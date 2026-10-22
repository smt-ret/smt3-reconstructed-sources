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
          goto LABEL_16;
      }
      else
      {
        v13->texture = NewSpecific(UnityEngine_Texture, 1u);
        v13 = *hBillboard;
        if ((*hBillboard)->type == 1)
        {
LABEL_16:
          v13->pP2A->basic->texture = v13->texture;
          TextureMax = billGetTextureMax();
          v16 = NewSpecific(UnityEngine_Texture, TextureMax);
          v17 = 0;
          {
LABEL_22:
          }
          while (v17 < billGetTextureMax())
          {
            v20 = billGetTexture(v9);
            v21 = v20;
            *&v16[2 * v17++ + 8] = v21;
              goto LABEL_22;
          }
          pP2A = (*hBillboard)->pP2A;
          pP2A->hResource = dds3BillAnimLoadP2A(&bytedata->obj, &bPos, v16);
          v25 = *hBillboard;
          v26 = v9 + 128;
          goto LABEL_47;
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
LABEL_47:
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
      goto LABEL_18;
    goto LABEL_9;
  }
  if (pColAnim->alpha_s < frame)
  {
    v5 = pColAnim->alpha << 24;
    if (pColAnim->type == 1)
      goto LABEL_18;
LABEL_9:
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
    goto LABEL_9;
LABEL_18:
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
  s32 v3;
  u16 *v5;
  s64 v6;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  struct dds3EffectTable_t_array *EffParticleTable;
  s64 v12;
  dds3Particle_Basic_t_o *result;
  dds3Particle_Basic_t_c *klass;
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
      || *(*(v6 + 200) + 8 * typeHierarchyDepth - 8) != dds3Particle_Basic_t)
    {
      sub_8FC2C0(*(v6 + 64), dds3Particle_Basic_t, v19);
      if ((v19[0] & 1) != 0)
        v8 = v20;
      else
        v8 = v19 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v12 = v5[130];
  result = dds3EffectTable_t_CreateDelegate__Invoke(EffParticleTable->m_Items[v12]->Create, *hData, v3, 1, 0);
  klass = result->klass;
  if (result->klass->_2.typeHierarchyDepth < v16
    || klass->_2.typeHierarchy[v16 - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v19);
    if ((v19[0] & 1) != 0)
      v17 = v20;
    else
      v17 = v19 + 1;
    v18 = sub_8C4940(v17);
  }
  result->type = v5[130];
  return result;
}

// 0x1131b70
dds3Particle_Basic_t *dds3ParticleCreate(u16 type, void *pData, s32 bPos) {
  struct dds3EffectTable_t_array *EffParticleTable;
  dds3Particle_Basic_t_o *result;
  dds3Particle_Basic_t_c *klass;
  s64 typeHierarchyDepth;
  char *v13;
  s64 *v14;
  u64 v15[3];

  result = dds3EffectTable_t_CreateDelegate__Invoke(EffParticleTable->m_Items[type]->Create, pData, bPos, 0, 0);
  klass = result->klass;
  if (result->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v15);
    if ((v15[0] & 1) != 0)
      v13 = v15[2];
    else
      v13 = v15 + 1;
    v14 = sub_8C4940(v13);
  }
  result->type = type;
  return result;
}

// 0x1131ce0
void dds3ParticleDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  struct dds3EffectTable_t_array *EffParticleTable;
  s64 v9;
  u64 v11[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v11);
      if ((v11[0] & 1) != 0)
        v6 = v11[2];
      else
        v6 = v11 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  pMeshDelete(&v3[11]);
  v9 = WORD2(v3[16].klass);
  dds3EffectTable_t_DeleteDelegate__Invoke(EffParticleTable->m_Items[v9]->Delete, hData);
}

// 0x1132100
void dds3ParticleDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u32 v8;
  struct dds3EffectTable_t_array *EffParticleTable;
  s64 v11;
  billHandle_t_o *v13;
  Il2CppClass *v15;
  s32 *typeDefinition;
  u32 *v17;
  s32 v18;
  s64 v19;
  u64 v23;
  XRD773Unity_GraphicManager_o *Instance;
  s64 *Mesh;
  s64 *v26;
  UnityEngine_Component_o **v28;
  UnityEngine_Object_o *gameObject;
  System_Object_array *v31;
  s64 *name;
  s64 *v33;
  Il2CppClass *v39;
  s64 *v42;
  s64 *v43;
  System_String_o *v45;
  XRD773Unity_GraphicManager_CommonObject_o **v46;
  s64 v48;
  struct dds3EffectTable_t_array *v50;
  s64 v51;
  s32 monitor;
  s64 klass_low;
  f32 v55;
  f32 v56;
  f32 v58;
  f32 v59;
  u64 v61;
  s32 v62;
  s64 v63;
  u64 *v64;
  s64 v66;
  s32 v67;
  Il2CppClass *v69;
  u64 *v70;
  s64 v71;
  s32 v72;
  s64 v73;
  XRD773Unity_CommonMesh_o **v75;
  s64 v77;
  u64 i;
  s64 v79;
  u64 *v80;
  s64 v82;
  s32 v83;
  void *v85;
  UnityEngine_GameObject_o *v87;
  Il2CppObject *hDataa;
  billHandle_t_o *hBillboard;
  u64 v91[3];

  hDataa = 0;
  hBillboard = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v91);
      if ((v91[0] & 1) != 0)
        v6 = v91[2];
      else
        v6 = v91 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  hBillboard = 0;
  if (!HIWORD(v3[16].klass))
    return;
  if (LODWORD(v3[12].klass))
  {
    v8 = 0;
    do
    {
      v11 = WORD2(v3[16].klass);
      dds3EffectTable_t_DrawDelegate__Invoke(EffParticleTable->m_Items[v11]->Draw, hData);
      ++v8;
    }
    while (v8 < LODWORD(v3[12].klass));
    LODWORD(v3[12].klass) = 0;
    v13 = v3[11].klass;
    hBillboard = v13;
    if (!v13)
      goto LABEL_71;
  }
  else
  {
    v50 = EffParticleTable;
    v51 = WORD2(v3[16].klass);
    dds3EffectTable_t_DrawDelegate__Invoke(v50->m_Items[v51]->Draw, hData);
    v13 = v3[11].klass;
    hBillboard = v13;
    if (!v13)
      goto LABEL_71;
  }
  if (!v13->pMesh)
  {
    v13->pMesh = NewSpecific(XRD773Unity_CommonMesh, 1u);
    v15 = v3[11].klass;
    typeDefinition = v15->_1.typeDefinition;
    v17 = (typeDefinition + 6);
    v18 = v15->_1.parent ? LOWORD(v3[4].klass) + 4 : LOWORD(v3[4].klass);
    if (typeDefinition[6] >= 1)
    {
      v19 = 4;
      do
      {
        {
        }
        v23 = v19 - 4;
        Instance = get_Instance();
        Mesh = GetMesh(Instance, v18, 0);
        v26 = Mesh;
        *&typeDefinition[2 * v19] = v26;
        v28 = v3[11].klass->_1.typeDefinition;
        gameObject = get_gameObject(v28[v19]);
        v31 = NewSpecific(object, 5u);
        name = get_name(gameObject);
        v33 = name;
        v31->m_Items[0] = v33;
        v31->m_Items[1] = ":dds3ParticleDraw:UseOne:call:";
        v39 = v3[11].klass->_1.klass;
        v31->m_Items[2] = v39;
        v31->m_Items[3] = ":";
        LODWORD(v91[0]) = v19 - 4;
        v42 = sub_8D3950(s32, v91);
        v43 = v42;
        v31->m_Items[4] = v43;
        v45 = Concat_5270224(v31);
        set_name(gameObject, v45);
        v46 = v3[11].klass->_1.typeDefinition;
        SetAutoHide(v46[v19], 1);
        typeDefinition = v3[11].klass->_1.typeDefinition;
        v17 = (typeDefinition + 6);
        v48 = v19 - 3;
        ++v19;
      }
      while (v48 < typeDefinition[6]);
    }
  }
LABEL_71:
  monitor = v3[3].monitor;
  klass_low = LODWORD(v3[3].klass);
  sub_854710(&v3[2], 0);
  v56 = v55;
  sub_854710(&v3[2], 1u);
  v59 = v58;
  dds3BillboardSetScale(&hBillboard, v56, v59);
  hDataa = hBillboard;
  if (klass_low < 1)
  {
    v62 = 0;
  }
  else
  {
    v61 = 0;
    v62 = 0;
    do
    {
      v64 = v3[11].monitor;
      else
      {
        v63 = v64[3];
        if (v61 >= *(v63 + 24))
        {
LABEL_81:
        }
      }
      v66 = v63 + 8 * v61++;
      v62 += *(*(v66 + 32) + 48LL) >= 0 && monitor > *(*(v66 + 32) + 48LL);
    }
    while (klass_low != v61);
  }
  v67 = dds3Particle_EffectDrawNum(&v3[4].monitor);
  v69 = v3[11].klass;
  v70 = v69->_1.typeDefinition;
  v71 = v70[3];
  if (v71 >= 1)
  {
    v72 = v67 + v62;
    v73 = 4;
    do
    {
      SetUseIndexMax(v70[v73], v72);
      v75 = v3[11].klass->_1.typeDefinition;
      ClearUseIndex(v75[v73]);
      v69 = v3[11].klass;
      v70 = v69->_1.typeDefinition;
      LODWORD(v71) = *(v70 + 6);
      v77 = v73 - 3;
      ++v73;
    }
    while (v77 < v71);
  }
  if (klass_low >= 1)
  {
    for (i = 0; i != klass_low; ++i)
    {
      v80 = v3[11].monitor;
      else
      {
        v79 = v80[3];
        if (i >= *(v79 + 24))
        {
LABEL_102:
        }
      }
      v82 = *(v79 + 8 * i + 32);
      v83 = *(v82 + 48);
      if (monitor > v83 && (v83 & 0x80000000) == 0)
      {
        SDF_VU0__COPYVECTOR(&hBillboard->pos, *(v82 + 16), 0);
        hBillboard->abgr = *(v82 + 52);
        dds3BillboardDraw(&hDataa);
      }
    }
    v69 = v3[11].klass;
  }
  if (v69)
  {
    v85 = v69->_1.typeDefinition;
    if (v85)
    {
      v87 = get_gameObject(*(v85 + 4), 0);
      if (get_activeSelf(v87))
      {
        dds3Particle_EffectDraw(&v3[4].monitor);
      }
    }
  }
}

// 0x1131fb0
void dds3ParticleDrawOff(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  u64 *typeDefinition;
  s64 v7;
  u64 v8;
  char *v10;
  s64 *v11;
  u64 v12[3];

  v3 = *hData;
  klass = v3->klass;
  if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v12);
    if ((v12[0] & 1) != 0)
      v10 = v12[2];
    else
      v10 = v12 + 1;
    v11 = sub_8C4940(v10);
  }
  typeDefinition = v3[11].klass->_1.typeDefinition;
  if (typeDefinition)
  {
    v7 = typeDefinition[3];
    if (v7 >= 1)
    {
      v8 = 0;
      do
      {
        SetActive(typeDefinition[v8 + 4], 0, 0);
        typeDefinition = v3[11].klass->_1.typeDefinition;
        LODWORD(v7) = *(typeDefinition + 6);
        ++v8;
      }
      while (v8 < v7);
    }
  }
}

// 0x1133ee0
dds3Particle_Basic_t *dds3ParticleExpCopy(void **hData, s32 bPos) {
  s32 v3;
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  struct dds3EffectTable_t_array *EffParticleTable;
  s64 v12;
  Il2CppObject *v14;
  dds3Particle_Basic_t_o *v16;
  Il2CppClass *v17;
  s64 v18;
  char *v19;
  s64 *v20;
  billHandle_t_o *v21;
  f32 v22;
  f32 v23;
  f32 v24;
  billHandle_t_o *v25;
  Il2CppClass *v26;
  u64 v28[2];
  char *v29;
  billHandle_t_o *hBillboard;

  v3 = bPos;
  hBillboard = 0;
  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v28);
      if ((v28[0] & 1) != 0)
        v8 = v29;
      else
        v8 = v28 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  hBillboard = 0;
  v12 = WORD2(v5[16].klass);
  v14 = dds3EffectTable_t_CreateDelegate__Invoke(EffParticleTable->m_Items[v12]->Create, *hData, v3, 1, 0);
  v16 = v14;
  if (v14)
  {
    v17 = v14->klass;
    if (v14->klass->_2.typeHierarchyDepth < v18
      || v17->_2.typeHierarchy[v18 - 1] != dds3Particle_Basic_t)
    {
      sub_8FC2C0(v17->_1.element_class, dds3Particle_Basic_t, v28);
      if ((v28[0] & 1) != 0)
        v19 = v29;
      else
        v19 = v28 + 1;
      v20 = sub_8C4940(v19);
    }
  }
  WORD2(v14[16].klass) = WORD2(v5[16].klass);
  if (HIDWORD(v5[3].monitor) == -1)
  {
    v21 = v5[11].klass;
    hBillboard = dds3BillboardCopy(v21);
    sub_854710(&v16->scale, 0);
    v23 = v22;
    sub_854710(&v16->scale, 1u);
    dds3BillboardSetScale(&hBillboard, v23, v24);
    dds3BillboardSetMode(&hBillboard, v16->billmode);
    dds3BillboardSetAnimColorAdvMode(&hBillboard);
    v25 = hBillboard;
    if (hBillboard)
    {
      v26 = v5[11].klass;
      if (v26)
      {
        hBillboard->alf_raito = *&v26->_1.generic_class;
        v25->bri_raito = *(&v5[11].klass->_1.generic_class + 1);
      }
    }
    v16->hBillboard = v25;
  }
  return v16;
}

// 0x1133710
dds3Particle_Basic_t *dds3ParticleExpCreate(u16 type, void *pData, s32 bPos) {
  Il2CppClass *v6;
  s64 *Interface;
  char *v8;
  s64 *v9;
  dds3Particle_Exp_t_o *v10;
  u32 size;
  u32 v13;
  bool v15;
  struct dds3EffectTable_t_array *v16;
  Il2CppObject *v18;
  dds3Particle_Basic_t_o *v19;
  Il2CppClass *v20;
  s64 v21;
  char *v22;
  s64 *v23;
  s32 v24;
  s32 v25;
  System_String_o *v26;
  System_String_o *v28;
  f32 v30;
  f32 v31;
  f32 v32;
  billHandle_t_o *v33;
  billHandle_t_o *v34;
  struct dds3EffectTable_t_array *EffParticleTable;
  Il2CppObject *v37;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v40;
  s64 *v41;
  billHandle_t_o *v43;
  u64 v44[2];
  char *v45;
  s32 oPos;
  s32 pos;

  pos = bPos;
  oPos = 0;
  v43 = 0;
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v6, v44);
      if ((v44[0] & 1) != 0)
        v8 = v45;
      else
        v8 = v44 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  else
  {
    Interface = 0;
  }
  v10 = Allocate(dds3Particle_Exp_t);
  dds3Particle_Exp_t___ctor(v10);
  dds3Particle_Exp_t__pCopy(v10, Interface, &pos);
  oPos = pos;
  v13 = v10->type;
  size = v10->size;
  pos += size;
  if (size)
    v15 = 0;
  else
    v15 = v13 == 3;
  if (v15)
  {
    v37 = dds3EffectTable_t_CreateDelegate__Invoke(EffParticleTable->m_Items[type]->Create, Interface, pos, 0, 0);
    v19 = v37;
    if (v37)
    {
      klass = v37->klass;
      if (v37->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v44);
        if ((v44[0] & 1) != 0)
          v40 = v45;
        else
          v40 = v44 + 1;
        v41 = sub_8C4940(v40);
      }
    }
  }
  else
  {
    v16 = EffParticleTable;
    v18 = dds3EffectTable_t_CreateDelegate__Invoke(v16->m_Items[type]->Create, Interface, pos, 0, -1);
    v19 = v18;
    if (v18)
    {
      v20 = v18->klass;
      if (v18->klass->_2.typeHierarchyDepth < v21
        || v20->_2.typeHierarchy[v21 - 1] != dds3Particle_Basic_t)
      {
        sub_8FC2C0(v20->_1.element_class, dds3Particle_Basic_t, v44);
        if ((v44[0] & 1) != 0)
          v22 = v45;
        else
          v22 = v44 + 1;
        v23 = sub_8C4940(v22);
      }
    }
    v24 = v10->type;
    v25 = oPos;
    v26 = sub_232A70(&oPos, "x8");
    v28 = Concat_5224608("dds3ParticleExpCreate", v26);
    v43 = dds3BillboardCreate(v24, Interface, v25, v28);
    SetExpTextureUnity(&v43, Interface, oPos);
    sub_854710(&v19->scale, 0);
    v31 = v30;
    sub_854710(&v19->scale, 1u);
    dds3BillboardSetScale(&v43, v31, v32);
    dds3BillboardSetMode(&v43, v19->billmode);
    dds3BillboardSetAnimColorAdvMode(&v43);
    v33 = v43;
    v33->alf_raito = billAlfRaitoGet();
    v34 = v43;
    v34->bri_raito = billBriRaitoGet();
    billAlfRaitoSet(0.0);
    billBriRaitoSet(0.0);
    v19->hBillboard = v43;
  }
  v19->type = type;
  return v19;
}

// 0x11341c0
void dds3ParticleExpDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  struct dds3EffectTable_t_array *EffParticleTable;
  s64 v9;
  u64 v11[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v11);
      if ((v11[0] & 1) != 0)
        v6 = v11[2];
      else
        v6 = v11 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  pMeshDelete(&v3[11]);
  v9 = WORD2(v3[16].klass);
  dds3EffectTable_t_DeleteDelegate__Invoke(EffParticleTable->m_Items[v9]->Delete, hData);
}

// 0x11344a0
void dds3ParticleExpDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u32 v8;
  struct dds3EffectTable_t_array *v10;
  s64 v11;
  f32 v13;
  s64 klass_low;
  f32 v16;
  f32 *monitor;
  f32 v18;
  f32 v19;
  f32 v20;
  u32 v21;
  f32 v22;
  u64 i;
  s64 v24;
  u64 *v25;
  s64 v27;
  f32 v28;
  billHandle_t_o *v29;
  struct dds3EffectTable_t_array *EffParticleTable;
  s64 v32;
  u64 TexNum;
  Il2CppClass *v35;
  s32 *pMesh;
  s32 v38;
  u32 *v39;
  s64 v40;
  u64 v49;
  XRD773Unity_GraphicManager_o *Instance;
  s64 *Mesh;
  s64 *v52;
  UnityEngine_Component_o **typeDefinition;
  UnityEngine_Object_o *gameObject;
  System_Object_array *v57;
  s64 *v60;
  s64 *v62;
  s64 *v66;
  s64 *v67;
  Il2CppClass *v71;
  s64 *v75;
  s64 *v76;
  s64 *v79;
  s64 *v80;
  System_String_o *v82;
  XRD773Unity_GraphicManager_CommonObject_o **v83;
  s64 v85;
  f32 v86;
  s64 v87;
  s32 v88;
  f32 *v90;
  f32 v91;
  f32 v92;
  f32 v93;
  f32 v94;
  s32 v95;
  f32 v96;
  u64 v97;
  s32 v98;
  s64 v99;
  u64 *v100;
  s64 v102;
  s32 v103;
  Il2CppClass *v105;
  u64 *v106;
  s64 v107;
  s32 v108;
  s64 v109;
  XRD773Unity_CommonMesh_o **v111;
  s64 v113;
  f32 v114;
  u64 j;
  s64 v116;
  u64 *v117;
  s64 v119;
  s32 v120;
  billHandle_t_o *v121;
  s64 p_scale;
  f32 v124;
  void *v125;
  UnityEngine_GameObject_o *v127;
  s32 v129;
  s16 v130;
  Il2CppObject *UnnamedParameter;
  Il2CppObject *v132;
  Il2CppObject *hDataa;
  billHandle_t_o *hBillboard;
  u64 v135[3];

  hDataa = 0;
  hBillboard = 0;
  UnnamedParameter = 0;
  v132 = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v135);
      if ((v135[0] & 1) != 0)
        v6 = v135[2];
      else
        v6 = v135 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  hBillboard = 0;
  if (!HIWORD(v3[16].klass))
    return;
  if (!LODWORD(v3[12].klass))
  {
    v132 = v3;
    v32 = WORD2(v3[16].klass);
    dds3EffectTable_t_DrawDelegate__Invoke(EffParticleTable->m_Items[v32]->Draw, &v132);
    v29 = v3[11].klass;
    if (v29)
      goto LABEL_37;
LABEL_46:
    hBillboard = 0;
    return;
  }
  v8 = 0;
  do
  {
    UnnamedParameter = v3;
    v10 = EffParticleTable;
    v11 = WORD2(v3[16].klass);
    dds3EffectTable_t_DrawDelegate__Invoke(v10->m_Items[v11]->Draw, &UnnamedParameter);
    ++v8;
  }
  while (v8 < LODWORD(v3[12].klass));
  v13 = *(v3[5].monitor + 4);
  klass_low = LODWORD(v3[3].klass);
  sub_854710(&v3[2], 0);
  monitor = v3[5].monitor;
  if (*(monitor + 32))
    v18 = -1.0;
  else
    v18 = 1.0;
  if (LODWORD(v3[12].klass) && klass_low >= 1)
  {
    v19 = (v13 - v16) / SLODWORD(v3[3].monitor);
    v20 = monitor[5] * 0.017453;
    v21 = 0;
    do
    {
      v22 = 1.0;
      for (i = 0; i != klass_low; ++i)
      {
        v25 = v3[11].monitor;
        else
        {
          v24 = v25[3];
          if (i >= *(v24 + 24))
          {
LABEL_31:
          }
        }
        v27 = *(v24 + 8 * i + 32);
        if ((*(v27 + 48) & 0x80000000) == 0)
        {
          v28 = *(v27 + 60);
          *(v27 + 56) = v19 + *(v27 + 56);
          *(v27 + 60) = (v20 * v22) + v28;
        }
        v22 = v18 * v22;
      }
      ++v21;
    }
    while (v21 < LODWORD(v3[12].klass));
  }
  LODWORD(v3[12].klass) = 0;
  v29 = v3[11].klass;
  if (!v29)
    goto LABEL_46;
LABEL_37:
  if (v29->pMesh)
  {
    hBillboard = v29;
    if (v29->type == 1)
      goto LABEL_124;
  }
  else
  {
    if (v29->type == 1)
    {
      TexNum = v29->pP2A->hResource->TexNum;
    }
    else
    {
      TexNum = 1;
    }
    v29->pMesh = NewSpecific(v35, TexNum);
    v29 = v3[11].klass;
    pMesh = v29->pMesh;
    if (v29->texture)
      v38 = LOWORD(v3[4].klass) + 4;
    else
      v38 = LOWORD(v3[4].klass);
    v39 = (pMesh + 6);
    if (pMesh[6] >= 1)
    {
      v40 = 4;
      do
      {
        {
        }
        v49 = v40 - 4;
        Instance = get_Instance();
        Mesh = GetMesh(Instance, v38, 0);
        v52 = Mesh;
        *&pMesh[2 * v40] = v52;
        typeDefinition = v3[11].klass->_1.typeDefinition;
        gameObject = get_gameObject(typeDefinition[v40]);
        v57 = NewSpecific(object, 0xAu);
        v57->m_Items[0] = "dds3ParticleExpDraw:UseOne:type=";
        v130 = WORD2(v3[16].klass);
        v60 = sub_8D3950(ushort, &v130);
        v62 = v60;
        v57->m_Items[1] = v62;
        v57->m_Items[2] = ":";
        v66 = sub_232970(&exp_uniq);
        v67 = v66;
        v57->m_Items[3] = v67;
        v57->m_Items[4] = ":call:";
        v71 = v3[11].klass->_1.klass;
        v57->m_Items[5] = v71;
        v57->m_Items[6] = ":tmx=";
        LODWORD(v135[0]) = v3[11].klass->_1.interopData;
        v75 = sub_8D3950(s32, v135);
        v76 = v75;
        v57->m_Items[7] = v76;
        v57->m_Items[8] = ":";
        v129 = v40 - 4;
        v79 = sub_8D3950(s32, &v129);
        v80 = v79;
        v57->m_Items[9] = v80;
        v82 = Concat_5270224(v57);
        set_name(gameObject, v82);
        v83 = v3[11].klass->_1.typeDefinition;
        SetAutoHide(v83[v40], 1);
        ++exp_uniq;
        v29 = v3[11].klass;
        pMesh = v29->pMesh;
        v85 = v40 - 3;
        v39 = (pMesh + 6);
        ++v40;
      }
      while (v85 < pMesh[6]);
    }
    hBillboard = v29;
    if (!v29)
      return;
    if (v29->type == 1)
      goto LABEL_124;
  }
  v29->pNormal->hResource->number = 0;
LABEL_124:
  v86 = *(v3[5].monitor + 4);
  v87 = LODWORD(v3[3].klass);
  v88 = v3[3].monitor;
  sub_854710(&v3[2], 0);
  v90 = v3[5].monitor;
  v91 = v90[5];
  LODWORD(v90) = *(v90 + 32);
  v93 = v92;
  v94 = 1.0;
  v95 = v3[3].monitor;
  hDataa = v29;
  if (v90)
    v96 = -1.0;
  else
    v96 = 1.0;
  if (v87 < 1)
  {
    v98 = 0;
  }
  else
  {
    v97 = 0;
    v98 = 0;
    do
    {
      v100 = v3[11].monitor;
      else
      {
        v99 = v100[3];
        if (v97 >= *(v99 + 24))
        {
LABEL_134:
        }
      }
      v102 = v99 + 8 * v97++;
      v98 += *(*(v102 + 32) + 48LL) >= 0 && v88 > *(*(v102 + 32) + 48LL);
    }
    while (v87 != v97);
  }
  v103 = dds3Particle_EffectDrawNum(&v3[4].monitor);
  v105 = v3[11].klass;
  v106 = v105->_1.typeDefinition;
  v107 = v106[3];
  if (v107 >= 1)
  {
    v108 = v103 + v98;
    v109 = 4;
    do
    {
      SetUseIndexMax(v106[v109], v108);
      v111 = v3[11].klass->_1.typeDefinition;
      ClearUseIndex(v111[v109]);
      v105 = v3[11].klass;
      v106 = v105->_1.typeDefinition;
      LODWORD(v107) = *(v106 + 6);
      v113 = v109 - 3;
      ++v109;
    }
    while (v113 < v107);
  }
  if (v87 >= 1)
  {
    v114 = (v86 - v93) / v95;
    for (j = 0; j != v87; ++j)
    {
      v117 = v3[11].monitor;
      else
      {
        v116 = v117[3];
        if (j >= *(v116 + 24))
        {
LABEL_155:
        }
      }
      v119 = *(v116 + 8 * j + 32);
      v120 = *(v119 + 48);
      if (v88 > v120 && (v120 & 0x80000000) == 0)
      {
        SDF_VU0__COPYVECTOR(&hBillboard->pos, *(v119 + 16), 0);
        v121 = hBillboard;
        hBillboard->abgr = *(v119 + 52);
        v121->rot = *(v119 + 60);
        p_scale = &v121->scale;
        sub_854930(&v121->scale, 1u);
        sub_854930(p_scale, 0);
        v124 = *(v119 + 60);
        *(v119 + 56) = fmaxf(v114 + *(v119 + 56), 0.0);
        *(v119 + 60) = ((v91 * 0.017453) * v94) + v124;
        dds3BillboardSetAnimKey(&hBillboard, v120);
        dds3BillboardDraw(&hDataa);
      }
      v94 = v96 * v94;
    }
    v105 = v3[11].klass;
  }
  if (v105)
  {
    v125 = v105->_1.typeDefinition;
    if (v125)
    {
      v127 = get_gameObject(*(v125 + 4), 0);
      if (get_activeSelf(v127))
      {
        dds3Particle_EffectDraw(&v3[4].monitor);
      }
    }
  }
}

// 0x1134320
void dds3ParticleExpDrawOff(void **hData) {
  Il2CppObject **v3;

  else
  {
    v3 = hData;
  }
  dds3ParticleDrawOff(v3);
}

// 0x1135740
u8 dds3ParticleExpGetLoop(void **hData) {
  Il2CppObject **v3;

  else
  {
    v3 = hData;
  }
  return dds3ParticleGetLoop(v3);
}

// 0x1135360
u16 dds3ParticleExpGetState(void **hData) {
  Il2CppObject **v3;

  else
  {
    v3 = hData;
  }
  return dds3ParticleGetState(v3);
}

// 0x11343a0
XRD773Unity_CommonMesh **dds3ParticleExpGetUseMesh(void **hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v5;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  v5 = (*hData)[11].klass;
  if (v5)
    return v5->_1.typeDefinition;
  else
    return 0;
}

// 0x11351a0
void dds3ParticleExpReset(void **hData) {
  Il2CppObject **v3;

  else
  {
    v3 = hData;
  }
  dds3ParticleReset(v3);
}

// 0x11356c0
void dds3ParticleExpSetLoop(void **hData, u8 loop) {
  dds3ParticleSetLoop(hData, loop);
}

// 0x11353e0
void dds3ParticleExpSetPosition(void **hData, sdfVector4_t pPos) {
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
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != dds3Particle_Basic_t)
    {
      sub_8FC2C0(*(v9 + 64), dds3Particle_Basic_t, v13);
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

// 0x11355d0
void dds3ParticleExpSetRGBA(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[10].monitor) = abgr;
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
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  f32 *monitor;
  u64 v11[3];

  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v11);
      if ((v11[0] & 1) != 0)
        v8 = v11[2];
      else
        v8 = v11 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  dds3ParticleSetScale(hData, scale);
  monitor = v5[5].monitor;
  if (monitor)
    monitor[4] = monitor[4] * scale;
}

// 0x1133570
u8 dds3ParticleGetLoop(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u8 result;
  u8 *monitor;
  u64 v10[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v10);
      if ((v10[0] & 1) != 0)
        v6 = v10[2];
      else
        v6 = v10 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  result = 0;
  switch (WORD2(v3[16].klass))
  {
    case 0:
      monitor = v3[17].klass;
      goto LABEL_23;
    case 1:
      return *(v3[17].monitor + 24);
    case 2:
      monitor = v3[18].klass;
      goto LABEL_23;
    case 3:
      monitor = v3[18].monitor;
      goto LABEL_23;
    case 4:
      monitor = v3[19].klass;
      goto LABEL_23;
    case 5:
      return *(v3[19].monitor + 24);
    case 6:
      monitor = v3[20].klass;
      goto LABEL_23;
    case 7:
      monitor = v3[20].monitor;
      goto LABEL_23;
    case 8:
      monitor = v3[21].klass;
      goto LABEL_23;
    case 0xA:
      monitor = v3[22].klass;
      goto LABEL_23;
    case 0xB:
      return *(v3[22].monitor + 24);
    case 0xC:
      monitor = v3[23].klass;
LABEL_23:
      result = monitor[25];
      break;
    default:
      return result;
  }
  return result;
}

// 0x1132f40
u16 dds3ParticleGetState(void **hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v8[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v8);
    if ((v8[0] & 1) != 0)
      v6 = v8[2];
    else
      v6 = v8 + 1;
    v7 = sub_8C4940(v6);
  }
  return HIWORD((*hData)[16].klass);
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
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  struct dds3EffectTable_Reset_t_array *ResetTbl;
  s64 v10;
  u64 v12[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v12);
      if ((v12[0] & 1) != 0)
        v6 = v12[2];
      else
        v6 = v12 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v10 = WORD2(v3[16].klass);
  dds3EffectTable_Reset_t_ResetDelegate__Invoke(ResetTbl->m_Items[v10]->Reset, hData);
  LODWORD(v3[12].klass) = HIDWORD(v3[6].klass);
  HIWORD(v3[16].klass) = 1;
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
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u8 *monitor;
  u64 v11[3];

  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v11);
      if ((v11[0] & 1) != 0)
        v8 = v11[2];
      else
        v8 = v11 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  switch (WORD2(v5[16].klass))
  {
    case 0:
      monitor = v5[17].klass;
      goto LABEL_23;
    case 1:
      *(v5[17].monitor + 24) = loop;
      break;
    case 2:
      monitor = v5[18].klass;
      goto LABEL_23;
    case 3:
      monitor = v5[18].monitor;
      goto LABEL_23;
    case 4:
      monitor = v5[19].klass;
      goto LABEL_23;
    case 5:
      *(v5[19].monitor + 24) = loop;
      break;
    case 6:
      monitor = v5[20].klass;
      goto LABEL_23;
    case 7:
      monitor = v5[20].monitor;
      goto LABEL_23;
    case 8:
      monitor = v5[21].klass;
      goto LABEL_23;
    case 0xA:
      monitor = v5[22].klass;
      goto LABEL_23;
    case 0xB:
      *(v5[22].monitor + 24) = loop;
      break;
    case 0xC:
      monitor = v5[23].klass;
LABEL_23:
      monitor[25] = loop;
      break;
    default:
      break;
  }
  HIWORD(v5[16].klass) = 1;
}

// 0x1133030
void dds3ParticleSetPosition(void **hData, sdfVector4_t pPos) {
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
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != dds3Particle_Basic_t)
    {
      sub_8FC2C0(*(v9 + 64), dds3Particle_Basic_t, v13);
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

// 0x11332f0
void dds3ParticleSetRGBA(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[10].monitor) = abgr;
}

// 0x1133160
void dds3ParticleSetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
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
  s64 v16;
  s64 v17;
  s64 v18;
  s64 v19;
  s64 v20;
  s64 v21;
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
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v25);
      if ((v25[0] & 1) != 0)
        v14 = v25[2];
      else
        v14 = v25 + 1;
      v15 = sub_8C4940(v14);
    }
  }
  v16 = *(&v7[12].klass + 4);
  v17 = *(&v7[12].monitor + 4);
  v18 = *(&v7[13].monitor + 4);
  *&v23.m01 = *(&v7[13].klass + 4);
  *&v23.m21 = v18;
  *&v23.m00 = v16;
  *&v23.m20 = v17;
  v19 = *(&v7[14].klass + 4);
  v20 = *(&v7[14].monitor + 4);
  v21 = *(&v7[15].monitor + 4);
  *&v23.m03 = *(&v7[15].klass + 4);
  *&v23.m23 = v21;
  *&v23.m02 = v19;
  *&v23.m22 = v20;
  SDF_VU0__LOADMATRIX_B(&v23);
  MultMatrixNoArg();
  SDF_VU0__STOREMATRIX(&v7[6].monitor);
}

