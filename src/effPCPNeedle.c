#include "types.h"

typedef struct XRD773Unity_CommonMesh XRD773Unity_CommonMesh;
typedef struct XRD773Unity_GraphicManager XRD773Unity_GraphicManager;
typedef struct XRD773Unity_GraphicManager_CommonObject XRD773Unity_GraphicManager_CommonObject;
typedef struct dds3EffectPCPData_t dds3EffectPCPData_t;
typedef struct dds3NeedleModel_tag dds3NeedleModel_tag;
typedef struct dds3TrackPoly_t dds3TrackPoly_t;
typedef struct effPCPNeedleSpiralParam_t effPCPNeedleSpiralParam_t;
typedef struct effPCPNeedleSpiral_tag effPCPNeedleSpiral_tag;
typedef struct nbFormation_t nbFormation_t;
typedef struct sdf3DPrimPolyParm_t sdf3DPrimPolyParm_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfMat_t sdfMat_t;

static sdf3DPrimPolyParm_t *NM_PrimPolyParm;

f32 DDS3EFFECT_RAND_F(void);
f32 DDS3EFFECT_RAND_FA(f32 r);
u32 DDS3EFFECT_RAND_I(void);
sdfColor_t **GetColor(XRD773Unity_CommonMesh *this);
s32 **GetIndexTable(XRD773Unity_CommonMesh *this);
XRD773Unity_CommonMesh *GetMesh(XRD773Unity_GraphicManager *this, s32 index, bool outlinechk);
sdfVector3_t **GetPosition(XRD773Unity_CommonMesh *this);
void LookAtMatrix(sdfVector4_t aTarget, sdfVector4_t aEye, sdfVector4_t aDown);
void ReverseMatrix(void);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__ADDVECTOR_A_C(void);
void SDF_VU0__APPLYMATRIX_XYZ(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__COPYVECTOR_A_TO_B(void);
void SDF_VU0__COPYVECTOR_A_TO_C(void);
void SDF_VU0__COPYVECTOR_C_TO_A(void);
void SDF_VU0__COPYVECTOR_C_TO_B(void);
void SDF_VU0__LOADMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__MULVECTOR(void);
void SDF_VU0__NORMALIZE(void);
void SDF_VU0__OUTERPRODUCT(void);
void SDF_VU0__STOREIDENTITY(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__STOREVECTOR_B(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
void SDF_VU0__SUBVECTOR_B_A(void);
void SDF_VU0__SWAPVECTOR_A_C(void);
void SetActive(XRD773Unity_GraphicManager_CommonObject *this, bool act);
void SetAutoHide(XRD773Unity_GraphicManager_CommonObject *this, bool act);
void SetColor_20241296(XRD773Unity_CommonMesh *this, sdfColor_t **col);
void SetIndexTable(XRD773Unity_CommonMesh *this, s32 **idx);
void SetPosition_20241056(XRD773Unity_CommonMesh *this, sdfVector3_t **pos);
void SetRotateMatrixAxis(f32 aAngle, sdfVector4_t aAxis);
void *dds3EffectPCPDataGetDataUnityOffSet(void *hData, s32 offset, s32 type);
void dds3EffectPCPData_t__pCopy(dds3EffectPCPData_t *this, u8 **bytedata, s32 *pos);
dds3NeedleModel_tag *dds3NeedleModelCreate(u32 number);
void dds3NeedleModelDelete(dds3NeedleModel_tag *hNModel);
void dds3NeedleModelDraw(dds3NeedleModel_tag *hNModel);
void dds3NeedleModelGetPosition(dds3NeedleModel_tag *hNModel, u32 index, sdfVector4_t *pPos);
void dds3NeedleModelSetPosition(dds3NeedleModel_tag **hNModel, u32 index, sdfVector4_t pPos);
void dds3NeedleModelVNCListCreate(dds3NeedleModel_tag **hNModel, u32 split, f32 radius, f32 length, u32 abgr_in, u32 abgr_out);
void dds3TrackPolyColorSet(dds3TrackPoly_t **hTrackPoly, s32 number, u32 color);
dds3TrackPoly_t *dds3TrackPolyCreate(s32 number, s32 face, s32 rec, s32 type);
void dds3TrackPolyDelete(dds3TrackPoly_t **hTrackPoly);
void dds3TrackPolyDraw(dds3TrackPoly_t **hTrackPoly, char *funcname);
void dds3TrackPolyListInit(dds3TrackPoly_t **hTrackPoly, s32 number);
void dds3TrackPolySet(dds3TrackPoly_t **hTrackPoly, s32 number, sdfVector4_t **pV);
void dds3TrackPolySetMode(dds3TrackPoly_t **hTrackPoly, u16 mode);
void dds3TrackPolyVCRefresh_ParType1(dds3TrackPoly_t **hTrackPoly, u32 index);
void dds3TrackPolyVCSet(dds3TrackPoly_t **hTrackPoly, s32 type, u32 abgr_in, u32 abgr_out);
void effBTLModelGetSphereCenter(nbFormation_t **pFormation);
s32 effBTLSkillCheckRun(void);
nbFormation_t *effBTLSkillGetInvokeFormation(s32 idx);
u32 effColorBlend(u32 abgr0, u32 abgr1, f32 rate);
sdfColor_t effGetBlendColor(u32 icol);
sdfColor_t effGetVertexColor(u32 icol, sdfColor_t blend_col);
effPCPNeedleSpiral_tag *effPCPNeedleSpiralCreate(effPCPNeedleSpiralParam_t *pParam);
void effPCPNeedleSpiralParam_t__pClone(effPCPNeedleSpiralParam_t *this, effPCPNeedleSpiralParam_t **param);
f32 sdfCos(f32 aRadius);
sdfMat_t *sdfMatNew(void);
void sdfMatSetConstant(sdfMat_t *aMat, f32 aRatio);
f32 sdfSin(f32 aRadius);

// 0x1758db0
dds3NeedleModel_tag *dds3NeedleModelCreate(u32 number) {
  dds3NeedleModel_tag_o *v3;
  s64 v4;
  struct System_Single_array *v5;
  struct System_Single_array *scale;
  struct System_Single_array *v9;
  sdfMat_t_o *v12;
  u64 v14;
  u32 *pPart;
  u64 *v17;
  struct dds3NeedleModelPart_tag_array *v19;
  Il2CppClass **v21;

  v3 = Allocate(dds3NeedleModel_tag);
  _ctor(v3, 0);
  v4 = number;
  v3->pPart = NewSpecific(dds3NeedleModelPart_tag, number);
  v3->number = number;
  v3->blend = 2;
  v5 = NewSpecific(f32, 3u);
  v3->scale = v5;
  v5->m_Items[0] = 1.0;
  scale = v3->scale;
  scale->m_Items[1] = 1.0;
  v9 = v3->scale;
  v9->m_Items[2] = 1.0;
  v3->hVNMem = 0;
  v3->hMem = 0;
  SDF_VU0__STOREIDENTITY(&v3->matrix);
  v12 = sdfMatNew();
  v3->pMat = v12;
  sdfMatSetConstant(v12, 1.0);
  if (number)
  {
    v14 = 0;
    do
    {
      pPart = v3->pPart;
      v17 = Allocate(dds3NeedleModelPart_tag);
      _ctor(v17, 0);
      *&pPart[2 * v14 + 8] = v17;
      v19 = v3->pPart;
      v21 = &v19->obj.klass + v14++;
      LODWORD(v21[4]->_1.byval_arg.data) = -2139062144;
    }
    while (v4 != v14);
  }
  NM_PrimPolyParm->attr = 0x4000;
  return v3;
}

// 0x1759020
void dds3NeedleModelDelete(dds3NeedleModel_tag *hNModel) {
  Il2CppObject *hVNMem;
  struct XRD773Unity_CommonMesh_array *pMesh;
  il2cpp_array_size_t max_length;
  s64 v6;
  u64 v7;
  UnityEngine_Object_o *v9;
  struct XRD773Unity_CommonMesh_array *v10;
  UnityEngine_Object_o *gameObject;
  struct XRD773Unity_CommonMesh_array *v14;
  s64 v16;

  hVNMem = hNModel->hVNMem;
  if (hVNMem)
  {
    Write_2930400(StringLiteral_15538, hVNMem);
  }
  pMesh = hNModel->pMesh;
  if (pMesh)
  {
    max_length = pMesh->max_length;
    if (max_length >= 1)
    {
      v6 = 4;
      do
      {
        v7 = v6 - 4;
        v9 = *(&pMesh->obj.klass + v6);
        if (op_Inequality(v9, 0, 0))
        {
          v10 = hNModel->pMesh;
          gameObject = get_gameObject(*(&v10->obj.klass + v6), 0);
          Destroy_27360000(gameObject);
          v14 = hNModel->pMesh;
          *(&v14->obj.klass + v6) = 0;
        }
        pMesh = hNModel->pMesh;
        LODWORD(max_length) = pMesh->max_length;
        v16 = v6 - 3;
        ++v6;
      }
      while (v16 < max_length);
    }
    hNModel->pMesh = 0;
  }
}

// 0x17593b0
void dds3NeedleModelDraw(dds3NeedleModel_tag *hNModel) {
    GetMesh(0, 0, 0);
    SetAutoHide(0, 0);
    effGetBlendColor(0);
    GetPosition(0);
    SetPosition_20241056(0, 0);
    SetColor_20241296(0, 0);
    SetIndexTable(0, 0);
    GetColor(0);
    GetIndexTable(0);
    effGetVertexColor(0, (sdfColor_t){0});
    SetActive(0, 0);
}

// 0x17592a0
void dds3NeedleModelDrawOff(dds3NeedleModel_tag *hNModel) {
  struct XRD773Unity_CommonMesh_array *pMesh;
  il2cpp_array_size_t max_length;
  s64 v5;
  UnityEngine_Object_o *v7;
  struct XRD773Unity_CommonMesh_array *v8;
  s64 v10;

  pMesh = hNModel->pMesh;
  if (pMesh)
  {
    max_length = pMesh->max_length;
    if (max_length >= 1)
    {
      v5 = 4;
      do
      {
        v7 = *(&pMesh->obj.klass + v5);
        if (op_Inequality(v7, 0, 0))
        {
          v8 = hNModel->pMesh;
          SetActive(*(&v8->obj.klass + v5), 0, 0);
        }
        pMesh = hNModel->pMesh;
        LODWORD(max_length) = pMesh->max_length;
        v10 = v5 - 3;
        ++v5;
      }
      while (v10 < max_length);
    }
  }
}

// 0x1759ee0
void dds3NeedleModelGetPosition(dds3NeedleModel_tag *hNModel, u32 index, sdfVector4_t *pPos) {
}

// 0x1759ff0
void dds3NeedleModelSetColor(dds3NeedleModel_tag **hNModel, u32 index, u32 abgr) {
  struct dds3NeedleModelPart_tag_array *pPart;

  pPart = (*hNModel)->pPart;
  pPart->m_Items[index]->abgr = abgr;
}

// 0x175a050
void dds3NeedleModelSetMatrix(dds3NeedleModel_tag **hNModel, sdfMatrix4_t *pMatrix) {
  s64 v3;
  s64 v4;
  s64 v6;
  s64 v7;
  s64 v8;
  s64 v9;
  UnityEngine_Matrix4x4_o v10;

  v3 = *&pMatrix->m00;
  v4 = *&pMatrix->m20;
  v6 = *&pMatrix->m21;
  *&v10.m01 = *&pMatrix->m01;
  *&v10.m21 = v6;
  *&v10.m00 = v3;
  *&v10.m20 = v4;
  v7 = *&pMatrix->m02;
  v8 = *&pMatrix->m22;
  v9 = *&pMatrix->m23;
  *&v10.m03 = *&pMatrix->m03;
  *&v10.m23 = v9;
  *&v10.m02 = v7;
  *&v10.m22 = v8;
  SDF_VU0__LOADMATRIX(&v10);
  SDF_VU0__STOREMATRIX(&(*hNModel)->matrix, 0);
}

// 0x1759db0
void dds3NeedleModelSetPosition(dds3NeedleModel_tag **hNModel, u32 index, sdfVector4_t pPos) {
}

// 0x175a0b0
void dds3NeedleModelVNCListCreate(dds3NeedleModel_tag **hNModel, u32 split, f32 radius, f32 length, u32 abgr_in, u32 abgr_out) {
    sdfCos(0);
    sdfSin(0);
}

// 0x1759210
void dds3NeedleModelVNCListDelete(dds3NeedleModel_tag *hNModel) {
  Il2CppObject *hVNMem;

  hVNMem = hNModel->hVNMem;
  if (hVNMem)
  {
    Write_2930400(StringLiteral_15538, hVNMem);
  }
}

// 0x175af50
effPCPNeedleSpiral_tag *effPCPNeedleSpiralCopy(void **hData, s32 bPos, bool tbldata) {
    effPCPNeedleSpiralCreate(0);
    return 0;
}

// 0x175a7f0
effPCPNeedleSpiral_tag *effPCPNeedleSpiralCreate(effPCPNeedleSpiralParam_t *pParam) {
  u64 *v3;
  u64 *v4;
  u32 number;
  u32 v7;
  dds3NeedleModel_tag_o *v8;
  struct System_UInt32_array *n_vc;
  u32 max_length;
  u32 v12;
  s32 v15;
  s32 v16;
  dds3TrackPoly_t_o *v17;
  u64 v18;
  s64 v19;
  u32 timing;
  u64 v21;
  s64 v22;
  f32 v23;
  f32 v24;
  s64 v25;
  u32 *v27;
  u64 v28;
  u64 *v29;
  u64 v32;
  s64 v34;
  u32 v35;
  s64 v37;
  s64 v39;

  v3 = Allocate(effPCPNeedleSpiral_tag);
  _ctor(v3, 0);
  v3[3] = NewSpecific(effPCPNeedleSpiralPart_tag, pParam->number);
  v4 = Allocate(effPCPNeedleSpiralParam_t);
  effPCPNeedleSpiralParam_t___ctor(v4);
  v3[2] = v4;
  effPCPNeedleSpiralParam_t__pClone(pParam, v3 + 2);
  number = pParam->number;
  v3[7] = 0;
  *(v3 + 8) = -2139062144;
  *(v3 + 9) = number;
  v3[5] = 0;
  v7 = pParam->number;
  v8 = dds3NeedleModelCreate(v7);
  v3[6] = v8;
  v8->blend = pParam->blend;
  n_vc = pParam->n_vc;
  max_length = n_vc->max_length;
  v12 = n_vc->m_Items[0];
  dds3NeedleModelVNCListCreate(v3 + 6, pParam->n_split, pParam->n_radius, pParam->n_length, v12, pParam->n_vc->m_Items[1]);
  v15 = *(v3 + 9);
  v16 = *(v3[2] + 100);
  v17 = dds3TrackPolyCreate(v15, v16, 0, 0);
  v18 = v3[2];
  v3[5] = v17;
  dds3TrackPolyVCSet(v3 + 5, 1, *(v18 + 104), *(v18 + 104), 0);
  dds3TrackPolySetMode(v3 + 5, *(v3[2] + 40), 0);
  v19 = *(v3 + 9);
  if (pParam->timing)
    timing = pParam->timing;
  else
    timing = 1;
  if (v19)
  {
    v21 = v3[2];
    v22 = -v19;
    v24 = *(v21 + 64);
    v23 = *(v21 + 68);
    v25 = 4;
    do
    {
      v27 = v3[3];
      v28 = v25 - 4;
      v29 = Allocate(effPCPNeedleSpiralPart_tag);
      _ctor(v29, 0);
      *&v27[2 * v25] = v29;
      v32 = v3[3];
      v34 = *(v32 + 8 * v25);
      *(v34 + 56) = DDS3EFFECT_RAND_F() * 6.2832;
      *(v34 + 52) = v24 * DDS3EFFECT_RAND_FA(v23);
      v35 = DDS3EFFECT_RAND_I();
      *(v34 + 48) = v35 / timing * timing - v35;
      v37 = *(v3[6] + 80);
      v39 = *(v37 + 8 * v25++);
      *(v39 + 32) = 8421504;
    }
    while (v22 + v25 != 4);
  }
  return v3;
}

// 0x175a6d0
effPCPNeedleSpiral_tag *effPCPNeedleSpiralCreateP(void **pData, s32 bPos, bool tbldata) {
    effPCPNeedleSpiralCreate(0);
    return 0;
}

// 0x175ad10
effPCPNeedleSpiral_tag *effPCPNeedleSpiralCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    effPCPNeedleSpiralCreate(0);
    return 0;
}

// 0x175abc0
void effPCPNeedleSpiralDelete(void **hData) {
    dds3TrackPolyDelete(0);
    dds3NeedleModelDelete(0);
}

// 0x175b060
void effPCPNeedleSpiralDraw(void **hData) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__STOREVECTOR(0);
    effBTLSkillCheckRun();
    SDF_VU0__LOADMATRIX(0);
    effBTLSkillGetInvokeFormation(0);
    effBTLModelGetSphereCenter(0);
    LookAtMatrix((sdfVector4_t){0}, (sdfVector4_t){0}, (sdfVector4_t){0});
    ReverseMatrix();
    SDF_VU0__STOREMATRIX(0);
    SDF_VU0__APPLYMATRIX_XYZ();
    SDF_VU0__MULVECTOR();
    sdfCos(0);
    sdfSin(0);
    dds3NeedleModelSetPosition(0, 0, (sdfVector4_t){0});
    dds3TrackPolyColorSet(0, 0, 0);
    dds3TrackPolyListInit(0, 0);
    dds3NeedleModelGetPosition(0, 0, 0);
    SDF_VU0__ADDVECTOR();
    SetRotateMatrixAxis(0, (sdfVector4_t){0});
    effColorBlend(0, 0, 0);
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__COPYVECTOR_C_TO_B();
    SDF_VU0__OUTERPRODUCT();
    SDF_VU0__NORMALIZE();
    SDF_VU0__SWAPVECTOR_A_C();
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__ADDVECTOR_A_C();
    SDF_VU0__COPYVECTOR_C_TO_A();
    SDF_VU0__SUBVECTOR_B_A();
    SDF_VU0__STOREVECTOR_B(0);
    dds3TrackPolySet(0, 0, 0);
    dds3TrackPolyVCRefresh_ParType1(0, 0);
    dds3TrackPolyDraw(0, 0);
    dds3NeedleModelDraw(0);
}

// 0x175bf50
void effPCPNeedleSpiralSetColor(void **hData, u32 abgr) {
}

// 0x175bcc0
void effPCPNeedleSpiralSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x175bde0
void effPCPNeedleSpiralSetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__STOREMATRIX(0);
}

// 0x1758da0
void effPkt3DPrimLinkPoly(sdfDrawTag_t *pTag, sdf3DPrimPolyParm_t *pParam) {
  ;
}
