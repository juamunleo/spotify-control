#include <stdio.h>
#include <string.h>
#include "io.h"

IO_Pin_t g_io_stopButton = {
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

static const char * g_stopCommandString = "stop";
static const char * g_stopPlayString = "play";
static const char * g_stopNextString = "next";
static const char * g_stopPrevString = "prev";
static const char * g_stopVolupString = "volup";
static const char * g_stopVoldownString = "voldown";
static const char * g_stopRandomString = "random";

static void io_processInput(char * commandString) {
    if(strcmp(commandString, g_stopCommandString) == 0) io_setPinState(&g_io_stopButton, true);
    else if(strcmp(commandString, g_stopPlayString) == 0) io_setPinState(&g_io_playButton, true);
    else if(strcmp(commandString, g_stopNextString) == 0) io_setPinState(&g_io_nextButton, true);
    else if(strcmp(commandString, g_stopPrevString) == 0) io_setPinState(&g_io_prevButton, true);
    else if(strcmp(commandString, g_stopVolupString) == 0) io_setPinState(&g_io_volUpButton, true);
    else if(strcmp(commandString, g_stopVoldownString) == 0) io_setPinState(&g_io_volDownButton, true);
    else if(strcmp(commandString, g_stopRandomString) == 0) io_setPinState(&g_io_randomButton, true);
}

void io_init() {
    printf("Commands:\n");
    printf("    * %s\n", g_stopCommandString);
    printf("    * %s\n", g_stopPlayString);
    printf("    * %s\n", g_stopNextString);
    printf("    * %s\n", g_stopPrevString);
    printf("    * %s\n", g_stopVolupString);
    printf("    * %s\n", g_stopVoldownString);
    printf("    * %s\n", g_stopRandomString);
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
    printf("Pin %d set %s\n", pin->id, state ? "HIGH":"LOW");
}