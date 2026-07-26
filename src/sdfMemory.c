#include "types.h"

typedef struct sdfDelayedResrcCB_t sdfDelayedResrcCB_t;
typedef struct sdfMemHandleCB_tag sdfMemHandleCB_tag;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfMemInfo_t sdfMemInfo_t;
typedef struct sdfMemRecord_t sdfMemRecord_t;
typedef struct sdfMemory_sdfMemErrorHandlerDelegate sdfMemory_sdfMemErrorHandlerDelegate;

static sdfMemHandleCB_tag *sdfMemCB;
static sdfDelayedResrcCB_t *sdfMemDelayedResrcCB;
static sdfMemRecord_t *sdfMemRecordList[256];
static sdfMemory_sdfMemErrorHandlerDelegate *sdfMemErrorHandler;

void *sdfChipAllocDirect(s32 aSize);
void sdfChipFreeDirect(void *aPtr);
void sdfDelayedResrcEntry(sdfDelayedResrcCB_t *aCB, void *aItem);
void sdfMemFreeDirect(sdfMemHandle_t *aHandle);
void sdfMemPurgeRecord(sdfMemHandle_t *aHandle, char *aFile, s32 aLine);

// 0x17993f0
sdfMemHandle_t *sdfMemAlloc2Direct(s32 aSize) {
    sdfChipAllocDirect(0);
    return 0;
}

// 0x179a850
sdfMemHandle_t *sdfMemAlloc2Record(s32 aSize, char *aFile, s32 aLine) {
    sdfChipAllocDirect(0);
    return 0;
}

// 0x1798b10
sdfMemHandle_t *sdfMemAllocDirect(s32 aSize) {
    sdfChipAllocDirect(0);
    return 0;
}

// 0x1799190
sdfMemHandle_t *sdfMemAllocFromTailDirect(s32 aSize) {
    sdfChipAllocDirect(0);
    return 0;
}

// 0x179a5b0
sdfMemHandle_t *sdfMemAllocFromTailRecord(s32 aSize, char *aFile, s32 aLine) {
    sdfChipAllocDirect(0);
    return 0;
}

// 0x179a310
sdfMemHandle_t *sdfMemAllocRecord(s32 aSize, char *aFile, s32 aLine) {
    sdfChipAllocDirect(0);
    return 0;
}

// 0x1799f70
void sdfMemFreeDelayedDirect(sdfMemHandle_t *aHandle) {
  sdfDelayedResrcCB_t_o *sdfMemDelayedResrcCB;

  if (aHandle)
  {
    sdfDelayedResrcEntry(sdfMemDelayedResrcCB, aHandle);
  }
}

// 0x179ae20
void sdfMemFreeDelayedRecord(sdfMemHandle_t *aHandle, char *aFile, s32 aLine) {
  sdfDelayedResrcCB_t_o *sdfMemDelayedResrcCB;

  if (aHandle)
  {
    sdfMemPurgeRecord(aHandle, aFile, aLine);
    sdfDelayedResrcEntry(sdfMemDelayedResrcCB, aHandle);
  }
}

// 0x1799a90
void sdfMemFreeDirect(sdfMemHandle_t *aHandle) {
  u64 *v3;
  u64 *v4;
  struct sdfMemHandle_t_o *next;
  struct sdfMemHandle_t_o *prev;
  u64 *v8;
  u64 *v9;
  struct sdfMemHandle_t_o *v11;
  u64 *v12;
  u64 *v13;
  struct sdfMemHandle_t_o *v15;

  v3 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v3);
  v4 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v4);
  if (aHandle)
  {
    next = aHandle->next;
    if (next->stat)
    {
      prev = aHandle->prev;
      if (prev->stat)
      {
        *&aHandle->stat = 0;
        return;
      }
    }
    else
    {
      v8 = Allocate(sdfMemHandle_t);
      sdfMemHandle_t___ctor(v8);
      v9 = Allocate(sdfMemHandle_t);
      sdfMemHandle_t___ctor(v9);
      v11 = aHandle->next->next;
      v11->prev = aHandle;
      aHandle->next = v11;
      sdfChipFreeDirect(next);
      prev = aHandle->prev;
      if (prev->stat)
    }
    v12 = Allocate(sdfMemHandle_t);
    sdfMemHandle_t___ctor(v12);
    v13 = Allocate(sdfMemHandle_t);
    sdfMemHandle_t___ctor(v13);
    v15 = prev->next->next;
    v15->prev = prev;
    prev->next = v15;
    sdfChipFreeDirect(aHandle);
  }
}

