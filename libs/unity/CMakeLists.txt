cmake_minimum_required(VERSION 3.17)
project(Unity)

add_library(
    ${PROJECT_NAME}
    src/unity.c
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    include/
)