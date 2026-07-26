#include "types.h"

typedef struct dds3BasicArrayHandle_t dds3BasicArrayHandle_t;
typedef struct dds3Basic_t dds3Basic_t;

s32 dds3AddBasicArray(dds3BasicArrayHandle_t **hndl, s32 bufcnt);
dds3Basic_t *dds3AddSceneBasicData(u32 type);
dds3BasicArrayHandle_t *dds3AreaBasicGetItemArray(dds3Basic_t **pAreaBasic, u32 itemType);
s32 dds3CallbackBasicArray(dds3BasicArrayHandle_t **hndl, void *func);
void dds3FreeBasicArrayHandle(dds3BasicArrayHandle_t **hndl);
dds3Basic_t *dds3GetBasicArray(dds3BasicArrayHandle_t **hndl);
s32 dds3GetBasicArrayCount(dds3BasicArrayHandle_t **hndl);
dds3BasicArrayHandle_t *dds3GetBasicArrayHandle(s32 bufcnt);
dds3Basic_t *dds3GetControlScene(void);
dds3Basic_t *dds3ObjectBaseSetControlBasicType(dds3Basic_t **pObjectBasic, dds3Basic_t **pItemBasic, u32 itemType);
dds3BasicArrayHandle_t *dds3SceneBasicGetList(dds3Basic_t **pBasic, u32 type);
s32 dds3SearchDeleteBasicArray(dds3BasicArrayHandle_t **hArray, dds3Basic_t **pBasic, u32 mode);
s32 dds3SetBasicArray(dds3BasicArrayHandle_t **hndl, dds3Basic_t **data);
s32 dds3SetFirstBasicArray(dds3BasicArrayHandle_t **hndl);
s32 dds3SetNextBasicArray(dds3BasicArrayHandle_t **hndl);
s32 dds3SetSearchNextBasicArray(dds3BasicArrayHandle_t **hArray, dds3Basic_t **pBasic);

// 0x15206b0
s32 AreaBasicConstructor(dds3Basic_t *pBasic) {
    dds3GetBasicArrayHandle(0);
    return 0;
}

// 0x15209d0
s32 AreaBasicDestructor(dds3Basic_t *pBasic) {
    dds3CallbackBasicArray(0, 0);
    dds3FreeBasicArrayHandle(0);
    return 0;
}

// 0x1520c40
s32 AreaBasicDrawprocuder(dds3Basic_t *pBasic) {
    dds3CallbackBasicArray(0, 0);
    return 0;
}

// 0x1520c30
s32 AreaBasicMainprocuder(dds3Basic_t *pBasic) {
  return 1;
}

// 0x1520e60
u32 BasicTypeToItemType(u32 type) {
  return (type & 0xFFFFFFFC) != 4 && type == 8;
}

// 0x1520db0
s32 CB_BasicDrawProcuder(dds3Basic_t *pBasic) {
  System_Func_object__int__o *drawprocuder;

  drawprocuder = pBasic->basicfunction->drawprocuder;
  if (drawprocuder)
    return int___Invoke(drawprocuder, pBasic);
  else
    return 1;
}

// 0x1520e20
s32 CB_ReleaseObjectBasic(dds3Basic_t *pBasic) {
  dds3Basic_t_o *v3;
  dds3Basic_t_o *pObjectBasic;

  v3 = 0;
  pObjectBasic = pBasic;
  dds3ObjectBaseSetControlBasicType(&pObjectBasic, &v3, 5u);
  return 1;
}

// 0x1520e80
dds3Basic_t *dds3AddAreaBasic(u32 serialID, char *pName) {
  dds3Basic_t_o *result;

  result = dds3AddSceneBasicData(2u);
  result->serialID = serialID;
  result->name = pName;
  return result;
}

