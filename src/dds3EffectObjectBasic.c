#include "types.h"

typedef struct billHandle_t billHandle_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3EffectObjectBasicWorkData_t dds3EffectObjectBasicWorkData_t;
typedef struct dds3ObjectBaseControlWorkData_t dds3ObjectBaseControlWorkData_t;
typedef struct dds3PoseSet_t dds3PoseSet_t;
typedef struct effBTL_t effBTL_t;
typedef struct effEveBEDCutHandle_t effEveBEDCutHandle_t;
typedef struct effEveBEDParams_t effEveBEDParams_t;
typedef struct effHandle_t effHandle_t;
typedef struct effMagaP4Point_t effMagaP4Point_t;
typedef struct effMagaSCArea_t effMagaSCArea_t;
typedef struct fldResourceEffect_t fldResourceEffect_t;

dds3Basic_t *AddBEDEffect(void *p, sdfVector4_t pos, sdfVector4_t rot);
dds3Basic_t *AddD3PEffect(effHandle_t **eff, sdfVector4_t pos, sdfVector4_t rot);
dds3Basic_t *AddESPEffect(char *name, sdfVector4_t pos, sdfVector4_t rot, f32 r);
dds3Basic_t *AddMG12Effect(s32 type, void *data);
dds3Basic_t *AddP2AEffect(billHandle_t **p2a, sdfVector4_t pos, sdfVector4_t rot);
dds3Basic_t *AddTMXEffect(billHandle_t **tmx, sdfVector4_t pos, sdfVector4_t rot);
dds3EffectObjectBasicWorkData_t *CheckESP(dds3Basic_t **b);
u32 DDS3_GETBASICTYPEL(dds3Basic_t *pAreaBasic);
void FreeEffectData(dds3EffectObjectBasicWorkData_t **work);
billHandle_t *GetBillHandle(void *h, s32 type);
void MultMatrixRevNoArg(void);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__APPLYMATRIX(void);
void SDF_VU0__COPYMATRIX_A_TO_B(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__LOADIDENTITY(void);
void SDF_VU0__LOADIDENTITYVECTOR(void);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__NORMALIZE(void);
void SDF_VU0__STOREMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__TRANSLATE(void);
void SDF_VU0__VECTOR_W_SET_ONE(void);
void ToMatrix(void);
dds3Basic_t *dds3AddEffectObjectBasic(u32 serialID, sdfVector4_t aPos, sdfVector4_t aRot);
dds3Basic_t *dds3AddSceneBasicData(u32 type);
dds3Basic_t *dds3AreaBasicGetFastArea(void);
void dds3AreaBasicRegistItem(dds3Basic_t **pAreaBasic, dds3Basic_t **pItemBasic);
void dds3BackupPoseSet(dds3PoseSet_t **pPoseSet);
billHandle_t *dds3BillboardCopy(billHandle_t *hBillboard);
billHandle_t *dds3BillboardCreate(s32 type, void *pTex, s32 bPos, char *callname);
void dds3BillboardDelete(void **hData);
void dds3BillboardDraw(void **hData);
void dds3BillboardDrawOff(void **hData);
billHandle_t *dds3BillboardFileLoad(s32 type, char *pFileName, char *akey);
s32 dds3BillboardGetAnimState(billHandle_t *hBillboard);
void dds3BillboardSetAnimNumber(billHandle_t **hBillboard, s32 number);
void dds3BillboardSetDrawType(billHandle_t *hBillboard, u16 type);
void dds3BillboardSetMode(billHandle_t **hBillboard, s16 mode);
void dds3BillboardSetPosition(billHandle_t **hBillboard, sdfVector4_t pPos);
void dds3BillboardSetRGBA(billHandle_t **hBillboard, u32 abgr);
void dds3BillboardSetXYOffset(billHandle_t **hBillboard, f32 x, f32 y);
void dds3DeleteSceneBasicData(dds3Basic_t **basic);
void dds3EffectDelete(void **pData);
void dds3EffectDraw(void **pData);
void dds3EffectDrawOff(void **pData);
effHandle_t *dds3EffectFileLoad(char *pFilename);
u16 dds3EffectGetState(effHandle_t *hEffect);
effHandle_t *dds3EffectLoad(void **pD3P, s32 bPos, bool tbldata);
void dds3EffectObjectBasicCalcFldEx(dds3Basic_t **basic);
dds3ObjectBaseControlWorkData_t *dds3EffectObjectBasicGetControlWorkData(dds3Basic_t **pBasic);
void dds3EffectObjectBasicGetObjectIndex(dds3Basic_t **basic);
s32 dds3EffectObjectBasicLinkObject(dds3Basic_t **basic, dds3Basic_t **target);
void dds3EffectObjectBasicStatOn(dds3Basic_t **basic, u32 s);
void dds3EffectObjectBasicUnlinkObject(dds3Basic_t **basic);
void dds3EffectObjectBasicWorkData_t__Clear(dds3EffectObjectBasicWorkData_t *this);
void dds3EffectSetPosition(void **pData, sdfVector4_t pPos);
void dds3EffectSetRotateMatrix(void **pData, sdfMatrix4_t *pMatrix);
void dds3FreePoseSet(dds3Basic_t **basic);
dds3Basic_t *dds3GetActiveScene(void);
void dds3GetPosPoseSetMCR(dds3Basic_t **pBasic);
void dds3GetRotPoseSetMCR(dds3Basic_t **pBasic);
s32 dds3InitPoseSet(dds3Basic_t **basic);
s32 dds3ObjectBaseCheckFlag(dds3Basic_t **pObjectBasic, u32 flag);
void dds3ObjectBaseCreateMover(dds3Basic_t **pObjectBasic);
void dds3ObjectBaseFreeControlWorkData(dds3ObjectBaseControlWorkData_t **pControl);
dds3ObjectBaseControlWorkData_t *dds3ObjectBaseInitControlWorkData(dds3Basic_t **pObjectBasic);
void dds3ObjectBaseOnFlag(dds3Basic_t **pObjectBasic, u32 flag, bool alock);
void dds3OffPoseSetFlag(dds3PoseSet_t **pPoseSet, u32 flag);
s32 dds3SceneBasicExistBasicFromType(dds3Basic_t **scene, s32 type, dds3Basic_t *target);
u32 dds3SerializeID(void);
void dds3SetPosPoseSet(dds3Basic_t **pBasic, sdfVector4_t pos);
void dds3SetRotPoseSet(dds3Basic_t **pBasic, sdfVector4_t rot);
effBTL_t *effEveBEDCreate(u8 **pData);
effEveBEDCutHandle_t *effEveBEDCutCreate(effBTL_t *hEveBED, u16 CutNum, effEveBEDParams_t *pParams);
void effEveBEDCutDelete(effEveBEDCutHandle_t *hEveBEDCut);
void effEveBEDCutDraw(effEveBEDCutHandle_t **hEveBEDCut);
void effEveBEDCutSetParams(effEveBEDCutHandle_t **hEveBEDCut, effEveBEDParams_t *pParams);
void effEveBEDDelete(effBTL_t *hEveBED);
void effEveBEDParams_t__Copy(effEveBEDParams_t *this, effEveBEDParams_t *para);
void effMagaP4Point_t__Copy(effMagaP4Point_t *this, effMagaP4Point_t *para);
void effMagaP4Randomize(effHandle_t **hEffect);
void effMagaP4SetPoint(effHandle_t **hEffect, effMagaP4Point_t *pP4Point);
void effMagaRandomize(effHandle_t **hEffect);
void effMagaSCArea_t__Copy(effMagaSCArea_t *this, effMagaSCArea_t *para);
void effMagaSCSetArea(effHandle_t **hEffect, effMagaSCArea_t *pMagaSCArea);
s32 fldGbChkEView(s32 fld, s32 area, s32 grp);
s32 fldGbGetEAnimeCngID(s32 fld, s32 area, s32 grp);
void *sdfDevLoadFileUnity_25061072(char *aFilename, u8 ***aTopPtr, s32 aSizePtr, char *akey);

// 0x17b0e30
dds3Basic_t *AddBEDEffect(void *p, sdfVector4_t pos, sdfVector4_t rot) {
  f32 z;
  f32 y;
  f32 x;
  f32 w;
  f32 v8;
  f32 v9;
  f32 v10;
  u64 *v12;
  s32 v13;
  s32 v14;
  s32 v16;
  s32 v17;
  u32 v18;
  dds3Basic_t_o *result;
  s64 *Interface;
  effBTL_t_o *v26;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v30;
  s64 *v31;
  u64 *v32;
  u64 v33;
  s64 v34;
  char *v35;
  s64 *v36;
  dds3ObjectBaseControlWorkData_t_o *ControlWorkData;
  dds3Basic_t_o *FastArea;
  struct dds3Basic_t_array *v40;
  dds3Basic_t_o *v41;
  f32 aRot;
  u64 v45;
  s64 v46;
  dds3Basic_t_o *pAreaBasic;
  dds3Basic_t_o *pBasic;
  u64 v49;
  s64 v50;
  char *v51;
  UnityEngine_Vector4_o v52;
  UnityEngine_Vector4_o v53;
  UnityEngine_Vector4_o v54;
  UnityEngine_Vector4_o v55;

  z = rot.z;
  y = rot.y;
  x = rot.x;
  w = pos.w;
  v8 = pos.z;
  v9 = pos.y;
  v10 = pos.x;
  aRot = rot.w;
  pAreaBasic = 0;
  pBasic = 0;
  v12 = Allocate(effEveBEDParams_t);
  effEveBEDParams_t___ctor(v12);
  v49 = 0;
  v50 = 0;
  sub_854690(&v49, 0.0, 0.0, 0.0, 0.0);
  v14 = v50;
  v13 = HIDWORD(v50);
  v12[2] = v49;
  *(v12 + 6) = v14;
  *(v12 + 7) = v13;
  v45 = 0;
  v46 = 0;
  sub_854690(&v45, 0.0, 0.0, 0.0, 1.0);
  v17 = v46;
  v16 = HIDWORD(v46);
  v12[4] = v45;
  *(v12 + 10) = v17;
  *(v12 + 11) = v16;
  v12[6] = 0x42C8000042C80000LL;
  v12[7] = 0x808080803F800000LL;
  v18 = dds3SerializeID();
  v52.x = v10;
  v52.y = v9;
  v52.z = v8;
  v52.w = w;
  v55.x = x;
  v55.y = y;
  v55.z = z;
  v55.w = aRot;
  result = dds3AddEffectObjectBasic(v18, v52, v55);
  pBasic = result;
  if (result)
  {
    v53.x = v10;
    v53.y = v9;
    v53.z = v8;
    v53.w = w;
    SDF_VU0__COPYVECTOR(v12 + 1, v53);
    v54.x = x;
    v54.y = y;
    v54.z = z;
    v54.w = aRot;
    SDF_VU0__COPYVECTOR(v12 + 2, v54);
    else if (p)
    {
      goto LABEL_10;
    }
    Interface = 0;
LABEL_17:
    v26 = effEveBEDCreate(Interface);
    workdata = pBasic->workdata;
    if (workdata)
    {
      klass = workdata->klass;
      if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectObjectBasicWorkData_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3EffectObjectBasicWorkData_t, &v49);
        if ((v49 & 1) != 0)
          v30 = v51;
        else
          v30 = &v49 + 1;
        v31 = sub_8C4940(v30);
      }
    }
    workdata[1].monitor = 0x500000000LL;
    workdata[2].klass = v26;
    workdata[5].klass = 0;
    workdata[3].monitor = 0;
    LODWORD(workdata[4].klass) = 0;
    v32 = Allocate(effEveBEDParams_t);
    effEveBEDParams_t___ctor(v32);
    workdata[4].monitor = v32;
    if (v32)
    {
      v33 = *v32;
      if (*(*v32 + 288) < v34 || *(*(v33 + 200) + 8 * v34 - 8) != effEveBEDParams_t)
      {
        sub_8FC2C0(*(v33 + 64), effEveBEDParams_t, &v49);
        if ((v49 & 1) != 0)
          v35 = v51;
        else
          v35 = &v49 + 1;
        v36 = sub_8C4940(v35);
      }
    }
    effEveBEDParams_t__Copy(v32, v12);
    ControlWorkData = dds3EffectObjectBasicGetControlWorkData(&pBasic);
    ControlWorkData->modelType = 2;
    FastArea = dds3AreaBasicGetFastArea();
    pAreaBasic = FastArea;
    if (FastArea)
    {
      v40 = ControlWorkData->pBasic;
      v41 = FastArea;
      v40->m_Items[5] = v41;
      dds3AreaBasicRegistItem(&pAreaBasic, &pBasic);
    }
    return pBasic;
  }
  return result;
}

