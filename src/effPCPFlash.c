#include "types.h"

typedef struct XRD773Unity_CommonMesh XRD773Unity_CommonMesh;
typedef struct XRD773Unity_GraphicManager XRD773Unity_GraphicManager;
typedef struct XRD773Unity_GraphicManager_CommonObject XRD773Unity_GraphicManager_CommonObject;
typedef struct dds3FlashPolyList_t dds3FlashPolyList_t;
typedef struct dds3HermitianTrackPoly_tag dds3HermitianTrackPoly_tag;
typedef struct effPCPFlashPolyCircleParam_t effPCPFlashPolyCircleParam_t;
typedef struct effPCPFlashPolyCircle_tag effPCPFlashPolyCircle_tag;
typedef struct effPCPFlashPolyPipeParam_t effPCPFlashPolyPipeParam_t;
typedef struct effPCPFlashPolyPipe_tag effPCPFlashPolyPipe_tag;
typedef struct effPCPFlashPolyRingExp2Param_t effPCPFlashPolyRingExp2Param_t;
typedef struct effPCPFlashPolyRingExp2_tag effPCPFlashPolyRingExp2_tag;
typedef struct effPCPFlashPolyRingExpH_tag effPCPFlashPolyRingExpH_tag;
typedef struct effPCPFlashPolyRingExpParam_t effPCPFlashPolyRingExpParam_t;
typedef struct effPCPFlashPolyRingExp_tag effPCPFlashPolyRingExp_tag;
typedef struct effPCPFlashPolyRingParam_t effPCPFlashPolyRingParam_t;
typedef struct effPCPFlashPolyRing_tag effPCPFlashPolyRing_tag;
typedef struct effPCPFlashPolySphere2ExpParam_t effPCPFlashPolySphere2ExpParam_t;
typedef struct effPCPFlashPolySphere2Exp_tag effPCPFlashPolySphere2Exp_tag;
typedef struct effPCPFlashPolySphere2Param_t effPCPFlashPolySphere2Param_t;
typedef struct effPCPFlashPolySphere2_tag effPCPFlashPolySphere2_tag;
typedef struct effPCPFlashPolySphere3Param_t effPCPFlashPolySphere3Param_t;
typedef struct effPCPFlashPolySphere3_tag effPCPFlashPolySphere3_tag;
typedef struct effPCPFlashPolySphereExpParam_t effPCPFlashPolySphereExpParam_t;
typedef struct effPCPFlashPolySphereExp_tag effPCPFlashPolySphereExp_tag;
typedef struct effPCPFlashPolySphereParam_t effPCPFlashPolySphereParam_t;
typedef struct effPCPFlashPolySphere_tag effPCPFlashPolySphere_tag;
typedef struct effPCPFlash_dds3FlashPolyListDrawJob effPCPFlash_dds3FlashPolyListDrawJob;
typedef struct sdfMat_t sdfMat_t;

struct effPCPFlash_dds3FlashPolyListDrawJob {
    sdfMatrix4_t matrix;
    sdfVector4_t blend_col;
    void pos;
    void color;
};

static sdfVector4_t def_dir;
static sdfVector4_t dds3FlashPolyListDrawJobV[UNKNOWN_ARRAY_SIZE];
static u32 dds3FlashPolyListDrawJobVC[UNKNOWN_ARRAY_SIZE];
static effPCPFlash_dds3FlashPolyListDrawJob dds3FlashPolyListDrawJobSingle;
static f32 fp_alf_raito;
static s32 fp_cut_raito;

void *AllocateNativeArray(XRD773Unity_CommonMesh *this, s32 lenght);
s32 **AlocateIndexTable(XRD773Unity_CommonMesh *this, s32 point);
f32 DDS3EFFECT_RAND_F(void);
f32 DDS3EFFECT_RAND_FA(f32 r);
u32 DDS3EFFECT_RAND_I(void);
f32 DDS3EFFECT_RAND_PM(void);
sdfColor_t **GetColor(XRD773Unity_CommonMesh *this);
s32 **GetIndexTable(XRD773Unity_CommonMesh *this);
XRD773Unity_CommonMesh *GetMesh(XRD773Unity_GraphicManager *this, s32 index, bool outlinechk);
sdfVector3_t **GetPosition(XRD773Unity_CommonMesh *this);
void SDF_VU0__APPLYMATRIX_XYZ(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__COPYVECTOR_A_TO_B(void);
void SDF_VU0__COPYVECTOR_A_TO_C(void);
void SDF_VU0__LOADMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__NORMALIZE(void);
void SDF_VU0__OUTERPRODUCT(void);
void SDF_VU0__STOREIDENTITY(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
void SetActive(XRD773Unity_GraphicManager_CommonObject *this, bool act);
void SetAutoHide(XRD773Unity_GraphicManager_CommonObject *this, bool act);
void SetColor(XRD773Unity_CommonMesh *this, void col, s32 length);
void SetColor_20241296(XRD773Unity_CommonMesh *this, sdfColor_t **col);
void SetIndexTable(XRD773Unity_CommonMesh *this, s32 **idx);
void SetPosition(XRD773Unity_CommonMesh *this, void pos, s32 length);
void SetPosition_20241056(XRD773Unity_CommonMesh *this, sdfVector3_t **pos);
void SetRotateMatrixAxis(f32 aAngle, sdfVector4_t aAxis);
u32 dds3EffectPCPDataGetDataOffSet(void *hPCPData, u32 number, s32 bPos);
void *dds3EffectPCPDataGetDataUnity(void *hData, u32 number, s32 type, s32 bPos);
dds3FlashPolyList_t *dds3FlashPolyList2Create(u32 face);
void dds3FlashPolyList2Draw(dds3FlashPolyList_t **hPoly, s32 count);
void dds3FlashPolyList2DrawOff(dds3FlashPolyList_t **hPoly);
dds3FlashPolyList_t *dds3FlashPolyList3Create(u32 face);
void dds3FlashPolyList3Draw(dds3FlashPolyList_t **hPoly, s32 count);
void dds3FlashPolyList3DrawOff(dds3FlashPolyList_t **hPoly);
dds3FlashPolyList_t *dds3FlashPolyListCreate(u32 face);
void dds3FlashPolyListDraw(dds3FlashPolyList_t **hPoly, s32 count, char *idstr);
void dds3FlashPolyListDrawOff(dds3FlashPolyList_t **hPoly);
void dds3FlashPolyListHDelete(dds3FlashPolyList_t *hPoly);
void dds3FlashPolyListHDraw(dds3FlashPolyList_t **hPoly, s32 count);
void dds3FlashPolyListHDrawOff(dds3FlashPolyList_t **hPoly);
void dds3FlashPolyList_t__Clear(dds3FlashPolyList_t *this, s32 vcnt);
bool effBTLSkillCheckRun2(u32 skillid);
u32 effColorBlend(u32 abgr0, u32 abgr1, f32 rate);
u32 effColorMultiply(u32 abgr0, u32 abgr1);
sdfColor_t effGetBlendColor(u32 icol);
effPCPFlashPolyCircle_tag *effPCPFlashPolyCircleCreate(effPCPFlashPolyCircleParam_t *pParam);
void effPCPFlashPolyCircleParam_t__pClone(effPCPFlashPolyCircleParam_t *this, effPCPFlashPolyCircleParam_t **param);
effPCPFlashPolyCircleParam_t **effPCPFlashPolyCircleParam_t__pCopy(effPCPFlashPolyCircleParam_t *this, void *pData, s32 *pos, s32 max);
void effPCPFlashPolyCirclePartSetVC(effPCPFlashPolyCircle_tag **pFlashPoly, s32 number, u32 abgr, s32 vpos);
void effPCPFlashPolyCirclePartSetVertex(effPCPFlashPolyCircle_tag **pFlashPoly, s32 number, sdfVector4_t pLook, s32 vpos);
effPCPFlashPolyPipe_tag *effPCPFlashPolyPipeCreate(effPCPFlashPolyPipeParam_t *pParam, bool fCopy);
void effPCPFlashPolyPipeParam_t__pClone(effPCPFlashPolyPipeParam_t *this, effPCPFlashPolyPipeParam_t **param);
effPCPFlashPolyPipeParam_t **effPCPFlashPolyPipeParam_t__pCopy(effPCPFlashPolyPipeParam_t *this, void *pData, s32 *pos, s32 max);
void effPCPFlashPolyPipePartSetVC(effPCPFlashPolyPipe_tag **pFlashPoly, s32 number, u32 abgr, s32 vpos);
void effPCPFlashPolyPipePartSetVertex(effPCPFlashPolyPipe_tag **pFlashPoly, s32 number, s32 vpos);
effPCPFlashPolyRing_tag *effPCPFlashPolyRingCreate(effPCPFlashPolyRingParam_t *pParam);
effPCPFlashPolyRingExp2_tag *effPCPFlashPolyRingExp2Create(effPCPFlashPolyRingExp2Param_t *pParam);
void effPCPFlashPolyRingExp2Param_t__pClone(effPCPFlashPolyRingExp2Param_t *this, effPCPFlashPolyRingExp2Param_t **param);
effPCPFlashPolyRingExp2Param_t **effPCPFlashPolyRingExp2Param_t__pCopy(effPCPFlashPolyRingExp2Param_t *this, void *pData, s32 *pos, s32 max);
void effPCPFlashPolyRingExp2PartSetVC(effPCPFlashPolyRingExp2_tag **pFlashPoly, s32 number, u32 abgr, s32 vpos);
void effPCPFlashPolyRingExp2PartSetVertex(effPCPFlashPolyRingExp2_tag **pFlashPoly, s32 number, s32 vpos);
effPCPFlashPolyRingExp_tag *effPCPFlashPolyRingExpCreate(effPCPFlashPolyRingExpParam_t *pParam);
effPCPFlashPolyRingExpH_tag *effPCPFlashPolyRingExpHCreate(effPCPFlashPolyRingExpParam_t *pParam);
void effPCPFlashPolyRingExpHPartSetVC(effPCPFlashPolyRingExpH_tag **pFlashPoly, s32 number, u32 abgr, s32 vpos);
void effPCPFlashPolyRingExpHPartSetVertex(effPCPFlashPolyRingExpH_tag **pFlashPoly, s32 number, s32 vpos);
void effPCPFlashPolyRingExpParam_t__pClone(effPCPFlashPolyRingExpParam_t *this, effPCPFlashPolyRingExpParam_t **param);
effPCPFlashPolyRingExpParam_t **effPCPFlashPolyRingExpParam_t__pCopy(effPCPFlashPolyRingExpParam_t *this, void *pData, s32 *pos, s32 max);
void effPCPFlashPolyRingExpPartSetVC(effPCPFlashPolyRingExp_tag **pFlashPoly, s32 number, u32 abgr, s32 vpos);
void effPCPFlashPolyRingExpPartSetVertex(effPCPFlashPolyRingExp_tag **pFlashPoly, s32 number, s32 vpos);
void effPCPFlashPolyRingParam_t__pClone(effPCPFlashPolyRingParam_t *this, effPCPFlashPolyRingParam_t **param);
effPCPFlashPolyRingParam_t **effPCPFlashPolyRingParam_t__pCopy(effPCPFlashPolyRingParam_t *this, void *pData, s32 *pos, s32 max);
void effPCPFlashPolyRingPartSetVC(effPCPFlashPolyRing_tag **pFlashPoly, s32 number, u32 abgr, s32 vpos);
void effPCPFlashPolyRingPartSetVertex(effPCPFlashPolyRing_tag **pFlashPoly, s32 number, s32 vpos);
effPCPFlashPolySphere2_tag *effPCPFlashPolySphere2Create(effPCPFlashPolySphere2Param_t *pParam);
effPCPFlashPolySphere2Exp_tag *effPCPFlashPolySphere2ExpCreate(effPCPFlashPolySphere2ExpParam_t *pParam);
void effPCPFlashPolySphere2ExpParam_t__pClone(effPCPFlashPolySphere2ExpParam_t *this, effPCPFlashPolySphere2ExpParam_t **param);
effPCPFlashPolySphere2ExpParam_t **effPCPFlashPolySphere2ExpParam_t__pCopy(effPCPFlashPolySphere2ExpParam_t *this, void *pData, s32 *pos, s32 max);
void effPCPFlashPolySphere2ExpPartSetVC(effPCPFlashPolySphere2Exp_tag **pFlashPoly, s32 number, u32 abgr, s32 vpos);
void effPCPFlashPolySphere2ExpPartSetVertex(effPCPFlashPolySphere2Exp_tag **pFlashPoly, s32 number, sdfVector4_t pLook, s32 vpos);
void effPCPFlashPolySphere2Param_t__pClone(effPCPFlashPolySphere2Param_t *this, effPCPFlashPolySphere2Param_t **param);
void effPCPFlashPolySphere2PartSetVC(effPCPFlashPolySphere2_tag **pFlashPoly, s32 number, u32 abgr, s32 vpos);
void effPCPFlashPolySphere2PartSetVertex(effPCPFlashPolySphere2_tag **pFlashPoly, s32 number, sdfVector4_t pLook, s32 vpos);
effPCPFlashPolySphere3_tag *effPCPFlashPolySphere3Create(effPCPFlashPolySphere3Param_t *pParam);
void effPCPFlashPolySphere3Param_t__pClone(effPCPFlashPolySphere3Param_t *this, effPCPFlashPolySphere3Param_t **param);
effPCPFlashPolySphere3Param_t **effPCPFlashPolySphere3Param_t__pCopy(effPCPFlashPolySphere3Param_t *this, void *pData, s32 *pos, s32 max);
void effPCPFlashPolySphere3PartInit(effPCPFlashPolySphere3_tag **pFlashPoly, s32 number, sdfVector4_t pLook);
void effPCPFlashPolySphere3PartSetVC(effPCPFlashPolySphere3_tag **pFlashPoly, s32 number, u32 abgr, s32 vpos);
void effPCPFlashPolySphere3PartSetVertex(effPCPFlashPolySphere3_tag **pFlashPoly, s32 number, sdfVector4_t pLook, s32 vpos);
effPCPFlashPolySphere_tag *effPCPFlashPolySphereCreate(void **hData, s32 bPos, bool tbldata);
effPCPFlashPolySphereExp_tag *effPCPFlashPolySphereExpCreate(effPCPFlashPolySphereExpParam_t *pParam);
void effPCPFlashPolySphereExpParam_t__pClone(effPCPFlashPolySphereExpParam_t *this, effPCPFlashPolySphereExpParam_t **param);
effPCPFlashPolySphereExpParam_t **effPCPFlashPolySphereExpParam_t__pCopy(effPCPFlashPolySphereExpParam_t *this, void *pData, s32 *pos, s32 max);
void effPCPFlashPolySphereExpPartInit(effPCPFlashPolySphereExp_tag **pFlashPoly, s32 number, sdfVector4_t pLook);
void effPCPFlashPolySphereExpPartSetVC(effPCPFlashPolySphereExp_tag **pFlashPoly, s32 number, u32 abgr, s32 vpos);
void effPCPFlashPolySphereExpPartSetVertex(effPCPFlashPolySphereExp_tag **pFlashPoly, s32 number, sdfVector4_t pLook, s32 vpos);
void effPCPFlashPolySphereParam_t__pClone(effPCPFlashPolySphereParam_t *this, effPCPFlashPolySphereParam_t **param);
effPCPFlashPolySphereParam_t **effPCPFlashPolySphereParam_t__pCopy(effPCPFlashPolySphereParam_t *this, void *pData, s32 *pos, s32 max);
void effPCPFlashPolySpherePartInit(effPCPFlashPolySphere_tag **pFlashPoly, s32 number, sdfVector4_t pLook);
void effPCPFlashPolySpherePartRotate(effPCPFlashPolySphere_tag **pFlashPoly, s32 number, sdfVector4_t pLook);
void effPCPFlashPolySpherePartSetVC(effPCPFlashPolySphere_tag **pFlashPoly, s32 number, u32 abgr, s32 vpos);
void effPCPFlashPolySpherePartSetVertex(effPCPFlashPolySphere_tag **pFlashPoly, s32 number, sdfVector4_t pLook, s32 vpos);
void pMeshDelete(dds3HermitianTrackPoly_tag **hPoly);
f32 sdfCos(f32 aRadius);
sdfMat_t *sdfMatNew(void);
f32 sdfSin(f32 aRadius);

// 0x1208a90
u32 CutRaitoGet(u32 number, u32 numberO) {
  s32 fp_cut_raito;

  if (number == numberO)
  {
    if (fp_cut_raito)
    {
      return fp_cut_raito * number / 0x64;
    }
  }
  return number;
}

// 0x1157360
void Unity_Jobs_IJobParallelFor_Execute(effPCPFlash_dds3FlashPolyListDrawJob *this, s32 p) {
}

// 0x11f6ff0
dds3FlashPolyList_t *dds3FlashPolyList2Create(u32 face) {
  u64 v3;
  u64 *v4;
  u64 *v6;

  v3 = 3 * face;
  v4 = Allocate(dds3FlashPolyList_t);
  dds3FlashPolyList_t___ctor(v4);
  v4[14] = NewSpecific(UnityEngine_Vector4, v3);
  v4[15] = NewSpecific(uint, v3);
  v4[12] = 0x8080808000000002LL;
  *(v4 + 26) = v3;
  *(v4 + 27) = 1065353216;
  v4[16] = sdfMatNew();
  v6 = Allocate(dds3FlashPolyList_t);
  dds3FlashPolyList_t___ctor(v6);
  dds3FlashPolyList_t__Clear(v6, v3);
  *(v6 + 38) = LODWORD(fp_alf_raito);
  fp_alf_raito = 0.0;
  return v6;
}

// 0x11f71c0
void dds3FlashPolyList2Delete(dds3FlashPolyList_t *hPoly) {
  dds3FlashPolyList_t_o *hPolya;

  hPolya = hPoly;
  pMeshDelete(&hPolya);
}

// 0x11f7350
void dds3FlashPolyList2Draw(dds3FlashPolyList_t **hPoly, s32 count) {
    GetMesh(0, 0, 0);
    SetAutoHide(0, 0);
    AllocateNativeArray(0, 0);
    effGetBlendColor(0);
    AlocateIndexTable(0, 0);
    SetIndexTable(0, 0);
    SetPosition(0, 0, 0);
    SetColor(0, 0, 0);
    SetActive(0, 0);
}

// 0x11f7230
void dds3FlashPolyList2DrawOff(dds3FlashPolyList_t **hPoly) {
  struct XRD773Unity_CommonMesh_array *pMesh;
  il2cpp_array_size_t max_length;
  s64 v5;
  UnityEngine_Object_o *v7;
  struct XRD773Unity_CommonMesh_array *v8;
  s64 v10;

  pMesh = (*hPoly)->pMesh;
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
          v8 = (*hPoly)->pMesh;
          SetActive(*(&v8->obj.klass + v5), 0, 0);
        }
        pMesh = (*hPoly)->pMesh;
        LODWORD(max_length) = pMesh->max_length;
        v10 = v5 - 3;
        ++v5;
      }
      while (v10 < max_length);
    }
  }
}

