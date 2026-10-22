#pragma once
#include "types.h"

typedef struct mviDebugCb_t mviDebugCb_t;
typedef struct sdfMovieCb_t sdfMovieCb_t;

struct mviDebugCb_t {
    u8 init;
    u8 cursor;
    u8 ioAct;
    u8 memAct;
    s32 ioAddr;
    sdfMovieCb_t *memAddr;
    s32 ioData;
    u8 memData[64];
};
