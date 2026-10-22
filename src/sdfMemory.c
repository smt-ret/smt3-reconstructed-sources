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
  struct sdfMemHandleCB_tag_o *sdfMemCB;
  u64 *v5;
  u64 *v6;
  struct sdfMemHandle_t_o *next;
  s32 stat;
  s64 ptr;
  s32 v10;
  s32 v12;
  s32 v14;
  Il2CppObject *v15;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppObject *v18;
  char *v20;
  s64 *v21;
  u64 v22[3];

  v5 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v5);
  v6 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v6);
  next = sdfMemCB->headGuard->next;
  stat = next->stat;
  if (next->stat)
    goto LABEL_9;
  while (1)
  {
    ptr = next->ptr;
    v10 = *il2cp::SizeOf(next->next->ptr, s32);
    v12 = v10 - *il2cp::SizeOf(ptr, s32);
    if (v12 >= aSize)
      break;
    while (1)
    {
      next = next->next;
      stat = next->stat;
      if (!next->stat)
        break;
LABEL_9:
      if (stat == 2)
        return 0;
    }
  }
  if (v12 > aSize)
  {
    {
    }
    v14 = SizeOf_sdfMemRecord_t_(v6);
    v15 = sdfChipAllocDirect(v14);
    klass = v15->klass;
    if (v15->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfMemHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, sdfMemHandle_t, v22);
      if ((v22[0] & 1) != 0)
        v20 = v22[2];
      else
        v20 = v22 + 1;
      v21 = sub_8C4940(v20);
    }
    v15[1].klass = next;
    v15[1].monitor = next->next;
    v18 = v15;
    LODWORD(v22[0]) = *il2cp::SizeOf(next->ptr, s32) + aSize;
    v18[2].klass = sub_8D3950(s32, v22);
    LODWORD(v18[2].monitor) = 0;
    next->next->prev = v18;
    next->next = v18;
  }
  next->stat = 1;
  return next;
}

// 0x179a850
sdfMemHandle_t *sdfMemAlloc2Record(s32 aSize, char *aFile, s32 aLine) {
  u64 *v6;
  Il2CppObject *v7;
  u64 *v8;
  s32 v11;
  Il2CppObject *v12;
  Il2CppObject *v14;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v17;
  s64 *v18;
  struct sdfMemRecord_t_array *sdfMemRecordList;
  struct sdfMemRecord_t_array *v22;
  u64 v26[3];

  v6 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v6);
  v7 = Allocate(sdfMemRecord_t);
  v8 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v8);
  v7[1].monitor = v8;
  _ctor(v7, 0);
  if (v6)
  {
    {
    }
    v11 = SizeOf_sdfMemRecord_t_(v7);
    v12 = sdfChipAllocDirect(v11);
    v14 = v12;
    if (v12)
    {
      klass = v12->klass;
      if (v12->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfMemRecord_t)
      {
        sub_8FC2C0(klass->_1.element_class, sdfMemRecord_t, v26);
        if ((v26[0] & 1) != 0)
          v17 = v26[2];
        else
          v17 = v26 + 1;
        v18 = sub_8C4940(v17);
      }
    }
    else
    {
      if (!LODWORD(sdfMemRecordList->max_length))
        goto LABEL_22;
    }
    v14[1].klass = sdfMemRecordList->m_Items[0];
    v14[2].klass = aFile;
    LODWORD(v14[2].monitor) = aLine;
    v22 = sdfMemRecordList;
    v22->m_Items[0] = v14;
  }
  return v6;
}

// 0x1798b10
sdfMemHandle_t *sdfMemAllocDirect(s32 aSize) {
  struct sdfMemHandleCB_tag_o *sdfMemCB;
  u64 *v5;
  u64 *v6;
  struct sdfMemHandle_t_o *next;
  s32 stat;
  sdfMemory_sdfMemErrorHandlerDelegate_o *sdfMemErrorHandler;
  s64 ptr;
  s32 v14;
  s32 v15;
  s32 v17;
  Il2CppObject *v18;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppObject *v21;
  char *v23;
  s64 *v24;
  u64 v25[3];

  v5 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v5);
  v6 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v6);
  next = sdfMemCB->headGuard->next;
  stat = next->stat;
  if (next->stat)
    goto LABEL_9;
