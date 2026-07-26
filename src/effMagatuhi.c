#include "types.h"

typedef struct XRD773Unity_CommonMesh XRD773Unity_CommonMesh;
typedef struct XRD773Unity_GraphicManager XRD773Unity_GraphicManager;
typedef struct XRD773Unity_GraphicManager_CommonObject XRD773Unity_GraphicManager_CommonObject;
typedef struct dds3MagaFuncTable_t dds3MagaFuncTable_t;
typedef struct dds3MagatuhiBill_tag dds3MagatuhiBill_tag;
typedef struct dds3MagatuhiPar_tag dds3MagatuhiPar_tag;
typedef struct effBezier4P_t effBezier4P_t;
typedef struct effHandle_t effHandle_t;
typedef struct effMagaCylinderParam_t effMagaCylinderParam_t;
typedef struct effMagaCylinder_tag effMagaCylinder_tag;
typedef struct effMagaP4Point_t effMagaP4Point_t;
typedef struct effMagaPoint4Param_t effMagaPoint4Param_t;
typedef struct effMagaPoint4_tag effMagaPoint4_tag;
typedef struct effMagaSCArea_t effMagaSCArea_t;
typedef struct effMagaSmokeConvParam_t effMagaSmokeConvParam_t;
typedef struct effMagaSmokeConv_tag effMagaSmokeConv_tag;
typedef struct effMagaSmokeParam_t effMagaSmokeParam_t;
typedef struct effMagaSmoke_tag effMagaSmoke_tag;
typedef struct effMagaSpiralParam_t effMagaSpiralParam_t;
typedef struct effMagaSpiral_tag effMagaSpiral_tag;
typedef struct effMagatuhiParams_t effMagatuhiParams_t;
typedef struct effMagatuhi_tag effMagatuhi_tag;
typedef struct sdfRandCB_t sdfRandCB_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

struct effMagatuhi_tag {
    effMagatuhiParams_t *params;
    dds3MagatuhiBill_tag *hMagaBill;
};

static u16 **dds3MagatuhiUVBuff[UNKNOWN_ARRAY_SIZE];
static dds3MagaFuncTable_t *EffMagatuhiParTable[5];

