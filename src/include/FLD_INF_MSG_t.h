#pragma once
#include "types.h"

typedef struct FLD_INF_MSG_t FLD_INF_MSG_t;

struct FLD_INF_MSG_t {
    s16 Type;
    s16 Msg;
    u8 Go[4];
    s16 FlgOffOn[2];
    u16 View;
    u16 Ex;
};
