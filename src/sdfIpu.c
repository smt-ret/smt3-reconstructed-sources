#include "types.h"

typedef struct sdfHandlerLink_t sdfHandlerLink_t;
typedef struct sdfIpuDecodeCb_t sdfIpuDecodeCb_t;
typedef struct sdfIpuInitParm_t sdfIpuInitParm_t;
typedef struct sdfIpuStrmCallback_t sdfIpuStrmCallback_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

static sdfIpuDecodeCb_t *sdfIpuTaskLink;
static sdfHandlerLink_t *sdfFromIpuDmacHandlerHandle;
static sdfHandlerLink_t *sdfToIpuDmacHandlerHandle;
static sdfIpuDecodeCb_t *sdfCurrIpuDecodeCb;
static sdfIpuDecodeCb_t *sdfIpuCurrToDmaCb;
static sdfIpuDecodeCb_t *sdfIpuQueueHead;
static sdfIpuDecodeCb_t *sdfIpuQueueTail;
static u8 ipu_error_info;
static s32 sdfIpuDecodeThId;
static u32 sdfIpuDecodeThStack[512];
static s32 sdfIpuToDmacHandler_last_frame;

void sdfIpuAttachQueue(sdfIpuDecodeCb_t *cb, s32 critical);
void sdfIpuDecode(sdfIpuDecodeCb_t *cb, sdfIpuInitParm_t *parm, void *data, s32 leng);
void sdfIpuDetachQueue(sdfIpuDecodeCb_t *cb, s32 critical);
void sdfIpuExecQueue(s32 critical);

// 0x1793d90
void sdfIpuAllocBuff(sdfIpuDecodeCb_t *cb) {
  s32 v2;

  if (cb->rgbMode)
    v2 = 2;
  else
    v2 = 4;
  cb->buffSize = v2 * cb->width * cb->height;
}

// 0x1793b70
void sdfIpuAttachQueue(sdfIpuDecodeCb_t *cb, s32 critical) {
    sdfIpuDetachQueue(0, 0);
}

// 0x1793c90
void sdfIpuAttachTask(sdfIpuDecodeCb_t *cb) {
  sdfIpu_c *v3;
  struct sdfIpu_StaticFields *static_fields;
  struct sdfIpuDecodeCb_t_o *sdfIpuTaskLink;

  static_fields = v3->static_fields;
  do
  {
    sdfIpuTaskLink = static_fields->sdfIpuTaskLink;
    static_fields = &static_fields->sdfIpuTaskLink->taskNext;
  }
  while (sdfIpuTaskLink);
  cb->taskNext = 0;
}

// 0x17944e0
void sdfIpuClose(void) {
  ;
}

// 0x1793e20
void sdfIpuDecode(sdfIpuDecodeCb_t *cb, sdfIpuInitParm_t *parm, void *data, s32 leng) {
    sdfIpuAttachQueue(0, 0);
    sdfIpuExecQueue(0);
}

// 0x17940f0
void sdfIpuDecodeThread(void *dummy) {
  ;
}

// 0x1793a90
void sdfIpuDetachQueue(sdfIpuDecodeCb_t *cb, s32 critical) {
  struct sdfIpuDecodeCb_t_o *prev;
  struct sdfIpuDecodeCb_t_o *next;
  sdfIpuDecodeCb_t_Fields *p_fields;

  if (cb->queueLinked)
  {
    prev = cb->prev;
    next = cb->next;
    if (prev)
    {
      prev->next = next;
      if (next)
      {
        p_fields = &next->fields;
        p_fields->prev = prev;
        cb->queueLinked = 0;
        return;
      }
    }
    else
    {
      sdfIpuQueueHead = next;
      if (next)
    }
    p_fields = &sdfIpuQueueTail;
  }
}

// 0x1793d10
void sdfIpuDetachTask(sdfIpuDecodeCb_t *cb) {
  sdfIpu_c *v3;
  struct sdfIpu_StaticFields *static_fields;
  sdfIpuDecodeCb_t_o *sdfIpuTaskLink;
  bool v6;

  static_fields = v3->static_fields;
  do
  {
    sdfIpuTaskLink = static_fields->sdfIpuTaskLink;
    v6 = static_fields->sdfIpuTaskLink == 0;
    static_fields = &static_fields->sdfIpuTaskLink->taskNext;
    v6 = v6 || sdfIpuTaskLink == cb;
  }
  while (!v6);
}

// 0x1793990
void sdfIpuExecQueue(s32 critical) {
  struct sdfIpu_StaticFields *static_fields;
  sdfIpuDecodeCb_t_o *sdfIpuQueueHead;

  else
  {
    static_fields = sdfIpu->static_fields;
    if (static_fields->sdfCurrIpuDecodeCb)
      return;
  }
  sdfIpuQueueHead = static_fields->sdfIpuQueueHead;
  if (sdfIpuQueueHead)
  {
    while (sdfIpuQueueHead->imageTrans + sdfIpuQueueHead->activeBuffCount > 1
         || sdfIpuQueueHead->type == 1 && !sdfIpuQueueHead->strmBuffActiveChunk)
    {
      sdfIpuQueueHead = sdfIpuQueueHead->next;
      if (!sdfIpuQueueHead)
        return;
    }
    sdfIpuDetachQueue(sdfIpuQueueHead);
  }
}

// 0x1794140
void sdfIpuFinishActiveFrame(sdfIpuDecodeCb_t *cb) {
  u8 getBuffId;
  s32 frameCount;
  s32 v5;
  s32 v6;

  if (cb->activeBuffCount)
  {
    getBuffId = cb->getBuffId;
    --cb->activeBuffCount;
    cb->getBuffId = getBuffId ^ 1;
    ++cb->imageTrans;
  }
  frameCount = cb->frameCount;
  v5 = cb->frame + 1;
  cb->frame = v5;
  if (v5 == frameCount && cb->loopMode)
    cb->frame = 0;
  sdfIpuExecQueue(v6);
}

