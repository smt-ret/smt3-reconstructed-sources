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
  u64 number;
  struct XRD773Unity_CommonMesh_array *v4;
  struct XRD773Unity_CommonMesh_array *v5;
  s32 v6;
  XRD773Unity_GraphicManager_o *Instance;
  s64 *Mesh;
  s64 *v10;
  struct XRD773Unity_CommonMesh_array *pMesh;
  UnityEngine_Object_o *gameObject;
  System_String_o *name;
  System_String_o *v16;
  System_String_o *v17;
  struct XRD773Unity_CommonMesh_array *v18;
  u64 v21;
  u64 point;
  struct XRD773Unity_CommonMesh_array *v23;
  struct XRD773Unity_CommonMesh_array *v25;
  XRD773Unity_CommonMesh_o *v27;
  UnityEngine_Vector3_array *v28;
  struct XRD773Unity_CommonMesh_array *v29;
  XRD773Unity_CommonMesh_o *v31;
  UnityEngine_Color_array *v32;
  struct XRD773Unity_CommonMesh_array *v33;
  XRD773Unity_CommonMesh_o *v35;
  UnityEngine_Vector2_array *v36;
  struct XRD773Unity_CommonMesh_array *v37;
  XRD773Unity_CommonMesh_o *v39;
  System_Int32_array *v40;
  struct XRD773Unity_CommonMesh_array *v41;
  UnityEngine_Vector3_array *Position;
  struct XRD773Unity_CommonMesh_array *v44;
  UnityEngine_Color_array *Color;
  struct XRD773Unity_CommonMesh_array *v47;
  s32 v50;
  u32 *p_y;
  s64 v52;
  u64 v53;
  f32 *p_z;
  u64 v55;
  struct UnityEngine_Vector4_array *pVertex;
  f32 x;
  f32 y;
  f32 z;
  f32 w;
  f32 v62;
  f32 v63;
  f32 v64;
  f32 v65;
  f32 *p_SDF_CC_NDNM;
  f32 v69;
  f32 v70;
  f32 v71;
  struct System_UInt32_array *pVC;
  u32 v75;
  struct UnityEngine_Vector2_array *dds3ScatterPolyListDraw_uv;
  u32 max_length;
  s64 v80;
  Il2CppClass **v82;
  s32 v83;
  struct XRD773Unity_CommonMesh_array *v85;
  System_Int32_array *IndexTable;
  System_Int32_array *v89;
  s32 v90;
  s32 v91;
  s32 v92;
  s32 v93;
  u64 v94;
  s64 v95;
  struct System_UInt32_array *ScatterFaceIndex;
  u32 v99;
  s32 v101;
  il2cpp_array_size_t v102;
  s64 v103;
  s64 v104;
  struct XRD773Unity_CommonMesh_array *v106;
  struct XRD773Unity_CommonMesh_array *v108;
  u64 v110;
  s32 v111;
  s64 v112;
  UnityEngine_Vector2_array *UvTable;
  UnityEngine_Color_array *v114;
  UnityEngine_Vector3_array *v115;
  u32 v116;
  UnityEngine_Vector3_o v117;
  UnityEngine_Vector3_o v118;
  UnityEngine_Vector4_o v119;
  UnityEngine_Color_o VertexColorT;
  UnityEngine_Vector3_o v121;
  UnityEngine_Vector4_o v122;
  UnityEngine_Color_o BlendColor;
  UnityEngine_Vector4_o v124;
  UnityEngine_Color_o v125;
  UnityEngine_Vector4_o v126;

  v116 = 0;
  number = hPoly->number;
  if (!hPoly->pMesh)
  {
    v4 = NewSpecific(XRD773Unity_CommonMesh, number);
    hPoly->pMesh = v4;
    v116 = 0;
    if (hPoly->number < 1)
      return;
    v5 = v4;
    v6 = 0;
      goto LABEL_10;
LABEL_8:
    while (1)
    {
LABEL_10:
      Instance = get_Instance();
      Mesh = GetMesh(Instance, hPoly->blend + 4, 0);
      v10 = Mesh;
      v5->m_Items[v6] = v10;
      pMesh = hPoly->pMesh;
      gameObject = get_gameObject(pMesh->m_Items[v116]);
      name = get_name(gameObject);
      v16 = sub_232970(&v116);
      v17 = Concat_5221536(name, ":dds3ScatterPolyListDraw:", v16);
      set_name(gameObject, v17);
      v18 = hPoly->pMesh;
      SetAutoHide(v18->m_Items[v116], 1);
      v6 = v116 + 1;
      v116 = v6;
      number = hPoly->number;
      if (v6 >= number)
        break;
      v5 = hPoly->pMesh;
        goto LABEL_8;
    }
  }
  if (number >= 1)
  {
    v21 = 0;
    while (1)
    {
      BlendColor = effGetBlendColor(hPoly->abgr);
      v119 = op_Implicit(BlendColor, 0);
      if (v119.w > 0.0)
        break;
LABEL_95:
      if (++v21 >= hPoly->number)
        return;
    }
    point = hPoly->point;
    v23 = hPoly->pMesh;
    v111 = hPoly->point / 6;
    if (point > SLODWORD(GetPosition(v23->m_Items[v21])->max_length))
    {
      v25 = hPoly->pMesh;
      v27 = v25->m_Items[v21];
      v28 = NewSpecific(UnityEngine_Vector3, point);
      SetPosition_20241056(v27, v28);
      v29 = hPoly->pMesh;
      v31 = v29->m_Items[v21];
      v32 = NewSpecific(UnityEngine_Color, point);
      SetColor_20241296(v31, v32);
      v33 = hPoly->pMesh;
      v35 = v33->m_Items[v21];
      v36 = NewSpecific(UnityEngine_Vector2, point);
      SetUvTable_20243232(v35, v36);
      v37 = hPoly->pMesh;
      v39 = v37->m_Items[v21];
      v40 = NewSpecific(s32, (12 * v111));
      SetIndexTable(v39, v40);
    }
    v41 = hPoly->pMesh;
    Position = GetPosition(v41->m_Items[v21]);
    v44 = hPoly->pMesh;
    v115 = Position;
    Color = GetColor(v44->m_Items[v21], 0);
    v47 = hPoly->pMesh;
    v114 = Color;
    v110 = v21;
    UvTable = GetUvTable(v47->m_Items[v21]);
    if (point >= 1)
    {
      v50 = point * v21;
      v112 = 4LL * point * v21 + 32;
      p_y = &UvTable->m_Items[0].y;
      v52 = 0;
      v53 = 0;
      p_z = &v115->m_Items[0].z;
      do
      {
        v55 = point;
        pVertex = hPoly->pVertex;
        x = hPoly->pos.x;
        y = hPoly->pos.y;
        z = hPoly->pos.z;
        w = hPoly->pos.w;
        v62 = pVertex->m_Items[v52].x;
        v63 = pVertex->m_Items[v52].y;
        v64 = pVertex->m_Items[v52].z;
        v65 = pVertex->m_Items[v52].w;
        v122.x = x;
        v122.y = y;
        v122.z = z;
        v122.w = w;
        v126.x = v62;
        v126.y = v63;
        v126.z = v64;
        v126.w = v65;
        v124 = op_Addition(v122, v126);
        v117 = op_Implicit_8738992(v124);
        p_SDF_CC_NDNM = &SDF_CC_NDNM;
        v69 = p_SDF_CC_NDNM[41];
        v70 = p_SDF_CC_NDNM[42];
        v71 = p_SDF_CC_NDNM[43];
        v121.x = v69;
        v121.y = v70;
        v121.z = v71;
        v118 = Scale(v117, v121);
        *(p_z - 2) = v118;
        pVC = hPoly->pVC;
        v75 = *(&pVC->obj.klass + 4 * v53 + v112);
        v125 = op_Implicit_27186336(v119);
        VertexColorT = effGetVertexColorT(v75, v125);
        v114->m_Items[v52] = VertexColorT;
        max_length = dds3ScatterPolyListDraw_uv->max_length;
        v80 = (v53 % max_length);
        v82 = &dds3ScatterPolyListDraw_uv->obj.klass + v80;
        v83 = *(v82 + 9);
        ++v53;
        *(p_y - 1) = *(v82 + 8);
        *p_y = v83;
        ++v52;
        p_y += 2;
        p_z += 3;
        point = v55;
      }
      while (v55 != v53);
    }
    v85 = hPoly->pMesh;
    v21 = v110;
    IndexTable = GetIndexTable(v85->m_Items[v110]);
    v89 = IndexTable;
    if (point < 6)
    {
      v101 = 0;
      LODWORD(v102) = IndexTable->max_length;
      if (v102 <= 0)
      {
LABEL_90:
        v106 = hPoly->pMesh;
        SetMatTexture(v106->m_Items[v21], hPoly->pTexture);
        v108 = hPoly->pMesh;
        SetActive(v108->m_Items[v21], 1, 0);
        goto LABEL_95;
      }
    }
    else
    {
      v90 = 0;
      v91 = 0;
      v92 = 0;
      do
      {
        v93 = v91;
        v94 = 0;
        v95 = &v89->m_Items[v91];
        do
        {
          v99 = ScatterFaceIndex->m_Items[v94] + v90;
          *(v95 + 4 * v94++) = v99;
        }
        while (v94 != 12);
        ++v92;
        v91 = v93 + 12;
        v90 += 6;
      }
      while (v92 != v111);
      v101 = v93 + 12;
      v21 = v110;
      LODWORD(v102) = v89->max_length;
      if (v93 + 12 >= v102)
        goto LABEL_90;
    }
    v103 = v101;
    do
    {
      v104 = v103 + 1;
      v89->m_Items[v103] = 0;
      v102 = v89->max_length;
      ++v103;
    }
    while (v104 < v102);
    goto LABEL_90;
  }
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
  dds3ScatterPolyList_tag_o *v5;
  dds3ScatterPolyListTexResource_tag_o *v6;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3ScatterPolyList_tag_o *v10;
  char *v11;
  s64 *v12;
  u64 v13[3];

  v5 = *hPoly;
LABEL_7:
  if (pTex)
  {
    v6 = Allocate(dds3ScatterPolyListTexResource_tag);
    _ctor(v6, 0);
    v6->hTex = sdfTexSet(pTex);
    v6->count = 1;
    v5->hTexRes = v6;
    klass = pTex->klass;
    v10 = *hPoly;
    if (pTex->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != UnityEngine_Texture)
    {
      sub_8FC2C0(klass->_1.element_class, UnityEngine_Texture, v13);
      if ((v13[0] & 1) != 0)
        v11 = v13[2];
      else
        v11 = v13 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  else
  {
    v5->hTexRes = 0;
    v10 = *hPoly;
  }
  v10->pTexture = pTex;
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
  f32 *p_SDF_CC_NDNM;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 scale;
  f32 x;
  f32 y;
  f32 w;
  f32 z;
  dds3WhirlwindPolyList_tag_o *v17;
  struct XRD773Unity_CommonMesh_array *pMesh;
  XRD773Unity_GraphicManager_o *Instance;
  s64 *Mesh;
  s64 *v22;
  struct XRD773Unity_CommonMesh_array *v24;
  UnityEngine_Object_o *gameObject;
  System_String_o *name;
  System_String_o *v28;
  struct XRD773Unity_CommonMesh_array *v29;
  u64 *v34;
  dds3WhirlwindPolyList_tag_o *v35;
  u64 *v36;
  s32 v37;
  char *v38;
  s64 v39;
  struct System_UInt32_array *pABGR;
  u32 v42;
  u64 v44;
  struct XRD773Unity_CommonMesh_array *v45;
  s32 point;
  u32 v47;
  s32 v48;
  struct XRD773Unity_CommonMesh_array *v50;
  XRD773Unity_CommonMesh_o *v52;
  u64 v53;
  UnityEngine_Vector3_array *v54;
  struct XRD773Unity_CommonMesh_array *v55;
  XRD773Unity_CommonMesh_o *v57;
  UnityEngine_Color_array *v58;
  struct XRD773Unity_CommonMesh_array *v59;
  XRD773Unity_CommonMesh_o *v61;
  UnityEngine_Vector2_array *v62;
  struct XRD773Unity_CommonMesh_array *v63;
  XRD773Unity_CommonMesh_o *v65;
  System_Int32_array *v66;
  struct XRD773Unity_CommonMesh_array *v67;
  UnityEngine_Vector3_array *Position;
  struct XRD773Unity_CommonMesh_array *v70;
  UnityEngine_Color_array *Color;
  struct XRD773Unity_CommonMesh_array *v73;
  UnityEngine_Vector2_array *UvTable;
  struct XRD773Unity_CommonMesh_array *v76;
  System_Int32_array *IndexTable;
  dds3WhirlwindPolyList_tag_o *v80;
  System_Int32_array *v81;
  u64 v82;
  s32 v83;
  s32 v84;
  f32 *v86;
  f32 v87;
  f32 v88;
  f32 v89;
  f32 v90;
  u64 v91;
  s64 v92;
  s64 v93;
  u32 *p_z;
  s64 p_a;
  f32 *p_y;
  struct UnityEngine_Vector4_array *pVertex;
  f32 v99;
  f32 v100;
  f32 v101;
  f32 v102;
  long f64 v103;
  long f64 v104;
  s32 v105;
  s32 v106;
  u32 v107;
  struct System_UInt32_array *pVC;
  u32 v111;
  struct UnityEngine_Vector2_array *pUV;
  char *v115;
  s32 v116;
  f32 v117;
  s32 v119;
  s32 *v120;
  s32 v121;
  s32 v124;
  s32 v126;
  s32 v128;
  s32 v130;
  il2cpp_array_size_t max_length;
  struct XRD773Unity_CommonMesh_array *v133;
  struct XRD773Unity_CommonMesh_array *v134;
  s64 v136;
  s64 v137;
  s32 *v141;
  s32 v142;
  System_Int32_array *v143;
  u64 *v144;
  s32 v145;
  s32 v146;
  u64 v147;
  s32 v148;
  UnityEngine_Vector2_array *v149;
  UnityEngine_Color_array *v150;
  UnityEngine_Vector3_array *v151;
  s64 v152;
  s32 v153;
  dds3WhirlwindPolyList_tag_o **v154;
  UnityEngine_Matrix4x4_o v155;
  UnityEngine_Matrix4x4_o v156;
  UnityEngine_Matrix4x4_o v157;
  UnityEngine_Matrix4x4_o v158;
  UnityEngine_Matrix4x4_o v159;
  UnityEngine_Matrix4x4_o v160;
  UnityEngine_Vector3_o v161;
  UnityEngine_Vector3_o v162;
  UnityEngine_Vector4_o v163;
  UnityEngine_Color_o VertexColorT;
  UnityEngine_Vector3_o v165;
  UnityEngine_Vector3_o v166;
  UnityEngine_Vector3_o v167;
  UnityEngine_Vector4_o v168;
  UnityEngine_Vector4_o v169;
  UnityEngine_Vector4_o v170;
  UnityEngine_Color_o BlendColor;
  UnityEngine_Color_o v172;

  memset(&v160, 0, sizeof(v160));
  p_SDF_CC_NDNM = &SDF_CC_NDNM;
  v7 = p_SDF_CC_NDNM[43];
  v8 = p_SDF_CC_NDNM[41];
  v9 = p_SDF_CC_NDNM[42];
  scale = (*hPoly)->scale;
  v165.x = v8;
  v165.y = v9;
  v165.z = v7;
  v161 = op_Multiply(v165, scale, 0);
  Scale(&v159, v161);
  sub_19FF440(&(*hPoly)->matrix, 0, &v158);
  v156 = v159;
  v155 = v158;
  op_Multiply(&v157, &v156, &v155, 0);
  v160 = v157;
  x = (*hPoly)->pos.x;
  y = (*hPoly)->pos.y;
  z = (*hPoly)->pos.z;
  w = (*hPoly)->pos.w;
  v168.x = x;
  v168.y = y;
  v168.z = z;
  v168.w = w;
  v166 = op_Implicit_8738992(v168);
  v167 = Scale(v166, mod_pos);
  op_Implicit(v167, 0);
  sub_1A009D0(&v160, 3);
  if (!(*hPoly)->pMesh)
  {
    v17 = *hPoly;
    v17->pMesh = NewSpecific(XRD773Unity_CommonMesh, 1u);
    pMesh = (*hPoly)->pMesh;
    {
    }
    Instance = get_Instance();
    Mesh = GetMesh(Instance, (*hPoly)->blend + 4, 0, 0);
    v22 = Mesh;
    pMesh->m_Items[0] = v22;
    v24 = (*hPoly)->pMesh;
    gameObject = get_gameObject(v24->m_Items[0]);
    name = get_name(gameObject);
    v28 = Concat_5221536(name, ":dds3WhirlwindPolyListDraw:UseOne:", callname);
    set_name(gameObject, v28);
    v29 = (*hPoly)->pMesh;
    SetAutoHide(v29->m_Items[0], 1);
    if (e634_flag)
    {
      e634_flag = 0;
    }
  }
  v34 = NewSpecific(UnityEngine_Vector4, (*hPoly)->number);
  v35 = *hPoly;
  if ((*hPoly)->number)
  {
    v36 = v34;
    v37 = 0;
    v38 = v34 + 44;
    v39 = 8;
    do
    {
      pABGR = v35->pABGR;
      v42 = *(&pABGR->obj.klass + v39);
      if (HIBYTE(v42))
      {
        BlendColor = effGetBlendColor(v42);
        v163 = op_Implicit(BlendColor, 0);
        ++v37;
        *(v38 - 12) = v163;
      }
      v35 = *hPoly;
      v44 = v39 - 7;
      ++v39;
      v38 += 16;
    }
    while (v44 < (*hPoly)->number);
    if (v37 >= 1)
    {
      v45 = v35->pMesh;
      point = v35->point;
      v47 = point * v37;
      if (point - 2 >= 0)
        v48 = point - 2;
      else
        v48 = point - 1;
      v145 = point - 2;
      v152 = v35->point;
      v142 = v48 >> 1;
      if (v47 > SLODWORD(GetPosition(v45->m_Items[0])->max_length))
      {
        v50 = (*hPoly)->pMesh;
        v52 = v50->m_Items[0];
        v53 = v47;
        v54 = NewSpecific(UnityEngine_Vector3, v47);
        SetPosition_20241056(v52, v54);
        v55 = (*hPoly)->pMesh;
        v57 = v55->m_Items[0];
        v58 = NewSpecific(UnityEngine_Color, v53);
        SetColor_20241296(v57, v58);
        v59 = (*hPoly)->pMesh;
        v61 = v59->m_Items[0];
        v62 = NewSpecific(UnityEngine_Vector2, v53);
        SetUvTable_20243232(v61, v62);
        v63 = (*hPoly)->pMesh;
        v65 = v63->m_Items[0];
        v66 = NewSpecific(s32, (6 * v37 * v142));
        SetIndexTable(v65, v66);
      }
      v67 = (*hPoly)->pMesh;
      Position = GetPosition(v67->m_Items[0]);
      v70 = (*hPoly)->pMesh;
      v151 = Position;
      Color = GetColor(v70->m_Items[0], 0);
      v73 = (*hPoly)->pMesh;
      v150 = Color;
      UvTable = GetUvTable(v73->m_Items[0]);
      v76 = (*hPoly)->pMesh;
      v149 = UvTable;
      IndexTable = GetIndexTable(v76->m_Items[0]);
      v80 = *hPoly;
      v81 = IndexTable;
      if ((*hPoly)->number)
      {
        v82 = 0;
        v153 = 0;
        v154 = hPoly;
        v83 = 0;
        v143 = IndexTable;
        v84 = 0;
        v148 = 0;
        v141 = &IndexTable->m_Items[5];
        v144 = v36;
        do
        {
          v86 = &v36[2 * v82];
          v87 = v86[11];
          if (v87 > 0.0)
          {
            if (v152 >= 1)
            {
              v146 = v84;
              v147 = v82;
              v88 = v86[8];
              v89 = v86[9];
              v90 = v86[10];
              v91 = 0;
              v92 = v153;
              v93 = 16LL * v153 + 32;
              p_z = &v151->m_Items[v148].z;
              p_a = &v150->m_Items[v148].a;
              p_y = &v149->m_Items[v148].y;
              do
              {
                pVertex = (*hPoly)->pVertex;
                v99 = *(&pVertex->obj.klass + v93);
                v100 = *(&pVertex->obj.klass + v93 + 4);
                v101 = *(&pVertex->obj.monitor + v93);
                v102 = *(&pVertex->obj.monitor + v93 + 4);
                {
                }
                v169.x = v99;
                v169.y = v100;
                v169.z = v101;
                v169.w = v102;
                v162 = op_Implicit_8738992(v169);
                v104 = sub_1A00CF0(&v160.m00, v162.x, v162.y, v162.z, v103);
                v107 = v148 + v91;
                *(p_z - 2) = LODWORD(v104);
                *(p_z - 1) = v105;
                *p_z = v106;
                pVC = (*v154)->pVC;
                v111 = pVC->m_Items[v91];
                v170.x = v88;
                v170.y = v89;
                v170.z = v90;
                v170.w = v87;
                v172 = op_Implicit_27186336(v170);
                VertexColorT = effGetVertexColorT(v111, v172);
                *(p_a - 12) = VertexColorT;
                pUV = (*v154)->pUV;
                v115 = pUV + v92 * 8;
                v117 = pUV->m_Items[v92].x;
                v116 = *(v115 + 9);
                *(p_y - 1) = v117;
                *p_y = v116;
                hPoly = v154;
                ++v91;
                ++v92;
                v93 += 16;
                p_z += 3;
                p_a += 16;
                p_y += 2;
              }
              while (v152 != v91);
              v81 = v143;
              v82 = v147;
              v84 = v146;
              v148 += v91;
            }
            if (v145 <= 1)
            {
              v36 = v144;
            }
            else
            {
              v119 = v142;
              v120 = &v141[v83];
              v36 = v144;
              do
              {
                v121 = v84;
                *(v120 - 5) = v84;
                v124 = v84 + 1;
                *(v120 - 4) = v121 + 1;
                v126 = v124 + 2;
                *(v120 - 3) = v126;
                v128 = v126 - 3;
                *(v120 - 2) = v128;
                v130 = v128 + 3;
                *(v120 - 1) = v130;
                v84 = v130 - 1;
                --v119;
                v83 += 6;
                *v120 = v84;
                v120 += 6;
              }
              while (v119);
              v84 = v121 + 2;
            }
            v84 += 2;
          }
          v80 = *hPoly;
          ++v82;
          v153 += v152;
        }
        while (v82 < (*hPoly)->number);
        LODWORD(max_length) = v81->max_length;
        if (v83 >= max_length)
        {
LABEL_112:
          v133 = v80->pMesh;
          if (LODWORD(v133->max_length))
          {
LABEL_113:
            SetMatTexture(v133->m_Items[0], v80->pTexture);
            v134 = (*hPoly)->pMesh;
            SetActive(v134->m_Items[0], 1, 0);
            return;
          }
LABEL_123:
        }
      }
      else
      {
        v83 = 0;
        LODWORD(max_length) = IndexTable->max_length;
        if (max_length <= 0)
          goto LABEL_112;
      }
      v136 = v83;
      do
      {
        v137 = v136 + 1;
        v81->m_Items[v136] = 0;
        max_length = v81->max_length;
        ++v136;
      }
      while (v137 < max_length);
      v80 = *hPoly;
      v133 = (*hPoly)->pMesh;
      if (LODWORD(v133->max_length))
        goto LABEL_113;
      goto LABEL_123;
    }
  }
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
  dds3WhirlwindPolyList_tag_o *v5;
  dds3ScatterPolyListTexResource_tag_o *v6;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3WhirlwindPolyList_tag_o *v10;
  char *v11;
  s64 *v12;
  u64 v13[3];

  v5 = *hPoly;
LABEL_7:
  if (pTex)
  {
    v6 = Allocate(dds3ScatterPolyListTexResource_tag);
    _ctor(v6, 0);
    v6->hTex = sdfTexSet(pTex);
    v6->count = 1;
    v5->hTexRes = v6;
    klass = pTex->klass;
    v10 = *hPoly;
    if (pTex->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != UnityEngine_Texture)
    {
      sub_8FC2C0(klass->_1.element_class, UnityEngine_Texture, v13);
      if ((v13[0] & 1) != 0)
        v11 = v13[2];
      else
        v11 = v13 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  else
  {
    v5->hTexRes = 0;
    v10 = *hPoly;
  }
  v10->pTexture = pTex;
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
        else if (!LODWORD(v19->max_length))
        {
LABEL_24:
        }
        v21 = dds3EffectPartCopy(v19->m_Items, 0, 0);
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
          else if (!*(v31 + 24))
          {
LABEL_34:
          }
          v33 = dds3EffectPartCopy((v31 + 32), 0, 0);
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
  struct dds3EffectPCPData_Part_t_array *v18;
  Il2CppObject *v19;
  Il2CppObject *v21;
  struct dds3EffectPCPData_Part_t_array *v22;
  Il2CppObject *v23;
  Il2CppObject *Texture;
  Il2CppObject *v26;
  struct dds3EffectPCPData_Part_t_array *v28;
  Il2CppObject *v29;
  u32 v31;
  s32 TmxIndex;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  effPCPHamaCardScatterParam_t_o *v37;
  char *v38;
  s64 *v39;
  Il2CppClass *v40;
  s64 v41;
  char *v42;
  s64 *v43;
  u64 v45[2];
  char *v46;
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
      sub_8FC2C0(v7->klass->_1.element_class, v8, v45);
      if ((v45[0] & 1) != 0)
        v10 = v46;
      else
        v10 = v45 + 1;
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
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 31);
  v18 = v6->pcpData;
  v19 = DataUnityOffSet;
  v21 = dds3EffectPCPDataGetDataUnityOffSet(*hData, v18->m_Items[1]->offset + bPos, 58);
  v22 = v6->pcpData;
  v23 = *hData;
  Texture = v21;
  v26 = dds3EffectPCPDataGetDataUnityOffSet(v23, v22->m_Items[2]->offset + bPos, 58);
  v28 = v6->pcpData;
  v29 = v26;
  v31 = v28->m_Items[1]->offset;
  TmxIndex = GetTmxIndex(Interface, v31 + bPos);
  if (v19)
  {
    klass = v19->klass;
    if (v19->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || (v37 = v19, klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHamaCardScatterParam_t))
    {
      sub_8FC2C0(klass->_1.element_class, effPCPHamaCardScatterParam_t, v45);
      if ((v45[0] & 1) != 0)
        v38 = v46;
      else
        v38 = v45 + 1;
      v39 = sub_8C4940(v38);
    }
  }
  else
  {
    v37 = 0;
  }
  if (TmxIndex < 0)
  {
    if (v19)
    {
      v40 = v19->klass;
      if (v19->klass->_2.typeHierarchyDepth < v41
        || v40->_2.typeHierarchy[v41 - 1] != effPCPHamaCardScatterParam_t)
      {
        sub_8FC2C0(v40->_1.element_class, effPCPHamaCardScatterParam_t, v45);
        if ((v45[0] & 1) != 0)
          v42 = v46;
        else
          v42 = v45 + 1;
        v43 = sub_8C4940(v42);
      }
      v37 = v19;
    }
    else
    {
      v37 = 0;
    }
  }
  else
  {
    Texture = billGetTexture(TmxIndex);
  }
  return effPCPHamaCardScatterCreate(v37, Texture, v29);
}

// 0x1761760
void effPCPHamaCardScatterDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s64 monitor_low;
  u64 v9;
  s64 v10;
  Il2CppClass *v11;
  dds3ScatterPolyList_tag_o *monitor;
  u64 v14[3];

  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHamaCardScatter_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPHamaCardScatter_tag, v14);
      if ((v14[0] & 1) != 0)
        v6 = v14[2];
      else
        v6 = v14 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  if (v3[4].monitor)
  {
    monitor_low = LODWORD(v3[3].monitor);
    if (monitor_low)
    {
      v9 = 0;
      v10 = 32;
      do
      {
        v11 = v3[4].klass;
        else if (v9 >= LODWORD(v11->_1.namespaze))
        {
LABEL_18:
        }
        dds3EffectPartDelete((v11 + v10), 0);
        ++v9;
        v10 += 8;
      }
      while (monitor_low != v9);
    }
    v3[4].monitor = 0;
  }
  monitor = v3[2].monitor;
  dds3ScatterPolyListDelete(monitor);
}

