#include<stdio.h>
#include "application.h"
#include "io.h"
#include "player.h"

void app_setup(void) {
    io_init();
    player_init();
}

void app_loop(void) {
    if(io_getPinState(&g_io_playPauseButton)) player_togglePlay();
    else if(io_getPinState(&g_io_nextButton)) player_next();
    else if(io_getPinState(&g_io_prevButton)) player_prev();
    else if(io_getPinState(&g_io_volUpButton)) player_volUp();
    else if(io_getPinState(&g_io_volDownButton)) player_volDown();
    else if(io_getPinState(&g_io_randomButton)) player_toggleRandom();
}