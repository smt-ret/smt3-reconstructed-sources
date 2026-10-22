#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ObjectBaseControlWorkData_t dds3ObjectBaseControlWorkData_t;

void LookAtMatrix(sdfVector4_t aTarget, sdfVector4_t aEye, sdfVector4_t aDown);
void MakeCamera(dds3Basic_t **pBasic);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__APPLYMATRIX(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__LOADMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__STOREMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__VECTOR_W_SET_ONE(void);
void ToMatrix(void);
dds3Basic_t *dds3AddSceneBasicData(u32 type);
void dds3DeleteSceneBasicData(dds3Basic_t **basic);
dds3Basic_t *dds3GetActiveCameraSceneBasic(dds3Basic_t **pBasic);
dds3Basic_t *dds3GetControlScene(void);
s32 dds3InitPoseSet(dds3Basic_t **basic);
void dds3ObjectBaseCreateMover(dds3Basic_t **pObjectBasic);
void dds3ObjectBaseFreeControlWorkData(dds3ObjectBaseControlWorkData_t **pControl);
dds3ObjectBaseControlWorkData_t *dds3ObjectBaseInitControlWorkData(dds3Basic_t **pObjectBasic);
void dds3ObjectBaseOnFlag(dds3Basic_t **pObjectBasic, u32 flag, bool alock);
void dds3SetScreenFovy(f32 fovy);

// 0x15243e0
s32 CameraObjectBasicConstructor(dds3Basic_t *pBasic) {
  dds3CameraObjectBasicWorkData_t_o *v3;
  dds3CameraObjectBasicWorkData_t_c *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3Basic_t_o *v9[3];
  dds3Basic_t_o *basic;

  basic = pBasic;
  dds3InitPoseSet(&basic);
  v3 = Allocate(dds3CameraObjectBasicWorkData_t);
  dds3CameraObjectBasicWorkData_t___ctor(v3);
  pBasic->workdata = v3;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3CameraObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3CameraObjectBasicWorkData_t, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v3->pObjectBaseControlWorkData = dds3ObjectBaseInitControlWorkData(&basic);
  dds3ObjectBaseOnFlag(&basic, 0x62u, 0);
  v3->flag = 0;
  return 1;
}

// 0x1524540
s32 CameraObjectBasicDestructor(dds3Basic_t *pBasic) {
  dds3ObjectBaseControlWorkData_t_o **workdata;
  dds3ObjectBaseControlWorkData_t_o *v4;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v9[3];

  if (pBasic && pBasic->poseset)
    pBasic->poseset = 0;
  workdata = pBasic->workdata;
  if (workdata)
  {
    v4 = *workdata;
    if (LOBYTE((*workdata)[2].MotMode) < typeHierarchyDepth
      || *(v4[1].sdwnodeidx + typeHierarchyDepth - 1) != dds3CameraObjectBasicWorkData_t)
    {
      sub_8FC2C0(v4->pModelRangeRootNode, dds3CameraObjectBasicWorkData_t, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
    dds3ObjectBaseFreeControlWorkData(workdata + 11);
  }
  return 0;
}

// 0x1524b50
s32 CameraObjectBasicDrawprocuder(dds3Basic_t *pBasic) {
  return 1;
}

// 0x1524670
s32 CameraObjectBasicMainprocuder(dds3Basic_t *pBasic) {
  Il2CppObject *workdata;
  struct dds3PoseSet_t_o *poseset;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u32 flag;
  f32 v14;
  dds3Basic_t_o *ControlScene;
  dds3Basic_t_o *v17[3];
  dds3Basic_t_o *pBasica;

  pBasica = pBasic;
  ControlScene = 0;
  workdata = pBasic->workdata;
  poseset = pBasic->poseset;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3CameraObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3CameraObjectBasicWorkData_t, v17);
      if ((v17[0] & 1) != 0)
        v7 = v17[2];
      else
        v7 = v17 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  else
  {
    flag = poseset->flag;
    if ((flag & 1) == 0)
      goto LABEL_17;
  }
  poseset->flag = flag & 0xFFFFFFFE;
  MakeCamera(&pBasica);
  SDF_VU0__COPYVECTOR(&poseset->workscl, poseset->scl);
  SDF_VU0__COPYVECTOR(&poseset->workrot, poseset->rot);
  SDF_VU0__COPYVECTOR(&poseset->workpos, poseset->pos);
LABEL_17:
  ControlScene = dds3GetControlScene();
  if (ControlScene)
  {
    if (dds3GetActiveCameraSceneBasic(&ControlScene) == pBasic)
    {
      SDF_VU0__COPYVECTOR(&dds3CameraEyePos, poseset->pos);
      SDF_VU0__COPYVECTOR(&dds3CameraTargetPos, *(workdata + 56), 0);
      SDF_VU0__COPYVECTOR(&dds3CameraUpVector, *(workdata + 72), 0);
      if ((BYTE4(workdata[6].klass) & 1) != 0)
      {
        v14 = *&workdata[6].monitor;
        dds3SetScreenFovy(v14);
        HIDWORD(workdata[6].klass) &= ~1u;
      }
    }
  }
  return 1;
}

// 0x1524930
void MakeCamera(dds3Basic_t **pBasic) {
  struct dds3PoseSet_t_o *poseset;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  f32 x;
  f32 y;
  f32 z;
  f32 w;
  u64 v21[3];
  UnityEngine_Vector4_o v22;
  UnityEngine_Vector4_o v23;
  UnityEngine_Vector4_o v24;

  workdata = (*pBasic)->workdata;
  poseset = (*pBasic)->poseset;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3CameraObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3CameraObjectBasicWorkData_t, v21);
      if ((v21[0] & 1) != 0)
        v7 = v21[2];
      else
        v7 = v21 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  SDF_VU0__LOADVECTOR(poseset->rot);
  ToMatrix();
  SDF_VU0__LOADVECTOR(*(workdata + 40), 0);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__VECTOR_W_SET_ONE();
  SDF_VU0__STOREVECTOR(&workdata[4].monitor);
  if (LODWORD(workdata[6].klass) == 1)
  {
    SDF_VU0__LOADVECTOR(*(workdata + 24), 0);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__LOADVECTOR_B(poseset->pos);
    SDF_VU0__ADDVECTOR();
    SDF_VU0__VECTOR_W_SET_ONE();
    SDF_VU0__STOREVECTOR(&workdata[3].monitor);
  }
  v23 = *(workdata + 56);
  x = poseset->pos.x;
  y = poseset->pos.y;
  z = poseset->pos.z;
  w = poseset->pos.w;
  v24.x = x;
  v24.y = y;
  v24.z = z;
  v24.w = w;
  *&v22.x = 0;
  LookAtMatrix(v23, v24, v22);
  SDF_VU0__STOREMATRIX(&workdata[1].klass->_1.name);
}

// 0x1525260
dds3Basic_t *dds3AddCameraObjectBasic(u32 serialID, sdfVector4_t eyePos, sdfVector4_t eyeVector, sdfVector4_t vertical, f32 fovy, u32 mode) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 v11;
  f32 v12;
  f32 v13;
  f32 v14;
  f32 v15;
  dds3Basic_t_o *v18;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v22;
  s64 *v23;
  struct dds3PoseSet_t_o *poseset;
  dds3Basic_t_o *pObjectBasic[3];
  dds3Basic_t_o *pBasic;
  s64 v29;
  s32 v30;
  UnityEngine_Vector4_o v31;
  UnityEngine_Vector4_o v32;
  UnityEngine_Vector4_o v33;
  UnityEngine_Vector4_o v34;

  w = eyeVector.w;
  z = eyeVector.z;
  y = eyeVector.y;
  x = eyeVector.x;
  v11 = eyePos.w;
  v12 = eyePos.z;
  v13 = eyePos.y;
  v14 = eyePos.x;
  v15 = vertical.x;
  pBasic = 0;
  pObjectBasic[0] = 0;
  pObjectBasic[0] = dds3AddSceneBasicData(4u);
  pObjectBasic[0]->serialID = serialID;
  dds3ObjectBaseCreateMover(pObjectBasic);
  v18 = pObjectBasic[0];
  pBasic = pObjectBasic[0];
  workdata = pObjectBasic[0]->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3CameraObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3CameraObjectBasicWorkData_t, pObjectBasic);
      if ((pObjectBasic[0] & 1) != 0)
        v22 = pObjectBasic[2];
      else
        v22 = pObjectBasic + 1;
      v23 = sub_8C4940(v22);
    }
  }
  *&workdata[6].klass = v15;
  LODWORD(workdata[6].monitor) = v30;
  poseset = v18->poseset;
  v31.x = v14;
  v31.y = v13;
  v31.z = v12;
  v31.w = v11;
  poseset->flag = poseset->flag & 0xFFFFFFFC | 1;
  SDF_VU0__COPYVECTOR(&poseset->pos, v31);
  SDF_VU0__COPYVECTOR(&v18->poseset->workscl, v18->poseset->scl);
  SDF_VU0__COPYVECTOR(&v18->poseset->workrot, v18->poseset->rot);
  SDF_VU0__COPYVECTOR(&v18->poseset->workpos, v18->poseset->pos);
  v32.x = fovy;
  v32.y = *(&fovy + 1);
  *&v32.z = v29;
  SDF_VU0__COPYVECTOR(&workdata[2].monitor, v32);
  v33.y = y;
  v33.w = w;
  v33.x = x;
  v33.z = z;
  SDF_VU0__COPYVECTOR(&workdata[1].monitor, v33);
  if (v15 == 0.0)
  {
    v34.x = x;
    v34.y = y;
    v34.z = z;
    v34.w = w;
    SDF_VU0__COPYVECTOR(&workdata[3].monitor, v34);
  }
  MakeCamera(&pBasic);
  return v18;
}

