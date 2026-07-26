#include "types.h"

typedef struct Eff_ModelTrackPolyParam_t Eff_ModelTrackPolyParam_t;
typedef struct XRD773Unity_CommonMesh XRD773Unity_CommonMesh;
typedef struct XRD773Unity_GraphicManager XRD773Unity_GraphicManager;
typedef struct XRD773Unity_GraphicManager_CommonObject XRD773Unity_GraphicManager_CommonObject;
typedef struct billHandle_t billHandle_t;
typedef struct dds3BillAnimResource_tag dds3BillAnimResource_tag;
typedef struct dds3BillResource_tag dds3BillResource_tag;
typedef struct dds3EffectTable_Reset_t dds3EffectTable_Reset_t;
typedef struct dds3EffectTable_Scale_t dds3EffectTable_Scale_t;
typedef struct dds3EffectTable_t dds3EffectTable_t;
typedef struct dds3HermitianTrackPoly_tag dds3HermitianTrackPoly_tag;
typedef struct dds3ParOffsetBuff_t dds3ParOffsetBuff_t;
typedef struct dds3ParticleColorAnim_t dds3ParticleColorAnim_t;
typedef struct dds3Particle_Basic_t dds3Particle_Basic_t;
typedef struct dds3Particle_BlurBuff_t dds3Particle_BlurBuff_t;
typedef struct dds3Particle_Effect_t dds3Particle_Effect_t;
typedef struct dds3Particle_Exp_t dds3Particle_Exp_t;
typedef struct dds3Particle_Nop_t3 dds3Particle_Nop_t3;
typedef struct dds3Particle_Physics_t dds3Particle_Physics_t;
typedef struct dds3Particle_Radiate_t3 dds3Particle_Radiate_t3;
typedef struct dds3Particle_SmokeOffset_t3 dds3Particle_SmokeOffset_t3;
typedef struct dds3Particle_Smoke_t3 dds3Particle_Smoke_t3;
typedef struct dds3Particle_Spark2_t3 dds3Particle_Spark2_t3;
typedef struct dds3Particle_SparkOffset_t3 dds3Particle_SparkOffset_t3;
typedef struct dds3Particle_Spark_t3 dds3Particle_Spark_t3;
typedef struct dds3Particle_SphereAtom_t3 dds3Particle_SphereAtom_t3;
typedef struct dds3Particle_SphereRing_t3 dds3Particle_SphereRing_t3;
typedef struct dds3Particle_SphereSmoke_t3 dds3Particle_SphereSmoke_t3;
typedef struct dds3Particle_SphereSpiral2_t3 dds3Particle_SphereSpiral2_t3;
typedef struct dds3Particle_SphereSpiral_t3 dds3Particle_SphereSpiral_t3;
typedef struct dds3Particle_Spiral_t3 dds3Particle_Spiral_t3;
typedef struct dds3TrackPoly_t dds3TrackPoly_t;
typedef struct effMTPolyListHandle_t effMTPolyListHandle_t;
typedef struct parPhysics_t parPhysics_t;
typedef struct sdfRandCB_t sdfRandCB_t;

static sdfRandCB_t *ParRand;
static s32 SmokeOffset_unique;
static sdfVector4_t parLook;
static sdfVector4_t parTrack_w;
static dds3EffectTable_t *EffParticleTable[13];
static dds3EffectTable_Reset_t *ResetTbl[13];
static dds3EffectTable_Scale_t *ScaleTbl[13];
static s32 exp_uniq;