// 0x17b0980
dds3Basic_t *AddD3PEffect(effHandle_t **eff, sdfVector4_t pos, sdfVector4_t rot) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  u32 v14;
  dds3Basic_t_o *result;
  dds3Basic_t_o *v17;
  f32 v19;
  f32 v20;
  f32 v21;
  f32 v22;
  dds3EffectObjectBasicWorkData_t_c *v23;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v27;
  s64 *v28;
  effHandle_t_o *v29;
  dds3ObjectBaseControlWorkData_t_o *ControlWorkData;
  dds3Basic_t_o *FastArea;
  struct dds3Basic_t_array *v32;
  dds3Basic_t_o *v33;
  effHandle_t_o *v36;
  UnityEngine_Vector4_o p;
  dds3Basic_t_o *pAreaBasic;
  dds3Basic_t_o *pBasic;
  u64 v40[3];
  UnityEngine_Vector4_o v41;
  UnityEngine_Vector4_o v42;
  UnityEngine_Vector4_o v43;
  UnityEngine_Vector4_o v44;

  w = rot.w;
  z = rot.z;
  y = rot.y;
  x = rot.x;
  v8 = pos.w;
  v9 = pos.z;
  v10 = pos.y;
  v11 = pos.x;
  pAreaBasic = 0;
  pBasic = 0;
  v36 = 0;
  *&p.x = 0;
  *&p.z = 0;
  sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
  v14 = dds3SerializeID();
  v41.x = v11;
  v41.y = v10;
  v41.z = v9;
  v41.w = v8;
  v44.x = x;
  v44.y = y;
  v44.z = z;
  v44.w = w;
  result = dds3AddEffectObjectBasic(v14, v41, v44);
  pBasic = result;
  if (result)
  {
    v42.x = v11;
    v42.y = v10;
    v42.z = v9;
    v42.w = v8;
    v17 = result;
    SDF_VU0__LOADVECTOR(v42);
    SDF_VU0__STOREVECTOR(&p);
    v36 = *eff;
    v20 = p.x;
    v19 = p.y;
    v22 = p.z;
    v21 = p.w;
    v43.x = v20;
    v43.y = v19;
    v43.z = v22;
    v43.w = v21;
    dds3EffectSetPosition(&v36, v43);
    workdata = v17->workdata;
    if (workdata)
    {
      klass = workdata->klass;
      if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectObjectBasicWorkData_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3EffectObjectBasicWorkData_t, v40);
        if ((v40[0] & 1) != 0)
          v27 = v40[2];
        else
          v27 = v40 + 1;
        v28 = sub_8C4940(v27);
      }
    }
    workdata[1].monitor = 0x100000000LL;
    v29 = *eff;
    workdata[3].monitor = 0;
    LODWORD(workdata[4].klass) = 0;
    workdata[2].klass = v29;
    ControlWorkData = dds3EffectObjectBasicGetControlWorkData(&pBasic, v23);
    ControlWorkData->modelType = 2;
    FastArea = dds3AreaBasicGetFastArea();
    pAreaBasic = FastArea;
    if (FastArea)
    {
      v32 = ControlWorkData->pBasic;
      v33 = FastArea;
      v32->m_Items[5] = v33;
      dds3AreaBasicRegistItem(&pAreaBasic, &pBasic);
    }
    return pBasic;
  }
  return result;
}

// 0x17b16f0
dds3Basic_t *AddESPEffect(char *name, sdfVector4_t pos, sdfVector4_t rot, f32 r) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  u32 v14;
  dds3Basic_t_o *v16;
  dds3Basic_t_o *v17;
  s64 p_scl;
  Il2CppObject *workdata;
  dds3EffectObjectBasicWorkData_t_c *v20;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3ObjectBaseControlWorkData_t_o *ControlWorkData;
  dds3Basic_t_o *FastArea;
  struct dds3Basic_t_array *v25;
  dds3Basic_t_o *v26;
  char *v30;
  s64 *v31;
  dds3Basic_t_o *v32;
  dds3Basic_t_o *v33[3];
  dds3Basic_t_o *pBasic;
  UnityEngine_Vector4_o v35;
  UnityEngine_Vector4_o v36;

  w = rot.w;
  z = rot.z;
  y = rot.y;
  x = rot.x;
  v9 = pos.w;
  v10 = pos.z;
  v11 = pos.y;
  v12 = pos.x;
  pBasic = 0;
  v32 = 0;
  v14 = dds3SerializeID();
  v35.x = v12;
  v35.y = v11;
  v35.z = v10;
  v35.w = v9;
  v36.x = x;
  v36.y = y;
  v36.z = z;
  v36.w = w;
  v16 = dds3AddEffectObjectBasic(v14, v35, v36);
  v17 = v16;
  pBasic = v16;
  if (v16)
  {
    p_scl = &v16->poseset->scl;
    v17->name = name;
    sub_854930(p_scl, 0);
    sub_854930(&v17->poseset->scl, 1u);
    sub_854930(&v17->poseset->scl, 2u);
    workdata = v17->workdata;
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3EffectObjectBasicWorkData_t, v33);
      if ((v33[0] & 1) != 0)
        v30 = v33[2];
      else
        v30 = v33 + 1;
      v31 = sub_8C4940(v30);
    }
    workdata[5].klass = 0;
    workdata[1].monitor = 0x600000000LL;
    workdata[2].klass = 0;
    workdata[3].monitor = 0;
    LODWORD(workdata[4].klass) = 0;
    ControlWorkData = dds3EffectObjectBasicGetControlWorkData(&pBasic, v20);
    ControlWorkData->modelType = 2;
    FastArea = dds3AreaBasicGetFastArea();
    v32 = FastArea;
    if (FastArea)
    {
      v25 = ControlWorkData->pBasic;
      v26 = FastArea;
      v25->m_Items[5] = v26;
      dds3AreaBasicRegistItem(&v32, &pBasic);
      return pBasic;
    }
  }
  return v17;
}

