#include "types.h"

typedef struct XRD773Unity_CommonMesh XRD773Unity_CommonMesh;
typedef struct XRD773Unity_GraphicManager XRD773Unity_GraphicManager;
typedef struct XRD773Unity_GraphicManager_CommonObject XRD773Unity_GraphicManager_CommonObject;
typedef struct dds3EffectTable_Reset_t dds3EffectTable_Reset_t;
typedef struct dds3EffectTable_Scale_t dds3EffectTable_Scale_t;
typedef struct dds3EffectTable_t dds3EffectTable_t;
typedef struct dds3HermitianTrackPoly_tag dds3HermitianTrackPoly_tag;
typedef struct dds3Polygon_t dds3Polygon_t;
typedef struct dds3SpPoly_Basic_t dds3SpPoly_Basic_t;
typedef struct dds3SpPoly_Ring_Old_t3 dds3SpPoly_Ring_Old_t3;
typedef struct dds3SpPoly_Ring_t3 dds3SpPoly_Ring_t3;
typedef struct dds3SpPoly_RollRing_t3 dds3SpPoly_RollRing_t3;
typedef struct dds3SpPoly_SphereRing_t3 dds3SpPoly_SphereRing_t3;
typedef struct dds3TrackPoly_t dds3TrackPoly_t;
typedef struct dds3TrianglePoly_t dds3TrianglePoly_t;
typedef struct polyManager_VCSetFuncDelegate polyManager_VCSetFuncDelegate;
typedef struct polyManager_pAlphaPkt polyManager_pAlphaPkt;
typedef struct sdf3DPrimPolyParm_t sdf3DPrimPolyParm_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfGrOt_t sdfGrOt_t;
typedef struct sdfGrPacketHeader_t sdfGrPacketHeader_t;
typedef struct sdfGrTagStdReg_t sdfGrTagStdReg_t;
typedef struct sdfMat_t sdfMat_t;
typedef struct sdfRandCB_t sdfRandCB_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

struct polyManager_pAlphaPkt {
    sdfGrPacketHeader_t *header;
    sdfGrTagStdReg_t *alpha;
};

static s32 DDS3POLYGON_ATTRBIT_SINGLESIDE;
static s32 DDS3POLYGON_ATTRBIT_LIGHTCOLOR;
static s32 DDS3POLYGON_TYPE_TEX;
static s32 DDS3POLYGON_TYPE_NORMAL;
static s32 DDS3POLYGON_TYPE_VC;
static s32 DDS3POLYGON_TYPE_STRIP;
static s32 DDS3POLYGON_TYPE_SEMITRANS;
static s32 DDS3POLYGON_TYPE_ADDTRANS;
static sdfGrOt_t *dds3Ot[1];
static u64 DDS3EFFECT_BLEND_NEG;
static u64 DDS3EFFECT_BLEND_SUB;
static dds3Polygon_t *hDrawListTop;
static sdfRandCB_t *PolyRand;
static u32 polySquareFaceIndex[90];
static u32 polySquareFaceIndex2[84];
static u32 polySquareFaceIndex3[90];
static u32 polySquareFaceIndex4[54];
static u32 polySquareFaceIndex5[72];
static sdf3DPrimPolyParm_t *TrackPolyParm;
static dds3TrackPoly_t *hTPDrawListTop;
static polyManager_VCSetFuncDelegate *VCSetFunc[5];
static sdfVector4_t abgr_s;
static sdfVector4_t abgr_e;
static dds3EffectTable_t *EffSpPolyTable[4];
static dds3EffectTable_Reset_t *ResetTbl[4];
static dds3EffectTable_Scale_t *ScaleTbl[4];
static f32 tp_alf_raito;

f32 DDS3EFFECT_RAND_FA(f32 r);
sdfColor_t **GetColor(XRD773Unity_CommonMesh *this);
s32 **GetIndexTable(XRD773Unity_CommonMesh *this);
XRD773Unity_CommonMesh *GetMesh(XRD773Unity_GraphicManager *this, s32 index, bool outlinechk);
sdfVector3_t **GetPosition(XRD773Unity_CommonMesh *this);
void MultMatrixNoArg(void);
void MultMatrixRevNoArg(void);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__ADDVECTOR_A_C(void);
void SDF_VU0__ADDVECTOR_B_C(void);
void SDF_VU0__APPLYMATRIX(void);
void SDF_VU0__APPLYMATRIX_B(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__COPYVECTOR_A_TO_B(void);
void SDF_VU0__COPYVECTOR_A_TO_C(void);
void SDF_VU0__COPYVECTOR_B_TO_A(void);
void SDF_VU0__COPYVECTOR_C_TO_A(void);
void SDF_VU0__COPYVECTOR_C_TO_B(void);
void SDF_VU0__INTERPOLATE(f32 rate);
void SDF_VU0__LOADMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__LOADMATRIX_B(sdfMatrix4_t *aMatrix);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_C(sdfVector4_t p);
void SDF_VU0__MULVECTOR(void);
void SDF_VU0__NORMALIZE(void);
void SDF_VU0__SCALEVECTOR(f32 v);
void SDF_VU0__SCALEVECTOR_B(f32 v);
void SDF_VU0__STOREMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__STOREVECTOR_B(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
void SDF_VU0__SUBVECTOR_B_C(void);
u32 SDF_VU0__dds3ColorFtoI(f32 ratio);
void SDF_VU0__dds3ColorItoF(u32 rgba);
void SetActive(XRD773Unity_GraphicManager_CommonObject *this, bool act);
void SetAutoHide(XRD773Unity_GraphicManager_CommonObject *this, bool act);
void SetColor_20241296(XRD773Unity_CommonMesh *this, sdfColor_t **col);
void SetIndexTable(XRD773Unity_CommonMesh *this, s32 **idx);
void SetPosition_20241056(XRD773Unity_CommonMesh *this, sdfVector3_t **pos);
void SetRotateMatrixX(f32 aAngle);
void SetRotateMatrixY_B(f32 aAngle);
void dds3SpPolyReset(void **hData);
u32 dds3SpPoly_Color(u32 frame, u32 frame_end, u32 abgr);
void dds3SpPoly_RingAllBuffInit(void **hData);
void dds3SpPoly_RingBuffInit(dds3SpPoly_Ring_t3 **pRing, s32 number);
void dds3SpPoly_RingMove(dds3SpPoly_Ring_t3 **pRing, s32 number);
void dds3SpPoly_RingNew(dds3SpPoly_Ring_t3 **pRing, s32 number, f32 radius);
void dds3SpPoly_Ring_Old_BuffInit(void **hData);
void dds3SpPoly_Ring_Old_Calc(dds3SpPoly_Ring_Old_t3 **pRing);
void dds3SpPoly_Ring_Old_Move(dds3SpPoly_Ring_Old_t3 **pRing, s32 number);
void dds3SpPoly_Ring_Old_New(dds3SpPoly_Ring_Old_t3 **pRing, s32 number);
void dds3SpPoly_Ring_Old_t3__pClone(dds3SpPoly_Ring_Old_t3 *this, dds3SpPoly_Ring_Old_t3 **dst);
void dds3SpPoly_Ring_Old_t3__pCopy(dds3SpPoly_Ring_Old_t3 *this, u8 **bytedata, s32 *bpos);
void dds3SpPoly_Ring_t3__pClone(dds3SpPoly_Ring_t3 *this, dds3SpPoly_Ring_t3 **dst);
void dds3SpPoly_Ring_t3__pCopy(dds3SpPoly_Ring_t3 *this, u8 **bytedata, s32 *bpos);
void dds3SpPoly_RollRingAllBuffInit(void **hData);
void dds3SpPoly_RollRingBuffInit(dds3SpPoly_RollRing_t3 **pRollRing, s32 number);
void dds3SpPoly_RollRingMove(dds3SpPoly_RollRing_t3 **pRollRing, s32 number);
void dds3SpPoly_RollRing_t3__pClone(dds3SpPoly_RollRing_t3 *this, dds3SpPoly_RollRing_t3 **dst);
void dds3SpPoly_RollRing_t3__pCopy(dds3SpPoly_RollRing_t3 *this, u8 **bytedata, s32 *bpos);
void dds3SpPoly_SphereRingAllBuffInit(void **hData);
void dds3SpPoly_SphereRingBuffInit(dds3SpPoly_SphereRing_t3 **pSphereRing, s32 number);
void dds3SpPoly_SphereRingMove(dds3SpPoly_SphereRing_t3 **pSphereRing, s32 number);
void dds3SpPoly_SphereRing_t3__pClone(dds3SpPoly_SphereRing_t3 *this, dds3SpPoly_SphereRing_t3 **dst);
void dds3SpPoly_SphereRing_t3__pCopy(dds3SpPoly_SphereRing_t3 *this, u8 **bytedata, s32 *bpos);
dds3TrackPoly_t *dds3TrackPolyCreate(s32 number, s32 face, s32 rec, s32 type);
void dds3TrackPolyDraw(dds3TrackPoly_t **hTrackPoly, char *funcname);
bool dds3TrackPolyDrawGetParam(s32 index, dds3TrackPoly_t **hTrackPoly, s32 *div, s32 *pmax, s32 *face, u32 ***face_index);
void dds3TrackPolyDrawOff(dds3TrackPoly_t **hTrackPoly);
void dds3TrackPolyListInit(dds3TrackPoly_t **hTrackPoly, s32 number);
void dds3TrackPolyVCSet(dds3TrackPoly_t **hTrackPoly, s32 type, u32 abgr_in, u32 abgr_out);
sdfColor_t effGetBlendColor(u32 icol);
sdfColor_t effGetVertexColor(u32 icol, sdfColor_t blend_col);
bool evtBitCheck(s32 no);
void pMeshDelete(dds3HermitianTrackPoly_tag **hPoly);
f32 sdfCos(f32 aRadius);
sdfMat_t *sdfMatNew(void);
void sdfMatSetConstant(sdfMat_t *aMat, f32 aRatio);
void sdfMatSetTex(sdfMat_t *aMat, sdfTexHandle_t *aTex);
void sdfRandomizeByTime(sdfRandCB_t **aCB);
f32 sdfSin(f32 aRadius);

// 0x154aae0
s32 SDF_GS_SET_ALPHA(s32 a, s32 b, s32 c, s32 d, s32 fix) {
  return a | (4 * b) | (16 * c) | fix | (d << 6);
}

// 0x154ac90
dds3Polygon_t *dds3PolygonCreate(s32 face, s16 type, s16 attr) {
  u64 v8;
  dds3Polygon_t_o *v9;
  struct sdf3DPrimPolyParm_t_o *parm;
  sdfMat_t_o *pMat;

  if ((DDS3POLYGON_TYPE_STRIP & type) != 0)
    v8 = (face + 2);
  else
    v8 = (3 * face);
  v9 = Allocate(dds3Polygon_t);
  dds3Polygon_t___ctor(v9);
  v9->pVertex = NewSpecific(UnityEngine_Vector4, v8);
  if ((DDS3POLYGON_TYPE_TEX & type) != 0)
  {
    v9->pUV = NewSpecific(UnityEngine_Vector2, v8);
  }
  if ((DDS3POLYGON_TYPE_NORMAL & type) != 0)
  {
    v9->pNormal = NewSpecific(UnityEngine_Vector4, v8);
  }
  if ((DDS3POLYGON_TYPE_VC & type) != 0)
  {
    v9->pVertexColor = NewSpecific(uint, v8);
  }
  parm = v9->parm;
  v9->type = type;
  v9->point = v8;
  v9->count = 0;
  v9->hMem = 0;
  parm->color = -2139062144;
  if ((DDS3POLYGON_ATTRBIT_SINGLESIDE & attr) == 0)
    v9->parm->attr = 0x4000;
  v9->pMat = sdfMatNew();
  else if ((DDS3POLYGON_ATTRBIT_LIGHTCOLOR & attr) != 0)
  {
    return v9;
  }
  pMat = v9->pMat;
  sdfMatSetConstant(pMat, 1.0);
  return v9;
}

// 0x154af20
void dds3PolygonDelete(dds3Polygon_t **hPolygon) {
  (*hPolygon)->type = 1;
}

// 0x154af30
void dds3PolygonDraw(dds3Polygon_t **hPolygon) {
  dds3Polygon_t_o *v4;

  v4 = *hPolygon;
  v4->next = hDrawListTop;
  hDrawListTop = *hPolygon;
}

// 0x154afc0
void dds3PolygonLinkOt(void) {
  ;
}

// 0x154ac80
void dds3PolygonManagerExit(void) {
  ;
}

// 0x154ab90
void dds3PolygonManagerInit(void) {
  hDrawListTop = 0;
  TrackPolyParm->attr = 0x4000;
  sdfRandomizeByTime(&PolyRand);
}

// 0x154b050
void dds3PolygonSetColor(dds3Polygon_t **hPolygon, u32 color) {
  (*hPolygon)->parm->color = color;
}

// 0x154afd0
void dds3PolygonSetTex(dds3Polygon_t **hPolygon, sdfTexHandle_t *hTex) {
  sdfMat_t_o *pMat;

  pMat = (*hPolygon)->pMat;
  sdfMatSetTex(pMat, hTex);
}

// 0x154b060
void dds3PolygonTriangleSet(dds3Polygon_t **hPolygon, sdfVector4_t center) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  dds3Polygon_t_o *v8;
  s64 count;
  struct UnityEngine_Vector4_array *pVertex;
  f32 *v12;
  struct UnityEngine_Vector4_array *v13;
  f32 v14;
  s64 v15;
  f32 v16;
  f32 v17;
  Il2CppObject *v19;
  struct UnityEngine_Vector4_array *v21;
  f32 v22;
  s64 v23;
  f32 v24;
  f32 v25;
  Il2CppObject *v27;
  s32 type;
  struct UnityEngine_Vector4_array *pNormal;
  s32 v31;
  s32 v32;
  s32 v33;
  Il2CppObject *v35;
  struct UnityEngine_Vector4_array *v36;
  s32 v37;
  s32 v38;
  s32 v39;
  Il2CppObject *v41;
  struct UnityEngine_Vector4_array *v42;
  s32 v43;
  s32 v44;
  s32 v45;
  Il2CppObject *v47;
  s32 v48;
  struct System_UInt32_array *pVertexColor;
  struct System_UInt32_array *v51;
  struct System_UInt32_array *v53;
  s64 v55;
  s64 v56;
  f32 v57;
  f32 v58;
  f32 v59;
  f32 v60;

  w = center.w;
  z = center.z;
  y = center.y;
  x = center.x;
  v55 = 0;
  v56 = 0;
  v8 = *hPolygon;
  count = (*hPolygon)->count;
  v57 = x;
  v58 = y;
  v59 = z;
  v60 = w;
  pVertex = v8->pVertex;
  v12 = (&pVertex->obj + count);
  v12[8] = x;
  v12[9] = y;
  v12[10] = z;
  v12[11] = w;
  sub_854710(&v57, 1u);
  sub_854930(&v57, 1u);
  v13 = (*hPolygon)->pVertex;
  v14 = v58;
  v15 = count + 1;
  v17 = v59;
  v16 = v60;
  v19 = &v13->obj + v15;
  *&v19[2].klass = v57;
  *(&v19[2].klass + 1) = v14;
  *&v19[2].monitor = v17;
  *(&v19[2].monitor + 1) = v16;
  sub_854710(&v57, 2u);
  sub_854930(&v57, 2u);
  v21 = (*hPolygon)->pVertex;
  v22 = v58;
  v23 = count + 2;
  v25 = v59;
  v24 = v60;
  v27 = &v21->obj + v23;
  *&v27[2].klass = v57;
  *(&v27[2].klass + 1) = v22;
  *&v27[2].monitor = v25;
  *(&v27[2].monitor + 1) = v24;
  type = (*hPolygon)->type;
  else if ((DDS3POLYGON_TYPE_NORMAL & type) == 0)
  {
    goto LABEL_19;
  }
  sub_854690(&v55, 0.0, 0.0, -1.0, 0.0);
  pNormal = (*hPolygon)->pNormal;
  v31 = HIDWORD(v55);
  v33 = v56;
  v32 = HIDWORD(v56);
  v35 = &pNormal->obj + count;
  LODWORD(v35[2].klass) = v55;
  HIDWORD(v35[2].klass) = v31;
  LODWORD(v35[2].monitor) = v33;
  HIDWORD(v35[2].monitor) = v32;
  v36 = (*hPolygon)->pNormal;
  v37 = HIDWORD(v55);
  v39 = v56;
  v38 = HIDWORD(v56);
  v41 = &v36->obj + v15;
  LODWORD(v41[2].klass) = v55;
  HIDWORD(v41[2].klass) = v37;
  LODWORD(v41[2].monitor) = v39;
  HIDWORD(v41[2].monitor) = v38;
  v42 = (*hPolygon)->pNormal;
  v43 = HIDWORD(v55);
  v45 = v56;
  v44 = HIDWORD(v56);
  v47 = &v42->obj + v23;
  LODWORD(v47[2].klass) = v55;
  HIDWORD(v47[2].klass) = v43;
  LODWORD(v47[2].monitor) = v45;
  HIDWORD(v47[2].monitor) = v44;
LABEL_19:
  v48 = (*hPolygon)->type;
  else if ((DDS3POLYGON_TYPE_VC & v48) == 0)
  {
    goto LABEL_29;
  }
  pVertexColor = (*hPolygon)->pVertexColor;
  pVertexColor->m_Items[count] = -2147483520;
  v51 = (*hPolygon)->pVertexColor;
  v51->m_Items[v15] = -2147483520;
  v53 = (*hPolygon)->pVertexColor;
  v53->m_Items[v23] = -2147483520;
LABEL_29:
  (*hPolygon)->count += 3;
}

// 0x1555210
dds3SpPoly_Basic_t *dds3SpPolyCopy(void **hData, s32 bPos) {
  s32 v3;
  u16 *v5;
  s64 v6;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  struct dds3EffectTable_t_array *EffSpPolyTable;
  s64 v12;
  dds3SpPoly_Basic_t_o *result;
  dds3SpPoly_Basic_t_c *klass;
  s64 v16;
  char *v17;
  s64 *v18;
  u64 v19[2];
  char *v20;

  v3 = bPos;
  v5 = *hData;
  if (*hData)
  {
    v6 = *v5;
    if (*(*v5 + 288LL) < typeHierarchyDepth
      || *(*(v6 + 200) + 8 * typeHierarchyDepth - 8) != dds3SpPoly_Basic_t)
    {
      sub_8FC2C0(*(v6 + 64), dds3SpPoly_Basic_t, v19);
      if ((v19[0] & 1) != 0)
        v8 = v20;
      else
        v8 = v19 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v12 = v5[96];
  result = dds3EffectTable_t_CreateDelegate__Invoke(EffSpPolyTable->m_Items[v12]->Create, *hData, v3, 1, 0);
  klass = result->klass;
  if (result->klass->_2.typeHierarchyDepth < v16
    || klass->_2.typeHierarchy[v16 - 1] != dds3SpPoly_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3SpPoly_Basic_t, v19);
    if ((v19[0] & 1) != 0)
      v17 = v20;
    else
      v17 = v19 + 1;
    v18 = sub_8C4940(v17);
  }
  result->type = v5[96];
  result->state = 1;
  return result;
}

// 0x15550a0
dds3SpPoly_Basic_t *dds3SpPolyCreate(u16 type, void *pData, s32 bPos) {
  struct dds3EffectTable_t_array *EffSpPolyTable;
  dds3SpPoly_Basic_t_o *result;
  dds3SpPoly_Basic_t_c *klass;
  s64 typeHierarchyDepth;
  char *v13;
  s64 *v14;
  u64 v15[3];

  result = dds3EffectTable_t_CreateDelegate__Invoke(EffSpPolyTable->m_Items[type]->Create, pData, bPos, 0, 0);
  klass = result->klass;
  if (result->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SpPoly_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3SpPoly_Basic_t, v15);
    if ((v15[0] & 1) != 0)
      v13 = v15[2];
    else
      v13 = v15 + 1;
    v14 = sub_8C4940(v13);
  }
  result->type = type;
  result->state = 1;
  return result;
}

// 0x1555410
void dds3SpPolyDelete(void **hData) {
  u16 *v3;
  s64 v4;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  struct dds3EffectTable_t_array *EffSpPolyTable;
  s64 v10;
  u64 v12[3];

  v3 = *hData;
  if (*hData)
  {
    v4 = *v3;
    if (*(*v3 + 288LL) < typeHierarchyDepth
      || *(*(v4 + 200) + 8 * typeHierarchyDepth - 8) != dds3SpPoly_Basic_t)
    {
      sub_8FC2C0(*(v4 + 64), dds3SpPoly_Basic_t, v12);
      if ((v12[0] & 1) != 0)
        v6 = v12[2];
      else
        v6 = v12 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v10 = v3[96];
  dds3EffectTable_t_DeleteDelegate__Invoke(EffSpPolyTable->m_Items[v10]->Delete, hData);
}

// 0x1555580
void dds3SpPolyDraw(void **hData) {
  u16 *v3;
  s64 v4;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  struct dds3EffectTable_t_array *EffSpPolyTable;
  s64 v10;
  u64 v12[3];

  v3 = *hData;
  if (*hData)
  {
    v4 = *v3;
    if (*(*v3 + 288LL) < typeHierarchyDepth
      || *(*(v4 + 200) + 8 * typeHierarchyDepth - 8) != dds3SpPoly_Basic_t)
    {
      sub_8FC2C0(*(v4 + 64), dds3SpPoly_Basic_t, v12);
      if ((v12[0] & 1) != 0)
        v6 = v12[2];
      else
        v6 = v12 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v10 = v3[96];
  dds3EffectTable_t_DrawDelegate__Invoke(EffSpPolyTable->m_Items[v10]->Draw, hData);
}

// 0x1555570
void dds3SpPolyDrawOff(void **hData) {
  ;
}

// 0x1555f40
u8 dds3SpPolyGetLoop(void **hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v8[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SpPoly_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3SpPoly_Basic_t, v8);
    if ((v8[0] & 1) != 0)
      v6 = v8[2];
    else
      v6 = v8 + 1;
    v7 = sub_8C4940(v6);
  }
  return BYTE4((*hData)[7].klass);
}

// 0x15559b0
u16 dds3SpPolyGetState(void **hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v8[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SpPoly_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3SpPoly_Basic_t, v8);
    if ((v8[0] & 1) != 0)
      v6 = v8[2];
    else
      v6 = v8 + 1;
    v7 = sub_8C4940(v6);
  }
  return WORD1((*hData)[12].klass);
}

// 0x15556e0
void dds3SpPolyReset(void **hData) {
  u16 *v3;
  s64 v4;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  struct dds3EffectTable_Reset_t_array *ResetTbl;
  s64 v10;
  u64 v12[3];

  v3 = *hData;
  if (*hData)
  {
    v4 = *v3;
    if (*(*v3 + 288LL) < typeHierarchyDepth
      || *(*(v4 + 200) + 8 * typeHierarchyDepth - 8) != dds3SpPoly_Basic_t)
    {
      sub_8FC2C0(*(v4 + 64), dds3SpPoly_Basic_t, v12);
      if ((v12[0] & 1) != 0)
        v6 = v12[2];
      else
        v6 = v12 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v10 = v3[96];
  dds3EffectTable_Reset_t_ResetDelegate__Invoke(ResetTbl->m_Items[v10]->Reset, hData);
  v3[97] = 1;
}

// 0x1555e40
void dds3SpPolySetLoop(void **hData, u8 loop) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  v5 = *hData;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SpPoly_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3SpPoly_Basic_t, v10);
    if ((v10[0] & 1) != 0)
      v8 = v10[2];
    else
      v8 = v10 + 1;
    v9 = sub_8C4940(v8);
  }
  if (!LOWORD(v5[12].klass))
    BYTE4(v5[7].klass) = loop;
  BYTE4(v5[7].klass) = loop;
}

// 0x1555aa0
void dds3SpPolySetPosition(void **hData, sdfVector4_t pPos) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  UnityEngine_Vector4_o *v8;
  s64 v9;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  u64 v13[3];
  UnityEngine_Vector4_o v14;

  w = pPos.w;
  z = pPos.z;
  y = pPos.y;
  x = pPos.x;
  v8 = *hData;
  if (*hData)
  {
    v9 = *&v8->x;
    if (*(*&v8->x + 288LL) < typeHierarchyDepth
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != dds3SpPoly_Basic_t)
    {
      sub_8FC2C0(*(v9 + 64), dds3SpPoly_Basic_t, v13);
      if ((v13[0] & 1) != 0)
        v11 = v13[2];
      else
        v11 = v13 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  v14.x = x;
  v14.y = y;
  v14.z = z;
  v14.w = w;
  SDF_VU0__COPYVECTOR(v8 + 1, v14);
}

// 0x1555d50
void dds3SpPolySetRGBA(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SpPoly_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3SpPoly_Basic_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[7].klass) = abgr;
}

// 0x1555bd0
void dds3SpPolySetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
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
  Il2CppClass *v16;
  void *monitor;
  void *v18;
  Il2CppClass *v19;
  void *v20;
  void *v21;
  UnityEngine_Matrix4x4_o v23;
  UnityEngine_Matrix4x4_o v24;
  u64 v25[3];

  v5 = *&pMatrix->m00;
  v6 = *&pMatrix->m20;
  v7 = *hData;
  v8 = *&pMatrix->m21;
  *&v24.m01 = *&pMatrix->m01;
  *&v24.m21 = v8;
  *&v24.m00 = v5;
  *&v24.m20 = v6;
  v9 = *&pMatrix->m02;
  v10 = *&pMatrix->m22;
  v11 = *&pMatrix->m23;
  *&v24.m03 = *&pMatrix->m03;
  *&v24.m23 = v11;
  *&v24.m02 = v9;
  *&v24.m22 = v10;
  SDF_VU0__LOADMATRIX(&v24);
  if (v7)
  {
    klass = v7->klass;
    if (v7->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SpPoly_Basic_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3SpPoly_Basic_t, v25);
      if ((v25[0] & 1) != 0)
        v14 = v25[2];
      else
        v14 = v25 + 1;
      v15 = sub_8C4940(v14);
    }
  }
  v16 = v7[8].klass;
  monitor = v7[8].monitor;
  v18 = v7[9].monitor;
  *&v23.m01 = v7[9].klass;
  *&v23.m21 = v18;
  *&v23.m00 = v16;
  *&v23.m20 = monitor;
  v19 = v7[10].klass;
  v20 = v7[10].monitor;
  v21 = v7[11].monitor;
  *&v23.m03 = v7[11].klass;
  *&v23.m23 = v21;
  *&v23.m02 = v19;
  *&v23.m22 = v20;
  SDF_VU0__LOADMATRIX_B(&v23);
  MultMatrixNoArg();
  SDF_VU0__STOREMATRIX(&v7[3]);
}

