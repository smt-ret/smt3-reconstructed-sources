#pragma once
#include "types.h"

typedef struct pbErrorCode_t pbErrorCode_t;

struct pbErrorCode_t {
    u32 col;
    u8 mes[128];
};
