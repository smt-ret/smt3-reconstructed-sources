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
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  Il2CppClass *v10;
  u64 v11[3];

  v10 = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPThunderSpherePoly_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPThunderSpherePoly_t, v11);
    if ((v11[0] & 1) != 0)
      v8 = v11[2];
    else
      v8 = v11 + 1;
    v9 = sub_8C4940(v8);
  }
  v10 = (*hData)[1].klass;
  return effPCPThunderSpherePolyCreate(&v10, effPCPThunderSpherePoly_t, 0);
}

// 0x176b910
effPCPThunderSpherePoly_t *effPCPThunderSpherePolyCreate(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 *v10;
  u64 *v11;
  u64 v13;
  s32 v14;
  s32 v15;
  s64 v16;
  u32 *v18;
  u64 v19;
  u64 *v20;
  u64 v22;
  u64 v24;
  u64 v26;
  u64 v28;
  u64 v30[3];

  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPThunderSpherePolyParam_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPThunderSpherePolyParam_t, v30);
      if ((v30[0] & 1) != 0)
        v8 = v30[2];
      else
        v8 = v30 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = Allocate(effPCPThunderSpherePoly_t);
  effPCPThunderSpherePoly_t___ctor(v10);
  v11 = Allocate(effPCPThunderSpherePolyParam_t);
  effPCPThunderSpherePolyParam_t___ctor(v11);
  v10[2] = v11;
  effPCPThunderSpherePolyParam_t__pClone(v5, v10 + 2);
  v10[3] = NewSpecific(effPCPThunderSpherePolyPart_t, HIDWORD(v5[2].klass));
  v10[7] = 0;
  *(v10 + 9) = HIDWORD(v5[2].monitor);
  *(v10 + 10) = v5[3].klass;
  v13 = v10[2];
  v14 = *(v13 + 36);
  v15 = *(v13 + 64);
  v10[6] = dds3TrackPolyCreate(v14, v15, 0, 4);
  dds3TrackPolyVC5Set_AcuteW(v10 + 6, *(v10[2] + 72), *(v10[2] + 80), *(v10[2] + 88), 0);
  dds3TrackPolySetMode(v10 + 6, *(v10[2] + 32), 0);
  if (*(v10[2] + 36))
  {
    v16 = 4;
    do
    {
      v18 = v10[3];
      v19 = v16 - 4;
      v20 = Allocate(effPCPThunderSpherePolyPart_t);
      effPCPThunderSpherePolyPart_t___ctor(v20);
      *&v18[2 * v16] = v20;
      v22 = v10[3];
      *(*(v22 + 8 * v16) + 16LL) = 0;
      v24 = v10[3];
      *(*(v24 + 8 * v16) + 20LL) = 0;
      v26 = v10[3];
      *(*(v26 + 8 * v16) + 56LL) = 0;
      v28 = v16 - 3;
      ++v16;
    }
    while (v28 < *(v10[2] + 36));
  }
  *(v10 + 8) = -2139062144;
  return v10;
}

// 0x176bc30
effPCPThunderSpherePoly_t *effPCPThunderSpherePolyCreatePCF(void **hData, s32 bPos, bool tbldata) {
  dds3EffectPCPData_t_o *v6;
  Il2CppObject *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  struct dds3EffectPCPData_Part_t_array *pcpData;
  Il2CppObject *v14;
  u32 offset;
  Il2CppObject *DataUnityOffSet;
  s32 v18;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v22;
  s64 *v23;
  Il2CppObject *v25;
  u64 v26[2];
  char *v27;
  s32 pos;

  pos = bPos;
  v25 = 0;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v7->klass->_1.element_class, v8, v26);
      if ((v26[0] & 1) != 0)
        v10 = v27;
      else
        v10 = v26 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v6, Interface, &pos);
  pcpData = v6->pcpData;
  v14 = *hData;
  offset = pcpData->m_Items[0]->offset;
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 36);
  if (DataUnityOffSet)
  {
    klass = DataUnityOffSet->klass;
    if (DataUnityOffSet->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPThunderSpherePolyParam_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPThunderSpherePolyParam_t, v26);
      if ((v26[0] & 1) != 0)
        v22 = v27;
      else
        v22 = v26 + 1;
      v23 = sub_8C4940(v22);
    }
  }
  v25 = DataUnityOffSet;
  return effPCPThunderSpherePolyCreate(&v25, v18, 0);
}

// 0x176bf50
void effPCPThunderSpherePolyDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3TrackPoly_t_o **v8;
  u64 v9[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPThunderSpherePoly_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPThunderSpherePoly_t, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = &v3[3];
  dds3TrackPolyDelete(v8);
}

// 0x176c9e0
void effPCPThunderSpherePolyDraw(void **hData) {
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  s64 data_high;
  u32 v10;
  u64 i;
  u64 *monitor;
  u32 *v14;
  s64 v15;
  s64 v17;
  s32 v18;
  u32 v20;
  effPCPThunderSpherePoly_t_o *v22[3];
  effPCPThunderSpherePoly_t_o *pThunderPoly;

  pThunderPoly = 0;
  v4 = *hData;
  if (*hData)
  {
    klass = v4->klass;
    if (v4->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPThunderSpherePoly_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPThunderSpherePoly_t, v22);
      if ((v22[0] & 1) != 0)
        v7 = v22[2];
      else
        v7 = v22 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  pThunderPoly = *hData;
  data_high = HIDWORD(v4[1].klass->_1.byval_arg.data);
  if (data_high >= 1)
  {
    v10 = v4[2].klass;
    for (i = 0; i != data_high; ++i)
    {
      monitor = v4[1].monitor;
      v14 = monitor[i + 4];
      v15 = *&v4[3].klass->_1.byval_arg.bits;
      v17 = *(v15 + 8 * i + 32);
      v18 = v14[4];
      if (v18)
      {
        v14[4] = v18 - 1;
      }
      else if (v14[5])
      {
        effPCPThunderSpherePolyPartRefresh(&pThunderPoly, i);
        effPCPThunderSpherePolyPartMove(&pThunderPoly, i);
        --v14[5];
      }
      else
      {
        v20 = v14[14];
        if (HIBYTE(v20))
        {
          v14[14] = v20 - 0x20000000;
          effPCPThunderSpherePolyPartMove(&pThunderPoly, i);
        }
        else
        {
          effPCPThunderSpherePolyPartInit(&pThunderPoly, i);
          dds3TrackPolyListInit(&v4[3], i);
        }
      }
      *(v17 + 40) = effColorMultiply(v14[14], v10);
    }
  }
  dds3TrackPolyDraw(&v4[3], "effPCPThunderSpherePolyDraw");
}

// 0x176c8c0
void effPCPThunderSpherePolyDrawOff(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3TrackPoly_t_o **v8;
  u64 v9[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPThunderSpherePoly_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPThunderSpherePoly_t, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = &v3[3];
  dds3TrackPolyDrawOff(v8);
}

// 0x176c3a0
effPCPThunderSpherePolyParam_t *effPCPThunderSpherePolyGetParam(effPCPThunderSpherePoly_t *pThunderPoly) {
  return pThunderPoly->param;
}

// 0x176dcc0
effPCPThunderSpherePolyLow_t *effPCPThunderSpherePolyLowCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPThunderSpherePolyLow_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPThunderSpherePolyLow_t, v10);
    if ((v10[0] & 1) != 0)
      v8 = v10[2];
    else
      v8 = v10 + 1;
    v9 = sub_8C4940(v8);
  }
  return effPCPThunderSpherePolyLowCreate(
           (*hData)[1].klass,
           effPCPThunderSpherePolyLow_t);
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
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v11[3];

  v5 = *pData;
  if (*pData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPThunderSpherePolyParam_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPThunderSpherePolyParam_t, v11);
      if ((v11[0] & 1) != 0)
        v8 = v11[2];
      else
        v8 = v11 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  return effPCPThunderSpherePolyLowCreate(v5, *&bPos);
}

// 0x176dab0
effPCPThunderSpherePolyLow_t *effPCPThunderSpherePolyLowCreatePCF(void **hData, s32 bPos, bool tbldata) {
  dds3EffectPCPData_t_o *v6;
  Il2CppObject *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  struct dds3EffectPCPData_Part_t_array *pcpData;
  Il2CppObject *v14;
  u32 offset;
  Il2CppObject *DataUnityOffSet;
  effPCPThunderSpherePolyParam_t_c *v18;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v21;
  s64 *v22;
  u64 v24[2];
  char *v25;
  s32 pos;

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v7->klass->_1.element_class, v8, v24);
      if ((v24[0] & 1) != 0)
        v10 = v25;
      else
        v10 = v24 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v6, Interface, &pos);
  pcpData = v6->pcpData;
  v14 = *hData;
  offset = pcpData->m_Items[0]->offset;
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 36);
  if (DataUnityOffSet)
  {
    klass = DataUnityOffSet->klass;
    if (DataUnityOffSet->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPThunderSpherePolyParam_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPThunderSpherePolyParam_t, v24);
      if ((v24[0] & 1) != 0)
        v21 = v25;
      else
        v21 = v24 + 1;
      v22 = sub_8C4940(v21);
    }
  }
  return effPCPThunderSpherePolyLowCreate(DataUnityOffSet, v18);
}

// 0x176d990
void effPCPThunderSpherePolyLowDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3TrackPoly_t_o **v8;
  u64 v9[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPThunderSpherePolyLow_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPThunderSpherePolyLow_t, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = &v3[3];
  dds3TrackPolyDelete(v8);
}

// 0x176e5d0
void effPCPThunderSpherePolyLowDraw(void **hData) {
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  s64 data_high;
  u32 v10;
  u64 i;
  u64 *monitor;
  u32 *v14;
  s64 v15;
  s64 v17;
  s32 v18;
  u32 v20;
  effPCPThunderSpherePolyLow_t_o *v22[3];
  effPCPThunderSpherePolyLow_t_o *pThunderPoly;

  pThunderPoly = 0;
  v4 = *hData;
  if (*hData)
  {
    klass = v4->klass;
    if (v4->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPThunderSpherePolyLow_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPThunderSpherePolyLow_t, v22);
      if ((v22[0] & 1) != 0)
        v7 = v22[2];
      else
        v7 = v22 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  pThunderPoly = *hData;
  data_high = HIDWORD(v4[1].klass->_1.byval_arg.data);
  if (data_high >= 1)
  {
    v10 = v4[2].klass;
    for (i = 0; i != data_high; ++i)
    {
      monitor = v4[1].monitor;
      v14 = monitor[i + 4];
      v15 = *&v4[3].klass->_1.byval_arg.bits;
      v17 = *(v15 + 8 * i + 32);
      v18 = v14[4];
      if (v18)
      {
        v14[4] = v18 - 1;
      }
      else if (v14[5])
      {
        effPCPThunderSpherePolyLowPartRefresh(&pThunderPoly, i);
        effPCPThunderSpherePolyLowPartMove(&pThunderPoly, i);
        --v14[5];
      }
      else
      {
        v20 = v14[14];
        if (HIBYTE(v20))
        {
          v14[14] = v20 - 0x20000000;
          effPCPThunderSpherePolyLowPartMove(&pThunderPoly, i);
        }
        else
        {
          effPCPThunderSpherePolyLowPartInit(&pThunderPoly, i);
          dds3TrackPolyListInit(&v4[3], i);
        }
      }
      *(v17 + 40) = effColorMultiply(v14[14], v10);
    }
  }
  dds3TrackPolyDraw(&v4[3], "effPCPThunderSpherePolyLowDraw");
}

// 0x176e4b0
void effPCPThunderSpherePolyLowDrawOff(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3TrackPoly_t_o **v8;
  u64 v9[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPThunderSpherePolyLow_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPThunderSpherePolyLow_t, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = &v3[3];
  dds3TrackPolyDrawOff(v8);
}

// 0x176e0e0
effPCPThunderSpherePolyParam_t *effPCPThunderSpherePolyLowGetParam(effPCPThunderSpherePolyLow_t *pThunderPoly) {
  return pThunderPoly->param;
}

// 0x176cc70
void effPCPThunderSpherePolyLowPartInit(effPCPThunderSpherePolyLow_t **pThunderPoly, s32 number) {
  struct effPCPThunderSpherePolyPart_t_array *pPart;
  effPCPThunderSpherePolyPart_t_o *v7;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  f32 v13;
  f32 refraction;
  f32 width;
  f32 v16;
  UnityEngine_Vector4_o v17;

  *&v17.x = 0;
  *&v17.z = 0;
  pPart = (*pThunderPoly)->pPart;
  v7 = pPart->m_Items[number];
  v7->wait = DDS3EFFECT_RAND_I() % (*pThunderPoly)->param->interval;
  v7->refresh = DDS3EFFECT_RAND_I() % (*pThunderPoly)->param->refresh + 1;
  DDS3EFFECT_RAND_PM();
  sub_854930(&v17, 0);
  sub_854930(&v17, 1u);
  DDS3EFFECT_RAND_PM();
  sub_854930(&v17, 2u);
  SDF_VU0__LOADVECTOR(v17);
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v17);
  DDS3EFFECT_RAND_PM();
  sub_854930(&v17, 1u);
  sub_854710(&v17, 0);
  sub_8529B0(&v7->dir, 0, v8);
  sub_854710(&v17, 1u);
  sub_8529B0(&v7->dir, 1, v9);
  sub_854710(&v17, 2u);
  sub_8529B0(&v7->dir, 2, v10);
  DDS3EFFECT_RAND_PM();
  sub_854930(&v17, 0);
  sub_854930(&v17, 1u);
  DDS3EFFECT_RAND_PM();
  sub_854930(&v17, 2u);
  SDF_VU0__LOADVECTOR(v17);
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v17);
  sub_854710(&v17, 0);
  sub_8529B0(&v7->axis, 0, v11);
  sub_854710(&v17, 1u);
  sub_8529B0(&v7->axis, 1, v12);
  sub_854710(&v17, 2u);
  sub_8529B0(&v7->axis, 2, v13);
  refraction = (*pThunderPoly)->param->refraction;
  v7->rotate = refraction * ((DDS3EFFECT_RAND_PM() * 0.4) + 1.0);
  width = (*pThunderPoly)->param->width;
  v16 = DDS3EFFECT_RAND_PM();
  v7->abgr = -2139062144;
  v7->radius = (width * 0.5) * ((v16 * 0.3) + 1.0);
}

// 0x176e0f0
void effPCPThunderSpherePolyLowPartMove(effPCPThunderSpherePolyLow_t **pThunderPoly, s32 number) {
  u64 *v5;
  struct effPCPThunderSpherePolyPart_t_array *pPart;
  struct dds3TrackPoly_t_o *hPoly;
  struct dds3TrackPolyList_t_array *trackList;
  effPCPThunderSpherePolyPart_t_o *v11;
  Il2CppClass **v13;
  s32 point;
  const char *name;
  f32 rotate;
  s64 p_dir;
  f32 v18;
  f32 *p_x;
  s64 v21;
  s64 v22;
  f32 v23;
  f32 v24;
  u64 v25;
  s32 v26;
  UnityEngine_Vector4_o *v27;
  UnityEngine_Vector4_o v32;
  s64 v33;
  s64 v34;
  UnityEngine_Vector4_o v35;

  v5 = Allocate(dds3TrackPolyList_t);
  dds3TrackPolyList_t___ctor(v5);
  v33 = 0;
  v34 = 0;
  *&v32.x = 0;
  *&v32.z = 0;
  pPart = (*pThunderPoly)->pPart;
  hPoly = (*pThunderPoly)->hPoly;
  trackList = hPoly->trackList;
  v11 = pPart->m_Items[number];
  v13 = &trackList->obj.klass + number;
  point = hPoly->point;
  name = v13[4]->_1.name;
  rotate = v11->rotate;
  p_dir = &v11->dir;
  v18 = DDS3EFFECT_RAND_F();
  sub_8527D0(&v11->dir.x, 0);
  sub_854930(&v32, 0);
  sub_854930(&v32, 1u);
  sub_8527D0(&v11->dir.x, 2);
  sub_854930(&v32, 2u);
  p_x = &v11->axis.x;
  sub_8527D0(p_x, 0);
  sub_854930(&v33, 0);
  sub_8527D0(p_x, 1);
  sub_854930(&v33, 1u);
  sub_8527D0(p_x, 2);
  sub_854930(&v33, 2u);
  v21 = v33;
  v22 = v34;
  *&v35.x = v21;
  *&v35.z = v22;
  SetRotateMatrixAxis((rotate * v18) * 3.0, v35, 0);
  SDF_VU0__LOADVECTOR(v32);
  SDF_VU0__APPLYMATRIX_XYZ();
  SDF_VU0__STOREVECTOR(&v32);
  sub_854710(&v32, 0);
  sub_8529B0(p_dir, 0, v23);
  sub_854710(&v32, 2u);
  sub_8529B0(p_dir, 2, v24);
  SDF_VU0__LOADVECTOR_B((*pThunderPoly)->param->pos, 0);
  if (point >= 2)
  {
    v25 = 0;
    v26 = 0;
    v27 = (name + 32);
    do
    {
      SDF_VU0__LOADVECTOR(*v27);
      SDF_VU0__SUBVECTOR();
      SDF_VU0__APPLYMATRIX_XYZ();
      SDF_VU0__ADDVECTOR();
      SDF_VU0__STOREVECTOR(v27);
      SDF_VU0__LOADVECTOR(v27[1]);
      SDF_VU0__SUBVECTOR();
      SDF_VU0__APPLYMATRIX_XYZ();
      SDF_VU0__ADDVECTOR();
      SDF_VU0__STOREVECTOR(v27 + 1);
      ++v26;
      v27 += 2;
      v25 += 2LL;
    }
    while (v26 < point >> 1);
  }
}

