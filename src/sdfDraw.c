#include "types.h"

typedef struct sdfDrawReqRec_t sdfDrawReqRec_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfGrClearPacket_t sdfGrClearPacket_t;
typedef struct sdfGrDrawDefParmPacket_t sdfGrDrawDefParmPacket_t;
typedef struct sdfGrDrawEnv_t sdfGrDrawEnv_t;
typedef struct sdfGrDrawFramePacket_t sdfGrDrawFramePacket_t;
typedef struct sdfGrDrawFrame_t sdfGrDrawFrame_t;
typedef struct sdfGrFramePacket_t sdfGrFramePacket_t;
typedef struct sdfGrFrameSet_t sdfGrFrameSet_t;
typedef struct sdfGrOt_t sdfGrOt_t;
typedef struct sdfGrPacketHeader_t sdfGrPacketHeader_t;
typedef struct sdfGrRefGifPacketHeader_t sdfGrRefGifPacketHeader_t;
typedef struct sdfGrRefPacketHeader_t sdfGrRefPacketHeader_t;
typedef struct sdfGrStdDrawEnv_t sdfGrStdDrawEnv_t;
typedef struct sdfPreDrawChain_t sdfPreDrawChain_t;
typedef struct sdfPreDrawHook_t sdfPreDrawHook_t;
typedef struct sdfPreDrawTag_t sdfPreDrawTag_t;

static u16 sdfDrawTimeCount;
static u8 sdfDrawEndFlag;
static u8 sdfDrawFrameId;
static u8 sdfDrawHalfOffsetId;
static u8 sdfReqDrawDelayCount;
static u16 sdfReqDrawDelaySleepCount;
static u8 sdfDrawCancel;
static u8 sdfDrawing;
static sdfDrawReqRec_t *sdfDrawReqQueue[3];
static s32 sdfDrawReqQueueIndex;
static u8 sdfDrawImageTrans;
static void *sdfDrawPacketLast;
static s32 sdfDrawFrameCount;

u8 SDF_DMA_ID(u8 irq, u8 id, u8 pce);
void sdfDelayedResrcProc(void);
void sdfDeliverDrawStart(s32 frameId, s32 buffId);
void sdfDrawTagLink(sdfDrawTag_t *aTag, void *aPacket);
void sdfDrawTagLinkRef(sdfDrawTag_t *aTag, void *aPacket);
s32 sdfGetRunTimeCount(s32 aBaseTime);
s32 sdfGetRunTimeCountBase(void);
void sdfGrInitExPacket(sdfDrawTag_t *p);
void sdfGrJoinDrawTag(sdfDrawTag_t *aFore, sdfDrawTag_t *aBack);

// 0x17ea830
void sdfDrawSync(void) {
  while (1)
  {
      ;
  }
}

// 0x17e7eb0
void sdfDrawTagInit(sdfDrawTag_t *aTag) {
}

// 0x17c9770
void sdfDrawTagLink(sdfDrawTag_t *aTag, void *aPacket) {
    SDF_DMA_ID(0, 0, 0);
}

// 0x17e8020
void sdfDrawTagLink2(sdfDrawTag_t *aTag, void *aHeadPacket, void *aTailPacket) {
}

// 0x17e8640
void sdfDrawTagLinkCall(sdfDrawTag_t *aTag, void *aPacket) {
}

// 0x17e9540
void sdfDrawTagLinkOt(sdfGrOt_t *ot, sdfDrawTag_t *tag) {
  sdfGrOt_t_regFuncDelegate_o *regFunc;

  if (ot)
  {
    regFunc = ot->regFunc;
    if (regFunc)
      sdfGrOt_t_regFuncDelegate__Invoke(regFunc, ot, tag);
  }
}