// 0x1132d60
void dds3ParticleSetScale(void **hData, f32 scale) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  struct dds3EffectTable_Scale_t_array *ScaleTbl;
  s64 v12;
  u64 *monitor;
  s32 v16;
  s64 v17;
  u64 v18[3];

  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v18);
      if ((v18[0] & 1) != 0)
        v8 = v18[2];
      else
        v8 = v18 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v12 = WORD2(v5[16].klass);
  dds3EffectTable_Scale_t_ScaleDelegate__Invoke(ScaleTbl->m_Items[v12]->Scale, hData, scale);
  monitor = v5[4].monitor;
  if (monitor)
  {
    v16 = *(monitor + 8);
    switch (v16)
    {
      case 4:
        v17 = *(monitor[3] + 16LL);
        break;
      case 3:
        v17 = *(monitor[3] + 24LL);
        break;
      case 2:
        v17 = *(monitor[3] + 32LL);
        break;
      default:
        goto LABEL_23;
    }
    *(v17 + 20) = *(v17 + 20) * scale;
LABEL_23:
    dds3ParticleReset(hData);
  }
}

// 0x111ea10
void dds3Particle_BasicCreate(dds3Particle_Basic_t **pParBasic, bool pCopy) {
  f32 v7;
  u32 number;
  f32 v9;
  f32 v10;
  u32 v11;
  f32 bri_raito;
  dds3Particle_Basic_t_o *v15;
  s32 v16;
  dds3Particle_Basic_t_o *v19;
  s32 billno;
  struct billHandle_t_o *hBillboard;
  f32 alf_raito;
  Il2CppObject *v24;
  s32 frame;
  dds3Particle_Basic_t_o *v37;
  struct dds3Particle_Effect_t_o *effect;
  struct dds3Particle_Blur_t_o *blur;
  u32 v40;
  billHandle_t_o *v41;
  u16 length;
  s32 v43;
  struct dds3Particle_Track_t_o *track;
  s32 v45;
  struct dds3Particle_Track_t_o *v46;
  dds3Particle_Basic_t_o *v47;
  dds3TrackPoly_t_o **v48;
  s32 v49;
  struct dds3Particle_Track2_t_o *track2;
  s32 v51;
  struct dds3Particle_Track2_t_o *v52;
  struct dds3Particle_Track3_t_o *track3;
  u32 v54;
  dds3Particle_Basic_t_o *v55;
  s64 v56;
  s64 v57;
  s64 v58;
  s64 v59;
  s64 v60;
  s64 v61;
  s64 v62;
  UnityEngine_Matrix4x4_o v63;
  s64 eff_scl_raito;

  eff_scl_raito = 0;
  if (billCutRaitoGet() != 0.0)
  {
    else
    {
      v7 = billCutRaitoGet();
      if (v7 != 0.0)
        goto LABEL_14;
    }
    goto LABEL_26;
  }
  else if (billCutRaitoGet2() == 0.0)
  {
    goto LABEL_26;
  }
  v7 = billCutRaitoGet2();
  if (v7 == 0.0)
  {
LABEL_26:
      goto LABEL_29;
    goto LABEL_27;
  }
LABEL_14:
  number = (*pParBasic)->number;
  if (number != (*pParBasic)->numberO)
    goto LABEL_26;
  v9 = number;
  v10 = fmaxf((v7 * v9) / 100.0, 1.0);
  v11 = v10;
  if (v10 >= 0.0)
    v11 = v10;
  (*pParBasic)->number = v11;
  {
LABEL_27:
  }
LABEL_29:
  bri_raito = 0.0;
  billCutRaitoSet(0.0);
  eff_scl_raito = 0;
  billScaleRaitoGet(&eff_scl_raito + 1, &eff_scl_raito);
  (*pParBasic)->par_scl_raito = *(&eff_scl_raito + 1);
  LODWORD((*pParBasic)->eff_scl_raito) = eff_scl_raito;
  billScaleRaitoSet(0.0, 0.0);
  v15 = *pParBasic;
  v16 = (*pParBasic)->number;
  v15->hPhysics = dds3Particle_PhysicsCreate(v16);
  v19 = *pParBasic;
  billno = (*pParBasic)->billno;
  if (billno != -1)
  {
    if (pCopy)
    {
      hBillboard = v19->hBillboard;
      if (hBillboard)
      {
        alf_raito = hBillboard->alf_raito;
        bri_raito = hBillboard->bri_raito;
          goto LABEL_43;
      }
      else
      {
        alf_raito = 0.0;
          goto LABEL_43;
      }
    }
    else
    {
      alf_raito = billAlfRaitoGet();
      bri_raito = billBriRaitoGet();
      billAlfRaitoSet(0.0);
      billBriRaitoSet(0.0);
      v19 = *pParBasic;
      billno = (*pParBasic)->billno;
        goto LABEL_43;
    }
LABEL_43:
    v24 = dds3BillboardGeneral(billno);
    if (!v24)
      goto LABEL_50;
    goto LABEL_44;
  }
LABEL_52:
  frame = v19->frame;
  dds3ParticleSetColorTable(&v19->color, frame);
  v37 = *pParBasic;
  effect = (*pParBasic)->effect;
  switch (effect->type)
  {
    case 1u:
      blur = effect->param->blur;
      v40 = v37->number;
      v41 = v37->hBillboard;
      length = blur->length;
      blur->hBlur = dds3Particle_BlurCreate(v40, length, v41);
      break;
    case 2u:
      v43 = v37->number;
      track = effect->param->track;
      v45 = track->length;
      track->hTrackPoly = dds3TrackPolyCreate(v43, v45, 0, 0);
      v46 = (*pParBasic)->effect->param->track;
      dds3TrackPolyVCSet(&v46->hTrackPoly, 1, v46->color, v46->color);
      v47 = *pParBasic;
      v48 = (*pParBasic)->effect->param->track;
      goto LABEL_74;
    case 3u:
      v49 = v37->number;
      track2 = effect->param->track2;
      v51 = track2->length;
      track2->hTrackPoly = dds3TrackPolyCreate(v49, v51, 0, 1);
      v52 = (*pParBasic)->effect->param->track2;
      dds3TrackPolyVCSet(&v52->hTrackPoly, 1, v52->color_in, v52->color_out);
      v47 = *pParBasic;
      v48 = (*pParBasic)->effect->param->track2;
LABEL_74:
      dds3TrackPolySetMode(v48 + 4, v47->billmode);
      break;
    case 4u:
      LODWORD(off_28) = 1;
      HIDWORD(off_28) = (*pParBasic)->effect->param->track3->length;
      *init_proc = 10;
      loc_34 = (*pParBasic)->billmode;
      *(loc_38 + 16LL) = (*pParBasic)->effect->param->track3->color_s;
      *(loc_38 + 20LL) = *(loc_38 + 16LL);
      *(loc_38 + 24LL) = (*pParBasic)->effect->param->track3->color_e;
      *(loc_38 + 28LL) = *(loc_38 + 24LL);
      track3 = (*pParBasic)->effect->param->track3;
      v54 = (*pParBasic)->number;
      track3->hTrackPoly = Eff_ModelTrackPolyListCreate(0, v54);
      break;
    default:
      break;
  }
  (*pParBasic)->empty_loop = (*pParBasic)->d_frame;
  v55 = *pParBasic;
  v56 = *&(*pParBasic)->rot.m21;
  v57 = *&(*pParBasic)->rot.m00;
  v58 = *&(*pParBasic)->rot.m20;
  *&v63.m01 = *&(*pParBasic)->rot.m01;
  *&v63.m21 = v56;
  v59 = *&v55->rot.m02;
  v60 = *&v55->rot.m22;
  v62 = *&v55->rot.m03;
  v61 = *&v55->rot.m23;
  *&v63.m00 = v57;
  *&v63.m20 = v58;
  *&v63.m03 = v62;
  *&v63.m23 = v61;
  *&v63.m02 = v59;
  *&v63.m22 = v60;
  SDF_VU0__LOADMATRIX(&v63);
  SDF_VU0__STOREMATRIX(&(*pParBasic)->rot_b, 0);
  (*pParBasic)->abgr = -2139062144;
  (*pParBasic)->state = 1;
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
      goto LABEL_9;
    case 3u:
      track = effect->param->track2;
LABEL_9:
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
  if (!LODWORD(blurList->max_length))
  {
LABEL_5:
  }
  while (1)
  {
    v3 += blurList->m_Items[v2]->count;
    if ((*hBlur)->number - 1LL == v2)
      return v3;
    ++v2;
    blurList = (*hBlur)->blurList;
    if (v2 >= LODWORD(blurList->max_length))
      goto LABEL_5;
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
  struct dds3ParOffsetBuffParts_t_array *pParts;
  dds3ParOffsetBuffParts_t_o *v13;
  struct dds3Particle_BlurBuffList_t_array *blurList;
  dds3Particle_BlurBuffList_t_o *v16;
  s64 count;
  s64 v18;
  s64 v19;
  u64 v20;
  struct UnityEngine_Vector4_array *pPos;
  s64 v23;
  f32 w;
  s32 v25;
  struct UnityEngine_Vector3_array *pPosBuff;
  struct UnityEngine_Vector3_array *v28;
  struct UnityEngine_Vector3_array *v30;
  struct UnityEngine_Vector4_array *v32;
  s32 v33;
  s32 v34;
  s32 v35;
  u32 *v37;
  s64 v39;
  u32 length;
  UnityEngine_Vector4_o dst;
  s64 v42;
  s64 v43;

  v42 = 0;
  v43 = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  SDF_VU0__COPYVECTOR(&dst, pPosBase);
  pParts = pOffBuff->pParts;
  v13 = pParts->m_Items[index];
  blurList = (*hBlur)->blurList;
  v16 = blurList->m_Items[index];
  length = pOffBuff->length;
  LODWORD(v18) = v13->point;
  count = v13->count;
  v16->count = count;
  v39 = count;
  if (count >= 1)
  {
    v19 = 0;
    v20 = 0;
    do
    {
      pPos = v16->pPos;
      v23 = *&pPos->m_Items[v19].x;
      w = pPos->m_Items[v19].w;
      *&v43 = pPos->m_Items[v19].z;
      *(&v43 + 1) = w;
      v25 = length;
      if (v18)
        v25 = v18;
      v42 = v23;
      v18 = v25 - 1LL;
      sub_854710(&dst, 0);
      pPosBuff = v13->pPosBuff;
      sub_8527D0(&pPosBuff->m_Items[v18].x, 0);
      sub_854930(&v42, 0);
      sub_854710(&dst, 1u);
      v28 = v13->pPosBuff;
      sub_8527D0(&v28->m_Items[v18].x, 1);
      sub_854930(&v42, 1u);
      sub_854710(&dst, 2u);
      v30 = v13->pPosBuff;
      sub_8527D0(&v30->m_Items[v18].x, 2);
      sub_854930(&v42, 2u);
      v32 = v16->pPos;
      v33 = HIDWORD(v42);
      v34 = v43;
      v35 = HIDWORD(v43);
      v37 = (v32 + v19 * 16);
      ++v19;
      v37[8] = v42;
      v37[9] = v33;
      ++v20;
      v37[10] = v34;
      v37[11] = v35;
    }
    while (v39 != v20);
  }
  v16->abgr = abgr;
  v16->scale = scale;
}

// 0x1131620
void dds3Particle_EffectDraw(dds3Particle_Effect_t **pEffect) {
  dds3Particle_Effect_t_o *v3;
  s64 p_hBlur;
  dds3Particle_BlurBuff_t_o **v5;
  char *track;
  dds3TrackPoly_t_o **v7;
  effMTPolyListHandle_t_o **p_hTrackPoly;

  v3 = *pEffect;
  switch ((*pEffect)->type)
  {
    case 1u:
      p_hBlur = &v3->param->blur->hBlur;
      else
      {
        v5 = &v3->param->blur->hBlur;
      }
      dds3Particle_BlurDraw(v5);
      break;
    case 2u:
      track = v3->param->track;
      goto LABEL_10;
    case 3u:
      track = v3->param->track2;
LABEL_10:
      v7 = (track + 32);
      dds3TrackPolyDraw(v7, "");
      break;
    case 4u:
      p_hTrackPoly = &v3->param->track3->hTrackPoly;
      Eff_ModelTrackPolyListDrawOnly(p_hTrackPoly);
      break;
    default:
      return;
  }
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
LABEL_7:
  v6 = 0;
  v7 = 0;
  blurList = hBlur->blurList;
  if (!LODWORD(blurList->max_length))
  {
LABEL_10:
  }
  while (1)
  {
    v7 += blurList->m_Items[v6]->count;
    if (number - 1 == v6)
      return v7;
    ++v6;
    blurList = blur->hBlur->blurList;
    if (v6 >= LODWORD(blurList->max_length))
      goto LABEL_10;
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
      goto LABEL_9;
    case 3u:
      track = v3->param->track2;
LABEL_9:
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
  s32 type;

  type = pEffect->type;
  switch (type)
  {
    case 4:
      break;
    case 3:
      break;
    case 2:
      break;
    default:
      return;
  }
  sub_854930(&parTrack_w, 2u);
  sub_854930(&parTrack_w, 1u);
  sub_854930(&parTrack_w, 0);
  SDF_VU0__LOADVECTOR(dds3CameraTargetPos);
  SDF_VU0__LOADVECTOR_B(dds3CameraEyePos);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__STOREVECTOR(&parLook);
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
      goto LABEL_12;
    case 3u:
      track = v5->param->track2;
LABEL_12:
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
  dds3Particle_Basic_t_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3Particle_Nop_t3_o *monitor;
  u64 v9[3];

  monitor = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v9);
    if ((v9[0] & 1) != 0)
      v6 = v9[2];
    else
      v6 = v9 + 1;
    v7 = sub_8C4940(v6);
  }
  monitor = (*hData)[21].monitor;
  dds3Particle_NopBuffInit(&monitor, v3);
}

// 0x112ae80
void dds3Particle_NopBuffInit(dds3Particle_Nop_t3 **pNop) {
  struct dds3Particle_Physics_t_o *hPhysics;
  struct parPhysics_t_array *pPhysics;
  parPhysics_t_o *v6;
  struct dds3ParticleColorAnim_t_o *color;
  struct System_UInt32_array *v8;
  s32 v10;
  struct dds3Particle_Basic_t_o *basic;
  struct dds3Particle_Expansion_t_o *exp;
  f32 v13;
  struct dds3Particle_Basic_t_o *v14;
  f32 scl_r;
  f32 v17;
  f32 v18;
  f32 rot_r;
  f32 v21;

  hPhysics = (*pNop)->basic->hPhysics;
  else
  {
    pPhysics = hPhysics->pPhysics;
    if (!LODWORD(pPhysics->max_length))
      goto LABEL_6;
  }
  v6 = pPhysics->m_Items[0];
  sub_854710(&(*pNop)->basic->fields, 0);
  sub_854930(&v6->fields, 0);
  sub_854710(&(*pNop)->basic->fields, 1u);
  sub_854930(&v6->fields, 1u);
  sub_854710(&(*pNop)->basic->fields, 2u);
  sub_854930(&v6->fields, 2u);
  color = (*pNop)->basic->color;
  v8 = color->color;
  v10 = v8->m_Items[0] | (color->alpha << 24);
  v6->frame = -1;
  v6->color = v10;
  *&v6->scale = 1065353216;
  basic = (*pNop)->basic;
  exp = basic->exp;
  sub_854710(&basic->scale, 0);
  exp->scl = v13;
  v14 = (*pNop)->basic;
  scl_r = v14->exp->scl_r;
  sub_854710(&v14->scale, 0);
  v18 = v17;
  v6->scale = v18 * DDS3EFFECT_RAND_FA(scl_r);
  rot_r = (*pNop)->basic->exp->rot_r;
  if (rot_r == 0.0)
  {
    v21 = 0.0;
  }
  else
  {
    v21 = DDS3EFFECT_RAND_FA(rot_r) * 6.2832;
  }
  v6->rot = v21;
}

// 0x112b260
dds3Particle_Basic_t *dds3Particle_NopCreate(void *hData, s32 bPos, bool pCopy, s32 billno) {
  u64 *v8;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  dds3Particle_Nop_t3_o *pNop;
  Il2CppClass *v16;
  s64 *Interface;
  char *v18;
  s64 *v19;
  struct dds3Particle_Basic_t_o *basic;
  dds3Particle_Basic_t_o *result;
  dds3Particle_Basic_t_o *v22;
  u64 v23[2];
  char *v24;
  s32 bpos;

  bpos = bPos;
  v22 = 0;
  if (pCopy)
  {
    v8 = Allocate(dds3Particle_Basic_t);
    dds3Particle_Basic_t___ctor(v8);
    v22 = v8;
    if (hData)
    {
      klass = hData->klass;
      if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v23);
        if ((v23[0] & 1) != 0)
          v11 = v24;
        else
          v11 = v23 + 1;
        v12 = sub_8C4940(v11);
      }
    }
    dds3Particle_Basic_t__dCopy(hData, &v22);
    pNop = v22->pNop;
  }
  else
  {
    pNop = Allocate(dds3Particle_Nop_t3);
    dds3Particle_Nop_t3___ctor(pNop);
    if (hData)
    {
      Interface = QueryInterface(hData, byte);
      if (!Interface)
      {
        sub_8FC2C0(hData->klass->_1.element_class, v16, v23);
        if ((v23[0] & 1) != 0)
          v18 = v24;
        else
          v18 = v23 + 1;
        v19 = sub_8C4940(v18);
      }
    }
    else
    {
      Interface = 0;
    }
    dds3Particle_Nop_t3__pCopy(pNop, Interface, &bpos);
    if (billno == -1)
      pNop->basic->billno = -1;
  }
  pNop->basic->number = 1;
  pNop->basic->frame = 0;
  basic = pNop->basic;
  if (!basic->billno && !basic->billmode)
    basic->billmode = 2;
  dds3Particle_BasicCreate(&pNop->basic, pCopy);
  result = pNop->basic;
  result->pNop = pNop;
  return result;
}

// 0x112b4d0
void dds3Particle_NopDelete(void **hData) {
  dds3Particle_Basic_t_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3Particle_Basic_t_o *v6;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  v6 = *((*hData)[21].monitor + 2);
  dds3Particle_BasicDelete(v6, v3);
}

// 0x112b5e0
void dds3Particle_NopDraw(void **hData) {
  dds3Particle_Basic_t_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3Particle_Nop_t3_o *monitor;
  struct dds3Particle_Physics_t_o *hPhysics;
  struct parPhysics_t_array *pPhysics;
  parPhysics_t_o *v9;
  s32 frame;
  struct dds3ParticleColorAnim_t_o *color;
  struct System_UInt32_array *v14;
  u32 v16;
  u32 abgr;
  char *v18;
  s64 *v19;
  dds3Particle_Nop_t3_o *v20[3];
  dds3Particle_Nop_t3_o *pNop;

  pNop = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v20);
    if ((v20[0] & 1) != 0)
      v18 = v20[2];
    else
      v18 = v20 + 1;
    v19 = sub_8C4940(v18);
  }
  monitor = (*hData)[21].monitor;
  pNop = monitor;
  hPhysics = monitor->basic->hPhysics;
  pPhysics = hPhysics->pPhysics;
  if (!LODWORD(pPhysics->max_length))
    goto LABEL_14;
LABEL_8:
  v9 = pPhysics->m_Items[0];
  if (!v9->frame)
  {
    dds3Particle_NopBuffInit(&pNop, v3);
  }
  sub_854710(&monitor->basic->fields, 0);
  sub_854930(&v9->fields, 0);
  sub_854710(&monitor->basic->fields, 1u);
  sub_854930(&v9->fields, 1u);
  sub_854710(&monitor->basic->fields, 2u);
  sub_854930(&v9->fields, 2u);
  frame = v9->frame;
  v9->frame = frame + 1;
  monitor->basic->frame = frame + 2;
  color = monitor->basic->color;
  v14 = color->color;
  v16 = v14->m_Items[0] | (color->alpha << 24);
  v9->color = v16;
  abgr = monitor->basic->abgr;
  SDF_VU0__dds3ColorItoF(v16);
  SDF_VU0__COPYVECTOR_A_TO_B();
  SDF_VU0__dds3ColorItoF(abgr);
  SDF_VU0__MULVECTOR();
  v9->color = SDF_VU0__dds3ColorFtoI(128.0);
}

// 0x112b0d0
void dds3Particle_NopSetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  u64 *monitor;
  s64 v7;
  s64 v8;
  s64 v9;
  char *v10;
  s64 *v11;
  u64 v12[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v12);
    if ((v12[0] & 1) != 0)
      v10 = v12[2];
    else
      v10 = v12 + 1;
    v11 = sub_8C4940(v10);
  }
  monitor = (*hData)[21].monitor;
  if (monitor)
  {
    v7 = monitor[2] + 32LL;
    sub_854710(v7, 0);
    sub_854930(v7, 0);
    v8 = monitor[2] + 32LL;
    sub_854710(v8, 1u);
    sub_854930(v8, 1u);
    v9 = monitor[2] + 32LL;
    sub_854710(v9, 2u);
    sub_854930(v9, 2u);
  }
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
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3Particle_Radiate_t3_o *monitor;
  struct dds3Particle_Basic_t_o *basic;
  u64 v9;
  s32 v10;
  struct parPhysics_t_array *pPhysics;
  struct dds3Particle_Physics_t_o *hPhysics;
  parPhysics_t_o *v14;
  char *v15;
  s64 *v16;
  dds3Particle_Radiate_t3_o *v17[3];
  dds3Particle_Radiate_t3_o *pRadiate;

  pRadiate = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v17);
    if ((v17[0] & 1) != 0)
      v15 = v17[2];
    else
      v15 = v17 + 1;
    v16 = sub_8C4940(v15);
  }
  monitor = (*hData)[18].monitor;
  pRadiate = monitor;
  basic = monitor->basic;
  if (basic->number)
  {
    v9 = 0;
    v10 = 0;
    do
    {
      while (1)
      {
        hPhysics = basic->hPhysics;
        else
        {
          pPhysics = hPhysics->pPhysics;
          if (v9 >= LODWORD(pPhysics->max_length))
          {
LABEL_14:
          }
        }
        v14 = pPhysics->m_Items[v9];
        dds3Particle_RadiateBuffInit(&pRadiate, v9);
        v14->frame = v10;
        if (++v9 % monitor->split)
          break;
        v10 -= monitor->interval;
        basic = monitor->basic;
        if (v9 >= basic->number)
          return;
      }
      basic = monitor->basic;
    }
    while (v9 < basic->number);
  }
}

// 0x1124470
void dds3Particle_RadiateBuffInit(dds3Particle_Radiate_t3 **pRadiate, s32 number) {
  struct dds3Particle_Physics_t_o *hPhysics;
  struct parPhysics_t_array *pPhysics;
  parPhysics_t_o *v8;
  f32 x;
  f32 y;
  f32 z;
  f32 w;
  s64 split;
  f32 v21;
  f32 v22;
  struct dds3Particle_Basic_t_o *basic;
  f32 scl_r;
  f32 v26;
  f32 v27;
  f32 rot_r;
  f32 v31;
  dds3Particle_Effect_t_o **p_effect;
  f32 v33;
  UnityEngine_Vector4_o v38;
  UnityEngine_Vector4_o dds3CameraTargetPos;
  UnityEngine_Vector4_o v40;

  hPhysics = (*pRadiate)->basic->hPhysics;
  pPhysics = hPhysics->pPhysics;
  v8 = pPhysics->m_Items[number];
  x = dds3CameraEyePos.x;
  y = dds3CameraEyePos.y;
  z = dds3CameraEyePos.z;
  w = dds3CameraEyePos.w;
  v40.x = x;
  v40.y = y;
  v40.z = z;
  v40.w = w;
  *&v38.x = 0;
  LODWORD(v38.z) = number;
  v38.w = v33;
  LookAtMatrix(dds3CameraTargetPos, v40, v38);
  ReverseMatrix();
  if ((*pRadiate)->type)
  {
    sdfCos(NAN);
    sub_854930(&v8->dir, 0);
    sub_854930(&v8->dir, 1u);
    sdfSin(NAN);
    sub_854930(&v8->dir, 2u);
    sub_854930(&v8->val_f, 1u);
    sub_854710(&v8->dir, 0);
    sub_854930(&v8->fields, 0);
    sub_854710(&v8->dir, 1u);
    sub_854930(&v8->fields, 1u);
    sub_854710(&v8->dir, 2u);
    sub_854930(&v8->fields, 2u);
    *&v8->frame = 0;
  }
  else
  {
    SDF_VU0__COPYVECTOR(&v8->pos, (*pRadiate)->basic->pos, 0);
    split = (*pRadiate)->split;
    v21 = split;
    v22 = (6.2832 / v21) * (number % split);
    sdfCos(v22);
    sub_854930(&v8->dir, 0);
    sdfSin(v22);
    sub_854930(&v8->dir, 1u);
    sub_854930(&v8->dir, 2u);
    SDF_VU0__LOADVECTOR(v8->dir);
    SDF_VU0__APPLYMATRIX_XYZ();
    SDF_VU0__STOREVECTOR(&v8->dir);
    *&v8->frame = 0;
    sub_854930(&v8->val_f, 1u);
  }
  basic = (*pRadiate)->basic;
  scl_r = basic->exp->scl_r;
  sub_854710(&basic->scale, 0);
  v27 = v26;
  v8->scale = v27 * DDS3EFFECT_RAND_FA(scl_r);
  rot_r = (*pRadiate)->basic->exp->rot_r;
  if (rot_r == 0.0)
  {
    v31 = 0.0;
  }
  else
  {
    v31 = DDS3EFFECT_RAND_FA(rot_r) * 6.2832;
  }
  v8->rot = v31;
  p_effect = &(*pRadiate)->basic->effect;
  dds3Particle_EffectReset(p_effect, number);
}

// 0x1124a60
dds3Particle_Basic_t *dds3Particle_RadiateCreate(void *hData, s32 bPos, bool pCopy, s32 billno) {
  u64 *v8;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  dds3Particle_Radiate_t3_o *pRadiate;
  Il2CppClass *v16;
  s64 *Interface;
  char *v18;
  s64 *v19;
  dds3Particle_Basic_t_o *dst;
  Il2CppObject *hDataa;
  u64 v24[2];
  char *v25;
  s32 bpos;

  bpos = bPos;
  dst = 0;
  hDataa = 0;
  if (pCopy)
  {
    v8 = Allocate(dds3Particle_Basic_t);
    dds3Particle_Basic_t___ctor(v8);
    dst = v8;
    if (hData)
    {
      klass = hData->klass;
      if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v24);
        if ((v24[0] & 1) != 0)
          v11 = v25;
        else
          v11 = v24 + 1;
        v12 = sub_8C4940(v11);
      }
    }
    dds3Particle_Basic_t__dCopy(hData, &dst);
    pRadiate = dst->pRadiate;
  }
  else
  {
    pRadiate = Allocate(dds3Particle_Radiate_t3);
    dds3Particle_Radiate_t3___ctor(pRadiate);
    if (hData)
    {
      Interface = QueryInterface(hData, byte);
      if (!Interface)
      {
        sub_8FC2C0(hData->klass->_1.element_class, v16, v24);
        if ((v24[0] & 1) != 0)
          v18 = v25;
        else
          v18 = v24 + 1;
        v19 = sub_8C4940(v18);
      }
    }
    else
    {
      Interface = 0;
    }
    dds3Particle_Radiate_t3__pCopy(pRadiate, Interface, &bpos);
    if (billno == -1)
      pRadiate->basic->billno = -1;
  }
  dds3Particle_BasicCreate(&pRadiate->basic, pCopy);
  dst = pRadiate->basic;
  hDataa = dst;
  dst->pRadiate = pRadiate;
  dds3Particle_RadiateAllBuffInit(&hDataa);
  return dst;
}

// 0x1124cb0
void dds3Particle_RadiateDelete(void **hData) {
  dds3Particle_Basic_t_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3Particle_Basic_t_o *v6;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  v6 = *((*hData)[18].monitor + 2);
  dds3Particle_BasicDelete(v6, v3);
}

// 0x1124dc0
void dds3Particle_RadiateDraw(void **hData) {
  dds3Particle_Basic_t_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3Particle_Radiate_t3_o *monitor;
  struct dds3Particle_Basic_t_o *basic;
  dds3Particle_Effect_t_o *effect;
  s32 type;
  f32 eff_scl_raito;
  s64 v11;
  f32 x;
  f32 y;
  f32 z;
  f32 w;
  s64 v22;
  struct dds3Particle_Basic_t_o *v25;
  s64 v26;
  s32 frame;
  u64 v28;
  struct dds3Particle_Physics_t_o *hPhysics;
  struct parPhysics_t_array *pPhysics;
  parPhysics_t_o *v33;
  s32 v34;
  dds3ParticleColorAnim_t_o *color;
  u32 v36;
  u32 abgr;
  f32 v39;
  f32 v40;
  dds3Particle_Effect_t_o **p_effect;
  f32 scale;
  u32 v45;
  s32 v46;
  dds3Particle_Effect_t_o **v47;
  char *v48;
  s64 *v49;
  s64 number;
  s32 v54;
  s32 loop;
  dds3Particle_Radiate_t3_o *pRadiate;
  u64 v58[3];
  UnityEngine_Vector4_o v59;
  UnityEngine_Vector4_o dds3CameraTargetPos;
  UnityEngine_Vector4_o v61;

  pRadiate = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v58);
    if ((v58[0] & 1) != 0)
      v48 = v58[2];
    else
      v48 = v58 + 1;
    v49 = sub_8C4940(v48);
  }
  monitor = (*hData)[18].monitor;
  pRadiate = monitor;
  basic = monitor->basic;
  effect = basic->effect;
  type = effect->type;
  eff_scl_raito = basic->eff_scl_raito;
  dds3Particle_EffectInit(effect, eff_scl_raito, v3);
  x = dds3CameraEyePos.x;
  y = dds3CameraEyePos.y;
  z = dds3CameraEyePos.z;
  w = dds3CameraEyePos.w;
  v61.x = x;
  v61.y = y;
  v61.z = z;
  v61.w = w;
  *&v59.x = 0;
  *&v59.z = v11;
  LookAtMatrix(dds3CameraTargetPos, v61, v59);
  ReverseMatrix();
  v25 = monitor->basic;
  number = v25->number;
  if (v25->number >= 1)
  {
    v54 = 0;
    loop = monitor->loop;
    v26 = number - 1;
    frame = v25->frame;
    v28 = 0;
    hPhysics = v25->hPhysics;
      goto LABEL_18;
LABEL_19:
    pPhysics = hPhysics->pPhysics;
    if (v28 >= LODWORD(pPhysics->max_length))
    {
LABEL_20:
    }
    while (1)
    {
      v33 = pPhysics->m_Items[v28];
      v34 = v33->frame;
      if ((v34 & 0x80000000) == 0)
      {
        color = monitor->basic->color;
        v36 = dds3ParticleColorAnim(color, v22, v34);
        v33->color = v36;
        abgr = monitor->basic->abgr;
        SDF_VU0__dds3ColorItoF(v36);
        SDF_VU0__COPYVECTOR_A_TO_B();
        SDF_VU0__dds3ColorItoF(abgr);
        SDF_VU0__MULVECTOR();
        v33->color = SDF_VU0__dds3ColorFtoI(128.0);
        if (type)
          SDF_VU0__LOADVECTOR_C(v33->pos);
        sub_854710(&v33->fields, 0);
        sub_854710(&v33->dir, 0);
        sub_854930(&v33->fields, 0);
        sub_854710(&v33->fields, 1u);
        sub_854710(&v33->dir, 1u);
        sub_854930(&v33->fields, 1u);
        sub_854710(&v33->fields, 2u);
        sub_854710(&v33->dir, 2u);
        sub_854930(&v33->fields, 2u);
        sub_854710(&v33->val_f, 1u);
        v40 = v39;
        sdfCos(v40);
        sub_854930(&v33->dir, 0);
        sdfSin(v40);
        sub_854930(&v33->dir, 1u);
        sub_854930(&v33->dir, 2u);
        SDF_VU0__LOADVECTOR(v33->dir);
        SDF_VU0__APPLYMATRIX_XYZ();
        SDF_VU0__STOREVECTOR(&v33->dir);
        sub_854710(&v33->val_f, 1u);
        sub_854930(&v33->val_f, 1u);
        if (type)
        {
          SDF_VU0__LOADVECTOR(v33->pos);
          p_effect = &monitor->basic->effect;
          scale = v33->scale;
          v45 = v33->color;
          dds3Particle_EffectSet(p_effect, v28, v45, scale);
        }
      }
      v46 = v34 + 1;
      if (v34 + 1 < frame)
        goto LABEL_49;
      if (!loop)
        break;
      dds3Particle_RadiateBuffInit(&pRadiate, v28);
      v33->frame = v33->frame;
      if (v26 == v28)
        return;
LABEL_17:
      ++v28;
      hPhysics = monitor->basic->hPhysics;
        goto LABEL_19;
LABEL_18:
        goto LABEL_19;
      pPhysics = hPhysics->pPhysics;
      if (v28 >= LODWORD(pPhysics->max_length))
        goto LABEL_20;
    }
    v47 = &monitor->basic->effect;
    dds3Particle_EffectReset(v47, v28);
    if (++v54 >= number)
      monitor->basic->state = 0;
LABEL_49:
    v33->frame = v46;
    if (v26 == v28)
      return;
    goto LABEL_17;
  }
}

// 0x11248d0
void dds3Particle_RadiateSetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  f32 *monitor;
  s64 v8;
  s64 v9;
  s64 v10;
  char *v11;
  s64 *v12;
  u64 v13[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v13);
    if ((v13[0] & 1) != 0)
      v11 = v13[2];
    else
      v11 = v13 + 1;
    v12 = sub_8C4940(v11);
  }
  monitor = (*hData)[18].monitor;
  if (monitor)
  {
    v8 = *(monitor + 2) + 32LL;
    sub_854710(v8, 0);
    sub_854930(v8, 0);
    v9 = *(monitor + 2) + 32LL;
    sub_854710(v9, 1u);
    sub_854930(v9, 1u);
    v10 = *(monitor + 2) + 32LL;
    sub_854710(v10, 2u);
    sub_854930(v10, 2u);
    monitor[11] = monitor[11] * scale;
  }
}

