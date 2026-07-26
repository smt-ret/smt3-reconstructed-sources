#include "types.h"

typedef struct dds3BasicArrayHandle_t dds3BasicArrayHandle_t;
typedef struct dds3Basic_t dds3Basic_t;

static dds3Basic_t *dds3TheWorld;

dds3Basic_t *dds3AddBasic(u32 type);
s32 dds3AddBasicArray(dds3BasicArrayHandle_t **hndl, s32 bufcnt);
s32 dds3CallDrawProcuder(dds3Basic_t **basic);
s32 dds3CallMainProcuder(dds3Basic_t **basic);
void dds3DeleteAllBasicArray(dds3BasicArrayHandle_t **hndl);
void dds3DeleteBasic(dds3Basic_t **basic);
void dds3DeleteBasicArray(dds3BasicArrayHandle_t **hndl);
void dds3DeleteScene(dds3Basic_t **scene);
void dds3FreeBasicArrayHandle(dds3BasicArrayHandle_t **hndl);
dds3Basic_t *dds3GetBasicArray(dds3BasicArrayHandle_t **hndl);
s32 dds3SetNextBasicArray(dds3BasicArrayHandle_t **hndl);
s32 dds3SetSearchNextBasicArray(dds3BasicArrayHandle_t **hArray, dds3Basic_t **pBasic);

// 0x180f3c0
s32 dds3AddBasicArray(dds3BasicArrayHandle_t **hndl, s32 bufcnt) {
    return 0;
}

// 0x180f010
dds3Basic_t *dds3AddScene(void) {
    dds3AddBasic(0);
    return 0;
}

// 0x180e6f0
dds3Basic_t *dds3AddWorld(s32 bufcnt) {
    dds3AddBasic(0);
    return 0;
}

// 0x1810490
s32 dds3CallbackBasicArray(dds3BasicArrayHandle_t **hndl, void *func) {
  dds3BasicArrayHandle_t_o *v5;
  Il2CppObject *BasicArray;
  s32 result;

  if (!func)
    return 1;
  v5 = *hndl;
  if (!*hndl)
    return 1;
  if (!v5->count)
    return 1;
  v5->nowindex = v5->firstindex;
  if ((*hndl)->nowindex < 0)
    return 1;
  while (1)
  {
    BasicArray = dds3GetBasicArray(hndl, func);
    result = int___Invoke(func, BasicArray);
    if (!result)
      break;
    else if (!dds3SetNextBasicArray(hndl))
    {
      return 1;
    }
  }
  return result;
}

// 0x180f700
void dds3DeleteAllBasicArray(dds3BasicArrayHandle_t **hndl) {
}

// 0x180f9b0
void dds3DeleteBasicArray(dds3BasicArrayHandle_t **hndl) {
}

// 0x180e0f0
void dds3DeleteScene(dds3Basic_t **scene) {
    dds3DeleteBasic(0);
}

// 0x180ea10
void dds3DeleteWorld(void) {
  if (dds3TheWorld)
  {
    dds3DeleteBasic(&dds3TheWorld);
    dds3TheWorld = 0;
  }
}

// 0x180e300
void dds3FreeBasicArrayHandle(dds3BasicArrayHandle_t **hndl) {
    dds3DeleteAllBasicArray(0);
}

// 0x180ec20
dds3Basic_t *dds3GetActiveScene(void) {
    return 0;
}

// 0x1810010
dds3Basic_t *dds3GetBasicArray(dds3BasicArrayHandle_t **hndl) {
    return 0;
}

// 0x180ff00
s32 dds3GetBasicArrayCount(dds3BasicArrayHandle_t **hndl) {
  if (*hndl)
    return (*hndl)->count;
  else
    return 0;
}

// 0x180f1c0
dds3BasicArrayHandle_t *dds3GetBasicArrayHandle(s32 bufcnt) {
    dds3AddBasicArray(0, 0);
    return 0;
}

// 0x180eec0
dds3Basic_t *dds3GetControlScene(void) {
    return 0;
}

// 0x180fd70
s32 dds3SearchDeleteBasicArray(dds3BasicArrayHandle_t **hArray, dds3Basic_t **pBasic, u32 mode) {
  dds3BasicArrayHandle_t_o *v7;
  s32 v8;

  else
  {
    v7 = *hArray;
    if (!*hArray)
      return 0;
  }
  if (!v7->count)
    return 0;
  v7->nowindex = v7->firstindex;
  if (!mode)
  {
    if (dds3SetSearchNextBasicArray(hArray, pBasic, *&mode) == 1)
    {
      dds3DeleteBasicArray(hArray);
      return 1;
    }
    return 0;
  }
  v8 = 0;
  while (dds3SetSearchNextBasicArray(hArray, pBasic, *&mode) == 1)
  {
    dds3DeleteBasicArray(hArray);
    v8 = 1;
  }
  return v8;
}

// 0x180ead0
void dds3SetActiveScene(dds3Basic_t *scene) {
}

// 0x1810310
s32 dds3SetBasicArray(dds3BasicArrayHandle_t **hndl, dds3Basic_t **data) {
    return 0;
}

// 0x180ed70
void dds3SetControlScene(dds3Basic_t **scene) {
}

// 0x180ff20
s32 dds3SetFirstBasicArray(dds3BasicArrayHandle_t **hndl) {
  (*hndl)->nowindex = (*hndl)->firstindex;
  return ((*hndl)->nowindex >> 15) ^ 1;
}

// 0x1810190
s32 dds3SetNextBasicArray(dds3BasicArrayHandle_t **hndl) {
    return 0;
}

// 0x180ff40
s32 dds3SetSearchNextBasicArray(dds3BasicArrayHandle_t **hArray, dds3Basic_t **pBasic) {
  dds3Basic_t_o *BasicArray;

  while (1)
  {
    BasicArray = dds3GetBasicArray(hArray, pBasic);
    if (!BasicArray)
      break;
    if (*pBasic == BasicArray)
    {
      LODWORD(BasicArray) = 1;
      return BasicArray;
    }
    else
    {
      LODWORD(BasicArray) = dds3SetNextBasicArray(hArray);
      if (!BasicArray)
        return BasicArray;
    }
  }
  return BasicArray;
}

// 0x180ded0
s32 worldconstructor(dds3Basic_t *basic) {
  u64 *v3;

  v3 = Allocate(dds3WorldBasic_t);
  dds3WorldBasic_t___ctor(v3);
  if (!v3)
    return 0;
  v3[8] = 0xFFFFFFFF0000LL;
  v3[6] = 0;
  v3[7] = 0;
  v3[4] = 0;
  v3[5] = 0;
  v3[2] = 0;
  v3[3] = 0;
  v3[9] = 0;
  v3[10] = 0;
  basic->workdata = v3;
  return 1;
}

// 0x180df60
s32 worlddestructor(dds3Basic_t *basic) {
    dds3DeleteScene(0);
    dds3FreeBasicArrayHandle(0);
    return 0;
}

// 0x180e5d0
s32 worlddrawprocuder(dds3Basic_t *basic) {
    dds3CallDrawProcuder(0);
    return 0;
}

// 0x180e4b0
s32 worldmainprocuder(dds3Basic_t *basic) {
    dds3CallMainProcuder(0);
    return 0;
}
