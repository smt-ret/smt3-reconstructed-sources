#include "types.h"

typedef struct FieldBgHD FieldBgHD;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3MatterObjectBasicWorkData_t dds3MatterObjectBasicWorkData_t;
typedef struct dds3ObjectBaseControlWorkData_t dds3ObjectBaseControlWorkData_t;
typedef struct dds3PoseSet_t dds3PoseSet_t;
typedef struct sdfModelOt_t sdfModelOt_t;

FieldBgHD *GetFHD(void);
void RetTransparent(void *obj);
void SDF_VU0__SET_ROW3(void);
void SDF_VU0__STOREMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SetTransparentEvent(FieldBgHD *this, void *rootobj, u32 rgba);
dds3Basic_t *dds3AddSceneBasicData(u32 type);
void dds3BackupPoseSet(dds3PoseSet_t **pPoseSet);
void dds3DeleteSceneBasicData(dds3Basic_t **basic);
void dds3FreePoseSet(dds3Basic_t **basic);
dds3ObjectBaseControlWorkData_t *dds3GetBaseControlWorkData(dds3Basic_t **pObjectBasic);
dds3Basic_t *dds3GetControlScene(void);
void dds3GetPosPoseSet(dds3Basic_t **pBasic);
void dds3GetRotPoseSet(dds3Basic_t **pBasic);
void dds3GetTMPoseSet(dds3Basic_t **pBasic);
s32 dds3InitPoseSet(dds3Basic_t **basic);
void dds3MatterObjectBasicWorkData_t__Clear(dds3MatterObjectBasicWorkData_t *this);
void dds3ObjectBaseCreateMover(dds3Basic_t **pObjectBasic);
void dds3ObjectBaseFreeControlWorkData(dds3ObjectBaseControlWorkData_t **pControl);
dds3ObjectBaseControlWorkData_t *dds3ObjectBaseInitControlWorkData(dds3Basic_t **pObjectBasic);
void dds3ObjectBaseModelLinkOt(sdfModelOt_t *pModelOt, dds3Basic_t **pObjectBasic);
void dds3OffPoseSetFlag(dds3PoseSet_t **pPoseSet, u32 flag);
dds3Basic_t *dds3SearchSceneBasic(dds3Basic_t **pBasic, u32 serialID, u32 type);
void dds3SetPosPoseSet(dds3Basic_t **pBasic, sdfVector4_t pos);
void dds3SetRotPoseSet(dds3Basic_t **pBasic, sdfVector4_t rot);
s32 fldDoor_Step(s32 matter_resid, f32 *x, f32 *y, f32 *z);

// 0x14e9e70
FieldBgHD *GetFHD(void) {
  UnityEngine_Object_o *fldprefab;
  bool v5;
  FieldBgHD_o *result;

  fldprefab = kernelObject->fldprefab;
  v5 = op_Inequality(fldprefab, 0, 0);
  result = 0;
  if (v5)
  {
    return GetComponent_object_(kernelObject->fldprefab);
  }
  return result;
}

// 0x14ea530
dds3Basic_t *dds3AddMatterObjectBasic(u32 serialID, sdfVector4_t pos, sdfVector4_t rot) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  dds3Basic_t_o *result;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v20;
  s64 *v21;
  UnityEngine_Vector4_o v22;
  dds3Basic_t_o *pObjectBasic;
  u64 v24[3];
  UnityEngine_Vector4_o v25;

  w = rot.w;
  z = rot.z;
  y = rot.y;
  x = rot.x;
  v8 = pos.w;
  v9 = pos.z;
  v10 = pos.y;
  v11 = pos.x;
  *&v22.z = 0;
  pObjectBasic = 0;
  *&v22.x = 0;
  sub_854690(&v22.x, 0.0, 0.0, 0.0, 1.0);
  pObjectBasic = dds3AddSceneBasicData(6u);
  pObjectBasic->serialID = serialID;
  dds3ObjectBaseCreateMover(&pObjectBasic);
  v25.x = x;
  v25.y = y;
  v25.z = z;
  v25.w = w;
  dds3SetRotPoseSet(&pObjectBasic, v25);
  dds3SetPosPoseSet(&pObjectBasic, v22);
  dds3BackupPoseSet(&pObjectBasic->poseset);
  result = pObjectBasic;
  workdata = pObjectBasic->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3MatterObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3MatterObjectBasicWorkData_t, v24);
      if ((v24[0] & 1) != 0)
        v20 = v24[2];
      else
        v20 = v24 + 1;
      v21 = sub_8C4940(v20);
    }
  }
  *(&workdata[2].klass + 1) = v11;
  *&workdata[2].monitor = v10;
  *(&workdata[2].monitor + 1) = v9;
  *&workdata[3].klass = v8;
  return result;
}

