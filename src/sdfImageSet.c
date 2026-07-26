#include "types.h"

typedef struct sdfImageSetCb_t sdfImageSetCb_t;
typedef struct sdfImageSetParm_t sdfImageSetParm_t;

static sdfImageSetCb_t *sdfImageSetCb;

// 0x1793150
s32 sdfImageDataSize(s32 format, s32 width, s32 height) {
  s32 v5;

  if (format <= 20)
  {
    if (format <= 2)
    {
      if (format == 2)
        v5 = 16;
      else
        v5 = 32;
      if (format == 1)
        v5 = 24;
      return (height * width * v5) >> 7;
    }
    else
    {
      if (format == 10)
        return (16 * height * width) >> 7;
      if (format != 19)
      {
        if (format == 20)
          return (4 * height * width) >> 7;
        return (32 * height * width) >> 7;
      }
      return (8 * height * width) >> 7;
    }
  }
  else if (format <= 44)
  {
    if (format != 27)
    {
      if (format == 36 || format == 44)
        return (4 * height * width) >> 7;
      return (32 * height * width) >> 7;
    }
    return (8 * height * width) >> 7;
  }
  else
  {
    if (format != 49)
    {
      if (format != 50 && format != 58)
        return (32 * height * width) >> 7;
      return (16 * height * width) >> 7;
    }
    return (24 * height * width) >> 7;
  }
}

// 0x1793290
void sdfImageSetChainReleaseMem(void *p) {
  ;
}

// 0x1793280
void sdfImageSetChainTag(void *head, void *tail) {
  ;
}

// 0x17932a0
void sdfImageSetClearCb(sdfImageSetCb_t *cb) {
  cb->tagHead = 0;
  cb->tagTail = 0;
  cb->packetHead = 0;
  cb->packetTail = 0;
}

// 0x17932b0
s32 sdfImageSetDmacHandler(s32 ch, void *arg, void *addr) {
  return -1;
}

// 0x17932d0
void sdfImageSetInit(void) {
  struct sdfImageSetCb_t_o *sdfImageSetCb;

  sdfImageSetCb->tagHead = 0;
  sdfImageSetCb->tagTail = 0;
  sdfImageSetCb->packetHead = 0;
  sdfImageSetCb->packetTail = 0;
}

// 0x1793270
void sdfImageSetReq(sdfImageSetParm_t *parm) {
  ;
}

// 0x17932c0
void sdfImageSetTrans(void) {
  ;
}
