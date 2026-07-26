#pragma once
#include "types.h"

typedef struct sdfMemHandleCB_tag sdfMemHandleCB_tag;
typedef struct sdfMemHandle_t sdfMemHandle_tag;

struct sdfMemHandleCB_tag {
    sdfMemHandle_tag *headGuard;
    sdfMemHandle_tag *tailGuard;
    void *allocPtr;
    s32 allocSize;
};
