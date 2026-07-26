#include "types.h"

typedef struct XRD773Unity_CommonMesh XRD773Unity_CommonMesh;
typedef struct XRD773Unity_GraphicManager XRD773Unity_GraphicManager;
typedef struct XRD773Unity_GraphicManager_CommonObject XRD773Unity_GraphicManager_CommonObject;
typedef struct dds3EffectPCPData_t dds3EffectPCPData_t;
typedef struct dds3ScatterPolyListTexResource_tag dds3ScatterPolyListTexResource_tag;
typedef struct dds3ScatterPolyList_tag dds3ScatterPolyList_tag;
typedef struct dds3WhirlwindPolyList_tag dds3WhirlwindPolyList_tag;
typedef struct effPCPHamaCardScatterParam_t effPCPHamaCardScatterParam_t;
typedef struct effPCPHamaCardScatter_tag effPCPHamaCardScatter_tag;
typedef struct effPCPHamaCardSphereParam_t effPCPHamaCardSphereParam_t;
typedef struct effPCPHamaCardSphere_tag effPCPHamaCardSphere_tag;
typedef struct effPCPHamaCardSpiralParam_t effPCPHamaCardSpiralParam_t;
typedef struct effPCPHamaCardSpiral_tag effPCPHamaCardSpiral_tag;
typedef struct effPCPScatter_effPCPScatterJob effPCPScatter_effPCPScatterJob;
typedef struct effPCPWhirlwind2PolyParam_t effPCPWhirlwind2PolyParam_t;
typedef struct effPCPWhirlwind2Poly_tag effPCPWhirlwind2Poly_tag;
typedef struct effPCPWhirlwind3PolyParam_t effPCPWhirlwind3PolyParam_t;
typedef struct effPCPWhirlwind3Poly_tag effPCPWhirlwind3Poly_tag;
typedef struct effPCPWhirlwindPolyParam_t effPCPWhirlwindPolyParam_t;
typedef struct effPCPWhirlwindPoly_tag effPCPWhirlwindPoly_tag;
typedef struct effPCPWwSpherePolyParam_t effPCPWwSpherePolyParam_t;
typedef struct effPCPWwSpherePoly_tag effPCPWwSpherePoly_tag;
typedef struct effPartHandle_t effPartHandle_t;
typedef struct sdf3DPrimPolyParm_t sdf3DPrimPolyParm_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfMat_t sdfMat_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

struct effPCPScatter_effPCPScatterJob {
    sdfMatrix4_t matrix;
    void pos;
    void uvpos;
};

static sdfVector2_t dds3ScatterPolyListDraw_uv[24];
static u32 ScatterFaceIndex[60];
static sdf3DPrimPolyParm_t *SPL_PrimPolyParm;
static bool e634_flag;
static dds3WhirlwindPolyList_tag *effPCPScatterJob_hPoly;
static sdfMatrix4_t effPCPScatterJob_matrix;
static u32 WhirlwindFaceIndex[72];
static sdf3DPrimPolyParm_t *WPL_PrimPolyParm;