LABEL_17:
  ptr = next->ptr;
  v14 = *il2cp::SizeOf(next->next->ptr, s32);
  v15 = v14 - *il2cp::SizeOf(ptr, s32);
  if (v15 < aSize)
  {
    while (1)
    {
      while (1)
      {
        do
        {
          next = next->next;
          stat = next->stat;
          if (!next->stat)
            goto LABEL_17;
LABEL_9:
          ;
        }
        while (stat != 2);
          break;
        if (sdfMemErrorHandler)
          goto LABEL_13;
      }
      if (sdfMemErrorHandler)
      {
LABEL_13:
        Invoke(sdfMemErrorHandler, aSize);
      }
    }
  }
  if (v15 > aSize)
  {
    {
    }
    v17 = SizeOf_sdfMemRecord_t_(v6);
    v18 = sdfChipAllocDirect(v17);
    klass = v18->klass;
    if (v18->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfMemHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, sdfMemHandle_t, v25);
      if ((v25[0] & 1) != 0)
        v23 = v25[2];
      else
        v23 = v25 + 1;
      v24 = sub_8C4940(v23);
    }
    v18[1].klass = next;
    v18[1].monitor = next->next;
    v21 = v18;
    LODWORD(v25[0]) = *il2cp::SizeOf(next->ptr, s32) + aSize;
    v21[2].klass = sub_8D3950(s32, v25);
    LODWORD(v21[2].monitor) = 0;
    next->next->prev = v21;
    next->next = v21;
  }
  next->stat = 1;
  return next;
}

// 0x1799190
sdfMemHandle_t *sdfMemAllocFromTailDirect(s32 aSize) {
  struct sdfMemHandleCB_tag_o *sdfMemCB;
  u64 *v5;
  u64 *v6;
  struct sdfMemHandle_t_o *prev;
  s64 ptr;
  s32 v9;
  s32 v11;
  s32 v12;
  s32 v14;
  Il2CppObject *v15;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppObject *v18;
  char *v20;
  s64 *v21;
  u64 v22[3];

  v5 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v5);
  v6 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v6);
  prev = sdfMemCB->tailGuard->prev;
  if (!prev->stat)
    goto LABEL_8;
  do
  {
    do
      prev = prev->prev;
    while (prev->stat);
LABEL_8:
    ptr = prev->ptr;
    v9 = *il2cp::SizeOf(prev->next->ptr, s32);
    v11 = v9 - *il2cp::SizeOf(ptr, s32);
    v12 = v11 - aSize;
  }
  while (v11 < aSize);
  if (v11 > aSize)
  {
    {
    }
    v14 = SizeOf_sdfMemRecord_t_(v6);
    v15 = sdfChipAllocDirect(v14);
    klass = v15->klass;
    if (v15->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfMemHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, sdfMemHandle_t, v22);
      if ((v22[0] & 1) != 0)
        v20 = v22[2];
      else
        v20 = v22 + 1;
      v21 = sub_8C4940(v20);
    }
    v15[1].klass = prev;
    v15[1].monitor = prev->next;
    v18 = v15;
    LODWORD(v22[0]) = v12 + *il2cp::SizeOf(prev->ptr, s32);
    v18[2].klass = sub_8D3950(s32, v22);
    LODWORD(v18[2].monitor) = 0;
    prev->next->prev = v18;
    prev->next = v18;
  }
  prev->stat = 1;
  return prev;
}

// 0x179a5b0
sdfMemHandle_t *sdfMemAllocFromTailRecord(s32 aSize, char *aFile, s32 aLine) {
  u64 *v6;
  Il2CppObject *v7;
  u64 *v8;
  s32 v11;
  Il2CppObject *v12;
  Il2CppObject *v14;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v17;
  s64 *v18;
  struct sdfMemRecord_t_array *sdfMemRecordList;
  struct sdfMemRecord_t_array *v22;
  u64 v26[3];

  v6 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v6);
  v7 = Allocate(sdfMemRecord_t);
  v8 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v8);
  v7[1].monitor = v8;
  _ctor(v7, 0);
  {
  }
  v11 = SizeOf_sdfMemRecord_t_(v7);
  v12 = sdfChipAllocDirect(v11);
  v14 = v12;
  if (v12)
  {
    klass = v12->klass;
    if (v12->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfMemRecord_t)
    {
      sub_8FC2C0(klass->_1.element_class, sdfMemRecord_t, v26);
      if ((v26[0] & 1) != 0)
        v17 = v26[2];
      else
        v17 = v26 + 1;
      v18 = sub_8C4940(v17);
    }
  }
  else
  {
    if (!LODWORD(sdfMemRecordList->max_length))
      goto LABEL_21;
  }
  v14[1].klass = sdfMemRecordList->m_Items[0];
  v14[2].klass = aFile;
  LODWORD(v14[2].monitor) = aLine;
  v22 = sdfMemRecordList;
  v22->m_Items[0] = v14;
  return v6;
}

