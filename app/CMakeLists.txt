cmake_minimum_required(VERSION 3.17)
project(App)

add_executable(
    ${PROJECT_NAME}
    src/main.c
    src/application.c
    src/player.c
)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    include/
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    DesktopPlatform
)