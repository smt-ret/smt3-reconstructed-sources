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
static sdfVector4_t *dds3FlashPolyListDrawJobV;
static u32 *dds3FlashPolyListDrawJobVC;
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
  sub_11571A0(&this->matrix.m01, *&p);
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
LABEL_10:
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
  f32 *p_SDF_CC_NDNM;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 scale;
  f32 x;
  f32 y;
  f32 w;
  f32 z;
  dds3FlashPolyList_t_o *v17;
  struct XRD773Unity_CommonMesh_array *pMesh;
  XRD773Unity_GraphicManager_o *Instance;
  s64 *Mesh;
  s64 *v22;
  struct XRD773Unity_CommonMesh_array *v24;
  struct XRD773Unity_CommonMesh_array *v26;
  System_Tuple_NativeArray_Vector3___NativeArray_Color___o *NativeArray;
  void *m_Buffer;
  s64 v30;
  s64 v31;
  char *v32;
  dds3FlashPolyList_t_o *v34;
  f32 alf_raito;
  f32 v36;
  struct XRD773Unity_CommonMesh_array *v37;
  s32 point;
  System_Tuple_NativeArray_Vector3___NativeArray_Color___o *v40;
  s64 v41;
  void *v42;
  void *v43;
  Unity_Collections_NativeArray_Color__o v44;
  s64 v45;
  dds3FlashPolyList_t_o *v46;
  struct UnityEngine_Vector4_array *pVertex;
  struct XRD773Unity_CommonMesh_array *v48;
  System_Int32_array *v50;
  u64 v51;
  s32 v52;
  u64 v53;
  u64 max_length_low;
  u32 *v56;
  u32 v59;
  il2cpp_array_size_t max_length;
  s64 v61;
  struct XRD773Unity_CommonMesh_array *v63;
  struct XRD773Unity_CommonMesh_array *v65;
  struct XRD773Unity_CommonMesh_array *v67;
  struct XRD773Unity_CommonMesh_array *v69;
  Unity_Jobs_JobHandle_o v72;
  s64 v73;
  s64 v74;
  s64 v75;
  s64 v76;
  s64 v77;
  s64 v78;
  s64 v79;
  s64 v80;
  effPCPFlash_dds3FlashPolyListDrawJob_o v81;
  UnityEngine_Vector3_o v82;
  Unity_Collections_NativeArray_Color__o Item2;
  Unity_Collections_NativeArray_Vector3__o Item1;
  Unity_Collections_NativeArray_Vector3__o v85;
  Unity_Collections_NativeArray_Color__o v86;
  Unity_Jobs_JobHandle_o v87;
  UnityEngine_Vector4_o v88;
  UnityEngine_Vector3_o v89;
  UnityEngine_Vector3_o v90;
  UnityEngine_Vector3_o v91;
  UnityEngine_Vector4_o v92;
  UnityEngine_Vector4_o zero;
  UnityEngine_Color_o BlendColor;

  v79 = 0;
  v80 = 0;
  v77 = 0;
  v78 = 0;
  v75 = 0;
  v76 = 0;
  v73 = 0;
  v74 = 0;
  v72.jobGroup = 0;
  *&v72.version = 0;
  p_SDF_CC_NDNM = &SDF_CC_NDNM;
  v7 = p_SDF_CC_NDNM[43];
  v8 = p_SDF_CC_NDNM[41];
  v9 = p_SDF_CC_NDNM[42];
  scale = (*hPoly)->scale;
  v89.x = v8;
  v89.y = v9;
  v89.z = v7;
  v82 = op_Multiply(v89, scale, 0);
  Scale(&v81.matrix, v82);
  v75 = *&v81.matrix.m01;
  v76 = *&v81.matrix.m21;
  v73 = *&v81.matrix.m00;
  v74 = *&v81.matrix.m20;
  v79 = *&v81.matrix.m03;
  v80 = *&v81.matrix.m23;
  v77 = *&v81.matrix.m02;
  v78 = *&v81.matrix.m22;
  x = (*hPoly)->pos.x;
  y = (*hPoly)->pos.y;
  z = (*hPoly)->pos.z;
  w = (*hPoly)->pos.w;
  v92.x = x;
  v92.y = y;
  v92.z = z;
  v92.w = w;
  v90 = op_Implicit_8738992(v92);
  v91 = Scale(v90, mod_pos);
  op_Implicit(v91, 0);
  sub_1A009D0(&v73, 3);
  v17 = *hPoly;
  if (!(*hPoly)->pMesh)
  {
    v17->pMesh = NewSpecific(XRD773Unity_CommonMesh, 1u);
    pMesh = (*hPoly)->pMesh;
    {
    }
    Instance = get_Instance();
    Mesh = GetMesh(Instance, (*hPoly)->blend, 0, 0);
    v22 = Mesh;
    pMesh->m_Items[0] = v22;
    v24 = (*hPoly)->pMesh;
    SetAutoHide(v24->m_Items[0], 1);
    v26 = (*hPoly)->pMesh;
    NativeArray = AllocateNativeArray(v26->m_Items[0], (*hPoly)->point, 0);
    m_Buffer = _NativeArray_Color____get_Item1(NativeArray).m_Buffer;
    Item2 = _NativeArray_Color____get_Item2(NativeArray);
    v17 = *hPoly;
    if ((*hPoly)->point > count)
    {
      v30 = m_Buffer + 12 * count + 8;
      v31 = count;
      v32 = Item2.m_Buffer + 16 * count + 8;
      do
      {
        *(v30 - 8) = get_zero();
        zero = get_zero();
        *(v32 - 8) = op_Implicit_27186336(zero);
        ++v31;
        v30 += 12;
        v32 += 16;
        v17 = *hPoly;
      }
      while (v31 < (*hPoly)->point);
    }
  }
  BlendColor = effGetBlendColor(v17->abgr);
  v88 = op_Implicit(BlendColor, 0);
  v34 = *hPoly;
  alf_raito = (*hPoly)->alf_raito;
  if (alf_raito == 0.0)
    v36 = v88.w;
  else
    v36 = v88.w * alf_raito;
  if (v36 > 0.0)
  {
    v37 = v34->pMesh;
    point = v34->point;
    v40 = AllocateNativeArray(v37->m_Items[0], point);
    Item1 = _NativeArray_Color____get_Item1(v40);
    v41 = *&Item1.m_Length;
    v42 = Item1.m_Buffer;
    v44 = _NativeArray_Color____get_Item2(v40);
    v43 = v44.m_Buffer;
    v45 = *&v44.m_Length;
    v46 = *hPoly;
    pVertex = v46->pVertex;
    *(*(v44.m_Buffer + 23) + 16LL) = pVertex;
    *(*(v44.m_Buffer + 23) + 24LL) = v46->pVC;
    *&v81.matrix.m01 = v75;
    *&v81.matrix.m21 = v76;
    v81.pos.m_Buffer = v42;
    *&v81.pos.m_Length = v41;
    v81.color.m_Buffer = v43;
    *&v81.color.m_Length = v45;
    *&v81.matrix.m00 = v73;
    *&v81.matrix.m20 = v74;
    v87.jobGroup = 0;
    *&v87.version = 0;
    *&v81.matrix.m03 = v79;
    *&v81.matrix.m23 = v80;
    v81.blend_col.x = v88.x;
    v81.blend_col.y = v88.y;
    v81.blend_col.z = v88.z;
    v81.blend_col.w = v36;
    *&v81.matrix.m02 = v77;
    *&v81.matrix.m22 = v78;
    v72 = Schedule_effPCPFlash_dds3FlashPolyListDrawJob_(&v81, count, 0, v87);
    ScheduleBatchedJobs();
    v48 = (*hPoly)->pMesh;
    v50 = AlocateIndexTable(v48->m_Items[0], 3 * (point / 3), 0);
    if (count < 3)
    {
      v59 = 0;
      max_length = v50->max_length;
      if (max_length <= 0)
      {
LABEL_68:
        v63 = (*hPoly)->pMesh;
        SetIndexTable(v63->m_Items[0], v50);
        sub_19E2EC0(&v72.jobGroup);
        v65 = (*hPoly)->pMesh;
        v85.m_Buffer = v42;
        *&v85.m_Length = v41;
        SetPosition(v65->m_Items[0], v85, count);
        v67 = (*hPoly)->pMesh;
        v86.m_Buffer = v43;
        *&v86.m_Length = v45;
        SetColor(v67->m_Items[0], v86, count, 0);
        v69 = (*hPoly)->pMesh;
        SetActive(v69->m_Items[0], 1, 0);
        return;
      }
    }
    else
    {
      v51 = 0;
      v52 = count / 3;
      do
      {
        v53 = v51;
        max_length_low = LODWORD(v50->max_length);
        v56 = (v50 + 4 * v53);
        v56[8] = v53;
        v56[9] = v53 + 1;
        v56[10] = v53 + 2;
        --v52;
        v51 = v53 + 3;
      }
      while (v52);
      v59 = v53 + 3;
      max_length = v50->max_length;
      if (v53 + 3 >= max_length)
        goto LABEL_68;
    }
    v61 = 0;
    do
    {
      v50->m_Items[v59 + v61++] = 0;
    }
    while ((v59 + v61) < max_length);
    goto LABEL_68;
  }
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
LABEL_10:
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
  f32 *p_SDF_CC_NDNM;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 scale;
  f32 x;
  f32 y;
  f32 w;
  f32 z;
  dds3FlashPolyList_t_o *v17;
  struct XRD773Unity_CommonMesh_array *pMesh;
  XRD773Unity_GraphicManager_o *Instance;
  s64 *Mesh;
  s64 *v22;
  struct XRD773Unity_CommonMesh_array *v24;
  struct XRD773Unity_CommonMesh_array *v26;
  System_Tuple_NativeArray_Vector3___NativeArray_Color___o *NativeArray;
  void *m_Buffer;
  s64 v30;
  s64 v31;
  char *v32;
  dds3FlashPolyList_t_o *v34;
  f32 alf_raito;
  f32 v36;
  struct XRD773Unity_CommonMesh_array *v37;
  s32 point;
  System_Tuple_NativeArray_Vector3___NativeArray_Color___o *v40;
  s64 v41;
  void *v42;
  void *v43;
  Unity_Collections_NativeArray_Color__o v44;
  s64 v45;
  dds3FlashPolyList_t_o *v46;
  struct UnityEngine_Vector4_array *pVertex;
  struct XRD773Unity_CommonMesh_array *v48;
  System_Int32_array *v50;
  s32 v51;
  u64 v52;
  s32 v53;
  s32 *v54;
  u64 v55;
  u64 max_length_low;
  s32 v59;
  s32 v61;
  s32 v63;
  s32 v65;
  s32 v67;
  s32 v69;
  s32 v71;
  s32 v73;
  s32 v75;
  s32 v77;
  u32 v79;
  il2cpp_array_size_t max_length;
  s64 v81;
  struct XRD773Unity_CommonMesh_array *v83;
  struct XRD773Unity_CommonMesh_array *v85;
  struct XRD773Unity_CommonMesh_array *v87;
  struct XRD773Unity_CommonMesh_array *v89;
  void *v92;
  s64 v93;
  Unity_Jobs_JobHandle_o v94;
  s64 v95;
  s64 v96;
  s64 v97;
  s64 v98;
  s64 v99;
  s64 v100;
  s64 v101;
  s64 v102;
  effPCPFlash_dds3FlashPolyListDrawJob_o v103;
  UnityEngine_Vector3_o v104;
  Unity_Collections_NativeArray_Color__o Item2;
  Unity_Collections_NativeArray_Vector3__o Item1;
  Unity_Collections_NativeArray_Vector3__o v107;
  Unity_Collections_NativeArray_Color__o v108;
  Unity_Jobs_JobHandle_o v109;
  UnityEngine_Vector4_o v110;
  UnityEngine_Vector3_o v111;
  UnityEngine_Vector3_o v112;
  UnityEngine_Vector3_o v113;
  UnityEngine_Vector4_o v114;
  UnityEngine_Vector4_o zero;
  UnityEngine_Color_o BlendColor;

  v101 = 0;
  v102 = 0;
  v99 = 0;
  v100 = 0;
  v97 = 0;
  v98 = 0;
  v95 = 0;
  v96 = 0;
  v94.jobGroup = 0;
  *&v94.version = 0;
  p_SDF_CC_NDNM = &SDF_CC_NDNM;
  v7 = p_SDF_CC_NDNM[43];
  v8 = p_SDF_CC_NDNM[41];
  v9 = p_SDF_CC_NDNM[42];
  scale = (*hPoly)->scale;
  v111.x = v8;
  v111.y = v9;
  v111.z = v7;
  v104 = op_Multiply(v111, scale, 0);
  Scale(&v103.matrix, v104);
  v97 = *&v103.matrix.m01;
  v98 = *&v103.matrix.m21;
  v95 = *&v103.matrix.m00;
  v96 = *&v103.matrix.m20;
  v101 = *&v103.matrix.m03;
  v102 = *&v103.matrix.m23;
  v99 = *&v103.matrix.m02;
  v100 = *&v103.matrix.m22;
  x = (*hPoly)->pos.x;
  y = (*hPoly)->pos.y;
  z = (*hPoly)->pos.z;
  w = (*hPoly)->pos.w;
  v114.x = x;
  v114.y = y;
  v114.z = z;
  v114.w = w;
  v112 = op_Implicit_8738992(v114);
  v113 = Scale(v112, mod_pos);
  op_Implicit(v113, 0);
  sub_1A009D0(&v95, 3);
  v17 = *hPoly;
  if (!(*hPoly)->pMesh)
  {
    v17->pMesh = NewSpecific(XRD773Unity_CommonMesh, 1u);
    pMesh = (*hPoly)->pMesh;
    {
    }
    Instance = get_Instance();
    Mesh = GetMesh(Instance, (*hPoly)->blend, 0, 0);
    v22 = Mesh;
    pMesh->m_Items[0] = v22;
    v24 = (*hPoly)->pMesh;
    SetAutoHide(v24->m_Items[0], 1);
    v26 = (*hPoly)->pMesh;
    NativeArray = AllocateNativeArray(v26->m_Items[0], (*hPoly)->point, 0);
    m_Buffer = _NativeArray_Color____get_Item1(NativeArray).m_Buffer;
    Item2 = _NativeArray_Color____get_Item2(NativeArray);
    v17 = *hPoly;
    if ((*hPoly)->point > count)
    {
      v30 = m_Buffer + 12 * count + 8;
      v31 = count;
      v32 = Item2.m_Buffer + 16 * count + 8;
      do
      {
        *(v30 - 8) = get_zero();
        zero = get_zero();
        *(v32 - 8) = op_Implicit_27186336(zero);
        ++v31;
        v30 += 12;
        v32 += 16;
        v17 = *hPoly;
      }
      while (v31 < (*hPoly)->point);
    }
  }
  BlendColor = effGetBlendColor(v17->abgr);
  v110 = op_Implicit(BlendColor, 0);
  v34 = *hPoly;
  alf_raito = (*hPoly)->alf_raito;
  if (alf_raito == 0.0)
    v36 = v110.w;
  else
    v36 = v110.w * alf_raito;
  if (v36 > 0.0)
  {
    v37 = v34->pMesh;
    point = v34->point;
    v40 = AllocateNativeArray(v37->m_Items[0], point);
    Item1 = _NativeArray_Color____get_Item1(v40);
    v41 = *&Item1.m_Length;
    v42 = Item1.m_Buffer;
    v44 = _NativeArray_Color____get_Item2(v40);
    v43 = v44.m_Buffer;
    v45 = *&v44.m_Length;
    v46 = *hPoly;
    pVertex = v46->pVertex;
    *(*(v44.m_Buffer + 23) + 16LL) = pVertex;
    *(*(v44.m_Buffer + 23) + 24LL) = v46->pVC;
    *&v103.matrix.m01 = v97;
    *&v103.matrix.m21 = v98;
    v103.pos.m_Buffer = v42;
    *&v103.pos.m_Length = v41;
    v103.color.m_Buffer = v43;
    *&v103.color.m_Length = v45;
    *&v103.matrix.m00 = v95;
    *&v103.matrix.m20 = v96;
    v109.jobGroup = 0;
    *&v109.version = 0;
    *&v103.matrix.m03 = v101;
    *&v103.matrix.m23 = v102;
    v103.blend_col.x = v110.x;
    v103.blend_col.y = v110.y;
    v103.blend_col.z = v110.z;
    v103.blend_col.w = v36;
    *&v103.matrix.m02 = v99;
    *&v103.matrix.m22 = v100;
    v94 = Schedule_effPCPFlash_dds3FlashPolyListDrawJob_(&v103, count, 0, v109);
    ScheduleBatchedJobs();
    v48 = (*hPoly)->pMesh;
    v93 = v45;
    v50 = AlocateIndexTable(v48->m_Items[0], 12 * (point / 5), 0);
    if (count < 5)
    {
      v79 = 0;
      max_length = v50->max_length;
      if (max_length <= 0)
      {
LABEL_86:
        v83 = (*hPoly)->pMesh;
        SetIndexTable(v83->m_Items[0], v50);
        sub_19E2EC0(&v94.jobGroup);
        v85 = (*hPoly)->pMesh;
        v107.m_Buffer = v42;
        *&v107.m_Length = v41;
        SetPosition(v85->m_Items[0], v107, count);
        v87 = (*hPoly)->pMesh;
        v108.m_Buffer = v43;
        *&v108.m_Length = v93;
        SetColor(v87->m_Items[0], v108, count, 0);
        v89 = (*hPoly)->pMesh;
        SetActive(v89->m_Items[0], 1, 0);
        return;
      }
    }
    else
    {
      v51 = count / 5;
      v52 = 0;
      v53 = 0;
      v54 = &v50->m_Items[2];
      v92 = v43;
      do
      {
        v55 = v52;
        max_length_low = LODWORD(v50->max_length);
        *(v54 - 2) = v53;
        v59 = v53 + 2;
        *(v54 - 1) = v59;
        v61 = v59 - 1;
        *v54 = v61;
        v63 = v61 - 1;
        v54[1] = v63;
        v65 = v63 + 3;
        v54[2] = v65;
        v67 = v65 - 1;
        v54[3] = v67;
        v69 = v67 + 2;
        v54[4] = v69;
        v71 = v69 - 3;
        v54[5] = v71;
        v73 = v71 + 1;
        v54[6] = v73;
        v75 = v73 + 2;
        v54[7] = v75;
        v77 = v75 - 2;
        v54[8] = v77;
        --v51;
        v54[9] = v77 + 1;
        v54 += 12;
        v52 = v55 + 12;
        v53 = v77 + 3;
      }
      while (v51);
      v79 = v55 + 12;
      v43 = v92;
      max_length = v50->max_length;
      if (v79 >= max_length)
        goto LABEL_86;
    }
    v81 = 0;
    do
    {
      v50->m_Items[v79 + v81++] = 0;
    }
    while ((v79 + v81) < max_length);
    goto LABEL_86;
  }
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
LABEL_10:
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
  f32 *p_SDF_CC_NDNM;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 scale;
  f32 x;
  f32 y;
  f32 w;
  f32 z;
  dds3FlashPolyList_t_o *v18;
  s32 blend;
  struct XRD773Unity_CommonMesh_array *pMesh;
  XRD773Unity_GraphicManager_o *Instance;
  s64 *Mesh;
  s64 *v25;
  struct XRD773Unity_CommonMesh_array *v27;
  struct XRD773Unity_CommonMesh_array *v29;
  System_Tuple_NativeArray_Vector3___NativeArray_Color___o *NativeArray;
  void *m_Buffer;
  s64 v33;
  s64 v34;
  char *v35;
  dds3FlashPolyList_t_o *v37;
  f32 alf_raito;
  f32 v39;
  s32 point;
  struct XRD773Unity_CommonMesh_array *v41;
  XRD773Unity_CommonMesh_o *v43;
  System_Tuple_NativeArray_Vector3___NativeArray_Color___o *v44;
  s64 v45;
  void *v46;
  void *v47;
  Unity_Collections_NativeArray_Color__o v48;
  s64 v49;
  dds3FlashPolyList_t_o *v50;
  struct UnityEngine_Vector4_array *pVertex;
  System_Int32_array *v52;
  u32 v53;
  s32 v54;
  u64 v55;
  s32 v56;
  s32 *v57;
  u64 v58;
  u64 max_length_low;
  s32 v62;
  s32 v64;
  s32 v66;
  s32 v68;
  s32 v70;
  s32 v72;
  s32 v74;
  s32 v76;
  il2cpp_array_size_t max_length;
  s64 v78;
  void *v81;
  s64 pos;
  Unity_Jobs_JobHandle_o v83;
  s64 v84;
  s64 v85;
  s64 v86;
  s64 v87;
  s64 v88;
  s64 v89;
  s64 v90;
  s64 v91;
  effPCPFlash_dds3FlashPolyListDrawJob_o v92;
  UnityEngine_Vector3_o v93;
  Unity_Collections_NativeArray_Color__o Item2;
  Unity_Collections_NativeArray_Vector3__o Item1;
  Unity_Collections_NativeArray_Vector3__o v96;
  Unity_Collections_NativeArray_Color__o v97;
  Unity_Jobs_JobHandle_o v98;
  UnityEngine_Vector4_o v99;
  UnityEngine_Vector3_o v100;
  UnityEngine_Vector3_o v101;
  UnityEngine_Vector3_o v102;
  UnityEngine_Vector4_o v103;
  UnityEngine_Vector4_o zero;
  UnityEngine_Color_o BlendColor;

  v90 = 0;
  v91 = 0;
  v88 = 0;
  v89 = 0;
  v86 = 0;
  v87 = 0;
  v84 = 0;
  v85 = 0;
  v83.jobGroup = 0;
  *&v83.version = 0;
  p_SDF_CC_NDNM = &SDF_CC_NDNM;
  v8 = p_SDF_CC_NDNM[43];
  v9 = p_SDF_CC_NDNM[41];
  v10 = p_SDF_CC_NDNM[42];
  scale = (*hPoly)->scale;
  v100.x = v9;
  v100.y = v10;
  v100.z = v8;
  v93 = op_Multiply(v100, scale, 0);
  Scale(&v92.matrix, v93);
  v86 = *&v92.matrix.m01;
  v87 = *&v92.matrix.m21;
  v84 = *&v92.matrix.m00;
  v85 = *&v92.matrix.m20;
  v90 = *&v92.matrix.m03;
  v91 = *&v92.matrix.m23;
  v88 = *&v92.matrix.m02;
  v89 = *&v92.matrix.m22;
  x = (*hPoly)->pos.x;
  y = (*hPoly)->pos.y;
  z = (*hPoly)->pos.z;
  w = (*hPoly)->pos.w;
  v103.x = x;
  v103.y = y;
  v103.z = z;
  v103.w = w;
  v101 = op_Implicit_8738992(v103);
  v102 = Scale(v101, mod_pos);
  op_Implicit(v102, 0);
  sub_1A009D0(&v84, 3);
  v18 = *hPoly;
  if (!(*hPoly)->pMesh)
  {
    blend = v18->blend;
    v18->pMesh = NewSpecific(XRD773Unity_CommonMesh, 1u);
    else if (!effBTLSkillCheckRun2(0x22u))
    {
LABEL_19:
      if (!effBTLSkillCheckRun2(0x20u))
        goto LABEL_26;
    }
    blend = 1;
LABEL_26:
    pMesh = (*hPoly)->pMesh;
    {
    }
    Instance = get_Instance();
    Mesh = GetMesh(Instance, blend, 0);
    v25 = Mesh;
    pMesh->m_Items[0] = v25;
    v27 = (*hPoly)->pMesh;
    SetAutoHide(v27->m_Items[0], 1);
    v29 = (*hPoly)->pMesh;
    NativeArray = AllocateNativeArray(v29->m_Items[0], (*hPoly)->point, 0);
    m_Buffer = _NativeArray_Color____get_Item1(NativeArray).m_Buffer;
    Item2 = _NativeArray_Color____get_Item2(NativeArray);
    v18 = *hPoly;
    if ((*hPoly)->point > count)
    {
      v33 = m_Buffer + 12 * count + 8;
      v34 = count;
      v35 = Item2.m_Buffer + 16 * count + 8;
      do
      {
        *(v33 - 8) = get_zero();
        zero = get_zero();
        *(v35 - 8) = op_Implicit_27186336(zero);
        ++v34;
        v33 += 12;
        v35 += 16;
        v18 = *hPoly;
      }
      while (v34 < (*hPoly)->point);
    }
  }
  BlendColor = effGetBlendColor(v18->abgr);
  v99 = op_Implicit(BlendColor, 0);
  v37 = *hPoly;
  alf_raito = (*hPoly)->alf_raito;
  if (alf_raito == 0.0)
    v39 = v99.w;
  else
    v39 = v99.w * alf_raito;
  if (v39 > 0.0)
  {
    point = v37->point;
    if (point)
    {
      v41 = v37->pMesh;
      v43 = v41->m_Items[0];
      v44 = AllocateNativeArray(v43, point);
      Item1 = _NativeArray_Color____get_Item1(v44);
      v45 = *&Item1.m_Length;
      v46 = Item1.m_Buffer;
      v48 = _NativeArray_Color____get_Item2(v44);
      v47 = v48.m_Buffer;
      v49 = *&v48.m_Length;
      v50 = *hPoly;
      pVertex = v50->pVertex;
      *(*(v48.m_Buffer + 23) + 16LL) = pVertex;
      *(*(v48.m_Buffer + 23) + 24LL) = v50->pVC;
      *&v92.matrix.m01 = v86;
      *&v92.matrix.m21 = v87;
      v92.pos.m_Buffer = v46;
      *&v92.pos.m_Length = v45;
      v92.color.m_Buffer = v47;
      *&v92.color.m_Length = v49;
      *&v92.matrix.m00 = v84;
      *&v92.matrix.m20 = v85;
      v98.jobGroup = 0;
      *&v98.version = 0;
      *&v92.matrix.m03 = v90;
      *&v92.matrix.m23 = v91;
      v92.blend_col.x = v99.x;
      v92.blend_col.y = v99.y;
      v92.blend_col.z = v99.z;
      v92.blend_col.w = v39;
      *&v92.matrix.m02 = v88;
      *&v92.matrix.m22 = v89;
      pos = v45;
      v83 = Schedule_effPCPFlash_dds3FlashPolyListDrawJob_(&v92, count, 0, v98);
      ScheduleBatchedJobs();
      v52 = AlocateIndexTable(v43, 9 * (point / 5), 0);
      v53 = 0;
      if (count >= 5)
      {
        v54 = count / 5;
        v55 = 0;
        v56 = 0;
        v57 = &v52->m_Items[8];
        v81 = v46;
        do
        {
          v58 = v55;
          max_length_low = LODWORD(v52->max_length);
          *(v57 - 8) = v56;
          v62 = v56 + 3;
          *(v57 - 7) = v62;
          v64 = v62 - 1;
          *(v57 - 6) = v64;
          v66 = v64 - 2;
          *(v57 - 5) = v66;
          v68 = v66 + 1;
          *(v57 - 4) = v68;
          v70 = v68 + 2;
          *(v57 - 3) = v70;
          v72 = v70 - 2;
          *(v57 - 2) = v72;
          v74 = v72 + 3;
          *(v57 - 1) = v74;
          v76 = v74 - 1;
          --v54;
          v55 = v58 + 9;
          v56 = v74 + 1;
          *v57 = v76;
          v57 += 9;
        }
        while (v54);
        v53 = v58 + 9;
        v46 = v81;
      }
      max_length = v52->max_length;
      if (v53 < max_length)
      {
        v78 = 0;
        do
        {
          v52->m_Items[v53 + v78++] = 0;
        }
        while ((v53 + v78) < max_length);
      }
      SetIndexTable(v43, v52);
      sub_19E2EC0(&v83.jobGroup);
      *&v96.m_Length = pos;
      v96.m_Buffer = v46;
      SetPosition(v43, v96, count);
      v97.m_Buffer = v47;
      *&v97.m_Length = v49;
      SetColor(v43, v97, count, 0);
      SetActive(v43, 1, 0);
    }
  }
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
  s64 v7;
  s64 v8;
  s64 v9;
  s64 v10;
  s64 v11;
  s64 v12;
  s64 v13;
  f32 x;
  f32 y;
  f32 w;
  f32 z;
  f32 v22;
  f32 v23;
  f32 v24;
  dds3FlashPolyList_t_o *v25;
  struct XRD773Unity_CommonMesh_array *pMesh;
  XRD773Unity_GraphicManager_o *Instance;
  s64 *Mesh;
  s64 *v30;
  struct XRD773Unity_CommonMesh_array *v32;
  XRD773Unity_CommonMesh_o *v34;
  UnityEngine_Vector3_array *v35;
  struct XRD773Unity_CommonMesh_array *v36;
  XRD773Unity_CommonMesh_o *v38;
  UnityEngine_Color_array *v39;
  struct XRD773Unity_CommonMesh_array *v40;
  XRD773Unity_CommonMesh_o *v42;
  System_Int32_array *v43;
  struct XRD773Unity_CommonMesh_array *v44;
  f32 alf_raito;
  f32 v47;
  dds3FlashPolyList_t_o *v50;
  struct UnityEngine_Vector4_array *pVertex;
  struct XRD773Unity_CommonMesh_array *v52;
  System_Int32_array *IndexTable;
  s32 v55;
  u64 v56;
  s32 v57;
  s32 *v58;
  u64 v59;
  u64 max_length_low;
  s32 v63;
  s32 v65;
  s32 v67;
  s32 v69;
  s32 v71;
  s32 v73;
  s32 v75;
  s32 v77;
  u32 v78;
  il2cpp_array_size_t max_length;
  s64 v80;
  struct XRD773Unity_CommonMesh_array *v82;
  struct XRD773Unity_CommonMesh_array *v84;
  s64 v85;
  void *m_Buffer;
  UnityEngine_Vector3_array *Position;
  struct XRD773Unity_CommonMesh_array *v89;
  s64 v90;
  void *v91;
  UnityEngine_Color_array *Color;
  struct XRD773Unity_CommonMesh_array *v94;
  UnityEngine_Matrix4x4_o v97;
  UnityEngine_Matrix4x4_o matrix;
  UnityEngine_Matrix4x4_o v99;
  UnityEngine_Matrix4x4_o v100;
  Unity_Jobs_JobHandle_o v101;
  struct Unity_Collections_NativeArray_Color__o v102;
  struct Unity_Collections_NativeArray_Vector3__o v103;
  UnityEngine_Matrix4x4_o v104;
  effPCPFlash_dds3FlashPolyListDrawJob_o v105;
  UnityEngine_Vector3_o v106;
  Unity_Collections_NativeArray_T__o v107;
  Unity_Collections_NativeArray_T__o v108;
  Unity_Jobs_JobHandle_o v109;
  UnityEngine_Vector4_o v110;
  UnityEngine_Vector3_o v111;
  UnityEngine_Vector3_o v112;
  UnityEngine_Vector4_o v113;
  UnityEngine_Color_o BlendColor;

  memset(&v104, 0, sizeof(v104));
  v103.m_Buffer = 0;
  *&v103.m_Length = 0;
  v102.m_Buffer = 0;
  *&v102.m_Length = 0;
  v101.jobGroup = 0;
  *&v101.version = 0;
  v7 = *&mod_p_matrix.m00;
  v8 = *&mod_p_matrix.m20;
  v9 = *&mod_p_matrix.m21;
  *&v105.matrix.m01 = *&mod_p_matrix.m01;
  *&v105.matrix.m21 = v9;
  *&v105.matrix.m00 = v7;
  *&v105.matrix.m20 = v8;
  v10 = *&mod_p_matrix.m02;
  v11 = *&mod_p_matrix.m22;
  v13 = *&mod_p_matrix.m03;
  v12 = *&mod_p_matrix.m23;
  *&v105.matrix.m03 = v13;
  *&v105.matrix.m23 = v12;
  *&v105.matrix.m02 = v10;
  *&v105.matrix.m22 = v11;
  sub_19FF440(&(*hPoly)->fields, 0, &v100);
  matrix = v105.matrix;
  v97 = v100;
  op_Multiply(&v99, &matrix, &v97, 0);
  v104 = v99;
  x = (*hPoly)->pos.x;
  y = (*hPoly)->pos.y;
  z = (*hPoly)->pos.z;
  w = (*hPoly)->pos.w;
  v113.x = x;
  v113.y = y;
  v113.z = z;
  v113.w = w;
  v106 = op_Implicit_8738992(v113);
  v22 = mod_pos.x;
  v23 = mod_pos.y;
  v24 = mod_pos.z;
  v112.x = v22;
  v112.y = v23;
  v112.z = v24;
  v111 = Scale(v106, v112);
  op_Implicit(v111, 0);
  sub_1A009D0(&v104, 3);
  v25 = *hPoly;
  if (!(*hPoly)->pMesh)
  {
    v25->pMesh = NewSpecific(XRD773Unity_CommonMesh, 1u);
    pMesh = (*hPoly)->pMesh;
    {
    }
    Instance = get_Instance();
    Mesh = GetMesh(Instance, (*hPoly)->blend, 0, 0);
    v30 = Mesh;
    pMesh->m_Items[0] = v30;
    v32 = (*hPoly)->pMesh;
    v34 = v32->m_Items[0];
    v35 = NewSpecific(UnityEngine_Vector3, (*hPoly)->point);
    SetPosition_20241056(v34, v35);
    v36 = (*hPoly)->pMesh;
    v38 = v36->m_Items[0];
    v39 = NewSpecific(UnityEngine_Color, (*hPoly)->point);
    SetColor_20241296(v38, v39);
    v40 = (*hPoly)->pMesh;
    v42 = v40->m_Items[0];
    v43 = NewSpecific(s32, (9 * ((*hPoly)->point / 5)));
    SetIndexTable(v42, v43);
    v44 = (*hPoly)->pMesh;
    SetAutoHide(v44->m_Items[0], 1);
    v25 = *hPoly;
  }
  BlendColor = effGetBlendColor(v25->abgr);
  v110 = op_Implicit(BlendColor, 0);
  alf_raito = (*hPoly)->alf_raito;
  if (alf_raito == 0.0)
    v47 = v110.w;
  else
    v47 = v110.w * alf_raito;
  if (v47 > 0.0)
  {
    sub_7FCEE0(&v103, count, 3u, 1);
    sub_7FBAE0(&v102, count, 3u, 1);
    v50 = *hPoly;
    pVertex = v50->pVertex;
    dds3FlashPolyListDrawJobV = pVertex;
    dds3FlashPolyListDrawJobVC = v50->pVC;
    v105.blend_col.x = v110.x;
    v105.blend_col.y = v110.y;
    v105.blend_col.z = v110.z;
    v105.blend_col.w = v47;
    v105.matrix = v104;
    v109.jobGroup = 0;
    *&v109.version = 0;
    v105.pos = v103;
    v105.color = v102;
    v101 = Schedule_effPCPFlash_dds3FlashPolyListDrawJob_(&v105, count, 0, v109);
    ScheduleBatchedJobs();
    v52 = (*hPoly)->pMesh;
    IndexTable = GetIndexTable(v52->m_Items[0]);
    if (count < 5)
    {
      v78 = 0;
      max_length = IndexTable->max_length;
      if (max_length <= 0)
      {
LABEL_74:
        v82 = (*hPoly)->pMesh;
        SetIndexTable(v82->m_Items[0], IndexTable);
        sub_19E2EC0(&v101.jobGroup);
        v84 = (*hPoly)->pMesh;
        m_Buffer = v103.m_Buffer;
        v85 = *&v103.m_Length;
        Position = GetPosition(v84->m_Items[0]);
        v107.m_Buffer = m_Buffer;
        *&v107.m_Length = v85;
        _Copy_8378240(v107, 0, Position, 0, count);
        v89 = (*hPoly)->pMesh;
        v91 = v102.m_Buffer;
        v90 = *&v102.m_Length;
        Color = GetColor(v89->m_Items[0], 0);
        v108.m_Buffer = v91;
        *&v108.m_Length = v90;
        _Copy_8373120(v108, 0, Color, 0, count);
        sub_7FD250(&v103);
        sub_7FBE50(&v102);
        v94 = (*hPoly)->pMesh;
        SetActive(v94->m_Items[0], 1, 0);
        return;
      }
    }
    else
    {
      v55 = count / 5;
      v56 = 0;
      v57 = 0;
      v58 = &IndexTable->m_Items[8];
      do
      {
        v59 = v56;
        max_length_low = LODWORD(IndexTable->max_length);
        *(v58 - 8) = v57;
        v63 = v57 + 3;
        *(v58 - 7) = v63;
        v65 = v63 - 1;
        *(v58 - 6) = v65;
        v67 = v65 - 2;
        *(v58 - 5) = v67;
        v69 = v67 + 1;
        *(v58 - 4) = v69;
        v71 = v69 + 2;
        *(v58 - 3) = v71;
        v73 = v71 - 2;
        *(v58 - 2) = v73;
        v75 = v73 + 3;
        *(v58 - 1) = v75;
        v77 = v75 - 1;
        --v55;
        v56 = v59 + 9;
        v57 = v75 + 1;
        *v58 = v77;
        v58 += 9;
      }
      while (v55);
      v78 = v59 + 9;
      max_length = IndexTable->max_length;
      if (v59 + 9 >= max_length)
        goto LABEL_74;
    }
    v80 = 0;
    do
    {
      IndexTable->m_Items[v78 + v80++] = 0;
    }
    while ((v78 + v80) < max_length);
    goto LABEL_74;
  }
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
  effPCPFlashPolyCircle_tag_c *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v8;
  char *v10;
  s64 *v11;
  u64 v12[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyCircle_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyCircle_tag, v12);
    if ((v12[0] & 1) != 0)
      v10 = v12[2];
    else
      v10 = v12 + 1;
    v11 = sub_8C4940(v10);
  }
  v8 = (*hData)[1].klass;
  return effPCPFlashPolyCircleCreate(v8, v5);
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
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v11[3];

  v5 = *pData;
  else if (!v5)
  {
    return effPCPFlashPolyCircleCreate(v5, *&bPos);
  }
  klass = v5->klass;
  if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyCircleParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyCircleParam_t, v11);
    if ((v11[0] & 1) != 0)
      v8 = v11[2];
    else
      v8 = v11 + 1;
    v9 = sub_8C4940(v8);
  }
  return effPCPFlashPolyCircleCreate(v5, *&bPos);
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
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3FlashPolyList_t_o **v8;
  dds3FlashPolyList_t_o *hPoly[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyCircle_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyCircle_tag, hPoly);
      if ((hPoly[0] & 1) != 0)
        v6 = hPoly[2];
      else
        v6 = hPoly + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = &v3[3];
  pMeshDelete(v8);
  hPoly[0] = *v8;
  pMeshDelete(hPoly);
}

