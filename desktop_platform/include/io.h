#ifndef DESKTOP_PLATFORM_INCLUDE_IO_H
#define DESKTOP_PLATFORM_INCLUDE_IO_H

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    IO_PinState_Low,
    IO_PinState_High
} IO_PinState_t;

typedef struct {
    uint8_t id;
    bool received;
}IO_Pin_t;

extern IO_Pin_t g_io_playPauseButton;
extern IO_Pin_t g_io_nextButton;
extern IO_Pin_t g_io_prevButton;
extern IO_Pin_t g_io_volUpButton;
extern IO_Pin_t g_io_volDownButton;
extern IO_Pin_t g_io_randomButton;

void io_init(void);
bool io_isInterrupted(void);
IO_PinState_t io_getPinState(IO_Pin_t * pin);
void io_setPinState(IO_Pin_t * pin, IO_PinState_t state);

#endif