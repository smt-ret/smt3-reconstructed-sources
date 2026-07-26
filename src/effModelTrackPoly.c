#include "types.h"

typedef struct Eff_ModelTrackPolyABGR_t Eff_ModelTrackPolyABGR_t;
typedef struct Eff_ModelTrackPolyParam_t Eff_ModelTrackPolyParam_t;
typedef struct Eff_ModelTrackPoly_tag Eff_ModelTrackPoly_tag;
typedef struct XRD773Unity_CommonMesh XRD773Unity_CommonMesh;
typedef struct XRD773Unity_GraphicManager XRD773Unity_GraphicManager;
typedef struct XRD773Unity_GraphicManager_CommonObject XRD773Unity_GraphicManager_CommonObject;
typedef struct dds3HermitianTrackPoly_tag dds3HermitianTrackPoly_tag;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct effMTPolyListHandle_t effMTPolyListHandle_t;
typedef struct effSwordTrackParams_t effSwordTrackParams_t;
typedef struct sdf3DPrimPolyParm_t sdf3DPrimPolyParm_t;
typedef struct sdfMat_t sdfMat_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;

static sdf3DPrimPolyParm_t *HTP_PrimPolyParm;
static s32 id_Shift;
static s32 id_ColShift;

void Eff_HermitianSpline(sdfVector4_t **pVertex, f32 percentage);
Eff_ModelTrackPoly_tag *Eff_ModelTrackPolyCreate(Eff_ModelTrackPolyParam_t *pParam);
void Eff_ModelTrackPolyDelete(Eff_ModelTrackPoly_tag **hMTPoly);
void Eff_ModelTrackPolyGetMarkPosition(Eff_ModelTrackPoly_tag *hMTPoly);
void Eff_ModelTrackPolyReset(Eff_ModelTrackPoly_tag **hMTPoly);
s32 Eff_ModelTrackPoly_DANTE_Check(dds3ModelHandle_t *hModel);
sdfColor_t **GetColor(XRD773Unity_CommonMesh *this);
s32 **GetIndexTable(XRD773Unity_CommonMesh *this);
XRD773Unity_CommonMesh *GetMesh(XRD773Unity_GraphicManager *this, s32 index, bool outlinechk);
sdfVector3_t **GetPosition(XRD773Unity_CommonMesh *this);
bool MeshDraw(dds3HermitianTrackPoly_tag **hPoly, sdfVector4_t blend_col);
void SDF_VU0__ADDVECTOR_A_C(void);
void SDF_VU0__ADDVECTOR_C_A(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__COPYVECTOR_A_TO_C(void);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__MULVECTOR(void);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
void SetActive(XRD773Unity_GraphicManager_CommonObject *this, bool act);
void SetAutoHide(XRD773Unity_GraphicManager_CommonObject *this, bool act);
void SetColor_20241296(XRD773Unity_CommonMesh *this, sdfColor_t **col);
void SetIndexTable(XRD773Unity_CommonMesh *this, s32 **idx);
void SetPosition_20241056(XRD773Unity_CommonMesh *this, sdfVector3_t **pos);
dds3HermitianTrackPoly_tag *dds3HermitianTrackPolyCreate(u32 face, u32 split);
void dds3HermitianTrackPolyDraw(dds3HermitianTrackPoly_tag **hPoly);
void dds3HermitianTrackPolyGetVertex(dds3HermitianTrackPoly_tag **hPoly, sdfVector4_t *pVertex0, sdfVector4_t *pVertex1, s32 frame);
void dds3HermitianTrackPolySetVC(dds3HermitianTrackPoly_tag **hPoly, Eff_ModelTrackPolyABGR_t *pABGR);
void dds3HermitianTrackPolySetVertex(dds3HermitianTrackPoly_tag **hPoly, sdfVector4_t **pVertex);
void dds3HermitianTrackPolySetVertexSub(dds3HermitianTrackPoly_tag **hPoly, sdfVector4_t **pVertex);
u32 effColorBlend(u32 abgr0, u32 abgr1, f32 rate);
Eff_ModelTrackPoly_tag *effSwordTrackCreate(effSwordTrackParams_t *pParams);
void effSwordTrackDelete(Eff_ModelTrackPoly_tag **hSwordTrack);
void effSwordTrackDraw(Eff_ModelTrackPoly_tag **hSwordTrack);
void effSwordTrackPolygon2DDraw(Eff_ModelTrackPoly_tag **hSwordTrack);
void effSwordTrackRecord(Eff_ModelTrackPoly_tag **hSwordTrack);
s32 mdlGetMajorNum(dds3ModelHandle_t **aHandle);
s32 mdlGetMinorNum(dds3ModelHandle_t **aHandle);
s32 mdlGetMotionFrameForUnity(void *obj);
void pMeshDelete(dds3HermitianTrackPoly_tag **hPoly);
sdfMat_t *sdfMatNew(void);
void sdfMatSetConstant(sdfMat_t *aMat, f32 aRatio);
s32 sdfModelGetMarkPosUnity(sdfModelRootNode_t *aRoot, s32 aId);

// 0x16bf290
u32 DDS3EFFECT_RGBA(u32 r, u32 g, u32 b, u32 a) {
  return r | (g << 8) | (b << 16) | (a << 24);
}

// 0x16c1200
void Eff_HermitianSpline(sdfVector4_t **pVertex, f32 percentage) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__ADDVECTOR_A_C();
    SDF_VU0__MULVECTOR();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__ADDVECTOR_C_A();
}

