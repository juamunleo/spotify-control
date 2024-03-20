cmake_minimum_required(VERSION 3.20)
project(STM32HAL)

set (PROJECT_SOURCES
    src/Legacy/stm32f4xx_hal_can.c
    src/Legacy/stm32f4xx_hal_eth.c
    src/stm32f4xx_hal_tim.c
    src/stm32f4xx_hal_tim_ex.c
    src/stm32f4xx_hal_rcc.c
    src/stm32f4xx_hal_rcc_ex.c
    src/stm32f4xx_hal_flash.c
    src/stm32f4xx_hal_flash_ex.c
    src/stm32f4xx_hal_flash_ramfunc.c
    src/stm32f4xx_hal_gpio.c
    src/stm32f4xx_hal_dma_ex.c
    src/stm32f4xx_hal_dma.c
    src/stm32f4xx_hal_pwr.c
    src/stm32f4xx_hal_pwr_ex.c
    src/stm32f4xx_hal_cortex.c
    src/stm32f4xx_hal.c
    src/stm32f4xx_hal_exti.c
)

set (PROJECT_INCLUDES
    include/
    include/Legacy/
)

add_library(
    ${PROJECT_NAME}
    ${PROJECT_SOURCES}
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    ${PROJECT_INCLUDES}
)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC
    STM32DEVICE
    STM32CORE
)