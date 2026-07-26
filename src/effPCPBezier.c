#include "types.h"

typedef struct XRD773Unity_CommonMesh XRD773Unity_CommonMesh;
typedef struct XRD773Unity_GraphicManager XRD773Unity_GraphicManager;
typedef struct XRD773Unity_GraphicManager_CommonObject XRD773Unity_GraphicManager_CommonObject;
typedef struct dds3BezierTrackPolyABGR_tag dds3BezierTrackPolyABGR_tag;
typedef struct dds3BezierTrackPoly_tag dds3BezierTrackPoly_tag;
typedef struct dds3EffectPCPData_t dds3EffectPCPData_t;
typedef struct effBTL_t effBTL_t;
typedef struct effBezier7PPart_t effBezier7PPart_t;
typedef struct effEveBEDCutHandle_t effEveBEDCutHandle_t;
typedef struct effEveBEDParams_t effEveBEDParams_t;
typedef struct effPCPBezierBillParam_t effPCPBezierBillParam_t;
typedef struct effPCPBezierBill_tag effPCPBezierBill_tag;
typedef struct nbFormation_t nbFormation_t;
typedef struct sdf3DPrimPolyParm_t sdf3DPrimPolyParm_t;
typedef struct sdfMat_t sdfMat_t;
typedef struct sdfRandCB_t sdfRandCB_t;

static sdf3DPrimPolyParm_t *BZTP_PrimPolyParm;
static u32 bztpSquareFaceIndex[84];
static sdf3DPrimPolyParm_t *BZTP_H_PrimPolyParm;
static u32 bztpHeadFaceIndex[6];
static sdfVector4_t bztpHeadVertex[8];

