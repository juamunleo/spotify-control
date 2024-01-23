cmake_minimum_required(VERSION 3.17)
project(program)

add_executable(
    ${PROJECT_NAME}
    src/main.c
)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC
    SpotifyPlayer
)