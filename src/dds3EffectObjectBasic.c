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
    dds3SerializeID();
    dds3AddEffectObjectBasic(0, (sdfVector4_t){0}, (sdfVector4_t){0});
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    effEveBEDCreate(0);
    effEveBEDParams_t__Copy(0, 0);
    dds3EffectObjectBasicGetControlWorkData(0);
    dds3AreaBasicGetFastArea();
    dds3AreaBasicRegistItem(0, 0);
    return 0;
}

// 0x17b0980
dds3Basic_t *AddD3PEffect(effHandle_t **eff, sdfVector4_t pos, sdfVector4_t rot) {
    dds3SerializeID();
    dds3AddEffectObjectBasic(0, (sdfVector4_t){0}, (sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__STOREVECTOR(0);
    dds3EffectSetPosition(0, (sdfVector4_t){0});
    dds3EffectObjectBasicGetControlWorkData(0);
    dds3AreaBasicGetFastArea();
    dds3AreaBasicRegistItem(0, 0);
    return 0;
}

// 0x17b16f0
dds3Basic_t *AddESPEffect(char *name, sdfVector4_t pos, sdfVector4_t rot, f32 r) {
    dds3SerializeID();
    dds3AddEffectObjectBasic(0, (sdfVector4_t){0}, (sdfVector4_t){0});
    dds3EffectObjectBasicGetControlWorkData(0);
    dds3AreaBasicGetFastArea();
    dds3AreaBasicRegistItem(0, 0);
    return 0;
}

// 0x17b1980
dds3Basic_t *AddMG12Effect(s32 type, void *data) {
    dds3EffectLoad(0, 0, 0);
    dds3SerializeID();
    dds3AddEffectObjectBasic(0, (sdfVector4_t){0}, (sdfVector4_t){0});
    effMagaP4Point_t__Copy(0, 0);
    effMagaP4SetPoint(0, 0);
    effMagaSCArea_t__Copy(0, 0);
    effMagaSCSetArea(0, 0);
    dds3EffectObjectBasicGetControlWorkData(0);
    dds3AreaBasicGetFastArea();
    dds3AreaBasicRegistItem(0, 0);
    return 0;
}

// 0x17afb80
dds3Basic_t *AddP2AEffect(billHandle_t **p2a, sdfVector4_t pos, sdfVector4_t rot) {
    dds3SerializeID();
    dds3AddEffectObjectBasic(0, (sdfVector4_t){0}, (sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__STOREVECTOR(0);
    dds3BillboardSetPosition(0, (sdfVector4_t){0});
    dds3EffectObjectBasicGetControlWorkData(0);
    dds3AreaBasicGetFastArea();
    dds3AreaBasicRegistItem(0, 0);
    return 0;
}

// 0x17b0300
dds3Basic_t *AddTMXEffect(billHandle_t **tmx, sdfVector4_t pos, sdfVector4_t rot) {
    dds3SerializeID();
    dds3AddEffectObjectBasic(0, (sdfVector4_t){0}, (sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__STOREVECTOR(0);
    dds3BillboardSetPosition(0, (sdfVector4_t){0});
    dds3EffectObjectBasicGetControlWorkData(0);
    dds3AreaBasicGetFastArea();
    dds3AreaBasicRegistItem(0, 0);
    return 0;
}

// 0x17b2180
dds3EffectObjectBasicWorkData_t *CheckESP(dds3Basic_t **b) {
    DDS3_GETBASICTYPEL(0);
    return 0;
}

// 0x17adf30
void FreeEffectData(dds3EffectObjectBasicWorkData_t **work) {
    dds3EffectDelete(0);
    dds3BillboardDelete(0);
    effEveBEDCutDelete(0);
    effEveBEDDelete(0);
}

// 0x17aeef0
billHandle_t *GetBillHandle(void *h, s32 type) {
    return 0;
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
    CheckESP(0);
    return 0;
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
  v13 = Concat_5221536(StringLiteral_14724, file, StringLiteral_4739);
  sdfDevLoadFileUnity_25061072(v13, &aTopPtr, 0, StringLiteral_8913);
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
    dds3AddSceneBasicData(0);
    dds3ObjectBaseCreateMover(0);
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
    dds3SetRotPoseSet(0, (sdfVector4_t){0});
    dds3BackupPoseSet(0);
    return 0;
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
  v13 = dds3BillboardCreate(1, effdata, 0, StringLiteral_416);
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
    GetBillHandle(0, 0);
    dds3BillboardCopy(0);
    AddP2AEffect(0, (sdfVector4_t){0}, (sdfVector4_t){0});
    return 0;
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
  Write_2930400(StringLiteral_14723, file);
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
  v13 = dds3BillboardCreate(0, effdata, 0, StringLiteral_416);
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
    GetBillHandle(0, 0);
    dds3BillboardCopy(0);
    AddTMXEffect(0, (sdfVector4_t){0}, (sdfVector4_t){0});
    return 0;
}

// 0x17af400
void dds3EffectObjectBasicCalcFldEx(dds3Basic_t **basic) {
    fldGbChkEView(0, 0, 0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    GetBillHandle(0, 0);
    dds3BillboardSetRGBA(0, 0);
    fldGbGetEAnimeCngID(0, 0, 0);
    dds3BillboardSetAnimNumber(0, 0);
}

// 0x17adbe0
s32 dds3EffectObjectBasicConstructor(dds3Basic_t *aPtr) {
    dds3InitPoseSet(0);
    dds3EffectObjectBasicWorkData_t__Clear(0);
    dds3ObjectBaseInitControlWorkData(0);
    dds3ObjectBaseOnFlag(0, 0, 0);
    return 0;
}

// 0x17adde0
s32 dds3EffectObjectBasicDestructor(dds3Basic_t *aPtr) {
    FreeEffectData(0);
    dds3FreePoseSet(0);
    dds3ObjectBaseFreeControlWorkData(0);
    return 0;
}

// 0x17af110
s32 dds3EffectObjectBasicDrawProcedure(dds3Basic_t *aPtr) {
    dds3EffectObjectBasicCalcFldEx(0);
    dds3ObjectBaseCheckFlag(0, 0);
    dds3EffectDraw(0);
    dds3EffectDrawOff(0);
    GetBillHandle(0, 0);
    dds3BillboardDraw(0);
    dds3BillboardDrawOff(0);
    effEveBEDCutDraw(0);
    return 0;
}

// 0x17af880
dds3ObjectBaseControlWorkData_t *dds3EffectObjectBasicGetControlWorkData(dds3Basic_t **pBasic) {
    return 0;
}

// 0x17aec30
void dds3EffectObjectBasicGetObjectIndex(dds3Basic_t **basic) {
    DDS3_GETBASICTYPEL(0);
}

// 0x17b2f60
s32 dds3EffectObjectBasicLinkObject(dds3Basic_t **basic, dds3Basic_t **target) {
    DDS3_GETBASICTYPEL(0);
    return 0;
}

// 0x17b30f0
s32 dds3EffectObjectBasicLinkObjectIndex(dds3Basic_t **basic, dds3Basic_t **target, s32 index) {
    dds3EffectObjectBasicLinkObject(0, 0);
    return 0;
}

// 0x17ae290
s32 dds3EffectObjectBasicMainProcedure(dds3Basic_t *aPtr) {
    dds3OffPoseSetFlag(0, 0);
    dds3GetPosPoseSetMCR(0);
    SDF_VU0__STOREVECTOR(0);
    dds3BackupPoseSet(0);
    dds3GetRotPoseSetMCR(0);
    dds3EffectSetPosition(0, (sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    ToMatrix();
    SDF_VU0__STOREMATRIX(0);
    dds3EffectSetRotateMatrix(0, 0);
    dds3EffectGetState(0);
    GetBillHandle(0, 0);
    dds3BillboardSetPosition(0, (sdfVector4_t){0});
    dds3BillboardGetAnimState(0);
    dds3DeleteSceneBasicData(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    effEveBEDCutSetParams(0, 0);
    dds3GetActiveScene();
    dds3SceneBasicExistBasicFromType(0, 0, 0);
    dds3EffectObjectBasicUnlinkObject(0);
    dds3EffectObjectBasicGetObjectIndex(0);
    SDF_VU0__LOADIDENTITY();
    SDF_VU0__COPYMATRIX_A_TO_B();
    SDF_VU0__VECTOR_W_SET_ONE();
    SDF_VU0__TRANSLATE();
    MultMatrixRevNoArg();
    SDF_VU0__LOADIDENTITYVECTOR();
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    return 0;
}

// 0x17b01c0
void dds3EffectObjectBasicSetAnmeID(dds3Basic_t **basic, s32 animeID) {
    GetBillHandle(0, 0);
    dds3BillboardSetAnimNumber(0, 0);
}

// 0x17b3210
void dds3EffectObjectBasicSetFldEx(dds3Basic_t **basic, fldResourceEffect_t **pResEff) {
    dds3EffectObjectBasicStatOn(0, 0);
    GetBillHandle(0, 0);
    dds3BillboardSetAnimNumber(0, 0);
    dds3BillboardSetXYOffset(0, 0, 0);
    dds3BillboardSetDrawType(0, 0);
    dds3BillboardSetMode(0, 0);
}

// 0x17b2e60
void dds3EffectObjectBasicStatOff(dds3Basic_t **basic, u32 s) {
}

// 0x17b2d60
void dds3EffectObjectBasicStatOn(dds3Basic_t **basic, u32 s) {
}

// 0x17aedf0
void dds3EffectObjectBasicUnlinkObject(dds3Basic_t **basic) {
}

// 0x17b2340
void dds3EffectObjectPresetMG12(dds3Basic_t **eff) {
    DDS3_GETBASICTYPEL(0);
    effMagaRandomize(0);
    effMagaP4Randomize(0);
}

// 0x17b2580
s32 dds3EffectObjectSetMG12Pos(dds3Basic_t **eff, dds3Basic_t **p1, dds3Basic_t **p2, dds3Basic_t **p3, dds3Basic_t **p4) {
    DDS3_GETBASICTYPEL(0);
    CheckESP(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__STOREVECTOR(0);
    effMagaSCSetArea(0, 0);
    effMagaP4SetPoint(0, 0);
    return 0;
}

// 0x17b13b0
void dds3StartBEDEffectObjectBasic(dds3Basic_t **basic, u32 cutno) {
    effEveBEDCutDelete(0);
    effEveBEDCutCreate(0, 0, 0);
}

// 0x17adbd0
s32 fldGbGetEAnimeCngID(s32 fld, s32 area, s32 grp) {
  return 0;
}
