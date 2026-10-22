#pragma once
#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct effHandle_t effHandle_t;
typedef struct fldTakaraWork_tag fldTakaraWork_tag;

struct fldTakaraWork_tag {
    dds3Basic_t *Basic;
    s32 TakaraIdx;
    s32 MotPhase;
    s32 MotPhaseNext;
    f32 x;
    f32 y;
    f32 z;
    f32 r;
    s32 type;
    effHandle_t *d3p;
    s32 fldTakaraTblIdx;
    s32 dmy;
    void *fldObj;
};