// 0x1799ed0
void sdfMemFreeHandleDirect(sdfMemHandle_t *aHandlePtr) {
  u64 *v2;
  sdfMemHandle_t_o *v4;

  v2 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v2);
  if (v2)
  {
    else
    {
      v4 = v2;
    }
    sdfMemFreeDirect(v4);
  }
}

// 0x179ad80
void sdfMemFreeHandleRecord(sdfMemHandle_t *aHandlePtr, char *aFile, s32 aLine) {
  u64 *v4;
  System_String_o *v5;
  s32 v6;

  v4 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v4);
  if (v4)
  {
    sdfMemPurgeRecord(v4, v5, v6);
    sdfMemFreeDirect(v4);
  }
}

// 0x1799c80
void sdfMemFreeMerge(sdfMemHandle_t *aHandle) {
  u64 *v3;
  u64 *v4;
  struct sdfMemHandle_t_o *next;

  v3 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v3);
  v4 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v4);
  next = aHandle->next->next;
  next->prev = aHandle;
  aHandle->next = next;
}

// 0x1799d00
void sdfMemFreePtrDirect(void *aPtr) {
  struct sdfMemHandleCB_tag_o *sdfMemCB;
  u64 *v5;
  sdfMemHandle_t_o *next;

  v5 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v5);
  next = sdfMemCB->headGuard->next;
  if (next->stat == 1)
  do
  {
    do
      next = next->next;
    while (next->stat != 1);
    ;
  }
  while (next->ptr != aPtr);
  sdfMemFreeDirect(next);
}

// 0x179ace0
void sdfMemFreePtrRecord(void *aPtr, char *aFile, s32 aLine) {
  u64 *v5;
  System_String_o *v6;
  s32 v7;

  v5 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v5);
  if (aPtr)
  {
    sdfMemPurgeRecord(v5, v6, v7);
    sdfMemFreeDirect(v5);
  }
}

// 0x179ac60
void sdfMemFreeRecord(sdfMemHandle_t *aHandle, char *aFile, s32 aLine) {
  if (aHandle)
  {
    sdfMemPurgeRecord(aHandle, aFile, aLine);
    sdfMemFreeDirect(aHandle);
  }
}

// 0x1799e10
sdfMemHandle_t *sdfMemGetHandleByPtr(void *aPtr) {
  struct sdfMemHandleCB_tag_o *sdfMemCB;
  u64 *v5;
  sdfMemHandle_t_o *result;

  v5 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v5);
  result = sdfMemCB->headGuard->next;
  if (result->stat == 1)
  do
  {
    do
      result = result->next;
    while (result->stat != 1);
    ;
  }
  while (result->ptr != aPtr);
  return result;
}

// 0x179a060
void sdfMemGetInfo(sdfMemInfo_t *aInfo) {
  struct sdfMemHandleCB_tag_o *sdfMemCB;
  u64 *v4;
  struct sdfMemHandle_t_o *next;
  s32 v6;
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;
  s32 v11;
  s64 ptr;
  s32 v13;
  u32 *v14;
  s32 stat;
  s32 v16;
  s32 v18;
  s32 v19;

  v4 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v4);
  next = sdfMemCB->headGuard->next;
  if (next->stat == 2)
  {
    v6 = 0;
    v7 = 0;
    v8 = 0;
    v9 = 0;
    v10 = 0;
    v11 = 0;
  }
  else
  {
    v11 = 0;
    v10 = 0;
    v9 = 0;
    v8 = 0;
    v7 = 0;
    v6 = 0;
    do
    {
      ptr = next->ptr;
      ++v7;
      v13 = *il2cp::SizeOf(next->next->ptr, s32);
      v14 = il2cp::SizeOf(ptr, s32);
      stat = next->stat;
      v16 = v13 - *v14;
      next = next->next;
      if (v16 < v8 || v8 == 0)
        v18 = v13 - *v14;
      else
        v18 = v8;
      v11 += v16;
      v19 = v16 + v10;
      if (v16 <= v9)
        v16 = v9;
      if (!stat)
      {
        ++v6;
        v8 = v18;
        v9 = v16;
        v10 = v19;
      }
    }
    while (next->stat != 2);
  }
  aInfo->total = v11;
  aInfo->freeSize = v10;
  aInfo->maxFreeSize = v9;
  aInfo->minFreeSize = v8;
  aInfo->handleCount = v7;
  aInfo->freeHandleCount = v6;
}