// 0x176cfb0
void effPCPThunderSpherePolyLowPartRefresh(effPCPThunderSpherePolyLow_t **pThunderPoly, s32 number) {
  u64 *v5;
  u64 *v6;
  struct effPCPThunderSpherePolyPart_t_array *pPart;
  u64 *v9;
  struct dds3TrackPoly_t_o *hPoly;
  struct dds3TrackPolyList_t_array *trackList;
  f32 *v13;
  dds3TrackPolyList_t_o *v15;
  s32 point;
  struct UnityEngine_Vector4_array *pVertex;
  u64 v20;
  s32 v21;
  s32 v22;
  UnityEngine_Vector4_o *m_Items;
  f32 v25;
  f32 v27;
  f32 v30;
  f32 v32;
  f32 v33;
  u64 v35;
  UnityEngine_Vector4_o v37;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v40;
  UnityEngine_Vector4_o v41;
  UnityEngine_Vector4_o v42;
  UnityEngine_Vector4_o v43;

  v5 = Allocate(dds3TrackPolyList_t);
  dds3TrackPolyList_t___ctor(v5);
  *&v43.x = 0;
  *&v43.z = 0;
  *&v42.x = 0;
  *&v42.z = 0;
  *&v41.x = 0;
  *&v41.z = 0;
  *&v40.x = 0;
  *&v40.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  *&v37.x = 0;
  *&v37.z = 0;
  v6 = NewSpecific(f32, 3u);
  pPart = (*pThunderPoly)->pPart;
  v9 = v6;
  hPoly = (*pThunderPoly)->hPoly;
  trackList = hPoly->trackList;
  v13 = pPart->m_Items[number];
  v15 = trackList->m_Items[number];
  point = hPoly->point;
  pVertex = v15->pVertex;
  v15->count = point;
  DDS3EFFECT_RAND_PM();
  sub_854930(&v37, 0);
  sub_854710(&v37, 0);
  sub_854930(&v37, 1u);
  sub_854930(&v37, 2u);
  sub_8527D0(v13 + 9, 0);
  sub_854930(&v40, 0);
  sub_8527D0(v13 + 9, 1);
  sub_854930(&v40, 1u);
  sub_8527D0(v13 + 9, 2);
  sub_854930(&v40, 2u);
  sub_854930(&v40, 3u);
  SDF_VU0__LOADVECTOR(dds3CameraTargetPos);
  SDF_VU0__LOADVECTOR_B(dds3CameraEyePos);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__STOREVECTOR(&p);
  sub_8527D0(v13 + 6, 0);
  sub_854930(&v42, 0);
  sub_854930(&v42, 1u);
  sub_8527D0(v13 + 6, 2);
  sub_854930(&v42, 2u);
  SDF_VU0__COPYVECTOR(&dst, (*pThunderPoly)->param->pos, 0);
  sub_854710(&dst, 1u);
  sub_8527D0(v13 + 6, 1);
  sub_854930(&dst, 1u);
  if (point >= 2)
  {
    v20 = 0;
    v21 = 0;
    v22 = point >> 1;
    m_Items = pVertex->m_Items;
    do
    {
      sub_854710(&dst, 0);
      sub_854710(&v42, 0);
      sub_854930(&v43, 0);
      sub_854710(&dst, 1u);
      sub_854710(&v42, 1u);
      sub_854930(&v43, 1u);
      sub_854710(&dst, 2u);
      sub_854710(&v42, 2u);
      sub_854930(&v43, 2u);
      SDF_VU0__COPYVECTOR(&v41, v40);
      v25 = DDS3EFFECT_RAND_F();
      *(v9 + 8) = v25 * 1.5708;
      v27 = DDS3EFFECT_RAND_F();
      *(v9 + 9) = v27 * 1.5708;
      v30 = DDS3EFFECT_RAND_F();
      *(v9 + 10) = v30 * 1.5708;
      SetRotateMatrixXYZ(v9);
      SDF_VU0__LOADVECTOR(v41);
      SDF_VU0__APPLYMATRIX_XYZ();
      SDF_VU0__STOREVECTOR(&v41);
      v32 = v13[12];
      v33 = DDS3EFFECT_RAND_PM();
      SetRotateMatrixAxis(-(v32 * ((v33 * 0.8) + 1.0)), v41, 0);
      SDF_VU0__LOADVECTOR(v42);
      SDF_VU0__COPYVECTOR_A_TO_B();
      SDF_VU0__APPLYMATRIX_XYZ();
      SDF_VU0__STOREVECTOR(&v42);
      SDF_VU0__SUBVECTOR();
      SDF_VU0__LOADVECTOR_B(p);
      SDF_VU0__OUTERPRODUCT();
      SDF_VU0__NORMALIZE();
      SDF_VU0__LOADVECTOR_B(v37);
      SDF_VU0__MULVECTOR();
      SDF_VU0__COPYVECTOR_A_TO_C();
      SDF_VU0__LOADVECTOR(v43);
      SDF_VU0__COPYVECTOR_A_TO_B();
      SDF_VU0__ADDVECTOR_A_C();
      SDF_VU0__STOREVECTOR(m_Items);
      SDF_VU0__COPYVECTOR_C_TO_A();
      SDF_VU0__SUBVECTOR_B_A();
      v35 = v20 + 1;
      SDF_VU0__STOREVECTOR_B(m_Items + 1);
      ++v21;
      m_Items += 2;
      v20 = v35 + 1;
    }
    while (v21 < v22);
  }
}

// 0x176ded0
void effPCPThunderSpherePolyLowSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPThunderSpherePolyLow_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPThunderSpherePolyLow_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[2].klass) = abgr;
}

// 0x176ddb0
void effPCPThunderSpherePolyLowSetPosition(void **hData, sdfVector4_t pPos) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v10;
  s64 *v11;
  u64 v12[3];
  UnityEngine_Vector4_o v13;

  w = pPos.w;
  z = pPos.z;
  y = pPos.y;
  x = pPos.x;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPThunderSpherePolyLow_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPThunderSpherePolyLow_t, v12);
    if ((v12[0] & 1) != 0)
      v10 = v12[2];
    else
      v10 = v12 + 1;
    v11 = sub_8C4940(v10);
  }
  v13.x = x;
  v13.y = y;
  v13.z = z;
  v13.w = w;
  SDF_VU0__COPYVECTOR(&(*hData)[1].klass->_1.name, v13, 0);
}

// 0x176dfc0
void effPCPThunderSpherePolyLowSetScale(void **hData, f32 scale) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPThunderSpherePolyLow_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPThunderSpherePolyLow_t, v10);
      if ((v10[0] & 1) != 0)
        v8 = v10[2];
      else
        v8 = v10 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  *(&v5[1].klass->_1.byval_arg.bits + 1) = *(&v5[2].klass + 1) * scale;
  *&v5[1].klass->_1.this_arg.data = *&v5[2].monitor * scale;
}

// 0x176ae00
void effPCPThunderSpherePolyPartInit(effPCPThunderSpherePoly_t **pThunderPoly, s32 number) {
  struct effPCPThunderSpherePolyPart_t_array *pPart;
  effPCPThunderSpherePolyPart_t_o *v7;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  f32 v13;
  f32 refraction;
  f32 width;
  f32 v16;
  UnityEngine_Vector4_o v17;

  *&v17.x = 0;
  *&v17.z = 0;
  pPart = (*pThunderPoly)->pPart;
  v7 = pPart->m_Items[number];
  v7->wait = DDS3EFFECT_RAND_I() % (*pThunderPoly)->param->interval;
  v7->refresh = DDS3EFFECT_RAND_I() % (*pThunderPoly)->param->refresh + 1;
  DDS3EFFECT_RAND_PM();
  sub_854930(&v17, 0);
  sub_854930(&v17, 1u);
  DDS3EFFECT_RAND_PM();
  sub_854930(&v17, 2u);
  SDF_VU0__LOADVECTOR(v17);
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v17);
  DDS3EFFECT_RAND_PM();
  sub_854930(&v17, 1u);
  sub_854710(&v17, 0);
  sub_8529B0(&v7->dir, 0, v8);
  sub_854710(&v17, 1u);
  sub_8529B0(&v7->dir, 1, v9);
  sub_854710(&v17, 2u);
  sub_8529B0(&v7->dir, 2, v10);
  DDS3EFFECT_RAND_PM();
  sub_854930(&v17, 0);
  sub_854930(&v17, 1u);
  DDS3EFFECT_RAND_PM();
  sub_854930(&v17, 2u);
  SDF_VU0__LOADVECTOR(v17);
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v17);
  sub_854710(&v17, 0);
  sub_8529B0(&v7->axis, 0, v11);
  sub_854710(&v17, 1u);
  sub_8529B0(&v7->axis, 1, v12);
  sub_854710(&v17, 2u);
  sub_8529B0(&v7->axis, 2, v13);
  refraction = (*pThunderPoly)->param->refraction;
  v7->rotate = refraction * ((DDS3EFFECT_RAND_PM() * 0.4) + 1.0);
  width = (*pThunderPoly)->param->width;
  v16 = DDS3EFFECT_RAND_PM();
  v7->abgr = -2139062144;
  v7->radius = (width * 0.5) * ((v16 * 0.3) + 1.0);
}

// 0x176c3b0
void effPCPThunderSpherePolyPartMove(effPCPThunderSpherePoly_t **pThunderPoly, s32 number) {
  struct effPCPThunderSpherePolyPart_t_array *pPart;
  struct dds3TrackPoly_t_o *hPoly;
  struct dds3TrackPolyList_t_array *trackList;
  effPCPThunderSpherePolyPart_t_o *v9;
  Il2CppClass **v11;
  s32 point;
  const char *name;
  f32 rotate;
  s64 p_dir;
  f32 v16;
  f32 *p_x;
  s64 v19;
  s64 v20;
  f32 v21;
  f32 v22;
  s32 v23;
  u64 v24;
  const char *v25;
  u64 v28;
  u64 v31;
  u64 v34;
  u64 v37;
  UnityEngine_Vector4_o v40;
  s64 v41;
  s64 v42;
  UnityEngine_Vector4_o v43;

  v41 = 0;
  v42 = 0;
  *&v40.x = 0;
  *&v40.z = 0;
  pPart = (*pThunderPoly)->pPart;
  hPoly = (*pThunderPoly)->hPoly;
  trackList = hPoly->trackList;
  v9 = pPart->m_Items[number];
  v11 = &trackList->obj.klass + number;
  point = hPoly->point;
  name = v11[4]->_1.name;
  rotate = v9->rotate;
  p_dir = &v9->dir;
  v16 = DDS3EFFECT_RAND_F();
  sub_8527D0(&v9->dir.x, 0);
  sub_854930(&v40, 0);
  sub_854930(&v40, 1u);
  sub_8527D0(&v9->dir.x, 2);
  sub_854930(&v40, 2u);
  p_x = &v9->axis.x;
  sub_8527D0(p_x, 0);
  sub_854930(&v41, 0);
  sub_8527D0(p_x, 1);
  sub_854930(&v41, 1u);
  sub_8527D0(p_x, 2);
  sub_854930(&v41, 2u);
  v19 = v41;
  v20 = v42;
  *&v43.x = v19;
  *&v43.z = v20;
  SetRotateMatrixAxis((rotate * v16) * 3.0, v43, 0);
  SDF_VU0__LOADVECTOR(v40);
  SDF_VU0__APPLYMATRIX_XYZ();
  SDF_VU0__STOREVECTOR(&v40);
  sub_854710(&v40, 0);
  sub_8529B0(p_dir, 0, v21);
  sub_854710(&v40, 2u);
  sub_8529B0(p_dir, 2, v22);
  SDF_VU0__LOADVECTOR_B((*pThunderPoly)->param->pos, 0);
  if (point >= 5)
  {
    v23 = point / 5;
    v24 = 0;
    v25 = name + 56;
    do
    {
      SDF_VU0__LOADVECTOR(*(v25 - 24), 0);
      SDF_VU0__SUBVECTOR();
      SDF_VU0__APPLYMATRIX_XYZ();
      SDF_VU0__ADDVECTOR();
      SDF_VU0__STOREVECTOR((v25 - 24), 0);
      v28 = v24 + 1;
      SDF_VU0__LOADVECTOR(*(v25 - 8), 0);
      SDF_VU0__SUBVECTOR();
      SDF_VU0__APPLYMATRIX_XYZ();
      SDF_VU0__ADDVECTOR();
      SDF_VU0__STOREVECTOR((v25 - 8), 0);
      v31 = v28 + 1;
      SDF_VU0__LOADVECTOR(*(v25 + 8), 0);
      SDF_VU0__SUBVECTOR();
      SDF_VU0__APPLYMATRIX_XYZ();
      SDF_VU0__ADDVECTOR();
      SDF_VU0__STOREVECTOR((v25 + 8), 0);
      v34 = v31 + 1;
      SDF_VU0__LOADVECTOR(*(v25 + 24), 0);
      SDF_VU0__SUBVECTOR();
      SDF_VU0__APPLYMATRIX_XYZ();
      SDF_VU0__ADDVECTOR();
      SDF_VU0__STOREVECTOR((v25 + 24), 0);
      v37 = v34 + 1;
      SDF_VU0__LOADVECTOR(*(v25 + 40), 0);
      SDF_VU0__SUBVECTOR();
      SDF_VU0__APPLYMATRIX_XYZ();
      SDF_VU0__ADDVECTOR();
      SDF_VU0__STOREVECTOR((v25 + 40), 0);
      v25 += 80;
      --v23;
      v24 = v37 + 1;
    }
    while (v23);
  }
}

// 0x176b140
void effPCPThunderSpherePolyPartRefresh(effPCPThunderSpherePoly_t **pThunderPoly, s32 number) {
  u64 *v5;
  struct effPCPThunderSpherePolyPart_t_array *pPart;
  u64 *v8;
  struct dds3TrackPoly_t_o *hPoly;
  f32 *v11;
  struct dds3TrackPolyList_t_array *trackList;
  dds3TrackPolyList_t_o *v14;
  s32 point;
  struct UnityEngine_Vector4_array *pVertex;
  f32 v19;
  s32 v20;
  UnityEngine_Vector4_o *v21;
  u64 v22;
  f32 v24;
  f32 v26;
  f32 v29;
  f32 v31;
  UnityEngine_Vector4_o v37;
  UnityEngine_Vector4_o v38;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v41;
  UnityEngine_Vector4_o v42;
  UnityEngine_Vector4_o v43;
  UnityEngine_Vector4_o v44;
  UnityEngine_Vector4_o v45;

  *&v45.x = 0;
  *&v45.z = 0;
  *&v44.x = 0;
  *&v44.z = 0;
  *&v43.x = 0;
  *&v43.z = 0;
  *&v42.x = 0;
  *&v42.z = 0;
  *&v41.x = 0;
  *&v41.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  *&v38.x = 0;
  *&v38.z = 0;
  *&v37.x = 0;
  *&v37.z = 0;
  v5 = NewSpecific(f32, 3u);
  pPart = (*pThunderPoly)->pPart;
  v8 = v5;
  hPoly = (*pThunderPoly)->hPoly;
  v11 = pPart->m_Items[number];
  trackList = hPoly->trackList;
  v14 = trackList->m_Items[number];
  point = hPoly->point;
  pVertex = v14->pVertex;
  v14->count = point;
  DDS3EFFECT_RAND_PM();
  sub_854930(&v38, 0);
  sub_854710(&v38, 0);
  sub_854930(&v38, 1u);
  sub_854930(&v38, 2u);
  sub_854710(&v38, 0);
  sub_854930(&v37, 0);
  sub_854710(&v37, 0);
  sub_854930(&v37, 1u);
  sub_854930(&v37, 2u);
  sub_8527D0(v11 + 9, 0);
  sub_854930(&v42, 0);
  sub_8527D0(v11 + 9, 1);
  sub_854930(&v42, 1u);
  sub_8527D0(v11 + 9, 2);
  sub_854930(&v42, 2u);
  sub_854930(&v42, 3u);
  v19 = v11[12];
  SDF_VU0__LOADVECTOR(dds3CameraTargetPos);
  SDF_VU0__LOADVECTOR_B(dds3CameraEyePos);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__STOREVECTOR(&p);
  sub_8527D0(v11 + 6, 0);
  sub_854930(&v44, 0);
  sub_854930(&v44, 1u);
  sub_8527D0(v11 + 6, 2);
  sub_854930(&v44, 2u);
  SDF_VU0__COPYVECTOR(&dst, (*pThunderPoly)->param->pos, 0);
  sub_854710(&dst, 1u);
  sub_8527D0(v11 + 6, 1);
  sub_854930(&dst, 1u);
  if (point >= 5)
  {
    v20 = point / 5;
    v21 = &pVertex->m_Items[4];
    v22 = 4;
    do
    {
      sub_854710(&dst, 0);
      sub_854710(&v44, 0);
      sub_854930(&v45, 0);
      sub_854710(&dst, 1u);
      sub_854710(&v44, 1u);
      sub_854930(&v45, 1u);
      sub_854710(&dst, 2u);
      sub_854710(&v44, 2u);
      sub_854930(&v45, 2u);
      SDF_VU0__COPYVECTOR(&v43, v42);
      v24 = DDS3EFFECT_RAND_F();
      *(v8 + 8) = v24 * 1.309;
      v26 = DDS3EFFECT_RAND_F();
      *(v8 + 9) = v26 * 1.309;
      v29 = DDS3EFFECT_RAND_F();
      *(v8 + 10) = v29 * 1.309;
      SetRotateMatrixXYZ(v8);
      SDF_VU0__LOADVECTOR(v43);
      SDF_VU0__APPLYMATRIX_XYZ();
      SDF_VU0__STOREVECTOR(&v43);
      v31 = DDS3EFFECT_RAND_PM();
      SetRotateMatrixAxis(-(v19 * ((v31 * 0.7) + 1.0)), v43, 0);
      SDF_VU0__LOADVECTOR(v44);
      SDF_VU0__COPYVECTOR_A_TO_B();
      SDF_VU0__APPLYMATRIX_XYZ();
      SDF_VU0__STOREVECTOR(&v44);
      SDF_VU0__SUBVECTOR();
      SDF_VU0__LOADVECTOR_B(p);
      SDF_VU0__OUTERPRODUCT();
      SDF_VU0__NORMALIZE();
      SDF_VU0__STOREVECTOR(&v41);
      SDF_VU0__LOADVECTOR_B(v38);
      SDF_VU0__MULVECTOR();
      SDF_VU0__COPYVECTOR_A_TO_C();
      SDF_VU0__LOADVECTOR(v45);
      SDF_VU0__STOREVECTOR(v21 - 2);
      SDF_VU0__COPYVECTOR_A_TO_B();
      SDF_VU0__ADDVECTOR_A_C();
      SDF_VU0__STOREVECTOR(v21 - 3);
      SDF_VU0__COPYVECTOR_C_TO_A();
      SDF_VU0__SUBVECTOR_B_A();
      SDF_VU0__STOREVECTOR_B(v21 - 1);
      SDF_VU0__LOADVECTOR(v41);
      SDF_VU0__LOADVECTOR_B(v37);
      SDF_VU0__MULVECTOR();
      SDF_VU0__COPYVECTOR_A_TO_C();
      SDF_VU0__LOADVECTOR(v45);
      SDF_VU0__COPYVECTOR_A_TO_B();
      SDF_VU0__ADDVECTOR_A_C();
      SDF_VU0__STOREVECTOR(v21 - 4);
      SDF_VU0__COPYVECTOR_C_TO_A();
      SDF_VU0__SUBVECTOR_B_A();
      SDF_VU0__STOREVECTOR_B(v21);
      v21 += 5;
      v22 += 5LL;
      --v20;
    }
    while (v20);
  }
}

