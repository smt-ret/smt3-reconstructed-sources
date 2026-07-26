#pragma once
#include "types.h"

typedef struct packettestalpha_tag packettestalpha_tag;
typedef struct sdfGrPacketHeader_t sdfGrPacketHeader_t;
typedef struct sdfGrTagStdReg_t sdfGrTagStdReg_t;

struct packettestalpha_tag {
    sdfGrPacketHeader_t *header;
    sdfGrTagStdReg_t *test;
    sdfGrTagStdReg_t *alpha;
};
