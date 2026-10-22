#include "types.h"

typedef struct sdfDelayedResrcCB_t sdfDelayedResrcCB_t;
typedef struct sdfGsMemSlice_t sdfGsMemSlice_t;
typedef struct sdfGsMemory_sdfGsErrorHandlerDelegate sdfGsMemory_sdfGsErrorHandlerDelegate;

static sdfGsMemSlice_t *gsMemHandleLinkHead;
static sdfGsMemSlice_t *gsMemHandleLinkTail;
static sdfDelayedResrcCB_t *gsMemDelayedResrcCB;
static sdfGsMemory_sdfGsErrorHandlerDelegate *sdfGsErrorHandler;

void *sdfGsMemAllocFromHead(s32 aSize, s32 aType);

// 0x1791f50
s32 SDF_GS_SET_ALPHA(s32 a, s32 b, s32 c, s32 d, s32 fix) {
  return a | (4 * b) | (16 * c) | fix | (d << 6);
}

// 0x1792090
s32 sdfGetTexelBitCount(s32 aFormat) {
  s32 result;

  if (aFormat <= 20)
  {
    if (aFormat <= 10)
    {
      result = 24;
      switch (aFormat)
      {
        case 0:
          result = 32;
          break;
        case 1:
          return result;
        case 2:
        case 10:
LABEL_13:
          result = 16;
          break;
        default:
LABEL_14:
          result = 0;
          break;
      }
    }
    else if (aFormat == 19)
    {
      return 8;
    }
    else
    {
      return 4 * (aFormat == 20);
    }
  }
  else if (aFormat <= 36)
  {
    if (aFormat == 27)
      return 8;
    else
      return 4 * (aFormat == 36);
  }
  else
  {
    result = 4;
    switch (aFormat)
    {
      case ',':
        return result;
      case '0':
        result = 32;
        break;
      case '1':
        result = 24;
        break;
      case '2':
      case ':':
        goto LABEL_13;
      default:
        goto LABEL_14;
    }
  }
  return result;
}

// 0x1792c00
sdfGsMemSlice_t *sdfGsAllocFrameBuff(s32 aW, s32 aH, s32 aPixelFormat) {
  u64 *v7;
  s32 v10;
  sdfGsMemSlice_t_o *result;
  sdfGsMemSlice_t_c *klass;
  s64 typeHierarchyDepth;
  sdfGsMemSlice_t_c *v14;
  s64 v15;
  char *v16;
  s64 *v17;
  char *v18;
  s64 *v19;
  u64 v20[2];
  char *v21;

  v7 = Allocate(sdfGsFrameBuff_t);
  sdfGsFrameBuff_t___ctor(v7);
  v10 = (aW + 63) & 0xFFFFFFC0;
  if (aPixelFormat > 10)
  {
    if ((aPixelFormat & 0xFFFFFFFE) == 0x30 || (aPixelFormat | 8) != 0x3A)
      goto LABEL_10;
LABEL_9:
    v10 >>= 1;
    goto LABEL_10;
  }
  if (aPixelFormat >= 2 && (aPixelFormat | 8) == 0xA)
    goto LABEL_9;
LABEL_10:
  result = sdfGsMemAllocFromHead((v10 * ((aH + 31) & 0xFFFFFFE0) + 2047) & 0xFFFFF800, 1);
  klass = result->klass;
  if (result->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfGsFrameBuff_t)
  {
    sub_8FC2C0(klass->_1.element_class, sdfGsFrameBuff_t, v20);
    if ((v20[0] & 1) != 0)
      v18 = v21;
    else
      v18 = v20 + 1;
    v19 = sub_8C4940(v18);
  }
  result->prev->w = aW;
  result->prev->h = aH;
  result->prev->pixelFormat = aPixelFormat;
  if (result)
  {
    v14 = result->klass;
    if (result->klass->_2.typeHierarchyDepth < v15
      || v14->_2.typeHierarchy[v15 - 1] != sdfGsMemSlice_t)
    {
      sub_8FC2C0(v14->_1.element_class, sdfGsMemSlice_t, v20);
      if ((v20[0] & 1) != 0)
        v16 = v21;
      else
        v16 = v20 + 1;
      v17 = sub_8C4940(v16);
    }
  }
  return result;
}