// 0x1521260
dds3BasicArrayHandle_t *dds3AreaBasicArrangeGetItemArray(dds3Basic_t **pAreaBasic, u32 itemType, void *checkFunc, dds3Basic_t *pBasic) {
  u64 *v8;
  u64 *v9;
  dds3Basic_t_o *data;
  dds3BasicArrayHandle_t_o *BasicArrayHandle;
  dds3BasicArrayHandle_t_o *hndl;

  data = 0;
  v8 = Allocate(dds3BasicArrayHandle_t);
  dds3BasicArrayHandle_t___ctor(v8);
  v9 = Allocate(dds3BasicArrayHandle_t);
  dds3BasicArrayHandle_t___ctor(v9);
  BasicArrayHandle = v9;
  hndl = dds3AreaBasicGetItemArray(pAreaBasic, itemType);
  else if (!dds3GetBasicArrayCount(&hndl))
  {
    return 0;
  }
  BasicArrayHandle = dds3GetBasicArrayHandle(0);
  dds3SetFirstBasicArray(&hndl);
  if (checkFunc)
  {
    do
    {
      data = dds3GetBasicArray(&hndl);
      if (int___Invoke(checkFunc, data))
      {
        dds3AddBasicArray(&BasicArrayHandle, 1);
        dds3SetBasicArray(&BasicArrayHandle, &data);
      }
    }
    while (dds3SetNextBasicArray(&hndl));
  }
  else
  {
    do
    {
      while (1)
      {
        data = dds3GetBasicArray(&hndl);
        dds3AddBasicArray(&BasicArrayHandle, 1);
        dds3SetBasicArray(&BasicArrayHandle, &data);
          break;
        if (!dds3SetNextBasicArray(&hndl))
      }
    }
    while (dds3SetNextBasicArray(&hndl));
  }
  else if (dds3GetBasicArrayCount(&BasicArrayHandle))
  {
    return BasicArrayHandle;
  }
  dds3FreeBasicArrayHandle(&BasicArrayHandle);
  return 0;
}

// 0x1521530
dds3Basic_t *dds3AreaBasicGetFastArea(void) {
  u64 *v1;
  dds3Basic_t_o *BasicArray;
  s64 *v7;
  dds3Basic_t_o *ControlScene;
  dds3BasicArrayHandle_t_o *hndl;

  ControlScene = 0;
  v1 = Allocate(dds3BasicArrayHandle_t);
  dds3BasicArrayHandle_t___ctor(v1);
  hndl = v1;
  ControlScene = dds3GetControlScene();
  hndl = dds3SceneBasicGetList(&ControlScene, 2u);
  if (!hndl)
  {
    v7 = &StringLiteral_14648;
  }
  if (!dds3GetBasicArrayCount(&hndl))
  {
    v7 = &StringLiteral_14649;
    Write(*v7, 0);
    return 0;
  }
  dds3SetFirstBasicArray(&hndl);
  BasicArray = dds3GetBasicArray(&hndl);
  dds3FreeBasicArrayHandle(&hndl);
  return BasicArray;
}

// 0x1521050
dds3BasicArrayHandle_t *dds3AreaBasicGetItemArray(dds3Basic_t **pAreaBasic, u32 itemType) {
    return 0;
}

// 0x1520f00
void dds3AreaBasicRegistItem(dds3Basic_t **pAreaBasic, dds3Basic_t **pItemBasic) {
  u64 *v5;
  dds3Basic_t_o *v8;
  dds3BasicArrayHandle_t_o *hndl;

  v5 = Allocate(dds3BasicArrayHandle_t);
  dds3BasicArrayHandle_t___ctor(v5);
  hndl = v5;
  v8 = *pItemBasic;
  hndl = dds3AreaBasicGetItemArray(
           pAreaBasic,
           (HIBYTE(v8->type) == 8) & (v8->type >> 26 != 1));
  dds3SetFirstBasicArray(&hndl);
  if (dds3SetSearchNextBasicArray(&hndl, pItemBasic) != 1)
  {
    dds3AddBasicArray(&hndl, 1);
    dds3SetBasicArray(&hndl, pItemBasic);
  }
}

// 0x1521170
void dds3AreaBasicReleaseItem(dds3Basic_t **pAreaBasic, dds3Basic_t **pItemBasic) {
  u64 *v5;
  dds3Basic_t_o *v8;
  dds3BasicArrayHandle_t_o *hArray;

  v5 = Allocate(dds3BasicArrayHandle_t);
  dds3BasicArrayHandle_t___ctor(v5);
  hArray = v5;
  v8 = *pItemBasic;
  hArray = dds3AreaBasicGetItemArray(
             pAreaBasic,
             (HIBYTE(v8->type) == 8) & (v8->type >> 26 != 1));
  dds3SearchDeleteBasicArray(&hArray, pItemBasic, 0);
}
