cmake_minimum_required(VERSION 3.17)
project(SpotifyControl)

if(DEFINED TEST)
    set(ignoreMe "${TEST}")
    include(CTest)
    enable_testing()
    add_subdirectory(libs/unity)
endif()

if(DEFINED DESKTOP)
    set(ignoreMe "${DESKTOP}")
    add_subdirectory(desktop_platform)
endif()

add_subdirectory(app)