// 0x1761ac0
void effPCPHamaCardScatterDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  Il2CppClass *v9;
  s32 element_class_high;
  s64 data_low;
  s32 v12;
  s32 v15;
  f32 v16;
  f32 v17;
  u64 v18;
  s32 v19;
  s64 v20;
  u64 *monitor;
  s64 v23;
  s64 v24;
  void *v25;
  u32 *v26;
  s64 v27;
  f32 v28;
  f32 v29;
  f32 v30;
  s32 v31;
  u32 v32;
  s32 v33;
  s64 v35;
  u32 *v37;
  s64 v38;
  u32 *v40;
  s64 v41;
  u32 *v43;
  s64 v44;
  s64 v46;
  u32 *v48;
  s64 v49;
  u32 v50;
  f32 v51;
  f32 v52;
  f32 v53;
  f32 v54;
  u32 v55;
  f32 v57;
  f32 v58;
  f32 v59;
  f32 v60;
  f32 v61;
  u32 v62;
  s64 v63;
  s64 v64;
  s64 v66;
  f32 v69;
  f32 v70;
  f32 v73;
  u32 v74;
  s32 v75;
  s32 v76;
  Il2CppClass *v77;
  Il2CppClass *v79;
  Il2CppClass *v81;
  s64 v83;
  s64 v84;
  s64 v85;
  dds3ScatterPolyList_tag_o *v87;
  f32 v88;
  f32 v89;
  s64 v90;
  s64 bits;
  s32 v92;
  s64 v93;
  Il2CppObject *v94;
  s32 element_class;
  u32 parent;
  u32 abgr1;
  s32 declaringType_high;
  s32 v99;
  Il2CppClass *v100;
  s32 v101;
  s32 v102;
  UnityEngine_Vector4_o v103;
  UnityEngine_Vector4_o v104;
  UnityEngine_Vector4_o v105;
  UnityEngine_Vector4_o v106;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o v109;
  UnityEngine_Vector4_o v110;
  effPCPHamaCardScatter_tag_o *pHCardScatter;
  u64 v112[4];

  pHCardScatter = 0;
  *&v110.x = 0;
  *&v110.z = 0;
  *&v109.x = 0;
  *&v109.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v106.x = 0;
  *&v106.z = 0;
  *&v105.x = 0;
  *&v105.z = 0;
  *&v104.x = 0;
  *&v104.z = 0;
  *&v103.x = 0;
  *&v103.z = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHamaCardScatter_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPHamaCardScatter_tag, v112);
      if ((v112[0] & 1) != 0)
        v6 = v112[2];
      else
        v6 = v112 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  pHCardScatter = *hData;
  v8 = Allocate(effPCPHamaCardScatterPart_tag);
  _ctor(v8, 0);
  *&v110.x = 0;
  *&v110.z = 0;
  *&v109.x = 0;
  *&v109.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v106.x = 0;
  *&v106.z = 0;
  *&v105.x = 0;
  *&v105.z = 0;
  *&v104.x = 0;
  *&v104.z = 0;
  *&v103.x = 0;
  *&v103.z = 0;
  v9 = v3[1].klass;
  element_class_high = HIDWORD(v9->_1.element_class);
  data_low = LODWORD(v9->_1.this_arg.data);
  v12 = *(&v9->_1.byval_arg.bits + 4);
  element_class = v9->_1.element_class;
  bits = v9->_1.this_arg.bits;
  v90 = *(&v9->_1.this_arg.bits + 1);
  v100 = v3[4].klass;
  parent = v9->_1.parent;
  abgr1 = HIDWORD(v3[2].klass);
  declaringType_high = HIDWORD(v9->_1.declaringType);
  sub_854930(&v105, 0);
  sub_854710(&v105, 0);
  sub_854930(&v105, 1u);
  sub_854930(&v105, 2u);
  sub_854930(&v104, 0);
  sub_854710(&v104, 0);
  sub_854930(&v104, 1u);
  sub_854930(&v104, 2u);
  if (data_low)
  {
    v15 = 3;
    v101 = element_class_high + element_class;
    v16 = bits;
    v89 = v16;
    v17 = v90;
    v18 = 0;
    v19 = 0;
    v92 = v12;
    v88 = v17;
    v93 = data_low;
    v94 = v3;
    do
    {
      monitor = v3[1].monitor;
      v23 = monitor[v18 + 4];
      v24 = *(v23 + 16);
      if (v24)
      {
        v25 = v3[2].monitor;
        v102 = v15;
        v26 = *(v25 + 7);
        if (v24 >= 1)
        {
          v27 = *(v25 + 6);
          v28 = 0.0;
          if (v101 >= v24)
          {
            if (bits && v24 < bits)
            {
              v29 = v89;
              v30 = v24;
              goto LABEL_44;
            }
            v28 = 1.0;
            if (v90)
            {
              v28 = 1.0;
              if (v101 - v24 <= v90)
              {
                v30 = (v101 - v24);
                v29 = v88;
LABEL_44:
                v28 = v30 / v29;
              }
            }
          }
          v99 = v19;
          v49 = 16LL * v19;
          v50 = effColorBlend(abgr1 & 0xFFFFFF, abgr1, v28);
          v52 = *(v23 + 20);
          v51 = *(v23 + 24);
          v53 = *(v23 + 40);
          v54 = *(v23 + 28);
          v55 = v50;
          sub_854710(&v105, 0);
          v58 = v57;
          v59 = sdfAtan(v58 / v53);
          v60 = *(v23 + 36);
          v61 = v54 - v59;
          sub_854930(&v106, 0);
          sub_854930(&v106, 1u);
          sub_854930(&v106, 2u);
          sdfSin(v61);
          sub_854930(&v109, 0);
          sdfCos(v61);
          sub_854930(&v109, 1u);
          sub_854930(&v109, 2u);
          SDF_VU0__LOADVECTOR(v109);
          SDF_VU0__COPYVECTOR_A_TO_C();
          v62 = v102;
          v63 = 0;
          v64 = v27 + v49;
          do
          {
            v66 = *(v26 + 3);
            v26[8] = v55;
            v26[11] = v55;
            v52 = v51 + v52;
            sub_854710(&v105, 0);
            v70 = v69;
            v61 = v61 + sdfAtan(v70 / v53);
            sdfSin(v61);
            sub_854930(&v110, 0);
            sdfCos(v61);
            sub_854930(&v110, 1u);
            sub_854930(&v110, 2u);
            SDF_VU0__LOADVECTOR(v110);
            SDF_VU0__LOADVECTOR_B(v109);
            SDF_VU0__SUBVECTOR();
            SDF_VU0__NORMALIZE();
            SDF_VU0__STOREVECTOR(&p);
            SDF_VU0__LOADVECTOR_B(v105);
            SDF_VU0__MULVECTOR();
            SDF_VU0__ADDVECTOR_A_C();
            SDF_VU0__COPYVECTOR_A_TO_C();
            SDF_VU0__STOREVECTOR(&v109);
            SDF_VU0__LOADVECTOR(v106);
            SDF_VU0__LOADVECTOR_B(v104);
            SDF_VU0__MULVECTOR();
            SDF_VU0__STOREVECTOR(&v103);
            SDF_VU0__LOADVECTOR(v109);
            SDF_VU0__LOADVECTOR_B(v103);
            SDF_VU0__ADDVECTOR();
            SDF_VU0__STOREVECTOR((v64 + v63 + 32), 0);
            SDF_VU0__SUBVECTOR();
            SDF_VU0__SUBVECTOR();
            SDF_VU0__STOREVECTOR((v64 + v63 + 80), 0);
            if (v63 == 16)
              SDF_VU0__COPYVECTOR(&dst, v109);
            SDF_VU0__COPYVECTOR(&v109, v110);
            v63 += 16;
            ++v62;
          }
          while (v63 != 48);
          data_low = v93;
          v3 = v94;
          v12 = v92;
          v19 = v99;
          v15 = v102;
          if (v24 < element_class)
          {
            *(v23 + 20) = v51 + *(v23 + 20);
            v73 = v60 + *(v23 + 28);
            *(v23 + 28) = v73;
            if (sdfFabs(v73) > (*(v23 + 32) * 0.5))
            {
              *(v23 + 28) = *(v23 + 28) - v60;
              *(v23 + 36) = -*(v23 + 36);
            }
          }
          if (!v92)
            goto LABEL_72;
          goto LABEL_70;
        }
        v31 = 6 * v18;
        v32 = v26[6];
        v33 = v19;
        v35 = v31 | 1u;
        v26[v31 + 8] = 0;
        v37 = &v26[v35];
        v38 = (v31 + 2);
        v37[8] = 0;
        v40 = &v26[v38];
        v41 = (v31 + 3);
        v40[8] = 0;
        v43 = &v26[v41];
        v44 = (v31 + 4);
        v43[8] = 0;
        v46 = (v31 + 5);
        v26[v44 + 8] = 0;
        v48 = &v26[v46];
        v15 = v102;
        v19 = v33;
        v48[8] = 0;
        if (!v12)
          goto LABEL_72;
      }
      else
      {
        effPCPHamaCardScatterPartInit(&pHCardScatter, v18);
        if (!v12)
          goto LABEL_72;
      }
LABEL_70:
      if (v101 <= v24)
        *(v23 + 16) = -1;
LABEL_72:
      if ((v24 & 0x80000000) == 0)
      {
        if (v100)
        {
          if (declaringType_high <= v24)
          {
            v74 = v18 / parent;
            if (!(v18 % parent))
            {
              v75 = v15;
              v76 = v19;
              v77 = v3[4].klass;
              else
              {
                v20 = v74;
                if (v74 >= LODWORD(v77->_1.namespaze))
                {
LABEL_79:
                }
              }
              dds3EffectPartSetColor(&v77->_1.byval_arg.data + v20, abgr1);
              SDF_VU0__LOADVECTOR(*&v3[1].klass->_1.name);
              SDF_VU0__LOADVECTOR_B(dst);
              SDF_VU0__ADDVECTOR();
              SDF_VU0__STOREVECTOR(&dst);
              v79 = v3[4].klass;
              dds3EffectPartSetPosition(&v79->_1.byval_arg.data + v20, dst);
              v81 = v3[4].klass;
              dds3EffectPartDraw(&v81->_1.byval_arg.data + v20);
              v19 = v76;
              v15 = v75;
            }
          }
        }
      }
      ++v18;
      v19 += 6;
      v15 += 6;
      ++*(v23 + 16);
    }
    while (v18 != data_low);
  }
  v83 = v3[2].monitor + 16;
  sub_854710(&v3[1].klass->_1.name, 0);
  sub_854930(v83, 0);
  v84 = v3[2].monitor + 16;
  sub_854710(&v3[1].klass->_1.name, 1u);
  sub_854930(v84, 1u);
  v85 = v3[2].monitor + 16;
  sub_854710(&v3[1].klass->_1.name, 2u);
  sub_854930(v85, 2u);
  v87 = v3[2].monitor;
  dds3ScatterPolyListDraw(v87);
}

