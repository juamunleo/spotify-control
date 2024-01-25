#ifndef SRC_PLAYER_PLAYER_H
#define SRC_PLAYER_PLAYER_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint8_t vol;
    bool playing;
    bool randomEnabled;
} PlayerState_t;

typedef enum {
    Command_Stop,
    Command_Play,
    Command_Next,
    Command_Prev,
    Command_VolUp,
    Command_VolDown,
    Command_Random,
    
    Command_Unknown
} Command_t;

void player_init(void);
bool player_isPlaying(void);
bool player_isRandomEnabled(void);
uint8_t player_volume(void);
void player_executeCommand(Command_t command);

#endif