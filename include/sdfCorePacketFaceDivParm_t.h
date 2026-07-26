#pragma once
#include "types.h"

typedef struct sdfCorePacketFaceDivParm_t sdfCorePacketFaceDivParm_t;

struct sdfCorePacketFaceDivParm_t {
    f32 pad0;
    f32 bias;
    f32 pad1;
    f32 coeff;
    sdfVector4_t colA;
    sdfVector4_t colB;
};