// 0x176c190
void effPCPThunderSpherePolySetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPThunderSpherePoly_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPThunderSpherePoly_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[2].klass) = abgr;
}

// 0x176c070
void effPCPThunderSpherePolySetPosition(void **hData, sdfVector4_t pPos) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v10;
  s64 *v11;
  u64 v12[3];
  UnityEngine_Vector4_o v13;

  w = pPos.w;
  z = pPos.z;
  y = pPos.y;
  x = pPos.x;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPThunderSpherePoly_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPThunderSpherePoly_t, v12);
    if ((v12[0] & 1) != 0)
      v10 = v12[2];
    else
      v10 = v12 + 1;
    v11 = sub_8C4940(v10);
  }
  v13.x = x;
  v13.y = y;
  v13.z = z;
  v13.w = w;
  SDF_VU0__COPYVECTOR(&(*hData)[1].klass->_1.name, v13, 0);
}

// 0x176c280
void effPCPThunderSpherePolySetScale(void **hData, f32 scale) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPThunderSpherePoly_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPThunderSpherePoly_t, v10);
      if ((v10[0] & 1) != 0)
        v8 = v10[2];
      else
        v8 = v10 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  *(&v5[1].klass->_1.byval_arg.bits + 1) = *(&v5[2].klass + 1) * scale;
  *&v5[1].klass->_1.this_arg.data = *&v5[2].monitor * scale;
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
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v11[3];

  v5 = *pData;
  if (*pData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_ThunderColumnPolyLowParam_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCP_ThunderColumnPolyLowParam_t, v11);
      if ((v11[0] & 1) != 0)
        v8 = v11[2];
      else
        v8 = v11 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  return effPCP_ThunderColumnPolyLowCreate(v5, *&bPos);
}

// 0x176f900
void effPCP_ThunderColumnPolyLowDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s64 v8;
  u64 i;
  u64 *monitor;
  dds3TrackPoly_t_o **v12;
  u64 v13[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_ThunderColumnPolyLow_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCP_ThunderColumnPolyLow_t, v13);
      if ((v13[0] & 1) != 0)
        v6 = v13[2];
      else
        v6 = v13 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = *(&v3[1].klass->_1.byval_arg.bits + 1);
  if (v8 >= 1)
  {
    for (i = 0; i != v8; ++i)
    {
      monitor = v3[1].monitor;
      v12 = (monitor[i + 4] + 48LL);
      dds3TrackPolyDelete(v12);
    }
  }
}

// 0x176fc80
void effPCP_ThunderColumnPolyLowDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  u64 *v9;
  Il2CppClass *v10;
  s32 data_high;
  f32 v12;
  f32 v13;
  s32 data_low;
  s64 v17;
  u64 v18;
  u64 *monitor;
  s64 v21;
  s32 v22;
  f32 v24;
  f32 v26;
  f32 v27;
  f32 v28;
  f32 v29;
  u32 v31;
  f32 v32;
  s32 v33;
  u32 v34;
  s64 v35;
  u32 v36;
  s64 v38;
  s64 v39;
  s64 v41;
  s64 v43;
  s64 v45;
  s64 v47;
  s64 v49;
  s32 element_class;
  s32 v54;
  u32 abgr1;
  s32 v56;
  s64 bits;
  UnityEngine_Vector4_o dst;
  s64 v59;
  s64 v60;
  effPCP_ThunderColumnPolyLow_t_o *pThunderPoly;
  u64 v62[3];

  v60 = 0;
  pThunderPoly = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  v59 = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_ThunderColumnPolyLow_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCP_ThunderColumnPolyLow_t, v62);
      if ((v62[0] & 1) != 0)
        v6 = v62[2];
      else
        v6 = v62 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  pThunderPoly = *hData;
  v8 = Allocate(effPCP_ThunderColumnPolyLowPart_t);
  effPCP_ThunderColumnPolyLowPart_t___ctor(v8);
  v9 = Allocate(dds3TrackPolyList_t);
  dds3TrackPolyList_t___ctor(v9);
  v59 = 0;
  v60 = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  v10 = v3[1].klass;
  data_high = HIDWORD(v10->_1.this_arg.data);
  bits = v10->_1.this_arg.bits;
  v56 = *(&v10->_1.this_arg.bits + 1);
  element_class = v10->_1.element_class;
  abgr1 = v3[2].klass;
  v12 = *(&v10->_1.generic_class + 1);
  v13 = *&v10->_1.parent;
  data_low = LOBYTE(v10->_1.this_arg.data);
  SDF_VU0__COPYVECTOR(&dst, *&v10->_1.name);
  v17 = *(&v3[1].klass->_1.byval_arg.bits + 1);
  if (v17 >= 1)
  {
    v18 = 0;
    v54 = data_low;
    do
    {
      while (1)
      {
        monitor = v3[1].monitor;
        v21 = monitor[v18 + 4];
        v22 = *(v21 + 16);
        if (v22)
          break;
        effPCP_ThunderColumnPolyLowPartInit(&pThunderPoly, v18);
        dds3TrackPolyListInit((v21 + 48), 0, 0);
LABEL_28:
        if (data_low)
          goto LABEL_29;
LABEL_57:
        ++v18;
        ++*(v21 + 16);
        if (v17 == v18)
          return;
      }
      if (v22 < 1 || data_high < v22)
        goto LABEL_28;
      v24 = *(v21 + 28);
      sub_854710(&dst, 0);
      sdfCos(v24);
      sub_854930(&v59, 0);
      sub_854710(&dst, 1u);
      sub_854930(&v59, 1u);
      sub_854710(&dst, 2u);
      sdfSin(v24);
      sub_854930(&v59, 2u);
      v26 = *(v21 + 24);
      v27 = *(v21 + 32);
      v28 = *(v21 + 28) + v27;
      *(v21 + 20) = *(v21 + 20) + v26;
      *(v21 + 24) = v12 * v26;
      *(v21 + 28) = v28;
      *(v21 + 32) = v13 * v27;
      if (v22 >= v56)
      {
        v29 = 1.0;
        if (data_high - v22 <= element_class)
          v29 = (data_high - v22) / element_class;
      }
      else
      {
        v29 = v22 / v56;
      }
      v32 = v29 * 127.0;
      v33 = v32;
      if (v32 >= 0.0)
        LOBYTE(v33) = v32;
      v34 = effColorMultiply((v33 << 24) | 0x808080, abgr1, 0);
      v35 = *(*(v21 + 48) + 40LL);
      v36 = v34;
      v38 = *(v35 + 32);
      v39 = *(v3[1].klass->_1.byval_arg.data + 2);
      sub_854710(&v59, 0);
      sub_854930(v39 + 32, 0);
      v41 = *(v3[1].klass->_1.byval_arg.data + 2);
      sub_854710(&v59, 1u);
      sub_854930(v41 + 32, 1u);
      v43 = *(v3[1].klass->_1.byval_arg.data + 2);
      sub_854710(&v59, 2u);
      sub_854930(v43 + 32, 2u);
      v45 = *(v3[1].klass->_1.byval_arg.data + 2);
      sub_854710(&v59, 0);
      sub_854930(v45 + 48, 0);
      v47 = *(v3[1].klass->_1.byval_arg.data + 2);
      sub_854710(&v59, 1u);
      sub_854930(v47 + 48, 1u);
      v49 = *(v3[1].klass->_1.byval_arg.data + 2);
      sub_854710(&v59, 2u);
      sub_854930(v49 + 48, 2u);
      effPCP_ThunderColumnPolyLowPartRefresh(&pThunderPoly, v18);
      *(v38 + 40) = v36;
      dds3TrackPolyDraw((v21 + 48), "effPCP_ThunderColumnPolyLowDraw", 0);
      data_low = v54;
      if (!v54)
        goto LABEL_57;
LABEL_29:
      if (data_high > v22)
        goto LABEL_57;
      v31 = DDS3EFFECT_RAND_I();
      ++v18;
      *(v21 + 16) = v31 / bits * bits - v31;
    }
    while (v17 != v18);
  }
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
  struct effPCP_ThunderColumnPolyLowPart_t_array *pPart;
  struct dds3TrackPoly_t_o *hPoly;
  struct dds3TrackPolyList_t_array *trackList;
  dds3TrackPolyList_t_o *v10;
  struct UnityEngine_Vector4_array *pVertex;
  u32 split;
  struct UnityEngine_Vector4_array *pos;
  struct UnityEngine_Vector4_array *v15;
  f32 v20;
  struct UnityEngine_Vector4_array *v21;
  f32 v23;
  f32 v25;
  f32 v26;
  u32 v27;
  f32 v28;
  s64 v29;
  u64 v30;
  UnityEngine_Vector4_o *v32;
  u64 v34;
  u64 v36;
  f32 v41;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  f32 v46;
  f32 v47;
  u64 max_length_low;
  f32 v50;
  f32 v51;
  f32 v52;
  f32 v53;
  UnityEngine_Vector4_o v55;
  UnityEngine_Vector4_o v56;
  UnityEngine_Vector4_o v57;
  UnityEngine_Vector4_o v58;
  UnityEngine_Vector4_o v59;
  UnityEngine_Vector4_o v60;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v62;
  UnityEngine_Vector4_o v63;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o v65;
  UnityEngine_Vector4_o v66;
  UnityEngine_Vector4_o v67;
  UnityEngine_Vector4_o v68;
  UnityEngine_Vector4_o v69;

  *&v55.x = 0;
  *&v55.z = 0;
  *&v66.x = 0;
  *&v66.z = 0;
  *&v65.x = 0;
  *&v65.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  *&v63.x = 0;
  *&v63.z = 0;
  *&v62.x = 0;
  *&v62.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v60.x = 0;
  *&v60.z = 0;
  *&v59.x = 0;
  *&v59.z = 0;
  *&v58.x = 0;
  *&v58.z = 0;
  *&v57.x = 0;
  *&v57.z = 0;
  *&v56.x = 0;
  *&v56.z = 0;
  pPart = (*pThunderPoly)->pPart;
  hPoly = pPart->m_Items[number]->hPoly;
  trackList = hPoly->trackList;
  v10 = trackList->m_Items[0];
  pVertex = v10->pVertex;
  split = (*pThunderPoly)->param->TP->split;
  v10->count = hPoly->point;
  sub_854930(&v66, 0);
  sub_854710(&v66, 0);
  sub_854930(&v66, 1u);
  sub_854930(&v66, 2u);
  sub_854710(&v66, 0);
  sub_854930(&v65, 0);
  sub_854710(&v65, 0);
  sub_854930(&v65, 1u);
  sub_854930(&v65, 2u);
  pos = (*pThunderPoly)->param->TP->pos;
  SDF_VU0__LOADVECTOR(pos->m_Items[1]);
  v15 = (*pThunderPoly)->param->TP->pos;
  SDF_VU0__LOADVECTOR_B(v15->m_Items[0]);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__GETLENGTH();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&p);
  SDF_VU0__LOADVECTOR(dds3CameraTargetPos);
  SDF_VU0__LOADVECTOR_B(dds3CameraEyePos);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__STOREVECTOR(&v59);
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v60);
  v20 = DDS3EFFECT_RAND_F();
  v21 = (*pThunderPoly)->param->TP->pos;
  v23 = v20 * 6.2832;
  SDF_VU0__COPYVECTOR(&dst, v21->m_Items[0]);
  sdfSin(v23);
  sub_854930(&v58, 0);
  sub_854710(&v58, 0);
  sub_854930(&v58, 1u);
  sub_854930(&v58, 2u);
  SDF_VU0__LOADVECTOR(v60);
  SDF_VU0__LOADVECTOR_B(v58);
  SDF_VU0__MULVECTOR();
  SDF_VU0__LOADVECTOR_B(dst);
  SDF_VU0__ADDVECTOR_B_A();
  SDF_VU0__STOREVECTOR_B(&dst);
  sub_854930(&v57, 0);
  sub_854710(&v57, 0);
  sub_854930(&v57, 1u);
  sub_854930(&v57, 2u);
  sdfSin(v23);
  sub_854930(&v58, 0);
  sub_854710(&v58, 0);
  sub_854930(&v58, 1u);
  sub_854930(&v58, 2u);
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__LOADVECTOR_B(v57);
  SDF_VU0__MULVECTOR();
  SDF_VU0__COPYVECTOR_A_TO_C();
  SDF_VU0__LOADVECTOR(v60);
  SDF_VU0__LOADVECTOR_B(v58);
  SDF_VU0__MULVECTOR();
  SDF_VU0__ADDVECTOR_A_C();
  SDF_VU0__COPYVECTOR_A_TO_C();
  SDF_VU0__LOADVECTOR_B(dst);
  SDF_VU0__ADDVECTOR_B_A();
  SDF_VU0__STOREVECTOR_B(&v63);
  SDF_VU0__COPYVECTOR_C_TO_A();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v62);
  if (split)
  {
    v25 = v23 + -6.2832;
    v26 = split;
    v27 = split << 6;
    v28 = (3.1416 / v26) * 4.0;
    v29 = 0;
    v30 = 0;
    do
    {
      SDF_VU0__LOADVECTOR(v62);
      SDF_VU0__LOADVECTOR_B(v59);
      SDF_VU0__OUTERPRODUCT();
      SDF_VU0__NORMALIZE();
      SDF_VU0__STOREVECTOR(&v62);
      SDF_VU0__LOADVECTOR_B(v66);
      SDF_VU0__MULVECTOR();
      SDF_VU0__COPYVECTOR_A_TO_C();
      SDF_VU0__LOADVECTOR(dst);
      SDF_VU0__COPYVECTOR_A_TO_B();
      SDF_VU0__ADDVECTOR_A_C();
      v32 = (pVertex + v29 * 16);
      SDF_VU0__STOREVECTOR(&pVertex->m_Items[v29]);
      SDF_VU0__COPYVECTOR_C_TO_A();
      SDF_VU0__SUBVECTOR_B_A();
      SDF_VU0__STOREVECTOR_B(v32 + 3);
      v34 = v30 + 2;
      SDF_VU0__COPYVECTOR(&v56, v62);
      SDF_VU0__COPYVECTOR(&dst, v63);
      SDF_VU0__LOADVECTOR(v62);
      SDF_VU0__LOADVECTOR_B(v66);
      SDF_VU0__MULVECTOR();
      SDF_VU0__COPYVECTOR_A_TO_C();
      SDF_VU0__LOADVECTOR(dst);
      SDF_VU0__COPYVECTOR_A_TO_B();
      SDF_VU0__ADDVECTOR_A_C();
      SDF_VU0__STOREVECTOR(v32 + 4);
      SDF_VU0__COPYVECTOR_C_TO_A();
      SDF_VU0__SUBVECTOR_B_A();
      v36 = v30 + 3;
      SDF_VU0__STOREVECTOR_B(v32 + 5);
      v25 = v28 + v25;
      if (v25 > 3.1416)
      {
        v25 = v25 + -3.1416;
        DDS3EFFECT_RAND_F();
      }
      v23 = v28 + v23;
      sdfSin(v23);
      sub_854930(&v58, 0);
      sub_854710(&v58, 0);
      sub_854930(&v58, 1u);
      sub_854930(&v58, 2u);
      SDF_VU0__LOADVECTOR(p);
      SDF_VU0__LOADVECTOR_B(v57);
      SDF_VU0__MULVECTOR();
      SDF_VU0__COPYVECTOR_A_TO_C();
      SDF_VU0__LOADVECTOR(v60);
      SDF_VU0__LOADVECTOR_B(v58);
      SDF_VU0__MULVECTOR();
      SDF_VU0__ADDVECTOR_A_C();
      *&v55.x = 0;
      *&v55.z = 0;
      SDF_VU0__STOREVECTOR(&v55);
      v41 = DDS3EFFECT_RAND_PM();
      x = v59.x;
      y = v59.y;
      z = v59.z;
      w = v59.w;
      v46 = v41;
      v69.x = x;
      v69.y = y;
      v69.z = z;
      v69.w = w;
      v30 += 4LL;
      SetRotateMatrixAxis(v46 * 0.34907, v69);
      SDF_VU0__LOADVECTOR(v55);
      SDF_VU0__APPLYMATRIX_XYZ();
      SDF_VU0__COPYVECTOR_A_TO_C();
      SDF_VU0__LOADVECTOR_B(dst);
      SDF_VU0__ADDVECTOR_B_A();
      SDF_VU0__STOREVECTOR_B(&v63);
      SDF_VU0__COPYVECTOR_C_TO_A();
      SDF_VU0__NORMALIZE();
      SDF_VU0__STOREVECTOR(&v62);
      SDF_VU0__LOADVECTOR(v63);
      SDF_VU0__LOADVECTOR_B(dst);
      SDF_VU0__SUBVECTOR();
      SDF_VU0__NORMALIZE();
      SDF_VU0__LOADVECTOR_B(v56);
      v47 = SDF_VU0__INNERPRODUCT();
      max_length_low = LODWORD(pVertex->max_length);
      if (v47 >= 0.0)
      {
        v50 = v32[4].x;
        v51 = v32[4].y;
        v52 = v32[4].z;
        v53 = v32[4].w;
        v67 = v65;
      }
      else
      {
        v50 = v32[5].x;
        v51 = v32[5].y;
        v52 = v32[5].z;
        v53 = v32[5].w;
        v67 = v66;
      }
      SDF_VU0__LOADVECTOR_C(v67);
      SDF_VU0__LOADVECTOR(v62);
      SDF_VU0__LOADVECTOR_B(v59);
      SDF_VU0__OUTERPRODUCT();
      SDF_VU0__NORMALIZE();
      SDF_VU0__COPYVECTOR_C_TO_B();
      SDF_VU0__MULVECTOR();
      v68.x = v50;
      v68.y = v51;
      v68.z = v52;
      v68.w = v53;
      SDF_VU0__LOADVECTOR_B(v68);
      SDF_VU0__ADDVECTOR();
      SDF_VU0__STOREVECTOR(&dst);
      v29 += 4;
    }
    while (v27 != (v29 * 16));
  }
}

