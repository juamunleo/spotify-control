#ifndef SRC_PLAYER_PLAYER_H
#define SRC_PLAYER_PLAYER_H

#include <stdint.h>
#include <stdbool.h>

void player_init(void);
bool player_isPlaying(void);
bool player_isRandomEnabled(void);
uint8_t player_getVolume(void);
void player_togglePlay(void);
void player_next(void);
void player_prev(void);
void player_volUp(void);
void player_volDown(void);
void player_vol(uint8_t newVolume);
void player_toggleRandom(void);
#endif