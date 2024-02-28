#ifndef DRIVERS_SRC_STM32F411XX_H_
#define DRIVERS_SRC_STM32F411XX_H_

#include <stdint.h>

#define HSE_FREQ ((uint32_t) 8000000)
#define HSI_FREQ ((uint32_t) 16000000)

void assert_failed(uint8_t *file, uint32_t line);

#define ASSERT_TRUE(expr)	((expr) ? (void)0 : assert_failed((uint8_t*)__FILE__, __LINE__))
#define ASSERT_FALSE(expr)	(!(expr) ? (void)0 : assert_failed((uint8_t*)__FILE__, __LINE__))

#define ENABLE 1
#define DISABLE 0

#define SET 1
#define RESET 0

#define AHB1PERIPH_ADDRESS 0x40020000UL
#define APB1PERIPH_ADDRESS 0x40000000UL
#define APB2PERIPH_ADDRESS 0x40010000UL

#define GPIOA_BASEADDR 	(AHB1PERIPH_ADDRESS + 0x0000)
#define GPIOB_BASEADDR 	(AHB1PERIPH_ADDRESS + 0x0400)
#define GPIOC_BASEADDR 	(AHB1PERIPH_ADDRESS + 0x0800)
#define GPIOD_BASEADDR 	(AHB1PERIPH_ADDRESS + 0xC000)
#define GPIOE_BASEADDR 	(AHB1PERIPH_ADDRESS + 0x1000)
#define GPIOH_BASEADDR 	(AHB1PERIPH_ADDRESS + 0x1C00)

#define RCC_BASEADDR 	(AHB1PERIPH_ADDRESS + 0x3800)

#define SYSCFG_BASEADDR (APB2PERIPH_ADDRESS + 0x3800)

#define EXTI_BASEADDR 	(APB2PERIPH_ADDRESS + 0x3C00)

#define PWR_BASEADDR	(APB1PERIPH_ADDRESS + 0x7000)

#define TIM1_BASEADDR	(APB2PERIPH_ADDRESS + 0x0000)
#define TIM2_BASEADDR	(APB1PERIPH_ADDRESS + 0x0000)
#define TIM3_BASEADDR	(APB1PERIPH_ADDRESS + 0x0400)
#define TIM4_BASEADDR	(APB1PERIPH_ADDRESS + 0x0800)
#define TIM5_BASEADDR	(APB1PERIPH_ADDRESS + 0x0C00)
#define TIM9_BASEADDR	(APB2PERIPH_ADDRESS + 0x4000)
#define TIM10_BASEADDR	(APB2PERIPH_ADDRESS + 0x4400)
#define TIM11_BASEADDR	(APB2PERIPH_ADDRESS + 0x4800)

#define NVIC_ISER0		(*((volatile uint32_t *) 0xE000E100UL))
#define NVIC_ISER1		(*((volatile uint32_t *) 0xE000E104UL))
#define NVIC_ISER2		(*((volatile uint32_t *) 0xE000E108UL))

#define NVIC_ICER0		(*((volatile uint32_t *) 0xE000E180UL))
#define NVIC_ICER1		(*((volatile uint32_t *) 0xE000E184UL))
#define NVIC_ICER2		(*((volatile uint32_t *) 0xE000E188UL))

#define NVIC_IPR_BASEADDR	0xE000E400UL


//Estructura de periféricos
typedef struct {
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFR[2];
}GPIO_RegDef_t;

typedef struct {
	volatile uint32_t CR;
	volatile uint32_t PLLCFGR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t AHB1RSTR;
	volatile uint32_t AHB2RSTR;
	volatile uint32_t RES0[2];
	volatile uint32_t APB1RSTR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t RES1[2];
	volatile uint32_t AHB1ENR;
	volatile uint32_t AHB2ENR;
	volatile uint32_t RES2[2];
	volatile uint32_t APB1ENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t RES3[2];
	volatile uint32_t AHB1LPENR;
	volatile uint32_t AHB2LPENR;
	volatile uint32_t RES4[2];
	volatile uint32_t APB1LPENR;
	volatile uint32_t APB2LPENR;
	volatile uint32_t RES5[2];
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t RES6[2];
	volatile uint32_t SSCGR;
	volatile uint32_t PLLI2SCFGR;
	volatile uint32_t RES7;
	volatile uint32_t DCKCFGR;
}RCC_RegDef_t;