// 0x1524c50
dds3Basic_t *dds3AddCameraObjectBasicDef(u32 serialID) {
  dds3Basic_t_o *pObjectBasic;

  pObjectBasic = 0;
  pObjectBasic = dds3AddSceneBasicData(4u);
  pObjectBasic->serialID = serialID;
  dds3ObjectBaseCreateMover(&pObjectBasic);
  return pObjectBasic;
}

// 0x1524ce0
dds3Basic_t *dds3AddCameraObjectBasicTypeFree(u32 serialID, sdfVector4_t pos, sdfVector4_t rot) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 v8;
  f32 v9;
  dds3Basic_t_o *v13;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v17;
  s64 *v18;
  struct dds3PoseSet_t_o *poseset;
  struct dds3PoseSet_t_o *v20;
  f32 v23;
  f32 v24;
  dds3Basic_t_o *pBasic;
  UnityEngine_Vector4_o v26;
  UnityEngine_Vector4_o v27;
  dds3Basic_t_o *pObjectBasic[3];
  UnityEngine_Vector4_o v29;
  UnityEngine_Vector4_o v30;

  w = rot.w;
  z = rot.z;
  y = rot.y;
  x = rot.x;
  v8 = pos.y;
  v9 = pos.x;
  v23 = pos.z;
  v24 = pos.w;
  pBasic = 0;
  *&v27.x = 0;
  *&v27.z = 0;
  *&v26.x = 0;
  *&v26.z = 0;
  sub_854690(&v27.x, 0.0, 1.0, 0.0, 1.0);
  sub_854690(&v26.x, 0.0, 0.0, 1.0, 1.0);
  pObjectBasic[0] = 0;
  pObjectBasic[0] = dds3AddSceneBasicData(4u);
  pObjectBasic[0]->serialID = serialID;
  dds3ObjectBaseCreateMover(pObjectBasic);
  v13 = pObjectBasic[0];
  pBasic = pObjectBasic[0];
  workdata = pObjectBasic[0]->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3CameraObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3CameraObjectBasicWorkData_t, pObjectBasic);
      if ((pObjectBasic[0] & 1) != 0)
        v17 = pObjectBasic[2];
      else
        v17 = pObjectBasic + 1;
      v18 = sub_8C4940(v17);
    }
  }
  LODWORD(workdata[6].klass) = 1;
  LODWORD(workdata[6].monitor) = 1059117436;
  poseset = v13->poseset;
  v29.x = x;
  v29.y = y;
  v29.z = z;
  v29.w = w;
  poseset->flag = poseset->flag & 0xFFFFFFFC | 1;
  SDF_VU0__COPYVECTOR(&poseset->rot, v29);
  v20 = v13->poseset;
  v20->flag = v20->flag & 0xFFFFFFFC | 1;
  v30.x = v9;
  v30.z = v23;
  v30.w = v24;
  v30.y = v8;
  SDF_VU0__COPYVECTOR(&v20->pos, v30);
  SDF_VU0__COPYVECTOR(&v13->poseset->workscl, v13->poseset->scl);
  SDF_VU0__COPYVECTOR(&v13->poseset->workrot, v13->poseset->rot);
  SDF_VU0__COPYVECTOR(&v13->poseset->workpos, v13->poseset->pos);
  SDF_VU0__COPYVECTOR(&workdata[2].monitor, v27);
  SDF_VU0__COPYVECTOR(&workdata[1].monitor, v26);
  MakeCamera(&pBasic);
  return v13;
}