// 0x1206c40
void effPCPFlashPolyCircleDraw(void **hData) {
  effPCPFlashPolyCircle_tag_o *v3;
  effPCPFlashPolyCircle_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  struct effPCPFlashPolyCircleParam_t_o *param;
  s64 number;
  s32 life;
  s32 abgr_s;
  f32 abgr_e;
  f32 radius_a;
  s32 loop;
  u64 v18;
  s32 v19;
  struct effPCPFlashPolyCirclePart_tag_array *pPart;
  effPCPFlashPolyCirclePart_tag_o *v22;
  s32 frame;
  s32 v24;
  f32 v25;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  f32 v30;
  s32 v31;
  u32 v32;
  s64 v33;
  u32 v35;
  dds3FlashPolyList_t_o **p_hPoly;
  struct dds3FlashPolyList_t_o *hPoly;
  s64 p_pos;
  s64 v39;
  s32 v42;
  f32 radius_s;
  f32 radius;
  u32 abgr1;
  UnityEngine_Vector4_o p;
  effPCPFlashPolyCircle_tag_o *pFlashPoly;
  u64 v48[3];
  UnityEngine_Vector4_o v49;

  *&p.z = 0;
  pFlashPoly = 0;
  *&p.x = 0;
  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyCircle_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyCircle_tag, v48);
      if ((v48[0] & 1) != 0)
        v6 = v48[2];
      else
        v6 = v48 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  pFlashPoly = v3;
  SDF_VU0__LOADVECTOR(dds3CameraTargetPos);
  SDF_VU0__LOADVECTOR_B(dds3CameraEyePos);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&p);
  param = v3->param;
  number = param->number;
  if (number >= 1)
  {
    radius = param->radius;
    radius_s = param->radius_s;
    life = param->life;
    abgr_s = param->abgr_s;
    abgr_e = param->abgr_e;
    v42 = param->abgr_e;
    radius_a = param->radius_a;
    loop = param->loop;
    v18 = 0;
    v19 = 0;
    abgr1 = v3->abgr;
    while (1)
    {
      pPart = v3->pPart;
      v22 = pPart->m_Items[v18];
      frame = v22->frame;
      v24 = life - frame;
      if (life < frame)
        goto LABEL_39;
      if (!frame)
        break;
      if (frame < 1)
        goto LABEL_27;
      v25 = v22->radius_s;
      v22->radius = v22->radius + v25;
      v22->radius_s = radius_a * v25;
      x = p.x;
      y = p.y;
      z = p.z;
      w = p.w;
      v49.x = x;
      v49.y = y;
      v49.z = z;
      v49.w = w;
      effPCPFlashPolyCirclePartSetVertex(&pFlashPoly, v18, v49, v19);
      if (abgr_s && frame < abgr_s)
      {
        v30 = frame / abgr_s;
      }
      else
      {
        v30 = 1.0;
        if (v42)
        {
          v30 = 1.0;
          if (v24 <= v42)
            v30 = v24 / abgr_e;
        }
      }
      v32 = effColorBlend(0, v22->abgr, v30);
      v35 = effColorMultiply(v32, abgr1);
      effPCPFlashPolyCirclePartSetVC(&pFlashPoly, v33, v35, v19);
      v19 += 3;
      if (!loop)
      {
LABEL_37:
        v31 = v22->frame + 1;
        goto LABEL_38;
      }
LABEL_28:
      if (life != frame)
        goto LABEL_37;
      v31 = 0;
LABEL_38:
      v22->frame = v31;
LABEL_39:
      if (number == ++v18)
      {
        param = v3->param;
        goto LABEL_42;
      }
    }
    v22->radius = radius;
    v22->radius_s = radius_s;
    v22->abgr = -2139062144;
LABEL_27:
    if (!loop)
      goto LABEL_37;
    goto LABEL_28;
  }
  v19 = 0;
