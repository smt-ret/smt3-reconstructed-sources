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
}

// 0x1555210
dds3SpPoly_Basic_t *dds3SpPolyCopy(void **hData, s32 bPos) {
    return 0;
}

// 0x15550a0
dds3SpPoly_Basic_t *dds3SpPolyCreate(u16 type, void *pData, s32 bPos) {
    return 0;
}

// 0x1555410
void dds3SpPolyDelete(void **hData) {
}

// 0x1555580
void dds3SpPolyDraw(void **hData) {
}

// 0x1555570
void dds3SpPolyDrawOff(void **hData) {
  ;
}

// 0x1555f40
u8 dds3SpPolyGetLoop(void **hData) {
    return 0;
}

// 0x15559b0
u16 dds3SpPolyGetState(void **hData) {
    return 0;
}

// 0x15556e0
void dds3SpPolyReset(void **hData) {
}

// 0x1555e40
void dds3SpPolySetLoop(void **hData, u8 loop) {
}

// 0x1555aa0
void dds3SpPolySetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1555d50
void dds3SpPolySetRGBA(void **hData, u32 abgr) {
}

// 0x1555bd0
void dds3SpPolySetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__LOADMATRIX_B(0);
    MultMatrixNoArg();
    SDF_VU0__STOREMATRIX(0);
}

// 0x1555840
void dds3SpPolySetScale(void **hData, f32 scale) {
    dds3SpPolyReset(0);
}

// 0x1551a40
u32 dds3SpPoly_Color(u32 frame, u32 frame_end, u32 abgr) {
  f32 v7;
  f32 v8;
  f32 v9;

  if ((byte_3F59C84 & 1) == 0)
  {
    if (frame < frame_end)
    v9 = 1.0;
  }
  if (frame >= frame_end)
  v7 = frame;
  v8 = frame_end;
  v9 = v7 / v8;
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
    dds3SpPoly_Ring_t3__pClone(0, 0);
    dds3SpPoly_Ring_t3__pCopy(0, 0, 0);
    dds3TrackPolyCreate(0, 0, 0, 0);
    dds3TrackPolyVCSet(0, 0, 0, 0);
    dds3SpPoly_RingAllBuffInit(0);
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__STOREMATRIX(0);
    return 0;
}

// 0x15529a0
void dds3SpPoly_RingDelete(void **hData) {
    pMeshDelete(0);
}

// 0x1552c30
void dds3SpPoly_RingDraw(void **hData) {
    dds3SpPoly_RingBuffInit(0, 0);
    dds3SpPoly_Color(0, 0, 0);
    dds3SpPoly_RingMove(0, 0);
    dds3TrackPolyDraw(0, 0);
}

// 0x1552290
void dds3SpPoly_RingMove(dds3SpPoly_Ring_t3 **pRing, s32 number) {
    SDF_VU0__LOADMATRIX(0);
    sdfCos(0);
    sdfSin(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__MULVECTOR();
    SDF_VU0__APPLYMATRIX_B();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__COPYVECTOR_C_TO_A();
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1551e70
void dds3SpPoly_RingNew(dds3SpPoly_Ring_t3 **pRing, s32 number, f32 radius) {
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__LOADVECTOR_C((sdfVector4_t){0});
    sdfCos(0);
    sdfSin(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__MULVECTOR();
    SDF_VU0__ADDVECTOR_A_C();
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1552b10
void dds3SpPoly_RingSetScale(void **hData, f32 scale) {
}

// 0x15503b0
void dds3SpPoly_Ring_Old_BuffInit(void **hData) {
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
              v19 = v13->frame + 1;
            }
          }
          v16->color = 8421504;
          v19 = -16777215;
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
            ++v24->frame;
            v9 = (v9 + 1);
            if (number_low <= v9)
              return;
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
        v4 = *pRing;
      }
    }
  }
}

// 0x1550900
dds3SpPoly_Basic_t *dds3SpPoly_Ring_Old_Create(void *hData, s32 bPos, bool pCopy, s32 billno) {
    dds3SpPoly_Ring_Old_t3__pClone(0, 0);
    dds3SpPoly_Ring_Old_t3__pCopy(0, 0, 0);
    dds3TrackPolyCreate(0, 0, 0, 0);
    dds3TrackPolyVCSet(0, 0, 0, 0);
    dds3SpPoly_Ring_Old_BuffInit(0);
    return 0;
}

// 0x1550b70
void dds3SpPoly_Ring_Old_Delete(void **hData) {
    pMeshDelete(0);
}

// 0x1550de0
void dds3SpPoly_Ring_Old_Draw(void **hData) {
    dds3TrackPolyDrawOff(0);
    dds3SpPoly_Ring_Old_Calc(0);
    dds3TrackPolyDraw(0, 0);
}