dds3BillResource_tag *BillboardLoadTex(void *pTex);
void ClearUseIndex(XRD773Unity_CommonMesh *this);
f32 DDS3EFFECT_RAND_F(void);
f32 DDS3EFFECT_RAND_FA(f32 r);
f32 DDS3EFFECT_RAND_PM(void);
void Eff_ModelTrackPolyListColorSet(effMTPolyListHandle_t **hMTPolyList, u32 index, u32 abgr);
effMTPolyListHandle_t *Eff_ModelTrackPolyListCreate(Eff_ModelTrackPolyParam_t *pParam, u32 number);
void Eff_ModelTrackPolyListDelete(effMTPolyListHandle_t **hMTPolyList);
void Eff_ModelTrackPolyListDrawOnly(effMTPolyListHandle_t **hMTPolyList);
void Eff_ModelTrackPolyListDrawOnlyOff(effMTPolyListHandle_t *hMTPolyList);
void Eff_ModelTrackPolyListReset(effMTPolyListHandle_t **hMTPolyList, u32 index);
void Eff_ModelTrackPolyListVertexSet(effMTPolyListHandle_t **hMTPolyList, u32 index, sdfVector4_t **pVertex);
XRD773Unity_CommonMesh *GetMesh(XRD773Unity_GraphicManager *this, s32 index, bool outlinechk);
s32 GetTmxIndex(u8 **bData, s32 bPos);
void LookAtMatrix(sdfVector4_t aTarget, sdfVector4_t aEye, sdfVector4_t aDown);
void MultMatrixNoArg(void);
void ReverseMatrix(void);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__ADDVECTOR_A_C(void);
void SDF_VU0__APPLYMATRIX(void);
void SDF_VU0__APPLYMATRIX_XYZ(void);
void SDF_VU0__COPYMATRIX_B_TO_A(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__COPYVECTOR_A_TO_B(void);
void SDF_VU0__COPYVECTOR_A_TO_C(void);
void SDF_VU0__COPYVECTOR_C_TO_A(void);
void SDF_VU0__COPYVECTOR_C_TO_B(void);
f32 SDF_VU0__GETLENGTH(void);
f32 SDF_VU0__INNERPRODUCT(void);
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
void SDF_VU0__STOREVECTOR_B(sdfVector4_t *p);
void SDF_VU0__STOREVECTOR_C(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
void SDF_VU0__SUBVECTOR_B_A(void);
void SDF_VU0__SWAPVECTOR_A_C(void);
u32 SDF_VU0__dds3ColorFtoI(f32 ratio);
void SDF_VU0__dds3ColorItoF(u32 rgba);
void SetActive(XRD773Unity_GraphicManager_CommonObject *this, bool act);
void SetAutoHide(XRD773Unity_GraphicManager_CommonObject *this, bool act);
void SetExpTextureUnity(billHandle_t **hBillboard, u8 **bytedata, s32 oPos);
void SetRotateMatrixAxis(f32 aAngle, sdfVector4_t aAxis);
void SetUseIndexMax(XRD773Unity_CommonMesh *this, s32 index);
f32 billAlfRaitoGet(void);
void billAlfRaitoSet(f32 raito);
f32 billBriRaitoGet(void);
void billBriRaitoSet(f32 raito);
f32 billCutRaitoGet(void);
f32 billCutRaitoGet2(void);
void billCutRaitoSet(f32 raito);
void *billGetTexture(s32 index);
s32 billGetTextureMax(void);
void billScaleRaitoGet(f32 *par_scl_raito, f32 *eff_scl_raito);
void billScaleRaitoSet(f32 par_scl_raito, f32 eff_scl_raito);
dds3BillAnimResource_tag *dds3BillAnimLoadP2A(void *pData, s32 *bPos, void **pTGA);
billHandle_t *dds3BillboardCopy(billHandle_t *hBillboard);
billHandle_t *dds3BillboardCreate(s32 type, void *pTex, s32 bPos, char *callname);
void dds3BillboardDelete(void **hData);
void dds3BillboardDraw(void **hData);
void dds3BillboardDrawOff(void **hData);
void *dds3BillboardGeneral(s32 number);
void dds3BillboardSetAnimColorAdvMode(billHandle_t **hBillboard);
void dds3BillboardSetAnimKey(billHandle_t **hBillboard, s32 frame);
void dds3BillboardSetMode(billHandle_t **hBillboard, s16 mode);
void dds3BillboardSetScale(billHandle_t **hBillboard, f32 x, f32 y);
u32 dds3ParticleColorAnim(dds3ParticleColorAnim_t *pColAnim, u32 color_now, s32 frame);
void dds3ParticleDrawOff(void **hData);
u8 dds3ParticleGetLoop(void **hData);
u16 dds3ParticleGetState(void **hData);
void dds3ParticleReset(void **hData);
void dds3ParticleSetColorTable(dds3ParticleColorAnim_t **pColAnim, s32 frame);
void dds3ParticleSetLoop(void **hData, u8 loop);
void dds3ParticleSetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix);
void dds3ParticleSetScale(void **hData, f32 scale);
void dds3Particle_BasicCreate(dds3Particle_Basic_t **pParBasic, bool pCopy);
void dds3Particle_BasicDelete(dds3Particle_Basic_t *pParBasic);
void dds3Particle_Basic_t__dCopy(dds3Particle_Basic_t *this, dds3Particle_Basic_t **dst);
dds3Particle_BlurBuff_t *dds3Particle_BlurCreate(u32 number, u16 length, billHandle_t *pBill_Handle);
void dds3Particle_BlurDraw(dds3Particle_BlurBuff_t **hBlur);
void dds3Particle_BlurSet(dds3Particle_BlurBuff_t **hBlur, s32 index, u32 abgr, f32 scale);
void dds3Particle_BlurSetExp(dds3Particle_BlurBuff_t **hBlur, s32 index, sdfVector4_t pPosBase, u32 abgr, dds3ParOffsetBuff_t *pOffBuff, f32 scale);
void dds3Particle_EffectDraw(dds3Particle_Effect_t **pEffect);
s32 dds3Particle_EffectDrawNum(dds3Particle_Effect_t **pEffect);
void dds3Particle_EffectInit(dds3Particle_Effect_t *pEffect, f32 scale_raito);
void dds3Particle_EffectReset(dds3Particle_Effect_t **pEffect, s32 number);
void dds3Particle_EffectSet(dds3Particle_Effect_t **pEffect, s32 index, u32 abgr, f32 scale);
void dds3Particle_Exp_t__pCopy(dds3Particle_Exp_t *this, u8 **bytedata, s32 *pos);
void dds3Particle_NopBuffInit(dds3Particle_Nop_t3 **pNop);
void dds3Particle_Nop_t3__pCopy(dds3Particle_Nop_t3 *this, u8 **bytedata, s32 *bpos);
dds3Particle_Physics_t *dds3Particle_PhysicsCreate(s32 number);
void dds3Particle_RadiateAllBuffInit(void **hData);
void dds3Particle_RadiateBuffInit(dds3Particle_Radiate_t3 **pRadiate, s32 number);
void dds3Particle_Radiate_t3__pCopy(dds3Particle_Radiate_t3 *this, u8 **bytedata, s32 *bpos);
void dds3Particle_SmokeAllBuffInit(void **hData);
void dds3Particle_SmokeBuffInit(dds3Particle_Smoke_t3 **pSmoke, s32 number);
void dds3Particle_SmokeOffsetAllBuffInit(void **hData);
void dds3Particle_SmokeOffsetBuffInit(dds3Particle_SmokeOffset_t3 **pSmokeOffset, s32 number);
void dds3Particle_SmokeOffset_t3__pCopy(dds3Particle_SmokeOffset_t3 *this, u8 **bytedata, s32 *bpos);
void dds3Particle_Smoke_t3__pCopy(dds3Particle_Smoke_t3 *this, u8 **bytedata, s32 *bpos);
void dds3Particle_Spark2AllBuffInit(void **hData);
void dds3Particle_Spark2BuffInit(dds3Particle_Spark2_t3 **pSpark2, s32 number);
void dds3Particle_Spark2_t3__pCopy(dds3Particle_Spark2_t3 *this, u8 **bytedata, s32 *bpos);
void dds3Particle_SparkAllBuffInit(void **hData);
void dds3Particle_SparkBuffInit(dds3Particle_Spark_t3 **pSpark, s32 number);
void dds3Particle_SparkOffsetAllBuffInit(void **hData);
void dds3Particle_SparkOffsetBuffInit(dds3Particle_SparkOffset_t3 **pSparkOffset, s32 number);
void dds3Particle_SparkOffset_t3__pCopy(dds3Particle_SparkOffset_t3 *this, u8 **bytedata, s32 *bpos);
void dds3Particle_Spark_t3__pCopy(dds3Particle_Spark_t3 *this, u8 **bytedata, s32 *bpos);
void dds3Particle_SphereAtomAllBuffInit(void **hData);
void dds3Particle_SphereAtomBuffInit(dds3Particle_SphereAtom_t3 **pSphereAtom, s32 number);
void dds3Particle_SphereAtom_t3__pCopy(dds3Particle_SphereAtom_t3 *this, u8 **bytedata, s32 *bpos);
void dds3Particle_SphereRingAllBuffInit(void **hData);
void dds3Particle_SphereRingBuffInit(dds3Particle_SphereRing_t3 **pSphereRing, s32 number);
void dds3Particle_SphereRing_t3__pCopy(dds3Particle_SphereRing_t3 *this, u8 **bytedata, s32 *bpos);
void dds3Particle_SphereSmokeAllBuffInit(void **hData);
void dds3Particle_SphereSmokeBuffInit(dds3Particle_SphereSmoke_t3 **pSphereSmoke, s32 number);
void dds3Particle_SphereSmoke_t3__pCopy(dds3Particle_SphereSmoke_t3 *this, u8 **bytedata, s32 *bpos);
void dds3Particle_SphereSpiral2AllBuffInit(void **hData);
void dds3Particle_SphereSpiral2BuffInit(dds3Particle_SphereSpiral2_t3 **pSphereSpiral2, s32 number);
void dds3Particle_SphereSpiral2_t3__pCopy(dds3Particle_SphereSpiral2_t3 *this, u8 **bytedata, s32 *bpos);
void dds3Particle_SphereSpiralAllBuffInit(void **hData);
void dds3Particle_SphereSpiralBuffInit(dds3Particle_SphereSpiral_t3 **pSphereSpiral, s32 number);
void dds3Particle_SphereSpiral_t3__pCopy(dds3Particle_SphereSpiral_t3 *this, u8 **bytedata, s32 *bpos);
void dds3Particle_SpiralAllBuffInit(void **hData);
void dds3Particle_SpiralBuffInit(dds3Particle_Spiral_t3 **pSpiral, s32 number);
void dds3Particle_Spiral_t3__pCopy(dds3Particle_Spiral_t3 *this, u8 **bytedata, s32 *bpos);
void dds3Particle_Track2Set(dds3TrackPoly_t **hTrackPoly, s32 i, u32 abgr);
void dds3Particle_Track2SetExp(dds3TrackPoly_t **hTrackPoly, s32 index, sdfVector4_t pPos, u32 abgr, dds3ParOffsetBuff_t *pOffBuff);
void dds3Particle_Track3Set(effMTPolyListHandle_t **hTrackPoly, s32 i, u32 abgr);
void dds3Particle_TrackSet(dds3TrackPoly_t **hTrackPoly, s32 i, u32 abgr);
void dds3Particle_TrackSetExp(dds3TrackPoly_t **hTrackPoly, s32 index, sdfVector4_t pPos, u32 abgr, dds3ParOffsetBuff_t *pOffBuff);
void dds3TrackPolyColorSet(dds3TrackPoly_t **hTrackPoly, s32 number, u32 color);
dds3TrackPoly_t *dds3TrackPolyCreate(s32 number, s32 face, s32 rec, s32 type);
void dds3TrackPolyDelete(dds3TrackPoly_t **hTrackPoly);
void dds3TrackPolyDraw(dds3TrackPoly_t **hTrackPoly, char *funcname);
void dds3TrackPolyDrawOff(dds3TrackPoly_t **hTrackPoly);
void dds3TrackPolyListInit(dds3TrackPoly_t **hTrackPoly, s32 number);
void dds3TrackPolySet(dds3TrackPoly_t **hTrackPoly, s32 number, sdfVector4_t **pV);
void dds3TrackPolySet2(dds3TrackPoly_t **hTrackPoly, s32 number, sdfVector4_t **pV);
void dds3TrackPolySetMode(dds3TrackPoly_t **hTrackPoly, u16 mode);
void dds3TrackPolyVCRefresh_ParType1(dds3TrackPoly_t **hTrackPoly, u32 index);
void dds3TrackPolyVCRefresh_ParType2(dds3TrackPoly_t **hTrackPoly, u32 index);
void dds3TrackPolyVCSet(dds3TrackPoly_t **hTrackPoly, s32 type, u32 abgr_in, u32 abgr_out);
bool effBTLSkillCheckRun2(u32 skillid);
void pMeshDelete(dds3HermitianTrackPoly_tag **hPoly);
f32 sdfCos(f32 aRadius);
u32 sdfGetRand(sdfRandCB_t **aCB);
f32 sdfGetRandFloat(sdfRandCB_t **aCB);
void sdfRandomizeByTime(sdfRandCB_t **aCB);
f32 sdfSin(f32 aRadius);

// 0x1133b90
void SetExpTextureUnity(billHandle_t **hBillboard, u8 **bytedata, s32 oPos) {
  s32 TmxIndex;
  s32 v9;
  s64 *Texture;
  billHandle_t_o *v13;
  u32 TextureMax;
  u32 *v16;
  u64 v17;
  s64 *v20;
  s64 *v21;
  struct dds3Billboard_P2A_tag3_o *pP2A;
  billHandle_t_o *v25;
  s32 v26;
  struct UnityEngine_Texture_array *v28;
  struct dds3Billboard_Normal_tag3_o *pNormal;
  s32 bPos;

  bPos = oPos;
  TmxIndex = GetTmxIndex(bytedata, oPos);
  if ((TmxIndex & 0x80000000) == 0)
  {
    v9 = TmxIndex;
    Texture = billGetTexture(v9);
    if (op_Inequality(Texture, 0, 0))
    {
      v13 = *hBillboard;
      if ((*hBillboard)->texture)
      {
        if (v13->type == 1)
      }
      else
      {
        v13->texture = NewSpecific(UnityEngine_Texture, 1u);
        v13 = *hBillboard;
        if ((*hBillboard)->type == 1)
        {
          v13->pP2A->basic->texture = v13->texture;
          TextureMax = billGetTextureMax();
          v16 = NewSpecific(UnityEngine_Texture, TextureMax);
          v17 = 0;
          {
          }
          while (v17 < billGetTextureMax())
          {
            v20 = billGetTexture(v9);
            v21 = v20;
            *&v16[2 * v17++ + 8] = v21;
          }
          pP2A = (*hBillboard)->pP2A;
          pP2A->hResource = dds3BillAnimLoadP2A(&bytedata->obj, &bPos, v16);
          v25 = *hBillboard;
          v26 = v9 + 128;
        }
      }
      v13->texture = NewSpecific(UnityEngine_Texture, 1u);
      v28 = (*hBillboard)->texture;
      v28->m_Items[0] = Texture;
      (*hBillboard)->pNormal->basic->texture = (*hBillboard)->texture;
      pNormal = (*hBillboard)->pNormal;
      pNormal->hResource = BillboardLoadTex(Texture);
      v25 = *hBillboard;
      v26 = v9 + 144;
      v25->use_tmx_idx = v26;
    }
  }
}

// 0x1120d60
u32 dds3ParticleColorAnim(dds3ParticleColorAnim_t *pColAnim, u32 color_now, s32 frame) {
  s32 frame_end;
  u32 v5;
  bool v6;
  s32 v7;
  f32 v9;
  s32 frame_h;
  struct System_Single_array *v11;
  f32 v12;
  struct System_Single_array *v13;
  struct System_Single_array *v14;
  f32 v15;
  f32 v16;
  struct System_UInt32_array *v18;
  s32 v19;
  s32 v20;
  s32 v21;
  u32 v23;
  struct System_UInt32_array *v24;
  s32 v26;
  struct System_Single_array *r_add;
  f32 v29;
  f32 v30;
  struct System_Single_array *g_add;
  struct System_Single_array *b_add;
  f32 v34;
  f32 v35;
  struct System_UInt32_array *color;

  frame_end = pColAnim->frame_end;
  if (frame_end - pColAnim->alpha_e <= frame)
  {
    v6 = __OFSUB__(frame_end, frame);
    v7 = frame_end - frame;
    if (v7 < 0 != v6)
      return 0;
    v5 = (pColAnim->alpha_e_sub * v7) & 0xFF000000;
    if (pColAnim->type == 1)
  }
  if (pColAnim->alpha_s < frame)
  {
    v5 = pColAnim->alpha << 24;
    if (pColAnim->type == 1)
    v9 = frame;
    frame_h = pColAnim->frame_h;
    if (frame_h <= frame)
    {
      r_add = pColAnim->r_add;
      v29 = v9 - frame_h;
      v30 = r_add->m_Items[1];
      g_add = pColAnim->g_add;
      b_add = pColAnim->b_add;
      v34 = v29 * v30;
      v35 = v29 * g_add->m_Items[1];
      color = pColAnim->color;
      v19 = v34;
      v20 = v35;
      v21 = (v29 * b_add->m_Items[1]);
      v23 = color->m_Items[1];
    }
    else
    {
      v11 = pColAnim->r_add;
      v12 = v11->m_Items[0];
      v13 = pColAnim->g_add;
      v14 = pColAnim->b_add;
      v15 = v12 * v9;
      v16 = v13->m_Items[0] * v9;
      v18 = pColAnim->color;
      v19 = v15;
      v20 = v16;
      v21 = (v14->m_Items[0] * v9);
      v23 = v18->m_Items[0];
    }
    v26 = (v19 + (v20 << 8) + (v21 << 16) + v23) & 0xFFFFFF;
    return v26 | v5;
  }
  v5 = (pColAnim->alpha_s_add * frame) & 0xFF000000;
  if (pColAnim->type != 1)
  v24 = pColAnim->color;
  v26 = v24->m_Items[0];
  return v26 | v5;
}

// 0x1120fc0
u32 dds3ParticleColorBlend(u32 color0, u32 color1) {
  SDF_VU0__dds3ColorItoF(color0);
  SDF_VU0__COPYVECTOR_A_TO_B();
  SDF_VU0__dds3ColorItoF(color1);
  SDF_VU0__MULVECTOR();
  return SDF_VU0__dds3ColorFtoI(128.0);
}

// 0x11329f0
dds3Particle_Basic_t *dds3ParticleCopy(void **hData, s32 bPos) {
    return 0;
}

// 0x1131b70
dds3Particle_Basic_t *dds3ParticleCreate(u16 type, void *pData, s32 bPos) {
    return 0;
}

// 0x1131ce0
void dds3ParticleDelete(void **hData) {
    pMeshDelete(0);
}

// 0x1132100
void dds3ParticleDraw(void **hData) {
    GetMesh(0, 0, 0);
    SetAutoHide(0, 0);
    dds3BillboardSetScale(0, 0, 0);
    dds3Particle_EffectDrawNum(0);
    SetUseIndexMax(0, 0);
    ClearUseIndex(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    dds3BillboardDraw(0);
    dds3Particle_EffectDraw(0);
}

// 0x1131fb0
void dds3ParticleDrawOff(void **hData) {
    SetActive(0, 0);
}

// 0x1133ee0
dds3Particle_Basic_t *dds3ParticleExpCopy(void **hData, s32 bPos) {
    dds3BillboardCopy(0);
    dds3BillboardSetScale(0, 0, 0);
    dds3BillboardSetMode(0, 0);
    dds3BillboardSetAnimColorAdvMode(0);
    return 0;
}

// 0x1133710
dds3Particle_Basic_t *dds3ParticleExpCreate(u16 type, void *pData, s32 bPos) {
    dds3Particle_Exp_t__pCopy(0, 0, 0);
    dds3BillboardCreate(0, 0, 0, 0);
    SetExpTextureUnity(0, 0, 0);
    dds3BillboardSetScale(0, 0, 0);
    dds3BillboardSetMode(0, 0);
    dds3BillboardSetAnimColorAdvMode(0);
    billAlfRaitoGet();
    billBriRaitoGet();
    billAlfRaitoSet(0);
    billBriRaitoSet(0);
    return 0;
}

// 0x11341c0
void dds3ParticleExpDelete(void **hData) {
    pMeshDelete(0);
}

// 0x11344a0
void dds3ParticleExpDraw(void **hData) {
    GetMesh(0, 0, 0);
    SetAutoHide(0, 0);
    dds3Particle_EffectDrawNum(0);
    SetUseIndexMax(0, 0);
    ClearUseIndex(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    dds3BillboardSetAnimKey(0, 0);
    dds3BillboardDraw(0);
    dds3Particle_EffectDraw(0);
}

// 0x1134320
void dds3ParticleExpDrawOff(void **hData) {
    dds3ParticleDrawOff(0);
}

// 0x1135740
u8 dds3ParticleExpGetLoop(void **hData) {
    dds3ParticleGetLoop(0);
    return 0;
}

// 0x1135360
u16 dds3ParticleExpGetState(void **hData) {
    dds3ParticleGetState(0);
    return 0;
}

// 0x11343a0
XRD773Unity_CommonMesh **dds3ParticleExpGetUseMesh(void **hData) {
    return 0;
}

// 0x11351a0
void dds3ParticleExpReset(void **hData) {
    dds3ParticleReset(0);
}

// 0x11356c0
void dds3ParticleExpSetLoop(void **hData, u8 loop) {
  dds3ParticleSetLoop(hData, loop);
}

// 0x11353e0
void dds3ParticleExpSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x11355d0
void dds3ParticleExpSetRGBA(void **hData, u32 abgr) {
}

// 0x1135510
void dds3ParticleExpSetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
  s64 v5;
  s64 v6;
  s64 v7;
  s64 v8;
  s64 v9;
  s64 v10;
  UnityEngine_Matrix4x4_o v11;
  UnityEngine_Matrix4x4_o v12;

  v5 = *&pMatrix->m00;
  v6 = *&pMatrix->m20;
  v7 = *&pMatrix->m21;
  *&v12.m01 = *&pMatrix->m01;
  *&v12.m21 = v7;
  *&v12.m00 = v5;
  *&v12.m20 = v6;
  v8 = *&pMatrix->m23;
  v9 = *&pMatrix->m02;
  v10 = *&pMatrix->m22;
  *&v12.m03 = *&pMatrix->m03;
  *&v12.m23 = v8;
  *&v12.m02 = v9;
  *&v12.m22 = v10;
  v11 = v12;
  dds3ParticleSetRotateMatrix(hData, &v11);
}

// 0x1135220
void dds3ParticleExpSetScale(void **hData, f32 scale) {
    dds3ParticleSetScale(0, 0);
}

// 0x1133570
u8 dds3ParticleGetLoop(void **hData) {
    return 0;
}

// 0x1132f40
u16 dds3ParticleGetState(void **hData) {
    return 0;
}

// 0x111e770
void dds3ParticleManagerExit(void) {
  ;
}

// 0x111e6e0
void dds3ParticleManagerInit(void) {
  sdfRandomizeByTime(&ParRand);
}

// 0x1132bf0
void dds3ParticleReset(void **hData) {
}

// 0x111f160
void dds3ParticleSetColorTable(dds3ParticleColorAnim_t **pColAnim, s32 frame) {
  struct System_UInt32_array *color;
  s32 v4;
  struct System_UInt32_array *v6;
  struct System_UInt32_array *v8;
  dds3ParticleColorAnim_t_o *v10;
  s32 alpha_s;
  dds3ParticleColorAnim_t_o *v12;
  s32 alpha_e;
  u32 type;
  s32 frame_h;
  f32 v16;
  struct System_UInt32_array *v17;
  bool v18;
  u32 max_length;
  f32 v20;
  u32 v21;
  u32 v23;
  struct System_Single_array *r_add;
  f32 v25;
  f32 v26;
  f32 v27;
  f32 v29;
  f32 v30;
  struct System_Single_array *g_add;
  f32 v32;
  f32 v34;
  f32 v35;
  f32 v36;
  struct System_Single_array *b_add;
  dds3ParticleColorAnim_t_o *v39;
  struct System_UInt32_array *v40;
  u32 v41;
  u32 v43;
  u32 v45;
  struct System_Single_array *v46;
  f32 v47;
  f32 v48;
  f32 v49;
  f32 v51;
  f32 v52;
  struct System_Single_array *v53;
  f32 v54;
  f32 v56;
  f32 v57;
  f32 v58;
  struct System_Single_array *v59;

  color = (*pColAnim)->color;
  v4 = frame;
  color->m_Items[0] &= 0xFFFFFFu;
  v6 = (*pColAnim)->color;
  v6->m_Items[1] &= 0xFFFFFFu;
  v8 = (*pColAnim)->color;
  v8->m_Items[2] &= 0xFFFFFFu;
  (*pColAnim)->alpha_s_add = (*pColAnim)->alpha << 24;
  v10 = *pColAnim;
  alpha_s = (*pColAnim)->alpha_s;
  if (alpha_s >= 1)
  {
    v10->alpha_s_add /= alpha_s;
    v10 = *pColAnim;
  }
  v10->alpha_e_sub = v10->alpha << 24;
  v12 = *pColAnim;
  alpha_e = (*pColAnim)->alpha_e;
  if (alpha_e >= 1)
  {
    v12->alpha_e_sub /= alpha_e;
    v12 = *pColAnim;
  }
  v12->frame_end = frame;
  type = (*pColAnim)->type;
  if (type != 1)
  {
    if (type != 2)
      v4 = frame >> 1;
    (*pColAnim)->frame_h = v4;
    frame_h = (*pColAnim)->frame_h;
    v16 = frame_h;
    v17 = (*pColAnim)->color;
    v18 = frame_h == 0;
    max_length = v17->max_length;
    if (v18)
      v20 = 1.0;
    else
      v20 = v16;
    v21 = v17->m_Items[0];
    v23 = (*pColAnim)->color->m_Items[1];
    r_add = (*pColAnim)->r_add;
    v25 = v23;
    v26 = v21;
    v27 = (v25 - v26) / v20;
    v29 = BYTE1(v23);
    v30 = BYTE1(v21);
    r_add->m_Items[0] = v27;
    g_add = (*pColAnim)->g_add;
    v32 = (v29 - v30) / v20;
    v34 = BYTE2(v23);
    v35 = BYTE2(v21);
    v36 = v34 - v35;
    g_add->m_Items[0] = v32;
    b_add = (*pColAnim)->b_add;
    b_add->m_Items[0] = v36 / v20;
    v39 = *pColAnim;
    if ((*pColAnim)->type != 2)
    {
      v40 = v39->color;
      v41 = v40->max_length;
      v43 = v40->m_Items[1];
      v45 = v39->color->m_Items[2];
      v46 = v39->r_add;
      v47 = v45;
      v48 = v43;
      v49 = (v47 - v48) / v20;
      v51 = BYTE1(v45);
      v52 = BYTE1(v43);
      v46->m_Items[1] = v49;
      v53 = (*pColAnim)->g_add;
      v54 = (v51 - v52) / v20;
      v56 = BYTE2(v45);
      v57 = BYTE2(v43);
      v58 = (v56 - v57) / v20;
      v53->m_Items[1] = v54;
      v59 = (*pColAnim)->b_add;
      v59->m_Items[1] = v58;
    }
  }
}

// 0x11333e0
void dds3ParticleSetLoop(void **hData, u8 loop) {
}

// 0x1133030
void dds3ParticleSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x11332f0
void dds3ParticleSetRGBA(void **hData, u32 abgr) {
}

// 0x1133160
void dds3ParticleSetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__LOADMATRIX_B(0);
    MultMatrixNoArg();
    SDF_VU0__STOREMATRIX(0);
}

// 0x1132d60
void dds3ParticleSetScale(void **hData, f32 scale) {
    dds3ParticleReset(0);
}

// 0x111ea10
void dds3Particle_BasicCreate(dds3Particle_Basic_t **pParBasic, bool pCopy) {
    billCutRaitoGet();
    billCutRaitoGet2();
    billCutRaitoSet(0);
    billScaleRaitoGet(0, 0);
    billScaleRaitoSet(0, 0);
    dds3Particle_PhysicsCreate(0);
    billAlfRaitoGet();
    billBriRaitoGet();
    billAlfRaitoSet(0);
    billBriRaitoSet(0);
    dds3BillboardGeneral(0);
    dds3BillboardSetScale(0, 0, 0);
    dds3BillboardSetMode(0, 0);
    dds3ParticleSetColorTable(0, 0);
    dds3Particle_BlurCreate(0, 0, 0);
    dds3TrackPolyCreate(0, 0, 0, 0);
    dds3TrackPolyVCSet(0, 0, 0, 0);
    dds3TrackPolySetMode(0, 0);
    Eff_ModelTrackPolyListCreate(0, 0);
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__STOREMATRIX(0);
}

// 0x111f720
void dds3Particle_BasicDelete(dds3Particle_Basic_t *pParBasic) {
  struct dds3Particle_Effect_t_o *effect;
  char *track;
  dds3TrackPoly_t_o **v5;
  effMTPolyListHandle_t_o **p_hTrackPoly;
  Il2CppObject *hData;

  hData = 0;
  effect = pParBasic->effect;
  switch (effect->type)
  {
    case 1u:
      break;
    case 2u:
      track = effect->param->track;
    case 3u:
      track = effect->param->track2;
      v5 = (track + 32);
      dds3TrackPolyDelete(v5);
      break;
    case 4u:
      p_hTrackPoly = &effect->param->track3->hTrackPoly;
      Eff_ModelTrackPolyListDelete(p_hTrackPoly);
      break;
    default:
      break;
  }
  hData = pParBasic->hBillboard;
  dds3BillboardDelete(&hData);
}

// 0x111f520
dds3Particle_BlurBuff_t *dds3Particle_BlurCreate(u32 number, u16 length, billHandle_t *pBill_Handle) {
  dds3Particle_BlurBuff_t_o *v7;
  struct dds3Particle_BlurBuffList_t_array *v8;
  s64 v9;
  s64 v10;
  u32 *v11;
  u64 v12;
  u64 *v13;
  struct dds3Particle_BlurBuffList_t_array *blurList;
  s64 v17;
  struct dds3Particle_BlurBuffList_t_array *v18;
  struct dds3Particle_BlurBuffList_t_array *v20;

  v7 = Allocate(dds3Particle_BlurBuff_t);
  dds3Particle_BlurBuff_t___ctor(v7);
  v8 = NewSpecific(dds3Particle_BlurBuffList_t, number);
  v7->number = number;
  v7->point = length;
  v7->hMem = 0;
  v7->blurList = v8;
  v7->pBill_Handle = pBill_Handle;
  if (number)
  {
    v9 = 1LL - number;
    v10 = 4;
    v11 = v8;
    while (1)
    {
      v12 = v10 - 4;
      v13 = Allocate(dds3Particle_BlurBuffList_t);
      dds3Particle_BlurBuffList_t___ctor(v13);
      *&v11[2 * v10] = v13;
      blurList = v7->blurList;
      v17 = *(&blurList->obj.klass + v10);
      *(v17 + 16) = NewSpecific(UnityEngine_Vector4, length);
      v18 = v7->blurList;
      *(*(&v18->obj.klass + v10) + 24LL) = 0;
      v20 = v7->blurList;
      *(*(&v20->obj.klass + v10) + 28LL) = 0;
      if (v9 + v10 == 4)
        break;
      v11 = v7->blurList;
      ++v10;
    }
  }
  return v7;
}

// 0x111f8a0
void dds3Particle_BlurDelete(dds3Particle_BlurBuff_t *hBlur) {
  ;
}

// 0x1131770
void dds3Particle_BlurDraw(dds3Particle_BlurBuff_t **hBlur) {
  u64 i;
  struct dds3Particle_BlurBuffList_t_array *blurList;
  dds3Particle_BlurBuffList_t_o *v6;
  f32 scale;
  s64 count;
  u32 abgr;
  u32 v10;
  s32 v11;
  u32 v12;
  u64 v13;
  s64 v14;
  struct UnityEngine_Vector4_array *pPos;
  s64 number;
  Il2CppObject *hData;
  billHandle_t_o *hBillboard;

  number = (*hBlur)->number;
  hBillboard = (*hBlur)->pBill_Handle;
  hData = hBillboard;
  dds3BillboardDrawOff(&hData);
  if (number)
  {
    for (i = 0; i != number; ++i)
    {
      blurList = (*hBlur)->blurList;
      v6 = blurList->m_Items[i];
      scale = v6->scale;
      count = v6->count;
      abgr = v6->abgr;
      dds3BillboardSetScale(&hBillboard, scale, scale);
      if (count)
      {
        v10 = abgr & 0xFF000000;
        v11 = abgr & 0xFFFFFF;
        v12 = (abgr & 0xFF000000) / (count + 1);
        v13 = 0;
        v14 = 32;
        do
        {
          pPos = v6->pPos;
          if (hBillboard)
          {
            SDF_VU0__COPYVECTOR(&hBillboard->pos, *(&pPos->obj + v14), 0);
            v10 -= v12;
            hBillboard->abgr = v10 & 0xFF000000 | v11;
            dds3BillboardDraw(&hData);
          }
          ++v13;
          v14 += 16;
        }
        while (count != v13);
      }
    }
  }
}

// 0x1131a60
s32 dds3Particle_BlurDrawNum(dds3Particle_BlurBuff_t **hBlur) {
  u64 v2;
  s32 v3;
  struct dds3Particle_BlurBuffList_t_array *blurList;

  if (!(*hBlur)->number)
    return 0;
  v2 = 0;
  v3 = 0;
  blurList = (*hBlur)->blurList;
  while (1)
  {
    v3 += blurList->m_Items[v2]->count;
    if ((*hBlur)->number - 1LL == v2)
      return v3;
    ++v2;
    blurList = (*hBlur)->blurList;
    if (v2 >= LODWORD(blurList->max_length))
  }
}

// 0x1131610
void dds3Particle_BlurDrawOff(dds3Particle_BlurBuff_t **hBlur) {
  ;
}

// 0x1131b10
void dds3Particle_BlurReset(dds3Particle_BlurBuff_t **hBlur, s32 number) {
  struct dds3Particle_BlurBuffList_t_array *blurList;

  blurList = (*hBlur)->blurList;
  blurList->m_Items[number]->count = 0;
}

// 0x1130dc0
void dds3Particle_BlurSet(dds3Particle_BlurBuff_t **hBlur, s32 index, u32 abgr, f32 scale) {
  struct dds3Particle_BlurBuffList_t_array *blurList;
  u32 max_length;
  s64 v8;
  dds3Particle_BlurBuffList_t_o *v10;
  u32 v11;
  s64 v12;
  struct UnityEngine_Vector4_array *pPos;
  u32 v14;
  f32 v16;
  f32 v17;
  struct UnityEngine_Vector4_array *v19;
  f32 y;
  f32 z;
  f32 w;
  f32 *v24;
  u32 count;
  struct UnityEngine_Vector4_array *v26;
  f32 v27;
  f32 v28;
  f32 v29;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o p;
  s64 point;
  UnityEngine_Vector4_o v35;

  *&p.x = 0;
  *&p.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  blurList = (*hBlur)->blurList;
  max_length = blurList->max_length;
  v8 = (*hBlur)->point - 1;
  point = (*hBlur)->point;
  v10 = blurList->m_Items[index];
  if (v8 >= 1)
  {
    v11 = point - 2;
    v12 = 16 * (point - 2) + 32;
    do
    {
      pPos = v10->pPos;
      v14 = pPos->max_length;
      v17 = *(&pPos->max_length + v12);
      v16 = *(&pPos->max_length + v12 + 4);
      *&dst.x = *(&pPos->bounds + v12);
      dst.z = v17;
      dst.w = v16;
      v35.y = *(&pPos->obj.klass + v12 + 4);
      v35.z = *(&pPos->obj.monitor + v12);
      v35.w = *(&pPos->obj.monitor + v12 + 4);
      p.x = *(&pPos->obj.klass + v12);
      v35.x = p.x;
      p.y = v35.y;
      p.z = v35.z;
      p.w = v35.w;
      SDF_VU0__COPYVECTOR(&dst, v35);
      v19 = v10->pPos;
      y = dst.y;
      z = dst.z;
      w = dst.w;
      v24 = (v19 + v12);
      v12 -= 16;
      --v11;
      --v8;
      v24[4] = dst.x;
      v24[5] = y;
      v24[6] = z;
      v24[7] = w;
    }
    while (v8);
  }
  count = v10->count;
  if (point > count)
    v10->count = count + 1;
  SDF_VU0__STOREVECTOR_C(&p);
  v26 = v10->pPos;
  v27 = p.y;
  v29 = p.z;
  v28 = p.w;
  v26->m_Items[0].x = p.x;
  v26->m_Items[0].y = v27;
  v26->m_Items[0].z = v29;
  v26->m_Items[0].w = v28;
  v10->abgr = abgr;
  v10->scale = scale;
}

// 0x1130040
void dds3Particle_BlurSetExp(dds3Particle_BlurBuff_t **hBlur, s32 index, sdfVector4_t pPosBase, u32 abgr, dds3ParOffsetBuff_t *pOffBuff, f32 scale) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1131620
void dds3Particle_EffectDraw(dds3Particle_Effect_t **pEffect) {
    dds3Particle_BlurDraw(0);
    dds3TrackPolyDraw(0, 0);
    Eff_ModelTrackPolyListDrawOnly(0);
}

// 0x1131950
s32 dds3Particle_EffectDrawNum(dds3Particle_Effect_t **pEffect) {
  struct dds3Particle_Blur_t_o *blur;
  struct dds3Particle_BlurBuff_t_o *hBlur;
  s64 number;
  u64 v6;
  s32 v7;
  struct dds3Particle_BlurBuffList_t_array *blurList;

  if ((*pEffect)->type != 1)
    return 0;
  blur = (*pEffect)->param->blur;
  hBlur = blur->hBlur;
  number = hBlur->number;
  if (!hBlur->number)
    return 0;
  v6 = 0;
  v7 = 0;
  blurList = hBlur->blurList;
  while (1)
  {
    v7 += blurList->m_Items[v6]->count;
    if (number - 1 == v6)
      return v7;
    ++v6;
    blurList = blur->hBlur->blurList;
    if (v6 >= LODWORD(blurList->max_length))
  }
}

// 0x11314f0
void dds3Particle_EffectDrawOff(dds3Particle_Effect_t **pEffect) {
  dds3Particle_Effect_t_o *v3;
  char *track;
  dds3TrackPoly_t_o **v5;
  effMTPolyListHandle_t_o *hTrackPoly;

  v3 = *pEffect;
  switch ((*pEffect)->type)
  {
    case 1u:
      break;
    case 2u:
      track = v3->param->track;
    case 3u:
      track = v3->param->track2;
      v5 = (track + 32);
      dds3TrackPolyDrawOff(v5);
      break;
    case 4u:
      hTrackPoly = v3->param->track3->hTrackPoly;
      Eff_ModelTrackPolyListDrawOnlyOff(hTrackPoly);
      break;
    default:
      return;
  }
}

// 0x1120b70
void dds3Particle_EffectInit(dds3Particle_Effect_t *pEffect, f32 scale_raito) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__STOREVECTOR(0);
}