// 0x16c2540
void Eff_ModelTrackPolyColorSet(Eff_ModelTrackPoly_tag **hMTPoly, u32 abgr) {
  (*hMTPoly)->hPoly->abgr = abgr;
}

// 0x16c1a70
Eff_ModelTrackPoly_tag *Eff_ModelTrackPolyCreate(Eff_ModelTrackPolyParam_t *pParam) {
    Eff_ModelTrackPoly_DANTE_Check(0);
    effSwordTrackCreate(0);
    dds3HermitianTrackPolyCreate(0, 0);
    dds3HermitianTrackPolySetVC(0, 0);
    return 0;
}

// 0x16c1f60
void Eff_ModelTrackPolyDelete(Eff_ModelTrackPoly_tag **hMTPoly) {
  dds3ModelHandle_t_o *hModel;
  dds3HermitianTrackPoly_tag_o **p_hPoly;
  dds3HermitianTrackPoly_tag_o **v7;
  dds3HermitianTrackPoly_tag_o **v9;

  hModel = (*hMTPoly)->param->hModel;
  if (Eff_ModelTrackPoly_DANTE_Check(hModel))
  {
    p_hPoly = &(*hMTPoly)->hPoly;
    pMeshDelete(p_hPoly);
    effSwordTrackDelete(hMTPoly);
    (*hMTPoly)->hPoly = 0;
  }
  v7 = &(*hMTPoly)->hPoly;
  if (*v7)
  {
    pMeshDelete(v7);
    v9 = &(*hMTPoly)->hPoly;
    pMeshDelete(v9);
  }
}

// 0x16c25d0
void Eff_ModelTrackPolyDraw(Eff_ModelTrackPoly_tag **hMTPoly) {
    Eff_ModelTrackPoly_DANTE_Check(0);
    mdlGetMinorNum(0);
    effSwordTrackDraw(0);
    mdlGetMotionFrameForUnity(0);
    Eff_ModelTrackPolyReset(0);
    Eff_ModelTrackPolyGetMarkPosition(0);
    dds3HermitianTrackPolyDraw(0);
}

// 0x16c2550
void Eff_ModelTrackPolyDrawOnly(Eff_ModelTrackPoly_tag **hMTPoly) {
    dds3HermitianTrackPolyDraw(0);
}

