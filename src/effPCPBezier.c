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
  u64 *v3;
  u32 *v4;
  s32 count;
  s32 v6;
  u32 *v7;
  u32 v8;
  s32 v11;
  u32 v12;
  u32 v15;
  s32 v17;
  u32 v18;
  s32 v19;
  struct XRD773Unity_CommonMesh_array *v20;
  struct XRD773Unity_CommonMesh_array *v22;
  u64 v23;
  u64 v24;
  u64 v25;
  XRD773Unity_CommonMesh_o *v27;
  UnityEngine_Vector3_array *v28;
  struct XRD773Unity_CommonMesh_array *v29;
  XRD773Unity_CommonMesh_o *v31;
  u64 v32;
  s32 v33;
  UnityEngine_Color_array *v34;
  struct XRD773Unity_CommonMesh_array *v35;
  XRD773Unity_CommonMesh_o *v37;
  System_Int32_array *v38;
  struct XRD773Unity_CommonMesh_array *v39;
  UnityEngine_Vector3_array *Position;
  struct XRD773Unity_CommonMesh_array *v42;
  UnityEngine_Color_array *Color;
  struct XRD773Unity_CommonMesh_array *v45;
  UnityEngine_Color_array *v46;
  System_Int32_array *IndexTable;
  u32 abgr;
  System_Int32_array *v50;
  f32 v51;
  f32 v52;
  f32 v53;
  f32 v54;
  f32 v56;
  u64 v57;
  s32 v58;
  s32 v59;
  u64 v60;
  s32 v62;
  s32 v63;
  s64 p_z;
  f32 *p_a;
  s64 v66;
  struct UnityEngine_Vector4_array *pVertex;
  u64 v68;
  u32 v70;
  f32 *v72;
  f32 v73;
  f32 v74;
  f32 v75;
  f32 v76;
  f32 *p_SDF_CC_NDNM;
  f32 v80;
  f32 v81;
  f32 v82;
  u32 v83;
  struct System_UInt32_array *pVC;
  u32 v87;
  f32 v88;
  f32 v89;
  f32 v90;
  f32 v91;
  s32 v93;
  s32 v94;
  u64 v95;
  s32 v96;
  s64 v97;
  struct System_UInt32_array *bztpSquareFaceIndex;
  u32 v101;
  il2cpp_array_size_t max_length;
  s64 v104;
  s64 v105;
  struct XRD773Unity_CommonMesh_array *v107;
  struct XRD773Unity_CommonMesh_array *v110;
  struct XRD773Unity_CommonMesh_array *v112;
  XRD773Unity_GraphicManager_o *Instance;
  s64 *Mesh;
  s64 *v115;
  struct XRD773Unity_CommonMesh_array *pMesh;
  UnityEngine_Object_o *gameObject;
  System_String_o *name;
  System_String_o *v120;
  struct XRD773Unity_CommonMesh_array *v121;
  u32 *v130;
  f32 v131;
  s64 v132;
  UnityEngine_Vector3_array *v133;
  s64 v134;
  u32 *v135;
  s32 v136;
  u64 v137;
  u64 *v138;
  dds3BezierTrackPoly_tag_o *v139;
  s64 v140;
  s64 v141;
  UnityEngine_Vector3_o v142;
  UnityEngine_Vector3_o v143;
  UnityEngine_Vector3_o v144;
  UnityEngine_Vector4_o v145;

  v3 = NewSpecific(s32, 2u);
  v4 = NewSpecific(s32, 2u);
  count = hPoly->count;
  if (!count)
    return;
  v6 = hPoly->current - count;
  v7 = v4;
  *(v3 + 8) = v6;
  if (v6 <= 2)
  {
    *(v3 + 8) = v6 - 3;
    v11 = 3 - v6;
    v4[8] = v11;
    v12 = *(v3 + 6);
    *(v3 + 8) += hPoly->point;
    *(v3 + 9) = 0;
    v15 = v4[6];
    v17 = count + 3 - v4[8];
    v4[9] = v17;
    if (!hPoly->pMesh)
    {
LABEL_93:
      v110 = NewSpecific(XRD773Unity_CommonMesh, 1u);
      hPoly->pMesh = v110;
      v112 = v110;
      {
      }
      Instance = get_Instance();
      Mesh = GetMesh(Instance, hPoly->blend, 0);
      v115 = Mesh;
      v112->m_Items[0] = v115;
      pMesh = hPoly->pMesh;
      gameObject = get_gameObject(pMesh->m_Items[0]);
      name = get_name(gameObject);
      v120 = Concat_5224608(name, ":dds3BezierTrackPolyDraw");
      set_name(gameObject, v120);
      v121 = hPoly->pMesh;
      SetAutoHide(v121->m_Items[0], 1);
      v18 = v7[6];
      if (!v18)
      {
LABEL_104:
      }
      goto LABEL_23;
    }
  }
  else
  {
    v8 = v4[6];
    v4[8] = count;
    v4[9] = 0;
    if (!hPoly->pMesh)
      goto LABEL_93;
  }
  v18 = v4[6];
  if (!v18)
    goto LABEL_104;