// 0x17b1980
dds3Basic_t *AddMG12Effect(s32 type, void *data) {
  u64 *v4;
  s32 v5;
  s32 v6;
  s32 v7;
  s32 v8;
  effMagaP4Point_t_o *v9;
  struct UnityEngine_Vector4_array *v10;
  f32 v11;
  f32 v12;
  f32 v13;
  f32 v15;
  f32 v16;
  f32 v17;
  f32 v19;
  f32 v20;
  f32 v21;
  f32 v23;
  f32 v24;
  f32 v25;
  System_Array_o *v27;
  u32 v30;
  dds3Basic_t_o *result;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v36;
  s64 *v37;
  s32 v38;
  u64 *v39;
  u64 *v41;
  u64 v42;
  s64 v43;
  char *v44;
  s64 *v45;
  effMagaSCArea_t_o *v47;
  effMagaSCArea_t_c *v48;
  s64 v49;
  char *v50;
  s64 *v51;
  u64 *v52;
  u64 v53;
  s64 v54;
  char *v55;
  s64 *v56;
  effMagaP4Point_t_o *monitor;
  effMagaP4Point_t_c *v59;
  s64 v60;
  char *v61;
  s64 *v62;
  dds3ObjectBaseControlWorkData_t_o *ControlWorkData;
  dds3Basic_t_o *FastArea;
  struct dds3Basic_t_array *v65;
  dds3Basic_t_o *v66;
  s64 v69;
  s64 v70;
  s64 v71;
  s64 v72;
  s64 v73;
  s64 v74;
  s64 v75;
  s64 v76;
  u64 v77;
  s64 v78;
  effHandle_t_o *hEffect;
  dds3Basic_t_o *pAreaBasic;
  UnityEngine_Vector4_o v81;
  UnityEngine_Vector4_o v82;
  dds3Basic_t_o *pBasic;
  u64 v84;
  s64 v85;
  char *v86;
  Il2CppObject *pD3P;

  pD3P = data;
  *&v82.x = 0;
  *&v82.z = 0;
  *&v81.x = 0;
  *&v81.z = 0;
  pBasic = 0;
  hEffect = 0;
  pAreaBasic = 0;
  sub_854690(&v82.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v81.x, 0.0, 0.0, 0.0, 1.0);
  v4 = Allocate(effMagaSCArea_t);
  effMagaSCArea_t___ctor(v4);
  v84 = 0;
  v85 = 0;
  sub_854690(&v84, 0.0, 0.0, 0.0, 0.0);
  v6 = v85;
  v5 = HIDWORD(v85);
  v4[2] = v84;
  *(v4 + 6) = v6;
  *(v4 + 7) = v5;
  v77 = 0;
  v78 = 0;
  sub_854690(&v77, 0.0, -500.0, 0.0, 0.0);
  v8 = v78;
  v7 = HIDWORD(v78);
  v4[4] = v77;
  *(v4 + 10) = v8;
  *(v4 + 11) = v7;
  v4[6] = 0x4396000043960000LL;
  v9 = Allocate(effMagaP4Point_t);
  effMagaP4Point_t___ctor(v9);
  v10 = NewSpecific(UnityEngine_Vector4, 4u);
  v75 = 0;
  v76 = 0;
  sub_854690(&v75, 0.0, 0.0, 0.0, 0.0);
  v11 = *(&v75 + 1);
  v13 = *&v76;
  v12 = *(&v76 + 1);
  LODWORD(v10->m_Items[0].x) = v75;
  v10->m_Items[0].y = v11;
  v10->m_Items[0].z = v13;
  v10->m_Items[0].w = v12;
  v73 = 0;
  v74 = 0;
  sub_854690(&v73, 100.0, -200.0, 0.0, 0.0);
  v15 = *(&v73 + 1);
  v17 = *&v74;
  v16 = *(&v74 + 1);
  LODWORD(v10->m_Items[1].x) = v73;
  v10->m_Items[1].y = v15;
  v10->m_Items[1].z = v17;
  v10->m_Items[1].w = v16;
  v71 = 0;
  v72 = 0;
  sub_854690(&v71, 100.0, -400.0, 0.0, 0.0);
  v19 = *(&v71 + 1);
  v21 = *&v72;
  v20 = *(&v72 + 1);
  LODWORD(v10->m_Items[2].x) = v71;
  v10->m_Items[2].y = v19;
  v10->m_Items[2].z = v21;
  v10->m_Items[2].w = v20;
  v69 = 0;
  v70 = 0;
  sub_854690(&v69, 0.0, -600.0, 0.0, 0.0);
  v23 = *(&v69 + 1);
  v25 = *&v70;
  v24 = *(&v70 + 1);
  LODWORD(v10->m_Items[3].x) = v69;
  v10->m_Items[3].y = v23;
  v10->m_Items[3].z = v25;
  v10->m_Items[3].w = v24;
  v9->point = v10;
  v27 = NewSpecific(f32, 4u);
  InitializeArray_1543888(v27, Field__PrivateImplementationDetails__A5B7A621614F37AC762AA3AB6251E4760F02B541);
  v9->radius = v27;
  hEffect = dds3EffectLoad(&pD3P, 0, 0, 0);
  v30 = dds3SerializeID();
  result = dds3AddEffectObjectBasic(v30, v82, v81);
  pBasic = result;
  if (result)
  {
    workdata = result->workdata;
    if (workdata)
    {
      klass = workdata->klass;
      if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectObjectBasicWorkData_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3EffectObjectBasicWorkData_t, &v84);
        if ((v84 & 1) != 0)
          v36 = v86;
        else
          v36 = &v84 + 1;
        v37 = sub_8C4940(v36);
      }
    }
    if (type == 1)
      v38 = 7;
    else
      v38 = 8;
    LODWORD(workdata[1].monitor) = 0;
    HIDWORD(workdata[1].monitor) = v38;
    workdata[2].klass = hEffect;
    workdata[3].monitor = 0;
    LODWORD(workdata[4].klass) = 0;
    v39 = Allocate(dds3Basic_t);
    dds3Basic_t___ctor(v39);
    workdata[5].klass = v39;
    if (type != 1)
    {
      if (type == 2)
      {
        v52 = Allocate(effMagaP4Point_t);
        effMagaP4Point_t___ctor(v52);
        workdata[4].monitor = v52;
        if (v52)
        {
          v53 = *v52;
          if (*(*v52 + 288) < v54 || *(*(v53 + 200) + 8 * v54 - 8) != effMagaP4Point_t)
          {
            sub_8FC2C0(*(v53 + 64), effMagaP4Point_t, &v84);
            if ((v84 & 1) != 0)
              v55 = v86;
            else
              v55 = &v84 + 1;
            v56 = sub_8C4940(v55);
          }
        }
        effMagaP4Point_t__Copy(v52, v9);
        monitor = workdata[4].monitor;
        if (monitor)
        {
          v59 = monitor->klass;
          if (monitor->klass->_2.typeHierarchyDepth < v60
            || v59->_2.typeHierarchy[v60 - 1] != effMagaP4Point_t)
          {
            sub_8FC2C0(v59->_1.element_class, effMagaP4Point_t, &v84);
            if ((v84 & 1) != 0)
              v61 = v86;
            else
              v61 = &v84 + 1;
            v62 = sub_8C4940(v61);
          }
        }
        effMagaP4SetPoint(&hEffect, monitor);
      }
      goto LABEL_65;
    }
    v41 = Allocate(effMagaSCArea_t);
    effMagaSCArea_t___ctor(v41);
    workdata[4].monitor = v41;
    if (v41)
    {
      v42 = *v41;
      if (*(*v41 + 288) < v43 || *(*(v42 + 200) + 8 * v43 - 8) != effMagaSCArea_t)
      {
        sub_8FC2C0(*(v42 + 64), effMagaSCArea_t, &v84);
        if ((v84 & 1) != 0)
          v44 = v86;
        else
          v44 = &v84 + 1;
        v45 = sub_8C4940(v44);
      }
    }
    effMagaSCArea_t__Copy(v41, v4);
    v47 = workdata[4].monitor;
    else if (v47)
    {
LABEL_39:
      v48 = v47->klass;
      if (v47->klass->_2.typeHierarchyDepth < v49
        || v48->_2.typeHierarchy[v49 - 1] != effMagaSCArea_t)
      {
        sub_8FC2C0(v48->_1.element_class, effMagaSCArea_t, &v84);
        if ((v84 & 1) != 0)
          v50 = v86;
        else
          v50 = &v84 + 1;
        v51 = sub_8C4940(v50);
      }
    }
    effMagaSCSetArea(&hEffect, v47);
LABEL_65:
    ControlWorkData = dds3EffectObjectBasicGetControlWorkData(&pBasic);
    ControlWorkData->modelType = 2;
    FastArea = dds3AreaBasicGetFastArea();
    pAreaBasic = FastArea;
    if (FastArea)
    {
      v65 = ControlWorkData->pBasic;
      v66 = FastArea;
      v65->m_Items[5] = v66;
      dds3AreaBasicRegistItem(&pAreaBasic, &pBasic);
    }
    return pBasic;
  }
  return result;
}

// 0x17afb80
dds3Basic_t *AddP2AEffect(billHandle_t **p2a, sdfVector4_t pos, sdfVector4_t rot) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  u32 v14;
  dds3Basic_t_o *result;
  dds3Basic_t_o *v17;
  f32 v19;
  f32 v20;
  f32 v21;
  f32 v22;
  dds3EffectObjectBasicWorkData_t_c *v23;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v27;
  s64 *v28;
  billHandle_t_o *v29;
  dds3ObjectBaseControlWorkData_t_o *ControlWorkData;
  dds3Basic_t_o *FastArea;
  struct dds3Basic_t_array *v32;
  dds3Basic_t_o *v33;
  UnityEngine_Vector4_o p;
  dds3Basic_t_o *pAreaBasic;
  dds3Basic_t_o *pBasic;
  u64 v39[3];
  UnityEngine_Vector4_o v40;
  UnityEngine_Vector4_o v41;
  UnityEngine_Vector4_o v42;
  UnityEngine_Vector4_o v43;

  w = rot.w;
  z = rot.z;
  y = rot.y;
  x = rot.x;
  v8 = pos.w;
  v9 = pos.z;
  v10 = pos.y;
  v11 = pos.x;
  pAreaBasic = 0;
  pBasic = 0;
  *&p.x = 0;
  *&p.z = 0;
  sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
  v14 = dds3SerializeID();
  v40.x = v11;
  v40.y = v10;
  v40.z = v9;
  v40.w = v8;
  v43.x = x;
  v43.y = y;
  v43.z = z;
  v43.w = w;
  result = dds3AddEffectObjectBasic(v14, v40, v43);
  pBasic = result;
  if (result)
  {
    v41.x = v11;
    v41.y = v10;
    v41.z = v9;
    v41.w = v8;
    v17 = result;
    SDF_VU0__LOADVECTOR(v41);
    SDF_VU0__STOREVECTOR(&p);
    v20 = p.x;
    v19 = p.y;
    v22 = p.z;
    v21 = p.w;
    v42.x = v20;
    v42.y = v19;
    v42.z = v22;
    v42.w = v21;
    dds3BillboardSetPosition(p2a, v42);
    workdata = v17->workdata;
    if (workdata)
    {
      klass = workdata->klass;
      if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectObjectBasicWorkData_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3EffectObjectBasicWorkData_t, v39);
        if ((v39[0] & 1) != 0)
          v27 = v39[2];
        else
          v27 = v39 + 1;
        v28 = sub_8C4940(v27);
      }
    }
    workdata[1].monitor = 0x200000000LL;
    v29 = *p2a;
    workdata[3].monitor = 0;
    LODWORD(workdata[4].klass) = 0;
    workdata[2].klass = v29;
    ControlWorkData = dds3EffectObjectBasicGetControlWorkData(&pBasic, v23);
    ControlWorkData->modelType = 2;
    FastArea = dds3AreaBasicGetFastArea();
    pAreaBasic = FastArea;
    if (FastArea)
    {
      v32 = ControlWorkData->pBasic;
      v33 = FastArea;
      v32->m_Items[5] = v33;
      dds3AreaBasicRegistItem(&pAreaBasic, &pBasic);
    }
    return pBasic;
  }
  return result;
}

// 0x17b0300
dds3Basic_t *AddTMXEffect(billHandle_t **tmx, sdfVector4_t pos, sdfVector4_t rot) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  u32 v14;
  dds3Basic_t_o *result;
  dds3Basic_t_o *v17;
  f32 v19;
  f32 v20;
  f32 v21;
  f32 v22;
  dds3EffectObjectBasicWorkData_t_c *v23;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v27;
  s64 *v28;
  billHandle_t_o *v29;
  dds3ObjectBaseControlWorkData_t_o *ControlWorkData;
  dds3Basic_t_o *FastArea;
  struct dds3Basic_t_array *v32;
  dds3Basic_t_o *v33;
  UnityEngine_Vector4_o p;
  dds3Basic_t_o *pAreaBasic;
  dds3Basic_t_o *pBasic;
  u64 v39[3];
  UnityEngine_Vector4_o v40;
  UnityEngine_Vector4_o v41;
  UnityEngine_Vector4_o v42;
  UnityEngine_Vector4_o v43;

  w = rot.w;
  z = rot.z;
  y = rot.y;
  x = rot.x;
  v8 = pos.w;
  v9 = pos.z;
  v10 = pos.y;
  v11 = pos.x;
  pAreaBasic = 0;
  pBasic = 0;
  *&p.x = 0;
  *&p.z = 0;
  sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
  v14 = dds3SerializeID();
  v40.x = v11;
  v40.y = v10;
  v40.z = v9;
  v40.w = v8;
  v43.x = x;
  v43.y = y;
  v43.z = z;
  v43.w = w;
  result = dds3AddEffectObjectBasic(v14, v40, v43);
  pBasic = result;
  if (result)
  {
    v41.x = v11;
    v41.y = v10;
    v41.z = v9;
    v41.w = v8;
    v17 = result;
    SDF_VU0__LOADVECTOR(v41);
    SDF_VU0__STOREVECTOR(&p);
    v20 = p.x;
    v19 = p.y;
    v22 = p.z;
    v21 = p.w;
    v42.x = v20;
    v42.y = v19;
    v42.z = v22;
    v42.w = v21;
    dds3BillboardSetPosition(tmx, v42);
    workdata = v17->workdata;
    if (workdata)
    {
      klass = workdata->klass;
      if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectObjectBasicWorkData_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3EffectObjectBasicWorkData_t, v39);
        if ((v39[0] & 1) != 0)
          v27 = v39[2];
        else
          v27 = v39 + 1;
        v28 = sub_8C4940(v27);
      }
    }
    workdata[1].monitor = 0x300000000LL;
    v29 = *tmx;
    workdata[3].monitor = 0;
    LODWORD(workdata[4].klass) = 0;
    workdata[2].klass = v29;
    ControlWorkData = dds3EffectObjectBasicGetControlWorkData(&pBasic, v23);
    ControlWorkData->modelType = 2;
    FastArea = dds3AreaBasicGetFastArea();
    pAreaBasic = FastArea;
    if (FastArea)
    {
      v32 = ControlWorkData->pBasic;
      v33 = FastArea;
      v32->m_Items[5] = v33;
      dds3AreaBasicRegistItem(&pAreaBasic, &pBasic);
    }
    return pBasic;
  }
  return result;
}