void ClearUseIndex(XRD773Unity_CommonMesh *this);
XRD773Unity_CommonMesh *GetMesh(XRD773Unity_GraphicManager *this, s32 index, bool outlinechk);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__ADDVECTOR_A_C(void);
void SDF_VU0__APPLYMATRIX(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__COPYVECTOR_A_TO_B(void);
void SDF_VU0__COPYVECTOR_A_TO_C(void);
void SDF_VU0__COPYVECTOR_C_TO_B(void);
f32 SDF_VU0__GETLENGTH(void);
void SDF_VU0__INTERPOLATE(f32 rate);
void SDF_VU0__LOADMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__MULVECTOR(void);
void SDF_VU0__NORMALIZE(void);
void SDF_VU0__OUTERPRODUCT(void);
sdfVector4_t SDF_VU0__Retdds3ColorItoF(u32 rgba, f32 ratio);
void SDF_VU0__STOREIDENTITY(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
u32 SDF_VU0__dds3ColorFtoI(f32 ratio);
void SDF_VU0__dds3ColorItoF(u32 rgba);
void SetActive(XRD773Unity_GraphicManager_CommonObject *this, bool act);
void SetAutoHide(XRD773Unity_GraphicManager_CommonObject *this, bool act);
void SetColor_20241296(XRD773Unity_CommonMesh *this, sdfColor_t **col);
void SetIndexTable(XRD773Unity_CommonMesh *this, s32 **idx);
void SetMatTexture(XRD773Unity_CommonMesh *this, void *texture);
void SetPosition_20241056(XRD773Unity_CommonMesh *this, sdfVector3_t **pos);
void SetUvTable_20243232(XRD773Unity_CommonMesh *this, sdfVector2_t **pos);
effBezier4P_t *dds3Bezier4PCreate(u32 number);
s32 dds3Bezier4PRun(effBezier4P_t **pEffBezier4P, u32 index, sdfVector4_t *pOut);
void **dds3BillboardGetGeneralPtexture(s32 number);
sdfTexHandle_t *dds3BillboardGetGeneralTex(s32 number);
dds3MagatuhiBill_tag *dds3MagatuhiBillCreate(u32 number, u32 point, f32 scale, u32 blend, f32 t);
void dds3MagatuhiBillDraw(dds3MagatuhiBill_tag *hMagaBill, char *callname);
void dds3MagatuhiBillPartsInit(dds3MagatuhiBill_tag **hMagaBill, u32 index);
void dds3MagatuhiBillSetVertex(dds3MagatuhiBill_tag **hMagaBill, u32 index, sdfVector4_t pV);
dds3MagatuhiPar_tag *dds3MagatuhiParCreateTbl(u16 type, void *pData, s32 bPos);
u32 effColorBlend(u32 abgr0, u32 abgr1, f32 rate);
void effMagaCylinderParam_t__bCopy(effMagaCylinderParam_t *this, u8 **bytedata, s32 *bPos);
void effMagaCylinderParam_t__pClone(effMagaCylinderParam_t *this, effMagaCylinderParam_t **dst);
void effMagaCylinderPartInit(effMagaCylinder_tag **pMagaCylinder, u32 index);
void effMagaCylinderRandomize(effHandle_t **hEffect);
void effMagaP4Randomize(effHandle_t **hEffect);
void effMagaPoint4Param_t__bCopy(effMagaPoint4Param_t *this, u8 **bytedata, s32 *bPos);
void effMagaPoint4Param_t__pClone(effMagaPoint4Param_t *this, effMagaPoint4Param_t **dst);
void effMagaPoint4PartInit(effMagaPoint4_tag **pMagaPoint4, u32 index);
void effMagaSmokeConvParam_t__bCopy(effMagaSmokeConvParam_t *this, u8 **bytedata, s32 *bPos);
void effMagaSmokeConvParam_t__pClone(effMagaSmokeConvParam_t *this, effMagaSmokeConvParam_t **dst);
void effMagaSmokeConvPartInit(effMagaSmokeConv_tag **pMagaSmokeConv, u32 index);
void effMagaSmokeParam_t__bCopy(effMagaSmokeParam_t *this, u8 **bytedata, s32 *bPos);
void effMagaSmokeParam_t__pClone(effMagaSmokeParam_t *this, effMagaSmokeParam_t **dst);
void effMagaSmokePartInit(effMagaSmoke_tag **pMagaSmoke, u32 index);
void effMagaSmokeRandomize(effHandle_t **hEffect);
void effMagaSpiralParam_t__bCopy(effMagaSpiralParam_t *this, u8 **bytedata, s32 *bPos);
void effMagaSpiralParam_t__pClone(effMagaSpiralParam_t *this, effMagaSpiralParam_t **dst);
void effMagaSpiralPartInit(effMagaSpiral_tag **pMagaSpiral, u32 index);
void effMagaSpiralRandomize(effHandle_t **hEffect);
effMagatuhi_tag *effMagatuhiCreate(effMagatuhiParams_t *pParams);
void effMagatuhiDelete(effMagatuhi_tag **pMagatuhi);
f32 sdfCos(f32 aRadius);
u32 sdfGetRand(sdfRandCB_t **aCB);
f32 sdfGetRandFloat(sdfRandCB_t **aCB);
f32 sdfSin(f32 aRadius);

// 0x16b5860
void InitMagatuhiEdtorProcess(void) {
  ;
}

// 0x16a8340
dds3MagatuhiBill_tag *dds3MagatuhiBillCreate(u32 number, u32 point, f32 scale, u32 blend, f32 t) {
  u64 v11;
  dds3MagatuhiBill_tag_o *v12;
  struct dds3MagatuhiBillTail_tag_array *v13;
  u32 *pTail;
  u64 v16;
  u64 v17;
  u64 *v18;
  struct System_UInt16_array_array_array *v22;
  u64 i;
  u32 *dds3MagatuhiUVBuff;
  s64 *v39;
  s64 *v40;
  struct System_UInt16_array_array_array *v42;
  System_UInt16_array_array *v44;
  s64 *v45;
  s64 *v46;
  struct System_UInt16_array_array_array *v48;
  System_UInt16_array_array *v49;
  System_UInt16_array *v50;
  struct System_UInt16_array_array_array *v51;
  System_UInt16_array_array *v52;
  System_UInt16_array *v53;
  struct System_UInt16_array_array_array *v55;
  System_UInt16_array_array *v57;
  s64 *v58;
  s64 *v59;
  struct System_UInt16_array_array_array *v61;
  System_UInt16_array_array *v63;
  System_UInt16_array *v65;
  struct System_UInt16_array_array_array *v67;
  System_UInt16_array_array *v69;
  System_UInt16_array *v71;
  struct System_UInt16_array_array_array *v73;
  System_UInt16_array_array *v75;
  s64 *v76;
  s64 *v77;
  struct System_UInt16_array_array_array *v79;
  System_UInt16_array_array *v81;
  System_UInt16_array *v83;
  struct System_UInt16_array_array_array *v85;
  System_UInt16_array_array *v87;
  System_UInt16_array *v89;
  struct System_UInt16_array_array_array *v91;
  System_UInt16_array_array *v93;
  s64 *v94;
  s64 *v96;
  struct System_UInt16_array_array_array *v98;
  System_UInt16_array_array *v100;
  System_UInt16_array *v102;
  struct System_UInt16_array_array_array *v104;
  System_UInt16_array_array *v106;
  System_UInt16_array *v107;
  u32 v108;
  dds3MagatuhiBill_tag_o *hMagaBill;

  v11 = point * number;
  v12 = Allocate(dds3MagatuhiBill_tag);
  _ctor(v12, 0);
  hMagaBill = v12;
  v12->number = number;
  v12->point = point;
  v12->scale = scale;
  v12->t = t;
  v12->blend = blend;
  v12->pVertex = NewSpecific(UnityEngine_Vector4, v11);
  v12->pScale = NewSpecific(f32, v11);
  v12->pVC = NewSpecific(uint, v11);
  v12->pRGBA = NewSpecific(uint, v11);
  v12->pCurrent = NewSpecific(ushort, v11);
  v12->pCount = NewSpecific(ushort, v11);
  v13 = NewSpecific(dds3MagatuhiBillTail_tag, v11);
  v12->pTail = v13;
  if (v11)
  {
    pTail = v13;
    v16 = 0;
    v17 = v11 - 1;
    while (1)
    {
      v18 = Allocate(dds3MagatuhiBillTail_tag);
      _ctor(v18, 0);
      *&pTail[2 * v16 + 8] = v18;
      if (v17 == v16)
        break;
      pTail = v12->pTail;
      ++v16;
    }
  }
  v12->hMem = 0;
  v12->hTex = dds3BillboardGetGeneralTex(0);
  v22 = NewSpecific(ushort____, 0x20u);
  dds3MagatuhiUVBuff = v22;
  for (i = 0; i != 32; ++i)
  {
    v39 = NewSpecific(ushort__, 4u);
    v40 = v39;
    *&dds3MagatuhiUVBuff[2 * i + 8] = v40;
    v42 = dds3MagatuhiUVBuff;
    v44 = v42->m_Items[i];
    v45 = NewSpecific(ushort, 2u);
    v46 = v45;
    v44->m_Items[0] = v46;
    v48 = dds3MagatuhiUVBuff;
    v49 = v48->m_Items[i];
    v50 = v49->m_Items[0];
    v50->m_Items[0] = 0;
    v51 = dds3MagatuhiUVBuff;
    v52 = v51->m_Items[i];
    v53 = v52->m_Items[0];
    v53->m_Items[1] = 0;
    v55 = dds3MagatuhiUVBuff;
    v57 = v55->m_Items[i];
    v58 = NewSpecific(ushort, 2u);
    v59 = v58;
    v57->m_Items[1] = v59;
    v61 = dds3MagatuhiUVBuff;
    v63 = v61->m_Items[i];
    v65 = v63->m_Items[1];
    v65->m_Items[0] = 1024;
    v67 = dds3MagatuhiUVBuff;
    v69 = v67->m_Items[i];
    v71 = v69->m_Items[1];
    v71->m_Items[1] = 0;
    v73 = dds3MagatuhiUVBuff;
    v75 = v73->m_Items[i];
    v76 = NewSpecific(ushort, 2u);
    v77 = v76;
    v75->m_Items[2] = v77;
    v79 = dds3MagatuhiUVBuff;
    v81 = v79->m_Items[i];
    v83 = v81->m_Items[2];
    v83->m_Items[0] = 1024;
    v85 = dds3MagatuhiUVBuff;
    v87 = v85->m_Items[i];
    v89 = v87->m_Items[2];
    v89->m_Items[1] = 1024;
    v91 = dds3MagatuhiUVBuff;
    v93 = v91->m_Items[i];
    v94 = NewSpecific(ushort, 2u);
    v96 = v94;
    v93->m_Items[3] = v96;
    v98 = dds3MagatuhiUVBuff;
    v100 = v98->m_Items[i];
    v102 = v100->m_Items[3];
    v102->m_Items[0] = 0;
    v104 = dds3MagatuhiUVBuff;
    v106 = v104->m_Items[i];
    v107 = v106->m_Items[3];
    v107->m_Items[1] = 1024;
  }
  if (number)
  {
    v108 = 0;
    do
    {
      dds3MagatuhiBillPartsInit(&hMagaBill, v108++);
    }
    while (number != v108);
  }
  return v12;
}

// 0x16a8e10
void dds3MagatuhiBillDelete(dds3MagatuhiBill_tag *hMagaBill) {
  ;
}

// 0x16a8e20
void dds3MagatuhiBillDraw(dds3MagatuhiBill_tag *hMagaBill, char *callname) {
    SDF_VU0__STOREIDENTITY(0);
    ClearUseIndex(0);
    GetMesh(0, 0, 0);
    SetAutoHide(0, 0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    SDF_VU0__dds3ColorItoF(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__MULVECTOR();
    SDF_VU0__dds3ColorFtoI(0);
    SDF_VU0__Retdds3ColorItoF(0, 0);
    SetPosition_20241056(0, 0);
    SetIndexTable(0, 0);
    SetColor_20241296(0, 0);
    SetUvTable_20243232(0, 0);
    dds3BillboardGetGeneralPtexture(0);
    SetMatTexture(0, 0);
    SetActive(0, 0);
}

// 0x16a8cb0
void dds3MagatuhiBillPartsInit(dds3MagatuhiBill_tag **hMagaBill, u32 index) {
  struct System_UInt16_array *pCurrent;
  s64 v5;
  struct System_UInt16_array *pCount;
  struct System_UInt32_array *pRGBA;
  struct dds3MagatuhiBillTail_tag_array *pTail;
  s64 *v13;
  struct dds3MagatuhiBillTail_tag_array *v14;

  pCurrent = (*hMagaBill)->pCurrent;
  v5 = index;
  pCurrent->m_Items[index] = 0;
  pCount = (*hMagaBill)->pCount;
  pCount->m_Items[index] = 0;
  pRGBA = (*hMagaBill)->pRGBA;
  pRGBA->m_Items[index] = -2139062144;
  pTail = (*hMagaBill)->pTail;
  v13 = pTail->m_Items[index];
  v13[2] = 1086918619;
  v13[3] = 1078530011;
  v14 = (*hMagaBill)->pTail;
  v14->m_Items[v5] = v13;
}

// 0x16aa8f0
void dds3MagatuhiBillReset(dds3MagatuhiBill_tag **hMagaBill, u32 index) {
  dds3MagatuhiBillPartsInit(hMagaBill, index);
}

// 0x16aa630
void dds3MagatuhiBillSetRGBA(dds3MagatuhiBill_tag **hMagaBill, u32 index, u32 abgr) {
  struct System_UInt32_array *pRGBA;

  pRGBA = (*hMagaBill)->pRGBA;
  pRGBA->m_Items[index] = abgr;
}

// 0x16aa690
void dds3MagatuhiBillSetVC(dds3MagatuhiBill_tag **hMagaBill, u32 abgr_s, u32 abgr_e) {
  dds3MagatuhiBill_tag_o *v4;
  s64 point;
  f32 v6;
  f32 v7;
  f32 v8;
  u64 v12;
  s64 v13;
  struct System_UInt32_array *pVC;
  u32 v15;

  v4 = *hMagaBill;
  point = (*hMagaBill)->point;
  if ((*hMagaBill)->point)
  {
    v6 = point;
    v7 = 1.0 / v6;
    v8 = 0.0;
    v12 = 0;
    v13 = point - 1;
    while (1)
    {
      pVC = v4->pVC;
      v15 = effColorBlend(abgr_s, abgr_e, v8, *&abgr_e);
      pVC->m_Items[v12] = v15;
      if (v13 == v12)
        break;
      v4 = *hMagaBill;
      ++v12;
      v8 = v7 + v8;
    }
  }
}

// 0x16a9bc0
void dds3MagatuhiBillSetVertex(dds3MagatuhiBill_tag **hMagaBill, u32 index, sdfVector4_t pV) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    sdfGetRandFloat(0);
    sdfSin(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__COPYVECTOR_C_TO_B();
    SDF_VU0__OUTERPRODUCT();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__GETLENGTH();
    SDF_VU0__MULVECTOR();
}

// 0x16ad470
void *dds3MagatuhiGetHandle(dds3MagatuhiPar_tag *hMagaPar) {
  return hMagaPar->pHandle;
}

// 0x16b0b30
u32 dds3MagatuhiGetType(dds3MagatuhiPar_tag *hMagaPar) {
  return hMagaPar->type;
}

// 0x16b5410
dds3MagatuhiPar_tag *dds3MagatuhiParCopy(void **hData, s32 bPos) {
    dds3MagatuhiParCreateTbl(0, 0, 0);
    return 0;
}

// 0x16b4160
dds3MagatuhiPar_tag *dds3MagatuhiParCreate(u16 type, void *pData, s32 bPos) {
  dds3MagatuhiPar_tag_o *v7;
  struct dds3MagaFuncTable_t_array *EffMagatuhiParTable;

  v7 = Allocate(dds3MagatuhiPar_tag);
  _ctor(v7, 0);
  v7->pHandle = Invoke(
                         EffMagatuhiParTable->m_Items[type]->Create,
                         pData,
                         bPos,
                         0,
                         0);
  v7->type = type;
  return v7;
}

// 0x16b4250
dds3MagatuhiPar_tag *dds3MagatuhiParCreateTbl(u16 type, void *pData, s32 bPos) {
  dds3MagatuhiPar_tag_o *v7;
  struct dds3MagaFuncTable_t_array *EffMagatuhiParTable;

  v7 = Allocate(dds3MagatuhiPar_tag);
  _ctor(v7, 0);
  v7->pHandle = Invoke(
                         EffMagatuhiParTable->m_Items[type]->Create,
                         pData,
                         bPos,
                         1,
                         0);
  v7->type = type;
  return v7;
}

// 0x16b44b0
void dds3MagatuhiParDelete(void **hData) {
}

// 0x16b4350
void dds3MagatuhiParDraw(void **hData) {
}

// 0x16b4340
void dds3MagatuhiParDrawOff(void **hData) {
  ;
}

// 0x16b5010
u8 dds3MagatuhiParGetLoop(void **hData) {
    return 0;
}

// 0x16b4650
u16 dds3MagatuhiParGetState(void **hData) {
  return 1;
}

// 0x16b4610
void dds3MagatuhiParReset(void **hData) {

}

// 0x16b4c10
void dds3MagatuhiParSetLoop(void **hData, u8 loop) {
}

// 0x16b4690
void dds3MagatuhiParSetPosition(void **hData, sdfVector4_t pPos) {
}

// 0x16b4a50
void dds3MagatuhiParSetRGBA(void **hData, u32 abgr) {
}

// 0x16b4870
void dds3MagatuhiParSetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
}

// 0x16b5820
void dds3MagatuhiParSetScale(void **hData, f32 scale) {

}

// 0x16af2d0
effMagaCylinder_tag *effMagaCylinderCreate(void *pData, s32 bPos, bool tbldata) {
    effMagaCylinderParam_t__bCopy(0, 0, 0);
    effMagaCylinderParam_t__pClone(0, 0);
    SDF_VU0__STOREIDENTITY(0);
    effMagatuhiCreate(0);
    sdfGetRand(0);
    return 0;
}

// 0x16af700
void effMagaCylinderDelete(void **pData) {
    effMagatuhiDelete(0);
}

// 0x16afc90
void effMagaCylinderDraw(void **pData) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    SDF_VU0__LOADMATRIX(0);
    sdfCos(0);
    sdfSin(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(0);
    dds3MagatuhiBillSetVertex(0, 0, (sdfVector4_t){0});
    effMagaCylinderPartInit(0, 0);
    sdfGetRand(0);
    dds3MagatuhiBillDraw(0, 0);
}

// 0x16af820
void effMagaCylinderPartInit(effMagaCylinder_tag **pMagaCylinder, u32 index) {
    sdfGetRandFloat(0);
    dds3MagatuhiBillPartsInit(0, 0);
}

// 0x16b05a0
void effMagaCylinderRandomize(effHandle_t **hEffect) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    SDF_VU0__LOADMATRIX(0);
    effMagaCylinderPartInit(0, 0);
    sdfGetRand(0);
    sdfCos(0);
    sdfSin(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(0);
    dds3MagatuhiBillSetVertex(0, 0, (sdfVector4_t){0});
}

// 0x16b0260
void effMagaCylinderSetPosition(void **pData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x16b0380
void effMagaCylinderSetRGBA(void **pData, u32 abgr) {
}

// 0x16b0470
void effMagaCylinderSetRotateMatrix(void **pData, sdfMatrix4_t *pMatrix) {
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__STOREMATRIX(0);
}

// 0x16aee40
void effMagaP4Randomize(effHandle_t **hEffect) {
    effMagaPoint4PartInit(0, 0);
    sdfGetRand(0);
    dds3Bezier4PRun(0, 0, 0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__INTERPOLATE(0);
    SDF_VU0__STOREVECTOR(0);
    dds3MagatuhiBillSetVertex(0, 0, (sdfVector4_t){0});
}

// 0x16aead0
void effMagaP4SetPoint(effHandle_t **hEffect, effMagaP4Point_t *pP4Point) {
}

// 0x16ad480
effMagaPoint4_tag *effMagaPoint4Create(void *pData, s32 bPos, bool tbldata) {
    effMagaPoint4Param_t__bCopy(0, 0, 0);
    effMagaPoint4Param_t__pClone(0, 0);
    effMagatuhiCreate(0);
    dds3Bezier4PCreate(0);
    sdfGetRand(0);
    return 0;
}

// 0x16ad8b0
void effMagaPoint4Delete(void **pData) {
    effMagatuhiDelete(0);
}

// 0x16ae650
void effMagaPoint4Draw(void **pData) {
    effMagaPoint4PartInit(0, 0);
    dds3Bezier4PRun(0, 0, 0);
    dds3MagatuhiBillSetVertex(0, 0, (sdfVector4_t){0});
    sdfGetRand(0);
    dds3MagatuhiBillDraw(0, 0);
}

// 0x16ad9d0
void effMagaPoint4PartInit(effMagaPoint4_tag **pMagaPoint4, u32 index) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__STOREVECTOR(0);
    sdfGetRandFloat(0);
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__OUTERPRODUCT();
    SDF_VU0__NORMALIZE();
    SDF_VU0__MULVECTOR();
    SDF_VU0__ADDVECTOR_A_C();
    SDF_VU0__ADDVECTOR();
    dds3MagatuhiBillPartsInit(0, 0);
}

// 0x16b3f60
void effMagaRandomize(effHandle_t **hEffect) {
    effMagaP4Randomize(0);
    effMagaCylinderRandomize(0);
    effMagaSpiralRandomize(0);
    effMagaSmokeRandomize(0);
}

// 0x16ad1c0
void effMagaSCSetArea(effHandle_t **hEffect, effMagaSCArea_t *pMagaSCArea) {
}

// 0x16aad00
effMagaSmokeConv_tag *effMagaSmokeConvCreate(void *pData, s32 bPos, bool tbldata) {
    effMagaSmokeConvParam_t__bCopy(0, 0, 0);
    effMagaSmokeConvParam_t__pClone(0, 0);
    effMagatuhiCreate(0);
    dds3Bezier4PCreate(0);
    sdfGetRand(0);
    return 0;
}

// 0x16ab400
void effMagaSmokeConvDelete(void **pData) {
    effMagatuhiDelete(0);
}

// 0x16abd30
void effMagaSmokeConvDraw(void **pData) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    effMagaSmokeConvPartInit(0, 0);
    sdfSin(0);
    SDF_VU0__GETLENGTH();
    SDF_VU0__NORMALIZE();
    SDF_VU0__OUTERPRODUCT();
    sdfGetRandFloat(0);
    dds3Bezier4PRun(0, 0, 0);
    dds3MagatuhiBillSetVertex(0, 0, (sdfVector4_t){0});
    sdfGetRand(0);
    dds3MagatuhiBillDraw(0, 0);
}

// 0x16ab530
void effMagaSmokeConvPartInit(effMagaSmokeConv_tag **pMagaSmokeConv, u32 index) {
    sdfGetRandFloat(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    dds3MagatuhiBillPartsInit(0, 0);
}

// 0x16b2380
effMagaSmoke_tag *effMagaSmokeCreate(void *pData, s32 bPos, bool tbldata) {
    effMagaSmokeParam_t__bCopy(0, 0, 0);
    effMagaSmokeParam_t__pClone(0, 0);
    SDF_VU0__STOREIDENTITY(0);
    effMagatuhiCreate(0);
    sdfGetRand(0);
    return 0;
}

// 0x16b27b0
void effMagaSmokeDelete(void **pData) {
    effMagatuhiDelete(0);
}

// 0x16b2fb0
void effMagaSmokeDraw(void **pData) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    SDF_VU0__LOADMATRIX(0);
    effMagaSmokePartInit(0, 0);
    sdfSin(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(0);
    dds3MagatuhiBillSetVertex(0, 0, (sdfVector4_t){0});
    sdfGetRand(0);
    dds3MagatuhiBillDraw(0, 0);
}

// 0x16b28d0
void effMagaSmokePartInit(effMagaSmoke_tag **pMagaSmoke, u32 index) {
    sdfGetRandFloat(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    dds3MagatuhiBillPartsInit(0, 0);
}

// 0x16b3910
void effMagaSmokeRandomize(effHandle_t **hEffect) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    SDF_VU0__LOADMATRIX(0);
    effMagaSmokePartInit(0, 0);
    sdfGetRand(0);
    sdfSin(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(0);
    dds3MagatuhiBillSetVertex(0, 0, (sdfVector4_t){0});
}

// 0x16b35d0
void effMagaSmokeSetPosition(void **pData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x16b36f0
void effMagaSmokeSetRGBA(void **pData, u32 abgr) {
}

// 0x16b37e0
void effMagaSmokeSetRotateMatrix(void **pData, sdfMatrix4_t *pMatrix) {
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__STOREMATRIX(0);
}

// 0x16b0b40
effMagaSpiral_tag *effMagaSpiralCreate(void *pData, s32 bPos, bool tbldata) {
    effMagaSpiralParam_t__bCopy(0, 0, 0);
    effMagaSpiralParam_t__pClone(0, 0);
    SDF_VU0__STOREIDENTITY(0);
    effMagatuhiCreate(0);
    sdfGetRand(0);
    return 0;
}

// 0x16b0f70
void effMagaSpiralDelete(void **pData) {
    effMagatuhiDelete(0);
}

// 0x16b1510
void effMagaSpiralDraw(void **pData) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    SDF_VU0__LOADMATRIX(0);
    sdfCos(0);
    sdfSin(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(0);
    dds3MagatuhiBillSetVertex(0, 0, (sdfVector4_t){0});
    effMagaSpiralPartInit(0, 0);
    sdfGetRand(0);
    dds3MagatuhiBillDraw(0, 0);
}

// 0x16b1090
void effMagaSpiralPartInit(effMagaSpiral_tag **pMagaSpiral, u32 index) {
    sdfGetRandFloat(0);
    dds3MagatuhiBillPartsInit(0, 0);
}

// 0x16b1dd0
void effMagaSpiralRandomize(effHandle_t **hEffect) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    SDF_VU0__LOADMATRIX(0);
    effMagaSpiralPartInit(0, 0);
    sdfGetRand(0);
    sdfCos(0);
    sdfSin(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(0);
    dds3MagatuhiBillSetVertex(0, 0, (sdfVector4_t){0});
}

// 0x16b1a90
void effMagaSpiralSetPosition(void **pData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x16b1bb0
void effMagaSpiralSetRGBA(void **pData, u32 abgr) {
}

// 0x16b1ca0
void effMagaSpiralSetRotateMatrix(void **pData, sdfMatrix4_t *pMatrix) {
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__STOREMATRIX(0);
}

// 0x16aa970
effMagatuhi_tag *effMagatuhiCreate(effMagatuhiParams_t *pParams) {
  Il2CppObject *v3;
  f32 scale;
  u32 number;
  u32 tail;
  u32 blend;
  f32 t;
  dds3MagatuhiBill_tag_o *monitor;
  s64 point;
  f32 v14;
  f32 v15;
  Il2CppClass *klass;
  u32 namespaze_high;
  u32 data;
  f32 v19;
  u64 v20;
  s64 v21;
  struct System_UInt32_array *pVC;
  u32 v23;

  v3 = Allocate(effMagatuhi_tag);
  _ctor(v3, 0);
  v3[1].klass = pParams;
  scale = pParams->scale;
  number = pParams->number;
  tail = pParams->tail;
  blend = pParams->blend;
  t = pParams->t;
  monitor = dds3MagatuhiBillCreate(number, tail, scale, blend, t);
  v3[1].monitor = monitor;
  point = monitor->point;
  if (monitor->point)
  {
    v14 = point;
    v15 = 1.0 / v14;
    klass = v3[1].klass;
    namespaze_high = HIDWORD(klass->_1.namespaze);
    data = klass->_1.byval_arg.data;
    v19 = 0.0;
    v20 = 0;
    v21 = point - 1;
    while (1)
    {
      pVC = monitor->pVC;
      v23 = effColorBlend(namespaze_high, data, v19);
      pVC->m_Items[v20] = v23;
      if (v21 == v20)
        break;
      monitor = v3[1].monitor;
      ++v20;
      v19 = v15 + v19;
    }
  }
  return v3;
}

// 0x16aaad0
void effMagatuhiDelete(effMagatuhi_tag **pMagatuhi) {
  struct dds3MagatuhiBill_tag_o *hMagaBill;
  struct XRD773Unity_CommonMesh_array **p_pMesh;
  struct XRD773Unity_CommonMesh_array *v5;
  struct XRD773Unity_CommonMesh_array *pMesh;
  u32 max_length;
  s64 v8;
  u64 v9;
  UnityEngine_Object_o *v11;
  struct XRD773Unity_CommonMesh_array *v12;
  UnityEngine_Object_o *gameObject;
  struct XRD773Unity_CommonMesh_array *v16;
  struct dds3MagatuhiBill_tag_o *v18;
  s64 v19;

  if (*pMagatuhi)
  {
    hMagaBill = (*pMagatuhi)->hMagaBill;
    if (hMagaBill)
    {
      pMesh = hMagaBill->pMesh;
      p_pMesh = &hMagaBill->pMesh;
      v5 = pMesh;
      if (pMesh)
      {
        if (v5->max_length >= 1)
        {
          max_length = v5->max_length;
          v8 = 4;
          do
          {
            v9 = v8 - 4;
            v11 = *(&v5->obj.klass + v8);
            if (op_Inequality(v11, 0, 0))
            {
              v12 = (*pMagatuhi)->hMagaBill->pMesh;
              gameObject = get_gameObject(*(&v12->obj.klass + v8), 0);
              {
              }
              Destroy_27360000(gameObject);
              v16 = (*pMagatuhi)->hMagaBill->pMesh;
              *(&v16->obj.klass + v8) = 0;
            }
            v18 = (*pMagatuhi)->hMagaBill;
            v5 = v18->pMesh;
            max_length = v5->max_length;
            v19 = v8 - 3;
            ++v8;
          }
          while (v19 < max_length);
          p_pMesh = &v18->pMesh;
        }
        *p_pMesh = 0;
      }
    }
  }
  dds3MagatuhiUVBuff = 0;
}

// 0x16aac80
void effMagatuhiDraw(effMagatuhi_tag **pMagatuhi, char *callname) {
  dds3MagatuhiBill_tag_o *hMagaBill;

  hMagaBill = (*pMagatuhi)->hMagaBill;
  dds3MagatuhiBillDraw(hMagaBill, callname);
}
