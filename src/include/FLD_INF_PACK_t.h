#pragma once
#include "types.h"

typedef struct FLD_INF_PACK2_t FLD_INF_PACK2_t;
typedef struct FLD_INF_PACK_t FLD_INF_PACK_t;

struct FLD_INF_PACK_t {
    s32 Idx;
    FLD_INF_PACK2_t *EveHit[5];
};