// 0x1120380
void dds3Particle_EffectReset(dds3Particle_Effect_t **pEffect, s32 number) {
  dds3Particle_Effect_t_o *v5;
  struct dds3Particle_Blur_t_o *blur;
  struct dds3Particle_BlurBuffList_t_array *blurList;
  char *track;
  dds3TrackPoly_t_o **v10;
  effMTPolyListHandle_t_o **p_hTrackPoly;

  v5 = *pEffect;
  switch ((*pEffect)->type)
  {
    case 1u:
      blur = v5->param->blur;
      blurList = blur->hBlur->blurList;
      blurList->m_Items[number]->count = 0;
      break;
    case 2u:
      track = v5->param->track;
    case 3u:
      track = v5->param->track2;
      v10 = (track + 32);
      dds3TrackPolyListInit(v10, number);
      break;
    case 4u:
      p_hTrackPoly = &v5->param->track3->hTrackPoly;
      Eff_ModelTrackPolyListReset(p_hTrackPoly, number);
      break;
    default:
      return;
  }
}

// 0x1121010
void dds3Particle_EffectSet(dds3Particle_Effect_t **pEffect, s32 index, u32 abgr, f32 scale) {
  dds3Particle_Effect_t_o *v9;
  dds3Particle_BlurBuff_t_o **p_hBlur;
  dds3TrackPoly_t_o **p_hTrackPoly;
  dds3TrackPoly_t_o **v12;
  effMTPolyListHandle_t_o **v13;

  v9 = *pEffect;
  switch ((*pEffect)->type)
  {
    case 1u:
      p_hBlur = &v9->param->blur->hBlur;
      dds3Particle_BlurSet(p_hBlur, index, abgr, scale);
      break;
    case 2u:
      p_hTrackPoly = &v9->param->track->hTrackPoly;
      dds3Particle_TrackSet(p_hTrackPoly, index, abgr);
      break;
    case 3u:
      v12 = &v9->param->track2->hTrackPoly;
      dds3Particle_Track2Set(v12, index, abgr);
      break;
    case 4u:
      v13 = &v9->param->track3->hTrackPoly;
      dds3Particle_Track3Set(v13, index, abgr);
      break;
    default:
      return;
  }
}