// 0x1761910
void effPCPHamaCardScatterPartInit(effPCPHamaCardScatter_tag **pHCardScatter, s32 number) {
  struct effPCPHamaCardScatterPart_tag_array *pPart;
  effPCPHamaCardScatterPart_tag_o *v7;
  f32 v8;
  f32 v9;
  f32 v10;
  UnityEngine_Vector4_o v11;

  *&v11.x = 0;
  *&v11.z = 0;
  pPart = (*pHCardScatter)->pPart;
  v7 = pPart->m_Items[number];
  v7->height = 0.0;
  v7->height_s = (*pHCardScatter)->param->drop_s;
  *&v7->radian = 0x3FC90FDB3F490FDBLL;
  v7->radian_s = 0.087266;
  v8 = DDS3EFFECT_RAND_F();
  v7->radius = 200.0;
  v7->roll = v8 * 6.2832;
  DDS3EFFECT_RAND_PM();
  sub_854930(&v11, 0);
  sub_854930(&v11, 1u);
  DDS3EFFECT_RAND_PM();
  sub_854930(&v11, 2u);
  SDF_VU0__LOADVECTOR(v11);
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v11);
  sub_854710(&v11, 0);
  sub_8518D0(&v7->axis, 0, v9);
  sub_854710(&v11, 2u);
  sub_8518D0(&v7->axis, 1, v10);
  v7->frame = 0;
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
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  effPCPHamaCardSphereParam_t_o *v10;
  effPCPHamaCardSphere_tag_o *v11;
  void *monitor;
  effPCPHamaCardSphere_tag_o *v14;
  struct dds3ScatterPolyList_tag_o *hPoly;
  struct effPCPHamaCardSphereParam_t_o *param;
  u32 v17;
  s64 v18;
  u64 *v19;
  u64 v21;
  u32 *pAttach;
  Il2CppClass *v24;
  s64 *v26;
  s64 *v27;
  u32 *v29;
  u64 v31[3];

  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHamaCardSphere_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPHamaCardSphere_tag, v31);
      if ((v31[0] & 1) != 0)
        v8 = v31[2];
      else
        v8 = v31 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = v5[1].klass;
  v11 = effPCPHamaCardSphereCreate(v10, 0, 0);
  monitor = v5[2].monitor;
  v14 = v11;
  hPoly = v14->hPoly;
  hPoly->hTexRes = 0;
  v14->hPoly->pTexture = *(monitor + 12);
  param = v14->param;
  if (param->attach)
  {
    v17 = param->number / param->attach_i;
    v14->AttachNum = v17;
    if (param->number % param->attach_i)
      v14->AttachNum = ++v17;
    v18 = v17;
    v14->pAttach = NewSpecific(effPartHandle_t, v17);
    v19 = Allocate(sdfMemHandle_t);
    sdfMemHandle_t___ctor(v19);
    v14->hAttachMem = v19;
    if (v17)
    {
      v21 = 0;
      do
      {
        pAttach = v14->pAttach;
        v24 = v5[4].klass;
        else if (!LODWORD(v24->_1.namespaze))
        {
LABEL_29:
        }
        v26 = dds3EffectPartCopy(&v24->_1.byval_arg, 0, 0);
        v27 = v26;
        v29 = &pAttach[2 * v21++];
        *(v29 + 4) = v27;
      }
      while (v18 != v21);
    }
  }
  return v14;
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
          else if (!*(v31 + 24))
          {
LABEL_34:
          }
          v33 = dds3EffectPartCopy((v31 + 32), 0, 0);
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
  struct dds3EffectPCPData_Part_t_array *v18;
  Il2CppObject *v19;
  Il2CppObject *v21;
  struct dds3EffectPCPData_Part_t_array *v22;
  Il2CppObject *v23;
  Il2CppObject *Texture;
  Il2CppObject *v26;
  struct dds3EffectPCPData_Part_t_array *v28;
  Il2CppObject *v29;
  u32 v31;
  s32 TmxIndex;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  effPCPHamaCardSphereParam_t_o *v37;
  char *v38;
  s64 *v39;
  Il2CppClass *v40;
  s64 v41;
  char *v42;
  s64 *v43;
  u64 v45[2];
  char *v46;
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
      sub_8FC2C0(v7->klass->_1.element_class, v8, v45);
      if ((v45[0] & 1) != 0)
        v10 = v46;
      else
        v10 = v45 + 1;
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
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 30);
  v18 = v6->pcpData;
  v19 = DataUnityOffSet;
  v21 = dds3EffectPCPDataGetDataUnityOffSet(*hData, v18->m_Items[1]->offset + bPos, 58);
  v22 = v6->pcpData;
  v23 = *hData;
  Texture = v21;
  v26 = dds3EffectPCPDataGetDataUnityOffSet(v23, v22->m_Items[2]->offset + bPos, 58);
  v28 = v6->pcpData;
  v29 = v26;
  v31 = v28->m_Items[1]->offset;
  TmxIndex = GetTmxIndex(Interface, v31 + bPos);
  if (v19)
  {
    klass = v19->klass;
    if (v19->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || (v37 = v19, klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHamaCardSphereParam_t))
    {
      sub_8FC2C0(klass->_1.element_class, effPCPHamaCardSphereParam_t, v45);
      if ((v45[0] & 1) != 0)
        v38 = v46;
      else
        v38 = v45 + 1;
      v39 = sub_8C4940(v38);
    }
  }
  else
  {
    v37 = 0;
  }
  if (TmxIndex < 0)
  {
    if (v19)
    {
      v40 = v19->klass;
      if (v19->klass->_2.typeHierarchyDepth < v41
        || v40->_2.typeHierarchy[v41 - 1] != effPCPHamaCardSphereParam_t)
      {
        sub_8FC2C0(v40->_1.element_class, effPCPHamaCardSphereParam_t, v45);
        if ((v45[0] & 1) != 0)
          v42 = v46;
        else
          v42 = v45 + 1;
        v43 = sub_8C4940(v42);
      }
      v37 = v19;
    }
    else
    {
      v37 = 0;
    }
  }
  else
  {
    Texture = billGetTexture(TmxIndex);
  }
  return effPCPHamaCardSphereCreate(v37, Texture, v29);
}

// 0x175f9f0
void effPCPHamaCardSphereDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s64 monitor_low;
  u64 v9;
  s64 v10;
  Il2CppClass *v11;
  dds3ScatterPolyList_tag_o *monitor;
  u64 v14[3];

  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHamaCardSphere_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPHamaCardSphere_tag, v14);
      if ((v14[0] & 1) != 0)
        v6 = v14[2];
      else
        v6 = v14 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  if (v3[4].monitor)
  {
    monitor_low = LODWORD(v3[3].monitor);
    if (monitor_low)
    {
      v9 = 0;
      v10 = 32;
      do
      {
        v11 = v3[4].klass;
        else if (v9 >= LODWORD(v11->_1.namespaze))
        {
LABEL_18:
        }
        dds3EffectPartDelete((v11 + v10), 0);
        ++v9;
        v10 += 8;
      }
      while (monitor_low != v9);
    }
    v3[4].monitor = 0;
  }
  monitor = v3[2].monitor;
  dds3ScatterPolyListDelete(monitor);
}

// 0x175fdb0
void effPCPHamaCardSphereDraw(void **hData) {
  u32 *v3;
  s64 v4;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  s64 v9;
  s64 v10;
  s32 v11;
  s32 v12;
  s32 v13;
  s64 v14;
  s64 v15;
  u32 v16;
  f64 v19;
  f64 v20;
  u64 v21;
  s32 v22;
  s32 v23;
  u32 v24;
  s64 v25;
  s64 v26;
  s64 v28;
  s64 v29;
  s64 v30;
  s64 v31;
  f32 v32;
  f32 v33;
  f32 v34;
  u32 v35;
  u32 v36;
  s64 v38;
  s64 v40;
  s64 v41;
  s64 v43;
  s64 v44;
  s64 v46;
  s64 v47;
  s64 v49;
  s64 v51;
  s64 v52;
  s64 v53;
  u32 v54;
  f32 v55;
  f32 v56;
  f32 v57;
  f32 v58;
  bool v59;
  f32 *v60;
  f32 v61;
  s64 v63;
  s64 v64;
  s64 v65;
  u32 v66;
  s64 v67;
  u32 *v68;
  u32 v71;
  f32 v74;
  f32 v75;
  f32 v77;
  s64 v78;
  s64 v79;
  f32 v82;
  u32 v83;
  effPCPHamaCardSphere_tag_o *v84;
  s32 v85;
  struct effPartHandle_t_array *pAttach;
  struct effPartHandle_t_array *v88;
  struct effPartHandle_t_array *v90;
  s64 v92;
  s64 v93;
  s64 v94;
  dds3ScatterPolyList_tag_o *v96;
  f32 v97;
  f32 v98;
  s64 v99;
  s64 v100;
  f32 v101;
  s32 v102;
  s32 abgr0;
  s32 v104;
  s32 v105;
  s64 v106;
  f32 v107;
  s32 v108;
  u32 v109;
  s32 v110;
  s32 v111;
  s32 v112;
  u32 abgr;
  s64 v114;
  s32 v115;
  s32 v116;
  s32 v117;
  s64 v118;
  UnityEngine_Vector4_o v119;
  UnityEngine_Vector4_o v120;
  UnityEngine_Vector4_o v121;
  UnityEngine_Vector4_o v122;
  UnityEngine_Vector4_o v123;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v126;
  s64 v127;
  s64 v128;
  effPCPHamaCardSphere_tag_o *pHCardSphere;
  u64 v130[4];
  UnityEngine_Vector4_o v131;
  UnityEngine_Vector4_o v132;

  v128 = 0;
  pHCardSphere = 0;
  *&v126.x = 0;
  *&v126.z = 0;
  v127 = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  *&v123.x = 0;
  *&v123.z = 0;
  *&v122.x = 0;
  *&v122.z = 0;
  *&v121.x = 0;
  *&v121.z = 0;
  *&v120.x = 0;
  *&v120.z = 0;
  *&v119.x = 0;
  *&v119.z = 0;
  v3 = *hData;
  if (*hData)
  {
    v4 = *v3;
    if (*(*v3 + 288LL) < typeHierarchyDepth
      || *(*(v4 + 200) + 8 * typeHierarchyDepth - 8) != effPCPHamaCardSphere_tag)
    {
      sub_8FC2C0(*(v4 + 64), effPCPHamaCardSphere_tag, v130);
      if ((v130[0] & 1) != 0)
        v6 = v130[2];
      else
        v6 = v130 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  pHCardSphere = *hData;
  v8 = Allocate(effPCPHamaCardSpherePart_tag);
  _ctor(v8, 0);
  v127 = 0;
  v128 = 0;
  *&v126.x = 0;
  *&v126.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  *&v123.x = 0;
  *&v123.z = 0;
  *&v122.x = 0;
  *&v122.z = 0;
  *&v121.x = 0;
  *&v121.z = 0;
  *&v120.x = 0;
  *&v120.z = 0;
  *&v119.x = 0;
  *&v119.z = 0;
  v9 = *(v3 + 2);
  v10 = *(v9 + 48);
  v12 = *(v9 + 64);
  v11 = *(v9 + 68);
  v13 = *(v9 + 44);
  v107 = *(v9 + 100);
  v108 = *(v9 + 96);
  v15 = *(v9 + 56);
  v14 = *(v9 + 60);
  v101 = *(v9 + 76);
  v114 = *(v3 + 8);
  v109 = *(v9 + 112);
  v110 = *(v9 + 108);
  v16 = v3[9];
  sub_854930(&v121, 0);
  sub_854710(&v121, 0);
  sub_854930(&v121, 1u);
  sub_854930(&v121, 2u);
  sub_854930(&v120, 0);
  sub_854710(&v120, 0);
  sub_854930(&v120, 1u);
  sub_854930(&v120, 2u);
  if (v10)
  {
    v19 = v15;
    v20 = v14;
    v99 = v14;
    v100 = v15;
    v21 = 0;
    v22 = 0;
    abgr0 = v16 & 0xFFFFFF;
    v104 = v13;
    v23 = 3;
    v24 = v16;
    v115 = v11 + v12;
    v102 = v12 + 1;
    abgr = v16;
    v106 = v10;
    v105 = v12;
    *&v19 = v19;
    v98 = *&v19;
    *&v19 = v20;
    v97 = *&v19;
    do
    {
      v26 = *(v3 + 3);
      v28 = *(*(v26 + 8 * v21 + 32) + 16LL);
      v118 = *(v26 + 8 * v21 + 32);
      if (v28)
      {
        v29 = *(v3 + 5);
        v116 = v23;
        v30 = *(v29 + 56);
        if (v28 >= 1)
        {
          v31 = *(v29 + 48);
          v32 = 0.0;
          if (v115 >= v28)
          {
            if (v100 && v28 < v100)
            {
              v33 = v98;
              v34 = v28;
              goto LABEL_44;
            }
            v32 = 1.0;
            if (v99)
            {
              v32 = 1.0;
              if (v115 - v28 <= v99)
              {
                v34 = (v115 - v28);
                v33 = v97;
LABEL_44:
                v32 = v34 / v33;
              }
            }
          }
          v52 = 16LL * v22;
          v112 = v22;
          v53 = 4LL * v22;
          v54 = effColorBlend(abgr0, v24, v32);
          v56 = *(v118 + 28);
          v55 = *(v118 + 32);
          v111 = v28;
          v57 = v55 - v107;
          if (v28 != v102)
            v57 = *(v118 + 32);
          if (v28 == v12)
            v57 = v107 + v55;
          v58 = *(v118 + 24);
          v59 = v28 < v12;
          v60 = (v118 + 36);
          if (v59)
            v57 = *(v118 + 32);
          if (v108)
            v61 = v57;
          else
            v61 = *(v118 + 32);
          sub_8527D0((v118 + 36), 0);
          sub_854930(&v127, 0);
          sub_8527D0(v60, 1);
          sub_854930(&v127, 1u);
          sub_8527D0(v60, 2);
          sub_854930(&v127, 2u);
          v63 = v127;
          v64 = v128;
          *&v131.x = v63;
          *&v131.z = v64;
          SetRotateMatrixAxis(v61, v131);
          sub_854930(&p, 0);
          sub_854930(&p, 1u);
          sub_854930(&p, 2u);
          SDF_VU0__LOADVECTOR(p);
          SDF_VU0__APPLYMATRIX();
          SDF_VU0__STOREVECTOR(&p);
          SDF_VU0__COPYVECTOR_A_TO_C();
          v65 = v31 + v52;
          v66 = v116;
          v67 = 0;
          v68 = (v30 + v53 + 44);
          do
          {
            *(v68 - 3) = v54;
            v71 = *(v30 + 24);
            *v68 = *(v30 + 32);
            sub_854710(&v121, 0);
            v75 = v74;
            v77 = sdfAtan(v75 / v56);
            v78 = v127;
            v79 = v128;
            v61 = v61 + v77;
            *&v132.x = v78;
            *&v132.z = v79;
            SetRotateMatrixAxis(v61, v132);
            sub_854930(&v126, 0);
            sub_854930(&v126, 1u);
            sub_854930(&v126, 2u);
            SDF_VU0__LOADVECTOR(v126);
            SDF_VU0__APPLYMATRIX();
            SDF_VU0__STOREVECTOR(&v126);
            SDF_VU0__LOADVECTOR(v126);
            SDF_VU0__LOADVECTOR_B(p);
            SDF_VU0__SUBVECTOR();
            SDF_VU0__NORMALIZE();
            SDF_VU0__STOREVECTOR(&v123);
            SDF_VU0__LOADVECTOR_B(v121);
            SDF_VU0__MULVECTOR();
            SDF_VU0__ADDVECTOR_A_C();
            SDF_VU0__COPYVECTOR_A_TO_C();
            SDF_VU0__STOREVECTOR(&p);
            SDF_VU0__STOREVECTOR(&v122);
            sub_854930(&v122, 1u);
            SDF_VU0__LOADVECTOR(v123);
            SDF_VU0__LOADVECTOR_B(v122);
            SDF_VU0__OUTERPRODUCT();
            SDF_VU0__NORMALIZE();
            SDF_VU0__LOADVECTOR_B(v120);
            SDF_VU0__MULVECTOR();
            SDF_VU0__STOREVECTOR(&v119);
            SDF_VU0__LOADVECTOR(p);
            SDF_VU0__LOADVECTOR_B(v119);
            SDF_VU0__ADDVECTOR();
            SDF_VU0__STOREVECTOR((v65 + v67 + 32), 0);
            SDF_VU0__SUBVECTOR();
            SDF_VU0__SUBVECTOR();
            SDF_VU0__STOREVECTOR((v65 + v67 + 80), 0);
            if (v67 == 16)
              SDF_VU0__COPYVECTOR(&dst, p);
            SDF_VU0__COPYVECTOR(&p, v126);
            v67 += 16;
            ++v68;
            ++v66;
          }
          while (v67 != 48);
          v13 = v104;
          v12 = v105;
          v10 = v106;
          LODWORD(v28) = v111;
          v22 = v112;
          v24 = abgr;
          v23 = v116;
          if (v111 < v105)
          {
            v82 = v58 + *(v118 + 32);
            *(v118 + 28) = *(v118 + 28) + *(v118 + 20);
            *(v118 + 32) = v82;
            *(v118 + 24) = v101 * v58;
          }
          if (!v104)
            goto LABEL_82;
          goto LABEL_80;
        }
        v35 = 6 * v21;
        v36 = *(v30 + 24);
        v38 = v35 | 1;
        *(v30 + 4LL * v35 + 32) = 0;
        v40 = v30 + 4 * v38;
        v41 = v35 + 2;
        *(v40 + 32) = 0;
        v43 = v30 + 4 * v41;
        v44 = v35 + 3;
        *(v43 + 32) = 0;
        v46 = v30 + 4 * v44;
        v47 = v35 + 4;
        *(v46 + 32) = 0;
        v49 = v35 + 5;
        *(v30 + 4 * v47 + 32) = 0;
        v51 = v30 + 4 * v49;
        v23 = v116;
        *(v51 + 32) = 0;
        if (!v13)
          goto LABEL_82;
      }
      else
      {
        effPCPHamaCardSpherePartInit(&pHCardSphere, v21);
        if (!v13)
          goto LABEL_82;
      }
LABEL_80:
      if (v115 <= v28)
        *(v118 + 16) = -1;
LABEL_82:
      if ((v28 & 0x80000000) == 0)
      {
        if (v114)
        {
          if (v110 <= v28)
          {
            v83 = v21 / v109;
            if (!(v21 % v109))
            {
              v84 = pHCardSphere;
              v117 = v23;
              v85 = v22;
              pAttach = pHCardSphere->pAttach;
              else
              {
                v25 = v83;
                if (v83 >= LODWORD(pAttach->max_length))
                {
LABEL_89:
                }
              }
              dds3EffectPartSetColor(&pAttach->m_Items[v25], abgr);
              SDF_VU0__LOADVECTOR(v84->param->pos);
              SDF_VU0__LOADVECTOR_B(dst);
              SDF_VU0__ADDVECTOR();
              SDF_VU0__STOREVECTOR(&dst);
              v88 = v84->pAttach;
              dds3EffectPartSetPosition(&v88->m_Items[v25], dst);
              v90 = v84->pAttach;
              dds3EffectPartDraw(&v90->m_Items[v25]);
              v24 = abgr;
              v22 = v85;
              v23 = v117;
            }
          }
        }
      }
      ++*(v118 + 16);
      v3 = pHCardSphere;
      ++v21;
      v22 += 6;
      v23 += 6;
    }
    while (v21 != v10);
  }
  v92 = *(v3 + 5) + 16LL;
  sub_854710(*(v3 + 2) + 16LL, 0);
  sub_854930(v92, 0);
  v93 = *(v3 + 5) + 16LL;
  sub_854710(*(v3 + 2) + 16LL, 1u);
  sub_854930(v93, 1u);
  v94 = *(v3 + 5) + 16LL;
  sub_854710(*(v3 + 2) + 16LL, 2u);
  sub_854930(v94, 2u);
  v96 = *(v3 + 5);
  dds3ScatterPolyListDraw(v96);
}

// 0x175fba0
void effPCPHamaCardSpherePartInit(effPCPHamaCardSphere_tag **pHCardSphere, s32 number) {
  struct effPCPHamaCardSpherePart_tag_array *pPart;
  effPCPHamaCardSpherePart_tag_o *v7;
  struct effPCPHamaCardSphereParam_t_o *param;
  f32 radius_s;
  struct effPCPHamaCardSphereParam_t_o *v10;
  f32 radius_e;
  f32 v12;
  f32 v13;
  f32 v14;
  UnityEngine_Vector4_o v15;

  *&v15.x = 0;
  *&v15.z = 0;
  pPart = (*pHCardSphere)->pPart;
  v7 = pPart->m_Items[number];
  v7->radian = DDS3EFFECT_RAND_F() * 6.2832;
  param = (*pHCardSphere)->param;
  radius_s = param->radius_s;
  v7->radius = radius_s * DDS3EFFECT_RAND_FA(param->radius_s_r);
  v10 = (*pHCardSphere)->param;
  radius_e = v10->radius_e;
  v7->radius_s = ((radius_e * DDS3EFFECT_RAND_FA(v10->radius_e_r)) - v7->radius)
                      / v10->life;
  v7->roll_s = (*pHCardSphere)->param->roll_s;
  DDS3EFFECT_RAND_PM();
  sub_854930(&v15, 0);
  DDS3EFFECT_RAND_PM();
  sub_854930(&v15, 1u);
  DDS3EFFECT_RAND_PM();
  sub_854930(&v15, 2u);
  SDF_VU0__LOADVECTOR(v15);
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v15);
  sub_854710(&v15, 0);
  sub_8529B0(&v7->axis, 0, v12);
  sub_854710(&v15, 1u);
  sub_8529B0(&v7->axis, 1, v13);
  sub_854710(&v15, 2u);
  sub_8529B0(&v7->axis, 2, v14);
  v7->frame = 0;
}

// 0x1760ac0
void effPCPHamaCardSphereSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHamaCardSphere_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPHamaCardSphere_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[2].klass) = abgr;
}

// 0x17609a0
void effPCPHamaCardSphereSetPosition(void **hData, sdfVector4_t pPos) {
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
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHamaCardSphere_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPHamaCardSphere_tag, v12);
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

// 0x1760bb0
void effPCPHamaCardSphereSetScale(void **hData, f32 scale) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  v5 = *hData;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHamaCardSphere_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPHamaCardSphere_tag, v10);
    if ((v10[0] & 1) != 0)
      v8 = v10[2];
    else
      v8 = v10 + 1;
    v9 = sub_8C4940(v8);
  }
  *&v5[1].klass->_1.declaringType = *&v5[1].klass->_1.declaringType * scale;
  *(&v5[1].klass->_1.declaringType + 1) = *(&v5[1].klass->_1.declaringType + 1) * scale;
}