LABEL_23:
  v19 = v7[9] + v7[8];
  if (v19 >= 1)
  {
    v20 = hPoly->pMesh;
    if (v19 > SLODWORD(GetPosition(v20->m_Items[0])->max_length))
    {
      v22 = hPoly->pMesh;
      v23 = 1431655766LL * (v19 - 3);
      v24 = v23 >> 63;
      v25 = HIDWORD(v23);
      v27 = v22->m_Items[0];
      v28 = NewSpecific(UnityEngine_Vector3, v19);
      SetPosition_20241056(v27, v28);
      v29 = hPoly->pMesh;
      v31 = v29->m_Items[0];
      v32 = v19;
      v33 = v25 + v24;
      v34 = NewSpecific(UnityEngine_Color, v32);
      SetColor_20241296(v31, v34);
      v35 = hPoly->pMesh;
      v37 = v35->m_Items[0];
      v38 = NewSpecific(s32, (12 * v33));
      SetIndexTable(v37, v38);
    }
    v39 = hPoly->pMesh;
    Position = GetPosition(v39->m_Items[0]);
    v42 = hPoly->pMesh;
    v133 = Position;
    v138 = v3;
    Color = GetColor(v42->m_Items[0], 0);
    v45 = hPoly->pMesh;
    v46 = Color;
    IndexTable = GetIndexTable(v45->m_Items[0]);
    v139 = hPoly;
    v140 = 0;
    abgr = hPoly->abgr;
    v141 = 0;
    v50 = IndexTable;
    v51 = abgr;
    v52 = BYTE1(abgr);
    v53 = BYTE2(abgr);
    v54 = HIBYTE(abgr);
    sub_19EC630(&v140, v51 * 0.0078125, v52 * 0.0078125, v53 * 0.0078125, v54 * 0.0078125);
    v56 = *&v141;
    v132 = v140;
    v131 = *(&v141 + 1);
    v57 = 0;
    v58 = 0;
    v59 = 0;
    v130 = v7;
    do
    {
      while (1)
      {
        v60 = v57;
        v62 = v7[v57 + 8];
        if (v62)
          break;
        v57 = 1;
        if (v60)
          goto LABEL_84;
      }
      v63 = v58;
      if (v62 >= 1)
      {
        p_z = &v133->m_Items[v58].z;
        v135 = v138 + v57 + 8;
        v136 = v62;
        v134 = 4LL * v58 + 32;
        p_a = &v46->m_Items[v58].a;
        v66 = 0;
        do
        {
          pVertex = v139->pVertex;
          v68 = v60;
          v70 = v66 + *v135;
          v72 = (&pVertex->obj + v70);
          v73 = v72[8];
          v74 = v72[9];
          v75 = v72[10];
          v76 = v72[11];
          v145.x = v73;
          v145.y = v74;
          v145.z = v75;
          v145.w = v76;
          v142 = op_Implicit_8738992(v145);
          p_SDF_CC_NDNM = &SDF_CC_NDNM;
          v80 = p_SDF_CC_NDNM[41];
          v81 = p_SDF_CC_NDNM[42];
          v82 = p_SDF_CC_NDNM[43];
          v144.x = v80;
          v144.y = v81;
          v144.z = v82;
          v143 = Scale(v142, v144);
          v83 = v58 + v66;
          *(p_z - 8) = v143;
          pVC = v139->pVC;
          v87 = *(&pVC->obj.klass + 4 * v66 + v134);
          v88 = *(&pVC->obj.klass + 4 * v66 + v134);
          *(p_a - 3) = *&v132 * (v88 * 0.0039216);
          v89 = BYTE1(v87);
          *(p_a - 2) = *(&v132 + 1) * (v89 * 0.0039216);
          v90 = BYTE2(v87);
          *(p_a - 1) = v56 * (v90 * 0.0039216);
          v91 = HIBYTE(v87);
          *p_a = v131 * (v91 * 0.0078125);
          v62 = v136;
          ++v66;
          p_z += 12;
          p_a += 4;
          v60 = v68;
        }
        while (v136 != v66);
        v7 = v130;
        v63 = v58 + v66;
      }
      if (v62 - 3 >= 3)
      {
        v137 = v60;
        v93 = 0;
        v94 = (v62 - 3) / 3;
        do
        {
          v95 = 0;
          v96 = v59;
          v97 = &v50->m_Items[v59];
          do
          {
            v101 = bztpSquareFaceIndex->m_Items[v95] + v58;
            *(v97 + 4 * v95++) = v101;
          }
          while (v95 != 12);
          ++v93;
          v59 = v96 + 12;
          v58 += 3;
        }
        while (v93 != v94);
        v59 = v96 + 12;
        v7 = v130;
        v60 = v137;
      }
      v57 = 1;
      v58 = v63;
    }
    while (!v60);
LABEL_84:
    LODWORD(max_length) = v50->max_length;
    if (v59 < max_length)
    {
      v104 = v59;
      do
      {
        v105 = v104 + 1;
        v50->m_Items[v104] = 0;
        max_length = v50->max_length;
        ++v104;
      }
      while (v105 < max_length);
    }
    v107 = v139->pMesh;
    SetActive(v107->m_Items[0], 1, 0);
  }
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
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 *v10;
  dds3BezierTrackPolyABGR_tag_o *v11;
  u64 data_low;
  effPCPBezierBill_tag_o *v13;
  u32 *v14;
  u64 *v15;
  s32 **p_fields;
  s32 *param;
  u32 v18;
  u32 v19;
  u64 v20;
  u32 *v21;
  effPCPBezierBillPart_tag_o *v23;
  s64 v32;
  u64 *v33;
  s64 v40;
  effBTL_t_o *hBED;
  effEveBEDCutHandle_t_o *v42;
  bool v43;
  u64 v45[3];
  u64 v46;

  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBezierBill_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBezierBill_tag, v45);
      if ((v45[0] & 1) != 0)
        v8 = v45[2];
      else
        v8 = v45 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = Allocate(effEveBEDParams_t);
  effEveBEDParams_t___ctor(v10);
  v11 = Allocate(dds3BezierTrackPolyABGR_tag);
  _ctor(v11, 0);
  data_low = LODWORD(v5[1].klass->_1.this_arg.data);
  v13 = Allocate(effPCPBezierBill_tag);
  _ctor(v13, 0);
  v46 = data_low;
  v14 = NewSpecific(effPCPBezierBillPart_tag, data_low);
  v15 = Allocate(effPCPBezierBillParam_t);
  effPCPBezierBillParam_t___ctor(v15);
  v13->param = v15;
  p_fields = &v13->fields;
  effPCPBezierBillParam_t__pClone(v5[1].klass, &v13->param);
  v13->abgr = -2139062144;
  v13->hMem = 0;
  v13->original = 0;
  v13->hBED = v5[2].monitor;
  param = v13->param;
  if (param[18])
  {
    if (param[19] > 0)
      goto LABEL_12;
LABEL_48:
    param[19] = 1;
    param = *p_fields;
    if ((*p_fields)[14] > 0)
      goto LABEL_13;
    goto LABEL_49;
  }
  param[18] = 1;
  param = *p_fields;
  if ((*p_fields)[19] <= 0)
    goto LABEL_48;
