#pragma once
#include "types.h"

typedef struct effBTL_t effBTL_t;
typedef struct effPCPBezierBillParam_t effPCPBezierBillParam_t;
typedef struct effPCPBezierBillPart_tag effPCPBezierBillPart_tag;
typedef struct effPCPBezierBill_tag effPCPBezierBill_tag;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct effPCPBezierBill_tag {
    effPCPBezierBillParam_t *param;
    effPCPBezierBillPart_tag pPart[UNKNOWN_ARRAY_SIZE];
    u32 abgr;
    effBTL_t *hBED;
    u8 original;
    sdfMemHandle_t *hMem;
};