f32 DDS3EFFECT_RAND_F(void);
f32 DDS3EFFECT_RAND_FA(f32 r);
u32 DDS3EFFECT_RAND_I(void);
f32 DDS3EFFECT_RAND_PM(void);
sdfColor_t **GetColor(XRD773Unity_CommonMesh *this);
s32 **GetIndexTable(XRD773Unity_CommonMesh *this);
XRD773Unity_CommonMesh *GetMesh(XRD773Unity_GraphicManager *this, s32 index, bool outlinechk);
sdfVector3_t **GetPosition(XRD773Unity_CommonMesh *this);
s32 GetTmxIndex(u8 **bData, s32 bPos);
sdfVector2_t **GetUvTable(XRD773Unity_CommonMesh *this);
void MultMatrixNoArg(void);
void MultMatrixRevNoArg(void);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__ADDVECTOR_A_C(void);
void SDF_VU0__APPLYMATRIX(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__COPYVECTOR_A_TO_C(void);
void SDF_VU0__LD_APPLYMATRIX(sdfVector4_t *vec);
void SDF_VU0__LOADMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__LOADMATRIX_B(sdfMatrix4_t *aMatrix);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_C(sdfVector4_t p);
void SDF_VU0__MULVECTOR(void);
void SDF_VU0__NORMALIZE(void);
void SDF_VU0__OUTERPRODUCT(void);
void SDF_VU0__STOREIDENTITY(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
void SetActive(XRD773Unity_GraphicManager_CommonObject *this, bool act);
void SetAutoHide(XRD773Unity_GraphicManager_CommonObject *this, bool act);
void SetColor_20241296(XRD773Unity_CommonMesh *this, sdfColor_t **col);
void SetIndexTable(XRD773Unity_CommonMesh *this, s32 **idx);
void SetMatTexture(XRD773Unity_CommonMesh *this, void *texture);
void SetPosition_20241056(XRD773Unity_CommonMesh *this, sdfVector3_t **pos);
void SetRotateMatrixAxis(f32 aAngle, sdfVector4_t aAxis);
void SetRotateMatrixX(f32 aAngle);
void SetRotateMatrixXYZ(f32 **aAngles);
void SetRotateMatrixY_B(f32 aAngle);
void SetUvTable_20243232(XRD773Unity_CommonMesh *this, sdfVector2_t **pos);
void *billGetTexture(s32 index);
void *dds3EffectPCPDataGetDataUnityOffSet(void *hData, s32 offset, s32 type);
void dds3EffectPCPData_t__pCopy(dds3EffectPCPData_t *this, u8 **bytedata, s32 *pos);
effPartHandle_t *dds3EffectPartCopy(effPartHandle_t **hEffPartSrc);
effPartHandle_t *dds3EffectPartCreate(u16 type, void *pData);
void dds3EffectPartDelete(effPartHandle_t **hEffPart);
void dds3EffectPartDraw(effPartHandle_t **hEffPart);
void dds3EffectPartSetColor(effPartHandle_t **hEffPart, u32 abgr);
void dds3EffectPartSetPosition(effPartHandle_t **hEffPart, sdfVector4_t pPos);
dds3ScatterPolyList_tag *dds3ScatterPolyListCreate(u32 face);
void dds3ScatterPolyListDelete(dds3ScatterPolyList_tag *hPoly);
void dds3ScatterPolyListDraw(dds3ScatterPolyList_tag *hPoly);
void dds3ScatterPolyListSetTex(dds3ScatterPolyList_tag **hPoly, void *pTex);
dds3WhirlwindPolyList_tag *dds3WhirlwindPolyListCreate(u32 number, u32 face);
void dds3WhirlwindPolyListDelete(dds3WhirlwindPolyList_tag *hPoly);
void dds3WhirlwindPolyListDraw(dds3WhirlwindPolyList_tag **hPoly, char *callname);
bool effBTLSkillCheckRun2(u32 skillid);
u32 effColorBlend(u32 abgr0, u32 abgr1, f32 rate);
u32 effColorMultiply(u32 abgr0, u32 abgr1);
sdfColor_t effGetBlendColor(u32 icol);
sdfColor_t effGetVertexColorT(u32 icol, sdfColor_t blend_col);
effPCPHamaCardScatter_tag *effPCPHamaCardScatterCreate(effPCPHamaCardScatterParam_t *pParam, void *pTex, void *pData);
void effPCPHamaCardScatterParam_t__pClone(effPCPHamaCardScatterParam_t *this, effPCPHamaCardScatterParam_t **param);
void effPCPHamaCardScatterPartInit(effPCPHamaCardScatter_tag **pHCardScatter, s32 number);
effPCPHamaCardSphere_tag *effPCPHamaCardSphereCreate(effPCPHamaCardSphereParam_t *pParam, void *pTex, void *pData);
void effPCPHamaCardSphereParam_t__pClone(effPCPHamaCardSphereParam_t *this, effPCPHamaCardSphereParam_t **param);
void effPCPHamaCardSpherePartInit(effPCPHamaCardSphere_tag **pHCardSphere, s32 number);
effPCPHamaCardSpiral_tag *effPCPHamaCardSpiralCreate(effPCPHamaCardSpiralParam_t *pParam, void *pTex, void *pData);
void effPCPHamaCardSpiralParam_t__pClone(effPCPHamaCardSpiralParam_t *this, effPCPHamaCardSpiralParam_t **param);
void effPCPHamaCardSpiralPartInit(effPCPHamaCardSpiral_tag **pHCardSpiral, s32 number);
effPCPWhirlwind2Poly_tag *effPCPWhirlwind2PolyCreate(effPCPWhirlwind2PolyParam_t *pParam, void *pTex);
void effPCPWhirlwind2PolyParam_t__pClone(effPCPWhirlwind2PolyParam_t *this, effPCPWhirlwind2PolyParam_t **param);
void effPCPWhirlwind2PolyPartInit(effPCPWhirlwind2Poly_tag **pWhirlwind2Poly, s32 index);
void effPCPWhirlwind2PolyPartMove(effPCPWhirlwind2Poly_tag **pWhirlwind2Poly, s32 index);
effPCPWhirlwind3Poly_tag *effPCPWhirlwind3PolyCreate(effPCPWhirlwind3PolyParam_t *pParam, void *pTex);
void effPCPWhirlwind3PolyParam_t__pClone(effPCPWhirlwind3PolyParam_t *this, effPCPWhirlwind3PolyParam_t **param);
void effPCPWhirlwind3PolyPartInit(effPCPWhirlwind3Poly_tag **pWhirlwind3Poly, s32 index);
void effPCPWhirlwind3PolyPartMove(effPCPWhirlwind3Poly_tag **pWhirlwind3Poly, s32 index);
effPCPWhirlwindPoly_tag *effPCPWhirlwindPolyCreate(effPCPWhirlwindPolyParam_t *pParam, void *pTex);
void effPCPWhirlwindPolyParam_t__pClone(effPCPWhirlwindPolyParam_t *this, effPCPWhirlwindPolyParam_t **param);
void effPCPWhirlwindPolyPartInit(effPCPWhirlwindPoly_tag **pWhirlwindPoly, s32 index);
void effPCPWhirlwindPolyPartMove(effPCPWhirlwindPoly_tag **pWhirlwindPoly, s32 index);
effPCPWwSpherePoly_tag *effPCPWwSpherePolyCreate(effPCPWwSpherePolyParam_t *pParam, void *pTex);
void effPCPWwSpherePolyParam_t__pClone(effPCPWwSpherePolyParam_t *this, effPCPWwSpherePolyParam_t **param);
void effPCPWwSpherePolyPartInit(effPCPWwSpherePoly_tag **pWwSpherePoly, s32 index);
void effPCPWwSpherePolyPartMove(effPCPWwSpherePoly_tag **pWwSpherePoly, s32 index);
f32 sdfAtan(f32 aX);
f32 sdfCos(f32 aRadius);
f32 sdfFabs(f32 c);
sdfMat_t *sdfMatNew(void);
void sdfMatSetConstant(sdfMat_t *aMat, f32 aRatio);
f32 sdfSin(f32 aRadius);
sdfTexHandle_t *sdfTexSet(void *aTex);

// 0x176ada0
void Unity_Jobs_IJobParallelFor_Execute(effPCPScatter_effPCPScatterJob *this, s32 p) {
  JUMPOUT(0x176AC40);
}

// 0x175d0c0
void dds3ScatterPolyListCopyTex(dds3ScatterPolyList_tag **hPoly, dds3ScatterPolyList_tag *hPolySrc) {
  dds3ScatterPolyList_tag_o *v5;

  v5 = *hPoly;
  v5->hTexRes = 0;
  (*hPoly)->pTexture = hPolySrc->pTexture;
}

// 0x175c280
dds3ScatterPolyList_tag *dds3ScatterPolyListCreate(u32 face) {
  u64 v3;
  u64 *v4;
  u64 *v5;
  sdfMat_t_o *v7;

  v3 = 6 * face;
  v4 = Allocate(dds3ScatterPolyList_tag);
  _ctor(v4, 0);
  v4[6] = NewSpecific(UnityEngine_Vector4, v3);
  v5 = NewSpecific(uint, v3);
  v4[9] = 0;
  v4[10] = 0;
  v4[4] = 0x8080808000000001LL;
  v4[7] = v5;
  *(v4 + 10) = v3;
  *(v4 + 11) = 1065353216;
  *(v4 + 22) = 1;
  v7 = sdfMatNew();
  v4[8] = v7;
  sdfMatSetConstant(v7, 1.0);
  SPL_PrimPolyParm->attr = 0x4000;
  return v4;
}

// 0x175c3b0
void dds3ScatterPolyListDelete(dds3ScatterPolyList_tag *hPoly) {
  struct dds3ScatterPolyListTexResource_tag_o *hTexRes;
  struct XRD773Unity_CommonMesh_array *pMesh;
  il2cpp_array_size_t max_length;
  s64 v6;
  u64 v7;
  UnityEngine_Object_o *v9;
  struct XRD773Unity_CommonMesh_array *v10;
  UnityEngine_Object_o *gameObject;
  struct XRD773Unity_CommonMesh_array *v14;
  s64 v16;

  hTexRes = hPoly->hTexRes;
  if (hTexRes)
  {
    --hTexRes->count;
  }
  pMesh = hPoly->pMesh;
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
          v10 = hPoly->pMesh;
          gameObject = get_gameObject(*(&v10->obj.klass + v6), 0);
          Destroy_27360000(gameObject);
          v14 = hPoly->pMesh;
          *(&v14->obj.klass + v6) = 0;
        }
        pMesh = hPoly->pMesh;
        LODWORD(max_length) = pMesh->max_length;
        v16 = v6 - 3;
        ++v6;
      }
      while (v16 < max_length);
    }
    hPoly->pMesh = 0;
  }
}

