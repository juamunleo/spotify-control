
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "parson.h"
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

static char * accessToken;
static char * refreshToken;

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

static char * api_getNewToken(void) {
    // Variable declaration
    char bodyContent[313];
    char authorization[110];
    RequestResponse_t response;
    curl_off_t size;
    JSON_Value * jsonValue;
    JSON_Object * jsonObject;
    const char * receivedAccessToken;
    size_t receivedAccessTokenSize;
    struct curl_slist *list = NULL;
    char * newAccessToken;

    // Initialization
    CURL* curl = curl_easy_init();
    api_initRequestResponse(&response);

    // HTTP Request using cURL
    snprintf(bodyContent, sizeof(bodyContent), "grant_type=refresh_token&refresh_token=%s", REFRESH_TOKEN);
    snprintf(authorization, sizeof(authorization), "Authorization: Basic %s", BASIC_AUTHORIZATION_BASE64);
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_URL, API_URL_TOKEN);
    //curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, strlen(bodyContent)+1);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, bodyContent);
    list = curl_slist_append(list, "Accept: application/json");
    list = curl_slist_append(list, authorization);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, api_callback_readContent);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    //curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); // Uncomment if request debug is needed
    curl_easy_perform(curl);

    // Parse HTTP response using JSONc
    jsonValue = json_parse_string(response.content);
    jsonObject = json_value_get_object(jsonValue);
    receivedAccessToken = json_object_get_string(jsonObject, "access_token");

    // Store the received token in the variable that will be returned
    if(receivedAccessToken != NULL) {
        receivedAccessTokenSize = strlen(receivedAccessToken);
        newAccessToken = malloc(receivedAccessTokenSize+1);
        strcpy(newAccessToken, receivedAccessToken);
    }

    // Cleanup
    json_value_free(jsonValue);
    api_freeRequestResponse(&response);
    curl_slist_free_all(list);
    curl_easy_cleanup(curl);

    return newAccessToken;
}

static void renewToken() {
    free(accessToken);
    free(refreshToken);
    accessToken = api_getNewToken();
    if(accessToken == NULL) {
        printf("Error getting new access token\n");
    }
}



static void api_sendRequest(char * url, HTTPRequestType_t type) {
    // Variable declaration
    char authHeader[210];

    // Initialization
    CURL* curl = curl_easy_init();
    struct curl_slist *list = NULL;

    // HTTP Request using cURL
    if(type == HTTPRequestType_PUT) curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
    else if(type == HTTPRequestType_PUT) curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, 0L);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "");
    snprintf(authHeader, sizeof(authHeader), "Authorization: Bearer %s", accessToken);
    list = curl_slist_append(list, authHeader);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
    //curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); // Uncomment if request debug is needed
    curl_easy_perform(curl);

    // Cleanup
    curl_slist_free_all(list);
    curl_easy_cleanup(curl);
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

static void api_initRequest(ApiRequest_t * request) {
    request->type = RequestType_Undefined;
    request->volumePercent = 0;
    request->randomEnabled = false;
}

void api_init(void) {
    renewToken();
}

void api_makeRequest(ApiRequest_t * request) {
    switch(request->type) {
        case RequestType_Pause:
            api_sendPauseRequest();
            break;

        case RequestType_Play:
            api_sendPlayRequest();
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