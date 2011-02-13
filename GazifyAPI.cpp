/**********************************************************\

  Auto-generated GazifyAPI.cpp

\**********************************************************/

#include "JSObject.h"
#include "variant_list.h"
#include "DOM/Document.h"

#include "GazifyAPI.h"

#include <spotify.h>

///////////////////////////////////////////////////////////////////////////////
/// @fn GazifyAPI::GazifyAPI(const GazifyPtr& plugin, const FB::BrowserHostPtr host)
///
/// @brief  Constructor for your JSAPI object.  You should register your methods, properties, and events
///         that should be accessible to Javascript from here.
///
/// @see FB::JSAPIAuto::registerMethod
/// @see FB::JSAPIAuto::registerProperty
/// @see FB::JSAPIAuto::registerEvent
///////////////////////////////////////////////////////////////////////////////
GazifyAPI::GazifyAPI(const GazifyPtr& plugin, const FB::BrowserHostPtr& host) : m_plugin(plugin), m_host(host)
{
    registerMethod("playTrack",      make_method(this, &GazifyAPI::playTrack));
    registerMethod("testFade",      make_method(this, &GazifyAPI::testFade));
}

///////////////////////////////////////////////////////////////////////////////
/// @fn GazifyAPI::~GazifyAPI()
///
/// @brief  Destructor.  Remember that this object will not be released until
///         the browser is done with it; this will almost definitely be after
///         the plugin is released.
///////////////////////////////////////////////////////////////////////////////
GazifyAPI::~GazifyAPI()
{
}

///////////////////////////////////////////////////////////////////////////////
/// @fn GazifyPtr GazifyAPI::getPlugin()
///
/// @brief  Gets a reference to the plugin that was passed in when the object
///         was created.  If the plugin has already been released then this
///         will throw a FB::script_error that will be translated into a
///         javascript exception in the page.
///////////////////////////////////////////////////////////////////////////////
GazifyPtr GazifyAPI::getPlugin()
{
    GazifyPtr plugin(m_plugin.lock());
    if (!plugin) {
        throw FB::script_error("The plugin is invalid");
    }
    return plugin;
}

const char *tracks[] = {
"spotify:track:6jr9Nfy7usc9UCPmvsP9HA#0:14",
"spotify:track:0ukciTLsLePMaI6Dx2N1ZR#0:10",
"spotify:track:6jr9Nfy7usc9UCPmvsP9HA#0:15",
"spotify:track:2KV7UQd1yr9ALqsijB0RN1",
"spotify:track:5XjLR8b4uJsLuv7JxEUDri#3:16",
"spotify:track:1dkNKO29FkD0Hq3FKDeQtL",
"spotify:track:4TuweDJq5Es0NhGFWsNloS#0:10",
"spotify:track:2ZiVInK0uFGho2WthDxZhh",
"spotify:track:0WZyZa0sN8bQbhBKC1L5Pc",
"spotify:track:4RjmZ4CXTGd6MFuSMTBoD5",
"spotify:track:0dH3bW9ndjyCZfKuPaeTvO",
"spotify:track:4KKDoL0meGHUKpB3JCsQeR#0:15",
"spotify:track:1W3KOOedq6XfnJzfR5rn9t#0:20",
"spotify:track:3Vc4RjJ4CJmnzJp74fYK5M",
"spotify:track:4rp7e604nblHYU7J6fchZP"
};


/* Plays through a default set of tracks & Fades */
void GazifyAPI::testFade()
{
    static int curr_idx;
    printf("testFade\n");
    if(curr_idx == 0)
        printf("Starting fade test\n");
    printf("Switching to song: %s\n",tracks[curr_idx]);
    spotify_play(tracks[curr_idx]);
    curr_idx++;
    if(curr_idx > sizeof(tracks)/sizeof(tracks[0]))
        curr_idx = 0;
}

void GazifyAPI::playTrack(std::string var)
{
    printf("playing %s\n", var.c_str());
    spotify_play(var);
}

