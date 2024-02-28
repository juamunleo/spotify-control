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
elseif(DEFINED EMBEDDED)
    set(ignoreMe "${EMBEDDED}")
    add_subdirectory(embedded_platform)
endif()

add_subdirectory(app)