#pragma once
#include "types.h"

typedef struct packetregist_TEST_tag packetregist_TEST_tag;
typedef struct sdfGrPacketHeader_t sdfGrPacketHeader_t;
typedef struct sdfGrTagStdReg_t sdfGrTagStdReg_t;

struct packetregist_TEST_tag {
    sdfGrPacketHeader_t *header;
    sdfGrTagStdReg_t *test;
};