// 0x1550190
void dds3SpPoly_Ring_Old_Move(dds3SpPoly_Ring_Old_t3 **pRing, s32 number) {
    SDF_VU0__LOADVECTOR_C((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__COPYVECTOR_C_TO_B();
    SDF_VU0__MULVECTOR();
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(0);
}

// 0x154fe40
void dds3SpPoly_Ring_Old_New(dds3SpPoly_Ring_Old_t3 **pRing, s32 number) {
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    sdfCos(0);
    sdfSin(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__STOREVECTOR_B(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(0);
}

// 0x1550ce0
void dds3SpPoly_Ring_Old_SetScale(void **hData, f32 scale) {
}

// 0x1553f20
void dds3SpPoly_RollRingAllBuffInit(void **hData) {
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
    dds3SpPoly_RollRing_t3__pClone(0, 0);
    dds3SpPoly_RollRing_t3__pCopy(0, 0, 0);
    dds3TrackPolyCreate(0, 0, 0, 0);
    dds3TrackPolyVCSet(0, 0, 0, 0);
    dds3SpPoly_RollRingAllBuffInit(0);
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__STOREMATRIX(0);
    return 0;
}

// 0x1554a40
void dds3SpPoly_RollRingDelete(void **hData) {
    pMeshDelete(0);
}

// 0x1554cb0
void dds3SpPoly_RollRingDraw(void **hData) {
    dds3SpPoly_RollRingBuffInit(0, 0);
    dds3SpPoly_Color(0, 0, 0);
    dds3SpPoly_RollRingMove(0, 0);
    dds3TrackPolyDraw(0, 0);
}

// 0x15542e0
void dds3SpPoly_RollRingMove(dds3SpPoly_RollRing_t3 **pRollRing, s32 number) {
    SetRotateMatrixX(0);
    SetRotateMatrixY_B(0);
    MultMatrixRevNoArg();
    SDF_VU0__LOADMATRIX_B(0);
    SDF_VU0__LOADVECTOR_C((sdfVector4_t){0});
    sdfCos(0);
    sdfSin(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__MULVECTOR();
    SDF_VU0__ADDVECTOR_A_C();
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
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
}

// 0x1552f60
void dds3SpPoly_SphereRingAllBuffInit(void **hData) {
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
    dds3SpPoly_SphereRing_t3__pClone(0, 0);
    dds3SpPoly_SphereRing_t3__pCopy(0, 0, 0);
    dds3TrackPolyCreate(0, 0, 0, 0);
    dds3TrackPolyVCSet(0, 0, 0, 0);
    dds3SpPoly_SphereRingAllBuffInit(0);
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__STOREMATRIX(0);
    return 0;
}

// 0x1553980
void dds3SpPoly_SphereRingDelete(void **hData) {
    pMeshDelete(0);
}

// 0x1553bf0
void dds3SpPoly_SphereRingDraw(void **hData) {
    dds3SpPoly_SphereRingBuffInit(0, 0);
    dds3SpPoly_Color(0, 0, 0);
    dds3SpPoly_SphereRingMove(0, 0);
    dds3TrackPolyDraw(0, 0);
}

// 0x1553210
void dds3SpPoly_SphereRingMove(dds3SpPoly_SphereRing_t3 **pSphereRing, s32 number) {
    sdfSin(0);
    sdfCos(0);
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__LOADVECTOR_C((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__ADDVECTOR_A_C();
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1553af0
void dds3SpPoly_SphereRingSetScale(void **hData, f32 scale) {
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
  *(v14 + 24) = LODWORD(tp_alf_raito);
  tp_alf_raito = 0.0;
  return v14;
}

// 0x154b9a0
void dds3TrackPolyDelete(dds3TrackPoly_t **hTrackPoly) {
    pMeshDelete(0);
}

// 0x1550f10
void dds3TrackPolyDraw(dds3TrackPoly_t **hTrackPoly, char *funcname) {
    GetMesh(0, 0, 0);
    SetAutoHide(0, 0);
    dds3TrackPolyDrawGetParam(0, 0, 0, 0, 0, 0);
    GetPosition(0);
    SetPosition_20241056(0, 0);
    SetColor_20241296(0, 0);
    GetIndexTable(0);
    SetIndexTable(0, 0);
    GetColor(0);
    effGetBlendColor(0);
    effGetVertexColor(0, (sdfColor_t){0});
    SetActive(0, 0);
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
    }
    else  }
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
    }
    else  }
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
      }
    }
  }
}

// 0x154c500
void dds3TrackPolyVCRefresh_ParType1(dds3TrackPoly_t **hTrackPoly, u32 index) {
    SDF_VU0__dds3ColorItoF(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__INTERPOLATE(0);
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__dds3ColorFtoI(0);
    SDF_VU0__SUBVECTOR_B_C();
    SDF_VU0__COPYVECTOR_B_TO_A();
}

// 0x154c760
void dds3TrackPolyVCRefresh_ParType2(dds3TrackPoly_t **hTrackPoly, u32 index) {
    SDF_VU0__dds3ColorItoF(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__INTERPOLATE(0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__dds3ColorFtoI(0);
    SDF_VU0__LOADVECTOR_C((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR_B_C();
    SDF_VU0__STOREVECTOR_B(0);
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
    SDF_VU0__dds3ColorItoF(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__INTERPOLATE(0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__dds3ColorFtoI(0);
    SDF_VU0__LOADVECTOR_C((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR_B_C();
    SDF_VU0__STOREVECTOR_B(0);
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
      }
    }
  }
}

// 0x154ccd0
void dds3TrackPolyVCSet_Acute(dds3TrackPoly_t **hTrackPoly, u32 abgr_in, u32 abgr_out) {
    SDF_VU0__dds3ColorItoF(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__INTERPOLATE(0);
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__dds3ColorFtoI(0);
    SDF_VU0__SUBVECTOR_B_C();
    SDF_VU0__COPYVECTOR_B_TO_A();
}

// 0x154cf70
void dds3TrackPolyVCSet_AcuteW(dds3TrackPoly_t **hTrackPoly, u32 abgr_in, u32 abgr_out) {
    SDF_VU0__dds3ColorItoF(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__INTERPOLATE(0);
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__dds3ColorFtoI(0);
    SDF_VU0__ADDVECTOR_B_C();
    SDF_VU0__COPYVECTOR_B_TO_A();
    SDF_VU0__SUBVECTOR_B_C();
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
