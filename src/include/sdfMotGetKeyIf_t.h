#pragma once
#include "types.h"

typedef struct sdfMotGetKeyIf_t sdfMotGetKeyIf_t;

struct sdfMotGetKeyIf_t {
    u8 *key_frame;
    s32 basePtr;
    s32 nextPtr;
    f32 rate;
};