// 0x1524fd0
dds3Basic_t *dds3AddCameraObjectBasicTypeLookAt(u32 serialID, sdfVector4_t eyePos, sdfVector4_t targetPos, sdfVector4_t vertical) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  dds3Basic_t_o *v15;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v19;
  s64 *v20;
  struct dds3PoseSet_t_o *poseset;
  dds3Basic_t_o *pBasic;
  dds3Basic_t_o *pObjectBasic[3];
  s64 v26;
  s64 v27;
  UnityEngine_Vector4_o v28;
  UnityEngine_Vector4_o v29;
  UnityEngine_Vector4_o v30;

  w = targetPos.w;
  z = targetPos.z;
  y = targetPos.y;
  x = targetPos.x;
  v9 = eyePos.w;
  v10 = eyePos.z;
  v11 = eyePos.y;
  v12 = eyePos.x;
  pBasic = 0;
  pObjectBasic[0] = 0;
  pObjectBasic[0] = dds3AddSceneBasicData(4u);
  pObjectBasic[0]->serialID = serialID;
  dds3ObjectBaseCreateMover(pObjectBasic);
  v15 = pObjectBasic[0];
  pBasic = pObjectBasic[0];
  workdata = pObjectBasic[0]->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3CameraObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3CameraObjectBasicWorkData_t, pObjectBasic);
      if ((pObjectBasic[0] & 1) != 0)
        v19 = pObjectBasic[2];
      else
        v19 = pObjectBasic + 1;
      v20 = sub_8C4940(v19);
    }
  }
  LODWORD(workdata[6].klass) = 0;
  LODWORD(workdata[6].monitor) = 1059117436;
  poseset = v15->poseset;
  v28.x = v12;
  v28.y = v11;
  v28.z = v10;
  v28.w = v9;
  poseset->flag = poseset->flag & 0xFFFFFFFC | 1;
  SDF_VU0__COPYVECTOR(&poseset->pos, v28);
  SDF_VU0__COPYVECTOR(&v15->poseset->workscl, v15->poseset->scl);
  SDF_VU0__COPYVECTOR(&v15->poseset->workrot, v15->poseset->rot);
  SDF_VU0__COPYVECTOR(&v15->poseset->workpos, v15->poseset->pos);
  *&v29.x = v26;
  *&v29.z = v27;
  SDF_VU0__COPYVECTOR(&workdata[2].monitor, v29);
  v30.x = x;
  v30.y = y;
  v30.z = z;
  v30.w = w;
  SDF_VU0__COPYVECTOR(&workdata[3].monitor, v30);
  MakeCamera(&pBasic);
  return v15;
}