// 0x17e9560
void sdfDrawTagLinkOtHead(sdfGrOt_t *ot, sdfDrawTag_t *tag) {
  sdfGrOt_t_callbackFuncDelegate_o *callbackFunc;

  if (ot)
  {
    callbackFunc = ot->callbackFunc;
    if (callbackFunc)
      sdfGrOt_t_callbackFuncDelegate__Invoke(callbackFunc, ot, 1, tag);
  }
}

// 0x17e81c0
void sdfDrawTagLinkRef(sdfDrawTag_t *aTag, void *aPacket) {
}

// 0x17e8480
void sdfDrawTagLinkRefGif(sdfDrawTag_t *aTag, sdfGrRefGifPacketHeader_t *aPacket) {
}

// 0x17e8ff0
void *sdfGrAddExPacket(sdfGrPacketHeader_t *p, void *ex) {
  u64 *v3;

  v3 = Allocate(sdfGrRefPacketHeader_t);
  sdfGrRefPacketHeader_t___ctor(v3);
  return v3[3];
}

// 0x17ea400
void sdfGrDrawFrame(void) {
    sdfDelayedResrcProc();
    sdfDeliverDrawStart(0, 0);
}

// 0x17e9f40
void sdfGrFramePacketPredraw(sdfPreDrawHook_t *aPre, s32 aEvenOdd) {
}

// 0x17ea360
void sdfGrInitDraw(void) {
  struct sdfDrawReqRec_t_array *sdfDrawReqQueue;

  sdfReqDrawDelayCount = 0;
  sdfDrawReqQueueIndex = 0;
  sdfDrawReqQueue->m_Items[0]->drawTag = 0;
}

// 0x17e9050
void sdfGrInitExPacket(sdfDrawTag_t *p) {
}

// 0x17e89a0
void sdfGrJoinDrawTag(sdfDrawTag_t *aFore, sdfDrawTag_t *aBack) {
}

// 0x17e9e40
void sdfGrLinkDispFrameTex(sdfDrawTag_t *aTag, sdfGrStdDrawEnv_t *aEnv, sdfGrRefPacketHeader_t *aPkt) {
  sdfDrawTagLinkRef(aTag, aPkt, aPkt);
}

// 0x17e9ec0
void sdfGrLinkDrawFrameTex(sdfDrawTag_t *aTag, sdfGrStdDrawEnv_t *aEnv, sdfGrRefPacketHeader_t *aPkt) {
  sdfDrawTagLinkRef(aTag, aPkt, aPkt);
}

// 0x17e9cc0
void sdfGrLinkStdDrawEnv(sdfDrawTag_t *aTag, sdfPreDrawTag_t *aPreDrawTag, sdfGrStdDrawEnv_t *aEnv) {
  struct sdfPreDrawHook_t_o *worker;
  struct sdfPreDrawHook_t_o *tail;
  struct sdfPreDrawHook_t_o **p_next;

  worker = aEnv->worker;
  tail = aPreDrawTag->tail;
  if (tail)
    p_next = &tail->next;
  else
    p_next = &aPreDrawTag->head;
  *p_next = worker;
  aPreDrawTag->tail = worker;
  worker->next = 0;
  sdfDrawTagLink(aTag, aEnv->header, aEnv);
}

// 0x17e8f90
void *sdfGrNewExPacket(void *ex) {
  u64 *v2;

  v2 = Allocate(sdfGrRefPacketHeader_t);
  sdfGrRefPacketHeader_t___ctor(v2);
  return v2;
}

// 0x17e9380
sdfDrawTag_t *sdfGrOtClose(sdfGrOt_t *aOt) {
    sdfGrJoinDrawTag(0, 0);
    sdfGrInitExPacket(0);
    return 0;
}

// 0x17e8900
void sdfGrOtFuncLinkToHead(sdfGrOt_t *aOt, sdfDrawTag_t *aTag) {
  sdfDrawTag_t_o *tagHead;

  if (aTag->tail)
  {
    tagHead = aOt->tagHead;
    if (tagHead)
    {
      sdfGrJoinDrawTag(aTag, tagHead);
    }
    else
    {
      aOt->tagTail = aTag;
    }
    aTag->next = tagHead;
    aOt->tagHead = aTag;
  }
}