// 0x16c2350
void Eff_ModelTrackPolyGetMarkPosition(Eff_ModelTrackPoly_tag *hMTPoly) {
  u64 *v3;
  struct Eff_ModelTrackPolyParam_t_o *param;
  struct System_UInt32_array *mark;
  struct dds3ModelHandle_t_o *hModel;
  sdfModelRootNode_t_o *modelRoot;
  u64 *v9;
  s32 v11;
  struct System_UInt32_array *v13;
  dds3HermitianTrackPoly_tag_o **p_hPoly;

  v3 = NewSpecific(UnityEngine_Vector4, 2u);
  param = hMTPoly->param;
  hModel = param->hModel;
  mark = param->mark;
  modelRoot = hModel->modelRoot;
  v9 = v3;
  v11 = mark->m_Items[0];
  sdfModelGetMarkPosUnity(modelRoot, v11);
  SDF_VU0__STOREVECTOR(v9 + 2);
  v13 = hMTPoly->param->mark;
  sdfModelGetMarkPosUnity(hModel->modelRoot, v13->m_Items[1]);
  SDF_VU0__STOREVECTOR(v9 + 3);
  p_hPoly = &hMTPoly->hPoly;
  dds3HermitianTrackPolySetVertex(p_hPoly, v9);
}

// 0x16c33e0
void Eff_ModelTrackPolyListColorSet(effMTPolyListHandle_t **hMTPolyList, u32 index, u32 abgr) {
}

// 0x16c2fc0
effMTPolyListHandle_t *Eff_ModelTrackPolyListCreate(Eff_ModelTrackPolyParam_t *pParam, u32 number) {
  effMTPolyListHandle_t_o *v5;
  struct Eff_ModelTrackPoly_tag_array *v6;
  u32 *hPolyList;
  u64 v9;
  s64 v10;
  s64 *v12;

  v5 = Allocate(effMTPolyListHandle_t);
  effMTPolyListHandle_t___ctor(v5);
  v6 = NewSpecific(Eff_ModelTrackPoly_tag, number);
  v5->hPolyList = v6;
  v5->number = number;
  v5->hMem = 0;
  if (number)
  {
    hPolyList = v6;
    v9 = 0;
    v10 = number - 1LL;
    v12 = Eff_ModelTrackPolyCreate(pParam);
    if (!v12)
    while (1)
    {
      *&hPolyList[2 * v9 + 8] = v12;
      if (v10 == v9)
        break;
      hPolyList = v5->hPolyList;
      ++v9;
      v12 = Eff_ModelTrackPolyCreate(pParam);
      if (v12)
    }
  }
  return v5;
}

// 0x16c3130
void Eff_ModelTrackPolyListDelete(effMTPolyListHandle_t **hMTPolyList) {
  s64 number;
  u64 v4;
  s64 v5;
  s64 v6;
  struct Eff_ModelTrackPoly_tag_array *hPolyList;

  number = (*hMTPolyList)->number;
  if (number)
  {
    v4 = 0;
    v5 = number - 1;
    v6 = 32;
    hPolyList = (*hMTPolyList)->hPolyList;
    while (1)
    {
      Eff_ModelTrackPolyDelete((hPolyList + v6));
      if (v5 == v4)
        break;
      ++v4;
      v6 += 8;
      hPolyList = (*hMTPolyList)->hPolyList;
      if (v4 >= LODWORD(hPolyList->max_length))
    }
  }
}

// 0x16c34b0
void Eff_ModelTrackPolyListDrawOnly(effMTPolyListHandle_t **hMTPolyList) {
  s64 number;
  s64 v4;
  u64 v5;
  struct Eff_ModelTrackPoly_tag_array *hPolyList;
  Il2CppClass **v9;
  dds3HermitianTrackPoly_tag_o **p_bits;

  number = (*hMTPolyList)->number;
  if (number)
  {
    v4 = number - 1;
    v5 = 0;
    hPolyList = (*hMTPolyList)->hPolyList;
    while (1)
    {
      while (1)
      {
        v9 = &hPolyList->obj.klass + v5;
        p_bits = &v9[4]->_1.byval_arg.bits;
        else
        {
          dds3HermitianTrackPolyDraw(p_bits);
          if (v4 == v5)
            return;
        }
        ++v5;
        hPolyList = (*hMTPolyList)->hPolyList;
          break;
        if (v5 >= LODWORD(hPolyList->max_length))
      }
    }
  }
}