// 0x1555840
void dds3SpPolySetScale(void **hData, f32 scale) {
  u16 *v5;
  s64 v6;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  struct dds3EffectTable_Scale_t_array *ScaleTbl;
  s64 v12;
  u64 v15[3];

  v5 = *hData;
  if (*hData)
  {
    v6 = *v5;
    if (*(*v5 + 288LL) < typeHierarchyDepth
      || *(*(v6 + 200) + 8 * typeHierarchyDepth - 8) != dds3SpPoly_Basic_t)
    {
      sub_8FC2C0(*(v6 + 64), dds3SpPoly_Basic_t, v15);
      if ((v15[0] & 1) != 0)
        v8 = v15[2];
      else
        v8 = v15 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v12 = v5[96];
  dds3EffectTable_Scale_t_ScaleDelegate__Invoke(ScaleTbl->m_Items[v12]->Scale, hData, scale);
  dds3SpPolyReset(hData);
}

// 0x1551a40
u32 dds3SpPoly_Color(u32 frame, u32 frame_end, u32 abgr) {
  f32 v7;
  f32 v8;
  f32 v9;

  if ((byte_3F59C84 & 1) == 0)
  {
    if (frame < frame_end)
      goto LABEL_3;
LABEL_5:
    v9 = 1.0;
    goto LABEL_6;
  }
  if (frame >= frame_end)
    goto LABEL_5;
LABEL_3:
  v7 = frame;
  v8 = frame_end;
  v9 = v7 / v8;
LABEL_6:
  SDF_VU0__LOADVECTOR(abgr_e);
  SDF_VU0__LOADVECTOR_B(abgr_s);
  SDF_VU0__SCALEVECTOR(1.0 - v9);
  SDF_VU0__SCALEVECTOR_B(v9);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__COPYVECTOR_A_TO_B();
  SDF_VU0__dds3ColorItoF(abgr);
  SDF_VU0__MULVECTOR();
  return SDF_VU0__dds3ColorFtoI(128.0);
}

// 0x1551b60
void dds3SpPoly_RingAllBuffInit(void **hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v5;
  s64 v6;
  s32 namespaze;
  u64 v8;
  s32 v9;
  u32 *declaringType;
  u64 *v12;
  Il2CppClass *v14;
  s64 v16;
  char *v17;
  s64 *v18;
  u64 v19[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SpPoly_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3SpPoly_Basic_t, v19);
    if ((v19[0] & 1) != 0)
      v17 = v19[2];
    else
      v17 = v19 + 1;
    v18 = sub_8C4940(v17);
  }
  v5 = (*hData)[13].klass;
  v6 = *(v5->_1.name + 8);
  if (v6)
  {
    namespaze = v5->_1.namespaze;
    v8 = 0;
    v9 = -16777215;
    do
    {
      declaringType = v5->_1.declaringType;
      v12 = Allocate(dds3SpPoly_RingPhysics_t);
      dds3SpPoly_RingPhysics_t___ctor(v12);
      *&declaringType[2 * v8 + 8] = v12;
      v14 = v5->_1.declaringType;
      v16 = *(&v14->_1.byval_arg.data + v8);
      if (v16)
      {
        *(v16 + 16) = v9;
        v9 -= namespaze;
      }
      ++v8;
    }
    while (v6 != v8);
  }
}

// 0x1551d40
void dds3SpPoly_RingBuffInit(dds3SpPoly_Ring_t3 **pRing, s32 number) {
  dds3SpPoly_Ring_t3_o *v5;
  struct dds3SpPoly_RingPhysics_t_array *pPhysics;
  dds3SpPoly_RingPhysics_t_o *v8;
  f32 radius_s_r;
  f32 radius_s;
  f32 v11;
  f32 radius_e;
  f32 v15;
  s32 frame;
  f32 v17;

  v5 = *pRing;
  pPhysics = (*pRing)->pPhysics;
  v8 = pPhysics->m_Items[number];
  radius_s_r = v5->radius_s_r;
  radius_s = v5->radius_s;
  v11 = radius_s * DDS3EFFECT_RAND_FA(radius_s_r);
  radius_e = (*pRing)->radius_e;
  v15 = DDS3EFFECT_RAND_FA((*pRing)->radius_e_r, 0);
  v8->frame = 0;
  frame = (*pRing)->basic->frame;
  v17 = (radius_e * v15) - v11;
  if (frame >= 1)
    v17 = v17 / frame;
  v8->spread_s = v17;
  dds3SpPoly_RingNew(pRing, number, v11);
}

// 0x15526f0
dds3SpPoly_Basic_t *dds3SpPoly_RingCreate(void *hData, s32 bPos, bool pCopy, s32 billno) {
  u64 *v7;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v10;
  s64 *Interface;
  System_Byte_array *v12;
  char *v13;
  s64 *v14;
  dds3SpPoly_Ring_t3_o *v15;
  struct dds3SpPoly_RingPhysics_t_array *v16;
  u32 vertex;
  s32 number;
  dds3TrackPoly_t_o **p_hTrackPoly;
  char *v25;
  s64 *v26;
  UnityEngine_Matrix4x4_o dest;
  Il2CppObject *hDataa;
  dds3SpPoly_Ring_t3_o *dst;
  u64 v30[2];
  char *v31;
  s32 bpos;

  bpos = bPos;
  hDataa = 0;
  v7 = Allocate(dds3SpPoly_Ring_t3);
  dds3SpPoly_Ring_t3___ctor(v7);
  dst = v7;
  if (pCopy)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SpPoly_Basic_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3SpPoly_Basic_t, v30);
      if ((v30[0] & 1) != 0)
        v25 = v31;
      else
        v25 = v30 + 1;
      v26 = sub_8C4940(v25);
    }
    dds3SpPoly_Ring_t3__pClone(hData[13].klass, &dst);
  }
  else
  {
    if (hData)
    {
      Interface = QueryInterface(hData, byte);
      if (!Interface)
      {
        sub_8FC2C0(hData->klass->_1.element_class, v10, v30);
        if ((v30[0] & 1) != 0)
          v13 = v31;
        else
          v13 = v30 + 1;
        v14 = sub_8C4940(v13);
      }
      v12 = Interface;
    }
    else
    {
      v12 = 0;
    }
    dds3SpPoly_Ring_t3__pCopy(v7, v12, &bpos);
  }
  v15 = dst;
  dst->basic->pRing = dst;
  v16 = NewSpecific(dds3SpPoly_RingPhysics_t, v15->basic->number);
  vertex = v15->vertex;
  v15->pPhysics = v16;
  if (vertex <= 2)
  {
    vertex = 3;
    v15->vertex = 3;
  }
  number = v15->basic->number;
  v15->hTrackPoly = dds3TrackPolyCreate(number, vertex, 1, 0);
  p_hTrackPoly = &v15->hTrackPoly;
  dds3TrackPolyVCSet(p_hTrackPoly, 0, *(p_hTrackPoly - 1), *(p_hTrackPoly - 3));
  hDataa = *(p_hTrackPoly - 7);
  dds3SpPoly_RingAllBuffInit(&hDataa);
  memmove(&dest, &(*(p_hTrackPoly - 7))->pVertex, 0x40u);
  SDF_VU0__LOADMATRIX(&dest);
  SDF_VU0__STOREMATRIX(&(*(p_hTrackPoly - 7))[1].point, 0);
  (*p_hTrackPoly)->mode = HIWORD((*(p_hTrackPoly - 7))[1].monitor);
  return *(p_hTrackPoly - 7);
}

// 0x15529a0
void dds3SpPoly_RingDelete(void **hData) {
  dds3SpPoly_Basic_t_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v6;
  dds3TrackPoly_t_o **p_castClass;
  char *v8;
  s64 *v9;
  u64 v10[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SpPoly_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3SpPoly_Basic_t, v10);
    if ((v10[0] & 1) != 0)
      v8 = v10[2];
    else
      v8 = v10 + 1;
    v9 = sub_8C4940(v8);
  }
  v6 = (*hData)[13].klass;
  p_castClass = &v6->_1.castClass;
LABEL_9:
  pMeshDelete(p_castClass, v3);
}

// 0x1552c30
void dds3SpPoly_RingDraw(void **hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3SpPoly_Ring_t3_o *v8;
  struct dds3SpPoly_Basic_t_o *basic;
  s32 frame;
  u64 v11;
  s64 v12;
  u32 v13;
  u32 v14;
  struct dds3SpPoly_RingPhysics_t_array *pPhysics;
  dds3SpPoly_RingPhysics_t_o *v17;
  struct dds3TrackPolyList_t_array *trackList;
  Il2CppClass **v20;
  signed s32 v21;
  Il2CppClass *v22;
  struct dds3SpPoly_Basic_t_o *v23;
  s64 alpha_s;
  u32 v25;
  u32 alpha_e;
  s32 v27;
  char *v28;
  s64 *v29;
  s64 number;
  u32 abgr;
  s32 loop;
  dds3SpPoly_Ring_t3_o *pRing;
  u64 v34[3];

  pRing = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SpPoly_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3SpPoly_Basic_t, v34);
    if ((v34[0] & 1) != 0)
      v28 = v34[2];
    else
      v28 = v34 + 1;
    v29 = sub_8C4940(v28);
  }
  v8 = (*hData)[13].klass;
  pRing = v8;
  basic = v8->basic;
  number = basic->number;
  if (basic->number >= 1)
  {
    frame = basic->frame;
    abgr = basic->abgr;
    loop = basic->loop;
    v11 = 0;
    LODWORD(v12) = 0;
    while (1)
    {
      pPhysics = v8->pPhysics;
      v17 = pPhysics->m_Items[v11];
      if (!v17)
        goto LABEL_45;
      trackList = v8->hTrackPoly->trackList;
      v20 = &trackList->obj.klass + v11;
      v21 = v17->frame;
      v22 = v20[4];
      if (v21 == -16777215)
      {
        dds3SpPoly_RingBuffInit(&pRing, v11);
        v21 = v17->frame;
      }
      if (v21 < 0)
        goto LABEL_36;
      v23 = v8->basic;
      alpha_s = v23->alpha_s;
      if (v21 < alpha_s)
        break;
      if (frame >= v21)
      {
        alpha_e = v23->alpha_e;
        if (frame - alpha_e <= v21)
        {
          v13 = frame - v21;
          v14 = alpha_e;
LABEL_27:
          v25 = dds3SpPoly_Color(v13, v14, abgr);
          v22->_1.byval_arg.bits = v25;
          if (HIBYTE(v25))
            goto LABEL_32;
          goto LABEL_39;
        }
      }
      if (HIBYTE(v22->_1.byval_arg.bits))
      {
LABEL_32:
        dds3SpPoly_RingMove(&pRing, v11);
LABEL_36:
        v27 = v21 + 1;
        if (v21 + 1 >= frame)
          goto LABEL_37;
        goto LABEL_44;
      }
LABEL_39:
      LODWORD(v22->_1.byval_arg.data) = 0;
      v27 = v21 + 1;
      if (v21 + 1 >= frame)
      {
LABEL_37:
        if (loop)
        {
          v27 = -16777215;
        }
        else
        {
          v12 = (v12 + 1);
          if (v12 >= number)
            v8->basic->state = 0;
        }
        LODWORD(v22->_1.byval_arg.data) = 0;
      }
LABEL_44:
      v17->frame = v27;
LABEL_45:
      if (number == ++v11)
        goto LABEL_46;
    }
    v13 = v21;
    v14 = alpha_s;
    goto LABEL_27;
  }
LABEL_46:
  dds3TrackPolyDraw(&v8->hTrackPoly, "");
}

// 0x1552290
void dds3SpPoly_RingMove(dds3SpPoly_Ring_t3 **pRing, s32 number) {
  u64 v3;
  struct dds3TrackPoly_t_o *hTrackPoly;
  struct dds3TrackPolyList_t_array *trackList;
  dds3TrackPolyList_t_o *v10;
  struct UnityEngine_Vector4_array *pVertex;
  s32 v12;
  s32 v14;
  f32 v15;
  f32 v16;
  f32 v17;
  u64 v18;
  UnityEngine_Vector4_o *m_Items;
  struct UnityEngine_Vector4_array *v24;
  f32 *v26;
  f32 v28;
  f32 v29;
  f32 v30;
  f32 v31;
  s64 v32;
  UnityEngine_Matrix4x4_o v35;
  UnityEngine_Vector4_o v36;
  UnityEngine_Vector4_o v37;
  UnityEngine_Vector4_o v38;
  UnityEngine_Vector4_o v39;

  *&v38.x = 0;
  *&v38.z = 0;
  *&v37.x = 0;
  *&v37.z = 0;
  *&v36.x = 0;
  *&v36.z = 0;
  hTrackPoly = (*pRing)->hTrackPoly;
  trackList = hTrackPoly->trackList;
  v10 = trackList->m_Items[number];
  v10->count = hTrackPoly->point;
  pVertex = v10->pVertex;
  v12 = hTrackPoly->point >> 1;
  sub_854930(&v37, 0);
  sub_854710(&v37, 0);
  sub_854930(&v37, 1u);
  sub_854930(&v37, 2u);
  sub_854930(&v36, 1u);
  sub_854930(&v36, 0);
  sub_854930(&v36, 2u);
  LODWORD(v3) = (*pRing)->vertex;
  memmove(&v35, &(*pRing)->basic->rot, 0x40u);
  SDF_VU0__LOADMATRIX(&v35);
  v14 = v12 - 1;
  if (v12 - 1 < 1)
  {
    LODWORD(v18) = 0;
    v24 = v10->pVertex;
    if (LODWORD(v24->max_length))
      goto LABEL_22;
LABEL_30:
  }
  v15 = v3;
  v16 = 6.2832 / v15;
  v17 = 0.0;
  v18 = 0;
  m_Items = pVertex->m_Items;
  do
  {
    sdfCos(v17);
    sub_854930(&v38, 0);
    sub_854930(&v38, 1u);
    sdfSin(v17);
    sub_854930(&v38, 2u);
    SDF_VU0__LOADVECTOR(v38);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__LOADVECTOR_B(v37);
    SDF_VU0__MULVECTOR();
    SDF_VU0__LOADVECTOR_B(v36);
    SDF_VU0__APPLYMATRIX_B();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__LOADVECTOR_B(m_Items[1]);
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(m_Items + 1);
    SDF_VU0__COPYVECTOR_C_TO_A();
    SDF_VU0__LOADVECTOR_B(*m_Items);
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(m_Items);
    v17 = v16 + v17;
    v18 += 2LL;
    m_Items += 2;
    --v14;
  }
  while (v14);
  v24 = v10->pVertex;
  if (!LODWORD(v24->max_length))
    goto LABEL_30;
LABEL_22:
  SDF_VU0__COPYVECTOR(&pVertex->m_Items[v18], v24->m_Items[0]);
  v26 = v10->pVertex;
  v28 = v26[12];
  v29 = v26[13];
  v30 = v26[14];
  v31 = v26[15];
  v32 = v18 | 1;
  v39.x = v28;
  v39.y = v29;
  v39.z = v30;
  v39.w = v31;
  SDF_VU0__COPYVECTOR(&pVertex->m_Items[v32], v39);
}