// 0x179a310
sdfMemHandle_t *sdfMemAllocRecord(s32 aSize, char *aFile, s32 aLine) {
  u64 *v6;
  Il2CppObject *v7;
  u64 *v8;
  s32 v11;
  Il2CppObject *v12;
  Il2CppObject *v14;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v17;
  s64 *v18;
  struct sdfMemRecord_t_array *sdfMemRecordList;
  struct sdfMemRecord_t_array *v22;
  u64 v26[3];

  v6 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v6);
  v7 = Allocate(sdfMemRecord_t);
  v8 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v8);
  v7[1].monitor = v8;
  _ctor(v7, 0);
  {
  }
  v11 = SizeOf_sdfMemRecord_t_(v7);
  v12 = sdfChipAllocDirect(v11);
  v14 = v12;
  if (v12)
  {
    klass = v12->klass;
    if (v12->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfMemRecord_t)
    {
      sub_8FC2C0(klass->_1.element_class, sdfMemRecord_t, v26);
      if ((v26[0] & 1) != 0)
        v17 = v26[2];
      else
        v17 = v26 + 1;
      v18 = sub_8C4940(v17);
    }
  }
  else
  {
    if (!LODWORD(sdfMemRecordList->max_length))
      goto LABEL_21;
  }
  v14[1].klass = sdfMemRecordList->m_Items[0];
  v14[2].klass = aFile;
  LODWORD(v14[2].monitor) = aLine;
  v22 = sdfMemRecordList;
  v22->m_Items[0] = v14;
  return v6;
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
LABEL_6:
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
        goto LABEL_6;
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

LABEL_7:
  v5 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v5);
  next = sdfMemCB->headGuard->next;
  if (next->stat == 1)
    goto LABEL_12;
  do
  {
    do
      next = next->next;
    while (next->stat != 1);
LABEL_12:
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
    goto LABEL_8;
  do
  {
    do
      result = result->next;
    while (result->stat != 1);
LABEL_8:
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
  struct sdfMemHandleCB_tag_o *sdfMemCB;
  u64 *v5;
  s32 v8;
  Il2CppObject *v9;
  Il2CppObject *v10;
  struct sdfMemHandle_tag_o *tailGuard;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v14;
  s64 *v15;
  u64 v16[3];
  u32 v17;

  v5 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v5);
  sdfMemCB->allocSize = aSize;
  {
  }
  v8 = SizeOf_sdfMemRecord_t_(v5);
  v9 = sdfChipAllocDirect(v8);
  sdfMemCB->headGuard->prev = 0;
  sdfMemCB->headGuard->stat = 2;
  sdfMemCB->headGuard->mlock = -1;
  sdfMemCB->tailGuard->next = 0;
  v10 = v9;
  tailGuard = sdfMemCB->tailGuard;
  v17 = (*il2cp::SizeOf(sdfMemCB->allocPtr, s32) + aSize) & 0xFFFFFF80;
  tailGuard->ptr = sub_8D3950(s32, &v17);
  sdfMemCB->tailGuard->stat = 2;
  sdfMemCB->tailGuard->mlock = -1;
  klass = v10->klass;
  if (v10->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfMemHandle_t)
  {
    sub_8FC2C0(klass->_1.element_class, sdfMemHandle_t, v16);
    if ((v16[0] & 1) != 0)
      v14 = v16[2];
    else
      v14 = v16 + 1;
    v15 = sub_8C4940(v14);
  }
  v10[1].klass = sdfMemCB->headGuard;
  v10[1].monitor = sdfMemCB->tailGuard;
  v10[2].klass = sdfMemCB->headGuard->ptr;
  LODWORD(v10[2].monitor) = 0;
  sdfMemErrorHandler = 0;
}

// 0x179a020
void *sdfMemLock(sdfMemHandle_t *aHandle) {
  ++aHandle->mlock;
  return aHandle->ptr;
}

// 0x179ab00
void sdfMemPurgeRecord(sdfMemHandle_t *aHandle, char *aFile, s32 aLine) {
  Il2CppObject *v5;
  u64 *v6;
  struct sdfMemRecord_t_array *sdfMemRecordList;
  sdfMemRecord_t_o **m_Items;
  sdfMemRecord_t_o *v11;

  v5 = Allocate(sdfMemRecord_t);
  v6 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v6);
  v5[1].monitor = v6;
  _ctor(v5, 0);
  else
  {
    if (!LODWORD(sdfMemRecordList->max_length))
      goto LABEL_8;
  }
  m_Items = sdfMemRecordList->m_Items;
  while (1)
  {
    v11 = *m_Items;
    if (!*m_Items)
      break;
    m_Items = &v11->next;
    if (v11->handle == aHandle)
    {
      sdfChipFreeDirect(v11);
      return;
    }
  }
}

