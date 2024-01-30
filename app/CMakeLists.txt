cmake_minimum_required(VERSION 3.17)
project(App)

if(DEFINED TEST)
    MESSAGE(STATUS "--- INCLUDING TESTS IN BUILD ---")
    add_executable(
        ${PROJECT_NAME}
        src/player.c
        test/main_test.c
        test/player_test.c
    )
    target_include_directories(
        ${PROJECT_NAME}
        PRIVATE
        include/
        test/
        src/
    )
    target_link_libraries(
        ${PROJECT_NAME}
        PRIVATE
        Unity
    )
    add_test(${PROJECT_NAME}Tests ${PROJECT_NAME})
else()
    add_executable(
        ${PROJECT_NAME}
        src/main.c
        src/application.c
        src/player.c
    )
endif()

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