// 0x17b2180
dds3EffectObjectBasicWorkData_t *CheckESP(dds3Basic_t **b) {
  dds3Basic_t_o *v3;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  v3 = *b;
  if (!*b)
    return 0;
  if (DDS3_GETBASICTYPEL(v3) != 7)
    return 0;
  workdata = (*b)->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectObjectBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3EffectObjectBasicWorkData_t, v10);
    if ((v10[0] & 1) != 0)
      v8 = v10[2];
    else
      v8 = v10 + 1;
    v9 = sub_8C4940(v8);
  }
  if (HIDWORD(workdata[1].monitor) == 6)
    return (*b)->workdata;
  else
    return 0;
}

// 0x17adf30
void FreeEffectData(dds3EffectObjectBasicWorkData_t **work) {
  dds3EffectObjectBasicWorkData_t_o *v3;
  Il2CppObject **p_handle;
  Il2CppObject *handle;
  Il2CppObject **v6;
  effEveBEDCutHandle_t_o *cuth;
  effEveBEDCutHandle_t_c *klass;
  s64 typeHierarchyDepth;
  char *v10;
  s64 *v11;
  effBTL_t_o *v12;
  effBTL_t_c *v13;
  s64 v14;
  char *v15;
  s64 *v16;
  Il2CppObject *v17;
  u64 v18[2];
  char *v19;
  Il2CppObject *v20;

  v20 = 0;
  v17 = 0;
  v3 = *work;
  if (*work)
  {
    switch (v3->type)
    {
      case 1:
        handle = v3->handle;
        p_handle = &v3->handle;
        if (handle)
        {
          dds3EffectDelete(p_handle);
          goto LABEL_28;
        }
        break;
      case 2:
        if (v3->handle)
        {
          v20 = v3->handle;
          v6 = &v20;
          goto LABEL_27;
        }
        break;
      case 3:
        if (v3->handle)
        {
          v17 = v3->handle;
          v6 = &v17;
LABEL_27:
          dds3BillboardDelete(v6);
LABEL_28:
          (*work)->handle = 0;
        }
        break;
      case 4:
        if (v3->handle)
          v3->handle = 0;
        break;
      case 5:
        cuth = v3->cuth;
        if (cuth)
        {
          klass = cuth->klass;
          if (cuth->klass->_2.typeHierarchyDepth < typeHierarchyDepth
            || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effEveBEDCutHandle_t)
          {
            sub_8FC2C0(klass->_1.element_class, effEveBEDCutHandle_t, v18);
            if ((v18[0] & 1) != 0)
              v10 = v19;
            else
              v10 = v18 + 1;
            v11 = sub_8C4940(v10);
          }
          effEveBEDCutDelete(cuth);
          (*work)->cuth = 0;
          v3 = *work;
        }
        v12 = v3->handle;
        if (!v12)
          goto LABEL_54;
        v13 = v12->klass;
        if (v12->klass->_2.typeHierarchyDepth < v14 || v13->_2.typeHierarchy[v14 - 1] != effBTL_t)
        {
          sub_8FC2C0(v13->_1.element_class, effBTL_t, v18);
          if ((v18[0] & 1) != 0)
            v15 = v19;
          else
            v15 = v18 + 1;
          v16 = sub_8C4940(v15);
        }
        effEveBEDDelete(v12);
        (*work)->handle = 0;
        goto LABEL_53;
      case 7:
      case 8:
        if (v3->handle)
        {
          dds3EffectDelete(&v3->handle);
          (*work)->handle = 0;
          v3 = *work;
        }
        if (v3->cuth)
        {
          v3->cuth = 0;
LABEL_53:
          v3 = *work;
        }
LABEL_54:
        if (v3->para)
          v3->para = 0;
        break;
      default:
        break;
    }
    (*work)->type = 0;
    (*work)->handle = 0;
  }
}

// 0x17aeef0
billHandle_t *GetBillHandle(void *h, s32 type) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  Il2CppClass *v9;
  s64 v10;
  billHandle_t_o **monitor;
  billHandle_t_o *v12;
  s64 v13;
  char *v15;
  s64 *v16;
  char *v17;
  s64 *v18;
  u64 v19[2];
  char *v20;

  if ((type & 0xFFFFFFFE) == 2)
  {
    if (h)
    {
      klass = h->klass;
      if (h->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != billHandle_t)
      {
        sub_8FC2C0(klass->_1.element_class, billHandle_t, v19);
        if ((v19[0] & 1) != 0)
          v7 = v20;
        else
          v7 = v19 + 1;
        v8 = sub_8C4940(v7);
      }
    }
  }
  else
  {
    v9 = h->klass;
    if (h->klass->_2.typeHierarchyDepth < v10 || v9->_2.typeHierarchy[v10 - 1] != effHandle_t)
    {
      sub_8FC2C0(v9->_1.element_class, effHandle_t, v19);
      if ((v19[0] & 1) != 0)
        v15 = v20;
      else
        v15 = v19 + 1;
      v16 = sub_8C4940(v15);
    }
    monitor = h[1].monitor;
    v12 = *monitor;
    if (LOBYTE((*monitor)[2].scale.x) < v13
      || *(v12[1].pNormal + v13 - 1) != dds3Particle_Basic_t)
    {
      sub_8FC2C0(*&v12->type, dds3Particle_Basic_t, v19);
      if ((v19[0] & 1) != 0)
        v17 = v20;
      else
        v17 = v19 + 1;
      v18 = sub_8C4940(v17);
    }
    return monitor[22];
  }
  return h;
}

// 0x17b22c0
s32 GetESPPos(dds3Basic_t **b) {
  dds3EffectObjectBasicWorkData_t_o *v3;

  v3 = CheckESP(b);
  if (v3)
  {
    SDF_VU0__LOADVECTOR((*b)->poseset->pos, 0);
    LODWORD(v3) = 1;
  }
  return v3;
}

// 0x17b2300
s32 GetESPR(dds3Basic_t **b) {
  dds3EffectObjectBasicWorkData_t_o *v3;
  f32 v4;

  v3 = CheckESP(b);
  if (v3)
  {
    sub_854710(&(*b)->poseset->scl, 0);
    LODWORD(v3) = v4;
  }
  return v3;
}

// 0x17b12b0
dds3Basic_t *dds3AddBEDEffectObjectBasic(char *file, sdfVector4_t pos, sdfVector4_t rot) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  System_String_o *v13;
  System_Byte_array *aTopPtr;
  UnityEngine_Vector4_o v17;
  UnityEngine_Vector4_o v18;

  w = rot.w;
  z = rot.z;
  y = rot.y;
  x = rot.x;
  v8 = pos.w;
  v9 = pos.z;
  v10 = pos.y;
  v11 = pos.x;
  aTopPtr = 0;
  v13 = Concat_5221536("dds3data", file, ".bytes");
  sdfDevLoadFileUnity_25061072(v13, &aTopPtr, 0, "f_bin");
  v17.x = v11;
  v17.y = v10;
  v17.z = v9;
  v17.w = v8;
  v18.x = x;
  v18.y = y;
  v18.z = z;
  v18.w = w;
  return AddBEDEffect(&aTopPtr->obj, v17, v18);
}

// 0x17b12a0
dds3Basic_t *dds3AddBEDEffectObjectBasic2(void *data, sdfVector4_t pos, sdfVector4_t rot) {
  return AddBEDEffect(data, pos, rot);
}

// 0x17b0d40
dds3Basic_t *dds3AddD3PEffectObjectBasic(char *file, sdfVector4_t pos, sdfVector4_t rot) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  effHandle_t_o *v13;
  effHandle_t_o *eff;
  UnityEngine_Vector4_o v17;
  UnityEngine_Vector4_o v18;

  w = rot.w;
  z = rot.z;
  y = rot.y;
  x = rot.x;
  v8 = pos.w;
  v9 = pos.z;
  v10 = pos.y;
  v11 = pos.x;
  eff = 0;
  v13 = dds3EffectFileLoad(file);
  v17.x = v11;
  v17.y = v10;
  v17.z = v9;
  v17.w = v8;
  v18.x = x;
  eff = v13;
  v18.y = y;
  v18.z = z;
  v18.w = w;
  return AddD3PEffect(&eff, v17, v18);
}

// 0x17b0c50
dds3Basic_t *dds3AddD3PEffectObjectBasic2(void *effdata, sdfVector4_t pos, sdfVector4_t rot) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  effHandle_t_o *v12;
  effHandle_t_o *eff;
  Il2CppObject *pD3P;
  UnityEngine_Vector4_o v17;
  UnityEngine_Vector4_o v18;

  w = rot.w;
  z = rot.z;
  y = rot.y;
  x = rot.x;
  v8 = pos.w;
  v9 = pos.z;
  v10 = pos.y;
  v11 = pos.x;
  pD3P = effdata;
  eff = 0;
  v12 = dds3EffectLoad(&pD3P, 0, 0, 0);
  v17.x = v11;
  v17.y = v10;
  v17.z = v9;
  v17.w = v8;
  v18.x = x;
  eff = v12;
  v18.y = y;
  v18.z = z;
  v18.w = w;
  return AddD3PEffect(&eff, v17, v18);
}

// 0x17b1970
dds3Basic_t *dds3AddESPEffectObjectBasic(char *name, sdfVector4_t pos, sdfVector4_t rot, f32 r) {
  return AddESPEffect(name, pos, rot, r);
}

// 0x17af9a0
dds3Basic_t *dds3AddEffectObjectBasic(u32 serialID, sdfVector4_t aPos, sdfVector4_t aRot) {
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
  char *v18;
  s64 *v19;
  dds3Basic_t_o *v20;
  u64 v21[3];
  UnityEngine_Vector4_o v22;
  UnityEngine_Vector4_o v23;

  w = aRot.w;
  z = aRot.z;
  y = aRot.y;
  x = aRot.x;
  v8 = aPos.w;
  v9 = aPos.z;
  v10 = aPos.y;
  v11 = aPos.x;
  v20 = 0;
  result = dds3AddSceneBasicData(7u);
  v20 = result;
  if (result)
  {
    result->serialID = serialID;
    dds3ObjectBaseCreateMover(&v20);
    v22.x = v11;
    v22.y = v10;
    v22.z = v9;
    v22.w = v8;
    dds3SetPosPoseSet(&v20, v22);
    v23.x = x;
    v23.y = y;
    v23.z = z;
    v23.w = w;
    dds3SetRotPoseSet(&v20, v23);
    dds3BackupPoseSet(&v20->poseset);
    result = v20;
    workdata = v20->workdata;
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3EffectObjectBasicWorkData_t, v21);
      if ((v21[0] & 1) != 0)
        v18 = v21[2];
      else
        v18 = v21 + 1;
      v19 = sub_8C4940(v18);
    }
    workdata[1].monitor = 0;
    workdata[2].klass = 0;
    workdata[3].monitor = 0;
    LODWORD(workdata[4].klass) = 0;
  }
  return result;
}

// 0x17b2170
dds3Basic_t *dds3AddMG12EffectObjectBasic(s32 type, char *file) {
  return AddMG12Effect(type, 0);
}

// 0x17b2160
dds3Basic_t *dds3AddMG12EffectObjectBasic2(s32 type, void *effdata) {
  return AddMG12Effect(type, effdata);
}

