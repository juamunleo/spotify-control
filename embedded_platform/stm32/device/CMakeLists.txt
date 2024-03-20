cmake_minimum_required(VERSION 3.20)
project(STM32DEVICE)

set (PROJECT_INCLUDES
    include/
)

add_library(
    ${PROJECT_NAME}
    src/main.c
)

target_compile_definitions(
    ${PROJECT_NAME}
    PUBLIC
    STM32F411xE
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    ${PROJECT_INCLUDES}
)