#include <stdio.h>
#include <string.h>
#include "io.h"

IO_Pin_t g_io_playPauseButton = {
    .id = 1
};

IO_Pin_t g_io_nextButton = {
    .id = 2
};

IO_Pin_t g_io_prevButton = {
    .id = 3
};

IO_Pin_t g_io_volUpButton = {
    .id = 4
};

IO_Pin_t g_io_volDownButton = {
    .id = 5
};

IO_Pin_t g_io_randomButton = {
    .id = 6
};

static const char * g_playPauseCommandString = "play";
static const char * g_nextCommandString = "next";
static const char * g_prevCommandString = "prev";
static const char * g_volupCommandString = "volup";
static const char * g_voldownCommandString = "voldown";
static const char * g_randomCommandString = "random";

static void io_processInput(char * commandString) {
    if(strcmp(commandString, g_playPauseCommandString) == 0) io_setPinState(&g_io_playPauseButton, true);
    else if(strcmp(commandString, g_nextCommandString) == 0) io_setPinState(&g_io_nextButton, true);
    else if(strcmp(commandString, g_prevCommandString) == 0) io_setPinState(&g_io_prevButton, true);
    else if(strcmp(commandString, g_volupCommandString) == 0) io_setPinState(&g_io_volUpButton, true);
    else if(strcmp(commandString, g_voldownCommandString) == 0) io_setPinState(&g_io_volDownButton, true);
    else if(strcmp(commandString, g_randomCommandString) == 0) io_setPinState(&g_io_randomButton, true);
}

void io_init(void) {
    printf("Commands:\n");
    printf("    * %s\n", g_playPauseCommandString);
    printf("    * %s\n", g_nextCommandString);
    printf("    * %s\n", g_prevCommandString);
    printf("    * %s\n", g_volupCommandString);
    printf("    * %s\n", g_voldownCommandString);
    printf("    * %s\n", g_randomCommandString);
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