// 0x112ad60
void dds3Particle_NopAllBuffInit(void **hData) {
    dds3Particle_NopBuffInit(0);
}

// 0x112ae80
void dds3Particle_NopBuffInit(dds3Particle_Nop_t3 **pNop) {
    DDS3EFFECT_RAND_FA(0);
}

// 0x112b260
dds3Particle_Basic_t *dds3Particle_NopCreate(void *hData, s32 bPos, bool pCopy, s32 billno) {
    dds3Particle_Basic_t__dCopy(0, 0);
    dds3Particle_Nop_t3__pCopy(0, 0, 0);
    dds3Particle_BasicCreate(0, 0);
    return 0;
}

// 0x112b4d0
void dds3Particle_NopDelete(void **hData) {
    dds3Particle_BasicDelete(0);
}

// 0x112b5e0
void dds3Particle_NopDraw(void **hData) {
    dds3Particle_NopBuffInit(0);
    SDF_VU0__dds3ColorItoF(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__MULVECTOR();
    SDF_VU0__dds3ColorFtoI(0);
}

// 0x112b0d0
void dds3Particle_NopSetScale(void **hData, f32 scale) {
}

// 0x111e780
dds3Particle_Physics_t *dds3Particle_PhysicsCreate(s32 number) {
  dds3Particle_Physics_t_o *v3;
  struct parPhysics_t_array *v4;
  u32 *v5;
  s64 v6;
  s64 i;
  u64 v8;
  u64 *v9;
  struct parPhysics_t_array *pPhysics;
  struct parPhysics_t_array *v13;

  v3 = Allocate(dds3Particle_Physics_t);
  dds3Particle_Physics_t___ctor(v3);
  v4 = NewSpecific(parPhysics_t, number);
  v3->pPhysics = v4;
  if (number >= 1)
  {
    v5 = v4;
    v6 = 1LL - number;
    for (i = 4; ; ++i)
    {
      v8 = i - 4;
      v9 = Allocate(parPhysics_t);
      parPhysics_t___ctor(v9);
      *&v5[2 * i] = v9;
      pPhysics = v3->pPhysics;
      *(*(&pPhysics->obj.klass + i) + 48LL) = 0;
      v13 = v3->pPhysics;
      *(*(&v13->obj.klass + i) + 52LL) = 0;
      if (v6 + i == 4)
        break;
      v5 = v3->pPhysics;
    }
  }
  return v3;
}

// 0x111e910
void dds3Particle_PhysicsDelete(dds3Particle_Physics_t *hPhysics) {
  ;
}

// 0x111e920
parPhysics_t *dds3Particle_PhysicsGetBuff(dds3Particle_Physics_t *hPhysics, s32 index) {
  struct parPhysics_t_array *pPhysics;

  pPhysics = hPhysics->pPhysics;
  return pPhysics->m_Items[index];
}

// 0x111e970
void dds3Particle_PhysicsSetBuff(dds3Particle_Physics_t **hPhysics, s32 index, parPhysics_t *physics) {
  struct parPhysics_t_array *pPhysics;

  pPhysics = (*hPhysics)->pPhysics;
  pPhysics->m_Items[index] = physics;
}

// 0x11242a0
void dds3Particle_RadiateAllBuffInit(void **hData) {
    dds3Particle_RadiateBuffInit(0, 0);
}

// 0x1124470
void dds3Particle_RadiateBuffInit(dds3Particle_Radiate_t3 **pRadiate, s32 number) {
    LookAtMatrix((sdfVector4_t){0}, (sdfVector4_t){0}, (sdfVector4_t){0});
    ReverseMatrix();
    sdfCos(0);
    sdfSin(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX_XYZ();
    SDF_VU0__STOREVECTOR(0);
    DDS3EFFECT_RAND_FA(0);
    dds3Particle_EffectReset(0, 0);
}

// 0x1124a60
dds3Particle_Basic_t *dds3Particle_RadiateCreate(void *hData, s32 bPos, bool pCopy, s32 billno) {
    dds3Particle_Basic_t__dCopy(0, 0);
    dds3Particle_Radiate_t3__pCopy(0, 0, 0);
    dds3Particle_BasicCreate(0, 0);
    dds3Particle_RadiateAllBuffInit(0);
    return 0;
}

// 0x1124cb0
void dds3Particle_RadiateDelete(void **hData) {
    dds3Particle_BasicDelete(0);
}

// 0x1124dc0
void dds3Particle_RadiateDraw(void **hData) {
    dds3Particle_EffectInit(0, 0);
    LookAtMatrix((sdfVector4_t){0}, (sdfVector4_t){0}, (sdfVector4_t){0});
    ReverseMatrix();
    dds3ParticleColorAnim(0, 0, 0);
    SDF_VU0__dds3ColorItoF(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__MULVECTOR();
    SDF_VU0__dds3ColorFtoI(0);
    SDF_VU0__LOADVECTOR_C((sdfVector4_t){0});
    sdfCos(0);
    sdfSin(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX_XYZ();
    SDF_VU0__STOREVECTOR(0);
    dds3Particle_EffectSet(0, 0, 0, 0);
    dds3Particle_RadiateBuffInit(0, 0);
    dds3Particle_EffectReset(0, 0);
}

// 0x11248d0
void dds3Particle_RadiateSetScale(void **hData, f32 scale) {
}

// 0x11211d0
void dds3Particle_SmokeAllBuffInit(void **hData) {
}

// 0x1121870
void dds3Particle_SmokeBuffInit(dds3Particle_Smoke_t3 **pSmoke, s32 number) {
    DDS3EFFECT_RAND_PM();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__APPLYMATRIX();
    DDS3EFFECT_RAND_FA(0);
    sdfGetRand(0);
    dds3Particle_EffectReset(0, 0);
}

// 0x1121500
dds3Particle_Basic_t *dds3Particle_SmokeCreate(void *hData, s32 bPos, bool pCopy, s32 billno) {
    dds3Particle_Basic_t__dCopy(0, 0);
    dds3Particle_Smoke_t3__pCopy(0, 0, 0);
    dds3Particle_BasicCreate(0, 0);
    dds3Particle_SmokeAllBuffInit(0);
    return 0;
}

// 0x1121750
void dds3Particle_SmokeDelete(void **hData) {
    dds3Particle_BasicDelete(0);
}

// 0x1121d40
void dds3Particle_SmokeDraw(void **hData) {
    dds3Particle_EffectInit(0, 0);
    SDF_VU0__LOADMATRIX(0);
    dds3Particle_SmokeBuffInit(0, 0);
    dds3ParticleColorAnim(0, 0, 0);
    SDF_VU0__dds3ColorItoF(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__MULVECTOR();
    SDF_VU0__dds3ColorFtoI(0);
    SDF_VU0__LOADVECTOR_C((sdfVector4_t){0});
    sdfSin(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(0);
    dds3Particle_EffectSet(0, 0, 0, 0);
    dds3Particle_EffectReset(0, 0);
}

// 0x112d5d0
void dds3Particle_SmokeOffsetAllBuffInit(void **hData) {
}

// 0x112dc80
void dds3Particle_SmokeOffsetBuffInit(dds3Particle_SmokeOffset_t3 **pSmokeOffset, s32 number) {
    DDS3EFFECT_RAND_PM();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__APPLYMATRIX();
    DDS3EFFECT_RAND_FA(0);
    sdfGetRand(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    dds3Particle_EffectReset(0, 0);
}

// 0x112d900
dds3Particle_Basic_t *dds3Particle_SmokeOffsetCreate(void *hData, s32 bPos, bool pCopy, s32 billno) {
    dds3Particle_Basic_t__dCopy(0, 0);
    dds3Particle_SmokeOffset_t3__pCopy(0, 0, 0);
    dds3Particle_BasicCreate(0, 0);
    dds3Particle_SmokeOffsetAllBuffInit(0);
    return 0;
}

// 0x112db70
void dds3Particle_SmokeOffsetDelete(void **hData) {
    dds3Particle_BasicDelete(0);
}

// 0x112e120
void dds3Particle_SmokeOffsetDraw(void **hData) {
    dds3Particle_EffectInit(0, 0);
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    dds3Particle_SmokeOffsetBuffInit(0, 0);
    dds3ParticleColorAnim(0, 0, 0);
    SDF_VU0__dds3ColorItoF(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__MULVECTOR();
    SDF_VU0__dds3ColorFtoI(0);
    SDF_VU0__LOADVECTOR_C((sdfVector4_t){0});
    sdfSin(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    dds3Particle_EffectSet(0, 0, 0, 0);
    dds3Particle_EffectReset(0, 0);
}

// 0x112d760
void dds3Particle_SmokeOffsetSetScale(void **hData, f32 scale) {
}

// 0x1121360
void dds3Particle_SmokeSetScale(void **hData, f32 scale) {
}

// 0x11287c0
void dds3Particle_Spark2AllBuffInit(void **hData) {
}

// 0x1128e50
void dds3Particle_Spark2BuffInit(dds3Particle_Spark2_t3 **pSpark2, s32 number) {
    effBTLSkillCheckRun2(0);
    sdfCos(0);
    sdfSin(0);
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(0);
    sdfGetRand(0);
    DDS3EFFECT_RAND_FA(0);
    dds3Particle_EffectReset(0, 0);
}

// 0x1128af0
dds3Particle_Basic_t *dds3Particle_Spark2Create(void *hData, s32 bPos, bool pCopy, s32 billno) {
    dds3Particle_Basic_t__dCopy(0, 0);
    dds3Particle_Spark2_t3__pCopy(0, 0, 0);
    dds3Particle_BasicCreate(0, 0);
    dds3Particle_Spark2AllBuffInit(0);
    return 0;
}

// 0x1128d40
void dds3Particle_Spark2Delete(void **hData) {
    dds3Particle_BasicDelete(0);
}

// 0x1129390
void dds3Particle_Spark2Draw(void **hData) {
    dds3Particle_EffectInit(0, 0);
    SDF_VU0__LOADMATRIX(0);
    dds3Particle_Spark2BuffInit(0, 0);
    dds3ParticleColorAnim(0, 0, 0);
    SDF_VU0__dds3ColorItoF(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__MULVECTOR();
    SDF_VU0__dds3ColorFtoI(0);
    SDF_VU0__LOADVECTOR_C((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(0);
    dds3Particle_EffectSet(0, 0, 0, 0);
    dds3Particle_EffectReset(0, 0);
}

// 0x1128950
void dds3Particle_Spark2SetScale(void **hData, f32 scale) {
}

// 0x1122380
void dds3Particle_SparkAllBuffInit(void **hData) {
}

// 0x1122a10
void dds3Particle_SparkBuffInit(dds3Particle_Spark_t3 **pSpark, s32 number) {
    SDF_VU0__STOREIDENTITY(0);
    DDS3EFFECT_RAND_PM();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    DDS3EFFECT_RAND_FA(0);
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__APPLYMATRIX();
    sdfGetRandFloat(0);
    sdfCos(0);
    sdfSin(0);
    sdfGetRand(0);
    dds3Particle_EffectReset(0, 0);
}

// 0x11226b0
dds3Particle_Basic_t *dds3Particle_SparkCreate(void *hData, s32 bPos, bool pCopy, s32 billno) {
    dds3Particle_Basic_t__dCopy(0, 0);
    dds3Particle_Spark_t3__pCopy(0, 0, 0);
    dds3Particle_BasicCreate(0, 0);
    dds3Particle_SparkAllBuffInit(0);
    return 0;
}

// 0x1122900
void dds3Particle_SparkDelete(void **hData) {
    dds3Particle_BasicDelete(0);
}

// 0x1123ce0
void dds3Particle_SparkDraw(void **hData) {
    dds3Particle_EffectInit(0, 0);
    SDF_VU0__LOADMATRIX(0);
    dds3Particle_SparkBuffInit(0, 0);
    dds3ParticleColorAnim(0, 0, 0);
    SDF_VU0__dds3ColorItoF(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__MULVECTOR();
    SDF_VU0__dds3ColorFtoI(0);
    SDF_VU0__LOADVECTOR_C((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(0);
    dds3Particle_EffectSet(0, 0, 0, 0);
    dds3Particle_EffectReset(0, 0);
}

// 0x112b890
void dds3Particle_SparkOffsetAllBuffInit(void **hData) {
}

// 0x112bf20
void dds3Particle_SparkOffsetBuffInit(dds3Particle_SparkOffset_t3 **pSparkOffset, s32 number) {
    SDF_VU0__STOREIDENTITY(0);
    DDS3EFFECT_RAND_PM();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    DDS3EFFECT_RAND_FA(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__APPLYMATRIX();
    sdfGetRandFloat(0);
    sdfCos(0);
    sdfSin(0);
    sdfGetRand(0);
    dds3Particle_EffectReset(0, 0);
}

// 0x112bbc0
dds3Particle_Basic_t *dds3Particle_SparkOffsetCreate(void *hData, s32 bPos, bool pCopy, s32 billno) {
    dds3Particle_Basic_t__dCopy(0, 0);
    dds3Particle_SparkOffset_t3__pCopy(0, 0, 0);
    dds3Particle_BasicCreate(0, 0);
    dds3Particle_SparkOffsetAllBuffInit(0);
    return 0;
}

// 0x112be10
void dds3Particle_SparkOffsetDelete(void **hData) {
    dds3Particle_BasicDelete(0);
}

// 0x112d010
void dds3Particle_SparkOffsetDraw(void **hData) {
    dds3Particle_EffectInit(0, 0);
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    dds3Particle_SparkOffsetBuffInit(0, 0);
    dds3ParticleColorAnim(0, 0, 0);
    SDF_VU0__dds3ColorItoF(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__MULVECTOR();
    SDF_VU0__dds3ColorFtoI(0);
    SDF_VU0__LOADVECTOR_C((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    dds3Particle_EffectSet(0, 0, 0, 0);
    dds3Particle_EffectReset(0, 0);
}

// 0x112ba20
void dds3Particle_SparkOffsetSetScale(void **hData, f32 scale) {
}

// 0x1122510
void dds3Particle_SparkSetScale(void **hData, f32 scale) {
}

// 0x1129920
void dds3Particle_SphereAtomAllBuffInit(void **hData) {
}

// 0x1129fc0
void dds3Particle_SphereAtomBuffInit(dds3Particle_SphereAtom_t3 **pSphereAtom, s32 number) {
    DDS3EFFECT_RAND_PM();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    DDS3EFFECT_RAND_F();
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    sdfCos(0);
    sdfSin(0);
    sdfGetRand(0);
    DDS3EFFECT_RAND_FA(0);
    dds3Particle_EffectReset(0, 0);
}

// 0x1129c60
dds3Particle_Basic_t *dds3Particle_SphereAtomCreate(void *hData, s32 bPos, bool pCopy, s32 billno) {
    dds3Particle_Basic_t__dCopy(0, 0);
    dds3Particle_SphereAtom_t3__pCopy(0, 0, 0);
    dds3Particle_BasicCreate(0, 0);
    dds3Particle_SphereAtomAllBuffInit(0);
    return 0;
}

// 0x1129eb0
void dds3Particle_SphereAtomDelete(void **hData) {
    dds3Particle_BasicDelete(0);
}

// 0x112a540
void dds3Particle_SphereAtomDraw(void **hData) {
    dds3Particle_EffectInit(0, 0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    dds3Particle_SphereAtomBuffInit(0, 0);
    dds3ParticleColorAnim(0, 0, 0);
    SDF_VU0__dds3ColorItoF(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__MULVECTOR();
    SDF_VU0__dds3ColorFtoI(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__GETLENGTH();
    SDF_VU0__COPYVECTOR_C_TO_A();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__COPYVECTOR_C_TO_B();
    SDF_VU0__INNERPRODUCT();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__LOADVECTOR_C((sdfVector4_t){0});
    dds3Particle_EffectSet(0, 0, 0, 0);
    dds3Particle_EffectReset(0, 0);
}

// 0x1129ac0
void dds3Particle_SphereAtomSetScale(void **hData, f32 scale) {
}

// 0x11277d0
void dds3Particle_SphereRingAllBuffInit(void **hData) {
}

// 0x1127e70
void dds3Particle_SphereRingBuffInit(dds3Particle_SphereRing_t3 **pSphereRing, s32 number) {
    DDS3EFFECT_RAND_FA(0);
    sdfCos(0);
    sdfSin(0);
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX_XYZ();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(0);
    dds3Particle_EffectReset(0, 0);
}

// 0x1127b10
dds3Particle_Basic_t *dds3Particle_SphereRingCreate(void *hData, s32 bPos, bool pCopy, s32 billno) {
    dds3Particle_Basic_t__dCopy(0, 0);
    dds3Particle_SphereRing_t3__pCopy(0, 0, 0);
    dds3Particle_BasicCreate(0, 0);
    dds3Particle_SphereRingAllBuffInit(0);
    return 0;
}

// 0x1127d60
void dds3Particle_SphereRingDelete(void **hData) {
    dds3Particle_BasicDelete(0);
}

// 0x1128190
void dds3Particle_SphereRingDraw(void **hData) {
    dds3Particle_EffectInit(0, 0);
    SDF_VU0__LOADMATRIX(0);
    sdfCos(0);
    sdfSin(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    dds3Particle_SphereRingBuffInit(0, 0);
    dds3ParticleColorAnim(0, 0, 0);
    SDF_VU0__dds3ColorItoF(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__MULVECTOR();
    SDF_VU0__dds3ColorFtoI(0);
    SDF_VU0__LOADVECTOR_C((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(0);
    dds3Particle_EffectSet(0, 0, 0, 0);
    dds3Particle_EffectReset(0, 0);
}

// 0x1127980
void dds3Particle_SphereRingSetScale(void **hData, f32 scale) {
}

// 0x11265e0
void dds3Particle_SphereSmokeAllBuffInit(void **hData) {
}

// 0x1126c70
void dds3Particle_SphereSmokeBuffInit(dds3Particle_SphereSmoke_t3 **pSphereSmoke, s32 number) {
    DDS3EFFECT_RAND_PM();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    DDS3EFFECT_RAND_FA(0);
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__APPLYMATRIX();
    sdfGetRand(0);
    dds3Particle_EffectReset(0, 0);
}

// 0x1126910
dds3Particle_Basic_t *dds3Particle_SphereSmokeCreate(void *hData, s32 bPos, bool pCopy, s32 billno) {
    dds3Particle_Basic_t__dCopy(0, 0);
    dds3Particle_SphereSmoke_t3__pCopy(0, 0, 0);
    dds3Particle_BasicCreate(0, 0);
    dds3Particle_SphereSmokeAllBuffInit(0);
    return 0;
}

// 0x1126b60
void dds3Particle_SphereSmokeDelete(void **hData) {
    dds3Particle_BasicDelete(0);
}

// 0x1127190
void dds3Particle_SphereSmokeDraw(void **hData) {
    dds3Particle_EffectInit(0, 0);
    SDF_VU0__LOADMATRIX(0);
    dds3Particle_SphereSmokeBuffInit(0, 0);
    dds3ParticleColorAnim(0, 0, 0);
    SDF_VU0__dds3ColorItoF(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__MULVECTOR();
    SDF_VU0__dds3ColorFtoI(0);
    SDF_VU0__LOADVECTOR_C((sdfVector4_t){0});
    sdfSin(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(0);
    dds3Particle_EffectSet(0, 0, 0, 0);
    dds3Particle_EffectReset(0, 0);
}

// 0x1126770
void dds3Particle_SphereSmokeSetScale(void **hData, f32 scale) {
}

// 0x112e830
void dds3Particle_SphereSpiral2AllBuffInit(void **hData) {
}

// 0x112f0d0
void dds3Particle_SphereSpiral2BuffInit(dds3Particle_SphereSpiral2_t3 **pSphereSpiral2, s32 number) {
    sdfGetRand(0);
    DDS3EFFECT_RAND_PM();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    DDS3EFFECT_RAND_FA(0);
    SDF_VU0__GETLENGTH();
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__APPLYMATRIX_XYZ();
    dds3Particle_EffectReset(0, 0);
}

// 0x112eb50
dds3Particle_Basic_t *dds3Particle_SphereSpiral2Create(void *hData, s32 bPos, bool pCopy, s32 billno) {
    dds3Particle_Basic_t__dCopy(0, 0);
    dds3Particle_SphereSpiral2_t3__pCopy(0, 0, 0);
    dds3Particle_BasicCreate(0, 0);
    dds3Particle_SphereSpiral2AllBuffInit(0);
    return 0;
}

// 0x112efc0
void dds3Particle_SphereSpiral2Delete(void **hData) {
    dds3Particle_BasicDelete(0);
}

// 0x112f6c0
void dds3Particle_SphereSpiral2Draw(void **hData) {
    dds3Particle_EffectInit(0, 0);
    SDF_VU0__LOADMATRIX_B(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    dds3Particle_SphereSpiral2BuffInit(0, 0);
    dds3ParticleColorAnim(0, 0, 0);
    SDF_VU0__dds3ColorItoF(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__MULVECTOR();
    SDF_VU0__dds3ColorFtoI(0);
    SDF_VU0__LOADVECTOR_C((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__GETLENGTH();
    SDF_VU0__NORMALIZE();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__COPYMATRIX_B_TO_A();
    SDF_VU0__APPLYMATRIX_XYZ();
    SetRotateMatrixAxis(0, (sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    dds3Particle_Track2SetExp(0, 0, (sdfVector4_t){0}, 0, 0);
    dds3Particle_BlurSetExp(0, 0, (sdfVector4_t){0}, 0, 0, 0);
    dds3Particle_TrackSetExp(0, 0, (sdfVector4_t){0}, 0, 0);
    dds3Particle_EffectReset(0, 0);
}

// 0x112e9c0
void dds3Particle_SphereSpiral2SetScale(void **hData, f32 scale) {
}

// 0x1125390
void dds3Particle_SphereSpiralAllBuffInit(void **hData) {
}

// 0x1125a10
void dds3Particle_SphereSpiralBuffInit(dds3Particle_SphereSpiral_t3 **pSphereSpiral, s32 number) {
    sdfGetRand(0);
    DDS3EFFECT_RAND_PM();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    DDS3EFFECT_RAND_FA(0);
    SDF_VU0__GETLENGTH();
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__APPLYMATRIX_XYZ();
    dds3Particle_EffectReset(0, 0);
}

// 0x11256b0
dds3Particle_Basic_t *dds3Particle_SphereSpiralCreate(void *hData, s32 bPos, bool pCopy, s32 billno) {
    dds3Particle_Basic_t__dCopy(0, 0);
    dds3Particle_SphereSpiral_t3__pCopy(0, 0, 0);
    dds3Particle_BasicCreate(0, 0);
    dds3Particle_SphereSpiralAllBuffInit(0);
    return 0;
}

// 0x1125900
void dds3Particle_SphereSpiralDelete(void **hData) {
    dds3Particle_BasicDelete(0);
}

// 0x1126000
void dds3Particle_SphereSpiralDraw(void **hData) {
    dds3Particle_EffectInit(0, 0);
    SDF_VU0__LOADMATRIX_B(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    dds3Particle_SphereSpiralBuffInit(0, 0);
    dds3ParticleColorAnim(0, 0, 0);
    SDF_VU0__dds3ColorItoF(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__MULVECTOR();
    SDF_VU0__dds3ColorFtoI(0);
    SDF_VU0__LOADVECTOR_C((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__GETLENGTH();
    SDF_VU0__NORMALIZE();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__COPYMATRIX_B_TO_A();
    SDF_VU0__APPLYMATRIX_XYZ();
    SetRotateMatrixAxis(0, (sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    dds3Particle_EffectSet(0, 0, 0, 0);
    dds3Particle_EffectReset(0, 0);
}

// 0x1125520
void dds3Particle_SphereSpiralSetScale(void **hData, f32 scale) {
}

// 0x111f8b0
void dds3Particle_SpiralAllBuffInit(void **hData) {
}

// 0x111ff60
void dds3Particle_SpiralBuffInit(dds3Particle_Spiral_t3 **pSpiral, s32 number) {
    DDS3EFFECT_RAND_FA(0);
    sdfCos(0);
    sdfSin(0);
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(0);
    dds3Particle_EffectReset(0, 0);
}

// 0x111fc00
dds3Particle_Basic_t *dds3Particle_SpiralCreate(void *hData, s32 bPos, bool pCopy, s32 billno) {
    dds3Particle_Basic_t__dCopy(0, 0);
    dds3Particle_Spiral_t3__pCopy(0, 0, 0);
    dds3Particle_BasicCreate(0, 0);
    dds3Particle_SpiralAllBuffInit(0);
    return 0;
}

// 0x111fe50
void dds3Particle_SpiralDelete(void **hData) {
    dds3Particle_BasicDelete(0);
}

// 0x11204f0
void dds3Particle_SpiralDraw(void **hData) {
    dds3Particle_EffectInit(0, 0);
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    dds3Particle_SpiralBuffInit(0, 0);
    dds3ParticleColorAnim(0, 0, 0);
    SDF_VU0__dds3ColorItoF(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__MULVECTOR();
    SDF_VU0__dds3ColorFtoI(0);
    SDF_VU0__LOADVECTOR_C((sdfVector4_t){0});
    sdfCos(0);
    sdfSin(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(0);
    dds3Particle_EffectSet(0, 0, 0, 0);
    dds3Particle_EffectReset(0, 0);
}

// 0x111fa60
void dds3Particle_SpiralSetScale(void **hData, f32 scale) {
}

// 0x1131150
void dds3Particle_Track2Set(dds3TrackPoly_t **hTrackPoly, s32 i, u32 abgr) {
  u64 *v7;

  v7 = NewSpecific(UnityEngine_Vector4, 3u);
  SDF_VU0__COPYVECTOR_C_TO_B();
  SDF_VU0__SUBVECTOR();
  SDF_VU0__LOADVECTOR_B(parLook);
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__NORMALIZE();
  SDF_VU0__LOADVECTOR_B(parTrack_w);
  SDF_VU0__MULVECTOR();
  SDF_VU0__SWAPVECTOR_A_C();
  SDF_VU0__STOREVECTOR(v7 + 3);
  SDF_VU0__COPYVECTOR_A_TO_B();
  SDF_VU0__ADDVECTOR_A_C();
  SDF_VU0__STOREVECTOR(v7 + 2);
  SDF_VU0__COPYVECTOR_C_TO_A();
  SDF_VU0__SUBVECTOR_B_A();
  SDF_VU0__STOREVECTOR_B(v7 + 4);
  dds3TrackPolySet2(hTrackPoly, i, v7);
  dds3TrackPolyVCRefresh_ParType2(hTrackPoly, i);
  dds3TrackPolyColorSet(hTrackPoly, i, abgr & 0xFF000000 | 0x808080);
}

// 0x1130840
void dds3Particle_Track2SetExp(dds3TrackPoly_t **hTrackPoly, s32 index, sdfVector4_t pPos, u32 abgr, dds3ParOffsetBuff_t *pOffBuff) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_C((sdfVector4_t){0});
    SDF_VU0__COPYVECTOR_C_TO_B();
    SDF_VU0__SUBVECTOR();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__OUTERPRODUCT();
    SDF_VU0__NORMALIZE();
    SDF_VU0__MULVECTOR();
    SDF_VU0__SWAPVECTOR_A_C();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__ADDVECTOR_A_C();
    SDF_VU0__COPYVECTOR_C_TO_A();
    SDF_VU0__SUBVECTOR_B_A();
    SDF_VU0__STOREVECTOR_B(0);
    dds3TrackPolyVCRefresh_ParType2(0, 0);
    dds3TrackPolyColorSet(0, 0, 0);
}

// 0x1131340
void dds3Particle_Track3Set(effMTPolyListHandle_t **hTrackPoly, s32 i, u32 abgr) {
  u64 *v7;

  v7 = NewSpecific(UnityEngine_Vector4, 2u);
  SDF_VU0__COPYVECTOR_C_TO_B();
  SDF_VU0__SUBVECTOR();
  SDF_VU0__LOADVECTOR_B(parLook);
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__NORMALIZE();
  SDF_VU0__LOADVECTOR_B(parTrack_w);
  SDF_VU0__MULVECTOR();
  SDF_VU0__SWAPVECTOR_A_C();
  SDF_VU0__COPYVECTOR_A_TO_B();
  SDF_VU0__ADDVECTOR_A_C();
  SDF_VU0__STOREVECTOR(v7 + 2);
  SDF_VU0__COPYVECTOR_C_TO_A();
  SDF_VU0__SUBVECTOR_B_A();
  SDF_VU0__STOREVECTOR_B(v7 + 3);
  Eff_ModelTrackPolyListVertexSet(hTrackPoly, i, v7);
  Eff_ModelTrackPolyListColorSet(hTrackPoly, i, abgr & 0xFF000000 | 0x808080);
}

// 0x1131b60
void dds3Particle_Track3SetExp(effMTPolyListHandle_t **hTrackPoly, s32 i, u32 abgr) {
  ;
}

// 0x111f710
s32 dds3Particle_TrackPolyGetRecTiming(s32 number) {
  return 0;
}

// 0x1130f90
void dds3Particle_TrackSet(dds3TrackPoly_t **hTrackPoly, s32 i, u32 abgr) {
  u64 *v7;

  v7 = NewSpecific(UnityEngine_Vector4, 2u);
  SDF_VU0__COPYVECTOR_C_TO_B();
  SDF_VU0__SUBVECTOR();
  SDF_VU0__LOADVECTOR_B(parLook);
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__NORMALIZE();
  SDF_VU0__LOADVECTOR_B(parTrack_w);
  SDF_VU0__MULVECTOR();
  SDF_VU0__SWAPVECTOR_A_C();
  SDF_VU0__COPYVECTOR_A_TO_B();
  SDF_VU0__ADDVECTOR_A_C();
  SDF_VU0__STOREVECTOR(v7 + 2);
  SDF_VU0__COPYVECTOR_C_TO_A();
  SDF_VU0__SUBVECTOR_B_A();
  SDF_VU0__STOREVECTOR_B(v7 + 3);
  dds3TrackPolySet(hTrackPoly, i, v7);
  dds3TrackPolyVCRefresh_ParType1(hTrackPoly, i);
  dds3TrackPolyColorSet(hTrackPoly, i, abgr & 0xFF000000 | 0x808080);
}

// 0x11302f0
void dds3Particle_TrackSetExp(dds3TrackPoly_t **hTrackPoly, s32 index, sdfVector4_t pPos, u32 abgr, dds3ParOffsetBuff_t *pOffBuff) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_C((sdfVector4_t){0});
    SDF_VU0__COPYVECTOR_C_TO_B();
    SDF_VU0__SUBVECTOR();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__OUTERPRODUCT();
    SDF_VU0__NORMALIZE();
    SDF_VU0__MULVECTOR();
    SDF_VU0__SWAPVECTOR_A_C();
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__ADDVECTOR_A_C();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__COPYVECTOR_C_TO_A();
    SDF_VU0__SUBVECTOR_B_A();
    SDF_VU0__STOREVECTOR_B(0);
    dds3TrackPolyVCRefresh_ParType1(0, 0);
    dds3TrackPolyColorSet(0, 0, 0);
}

// 0x1131e40
void pMeshDelete(billHandle_t **hBillboard) {
  billHandle_t_o *v3;
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
  s64 v18;

  v3 = *hBillboard;
  if (*hBillboard)
  {
    pMesh = v3->pMesh;
    p_pMesh = &v3->pMesh;
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
            v12 = (*hBillboard)->pMesh;
            gameObject = get_gameObject(*(&v12->obj.klass + v8), 0);
            Destroy_27360000(gameObject);
            v16 = (*hBillboard)->pMesh;
            *(&v16->obj.klass + v8) = 0;
          }
          v5 = (*hBillboard)->pMesh;
          max_length = v5->max_length;
          v18 = v8 - 3;
          ++v8;
        }
        while (v18 < max_length);
        p_pMesh = &(*hBillboard)->pMesh;
      }
      *p_pMesh = 0;
    }
  }
}