// 0x17940a0
void sdfIpuFree(sdfIpuDecodeCb_t *cb) {
  ;
}

// 0x1794100
s32 sdfIpuFromDmacHandler(s32 ch, void *arg, void *stopPc) {
  return 0;
}

// 0x1794120
void *sdfIpuGetActiveFrame(sdfIpuDecodeCb_t *cb) {
  return 0;
}

// 0x1794130
void *sdfIpuGetActivePacket(sdfIpuDecodeCb_t *cb) {
  return 0;
}

// 0x17940e0
u32 sdfIpuGetFlag(void) {
  return 0;
}

// 0x17940b0
void sdfIpuGetStrmData(sdfIpuDecodeCb_t *cb) {
  ;
}

// 0x17944d0
void sdfIpuInit(void) {
  ;
}

// 0x1793de0
void sdfIpuInitCb(sdfIpuDecodeCb_t *cb, sdfIpuInitParm_t *parm) {
  u8 v3;

  if (parm->rgbMode)
  {
    if (parm->ditherMode)
      v3 = 2;
    else
      v3 = 1;
    cb->rgbMode = v3;
  }
  else
  {
    cb->rgbMode = 0;
  }
  cb->loopMode = parm->loopMode;
  cb->fps = parm->fps;
}

// 0x1793b60
void sdfIpuKickDecode(sdfIpuDecodeCb_t *cb) {
  ;
}

// 0x1793dd0
void sdfIpuMakeBltPacket(sdfIpuDecodeCb_t *cb) {
  ;
}

// 0x1793dc0
void sdfIpuMakeToIpuDmaTag(sdfIpuDecodeCb_t *cb, void *data, s32 leng) {
  ;
}

// 0x1794220
void sdfIpuPlay(sdfIpuDecodeCb_t *cb, sdfIpuInitParm_t *parm, void *data, s32 leng, u32 gsAddr) {
  sdfIpu_c *v12;
  struct sdfIpu_StaticFields *static_fields;
  struct sdfIpuDecodeCb_t_o *sdfIpuTaskLink;

  ipu_error_info = 0;
  sdfIpuDecode(cb, parm, data, leng, *&gsAddr);
  cb->gsAddr = gsAddr;
  static_fields = v12->static_fields;
  do
  {
    sdfIpuTaskLink = static_fields->sdfIpuTaskLink;
    static_fields = &static_fields->sdfIpuTaskLink->taskNext;
  }
  while (sdfIpuTaskLink);
  cb->taskNext = 0;
}

// 0x1794310
void sdfIpuPlayTex(sdfIpuDecodeCb_t *cb, sdfIpuInitParm_t *parm, void *data, s32 leng, sdfTexHandle_t *tex) {
  u64 *v6;

  v6 = Allocate(sdfIpuInitParm_t);
  sdfIpuInitParm_t___ctor(v6);
}

// 0x1794200
s32 sdfIpuReqBlt(sdfIpuDecodeCb_t *cb) {
  return 1;
}

// 0x17940d0
void sdfIpuSetFromIpuDma(sdfIpuDecodeCb_t *cb) {
  ;
}

// 0x17940c0
void sdfIpuSetToIpuDma(sdfIpuDecodeCb_t *cb) {
  ;
}

// 0x1793fc0
void sdfIpuStrmDecode(sdfIpuDecodeCb_t *cb, sdfIpuInitParm_t *parm, sdfIpuStrmCallback_t *callback, void *callbackParm) {
  u8 v9;

  if (!parm->rgbMode)
  if (parm->ditherMode)
    v9 = 2;
  else
    v9 = 1;
  cb->rgbMode = v9;
  cb->loopMode = parm->loopMode;
  cb->fps = parm->fps;
  cb->type = 1;
  cb->strmCallback = callback;
  cb->strmCallbackParm = callbackParm;
}

// 0x1794090
void sdfIpuStrmDecodeInit(sdfIpuDecodeCb_t *cb) {
  ;
}

// 0x1794360
void sdfIpuStrmPlay(sdfIpuDecodeCb_t *cb, sdfIpuInitParm_t *parm, sdfIpuStrmCallback_t *callback, void *callbackParm, u32 gsAddr) {
  u8 v12;
  u8 fps;
  sdfIpu_c *v14;
  struct sdfIpu_StaticFields *static_fields;
  struct sdfIpuDecodeCb_t_o *sdfIpuTaskLink;

  ipu_error_info = 0;
  if (!parm->rgbMode)
  if (parm->ditherMode)
    v12 = 2;
  else
    v12 = 1;
  cb->rgbMode = v12;
  cb->loopMode = parm->loopMode;
  fps = parm->fps;
  cb->type = 1;
  cb->gsAddr = gsAddr;
  cb->strmCallback = callback;
  cb->strmCallbackParm = callbackParm;
  cb->fps = fps;
  static_fields = v14->static_fields;
  do
  {
    sdfIpuTaskLink = static_fields->sdfIpuTaskLink;
    static_fields = &static_fields->sdfIpuTaskLink->taskNext;
  }
  while (sdfIpuTaskLink);
  cb->taskNext = 0;
}

// 0x1794210
void sdfIpuTask(s32 fpsBase) {
  ;
}

// 0x1794110
s32 sdfIpuToDmacHandler(s32 ch, void *arg, void *stopPc) {
  return 0;
}
