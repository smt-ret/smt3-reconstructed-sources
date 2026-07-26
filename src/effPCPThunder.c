#include "types.h"

typedef struct dds3EffectPCPData_t dds3EffectPCPData_t;
typedef struct dds3TrackPoly_t dds3TrackPoly_t;
typedef struct effPCPThunderSpherePolyLow_t effPCPThunderSpherePolyLow_t;
typedef struct effPCPThunderSpherePolyParam_t effPCPThunderSpherePolyParam_t;
typedef struct effPCPThunderSpherePoly_t effPCPThunderSpherePoly_t;
typedef struct effPCP_ThunderColumnPolyLowParam_t effPCP_ThunderColumnPolyLowParam_t;
typedef struct effPCP_ThunderColumnPolyLow_t effPCP_ThunderColumnPolyLow_t;
typedef struct effPCP_ThunderPolyListParam_t effPCP_ThunderPolyListParam_t;
typedef struct effPCP_ThunderPolyList_t effPCP_ThunderPolyList_t;
typedef struct effPCP_ThunderPolyLow_t effPCP_ThunderPolyLow_t;
typedef struct effPCP_ThunderPolyParam_t effPCP_ThunderPolyParam_t;
typedef struct effPCP_ThunderPoly_t effPCP_ThunderPoly_t;
typedef struct effPCP_ThunderRadiatePolyParam_t effPCP_ThunderRadiatePolyParam_t;
typedef struct effPCP_ThunderRadiatePoly_t effPCP_ThunderRadiatePoly_t;