// 0x11f7ae0
dds3FlashPolyList_t *dds3FlashPolyList3Create(u32 face) {
  u64 v3;
  u64 *v4;
  u64 *v6;

  v3 = 5 * face;
  v4 = Allocate(dds3FlashPolyList_t);
  dds3FlashPolyList_t___ctor(v4);
  v4[14] = NewSpecific(UnityEngine_Vector4, v3);
  v4[15] = NewSpecific(uint, v3);
  v4[12] = 0x8080808000000002LL;
  *(v4 + 26) = v3;
  *(v4 + 27) = 1065353216;
  v4[16] = sdfMatNew();
  v6 = Allocate(dds3FlashPolyList_t);
  dds3FlashPolyList_t___ctor(v6);
  dds3FlashPolyList_t__Clear(v6, v3);
  *(v6 + 38) = LODWORD(fp_alf_raito);
  fp_alf_raito = 0.0;
  return v6;
}

// 0x11f7cb0
void dds3FlashPolyList3Delete(dds3FlashPolyList_t *hPoly) {
  dds3FlashPolyList_t_o *hPolya;

  hPolya = hPoly;
  pMeshDelete(&hPolya);
}

// 0x11f7e40
void dds3FlashPolyList3Draw(dds3FlashPolyList_t **hPoly, s32 count) {
    GetMesh(0, 0, 0);
    SetAutoHide(0, 0);
    AllocateNativeArray(0, 0);
    effGetBlendColor(0);
    AlocateIndexTable(0, 0);
    SetIndexTable(0, 0);
    SetPosition(0, 0, 0);
    SetColor(0, 0, 0);
    SetActive(0, 0);
}

// 0x11f7d20
void dds3FlashPolyList3DrawOff(dds3FlashPolyList_t **hPoly) {
  struct XRD773Unity_CommonMesh_array *pMesh;
  il2cpp_array_size_t max_length;
  s64 v5;
  UnityEngine_Object_o *v7;
  struct XRD773Unity_CommonMesh_array *v8;
  s64 v10;

  pMesh = (*hPoly)->pMesh;
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
          v8 = (*hPoly)->pMesh;
          SetActive(*(&v8->obj.klass + v5), 0, 0);
        }
        pMesh = (*hPoly)->pMesh;
        LODWORD(max_length) = pMesh->max_length;
        v10 = v5 - 3;
        ++v5;
      }
      while (v10 < max_length);
    }
  }
}

// 0x11de980
dds3FlashPolyList_t *dds3FlashPolyListCreate(u32 face) {
  u64 v3;
  u64 *v4;
  u64 *v6;

  v3 = 5 * face;
  v4 = Allocate(dds3FlashPolyList_t);
  dds3FlashPolyList_t___ctor(v4);
  v4[14] = NewSpecific(UnityEngine_Vector4, v3);
  v4[15] = NewSpecific(uint, v3);
  v4[12] = 0x8080808000000002LL;
  *(v4 + 26) = v3;
  *(v4 + 27) = 1065353216;
  v4[16] = sdfMatNew();
  v6 = Allocate(dds3FlashPolyList_t);
  dds3FlashPolyList_t___ctor(v6);
  dds3FlashPolyList_t__Clear(v6, v3);
  *(v6 + 38) = LODWORD(fp_alf_raito);
  fp_alf_raito = 0.0;
  return v6;
}

// 0x11df3c0
void dds3FlashPolyListDelete(dds3FlashPolyList_t *hPoly) {
  dds3FlashPolyList_t_o *hPolya;

  hPolya = hPoly;
  pMeshDelete(&hPolya);
}

// 0x11e0a30
void dds3FlashPolyListDraw(dds3FlashPolyList_t **hPoly, s32 count, char *idstr) {
    effBTLSkillCheckRun2(0);
    GetMesh(0, 0, 0);
    SetAutoHide(0, 0);
    AllocateNativeArray(0, 0);
    effGetBlendColor(0);
    AlocateIndexTable(0, 0);
    SetIndexTable(0, 0);
    SetPosition(0, 0, 0);
    SetColor(0, 0, 0);
    SetActive(0, 0);
}

// 0x11f6e90
void dds3FlashPolyListDrawOff(dds3FlashPolyList_t **hPoly) {
  struct XRD773Unity_CommonMesh_array *pMesh;
  il2cpp_array_size_t max_length;
  s64 v5;
  u64 v6;
  UnityEngine_Object_o *v8;
  struct XRD773Unity_CommonMesh_array *v9;
  UnityEngine_GameObject_o *gameObject;
  struct XRD773Unity_CommonMesh_array *v12;
  UnityEngine_GameObject_o *v14;
  s64 v15;

  pMesh = (*hPoly)->pMesh;
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
          v9 = (*hPoly)->pMesh;
          gameObject = get_gameObject(*(&v9->obj.klass + v5), 0);
          if (get_activeSelf(gameObject))
          {
            v12 = (*hPoly)->pMesh;
            v14 = get_gameObject(*(&v12->obj.klass + v5), 0);
            SetActive(v14, 0, 0);
          }
        }
        pMesh = (*hPoly)->pMesh;
        LODWORD(max_length) = pMesh->max_length;
        v15 = v5 - 3;
        ++v5;
      }
      while (v15 < max_length);
    }
  }
}

// 0x11f8740
dds3FlashPolyList_t *dds3FlashPolyListHCreate(u32 face) {
  dds3FlashPolyList_t_o *v3;

  v3 = dds3FlashPolyListCreate(face);
  SDF_VU0__STOREIDENTITY(&v3->matrix);
  return v3;
}

// 0x11f87c0
void dds3FlashPolyListHDelete(dds3FlashPolyList_t *hPoly) {
  dds3FlashPolyList_t_o *v4;
  dds3FlashPolyList_t_o *hPolya;

  v4 = hPoly;
  pMeshDelete(&v4);
  hPolya = hPoly;
  pMeshDelete(&hPolya);
}

// 0x11f89a0
void dds3FlashPolyListHDraw(dds3FlashPolyList_t **hPoly, s32 count) {
    GetMesh(0, 0, 0);
    SetPosition_20241056(0, 0);
    SetColor_20241296(0, 0);
    SetIndexTable(0, 0);
    SetAutoHide(0, 0);
    effGetBlendColor(0);
    GetIndexTable(0);
    GetPosition(0);
    GetColor(0);
    SetActive(0, 0);
}

// 0x11f8880
void dds3FlashPolyListHDrawOff(dds3FlashPolyList_t **hPoly) {
  struct XRD773Unity_CommonMesh_array *pMesh;
  il2cpp_array_size_t max_length;
  s64 v5;
  UnityEngine_Object_o *v7;
  struct XRD773Unity_CommonMesh_array *v8;
  s64 v10;

  pMesh = (*hPoly)->pMesh;
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
          v8 = (*hPoly)->pMesh;
          SetActive(*(&v8->obj.klass + v5), 0, 0);
        }
        pMesh = (*hPoly)->pMesh;
        LODWORD(max_length) = pMesh->max_length;
        v10 = v5 - 3;
        ++v5;
      }
      while (v10 < max_length);
    }
  }
}

// 0x1208990
void dds3FlashPolyListHSetABGR(dds3FlashPolyList_t **hPoly, u32 abgr) {
  (*hPoly)->abgr = abgr;
}

// 0x1208980
void dds3FlashPolyListHSetBlend(dds3FlashPolyList_t **hPoly, u32 blend) {
  (*hPoly)->blend = blend;
}

// 0x12089a0
void dds3FlashPolyListHSetScale(dds3FlashPolyList_t **hPoly, f32 scale) {
  (*hPoly)->scale = scale;
}

// 0x11e0a20
void dds3FlashPolyListSetABGR(dds3FlashPolyList_t **hPoly, u32 abgr) {
  (*hPoly)->abgr = abgr;
}

// 0x11deb50
void dds3FlashPolyListSetBlend(dds3FlashPolyList_t **hPoly, u32 blend) {
  (*hPoly)->blend = blend;
}

// 0x1208970
void dds3FlashPolyListSetScale(dds3FlashPolyList_t **hPoly, f32 scale) {
  (*hPoly)->scale = scale;
}

// 0x1206120
effPCPFlashPolyCircle_tag *effPCPFlashPolyCircleCopy(void **hData, s32 bPos, bool tbldata) {
    effPCPFlashPolyCircleCreate(0);
    return 0;
}

// 0x1205e20
effPCPFlashPolyCircle_tag *effPCPFlashPolyCircleCreate(effPCPFlashPolyCircleParam_t *pParam) {
  u64 *v3;
  u64 *v4;
  u32 v6;
  dds3FlashPolyList_t_o *v7;
  u64 v8;
  s64 v9;
  u32 *v11;
  u64 v12;
  u64 *v13;
  u64 v15;
  u64 v17;

  v3 = Allocate(effPCPFlashPolyCircle_tag);
  _ctor(v3, 0);
  v4 = Allocate(effPCPFlashPolyCircleParam_t);
  effPCPFlashPolyCircleParam_t___ctor(v4);
  v3[2] = v4;
  effPCPFlashPolyCircleParam_t__pClone(pParam, v3 + 2);
  v3[3] = NewSpecific(effPCPFlashPolyCirclePart_tag, pParam->number);
  v3[4] = 0x8080808000000000LL;
  *(v3 + 10) = 1065353216;
  v6 = *(v3[2] + 32);
  v7 = dds3FlashPolyList2Create(v6);
  v8 = v3[2];
  v3[6] = v7;
  v7->blend = *(v8 + 76);
  if (*(v3[2] + 32))
  {
    v9 = 4;
    do
    {
      v11 = v3[3];
      v12 = v9 - 4;
      v13 = Allocate(effPCPFlashPolyCirclePart_tag);
      _ctor(v13, 0);
      *&v11[2 * v9] = v13;
      v15 = v3[3];
      *(*(v15 + 8 * v9) + 20LL) = 0;
      v17 = v9 - 3;
      ++v9;
    }
    while (v17 < *(v3[2] + 32));
  }
  return v3;
}