// 0x11211d0
void dds3Particle_SmokeAllBuffInit(void **hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  u64 *monitor;
  s64 v7;
  u64 v8;
  s64 v9;
  s64 v10;
  s64 v12;
  char *v13;
  s64 *v14;
  u64 v15[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v15);
    if ((v15[0] & 1) != 0)
      v13 = v15[2];
    else
      v13 = v15 + 1;
    v14 = sub_8C4940(v13);
  }
  monitor = (*hData)[17].monitor;
  v7 = monitor[2];
  if (*(v7 + 48))
  {
    v8 = 0;
    do
    {
      v10 = *(v7 + 184);
      else
      {
        v9 = *(v10 + 24);
        if (v8 >= *(v9 + 24))
        {
LABEL_12:
        }
      }
      v12 = v9 + 8 * v8++;
      *(*(v12 + 32) + 48LL) = -268435455;
      v7 = monitor[2];
    }
    while (v8 < *(v7 + 48));
  }
}

// 0x1121870
void dds3Particle_SmokeBuffInit(dds3Particle_Smoke_t3 **pSmoke, s32 number) {
  struct dds3Particle_Physics_t_o *hPhysics;
  struct parPhysics_t_array *pPhysics;
  parPhysics_t_o *v8;
  f32 v9;
  struct dds3Particle_Basic_t_o *basic;
  s64 v11;
  s64 v12;
  s64 v13;
  s64 v14;
  s64 v15;
  s64 v16;
  s64 v17;
  u32 Rand;
  s64 v20;
  struct dds3Particle_Basic_t_o *v21;
  f32 scl_r;
  f32 v23;
  f32 rot_r;
  dds3Particle_Effect_t_o **p_effect;
  UnityEngine_Matrix4x4_o v28;
  UnityEngine_Vector4_o p;

  *&p.x = 0;
  *&p.z = 0;
  hPhysics = (*pSmoke)->basic->hPhysics;
  pPhysics = hPhysics->pPhysics;
  v8 = pPhysics->m_Items[number];
  DDS3EFFECT_RAND_PM();
  DDS3EFFECT_RAND_PM();
  sub_854930(&p, 0);
  v9 = 0.0;
  sub_854930(&p, 1u);
  DDS3EFFECT_RAND_PM();
  sub_854930(&p, 2u);
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&p);
  sub_854710(&p, 0);
  sub_854930(&v8->fields, 0);
  sub_854930(&v8->fields, 1u);
  sub_854710(&p, 2u);
  sub_854930(&v8->fields, 2u);
  basic = (*pSmoke)->basic;
  v11 = *&basic->rot.m00;
  v12 = *&basic->rot.m20;
  v13 = *&basic->rot.m21;
  *&v28.m01 = *&basic->rot.m01;
  *&v28.m21 = v13;
  *&v28.m00 = v11;
  *&v28.m20 = v12;
  v14 = *&basic->rot.m02;
  v15 = *&basic->rot.m22;
  v17 = *&basic->rot.m03;
  v16 = *&basic->rot.m23;
  *&v28.m03 = v17;
  *&v28.m23 = v16;
  *&v28.m02 = v14;
  *&v28.m22 = v15;
  SDF_VU0__LOADMATRIX(&v28);
  SDF_VU0__LOADVECTOR(v8->pos);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__STOREVECTOR(&v8->pos);
  sub_854710(&v8->fields, 0);
  sub_854710(&(*pSmoke)->basic->fields, 0);
  sub_854930(&v8->fields, 0);
  sub_854710(&v8->fields, 1u);
  sub_854710(&(*pSmoke)->basic->fields, 1u);
  sub_854930(&v8->fields, 1u);
  sub_854710(&v8->fields, 2u);
  sub_854710(&(*pSmoke)->basic->fields, 2u);
  sub_854930(&v8->fields, 2u);
  DDS3EFFECT_RAND_PM();
  sub_854930(&p, 0);
  sub_854930(&p, 1u);
  DDS3EFFECT_RAND_PM();
  sub_854930(&p, 2u);
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v8->dir);
  DDS3EFFECT_RAND_FA((*pSmoke)->ampli_r, 0);
  sub_854930(&v8->val_f, 0);
  sub_854930(&v8->val_f, 1u);
  sub_854930(&v8->val_f, 2u);
  DDS3EFFECT_RAND_FA((*pSmoke)->up_s_r, 0);
  sub_854930(&v8->val_f, 3u);
  Rand = sdfGetRand(&ParRand);
  v20 = (*pSmoke)->timing + 1LL;
  v8->frame = Rand / v20 * v20 - Rand;
  v8->color = 0;
  v21 = (*pSmoke)->basic;
  scl_r = v21->exp->scl_r;
  sub_854710(&v21->scale, 0);
  v8->scale = v23 * DDS3EFFECT_RAND_FA(scl_r);
  rot_r = (*pSmoke)->basic->exp->rot_r;
  if (rot_r != 0.0)
  {
    v9 = DDS3EFFECT_RAND_FA(rot_r) * 6.2832;
  }
  v8->rot = v9;
  p_effect = &(*pSmoke)->basic->effect;
  dds3Particle_EffectReset(p_effect, number);
}

// 0x1121500
dds3Particle_Basic_t *dds3Particle_SmokeCreate(void *hData, s32 bPos, bool pCopy, s32 billno) {
  u64 *v8;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  dds3Particle_Smoke_t3_o *pSmoke;
  Il2CppClass *v16;
  s64 *Interface;
  char *v18;
  s64 *v19;
  dds3Particle_Basic_t_o *dst;
  Il2CppObject *hDataa;
  u64 v24[2];
  char *v25;
  s32 bpos;

  bpos = bPos;
  dst = 0;
  hDataa = 0;
  if (pCopy)
  {
    v8 = Allocate(dds3Particle_Basic_t);
    dds3Particle_Basic_t___ctor(v8);
    dst = v8;
    if (hData)
    {
      klass = hData->klass;
      if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v24);
        if ((v24[0] & 1) != 0)
          v11 = v25;
        else
          v11 = v24 + 1;
        v12 = sub_8C4940(v11);
      }
    }
    dds3Particle_Basic_t__dCopy(hData, &dst);
    pSmoke = dst->pSmoke;
  }
  else
  {
    pSmoke = Allocate(dds3Particle_Smoke_t3);
    dds3Particle_Smoke_t3___ctor(pSmoke);
    if (hData)
    {
      Interface = QueryInterface(hData, byte);
      if (!Interface)
      {
        sub_8FC2C0(hData->klass->_1.element_class, v16, v24);
        if ((v24[0] & 1) != 0)
          v18 = v25;
        else
          v18 = v24 + 1;
        v19 = sub_8C4940(v18);
      }
    }
    else
    {
      Interface = 0;
    }
    dds3Particle_Smoke_t3__pCopy(pSmoke, Interface, &bpos);
    if (billno == -1)
      pSmoke->basic->billno = -1;
  }
  dds3Particle_BasicCreate(&pSmoke->basic, pCopy);
  dst = pSmoke->basic;
  hDataa = dst;
  dst->pSmoke = pSmoke;
  dds3Particle_SmokeAllBuffInit(&hDataa);
  return dst;
}

// 0x1121750
void dds3Particle_SmokeDelete(void **hData) {
  dds3Particle_Basic_t_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  void *monitor;
  dds3Particle_Basic_t_o *v7;
  char *v8;
  s64 *v9;
  u64 v10[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v10);
    if ((v10[0] & 1) != 0)
      v8 = v10[2];
    else
      v8 = v10 + 1;
    v9 = sub_8C4940(v8);
  }
  monitor = (*hData)[17].monitor;
  if (monitor)
  {
    v7 = *(monitor + 2);
    dds3Particle_BasicDelete(v7, v3);
  }
}

// 0x1121d40
void dds3Particle_SmokeDraw(void **hData) {
  dds3Particle_Basic_t_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3Particle_Smoke_t3_o *monitor;
  struct dds3Particle_Basic_t_o *basic;
  dds3Particle_Effect_t_o *effect;
  s32 type;
  f32 eff_scl_raito;
  struct dds3Particle_Basic_t_o *v11;
  s64 v12;
  s64 v13;
  s64 v14;
  s64 v15;
  s64 v16;
  s64 v17;
  s64 v18;
  s64 v19;
  struct dds3Particle_Basic_t_o *v22;
  s64 v23;
  u64 v24;
  s32 v25;
  struct dds3Particle_Physics_t_o *hPhysics;
  struct parPhysics_t_array *pPhysics;
  parPhysics_t_o *v30;
  s32 v31;
  dds3ParticleColorAnim_t_o *color;
  u32 v33;
  u32 abgr;
  f32 v36;
  f32 v37;
  dds3Particle_Effect_t_o **p_effect;
  f32 scale;
  u32 v42;
  s32 v43;
  s32 v44;
  dds3Particle_Effect_t_o **v46;
  char *v47;
  s64 *v48;
  s64 number;
  s32 loop;
  s32 frame;
  UnityEngine_Matrix4x4_o v52;
  UnityEngine_Vector4_o p;
  dds3Particle_Smoke_t3_o *v54[4];
  dds3Particle_Smoke_t3_o *pSmoke;

  pSmoke = 0;
  *&p.x = 0;
  *&p.z = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v54);
    if ((v54[0] & 1) != 0)
      v47 = v54[2];
    else
      v47 = v54 + 1;
    v48 = sub_8C4940(v47);
  }
  monitor = (*hData)[17].monitor;
  pSmoke = monitor;
  *&p.x = 0;
  *&p.z = 0;
  basic = monitor->basic;
  effect = basic->effect;
  type = effect->type;
  eff_scl_raito = basic->eff_scl_raito;
  dds3Particle_EffectInit(effect, eff_scl_raito, v3);
  v11 = monitor->basic;
  v12 = *&v11->rot.m00;
  v13 = *&v11->rot.m20;
  v14 = *&v11->rot.m21;
  *&v52.m01 = *&v11->rot.m01;
  *&v52.m21 = v14;
  *&v52.m00 = v12;
  *&v52.m20 = v13;
  v15 = *&v11->rot.m02;
  v16 = *&v11->rot.m22;
  v18 = *&v11->rot.m03;
  v17 = *&v11->rot.m23;
  *&v52.m03 = v18;
  *&v52.m23 = v17;
  *&v52.m02 = v15;
  *&v52.m22 = v16;
  SDF_VU0__LOADMATRIX(&v52);
  v22 = monitor->basic;
  number = v22->number;
  if (v22->number >= 1)
  {
    frame = v22->frame;
    loop = monitor->loop;
    v23 = number - 1;
    v24 = 0;
    v25 = 0;
    hPhysics = v22->hPhysics;
      goto LABEL_12;
    while (1)
    {
LABEL_13:
      pPhysics = hPhysics->pPhysics;
      if (v24 >= LODWORD(pPhysics->max_length))
      {
LABEL_14:
      }
      while (1)
      {
        v30 = pPhysics->m_Items[v24];
        v31 = v30->frame;
        if (v31 == -268435455)
        {
          dds3Particle_SmokeBuffInit(&pSmoke, v24);
          v31 = v30->frame;
        }
        if ((v31 & 0x80000000) == 0)
        {
          color = monitor->basic->color;
          v33 = dds3ParticleColorAnim(color, v19, v31);
          v30->color = v33;
          abgr = monitor->basic->abgr;
          SDF_VU0__dds3ColorItoF(v33);
          SDF_VU0__COPYVECTOR_A_TO_B();
          SDF_VU0__dds3ColorItoF(abgr);
          SDF_VU0__MULVECTOR();
          v30->color = SDF_VU0__dds3ColorFtoI(128.0);
          if (type)
            SDF_VU0__LOADVECTOR_C(v30->pos);
          sub_854710(&v30->val_f, 0);
          sub_854930(&v30->val_f, 0);
          sub_854710(&v30->val_f, 1u);
          sub_854930(&v30->val_f, 1u);
          sub_854710(&v30->val_f, 3u);
          sub_854710(&v30->val_f, 1u);
          v37 = v36;
          sdfSin(v37);
          sub_854710(&v30->val_f, 2u);
          sub_854930(&v30->val_f, 2u);
          sub_854710(&v30->val_f, 0);
          sub_854710(&v30->dir, 0);
          sub_854930(&p, 0);
          sub_854930(&p, 1u);
          sub_854710(&v30->dir, 2u);
          sub_854930(&p, 2u);
          SDF_VU0__LOADVECTOR(p);
          SDF_VU0__APPLYMATRIX();
          SDF_VU0__STOREVECTOR(&p);
          sub_854710(&v30->fields, 0);
          sub_854710(&p, 0);
          sub_854930(&v30->fields, 0);
          sub_854710(&v30->fields, 1u);
          sub_854710(&p, 1u);
          sub_854930(&v30->fields, 1u);
          sub_854710(&v30->fields, 2u);
          sub_854710(&p, 2u);
          sub_854930(&v30->fields, 2u);
          sub_854930(&v30->val_f, 3u);
          if (type)
          {
            SDF_VU0__LOADVECTOR(v30->pos);
            p_effect = &monitor->basic->effect;
            scale = v30->scale;
            v42 = v30->color;
            dds3Particle_EffectSet(p_effect, v24, v42, scale);
          }
        }
        v43 = v31 + 1;
        v44 = v31 + 1 < frame ? v31 + 1 : -268435455;
        if (v43 >= frame && loop == 0)
        {
          v46 = &monitor->basic->effect;
          dds3Particle_EffectReset(v46, v24);
          if (++v25 >= number)
            monitor->basic->state = 0;
          v30->frame = v43;
          if (v23 == v24)
            return;
        }
        else
        {
          v30->frame = v44;
          if (v23 == v24)
            return;
        }
        ++v24;
        hPhysics = monitor->basic->hPhysics;
          goto LABEL_13;
LABEL_12:
          break;
        pPhysics = hPhysics->pPhysics;
        if (v24 >= LODWORD(pPhysics->max_length))
          goto LABEL_14;
      }
    }
  }
}

// 0x112d5d0
void dds3Particle_SmokeOffsetAllBuffInit(void **hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  u64 *monitor;
  s64 v7;
  u64 v8;
  s64 v9;
  s64 v10;
  s64 v12;
  char *v13;
  s64 *v14;
  u64 v15[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v15);
    if ((v15[0] & 1) != 0)
      v13 = v15[2];
    else
      v13 = v15 + 1;
    v14 = sub_8C4940(v13);
  }
  monitor = (*hData)[22].monitor;
  v7 = monitor[2];
  if (*(v7 + 48))
  {
    v8 = 0;
    do
    {
      v10 = *(v7 + 184);
      else
      {
        v9 = *(v10 + 24);
        if (v8 >= *(v9 + 24))
        {
LABEL_12:
        }
      }
      v12 = v9 + 8 * v8++;
      *(*(v12 + 32) + 48LL) = -268435455;
      v7 = monitor[2];
    }
    while (v8 < *(v7 + 48));
  }
}

// 0x112dc80
void dds3Particle_SmokeOffsetBuffInit(dds3Particle_SmokeOffset_t3 **pSmokeOffset, s32 number) {
  struct dds3Particle_Physics_t_o *hPhysics;
  struct parPhysics_t_array *pPhysics;
  parPhysics_t_o *v8;
  struct UnityEngine_Vector4_array *pOffset;
  Il2CppObject *v11;
  Il2CppClass *klass;
  f32 v13;
  f32 v14;
  struct dds3Particle_Basic_t_o *basic;
  s64 v16;
  s64 v17;
  s64 v18;
  s64 v19;
  s64 v20;
  s64 v21;
  s64 v22;
  u32 Rand;
  s64 v25;
  struct dds3Particle_Basic_t_o *v26;
  f32 scl_r;
  f32 v28;
  f32 rot_r;
  dds3Particle_Effect_t_o **p_effect;
  struct UnityEngine_Vector4_array *v33;
  f32 y;
  f32 w;
  f32 z;
  f32 *v38;
  UnityEngine_Matrix4x4_o v39;
  UnityEngine_Vector4_o v40;
  UnityEngine_Vector4_o p;

  *&v40.x = 0;
  *&v40.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  hPhysics = (*pSmokeOffset)->basic->hPhysics;
  pPhysics = hPhysics->pPhysics;
  v8 = pPhysics->m_Items[number];
  pOffset = (*pSmokeOffset)->pOffset;
  v11 = &pOffset->obj + number;
  klass = v11[2].klass;
  v13 = *&v11[2].monitor;
  LODWORD(v11) = HIDWORD(v11[2].monitor);
  *&v40.x = klass;
  v40.z = v13;
  LODWORD(v40.w) = v11;
  DDS3EFFECT_RAND_PM();
  DDS3EFFECT_RAND_PM();
  sub_854930(&p, 0);
  v14 = 0.0;
  sub_854930(&p, 1u);
  DDS3EFFECT_RAND_PM();
  sub_854930(&p, 2u);
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&p);
  sub_854710(&p, 0);
  sub_854930(&v40, 0);
  sub_854930(&v40, 1u);
  sub_854710(&p, 2u);
  sub_854930(&v40, 2u);
  basic = (*pSmokeOffset)->basic;
  v16 = *&basic->rot.m00;
  v17 = *&basic->rot.m20;
  v18 = *&basic->rot.m21;
  *&v39.m01 = *&basic->rot.m01;
  *&v39.m21 = v18;
  *&v39.m00 = v16;
  *&v39.m20 = v17;
  v19 = *&basic->rot.m02;
  v20 = *&basic->rot.m22;
  v22 = *&basic->rot.m03;
  v21 = *&basic->rot.m23;
  *&v39.m03 = v22;
  *&v39.m23 = v21;
  *&v39.m02 = v19;
  *&v39.m22 = v20;
  SDF_VU0__LOADMATRIX(&v39);
  SDF_VU0__LOADVECTOR(v40);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__STOREVECTOR(&v40);
  DDS3EFFECT_RAND_PM();
  sub_854930(&p, 0);
  sub_854930(&p, 1u);
  DDS3EFFECT_RAND_PM();
  sub_854930(&p, 2u);
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v8->dir);
  DDS3EFFECT_RAND_FA((*pSmokeOffset)->ampli_r, 0);
  sub_854930(&v8->val_f, 0);
  sub_854930(&v8->val_f, 1u);
  sub_854930(&v8->val_f, 2u);
  DDS3EFFECT_RAND_FA((*pSmokeOffset)->up_s_r, 0);
  sub_854930(&v8->val_f, 3u);
  Rand = sdfGetRand(&ParRand);
  v25 = (*pSmokeOffset)->timing + 1LL;
  v8->frame = Rand / v25 * v25 - Rand;
  v8->color = 0;
  SDF_VU0__COPYVECTOR(&v8->pos, (*pSmokeOffset)->basic->pos, 0);
  v26 = (*pSmokeOffset)->basic;
  scl_r = v26->exp->scl_r;
  sub_854710(&v26->scale, 0);
  v8->scale = v28 * DDS3EFFECT_RAND_FA(scl_r);
  rot_r = (*pSmokeOffset)->basic->exp->rot_r;
  if (rot_r != 0.0)
  {
    v14 = DDS3EFFECT_RAND_FA(rot_r) * 6.2832;
  }
  v8->rot = v14;
  p_effect = &(*pSmokeOffset)->basic->effect;
  dds3Particle_EffectReset(p_effect, number);
  v33 = (*pSmokeOffset)->pOffset;
  y = v40.y;
  z = v40.z;
  w = v40.w;
  v38 = (&v33->obj + number);
  v38[8] = v40.x;
  v38[9] = y;
  v38[10] = z;
  v38[11] = w;
}

// 0x112d900
dds3Particle_Basic_t *dds3Particle_SmokeOffsetCreate(void *hData, s32 bPos, bool pCopy, s32 billno) {
  u64 *v8;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  dds3Particle_SmokeOffset_t3_o *pSmokeOffset;
  Il2CppClass *v14;
  s64 *Interface;
  char *v16;
  s64 *v17;
  dds3Particle_Basic_t_o *dst;
  Il2CppObject *hDataa;
  u64 v24[2];
  char *v25;
  s32 bpos;

  bpos = bPos;
  dst = 0;
  hDataa = 0;
  if (pCopy)
  {
    v8 = Allocate(dds3Particle_Basic_t);
    dds3Particle_Basic_t___ctor(v8);
    dst = v8;
    if (hData)
    {
      klass = hData->klass;
      if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v24);
        if ((v24[0] & 1) != 0)
          v11 = v25;
        else
          v11 = v24 + 1;
        v12 = sub_8C4940(v11);
      }
    }
    dds3Particle_Basic_t__dCopy(hData, &dst);
    pSmokeOffset = dst->pSmokeOffset;
  }
  else
  {
    pSmokeOffset = Allocate(dds3Particle_SmokeOffset_t3);
    dds3Particle_SmokeOffset_t3___ctor(pSmokeOffset);
    if (hData)
    {
      Interface = QueryInterface(hData, byte);
      if (!Interface)
      {
        sub_8FC2C0(hData->klass->_1.element_class, v14, v24);
        if ((v24[0] & 1) != 0)
          v16 = v25;
        else
          v16 = v24 + 1;
        v17 = sub_8C4940(v16);
      }
    }
    else
    {
      Interface = 0;
    }
    dds3Particle_SmokeOffset_t3__pCopy(pSmokeOffset, Interface, &bpos);
    if (billno == -1)
      pSmokeOffset->basic->billno = -1;
  }
  pSmokeOffset->pOffset = NewSpecific(
                                   UnityEngine_Vector4,
                                   pSmokeOffset->basic->number);
  dds3Particle_BasicCreate(&pSmokeOffset->basic, pCopy);
  dst = pSmokeOffset->basic;
  hDataa = dst;
  dst->pSmokeOffset = pSmokeOffset;
  dds3Particle_SmokeOffsetAllBuffInit(&hDataa);
  return dst;
}

// 0x112db70
void dds3Particle_SmokeOffsetDelete(void **hData) {
  dds3Particle_Basic_t_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3Particle_Basic_t_o *v6;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  v6 = *((*hData)[22].monitor + 2);
  dds3Particle_BasicDelete(v6, v3);
}

// 0x112e120
void dds3Particle_SmokeOffsetDraw(void **hData) {
  dds3Particle_Basic_t_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3Particle_SmokeOffset_t3_o *monitor;
  struct dds3Particle_Basic_t_o *basic;
  dds3Particle_Effect_t_o *effect;
  f32 eff_scl_raito;
  struct dds3Particle_Basic_t_o *v10;
  s64 v11;
  s64 v12;
  s64 v13;
  s64 v14;
  s64 v15;
  s64 v16;
  s64 v17;
  struct dds3Particle_Basic_t_o *v18;
  s64 number;
  s64 v20;
  u64 v23;
  s64 v24;
  struct parPhysics_t_array *pPhysics;
  struct dds3Particle_Physics_t_o *hPhysics;
  struct UnityEngine_Vector4_array *pOffset;
  parPhysics_t_o *v30;
  f32 v32;
  f32 v33;
  s32 v34;
  struct UnityEngine_Vector4_array *v35;
  f32 v37;
  f32 v38;
  dds3ParticleColorAnim_t_o *color;
  u32 v40;
  u32 abgr;
  f32 v43;
  f32 v44;
  dds3Particle_Effect_t_o **p_effect;
  f32 scale;
  u32 v49;
  s32 v50;
  s32 v51;
  dds3Particle_Effect_t_o **v53;
  struct dds3Particle_Basic_t_o *v54;
  u32 *v55;
  struct UnityEngine_Vector4_array *v57;
  f32 y;
  f32 w;
  f32 z;
  f32 *v62;
  char *v63;
  s64 *v64;
  s32 v65;
  s32 loop;
  s32 frame;
  s32 type;
  UnityEngine_Matrix4x4_o v69;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o v72;
  dds3Particle_SmokeOffset_t3_o *v73[4];
  dds3Particle_SmokeOffset_t3_o *pSmokeOffset;

  pSmokeOffset = 0;
  *&v72.x = 0;
  *&v72.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v73);
    if ((v73[0] & 1) != 0)
      v63 = v73[2];
    else
      v63 = v73 + 1;
    v64 = sub_8C4940(v63);
  }
  monitor = (*hData)[22].monitor;
  pSmokeOffset = monitor;
  *&v72.x = 0;
  *&v72.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  basic = monitor->basic;
  effect = basic->effect;
  type = effect->type;
  eff_scl_raito = basic->eff_scl_raito;
  dds3Particle_EffectInit(effect, eff_scl_raito, v3);
  v10 = monitor->basic;
  v11 = *&v10->rot.m00;
  v12 = *&v10->rot.m20;
  v13 = *&v10->rot.m21;
  *&v69.m01 = *&v10->rot.m01;
  *&v69.m21 = v13;
  *&v69.m00 = v11;
  *&v69.m20 = v12;
  v14 = *&v10->rot.m02;
  v15 = *&v10->rot.m22;
  v17 = *&v10->rot.m03;
  v16 = *&v10->rot.m23;
  *&v69.m03 = v17;
  *&v69.m23 = v16;
  *&v69.m02 = v14;
  *&v69.m22 = v15;
  SDF_VU0__LOADMATRIX(&v69);
  v18 = monitor->basic;
  frame = v18->frame;
  loop = monitor->loop;
  number = v18->number;
  SDF_VU0__COPYVECTOR(&dst, v18->pos);
  if (number >= 1)
  {
    v23 = 0;
    v24 = 32;
    v65 = 0;
    do
    {
      hPhysics = monitor->basic->hPhysics;
      else
      {
        pPhysics = hPhysics->pPhysics;
        if (v23 >= LODWORD(pPhysics->max_length))
        {
LABEL_16:
        }
      }
      pOffset = monitor->pOffset;
      v30 = pPhysics->m_Items[v23];
      v33 = *(&pOffset->obj.monitor + v24);
      v32 = *(&pOffset->obj.monitor + v24 + 4);
      *&p.x = *(&pOffset->obj.klass + v24);
      p.z = v33;
      p.w = v32;
      v34 = v30->frame;
      if (v34 == -268435455)
      {
        dds3Particle_SmokeOffsetBuffInit(&pSmokeOffset, v23);
        v35 = monitor->pOffset;
        v38 = *(&v35->obj.monitor + v24);
        v37 = *(&v35->obj.monitor + v24 + 4);
        *&p.x = *(&v35->obj.klass + v24);
        p.z = v38;
        p.w = v37;
        v34 = v30->frame;
      }
      if ((v34 & 0x80000000) == 0)
      {
        color = monitor->basic->color;
        v40 = dds3ParticleColorAnim(color, v20, v34);
        v30->color = v40;
        abgr = monitor->basic->abgr;
        SDF_VU0__dds3ColorItoF(v40);
        SDF_VU0__COPYVECTOR_A_TO_B();
        SDF_VU0__dds3ColorItoF(abgr);
        SDF_VU0__MULVECTOR();
        v30->color = SDF_VU0__dds3ColorFtoI(128.0);
        if (type)
          SDF_VU0__LOADVECTOR_C(v30->pos);
        sub_854710(&v30->val_f, 0);
        sub_854930(&v30->val_f, 0);
        sub_854710(&v30->val_f, 1u);
        sub_854930(&v30->val_f, 1u);
        sub_854710(&v30->val_f, 3u);
        sub_854710(&v30->val_f, 1u);
        v44 = v43;
        sdfSin(v44);
        sub_854710(&v30->val_f, 2u);
        sub_854930(&v30->val_f, 2u);
        sub_854710(&v30->val_f, 0);
        sub_854710(&p, 0);
        sub_854710(&v30->dir, 0);
        sub_854930(&v72, 0);
        sub_854710(&p, 1u);
        sub_854930(&v72, 1u);
        sub_854710(&p, 2u);
        sub_854710(&v30->dir, 2u);
        sub_854930(&v72, 2u);
        SDF_VU0__LOADVECTOR(v72);
        SDF_VU0__STOREVECTOR(&p);
        SDF_VU0__APPLYMATRIX();
        SDF_VU0__LOADVECTOR_B(dst);
        SDF_VU0__ADDVECTOR();
        SDF_VU0__STOREVECTOR(&v30->pos);
        sub_854930(&v30->val_f, 3u);
        if (type)
        {
          SDF_VU0__LOADVECTOR(v30->pos);
          p_effect = &monitor->basic->effect;
          scale = v30->scale;
          v49 = v30->color;
          dds3Particle_EffectSet(p_effect, v23, v49, scale);
        }
      }
      v50 = v34 + 1;
      if (v34 + 1 < frame)
        v51 = v34 + 1;
      else
        v51 = -268435455;
      if (v50 >= frame && loop == 0)
      {
        v53 = &monitor->basic->effect;
        dds3Particle_EffectReset(v53, v23);
        if (++v65 >= number)
          monitor->basic->state = 0;
      }
      else
      {
        v50 = v51;
      }
      v30->frame = v50;
      v54 = monitor->basic;
      v55 = v54->hPhysics->pPhysics;
      *&v55[2 * v23 + 8] = v30;
      v57 = monitor->pOffset;
      y = p.y;
      z = p.z;
      w = p.w;
      v62 = (v57 + v24);
      ++v23;
      *v62 = p.x;
      v62[1] = y;
      v24 += 16;
      v62[2] = z;
      v62[3] = w;
    }
    while (number != v23);
  }
}

// 0x112d760
void dds3Particle_SmokeOffsetSetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  void *monitor;
  s64 v8;
  s64 v9;
  s64 v10;
  f32 v11;
  f32 v12;
  char *v13;
  s64 *v14;
  u64 v15[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v15);
    if ((v15[0] & 1) != 0)
      v13 = v15[2];
    else
      v13 = v15 + 1;
    v14 = sub_8C4940(v13);
  }
  monitor = (*hData)[22].monitor;
  if (monitor)
  {
    v8 = *(monitor + 2) + 32LL;
    sub_854710(v8, 0);
    sub_854930(v8, 0);
    v9 = *(monitor + 2) + 32LL;
    sub_854710(v9, 1u);
    sub_854930(v9, 1u);
    v10 = *(monitor + 2) + 32LL;
    sub_854710(v10, 2u);
    sub_854930(v10, 2u);
    v11 = *(monitor + 9) * scale;
    v12 = *(monitor + 11);
    *(monitor + 8) = *(monitor + 8) * scale;
    *(monitor + 9) = v11;
    *(monitor + 11) = v12 * scale;
  }
}

// 0x1121360
void dds3Particle_SmokeSetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  void *monitor;
  s64 v8;
  s64 v9;
  s64 v10;
  f32 v11;
  f32 v12;
  char *v13;
  s64 *v14;
  u64 v15[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v15);
    if ((v15[0] & 1) != 0)
      v13 = v15[2];
    else
      v13 = v15 + 1;
    v14 = sub_8C4940(v13);
  }
  monitor = (*hData)[17].monitor;
  if (monitor)
  {
    v8 = *(monitor + 2) + 32LL;
    sub_854710(v8, 0);
    sub_854930(v8, 0);
    v9 = *(monitor + 2) + 32LL;
    sub_854710(v9, 1u);
    sub_854930(v9, 1u);
    v10 = *(monitor + 2) + 32LL;
    sub_854710(v10, 2u);
    sub_854930(v10, 2u);
    v11 = *(monitor + 9) * scale;
    v12 = *(monitor + 11);
    *(monitor + 8) = *(monitor + 8) * scale;
    *(monitor + 9) = v11;
    *(monitor + 11) = v12 * scale;
  }
}

// 0x11287c0
void dds3Particle_Spark2AllBuffInit(void **hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  u64 *monitor;
  s64 v7;
  u64 v8;
  s64 v9;
  s64 v10;
  s64 v12;
  char *v13;
  s64 *v14;
  u64 v15[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v15);
    if ((v15[0] & 1) != 0)
      v13 = v15[2];
    else
      v13 = v15 + 1;
    v14 = sub_8C4940(v13);
  }
  monitor = (*hData)[20].monitor;
  v7 = monitor[2];
  if (*(v7 + 48))
  {
    v8 = 0;
    do
    {
      v10 = *(v7 + 184);
      else
      {
        v9 = *(v10 + 24);
        if (v8 >= *(v9 + 24))
        {
LABEL_12:
        }
      }
      v12 = v9 + 8 * v8++;
      *(*(v12 + 32) + 48LL) = -268435455;
      v7 = monitor[2];
    }
    while (v8 < *(v7 + 48));
  }
}

// 0x1128e50
void dds3Particle_Spark2BuffInit(dds3Particle_Spark2_t3 **pSpark2, s32 number) {
  struct dds3Particle_Physics_t_o *hPhysics;
  struct parPhysics_t_array *pPhysics;
  parPhysics_t_o *v8;
  f32 angle;
  u64 v11;
  dds3Particle_Spark2_t3_o *v12;
  f32 v13;
  f32 v15;
  f32 v16;
  struct dds3Particle_Basic_t_o *basic;
  s64 v18;
  s64 v19;
  s64 v20;
  s64 v21;
  s64 v22;
  s64 v23;
  s64 v24;
  u32 Rand;
  s64 v26;
  struct dds3Particle_Basic_t_o *v27;
  f32 scl_r;
  f32 v30;
  f32 v31;
  f32 rot_r;
  f32 v35;
  dds3Particle_Effect_t_o **p_effect;
  UnityEngine_Matrix4x4_o v37;

  hPhysics = (*pSpark2)->basic->hPhysics;
  pPhysics = hPhysics->pPhysics;
  v8 = pPhysics->m_Items[number];
  angle = (*pSpark2)->angle;
  else if (effBTLSkillCheckRun2(0x4Fu))
  {
    goto LABEL_24;
  }
  else if (effBTLSkillCheckRun2(0x62u))
  {
    goto LABEL_24;
  }
  else if (!effBTLSkillCheckRun2(0x64u))
  {
    goto LABEL_17;
  }
LABEL_24:
  v12 = *pSpark2;
  v13 = (*pSpark2)->angle;
  if ((*pSpark2)->type)
    goto LABEL_25;
LABEL_28:
  LODWORD(v11) = v12->basic->number;
  v15 = v11;
  v16 = (v13 / v15) * number;
  sdfCos(v16);
  sdfSin(v16);
  sub_854930(&v8->fields, 0);
  sub_854930(&v8->fields, 1u);
  sub_854930(&v8->fields, 2u);
  basic = (*pSpark2)->basic;
  v18 = *&basic->rot.m00;
  v19 = *&basic->rot.m20;
  v20 = *&basic->rot.m21;
  *&v37.m01 = *&basic->rot.m01;
  *&v37.m21 = v20;
  *&v37.m00 = v18;
  *&v37.m20 = v19;
  v21 = *&basic->rot.m02;
  v22 = *&basic->rot.m22;
  v24 = *&basic->rot.m03;
  v23 = *&basic->rot.m23;
  *&v37.m03 = v24;
  *&v37.m23 = v23;
  *&v37.m02 = v21;
  *&v37.m22 = v22;
  SDF_VU0__LOADMATRIX(&v37);
  SDF_VU0__LOADVECTOR(v8->pos);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__STOREVECTOR(&v8->pos);
  sub_854710(&v8->fields, 0);
  sub_854710(&(*pSpark2)->basic->fields, 0);
  sub_854930(&v8->fields, 0);
  sub_854710(&v8->fields, 1u);
  sub_854710(&(*pSpark2)->basic->fields, 1u);
  sub_854930(&v8->fields, 1u);
  sub_854710(&v8->fields, 2u);
  sub_854710(&(*pSpark2)->basic->fields, 2u);
  sub_854930(&v8->fields, 2u);
  sub_854930(&v8->dir, 0);
  sub_854930(&v8->dir, 1u);
  sub_854930(&v8->dir, 2u);
  sub_854930(&v8->val_f, 2u);
  {
LABEL_26:
  }
LABEL_32:
  Rand = sdfGetRand(&ParRand);
  v26 = (*pSpark2)->timing + 1LL;
  v8->frame = Rand / v26 * v26 - Rand;
  v8->color = 0;
  v27 = (*pSpark2)->basic;
  scl_r = v27->exp->scl_r;
  sub_854710(&v27->scale, 0);
  v31 = v30;
  v8->scale = v31 * DDS3EFFECT_RAND_FA(scl_r);
  rot_r = (*pSpark2)->basic->exp->rot_r;
  if (rot_r == 0.0)
  {
    v35 = 0.0;
  }
  else
  {
    v35 = DDS3EFFECT_RAND_FA(rot_r) * 6.2832;
  }
  v8->rot = v35;
  p_effect = &(*pSpark2)->basic->effect;
  dds3Particle_EffectReset(p_effect, number);
}