f32 DDS3EFFECT_RAND_F(void);
f32 DDS3EFFECT_RAND_FA(f32 r);
u32 DDS3EFFECT_RAND_I(void);
f32 DDS3EFFECT_RAND_PM(void);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__ADDVECTOR_A_C(void);
void SDF_VU0__ADDVECTOR_B_A(void);
void SDF_VU0__APPLYMATRIX_XYZ(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__COPYVECTOR_A_TO_B(void);
void SDF_VU0__COPYVECTOR_A_TO_C(void);
void SDF_VU0__COPYVECTOR_B_TO_A(void);
void SDF_VU0__COPYVECTOR_C_TO_A(void);
void SDF_VU0__COPYVECTOR_C_TO_B(void);
f32 SDF_VU0__GETLENGTH(void);
f32 SDF_VU0__INNERPRODUCT(void);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_C(sdfVector4_t p);
void SDF_VU0__MULVECTOR(void);
void SDF_VU0__NORMALIZE(void);
void SDF_VU0__OUTERPRODUCT(void);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__STOREVECTOR_B(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
void SDF_VU0__SUBVECTOR_B_A(void);
void SetRotateMatrixAxis(f32 aAngle, sdfVector4_t aAxis);
void SetRotateMatrixXYZ(f32 **aAngles);
void *dds3EffectPCPDataGetDataUnityOffSet(void *hData, s32 offset, s32 type);
void dds3EffectPCPData_t__pCopy(dds3EffectPCPData_t *this, u8 **bytedata, s32 *pos);
dds3TrackPoly_t *dds3TrackPolyCreate(s32 number, s32 face, s32 rec, s32 type);
void dds3TrackPolyDelete(dds3TrackPoly_t **hTrackPoly);
void dds3TrackPolyDraw(dds3TrackPoly_t **hTrackPoly, char *funcname);
void dds3TrackPolyDrawOff(dds3TrackPoly_t **hTrackPoly);
void dds3TrackPolyListInit(dds3TrackPoly_t **hTrackPoly, s32 number);
void dds3TrackPolySetMode(dds3TrackPoly_t **hTrackPoly, u16 mode);
void dds3TrackPolyVC3Set_Acute(dds3TrackPoly_t **hTrackPoly, u32 abgr_0, u32 abgr_1, u32 abgr_2);
void dds3TrackPolyVC5Set_Acute(dds3TrackPoly_t **hTrackPoly, u32 abgr_0, u32 abgr_1, u32 abgr_2);
void dds3TrackPolyVC5Set_AcuteR(dds3TrackPoly_t **hTrackPoly, u32 abgr_0, u32 abgr_1, u32 abgr_2);
void dds3TrackPolyVC5Set_AcuteW(dds3TrackPoly_t **hTrackPoly, u32 abgr_0, u32 abgr_1, u32 abgr_2);
void dds3TrackPolyVC5Set_Normal(dds3TrackPoly_t **hTrackPoly, u32 abgr_0, u32 abgr_1, u32 abgr_2);
void dds3TrackPolyVCSet(dds3TrackPoly_t **hTrackPoly, s32 type, u32 abgr_in, u32 abgr_out);
u32 effColorMultiply(u32 abgr0, u32 abgr1);
effPCPThunderSpherePoly_t *effPCPThunderSpherePolyCreate(void **hData, s32 bPos, bool tbldata);
effPCPThunderSpherePolyLow_t *effPCPThunderSpherePolyLowCreate(effPCPThunderSpherePolyParam_t *pParam);
void effPCPThunderSpherePolyLowPartInit(effPCPThunderSpherePolyLow_t **pThunderPoly, s32 number);
void effPCPThunderSpherePolyLowPartMove(effPCPThunderSpherePolyLow_t **pThunderPoly, s32 number);
void effPCPThunderSpherePolyLowPartRefresh(effPCPThunderSpherePolyLow_t **pThunderPoly, s32 number);
void effPCPThunderSpherePolyParam_t__pClone(effPCPThunderSpherePolyParam_t *this, effPCPThunderSpherePolyParam_t **param);
void effPCPThunderSpherePolyPartInit(effPCPThunderSpherePoly_t **pThunderPoly, s32 number);
void effPCPThunderSpherePolyPartMove(effPCPThunderSpherePoly_t **pThunderPoly, s32 number);
void effPCPThunderSpherePolyPartRefresh(effPCPThunderSpherePoly_t **pThunderPoly, s32 number);
effPCP_ThunderColumnPolyLow_t *effPCP_ThunderColumnPolyLowCreate(effPCP_ThunderColumnPolyLowParam_t *pParam);
void effPCP_ThunderColumnPolyLowParam_t__pClone(effPCP_ThunderColumnPolyLowParam_t *this, effPCP_ThunderColumnPolyLowParam_t **param);
void effPCP_ThunderColumnPolyLowPartInit(effPCP_ThunderColumnPolyLow_t **pThunderPoly, s32 number);
void effPCP_ThunderColumnPolyLowPartRefresh(effPCP_ThunderColumnPolyLow_t **pThunderPoly, s32 number);
effPCP_ThunderPoly_t *effPCP_ThunderPolyCreate(void **hData, s32 bPos, bool tbldata);
void effPCP_ThunderPolyDelete(void **hData);
void effPCP_ThunderPolyListParam_t__pClone(effPCP_ThunderPolyListParam_t *this, effPCP_ThunderPolyListParam_t **param);
void effPCP_ThunderPolyListPartRefresh(effPCP_ThunderPoly_t **pThunderPoly, s32 number, sdfVector4_t **pPos, s32 pidx);
void effPCP_ThunderPolyLowPartInit(effPCP_ThunderPolyLow_t **pThunderPoly, s32 number);
void effPCP_ThunderPolyLowPartRefresh(effPCP_ThunderPolyLow_t **pThunderPoly, s32 number);
void effPCP_ThunderPolyParam_t__pClone(effPCP_ThunderPolyParam_t *this, effPCP_ThunderPolyParam_t **param);
effPCP_ThunderPolyParam_t *effPCP_ThunderPolyParam_t__pCopy(effPCP_ThunderPolyParam_t *this, void *pData, s32 *pos, s32 max);
void effPCP_ThunderPolyPartInit(effPCP_ThunderPoly_t **pThunderPoly, s32 number);
void effPCP_ThunderPolyPartRefresh(effPCP_ThunderPoly_t **pThunderPoly, s32 number);
void effPCP_ThunderRadiatePolyParam_t__pClone(effPCP_ThunderRadiatePolyParam_t *this, effPCP_ThunderRadiatePolyParam_t **param);
void effPCP_ThunderRadiatePolyPartInit(effPCP_ThunderRadiatePoly_t **pThunderRadiatePoly, s32 number);
void effPCP_ThunderRadiatePolyPartRefresh(effPCP_ThunderRadiatePoly_t **pThunderRadiatePoly, s32 number);
f32 sdfCos(f32 aRadius);
f32 sdfSin(f32 aRadius);

// 0x176be50
effPCPThunderSpherePoly_t *effPCPThunderSpherePolyCopy(void **hData, s32 bPos, bool tbldata) {
    effPCPThunderSpherePolyCreate(0, 0, 0);
    return 0;
}

// 0x176b910
effPCPThunderSpherePoly_t *effPCPThunderSpherePolyCreate(void **hData, s32 bPos, bool tbldata) {
    effPCPThunderSpherePolyParam_t__pClone(0, 0);
    dds3TrackPolyCreate(0, 0, 0, 0);
    dds3TrackPolyVC5Set_AcuteW(0, 0, 0, 0);
    dds3TrackPolySetMode(0, 0);
    return 0;
}

// 0x176bc30
effPCPThunderSpherePoly_t *effPCPThunderSpherePolyCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    effPCPThunderSpherePolyCreate(0, 0, 0);
    return 0;
}

// 0x176bf50
void effPCPThunderSpherePolyDelete(void **hData) {
    dds3TrackPolyDelete(0);
}

// 0x176c9e0
void effPCPThunderSpherePolyDraw(void **hData) {
    effPCPThunderSpherePolyPartRefresh(0, 0);
    effPCPThunderSpherePolyPartMove(0, 0);
    effPCPThunderSpherePolyPartInit(0, 0);
    dds3TrackPolyListInit(0, 0);
    effColorMultiply(0, 0);
    dds3TrackPolyDraw(0, 0);
}

// 0x176c8c0
void effPCPThunderSpherePolyDrawOff(void **hData) {
    dds3TrackPolyDrawOff(0);
}

// 0x176c3a0
effPCPThunderSpherePolyParam_t *effPCPThunderSpherePolyGetParam(effPCPThunderSpherePoly_t *pThunderPoly) {
  return pThunderPoly->param;
}

// 0x176dcc0
effPCPThunderSpherePolyLow_t *effPCPThunderSpherePolyLowCopy(void **hData, s32 bPos, bool tbldata) {
    effPCPThunderSpherePolyLowCreate(0);
    return 0;
}

// 0x176d710
effPCPThunderSpherePolyLow_t *effPCPThunderSpherePolyLowCreate(effPCPThunderSpherePolyParam_t *pParam) {
  effPCPThunderSpherePolyLow_t_o *v3;
  u64 *v4;
  struct effPCPThunderSpherePolyParam_t_o *param;
  s32 number;
  s32 split;
  s64 v9;
  u32 *pPart;
  u64 v12;
  u64 *v13;
  struct effPCPThunderSpherePolyPart_t_array *v15;
  struct effPCPThunderSpherePolyPart_t_array *v17;
  struct effPCPThunderSpherePolyPart_t_array *v19;
  u64 v21;

  v3 = Allocate(effPCPThunderSpherePolyLow_t);
  effPCPThunderSpherePolyLow_t___ctor(v3);
  v4 = Allocate(effPCPThunderSpherePolyParam_t);
  effPCPThunderSpherePolyParam_t___ctor(v4);
  v3->param = v4;
  effPCPThunderSpherePolyParam_t__pClone(pParam, &v3->param);
  v3->pPart = NewSpecific(effPCPThunderSpherePolyPart_t, pParam->number);
  v3->hMem = 0;
  v3->width_base = pParam->width;
  v3->height_base = pParam->height;
  param = v3->param;
  number = param->number;
  split = param->split;
  v3->hPoly = dds3TrackPolyCreate(number, split, 0, 0);
  dds3TrackPolyVCSet(&v3->hPoly, 2, v3->param->color_border, v3->param->color_border);
  dds3TrackPolySetMode(&v3->hPoly, v3->param->blend);
  if (v3->param->number)
  {
    v9 = 4;
    do
    {
      pPart = v3->pPart;
      v12 = v9 - 4;
      v13 = Allocate(effPCPThunderSpherePolyPart_t);
      effPCPThunderSpherePolyPart_t___ctor(v13);
      *&pPart[2 * v9] = v13;
      v15 = v3->pPart;
      *(*(&v15->obj.klass + v9) + 16LL) = 0;
      v17 = v3->pPart;
      *(*(&v17->obj.klass + v9) + 20LL) = 0;
      v19 = v3->pPart;
      *(*(&v19->obj.klass + v9) + 56LL) = 0;
      v21 = v9 - 3;
      ++v9;
    }
    while (v21 < v3->param->number);
  }
  v3->abgr = -2139062144;
  return v3;
}

// 0x176d620
effPCPThunderSpherePolyLow_t *effPCPThunderSpherePolyLowCreateP(void **pData, s32 bPos, bool tbldata) {
    effPCPThunderSpherePolyLowCreate(0);
    return 0;
}

// 0x176dab0
effPCPThunderSpherePolyLow_t *effPCPThunderSpherePolyLowCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    effPCPThunderSpherePolyLowCreate(0);
    return 0;
}

