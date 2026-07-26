#pragma once
#include "types.h"

typedef struct frDrawCommonPktPac_t frDrawCommonPktPac_t;
typedef struct frDrawFontPkt_t frDrawFontPkt_t;

struct frDrawFontPkt_t {
    frDrawCommonPktPac_t *top;
    frDrawCommonPktPac_t *pkt;
};