// 0x176fb90
void effPCP_ThunderColumnPolyLowSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_ThunderColumnPolyLow_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCP_ThunderColumnPolyLow_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[2].klass) = abgr;
}

// 0x176fa70
void effPCP_ThunderColumnPolyLowSetPosition(void **hData, sdfVector4_t pPos) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v10;
  s64 *v11;
  u64 v12[3];
  UnityEngine_Vector4_o v13;

  w = pPos.w;
  z = pPos.z;
  y = pPos.y;
  x = pPos.x;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_ThunderColumnPolyLow_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCP_ThunderColumnPolyLow_t, v12);
    if ((v12[0] & 1) != 0)
      v10 = v12[2];
    else
      v10 = v12 + 1;
    v11 = sub_8C4940(v10);
  }
  v13.x = x;
  v13.y = y;
  v13.z = z;
  v13.w = w;
  SDF_VU0__COPYVECTOR(&(*hData)[1].klass->_1.name, v13, 0);
}

// 0x1771180
effPCP_ThunderPoly_t *effPCP_ThunderPolyCreate(void **hData, s32 bPos, bool tbldata) {
  u64 *v6;
  u64 *v7;
  Il2CppObject *v8;
  u64 *v9;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v12;
  s64 *v13;
  effPCP_ThunderPolyParam_t_o *v14;
  u64 *v15;
  u64 *v16;
  u64 v18;
  s32 v19;
  s32 v20;
  u64 v21;
  u32 *v23;
  u64 *v24;
  effPCP_ThunderPoly_t_o *v28;
  u64 v29[3];
  s32 pos;

  pos = bPos;
  v6 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v6);
  v7 = Allocate(effPCP_ThunderPoly_t);
  effPCP_ThunderPoly_t___ctor(v7);
  v28 = v7;
  if (tbldata)
  {
    v8 = *hData;
    v9 = Allocate(effPCP_ThunderPolyParam_t);
    effPCP_ThunderPolyParam_t___ctor(v9);
    v7[2] = v9;
    if (v8)
    {
      klass = v8->klass;
      if (v8->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_ThunderPolyParam_t)
      {
        sub_8FC2C0(klass->_1.element_class, effPCP_ThunderPolyParam_t, v29);
        if ((v29[0] & 1) != 0)
          v12 = v29[2];
        else
          v12 = v29 + 1;
        v13 = sub_8C4940(v12);
      }
    }
    effPCP_ThunderPolyParam_t__pClone(v8, v7 + 2);
    v14 = v7[2];
  }
  else
  {
    v15 = Allocate(effPCP_ThunderPolyParam_t);
    effPCP_ThunderPolyParam_t___ctor(v15);
    v14 = effPCP_ThunderPolyParam_t__pCopy(v15, *hData, &pos, 1);
    v7[2] = v14;
  }
  v16 = NewSpecific(effPCP_ThunderPolyPart_t, v14->number);
  v18 = v7[2];
  v7[3] = v16;
  v19 = *(v18 + 28);
  v20 = *(v18 + 48);
  v7[5] = dds3TrackPolyCreate(v19, 2 * v20 - 1, 0, 4);
  dds3TrackPolyVC5Set_AcuteW(v7 + 5, *(v7[2] + 56), *(v7[2] + 64), *(v7[2] + 72), 0);
  dds3TrackPolySetMode(v7 + 5, *(v7[2] + 24), 0);
  if (*(v7[2] + 28))
  {
    v21 = 0;
    do
    {
      v23 = v7[3];
      v24 = Allocate(effPCP_ThunderPolyPart_t);
      effPCP_ThunderPolyPart_t___ctor(v24);
      *&v23[2 * v21 + 8] = v24;
      effPCP_ThunderPolyPartInit(&v28, v21++);
    }
    while (v21 < *(v7[2] + 28));
  }
  v7[4] = 2155905152LL;
  return v7;
}

// 0x1771480
void effPCP_ThunderPolyDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3TrackPoly_t_o **p_monitor;
  u64 v9[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_ThunderPoly_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCP_ThunderPoly_t, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  p_monitor = &v3[2].monitor;
  dds3TrackPolyDelete(p_monitor);
}

// 0x1771b90
void effPCP_ThunderPolyDraw(void **hData) {
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  Il2CppClass *v9;
  s64 namespaze_high;
  u32 v11;
  void **p_monitor;
  u64 j;
  u64 *v14;
  u32 *v16;
  s64 v17;
  s64 v19;
  s32 v20;
  u32 v21;
  u64 i;
  u64 *monitor;
  u32 *v25;
  s64 v26;
  s64 v28;
  s32 v29;
  u32 v30;
  effPCP_ThunderPoly_t_o *v32[3];
  effPCP_ThunderPoly_t_o *pThunderPoly;

  pThunderPoly = 0;
  v4 = *hData;
  if (*hData)
  {
    klass = v4->klass;
    if (v4->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_ThunderPoly_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCP_ThunderPoly_t, v32);
      if ((v32[0] & 1) != 0)
        v7 = v32[2];
      else
        v7 = v32 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  pThunderPoly = *hData;
  v9 = v4[1].klass;
  namespaze_high = HIDWORD(v9->_1.namespaze);
  if (namespaze_high >= 1)
  {
    v11 = v4[2].klass;
    p_monitor = &v4[2].monitor;
    if ((LODWORD(v9->_1.byval_arg.data) - 1) >= HIDWORD(v4[2].klass))
    {
      for (i = 0; i != namespaze_high; ++i)
      {
        monitor = v4[1].monitor;
        v25 = monitor[i + 4];
        v26 = *(*p_monitor + 5);
        v28 = *(v26 + 8 * i + 32);
        v29 = v25[4];
        if (v29)
        {
          v25[4] = v29 - 1;
        }
        else if (v25[5])
        {
          effPCP_ThunderPolyPartRefresh(&pThunderPoly, i);
          --v25[5];
        }
        else
        {
          v30 = v25[6];
          if (HIBYTE(v30))
          {
            v25[6] = v30 - 0x20000000;
          }
          else
          {
            effPCP_ThunderPolyPartInit(&pThunderPoly, i);
            dds3TrackPolyListInit(&v4[2].monitor, i);
          }
        }
        *(v28 + 40) = effColorMultiply(v25[6], v11);
      }
    }
    else
    {
      for (j = 0; j != namespaze_high; ++j)
      {
        v14 = v4[1].monitor;
        v16 = v14[j + 4];
        v17 = *(*p_monitor + 5);
        v19 = *(v17 + 8 * j + 32);
        v20 = v16[4];
        if (v20)
        {
          v16[4] = v20 - 1;
        }
        else if (v16[5])
        {
          effPCP_ThunderPolyPartRefresh(&pThunderPoly, j);
          --v16[5];
        }
        else
        {
          v21 = v16[6];
          if (HIBYTE(v21))
            v16[6] = v21 - 0x20000000;
          else
            *(v19 + 32) = 0;
        }
        *(v19 + 40) = effColorMultiply(v16[6], v11);
      }
    }
  }
  ++HIDWORD(v4[2].klass);
  dds3TrackPolyDraw(&v4[2].monitor, "effPCP_ThunderPolyDraw");
}

// 0x1771a70
void effPCP_ThunderPolyDrawOff(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3TrackPoly_t_o **p_monitor;
  u64 v9[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_ThunderPoly_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCP_ThunderPoly_t, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  p_monitor = &v3[2].monitor;
  dds3TrackPolyDrawOff(p_monitor);
}

// 0x1771880
effPCP_ThunderPolyParam_t *effPCP_ThunderPolyGetParam(effPCP_ThunderPoly_t *pThunderPoly) {
  return pThunderPoly->param;
}

// 0x1774f20
effPCP_ThunderPolyList_t *effPCP_ThunderPolyListCreate(void **hData, s32 bPos, bool tbldata) {
  effPCP_ThunderPolyListParam_t_o *v6;
  effPCP_ThunderPolyListParam_t_c *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  effPCP_ThunderPolyList_t_o *v11;
  u64 *v12;
  struct effPCP_ThunderPoly_t_array *v13;
  struct effPCP_ThunderPolyListParam_t_o *param;
  struct effPCP_ThunderPoly_t_array *v15;
  s64 *v17;
  s64 *v19;
  struct effPCP_ThunderPoly_t_array *pTP;
  effPCP_ThunderPoly_t_o *v21;
  dds3TrackPoly_t_o **p_hPoly;
  struct effPCP_ThunderPolyParam_t_o *v23;
  u32 color_center;
  u32 color_border;
  u32 color_edge;
  s64 i;
  u32 *v29;
  s64 point;
  u64 v31;
  s64 *v32;
  s64 *v34;
  struct effPCP_ThunderPoly_t_array *v36;
  signed s64 v37;
  s64 v39;
  dds3TrackPoly_t_o **v40;
  u32 *v41;
  u32 v42;
  u32 v43;
  u32 v44;
  s64 v46;
  dds3TrackPoly_t_o **v47;
  u32 *v48;
  u32 v49;
  u32 v50;
  u32 v51;
  Il2CppObject *hDataa;
  u64 v58[3];

  hDataa = 0;
  v6 = *hData;
  if (*hData)
  {
    klass = v6->klass;
    if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_ThunderPolyListParam_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCP_ThunderPolyListParam_t, v58);
      if ((v58[0] & 1) != 0)
        v9 = v58[2];
      else
        v9 = v58 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  v11 = Allocate(effPCP_ThunderPolyList_t);
  effPCP_ThunderPolyList_t___ctor(v11);
  v12 = Allocate(effPCP_ThunderPolyListParam_t);
  effPCP_ThunderPolyListParam_t___ctor(v12);
  v11->param = v12;
  effPCP_ThunderPolyListParam_t__pClone(v6, &v11->param);
  v13 = NewSpecific(effPCP_ThunderPoly_t, v6->point);
  param = v11->param;
  v11->pTP = v13;
  hDataa = param->TPParam;
  v15 = v13;
  v17 = effPCP_ThunderPolyCreate(&hDataa, bPos, tbldata);
  v19 = v17;
  v15->m_Items[0] = v19;
  pTP = v11->pTP;
  v21 = pTP->m_Items[0];
  p_hPoly = &v21->hPoly;
  v23 = v21->param;
  color_center = v23->color_center;
  color_border = v23->color_border;
  color_edge = v23->color_edge;
  dds3TrackPolyVC5Set_AcuteR(p_hPoly, color_center, color_border, color_edge);
  for (i = 5; ; ++i)
  {
    v29 = v11->pTP;
    point = v6->point;
    hDataa = v11->param->TPParam;
    v31 = i - 4;
    v32 = effPCP_ThunderPolyCreate(&hDataa, bPos, tbldata);
    v34 = v32;
    *&v29[2 * i] = v34;
    v36 = v11->pTP;
    v37 = point - 2;
    if (v31 >= v37)
      break;
    v39 = *(&v36->obj.klass + i);
    v40 = (v39 + 40);
    v41 = *(v39 + 16);
    v42 = v41[14];
    v43 = v41[16];
    v44 = v41[18];
    dds3TrackPolyVC5Set_Normal(v40, v42, v43, v44);
  }
  v46 = *(&v36->obj.klass + i);
  v47 = (v46 + 40);
  v48 = *(v46 + 16);
  v49 = v48[14];
  v50 = v48[16];
  v51 = v48[18];
  dds3TrackPolyVC5Set_Acute(v47, v49, v50, v51);
  v11->abgr = -2139062144;
  return v11;
}

// 0x1775370
void effPCP_ThunderPolyListDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s64 v8;
  u64 *monitor;
  Il2CppObject *v11[3];
  Il2CppObject *hDataa;

  hDataa = 0;
  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_ThunderPolyList_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCP_ThunderPolyList_t, v11);
      if ((v11[0] & 1) != 0)
        v6 = v11[2];
      else
        v6 = v11 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  if (SLODWORD(v3[1].klass->_1.namespaze) >= 2)
  {
    v8 = 0;
    do
    {
      monitor = v3[1].monitor;
      hDataa = monitor[v8 + 4];
      effPCP_ThunderPolyDelete(&hDataa);
      ++v8;
    }
    while (v8 < SLODWORD(v3[1].klass->_1.namespaze) - 1LL);
  }
}

// 0x1776880
void effPCP_ThunderPolyListDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppClass *v8;
  s32 v9;
  const char *name;
  u64 v11;
  u64 *monitor;
  effPCP_ThunderPoly_t_o *v14;
  struct UnityEngine_Vector4_array *pos;
  struct UnityEngine_Vector4_array *v18;
  u64 v19;
  s64 number;
  u32 v23;
  u32 v27;
  u64 v28;
  u64 v29;
  struct dds3TrackPolyList_t_array *trackList;
  u32 *v33;
  dds3TrackPolyList_t_o *v34;
  s64 v36;
  struct dds3TrackPolyList_t_array *v39;
  dds3TrackPolyList_t_o *v41;
  s64 v42;
  effPCP_ThunderPoly_t_o *pThunderPoly;
  u64 v44[3];

  pThunderPoly = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_ThunderPolyList_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCP_ThunderPolyList_t, v44);
      if ((v44[0] & 1) != 0)
        v6 = v44[2];
      else
        v6 = v44 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = v3[1].klass;
  v9 = LODWORD(v8->_1.namespaze) - 1;
  if (v9 >= 1)
  {
    name = v8->_1.name;
    v11 = 0;
    v42 = v9;
    do
    {
      monitor = v3[1].monitor;
      v14 = monitor[v11 + 4];
      pThunderPoly = v14;
      pos = v14->param->pos;
      SDF_VU0__COPYVECTOR(pos->m_Items, *&name[16 * v11 + 32]);
      v18 = v14->param->pos;
      v19 = v11 + 1;
      SDF_VU0__COPYVECTOR(&v18->m_Items[1], *&name[16 * v19 + 32]);
      number = v14->param->number;
      v23 = effColorMultiply(v3[2].klass, v14->abgr);
      if (number >= 1)
      {
        v27 = v23;
        v28 = 0;
        if (v11)
        {
          v29 = v11 - 1;
          do
          {
            trackList = v14->hPoly->trackList;
            v33 = v3[1].monitor;
            v34 = trackList->m_Items[v28];
            v36 = *(*(*&v33[2 * v29 + 8] + 40LL) + 40LL);
            effPCP_ThunderPolyListPartRefresh(
              &pThunderPoly,
              v28++,
              *(*(v36 + 32) + 16LL),
              *(*(v36 + 32) + 32LL) - 5);
            v34->color = v27;
          }
          while (number != v28);
        }
        else
        {
          do
          {
            v39 = v14->hPoly->trackList;
            v41 = v39->m_Items[v28];
            effPCP_ThunderPolyPartRefresh(&pThunderPoly, v28++);
            v41->color = v27;
          }
          while (number != v28);
        }
      }
      ++v14->frame;
      dds3TrackPolyDraw(&v14->hPoly, "effPCP_ThunderPolyListDraw");
      v11 = v19;
    }
    while (v19 != v42);
  }
}