// 0x16c34a0
void Eff_ModelTrackPolyListDrawOnlyOff(effMTPolyListHandle_t *hMTPolyList) {
  ;
}

// 0x16c3330
void Eff_ModelTrackPolyListReset(effMTPolyListHandle_t **hMTPolyList, u32 index) {
    Eff_ModelTrackPolyReset(0);
}

// 0x16c3220
void Eff_ModelTrackPolyListVertexSet(effMTPolyListHandle_t **hMTPolyList, u32 index, sdfVector4_t **pVertex) {
    dds3HermitianTrackPolySetVertex(0, 0);
}

// 0x16c2170
void Eff_ModelTrackPolyReset(Eff_ModelTrackPoly_tag **hMTPoly) {
  dds3ModelHandle_t_o *hModel;
  struct dds3HermitianTrackPoly_tag_o **p_hPoly;

  hModel = (*hMTPoly)->param->hModel;
  if (!Eff_ModelTrackPoly_DANTE_Check((*hMTPoly)->param->hModel))
  (*hMTPoly)->frame = 0;
  (*hMTPoly)->slide_par = 1.0;
  p_hPoly = &(*hMTPoly)->hPoly;
  (*p_hPoly)->count = 0;
  (*p_hPoly)->current = 2;
  (*p_hPoly)->abgr = -2139062144;
}

// 0x16c24c0
void Eff_ModelTrackPolyVertexSet(Eff_ModelTrackPoly_tag **hMTPoly, sdfVector4_t **pVertex) {
  dds3HermitianTrackPoly_tag_o **p_hPoly;

  p_hPoly = &(*hMTPoly)->hPoly;
  dds3HermitianTrackPolySetVertex(p_hPoly, pVertex);
}

// 0x16bf2a0
s32 Eff_ModelTrackPoly_DANTE_Check(dds3ModelHandle_t *hModel) {
  s32 MinorNum;
  dds3ModelHandle_t_o *aHandle;

  aHandle = hModel;
  if (mdlGetMajorNum(&aHandle) != 1)
    return 0;
  MinorNum = mdlGetMinorNum(&aHandle);
  return MinorNum == 192 || (MinorNum - 339) < 3;
}

// 0x16bf720
bool MeshDraw(dds3HermitianTrackPoly_tag **hPoly, sdfVector4_t blend_col) {
    GetMesh(0, 0, 0);
    SetAutoHide(0, 0);
    GetPosition(0);
    SetPosition_20241056(0, 0);
    SetColor_20241296(0, 0);
    GetColor(0);
    GetIndexTable(0);
    SetIndexTable(0, 0);
    SetActive(0, 0);
    return 0;
}

// 0x16bf370
dds3HermitianTrackPoly_tag *dds3HermitianTrackPolyCreate(u32 face, u32 split) {
  u64 v5;
  u64 *v6;
  u64 *v7;
  sdfMat_t_o *v9;

  v5 = 2 * face * split + 4;
  v6 = Allocate(dds3HermitianTrackPoly_tag);
  dds3HermitianTrackPoly_tag___ctor(v6);
  v6[5] = NewSpecific(UnityEngine_Vector4, v5);
  v7 = NewSpecific(uint, v5);
  v6[2] = 0x8080808000000002LL;
  v6[6] = v7;
  *(v6 + 6) = v5;
  *(v6 + 9) = split;
  *(v6 + 28) = 0x200000000LL;
  v6[8] = 0;
  v9 = sdfMatNew();
  v6[7] = v9;
  sdfMatSetConstant(v9, 1.0);
  HTP_PrimPolyParm->attr = 0x4000;
  return v6;
}