// 0x14ea730
void dds3DeleteMatterObjectBasic(dds3Basic_t **aPtr) {
  dds3Basic_t_o **v3;

  else
  {
    v3 = aPtr;
  }
  dds3DeleteSceneBasicData(v3);
}

// 0x14e9350
s32 dds3MatterObjectBasicConstructor(dds3Basic_t *aPtr) {
  dds3Basic_t_o *v2;
  u64 *v3;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  dds3MatterObjectBasicWorkData_t_c *v9;
  Il2CppObject *v10;
  Il2CppClass *v11;
  s64 v12;
  char *v13;
  s64 *v14;
  dds3ObjectBaseControlWorkData_t_o *inited;
  dds3ObjectBaseControlWorkData_t_o *BaseControlWorkData;
  u64 v19[2];
  char *v20;
  dds3Basic_t_o *basic;

  basic = aPtr;
  dds3InitPoseSet(&basic);
  v2 = basic;
  v3 = Allocate(dds3MatterObjectBasicWorkData_t);
  dds3MatterObjectBasicWorkData_t___ctor(v3);
  v2->workdata = v3;
  workdata = basic->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3MatterObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3MatterObjectBasicWorkData_t, v19);
      if ((v19[0] & 1) != 0)
        v7 = v20;
      else
        v7 = v19 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  dds3MatterObjectBasicWorkData_t__Clear(workdata);
  v10 = basic->workdata;
  if (v10)
  {
    v11 = v10->klass;
    if (v10->klass->_2.typeHierarchyDepth < v12
      || v11->_2.typeHierarchy[v12 - 1] != dds3MatterObjectBasicWorkData_t)
    {
      sub_8FC2C0(v11->_1.element_class, dds3MatterObjectBasicWorkData_t, v19);
      if ((v19[0] & 1) != 0)
        v13 = v20;
      else
        v13 = v19 + 1;
      v14 = sub_8C4940(v13);
    }
  }
  inited = dds3ObjectBaseInitControlWorkData(&basic, v9);
  LODWORD(v10[2].klass) = -1;
  v10[1].klass = inited;
  v10[1].monitor = 0;
  *(&v10[2].klass + 4) = 0;
  *(&v10[2].monitor + 4) = 0x3F80000000000000LL;
  *(&v10[3].klass + 4) = 0;
  *(&v10[3].monitor + 4) = 0x3F80000000000000LL;
  BaseControlWorkData = dds3GetBaseControlWorkData(&basic);
  BaseControlWorkData->flag |= 0xE2u;
  return 1;
}

// 0x14e9590
s32 dds3MatterObjectBasicDestructor(dds3Basic_t *aPtr) {
  dds3ObjectBaseControlWorkData_t_o **workdata;
  dds3ObjectBaseControlWorkData_t_o *v3;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  dds3Basic_t_o *v8[3];
  dds3Basic_t_o *basic;

  basic = aPtr;
  dds3FreePoseSet(&basic);
  workdata = basic->workdata;
  if (workdata)
  {
    v3 = *workdata;
    if (LOBYTE((*workdata)[2].MotMode) < typeHierarchyDepth
      || *(v3[1].sdwnodeidx + typeHierarchyDepth - 1) != dds3MatterObjectBasicWorkData_t)
    {
      sub_8FC2C0(v3->pModelRangeRootNode, dds3MatterObjectBasicWorkData_t, v8);
      if ((v8[0] & 1) != 0)
        v5 = v8[2];
      else
        v5 = v8 + 1;
      v6 = sub_8C4940(v5);
    }
    dds3ObjectBaseFreeControlWorkData(workdata + 2, dds3MatterObjectBasicWorkData_t);
  }
  return 0;
}

