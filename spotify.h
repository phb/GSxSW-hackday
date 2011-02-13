#ifndef __spotify_h__
#define __spotify_h__
#include "libspotify/api.h"
#include <string>

#define SPOTIFY_USER "svamp"
#define SPOTIFY_PASSWORD ""
class Gazify;

int spotify_init(Gazify *g , const char *username, const char *password);
int spotify_play(std::string uri);
//Exit gracefully
void spotify_exit();
#endif