// 0x1792220
void *sdfGsMemAllocFromHead(s32 aSize, s32 aType) {
  u64 *v5;
  sdfGsMemSlice_t_o *v6;
  struct sdfGsMemSlice_t_o *gsMemHandleLinkHead;
  sdfGsMemory_sdfGsErrorHandlerDelegate_o *sdfGsErrorHandler;
  s32 size;
  struct sdfGsMemSlice_t_o *prev;
  s32 v14;

  v5 = Allocate(sdfGsMemSlice_t);
  sdfGsMemSlice_t___ctor(v5);
  v6 = Allocate(sdfGsMemSlice_t);
  sdfGsMemSlice_t___ctor(v6);
  else
  {
    if (gsMemHandleLinkHead)
      goto LABEL_17;
  }
LABEL_10:
  else
  {
    if (!sdfGsErrorHandler)
      goto LABEL_17;
  }
  Invoke(sdfGsErrorHandler, aSize, aType);
LABEL_17:
  while (1)
  {
    if (!gsMemHandleLinkHead->type)
    {
      size = gsMemHandleLinkHead->size;
      if (size >= aSize)
        break;
    }
    gsMemHandleLinkHead = gsMemHandleLinkHead->next;
    if (!gsMemHandleLinkHead)
      goto LABEL_10;
  }
  if (size == aSize)
  {
    gsMemHandleLinkHead->type = aType;
    return gsMemHandleLinkHead;
  }
  else
  {
    prev = gsMemHandleLinkHead->prev;
    v6->prev = prev;
    if (prev)
      gsMemHandleLinkHead->prev->next = v6;
    gsMemHandleLinkHead->prev = v6;
    v6->next = gsMemHandleLinkHead;
    v6->type = aType;
    v6->addr = gsMemHandleLinkHead->addr;
    v6->size = aSize;
    v14 = gsMemHandleLinkHead->size;
    gsMemHandleLinkHead->addr += aSize;
    gsMemHandleLinkHead->size = v14 - aSize;
  }
  return v6;
}

// 0x17927b0
sdfGsMemSlice_t *sdfGsMemAllocFromTail(s32 aSize, s32 aType) {
  u64 *v5;
  sdfGsMemSlice_t_o *v6;
  struct sdfGsMemSlice_t_o *gsMemHandleLinkTail;
  sdfGsMemory_sdfGsErrorHandlerDelegate_o *sdfGsErrorHandler;
  s32 size;
  struct sdfGsMemSlice_t_o *next;

  v5 = Allocate(sdfGsMemSlice_t);
  sdfGsMemSlice_t___ctor(v5);
  v6 = Allocate(sdfGsMemSlice_t);
  sdfGsMemSlice_t___ctor(v6);
  else
  {
    if (gsMemHandleLinkTail)
      goto LABEL_17;
  }
LABEL_10:
  else
  {
    if (!sdfGsErrorHandler)
      goto LABEL_17;
  }
  Invoke(sdfGsErrorHandler, aSize, aType);
LABEL_17:
  while (1)
  {
    if (!gsMemHandleLinkTail->type)
    {
      size = gsMemHandleLinkTail->size;
      if (size >= aSize)
        break;
    }
    gsMemHandleLinkTail = gsMemHandleLinkTail->prev;
    if (!gsMemHandleLinkTail)
      goto LABEL_10;
  }
  if (size == aSize)
  {
    gsMemHandleLinkTail->type = aType;
  }
  else
  {
    next = gsMemHandleLinkTail->next;
    v6->next = next;
    if (next)
      gsMemHandleLinkTail->next->prev = v6;
    gsMemHandleLinkTail->next = v6;
    v6->prev = gsMemHandleLinkTail;
    v6->type = aType;
    v6->size = aSize;
    gsMemHandleLinkTail->size -= aSize;
    return v6;
  }
  return gsMemHandleLinkTail;
}

// 0x1792950
sdfGsMemSlice_t *sdfGsMemAllocRect(s32 aWidth, s32 aHeight, s32 aFormat, s32 aType, s32 aFromHead) {
  u64 *v6;

  v6 = Allocate(sdfGsMemSlice_t);
  sdfGsMemSlice_t___ctor(v6);
  return v6;
}