// 0x1776700
void effPCP_ThunderPolyListDrawOff(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s32 v8;
  u64 v9;
  s64 v10;
  u64 *monitor;
  dds3TrackPoly_t_o **v13;
  u64 v14[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_ThunderPolyList_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCP_ThunderPolyList_t, v14);
      if ((v14[0] & 1) != 0)
        v6 = v14[2];
      else
        v6 = v14 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = LODWORD(v3[1].klass->_1.namespaze) - 1;
  if (v8 >= 1)
  {
    v9 = 0;
    v10 = v8;
    do
    {
      monitor = v3[1].monitor;
      v13 = (monitor[v9 + 4] + 40LL);
      dds3TrackPolyDrawOff(v13);
      ++v9;
    }
    while (v10 != v9);
  }
}

// 0x17754d0
effPCP_ThunderPolyListParam_t *effPCP_ThunderPolyListGetParam(effPCP_ThunderPolyList_t *pTPolyList) {
  return pTPolyList->param;
}

// 0x17755d0
void effPCP_ThunderPolyListPartRefresh(effPCP_ThunderPoly_t **pThunderPoly, s32 number, sdfVector4_t **pPos, s32 pidx) {
  u64 *v8;
  struct dds3TrackPoly_t_o *hPoly;
  struct dds3TrackPolyList_t_array *trackList;
  dds3TrackPolyList_t_o *v12;
  struct UnityEngine_Vector4_array *pVertex;
  u32 split;
  struct UnityEngine_Vector4_array *pos;
  f32 *v18;
  f32 *v19;
  f32 v20;
  f32 v24;
  f32 v26;
  UnityEngine_Vector4_o *v28;
  UnityEngine_Vector4_o *v29;
  f32 v30;
  f32 v31;
  UnityEngine_Vector4_o *v32;
  u64 v33;
  UnityEngine_Vector4_o *v34;
  u64 v35;
  s32 v36;
  f32 v37;
  u64 v38;
  UnityEngine_Vector4_o *v40;
  UnityEngine_Vector4_o *v47;
  UnityEngine_Vector4_o *v57;
  u64 v59;
  f32 v64;
  f32 v67;
  f32 y;
  f32 x;
  f32 w;
  f32 v71;
  f32 z;
  f32 v73;
  u64 max_length_low;
  f32 v76;
  f32 v77;
  f32 v78;
  f32 v79;
  f32 *v81;
  f32 *v82;
  f32 *v83;
  f32 *v84;
  f32 *v85;
  f32 *v86;
  f32 *v87;
  f32 *v88;
  f32 *v89;
  f32 *p_w;
  f32 *p_z;
  f32 *p_y;
  f32 *v93;
  f32 *v94;
  f32 *v95;
  s64 v97;
  f32 v98;
  UnityEngine_Vector4_o v99;
  UnityEngine_Vector4_o v100;
  UnityEngine_Vector4_o v101;
  UnityEngine_Vector4_o v102;
  UnityEngine_Vector4_o aAxis;
  UnityEngine_Vector4_o v104;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v106;
  UnityEngine_Vector4_o v107;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o v109;
  UnityEngine_Vector4_o v110;
  UnityEngine_Vector4_o v111;
  UnityEngine_Vector4_o v112;
  UnityEngine_Vector4_o v113;
  UnityEngine_Vector4_o v114;
  UnityEngine_Vector4_o v115;
  UnityEngine_Vector4_o v116;
  UnityEngine_Vector4_o v117;
  UnityEngine_Vector4_o v118;
  UnityEngine_Vector4_o v119;
  UnityEngine_Vector4_o v120;
  UnityEngine_Vector4_o v121;

  *&v99.x = 0;
  *&v99.z = 0;
  v8 = Allocate(dds3TrackPolyList_t);
  dds3TrackPolyList_t___ctor(v8);
  *&v111.x = 0;
  *&v111.z = 0;
  *&v110.x = 0;
  *&v110.z = 0;
  *&v109.x = 0;
  *&v109.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  *&v107.x = 0;
  *&v107.z = 0;
  *&v106.x = 0;
  *&v106.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v104.x = 0;
  *&v104.z = 0;
  *&aAxis.x = 0;
  *&aAxis.z = 0;
  *&v102.x = 0;
  *&v102.z = 0;
  *&v101.x = 0;
  *&v101.z = 0;
  *&v100.x = 0;
  *&v100.z = 0;
  hPoly = (*pThunderPoly)->hPoly;
  trackList = hPoly->trackList;
  v12 = trackList->m_Items[number];
  pVertex = v12->pVertex;
  split = (*pThunderPoly)->param->split;
  v12->count = hPoly->point;
  sub_854930(&v111, 0);
  sub_854710(&v111, 0);
  sub_854930(&v111, 1u);
  sub_854930(&v111, 2u);
  sub_854710(&v111, 0);
  sub_854930(&v110, 0);
  sub_854710(&v110, 0);
  sub_854930(&v110, 1u);
  sub_854930(&v110, 2u);
  sub_854710(&v110, 0);
  sub_854930(&v109, 0);
  sub_854710(&v109, 0);
  sub_854930(&v109, 1u);
  sub_854930(&v109, 2u);
  pos = (*pThunderPoly)->param->pos;
  SDF_VU0__LOADVECTOR(pos->m_Items[1]);
  v97 = pidx + 3LL;
  v18 = (&pPos->obj + v97);
  v20 = v18[8];
  v19 = v18 + 8;
  v112.x = v20;
  v112.y = v19[1];
  v95 = v19 + 1;
  v112.z = v19[2];
  v94 = v19 + 2;
  v112.w = v19[3];
  v93 = v19 + 3;
  SDF_VU0__LOADVECTOR_B(v112);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__GETLENGTH();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&p);
  SDF_VU0__LOADVECTOR(dds3CameraTargetPos);
  SDF_VU0__LOADVECTOR_B(dds3CameraEyePos);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__STOREVECTOR(&aAxis);
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v104);
  v24 = DDS3EFFECT_RAND_F();
  v113.y = *v95;
  v113.z = *v94;
  v113.x = *v19;
  v113.w = *v93;
  v26 = v24 * 6.2832;
  SDF_VU0__COPYVECTOR(&dst, v113);
  sdfSin(v26);
  sub_854930(&v102, 0);
  sub_854710(&v102, 0);
  sub_854930(&v102, 1u);
  sub_854930(&v102, 2u);
  SDF_VU0__LOADVECTOR(v104);
  SDF_VU0__LOADVECTOR_B(v102);
  SDF_VU0__MULVECTOR();
  SDF_VU0__LOADVECTOR_B(dst);
  SDF_VU0__ADDVECTOR_B_A();
  SDF_VU0__STOREVECTOR_B(&dst);
  sub_854930(&v101, 0);
  sub_854710(&v101, 0);
  sub_854930(&v101, 1u);
  sub_854930(&v101, 2u);
  v98 = v26;
  sdfSin(v26);
  sub_854930(&v102, 0);
  sub_854710(&v102, 0);
  sub_854930(&v102, 1u);
  sub_854930(&v102, 2u);
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__LOADVECTOR_B(v101);
  SDF_VU0__MULVECTOR();
  SDF_VU0__COPYVECTOR_A_TO_C();
  SDF_VU0__LOADVECTOR(v104);
  SDF_VU0__LOADVECTOR_B(v102);
  SDF_VU0__MULVECTOR();
  SDF_VU0__ADDVECTOR_A_C();
  SDF_VU0__COPYVECTOR_A_TO_C();
  SDF_VU0__LOADVECTOR_B(dst);
  SDF_VU0__ADDVECTOR_B_A();
  SDF_VU0__STOREVECTOR_B(&v107);
  SDF_VU0__COPYVECTOR_C_TO_A();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v106);
  if (split)
  {
    v28 = &pPos->m_Items[pidx];
    p_y = &v28->y;
    p_w = &v28->w;
    p_z = &v28->z;
    v29 = &pPos->m_Items[pidx + 1];
    v89 = &v29->y;
    v30 = v26 + -6.2832;
    v87 = &v29->w;
    v88 = &v29->z;
    v31 = split;
    v32 = &pPos->m_Items[pidx + 2];
    v33 = 0;
    v86 = &v32->y;
    v84 = &v32->w;
    v85 = &v32->z;
    v34 = &pPos->m_Items[pidx + 4];
    v83 = &v34->y;
    v35 = 9;
    v81 = &v34->w;
    v82 = &v34->z;
    v36 = 160 * split;
    v37 = (3.1416 / v31) * 4.0;
    do
    {
      v38 = v35 - 9;
      SDF_VU0__LOADVECTOR(v106);
      SDF_VU0__LOADVECTOR_B(aAxis);
      SDF_VU0__OUTERPRODUCT();
      SDF_VU0__NORMALIZE();
      SDF_VU0__STOREVECTOR(&v106);
      if (v33)
      {
        SDF_VU0__COPYVECTOR_A_TO_B();
        SDF_VU0__LOADVECTOR(dst);
        v40 = (pVertex + v33);
        SDF_VU0__STOREVECTOR(&pVertex->m_Items[v33 / 0x10 + 2]);
        SDF_VU0__COPYVECTOR_B_TO_A();
        SDF_VU0__LOADVECTOR_B(v111);
        SDF_VU0__MULVECTOR();
        SDF_VU0__COPYVECTOR_A_TO_C();
        SDF_VU0__LOADVECTOR(dst);
        SDF_VU0__COPYVECTOR_A_TO_B();
        SDF_VU0__ADDVECTOR_A_C();
        SDF_VU0__STOREVECTOR(v40 + 3);
        SDF_VU0__COPYVECTOR_C_TO_A();
        SDF_VU0__SUBVECTOR_B_A();
        SDF_VU0__STOREVECTOR_B(v40 + 5);
        SDF_VU0__LOADVECTOR(v106);
        SDF_VU0__LOADVECTOR_B(v110);
        SDF_VU0__MULVECTOR();
        SDF_VU0__COPYVECTOR_A_TO_C();
        SDF_VU0__LOADVECTOR(dst);
        SDF_VU0__COPYVECTOR_A_TO_B();
        SDF_VU0__ADDVECTOR_A_C();
        SDF_VU0__STOREVECTOR(v40 + 2);
        SDF_VU0__COPYVECTOR_C_TO_A();
        SDF_VU0__SUBVECTOR_B_A();
        SDF_VU0__STOREVECTOR_B(v40 + 6);
      }
      else
      {
        v114.x = pPos->m_Items[pidx].x;
        v114.y = *p_y;
        v114.z = *p_z;
        v114.w = *p_w;
        v47 = (pVertex + v33);
        SDF_VU0__COPYVECTOR(&pVertex->m_Items[v33 / 0x10], v114);
        v115.x = pPos->m_Items[pidx + 1].x;
        v115.y = *v89;
        v115.z = *v88;
        v115.w = *v87;
        SDF_VU0__COPYVECTOR(v47 + 3, v115);
        v116.x = pPos->m_Items[pidx + 2].x;
        v116.y = *v86;
        v116.z = *v85;
        v116.w = *v84;
        SDF_VU0__COPYVECTOR(v47 + 4, v116);
        v117.x = *v19;
        v117.y = *v95;
        v117.z = *v94;
        v117.w = *v93;
        SDF_VU0__COPYVECTOR(v47 + 5, v117);
        v118.x = pPos->m_Items[pidx + 4].x;
        v118.y = *v83;
        v118.z = *v82;
        v118.w = *v81;
        SDF_VU0__COPYVECTOR(v47 + 6, v118);
      }
      SDF_VU0__COPYVECTOR(&v100, v106);
      SDF_VU0__COPYVECTOR(&dst, v107);
      SDF_VU0__LOADVECTOR(dst);
      v57 = (pVertex + v33);
      SDF_VU0__STOREVECTOR(&pVertex->m_Items[v33 / 0x10 + 7]);
      SDF_VU0__LOADVECTOR(v106);
      SDF_VU0__LOADVECTOR_B(v111);
      SDF_VU0__MULVECTOR();
      SDF_VU0__COPYVECTOR_A_TO_C();
      SDF_VU0__LOADVECTOR(dst);
      SDF_VU0__COPYVECTOR_A_TO_B();
      SDF_VU0__ADDVECTOR_A_C();
      v59 = v35 - 4;
      SDF_VU0__STOREVECTOR(v57 + 8);
      SDF_VU0__COPYVECTOR_C_TO_A();
      SDF_VU0__SUBVECTOR_B_A();
      SDF_VU0__STOREVECTOR_B(v57 + 10);
      SDF_VU0__LOADVECTOR(v106);
      SDF_VU0__LOADVECTOR_B(v110);
      SDF_VU0__MULVECTOR();
      SDF_VU0__COPYVECTOR_A_TO_C();
      SDF_VU0__LOADVECTOR(dst);
      SDF_VU0__COPYVECTOR_A_TO_B();
      SDF_VU0__ADDVECTOR_A_C();
      SDF_VU0__STOREVECTOR(v57 + 7);
      SDF_VU0__COPYVECTOR_C_TO_A();
      SDF_VU0__SUBVECTOR_B_A();
      SDF_VU0__STOREVECTOR_B(v57 + 11);
      v30 = v37 + v30;
      if (v30 > 3.1416)
      {
        v30 = v30 + -3.1416;
        DDS3EFFECT_RAND_F();
      }
      v64 = v37 + v98;
      v98 = v37 + v98;
      sdfSin(v64);
      sub_854930(&v102, 0);
      sub_854710(&v102, 0);
      sub_854930(&v102, 1u);
      sub_854930(&v102, 2u);
      SDF_VU0__LOADVECTOR(p);
      SDF_VU0__LOADVECTOR_B(v101);
      SDF_VU0__MULVECTOR();
      SDF_VU0__COPYVECTOR_A_TO_C();
      SDF_VU0__LOADVECTOR(v104);
      SDF_VU0__LOADVECTOR_B(v102);
      SDF_VU0__MULVECTOR();
      SDF_VU0__ADDVECTOR_A_C();
      *&v99.x = 0;
      *&v99.z = 0;
      SDF_VU0__STOREVECTOR(&v99);
      v67 = DDS3EFFECT_RAND_PM();
      y = aAxis.y;
      x = aAxis.x;
      w = aAxis.w;
      v71 = v67;
      z = aAxis.z;
      v121.x = x;
      v121.y = y;
      v121.z = z;
      v121.w = w;
      SetRotateMatrixAxis(v71 * 0.34907, v121);
      SDF_VU0__LOADVECTOR(v99);
      SDF_VU0__APPLYMATRIX_XYZ();
      SDF_VU0__COPYVECTOR_A_TO_C();
      SDF_VU0__LOADVECTOR_B(dst);
      SDF_VU0__ADDVECTOR_B_A();
      SDF_VU0__STOREVECTOR_B(&v107);
      SDF_VU0__COPYVECTOR_C_TO_A();
      SDF_VU0__NORMALIZE();
      SDF_VU0__STOREVECTOR(&v106);
      SDF_VU0__LOADVECTOR(v107);
      SDF_VU0__LOADVECTOR_B(dst);
      SDF_VU0__SUBVECTOR();
      SDF_VU0__NORMALIZE();
      SDF_VU0__LOADVECTOR_B(v100);
      v73 = SDF_VU0__INNERPRODUCT();
      max_length_low = LODWORD(pVertex->max_length);
      if (v73 >= 0.0)
      {
        v76 = v57[7].x;
        v77 = v57[7].y;
        v78 = v57[7].z;
        v79 = v57[7].w;
        v119 = v109;
      }
      else
      {
        v76 = v57[11].x;
        v77 = v57[11].y;
        v78 = v57[11].z;
        v79 = v57[11].w;
        v119 = v110;
      }
      SDF_VU0__LOADVECTOR_C(v119);
      SDF_VU0__LOADVECTOR(v106);
      SDF_VU0__LOADVECTOR_B(aAxis);
      SDF_VU0__OUTERPRODUCT();
      SDF_VU0__NORMALIZE();
      SDF_VU0__COPYVECTOR_C_TO_B();
      SDF_VU0__MULVECTOR();
      v120.x = v76;
      v120.y = v77;
      v120.z = v78;
      v120.w = v79;
      SDF_VU0__LOADVECTOR_B(v120);
      SDF_VU0__ADDVECTOR();
      SDF_VU0__STOREVECTOR(&dst);
      v33 += 160LL;
      v35 += 10LL;
    }
    while (v36 != v33);
  }
}

