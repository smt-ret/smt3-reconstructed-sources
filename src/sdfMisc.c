#include "types.h"

typedef struct sdfItemArray_t sdfItemArray_t;
typedef struct sdfMatList_t sdfMatList_t;
typedef struct sdfModelNodeList_t sdfModelNodeList_t;
typedef struct sdfMotionNodeList_t sdfMotionNodeList_t;

void sdfItemArraySetCapacity_sdfModelNodeList(sdfModelNodeList_t *aArray, s32 aCapa);

// 0x179b250
s32 sdfBCDtoDEC(s32 aBCD) {
  s32 v2;
  s32 result;
  s32 v4;
  bool v5;

  if (aBCD < 1)
    return 0;
  v2 = aBCD;
  result = 0;
  v4 = 1;
  do
  {
    result += (v2 & 0xF) * v4;
    v4 *= 10;
    v5 = v2 <= 15;
    v2 >>= 4;
  }
  while (!v5);
  return result;
}

// 0x179b290
s32 sdfDECtoBCD(s32 aDec) {
  s32 v2;
  s32 result;
  s32 v4;
  char v5;
  bool v6;

  if (aDec < 1)
    return 0;
  v2 = aDec;
  result = 0;
  v4 = 0;
  do
  {
    v5 = v4 & 0x1C;
    v4 += 4;
    result |= (v2 % 10) << v5;
    v6 = v2 <= 9;
    v2 /= 10;
  }
  while (!v6);
  return result;
}

// 0x179b1c0
void *sdfFillZero128(void *p, s32 l) {
  return p;
}

// 0x179b4f0
void sdfItemArrayFree(sdfItemArray_t *aArray) {
  ;
}

// 0x179b500
void sdfItemArrayGrow(sdfItemArray_t *aArray) {
  s32 growStep;

  if (!aArray->memHandle)
  {
    growStep = aArray->growStep;
    if (growStep >= 1)
      aArray->capacity = growStep;
  }
}

// 0x179b570
void sdfItemArrayGrow_sdfModelNodeList(sdfModelNodeList_t *aArray) {
  s16 v4;
  struct sdfModelNode_t_array *v5;
  u32 *items;
  u64 v7;
  u64 *v8;
  u32 *v10;

  if (aArray->memHandle)
  {
    v4 = aArray->growStep + aArray->capacity;
    aArray->capacity = v4;
    v5 = NewSpecific(sdfModelNode_t, v4 & 0xFFFFFFFFLL);
    aArray->items = v5;
    if (aArray->capacity >= 1)
    {
      items = v5;
      v7 = 0;
      while (1)
      {
        v8 = Allocate(sdfModelNode_t);
        sdfModelNode_t___ctor(v8);
        v10 = &items[2 * v7++];
        *(v10 + 4) = v8;
        if (v7 >= aArray->capacity)
          break;
        items = aArray->items;
      }
    }
  }
  else
  {
    sdfItemArraySetCapacity_sdfModelNodeList(aArray, aArray->growStep);
  }
}

// 0x179b2f0
sdfItemArray_t *sdfItemArrayNew(s32 aInitCapa, s32 aElemSize, s32 aGrowStep) {
  s16 v4;
  s16 v5;
  sdfItemArray_t_o *v7;

  v4 = aGrowStep;
  v5 = aElemSize;
  v7 = Allocate(sdfItemArray_t);
  sdfItemArray_t___ctor(v7);
  v7->count = 0;
  v7->capacity = aInitCapa;
  v7->growStep = v4;
  v7->elemSize = v5;
  if (aInitCapa)
  {
    v7->items = NewSpecific(s32, aInitCapa);
  }
  else
  {
    v7->memHandle = 0;
    v7->items = 0;
  }
  return v7;
}

// 0x17947b0
sdfMatList_t *sdfItemArrayNew_sdfMatList(s32 aInitCapa, s32 aElemSize, s32 aGrowStep) {
  s16 v4;
  s16 v5;
  sdfMatList_t_o *v7;

  v4 = aGrowStep;
  v5 = aElemSize;
  v7 = Allocate(sdfMatList_t);
  sdfMatList_t___ctor(v7);
  v7->count = 0;
  v7->capacity = aInitCapa;
  v7->growStep = v4;
  v7->elemSize = v5;
  if (aInitCapa)
  {
    v7->items = NewSpecific(sdfMat_t, aInitCapa);
  }
  else
  {
    v7->memHandle = 0;
    v7->items = 0;
  }
  return v7;
}