// 0x175c540
void dds3ScatterPolyListDraw(dds3ScatterPolyList_tag *hPoly) {
    GetMesh(0, 0, 0);
    SetAutoHide(0, 0);
    effGetBlendColor(0);
    GetPosition(0);
    SetPosition_20241056(0, 0);
    SetColor_20241296(0, 0);
    SetUvTable_20243232(0, 0);
    SetIndexTable(0, 0);
    GetColor(0);
    GetUvTable(0);
    effGetVertexColorT(0, (sdfColor_t){0});
    GetIndexTable(0);
    SetMatTexture(0, 0);
    SetActive(0, 0);
}

// 0x175ceb0
u32 dds3ScatterPolyListGetVC(dds3ScatterPolyList_tag *hPoly, s32 index) {
  struct System_UInt32_array *pVC;

  pVC = hPoly->pVC;
  return pVC->m_Items[6 * index];
}

// 0x175ce60
sdfVector4_t dds3ScatterPolyListGetVertex(dds3ScatterPolyList_tag *hPoly, s32 index) {
  struct UnityEngine_Vector4_array *pVertex;
  f32 *v5;
  UnityEngine_Vector4_o result;

  pVertex = hPoly->pVertex;
  v5 = (pVertex + 96 * index);
  result.x = v5[8];
  result.y = v5[9];
  result.z = v5[10];
  result.w = v5[11];
  return result;
}

// 0x175cf00
void dds3ScatterPolyListSetTex(dds3ScatterPolyList_tag **hPoly, void *pTex) {
    sdfTexSet(0);
}

// 0x175c270
dds3ScatterPolyListTexResource_tag *dds3ScatterPolyListTexResourceCopy(dds3ScatterPolyListTexResource_tag *hSplTexResSrc) {
  return 0;
}

// 0x175c1b0
dds3ScatterPolyListTexResource_tag *dds3ScatterPolyListTexResourceCreate(void *pTex) {
  dds3ScatterPolyListTexResource_tag_o *v3;

  if (!pTex)
    return 0;
  v3 = Allocate(dds3ScatterPolyListTexResource_tag);
  _ctor(v3, 0);
  v3->hTex = sdfTexSet(pTex);
  v3->count = 1;
  return v3;
}

// 0x175c260
void dds3ScatterPolyListTexResourceDelete(dds3ScatterPolyListTexResource_tag *hSplTexRes) {
  --hSplTexRes->count;
}

// 0x17639e0
void dds3WhirlwindPolyListCopyTex(dds3WhirlwindPolyList_tag **hPoly, dds3WhirlwindPolyList_tag *hPolySrc) {
  (*hPoly)->pTexture = hPolySrc->pTexture;
}

// 0x1762620
dds3WhirlwindPolyList_tag *dds3WhirlwindPolyListCreate(u32 number, u32 face) {
  u32 v5;
  signed s32 v6;
  u64 *v7;
  u64 *v8;
  u32 v10;
  f32 v11;
  u64 v12;
  s32 *v13;
  f32 v14;
  u64 v15;
  s32 *v16;
  u8 v22;
  u8 v23;
  s32 v24;
  u64 v25;
  u64 v26;
  u64 v27;
  u64 v28;
  s32 v29;
  u64 v31;
  u64 v32;
  u64 v34;

  v5 = 2 * face;
  v6 = 2 * face + 2;
  v7 = Allocate(dds3WhirlwindPolyList_tag);
  _ctor(v7, 0);
  v7[15] = NewSpecific(UnityEngine_Vector4, v6 * number);
  v7[16] = NewSpecific(UnityEngine_Vector2, v6 * number);
  v7[17] = NewSpecific(uint, v5 + 2);
  v8 = NewSpecific(uint, number);
  v7[20] = 0;
  v7[21] = 0;
  v7[12] = 0x8080808000000001LL;
  v7[18] = v8;
  *(v7 + 26) = number;
  *(v7 + 27) = v6;
  *(v7 + 28) = 1065353216;
  if (v6)
  {
    v10 = v6 >> 2;
    if ((v6 >> 2) <= 1)
    {
      if (v6 >= 1)
      {
        v31 = 0;
        do
        {
          v32 = v7[17];
          v34 = v32 + 4 * v31++;
          *(v34 + 32) = -2139062144;
        }
        while (v6 != v31);
      }
    }
    else
    {
      v11 = v10;
      v12 = v7[17];
      v13 = (v12 + 4LL * v5 + 36);
      v14 = 0.0;
      v15 = 0;
      v16 = (v12 + 32);
      do
      {
        v22 = vcvts_n_s32_f32(v14, 7u);
        v23 = vcvts_n_u32_f32(v14, 7u);
        if ((v14 * 128.0) >= 0.0)
          v22 = v23;
        v24 = (v22 << 24) | 0x808080;
        v25 = *(v12 + 24);
        *v16 = v24;
        v26 = v15 + 1;
        v27 = v26 - 1;
        v16[1] = v24;
        *(v13 - 1) = *v16;
        v28 = *(v12 + 24);
        v29 = *v16;
        v14 = (1.0 / v11) + v14;
        --v10;
        v5 -= 2;
        v16 += 2;
        v15 = v27 + 2;
        *v13 = v29;
        v13 -= 2;
      }
      while (v10);
    }
    WPL_PrimPolyParm->attr = 0x4000;
  }
  return v7;
}