LABEL_12:
  if (param[14] > 0)
    goto LABEL_13;
LABEL_49:
  param[14] = 1;
  param = *p_fields;
LABEL_13:
  v18 = param[18];
  v19 = param[19];
  v11->s_c = param[20];
  v11->s_e = (*p_fields)[21];
  v11->e_c = (*p_fields)[22];
  v11->e_e = (*p_fields)[23];
  sub_854930((v10 + 2), 0);
  sub_854930((v10 + 2), 1u);
  sub_854930((v10 + 2), 2u);
  sub_854930((v10 + 2), 3u);
  sub_854930((v10 + 4), 0);
  sub_854930((v10 + 4), 1u);
  sub_854930((v10 + 4), 2u);
  sub_854930((v10 + 4), 3u);
  v10[6] = 0x42C8000042C80000LL;
  *(v10 + 14) = 1065353216;
  *(v10 + 15) = -2139062144;
  if (v46)
  {
    v20 = 0;
    v21 = v14 + 8;
    do
    {
      v23 = Allocate(effPCPBezierBillPart_tag);
      _ctor(v23, 0);
      *&v21[2 * v20] = v23;
      v23->hBztp = dds3BezierTrackPolyCreate(v18, v19);
      dds3BezierTrackPolySetVC((*&v21[2 * v20] + 40LL), v11);
      *(*&v21[2 * v20] + 32LL) = 0;
      *(*&v21[2 * v20] + 36LL) = 1065353216;
      v32 = *&v21[2 * v20];
      v33 = Allocate(effBezier7PPart_t);
      effBezier7PPart_t___ctor(v33);
      *(v32 + 48) = v33;
      effBezier7PPart_t__Clear(*(*&v21[2 * v20] + 48LL), 0);
      *(*(*&v21[2 * v20] + 48LL) + 24LL) = 0;
      *(*(*&v21[2 * v20] + 48LL) + 28LL) = 0;
      *(*(*&v21[2 * v20] + 48LL) + 32LL) = 0;
      v40 = *&v21[2 * v20];
      hBED = v13->hBED;
      v42 = effEveBEDCutCreate(hBED, 2u, v10);
      v43 = v46 == ++v20;
      *(v40 + 56) = v42;
    }
    while (!v43);
  }
  v13->pPart = v14;
  return v13;
}

