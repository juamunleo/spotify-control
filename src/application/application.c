#include<stdio.h>
#include "application.h"
#include "io.h"
#include "player.h"
#include "api.h"

void app_setup(void) {
    io_init();
    player_init();
    api_init();
}

void app_loop(void) {
    if(!io_isInterrupted()) return;

    if(io_getPinState(&g_io_stopButton)) player_executeCommand(Command_Stop);
    else if(io_getPinState(&g_io_playButton)) player_executeCommand(Command_Play);
    else if(io_getPinState(&g_io_nextButton)) player_executeCommand(Command_Next);
    else if(io_getPinState(&g_io_prevButton)) player_executeCommand(Command_Prev);
    else if(io_getPinState(&g_io_volUpButton)) player_executeCommand(Command_VolUp);
    else if(io_getPinState(&g_io_volDownButton)) player_executeCommand(Command_VolDown);
    else if(io_getPinState(&g_io_randomButton)) player_executeCommand(Command_Random);
}