LABEL_42:
  hPoly = v3->hPoly;
  p_hPoly = &v3->hPoly;
  ++*(p_hPoly - 4);
  sub_854710(&param->fields, 0);
  sub_854710(&p, 0);
  sub_854930(&hPoly->pos, 0);
  p_pos = &(*p_hPoly)->pos;
  sub_854710(&(*(p_hPoly - 4))->fields, 1u);
  sub_854710(&p, 1u);
  sub_854930(p_pos, 1u);
  v39 = &(*p_hPoly)->pos;
  sub_854710(&(*(p_hPoly - 4))->fields, 2u);
  sub_854710(&p, 2u);
  sub_854930(v39, 2u);
  (*p_hPoly)->scale = *(p_hPoly - 2);
  if (v19 >= 1)
  {
    dds3FlashPolyList2Draw(p_hPoly, v19);
  }
}

// 0x1206b20
void effPCPFlashPolyCircleDrawOff(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3FlashPolyList_t_o **v8;
  u64 v9[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyCircle_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyCircle_tag, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = &v3[3];
  dds3FlashPolyList2DrawOff(v8);
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
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  effPCPFlashPolyCircle_tag_o *v12;
  struct effPCPFlashPolyCirclePart_tag_array *pPart;
  effPCPFlashPolyCirclePart_tag_o *v15;
  f32 v16;
  f32 v17;
  struct UnityEngine_Vector4_array *pVertex;
  struct effPCPFlash_StaticFields *static_fields;
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
  f32 v35;
  f32 v36;
  f32 v37;
  f32 v38;
  f32 radius;
  f32 *v41;
  f32 v42;
  f32 v45;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v47;
  f32 v48;
  f32 v49;
  UnityEngine_Vector4_o v50;
  UnityEngine_Vector4_o v51;
  UnityEngine_Vector4_o zero;
  UnityEngine_Vector4_o v53;
  UnityEngine_Vector4_o v54;
  UnityEngine_Vector4_o v55;
  UnityEngine_Vector4_o v56;
  UnityEngine_Vector4_o v57;

  w = pLook.w;
  z = pLook.z;
  y = pLook.y;
  x = pLook.x;
  *&v47.x = 0;
  *&v47.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  v12 = *pFlashPoly;
  pPart = (*pFlashPoly)->pPart;
  v15 = pPart->m_Items[number];
  LODWORD(pLook.x) = v12->param->number;
  v16 = *&pLook.x;
  v17 = 6.2832 / v16;
  pVertex = v12->hPoly->pVertex;
  sub_854690(&v47.x, 0.0, 0.0, 0.0, 0.0);
  v48 = v17;
  v22 = def_dir.x;
  v23 = def_dir.y;
  v24 = v17 * number;
  v25 = def_dir.z;
  *&static_fields = def_dir.w;
  p.x = v22;
  p.y = v23;
  p.z = v25;
  LODWORD(p.w) = static_fields;
  v26 = v22;
  v27 = v23;
  v28 = v25;
  v29 = *&static_fields;
  v56.x = x;
  v56.y = y;
  v56.z = z;
  v56.w = w;
  v45 = v24;
  SetRotateMatrixAxis(v24, v56);
  v53.x = v26;
  v53.y = v27;
  v53.z = v28;
  v53.w = v29;
  SDF_VU0__LOADVECTOR(v53);
  v54.x = x;
  v54.y = y;
  v54.z = z;
  v54.w = w;
  v49 = x;
  v31 = y;
  v32 = z;
  v33 = w;
  SDF_VU0__LOADVECTOR_B(v54);
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&p);
  SDF_VU0__APPLYMATRIX_XYZ();
  SDF_VU0__STOREVECTOR(&v47);
  v36 = v47.x;
  v35 = v47.y;
  v38 = v47.z;
  v37 = v47.w;
  radius = v15->radius;
  v55.x = v36;
  v55.y = v35;
  v55.z = v38;
  v55.w = v37;
  v50 = op_Multiply(v55, radius, 0);
  v41 = (&pVertex->obj + vpos);
  v41[8] = v50.x;
  v41[9] = v50.y;
  v42 = v48;
  v41[10] = v50.z;
  v41[11] = v50.w;
  v57.x = v49;
  v57.y = v31;
  v57.z = v32;
  v57.w = v33;
  SetRotateMatrixAxis(v42 + v45, v57);
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__APPLYMATRIX_XYZ();
  SDF_VU0__STOREVECTOR(&v47);
  v51 = op_Multiply(v47, v15->radius, 0);
  pVertex->m_Items[vpos + 1] = v51;
  zero = get_zero();
  pVertex->m_Items[vpos + 2] = zero;
}

// 0x12064b0
void effPCPFlashPolyCircleSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyCircle_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyCircle_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[2].klass) = abgr;
}

// 0x1206390
void effPCPFlashPolyCircleSetPosition(void **hData, sdfVector4_t pPos) {
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
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyCircle_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyCircle_tag, v12);
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

// 0x12065a0
void effPCPFlashPolyCircleSetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyCircle_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyCircle_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *&(*hData)[2].monitor = scale;
}

// 0x11fdb00
effPCPFlashPolyPipe_tag *effPCPFlashPolyPipeCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v7;
  char *v9;
  s64 *v10;
  u64 v11[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyPipe_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyPipe_tag, v11);
    if ((v11[0] & 1) != 0)
      v9 = v11[2];
    else
      v9 = v11 + 1;
    v10 = sub_8C4940(v9);
  }
  v7 = (*hData)[1].klass;
  return effPCPFlashPolyPipeCreate(v7, 0, tbldata);
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
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v11[3];

  v5 = *pData;
  else if (!v5)
  {
    return effPCPFlashPolyPipeCreate(v5, 0, tbldata);
  }
  klass = v5->klass;
  if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyPipeParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyPipeParam_t, v11);
    if ((v11[0] & 1) != 0)
      v8 = v11[2];
    else
      v8 = v11 + 1;
    v9 = sub_8C4940(v8);
  }
  return effPCPFlashPolyPipeCreate(v5, 0, tbldata);
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
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3FlashPolyList_t_o **v8;
  dds3FlashPolyList_t_o *hPoly[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyPipe_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyPipe_tag, hPoly);
      if ((hPoly[0] & 1) != 0)
        v6 = hPoly[2];
      else
        v6 = hPoly + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = &v3[3];
  pMeshDelete(v8);
  hPoly[0] = *v8;
  pMeshDelete(hPoly);
}

// 0x11fe860
void effPCPFlashPolyPipeDraw(void **hData) {
  effPCPFlashPolyPipe_tag_o *v4;
  effPCPFlashPolyPipe_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  struct effPCPFlashPolyPipeParam_t_o *param;
  s64 number;
  s32 abgr_s;
  s32 life;
  u32 interval;
  effManager_c **v14;
  u64 v15;
  s32 v16;
  struct effPCPFlashPolyPipePart_tag_array *v17;
  struct effPCPFlashPolyPipePart_tag_array *pPart;
  effPCPFlashPolyPipePart_tag_o *v20;
  s32 frame;
  effManager_c **v22;
  s32 v24;
  f32 v25;
  u64 v26;
  f32 v27;
  f32 width_out;
  u64 v29;
  s32 v30;
  u32 v31;
  s64 v32;
  u32 v34;
  dds3FlashPolyList_t_o **p_hPoly;
  struct dds3FlashPolyList_t_o *hPoly;
  s64 p_pos;
  s64 v38;
  s32 abgr_e;
  u32 abgr1;
  s32 loop;
  effPCPFlashPolyPipe_tag_o *pFlashPoly;
  u64 v45[3];

  pFlashPoly = 0;
  v4 = *hData;
  if (v4)
  {
    klass = v4->klass;
    if (v4->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyPipe_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyPipe_tag, v45);
      if ((v45[0] & 1) != 0)
        v7 = v45[2];
      else
        v7 = v45 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  pFlashPoly = v4;
  param = v4->param;
  number = param->number;
  if (number < 1)
  {
    v16 = 0;
  }
  else
  {
    abgr_s = param->abgr_s;
    life = param->life;
    interval = param->interval;
    abgr_e = param->abgr_e;
    abgr1 = v4->abgr;
    loop = param->loop;
    v14 = &effManager;
    v15 = 0;
    v16 = 0;
    do
    {
      pPart = v4->pPart;
      v20 = pPart->m_Items[v15];
      frame = v20->frame;
      if (frame)
      {
        if (frame >= life)
        {
          if (loop)
          {
            v29 = *v14;
            if (((*v14)->_2.bitflags2 & 2) != 0 && !*(v29 + 216))
            v20->frame = ~(DDS3EFFECT_RAND_I() % interval);
          }
        }
        else if (frame >= 1)
        {
          v22 = v14;
          else
          {
            v17 = v4->pPart;
            if (v15 >= LODWORD(v17->max_length))
            {
LABEL_22:
            }
          }
          v17->m_Items[v15]->rotate = v17->m_Items[v15]->rotate + v4->param->rotate;
          effPCPFlashPolyPipePartSetVertex(&pFlashPoly, v15, v16);
          v24 = v20->frame;
          if (abgr_s && v24 < abgr_s)
          {
            v25 = v24 / abgr_s;
          }
          else
          {
            v25 = 1.0;
            if (abgr_e)
            {
              v25 = 1.0;
              v30 = life - v24;
              if (v30 <= abgr_e)
                v25 = v30 / abgr_e;
            }
          }
          v31 = effColorBlend(0, v20->abgr, v25);
          v34 = effColorMultiply(v31, abgr1);
          effPCPFlashPolyPipePartSetVC(&pFlashPoly, v32, v34, v16);
          v16 += 5;
          v14 = v22;
        }
      }
      else
      {
        v20->abgr = -2139062144;
        v26 = *v14;
        if (((*v14)->_2.bitflags2 & 2) != 0 && !*(v26 + 216))
        v20->length = ((DDS3EFFECT_RAND_F() * 0.5) + 0.5) * v4->param->length;
        v27 = (DDS3EFFECT_RAND_F() * 0.7) + 0.3;
        v20->width_in = v27 * v4->param->width_in;
        width_out = v4->param->width_out;
        v20->up = 0.0;
        v20->width_out = v27 * width_out;
      }
      ++v15;
      ++v20->frame;
    }
    while (number != v15);
    param = v4->param;
  }
  hPoly = v4->hPoly;
  p_hPoly = &v4->hPoly;
  ++*(p_hPoly - 4);
  sub_854710(&param->fields, 0);
  sub_854930(&hPoly->pos, 0);
  p_pos = &(*p_hPoly)->pos;
  sub_854710(&(*(p_hPoly - 4))->fields, 1u);
  sub_854930(p_pos, 1u);
  v38 = &(*p_hPoly)->pos;
  sub_854710(&(*(p_hPoly - 4))->fields, 2u);
  sub_854930(v38, 2u);
  (*p_hPoly)->scale = *(p_hPoly - 2);
  if (v16 >= 1)
  {
    dds3FlashPolyList3Draw(p_hPoly, v16);
  }
}

// 0x11fe740
void effPCPFlashPolyPipeDrawOff(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3FlashPolyList_t_o **v8;
  u64 v9[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyPipe_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyPipe_tag, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = &v3[3];
  dds3FlashPolyList3DrawOff(v8);
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
  effPCPFlashPolyPipe_tag_o *v7;
  struct effPCPFlashPolyPipePart_tag_array *pPart;
  effPCPFlashPolyPipePart_tag_o *v10;
  struct dds3FlashPolyList_t_o *hPoly;
  struct effPCPFlashPolyPipeParam_t_o *param;
  f32 radius;
  f32 spread;
  struct UnityEngine_Vector4_array *pVertex;
  f32 rotate;
  f32 v17;
  f32 v18;
  f32 v19;
  f32 v20;
  f32 v21;
  f32 v22;
  f32 v23;
  f32 v24;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  f32 width_in;
  s64 v31;
  s64 v32;
  s64 v34;
  s64 v35;
  s64 v37;
  s64 v38;
  UnityEngine_Vector4_o v42;
  UnityEngine_Vector4_o v43;
  UnityEngine_Vector4_o v44;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v46;
  UnityEngine_Vector4_o v47;
  UnityEngine_Vector4_o v48;
  UnityEngine_Vector4_o v49;
  UnityEngine_Vector4_o v50;
  UnityEngine_Vector4_o v51;
  UnityEngine_Vector4_o v52;
  UnityEngine_Vector4_o v53;
  UnityEngine_Vector4_o v54;
  UnityEngine_Vector4_o v55;
  UnityEngine_Vector4_o v56;
  UnityEngine_Vector4_o v57;

  *&p.x = 0;
  *&p.z = 0;
  *&v44.x = 0;
  *&v44.z = 0;
  *&v43.x = 0;
  *&v43.z = 0;
  *&v42.x = 0;
  *&v42.z = 0;
  v7 = *pFlashPoly;
  pPart = (*pFlashPoly)->pPart;
  v10 = pPart->m_Items[number];
  hPoly = v7->hPoly;
  param = v7->param;
  radius = param->radius;
  spread = param->spread;
  pVertex = hPoly->pVertex;
  rotate = v10->rotate;
  v17 = sdfCos(rotate);
  v18 = sdfSin(v10->rotate);
  sub_854690(&v44.x, v17, 0.0, v18, 0.0);
  sub_854710(&v44, 0);
  v20 = v19;
  sub_854710(&v44, 2u);
  sub_854690(&v43.x, radius * v20, 0.0, radius * v21, 0.0);
  sub_854710(&v44, 0);
  v23 = v22;
  sub_854710(&v44, 2u);
  sub_854690(&v42.x, spread * v23, spread + -1.0, spread * v24, 0.0);
  SDF_VU0__LOADVECTOR(v42);
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v42);
  SDF_VU0__COPYVECTOR_A_TO_B();
  SDF_VU0__LOADVECTOR(v44);
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&p);
  x = p.x;
  y = p.y;
  z = p.z;
  w = p.w;
  width_in = v10->width_in;
  v51.x = x;
  v51.y = y;
  v51.z = z;
  v51.w = w;
  p = op_Multiply(v51, width_in, 0);
  v31 = *&v43.z;
  v32 = *&v43.x;
  v55 = op_Multiply(v42, v10->up + v10->length, 0);
  *&v52.x = v32;
  *&v52.z = v31;
  v46 = op_Addition(v52, v55);
  pVertex->m_Items[vpos] = v46;
  v34 = *&v43.x;
  v35 = *&v43.z;
  v56 = op_Multiply(v42, v10->up - v10->length, 0);
  *&v53.x = v34;
  *&v53.z = v35;
  v47 = op_Addition(v53, v56);
  pVertex->m_Items[vpos + 4] = v47;
  v37 = *&v43.x;
  v38 = *&v43.z;
  v57 = op_Multiply(v42, v10->up, 0);
  *&v54.x = v37;
  *&v54.z = v38;
  v48 = op_Addition(v54, v57);
  v43 = v48;
  pVertex->m_Items[vpos + 2] = v48;
  v49 = op_Addition(v43, p);
  pVertex->m_Items[vpos + 1] = v49;
  v50 = op_Subtraction(v43, p);
  pVertex->m_Items[vpos + 3] = v50;
  v10->up = v10->up + (*pFlashPoly)->param->up_s;
}