// 0x17754e0
void effPCP_ThunderPolyListSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_ThunderPolyList_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCP_ThunderPolyList_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[2].klass) = abgr;
}

// 0x1772dc0
effPCP_ThunderPolyLow_t *effPCP_ThunderPolyLowCreate(void **hData, s32 bPos, bool tbldata) {
  effPCP_ThunderPolyParam_t_o *v5;
  effPCP_ThunderPolyParam_t_c *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 *v10;
  effPCP_ThunderPolyLow_t_o *v11;
  u64 *v12;
  struct effPCP_ThunderPolyPart_t_array *v13;
  struct effPCP_ThunderPolyParam_t_o *param;
  s32 number;
  s32 split;
  dds3TrackPoly_t_o *v18;
  struct effPCP_ThunderPolyParam_t_o *v19;
  u64 v20;
  u32 *pPart;
  u64 *v23;
  effPCP_ThunderPolyLow_t_o *v27;
  u64 v28[3];

  v27 = 0;
  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_ThunderPolyParam_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCP_ThunderPolyParam_t, v28);
      if ((v28[0] & 1) != 0)
        v8 = v28[2];
      else
        v8 = v28 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v10);
  v11 = Allocate(effPCP_ThunderPolyLow_t);
  effPCP_ThunderPolyLow_t___ctor(v11);
  v27 = v11;
  v12 = Allocate(effPCP_ThunderPolyParam_t);
  effPCP_ThunderPolyParam_t___ctor(v12);
  v11->param = v12;
  effPCP_ThunderPolyParam_t__pClone(v5, &v11->param);
  v13 = NewSpecific(effPCP_ThunderPolyPart_t, v5->number);
  param = v11->param;
  v11->pPart = v13;
  v11->hMem = v10;
  number = param->number;
  split = param->split;
  v11->hPoly = dds3TrackPolyCreate(number, 2 * split - 1, 0, 1);
  dds3TrackPolyVCSet(&v11->hPoly, 2, v11->param->color_border, v11->param->color_edge);
  dds3TrackPolySetMode(&v11->hPoly, v11->param->blend);
  v18 = dds3TrackPolyCreate(v11->param->number, 2 * v11->param->split - 1, 0, 0);
  v19 = v11->param;
  v11->hPoly_c = v18;
  dds3TrackPolyVCSet(&v11->hPoly_c, 2, v19->color_center, v19->color_center);
  dds3TrackPolySetMode(&v11->hPoly_c, v11->param->blend);
  if (v11->param->number)
  {
    v20 = 0;
    do
    {
      pPart = v11->pPart;
      v23 = Allocate(effPCP_ThunderPolyPart_t);
      effPCP_ThunderPolyPart_t___ctor(v23);
      *&pPart[2 * v20 + 8] = v23;
      effPCP_ThunderPolyLowPartInit(&v27, v20++);
    }
    while (v20 < v11->param->number);
  }
  v11->abgr = -2139062144;
  return v11;
}

// 0x17730e0
void effPCP_ThunderPolyLowDelete(void **hData) {
  dds3TrackPoly_t_o **v3;
  dds3TrackPoly_t_o *v4;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v8[3];

  v3 = *hData;
  if (*hData)
  {
    v4 = *v3;
    if (LOBYTE((*v3)[2].d_next) < typeHierarchyDepth
      || *(*&v4[1].alf_raito + 8 * typeHierarchyDepth - 8) != effPCP_ThunderPolyLow_t)
    {
      sub_8FC2C0(v4->pMat, effPCP_ThunderPolyLow_t, v8);
      if ((v8[0] & 1) != 0)
        v6 = v8[2];
      else
        v6 = v8 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  dds3TrackPolyDelete(v3 + 5);
  dds3TrackPolyDelete(v3 + 6);
}

// 0x1773620
void effPCP_ThunderPolyLowDraw(void **hData) {
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  s64 namespaze_high;
  s64 v10;
  u64 *monitor;
  u64 v12;
  u32 *v14;
  s64 v15;
  s64 v17;
  s64 v18;
  s64 v20;
  s32 v21;
  u32 v22;
  Il2CppClass *v24;
  s64 *Interface;
  s32 v27;
  s64 v28;
  char *v29;
  s64 *v30;
  u32 abgr1;
  effPCP_ThunderPolyLow_t_o *pThunderPoly;
  u64 v33[2];
  char *v34;

  pThunderPoly = 0;
  v4 = *hData;
  if (*hData)
  {
    klass = v4->klass;
    if (v4->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_ThunderPolyLow_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCP_ThunderPolyLow_t, v33);
      if ((v33[0] & 1) != 0)
        v7 = v34;
      else
        v7 = v33 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  pThunderPoly = *hData;
  namespaze_high = SHIDWORD(v4[1].klass->_1.namespaze);
  if (namespaze_high >= 1)
  {
    v10 = 4;
    abgr1 = v4[2].klass;
    do
    {
      monitor = v4[1].monitor;
      v12 = v10 - 4;
      v14 = monitor[v10];
      v15 = *(v4[2].monitor + 5);
      v17 = *(v15 + 8 * v10);
      v18 = *&v4[3].klass->_1.byval_arg.bits;
      v20 = *(v18 + 8 * v10);
      v21 = v14[4];
      if (v21)
      {
        v14[4] = v21 - 1;
      }
      else if (v14[5])
      {
        effPCP_ThunderPolyLowPartRefresh(&pThunderPoly, v10 - 4);
        --v14[5];
      }
      else
      {
        v22 = v14[6];
        if (HIBYTE(v22))
        {
          v14[6] = v22 - 0x20000000;
        }
        else
        {
          effPCP_ThunderPolyLowPartInit(&pThunderPoly, v12);
          dds3TrackPolyListInit(&v4[2].monitor, v12);
          dds3TrackPolyListInit(&v4[3], v12);
        }
      }
      *(v17 + 40) = effColorMultiply(v14[6], abgr1);
      Interface = QueryInterface(v17, dds3TrackPolyList_t);
      if (!Interface)
      {
        sub_8FC2C0(*(*v17 + 64LL), v24, v33);
        if ((v33[0] & 1) != 0)
          v29 = v34;
        else
          v29 = v33 + 1;
        v30 = sub_8C4940(v29);
      }
      v27 = *(Interface[v10] + 40);
      v28 = v10 - 3;
      ++v10;
      *(v20 + 40) = v27;
    }
    while (v28 < namespaze_high);
  }
  dds3TrackPolyDraw(&v4[2].monitor, "effPCP_ThunderPolyLowDraw");
  dds3TrackPolyDraw(&v4[3], "effPCP_ThunderPolyLowDraw_C");
}

// 0x17734f0
void effPCP_ThunderPolyLowDrawOff(void **hData) {
  dds3TrackPoly_t_o **v3;
  dds3TrackPoly_t_o *v4;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v8[3];

  v3 = *hData;
  if (*hData)
  {
    v4 = *v3;
    if (LOBYTE((*v3)[2].d_next) < typeHierarchyDepth
      || *(*&v4[1].alf_raito + 8 * typeHierarchyDepth - 8) != effPCP_ThunderPolyLow_t)
    {
      sub_8FC2C0(v4->pMat, effPCP_ThunderPolyLow_t, v8);
      if ((v8[0] & 1) != 0)
        v6 = v8[2];
      else
        v6 = v8 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  dds3TrackPolyDrawOff(v3 + 5);
  dds3TrackPolyDrawOff(v3 + 6);
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
  __int128 v3;
  u64 *v6;
  u64 *v7;
  effPCP_ThunderPolyLow_t_o *v8;
  struct dds3TrackPolyList_t_array *trackList;
  dds3TrackPolyList_t_o *v11;
  struct dds3TrackPolyList_t_array *v12;
  struct UnityEngine_Vector4_array *pVertex;
  dds3TrackPolyList_t_o *v15;
  u32 split;
  struct UnityEngine_Vector4_array *v17;
  struct UnityEngine_Vector4_array *pos;
  struct UnityEngine_Vector4_array *v20;
  f32 v25;
  struct UnityEngine_Vector4_array *v26;
  f32 v28;
  s32 v30;
  f32 v31;
  s64 v32;
  u64 v33;
  UnityEngine_Vector4_o *v34;
  u64 v35;
  u64 v37;
  UnityEngine_Vector4_o *v40;
  u64 v43;
  u64 v45;
  u64 v47;
  __int128 v52;
  f32 v55;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  f32 v60;
  f32 v61;
  u64 max_length_low;
  f32 v64;
  f32 v65;
  f32 v66;
  f32 v67;
  UnityEngine_Vector4_o v69;
  UnityEngine_Vector4_o v70;
  UnityEngine_Vector4_o v71;
  UnityEngine_Vector4_o v72;
  UnityEngine_Vector4_o v73;
  UnityEngine_Vector4_o v74;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v76;
  UnityEngine_Vector4_o v77;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o v79;
  UnityEngine_Vector4_o v80;
  UnityEngine_Vector4_o v81;
  UnityEngine_Vector4_o v82;
  UnityEngine_Vector4_o v83;
  UnityEngine_Vector4_o v84;

  *&v69.x = 0;
  *&v69.z = 0;
  v6 = Allocate(dds3TrackPolyList_t);
  dds3TrackPolyList_t___ctor(v6);
  v7 = Allocate(dds3TrackPolyList_t);
  dds3TrackPolyList_t___ctor(v7);
  *&v81.x = 0;
  *&v81.z = 0;
  *&v80.x = 0;
  *&v80.z = 0;
  *&v79.x = 0;
  *&v79.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  *&v77.x = 0;
  *&v77.z = 0;
  *&v76.x = 0;
  *&v76.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v74.x = 0;
  *&v74.z = 0;
  *&v73.x = 0;
  *&v73.z = 0;
  *&v72.x = 0;
  *&v72.z = 0;
  *&v71.x = 0;
  *&v71.z = 0;
  *&v70.x = 0;
  *&v70.z = 0;
  v8 = *pThunderPoly;
  trackList = (*pThunderPoly)->hPoly->trackList;
  v11 = trackList->m_Items[number];
  v12 = v8->hPoly_c->trackList;
  pVertex = v11->pVertex;
  v15 = v12->m_Items[number];
  split = v8->param->split;
  v17 = v15->pVertex;
  v11->count = v8->hPoly->point;
  v15->count = (*pThunderPoly)->hPoly_c->point;
  sub_854930(&v81, 0);
  sub_854710(&v81, 0);
  sub_854930(&v81, 1u);
  sub_854930(&v81, 2u);
  sub_854710(&v81, 0);
  sub_854930(&v80, 0);
  sub_854710(&v80, 0);
  sub_854930(&v80, 1u);
  sub_854930(&v80, 2u);
  sub_854710(&v80, 0);
  sub_854930(&v79, 0);
  sub_854710(&v79, 0);
  sub_854930(&v79, 1u);
  sub_854930(&v79, 2u);
  pos = (*pThunderPoly)->param->pos;
  SDF_VU0__LOADVECTOR(pos->m_Items[1]);
  v20 = (*pThunderPoly)->param->pos;
  SDF_VU0__LOADVECTOR_B(v20->m_Items[0]);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__GETLENGTH();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&p);
  SDF_VU0__LOADVECTOR(dds3CameraTargetPos);
  SDF_VU0__LOADVECTOR_B(dds3CameraEyePos);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__STOREVECTOR(&v73);
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v74);
  v25 = DDS3EFFECT_RAND_F();
  v26 = (*pThunderPoly)->param->pos;
  v28 = v25 * 6.2832;
  SDF_VU0__COPYVECTOR(&dst, v26->m_Items[0]);
  sdfSin(v28);
  sub_854930(&v72, 0);
  sub_854710(&v72, 0);
  sub_854930(&v72, 1u);
  sub_854930(&v72, 2u);
  SDF_VU0__LOADVECTOR(v74);
  SDF_VU0__LOADVECTOR_B(v72);
  SDF_VU0__MULVECTOR();
  SDF_VU0__LOADVECTOR_B(dst);
  SDF_VU0__ADDVECTOR_B_A();
  SDF_VU0__STOREVECTOR_B(&dst);
  sub_854930(&v71, 0);
  sub_854710(&v71, 0);
  sub_854930(&v71, 1u);
  sub_854930(&v71, 2u);
  sdfSin(v28);
  sub_854930(&v72, 0);
  sub_854710(&v72, 0);
  sub_854930(&v72, 1u);
  sub_854930(&v72, 2u);
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__LOADVECTOR_B(v71);
  SDF_VU0__MULVECTOR();
  SDF_VU0__COPYVECTOR_A_TO_C();
  SDF_VU0__LOADVECTOR(v74);
  SDF_VU0__LOADVECTOR_B(v72);
  SDF_VU0__MULVECTOR();
  SDF_VU0__ADDVECTOR_A_C();
  SDF_VU0__COPYVECTOR_A_TO_C();
  SDF_VU0__LOADVECTOR_B(dst);
  SDF_VU0__ADDVECTOR_B_A();
  SDF_VU0__STOREVECTOR_B(&v77);
  SDF_VU0__COPYVECTOR_C_TO_A();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v76);
  if (split)
  {
    v30 = 96 * split;
    v31 = v28 + -6.2832;
    *&v3 = (3.1416 / split) * 4.0;
    v32 = 0;
    v33 = 0;
    v34 = &v17->m_Items[1];
    v35 = 2;
    do
    {
      SDF_VU0__LOADVECTOR(v76);
      SDF_VU0__LOADVECTOR_B(v73);
      SDF_VU0__OUTERPRODUCT();
      SDF_VU0__NORMALIZE();
      SDF_VU0__STOREVECTOR(&v76);
      SDF_VU0__LOADVECTOR_B(v81);
      SDF_VU0__MULVECTOR();
      SDF_VU0__COPYVECTOR_A_TO_C();
      SDF_VU0__LOADVECTOR(dst);
      SDF_VU0__COPYVECTOR_A_TO_B();
      SDF_VU0__ADDVECTOR_A_C();
      SDF_VU0__STOREVECTOR(v34 - 1);
      SDF_VU0__COPYVECTOR_C_TO_A();
      SDF_VU0__SUBVECTOR_B_A();
      v37 = v33 + 1;
      SDF_VU0__STOREVECTOR_B(v34);
      SDF_VU0__LOADVECTOR(v76);
      SDF_VU0__LOADVECTOR_B(v80);
      SDF_VU0__MULVECTOR();
      SDF_VU0__COPYVECTOR_A_TO_C();
      SDF_VU0__LOADVECTOR(dst);
      v40 = (pVertex + v32 * 16);
      SDF_VU0__STOREVECTOR(&pVertex->m_Items[v32 + 1]);
      SDF_VU0__COPYVECTOR_A_TO_B();
      SDF_VU0__ADDVECTOR_A_C();
      SDF_VU0__STOREVECTOR(v40 + 2);
      SDF_VU0__COPYVECTOR_C_TO_A();
      SDF_VU0__SUBVECTOR_B_A();
      SDF_VU0__STOREVECTOR_B(v40 + 4);
      SDF_VU0__COPYVECTOR(&v70, v76);
      SDF_VU0__COPYVECTOR(&dst, v77);
      SDF_VU0__LOADVECTOR(v76);
      SDF_VU0__LOADVECTOR_B(v81);
      SDF_VU0__MULVECTOR();
      SDF_VU0__COPYVECTOR_A_TO_C();
      SDF_VU0__LOADVECTOR(dst);
      SDF_VU0__COPYVECTOR_A_TO_B();
      SDF_VU0__ADDVECTOR_A_C();
      v43 = v37 + 1;
      SDF_VU0__STOREVECTOR(v34 + 1);
      SDF_VU0__COPYVECTOR_C_TO_A();
      SDF_VU0__SUBVECTOR_B_A();
      v45 = v43 + 1;
      v47 = v35 + 1;
      SDF_VU0__STOREVECTOR_B(v34 + 2);
      SDF_VU0__LOADVECTOR(v76);
      SDF_VU0__LOADVECTOR_B(v80);
      SDF_VU0__MULVECTOR();
      SDF_VU0__COPYVECTOR_A_TO_C();
      SDF_VU0__LOADVECTOR(dst);
      SDF_VU0__STOREVECTOR(v40 + 6);
      SDF_VU0__COPYVECTOR_A_TO_B();
      SDF_VU0__ADDVECTOR_A_C();
      SDF_VU0__STOREVECTOR(v40 + 5);
      SDF_VU0__COPYVECTOR_C_TO_A();
      SDF_VU0__SUBVECTOR_B_A();
      SDF_VU0__STOREVECTOR_B(v40 + 7);
      v31 = *&v3 + v31;
      if (v31 > 3.1416)
      {
        v31 = v31 + -3.1416;
        DDS3EFFECT_RAND_F();
      }
      v28 = *&v3 + v28;
      v52 = v3;
      sdfSin(v28);
      sub_854930(&v72, 0);
      sub_854710(&v72, 0);
      sub_854930(&v72, 1u);
      sub_854930(&v72, 2u);
      SDF_VU0__LOADVECTOR(p);
      SDF_VU0__LOADVECTOR_B(v71);
      SDF_VU0__MULVECTOR();
      SDF_VU0__COPYVECTOR_A_TO_C();
      SDF_VU0__LOADVECTOR(v74);
      SDF_VU0__LOADVECTOR_B(v72);
      SDF_VU0__MULVECTOR();
      SDF_VU0__ADDVECTOR_A_C();
      *&v69.x = 0;
      *&v69.z = 0;
      SDF_VU0__STOREVECTOR(&v69);
      v55 = DDS3EFFECT_RAND_PM();
      x = v73.x;
      y = v73.y;
      z = v73.z;
      w = v73.w;
      v60 = v55;
      v84.x = x;
      v84.y = y;
      v84.z = z;
      v84.w = w;
      SetRotateMatrixAxis(v60 * 0.34907, v84);
      SDF_VU0__LOADVECTOR(v69);
      SDF_VU0__APPLYMATRIX_XYZ();
      SDF_VU0__COPYVECTOR_A_TO_C();
      SDF_VU0__LOADVECTOR_B(dst);
      SDF_VU0__ADDVECTOR_B_A();
      SDF_VU0__STOREVECTOR_B(&v77);
      SDF_VU0__COPYVECTOR_C_TO_A();
      SDF_VU0__NORMALIZE();
      SDF_VU0__STOREVECTOR(&v76);
      SDF_VU0__LOADVECTOR(v77);
      SDF_VU0__LOADVECTOR_B(dst);
      SDF_VU0__SUBVECTOR();
      SDF_VU0__NORMALIZE();
      SDF_VU0__LOADVECTOR_B(v70);
      v61 = SDF_VU0__INNERPRODUCT();
      max_length_low = LODWORD(pVertex->max_length);
      if (v61 >= 0.0)
      {
        v64 = v40[5].x;
        v65 = v40[5].y;
        v66 = v40[5].z;
        v67 = v40[5].w;
        v82 = v79;
      }
      else
      {
        v64 = v40[7].x;
        v65 = v40[7].y;
        v66 = v40[7].z;
        v67 = v40[7].w;
        v82 = v80;
      }
      SDF_VU0__LOADVECTOR_C(v82);
      v3 = v52;
      SDF_VU0__LOADVECTOR(v76);
      SDF_VU0__LOADVECTOR_B(v73);
      SDF_VU0__OUTERPRODUCT();
      SDF_VU0__NORMALIZE();
      SDF_VU0__COPYVECTOR_C_TO_B();
      SDF_VU0__MULVECTOR();
      v83.x = v64;
      v83.y = v65;
      v83.z = v66;
      v83.w = v67;
      SDF_VU0__LOADVECTOR_B(v83);
      SDF_VU0__ADDVECTOR();
      SDF_VU0__STOREVECTOR(&dst);
      v32 += 6;
      v34 += 4;
      v35 += 6LL;
      v33 = v45 + 1;
    }
    while (v30 != (v32 * 16));
  }
}

// 0x1773400
void effPCP_ThunderPolyLowSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_ThunderPolyLow_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCP_ThunderPolyLow_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[2].klass) = abgr;
}