// 0x16c51f0
effPCPBezierBill_tag *effPCPBezierBillCreate(effPCPBezierBillParam_t *pParam, void *pBEDData) {
  u64 *v5;
  dds3BezierTrackPolyABGR_tag_o *v6;
  u64 number;
  effPCPBezierBill_tag_o *v8;
  u32 *v9;
  u32 *v11;
  Il2CppClass *v12;
  s64 *Interface;
  char *v14;
  s64 *v15;
  effBTL_t_o *v16;
  s32 *param;
  u32 v18;
  u32 v19;
  u64 v20;
  u32 *v21;
  effPCPBezierBillPart_tag_o *v23;
  s64 v32;
  u64 *v33;
  s64 v40;
  effBTL_t_o *hBED;
  effEveBEDCutHandle_t_o *v42;
  bool v43;
  u64 v45[3];
  u64 v46;

  v5 = Allocate(effEveBEDParams_t);
  effEveBEDParams_t___ctor(v5);
  v6 = Allocate(dds3BezierTrackPolyABGR_tag);
  _ctor(v6, 0);
  number = pParam->number;
  v8 = Allocate(effPCPBezierBill_tag);
  _ctor(v8, 0);
  v46 = number;
  v9 = NewSpecific(effPCPBezierBillPart_tag, number);
  v8->param = pParam;
  v8->abgr = -2139062144;
  v8->hMem = 0;
  v8->original = 1;
  v11 = v9;
  if (!pBEDData)
    goto LABEL_12;
LABEL_6:
  Interface = QueryInterface(pBEDData, byte);
  if (!Interface)
  {
    sub_8FC2C0(pBEDData->klass->_1.element_class, v12, v45);
    if ((v45[0] & 1) != 0)
      v14 = v45[2];
    else
      v14 = v45 + 1;
    v15 = sub_8C4940(v14);
  }
LABEL_13:
  v16 = effEveBEDCreate(Interface);
  param = v8->param;
  v8->hBED = v16;
  if (param[18])
  {
    if (param[19] > 0)
      goto LABEL_15;
LABEL_51:
    param[19] = 1;
    param = v8->param;
    if (param[14] > 0)
      goto LABEL_16;
    goto LABEL_52;
  }
  param[18] = 1;
  param = v8->param;
  if (param[19] <= 0)
    goto LABEL_51;
LABEL_15:
  if (param[14] > 0)
    goto LABEL_16;
LABEL_52:
  param[14] = 1;
  param = v8->param;
LABEL_16:
  v18 = param[18];
  v19 = param[19];
  v6->s_c = param[20];
  v6->s_e = v8->param->abgr_s_e;
  v6->e_c = v8->param->abgr_e_c;
  v6->e_e = v8->param->abgr_e_e;
  sub_854930((v5 + 2), 0);
  sub_854930((v5 + 2), 1u);
  sub_854930((v5 + 2), 2u);
  sub_854930((v5 + 2), 3u);
  sub_854930((v5 + 4), 0);
  sub_854930((v5 + 4), 1u);
  sub_854930((v5 + 4), 2u);
  sub_854930((v5 + 4), 3u);
  v5[6] = 0x42C8000042C80000LL;
  *(v5 + 14) = 1065353216;
  *(v5 + 15) = -2139062144;
  if (v46)
  {
    v20 = 0;
    v21 = v11 + 8;
    do
    {
      v23 = Allocate(effPCPBezierBillPart_tag);
      _ctor(v23, 0);
      *&v21[2 * v20] = v23;
      v23->hBztp = dds3BezierTrackPolyCreate(v18, v19);
      dds3BezierTrackPolySetVC((*&v21[2 * v20] + 40LL), v6);
      *(*&v21[2 * v20] + 32LL) = 0;
      *(*&v21[2 * v20] + 36LL) = 1065353216;
      v32 = *&v21[2 * v20];
      v33 = Allocate(effBezier7PPart_t);
      effBezier7PPart_t___ctor(v33);
      *(v32 + 48) = v33;
      effBezier7PPart_t__Clear(*(*&v21[2 * v20] + 48LL), 0);
      *(*(*&v21[2 * v20] + 48LL) + 24LL) = 0;
      *(*(*&v21[2 * v20] + 48LL) + 28LL) = 0;
      *(*(*&v21[2 * v20] + 48LL) + 32LL) = 0;
      v40 = *&v21[2 * v20];
      hBED = v8->hBED;
      v42 = effEveBEDCutCreate(hBED, 2u, v5);
      v43 = v46 == ++v20;
      *(v40 + 56) = v42;
    }
    while (!v43);
  }
  v8->pPart = v11;
  return v8;
}