// 0x175da60
effPCPHamaCardSpiral_tag *effPCPHamaCardSpiralCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  effPCPHamaCardSpiralParam_t_o *v10;
  effPCPHamaCardSpiral_tag_o *v11;
  void *monitor;
  effPCPHamaCardSpiral_tag_o *v14;
  struct dds3ScatterPolyList_tag_o *hPoly;
  struct effPCPHamaCardSpiralParam_t_o *param;
  u32 v17;
  s64 v18;
  u64 *v19;
  u64 v21;
  u32 *pAttach;
  Il2CppClass *v24;
  s64 *v26;
  s64 *v27;
  u32 *v29;
  u64 v31[3];

  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHamaCardSpiral_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPHamaCardSpiral_tag, v31);
      if ((v31[0] & 1) != 0)
        v8 = v31[2];
      else
        v8 = v31 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = v5[1].klass;
  v11 = effPCPHamaCardSpiralCreate(v10, 0, 0);
  monitor = v5[2].monitor;
  v14 = v11;
  hPoly = v14->hPoly;
  hPoly->hTexRes = 0;
  v14->hPoly->pTexture = *(monitor + 12);
  param = v14->param;
  if (param->attach)
  {
    v17 = param->number / param->attach_i;
    v14->AttachNum = v17;
    if (param->number % param->attach_i)
      v14->AttachNum = ++v17;
    v18 = v17;
    v14->pAttach = NewSpecific(effPartHandle_t, v17);
    v19 = Allocate(sdfMemHandle_t);
    sdfMemHandle_t___ctor(v19);
    v14->hAttachMem = v19;
    if (v17)
    {
      v21 = 0;
      do
      {
        pAttach = v14->pAttach;
        v24 = v5[4].klass;
        else if (!LODWORD(v24->_1.namespaze))
        {
LABEL_29:
        }
        v26 = dds3EffectPartCopy(&v24->_1.byval_arg, 0, 0);
        v27 = v26;
        v29 = &pAttach[2 * v21++];
        *(v29 + 4) = v27;
      }
      while (v18 != v21);
    }
  }
  return v14;
}

// 0x175d140
effPCPHamaCardSpiral_tag *effPCPHamaCardSpiralCreate(effPCPHamaCardSpiralParam_t *pParam, void *pTex, void *pData) {
  u64 *v7;
  u64 *v8;
  u64 *v9;
  u64 *v10;
  s64 *v12;
  u32 number;
  dds3ScatterPolyList_tag_o *v14;
  u64 v17;
  u32 v18;
  u32 v19;
  s64 v20;
  u64 *v21;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  s64 v24;
  Il2CppClass *v25;
  s32 monitor;
  s64 *v27;
  s64 *v29;
  s64 v32;
  s64 v33;
  s64 v35;
  s64 *v37;
  s64 *v38;
  s64 v40;
  s64 v41;
  u32 v42;
  u32 v43;
  u64 v44;
  s32 v45;
  u32 *v47;
  u64 *v48;
  u64 v51;
  s64 v53;
  u32 v54;
  u32 v55;
  char *v57;
  s64 *v58;
  u64 v59[3];

  v7 = Allocate(effPCPHamaCardSpiral_tag);
  _ctor(v7, 0);
  v8 = Allocate(effPCPHamaCardSpiralParam_t);
  effPCPHamaCardSpiralParam_t___ctor(v8);
  v9 = v7 + 2;
  v7[2] = v8;
  effPCPHamaCardSpiralParam_t__pClone(pParam, v7 + 2);
  v10 = NewSpecific(effPCPHamaCardSpiralPart_tag, pParam->number);
  v7[9] = 0;
  v7[6] = 0;
  v7[8] = 0;
  v12 = (v7 + 8);
  v7[3] = v10;
  v7[4] = 0x808080803F800000LL;
  number = pParam->number;
  v14 = dds3ScatterPolyListCreate(number);
  v7[5] = v14;
  v14->blend = pParam->blend;
  if (pTex)
  {
    dds3ScatterPolyListSetTex(v7 + 5, pTex);
  }
  if (pData)
  {
    v17 = *v9;
    if (*(*v9 + 120))
    {
      v18 = *(v17 + 128);
      if (!v18)
      {
        *(v17 + 128) = 1;
        v17 = *v9;
        v18 = *(*v9 + 128);
      }
      v19 = *(v17 + 48) / v18;
      *(v7 + 14) = v19;
      if (*(v17 + 48) % *(v17 + 128))
        *(v7 + 14) = ++v19;
      v20 = v19;
      v7[8] = NewSpecific(effPartHandle_t, v19);
      v21 = Allocate(sdfMemHandle_t);
      sdfMemHandle_t___ctor(v21);
      v7[9] = v21;
      klass = pData->klass;
      if (pData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_object_Param_t)
      {
        sub_8FC2C0(klass->_1.element_class, effPCP_object_Param_t, v59);
        if ((v59[0] & 1) != 0)
          v57 = v59[2];
        else
          v57 = v59 + 1;
        v58 = sub_8C4940(v57);
      }
      v24 = *v12;
      v25 = pData[1].klass;
      monitor = pData[1].monitor;
      v27 = dds3EffectPartCreate(6u, v25, monitor, 0);
      v29 = v27;
      *(v24 + 32) = v29;
      if (v20 >= 2)
      {
        v32 = 0;
        v33 = v20 - 1;
        do
        {
          v35 = *v12;
          else if (!*(v35 + 24))
          {
LABEL_36:
          }
          v37 = dds3EffectPartCopy((v35 + 32), 0, 0);
          v38 = v37;
          v40 = v35 + 8 * v32++;
          *(v40 + 40) = v38;
        }
        while (v33 != v32);
      }
    }
  }
  v41 = *(*v9 + 48);
  if (*(*v9 + 56) <= 1)
    v42 = 1;
  else
    v42 = *(*v9 + 56);
  if (v41)
  {
    v43 = *(*v9 + 52);
    v44 = 0;
    v45 = 0;
    do
    {
      v47 = v7[3];
      v48 = Allocate(effPCPHamaCardSpiralPart_tag);
      _ctor(v48, 0);
      *&v47[2 * v44 + 8] = v48;
      v51 = v7[3];
      v53 = *(v51 + 8 * v44 + 32);
      v54 = DDS3EFFECT_RAND_I();
      ++v44;
      *(v53 + 16) = v45 + v54 / v42 * v42 - v54;
      if (v44 % v43)
        v55 = 0;
      else
        v55 = v42;
      v45 -= v55;
    }
    while (v41 != v44);
  }
  return v7;
}

// 0x175d660
effPCPHamaCardSpiral_tag *effPCPHamaCardSpiralCreatePCF(void **hData, s32 bPos, bool tbldata) {
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
  struct dds3EffectPCPData_Part_t_array *v18;
  Il2CppObject *v19;
  Il2CppObject *v21;
  struct dds3EffectPCPData_Part_t_array *v22;
  Il2CppObject *v23;
  Il2CppObject *Texture;
  Il2CppObject *v26;
  struct dds3EffectPCPData_Part_t_array *v28;
  Il2CppObject *v29;
  u32 v31;
  s32 TmxIndex;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  effPCPHamaCardSpiralParam_t_o *v37;
  char *v38;
  s64 *v39;
  Il2CppClass *v40;
  s64 v41;
  char *v42;
  s64 *v43;
  u64 v45[2];
  char *v46;
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
      sub_8FC2C0(v7->klass->_1.element_class, v8, v45);
      if ((v45[0] & 1) != 0)
        v10 = v46;
      else
        v10 = v45 + 1;
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
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 29);
  v18 = v6->pcpData;
  v19 = DataUnityOffSet;
  v21 = dds3EffectPCPDataGetDataUnityOffSet(*hData, v18->m_Items[1]->offset + bPos, 58);
  v22 = v6->pcpData;
  v23 = *hData;
  Texture = v21;
  v26 = dds3EffectPCPDataGetDataUnityOffSet(v23, v22->m_Items[2]->offset + bPos, 58);
  v28 = v6->pcpData;
  v29 = v26;
  v31 = v28->m_Items[1]->offset;
  TmxIndex = GetTmxIndex(Interface, v31 + bPos);
  if (v19)
  {
    klass = v19->klass;
    if (v19->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || (v37 = v19, klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHamaCardSpiralParam_t))
    {
      sub_8FC2C0(klass->_1.element_class, effPCPHamaCardSpiralParam_t, v45);
      if ((v45[0] & 1) != 0)
        v38 = v46;
      else
        v38 = v45 + 1;
      v39 = sub_8C4940(v38);
    }
  }
  else
  {
    v37 = 0;
  }
  if (TmxIndex < 0)
  {
    if (v19)
    {
      v40 = v19->klass;
      if (v19->klass->_2.typeHierarchyDepth < v41
        || v40->_2.typeHierarchy[v41 - 1] != effPCPHamaCardSpiralParam_t)
      {
        sub_8FC2C0(v40->_1.element_class, effPCPHamaCardSpiralParam_t, v45);
        if ((v45[0] & 1) != 0)
          v42 = v46;
        else
          v42 = v45 + 1;
        v43 = sub_8C4940(v42);
      }
      v37 = v19;
    }
    else
    {
      v37 = 0;
    }
  }
  else
  {
    Texture = billGetTexture(TmxIndex);
  }
  return effPCPHamaCardSpiralCreate(v37, Texture, v29);
}

// 0x175dd40
void effPCPHamaCardSpiralDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s64 monitor_low;
  u64 v9;
  s64 v10;
  Il2CppClass *v11;
  dds3ScatterPolyList_tag_o *monitor;
  u64 v14[3];

  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHamaCardSpiral_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPHamaCardSpiral_tag, v14);
      if ((v14[0] & 1) != 0)
        v6 = v14[2];
      else
        v6 = v14 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  if (v3[4].monitor)
  {
    monitor_low = LODWORD(v3[3].monitor);
    if (monitor_low)
    {
      v9 = 0;
      v10 = 32;
      do
      {
        v11 = v3[4].klass;
        else if (v9 >= LODWORD(v11->_1.namespaze))
        {
LABEL_18:
        }
        dds3EffectPartDelete((v11 + v10), 0);
        ++v9;
        v10 += 8;
      }
      while (monitor_low != v9);
    }
    v3[4].monitor = 0;
  }
  monitor = v3[2].monitor;
  dds3ScatterPolyListDelete(monitor);
}

// 0x175e080
void effPCPHamaCardSpiralDraw(void **hData) {
  effPCPHamaCardSpiral_tag_o *v3;
  effPCPHamaCardSpiral_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  struct effPCPHamaCardSpiralParam_t_o *param;
  s64 number;
  s32 wait;
  s32 life;
  s32 loop;
  f32 vib_power;
  u32 abgr;
  s64 fade_in;
  s64 fade_out;
  f32 v19;
  f32 v20;
  s32 v21;
  u64 v22;
  s32 v23;
  s64 v24;
  struct effPCPHamaCardSpiralPart_tag_array *pPart;
  struct dds3ScatterPolyList_tag_o *hPoly;
  struct UnityEngine_Vector4_array *pVertex;
  struct System_UInt32_array *pVC;
  s64 frame;
  f32 v31;
  f32 v32;
  f32 v33;
  s32 v34;
  u32 v35;
  s32 v36;
  s64 v38;
  s64 v40;
  s64 v41;
  s64 v43;
  s64 v44;
  s64 v46;
  s64 v47;
  s64 v49;
  u32 v51;
  f32 radian;
  f32 radius;
  f32 height;
  f32 up_s;
  f32 roll_s;
  u32 v58;
  s64 v59;
  s64 v60;
  u32 v61;
  s64 v62;
  u32 *v63;
  u32 v64;
  u32 max_length;
  f32 v70;
  f32 v71;
  f32 v74;
  u32 v75;
  effPCPHamaCardSpiral_tag_o *v76;
  struct effPartHandle_t_array *v77;
  struct effPartHandle_t_array *v79;
  struct effPartHandle_t_array *v81;
  s64 p_fields;
  s64 v84;
  s64 v85;
  dds3ScatterPolyList_tag_o *v87;
  f32 v88;
  s32 v89;
  f32 v90;
  s64 v91;
  s64 v92;
  f32 roll_a;
  f32 up_a;
  s32 abgr0;
  s32 v96;
  s32 v97;
  s64 v98;
  s32 vibrate;
  u32 attach_i;
  s32 v101;
  u32 abgr1;
  s32 attach_f;
  s32 v104;
  struct effPartHandle_t_array *pAttach;
  s64 v106;
  s32 v107;
  effPCPHamaCardSpiralPart_tag_o *v108;
  UnityEngine_Vector4_o v109;
  UnityEngine_Vector4_o v110;
  UnityEngine_Vector4_o v111;
  UnityEngine_Vector4_o v112;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o v115;
  UnityEngine_Vector4_o v116;
  effPCPHamaCardSpiral_tag_o *pHCardSpiral;
  u64 v118[4];

  *&v116.z = 0;
  pHCardSpiral = 0;
  *&v115.x = 0;
  *&v115.z = 0;
  *&v116.x = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v112.x = 0;
  *&v112.z = 0;
  *&v111.x = 0;
  *&v111.z = 0;
  *&v110.x = 0;
  *&v110.z = 0;
  *&v109.x = 0;
  *&v109.z = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHamaCardSpiral_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPHamaCardSpiral_tag, v118);
      if ((v118[0] & 1) != 0)
        v6 = v118[2];
      else
        v6 = v118 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  *&v116.z = 0;
  pHCardSpiral = v3;
  *&v115.z = 0;
  *&v116.x = 0;
  *&v115.x = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v112.x = 0;
  *&v112.z = 0;
  *&v111.x = 0;
  *&v111.z = 0;
  *&v110.x = 0;
  *&v110.z = 0;
  *&v109.x = 0;
  *&v109.z = 0;
  param = v3->param;
  number = param->number;
  life = param->life;
  wait = param->wait;
  loop = param->loop;
  vib_power = param->vib_power;
  abgr = v3->abgr;
  vibrate = param->vibrate;
  fade_in = param->fade_in;
  fade_out = param->fade_out;
  up_a = param->up_a;
  roll_a = param->roll_a;
  pAttach = v3->pAttach;
  attach_f = param->attach_f;
  attach_i = param->attach_i;
  sub_854930(&v111, 0);
  sub_854710(&v111, 0);
  sub_854930(&v111, 1u);
  sub_854930(&v111, 2u);
  sub_854930(&v110, 0);
  sub_854710(&v110, 0);
  sub_854930(&v110, 1u);
  sub_854930(&v110, 2u);
  if (number)
  {
    v91 = fade_out;
    v92 = fade_in;
    v98 = number;
    v97 = life;
    v19 = fade_in;
    v90 = v19;
    v20 = fade_out;
    v21 = wait + life;
    abgr0 = abgr & 0xFFFFFF;
    v96 = loop;
    v22 = 0;
    v23 = 0;
    v89 = life + 1;
    v101 = wait + life;
    abgr1 = abgr;
    v107 = 3;
    v88 = v20;
    do
    {
      pPart = v3->pPart;
      v106 = v23;
      v108 = pPart->m_Items[v22];
      hPoly = v3->hPoly;
      pVertex = hPoly->pVertex;
      pVC = hPoly->pVC;
      frame = v108->frame;
      if (frame)
      {
        if (frame >= 1)
        {
          v31 = 0.0;
          if (v21 >= frame)
          {
            if (v92 && frame < v92)
            {
              v32 = v90;
              v33 = frame;
              goto LABEL_44;
            }
            v31 = 1.0;
            if (v91)
            {
              v31 = 1.0;
              if (v21 - frame <= v91)
              {
                v33 = (v21 - frame);
                v32 = v88;
LABEL_44:
                v31 = v33 / v32;
              }
            }
          }
          v51 = effColorBlend(abgr0, abgr1, v31);
          radius = v108->radius;
          radian = v108->radian;
          height = v108->height;
          roll_s = v108->roll_s;
          up_s = v108->up_s;
          v58 = v51;
          if (vibrate && frame >= life)
          {
            if (frame == life)
            {
              radian = vib_power + radian;
              height = height + ((vib_power * up_s) / roll_s);
            }
            else if (frame == v89)
            {
              radian = radian - vib_power;
              height = height - ((vib_power * up_s) / roll_s);
            }
          }
          v104 = frame;
          v59 = 16LL * v23;
          sdfCos(radian);
          sub_854930(&v115, 0);
          sub_854930(&v115, 1u);
          sdfSin(radian);
          sub_854930(&v115, 2u);
          SDF_VU0__LOADVECTOR_C(v115);
          v60 = pVertex + v59;
          v61 = v107;
          v62 = 0;
          v63 = &pVC->m_Items[v106];
          do
          {
            v64 = v61 - 3;
            *v63 = v58;
            max_length = pVC->max_length;
            v63[3] = v58;
            sub_854710(&v111, 0);
            v71 = v70;
            radian = radian + sdfAtan(v71 / radius);
            height = up_s + height;
            sdfCos(radian);
            sub_854930(&v116, 0);
            sub_854930(&v116, 1u);
            sdfSin(radian);
            sub_854930(&v116, 2u);
            SDF_VU0__LOADVECTOR(v116);
            SDF_VU0__LOADVECTOR_B(v115);
            SDF_VU0__SUBVECTOR();
            SDF_VU0__NORMALIZE();
            SDF_VU0__STOREVECTOR(&p);
            SDF_VU0__LOADVECTOR_B(v111);
            SDF_VU0__MULVECTOR();
            SDF_VU0__ADDVECTOR_A_C();
            SDF_VU0__COPYVECTOR_A_TO_C();
            SDF_VU0__STOREVECTOR(&v115);
            SDF_VU0__STOREVECTOR(&v112);
            sub_854930(&v112, 1u);
            SDF_VU0__LOADVECTOR(p);
            SDF_VU0__LOADVECTOR_B(v112);
            SDF_VU0__OUTERPRODUCT();
            SDF_VU0__NORMALIZE();
            SDF_VU0__LOADVECTOR_B(v110);
            SDF_VU0__MULVECTOR();
            SDF_VU0__STOREVECTOR(&v109);
            SDF_VU0__LOADVECTOR(v115);
            SDF_VU0__LOADVECTOR_B(v109);
            SDF_VU0__ADDVECTOR();
            SDF_VU0__STOREVECTOR((v60 + v62 + 32), 0);
            SDF_VU0__SUBVECTOR();
            SDF_VU0__SUBVECTOR();
            SDF_VU0__STOREVECTOR((v60 + v62 + 80), 0);
            if (v62 == 16)
              SDF_VU0__COPYVECTOR(&dst, v115);
            SDF_VU0__COPYVECTOR(&v115, v116);
            v62 += 16;
            ++v63;
            ++v61;
          }
          while (v62 != 48);
          loop = v96;
          life = v97;
          LODWORD(frame) = v104;
          number = v98;
          v21 = v101;
          if (v104 < v97)
          {
            v74 = roll_s + v108->radian;
            v108->radius = v108->radius + v108->radius_s;
            v108->radian = v74;
            v108->height = up_s + v108->height;
            v108->roll_s = roll_a * roll_s;
            v108->up_s = up_a * up_s;
          }
          if (!v96)
            goto LABEL_76;
          goto LABEL_74;
        }
        v34 = 6 * v22;
        v35 = pVC->max_length;
        v36 = v108->frame;
        v38 = v34 | 1u;
        pVC->m_Items[v34] = 0;
        v40 = pVC + 4 * v38;
        v41 = (v34 + 2);
        *(v40 + 32) = 0;
        v43 = pVC + 4 * v41;
        v44 = (v34 + 3);
        *(v43 + 32) = 0;
        v46 = pVC + 4 * v44;
        v47 = (v34 + 4);
        *(v46 + 32) = 0;
        v49 = (v34 + 5);
        pVC->m_Items[v47] = 0;
        LODWORD(frame) = v36;
        pVC->m_Items[v49] = 0;
        if (!loop)
          goto LABEL_76;
      }
      else
      {
        effPCPHamaCardSpiralPartInit(&pHCardSpiral, v22);
        if (!loop)
          goto LABEL_76;
      }
LABEL_74:
      if (v21 <= frame)
        v108->frame = -1;
LABEL_76:
      if ((frame & 0x80000000) == 0)
      {
        if (pAttach)
        {
          if (attach_f <= frame)
          {
            v75 = v22 / attach_i;
            if (!(v22 % attach_i))
            {
              v76 = pHCardSpiral;
              v77 = pHCardSpiral->pAttach;
              else
              {
                v24 = v75;
                if (v75 >= LODWORD(v77->max_length))
                {
LABEL_83:
                }
              }
              dds3EffectPartSetColor(&v77->m_Items[v24], abgr1);
              SDF_VU0__LOADVECTOR(v76->param->pos);
              SDF_VU0__LOADVECTOR_B(dst);
              SDF_VU0__ADDVECTOR();
              SDF_VU0__STOREVECTOR(&dst);
              v79 = v76->pAttach;
              dds3EffectPartSetPosition(&v79->m_Items[v24], dst);
              v81 = v76->pAttach;
              dds3EffectPartDraw(&v81->m_Items[v24]);
              v21 = v101;
            }
          }
        }
      }
      v3 = pHCardSpiral;
      pHCardSpiral->hPoly->pVertex = pVertex;
      v3->hPoly->pVC = pVC;
      ++v108->frame;
      v23 = v106 + 6;
      ++v22;
      v107 += 6;
    }
    while (v22 != number);
  }
  p_fields = &v3->hPoly->fields;
  sub_854710(&v3->param->fields, 0);
  sub_854930(p_fields, 0);
  v84 = &v3->hPoly->fields;
  sub_854710(&v3->param->fields, 1u);
  sub_854930(v84, 1u);
  v85 = &v3->hPoly->fields;
  sub_854710(&v3->param->fields, 2u);
  sub_854930(v85, 2u);
  v87 = v3->hPoly;
  dds3ScatterPolyListDraw(v87);
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
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHamaCardSpiral_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPHamaCardSpiral_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[2].klass) = abgr;
}

