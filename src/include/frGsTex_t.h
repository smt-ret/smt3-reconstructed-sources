#pragma once
#include "types.h"

typedef struct frGsTex_t frGsTex_t;

struct frGsTex_t {
    u32 Width;
    u32 Width2;
    u32 Height;
    u32 Height2;
    u32 Addr;
    u32 BufWidth;
};