// 0x179b3a0
sdfModelNodeList_t *sdfItemArrayNew_sdfModelNodeList(s32 aInitCapa, s32 aElemSize, s32 aGrowStep) {
  s16 v4;
  s16 v5;
  sdfModelNodeList_t_o *v7;

  v4 = aGrowStep;
  v5 = aElemSize;
  v7 = Allocate(sdfModelNodeList_t);
  sdfModelNodeList_t___ctor(v7);
  v7->count = 0;
  v7->capacity = aInitCapa;
  v7->growStep = v4;
  v7->elemSize = v5;
  if (aInitCapa)
  {
    v7->items = NewSpecific(sdfModelNode_t, aInitCapa);
  }
  else
  {
    v7->memHandle = 0;
    v7->items = 0;
  }
  return v7;
}

// 0x179b450
sdfMotionNodeList_t *sdfItemArrayNew_sdfMotionNodeList(s32 aInitCapa, s32 aGrowStep) {
  s16 v3;
  sdfMotionNodeList_t_o *v5;

  v3 = aGrowStep;
  v5 = Allocate(sdfMotionNodeList_t);
  sdfMotionNodeList_t___ctor(v5);
  v5->count = 0;
  v5->capacity = aInitCapa;
  v5->growStep = v3;
  if (aInitCapa)
  {
    v5->items = NewSpecific(sdfMotionNode_t, aInitCapa);
  }
  else
  {
    v5->memHandle = 0;
    v5->items = 0;
  }
  return v5;
}

// 0x179b520
void sdfItemArraySetCapacity(sdfItemArray_t *aArray, s32 aCapa) {
  if (aArray->memHandle)
  {
    if (aCapa <= 0)
    {
      aArray->memHandle = 0;
      *&aArray->count = 0;
      aArray->items = 0;
    }
    else if (aArray->count > aCapa)
    {
      aArray->count = aCapa;
    }
  }
  else if (aCapa >= 1)
  {
    aArray->capacity = aCapa;
  }
}

// 0x179b6c0
void sdfItemArraySetCapacity_sdfModelNodeList(sdfModelNodeList_t *aArray, s32 aCapa) {
  struct sdfModelNode_t_array *v5;
  u32 *items;
  u64 i;
  u64 *v8;
  s64 v11;
  struct sdfModelNode_t_array *v12;
  u32 *v13;
  u64 v14;
  s64 v15;
  u64 *v16;

  if (aArray->memHandle)
  {
    if (aCapa <= 0)
    {
      aArray->memHandle = 0;
      *&aArray->count = 0;
      aArray->items = 0;
    }
    else
    {
      aArray->capacity = aCapa;
      v5 = NewSpecific(sdfModelNode_t, aCapa);
      aArray->items = v5;
      items = v5;
      for (i = 0; ; ++i)
      {
        v8 = Allocate(sdfModelNode_t);
        sdfModelNode_t___ctor(v8);
        *&items[2 * i + 8] = v8;
        if (aCapa - 1LL == i)
          break;
        items = aArray->items;
      }
      if (aArray->count > aCapa)
        aArray->count = aCapa;
    }
  }
  else if (aCapa >= 1)
  {
    aArray->capacity = aCapa;
    v11 = aCapa;
    v12 = NewSpecific(sdfModelNode_t, aCapa);
    aArray->items = v12;
    v13 = v12;
    v14 = 0;
    v15 = v11 - 1;
    while (1)
    {
      v16 = Allocate(sdfModelNode_t);
      sdfModelNode_t___ctor(v16);
      *&v13[2 * v14 + 8] = v16;
      if (v15 == v14)
        break;
      v13 = aArray->items;
      ++v14;
    }
  }
}

// 0x179b1d0
char *sdfStrDup(char *str) {
  System_String_o *v3;

  if (!str)
    return 0;
  v3 = "";
  get_Length(str);
  return v3;
}

// 0x179b140
void sdfZeroMemory(void *aPtr, s32 aLeng) {
  if (aLeng >= 1)
    il2cp::SizeOf(aPtr, s32);
}
