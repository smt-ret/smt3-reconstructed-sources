#pragma once
#include "types.h"

typedef struct FLD_INF_START_t FLD_INF_START_t;

struct FLD_INF_START_t {
    s16 Type;
    u16 Area;
    u16 Action;
    char *EveHit;
};