// 0x16bf580
void dds3HermitianTrackPolyDelete(dds3HermitianTrackPoly_tag **hPoly) {
    pMeshDelete(0);
}

// 0x16bf600
void dds3HermitianTrackPolyDraw(dds3HermitianTrackPoly_tag **hPoly) {
    MeshDraw(0, (sdfVector4_t){0});
}

// 0x16c1100
void dds3HermitianTrackPolyGetVertex(dds3HermitianTrackPoly_tag **hPoly, sdfVector4_t *pVertex0, sdfVector4_t *pVertex1, s32 frame) {
  dds3HermitianTrackPoly_tag_o *v5;
  s32 v6;
  struct UnityEngine_Vector4_array *pVertex;
  s64 v9;

  v5 = *hPoly;
  v6 = (*hPoly)->current - 2 * (frame + (*hPoly)->split * (frame - 1));
  if (v6 <= 1)
    v6 = v6 + v5->point - 2;
  pVertex = v5->pVertex;
  v9 = v6;
  SDF_VU0__COPYVECTOR(pVertex0, pVertex->m_Items[v6]);
  SDF_VU0__COPYVECTOR(pVertex1, pVertex->m_Items[v9 + 1]);
}

// 0x16c1a40
void dds3HermitianTrackPolyReset(dds3HermitianTrackPoly_tag **hPoly) {
  (*hPoly)->count = 0;
  (*hPoly)->current = 2;
  (*hPoly)->abgr = -2139062144;
}

// 0x16c1a30
void dds3HermitianTrackPolySetBlend(dds3HermitianTrackPoly_tag **hPoly, u32 blend) {
  (*hPoly)->blend = blend;
}

// 0x16c11c0
void dds3HermitianTrackPolySetCurrent(dds3HermitianTrackPoly_tag **hPoly, s32 frame) {
  dds3HermitianTrackPoly_tag_o *v3;
  s32 v4;

  v3 = *hPoly;
  v4 = (*hPoly)->current - 2 * (frame + ((*hPoly)->split - 1) * (frame - 1));
  if (v4 <= 1)
    v4 = v4 + v3->point - 2;
  v3->current = v4;
}

// 0x16c1950
void dds3HermitianTrackPolySetVC(dds3HermitianTrackPoly_tag **hPoly, Eff_ModelTrackPolyABGR_t *pABGR) {
  u32 v3;
  f32 v4;
  f32 v5;
  struct System_UInt32_array *pVC;
  f32 v7;
  u64 v9;
  u32 v11;
  char *v13;
  u64 v14;
  u32 v15;

  v3 = (*hPoly)->point >> 1;
  if (v3)
  {
    v4 = v3;
    v5 = 1.0 / v4;
    pVC = (*hPoly)->pVC;
    v7 = 0.0;
    v9 = 0;
    do
    {
      v11 = effColorBlend(pABGR->e0, pABGR->s0, v7);
      v13 = pVC + 4 * v9;
      *(v13 + 8) = v11;
      v14 = v9 + 1;
      v15 = effColorBlend(pABGR->e1, pABGR->s1, v7);
      v7 = v5 + v7;
      --v3;
      v9 = v14 + 1;
      *(v13 + 9) = v15;
    }
    while (v3);
  }
}