// 0x1205d00
effPCPFlashPolyCircle_tag *effPCPFlashPolyCircleCreateP(void **pData, s32 bPos, bool tbldata) {
    effPCPFlashPolyCircleCreate(0);
    return 0;
}

// 0x1206010
effPCPFlashPolyCircle_tag *effPCPFlashPolyCircleCreatePCF(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v6;
  u64 *v7;
  effPCPFlashPolyCircleParam_t_array *v9;
  effPCPFlashPolyCircleParam_t_o *v11;
  s32 pos;

  pos = 0;
  v6 = *hData;
  pos = dds3EffectPCPDataGetDataOffSet(v6, 0, bPos);
  v7 = Allocate(effPCPFlashPolyCircleParam_t);
  effPCPFlashPolyCircleParam_t___ctor(v7);
  v9 = effPCPFlashPolyCircleParam_t__pCopy(v7, *hData, &pos, 1);
  v11 = v9->m_Items[0];
  return effPCPFlashPolyCircleCreate(v11);
}

// 0x1206230
void effPCPFlashPolyCircleDelete(void **hData) {
    pMeshDelete(0);
}

// 0x1206c40
void effPCPFlashPolyCircleDraw(void **hData) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    effPCPFlashPolyCirclePartSetVertex(0, 0, (sdfVector4_t){0}, 0);
    effColorBlend(0, 0, 0);
    effColorMultiply(0, 0);
    effPCPFlashPolyCirclePartSetVC(0, 0, 0, 0);
    dds3FlashPolyList2Draw(0, 0);
}

// 0x1206b20
void effPCPFlashPolyCircleDrawOff(void **hData) {
    dds3FlashPolyList2DrawOff(0);
}

// 0x1206690
void effPCPFlashPolyCirclePartSetVC(effPCPFlashPolyCircle_tag **pFlashPoly, s32 number, u32 abgr, s32 vpos) {
  struct effPCPFlashPolyCircleParam_t_o *param;
  u32 abgr_in;
  struct System_UInt32_array *pVC;
  u32 v8;
  u32 v11;
  u32 v13;
  u32 v15;

  param = (*pFlashPoly)->param;
  abgr_in = param->abgr_in;
  pVC = (*pFlashPoly)->hPoly->pVC;
  v8 = param->abgr_out & 0xFFFFFF;
  v11 = effColorMultiply(v8, abgr);
  pVC->m_Items[vpos] = v11;
  v13 = effColorMultiply(v8, abgr);
  pVC->m_Items[vpos + 1] = v13;
  v15 = effColorMultiply(abgr_in | 0xFF000000, abgr);
  pVC->m_Items[vpos + 2] = v15;
}

