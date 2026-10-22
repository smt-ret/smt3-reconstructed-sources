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
  struct System_Object_array *texPacket;
  s64 *v4;
  s64 *v5;
  struct System_Object_array *v7;
  s64 *v8;
  s64 *v9;
  s32 v13;
  s32 v14;
  s32 v15;
  s32 v16;

  aTag->next = 0;
  aTag->head = 0;
  aTag->tail = 0;
  aTag->z = 65535.0;
  v16 = 0;
  aTag->lightPacket = sub_8D3950(s32, &v16);
  v15 = 0;
  aTag->fogPacket = sub_8D3950(s32, &v15);
  texPacket = aTag->texPacket;
  v14 = 0;
  v4 = sub_8D3950(s32, &v14);
  v5 = v4;
  texPacket->m_Items[0] = v5;
  v7 = aTag->texPacket;
  v13 = 0;
  v8 = sub_8D3950(s32, &v13);
  v9 = v8;
  v7->m_Items[1] = v9;
}

// 0x17c9770
void sdfDrawTagLink(sdfDrawTag_t *aTag, void *aPacket) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppObject *v7;
  char *v8;
  s64 *v9;
  struct sdfGrPacketHeader_t_o *tail;
  struct sdfDmaTag_t_o *dmatag;
  Il2CppClass *v12;
  s64 v13;
  bool v14;
  Il2CppObject *v15;
  char *v16;
  s64 *v17;
  Il2CppClass *v18;
  s64 v19;
  char *v20;
  s64 *v21;
  u64 v22[2];
  char *v23;

  if (aPacket)
  {
    klass = aPacket->klass;
    if (aPacket->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || (v7 = aPacket, klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfGrPacketHeader_t))
    {
      sub_8FC2C0(klass->_1.element_class, sdfGrPacketHeader_t, v22);
      if ((v22[0] & 1) != 0)
        v8 = v23;
      else
        v8 = v22 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  else
  {
    v7 = 0;
  }
  tail = aTag->tail;
  if (tail)
  {
    dmatag = tail->dmatag;
    dmatag->id = SDF_DMA_ID(0, 2u, 0);
    tail->dmatag->addr = v7;
    if (!aPacket)
      goto LABEL_29;
    goto LABEL_23;
  }
  if (aPacket)
  {
    v12 = aPacket->klass;
    if (aPacket->klass->_2.typeHierarchyDepth < v13
      || (v14 = v12->_2.typeHierarchy[v13 - 1] == sdfGrPacketHeader_t, v15 = aPacket, !v14))
    {
      sub_8FC2C0(v12->_1.element_class, sdfGrPacketHeader_t, v22);
      if ((v22[0] & 1) != 0)
        v16 = v23;
      else
        v16 = v22 + 1;
      v17 = sub_8C4940(v16);
    }
  }
  else
  {
    v15 = 0;
  }
  aTag->head = v15;
  if (aPacket)
  {
LABEL_23:
    v18 = aPacket->klass;
    if (aPacket->klass->_2.typeHierarchyDepth < v19
      || v18->_2.typeHierarchy[v19 - 1] != sdfGrPacketHeader_t)
    {
      sub_8FC2C0(v18->_1.element_class, sdfGrPacketHeader_t, v22);
      if ((v22[0] & 1) != 0)
        v20 = v23;
      else
        v20 = v22 + 1;
      v21 = sub_8C4940(v20);
    }
  }
LABEL_29:
  aTag->tail = aPacket;
}

// 0x17e8020
void sdfDrawTagLink2(sdfDrawTag_t *aTag, void *aHeadPacket, void *aTailPacket) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  Il2CppClass *v11;
  s64 v12;
  char *v13;
  s64 *v14;
  u64 v15[2];
  char *v16;

  if (aTag->tail)
  {
    if (!aTailPacket)
      goto LABEL_20;
    goto LABEL_14;
  }
  if (aHeadPacket)
  {
    klass = aHeadPacket->klass;
    if (aHeadPacket->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfGrPacketHeader_t)
    {
      sub_8FC2C0(klass->_1.element_class, sdfGrPacketHeader_t, v15);
      if ((v15[0] & 1) != 0)
        v9 = v16;
      else
        v9 = v15 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  aTag->head = aHeadPacket;
  if (aTailPacket)
  {
LABEL_14:
    v11 = aTailPacket->klass;
    if (aTailPacket->klass->_2.typeHierarchyDepth < v12
      || v11->_2.typeHierarchy[v12 - 1] != sdfGrPacketHeader_t)
    {
      sub_8FC2C0(v11->_1.element_class, sdfGrPacketHeader_t, v15);
      if ((v15[0] & 1) != 0)
        v13 = v16;
      else
        v13 = v15 + 1;
      v14 = sub_8C4940(v13);
    }
  }
LABEL_20:
  aTag->tail = aTailPacket;
}

// 0x17e8640
void sdfDrawTagLinkCall(sdfDrawTag_t *aTag, void *aPacket) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppObject *v7;
  char *v8;
  s64 *v9;
  Il2CppClass *v10;
  s64 v11;
  struct sdfGrPacketHeader_t_o *monitor;
  Il2CppClass *v13;
  s64 v14;
  char *v15;
  s64 *v16;
  sdfGrPacketHeader_t_c *v17;
  s64 v18;
  char *v19;
  s64 *v20;
  char *v21;
  s64 *v22;
  u64 v23[2];
  char *v24;

  if (aPacket)
  {
    klass = aPacket->klass;
    if (aPacket->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || (v7 = aPacket, klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfGrCallPacketHeader_t))
    {
      sub_8FC2C0(klass->_1.element_class, sdfGrCallPacketHeader_t, v23);
      if ((v23[0] & 1) != 0)
        v8 = v24;
      else
        v8 = v23 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  else
  {
    v7 = 0;
  }
  if (aTag->tail)
  {
    v10 = aPacket->klass;
    if (aPacket->klass->_2.typeHierarchyDepth < v11
      || v10->_2.typeHierarchy[v11 - 1] != sdfGrCallPacketHeader_t)
    {
      sub_8FC2C0(v10->_1.element_class, sdfGrCallPacketHeader_t, v23);
      if ((v23[0] & 1) != 0)
        v21 = v24;
      else
        v21 = v23 + 1;
      v22 = sub_8C4940(v21);
    }
    monitor = aPacket[1].monitor;
    if (!monitor)
      goto LABEL_30;
LABEL_24:
    v17 = monitor->klass;
    if (monitor->klass->_2.typeHierarchyDepth < v18
      || v17->_2.typeHierarchy[v18 - 1] != sdfGrPacketHeader_t)
    {
      sub_8FC2C0(v17->_1.element_class, sdfGrPacketHeader_t, v23);
      if ((v23[0] & 1) != 0)
        v19 = v24;
      else
        v19 = v23 + 1;
      v20 = sub_8C4940(v19);
    }
    goto LABEL_30;
  }
  if (aPacket)
  {
    v13 = aPacket->klass;
    if (aPacket->klass->_2.typeHierarchyDepth < v14
      || v13->_2.typeHierarchy[v14 - 1] != sdfGrPacketHeader_t)
    {
      sub_8FC2C0(v13->_1.element_class, sdfGrPacketHeader_t, v23);
      if ((v23[0] & 1) != 0)
        v15 = v24;
      else
        v15 = v23 + 1;
      v16 = sub_8C4940(v15);
    }
  }
  aTag->head = aPacket;
  monitor = *(&xmmword_10 + v7 + 8);
  if (monitor)
    goto LABEL_24;
LABEL_30:
  aTag->tail = monitor;
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
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppObject *v7;
  char *v8;
  s64 *v9;
  Il2CppClass *v10;
  s64 v11;
  struct sdfGrPacketHeader_t_o *monitor;
  Il2CppClass *v13;
  s64 v14;
  char *v15;
  s64 *v16;
  sdfGrPacketHeader_t_c *v17;
  s64 v18;
  char *v19;
  s64 *v20;
  char *v21;
  s64 *v22;
  u64 v23[2];
  char *v24;

  if (aPacket)
  {
    klass = aPacket->klass;
    if (aPacket->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || (v7 = aPacket, klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfGrRefPacketHeader_t))
    {
      sub_8FC2C0(klass->_1.element_class, sdfGrRefPacketHeader_t, v23);
      if ((v23[0] & 1) != 0)
        v8 = v24;
      else
        v8 = v23 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  else
  {
    v7 = 0;
  }
  if (aTag->tail)
  {
    v10 = aPacket->klass;
    if (aPacket->klass->_2.typeHierarchyDepth < v11
      || v10->_2.typeHierarchy[v11 - 1] != sdfGrRefPacketHeader_t)
    {
      sub_8FC2C0(v10->_1.element_class, sdfGrRefPacketHeader_t, v23);
      if ((v23[0] & 1) != 0)
        v21 = v24;
      else
        v21 = v23 + 1;
      v22 = sub_8C4940(v21);
    }
    monitor = aPacket[1].monitor;
    if (!monitor)
      goto LABEL_30;
LABEL_24:
    v17 = monitor->klass;
    if (monitor->klass->_2.typeHierarchyDepth < v18
      || v17->_2.typeHierarchy[v18 - 1] != sdfGrPacketHeader_t)
    {
      sub_8FC2C0(v17->_1.element_class, sdfGrPacketHeader_t, v23);
      if ((v23[0] & 1) != 0)
        v19 = v24;
      else
        v19 = v23 + 1;
      v20 = sub_8C4940(v19);
    }
    goto LABEL_30;
  }
  if (aPacket)
  {
    v13 = aPacket->klass;
    if (aPacket->klass->_2.typeHierarchyDepth < v14
      || v13->_2.typeHierarchy[v14 - 1] != sdfGrPacketHeader_t)
    {
      sub_8FC2C0(v13->_1.element_class, sdfGrPacketHeader_t, v23);
      if ((v23[0] & 1) != 0)
        v15 = v24;
      else
        v15 = v23 + 1;
      v16 = sub_8C4940(v15);
    }
  }
  aTag->head = aPacket;
  monitor = v7[1].monitor;
  if (monitor)
    goto LABEL_24;
LABEL_30:
  aTag->tail = monitor;
}

// 0x17e8480
void sdfDrawTagLinkRefGif(sdfDrawTag_t *aTag, sdfGrRefGifPacketHeader_t *aPacket) {
  struct sdfGrPacketHeader_t_o *linktag;
  sdfGrRefGifPacketHeader_t_c *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  sdfGrPacketHeader_t_c *v10;
  s64 v11;
  char *v12;
  s64 *v13;
  u64 v14[2];
  char *v15;

  if (aTag->tail)
  {
    linktag = aPacket->linktag;
    if (!linktag)
      goto LABEL_20;
    goto LABEL_14;
  }
  if (!aPacket)
  {
    aTag->head = 0;
    linktag = &xmmword_0;
    if (!&xmmword_0)
      goto LABEL_20;
    goto LABEL_14;
  }
  klass = aPacket->klass;
  if (aPacket->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfGrPacketHeader_t)
  {
    sub_8FC2C0(klass->_1.element_class, sdfGrPacketHeader_t, v14);
    if ((v14[0] & 1) != 0)
      v8 = v15;
    else
      v8 = v14 + 1;
    v9 = sub_8C4940(v8);
  }
  aTag->head = aPacket;
  linktag = aPacket->linktag;
  if (linktag)
  {
LABEL_14:
    v10 = linktag->klass;
    if (linktag->klass->_2.typeHierarchyDepth < v11
      || v10->_2.typeHierarchy[v11 - 1] != sdfGrPacketHeader_t)
    {
      sub_8FC2C0(v10->_1.element_class, sdfGrPacketHeader_t, v14);
      if ((v14[0] & 1) != 0)
        v12 = v15;
      else
        v12 = v14 + 1;
      v13 = sub_8C4940(v12);
    }
  }
LABEL_20:
  aTag->tail = linktag;
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
  struct sdfDrawReqRec_t_array *sdfDrawReqQueue;
  s64 sdfDrawReqQueueIndex;
  sdfDrawReqRec_t_o *v8;
  struct sdfDrawTag_t_o *drawTag;
  u8 v12;
  s32 sdfDrawFrameId;
  s32 buffId;
  sdfPreDrawHook_t_o *preDraw;
  Il2CppObject *head;
  s32 v22;

  v8 = sdfDrawReqQueue->m_Items[sdfDrawReqQueueIndex];
  drawTag = v8->drawTag;
  if (!drawTag)
    goto LABEL_11;
  if (v8->drawCount)
  {
    if (v8->drawCount == 2)
    {
LABEL_11:
      sdfDrawEndFlag = 1;
      sdfDelayedResrcProc();
      return;
    }
    v12 = v8->halfOffsetId ^ 1;
    v8->halfOffsetId = v12;
    sdfDrawHalfOffsetId = v12;
  }
  v8->drawFrameId = sdfDrawFrameId;
  buffId = v8->buffId;
  sdfDeliverDrawStart(sdfDrawFrameId, buffId);
  if (sdfDrawImageTrans)
  {
    sdfDrawImageTrans = 0;
  }
  preDraw = v8->preDraw;
  if (preDraw)
  {
    do
    {
      sdfPreDrawHook_t_predrawFuncDelegate__Invoke(preDraw->predrawFunc, preDraw, v8->drawFrameId);
      preDraw = preDraw->next;
    }
    while (preDraw);
  }
  head = drawTag->head;
  sdfDrawPacketLast = head;
  v22 = 0;
  sub_8D3950(s32, &v22);
}

// 0x17e9f40
void sdfGrFramePacketPredraw(sdfPreDrawHook_t *aPre, s32 aEvenOdd) {
  sdfPreDrawHook_t_c *klass;
  s64 typeHierarchyDepth;
  s64 v6;
  bool v7;
  void *v8;
  char *v9;
  s64 *v10;
  u64 v11[3];

  klass = aPre->klass;
  if (aPre->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfGrFramePacket_t)
  {
    sub_8FC2C0(klass->_1.element_class, sdfGrFramePacket_t, v11);
    if ((v11[0] & 1) != 0)
      v9 = v11[2];
    else
      v9 = v11 + 1;
    v10 = sub_8C4940(v9);
  }
  v6 = 76;
  v7 = LODWORD(aPre[1].predrawFunc) == 0;
  v8 = &loc_4C + 2;
  if (LODWORD(aPre[1].predrawFunc))
    v6 = 77;
  *(*&aPre->option0 + 32LL) = v6;
  if (!v7)
    v8 = &loc_4C + 3;
  aPre[1].klass->_1.byval_arg.data = v8;
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
  u64 *v3;
  u64 v4;
  u32 v5;
  s64 typeHierarchyDepth;
  s64 v7;
  char *v8;
  s64 *v9;
  u64 *v10;
  u64 v11;
  u32 v12;
  s64 v13;
  s64 v14;
  char *v15;
  s64 *v16;
  s64 v17;
  char *v18;
  s64 *v19;
  s64 v20;
  char *v21;
  s64 *v22;
  u64 v23[2];
  char *v24;

  if (p->fogPacket)
  {
    v3 = Allocate(sdfGrRefPacketHeader_t);
    sdfGrRefPacketHeader_t___ctor(v3);
    if (v3)
    {
      v4 = *v3;
      v5 = *(*v3 + 288);
      if (v5 < typeHierarchyDepth
        || (v7 = *(v4 + 200), *(v7 + 8 * typeHierarchyDepth - 8) != sdfGrRefPacketHeader_t))
      {
        sub_8FC2C0(*(v4 + 64), sdfGrRefPacketHeader_t, v23);
        if ((v23[0] & 1) != 0)
          v8 = v24;
        else
          v8 = v23 + 1;
        v9 = sub_8C4940(v8);
      }
      if (v5 < v17 || *(v7 + 8 * v17 - 8) != sdfGrPacketHeader_t)
      {
        sub_8FC2C0(*(v4 + 64), sdfGrPacketHeader_t, v23);
        if ((v23[0] & 1) != 0)
          v18 = v24;
        else
          v18 = v23 + 1;
        v19 = sub_8C4940(v18);
      }
    }
    p->head = v3;
  }
  if (p->lightPacket)
  {
    v10 = Allocate(sdfGrRefPacketHeader_t);
    sdfGrRefPacketHeader_t___ctor(v10);
    if (v10)
    {
      v11 = *v10;
      v12 = *(*v10 + 288);
      if (v12 < v13 || (v14 = *(v11 + 200), *(v14 + 8 * v13 - 8) != sdfGrRefPacketHeader_t))
      {
        sub_8FC2C0(*(v11 + 64), sdfGrRefPacketHeader_t, v23);
        if ((v23[0] & 1) != 0)
          v15 = v24;
        else
          v15 = v23 + 1;
        v16 = sub_8C4940(v15);
      }
      if (v12 < v20 || *(v14 + 8 * v20 - 8) != sdfGrPacketHeader_t)
      {
        sub_8FC2C0(*(v11 + 64), sdfGrPacketHeader_t, v23);
        if ((v23[0] & 1) != 0)
          v21 = v24;
        else
          v21 = v23 + 1;
        v22 = sub_8C4940(v21);
      }
    }
    p->head = v10;
  }
}

// 0x17e89a0
void sdfGrJoinDrawTag(sdfDrawTag_t *aFore, sdfDrawTag_t *aBack) {
  sdfDrawTag_t_o *v3;
  Il2CppObject *lightPacket;
  Il2CppObject *v6;
  sdfGrRefPacketHeader_t_o *v7;
  struct sdfDmaTag_t_o *linktag;
  sdfDmaTag_t_c *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  Il2CppObject *fogPacket;
  Il2CppObject *v14;
  sdfGrRefPacketHeader_t_o *v15;
  struct sdfDmaTag_t_o *v16;
  sdfDmaTag_t_c *v17;
  s64 v18;
  char *v19;
  s64 *v20;
  u64 v21[2];
  char *v22;

  v3 = aBack;
  lightPacket = aFore->lightPacket;
  v6 = v3->lightPacket;
  if (lightPacket != v6)
  {
    if (!v6)
    {
      v3->lightPacket = lightPacket;
      fogPacket = aFore->fogPacket;
      v14 = v3->fogPacket;
      if (fogPacket == v14)
        return;
      goto LABEL_18;
    }
    v7 = Allocate(sdfGrRefPacketHeader_t);
    sdfGrRefPacketHeader_t___ctor(v7);
    linktag = v7->linktag;
    if (linktag)
    {
      klass = linktag->klass;
      if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfGrPacketHeader_t)
      {
        sub_8FC2C0(klass->_1.element_class, sdfGrPacketHeader_t, v21);
        if ((v21[0] & 1) != 0)
          v11 = v22;
        else
          v11 = v21 + 1;
        v12 = sub_8C4940(v11);
      }
    }
  }
  fogPacket = aFore->fogPacket;
  v14 = v3->fogPacket;
  if (fogPacket == v14)
    return;
LABEL_18:
  if (v14)
  {
    v15 = Allocate(sdfGrRefPacketHeader_t);
    sdfGrRefPacketHeader_t___ctor(v15);
    v16 = v15->linktag;
    if (v16)
    {
      v17 = v16->klass;
      if (v17->_2.typeHierarchyDepth < v18 || v17->_2.typeHierarchy[v18 - 1] != sdfGrPacketHeader_t)
      {
        sub_8FC2C0(v17->_1.element_class, sdfGrPacketHeader_t, v21);
        if ((v21[0] & 1) != 0)
          v19 = v22;
        else
          v19 = v21 + 1;
        v20 = sub_8C4940(v19);
      }
    }
  }
  else
  {
    v3->fogPacket = fogPacket;
  }
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
  sdfDrawTag_t_o *v3;
  sdfDrawTag_t_o *tagTail;
  sdfGrOt_t_callbackFuncDelegate_o *callbackFunc;
  u64 *v6;
  sdfDrawTag_t_o *tagHead;
  s32 v11;

  else
  {
    v3 = 0;
    sdfPacketBuffFlag = 0;
    if (!aOt)
      return v3;
  }
  tagTail = 0;
  do
  {
    callbackFunc = aOt->callbackFunc;
    v11 = 0;
    v6 = sub_8D3950(s32, &v11);
    sdfGrOt_t_callbackFuncDelegate__Invoke(callbackFunc, aOt, 0, v6);
    tagHead = aOt->tagHead;
    if (tagHead)
    {
      if (v3)
      {
        sdfGrJoinDrawTag(tagTail, tagHead);
      }
      else
      {
        sdfGrInitExPacket(tagHead);
        v3 = tagHead;
      }
      tagTail = aOt->tagTail;
    }
    aOt = aOt->next;
  }
  while (aOt);
  return v3;
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
  u64 *v5;
  s32 i;
  u64 *v7;
  u64 *v8;
  s32 v9;

  v5 = Allocate(sdfGrOt_t);
  sdfGrOt_t___ctor(v5);
  for (i = 1 - aNumOt; ; ++i)
  {
    aOt->tagTail = 0;
    aOt->noSortTag = 0;
    aOt->tagHead = 0;
    v7 = Allocate(sdfGrOt_t_regFuncDelegate);
    sdfGrOt_t_regFuncDelegate___ctor(v7, 0, Method_sdfDraw_sdfGrOtNormalReg__);
    aOt->regFunc = v7;
    v8 = Allocate(sdfGrOt_t_callbackFuncDelegate);
    sdfGrOt_t_callbackFuncDelegate___ctor(v8, 0, Method_sdfDraw_sdfGrOtNormalCallback__);
    aOt->callbackFunc = v8;
    v9 = 0;
    aOt->data = sub_8D3950(s32, &v9);
    if (!i)
      break;
    aOt->next = v5;
    aOt = v5;
  }
  aOt->next = 0;
}

// 0x17e8cd0
void sdfGrOtNormalCallback(sdfGrOt_t *aOt, s32 aFunc, void *aData) {
  s32 v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  sdfDrawTag_t_o *tagHead;
  u64 v12[3];

  v5 = aFunc;
  if (v5 == 1)
  {
    else if (aData)
    {
LABEL_7:
      klass = aData->klass;
      if (aData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfDrawTag_t)
      {
        sub_8FC2C0(klass->_1.element_class, sdfDrawTag_t, v12);
        if ((v12[0] & 1) != 0)
          v9 = v12[2];
        else
          v9 = v12 + 1;
        v10 = sub_8C4940(v9);
      }
    }
    if (aData[2].klass)
    {
      tagHead = aOt->tagHead;
      if (tagHead)
      {
        sdfGrJoinDrawTag(aData, tagHead, aData);
      }
      else
      {
        aOt->tagTail = aData;
      }
      aData[1].klass = tagHead;
      aOt->tagHead = aData;
    }
  }
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
        goto LABEL_12;
    }
  }
  while (sdfReqDrawDelayCount);
LABEL_12:
  RunTimeCount = sdfGetRunTimeCount(RunTimeCountBase);
  sdfReqDrawDelaySleepCount = RunTimeCount;
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
  u64 *v5;
  u64 v6;
  s64 typeHierarchyDepth;
  sdfPreDrawHook_t_c *klass;
  s64 v10;
  sdfPreDrawHook_t_c *v11;
  u64 *monitor;
  char *v13;
  s64 *v14;
  char *v15;
  s64 *v16;
  u64 v17[2];
  char *v18;
  u32 option0;

  option0 = aPre->option0;
  v5 = sub_8D3950(uint, &option0);
  v6 = *v5;
  if (*(*v5 + 288) < typeHierarchyDepth
    || *(*(v6 + 200) + 8 * typeHierarchyDepth - 8) != sdfGrFrameSet_t)
  {
    sub_8FC2C0(*(v6 + 64), sdfGrFrameSet_t, v17);
    if ((v17[0] & 1) != 0)
      v13 = v18;
    else
      v13 = v17 + 1;
    v14 = sub_8C4940(v13);
  }
  klass = aPre->klass;
  if (aPre->klass->_2.typeHierarchyDepth < v10
    || klass->_2.typeHierarchy[v10 - 1] != sdfGrStdDrawEnv_t)
  {
    sub_8FC2C0(klass->_1.element_class, sdfGrStdDrawEnv_t, v17);
    if ((v17[0] & 1) != 0)
      v15 = v18;
    else
      v15 = v17 + 1;
    v16 = sub_8C4940(v15);
  }
  v11 = aPre[1].klass;
  *(v11->_1.name + 4) = 76;
  *(v11->_1.namespaze + 4) = 78;
  *(v11->_1.byval_arg.data + 4) = 24;
  *(*&v11->_1.byval_arg.bits + 32LL) = 64;
  monitor = aPre[1].monitor;
  *(monitor[2] + 32LL) = 77;
  *(monitor[3] + 32LL) = 79;
  *(monitor[4] + 32LL) = 25;
  *(monitor[5] + 32LL) = 65;
  *&aPre[2].next->next->next->option0 = 76;
  aPre[2].next->next->predrawFunc->m_target = (&loc_4C + 1);
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