// 0x175eb90
void effPCPHamaCardSpiralSetPosition(void **hData, sdfVector4_t pPos) {
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
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHamaCardSpiral_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPHamaCardSpiral_tag, v12);
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

// 0x175eda0
void effPCPHamaCardSpiralSetScale(void **hData, f32 scale) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  v5 = *hData;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHamaCardSpiral_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPHamaCardSpiral_tag, v10);
    if ((v10[0] & 1) != 0)
      v8 = v10[2];
    else
      v8 = v10 + 1;
    v9 = sub_8C4940(v8);
  }
  *(&v5[1].klass->_1.castClass + 1) = *(&v5[1].klass->_1.castClass + 1) * scale;
  *(&v5[1].klass->_1.parent + 1) = *(&v5[1].klass->_1.parent + 1) * scale;
  *&v5[1].klass->_1.generic_class = *&v5[1].klass->_1.generic_class * scale;
}

// 0x1765b90
effPCPWhirlwind2Poly_tag *effPCPWhirlwind2PolyCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  effPCPWhirlwind2PolyParam_t_o *v8;
  Il2CppObject *interfaceOffsets;
  effPCPWhirlwind2Poly_tag_o *result;
  char *v11;
  s64 *v12;
  u64 v13[3];

  v5 = *hData;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPWhirlwind2Poly_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPWhirlwind2Poly_tag, v13);
    if ((v13[0] & 1) != 0)
      v11 = v13[2];
    else
      v11 = v13 + 1;
    v12 = sub_8C4940(v11);
  }
  v8 = v5[5].klass;
  interfaceOffsets = v5[7].klass->_1.interfaceOffsets;
  result = effPCPWhirlwind2PolyCreate(v8, interfaceOffsets, tbldata);
  result->hPoly->pTexture = v5[7].klass->_1.interfaceOffsets;
  return result;
}

// 0x1765500
effPCPWhirlwind2Poly_tag *effPCPWhirlwind2PolyCreate(effPCPWhirlwind2PolyParam_t *pParam, void *pTex) {
  u64 *v5;
  u64 *v6;
  u64 *v7;
  u64 *v8;
  s64 v9;
  s64 v10;
  s64 v11;
  s64 v12;
  s64 v13;
  s64 v14;
  u32 split;
  u32 number;
  dds3WhirlwindPolyList_tag_o *v19;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v22;
  s64 *v23;
  u64 v24;
  s64 v25;
  s64 v26;
  u64 i;
  u32 *v29;
  u64 *v30;
  u64 v33;
  s64 v35;
  u32 v36;
  UnityEngine_Matrix4x4_o v38;
  u64 v39[3];

  v5 = Allocate(effPCPWhirlwind2Poly_tag);
  _ctor(v5, 0);
  v6 = Allocate(effPCPWhirlwind2PolyParam_t);
  effPCPWhirlwind2PolyParam_t___ctor(v6);
  v7 = v5 + 10;
  v5[10] = v6;
  effPCPWhirlwind2PolyParam_t__pClone(pParam, v5 + 10);
  v8 = NewSpecific(effPCPWhirlwind2PolyPart_tag, pParam->number);
  *(v5 + 26) = 0;
  v5[15] = 0;
  v5[11] = v8;
  v5[12] = 0x808080803F800000LL;
  v9 = *&pParam->matrix.m00;
  v10 = *&pParam->matrix.m20;
  v11 = *&pParam->matrix.m21;
  *&v38.m01 = *&pParam->matrix.m01;
  *&v38.m21 = v11;
  *&v38.m00 = v9;
  *&v38.m20 = v10;
  v12 = *&pParam->matrix.m02;
  v13 = *&pParam->matrix.m22;
  v14 = *&pParam->matrix.m23;
  *&v38.m03 = *&pParam->matrix.m03;
  *&v38.m23 = v14;
  *&v38.m02 = v12;
  *&v38.m22 = v13;
  SDF_VU0__LOADMATRIX(&v38);
  SDF_VU0__STOREMATRIX((v5 + 2), 0);
  number = pParam->number;
  split = pParam->split;
  v19 = dds3WhirlwindPolyListCreate(number, split);
  v5[14] = v19;
  v19->blend = pParam->blend;
  if (pTex)
  {
    klass = pTex->klass;
    if (pTex->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != UnityEngine_Texture)
    {
      sub_8FC2C0(klass->_1.element_class, UnityEngine_Texture, v39);
      if ((v39[0] & 1) != 0)
        v22 = v39[2];
      else
        v22 = v39 + 1;
      v23 = sub_8C4940(v22);
    }
    *(v5[14] + 176) = pTex;
  }
  v24 = *v7;
  if (*(*v7 + 116) <= 0)
  {
    *(v24 + 116) = 1;
    v24 = *v7;
  }
  v25 = *(v24 + 108);
  if (v25)
  {
    v26 = *(v24 + 116);
    for (i = 0; i != v25; ++i)
    {
      v29 = v5[11];
      v30 = Allocate(effPCPWhirlwind2PolyPart_tag);
      _ctor(v30, 0);
      *&v29[2 * i + 8] = v30;
      v33 = v5[11];
      v35 = *(v33 + 8 * i + 32);
      v36 = DDS3EFFECT_RAND_I();
      *(v35 + 24) = v36 / v26 * v26 - v36;
    }
  }
  return v5;
}

// 0x1765820
effPCPWhirlwind2Poly_tag *effPCPWhirlwind2PolyCreatePCF(void **hData, s32 bPos, bool tbldata) {
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
  struct dds3EffectPCPData_Part_t_array *v19;
  Il2CppObject *v20;
  u32 v22;
  s32 TmxIndex;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  effPCPWhirlwind2PolyParam_t_o *v28;
  char *v29;
  s64 *v30;
  Il2CppObject *Texture;
  Il2CppClass *v32;
  s64 v33;
  char *v34;
  s64 *v35;
  s32 pos;
  u64 v38[2];
  char *v39;

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v7->klass->_1.element_class, v8, v38);
      if ((v38[0] & 1) != 0)
        v10 = v39;
      else
        v10 = v38 + 1;
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
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 33);
  v19 = v6->pcpData;
  v20 = DataUnityOffSet;
  v22 = v19->m_Items[1]->offset;
  TmxIndex = GetTmxIndex(Interface, v22 + bPos);
  if (v20)
  {
    klass = v20->klass;
    if (v20->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || (v28 = v20, klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPWhirlwind2PolyParam_t))
    {
      sub_8FC2C0(klass->_1.element_class, effPCPWhirlwind2PolyParam_t, v38);
      if ((v38[0] & 1) != 0)
        v29 = v39;
      else
        v29 = v38 + 1;
      v30 = sub_8C4940(v29);
    }
  }
  else
  {
    v28 = 0;
  }
  if (TmxIndex < 0)
  {
    if (v20)
    {
      v32 = v20->klass;
      if (v20->klass->_2.typeHierarchyDepth < v33
        || v32->_2.typeHierarchy[v33 - 1] != effPCPWhirlwind2PolyParam_t)
      {
        sub_8FC2C0(v32->_1.element_class, effPCPWhirlwind2PolyParam_t, v38);
        if ((v38[0] & 1) != 0)
          v34 = v39;
        else
          v34 = v38 + 1;
        v35 = sub_8C4940(v34);
      }
      Texture = 0;
      v28 = v20;
    }
    else
    {
      v28 = 0;
      Texture = 0;
    }
  }
  else
  {
    Texture = billGetTexture(TmxIndex);
  }
  return effPCPWhirlwind2PolyCreate(v28, Texture);
}

// 0x1765cc0
void effPCPWhirlwind2PolyDelete(void **hData) {
  effPCPWhirlwind2Poly_tag_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v6;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPWhirlwind2Poly_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPWhirlwind2Poly_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  v6 = (*hData)[7].klass;
  dds3WhirlwindPolyListDelete(v6, v3);
}

// 0x1766810
void effPCPWhirlwind2PolyDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppClass *v8;
  s32 typeDefinition;
  s64 typeDefinition_high;
  s32 v11;
  s32 klass_high;
  s32 v13;
  s64 interopData_high;
  u32 v15;
  s32 monitor;
  s32 v19;
  f32 v20;
  u64 v21;
  bool v22;
  u64 *v23;
  s64 v25;
  s32 v26;
  struct System_UInt32_array *pABGR;
  f32 v29;
  u32 v30;
  struct System_UInt32_array *v33;
  u32 v35;
  s32 v37;
  dds3WhirlwindPolyList_tag_o *v38;
  s32 v41;
  s32 v42;
  u32 v43;
  UnityEngine_Matrix4x4_o v44;
  dds3WhirlwindPolyList_tag_o *hPoly;
  UnityEngine_Matrix4x4_o v46;
  effPCPWhirlwind2Poly_tag_o *pWhirlwind2Poly;

  pWhirlwind2Poly = 0;
  hPoly = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPWhirlwind2Poly_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPWhirlwind2Poly_tag, &v46);
      if ((LOBYTE(v46.m00) & 1) != 0)
        v6 = *&v46.m01;
      else
        v6 = &v46.m00 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  pWhirlwind2Poly = *hData;
  hPoly = v3[7].klass;
  v8 = v3[5].klass;
  typeDefinition = v8->_1.typeDefinition;
  typeDefinition_high = HIDWORD(v8->_1.typeDefinition);
  v11 = BYTE4(v8->_1.generic_class);
  klass_high = HIDWORD(v8->_1.klass);
  v13 = v8->_1.klass;
  interopData_high = SHIDWORD(v8->_1.interopData);
  v15 = effColorMultiply(HIDWORD(v3[6].klass), v8->rgctx_data, 0);
  monitor = v3[6].monitor;
  v19 = typeDefinition - monitor;
  v43 = v15;
  if (typeDefinition >= monitor)
  {
    v20 = 1.0;
    v41 = v3[6].monitor;
    v42 = v11;
    if (klass_high && v19 <= klass_high)
      v20 = v19 / klass_high;
    if (typeDefinition_high)
    {
      v21 = 0;
      v22 = v11 == 0 || typeDefinition > monitor;
      do
      {
        while (1)
        {
          while (1)
          {
            v23 = v3[5].monitor;
            v25 = v23[v21 + 4];
            v26 = *(v25 + 24);
            if (v26 <= typeDefinition)
              break;
            pABGR = hPoly->pABGR;
            pABGR->m_Items[v21++] = 0;
            if (typeDefinition_high == v21)
              goto LABEL_47;
          }
          if (!v26)
            break;
          if (v26 >= 1)
          {
            v29 = 1.0;
            if (v13)
            {
              v29 = 1.0;
              if (v26 < v13)
                v29 = v26 / v13;
            }
            v30 = effColorBlend(v43 & 0xFFFFFF, v43, v20 * v29);
            v33 = hPoly->pABGR;
            v33->m_Items[v21] = v30;
            effPCPWhirlwind2PolyPartMove(&pWhirlwind2Poly, v21);
          }
          if (v22)
            goto LABEL_35;
LABEL_40:
          v35 = DDS3EFFECT_RAND_I();
          *(v25 + 24) = v35 / interopData_high * interopData_high - v35;
          if (typeDefinition_high == ++v21)
            goto LABEL_47;
        }
        else
        {
          effPCPWhirlwind2PolyPartInit(&pWhirlwind2Poly, v21);
          if (!v22)
            goto LABEL_40;
        }
LABEL_35:
        ++*(v25 + 24);
        ++v21;
      }
      while (typeDefinition_high != v21);
    }
LABEL_47:
    if (v42 && typeDefinition <= v41)
      v37 = 0;
    else
      v37 = LODWORD(v3[6].monitor) + 1;
    LODWORD(v3[6].monitor) = v37;
    v38 = hPoly;
    hPoly->scale = *&v3[6].klass;
    SDF_VU0__COPYVECTOR(&v38->pos, *&v3[5].klass->_1.name);
    v44 = *&v3[1].klass;
    v46 = v44;
    SDF_VU0__LOADMATRIX(&v46);
    SDF_VU0__STOREMATRIX(&v38->matrix);
    dds3WhirlwindPolyListDraw(&hPoly, "effPCPWhirlwind2PolyDraw");
  }
}

// 0x1765dd0
void effPCPWhirlwind2PolyPartInit(effPCPWhirlwind2Poly_tag **pWhirlwind2Poly, s32 index) {
  struct effPCPWhirlwind2PolyPart_tag_array *pPart;
  struct dds3WhirlwindPolyList_tag_o *hPoly;
  u32 point;
  struct UnityEngine_Vector4_array *pVertex;
  struct UnityEngine_Vector2_array *pUV;
  f32 *v11;
  u32 v12;
  f32 v13;
  struct effPCPWhirlwind2PolyParam_t_o *param;
  f32 v15;
  f32 radian_w;
  f32 v17;
  struct effPCPWhirlwind2PolyParam_t_o *v18;
  f32 v19;
  f32 radius;
  f32 v21;
  f32 v22;
  struct effPCPWhirlwind2PolyParam_t_o *v23;
  f32 v24;
  f32 width;
  f32 v26;
  struct effPCPWhirlwind2PolyParam_t_o *v27;
  f32 v28;
  f32 radius_s;
  f32 incline;
  f32 v32;
  u64 v34;
  u64 v35;
  struct effPCPWhirlwind2PolyParam_t_o *v36;
  u32 v37;
  f32 v38;
  f32 v39;
  f32 v40;
  f32 v41;
  f32 v42;
  s64 v43;
  UnityEngine_Vector4_o *v44;
  u32 v49;
  f32 v63;
  f32 radian_w_u;

  pPart = (*pWhirlwind2Poly)->pPart;
  hPoly = (*pWhirlwind2Poly)->hPoly;
  point = hPoly->point;
  pVertex = hPoly->pVertex;
  pUV = hPoly->pUV;
  v11 = pPart->m_Items[index];
  v12 = point >> 1;
  v13 = DDS3EFFECT_RAND_F();
  param = (*pWhirlwind2Poly)->param;
  v15 = v13 * 6.2832;
  radian_w = param->radian_w;
  v17 = radian_w * DDS3EFFECT_RAND_FA(param->radian_w_r);
  v18 = (*pWhirlwind2Poly)->param;
  v19 = v12;
  radian_w_u = v18->radian_w_u;
  radius = v18->radius;
  v21 = v17 / v19;
  v22 = DDS3EFFECT_RAND_FA(v18->radius_r);
  v23 = (*pWhirlwind2Poly)->param;
  v24 = radius * v22;
  width = v23->width;
  v26 = DDS3EFFECT_RAND_FA(v23->width_r);
  v27 = (*pWhirlwind2Poly)->param;
  v28 = width * v26;
  radius_s = v27->radius_s;
  v11[12] = radius_s * DDS3EFFECT_RAND_FA(v27->radius_s_r);
  incline = (*pWhirlwind2Poly)->param->incline;
  v32 = incline * DDS3EFFECT_RAND_F();
  v11[4] = v32;
  v11[5] = 0.0;
  v11[8] = v15;
  v63 = v21;
  v11[10] = v21;
  v11[11] = v24;
  v11[13] = v28;
  v11[9] = (*pWhirlwind2Poly)->param->roll_s;
  v11[7] = (*pWhirlwind2Poly)->param->up_s;
  SetRotateMatrixX(v32);
  SetRotateMatrixY_B(v11[5]);
  MultMatrixRevNoArg();
  if (v12)
  {
    v36 = (*pWhirlwind2Poly)->param;
    v37 = point * index;
    LODWORD(v34) = v36->repeat_u;
    LODWORD(v35) = v36->repeat_v;
    v38 = 0.0;
    v39 = v35;
    v40 = v34;
    v41 = v40 / v19;
    v42 = 0.0;
    v43 = &pUV->m_Items[point * index];
    v44 = &pVertex->m_Items[v37];
    do
    {
      sdfCos(v15);
      sub_854930(v44, 0);
      sub_854930(v44, 1u);
      sdfSin(v15);
      sub_854930(v44, 2u);
      sub_854710(v44, 0);
      v49 = v37 + 1;
      sub_854930(&v44[1], 0);
      sub_854710(v44, 1u);
      sub_854930(&v44[1], 1u);
      sub_854710(v44, 2u);
      sub_854930(&v44[1], 2u);
      SDF_VU0__LOADVECTOR(*v44);
      SDF_VU0__APPLYMATRIX();
      SDF_VU0__STOREVECTOR(v44);
      SDF_VU0__LOADVECTOR(v44[1]);
      SDF_VU0__APPLYMATRIX();
      SDF_VU0__STOREVECTOR(v44 + 1);
      sub_8518D0(v43, 0, v42);
      sub_8518D0(v43, 1, 0.0);
      sub_8518D0(v43 + 8, 0, v42);
      sub_8518D0(v43 + 8, 1, v39);
      v38 = radian_w_u + v38;
      v42 = v41 + v42;
      v43 += 16;
      --v12;
      v37 += 2;
      v44 += 2;
      v15 = v63 + v15;
    }
    while (v12);
  }
}

// 0x17663d0
void effPCPWhirlwind2PolyPartMove(effPCPWhirlwind2Poly_tag **pWhirlwind2Poly, s32 index) {
  struct effPCPWhirlwind2PolyPart_tag_array *pPart;
  struct dds3WhirlwindPolyList_tag_o *hPoly;
  s32 point;
  struct UnityEngine_Vector4_array *pVertex;
  effPCPWhirlwind2PolyPart_tag_o *v10;
  s32 v11;
  f32 radian;
  f32 up_s;
  f32 radian_add;
  f32 rot_x;
  f32 v16;
  f32 radian_s;
  f32 roll_a;
  u32 v20;
  UnityEngine_Vector4_o *v21;
  u32 v26;

  pPart = (*pWhirlwind2Poly)->pPart;
  hPoly = (*pWhirlwind2Poly)->hPoly;
  point = hPoly->point;
  pVertex = hPoly->pVertex;
  v10 = pPart->m_Items[index];
  v11 = point >> 1;
  up_s = v10->up_s;
  radian = v10->radian;
  radian_add = v10->radian_add;
  rot_x = v10->rot_x;
  v16 = v10->radius + v10->radius_s;
  SetRotateMatrixX(rot_x);
  SetRotateMatrixY_B(v10->rot_y);
  MultMatrixRevNoArg();
  radian_s = v10->radian_s;
  v10->rot_y = v10->rot_y + radian_s;
  roll_a = (*pWhirlwind2Poly)->param->roll_a;
  v10->radius = v16;
  v10->radian_s = radian_s * roll_a;
  v10->radius_s = v10->radius_s * (*pWhirlwind2Poly)->param->radius_a;
  v10->up_s = up_s * (*pWhirlwind2Poly)->param->up_a;
  if (v11)
  {
    v20 = point * index;
    v21 = &pVertex->m_Items[v20];
    do
    {
      sdfCos(radian);
      sub_854930(v21, 0);
      sub_854710(v21, 1u);
      sub_854930(v21, 1u);
      sdfSin(radian);
      sub_854930(v21, 2u);
      sub_854710(v21, 0);
      v26 = v20 + 1;
      sub_854930(&v21[1], 0);
      sub_854710(&v21[1], 1u);
      sub_854930(&v21[1], 1u);
      sub_854710(v21, 2u);
      sub_854930(&v21[1], 2u);
      SDF_VU0__LOADVECTOR(*v21);
      SDF_VU0__APPLYMATRIX();
      SDF_VU0__STOREVECTOR(v21);
      SDF_VU0__LOADVECTOR(v21[1]);
      SDF_VU0__APPLYMATRIX();
      SDF_VU0__STOREVECTOR(v21 + 1);
      radian = radian_add + radian;
      --v11;
      v20 += 2;
      v21 += 2;
    }
    while (v11);
  }
}

