#pragma once
#include "types.h"

typedef struct sdfPacDecodeClass sdfPacDecodeClass;

struct sdfPacDecodeClass {
    u32 dataSize;
    u32 addrInfoSize;
    u32 pad[2];
};