// 0x1762980
void dds3WhirlwindPolyListDelete(dds3WhirlwindPolyList_tag *hPoly) {
  struct dds3ScatterPolyListTexResource_tag_o *hTexRes;
  struct XRD773Unity_CommonMesh_array *pMesh;
  il2cpp_array_size_t max_length;
  s64 v6;
  u64 v7;
  UnityEngine_Object_o *v9;
  struct XRD773Unity_CommonMesh_array *v10;
  UnityEngine_Object_o *gameObject;
  struct XRD773Unity_CommonMesh_array *v14;
  s64 v16;

  hTexRes = hPoly->hTexRes;
  if (hTexRes)
  {
    --hTexRes->count;
  }
  pMesh = hPoly->pMesh;
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
          v10 = hPoly->pMesh;
          gameObject = get_gameObject(*(&v10->obj.klass + v6), 0);
          Destroy_27360000(gameObject);
          v14 = hPoly->pMesh;
          *(&v14->obj.klass + v6) = 0;
        }
        pMesh = hPoly->pMesh;
        LODWORD(max_length) = pMesh->max_length;
        v16 = v6 - 3;
        ++v6;
      }
      while (v16 < max_length);
    }
    hPoly->pMesh = 0;
  }
}

// 0x1762b10
void dds3WhirlwindPolyListDraw(dds3WhirlwindPolyList_tag **hPoly, char *callname) {
    GetMesh(0, 0, 0);
    SetAutoHide(0, 0);
    effGetBlendColor(0);
    GetPosition(0);
    SetPosition_20241056(0, 0);
    SetColor_20241296(0, 0);
    SetUvTable_20243232(0, 0);
    SetIndexTable(0, 0);
    GetColor(0);
    GetUvTable(0);
    GetIndexTable(0);
    effGetVertexColorT(0, (sdfColor_t){0});
    SetMatTexture(0, 0);
    SetActive(0, 0);
}

// 0x1763770
u32 dds3WhirlwindPolyListGetABGR(dds3WhirlwindPolyList_tag *hPoly, s32 index) {
  struct System_UInt32_array *pABGR;

  pABGR = hPoly->pABGR;
  return pABGR->m_Items[index];
}

// 0x1763720
sdfVector2_t dds3WhirlwindPolyListGetUV(dds3WhirlwindPolyList_tag *hPoly, s32 index) {
  struct UnityEngine_Vector2_array *pUV;
  s32 v4;
  f32 *v6;
  UnityEngine_Vector2_o result;

  pUV = hPoly->pUV;
  v4 = hPoly->point * index;
  v6 = (&pUV->obj.klass + v4);
  result.x = v6[8];
  result.y = v6[9];
  return result;
}

// 0x17636d0
sdfVector4_t dds3WhirlwindPolyListGetVertex(dds3WhirlwindPolyList_tag *hPoly, s32 index) {
  struct UnityEngine_Vector4_array *pVertex;
  s32 v4;
  f32 *v6;
  UnityEngine_Vector4_o result;

  pVertex = hPoly->pVertex;
  v4 = hPoly->point * index;
  v6 = (&pVertex->obj + v4);
  result.x = v6[8];
  result.y = v6[9];
  result.z = v6[10];
  result.w = v6[11];
  return result;
}

// 0x17637c0
void dds3WhirlwindPolyListSetRotateMatrix(dds3WhirlwindPolyList_tag **hPoly, sdfMatrix4_t *pMatrix) {
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
  SDF_VU0__STOREMATRIX(&(*hPoly)->matrix, 0);
}

// 0x1763820
void dds3WhirlwindPolyListSetTex(dds3WhirlwindPolyList_tag **hPoly, void *pTex) {
    sdfTexSet(0);
}

// 0x1761510
effPCPHamaCardScatter_tag *effPCPHamaCardScatterCopy(effPCPHamaCardScatter_tag *pHCardScatterSrc) {
  effPCPHamaCardScatterParam_t_o *param;
  effPCPHamaCardScatter_tag_o *v5;
  struct dds3ScatterPolyList_tag_o *hPoly;
  effPCPHamaCardScatter_tag_o *v8;
  struct dds3ScatterPolyList_tag_o *v9;
  struct effPCPHamaCardScatterParam_t_o *v10;
  u32 attach_i;
  u32 v12;
  s64 v13;
  u64 *v14;
  u64 v16;
  u32 *pAttach;
  struct effPartHandle_t_array *v19;
  s64 *v21;
  s64 *v22;
  u32 *v24;

  param = pHCardScatterSrc->param;
  v5 = effPCPHamaCardScatterCreate(param, 0, 0);
  hPoly = pHCardScatterSrc->hPoly;
  v8 = v5;
  v9 = v8->hPoly;
  v9->hTexRes = 0;
  v8->hPoly->pTexture = hPoly->pTexture;
  v10 = v8->param;
  if (v10->attach)
  {
    attach_i = v10->attach_i;
    if (!attach_i)
    {
      v10->attach_i = 1;
      v10 = v8->param;
      attach_i = v10->attach_i;
    }
    v12 = v10->number / attach_i;
    v8->AttachNum = v12;
    if (v10->number % v10->attach_i)
      v8->AttachNum = ++v12;
    v13 = v12;
    v8->pAttach = NewSpecific(effPartHandle_t, v12);
    v14 = Allocate(sdfMemHandle_t);
    sdfMemHandle_t___ctor(v14);
    v8->hAttachMem = v14;
    if (v12)
    {
      v16 = 0;
      do
      {
        pAttach = v8->pAttach;
        v19 = pHCardScatterSrc->pAttach;
        else        v21 = dds3EffectPartCopy(v19->m_Items, 0, 0);
        v22 = v21;
        v24 = &pAttach[2 * v16++];
        *(v24 + 4) = v22;
      }
      while (v13 != v16);
    }
  }
  return v8;
}

