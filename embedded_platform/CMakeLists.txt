#############################################################################################################################
# file:  CMakeLists.txt
# brief: Template "CMakeLists.txt" for building of executables and static libraries.
#
# usage: Edit "VARIABLES"-section to suit project requirements.
#        For debug build:
#          cmake -DCMAKE_TOOLCHAIN_FILE=cubeide-gcc.cmake  -S ./ -B Debug -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug
#          make -C Debug VERBOSE=1
#        For release build:
#          cmake -DCMAKE_TOOLCHAIN_FILE=cubeide-gcc.cmake  -S ./ -B Release -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
#          make -C Release VERBOSE=1
#############################################################################################################################
cmake_minimum_required(VERSION 3.20)

MESSAGE(STATUS "--- USING EMBEDDED PLATFORM ---")

set (PROJECT_SOURCES
	Startup/startup_stm32f411retx.s
	src/syscalls.c
	src/sysmem.c
    src/io.c
    src/api.c
    Drivers/src/stm32f411xx_gpio.c
)

set (PROJECT_INCLUDES
    include/
)
set (DRIVERS_INCLUDES
    Drivers/Inc/
)

project(EmbeddedPlatform)
enable_language(ASM)

add_library(
    ${PROJECT_NAME}
    ${PROJECT_SOURCES}
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    ${PROJECT_INCLUDES}
    ${DRIVERS_INCLUDES}
)

if(NOT DEFINED READ_ENV_FILE)
    set(READ_ENV_FILE FALSE)
endif()

if(NOT DEFINED TEST AND READ_ENV_FILE)
    file(STRINGS ../.env ENV_FILE)
    
    # Lines 0 and 1 of the .env file are ignored. They are not useful in the build process.
    list(GET ENV_FILE 2 BASIC_AUTHORIZATION_BASE64)
    list(GET ENV_FILE 3 REFRESH_TOKEN)

    add_definitions(-DBASIC_AUTHORIZATION_BASE64="${BASIC_AUTHORIZATION_BASE64}")
    add_definitions(-DREFRESH_TOKEN="${REFRESH_TOKEN}")
elseif(DEFINED BASIC_AUTHORIZATION_BASE64 AND DEFINED REFRESH_TOKEN)
    add_definitions(-DBASIC_AUTHORIZATION_BASE64="${BASIC_AUTHORIZATION_BASE64}")
    add_definitions(-DREFRESH_TOKEN="${REFRESH_TOKEN}")
endif()