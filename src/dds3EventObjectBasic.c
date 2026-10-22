#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ObjectBaseControlWorkData_t dds3ObjectBaseControlWorkData_t;
typedef struct dds3PoseSet_t dds3PoseSet_t;

dds3Basic_t *dds3AddSceneBasicData(u32 type);
void dds3BackupPoseSet(dds3PoseSet_t **pPoseSet);
s32 dds3CheckPoseSetFlag(dds3PoseSet_t **pPoseSet, u32 flag);
void dds3FreePoseSet(dds3Basic_t **basic);
s32 dds3InitPoseSet(dds3Basic_t **basic);
void dds3ObjectBaseFreeControlWorkData(dds3ObjectBaseControlWorkData_t **pControl);
dds3ObjectBaseControlWorkData_t *dds3ObjectBaseInitControlWorkData(dds3Basic_t **pObjectBasic);
void dds3OffPoseSetFlag(dds3PoseSet_t **pPoseSet, u32 flag);
void dds3SetPosPoseSet(dds3Basic_t **pBasic, sdfVector4_t pos);
void dds3SetRotPoseSet(dds3Basic_t **pBasic, sdfVector4_t rot);

// 0x17b3ea0
s32 EventObjectBasicConstructor(dds3Basic_t *pBasic) {
  dds3Basic_t_o *v2;
  u64 *v3;
  Il2CppObject *workdata;
  dds3ObjectBaseControlWorkData_t_o *inited;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  dds3Basic_t_o *v11[3];
  dds3Basic_t_o *basic;

  basic = pBasic;
  dds3InitPoseSet(&basic);
  v2 = basic;
  v3 = Allocate(dds3EventObjectBasicWorkData_t);
  dds3EventObjectBasicWorkData_t___ctor(v3);
  v2->workdata = v3;
  workdata = basic->workdata;
  inited = dds3ObjectBaseInitControlWorkData(&basic);
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EventObjectBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3EventObjectBasicWorkData_t, v11);
    if ((v11[0] & 1) != 0)
      v9 = v11[2];
    else
      v9 = v11 + 1;
    v10 = sub_8C4940(v9);
  }
  workdata[1].klass = inited;
  return 1;
}

// 0x17b3ff0
s32 EventObjectBasicDestructor(dds3Basic_t *pBasic) {
  dds3ObjectBaseControlWorkData_t_o **workdata;
  dds3ObjectBaseControlWorkData_t_o *v3;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  dds3Basic_t_o *v8[3];
  dds3Basic_t_o *basic;

  basic = pBasic;
  dds3FreePoseSet(&basic);
  workdata = basic->workdata;
  if (workdata)
  {
    v3 = *workdata;
    if (LOBYTE((*workdata)[2].MotMode) < typeHierarchyDepth
      || *(v3[1].sdwnodeidx + typeHierarchyDepth - 1) != dds3EventObjectBasicWorkData_t)
    {
      sub_8FC2C0(v3->pModelRangeRootNode, dds3EventObjectBasicWorkData_t, v8);
      if ((v8[0] & 1) != 0)
        v5 = v8[2];
      else
        v5 = v8 + 1;
      v6 = sub_8C4940(v5);
    }
    dds3ObjectBaseFreeControlWorkData(workdata + 2);
  }
  return 0;
}

// 0x17b4120
s32 EventObjectBasicMainProcuder(dds3Basic_t *pBasic) {
  dds3PoseSet_t_o *pPoseSet;

  pPoseSet = pBasic->poseset;
  if (dds3CheckPoseSetFlag(&pPoseSet, 1u) == 1)
  {
    dds3OffPoseSetFlag(&pPoseSet, 1u);
    dds3BackupPoseSet(&pPoseSet);
  }
  return 1;
}

// 0x17b41e0
dds3Basic_t *dds3AddEventObjectBasic(u32 serialID, sdfVector4_t pos, sdfVector4_t rot) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  dds3Basic_t_o *pBasic;
  UnityEngine_Vector4_o v16;
  UnityEngine_Vector4_o v17;

  w = rot.w;
  z = rot.z;
  y = rot.y;
  x = rot.x;
  v8 = pos.w;
  v9 = pos.z;
  v10 = pos.y;
  v11 = pos.x;
  pBasic = 0;
  pBasic = dds3AddSceneBasicData(8u);
  pBasic->serialID = serialID;
  v16.x = v11;
  v16.y = v10;
  v16.z = v9;
  v16.w = v8;
  dds3SetPosPoseSet(&pBasic, v16);
  v17.x = x;
  v17.y = y;
  v17.z = z;
  v17.w = w;
  dds3SetRotPoseSet(&pBasic, v17);
  dds3BackupPoseSet(&pBasic->poseset);
  return pBasic;
}

// 0x17b4310
dds3ObjectBaseControlWorkData_t *dds3EventObjectBasicGetControlWorkData(dds3Basic_t **pBasic) {
  dds3ObjectBaseControlWorkData_t_o **workdata;
  dds3ObjectBaseControlWorkData_t_o *v4;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  workdata = (*pBasic)->workdata;
  v4 = *workdata;
  if (LOBYTE((*workdata)[2].MotMode) < typeHierarchyDepth
    || *(v4[1].sdwnodeidx + typeHierarchyDepth - 1) != dds3EventObjectBasicWorkData_t)
  {
    sub_8FC2C0(v4->pModelRangeRootNode, dds3EventObjectBasicWorkData_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  return workdata[2];
}
