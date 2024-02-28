#include "io.h"

IO_Pin_t g_io_playPauseButton;
IO_Pin_t g_io_nextButton;
IO_Pin_t g_io_prevButton;
IO_Pin_t g_io_volUpButton;
IO_Pin_t g_io_volDownButton;
IO_Pin_t g_io_randomButton;

void io_init(void) {
    g_io_playPauseButton.pGPIOx = GPIOC;
	g_io_playPauseButton.GPIO_config.GPIO_Mode = GPIO_MODE_IN;
	g_io_playPauseButton.GPIO_config.GPIO_Pin = GPIO_PIN_13;
	g_io_playPauseButton.GPIO_config.GPIO_PuPd = GPIO_PUPD_NONE;
	g_io_playPauseButton.GPIO_config.GPIO_Speed = GPIO_SPEED_LOW;
	GPIO_Init(&g_io_playPauseButton);
}

IO_PinState_t io_getPinState(IO_Pin_t * pin) {
    if(pin != &g_io_playPauseButton) return IO_PinState_Low;
    return !GPIO_ReadPin(
        pin->pGPIOx,
        pin->GPIO_config.GPIO_Pin
    );
}

void io_setPinState(IO_Pin_t * pin, IO_PinState_t state) {
    if(pin != &g_io_playPauseButton) return;
    GPIO_WritePin(
        pin->pGPIOx,
        pin->GPIO_config.GPIO_Pin,
        state
    );
}