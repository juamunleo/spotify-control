
#include <stdio.h>
#include "player.h"
#include "api.h"

#define PLAYER_VOLUME_STEP 5

typedef struct {
    bool playing;
    uint8_t volumePercent;
    bool randomEnabled;
} PlayerState_t;

static PlayerState_t g_playerState;

void player_init(void) {
    api_init();
    g_playerState.playing = false;
    g_playerState.volumePercent = 50;
    g_playerState.randomEnabled = false;
}

bool player_isPlaying(void) {
    return g_playerState.playing;
}

static void player_setPlaying(bool playing) {
    g_playerState.playing = playing;
}

uint8_t player_getVolume(void) {
    return g_playerState.volumePercent;
}

static void player_setVolume(uint8_t newVolume) {
    if(newVolume > 100) newVolume = 100;
    
    g_playerState.volumePercent = newVolume;
}

bool player_isRandomEnabled(void) {
    return g_playerState.randomEnabled;
}

static void player_setRandomEnabled(bool enabled) {
    g_playerState.randomEnabled = enabled;
}



void player_togglePlay(void) {
    player_setPlaying(!player_isPlaying());
    ApiRequest_t request = {
        .type = RequestType_PlayPause,
        .playEnabled = player_isPlaying()
    };
    api_makeRequest(&request);
}

void player_next(void) {
    ApiRequest_t request = {
        .type = RequestType_Next
    };
    api_makeRequest(&request);
}

void player_prev(void) {
    ApiRequest_t request = {
        .type = RequestType_Prev
    };
    api_makeRequest(&request);
}

void player_volUp(void) {
    uint8_t newVolume = player_getVolume()+PLAYER_VOLUME_STEP;
    if(newVolume > 100) newVolume = 100;
    player_setVolume(newVolume);
    ApiRequest_t request = {
        .type = RequestType_Vol,
        .volumePercent = player_getVolume()
    };
    api_makeRequest(&request);
}

void player_volDown(void) {
    int8_t newVolume = player_getVolume()-PLAYER_VOLUME_STEP;
    if(newVolume < 0) newVolume = 0;
    player_setVolume(newVolume);
    ApiRequest_t request = {
        .type = RequestType_Vol,
        .volumePercent = player_getVolume()
    };
    api_makeRequest(&request);
}

void player_vol(uint8_t newVolume) {
    player_setVolume(newVolume);
    ApiRequest_t request = {
        .type = RequestType_Vol,
        .volumePercent = player_getVolume()
    };
    api_makeRequest(&request);
}

void player_toggleRandom(void) {
    player_setRandomEnabled(!player_isRandomEnabled());
    ApiRequest_t request = {
        .type = RequestType_Random,
        .randomEnabled = player_isRandomEnabled()
    };
    api_makeRequest(&request);
}