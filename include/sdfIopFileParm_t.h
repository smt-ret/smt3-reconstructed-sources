#pragma once
#include "types.h"

typedef struct sdfFileCmdHandle_t sdfFileCmdHandle_t;
typedef struct sdfIopFileParm_t sdfIopFileParm_t;

struct sdfIopFileParm_t {
    sdfFileCmdHandle_t *handle;
    s32 ptr;
    s32 size;
};