// 0x11fde90
void effPCPFlashPolyPipeSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyPipe_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyPipe_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[2].klass) = abgr;
}

// 0x11fdd70
void effPCPFlashPolyPipeSetPosition(void **hData, sdfVector4_t pPos) {
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
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyPipe_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyPipe_tag, v12);
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

// 0x11fdf80
void effPCPFlashPolyPipeSetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyPipe_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyPipe_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *&(*hData)[2].monitor = scale;
}

// 0x11fc410
effPCPFlashPolyRing_tag *effPCPFlashPolyRingCopy(void **hData, s32 bPos, bool tbldata) {
  effPCPFlashPolyRing_tag_c *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v8;
  char *v10;
  s64 *v11;
  u64 v12[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyRing_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyRing_tag, v12);
    if ((v12[0] & 1) != 0)
      v10 = v12[2];
    else
      v10 = v12 + 1;
    v11 = sub_8C4940(v10);
  }
  v8 = (*hData)[1].klass;
  return effPCPFlashPolyRingCreate(v8, v5);
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
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v11[3];

  v5 = *pData;
  else if (!v5)
  {
    return effPCPFlashPolyRingCreate(v5, *&bPos);
  }
  klass = v5->klass;
  if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyRingParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyRingParam_t, v11);
    if ((v11[0] & 1) != 0)
      v8 = v11[2];
    else
      v8 = v11 + 1;
    v9 = sub_8C4940(v8);
  }
  return effPCPFlashPolyRingCreate(v5, *&bPos);
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
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3FlashPolyList_t_o **v8;
  dds3FlashPolyList_t_o *hPoly[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyRing_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyRing_tag, hPoly);
      if ((hPoly[0] & 1) != 0)
        v6 = hPoly[2];
      else
        v6 = hPoly + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = &v3[3];
  pMeshDelete(v8);
  hPoly[0] = *v8;
  pMeshDelete(hPoly);
}

// 0x11fd1c0
void effPCPFlashPolyRingDraw(void **hData) {
  effPCPFlashPolyRing_tag_o *v4;
  effPCPFlashPolyRing_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  struct effPCPFlashPolyRingParam_t_o *param;
  s64 number;
  s32 scale_f;
  s32 life;
  f32 length;
  f32 v14;
  f32 v15;
  effPCPFlash_c **v16;
  u64 v17;
  s32 v18;
  struct effPCPFlashPolyRingPart_tag_array *pPart;
  effPCPFlashPolyRingPart_tag_o *v21;
  signed s32 frame;
  f32 v23;
  f32 *p_length;
  u64 v25;
  effPCPFlash_c **v26;
  struct effPCPFlashPolyRingPart_tag_array *v27;
  s32 v30;
  f32 v31;
  f32 v32;
  bool v33;
  u32 abgr;
  u32 v35;
  u32 v38;
  u64 v39;
  dds3FlashPolyList_t_o **p_hPoly;
  struct dds3FlashPolyList_t_o *hPoly;
  s64 p_pos;
  s64 v43;
  System_String_o *v45;
  u32 interval;
  u32 abgr1;
  s32 v49;
  s32 loop;
  effPCPFlashPolyRing_tag_o *v51[3];
  effPCPFlashPolyRing_tag_o *pFlashPoly;

  pFlashPoly = 0;
  v4 = *hData;
  if (v4)
  {
    klass = v4->klass;
    if (v4->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyRing_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyRing_tag, v51);
      if ((v51[0] & 1) != 0)
        v7 = v51[2];
      else
        v7 = v51 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  pFlashPoly = v4;
  param = v4->param;
  number = param->number;
  if (number >= 1)
  {
    life = param->life;
    scale_f = param->scale_f;
    interval = param->interval;
    length = param->length;
    v14 = scale_f;
    if (scale_f)
      v15 = 0.0;
    else
      v15 = param->length;
    abgr1 = v4->abgr;
    v49 = param->scale_f;
    loop = param->loop;
    v16 = &effPCPFlash;
    v17 = 0;
    v18 = 0;
    while (1)
    {
      pPart = v4->pPart;
      v21 = pPart->m_Items[v17];
      frame = v21->frame;
      if (frame)
      {
        if (life <= frame)
        {
          if (loop)
          {
            frame = ~(DDS3EFFECT_RAND_I() % interval);
            v21->frame = frame;
          }
          goto LABEL_48;
        }
        if (frame >= 1)
        {
          if (v49)
          {
            v23 = (length * frame) / v14;
            v21->length = v23;
            p_length = &v21->length;
            if (v23 <= length)
            {
              v25 = *v16;
              v26 = v16;
              if (((*v16)->_2.bitflags2 & 2) != 0)
                goto LABEL_23;
              goto LABEL_34;
            }
          }
          else
          {
            p_length = &v21->length;
          }
          *p_length = length;
          v25 = *v16;
          v26 = v16;
          if (((*v16)->_2.bitflags2 & 2) == 0)
            goto LABEL_34;
LABEL_23:
          if (*(v25 + 216))
          {
LABEL_34:
            v27 = v4->pPart;
            if (v17 >= LODWORD(v27->max_length))
            {
LABEL_35:
            }
          }
          else
          {
            v27 = v4->pPart;
            if (v17 >= LODWORD(v27->max_length))
              goto LABEL_35;
          }
          v27->m_Items[v17]->rotate = v27->m_Items[v17]->rotate + v4->param->rotate;
          effPCPFlashPolyRingPartSetVertex(&pFlashPoly, v17, v18);
          if (v21->frame >= life >> 1)
            v30 = life - frame;
          else
            v30 = frame;
          v31 = v30;
          v32 = v31 / (life >> 1);
          v33 = effBTLSkillCheckRun2(0xD5u);
          abgr = v21->abgr;
          v16 = v26;
          if (v33)
          {
            abgr |= 0xFF000000;
            v21->abgr = abgr;
          }
          v35 = effColorBlend(0, abgr, v32);
          v38 = effColorMultiply(v35, abgr1);
          v39 = *v26;
          if (((*v26)->_2.bitflags2 & 2) != 0 && !*(v39 + 216))
          effPCPFlashPolyRingPartSetVC(&pFlashPoly, v17, v38, v18);
          frame = v21->frame;
          v18 += 5;
        }
      }
      else
      {
        v21->length = v15;
        v21->length_max = length;
        v21->abgr = -2139062144;
      }
LABEL_48:
      ++v17;
      v21->frame = frame + 1;
      if (number == v17)
      {
        param = v4->param;
        goto LABEL_51;
      }
    }
  }
  v18 = 0;
LABEL_51:
  hPoly = v4->hPoly;
  p_hPoly = &v4->hPoly;
  ++*(p_hPoly - 4);
  sub_854710(&param->fields, 0);
  sub_854930(&hPoly->pos, 0);
  p_pos = &(*p_hPoly)->pos;
  sub_854710(&(*(p_hPoly - 4))->fields, 1u);
  sub_854930(p_pos, 1u);
  v43 = &(*p_hPoly)->pos;
  sub_854710(&(*(p_hPoly - 4))->fields, 2u);
  sub_854930(v43, 2u);
  (*p_hPoly)->scale = *(p_hPoly - 2);
  if (v18 >= 1)
  {
    dds3FlashPolyListDraw(p_hPoly, v18, v45);
  }
}

// 0x11fd0a0
void effPCPFlashPolyRingDrawOff(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3FlashPolyList_t_o **v8;
  u64 v9[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyRing_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyRing_tag, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = &v3[3];
  dds3FlashPolyListDrawOff(v8);
}

// 0x1204ae0
effPCPFlashPolyRingExp2_tag *effPCPFlashPolyRingExp2Copy(void **hData, s32 bPos, bool tbldata) {
  effPCPFlashPolyRingExp2_tag_c *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v8;
  char *v10;
  s64 *v11;
  u64 v12[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyRingExp2_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyRingExp2_tag, v12);
    if ((v12[0] & 1) != 0)
      v10 = v12[2];
    else
      v10 = v12 + 1;
    v11 = sub_8C4940(v10);
  }
  v8 = (*hData)[1].klass;
  return effPCPFlashPolyRingExp2Create(v8, v5);
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
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v11[3];

  v5 = *pData;
  else if (!v5)
  {
    return effPCPFlashPolyRingExp2Create(v5, *&bPos);
  }
  klass = v5->klass;
  if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyRingExp2Param_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyRingExp2Param_t, v11);
    if ((v11[0] & 1) != 0)
      v8 = v11[2];
    else
      v8 = v11 + 1;
    v9 = sub_8C4940(v8);
  }
  return effPCPFlashPolyRingExp2Create(v5, *&bPos);
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
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3FlashPolyList_t_o **v8;
  dds3FlashPolyList_t_o *hPoly[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyRingExp2_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyRingExp2_tag, hPoly);
      if ((hPoly[0] & 1) != 0)
        v6 = hPoly[2];
      else
        v6 = hPoly + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = &v3[3];
  pMeshDelete(v8);
  hPoly[0] = *v8;
  pMeshDelete(hPoly);
}

// 0x1205890
void effPCPFlashPolyRingExp2Draw(void **hData) {
  effPCPFlashPolyRingExp2_tag_o *v4;
  effPCPFlashPolyRingExp2_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  struct effPCPFlashPolyRingExp2Param_t_o *param;
  s64 number;
  u32 interval;
  s32 scale_f;
  s32 life;
  f32 v14;
  f32 abgr_s;
  u64 v16;
  s32 v17;
  f32 abgr_e;
  f32 length;
  f32 v20;
  s32 loop;
  struct effPCPFlashPolyRingExp2Part_tag_array *v22;
  struct effPCPFlashPolyRingExp2Part_tag_array *pPart;
  effPCPFlashPolyRingExp2Part_tag_o *v25;
  s32 frame;
  s32 v27;
  u32 v28;
  f32 v29;
  f32 *p_length;
  u32 v31;
  s32 v32;
  Il2CppClass **v34;
  s32 v35;
  f32 v36;
  u32 v37;
  u32 v40;
  dds3FlashPolyList_t_o **p_hPoly;
  struct dds3FlashPolyList_t_o *hPoly;
  s64 p_pos;
  s64 v44;
  System_String_o *v46;
  s32 v48;
  s32 v49;
  u32 abgr1;
  s32 v51;
  s32 v52;
  effPCPFlashPolyRingExp2_tag_o *pFlashPoly;
  u64 v54[3];

  pFlashPoly = 0;
  v4 = *hData;
  if (v4)
  {
    klass = v4->klass;
    if (v4->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyRingExp2_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyRingExp2_tag, v54);
      if ((v54[0] & 1) != 0)
        v7 = v54[2];
      else
        v7 = v54 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  pFlashPoly = v4;
  param = v4->param;
  number = param->number;
  if (number < 1)
  {
    v17 = 0;
    goto LABEL_53;
  }
  interval = param->interval;
  life = param->life;
  scale_f = param->scale_f;
  v14 = scale_f;
  abgr_s = param->abgr_s;
  v16 = 0;
  v17 = 0;
  abgr_e = param->abgr_e;
  v52 = param->abgr_s;
  length = param->length;
  abgr1 = v4->abgr;
  v51 = scale_f;
  if (scale_f)
    v20 = 0.0;
  else
    v20 = param->length;
  loop = param->loop;
  v48 = param->abgr_e;
  v49 = loop;
  do
  {
    pPart = v4->pPart;
    v25 = pPart->m_Items[v16];
    frame = v25->frame;
    v27 = life - frame;
    if (life >= frame)
    {
      if (loop && life == frame)
      {
        v28 = ~(DDS3EFFECT_RAND_I() % interval);
        goto LABEL_50;
      }
      if (frame)
      {
        if (frame >= 1)
        {
          if (v51)
          {
            v29 = (length * frame) / v14;
            v25->length = v29;
            p_length = &v25->length;
            if (v29 <= length)
            {
LABEL_35:
              v31 = interval;
              v32 = v17;
              else
              {
                v22 = v4->pPart;
                if (v16 >= LODWORD(v22->max_length))
                {
LABEL_38:
                }
              }
              v34 = &v22->obj.klass + v16;
              v35 = v32;
              *&v34[4]->_1.byval_arg.data = *&v34[4]->_1.byval_arg.data + v4->param->rotate;
              effPCPFlashPolyRingExp2PartSetVertex(&pFlashPoly, v16, v32);
              if (v52 && frame < v52)
              {
                v36 = frame / abgr_s;
                interval = v31;
              }
              else
              {
                v36 = 1.0;
                interval = v31;
                if (v48)
                {
                  v36 = 1.0;
                  if (v27 <= v48)
                    v36 = v27 / abgr_e;
                }
              }
              v37 = effColorBlend(0, v25->abgr, v36);
              v40 = effColorMultiply(v37, abgr1);
              loop = v49;
              effPCPFlashPolyRingExp2PartSetVC(&pFlashPoly, v16, v40, v35);
              frame = v25->frame;
              v17 = v35 + 5;
              goto LABEL_49;
            }
          }
          else
          {
            p_length = &v25->length;
          }
          *p_length = length;
          goto LABEL_35;
        }
      }
      else
      {
        v25->length = v20;
        v25->length_max = length;
        v25->abgr = -2139062144;
      }
LABEL_49:
      v28 = frame + 1;
LABEL_50:
      v25->frame = v28;
    }
    ++v16;
  }
  while (number != v16);
  param = v4->param;
LABEL_53:
  hPoly = v4->hPoly;
  p_hPoly = &v4->hPoly;
  ++*(p_hPoly - 4);
  sub_854710(&param->fields, 0);
  sub_854930(&hPoly->pos, 0);
  p_pos = &(*p_hPoly)->pos;
  sub_854710(&(*(p_hPoly - 4))->fields, 1u);
  sub_854930(p_pos, 1u);
  v44 = &(*p_hPoly)->pos;
  sub_854710(&(*(p_hPoly - 4))->fields, 2u);
  sub_854930(v44, 2u);
  (*p_hPoly)->scale = *(p_hPoly - 2);
  if (v17 >= 1)
  {
    dds3FlashPolyListDraw(p_hPoly, v17, v46);
  }
}

// 0x1205770
void effPCPFlashPolyRingExp2DrawOff(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3FlashPolyList_t_o **v8;
  u64 v9[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyRingExp2_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyRingExp2_tag, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = &v3[3];
  dds3FlashPolyListDrawOff(v8);
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
  effPCPFlashPolyRingExp2_tag_o *v7;
  struct effPCPFlashPolyRingExp2Part_tag_array *pPart;
  f32 *v10;
  struct dds3FlashPolyList_t_o *hPoly;
  struct effPCPFlashPolyRingExp2Param_t_o *param;
  f32 radius;
  f32 spread;
  struct UnityEngine_Vector4_array *pVertex;
  f32 v16;
  f32 v17;
  f32 v18;
  f32 v19;
  f32 v20;
  f32 v21;
  f32 v22;
  f32 v23;
  f32 v24;
  f32 v25;
  f32 v26;
  f32 v27;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  f32 width_in;
  f32 v34;
  f32 v35;
  f32 v36;
  s64 v37;
  f32 *v39;
  s64 v42;
  s64 v43;
  UnityEngine_Vector4_o v46;
  UnityEngine_Vector4_o v47;
  UnityEngine_Vector4_o v48;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v50;
  UnityEngine_Vector4_o v51;
  UnityEngine_Vector4_o v52;
  UnityEngine_Vector4_o v53;
  UnityEngine_Vector4_o v54;
  UnityEngine_Vector4_o v55;
  UnityEngine_Vector4_o v56;
  UnityEngine_Vector4_o v57;
  UnityEngine_Vector4_o v58;

  *&p.x = 0;
  *&p.z = 0;
  *&v48.x = 0;
  *&v48.z = 0;
  *&v47.x = 0;
  *&v47.z = 0;
  *&v46.x = 0;
  *&v46.z = 0;
  v7 = *pFlashPoly;
  pPart = (*pFlashPoly)->pPart;
  v10 = pPart->m_Items[number];
  hPoly = v7->hPoly;
  param = v7->param;
  radius = param->radius;
  spread = param->spread;
  pVertex = hPoly->pVertex;
  v16 = v10[6];
  v17 = v10[7];
  v18 = v10[8];
  v19 = v16 / v17;
  v20 = sdfCos(v18);
  v21 = sdfSin(v10[8]);
  sub_854690(&v48.x, v20, 0.0, v21, 0.0);
  sub_854710(&v48, 0);
  v23 = v22;
  sub_854710(&v48, 2u);
  sub_854690(&v47.x, radius * v23, 0.0, radius * v24, 0.0);
  sub_854710(&v48, 0);
  v26 = v25;
  sub_854710(&v48, 2u);
  sub_854690(&v46.x, spread * v26, spread + -1.0, spread * v27, 0.0);
  SDF_VU0__LOADVECTOR(v46);
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v46);
  SDF_VU0__COPYVECTOR_A_TO_B();
  SDF_VU0__LOADVECTOR(v48);
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&p);
  x = p.x;
  y = p.y;
  z = p.z;
  w = p.w;
  width_in = (*pFlashPoly)->param->width_in;
  v55.x = x;
  v55.y = y;
  v55.z = z;
  v55.w = w;
  v57 = op_Multiply(v55, width_in, 0);
  v50 = op_Multiply(v57, v19, 0);
  p = op_Multiply(p, v19 * (*pFlashPoly)->param->width_out, 0);
  v34 = v47.y;
  v36 = v47.z;
  v35 = v47.w;
  v37 = vpos + 3LL;
  v39 = (&pVertex->obj + v37);
  v39[8] = v47.x;
  v39[9] = v34;
  v39[10] = v36;
  v39[11] = v35;
  v51 = op_Addition(v47, v50);
  pVertex->m_Items[vpos + 2] = v51;
  v52 = op_Subtraction(v47, v50);
  pVertex->m_Items[vpos + 4] = v52;
  v42 = *&v47.x;
  v43 = *&v47.z;
  v58 = op_Multiply(v46, v10[6], 0);
  *&v56.x = v42;
  *&v56.z = v43;
  v47 = op_Addition(v56, v58);
  v53 = op_Addition(v47, p);
  pVertex->m_Items[vpos] = v53;
  v54 = op_Subtraction(v47, p);
  pVertex->m_Items[vpos + 1] = v54;
}

