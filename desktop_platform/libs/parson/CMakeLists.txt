cmake_minimum_required(VERSION 3.17)
project(JsonLibrary)

add_library(
    ${PROJECT_NAME}
    src/parson.c
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    include/
)