// 0x1525e90
void dds3CameraObjectBasicAlterMode(dds3Basic_t **pBasic, u32 mode) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  workdata = (*pBasic)->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3CameraObjectBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3CameraObjectBasicWorkData_t, v10);
    if ((v10[0] & 1) != 0)
      v8 = v10[2];
    else
      v8 = v10 + 1;
    v9 = sub_8C4940(v8);
  }
  if (LODWORD(workdata[6].klass) != mode)
    LODWORD(workdata[6].klass) = mode;
}

// 0x15255a0
void dds3CameraObjectBasicGetCameraTM(dds3Basic_t **pBasic) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  UnityEngine_Matrix4x4_o dest;
  u64 v9[3];

  workdata = (*pBasic)->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3CameraObjectBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3CameraObjectBasicWorkData_t, v9);
    if ((v9[0] & 1) != 0)
      v6 = v9[2];
    else
      v6 = v9 + 1;
    v7 = sub_8C4940(v6);
  }
  memmove(&dest, &workdata[1].klass->_1.name, 0x40u);
  SDF_VU0__LOADMATRIX(&dest);
}

// 0x1524b60
dds3ObjectBaseControlWorkData_t *dds3CameraObjectBasicGetControlWorkData(dds3Basic_t **pBasic) {
  dds3ObjectBaseControlWorkData_t_o **workdata;
  dds3ObjectBaseControlWorkData_t_o *v4;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  workdata = (*pBasic)->workdata;
  v4 = *workdata;
  if (LOBYTE((*workdata)[2].MotMode) < typeHierarchyDepth
    || *(v4[1].sdwnodeidx + typeHierarchyDepth - 1) != dds3CameraObjectBasicWorkData_t)
  {
    sub_8FC2C0(v4->pModelRangeRootNode, dds3CameraObjectBasicWorkData_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  return workdata[11];
}

// 0x1525ad0
f32 dds3CameraObjectBasicGetFovy(dds3Basic_t **pBasic) {
  f32 *workdata;
  s64 v4;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  workdata = (*pBasic)->workdata;
  v4 = *workdata;
  if (*(*workdata + 288LL) < typeHierarchyDepth
    || *(*(v4 + 200) + 8 * typeHierarchyDepth - 8) != dds3CameraObjectBasicWorkData_t)
  {
    sub_8FC2C0(*(v4 + 64), dds3CameraObjectBasicWorkData_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  return workdata[26];
}

// 0x1525da0
u32 dds3CameraObjectBasicGetMode(dds3Basic_t **pBasic) {
  u32 *workdata;
  s64 v4;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  workdata = (*pBasic)->workdata;
  v4 = *workdata;
  if (*(*workdata + 288LL) < typeHierarchyDepth
    || *(*(v4 + 200) + 8 * typeHierarchyDepth - 8) != dds3CameraObjectBasicWorkData_t)
  {
    sub_8FC2C0(*(v4 + 64), dds3CameraObjectBasicWorkData_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  return workdata[24];
}

// 0x15257e0
void dds3CameraObjectBasicGetTargetPos(dds3Basic_t **pBasic) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v8[3];

  workdata = (*pBasic)->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3CameraObjectBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3CameraObjectBasicWorkData_t, v8);
    if ((v8[0] & 1) != 0)
      v6 = v8[2];
    else
      v6 = v8 + 1;
    v7 = sub_8C4940(v6);
  }
  SDF_VU0__LOADVECTOR(*(workdata + 56), 0);
}

// 0x1525bc0
void dds3CameraObjectBasicGetTgtCam(dds3Basic_t **pBasic, sdfVector4_t *tgtpos, sdfVector4_t *campos) {
  dds3Basic_t_o *v7;
  struct dds3PoseSet_t_o *poseset;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v12;
  s64 *v13;
  u64 v14[3];

  v7 = *pBasic;
  if (*pBasic)
  {
    workdata = v7->workdata;
    poseset = v7->poseset;
    if (workdata)
    {
      klass = workdata->klass;
      if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3CameraObjectBasicWorkData_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3CameraObjectBasicWorkData_t, v14);
        if ((v14[0] & 1) != 0)
          v12 = v14[2];
        else
          v12 = v14 + 1;
        v13 = sub_8C4940(v12);
      }
    }
    SDF_VU0__LOADVECTOR(poseset->rot);
    ToMatrix();
    SDF_VU0__LOADVECTOR(*(workdata + 40), 0);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__VECTOR_W_SET_ONE();
    SDF_VU0__STOREVECTOR(&workdata[4].monitor);
    if (LODWORD(workdata[6].klass) == 1)
    {
      SDF_VU0__LOADVECTOR(*(workdata + 24), 0);
      SDF_VU0__APPLYMATRIX();
      SDF_VU0__LOADVECTOR_B(poseset->pos);
      SDF_VU0__ADDVECTOR();
      SDF_VU0__VECTOR_W_SET_ONE();
      SDF_VU0__STOREVECTOR(&workdata[3].monitor);
    }
    tgtpos->x = *&workdata[3].monitor;
    tgtpos->y = *(&workdata[3].monitor + 1);
    tgtpos->z = *&workdata[4].klass;
    tgtpos->w = *(&workdata[4].klass + 1);
    campos->x = poseset->pos.x;
    campos->y = poseset->pos.y;
    campos->z = poseset->pos.z;
    campos->w = poseset->pos.w;
  }
}

// 0x15258d0
void dds3CameraObjectBasicSetFovy(dds3Basic_t **pBasic, f32 fovy) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  s32 v8;
  char *v9;
  s64 *v10;
  u64 v11[3];

  workdata = (*pBasic)->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3CameraObjectBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3CameraObjectBasicWorkData_t, v11);
    if ((v11[0] & 1) != 0)
      v9 = v11[2];
    else
      v9 = v11 + 1;
    v10 = sub_8C4940(v9);
  }
  v8 = HIDWORD(workdata[6].klass) | 1;
  *&workdata[6].monitor = fovy;
  HIDWORD(workdata[6].klass) = v8;
}

