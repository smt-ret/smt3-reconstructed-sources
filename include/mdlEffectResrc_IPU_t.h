#pragma once
#include "types.h"

typedef struct mdlEffectResrc_IPU_t mdlEffectResrc_IPU_t;
typedef struct sdfIpuDecodeCb_t sdfIpuDecodeCb_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

struct mdlEffectResrc_IPU_t {
    void *data;
    sdfMemHandle_t *dataMemHandle;
    u8 busy;
    u8 playing;
    u8 pad[UNKNOWN_ARRAY_SIZE];
    sdfTexHandle_t *tex;
    s32 dataSize;
    s32 pad2[UNKNOWN_ARRAY_SIZE];
    sdfIpuDecodeCb_t *decodeCb;
};
