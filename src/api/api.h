#ifndef SRC_API_API_H
#define SRC_API_API_H

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    RequestType_Stop,
    RequestType_Play,
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
} ApiRequest_t;

void api_init(void);
void api_makeRequest(ApiRequest_t * request);

#endif