// 0x16c57b0
effPCPBezierBill_tag *effPCPBezierBillCreatePCF(void **hData, s32 bPos, bool tbldata) {
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
  effPCPBezierBillParam_t_o *v21;
  u32 v23;
  Il2CppObject *EffPCPAgiFireballPart;
  effPCPBezierBillParam_t_c *klass;
  s64 typeHierarchyDepth;
  char *v29;
  s64 *v30;
  u64 v32[2];
  char *v33;
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
      sub_8FC2C0(v7->klass->_1.element_class, v8, v32);
      if ((v32[0] & 1) != 0)
        v10 = v33;
      else
        v10 = v32 + 1;
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
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 56);
  v19 = v6->pcpData;
  v20 = *hData;
  v21 = DataUnityOffSet;
  v23 = v19->m_Items[1]->offset;
  EffPCPAgiFireballPart = GetEffPCPAgiFireballPart(v20, v23 + bPos);
  else if (!v21)
  {
    return effPCPBezierBillCreate(v21, EffPCPAgiFireballPart);
  }
  klass = v21->klass;
  if (v21->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBezierBillParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBezierBillParam_t, v32);
    if ((v32[0] & 1) != 0)
      v29 = v33;
    else
      v29 = v32 + 1;
    v30 = sub_8C4940(v29);
  }
  return effPCPBezierBillCreate(v21, EffPCPAgiFireballPart);
}

// 0x16c6030
void effPCPBezierBillDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s64 data_low;
  u64 i;
  u64 *monitor;
  s64 v12;
  dds3BezierTrackPoly_tag_o *v13;
  effEveBEDCutHandle_t_o *v15;
  effBTL_t_o *v16;
  u64 v17[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBezierBill_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBezierBill_tag, v17);
      if ((v17[0] & 1) != 0)
        v6 = v17[2];
      else
        v6 = v17 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  data_low = LODWORD(v3[1].klass->_1.this_arg.data);
  if (data_low)
  {
    for (i = 0; i != data_low; ++i)
    {
      monitor = v3[1].monitor;
      v12 = monitor[i + 4];
      v13 = *(v12 + 40);
      dds3BezierTrackPolyDelete(v13);
      v15 = *(v12 + 56);
      effEveBEDCutDelete(v15);
    }
  }
  if (LOBYTE(v3[3].klass))
  {
    v16 = v3[2].monitor;
    effEveBEDDelete(v16);
  }
}