// 0x17b00d0
dds3Basic_t *dds3AddP2AEffectObjectBasic(char *file, sdfVector4_t pos, sdfVector4_t rot, char *akey) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  billHandle_t_o *v15;
  billHandle_t_o *p2a;
  UnityEngine_Vector4_o v19;
  UnityEngine_Vector4_o v20;

  w = rot.w;
  z = rot.z;
  y = rot.y;
  x = rot.x;
  v9 = pos.w;
  v10 = pos.z;
  v11 = pos.y;
  v12 = pos.x;
  p2a = 0;
  v15 = dds3BillboardFileLoad(1, file, akey);
  v19.x = v12;
  v19.y = v11;
  v19.z = v10;
  v19.w = v9;
  v20.x = x;
  p2a = v15;
  v20.y = y;
  v20.z = z;
  v20.w = w;
  return AddP2AEffect(&p2a, v19, v20);
}

// 0x17affd0
dds3Basic_t *dds3AddP2AEffectObjectBasic2(void *effdata, sdfVector4_t pos, sdfVector4_t rot) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  billHandle_t_o *v13;
  billHandle_t_o *p2a;
  UnityEngine_Vector4_o v17;
  UnityEngine_Vector4_o v18;

  w = rot.w;
  z = rot.z;
  y = rot.y;
  x = rot.x;
  v8 = pos.w;
  v9 = pos.z;
  v10 = pos.y;
  v11 = pos.x;
  p2a = 0;
  v13 = dds3BillboardCreate(1, effdata, 0, "");
  v17.x = v11;
  v17.y = v10;
  v17.z = v9;
  v17.w = v8;
  v18.x = x;
  p2a = v13;
  v18.y = y;
  v18.z = z;
  v18.w = w;
  return AddP2AEffect(&p2a, v17, v18);
}

// 0x17afe40
dds3Basic_t *dds3AddP2AEffectObjectBasic3(dds3Basic_t **ebasic, sdfVector4_t pos, sdfVector4_t rot) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  billHandle_t_o *BillHandle;
  billHandle_t_o *v19;
  char *v22;
  s64 *v23;
  billHandle_t_o *v24;
  u64 v25[3];
  UnityEngine_Vector4_o v26;
  UnityEngine_Vector4_o v27;

  w = rot.w;
  z = rot.z;
  y = rot.y;
  x = rot.x;
  v9 = pos.w;
  v10 = pos.z;
  v11 = pos.y;
  v12 = pos.x;
  v24 = 0;
  workdata = (*ebasic)->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectObjectBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3EffectObjectBasicWorkData_t, v25);
    if ((v25[0] & 1) != 0)
      v22 = v25[2];
    else
      v22 = v25 + 1;
    v23 = sub_8C4940(v22);
  }
  BillHandle = GetBillHandle(workdata[2].klass, HIDWORD(workdata[1].monitor));
  v19 = dds3BillboardCopy(BillHandle);
  v26.x = v12;
  v26.y = v11;
  v26.z = v10;
  v26.w = v9;
  v27.x = x;
  v24 = v19;
  v27.y = y;
  v27.z = z;
  v27.w = w;
  return AddP2AEffect(&v24, v26, v27);
}

// 0x17b0850
dds3Basic_t *dds3AddTMXEffectObjectBasic(char *file, sdfVector4_t pos, sdfVector4_t rot, char *akey) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  billHandle_t_o *v16;
  billHandle_t_o *tmx;
  UnityEngine_Vector4_o v20;
  UnityEngine_Vector4_o v21;

  w = rot.w;
  z = rot.z;
  y = rot.y;
  x = rot.x;
  v9 = pos.w;
  v10 = pos.z;
  v11 = pos.y;
  v12 = pos.x;
  tmx = 0;
  Write_2930400("LoadFile:{0}\n", file);
  v16 = dds3BillboardFileLoad(0, file, akey);
  v20.x = v12;
  v20.y = v11;
  v20.z = v10;
  v20.w = v9;
  v21.x = x;
  tmx = v16;
  v21.y = y;
  v21.z = z;
  v21.w = w;
  return AddTMXEffect(&tmx, v20, v21);
}

// 0x17b0750
dds3Basic_t *dds3AddTMXEffectObjectBasic2(void *effdata, sdfVector4_t pos, sdfVector4_t rot) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  billHandle_t_o *v13;
  billHandle_t_o *tmx;
  UnityEngine_Vector4_o v17;
  UnityEngine_Vector4_o v18;

  w = rot.w;
  z = rot.z;
  y = rot.y;
  x = rot.x;
  v8 = pos.w;
  v9 = pos.z;
  v10 = pos.y;
  v11 = pos.x;
  tmx = 0;
  v13 = dds3BillboardCreate(0, effdata, 0, "");
  v17.x = v11;
  v17.y = v10;
  v17.z = v9;
  v17.w = v8;
  v18.x = x;
  tmx = v13;
  v18.y = y;
  v18.z = z;
  v18.w = w;
  return AddTMXEffect(&tmx, v17, v18);
}

// 0x17b05c0
dds3Basic_t *dds3AddTMXEffectObjectBasic3(dds3Basic_t **ebasic, sdfVector4_t pos, sdfVector4_t rot) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  billHandle_t_o *BillHandle;
  billHandle_t_o *v19;
  char *v22;
  s64 *v23;
  billHandle_t_o *v24;
  u64 v25[3];
  UnityEngine_Vector4_o v26;
  UnityEngine_Vector4_o v27;

  w = rot.w;
  z = rot.z;
  y = rot.y;
  x = rot.x;
  v9 = pos.w;
  v10 = pos.z;
  v11 = pos.y;
  v12 = pos.x;
  v24 = 0;
  workdata = (*ebasic)->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectObjectBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3EffectObjectBasicWorkData_t, v25);
    if ((v25[0] & 1) != 0)
      v22 = v25[2];
    else
      v22 = v25 + 1;
    v23 = sub_8C4940(v22);
  }
  BillHandle = GetBillHandle(workdata[2].klass, HIDWORD(workdata[1].monitor));
  v19 = dds3BillboardCopy(BillHandle);
  v26.x = v12;
  v26.y = v11;
  v26.z = v10;
  v26.w = v9;
  v27.x = x;
  v24 = v19;
  v27.y = y;
  v27.z = z;
  v27.w = w;
  return AddTMXEffect(&v24, v26, v27);
}

// 0x17af400
void dds3EffectObjectBasicCalcFldEx(dds3Basic_t **basic) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u32 *monitor;
  s32 v12;
  s32 v13;
  u32 v14;
  s32 v15;
  f32 *static_fields;
  f32 v18;
  f32 v19;
  f32 v20;
  f32 v21;
  u64 v22;
  s32 v23;
  f32 v25;
  u32 v26;
  f32 v27;
  s32 v29;
  s32 EAnimeCngID;
  s32 v33;
  s32 v34;
  billHandle_t_o *BillHandle;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v37;
  u64 v38[3];

  *&v37.x = 0;
  *&v37.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  BillHandle = 0;
  sub_854690(&v37.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
  workdata = (*basic)->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3EffectObjectBasicWorkData_t, v38);
      if ((v38[0] & 1) != 0)
        v7 = v38[2];
      else
        v7 = v38 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  if ((workdata[1].monitor & 0x10) != 0)
  {
    monitor = workdata[6].monitor;
    v10 = monitor[11];
    if ()
    {
      v12 = fldGbChkEView(fldGb->fieldID, fldGb->areaID + 1, 0);
      v13 = workdata[1].monitor;
      v14 = v13 & 0xFFFFFFFE;
      v15 = v13 | 1;
      if (v12)
        v15 = v14;
      LODWORD(workdata[1].monitor) = v15;
    }
    v18 = static_fields[39] - *(&workdata[7].klass + 1);
    v19 = static_fields[38] - *&workdata[7].klass;
    v20 = static_fields[40] - *&workdata[7].monitor;
    v21 = sqrtf(((v19 * v19) + (v18 * v18)) + (v20 * v20));
    if (monitor[10])
    {
      sub_854930(&v37, 0);
      sub_854930(&v37, 1u);
      sub_854930(&v37, 2u);
      sub_854930(&v37, 3u);
      SDF_VU0__LOADVECTOR(v37);
      SDF_VU0__NORMALIZE();
      SDF_VU0__STOREVECTOR(&p);
      LODWORD(v22) = monitor[10];
      *&v22 = v22;
      (*basic)->poseset->pos.x = *&workdata[7].klass - (p.x * *&v22);
      (*basic)->poseset->pos.y = *(&workdata[7].klass + 1) - (p.y * *&v22);
      (*basic)->poseset->pos.z = *&workdata[7].monitor - (p.z * *&v22);
    }
    v23 = monitor[5];
    if (v23 == 3)
    {
LABEL_29:
      BillHandle = GetBillHandle(workdata[2].klass, HIDWORD(workdata[1].monitor));
      if (*(monitor + 6))
      {
        v25 = monitor[12];
        v26 = 8421504;
        if (v21 >= v25)
        {
          v27 = monitor[13];
          if (v21 <= v27)
          {
            v34 = (((v21 - v25) * 128.0) / (v27 - v25));
            if (v34 >= 128)
              v34 = 128;
            v26 = ((v34 & ~(v34 >> 31)) << 24) | 0x808080;
          }
          else
          {
            v26 = -2139062144;
          }
        }
        dds3BillboardSetRGBA(&BillHandle, v26);
      }
      return;
    }
    if (v23 != 1)
    {
      if (v23)
        return;
      goto LABEL_29;
    }
    BillHandle = GetBillHandle(workdata[2].klass, HIDWORD(workdata[1].monitor));
    v29 = monitor[11];
    if (v29)
    {
      EAnimeCngID = fldGbGetEAnimeCngID(fldGb->fieldID, fldGb->areaID + 1, v29);
      if (EAnimeCngID != -1)
      {
        v33 = EAnimeCngID;
        dds3BillboardSetAnimNumber(&BillHandle, v33);
      }
    }
  }
}

// 0x17adbe0
s32 dds3EffectObjectBasicConstructor(dds3Basic_t *aPtr) {
  dds3Basic_t_o *v2;
  u64 *v3;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  Il2CppObject *v9;
  dds3ObjectBaseControlWorkData_t_o *inited;
  Il2CppClass *v11;
  s64 v12;
  char *v14;
  s64 *v15;
  u64 v16[2];
  char *v17;
  dds3Basic_t_o *basic;

  basic = aPtr;
  dds3InitPoseSet(&basic);
  v2 = basic;
  v3 = Allocate(dds3EffectObjectBasicWorkData_t);
  dds3EffectObjectBasicWorkData_t___ctor(v3);
  v2->workdata = v3;
  workdata = basic->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3EffectObjectBasicWorkData_t, v16);
      if ((v16[0] & 1) != 0)
        v7 = v17;
      else
        v7 = v16 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  dds3EffectObjectBasicWorkData_t__Clear(workdata);
  v9 = basic->workdata;
  inited = dds3ObjectBaseInitControlWorkData(&basic);
  v11 = v9->klass;
  if (v9->klass->_2.typeHierarchyDepth < v12
    || v11->_2.typeHierarchy[v12 - 1] != dds3EffectObjectBasicWorkData_t)
  {
    sub_8FC2C0(v11->_1.element_class, dds3EffectObjectBasicWorkData_t, v16);
    if ((v16[0] & 1) != 0)
      v14 = v17;
    else
      v14 = v16 + 1;
    v15 = sub_8C4940(v14);
  }
  v9[1].klass = inited;
  dds3ObjectBaseOnFlag(&basic, 0x60u, 0);
  return 1;
}