// 0x1760cc0
effPCPHamaCardScatter_tag *effPCPHamaCardScatterCreate(effPCPHamaCardScatterParam_t *pParam, void *pTex, void *pData) {
  u64 *v7;
  u64 *v8;
  u64 *v9;
  u64 *v10;
  u32 number;
  dds3ScatterPolyList_tag_o *v13;
  u64 v16;
  u32 v17;
  u32 v18;
  s64 v19;
  u64 *v20;
  u64 v22;
  s64 *v23;
  s64 *v25;
  s64 v28;
  s64 v29;
  u64 v31;
  s64 *v33;
  s64 *v34;
  u64 v36;
  s64 v37;
  u32 v38;
  u64 i;
  u32 *v41;
  u64 *v42;
  u64 v45;
  s64 v47;
  u32 v48;

  v7 = Allocate(effPCPHamaCardScatter_tag);
  _ctor(v7, 0);
  v8 = Allocate(effPCPHamaCardScatterParam_t);
  effPCPHamaCardScatterParam_t___ctor(v8);
  v9 = v7 + 2;
  v7[2] = v8;
  effPCPHamaCardScatterParam_t__pClone(pParam, v7 + 2);
  v10 = NewSpecific(effPCPHamaCardScatterPart_tag, pParam->number);
  v7[9] = 0;
  v7[6] = 0;
  v7[8] = 0;
  v7[3] = v10;
  v7[4] = 0x808080803F800000LL;
  number = pParam->number;
  v13 = dds3ScatterPolyListCreate(number);
  v7[5] = v13;
  v13->blend = pParam->blend;
  if (pTex)
  {
    dds3ScatterPolyListSetTex(v7 + 5, pTex);
  }
  if (pData)
  {
    v16 = *v9;
    if (*(*v9 + 80))
    {
      v17 = *(v16 + 88);
      if (!v17)
      {
        *(v16 + 88) = 1;
        v16 = *v9;
        v17 = *(*v9 + 88);
      }
      v18 = *(v16 + 48) / v17;
      *(v7 + 14) = v18;
      if (*(v16 + 48) % *(v16 + 88))
        *(v7 + 14) = ++v18;
      v19 = v18;
      v7[8] = NewSpecific(effPartHandle_t, v18);
      v20 = Allocate(sdfMemHandle_t);
      sdfMemHandle_t___ctor(v20);
      v7[9] = v20;
      v22 = v7[8];
      v23 = dds3EffectPartCreate(6u, pData, 0, 0);
      v25 = v23;
      *(v22 + 32) = v25;
      if (v19 >= 2)
      {
        v28 = 0;
        v29 = v19 - 1;
        do
        {
          v31 = v7[8];
          else          v33 = dds3EffectPartCopy((v31 + 32), 0, 0);
          v34 = v33;
          v36 = v31 + 8 * v28++;
          *(v36 + 40) = v34;
        }
        while (v29 != v28);
      }
    }
  }
  v37 = *(*v9 + 48);
  if (*(*v9 + 52) <= 1)
    v38 = 1;
  else
    v38 = *(*v9 + 52);
  if (v37)
  {
    for (i = 0; i != v37; ++i)
    {
      v41 = v7[3];
      v42 = Allocate(effPCPHamaCardScatterPart_tag);
      _ctor(v42, 0);
      *&v41[2 * i + 8] = v42;
      v45 = v7[3];
      v47 = *(v45 + 8 * i + 32);
      v48 = DDS3EFFECT_RAND_I();
      *(v47 + 16) = v48 / v38 * v38 - v48;
    }
  }
  return v7;
}

// 0x1761110
effPCPHamaCardScatter_tag *effPCPHamaCardScatterCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    GetTmxIndex(0, 0);
    billGetTexture(0);
    effPCPHamaCardScatterCreate(0, 0, 0);
    return 0;
}

// 0x1761760
void effPCPHamaCardScatterDelete(void **hData) {
    dds3EffectPartDelete(0);
    dds3ScatterPolyListDelete(0);
}

// 0x1761ac0
void effPCPHamaCardScatterDraw(void **hData) {
    effColorBlend(0, 0, 0);
    sdfAtan(0);
    sdfSin(0);
    sdfCos(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__MULVECTOR();
    SDF_VU0__ADDVECTOR_A_C();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    sdfFabs(0);
    effPCPHamaCardScatterPartInit(0, 0);
    dds3EffectPartSetColor(0, 0);
    dds3EffectPartSetPosition(0, (sdfVector4_t){0});
    dds3EffectPartDraw(0);
    dds3ScatterPolyListDraw(0);
}

// 0x1761910
void effPCPHamaCardScatterPartInit(effPCPHamaCardScatter_tag **pHCardScatter, s32 number) {
    DDS3EFFECT_RAND_F();
    DDS3EFFECT_RAND_PM();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
}

// 0x1762600
void effPCPHamaCardScatterSetColor(effPCPHamaCardScatter_tag **pHCardScatter, u32 abgr) {
  (*pHCardScatter)->abgr = abgr;
}

// 0x17625e0
void effPCPHamaCardScatterSetPosition(effPCPHamaCardScatter_tag **pHCardScatter, sdfVector4_t pPos) {
  SDF_VU0__COPYVECTOR(&(*pHCardScatter)->param->pos, pPos, 0);
}

// 0x1762610
void effPCPHamaCardScatterSetScale(effPCPHamaCardScatter_tag **pHCardScatter, f32 scale) {
  ;
}

// 0x175f710
effPCPHamaCardSphere_tag *effPCPHamaCardSphereCopy(void **hData, s32 bPos, bool tbldata) {
    effPCPHamaCardSphereCreate(0, 0, 0);
    dds3EffectPartCopy(0);
    return 0;
}

// 0x175eec0
effPCPHamaCardSphere_tag *effPCPHamaCardSphereCreate(effPCPHamaCardSphereParam_t *pParam, void *pTex, void *pData) {
  u64 *v7;
  u64 *v8;
  u64 *v9;
  u64 *v10;
  u32 number;
  dds3ScatterPolyList_tag_o *v13;
  u64 v16;
  u32 v17;
  u32 v18;
  s64 v19;
  u64 *v20;
  u64 v22;
  s64 *v23;
  s64 *v25;
  s64 v28;
  s64 v29;
  u64 v31;
  s64 *v33;
  s64 *v34;
  u64 v36;
  s64 v37;
  u32 v38;
  u64 i;
  u32 *v41;
  u64 *v42;
  u64 v45;
  s64 v47;
  u32 v48;

  v7 = Allocate(effPCPHamaCardSphere_tag);
  _ctor(v7, 0);
  v8 = Allocate(effPCPHamaCardSphereParam_t);
  effPCPHamaCardSphereParam_t___ctor(v8);
  v9 = v7 + 2;
  v7[2] = v8;
  effPCPHamaCardSphereParam_t__pClone(pParam, v7 + 2);
  v10 = NewSpecific(effPCPHamaCardSpherePart_tag, pParam->number);
  v7[9] = 0;
  v7[6] = 0;
  v7[8] = 0;
  v7[3] = v10;
  v7[4] = 0x808080803F800000LL;
  number = pParam->number;
  v13 = dds3ScatterPolyListCreate(number);
  v7[5] = v13;
  v13->blend = pParam->blend;
  if (pTex)
  {
    dds3ScatterPolyListSetTex(v7 + 5, pTex);
  }
  if (pData)
  {
    v16 = *v9;
    if (*(*v9 + 104))
    {
      v17 = *(v16 + 112);
      if (!v17)
      {
        *(v16 + 112) = 1;
        v16 = *v9;
        v17 = *(*v9 + 112);
      }
      v18 = *(v16 + 48) / v17;
      *(v7 + 14) = v18;
      if (*(v16 + 48) % *(v16 + 112))
        *(v7 + 14) = ++v18;
      v19 = v18;
      v7[8] = NewSpecific(effPartHandle_t, v18);
      v20 = Allocate(sdfMemHandle_t);
      sdfMemHandle_t___ctor(v20);
      v7[9] = v20;
      v22 = v7[8];
      v23 = dds3EffectPartCreate(6u, pData, 0, 0);
      v25 = v23;
      *(v22 + 32) = v25;
      if (v19 >= 2)
      {
        v28 = 0;
        v29 = v19 - 1;
        do
        {
          v31 = v7[8];
          else          v33 = dds3EffectPartCopy((v31 + 32), 0, 0);
          v34 = v33;
          v36 = v31 + 8 * v28++;
          *(v36 + 40) = v34;
        }
        while (v29 != v28);
      }
    }
  }
  v37 = *(*v9 + 48);
  if (*(*v9 + 52) <= 1)
    v38 = 1;
  else
    v38 = *(*v9 + 52);
  if (v37)
  {
    for (i = 0; i != v37; ++i)
    {
      v41 = v7[3];
      v42 = Allocate(effPCPHamaCardSpherePart_tag);
      _ctor(v42, 0);
      *&v41[2 * i + 8] = v42;
      v45 = v7[3];
      v47 = *(v45 + 8 * i + 32);
      v48 = DDS3EFFECT_RAND_I();
      *(v47 + 16) = v48 / v38 * v38 - v48;
    }
  }
  return v7;
}

// 0x175f310
effPCPHamaCardSphere_tag *effPCPHamaCardSphereCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    GetTmxIndex(0, 0);
    billGetTexture(0);
    effPCPHamaCardSphereCreate(0, 0, 0);
    return 0;
}