// 0x12067a0
void effPCPFlashPolyCirclePartSetVertex(effPCPFlashPolyCircle_tag **pFlashPoly, s32 number, sdfVector4_t pLook, s32 vpos) {
    SetRotateMatrixAxis(0, (sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__OUTERPRODUCT();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__APPLYMATRIX_XYZ();
}

// 0x12064b0
void effPCPFlashPolyCircleSetColor(void **hData, u32 abgr) {
}

// 0x1206390
void effPCPFlashPolyCircleSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x12065a0
void effPCPFlashPolyCircleSetScale(void **hData, f32 scale) {
}

// 0x11fdb00
effPCPFlashPolyPipe_tag *effPCPFlashPolyPipeCopy(void **hData, s32 bPos, bool tbldata) {
    effPCPFlashPolyPipeCreate(0, 0);
    return 0;
}

// 0x11fd750
effPCPFlashPolyPipe_tag *effPCPFlashPolyPipeCreate(effPCPFlashPolyPipeParam_t *pParam, bool fCopy) {
  u64 *v4;
  u64 *v5;
  u64 *v6;
  u64 v8;
  u32 v9;
  dds3FlashPolyList_t_o *v10;
  u64 v11;
  u32 v12;
  f32 v13;
  f32 v14;
  u32 v15;
  f32 v16;
  s64 v17;
  u32 *v19;
  u64 v20;
  u64 *v21;
  u64 v24;
  s64 v26;
  u32 v27;
  u64 v28;
  u64 v30;

  v4 = Allocate(effPCPFlashPolyPipe_tag);
  _ctor(v4, 0);
  v5 = Allocate(effPCPFlashPolyPipeParam_t);
  effPCPFlashPolyPipeParam_t___ctor(v5);
  v6 = v4 + 2;
  v4[2] = v5;
  effPCPFlashPolyPipeParam_t__pClone(pParam, v4 + 2);
  v4[3] = NewSpecific(effPCPFlashPolyPipePart_tag, pParam->number);
  v4[4] = 0x8080808000000000LL;
  *(v4 + 10) = 1065353216;
  v8 = v4[2];
  if (!*(v8 + 44))
  {
    *(v8 + 44) = 1;
    v8 = *v6;
  }
  v9 = *(v8 + 32);
  v10 = dds3FlashPolyList3Create(v9);
  v4[6] = v10;
  v10->scale = 1.0;
  *(v4[6] + 96) = *(v4[2] + 92);
  v11 = v4[2];
  v12 = *(v11 + 32);
  if (v12)
  {
    v13 = v12;
    v14 = 6.2832 / v13;
    v15 = *(v11 + 44);
    v16 = -1.5708;
    v17 = 4;
    do
    {
      v19 = v4[3];
      v20 = v17 - 4;
      v21 = Allocate(effPCPFlashPolyPipePart_tag);
      _ctor(v21, 0);
      *&v19[2 * v17] = v21;
      v24 = v4[3];
      v26 = *(v24 + 8 * v17);
      v27 = DDS3EFFECT_RAND_I();
      *(v26 + 20) = v27 / v15 * v15 - v27;
      v28 = v4[3];
      *(*(v28 + 8 * v17) + 40LL) = v16;
      v16 = v14 + v16;
      v30 = v17 - 3;
      ++v17;
    }
    while (v30 < *(*v6 + 32));
  }
  return v4;
}

// 0x11fd630
effPCPFlashPolyPipe_tag *effPCPFlashPolyPipeCreateP(void **pData, s32 bPos, bool tbldata) {
    effPCPFlashPolyPipeCreate(0, 0);
    return 0;
}

// 0x11fd9f0
effPCPFlashPolyPipe_tag *effPCPFlashPolyPipeCreatePCF(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v6;
  u64 *v7;
  effPCPFlashPolyPipeParam_t_array *v10;
  effPCPFlashPolyPipeParam_t_o *v12;
  s32 pos;

  pos = 0;
  v6 = *hData;
  pos = dds3EffectPCPDataGetDataOffSet(v6, 0, bPos);
  v7 = Allocate(effPCPFlashPolyPipeParam_t);
  effPCPFlashPolyPipeParam_t___ctor(v7);
  v10 = effPCPFlashPolyPipeParam_t__pCopy(v7, *hData, &pos, 1);
  v12 = v10->m_Items[0];
  return effPCPFlashPolyPipeCreate(v12, 0);
}

// 0x11fdc10
void effPCPFlashPolyPipeDelete(void **hData) {
    pMeshDelete(0);
}

// 0x11fe860
void effPCPFlashPolyPipeDraw(void **hData) {
    DDS3EFFECT_RAND_I();
    effPCPFlashPolyPipePartSetVertex(0, 0, 0);
    effColorBlend(0, 0, 0);
    effColorMultiply(0, 0);
    effPCPFlashPolyPipePartSetVC(0, 0, 0, 0);
    DDS3EFFECT_RAND_F();
    dds3FlashPolyList3Draw(0, 0);
}

// 0x11fe740
void effPCPFlashPolyPipeDrawOff(void **hData) {
    dds3FlashPolyList3DrawOff(0);
}

// 0x11fe6d0
void effPCPFlashPolyPipePartRotate(effPCPFlashPolyPipe_tag **pFlashPoly, s32 number) {
  struct effPCPFlashPolyPipePart_tag_array *pPart;
  effPCPFlashPolyPipePart_tag_o *v5;

  pPart = (*pFlashPoly)->pPart;
  v5 = pPart->m_Items[number];
  v5->rotate = v5->rotate + (*pFlashPoly)->param->rotate;
}

// 0x11fe070
void effPCPFlashPolyPipePartSetVC(effPCPFlashPolyPipe_tag **pFlashPoly, s32 number, u32 abgr, s32 vpos) {
  struct effPCPFlashPolyPipeParam_t_o *param;
  u32 abgr_in;
  struct System_UInt32_array *pVC;
  u32 v10;
  u32 v11;
  s32 v13;
  char *v14;
  u32 *v15;
  u32 v16;
  u32 v18;
  u32 v20;
  u32 max_length;

  param = (*pFlashPoly)->param;
  abgr_in = param->abgr_in;
  pVC = (*pFlashPoly)->hPoly->pVC;
  v10 = param->abgr_out & 0xFFFFFF;
  v11 = effColorMultiply(v10 | 0x80000000, abgr);
  v13 = abgr_in & 0xFFFFFF;
  v14 = pVC + 4 * vpos;
  *(v14 + 8) = v11;
  v15 = (v14 + 32);
  v16 = effColorMultiply(v10, abgr);
  pVC->m_Items[vpos + 1] = v16;
  v18 = effColorMultiply(v13 | 0x80000000, abgr);
  pVC->m_Items[vpos + 2] = v18;
  v20 = effColorMultiply(v10, abgr);
  pVC->m_Items[vpos + 3] = v20;
  max_length = pVC->max_length;
  pVC->m_Items[vpos + 4] = *v15;
}

// 0x11fe210
void effPCPFlashPolyPipePartSetVertex(effPCPFlashPolyPipe_tag **pFlashPoly, s32 number, s32 vpos) {
    sdfCos(0);
    sdfSin(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__OUTERPRODUCT();
}

// 0x11fde90
void effPCPFlashPolyPipeSetColor(void **hData, u32 abgr) {
}

// 0x11fdd70
void effPCPFlashPolyPipeSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x11fdf80
void effPCPFlashPolyPipeSetScale(void **hData, f32 scale) {
}

// 0x11fc410
effPCPFlashPolyRing_tag *effPCPFlashPolyRingCopy(void **hData, s32 bPos, bool tbldata) {
    effPCPFlashPolyRingCreate(0);
    return 0;
}

// 0x11fc060
effPCPFlashPolyRing_tag *effPCPFlashPolyRingCreate(effPCPFlashPolyRingParam_t *pParam) {
  u64 *v3;
  u64 *v4;
  u64 *v5;
  u64 v7;
  u32 v8;
  dds3FlashPolyList_t_o *v9;
  u64 v10;
  u32 v11;
  f32 v12;
  f32 v13;
  u32 v14;
  f32 v15;
  s64 v16;
  u32 *v18;
  u64 v19;
  u64 *v20;
  u64 v23;
  s64 v25;
  u32 v26;
  u64 v27;
  u64 v29;

  v3 = Allocate(effPCPFlashPolyRing_tag);
  _ctor(v3, 0);
  v4 = Allocate(effPCPFlashPolyRingParam_t);
  effPCPFlashPolyRingParam_t___ctor(v4);
  v5 = v3 + 2;
  v3[2] = v4;
  effPCPFlashPolyRingParam_t__pClone(pParam, v3 + 2);
  v3[3] = NewSpecific(effPCPFlashPolyRingPart_tag, pParam->number);
  v3[4] = 0x8080808000000000LL;
  *(v3 + 10) = 1065353216;
  v7 = v3[2];
  if (!*(v7 + 48))
  {
    *(v7 + 48) = 1;
    v7 = *v5;
  }
  v8 = *(v7 + 32);
  v9 = dds3FlashPolyListCreate(v8);
  v3[6] = v9;
  v9->scale = 1.0;
  *(v3[6] + 96) = *(v3[2] + 84);
  v10 = v3[2];
  v11 = *(v10 + 32);
  if (v11)
  {
    v12 = v11;
    v13 = 6.2832 / v12;
    v14 = *(v10 + 48);
    v15 = -1.5708;
    v16 = 4;
    do
    {
      v18 = v3[3];
      v19 = v16 - 4;
      v20 = Allocate(effPCPFlashPolyRingPart_tag);
      _ctor(v20, 0);
      *&v18[2 * v16] = v20;
      v23 = v3[3];
      v25 = *(v23 + 8 * v16);
      v26 = DDS3EFFECT_RAND_I();
      *(v25 + 20) = v26 / v14 * v14 - v26;
      v27 = v3[3];
      *(*(v27 + 8 * v16) + 32LL) = v15;
      v15 = v13 + v15;
      v29 = v16 - 3;
      ++v16;
    }
    while (v29 < *(*v5 + 32));
  }
  return v3;
}

// 0x11fbf40
effPCPFlashPolyRing_tag *effPCPFlashPolyRingCreateP(void **pData, s32 bPos, bool tbldata) {
    effPCPFlashPolyRingCreate(0);
    return 0;
}

// 0x11fc300
effPCPFlashPolyRing_tag *effPCPFlashPolyRingCreatePCF(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v6;
  u64 *v7;
  effPCPFlashPolyRingParam_t_array *v9;
  effPCPFlashPolyRingParam_t_o *v11;
  s32 pos;

  pos = 0;
  v6 = *hData;
  pos = dds3EffectPCPDataGetDataOffSet(v6, 0, bPos);
  v7 = Allocate(effPCPFlashPolyRingParam_t);
  effPCPFlashPolyRingParam_t___ctor(v7);
  v9 = effPCPFlashPolyRingParam_t__pCopy(v7, *hData, &pos, 1);
  v11 = v9->m_Items[0];
  return effPCPFlashPolyRingCreate(v11);
}

// 0x11fc520
void effPCPFlashPolyRingDelete(void **hData) {
    pMeshDelete(0);
}

// 0x11fd1c0
void effPCPFlashPolyRingDraw(void **hData) {
    DDS3EFFECT_RAND_I();
    effPCPFlashPolyRingPartSetVertex(0, 0, 0);
    effBTLSkillCheckRun2(0);
    effColorBlend(0, 0, 0);
    effColorMultiply(0, 0);
    effPCPFlashPolyRingPartSetVC(0, 0, 0, 0);
    dds3FlashPolyListDraw(0, 0, 0);
}

// 0x11fd0a0
void effPCPFlashPolyRingDrawOff(void **hData) {
    dds3FlashPolyListDrawOff(0);
}

// 0x1204ae0
effPCPFlashPolyRingExp2_tag *effPCPFlashPolyRingExp2Copy(void **hData, s32 bPos, bool tbldata) {
    effPCPFlashPolyRingExp2Create(0);
    return 0;
}

// 0x1204730
effPCPFlashPolyRingExp2_tag *effPCPFlashPolyRingExp2Create(effPCPFlashPolyRingExp2Param_t *pParam) {
  u64 *v3;
  u64 *v4;
  u64 *v5;
  u64 v7;
  u32 v8;
  dds3FlashPolyList_t_o *v9;
  u64 v10;
  u32 v11;
  f32 v12;
  f32 v13;
  u32 v14;
  f32 v15;
  s64 v16;
  u32 *v18;
  u64 v19;
  u64 *v20;
  u64 v23;
  s64 v25;
  u32 v26;
  u64 v27;
  u64 v29;

  v3 = Allocate(effPCPFlashPolyRingExp2_tag);
  _ctor(v3, 0);
  v4 = Allocate(effPCPFlashPolyRingExp2Param_t);
  effPCPFlashPolyRingExp2Param_t___ctor(v4);
  v5 = v3 + 2;
  v3[2] = v4;
  effPCPFlashPolyRingExp2Param_t__pClone(pParam, v3 + 2);
  v3[3] = NewSpecific(effPCPFlashPolyRingExp2Part_tag, pParam->number);
  v3[4] = 0x8080808000000000LL;
  *(v3 + 10) = 1065353216;
  v7 = v3[2];
  if (!*(v7 + 48))
  {
    *(v7 + 48) = 1;
    v7 = *v5;
  }
  v8 = *(v7 + 32);
  v9 = dds3FlashPolyListCreate(v8);
  v3[6] = v9;
  v9->scale = 1.0;
  *(v3[6] + 96) = *(v3[2] + 92);
  v10 = v3[2];
  v11 = *(v10 + 32);
  if (v11)
  {
    v12 = v11;
    v13 = 6.2832 / v12;
    v14 = *(v10 + 48);
    v15 = -1.5708;
    v16 = 4;
    do
    {
      v18 = v3[3];
      v19 = v16 - 4;
      v20 = Allocate(effPCPFlashPolyRingExp2Part_tag);
      _ctor(v20, 0);
      *&v18[2 * v16] = v20;
      v23 = v3[3];
      v25 = *(v23 + 8 * v16);
      v26 = DDS3EFFECT_RAND_I();
      *(v25 + 20) = v26 / v14 * v14 - v26;
      v27 = v3[3];
      *(*(v27 + 8 * v16) + 32LL) = v15;
      v15 = v13 + v15;
      v29 = v16 - 3;
      ++v16;
    }
    while (v29 < *(*v5 + 32));
  }
  return v3;
}

// 0x1204610
effPCPFlashPolyRingExp2_tag *effPCPFlashPolyRingExp2CreateP(void **pData, s32 bPos, bool tbldata) {
    effPCPFlashPolyRingExp2Create(0);
    return 0;
}

// 0x12049d0
effPCPFlashPolyRingExp2_tag *effPCPFlashPolyRingExp2CreatePCF(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v6;
  u64 *v7;
  effPCPFlashPolyRingExp2Param_t_array *v9;
  effPCPFlashPolyRingExp2Param_t_o *v11;
  s32 pos;

  pos = 0;
  v6 = *hData;
  pos = dds3EffectPCPDataGetDataOffSet(v6, 0, bPos);
  v7 = Allocate(effPCPFlashPolyRingExp2Param_t);
  effPCPFlashPolyRingExp2Param_t___ctor(v7);
  v9 = effPCPFlashPolyRingExp2Param_t__pCopy(v7, *hData, &pos, 1);
  v11 = v9->m_Items[0];
  return effPCPFlashPolyRingExp2Create(v11);
}

// 0x1204bf0
void effPCPFlashPolyRingExp2Delete(void **hData) {
    pMeshDelete(0);
}

// 0x1205890
void effPCPFlashPolyRingExp2Draw(void **hData) {
    DDS3EFFECT_RAND_I();
    effPCPFlashPolyRingExp2PartSetVertex(0, 0, 0);
    effColorBlend(0, 0, 0);
    effColorMultiply(0, 0);
    effPCPFlashPolyRingExp2PartSetVC(0, 0, 0, 0);
    dds3FlashPolyListDraw(0, 0, 0);
}

// 0x1205770
void effPCPFlashPolyRingExp2DrawOff(void **hData) {
    dds3FlashPolyListDrawOff(0);
}

// 0x1205700
void effPCPFlashPolyRingExp2PartRotate(effPCPFlashPolyRingExp2_tag **pFlashPoly, s32 number) {
  struct effPCPFlashPolyRingExp2Part_tag_array *pPart;
  effPCPFlashPolyRingExp2Part_tag_o *v5;

  pPart = (*pFlashPoly)->pPart;
  v5 = pPart->m_Items[number];
  v5->rotate = v5->rotate + (*pFlashPoly)->param->rotate;
}

// 0x1205050
void effPCPFlashPolyRingExp2PartSetVC(effPCPFlashPolyRingExp2_tag **pFlashPoly, s32 number, u32 abgr, s32 vpos) {
  struct effPCPFlashPolyRingExp2Param_t_o *param;
  u32 abgr_in;
  struct System_UInt32_array *pVC;
  u32 v8;
  char v10;
  u32 v12;
  u32 v14;
  u32 v16;
  u32 v18;
  u32 v20;
  u32 v21;
  u32 v23;
  u32 v25;

  param = (*pFlashPoly)->param;
  abgr_in = param->abgr_in;
  pVC = (*pFlashPoly)->hPoly->pVC;
  v8 = param->abgr_out & 0xFFFFFF;
  v10 = number;
  v12 = effColorMultiply(v8, abgr);
  pVC->m_Items[vpos] = v12;
  v14 = effColorMultiply(v8, abgr);
  pVC->m_Items[vpos + 1] = v14;
  if ((v10 & 1) != 0)
  {
    v21 = effColorMultiply(0x80000000, abgr);
    pVC->m_Items[vpos + 2] = v21;
    v23 = effColorMultiply(abgr_in | 0xFF000000, abgr);
    pVC->m_Items[vpos + 3] = v23;
    v20 = 0x80000000;
  }
  else
  {
    v16 = effColorMultiply(0xFF000000, abgr);
    pVC->m_Items[vpos + 2] = v16;
    v18 = effColorMultiply(abgr_in & 0xFFFFFF | 0x40000000, abgr);
    v20 = -16777216;
    pVC->m_Items[vpos + 3] = v18;
  }
  v25 = effColorMultiply(v20, abgr);
  pVC->m_Items[vpos + 4] = v25;
}

// 0x1205260
void effPCPFlashPolyRingExp2PartSetVertex(effPCPFlashPolyRingExp2_tag **pFlashPoly, s32 number, s32 vpos) {
    sdfCos(0);
    sdfSin(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__OUTERPRODUCT();
}

// 0x1204e70
void effPCPFlashPolyRingExp2SetColor(void **hData, u32 abgr) {
}

// 0x1204d50
void effPCPFlashPolyRingExp2SetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1204f60
void effPCPFlashPolyRingExp2SetScale(void **hData, f32 scale) {
}

// 0x11ff1d0
effPCPFlashPolyRingExp_tag *effPCPFlashPolyRingExpCopy(void **hData, s32 bPos, bool tbldata) {
    effPCPFlashPolyRingExpCreate(0);
    return 0;
}

// 0x11fee10
effPCPFlashPolyRingExp_tag *effPCPFlashPolyRingExpCreate(effPCPFlashPolyRingExpParam_t *pParam) {
  u64 *v3;
  u64 *v4;
  u64 *v5;
  u32 *v7;
  u32 v8;
  dds3FlashPolyList_t_o *v9;
  u64 v10;
  u32 v11;
  f32 v12;
  f32 v13;
  u32 v14;
  f32 v15;
  s64 v16;
  u32 *v18;
  u64 v19;
  u64 *v20;
  u64 v23;
  s64 v25;
  u32 v26;
  u64 v27;
  u64 v29;

  v3 = Allocate(effPCPFlashPolyRingExp_tag);
  _ctor(v3, 0);
  v4 = Allocate(effPCPFlashPolyRingExpParam_t);
  effPCPFlashPolyRingExpParam_t___ctor(v4);
  v5 = v3 + 2;
  v3[2] = v4;
  effPCPFlashPolyRingExpParam_t__pClone(pParam, v3 + 2);
  v3[3] = NewSpecific(effPCPFlashPolyRingExpPart_tag, pParam->number);
  v3[4] = 0x8080808000000000LL;
  *(v3 + 10) = 1065353216;
  v7 = v3[2];
  *(v3 + 11) = v7[18];
  *(v3 + 13) = v7[16];
  *(v3 + 14) = v7[17];
  if (!v7[11])
  {
    v7[11] = 1;
    v7 = *v5;
  }
  v8 = v7[8];
  v9 = dds3FlashPolyListCreate(v8);
  v3[8] = v9;
  v9->scale = 1.0;
  *(v3[8] + 96) = *(v3[2] + 100);
  v10 = v3[2];
  v11 = *(v10 + 32);
  if (v11)
  {
    v12 = v11;
    v13 = 6.2832 / v12;
    v14 = *(v10 + 44);
    v15 = -1.5708;
    v16 = 4;
    do
    {
      v18 = v3[3];
      v19 = v16 - 4;
      v20 = Allocate(effPCPFlashPolyRingExpPart_tag);
      _ctor(v20, 0);
      *&v18[2 * v16] = v20;
      v23 = v3[3];
      v25 = *(v23 + 8 * v16);
      v26 = DDS3EFFECT_RAND_I();
      *(v25 + 20) = v26 / v14 * v14 - v26;
      v27 = v3[3];
      *(*(v27 + 8 * v16) + 24LL) = v15;
      v15 = v13 + v15;
      v29 = v16 - 3;
      ++v16;
    }
    while (v29 < *(*v5 + 32));
  }
  return v3;
}

// 0x11fecf0
effPCPFlashPolyRingExp_tag *effPCPFlashPolyRingExpCreateP(void **pData, s32 bPos, bool tbldata) {
    effPCPFlashPolyRingExpCreate(0);
    return 0;
}

// 0x11ff0c0
effPCPFlashPolyRingExp_tag *effPCPFlashPolyRingExpCreatePCF(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v6;
  u64 *v7;
  effPCPFlashPolyRingExpParam_t_array *v9;
  effPCPFlashPolyRingExpParam_t_o *v11;
  s32 pos;

  pos = 0;
  v6 = *hData;
  pos = dds3EffectPCPDataGetDataOffSet(v6, 0, bPos);
  v7 = Allocate(effPCPFlashPolyRingExpParam_t);
  effPCPFlashPolyRingExpParam_t___ctor(v7);
  v9 = effPCPFlashPolyRingExpParam_t__pCopy(v7, *hData, &pos, 1);
  v11 = v9->m_Items[0];
  return effPCPFlashPolyRingExpCreate(v11);
}

// 0x11ff2e0
void effPCPFlashPolyRingExpDelete(void **hData) {
    pMeshDelete(0);
}

// 0x11fff60
void effPCPFlashPolyRingExpDraw(void **hData) {
    DDS3EFFECT_RAND_I();
    effPCPFlashPolyRingExpPartSetVertex(0, 0, 0);
    effColorBlend(0, 0, 0);
    effColorMultiply(0, 0);
    effPCPFlashPolyRingExpPartSetVC(0, 0, 0, 0);
    dds3FlashPolyListDraw(0, 0, 0);
}

// 0x11ffe40
void effPCPFlashPolyRingExpDrawOff(void **hData) {
    dds3FlashPolyListDrawOff(0);
}

// 0x1207620
effPCPFlashPolyRingExpH_tag *effPCPFlashPolyRingExpHCopy(void **hData, s32 bPos, bool tbldata) {
    effPCPFlashPolyRingExpHCreate(0);
    return 0;
}

// 0x1207200
effPCPFlashPolyRingExpH_tag *effPCPFlashPolyRingExpHCreate(effPCPFlashPolyRingExpParam_t *pParam) {
  u64 *v3;
  u64 *v4;
  u64 *v5;
  u32 *v7;
  u32 v8;
  dds3FlashPolyList_t_o *v9;
  u64 v10;
  u32 v11;
  f32 v12;
  f32 v13;
  u32 v14;
  f32 v15;
  s64 v16;
  u32 *v18;
  u64 v19;
  u64 *v20;
  u64 v23;
  s64 v25;
  u32 v26;
  u64 v27;
  u64 v29;

  v3 = Allocate(effPCPFlashPolyRingExpH_tag);
  _ctor(v3, 0);
  v4 = Allocate(effPCPFlashPolyRingExpParam_t);
  effPCPFlashPolyRingExpParam_t___ctor(v4);
  v5 = v3 + 2;
  v3[2] = v4;
  effPCPFlashPolyRingExpParam_t__pClone(pParam, v3 + 2);
  v3[3] = NewSpecific(effPCPFlashPolyRingExpHPart_tag, pParam->number);
  v3[4] = 0x8080808000000000LL;
  *(v3 + 10) = 1065353216;
  v7 = v3[2];
  *(v3 + 11) = v7[18];
  *(v3 + 13) = v7[16];
  *(v3 + 14) = v7[17];
  if (!v7[11])
  {
    v7[11] = 1;
    v7 = *v5;
  }
  v8 = v7[8];
  v9 = dds3FlashPolyListCreate(v8);
  SDF_VU0__STOREIDENTITY(&v9->matrix);
  v3[8] = v9;
  v9->scale = 1.0;
  *(v3[8] + 96) = *(v3[2] + 100);
  v10 = v3[2];
  v11 = *(v10 + 32);
  if (v11)
  {
    v12 = v11;
    v13 = 6.2832 / v12;
    v14 = *(v10 + 44);
    v15 = -1.5708;
    v16 = 4;
    do
    {
      v18 = v3[3];
      v19 = v16 - 4;
      v20 = Allocate(effPCPFlashPolyRingExpHPart_tag);
      _ctor(v20, 0);
      *&v18[2 * v16] = v20;
      v23 = v3[3];
      v25 = *(v23 + 8 * v16);
      v26 = DDS3EFFECT_RAND_I();
      *(v25 + 20) = v26 / v14 * v14 - v26;
      v27 = v3[3];
      *(*(v27 + 8 * v16) + 24LL) = v15;
      v15 = v13 + v15;
      v29 = v16 - 3;
      ++v16;
    }
    while (v29 < *(*v5 + 32));
  }
  return v3;
}

// 0x12070e0
effPCPFlashPolyRingExpH_tag *effPCPFlashPolyRingExpHCreateP(void **pData, s32 bPos, bool tbldata) {
    effPCPFlashPolyRingExpHCreate(0);
    return 0;
}

// 0x1207510
effPCPFlashPolyRingExpH_tag *effPCPFlashPolyRingExpHCreatePCF(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v6;
  u64 *v7;
  effPCPFlashPolyRingExpParam_t_array *v9;
  effPCPFlashPolyRingExpParam_t_o *v11;
  s32 pos;

  pos = 0;
  v6 = *hData;
  pos = dds3EffectPCPDataGetDataOffSet(v6, 0, bPos);
  v7 = Allocate(effPCPFlashPolyRingExpParam_t);
  effPCPFlashPolyRingExpParam_t___ctor(v7);
  v9 = effPCPFlashPolyRingExpParam_t__pCopy(v7, *hData, &pos, 1);
  v11 = v9->m_Items[0];
  return effPCPFlashPolyRingExpHCreate(v11);
}

// 0x1207730
void effPCPFlashPolyRingExpHDelete(void **hData) {
    pMeshDelete(0);
    dds3FlashPolyListHDelete(0);
}

// 0x12084a0
void effPCPFlashPolyRingExpHDraw(void **hData) {
    DDS3EFFECT_RAND_I();
    effPCPFlashPolyRingExpHPartSetVertex(0, 0, 0);
    effColorBlend(0, 0, 0);
    effColorMultiply(0, 0);
    effPCPFlashPolyRingExpHPartSetVC(0, 0, 0, 0);
    dds3FlashPolyListHDraw(0, 0);
}

// 0x1208380
void effPCPFlashPolyRingExpHDrawOff(void **hData) {
    dds3FlashPolyListHDrawOff(0);
}

// 0x1208310
void effPCPFlashPolyRingExpHPartRotate(effPCPFlashPolyRingExpH_tag **pFlashPoly, s32 number) {
  struct effPCPFlashPolyRingExpHPart_tag_array *pPart;
  effPCPFlashPolyRingExpHPart_tag_o *v5;

  pPart = (*pFlashPoly)->pPart;
  v5 = pPart->m_Items[number];
  v5->rotate = v5->rotate + (*pFlashPoly)->param->rotate;
}

// 0x1207c80
void effPCPFlashPolyRingExpHPartSetVC(effPCPFlashPolyRingExpH_tag **pFlashPoly, s32 number, u32 abgr, s32 vpos) {
  struct effPCPFlashPolyRingExpParam_t_o *param;
  u32 abgr_in;
  struct System_UInt32_array *pVC;
  u32 v8;
  char v10;
  u32 v12;
  u32 v14;
  u32 v16;
  u32 v18;
  u32 v20;
  u32 v21;
  u32 v23;
  u32 v25;

  param = (*pFlashPoly)->param;
  abgr_in = param->abgr_in;
  pVC = (*pFlashPoly)->hPoly->pVC;
  v8 = param->abgr_out & 0xFFFFFF;
  v10 = number;
  v12 = effColorMultiply(v8, abgr);
  pVC->m_Items[vpos] = v12;
  v14 = effColorMultiply(v8, abgr);
  pVC->m_Items[vpos + 1] = v14;
  if ((v10 & 1) != 0)
  {
    v21 = effColorMultiply(0x80000000, abgr);
    pVC->m_Items[vpos + 2] = v21;
    v23 = effColorMultiply(abgr_in | 0xFF000000, abgr);
    pVC->m_Items[vpos + 3] = v23;
    v20 = 0x80000000;
  }
  else
  {
    v16 = effColorMultiply(0xFF000000, abgr);
    pVC->m_Items[vpos + 2] = v16;
    v18 = effColorMultiply(abgr_in & 0xFFFFFF | 0x40000000, abgr);
    v20 = -16777216;
    pVC->m_Items[vpos + 3] = v18;
  }
  v25 = effColorMultiply(v20, abgr);
  pVC->m_Items[vpos + 4] = v25;
}

// 0x1207e90
void effPCPFlashPolyRingExpHPartSetVertex(effPCPFlashPolyRingExpH_tag **pFlashPoly, s32 number, s32 vpos) {
    sdfCos(0);
    sdfSin(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__OUTERPRODUCT();
}

// 0x1207970
void effPCPFlashPolyRingExpHSetColor(void **hData, u32 abgr) {
}

// 0x1207850
void effPCPFlashPolyRingExpHSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1207b50
void effPCPFlashPolyRingExpHSetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__STOREMATRIX(0);
}

// 0x1207a60
void effPCPFlashPolyRingExpHSetScale(void **hData, f32 scale) {
}

// 0x11ffdd0
void effPCPFlashPolyRingExpPartRotate(effPCPFlashPolyRingExp_tag **pFlashPoly, s32 number) {
  struct effPCPFlashPolyRingExpPart_tag_array *pPart;
  effPCPFlashPolyRingExpPart_tag_o *v5;

  pPart = (*pFlashPoly)->pPart;
  v5 = pPart->m_Items[number];
  v5->rotate = v5->rotate + (*pFlashPoly)->param->rotate;
}

// 0x11ff740
void effPCPFlashPolyRingExpPartSetVC(effPCPFlashPolyRingExp_tag **pFlashPoly, s32 number, u32 abgr, s32 vpos) {
  struct effPCPFlashPolyRingExpParam_t_o *param;
  u32 abgr_in;
  struct System_UInt32_array *pVC;
  u32 v8;
  char v10;
  u32 v12;
  u32 v14;
  u32 v16;
  u32 v18;
  u32 v20;
  u32 v21;
  u32 v23;
  u32 v25;

  param = (*pFlashPoly)->param;
  abgr_in = param->abgr_in;
  pVC = (*pFlashPoly)->hPoly->pVC;
  v8 = param->abgr_out & 0xFFFFFF;
  v10 = number;
  v12 = effColorMultiply(v8, abgr);
  pVC->m_Items[vpos] = v12;
  v14 = effColorMultiply(v8, abgr);
  pVC->m_Items[vpos + 1] = v14;
  if ((v10 & 1) != 0)
  {
    v21 = effColorMultiply(0x80000000, abgr);
    pVC->m_Items[vpos + 2] = v21;
    v23 = effColorMultiply(abgr_in | 0xFF000000, abgr);
    pVC->m_Items[vpos + 3] = v23;
    v20 = 0x80000000;
  }
  else
  {
    v16 = effColorMultiply(0xFF000000, abgr);
    pVC->m_Items[vpos + 2] = v16;
    v18 = effColorMultiply(abgr_in & 0xFFFFFF | 0x40000000, abgr);
    v20 = -16777216;
    pVC->m_Items[vpos + 3] = v18;
  }
  v25 = effColorMultiply(v20, abgr);
  pVC->m_Items[vpos + 4] = v25;
}

// 0x11ff950
void effPCPFlashPolyRingExpPartSetVertex(effPCPFlashPolyRingExp_tag **pFlashPoly, s32 number, s32 vpos) {
    sdfCos(0);
    sdfSin(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__OUTERPRODUCT();
}

// 0x11ff560
void effPCPFlashPolyRingExpSetColor(void **hData, u32 abgr) {
}

// 0x11ff440
void effPCPFlashPolyRingExpSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x11ff650
void effPCPFlashPolyRingExpSetScale(void **hData, f32 scale) {
}

// 0x11fd030
void effPCPFlashPolyRingPartRotate(effPCPFlashPolyRing_tag **pFlashPoly, s32 number) {
  struct effPCPFlashPolyRingPart_tag_array *pPart;
  effPCPFlashPolyRingPart_tag_o *v5;

  pPart = (*pFlashPoly)->pPart;
  v5 = pPart->m_Items[number];
  v5->rotate = v5->rotate + (*pFlashPoly)->param->rotate;
}

// 0x11fc980
void effPCPFlashPolyRingPartSetVC(effPCPFlashPolyRing_tag **pFlashPoly, s32 number, u32 abgr, s32 vpos) {
  struct effPCPFlashPolyRingParam_t_o *param;
  u32 abgr_in;
  struct System_UInt32_array *pVC;
  u32 v8;
  char v10;
  u32 v12;
  u32 v14;
  u32 v16;
  u32 v18;
  u32 v20;
  u32 v21;
  u32 v23;
  u32 v25;

  param = (*pFlashPoly)->param;
  abgr_in = param->abgr_in;
  pVC = (*pFlashPoly)->hPoly->pVC;
  v8 = param->abgr_out & 0xFFFFFF;
  v10 = number;
  v12 = effColorMultiply(v8, abgr);
  pVC->m_Items[vpos] = v12;
  v14 = effColorMultiply(v8, abgr);
  pVC->m_Items[vpos + 1] = v14;
  if ((v10 & 1) != 0)
  {
    v21 = effColorMultiply(0x80000000, abgr);
    pVC->m_Items[vpos + 2] = v21;
    v23 = effColorMultiply(abgr_in | 0xFF000000, abgr);
    pVC->m_Items[vpos + 3] = v23;
    v20 = 0x80000000;
  }
  else
  {
    v16 = effColorMultiply(0xFF000000, abgr);
    pVC->m_Items[vpos + 2] = v16;
    v18 = effColorMultiply(abgr_in & 0xFFFFFF | 0x40000000, abgr);
    v20 = -16777216;
    pVC->m_Items[vpos + 3] = v18;
  }
  v25 = effColorMultiply(v20, abgr);
  pVC->m_Items[vpos + 4] = v25;
}

// 0x11fcb90
void effPCPFlashPolyRingPartSetVertex(effPCPFlashPolyRing_tag **pFlashPoly, s32 number, s32 vpos) {
    sdfCos(0);
    sdfSin(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__OUTERPRODUCT();
}

// 0x11fc7a0
void effPCPFlashPolyRingSetColor(void **hData, u32 abgr) {
}

// 0x11fc680
void effPCPFlashPolyRingSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x11fc890
void effPCPFlashPolyRingSetScale(void **hData, f32 scale) {
}

// 0x11f9730
effPCPFlashPolySphere2_tag *effPCPFlashPolySphere2Copy(void **hData, s32 bPos, bool tbldata) {
    effPCPFlashPolySphere2Create(0);
    return 0;
}

// 0x11f93e0
effPCPFlashPolySphere2_tag *effPCPFlashPolySphere2Create(effPCPFlashPolySphere2Param_t *pParam) {
  u64 *v3;
  u64 *v4;
  u32 v6;
  dds3FlashPolyList_t_o *v7;
  u64 v8;
  s64 v9;
  u32 *v11;
  u64 v12;
  u64 *v13;
  u64 v15;
  u64 v17;

  v3 = Allocate(effPCPFlashPolySphere2_tag);
  _ctor(v3, 0);
  v4 = Allocate(effPCPFlashPolySphere2Param_t);
  effPCPFlashPolySphere2Param_t___ctor(v4);
  v3[2] = v4;
  effPCPFlashPolySphere2Param_t__pClone(pParam, v3 + 2);
  v3[3] = NewSpecific(effPCPFlashPolySphere2Part_tag, pParam->number);
  v3[4] = 0x8080808000000000LL;
  *(v3 + 10) = 1065353216;
  v6 = *(v3[2] + 32);
  v7 = dds3FlashPolyList2Create(v6);
  v8 = v3[2];
  v3[6] = v7;
  v7->blend = *(v8 + 60);
  if (*(v3[2] + 32))
  {
    v9 = 4;
    do
    {
      v11 = v3[3];
      v12 = v9 - 4;
      v13 = Allocate(effPCPFlashPolySphere2Part_tag);
      _ctor(v13, 0);
      *&v11[2 * v9] = v13;
      v15 = v3[3];
      *(*(v15 + 8 * v9) + 20LL) = 0;
      v17 = v9 - 3;
      ++v9;
    }
    while (v17 < *(v3[2] + 32));
  }
  return v3;
}

// 0x11f92c0
effPCPFlashPolySphere2_tag *effPCPFlashPolySphere2CreateP(void **pData, s32 bPos, bool tbldata) {
    effPCPFlashPolySphere2Create(0);
    return 0;
}

// 0x11f95d0
effPCPFlashPolySphere2_tag *effPCPFlashPolySphere2CreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPDataGetDataUnity(0, 0, 0, 0);
    effPCPFlashPolySphere2Create(0);
    return 0;
}

// 0x11f9840
void effPCPFlashPolySphere2Delete(void **hData) {
    pMeshDelete(0);
}

// 0x11fa1d0
void effPCPFlashPolySphere2Draw(void **hData) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    effPCPFlashPolySphere2PartSetVertex(0, 0, (sdfVector4_t){0}, 0);
    effColorBlend(0, 0, 0);
    effColorMultiply(0, 0);
    effPCPFlashPolySphere2PartSetVC(0, 0, 0, 0);
    dds3FlashPolyList2Draw(0, 0);
}

// 0x11fa0b0
void effPCPFlashPolySphere2DrawOff(void **hData) {
    dds3FlashPolyList2DrawOff(0);
}

// 0x1201ff0
effPCPFlashPolySphere2Exp_tag *effPCPFlashPolySphere2ExpCopy(void **hData, s32 bPos, bool tbldata) {
    effPCPFlashPolySphere2ExpCreate(0);
    return 0;
}

// 0x1201cf0
effPCPFlashPolySphere2Exp_tag *effPCPFlashPolySphere2ExpCreate(effPCPFlashPolySphere2ExpParam_t *pParam) {
  u64 *v3;
  u64 *v4;
  u32 v6;
  dds3FlashPolyList_t_o *v7;
  u64 v8;
  s64 v9;
  u32 *v11;
  u64 v12;
  u64 *v13;
  u64 v15;
  u64 v17;

  v3 = Allocate(effPCPFlashPolySphere2Exp_tag);
  _ctor(v3, 0);
  v4 = Allocate(effPCPFlashPolySphere2ExpParam_t);
  effPCPFlashPolySphere2ExpParam_t___ctor(v4);
  v3[2] = v4;
  effPCPFlashPolySphere2ExpParam_t__pClone(pParam, v3 + 2);
  v3[3] = NewSpecific(effPCPFlashPolySphere2ExpPart_tag, pParam->number);
  v3[4] = 0x8080808000000000LL;
  *(v3 + 10) = 1065353216;
  v6 = *(v3[2] + 32);
  v7 = dds3FlashPolyList2Create(v6);
  v8 = v3[2];
  v3[6] = v7;
  v7->blend = *(v8 + 72);
  if (*(v3[2] + 32))
  {
    v9 = 4;
    do
    {
      v11 = v3[3];
      v12 = v9 - 4;
      v13 = Allocate(effPCPFlashPolySphere2ExpPart_tag);
      _ctor(v13, 0);
      *&v11[2 * v9] = v13;
      v15 = v3[3];
      *(*(v15 + 8 * v9) + 20LL) = 0;
      v17 = v9 - 3;
      ++v9;
    }
    while (v17 < *(v3[2] + 32));
  }
  return v3;
}

// 0x1201bd0
effPCPFlashPolySphere2Exp_tag *effPCPFlashPolySphere2ExpCreateP(void **pData, s32 bPos, bool tbldata) {
    effPCPFlashPolySphere2ExpCreate(0);
    return 0;
}

// 0x1201ee0
effPCPFlashPolySphere2Exp_tag *effPCPFlashPolySphere2ExpCreatePCF(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v6;
  u64 *v7;
  effPCPFlashPolySphere2ExpParam_t_array *v9;
  effPCPFlashPolySphere2ExpParam_t_o *v11;
  s32 pos;

  pos = 0;
  v6 = *hData;
  pos = dds3EffectPCPDataGetDataOffSet(v6, 0, bPos);
  v7 = Allocate(effPCPFlashPolySphere2ExpParam_t);
  effPCPFlashPolySphere2ExpParam_t___ctor(v7);
  v9 = effPCPFlashPolySphere2ExpParam_t__pCopy(v7, *hData, &pos, 1);
  v11 = v9->m_Items[0];
  return effPCPFlashPolySphere2ExpCreate(v11);
}

// 0x1202100
void effPCPFlashPolySphere2ExpDelete(void **hData) {
    pMeshDelete(0);
}

// 0x1202b00
void effPCPFlashPolySphere2ExpDraw(void **hData) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    effPCPFlashPolySphere2ExpPartSetVertex(0, 0, (sdfVector4_t){0}, 0);
    effColorBlend(0, 0, 0);
    effColorMultiply(0, 0);
    effPCPFlashPolySphere2ExpPartSetVC(0, 0, 0, 0);
    dds3FlashPolyList2Draw(0, 0);
}

// 0x12029e0
void effPCPFlashPolySphere2ExpDrawOff(void **hData) {
    dds3FlashPolyList2DrawOff(0);
}

// 0x1202560
void effPCPFlashPolySphere2ExpPartSetVC(effPCPFlashPolySphere2Exp_tag **pFlashPoly, s32 number, u32 abgr, s32 vpos) {
  struct effPCPFlashPolySphere2ExpParam_t_o *param;
  u32 abgr_in;
  struct System_UInt32_array *pVC;
  u32 v8;
  u32 v11;
  u32 v13;
  u32 v15;

  param = (*pFlashPoly)->param;
  abgr_in = param->abgr_in;
  pVC = (*pFlashPoly)->hPoly->pVC;
  v8 = param->abgr_out & 0xFFFFFF;
  v11 = effColorMultiply(v8, abgr);
  pVC->m_Items[vpos] = v11;
  v13 = effColorMultiply(v8, abgr);
  pVC->m_Items[vpos + 1] = v13;
  v15 = effColorMultiply(abgr_in | 0xFF000000, abgr);
  pVC->m_Items[vpos + 2] = v15;
}

// 0x1202670
void effPCPFlashPolySphere2ExpPartSetVertex(effPCPFlashPolySphere2Exp_tag **pFlashPoly, s32 number, sdfVector4_t pLook, s32 vpos) {
  f32 w;
  f32 z;
  f32 y;
  effPCPFlashPolySphere2Exp_tag_o *v11;
  struct effPCPFlashPolySphere2ExpPart_tag_array *pPart;
  effPCPFlashPolySphere2ExpPart_tag_o *v14;
  f32 v15;
  f32 v16;
  struct UnityEngine_Vector4_array *pVertex;
  effPCPFlash_c *v18;
  struct effPCPFlash_StaticFields *static_fields;
  f32 v20;
  f32 v21;
  f32 v22;
  f32 v23;
  f32 v24;
  f32 v25;
  f32 v26;
  f32 v27;
  f32 v28;
  f32 v29;
  f32 v31;
  f32 v32;
  f32 v33;
  f32 v34;
  f32 radius;
  f32 v39;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v41;
  f32 v42;
  f32 x;
  UnityEngine_Vector4_o v44;
  UnityEngine_Vector4_o v45;
  UnityEngine_Vector4_o zero;
  UnityEngine_Vector4_o v47;
  UnityEngine_Vector4_o v48;
  UnityEngine_Vector4_o v49;
  UnityEngine_Vector4_o v50;
  UnityEngine_Vector4_o v51;

  w = pLook.w;
  z = pLook.z;
  y = pLook.y;
  x = pLook.x;
  *&v41.x = 0;
  *&v41.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  v11 = *pFlashPoly;
  pPart = (*pFlashPoly)->pPart;
  v14 = pPart->m_Items[number];
  LODWORD(pLook.x) = v11->param->number;
  v15 = *&pLook.x;
  v16 = 6.2832 / v15;
  pVertex = v11->hPoly->pVertex;
  static_fields = v18->static_fields;
  v39 = v16;
  v20 = static_fields->def_dir.x;
  v21 = static_fields->def_dir.y;
  v22 = v16 * number;
  v23 = static_fields->def_dir.z;
  *&static_fields = static_fields->def_dir.w;
  p.x = v20;
  p.y = v21;
  p.z = v23;
  LODWORD(p.w) = static_fields;
  v24 = v20;
  v25 = v21;
  v26 = v23;
  v27 = *&static_fields;
  v50.x = x;
  v50.y = y;
  v50.z = z;
  v50.w = w;
  SetRotateMatrixAxis(v22, v50);
  v47.x = v24;
  v47.y = v25;
  v47.z = v26;
  v47.w = v27;
  SDF_VU0__LOADVECTOR(v47);
  v48.x = x;
  v48.y = y;
  v48.z = z;
  v48.w = w;
  v42 = y;
  v28 = z;
  v29 = w;
  SDF_VU0__LOADVECTOR_B(v48);
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&p);
  SDF_VU0__APPLYMATRIX_XYZ();
  SDF_VU0__STOREVECTOR(&v41);
  v32 = v41.x;
  v31 = v41.y;
  v34 = v41.z;
  v33 = v41.w;
  radius = v14->radius;
  v49.x = v32;
  v49.y = v31;
  v49.z = v34;
  v49.w = v33;
  v44 = op_Multiply(v49, radius, 0);
  pVertex->m_Items[vpos] = v44;
  v51.y = v42;
  v51.x = x;
  v51.z = v28;
  v51.w = v29;
  SetRotateMatrixAxis(v39 + v22, v51);
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__APPLYMATRIX_XYZ();
  SDF_VU0__STOREVECTOR(&v41);
  v45 = op_Multiply(v41, v14->radius, 0);
  pVertex->m_Items[vpos + 1] = v45;
  zero = get_zero();
  pVertex->m_Items[vpos + 2] = zero;
}

// 0x1202380
void effPCPFlashPolySphere2ExpSetColor(void **hData, u32 abgr) {
}

// 0x1202260
void effPCPFlashPolySphere2ExpSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1202470
void effPCPFlashPolySphere2ExpSetScale(void **hData, f32 scale) {
}

// 0x11f9ca0
void effPCPFlashPolySphere2PartSetVC(effPCPFlashPolySphere2_tag **pFlashPoly, s32 number, u32 abgr, s32 vpos) {
  struct effPCPFlashPolySphere2Param_t_o *param;
  u32 abgr_in;
  struct System_UInt32_array *pVC;
  u32 v8;
  u32 v11;
  u32 v13;
  u32 v15;

  param = (*pFlashPoly)->param;
  abgr_in = param->abgr_in;
  pVC = (*pFlashPoly)->hPoly->pVC;
  v8 = param->abgr_out & 0xFFFFFF;
  v11 = effColorMultiply(v8, abgr);
  pVC->m_Items[vpos] = v11;
  v13 = effColorMultiply(v8, abgr);
  pVC->m_Items[vpos + 1] = v13;
  v15 = effColorMultiply(abgr_in | 0xFF000000, abgr);
  pVC->m_Items[vpos + 2] = v15;
}

// 0x11f9db0
void effPCPFlashPolySphere2PartSetVertex(effPCPFlashPolySphere2_tag **pFlashPoly, s32 number, sdfVector4_t pLook, s32 vpos) {
  f32 w;
  effPCPFlashPolySphere2_tag_o *v9;
  struct effPCPFlashPolySphere2Part_tag_array *pPart;
  effPCPFlashPolySphere2Part_tag_o *v12;
  struct UnityEngine_Vector4_array *pVertex;
  f64 v14;
  f32 v15;
  f32 v18;
  s64 v20;
  f32 v22;
  u32 p[5];
  UnityEngine_Vector4_o v26;
  f32 y;
  f32 z;
  UnityEngine_Vector4_o zero;
  UnityEngine_Vector4_o v30;
  UnityEngine_Vector4_o v31;
  UnityEngine_Vector4_o v32;
  UnityEngine_Vector4_o v33;
  UnityEngine_Vector4_o v34;

  w = pLook.w;
  y = pLook.y;
  z = pLook.z;
  p[0] = LODWORD(pLook.x);
  *&v26.x = 0;
  *&v26.z = 0;
  *&p[1] = 0;
  *&p[3] = 0;
  v9 = *pFlashPoly;
  pPart = (*pFlashPoly)->pPart;
  v12 = pPart->m_Items[number];
  LODWORD(pLook.x) = v9->param->number;
  pVertex = v9->hPoly->pVertex;
  v14 = *&pLook.x;
  zero = get_zero();
  *&p[1] = zero;
  v15 = v14;
  v18 = 6.2832 / v15;
  SDF_VU0__LOADVECTOR(def_dir);
  LODWORD(v32.x) = p[0];
  v32.y = y;
  v32.z = z;
  v32.w = w;
  SDF_VU0__LOADVECTOR_B(v32);
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__STOREVECTOR(&v26);
  v20 = vpos + 2LL;
  pVertex->m_Items[v20] = zero;
  v22 = v18 * number;
  LODWORD(v33.x) = p[0];
  v33.y = y;
  v33.z = z;
  v33.w = w;
  SetRotateMatrixAxis(v22, v33);
  SDF_VU0__LOADVECTOR(v26);
  SDF_VU0__APPLYMATRIX_XYZ();
  SDF_VU0__STOREVECTOR(&p[1]);
  v30 = op_Multiply(*&p[1], v12->radius, 0);
  pVertex->m_Items[vpos] = v30;
  v34.y = y;
  v34.z = z;
  LODWORD(v34.x) = p[0];
  v34.w = w;
  SetRotateMatrixAxis(v18 + v22, v34);
  SDF_VU0__LOADVECTOR(v26);
  SDF_VU0__APPLYMATRIX_XYZ();
  SDF_VU0__STOREVECTOR(&p[1]);
  v31 = op_Multiply(*&p[1], v12->radius, 0);
  pVertex->m_Items[vpos + 1] = v31;
}

// 0x11f9ac0
void effPCPFlashPolySphere2SetColor(void **hData, u32 abgr) {
}

// 0x11f99a0
void effPCPFlashPolySphere2SetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x11f9bb0
void effPCPFlashPolySphere2SetScale(void **hData, f32 scale) {
}

// 0x12033c0
effPCPFlashPolySphere3_tag *effPCPFlashPolySphere3Copy(void **hData, s32 bPos, bool tbldata) {
    effPCPFlashPolySphere3Create(0);
    return 0;
}

// 0x1203060
effPCPFlashPolySphere3_tag *effPCPFlashPolySphere3Create(effPCPFlashPolySphere3Param_t *pParam) {
  u64 *v3;
  u64 *v4;
  u64 *v5;
  u64 v7;
  u32 v8;
  dds3FlashPolyList_t_o *v9;
  u64 v10;
  u32 v11;
  s64 v12;
  u32 *v14;
  u64 v15;
  u64 *v16;
  u64 v19;
  s64 v21;
  u32 v22;
  u64 v23;

  v3 = Allocate(effPCPFlashPolySphere3_tag);
  _ctor(v3, 0);
  v4 = Allocate(effPCPFlashPolySphere3Param_t);
  effPCPFlashPolySphere3Param_t___ctor(v4);
  v5 = v3 + 2;
  v3[2] = v4;
  effPCPFlashPolySphere3Param_t__pClone(pParam, v3 + 2);
  v3[3] = NewSpecific(effPCPFlashPolySphere3Part_tag, pParam->number);
  v3[4] = 0x8080808000000000LL;
  *(v3 + 10) = 1065353216;
  v7 = v3[2];
  if (!*(v7 + 44))
  {
    *(v7 + 44) = 1;
    v7 = *v5;
  }
  v8 = *(v7 + 32);
  v9 = dds3FlashPolyList3Create(v8);
  v3[6] = v9;
  v9->scale = 1.0;
  *(v3[6] + 96) = *(v3[2] + 92);
  v10 = v3[2];
  if (*(v10 + 32))
  {
    v11 = *(v10 + 44);
    v12 = 4;
    do
    {
      v14 = v3[3];
      v15 = v12 - 4;
      v16 = Allocate(effPCPFlashPolySphere3Part_tag);
      _ctor(v16, 0);
      *&v14[2 * v12] = v16;
      v19 = v3[3];
      v21 = *(v19 + 8 * v12);
      v22 = DDS3EFFECT_RAND_I();
      v23 = v12 - 3;
      ++v12;
      *(v21 + 20) = v22 / v11 * v11 - v22;
    }
    while (v23 < *(*v5 + 32));
  }
  return v3;
}

// 0x1202f40
effPCPFlashPolySphere3_tag *effPCPFlashPolySphere3CreateP(void **pData, s32 bPos, bool tbldata) {
    effPCPFlashPolySphere3Create(0);
    return 0;
}

// 0x12032b0
effPCPFlashPolySphere3_tag *effPCPFlashPolySphere3CreatePCF(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v6;
  u64 *v7;
  effPCPFlashPolySphere3Param_t_array *v9;
  effPCPFlashPolySphere3Param_t_o *v11;
  s32 pos;

  pos = 0;
  v6 = *hData;
  pos = dds3EffectPCPDataGetDataOffSet(v6, 0, bPos);
  v7 = Allocate(effPCPFlashPolySphere3Param_t);
  effPCPFlashPolySphere3Param_t___ctor(v7);
  v9 = effPCPFlashPolySphere3Param_t__pCopy(v7, *hData, &pos, 1);
  v11 = v9->m_Items[0];
  return effPCPFlashPolySphere3Create(v11);
}

// 0x12034d0
void effPCPFlashPolySphere3Delete(void **hData) {
    pMeshDelete(0);
}

// 0x1204130
void effPCPFlashPolySphere3Draw(void **hData) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__STOREVECTOR(0);
    DDS3EFFECT_RAND_I();
    effPCPFlashPolySphere3PartSetVertex(0, 0, (sdfVector4_t){0}, 0);
    effColorBlend(0, 0, 0);
    effColorMultiply(0, 0);
    effPCPFlashPolySphere3PartSetVC(0, 0, 0, 0);
    effPCPFlashPolySphere3PartInit(0, 0, (sdfVector4_t){0});
    dds3FlashPolyList3Draw(0, 0);
}

// 0x1204010
void effPCPFlashPolySphere3DrawOff(void **hData) {
    dds3FlashPolyList3DrawOff(0);
}

// 0x1203ad0
void effPCPFlashPolySphere3PartInit(effPCPFlashPolySphere3_tag **pFlashPoly, s32 number, sdfVector4_t pLook) {
  struct effPCPFlashPolySphere3Part_tag_array *pPart;
  f32 *v8;
  struct effPCPFlashPolySphere3Param_t_o *param;
  f32 width;
  f32 rotate;

  pPart = (*pFlashPoly)->pPart;
  v8 = pPart->m_Items[number];
  v8[10] = DDS3EFFECT_RAND_F() * 6.2832;
  v8[7] = ((DDS3EFFECT_RAND_F() * 0.3) + 0.7) * (*pFlashPoly)->param->radius;
  param = (*pFlashPoly)->param;
  width = param->width;
  v8[11] = width * DDS3EFFECT_RAND_FA(param->width_r);
  rotate = (*pFlashPoly)->param->rotate;
  v8[6] = rotate * DDS3EFFECT_RAND_PM();
}

// 0x1203fb0
void effPCPFlashPolySphere3PartRotate(effPCPFlashPolySphere3_tag **pFlashPoly, s32 number, sdfVector4_t pLook) {
  struct effPCPFlashPolySphere3Part_tag_array *pPart;
  effPCPFlashPolySphere3Part_tag_o *v6;

  pPart = (*pFlashPoly)->pPart;
  v6 = pPart->m_Items[number];
  v6->look_r = v6->look_r + v6->rotate;
}

// 0x1203930
void effPCPFlashPolySphere3PartSetVC(effPCPFlashPolySphere3_tag **pFlashPoly, s32 number, u32 abgr, s32 vpos) {
  struct effPCPFlashPolySphere3Param_t_o *param;
  u32 abgr_in;
  struct System_UInt32_array *pVC;
  u32 v10;
  u32 v11;
  s32 v13;
  char *v14;
  u32 *v15;
  u32 v16;
  u32 v18;
  u32 v20;
  u32 max_length;

  param = (*pFlashPoly)->param;
  abgr_in = param->abgr_in;
  pVC = (*pFlashPoly)->hPoly->pVC;
  v10 = param->abgr_out & 0xFFFFFF;
  v11 = effColorMultiply(v10 | 0x80000000, abgr);
  v13 = abgr_in & 0xFFFFFF;
  v14 = pVC + 4 * vpos;
  *(v14 + 8) = v11;
  v15 = (v14 + 32);
  v16 = effColorMultiply(v10, abgr);
  pVC->m_Items[vpos + 1] = v16;
  v18 = effColorMultiply(v13 | 0x80000000, abgr);
  pVC->m_Items[vpos + 2] = v18;
  v20 = effColorMultiply(v10, abgr);
  pVC->m_Items[vpos + 3] = v20;
  max_length = pVC->max_length;
  pVC->m_Items[vpos + 4] = *v15;
}

// 0x1203c00
void effPCPFlashPolySphere3PartSetVertex(effPCPFlashPolySphere3_tag **pFlashPoly, s32 number, sdfVector4_t pLook, s32 vpos) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  struct effPCPFlashPolySphere3Part_tag_array *pPart;
  effPCPFlashPolySphere3Part_tag_o *v14;
  struct UnityEngine_Vector4_array *pVertex;
  f32 look_r;
  s64 v20;
  f32 v21;
  f32 v22;
  f32 width;
  UnityEngine_Vector4_o v29;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v31;
  UnityEngine_Vector4_o v32;
  UnityEngine_Vector4_o v33;
  UnityEngine_Vector4_o v34;
  UnityEngine_Vector4_o v35;
  UnityEngine_Vector4_o v36;
  UnityEngine_Vector4_o v37;
  UnityEngine_Vector4_o v38;
  UnityEngine_Vector4_o v39;

  w = pLook.w;
  z = pLook.z;
  y = pLook.y;
  x = pLook.x;
  *&p.x = 0;
  *&p.z = 0;
  *&v29.x = 0;
  *&v29.z = 0;
  pPart = (*pFlashPoly)->pPart;
  v14 = pPart->m_Items[number];
  pVertex = (*pFlashPoly)->hPoly->pVertex;
  look_r = v14->look_r;
  v39.x = x;
  v39.y = y;
  v39.z = z;
  v39.w = w;
  SetRotateMatrixAxis(look_r, v39);
  SDF_VU0__LOADVECTOR(def_dir);
  v36.x = x;
  v36.y = y;
  v36.z = z;
  v36.w = w;
  SDF_VU0__LOADVECTOR_B(v36);
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__NORMALIZE();
  SDF_VU0__APPLYMATRIX_XYZ();
  SDF_VU0__STOREVECTOR(&p);
  v37.x = x;
  v37.y = y;
  v37.z = z;
  v37.w = w;
  SDF_VU0__LOADVECTOR_B(v37);
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v29);
  v20 = *&v29.x;
  v22 = v29.z;
  v21 = v29.w;
  width = v14->width;
  *&v38.x = v20;
  v38.z = v22;
  v38.w = v21;
  v29 = op_Multiply(v38, width, 0);
  v31 = op_Multiply(p, v14->move + v14->radius, 0);
  pVertex->m_Items[vpos] = v31;
  v32 = op_Multiply(p, v14->move - v14->radius, 0);
  pVertex->m_Items[vpos + 4] = v32;
  v33 = op_Multiply(p, v14->move, 0);
  p = v33;
  pVertex->m_Items[vpos + 2] = v33;
  v34 = op_Addition(p, v29);
  pVertex->m_Items[vpos + 1] = v34;
  v35 = op_Subtraction(p, v29);
  pVertex->m_Items[vpos + 3] = v35;
}

