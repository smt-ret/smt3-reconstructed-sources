#pragma once
#include "types.h"

typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfPacTmxDecodeCb_t sdfPacTmxDecodeCb_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

struct sdfPacTmxDecodeCb_t {
    sdfTexHandle_t *texHandle;
    sdfMemHandle_t *memHandle;
    void *workPtr;
    s32 rest;
};
