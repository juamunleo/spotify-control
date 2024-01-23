cmake_minimum_required(VERSION 3.17)
project(SpotifyPlayer)

add_library(
    ${PROJECT_NAME}
    src/application/application.c
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    src/application
)