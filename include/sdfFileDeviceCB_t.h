#pragma once
#include "types.h"

typedef struct sdfFileCmdHandle_t sdfFileCmdHandle_t;
typedef struct sdfFileDeviceCB_t sdfFileDeviceCB_t;

struct sdfFileDeviceCB_t {
    s32 thId;
    s32 semaId;
    sdfFileCmdHandle_t *head;
    sdfFileCmdHandle_t *tail;
    s32 count;
    s32 blockSize;
};
