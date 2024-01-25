
#include <stdio.h>
#include "player.h"

static PlayerState_t g_playerState;

void player_init(void) {
    g_playerState.playing = false;
    g_playerState.vol = 50;
    g_playerState.randomEnabled = true;
}

bool player_isPlaying(void) {
    return g_playerState.playing;
}

bool player_isRandomEnabled(void) {
    return g_playerState.randomEnabled;
}

uint8_t player_volume(void) {
    return g_playerState.vol;
}

static void player_command_stop(void) {
    printf("Command executed: stop\n");
}

static void player_command_play(void) {
    printf("Command executed: play\n");
}

static void player_command_next(void) {
    printf("Command executed: next\n");
}

static void player_command_prev(void) {
    printf("Command executed: prev\n");
}

static void player_command_volup(void) {
    printf("Command executed: volup\n");
}

static void player_command_voldown(void) {
    printf("Command executed: voldown\n");
}

static void player_command_random(void) {
    printf("Command executed: random\n");
}

void player_executeCommand(Command_t command) {
    switch(command) {
        case Command_Stop:
            player_command_stop();
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