// 0x1204e70
void effPCPFlashPolyRingExp2SetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyRingExp2_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyRingExp2_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[2].klass) = abgr;
}

// 0x1204d50
void effPCPFlashPolyRingExp2SetPosition(void **hData, sdfVector4_t pPos) {
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
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyRingExp2_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyRingExp2_tag, v12);
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

// 0x1204f60
void effPCPFlashPolyRingExp2SetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyRingExp2_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyRingExp2_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *&(*hData)[2].monitor = scale;
}

// 0x11ff1d0
effPCPFlashPolyRingExp_tag *effPCPFlashPolyRingExpCopy(void **hData, s32 bPos, bool tbldata) {
  effPCPFlashPolyRingExp_tag_c *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v8;
  char *v10;
  s64 *v11;
  u64 v12[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyRingExp_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyRingExp_tag, v12);
    if ((v12[0] & 1) != 0)
      v10 = v12[2];
    else
      v10 = v12 + 1;
    v11 = sub_8C4940(v10);
  }
  v8 = (*hData)[1].klass;
  return effPCPFlashPolyRingExpCreate(v8, v5);
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
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v11[3];

  v5 = *pData;
  else if (!v5)
  {
    return effPCPFlashPolyRingExpCreate(v5, *&bPos);
  }
  klass = v5->klass;
  if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyRingExpParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyRingExpParam_t, v11);
    if ((v11[0] & 1) != 0)
      v8 = v11[2];
    else
      v8 = v11 + 1;
    v9 = sub_8C4940(v8);
  }
  return effPCPFlashPolyRingExpCreate(v5, *&bPos);
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
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3FlashPolyList_t_o **v8;
  dds3FlashPolyList_t_o *hPoly[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyRingExp_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyRingExp_tag, hPoly);
      if ((hPoly[0] & 1) != 0)
        v6 = hPoly[2];
      else
        v6 = hPoly + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = &v3[4];
  pMeshDelete(v8);
  hPoly[0] = *v8;
  pMeshDelete(hPoly);
}

// 0x11fff60
void effPCPFlashPolyRingExpDraw(void **hData) {
  u64 v3;
  effPCPFlashPolyRingExp_tag_o *v5;
  effPCPFlashPolyRingExp_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  struct effPCPFlashPolyRingExpParam_t_o *param;
  s64 number;
  s32 abgr_s;
  f32 spread_s;
  f32 spread_e;
  s32 loop;
  u32 interval;
  s64 life;
  f32 v18;
  f32 radius_s;
  f32 radius_e;
  f32 v21;
  u64 v22;
  s32 v23;
  struct effPCPFlashPolyRingExpPart_tag_array *v24;
  struct effPCPFlashPolyRingExpPart_tag_array *pPart;
  effPCPFlashPolyRingExpPart_tag_o *v27;
  signed s32 frame;
  s32 v30;
  f32 v31;
  s32 v32;
  u32 v33;
  u32 v36;
  struct dds3FlashPolyList_t_o *v37;
  dds3FlashPolyList_t_o **p_hPoly;
  struct dds3FlashPolyList_t_o *hPoly;
  s64 v40;
  s32 v41;
  s64 p_pos;
  s64 v43;
  s64 v44;
  System_String_o *v46;
  u32 abgr1;
  s32 abgr_e;
  effPCPFlashPolyRingExp_tag_o *v50[3];
  effPCPFlashPolyRingExp_tag_o *pFlashPoly;

  pFlashPoly = 0;
  v5 = *hData;
  if (v5)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyRingExp_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyRingExp_tag, v50);
      if ((v50[0] & 1) != 0)
        v8 = v50[2];
      else
        v8 = v50 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  pFlashPoly = v5;
  param = v5->param;
  number = param->number;
  abgr_s = param->abgr_s;
  abgr_e = param->abgr_e;
  spread_s = param->spread_s;
  spread_e = param->spread_e;
  loop = param->loop;
  interval = param->interval;
  life = param->life;
  abgr1 = v5->abgr;
  if (life < 1)
  {
    LODWORD(v3) = 1.0;
  }
  else
  {
    LODWORD(v3) = v5->frame;
    v18 = v3;
    *&v3 = v18 / life;
  }
  radius_s = param->radius_s;
  v5->radius = radius_s + (*&v3 * (param->radius_e - radius_s));
  radius_e = param->radius_e;
  if (radius_s > 0.0)
    radius_e = radius_e / radius_s;
  v5->width_in = param->width_in + (*&v3 * ((param->width_in * radius_e) - param->width_in));
  v5->width_out = param->width_out
                       + (*&v3 * ((radius_e * param->width_out) - param->width_out));
  v5->length = param->length_s + (*&v3 * (param->length_e - param->length_s));
  if (number < 1)
  {
    v23 = 0;
  }
  else
  {
    v21 = spread_e - spread_s;
    v22 = 0;
    v23 = 0;
    do
    {
      pPart = v5->pPart;
      v27 = pPart->m_Items[v22];
      frame = v27->frame;
      if (frame)
      {
        if (frame >= life)
        {
          if (loop)
          {
            frame = ~(DDS3EFFECT_RAND_I() % interval);
            v27->frame = frame;
          }
        }
        else if (frame >= 1)
        {
          v27->spread = (v21 * (frame / life)) + v5->param->spread_s;
          else
          {
            v24 = v5->pPart;
            if (v22 >= LODWORD(v24->max_length))
            {
LABEL_27:
            }
          }
          v24->m_Items[v22]->rotate = v24->m_Items[v22]->rotate + v5->param->rotate;
          effPCPFlashPolyRingExpPartSetVertex(&pFlashPoly, v22, v23);
          v30 = v27->frame;
          if (abgr_s && v30 < abgr_s)
          {
            v31 = v30 / abgr_s;
          }
          else
          {
            v31 = 1.0;
            if (abgr_e)
            {
              v31 = 1.0;
              v32 = life - v30;
              if (v32 <= abgr_e)
                v31 = v32 / abgr_e;
            }
          }
          v33 = effColorBlend(0, v27->abgr, v31);
          v36 = effColorMultiply(v33, abgr1);
          effPCPFlashPolyRingExpPartSetVC(&pFlashPoly, v22, v36, v23);
          frame = v27->frame;
          v23 += 5;
        }
      }
      else
      {
        v27->spread = v5->param->spread_s;
        v27->abgr = -2139062144;
      }
      ++v22;
      v27->frame = frame + 1;
    }
    while (number != v22);
    param = v5->param;
  }
  hPoly = v5->hPoly;
  p_hPoly = &v5->hPoly;
  v37 = hPoly;
  v40 = *(p_hPoly - 8);
  if (v40 == life)
    v41 = 0;
  else
    v41 = v40 + 1;
  *(p_hPoly - 8) = v41;
  p_pos = &v37->pos;
  sub_854710(&param->fields, 0);
  sub_854930(p_pos, 0);
  v43 = &(*p_hPoly)->pos;
  sub_854710(&(*(p_hPoly - 6))->fields, 1u);
  sub_854930(v43, 1u);
  v44 = &(*p_hPoly)->pos;
  sub_854710(&(*(p_hPoly - 6))->fields, 2u);
  sub_854930(v44, 2u);
  (*p_hPoly)->scale = *(p_hPoly - 6);
  if (v23 >= 1)
  {
    dds3FlashPolyListDraw(p_hPoly, v23, v46);
  }
}

// 0x11ffe40
void effPCPFlashPolyRingExpDrawOff(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3FlashPolyList_t_o **v8;
  u64 v9[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyRingExp_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyRingExp_tag, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = &v3[4];
  dds3FlashPolyListDrawOff(v8);
}

// 0x1207620
effPCPFlashPolyRingExpH_tag *effPCPFlashPolyRingExpHCopy(void **hData, s32 bPos, bool tbldata) {
  effPCPFlashPolyRingExpH_tag_c *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v8;
  char *v10;
  s64 *v11;
  u64 v12[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyRingExpH_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyRingExpH_tag, v12);
    if ((v12[0] & 1) != 0)
      v10 = v12[2];
    else
      v10 = v12 + 1;
    v11 = sub_8C4940(v10);
  }
  v8 = (*hData)[1].klass;
  return effPCPFlashPolyRingExpHCreate(v8, v5);
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
LABEL_9:
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
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v11[3];

  v5 = *pData;
  else if (!v5)
  {
    return effPCPFlashPolyRingExpHCreate(v5, *&bPos);
  }
  klass = v5->klass;
  if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyRingExpParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyRingExpParam_t, v11);
    if ((v11[0] & 1) != 0)
      v8 = v11[2];
    else
      v8 = v11 + 1;
    v9 = sub_8C4940(v8);
  }
  return effPCPFlashPolyRingExpHCreate(v5, *&bPos);
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
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3FlashPolyList_t_o **v8;
  u64 v10[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyRingExpH_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyRingExpH_tag, v10);
      if ((v10[0] & 1) != 0)
        v6 = v10[2];
      else
        v6 = v10 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = &v3[4];
  pMeshDelete(v8);
  dds3FlashPolyListHDelete(*v8);
}

// 0x12084a0
void effPCPFlashPolyRingExpHDraw(void **hData) {
  u64 v3;
  effPCPFlashPolyRingExpH_tag_o *v5;
  effPCPFlashPolyRingExpH_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  struct effPCPFlashPolyRingExpParam_t_o *param;
  s64 number;
  s32 abgr_s;
  f32 spread_s;
  f32 spread_e;
  s32 loop;
  u32 interval;
  s64 life;
  f32 v18;
  f32 radius_s;
  f32 radius_e;
  f32 v21;
  u64 v22;
  s32 v23;
  struct effPCPFlashPolyRingExpHPart_tag_array *v24;
  struct effPCPFlashPolyRingExpHPart_tag_array *pPart;
  effPCPFlashPolyRingExpHPart_tag_o *v27;
  signed s32 frame;
  s32 v30;
  f32 v31;
  s32 v32;
  u32 v33;
  u32 v36;
  struct dds3FlashPolyList_t_o *v37;
  dds3FlashPolyList_t_o **p_hPoly;
  struct dds3FlashPolyList_t_o *hPoly;
  s64 v40;
  s32 v41;
  s64 p_pos;
  s64 v43;
  s64 v44;
  u32 abgr1;
  s32 abgr_e;
  effPCPFlashPolyRingExpH_tag_o *v49[3];
  effPCPFlashPolyRingExpH_tag_o *pFlashPoly;

  pFlashPoly = 0;
  v5 = *hData;
  if (v5)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyRingExpH_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyRingExpH_tag, v49);
      if ((v49[0] & 1) != 0)
        v8 = v49[2];
      else
        v8 = v49 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  pFlashPoly = v5;
  param = v5->param;
  number = param->number;
  abgr_s = param->abgr_s;
  abgr_e = param->abgr_e;
  spread_s = param->spread_s;
  spread_e = param->spread_e;
  loop = param->loop;
  interval = param->interval;
  life = param->life;
  abgr1 = v5->abgr;
  if (life < 1)
  {
    LODWORD(v3) = 1.0;
  }
  else
  {
    LODWORD(v3) = v5->frame;
    v18 = v3;
    *&v3 = v18 / life;
  }
  radius_s = param->radius_s;
  v5->radius = radius_s + (*&v3 * (param->radius_e - radius_s));
  radius_e = param->radius_e;
  if (radius_s > 0.0)
    radius_e = radius_e / radius_s;
  v5->width_in = param->width_in + (*&v3 * ((param->width_in * radius_e) - param->width_in));
  v5->width_out = param->width_out
                       + (*&v3 * ((radius_e * param->width_out) - param->width_out));
  v5->length = param->length_s + (*&v3 * (param->length_e - param->length_s));
  if (number < 1)
  {
    v23 = 0;
  }
  else
  {
    v21 = spread_e - spread_s;
    v22 = 0;
    v23 = 0;
    do
    {
      pPart = v5->pPart;
      v27 = pPart->m_Items[v22];
      frame = v27->frame;
      if (frame)
      {
        if (frame >= life)
        {
          if (loop)
          {
            frame = ~(DDS3EFFECT_RAND_I() % interval);
            v27->frame = frame;
          }
        }
        else if (frame >= 1)
        {
          v27->spread = (v21 * (frame / life)) + v5->param->spread_s;
          else
          {
            v24 = v5->pPart;
            if (v22 >= LODWORD(v24->max_length))
            {
LABEL_27:
            }
          }
          v24->m_Items[v22]->rotate = v24->m_Items[v22]->rotate + v5->param->rotate;
          effPCPFlashPolyRingExpHPartSetVertex(&pFlashPoly, v22, v23);
          v30 = v27->frame;
          if (abgr_s && v30 < abgr_s)
          {
            v31 = v30 / abgr_s;
          }
          else
          {
            v31 = 1.0;
            if (abgr_e)
            {
              v31 = 1.0;
              v32 = life - v30;
              if (v32 <= abgr_e)
                v31 = v32 / abgr_e;
            }
          }
          v33 = effColorBlend(0, v27->abgr, v31);
          v36 = effColorMultiply(v33, abgr1);
          effPCPFlashPolyRingExpHPartSetVC(&pFlashPoly, v22, v36, v23);
          frame = v27->frame;
          v23 += 5;
        }
      }
      else
      {
        v27->spread = v5->param->spread_s;
        v27->abgr = -2139062144;
      }
      ++v22;
      v27->frame = frame + 1;
    }
    while (number != v22);
    param = v5->param;
  }
  hPoly = v5->hPoly;
  p_hPoly = &v5->hPoly;
  v37 = hPoly;
  v40 = *(p_hPoly - 8);
  if (v40 == life)
    v41 = 0;
  else
    v41 = v40 + 1;
  *(p_hPoly - 8) = v41;
  p_pos = &v37->pos;
  sub_854710(&param->fields, 0);
  sub_854930(p_pos, 0);
  v43 = &(*p_hPoly)->pos;
  sub_854710(&(*(p_hPoly - 6))->fields, 1u);
  sub_854930(v43, 1u);
  v44 = &(*p_hPoly)->pos;
  sub_854710(&(*(p_hPoly - 6))->fields, 2u);
  sub_854930(v44, 2u);
  (*p_hPoly)->scale = *(p_hPoly - 6);
  if (v23 >= 1)
  {
    dds3FlashPolyListHDraw(p_hPoly, v23);
  }
}