// 0x1766e70
void effPCPWhirlwind2PolySetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPWhirlwind2Poly_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPWhirlwind2Poly_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[6].klass) = abgr;
}

// 0x1766c60
void effPCPWhirlwind2PolySetPosition(void **hData, sdfVector4_t pPos) {
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
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPWhirlwind2Poly_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPWhirlwind2Poly_tag, v12);
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
  SDF_VU0__COPYVECTOR(&(*hData)[5].klass->_1.name, v13, 0);
}

// 0x1766f60
void effPCPWhirlwind2PolySetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
  s64 v5;
  s64 v6;
  Il2CppObject *v7;
  s64 v8;
  s64 v9;
  s64 v10;
  s64 v11;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v14;
  s64 *v15;
  UnityEngine_Matrix4x4_o dest;
  UnityEngine_Matrix4x4_o v18;
  u64 v19[3];

  v5 = *&pMatrix->m00;
  v6 = *&pMatrix->m20;
  v7 = *hData;
  v8 = *&pMatrix->m21;
  *&v18.m01 = *&pMatrix->m01;
  *&v18.m21 = v8;
  *&v18.m00 = v5;
  *&v18.m20 = v6;
  v9 = *&pMatrix->m02;
  v10 = *&pMatrix->m22;
  v11 = *&pMatrix->m23;
  *&v18.m03 = *&pMatrix->m03;
  *&v18.m23 = v11;
  *&v18.m02 = v9;
  *&v18.m22 = v10;
  SDF_VU0__LOADMATRIX(&v18);
  if (v7)
  {
    klass = v7->klass;
    if (v7->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPWhirlwind2Poly_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPWhirlwind2Poly_tag, v19);
      if ((v19[0] & 1) != 0)
        v14 = v19[2];
      else
        v14 = v19 + 1;
      v15 = sub_8C4940(v14);
    }
  }
  memmove(&dest, &v7[5].klass->_1.byval_arg, 0x40u);
  SDF_VU0__LOADMATRIX_B(&dest);
  MultMatrixNoArg();
  SDF_VU0__STOREMATRIX(&v7[1]);
}

// 0x1766d80
void effPCPWhirlwind2PolySetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPWhirlwind2Poly_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPWhirlwind2Poly_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *&(*hData)[6].klass = scale;
}

// 0x1767770
effPCPWhirlwind3Poly_tag *effPCPWhirlwind3PolyCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  effPCPWhirlwind3PolyParam_t_o *v8;
  Il2CppObject *interfaceOffsets;
  effPCPWhirlwind3Poly_tag_o *result;
  char *v11;
  s64 *v12;
  u64 v13[3];

  v5 = *hData;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPWhirlwind3Poly_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPWhirlwind3Poly_tag, v13);
    if ((v13[0] & 1) != 0)
      v11 = v13[2];
    else
      v11 = v13 + 1;
    v12 = sub_8C4940(v11);
  }
  v8 = v5[5].klass;
  interfaceOffsets = v5[7].klass->_1.interfaceOffsets;
  result = effPCPWhirlwind3PolyCreate(v8, interfaceOffsets, tbldata);
  result->hPoly->pTexture = v5[7].klass->_1.interfaceOffsets;
  return result;
}

// 0x17670e0
effPCPWhirlwind3Poly_tag *effPCPWhirlwind3PolyCreate(effPCPWhirlwind3PolyParam_t *pParam, void *pTex) {
  u64 *v5;
  u64 *v6;
  u64 *v7;
  u64 *v8;
  s64 v9;
  s64 v10;
  s64 v11;
  s64 v12;
  s64 v13;
  s64 v14;
  u32 split;
  u32 number;
  dds3WhirlwindPolyList_tag_o *v19;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v22;
  s64 *v23;
  u64 v24;
  s64 v25;
  s64 v26;
  u64 i;
  u32 *v29;
  u64 *v30;
  u64 v33;
  s64 v35;
  u32 v36;
  UnityEngine_Matrix4x4_o v38;
  u64 v39[3];

  v5 = Allocate(effPCPWhirlwind3Poly_tag);
  _ctor(v5, 0);
  v6 = Allocate(effPCPWhirlwind3PolyParam_t);
  effPCPWhirlwind3PolyParam_t___ctor(v6);
  v7 = v5 + 10;
  v5[10] = v6;
  effPCPWhirlwind3PolyParam_t__pClone(pParam, v5 + 10);
  v8 = NewSpecific(effPCPWhirlwind3PolyPart_tag, pParam->number);
  *(v5 + 26) = 0;
  v5[15] = 0;
  v5[11] = v8;
  v5[12] = 0x808080803F800000LL;
  v9 = *&pParam->matrix.m00;
  v10 = *&pParam->matrix.m20;
  v11 = *&pParam->matrix.m21;
  *&v38.m01 = *&pParam->matrix.m01;
  *&v38.m21 = v11;
  *&v38.m00 = v9;
  *&v38.m20 = v10;
  v12 = *&pParam->matrix.m02;
  v13 = *&pParam->matrix.m22;
  v14 = *&pParam->matrix.m23;
  *&v38.m03 = *&pParam->matrix.m03;
  *&v38.m23 = v14;
  *&v38.m02 = v12;
  *&v38.m22 = v13;
  SDF_VU0__LOADMATRIX(&v38);
  SDF_VU0__STOREMATRIX((v5 + 2), 0);
  number = pParam->number;
  split = pParam->split;
  v19 = dds3WhirlwindPolyListCreate(number, split);
  v5[14] = v19;
  v19->blend = pParam->blend;
  if (pTex)
  {
    klass = pTex->klass;
    if (pTex->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != UnityEngine_Texture)
    {
      sub_8FC2C0(klass->_1.element_class, UnityEngine_Texture, v39);
      if ((v39[0] & 1) != 0)
        v22 = v39[2];
      else
        v22 = v39 + 1;
      v23 = sub_8C4940(v22);
    }
    *(v5[14] + 176) = pTex;
  }
  v24 = *v7;
  if (*(*v7 + 116) <= 0)
  {
    *(v24 + 116) = 1;
    v24 = *v7;
  }
  v25 = *(v24 + 108);
  if (v25)
  {
    v26 = *(v24 + 116);
    for (i = 0; i != v25; ++i)
    {
      v29 = v5[11];
      v30 = Allocate(effPCPWhirlwind3PolyPart_tag);
      _ctor(v30, 0);
      *&v29[2 * i + 8] = v30;
      v33 = v5[11];
      v35 = *(v33 + 8 * i + 32);
      v36 = DDS3EFFECT_RAND_I();
      *(v35 + 24) = v36 / v26 * v26 - v36;
    }
  }
  return v5;
}

// 0x1767400
effPCPWhirlwind3Poly_tag *effPCPWhirlwind3PolyCreatePCF(void **hData, s32 bPos, bool tbldata) {
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
  struct dds3EffectPCPData_Part_t_array *v19;
  Il2CppObject *v20;
  u32 v22;
  s32 TmxIndex;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  effPCPWhirlwind3PolyParam_t_o *v28;
  char *v29;
  s64 *v30;
  Il2CppObject *Texture;
  Il2CppClass *v32;
  s64 v33;
  char *v34;
  s64 *v35;
  s32 pos;
  u64 v38[2];
  char *v39;

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v7->klass->_1.element_class, v8, v38);
      if ((v38[0] & 1) != 0)
        v10 = v39;
      else
        v10 = v38 + 1;
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
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 34);
  v19 = v6->pcpData;
  v20 = DataUnityOffSet;
  v22 = v19->m_Items[1]->offset;
  TmxIndex = GetTmxIndex(Interface, v22 + bPos);
  if (v20)
  {
    klass = v20->klass;
    if (v20->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || (v28 = v20, klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPWhirlwind3PolyParam_t))
    {
      sub_8FC2C0(klass->_1.element_class, effPCPWhirlwind3PolyParam_t, v38);
      if ((v38[0] & 1) != 0)
        v29 = v39;
      else
        v29 = v38 + 1;
      v30 = sub_8C4940(v29);
    }
  }
  else
  {
    v28 = 0;
  }
  if (TmxIndex < 0)
  {
    if (v20)
    {
      v32 = v20->klass;
      if (v20->klass->_2.typeHierarchyDepth < v33
        || v32->_2.typeHierarchy[v33 - 1] != effPCPWhirlwind3PolyParam_t)
      {
        sub_8FC2C0(v32->_1.element_class, effPCPWhirlwind3PolyParam_t, v38);
        if ((v38[0] & 1) != 0)
          v34 = v39;
        else
          v34 = v38 + 1;
        v35 = sub_8C4940(v34);
      }
      Texture = 0;
      v28 = v20;
    }
    else
    {
      v28 = 0;
      Texture = 0;
    }
  }
  else
  {
    Texture = billGetTexture(TmxIndex);
  }
  return effPCPWhirlwind3PolyCreate(v28, Texture);
}

// 0x17678a0
void effPCPWhirlwind3PolyDelete(void **hData) {
  effPCPWhirlwind3Poly_tag_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v6;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPWhirlwind3Poly_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPWhirlwind3Poly_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  v6 = (*hData)[7].klass;
  dds3WhirlwindPolyListDelete(v6, v3);
}

// 0x1768410
void effPCPWhirlwind3PolyDraw(void **hData) {
  dds3WhirlwindPolyList_tag_o **v4;
  dds3WhirlwindPolyList_tag_o *v5;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  dds3WhirlwindPolyList_tag_o *v9;
  s32 number;
  s32 v11;
  s32 v12;
  s64 point;
  f32 v14;
  s32 pVertex;
  s64 v16;
  s32 pVertex_high;
  u64 v18;
  bool v19;
  dds3WhirlwindPolyList_tag_o *v20;
  s64 v22;
  s32 v23;
  struct System_UInt32_array *pABGR;
  u32 v26;
  f32 v28;
  u32 v29;
  struct System_UInt32_array *v30;
  u32 v33;
  s32 v35;
  u32 v36;
  s32 v38;
  dds3WhirlwindPolyList_tag_o *v39;
  s32 v42;
  s32 abgr_low;
  u32 abgr0;
  u32 monitor;
  u32 klass_high;
  struct UnityEngine_Matrix4x4_o matrix;
  dds3WhirlwindPolyList_tag_o *hPoly;
  UnityEngine_Matrix4x4_o v49;
  effPCPWhirlwind3Poly_tag_o *pWhirlwind3Poly;

  pWhirlwind3Poly = 0;
  hPoly = 0;
  v4 = *hData;
  if (*hData)
  {
    v5 = *v4;
    if (LOBYTE((*v4)[1].blend) < typeHierarchyDepth
      || *(v5[1].monitor + typeHierarchyDepth - 1) != effPCPWhirlwind3Poly_tag)
    {
      sub_8FC2C0(*&v5->matrix.m02, effPCPWhirlwind3Poly_tag, &v49);
      if ((LOBYTE(v49.m00) & 1) != 0)
        v7 = *&v49.m01;
      else
        v7 = &v49.m00 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  pWhirlwind3Poly = *hData;
  hPoly = v4[14];
  v9 = v4[10];
  number = v9->number;
  v11 = *(v4 + 26);
  v12 = number - v11;
  if (number >= v11)
  {
    point = v9->point;
    v14 = 1.0;
    pVertex = v9->pVertex;
    v16 = *(&v9->scale + 1);
    pVertex_high = HIDWORD(v9->pVertex);
    monitor = v9[1].monitor;
    klass_high = HIDWORD(v9[1].klass);
    abgr0 = *(v4 + 25);
    if (pVertex_high && v12 <= pVertex_high)
      v14 = v12 / pVertex_high;
    v42 = *(v4 + 26);
    abgr_low = LOBYTE(v9->abgr);
    if (point)
    {
      v18 = 0;
      v19 = LOBYTE(v9->abgr) == 0 || number > v11;
      do
      {
        while (1)
        {
          v20 = v4[11];
          v22 = *(&v20->matrix.m00 + v18);
          v23 = *(v22 + 24);
          if (v23 <= number)
            break;
          pABGR = hPoly->pABGR;
          pABGR->m_Items[v18] = 0;
          v4 = pWhirlwind3Poly;
          if (point == ++v18)
            goto LABEL_50;
        }
        if (v23)
        {
          if (v23 >= 1)
          {
            v26 = effColorBlend(klass_high, monitor, v23 / number);
            if (v23 >= pVertex || pVertex == 0)
              v28 = 1.0;
            else
              v28 = v23 / pVertex;
            v29 = effColorMultiply(abgr0, v26);
            v30 = hPoly->pABGR;
            v33 = effColorBlend(v29 & 0xFFFFFF, v29, v14 * v28);
            v30->m_Items[v18] = v33;
            effPCPWhirlwind3PolyPartMove(&pWhirlwind3Poly, v18);
          }
          if (!v19)
          {
LABEL_42:
            v36 = DDS3EFFECT_RAND_I();
            v35 = v36 / v16 * v16 - v36;
            goto LABEL_46;
          }
        }
        {
          effPCPWhirlwind3PolyPartInit(&pWhirlwind3Poly, v18);
          if (!v19)
            goto LABEL_42;
        }
        else
        {
          effPCPWhirlwind3PolyPartInit(&pWhirlwind3Poly, v18);
          if (!v19)
            goto LABEL_42;
        }
        v35 = *(v22 + 24) + 1;
LABEL_46:
        *(v22 + 24) = v35;
        v4 = pWhirlwind3Poly;
        ++v18;
      }
      while (point != v18);
    }
LABEL_50:
    if (abgr_low && number <= v42)
      v38 = 0;
    else
      v38 = *(v4 + 26) + 1;
    *(v4 + 26) = v38;
    v39 = hPoly;
    hPoly->scale = *(v4 + 24);
    SDF_VU0__COPYVECTOR(&v39->pos, v4[10]->pos);
    matrix = pWhirlwind3Poly->matrix;
    v49 = matrix;
    SDF_VU0__LOADMATRIX(&v49);
    SDF_VU0__STOREMATRIX(&v39->matrix);
    dds3WhirlwindPolyListDraw(&hPoly, "effPCPWhirlwind3PolyDraw");
  }
}

// 0x17679b0
void effPCPWhirlwind3PolyPartInit(effPCPWhirlwind3Poly_tag **pWhirlwind3Poly, s32 index) {
  struct effPCPWhirlwind3PolyPart_tag_array *pPart;
  struct dds3WhirlwindPolyList_tag_o *hPoly;
  s32 point;
  struct UnityEngine_Vector4_array *pVertex;
  struct UnityEngine_Vector2_array *pUV;
  Il2CppClass **v11;
  u32 v12;
  f32 *v13;
  f32 v14;
  struct effPCPWhirlwind3PolyParam_t_o *param;
  f32 v16;
  f32 radian_w;
  f32 v18;
  struct effPCPWhirlwind3PolyParam_t_o *v19;
  f32 v20;
  f32 radius;
  f32 v22;
  f32 v23;
  struct effPCPWhirlwind3PolyParam_t_o *v24;
  f32 v25;
  f32 width;
  f32 v27;
  struct effPCPWhirlwind3PolyParam_t_o *v28;
  f32 v29;
  f32 radius_s;
  f32 incline;
  f32 v33;
  struct effPCPWhirlwind3PolyParam_t_o *v34;
  s64 number;
  f32 slant;
  u64 v38;
  u64 v39;
  u32 v40;
  struct effPCPWhirlwind3PolyParam_t_o *v41;
  UnityEngine_Vector4_o *v42;
  s64 v43;
  f32 v44;
  f32 v45;
  f32 v46;
  f32 v47;
  u32 v52;

  pPart = (*pWhirlwind3Poly)->pPart;
  hPoly = (*pWhirlwind3Poly)->hPoly;
  point = hPoly->point;
  pVertex = hPoly->pVertex;
  pUV = hPoly->pUV;
  v11 = &pPart->obj.klass + index;
  v12 = point >> 1;
  v13 = v11[4];
  v14 = DDS3EFFECT_RAND_F();
  param = (*pWhirlwind3Poly)->param;
  v16 = v14 * 6.2832;
  radian_w = param->radian_w;
  v18 = radian_w * DDS3EFFECT_RAND_FA(param->radian_w_r);
  v19 = (*pWhirlwind3Poly)->param;
  v20 = v12;
  radius = v19->radius;
  v22 = v18 / v20;
  v23 = DDS3EFFECT_RAND_FA(v19->radius_r);
  v24 = (*pWhirlwind3Poly)->param;
  v25 = radius * v23;
  width = v24->width;
  v27 = DDS3EFFECT_RAND_FA(v24->width_r);
  v28 = (*pWhirlwind3Poly)->param;
  v29 = width * v27;
  radius_s = v28->radius_s;
  v13[12] = radius_s * DDS3EFFECT_RAND_FA(v28->radius_s_r);
  incline = (*pWhirlwind3Poly)->param->incline;
  v33 = incline * DDS3EFFECT_RAND_F();
  v13[4] = v33;
  v13[5] = 0.0;
  v34 = (*pWhirlwind3Poly)->param;
  number = v34->number;
  slant = v34->slant;
  v13[8] = v16;
  v13[13] = v29;
  v13[10] = v22;
  v13[11] = v25 + (slant * (number - index));
  v13[9] = (*pWhirlwind3Poly)->param->roll_s;
  v13[7] = (*pWhirlwind3Poly)->param->up_s;
  SetRotateMatrixX(v33);
  SetRotateMatrixY_B(v13[5]);
  MultMatrixRevNoArg();
  if (v12)
  {
    v40 = point * index;
    v41 = (*pWhirlwind3Poly)->param;
    v42 = &pVertex->m_Items[point * index];
    LODWORD(v38) = v41->repeat_u;
    LODWORD(v39) = v41->repeat_v;
    v43 = &pUV->m_Items[point * index];
    v44 = v39;
    v45 = v38;
    v46 = v45 / v20;
    v47 = 0.0;
    do
    {
      sdfCos(v16);
      sub_854930(v42, 0);
      sub_854930(v42, 1u);
      sdfSin(v16);
      sub_854930(v42, 2u);
      sub_854710(v42, 0);
      v52 = v40 + 1;
      sub_854930(&v42[1], 0);
      sub_854710(v42, 1u);
      sub_854930(&v42[1], 1u);
      sub_854710(v42, 2u);
      sub_854930(&v42[1], 2u);
      SDF_VU0__LOADVECTOR(*v42);
      SDF_VU0__APPLYMATRIX();
      SDF_VU0__STOREVECTOR(v42);
      SDF_VU0__LOADVECTOR(v42[1]);
      SDF_VU0__APPLYMATRIX();
      SDF_VU0__STOREVECTOR(v42 + 1);
      sub_8518D0(v43, 0, v47);
      sub_8518D0(v43, 1, 0.0);
      sub_8518D0(v43 + 8, 0, v47);
      sub_8518D0(v43 + 8, 1, v44);
      v47 = v46 + v47;
      v43 += 16;
      --v12;
      v40 += 2;
      v42 += 2;
      v16 = v22 + v16;
    }
    while (v12);
  }
}

// 0x1767fd0
void effPCPWhirlwind3PolyPartMove(effPCPWhirlwind3Poly_tag **pWhirlwind3Poly, s32 index) {
  struct effPCPWhirlwind3PolyPart_tag_array *pPart;
  struct dds3WhirlwindPolyList_tag_o *hPoly;
  s32 point;
  struct UnityEngine_Vector4_array *pVertex;
  effPCPWhirlwind3PolyPart_tag_o *v10;
  s32 v11;
  f32 radian;
  f32 up_s;
  f32 radian_add;
  f32 rot_x;
  f32 v16;
  f32 radian_s;
  f32 roll_a;
  u32 v20;
  UnityEngine_Vector4_o *v21;
  u32 v26;

  pPart = (*pWhirlwind3Poly)->pPart;
  hPoly = (*pWhirlwind3Poly)->hPoly;
  point = hPoly->point;
  pVertex = hPoly->pVertex;
  v10 = pPart->m_Items[index];
  v11 = point >> 1;
  up_s = v10->up_s;
  radian = v10->radian;
  radian_add = v10->radian_add;
  rot_x = v10->rot_x;
  v16 = v10->radius + v10->radius_s;
  SetRotateMatrixX(rot_x);
  SetRotateMatrixY_B(v10->rot_y);
  MultMatrixRevNoArg();
  radian_s = v10->radian_s;
  v10->rot_y = v10->rot_y + radian_s;
  roll_a = (*pWhirlwind3Poly)->param->roll_a;
  v10->radius = v16;
  v10->radian_s = radian_s * roll_a;
  v10->radius_s = v10->radius_s * (*pWhirlwind3Poly)->param->radius_a;
  v10->up_s = up_s * (*pWhirlwind3Poly)->param->up_a;
  if (v11)
  {
    v20 = point * index;
    v21 = &pVertex->m_Items[v20];
    do
    {
      sdfCos(radian);
      sub_854930(v21, 0);
      sub_854710(v21, 1u);
      sub_854930(v21, 1u);
      sdfSin(radian);
      sub_854930(v21, 2u);
      sub_854710(v21, 0);
      v26 = v20 + 1;
      sub_854930(&v21[1], 0);
      sub_854710(&v21[1], 1u);
      sub_854930(&v21[1], 1u);
      sub_854710(v21, 2u);
      sub_854930(&v21[1], 2u);
      SDF_VU0__LOADVECTOR(*v21);
      SDF_VU0__APPLYMATRIX();
      SDF_VU0__STOREVECTOR(v21);
      SDF_VU0__LOADVECTOR(v21[1]);
      SDF_VU0__APPLYMATRIX();
      SDF_VU0__STOREVECTOR(v21 + 1);
      radian = radian_add + radian;
      --v11;
      v20 += 2;
      v21 += 2;
    }
    while (v11);
  }
}

// 0x1768a80
void effPCPWhirlwind3PolySetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPWhirlwind3Poly_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPWhirlwind3Poly_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[6].klass) = abgr;
}