// 0x17adde0
s32 dds3EffectObjectBasicDestructor(dds3Basic_t *aPtr) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *p_workdata;
  dds3EffectObjectBasicWorkData_t_o *work;
  dds3Basic_t_o *basic;
  u64 v13[3];

  basic = aPtr;
  work = 0;
  if (aPtr)
  {
    workdata = aPtr->workdata;
    if (workdata)
    {
      klass = workdata->klass;
      if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectObjectBasicWorkData_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3EffectObjectBasicWorkData_t, v13);
        if ((v13[0] & 1) != 0)
          v6 = v13[2];
        else
          v6 = v13 + 1;
        v7 = sub_8C4940(v6);
      }
      work = aPtr->workdata;
      FreeEffectData(&work, dds3EffectObjectBasicWorkData_t);
      dds3FreePoseSet(&basic);
      dds3ObjectBaseFreeControlWorkData(&work->pObjectBaseControlWorkData);
      p_workdata = &basic->workdata;
    }
    else
    {
      p_workdata = &work;
    }
    *p_workdata = 0;
  }
  return 0;
}

// 0x17af110
s32 dds3EffectObjectBasicDrawProcedure(dds3Basic_t *aPtr) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppObject *v11;
  s32 v12;
  Il2CppClass *v14;
  u64 *image;
  s64 v16;
  char *v17;
  s64 *v18;
  effEveBEDCutHandle_t_o *hEveBEDCut;
  Il2CppObject *hData;
  Il2CppObject *pData;
  dds3Basic_t_o *basic;
  u64 v23[2];
  char *v24;

  basic = aPtr;
  hData = 0;
  pData = 0;
  hEveBEDCut = 0;
  workdata = aPtr->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3EffectObjectBasicWorkData_t, v23);
      if ((v23[0] & 1) != 0)
        v6 = v24;
      else
        v6 = v23 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  dds3EffectObjectBasicCalcFldEx(&basic);
  if (!dds3ObjectBaseCheckFlag(&basic, 1u))
  {
    hData = 0;
    pData = 0;
    switch (HIDWORD(workdata[1].monitor))
    {
      case 1:
      case 7:
      case 8:
        if (workdata[2].klass)
        {
          pData = workdata[2].klass;
          if ((workdata[1].monitor & 1) != 0)
          {
            dds3EffectDraw(&pData);
          }
          else
          {
            dds3EffectDrawOff(&pData);
          }
        }
        break;
      case 2:
        v11 = workdata[2].klass;
        if (v11)
        {
          v12 = 2;
          goto LABEL_23;
        }
        break;
      case 3:
        v11 = workdata[2].klass;
        if (v11)
        {
          v12 = 3;
LABEL_23:
          hData = GetBillHandle(v11, v12);
          if ((workdata[1].monitor & 1) != 0)
          {
            dds3BillboardDraw(&hData);
          }
          else
          {
            dds3BillboardDrawOff(&hData);
          }
        }
        break;
      case 5:
        v14 = workdata[5].klass;
        if (v14)
        {
          image = v14->_1.image;
          if (*(v14->_1.image + 288) < v16 || *(image[25] + 8 * v16 - 8) != effEveBEDCutHandle_t)
          {
            sub_8FC2C0(image[8], effEveBEDCutHandle_t, v23);
            if ((v23[0] & 1) != 0)
              v17 = v24;
            else
              v17 = v23 + 1;
            v18 = sub_8C4940(v17);
          }
          hEveBEDCut = workdata[5].klass;
          if ((workdata[1].monitor & 1) != 0)
          {
            effEveBEDCutDraw(&hEveBEDCut);
          }
        }
        break;
      default:
        return 1;
    }
  }
  return 1;
}

// 0x17af880
dds3ObjectBaseControlWorkData_t *dds3EffectObjectBasicGetControlWorkData(dds3Basic_t **pBasic) {
  dds3ObjectBaseControlWorkData_t_o **workdata;
  dds3ObjectBaseControlWorkData_t_o *v4;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v9[3];

  workdata = (*pBasic)->workdata;
  if (!workdata)
    return 0;
  v4 = *workdata;
  if (LOBYTE((*workdata)[2].MotMode) < typeHierarchyDepth
    || *(v4[1].sdwnodeidx + typeHierarchyDepth - 1) != dds3EffectObjectBasicWorkData_t)
  {
    sub_8FC2C0(v4->pModelRangeRootNode, dds3EffectObjectBasicWorkData_t, v9);
    if ((v9[0] & 1) != 0)
      v6 = v9[2];
    else
      v6 = v9 + 1;
    v7 = sub_8C4940(v6);
  }
  return workdata[2];
}

// 0x17aec30
void dds3EffectObjectBasicGetObjectIndex(dds3Basic_t **basic) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3Basic_t_o *monitor;
  s64 v9;
  s64 v10;
  char *v11;
  s64 *v12;
  u64 v13[2];
  char *v14;

  workdata = (*basic)->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3EffectObjectBasicWorkData_t, v13);
      if ((v13[0] & 1) != 0)
        v6 = v14;
      else
        v6 = v13 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  if ((workdata[1].monitor & 8) != 0)
  {
    monitor = workdata[3].monitor;
    if (DDS3_GETBASICTYPEL(monitor) == 5)
    {
      v9 = **(workdata[3].monitor + 7);
      if (*(v9 + 288) < v10 || *(*(v9 + 200) + 8 * v10 - 8) != dds3UnitObjectBasicWorkData_t)
      {
        sub_8FC2C0(*(v9 + 64), dds3UnitObjectBasicWorkData_t, v13);
        if ((v13[0] & 1) != 0)
          v11 = v14;
        else
          v11 = v13 + 1;
        v12 = sub_8C4940(v11);
      }
    }
  }
}

// 0x17b2f60
s32 dds3EffectObjectBasicLinkObject(dds3Basic_t **basic, dds3Basic_t **target) {
  dds3Basic_t_o *v5;
  u32 v6;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3Basic_t_o *v11;
  s32 result;
  char *v13;
  s64 *v14;
  u64 v15[3];

  v5 = *target;
  v6 = DDS3_GETBASICTYPEL(v5);
  if (v6 - 4 >= 6 && v6 != 17)
    return 0;
  workdata = (*basic)->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectObjectBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3EffectObjectBasicWorkData_t, v15);
    if ((v15[0] & 1) != 0)
      v13 = v15[2];
    else
      v13 = v15 + 1;
    v14 = sub_8C4940(v13);
  }
  LODWORD(workdata[1].monitor) = workdata[1].monitor & 0xFFFFFFF3 | 4;
  workdata[3].monitor = *target;
  v11 = *target;
  WORD1(workdata[4].klass) = DDS3_GETBASICTYPEL(v11);
  result = 1;
  LOWORD(workdata[4].klass) = 0;
  workdata[2].monitor = 0;
  LODWORD(workdata[3].klass) = 0;
  return result;
}

// 0x17b30f0
s32 dds3EffectObjectBasicLinkObjectIndex(dds3Basic_t **basic, dds3Basic_t **target, s32 index) {
  s16 v4;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  u64 v13[3];

  v4 = index;
  if (dds3EffectObjectBasicLinkObject(basic, target, *&index))
  {
    workdata = (*basic)->workdata;
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3EffectObjectBasicWorkData_t, v13);
      if ((v13[0] & 1) != 0)
        v11 = v13[2];
      else
        v11 = v13 + 1;
      v12 = sub_8C4940(v11);
    }
    LODWORD(workdata[1].monitor) |= 8u;
    LOWORD(workdata[4].klass) = v4;
  }
  return 1;
}