typedef struct {
	volatile uint32_t MEMRMP;
	volatile uint32_t PMC;
	volatile uint32_t EXTICR[4];
	volatile uint32_t RES[2];
	volatile uint32_t CMPCR;
}SYSCFG_RegDef_t;

typedef struct {
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_RegDef_t;

typedef struct {
	volatile uint32_t CR;
	volatile uint32_t CSR;
}PWR_RegDef_t;

typedef struct {
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t SMCR;
	volatile uint32_t DIER;
	volatile uint32_t SR;
	volatile uint32_t EGR;
	volatile uint32_t CCMR1;
	volatile uint32_t CCMR2;
	volatile uint32_t CCER;
	volatile uint32_t CNT;
	volatile uint32_t PSC;
	volatile uint32_t ARR;
	volatile uint32_t RCR;
	volatile uint32_t CCR1;
	volatile uint32_t CCR2;
	volatile uint32_t CCR3;
	volatile uint32_t CCR4;
	volatile uint32_t BDTR;
	volatile uint32_t DCR;
	volatile uint32_t DMAR;
	volatile uint32_t TIM_OR;
 }TIM_RegDef_t;

//Definición de periféricos
#define GPIOA 	((GPIO_RegDef_t *) GPIOA_BASEADDR)
#define GPIOB 	((GPIO_RegDef_t *) GPIOB_BASEADDR)
#define GPIOC 	((GPIO_RegDef_t *) GPIOC_BASEADDR)
#define GPIOD 	((GPIO_RegDef_t *) GPIOD_BASEADDR)
#define GPIOE 	((GPIO_RegDef_t *) GPIOE_BASEADDR)
#define GPIOH 	((GPIO_RegDef_t *) GPIOH_BASEADDR)

#define RCC 	((RCC_RegDef_t *) RCC_BASEADDR)

#define SYSCFG 	((SYSCFG_RegDef_t *) SYSCFG_BASEADDR)

#define EXTI 	((EXTI_RegDef_t *) EXTI_BASEADDR)

#define PWR		((PWR_RegDef_t *) PWR_BASEADDR)

#define TIM1	((TIM_RegDef_t *) TIM1_BASEADDR)
#define TIM2	((TIM_RegDef_t *) TIM2_BASEADDR)
#define TIM3	((TIM_RegDef_t *) TIM3_BASEADDR)
#define TIM4	((TIM_RegDef_t *) TIM4_BASEADDR)
#define TIM5	((TIM_RegDef_t *) TIM5_BASEADDR)
#define TIM9	((TIM_RegDef_t *) TIM9_BASEADDR)
#define TIM10	((TIM_RegDef_t *) TIM10_BASEADDR)
#define TIM11	((TIM_RegDef_t *) TIM11_BASEADDR)

//Habilitar clock de periféricos
#define GPIOA_EN_CLK()		(RCC->AHB1ENR |= (1 << 0))
#define GPIOB_EN_CLK()		(RCC->AHB1ENR |= (1 << 1))
#define GPIOC_EN_CLK()		(RCC->AHB1ENR |= (1 << 2))
#define GPIOD_EN_CLK()		(RCC->AHB1ENR |= (1 << 3))
#define GPIOE_EN_CLK()		(RCC->AHB1ENR |= (1 << 4))
#define GPIOH_EN_CLK()		(RCC->AHB1ENR |= (1 << 7))

#define SYSCFG_EN_CLK()		(RCC->APB2ENR |= (1 << 14))

#define PWR_EN_CLK()		(RCC->APB1ENR |= (1 << 28))

#define TIM1_EN_CLK()		(RCC->APB2ENR |= (1 << RCC_APB2ENR_TIM1EN))
#define TIM2_EN_CLK()		(RCC->APB1ENR |= (1 << RCC_APB1ENR_TIM2EN))
#define TIM3_EN_CLK()		(RCC->APB1ENR |= (1 << RCC_APB1ENR_TIM3EN))
#define TIM4_EN_CLK()		(RCC->APB1ENR |= (1 << RCC_APB1ENR_TIM4EN))
#define TIM5_EN_CLK()		(RCC->APB1ENR |= (1 << RCC_APB1ENR_TIM5EN))
#define TIM9_EN_CLK()		(RCC->APB2ENR |= (1 << RCC_APB2ENR_TIM9EN))
#define TIM10_EN_CLK()		(RCC->APB2ENR |= (1 << RCC_APB2ENR_TIM10EN))
#define TIM11_EN_CLK()		(RCC->APB2ENR |= (1 << RCC_APB2ENR_TIM11EN))

//Deshabilitar clock de periféricos
#define GPIOA_DIS_CLK()		(RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_DIS_CLK()		(RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_DIS_CLK()		(RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_DIS_CLK()		(RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_DIS_CLK()		(RCC->AHB1ENR &= ~(1 << 4))
#define GPIOH_DIS_CLK()		(RCC->AHB1ENR &= ~(1 << 7))

#define SYSCFG_DIS_CLK()	(RCC->APB2ENR &= ~(1 << 14))

#define PWR_DIS_CLK()		(RCC->APB1ENR &= ~(1 << 28))

#define TIM1_DIS_CLK()		(RCC->APB2ENR &= ~(1 << RCC_APB2ENR_TIM1EN))
#define TIM2_DIS_CLK()		(RCC->APB1ENR &= ~(1 << RCC_APB1ENR_TIM2EN))
#define TIM3_DIS_CLK()		(RCC->APB1ENR &= ~(1 << RCC_APB1ENR_TIM3EN))
#define TIM4_DIS_CLK()		(RCC->APB1ENR &= ~(1 << RCC_APB1ENR_TIM4EN))
#define TIM5_DIS_CLK()		(RCC->APB1ENR &= ~(1 << RCC_APB1ENR_TIM5EN))
#define TIM9_DIS_CLK()		(RCC->APB2ENR &= ~(1 << RCC_APB2ENR_TIM9EN))
#define TIM10_DIS_CLK()		(RCC->APB2ENR &= ~(1 << RCC_APB2ENR_TIM10EN))
#define TIM11_DIS_CLK()		(RCC->APB2ENR &= ~(1 << RCC_APB2ENR_TIM11EN))

//Reset de periférico
#define GPIOA_RESET() 		do{(RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0));}while(0)
#define GPIOB_RESET() 		do{(RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR &= ~(1 << 1));}while(0)
#define GPIOC_RESET() 		do{(RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR &= ~(1 << 2));}while(0)
#define GPIOD_RESET() 		do{(RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR &= ~(1 << 3));}while(0)
#define GPIOE_RESET() 		do{(RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4));}while(0)
#define GPIOH_RESET() 		do{(RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR &= ~(1 << 7));}while(0)

//Macro para obtener el número de puerto
#define PORT_NUMBER(x)		((x == GPIOA) ? 0 : \
							 (x == GPIOB) ? 1 : \
							 (x == GPIOC) ? 2 : \
							 (x == GPIOD) ? 3 : \
							 (x == GPIOE) ? 4 : 5)

