#pragma once
#include "types.h"

typedef struct pbError_t pbError_t;

struct pbError_t {
    u32 code;
    u32 cnt;
    u32 frame;
};