// 0x1208380
void effPCPFlashPolyRingExpHDrawOff(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3FlashPolyList_t_o **v8;
  u64 v9[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyRingExpH_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyRingExpH_tag, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = &v3[4];
  dds3FlashPolyListHDrawOff(v8);
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
  effPCPFlashPolyRingExpH_tag_o *v7;
  struct effPCPFlashPolyRingExpHPart_tag_array *pPart;
  effPCPFlashPolyRingExpHPart_tag_o *v10;
  f32 radius;
  struct UnityEngine_Vector4_array *pVertex;
  f32 rotate;
  f32 spread;
  f32 v15;
  f32 v16;
  f32 v17;
  f32 v18;
  f32 v19;
  f32 v20;
  f32 v21;
  f32 v22;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  f32 width_in;
  f32 v29;
  f32 v30;
  f32 v31;
  s64 v32;
  f32 *v34;
  s64 v37;
  s64 v38;
  UnityEngine_Vector4_o v41;
  UnityEngine_Vector4_o v42;
  UnityEngine_Vector4_o v43;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v45;
  UnityEngine_Vector4_o v46;
  UnityEngine_Vector4_o v47;
  UnityEngine_Vector4_o v48;
  UnityEngine_Vector4_o v49;
  UnityEngine_Vector4_o v50;
  UnityEngine_Vector4_o v51;
  UnityEngine_Vector4_o v52;

  *&p.x = 0;
  *&p.z = 0;
  *&v43.x = 0;
  *&v43.z = 0;
  *&v42.x = 0;
  *&v42.z = 0;
  *&v41.x = 0;
  *&v41.z = 0;
  v7 = *pFlashPoly;
  pPart = (*pFlashPoly)->pPart;
  v10 = pPart->m_Items[number];
  radius = v7->radius;
  pVertex = v7->hPoly->pVertex;
  rotate = v10->rotate;
  spread = v10->spread;
  v15 = sdfCos(rotate);
  v16 = sdfSin(v10->rotate);
  sub_854690(&v43.x, v15, 0.0, v16, 0.0);
  sub_854710(&v43, 0);
  v18 = v17;
  sub_854710(&v43, 2u);
  sub_854690(&v42.x, radius * v18, 0.0, radius * v19, 0.0);
  sub_854710(&v43, 0);
  v21 = v20;
  sub_854710(&v43, 2u);
  sub_854690(&v41.x, spread * v21, spread + -1.0, spread * v22, 0.0);
  SDF_VU0__LOADVECTOR(v41);
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v41);
  SDF_VU0__COPYVECTOR_A_TO_B();
  SDF_VU0__LOADVECTOR(v43);
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&p);
  x = p.x;
  y = p.y;
  z = p.z;
  w = p.w;
  width_in = (*pFlashPoly)->width_in;
  v50.x = x;
  v50.y = y;
  v50.z = z;
  v50.w = w;
  v45 = op_Multiply(v50, width_in, 0);
  p = op_Multiply(p, (*pFlashPoly)->width_out, 0);
  v29 = v42.y;
  v31 = v42.z;
  v30 = v42.w;
  v32 = vpos + 3LL;
  v34 = (&pVertex->obj + v32);
  v34[8] = v42.x;
  v34[9] = v29;
  v34[10] = v31;
  v34[11] = v30;
  v46 = op_Addition(v42, v45);
  pVertex->m_Items[vpos + 2] = v46;
  v47 = op_Subtraction(v42, v45);
  pVertex->m_Items[vpos + 4] = v47;
  v37 = *&v42.x;
  v38 = *&v42.z;
  v52 = op_Multiply(v41, (*pFlashPoly)->length, 0);
  *&v51.x = v37;
  *&v51.z = v38;
  v42 = op_Addition(v51, v52);
  v48 = op_Addition(v42, p);
  pVertex->m_Items[vpos] = v48;
  v49 = op_Subtraction(v42, p);
  pVertex->m_Items[vpos + 1] = v49;
}

// 0x1207970
void effPCPFlashPolyRingExpHSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyRingExpH_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyRingExpH_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[2].klass) = abgr;
}

// 0x1207850
void effPCPFlashPolyRingExpHSetPosition(void **hData, sdfVector4_t pPos) {
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
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyRingExpH_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyRingExpH_tag, v12);
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

// 0x1207b50
void effPCPFlashPolyRingExpHSetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
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
  klass = v7->klass;
  if (v7->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyRingExpH_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyRingExpH_tag, v17);
    if ((v17[0] & 1) != 0)
      v14 = v17[2];
    else
      v14 = v17 + 1;
    v15 = sub_8C4940(v14);
  }
  SDF_VU0__STOREMATRIX(&v7[4].klass->_1.name);
}

// 0x1207a60
void effPCPFlashPolyRingExpHSetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyRingExpH_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyRingExpH_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *&(*hData)[2].monitor = scale;
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
  effPCPFlashPolyRingExp_tag_o *v7;
  struct effPCPFlashPolyRingExpPart_tag_array *pPart;
  effPCPFlashPolyRingExpPart_tag_o *v10;
  f32 radius;
  struct UnityEngine_Vector4_array *pVertex;
  f32 rotate;
  f32 spread;
  f32 v15;
  f32 v16;
  f32 v17;
  f32 v18;
  f32 v19;
  f32 v20;
  f32 v21;
  f32 v22;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  f32 width_in;
  f32 v29;
  f32 v30;
  f32 v31;
  s64 v32;
  f32 *v34;
  s64 v37;
  s64 v38;
  UnityEngine_Vector4_o v41;
  UnityEngine_Vector4_o v42;
  UnityEngine_Vector4_o v43;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v45;
  UnityEngine_Vector4_o v46;
  UnityEngine_Vector4_o v47;
  UnityEngine_Vector4_o v48;
  UnityEngine_Vector4_o v49;
  UnityEngine_Vector4_o v50;
  UnityEngine_Vector4_o v51;
  UnityEngine_Vector4_o v52;

  *&p.x = 0;
  *&p.z = 0;
  *&v43.x = 0;
  *&v43.z = 0;
  *&v42.x = 0;
  *&v42.z = 0;
  *&v41.x = 0;
  *&v41.z = 0;
  v7 = *pFlashPoly;
  pPart = (*pFlashPoly)->pPart;
  v10 = pPart->m_Items[number];
  radius = v7->radius;
  pVertex = v7->hPoly->pVertex;
  rotate = v10->rotate;
  spread = v10->spread;
  v15 = sdfCos(rotate);
  v16 = sdfSin(v10->rotate);
  sub_854690(&v43.x, v15, 0.0, v16, 0.0);
  sub_854710(&v43, 0);
  v18 = v17;
  sub_854710(&v43, 2u);
  sub_854690(&v42.x, radius * v18, 0.0, radius * v19, 0.0);
  sub_854710(&v43, 0);
  v21 = v20;
  sub_854710(&v43, 2u);
  sub_854690(&v41.x, spread * v21, spread + -1.0, spread * v22, 0.0);
  SDF_VU0__LOADVECTOR(v41);
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v41);
  SDF_VU0__COPYVECTOR_A_TO_B();
  SDF_VU0__LOADVECTOR(v43);
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&p);
  x = p.x;
  y = p.y;
  z = p.z;
  w = p.w;
  width_in = (*pFlashPoly)->width_in;
  v50.x = x;
  v50.y = y;
  v50.z = z;
  v50.w = w;
  v45 = op_Multiply(v50, width_in, 0);
  p = op_Multiply(p, (*pFlashPoly)->width_out, 0);
  v29 = v42.y;
  v31 = v42.z;
  v30 = v42.w;
  v32 = vpos + 3LL;
  v34 = (&pVertex->obj + v32);
  v34[8] = v42.x;
  v34[9] = v29;
  v34[10] = v31;
  v34[11] = v30;
  v46 = op_Addition(v42, v45);
  pVertex->m_Items[vpos + 2] = v46;
  v47 = op_Subtraction(v42, v45);
  pVertex->m_Items[vpos + 4] = v47;
  v37 = *&v42.x;
  v38 = *&v42.z;
  v52 = op_Multiply(v41, (*pFlashPoly)->length, 0);
  *&v51.x = v37;
  *&v51.z = v38;
  v42 = op_Addition(v51, v52);
  v48 = op_Addition(v42, p);
  pVertex->m_Items[vpos] = v48;
  v49 = op_Subtraction(v42, p);
  pVertex->m_Items[vpos + 1] = v49;
}

// 0x11ff560
void effPCPFlashPolyRingExpSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyRingExp_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyRingExp_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[2].klass) = abgr;
}

// 0x11ff440
void effPCPFlashPolyRingExpSetPosition(void **hData, sdfVector4_t pPos) {
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
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyRingExp_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyRingExp_tag, v12);
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

// 0x11ff650
void effPCPFlashPolyRingExpSetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyRingExp_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyRingExp_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *&(*hData)[2].monitor = scale;
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
  effPCPFlashPolyRing_tag_o *v7;
  struct effPCPFlashPolyRingPart_tag_array *pPart;
  f32 *v10;
  struct dds3FlashPolyList_t_o *hPoly;
  struct effPCPFlashPolyRingParam_t_o *param;
  f32 radius;
  f32 spread;
  struct UnityEngine_Vector4_array *pVertex;
  f32 v16;
  f32 v17;
  f32 v18;
  f32 v19;
  f32 v20;
  f32 v21;
  f32 v22;
  f32 v23;
  f32 v24;
  f32 v25;
  f32 v26;
  f32 v27;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  f32 width_in;
  f32 v34;
  f32 v35;
  f32 v36;
  s64 v37;
  f32 *v39;
  s64 v42;
  s64 v43;
  UnityEngine_Vector4_o v46;
  UnityEngine_Vector4_o v47;
  UnityEngine_Vector4_o v48;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v50;
  UnityEngine_Vector4_o v51;
  UnityEngine_Vector4_o v52;
  UnityEngine_Vector4_o v53;
  UnityEngine_Vector4_o v54;
  UnityEngine_Vector4_o v55;
  UnityEngine_Vector4_o v56;
  UnityEngine_Vector4_o v57;
  UnityEngine_Vector4_o v58;

  *&p.x = 0;
  *&p.z = 0;
  *&v48.x = 0;
  *&v48.z = 0;
  *&v47.x = 0;
  *&v47.z = 0;
  *&v46.x = 0;
  *&v46.z = 0;
  v7 = *pFlashPoly;
  pPart = (*pFlashPoly)->pPart;
  v10 = pPart->m_Items[number];
  hPoly = v7->hPoly;
  param = v7->param;
  radius = param->radius;
  spread = param->spread;
  pVertex = hPoly->pVertex;
  v16 = v10[6];
  v17 = v10[7];
  v18 = v10[8];
  v19 = v16 / v17;
  v20 = sdfCos(v18);
  v21 = sdfSin(v10[8]);
  sub_854690(&v48.x, v20, 0.0, v21, 0.0);
  sub_854710(&v48, 0);
  v23 = v22;
  sub_854710(&v48, 2u);
  sub_854690(&v47.x, radius * v23, 0.0, radius * v24, 0.0);
  sub_854710(&v48, 0);
  v26 = v25;
  sub_854710(&v48, 2u);
  sub_854690(&v46.x, spread * v26, spread + -1.0, spread * v27, 0.0);
  SDF_VU0__LOADVECTOR(v46);
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v46);
  SDF_VU0__COPYVECTOR_A_TO_B();
  SDF_VU0__LOADVECTOR(v48);
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&p);
  x = p.x;
  y = p.y;
  z = p.z;
  w = p.w;
  width_in = (*pFlashPoly)->param->width_in;
  v55.x = x;
  v55.y = y;
  v55.z = z;
  v55.w = w;
  v57 = op_Multiply(v55, width_in, 0);
  v50 = op_Multiply(v57, v19, 0);
  p = op_Multiply(p, v19 * (*pFlashPoly)->param->width_out, 0);
  v34 = v47.y;
  v36 = v47.z;
  v35 = v47.w;
  v37 = vpos + 3LL;
  v39 = (&pVertex->obj + v37);
  v39[8] = v47.x;
  v39[9] = v34;
  v39[10] = v36;
  v39[11] = v35;
  v51 = op_Addition(v47, v50);
  pVertex->m_Items[vpos + 2] = v51;
  v52 = op_Subtraction(v47, v50);
  pVertex->m_Items[vpos + 4] = v52;
  v42 = *&v47.x;
  v43 = *&v47.z;
  v58 = op_Multiply(v46, v10[6], 0);
  *&v56.x = v42;
  *&v56.z = v43;
  v47 = op_Addition(v56, v58);
  v53 = op_Addition(v47, p);
  pVertex->m_Items[vpos] = v53;
  v54 = op_Subtraction(v47, p);
  pVertex->m_Items[vpos + 1] = v54;
}

// 0x11fc7a0
void effPCPFlashPolyRingSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyRing_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyRing_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[2].klass) = abgr;
}

// 0x11fc680
void effPCPFlashPolyRingSetPosition(void **hData, sdfVector4_t pPos) {
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
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyRing_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyRing_tag, v12);
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

// 0x11fc890
void effPCPFlashPolyRingSetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolyRing_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolyRing_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *&(*hData)[2].monitor = scale;
}

// 0x11f9730
effPCPFlashPolySphere2_tag *effPCPFlashPolySphere2Copy(void **hData, s32 bPos, bool tbldata) {
  effPCPFlashPolySphere2_tag_c *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v8;
  char *v10;
  s64 *v11;
  u64 v12[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphere2_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphere2_tag, v12);
    if ((v12[0] & 1) != 0)
      v10 = v12[2];
    else
      v10 = v12 + 1;
    v11 = sub_8C4940(v10);
  }
  v8 = (*hData)[1].klass;
  return effPCPFlashPolySphere2Create(v8, v5);
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
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v11[3];

  v5 = *pData;
  else if (!v5)
  {
    return effPCPFlashPolySphere2Create(v5, *&bPos);
  }
  klass = v5->klass;
  if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphere2Param_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphere2Param_t, v11);
    if ((v11[0] & 1) != 0)
      v8 = v11[2];
    else
      v8 = v11 + 1;
    v9 = sub_8C4940(v8);
  }
  return effPCPFlashPolySphere2Create(v5, *&bPos);
}

// 0x11f95d0
effPCPFlashPolySphere2_tag *effPCPFlashPolySphere2CreatePCF(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v6;
  effPCPFlashPolySphere2Param_t_c *v7;
  Il2CppObject *DataUnity;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  u64 v14[3];

  v6 = *hData;
  DataUnity = dds3EffectPCPDataGetDataUnity(v6, 0, 0, bPos);
  else if (!DataUnity)
  {
    return effPCPFlashPolySphere2Create(DataUnity, v7);
  }
  klass = DataUnity->klass;
  if (DataUnity->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphere2Param_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphere2Param_t, v14);
    if ((v14[0] & 1) != 0)
      v11 = v14[2];
    else
      v11 = v14 + 1;
    v12 = sub_8C4940(v11);
  }
  return effPCPFlashPolySphere2Create(DataUnity, v7);
}

// 0x11f9840
void effPCPFlashPolySphere2Delete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3FlashPolyList_t_o **v8;
  dds3FlashPolyList_t_o *hPoly[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphere2_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphere2_tag, hPoly);
      if ((hPoly[0] & 1) != 0)
        v6 = hPoly[2];
      else
        v6 = hPoly + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = &v3[3];
  pMeshDelete(v8);
  hPoly[0] = *v8;
  pMeshDelete(hPoly);
}

// 0x11fa1d0
void effPCPFlashPolySphere2Draw(void **hData) {
  effPCPFlashPolySphere2_tag_o *v3;
  effPCPFlashPolySphere2_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  struct effPCPFlashPolySphere2Param_t_o *param;
  s64 number;
  s32 life;
  s32 scale_f;
  f32 radius;
  s32 loop;
  f32 v17;
  u64 v18;
  s32 v19;
  struct effPCPFlashPolySphere2Part_tag_array *pPart;
  effPCPFlashPolySphere2Part_tag_o *v22;
  s32 frame;
  f32 v24;
  f32 *p_radius;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  s32 v30;
  u32 v31;
  s64 v32;
  u32 v34;
  dds3FlashPolyList_t_o **p_hPoly;
  struct dds3FlashPolyList_t_o *hPoly;
  s64 p_pos;
  s64 v38;
  u32 abgr1;
  UnityEngine_Vector4_o p;
  effPCPFlashPolySphere2_tag_o *pFlashPoly;
  u64 v44[3];
  UnityEngine_Vector4_o v45;

  *&p.z = 0;
  pFlashPoly = 0;
  *&p.x = 0;
  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphere2_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphere2_tag, v44);
      if ((v44[0] & 1) != 0)
        v6 = v44[2];
      else
        v6 = v44 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  pFlashPoly = v3;
  SDF_VU0__LOADVECTOR(dds3CameraTargetPos);
  SDF_VU0__LOADVECTOR_B(dds3CameraEyePos);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&p);
  param = v3->param;
  number = param->number;
  if (number >= 1)
  {
    life = param->life;
    scale_f = param->scale_f;
    radius = param->radius;
    abgr1 = v3->abgr;
    loop = param->loop;
    if (scale_f)
      v17 = 0.0;
    else
      v17 = param->radius;
    v18 = 0;
    v19 = 0;
    while (1)
    {
      pPart = v3->pPart;
      v22 = pPart->m_Items[v18];
      frame = v22->frame;
      if (frame)
      {
        if (life <= frame)
        {
          if (loop)
          {
            frame = 0;
            v22->frame = 0;
          }
          goto LABEL_41;
        }
        if (frame >= 1)
        {
          if (scale_f)
          {
            v24 = (radius * frame) / scale_f;
            v22->radius = v24;
            p_radius = &v22->radius;
            if (v24 <= radius)
            {
LABEL_31:
              x = p.x;
              y = p.y;
              z = p.z;
              w = p.w;
              v45.x = x;
              v45.y = y;
              v45.z = z;
              v45.w = w;
              effPCPFlashPolySphere2PartSetVertex(&pFlashPoly, v18, v45, v19);
              if (v22->frame >= life >> 1)
                v30 = life - frame;
              else
                v30 = frame;
              v31 = effColorBlend(0, v22->abgr, v30 / (life >> 1), 0);
              v34 = effColorMultiply(v31, abgr1);
              effPCPFlashPolySphere2PartSetVC(&pFlashPoly, v32, v34, v19);
              frame = v22->frame;
              v19 += 3;
              goto LABEL_41;
            }
          }
          else
          {
            p_radius = &v22->radius;
          }
          *p_radius = radius;
          goto LABEL_31;
        }
      }
      else
      {
        v22->radius = v17;
        v22->abgr = -2139062144;
      }
LABEL_41:
      ++v18;
      v22->frame = frame + 1;
      if (number == v18)
      {
        param = v3->param;
        goto LABEL_44;
      }
    }
  }
  v19 = 0;