// 0x1792160
s32 sdfGsMemCheckHandle(sdfGsMemSlice_t *aHandle) {
  u64 *v3;
  struct sdfGsMemSlice_t_o *gsMemHandleLinkHead;

  v3 = Allocate(sdfGsMemSlice_t);
  sdfGsMemSlice_t___ctor(v3);
  if (!gsMemHandleLinkHead)
    return 0;
LABEL_6:
  while (gsMemHandleLinkHead != aHandle)
  {
    gsMemHandleLinkHead = gsMemHandleLinkHead->next;
    if (!gsMemHandleLinkHead)
      return 0;
  }
  return 1;
}

// 0x1791f70
void sdfGsMemCheckLinkConsistence(void) {
  sdfGsMemSlice_t_o *next;
  sdfGsMemSlice_t_o *prev;

  next = Allocate(sdfGsMemSlice_t);
  sdfGsMemSlice_t___ctor(next);
  do
  {
    prev = next;
    next = next->next;
  }
  while (next);
  do
    prev = prev->prev;
  while (prev);
}

// 0x17929b0
s32 sdfGsMemCheckMerge(sdfGsMemSlice_t *aHandle) {
  u64 *v3;
  struct sdfGsMemSlice_t_o *next;
  struct sdfGsMemSlice_t_o *v6;

  v3 = Allocate(sdfGsMemSlice_t);
  sdfGsMemSlice_t___ctor(v3);
  next = aHandle->next;
  if (!next)
    return 0;
  if (next->type)
    return 0;
  aHandle->size += next->size;
  v6 = next->next;
  aHandle->next = v6;
  if (v6)
    next->next->prev = aHandle;
  return 1;
}

// 0x1792a60
void sdfGsMemFree(sdfGsMemSlice_t *aHandle) {
  u64 *v3;
  struct sdfGsMemSlice_t_o *next;
  struct sdfGsMemSlice_t_o *v6;
  struct sdfGsMemSlice_t_o *prev;
  u64 *v8;
  struct sdfGsMemSlice_t_o *v9;
  struct sdfGsMemSlice_t_o *v10;

  if (aHandle)
  {
    aHandle->type = 0;
    v3 = Allocate(sdfGsMemSlice_t);
    sdfGsMemSlice_t___ctor(v3);
    next = aHandle->next;
    if (next)
    {
      if (!next->type)
      {
        aHandle->size += next->size;
        v6 = next->next;
        aHandle->next = v6;
        if (v6)
          next->next->prev = aHandle;
      }
    }
    prev = aHandle->prev;
    if (prev && !prev->type)
    {
      v8 = Allocate(sdfGsMemSlice_t);
      sdfGsMemSlice_t___ctor(v8);
      v9 = prev->next;
      if (v9 && !v9->type)
      {
        prev->size += v9->size;
        v10 = v9->next;
        prev->next = v10;
        if (v10)
          v9->next->prev = prev;
      }
    }
  }
}

// 0x1792be0
void sdfGsMemFreeDelayed(sdfGsMemSlice_t *aHandle) {
  ;
}

// 0x1791fe0
s32 sdfGsMemGetBitCount(s32 aFormat) {
  if (aFormat <= 19)
  {
    if (aFormat <= 2)
    {
      if (aFormat < 2)
        return 32;
      if (aFormat == 2)
        return 16;
      return 0;
    }
    if (aFormat == 10)
      return 16;
    else
      return 8 * (aFormat == 19);
  }
  else
  {
    if (aFormat > 27)
    {
      if (aFormat <= 0x3A)
      {
        if (((1LL << aFormat) & 0x3101000000000LL) != 0)
          return 32;
        if (aFormat == 50 || aFormat == 58)
          return 16;
      }
      return 0;
    }
    if (aFormat == 20)
      return 4;
    else
      return 32 * (aFormat == 27);
  }
}

// 0x1792e30
sdfGsMemSlice_t *sdfGsMemGetLinkHead(void) {
  return gsMemHandleLinkHead;
}

// 0x1792ea0
sdfGsMemSlice_t *sdfGsMemGetLinkTail(void) {
  return gsMemHandleLinkTail;
}

// 0x1792bf0
void sdfGsMemInit(void) {
  ;
}