// 0x15259d0
void dds3CameraObjectBasicSetFovy2(dds3Basic_t **pBasic, f32 fovy) {
  f32 *workdata;
  s64 v6;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  workdata = (*pBasic)->workdata;
  v6 = *workdata;
  if (*(*workdata + 288LL) < typeHierarchyDepth
    || *(*(v6 + 200) + 8 * typeHierarchyDepth - 8) != dds3CameraObjectBasicWorkData_t)
  {
    sub_8FC2C0(*(v6 + 64), dds3CameraObjectBasicWorkData_t, v10);
    if ((v10[0] & 1) != 0)
      v8 = v10[2];
    else
      v8 = v10 + 1;
    v9 = sub_8C4940(v8);
  }
  workdata[26] = fovy;
}

// 0x15256b0
void dds3CameraObjectBasicSetTargetPos(dds3Basic_t **pBasic, sdfVector4_t targetPos) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  u64 v13[3];
  UnityEngine_Vector4_o v14;

  w = targetPos.w;
  z = targetPos.z;
  y = targetPos.y;
  x = targetPos.x;
  workdata = (*pBasic)->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3CameraObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3CameraObjectBasicWorkData_t, v13);
      if ((v13[0] & 1) != 0)
        v11 = v13[2];
      else
        v11 = v13 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  v14.x = x;
  v14.y = y;
  v14.z = z;
  v14.w = w;
  SDF_VU0__COPYVECTOR(&workdata[3].monitor, v14);
}

// 0x1525530
void dds3DeleteCameraObjectBasic(dds3Basic_t **pBasic) {
  dds3DeleteSceneBasicData(pBasic);
}
