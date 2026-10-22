#pragma once
#include "types.h"

typedef struct packetregist_ALPHA_tag packetregist_ALPHA_tag;
typedef struct sdfGrPacketHeader_t sdfGrPacketHeader_t;
typedef struct sdfGrTagStdReg_t sdfGrTagStdReg_t;

struct packetregist_ALPHA_tag {
    sdfGrPacketHeader_t *header;
    sdfGrTagStdReg_t *alpha;
};