// 0x1128af0
dds3Particle_Basic_t *dds3Particle_Spark2Create(void *hData, s32 bPos, bool pCopy, s32 billno) {
  u64 *v8;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  dds3Particle_Spark2_t3_o *pSpark2;
  Il2CppClass *v16;
  s64 *Interface;
  char *v18;
  s64 *v19;
  dds3Particle_Basic_t_o *dst;
  Il2CppObject *hDataa;
  u64 v24[2];
  char *v25;
  s32 bpos;

  bpos = bPos;
  dst = 0;
  hDataa = 0;
  if (pCopy)
  {
    v8 = Allocate(dds3Particle_Basic_t);
    dds3Particle_Basic_t___ctor(v8);
    dst = v8;
    if (hData)
    {
      klass = hData->klass;
      if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v24);
        if ((v24[0] & 1) != 0)
          v11 = v25;
        else
          v11 = v24 + 1;
        v12 = sub_8C4940(v11);
      }
    }
    dds3Particle_Basic_t__dCopy(hData, &dst);
    pSpark2 = dst->pSpark2;
  }
  else
  {
    pSpark2 = Allocate(dds3Particle_Spark2_t3);
    dds3Particle_Spark2_t3___ctor(pSpark2);
    if (hData)
    {
      Interface = QueryInterface(hData, byte);
      if (!Interface)
      {
        sub_8FC2C0(hData->klass->_1.element_class, v16, v24);
        if ((v24[0] & 1) != 0)
          v18 = v25;
        else
          v18 = v24 + 1;
        v19 = sub_8C4940(v18);
      }
    }
    else
    {
      Interface = 0;
    }
    dds3Particle_Spark2_t3__pCopy(pSpark2, Interface, &bpos);
    if (billno == -1)
      pSpark2->basic->billno = -1;
  }
  dds3Particle_BasicCreate(&pSpark2->basic, pCopy);
  dst = pSpark2->basic;
  hDataa = dst;
  dst->pSpark2 = pSpark2;
  dds3Particle_Spark2AllBuffInit(&hDataa);
  return dst;
}

// 0x1128d40
void dds3Particle_Spark2Delete(void **hData) {
  dds3Particle_Basic_t_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3Particle_Basic_t_o *v6;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  v6 = *((*hData)[20].monitor + 2);
  dds3Particle_BasicDelete(v6, v3);
}

// 0x1129390
void dds3Particle_Spark2Draw(void **hData) {
  dds3Particle_Basic_t_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3Particle_Spark2_t3_o *monitor;
  struct dds3Particle_Basic_t_o *basic;
  dds3Particle_Effect_t_o *effect;
  s32 type;
  f32 eff_scl_raito;
  struct dds3Particle_Basic_t_o *v11;
  s64 v12;
  s64 v13;
  s64 v14;
  s64 v15;
  s64 v16;
  s64 v17;
  s64 v18;
  s64 v19;
  struct dds3Particle_Basic_t_o *v22;
  s32 loop;
  s32 frame;
  u64 v25;
  s32 v26;
  struct dds3Particle_Physics_t_o *hPhysics;
  struct parPhysics_t_array *pPhysics;
  parPhysics_t_o *v31;
  s32 v32;
  dds3ParticleColorAnim_t_o *color;
  u32 v34;
  u32 abgr;
  s32 v36;
  s32 v37;
  dds3Particle_Effect_t_o **p_effect;
  f32 scale;
  u32 v42;
  s32 v43;
  s32 v44;
  dds3Particle_Effect_t_o **v46;
  char *v47;
  s64 *v48;
  s32 v49;
  s64 number;
  s64 v51;
  UnityEngine_Matrix4x4_o v52;
  UnityEngine_Vector4_o p;
  dds3Particle_Spark2_t3_o *v54[4];
  dds3Particle_Spark2_t3_o *pSpark2;

  pSpark2 = 0;
  *&p.x = 0;
  *&p.z = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v54);
    if ((v54[0] & 1) != 0)
      v47 = v54[2];
    else
      v47 = v54 + 1;
    v48 = sub_8C4940(v47);
  }
  monitor = (*hData)[20].monitor;
  pSpark2 = monitor;
  *&p.x = 0;
  *&p.z = 0;
  basic = monitor->basic;
  effect = basic->effect;
  type = effect->type;
  eff_scl_raito = basic->eff_scl_raito;
  dds3Particle_EffectInit(effect, eff_scl_raito, v3);
  v11 = monitor->basic;
  v12 = *&v11->rot.m00;
  v13 = *&v11->rot.m20;
  v14 = *&v11->rot.m21;
  *&v52.m01 = *&v11->rot.m01;
  *&v52.m21 = v14;
  *&v52.m00 = v12;
  *&v52.m20 = v13;
  v15 = *&v11->rot.m02;
  v16 = *&v11->rot.m22;
  v18 = *&v11->rot.m03;
  v17 = *&v11->rot.m23;
  *&v52.m03 = v18;
  *&v52.m23 = v17;
  *&v52.m02 = v15;
  *&v52.m22 = v16;
  SDF_VU0__LOADMATRIX(&v52);
  v22 = monitor->basic;
  number = v22->number;
  if (v22->number >= 1)
  {
    loop = monitor->loop;
    v51 = number - 1;
    frame = v22->frame;
    v25 = 0;
    v26 = 0;
    v49 = type;
    hPhysics = v22->hPhysics;
      goto LABEL_12;
    while (1)
    {
LABEL_13:
      pPhysics = hPhysics->pPhysics;
      if (v25 >= LODWORD(pPhysics->max_length))
      {
LABEL_14:
      }
      while (1)
      {
        v31 = pPhysics->m_Items[v25];
        v32 = v31->frame;
        if (v32 == -268435455)
        {
          dds3Particle_Spark2BuffInit(&pSpark2, v25);
          v32 = v31->frame;
        }
        if ((v32 & 0x80000000) == 0)
        {
          color = monitor->basic->color;
          v34 = dds3ParticleColorAnim(color, v19, v32);
          v31->color = v34;
          abgr = monitor->basic->abgr;
          SDF_VU0__dds3ColorItoF(v34);
          SDF_VU0__COPYVECTOR_A_TO_B();
          SDF_VU0__dds3ColorItoF(abgr);
          SDF_VU0__MULVECTOR();
          v31->color = SDF_VU0__dds3ColorFtoI(128.0);
          if (type)
            SDF_VU0__LOADVECTOR_C(v31->pos);
          sub_854710(&v31->dir, 0);
          sub_854930(&v31->dir, 0);
          sub_854710(&v31->dir, 1u);
          sub_854930(&v31->dir, 1u);
          sub_854710(&v31->dir, 2u);
          sub_854930(&v31->dir, 2u);
          sub_854710(&v31->dir, 1u);
          sub_854710(&v31->val_f, 2u);
          sub_854930(&v31->dir, 1u);
          SDF_VU0__LOADVECTOR(v31->dir);
          SDF_VU0__APPLYMATRIX();
          SDF_VU0__STOREVECTOR(&p);
          sub_854710(&v31->fields, 0);
          sub_854710(&p, 0);
          sub_854930(&v31->fields, 0);
          sub_854710(&v31->fields, 1u);
          sub_854710(&p, 1u);
          sub_854930(&v31->fields, 1u);
          sub_854710(&v31->fields, 2u);
          sub_854710(&p, 2u);
          sub_854930(&v31->fields, 2u);
          if (type)
          {
            v36 = loop;
            v37 = frame;
            SDF_VU0__LOADVECTOR(v31->pos);
            p_effect = &monitor->basic->effect;
            scale = v31->scale;
            v42 = v31->color;
            dds3Particle_EffectSet(p_effect, v25, v42, scale);
            frame = v37;
            loop = v36;
            type = v49;
          }
        }
        v43 = v32 + 1;
        v44 = v32 + 1 < frame ? v32 + 1 : -268435455;
        if (v43 >= frame && loop == 0)
        {
          v46 = &monitor->basic->effect;
          dds3Particle_EffectReset(v46, v25);
          if (++v26 >= number)
            monitor->basic->state = 0;
          v31->frame = v43;
          if (v51 == v25)
            return;
        }
        else
        {
          v31->frame = v44;
          if (v51 == v25)
            return;
        }
        ++v25;
        hPhysics = monitor->basic->hPhysics;
          goto LABEL_13;
LABEL_12:
          break;
        pPhysics = hPhysics->pPhysics;
        if (v25 >= LODWORD(pPhysics->max_length))
          goto LABEL_14;
      }
    }
  }
}

// 0x1128950
void dds3Particle_Spark2SetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  void *monitor;
  s64 v8;
  s64 v9;
  s64 v10;
  f32 v11;
  f32 v12;
  char *v13;
  s64 *v14;
  u64 v15[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v15);
    if ((v15[0] & 1) != 0)
      v13 = v15[2];
    else
      v13 = v15 + 1;
    v14 = sub_8C4940(v13);
  }
  monitor = (*hData)[20].monitor;
  if (monitor)
  {
    v8 = *(monitor + 2) + 32LL;
    sub_854710(v8, 0);
    sub_854930(v8, 0);
    v9 = *(monitor + 2) + 32LL;
    sub_854710(v9, 1u);
    sub_854930(v9, 1u);
    v10 = *(monitor + 2) + 32LL;
    sub_854710(v10, 2u);
    sub_854930(v10, 2u);
    v11 = *(monitor + 12);
    v12 = *(monitor + 9) * scale;
    *(monitor + 11) = *(monitor + 11) * scale;
    *(monitor + 9) = v12;
    *(monitor + 12) = v11 * scale;
  }
}

// 0x1122380
void dds3Particle_SparkAllBuffInit(void **hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v6;
  const char *name;
  u64 v8;
  s64 v9;
  s64 v10;
  s64 v12;
  char *v13;
  s64 *v14;
  u64 v15[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v15);
    if ((v15[0] & 1) != 0)
      v13 = v15[2];
    else
      v13 = v15 + 1;
    v14 = sub_8C4940(v13);
  }
  v6 = (*hData)[18].klass;
  name = v6->_1.name;
  if (*(name + 12))
  {
    v8 = 0;
    do
    {
      v10 = *(name + 23);
      else
      {
        v9 = *(v10 + 24);
        if (v8 >= *(v9 + 24))
        {
LABEL_12:
        }
      }
      v12 = v9 + 8 * v8++;
      *(*(v12 + 32) + 48LL) = -268435455;
      name = v6->_1.name;
    }
    while (v8 < *(name + 12));
  }
}

// 0x1122a10
void dds3Particle_SparkBuffInit(dds3Particle_Spark_t3 **pSpark, s32 number) {
  u64 v3;
  struct dds3Particle_Physics_t_o *hPhysics;
  struct parPhysics_t_array *pPhysics;
  parPhysics_t_o *v9;
  dds3Particle_Spark_t3_o *v10;
  s32 type;
  struct dds3Particle_Basic_t_o *basic;
  s64 v13;
  s64 v14;
  s64 v15;
  s64 v16;
  s64 v17;
  s64 v18;
  s64 v19;
  s64 p_val_f;
  s32 v23;
  s64 v25;
  f32 v26;
  f32 v27;
  struct dds3Particle_Basic_t_o *v28;
  s64 v29;
  s64 v30;
  s64 v31;
  s64 v32;
  s64 v33;
  s64 v34;
  s64 v35;
  s64 p_dir;
  u32 *v37;
  s32 v38;
  s32 v39;
  s32 v40;
  s32 v42;
  s32 v43;
  s32 v44;
  s32 v46;
  s32 v47;
  s32 v48;
  s32 v50;
  s32 v51;
  s32 v52;
  s32 v54;
  s32 v55;
  s32 v56;
  s32 v58;
  s32 v59;
  s32 v60;
  s32 v62;
  s32 v63;
  s32 v64;
  s32 v66;
  s32 v67;
  s32 v68;
  s32 v70;
  s32 v71;
  s32 v72;
  s32 v74;
  s32 v75;
  s32 v76;
  s32 v78;
  s32 v79;
  s32 v80;
  s32 v82;
  s32 v83;
  s32 v84;
  u32 v86;
  s64 v88;
  u32 Rand;
  s64 v92;
  struct dds3Particle_Basic_t_o *v93;
  f32 scl_r;
  f32 v96;
  f32 v97;
  f32 rot_r;
  f32 v101;
  dds3Particle_Effect_t_o **p_effect;
  s64 v103;
  s64 v104;
  s64 v105;
  s64 v106;
  s64 v107;
  s64 v108;
  s64 v109;
  s64 v110;
  s64 v111;
  s64 v112;
  s64 v113;
  s64 v114;
  s64 v115;
  s64 v116;
  s64 v117;
  s64 v118;
  s64 v119;
  s64 v120;
  s64 v121;
  s64 v122;
  s64 v123;
  s64 v124;
  s64 v125;
  s64 v126;
  UnityEngine_Matrix4x4_o v127;
  UnityEngine_Matrix4x4_o v128;
  UnityEngine_Vector4_o p;
  u64 v130[3];

  v130[0] = 0;
  v130[1] = 0;
  *&p.x = 0;
  *&p.z = 0;
  hPhysics = (*pSpark)->basic->hPhysics;
  pPhysics = hPhysics->pPhysics;
  v9 = pPhysics->m_Items[number];
  v10 = *pSpark;
  type = (*pSpark)->type;
  if (type == 2)
  {
    if (v10->random)
    {
      SDF_VU0__STOREIDENTITY(&v10->basic->rot);
      DDS3EFFECT_RAND_PM();
      sub_854930(&p, 0);
      DDS3EFFECT_RAND_PM();
      sub_854930(&p, 1u);
      DDS3EFFECT_RAND_PM();
      sub_854930(&p, 2u);
      SDF_VU0__LOADVECTOR(p);
      SDF_VU0__NORMALIZE();
      SDF_VU0__STOREVECTOR(&p);
      DDS3EFFECT_RAND_FA((*pSpark)->speed_r, 0);
      sub_854710(&p, 0);
      sub_854930(&p, 0);
      sub_854710(&p, 1u);
      sub_854930(&p, 1u);
      sub_854710(&p, 2u);
      sub_854930(&p, 2u);
      sub_854710(&p, 0);
      sub_854930(&v9->dir, 0);
      sub_854710(&p, 1u);
      sub_854930(&v9->dir, 1u);
      sub_854710(&p, 2u);
      sub_854930(&v9->dir, 2u);
      sub_854710(&(*pSpark)->basic->fields, 0);
      sub_854930(v130, 0);
      sub_854710(&(*pSpark)->basic->fields, 1u);
      sub_854930(v130, 1u);
      sub_854710(&(*pSpark)->basic->fields, 2u);
      sub_854930(v130, 2u);
      v23 = 0;
      do
      {
        sub_854710(v130, 0);
        sub_854710(&p, 0);
        sub_854930(v130, 0);
        sub_854710(v130, 1u);
        sub_854710(&p, 1u);
        sub_854930(v130, 1u);
        sub_854710(v130, 2u);
        sub_854710(&p, 2u);
        sub_854930(v130, 2u);
        sub_854710(&p, 0);
        sub_854930(&p, 0);
        sub_854710(&p, 1u);
        sub_854930(&p, 1u);
        sub_854710(&p, 2u);
        sub_854930(&p, 2u);
        sub_854710(&p, 1u);
        sub_854930(&p, 1u);
        ++v23;
      }
      while (v23 < (*pSpark)->basic->frame);
      sub_854710(v130, 0);
      sub_854930(&v9->fields, 0);
      sub_854710(v130, 1u);
      sub_854930(&v9->fields, 1u);
      sub_854710(v130, 2u);
      sub_854930(&v9->fields, 2u);
      p_val_f = &v9->val_f;
      goto LABEL_71;
    }
  }
  else
  {
    if (type == 1)
    {
      if (!v10->random)
      {
        v37 = NewSpecific(UnityEngine_Vector4, 0xCu);
        v125 = 0;
        v126 = 0;
        sub_8546D0(&v125, 0.0, 1.0, 0.0);
        v38 = HIDWORD(v125);
        v40 = v126;
        v39 = HIDWORD(v126);
        v37[8] = v125;
        v37[9] = v38;
        v37[10] = v40;
        v37[11] = v39;
        v123 = 0;
        v124 = 0;
        sub_8546D0(&v123, 0.0, 0.44721, 0.89443);
        v42 = HIDWORD(v123);
        v44 = v124;
        v43 = HIDWORD(v124);
        v37[12] = v123;
        v37[13] = v42;
        v37[14] = v44;
        v37[15] = v43;
        v121 = 0;
        v122 = 0;
        sub_8546D0(&v121, 0.85065, 0.44721, 0.27639);
        v46 = HIDWORD(v121);
        v48 = v122;
        v47 = HIDWORD(v122);
        v37[16] = v121;
        v37[17] = v46;
        v37[18] = v48;
        v37[19] = v47;
        v119 = 0;
        v120 = 0;
        sub_8546D0(&v119, 0.52573, 0.44721, -0.72361);
        v50 = HIDWORD(v119);
        v52 = v120;
        v51 = HIDWORD(v120);
        v37[20] = v119;
        v37[21] = v50;
        v37[22] = v52;
        v37[23] = v51;
        v117 = 0;
        v118 = 0;
        sub_8546D0(&v117, -0.52573, 0.44721, -0.72361);
        v54 = HIDWORD(v117);
        v56 = v118;
        v55 = HIDWORD(v118);
        v37[24] = v117;
        v37[25] = v54;
        v37[26] = v56;
        v37[27] = v55;
        v115 = 0;
        v116 = 0;
        sub_8546D0(&v115, -0.85065, 0.44721, 0.27639);
        v58 = HIDWORD(v115);
        v60 = v116;
        v59 = HIDWORD(v116);
        v37[28] = v115;
        v37[29] = v58;
        v37[30] = v60;
        v37[31] = v59;
        v113 = 0;
        v114 = 0;
        sub_8546D0(&v113, 0.52573, -0.44721, 0.72361);
        v62 = HIDWORD(v113);
        v64 = v114;
        v63 = HIDWORD(v114);
        v37[32] = v113;
        v37[33] = v62;
        v37[34] = v64;
        v37[35] = v63;
        v111 = 0;
        v112 = 0;
        sub_8546D0(&v111, 0.85065, -0.44721, -0.27639);
        v66 = HIDWORD(v111);
        v68 = v112;
        v67 = HIDWORD(v112);
        v37[36] = v111;
        v37[37] = v66;
        v37[38] = v68;
        v37[39] = v67;
        v109 = 0;
        v110 = 0;
        sub_8546D0(&v109, 0.0, -0.44721, -0.89443);
        v70 = HIDWORD(v109);
        v72 = v110;
        v71 = HIDWORD(v110);
        v37[40] = v109;
        v37[41] = v70;
        v37[42] = v72;
        v37[43] = v71;
        v107 = 0;
        v108 = 0;
        sub_8546D0(&v107, -0.85065, -0.44721, -0.27639);
        v74 = HIDWORD(v107);
        v76 = v108;
        v75 = HIDWORD(v108);
        v37[44] = v107;
        v37[45] = v74;
        v37[46] = v76;
        v37[47] = v75;
        v105 = 0;
        v106 = 0;
        sub_8546D0(&v105, -0.52573, -0.44721, 0.72361);
        v78 = HIDWORD(v105);
        v80 = v106;
        v79 = HIDWORD(v106);
        v37[48] = v105;
        v37[49] = v78;
        v37[50] = v80;
        v37[51] = v79;
        v103 = 0;
        v104 = 0;
        sub_8546D0(&v103, 0.0, -1.0, 0.0);
        v82 = HIDWORD(v103);
        v84 = v104;
        v83 = HIDWORD(v104);
        v37[52] = v103;
        v37[53] = v82;
        v37[54] = v84;
        v37[55] = v83;
        sub_854710(&(*pSpark)->basic->fields, 0);
        sub_854930(&v9->fields, 0);
        sub_854710(&(*pSpark)->basic->fields, 1u);
        sub_854930(&v9->fields, 1u);
        sub_854710(&(*pSpark)->basic->fields, 2u);
        sub_854930(&v9->fields, 2u);
        SDF_VU0__STOREIDENTITY(&(*pSpark)->basic->rot, 0);
        v86 = number % 12;
        v88 = &v37[4 * (number % 12) + 8];
        sub_854710(v88, 0);
        sub_854930(&v9->dir, 0);
        sub_854710(v88, 1u);
        sub_854930(&v9->dir, 1u);
        sub_854710(v88, 2u);
        p_dir = &v9->dir;
        goto LABEL_70;
      }
      sub_854710(&v10->basic->fields, 0);
      sub_854930(&v9->fields, 0);
      sub_854710(&(*pSpark)->basic->fields, 1u);
      sub_854930(&v9->fields, 1u);
      sub_854710(&(*pSpark)->basic->fields, 2u);
      sub_854930(&v9->fields, 2u);
      DDS3EFFECT_RAND_PM();
      sub_854930(&p, 0);
      DDS3EFFECT_RAND_PM();
      sub_854930(&p, 1u);
      DDS3EFFECT_RAND_PM();
      sub_854930(&p, 2u);
      SDF_VU0__LOADVECTOR(p);
      SDF_VU0__NORMALIZE();
      SDF_VU0__STOREVECTOR(&p);
      DDS3EFFECT_RAND_FA((*pSpark)->speed_r, 0);
      v25 = &v9->dir;
      sub_854710(&p, 0);
      sub_854930(&v9->dir, 0);
      sub_854710(&p, 1u);
      sub_854930(&v9->dir, 1u);
      sub_854710(&p, 2u);
LABEL_38:
      p_dir = v25;
LABEL_70:
      sub_854930(p_dir, 2u);
      p_val_f = &v9->val_f;
LABEL_71:
      sub_854930(p_val_f, 2u);
      goto LABEL_72;
    }
    if (!(*pSpark)->type)
    {
      if (v10->random)
      {
        DDS3EFFECT_RAND_PM();
        sub_854930(&p, 0);
        sub_854930(&p, 1u);
        DDS3EFFECT_RAND_PM();
        sub_854930(&p, 2u);
        SDF_VU0__LOADVECTOR(p);
        SDF_VU0__NORMALIZE();
        SDF_VU0__STOREVECTOR(&p);
        sub_854710(&p, 0);
        sub_854930(&v9->fields, 0);
        sub_854930(&v9->fields, 1u);
        sub_854710(&p, 2u);
        sub_854930(&v9->fields, 2u);
        basic = (*pSpark)->basic;
        v13 = *&basic->rot.m00;
        v14 = *&basic->rot.m20;
        v15 = *&basic->rot.m21;
        *&v128.m01 = *&basic->rot.m01;
        *&v128.m21 = v15;
        *&v128.m00 = v13;
        *&v128.m20 = v14;
        v16 = *&basic->rot.m02;
        v17 = *&basic->rot.m22;
        v19 = *&basic->rot.m03;
        v18 = *&basic->rot.m23;
        *&v128.m03 = v19;
        *&v128.m23 = v18;
        *&v128.m02 = v16;
        *&v128.m22 = v17;
        SDF_VU0__LOADMATRIX(&v128);
        SDF_VU0__LOADVECTOR(v9->pos);
        SDF_VU0__APPLYMATRIX();
        SDF_VU0__STOREVECTOR(&v9->pos);
        sub_854710(&v9->fields, 0);
        sub_854710(&(*pSpark)->basic->fields, 0);
        sub_854930(&v9->fields, 0);
        sub_854710(&v9->fields, 1u);
        sub_854710(&(*pSpark)->basic->fields, 1u);
        sub_854930(&v9->fields, 1u);
        sub_854710(&v9->fields, 2u);
        sub_854710(&(*pSpark)->basic->fields, 2u);
        sub_854930(&v9->fields, 2u);
        sdfGetRandFloat(&ParRand);
        sub_854930(&p, 0);
        sub_854930(&p, 1u);
        sdfGetRandFloat(&ParRand);
        sub_854930(&p, 2u);
        SDF_VU0__LOADVECTOR(p);
        SDF_VU0__NORMALIZE();
        SDF_VU0__STOREVECTOR(&p);
        DDS3EFFECT_RAND_FA((*pSpark)->speed_r, 0);
        sub_854710(&p, 0);
        sub_854930(&v9->dir, 0);
        sub_854710(&p, 1u);
        sub_854930(&v9->dir, 1u);
        sub_854710(&p, 2u);
        sub_854930(&v9->dir, 2u);
        DDS3EFFECT_RAND_FA(0.5);
        p_val_f = &v9->val_f;
        goto LABEL_71;
      }
      LODWORD(v3) = v10->basic->number;
      v26 = v3;
      v27 = (6.2832 / v26) * number;
      sdfCos(v27);
      sdfSin(v27);
      sub_854930(&v9->fields, 0);
      sub_854930(&v9->fields, 1u);
      sub_854930(&v9->fields, 2u);
      v28 = (*pSpark)->basic;
      v29 = *&v28->rot.m00;
      v30 = *&v28->rot.m20;
      v31 = *&v28->rot.m21;
      *&v127.m01 = *&v28->rot.m01;
      *&v127.m21 = v31;
      *&v127.m00 = v29;
      *&v127.m20 = v30;
      v32 = *&v28->rot.m02;
      v33 = *&v28->rot.m22;
      v35 = *&v28->rot.m03;
      v34 = *&v28->rot.m23;
      *&v127.m03 = v35;
      *&v127.m23 = v34;
      *&v127.m02 = v32;
      *&v127.m22 = v33;
      SDF_VU0__LOADMATRIX(&v127);
      SDF_VU0__LOADVECTOR(v9->pos);
      SDF_VU0__APPLYMATRIX();
      SDF_VU0__STOREVECTOR(&v9->pos);
      sub_854710(&v9->fields, 0);
      sub_854710(&(*pSpark)->basic->fields, 0);
      sub_854930(&v9->fields, 0);
      sub_854710(&v9->fields, 1u);
      sub_854710(&(*pSpark)->basic->fields, 1u);
      sub_854930(&v9->fields, 1u);
      sub_854710(&v9->fields, 2u);
      sub_854710(&(*pSpark)->basic->fields, 2u);
      sub_854930(&v9->fields, 2u);
      v25 = &v9->dir;
      sub_854930(&v9->dir, 0);
      sub_854930(&v9->dir, 1u);
      goto LABEL_38;
    }
  }
LABEL_72:
  Rand = sdfGetRand(&ParRand);
  v92 = (*pSpark)->timing + 1LL;
  v9->frame = Rand / v92 * v92 - Rand;
  v9->color = 0;
  v93 = (*pSpark)->basic;
  scl_r = v93->exp->scl_r;
  sub_854710(&v93->scale, 0);
  v97 = v96;
  v9->scale = v97 * DDS3EFFECT_RAND_FA(scl_r);
  rot_r = (*pSpark)->basic->exp->rot_r;
  if (rot_r == 0.0)
  {
    v101 = 0.0;
  }
  else
  {
    v101 = DDS3EFFECT_RAND_FA(rot_r) * 6.2832;
  }
  v9->rot = v101;
  p_effect = &(*pSpark)->basic->effect;
  dds3Particle_EffectReset(p_effect, number);
}

// 0x11226b0
dds3Particle_Basic_t *dds3Particle_SparkCreate(void *hData, s32 bPos, bool pCopy, s32 billno) {
  u64 *v8;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  dds3Particle_Spark_t3_o *pSpark;
  Il2CppClass *v16;
  s64 *Interface;
  char *v18;
  s64 *v19;
  dds3Particle_Basic_t_o *dst;
  Il2CppObject *hDataa;
  u64 v24[2];
  char *v25;
  s32 bpos;

  bpos = bPos;
  dst = 0;
  hDataa = 0;
  if (pCopy)
  {
    v8 = Allocate(dds3Particle_Basic_t);
    dds3Particle_Basic_t___ctor(v8);
    dst = v8;
    if (hData)
    {
      klass = hData->klass;
      if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v24);
        if ((v24[0] & 1) != 0)
          v11 = v25;
        else
          v11 = v24 + 1;
        v12 = sub_8C4940(v11);
      }
    }
    dds3Particle_Basic_t__dCopy(hData, &dst);
    pSpark = dst->pSpark;
  }
  else
  {
    pSpark = Allocate(dds3Particle_Spark_t3);
    dds3Particle_Spark_t3___ctor(pSpark);
    if (hData)
    {
      Interface = QueryInterface(hData, byte);
      if (!Interface)
      {
        sub_8FC2C0(hData->klass->_1.element_class, v16, v24);
        if ((v24[0] & 1) != 0)
          v18 = v25;
        else
          v18 = v24 + 1;
        v19 = sub_8C4940(v18);
      }
    }
    else
    {
      Interface = 0;
    }
    dds3Particle_Spark_t3__pCopy(pSpark, Interface, &bpos);
    if (billno == -1)
      pSpark->basic->billno = -1;
  }
  dds3Particle_BasicCreate(&pSpark->basic, pCopy);
  dst = pSpark->basic;
  hDataa = dst;
  dst->pSpark = pSpark;
  dds3Particle_SparkAllBuffInit(&hDataa);
  return dst;
}

// 0x1122900
void dds3Particle_SparkDelete(void **hData) {
  dds3Particle_Basic_t_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3Particle_Basic_t_o *name;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  name = (*hData)[18].klass->_1.name;
  dds3Particle_BasicDelete(name, v3);
}

// 0x1123ce0
void dds3Particle_SparkDraw(void **hData) {
  dds3Particle_Basic_t_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3Particle_Spark_t3_o *v6;
  struct dds3Particle_Basic_t_o *basic;
  dds3Particle_Effect_t_o *effect;
  s32 type;
  f32 eff_scl_raito;
  s64 v11;
  struct dds3Particle_Basic_t_o *v14;
  s64 v15;
  s64 v16;
  s64 v17;
  s64 v18;
  s64 v19;
  s64 v20;
  s64 v21;
  struct dds3Particle_Basic_t_o *v22;
  s32 loop;
  s64 v24;
  s32 frame;
  u64 v26;
  s32 v27;
  struct dds3Particle_Physics_t_o *hPhysics;
  struct parPhysics_t_array *pPhysics;
  parPhysics_t_o *v32;
  s32 v33;
  dds3ParticleColorAnim_t_o *color;
  u32 v35;
  u32 abgr;
  s64 v37;
  s32 v38;
  s32 v39;
  f32 scale;
  u32 v43;
  dds3Particle_Effect_t_o **p_effect;
  s32 v45;
  s32 v46;
  dds3Particle_Effect_t_o **v48;
  char *v49;
  s64 *v50;
  s32 v51;
  s64 number;
  s32 v53;
  UnityEngine_Matrix4x4_o v54;
  UnityEngine_Vector4_o p;
  dds3Particle_Spark_t3_o *v56[4];
  dds3Particle_Spark_t3_o *pSpark;

  pSpark = 0;
  *&p.x = 0;
  *&p.z = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v56);
    if ((v56[0] & 1) != 0)
      v49 = v56[2];
    else
      v49 = v56 + 1;
    v50 = sub_8C4940(v49);
  }
  v6 = (*hData)[18].klass;
  pSpark = v6;
  *&p.x = 0;
  *&p.z = 0;
  basic = v6->basic;
  effect = basic->effect;
  type = effect->type;
  eff_scl_raito = basic->eff_scl_raito;
  dds3Particle_EffectInit(effect, eff_scl_raito, v3);
  v53 = v6->type;
  if (!v6->type)
  {
    v14 = v6->basic;
    v15 = *&v14->rot.m00;
    v16 = *&v14->rot.m20;
    v17 = *&v14->rot.m21;
    *&v54.m01 = *&v14->rot.m01;
    *&v54.m21 = v17;
    *&v54.m00 = v15;
    *&v54.m20 = v16;
    v18 = *&v14->rot.m02;
    v19 = *&v14->rot.m22;
    v21 = *&v14->rot.m03;
    v20 = *&v14->rot.m23;
    *&v54.m03 = v21;
    *&v54.m23 = v20;
    *&v54.m02 = v18;
    *&v54.m22 = v19;
    SDF_VU0__LOADMATRIX(&v54);
    v6 = pSpark;
  }
  v22 = v6->basic;
  number = v22->number;
  if (v22->number >= 1)
  {
    loop = v6->loop;
    v24 = number - 1;
    frame = v22->frame;
    v26 = 0;
    v27 = 0;
    v51 = type;
    hPhysics = v22->hPhysics;
      goto LABEL_14;
    while (1)
    {
LABEL_15:
      pPhysics = hPhysics->pPhysics;
      if (v26 >= LODWORD(pPhysics->max_length))
      {
LABEL_16:
      }
      while (1)
      {
        v32 = pPhysics->m_Items[v26];
        v33 = v32->frame;
        if (v33 == -268435455)
        {
          dds3Particle_SparkBuffInit(&pSpark, v26);
          v33 = v32->frame;
        }
        if ((v33 & 0x80000000) == 0)
        {
          color = pSpark->basic->color;
          v35 = dds3ParticleColorAnim(color, v11, v33);
          v32->color = v35;
          abgr = pSpark->basic->abgr;
          SDF_VU0__dds3ColorItoF(v35);
          SDF_VU0__COPYVECTOR_A_TO_B();
          SDF_VU0__dds3ColorItoF(abgr);
          SDF_VU0__MULVECTOR();
          v32->color = SDF_VU0__dds3ColorFtoI(128.0);
          if (type)
            SDF_VU0__LOADVECTOR_C(v32->pos);
          sub_854710(&v32->dir, 0);
          sub_854930(&v32->dir, 0);
          sub_854710(&v32->dir, 1u);
          sub_854930(&v32->dir, 1u);
          sub_854710(&v32->dir, 2u);
          sub_854930(&v32->dir, 2u);
          sub_854710(&v32->dir, 1u);
          sub_854710(&v32->val_f, 2u);
          sub_854930(&v32->dir, 1u);
          SDF_VU0__LOADVECTOR(v32->dir);
          if (!v53)
            SDF_VU0__APPLYMATRIX();
          SDF_VU0__STOREVECTOR(&p);
          sub_854710(&v32->fields, 0);
          sub_854710(&p, 0);
          sub_854930(&v32->fields, 0);
          sub_854710(&v32->fields, 1u);
          sub_854710(&p, 1u);
          sub_854930(&v32->fields, 1u);
          sub_854710(&v32->fields, 2u);
          sub_854710(&p, 2u);
          sub_854930(&v32->fields, 2u);
          if (type)
          {
            v37 = v24;
            v38 = loop;
            v39 = frame;
            SDF_VU0__LOADVECTOR(v32->pos);
            scale = v32->scale;
            v43 = v32->color;
            p_effect = &pSpark->basic->effect;
            dds3Particle_EffectSet(p_effect, v26, v43, scale);
            frame = v39;
            loop = v38;
            v24 = v37;
            type = v51;
          }
        }
        v45 = v33 + 1;
        v46 = v33 + 1 < frame ? v33 + 1 : -268435455;
        if (v45 >= frame && loop == 0)
        {
          v48 = &pSpark->basic->effect;
          dds3Particle_EffectReset(v48, v26);
          if (++v27 >= number)
            pSpark->basic->state = 0;
          v32->frame = v45;
          if (v24 == v26)
            return;
        }
        else
        {
          v32->frame = v46;
          if (v24 == v26)
            return;
        }
        ++v26;
        hPhysics = pSpark->basic->hPhysics;
          goto LABEL_15;
LABEL_14:
          break;
        pPhysics = hPhysics->pPhysics;
        if (v26 >= LODWORD(pPhysics->max_length))
          goto LABEL_16;
      }
    }
  }
}

