#pragma once
#include "types.h"

typedef struct FLD_SEED_WORK_t FLD_SEED_WORK_t;

struct FLD_SEED_WORK_t {
    f32 x;
    f32 y;
    f32 z;
    s16 flg;
    u16 spd;
    u16 rgbofs;
    s16 life;
    s16 alp;
};