// 0x1768870
void effPCPWhirlwind3PolySetPosition(void **hData, sdfVector4_t pPos) {
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
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPWhirlwind3Poly_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPWhirlwind3Poly_tag, v12);
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
  SDF_VU0__COPYVECTOR(&(*hData)[5].klass->_1.name, v13, 0);
}

// 0x1768b70
void effPCPWhirlwind3PolySetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
  s64 v5;
  s64 v6;
  Il2CppObject *v7;
  s64 v8;
  s64 v9;
  s64 v10;
  s64 v11;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v14;
  s64 *v15;
  UnityEngine_Matrix4x4_o dest;
  UnityEngine_Matrix4x4_o v18;
  u64 v19[3];

  v5 = *&pMatrix->m00;
  v6 = *&pMatrix->m20;
  v7 = *hData;
  v8 = *&pMatrix->m21;
  *&v18.m01 = *&pMatrix->m01;
  *&v18.m21 = v8;
  *&v18.m00 = v5;
  *&v18.m20 = v6;
  v9 = *&pMatrix->m02;
  v10 = *&pMatrix->m22;
  v11 = *&pMatrix->m23;
  *&v18.m03 = *&pMatrix->m03;
  *&v18.m23 = v11;
  *&v18.m02 = v9;
  *&v18.m22 = v10;
  SDF_VU0__LOADMATRIX(&v18);
  if (v7)
  {
    klass = v7->klass;
    if (v7->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPWhirlwind3Poly_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPWhirlwind3Poly_tag, v19);
      if ((v19[0] & 1) != 0)
        v14 = v19[2];
      else
        v14 = v19 + 1;
      v15 = sub_8C4940(v14);
    }
  }
  memmove(&dest, &v7[5].klass->_1.byval_arg, 0x40u);
  SDF_VU0__LOADMATRIX_B(&dest);
  MultMatrixNoArg();
  SDF_VU0__STOREMATRIX(&v7[1]);
}

// 0x1768990
void effPCPWhirlwind3PolySetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPWhirlwind3Poly_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPWhirlwind3Poly_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *&(*hData)[6].klass = scale;
}

// 0x1764060
effPCPWhirlwindPoly_tag *effPCPWhirlwindPolyCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  effPCPWhirlwindPolyParam_t_o *v8;
  Il2CppObject *v9;
  effPCPWhirlwindPoly_tag_o *result;
  char *v11;
  s64 *v12;
  u64 v13[3];

  v5 = *hData;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPWhirlwindPoly_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPWhirlwindPoly_tag, v13);
    if ((v13[0] & 1) != 0)
      v11 = v13[2];
    else
      v11 = v13 + 1;
    v12 = sub_8C4940(v11);
  }
  v8 = v5[5].klass;
  v9 = *(v5[6].monitor + 22);
  result = effPCPWhirlwindPolyCreate(v8, v9, tbldata);
  result->hPoly->pTexture = *(v5[6].monitor + 22);
  return result;
}

// 0x17639f0
effPCPWhirlwindPoly_tag *effPCPWhirlwindPolyCreate(effPCPWhirlwindPolyParam_t *pParam, void *pTex) {
  u64 *v5;
  u64 *v6;
  u64 *v7;
  u64 *v8;
  s64 v9;
  s64 v10;
  s64 v11;
  s64 v12;
  s64 v13;
  s64 v14;
  u32 split;
  u32 number;
  dds3WhirlwindPolyList_tag_o *v19;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v22;
  s64 *v23;
  s64 v24;
  u32 v25;
  u64 i;
  u32 *v28;
  u64 *v29;
  u64 v32;
  s64 v34;
  u32 v35;
  UnityEngine_Matrix4x4_o v37;
  u64 v38[3];

  v5 = Allocate(effPCPWhirlwindPoly_tag);
  _ctor(v5, 0);
  v6 = Allocate(effPCPWhirlwindPolyParam_t);
  effPCPWhirlwindPolyParam_t___ctor(v6);
  v7 = v5 + 10;
  v5[10] = v6;
  effPCPWhirlwindPolyParam_t__pClone(pParam, v5 + 10);
  v8 = NewSpecific(effPCPWhirlwindPolyPart_tag, pParam->number);
  v5[14] = 0;
  v5[11] = v8;
  v5[12] = 0x808080803F800000LL;
  v9 = *&pParam->matrix.m00;
  v10 = *&pParam->matrix.m20;
  v11 = *&pParam->matrix.m21;
  *&v37.m01 = *&pParam->matrix.m01;
  *&v37.m21 = v11;
  *&v37.m00 = v9;
  *&v37.m20 = v10;
  v12 = *&pParam->matrix.m02;
  v13 = *&pParam->matrix.m22;
  v14 = *&pParam->matrix.m23;
  *&v37.m03 = *&pParam->matrix.m03;
  *&v37.m23 = v14;
  *&v37.m02 = v12;
  *&v37.m22 = v13;
  SDF_VU0__LOADMATRIX(&v37);
  SDF_VU0__STOREMATRIX((v5 + 2), 0);
  number = pParam->number;
  split = pParam->split;
  v19 = dds3WhirlwindPolyListCreate(number, split);
  v5[13] = v19;
  v19->blend = pParam->blend;
  if (pTex)
  {
    klass = pTex->klass;
    if (pTex->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != UnityEngine_Texture)
    {
      sub_8FC2C0(klass->_1.element_class, UnityEngine_Texture, v38);
      if ((v38[0] & 1) != 0)
        v22 = v38[2];
      else
        v22 = v38 + 1;
      v23 = sub_8C4940(v22);
    }
    *(v5[13] + 176) = pTex;
  }
  v24 = *(*v7 + 108);
  if (*(*v7 + 116) <= 1)
    v25 = 1;
  else
    v25 = *(*v7 + 116);
  if (v24)
  {
    for (i = 0; i != v24; ++i)
    {
      v28 = v5[11];
      v29 = Allocate(effPCPWhirlwindPolyPart_tag);
      _ctor(v29, 0);
      *&v28[2 * i + 8] = v29;
      v32 = v5[11];
      v34 = *(v32 + 8 * i + 32);
      v35 = DDS3EFFECT_RAND_I();
      *(v34 + 24) = v35 / v25 * v25 - v35;
    }
  }
  return v5;
}

// 0x1763cf0
effPCPWhirlwindPoly_tag *effPCPWhirlwindPolyCreatePCF(void **hData, s32 bPos, bool tbldata) {
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
  struct dds3EffectPCPData_Part_t_array *v19;
  Il2CppObject *v20;
  u32 v22;
  s32 TmxIndex;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  effPCPWhirlwindPolyParam_t_o *v28;
  char *v29;
  s64 *v30;
  Il2CppObject *Texture;
  Il2CppClass *v32;
  s64 v33;
  char *v34;
  s64 *v35;
  s32 pos;
  u64 v38[2];
  char *v39;

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v7->klass->_1.element_class, v8, v38);
      if ((v38[0] & 1) != 0)
        v10 = v39;
      else
        v10 = v38 + 1;
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
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 32);
  v19 = v6->pcpData;
  v20 = DataUnityOffSet;
  v22 = v19->m_Items[1]->offset;
  TmxIndex = GetTmxIndex(Interface, v22 + bPos);
  if (v20)
  {
    klass = v20->klass;
    if (v20->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || (v28 = v20, klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPWhirlwindPolyParam_t))
    {
      sub_8FC2C0(klass->_1.element_class, effPCPWhirlwindPolyParam_t, v38);
      if ((v38[0] & 1) != 0)
        v29 = v39;
      else
        v29 = v38 + 1;
      v30 = sub_8C4940(v29);
    }
  }
  else
  {
    v28 = 0;
  }
  if (TmxIndex < 0)
  {
    if (v20)
    {
      v32 = v20->klass;
      if (v20->klass->_2.typeHierarchyDepth < v33
        || v32->_2.typeHierarchy[v33 - 1] != effPCPWhirlwindPolyParam_t)
      {
        sub_8FC2C0(v32->_1.element_class, effPCPWhirlwindPolyParam_t, v38);
        if ((v38[0] & 1) != 0)
          v34 = v39;
        else
          v34 = v38 + 1;
        v35 = sub_8C4940(v34);
      }
      Texture = 0;
      v28 = v20;
    }
    else
    {
      v28 = 0;
      Texture = 0;
    }
  }
  else
  {
    Texture = billGetTexture(TmxIndex);
  }
  return effPCPWhirlwindPolyCreate(v28, Texture);
}

// 0x1764190
void effPCPWhirlwindPolyDelete(void **hData) {
  effPCPWhirlwindPoly_tag_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3WhirlwindPolyList_tag_o *monitor;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPWhirlwindPoly_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPWhirlwindPoly_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  monitor = (*hData)[6].monitor;
  dds3WhirlwindPolyListDelete(monitor, v3);
}

// 0x1764c70
void effPCPWhirlwindPolyDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3WhirlwindPolyList_tag_o *monitor;
  Il2CppClass *v9;
  s32 typeDefinition;
  s64 typeDefinition_high;
  s32 v12;
  s32 klass_high;
  s32 v14;
  u32 v15;
  f32 v18;
  f32 v19;
  u32 v20;
  u64 v21;
  u64 *v22;
  s64 v24;
  s32 v25;
  s32 v26;
  struct System_UInt32_array *pABGR;
  f32 v29;
  u32 v30;
  struct System_UInt32_array *v33;
  s32 v37;
  s32 v38;
  UnityEngine_Matrix4x4_o v39;
  dds3WhirlwindPolyList_tag_o *hPoly;
  effPCPWhirlwindPoly_tag_o *pWhirlwindPoly;
  UnityEngine_Matrix4x4_o v42;

  hPoly = 0;
  pWhirlwindPoly = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPWhirlwindPoly_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPWhirlwindPoly_tag, &v42);
      if ((LOBYTE(v42.m00) & 1) != 0)
        v6 = *&v42.m01;
      else
        v6 = &v42.m00 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  monitor = v3[6].monitor;
  hPoly = monitor;
  pWhirlwindPoly = v3;
  v9 = v3[5].klass;
  typeDefinition = v9->_1.typeDefinition;
  typeDefinition_high = HIDWORD(v9->_1.typeDefinition);
  v12 = BYTE4(v9->_1.generic_class);
  v14 = v9->_1.klass;
  klass_high = HIDWORD(v9->_1.klass);
  v15 = effColorMultiply(HIDWORD(v3[6].klass), HIDWORD(v9->static_fields), 0);
  if (typeDefinition_high)
  {
    v18 = v14;
    v37 = klass_high;
    v19 = klass_high;
    v20 = v15;
    v21 = 0;
    v38 = v14;
    while (1)
    {
      while (1)
      {
        while (1)
        {
          v22 = v3[5].monitor;
          v24 = v22[v21 + 4];
          v25 = *(v24 + 24);
          v26 = typeDefinition - v25;
          if (typeDefinition >= v25)
            break;
          pABGR = hPoly->pABGR;
          pABGR->m_Items[v21++] = 0;
          if (typeDefinition_high == v21)
          {
LABEL_49:
            monitor = hPoly;
            goto LABEL_50;
          }
        }
        if (v25)
          break;
        effPCPWhirlwindPolyPartInit(&pWhirlwindPoly, v21);
LABEL_28:
        if (v12)
          goto LABEL_29;
LABEL_48:
        ++*(v24 + 24);
        if (typeDefinition_high == ++v21)
          goto LABEL_49;
      }
      if (v25 < 1)
        goto LABEL_28;
      if (v14 && v25 < v14)
      {
        v29 = v25 / v18;
      }
      else
      {
        v29 = 1.0;
        if (v37)
        {
          v29 = 1.0;
          if (v26 <= v37)
            v29 = v26 / v19;
        }
      }
      else if (!effBTLSkillCheckRun2(0xBBu))
      {
        goto LABEL_42;
      }
      if (typeDefinition_high == 340 || typeDefinition_high == 160)
        v20 = v20 & 0xFFFFFF | 0xA000000;
LABEL_42:
      v30 = effColorBlend(v20 & 0xFFFFFF, v20, v29);
      v33 = hPoly->pABGR;
      v33->m_Items[v21] = v30;
      effPCPWhirlwindPolyPartMove(&pWhirlwindPoly, v21);
      v14 = v38;
      if (!v12)
        goto LABEL_48;
LABEL_29:
      if (typeDefinition > v25)
        goto LABEL_48;
      *(v24 + 24) = 0;
      if (typeDefinition_high == ++v21)
        goto LABEL_49;
    }
  }
LABEL_50:
  monitor->scale = *&v3[6].klass;
  SDF_VU0__COPYVECTOR(&monitor->pos, *&v3[5].klass->_1.name);
  v39 = *&v3[1].klass;
  v42 = v39;
  SDF_VU0__LOADMATRIX(&v42);
  SDF_VU0__STOREMATRIX(&monitor->matrix);
  dds3WhirlwindPolyListDraw(&hPoly, "effPCPWhirlwindPolyDraw");
}

// 0x17642a0
void effPCPWhirlwindPolyPartInit(effPCPWhirlwindPoly_tag **pWhirlwindPoly, s32 index) {
  struct effPCPWhirlwindPolyPart_tag_array *pPart;
  struct dds3WhirlwindPolyList_tag_o *hPoly;
  s32 point;
  struct UnityEngine_Vector4_array *pVertex;
  struct UnityEngine_Vector2_array *pUV;
  f32 *v11;
  u32 v12;
  f32 v13;
  struct effPCPWhirlwindPolyParam_t_o *param;
  f32 v15;
  f32 radian_w;
  f32 v17;
  struct effPCPWhirlwindPolyParam_t_o *v18;
  f32 v19;
  f32 radius_s;
  f32 v21;
  f32 v22;
  struct effPCPWhirlwindPolyParam_t_o *v23;
  f32 v24;
  f32 width;
  f32 v26;
  struct effPCPWhirlwindPolyParam_t_o *v27;
  f32 v28;
  f32 radius_e;
  f32 incline;
  f32 v32;
  u64 v34;
  u64 v35;
  struct effPCPWhirlwindPolyParam_t_o *v36;
  u32 v37;
  f32 v38;
  f32 v39;
  f32 v40;
  f32 v41;
  f32 v42;
  s64 v43;
  UnityEngine_Vector4_o *v44;
  u32 v49;
  f32 v63;
  f32 radian_w_u;

  pPart = (*pWhirlwindPoly)->pPart;
  hPoly = (*pWhirlwindPoly)->hPoly;
  point = hPoly->point;
  pVertex = hPoly->pVertex;
  pUV = hPoly->pUV;
  v11 = pPart->m_Items[index];
  v12 = point >> 1;
  v13 = DDS3EFFECT_RAND_F();
  param = (*pWhirlwindPoly)->param;
  v15 = v13 * 6.2832;
  radian_w = param->radian_w;
  v17 = radian_w * DDS3EFFECT_RAND_FA(param->radian_w_r);
  v18 = (*pWhirlwindPoly)->param;
  v19 = v12;
  radian_w_u = v18->radian_w_u;
  radius_s = v18->radius_s;
  v21 = v17 / v19;
  v22 = DDS3EFFECT_RAND_FA(v18->radius_s_r);
  v23 = (*pWhirlwindPoly)->param;
  v24 = radius_s * v22;
  width = v23->width;
  v26 = DDS3EFFECT_RAND_FA(v23->width_r);
  v27 = (*pWhirlwindPoly)->param;
  v28 = width * v26;
  radius_e = v27->radius_e;
  v11[12] = ((radius_e * DDS3EFFECT_RAND_FA(v27->radius_e_r)) - v24) / v27->life;
  incline = (*pWhirlwindPoly)->param->incline;
  v32 = incline * DDS3EFFECT_RAND_F();
  v11[4] = v32;
  v11[5] = 0.0;
  v11[8] = v15;
  v63 = v21;
  v11[10] = v21;
  v11[11] = v24;
  v11[13] = v28;
  v11[9] = (*pWhirlwindPoly)->param->roll_s;
  v11[7] = (*pWhirlwindPoly)->param->up_s;
  SetRotateMatrixX(v32);
  SetRotateMatrixY_B(v11[5]);
  MultMatrixRevNoArg();
  if (v12)
  {
    v36 = (*pWhirlwindPoly)->param;
    v37 = point * index;
    LODWORD(v34) = v36->repeat_u;
    LODWORD(v35) = v36->repeat_v;
    v38 = 0.0;
    v39 = v35;
    v40 = v34;
    v41 = v40 / v19;
    v42 = 0.0;
    v43 = &pUV->m_Items[point * index];
    v44 = &pVertex->m_Items[v37];
    do
    {
      sdfCos(v15);
      sub_854930(v44, 0);
      sub_854930(v44, 1u);
      sdfSin(v15);
      sub_854930(v44, 2u);
      sub_854710(v44, 0);
      v49 = v37 + 1;
      sub_854930(&v44[1], 0);
      sub_854710(v44, 1u);
      sub_854930(&v44[1], 1u);
      sub_854710(v44, 2u);
      sub_854930(&v44[1], 2u);
      SDF_VU0__LOADVECTOR(*v44);
      SDF_VU0__APPLYMATRIX();
      SDF_VU0__STOREVECTOR(v44);
      SDF_VU0__LOADVECTOR(v44[1]);
      SDF_VU0__APPLYMATRIX();
      SDF_VU0__STOREVECTOR(v44 + 1);
      sub_8518D0(v43, 0, v42);
      sub_8518D0(v43, 1, 0.0);
      sub_8518D0(v43 + 8, 0, v42);
      sub_8518D0(v43 + 8, 1, v39);
      v38 = radian_w_u + v38;
      v42 = v41 + v42;
      v43 += 16;
      --v12;
      v37 += 2;
      v44 += 2;
      v15 = v63 + v15;
    }
    while (v12);
  }
}

// 0x17648b0
void effPCPWhirlwindPolyPartMove(effPCPWhirlwindPoly_tag **pWhirlwindPoly, s32 index) {
  struct effPCPWhirlwindPolyPart_tag_array *pPart;
  struct dds3WhirlwindPolyList_tag_o *hPoly;
  s32 point;
  struct UnityEngine_Vector4_array *pVertex;
  effPCPWhirlwindPolyPart_tag_o *v10;
  s32 v11;
  f32 radian;
  f32 up_s;
  f32 radian_add;
  f32 rot_x;
  f32 v16;
  f32 radian_s;
  f32 roll_a;
  s32 v20;
  UnityEngine_Vector4_o *v21;
  u32 v22;
  u32 v23;

  pPart = (*pWhirlwindPoly)->pPart;
  hPoly = (*pWhirlwindPoly)->hPoly;
  point = hPoly->point;
  pVertex = hPoly->pVertex;
  v10 = pPart->m_Items[index];
  v11 = point >> 1;
  up_s = v10->up_s;
  radian = v10->radian;
  radian_add = v10->radian_add;
  rot_x = v10->rot_x;
  v16 = v10->radius + v10->radius_s;
  SetRotateMatrixX(rot_x);
  SetRotateMatrixY_B(v10->rot_y);
  MultMatrixRevNoArg();
  radian_s = v10->radian_s;
  v10->rot_y = v10->rot_y + radian_s;
  roll_a = (*pWhirlwindPoly)->param->roll_a;
  v10->radius = v16;
  v10->radian_s = radian_s * roll_a;
  v10->up_s = up_s * (*pWhirlwindPoly)->param->up_a;
  if (v11)
  {
    v20 = point * index;
    v21 = &pVertex->m_Items[point * index];
    v22 = v20 + 1;
    do
    {
      sdfCos(radian);
      v23 = v22 - 1;
      sub_854930(v21, 0);
      sub_854710(v21, 1u);
      sub_854930(v21, 1u);
      sdfSin(radian);
      sub_854930(v21, 2u);
      sub_854710(v21, 0);
      sub_854930(&v21[1], 0);
      sub_854710(&v21[1], 1u);
      sub_854930(&v21[1], 1u);
      sub_854710(v21, 2u);
      sub_854930(&v21[1], 2u);
      SDF_VU0__LD_APPLYMATRIX(v21);
      SDF_VU0__LD_APPLYMATRIX(v21 + 1);
      radian = radian_add + radian;
      v21 += 2;
      v22 += 2;
      --v11;
    }
    while (v11);
  }
}