// 0x176d990
void effPCPThunderSpherePolyLowDelete(void **hData) {
    dds3TrackPolyDelete(0);
}

// 0x176e5d0
void effPCPThunderSpherePolyLowDraw(void **hData) {
    effPCPThunderSpherePolyLowPartRefresh(0, 0);
    effPCPThunderSpherePolyLowPartMove(0, 0);
    effPCPThunderSpherePolyLowPartInit(0, 0);
    dds3TrackPolyListInit(0, 0);
    effColorMultiply(0, 0);
    dds3TrackPolyDraw(0, 0);
}

// 0x176e4b0
void effPCPThunderSpherePolyLowDrawOff(void **hData) {
    dds3TrackPolyDrawOff(0);
}

// 0x176e0e0
effPCPThunderSpherePolyParam_t *effPCPThunderSpherePolyLowGetParam(effPCPThunderSpherePolyLow_t *pThunderPoly) {
  return pThunderPoly->param;
}

// 0x176cc70
void effPCPThunderSpherePolyLowPartInit(effPCPThunderSpherePolyLow_t **pThunderPoly, s32 number) {
    DDS3EFFECT_RAND_I();
    DDS3EFFECT_RAND_PM();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
}

// 0x176e0f0
void effPCPThunderSpherePolyLowPartMove(effPCPThunderSpherePolyLow_t **pThunderPoly, s32 number) {
    DDS3EFFECT_RAND_F();
    SetRotateMatrixAxis(0, (sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX_XYZ();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__ADDVECTOR();
}

// 0x176cfb0
void effPCPThunderSpherePolyLowPartRefresh(effPCPThunderSpherePolyLow_t **pThunderPoly, s32 number) {
    DDS3EFFECT_RAND_PM();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    DDS3EFFECT_RAND_F();
    SetRotateMatrixXYZ(0);
    SDF_VU0__APPLYMATRIX_XYZ();
    SetRotateMatrixAxis(0, (sdfVector4_t){0});
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__OUTERPRODUCT();
    SDF_VU0__NORMALIZE();
    SDF_VU0__MULVECTOR();
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__ADDVECTOR_A_C();
    SDF_VU0__COPYVECTOR_C_TO_A();
    SDF_VU0__SUBVECTOR_B_A();
    SDF_VU0__STOREVECTOR_B(0);
}

// 0x176ded0
void effPCPThunderSpherePolyLowSetColor(void **hData, u32 abgr) {
}

// 0x176ddb0
void effPCPThunderSpherePolyLowSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x176dfc0
void effPCPThunderSpherePolyLowSetScale(void **hData, f32 scale) {
}

// 0x176ae00
void effPCPThunderSpherePolyPartInit(effPCPThunderSpherePoly_t **pThunderPoly, s32 number) {
    DDS3EFFECT_RAND_I();
    DDS3EFFECT_RAND_PM();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
}

// 0x176c3b0
void effPCPThunderSpherePolyPartMove(effPCPThunderSpherePoly_t **pThunderPoly, s32 number) {
    DDS3EFFECT_RAND_F();
    SetRotateMatrixAxis(0, (sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX_XYZ();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__ADDVECTOR();
}

// 0x176b140
void effPCPThunderSpherePolyPartRefresh(effPCPThunderSpherePoly_t **pThunderPoly, s32 number) {
    DDS3EFFECT_RAND_PM();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    DDS3EFFECT_RAND_F();
    SetRotateMatrixXYZ(0);
    SDF_VU0__APPLYMATRIX_XYZ();
    SetRotateMatrixAxis(0, (sdfVector4_t){0});
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__OUTERPRODUCT();
    SDF_VU0__NORMALIZE();
    SDF_VU0__MULVECTOR();
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__ADDVECTOR_A_C();
    SDF_VU0__COPYVECTOR_C_TO_A();
    SDF_VU0__SUBVECTOR_B_A();
    SDF_VU0__STOREVECTOR_B(0);
}

// 0x176c190
void effPCPThunderSpherePolySetColor(void **hData, u32 abgr) {
}

// 0x176c070
void effPCPThunderSpherePolySetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x176c280
void effPCPThunderSpherePolySetScale(void **hData, f32 scale) {
}

// 0x176f5d0
effPCP_ThunderColumnPolyLow_t *effPCP_ThunderColumnPolyLowCreate(effPCP_ThunderColumnPolyLowParam_t *pParam) {
  u64 *v3;
  effPCP_ThunderColumnPolyLow_t_o *v4;
  u64 *v5;
  effPCP_ThunderColumnPolyLow_t_Fields *p_fields;
  struct effPCP_ThunderColumnPolyLowPart_t_array *v7;
  struct effPCP_ThunderColumnPolyLowParam_t_o *param;
  s64 timing;
  s64 v10;
  u32 *pPart;
  u64 v13;
  u64 *v14;
  struct effPCP_ThunderColumnPolyLowPart_t_array *v17;
  s64 v19;
  s32 split;
  struct effPCP_ThunderColumnPolyLowPart_t_array *v21;
  u32 color_center;
  struct effPCP_ThunderColumnPolyLowPart_t_array *v24;
  struct effPCP_ThunderColumnPolyLowPart_t_array *v28;
  s64 v30;
  u32 v31;
  u64 v32;
  effPCP_ThunderColumnPolyLow_t_o *pThunderPoly;

  v3 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v3);
  v4 = Allocate(effPCP_ThunderColumnPolyLow_t);
  effPCP_ThunderColumnPolyLow_t___ctor(v4);
  pThunderPoly = v4;
  v5 = Allocate(effPCP_ThunderColumnPolyLowParam_t);
  effPCP_ThunderColumnPolyLowParam_t___ctor(v5);
  p_fields = &v4->fields;
  v4->param = v5;
  effPCP_ThunderColumnPolyLowParam_t__pClone(pParam, &v4->param);
  v7 = NewSpecific(effPCP_ThunderColumnPolyLowPart_t, pParam->number);
  v4->abgr = -2139062144;
  param = v4->param;
  v4->pPart = v7;
  v4->hMem = v3;
  if (param->timing <= 0)
  {
    param->timing = 1;
    param = p_fields->param;
    if (!p_fields->param->number)
      return v4;
  }
  else if (!param->number)
  {
    return v4;
  }
  timing = param->timing;
  v10 = 4;
  do
  {
    pPart = v4->pPart;
    v13 = v10 - 4;
    v14 = Allocate(effPCP_ThunderColumnPolyLowPart_t);
    effPCP_ThunderColumnPolyLowPart_t___ctor(v14);
    *&pPart[2 * v10] = v14;
    v17 = v4->pPart;
    v19 = *(&v17->obj.klass + v10);
    split = p_fields->param->TP->split;
    *(v19 + 48) = dds3TrackPolyCreate(1, 2 * split - 1, 0, 0);
    v21 = v4->pPart;
    color_center = v4->param->TP->color_center;
    dds3TrackPolyVCSet((*(&v21->obj.klass + v10) + 48LL), 2, color_center, color_center, 0);
    v24 = v4->pPart;
    dds3TrackPolySetMode((*(&v24->obj.klass + v10) + 48LL), v4->param->TP->blend, 0);
    effPCP_ThunderColumnPolyLowPartInit(&pThunderPoly, v10 - 4);
    v28 = v4->pPart;
    v30 = *(&v28->obj.klass + v10);
    v31 = DDS3EFFECT_RAND_I();
    v32 = v10 - 3;
    ++v10;
    *(v30 + 16) = v31 / timing * timing - v31;
  }
  while (v32 < p_fields->param->number);
  return v4;
}

// 0x176f4e0
effPCP_ThunderColumnPolyLow_t *effPCP_ThunderColumnPolyLowCreateP(void **pData, s32 bPos, bool tbldata) {
    effPCP_ThunderColumnPolyLowCreate(0);
    return 0;
}

// 0x176f900
void effPCP_ThunderColumnPolyLowDelete(void **hData) {
    dds3TrackPolyDelete(0);
}

// 0x176fc80
void effPCP_ThunderColumnPolyLowDraw(void **hData) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    effPCP_ThunderColumnPolyLowPartInit(0, 0);
    dds3TrackPolyListInit(0, 0);
    sdfCos(0);
    sdfSin(0);
    effColorMultiply(0, 0);
    effPCP_ThunderColumnPolyLowPartRefresh(0, 0);
    dds3TrackPolyDraw(0, 0);
    DDS3EFFECT_RAND_I();
}

// 0x176e860
void effPCP_ThunderColumnPolyLowPartInit(effPCP_ThunderColumnPolyLow_t **pThunderPoly, s32 number) {
  struct effPCP_ThunderColumnPolyLowPart_t_array *pPart;
  effPCP_ThunderColumnPolyLowPart_t_o *v7;
  struct effPCP_ThunderColumnPolyLowParam_t_o *param;
  f32 up_r;
  f32 up_s;
  f32 height;
  struct effPCP_ThunderColumnPolyLowParam_t_o *v12;
  f32 roll_s;
  struct effPCP_ThunderColumnPolyLowParam_t_o *v14;
  f32 radius;

  pPart = (*pThunderPoly)->pPart;
  v7 = pPart->m_Items[number];
  v7->up = 0.0;
  param = (*pThunderPoly)->param;
  up_s = param->up_s;
  up_r = param->up_r;
  v7->up_s = up_s * DDS3EFFECT_RAND_FA(up_r);
  height = (*pThunderPoly)->param->height;
  v7->height = height * DDS3EFFECT_RAND_F();
  v7->rotate = DDS3EFFECT_RAND_F() * 6.2832;
  v12 = (*pThunderPoly)->param;
  roll_s = v12->roll_s;
  v7->rotate_s = roll_s * DDS3EFFECT_RAND_FA(v12->roll_r);
  v14 = (*pThunderPoly)->param;
  radius = v14->radius;
  v7->radius = radius * DDS3EFFECT_RAND_FA(v14->radius_r);
}

// 0x176e9a0
void effPCP_ThunderColumnPolyLowPartRefresh(effPCP_ThunderColumnPolyLow_t **pThunderPoly, s32 number) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__OUTERPRODUCT();
    DDS3EFFECT_RAND_F();
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    sdfSin(0);
    SDF_VU0__MULVECTOR();
    SDF_VU0__ADDVECTOR_B_A();
    SDF_VU0__STOREVECTOR_B(0);
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__ADDVECTOR_A_C();
    SDF_VU0__COPYVECTOR_C_TO_A();
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__SUBVECTOR_B_A();
    DDS3EFFECT_RAND_PM();
    SetRotateMatrixAxis(0, (sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX_XYZ();
    SDF_VU0__INNERPRODUCT();
    SDF_VU0__LOADVECTOR_C((sdfVector4_t){0});
    SDF_VU0__COPYVECTOR_C_TO_B();
    SDF_VU0__ADDVECTOR();
}

// 0x176fb90
void effPCP_ThunderColumnPolyLowSetColor(void **hData, u32 abgr) {
}

// 0x176fa70
void effPCP_ThunderColumnPolyLowSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1771180
effPCP_ThunderPoly_t *effPCP_ThunderPolyCreate(void **hData, s32 bPos, bool tbldata) {
    effPCP_ThunderPolyParam_t__pClone(0, 0);
    effPCP_ThunderPolyParam_t__pCopy(0, 0, 0, 0);
    dds3TrackPolyCreate(0, 0, 0, 0);
    dds3TrackPolyVC5Set_AcuteW(0, 0, 0, 0);
    dds3TrackPolySetMode(0, 0);
    effPCP_ThunderPolyPartInit(0, 0);
    return 0;
}

// 0x1771480
void effPCP_ThunderPolyDelete(void **hData) {
    dds3TrackPolyDelete(0);
}

// 0x1771b90
void effPCP_ThunderPolyDraw(void **hData) {
    effPCP_ThunderPolyPartRefresh(0, 0);
    effPCP_ThunderPolyPartInit(0, 0);
    dds3TrackPolyListInit(0, 0);
    effColorMultiply(0, 0);
    dds3TrackPolyDraw(0, 0);
}

// 0x1771a70
void effPCP_ThunderPolyDrawOff(void **hData) {
    dds3TrackPolyDrawOff(0);
}

// 0x1771880
effPCP_ThunderPolyParam_t *effPCP_ThunderPolyGetParam(effPCP_ThunderPoly_t *pThunderPoly) {
  return pThunderPoly->param;
}

// 0x1774f20
effPCP_ThunderPolyList_t *effPCP_ThunderPolyListCreate(void **hData, s32 bPos, bool tbldata) {
    effPCP_ThunderPolyListParam_t__pClone(0, 0);
    effPCP_ThunderPolyCreate(0, 0, 0);
    dds3TrackPolyVC5Set_AcuteR(0, 0, 0, 0);
    dds3TrackPolyVC5Set_Normal(0, 0, 0, 0);
    dds3TrackPolyVC5Set_Acute(0, 0, 0, 0);
    return 0;
}

// 0x1775370
void effPCP_ThunderPolyListDelete(void **hData) {
    effPCP_ThunderPolyDelete(0);
}

// 0x1776880
void effPCP_ThunderPolyListDraw(void **hData) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    effColorMultiply(0, 0);
    effPCP_ThunderPolyListPartRefresh(0, 0, 0, 0);
    effPCP_ThunderPolyPartRefresh(0, 0);
    dds3TrackPolyDraw(0, 0);
}

// 0x1776700
void effPCP_ThunderPolyListDrawOff(void **hData) {
    dds3TrackPolyDrawOff(0);
}

// 0x17754d0
effPCP_ThunderPolyListParam_t *effPCP_ThunderPolyListGetParam(effPCP_ThunderPolyList_t *pTPolyList) {
  return pTPolyList->param;
}

// 0x17755d0
void effPCP_ThunderPolyListPartRefresh(effPCP_ThunderPoly_t **pThunderPoly, s32 number, sdfVector4_t **pPos, s32 pidx) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__OUTERPRODUCT();
    DDS3EFFECT_RAND_F();
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    sdfSin(0);
    SDF_VU0__MULVECTOR();
    SDF_VU0__ADDVECTOR_B_A();
    SDF_VU0__STOREVECTOR_B(0);
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__ADDVECTOR_A_C();
    SDF_VU0__COPYVECTOR_C_TO_A();
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__COPYVECTOR_B_TO_A();
    SDF_VU0__SUBVECTOR_B_A();
    DDS3EFFECT_RAND_PM();
    SetRotateMatrixAxis(0, (sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX_XYZ();
    SDF_VU0__INNERPRODUCT();
    SDF_VU0__LOADVECTOR_C((sdfVector4_t){0});
    SDF_VU0__COPYVECTOR_C_TO_B();
    SDF_VU0__ADDVECTOR();
}

// 0x17754e0
void effPCP_ThunderPolyListSetColor(void **hData, u32 abgr) {
}

// 0x1772dc0
effPCP_ThunderPolyLow_t *effPCP_ThunderPolyLowCreate(void **hData, s32 bPos, bool tbldata) {
    effPCP_ThunderPolyParam_t__pClone(0, 0);
    dds3TrackPolyCreate(0, 0, 0, 0);
    dds3TrackPolyVCSet(0, 0, 0, 0);
    dds3TrackPolySetMode(0, 0);
    effPCP_ThunderPolyLowPartInit(0, 0);
    return 0;
}

// 0x17730e0
void effPCP_ThunderPolyLowDelete(void **hData) {
    dds3TrackPolyDelete(0);
}

// 0x1773620
void effPCP_ThunderPolyLowDraw(void **hData) {
    effPCP_ThunderPolyLowPartRefresh(0, 0);
    effPCP_ThunderPolyLowPartInit(0, 0);
    dds3TrackPolyListInit(0, 0);
    effColorMultiply(0, 0);
    dds3TrackPolyDraw(0, 0);
}

// 0x17734f0
void effPCP_ThunderPolyLowDrawOff(void **hData) {
    dds3TrackPolyDrawOff(0);
}

// 0x1771ef0
void effPCP_ThunderPolyLowPartInit(effPCP_ThunderPolyLow_t **pThunderPoly, s32 number) {
  struct effPCP_ThunderPolyPart_t_array *pPart;
  effPCP_ThunderPolyPart_t_o *v7;

  pPart = (*pThunderPoly)->pPart;
  v7 = pPart->m_Items[number];
  v7->wait = DDS3EFFECT_RAND_I() % (*pThunderPoly)->param->interval;
  v7->refresh = DDS3EFFECT_RAND_I() % (*pThunderPoly)->param->refresh + 1;
  v7->abgr = -2139062144;
}

// 0x1771fe0
void effPCP_ThunderPolyLowPartRefresh(effPCP_ThunderPolyLow_t **pThunderPoly, s32 number) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__OUTERPRODUCT();
    DDS3EFFECT_RAND_F();
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    sdfSin(0);
    SDF_VU0__MULVECTOR();
    SDF_VU0__ADDVECTOR_B_A();
    SDF_VU0__STOREVECTOR_B(0);
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__ADDVECTOR_A_C();
    SDF_VU0__COPYVECTOR_C_TO_A();
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__SUBVECTOR_B_A();
    DDS3EFFECT_RAND_PM();
    SetRotateMatrixAxis(0, (sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX_XYZ();
    SDF_VU0__INNERPRODUCT();
    SDF_VU0__LOADVECTOR_C((sdfVector4_t){0});
    SDF_VU0__COPYVECTOR_C_TO_B();
    SDF_VU0__ADDVECTOR();
}

// 0x1773400
void effPCP_ThunderPolyLowSetColor(void **hData, u32 abgr) {
}

// 0x1773210
void effPCP_ThunderPolyLowSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__STOREVECTOR_B(0);
    SDF_VU0__SUBVECTOR_B_A();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(0);
}

// 0x1770300
void effPCP_ThunderPolyPartInit(effPCP_ThunderPoly_t **pThunderPoly, s32 number) {
  struct effPCP_ThunderPolyPart_t_array *pPart;
  effPCP_ThunderPolyPart_t_o *v7;

  pPart = (*pThunderPoly)->pPart;
  v7 = pPart->m_Items[number];
  v7->wait = DDS3EFFECT_RAND_I() % (*pThunderPoly)->param->interval;
  v7->refresh = DDS3EFFECT_RAND_I() % (*pThunderPoly)->param->refresh + 1;
  v7->abgr = -2139062144;
}

// 0x17703f0
void effPCP_ThunderPolyPartRefresh(effPCP_ThunderPoly_t **pThunderPoly, s32 number) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__OUTERPRODUCT();
    DDS3EFFECT_RAND_F();
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    sdfSin(0);
    SDF_VU0__MULVECTOR();
    SDF_VU0__ADDVECTOR_B_A();
    SDF_VU0__STOREVECTOR_B(0);
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__ADDVECTOR_A_C();
    SDF_VU0__COPYVECTOR_C_TO_A();
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__COPYVECTOR_B_TO_A();
    SDF_VU0__SUBVECTOR_B_A();
    DDS3EFFECT_RAND_PM();
    SetRotateMatrixAxis(0, (sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX_XYZ();
    SDF_VU0__INNERPRODUCT();
    SDF_VU0__LOADVECTOR_C((sdfVector4_t){0});
    SDF_VU0__COPYVECTOR_C_TO_B();
    SDF_VU0__ADDVECTOR();
}

// 0x1771790
void effPCP_ThunderPolySetColor(void **hData, u32 abgr) {
}

// 0x17715a0
void effPCP_ThunderPolySetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__STOREVECTOR_B(0);
    SDF_VU0__SUBVECTOR_B_A();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(0);
}

// 0x1771890
void effPCP_ThunderPolySetVCAcute(effPCP_ThunderPoly_t **pThunderPoly) {
  effPCP_ThunderPoly_t_o *v3;
  dds3TrackPoly_t_o **p_hPoly;
  struct effPCP_ThunderPolyParam_t_o *param;
  u32 color_center;
  u32 color_border;
  u32 color_edge;

  v3 = *pThunderPoly;
  p_hPoly = &(*pThunderPoly)->hPoly;
  param = v3->param;
  color_center = param->color_center;
  color_border = param->color_border;
  color_edge = param->color_edge;
  dds3TrackPolyVC5Set_Acute(p_hPoly, color_center, color_border, color_edge);
}

// 0x1771930
void effPCP_ThunderPolySetVCAcute2(effPCP_ThunderPoly_t **pThunderPoly) {
  effPCP_ThunderPoly_t_o *v3;
  dds3TrackPoly_t_o **p_hPoly;
  struct effPCP_ThunderPolyParam_t_o *param;
  u32 color_center;
  u32 color_border;
  u32 color_edge;

  v3 = *pThunderPoly;
  p_hPoly = &(*pThunderPoly)->hPoly;
  param = v3->param;
  color_center = param->color_center;
  color_border = param->color_border;
  color_edge = param->color_edge;
  dds3TrackPolyVC5Set_AcuteR(p_hPoly, color_center, color_border, color_edge);
}

// 0x17719d0
void effPCP_ThunderPolySetVCNormal(effPCP_ThunderPoly_t **pThunderPoly) {
  effPCP_ThunderPoly_t_o *v3;
  dds3TrackPoly_t_o **p_hPoly;
  struct effPCP_ThunderPolyParam_t_o *param;
  u32 color_center;
  u32 color_border;
  u32 color_edge;

  v3 = *pThunderPoly;
  p_hPoly = &(*pThunderPoly)->hPoly;
  param = v3->param;
  color_center = param->color_center;
  color_border = param->color_border;
  color_edge = param->color_edge;
  dds3TrackPolyVC5Set_Normal(p_hPoly, color_center, color_border, color_edge);
}

// 0x17745a0
effPCP_ThunderRadiatePoly_t *effPCP_ThunderRadiatePolyCreate(void **hData, s32 bPos, bool tbldata) {
    effPCP_ThunderRadiatePolyParam_t__pClone(0, 0);
    dds3TrackPolyCreate(0, 0, 0, 0);
    dds3TrackPolyVC3Set_Acute(0, 0, 0, 0);
    dds3TrackPolySetMode(0, 0);
    effPCP_ThunderRadiatePolyPartInit(0, 0);
    return 0;
}

// 0x1774860
void effPCP_ThunderRadiatePolyDelete(void **hData) {
    dds3TrackPolyDelete(0);
}

// 0x1774cb0
void effPCP_ThunderRadiatePolyDraw(void **hData) {
    effPCP_ThunderRadiatePolyPartRefresh(0, 0);
    effPCP_ThunderRadiatePolyPartInit(0, 0);
    dds3TrackPolyListInit(0, 0);
    dds3TrackPolyDraw(0, 0);
}

// 0x1774b90
void effPCP_ThunderRadiatePolyDrawOff(void **hData) {
    dds3TrackPolyDrawOff(0);
}

// 0x1773990
void effPCP_ThunderRadiatePolyPartInit(effPCP_ThunderRadiatePoly_t **pThunderRadiatePoly, s32 number) {
    DDS3EFFECT_RAND_PM();
    DDS3EFFECT_RAND_I();
}

// 0x1773ad0
void effPCP_ThunderRadiatePolyPartRefresh(effPCP_ThunderRadiatePoly_t **pThunderRadiatePoly, s32 number) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__OUTERPRODUCT();
    SDF_VU0__NORMALIZE();
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    SDF_VU0__MULVECTOR();
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__ADDVECTOR_A_C();
    SDF_VU0__COPYVECTOR_C_TO_A();
    SDF_VU0__SUBVECTOR_B_A();
    SDF_VU0__STOREVECTOR_B(0);
    DDS3EFFECT_RAND_F();
    SDF_VU0__ADDVECTOR();
    DDS3EFFECT_RAND_PM();
    SetRotateMatrixAxis(0, (sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX_XYZ();
    SDF_VU0__INNERPRODUCT();
    SDF_VU0__LOADVECTOR_C((sdfVector4_t){0});
    SDF_VU0__COPYVECTOR_C_TO_B();
}

// 0x1774aa0
void effPCP_ThunderRadiatePolySetColor(void **hData, u32 abgr) {
}

// 0x1774980
void effPCP_ThunderRadiatePolySetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}
