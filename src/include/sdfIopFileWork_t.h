#pragma once
#include "types.h"

typedef struct sdfFileCmdHandle_t sdfFileCmdHandle_t;
typedef struct sdfIopFileWork_t sdfIopFileWork_t;

struct sdfIopFileWork_t {
    sdfFileCmdHandle_t *fileHandle;
    s32 semaId;
    s32 fileSize;
    s32 readSize;
    s32 readPtr;
    s32 readTotal;
};