// 0x1551e70
void dds3SpPoly_RingNew(dds3SpPoly_Ring_t3 **pRing, s32 number, f32 radius) {
  struct dds3TrackPoly_t_o *hTrackPoly;
  struct dds3TrackPolyList_t_array *trackList;
  dds3TrackPolyList_t_o *v9;
  struct UnityEngine_Vector4_array *pVertex;
  s32 v11;
  s32 v12;
  u64 v13;
  s32 v15;
  f32 v16;
  f32 v17;
  f32 v18;
  u64 v19;
  UnityEngine_Vector4_o *v20;
  struct UnityEngine_Vector4_array *v23;
  f32 *v25;
  f32 v27;
  f32 v28;
  f32 v29;
  f32 v30;
  s64 v31;
  UnityEngine_Matrix4x4_o v34;
  UnityEngine_Vector4_o v35;
  UnityEngine_Vector4_o v36;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v38;

  *&p.x = 0;
  *&p.z = 0;
  *&v36.x = 0;
  *&v36.z = 0;
  *&v35.x = 0;
  *&v35.z = 0;
  hTrackPoly = (*pRing)->hTrackPoly;
  trackList = hTrackPoly->trackList;
  v9 = trackList->m_Items[number];
  v9->count = hTrackPoly->point;
  pVertex = v9->pVertex;
  v11 = hTrackPoly->point / 2;
  sub_854930(&v36, 0);
  sub_854710(&v36, 0);
  sub_854930(&v36, 1u);
  sub_854930(&v36, 2u);
  sub_854710(&v36, 0);
  sub_854930(&v35, 0);
  sub_854710(&v35, 0);
  HIDWORD(v13) = v12;
  sub_854930(&v35, 1u);
  sub_854930(&v35, 2u);
  LODWORD(v13) = (*pRing)->vertex;
  memmove(&v34, &(*pRing)->basic->rot, 0x40u);
  SDF_VU0__LOADMATRIX(&v34);
  SDF_VU0__LOADVECTOR_C((*pRing)->basic->pos, 0);
  v15 = v11 - 1;
  if (v11 - 1 < 1)
  {
    LODWORD(v19) = 0;
    v23 = v9->pVertex;
    if (LODWORD(v23->max_length))
      goto LABEL_16;
LABEL_24:
  }
  v16 = v13;
  v17 = 6.2832 / v16;
  v18 = 0.0;
  v19 = 0;
  v20 = &pVertex->m_Items[1];
  do
  {
    sdfCos(v18);
    sub_854930(&p, 0);
    sub_854930(&p, 1u);
    sdfSin(v18);
    sub_854930(&p, 2u);
    SDF_VU0__LOADVECTOR(p);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(&p);
    SDF_VU0__LOADVECTOR_B(v36);
    SDF_VU0__MULVECTOR();
    SDF_VU0__ADDVECTOR_A_C();
    SDF_VU0__STOREVECTOR(v20);
    SDF_VU0__LOADVECTOR(p);
    SDF_VU0__LOADVECTOR_B(v35);
    SDF_VU0__MULVECTOR();
    SDF_VU0__ADDVECTOR_A_C();
    SDF_VU0__STOREVECTOR(v20 - 1);
    v18 = v17 + v18;
    v19 += 2LL;
    v20 += 2;
    --v15;
  }
  while (v15);
  v23 = v9->pVertex;
  if (!LODWORD(v23->max_length))
    goto LABEL_24;
LABEL_16:
  SDF_VU0__COPYVECTOR(&pVertex->m_Items[v19], v23->m_Items[0]);
  v25 = v9->pVertex;
  v27 = v25[12];
  v28 = v25[13];
  v29 = v25[14];
  v30 = v25[15];
  v31 = v19 | 1;
  v38.x = v27;
  v38.y = v28;
  v38.z = v29;
  v38.w = v30;
  SDF_VU0__COPYVECTOR(&pVertex->m_Items[v31], v38);
}

// 0x1552b10
void dds3SpPoly_RingSetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  f32 *v7;
  f32 v8;
  f32 v9;
  f32 v10;
  char *v11;
  s64 *v12;
  u64 v13[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SpPoly_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3SpPoly_Basic_t, v13);
    if ((v13[0] & 1) != 0)
      v11 = v13[2];
    else
      v11 = v13 + 1;
    v12 = sub_8C4940(v11);
  }
  v7 = (*hData)[13].klass;
  v8 = v7[8] * scale;
  v9 = v7[9] * scale;
  v7[13] = v7[13] * scale;
  v10 = v7[10];
  v7[8] = v8;
  v7[9] = v9;
  v7[10] = v10 * scale;
}

// 0x15503b0
void dds3SpPoly_Ring_Old_BuffInit(void **hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  u64 *monitor;
  s64 v6;
  u32 v7;
  s64 v8;
  u16 v9;
  s32 v10;
  s64 v11;
  u16 v12;
  s64 v14;
  s64 v15;
  s64 v17;
  s64 v19;
  char *v21;
  s64 *v22;
  u64 v23[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SpPoly_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3SpPoly_Basic_t, v23);
    if ((v23[0] & 1) != 0)
      v21 = v23[2];
    else
      v21 = v23 + 1;
    v22 = sub_8C4940(v21);
  }
  monitor = (*hData)[12].monitor;
  v6 = monitor[2];
  v7 = *(v6 + 32);
  if (*(v6 + 32))
  {
    v8 = monitor[7];
    v9 = 0;
    v10 = -16777215;
    do
    {
      v11 = monitor[8];
      v12 = v9;
      v14 = *(v8 + 40);
      v15 = *(v11 + 8LL * v9 + 32);
      *(*(v14 + 8LL * v9 + 32) + 36LL) = 0;
      v17 = *(v8 + 40);
      *(*(v17 + 8LL * v9 + 32) + 32LL) = 0;
      v19 = *(v8 + 40);
      *(*(v19 + 8LL * v9 + 32) + 40LL) = 8421504;
      *(v15 + 16) = v10;
      v10 -= *(monitor + 7);
      ++v9;
    }
    while (v7 > (v12 + 1));
  }
}

// 0x15505a0
void dds3SpPoly_Ring_Old_Calc(dds3SpPoly_Ring_Old_t3 **pRing) {
  dds3SpPoly_Ring_Old_t3_o *v4;
  struct dds3SpPoly_Basic_t_o *basic;
  u32 number_low;
  s32 frame;
  f32 v8;
  u32 v9;
  struct dds3SpPoly_Ring_Old_Physics_t_array *pPhysics;
  struct dds3TrackPolyList_t_array *trackList;
  dds3SpPoly_Ring_Old_Physics_t_o *v13;
  s32 v15;
  dds3TrackPolyList_t_o *v16;
  f32 v17;
  s32 v18;
  s32 v19;
  s32 v20;
  struct dds3SpPoly_Ring_Old_Physics_t_array *v21;
  struct dds3TrackPolyList_t_array *v23;
  dds3SpPoly_Ring_Old_Physics_t_o *v24;
  s32 v26;
  dds3TrackPolyList_t_o *v27;
  f32 v28;
  s32 v29;

  v4 = *pRing;
  basic = (*pRing)->basic;
  if (basic->state)
  {
    number_low = LOWORD(basic->number);
    if (LOWORD(basic->number))
    {
      frame = basic->frame;
      v8 = 128.0 / frame;
      v9 = 0;
      if (v4->loop)
      {
        while (1)
        {
          pPhysics = v4->pPhysics;
          trackList = v4->hTrackPoly->trackList;
          v13 = pPhysics->m_Items[v9];
          v15 = v13->frame;
          v16 = trackList->m_Items[v9];
          if (v15 == -16777215)
          {
            dds3SpPoly_Ring_Old_New(pRing, v9);
            v13->frame = 0;
            if (frame > -16777215)
              goto LABEL_26;
          }
          else
          {
            if ((v15 & 0x80000000) == 0)
            {
              v17 = v8 * (frame - v15);
              v18 = v17;
              if (v17 >= 0.0)
                LOBYTE(v18) = v17;
              v16->color = (v18 << 24) | 0x808080;
              dds3SpPoly_Ring_Old_Move(pRing, v9);
            }
            if (frame > v15)
            {
LABEL_26:
              v19 = v13->frame + 1;
              goto LABEL_28;
            }
          }
          v16->color = 8421504;
          v19 = -16777215;
LABEL_28:
          v13->frame = v19;
          v9 = (v9 + 1);
          if (number_low <= v9)
            return;
          v4 = *pRing;
        }
      }
      v20 = 0;
      while (1)
      {
        v21 = v4->pPhysics;
        v23 = v4->hTrackPoly->trackList;
        v24 = v21->m_Items[v9];
        v26 = v24->frame;
        v27 = v23->m_Items[v9];
        if (v26 == -16777215)
        {
          dds3SpPoly_Ring_Old_New(pRing, v9);
          v24->frame = 0;
          if (frame > -16777215)
            goto LABEL_50;
        }
        else
        {
          if ((v26 & 0x80000000) == 0)
          {
            v28 = v8 * (frame - v26);
            v29 = v28;
            if (v28 >= 0.0)
              LOBYTE(v29) = v28;
            v27->color = (v29 << 24) | 0x808080;
            dds3SpPoly_Ring_Old_Move(pRing, v9);
          }
          if (frame > v26)
          {
LABEL_50:
            ++v24->frame;
            v9 = (v9 + 1);
            if (number_low <= v9)
              return;
            goto LABEL_31;
          }
        }
        ++v20;
        v27->color = 8421504;
        if (number_low <= v20)
        {
          v27->color = 0;
          (*pRing)->basic->state = 0;
        }
        v9 = (v9 + 1);
        if (number_low <= v9)
          return;
LABEL_31:
        v4 = *pRing;
      }
    }
  }
}

// 0x1550900
dds3SpPoly_Basic_t *dds3SpPoly_Ring_Old_Create(void *hData, s32 bPos, bool pCopy, s32 billno) {
  u64 *v7;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v10;
  s64 *Interface;
  System_Byte_array *v12;
  char *v13;
  s64 *v14;
  dds3SpPoly_Ring_Old_t3_o *v15;
  struct dds3SpPoly_Ring_Old_Physics_t_array *v16;
  u32 split;
  s32 number;
  dds3TrackPoly_t_o **p_hTrackPoly;
  char *v25;
  s64 *v26;
  Il2CppObject *hDataa;
  dds3SpPoly_Ring_Old_t3_o *dst;
  u64 v29[2];
  char *v30;
  s32 bpos;

  bpos = bPos;
  hDataa = 0;
  v7 = Allocate(dds3SpPoly_Ring_Old_t3);
  dds3SpPoly_Ring_Old_t3___ctor(v7);
  dst = v7;
  if (pCopy)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SpPoly_Basic_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3SpPoly_Basic_t, v29);
      if ((v29[0] & 1) != 0)
        v25 = v30;
      else
        v25 = v29 + 1;
      v26 = sub_8C4940(v25);
    }
    dds3SpPoly_Ring_Old_t3__pClone(hData[12].monitor, &dst);
  }
  else
  {
    if (hData)
    {
      Interface = QueryInterface(hData, byte);
      if (!Interface)
      {
        sub_8FC2C0(hData->klass->_1.element_class, v10, v29);
        if ((v29[0] & 1) != 0)
          v13 = v30;
        else
          v13 = v29 + 1;
        v14 = sub_8C4940(v13);
      }
      v12 = Interface;
    }
    else
    {
      v12 = 0;
    }
    dds3SpPoly_Ring_Old_t3__pCopy(v7, v12, &bpos);
  }
  v15 = dst;
  dst->basic->pRing_Old = dst;
  v16 = NewSpecific(dds3SpPoly_Ring_Old_Physics_t, v15->basic->number);
  split = v15->split;
  v15->pPhysics = v16;
  if (split <= 2)
  {
    split = 3;
    v15->split = 3;
  }
  number = v15->basic->number;
  v15->hTrackPoly = dds3TrackPolyCreate(number, split, 1, 0);
  p_hTrackPoly = &v15->hTrackPoly;
  dds3TrackPolyVCSet(p_hTrackPoly, 0, *(p_hTrackPoly - 3), *(p_hTrackPoly - 2));
  hDataa = *(p_hTrackPoly - 5);
  dds3SpPoly_Ring_Old_BuffInit(&hDataa);
  return *(p_hTrackPoly - 5);
}

// 0x1550b70
void dds3SpPoly_Ring_Old_Delete(void **hData) {
  dds3SpPoly_Basic_t_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *monitor;
  dds3TrackPoly_t_o **v7;
  char *v8;
  s64 *v9;
  u64 v10[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SpPoly_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3SpPoly_Basic_t, v10);
    if ((v10[0] & 1) != 0)
      v8 = v10[2];
    else
      v8 = v10 + 1;
    v9 = sub_8C4940(v8);
  }
  monitor = (*hData)[12].monitor;
  v7 = (monitor + 56);
LABEL_9:
  pMeshDelete(v7, v3);
}

// 0x1550de0
void dds3SpPoly_Ring_Old_Draw(void **hData) {
  dds3SpPoly_Basic_t_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3TrackPoly_t_o **p_hTrackPoly;
  char *v9;
  s64 *v10;
  dds3SpPoly_Ring_Old_t3_o *monitor;
  u64 v12[3];

  monitor = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SpPoly_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3SpPoly_Basic_t, v12);
    if ((v12[0] & 1) != 0)
      v9 = v12[2];
    else
      v9 = v12 + 1;
    v10 = sub_8C4940(v9);
  }
  monitor = (*hData)[12].monitor;
  p_hTrackPoly = &monitor->hTrackPoly;
  dds3TrackPolyDrawOff(p_hTrackPoly, v3);
  dds3SpPoly_Ring_Old_Calc(&monitor);
  dds3TrackPolyDraw(p_hTrackPoly, "");
}

// 0x1550190
void dds3SpPoly_Ring_Old_Move(dds3SpPoly_Ring_Old_t3 **pRing, s32 number) {
  struct dds3TrackPoly_t_o *hTrackPoly;
  struct dds3TrackPolyList_t_array *trackList;
  s32 point;
  s32 v7;
  struct UnityEngine_Vector4_array *pVertex;
  s32 v9;
  UnityEngine_Vector4_o v16;

  *&v16.x = 0;
  *&v16.z = 0;
  hTrackPoly = (*pRing)->hTrackPoly;
  trackList = hTrackPoly->trackList;
  point = hTrackPoly->point;
  if (point >= 0)
    v7 = point;
  else
    v7 = point + 1;
  pVertex = trackList->m_Items[number]->pVertex;
  sub_854930(&v16, 2u);
  sub_854930(&v16, 1u);
  sub_854930(&v16, 0);
  SDF_VU0__LOADVECTOR_C(v16);
  if (point >= 2)
  {
    v9 = v7 >> 1;
    do
    {
      SDF_VU0__LOADVECTOR(pVertex->m_Items[1]);
      SDF_VU0__LOADVECTOR_B(pVertex->m_Items[0]);
      SDF_VU0__SUBVECTOR();
      SDF_VU0__NORMALIZE();
      SDF_VU0__COPYVECTOR_C_TO_B();
      SDF_VU0__MULVECTOR();
      SDF_VU0__COPYVECTOR_A_TO_B();
      SDF_VU0__LOADVECTOR(pVertex->m_Items[0]);
      SDF_VU0__ADDVECTOR();
      SDF_VU0__STOREVECTOR(pVertex->m_Items);
      SDF_VU0__LOADVECTOR(pVertex->m_Items[1]);
      SDF_VU0__ADDVECTOR();
      SDF_VU0__STOREVECTOR(&pVertex->m_Items[1]);
      --v9;
    }
    while (v9);
  }
}

// 0x154fe40
void dds3SpPoly_Ring_Old_New(dds3SpPoly_Ring_Old_t3 **pRing, s32 number) {
  u32 v3;
  struct dds3TrackPoly_t_o *hTrackPoly;
  struct dds3TrackPolyList_t_array *trackList;
  dds3TrackPolyList_t_o *v9;
  s32 v10;
  struct UnityEngine_Vector4_array *pVertex;
  s32 v13;
  f32 v14;
  u64 v15;
  UnityEngine_Vector4_o *m_Items;
  u64 v17;
  u32 v20;
  struct UnityEngine_Vector4_array *v21;
  struct UnityEngine_Vector4_array *v24;
  s64 v26;
  UnityEngine_Matrix4x4_o v28;
  UnityEngine_Vector4_o v29;
  UnityEngine_Vector4_o dst;

  *&dst.x = 0;
  *&dst.z = 0;
  *&v29.x = 0;
  *&v29.z = 0;
  hTrackPoly = (*pRing)->hTrackPoly;
  trackList = hTrackPoly->trackList;
  v9 = trackList->m_Items[number];
  v9->count = hTrackPoly->point;
  v10 = hTrackPoly->point / 2;
  LOWORD(v3) = (*pRing)->split;
  pVertex = v9->pVertex;
  memmove(&v28, &(*pRing)->basic->rot, 0x40u);
  SDF_VU0__LOADMATRIX(&v28);
  SDF_VU0__COPYVECTOR(&dst, (*pRing)->basic->pos, 0);
  v13 = v10 - 1;
  if (v13 < 1)
  {
    v20 = 0;
    v21 = v9->pVertex;
    if (!LODWORD(v21->max_length))
      goto LABEL_16;
  }
  else
  {
    v14 = 0.0;
    v15 = 0;
    m_Items = pVertex->m_Items;
    do
    {
      v17 = v15;
      sdfCos(v14);
      sdfSin(v14);
      SDF_VU0__LOADVECTOR_B(dst);
      SDF_VU0__STOREVECTOR_B(m_Items);
      sub_854930(&v29, 0);
      sub_854930(&v29, 1u);
      sub_854930(&v29, 2u);
      SDF_VU0__LOADVECTOR(v29);
      SDF_VU0__APPLYMATRIX();
      SDF_VU0__ADDVECTOR();
      SDF_VU0__STOREVECTOR(m_Items + 1);
      v14 = (6.2832 / v3) + v14;
      m_Items += 2;
      --v13;
      v15 = v17 + 2;
    }
    while (v13);
    v20 = v17 + 2;
    v21 = v9->pVertex;
    if (!LODWORD(v21->max_length))
    {
LABEL_16:
    }
  }
  SDF_VU0__COPYVECTOR(&pVertex->m_Items[v20], v21->m_Items[0]);
  v24 = v9->pVertex;
  v26 = v20 | 1;
  SDF_VU0__COPYVECTOR(&pVertex->m_Items[v26], v24->m_Items[1]);
}

// 0x1550ce0
void dds3SpPoly_Ring_Old_SetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  f32 *monitor;
  f32 v8;
  char *v9;
  s64 *v10;
  u64 v11[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SpPoly_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3SpPoly_Basic_t, v11);
    if ((v11[0] & 1) != 0)
      v9 = v11[2];
    else
      v9 = v11 + 1;
    v10 = sub_8C4940(v9);
  }
  monitor = (*hData)[12].monitor;
  v8 = monitor[10] * scale;
  monitor[9] = monitor[9] * scale;
  monitor[10] = v8;
}

// 0x1553f20
void dds3SpPoly_RollRingAllBuffInit(void **hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v5;
  s64 v6;
  s32 namespaze;
  s64 v8;
  s32 v9;
  s64 v10;
  u32 *v12;
  u64 *v13;
  Il2CppClass *v15;
  Il2CppClass *parent;
  u64 v19;
  u32 data_high;
  char *v21;
  s64 *v22;
  u64 v23[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SpPoly_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3SpPoly_Basic_t, v23);
    if ((v23[0] & 1) != 0)
      v21 = v23[2];
    else
      v21 = v23 + 1;
    v22 = sub_8C4940(v21);
  }
  v5 = (*hData)[14].klass;
  v6 = *(v5->_1.name + 8);
  if (v6)
  {
    namespaze = v5->_1.namespaze;
    v8 = -v6;
    v9 = -16777215;
    v10 = 4;
    do
    {
      while (1)
      {
        parent = v5->_1.parent;
        v19 = v10 - 4;
        if (*(&parent->_1.image + v10))
        {
          v15 = v5->_1.parent;
          if (v19 >= LODWORD(v15->_1.namespaze))
            goto LABEL_13;
        }
        else
        {
          v12 = v5->_1.parent;
          v13 = Allocate(dds3SpPoly_RollRingPhysics_t);
          dds3SpPoly_RollRingPhysics_t___ctor(v13);
          *&v12[2 * v10] = v13;
          v15 = v5->_1.parent;
          if (v19 >= LODWORD(v15->_1.namespaze))
          {
LABEL_13:
          }
        }
        *(*(&v15->_1.image + v10) + 16LL) = v9;
        data_high = HIDWORD(v5->_1.this_arg.data);
        if (data_high)
        {
          if ((v10 - 3) % data_high)
            break;
        }
        v9 -= namespaze;
        ++v10;
        if (v8 + v10 == 4)
          return;
      }
      ++v10;
    }
    while (v8 + v10 != 4);
  }
}

// 0x1554180
void dds3SpPoly_RollRingBuffInit(dds3SpPoly_RollRing_t3 **pRollRing, s32 number) {
  struct dds3SpPoly_RollRingPhysics_t_array *pPhysics;
  s64 v6;
  dds3SpPoly_RollRingPhysics_t_o *v8;
  f32 radius_s_r;
  f32 radius_s;
  f32 radius_e;
  s64 simu_num;
  f32 v13;
  f32 v14;

  pPhysics = (*pRollRing)->pPhysics;
  v6 = number;
  v8 = pPhysics->m_Items[number];
  v8->frame = 0;
  radius_s_r = (*pRollRing)->radius_s_r;
  radius_s = (*pRollRing)->radius_s;
  v8->radius = radius_s * DDS3EFFECT_RAND_FA(radius_s_r);
  radius_e = (*pRollRing)->radius_e;
  v8->spread_s = ((radius_e * DDS3EFFECT_RAND_FA((*pRollRing)->radius_e_r, 0))
                       - v8->radius)
                      / (*pRollRing)->basic->frame;
  v8->rot_x = (*pRollRing)->incline * 0.017453;
  simu_num = (*pRollRing)->simu_num;
  if (simu_num)
  {
    v13 = simu_num;
    v14 = (6.2832 / v13) * (v6 % simu_num);
  }
  else
  {
    v14 = 0.0;
  }
  v8->rot_y = v14;
}

