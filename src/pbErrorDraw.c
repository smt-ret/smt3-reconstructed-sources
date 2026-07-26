#include "types.h"

typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct pbProcHandle_t pbProcHandle_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfPrimTransPacket_t sdfPrimTransPacket_t;

static void pbEcode[UNKNOWN_ARRAY_SIZE];

void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
void dds3SetProcessData(dds3ProcessID_t **id, void *data);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
s32 pb_General__PB_PROC_REF_MESS(pbProcHandle_t *p);
void pb_General__PB_PROC_SEND_MESS(pbProcHandle_t *p, s32 mes);
void rsetAlpha(s32 mode);
void rsetOtOfs(s32 otofs);
void rsetTest(s32 ate, s32 atst, s32 aref, s32 afail, s32 date, s32 datm, s32 zte, s32 ztst);
void *sdfDevPrintf(s32 aX, s32 aY, u32 aZ, s32 aAttr, char *aStr, void **LegacyParamArray);
s32 sdfDrawTagInit(sdfDrawTag_t *a);
void sdfDrawTagLink(sdfDrawTag_t *aTag, void *aPacket);
s32 sdfDrawTagLinkOt(s32 a, sdfDrawTag_t *b);
void sdfPrimSetOpaquePacket(sdfPrimTransPacket_t *aPkt);

// 0x1657370
void *dds3PrimFrameRect(s32 aX, s32 aY, u32 aZ, s32 aW, s32 aH, u32 aBgCol, u32 aFrameCol) {
    return 0;
}

// 0x1657d80
dds3ProcessFunc_t *deleteError(dds3ProcessID_t *id) {
    return 0;
}

// 0x16573e0
dds3ProcessFunc_t *error(dds3ProcessID_t *id) {
    pb_General__PB_PROC_REF_MESS(0);
    pb_General__PB_PROC_SEND_MESS(0, 0);
    rsetOtOfs(0);
    rsetAlpha(0);
    rsetTest(0, 0, 0, 0, 0, 0, 0, 0);
    sdfDrawTagInit(0);
    sdfPrimSetOpaquePacket(0);
    sdfDrawTagLink(0, 0);
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLinkOt(0, 0);
    return 0;
}

// 0x1657f30
pbProcHandle_t *pbStartErrorDraw(pbProcHandle_t *parent, u32 eCode, u32 frame) {
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
    dds3LinkProcess(0, 0);
    pb_General__PB_PROC_SEND_MESS(0, 0);
    dds3SetProcessData(0, 0);
    return 0;
}

// 0x16573d0
void sdfChipFreeDelayed(void *aPtr) {
  ;
}
