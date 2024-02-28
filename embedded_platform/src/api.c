
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "api.h"

// URLs
#define API_URL_TOKEN "https://accounts.spotify.com/api/token"
#define API_URL_PAUSE "https://api.spotify.com/v1/me/player/pause"
#define API_URL_PLAY "https://api.spotify.com/v1/me/player/play"
#define API_URL_NEXT "https://api.spotify.com/v1/me/player/next"
#define API_URL_PREV "https://api.spotify.com/v1/me/player/previous"
#define API_URL_VOL "https://api.spotify.com/v1/me/player/volume?volume_percent=%d"
#define API_URL_RANDOM "https://api.spotify.com/v1/me/player/shuffle?state=%s"

#ifndef BASIC_AUTHORIZATION_BASE64
#define BASIC_AUTHORIZATION_BASE64 ""
#endif

#ifndef REFRESH_TOKEN
#define REFRESH_TOKEN ""
#endif

typedef struct {
    char * content;
    size_t len;
} RequestResponse_t;

typedef enum {
    HTTPRequestType_PUT,
    HTTPRequestType_POST
} HTTPRequestType_t;

static char * g_accessToken;
static char * g_refreshToken;

static bool api_isInitialized(void) {
    return g_accessToken != NULL;
}

/*
static void api_initRequestResponse(RequestResponse_t * response) {
    response->len = 0;
    response->content = malloc(1);
    if(response->content == NULL) {
        printf("Error initializating RequestResponse_t\n");
        exit(1);
    }
    response->content[0] = '\0';
}


static void api_freeRequestResponse(RequestResponse_t * response) {
    free(response->content);
}



static size_t api_callback_readContent(void * incomingContent, size_t size, size_t nmemb, RequestResponse_t * response){
    // Calculate new size of the response content (current+new)    
    size_t newLen = response->len + size*nmemb;

    // Reallocate response->content in memory to contain the new data
    response->content = realloc(response->content, newLen+1);
    if(response->content == NULL) {
        printf("Error reallocating RequestResponse_t\n");
        exit(1);
    }
    // Append new content in the response->content string.
    memcpy(&response->content[response->len], incomingContent, size*nmemb);
    response->content[newLen] = '\0';
    response->len = newLen;
    return size*nmemb;
}
*/

static char * api_getNewToken(void) {
    return NULL;
}

static void renewToken() {
    free(g_accessToken);
    free(g_refreshToken);
    g_accessToken = api_getNewToken();
    if(g_accessToken == NULL) {
        printf("Error getting new access token\n");
    }
}



static void api_sendRequest(char * url, HTTPRequestType_t type) {

}

static void api_sendPauseRequest(void) {
    api_sendRequest(API_URL_PAUSE, HTTPRequestType_PUT);
}

static void api_sendPlayRequest(void) {
    api_sendRequest(API_URL_PLAY, HTTPRequestType_PUT);
}

static void api_sendNextRequest(void) {
    api_sendRequest(API_URL_NEXT, HTTPRequestType_POST);
}

static void api_sendPrevRequest(void) {
    api_sendRequest(API_URL_PREV, HTTPRequestType_POST);
}

static void api_sendVolRequest(uint8_t volumePercent) {
    char url[63];
    snprintf(url, sizeof(url), API_URL_VOL, volumePercent);
    api_sendRequest(url, HTTPRequestType_PUT);
}

static void api_sendRandomRequest(bool randomEnabled) {
    char url[57];
    snprintf(url, sizeof(url), API_URL_RANDOM, randomEnabled ? "true" : "false");
    api_sendRequest(url, HTTPRequestType_PUT);
}

void api_init(void) {
    if((strlen(BASIC_AUTHORIZATION_BASE64) > 0) && (strlen(REFRESH_TOKEN) > 0)) renewToken();
}

void api_makeRequest(ApiRequest_t * request) {
    if(!api_isInitialized()) return;
    
    switch(request->type) {
        case RequestType_PlayPause:
            if(request->playEnabled) api_sendPlayRequest();
            else api_sendPauseRequest();
            break;

        case RequestType_Next:
            api_sendNextRequest();
            break;

        case RequestType_Prev:
            api_sendPrevRequest();
            break;

        case RequestType_Vol:
            api_sendVolRequest(request->volumePercent);
            break;

        case RequestType_Random:
            api_sendRandomRequest(request->randomEnabled);
            break;

        default:
            break;
    }
}