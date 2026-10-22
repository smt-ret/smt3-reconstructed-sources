#pragma once
#include "types.h"

typedef struct pTexPkt pTexPkt;
typedef struct sdfGrPacketHeader_t sdfGrPacketHeader_t;
typedef struct sdfGrTagStdReg_t sdfGrTagStdReg_t;

struct pTexPkt {
    sdfGrPacketHeader_t *header;
    sdfGrTagStdReg_t *texa;
    sdfGrTagStdReg_t *texflush;
};