// 0x1554790
dds3SpPoly_Basic_t *dds3SpPoly_RollRingCreate(void *hData, s32 bPos, bool pCopy, s32 billno) {
  u64 *v7;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v10;
  s64 *Interface;
  System_Byte_array *v12;
  char *v13;
  s64 *v14;
  dds3SpPoly_RollRing_t3_o *v15;
  struct dds3SpPoly_RollRingPhysics_t_array *v16;
  u32 vertex;
  s32 number;
  dds3TrackPoly_t_o **p_hTrackPoly;
  char *v25;
  s64 *v26;
  UnityEngine_Matrix4x4_o dest;
  Il2CppObject *hDataa;
  dds3SpPoly_RollRing_t3_o *dst;
  u64 v30[2];
  char *v31;
  s32 bpos;

  bpos = bPos;
  hDataa = 0;
  v7 = Allocate(dds3SpPoly_RollRing_t3);
  dds3SpPoly_RollRing_t3___ctor(v7);
  dst = v7;
  if (pCopy)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SpPoly_Basic_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3SpPoly_Basic_t, v30);
      if ((v30[0] & 1) != 0)
        v25 = v31;
      else
        v25 = v30 + 1;
      v26 = sub_8C4940(v25);
    }
    dds3SpPoly_RollRing_t3__pClone(hData[14].klass, &dst);
  }
  else
  {
    if (hData)
    {
      Interface = QueryInterface(hData, byte);
      if (!Interface)
      {
        sub_8FC2C0(hData->klass->_1.element_class, v10, v30);
        if ((v30[0] & 1) != 0)
          v13 = v31;
        else
          v13 = v30 + 1;
        v14 = sub_8C4940(v13);
      }
      v12 = Interface;
    }
    else
    {
      v12 = 0;
    }
    dds3SpPoly_RollRing_t3__pCopy(v7, v12, &bpos);
  }
  v15 = dst;
  dst->basic->pRollRing = dst;
  v16 = NewSpecific(dds3SpPoly_RollRingPhysics_t, v15->basic->number);
  vertex = v15->vertex;
  v15->pPhysics = v16;
  if (vertex <= 2)
  {
    vertex = 3;
    v15->vertex = 3;
  }
  number = v15->basic->number;
  v15->hTrackPoly = dds3TrackPolyCreate(number, vertex, 1, 0);
  p_hTrackPoly = &v15->hTrackPoly;
  dds3TrackPolyVCSet(p_hTrackPoly, 0, *(p_hTrackPoly - 2), *(p_hTrackPoly - 4));
  hDataa = *(p_hTrackPoly - 8);
  dds3SpPoly_RollRingAllBuffInit(&hDataa);
  memmove(&dest, &(*(p_hTrackPoly - 8))->pVertex, 0x40u);
  SDF_VU0__LOADMATRIX(&dest);
  SDF_VU0__STOREMATRIX(&(*(p_hTrackPoly - 8))[1].point, 0);
  (*p_hTrackPoly)->mode = HIWORD((*(p_hTrackPoly - 8))[1].monitor);
  return *(p_hTrackPoly - 8);
}

// 0x1554a40
void dds3SpPoly_RollRingDelete(void **hData) {
  dds3SpPoly_Basic_t_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v6;
  dds3TrackPoly_t_o **p_declaringType;
  char *v8;
  s64 *v9;
  u64 v10[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SpPoly_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3SpPoly_Basic_t, v10);
    if ((v10[0] & 1) != 0)
      v8 = v10[2];
    else
      v8 = v10 + 1;
    v9 = sub_8C4940(v8);
  }
  v6 = (*hData)[14].klass;
  p_declaringType = &v6->_1.declaringType;
LABEL_9:
  pMeshDelete(p_declaringType, v3);
}

// 0x1554cb0
void dds3SpPoly_RollRingDraw(void **hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3SpPoly_RollRing_t3_o *v8;
  struct dds3SpPoly_Basic_t_o *basic;
  s32 frame;
  u32 abgr;
  u64 v12;
  s64 v13;
  s32 v14;
  u32 v15;
  u32 v16;
  struct dds3SpPoly_RollRingPhysics_t_array *pPhysics;
  dds3SpPoly_RollRingPhysics_t_o *v19;
  struct dds3TrackPolyList_t_array *trackList;
  Il2CppClass **v22;
  signed s32 v23;
  Il2CppClass *v24;
  struct dds3SpPoly_Basic_t_o *v25;
  s64 alpha_s;
  u32 v27;
  u32 v28;
  u32 alpha_e;
  char *v30;
  s64 *v31;
  s64 number;
  s32 v33;
  s32 loop;
  dds3SpPoly_RollRing_t3_o *pRollRing;
  u64 v36[3];

  pRollRing = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SpPoly_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3SpPoly_Basic_t, v36);
    if ((v36[0] & 1) != 0)
      v30 = v36[2];
    else
      v30 = v36 + 1;
    v31 = sub_8C4940(v30);
  }
  v8 = (*hData)[14].klass;
  pRollRing = v8;
  basic = v8->basic;
  number = basic->number;
  if (basic->number >= 1)
  {
    frame = basic->frame;
    abgr = basic->abgr;
    v33 = 0;
    loop = basic->loop;
    v12 = 0;
    v13 = basic->number;
    while (1)
    {
      while (1)
      {
        pPhysics = v8->pPhysics;
        v19 = pPhysics->m_Items[v12];
        trackList = v8->hTrackPoly->trackList;
        v22 = &trackList->obj.klass + v12;
        v23 = v19->frame;
        v24 = v22[4];
        if (v23 == -16777215)
        {
          dds3SpPoly_RollRingBuffInit(&pRollRing, v12);
          v23 = v19->frame;
        }
        if ((v23 & 0x80000000) == 0)
          break;
LABEL_42:
        v14 = v23 + 1;
        if (v23 + 1 < frame)
          goto LABEL_43;
LABEL_8:
        if (loop)
        {
          v14 = -16777215;
        }
        else if (++v33 >= number)
        {
          v8->basic->state = 0;
        }
        LODWORD(v24->_1.byval_arg.data) = 0;
        ++v12;
        v19->frame = v14;
        if (v13 == v12)
          goto LABEL_44;
      }
      v25 = v8->basic;
      alpha_s = v25->alpha_s;
      if (v23 < alpha_s)
        break;
      v28 = abgr;
      if (frame >= v23)
      {
        alpha_e = v25->alpha_e;
        v28 = abgr;
        if (frame - alpha_e <= v23)
        {
          v15 = frame - v23;
          v16 = alpha_e;
LABEL_33:
          v27 = dds3SpPoly_Color(v15, v16, abgr);
          v24->_1.byval_arg.bits = v27;
          if (HIBYTE(v27))
            goto LABEL_38;
          goto LABEL_7;
        }
      }
      v24->_1.byval_arg.bits = v28;
      if (HIBYTE(v28))
      {
LABEL_38:
        dds3SpPoly_RollRingMove(&pRollRing, v12);
        goto LABEL_42;
      }
LABEL_7:
      LODWORD(v24->_1.byval_arg.data) = 0;
      v14 = v23 + 1;
      if (v23 + 1 >= frame)
        goto LABEL_8;
LABEL_43:
      ++v12;
      v19->frame = v14;
      if (v13 == v12)
        goto LABEL_44;
    }
    v15 = v23;
    v16 = alpha_s;
    goto LABEL_33;
  }
LABEL_44:
  dds3TrackPolyDraw(&v8->hTrackPoly, "");
}

// 0x15542e0
void dds3SpPoly_RollRingMove(dds3SpPoly_RollRing_t3 **pRollRing, s32 number) {
  u64 v3;
  struct dds3SpPoly_RollRingPhysics_t_array *pPhysics;
  Il2CppClass **v8;
  struct dds3TrackPoly_t_o *hTrackPoly;
  f32 *v10;
  struct dds3TrackPolyList_t_array *trackList;
  dds3TrackPolyList_t_o *v13;
  s32 v14;
  struct UnityEngine_Vector4_array *pVertex;
  f32 v16;
  s32 v18;
  UnityEngine_Vector4_o *v19;
  f32 v20;
  f32 v21;
  f32 v22;
  u64 v23;
  struct UnityEngine_Vector4_array *v26;
  f32 *v28;
  f32 v30;
  f32 v31;
  f32 v32;
  f32 v33;
  s64 v34;
  UnityEngine_Matrix4x4_o v37;
  UnityEngine_Vector4_o v38;
  UnityEngine_Vector4_o v39;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v41;

  *&p.x = 0;
  *&p.z = 0;
  *&v39.x = 0;
  *&v39.z = 0;
  *&v38.x = 0;
  *&v38.z = 0;
  pPhysics = (*pRollRing)->pPhysics;
  v8 = &pPhysics->obj.klass + number;
  hTrackPoly = (*pRollRing)->hTrackPoly;
  v10 = v8[4];
  trackList = hTrackPoly->trackList;
  v13 = trackList->m_Items[number];
  v13->count = hTrackPoly->point;
  v14 = hTrackPoly->point >> 1;
  pVertex = v13->pVertex;
  v16 = v10[7];
  SetRotateMatrixX(v16);
  SetRotateMatrixY_B(v10[8]);
  MultMatrixRevNoArg();
  v10[8] = v10[8] + ((*pRollRing)->roll_s * 0.017453);
  v10[5] = v10[5] + v10[6];
  LODWORD(v3) = (*pRollRing)->vertex;
  memmove(&v37, &(*pRollRing)->basic->rot, 0x40u);
  SDF_VU0__LOADMATRIX_B(&v37);
  MultMatrixRevNoArg();
  sub_854930(&v39, 0);
  sub_854710(&v39, 0);
  sub_854930(&v39, 1u);
  sub_854930(&v39, 2u);
  sub_854710(&v39, 0);
  sub_854930(&v38, 0);
  sub_854710(&v38, 0);
  sub_854930(&v38, 1u);
  sub_854930(&v38, 2u);
  SDF_VU0__LOADVECTOR_C((*pRollRing)->basic->pos, 0);
  v18 = v14 - 1;
  if (v14 - 1 < 1)
  {
    LODWORD(v23) = 0;
    v26 = v13->pVertex;
    if (LODWORD(v26->max_length))
      goto LABEL_21;
LABEL_29:
  }
  v19 = &pVertex->m_Items[1];
  v20 = v3;
  v21 = 6.2832 / v20;
  v22 = 0.0;
  v23 = 0;
  do
  {
    sdfCos(v22);
    sub_854930(&p, 0);
    sub_854930(&p, 1u);
    sdfSin(v22);
    sub_854930(&p, 2u);
    SDF_VU0__LOADVECTOR(p);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(&p);
    SDF_VU0__LOADVECTOR_B(v39);
    SDF_VU0__MULVECTOR();
    SDF_VU0__ADDVECTOR_A_C();
    SDF_VU0__STOREVECTOR(v19);
    SDF_VU0__LOADVECTOR(p);
    SDF_VU0__LOADVECTOR_B(v38);
    SDF_VU0__MULVECTOR();
    SDF_VU0__ADDVECTOR_A_C();
    SDF_VU0__STOREVECTOR(v19 - 1);
    v22 = v21 + v22;
    v23 += 2LL;
    v19 += 2;
    --v18;
  }
  while (v18);
  v26 = v13->pVertex;
  if (!LODWORD(v26->max_length))
    goto LABEL_29;
LABEL_21:
  SDF_VU0__COPYVECTOR(&pVertex->m_Items[v23], v26->m_Items[0]);
  v28 = v13->pVertex;
  v30 = v28[12];
  v31 = v28[13];
  v32 = v28[14];
  v33 = v28[15];
  v34 = v23 | 1;
  v41.x = v30;
  v41.y = v31;
  v41.z = v32;
  v41.w = v33;
  SDF_VU0__COPYVECTOR(&pVertex->m_Items[v34], v41);
}

// 0x1554ff0
void dds3SpPoly_RollRingSetEndless(dds3SpPoly_RollRing_t3 **pRollRing) {
  struct dds3SpPoly_Basic_t_o *basic;
  s64 number;
  u64 i;
  struct dds3SpPoly_RollRingPhysics_t_array *pPhysics;
  dds3SpPoly_RollRingPhysics_t_o *v7;

  basic = (*pRollRing)->basic;
  basic->frame = 0xFFFFFFF;
  number = basic->number;
  (*pRollRing)->basic->alpha_s = 0;
  (*pRollRing)->basic->alpha_e = 0;
  if (number)
  {
    for (i = 0; i != number; ++i)
    {
      pPhysics = (*pRollRing)->pPhysics;
      v7 = pPhysics->m_Items[i];
      if (v7->frame != -16777215)
        v7->frame = 268435440;
    }
  }
}

// 0x1554bb0
void dds3SpPoly_RollRingSetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v7;
  u32 v8;
  char *v9;
  s64 *v10;
  u64 v11[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SpPoly_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3SpPoly_Basic_t, v11);
    if ((v11[0] & 1) != 0)
      v9 = v11[2];
    else
      v9 = v11 + 1;
    v10 = sub_8C4940(v9);
  }
  v7 = (*hData)[14].klass;
  *&v8 = *&v7->_1.byval_arg.bits * scale;
  *(&v7->_1.byval_arg.data + 1) = *(&v7->_1.byval_arg.data + 1) * scale;
  v7->_1.byval_arg.bits = v8;
}

// 0x1552f60
void dds3SpPoly_SphereRingAllBuffInit(void **hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  void *monitor;
  s64 v6;
  s32 v7;
  u64 v8;
  s32 v9;
  u32 *v11;
  u64 *v12;
  s64 v14;
  s64 v16;
  char *v17;
  s64 *v18;
  u64 v19[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SpPoly_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3SpPoly_Basic_t, v19);
    if ((v19[0] & 1) != 0)
      v17 = v19[2];
    else
      v17 = v19 + 1;
    v18 = sub_8C4940(v17);
  }
  monitor = (*hData)[13].monitor;
  v6 = *(*(monitor + 2) + 32LL);
  if (v6)
  {
    v7 = *(monitor + 6);
    v8 = 0;
    v9 = -16777215;
    do
    {
      v11 = *(monitor + 8);
      v12 = Allocate(dds3SpPoly_SphereRingPhysics_t);
      dds3SpPoly_SphereRingPhysics_t___ctor(v12);
      *&v11[2 * v8 + 8] = v12;
      v14 = *(monitor + 8);
      v16 = v14 + 8 * v8++;
      *(*(v16 + 32) + 16LL) = v9;
      v9 -= v7;
    }
    while (v6 != v8);
  }
}

// 0x1553130
void dds3SpPoly_SphereRingBuffInit(dds3SpPoly_SphereRing_t3 **pSphereRing, s32 number) {
  struct dds3SpPoly_SphereRingPhysics_t_array *pPhysics;
  dds3SpPoly_SphereRingPhysics_t_o *v7;
  f32 radius_r;
  f32 radius;
  f32 v10;
  s32 v11;

  pPhysics = (*pSphereRing)->pPhysics;
  v7 = pPhysics->m_Items[number];
  v7->frame = 0;
  radius = (*pSphereRing)->radius;
  radius_r = (*pSphereRing)->radius_r;
  v10 = radius * DDS3EFFECT_RAND_FA(radius_r);
  v11 = v10;
  if (v10 >= 0.0)
    v11 = v10;
  v7->radius = v11;
}

// 0x15536d0
dds3SpPoly_Basic_t *dds3SpPoly_SphereRingCreate(void *hData, s32 bPos, bool pCopy, s32 billno) {
  u64 *v7;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v10;
  s64 *Interface;
  System_Byte_array *v12;
  char *v13;
  s64 *v14;
  dds3SpPoly_SphereRing_t3_o *v15;
  struct dds3SpPoly_SphereRingPhysics_t_array *v16;
  u32 vertex;
  s32 number;
  dds3TrackPoly_t_o **p_hTrackPoly;
  char *v25;
  s64 *v26;
  UnityEngine_Matrix4x4_o dest;
  Il2CppObject *hDataa;
  dds3SpPoly_SphereRing_t3_o *dst;
  u64 v30[2];
  char *v31;
  s32 bpos;

  bpos = bPos;
  hDataa = 0;
  v7 = Allocate(dds3SpPoly_SphereRing_t3);
  dds3SpPoly_SphereRing_t3___ctor(v7);
  dst = v7;
  if (pCopy)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SpPoly_Basic_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3SpPoly_Basic_t, v30);
      if ((v30[0] & 1) != 0)
        v25 = v31;
      else
        v25 = v30 + 1;
      v26 = sub_8C4940(v25);
    }
    dds3SpPoly_SphereRing_t3__pClone(hData[13].monitor, &dst);
  }
  else
  {
    if (hData)
    {
      Interface = QueryInterface(hData, byte);
      if (!Interface)
      {
        sub_8FC2C0(hData->klass->_1.element_class, v10, v30);
        if ((v30[0] & 1) != 0)
          v13 = v31;
        else
          v13 = v30 + 1;
        v14 = sub_8C4940(v13);
      }
      v12 = Interface;
    }
    else
    {
      v12 = 0;
    }
    dds3SpPoly_SphereRing_t3__pCopy(v7, v12, &bpos);
  }
  v15 = dst;
  dst->basic->pSphereRing = dst;
  v16 = NewSpecific(dds3SpPoly_SphereRingPhysics_t, v15->basic->number);
  vertex = v15->vertex;
  v15->pPhysics = v16;
  if (vertex <= 2)
  {
    vertex = 3;
    v15->vertex = 3;
  }
  number = v15->basic->number;
  v15->hTrackPoly = dds3TrackPolyCreate(number, vertex, 1, 0);
  p_hTrackPoly = &v15->hTrackPoly;
  dds3TrackPolyVCSet(p_hTrackPoly, 0, *(p_hTrackPoly - 1), *(p_hTrackPoly - 3));
  hDataa = *(p_hTrackPoly - 5);
  dds3SpPoly_SphereRingAllBuffInit(&hDataa);
  memmove(&dest, &(*(p_hTrackPoly - 5))->pVertex, 0x40u);
  SDF_VU0__LOADMATRIX(&dest);
  SDF_VU0__STOREMATRIX(&(*(p_hTrackPoly - 5))[1].point, 0);
  (*p_hTrackPoly)->mode = HIWORD((*(p_hTrackPoly - 5))[1].monitor);
  return *(p_hTrackPoly - 5);
}

// 0x1553980
void dds3SpPoly_SphereRingDelete(void **hData) {
  dds3SpPoly_Basic_t_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *monitor;
  dds3TrackPoly_t_o **v7;
  char *v8;
  s64 *v9;
  u64 v10[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SpPoly_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3SpPoly_Basic_t, v10);
    if ((v10[0] & 1) != 0)
      v8 = v10[2];
    else
      v8 = v10 + 1;
    v9 = sub_8C4940(v8);
  }
  monitor = (*hData)[13].monitor;
  v7 = (monitor + 56);
LABEL_9:
  pMeshDelete(v7, v3);
}

// 0x1553bf0
void dds3SpPoly_SphereRingDraw(void **hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3SpPoly_SphereRing_t3_o *monitor;
  struct dds3SpPoly_Basic_t_o *basic;
  s32 frame;
  u64 v11;
  s64 v12;
  s64 v13;
  s32 v14;
  u32 v15;
  u32 v16;
  struct dds3SpPoly_SphereRingPhysics_t_array *pPhysics;
  dds3SpPoly_SphereRingPhysics_t_o *v19;
  struct dds3TrackPolyList_t_array *trackList;
  Il2CppClass **v22;
  signed s32 v23;
  Il2CppClass *v24;
  struct dds3SpPoly_Basic_t_o *v25;
  s64 alpha_s;
  u32 v27;
  u32 alpha_e;
  char *v29;
  s64 *v30;
  s64 number;
  u32 abgr;
  s32 loop;
  dds3SpPoly_SphereRing_t3_o *pSphereRing;
  u64 v35[3];

  pSphereRing = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SpPoly_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3SpPoly_Basic_t, v35);
    if ((v35[0] & 1) != 0)
      v29 = v35[2];
    else
      v29 = v35 + 1;
    v30 = sub_8C4940(v29);
  }
  monitor = (*hData)[13].monitor;
  pSphereRing = monitor;
  basic = monitor->basic;
  number = basic->number;
  if (basic->number >= 1)
  {
    frame = basic->frame;
    abgr = basic->abgr;
    loop = basic->loop;
    v11 = 0;
    LODWORD(v12) = 0;
    v13 = basic->number;
    while (1)
    {
      while (1)
      {
        pPhysics = monitor->pPhysics;
        v19 = pPhysics->m_Items[v11];
        trackList = monitor->hTrackPoly->trackList;
        v22 = &trackList->obj.klass + v11;
        v23 = v19->frame;
        v24 = v22[4];
        if (v23 == -16777215)
        {
          dds3SpPoly_SphereRingBuffInit(&pSphereRing, v11);
          v23 = v19->frame;
        }
        if ((v23 & 0x80000000) == 0)
          break;
LABEL_42:
        v14 = v23 + 1;
        if (v23 + 1 < frame)
          goto LABEL_43;
LABEL_8:
        if (loop)
        {
          v14 = -16777215;
        }
        else
        {
          v12 = (v12 + 1);
          if (v12 >= number)
            monitor->basic->state = 0;
        }
        LODWORD(v24->_1.byval_arg.data) = 0;
        ++v11;
        v19->frame = v14;
        if (v13 == v11)
          goto LABEL_44;
      }
      v25 = monitor->basic;
      alpha_s = v25->alpha_s;
      if (v23 < alpha_s)
        break;
      if (frame >= v23)
      {
        alpha_e = v25->alpha_e;
        if (frame - alpha_e <= v23)
        {
          v15 = frame - v23;
          v16 = alpha_e;
LABEL_33:
          v27 = dds3SpPoly_Color(v15, v16, abgr);
          v24->_1.byval_arg.bits = v27;
          if (HIBYTE(v27))
            goto LABEL_38;
          goto LABEL_7;
        }
      }
      if (HIBYTE(v24->_1.byval_arg.bits))
      {
LABEL_38:
        dds3SpPoly_SphereRingMove(&pSphereRing, v11);
        goto LABEL_42;
      }
LABEL_7:
      LODWORD(v24->_1.byval_arg.data) = 0;
      v14 = v23 + 1;
      if (v23 + 1 >= frame)
        goto LABEL_8;
LABEL_43:
      ++v11;
      v19->frame = v14;
      if (v13 == v11)
        goto LABEL_44;
    }
    v15 = v23;
    v16 = alpha_s;
    goto LABEL_33;
  }