// 0x112b890
void dds3Particle_SparkOffsetAllBuffInit(void **hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v6;
  const char *name;
  u64 v8;
  s64 v9;
  s64 v10;
  s64 v12;
  char *v13;
  s64 *v14;
  u64 v15[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v15);
    if ((v15[0] & 1) != 0)
      v13 = v15[2];
    else
      v13 = v15 + 1;
    v14 = sub_8C4940(v13);
  }
  v6 = (*hData)[22].klass;
  name = v6->_1.name;
  if (*(name + 12))
  {
    v8 = 0;
    do
    {
      v10 = *(name + 23);
      else
      {
        v9 = *(v10 + 24);
        if (v8 >= *(v9 + 24))
        {
LABEL_12:
        }
      }
      v12 = v9 + 8 * v8++;
      *(*(v12 + 32) + 48LL) = -268435455;
      name = v6->_1.name;
    }
    while (v8 < *(name + 12));
  }
}

// 0x112bf20
void dds3Particle_SparkOffsetBuffInit(dds3Particle_SparkOffset_t3 **pSparkOffset, s32 number) {
  u64 v3;
  struct dds3Particle_Physics_t_o *hPhysics;
  struct parPhysics_t_array *pPhysics;
  parPhysics_t_o *v9;
  dds3Particle_SparkOffset_t3_o *v10;
  s32 type;
  struct dds3Particle_Basic_t_o *basic;
  s64 v13;
  s64 v14;
  s64 v15;
  s64 v16;
  s64 v17;
  s64 v18;
  s64 v19;
  s64 p_val_f;
  s32 v23;
  f32 v25;
  f32 v26;
  struct dds3Particle_Basic_t_o *v27;
  s64 v28;
  s64 v29;
  s64 v30;
  s64 v31;
  s64 v32;
  s64 v33;
  s64 v34;
  s64 p_dir;
  u32 *v36;
  s32 v37;
  s32 v38;
  s32 v39;
  s32 v41;
  s32 v42;
  s32 v43;
  s32 v45;
  s32 v46;
  s32 v47;
  s32 v49;
  s32 v50;
  s32 v51;
  s32 v53;
  s32 v54;
  s32 v55;
  s32 v57;
  s32 v58;
  s32 v59;
  s32 v61;
  s32 v62;
  s32 v63;
  s32 v65;
  s32 v66;
  s32 v67;
  s32 v69;
  s32 v70;
  s32 v71;
  s32 v73;
  s32 v74;
  s32 v75;
  s32 v77;
  s32 v78;
  s32 v79;
  s32 v81;
  s32 v82;
  s32 v83;
  u32 v85;
  s64 v87;
  u32 Rand;
  s64 v91;
  struct dds3Particle_Basic_t_o *v92;
  f32 scl_r;
  f32 v95;
  f32 v96;
  f32 rot_r;
  f32 v100;
  dds3Particle_Effect_t_o **p_effect;
  s64 v102;
  s64 v103;
  s64 v104;
  s64 v105;
  s64 v106;
  s64 v107;
  s64 v108;
  s64 v109;
  s64 v110;
  s64 v111;
  s64 v112;
  s64 v113;
  s64 v114;
  s64 v115;
  s64 v116;
  s64 v117;
  s64 v118;
  s64 v119;
  s64 v120;
  s64 v121;
  s64 v122;
  s64 v123;
  s64 v124;
  s64 v125;
  UnityEngine_Matrix4x4_o v126;
  UnityEngine_Matrix4x4_o v127;
  UnityEngine_Vector4_o p;
  u64 v129[3];

  v129[0] = 0;
  v129[1] = 0;
  *&p.x = 0;
  *&p.z = 0;
  hPhysics = (*pSparkOffset)->basic->hPhysics;
  pPhysics = hPhysics->pPhysics;
  v9 = pPhysics->m_Items[number];
  v10 = *pSparkOffset;
  type = (*pSparkOffset)->type;
  if (type == 2)
  {
    if (v10->random)
    {
      SDF_VU0__STOREIDENTITY(&v10->basic->rot);
      DDS3EFFECT_RAND_PM();
      sub_854930(&p, 0);
      DDS3EFFECT_RAND_PM();
      sub_854930(&p, 1u);
      DDS3EFFECT_RAND_PM();
      sub_854930(&p, 2u);
      SDF_VU0__LOADVECTOR(p);
      SDF_VU0__NORMALIZE();
      SDF_VU0__STOREVECTOR(&p);
      DDS3EFFECT_RAND_FA((*pSparkOffset)->speed_r, 0);
      sub_854710(&p, 0);
      sub_854930(&p, 0);
      sub_854710(&p, 1u);
      sub_854930(&p, 1u);
      sub_854710(&p, 2u);
      sub_854930(&p, 2u);
      sub_854710(&p, 0);
      sub_854930(&v9->dir, 0);
      sub_854710(&p, 1u);
      sub_854930(&v9->dir, 1u);
      sub_854710(&p, 2u);
      sub_854930(&v9->dir, 2u);
      sub_854930(v129, 0);
      sub_854930(v129, 1u);
      sub_854930(v129, 2u);
      v23 = 0;
      do
      {
        sub_854710(v129, 0);
        sub_854710(&p, 0);
        sub_854930(v129, 0);
        sub_854710(v129, 1u);
        sub_854710(&p, 1u);
        sub_854930(v129, 1u);
        sub_854710(v129, 2u);
        sub_854710(&p, 2u);
        sub_854930(v129, 2u);
        sub_854710(&p, 0);
        sub_854930(&p, 0);
        sub_854710(&p, 1u);
        sub_854930(&p, 1u);
        sub_854710(&p, 2u);
        sub_854930(&p, 2u);
        sub_854710(&p, 1u);
        sub_854930(&p, 1u);
        ++v23;
      }
      while (v23 < (*pSparkOffset)->basic->frame);
      sub_854710(v129, 0);
      sub_854930(&v9->fields, 0);
      sub_854710(v129, 1u);
      sub_854930(&v9->fields, 1u);
      sub_854710(v129, 2u);
      sub_854930(&v9->fields, 2u);
      p_val_f = &v9->val_f;
      goto LABEL_70;
    }
  }
  else
  {
    if (type == 1)
    {
      if (v10->random)
      {
        sub_854930(&v9->val_f, 0);
        sub_854930(&v9->val_f, 1u);
        sub_854930(&v9->val_f, 2u);
        SDF_VU0__COPYVECTOR(&v9->pos, (*pSparkOffset)->basic->pos, 0);
        DDS3EFFECT_RAND_PM();
        sub_854930(&p, 0);
        DDS3EFFECT_RAND_PM();
        sub_854930(&p, 1u);
        DDS3EFFECT_RAND_PM();
        sub_854930(&p, 2u);
        SDF_VU0__LOADVECTOR(p);
        SDF_VU0__NORMALIZE();
        SDF_VU0__STOREVECTOR(&p);
        DDS3EFFECT_RAND_FA((*pSparkOffset)->speed_r, 0);
        sub_854710(&p, 0);
        sub_854930(&v9->dir, 0);
        sub_854710(&p, 1u);
        sub_854930(&v9->dir, 1u);
        sub_854710(&p, 2u);
        sub_854930(&v9->dir, 2u);
        p_val_f = &v9->val_f;
        goto LABEL_70;
      }
      v36 = NewSpecific(UnityEngine_Vector4, 0xCu);
      v124 = 0;
      v125 = 0;
      sub_8546D0(&v124, 0.0, 1.0, 0.0);
      v37 = HIDWORD(v124);
      v39 = v125;
      v38 = HIDWORD(v125);
      v36[8] = v124;
      v36[9] = v37;
      v36[10] = v39;
      v36[11] = v38;
      v122 = 0;
      v123 = 0;
      sub_8546D0(&v122, 0.0, 0.44721, 0.89443);
      v41 = HIDWORD(v122);
      v43 = v123;
      v42 = HIDWORD(v123);
      v36[12] = v122;
      v36[13] = v41;
      v36[14] = v43;
      v36[15] = v42;
      v120 = 0;
      v121 = 0;
      sub_8546D0(&v120, 0.85065, 0.44721, 0.27639);
      v45 = HIDWORD(v120);
      v47 = v121;
      v46 = HIDWORD(v121);
      v36[16] = v120;
      v36[17] = v45;
      v36[18] = v47;
      v36[19] = v46;
      v118 = 0;
      v119 = 0;
      sub_8546D0(&v118, 0.52573, 0.44721, -0.72361);
      v49 = HIDWORD(v118);
      v51 = v119;
      v50 = HIDWORD(v119);
      v36[20] = v118;
      v36[21] = v49;
      v36[22] = v51;
      v36[23] = v50;
      v116 = 0;
      v117 = 0;
      sub_8546D0(&v116, -0.52573, 0.44721, -0.72361);
      v53 = HIDWORD(v116);
      v55 = v117;
      v54 = HIDWORD(v117);
      v36[24] = v116;
      v36[25] = v53;
      v36[26] = v55;
      v36[27] = v54;
      v114 = 0;
      v115 = 0;
      sub_8546D0(&v114, -0.85065, 0.44721, 0.27639);
      v57 = HIDWORD(v114);
      v59 = v115;
      v58 = HIDWORD(v115);
      v36[28] = v114;
      v36[29] = v57;
      v36[30] = v59;
      v36[31] = v58;
      v112 = 0;
      v113 = 0;
      sub_8546D0(&v112, 0.52573, -0.44721, 0.72361);
      v61 = HIDWORD(v112);
      v63 = v113;
      v62 = HIDWORD(v113);
      v36[32] = v112;
      v36[33] = v61;
      v36[34] = v63;
      v36[35] = v62;
      v110 = 0;
      v111 = 0;
      sub_8546D0(&v110, 0.85065, -0.44721, -0.27639);
      v65 = HIDWORD(v110);
      v67 = v111;
      v66 = HIDWORD(v111);
      v36[36] = v110;
      v36[37] = v65;
      v36[38] = v67;
      v36[39] = v66;
      v108 = 0;
      v109 = 0;
      sub_8546D0(&v108, 0.0, -0.44721, -0.89443);
      v69 = HIDWORD(v108);
      v71 = v109;
      v70 = HIDWORD(v109);
      v36[40] = v108;
      v36[41] = v69;
      v36[42] = v71;
      v36[43] = v70;
      v106 = 0;
      v107 = 0;
      sub_8546D0(&v106, -0.85065, -0.44721, -0.27639);
      v73 = HIDWORD(v106);
      v75 = v107;
      v74 = HIDWORD(v107);
      v36[44] = v106;
      v36[45] = v73;
      v36[46] = v75;
      v36[47] = v74;
      v104 = 0;
      v105 = 0;
      sub_8546D0(&v104, -0.52573, -0.44721, 0.72361);
      v77 = HIDWORD(v104);
      v79 = v105;
      v78 = HIDWORD(v105);
      v36[48] = v104;
      v36[49] = v77;
      v36[50] = v79;
      v36[51] = v78;
      v102 = 0;
      v103 = 0;
      sub_8546D0(&v102, 0.0, -1.0, 0.0);
      v81 = HIDWORD(v102);
      v83 = v103;
      v82 = HIDWORD(v103);
      v36[52] = v102;
      v36[53] = v81;
      v36[54] = v83;
      v36[55] = v82;
      sub_854930(&v9->fields, 0);
      sub_854930(&v9->fields, 1u);
      sub_854930(&v9->fields, 2u);
      SDF_VU0__STOREIDENTITY(&(*pSparkOffset)->basic->rot, 0);
      v85 = number % 12;
      v87 = &v36[4 * (number % 12) + 8];
      sub_854710(v87, 0);
      sub_854930(&v9->dir, 0);
      sub_854710(v87, 1u);
      sub_854930(&v9->dir, 1u);
      sub_854710(v87, 2u);
      p_dir = &v9->dir;
      goto LABEL_69;
    }
    if (!(*pSparkOffset)->type)
    {
      if (v10->random)
      {
        DDS3EFFECT_RAND_PM();
        sub_854930(&p, 0);
        sub_854930(&p, 1u);
        DDS3EFFECT_RAND_PM();
        sub_854930(&p, 2u);
        SDF_VU0__LOADVECTOR(p);
        SDF_VU0__NORMALIZE();
        SDF_VU0__STOREVECTOR(&p);
        sub_854710(&p, 0);
        sub_854930(&v9->val_f, 0);
        sub_854930(&v9->val_f, 1u);
        sub_854710(&p, 2u);
        sub_854930(&v9->val_f, 2u);
        SDF_VU0__COPYVECTOR(&v9->pos, (*pSparkOffset)->basic->pos, 0);
        basic = (*pSparkOffset)->basic;
        v13 = *&basic->rot.m00;
        v14 = *&basic->rot.m20;
        v15 = *&basic->rot.m21;
        *&v127.m01 = *&basic->rot.m01;
        *&v127.m21 = v15;
        *&v127.m00 = v13;
        *&v127.m20 = v14;
        v16 = *&basic->rot.m02;
        v17 = *&basic->rot.m22;
        v19 = *&basic->rot.m03;
        v18 = *&basic->rot.m23;
        *&v127.m03 = v19;
        *&v127.m23 = v18;
        *&v127.m02 = v16;
        *&v127.m22 = v17;
        SDF_VU0__LOADMATRIX(&v127);
        SDF_VU0__LOADVECTOR(v9->val_f);
        SDF_VU0__APPLYMATRIX();
        SDF_VU0__STOREVECTOR(&v9->val_f);
        sdfGetRandFloat(&ParRand);
        sub_854930(&p, 0);
        sub_854930(&p, 1u);
        sdfGetRandFloat(&ParRand);
        sub_854930(&p, 2u);
        SDF_VU0__LOADVECTOR(p);
        SDF_VU0__NORMALIZE();
        SDF_VU0__STOREVECTOR(&p);
        DDS3EFFECT_RAND_FA((*pSparkOffset)->speed_r, 0);
        sub_854710(&p, 0);
        sub_854930(&v9->dir, 0);
        sub_854710(&p, 1u);
        sub_854930(&v9->dir, 1u);
        sub_854710(&p, 2u);
        sub_854930(&v9->dir, 2u);
        DDS3EFFECT_RAND_FA(0.5);
        p_val_f = &v9->val_f;
        goto LABEL_70;
      }
      LODWORD(v3) = v10->basic->number;
      v25 = v3;
      v26 = (6.2832 / v25) * number;
      sdfCos(v26);
      sdfSin(v26);
      sub_854930(&v9->fields, 0);
      sub_854930(&v9->fields, 1u);
      sub_854930(&v9->fields, 2u);
      v27 = (*pSparkOffset)->basic;
      v28 = *&v27->rot.m00;
      v29 = *&v27->rot.m20;
      v30 = *&v27->rot.m21;
      *&v126.m01 = *&v27->rot.m01;
      *&v126.m21 = v30;
      *&v126.m00 = v28;
      *&v126.m20 = v29;
      v31 = *&v27->rot.m02;
      v32 = *&v27->rot.m22;
      v34 = *&v27->rot.m03;
      v33 = *&v27->rot.m23;
      *&v126.m03 = v34;
      *&v126.m23 = v33;
      *&v126.m02 = v31;
      *&v126.m22 = v32;
      SDF_VU0__LOADMATRIX(&v126);
      SDF_VU0__LOADVECTOR(v9->pos);
      SDF_VU0__APPLYMATRIX();
      SDF_VU0__STOREVECTOR(&v9->pos);
      sub_854930(&v9->dir, 0);
      sub_854930(&v9->dir, 1u);
      p_dir = &v9->dir;
LABEL_69:
      sub_854930(p_dir, 2u);
      p_val_f = &v9->val_f;
LABEL_70:
      sub_854930(p_val_f, 3u);
    }
  }
  Rand = sdfGetRand(&ParRand);
  v91 = (*pSparkOffset)->timing + 1LL;
  v9->frame = Rand / v91 * v91 - Rand;
  v9->color = 0;
  v92 = (*pSparkOffset)->basic;
  scl_r = v92->exp->scl_r;
  sub_854710(&v92->scale, 0);
  v96 = v95;
  v9->scale = v96 * DDS3EFFECT_RAND_FA(scl_r);
  rot_r = (*pSparkOffset)->basic->exp->rot_r;
  if (rot_r == 0.0)
  {
    v100 = 0.0;
  }
  else
  {
    v100 = DDS3EFFECT_RAND_FA(rot_r) * 6.2832;
  }
  v9->rot = v100;
  p_effect = &(*pSparkOffset)->basic->effect;
  dds3Particle_EffectReset(p_effect, number);
}

// 0x112bbc0
dds3Particle_Basic_t *dds3Particle_SparkOffsetCreate(void *hData, s32 bPos, bool pCopy, s32 billno) {
  u64 *v8;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  dds3Particle_SparkOffset_t3_o *pSparkOffset;
  Il2CppClass *v16;
  s64 *Interface;
  char *v18;
  s64 *v19;
  dds3Particle_Basic_t_o *dst;
  Il2CppObject *hDataa;
  u64 v24[2];
  char *v25;
  s32 bpos;

  bpos = bPos;
  dst = 0;
  hDataa = 0;
  if (pCopy)
  {
    v8 = Allocate(dds3Particle_Basic_t);
    dds3Particle_Basic_t___ctor(v8);
    dst = v8;
    if (hData)
    {
      klass = hData->klass;
      if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v24);
        if ((v24[0] & 1) != 0)
          v11 = v25;
        else
          v11 = v24 + 1;
        v12 = sub_8C4940(v11);
      }
    }
    dds3Particle_Basic_t__dCopy(hData, &dst);
    pSparkOffset = dst->pSparkOffset;
  }
  else
  {
    pSparkOffset = Allocate(dds3Particle_SparkOffset_t3);
    dds3Particle_SparkOffset_t3___ctor(pSparkOffset);
    if (hData)
    {
      Interface = QueryInterface(hData, byte);
      if (!Interface)
      {
        sub_8FC2C0(hData->klass->_1.element_class, v16, v24);
        if ((v24[0] & 1) != 0)
          v18 = v25;
        else
          v18 = v24 + 1;
        v19 = sub_8C4940(v18);
      }
    }
    else
    {
      Interface = 0;
    }
    dds3Particle_SparkOffset_t3__pCopy(pSparkOffset, Interface, &bpos);
    if (billno == -1)
      pSparkOffset->basic->billno = -1;
  }
  dds3Particle_BasicCreate(&pSparkOffset->basic, pCopy);
  dst = pSparkOffset->basic;
  hDataa = dst;
  dst->pSparkOffset = pSparkOffset;
  dds3Particle_SparkOffsetAllBuffInit(&hDataa);
  return dst;
}

// 0x112be10
void dds3Particle_SparkOffsetDelete(void **hData) {
  dds3Particle_Basic_t_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3Particle_Basic_t_o *name;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  name = (*hData)[22].klass->_1.name;
  dds3Particle_BasicDelete(name, v3);
}

// 0x112d010
void dds3Particle_SparkOffsetDraw(void **hData) {
  dds3Particle_Basic_t_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3Particle_SparkOffset_t3_o *v6;
  struct dds3Particle_Basic_t_o *basic;
  dds3Particle_Effect_t_o *effect;
  s32 type;
  f32 eff_scl_raito;
  struct dds3Particle_Basic_t_o *v11;
  s64 v12;
  s64 v13;
  s64 v14;
  s64 v15;
  s64 v16;
  s64 v17;
  s64 v18;
  struct dds3Particle_Basic_t_o *v19;
  s64 number;
  s64 v21;
  u64 v24;
  s32 v25;
  struct parPhysics_t_array *pPhysics;
  struct dds3Particle_Physics_t_o *hPhysics;
  parPhysics_t_o *v29;
  s32 v30;
  dds3ParticleColorAnim_t_o *color;
  u32 v32;
  u32 abgr;
  f32 scale;
  u32 v37;
  dds3Particle_Effect_t_o **p_effect;
  s32 v39;
  s32 v40;
  dds3Particle_Effect_t_o **v42;
  char *v43;
  s64 *v44;
  s32 v45;
  s32 loop;
  s32 frame;
  UnityEngine_Matrix4x4_o v48;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o p;
  dds3Particle_SparkOffset_t3_o *v51[4];
  dds3Particle_SparkOffset_t3_o *pSparkOffset;

  pSparkOffset = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v51);
    if ((v51[0] & 1) != 0)
      v43 = v51[2];
    else
      v43 = v51 + 1;
    v44 = sub_8C4940(v43);
  }
  v6 = (*hData)[22].klass;
  pSparkOffset = v6;
  *&p.x = 0;
  *&p.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  basic = v6->basic;
  effect = basic->effect;
  type = effect->type;
  eff_scl_raito = basic->eff_scl_raito;
  dds3Particle_EffectInit(effect, eff_scl_raito, v3);
  v45 = v6->type;
  if (!v6->type)
  {
    v11 = v6->basic;
    v12 = *&v11->rot.m00;
    v13 = *&v11->rot.m20;
    v14 = *&v11->rot.m21;
    *&v48.m01 = *&v11->rot.m01;
    *&v48.m21 = v14;
    *&v48.m00 = v12;
    *&v48.m20 = v13;
    v15 = *&v11->rot.m02;
    v16 = *&v11->rot.m22;
    v18 = *&v11->rot.m03;
    v17 = *&v11->rot.m23;
    *&v48.m03 = v18;
    *&v48.m23 = v17;
    *&v48.m02 = v15;
    *&v48.m22 = v16;
    SDF_VU0__LOADMATRIX(&v48);
    v6 = pSparkOffset;
  }
  v19 = v6->basic;
  frame = v19->frame;
  loop = v6->loop;
  number = v19->number;
  SDF_VU0__COPYVECTOR(&dst, v19->pos);
  if (number >= 1)
  {
    v24 = 0;
    v25 = 0;
    do
    {
      while (1)
      {
        hPhysics = pSparkOffset->basic->hPhysics;
        else
        {
          pPhysics = hPhysics->pPhysics;
          if (v24 >= LODWORD(pPhysics->max_length))
          {
LABEL_17:
          }
        }
        v29 = pPhysics->m_Items[v24];
        v30 = v29->frame;
        if (v30 == -268435455)
        {
          dds3Particle_SparkOffsetBuffInit(&pSparkOffset, v24);
          v30 = v29->frame;
        }
        if ((v30 & 0x80000000) == 0)
        {
          color = pSparkOffset->basic->color;
          v32 = dds3ParticleColorAnim(color, v21, v30);
          v29->color = v32;
          abgr = pSparkOffset->basic->abgr;
          SDF_VU0__dds3ColorItoF(v32);
          SDF_VU0__COPYVECTOR_A_TO_B();
          SDF_VU0__dds3ColorItoF(abgr);
          SDF_VU0__MULVECTOR();
          v29->color = SDF_VU0__dds3ColorFtoI(128.0);
          if (type)
            SDF_VU0__LOADVECTOR_C(v29->pos);
          sub_854710(&v29->dir, 0);
          sub_854930(&v29->dir, 0);
          sub_854710(&v29->dir, 1u);
          sub_854930(&v29->dir, 1u);
          sub_854710(&v29->dir, 2u);
          sub_854930(&v29->dir, 2u);
          sub_854710(&v29->dir, 1u);
          sub_854710(&v29->val_f, 3u);
          sub_854930(&v29->dir, 1u);
          SDF_VU0__LOADVECTOR(v29->dir);
          if (!v45)
            SDF_VU0__APPLYMATRIX();
          SDF_VU0__STOREVECTOR(&p);
          sub_854710(&v29->val_f, 0);
          sub_854710(&p, 0);
          sub_854930(&v29->val_f, 0);
          sub_854710(&v29->val_f, 1u);
          sub_854710(&p, 1u);
          sub_854930(&v29->val_f, 1u);
          sub_854710(&v29->val_f, 2u);
          sub_854710(&p, 2u);
          sub_854930(&v29->val_f, 2u);
          SDF_VU0__LOADVECTOR(v29->val_f);
          SDF_VU0__LOADVECTOR_B(dst);
          SDF_VU0__ADDVECTOR();
          SDF_VU0__STOREVECTOR(&v29->pos);
          if (type)
          {
            SDF_VU0__LOADVECTOR(v29->pos);
            scale = v29->scale;
            v37 = v29->color;
            p_effect = &pSparkOffset->basic->effect;
            dds3Particle_EffectSet(p_effect, v24, v37, scale);
          }
        }
        v39 = v30 + 1;
        v40 = v30 + 1 < frame ? v30 + 1 : -268435455;
        if (v39 >= frame && loop == 0)
          break;
        ++v24;
        v29->frame = v40;
        if (number == v24)
          return;
      }
      v42 = &pSparkOffset->basic->effect;
      dds3Particle_EffectReset(v42, v24);
      if (++v25 >= number)
        pSparkOffset->basic->state = 0;
      ++v24;
      v29->frame = v39;
    }
    while (number != v24);
  }
}

// 0x112ba20
void dds3Particle_SparkOffsetSetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v7;
  s64 v8;
  s64 v9;
  s64 v10;
  f32 v11;
  f32 v12;
  char *v13;
  s64 *v14;
  u64 v15[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v15);
    if ((v15[0] & 1) != 0)
      v13 = v15[2];
    else
      v13 = v15 + 1;
    v14 = sub_8C4940(v13);
  }
  v7 = (*hData)[22].klass;
  if (v7)
  {
    v8 = (v7->_1.name + 32);
    sub_854710(v8, 0);
    sub_854930(v8, 0);
    v9 = (v7->_1.name + 32);
    sub_854710(v9, 1u);
    sub_854930(v9, 1u);
    v10 = (v7->_1.name + 32);
    sub_854710(v10, 2u);
    sub_854930(v10, 2u);
    v11 = *&v7->_1.this_arg.data;
    v12 = *(&v7->_1.byval_arg.data + 1) * scale;
    *(&v7->_1.byval_arg.bits + 1) = *(&v7->_1.byval_arg.bits + 1) * scale;
    *(&v7->_1.byval_arg.data + 1) = v12;
    *&v7->_1.this_arg.data = v11 * scale;
  }
}

// 0x1122510
void dds3Particle_SparkSetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v7;
  s64 v8;
  s64 v9;
  s64 v10;
  f32 v11;
  f32 v12;
  char *v13;
  s64 *v14;
  u64 v15[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v15);
    if ((v15[0] & 1) != 0)
      v13 = v15[2];
    else
      v13 = v15 + 1;
    v14 = sub_8C4940(v13);
  }
  v7 = (*hData)[18].klass;
  if (v7)
  {
    v8 = (v7->_1.name + 32);
    sub_854710(v8, 0);
    sub_854930(v8, 0);
    v9 = (v7->_1.name + 32);
    sub_854710(v9, 1u);
    sub_854930(v9, 1u);
    v10 = (v7->_1.name + 32);
    sub_854710(v10, 2u);
    sub_854930(v10, 2u);
    v11 = *&v7->_1.this_arg.data;
    v12 = *(&v7->_1.byval_arg.data + 1) * scale;
    *(&v7->_1.byval_arg.bits + 1) = *(&v7->_1.byval_arg.bits + 1) * scale;
    *(&v7->_1.byval_arg.data + 1) = v12;
    *&v7->_1.this_arg.data = v11 * scale;
  }
}

// 0x1129920
void dds3Particle_SphereAtomAllBuffInit(void **hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v6;
  const char *name;
  u64 v8;
  s64 v9;
  s64 v10;
  s64 v12;
  char *v13;
  s64 *v14;
  u64 v15[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v15);
    if ((v15[0] & 1) != 0)
      v13 = v15[2];
    else
      v13 = v15 + 1;
    v14 = sub_8C4940(v13);
  }
  v6 = (*hData)[21].klass;
  name = v6->_1.name;
  if (*(name + 12))
  {
    v8 = 0;
    do
    {
      v10 = *(name + 23);
      else
      {
        v9 = *(v10 + 24);
        if (v8 >= *(v9 + 24))
        {
LABEL_12:
        }
      }
      v12 = *(v9 + 8 * v8 + 32);
      sub_854930(v12 + 64, 1u);
      *(v12 + 48) = -268435455;
      name = v6->_1.name;
      ++v8;
    }
    while (v8 < *(name + 12));
  }
}

// 0x1129fc0
void dds3Particle_SphereAtomBuffInit(dds3Particle_SphereAtom_t3 **pSphereAtom, s32 number) {
  struct dds3Particle_Physics_t_o *hPhysics;
  struct parPhysics_t_array *pPhysics;
  parPhysics_t_o *v8;
  struct dds3Particle_Basic_t_o *basic;
  s64 v10;
  s64 v11;
  s64 v12;
  s64 v13;
  s64 v14;
  s64 v15;
  s64 v16;
  u64 v18;
  f32 v19;
  u32 Rand;
  s64 v22;
  struct dds3Particle_Basic_t_o *v23;
  f32 scl_r;
  f32 v26;
  f32 v27;
  f32 rot_r;
  f32 v31;
  dds3Particle_Effect_t_o **p_effect;
  UnityEngine_Matrix4x4_o v33;
  UnityEngine_Vector4_o p;

  *&p.x = 0;
  *&p.z = 0;
  hPhysics = (*pSphereAtom)->basic->hPhysics;
  pPhysics = hPhysics->pPhysics;
  v8 = pPhysics->m_Items[number];
  if ((*pSphereAtom)->type)
  {
    DDS3EFFECT_RAND_PM();
    sub_854930(&p, 0);
    DDS3EFFECT_RAND_PM();
    sub_854930(&p, 1u);
    DDS3EFFECT_RAND_PM();
    sub_854930(&p, 2u);
    SDF_VU0__LOADVECTOR(p);
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(&p);
    DDS3EFFECT_RAND_F();
    sub_854710(&p, 0);
    sub_854930(&v8->fields, 0);
    DDS3EFFECT_RAND_F();
    sub_854710(&p, 1u);
    sub_854930(&v8->fields, 1u);
    DDS3EFFECT_RAND_F();
    sub_854710(&p, 2u);
    sub_854930(&v8->fields, 2u);
    basic = (*pSphereAtom)->basic;
    v10 = *&basic->rot.m00;
    v11 = *&basic->rot.m20;
    v12 = *&basic->rot.m21;
    *&v33.m01 = *&basic->rot.m01;
    *&v33.m21 = v12;
    *&v33.m00 = v10;
    *&v33.m20 = v11;
    v13 = *&basic->rot.m02;
    v14 = *&basic->rot.m22;
    v16 = *&basic->rot.m03;
    v15 = *&basic->rot.m23;
    *&v33.m03 = v16;
    *&v33.m23 = v15;
    *&v33.m02 = v13;
    *&v33.m22 = v14;
    SDF_VU0__LOADMATRIX(&v33);
    SDF_VU0__LOADVECTOR(v8->pos);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(&v8->pos);
    sub_854710(&v8->fields, 0);
    sub_854710(&(*pSphereAtom)->basic->fields, 0);
    sub_854930(&v8->fields, 0);
    sub_854710(&v8->fields, 1u);
    sub_854710(&(*pSphereAtom)->basic->fields, 1u);
    sub_854930(&v8->fields, 1u);
    sub_854710(&v8->fields, 2u);
    sub_854710(&(*pSphereAtom)->basic->fields, 2u);
    sub_854930(&v8->fields, 2u);
    DDS3EFFECT_RAND_PM();
    sub_854930(&p, 0);
    DDS3EFFECT_RAND_PM();
    sub_854930(&p, 1u);
    DDS3EFFECT_RAND_PM();
  }
  else
  {
    SDF_VU0__COPYVECTOR(&v8->pos, (*pSphereAtom)->basic->pos, 0);
    LODWORD(v18) = (*pSphereAtom)->basic->number;
    *&v18 = v18;
    v19 = (6.2832 / *&v18) * number;
    sdfCos(v19);
    sub_854930(&p, 0);
    sdfSin(v19);
    sub_854930(&p, 1u);
  }
  sub_854930(&p, 2u);
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v8->dir);
  Rand = sdfGetRand(&ParRand);
  v22 = (*pSphereAtom)->timing + 1LL;
  v8->frame = Rand / v22 * v22 - Rand;
  sub_854930(&v8->val_f, 0);
  v8->color = 0;
  v23 = (*pSphereAtom)->basic;
  scl_r = v23->exp->scl_r;
  sub_854710(&v23->scale, 0);
  v27 = v26;
  v8->scale = v27 * DDS3EFFECT_RAND_FA(scl_r);
  rot_r = (*pSphereAtom)->basic->exp->rot_r;
  if (rot_r == 0.0)
  {
    v31 = 0.0;
  }
  else
  {
    v31 = DDS3EFFECT_RAND_FA(rot_r) * 6.2832;
  }
  v8->rot = v31;
  p_effect = &(*pSphereAtom)->basic->effect;
  dds3Particle_EffectReset(p_effect, number);
}

