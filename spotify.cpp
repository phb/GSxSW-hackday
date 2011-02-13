/**
 * Copyright (c) 2006-2010 Spotify Ltd
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */
#include <libspotify/api.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "spotify.h"
#include "audio.h"
#include "Gazify.h"
#include <list>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <assert.h>

typedef struct sp_gazify {
    const char *username;
    const char *password;
    sp_session *session;
    Gazify * g;
    sp_track *current_t;
    std::list<boost::function<void()> > inbox;
    pthread_mutex_t inbox_mutex;
    bool want_exit;
} gazify_t;

gazify_t g_gazify;

int is_logged_out;

pthread_t g_spotify_tid;
/// The output queue for audo data
static audio_fifo_t g_audiofifo;
static int g_notify_do;
static pthread_mutex_t g_notify_mutex;
static pthread_cond_t g_notify_cond;
static sp_track *g_track_to_be_played;
static int g_track_offset;


static int try_play(sp_session *session, sp_track *t,int offset);

void notify_main_thread(sp_session *session)
{
    fprintf(stderr,"Notify main thread\n");
	pthread_mutex_lock(&g_notify_mutex);
	g_notify_do = 1;
	pthread_cond_signal(&g_notify_cond);
	pthread_mutex_unlock(&g_notify_mutex);
}

/**
 * This callback is called when the user was logged in, but the connection to
 * Spotify was dropped for some reason.
 *
 * @sa sp_session_callbacks#connection_error
 */
static void connection_error(sp_session *session, sp_error error)
{
	fprintf(stderr, "Connection to Spotify failed: %s\n",
	                sp_error_message(error));
}

sp_playlist_callbacks empty_callbacks = {0};

void foo(sp_playlist *bar, void *baz) {
    printf("playlist is loaded? %d\n", sp_playlist_is_loaded(bar));
}

/**
 * This callback is called when an attempt to login has succeeded or failed.
 *
 * @sa sp_session_callbacks#logged_in
 */
static void logged_in(sp_session *session, sp_error error)
{
	sp_user *me;
	const char *my_name;

	if (SP_ERROR_OK != error) {
		fprintf(stderr, "failed to log in to Spotify: %s\n",
		                sp_error_message(error));
		sp_session_release(session);
		exit(4);
	}

	// Let us print the nice message...
	me = sp_session_user(session);
	my_name = (sp_user_is_loaded(me) ? sp_user_display_name(me) : sp_user_canonical_name(me));

	fprintf(stderr, "Logged in to Spotify as user %s\n", my_name);
    sp_playlist *pl = sp_playlist_create(session, sp_link_create_from_string("spotify:user:devnevyn:playlist:44ZXlJstDZrwuQvWPOo7KX"));
    empty_callbacks.playlist_state_changed = foo;
    sp_playlist_add_callbacks(pl, &empty_callbacks, NULL);
}

/**
 * This callback is called when the session has logged out of Spotify.
 *
 * @sa sp_session_callbacks#logged_out
 */
static void logged_out(sp_session *session)
{
	is_logged_out = 1;  // Will exit mainloop
}


/**
 * This callback is called for log messages.
 *
 * @sa sp_session_callbacks#log_message
 */
static void log_message(sp_session *session, const char *data)
{
	fprintf(stderr, "%s", data);
}



/**
 * Callback called when libspotify has new metadata available
 *
 * Not used in this example (but available to be able to reuse the session.c file
 * for other examples.)
 *
 * @sa sp_session_callbacks#metadata_updated
 */
static void metadata_updated(sp_session *session)
{
    fprintf(stderr,"metadata updated\n");
    if(g_track_to_be_played)
        try_play(session,g_track_to_be_played,g_track_offset);
}

static void token_lost(sp_session *sess)
{
}

