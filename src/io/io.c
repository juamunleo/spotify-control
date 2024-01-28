#include <stdio.h>
#include <string.h>
#include "io.h"

IO_Pin_t g_io_pauseButton = {
    .id = 1
};

IO_Pin_t g_io_playButton = {
    .id = 2
};

IO_Pin_t g_io_nextButton = {
    .id = 3
};

IO_Pin_t g_io_prevButton = {
    .id = 4
};

IO_Pin_t g_io_volUpButton = {
    .id = 5
};

IO_Pin_t g_io_volDownButton = {
    .id = 6
};

IO_Pin_t g_io_randomButton = {
    .id = 7
};

static const char * g_pauseCommandString = "pause";
static const char * g_PlayCommandString = "play";
static const char * g_NextCommandString = "next";
static const char * g_PrevCommandString = "prev";
static const char * g_VolupCommandString = "volup";
static const char * g_VoldownCommandString = "voldown";
static const char * g_RandomCommandString = "random";

static void io_processInput(char * commandString) {
    if(strcmp(commandString, g_pauseCommandString) == 0) io_setPinState(&g_io_pauseButton, true);
    else if(strcmp(commandString, g_PlayCommandString) == 0) io_setPinState(&g_io_playButton, true);
    else if(strcmp(commandString, g_NextCommandString) == 0) io_setPinState(&g_io_nextButton, true);
    else if(strcmp(commandString, g_PrevCommandString) == 0) io_setPinState(&g_io_prevButton, true);
    else if(strcmp(commandString, g_VolupCommandString) == 0) io_setPinState(&g_io_volUpButton, true);
    else if(strcmp(commandString, g_VoldownCommandString) == 0) io_setPinState(&g_io_volDownButton, true);
    else if(strcmp(commandString, g_RandomCommandString) == 0) io_setPinState(&g_io_randomButton, true);
}

void io_init(void) {
    printf("Commands:\n");
    printf("    * %s\n", g_pauseCommandString);
    printf("    * %s\n", g_PlayCommandString);
    printf("    * %s\n", g_NextCommandString);
    printf("    * %s\n", g_PrevCommandString);
    printf("    * %s\n", g_VolupCommandString);
    printf("    * %s\n", g_VoldownCommandString);
    printf("    * %s\n", g_RandomCommandString);
}

bool io_isInterrupted(void) {
    char commandString[7];
    printf("Enter a command: \n");
    fflush(stdout);
    scanf("%s", commandString);    
    io_processInput(commandString);
    return true;
}

IO_PinState_t io_getPinState(IO_Pin_t * pin) {
    bool state = pin->received;
    pin->received = false;
    return state;
}

void io_setPinState(IO_Pin_t * pin, IO_PinState_t state) {
    pin->received = state;
}