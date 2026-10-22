#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ModelRangeBasicWorkData_t dds3ModelRangeBasicWorkData_t;

dds3Basic_t *dds3AddSceneBasicData(u32 type);
dds3Basic_t *dds3GetControlScene(void);
void dds3ModelRangeBasicWorkData_t__Clear(dds3ModelRangeBasicWorkData_t *this);
dds3Basic_t *dds3SearchSceneBasic(dds3Basic_t **pBasic, u32 serialID, u32 type);

// 0x14eb420
s32 ModelRangeBasicConstructor(dds3Basic_t *pBasic) {
  u64 *v3;
  u64 v4;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v9[3];

  v3 = Allocate(dds3ModelRangeBasicWorkData_t);
  dds3ModelRangeBasicWorkData_t___ctor(v3);
  pBasic->workdata = v3;
  if (v3)
  {
    v4 = *v3;
    if (*(*v3 + 288) < typeHierarchyDepth
      || *(*(v4 + 200) + 8 * typeHierarchyDepth - 8) != dds3ModelRangeBasicWorkData_t)
    {
      sub_8FC2C0(*(v4 + 64), dds3ModelRangeBasicWorkData_t, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  dds3ModelRangeBasicWorkData_t__Clear(v3);
  return 1;
}

// 0x14eb540
s32 ModelRangeBasicDestructor(dds3Basic_t *pBasic) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v9[3];

  workdata = pBasic->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelRangeBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelRangeBasicWorkData_t, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  return 0;
}

// 0x14eb630
dds3Basic_t *dds3AddModelRangeBasicNew(u32 serialID, void *pData, sdfVector4_t pos, char *pName) {
  dds3Basic_t_o *result;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  u64 v13[3];

  result = dds3AddSceneBasicData(0xBu, pData);
  workdata = result->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelRangeBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3ModelRangeBasicWorkData_t, v13);
    if ((v13[0] & 1) != 0)
      v11 = v13[2];
    else
      v11 = v13 + 1;
    v12 = sub_8C4940(v11);
  }
  LODWORD(workdata[3].monitor) = 0;
  result->serialID = serialID;
  result->name = pName;
  return result;
}

// 0x14eb850
s32 dds3ModelRangeBasicGetBlockID(s32 resID) {
  s32 *workdata;
  s64 v6;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  dds3Basic_t_o *ControlScene;
  u64 v12[3];

  ControlScene = 0;
  ControlScene = dds3GetControlScene();
  workdata = dds3SearchSceneBasic(&ControlScene, resID, 6u)->workdata;
  v6 = *workdata;
  if (*(*workdata + 288LL) < typeHierarchyDepth
    || *(*(v6 + 200) + 8 * typeHierarchyDepth - 8) != dds3ModelRangeBasicWorkData_t)
  {
    sub_8FC2C0(*(v6 + 64), dds3ModelRangeBasicWorkData_t, v12);
    if ((v12[0] & 1) != 0)
      v9 = v12[2];
    else
      v9 = v12 + 1;
    v10 = sub_8C4940(v9);
  }
  return workdata[14];
}

// 0x14eb750
void dds3ModelRangeBasicSetBlockID(dds3Basic_t **aPtr, s32 blockID) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  workdata = (*aPtr)->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelRangeBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3ModelRangeBasicWorkData_t, v10);
    if ((v10[0] & 1) != 0)
      v8 = v10[2];
    else
      v8 = v10 + 1;
    v9 = sub_8C4940(v8);
  }
  LODWORD(workdata[3].monitor) = blockID;
}