void FromEuler(f32 aRotateX, f32 aRotateY, f32 aRotateZ);
sdfColor_t **GetColor(XRD773Unity_CommonMesh *this);
void *GetEffPCPAgiFireballPart(void *hData, s32 offset);
s32 **GetIndexTable(XRD773Unity_CommonMesh *this);
XRD773Unity_CommonMesh *GetMesh(XRD773Unity_GraphicManager *this, s32 index, bool outlinechk);
sdfVector3_t **GetPosition(XRD773Unity_CommonMesh *this);
void SDF_VU0__ADDVECTOR_A_C(void);
void SDF_VU0__APPLYMATRIX_XYZ(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__COPYVECTOR_A_TO_B(void);
void SDF_VU0__COPYVECTOR_A_TO_C(void);
void SDF_VU0__COPYVECTOR_C_TO_A(void);
f32 SDF_VU0__GETLENGTH(void);
void SDF_VU0__INTERPOLATE(f32 rate);
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
void SDF_VU0__SWAPVECTOR_A_C(void);
void SetActive(XRD773Unity_GraphicManager_CommonObject *this, bool act);
void SetAutoHide(XRD773Unity_GraphicManager_CommonObject *this, bool act);
void SetColor_20241296(XRD773Unity_CommonMesh *this, sdfColor_t **col);
void SetIndexTable(XRD773Unity_CommonMesh *this, s32 **idx);
void SetPosition_20241056(XRD773Unity_CommonMesh *this, sdfVector3_t **pos);
void SetRotateMatrixAxis(f32 aAngle, sdfVector4_t aAxis);
s32 dds3Bezier7PPartRun(effBezier7PPart_t **pPart, sdfVector4_t *pOut);
dds3BezierTrackPoly_tag *dds3BezierTrackPolyCreate(u32 face, u32 split);
void dds3BezierTrackPolyDelete(dds3BezierTrackPoly_tag *hPoly);
void dds3BezierTrackPolyDraw(dds3BezierTrackPoly_tag *hPoly);
void dds3BezierTrackPolySetVC(dds3BezierTrackPoly_tag **hPoly, dds3BezierTrackPolyABGR_tag *pABGR);
void dds3BezierTrackPolySetVertex(dds3BezierTrackPoly_tag **hPoly, sdfVector4_t **pVertex);
void *dds3EffectPCPDataGetDataUnityOffSet(void *hData, s32 offset, s32 type);
void dds3EffectPCPData_t__pCopy(dds3EffectPCPData_t *this, u8 **bytedata, s32 *pos);
void effBTLModelGetSphereCenter(nbFormation_t **pFormation);
s32 effBTLSkillCheckRun(void);
nbFormation_t *effBTLSkillGetInvokeFormation(s32 idx);
nbFormation_t *effBTLSkillGetTargetFormation(u32 number);
void effBezier7PPart_t__Clear(effBezier7PPart_t *this);
u32 effColorBlend(u32 abgr0, u32 abgr1, f32 rate);
effBTL_t *effEveBEDCreate(u8 **pData);
effEveBEDCutHandle_t *effEveBEDCutCreate(effBTL_t *hEveBED, u16 CutNum, effEveBEDParams_t *pParams);
void effEveBEDCutDelete(effEveBEDCutHandle_t *hEveBEDCut);
void effEveBEDCutDraw(effEveBEDCutHandle_t **hEveBEDCut);
void effEveBEDCutSetParams(effEveBEDCutHandle_t **hEveBEDCut, effEveBEDParams_t *pParams);
void effEveBEDDelete(effBTL_t *hEveBED);
effPCPBezierBill_tag *effPCPBezierBillCreate(effPCPBezierBillParam_t *pParam, void *pBEDData);
void effPCPBezierBillParam_t__pClone(effPCPBezierBillParam_t *this, effPCPBezierBillParam_t **dst);
f32 sdfAtan2(f32 aY, f32 aX);
u32 sdfGetRand(sdfRandCB_t **aCB);
f32 sdfGetRandFloat(sdfRandCB_t **aCB);
sdfMat_t *sdfMatNew(void);

// 0x16c3f20
dds3BezierTrackPoly_tag *dds3BezierTrackPolyCreate(u32 face, u32 split) {
  u64 v5;
  u64 *v6;
  u64 *v7;

  v5 = 3 * face * split + 6;
  v6 = Allocate(dds3BezierTrackPoly_tag);
  _ctor(v6, 0);
  v6[5] = NewSpecific(UnityEngine_Vector4, v5);
  v6[9] = NewSpecific(UnityEngine_Vector4, 8u);
  v6[6] = NewSpecific(uint, v5);
  v7 = NewSpecific(uint, 8u);
  *(v6 + 28) = 0x300000000LL;
  v6[10] = v7;
  *(v6 + 6) = v5;
  *(v6 + 9) = split;
  v6[2] = 0x280808080LL;
  v6[8] = 0;
  v6[9] = bztpHeadVertex;
  v6[7] = sdfMatNew();
  BZTP_PrimPolyParm->attr = 0x4000;
  BZTP_PrimPolyParm->faceIndex = bztpSquareFaceIndex;
  PrimPolyParm->attr = 0x4000;
  PrimPolyParm->faceIndex = bztpHeadFaceIndex;
  PrimPolyParm->faceCount = 6;
  PrimPolyParm->pointCount = 8;
  return v6;
}

// 0x16c40c0
void dds3BezierTrackPolyDelete(dds3BezierTrackPoly_tag *hPoly) {
  struct XRD773Unity_CommonMesh_array *pMesh;
  il2cpp_array_size_t max_length;
  s64 v5;
  u64 v6;
  UnityEngine_Object_o *v8;
  struct XRD773Unity_CommonMesh_array *v9;
  UnityEngine_Object_o *gameObject;
  struct XRD773Unity_CommonMesh_array *v13;
  s64 v15;

  pMesh = hPoly->pMesh;
  if (pMesh)
  {
    max_length = pMesh->max_length;
    if (max_length >= 1)
    {
      v5 = 4;
      do
      {
        v6 = v5 - 4;
        v8 = *(&pMesh->obj.klass + v5);
        if (op_Inequality(v8, 0, 0))
        {
          v9 = hPoly->pMesh;
          gameObject = get_gameObject(*(&v9->obj.klass + v5), 0);
          Destroy_27360000(gameObject);
          v13 = hPoly->pMesh;
          *(&v13->obj.klass + v5) = 0;
        }
        pMesh = hPoly->pMesh;
        LODWORD(max_length) = pMesh->max_length;
        v15 = v5 - 3;
        ++v5;
      }
      while (v15 < max_length);
    }
    hPoly->pMesh = 0;
  }
}

// 0x16c4220
void dds3BezierTrackPolyDraw(dds3BezierTrackPoly_tag *hPoly) {
    GetMesh(0, 0, 0);
    SetAutoHide(0, 0);
    GetPosition(0);
    SetPosition_20241056(0, 0);
    SetColor_20241296(0, 0);
    SetIndexTable(0, 0);
    GetColor(0);
    GetIndexTable(0);
    SetActive(0, 0);
}

// 0x16c51c0
void dds3BezierTrackPolyReset(dds3BezierTrackPoly_tag **hPoly) {
  (*hPoly)->count = 0;
  (*hPoly)->current = 3;
  (*hPoly)->abgr = -2139062144;
}

// 0x16c4fd0
void dds3BezierTrackPolySetVC(dds3BezierTrackPoly_tag **hPoly, dds3BezierTrackPolyABGR_tag *pABGR) {
  s32 point;
  u32 v4;
  f32 v5;
  struct System_UInt32_array *pVC;
  u32 s_e;
  u32 v8;
  u32 e_e;
  u32 v10;
  f32 v11;
  f32 v12;
  f32 v13;
  f32 v14;
  f32 v15;
  u64 v16;
  u32 v17;
  u32 v18;
  u32 v19;
  u32 v20;
  u32 v22;
  u32 *v24;
  u32 v25;
  u64 max_length_low;
  u64 v27;
  u32 v32;
  u32 v33;

  point = (*hPoly)->point;
  if ((point + 2) >= 5)
  {
    v4 = point / 3;
    v5 = v4;
    v32 = v4 >> 1;
    v33 = v4;
    pVC = (*hPoly)->pVC;
    s_e = pABGR->s_e;
    v8 = pABGR->s_c & 0xFFFFFF;
    e_e = pABGR->e_e;
    v10 = pABGR->e_c & 0xFFFFFF;
    v11 = 1.0 / v5;
    v12 = (v4 >> 1);
    v13 = 1.0 / v12;
    v14 = 0.0;
    v15 = 0.0;
    v16 = 0;
    v17 = 0;
    do
    {
      v18 = vcvts_n_s32_f32(v15, 0x1Fu);
      v19 = vcvts_n_u32_f32(v15, 0x1Fu);
      if ((v15 * 2147500000.0) >= 0.0)
        v20 = v19;
      else
        v20 = v18;
      v22 = effColorBlend(e_e, s_e, v14);
      v24 = (pVC + 4 * v16);
      v24[8] = v22;
      v25 = effColorBlend(v10, v8, v14);
      max_length_low = LODWORD(pVC->max_length);
      v27 = v16 + 1;
      v24[9] = v25;
      v24[9] = v25 | v20 & 0xFF000000;
      v14 = v11 + v14;
      if (v17++ < v32)
        v15 = v13 + v15;
      v16 = v27 + 2;
      v24[10] = v24[8];
    }
    while (v17 < v33);
  }
}

// 0x16c4cd0
void dds3BezierTrackPolySetVertex(dds3BezierTrackPoly_tag **hPoly, sdfVector4_t **pVertex) {
  struct UnityEngine_Vector4_array *v3;
  s64 current;
  s64 v10;
  s64 v13;
  dds3BezierTrackPoly_tag_o *v15;
  s32 point;
  struct UnityEngine_Vector4_array *v17;
  struct UnityEngine_Vector4_array *v18;
  struct UnityEngine_Vector4_array *v21;
  s32 count;

  v3 = (*hPoly)->pVertex;
  current = (*hPoly)->current;
  SDF_VU0__COPYVECTOR(&v3->m_Items[current], pVertex->m_Items[0]);
  v10 = (*hPoly)->current + 1LL;
  SDF_VU0__COPYVECTOR(&v3->m_Items[v10], pVertex->m_Items[1]);
  v13 = (*hPoly)->current + 2LL;
  SDF_VU0__COPYVECTOR(&v3->m_Items[v13], pVertex->m_Items[2]);
  (*hPoly)->current += 3;
  v15 = *hPoly;
  point = (*hPoly)->point;
  if ((*hPoly)->current == point)
  {
    v17 = v15->pVertex;
    SDF_VU0__COPYVECTOR(v17->m_Items, pVertex->m_Items[0]);
    v18 = (*hPoly)->pVertex;
    SDF_VU0__COPYVECTOR(&v18->m_Items[1], pVertex->m_Items[1]);
    v21 = (*hPoly)->pVertex;
    SDF_VU0__COPYVECTOR(&v21->m_Items[2], pVertex->m_Items[2]);
    (*hPoly)->current = 3;
    v15 = *hPoly;
    point = (*hPoly)->point;
  }
  count = v15->count;
  if (count < point - 3)
    v15->count = count + 3;
}

// 0x16c5a60
effPCPBezierBill_tag *effPCPBezierBillCopy(void **hData, s32 bPos, bool tbldata) {
    effPCPBezierBillParam_t__pClone(0, 0);
    dds3BezierTrackPolyCreate(0, 0);
    dds3BezierTrackPolySetVC(0, 0);
    effBezier7PPart_t__Clear(0);
    effEveBEDCutCreate(0, 0, 0);
    return 0;
}

// 0x16c51f0
effPCPBezierBill_tag *effPCPBezierBillCreate(effPCPBezierBillParam_t *pParam, void *pBEDData) {
    effEveBEDCreate(0);
    dds3BezierTrackPolyCreate(0, 0);
    dds3BezierTrackPolySetVC(0, 0);
    effBezier7PPart_t__Clear(0);
    effEveBEDCutCreate(0, 0, 0);
    return 0;
}

// 0x16c57b0
effPCPBezierBill_tag *effPCPBezierBillCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    GetEffPCPAgiFireballPart(0, 0);
    effPCPBezierBillCreate(0, 0);
    return 0;
}