LABEL_44:
  hPoly = v3->hPoly;
  p_hPoly = &v3->hPoly;
  ++*(p_hPoly - 4);
  sub_854710(&param->fields, 0);
  sub_854930(&hPoly->pos, 0);
  p_pos = &(*p_hPoly)->pos;
  sub_854710(&(*(p_hPoly - 4))->fields, 1u);
  sub_854930(p_pos, 1u);
  v38 = &(*p_hPoly)->pos;
  sub_854710(&(*(p_hPoly - 4))->fields, 2u);
  sub_854930(v38, 2u);
  (*p_hPoly)->scale = *(p_hPoly - 2);
  if (v19 >= 1)
  {
    dds3FlashPolyList2Draw(p_hPoly, v19);
  }
}

// 0x11fa0b0
void effPCPFlashPolySphere2DrawOff(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3FlashPolyList_t_o **v8;
  u64 v9[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphere2_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphere2_tag, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = &v3[3];
  dds3FlashPolyList2DrawOff(v8);
}

// 0x1201ff0
effPCPFlashPolySphere2Exp_tag *effPCPFlashPolySphere2ExpCopy(void **hData, s32 bPos, bool tbldata) {
  effPCPFlashPolySphere2Exp_tag_c *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v8;
  char *v10;
  s64 *v11;
  u64 v12[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphere2Exp_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphere2Exp_tag, v12);
    if ((v12[0] & 1) != 0)
      v10 = v12[2];
    else
      v10 = v12 + 1;
    v11 = sub_8C4940(v10);
  }
  v8 = (*hData)[1].klass;
  return effPCPFlashPolySphere2ExpCreate(v8, v5);
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
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v11[3];

  v5 = *pData;
  else if (!v5)
  {
    return effPCPFlashPolySphere2ExpCreate(v5, *&bPos);
  }
  klass = v5->klass;
  if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphere2ExpParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphere2ExpParam_t, v11);
    if ((v11[0] & 1) != 0)
      v8 = v11[2];
    else
      v8 = v11 + 1;
    v9 = sub_8C4940(v8);
  }
  return effPCPFlashPolySphere2ExpCreate(v5, *&bPos);
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
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3FlashPolyList_t_o **v8;
  dds3FlashPolyList_t_o *hPoly[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphere2Exp_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphere2Exp_tag, hPoly);
      if ((hPoly[0] & 1) != 0)
        v6 = hPoly[2];
      else
        v6 = hPoly + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = &v3[3];
  pMeshDelete(v8);
  hPoly[0] = *v8;
  pMeshDelete(hPoly);
}

// 0x1202b00
void effPCPFlashPolySphere2ExpDraw(void **hData) {
  effPCPFlashPolySphere2Exp_tag_o *v3;
  effPCPFlashPolySphere2Exp_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  struct effPCPFlashPolySphere2ExpParam_t_o *param;
  s64 number;
  s32 life;
  s32 abgr_s;
  f32 abgr_e;
  f32 radius_a;
  s32 loop;
  u64 v18;
  s32 v19;
  struct effPCPFlashPolySphere2ExpPart_tag_array *pPart;
  effPCPFlashPolySphere2ExpPart_tag_o *v22;
  s32 frame;
  s32 v24;
  f32 v25;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  f32 v30;
  s32 v31;
  u32 v32;
  s64 v33;
  u32 v35;
  dds3FlashPolyList_t_o **p_hPoly;
  struct dds3FlashPolyList_t_o *hPoly;
  s64 p_pos;
  s64 v39;
  s32 v42;
  f32 radius_s;
  f32 radius;
  u32 abgr1;
  UnityEngine_Vector4_o p;
  effPCPFlashPolySphere2Exp_tag_o *pFlashPoly;
  u64 v48[3];
  UnityEngine_Vector4_o v49;

  *&p.z = 0;
  pFlashPoly = 0;
  *&p.x = 0;
  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphere2Exp_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphere2Exp_tag, v48);
      if ((v48[0] & 1) != 0)
        v6 = v48[2];
      else
        v6 = v48 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  pFlashPoly = v3;
  SDF_VU0__LOADVECTOR(dds3CameraTargetPos);
  SDF_VU0__LOADVECTOR_B(dds3CameraEyePos);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&p);
  param = v3->param;
  number = param->number;
  if (number >= 1)
  {
    radius = param->radius;
    radius_s = param->radius_s;
    life = param->life;
    abgr_s = param->abgr_s;
    abgr_e = param->abgr_e;
    v42 = param->abgr_e;
    radius_a = param->radius_a;
    loop = param->loop;
    v18 = 0;
    v19 = 0;
    abgr1 = v3->abgr;
    while (1)
    {
      pPart = v3->pPart;
      v22 = pPart->m_Items[v18];
      frame = v22->frame;
      v24 = life - frame;
      if (life < frame)
        goto LABEL_39;
      if (!frame)
        break;
      if (frame < 1)
        goto LABEL_27;
      v25 = v22->radius_s;
      v22->radius = v22->radius + v25;
      v22->radius_s = radius_a * v25;
      x = p.x;
      y = p.y;
      z = p.z;
      w = p.w;
      v49.x = x;
      v49.y = y;
      v49.z = z;
      v49.w = w;
      effPCPFlashPolySphere2ExpPartSetVertex(&pFlashPoly, v18, v49, v19);
      if (abgr_s && frame < abgr_s)
      {
        v30 = frame / abgr_s;
      }
      else
      {
        v30 = 1.0;
        if (v42)
        {
          v30 = 1.0;
          if (v24 <= v42)
            v30 = v24 / abgr_e;
        }
      }
      v32 = effColorBlend(0, v22->abgr, v30);
      v35 = effColorMultiply(v32, abgr1);
      effPCPFlashPolySphere2ExpPartSetVC(&pFlashPoly, v33, v35, v19);
      v19 += 3;
      if (!loop)
      {
LABEL_37:
        v31 = v22->frame + 1;
        goto LABEL_38;
      }
LABEL_28:
      if (life != frame)
        goto LABEL_37;
      v31 = 0;
LABEL_38:
      v22->frame = v31;
LABEL_39:
      if (number == ++v18)
      {
        param = v3->param;
        goto LABEL_42;
      }
    }
    v22->radius = radius;
    v22->radius_s = radius_s;
    v22->abgr = -2139062144;
LABEL_27:
    if (!loop)
      goto LABEL_37;
    goto LABEL_28;
  }
  v19 = 0;
LABEL_42:
  hPoly = v3->hPoly;
  p_hPoly = &v3->hPoly;
  ++*(p_hPoly - 4);
  sub_854710(&param->fields, 0);
  sub_854930(&hPoly->pos, 0);
  p_pos = &(*p_hPoly)->pos;
  sub_854710(&(*(p_hPoly - 4))->fields, 1u);
  sub_854930(p_pos, 1u);
  v39 = &(*p_hPoly)->pos;
  sub_854710(&(*(p_hPoly - 4))->fields, 2u);
  sub_854930(v39, 2u);
  (*p_hPoly)->scale = *(p_hPoly - 2);
  if (v19 >= 1)
  {
    dds3FlashPolyList2Draw(p_hPoly, v19);
  }
}

// 0x12029e0
void effPCPFlashPolySphere2ExpDrawOff(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3FlashPolyList_t_o **v8;
  u64 v9[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphere2Exp_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphere2Exp_tag, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = &v3[3];
  dds3FlashPolyList2DrawOff(v8);
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
  v39 = v16;
  v20 = def_dir.x;
  v21 = def_dir.y;
  v22 = v16 * number;
  v23 = def_dir.z;
  *&static_fields = def_dir.w;
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
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphere2Exp_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphere2Exp_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[2].klass) = abgr;
}

// 0x1202260
void effPCPFlashPolySphere2ExpSetPosition(void **hData, sdfVector4_t pPos) {
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
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphere2Exp_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphere2Exp_tag, v12);
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

// 0x1202470
void effPCPFlashPolySphere2ExpSetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphere2Exp_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphere2Exp_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *&(*hData)[2].monitor = scale;
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
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphere2_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphere2_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[2].klass) = abgr;
}

// 0x11f99a0
void effPCPFlashPolySphere2SetPosition(void **hData, sdfVector4_t pPos) {
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
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphere2_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphere2_tag, v12);
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

// 0x11f9bb0
void effPCPFlashPolySphere2SetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphere2_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphere2_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *&(*hData)[2].monitor = scale;
}

// 0x12033c0
effPCPFlashPolySphere3_tag *effPCPFlashPolySphere3Copy(void **hData, s32 bPos, bool tbldata) {
  effPCPFlashPolySphere3_tag_c *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v8;
  char *v10;
  s64 *v11;
  u64 v12[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphere3_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphere3_tag, v12);
    if ((v12[0] & 1) != 0)
      v10 = v12[2];
    else
      v10 = v12 + 1;
    v11 = sub_8C4940(v10);
  }
  v8 = (*hData)[1].klass;
  return effPCPFlashPolySphere3Create(v8, v5);
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
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v11[3];

  v5 = *pData;
  else if (!v5)
  {
    return effPCPFlashPolySphere3Create(v5, *&bPos);
  }
  klass = v5->klass;
  if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphere3Param_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphere3Param_t, v11);
    if ((v11[0] & 1) != 0)
      v8 = v11[2];
    else
      v8 = v11 + 1;
    v9 = sub_8C4940(v8);
  }
  return effPCPFlashPolySphere3Create(v5, *&bPos);
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
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3FlashPolyList_t_o **v8;
  dds3FlashPolyList_t_o *hPoly[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphere3_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphere3_tag, hPoly);
      if ((hPoly[0] & 1) != 0)
        v6 = hPoly[2];
      else
        v6 = hPoly + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = &v3[3];
  pMeshDelete(v8);
  hPoly[0] = *v8;
  pMeshDelete(hPoly);
}

// 0x1204130
void effPCPFlashPolySphere3Draw(void **hData) {
  effPCPFlashPolySphere3_tag_o *v3;
  effPCPFlashPolySphere3_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  struct effPCPFlashPolySphere3Param_t_o *param;
  s64 number;
  s32 abgr_s;
  f32 abgr_e;
  f32 move_a;
  u32 interval;
  s32 life;
  s32 loop;
  u64 v20;
  s32 v21;
  struct effPCPFlashPolySphere3Part_tag_array *v22;
  struct effPCPFlashPolySphere3Part_tag_array *pPart;
  effPCPFlashPolySphere3Part_tag_o *v25;
  s32 frame;
  u32 v27;
  f32 v28;
  s32 v30;
  f32 v31;
  s32 v32;
  u32 v33;
  s64 v34;
  u32 v36;
  dds3FlashPolyList_t_o **p_hPoly;
  struct dds3FlashPolyList_t_o *hPoly;
  s64 p_pos;
  s64 v40;
  s32 v43;
  f32 move_s;
  f32 move;
  f32 radius;
  u32 abgr1;
  UnityEngine_Vector4_o p;
  effPCPFlashPolySphere3_tag_o *pFlashPoly;
  u64 v50[3];
  UnityEngine_Vector4_o v51;

  *&p.z = 0;
  pFlashPoly = 0;
  *&p.x = 0;
  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphere3_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphere3_tag, v50);
      if ((v50[0] & 1) != 0)
        v6 = v50[2];
      else
        v6 = v50 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  pFlashPoly = v3;
  SDF_VU0__LOADVECTOR(dds3CameraTargetPos);
  SDF_VU0__LOADVECTOR_B(dds3CameraEyePos);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__STOREVECTOR(&p);
  param = v3->param;
  number = param->number;
  if (number < 1)
  {
    v21 = 0;
  }
  else
  {
    radius = param->radius;
    abgr_s = param->abgr_s;
    move = param->move;
    abgr_e = param->abgr_e;
    v43 = param->abgr_e;
    move_s = param->move_s;
    move_a = param->move_a;
    life = param->life;
    interval = param->interval;
    loop = param->loop;
    v20 = 0;
    v21 = 0;
    abgr1 = v3->abgr;
    do
    {
      pPart = v3->pPart;
      v25 = pPart->m_Items[v20];
      frame = v25->frame;
      if (frame <= life)
      {
        if (loop && frame == life)
        {
          v27 = ~(DDS3EFFECT_RAND_I() % interval);
        }
        else
        {
          if (frame)
          {
            if (frame >= 1)
            {
              v28 = v25->move_s;
              v25->move = v25->move + v28;
              v25->move_s = move_a * v28;
              else
              {
                v22 = v3->pPart;
                if (v20 >= LODWORD(v22->max_length))
                {
LABEL_32:
                }
              }
              v22->m_Items[v20]->look_r = v22->m_Items[v20]->look_r + v22->m_Items[v20]->rotate;
              effPCPFlashPolySphere3PartSetVertex(&pFlashPoly, v20, p, v21);
              v30 = v25->frame;
              if (abgr_s && v30 < abgr_s)
              {
                v31 = v30 / abgr_s;
              }
              else
              {
                v31 = 1.0;
                if (v43)
                {
                  v31 = 1.0;
                  v32 = life - v30;
                  if (v32 <= v43)
                    v31 = v32 / abgr_e;
                }
              }
              v33 = effColorBlend(0, v25->abgr, v31);
              v36 = effColorMultiply(v33, abgr1);
              effPCPFlashPolySphere3PartSetVC(&pFlashPoly, v34, v36, v21);
              v21 += 5;
            }
          }
          else
          {
            effPCPFlashPolySphere3PartInit(&pFlashPoly, v20, v51);
            v25->radius = radius;
            v25->move = move;
            v25->move_s = move_s;
            v25->abgr = -2139062144;
          }
          v27 = v25->frame + 1;
        }
        v25->frame = v27;
      }
      ++v20;
    }
    while (number != v20);
    param = v3->param;
  }
  hPoly = v3->hPoly;
  p_hPoly = &v3->hPoly;
  ++*(p_hPoly - 4);
  sub_854710(&param->fields, 0);
  sub_854930(&hPoly->pos, 0);
  p_pos = &(*p_hPoly)->pos;
  sub_854710(&(*(p_hPoly - 4))->fields, 1u);
  sub_854930(p_pos, 1u);
  v40 = &(*p_hPoly)->pos;
  sub_854710(&(*(p_hPoly - 4))->fields, 2u);
  sub_854930(v40, 2u);
  (*p_hPoly)->scale = *(p_hPoly - 2);
  if (v21 >= 1)
  {
    dds3FlashPolyList3Draw(p_hPoly, v21);
  }
}

// 0x1204010
void effPCPFlashPolySphere3DrawOff(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3FlashPolyList_t_o **v8;
  u64 v9[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphere3_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphere3_tag, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = &v3[3];
  dds3FlashPolyList3DrawOff(v8);
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
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphere3_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphere3_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[2].klass) = abgr;
}

// 0x1203630
void effPCPFlashPolySphere3SetPosition(void **hData, sdfVector4_t pPos) {
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
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphere3_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphere3_tag, v12);
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

// 0x1203840
void effPCPFlashPolySphere3SetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphere3_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphere3_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *&(*hData)[2].monitor = scale;
}

// 0x11faad0
effPCPFlashPolySphere_tag *effPCPFlashPolySphereCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject **v6;
  Il2CppObject *v7;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  Il2CppObject *v12[3];
  Il2CppObject *hDataa;

  hDataa = 0;
  v6 = *hData;
  if (!*hData)
    return 0;
  v7 = *v6;
  if (LOBYTE((*v6)[18].klass) < typeHierarchyDepth
    || *(v7[12].monitor + typeHierarchyDepth - 1) != effPCPFlashPolySphere_tag)
  {
    sub_8FC2C0(v7[4].klass, effPCPFlashPolySphere_tag, v12);
    if ((v12[0] & 1) != 0)
      v9 = v12[2];
    else
      v9 = v12 + 1;
    v10 = sub_8C4940(v9);
  }
  hDataa = v6[2];
  return effPCPFlashPolySphereCreate(&hDataa, bPos, 1);
}

