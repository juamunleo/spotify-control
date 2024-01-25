cmake_minimum_required(VERSION 3.17)
project(SpotifyApi)

add_executable(
    ${PROJECT_NAME}
    src/main.c
    src/application/application.c
    src/io/io.c
    src/player/player.c
)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    src/application
    src/io
    src/player
)