// 0x1773210
void effPCP_ThunderPolyLowSetPosition(void **hData, sdfVector4_t pPos) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  Il2CppObject *v8;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  const char *name;
  const char *v13;
  const char *v15;
  const char *v17;
  char *v19;
  s64 *v20;
  u64 v21[3];
  UnityEngine_Vector4_o v22;

  w = pPos.w;
  z = pPos.z;
  y = pPos.y;
  x = pPos.x;
  v8 = *hData;
  klass = v8->klass;
  if (v8->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_ThunderPolyLow_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCP_ThunderPolyLow_t, v21);
    if ((v21[0] & 1) != 0)
      v19 = v21[2];
    else
      v19 = v21 + 1;
    v20 = sub_8C4940(v19);
  }
  name = v8[1].klass->_1.name;
  SDF_VU0__LOADVECTOR(*(name + 3), 0);
  v22.x = x;
  v22.y = y;
  v22.z = z;
  v22.w = w;
  SDF_VU0__LOADVECTOR_B(v22);
  v13 = v8[1].klass->_1.name;
  SDF_VU0__STOREVECTOR_B(v13 + 3);
  SDF_VU0__SUBVECTOR_B_A();
  v15 = v8[1].klass->_1.name;
  SDF_VU0__LOADVECTOR(*(v15 + 2), 0);
  SDF_VU0__ADDVECTOR();
  v17 = v8[1].klass->_1.name;
  SDF_VU0__STOREVECTOR(v17 + 2);
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
  __int128 v3;
  u64 *v6;
  struct dds3TrackPoly_t_o *hPoly;
  struct dds3TrackPolyList_t_array *trackList;
  dds3TrackPolyList_t_o *v10;
  struct UnityEngine_Vector4_array *pVertex;
  u32 split;
  struct UnityEngine_Vector4_array *pos;
  struct UnityEngine_Vector4_array *v15;
  f32 v20;
  struct UnityEngine_Vector4_array *v21;
  f32 v23;
  f32 v25;
  u64 v26;
  f32 v27;
  s32 v28;
  s64 v29;
  UnityEngine_Vector4_o *v31;
  u64 v38;
  __int128 v43;
  f32 v46;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  f32 v51;
  f32 v52;
  u64 max_length_low;
  f32 v55;
  f32 v56;
  f32 v57;
  f32 v58;
  dds3TrackPolyList_t_o *v60;
  UnityEngine_Vector4_o v61;
  UnityEngine_Vector4_o v62;
  UnityEngine_Vector4_o v63;
  UnityEngine_Vector4_o v64;
  UnityEngine_Vector4_o v65;
  UnityEngine_Vector4_o v66;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v68;
  UnityEngine_Vector4_o v69;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o v71;
  UnityEngine_Vector4_o v72;
  UnityEngine_Vector4_o v73;
  UnityEngine_Vector4_o v74;
  UnityEngine_Vector4_o v75;
  UnityEngine_Vector4_o v76;

  *&v61.x = 0;
  *&v61.z = 0;
  v6 = Allocate(dds3TrackPolyList_t);
  dds3TrackPolyList_t___ctor(v6);
  *&v73.x = 0;
  *&v73.z = 0;
  *&v72.x = 0;
  *&v72.z = 0;
  *&v71.x = 0;
  *&v71.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  *&v69.x = 0;
  *&v69.z = 0;
  *&v68.x = 0;
  *&v68.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v66.x = 0;
  *&v66.z = 0;
  *&v65.x = 0;
  *&v65.z = 0;
  *&v64.x = 0;
  *&v64.z = 0;
  *&v63.x = 0;
  *&v63.z = 0;
  *&v62.x = 0;
  *&v62.z = 0;
  hPoly = (*pThunderPoly)->hPoly;
  trackList = hPoly->trackList;
  v10 = trackList->m_Items[number];
  pVertex = v10->pVertex;
  split = (*pThunderPoly)->param->split;
  v10->count = hPoly->point;
  v60 = v10;
  sub_854930(&v73, 0);
  sub_854710(&v73, 0);
  sub_854930(&v73, 1u);
  sub_854930(&v73, 2u);
  sub_854710(&v73, 0);
  sub_854930(&v72, 0);
  sub_854710(&v72, 0);
  sub_854930(&v72, 1u);
  sub_854930(&v72, 2u);
  sub_854710(&v72, 0);
  sub_854930(&v71, 0);
  sub_854710(&v71, 0);
  sub_854930(&v71, 1u);
  sub_854930(&v71, 2u);
  pos = (*pThunderPoly)->param->pos;
  SDF_VU0__LOADVECTOR(pos->m_Items[1]);
  v15 = (*pThunderPoly)->param->pos;
  SDF_VU0__LOADVECTOR_B(v15->m_Items[0]);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__GETLENGTH();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&p);
  SDF_VU0__LOADVECTOR(dds3CameraTargetPos);
  SDF_VU0__LOADVECTOR_B(dds3CameraEyePos);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__STOREVECTOR(&v65);
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v66);
  v20 = DDS3EFFECT_RAND_F();
  v21 = (*pThunderPoly)->param->pos;
  v23 = v20 * 6.2832;
  SDF_VU0__COPYVECTOR(&dst, v21->m_Items[0]);
  sdfSin(v23);
  sub_854930(&v64, 0);
  sub_854710(&v64, 0);
  sub_854930(&v64, 1u);
  sub_854930(&v64, 2u);
  SDF_VU0__LOADVECTOR(v66);
  SDF_VU0__LOADVECTOR_B(v64);
  SDF_VU0__MULVECTOR();
  SDF_VU0__LOADVECTOR_B(dst);
  SDF_VU0__ADDVECTOR_B_A();
  SDF_VU0__STOREVECTOR_B(&dst);
  sub_854930(&v63, 0);
  sub_854710(&v63, 0);
  sub_854930(&v63, 1u);
  sub_854930(&v63, 2u);
  sdfSin(v23);
  sub_854930(&v64, 0);
  sub_854710(&v64, 0);
  sub_854930(&v64, 1u);
  sub_854930(&v64, 2u);
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__LOADVECTOR_B(v63);
  SDF_VU0__MULVECTOR();
  SDF_VU0__COPYVECTOR_A_TO_C();
  SDF_VU0__LOADVECTOR(v66);
  SDF_VU0__LOADVECTOR_B(v64);
  SDF_VU0__MULVECTOR();
  SDF_VU0__ADDVECTOR_A_C();
  SDF_VU0__COPYVECTOR_A_TO_C();
  SDF_VU0__LOADVECTOR_B(dst);
  SDF_VU0__ADDVECTOR_B_A();
  SDF_VU0__STOREVECTOR_B(&v69);
  SDF_VU0__COPYVECTOR_C_TO_A();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v68);
  if (split)
  {
    v25 = split;
    v26 = 4;
    v27 = v23 + -6.2832;
    v28 = 160 * split;
    *&v3 = (3.1416 / v25) * 4.0;
    v29 = 0;
    do
    {
      SDF_VU0__LOADVECTOR(v68);
      SDF_VU0__LOADVECTOR_B(v65);
      SDF_VU0__OUTERPRODUCT();
      SDF_VU0__NORMALIZE();
      SDF_VU0__STOREVECTOR(&v68);
      SDF_VU0__COPYVECTOR_A_TO_B();
      SDF_VU0__LOADVECTOR(dst);
      v31 = (pVertex + v29 * 16);
      SDF_VU0__STOREVECTOR(&pVertex->m_Items[v29 + 2]);
      SDF_VU0__COPYVECTOR_B_TO_A();
      SDF_VU0__LOADVECTOR_B(v73);
      SDF_VU0__MULVECTOR();
      SDF_VU0__COPYVECTOR_A_TO_C();
      SDF_VU0__LOADVECTOR(dst);
      SDF_VU0__COPYVECTOR_A_TO_B();
      SDF_VU0__ADDVECTOR_A_C();
      SDF_VU0__STOREVECTOR(v31 + 3);
      SDF_VU0__COPYVECTOR_C_TO_A();
      SDF_VU0__SUBVECTOR_B_A();
      SDF_VU0__STOREVECTOR_B(v31 + 5);
      SDF_VU0__LOADVECTOR(v68);
      SDF_VU0__LOADVECTOR_B(v72);
      SDF_VU0__MULVECTOR();
      SDF_VU0__COPYVECTOR_A_TO_C();
      SDF_VU0__LOADVECTOR(dst);
      SDF_VU0__COPYVECTOR_A_TO_B();
      SDF_VU0__ADDVECTOR_A_C();
      SDF_VU0__STOREVECTOR(v31 + 2);
      SDF_VU0__COPYVECTOR_C_TO_A();
      SDF_VU0__SUBVECTOR_B_A();
      SDF_VU0__STOREVECTOR_B(v31 + 6);
      SDF_VU0__COPYVECTOR(&v62, v68);
      SDF_VU0__COPYVECTOR(&dst, v69);
      SDF_VU0__LOADVECTOR(dst);
      SDF_VU0__STOREVECTOR(v31 + 9);
      SDF_VU0__LOADVECTOR(v68);
      SDF_VU0__LOADVECTOR_B(v73);
      SDF_VU0__MULVECTOR();
      SDF_VU0__COPYVECTOR_A_TO_C();
      SDF_VU0__LOADVECTOR(dst);
      SDF_VU0__COPYVECTOR_A_TO_B();
      SDF_VU0__ADDVECTOR_A_C();
      v38 = v26 + 1;
      SDF_VU0__STOREVECTOR(v31 + 8);
      SDF_VU0__COPYVECTOR_C_TO_A();
      SDF_VU0__SUBVECTOR_B_A();
      SDF_VU0__STOREVECTOR_B(v31 + 10);
      SDF_VU0__LOADVECTOR(v68);
      SDF_VU0__LOADVECTOR_B(v72);
      SDF_VU0__MULVECTOR();
      SDF_VU0__COPYVECTOR_A_TO_C();
      SDF_VU0__LOADVECTOR(dst);
      SDF_VU0__COPYVECTOR_A_TO_B();
      SDF_VU0__ADDVECTOR_A_C();
      SDF_VU0__STOREVECTOR(v31 + 7);
      SDF_VU0__COPYVECTOR_C_TO_A();
      SDF_VU0__SUBVECTOR_B_A();
      SDF_VU0__STOREVECTOR_B(v31 + 11);
      v27 = *&v3 + v27;
      if (v27 > 3.1416)
      {
        v27 = v27 + -3.1416;
        DDS3EFFECT_RAND_F();
      }
      v23 = *&v3 + v23;
      v43 = v3;
      sdfSin(v23);
      sub_854930(&v64, 0);
      sub_854710(&v64, 0);
      sub_854930(&v64, 1u);
      sub_854930(&v64, 2u);
      SDF_VU0__LOADVECTOR(p);
      SDF_VU0__LOADVECTOR_B(v63);
      SDF_VU0__MULVECTOR();
      SDF_VU0__COPYVECTOR_A_TO_C();
      SDF_VU0__LOADVECTOR(v66);
      SDF_VU0__LOADVECTOR_B(v64);
      SDF_VU0__MULVECTOR();
      SDF_VU0__ADDVECTOR_A_C();
      *&v61.x = 0;
      *&v61.z = 0;
      SDF_VU0__STOREVECTOR(&v61);
      v46 = DDS3EFFECT_RAND_PM();
      x = v65.x;
      y = v65.y;
      z = v65.z;
      w = v65.w;
      v51 = v46;
      v76.x = x;
      v76.y = y;
      v76.z = z;
      v76.w = w;
      SetRotateMatrixAxis(v51 * 0.34907, v76);
      SDF_VU0__LOADVECTOR(v61);
      SDF_VU0__APPLYMATRIX_XYZ();
      SDF_VU0__COPYVECTOR_A_TO_C();
      SDF_VU0__LOADVECTOR_B(dst);
      SDF_VU0__ADDVECTOR_B_A();
      SDF_VU0__STOREVECTOR_B(&v69);
      SDF_VU0__COPYVECTOR_C_TO_A();
      SDF_VU0__NORMALIZE();
      SDF_VU0__STOREVECTOR(&v68);
      SDF_VU0__LOADVECTOR(v69);
      SDF_VU0__LOADVECTOR_B(dst);
      SDF_VU0__SUBVECTOR();
      SDF_VU0__NORMALIZE();
      SDF_VU0__LOADVECTOR_B(v62);
      v52 = SDF_VU0__INNERPRODUCT();
      max_length_low = LODWORD(pVertex->max_length);
      if (v52 >= 0.0)
      {
        v55 = v31[7].x;
        v56 = v31[7].y;
        v57 = v31[7].z;
        v58 = v31[7].w;
        v74 = v71;
      }
      else
      {
        v55 = v31[11].x;
        v56 = v31[11].y;
        v57 = v31[11].z;
        v58 = v31[11].w;
        v74 = v72;
      }
      SDF_VU0__LOADVECTOR_C(v74);
      v3 = v43;
      SDF_VU0__LOADVECTOR(v68);
      SDF_VU0__LOADVECTOR_B(v65);
      SDF_VU0__OUTERPRODUCT();
      SDF_VU0__NORMALIZE();
      SDF_VU0__COPYVECTOR_C_TO_B();
      SDF_VU0__MULVECTOR();
      v75.x = v55;
      v75.y = v56;
      v75.z = v57;
      v75.w = v58;
      SDF_VU0__LOADVECTOR_B(v75);
      SDF_VU0__ADDVECTOR();
      SDF_VU0__STOREVECTOR(&dst);
      v29 += 10;
      v26 += 10LL;
    }
    while (v28 != (v29 * 16));
  }
  v60->pVertex = pVertex;
}

// 0x1771790
void effPCP_ThunderPolySetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_ThunderPoly_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCP_ThunderPoly_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[2].klass) = abgr;
}

