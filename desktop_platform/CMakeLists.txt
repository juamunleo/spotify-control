cmake_minimum_required(VERSION 3.17)
project(DesktopPlatform)

find_package(CURL REQUIRED)

add_subdirectory(libs/parson)

add_library(
    ${PROJECT_NAME}
    src/api.c
    src/io.c
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    include/
    ${CURL_INCLUDE_DIR}
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    JsonLibrary
    ${CURL_LIBRARIES}
)

if(NOT DEFINED READ_ENV_FILE)
    set(READ_ENV_FILE TRUE)
endif()

if(NOT DEFINED TEST AND READ_ENV_FILE)
    file(STRINGS ../.env ENV_FILE)
    
    # Lines 0 and 1 of the .env file are ignored. They are not useful in the build process.
    list(GET ENV_FILE 2 BASIC_AUTHORIZATION_BASE64)
    list(GET ENV_FILE 3 REFRESH_TOKEN)

    add_definitions(-DBASIC_AUTHORIZATION_BASE64="${BASIC_AUTHORIZATION_BASE64}")
    add_definitions(-DREFRESH_TOKEN="${REFRESH_TOKEN}")
endif()