LABEL_44:
  dds3TrackPolyDraw(&monitor->hTrackPoly, "");
}

// 0x1553210
void dds3SpPoly_SphereRingMove(dds3SpPoly_SphereRing_t3 **pSphereRing, s32 number) {
  u64 v3;
  struct dds3SpPoly_SphereRingPhysics_t_array *pPhysics;
  struct dds3TrackPoly_t_o *hTrackPoly;
  struct dds3TrackPolyList_t_array *trackList;
  dds3SpPoly_SphereRingPhysics_t_o *v10;
  dds3TrackPolyList_t_o *v12;
  f32 v13;
  struct UnityEngine_Vector4_array *pVertex;
  s32 v15;
  f32 v16;
  s32 v18;
  f32 v19;
  f32 v20;
  f32 v21;
  u64 v22;
  UnityEngine_Vector4_o *v23;
  struct UnityEngine_Vector4_array *v26;
  f32 *v28;
  f32 v30;
  f32 v31;
  f32 v32;
  f32 v33;
  s64 v34;
  UnityEngine_Matrix4x4_o v37;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v39;
  UnityEngine_Vector4_o v40;

  *&v39.x = 0;
  *&v39.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  pPhysics = (*pSphereRing)->pPhysics;
  hTrackPoly = (*pSphereRing)->hTrackPoly;
  trackList = hTrackPoly->trackList;
  v10 = pPhysics->m_Items[number];
  v12 = trackList->m_Items[number];
  v12->count = hTrackPoly->point;
  v13 = v10->frame / (*pSphereRing)->basic->frame;
  pVertex = v12->pVertex;
  v15 = hTrackPoly->point >> 1;
  v16 = v13 * 3.1416;
  sdfSin(v16);
  sdfCos(v16);
  LODWORD(v3) = (*pSphereRing)->vertex;
  memmove(&v37, &(*pSphereRing)->basic->rot, 0x40u);
  SDF_VU0__LOADMATRIX(&v37);
  SDF_VU0__LOADVECTOR_C((*pSphereRing)->basic->pos, 0);
  v18 = v15 - 1;
  if (v15 - 1 < 1)
  {
    LODWORD(v22) = 0;
    v26 = v12->pVertex;
    if (LODWORD(v26->max_length))
      goto LABEL_21;
LABEL_29:
  }
  v19 = 0.0;
  v20 = v3;
  v21 = 6.2832 / v20;
  v22 = 0;
  v23 = &pVertex->m_Items[1];
  do
  {
    sdfCos(v19);
    sub_854930(&p, 0);
    sub_854930(&v39, 0);
    sdfSin(v19);
    sub_854930(&p, 2u);
    sub_854930(&v39, 2u);
    sub_854710(&p, 0);
    sub_854930(&p, 0);
    sub_854930(&p, 1u);
    sub_854710(&p, 2u);
    sub_854930(&p, 2u);
    SDF_VU0__LOADVECTOR(p);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(&p);
    sub_854710(&v39, 0);
    sub_854930(&v39, 0);
    sub_854930(&v39, 1u);
    sub_854710(&v39, 2u);
    sub_854930(&v39, 2u);
    SDF_VU0__LOADVECTOR(v39);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__ADDVECTOR_A_C();
    SDF_VU0__STOREVECTOR(v23);
    SDF_VU0__LOADVECTOR(p);
    SDF_VU0__ADDVECTOR_A_C();
    SDF_VU0__STOREVECTOR(v23 - 1);
    v19 = v21 + v19;
    v22 += 2LL;
    v23 += 2;
    --v18;
  }
  while (v18);
  v26 = v12->pVertex;
  if (!LODWORD(v26->max_length))
    goto LABEL_29;
LABEL_21:
  SDF_VU0__COPYVECTOR(&pVertex->m_Items[v22], v26->m_Items[0]);
  v28 = v12->pVertex;
  v30 = v28[12];
  v31 = v28[13];
  v32 = v28[14];
  v33 = v28[15];
  v34 = v22 | 1;
  v40.x = v30;
  v40.y = v31;
  v40.z = v32;
  v40.w = v33;
  SDF_VU0__COPYVECTOR(&pVertex->m_Items[v34], v40);
}

// 0x1553af0
void dds3SpPoly_SphereRingSetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SpPoly_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3SpPoly_Basic_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *((*hData)[13].monitor + 9) = *((*hData)[13].monitor + 9) * scale;
}

// 0x154c4a0
void dds3TrackPolyColorSet(dds3TrackPoly_t **hTrackPoly, s32 number, u32 color) {
  struct dds3TrackPolyList_t_array *trackList;

  trackList = (*hTrackPoly)->trackList;
  trackList->m_Items[number]->color = color;
}

// 0x154b3f0
dds3TrackPoly_t *dds3TrackPolyCreate(s32 number, s32 face, s32 rec, s32 type) {
  s32 v9;
  s32 v10;
  s32 v11;
  u32 v12;
  u64 v13;
  u64 *v14;
  u32 *v15;
  u32 *v17;
  u64 v18;
  s64 v19;
  u64 *v20;
  u64 v22;
  s64 v24;
  u64 v25;
  s64 v27;
  sdfMat_t_o *v31;
  s16 v35;
  s32 v36;
  u32 v37;
  dds3TrackPoly_t_o *hTrackPoly;

  hTrackPoly = 0;
  v35 = type;
  switch (type)
  {
    case 2:
      v9 = 6 * face + 6;
      break;
    case 3:
      v9 = 4 * face + 4;
      break;
    case 4:
      v9 = 5 * face + 5;
      break;
    default:
      v10 = 2 * face;
      if (rec)
      {
        if (v10 % rec)
          v10 = v10 / rec + 2;
        else
          v10 /= rec;
      }
      v11 = v10 + 2;
      v12 = v11 & 0xFFFFFFFE;
      v9 = (v11 & 0xFFFFFFFE) + (v11 >> 1);
      if (type != 1)
        v9 = v12;
      break;
  }
  v37 = v9;
  v13 = (v9 * number);
  v14 = Allocate(dds3TrackPoly_t);
  dds3TrackPoly_t___ctor(v14);
  hTrackPoly = v14;
  v14[6] = NewSpecific(UnityEngine_Vector4, v13);
  v14[7] = NewSpecific(uint, v13);
  v15 = NewSpecific(dds3TrackPolyList_t, number);
  v14[5] = v15;
  v36 = number;
  if (number >= 1)
  {
    v17 = v15;
    v18 = 0;
    v19 = number - 1LL;
    while (1)
    {
      v20 = Allocate(dds3TrackPolyList_t);
      dds3TrackPolyList_t___ctor(v20);
      *&v17[2 * v18 + 8] = v20;
      v22 = v14[5];
      v24 = *(v22 + 8 * v18 + 32);
      *(v24 + 16) = NewSpecific(UnityEngine_Vector4, v37);
      v25 = v14[5];
      v27 = *(v25 + 8 * v18 + 32);
      *(v27 + 24) = NewSpecific(uint, v37);
      dds3TrackPolyListInit(&hTrackPoly, v18);
      if (v19 == v18)
        break;
      v17 = v14[5];
      ++v18;
    }
  }
  v31 = sdfMatNew();
  v14[8] = v31;
  sdfMatSetConstant(v31, 1.0);
  *(v14 + 9) = 2;
  *(v14 + 5) = v36;
  *(v14 + 6) = v37;
  *(v14 + 8) = v35;
  v14[4] = 0;
  *(v14 + 7) = rec;
  v14[9] = 0;
  v14[10] = 0;
  if (evtBitCheck(3713))
  {
    *(v14 + 24) = 1077936128;
    return v14;
  }
LABEL_41:
  *(v14 + 24) = LODWORD(tp_alf_raito);
  tp_alf_raito = 0.0;
  return v14;
}

// 0x154b9a0
void dds3TrackPolyDelete(dds3TrackPoly_t **hTrackPoly) {
  dds3TrackPoly_t_o **v3;

  else
  {
    v3 = hTrackPoly;
  }
  pMeshDelete(v3);
}

// 0x1550f10
void dds3TrackPolyDraw(dds3TrackPoly_t **hTrackPoly, char *funcname) {
  dds3TrackPoly_t_o *v6;
  struct XRD773Unity_CommonMesh_array *pMesh;
  XRD773Unity_GraphicManager_o *Instance;
  s64 *Mesh;
  s64 *v11;
  struct XRD773Unity_CommonMesh_array *v13;
  UnityEngine_Object_o *gameObject;
  System_Object_array *v16;
  s64 *name;
  s64 *v18;
  s64 *v22;
  s64 *v23;
  System_String_o *v30;
  struct XRD773Unity_CommonMesh_array *v31;
  u64 v33;
  u32 v34;
  s32 v35;
  struct dds3TrackPolyList_t_array *trackList;
  struct XRD773Unity_CommonMesh_array *v38;
  struct XRD773Unity_CommonMesh_array *v40;
  XRD773Unity_CommonMesh_o *v42;
  UnityEngine_Vector3_array *v43;
  struct XRD773Unity_CommonMesh_array *v44;
  XRD773Unity_CommonMesh_o *v46;
  UnityEngine_Color_array *v47;
  struct XRD773Unity_CommonMesh_array *v48;
  struct XRD773Unity_CommonMesh_array *v50;
  XRD773Unity_CommonMesh_o *v52;
  System_Int32_array *v53;
  struct XRD773Unity_CommonMesh_array *v54;
  UnityEngine_Vector3_array *Position;
  struct XRD773Unity_CommonMesh_array *v57;
  UnityEngine_Color_array *Color;
  struct XRD773Unity_CommonMesh_array *v60;
  System_Int32_array *IndexTable;
  dds3TrackPoly_t_o *v65;
  System_Int32_array *v66;
  u64 v67;
  s32 v68;
  s32 v69;
  struct dds3TrackPolyList_t_array *v70;
  dds3TrackPolyList_t_o *v72;
  f32 alf_raito;
  s64 p_z;
  f32 w;
  u64 v76;
  s64 v77;
  struct UnityEngine_Vector4_array *pVertex;
  f32 v80;
  f32 v81;
  f32 v82;
  f32 v83;
  f32 *p_SDF_CC_NDNM;
  f32 v87;
  f32 v88;
  f32 v89;
  u32 v90;
  struct System_UInt32_array *pVC;
  u32 v94;
  s64 v96;
  s32 v99;
  s64 v100;
  System_UInt32_array *v101;
  s32 v102;
  u32 *v103;
  s32 v104;
  s32 *v105;
  u64 v106;
  s32 v109;
  il2cpp_array_size_t max_length;
  struct XRD773Unity_CommonMesh_array *v111;
  dds3TrackPoly_t_o *v114;
  s64 v115;
  s64 v116;
  dds3TrackPoly_t_o **v121;
  s32 v122;
  u64 v123;
  s32 *m_Items;
  UnityEngine_Vector3_array *v125;
  UnityEngine_Color_array *v126;
  s32 v127;
  s32 v128;
  u16 v129[2];
  s32 face;
  s32 pmax[2];
  System_UInt32_array *face_index[2];
  UnityEngine_Vector3_o v133;
  UnityEngine_Vector3_o v134;
  UnityEngine_Vector4_o v135;
  UnityEngine_Color_o VertexColor;
  UnityEngine_Vector3_o v137;
  UnityEngine_Vector4_o v138;
  UnityEngine_Vector4_o v139;
  UnityEngine_Color_o BlendColor;
  UnityEngine_Color_o v141;

  *pmax = 0;
  face_index[0] = 0;
  face = 0;
  v6 = *hTrackPoly;
  if (!(*hTrackPoly)->pMesh)
  {
    v6->pMesh = NewSpecific(XRD773Unity_CommonMesh, 1u);
    pMesh = (*hTrackPoly)->pMesh;
    {
    }
    Instance = get_Instance();
    Mesh = GetMesh(Instance, (*hTrackPoly)->mode, 0, 0);
    v11 = Mesh;
    pMesh->m_Items[0] = v11;
    v13 = (*hTrackPoly)->pMesh;
    gameObject = get_gameObject(v13->m_Items[0]);
    v16 = NewSpecific(object, 5u);
    name = get_name(gameObject);
    v18 = name;
    v16->m_Items[0] = v18;
    v16->m_Items[1] = ":dds3TrackPolyDraw:UseOne:type:";
    v129[0] = (*hTrackPoly)->type;
    v22 = sub_8D3950(ushort, v129);
    v23 = v22;
    v16->m_Items[2] = v23;
    v16->m_Items[3] = ":";
    v16->m_Items[4] = funcname;
    v30 = Concat_5270224(v16);
    set_name(gameObject, v30);
    v31 = (*hTrackPoly)->pMesh;
    SetAutoHide(v31->m_Items[0], 1);
    v6 = *hTrackPoly;
  }
  if (SLODWORD(v6->trackList->max_length) >= 1)
  {
    v33 = 0;
    v34 = 0;
    v35 = 0;
    do
    {
      if (dds3TrackPolyDrawGetParam(v33, hTrackPoly, &pmax[1], pmax, &face, face_index))
      {
        trackList = (*hTrackPoly)->trackList;
        v34 += trackList->m_Items[v33]->count;
        v35 += face * pmax[0];
      }
      ++v33;
    }
    while (v33 < SLODWORD((*hTrackPoly)->trackList->max_length));
    if (v35 >= 1)
    {
      v38 = (*hTrackPoly)->pMesh;
      if (v34 > SLODWORD(GetPosition(v38->m_Items[0])->max_length))
      {
        v40 = (*hTrackPoly)->pMesh;
        v42 = v40->m_Items[0];
        v43 = NewSpecific(UnityEngine_Vector3, v34);
        SetPosition_20241056(v42, v43);
        v44 = (*hTrackPoly)->pMesh;
        v46 = v44->m_Items[0];
        v47 = NewSpecific(UnityEngine_Color, v34);
        SetColor_20241296(v46, v47);
      }
      v48 = (*hTrackPoly)->pMesh;
      if (v35 > SLODWORD(GetIndexTable(v48->m_Items[0])->max_length))
      {
        v50 = (*hTrackPoly)->pMesh;
        v52 = v50->m_Items[0];
        v53 = NewSpecific(s32, v35);
        SetIndexTable(v52, v53);
      }
      v54 = (*hTrackPoly)->pMesh;
      Position = GetPosition(v54->m_Items[0]);
      v57 = (*hTrackPoly)->pMesh;
      v125 = Position;
      Color = GetColor(v57->m_Items[0], 0);
      v60 = (*hTrackPoly)->pMesh;
      v126 = Color;
      IndexTable = GetIndexTable(v60->m_Items[0]);
      v65 = *hTrackPoly;
      v66 = IndexTable;
      if (SLODWORD((*hTrackPoly)->trackList->max_length) < 1)
      {
        v68 = 0;
        LODWORD(max_length) = IndexTable->max_length;
        if (max_length <= 0)
          goto LABEL_127;
      }
      else
      {
        v67 = 0;
        v68 = 0;
        v69 = 0;
        v122 = 0;
        v121 = hTrackPoly;
        m_Items = IndexTable->m_Items;
        do
        {
          if (dds3TrackPolyDrawGetParam(v67, hTrackPoly, &pmax[1], pmax, &face, face_index))
          {
            v70 = (*hTrackPoly)->trackList;
            v72 = v70->m_Items[v67];
            BlendColor = effGetBlendColor(v72->color);
            v135 = op_Implicit(BlendColor, 0);
            v123 = v67;
            if (v72->count >= 1)
            {
              alf_raito = (*hTrackPoly)->alf_raito;
              p_z = &v125->m_Items[v122].z;
              if (alf_raito == 0.0)
                w = v135.w;
              else
                w = v135.w * alf_raito;
              v76 = 0;
              v77 = 32;
              do
              {
                pVertex = v72->pVertex;
                v80 = *(&pVertex->obj.klass + v77);
                v81 = *(&pVertex->obj.klass + v77 + 4);
                v82 = *(&pVertex->obj.monitor + v77);
                v83 = *(&pVertex->obj.monitor + v77 + 4);
                {
                }
                v138.x = v80;
                v138.y = v81;
                v138.z = v82;
                v138.w = v83;
                v133 = op_Implicit_8738992(v138);
                p_SDF_CC_NDNM = &SDF_CC_NDNM;
                v88 = p_SDF_CC_NDNM[41];
                v87 = p_SDF_CC_NDNM[42];
                v89 = p_SDF_CC_NDNM[43];
                {
                }
                v137.x = v88;
                v137.y = v87;
                v137.z = v89;
                v134 = Scale(v133, v137);
                v90 = v122 + v76;
                *(p_z - 8) = v134;
                pVC = v72->pVC;
                v139.y = v135.y;
                v139.x = v135.x;
                v139.z = v135.z;
                v139.w = w;
                v94 = pVC->m_Items[v76];
                v141 = op_Implicit_27186336(v139);
                VertexColor = effGetVertexColor(v94, v141);
                v96 = v126 + 16 * v122 + v77;
                *v96 = VertexColor;
                if (VertexColor.a > 1.0)
                {
                  *(v96 + 12) = 1065353216;
                }
                ++v76;
                v77 += 16;
                p_z += 12;
              }
              while (v76 < v72->count);
              v122 += v76;
            }
            v128 = face;
            if (face <= 0)
            {
              v99 = pmax[1];
              hTrackPoly = v121;
            }
            else
            {
              v100 = pmax[0];
              v99 = pmax[1];
              if (pmax[0] <= 0)
              {
                v109 = face;
                hTrackPoly = v121;
                if (face <= 1)
                  v109 = 1;
                v69 += pmax[1] * v109;
              }
              else
              {
                v101 = face_index[0];
                v102 = 0;
                v127 = pmax[1];
                v103 = face_index[0]->m_Items;
                do
                {
                  v104 = v68;
                  v105 = &m_Items[v68];
                  v106 = 0;
                  do
                  {
                    v105[v106] = v103[v106] + v69;
                    ++v106;
                  }
                  while (v100 != v106);
                  v99 = v127;
                  ++v102;
                  v68 = v104 + v106;
                  v69 += v127;
                }
                while (v102 < v128);
                hTrackPoly = v121;
                v68 = v104 + v106;
              }
            }
            v67 = v123;
            v69 += v99;
          }
          v65 = *hTrackPoly;
          ++v67;
        }
        while (v67 < SLODWORD((*hTrackPoly)->trackList->max_length));
        LODWORD(max_length) = v66->max_length;
        if (v68 >= max_length)
        {
LABEL_127:
          v111 = v65->pMesh;
          if (LODWORD(v111->max_length))
          {
LABEL_128:
            SetActive(v111->m_Items[0], 1, 0);
            v114 = *hTrackPoly;
            v114->next = hTPDrawListTop;
            hTPDrawListTop = *hTrackPoly;
            return;
          }
LABEL_139:
        }
      }
      v115 = v68;
      do
      {
        v116 = v115 + 1;
        v66->m_Items[v115] = 0;
        max_length = v66->max_length;
        ++v115;
      }
      while (v116 < max_length);
      v111 = (*hTrackPoly)->pMesh;
      if (LODWORD(v111->max_length))
        goto LABEL_128;
      goto LABEL_139;
    }
  }
}