// 0x1203750
void effPCPFlashPolySphere3SetColor(void **hData, u32 abgr) {
}

// 0x1203630
void effPCPFlashPolySphere3SetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1203840
void effPCPFlashPolySphere3SetScale(void **hData, f32 scale) {
}

// 0x11faad0
effPCPFlashPolySphere_tag *effPCPFlashPolySphereCopy(void **hData, s32 bPos, bool tbldata) {
    effPCPFlashPolySphereCreate(0, 0, 0);
    return 0;
}

// 0x11fa5e0
effPCPFlashPolySphere_tag *effPCPFlashPolySphereCreate(void **hData, s32 bPos, bool tbldata) {
    effPCPFlashPolySphereParam_t__pClone(0, 0);
    effPCPFlashPolySphereParam_t__pCopy(0, 0, 0, 0);
    dds3FlashPolyListCreate(0);
    DDS3EFFECT_RAND_I();
    return 0;
}

// 0x11fa9b0
effPCPFlashPolySphere_tag *effPCPFlashPolySphereCreatePCF(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v6;
  u64 *v7;
  effPCPFlashPolySphereParam_t_array *v8;
  Il2CppObject *hDataa;
  s32 pos;

  pos = 0;
  hDataa = 0;
  v6 = *hData;
  pos = dds3EffectPCPDataGetDataOffSet(v6, 0, bPos);
  v7 = Allocate(effPCPFlashPolySphereParam_t);
  effPCPFlashPolySphereParam_t___ctor(v7);
  v8 = effPCPFlashPolySphereParam_t__pCopy(v7, *hData, &pos, 1);
  hDataa = v8->m_Items[0];
  return effPCPFlashPolySphereCreate(&hDataa, 0, 1);
}