// 0x1129c60
dds3Particle_Basic_t *dds3Particle_SphereAtomCreate(void *hData, s32 bPos, bool pCopy, s32 billno) {
  u64 *v8;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  dds3Particle_SphereAtom_t3_o *pSphereAtom;
  Il2CppClass *v16;
  s64 *Interface;
  char *v18;
  s64 *v19;
  dds3Particle_Basic_t_o *dst;
  Il2CppObject *hDataa;
  u64 v24[2];
  char *v25;
  s32 bpos;

  bpos = bPos;
  dst = 0;
  hDataa = 0;
  if (pCopy)
  {
    v8 = Allocate(dds3Particle_Basic_t);
    dds3Particle_Basic_t___ctor(v8);
    dst = v8;
    if (hData)
    {
      klass = hData->klass;
      if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v24);
        if ((v24[0] & 1) != 0)
          v11 = v25;
        else
          v11 = v24 + 1;
        v12 = sub_8C4940(v11);
      }
    }
    dds3Particle_Basic_t__dCopy(hData, &dst);
    pSphereAtom = dst->pSphereAtom;
  }
  else
  {
    pSphereAtom = Allocate(dds3Particle_SphereAtom_t3);
    dds3Particle_SphereAtom_t3___ctor(pSphereAtom);
    if (hData)
    {
      Interface = QueryInterface(hData, byte);
      if (!Interface)
      {
        sub_8FC2C0(hData->klass->_1.element_class, v16, v24);
        if ((v24[0] & 1) != 0)
          v18 = v25;
        else
          v18 = v24 + 1;
        v19 = sub_8C4940(v18);
      }
    }
    else
    {
      Interface = 0;
    }
    dds3Particle_SphereAtom_t3__pCopy(pSphereAtom, Interface, &bpos);
    if (billno == -1)
      pSphereAtom->basic->billno = -1;
  }
  dds3Particle_BasicCreate(&pSphereAtom->basic, pCopy);
  dst = pSphereAtom->basic;
  hDataa = dst;
  dst->pSphereAtom = pSphereAtom;
  dds3Particle_SphereAtomAllBuffInit(&hDataa);
  return dst;
}

// 0x1129eb0
void dds3Particle_SphereAtomDelete(void **hData) {
  dds3Particle_Basic_t_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3Particle_Basic_t_o *name;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  name = (*hData)[21].klass->_1.name;
  dds3Particle_BasicDelete(name, v3);
}

// 0x112a540
void dds3Particle_SphereAtomDraw(void **hData) {
  dds3Particle_Basic_t_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3Particle_SphereAtom_t3_o *v6;
  struct dds3Particle_Basic_t_o *basic;
  dds3Particle_Effect_t_o *effect;
  s32 type;
  f32 eff_scl_raito;
  struct dds3Particle_Basic_t_o *v11;
  struct parPhysics_t_array *pPhysics;
  f32 radius_e;
  s64 p_val_f;
  f32 v16;
  f32 v17;
  f32 v18;
  f32 v19;
  f32 v20;
  s64 v21;
  s64 v24;
  u64 v25;
  s32 v26;
  struct dds3Particle_Physics_t_o *hPhysics;
  struct parPhysics_t_array *v28;
  parPhysics_t_o *v30;
  s32 v31;
  dds3ParticleColorAnim_t_o *color;
  u32 v33;
  u32 abgr;
  f32 v35;
  f32 scale;
  u32 v39;
  dds3Particle_Effect_t_o **p_effect;
  s32 v41;
  s32 v42;
  dds3Particle_SphereAtom_t3_o *v44;
  dds3Particle_Effect_t_o **v45;
  char *v46;
  s64 *v47;
  s64 number;
  s32 loop;
  s32 frame;
  UnityEngine_Vector4_o v51;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v53;
  UnityEngine_Vector4_o v54;
  UnityEngine_Vector4_o v55;
  UnityEngine_Vector4_o dst;
  dds3Particle_SphereAtom_t3_o *pSphereAtom;
  u64 v58[4];

  *&dst.z = 0;
  pSphereAtom = 0;
  *&v55.z = 0;
  *&dst.x = 0;
  *&v53.x = 0;
  *&v54.z = 0;
  *&v55.x = 0;
  *&v53.z = 0;
  *&v54.x = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v51.x = 0;
  *&v51.z = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v58);
    if ((v58[0] & 1) != 0)
      v46 = v58[2];
    else
      v46 = v58 + 1;
    v47 = sub_8C4940(v46);
  }
  v6 = (*hData)[21].klass;
  *&dst.z = 0;
  pSphereAtom = v6;
  *&v55.z = 0;
  *&dst.x = 0;
  *&v55.x = 0;
  basic = v6->basic;
  effect = basic->effect;
  type = effect->type;
  eff_scl_raito = basic->eff_scl_raito;
  dds3Particle_EffectInit(effect, eff_scl_raito, v3);
  v11 = v6->basic;
  pPhysics = v11->hPhysics->pPhysics;
  number = v11->number;
  radius_e = v6->radius_e;
  frame = v11->frame;
  loop = v6->loop;
  p_val_f = &pPhysics->m_Items[0]->val_f;
  v16 = (radius_e - v6->radius) / frame;
  sub_854710(p_val_f, 1u);
  v18 = v17;
  if (v16 < 0.0)
  {
    if (v17 <= radius_e)
      goto LABEL_17;
    sub_854930(p_val_f, 1u);
    sub_854710(p_val_f, 1u);
    if (v19 >= radius_e)
      goto LABEL_17;
LABEL_16:
    sub_854930(p_val_f, 1u);
    goto LABEL_17;
  }
  if (v17 < radius_e)
  {
    sub_854930(p_val_f, 1u);
    sub_854710(p_val_f, 1u);
    if (v20 > radius_e)
      goto LABEL_16;
  }
LABEL_17:
  SDF_VU0__COPYVECTOR(&dst, v6->basic->pos);
  if (number >= 1)
  {
    v24 = number - 1;
    v25 = 0;
    v26 = 0;
    while (1)
    {
      hPhysics = v6->basic->hPhysics;
      else
      {
        v28 = hPhysics->pPhysics;
        if (v25 >= LODWORD(v28->max_length))
          goto LABEL_23;
      }
      v30 = v28->m_Items[v25];
      v31 = v30->frame;
      if (v31 == -268435455)
      {
        dds3Particle_SphereAtomBuffInit(&pSphereAtom, v25);
        v31 = v30->frame;
      }
      if ((v31 & 0x80000000) == 0)
      {
        color = v6->basic->color;
        v33 = dds3ParticleColorAnim(color, v21, v31);
        v30->color = v33;
        abgr = v6->basic->abgr;
        SDF_VU0__dds3ColorItoF(v33);
        SDF_VU0__COPYVECTOR_A_TO_B();
        SDF_VU0__dds3ColorItoF(abgr);
        SDF_VU0__MULVECTOR();
        v30->color = SDF_VU0__dds3ColorFtoI(128.0);
        if (type)
          SDF_VU0__COPYVECTOR(&v55, v30->pos);
        sub_854710(&v30->val_f, 0);
        sub_854710(&v30->fields, 0);
        sub_854710(&v30->dir, 0);
        sub_854930(&v30->fields, 0);
        sub_854710(&v30->fields, 1u);
        sub_854710(&v30->dir, 1u);
        sub_854930(&v30->fields, 1u);
        sub_854710(&v30->fields, 2u);
        sub_854710(&v30->dir, 2u);
        sub_854930(&v30->fields, 2u);
        sub_854930(&v30->val_f, 0);
        sub_854690(&v54.x, -1.0, -1.0, -1.0, -1.0);
        *&v53.x = 0;
        *&v53.z = 0;
        *&p.x = 0;
        *&p.z = 0;
        *&v51.x = 0;
        *&v51.z = 0;
        SDF_VU0__LOADVECTOR(v30->pos);
        SDF_VU0__LOADVECTOR_B(dst);
        SDF_VU0__SUBVECTOR();
        SDF_VU0__COPYVECTOR_A_TO_C();
        v35 = SDF_VU0__GETLENGTH();
        SDF_VU0__COPYVECTOR_C_TO_A();
        SDF_VU0__NORMALIZE();
        SDF_VU0__STOREVECTOR(&p);
        if (v35 > v18)
        {
          SDF_VU0__LOADVECTOR(v30->dir);
          SDF_VU0__LOADVECTOR_B(v54);
          SDF_VU0__MULVECTOR();
          SDF_VU0__COPYVECTOR_A_TO_C();
          SDF_VU0__LOADVECTOR(dst);
          SDF_VU0__LOADVECTOR_B(v30->pos);
          SDF_VU0__SUBVECTOR();
          SDF_VU0__NORMALIZE();
          SDF_VU0__COPYVECTOR_C_TO_B();
          SDF_VU0__COPYVECTOR_A_TO_C();
          SDF_VU0__INNERPRODUCT();
          sub_854930(&v53, 0);
          sub_854710(&v53, 0);
          sub_854930(&v53, 0);
          sub_854710(&v53, 0);
          sub_854930(&v53, 1u);
          sub_854930(&v53, 2u);
          SDF_VU0__LOADVECTOR(v53);
          SDF_VU0__COPYVECTOR_C_TO_B();
          SDF_VU0__MULVECTOR();
          SDF_VU0__LOADVECTOR_B(v30->dir);
          SDF_VU0__ADDVECTOR();
          SDF_VU0__NORMALIZE();
          SDF_VU0__STOREVECTOR(&v30->dir);
          sub_854930(&v51, 0);
          sub_854710(&v51, 0);
          sub_854930(&v51, 1u);
          sub_854930(&v51, 2u);
          SDF_VU0__LOADVECTOR(p);
          SDF_VU0__LOADVECTOR_B(v51);
          SDF_VU0__MULVECTOR();
          SDF_VU0__LOADVECTOR_B(dst);
          SDF_VU0__ADDVECTOR();
          SDF_VU0__STOREVECTOR(&v30->pos);
        }
        if (type)
        {
          SDF_VU0__LOADVECTOR_C(v55);
          SDF_VU0__LOADVECTOR(v30->pos);
          scale = v30->scale;
          v39 = v30->color;
          p_effect = &pSphereAtom->basic->effect;
          dds3Particle_EffectSet(p_effect, v25, v39, scale);
        }
      }
      v41 = v31 + 1;
      if (v31 + 1 < frame)
        v42 = v31 + 1;
      else
        v42 = -268435455;
      if (v41 >= frame && loop == 0)
      {
        v44 = pSphereAtom;
        v45 = &pSphereAtom->basic->effect;
        dds3Particle_EffectReset(v45, v25);
        if (++v26 >= number)
          v44->basic->state = 0;
        v30->frame = v41;
        if (v24 == v25)
          return;
      }
      else
      {
        v30->frame = v42;
        if (v24 == v25)
          return;
      }
      v6 = pSphereAtom;
      ++v25;
    }
  }
}

// 0x1129ac0
void dds3Particle_SphereAtomSetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v7;
  s64 v8;
  s64 v9;
  s64 v10;
  f32 v11;
  f32 v12;
  char *v13;
  s64 *v14;
  u64 v15[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v15);
    if ((v15[0] & 1) != 0)
      v13 = v15[2];
    else
      v13 = v15 + 1;
    v14 = sub_8C4940(v13);
  }
  v7 = (*hData)[21].klass;
  if (v7)
  {
    v8 = (v7->_1.name + 32);
    sub_854710(v8, 0);
    sub_854930(v8, 0);
    v9 = (v7->_1.name + 32);
    sub_854710(v9, 1u);
    sub_854930(v9, 1u);
    v10 = (v7->_1.name + 32);
    sub_854710(v10, 2u);
    sub_854930(v10, 2u);
    v11 = *(&v7->_1.byval_arg.data + 1) * scale;
    v12 = *&v7->_1.byval_arg.bits;
    *&v7->_1.byval_arg.data = *&v7->_1.byval_arg.data * scale;
    *(&v7->_1.byval_arg.data + 1) = v11;
    *&v7->_1.byval_arg.bits = v12 * scale;
  }
}

// 0x11277d0
void dds3Particle_SphereRingAllBuffInit(void **hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v6;
  const char *name;
  u64 v8;
  s32 v9;
  s64 v10;
  s64 v11;
  s64 v13;
  char *v14;
  s64 *v15;
  u64 v16[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v16);
    if ((v16[0] & 1) != 0)
      v14 = v16[2];
    else
      v14 = v16 + 1;
    v15 = sub_8C4940(v14);
  }
  v6 = (*hData)[20].klass;
  name = v6->_1.name;
  if (*(name + 12))
  {
    v8 = 0;
    v9 = -268435455;
    do
    {
      while (1)
      {
        v11 = *(name + 23);
        else
        {
          v10 = *(v11 + 24);
          if (v8 >= *(v10 + 24))
          {
LABEL_14:
          }
        }
        v13 = v10 + 8 * v8++;
        *(*(v13 + 32) + 48LL) = v9;
        if (v8 % v6->_1.byval_arg.bits)
          break;
        v9 -= HIDWORD(v6->_1.namespaze);
        name = v6->_1.name;
        if (v8 >= *(name + 12))
          return;
      }
      name = v6->_1.name;
    }
    while (v8 < *(name + 12));
  }
}

// 0x1127e70
void dds3Particle_SphereRingBuffInit(dds3Particle_SphereRing_t3 **pSphereRing, s32 number) {
  struct dds3Particle_Physics_t_o *hPhysics;
  struct parPhysics_t_array *pPhysics;
  parPhysics_t_o *v8;
  f32 radius_r;
  s64 simu_num;
  f32 v12;
  f32 v13;
  f32 v14;
  struct dds3Particle_Basic_t_o *basic;
  s64 v16;
  s64 v17;
  s64 v18;
  s64 v19;
  s64 v20;
  s64 v21;
  s64 v22;
  struct dds3Particle_Basic_t_o *v23;
  f32 scl_r;
  f32 v25;
  f32 rot_r;
  dds3Particle_Effect_t_o **p_effect;
  UnityEngine_Matrix4x4_o v30;
  UnityEngine_Vector4_o v31;

  *&v31.x = 0;
  *&v31.z = 0;
  hPhysics = (*pSphereRing)->basic->hPhysics;
  pPhysics = hPhysics->pPhysics;
  v8 = pPhysics->m_Items[number];
  *&v8->frame = 0xFFFFFFFFLL;
  radius_r = (*pSphereRing)->radius_r;
  DDS3EFFECT_RAND_FA(radius_r);
  sub_854930(&v8->val_f, 0);
  simu_num = (*pSphereRing)->simu_num;
  v12 = simu_num;
  v13 = (6.2832 / v12) * (number % simu_num);
  sdfCos(v13);
  sub_854930(&v8->dir, 0);
  v14 = 0.0;
  sub_854930(&v8->dir, 1u);
  sdfSin(v13);
  sub_854930(&v8->dir, 2u);
  basic = (*pSphereRing)->basic;
  v16 = *&basic->rot.m00;
  v17 = *&basic->rot.m20;
  v18 = *&basic->rot.m21;
  *&v30.m01 = *&basic->rot.m01;
  *&v30.m21 = v18;
  *&v30.m00 = v16;
  *&v30.m20 = v17;
  v19 = *&basic->rot.m02;
  v20 = *&basic->rot.m22;
  v22 = *&basic->rot.m03;
  v21 = *&basic->rot.m23;
  *&v30.m03 = v22;
  *&v30.m23 = v21;
  *&v30.m02 = v19;
  *&v30.m22 = v20;
  SDF_VU0__LOADMATRIX(&v30);
  sub_854930(&v31, 0);
  sub_854930(&v31, 1u);
  sub_854930(&v31, 2u);
  SDF_VU0__LOADVECTOR(v31);
  SDF_VU0__APPLYMATRIX_XYZ();
  SDF_VU0__LOADVECTOR_B((*pSphereRing)->basic->pos, 0);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&v8->pos);
  v23 = (*pSphereRing)->basic;
  scl_r = v23->exp->scl_r;
  sub_854710(&v23->scale, 0);
  v8->scale = v25 * DDS3EFFECT_RAND_FA(scl_r);
  rot_r = (*pSphereRing)->basic->exp->rot_r;
  if (rot_r != 0.0)
  {
    v14 = DDS3EFFECT_RAND_FA(rot_r) * 6.2832;
  }
  v8->rot = v14;
  p_effect = &(*pSphereRing)->basic->effect;
  dds3Particle_EffectReset(p_effect, number);
}

// 0x1127b10
dds3Particle_Basic_t *dds3Particle_SphereRingCreate(void *hData, s32 bPos, bool pCopy, s32 billno) {
  u64 *v8;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  dds3Particle_SphereRing_t3_o *pSphereRing;
  Il2CppClass *v16;
  s64 *Interface;
  char *v18;
  s64 *v19;
  dds3Particle_Basic_t_o *dst;
  Il2CppObject *hDataa;
  u64 v24[2];
  char *v25;
  s32 bpos;

  bpos = bPos;
  dst = 0;
  hDataa = 0;
  if (pCopy)
  {
    v8 = Allocate(dds3Particle_Basic_t);
    dds3Particle_Basic_t___ctor(v8);
    dst = v8;
    if (hData)
    {
      klass = hData->klass;
      if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v24);
        if ((v24[0] & 1) != 0)
          v11 = v25;
        else
          v11 = v24 + 1;
        v12 = sub_8C4940(v11);
      }
    }
    dds3Particle_Basic_t__dCopy(hData, &dst);
    pSphereRing = dst->pSphereRing;
  }
  else
  {
    pSphereRing = Allocate(dds3Particle_SphereRing_t3);
    dds3Particle_SphereRing_t3___ctor(pSphereRing);
    if (hData)
    {
      Interface = QueryInterface(hData, byte);
      if (!Interface)
      {
        sub_8FC2C0(hData->klass->_1.element_class, v16, v24);
        if ((v24[0] & 1) != 0)
          v18 = v25;
        else
          v18 = v24 + 1;
        v19 = sub_8C4940(v18);
      }
    }
    else
    {
      Interface = 0;
    }
    dds3Particle_SphereRing_t3__pCopy(pSphereRing, Interface, &bpos);
    if (billno == -1)
      pSphereRing->basic->billno = -1;
  }
  dds3Particle_BasicCreate(&pSphereRing->basic, pCopy);
  dst = pSphereRing->basic;
  hDataa = dst;
  dst->pSphereRing = pSphereRing;
  dds3Particle_SphereRingAllBuffInit(&hDataa);
  return dst;
}

// 0x1127d60
void dds3Particle_SphereRingDelete(void **hData) {
  dds3Particle_Basic_t_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3Particle_Basic_t_o *name;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  name = (*hData)[20].klass->_1.name;
  dds3Particle_BasicDelete(name, v3);
}

// 0x1128190
void dds3Particle_SphereRingDraw(void **hData) {
  dds3Particle_Basic_t_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3Particle_SphereRing_t3_o *v6;
  struct dds3Particle_Basic_t_o *basic;
  dds3Particle_Effect_t_o *effect;
  s32 type;
  f32 eff_scl_raito;
  struct dds3Particle_Basic_t_o *v11;
  s64 v12;
  s64 v13;
  s64 v14;
  s64 v15;
  s64 v16;
  s64 v17;
  s64 v18;
  struct dds3Particle_Basic_t_o *v20;
  s64 number;
  s32 frame;
  s32 loop;
  f32 v24;
  s64 v25;
  f32 v28;
  u64 v29;
  struct parPhysics_t_array *pPhysics;
  struct dds3Particle_Physics_t_o *hPhysics;
  parPhysics_t_o *v33;
  s32 v34;
  dds3ParticleColorAnim_t_o *color;
  u32 v36;
  u32 abgr;
  f32 v39;
  s32 v40;
  s32 v41;
  dds3Particle_Effect_t_o **p_effect;
  f32 scale;
  u32 v46;
  s32 v47;
  s32 v48;
  dds3Particle_Effect_t_o **v50;
  char *v51;
  s64 *v52;
  s32 v53;
  s64 v54;
  s32 v55;
  UnityEngine_Matrix4x4_o v56;
  UnityEngine_Vector4_o v57;
  UnityEngine_Vector4_o dst;
  dds3Particle_SphereRing_t3_o *pSphereRing;
  u64 v60[4];

  *&dst.z = 0;
  pSphereRing = 0;
  *&v57.z = 0;
  *&dst.x = 0;
  *&v57.x = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v60);
    if ((v60[0] & 1) != 0)
      v51 = v60[2];
    else
      v51 = v60 + 1;
    v52 = sub_8C4940(v51);
  }
  v6 = (*hData)[20].klass;
  *&dst.z = 0;
  pSphereRing = v6;
  *&v57.z = 0;
  *&dst.x = 0;
  *&v57.x = 0;
  basic = v6->basic;
  effect = basic->effect;
  type = effect->type;
  eff_scl_raito = basic->eff_scl_raito;
  dds3Particle_EffectInit(effect, eff_scl_raito, v3);
  v11 = v6->basic;
  v12 = *&v11->rot.m00;
  v13 = *&v11->rot.m20;
  v14 = *&v11->rot.m21;
  *&v56.m01 = *&v11->rot.m01;
  *&v56.m21 = v14;
  *&v56.m00 = v12;
  *&v56.m20 = v13;
  v15 = *&v11->rot.m02;
  v16 = *&v11->rot.m22;
  v18 = *&v11->rot.m03;
  v17 = *&v11->rot.m23;
  *&v56.m03 = v18;
  *&v56.m23 = v17;
  *&v56.m02 = v15;
  *&v56.m22 = v16;
  SDF_VU0__LOADMATRIX(&v56);
  v20 = v6->basic;
  number = v20->number;
  frame = v20->frame;
  loop = v6->loop;
  v24 = v6->roll_s * 0.017453;
  sdfCos(v24);
  sdfSin(v24);
  SDF_VU0__COPYVECTOR(&dst, v6->basic->pos);
  if (number >= 1)
  {
    v28 = frame;
    v29 = 0;
    v55 = 0;
    v54 = number;
    v53 = loop;
    do
    {
      while (1)
      {
        hPhysics = v6->basic->hPhysics;
        else
        {
          pPhysics = hPhysics->pPhysics;
          if (v29 >= LODWORD(pPhysics->max_length))
          {
LABEL_18:
          }
        }
        v33 = pPhysics->m_Items[v29];
        v34 = v33->frame;
        if (v34 == -268435455)
        {
          dds3Particle_SphereRingBuffInit(&pSphereRing, v29);
          v34 = v33->frame;
        }
        if ((v34 & 0x80000000) == 0)
        {
          color = v6->basic->color;
          v36 = dds3ParticleColorAnim(color, v25, v34);
          v33->color = v36;
          abgr = v6->basic->abgr;
          SDF_VU0__dds3ColorItoF(v36);
          SDF_VU0__COPYVECTOR_A_TO_B();
          SDF_VU0__dds3ColorItoF(abgr);
          SDF_VU0__MULVECTOR();
          v33->color = SDF_VU0__dds3ColorFtoI(128.0);
          if (type)
            SDF_VU0__LOADVECTOR_C(v33->pos);
          sub_854710(&v33->val_f, 0);
          v39 = (v34 / v28) * 3.1416;
          sdfCos(v39);
          sdfSin(v39);
          sub_854710(&v33->dir, 0);
          sub_854930(&v57, 0);
          sub_854930(&v57, 1u);
          sub_854710(&v33->dir, 2u);
          sub_854930(&v57, 2u);
          SDF_VU0__LOADVECTOR(v57);
          SDF_VU0__APPLYMATRIX();
          SDF_VU0__LOADVECTOR_B(dst);
          SDF_VU0__ADDVECTOR();
          SDF_VU0__STOREVECTOR(&v33->pos);
          sub_854710(&v33->dir, 0);
          sub_854930(&v57, 0);
          sub_854710(&v33->dir, 2u);
          sub_854930(&v57, 2u);
          sub_854710(&v57, 0);
          sub_854710(&v57, 2u);
          sub_854930(&v33->dir, 0);
          sub_854710(&v57, 2u);
          sub_854710(&v57, 0);
          sub_854930(&v33->dir, 2u);
          if (type)
          {
            v40 = type;
            v41 = frame;
            SDF_VU0__LOADVECTOR(v33->pos);
            p_effect = &v6->basic->effect;
            scale = v33->scale;
            v46 = v33->color;
            dds3Particle_EffectSet(p_effect, v29, v46, scale);
            frame = v41;
            type = v40;
            number = v54;
            loop = v53;
          }
        }
        v47 = v34 + 1;
        v48 = v34 + 1 < frame ? v34 + 1 : -268435455;
        if (v47 >= frame && loop == 0)
          break;
        ++v29;
        v33->frame = v48;
        if (number == v29)
          return;
      }
      v50 = &v6->basic->effect;
      dds3Particle_EffectReset(v50, v29);
      if (++v55 >= number)
        v6->basic->state = 0;
      ++v29;
      v33->frame = v47;
    }
    while (number != v29);
  }
}

// 0x1127980
void dds3Particle_SphereRingSetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v7;
  s64 v8;
  s64 v9;
  s64 v10;
  char *v11;
  s64 *v12;
  u64 v13[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v13);
    if ((v13[0] & 1) != 0)
      v11 = v13[2];
    else
      v11 = v13 + 1;
    v12 = sub_8C4940(v11);
  }
  v7 = (*hData)[20].klass;
  if (v7)
  {
    v8 = (v7->_1.name + 32);
    sub_854710(v8, 0);
    sub_854930(v8, 0);
    v9 = (v7->_1.name + 32);
    sub_854710(v9, 1u);
    sub_854930(v9, 1u);
    v10 = (v7->_1.name + 32);
    sub_854710(v10, 2u);
    sub_854930(v10, 2u);
    *&v7->_1.byval_arg.data = *&v7->_1.byval_arg.data * scale;
  }
}

// 0x11265e0
void dds3Particle_SphereSmokeAllBuffInit(void **hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  u64 *monitor;
  s64 v7;
  u64 v8;
  s64 v9;
  s64 v10;
  s64 v12;
  char *v13;
  s64 *v14;
  u64 v15[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v15);
    if ((v15[0] & 1) != 0)
      v13 = v15[2];
    else
      v13 = v15 + 1;
    v14 = sub_8C4940(v13);
  }
  monitor = (*hData)[19].monitor;
  v7 = monitor[2];
  if (*(v7 + 48))
  {
    v8 = 0;
    do
    {
      v10 = *(v7 + 184);
      else
      {
        v9 = *(v10 + 24);
        if (v8 >= *(v9 + 24))
        {
LABEL_12:
        }
      }
      v12 = v9 + 8 * v8++;
      *(*(v12 + 32) + 48LL) = -268435455;
      v7 = monitor[2];
    }
    while (v8 < *(v7 + 48));
  }
}

// 0x1126c70
void dds3Particle_SphereSmokeBuffInit(dds3Particle_SphereSmoke_t3 **pSphereSmoke, s32 number) {
  struct dds3Particle_Physics_t_o *hPhysics;
  struct parPhysics_t_array *pPhysics;
  parPhysics_t_o *v8;
  f32 radius_s_r;
  struct dds3Particle_Basic_t_o *basic;
  s64 v11;
  s64 v12;
  s64 v13;
  s64 v14;
  s64 v15;
  s64 v16;
  s64 v17;
  f32 v18;
  struct dds3Particle_Basic_t_o *v20;
  f32 scl_r;
  f32 v22;
  f32 rot_r;
  dds3Particle_Effect_t_o **p_effect;
  UnityEngine_Matrix4x4_o v27;
  UnityEngine_Vector4_o p;

  *&p.x = 0;
  *&p.z = 0;
  hPhysics = (*pSphereSmoke)->basic->hPhysics;
  pPhysics = hPhysics->pPhysics;
  v8 = pPhysics->m_Items[number];
  radius_s_r = (*pSphereSmoke)->radius_s_r;
  DDS3EFFECT_RAND_PM();
  sub_854930(&p, 0);
  DDS3EFFECT_RAND_PM();
  sub_854930(&p, 1u);
  DDS3EFFECT_RAND_PM();
  sub_854930(&p, 2u);
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&p);
  DDS3EFFECT_RAND_FA(radius_s_r);
  sub_854710(&p, 0);
  sub_854930(&v8->fields, 0);
  DDS3EFFECT_RAND_FA(radius_s_r);
  sub_854710(&p, 1u);
  sub_854930(&v8->fields, 1u);
  DDS3EFFECT_RAND_FA(radius_s_r);
  sub_854710(&p, 2u);
  sub_854930(&v8->fields, 2u);
  basic = (*pSphereSmoke)->basic;
  v11 = *&basic->rot.m00;
  v12 = *&basic->rot.m20;
  v13 = *&basic->rot.m21;
  *&v27.m01 = *&basic->rot.m01;
  *&v27.m21 = v13;
  *&v27.m00 = v11;
  *&v27.m20 = v12;
  v14 = *&basic->rot.m02;
  v15 = *&basic->rot.m22;
  v17 = *&basic->rot.m03;
  v16 = *&basic->rot.m23;
  *&v27.m03 = v17;
  *&v27.m23 = v16;
  *&v27.m02 = v14;
  *&v27.m22 = v15;
  SDF_VU0__LOADMATRIX(&v27);
  SDF_VU0__LOADVECTOR(v8->pos);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__STOREVECTOR(&v8->pos);
  sub_854710(&v8->fields, 0);
  sub_854710(&(*pSphereSmoke)->basic->fields, 0);
  sub_854930(&v8->fields, 0);
  sub_854710(&v8->fields, 1u);
  sub_854710(&(*pSphereSmoke)->basic->fields, 1u);
  sub_854930(&v8->fields, 1u);
  sub_854710(&v8->fields, 2u);
  sub_854710(&(*pSphereSmoke)->basic->fields, 2u);
  sub_854930(&v8->fields, 2u);
  DDS3EFFECT_RAND_PM();
  sub_854930(&v8->dir, 0);
  v18 = 0.0;
  sub_854930(&v8->dir, 1u);
  DDS3EFFECT_RAND_PM();
  sub_854930(&v8->dir, 2u);
  SDF_VU0__LOADVECTOR(v8->dir);
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v8->dir);
  DDS3EFFECT_RAND_FA((*pSphereSmoke)->ampli_r, 0);
  sub_854930(&v8->val_f, 0);
  sub_854930(&v8->val_f, 1u);
  sub_854930(&v8->val_f, 2u);
  DDS3EFFECT_RAND_FA((*pSphereSmoke)->up_s_r, 0);
  sub_854930(&v8->val_f, 3u);
  v8->frame = ~(sdfGetRand(&ParRand)
                     % ((*pSphereSmoke)->timing + 1LL));
  v8->color = 0;
  v20 = (*pSphereSmoke)->basic;
  scl_r = v20->exp->scl_r;
  sub_854710(&v20->scale, 0);
  v8->scale = v22 * DDS3EFFECT_RAND_FA(scl_r);
  rot_r = (*pSphereSmoke)->basic->exp->rot_r;
  if (rot_r != 0.0)
  {
    v18 = DDS3EFFECT_RAND_FA(rot_r) * 6.2832;
  }
  v8->rot = v18;
  p_effect = &(*pSphereSmoke)->basic->effect;
  dds3Particle_EffectReset(p_effect, number);
}

// 0x1126910
dds3Particle_Basic_t *dds3Particle_SphereSmokeCreate(void *hData, s32 bPos, bool pCopy, s32 billno) {
  u64 *v8;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  dds3Particle_SphereSmoke_t3_o *pSphereSmoke;
  Il2CppClass *v16;
  s64 *Interface;
  char *v18;
  s64 *v19;
  dds3Particle_Basic_t_o *dst;
  Il2CppObject *hDataa;
  u64 v24[2];
  char *v25;
  s32 bpos;

  bpos = bPos;
  dst = 0;
  hDataa = 0;
  if (pCopy)
  {
    v8 = Allocate(dds3Particle_Basic_t);
    dds3Particle_Basic_t___ctor(v8);
    dst = v8;
    if (hData)
    {
      klass = hData->klass;
      if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v24);
        if ((v24[0] & 1) != 0)
          v11 = v25;
        else
          v11 = v24 + 1;
        v12 = sub_8C4940(v11);
      }
    }
    dds3Particle_Basic_t__dCopy(hData, &dst);
    pSphereSmoke = dst->pSphereSmoke;
  }
  else
  {
    pSphereSmoke = Allocate(dds3Particle_SphereSmoke_t3);
    dds3Particle_SphereSmoke_t3___ctor(pSphereSmoke);
    if (hData)
    {
      Interface = QueryInterface(hData, byte);
      if (!Interface)
      {
        sub_8FC2C0(hData->klass->_1.element_class, v16, v24);
        if ((v24[0] & 1) != 0)
          v18 = v25;
        else
          v18 = v24 + 1;
        v19 = sub_8C4940(v18);
      }
    }
    else
    {
      Interface = 0;
    }
    dds3Particle_SphereSmoke_t3__pCopy(pSphereSmoke, Interface, &bpos);
    if (billno == -1)
      pSphereSmoke->basic->billno = -1;
  }
  dds3Particle_BasicCreate(&pSphereSmoke->basic, pCopy);
  dst = pSphereSmoke->basic;
  hDataa = dst;
  dst->pSphereSmoke = pSphereSmoke;
  dds3Particle_SphereSmokeAllBuffInit(&hDataa);
  return dst;
}

// 0x1126b60
void dds3Particle_SphereSmokeDelete(void **hData) {
  dds3Particle_Basic_t_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3Particle_Basic_t_o *v6;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  v6 = *((*hData)[19].monitor + 2);
  dds3Particle_BasicDelete(v6, v3);
}

