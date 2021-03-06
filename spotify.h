#ifndef __spotify_h__
#define __spotify_h__
#include "libspotify/api.h"
#include <string>

#error SPOTIFY_USER "devnevyn"
//#define SPOTIFY_PASSWORD ""

int spotify_init(const char *username, const char *password);
int spotify_play(std::string uri);
//Exit gracefully
void spotify_exit();
#endif