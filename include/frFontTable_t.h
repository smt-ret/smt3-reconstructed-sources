#pragma once
#include "types.h"

typedef struct _FRQ _FRQ;
typedef struct _RING_BUF _RING_BUF;
typedef struct frFontData_t frFontData_t;
typedef struct frFontTable_t frFontTable_t;
typedef struct frGsTex_t frGsTex_t;
typedef struct sdfGsMemSlice_t sdfGsMemSlice_t;
typedef struct sdfImageSetParm_t sdfImageSetParm_t;

struct frFontTable_t {
    frFontData_t *pFont[9];
    s32 GsFontNums;
    s32 TextHandleNums;
    s32 FontHandleNums;
    _RING_BUF *pTextRing;
    _RING_BUF *pRequestRing;
    sdfGsMemSlice_t *TexMh;
    sdfGsMemSlice_t *ClutMh;
    frGsTex_t *GsTex;
    u32 GsClutAddr[6];
    sdfImageSetParm_t *Trans;
    _FRQ *DestroyHandleList[2];
};