#define IRQ_EXTI15_10		40
#define IRQ_TIM1_CC			27
#define IRQ_TIM1_BRK_TIM9	24
#define IRQ_TIM1_UP_TIM10	25
#define IRQ_TIM2			28

#define RCC_CR_HSION		0
#define RCC_CR_HSIRDY		1
#define RCC_CR_HSITRIM		3
#define RCC_CR_HSICAL		8
#define RCC_CR_HSEON		16
#define RCC_CR_HSERDY		17
#define RCC_CR_HSEBYP		18
#define RCC_CR_CSSON		19
#define RCC_CR_PLLON		24
#define RCC_CR_PLLRDY		25
#define RCC_CR_PLLI2SON		26
#define RCC_CR_PLLI2SRDY	27


#define RCC_PLLCFGR_PLLMO	0
#define RCC_PLLCFGR_PLLM1	1
#define RCC_PLLCFGR_PLLM2	2
#define RCC_PLLCFGR_PLLM3	3
#define RCC_PLLCFGR_PLLM4	4
#define RCC_PLLCFGR_PLLM5	5
#define RCC_PLLCFGR_PLLN	6
#define RCC_PLLCFGR_PLLP0	16
#define RCC_PLLCFGR_PLLP1	17
#define RCC_PLLCFGR_PLLSRC	22
#define RCC_PLLCFGR_PLLQ0	24
#define RCC_PLLCFGR_PLLQ1	25
#define RCC_PLLCFGR_PLLQ2	26
#define RCC_PLLCFGR_PLLQ3	27