// 0x17ae290
s32 dds3EffectObjectBasicMainProcedure(dds3Basic_t *aPtr) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3PoseSet_t_o **p_poseset;
  s32 v9;
  u32 v12;
  effHandle_t_o *v13;
  effHandle_t_c *v14;
  s64 v15;
  char *v16;
  s64 *v17;
  s32 monitor;
  s32 v21;
  dds3Basic_t_o *v22;
  s32 v24;
  s64 v25;
  Il2CppClass *v26;
  billHandle_t_o *v27;
  f32 v29;
  f32 v30;
  f32 v31;
  f32 v32;
  billHandle_t_o *BillHandle;
  billHandle_t_o *v35;
  f32 v36;
  f32 v37;
  f32 v38;
  f32 v39;
  Il2CppClass *v40;
  u64 *image;
  s64 v42;
  char *v43;
  s64 *v44;
  s32 v47;
  s64 v48;
  Il2CppClass *v49;
  dds3PoseSet_t_o **v51;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  effEveBEDParams_t_o *v56;
  effEveBEDParams_t_c *v57;
  s64 v58;
  char *v59;
  s64 *v60;
  char *v62;
  s64 *v63;
  char *v64;
  s64 *v65;
  UnityEngine_Matrix4x4_o v66;
  Il2CppObject *pData;
  dds3Basic_t_o *scene;
  effEveBEDCutHandle_t_o *hEveBEDCut;
  billHandle_t_o *hBillboard;
  billHandle_t_o *v71;
  UnityEngine_Vector4_o v72;
  UnityEngine_Vector4_o p;
  UnityEngine_Matrix4x4_o aMatrix;
  dds3Basic_t_o *pBasic;
  u64 v76[2];
  char *v77;
  UnityEngine_Vector4_o v78;
  UnityEngine_Vector4_o v79;
  UnityEngine_Vector4_o v80;
  UnityEngine_Vector4_o v81;
  UnityEngine_Vector4_o v82;

  pBasic = aPtr;
  *&p.x = 0;
  *&p.z = 0;
  *&v72.x = 0;
  *&v72.z = 0;
  pData = 0;
  hBillboard = 0;
  v71 = 0;
  scene = 0;
  hEveBEDCut = 0;
  memset(&aMatrix, 0, sizeof(aMatrix));
  sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v72.x, 0.0, 0.0, 0.0, 1.0);
  workdata = pBasic->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3EffectObjectBasicWorkData_t, v76);
      if ((v76[0] & 1) != 0)
        v6 = v77;
      else
        v6 = v76 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  if ((workdata[1].monitor & 4) == 0)
  {
    p_poseset = &pBasic->poseset;
    v9 = 1;
    dds3OffPoseSetFlag(p_poseset, 1u);
    dds3GetPosPoseSetMCR(&pBasic);
    SDF_VU0__STOREVECTOR(&p);
    dds3BackupPoseSet(&pBasic->poseset);
    dds3GetRotPoseSetMCR(&pBasic);
    SDF_VU0__STOREVECTOR(&v72);
    v12 = HIDWORD(workdata[1].monitor) - 1;
LABEL_15:
    switch (v12)
    {
      case 0u:
        v13 = workdata[2].klass;
        if (v13)
        {
          v14 = v13->klass;
          if (v13->klass->_2.typeHierarchyDepth < v15
            || v14->_2.typeHierarchy[v15 - 1] != effHandle_t)
          {
            sub_8FC2C0(v14->_1.element_class, effHandle_t, v76);
            if ((v76[0] & 1) != 0)
              v16 = v77;
            else
              v16 = v76 + 1;
            v17 = sub_8C4940(v16);
          }
          if (v9)
          {
            pData = workdata[2].klass;
            x = p.x;
            y = p.y;
            z = p.z;
            w = p.w;
            v82.x = x;
            v82.y = y;
            v82.z = z;
            v82.w = w;
            dds3EffectSetPosition(&pData, v82);
            SDF_VU0__LOADVECTOR(v72);
            ToMatrix();
            SDF_VU0__STOREMATRIX(&aMatrix);
            v66 = aMatrix;
            dds3EffectSetRotateMatrix(&pData, &v66);
          }
        }
        if (!dds3EffectGetState(v13))
          goto LABEL_27;
        break;
      case 1u:
        BillHandle = GetBillHandle(workdata[2].klass, 2);
        v35 = BillHandle;
        v71 = BillHandle;
        if (v9 && BillHandle)
        {
          v37 = p.x;
          v36 = p.y;
          v39 = p.z;
          v38 = p.w;
          v80.x = v37;
          v80.y = v36;
          v80.z = v39;
          v80.w = v38;
          dds3BillboardSetPosition(&v71, v80);
          v35 = v71;
        }
        if (!dds3BillboardGetAnimState(v35))
        {
LABEL_27:
          monitor = workdata[1].monitor;
          LODWORD(workdata[1].monitor) = monitor & 0xFFFFFFFE;
          if ((monitor & 2) != 0)
          {
            dds3DeleteSceneBasicData(&pBasic);
          }
        }
        break;
      case 2u:
        v27 = GetBillHandle(workdata[2].klass, 3);
        hBillboard = v27;
        if (v9 && v27)
        {
          v30 = p.x;
          v29 = p.y;
          v32 = p.z;
          v31 = p.w;
          v79.x = v30;
          v79.y = v29;
          v79.z = v32;
          v79.w = v31;
          dds3BillboardSetPosition(&hBillboard, v79);
        }
        break;
      case 4u:
        v40 = workdata[5].klass;
        if (v40)
        {
          image = v40->_1.image;
          if (*(v40->_1.image + 288) < v42 || *(image[25] + 8 * v42 - 8) != effEveBEDCutHandle_t)
          {
            sub_8FC2C0(image[8], effEveBEDCutHandle_t, v76);
            if ((v76[0] & 1) != 0)
              v43 = v77;
            else
              v43 = v76 + 1;
            v44 = sub_8C4940(v43);
          }
          hEveBEDCut = workdata[5].klass;
          if (v9)
          {
            v56 = workdata[4].monitor;
            if (v56)
            {
              v57 = v56->klass;
              if (v56->klass->_2.typeHierarchyDepth < v58
                || v57->_2.typeHierarchy[v58 - 1] != effEveBEDParams_t)
              {
                sub_8FC2C0(v57->_1.element_class, effEveBEDParams_t, v76);
                if ((v76[0] & 1) != 0)
                  v59 = v77;
                else
                  v59 = v76 + 1;
                v60 = sub_8C4940(v59);
              }
              SDF_VU0__COPYVECTOR(&v56->center, p);
              SDF_VU0__COPYVECTOR(&v56->rot, v72);
              effEveBEDCutSetParams(&hEveBEDCut, v56);
            }
          }
        }
        else
        {
          hEveBEDCut = 0;
        }
        break;
      default:
        return 1;
    }
    return 1;
  }
  scene = dds3GetActiveScene();
  v21 = WORD1(workdata[4].klass);
  v22 = workdata[3].monitor;
  if (!dds3SceneBasicExistBasicFromType(&scene, v21, v22))
  {
    dds3EffectObjectBasicUnlinkObject(&pBasic);
    v9 = 0;
    v12 = HIDWORD(workdata[1].monitor) - 1;
    if (v12 > 4)
      return 1;
    goto LABEL_15;
  }
  if ((workdata[1].monitor & 8) != 0)
  {
    dds3EffectObjectBasicGetObjectIndex(&pBasic);
  }
  else
  {
    v24 = WORD1(workdata[4].klass);
    if ((v24 - 4) < 6)
    {
      v78 = *(*(workdata[3].monitor + 8) + 40LL);
    }
    else
    {
      if (v24 != 17)
      {
        SDF_VU0__LOADIDENTITY();
        goto LABEL_78;
      }
      v25 = *(workdata[3].monitor + 7);
      if (!v25)
        sub_8C38A0();
      v26 = *(*v25 + 64LL);
      {
        sub_8FC2C0(v26, fldResourcePoint_t, v76);
        if ((v76[0] & 1) != 0)
          v62 = v77;
        else
          v62 = v76 + 1;
        v63 = sub_8C4940(v62);
      }
      v78 = *(sub_8D3F90(*(workdata[3].monitor + 7)) + 16);
    }
    SDF_VU0__LOADVECTOR(v78);
    SDF_VU0__STOREVECTOR(&v72);
    ToMatrix();
  }
LABEL_78:
  SDF_VU0__COPYMATRIX_A_TO_B();
  SDF_VU0__LOADIDENTITY();
  SDF_VU0__LOADVECTOR(*(workdata + 40), 0);
  SDF_VU0__VECTOR_W_SET_ONE();
  SDF_VU0__TRANSLATE();
  MultMatrixRevNoArg();
  SDF_VU0__LOADIDENTITYVECTOR();
  SDF_VU0__APPLYMATRIX();
  if ((workdata[1].monitor & 8) == 0)
  {
    v47 = WORD1(workdata[4].klass);
    if ((v47 - 4) < 6)
    {
      v81 = *(*(workdata[3].monitor + 8) + 24LL);
LABEL_89:
      SDF_VU0__LOADVECTOR_B(v81);
      SDF_VU0__ADDVECTOR();
      goto LABEL_90;
    }
    if (v47 == 17)
    {
      v48 = *(workdata[3].monitor + 7);
      if (!v48)
        sub_8C38A0();
      v49 = *(*v48 + 64LL);
      {
        sub_8FC2C0(v49, fldResourcePoint_t, v76);
        if ((v76[0] & 1) != 0)
          v64 = v77;
        else
          v64 = v76 + 1;
        v65 = sub_8C4940(v64);
      }
      v81 = *sub_8D3F90(*(workdata[3].monitor + 7));
      goto LABEL_89;
    }
  }
LABEL_90:
  SDF_VU0__STOREVECTOR(&p);
  v51 = &pBasic->poseset;
  dds3BackupPoseSet(v51);
  SDF_VU0__STOREVECTOR(&pBasic->poseset->pos);
  v9 = 1;
  dds3OffPoseSetFlag(&pBasic->poseset, 1u);
  v12 = HIDWORD(workdata[1].monitor) - 1;
  if (v12 <= 4)
    goto LABEL_15;
  return 1;
}

// 0x17b01c0
void dds3EffectObjectBasicSetAnmeID(dds3Basic_t **basic, s32 animeID) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  billHandle_t_o *v11[3];
  billHandle_t_o *hBillboard;

  hBillboard = 0;
  workdata = (*basic)->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectObjectBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3EffectObjectBasicWorkData_t, v11);
    if ((v11[0] & 1) != 0)
      v9 = v11[2];
    else
      v9 = v11 + 1;
    v10 = sub_8C4940(v9);
  }
  hBillboard = GetBillHandle(workdata[2].klass, HIDWORD(workdata[1].monitor));
  dds3BillboardSetAnimNumber(&hBillboard, animeID);
}

// 0x17b3210
void dds3EffectObjectBasicSetFldEx(dds3Basic_t **basic, fldResourceEffect_t **pResEff) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  s32 v11;
  s64 v13;
  u32 v14;
  f32 v15;
  f32 v17;
  u32 *monitor;
  billHandle_t_o *v20;
  s32 v21;
  s16 v22;
  s32 v24;
  billHandle_t_o *v26[3];
  billHandle_t_o *hBillboard;

  hBillboard = 0;
  workdata = (*basic)->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3EffectObjectBasicWorkData_t, v26);
      if ((v26[0] & 1) != 0)
        v8 = v26[2];
      else
        v8 = v26 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  workdata[6].monitor = *pResEff;
  *&workdata[7].klass = (*basic)->poseset->pos.x;
  HIDWORD(workdata[7].klass) = LODWORD((*basic)->poseset->pos.y);
  *&workdata[7].monitor = (*basic)->poseset->pos.z;
  HIDWORD(workdata[7].monitor) = LODWORD((*basic)->poseset->pos.w);
  dds3EffectObjectBasicStatOn(basic, 0x10u);
  v11 = *(workdata[6].monitor + 5);
  if (v11 != 3)
  {
    if (v11 == 1)
    {
      hBillboard = GetBillHandle(workdata[2].klass, HIDWORD(workdata[1].monitor));
      v24 = *(workdata[6].monitor + 12);
      dds3BillboardSetAnimNumber(&hBillboard, v24);
      return;
    }
    if (v11)
      return;
  }
  hBillboard = GetBillHandle(workdata[2].klass, HIDWORD(workdata[1].monitor));
  v13 = *(workdata[6].monitor + 4);
  v14 = *(v13 + 24);
  v15 = *(v13 + 32);
  v17 = *(*(workdata[6].monitor + 4) + 36LL);
  dds3BillboardSetXYOffset(&hBillboard, v15, v17);
  monitor = workdata[6].monitor;
  if (monitor[5] == 3)
  {
    v20 = hBillboard;
    dds3BillboardSetDrawType(v20, 1u);
    monitor = workdata[6].monitor;
  }
  v21 = monitor[4];
  if ((v21 & 1) != 0)
  {
    v22 = 2;
  }
  else
  {
    if ((v21 & 2) == 0)
      return;
    v22 = 3;
  }
  dds3BillboardSetMode(&hBillboard, v22);
}

// 0x17b2e60
void dds3EffectObjectBasicStatOff(dds3Basic_t **basic, u32 s) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  if (*basic)
  {
    workdata = (*basic)->workdata;
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3EffectObjectBasicWorkData_t, v10);
      if ((v10[0] & 1) != 0)
        v8 = v10[2];
      else
        v8 = v10 + 1;
      v9 = sub_8C4940(v8);
    }
    LODWORD(workdata[1].monitor) &= ~s;
  }
}

// 0x17b2d60
void dds3EffectObjectBasicStatOn(dds3Basic_t **basic, u32 s) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  if (*basic)
  {
    workdata = (*basic)->workdata;
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3EffectObjectBasicWorkData_t, v10);
      if ((v10[0] & 1) != 0)
        v8 = v10[2];
      else
        v8 = v10 + 1;
      v9 = sub_8C4940(v8);
    }
    LODWORD(workdata[1].monitor) |= s;
  }
}

// 0x17aedf0
void dds3EffectObjectBasicUnlinkObject(dds3Basic_t **basic) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v8[3];

  workdata = (*basic)->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectObjectBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3EffectObjectBasicWorkData_t, v8);
    if ((v8[0] & 1) != 0)
      v6 = v8[2];
    else
      v6 = v8 + 1;
    v7 = sub_8C4940(v6);
  }
  LODWORD(workdata[1].monitor) &= 0xFFFFFFF3;
  workdata[3].monitor = 0;
  LODWORD(workdata[4].klass) = 0;
}