// 0x16c6210
void effPCPBezierBillDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  u64 *v9;
  Il2CppClass *v10;
  s32 data_high;
  s32 element_class;
  s64 data_low;
  u32 castClass_high;
  s64 bits;
  s32 data;
  nbFormation_t_o *TargetFormation;
  f32 v24;
  f32 v25;
  f32 v26;
  u64 v27;
  u64 *monitor;
  s64 v403;
  s64 v404;
  effBezier7PPart_t_o **v405;
  f32 x;
  f32 z;
  s32 v578;
  f32 v579;
  f32 v580;
  u8 v581;
  u8 v582;
  s64 v583;
  s32 v584;
  s64 v585;
  s64 v586;
  u32 i;
  s64 v599;
  f32 v612;
  f32 v613;
  f32 v615;
  f32 v616;
  f32 v617;
  dds3BezierTrackPoly_tag_o *v619;
  s64 v620;
  UnityEngine_Vector4_o *v621;
  u32 v622;
  effEveBEDParams_t_o *pParams;
  u32 v624;
  Il2CppObject *v625;
  f32 v626;
  f32 v627;
  UnityEngine_Vector4_o *v628;
  UnityEngine_Vector4_o *v629;
  UnityEngine_Vector4_o *v630;
  UnityEngine_Vector4_o v631;
  UnityEngine_Vector4_o v632;
  UnityEngine_Vector4_o v633;
  s64 v634;
  s64 v635;
  UnityEngine_Vector4_o v636;
  UnityEngine_Vector4_o v637;
  UnityEngine_Vector4_o v638;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o pOut;
  UnityEngine_Vector4_o v641;
  UnityEngine_Vector4_o v642;
  UnityEngine_Vector4_o v643;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *pFormation;
  u64 v646[4];

  *&p.z = 0;
  pFormation = 0;
  *&v641.x = 0;
  *&v643.z = 0;
  *&p.x = 0;
  *&v642.z = 0;
  *&v643.x = 0;
  *&v641.z = 0;
  *&v642.x = 0;
  *&pOut.x = 0;
  *&pOut.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  *&v638.x = 0;
  *&v638.z = 0;
  *&v637.x = 0;
  *&v637.z = 0;
  *&v636.x = 0;
  *&v636.z = 0;
  v634 = 0;
  v635 = 0;
  *&v633.x = 0;
  *&v633.z = 0;
  *&v632.x = 0;
  *&v632.z = 0;
  *&v631.x = 0;
  *&v631.z = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBezierBill_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBezierBill_tag, v646);
      if ((v646[0] & 1) != 0)
        v6 = v646[2];
      else
        v6 = v646 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = Allocate(effEveBEDParams_t);
  effEveBEDParams_t___ctor(v8);
  *&p.z = 0;
  pFormation = 0;
  *&v643.z = 0;
  *&p.x = 0;
  *&v641.x = 0;
  *&v642.z = 0;
  *&v643.x = 0;
  *&v641.z = 0;
  *&v642.x = 0;
  *&pOut.x = 0;
  *&pOut.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  *&v638.x = 0;
  *&v638.z = 0;
  *&v637.x = 0;
  *&v637.z = 0;
  *&v636.x = 0;
  *&v636.z = 0;
  v634 = 0;
  v635 = 0;
  *&v633.x = 0;
  *&v633.z = 0;
  v9 = NewSpecific(UnityEngine_Vector4, 3u);
  *&v632.x = 0;
  *&v632.z = 0;
  *&v631.x = 0;
  *&v631.z = 0;
  v10 = v3[1].klass;
  data_high = HIDWORD(v10->_1.this_arg.data);
  v622 = v3[2].klass;
  element_class = v10->_1.element_class;
  data_low = LODWORD(v10->_1.this_arg.data);
  castClass_high = HIDWORD(v10->_1.castClass);
  bits = v10->_1.this_arg.bits;
  data = v10->_1.byval_arg.data;
  SDF_VU0__COPYVECTOR(&dst, *&v10->_1.name);
  sub_854930((v8 + 4), 0);
  sub_854930((v8 + 4), 1u);
  sub_854930((v8 + 4), 2u);
  v621 = (v8 + 4);
  sub_854930((v8 + 4), 3u);
  v8[6] = 0x42C8000042C80000LL;
  *(v8 + 14) = 1065353216;
  pParams = v8;
  if (!effBTLSkillCheckRun())
    goto LABEL_27;
LABEL_13:
  if (data == 3)
  {
    TargetFormation = effBTLSkillGetTargetFormation(0);
  }
  else
  {
    TargetFormation = effBTLSkillGetInvokeFormation(0);
  }
  pFormation = TargetFormation;
  effBTLModelGetSphereCenter(&pFormation);
  SDF_VU0__STOREVECTOR(&p);
