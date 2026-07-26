#include "types.h"

typedef struct sdfGrFrameSet_t sdfGrFrameSet_t;
typedef struct sdfGrScreenDef_t sdfGrScreenDef_t;
typedef struct sdfGraph_aCallbackDelegate sdfGraph_aCallbackDelegate;
typedef struct sdfGraph_sdfGrCaptureCallbackDelegate sdfGraph_sdfGrCaptureCallbackDelegate;
typedef struct sdfThCB_t sdfThCB_t;

static s8 sdfFrameId;
static sdfThCB_t *sdfDispThCB;
static u16 sdfDispThStack[4096];
static s32 sdfDrawThId;
static u16 sdfDrawThStack[32768];
static sdfGrScreenDef_t *sdfGrScreenTable[4];
static s8 reqMakeFrameBuff;
static s8 reqGsReset;
static u8 sdfDispReady;
static u8 sdfFrameEvenOdd;
static u8 sdfDrawThStat;
static char *sdfGrCaptureBuff;
static sdfGraph_sdfGrCaptureCallbackDelegate *sdfGrCaptureCallback;
static s32 sdfDispLockSemaId;
static s8 sdfDispFrameId[2];
static s8 sdfDrawLockBuffId;
static s32 sdfDispThread_frame;

// 0x17ef320
void sdfDeliverDrawEnd(s32 mode, s32 frameId, s32 halfOffset) {
}

// 0x17ea630
void sdfDeliverDrawStart(s32 frameId, s32 buffId) {
  s8 v3;
  struct System_SByte_array *sdfDispFrameId;
  struct System_SByte_array *v9;
  struct System_SByte_array *v11;
  struct System_SByte_array *v15;
  s8 v16;

  v3 = buffId;
  if (!LODWORD(sdfDispFrameId->max_length))
  v9 = sdfDispFrameId;
  v9->m_Items[0] = frameId ^ 1;
  {
  }
  v11 = sdfDispFrameId;
  v15 = sdfDispFrameId;
  v16 = frameId ^ 1;
  v15->m_Items[1] = v16;
  {
  }
  sdfDrawLockBuffId = v3;
}

// 0x17ef500
void sdfDispThread(void *aDummy) {
  sdfGraph_c *v2;
  struct sdfGraph_StaticFields *static_fields;
  struct System_SByte_array *sdfDispFrameId;
  s64 sdfFrameEvenOdd;

  while (1)
  {
    static_fields = v2->static_fields;
    sdfDispFrameId = static_fields->sdfDispFrameId;
    sdfFrameEvenOdd = static_fields->sdfFrameEvenOdd;
    if ((sdfDispFrameId->m_Items[sdfFrameEvenOdd] & 0x80000000) == 0
    {
    }
  }
}

// 0x17ef110
s32 sdfDrawThIntHandler(s32 aCh, void *aArg, void *aStopPc) {
  return 0;
}

// 0x17ef490
void sdfDrawThread(void *aDummy) {
  sdfGraph_c *v2;

  while (1)
  {
    do
    {
      reqMakeFrameBuff = 0;
      reqGsReset = 0;
    }
    while ((v2->_2.bitflags2 & 2) == 0);
  }
}

// 0x17ef190
void sdfGrCapture(void) {
}

// 0x17eefc0
void sdfGrFreeFrameSet(sdfGrFrameSet_t *aFrame) {
  struct sdfGsMemSlice_t_array *frameHandle;
  struct sdfGsMemSlice_t_array *v4;

  frameHandle = aFrame->frameHandle;
  frameHandle->m_Items[0] = 0;
  v4 = aFrame->frameHandle;
  v4->m_Items[1] = 0;
  aFrame->zbuffHandle = 0;
}

// 0x17ef100
void sdfGrGsReset(void) {
  ;
}

// 0x17ef5b0
void sdfGrInit(s32 aPacketBuffSize) {
  struct System_SByte_array *sdfDispFrameId;

  reqGsReset = 1;
  sdfDispFrameId->m_Items[1] = -1;
  sdfDispFrameId->m_Items[0] = -1;
  sdfDrawLockBuffId = -1;
}

// 0x17ef680
void sdfGrInitNewFrame(void) {
  ;
}

// 0x17ef030
void sdfGrMakeFrameSet(sdfGrFrameSet_t *aFrame) {
}

// 0x17ef120
void sdfGrReqCapture(char *aBuff, sdfGraph_aCallbackDelegate *aCallback) {
  sdfGrCaptureBuff = aBuff;
}

// 0x17ef0f0
void sdfGrSetDisp(s32 aEvenOdd) {
  ;
}

// 0x17eee60
void sdfGrSetFrameSetMode(sdfGrFrameSet_t *aFrame, s32 aMode, s32 aReqHandleClear) {
  struct sdfGsMemSlice_t_array *frameHandle;
  struct sdfGsMemSlice_t_array *v11;

  if (aReqHandleClear)
  {
    frameHandle = aFrame->frameHandle;
    frameHandle->m_Items[0] = 0;
    v11 = aFrame->frameHandle;
    v11->m_Items[1] = 0;
    aFrame->zbuffHandle = 0;
  }
}

// 0x17eef50
void sdfGrSetScreen(s32 aMode) {
  reqMakeFrameBuff = 1;
}
