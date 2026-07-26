#pragma once
#include "types.h"

typedef struct sdfDrawReqRec_t sdfDrawReqRec_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfPreDrawHook_t sdfPreDrawHook_t;

struct sdfDrawReqRec_t {
    sdfDrawTag_t *drawTag;
    sdfPreDrawHook_t *preDraw;
    u8 drawCount;
    u8 buffId;
    u8 drawFrameId;
    u8 halfOffsetId;
    u32 pad1;
};