// 0x16c6030
void effPCPBezierBillDelete(void **hData) {
    dds3BezierTrackPolyDelete(0);
    effEveBEDCutDelete(0);
    effEveBEDDelete(0);
}

// 0x16c6210
void effPCPBezierBillDraw(void **hData) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    effBTLSkillCheckRun();
    effBTLSkillGetTargetFormation(0);
    effBTLSkillGetInvokeFormation(0);
    effBTLModelGetSphereCenter(0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    dds3Bezier7PPartRun(0, 0);
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__OUTERPRODUCT();
    SDF_VU0__NORMALIZE();
    SDF_VU0__MULVECTOR();
    SDF_VU0__SWAPVECTOR_A_C();
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__ADDVECTOR_A_C();
    SDF_VU0__COPYVECTOR_C_TO_A();
    SDF_VU0__SUBVECTOR_B_A();
    SDF_VU0__STOREVECTOR_B(0);
    dds3BezierTrackPolySetVertex(0, 0);
    SDF_VU0__LOADVECTOR_C((sdfVector4_t){0});
    SDF_VU0__INTERPOLATE(0);
    sdfAtan2(0, 0);
    FromEuler(0, 0, 0);
    effEveBEDCutSetParams(0, 0);
    effEveBEDCutDraw(0);
    dds3BezierTrackPolyDraw(0);
    sdfGetRandFloat(0);
    SDF_VU0__GETLENGTH();
    SetRotateMatrixAxis(0, (sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX_XYZ();
    sdfGetRand(0);
}

// 0x16ca620
void effPCPBezierBillSetColor(void **hData, u32 abgr) {
}

// 0x16ca500
void effPCPBezierBillSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}