// 0x1127190
void dds3Particle_SphereSmokeDraw(void **hData) {
  dds3Particle_Basic_t_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3Particle_SphereSmoke_t3_o *monitor;
  struct dds3Particle_Basic_t_o *basic;
  dds3Particle_Effect_t_o *effect;
  s32 type;
  f32 eff_scl_raito;
  struct dds3Particle_Basic_t_o *v11;
  s64 v12;
  s64 v13;
  s64 v14;
  s64 v15;
  s64 v16;
  s64 v17;
  s64 v18;
  s64 v19;
  struct dds3Particle_Basic_t_o *v22;
  s64 v23;
  u64 v24;
  s32 v25;
  struct dds3Particle_Physics_t_o *hPhysics;
  struct parPhysics_t_array *pPhysics;
  parPhysics_t_o *v30;
  s32 v31;
  dds3ParticleColorAnim_t_o *color;
  u32 v33;
  u32 abgr;
  f32 v36;
  f32 v37;
  dds3Particle_Effect_t_o **p_effect;
  f32 scale;
  u32 v42;
  s32 v43;
  s32 v44;
  dds3Particle_Effect_t_o **v46;
  char *v47;
  s64 *v48;
  s64 number;
  s32 loop;
  s32 frame;
  UnityEngine_Matrix4x4_o v52;
  UnityEngine_Vector4_o p;
  dds3Particle_SphereSmoke_t3_o *v54[4];
  dds3Particle_SphereSmoke_t3_o *pSphereSmoke;

  pSphereSmoke = 0;
  *&p.x = 0;
  *&p.z = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v54);
    if ((v54[0] & 1) != 0)
      v47 = v54[2];
    else
      v47 = v54 + 1;
    v48 = sub_8C4940(v47);
  }
  monitor = (*hData)[19].monitor;
  pSphereSmoke = monitor;
  *&p.x = 0;
  *&p.z = 0;
  basic = monitor->basic;
  effect = basic->effect;
  type = effect->type;
  eff_scl_raito = basic->eff_scl_raito;
  dds3Particle_EffectInit(effect, eff_scl_raito, v3);
  v11 = monitor->basic;
  v12 = *&v11->rot.m00;
  v13 = *&v11->rot.m20;
  v14 = *&v11->rot.m21;
  *&v52.m01 = *&v11->rot.m01;
  *&v52.m21 = v14;
  *&v52.m00 = v12;
  *&v52.m20 = v13;
  v15 = *&v11->rot.m02;
  v16 = *&v11->rot.m22;
  v18 = *&v11->rot.m03;
  v17 = *&v11->rot.m23;
  *&v52.m03 = v18;
  *&v52.m23 = v17;
  *&v52.m02 = v15;
  *&v52.m22 = v16;
  SDF_VU0__LOADMATRIX(&v52);
  v22 = monitor->basic;
  number = v22->number;
  if (v22->number >= 1)
  {
    frame = v22->frame;
    loop = monitor->loop;
    v23 = number - 1;
    v24 = 0;
    v25 = 0;
    hPhysics = v22->hPhysics;
      goto LABEL_12;
    while (1)
    {
LABEL_13:
      pPhysics = hPhysics->pPhysics;
      if (v24 >= LODWORD(pPhysics->max_length))
      {
LABEL_14:
      }
      while (1)
      {
        v30 = pPhysics->m_Items[v24];
        v31 = v30->frame;
        if (v31 == -268435455)
        {
          dds3Particle_SphereSmokeBuffInit(&pSphereSmoke, v24);
          v31 = v30->frame;
        }
        if ((v31 & 0x80000000) == 0)
        {
          color = monitor->basic->color;
          v33 = dds3ParticleColorAnim(color, v19, v31);
          v30->color = v33;
          abgr = monitor->basic->abgr;
          SDF_VU0__dds3ColorItoF(v33);
          SDF_VU0__COPYVECTOR_A_TO_B();
          SDF_VU0__dds3ColorItoF(abgr);
          SDF_VU0__MULVECTOR();
          v30->color = SDF_VU0__dds3ColorFtoI(128.0);
          if (type)
            SDF_VU0__LOADVECTOR_C(v30->pos);
          sub_854710(&v30->val_f, 0);
          sub_854930(&v30->val_f, 0);
          sub_854710(&v30->val_f, 1u);
          sub_854930(&v30->val_f, 1u);
          sub_854710(&v30->val_f, 3u);
          sub_854710(&v30->val_f, 1u);
          v37 = v36;
          sdfSin(v37);
          sub_854710(&v30->val_f, 2u);
          sub_854930(&v30->val_f, 2u);
          sub_854710(&v30->val_f, 0);
          sub_854710(&v30->dir, 0);
          sub_854930(&p, 0);
          sub_854930(&p, 1u);
          sub_854710(&v30->dir, 2u);
          sub_854930(&p, 2u);
          SDF_VU0__LOADVECTOR(p);
          SDF_VU0__APPLYMATRIX();
          SDF_VU0__STOREVECTOR(&p);
          sub_854710(&v30->fields, 0);
          sub_854710(&p, 0);
          sub_854930(&v30->fields, 0);
          sub_854710(&v30->fields, 1u);
          sub_854710(&p, 1u);
          sub_854930(&v30->fields, 1u);
          sub_854710(&v30->fields, 2u);
          sub_854710(&p, 2u);
          sub_854930(&v30->fields, 2u);
          sub_854930(&v30->val_f, 3u);
          if (type)
          {
            SDF_VU0__LOADVECTOR(v30->pos);
            p_effect = &monitor->basic->effect;
            scale = v30->scale;
            v42 = v30->color;
            dds3Particle_EffectSet(p_effect, v24, v42, scale);
          }
        }
        v43 = v31 + 1;
        v44 = v31 + 1 < frame ? v31 + 1 : -268435455;
        if (v43 >= frame && loop == 0)
        {
          v46 = &monitor->basic->effect;
          dds3Particle_EffectReset(v46, v24);
          if (++v25 >= number)
            monitor->basic->state = 0;
          v30->frame = v43;
          if (v23 == v24)
            return;
        }
        else
        {
          v30->frame = v44;
          if (v23 == v24)
            return;
        }
        ++v24;
        hPhysics = monitor->basic->hPhysics;
          goto LABEL_13;
LABEL_12:
          break;
        pPhysics = hPhysics->pPhysics;
        if (v24 >= LODWORD(pPhysics->max_length))
          goto LABEL_14;
      }
    }
  }
}

// 0x1126770
void dds3Particle_SphereSmokeSetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  void *monitor;
  s64 v8;
  s64 v9;
  s64 v10;
  f32 v11;
  f32 v12;
  char *v13;
  s64 *v14;
  u64 v15[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v15);
    if ((v15[0] & 1) != 0)
      v13 = v15[2];
    else
      v13 = v15 + 1;
    v14 = sub_8C4940(v13);
  }
  monitor = (*hData)[19].monitor;
  if (monitor)
  {
    v8 = *(monitor + 2) + 32LL;
    sub_854710(v8, 0);
    sub_854930(v8, 0);
    v9 = *(monitor + 2) + 32LL;
    sub_854710(v9, 1u);
    sub_854930(v9, 1u);
    v10 = *(monitor + 2) + 32LL;
    sub_854710(v10, 2u);
    sub_854930(v10, 2u);
    v11 = *(monitor + 9) * scale;
    v12 = *(monitor + 11);
    *(monitor + 8) = *(monitor + 8) * scale;
    *(monitor + 9) = v11;
    *(monitor + 11) = v12 * scale;
  }
}

// 0x112e830
void dds3Particle_SphereSpiral2AllBuffInit(void **hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v6;
  const char *name;
  u64 v8;
  s64 v9;
  s64 v10;
  s64 v12;
  char *v13;
  s64 *v14;
  u64 v15[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v15);
    if ((v15[0] & 1) != 0)
      v13 = v15[2];
    else
      v13 = v15 + 1;
    v14 = sub_8C4940(v13);
  }
  v6 = (*hData)[23].klass;
  name = v6->_1.name;
  if (*(name + 12))
  {
    v8 = 0;
    do
    {
      v10 = *(name + 23);
      else
      {
        v9 = *(v10 + 24);
        if (v8 >= *(v9 + 24))
        {
LABEL_12:
        }
      }
      v12 = v9 + 8 * v8++;
      *(*(v12 + 32) + 48LL) = -268435455;
      name = v6->_1.name;
    }
    while (v8 < *(name + 12));
  }
}

// 0x112f0d0
void dds3Particle_SphereSpiral2BuffInit(dds3Particle_SphereSpiral2_t3 **pSphereSpiral2, s32 number) {
  struct dds3Particle_Physics_t_o *hPhysics;
  struct parPhysics_t_array *pPhysics;
  parPhysics_t_o *v8;
  u32 Rand;
  s64 v11;
  f32 radius_s_r;
  struct dds3Particle_Basic_t_o *basic;
  s64 v14;
  s64 v15;
  s64 v16;
  s64 v17;
  s64 v18;
  s64 v19;
  s64 v20;
  s64 p_val_f;
  f32 radius_e_r;
  struct dds3Particle_Basic_t_o *v25;
  f32 scl_r;
  f32 v27;
  f32 rot_r;
  f32 v31;
  dds3Particle_Effect_t_o **p_effect;
  UnityEngine_Matrix4x4_o v33;
  UnityEngine_Vector4_o p;

  *&p.x = 0;
  *&p.z = 0;
  hPhysics = (*pSphereSpiral2)->basic->hPhysics;
  pPhysics = hPhysics->pPhysics;
  v8 = pPhysics->m_Items[number];
  v8->color = 0;
  Rand = sdfGetRand(&ParRand);
  v11 = (*pSphereSpiral2)->timing + 1LL;
  v8->frame = Rand / v11 * v11 - Rand;
  radius_s_r = (*pSphereSpiral2)->radius_s_r;
  DDS3EFFECT_RAND_PM();
  sub_854930(&p, 0);
  DDS3EFFECT_RAND_PM();
  sub_854930(&p, 1u);
  DDS3EFFECT_RAND_PM();
  sub_854930(&p, 2u);
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&p);
  DDS3EFFECT_RAND_FA(radius_s_r);
  sub_854710(&p, 0);
  sub_854930(&v8->dir, 0);
  DDS3EFFECT_RAND_FA(radius_s_r);
  sub_854710(&p, 1u);
  sub_854930(&v8->dir, 1u);
  DDS3EFFECT_RAND_FA(radius_s_r);
  sub_854710(&p, 2u);
  sub_854930(&v8->dir, 2u);
  SDF_VU0__LOADVECTOR(v8->dir);
  SDF_VU0__GETLENGTH();
  basic = (*pSphereSpiral2)->basic;
  v14 = *&basic->rot.m00;
  v15 = *&basic->rot.m20;
  v16 = *&basic->rot.m21;
  *&v33.m01 = *&basic->rot.m01;
  *&v33.m21 = v16;
  *&v33.m00 = v14;
  *&v33.m20 = v15;
  v17 = *&basic->rot.m02;
  v18 = *&basic->rot.m22;
  v20 = *&basic->rot.m03;
  v19 = *&basic->rot.m23;
  *&v33.m03 = v20;
  *&v33.m23 = v19;
  *&v33.m02 = v17;
  *&v33.m22 = v18;
  SDF_VU0__LOADMATRIX(&v33);
  SDF_VU0__LOADVECTOR(v8->dir);
  SDF_VU0__APPLYMATRIX_XYZ();
  SDF_VU0__STOREVECTOR(&v8->dir);
  sub_854710(&v8->dir, 0);
  sub_854710(&(*pSphereSpiral2)->basic->fields, 0);
  sub_854930(&v8->fields, 0);
  sub_854710(&v8->dir, 1u);
  sub_854710(&(*pSphereSpiral2)->basic->fields, 1u);
  sub_854930(&v8->fields, 1u);
  sub_854710(&v8->dir, 2u);
  sub_854710(&(*pSphereSpiral2)->basic->fields, 2u);
  sub_854930(&v8->fields, 2u);
  if ((*pSphereSpiral2)->type == 1)
  {
    DDS3EFFECT_RAND_PM();
    sub_854930(&p, 0);
    DDS3EFFECT_RAND_PM();
    sub_854930(&p, 1u);
    DDS3EFFECT_RAND_PM();
    sub_854930(&p, 2u);
    SDF_VU0__LOADVECTOR(p);
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(&p);
    p_val_f = &v8->val_f;
    sub_854710(&p, 0);
    sub_854930(&v8->val_f, 0);
    sub_854710(&p, 1u);
    sub_854930(&v8->val_f, 1u);
    sub_854710(&p, 2u);
  }
  else
  {
    p_val_f = &v8->val_f;
    sub_854930(&v8->val_f, 0);
    sub_854930(&v8->val_f, 1u);
  }
  sub_854930(p_val_f, 2u);
  radius_e_r = (*pSphereSpiral2)->radius_e_r;
  DDS3EFFECT_RAND_FA(radius_e_r);
  sub_854930(&v8->val_f, 3u);
  v25 = (*pSphereSpiral2)->basic;
  scl_r = v25->exp->scl_r;
  sub_854710(&v25->scale, 0);
  v8->scale = v27 * DDS3EFFECT_RAND_FA(scl_r);
  rot_r = (*pSphereSpiral2)->basic->exp->rot_r;
  if (rot_r == 0.0)
  {
    v31 = 0.0;
  }
  else
  {
    v31 = DDS3EFFECT_RAND_FA(rot_r) * 6.2832;
  }
  v8->rot = v31;
  p_effect = &(*pSphereSpiral2)->basic->effect;
  dds3Particle_EffectReset(p_effect, number);
}

// 0x112eb50
dds3Particle_Basic_t *dds3Particle_SphereSpiral2Create(void *hData, s32 bPos, bool pCopy, s32 billno) {
  u64 *v8;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  dds3Particle_SphereSpiral2_t3_o *v15;
  Il2CppClass *v16;
  s64 *Interface;
  char *v18;
  s64 *v19;
  dds3Particle_SphereSpiral2_t3_Fields *p_fields;
  struct dds3Particle_Effect_t_o *effect;
  u64 number;
  u16 *blur;
  u64 v25;
  dds3ParOffsetBuff_t_o *v26;
  struct dds3ParOffsetBuff_t_o *OffBuff;
  s64 v28;
  s64 v29;
  u64 v31;
  u32 *pParts;
  u64 *v33;
  struct dds3ParOffsetBuffParts_t_array *v35;
  struct dds3ParOffsetBuffParts_t_array *v37;
  struct dds3ParOffsetBuffParts_t_array *v39;
  s64 v41;
  Il2CppObject *basic;
  Il2CppObject *hDataa;
  s32 bpos;
  u64 v46[2];
  char *v47;

  bpos = bPos;
  basic = 0;
  hDataa = 0;
  if (pCopy)
  {
    v8 = Allocate(dds3Particle_Basic_t);
    dds3Particle_Basic_t___ctor(v8);
    basic = v8;
    if (hData)
    {
      klass = hData->klass;
      if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v46);
        if ((v46[0] & 1) != 0)
          v11 = v47;
        else
          v11 = v46 + 1;
        v12 = sub_8C4940(v11);
      }
    }
    dds3Particle_Basic_t__dCopy(hData, &basic);
    v15 = basic[23].klass;
  }
  else
  {
    v15 = Allocate(dds3Particle_SphereSpiral2_t3);
    dds3Particle_SphereSpiral2_t3___ctor(v15);
    if (hData)
    {
      Interface = QueryInterface(hData, byte);
      if (!Interface)
      {
        sub_8FC2C0(hData->klass->_1.element_class, v16, v46);
        if ((v46[0] & 1) != 0)
          v18 = v47;
        else
          v18 = v46 + 1;
        v19 = sub_8C4940(v18);
      }
    }
    else
    {
      Interface = 0;
    }
    dds3Particle_SphereSpiral2_t3__pCopy(v15, Interface, &bpos);
    if (billno == -1)
      v15->basic->billno = -1;
  }
  p_fields = &v15->fields;
  dds3Particle_BasicCreate(&v15->basic, pCopy);
  effect = p_fields->basic->effect;
  if (effect->type)
  {
    number = p_fields->basic->number;
    switch (effect->type)
    {
      case 1u:
        blur = effect->param->blur;
        goto LABEL_32;
      case 2u:
        blur = effect->param->track;
        goto LABEL_32;
      case 3u:
        blur = effect->param->track2;
        goto LABEL_32;
      case 4u:
        blur = effect->param->track3;
LABEL_32:
        v25 = blur[8];
        break;
      default:
        v25 = 0;
        break;
    }
    v26 = Allocate(dds3ParOffsetBuff_t);
    dds3ParOffsetBuff_t___ctor(v26);
    v15->OffBuff = v26;
    v26->length = v25;
    OffBuff = v15->OffBuff;
    OffBuff->pParts = NewSpecific(dds3ParOffsetBuffParts_t, number);
    if (number >= 1)
    {
      v28 = 4;
      v29 = -number;
      do
      {
        v31 = v28 - 4;
        pParts = v15->OffBuff->pParts;
        v33 = Allocate(dds3ParOffsetBuffParts_t);
        dds3ParOffsetBuffParts_t___ctor(v33);
        *&pParts[2 * v28] = v33;
        v35 = v15->OffBuff->pParts;
        *(*(&v35->obj.klass + v28) + 16LL) = 0;
        v37 = v15->OffBuff->pParts;
        *(*(&v37->obj.klass + v28) + 20LL) = 0;
        v39 = v15->OffBuff->pParts;
        v41 = *(&v39->obj.klass + v28++);
        *(v41 + 24) = NewSpecific(UnityEngine_Vector3, v25);
      }
      while (v29 + v28 != 4);
    }
  }
  else
  {
    v15->OffBuff->hMem = 0;
  }
  basic = v15->basic;
  hDataa = basic;
  basic[23].klass = v15;
  dds3Particle_SphereSpiral2AllBuffInit(&hDataa);
  return basic;
}

// 0x112efc0
void dds3Particle_SphereSpiral2Delete(void **hData) {
  dds3Particle_Basic_t_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3Particle_Basic_t_o *name;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  name = (*hData)[23].klass->_1.name;
  dds3Particle_BasicDelete(name, v3);
}

// 0x112f6c0
void dds3Particle_SphereSpiral2Draw(void **hData) {
  dds3Particle_Basic_t_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3Particle_SphereSpiral2_t3_o *v6;
  struct dds3Particle_Basic_t_o *basic;
  dds3Particle_Effect_t_o *effect;
  s32 type;
  f32 eff_scl_raito;
  struct dds3Particle_Basic_t_o *v11;
  s64 v12;
  s64 v13;
  s64 v14;
  s64 v15;
  s64 v16;
  s64 v17;
  s64 v18;
  struct dds3Particle_Basic_t_o *v19;
  f32 roll_s;
  s64 number;
  s64 v22;
  f32 v25;
  u64 v26;
  s64 v27;
  dds3TrackPoly_t_o **v28;
  s64 v29;
  dds3ParOffsetBuff_t_o *v30;
  s32 v32;
  dds3ParOffsetBuff_t_o *v33;
  s64 v34;
  s64 v35;
  dds3TrackPoly_t_o **p_hTrackPoly;
  struct dds3ParOffsetBuff_t_o *OffBuff;
  struct dds3ParOffsetBuffParts_t_array *pParts;
  struct dds3Particle_Physics_t_o *hPhysics;
  struct parPhysics_t_array *pPhysics;
  parPhysics_t_o *v43;
  s32 v44;
  dds3ParticleColorAnim_t_o *color;
  u32 v46;
  u32 abgr;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  u32 v53;
  s32 v54;
  u8 color_high;
  s64 point;
  struct UnityEngine_Vector3_array *pPosBuff;
  f32 v58;
  struct UnityEngine_Vector3_array *v60;
  f32 v61;
  struct UnityEngine_Vector3_array *v63;
  f32 v64;
  u32 v66;
  s64 count;
  u32 v68;
  u32 v69;
  struct dds3Particle_Effect_t_o *v70;
  s32 v71;
  s64 v72;
  f32 scale;
  s64 v74;
  dds3Particle_BlurBuff_t_o **p_hBlur;
  u32 v76;
  dds3ParOffsetBuff_t_o *v77;
  dds3Particle_Effect_t_o **p_effect;
  char *v79;
  s64 *v80;
  s64 p_old_pos;
  s32 v82;
  s64 length;
  s32 loop;
  s32 frame;
  s64 v86;
  dds3ParOffsetBuffParts_t_o *v87;
  UnityEngine_Matrix4x4_o v88;
  UnityEngine_Vector4_o v89;
  UnityEngine_Vector4_o p;
  s64 v91;
  s64 v92;
  UnityEngine_Vector4_o dst;
  dds3Particle_SphereSpiral2_t3_o *pSphereSpiral2;
  u64 v95[4];
  UnityEngine_Vector4_o v96;
  UnityEngine_Vector4_o v97;
  UnityEngine_Vector4_o v98;
  UnityEngine_Vector4_o v99;

  *&dst.z = 0;
  pSphereSpiral2 = 0;
  v92 = 0;
  *&dst.x = 0;
  *&v89.x = 0;
  *&p.z = 0;
  v91 = 0;
  *&v89.z = 0;
  *&p.x = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v95);
    if ((v95[0] & 1) != 0)
      v79 = v95[2];
    else
      v79 = v95 + 1;
    v80 = sub_8C4940(v79);
  }
  v6 = (*hData)[23].klass;
  *&dst.z = 0;
  pSphereSpiral2 = v6;
  v92 = 0;
  *&dst.x = 0;
  *&v89.x = 0;
  *&p.z = 0;
  v91 = 0;
  *&v89.z = 0;
  *&p.x = 0;
  length = v6->OffBuff->length;
  basic = v6->basic;
  effect = basic->effect;
  type = effect->type;
  eff_scl_raito = basic->eff_scl_raito;
  dds3Particle_EffectInit(effect, eff_scl_raito, v3);
  v11 = v6->basic;
  v12 = *&v11->rot.m00;
  v13 = *&v11->rot.m20;
  v14 = *&v11->rot.m21;
  *&v88.m01 = *&v11->rot.m01;
  *&v88.m21 = v14;
  *&v88.m00 = v12;
  *&v88.m20 = v13;
  v15 = *&v11->rot.m02;
  v16 = *&v11->rot.m22;
  v18 = *&v11->rot.m03;
  v17 = *&v11->rot.m23;
  *&v88.m03 = v18;
  *&v88.m23 = v17;
  *&v88.m02 = v15;
  *&v88.m22 = v16;
  SDF_VU0__LOADMATRIX_B(&v88);
  v19 = v6->basic;
  frame = v19->frame;
  loop = v6->loop;
  roll_s = v6->roll_s;
  number = v19->number;
  SDF_VU0__COPYVECTOR(&dst, v19->pos);
  sub_854710(&v6->old_pos, 0);
  sub_854930(&v91, 0);
  sub_854710(&v6->old_pos, 1u);
  sub_854930(&v91, 1u);
  p_old_pos = &v6->old_pos;
  sub_854710(&v6->old_pos, 2u);
  sub_854930(&v91, 2u);
  sub_854930(&v91, 3u);
  v86 = number;
  if (number >= 1)
  {
    v25 = roll_s * 0.017453;
    v26 = 0;
    v87 = 0;
    v82 = 0;
    do
    {
      OffBuff = v6->OffBuff;
      if (OffBuff)
      {
        pParts = OffBuff->pParts;
        if (pParts)
        {
          v87 = pParts->m_Items[v26];
        }
      }
      hPhysics = v6->basic->hPhysics;
      else
      {
        pPhysics = hPhysics->pPhysics;
        if (v26 >= LODWORD(pPhysics->max_length))
          goto LABEL_28;
      }
      v43 = pPhysics->m_Items[v26];
      v44 = v43->frame;
      if (v44 == -268435455)
      {
        dds3Particle_SphereSpiral2BuffInit(&pSphereSpiral2, v26);
        v44 = v43->frame;
      }
      if (v44 < 0)
        goto LABEL_62;
      color = v6->basic->color;
      v46 = dds3ParticleColorAnim(color, v22, v44);
      v43->color = v46;
      abgr = v6->basic->abgr;
      SDF_VU0__dds3ColorItoF(v46);
      SDF_VU0__COPYVECTOR_A_TO_B();
      SDF_VU0__dds3ColorItoF(abgr);
      SDF_VU0__MULVECTOR();
      v43->color = SDF_VU0__dds3ColorFtoI(128.0);
      if (type)
        SDF_VU0__LOADVECTOR_C(v43->dir);
      SDF_VU0__LOADVECTOR(v43->dir);
      SDF_VU0__GETLENGTH();
      sub_854710(&v43->val_f, 3u);
      sub_854930(&v89, 0);
      sub_854710(&v89, 0);
      sub_854930(&v89, 1u);
      sub_854930(&v89, 2u);
      SDF_VU0__NORMALIZE();
      SDF_VU0__LOADVECTOR_B(v89);
      SDF_VU0__MULVECTOR();
      SDF_VU0__STOREVECTOR(&v43->dir);
      SDF_VU0__COPYMATRIX_B_TO_A();
      sub_854710(&v43->val_f, 0);
      sub_854930(&p, 0);
      sub_854710(&v43->val_f, 1u);
      sub_854930(&p, 1u);
      sub_854710(&v43->val_f, 2u);
      sub_854930(&p, 2u);
      sub_854930(&p, 3u);
      SDF_VU0__LOADVECTOR(p);
      SDF_VU0__APPLYMATRIX_XYZ();
      SDF_VU0__STOREVECTOR(&p);
      x = p.x;
      y = p.y;
      z = p.z;
      w = p.w;
      v99.x = x;
      v99.y = y;
      v99.z = z;
      v99.w = w;
      SetRotateMatrixAxis(v25, v99);
      SDF_VU0__LOADVECTOR(v43->dir);
      SDF_VU0__APPLYMATRIX_XYZ();
      SDF_VU0__LOADVECTOR_B(dst);
      SDF_VU0__STOREVECTOR(&v43->dir);
      SDF_VU0__ADDVECTOR();
      SDF_VU0__STOREVECTOR(&v43->pos);
      if (!type)
        goto LABEL_62;
      v53 = v6->basic->abgr;
      v54 = type;
      color_high = HIBYTE(v43->color);
      point = v87->point;
      pPosBuff = v87->pPosBuff;
      sub_854710(&v43->dir, 0);
      sub_8529B0(&pPosBuff->m_Items[point], 0, v58);
      v60 = v87->pPosBuff;
      sub_854710(&v43->dir, 1u);
      sub_8529B0(&v60->m_Items[point], 1, v61);
      v63 = v87->pPosBuff;
      sub_854710(&v43->dir, 2u);
      v66 = v53 & 0xFFFFFF | (color_high << 24);
      sub_8529B0(&v63->m_Items[point], 2, v64);
      v68 = v87->point;
      count = v87->count;
      if (v68 + 1 < length)
        v69 = v68 + 1;
      else
        v69 = 0;
      v87->point = v69;
      if (count < length)
        v87->count = count + 1;
      v70 = v6->basic->effect;
      v71 = v70->type;
      type = v54;
      if (v71 == 3)
      {
        v33 = v6->OffBuff;
        v34 = v91;
        v35 = v92;
        p_hTrackPoly = &v70->param->track2->hTrackPoly;
        *&v97.x = v34;
        *&v97.z = v35;
        dds3Particle_Track2SetExp(p_hTrackPoly, v26, v97, v66, v33);
        v32 = v44 + 1;
        if (v44 + 1 < frame)
          goto LABEL_75;
      }
      else
      {
        if (v71 != 2)
        {
          if (v71 == 1)
          {
            v72 = v91;
            scale = v43->scale;
            v74 = v92;
            p_hBlur = &v70->param->blur->hBlur;
            v76 = v43->color;
            v77 = v6->OffBuff;
            *&v98.x = v72;
            *&v98.z = v74;
            dds3Particle_BlurSetExp(p_hBlur, v26, v98, v76, v77, scale);
          }
LABEL_62:
          v32 = v44 + 1;
          if (v44 + 1 < frame)
            goto LABEL_75;
          goto LABEL_63;
        }
        v27 = v91;
        v28 = &v70->param->track->hTrackPoly;
        v29 = v92;
        v30 = v6->OffBuff;
        *&v96.x = v27;
        *&v96.z = v29;
        dds3Particle_TrackSetExp(v28, v26, v96, v66, v30);
        v32 = v44 + 1;
        if (v44 + 1 < frame)
          goto LABEL_75;
      }
LABEL_63:
      if (loop)
      {
        v32 = -268435455;
        if (!type)
          goto LABEL_75;
      }
      else
      {
        p_effect = &v6->basic->effect;
        dds3Particle_EffectReset(p_effect, v26);
        if (++v82 >= v86)
          v6->basic->state = 0;
        if (!type)
          goto LABEL_75;
      }
      *&v87->point = 0;
LABEL_75:
      ++v26;
      v43->frame = v32;
    }
    while (v86 != v26);
  }
  sub_854710(&dst, 0);
  sub_854930(p_old_pos, 0);
  sub_854710(&dst, 1u);
  sub_854930(p_old_pos, 1u);
  sub_854710(&dst, 2u);
  sub_854930(p_old_pos, 2u);
}

// 0x112e9c0
void dds3Particle_SphereSpiral2SetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v7;
  s64 v8;
  s64 v9;
  s64 v10;
  f32 v11;
  char *v12;
  s64 *v13;
  u64 v14[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v14);
    if ((v14[0] & 1) != 0)
      v12 = v14[2];
    else
      v12 = v14 + 1;
    v13 = sub_8C4940(v12);
  }
  v7 = (*hData)[23].klass;
  if (v7)
  {
    v8 = (v7->_1.name + 32);
    sub_854710(v8, 0);
    sub_854930(v8, 0);
    v9 = (v7->_1.name + 32);
    sub_854710(v9, 1u);
    sub_854930(v9, 1u);
    v10 = (v7->_1.name + 32);
    sub_854710(v10, 2u);
    sub_854930(v10, 2u);
    v11 = *&v7->_1.byval_arg.bits;
    *&v7->_1.byval_arg.data = *&v7->_1.byval_arg.data * scale;
    *&v7->_1.byval_arg.bits = v11 * scale;
  }
}

// 0x1125390
void dds3Particle_SphereSpiralAllBuffInit(void **hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v6;
  const char *name;
  u64 v8;
  s64 v9;
  s64 v10;
  s64 v12;
  char *v13;
  s64 *v14;
  u64 v15[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v15);
    if ((v15[0] & 1) != 0)
      v13 = v15[2];
    else
      v13 = v15 + 1;
    v14 = sub_8C4940(v13);
  }
  v6 = (*hData)[19].klass;
  name = v6->_1.name;
  if (*(name + 12))
  {
    v8 = 0;
    do
    {
      v10 = *(name + 23);
      else
      {
        v9 = *(v10 + 24);
        if (v8 >= *(v9 + 24))
        {
LABEL_12:
        }
      }
      v12 = v9 + 8 * v8++;
      *(*(v12 + 32) + 48LL) = -268435455;
      name = v6->_1.name;
    }
    while (v8 < *(name + 12));
  }
}

// 0x1125a10
void dds3Particle_SphereSpiralBuffInit(dds3Particle_SphereSpiral_t3 **pSphereSpiral, s32 number) {
  struct dds3Particle_Physics_t_o *hPhysics;
  struct parPhysics_t_array *pPhysics;
  parPhysics_t_o *v8;
  u32 Rand;
  s64 v11;
  f32 radius_s_r;
  struct dds3Particle_Basic_t_o *basic;
  s64 v14;
  s64 v15;
  s64 v16;
  s64 v17;
  s64 v18;
  s64 v19;
  s64 v20;
  s64 p_val_f;
  f32 radius_e_r;
  struct dds3Particle_Basic_t_o *v25;
  f32 scl_r;
  f32 v27;
  f32 rot_r;
  f32 v31;
  dds3Particle_Effect_t_o **p_effect;
  UnityEngine_Matrix4x4_o v33;
  UnityEngine_Vector4_o p;

  *&p.x = 0;
  *&p.z = 0;
  hPhysics = (*pSphereSpiral)->basic->hPhysics;
  pPhysics = hPhysics->pPhysics;
  v8 = pPhysics->m_Items[number];
  v8->color = 0;
  Rand = sdfGetRand(&ParRand);
  v11 = (*pSphereSpiral)->timing + 1LL;
  v8->frame = Rand / v11 * v11 - Rand;
  radius_s_r = (*pSphereSpiral)->radius_s_r;
  DDS3EFFECT_RAND_PM();
  sub_854930(&p, 0);
  DDS3EFFECT_RAND_PM();
  sub_854930(&p, 1u);
  DDS3EFFECT_RAND_PM();
  sub_854930(&p, 2u);
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&p);
  DDS3EFFECT_RAND_FA(radius_s_r);
  sub_854710(&p, 0);
  sub_854930(&v8->dir, 0);
  DDS3EFFECT_RAND_FA(radius_s_r);
  sub_854710(&p, 1u);
  sub_854930(&v8->dir, 1u);
  DDS3EFFECT_RAND_FA(radius_s_r);
  sub_854710(&p, 2u);
  sub_854930(&v8->dir, 2u);
  SDF_VU0__LOADVECTOR(v8->dir);
  SDF_VU0__GETLENGTH();
  basic = (*pSphereSpiral)->basic;
  v14 = *&basic->rot.m00;
  v15 = *&basic->rot.m20;
  v16 = *&basic->rot.m21;
  *&v33.m01 = *&basic->rot.m01;
  *&v33.m21 = v16;
  *&v33.m00 = v14;
  *&v33.m20 = v15;
  v17 = *&basic->rot.m02;
  v18 = *&basic->rot.m22;
  v20 = *&basic->rot.m03;
  v19 = *&basic->rot.m23;
  *&v33.m03 = v20;
  *&v33.m23 = v19;
  *&v33.m02 = v17;
  *&v33.m22 = v18;
  SDF_VU0__LOADMATRIX(&v33);
  SDF_VU0__LOADVECTOR(v8->dir);
  SDF_VU0__APPLYMATRIX_XYZ();
  SDF_VU0__STOREVECTOR(&v8->dir);
  sub_854710(&v8->dir, 0);
  sub_854710(&(*pSphereSpiral)->basic->fields, 0);
  sub_854930(&v8->fields, 0);
  sub_854710(&v8->dir, 1u);
  sub_854710(&(*pSphereSpiral)->basic->fields, 1u);
  sub_854930(&v8->fields, 1u);
  sub_854710(&v8->dir, 2u);
  sub_854710(&(*pSphereSpiral)->basic->fields, 2u);
  sub_854930(&v8->fields, 2u);
  if ((*pSphereSpiral)->type == 1)
  {
    DDS3EFFECT_RAND_PM();
    sub_854930(&p, 0);
    DDS3EFFECT_RAND_PM();
    sub_854930(&p, 1u);
    DDS3EFFECT_RAND_PM();
    sub_854930(&p, 2u);
    SDF_VU0__LOADVECTOR(p);
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(&p);
    p_val_f = &v8->val_f;
    sub_854710(&p, 0);
    sub_854930(&v8->val_f, 0);
    sub_854710(&p, 1u);
    sub_854930(&v8->val_f, 1u);
    sub_854710(&p, 2u);
  }
  else
  {
    p_val_f = &v8->val_f;
    sub_854930(&v8->val_f, 0);
    sub_854930(&v8->val_f, 1u);
  }
  sub_854930(p_val_f, 2u);
  radius_e_r = (*pSphereSpiral)->radius_e_r;
  DDS3EFFECT_RAND_FA(radius_e_r);
  sub_854930(&v8->val_f, 3u);
  v25 = (*pSphereSpiral)->basic;
  scl_r = v25->exp->scl_r;
  sub_854710(&v25->scale, 0);
  v8->scale = v27 * DDS3EFFECT_RAND_FA(scl_r);
  rot_r = (*pSphereSpiral)->basic->exp->rot_r;
  if (rot_r == 0.0)
  {
    v31 = 0.0;
  }
  else
  {
    v31 = DDS3EFFECT_RAND_FA(rot_r) * 6.2832;
  }
  v8->rot = v31;
  p_effect = &(*pSphereSpiral)->basic->effect;
  dds3Particle_EffectReset(p_effect, number);
}

