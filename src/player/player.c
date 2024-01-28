
#include <stdio.h>
#include "player.h"
#include "api.h"

static PlayerState_t g_playerState;

void player_init(void) {
    g_playerState.playing = false;
    g_playerState.volumePercent = 50;
    g_playerState.randomEnabled = true;
}

bool player_isPlaying(void) {
    return g_playerState.playing;
}

bool player_isRandomEnabled(void) {
    return g_playerState.randomEnabled;
}

uint8_t player_getVolume(void) {
    return g_playerState.volumePercent;
}

void player_updateVolume(int8_t volumeIncrease) {
    if((volumeIncrease > 100) || (volumeIncrease < -100)) return;
    if((volumeIncrease > 0) && (g_playerState.volumePercent == 100)) return;
    if((volumeIncrease < 0) && (g_playerState.volumePercent == 0)) return;
    
    g_playerState.volumePercent += volumeIncrease;

    if(g_playerState.volumePercent > 100 && volumeIncrease > 0) g_playerState.volumePercent = 100;

    // Note: it's compared to 100 because uint8_t can't be negative. If the volume is reduced below 0, it underflows to 255.
    if(g_playerState.volumePercent > 100 && volumeIncrease < 0) g_playerState.volumePercent = 0;
}

void player_updateRandomEnabled(bool enabled) {
    g_playerState.randomEnabled = enabled;
}

static void player_command_pause(void) {
    ApiRequest_t request = {
        .type = RequestType_Pause
    };
    api_makeRequest(&request);
}

static void player_command_play(void) {
    ApiRequest_t request = {
        .type = RequestType_Play
    };
    api_makeRequest(&request);
}

static void player_command_next(void) {
    ApiRequest_t request = {
        .type = RequestType_Next
    };
    api_makeRequest(&request);
}

static void player_command_prev(void) {
    ApiRequest_t request = {
        .type = RequestType_Prev
    };
    api_makeRequest(&request);
}

static void player_command_volup(void) {
    player_updateVolume(10);
    ApiRequest_t request = {
        .type = RequestType_Vol,
        .volumePercent = player_getVolume()
    };
    api_makeRequest(&request);
}

static void player_command_voldown(void) {
    player_updateVolume(-10);
    ApiRequest_t request = {
        .type = RequestType_Vol,
        .volumePercent = player_getVolume()
    };
    api_makeRequest(&request);
}

static void player_command_random(void) {
    player_updateRandomEnabled(!player_isRandomEnabled());
    ApiRequest_t request = {
        .type = RequestType_Random,
        .randomEnabled = player_isRandomEnabled()
    };
    api_makeRequest(&request);
}


void player_executeCommand(Command_t command) {
    switch(command) {
        case Command_Pause:
            player_command_pause();
            break;
        case Command_Play:
            player_command_play();
            break;
        case Command_Next:
            player_command_next();
            break;
        case Command_Prev:
            player_command_prev();
            break;
        case Command_VolUp:
            player_command_volup();
            break;
        case Command_VolDown:
            player_command_voldown();
            break;
        case Command_Random:
            player_command_random();
            break;

        default:
            break;
    }

}