#define RCC_CFGR_SW0		0
#define RCC_CFGR_SW1		1
#define RCC_CFGR_SWS0		2
#define RCC_CFGR_SWS1		3
#define RCC_CFGR_HPRE		4
#define RCC_CFGR_PPRE1		10
#define RCC_CFGR_PPRE2		13
#define RCC_CFGR_RTCPRE		16
#define RCC_CFGR_MCO1		21
#define RCC_CFGR_I2SSCR		23
#define RCC_CFGR_MCO1PRE	24
#define RCC_CFGR_MCO2PRE	27
#define RCC_CFGR_MCO2		30


#define RCC_CIR_LSIRDYF		0
#define RCC_CIR_LSERDYF		1
#define RCC_CIR_HSIRDYF		2
#define RCC_CIR_HSERDYF		3
#define RCC_CIR_PLLRDYF		4
#define RCC_CIR_PLLI2SRDYF	5
#define RCC_CIR_CSSF		7
#define RCC_CIR_LSIRDYIE	8
#define RCC_CIR_LSERDYIE	9
#define RCC_CIR_HSIRDYIE	10
#define RCC_CIR_HSERDYIE	11
#define RCC_CIR_PLLRDYIE	12
#define RCC_CIR_PLLI2SRDYIE	13
#define RCC_CIR_LSIRDYC		16
#define RCC_CIR_LSERDYC		17
#define RCC_CIR_HSIRDYC		18
#define RCC_CIR_HSERDYC		19
#define RCC_CIR_PLLRDYC		20
#define RCC_CIR_PLLI2SRDYC	21
#define RCC_CIR_CSSC		23

#define RCC_BDCR_LSEON		0
#define RCC_BDCR_LSERDY		1
#define RCC_BDCR_LSEBYP		2
#define RCC_BDCR_LSEMOD		3
#define RCC_BDCR_RTCSEL		8
#define RCC_BDCR_RTCEN		9
#define RCC_BDCR_BDRST		16

#define RCC_CSR_LSION		0
#define RCC_CSR_LSIRDY		1

#define PWR_CR_DBP			8

#define RCC_APB1ENR_TIM2EN	0
#define RCC_APB1ENR_TIM3EN	1
#define RCC_APB1ENR_TIM4EN	2
#define RCC_APB1ENR_TIM5EN	3

#define RCC_APB2ENR_TIM1EN	0
#define RCC_APB2ENR_TIM9EN	16
#define RCC_APB2ENR_TIM10EN	17
#define RCC_APB2ENR_TIM11EN	18

#define TIM_CR1_CEN			0
#define TIM_CR1_UDIS		1
#define TIM_CR1_URS			2
#define TIM_CR1_OPM			3
#define TIM_CR1_DIR			4
#define TIM_CR1_CMS			5
#define TIM_CR1_ARPE		7
#define TIM_CR1_CKD			8

#define TIM_CR2_CCPC		0
#define TIM_CR2_CCUS		2
#define TIM_CR2_CCDS		3
#define TIM_CR2_MMS			4
#define TIM_CR2_TI1S		7
#define TIM_CR2_OIS1		8
#define TIM_CR2_OIS1N		9
#define TIM_CR2_OIS2		10
#define TIM_CR2_OIS2N		11
#define TIM_CR2_OIS3		12
#define TIM_CR2_OIS3N		13
#define TIM_CR2_OIS4		14

#define TIM_SMCR_SMS		0
#define TIM_SMCR_TS			4
#define TIM_SMCR_MSM		7
#define TIM_SMCR_ETF		8
#define TIM_SMCR_ETPS		12
#define TIM_SMCR_ECE		14
#define TIM_SMCR_ETP		15

#define TIM_DIER_UIE		0
#define TIM_DIER_CC1IE		1
#define TIM_DIER_CC2IE		2
#define TIM_DIER_CC3IE		3
#define TIM_DIER_CC4IE		4
#define TIM_DIER_COMIE		5
#define TIM_DIER_TIE		6
#define TIM_DIER_BIE		7
#define TIM_DIER_UDE		8
#define TIM_DIER_CC1DD		9
#define TIM_DIER_CC2DE		10
#define TIM_DIER_CC3DE		11
#define TIM_DIER_CC4DE		12
#define TIM_DIER_COMDE		13
#define TIM_DIER_TDE		14

