cmake_minimum_required(VERSION 3.17)
project(SpotifyApi)

if(NOT DEFINED READ_ENV_FILE)
    set(READ_ENV_FILE TRUE)
endif()

find_package(CURL REQUIRED)
message(STATUS ${CURL_INCLUDE_DIR}/curl)


if(READ_ENV_FILE)
    file(STRINGS .env ENV_FILE)

    list(GET ENV_FILE 0 CLIENT_ID)
    list(GET ENV_FILE 1 CLIENT_SECRET)

    add_definitions(-DCLIENT_ID="${CLIENT_ID}")
    add_definitions(-DCLIENT_SECRET="${CLIENT_SECRET}")

    message(STATUS "CLIENT_ID=${CLIENT_ID}")
    message(STATUS "CLIENT_SECRET=${CLIENT_SECRET}")
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