// 0x175f9f0
void effPCPHamaCardSphereDelete(void **hData) {
    dds3EffectPartDelete(0);
    dds3ScatterPolyListDelete(0);
}

// 0x175fdb0
void effPCPHamaCardSphereDraw(void **hData) {
    effColorBlend(0, 0, 0);
    SetRotateMatrixAxis(0, (sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__COPYVECTOR_A_TO_C();
    sdfAtan(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__MULVECTOR();
    SDF_VU0__ADDVECTOR_A_C();
    SDF_VU0__OUTERPRODUCT();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    effPCPHamaCardSpherePartInit(0, 0);
    dds3EffectPartSetColor(0, 0);
    dds3EffectPartSetPosition(0, (sdfVector4_t){0});
    dds3EffectPartDraw(0);
    dds3ScatterPolyListDraw(0);
}

// 0x175fba0
void effPCPHamaCardSpherePartInit(effPCPHamaCardSphere_tag **pHCardSphere, s32 number) {
    DDS3EFFECT_RAND_F();
    DDS3EFFECT_RAND_FA(0);
    DDS3EFFECT_RAND_PM();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
}

// 0x1760ac0
void effPCPHamaCardSphereSetColor(void **hData, u32 abgr) {
}

// 0x17609a0
void effPCPHamaCardSphereSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1760bb0
void effPCPHamaCardSphereSetScale(void **hData, f32 scale) {
}

// 0x175da60
effPCPHamaCardSpiral_tag *effPCPHamaCardSpiralCopy(void **hData, s32 bPos, bool tbldata) {
    effPCPHamaCardSpiralCreate(0, 0, 0);
    dds3EffectPartCopy(0);
    return 0;
}

// 0x175d140
effPCPHamaCardSpiral_tag *effPCPHamaCardSpiralCreate(effPCPHamaCardSpiralParam_t *pParam, void *pTex, void *pData) {
    effPCPHamaCardSpiralParam_t__pClone(0, 0);
    dds3ScatterPolyListCreate(0);
    dds3ScatterPolyListSetTex(0, 0);
    dds3EffectPartCreate(0, 0);
    dds3EffectPartCopy(0);
    DDS3EFFECT_RAND_I();
    return 0;
}

// 0x175d660
effPCPHamaCardSpiral_tag *effPCPHamaCardSpiralCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    GetTmxIndex(0, 0);
    billGetTexture(0);
    effPCPHamaCardSpiralCreate(0, 0, 0);
    return 0;
}

// 0x175dd40
void effPCPHamaCardSpiralDelete(void **hData) {
    dds3EffectPartDelete(0);
    dds3ScatterPolyListDelete(0);
}

// 0x175e080
void effPCPHamaCardSpiralDraw(void **hData) {
    effColorBlend(0, 0, 0);
    sdfCos(0);
    sdfSin(0);
    SDF_VU0__LOADVECTOR_C((sdfVector4_t){0});
    sdfAtan(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__MULVECTOR();
    SDF_VU0__ADDVECTOR_A_C();
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__OUTERPRODUCT();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    effPCPHamaCardSpiralPartInit(0, 0);
    dds3EffectPartSetColor(0, 0);
    dds3EffectPartSetPosition(0, (sdfVector4_t){0});
    dds3EffectPartDraw(0);
    dds3ScatterPolyListDraw(0);
}

// 0x175def0
void effPCPHamaCardSpiralPartInit(effPCPHamaCardSpiral_tag **pHCardSpiral, s32 number) {
  struct effPCPHamaCardSpiralPart_tag_array *pPart;
  s64 v6;
  Il2CppClass **v8;
  u32 simu_num;
  f32 v10;
  f32 v11;
  Il2CppClass *v12;
  struct effPCPHamaCardSpiralParam_t_o *param;
  f32 radius_s;
  struct effPCPHamaCardSpiralParam_t_o *v15;
  f32 radius_e;
  struct effPCPHamaCardSpiralParam_t_o *v17;
  f32 up_s;

  pPart = (*pHCardSpiral)->pPart;
  v6 = number;
  v8 = &pPart->obj.klass + number;
  if ((*pHCardSpiral)->param->simu_num)
    simu_num = (*pHCardSpiral)->param->simu_num;
  else
    simu_num = 1;
  v10 = simu_num;
  v11 = 6.2832 / v10;
  v12 = v8[4];
  *(&v12->_1.byval_arg.data + 1) = ((v11 * 0.5) * DDS3EFFECT_RAND_F()) + (v11 * (v6 % simu_num));
  param = (*pHCardSpiral)->param;
  radius_s = param->radius_s;
  *&v12->_1.byval_arg.data = radius_s * DDS3EFFECT_RAND_FA(param->radius_s_r);
  v12->_1.byval_arg.bits = 0;
  v15 = (*pHCardSpiral)->param;
  radius_e = v15->radius_e;
  *(&v12->_1.name + 1) = ((radius_e * DDS3EFFECT_RAND_FA(v15->radius_e_r))
                        - *&v12->_1.byval_arg.data)
                       / v15->life;
  v17 = (*pHCardSpiral)->param;
  up_s = v17->up_s;
  *(&v12->_1.namespaze + 1) = up_s * DDS3EFFECT_RAND_FA(v17->up_r);
  *&v12->_1.namespaze = (*pHCardSpiral)->param->roll_s;
  LODWORD(v12->_1.name) = 0;
}

// 0x175ecb0
void effPCPHamaCardSpiralSetColor(void **hData, u32 abgr) {
}

// 0x175eb90
void effPCPHamaCardSpiralSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x175eda0
void effPCPHamaCardSpiralSetScale(void **hData, f32 scale) {
}

// 0x1765b90
effPCPWhirlwind2Poly_tag *effPCPWhirlwind2PolyCopy(void **hData, s32 bPos, bool tbldata) {
    effPCPWhirlwind2PolyCreate(0, 0);
    return 0;
}

// 0x1765500
effPCPWhirlwind2Poly_tag *effPCPWhirlwind2PolyCreate(effPCPWhirlwind2PolyParam_t *pParam, void *pTex) {
    effPCPWhirlwind2PolyParam_t__pClone(0, 0);
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__STOREMATRIX(0);
    dds3WhirlwindPolyListCreate(0, 0);
    DDS3EFFECT_RAND_I();
    return 0;
}

// 0x1765820
effPCPWhirlwind2Poly_tag *effPCPWhirlwind2PolyCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    GetTmxIndex(0, 0);
    billGetTexture(0);
    effPCPWhirlwind2PolyCreate(0, 0);
    return 0;
}

// 0x1765cc0
void effPCPWhirlwind2PolyDelete(void **hData) {
    dds3WhirlwindPolyListDelete(0);
}

// 0x1766810
void effPCPWhirlwind2PolyDraw(void **hData) {
    effColorMultiply(0, 0);
    effColorBlend(0, 0, 0);
    effPCPWhirlwind2PolyPartMove(0, 0);
    DDS3EFFECT_RAND_I();
    effPCPWhirlwind2PolyPartInit(0, 0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__STOREMATRIX(0);
    dds3WhirlwindPolyListDraw(0, 0);
}

// 0x1765dd0
void effPCPWhirlwind2PolyPartInit(effPCPWhirlwind2Poly_tag **pWhirlwind2Poly, s32 index) {
    DDS3EFFECT_RAND_F();
    DDS3EFFECT_RAND_FA(0);
    SetRotateMatrixX(0);
    SetRotateMatrixY_B(0);
    MultMatrixRevNoArg();
    sdfCos(0);
    sdfSin(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(0);
}

// 0x17663d0
void effPCPWhirlwind2PolyPartMove(effPCPWhirlwind2Poly_tag **pWhirlwind2Poly, s32 index) {
    SetRotateMatrixX(0);
    SetRotateMatrixY_B(0);
    MultMatrixRevNoArg();
    sdfCos(0);
    sdfSin(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(0);
}

// 0x1766e70
void effPCPWhirlwind2PolySetColor(void **hData, u32 abgr) {
}

// 0x1766c60
void effPCPWhirlwind2PolySetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1766f60
void effPCPWhirlwind2PolySetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__LOADMATRIX_B(0);
    MultMatrixNoArg();
    SDF_VU0__STOREMATRIX(0);
}

// 0x1766d80
void effPCPWhirlwind2PolySetScale(void **hData, f32 scale) {
}

// 0x1767770
effPCPWhirlwind3Poly_tag *effPCPWhirlwind3PolyCopy(void **hData, s32 bPos, bool tbldata) {
    effPCPWhirlwind3PolyCreate(0, 0);
    return 0;
}

// 0x17670e0
effPCPWhirlwind3Poly_tag *effPCPWhirlwind3PolyCreate(effPCPWhirlwind3PolyParam_t *pParam, void *pTex) {
    effPCPWhirlwind3PolyParam_t__pClone(0, 0);
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__STOREMATRIX(0);
    dds3WhirlwindPolyListCreate(0, 0);
    DDS3EFFECT_RAND_I();
    return 0;
}

// 0x1767400
effPCPWhirlwind3Poly_tag *effPCPWhirlwind3PolyCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    GetTmxIndex(0, 0);
    billGetTexture(0);
    effPCPWhirlwind3PolyCreate(0, 0);
    return 0;
}

// 0x17678a0
void effPCPWhirlwind3PolyDelete(void **hData) {
    dds3WhirlwindPolyListDelete(0);
}

// 0x1768410
void effPCPWhirlwind3PolyDraw(void **hData) {
    effColorBlend(0, 0, 0);
    effColorMultiply(0, 0);
    effPCPWhirlwind3PolyPartMove(0, 0);
    DDS3EFFECT_RAND_I();
    effPCPWhirlwind3PolyPartInit(0, 0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__STOREMATRIX(0);
    dds3WhirlwindPolyListDraw(0, 0);
}

// 0x17679b0
void effPCPWhirlwind3PolyPartInit(effPCPWhirlwind3Poly_tag **pWhirlwind3Poly, s32 index) {
    DDS3EFFECT_RAND_F();
    DDS3EFFECT_RAND_FA(0);
    SetRotateMatrixX(0);
    SetRotateMatrixY_B(0);
    MultMatrixRevNoArg();
    sdfCos(0);
    sdfSin(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(0);
}

// 0x1767fd0
void effPCPWhirlwind3PolyPartMove(effPCPWhirlwind3Poly_tag **pWhirlwind3Poly, s32 index) {
    SetRotateMatrixX(0);
    SetRotateMatrixY_B(0);
    MultMatrixRevNoArg();
    sdfCos(0);
    sdfSin(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(0);
}

// 0x1768a80
void effPCPWhirlwind3PolySetColor(void **hData, u32 abgr) {
}

// 0x1768870
void effPCPWhirlwind3PolySetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1768b70
void effPCPWhirlwind3PolySetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__LOADMATRIX_B(0);
    MultMatrixNoArg();
    SDF_VU0__STOREMATRIX(0);
}

// 0x1768990
void effPCPWhirlwind3PolySetScale(void **hData, f32 scale) {
}

// 0x1764060
effPCPWhirlwindPoly_tag *effPCPWhirlwindPolyCopy(void **hData, s32 bPos, bool tbldata) {
    effPCPWhirlwindPolyCreate(0, 0);
    return 0;
}

// 0x17639f0
effPCPWhirlwindPoly_tag *effPCPWhirlwindPolyCreate(effPCPWhirlwindPolyParam_t *pParam, void *pTex) {
    effPCPWhirlwindPolyParam_t__pClone(0, 0);
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__STOREMATRIX(0);
    dds3WhirlwindPolyListCreate(0, 0);
    DDS3EFFECT_RAND_I();
    return 0;
}

// 0x1763cf0
effPCPWhirlwindPoly_tag *effPCPWhirlwindPolyCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    GetTmxIndex(0, 0);
    billGetTexture(0);
    effPCPWhirlwindPolyCreate(0, 0);
    return 0;
}

// 0x1764190
void effPCPWhirlwindPolyDelete(void **hData) {
    dds3WhirlwindPolyListDelete(0);
}

// 0x1764c70
void effPCPWhirlwindPolyDraw(void **hData) {
    effColorMultiply(0, 0);
    effPCPWhirlwindPolyPartInit(0, 0);
    effBTLSkillCheckRun2(0);
    effColorBlend(0, 0, 0);
    effPCPWhirlwindPolyPartMove(0, 0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__STOREMATRIX(0);
    dds3WhirlwindPolyListDraw(0, 0);
}

// 0x17642a0
void effPCPWhirlwindPolyPartInit(effPCPWhirlwindPoly_tag **pWhirlwindPoly, s32 index) {
    DDS3EFFECT_RAND_F();
    DDS3EFFECT_RAND_FA(0);
    SetRotateMatrixX(0);
    SetRotateMatrixY_B(0);
    MultMatrixRevNoArg();
    sdfCos(0);
    sdfSin(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(0);
}

// 0x17648b0
void effPCPWhirlwindPolyPartMove(effPCPWhirlwindPoly_tag **pWhirlwindPoly, s32 index) {
    SetRotateMatrixX(0);
    SetRotateMatrixY_B(0);
    MultMatrixRevNoArg();
    sdfCos(0);
    sdfSin(0);
    SDF_VU0__LD_APPLYMATRIX(0);
}

// 0x1765290
void effPCPWhirlwindPolySetColor(void **hData, u32 abgr) {
}

// 0x1765080
void effPCPWhirlwindPolySetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1765380
void effPCPWhirlwindPolySetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__LOADMATRIX_B(0);
    MultMatrixNoArg();
    SDF_VU0__STOREMATRIX(0);
}

// 0x17651a0
void effPCPWhirlwindPolySetScale(void **hData, f32 scale) {
}

// 0x1769360
effPCPWwSpherePoly_tag *effPCPWwSpherePolyCopy(void **hData, s32 bPos, bool tbldata) {
    effPCPWwSpherePolyCreate(0, 0);
    return 0;
}

// 0x1768cf0
effPCPWwSpherePoly_tag *effPCPWwSpherePolyCreate(effPCPWwSpherePolyParam_t *pParam, void *pTex) {
    effPCPWwSpherePolyParam_t__pClone(0, 0);
    SDF_VU0__STOREIDENTITY(0);
    dds3WhirlwindPolyListCreate(0, 0);
    DDS3EFFECT_RAND_I();
    return 0;
}

// 0x1768ff0
effPCPWwSpherePoly_tag *effPCPWwSpherePolyCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    GetTmxIndex(0, 0);
    billGetTexture(0);
    effPCPWwSpherePolyCreate(0, 0);
    return 0;
}

// 0x1769490
void effPCPWwSpherePolyDelete(void **hData) {
    dds3WhirlwindPolyListDelete(0);
}

// 0x1769d00
void effPCPWwSpherePolyDraw(void **hData) {
    effColorMultiply(0, 0);
    effPCPWwSpherePolyPartInit(0, 0);
    effColorBlend(0, 0, 0);
    effPCPWwSpherePolyPartMove(0, 0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__STOREMATRIX(0);
    dds3WhirlwindPolyListDraw(0, 0);
}

// 0x17695a0
void effPCPWwSpherePolyPartInit(effPCPWwSpherePoly_tag **pWwSpherePoly, s32 index) {
    DDS3EFFECT_RAND_F();
    DDS3EFFECT_RAND_FA(0);
}

// 0x1769900
void effPCPWwSpherePolyPartMove(effPCPWwSpherePoly_tag **pWwSpherePoly, s32 index) {
    SetRotateMatrixXYZ(0);
    sdfCos(0);
    sdfSin(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(0);
}

// 0x176a2e0
void effPCPWwSpherePolySetColor(void **hData, u32 abgr) {
}

// 0x176a0d0
void effPCPWwSpherePolySetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x176a3d0
void effPCPWwSpherePolySetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__STOREMATRIX(0);
}

// 0x176a1f0
void effPCPWwSpherePolySetScale(void **hData, f32 scale) {
}

// 0x175c1a0
void effPkt3DPrimLinkPoly(sdfDrawTag_t *pTag, sdf3DPrimPolyParm_t *pParam) {
  ;
}

// 0x175c140
void *sdfChipAlloc(void *aSize) {
    return 0;
}
