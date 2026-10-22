#pragma once
#include "types.h"

typedef struct sdfPacDecodeClass2 sdfPacDecodeClass2;

struct sdfPacDecodeClass2 {
    u32 dataSize;
    u32 addrInfoSize;
    u32 pad[2];
};
