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
  dds3AreaBasicWorkData_t_o *v3;
  dds3AreaBasicWorkData_t_c *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  struct dds3BasicArrayHandle_t_array *v8;
  struct dds3BasicArrayHandle_t_array *v9;
  u64 *v10;
  struct dds3BasicArrayHandle_t_array *hBasicArray;
  s64 *BasicArrayHandle;
  s64 *v15;
  struct dds3BasicArrayHandle_t_array *v17;
  u64 *v18;
  struct dds3BasicArrayHandle_t_array *v21;
  s64 *v22;
  s64 *v23;
  u64 v30[3];

  v3 = Allocate(dds3AreaBasicWorkData_t);
  dds3AreaBasicWorkData_t___ctor(v3);
  pBasic->workdata = v3;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3AreaBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3AreaBasicWorkData_t, v30);
      if ((v30[0] & 1) != 0)
        v6 = v30[2];
      else
        v6 = v30 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = NewSpecific(dds3BasicArrayHandle_t, 2u);
  v3->hBasicArray = v8;
  v9 = v8;
  v10 = Allocate(dds3BasicArrayHandle_t);
  dds3BasicArrayHandle_t___ctor(v10);
  v9->m_Items[0] = v10;
  hBasicArray = v3->hBasicArray;
  BasicArrayHandle = dds3GetBasicArrayHandle(0);
  v15 = BasicArrayHandle;
  hBasicArray->m_Items[0] = v15;
  v17 = v3->hBasicArray;
  v18 = Allocate(dds3BasicArrayHandle_t);
  dds3BasicArrayHandle_t___ctor(v18);
  v17->m_Items[1] = v18;
  v21 = v3->hBasicArray;
  v22 = dds3GetBasicArrayHandle(0);
  v23 = v22;
  v21->m_Items[1] = v23;
  pBasic->workdata = v3;
  return 1;
}

// 0x15209d0
s32 AreaBasicDestructor(dds3Basic_t *pBasic) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppClass *v8;
  u64 *v9;
  Il2CppClass *v12;
  u64 *v13;
  Il2CppClass *v16;
  Il2CppClass *v19;
  u64 v22[3];

  workdata = pBasic->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3AreaBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3AreaBasicWorkData_t, v22);
      if ((v22[0] & 1) != 0)
        v6 = v22[2];
      else
        v6 = v22 + 1;
      v7 = sub_8C4940(v6);
    }
    v8 = workdata[1].klass;
    v9 = Allocate(System_Func_dds3Basic_t__int_);
    int____ctor(
      v9,
      0,
      Method_dds3AreaBasic_CB_ReleaseObjectBasic__);
    dds3CallbackBasicArray(&v8->_1.byval_arg, v9);
    v12 = workdata[1].klass;
    v13 = Allocate(System_Func_dds3Basic_t__int_);
    int____ctor(
      v13,
      0,
      Method_dds3AreaBasic_CB_ReleaseObjectBasic__);
    dds3CallbackBasicArray(&v12->_1.byval_arg.bits, v13);
    v16 = workdata[1].klass;
    dds3FreeBasicArrayHandle(&v16->_1.byval_arg);
    v19 = workdata[1].klass;
    dds3FreeBasicArrayHandle(&v19->_1.byval_arg.bits);
  }
  return 0;
}

// 0x1520c40
s32 AreaBasicDrawprocuder(dds3Basic_t *pBasic) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v6;
  u64 *v7;
  char *v11;
  s64 *v12;
  u64 v13[3];

  workdata = pBasic->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3AreaBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3AreaBasicWorkData_t, v13);
    if ((v13[0] & 1) != 0)
      v11 = v13[2];
    else
      v11 = v13 + 1;
    v12 = sub_8C4940(v11);
  }
  v6 = workdata[1].klass;
  v7 = Allocate(System_Func_dds3Basic_t__int_);
  int____ctor(
    v7,
    0,
    Method_dds3AreaBasic_CB_BasicDrawProcuder__);
  else if (!LODWORD(v6->_1.namespaze))
  {
    goto LABEL_8;
  }
  dds3CallbackBasicArray(&v6->_1.byval_arg, v7);
  return 1;
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
          goto LABEL_34;
      }
    }
    while (dds3SetNextBasicArray(&hndl));
  }
LABEL_34:
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
    v7 = &"エリアリストが見つかりません...\n";
    goto LABEL_26;
  }
  if (!dds3GetBasicArrayCount(&hndl))
  {
LABEL_22:
    v7 = &"not exist a area  エリアが見つかりません...\n";
LABEL_26:
    Write(*v7, 0);
    return 0;
  }
LABEL_13:
  dds3SetFirstBasicArray(&hndl);
  BasicArray = dds3GetBasicArray(&hndl);
  dds3FreeBasicArrayHandle(&hndl);
  return BasicArray;
}

// 0x1521050
dds3BasicArrayHandle_t *dds3AreaBasicGetItemArray(dds3Basic_t **pAreaBasic, u32 itemType) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v8;
  char *v11;
  s64 *v12;
  u64 v13[3];

  workdata = (*pAreaBasic)->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3AreaBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3AreaBasicWorkData_t, v13);
    if ((v13[0] & 1) != 0)
      v11 = v13[2];
    else
      v11 = v13 + 1;
    v12 = sub_8C4940(v11);
  }
  v8 = workdata[1].klass;
  return *(&v8->_1.byval_arg.data + itemType);
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