// 0x16bfdd0
void dds3HermitianTrackPolySetVertex(dds3HermitianTrackPoly_tag **hPoly, sdfVector4_t **pVertex) {
    dds3HermitianTrackPolyGetVertex(0, 0, 0, 0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    Eff_HermitianSpline(0, 0);
    SDF_VU0__STOREVECTOR(0);
    dds3HermitianTrackPolySetVertexSub(0, 0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
}

// 0x16c0df0
void dds3HermitianTrackPolySetVertexSub(dds3HermitianTrackPoly_tag **hPoly, sdfVector4_t **pVertex) {
  struct UnityEngine_Vector4_array *v3;
  s64 current;
  s64 v10;
  dds3HermitianTrackPoly_tag_o *v12;
  struct System_UInt32_array *pVC;
  s64 v14;
  struct System_UInt32_array *v16;
  s64 v17;
  dds3HermitianTrackPoly_tag_o *v19;
  s32 point;
  struct UnityEngine_Vector4_array *v21;
  struct UnityEngine_Vector4_array *v22;
  dds3HermitianTrackPoly_tag_o *v25;
  struct System_UInt32_array *v26;
  struct System_UInt32_array *v28;
  s32 count;

  v3 = (*hPoly)->pVertex;
  current = (*hPoly)->current;
  SDF_VU0__COPYVECTOR(&v3->m_Items[current], pVertex->m_Items[0]);
  v10 = (*hPoly)->current + 1LL;
  SDF_VU0__COPYVECTOR(&v3->m_Items[v10], pVertex->m_Items[1]);
  v12 = *hPoly;
  if ((*hPoly)->blend == 12)
  {
    pVC = v12->pVC;
    v14 = v12->current;
    pVC->m_Items[v14] = v12->abgr;
    v16 = (*hPoly)->pVC;
    v17 = (*hPoly)->current;
    v16->m_Items[v17 + 1] = (*hPoly)->abgr;
    v12 = *hPoly;
  }
  v12->current += 2;
  v19 = *hPoly;
  point = (*hPoly)->point;
  if ((*hPoly)->current == point)
  {
    v21 = v19->pVertex;
    SDF_VU0__COPYVECTOR(v21->m_Items, pVertex->m_Items[0]);
    v22 = (*hPoly)->pVertex;
    SDF_VU0__COPYVECTOR(&v22->m_Items[1], pVertex->m_Items[1]);
    v25 = *hPoly;
    if ((*hPoly)->blend == 12)
    {
      v26 = v25->pVC;
      v26->m_Items[0] = v25->abgr;
      v28 = (*hPoly)->pVC;
      v28->m_Items[1] = (*hPoly)->abgr;
      v25 = *hPoly;
    }
    v25->current = 2;
    v19 = *hPoly;
    point = (*hPoly)->point;
  }
  count = v19->count;
  if (count < point - 2)
    v19->count = count + 2;
}

// 0x16c1e40
Eff_ModelTrackPoly_tag *effSwordTrackCreate(effSwordTrackParams_t *pParams) {
  u64 *v3;
  Eff_ModelTrackPolyABGR_t_o *v4;
  u32 point;
  f32 step;
  u32 v9;

  v3 = Allocate(Eff_ModelTrackPoly_tag);
  Eff_ModelTrackPoly_tag___ctor(v3);
  v4 = Allocate(Eff_ModelTrackPolyABGR_t);
  Eff_ModelTrackPolyABGR_t___ctor(v4);
  v3[3] = pParams;
  v3[4] = 0x3F80000000000000LL;
  point = pParams->point;
  step = pParams->step;
  if ((1.0 / step) >= 0.0)
    v9 = (1.0 / step);
  else
    v9 = (1.0 / step);
  v3[5] = dds3HermitianTrackPolyCreate(point, v9);
  v4->s0 = pParams->abgr;
  v4->s1 = pParams->abgr;
  v4->e0 = pParams->abgr;
  v4->e1 = pParams->abgr;
  dds3HermitianTrackPolySetVC(v3 + 5, v4);
  *(v3[5] + 16) = pParams->blend;
  return v3;
}

// 0x16c20a0
void effSwordTrackDelete(Eff_ModelTrackPoly_tag **hSwordTrack) {
  Eff_ModelTrackPoly_tag_o *v3;
  dds3HermitianTrackPoly_tag_o **p_hPoly;

  v3 = *hSwordTrack;
  p_hPoly = &v3->hPoly;
  pMeshDelete(p_hPoly);
}

// 0x16c2ee0
void effSwordTrackDraw(Eff_ModelTrackPoly_tag **hSwordTrack) {
  u64 v2;
  u32 *p_frame;
  u32 v5;
  struct effSwordTrackParams_t_o *param_dante;
  f32 v7;
  f64 v8;
  f32 v9;

  p_frame = &(*hSwordTrack)->frame;
  v5 = *p_frame;
  param_dante = (*hSwordTrack)->param_dante;
  LODWORD(v2) = param_dante->frame_s;
  v7 = *p_frame;
  v8 = v2;
  *&v8 = v8;
  if (v7 >= *&v8)
  {
    LODWORD(v8) = param_dante->frame_e;
    v9 = *&v8;
    if (v7 < v9)
    {
      effSwordTrackRecord(hSwordTrack);
    }
    effSwordTrackPolygon2DDraw(hSwordTrack);
    p_frame = &(*hSwordTrack)->frame;
    v5 = *p_frame;
  }
  *p_frame = v5 + 1;
}

// 0x16c3790
void effSwordTrackPolygon2DDraw(Eff_ModelTrackPoly_tag **hSwordTrack) {
    MeshDraw(0, (sdfVector4_t){0});
}

// 0x16c3780
void effSwordTrackPolygonDraw(Eff_ModelTrackPoly_tag **hSwordTrack) {
  ;
}

// 0x16c3600
void effSwordTrackRecord(Eff_ModelTrackPoly_tag **hSwordTrack) {
  u64 *v3;
  struct effSwordTrackParams_t_o *param_dante;
  u64 *v6;
  struct System_UInt32_array *mark;
  struct dds3ModelHandle_t_o *hModel;
  sdfModelRootNode_t_o *modelRoot;
  s32 v11;
  struct System_UInt32_array *v13;
  dds3HermitianTrackPoly_tag_o **p_hPoly;

  v3 = NewSpecific(UnityEngine_Vector4, 2u);
  param_dante = (*hSwordTrack)->param_dante;
  v6 = v3;
  hModel = param_dante->hModel;
  mark = param_dante->mark;
  modelRoot = hModel->modelRoot;
  v11 = mark->m_Items[0];
  sdfModelGetMarkPosUnity(modelRoot, v11);
  SDF_VU0__STOREVECTOR(v6 + 2);
  v13 = (*hSwordTrack)->param_dante->mark;
  sdfModelGetMarkPosUnity(hModel->modelRoot, v13->m_Items[1]);
  SDF_VU0__STOREVECTOR(v6 + 3);
  p_hPoly = &(*hSwordTrack)->hPoly;
  dds3HermitianTrackPolySetVertex(p_hPoly, v6);
}

// 0x16c22b0
void effSwordTrackReset(Eff_ModelTrackPoly_tag **hSwordTrack) {
  Eff_ModelTrackPoly_tag_o *v3;

  (*hSwordTrack)->frame = 0;
  (*hSwordTrack)->slide_par = 1.0;
  v3 = *hSwordTrack;
  v3->hPoly->count = 0;
  v3->hPoly->current = 2;
  v3->hPoly->abgr = -2139062144;
}

// 0x16c2eb0
void effSwordTrackReset2(Eff_ModelTrackPoly_tag **hSwordTrack) {
  (*hSwordTrack)->slide_par = 1.0;
  (*hSwordTrack)->hPoly->count = 0;
  (*hSwordTrack)->hPoly->current = 2;
}

// 0x16bf4b0
void pMeshDelete(dds3HermitianTrackPoly_tag **hPoly) {
  UnityEngine_Object_o *pMesh;
  UnityEngine_Object_o *gameObject;

  if (*hPoly)
  {
    pMesh = (*hPoly)->pMesh;
    if (op_Inequality(pMesh, 0, 0))
    {
      gameObject = get_gameObject((*hPoly)->pMesh, 0);
      Destroy_27360000(gameObject);
      (*hPoly)->pMesh = 0;
    }
  }
}
