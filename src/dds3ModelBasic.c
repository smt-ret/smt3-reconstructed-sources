#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ModelBasicWorkData_t dds3ModelBasicWorkData_t;
typedef struct sdfModelDef_t sdfModelDef_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;
typedef struct sdfModelTexList_t sdfModelTexList_t;
typedef struct sdfMotionCtrlr_t sdfMotionCtrlr_t;
typedef struct sdfMotionPlayBook_t sdfMotionPlayBook_t;

dds3Basic_t *dds3AddSceneBasicData(u32 type);
void dds3ModelBasicWorkData_t__Clear(dds3ModelBasicWorkData_t *this);

// 0x14eaef0
s32 ModelBasicConstructor(dds3Basic_t *pBasic) {
  u64 *v3;

  v3 = Allocate(dds3ModelBasicWorkData_t);
  dds3ModelBasicWorkData_t___ctor(v3);
  pBasic->workdata = v3;
  dds3ModelBasicWorkData_t__Clear(v3);
  return 1;
}

// 0x14eaf60
s32 ModelBasicDestructor(dds3Basic_t *pBasic) {
  return 0;
}

// 0x14eaf70
dds3Basic_t *dds3AddModelBasic(u32 serialID, sdfModelDef_t *pModelDef, sdfMotionPlayBook_t *pMotDef, dds3Basic_t *pTextureBasic, char *pName) {
  dds3Basic_t_o *result;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v15;
  s64 *v16;
  u64 v17[3];

  result = dds3AddSceneBasicData(0xAu, pModelDef);
  workdata = result->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelBasicWorkData_t, v17);
      if ((v17[0] & 1) != 0)
        v15 = v17[2];
      else
        v15 = v17 + 1;
      v16 = sub_8C4940(v15);
    }
  }
  result->serialID = serialID;
  result->name = pName;
  workdata[2].klass = pMotDef;
  workdata[2].monitor = 0;
  workdata[1].klass = pTextureBasic;
  workdata[1].monitor = pModelDef;
  return result;
}

// 0x14eb0c0
dds3Basic_t *dds3AddModelBasic2(u32 serialID, sdfModelDef_t *pModelDef, sdfMotionPlayBook_t *pMotDef, sdfModelTexList_t *pTexList, char *pName) {
  dds3Basic_t_o *result;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v15;
  s64 *v16;
  u64 v17[3];

  result = dds3AddSceneBasicData(0xAu, pModelDef);
  workdata = result->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelBasicWorkData_t, v17);
      if ((v17[0] & 1) != 0)
        v15 = v17[2];
      else
        v15 = v17 + 1;
      v16 = sub_8C4940(v15);
    }
  }
  result->serialID = serialID;
  result->name = pName;
  workdata[2].klass = pMotDef;
  workdata[2].monitor = pTexList;
  workdata[1].monitor = pModelDef;
  return result;
}

// 0x14eb320
sdfMotionCtrlr_t *dds3ModelBasicMakeMotion(dds3Basic_t **pBasic, sdfModelRootNode_t *pRootNode) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v11[3];

  if (pRootNode)
  {
    workdata = (*pBasic)->workdata;
    if (workdata)
    {
      klass = workdata->klass;
      if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelBasicWorkData_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3ModelBasicWorkData_t, v11);
        if ((v11[0] & 1) != 0)
          v8 = v11[2];
        else
          v8 = v11 + 1;
        v9 = sub_8C4940(v8);
      }
    }
  }
  return 0;
}

// 0x14eb210
sdfModelRootNode_t *dds3ModelBasicMakeRootNode(dds3Basic_t **pBasic) {
  u64 *v3;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v10[3];

  v3 = Allocate(sdfModelRootNode_t);
  sdfModelRootNode_t___ctor(v3);
  workdata = (*pBasic)->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelBasicWorkData_t, v10);
      if ((v10[0] & 1) != 0)
        v7 = v10[2];
      else
        v7 = v10 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  return v3;
}
