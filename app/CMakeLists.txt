cmake_minimum_required(VERSION 3.17)
MESSAGE(STATUS "--- Building App: SUFFIX: ${CMAKE_EXECUTABLE_SUFFIX} ---")
project(App)
if(DEFINED TEST)
    MESSAGE(STATUS "--- INCLUDING TESTS IN BUILD ---")
    add_executable(
        ${PROJECT_NAME}${CMAKE_EXECUTABLE_SUFFIX}
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

if(DEFINED DESKTOP)
    MESSAGE(STATUS "[${PROJECT_NAME}] Linking DESKTOP libraries")
    target_link_libraries(
        ${PROJECT_NAME}
        PRIVATE
        DesktopPlatform
    )
elseif(DEFINED EMBEDDED)
    MESSAGE(STATUS "[${PROJECT_NAME}] Linking EMBEDDED libraries")
    target_link_libraries(
        ${PROJECT_NAME}
        PRIVATE
        EmbeddedPlatform
    )
endif()

MESSAGE(STATUS "--- Finished building App ---")