// 0x17e8e60
void sdfGrOtInit(sdfGrOt_t *aOt, s32 aNumOt) {
}

// 0x17e8cd0
void sdfGrOtNormalCallback(sdfGrOt_t *aOt, s32 aFunc, void *aData) {
    sdfGrJoinDrawTag(0, 0);
}

// 0x17e8c30
void sdfGrOtNormalReg(sdfGrOt_t *aOt, sdfDrawTag_t *aTag) {
  struct sdfDrawTag_t_o *tagTail;

  if (aTag->head)
  {
    tagTail = aOt->tagTail;
    if (tagTail)
    {
      tagTail->next = aTag;
      sdfGrJoinDrawTag(tagTail, aTag);
    }
    else
    {
      aOt->tagHead = aTag;
    }
    aOt->tagTail = aTag;
  }
}

// 0x17ea120
void sdfGrReqDraw(sdfDrawTag_t *aTag, sdfPreDrawChain_t *aPreDraw) {
  s32 RunTimeCountBase;
  u16 RunTimeCount;
  struct sdfDraw_StaticFields *static_fields;
  struct sdfDrawReqRec_t_array *sdfDrawReqQueue;
  s64 sdfDrawReqQueueIndex;
  s64 v14;
  sdfDrawReqRec_t_o *v16;
  struct sdfPreDrawHook_t_o *head;

  RunTimeCountBase = sdfGetRunTimeCountBase();
  do
  {
    {
      if (!sdfReqDrawDelayCount)
    }
  }
  while (sdfReqDrawDelayCount);
  RunTimeCount = sdfGetRunTimeCount(RunTimeCountBase);
  sdfReqDrawDelaySleepCount = RunTimeCount;
  static_fields = sdfDraw->static_fields;
  sdfDrawReqQueue = static_fields->sdfDrawReqQueue;
  sdfDrawReqQueueIndex = static_fields->sdfDrawReqQueueIndex;
  v14 = sdfDrawReqQueueIndex + 1;
  v16 = sdfDrawReqQueue->m_Items[v14];
  v16->drawTag = 0;
  v16->drawCount = 0;
  v16->preDraw = 0;
  if (aTag)
  {
    if (aTag->tail)
    {
      v16->drawTag = aTag;
      if (aPreDraw)
      {
        head = aPreDraw->tagHead->head;
        v16->preDraw = head;
        if (head)
          aPreDraw->tagTail->tail->next = 0;
      }
    }
  }
  sdfDrawReqQueueIndex = v14;
  sdfDrawImageTrans = 1;
  ++sdfDrawFrameCount;
}

// 0x17ea2f0
void sdfGrReqDrawDelay(s32 count) {
  s32 v4;

  v4 = count & ~(count >> 31);
  sdfReqDrawDelayCount = v4;
}

// 0x17e95f0
void sdfGrSetClearPacket(sdfGrClearPacket_t *aClear, s32 aW, s32 aH, s32 aPixelFormat, s32 aZBuffFormat) {
  aClear->test->reg = 71;
  aClear->prim->reg = 0;
  aClear->rgbaq->reg = 1;
  aClear->xyzA->reg = 5;
  aClear->xyzB->reg = 5;
}

// 0x17e9630
void sdfGrSetDrawDefParmPacket(sdfGrDrawDefParmPacket_t *aDef) {
  aDef->prmodecont->data = 1;
  aDef->prmodecont->reg = 26;
  aDef->colclamp->data = 1;
  aDef->colclamp->reg = 70;
  aDef->dthe->data = 0;
  aDef->dthe->reg = 69;
  aDef->texa->reg = 59;
}