// 0x17715a0
void effPCP_ThunderPolySetPosition(void **hData, sdfVector4_t pPos) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  Il2CppObject *v8;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  const char *name;
  const char *v13;
  const char *v15;
  const char *v17;
  char *v19;
  s64 *v20;
  u64 v21[3];
  UnityEngine_Vector4_o v22;

  w = pPos.w;
  z = pPos.z;
  y = pPos.y;
  x = pPos.x;
  v8 = *hData;
  klass = v8->klass;
  if (v8->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_ThunderPoly_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCP_ThunderPoly_t, v21);
    if ((v21[0] & 1) != 0)
      v19 = v21[2];
    else
      v19 = v21 + 1;
    v20 = sub_8C4940(v19);
  }
  name = v8[1].klass->_1.name;
  SDF_VU0__LOADVECTOR(*(name + 3), 0);
  v22.x = x;
  v22.y = y;
  v22.z = z;
  v22.w = w;
  SDF_VU0__LOADVECTOR_B(v22);
  v13 = v8[1].klass->_1.name;
  SDF_VU0__STOREVECTOR_B(v13 + 3);
  SDF_VU0__SUBVECTOR_B_A();
  v15 = v8[1].klass->_1.name;
  SDF_VU0__LOADVECTOR(*(v15 + 2), 0);
  SDF_VU0__ADDVECTOR();
  v17 = v8[1].klass->_1.name;
  SDF_VU0__STOREVECTOR(v17 + 2);
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
  effPCP_ThunderRadiatePolyParam_t_o *v5;
  effPCP_ThunderRadiatePolyParam_t_c *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 *v10;
  effPCP_ThunderRadiatePoly_t_o *v11;
  u64 *v12;
  struct effPCP_ThunderRadiatePolyPart_t_array *v13;
  struct effPCP_ThunderRadiatePolyParam_t_o *param;
  s32 number;
  s32 split;
  u64 v18;
  u32 *pPart;
  u64 *v21;
  effPCP_ThunderRadiatePoly_t_o *v25;
  u64 v26[3];

  v25 = 0;
  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_ThunderRadiatePolyParam_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCP_ThunderRadiatePolyParam_t, v26);
      if ((v26[0] & 1) != 0)
        v8 = v26[2];
      else
        v8 = v26 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v10);
  v11 = Allocate(effPCP_ThunderRadiatePoly_t);
  effPCP_ThunderRadiatePoly_t___ctor(v11);
  v25 = v11;
  v12 = Allocate(effPCP_ThunderRadiatePolyParam_t);
  effPCP_ThunderRadiatePolyParam_t___ctor(v12);
  v11->param = v12;
  effPCP_ThunderRadiatePolyParam_t__pClone(v5, &v11->param);
  v13 = NewSpecific(effPCP_ThunderRadiatePolyPart_t, v5->number);
  param = v11->param;
  v11->pPart = v13;
  v11->hMem = v10;
  number = param->number;
  split = param->split;
  v11->hPoly = dds3TrackPolyCreate(number, 2 * split - 1, 0, 2);
  dds3TrackPolyVC3Set_Acute(&v11->hPoly, v11->param->color_center, v11->param->color_border, v11->param->color_edge);
  dds3TrackPolySetMode(&v11->hPoly, v11->param->blend);
  if (v11->param->number)
  {
    v18 = 0;
    do
    {
      pPart = v11->pPart;
      v21 = Allocate(effPCP_ThunderRadiatePolyPart_t);
      effPCP_ThunderRadiatePolyPart_t___ctor(v21);
      *&pPart[2 * v18 + 8] = v21;
      effPCP_ThunderRadiatePolyPartInit(&v25, v18++);
    }
    while (v18 < v11->param->number);
  }
  return v11;
}

// 0x1774860
void effPCP_ThunderRadiatePolyDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3TrackPoly_t_o **p_monitor;
  u64 v9[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_ThunderRadiatePoly_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCP_ThunderRadiatePoly_t, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  p_monitor = &v3[2].monitor;
  dds3TrackPolyDelete(p_monitor);
}

// 0x1774cb0
void effPCP_ThunderRadiatePolyDraw(void **hData) {
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  s64 bits;
  u64 i;
  u64 *monitor;
  s64 v13;
  s64 v14;
  s32 v16;
  s64 v17;
  u32 v18;
  Il2CppObject *v20;
  u64 v21[3];

  v20 = 0;
  v4 = *hData;
  if (*hData)
  {
    klass = v4->klass;
    if (v4->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_ThunderRadiatePoly_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCP_ThunderRadiatePoly_t, v21);
      if ((v21[0] & 1) != 0)
        v7 = v21[2];
      else
        v7 = v21 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  v20 = *hData;
  bits = v4[1].klass->_1.byval_arg.bits;
  if (bits >= 1)
  {
    for (i = 0; i != bits; ++i)
    {
      while (1)
      {
        while (1)
        {
          while (1)
          {
            monitor = v4[1].monitor;
            v13 = monitor[i + 4];
            v14 = *(v4[2].monitor + 5);
            v16 = *(v13 + 28);
            if (!v16)
              break;
            *(v13 + 28) = v16 - 1;
            if (bits == ++i)
              goto LABEL_29;
          }
          if (!*(v13 + 32))
            break;
          effPCP_ThunderRadiatePolyPartRefresh(&v20, i);
          --*(v13 + 32);
          if (bits == ++i)
            goto LABEL_29;
        }
        v17 = *(v14 + 8 * i + 32);
        v18 = *(v17 + 40);
        if (!HIBYTE(v18))
          break;
        *(v17 + 40) = v18 - 0x20000000;
        if (bits == ++i)
          goto LABEL_29;
      }
      effPCP_ThunderRadiatePolyPartInit(&v20, i);
      dds3TrackPolyListInit(&v4[2].monitor, i);
    }
  }
LABEL_29:
  dds3TrackPolyDraw(&v4[2].monitor, "effPCP_ThunderRadiatePolyDraw");
}

// 0x1774b90
void effPCP_ThunderRadiatePolyDrawOff(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3TrackPoly_t_o **p_monitor;
  u64 v9[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_ThunderRadiatePoly_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCP_ThunderRadiatePoly_t, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  p_monitor = &v3[2].monitor;
  dds3TrackPolyDrawOff(p_monitor);
}

// 0x1773990
void effPCP_ThunderRadiatePolyPartInit(effPCP_ThunderRadiatePoly_t **pThunderRadiatePoly, s32 number) {
  struct effPCP_ThunderRadiatePolyPart_t_array *pPart;
  effPCP_ThunderRadiatePolyPart_t_o *v7;
  f32 v8;
  f32 v9;
  f32 v10;

  pPart = (*pThunderRadiatePoly)->pPart;
  v7 = pPart->m_Items[number];
  v8 = DDS3EFFECT_RAND_PM();
  sub_8529B0(&v7->fields, 0, v8);
  v9 = DDS3EFFECT_RAND_PM();
  sub_8529B0(&v7->fields, 1, v9);
  v10 = DDS3EFFECT_RAND_PM();
  sub_8529B0(&v7->fields, 2, v10);
  v7->wait = DDS3EFFECT_RAND_I() % (*pThunderRadiatePoly)->param->interval;
  v7->refresh = DDS3EFFECT_RAND_I() % (*pThunderRadiatePoly)->param->refresh + 1;
}

// 0x1773ad0
void effPCP_ThunderRadiatePolyPartRefresh(effPCP_ThunderRadiatePoly_t **pThunderRadiatePoly, s32 number) {
  u64 *v5;
  effPCP_ThunderRadiatePoly_t_o *v6;
  struct effPCP_ThunderRadiatePolyPart_t_array *pPart;
  effPCP_ThunderRadiatePolyPart_t_o *v9;
  struct dds3TrackPoly_t_o *hPoly;
  struct dds3TrackPolyList_t_array *trackList;
  dds3TrackPolyList_t_o *v13;
  s32 split;
  struct UnityEngine_Vector4_array *pVertex;
  s32 v18;
  s64 v19;
  u64 v20;
  UnityEngine_Vector4_o *v22;
  f32 v36;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  f32 v41;
  f32 v42;
  u64 max_length_low;
  f32 v45;
  f32 v46;
  f32 v47;
  f32 v48;
  UnityEngine_Vector4_o v50;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v52;
  UnityEngine_Vector4_o v53;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o v55;
  UnityEngine_Vector4_o v56;
  UnityEngine_Vector4_o v57;
  UnityEngine_Vector4_o v58;
  UnityEngine_Vector4_o v59;
  UnityEngine_Vector4_o v60;
  UnityEngine_Vector4_o v61;
  UnityEngine_Vector4_o v62;

  v5 = Allocate(dds3TrackPolyList_t);
  dds3TrackPolyList_t___ctor(v5);
  *&v59.x = 0;
  *&v59.z = 0;
  *&v58.x = 0;
  *&v58.z = 0;
  *&v57.x = 0;
  *&v57.z = 0;
  *&v56.x = 0;
  *&v56.z = 0;
  *&v55.x = 0;
  *&v55.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  *&v53.x = 0;
  *&v53.z = 0;
  *&v52.x = 0;
  *&v52.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v50.x = 0;
  *&v50.z = 0;
  v6 = *pThunderRadiatePoly;
  pPart = (*pThunderRadiatePoly)->pPart;
  v9 = pPart->m_Items[number];
  hPoly = v6->hPoly;
  trackList = hPoly->trackList;
  v13 = trackList->m_Items[number];
  split = v6->param->split;
  pVertex = v13->pVertex;
  v13->count = hPoly->point;
  sub_854930(&v59, 0);
  sub_854710(&v59, 0);
  sub_854930(&v59, 1u);
  sub_854930(&v59, 2u);
  sub_854710(&v59, 0);
  sub_854930(&v58, 0);
  sub_854710(&v58, 0);
  sub_854930(&v58, 1u);
  sub_854930(&v58, 2u);
  sub_854710(&v58, 0);
  sub_854930(&v57, 0);
  sub_854710(&v57, 0);
  sub_854930(&v57, 1u);
  sub_854930(&v57, 2u);
  sub_854710(&v57, 0);
  sub_854930(&v56, 0);
  sub_854710(&v56, 0);
  sub_854930(&v56, 1u);
  sub_854930(&v56, 2u);
  SDF_VU0__LOADVECTOR(dds3CameraTargetPos);
  SDF_VU0__LOADVECTOR_B(dds3CameraEyePos);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__STOREVECTOR(&p);
  sub_8527D0(&v9->dir.x, 0);
  sub_854930(&v52, 0);
  sub_8527D0(&v9->dir.x, 1);
  sub_854930(&v52, 1u);
  sub_8527D0(&v9->dir.x, 2);
  sub_854930(&v52, 2u);
  SDF_VU0__LOADVECTOR_B(v52);
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v50);
  SDF_VU0__COPYVECTOR(&dst, (*pThunderRadiatePoly)->param->pos, 0);
  if (split)
  {
    v18 = 160 * split;
    v19 = 0;
    v20 = 5;
    do
    {
      SDF_VU0__LOADVECTOR(v52);
      SDF_VU0__LOADVECTOR_B(p);
      SDF_VU0__OUTERPRODUCT();
      SDF_VU0__NORMALIZE();
      SDF_VU0__STOREVECTOR(&v53);
      SDF_VU0__LOADVECTOR_B(v59);
      SDF_VU0__MULVECTOR();
      SDF_VU0__COPYVECTOR_A_TO_C();
      SDF_VU0__LOADVECTOR(dst);
      SDF_VU0__COPYVECTOR_A_TO_B();
      SDF_VU0__ADDVECTOR_A_C();
      v22 = (pVertex + v19 * 16);
      SDF_VU0__STOREVECTOR(&pVertex->m_Items[v19 + 2]);
      SDF_VU0__COPYVECTOR_C_TO_A();
      SDF_VU0__SUBVECTOR_B_A();
      SDF_VU0__STOREVECTOR_B(v22 + 5);
      SDF_VU0__LOADVECTOR(v53);
      SDF_VU0__LOADVECTOR_B(v58);
      SDF_VU0__MULVECTOR();
      SDF_VU0__COPYVECTOR_A_TO_C();
      SDF_VU0__LOADVECTOR(dst);
      SDF_VU0__COPYVECTOR_A_TO_B();
      SDF_VU0__ADDVECTOR_A_C();
      SDF_VU0__STOREVECTOR(v22 + 3);
      SDF_VU0__COPYVECTOR_C_TO_A();
      SDF_VU0__SUBVECTOR_B_A();
      SDF_VU0__STOREVECTOR_B(v22 + 6);
      SDF_VU0__LOADVECTOR(v53);
      SDF_VU0__LOADVECTOR_B(v57);
      SDF_VU0__MULVECTOR();
      SDF_VU0__COPYVECTOR_A_TO_C();
      SDF_VU0__LOADVECTOR(dst);
      SDF_VU0__COPYVECTOR_A_TO_B();
      SDF_VU0__ADDVECTOR_A_C();
      SDF_VU0__STOREVECTOR(v22 + 2);
      SDF_VU0__COPYVECTOR_C_TO_A();
      SDF_VU0__SUBVECTOR_B_A();
      SDF_VU0__STOREVECTOR_B(v22 + 7);
      DDS3EFFECT_RAND_F();
      sub_854930(&v55, 0);
      sub_854710(&v55, 0);
      sub_854930(&v55, 1u);
      sub_854930(&v55, 2u);
      SDF_VU0__LOADVECTOR(v52);
      SDF_VU0__LOADVECTOR_B(v55);
      SDF_VU0__MULVECTOR();
      SDF_VU0__LOADVECTOR_B(dst);
      SDF_VU0__ADDVECTOR();
      SDF_VU0__STOREVECTOR(&dst);
      SDF_VU0__LOADVECTOR(v53);
      SDF_VU0__LOADVECTOR_B(v59);
      SDF_VU0__MULVECTOR();
      SDF_VU0__COPYVECTOR_A_TO_C();
      SDF_VU0__LOADVECTOR(dst);
      SDF_VU0__COPYVECTOR_A_TO_B();
      SDF_VU0__ADDVECTOR_A_C();
      SDF_VU0__STOREVECTOR(v22 + 9);
      SDF_VU0__COPYVECTOR_C_TO_A();
      SDF_VU0__SUBVECTOR_B_A();
      SDF_VU0__STOREVECTOR_B(v22 + 10);
      SDF_VU0__LOADVECTOR(v53);
      SDF_VU0__LOADVECTOR_B(v58);
      SDF_VU0__MULVECTOR();
      SDF_VU0__COPYVECTOR_A_TO_C();
      SDF_VU0__LOADVECTOR(dst);
      SDF_VU0__COPYVECTOR_A_TO_B();
      SDF_VU0__ADDVECTOR_A_C();
      SDF_VU0__STOREVECTOR(v22 + 8);
      SDF_VU0__COPYVECTOR_C_TO_A();
      SDF_VU0__SUBVECTOR_B_A();
      SDF_VU0__STOREVECTOR_B(v22 + 11);
      SDF_VU0__LOADVECTOR(v53);
      SDF_VU0__LOADVECTOR_B(v57);
      SDF_VU0__MULVECTOR();
      SDF_VU0__COPYVECTOR_A_TO_C();
      SDF_VU0__LOADVECTOR(dst);
      SDF_VU0__COPYVECTOR_A_TO_B();
      SDF_VU0__ADDVECTOR_A_C();
      SDF_VU0__STOREVECTOR(v22 + 7);
      SDF_VU0__COPYVECTOR_C_TO_A();
      SDF_VU0__SUBVECTOR_B_A();
      SDF_VU0__STOREVECTOR_B(v22 + 12);
      v36 = DDS3EFFECT_RAND_PM();
      x = p.x;
      y = p.y;
      z = p.z;
      w = p.w;
      v41 = v36;
      v62.x = x;
      v62.y = y;
      v62.z = z;
      v62.w = w;
      SetRotateMatrixAxis(v41 * 1.2217, v62);
      SDF_VU0__LOADVECTOR(v52);
      SDF_VU0__APPLYMATRIX_XYZ();
      SDF_VU0__STOREVECTOR(&v52);
      SDF_VU0__LOADVECTOR_B(v53);
      v42 = SDF_VU0__INNERPRODUCT();
      max_length_low = LODWORD(pVertex->max_length);
      if (v42 >= 0.0)
      {
        v45 = v22[6].x;
        v46 = v22[6].y;
        v47 = v22[6].z;
        v48 = v22[6].w;
        v60 = v56;
      }
      else
      {
        v45 = v22[11].x;
        v46 = v22[11].y;
        v47 = v22[11].z;
        v48 = v22[11].w;
        v60 = v57;
      }
      SDF_VU0__LOADVECTOR_C(v60);
      SDF_VU0__LOADVECTOR(v52);
      SDF_VU0__LOADVECTOR_B(p);
      SDF_VU0__OUTERPRODUCT();
      SDF_VU0__NORMALIZE();
      SDF_VU0__STOREVECTOR(&v53);
      SDF_VU0__COPYVECTOR_C_TO_B();
      SDF_VU0__MULVECTOR();
      v61.x = v45;
      v61.y = v46;
      v61.z = v47;
      v61.w = v48;
      SDF_VU0__LOADVECTOR_B(v61);
      SDF_VU0__ADDVECTOR();
      SDF_VU0__STOREVECTOR(&dst);
      v19 += 10;
      v20 += 10LL;
    }
    while (v18 != (v19 * 16));
  }
}

// 0x1774aa0
void effPCP_ThunderRadiatePolySetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_ThunderRadiatePoly_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCP_ThunderRadiatePoly_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[2].klass) = abgr;
}

// 0x1774980
void effPCP_ThunderRadiatePolySetPosition(void **hData, sdfVector4_t pPos) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v10;
  s64 *v11;
  u64 v12[3];
  UnityEngine_Vector4_o v13;

  w = pPos.w;
  z = pPos.z;
  y = pPos.y;
  x = pPos.x;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_ThunderRadiatePoly_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCP_ThunderRadiatePoly_t, v12);
    if ((v12[0] & 1) != 0)
      v10 = v12[2];
    else
      v10 = v12 + 1;
    v11 = sub_8C4940(v10);
  }
  v13.x = x;
  v13.y = y;
  v13.z = z;
  v13.w = w;
  SDF_VU0__COPYVECTOR(&(*hData)[1].klass->_1.name, v13, 0);
}