static int music_delivery(sp_session *sess, const sp_audioformat *format,
                          const void *frames, int num_frames)
{
	audio_fifo_t *af = &g_audiofifo;
	audio_fifo_data_t *afd;
	size_t s;
    
	if (num_frames == 0)
		return 0; // Audio discontinuity, do nothing
    
	pthread_mutex_lock(&af->mutex);
    
	/* Buffer one second of audio */
	if (af->qlen > format->sample_rate) {
		pthread_mutex_unlock(&af->mutex);
        
		return 0;
	}
    
	s = num_frames * sizeof(int16_t) * format->channels;
    
	afd = (audio_fifo_data_t *)malloc(sizeof(audio_fifo_data_t) + s);
	memcpy(afd->samples, frames, s);
    
	afd->nsamples = num_frames;
    
	afd->rate = format->sample_rate;
	afd->channels = format->channels;
    
	TAILQ_INSERT_TAIL(&af->q, afd, link);
	af->qlen += num_frames;
    
	pthread_cond_signal(&af->cond);
	pthread_mutex_unlock(&af->mutex);
    
	return num_frames;
}

/**
 * Session callbacks
 */
static sp_session_callbacks callbacks = {
	&logged_in,
	&logged_out,
	&metadata_updated,
	&connection_error,
	NULL,
	&notify_main_thread,
	&music_delivery,
	&token_lost,
	&log_message
};


static void *spotify_loop(void *arg)
{
    gazify_t *gazify = (gazify_t *)arg;
	sp_session *session = gazify->session;
 	int next_timeout = 0;
    
	pthread_mutex_init(&g_notify_mutex, NULL);
	pthread_cond_init(&g_notify_cond, NULL);
    while (!g_gazify.want_exit) {
		if (next_timeout == 0) {
			while(!g_notify_do)
				pthread_cond_wait(&g_notify_cond, &g_notify_mutex);
		} else {
			struct timespec ts;
            
#if _POSIX_TIMERS > 0
			clock_gettime(CLOCK_REALTIME, &ts);
#else
			struct timeval tv;
			gettimeofday(&tv, NULL);
			TIMEVAL_TO_TIMESPEC(&tv, &ts);
#endif
			ts.tv_sec += next_timeout / 1000;
			ts.tv_nsec += (next_timeout % 1000) * 1000000;
            
			pthread_cond_timedwait(&g_notify_cond, &g_notify_mutex, &ts);
		}
        
		g_notify_do = 0;
		pthread_mutex_unlock(&g_notify_mutex);
        
		do {
			sp_session_process_events(session, &next_timeout);
		} while (next_timeout == 0);
        //FIXME: If we are ever to call any blocking functions here, make sure we use a more granual lock!
        if(g_gazify.inbox.size() > 0) {
            pthread_mutex_lock(&g_gazify.inbox_mutex);
            for(std::list<boost::function<void()> >::iterator it = g_gazify.inbox.begin(); it != g_gazify.inbox.end();++it) {
                (*it)();
            }
            g_gazify.inbox.clear();
            pthread_mutex_unlock(&g_gazify.inbox_mutex);
        }
		pthread_mutex_lock(&g_notify_mutex);
	}    
}
/**
 * We'll spawn off a new thread which will be the 'spotify main thread'
 */
static void *spotify_init_thread(void *arg)
{
    gazify_t *gazify = (gazify_t *)arg;
    sp_session_config config;
	sp_error error;
	sp_session *session;
    
    /// The application key is specific to each project, and allows Spotify
    /// to produce statistics on how our service is used.
	extern const char g_appkey[];
    /// The size of the application key.
	extern const size_t g_appkey_size;
    
	memset(&config, 0, sizeof(config));
    
	// Always do this. It allows libspotify to check for
	// header/library inconsistencies.
	config.api_version = SPOTIFY_API_VERSION;
    
	// The path of the directory to store the cache. This must be specified.
	// Please read the documentation on preferred values.
	config.cache_location = "tmp";
    
	// The path of the directory to store the settings. 
	// This must be specified.
	// Please read the documentation on preferred values.
	config.settings_location = "tmp";
    
	// The key of the application. They are generated by Spotify,
	// and are specific to each application using libspotify.
	config.application_key = g_appkey;
	config.application_key_size = g_appkey_size;
    
	// This identifies the application using some
	// free-text string [1, 255] characters.
	config.user_agent = "Gazeify";
    
	// Register the callbacks.
	config.callbacks = &callbacks;
    
    
    audio_init(&g_audiofifo);
	error = sp_session_create(&config, &session);
	if (SP_ERROR_OK != error) {
		fprintf(stderr, "failed to create session: %s\n",
                sp_error_message(error));
		return (void*)2;
	}
    gazify->session = session;
    
	// Login using the credentials given on the command line.
	sp_session_login(session, gazify->username, gazify->password);
    
    spotify_loop(arg);
    return NULL;
}