// 0x1798a10
sdfMemHandle_t *sdfMemGetNext(sdfMemHandle_t *aHandle) {
  u64 *v3;

  v3 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v3);
  if (aHandle->next->stat == 2)
    return 0;
  else
    return aHandle->next;
}

// 0x1798b00
void *sdfMemGetPtr(sdfMemHandle_t *aHandle) {
  return aHandle->ptr;
}

// 0x1798a80
s32 sdfMemGetSize(sdfMemHandle_t *aHandle) {
  struct sdfMemHandle_t_o *next;
  Il2CppObject *ptr;
  s32 v5;

  next = aHandle->next;
  ptr = aHandle->ptr;
  v5 = *il2cp::SizeOf(next->ptr, s32);
  return v5 - *il2cp::SizeOf(ptr, s32);
}

// 0x17989a0
sdfMemHandle_t *sdfMemGetTop(void) {
  return sdfMemCB->headGuard->next;
}

// 0x1798990
s32 sdfMemGetType(sdfMemHandle_t *aHandle) {
  return aHandle->stat;
}

// 0x179a300
u32 sdfMemHashKey(sdfMemHandle_t *aHandle) {
  return 0;
}

// 0x1798750
void sdfMemInit(s32 aSize) {
    sdfChipAllocDirect(0);
}

// 0x179a020
void *sdfMemLock(sdfMemHandle_t *aHandle) {
  ++aHandle->mlock;
  return aHandle->ptr;
}

// 0x179ab00
void sdfMemPurgeRecord(sdfMemHandle_t *aHandle, char *aFile, s32 aLine) {
    sdfChipFreeDirect(0);
}

// 0x1799660
void sdfMemReallocRecord(sdfMemHandle_t *aHandle, s32 aSize, char *aFile, s32 aLine) {
    sdfChipAllocDirect(0);
    sdfChipFreeDirect(0);
    sdfMemFreeDirect(0);
}

// 0x179af20
void sdfMemRecordDump(void) {
  u64 i;
  struct sdfMemRecord_t_array *sdfMemRecordList;
  sdfMemRecord_t_o **p_next;
  sdfMemRecord_t_o *v7;

  for (i = 0; i != 256; ++i)
  {
    p_next = &sdfMemRecordList->m_Items[i];
    do
    {
      v7 = *p_next;
      p_next = &(*p_next)->next;
    }
    while (v7);
  }
}

// 0x179a1e0
sdfMemHandle_t *sdfMemSearchHandle(void *ptr) {
  u64 *v3;
  u64 *v4;
  s32 v5;
  u64 v6;
  s32 v7;
  s32 v8;

  v3 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v3);
  v4 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v4);
  do
  {
    while (1)
    {
      v5 = *(v3 + 20);
      if (v5 != 1)
        break;
      v6 = v3[3];
      v7 = *il2cp::SizeOf(v3[4], s32);
      if (v7 <= *il2cp::SizeOf(ptr, s32))
      {
        v8 = *il2cp::SizeOf(*(v6 + 32), s32);
        if (v8 > *il2cp::SizeOf(ptr, s32))
          return v3;
      }
    }
  }
  while (v5 != 2);
  return 0;
}

// 0x17986a0
sdfMemRecord_t *sdfMemSearchRecord(sdfMemHandle_t *aHandle, char *aFile, s32 aLine) {
    return 0;
}

// 0x179a040
void sdfMemUnlock(sdfMemHandle_t *aHandle) {
  if (aHandle->mlock)
    --aHandle->mlock;
}