// 0x11fac10
void effPCPFlashPolySphereDelete(void **hData) {
    pMeshDelete(0);
}

// 0x11fbaa0
void effPCPFlashPolySphereDraw(void **hData) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__STOREVECTOR(0);
    effPCPFlashPolySpherePartRotate(0, 0, (sdfVector4_t){0});
    effPCPFlashPolySpherePartSetVertex(0, 0, (sdfVector4_t){0}, 0);
    effColorBlend(0, 0, 0);
    effColorMultiply(0, 0);
    effPCPFlashPolySpherePartSetVC(0, 0, 0, 0);
    DDS3EFFECT_RAND_I();
    effPCPFlashPolySpherePartInit(0, 0, (sdfVector4_t){0});
    dds3FlashPolyListDraw(0, 0, 0);
}

// 0x11fb980
void effPCPFlashPolySphereDrawOff(void **hData) {
    dds3FlashPolyListDrawOff(0);
}

// 0x12008a0
effPCPFlashPolySphereExp_tag *effPCPFlashPolySphereExpCopy(void **hData, s32 bPos, bool tbldata) {
    effPCPFlashPolySphereExpCreate(0);
    return 0;
}

// 0x1200550
effPCPFlashPolySphereExp_tag *effPCPFlashPolySphereExpCreate(effPCPFlashPolySphereExpParam_t *pParam) {
  u64 *v3;
  u64 *v4;
  u64 *v5;
  u64 v7;
  u32 v8;
  dds3FlashPolyList_t_o *v9;
  u64 v10;
  u64 v11;
  u32 v12;
  s64 v13;
  u32 *v15;
  u64 v16;
  u64 *v17;
  u64 v20;
  s64 v22;
  u32 v23;
  u64 v24;

  v3 = Allocate(effPCPFlashPolySphereExp_tag);
  _ctor(v3, 0);
  v4 = Allocate(effPCPFlashPolySphereExpParam_t);
  effPCPFlashPolySphereExpParam_t___ctor(v4);
  v5 = v3 + 2;
  v3[2] = v4;
  effPCPFlashPolySphereExpParam_t__pClone(pParam, v3 + 2);
  v3[3] = NewSpecific(effPCPFlashPolySphereExpPart_tag, pParam->number);
  v3[4] = 0x8080808000000000LL;
  *(v3 + 10) = 1065353216;
  v7 = v3[2];
  if (!*(v7 + 48))
  {
    *(v7 + 48) = 1;
    v7 = *v5;
  }
  v8 = *(v7 + 32);
  v9 = dds3FlashPolyListCreate(v8);
  v10 = v3[2];
  v3[6] = v9;
  v9->blend = *(v10 + 88);
  v11 = v3[2];
  if (*(v11 + 32))
  {
    v12 = *(v11 + 48);
    v13 = 4;
    do
    {
      v15 = v3[3];
      v16 = v13 - 4;
      v17 = Allocate(effPCPFlashPolySphereExpPart_tag);
      _ctor(v17, 0);
      *&v15[2 * v13] = v17;
      v20 = v3[3];
      v22 = *(v20 + 8 * v13);
      v23 = DDS3EFFECT_RAND_I();
      v24 = v13 - 3;
      ++v13;
      *(v22 + 20) = v23 / v12 * v12 - v23;
    }
    while (v24 < *(*v5 + 32));
  }
  return v3;
}

