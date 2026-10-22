#pragma once
#include "types.h"

typedef struct FLD_INF_FLG_t FLD_INF_FLG_t;
typedef struct FLD_INF_MSG_t FLD_INF_MSG_t;
typedef struct FLD_INF_SET_t FLD_INF_SET_t;
typedef struct FLD_INF_START_t FLD_INF_START_t;

struct FLD_INF_SET_t {
    FLD_INF_START_t *st;
    FLD_INF_FLG_t *fl[4];
    FLD_INF_MSG_t *ms[20];
};
