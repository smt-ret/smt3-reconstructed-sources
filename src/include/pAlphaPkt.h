#pragma once
#include "types.h"

typedef struct pAlphaPkt pAlphaPkt;
typedef struct sdfGrPacketHeader_t sdfGrPacketHeader_t;
typedef struct sdfGrTagStdReg_t sdfGrTagStdReg_t;

struct pAlphaPkt {
    sdfGrPacketHeader_t *header;
    sdfGrTagStdReg_t *alpha;
};