// 0x1556030
bool dds3TrackPolyDrawGetParam(s32 index, dds3TrackPoly_t **hTrackPoly, s32 *div, s32 *pmax, s32 *face, u32 ***face_index) {
  struct dds3TrackPolyList_t_array *trackList;
  dds3TrackPolyList_t_o *v15;
  s32 type;
  System_UInt32_array **p_polySquareFaceIndex5;
  s32 v19;
  s32 v20;
  s32 v25;

  trackList = (*hTrackPoly)->trackList;
  v15 = trackList->m_Items[index];
  if (!v15->count || !HIBYTE(v15->color))
    return 0;
  type = (*hTrackPoly)->type;
  if (type == 4)
  {
    p_polySquareFaceIndex5 = &polySquareFaceIndex5;
    v19 = 24;
    v20 = 5;
  }
  else if (type == 1)
  {
    p_polySquareFaceIndex5 = &polySquareFaceIndex2;
    v19 = 12;
    v20 = 3;
  }
  else if ((*hTrackPoly)->type)
  {
    if (type == 2)
    {
      p_polySquareFaceIndex5 = &polySquareFaceIndex3;
      v19 = 30;
      v20 = 6;
    }
    else
    {
      p_polySquareFaceIndex5 = &polySquareFaceIndex4;
      v19 = 18;
      v20 = 4;
    }
  }
  else
  {
    p_polySquareFaceIndex5 = &polySquareFaceIndex;
    v19 = 6;
    v20 = 2;
  }
  *face_index = *p_polySquareFaceIndex5;
  *div = v20;
  *pmax = v19;
  v25 = (v15->count - *div) / *div;
  *face = v25;
  return v25 > 0;
}

// 0x154bb90
void dds3TrackPolyDrawOff(dds3TrackPoly_t **hTrackPoly) {
  struct XRD773Unity_CommonMesh_array *pMesh;
  il2cpp_array_size_t max_length;
  s64 v5;
  UnityEngine_Object_o *v7;
  struct XRD773Unity_CommonMesh_array *v8;
  s64 v10;

  pMesh = (*hTrackPoly)->pMesh;
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
          v8 = (*hTrackPoly)->pMesh;
          SetActive(*(&v8->obj.klass + v5), 0, 0);
        }
        pMesh = (*hTrackPoly)->pMesh;
        LODWORD(max_length) = pMesh->max_length;
        v10 = v5 - 3;
        ++v5;
      }
      while (v10 < max_length);
    }
  }
}

// 0x154ab20
void dds3TrackPolyInit(void) {
  TrackPolyParm->attr = 0x4000;
}

// 0x154fd20
void dds3TrackPolyLinkOt(void) {
  ;
}

// 0x154b7f0
void dds3TrackPolyListInit(dds3TrackPoly_t **hTrackPoly, s32 number) {
  struct dds3TrackPolyList_t_array *trackList;
  struct dds3TrackPolyList_t_array *v5;
  struct dds3TrackPolyList_t_array *v7;

  trackList = (*hTrackPoly)->trackList;
  trackList->m_Items[number]->count = 0;
  v5 = (*hTrackPoly)->trackList;
  v5->m_Items[number]->rec = 0;
  v7 = (*hTrackPoly)->trackList;
  v7->m_Items[number]->color = -2139062144;
}

// 0x154bed0
void dds3TrackPolyMove(dds3TrackPoly_t **hTrackPoly, s32 number, sdfVector4_t pMove) {
  struct dds3TrackPolyList_t_array *trackList;
  Il2CppClass **v6;
  s64 point;
  Il2CppClass *v8;
  s64 v9;
  u64 v10;
  const char *name;
  const char *v13;
  f32 y;
  f32 w;
  f32 z;
  f32 *v18;
  UnityEngine_Vector4_o v19;
  UnityEngine_Vector4_o v20;

  *&v19.x = 0;
  *&v19.z = 0;
  trackList = (*hTrackPoly)->trackList;
  v6 = &trackList->obj.klass + number;
  point = (*hTrackPoly)->point;
  v8 = v6[4];
  SDF_VU0__LOADVECTOR_B(pMove);
  if (point >= 1)
  {
    v9 = 0;
    v10 = 0;
    do
    {
      name = v8->_1.name;
      v20.y = *&name[v9 + 36];
      v20.z = *&name[v9 + 40];
      v20.w = *&name[v9 + 44];
      v19.x = *&name[v9 + 32];
      v20.x = v19.x;
      v19.y = v20.y;
      v19.z = v20.z;
      v19.w = v20.w;
      SDF_VU0__LOADVECTOR(v20);
      SDF_VU0__ADDVECTOR();
      SDF_VU0__STOREVECTOR(&v19);
      v13 = v8->_1.name;
      y = v19.y;
      z = v19.z;
      w = v19.w;
      ++v10;
      v18 = &v13[v9];
      v9 += 16;
      v18[8] = v19.x;
      v18[9] = y;
      v18[10] = z;
      v18[11] = w;
    }
    while (point != v10);
  }
}

// 0x154c2b0
void dds3TrackPolyMove2(dds3TrackPoly_t **hTrackPoly, s32 number, sdfVector4_t pMove) {
  struct dds3TrackPolyList_t_array *trackList;
  dds3TrackPolyList_t_o *v6;
  struct UnityEngine_Vector4_array *pVertex;
  s32 count;
  u64 v9;
  struct UnityEngine_Vector4_array *p_z;
  s32 v11;
  u64 v14;
  u64 v17;

  trackList = (*hTrackPoly)->trackList;
  v6 = trackList->m_Items[number];
  pVertex = v6->pVertex;
  count = v6->count;
  SDF_VU0__LOADVECTOR_B(pMove);
  if (count >= 3)
  {
    v9 = 0;
    p_z = &pVertex->m_Items[0].z;
    v11 = count / 3;
    do
    {
      SDF_VU0__LOADVECTOR(*&p_z[-1].m_Items[65534].z);
      SDF_VU0__ADDVECTOR();
      SDF_VU0__STOREVECTOR(&p_z[-1].m_Items[65534].z);
      v14 = v9 + 1;
      SDF_VU0__LOADVECTOR(*&p_z->obj.monitor);
      SDF_VU0__ADDVECTOR();
      SDF_VU0__STOREVECTOR(&p_z->obj.monitor);
      v17 = v14 + 1;
      SDF_VU0__LOADVECTOR(*&p_z->max_length);
      SDF_VU0__ADDVECTOR();
      SDF_VU0__STOREVECTOR(&p_z->max_length);
      p_z = (p_z + 48);
      --v11;
      v9 = v17 + 1;
    }
    while (v11);
  }
  v6->pVertex = pVertex;
}

// 0x154bcb0
void dds3TrackPolySet(dds3TrackPoly_t **hTrackPoly, s32 number, sdfVector4_t **pV) {
  struct dds3TrackPolyList_t_array *trackList;
  dds3TrackPolyList_t_o *v8;
  struct UnityEngine_Vector4_array *pVertex;
  s32 rec;
  dds3TrackPoly_t_o *v11;
  s32 point;
  u32 v13;
  UnityEngine_Vector4_o *v14;
  u32 max_length;
  s32 count;

  trackList = (*hTrackPoly)->trackList;
  v8 = trackList->m_Items[number];
  pVertex = v8->pVertex;
  rec = v8->rec;
  if (rec)
  {
    v8->rec = rec - 1;
    if (!LODWORD(pV->max_length))
    {
LABEL_23:
    }
  }
  else
  {
    v11 = *hTrackPoly;
    point = (*hTrackPoly)->point;
    if (point - 2 >= 1)
    {
      v13 = point - 1;
      v14 = &(&pVertex->bounds)[2 * point];
      do
      {
        max_length = pVertex->max_length;
        SDF_VU0__COPYVECTOR(v14, v14[-2]);
        --v13;
        --v14;
      }
      while (v13 != 1);
      v11 = *hTrackPoly;
    }
    v8->rec = v11->rec;
    count = v8->count;
    if (count < point)
    {
      v8->count = count + 2;
      if (!LODWORD(pV->max_length))
        goto LABEL_23;
    }
    else if (!LODWORD(pV->max_length))
    {
      goto LABEL_23;
    }
  }
  SDF_VU0__COPYVECTOR(pVertex->m_Items, pV->m_Items[0]);
  SDF_VU0__COPYVECTOR(&pVertex->m_Items[1], pV->m_Items[1]);
  v8->pVertex = pVertex;
}

// 0x154c030
void dds3TrackPolySet2(dds3TrackPoly_t **hTrackPoly, s32 number, sdfVector4_t **pV) {
  struct dds3TrackPolyList_t_array *trackList;
  dds3TrackPolyList_t_o *v8;
  struct UnityEngine_Vector4_array *pVertex;
  s32 rec;
  dds3TrackPoly_t_o *v11;
  s32 point;
  u32 v13;
  UnityEngine_Vector4_o *v14;
  u32 max_length;
  s32 count;

  trackList = (*hTrackPoly)->trackList;
  v8 = trackList->m_Items[number];
  pVertex = v8->pVertex;
  rec = v8->rec;
  if (rec)
  {
    v8->rec = rec - 1;
    if (!LODWORD(pV->max_length))
    {
LABEL_27:
    }
  }
  else
  {
    v11 = *hTrackPoly;
    point = (*hTrackPoly)->point;
    if (point - 3 >= 1)
    {
      v13 = point - 1;
      v14 = &(&pVertex->bounds)[2 * point];
      do
      {
        max_length = pVertex->max_length;
        SDF_VU0__COPYVECTOR(v14, v14[-3]);
        --v13;
        --v14;
      }
      while (v13 != 2);
      v11 = *hTrackPoly;
    }
    v8->rec = v11->rec;
    count = v8->count;
    if (count < point)
    {
      v8->count = count + 3;
      if (!LODWORD(pV->max_length))
        goto LABEL_27;
    }
    else if (!LODWORD(pV->max_length))
    {
      goto LABEL_27;
    }
  }
  SDF_VU0__COPYVECTOR(pVertex->m_Items, pV->m_Items[0]);
  SDF_VU0__COPYVECTOR(&pVertex->m_Items[1], pV->m_Items[1]);
  SDF_VU0__COPYVECTOR(&pVertex->m_Items[2], pV->m_Items[2]);
  v8->pVertex = pVertex;
}

// 0x154fc20
void dds3TrackPolySetMode(dds3TrackPoly_t **hTrackPoly, u16 mode) {
  (*hTrackPoly)->mode = mode;
}

// 0x154de00
void dds3TrackPolyVC3Set_Acute(dds3TrackPoly_t **hTrackPoly, u32 abgr_0, u32 abgr_1, u32 abgr_2) {
  dds3TrackPoly_t_o *v5;
  u32 v6;
  u64 v7;
  struct dds3TrackPolyList_t_array *trackList;
  struct System_UInt32_array *pVC;
  s32 v11;
  u32 v12;
  u64 v13;
  u32 v14;
  u32 v15;
  u32 *m_Items;
  u64 max_length_low;
  u64 v25;
  u32 v26;
  u64 v27;
  struct dds3TrackPolyList_t_array *v29;
  s32 point;
  s64 number;
  u64 v33;

  v5 = *hTrackPoly;
  number = (*hTrackPoly)->number;
  if ((*hTrackPoly)->number >= 1)
  {
    point = v5->point;
    v6 = point / 6;
    v7 = 0;
    trackList = v5->trackList;
    if (!LODWORD(trackList->max_length))
    {
LABEL_5:
    }
    while (1)
    {
      pVC = trackList->m_Items[v7]->pVC;
      v33 = v7;
      if (point >= 6)
      {
        v12 = abgr_0 & 0xFF000000;
        v11 = point / 6;
        v13 = 0;
        v15 = abgr_2 & 0xFF000000;
        v14 = abgr_1 & 0xFF000000;
        m_Items = pVC->m_Items;
        do
        {
          v15 -= (abgr_2 & 0xFF000000) / v6;
          v14 -= (abgr_1 & 0xFF000000) / v6;
          max_length_low = LODWORD(pVC->max_length);
          *m_Items = v15 & 0xFF000000 | abgr_2 & 0xFFFFFF;
          v12 -= (abgr_0 & 0xFF000000) / v6;
          v25 = v13 + 2;
          v26 = v12 & 0xFF000000 | abgr_0 & 0xFFFFFF;
          m_Items[1] = v14 & 0xFF000000 | abgr_1 & 0xFFFFFF;
          m_Items[2] = v26;
          v27 = v25 + 1;
          m_Items[3] = v26;
          m_Items[4] = m_Items[1];
          m_Items[5] = *m_Items;
          --v11;
          m_Items += 6;
          v13 = v27 + 3;
        }
        while (v11);
      }
      v29 = (*hTrackPoly)->trackList;
      v7 = v33 + 1;
      v29->m_Items[v33]->pVC = pVC;
      if (v33 + 1 == number)
        break;
      trackList = (*hTrackPoly)->trackList;
      if (v7 >= LODWORD(trackList->max_length))
        goto LABEL_5;
    }
  }
}

// 0x154e150
void dds3TrackPolyVC3Set_AcuteW(dds3TrackPoly_t **hTrackPoly, u32 abgr_0, u32 abgr_1, u32 abgr_2) {
  dds3TrackPoly_t_o *v5;
  u32 v6;
  u64 v7;
  struct dds3TrackPolyList_t_array *trackList;
  struct System_UInt32_array *pVC;
  u64 v11;
  s32 v12;
  s32 v13;
  s32 v14;
  signed s32 v15;
  u32 *m_Items;
  u32 *v17;
  u32 *v23;
  u64 v24;
  u64 max_length_low;
  u32 v28;
  u32 v30;
  u32 v31;
  u32 v32;
  signed s32 v33;
  u64 v34;
  u64 v39;
  u32 v41;
  u32 v43;
  u64 v44;
  struct dds3TrackPolyList_t_array *v47;
  s64 number;
  s32 point;
  u64 v51;
  u32 v52;
  u32 v53;
  u32 v54;
  u32 v55;
  u32 v56;
  u32 v57;
  signed s32 v58;

  v5 = *hTrackPoly;
  number = (*hTrackPoly)->number;
  if ((*hTrackPoly)->number >= 1)
  {
    point = v5->point;
    v6 = (point / 6) >> 1;
    v57 = (abgr_0 & 0xFF000000) / v6;
    v58 = v6;
    v56 = (abgr_1 & 0xFF000000) / v6;
    v55 = abgr_0 & 0xFFFFFF;
    v7 = 0;
    v54 = abgr_1 & 0xFFFFFF;
    v52 = (abgr_2 & 0xFF000000) / v6;
    v53 = abgr_2 & 0xFFFFFF;
    trackList = v5->trackList;
    if (!LODWORD(trackList->max_length))
    {
LABEL_5:
    }
    while (1)
    {
      pVC = trackList->m_Items[v7]->pVC;
      v51 = v7;
      if (point >= 12)
      {
        v11 = 0;
        v12 = 0;
        v13 = 0;
        v14 = 0;
        v15 = 0;
        m_Items = pVC->m_Items;
        v17 = &pVC->m_Items[6];
        do
        {
          v23 = v17;
          v24 = v11;
          max_length_low = LODWORD(pVC->max_length);
          *m_Items = v14 & 0xFF000000 | v53;
          m_Items[1] = v13 & 0xFF000000 | v54;
          v28 = v12 & 0xFF000000 | v55;
          m_Items[2] = v28;
          m_Items[3] = v28;
          m_Items[4] = m_Items[1];
          m_Items[5] = *m_Items;
          m_Items += 6;
          v12 += v57;
          v13 += v56;
          ++v15;
          v14 += v52;
          v11 = v24 + 6;
          v17 += 6;
        }
        while (v15 < v58);
        v31 = abgr_1 & 0xFF000000;
        v30 = abgr_0 & 0xFF000000;
        v32 = abgr_2 & 0xFF000000;
        v33 = 0;
        v34 = v24 + 6;
        do
        {
          v31 -= v56;
          v32 -= v52;
          v39 = LODWORD(pVC->max_length);
          v41 = v34 + 1;
          *v23 = v32 & 0xFF000000 | v53;
          v30 -= v57;
          v43 = v30 & 0xFF000000 | v55;
          v44 = v34 + 2;
          v23[1] = v31 & 0xFF000000 | v54;
          v23[2] = v43;
          v23[3] = v43;
          v23[4] = v23[1];
          ++v33;
          v23[5] = *v23;
          v23 += 6;
          v34 = v44 + 4;
        }
        while (v33 < v58);
      }
      v47 = (*hTrackPoly)->trackList;
      v7 = v51 + 1;
      v47->m_Items[v51]->pVC = pVC;
      if (v51 + 1 == number)
        break;
      trackList = (*hTrackPoly)->trackList;
      if (v7 >= LODWORD(trackList->max_length))
        goto LABEL_5;
    }
  }
}

// 0x154db90
void dds3TrackPolyVC3Set_Normal(dds3TrackPoly_t **hTrackPoly, u32 abgr_0, u32 abgr_1, u32 abgr_2) {
  dds3TrackPoly_t_o *v5;
  s32 point;
  u64 v7;
  struct dds3TrackPolyList_t_array *trackList;
  struct System_UInt32_array *pVC;
  s32 v11;
  u64 v12;
  u32 *v13;
  u64 max_length_low;
  u64 v15;
  u64 v16;
  u64 v17;
  u64 v18;
  u64 v19;
  struct dds3TrackPolyList_t_array *v26;
  Il2CppClass **v28;
  s64 number;

  v5 = *hTrackPoly;
  number = (*hTrackPoly)->number;
  if ((*hTrackPoly)->number >= 1)
  {
    point = v5->point;
    v7 = 0;
    trackList = v5->trackList;
    if (!LODWORD(trackList->max_length))
    {
LABEL_5:
    }
    while (1)
    {
      pVC = trackList->m_Items[v7]->pVC;
      if (point >= 6)
      {
        v11 = point / 6;
        v12 = 0;
        v13 = &pVC->m_Items[5];
        do
        {
          max_length_low = LODWORD(pVC->max_length);
          v15 = v12 + 1;
          *(v13 - 5) = abgr_2;
          v16 = v15 + 1;
          *(v13 - 4) = abgr_1;
          v17 = v16 + 1;
          *(v13 - 3) = abgr_0;
          v18 = v17 + 1;
          *(v13 - 2) = abgr_0;
          v19 = v18 + 1;
          *(v13 - 1) = abgr_1;
          --v11;
          v12 = v19 + 1;
          *v13 = abgr_2;
          v13 += 6;
        }
        while (v11);
      }
      v26 = (*hTrackPoly)->trackList;
      v28 = &v26->obj.klass + v7++;
      v28[4]->_1.namespaze = pVC;
      if (v7 == number)
        break;
      trackList = (*hTrackPoly)->trackList;
      if (v7 >= LODWORD(trackList->max_length))
        goto LABEL_5;
    }
  }
}

// 0x154f140
void dds3TrackPolyVC5Set_Acute(dds3TrackPoly_t **hTrackPoly, u32 abgr_0, u32 abgr_1, u32 abgr_2) {
  dds3TrackPoly_t_o *v5;
  u32 v6;
  u64 v7;
  struct dds3TrackPolyList_t_array *trackList;
  struct System_UInt32_array *pVC;
  s32 v11;
  u32 v12;
  u64 v13;
  u32 v14;
  u32 v15;
  u32 *m_Items;
  u64 max_length_low;
  u64 v23;
  u64 v25;
  u64 v26;
  u64 v27;
  u64 v28;
  u64 v29;
  struct dds3TrackPolyList_t_array *v31;
  s32 point;
  s64 number;
  u64 v35;

  v5 = *hTrackPoly;
  number = (*hTrackPoly)->number;
  if ((*hTrackPoly)->number >= 1)
  {
    point = v5->point;
    v6 = point / 5;
    v7 = 0;
    trackList = v5->trackList;
    if (!LODWORD(trackList->max_length))
    {
LABEL_5:
    }
    while (1)
    {
      pVC = trackList->m_Items[v7]->pVC;
      v35 = v7;
      if (point >= 5)
      {
        v12 = abgr_0 & 0xFF000000;
        v11 = point / 5;
        v13 = 0;
        v15 = abgr_2 & 0xFF000000;
        v14 = abgr_1 & 0xFF000000;
        m_Items = pVC->m_Items;
        do
        {
          v15 -= (abgr_2 & 0xFF000000) / v6;
          v14 -= (abgr_1 & 0xFF000000) / v6;
          max_length_low = LODWORD(pVC->max_length);
          v12 -= (abgr_0 & 0xFF000000) / v6;
          v23 = v13 + 1;
          *m_Items = v15 & 0xFF000000 | abgr_2 & 0xFFFFFF;
          v25 = v23 + 1;
          m_Items[1] = v14 & 0xFF000000 | abgr_1 & 0xFFFFFF;
          v26 = v25 - 1;
          m_Items[2] = v12 & 0xFF000000 | abgr_0 & 0xFFFFFF;
          v27 = v26 + 2;
          v28 = v27 - 3;
          m_Items[3] = m_Items[1];
          v29 = v28 + 4;
          m_Items[4] = *m_Items;
          --v11;
          m_Items += 5;
          v13 = v29 + 1;
        }
        while (v11);
      }
      v31 = (*hTrackPoly)->trackList;
      v7 = v35 + 1;
      v31->m_Items[v35]->pVC = pVC;
      if (v35 + 1 == number)
        break;
      trackList = (*hTrackPoly)->trackList;
      if (v7 >= LODWORD(trackList->max_length))
        goto LABEL_5;
    }
  }
}