// 0x17b2340
void dds3EffectObjectPresetMG12(dds3Basic_t **eff) {
  dds3Basic_t_o *v3;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v8;
  u64 *image;
  s64 v10;
  char *v11;
  s64 *v12;
  s32 monitor_high;
  char *v14;
  s64 *v15;
  Il2CppClass *v16;
  u64 v17[2];
  char *v18;

  v16 = 0;
  v3 = *eff;
  if (DDS3_GETBASICTYPEL(v3) == 7)
  {
    workdata = (*eff)->workdata;
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3EffectObjectBasicWorkData_t, v17);
      if ((v17[0] & 1) != 0)
        v14 = v18;
      else
        v14 = v17 + 1;
      v15 = sub_8C4940(v14);
    }
    v8 = workdata[2].klass;
    if (v8)
    {
      image = v8->_1.image;
      if (*(v8->_1.image + 288) < v10 || *(image[25] + 8 * v10 - 8) != effHandle_t)
      {
        sub_8FC2C0(image[8], effHandle_t, v17);
        if ((v17[0] & 1) != 0)
          v11 = v18;
        else
          v11 = v17 + 1;
        v12 = sub_8C4940(v11);
      }
    }
    v16 = workdata[2].klass;
    monitor_high = HIDWORD(workdata[1].monitor);
    if (monitor_high == 1)
    {
      effMagaRandomize(&v16);
    }
    else if (monitor_high == 8)
    {
      effMagaP4Randomize(&v16);
    }
  }
}

// 0x17b2580
s32 dds3EffectObjectSetMG12Pos(dds3Basic_t **eff, dds3Basic_t **p1, dds3Basic_t **p2, dds3Basic_t **p3, dds3Basic_t **p4) {
  dds3Basic_t_o *v11;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v16;
  s64 *v17;
  s32 monitor_high;
  effMagaSCArea_t_o *monitor;
  effMagaSCArea_t_c *v20;
  s64 v21;
  char *v22;
  s64 *v23;
  f32 v26;
  f32 v27;
  effMagaP4Point_t_o *v29;
  effMagaP4Point_t_c *v30;
  s64 v31;
  char *v32;
  s64 *v33;
  struct UnityEngine_Vector4_array *point;
  struct System_Single_array *radius;
  f32 v39;
  f32 v40;
  struct UnityEngine_Vector4_array *v43;
  struct System_Single_array *v45;
  f32 v47;
  f32 v48;
  struct UnityEngine_Vector4_array *v51;
  struct System_Single_array *v53;
  f32 v55;
  f32 v56;
  struct UnityEngine_Vector4_array *v59;
  struct System_Single_array *v61;
  f32 v63;
  f32 v64;
  Il2CppClass *v66;
  u64 *v67;
  s64 v68;
  char *v69;
  s64 *v70;
  f32 v73;
  f32 v74;
  Il2CppClass *v75;
  u64 *image;
  s64 v77;
  char *v78;
  s64 *v79;
  Il2CppClass *v80;
  u64 v81[2];
  char *v82;

  v80 = 0;
  v11 = *eff;
  if (DDS3_GETBASICTYPEL(v11) != 7)
    return 0;
  workdata = (*eff)->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3EffectObjectBasicWorkData_t, v81);
      if ((v81[0] & 1) != 0)
        v16 = v82;
      else
        v16 = v81 + 1;
      v17 = sub_8C4940(v16);
    }
  }
  monitor_high = HIDWORD(workdata[1].monitor);
  if (monitor_high != 8)
  {
    if (monitor_high == 7)
    {
      monitor = workdata[4].monitor;
      if (monitor)
      {
        v20 = monitor->klass;
        if (monitor->klass->_2.typeHierarchyDepth < v21
          || v20->_2.typeHierarchy[v21 - 1] != effMagaSCArea_t)
        {
          sub_8FC2C0(v20->_1.element_class, effMagaSCArea_t, v81);
          if ((v81[0] & 1) != 0)
            v22 = v82;
          else
            v22 = v81 + 1;
          v23 = sub_8C4940(v22);
        }
      }
      if (CheckESP(p1))
      {
        SDF_VU0__LOADVECTOR((*p1)->poseset->pos, 0);
        SDF_VU0__STOREVECTOR(&monitor->s_center);
        if (CheckESP(p1))
        {
          sub_854710(&(*p1)->poseset->scl, 0);
          v27 = v26;
        }
        else
        {
          v27 = 0.0;
        }
        monitor->s_radius = v27;
      }
      if (CheckESP(p2))
      {
        SDF_VU0__LOADVECTOR((*p2)->poseset->pos, 0);
        SDF_VU0__STOREVECTOR(&monitor->c_center);
        if (CheckESP(p2))
        {
          sub_854710(&(*p2)->poseset->scl, 0);
          v74 = v73;
        }
        else
        {
          v74 = 0.0;
        }
        monitor->c_radius = v74;
      }
      v75 = workdata[2].klass;
      if (v75)
      {
        image = v75->_1.image;
        if (*(v75->_1.image + 288) < v77 || *(image[25] + 8 * v77 - 8) != effHandle_t)
        {
          sub_8FC2C0(image[8], effHandle_t, v81);
          if ((v81[0] & 1) != 0)
            v78 = v82;
          else
            v78 = v81 + 1;
          v79 = sub_8C4940(v78);
        }
      }
      v80 = workdata[2].klass;
      effMagaSCSetArea(&v80, monitor);
      return 1;
    }
    return 0;
  }
  v29 = workdata[4].monitor;
  if (v29)
  {
    v30 = v29->klass;
    if (v29->klass->_2.typeHierarchyDepth < v31 || v30->_2.typeHierarchy[v31 - 1] != effMagaP4Point_t)
    {
      sub_8FC2C0(v30->_1.element_class, effMagaP4Point_t, v81);
      if ((v81[0] & 1) != 0)
        v32 = v82;
      else
        v32 = v81 + 1;
      v33 = sub_8C4940(v32);
    }
  }
  if (CheckESP(p1))
  {
    SDF_VU0__LOADVECTOR((*p1)->poseset->pos, 0);
    point = v29->point;
    SDF_VU0__STOREVECTOR(point->m_Items);
    radius = v29->radius;
    if (CheckESP(p1))
    {
      sub_854710(&(*p1)->poseset->scl, 0);
      v40 = v39;
      if (!LODWORD(radius->max_length))
        goto LABEL_39;
    }
    else
    {
      v40 = 0;
      if (!LODWORD(radius->max_length))
      {
LABEL_39:
      }
    }
    radius->m_Items[0] = v40;
  }
  if (CheckESP(p2))
  {
    SDF_VU0__LOADVECTOR((*p2)->poseset->pos, 0);
    v43 = v29->point;
    SDF_VU0__STOREVECTOR(&v43->m_Items[1]);
    v45 = v29->radius;
    if (CheckESP(p2))
    {
      sub_854710(&(*p2)->poseset->scl, 0);
      v48 = v47;
      if (LODWORD(v45->max_length) <= 1)
        goto LABEL_46;
    }
    else
    {
      v48 = 0;
      if (LODWORD(v45->max_length) <= 1)
      {
LABEL_46:
      }
    }
    v45->m_Items[1] = v48;
  }
  if (CheckESP(p3))
  {
    SDF_VU0__LOADVECTOR((*p3)->poseset->pos, 0);
    v51 = v29->point;
    SDF_VU0__STOREVECTOR(&v51->m_Items[2]);
    v53 = v29->radius;
    if (CheckESP(p3))
    {
      sub_854710(&(*p3)->poseset->scl, 0);
      v56 = v55;
      if (LODWORD(v53->max_length) <= 2)
        goto LABEL_53;
    }
    else
    {
      v56 = 0.0;
      if (LODWORD(v53->max_length) <= 2)
      {
LABEL_53:
      }
    }
    v53->m_Items[2] = v56;
  }
  if (CheckESP(p4))
  {
    SDF_VU0__LOADVECTOR((*p4)->poseset->pos, 0);
    v59 = v29->point;
    SDF_VU0__STOREVECTOR(&v59->m_Items[3]);
    v61 = v29->radius;
    if (CheckESP(p4))
    {
      sub_854710(&(*p4)->poseset->scl, 0);
      v64 = v63;
      if (LODWORD(v61->max_length) <= 3)
        goto LABEL_60;
    }
    else
    {
      v64 = 0.0;
      if (LODWORD(v61->max_length) <= 3)
      {
LABEL_60:
      }
    }
    v61->m_Items[3] = v64;
  }
  v66 = workdata[2].klass;
  if (v66)
  {
    v67 = v66->_1.image;
    if (*(v66->_1.image + 288) < v68 || *(v67[25] + 8 * v68 - 8) != effHandle_t)
    {
      sub_8FC2C0(v67[8], effHandle_t, v81);
      if ((v81[0] & 1) != 0)
        v69 = v82;
      else
        v69 = v81 + 1;
      v70 = sub_8C4940(v69);
    }
  }
  v80 = workdata[2].klass;
  effMagaP4SetPoint(&v80, v29);
  return 1;
}

// 0x17b13b0
void dds3StartBEDEffectObjectBasic(dds3Basic_t **basic, u32 cutno) {
  u16 v3;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  effEveBEDParams_t_o *monitor;
  effBTL_t_o *v11;
  effEveBEDCutHandle_t_o *v12;
  effEveBEDCutHandle_t_c *v13;
  s64 v14;
  char *v15;
  s64 *v16;
  effBTL_t_c *v17;
  s64 v18;
  char *v19;
  s64 *v20;
  effEveBEDParams_t_c *v21;
  s64 v22;
  char *v23;
  s64 *v24;
  u64 v25[2];
  char *v26;

  v3 = cutno;
  workdata = (*basic)->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3EffectObjectBasicWorkData_t, v25);
      if ((v25[0] & 1) != 0)
        v8 = v26;
      else
        v8 = v25 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  if (HIDWORD(workdata[1].monitor) == 5)
  {
    monitor = workdata[4].monitor;
    if (monitor)
    {
      v11 = workdata[2].klass;
      if (v11)
      {
        v12 = workdata[5].klass;
        if (v12)
        {
          v13 = v12->klass;
          if (v12->klass->_2.typeHierarchyDepth < v14
            || v13->_2.typeHierarchy[v14 - 1] != effEveBEDCutHandle_t)
          {
            sub_8FC2C0(v13->_1.element_class, effEveBEDCutHandle_t, v25);
            if ((v25[0] & 1) != 0)
              v15 = v26;
            else
              v15 = v25 + 1;
            v16 = sub_8C4940(v15);
          }
          effEveBEDCutDelete(v12);
          v11 = workdata[2].klass;
          monitor = workdata[4].monitor;
          workdata[5].klass = 0;
        }
        if (v11)
        {
          v17 = v11->klass;
          if (v11->klass->_2.typeHierarchyDepth < v18 || v17->_2.typeHierarchy[v18 - 1] != effBTL_t)
          {
            sub_8FC2C0(v17->_1.element_class, effBTL_t, v25);
            if ((v25[0] & 1) != 0)
              v19 = v26;
            else
              v19 = v25 + 1;
            v20 = sub_8C4940(v19);
          }
        }
        if (monitor)
        {
          v21 = monitor->klass;
          if (monitor->klass->_2.typeHierarchyDepth < v22
            || v21->_2.typeHierarchy[v22 - 1] != effEveBEDParams_t)
          {
            sub_8FC2C0(v21->_1.element_class, effEveBEDParams_t, v25);
            if ((v25[0] & 1) != 0)
              v23 = v26;
            else
              v23 = v25 + 1;
            v24 = sub_8C4940(v23);
          }
        }
        workdata[5].klass = effEveBEDCutCreate(v11, v3, monitor);
      }
    }
  }
}

// 0x17adbd0
s32 fldGbGetEAnimeCngID(s32 fld, s32 area, s32 grp) {
  return 0;
}