LABEL_28:
  SDF_VU0__LOADVECTOR(dds3CameraTargetPos);
  SDF_VU0__LOADVECTOR_B(dds3CameraEyePos);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__STOREVECTOR(&v637);
  sub_854930(&v636, 0);
  sub_854710(&v636, 0);
  sub_854930(&v636, 1u);
  sub_854930(&v636, 2u);
  if (data_low)
  {
    v630 = (v9 + 6);
    v629 = (v9 + 4);
    v24 = castClass_high;
    v628 = (v9 + 8);
    v620 = (v8 + 2);
    v624 = castClass_high - 1;
    v626 = 3.0 / (v24 * data_high);
    v25 = 1.0 / element_class;
    v26 = -0.5;
    v27 = 0;
    v627 = v25;
    v625 = v3;
    while (1)
    {
LABEL_241:
      monitor = v3[1].monitor;
      v403 = monitor[v27 + 4];
      v405 = (v403 + 48);
      v404 = *(v403 + 48);
      if (*(v404 + 32) == 0.0)
        break;
      v578 = *(v403 + 32);
      *(v403 + 32) = v578 + 1;
      if ((v578 & 0x80000000) == 0)
      {
        if (*(v404 + 28) < 1.0 || *(v404 + 24) < 3u)
        {
          v584 = data;
          v585 = bits;
          v586 = data_low;
          sub_854710(v403 + 16, 0);
          sub_854930(&v638, 0);
          sub_854710(v403 + 16, 1u);
          sub_854930(&v638, 1u);
          sub_854710(v403 + 16, 2u);
          sub_854930(&v638, 2u);
          for (i = v624; ; --i)
          {
            dds3Bezier7PPartRun(v405, &pOut);
            SDF_VU0__LOADVECTOR(pOut);
            SDF_VU0__COPYVECTOR_A_TO_C();
            SDF_VU0__LOADVECTOR_B(v638);
            SDF_VU0__SUBVECTOR();
            if (!i)
              break;
            SDF_VU0__LOADVECTOR_B(v637);
            SDF_VU0__OUTERPRODUCT();
            SDF_VU0__NORMALIZE();
            SDF_VU0__LOADVECTOR_B(v636);
            SDF_VU0__MULVECTOR();
            SDF_VU0__SWAPVECTOR_A_C();
            SDF_VU0__STOREVECTOR(v630);
            SDF_VU0__COPYVECTOR_A_TO_B();
            SDF_VU0__ADDVECTOR_A_C();
            SDF_VU0__STOREVECTOR(v629);
            SDF_VU0__COPYVECTOR_C_TO_A();
            SDF_VU0__SUBVECTOR_B_A();
            SDF_VU0__STOREVECTOR_B(v628);
            SDF_VU0__COPYVECTOR(&v638, pOut);
            dds3BezierTrackPolySetVertex((v403 + 40), v9);
          }
          SDF_VU0__NORMALIZE();
          SDF_VU0__STOREVECTOR(&v631);
          SDF_VU0__LOADVECTOR_B(v637);
          SDF_VU0__OUTERPRODUCT();
          SDF_VU0__NORMALIZE();
          SDF_VU0__STOREVECTOR(&v633);
          SDF_VU0__LOADVECTOR_B(v636);
          SDF_VU0__MULVECTOR();
          SDF_VU0__SWAPVECTOR_A_C();
          SDF_VU0__STOREVECTOR(v630);
          SDF_VU0__COPYVECTOR_A_TO_B();
          SDF_VU0__ADDVECTOR_A_C();
          data_low = v586;
          SDF_VU0__STOREVECTOR(v629);
          SDF_VU0__COPYVECTOR_C_TO_A();
          SDF_VU0__SUBVECTOR_B_A();
          bits = v585;
          SDF_VU0__STOREVECTOR_B(v628);
          data = v584;
          dds3BezierTrackPolySetVertex((v403 + 40), v9);
          sub_854710(&pOut, 0);
          sub_854930(v403 + 16, 0);
          sub_854710(&pOut, 1u);
          sub_854930(v403 + 16, 1u);
          sub_854710(&pOut, 2u);
          sub_854930(v403 + 16, 2u);
          v599 = *(*(v403 + 40) + 72LL);
          v3 = v625;
          SDF_VU0__COPYVECTOR((v599 + 32), *(v9 + 3), 0);
          SDF_VU0__COPYVECTOR((v599 + 48), *(v9 + 2), 0);
          SDF_VU0__COPYVECTOR((v599 + 144), *(v9 + 4), 0);
          sub_854710(&v633, 0);
          sub_854930(&v632, 0);
          sub_854710(&v633, 1u);
          sub_854930(&v632, 1u);
          sub_854710(&v633, 2u);
          sub_854930(&v632, 2u);
          sub_854710(&v633, 3u);
          sub_854930(&v632, 3u);
          SDF_VU0__LOADVECTOR_C(*(v9 + 3), 0);
          SDF_VU0__LOADVECTOR(v633);
          SDF_VU0__LOADVECTOR_B(v631);
          SDF_VU0__INTERPOLATE(0.33333);
          SDF_VU0__NORMALIZE();
          SDF_VU0__LOADVECTOR_B(v636);
          SDF_VU0__MULVECTOR();
          SDF_VU0__ADDVECTOR_A_C();
          SDF_VU0__STOREVECTOR((v599 + 64), 0);
          SDF_VU0__LOADVECTOR(v633);
          SDF_VU0__LOADVECTOR_B(v631);
          SDF_VU0__INTERPOLATE(0.66667);
          SDF_VU0__NORMALIZE();
          SDF_VU0__LOADVECTOR_B(v636);
          SDF_VU0__MULVECTOR();
          SDF_VU0__ADDVECTOR_A_C();
          SDF_VU0__STOREVECTOR((v599 + 80), 0);
          SDF_VU0__LOADVECTOR(v631);
          SDF_VU0__MULVECTOR();
          SDF_VU0__ADDVECTOR_A_C();
          SDF_VU0__STOREVECTOR((v599 + 96), 0);
          SDF_VU0__LOADVECTOR(v632);
          SDF_VU0__LOADVECTOR_B(v631);
          SDF_VU0__INTERPOLATE(0.66667);
          SDF_VU0__NORMALIZE();
          SDF_VU0__LOADVECTOR_B(v636);
          SDF_VU0__MULVECTOR();
          SDF_VU0__ADDVECTOR_A_C();
          SDF_VU0__STOREVECTOR((v599 + 112), 0);
          SDF_VU0__LOADVECTOR(v632);
          SDF_VU0__LOADVECTOR_B(v631);
          SDF_VU0__INTERPOLATE(0.33333);
          SDF_VU0__NORMALIZE();
          SDF_VU0__LOADVECTOR_B(v636);
          SDF_VU0__MULVECTOR();
          SDF_VU0__ADDVECTOR_A_C();
          v26 = -0.5;
          SDF_VU0__STOREVECTOR((v599 + 128), 0);
          v25 = v627;
        }
        else
        {
          v579 = *(v403 + 36);
          if (v579 <= v25)
          {
            *(*(v403 + 40) + 28LL) = 0;
            *(*(v403 + 40) + 32LL) = 3;
            *(*(v403 + 40) + 16LL) = -2139062144;
          }
          else
          {
            v580 = v579 - v25;
            v581 = vcvts_n_s32_f32(v580, 7u);
            *(v403 + 36) = v580;
            v582 = vcvts_n_u32_f32(v580, 7u);
            if ((v580 * 128.0) >= 0.0)
              v581 = v582;
            *(*(v403 + 40) + 16LL) = (v581 << 24) | 0x808080;
            v583 = *(v403 + 40);
            *(v583 + 16) = (((BYTE2(*(v583 + 16)) * (v622 & 0xFF0000)) | (*(v583 + 16) * v622)) >> 7) & 0xFF00FF
                         | (2 * ((BYTE1(*(v583 + 16)) * BYTE1(v622)) | (HIBYTE(*(v583 + 16)) * ((v622 >> 8) & 0xFF0000))))
                         & 0xFF00FF00;
          }
        }
        if ((*v405)->weight >= 1.0 && (*v405)->segment >= 3)
        {
          pParams->abgr = v622;
          sub_854710(v403 + 16, 0);
          sub_854930(v620, 0);
          sub_854710(v403 + 16, 1u);
          sub_854930(v620, 1u);
          sub_854710(v403 + 16, 2u);
          sub_854930(v620, 2u);
          sub_854930(v620, 3u);
          sub_854710(&p, 0);
          sub_854710(v620, 0);
          sub_854930(&v634, 0);
          sub_854710(&p, 2u);
          sub_854710(v620, 2u);
          sub_854930(&v634, 2u);
          sub_854710(&v634, 0);
          v613 = v612;
          sub_854710(&v634, 2u);
          v616 = v615;
          v617 = sdfAtan2(v613, v616);
          FromEuler(0.0, v617, 0.0);
          SDF_VU0__STOREVECTOR(v621);
          effEveBEDCutSetParams((v403 + 56), pParams, 0);
          effEveBEDCutDraw((v403 + 56), 0);
        }
        v619 = *(v403 + 40);
        dds3BezierTrackPolyDraw(v619);
      }
      if (++v27 == data_low)
        return;
    }
    else if ((byte_3F5A39F & 1) != 0)
    {
      goto LABEL_248;
    }
    goto LABEL_248;
  }
}

// 0x16ca620
void effPCPBezierBillSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBezierBill_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBezierBill_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[2].klass) = abgr;
}

// 0x16ca500
void effPCPBezierBillSetPosition(void **hData, sdfVector4_t pPos) {
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
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBezierBill_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBezierBill_tag, v12);
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