// 0x14e9f70
s32 dds3MatterObjectBasicDrawProcedure(dds3Basic_t *aPtr) {
  Il2CppObject *workdata;
  dds3MatterObjectBasicWorkData_t_c *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  u32 v8;
  sdfModelOt_t_o *v9;
  u32 color;
  sdfModelOt_t_o *v15;
  char *v17;
  s64 *v18;
  dds3Basic_t_o *v19;
  u64 v20[3];

  v19 = aPtr;
  workdata = aPtr->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3MatterObjectBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3MatterObjectBasicWorkData_t, v20);
    if ((v20[0] & 1) != 0)
      v17 = v20[2];
    else
      v17 = v20 + 1;
    v18 = sub_8C4940(v17);
  }
  v8 = workdata[2].klass;
  if (v8 == -1)
  {
    if (*(v9[7].ot->max_length + 24))
      goto LABEL_13;
    goto LABEL_12;
  }
  if ((HIDWORD(workdata[1].monitor) - 3) > 1 || aPtr->color == -2139062144)
  {
    if (v8 >= *(v9[7].ot->max_length + 24))
      goto LABEL_12;
    goto LABEL_13;
  }
  if ((dds3GetBaseControlWorkData(&player, v5)->flag & 1) == 0)
  {
    if (*(v9[7].ot->max_length + 24) > 7u)
    {
LABEL_13:
      dds3ObjectBaseModelLinkOt(v9, &v19);
      return 1;
    }
LABEL_12:
  }
  color = v19->color;
  v19->color = -2139062144;
  dds3ObjectBaseModelLinkOt(v15, &v19);
  v19->color = color;
  return 1;
}