int spotify_init(Gazify *g, const char *username,const char *password)
{
    g_gazify.username = username;
    g_gazify.password = password;
    g_gazify.g = g;
    pthread_create(&g_spotify_tid, NULL, &spotify_init_thread, &g_gazify);
	return 0;
}

static void image_loaded(sp_image *img, void *user)
{
    
    gazify_t *g = (gazify_t*)user;
    size_t img_size;
    const void *data = sp_image_data(img,&img_size);
    sp_artist *a = sp_track_artist(g->current_t,0);
    sp_album *alb = sp_track_album(g->current_t);
    
    
    g->g->postTrackInfo(sp_artist_name(a),sp_album_name(alb),sp_track_name(g->current_t),data,img_size);
    //sp_image_remove_load_callback(img,&image_loaded,user);
//    sp_image_release(img);
//fiuckit, let's leak!
}

static int try_play(sp_session *session, sp_track *t,int offset)
{
    sp_error err;
    fprintf(stderr,"try play\n");
    err = sp_session_player_load(session,t);
    if( err != SP_ERROR_OK) {
        fprintf(stderr,"Load failed %d\n",err);
    }
    if(!sp_track_is_loaded(t)) {
        if(g_track_to_be_played != t) {
            if(g_track_to_be_played)
                sp_track_release(g_track_to_be_played);
            g_track_to_be_played = t; //FIXME: Do I need to addref?
            sp_track_add_ref(g_track_to_be_played);
        }
    } else {
        //FIXME: Seek!
//        g_current_fifo_idx = (g_current_fifo_idx+1) % 2;
        sp_session_player_seek(session,offset);
        sp_session_player_play(session,true);
        sp_album *album = sp_track_album(t);
        if(album) {
            const byte *id = sp_album_cover(album);
            g_gazify.current_t = t;
            if(id) {
                sp_image *img = sp_image_create(session,id);
                sp_image_add_load_callback(img,&image_loaded,&g_gazify);
                
            }
        }
        g_track_to_be_played = NULL;
    }
    return err;
}

#warning We don't log errors.. but it's hackhack..
static void _spotify_play(sp_session *session, std::string uri)
{
    assert(pthread_equal(pthread_self(),g_spotify_tid));
    sp_link *l = sp_link_create_from_string(uri.c_str());
    sp_error err;
    int offset;
    if(!l || sp_link_type(l) != SP_LINKTYPE_TRACK) {
        return;
    }
    sp_track *t = sp_link_as_track_and_offset(l,&offset);
    try_play(session,t,offset);
    sp_link_release(l);
    return;
}

void spotify_mainthread(sp_session *session, boost::function<void()> f)
{
    pthread_mutex_lock(&g_gazify.inbox_mutex);
    g_gazify.inbox.push_back(f);
    notify_main_thread(session);
    pthread_mutex_unlock(&g_gazify.inbox_mutex);
}

int spotify_play(std::string uri)
{
    printf("Try to play: %s\n",uri.c_str());
    spotify_mainthread(g_gazify.session, boost::bind(_spotify_play,g_gazify.session,uri));
    return 0;
}

void spotify_exit()
{
    fprintf(stderr,"Want exit");
    g_gazify.want_exit = 1;
    spotify_mainthread(g_gazify.session, boost::bind(sp_session_logout,g_gazify.session));
    pthread_join(g_spotify_tid,NULL);
}