// 0x1200430
effPCPFlashPolySphereExp_tag *effPCPFlashPolySphereExpCreateP(void **pData, s32 bPos, bool tbldata) {
    effPCPFlashPolySphereExpCreate(0);
    return 0;
}

// 0x1200790
effPCPFlashPolySphereExp_tag *effPCPFlashPolySphereExpCreatePCF(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v6;
  u64 *v7;
  effPCPFlashPolySphereExpParam_t_array *v9;
  effPCPFlashPolySphereExpParam_t_o *v11;
  s32 pos;

  pos = 0;
  v6 = *hData;
  pos = dds3EffectPCPDataGetDataOffSet(v6, 0, bPos);
  v7 = Allocate(effPCPFlashPolySphereExpParam_t);
  effPCPFlashPolySphereExpParam_t___ctor(v7);
  v9 = effPCPFlashPolySphereExpParam_t__pCopy(v7, *hData, &pos, 1);
  v11 = v9->m_Items[0];
  return effPCPFlashPolySphereExpCreate(v11);
}

// 0x12009b0
void effPCPFlashPolySphereExpDelete(void **hData) {
    pMeshDelete(0);
}

// 0x12016e0
void effPCPFlashPolySphereExpDraw(void **hData) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__STOREVECTOR(0);
    effPCPFlashPolySphereExpPartInit(0, 0, (sdfVector4_t){0});
    DDS3EFFECT_RAND_I();
    effPCPFlashPolySphereExpPartSetVertex(0, 0, (sdfVector4_t){0}, 0);
    effColorBlend(0, 0, 0);
    effColorMultiply(0, 0);
    effPCPFlashPolySphereExpPartSetVC(0, 0, 0, 0);
    dds3FlashPolyListDraw(0, 0, 0);
}

// 0x12015c0
void effPCPFlashPolySphereExpDrawOff(void **hData) {
    dds3FlashPolyListDrawOff(0);
}

