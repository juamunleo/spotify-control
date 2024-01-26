
#include <stdio.h>
#include <curl/curl.h>
#include "api.h"

#ifndef CLIENT_ID
#define CLIENT_ID ""
#endif

#ifndef CLIENT_SECRET
#define CLIENT_SECRET ""
#endif

static CURL * g_curl;

void api_init(void) {
    struct curl_slist *list = NULL;
    curl_off_t size;
    g_curl = curl_easy_init();
    char url[159];
    snprintf(url, sizeof(url), "https://accounts.spotify.com/api/token?grant_type=client_credentials&client_id=%s&client_secret=%s", CLIENT_ID, CLIENT_SECRET);
    curl_easy_setopt(g_curl, CURLOPT_POST, 1L);    
    curl_easy_setopt(g_curl, CURLOPT_URL, url);
    curl_easy_setopt(g_curl, CURLOPT_POSTFIELDSIZE, 0L);
    curl_easy_setopt(g_curl, CURLOPT_POSTFIELDS, "");    
    list = curl_slist_append(list, "Content-Type: application/x-www-form-urlencoded");
    curl_easy_setopt(g_curl, CURLOPT_HTTPHEADER, list);
    curl_easy_perform(g_curl);
    curl_easy_getinfo(g_curl, CURLINFO_SIZE_DOWNLOAD_T, &size);
    printf("Size: %ld", size);
    curl_slist_free_all(list);
}

static void api_sendRequest(void /* data */) {
    
}

static void api_sendStopRequest(void) {
    
}

static void api_sendPlayRequest(void) {
    
}

static void api_sendNextRequest(void) {
    
}

static void api_sendPrevRequest(void) {
    
}

static void api_sendVolUpRequest(void) {
    
}

static void api_sendVolDownRequest(void) {
    
}

static void api_sendRandomRequest(void) {
    
}


void api_makeRequest(Request_t request) {
    switch(request) {
        case Request_Stop:
            api_sendStopRequest();
            break;

        case Request_Play:
            api_sendPlayRequest();
            break;

        case Request_Next:
            api_sendNextRequest();
            break;

        case Request_Prev:
            api_sendPrevRequest();
            break;

        case Request_VolUp:
            api_sendVolUpRequest();
            break;

        case Request_VolDown:
            api_sendVolDownRequest();
            break;
            
        case Request_Random:
            api_sendRandomRequest();
            break;

        default:
            break;
    }
}