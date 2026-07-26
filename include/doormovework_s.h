#pragma once
#include "types.h"

typedef struct doormovework_s doormovework_s;

struct doormovework_s {
    s32 stat;
    s32 evehit_resid;
    s32 mode1;
    s32 matter_resid1;
    s32 mode2;
    s32 matter_resid2;
    s32 cnt1;
    s32 cnt2;
    s32 cntmax;
    f32 x1;
    f32 y1;
    f32 z1;
    f32 mx1;
    f32 my1;
    f32 mz1;
    f32 x2;
    f32 y2;
    f32 z2;
    f32 mx2;
    f32 my2;
    f32 mz2;
};