// 0x1201020
void effPCPFlashPolySphereExpPartInit(effPCPFlashPolySphereExp_tag **pFlashPoly, s32 number, sdfVector4_t pLook) {
  struct effPCPFlashPolySphereExpPart_tag_array *pPart;
  f32 *v8;
  f32 v9;
  f32 v10;
  f32 rotate;

  pPart = (*pFlashPoly)->pPart;
  v8 = pPart->m_Items[number];
  v8[8] = DDS3EFFECT_RAND_F() * 6.2832;
  v9 = ((DDS3EFFECT_RAND_F() * 0.3) + 0.7) * (*pFlashPoly)->param->radius;
  v8[11] = v9;
  v8[7] = v9;
  v10 = ((DDS3EFFECT_RAND_F() * 0.5) + 0.5) * 0.5;
  v8[9] = (*pFlashPoly)->param->width_in * v10;
  v8[10] = v10 * (*pFlashPoly)->param->width_out;
  rotate = (*pFlashPoly)->param->rotate;
  v8[6] = rotate * DDS3EFFECT_RAND_PM();
}

// 0x1201560
void effPCPFlashPolySphereExpPartRotate(effPCPFlashPolySphereExp_tag **pFlashPoly, s32 number, sdfVector4_t pLook) {
  struct effPCPFlashPolySphereExpPart_tag_array *pPart;
  effPCPFlashPolySphereExpPart_tag_o *v6;

  pPart = (*pFlashPoly)->pPart;
  v6 = pPart->m_Items[number];
  v6->look_r = v6->look_r + v6->rotate;
}

// 0x1200e10
void effPCPFlashPolySphereExpPartSetVC(effPCPFlashPolySphereExp_tag **pFlashPoly, s32 number, u32 abgr, s32 vpos) {
  struct effPCPFlashPolySphereExpParam_t_o *param;
  u32 abgr_in;
  struct System_UInt32_array *pVC;
  u32 v8;
  char v10;
  u32 v12;
  u32 v14;
  u32 v16;
  u32 v18;
  u32 v20;
  u32 v21;
  u32 v23;
  u32 v25;

  param = (*pFlashPoly)->param;
  abgr_in = param->abgr_in;
  pVC = (*pFlashPoly)->hPoly->pVC;
  v8 = param->abgr_out & 0xFFFFFF;
  v10 = number;
  v12 = effColorMultiply(v8, abgr);
  pVC->m_Items[vpos] = v12;
  v14 = effColorMultiply(v8, abgr);
  pVC->m_Items[vpos + 1] = v14;
  if ((v10 & 1) != 0)
  {
    v21 = effColorMultiply(0x80000000, abgr);
    pVC->m_Items[vpos + 2] = v21;
    v23 = effColorMultiply(abgr_in | 0xFF000000, abgr);
    pVC->m_Items[vpos + 3] = v23;
    v20 = 0x80000000;
  }
  else
  {
    v16 = effColorMultiply(0xFF000000, abgr);
    pVC->m_Items[vpos + 2] = v16;
    v18 = effColorMultiply(abgr_in & 0xFFFFFF | 0x40000000, abgr);
    v20 = -16777216;
    pVC->m_Items[vpos + 3] = v18;
  }
  v25 = effColorMultiply(v20, abgr);
  pVC->m_Items[vpos + 4] = v25;
}

// 0x1201170
void effPCPFlashPolySphereExpPartSetVertex(effPCPFlashPolySphereExp_tag **pFlashPoly, s32 number, sdfVector4_t pLook, s32 vpos) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  struct effPCPFlashPolySphereExpPart_tag_array *pPart;
  effPCPFlashPolySphereExpPart_tag_o *v14;
  struct UnityEngine_Vector4_array *pVertex;
  f32 radius;
  effPCPFlash_c *v17;
  f32 radius_max;
  struct effPCPFlash_StaticFields *static_fields;
  s64 v20;
  f32 v21;
  f32 look_r;
  f32 v23;
  f32 v25;
  f32 v26;
  f32 v27;
  f32 v28;
  f32 width_in;
  s64 v30;
  UnityEngine_Vector4_o v36;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v38;
  UnityEngine_Vector4_o zero;
  UnityEngine_Vector4_o v40;
  UnityEngine_Vector4_o v41;
  UnityEngine_Vector4_o v42;
  UnityEngine_Vector4_o v43;
  UnityEngine_Vector4_o v44;
  UnityEngine_Vector4_o v45;
  UnityEngine_Vector4_o v46;
  UnityEngine_Vector4_o v47;

  w = pLook.w;
  z = pLook.z;
  y = pLook.y;
  x = pLook.x;
  *&p.x = 0;
  *&p.z = 0;
  *&v36.x = 0;
  *&v36.z = 0;
  pPart = (*pFlashPoly)->pPart;
  v14 = pPart->m_Items[number];
  pVertex = (*pFlashPoly)->hPoly->pVertex;
  radius = v14->radius;
  radius_max = v14->radius_max;
  static_fields = v17->static_fields;
  v20 = *&static_fields->def_dir.x;
  v21 = static_fields->def_dir.z;
  *&static_fields = static_fields->def_dir.w;
  *&v36.x = v20;
  v36.z = v21;
  LODWORD(v36.w) = static_fields;
  look_r = v14->look_r;
  v47.x = x;
  v47.y = y;
  v47.z = z;
  v47.w = w;
  v23 = radius / radius_max;
  SetRotateMatrixAxis(look_r, v47);
  SDF_VU0__LOADVECTOR(def_dir);
  v43.x = x;
  v43.y = y;
  v43.z = z;
  v43.w = w;
  SDF_VU0__LOADVECTOR_B(v43);
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__NORMALIZE();
  SDF_VU0__APPLYMATRIX_XYZ();
  SDF_VU0__STOREVECTOR(&v36);
  v44.x = x;
  v44.y = y;
  v44.z = z;
  v44.w = w;
  SDF_VU0__LOADVECTOR_B(v44);
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&p);
  v26 = p.x;
  v25 = p.y;
  v28 = p.z;
  v27 = p.w;
  width_in = v14->width_in;
  v45.x = v26;
  v45.y = v25;
  v45.z = v28;
  v45.w = v27;
  v46 = op_Multiply(v45, width_in, 0);
  v38 = op_Multiply(v46, v23, 0);
  p = op_Multiply(p, v23 * v14->width_out, 0);
  zero = get_zero();
  v30 = vpos + 3LL;
  pVertex->m_Items[v30] = zero;
  pVertex->m_Items[vpos + 2] = v38;
  v40 = op_UnaryNegation(v38);
  pVertex->m_Items[vpos + 4] = v40;
  v36 = op_Multiply(v36, v14->radius, 0);
  v41 = op_Addition(v36, p);
  pVertex->m_Items[vpos] = v41;
  v42 = op_Subtraction(v36, p);
  pVertex->m_Items[vpos + 1] = v42;
}

// 0x1200c30
void effPCPFlashPolySphereExpSetColor(void **hData, u32 abgr) {
}

// 0x1200b10
void effPCPFlashPolySphereExpSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1200d20
void effPCPFlashPolySphereExpSetScale(void **hData, f32 scale) {
}

// 0x11fb2d0
void effPCPFlashPolySpherePartInit(effPCPFlashPolySphere_tag **pFlashPoly, s32 number, sdfVector4_t pLook) {
    DDS3EFFECT_RAND_PM();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__OUTERPRODUCT();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    DDS3EFFECT_RAND_F();
}

// 0x11fb870
void effPCPFlashPolySpherePartRotate(effPCPFlashPolySphere_tag **pFlashPoly, s32 number, sdfVector4_t pLook) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  struct effPCPFlashPolySpherePart_tag_array *pPart;
  effPCPFlashPolySpherePart_tag_o *v12;
  f32 rotate;
  UnityEngine_Vector4_o *p_dir;
  f32 v15;
  UnityEngine_Vector4_o v16;
  UnityEngine_Vector4_o v17;

  w = pLook.w;
  z = pLook.z;
  y = pLook.y;
  x = pLook.x;
  pPart = (*pFlashPoly)->pPart;
  v12 = pPart->m_Items[number];
  rotate = v12->rotate;
  v17.x = x;
  v17.y = y;
  v17.z = z;
  v17.w = w;
  SetRotateMatrixAxis(rotate, v17);
  v15 = v12->dir.x;
  p_dir = &v12->dir;
  v16.x = v15;
  v16.w = p_dir->w;
  v16.y = p_dir->y;
  v16.z = p_dir->z;
  SDF_VU0__LOADVECTOR(v16);
  SDF_VU0__APPLYMATRIX_XYZ();
  SDF_VU0__STOREVECTOR(p_dir);
}

// 0x11fb0c0
void effPCPFlashPolySpherePartSetVC(effPCPFlashPolySphere_tag **pFlashPoly, s32 number, u32 abgr, s32 vpos) {
  struct effPCPFlashPolySphereParam_t_o *param;
  u32 abgr_in;
  struct System_UInt32_array *pVC;
  u32 v8;
  char v10;
  u32 v12;
  u32 v14;
  u32 v16;
  u32 v18;
  u32 v20;
  u32 v21;
  u32 v23;
  u32 v25;

  param = (*pFlashPoly)->param;
  abgr_in = param->abgr_in;
  pVC = (*pFlashPoly)->hPoly->pVC;
  v8 = param->abgr_out & 0xFFFFFF;
  v10 = number;
  v12 = effColorMultiply(v8, abgr);
  pVC->m_Items[vpos] = v12;
  v14 = effColorMultiply(v8, abgr);
  pVC->m_Items[vpos + 1] = v14;
  if ((v10 & 1) != 0)
  {
    v21 = effColorMultiply(0x80000000, abgr);
    pVC->m_Items[vpos + 2] = v21;
    v23 = effColorMultiply(abgr_in | 0xFF000000, abgr);
    pVC->m_Items[vpos + 3] = v23;
    v20 = 0x80000000;
  }
  else
  {
    v16 = effColorMultiply(0xFF000000, abgr);
    pVC->m_Items[vpos + 2] = v16;
    v18 = effColorMultiply(abgr_in & 0xFFFFFF | 0x40000000, abgr);
    v20 = -16777216;
    pVC->m_Items[vpos + 3] = v18;
  }
  v25 = effColorMultiply(v20, abgr);
  pVC->m_Items[vpos + 4] = v25;
}

// 0x11fb520
void effPCPFlashPolySpherePartSetVertex(effPCPFlashPolySphere_tag **pFlashPoly, s32 number, sdfVector4_t pLook, s32 vpos) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  struct effPCPFlashPolySpherePart_tag_array *pPart;
  effPCPFlashPolySpherePart_tag_o *v14;
  struct UnityEngine_Vector4_array *pVertex;
  f32 v16;
  f32 v18;
  f32 v19;
  f32 v20;
  f32 v21;
  f32 width_in;
  s64 v23;
  f32 v29;
  f32 v30;
  UnityEngine_Vector4_o p;
  f32 v32;
  f32 v33;
  UnityEngine_Vector4_o v34;
  UnityEngine_Vector4_o zero;
  UnityEngine_Vector4_o v36;
  UnityEngine_Vector4_o v37;
  UnityEngine_Vector4_o v38;
  UnityEngine_Vector4_o v39;
  UnityEngine_Vector4_o v40;
  UnityEngine_Vector4_o v41;
  UnityEngine_Vector4_o v42;
  UnityEngine_Vector4_o v43;
  UnityEngine_Vector4_o v44;

  w = pLook.w;
  z = pLook.z;
  y = pLook.y;
  x = pLook.x;
  *&p.x = 0;
  *&p.z = 0;
  pPart = (*pFlashPoly)->pPart;
  v14 = pPart->m_Items[number];
  pVertex = (*pFlashPoly)->hPoly->pVertex;
  v40.w = v14->dir.w;
  v40.x = v14->dir.x;
  v40.z = v14->dir.z;
  v16 = v14->radius / v14->radius_max;
  v32 = v14->dir.y;
  v40.y = v32;
  v33 = v40.x;
  v29 = v40.w;
  v30 = v40.z;
  SDF_VU0__LOADVECTOR(v40);
  v41.x = x;
  v41.y = y;
  v41.z = z;
  v41.w = w;
  SDF_VU0__LOADVECTOR_B(v41);
  SDF_VU0__COPYVECTOR_A_TO_C();
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&p);
  v19 = p.x;
  v18 = p.y;
  v21 = p.z;
  v20 = p.w;
  width_in = v14->width_in;
  v42.x = v19;
  v42.y = v18;
  v42.z = v21;
  v42.w = v20;
  v44 = op_Multiply(v42, width_in, 0);
  v34 = op_Multiply(v44, v16, 0);
  p = op_Multiply(p, v16 * v14->width_out, 0);
  zero = get_zero();
  v23 = vpos + 3LL;
  pVertex->m_Items[v23] = zero;
  pVertex->m_Items[vpos + 2] = v34;
  v36 = op_UnaryNegation(v34);
  pVertex->m_Items[vpos + 4] = v36;
  v43.y = v32;
  v43.x = v33;
  v43.w = v29;
  v43.z = v30;
  v37 = op_Multiply(v43, v14->radius, 0);
  v38 = op_Addition(v37, p);
  pVertex->m_Items[vpos] = v38;
  v39 = op_Subtraction(v37, p);
  pVertex->m_Items[vpos + 1] = v39;
}

// 0x11faec0
void effPCPFlashPolySphereSetColor(void **hData, u32 abgr) {
}

// 0x11fad80
void effPCPFlashPolySphereSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x11fafc0
void effPCPFlashPolySphereSetScale(void **hData, f32 scale) {
}

// 0x11f6c30
f32 fpAlfRaitoGet(void) {
  return fp_alf_raito;
}

// 0x11f6ca0
void fpAlfRaitoSet(f32 raito) {
  fp_alf_raito = raito;
}

// 0x1208a20
s32 fpCutRaitoGet(void) {
  return fp_cut_raito;
}

// 0x12089b0
void fpCutRaitoSet(s32 raito) {
  fp_cut_raito = raito;
}

// 0x11f6d20
void pMeshDelete(dds3FlashPolyList_t **hPoly) {
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

  p_pMesh = &(*hPoly)->pMesh;
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
          pMesh = (*hPoly)->pMesh;
          gameObject = get_gameObject(*(&pMesh->obj.klass + v6), 0);
          Destroy_27360000(gameObject);
          v14 = (*hPoly)->pMesh;
          *(&v14->obj.klass + v6) = 0;
        }
        v4 = (*hPoly)->pMesh;
        max_length = v4->max_length;
        v16 = v6 - 3;
        ++v6;
      }
      while (v16 < max_length);
      p_pMesh = &(*hPoly)->pMesh;
    }
    *p_pMesh = 0;
  }
}
