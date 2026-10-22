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
  s8 v5;
  struct System_SByte_array *v8;
  struct System_SByte_array *sdfDispFrameId;
  struct System_SByte_array *v13;

  v5 = frameId;
  if (!mode)
  {
    else
    {
      if (!LODWORD(sdfDispFrameId->max_length))
        goto LABEL_15;
    }
    sdfDispFrameId->m_Items[0] = v5;
    v13 = sdfDispFrameId;
    v13->m_Items[1] = v5;
      goto LABEL_10;
    goto LABEL_19;
  }
  v8 = sdfDispFrameId;
  v8->m_Items[halfOffset] = v5;
  {
LABEL_10:
  }
LABEL_19:
  sdfDrawLockBuffId = -1;
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
    goto LABEL_11;
LABEL_6:
  if (sdfDispFrameId->m_Items[0] != frameId)
  {
      goto LABEL_19;
    goto LABEL_8;
  }
  v9 = sdfDispFrameId;
  v9->m_Items[0] = frameId ^ 1;
  {
LABEL_8:
  }
LABEL_19:
  v11 = sdfDispFrameId;
  if (v11->m_Items[1] != frameId)
  {
      goto LABEL_31;
    goto LABEL_22;
  }
  v15 = sdfDispFrameId;
  v16 = frameId ^ 1;
  v15->m_Items[1] = v16;
  {
LABEL_22:
  }
LABEL_31:
  sdfDrawLockBuffId = v3;
}

// 0x17ef500
void sdfDispThread(void *aDummy) {
  struct System_SByte_array *sdfDispFrameId;
  s64 sdfFrameEvenOdd;

  while (1)
  {
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

    goto LABEL_5;
  while (1)
  {
    do
    {
      reqMakeFrameBuff = 0;
      reqGsReset = 0;
    }
    while ((v2->_2.bitflags2 & 2) == 0);
LABEL_5:
  }
}

// 0x17ef190
void sdfGrCapture(void) {
  u64 *v1;
  Il2CppObject *v4;
  Il2CppObject *sdfGrCaptureBuff;
  s32 v6;
  Il2CppObject *v7;
  u64 *v8;
  u64 *v9;
  Il2CppObject *v12;
  s32 v13;
  u64 *v14;
  u64 *v15;
  s32 v16;
  s32 v17;

  v1 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v1);
  v4 = "";
  v6 = 0;
  v7 = v4;
  do
  {
    v17 = 0;
    v8 = sub_8D3950(s32, &v17);
    sdfGrCaptureBuff = Concat(sdfGrCaptureBuff, v8);
    v16 = 0;
    v9 = sub_8D3950(s32, &v16);
    v7 = Concat(v7, v9);
    ++v6;
  }
  while (v6);
  v12 = Substring(sdfGrCaptureBuff, 0);
  v13 = 0;
  do
  {
    v17 = 0;
    v14 = sub_8D3950(s32, &v17);
    v12 = Concat(v12, v14);
    v16 = 0;
    v15 = sub_8D3950(s32, &v16);
    v4 = Concat(v4, v15);
    ++v13;
  }
  while (v13);
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
  struct sdfGsMemSlice_t_array *frameHandle;
  struct sdfGsMemSlice_t_array *v5;

  else
  {
    frameHandle = aFrame->frameHandle;
    if (!LODWORD(frameHandle->max_length))
      goto LABEL_6;
  }
  frameHandle->m_Items[0] = 0;
  v5 = aFrame->frameHandle;
  v5->m_Items[1] = 0;
  aFrame->zbuffHandle = 0;
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