#define TIM_SR_UIF			0
#define TIM_SR_CC1IF		1
#define TIM_SR_CC2IF		2
#define TIM_SR_CC3IF		3
#define TIM_SR_CC4IF		4
#define TIM_SR_COMIF		5
#define TIM_SR_TIF			6
#define TIM_SR_BIF			7
#define TIM_SR_CC1OF		9
#define TIM_SR_CC2OF		10
#define TIM_SR_CC3OF		11
#define TIM_SR_CC4OF		12

#define TIM_EGR_UG			0
#define TIM_EGR_CC1G		1
#define TIM_EGR_CC2G		2
#define TIM_EGR_CC3G		3
#define TIM_EGR_CC4G		4
#define TIM_EGR_COMG		5
#define TIM_EGR_TG			6
#define TIM_EGR_BG			7

#define TIM_CCMR1_CC1S		0
#define TIM_CCMR1_OC1FE		2
#define TIM_CCMR1_OC1PE		3
#define TIM_CCMR1_OC1M		4
#define TIM_CCMR1_OC1CE		7
#define TIM_CCMR1_CC2S		8
#define TIM_CCMR1_OC2FE		10
#define TIM_CCMR1_OC2PE		11
#define TIM_CCMR1_OC2M		12
#define TIM_CCMR1_OC2CE		15

#define TIM_CCMR1_IC1PSC	2
#define TIM_CCMR1_IC1F		4
#define TIM_CCMR1_IC2PSC	10
#define TIM_CCMR1_IC2F		12

#define TIM_CCMR2_CC3S		0
#define TIM_CCMR2_OC3FE		2
#define TIM_CCMR2_OC3PE		3
#define TIM_CCMR2_OC3M		4
#define TIM_CCMR2_OC3CE		7
#define TIM_CCMR2_CC4S		8
#define TIM_CCMR2_OC4FE		10
#define TIM_CCMR2_OC4PE		11
#define TIM_CCMR2_OC4M		12
#define TIM_CCMR2_OC4CE		15

#define TIM_CCMR2_IC3PSC	2
#define TIM_CCMR2_IC3F		4
#define TIM_CCMR2_IC4PSC	10
#define TIM_CCMR2_IC4F		12

#define TIM_CCER_CC1E		0
#define TIM_CCER_CC1P		1
#define TIM_CCER_CC1NE		2
#define TIM_CCER_CC1NP		3
#define TIM_CCER_CC2E		4
#define TIM_CCER_CC2P		5
#define TIM_CCER_CC2NE		6
#define TIM_CCER_CC2NP		7
#define TIM_CCER_CC3E		8
#define TIM_CCER_CC3P		9
#define TIM_CCER_CC3NE		10
#define TIM_CCER_CC3NP		11
#define TIM_CCER_CC4E		12
#define TIM_CCER_CC4P		13
#define TIM_CCER_CC4NP		15

#define TIM_RCR_REP			0

#define TIM_BDTR_DTG		0
#define TIM_BDTR_LOCK		8
#define TIM_BDTR_OSSI		10
#define TIM_BDTR_OSSR		11
#define TIM_BDTR_BKE		12
#define TIM_BDTR_BKP		13
#define TIM_BDTR_AOE		14
#define TIM_BDTR_MOE		15

#define TIM_DCR_DBA			0
#define TIM_DCR_DBL			8

//Máscaras de bits
#define TIM_IT_UIE			((uint16_t) 0x0001)
#define TIM_IT_CC1IE		((uint16_t) 0x0002)
#define TIM_IT_CC2IE		((uint16_t) 0x0004)
#define TIM_IT_CC3IE		((uint16_t) 0x0008)
#define TIM_IT_CC4IE		((uint16_t) 0x0010)
#define TIM_IT_COMIE		((uint16_t) 0x0020)
#define TIM_IT_TIE			((uint16_t) 0x0040)
#define TIM_IT_BIE			((uint16_t) 0x0080)
#define TIM_IT_UDE			((uint16_t) 0x0100)
#define TIM_IT_CC1DE		((uint16_t) 0x0200)
#define TIM_IT_CC2DE		((uint16_t) 0x0400)
#define TIM_IT_CC3DE		((uint16_t) 0x0800)
#define TIM_IT_CC4DE		((uint16_t) 0x1000)
#define TIM_IT_COMDE		((uint16_t) 0x2000)
#define TIM_IT_TDE			((uint16_t) 0x4000)

#endif /* DRIVERS_SRC_STM32F411XX_H_ */