// 0x154f430
void dds3TrackPolyVC5Set_AcuteR(dds3TrackPoly_t **hTrackPoly, u32 abgr_0, u32 abgr_1, u32 abgr_2) {
  dds3TrackPoly_t_o *v5;
  u32 v6;
  u64 v7;
  struct dds3TrackPolyList_t_array *trackList;
  struct System_UInt32_array *pVC;
  s32 v11;
  u64 v12;
  s32 v13;
  s32 v14;
  s32 v15;
  u32 *m_Items;
  u64 max_length_low;
  u64 v23;
  u64 v25;
  u64 v26;
  u64 v27;
  u64 v28;
  u64 v29;
  struct dds3TrackPolyList_t_array *v31;
  s32 point;
  s64 number;
  u64 v35;

  v5 = *hTrackPoly;
  number = (*hTrackPoly)->number;
  if ((*hTrackPoly)->number >= 1)
  {
    point = v5->point;
    v6 = point / 5;
    v7 = 0;
    trackList = v5->trackList;
    if (!LODWORD(trackList->max_length))
    {
LABEL_5:
    }
    while (1)
    {
      pVC = trackList->m_Items[v7]->pVC;
      v35 = v7;
      if (point >= 5)
      {
        v11 = point / 5;
        v12 = 0;
        v13 = 0;
        v14 = 0;
        v15 = 0;
        m_Items = pVC->m_Items;
        do
        {
          v15 += (abgr_2 & 0xFF000000) / v6;
          v14 += (abgr_1 & 0xFF000000) / v6;
          max_length_low = LODWORD(pVC->max_length);
          v13 += (abgr_0 & 0xFF000000) / v6;
          v23 = v12 + 1;
          *m_Items = v15 & 0xFF000000 | abgr_2 & 0xFFFFFF;
          v25 = v23 + 1;
          m_Items[1] = v14 & 0xFF000000 | abgr_1 & 0xFFFFFF;
          v26 = v25 - 1;
          m_Items[2] = v13 & 0xFF000000 | abgr_0 & 0xFFFFFF;
          v27 = v26 + 2;
          v28 = v27 - 3;
          m_Items[3] = m_Items[1];
          v29 = v28 + 4;
          m_Items[4] = *m_Items;
          --v11;
          m_Items += 5;
          v12 = v29 + 1;
        }
        while (v11);
      }
      v31 = (*hTrackPoly)->trackList;
      v7 = v35 + 1;
      v31->m_Items[v35]->pVC = pVC;
      if (v35 + 1 == number)
        break;
      trackList = (*hTrackPoly)->trackList;
      if (v7 >= LODWORD(trackList->max_length))
        goto LABEL_5;
    }
  }
}

// 0x154f720
void dds3TrackPolyVC5Set_AcuteW(dds3TrackPoly_t **hTrackPoly, u32 abgr_0, u32 abgr_1, u32 abgr_2) {
  dds3TrackPoly_t_o *v5;
  s64 number;
  u32 v7;
  dds3TrackPoly_t_o **v8;
  u64 v9;
  struct dds3TrackPolyList_t_array *trackList;
  u64 v12;
  s32 v13;
  s32 v14;
  s32 v15;
  signed s32 v16;
  u32 *m_Items;
  u32 *v18;
  u32 *v23;
  u64 v24;
  u64 max_length_low;
  u64 v29;
  u32 v30;
  u32 v31;
  u32 v32;
  signed s32 v33;
  u64 v38;
  struct dds3TrackPolyList_t_array *v42;
  s64 v44;
  s32 point;
  u64 v46;
  u32 v47;
  u32 v48;
  u32 v49;
  u32 v50;
  u32 v51;
  u32 v52;
  signed s32 v53;
  struct System_UInt32_array *pVC;

  v5 = *hTrackPoly;
  number = (*hTrackPoly)->number;
  if (number >= 1)
  {
    v44 = (*hTrackPoly)->number;
    point = v5->point;
    v7 = (point / 5) >> 1;
    v52 = (abgr_0 & 0xFF000000) / v7;
    v53 = v7;
    v51 = (abgr_1 & 0xFF000000) / v7;
    v50 = abgr_0 & 0xFFFFFF;
    v8 = hTrackPoly;
    v9 = 0;
    v49 = abgr_1 & 0xFFFFFF;
    v47 = (abgr_2 & 0xFF000000) / v7;
    v48 = abgr_2 & 0xFFFFFF;
    trackList = v5->trackList;
    if (!LODWORD(trackList->max_length))
    {
LABEL_5:
    }
    while (1)
    {
      pVC = trackList->m_Items[v9]->pVC;
      v46 = v9;
      if (point >= 10)
      {
        v12 = 0;
        v13 = 0;
        v14 = 0;
        v15 = 0;
        v16 = 0;
        m_Items = pVC->m_Items;
        v18 = &pVC->m_Items[5];
        do
        {
          v23 = v18;
          v24 = v12;
          max_length_low = LODWORD(pVC->max_length);
          *m_Items = v15 & 0xFF000000 | v48;
          m_Items[1] = v14 & 0xFF000000 | v49;
          m_Items[2] = v13 & 0xFF000000 | v50;
          m_Items[3] = m_Items[1];
          m_Items[4] = *m_Items;
          m_Items += 5;
          v13 += v52;
          v14 += v51;
          ++v16;
          v15 += v47;
          v12 = v24 + 5;
          v18 += 5;
        }
        while (v16 < v53);
        v8 = hTrackPoly;
        number = v44;
        v29 = v24 + 5;
        v31 = abgr_1 & 0xFF000000;
        v30 = abgr_0 & 0xFF000000;
        v32 = abgr_2 & 0xFF000000;
        v33 = 0;
        do
        {
          v31 -= v51;
          v32 -= v47;
          v38 = LODWORD(pVC->max_length);
          *v23 = v32 & 0xFF000000 | v48;
          v30 -= v52;
          v23[1] = v31 & 0xFF000000 | v49;
          v23[2] = v30 & 0xFF000000 | v50;
          v23[3] = v23[1];
          ++v33;
          v23[4] = *v23;
          v23 += 5;
          v29 += 5LL;
        }
        while (v33 < v53);
      }
      v42 = (*v8)->trackList;
      ++v9;
      v42->m_Items[v46]->pVC = pVC;
      if (v46 + 1 == number)
        break;
      trackList = (*v8)->trackList;
      if (v9 >= LODWORD(trackList->max_length))
        goto LABEL_5;
    }
  }
}

// 0x154ee90
void dds3TrackPolyVC5Set_Normal(dds3TrackPoly_t **hTrackPoly, u32 abgr_0, u32 abgr_1, u32 abgr_2) {
  dds3TrackPoly_t_o *v5;
  s64 number;
  s32 point;
  u64 v8;
  struct dds3TrackPolyList_t_array *v9;
  struct System_UInt32_array *pVC;
  s32 v12;
  u64 v13;
  u32 *v14;
  u64 max_length_low;
  u64 v16;
  u64 v17;
  u64 v18;
  u64 v19;
  struct dds3TrackPolyList_t_array *v25;
  Il2CppClass **v27;
  u64 i;
  struct dds3TrackPolyList_t_array *trackList;

  v5 = *hTrackPoly;
  number = (*hTrackPoly)->number;
  if (number >= 1)
  {
    point = v5->point;
    if (point <= 4)
    {
      for (i = 0; ; ++i)
      {
        trackList = v5->trackList;
        trackList->m_Items[i]->pVC = trackList->m_Items[i]->pVC;
        if (number - 1 == i)
          break;
        v5 = *hTrackPoly;
      }
    }
    else
    {
      v8 = 0;
      v9 = v5->trackList;
      if (!LODWORD(v9->max_length))
      {
LABEL_6:
      }
      while (1)
      {
        pVC = v9->m_Items[v8]->pVC;
        v12 = point / 5;
        v13 = 0;
        v14 = &pVC->m_Items[4];
        do
        {
          max_length_low = LODWORD(pVC->max_length);
          v16 = v13 + 1;
          *(v14 - 4) = abgr_2;
          v17 = v16 + 1;
          *(v14 - 3) = abgr_1;
          v18 = v17 + 1;
          *(v14 - 2) = abgr_0;
          v19 = v18 + 1;
          *(v14 - 1) = abgr_1;
          --v12;
          v13 = v19 + 1;
          *v14 = abgr_2;
          v14 += 5;
        }
        while (v12);
        v25 = (*hTrackPoly)->trackList;
        v27 = &v25->obj.klass + v8++;
        v27[4]->_1.namespaze = pVC;
        if (v8 == number)
          break;
        v9 = (*hTrackPoly)->trackList;
        if (v8 >= LODWORD(v9->max_length))
          goto LABEL_6;
      }
    }
  }
}

// 0x154c500
void dds3TrackPolyVCRefresh_ParType1(dds3TrackPoly_t **hTrackPoly, u32 index) {
  struct dds3TrackPolyList_t_array *trackList;
  u32 count;
  struct System_UInt32_array *pVC;
  u32 v10;
  u32 v11;
  f32 v12;
  u64 v13;
  u32 v15;
  u64 max_length_low;
  char *v17;
  u64 v18;
  struct dds3TrackPolyList_t_array *v20;
  UnityEngine_Vector4_o v22;

  *&v22.x = 0;
  *&v22.z = 0;
  sub_854690(&v22.x, 0.0, 0.0, 0.0, 0.0);
  trackList = (*hTrackPoly)->trackList;
  count = trackList->m_Items[index]->count;
  pVC = (*hTrackPoly)->trackList->m_Items[index]->pVC;
  if (count >= 4)
  {
    v10 = count >> 1;
    v11 = pVC->m_Items[0];
    SDF_VU0__dds3ColorItoF(v11 & 0xFF000000);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__LOADVECTOR(v22);
    v12 = v10;
    SDF_VU0__INTERPOLATE(1.0 / v12);
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__dds3ColorItoF(v11);
    if (v10)
    {
      v13 = 0;
      do
      {
        SDF_VU0__COPYVECTOR_A_TO_B();
        v15 = SDF_VU0__dds3ColorFtoI(128.0);
        max_length_low = LODWORD(pVC->max_length);
        v17 = pVC + 4 * v13;
        *(v17 + 8) = v15;
        v18 = v13 + 1;
        *(v17 + 9) = v15;
        SDF_VU0__SUBVECTOR_B_C();
        SDF_VU0__COPYVECTOR_B_TO_A();
        --v10;
        v13 = v18 + 1;
      }
      while (v10);
    }
    v20 = (*hTrackPoly)->trackList;
    v20->m_Items[index]->pVC = pVC;
  }
}

// 0x154c760
void dds3TrackPolyVCRefresh_ParType2(dds3TrackPoly_t **hTrackPoly, u32 index) {
  struct dds3TrackPolyList_t_array *trackList;
  struct dds3TrackPolyList_t_array *v7;
  struct System_UInt32_array *pVC;
  u32 v10;
  u32 v12;
  u32 v13;
  u32 *m_Items;
  f32 v15;
  f32 v16;
  u64 v17;
  u32 v18;
  u32 v20;
  u32 v22;
  u64 max_length_low;
  struct dds3TrackPolyList_t_array *v25;
  UnityEngine_Vector4_o v27;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v29;
  UnityEngine_Vector4_o v30;
  UnityEngine_Vector4_o v31;

  *&v31.x = 0;
  *&v31.z = 0;
  sub_854690(&v31.x, 0.0, 0.0, 0.0, 0.0);
  *&v30.x = 0;
  *&v30.z = 0;
  *&v29.x = 0;
  *&v29.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v27.x = 0;
  *&v27.z = 0;
  trackList = (*hTrackPoly)->trackList;
  if (trackList->m_Items[index]->count >= 6u)
  {
    v7 = (*hTrackPoly)->trackList;
    pVC = v7->m_Items[index]->pVC;
    v10 = trackList->m_Items[index]->count / 3u;
    v12 = pVC->m_Items[1];
    m_Items = pVC->m_Items;
    v13 = pVC->m_Items[0];
    SDF_VU0__dds3ColorItoF(v12 & 0xFF000000);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__LOADVECTOR(v31);
    v15 = v10;
    v16 = 1.0 / v15;
    SDF_VU0__INTERPOLATE(1.0 / v15);
    SDF_VU0__STOREVECTOR(&p);
    SDF_VU0__dds3ColorItoF(v13 & 0xFF000000);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__LOADVECTOR(v31);
    SDF_VU0__INTERPOLATE(v16);
    SDF_VU0__STOREVECTOR(&v27);
    SDF_VU0__dds3ColorItoF(v12);
    SDF_VU0__STOREVECTOR(&v30);
    SDF_VU0__dds3ColorItoF(v13);
    SDF_VU0__STOREVECTOR(&v29);
    v17 = 0;
    v18 = 0;
    do
    {
      SDF_VU0__LOADVECTOR(v30);
      SDF_VU0__COPYVECTOR_A_TO_B();
      v20 = SDF_VU0__dds3ColorFtoI(128.0);
      m_Items[1] = v20;
      SDF_VU0__LOADVECTOR_C(p);
      SDF_VU0__SUBVECTOR_B_C();
      SDF_VU0__STOREVECTOR_B(&v30);
      SDF_VU0__LOADVECTOR(v29);
      SDF_VU0__COPYVECTOR_A_TO_B();
      v22 = SDF_VU0__dds3ColorFtoI(128.0);
      max_length_low = LODWORD(pVC->max_length);
      *m_Items = v22;
      m_Items[2] = v22;
      SDF_VU0__LOADVECTOR_C(v27);
      SDF_VU0__SUBVECTOR_B_C();
      SDF_VU0__STOREVECTOR_B(&v29);
      ++v18;
      v17 += 3LL;
      m_Items += 3;
    }
    while (v18 < v10);
    v25 = (*hTrackPoly)->trackList;
    v25->m_Items[index]->pVC = pVC;
  }
}

// 0x154fc30
void dds3TrackPolyVCSet(dds3TrackPoly_t **hTrackPoly, s32 type, u32 abgr_in, u32 abgr_out) {
  struct polyManager_VCSetFuncDelegate_array_array *VCSetFunc;
  s64 v11;
  polyManager_VCSetFuncDelegate_array *v13;

  v11 = (*hTrackPoly)->type;
  v13 = VCSetFunc->m_Items[v11];
  Invoke(v13->m_Items[type], hTrackPoly, abgr_in, abgr_out, 0);
}

// 0x154d540
void dds3TrackPolyVCSet2_Acute(dds3TrackPoly_t **hTrackPoly, u32 abgr_in, u32 abgr_out) {
  s64 point;
  s64 number;
  u64 v9;
  s64 v10;
  s64 v11;
  f32 v12;
  f32 v13;
  u32 v14;
  s64 v15;
  u64 i;
  struct dds3TrackPolyList_t_array *trackList;
  struct System_UInt32_array *pVC;
  u64 v20;
  u32 v21;
  u32 v23;
  u32 *v25;
  u32 v26;
  u64 max_length_low;
  struct dds3TrackPolyList_t_array *v29;
  Il2CppClass **v31;
  u32 v32;
  UnityEngine_Vector4_o v33;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v35;
  UnityEngine_Vector4_o v36;
  u32 rgba;
  UnityEngine_Vector4_o v38;
  UnityEngine_Vector4_o v39;

  *&v36.x = 0;
  *&v36.z = 0;
  *&v35.x = 0;
  *&v35.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v33.x = 0;
  *&v33.z = 0;
  sub_854690(&v33.x, 0.0, 0.0, 0.0, 0.0);
  *&v36.x = 0;
  *&v36.z = 0;
  *&v35.x = 0;
  *&v35.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  number = (*hTrackPoly)->number;
  point = (*hTrackPoly)->point;
  v32 = (*hTrackPoly)->point;
  rgba = abgr_in;
  v9 = (2863311531LL * point) >> 33;
  SDF_VU0__dds3ColorItoF(abgr_in & 0xFF000000);
  SDF_VU0__COPYVECTOR_A_TO_B();
  v10 = *&v33.x;
  v11 = *&v33.z;
  SDF_VU0__LOADVECTOR(v33);
  v12 = v9;
  v13 = 1.0 / v12;
  SDF_VU0__INTERPOLATE(1.0 / v12);
  SDF_VU0__STOREVECTOR(&p);
  v14 = abgr_out;
  SDF_VU0__dds3ColorItoF(abgr_out & 0xFF000000);
  SDF_VU0__COPYVECTOR_A_TO_B();
  *&v38.x = v10;
  *&v38.z = v11;
  SDF_VU0__LOADVECTOR(v38);
  SDF_VU0__INTERPOLATE(v13);
  SDF_VU0__STOREVECTOR(&p);
  if (number)
  {
    v15 = number;
    for (i = 0; i != v15; ++i)
    {
      trackList = (*hTrackPoly)->trackList;
      pVC = trackList->m_Items[i]->pVC;
      SDF_VU0__dds3ColorItoF(rgba);
      SDF_VU0__STOREVECTOR(&v36);
      SDF_VU0__dds3ColorItoF(v14);
      SDF_VU0__STOREVECTOR(&v35);
      if (v32 >= 3)
      {
        v20 = 0;
        v21 = 0;
        do
        {
          SDF_VU0__LOADVECTOR(v36);
          SDF_VU0__COPYVECTOR_A_TO_B();
          v23 = SDF_VU0__dds3ColorFtoI(128.0);
          v25 = (pVC + 4 * v20);
          v25[9] = v23;
          SDF_VU0__LOADVECTOR_C(p);
          SDF_VU0__SUBVECTOR_B_C();
          SDF_VU0__STOREVECTOR_B(&v36);
          SDF_VU0__LOADVECTOR(v35);
          SDF_VU0__COPYVECTOR_A_TO_B();
          v26 = SDF_VU0__dds3ColorFtoI(128.0);
          max_length_low = LODWORD(pVC->max_length);
          v25[8] = v26;
          v39.x = 0.0;
          v39.y = 0.0;
          v39.z = 0.0;
          v39.w = 0.0;
          v25[10] = v26;
          SDF_VU0__LOADVECTOR_C(v39);
          SDF_VU0__SUBVECTOR_B_C();
          SDF_VU0__STOREVECTOR_B(&v35);
          ++v21;
          v20 += 3LL;
        }
        while (v21 < v9);
      }
      v29 = (*hTrackPoly)->trackList;
      v31 = &v29->obj.klass + i;
      v31[4]->_1.namespaze = pVC;
    }
  }
}

// 0x154d8d0
void dds3TrackPolyVCSet2_AcuteW(dds3TrackPoly_t **hTrackPoly, u32 abgr_in, u32 abgr_out) {
  dds3TrackPoly_t_o *v4;
  s32 v5;
  u32 v6;
  dds3TrackPoly_t_o **v7;
  u64 v8;
  struct dds3TrackPolyList_t_array *trackList;
  struct System_UInt32_array *pVC;
  u64 v12;
  s32 v13;
  s32 v14;
  s32 v15;
  u32 *v16;
  u32 *v17;
  u64 max_length_low;
  u32 *v20;
  u32 v21;
  u32 v24;
  u32 v25;
  s32 v26;
  u64 v27;
  u32 v29;
  struct dds3TrackPolyList_t_array *v32;
  s64 number;
  s32 point;
  u64 v36;
  u32 v37;
  u32 v38;
  u32 v39;

  v4 = *hTrackPoly;
  number = (*hTrackPoly)->number;
  if ((*hTrackPoly)->number >= 1)
  {
    point = v4->point;
    v5 = (point / 3) >> 1;
    v39 = (abgr_in & 0xFF000000) / v5;
    v6 = (abgr_out & 0xFF000000) / v5;
    v7 = hTrackPoly;
    v8 = 0;
    v38 = abgr_in & 0xFFFFFF;
    v37 = abgr_out & 0xFFFFFF;
    trackList = v4->trackList;
    if (!LODWORD(trackList->max_length))
    {
LABEL_5:
    }
    while (1)
    {
      pVC = trackList->m_Items[v8]->pVC;
      v36 = v8;
      if (point >= 6)
      {
        v12 = 0;
        v13 = 0;
        v14 = 0;
        v15 = 0;
        v16 = &pVC->m_Items[5];
        do
        {
          v17 = v16;
          max_length_low = LODWORD(pVC->max_length);
          v20 = (pVC + 4 * v12);
          v20[9] = v13 & 0xFF000000 | v38;
          v21 = v14 & 0xFF000000 | v37;
          v20[10] = v21;
          ++v15;
          v14 += v6;
          v12 += 3LL;
          v13 += v39;
          v16 = v17 + 3;
          v20[8] = v21;
        }
        while (v15 < v5);
        v7 = hTrackPoly;
        v25 = abgr_out & 0xFF000000;
        v24 = abgr_in & 0xFF000000;
        v26 = 0;
        do
        {
          v24 -= v39;
          v27 = LODWORD(pVC->max_length);
          v25 -= v6;
          *(v17 - 1) = v24 & 0xFF000000 | v38;
          v29 = v25 & 0xFF000000 | v37;
          *v17 = v29;
          ++v26;
          *(v17 - 2) = v29;
          v12 += 3LL;
          v17 += 3;
        }
        while (v26 < v5);
      }
      v32 = (*v7)->trackList;
      v8 = v36 + 1;
      v32->m_Items[v36]->pVC = pVC;
      if (v36 + 1 == number)
        break;
      trackList = (*v7)->trackList;
      if (v8 >= LODWORD(trackList->max_length))
        goto LABEL_5;
    }
  }
}