// 0x14eae00
s32 dds3MatterObjectBasicGetAlpMode(dds3Basic_t **aPtr) {
  s32 *workdata;
  s64 v4;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  workdata = (*aPtr)->workdata;
  v4 = *workdata;
  if (*(*workdata + 288LL) < typeHierarchyDepth
    || *(*(v4 + 200) + 8 * typeHierarchyDepth - 8) != dds3MatterObjectBasicWorkData_t)
  {
    sub_8FC2C0(*(v4 + 64), dds3MatterObjectBasicWorkData_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  return workdata[7];
}

// 0x14ea440
dds3ObjectBaseControlWorkData_t *dds3MatterObjectBasicGetControlWorkData(dds3Basic_t **pBasic) {
  dds3ObjectBaseControlWorkData_t_o **workdata;
  dds3ObjectBaseControlWorkData_t_o *v4;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  workdata = (*pBasic)->workdata;
  v4 = *workdata;
  if (LOBYTE((*workdata)[2].MotMode) < typeHierarchyDepth
    || *(v4[1].sdwnodeidx + typeHierarchyDepth - 1) != dds3MatterObjectBasicWorkData_t)
  {
    sub_8FC2C0(v4->pModelRangeRootNode, dds3MatterObjectBasicWorkData_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  return workdata[2];
}

// 0x14ea9b0
s32 dds3MatterObjectBasicGetHojiID(s32 resID) {
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
    || *(*(v6 + 200) + 8 * typeHierarchyDepth - 8) != dds3MatterObjectBasicWorkData_t)
  {
    sub_8FC2C0(*(v6 + 64), dds3MatterObjectBasicWorkData_t, v12);
    if ((v12[0] & 1) != 0)
      v9 = v12[2];
    else
      v9 = v12 + 1;
    v10 = sub_8C4940(v9);
  }
  return workdata[6];
}

// 0x14e96c0
s32 dds3MatterObjectBasicMainProcedure(dds3Basic_t *aPtr) {
  dds3Basic_t_o *v2;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  UnityEngine_Object_o *FHD;
  Il2CppObject *pModel;
  dds3Basic_t_o *v11;
  UnityEngine_Object_o *gameObject;
  dds3Basic_t_o *v14;
  s32 v15;
  dds3Basic_t_o *v16;
  u32 color;
  u32 v18;
  s32 v19;
  u32 color_high;
  u32 v21;
  s32 v22;
  u32 v23;
  UnityEngine_Object_o *v25;
  UnityEngine_GameObject_o *v26;
  bool v27;
  UnityEngine_Object_o *v28;
  UnityEngine_Object_o *v30;
  struct dds3PoseSet_t_o *poseset;
  f32 x;
  f32 v33;
  f32 w;
  f32 v35;
  f32 v36;
  UnityEngine_Transform_o *transform;
  f32 v38;
  f32 v39;
  UnityEngine_Object_o *v40;
  struct dds3PoseSet_t_o *v41;
  f32 v42;
  f32 v43;
  f32 v44;
  f32 v45;
  UnityEngine_Transform_o *v46;
  Il2CppClass *v47;
  s64 v48;
  char *v49;
  s64 *v50;
  dds3PoseSet_t_o **p_poseset;
  s32 serialID;
  s32 v54;
  dds3Basic_t_o *v55;
  f32 v56;
  f32 v57;
  struct dds3PoseSet_t_o *v58;
  f32 v59;
  dds3PoseSet_t_o **v61;
  f32 z;
  s64 y;
  dds3Basic_t_o *pObjectBasic;
  UnityEngine_Vector3_o v66;
  char *v67;
  UnityEngine_Vector3_o v68;
  UnityEngine_Vector3_o v69;
  UnityEngine_Vector4_o v70;
  UnityEngine_Vector4_o v71;

  v2 = aPtr;
  pObjectBasic = aPtr;
  y = 0;
  z = 0.0;
  workdata = v2->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3MatterObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3MatterObjectBasicWorkData_t, &v66);
      if ((LOBYTE(v66.x) & 1) != 0)
        v6 = v67;
      else
        v6 = &v66.x + 1;
      v7 = sub_8C4940(v6);
    }
  }
  FHD = GetFHD(aPtr);
  switch (HIDWORD(workdata[1].monitor))
  {
    case 0:
      pObjectBasic->color = -2139062144;
      pModel = dds3GetBaseControlWorkData(&pObjectBasic)->pModel;
      if (pModel)
        goto LABEL_77;
      return 1;
    case 1:
      v11 = pObjectBasic;
      pObjectBasic->color = -2139062144;
      gameObject = v11->gameObject;
      if (op_Inequality(gameObject, 0, 0))
        SetActive(pObjectBasic->gameObject, 1, 0);
        goto LABEL_35;
      goto LABEL_42;
    case 2:
      v14 = pObjectBasic;
      v15 = 8421504;
      goto LABEL_41;
    case 3:
      v16 = pObjectBasic;
      color = pObjectBasic->color;
      v18 = HIBYTE(color);
      v19 = HIBYTE(color) + 8;
      goto LABEL_29;
    case 4:
      v16 = pObjectBasic;
      color_high = HIBYTE(pObjectBasic->color);
      if (color_high > 0x40)
        color_high -= 8;
      if (color_high <= 0x40)
        LOBYTE(color_high) = 64;
      goto LABEL_34;
    case 5:
      v16 = pObjectBasic;
      color = pObjectBasic->color;
      v18 = HIBYTE(color);
      v19 = HIBYTE(color) + 4;
      goto LABEL_29;
    case 6:
      v14 = pObjectBasic;
      v21 = pObjectBasic->color;
      v22 = -67108864;
      goto LABEL_38;
    case 7:
      v16 = pObjectBasic;
      color = pObjectBasic->color;
      v18 = HIBYTE(color);
      v19 = HIBYTE(color) + 2;
LABEL_29:
      if ((color & 0x80000000) != 0)
        color_high = v18;
      else
        color_high = v19;
      if (color_high >= 0x80)
        LOBYTE(color_high) = 0x80;
LABEL_34:
      v16->color = (color_high << 24) | 0x808080;
        goto LABEL_35;
      goto LABEL_42;
    case 8:
      v14 = pObjectBasic;
      v21 = pObjectBasic->color;
      v22 = -33554432;
LABEL_38:
      v23 = (v21 + v22) & 0xFF000000 | 0x808080;
      if (HIBYTE(v21))
        v15 = v23;
      else
        v15 = 8421504;
LABEL_41:
      v14->color = v15;
        goto LABEL_42;
LABEL_35:
LABEL_42:
      if (!op_Inequality(FHD, 0, 0))
        goto LABEL_76;
      SetTransparentEvent(FHD, pObjectBasic->gameObject, pObjectBasic->color);
      pModel = dds3GetBaseControlWorkData(&pObjectBasic)->pModel;
      if (!pModel)
        return 1;
      goto LABEL_77;
    case 9:
      v25 = pObjectBasic->gameObject;
      if (!op_Inequality(v25, 0, 0)
        || get_activeSelf(pObjectBasic->gameObject))
      {
        goto LABEL_76;
      }
      v26 = pObjectBasic->gameObject;
      v27 = 1;
      goto LABEL_57;
    case 0xA:
      v28 = pObjectBasic->gameObject;
      if (!op_Inequality(v28, 0, 0)
        || !get_activeSelf(pObjectBasic->gameObject))
      {
        goto LABEL_76;
      }
      v26 = pObjectBasic->gameObject;
      v27 = 0;
LABEL_57:
      SetActive(v26, v27, 0);
      pModel = dds3GetBaseControlWorkData(&pObjectBasic)->pModel;
      if (!pModel)
        return 1;
      goto LABEL_77;
    case 0xB:
      v30 = pObjectBasic->gameObject;
      if (!op_Inequality(v30, 0, 0))
        goto LABEL_76;
      poseset = pObjectBasic->poseset;
      x = poseset->pos.x;
      v33 = poseset->pos.y;
      v35 = poseset->pos.z;
      w = poseset->pos.w;
      v70.x = x;
      v70.y = v33;
      v70.z = v35;
      v70.w = w;
      v68 = op_Implicit_8738992(v70);
      v36 = v68.z;
      transform = get_transform(pObjectBasic->gameObject, 0);
      v66.z = 0.0;
      *&v66.x = 0;
      v38 = v68.x / 100.0;
      v39 = v68.y / -100.0;
      goto LABEL_75;
    case 0xC:
      v40 = pObjectBasic->gameObject;
      if (!op_Inequality(v40, 0, 0))
        goto LABEL_76;
      v41 = pObjectBasic->poseset;
      v42 = v41->pos.x;
      v43 = v41->pos.y;
      v45 = v41->pos.z;
      v44 = v41->pos.w;
      v71.x = v42;
      v71.y = v43;
      v71.z = v45;
      v71.w = v44;
      v69 = op_Implicit_8738992(v71);
      v36 = v69.z;
      v46 = get_transform(pObjectBasic->gameObject, 0);
      v38 = v69.x / 100.0;
      transform = v46;
      v66.z = 0.0;
      *&v66.x = 0;
      v39 = (v69.y + -10000.0) / -100.0;
LABEL_75:
      sub_8524C0(&v66.x, v38, v39, v36 / 100.0);
      set_localPosition(transform, v66);
LABEL_76:
      pModel = dds3GetBaseControlWorkData(&pObjectBasic)->pModel;
      if (pModel)
      {
LABEL_77:
        v47 = pModel->klass;
        if (pModel->klass->_2.typeHierarchyDepth < v48
          || v47->_2.typeHierarchy[v48 - 1] != sdfModelRootNode_t)
        {
          sub_8FC2C0(v47->_1.element_class, sdfModelRootNode_t, &v66);
          if ((LOBYTE(v66.x) & 1) != 0)
            v49 = v67;
          else
            v49 = &v66.x + 1;
          v50 = sub_8C4940(v49);
        }
        p_poseset = &pObjectBasic->poseset;
        dds3OffPoseSetFlag(p_poseset, 1u);
        dds3GetRotPoseSet(&pObjectBasic);
        SDF_VU0__STOREVECTOR(&pModel[8].monitor);
        dds3GetTMPoseSet(&pObjectBasic);
        dds3GetPosPoseSet(&pObjectBasic);
        serialID = pObjectBasic->serialID;
        v54 = fldDoor_Step(serialID, &y + 1, &y, &z);
        v55 = pObjectBasic;
        v56 = *(&workdata[2].klass + 1);
        v57 = *(&workdata[3].klass + 1);
        v58 = pObjectBasic->poseset;
        if (v54)
        {
          v58->pos.x = (v56 + v57) + *(&y + 1);
          v55->poseset->pos.y = (*&workdata[2].monitor + *&workdata[3].monitor) + *&y;
          v59 = (*(&workdata[2].monitor + 1) + *(&workdata[3].monitor + 1)) + z;
        }
        else
        {
          v58->pos.x = v56 + v57;
          v55->poseset->pos.y = *&workdata[2].monitor + *&workdata[3].monitor;
          v59 = *(&workdata[2].monitor + 1) + *(&workdata[3].monitor + 1);
        }
        v55->poseset->pos.z = v59;
        SDF_VU0__SET_ROW3();
        SDF_VU0__STOREMATRIX(&pModel[4].monitor);
        v61 = &pObjectBasic->poseset;
        dds3BackupPoseSet(v61);
      }
      return 1;
    default:
      goto LABEL_76;
  }
}