// 0x17e9740
void sdfGrSetDrawEnv(sdfGrDrawEnv_t *aEnv, sdfGrFrameSet_t *aFrameSet, s32 aEvenOdd) {
  struct sdfGrDrawFramePacket_t_o *frame1;
  struct sdfGrDrawFramePacket_t_o *frame2;
  struct sdfGrClearPacket_t_o *clear;
  struct sdfGrDrawDefParmPacket_t_o *defParm;

  frame1 = aEnv->frame1;
  frame1->frame->reg = 76;
  frame1->zbuf->reg = 78;
  frame1->xyoffset->reg = 24;
  frame1->scissor->reg = 64;
  frame2 = aEnv->frame2;
  frame2->frame->reg = 77;
  frame2->zbuf->reg = 79;
  frame2->xyoffset->reg = 25;
  frame2->scissor->reg = 65;
  clear = aEnv->clear;
  clear->test->reg = 71;
  clear->prim->reg = 0;
  clear->rgbaq->reg = 1;
  clear->xyzA->reg = 5;
  clear->xyzB->reg = 5;
  aEnv->test1->data = 0;
  aEnv->test1->reg = 71;
  aEnv->alpha1->reg = 66;
  aEnv->test2->data = 0;
  aEnv->test2->reg = 72;
  aEnv->alpha2->reg = 67;
  defParm = aEnv->defParm;
  defParm->prmodecont->data = 1;
  defParm->prmodecont->reg = 26;
  defParm->colclamp->data = 1;
  defParm->colclamp->reg = 70;
  defParm->dthe->data = 0;
  defParm->dthe->reg = 69;
  defParm->texa->reg = 59;
}

// 0x17e9680
void sdfGrSetDrawFrame(sdfGrDrawFrame_t *aFrame, s32 aFrameAddr, s32 aW, s32 aH, s32 aPixelFormat, s32 aZBuffAddr, s32 aZBuffFormat, s32 aContext) {
  struct sdfGrDrawFramePacket_t_o *packet;
  s64 v12;
  s64 v13;
  s64 v14;
  s64 v15;

  packet = aFrame->packet;
  v12 = 76;
  if (aContext)
    v12 = 77;
  packet->frame->reg = v12;
  v13 = 78;
  if (aContext)
    v13 = 79;
  packet->zbuf->reg = v13;
  v14 = 24;
  if (aContext)
    v14 = 25;
  packet->xyoffset->reg = v14;
  v15 = 64;
  if (aContext)
    v15 = 65;
  packet->scissor->reg = v15;
}

// 0x17e95a0
void sdfGrSetDrawFramePacket(sdfGrDrawFramePacket_t *aFrame, s32 aFrameAddr, s32 aW, s32 aH, s32 aPixelFormat, s32 aZBuffAddr, s32 aZBuffFormat, s32 aHalfOffset, s32 aContext) {
  u64 v10;
  u64 v11;
  u64 v12;
  u64 v13;

  v10 = 76;
  v11 = 78;
  v12 = 24;
  v13 = 64;
  if (aContext)
    v10 = 77;
  aFrame->frame->reg = v10;
  if (aContext)
    v11 = 79;
  aFrame->zbuf->reg = v11;
  if (aContext)
    v12 = 25;
  aFrame->xyoffset->reg = v12;
  if (aContext)
    v13 = 65;
  aFrame->scissor->reg = v13;
}

// 0x17e9d60
void sdfGrSetFrameMaskRGB(sdfGrStdDrawEnv_t *aEnv, sdfGrRefGifPacketHeader_t *aHdr, s32 aContext) {

}

// 0x17e9dd0
void sdfGrSetFrameMaskReset(sdfGrStdDrawEnv_t *aEnv, sdfGrRefGifPacketHeader_t *aHdr, s32 aContext) {

}