// 0x11256b0
dds3Particle_Basic_t *dds3Particle_SphereSpiralCreate(void *hData, s32 bPos, bool pCopy, s32 billno) {
  u64 *v8;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  dds3Particle_SphereSpiral_t3_o *pSphereSpiral;
  Il2CppClass *v16;
  s64 *Interface;
  char *v18;
  s64 *v19;
  dds3Particle_Basic_t_o *dst;
  Il2CppObject *hDataa;
  u64 v24[2];
  char *v25;
  s32 bpos;

  bpos = bPos;
  dst = 0;
  hDataa = 0;
  if (pCopy)
  {
    v8 = Allocate(dds3Particle_Basic_t);
    dds3Particle_Basic_t___ctor(v8);
    dst = v8;
    if (hData)
    {
      klass = hData->klass;
      if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v24);
        if ((v24[0] & 1) != 0)
          v11 = v25;
        else
          v11 = v24 + 1;
        v12 = sub_8C4940(v11);
      }
    }
    dds3Particle_Basic_t__dCopy(hData, &dst);
    pSphereSpiral = dst->pSphereSpiral;
  }
  else
  {
    pSphereSpiral = Allocate(dds3Particle_SphereSpiral_t3);
    dds3Particle_SphereSpiral_t3___ctor(pSphereSpiral);
    if (hData)
    {
      Interface = QueryInterface(hData, byte);
      if (!Interface)
      {
        sub_8FC2C0(hData->klass->_1.element_class, v16, v24);
        if ((v24[0] & 1) != 0)
          v18 = v25;
        else
          v18 = v24 + 1;
        v19 = sub_8C4940(v18);
      }
    }
    else
    {
      Interface = 0;
    }
    dds3Particle_SphereSpiral_t3__pCopy(pSphereSpiral, Interface, &bpos);
    if (billno == -1)
      pSphereSpiral->basic->billno = -1;
  }
  dds3Particle_BasicCreate(&pSphereSpiral->basic, pCopy);
  dst = pSphereSpiral->basic;
  hDataa = dst;
  dst->pSphereSpiral = pSphereSpiral;
  dds3Particle_SphereSpiralAllBuffInit(&hDataa);
  return dst;
}

// 0x1125900
void dds3Particle_SphereSpiralDelete(void **hData) {
  dds3Particle_Basic_t_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3Particle_Basic_t_o *name;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  name = (*hData)[19].klass->_1.name;
  dds3Particle_BasicDelete(name, v3);
}

// 0x1126000
void dds3Particle_SphereSpiralDraw(void **hData) {
  dds3Particle_Basic_t_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3Particle_SphereSpiral_t3_o *v6;
  struct dds3Particle_Basic_t_o *basic;
  dds3Particle_Effect_t_o *effect;
  s32 type;
  f32 eff_scl_raito;
  struct dds3Particle_Basic_t_o *v11;
  s64 v12;
  s64 v13;
  s64 v14;
  s64 v15;
  s64 v16;
  s64 v17;
  s64 v18;
  struct dds3Particle_Basic_t_o *v19;
  f32 roll_s;
  s64 number;
  s64 v22;
  f32 v25;
  u64 v26;
  s32 v27;
  struct parPhysics_t_array *pPhysics;
  struct dds3Particle_Physics_t_o *hPhysics;
  parPhysics_t_o *v31;
  s32 v32;
  dds3ParticleColorAnim_t_o *color;
  u32 v34;
  u32 abgr;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  dds3Particle_Effect_t_o **p_effect;
  f32 scale;
  u32 v45;
  s32 v46;
  s32 v47;
  dds3Particle_Effect_t_o **v49;
  char *v50;
  s64 *v51;
  s32 loop;
  s32 frame;
  UnityEngine_Matrix4x4_o v54;
  UnityEngine_Vector4_o v55;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o dst;
  dds3Particle_SphereSpiral_t3_o *v58[4];
  dds3Particle_SphereSpiral_t3_o *pSphereSpiral;
  UnityEngine_Vector4_o v60;

  pSphereSpiral = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v55.x = 0;
  *&v55.z = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v58);
    if ((v58[0] & 1) != 0)
      v50 = v58[2];
    else
      v50 = v58 + 1;
    v51 = sub_8C4940(v50);
  }
  v6 = (*hData)[19].klass;
  pSphereSpiral = v6;
  *&dst.x = 0;
  *&dst.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v55.x = 0;
  *&v55.z = 0;
  basic = v6->basic;
  effect = basic->effect;
  type = effect->type;
  eff_scl_raito = basic->eff_scl_raito;
  dds3Particle_EffectInit(effect, eff_scl_raito, v3);
  v11 = v6->basic;
  v12 = *&v11->rot.m00;
  v13 = *&v11->rot.m20;
  v14 = *&v11->rot.m21;
  *&v54.m01 = *&v11->rot.m01;
  *&v54.m21 = v14;
  *&v54.m00 = v12;
  *&v54.m20 = v13;
  v15 = *&v11->rot.m02;
  v16 = *&v11->rot.m22;
  v18 = *&v11->rot.m03;
  v17 = *&v11->rot.m23;
  *&v54.m03 = v18;
  *&v54.m23 = v17;
  *&v54.m02 = v15;
  *&v54.m22 = v16;
  SDF_VU0__LOADMATRIX_B(&v54);
  v19 = v6->basic;
  frame = v19->frame;
  loop = v6->loop;
  roll_s = v6->roll_s;
  number = v19->number;
  SDF_VU0__COPYVECTOR(&dst, v19->pos);
  if (number >= 1)
  {
    v25 = roll_s * 0.017453;
    v26 = 0;
    v27 = 0;
    do
    {
      while (1)
      {
        hPhysics = v6->basic->hPhysics;
        else
        {
          pPhysics = hPhysics->pPhysics;
          if (v26 >= LODWORD(pPhysics->max_length))
          {
LABEL_15:
          }
        }
        v31 = pPhysics->m_Items[v26];
        v32 = v31->frame;
        if (v32 == -268435455)
        {
          dds3Particle_SphereSpiralBuffInit(&pSphereSpiral, v26);
          v32 = v31->frame;
        }
        if ((v32 & 0x80000000) == 0)
        {
          color = v6->basic->color;
          v34 = dds3ParticleColorAnim(color, v22, v32);
          v31->color = v34;
          abgr = v6->basic->abgr;
          SDF_VU0__dds3ColorItoF(v34);
          SDF_VU0__COPYVECTOR_A_TO_B();
          SDF_VU0__dds3ColorItoF(abgr);
          SDF_VU0__MULVECTOR();
          v31->color = SDF_VU0__dds3ColorFtoI(128.0);
          if (type)
            SDF_VU0__LOADVECTOR_C(v31->pos);
          SDF_VU0__LOADVECTOR(v31->dir);
          SDF_VU0__GETLENGTH();
          sub_854710(&v31->val_f, 3u);
          sub_854930(&v55, 0);
          sub_854710(&v55, 0);
          sub_854930(&v55, 1u);
          sub_854930(&v55, 2u);
          SDF_VU0__NORMALIZE();
          SDF_VU0__LOADVECTOR_B(v55);
          SDF_VU0__MULVECTOR();
          SDF_VU0__STOREVECTOR(&v31->dir);
          SDF_VU0__COPYMATRIX_B_TO_A();
          sub_854710(&v31->val_f, 0);
          sub_854930(&p, 0);
          sub_854710(&v31->val_f, 1u);
          sub_854930(&p, 1u);
          sub_854710(&v31->val_f, 2u);
          sub_854930(&p, 2u);
          sub_854930(&p, 3u);
          SDF_VU0__LOADVECTOR(p);
          SDF_VU0__APPLYMATRIX_XYZ();
          SDF_VU0__STOREVECTOR(&p);
          x = p.x;
          y = p.y;
          z = p.z;
          w = p.w;
          v60.x = x;
          v60.y = y;
          v60.z = z;
          v60.w = w;
          SetRotateMatrixAxis(v25, v60);
          SDF_VU0__LOADVECTOR(v31->dir);
          SDF_VU0__APPLYMATRIX_XYZ();
          SDF_VU0__LOADVECTOR_B(dst);
          SDF_VU0__STOREVECTOR(&v31->dir);
          SDF_VU0__ADDVECTOR();
          SDF_VU0__STOREVECTOR(&v31->pos);
          if (type)
          {
            SDF_VU0__LOADVECTOR(v31->pos);
            p_effect = &v6->basic->effect;
            scale = v31->scale;
            v45 = v31->color;
            dds3Particle_EffectSet(p_effect, v26, v45, scale);
          }
        }
        v46 = v32 + 1;
        v47 = v32 + 1 < frame ? v32 + 1 : -268435455;
        if (v46 >= frame && loop == 0)
          break;
        ++v26;
        v31->frame = v47;
        if (number == v26)
          return;
      }
      v49 = &v6->basic->effect;
      dds3Particle_EffectReset(v49, v26);
      if (++v27 >= number)
        v6->basic->state = 0;
      ++v26;
      v31->frame = v46;
    }
    while (number != v26);
  }
}

// 0x1125520
void dds3Particle_SphereSpiralSetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v7;
  s64 v8;
  s64 v9;
  s64 v10;
  f32 v11;
  char *v12;
  s64 *v13;
  u64 v14[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v14);
    if ((v14[0] & 1) != 0)
      v12 = v14[2];
    else
      v12 = v14 + 1;
    v13 = sub_8C4940(v12);
  }
  v7 = (*hData)[19].klass;
  if (v7)
  {
    v8 = (v7->_1.name + 32);
    sub_854710(v8, 0);
    sub_854930(v8, 0);
    v9 = (v7->_1.name + 32);
    sub_854710(v9, 1u);
    sub_854930(v9, 1u);
    v10 = (v7->_1.name + 32);
    sub_854710(v10, 2u);
    sub_854930(v10, 2u);
    v11 = *&v7->_1.byval_arg.bits;
    *&v7->_1.byval_arg.data = *&v7->_1.byval_arg.data * scale;
    *&v7->_1.byval_arg.bits = v11 * scale;
  }
}

// 0x111f8b0
void dds3Particle_SpiralAllBuffInit(void **hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v6;
  const char *name;
  u64 v8;
  s32 v9;
  s64 v10;
  s64 v11;
  s64 v13;
  char *v14;
  s64 *v15;
  u64 v16[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v16);
    if ((v16[0] & 1) != 0)
      v14 = v16[2];
    else
      v14 = v16 + 1;
    v15 = sub_8C4940(v14);
  }
  v6 = (*hData)[17].klass;
  name = v6->_1.name;
  if (*(name + 12))
  {
    v8 = 0;
    v9 = -268435455;
    do
    {
      while (1)
      {
        v11 = *(name + 23);
        else
        {
          v10 = *(v11 + 24);
          if (v8 >= *(v10 + 24))
          {
LABEL_14:
          }
        }
        v13 = v10 + 8 * v8++;
        *(*(v13 + 32) + 48LL) = v9;
        if (v8 % HIDWORD(v6->_1.byval_arg.data))
          break;
        v9 -= HIDWORD(v6->_1.namespaze);
        name = v6->_1.name;
        if (v8 >= *(name + 12))
          return;
      }
      name = v6->_1.name;
    }
    while (v8 < *(name + 12));
  }
}

// 0x111ff60
void dds3Particle_SpiralBuffInit(dds3Particle_Spiral_t3 **pSpiral, s32 number) {
  struct dds3Particle_Physics_t_o *hPhysics;
  struct parPhysics_t_array *pPhysics;
  parPhysics_t_o *v8;
  s64 simu_num;
  u32 v10;
  f32 v11;
  f32 v12;
  f32 v13;
  f32 radius_s_r;
  f32 v17;
  struct dds3Particle_Basic_t_o *basic;
  s64 v19;
  s64 v20;
  s64 v21;
  s64 v22;
  s64 v23;
  s64 v24;
  s64 v25;
  struct dds3Particle_Basic_t_o *v26;
  f32 scl_r;
  f32 v28;
  f32 rot_r;
  dds3Particle_Effect_t_o **p_effect;
  UnityEngine_Matrix4x4_o v33;

  hPhysics = (*pSpiral)->basic->hPhysics;
  pPhysics = hPhysics->pPhysics;
  v8 = pPhysics->m_Items[number];
  *&v8->frame = 0;
  simu_num = (*pSpiral)->simu_num;
  v10 = number % simu_num;
  if (v10)
  {
    v11 = simu_num;
    v12 = v10;
    v13 = (6.2832 / v11) * v12;
  }
  else
  {
    v13 = 0.0;
  }
  sub_854930(&v8->val_f, 0);
  radius_s_r = (*pSpiral)->radius_s_r;
  DDS3EFFECT_RAND_FA(radius_s_r);
  sub_854930(&v8->val_f, 1u);
  DDS3EFFECT_RAND_FA((*pSpiral)->radius_e_r, 0);
  sub_854930(&v8->dir, 0);
  sub_854930(&v8->val_f, 2u);
  sdfCos(v13);
  sub_854930(&v8->fields, 0);
  v17 = 0.0;
  sub_854930(&v8->fields, 1u);
  sdfSin(v13);
  sub_854930(&v8->fields, 2u);
  basic = (*pSpiral)->basic;
  v19 = *&basic->rot.m00;
  v20 = *&basic->rot.m20;
  v21 = *&basic->rot.m21;
  *&v33.m01 = *&basic->rot.m01;
  *&v33.m21 = v21;
  *&v33.m00 = v19;
  *&v33.m20 = v20;
  v22 = *&basic->rot.m02;
  v23 = *&basic->rot.m22;
  v25 = *&basic->rot.m03;
  v24 = *&basic->rot.m23;
  *&v33.m03 = v25;
  *&v33.m23 = v24;
  *&v33.m02 = v22;
  *&v33.m22 = v23;
  SDF_VU0__LOADMATRIX(&v33);
  SDF_VU0__LOADVECTOR(v8->pos);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__STOREVECTOR(&v8->pos);
  sub_854930(&v8->val_f, 3u);
  sub_854710(&v8->fields, 0);
  sub_854710(&(*pSpiral)->basic->fields, 0);
  sub_854930(&v8->fields, 0);
  sub_854710(&v8->fields, 1u);
  sub_854710(&(*pSpiral)->basic->fields, 1u);
  sub_854930(&v8->fields, 1u);
  sub_854710(&v8->fields, 2u);
  sub_854710(&(*pSpiral)->basic->fields, 2u);
  sub_854930(&v8->fields, 2u);
  v26 = (*pSpiral)->basic;
  scl_r = v26->exp->scl_r;
  sub_854710(&v26->scale, 0);
  v8->scale = v28 * DDS3EFFECT_RAND_FA(scl_r);
  rot_r = (*pSpiral)->basic->exp->rot_r;
  if (rot_r != 0.0)
  {
    v17 = DDS3EFFECT_RAND_FA(rot_r) * 6.2832;
  }
  v8->rot = v17;
  p_effect = &(*pSpiral)->basic->effect;
  dds3Particle_EffectReset(p_effect, number);
}

// 0x111fc00
dds3Particle_Basic_t *dds3Particle_SpiralCreate(void *hData, s32 bPos, bool pCopy, s32 billno) {
  u64 *v8;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  dds3Particle_Spiral_t3_o *pSpiral;
  Il2CppClass *v16;
  s64 *Interface;
  char *v18;
  s64 *v19;
  dds3Particle_Basic_t_o *dst;
  Il2CppObject *hDataa;
  u64 v24[2];
  char *v25;
  s32 bpos;

  bpos = bPos;
  dst = 0;
  hDataa = 0;
  if (pCopy)
  {
    v8 = Allocate(dds3Particle_Basic_t);
    dds3Particle_Basic_t___ctor(v8);
    dst = v8;
    if (hData)
    {
      klass = hData->klass;
      if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v24);
        if ((v24[0] & 1) != 0)
          v11 = v25;
        else
          v11 = v24 + 1;
        v12 = sub_8C4940(v11);
      }
    }
    dds3Particle_Basic_t__dCopy(hData, &dst);
    pSpiral = dst->pSpiral;
  }
  else
  {
    pSpiral = Allocate(dds3Particle_Spiral_t3);
    dds3Particle_Spiral_t3___ctor(pSpiral);
    if (hData)
    {
      Interface = QueryInterface(hData, byte);
      if (!Interface)
      {
        sub_8FC2C0(hData->klass->_1.element_class, v16, v24);
        if ((v24[0] & 1) != 0)
          v18 = v25;
        else
          v18 = v24 + 1;
        v19 = sub_8C4940(v18);
      }
    }
    else
    {
      Interface = 0;
    }
    dds3Particle_Spiral_t3__pCopy(pSpiral, Interface, &bpos);
    if (billno == -1)
      pSpiral->basic->billno = -1;
  }
  dds3Particle_BasicCreate(&pSpiral->basic, pCopy);
  dst = pSpiral->basic;
  hDataa = dst;
  dst->pSpiral = pSpiral;
  dds3Particle_SpiralAllBuffInit(&hDataa);
  return dst;
}

// 0x111fe50
void dds3Particle_SpiralDelete(void **hData) {
  dds3Particle_Basic_t_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3Particle_Basic_t_o *name;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  name = (*hData)[17].klass->_1.name;
  dds3Particle_BasicDelete(name, v3);
}

// 0x11204f0
void dds3Particle_SpiralDraw(void **hData) {
  dds3Particle_Basic_t_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3Particle_Spiral_t3_o *v6;
  struct dds3Particle_Basic_t_o *basic;
  dds3Particle_Effect_t_o *effect;
  s32 type;
  f32 eff_scl_raito;
  struct dds3Particle_Basic_t_o *v11;
  s64 v12;
  s64 v13;
  s64 v14;
  s64 v15;
  s64 v16;
  s64 v17;
  s64 v18;
  struct dds3Particle_Basic_t_o *v19;
  s64 number;
  s64 v21;
  u64 v24;
  s32 v25;
  struct parPhysics_t_array *pPhysics;
  struct dds3Particle_Physics_t_o *hPhysics;
  parPhysics_t_o *v29;
  s32 v30;
  dds3ParticleColorAnim_t_o *color;
  u32 v32;
  u32 abgr;
  f32 v34;
  f32 v35;
  f32 v36;
  dds3Particle_Effect_t_o **p_effect;
  f32 scale;
  u32 v42;
  s32 v43;
  s32 v44;
  dds3Particle_Effect_t_o **v46;
  char *v47;
  s64 *v48;
  s32 loop;
  s32 frame;
  UnityEngine_Matrix4x4_o v51;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o dst;
  dds3Particle_Spiral_t3_o *pSpiral;
  u64 v55[4];

  *&dst.z = 0;
  pSpiral = 0;
  *&p.z = 0;
  *&dst.x = 0;
  *&p.x = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v55);
    if ((v55[0] & 1) != 0)
      v47 = v55[2];
    else
      v47 = v55 + 1;
    v48 = sub_8C4940(v47);
  }
  v6 = (*hData)[17].klass;
  *&dst.z = 0;
  pSpiral = v6;
  *&p.z = 0;
  *&dst.x = 0;
  *&p.x = 0;
  basic = v6->basic;
  effect = basic->effect;
  type = effect->type;
  eff_scl_raito = basic->eff_scl_raito;
  dds3Particle_EffectInit(effect, eff_scl_raito, v3);
  v11 = v6->basic;
  v12 = *&v11->rot.m00;
  v13 = *&v11->rot.m20;
  v14 = *&v11->rot.m21;
  *&v51.m01 = *&v11->rot.m01;
  *&v51.m21 = v14;
  *&v51.m00 = v12;
  *&v51.m20 = v13;
  v15 = *&v11->rot.m02;
  v16 = *&v11->rot.m22;
  v18 = *&v11->rot.m03;
  v17 = *&v11->rot.m23;
  *&v51.m03 = v18;
  *&v51.m23 = v17;
  *&v51.m02 = v15;
  *&v51.m22 = v16;
  SDF_VU0__LOADMATRIX(&v51);
  v19 = v6->basic;
  frame = v19->frame;
  loop = v6->loop;
  number = v19->number;
  SDF_VU0__COPYVECTOR(&dst, v19->pos);
  if (number >= 1)
  {
    v24 = 0;
    v25 = 0;
    do
    {
      while (1)
      {
        hPhysics = v6->basic->hPhysics;
        else
        {
          pPhysics = hPhysics->pPhysics;
          if (v24 >= LODWORD(pPhysics->max_length))
          {
LABEL_15:
          }
        }
        v29 = pPhysics->m_Items[v24];
        v30 = v29->frame;
        if (v30 == -268435455)
        {
          dds3Particle_SpiralBuffInit(&pSpiral, v24);
          v30 = v29->frame;
        }
        if ((v30 & 0x80000000) == 0)
        {
          color = v6->basic->color;
          v32 = dds3ParticleColorAnim(color, v21, v30);
          v29->color = v32;
          abgr = v6->basic->abgr;
          SDF_VU0__dds3ColorItoF(v32);
          SDF_VU0__COPYVECTOR_A_TO_B();
          SDF_VU0__dds3ColorItoF(abgr);
          SDF_VU0__MULVECTOR();
          v29->color = SDF_VU0__dds3ColorFtoI(128.0);
          if (type)
            SDF_VU0__LOADVECTOR_C(v29->pos);
          sub_854710(&v29->dir, 0);
          sub_854710(&v29->val_f, 0);
          sub_854930(&v29->val_f, 0);
          sub_854710(&v29->val_f, 1u);
          sub_854930(&v29->val_f, 1u);
          sub_854710(&v29->val_f, 1u);
          if (v34 < 0.0)
            sub_854930(&v29->val_f, 1u);
          sub_854710(&v29->val_f, 0);
          v36 = v35;
          sub_854710(&v29->val_f, 1u);
          sub_854710(&v29->val_f, 3u);
          sub_854710(&v29->val_f, 2u);
          sub_854930(&v29->val_f, 3u);
          sdfCos(v36);
          sub_854930(&p, 0);
          sub_854710(&v29->val_f, 3u);
          sub_854930(&p, 1u);
          sdfSin(v36);
          sub_854930(&p, 2u);
          SDF_VU0__LOADVECTOR(p);
          SDF_VU0__APPLYMATRIX();
          SDF_VU0__STOREVECTOR(&p);
          sub_854710(&dst, 0);
          sub_854710(&p, 0);
          sub_854930(&v29->fields, 0);
          sub_854710(&dst, 1u);
          sub_854710(&p, 1u);
          sub_854930(&v29->fields, 1u);
          sub_854710(&dst, 2u);
          sub_854710(&p, 2u);
          sub_854930(&v29->fields, 2u);
          sub_854710(&v29->val_f, 2u);
          sub_854930(&v29->val_f, 2u);
          if (type)
          {
            SDF_VU0__LOADVECTOR(v29->pos);
            p_effect = &v6->basic->effect;
            scale = v29->scale;
            v42 = v29->color;
            dds3Particle_EffectSet(p_effect, v24, v42, scale);
          }
        }
        v43 = v30 + 1;
        v44 = v30 + 1 < frame ? v30 + 1 : -268435455;
        if (v43 >= frame && loop == 0)
          break;
        ++v24;
        v29->frame = v44;
        if (number == v24)
          return;
      }
      v46 = &v6->basic->effect;
      dds3Particle_EffectReset(v46, v24);
      if (++v25 >= number)
        v6->basic->state = 0;
      ++v24;
      v29->frame = v43;
    }
    while (number != v24);
  }
}

// 0x111fa60
void dds3Particle_SpiralSetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v7;
  s64 v8;
  s64 v9;
  s64 v10;
  f32 v11;
  f32 v12;
  char *v13;
  s64 *v14;
  u64 v15[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v15);
    if ((v15[0] & 1) != 0)
      v13 = v15[2];
    else
      v13 = v15 + 1;
    v14 = sub_8C4940(v13);
  }
  v7 = (*hData)[17].klass;
  if (v7)
  {
    v8 = (v7->_1.name + 32);
    sub_854710(v8, 0);
    sub_854930(v8, 0);
    v9 = (v7->_1.name + 32);
    sub_854710(v9, 1u);
    sub_854930(v9, 1u);
    v10 = (v7->_1.name + 32);
    sub_854710(v10, 2u);
    sub_854930(v10, 2u);
    v11 = *&v7->_1.byval_arg.data * scale;
    v12 = *&v7->_1.this_arg.data;
    *&v7->_1.byval_arg.bits = *&v7->_1.byval_arg.bits * scale;
    *&v7->_1.byval_arg.data = v11;
    *&v7->_1.this_arg.data = v12 * scale;
  }
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
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  s32 v12;
  struct dds3ParOffsetBuffParts_t_array *pParts;
  dds3ParOffsetBuffParts_t_o *v16;
  struct dds3TrackPolyList_t_array *trackList;
  dds3TrackPolyList_t_o *v19;
  struct UnityEngine_Vector4_array *pVertex;
  s32 v21;
  signed s32 point;
  u32 length;
  s64 v24;
  struct UnityEngine_Vector3_array *pPosBuff;
  struct UnityEngine_Vector3_array *v27;
  struct UnityEngine_Vector3_array *v29;
  UnityEngine_Vector4_o *v32;
  u64 v33;
  s32 v34;
  struct UnityEngine_Vector3_array *v35;
  struct UnityEngine_Vector3_array *v37;
  struct UnityEngine_Vector3_array *v39;
  dds3TrackPoly_t_o **v46;
  u32 v47;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o v49;
  UnityEngine_Vector4_o v50;

  w = pPos.w;
  z = pPos.z;
  y = pPos.y;
  x = pPos.x;
  v12 = index;
  *&v49.x = 0;
  *&v49.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  pParts = pOffBuff->pParts;
  v16 = pParts->m_Items[v12];
  trackList = (*hTrackPoly)->trackList;
  if (v16->count >= 2)
  {
    v46 = hTrackPoly;
    v47 = v12;
    v19 = trackList->m_Items[v12];
    pVertex = v19->pVertex;
    v50.x = x;
    v50.y = y;
    v50.z = z;
    v50.w = w;
    SDF_VU0__COPYVECTOR(&dst, v50);
    v21 = v16->count - 1;
    v19->count = 3 * v21;
    point = v16->point;
    length = pOffBuff->length;
    if (!point)
      point = pOffBuff->length;
    v24 = point - 1LL;
    sub_854710(&dst, 0);
    pPosBuff = v16->pPosBuff;
    sub_8527D0(&pPosBuff->m_Items[v24].x, 0);
    sub_854930(&v49, 0);
    sub_854710(&dst, 1u);
    v27 = v16->pPosBuff;
    sub_8527D0(&v27->m_Items[v24].x, 1);
    sub_854930(&v49, 1u);
    sub_854710(&dst, 2u);
    v29 = v16->pPosBuff;
    sub_8527D0(&v29->m_Items[v24].x, 2);
    sub_854930(&v49, 2u);
    sub_854930(&v49, 3u);
    if (v21 >= 1)
    {
      v32 = &pVertex->m_Items[2];
      v33 = 2;
      do
      {
        SDF_VU0__LOADVECTOR(v49);
        if (v24)
          v34 = v24;
        else
          v34 = length;
        v24 = v34 - 1LL;
        sub_854710(&dst, 0);
        v35 = v16->pPosBuff;
        sub_8527D0(&v35->m_Items[v24].x, 0);
        sub_854930(&v49, 0);
        sub_854710(&dst, 1u);
        v37 = v16->pPosBuff;
        sub_8527D0(&v37->m_Items[v24].x, 1);
        sub_854930(&v49, 1u);
        sub_854710(&dst, 2u);
        v39 = v16->pPosBuff;
        sub_8527D0(&v39->m_Items[v24].x, 2);
        sub_854930(&v49, 2u);
        SDF_VU0__LOADVECTOR_C(v49);
        SDF_VU0__COPYVECTOR_C_TO_B();
        SDF_VU0__SUBVECTOR();
        SDF_VU0__LOADVECTOR_B(parLook);
        SDF_VU0__OUTERPRODUCT();
        SDF_VU0__NORMALIZE();
        SDF_VU0__LOADVECTOR_B(parTrack_w);
        SDF_VU0__MULVECTOR();
        SDF_VU0__SWAPVECTOR_A_C();
        SDF_VU0__STOREVECTOR(v32 - 1);
        SDF_VU0__COPYVECTOR_A_TO_B();
        SDF_VU0__ADDVECTOR_A_C();
        SDF_VU0__STOREVECTOR(v32 - 2);
        SDF_VU0__COPYVECTOR_C_TO_A();
        SDF_VU0__SUBVECTOR_B_A();
        SDF_VU0__STOREVECTOR_B(v32);
        v32 += 3;
        v33 += 3LL;
        --v21;
      }
      while (v21);
    }
    hTrackPoly = v46;
    v12 = v47;
    dds3TrackPolyVCRefresh_ParType2(v46, v47);
  }
  dds3TrackPolyColorSet(hTrackPoly, v12, abgr);
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
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  s32 v12;
  struct dds3ParOffsetBuffParts_t_array *pParts;
  dds3ParOffsetBuffParts_t_o *v16;
  struct dds3TrackPolyList_t_array *trackList;
  dds3TrackPolyList_t_o *v19;
  struct UnityEngine_Vector4_array *pVertex;
  s32 v21;
  signed s32 point;
  u32 length;
  s64 v24;
  struct UnityEngine_Vector3_array *pPosBuff;
  struct UnityEngine_Vector3_array *v27;
  struct UnityEngine_Vector3_array *v29;
  u64 v32;
  UnityEngine_Vector4_o *m_Items;
  s32 v34;
  struct UnityEngine_Vector3_array *v35;
  struct UnityEngine_Vector3_array *v37;
  struct UnityEngine_Vector3_array *v39;
  u64 v44;
  dds3TrackPoly_t_o **v46;
  u32 v47;
  u32 v48;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o v50;
  UnityEngine_Vector4_o v51;

  w = pPos.w;
  z = pPos.z;
  y = pPos.y;
  x = pPos.x;
  v12 = index;
  *&v50.x = 0;
  *&v50.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  pParts = pOffBuff->pParts;
  v16 = pParts->m_Items[v12];
  trackList = (*hTrackPoly)->trackList;
  if (v16->count >= 2)
  {
    v46 = hTrackPoly;
    v47 = v12;
    v19 = trackList->m_Items[v12];
    pVertex = v19->pVertex;
    v51.x = x;
    v51.y = y;
    v51.z = z;
    v51.w = w;
    v48 = abgr;
    SDF_VU0__COPYVECTOR(&dst, v51);
    v21 = v16->count - 1;
    v19->count = 2 * v21;
    point = v16->point;
    length = pOffBuff->length;
    if (!point)
      point = pOffBuff->length;
    v24 = point - 1LL;
    sub_854710(&dst, 0);
    pPosBuff = v16->pPosBuff;
    sub_8527D0(&pPosBuff->m_Items[v24].x, 0);
    sub_854930(&v50, 0);
    sub_854710(&dst, 1u);
    v27 = v16->pPosBuff;
    sub_8527D0(&v27->m_Items[v24].x, 1);
    sub_854930(&v50, 1u);
    sub_854710(&dst, 2u);
    v29 = v16->pPosBuff;
    sub_8527D0(&v29->m_Items[v24].x, 2);
    sub_854930(&v50, 2u);
    sub_854930(&v50, 3u);
    if (v21 >= 1)
    {
      v32 = 0;
      m_Items = pVertex->m_Items;
      do
      {
        SDF_VU0__LOADVECTOR(v50);
        if (v24)
          v34 = v24;
        else
          v34 = length;
        v24 = v34 - 1LL;
        sub_854710(&dst, 0);
        v35 = v16->pPosBuff;
        sub_8527D0(&v35->m_Items[v24].x, 0);
        sub_854930(&v50, 0);
        sub_854710(&dst, 1u);
        v37 = v16->pPosBuff;
        sub_8527D0(&v37->m_Items[v24].x, 1);
        sub_854930(&v50, 1u);
        sub_854710(&dst, 2u);
        v39 = v16->pPosBuff;
        sub_8527D0(&v39->m_Items[v24].x, 2);
        sub_854930(&v50, 2u);
        SDF_VU0__LOADVECTOR_C(v50);
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
        SDF_VU0__STOREVECTOR(m_Items);
        SDF_VU0__COPYVECTOR_C_TO_A();
        SDF_VU0__SUBVECTOR_B_A();
        v44 = v32 + 1;
        SDF_VU0__STOREVECTOR_B(m_Items + 1);
        m_Items += 2;
        --v21;
        v32 = v44 + 1;
      }
      while (v21);
    }
    hTrackPoly = v46;
    v12 = v47;
    dds3TrackPolyVCRefresh_ParType1(v46, v47);
    abgr = v48;
  }
  dds3TrackPolyColorSet(hTrackPoly, v12, abgr);
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
