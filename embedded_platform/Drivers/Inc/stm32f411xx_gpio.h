#ifndef DRIVERS_INC_STM32F411XX_GPIO_H_
#define DRIVERS_INC_STM32F411XX_GPIO_H_

#include "stm32f411xx.h"

typedef enum {
	GPIO_PIN_0,
	GPIO_PIN_1,
	GPIO_PIN_2,
	GPIO_PIN_3,
	GPIO_PIN_4,
	GPIO_PIN_5,
	GPIO_PIN_6,
	GPIO_PIN_7,
	GPIO_PIN_8,
	GPIO_PIN_9,
	GPIO_PIN_10,
	GPIO_PIN_11,
	GPIO_PIN_12,
	GPIO_PIN_13,
	GPIO_PIN_14,
	GPIO_PIN_15
}GPIO_Pin_t;

typedef enum {
	GPIO_MODE_IN, 		//INPUT
	GPIO_MODE_OUT, 		//OUPTUT
	GPIO_MODE_AF, 		//Alternate function
	GPIO_MODE_AN, 		//Analog
	GPIO_MODE_IT_RE,	//INPUT with interrupt in Rising Edge mode
	GPIO_MODE_IT_FE,	//INPUT with interrupt in Falling Edge mode
	GPIO_MODE_IT_RFE	//INPUT with interrupt in Rising and Falling Edge mode
}GPIO_Mode_t;

typedef enum {
	GPIO_OTYPE_PP, 	//Push Pull
	GPIO_OTYPE_OD 	//Open Drain
}GPIO_OType_t;

typedef enum {
	GPIO_SPEED_LOW,
	GPIO_SPEED_MEDIUM,
	GPIO_SPEED_FAST,
	GPIO_SPEED_HIGH
}GPIO_Speed_t;

typedef enum {
	GPIO_PUPD_NONE,
	GPIO_PUPD_UP, 	//Pull up
	GPIO_PUPD_DOWN 	//Pull down
}GPIO_PuPd_t;

typedef enum {
	GPIO_ALTFUN_0,
	GPIO_ALTFUN_1,
	GPIO_ALTFUN_2,
	GPIO_ALTFUN_3,
	GPIO_ALTFUN_4,
	GPIO_ALTFUN_5,
	GPIO_ALTFUN_6,
	GPIO_ALTFUN_7,
	GPIO_ALTFUN_8,
	GPIO_ALTFUN_9,
	GPIO_ALTFUN_10,
	GPIO_ALTFUN_11,
	GPIO_ALTFUN_12,
	GPIO_ALTFUN_13,
	GPIO_ALTFUN_14,
	GPIO_ALTFUN_15
}GPIO_AltFun_t;

typedef struct {
	GPIO_Pin_t GPIO_Pin;		//Pin
	GPIO_Mode_t GPIO_Mode;		//Modo de funcionamiento
	GPIO_OType_t GPIO_OType;	//Tipo de salida
	GPIO_Speed_t GPIO_Speed;	//Velocidad
	GPIO_PuPd_t GPIO_PuPd;		//Pull up o Pull down
	GPIO_AltFun_t GPIO_AltFun;	//Función alternativa (ver tabla en reference manual)
}GPIO_Config_t;

typedef struct {
	GPIO_RegDef_t *pGPIOx;
	GPIO_Config_t GPIO_config;
}GPIO_Handle_t;

//Funciones
void GPIO_ClkCtrl(GPIO_RegDef_t *pGPIOx, uint8_t status);
void GPIO_Init(GPIO_Handle_t * pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

uint8_t GPIO_ReadPin(GPIO_RegDef_t * pGPIOx, GPIO_Pin_t pin);
uint16_t GPIO_ReadPort(GPIO_RegDef_t * pGPIOx);
void GPIO_WritePin(GPIO_RegDef_t * pGPIOx, GPIO_Pin_t pin, uint8_t value);
void GPIO_WritePort(GPIO_RegDef_t * pGPIOx, uint16_t value);
void GPIO_TogglePin(GPIO_RegDef_t * pGPIOx, GPIO_Pin_t pin);

void GPIO_IRQHandler(uint8_t pin);
#endif /* DRIVERS_INC_STM32F411XX_GPIO_H_ */
