
#include <curl/curl.h>
#include "api.h"

static CURL * g_curl;

void api_init(void) {
    g_curl = curl_easy_init();
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