// 0x17ea050
void sdfGrSetFramePacket(sdfGrFramePacket_t *aFrame, sdfGrFrameSet_t *aFrameSet, u32 aFrameMask, u32 aZBuffMask, s32 aContext) {
  struct sdfPreDrawHook_t_o *worker;
  u64 *v12;

  worker = aFrame->worker;
  v12 = Allocate(sdfPreDrawHook_t_predrawFuncDelegate);
  sdfPreDrawHook_t_predrawFuncDelegate___ctor(v12, 0, Method_sdfDraw_sdfGrFramePacketPredraw__);
  worker->predrawFunc = v12;
  aFrame->frameSet = aFrameSet;
  aFrame->frameMask = aFrameMask;
  aFrame->zbuffMask = aZBuffMask;
  aFrame->context = aContext;
}

// 0x17e9590
void sdfGrSetRefGifPacket(sdfGrRefGifPacketHeader_t *aPacket, void *aRegs, s32 aNumRegs) {
  ;
}

// 0x17c9ad0
void sdfGrSetRegsPacketHeader(sdfGrPacketHeader_t *aHeader, s32 aNumRegs) {
  ;
}

// 0x17e9b60
void sdfGrSetStdDrawEnv(sdfGrStdDrawEnv_t *aEnv, sdfGrFrameSet_t *aFrameSet) {
  struct sdfPreDrawHook_t_o *worker;
  u64 *v5;
  struct sdfGrClearPacket_t_o *clear;
  struct sdfGrDrawDefParmPacket_t_o *defParm;

  worker = aEnv->worker;
  v5 = Allocate(sdfPreDrawHook_t_predrawFuncDelegate);
  sdfPreDrawHook_t_predrawFuncDelegate___ctor(v5, 0, Method_sdfDraw_sdfGrStdDrawEnvPredraw__);
  worker->predrawFunc = v5;
  clear = aEnv->clear;
  clear->test->reg = 71;
  clear->prim->reg = 0;
  clear->rgbaq->reg = 1;
  clear->xyzA->reg = 5;
  clear->xyzB->reg = 5;
  aEnv->test1->data = 0;
  aEnv->test1->reg = 71;
  aEnv->alpha1->reg = 66;
  aEnv->test2->data = 0;
  aEnv->test2->reg = 72;
  aEnv->alpha2->reg = 67;
  defParm = aEnv->defParm;
  defParm->prmodecont->data = 1;
  defParm->prmodecont->reg = 26;
  defParm->colclamp->data = 1;
  defParm->colclamp->reg = 70;
  defParm->dthe->data = 0;
  defParm->dthe->reg = 69;
  defParm->texa->reg = 59;
}

// 0x17e9900
void sdfGrStdDrawEnvPredraw(sdfPreDrawHook_t *aPre, s32 aEvenOdd) {
}

// 0x17e9500
void sdfPreDrawChainInit(sdfPreDrawChain_t *aChain) {
  aChain->tagHead = 0;
  aChain->tagTail = 0;
}

// 0x17e9510
void sdfPreDrawChainLink(sdfPreDrawChain_t *aChain, sdfPreDrawTag_t *aTag) {
  struct sdfPreDrawTag_t_o *tagTail;

  tagTail = aChain->tagTail;
  if (tagTail)
    tagTail->tail->next = aTag->tail;
  else
    aChain->tagHead = aTag;
  aChain->tagTail = aTag;
}

// 0x17e94c0
void sdfPreDrawTagInit(sdfPreDrawTag_t *aTag) {
  aTag->pad = 0;
  aTag->head = 0;
  aTag->tail = 0;
  aTag->next = 0;
}

// 0x17e94d0
void sdfPreDrawTagLink(sdfPreDrawTag_t *aTag, sdfPreDrawHook_t *aHook) {
  struct sdfPreDrawHook_t_o *tail;
  struct sdfPreDrawHook_t_o **p_next;

  tail = aTag->tail;
  if (tail)
    p_next = &tail->next;
  else
    p_next = &aTag->head;
  *p_next = aHook;
  aTag->tail = aHook;
  aHook->next = 0;
}