// 0x1799660
void sdfMemReallocRecord(sdfMemHandle_t *aHandle, s32 aSize, char *aFile, s32 aLine) {
  u64 *v7;
  u64 *v8;
  struct sdfMemRecord_t_array *sdfMemRecordList;
  sdfMemRecord_t_o **m_Items;
  sdfMemRecord_t_o *v13;
  sdfMemHandle_t_o *handle;
  Il2CppObject *ptr;
  s32 v16;
  s32 v18;
  struct sdfMemHandle_t_o *next;
  s64 v20;
  s32 v21;
  u32 *v22;
  s32 v24;
  s32 v26;
  Il2CppObject *v27;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppObject *v30;
  sdfMemHandle_t_o *v31;
  struct sdfMemHandle_t_o *prev;
  struct sdfMemHandle_t_o *v34;
  Il2CppObject *v35;
  char *v36;
  s64 *v37;
  u64 v38[3];

  v7 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v7);
  v8 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v8);
LABEL_7:
  else
  {
    if (!LODWORD(sdfMemRecordList->max_length))
      goto LABEL_10;
  }
  m_Items = sdfMemRecordList->m_Items;
  do
  {
    v13 = *m_Items;
    handle = v13->handle;
    m_Items = &v13->next;
  }
  while (handle != aHandle);
  ptr = aHandle->ptr;
  v16 = *il2cp::SizeOf(aHandle->next->ptr, s32);
  v18 = v16 - *il2cp::SizeOf(ptr, s32);
  if (v18 != aSize)
  {
    next = aHandle->next;
    if (v18 >= aSize)
    {
      if (!next->stat)
        goto LABEL_36;
      {
      }
      v26 = SizeOf_sdfMemRecord_t_(v7);
      v27 = sdfChipAllocDirect(v26);
      klass = v27->klass;
      if (v27->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfMemHandle_t)
      {
        sub_8FC2C0(klass->_1.element_class, sdfMemHandle_t, v38);
        if ((v38[0] & 1) != 0)
          v36 = v38[2];
        else
          v36 = v38 + 1;
        v37 = sub_8C4940(v36);
      }
      v27[1].klass = aHandle;
      v27[1].monitor = next;
      v30 = v27;
      LODWORD(v38[0]) = *il2cp::SizeOf(aHandle->ptr, s32) + aSize;
      v30[2].klass = sub_8D3950(s32, v38);
      LODWORD(v30[2].monitor) = 0;
      next->prev = v30;
      aHandle->next = v30;
    }
    else
    {
      v20 = next->ptr;
      v21 = *il2cp::SizeOf(next->next->ptr, s32);
      v22 = il2cp::SizeOf(v20, s32);
      if (!next->stat)
      {
        v24 = v21 - *v22 + v18;
        if (v24 >= aSize)
        {
          if (v24 == aSize)
          {
            next->next->prev = aHandle;
            aHandle->next = next->next;
            sdfChipFreeDirect(next);
            return;
          }
LABEL_36:
          LODWORD(v38[0]) = *il2cp::SizeOf(aHandle->ptr, s32) + aSize;
          next->ptr = sub_8D3950(s32, v38);
          return;
        }
      }
      v31 = Allocate(sdfMemHandle_t);
      sdfMemHandle_t___ctor(v31);
      prev = v31->prev;
      v31->ptr = aHandle->ptr;
      v34 = aHandle->prev;
      aHandle->prev = prev;
      aHandle->next = v31->next;
      v31->prev = v34;
      v31->next = next;
      v35 = aHandle->ptr;
      aHandle->ptr = v31->ptr;
      v31->ptr = v35;
      aHandle->prev->next = aHandle;
      aHandle->next->prev = aHandle;
      v31->prev->next = v31;
      v31->next->prev = v31;
      sdfMemFreeDirect(v31);
    }
  }
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
  struct sdfMemRecord_t_array *sdfMemRecordList;
  s64 m_Items;
  sdfMemRecord_t_o *result;
  sdfMemHandle_t_o *v9;

  else
  {
    if (!LODWORD(sdfMemRecordList->max_length))
      goto LABEL_6;
  }
  m_Items = sdfMemRecordList->m_Items;
  do
  {
    result = *m_Items;
    v9 = *(*m_Items + 24LL);
    m_Items = *m_Items + 16LL;
  }
  while (v9 != aHandle);
  return result;
}

// 0x179a040
void sdfMemUnlock(sdfMemHandle_t *aHandle) {
  if (aHandle->mlock)
    --aHandle->mlock;
}