// 0x154d310
void dds3TrackPolyVCSet2_Normal(dds3TrackPoly_t **hTrackPoly, u32 abgr_in, u32 abgr_out) {
  dds3TrackPoly_t_o *v4;
  s64 number;
  s32 point;
  u64 v7;
  struct dds3TrackPolyList_t_array *v8;
  struct System_UInt32_array *pVC;
  u64 v11;
  s32 v12;
  u32 *v13;
  u64 max_length_low;
  struct dds3TrackPolyList_t_array *v18;
  Il2CppClass **v20;
  u64 v21;
  s64 v22;
  struct dds3TrackPolyList_t_array *trackList;

  v4 = *hTrackPoly;
  number = (*hTrackPoly)->number;
  if (number >= 1)
  {
    point = v4->point;
    if (point <= 2)
    {
      v21 = 0;
      v22 = number - 1;
      while (1)
      {
        trackList = v4->trackList;
        trackList->m_Items[v21]->pVC = trackList->m_Items[v21]->pVC;
        if (v22 == v21)
          break;
        v4 = *hTrackPoly;
        ++v21;
      }
    }
    else
    {
      v7 = 0;
      v8 = v4->trackList;
      if (!LODWORD(v8->max_length))
      {
LABEL_6:
      }
      while (1)
      {
        pVC = v8->m_Items[v7]->pVC;
        v11 = 0;
        v12 = point / 3;
        v13 = &pVC->m_Items[2];
        do
        {
          max_length_low = LODWORD(pVC->max_length);
          *(v13 - 1) = abgr_in;
          *v13 = abgr_out;
          *(v13 - 2) = abgr_out;
          v11 += 3LL;
          v13 += 3;
          --v12;
        }
        while (v12);
        v18 = (*hTrackPoly)->trackList;
        v20 = &v18->obj.klass + v7++;
        v20[4]->_1.namespaze = pVC;
        if (v7 == number)
          break;
        v8 = (*hTrackPoly)->trackList;
        if (v7 >= LODWORD(v8->max_length))
          goto LABEL_6;
      }
    }
  }
}

// 0x154e920
void dds3TrackPolyVCSet4_Acute(dds3TrackPoly_t **hTrackPoly, u32 abgr_in, u32 abgr_out) {
  dds3TrackPoly_t_o *v4;
  s32 point;
  u64 v6;
  struct dds3TrackPolyList_t_array *v7;
  struct System_UInt32_array *pVC;
  u32 v10;
  u32 v11;
  u64 v12;
  s32 v13;
  u32 *v14;
  u32 v15;
  u64 max_length_low;
  u32 v19;
  struct dds3TrackPolyList_t_array *v22;
  u64 i;
  struct dds3TrackPolyList_t_array *trackList;
  s64 number;
  u64 v28;

  v4 = *hTrackPoly;
  number = (*hTrackPoly)->number;
  if ((*hTrackPoly)->number >= 1)
  {
    point = v4->point;
    if (point <= 3)
    {
      for (i = 0; ; ++i)
      {
        trackList = v4->trackList;
        trackList->m_Items[i]->pVC = trackList->m_Items[i]->pVC;
        if (number - 1 == i)
          break;
        v4 = *hTrackPoly;
      }
    }
    else
    {
      v6 = 0;
      v7 = v4->trackList;
      if (!LODWORD(v7->max_length))
      {
LABEL_6:
      }
      while (1)
      {
        pVC = v7->m_Items[v6]->pVC;
        v28 = v6;
        v11 = abgr_out & 0xFF000000;
        v10 = abgr_in & 0xFF000000;
        v12 = 0;
        v13 = 0;
        v14 = &pVC->m_Items[3];
        do
        {
          v10 -= (abgr_in & 0xFF000000) / (point >> 2);
          v15 = v10 & 0xFF000000 | abgr_in & 0xFFFFFF;
          max_length_low = LODWORD(pVC->max_length);
          v11 -= (abgr_out & 0xFF000000) / (point >> 2);
          *(v14 - 1) = v15;
          *(v14 - 2) = v15;
          v19 = v11 & 0xFF000000 | abgr_out & 0xFFFFFF;
          *v14 = v19;
          ++v13;
          *(v14 - 3) = v19;
          v12 += 4LL;
          v14 += 4;
        }
        while (v13 < point >> 2);
        v22 = (*hTrackPoly)->trackList;
        v6 = v28 + 1;
        v22->m_Items[v28]->pVC = pVC;
        if (v28 + 1 == number)
          break;
        v7 = (*hTrackPoly)->trackList;
        if (v6 >= LODWORD(v7->max_length))
          goto LABEL_6;
      }
    }
  }
}

// 0x154eba0
void dds3TrackPolyVCSet4_AcuteW(dds3TrackPoly_t **hTrackPoly, u32 abgr_in, u32 abgr_out) {
  dds3TrackPoly_t_o *v4;
  u32 v5;
  dds3TrackPoly_t_o **v6;
  u64 v7;
  s32 v8;
  struct dds3TrackPolyList_t_array *trackList;
  struct System_UInt32_array *pVC;
  u64 v12;
  s32 v13;
  s32 v14;
  s32 v15;
  u32 *v16;
  u32 *v17;
  u32 *v18;
  u32 v19;
  u64 max_length_low;
  u32 v23;
  u32 v26;
  u32 v27;
  s32 v28;
  u32 v29;
  u32 max_length;
  u32 v33;
  struct dds3TrackPolyList_t_array *v36;
  s64 number;
  s32 point;
  u64 v40;
  u32 v41;
  u32 v42;
  u32 v43;

  v4 = *hTrackPoly;
  number = (*hTrackPoly)->number;
  if ((*hTrackPoly)->number >= 1)
  {
    point = v4->point;
    v43 = (abgr_in & 0xFF000000) / (point >> 3);
    v5 = (abgr_out & 0xFF000000) / (point >> 3);
    v6 = hTrackPoly;
    v7 = 0;
    v8 = point >> 3;
    v42 = abgr_in & 0xFFFFFF;
    v41 = abgr_out & 0xFFFFFF;
    trackList = v4->trackList;
    if (!LODWORD(trackList->max_length))
    {
LABEL_5:
    }
    while (1)
    {
      pVC = trackList->m_Items[v7]->pVC;
      v40 = v7;
      if (point >= 8)
      {
        v12 = 0;
        v13 = 0;
        v14 = 0;
        v15 = 0;
        v16 = &pVC->m_Items[3];
        v17 = &pVC->m_Items[7];
        do
        {
          v18 = v17;
          v19 = v13 & 0xFF000000 | v42;
          max_length_low = LODWORD(pVC->max_length);
          *(v16 - 1) = v19;
          *(v16 - 2) = v19;
          v23 = v14 & 0xFF000000 | v41;
          *v16 = v23;
          ++v15;
          *(v16 - 3) = v23;
          v14 += v5;
          v12 += 4LL;
          v16 += 4;
          v13 += v43;
          v17 = v18 + 4;
        }
        while (v15 < v8);
        v6 = hTrackPoly;
        v27 = abgr_out & 0xFF000000;
        v26 = abgr_in & 0xFF000000;
        v28 = 0;
        do
        {
          v26 -= v43;
          v29 = v26 & 0xFF000000 | v42;
          max_length = pVC->max_length;
          v27 -= v5;
          *(v18 - 1) = v29;
          *(v18 - 2) = v29;
          v33 = v27 & 0xFF000000 | v41;
          *v18 = v33;
          ++v28;
          *(v18 - 3) = v33;
          v12 += 4LL;
          v18 += 4;
        }
        while (v28 < v8);
      }
      v36 = (*v6)->trackList;
      v7 = v40 + 1;
      v36->m_Items[v40]->pVC = pVC;
      if (v40 + 1 == number)
        break;
      trackList = (*v6)->trackList;
      if (v7 >= LODWORD(trackList->max_length))
        goto LABEL_5;
    }
  }
}

// 0x154e6d0
void dds3TrackPolyVCSet4_Normal(dds3TrackPoly_t **hTrackPoly, u32 abgr_in, u32 abgr_out) {
  dds3TrackPoly_t_o *v4;
  s64 number;
  s32 point;
  u64 v7;
  struct dds3TrackPolyList_t_array *v8;
  struct System_UInt32_array *pVC;
  u64 v11;
  s32 v12;
  u32 *v13;
  u64 max_length_low;
  struct dds3TrackPolyList_t_array *v19;
  Il2CppClass **v21;
  u64 v22;
  s64 v23;
  struct dds3TrackPolyList_t_array *trackList;

  v4 = *hTrackPoly;
  number = (*hTrackPoly)->number;
  if (number >= 1)
  {
    point = v4->point;
    if (point <= 3)
    {
      v22 = 0;
      v23 = number - 1;
      while (1)
      {
        trackList = v4->trackList;
        trackList->m_Items[v22]->pVC = trackList->m_Items[v22]->pVC;
        if (v23 == v22)
          break;
        v4 = *hTrackPoly;
        ++v22;
      }
    }
    else
    {
      v7 = 0;
      v8 = v4->trackList;
      if (!LODWORD(v8->max_length))
      {
LABEL_6:
      }
      while (1)
      {
        pVC = v8->m_Items[v7]->pVC;
        v11 = 0;
        v12 = 0;
        v13 = &pVC->m_Items[3];
        do
        {
          max_length_low = LODWORD(pVC->max_length);
          *(v13 - 1) = abgr_in;
          *(v13 - 2) = abgr_in;
          *v13 = abgr_out;
          ++v12;
          *(v13 - 3) = abgr_out;
          v11 += 4LL;
          v13 += 4;
        }
        while (v12 < point >> 2);
        v19 = (*hTrackPoly)->trackList;
        v21 = &v19->obj.klass + v7++;
        v21[4]->_1.namespaze = pVC;
        if (v7 == number)
          break;
        v8 = (*hTrackPoly)->trackList;
        if (v7 >= LODWORD(v8->max_length))
          goto LABEL_6;
      }
    }
  }
}

// 0x154ccd0
void dds3TrackPolyVCSet_Acute(dds3TrackPoly_t **hTrackPoly, u32 abgr_in, u32 abgr_out) {
  s64 number;
  u32 v7;
  f32 v8;
  u64 i;
  struct dds3TrackPolyList_t_array *trackList;
  struct System_UInt32_array *pVC;
  u64 v13;
  u32 v14;
  u32 v16;
  u64 max_length_low;
  char *v18;
  u64 v19;
  struct dds3TrackPolyList_t_array *v21;
  Il2CppClass **v23;
  u64 j;
  struct dds3TrackPolyList_t_array *v25;
  struct System_UInt32_array *v27;
  struct dds3TrackPolyList_t_array *v28;
  Il2CppClass **v30;
  UnityEngine_Vector4_o v31;

  *&v31.x = 0;
  *&v31.z = 0;
  sub_854690(&v31.x, 0.0, 0.0, 0.0, 0.0);
  number = (*hTrackPoly)->number;
  v7 = (*hTrackPoly)->point >> 1;
  SDF_VU0__dds3ColorItoF(abgr_in & 0xFF000000);
  SDF_VU0__COPYVECTOR_A_TO_B();
  SDF_VU0__LOADVECTOR(v31);
  v8 = v7;
  SDF_VU0__INTERPOLATE(1.0 / v8);
  SDF_VU0__COPYVECTOR_A_TO_C();
  if (number)
  {
    if (v7)
    {
      for (i = 0; i != number; ++i)
      {
        trackList = (*hTrackPoly)->trackList;
        pVC = trackList->m_Items[i]->pVC;
        SDF_VU0__dds3ColorItoF(abgr_in);
        v13 = 0;
        v14 = v7;
        do
        {
          SDF_VU0__COPYVECTOR_A_TO_B();
          v16 = SDF_VU0__dds3ColorFtoI(128.0);
          max_length_low = LODWORD(pVC->max_length);
          v18 = pVC + 4 * v13;
          *(v18 + 8) = v16;
          v19 = v13 + 1;
          *(v18 + 9) = v16;
          SDF_VU0__SUBVECTOR_B_C();
          SDF_VU0__COPYVECTOR_B_TO_A();
          --v14;
          v13 = v19 + 1;
        }
        while (v14);
        v21 = (*hTrackPoly)->trackList;
        v23 = &v21->obj.klass + i;
        v23[4]->_1.namespaze = pVC;
      }
    }
    else
    {
      for (j = 0; j != number; ++j)
      {
        v25 = (*hTrackPoly)->trackList;
        v27 = v25->m_Items[j]->pVC;
        SDF_VU0__dds3ColorItoF(abgr_in);
        v28 = (*hTrackPoly)->trackList;
        v30 = &v28->obj.klass + j;
        v30[4]->_1.namespaze = v27;
      }
    }
  }
}

// 0x154cf70
void dds3TrackPolyVCSet_AcuteW(dds3TrackPoly_t **hTrackPoly, u32 abgr_in, u32 abgr_out) {
  s64 number;
  u32 v7;
  f32 v8;
  s64 v9;
  u64 v10;
  s64 v11;
  struct dds3TrackPolyList_t_array *trackList;
  struct System_UInt32_array *pVC;
  u64 v15;
  u32 v17;
  u64 max_length_low;
  char *v19;
  u32 v21;
  u32 max_length;
  s64 v24;
  u32 *v26;
  u32 v27;
  u32 v30;
  u32 v31;
  struct dds3TrackPolyList_t_array *v33;
  Il2CppClass **v35;
  u32 v36;
  UnityEngine_Vector4_o v37;
  u64 point;

  *&v37.x = 0;
  *&v37.z = 0;
  sub_854690(&v37.x, 0.0, 0.0, 0.0, 0.0);
  number = (*hTrackPoly)->number;
  point = (*hTrackPoly)->point;
  v7 = point >> 2;
  v36 = abgr_in;
  SDF_VU0__dds3ColorItoF(abgr_in & 0xFF000000);
  SDF_VU0__COPYVECTOR_A_TO_B();
  SDF_VU0__LOADVECTOR(v37);
  v8 = v7;
  SDF_VU0__INTERPOLATE(1.0 / v8);
  SDF_VU0__COPYVECTOR_A_TO_C();
  if (number)
  {
    v9 = number;
    v10 = 0;
    v11 = (point >> 1) & 0x7FFFFFFE;
    do
    {
      trackList = (*hTrackPoly)->trackList;
      pVC = trackList->m_Items[v10]->pVC;
      SDF_VU0__dds3ColorItoF(v36 & 0xFFFFFF);
      if (v7)
      {
        v15 = 0;
        do
        {
          SDF_VU0__COPYVECTOR_A_TO_B();
          v17 = SDF_VU0__dds3ColorFtoI(128.0);
          max_length_low = LODWORD(pVC->max_length);
          v19 = pVC + 4 * v15;
          *(v19 + 8) = v17;
          *(v19 + 9) = v17;
          SDF_VU0__ADDVECTOR_B_C();
          SDF_VU0__COPYVECTOR_B_TO_A();
          v15 += 2LL;
          v21 = v15;
        }
        while (v11 != v15);
        if ((point & 2) != 0)
        {
LABEL_16:
          max_length = pVC->max_length;
          pVC->m_Items[v21] = v36;
          v24 = v21 | 1;
          v21 += 2;
          pVC->m_Items[v24] = v36;
          if (!v7)
            goto LABEL_29;
LABEL_21:
          v26 = &pVC->m_Items[v21];
          v27 = v7;
          do
          {
            SDF_VU0__COPYVECTOR_A_TO_B();
            v30 = SDF_VU0__dds3ColorFtoI(128.0);
            *v26 = v30;
            v31 = pVC->max_length;
            v26[1] = v30;
            SDF_VU0__SUBVECTOR_B_C();
            SDF_VU0__COPYVECTOR_B_TO_A();
            --v27;
            v21 += 2;
            v26 += 2;
          }
          while (v27);
          goto LABEL_29;
        }
      }
      else
      {
        v21 = 0;
        if ((point & 2) != 0)
          goto LABEL_16;
      }
      if (v7)
        goto LABEL_21;
LABEL_29:
      v33 = (*hTrackPoly)->trackList;
      v35 = &v33->obj.klass + v10++;
      v35[4]->_1.namespaze = pVC;
    }
    while (v10 != v9);
  }
}

// 0x154cb00
void dds3TrackPolyVCSet_Normal(dds3TrackPoly_t **hTrackPoly, u32 abgr_in, u32 abgr_out) {
  dds3TrackPoly_t_o *v4;
  s64 number;
  s32 point;
  u64 v7;
  struct dds3TrackPolyList_t_array *v8;
  struct System_UInt32_array *pVC;
  u64 v11;
  s32 v12;
  u64 max_length_low;
  char *v15;
  u64 v16;
  struct dds3TrackPolyList_t_array *v18;
  Il2CppClass **v20;
  u64 v21;
  s64 v22;
  struct dds3TrackPolyList_t_array *trackList;

  v4 = *hTrackPoly;
  number = (*hTrackPoly)->number;
  if (number >= 1)
  {
    point = v4->point;
    if (point <= 1)
    {
      v21 = 0;
      v22 = number - 1;
      while (1)
      {
        trackList = v4->trackList;
        trackList->m_Items[v21]->pVC = trackList->m_Items[v21]->pVC;
        if (v22 == v21)
          break;
        v4 = *hTrackPoly;
        ++v21;
      }
    }
    else
    {
      v7 = 0;
      v8 = v4->trackList;
      if (!LODWORD(v8->max_length))
      {
LABEL_6:
      }
      while (1)
      {
        pVC = v8->m_Items[v7]->pVC;
        v11 = 0;
        v12 = 0;
        do
        {
          max_length_low = LODWORD(pVC->max_length);
          v15 = pVC + 4 * v11;
          v16 = v11 + 1;
          *(v15 + 8) = abgr_in;
          ++v12;
          v11 = v16 + 1;
          *(v15 + 9) = abgr_out;
        }
        while (v12 < point >> 1);
        v18 = (*hTrackPoly)->trackList;
        v20 = &v18->obj.klass + v7++;
        v20[4]->_1.namespaze = pVC;
        if (v7 == number)
          break;
        v8 = (*hTrackPoly)->trackList;
        if (v7 >= LODWORD(v8->max_length))
          goto LABEL_6;
      }
    }
  }
}

// 0x154fd30
dds3TrianglePoly_t *dds3TrianglePolyCreate(s32 number) {
  dds3TrianglePoly_t_o *v3;
  sdfMat_t_o *v5;

  v3 = Allocate(dds3TrianglePoly_t);
  dds3TrianglePoly_t___ctor(v3);
  v3->number = number;
  v3->pVertex = NewSpecific(UnityEngine_Vector4, (3 * number));
  v3->pVC = NewSpecific(uint, (3 * number));
  v3->abgr = -2139062144;
  v3->hMem = 0;
  v5 = sdfMatNew();
  v3->pMat = v5;
  sdfMatSetConstant(v5, 1.0);
  return v3;
}

// 0x154fe20
void dds3TrianglePolyDelete(dds3TrianglePoly_t **hTriPoly) {
  ;
}

// 0x154fe30
void dds3TrianglePolyLinkOt(sdfGrOt_t **pOt, dds3TrianglePoly_t **hTriPoly) {
  ;
}

// 0x154ab10
void effPkt3DPrimLinkPoly(sdfDrawTag_t *pTag, sdf3DPrimPolyParm_t *pParam) {
  ;
}

// 0x154ba20
void pMeshDelete(dds3TrackPoly_t **hTrackPoly) {
  struct XRD773Unity_CommonMesh_array **p_pMesh;
  struct XRD773Unity_CommonMesh_array *v4;
  u32 max_length;
  s64 v6;
  u64 v7;
  UnityEngine_Object_o *v9;
  struct XRD773Unity_CommonMesh_array *pMesh;
  UnityEngine_Object_o *gameObject;
  struct XRD773Unity_CommonMesh_array *v14;
  s64 v16;

  p_pMesh = &(*hTrackPoly)->pMesh;
  v4 = *p_pMesh;
  if (*p_pMesh)
  {
    if (v4->max_length >= 1)
    {
      max_length = v4->max_length;
      v6 = 4;
      do
      {
        v7 = v6 - 4;
        v9 = *(&v4->obj.klass + v6);
        if (op_Inequality(v9, 0, 0))
        {
          pMesh = (*hTrackPoly)->pMesh;
          gameObject = get_gameObject(*(&pMesh->obj.klass + v6), 0);
          Destroy_27360000(gameObject);
          v14 = (*hTrackPoly)->pMesh;
          *(&v14->obj.klass + v6) = 0;
        }
        v4 = (*hTrackPoly)->pMesh;
        max_length = v4->max_length;
        v16 = v6 - 3;
        ++v6;
      }
      while (v16 < max_length);
      p_pMesh = &(*hTrackPoly)->pMesh;
    }
    *p_pMesh = 0;
  }
}

// 0x154ab00
void sdfSetPacketHeader(sdfGrPacketHeader_t *aHdr, s32 aSize) {
  ;
}

// 0x154b8b0
f32 tpAlfRaitoGet(void) {
  return tp_alf_raito;
}

// 0x154b920
void tpAlfRaitoSet(f32 raito) {
  tp_alf_raito = raito;
}