// 0x1765290
void effPCPWhirlwindPolySetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPWhirlwindPoly_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPWhirlwindPoly_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[6].klass) = abgr;
}

// 0x1765080
void effPCPWhirlwindPolySetPosition(void **hData, sdfVector4_t pPos) {
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
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPWhirlwindPoly_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPWhirlwindPoly_tag, v12);
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
  SDF_VU0__COPYVECTOR(&(*hData)[5].klass->_1.name, v13, 0);
}

// 0x1765380
void effPCPWhirlwindPolySetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
  s64 v5;
  s64 v6;
  Il2CppObject *v7;
  s64 v8;
  s64 v9;
  s64 v10;
  s64 v11;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v14;
  s64 *v15;
  UnityEngine_Matrix4x4_o dest;
  UnityEngine_Matrix4x4_o v18;
  u64 v19[3];

  v5 = *&pMatrix->m00;
  v6 = *&pMatrix->m20;
  v7 = *hData;
  v8 = *&pMatrix->m21;
  *&v18.m01 = *&pMatrix->m01;
  *&v18.m21 = v8;
  *&v18.m00 = v5;
  *&v18.m20 = v6;
  v9 = *&pMatrix->m02;
  v10 = *&pMatrix->m22;
  v11 = *&pMatrix->m23;
  *&v18.m03 = *&pMatrix->m03;
  *&v18.m23 = v11;
  *&v18.m02 = v9;
  *&v18.m22 = v10;
  SDF_VU0__LOADMATRIX(&v18);
  if (v7)
  {
    klass = v7->klass;
    if (v7->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPWhirlwindPoly_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPWhirlwindPoly_tag, v19);
      if ((v19[0] & 1) != 0)
        v14 = v19[2];
      else
        v14 = v19 + 1;
      v15 = sub_8C4940(v14);
    }
  }
  memmove(&dest, &v7[5].klass->_1.byval_arg, 0x40u);
  SDF_VU0__LOADMATRIX_B(&dest);
  MultMatrixNoArg();
  SDF_VU0__STOREMATRIX(&v7[1]);
}

// 0x17651a0
void effPCPWhirlwindPolySetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPWhirlwindPoly_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPWhirlwindPoly_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *&(*hData)[6].klass = scale;
}

// 0x1769360
effPCPWwSpherePoly_tag *effPCPWwSpherePolyCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  effPCPWwSpherePolyParam_t_o *v8;
  Il2CppObject *v9;
  effPCPWwSpherePoly_tag_o *result;
  char *v11;
  s64 *v12;
  u64 v13[3];

  v5 = *hData;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPWwSpherePoly_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPWwSpherePoly_tag, v13);
    if ((v13[0] & 1) != 0)
      v11 = v13[2];
    else
      v11 = v13 + 1;
    v12 = sub_8C4940(v11);
  }
  v8 = v5[5].klass;
  v9 = *(v5[6].monitor + 22);
  result = effPCPWwSpherePolyCreate(v8, v9, tbldata);
  result->hPoly->pTexture = *(v5[6].monitor + 22);
  return result;
}

// 0x1768cf0
effPCPWwSpherePoly_tag *effPCPWwSpherePolyCreate(effPCPWwSpherePolyParam_t *pParam, void *pTex) {
  u64 *v5;
  u64 *v6;
  u64 *v7;
  u32 split;
  u32 number;
  dds3WhirlwindPolyList_tag_o *v12;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v15;
  s64 *v16;
  s64 v17;
  u32 v18;
  u64 i;
  u32 *v21;
  u64 *v22;
  u64 v24;
  s64 v26;
  u32 v28;
  u64 v30[3];

  v5 = Allocate(effPCPWwSpherePoly_tag);
  _ctor(v5, 0);
  v6 = Allocate(effPCPWwSpherePolyParam_t);
  effPCPWwSpherePolyParam_t___ctor(v6);
  v7 = v5 + 10;
  v5[10] = v6;
  effPCPWwSpherePolyParam_t__pClone(pParam, v5 + 10);
  v5[11] = NewSpecific(effPCPWwSpherePolyPart_tag, pParam->number);
  v5[12] = 0x808080803F800000LL;
  v5[14] = 0;
  SDF_VU0__STOREIDENTITY((v5 + 2), 0);
  number = pParam->number;
  split = pParam->split;
  v12 = dds3WhirlwindPolyListCreate(number, split);
  v5[13] = v12;
  v12->blend = pParam->blend;
  if (pTex)
  {
    klass = pTex->klass;
    if (pTex->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != UnityEngine_Texture)
    {
      sub_8FC2C0(klass->_1.element_class, UnityEngine_Texture, v30);
      if ((v30[0] & 1) != 0)
        v15 = v30[2];
      else
        v15 = v30 + 1;
      v16 = sub_8C4940(v15);
    }
    *(v5[13] + 176) = pTex;
  }
  v17 = *(*v7 + 44);
  if (*(*v7 + 52) <= 1)
    v18 = 1;
  else
    v18 = *(*v7 + 52);
  if (v17)
  {
    for (i = 0; i != v17; ++i)
    {
      v21 = v5[11];
      v22 = Allocate(effPCPWwSpherePolyPart_tag);
      _ctor(v22, 0);
      *&v21[2 * i + 8] = v22;
      v24 = v5[11];
      v26 = *(v24 + 8 * i + 32);
      *(v26 + 16) = NewSpecific(f32, 3u);
      v28 = DDS3EFFECT_RAND_I();
      *(v26 + 24) = v28 / v18 * v18 - v28;
    }
  }
  return v5;
}

// 0x1768ff0
effPCPWwSpherePoly_tag *effPCPWwSpherePolyCreatePCF(void **hData, s32 bPos, bool tbldata) {
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
  struct dds3EffectPCPData_Part_t_array *v19;
  Il2CppObject *v20;
  u32 v22;
  s32 TmxIndex;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  effPCPWwSpherePolyParam_t_o *v28;
  char *v29;
  s64 *v30;
  Il2CppObject *Texture;
  Il2CppClass *v32;
  s64 v33;
  char *v34;
  s64 *v35;
  s32 pos;
  u64 v38[2];
  char *v39;

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v7->klass->_1.element_class, v8, v38);
      if ((v38[0] & 1) != 0)
        v10 = v39;
      else
        v10 = v38 + 1;
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
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 35);
  v19 = v6->pcpData;
  v20 = DataUnityOffSet;
  v22 = v19->m_Items[1]->offset;
  TmxIndex = GetTmxIndex(Interface, v22 + bPos);
  if (v20)
  {
    klass = v20->klass;
    if (v20->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || (v28 = v20, klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPWwSpherePolyParam_t))
    {
      sub_8FC2C0(klass->_1.element_class, effPCPWwSpherePolyParam_t, v38);
      if ((v38[0] & 1) != 0)
        v29 = v39;
      else
        v29 = v38 + 1;
      v30 = sub_8C4940(v29);
    }
  }
  else
  {
    v28 = 0;
  }
  if (TmxIndex < 0)
  {
    if (v20)
    {
      v32 = v20->klass;
      if (v20->klass->_2.typeHierarchyDepth < v33
        || v32->_2.typeHierarchy[v33 - 1] != effPCPWwSpherePolyParam_t)
      {
        sub_8FC2C0(v32->_1.element_class, effPCPWwSpherePolyParam_t, v38);
        if ((v38[0] & 1) != 0)
          v34 = v39;
        else
          v34 = v38 + 1;
        v35 = sub_8C4940(v34);
      }
      Texture = 0;
      v28 = v20;
    }
    else
    {
      v28 = 0;
      Texture = 0;
    }
  }
  else
  {
    Texture = billGetTexture(TmxIndex);
  }
  return effPCPWwSpherePolyCreate(v28, Texture);
}

// 0x1769490
void effPCPWwSpherePolyDelete(void **hData) {
  effPCPWwSpherePoly_tag_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3WhirlwindPolyList_tag_o *monitor;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPWwSpherePoly_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPWwSpherePoly_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  monitor = (*hData)[6].monitor;
  dds3WhirlwindPolyListDelete(monitor, v3);
}

// 0x1769d00
void effPCPWwSpherePolyDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3WhirlwindPolyList_tag_o *monitor;
  Il2CppClass *v9;
  signed s32 bits;
  s64 v11;
  s32 v12;
  s32 v13;
  u32 v14;
  f32 v17;
  u32 v18;
  u64 v19;
  u32 v20;
  u64 *v21;
  s64 v23;
  s32 v24;
  s32 v25;
  struct System_UInt32_array *pABGR;
  char *v28;
  f32 v29;
  u32 v30;
  struct System_UInt32_array *v33;
  s32 abgr0;
  s32 v38;
  s32 v39;
  UnityEngine_Matrix4x4_o v40;
  dds3WhirlwindPolyList_tag_o *hPoly;
  UnityEngine_Matrix4x4_o v42;
  effPCPWwSpherePoly_tag_o *pWwSpherePoly;

  pWwSpherePoly = 0;
  hPoly = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPWwSpherePoly_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPWwSpherePoly_tag, &v42);
      if ((LOBYTE(v42.m00) & 1) != 0)
        v6 = *&v42.m01;
      else
        v6 = &v42.m00 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  pWwSpherePoly = *hData;
  monitor = v3[6].monitor;
  hPoly = monitor;
  v9 = v3[5].klass;
  bits = v9->_1.byval_arg.bits;
  v11 = *(&v9->_1.byval_arg.bits + 1);
  v39 = BYTE4(v9->_1.byval_arg.data);
  v13 = v9->_1.this_arg.bits;
  v12 = *(&v9->_1.this_arg.bits + 1);
  v14 = effColorMultiply(HIDWORD(v3[6].klass), HIDWORD(v9->_1.typeDefinition), 0);
  if (v11)
  {
    v17 = v13;
    v18 = v14;
    v19 = 0;
    v20 = v14;
    abgr0 = v14 & 0xFFFFFF;
    v38 = v13;
    while (1)
    {
      while (1)
      {
        while (1)
        {
          v21 = v3[5].monitor;
          v23 = v21[v19 + 4];
          v24 = *(v23 + 24);
          v25 = bits - v24;
          if (bits >= v24)
            break;
          pABGR = hPoly->pABGR;
          v28 = pABGR + 4 * v19;
          v18 = v20;
          *(v28 + 8) = 0;
          if (v11 == ++v19)
          {
LABEL_42:
            monitor = hPoly;
            goto LABEL_43;
          }
        }
        if (v24)
          break;
        effPCPWwSpherePolyPartInit(&pWwSpherePoly, v19);
LABEL_28:
        if (v39)
          goto LABEL_29;
LABEL_41:
        ++*(v23 + 24);
        if (v11 == ++v19)
          goto LABEL_42;
      }
      if (v24 < 1)
        goto LABEL_28;
      if (v13 && v24 < v13)
      {
        v29 = v24 / v17;
      }
      else
      {
        v29 = 1.0;
        if (v12)
        {
          v29 = 1.0;
          if (v25 <= v12)
            v29 = v25 / v12;
        }
      }
      v30 = effColorBlend(abgr0, v18, v29);
      v33 = hPoly->pABGR;
      v33->m_Items[v19] = v30;
      effPCPWwSpherePolyPartMove(&pWwSpherePoly, v19);
      v13 = v38;
      v18 = v20;
      if (!v39)
        goto LABEL_41;
LABEL_29:
      if (bits > v24)
        goto LABEL_41;
      *(v23 + 24) = 0;
      if (v11 == ++v19)
        goto LABEL_42;
    }
  }
LABEL_43:
  monitor->scale = *&v3[6].klass;
  SDF_VU0__COPYVECTOR(&monitor->pos, *&v3[5].klass->_1.name);
  v40 = *&v3[1].klass;
  v42 = v40;
  SDF_VU0__LOADMATRIX(&v42);
  SDF_VU0__STOREMATRIX(&monitor->matrix);
  dds3WhirlwindPolyListDraw(&hPoly, "effPCPWwSpherePolyDraw");
}

// 0x17695a0
void effPCPWwSpherePolyPartInit(effPCPWwSpherePoly_tag **pWwSpherePoly, s32 index) {
  struct effPCPWwSpherePolyPart_tag_array *pPart;
  struct dds3WhirlwindPolyList_tag_o *hPoly;
  u32 point;
  struct UnityEngine_Vector2_array *pUV;
  effPCPWwSpherePolyPart_tag_o *v10;
  u32 v11;
  f32 v12;
  struct effPCPWwSpherePolyParam_t_o *param;
  f32 radian_w;
  f32 v15;
  struct effPCPWwSpherePolyParam_t_o *v16;
  f32 v17;
  f32 v18;
  struct effPCPWwSpherePolyParam_t_o *v19;
  f32 width;
  f32 v21;
  struct System_Single_array *rot;
  f32 v23;
  f32 v24;
  struct System_Single_array *v26;
  f32 v27;
  f32 v28;
  f32 v29;
  struct System_Single_array *v31;
  f32 v32;
  u64 v33;
  u64 v34;
  struct effPCPWwSpherePolyParam_t_o *v36;
  f32 v37;
  f32 v38;
  f32 v39;
  f32 v40;
  s64 v41;
  u32 v42;
  f32 v47;
  f32 radius;
  f32 v49;

  pPart = (*pWwSpherePoly)->pPart;
  hPoly = (*pWwSpherePoly)->hPoly;
  point = hPoly->point;
  pUV = hPoly->pUV;
  v10 = pPart->m_Items[index];
  v11 = point >> 1;
  v12 = DDS3EFFECT_RAND_F();
  param = (*pWwSpherePoly)->param;
  v49 = v12;
  radian_w = param->radian_w;
  v15 = DDS3EFFECT_RAND_FA(param->radian_w_r);
  v16 = (*pWwSpherePoly)->param;
  v17 = v15;
  radius = v16->radius;
  v18 = DDS3EFFECT_RAND_FA(v16->radius_r);
  v19 = (*pWwSpherePoly)->param;
  v47 = v18;
  width = v19->width;
  v21 = DDS3EFFECT_RAND_FA(v19->width_r);
  rot = v10->rot;
  v23 = v21;
  v24 = DDS3EFFECT_RAND_F();
  rot->m_Items[0] = v24 * 6.2832;
  v26 = v10->rot;
  v27 = radian_w * v17;
  v28 = v11;
  v29 = DDS3EFFECT_RAND_F() * 6.2832;
  v26->m_Items[1] = v29;
  v31 = v10->rot;
  v32 = width * v23;
  *&v33 = DDS3EFFECT_RAND_F();
  v31->m_Items[2] = *&v33 * 6.2832;
  v10->radian = v49 * 6.2832;
  v10->radian_add = v27 / v28;
  v10->radius = radius * v47;
  v10->width = v32;
  v10->radian_s = (*pWwSpherePoly)->param->roll_s;
  v10->radius_s = (*pWwSpherePoly)->param->radius_s;
  if (v11)
  {
    v36 = (*pWwSpherePoly)->param;
    LODWORD(v34) = v36->repeat_u;
    LODWORD(v33) = v36->repeat_v;
    LODWORD(v36) = point * index;
    v37 = v33;
    v38 = v34;
    v39 = v38 / v28;
    v40 = 0.0;
    v41 = &pUV->m_Items[point * index];
    v42 = v36 + 1;
    do
    {
      sub_8518D0(v41, 0, v40);
      sub_8518D0(v41, 1, 0.0);
      sub_8518D0(v41 + 8, 0, v40);
      sub_8518D0(v41 + 8, 1, v37);
      v40 = v39 + v40;
      v41 += 16;
      v42 += 2;
      --v11;
    }
    while (v11);
  }
}

// 0x1769900
void effPCPWwSpherePolyPartMove(effPCPWwSpherePoly_tag **pWwSpherePoly, s32 index) {
  struct dds3WhirlwindPolyList_tag_o *hPoly;
  struct effPCPWwSpherePolyPart_tag_array *pPart;
  s32 point;
  struct UnityEngine_Vector4_array *pVertex;
  effPCPWwSpherePolyPart_tag_o *v10;
  struct effPCPWwSpherePolyParam_t_o *param;
  f32 radian;
  f32 radian_s;
  f32 radius;
  f32 radian_add;
  f32 radius_s;
  f32 v17;
  f32 v18;
  System_Single_array *rot;
  s32 v20;
  u32 v22;
  UnityEngine_Vector4_o *v23;
  u32 v28;

  hPoly = (*pWwSpherePoly)->hPoly;
  pPart = (*pWwSpherePoly)->pPart;
  point = hPoly->point;
  pVertex = hPoly->pVertex;
  v10 = pPart->m_Items[index];
  param = (*pWwSpherePoly)->param;
  radian = v10->radian;
  radian_s = v10->radian_s;
  radian_add = v10->radian_add;
  radius = v10->radius;
  radius_s = v10->radius_s;
  if (v10->frame >= param->radius_aw)
    v10->radius_s = radius_s * param->radius_a;
  v17 = radian + radian_s;
  v18 = radius + radius_s;
  rot = v10->rot;
  v20 = point >> 1;
  SetRotateMatrixXYZ(rot);
  v10->radius = v18;
  v10->radian = v17;
  v10->radian_s = v10->radian_s * (*pWwSpherePoly)->param->roll_a;
  if (v20)
  {
    v22 = point * index;
    v23 = &pVertex->m_Items[point * index];
    do
    {
      sdfCos(v17);
      sub_854930(v23, 0);
      sub_854930(v23, 1u);
      sdfSin(v17);
      sub_854930(v23, 2u);
      sub_854710(v23, 0);
      v28 = v22 + 1;
      sub_854930(&v23[1], 0);
      sub_854930(&v23[1], 1u);
      sub_854710(v23, 2u);
      sub_854930(&v23[1], 2u);
      SDF_VU0__LOADVECTOR(*v23);
      SDF_VU0__APPLYMATRIX();
      SDF_VU0__STOREVECTOR(v23);
      SDF_VU0__LOADVECTOR(v23[1]);
      SDF_VU0__APPLYMATRIX();
      SDF_VU0__STOREVECTOR(v23 + 1);
      v17 = radian_add + v17;
      --v20;
      v22 += 2;
      v23 += 2;
    }
    while (v20);
  }
}

// 0x176a2e0
void effPCPWwSpherePolySetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPWwSpherePoly_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPWwSpherePoly_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[6].klass) = abgr;
}

// 0x176a0d0
void effPCPWwSpherePolySetPosition(void **hData, sdfVector4_t pPos) {
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
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPWwSpherePoly_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPWwSpherePoly_tag, v12);
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
  SDF_VU0__COPYVECTOR(&(*hData)[5].klass->_1.name, v13, 0);
}

// 0x176a3d0
void effPCPWwSpherePolySetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
  s64 v5;
  s64 v6;
  Il2CppObject *v7;
  s64 v8;
  s64 v9;
  s64 v10;
  s64 v11;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v14;
  s64 *v15;
  UnityEngine_Matrix4x4_o v16;
  u64 v17[3];

  v5 = *&pMatrix->m00;
  v6 = *&pMatrix->m20;
  v7 = *hData;
  v8 = *&pMatrix->m21;
  *&v16.m01 = *&pMatrix->m01;
  *&v16.m21 = v8;
  *&v16.m00 = v5;
  *&v16.m20 = v6;
  v9 = *&pMatrix->m02;
  v10 = *&pMatrix->m22;
  v11 = *&pMatrix->m23;
  *&v16.m03 = *&pMatrix->m03;
  *&v16.m23 = v11;
  *&v16.m02 = v9;
  *&v16.m22 = v10;
  SDF_VU0__LOADMATRIX(&v16);
  if (v7)
  {
    klass = v7->klass;
    if (v7->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPWwSpherePoly_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPWwSpherePoly_tag, v17);
      if ((v17[0] & 1) != 0)
        v14 = v17[2];
      else
        v14 = v17 + 1;
      v15 = sub_8C4940(v14);
    }
  }
  SDF_VU0__STOREMATRIX(&v7[1]);
}

// 0x176a1f0
void effPCPWwSpherePolySetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPWwSpherePoly_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPWwSpherePoly_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *&(*hData)[6].klass = scale;
}

// 0x175c1a0
void effPkt3DPrimLinkPoly(sdfDrawTag_t *pTag, sdf3DPrimPolyParm_t *pParam) {
  ;
}

// 0x175c140
void *sdfChipAlloc(void *aSize) {
  s32 v3;

  v3 = 0;
  return sub_8D3950(s32, &v3);
}