// 0x14eac80
void dds3MatterObjectBasicSetAlpMode(dds3Basic_t **aPtr, s32 alpmode) {
  dds3Basic_t_o **v4;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  FieldBgHD_o *FHD;
  u64 v12[3];

  v4 = aPtr;
  workdata = (*v4)->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3MatterObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3MatterObjectBasicWorkData_t, v12);
      if ((v12[0] & 1) != 0)
        v8 = v12[2];
      else
        v8 = v12 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  if (HIDWORD(workdata[1].monitor) != alpmode && alpmode <= 0xC && ((1 << alpmode) & 0x1E03) != 0)
  {
    FHD = GetFHD(aPtr);
    if (op_Inequality(FHD, 0, 0))
      RetTransparent(FHD, (*v4)->gameObject, 0);
  }
  HIDWORD(workdata[1].monitor) = alpmode;
}

// 0x14ea8b0
void dds3MatterObjectBasicSetHojiID(dds3Basic_t **aPtr, s32 hojiID) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  workdata = (*aPtr)->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3MatterObjectBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3MatterObjectBasicWorkData_t, v10);
    if ((v10[0] & 1) != 0)
      v8 = v10[2];
    else
      v8 = v10 + 1;
    v9 = sub_8C4940(v8);
  }
  LODWORD(workdata[1].monitor) = hojiID;
}

// 0x14ea7b0
void dds3MatterObjectBasicSetOt(dds3Basic_t **aPtr, s32 idx) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  workdata = (*aPtr)->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3MatterObjectBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3MatterObjectBasicWorkData_t, v10);
    if ((v10[0] & 1) != 0)
      v8 = v10[2];
    else
      v8 = v10 + 1;
    v9 = sub_8C4940(v8);
  }
  LODWORD(workdata[2].klass) = idx;
}

// 0x14e9330
void rsetOtOfs(s32 otofs) {
  ;
}

// 0x14e9340
void rsetTest(s32 ate, s32 atst, s32 aref, s32 afail, s32 date, s32 datm, s32 zte, s32 ztst) {
  ;
}
