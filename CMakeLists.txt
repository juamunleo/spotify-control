cmake_minimum_required(VERSION 3.17)
project(SpotifyApi)

if(NOT DEFINED READ_ENV_FILE)
    set(READ_ENV_FILE TRUE)
endif()

find_package(CURL REQUIRED)
message(STATUS ${CURL_INCLUDE_DIR}/curl)


if(READ_ENV_FILE)
    file(STRINGS .env ENV_FILE)
    
    # Lines 0 and 1 of the .env file are ignored. They are not useful in the build process.
    list(GET ENV_FILE 2 BASIC_AUTHORIZATION_BASE64)
    list(GET ENV_FILE 3 REFRESH_TOKEN)

    add_definitions(-DBASIC_AUTHORIZATION_BASE64="${BASIC_AUTHORIZATION_BASE64}")
    add_definitions(-DREFRESH_TOKEN="${REFRESH_TOKEN}")

    message(STATUS "BASIC_AUTHORIZATION_BASE64=${BASIC_AUTHORIZATION_BASE64}")
    message(STATUS "REFRESH_TOKEN=${REFRESH_TOKEN}")
endif()

add_executable(
    ${PROJECT_NAME}
    src/main.c
    src/application/application.c
    src/io/io.c
    src/player/player.c
    src/api/api.c
    src/json/parson.c
)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    src/application
    src/io
    src/player
    src/api
    src/json
    ${CURL_INCLUDE_DIR}
)

target_link_libraries(
    ${PROJECT_NAME} 
    ${CURL_LIBRARIES}
)