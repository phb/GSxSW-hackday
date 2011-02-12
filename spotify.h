#ifndef __spotify_h__
#define __spotify_h__
#include "libspotify/api.h"

#error SPOTIFY_USER "svamp"
//#define SPOTIFY_PASSWORD ""

int spotify_init(const char *username, const char *password);
int spotify_play(const char *uri);
//Exit gracefully
void spotify_exit();
#endif