#pragma once
#include "types.h"

typedef struct datUnitWork_s datUnitWork_t;
typedef struct typeNbResultWork typeNbResultWork;

struct typeNbResultWork {
    s32 useflg;
    s32 exp_cnt;
    s32 l_lv;
    s32 lvupflg;
    s32 unitidx;
    datUnitWork_t *unit;
    s32 lvupanmflg;
    s32 lvupanmcnt;
    s32 lvuplvanmcnt;
    s32 ofsx;
    s32 stopcnt;
    s32 addexp;
    s32 resultadd;
};
