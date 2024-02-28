#ifndef EMBEDDED_PLATFORM_INCLUDE_API_H
#define EMBEDDED_PLATFORM_INCLUDE_API_H

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    RequestType_PlayPause,
    RequestType_Next,
    RequestType_Prev,
    RequestType_Vol,
    RequestType_Random,
    RequestType_Undefined
} RequestType_t;

typedef struct {
    RequestType_t type;
    uint8_t volumePercent;
    bool randomEnabled;
    bool playEnabled;
} ApiRequest_t;

void api_init(void);
void api_makeRequest(ApiRequest_t * request);

#endif