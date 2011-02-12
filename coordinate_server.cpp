/*
 *  coordinate_server.cpp
 *  FireBreath
 *
 *  Created by Johan Bjork on 2/12/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include "coordinate_server.h"
#include "Gazify.h"

#define BUFLEN 512
#define PORT 20320

void *coordiate_thread(void *arg)
{
    Gazify *g = (Gazify *)arg;

    struct sockaddr_in si_me, si_other;
    int s, i, slen=sizeof(si_other);
    char buf[BUFLEN];
    
    if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
        return NULL;
    
    memset((char *) &si_me, 0, sizeof(si_me));
    si_me.sin_family = AF_INET;
    si_me.sin_port = htons(PORT);
    si_me.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(s, (sockaddr *)&si_me, sizeof(si_me))==-1)
        return NULL;
    
    while(1) {
        int x,y;
        if (recvfrom(s, buf, BUFLEN, 0, (sockaddr*)&si_other, (socklen_t *)&slen)==-1) {
            printf("aborting recv thread");
            return NULL;
        }
        sscanf(buf,"%d %d\n",&x,&y);
        g->gaze(x,y);
    }
    
    close(s);
    return 0;
}