// 0x11fa5e0
effPCPFlashPolySphere_tag *effPCPFlashPolySphereCreate(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v7;
  u64 *v8;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  Il2CppClass *v13;
  s64 *Interface;
  u64 *v15;
  effPCPFlashPolySphereParam_t_array *v16;
  u64 *v18;
  effPCPFlashPolySphereParam_t_o *v19;
  u64 v21;
  u32 v22;
  dds3FlashPolyList_t_o *v23;
  u64 v24;
  u64 v25;
  u32 v26;
  s64 v27;
  u32 *v29;
  u64 v30;
  u64 *v31;
  u64 v34;
  s64 v36;
  u32 v37;
  u64 v38;
  char *v40;
  s64 *v41;
  effPCPFlashPolySphereParam_t_o *param;
  s32 pos;
  u64 v44[2];
  char *v45;

  pos = bPos;
  param = 0;
  v7 = *hData;
  if (tbldata)
  {
    v8 = Allocate(effPCPFlashPolySphereParam_t);
    effPCPFlashPolySphereParam_t___ctor(v8);
    param = v8;
    if (v7)
    {
      klass = v7->klass;
      if (v7->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphereParam_t)
      {
        sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphereParam_t, v44);
        if ((v44[0] & 1) != 0)
          v11 = v45;
        else
          v11 = v44 + 1;
        v12 = sub_8C4940(v11);
      }
    }
    effPCPFlashPolySphereParam_t__pClone(v7, &param);
  }
  else
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v7->klass->_1.element_class, v13, v44);
      if ((v44[0] & 1) != 0)
        v40 = v45;
      else
        v40 = v44 + 1;
      v41 = sub_8C4940(v40);
    }
    if (*(Interface + 6) <= bPos)
      return 0;
    v15 = Allocate(effPCPFlashPolySphereParam_t);
    effPCPFlashPolySphereParam_t___ctor(v15);
    v16 = effPCPFlashPolySphereParam_t__pCopy(v15, *hData, &pos, 1);
    param = v16->m_Items[0];
  }
  v18 = Allocate(effPCPFlashPolySphere_tag);
  _ctor(v18, 0);
  v19 = param;
  v18[2] = param;
  v18[3] = NewSpecific(effPCPFlashPolySpherePart_tag, v19->number);
  v18[4] = 0x8080808000000000LL;
  *(v18 + 10) = 1065353216;
  v21 = v18[2];
  if (!*(v21 + 48))
  {
    *(v21 + 48) = 1;
    v21 = v18[2];
  }
  v22 = *(v21 + 32);
  v23 = dds3FlashPolyListCreate(v22);
  v24 = v18[2];
  v18[6] = v23;
  v23->blend = *(v24 + 76);
  v25 = v18[2];
  if (*(v25 + 32))
  {
    v26 = *(v25 + 48);
    v27 = 4;
    do
    {
      v29 = v18[3];
      v30 = v27 - 4;
      v31 = Allocate(effPCPFlashPolySpherePart_tag);
      _ctor(v31, 0);
      *&v29[2 * v27] = v31;
      v34 = v18[3];
      v36 = *(v34 + 8 * v27);
      v37 = DDS3EFFECT_RAND_I();
      v38 = v27 - 3;
      ++v27;
      *(v36 + 20) = v37 / v26 * v26 - v37;
    }
    while (v38 < *(v18[2] + 32));
  }
  return v18;
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
  Il2CppObject *v3;
  effPCPFlashPolySphere_tag_c *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  dds3FlashPolyList_t_o **v9;
  dds3FlashPolyList_t_o *hPoly[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphere_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphere_tag, hPoly);
      if ((hPoly[0] & 1) != 0)
        v7 = hPoly[2];
      else
        v7 = hPoly + 1;
      v8 = sub_8C4940(v7);
    }
    v9 = &v3[3];
    pMeshDelete(v9, v4);
    hPoly[0] = *v9;
    pMeshDelete(hPoly);
  }
}

// 0x11fbaa0
void effPCPFlashPolySphereDraw(void **hData) {
  effPCPFlashPolySphere_tag_o *v3;
  effPCPFlashPolySphere_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  struct effPCPFlashPolySphereParam_t_o *param;
  s64 number;
  s32 scale_f;
  s32 life;
  f32 radius;
  u32 interval;
  f32 v17;
  s32 loop;
  f32 v19;
  u64 v20;
  s32 v21;
  struct effPCPFlashPolySpherePart_tag_array *pPart;
  effPCPFlashPolySpherePart_tag_o *v24;
  s32 frame;
  f32 v26;
  f32 *p_radius;
  f32 v28;
  f32 v29;
  f32 v30;
  f32 v31;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  s32 v37;
  u32 v38;
  u32 v41;
  dds3FlashPolyList_t_o **p_hPoly;
  struct dds3FlashPolyList_t_o *hPoly;
  s64 p_pos;
  s64 v45;
  System_String_o *v47;
  u32 abgr1;
  s32 v50;
  s32 v51;
  UnityEngine_Vector4_o p;
  effPCPFlashPolySphere_tag_o *pFlashPoly;
  u64 v54[3];
  UnityEngine_Vector4_o v55;
  UnityEngine_Vector4_o v56;

  *&p.z = 0;
  pFlashPoly = 0;
  *&p.x = 0;
  v3 = *hData;
  if (!v3)
  {
    pFlashPoly = 0;
    return;
  }
  klass = v3->klass;
  if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphere_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphere_tag, v54);
    if ((v54[0] & 1) != 0)
      v6 = v54[2];
    else
      v6 = v54 + 1;
    v7 = sub_8C4940(v6);
  }
  pFlashPoly = v3;
  SDF_VU0__LOADVECTOR(dds3CameraTargetPos);
  SDF_VU0__LOADVECTOR_B(dds3CameraEyePos);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__STOREVECTOR(&p);
  param = v3->param;
  number = param->number;
  if (number < 1)
  {
    v21 = 0;
    goto LABEL_52;
  }
  life = param->life;
  scale_f = param->scale_f;
  radius = param->radius;
  interval = param->interval;
  v17 = scale_f;
  abgr1 = v3->abgr;
  loop = param->loop;
  if (scale_f)
    v19 = 0.0;
  else
    v19 = radius;
  v50 = scale_f;
  v51 = loop;
  v20 = 0;
  v21 = 0;
  do
  {
    pPart = v3->pPart;
    v24 = pPart->m_Items[v20];
    frame = v24->frame;
    if (frame)
    {
      if (life > frame)
      {
        if (frame < 1)
          goto LABEL_49;
        if (v50)
        {
          v26 = (radius * frame) / v17;
          v24->radius = v26;
          p_radius = &v24->radius;
          if (v26 <= radius)
          {
LABEL_39:
            x = p.x;
            y = p.y;
            z = p.z;
            w = p.w;
            v56.x = x;
            v56.y = y;
            v56.z = z;
            v56.w = w;
            effPCPFlashPolySpherePartRotate(&pFlashPoly, v20, v56);
            effPCPFlashPolySpherePartSetVertex(&pFlashPoly, v20, p, v21);
            if (v24->frame >= life >> 1)
              v37 = life - frame;
            else
              v37 = frame;
            v38 = effColorBlend(0, v24->abgr, v37 / (life >> 1), 0);
            v41 = effColorMultiply(v38, abgr1);
            effPCPFlashPolySpherePartSetVC(&pFlashPoly, v20, v41, v21);
            v21 += 5;
            goto LABEL_49;
          }
        }
        else
        {
          p_radius = &v24->radius;
        }
        *p_radius = radius;
        goto LABEL_39;
      }
      if (v51)
      {
        v24->frame = ~(DDS3EFFECT_RAND_I() % interval);
      }
    }
    else
    {
      v29 = p.x;
      v28 = p.y;
      v31 = p.z;
      v30 = p.w;
      v55.x = v29;
      v55.y = v28;
      v55.z = v31;
      v55.w = v30;
      effPCPFlashPolySpherePartInit(&pFlashPoly, v20, v55);
      v24->radius = v19;
      v24->abgr = -2139062144;
    }
LABEL_49:
    ++v20;
    ++v24->frame;
  }
  while (number != v20);
  param = v3->param;
LABEL_52:
  hPoly = v3->hPoly;
  p_hPoly = &v3->hPoly;
  ++*(p_hPoly - 4);
  sub_854710(&param->fields, 0);
  sub_854930(&hPoly->pos, 0);
  p_pos = &(*p_hPoly)->pos;
  sub_854710(&(*(p_hPoly - 4))->fields, 1u);
  sub_854930(p_pos, 1u);
  v45 = &(*p_hPoly)->pos;
  sub_854710(&(*(p_hPoly - 4))->fields, 2u);
  sub_854930(v45, 2u);
  (*p_hPoly)->scale = *(p_hPoly - 2);
  if (v21 >= 1)
  {
    dds3FlashPolyListDraw(p_hPoly, v21, v47);
  }
}

// 0x11fb980
void effPCPFlashPolySphereDrawOff(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3FlashPolyList_t_o **v8;
  u64 v9[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphere_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphere_tag, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = &v3[3];
  dds3FlashPolyListDrawOff(v8);
}

// 0x12008a0
effPCPFlashPolySphereExp_tag *effPCPFlashPolySphereExpCopy(void **hData, s32 bPos, bool tbldata) {
  effPCPFlashPolySphereExp_tag_c *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v8;
  char *v10;
  s64 *v11;
  u64 v12[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphereExp_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphereExp_tag, v12);
    if ((v12[0] & 1) != 0)
      v10 = v12[2];
    else
      v10 = v12 + 1;
    v11 = sub_8C4940(v10);
  }
  v8 = (*hData)[1].klass;
  return effPCPFlashPolySphereExpCreate(v8, v5);
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
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v11[3];

  v5 = *pData;
  else if (!v5)
  {
    return effPCPFlashPolySphereExpCreate(v5, *&bPos);
  }
  klass = v5->klass;
  if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphereExpParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphereExpParam_t, v11);
    if ((v11[0] & 1) != 0)
      v8 = v11[2];
    else
      v8 = v11 + 1;
    v9 = sub_8C4940(v8);
  }
  return effPCPFlashPolySphereExpCreate(v5, *&bPos);
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
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3FlashPolyList_t_o **v8;
  dds3FlashPolyList_t_o *hPoly[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphereExp_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphereExp_tag, hPoly);
      if ((hPoly[0] & 1) != 0)
        v6 = hPoly[2];
      else
        v6 = hPoly + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = &v3[3];
  pMeshDelete(v8);
  hPoly[0] = *v8;
  pMeshDelete(hPoly);
}

// 0x12016e0
void effPCPFlashPolySphereExpDraw(void **hData) {
  effPCPFlashPolySphereExp_tag_o *v3;
  effPCPFlashPolySphereExp_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  struct effPCPFlashPolySphereExpParam_t_o *param;
  s64 number;
  s32 life;
  s32 abgr_s;
  f32 radius;
  u32 interval;
  f32 v19;
  u64 v20;
  s32 v21;
  struct effPCPFlashPolySphereExpPart_tag_array *pPart;
  effPCPFlashPolySphereExpPart_tag_o *v24;
  s32 frame;
  f32 v26;
  f32 *p_radius;
  struct effPCPFlashPolySphereExpPart_tag_array *v29;
  dds3FlashPolyList_t_o **p_hPoly;
  struct dds3FlashPolyList_t_o *hPoly;
  s64 p_pos;
  s64 v41;
  System_String_o *v43;
  s32 abgr_e;
  u32 abgr1;
  s32 scale_f;
  s32 loop;
  UnityEngine_Vector4_o p;
  effPCPFlashPolySphereExp_tag_o *pFlashPoly;
  u64 v51[3];
  UnityEngine_Vector4_o v52;

  *&p.z = 0;
  pFlashPoly = 0;
  *&p.x = 0;
  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphereExp_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphereExp_tag, v51);
      if ((v51[0] & 1) != 0)
        v6 = v51[2];
      else
        v6 = v51 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  pFlashPoly = v3;
  SDF_VU0__LOADVECTOR(dds3CameraTargetPos);
  SDF_VU0__LOADVECTOR_B(dds3CameraEyePos);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__STOREVECTOR(&p);
  param = v3->param;
  number = param->number;
  if (number >= 1)
  {
    life = param->life;
    abgr_s = param->abgr_s;
    v52.x = 0.0;
    radius = param->radius;
    interval = param->interval;
    abgr1 = v3->abgr;
    scale_f = param->scale_f;
    loop = param->loop;
    abgr_e = param->abgr_e;
    if (scale_f)
      v19 = 0.0;
    else
      v19 = param->radius;
    v20 = 0;
    v21 = 0;
    while (1)
    {
      pPart = v3->pPart;
      v24 = pPart->m_Items[v20];
      frame = v24->frame;
      if (!frame)
      {
        effPCPFlashPolySphereExpPartInit(&pFlashPoly, v20, v52);
        v24->radius = v19;
        v24->abgr = -2139062144;
        goto LABEL_52;
      }
      if (frame >= life)
      {
        if (loop)
        {
          v24->frame = ~(DDS3EFFECT_RAND_I() % interval);
        }
        goto LABEL_52;
      }
      if (frame >= 1)
        break;
LABEL_52:
      ++v20;
      ++v24->frame;
      if (number == v20)
      {
        param = v3->param;
        goto LABEL_55;
      }
    }
    if (scale_f)
    {
      v26 = (radius * frame) / scale_f;
      v24->radius = v26;
      p_radius = &v24->radius;
      if (v26 <= radius)
      {
          goto LABEL_40;
LABEL_26:
LABEL_40:
        v29 = v3->pPart;
        if (v20 >= LODWORD(v29->max_length))
        {
LABEL_41:
        }
        goto LABEL_42;
      }
    }
    else
    {
      p_radius = &v24->radius;
    }
    *p_radius = radius;
      goto LABEL_40;
    goto LABEL_26;
  }
  v21 = 0;
LABEL_55:
  hPoly = v3->hPoly;
  p_hPoly = &v3->hPoly;
  ++*(p_hPoly - 4);
  sub_854710(&param->fields, 0);
  sub_854930(&hPoly->pos, 0);
  p_pos = &(*p_hPoly)->pos;
  sub_854710(&(*(p_hPoly - 4))->fields, 1u);
  sub_854930(p_pos, 1u);
  v41 = &(*p_hPoly)->pos;
  sub_854710(&(*(p_hPoly - 4))->fields, 2u);
  sub_854930(v41, 2u);
  (*p_hPoly)->scale = *(p_hPoly - 2);
  if (v21 >= 1)
  {
    dds3FlashPolyListDraw(p_hPoly, v21, v43);
  }
}

// 0x12015c0
void effPCPFlashPolySphereExpDrawOff(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3FlashPolyList_t_o **v8;
  u64 v9[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphereExp_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphereExp_tag, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = &v3[3];
  dds3FlashPolyListDrawOff(v8);
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
  v20 = *&def_dir.x;
  v21 = def_dir.z;
  *&static_fields = def_dir.w;
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
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphereExp_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphereExp_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[2].klass) = abgr;
}

// 0x1200b10
void effPCPFlashPolySphereExpSetPosition(void **hData, sdfVector4_t pPos) {
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
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphereExp_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphereExp_tag, v12);
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

// 0x1200d20
void effPCPFlashPolySphereExpSetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphereExp_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphereExp_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *&(*hData)[2].monitor = scale;
}

// 0x11fb2d0
void effPCPFlashPolySpherePartInit(effPCPFlashPolySphere_tag **pFlashPoly, s32 number, sdfVector4_t pLook) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  struct effPCPFlashPolySpherePart_tag_array *pPart;
  f32 *v12;
  f32 v13;
  f32 v14;
  f32 rotate;
  UnityEngine_Vector4_o v16;
  UnityEngine_Vector4_o v17;

  w = pLook.w;
  z = pLook.z;
  y = pLook.y;
  x = pLook.x;
  *&v16.x = 0;
  *&v16.z = 0;
  pPart = (*pFlashPoly)->pPart;
  v12 = pPart->m_Items[number];
  *&v16.x = 0;
  *&v16.z = 0;
  DDS3EFFECT_RAND_PM();
  sub_854930(&v16, 0);
  DDS3EFFECT_RAND_PM();
  sub_854930(&v16, 1u);
  DDS3EFFECT_RAND_PM();
  sub_854930(&v16, 2u);
  SDF_VU0__LOADVECTOR(v16);
  v17.x = x;
  v17.y = y;
  v17.z = z;
  v17.w = w;
  SDF_VU0__LOADVECTOR_B(v17);
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v16);
  sub_854710(&v16, 0);
  sub_854930((v12 + 8), 0);
  sub_854710(&v16, 1u);
  sub_854930((v12 + 8), 1u);
  sub_854710(&v16, 2u);
  sub_854930((v12 + 8), 2u);
  v13 = ((DDS3EFFECT_RAND_F() * 0.3) + 0.7) * (*pFlashPoly)->param->radius;
  v12[14] = v13;
  v12[7] = v13;
  v14 = ((DDS3EFFECT_RAND_F() * 0.5) + 0.5) * 0.5;
  v12[12] = (*pFlashPoly)->param->width_in * v14;
  v12[13] = v14 * (*pFlashPoly)->param->width_out;
  rotate = (*pFlashPoly)->param->rotate;
  v12[6] = rotate * DDS3EFFECT_RAND_PM();
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
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphere_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphere_tag, v10);
      if ((v10[0] & 1) != 0)
        v8 = v10[2];
      else
        v8 = v10 + 1;
      v9 = sub_8C4940(v8);
    }
    HIDWORD(v5[2].klass) = abgr;
  }
}

// 0x11fad80
void effPCPFlashPolySphereSetPosition(void **hData, sdfVector4_t pPos) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  Il2CppObject *v8;
  Il2CppClass *klass;
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
    klass = v8->klass;
    if (v8->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFlashPolySphere_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFlashPolySphere_tag, v13);
      if ((v13[0] & 1) != 0)
        v11 = v13[2];
      else
        v11 = v13 + 1;
      v12 = sub_8C4940(v11);
    }
    v14.x = x;
    v14.y = y;
    v14.z = z;
    v14.w = w;
    SDF_VU0__COPYVECTOR(&v8[1].klass->_1.name, v14);
  }
}

// 0x11fafc0
void effPCPFlashPolySphereSetScale(void **hData, f32 scale) {
  f32 *v5;
  s64 v6;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  v5 = *hData;
  if (*hData)
  {
    v6 = *v5;
    if (*(*v5 + 288LL) < typeHierarchyDepth
      || *(*(v6 + 200) + 8 * typeHierarchyDepth - 8) != effPCPFlashPolySphere_tag)
    {
      sub_8FC2C0(*(v6 + 64), effPCPFlashPolySphere_tag, v10);
      if ((v10[0] & 1) != 0)
        v8 = v10[2];
      else
        v8 = v10 + 1;
      v9 = sub_8C4940(v8);
    }
    v5[10] = scale;
  }
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
