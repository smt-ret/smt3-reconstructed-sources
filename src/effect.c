#include "types.h"

typedef struct P2A_ANIMATION_tag P2A_ANIMATION_tag;
typedef struct P2A_HEAD_t P2A_HEAD_t;
typedef struct P2A_TEXANIM_tag P2A_TEXANIM_tag;
typedef struct dds3BillAnimResource_tag dds3BillAnimResource_tag;
typedef struct dds3BillAnim_tag dds3BillAnim_tag;
typedef struct dds3BillResource_tag dds3BillResource_tag;
typedef struct dds3EffectPCPData_Part_t dds3EffectPCPData_Part_t;
typedef struct dds3EffectPCPData_t dds3EffectPCPData_t;
typedef struct dds3Effect_Blur_t dds3Effect_Blur_t;
typedef struct dds3Effect_DistortionBlurParam_t dds3Effect_DistortionBlurParam_t;
typedef struct dds3Effect_Filter_t dds3Effect_Filter_t;
typedef struct dds3Effect_PartialMultiBlurParam_t dds3Effect_PartialMultiBlurParam_t;
typedef struct dds3Effect_PartialMultiBlur_t dds3Effect_PartialMultiBlur_t;
typedef struct dds3Effect_PartialMultiFilterParam_t dds3Effect_PartialMultiFilterParam_t;
typedef struct dds3Effect_RippleBlurParam_t dds3Effect_RippleBlurParam_t;
typedef struct dds3Effect_t dds3Effect_t;
typedef struct dds3FlashPolyList_t dds3FlashPolyList_t;
typedef struct dds3MultiBillResource_tag dds3MultiBillResource_tag;
typedef struct dds3P2APolygon_tag dds3P2APolygon_tag;
typedef struct dds3ParOffsetBuffParts_t dds3ParOffsetBuffParts_t;
typedef struct dds3ParOffsetBuff_t dds3ParOffsetBuff_t;
typedef struct dds3ParticleColorAnim_t dds3ParticleColorAnim_t;
typedef struct dds3Particle_Basic_t dds3Particle_Basic_t;
typedef struct dds3Particle_BlurBuffList_t dds3Particle_BlurBuffList_t;
typedef struct dds3Particle_BlurBuff_t dds3Particle_BlurBuff_t;
typedef struct dds3Particle_Blur_t dds3Particle_Blur_t;
typedef struct dds3Particle_EffItem_t dds3Particle_EffItem_t;
typedef struct dds3Particle_Effect_t dds3Particle_Effect_t;
typedef struct dds3Particle_Exp_t dds3Particle_Exp_t;
typedef struct dds3Particle_Expansion_t dds3Particle_Expansion_t;
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
typedef struct dds3Particle_Track2_t dds3Particle_Track2_t;
typedef struct dds3Particle_Track3_t dds3Particle_Track3_t;
typedef struct dds3Particle_Track_t dds3Particle_Track_t;
typedef struct dds3SpPoly_Basic_t dds3SpPoly_Basic_t;
typedef struct dds3SpPoly_RingPhysics_t dds3SpPoly_RingPhysics_t;
typedef struct dds3SpPoly_Ring_Old_t3 dds3SpPoly_Ring_Old_t3;
typedef struct dds3SpPoly_Ring_t3 dds3SpPoly_Ring_t3;
typedef struct dds3SpPoly_RollRingPhysics_t dds3SpPoly_RollRingPhysics_t;
typedef struct dds3SpPoly_RollRing_t3 dds3SpPoly_RollRing_t3;
typedef struct dds3SpPoly_SphereRing_t3 dds3SpPoly_SphereRing_t3;
typedef struct dds3TrackPolyList_t dds3TrackPolyList_t;
typedef struct dds3TrackPoly_t dds3TrackPoly_t;
typedef struct effBTLCutHandle_t effBTLCutHandle_t;
typedef struct effBTL_SkillCameraShake_t effBTL_SkillCameraShake_t;
typedef struct effBTL_SkillCamera_t effBTL_SkillCamera_t;
typedef struct effBTL_SkillColorAnim_t effBTL_SkillColorAnim_t;
typedef struct effBTL_SkillData_t effBTL_SkillData_t;
typedef struct effBTL_SkillField_t effBTL_SkillField_t;
typedef struct effBTL_SkillLight_t effBTL_SkillLight_t;
typedef struct effBTL_SkillModel_t effBTL_SkillModel_t;
typedef struct effBTL_SkillPBFileHeader_t effBTL_SkillPBFileHeader_t;
typedef struct effBTL_SkillPartsList_t effBTL_SkillPartsList_t;
typedef struct effBTL_SkillParts_t effBTL_SkillParts_t;
typedef struct effBTL_SkillPositionPtr_t effBTL_SkillPositionPtr_t;
typedef struct effBTL_SkillSE_t effBTL_SkillSE_t;
typedef struct effBTL_t effBTL_t;
typedef struct effBezier4PPart_t effBezier4PPart_t;
typedef struct effBezier7PPart_t effBezier7PPart_t;
typedef struct effEveBEDParams_t effEveBEDParams_t;
typedef struct effMagaCylinderParam_t effMagaCylinderParam_t;
typedef struct effMagaP4Point_t effMagaP4Point_t;
typedef struct effMagaPoint4Param_t effMagaPoint4Param_t;
typedef struct effMagaSCArea_t effMagaSCArea_t;
typedef struct effMagaSmokeConvParam_t effMagaSmokeConvParam_t;
typedef struct effMagaSmokeParam_t effMagaSmokeParam_t;
typedef struct effMagaSpiralParam_t effMagaSpiralParam_t;
typedef struct effMagatuhiParams_t effMagatuhiParams_t;
typedef struct effPCPAgiFireball2Param_t effPCPAgiFireball2Param_t;
typedef struct effPCPAgiFireballParam_t effPCPAgiFireballParam_t;
typedef struct effPCPAgiFireballPartList_t effPCPAgiFireballPartList_t;
typedef struct effPCPAgiraoFireParam_t effPCPAgiraoFireParam_t;
typedef struct effPCPBezierBillParam_t effPCPBezierBillParam_t;
typedef struct effPCPBlurExpParam_t effPCPBlurExpParam_t;
typedef struct effPCPBossBaelParam_t effPCPBossBaelParam_t;
typedef struct effPCPBossDengekiParam_t effPCPBossDengekiParam_t;
typedef struct effPCPBossKAGU2AttackParam_t effPCPBossKAGU2AttackParam_t;
typedef struct effPCPBossKAGUAttackParam_t effPCPBossKAGUAttackParam_t;
typedef struct effPCPBossKAGUInvokeParam_t effPCPBossKAGUInvokeParam_t;
typedef struct effPCPBossKAGUThunderboltParam_t effPCPBossKAGUThunderboltParam_t;
typedef struct effPCPBossMETATOBeamParam_t effPCPBossMETATOBeamParam_t;
typedef struct effPCPBossThunderboltParam_t effPCPBossThunderboltParam_t;
typedef struct effPCPBreathParam_t effPCPBreathParam_t;
typedef struct effPCPCrack2Param_t effPCPCrack2Param_t;
typedef struct effPCPCrackParam_t effPCPCrackParam_t;
typedef struct effPCPDANTE_Damage_Param_t effPCPDANTE_Damage_Param_t;
typedef struct effPCPDANTE_ShowTime_Param_t effPCPDANTE_ShowTime_Param_t;
typedef struct effPCPDANTE_Thunder_Param_t effPCPDANTE_Thunder_Param_t;
typedef struct effPCPDistortionBlurExpParam_t effPCPDistortionBlurExpParam_t;
typedef struct effPCPFLEACHBlurParam_t effPCPFLEACHBlurParam_t;
typedef struct effPCPFilterExpParam_t effPCPFilterExpParam_t;
typedef struct effPCPFlashPolyCircleParam_t effPCPFlashPolyCircleParam_t;
typedef struct effPCPFlashPolyPipeParam_t effPCPFlashPolyPipeParam_t;
typedef struct effPCPFlashPolyRingExp2Param_t effPCPFlashPolyRingExp2Param_t;
typedef struct effPCPFlashPolyRingExpParam_t effPCPFlashPolyRingExpParam_t;
typedef struct effPCPFlashPolyRingParam_t effPCPFlashPolyRingParam_t;
typedef struct effPCPFlashPolySphere2ExpParam_t effPCPFlashPolySphere2ExpParam_t;
typedef struct effPCPFlashPolySphere2Param_t effPCPFlashPolySphere2Param_t;
typedef struct effPCPFlashPolySphere3Param_t effPCPFlashPolySphere3Param_t;
typedef struct effPCPFlashPolySphereExpParam_t effPCPFlashPolySphereExpParam_t;
typedef struct effPCPFlashPolySphereParam_t effPCPFlashPolySphereParam_t;
typedef struct effPCPHamaCardScatterParam_t effPCPHamaCardScatterParam_t;
typedef struct effPCPHamaCardSphereParam_t effPCPHamaCardSphereParam_t;
typedef struct effPCPHamaCardSpiralParam_t effPCPHamaCardSpiralParam_t;
typedef struct effPCPHelperBEDParam_t effPCPHelperBEDParam_t;
typedef struct effPCPMultiBlurExp2Param_t effPCPMultiBlurExp2Param_t;
typedef struct effPCPMultiBlurExpParam_t effPCPMultiBlurExpParam_t;
typedef struct effPCPMultiFilterExpParam_t effPCPMultiFilterExpParam_t;
typedef struct effPCPMuzzleFlashParam_t effPCPMuzzleFlashParam_t;
typedef struct effPCPNeedleSpiralParam_t effPCPNeedleSpiralParam_t;
typedef struct effPCPRadiateBEDParam_t effPCPRadiateBEDParam_t;
typedef struct effPCPRadiateTBParam_t effPCPRadiateTBParam_t;
typedef struct effPCPRadiateThunderAttach_t effPCPRadiateThunderAttach_t;
typedef struct effPCPRadiateThunderParam_t effPCPRadiateThunderParam_t;
typedef struct effPCPRingPolyExp2Param_t effPCPRingPolyExp2Param_t;
typedef struct effPCPRingPolyExpParam_t effPCPRingPolyExpParam_t;
typedef struct effPCPRippleBlurExpParam_t effPCPRippleBlurExpParam_t;
typedef struct effPCPScreenCrackModelParam_t effPCPScreenCrackModelParam_t;
typedef struct effPCPSpiralBEDParam_t effPCPSpiralBEDParam_t;
typedef struct effPCPThunderSphereExpParam_t effPCPThunderSphereExpParam_t;
typedef struct effPCPThunderSpherePolyParam_t effPCPThunderSpherePolyParam_t;
typedef struct effPCPWhirlwind2PolyParam_t effPCPWhirlwind2PolyParam_t;
typedef struct effPCPWhirlwind3PolyParam_t effPCPWhirlwind3PolyParam_t;
typedef struct effPCPWhirlwindPolyParam_t effPCPWhirlwindPolyParam_t;
typedef struct effPCPWwSpherePolyParam_t effPCPWwSpherePolyParam_t;
typedef struct effPCP_BED_Param_t effPCP_BED_Param_t;
typedef struct effPCP_HBED2_Param_t effPCP_HBED2_Param_t;
typedef struct effPCP_PBCamera_Param_t effPCP_PBCamera_Param_t;
typedef struct effPCP_ThunderColumnPolyLowParam_t effPCP_ThunderColumnPolyLowParam_t;
typedef struct effPCP_ThunderPolyListParam_t effPCP_ThunderPolyListParam_t;
typedef struct effPCP_ThunderPolyParam_t effPCP_ThunderPolyParam_t;
typedef struct effPCP_ThunderPolyPart_t effPCP_ThunderPolyPart_t;
typedef struct effPCP_ThunderRadiatePolyParam_t effPCP_ThunderRadiatePolyParam_t;
typedef struct nbCameraAnim_t nbCameraAnim_t;
typedef struct nbCameraState_Start_t nbCameraState_Start_t;
typedef struct nbCamera_t nbCamera_t;
typedef struct parPhysics_t parPhysics_t;
typedef struct sdfMat_t sdfMat_t;

f32 Byte2Float(u8 **data, s32 pos);
u16 Byte2UInt16(u8 **bytedata, s32 pos);
u32 Byte2UInt32(u8 **bytedata, s32 pos);
u32 CutRaitoGet(u32 number, u32 numberO);
void dds3BillAnimResource_tag__dCopy(dds3BillAnimResource_tag *this, dds3BillAnimResource_tag **dst);
void dds3EffectPCPData_Part_t__pCopy(dds3EffectPCPData_Part_t *this, u8 **bytedata, s32 *pos);
void dds3Effect_Blur_t__Clear(dds3Effect_Blur_t *this);
void dds3Effect_Blur_t__SetData(dds3Effect_Blur_t *this, u8 **data, s32 *pos);
dds3Effect_Blur_t **dds3Effect_Blur_t__pCopy(dds3Effect_Blur_t *this, void *pData, s32 *pos, s32 max);
void dds3Effect_DistortionBlurParam_t__SetData(dds3Effect_DistortionBlurParam_t *this, u8 **data, s32 *pos);
void dds3Effect_Filter_t__Clear(dds3Effect_Filter_t *this);
void dds3Effect_Filter_t__SetData(dds3Effect_Filter_t *this, u8 **data, s32 *pos);
void dds3Effect_PartialMultiBlurParam_t__SetData(dds3Effect_PartialMultiBlurParam_t *this, u8 **data, s32 *pos);
dds3Effect_PartialMultiBlurParam_t **dds3Effect_PartialMultiBlurParam_t__pCopy(dds3Effect_PartialMultiBlurParam_t *this, void *pData, s32 *pos, s32 max);
void dds3Effect_PartialMultiFilterParam_t__SetData(dds3Effect_PartialMultiFilterParam_t *this, u8 **data, s32 *pos);
void dds3Effect_RippleBlurParam_t__SetData(dds3Effect_RippleBlurParam_t *this, u8 **data, s32 *pos);
void dds3ParticleColorAnim_t__dCopy(dds3ParticleColorAnim_t *this, dds3ParticleColorAnim_t **dst);
void dds3ParticleColorAnim_t__pCopy(dds3ParticleColorAnim_t *this, u8 **bytedata, s32 *bpos);
void dds3Particle_Basic_t__pCopy(dds3Particle_Basic_t *this, u8 **bytedata, s32 *bpos);
void dds3Particle_Blur_t__pCopy(dds3Particle_Blur_t *this, u8 **bytedata, s32 *pos);
void dds3Particle_EffItem_t__dCopy(dds3Particle_EffItem_t *this, dds3Particle_EffItem_t **dst);
void dds3Particle_EffItem_t__pCopy(dds3Particle_EffItem_t *this, u8 **bytedata, s32 *pos, u16 type);
void dds3Particle_Effect_t__pCopy(dds3Particle_Effect_t *this, u8 **bytedata, s32 *pos);
void dds3Particle_Expansion_t__pCopy(dds3Particle_Expansion_t *this, u8 **bytedata, s32 *bpos);
void dds3Particle_SmokeOffset_t3__dCopy(dds3Particle_SmokeOffset_t3 *this, dds3Particle_SmokeOffset_t3 **dst, dds3Particle_Basic_t *dstbasic);
void dds3Particle_SparkOffset_t3__dCopy(dds3Particle_SparkOffset_t3 *this, dds3Particle_SparkOffset_t3 **dst, dds3Particle_Basic_t *dstbasic);
void dds3Particle_SphereSpiral2_t3__dCopy(dds3Particle_SphereSpiral2_t3 *this, dds3Particle_SphereSpiral2_t3 **dst, dds3Particle_Basic_t *dstbasic);
void dds3Particle_Track2_t__pCopy(dds3Particle_Track2_t *this, u8 **bytedata, s32 *pos);
void dds3Particle_Track3_t__pCopy(dds3Particle_Track3_t *this, u8 **bytedata, s32 *pos);
void dds3Particle_Track_t__pCopy(dds3Particle_Track_t *this, u8 **bytedata, s32 *pos);
void dds3SpPoly_Basic_t__pClone(dds3SpPoly_Basic_t *this, dds3SpPoly_Basic_t **dst);
void dds3SpPoly_Basic_t__pCopy(dds3SpPoly_Basic_t *this, u8 **bytedata, s32 *bpos);
void dds3TrackPolyList_t__dCopy(dds3TrackPolyList_t *this, dds3TrackPolyList_t **dst);
void dds3TrackPoly_t__dCopy(dds3TrackPoly_t *this, dds3TrackPoly_t **dst);
s32 effBTL_SkillCamera_t__CopyByte(effBTL_SkillCamera_t *this, u8 **bytedata, s32 pos);
s32 effBTL_SkillColorAnim_t__CopyByte(effBTL_SkillColorAnim_t *this, u8 **bytedata, s32 pos);
s32 effBTL_SkillField_t__CopyByte(effBTL_SkillField_t *this, u8 **bytedata, s32 pos);
s32 effBTL_SkillLight_t__CopyByte(effBTL_SkillLight_t *this, u8 **bytedata, s32 pos);
s32 effBTL_SkillModel_t__CopyByte(effBTL_SkillModel_t *this, u8 **bytedata, s32 pos);
s32 effBTL_SkillPartsList_t__CopyByte(effBTL_SkillPartsList_t *this, u8 **bytedata, s32 pos);
s32 effBTL_SkillParts_t__CopyByte(effBTL_SkillParts_t *this, u8 **bytedata, s32 pos);
s32 effBTL_SkillPositionPtr_t__CopyByte(effBTL_SkillPositionPtr_t *this, u8 **bytedata, s32 pos);
void effBezier4PPart_t__Clear(effBezier4PPart_t *this);
void effMagatuhiParams_t__bCopy(effMagatuhiParams_t *this, u8 **bytedata, s32 *bPos);
effPCPAgiFireballParam_t **effPCPAgiFireballParam_t__pCopy(effPCPAgiFireballParam_t *this, void *pData, s32 *pos, s32 max);
effPCPCrackParam_t **effPCPCrackParam_t__pCopy(effPCPCrackParam_t *this, void *pData, s32 *pos, s32 max);
effPCPHelperBEDParam_t **effPCPHelperBEDParam_t__pCopy(effPCPHelperBEDParam_t *this, void *pData, s32 *pos, s32 max);
effPCPRadiateThunderAttach_t **effPCPRadiateThunderAttach_t__pCopy(effPCPRadiateThunderAttach_t *this, void *pData, s32 *pos, s32 max);
effPCPThunderSpherePolyParam_t **effPCPThunderSpherePolyParam_t__pCopy(effPCPThunderSpherePolyParam_t *this, void *pData, s32 *pos, s32 max);
void effPCP_ThunderPolyParam_t__pClone(effPCP_ThunderPolyParam_t *this, effPCP_ThunderPolyParam_t **param);
effPCP_ThunderPolyParam_t *effPCP_ThunderPolyParam_t__pCopy(effPCP_ThunderPolyParam_t *this, void *pData, s32 *pos, s32 max);
void parPhysics_t__dCopy(parPhysics_t *this, parPhysics_t **dst);
sdfMat_t *sdfMatNew(void);
void sdfMatSetConstant(sdfMat_t *aMat, f32 aRatio);

// 0x19cbd60
void P2A_ANIMATION_tag__dCopy(P2A_ANIMATION_tag *this, P2A_ANIMATION_tag **dst) {
  (*dst)->fields = this->fields;
}

// 0x19cbc50
void P2A_ANIMATION_tag__pCopy(P2A_ANIMATION_tag *this, u8 **bytedata, s32 *bpos) {
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;
  s32 v11;

  v7 = *bpos;
  this->spranm = Byte2UInt32(bytedata, v7);
  v8 = *bpos + 4;
  *bpos = v8;
  this->alpha = Byte2UInt32(bytedata, v8);
  v9 = *bpos + 4;
  *bpos = v9;
  this->attr = Byte2UInt32(bytedata, v9);
  v10 = *bpos + 4;
  *bpos = v10;
  this->times = Byte2UInt32(bytedata, v10);
  v11 = *bpos + 4;
  *bpos = v11;
  this->mode = Byte2UInt32(bytedata, v11);
  *bpos += 4;
}

// 0x19cbe60
void P2A_HEAD_t__dCopy(P2A_HEAD_t *this, P2A_HEAD_t **dst) {
  (*dst)->fields = this->fields;
}

// 0x19cbdb0
void P2A_HEAD_t__pCopy(P2A_HEAD_t *this, u8 **bytedata, s32 *bpos) {
  s32 v7;
  s32 v8;

  v7 = *bpos;
  this->tmxofs = Byte2UInt32(bytedata, v7);
  v8 = *bpos + 4;
  *bpos = v8;
  this->AnimNum = Byte2UInt32(bytedata, v8);
  *bpos += 4;
}

// 0x19cc040
void P2A_TEXANIM_tag__dCopy(P2A_TEXANIM_tag *this, P2A_TEXANIM_tag **dst) {
  (*dst)->fields = this->fields;
}

// 0x19cbe90
void P2A_TEXANIM_tag__pCopy(P2A_TEXANIM_tag *this, u8 **bytedata, s32 *bpos) {
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;
  s32 v11;
  s32 v12;
  s32 v13;
  s32 v14;
  s32 v15;
  s32 v16;
  s32 v17;

  v7 = *bpos;
  this->sx = Byte2UInt16(bytedata, v7);
  v8 = *bpos + 2;
  *bpos = v8;
  this->sy = Byte2UInt16(bytedata, v8);
  v9 = *bpos + 2;
  *bpos = v9;
  this->cx = Byte2UInt16(bytedata, v9);
  v10 = *bpos + 2;
  *bpos = v10;
  this->cy = Byte2UInt16(bytedata, v10);
  v11 = *bpos + 2;
  *bpos = v11;
  this->u1 = Byte2UInt16(bytedata, v11);
  v12 = *bpos + 2;
  *bpos = v12;
  this->v1 = Byte2UInt16(bytedata, v12);
  v13 = *bpos + 2;
  *bpos = v13;
  this->u2 = Byte2UInt16(bytedata, v13);
  v14 = *bpos + 2;
  *bpos = v14;
  this->v2 = Byte2UInt16(bytedata, v14);
  v15 = *bpos + 2;
  *bpos = v15;
  this->texid = Byte2UInt16(bytedata, v15);
  v16 = *bpos + 2;
  *bpos = v16;
  this->attr = Byte2UInt16(bytedata, v16);
  v17 = *bpos + 2;
  *bpos = v17;
  this->angle = Byte2Float(bytedata, v17);
  *bpos += 4;
}

// 0x19cc0f0
void dds3BillAnimResource_tag__dCopy(dds3BillAnimResource_tag *this, dds3BillAnimResource_tag **dst) {
  dds3BillAnimResource_tag_o *v5;
  u64 *v6;
  struct P2A_HEAD_t_o *pHeader;
  dds3BillAnimResource_tag_o *v8;
  dds3BillAnimResource_tag_o *v9;
  dds3BillAnimResource_tag_o *v10;
  s64 v11;
  u32 *pAnimTable;
  u64 v14;
  u64 *v15;
  struct P2A_ANIMATION_tag_array *v17;
  struct P2A_ANIMATION_tag_array *v19;
  u32 *v20;
  s64 v22;
  dds3BillAnimResource_tag_o *v23;
  dds3BillAnimResource_tag_o *v24;
  s64 v25;
  u32 *pResList;
  u64 v28;
  u64 *v29;
  struct dds3BillResource_tag_array *v31;
  struct dds3BillResource_tag_array *v33;
  s64 v34;
  s64 v36;

  (*dst)->hMem = this->hMem;
  v5 = *dst;
  v6 = Allocate(P2A_HEAD_t);
  _ctor(v6, 0);
  v5->pHeader = v6;
  pHeader = this->pHeader;
  v8 = *dst;
  (*dst)->pHeader->tmxofs = pHeader->tmxofs;
  v8->pHeader->AnimNum = pHeader->AnimNum;
  v9 = *dst;
  v9->pAnimTable = NewSpecific(
                            P2A_ANIMATION_tag,
                            LODWORD(this->pAnimTable->max_length));
  v10 = *dst;
  if (SLODWORD(this->pAnimTable->max_length) >= 1)
  {
    v11 = 4;
    do
    {
      pAnimTable = v10->pAnimTable;
      v14 = v11 - 4;
      v15 = Allocate(P2A_ANIMATION_tag);
      _ctor(v15, 0);
      *&pAnimTable[2 * v11] = v15;
      v17 = this->pAnimTable;
      v19 = (*dst)->pAnimTable;
      v20 = *(&v17->obj.klass + v11);
      *(*(&v19->obj.klass + v11) + 16LL) = v20[4];
      *(*(&v19->obj.klass + v11) + 20LL) = v20[5];
      *(*(&v19->obj.klass + v11) + 24LL) = v20[6];
      *(*(&v19->obj.klass + v11) + 28LL) = v20[7];
      *(*(&v19->obj.klass + v11) + 32LL) = v20[8];
      v10 = *dst;
      v22 = v11 - 3;
      ++v11;
    }
    while (v22 < SLODWORD(this->pAnimTable->max_length));
  }
  v10->AnimNum = this->AnimNum;
  (*dst)->TexNum = this->TexNum;
  (*dst)->count = this->count;
  v23 = *dst;
  v23->pResList = NewSpecific(
                           dds3BillResource_tag,
                           LODWORD(this->pResList->max_length));
  v24 = *dst;
  if (SLODWORD(this->pResList->max_length) >= 1)
  {
    v25 = 4;
    do
    {
      pResList = v24->pResList;
      v28 = v25 - 4;
      v29 = Allocate(dds3BillResource_tag);
      _ctor(v29, 0);
      *&pResList[2 * v25] = v29;
      v31 = this->pResList;
      v33 = (*dst)->pResList;
      v34 = *(&v31->obj.klass + v25);
      *(*(&v33->obj.klass + v25) + 16LL) = *(v34 + 16);
      *(*(&v33->obj.klass + v25) + 24LL) = *(v34 + 24);
      *(*(&v33->obj.klass + v25) + 28LL) = *(v34 + 28);
      *(*(&v33->obj.klass + v25) + 32LL) = *(v34 + 32);
      *(*(&v33->obj.klass + v25) + 40LL) = *(v34 + 40);
      *(*(&v33->obj.klass + v25) + 44LL) = *(v34 + 44);
      *(*(&v33->obj.klass + v25) + 48LL) = *(v34 + 48);
      *(*(&v33->obj.klass + v25) + 52LL) = *(v34 + 52);
      *(*(&v33->obj.klass + v25) + 56LL) = *(v34 + 56);
      *(*(&v33->obj.klass + v25) + 64LL) = *(v34 + 64);
      *(*(&v33->obj.klass + v25) + 72LL) = *(v34 + 72);
      *(*(&v33->obj.klass + v25) + 80LL) = *(v34 + 80);
      *(*(&v33->obj.klass + v25) + 88LL) = *(v34 + 88);
      v24 = *dst;
      v36 = v25 - 3;
      ++v25;
    }
    while (v36 < SLODWORD(this->pResList->max_length));
  }
  v24->pTexAnimTable = this->pTexAnimTable;
  (*dst)->pABGRTable = this->pABGRTable;
}

// 0x19cc5b0
void dds3BillAnim_tag__dCopy(dds3BillAnim_tag *this, dds3BillAnim_tag **dst) {
  struct dds3BillAnimResource_tag_array *hResource;
  dds3BillAnim_tag_o *v6;
  u64 v7;
  u32 *v9;
  u64 *v10;
  struct dds3BillAnimResource_tag_array *v13;
  dds3BillAnimResource_tag_o *v15;
  struct dds3BillAnimResource_tag_array *v16;
  dds3BillAnim_tag_o *v18;
  u64 *v19;
  struct P2A_ANIMATION_tag_o *pAnim;
  dds3BillAnim_tag_o *v21;
  dds3BillAnim_tag_o *v22;
  s64 v23;
  u64 v25;
  u32 *pTexAnim;
  u64 *v27;
  struct P2A_TEXANIM_tag_array *v29;
  struct P2A_TEXANIM_tag_array *v31;
  s64 v32;
  s64 v34;

  hResource = this->hResource;
  if (hResource)
  {
    v6 = *dst;
    v6->hResource = NewSpecific(
                             dds3BillAnimResource_tag,
                             LODWORD(hResource->max_length));
    if (SLODWORD(this->hResource->max_length) >= 1)
    {
      v7 = 0;
      do
      {
        v9 = (*dst)->hResource;
        v10 = Allocate(dds3BillAnimResource_tag);
        _ctor(v10, 0);
        *&v9[2 * v7 + 8] = v10;
        v13 = this->hResource;
        v15 = v13->m_Items[v7];
        v16 = (*dst)->hResource;
        dds3BillAnimResource_tag__dCopy(v15, &v16->m_Items[v7++]);
      }
      while (v7 < SLODWORD(this->hResource->max_length));
    }
  }
  (*dst)->key = 0;
  (*dst)->wait = this->wait;
  v18 = *dst;
  v19 = Allocate(P2A_ANIMATION_tag);
  _ctor(v19, 0);
  v18->pAnim = v19;
  pAnim = this->pAnim;
  v21 = *dst;
  (*dst)->pAnim->spranm = pAnim->spranm;
  v21->pAnim->alpha = pAnim->alpha;
  v21->pAnim->attr = pAnim->attr;
  v21->pAnim->times = pAnim->times;
  v21->pAnim->mode = pAnim->mode;
  v22 = *dst;
  v22->pTexAnim = NewSpecific(
                           P2A_TEXANIM_tag,
                           LODWORD(this->pTexAnim->max_length));
  if (SLODWORD(this->pTexAnim->max_length) >= 1)
  {
    v23 = 4;
    do
    {
      v25 = v23 - 4;
      pTexAnim = (*dst)->pTexAnim;
      v27 = Allocate(P2A_TEXANIM_tag);
      _ctor(v27, 0);
      *&pTexAnim[2 * v23] = v27;
      v29 = this->pTexAnim;
      v31 = (*dst)->pTexAnim;
      v32 = *(&v29->obj.klass + v23);
      *(*(&v31->obj.klass + v23) + 16LL) = *(v32 + 16);
      *(*(&v31->obj.klass + v23) + 18LL) = *(v32 + 18);
      *(*(&v31->obj.klass + v23) + 20LL) = *(v32 + 20);
      *(*(&v31->obj.klass + v23) + 22LL) = *(v32 + 22);
      *(*(&v31->obj.klass + v23) + 24LL) = *(v32 + 24);
      *(*(&v31->obj.klass + v23) + 26LL) = *(v32 + 26);
      *(*(&v31->obj.klass + v23) + 28LL) = *(v32 + 28);
      *(*(&v31->obj.klass + v23) + 30LL) = *(v32 + 30);
      *(*(&v31->obj.klass + v23) + 32LL) = *(v32 + 32);
      *(*(&v31->obj.klass + v23) + 34LL) = *(v32 + 34);
      *(*(&v31->obj.klass + v23) + 36LL) = *(v32 + 36);
      v34 = v23 - 3;
      ++v23;
    }
    while (v34 < SLODWORD(this->pTexAnim->max_length));
  }
}

// 0x19cc500
void dds3BillResource_tag__dCopy(dds3BillResource_tag *this, dds3BillResource_tag **dst) {
  (*dst)->fields = this->fields;
}

// 0x19ccaf0
void dds3EffectPCPData_Part_t__pCopy(dds3EffectPCPData_Part_t *this, u8 **bytedata, s32 *pos) {
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;

  v7 = *pos;
  this->size = Byte2UInt32(bytedata, v7);
  v8 = *pos + 4;
  *pos = v8;
  this->offset = Byte2UInt32(bytedata, v8);
  v9 = *pos + 4;
  *pos = v9;
  this->type = Byte2UInt32(bytedata, v9);
  v10 = *pos + 4;
  *pos = v10;
  this->reserve = Byte2UInt32(bytedata, v10);
  *pos += 4;
}

// 0x19ccbf0
void dds3EffectPCPData_t__pCopy(dds3EffectPCPData_t *this, u8 **bytedata, s32 *pos) {
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;
  struct dds3EffectPCPData_Part_t_array *v11;
  u32 part;
  u32 *v13;
  s64 i;
  u64 v15;
  u64 *v16;
  struct dds3EffectPCPData_Part_t_array *pcpData;

  v7 = *pos;
  this->kateg = Byte2UInt32(bytedata, v7);
  v8 = *pos + 4;
  *pos = v8;
  this->param = Byte2UInt32(bytedata, v8);
  v9 = *pos + 4;
  *pos = v9;
  this->part = Byte2UInt32(bytedata, v9);
  v10 = *pos + 4;
  *pos = v10;
  this->reserve = Byte2UInt32(bytedata, v10);
  *pos += 4;
  v11 = NewSpecific(dds3EffectPCPData_Part_t, this->part);
  part = this->part;
  this->pcpData = v11;
  if (part)
  {
    v13 = v11;
    for (i = 4; ; ++i)
    {
      v15 = i - 4;
      v16 = Allocate(dds3EffectPCPData_Part_t);
      _ctor(v16, 0);
      *&v13[2 * i] = v16;
      pcpData = this->pcpData;
      dds3EffectPCPData_Part_t__pCopy(*(&pcpData->obj.klass + i), bytedata, pos);
      if (i - 3 >= this->part)
        break;
      v13 = this->pcpData;
    }
  }
}

// 0x19cece0
void dds3Effect_Blur_t__Clear(dds3Effect_Blur_t *this) {
  u64 *v3;
  struct sdfIVector2_t_array *v4;
  struct sdfIVector2_t_array *v5;
  u64 *v6;
  struct sdfIVector2_t_array *xy;
  u64 *v9;

  *&this->abgr = 0;
  *&this->rotate = 0;
  v3 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v3);
  this->center = v3;
  v4 = NewSpecific(sdfIVector2_t, 2u);
  this->xy = v4;
  v5 = v4;
  v6 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v6);
  v5->m_Items[0] = v6;
  xy = this->xy;
  v9 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v9);
  xy->m_Items[1] = v9;
}

// 0x19cee40
void dds3Effect_Blur_t__SetData(dds3Effect_Blur_t *this, u8 **data, s32 *pos) {
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;
  sdfIVector2_t_o *v11;
  struct System_Int32_array *pm;
  s32 v13;
  s32 v15;
  struct System_Int32_array *v16;
  s32 v17;
  struct sdfIVector2_t_array *v19;
  struct sdfIVector2_t_array *v20;
  u64 *v21;
  struct sdfIVector2_t_array *xy;
  struct System_Int32_array *v24;
  s32 v25;
  s32 v26;
  s32 v28;
  struct sdfIVector2_t_array *v29;
  struct System_Int32_array *v31;
  s32 v32;
  struct sdfIVector2_t_array *v34;
  u64 *v35;
  struct sdfIVector2_t_array *v38;
  struct System_Int32_array *v40;
  s32 v41;
  s32 v42;
  s32 v44;
  struct sdfIVector2_t_array *v45;
  struct System_Int32_array *v47;
  s32 v48;

  v7 = *pos;
  this->abgr = ToUInt32(data, v7, 0);
  v8 = *pos + 4;
  *pos = v8;
  this->blend = ToInt32(data, v8, 0);
  v9 = *pos + 4;
  *pos = v9;
  this->rotate = ToSingle(data, v9, 0);
  v10 = *pos + 4;
  *pos = v10;
  this->scale = ToSingle(data, v10, 0);
  *pos += 4;
  v11 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v11);
  this->center = v11;
  pm = v11->pm;
  v13 = ToInt32(data, *pos, 0);
  pm->m_Items[0] = v13;
  v15 = *pos + 4;
  *pos = v15;
  v16 = this->center->pm;
  v17 = ToInt32(data, v15, 0);
  v16->m_Items[1] = v17;
  *pos += 4;
  v19 = NewSpecific(sdfIVector2_t, 2u);
  this->xy = v19;
  v20 = v19;
  v21 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v21);
  v20->m_Items[0] = v21;
  xy = this->xy;
  v24 = xy->m_Items[0]->pm;
  v25 = *pos;
  v26 = ToInt32(data, v25, 0);
  v24->m_Items[0] = v26;
  v28 = *pos + 4;
  *pos = v28;
  v29 = this->xy;
  v31 = v29->m_Items[0]->pm;
  v32 = ToInt32(data, v28, 0);
  v31->m_Items[1] = v32;
  *pos += 4;
  v34 = this->xy;
  v35 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v35);
  v34->m_Items[1] = v35;
  v38 = this->xy;
  v40 = v38->m_Items[1]->pm;
  v41 = *pos;
  v42 = ToInt32(data, v41, 0);
  v40->m_Items[0] = v42;
  v44 = *pos + 4;
  *pos = v44;
  v45 = this->xy;
  v47 = v45->m_Items[1]->pm;
  v48 = ToInt32(data, v44, 0);
  v47->m_Items[1] = v48;
  *pos += 4;
}

// 0x19cf2b0
dds3Effect_Blur_t **dds3Effect_Blur_t__pCopy(dds3Effect_Blur_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  u32 *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u32 *v14;
  u64 v15;
  u64 *v16;
  s32 v19;
  s32 v22;
  s64 v24;
  s32 v25;
  s64 v27;
  s32 v28;
  s64 v30;
  u64 v32[3];

  v8 = max;
  v9 = NewSpecific(dds3Effect_Blur_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v32);
      if ((v32[0] & 1) != 0)
        v12 = v32[2];
      else
        v12 = v32 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = v9 + 8;
    v15 = 0;
    do
    {
      v16 = Allocate(dds3Effect_Blur_t);
      _ctor(v16, 0);
      dds3Effect_Blur_t__Clear(v16);
      *&v14[2 * v15] = v16;
      v19 = *pos;
      *(v16 + 4) = Byte2UInt32(Interface, v19);
      v22 = *pos + 4;
      *pos = v22;
      v24 = *&v14[2 * v15];
      *(v24 + 20) = Byte2UInt32(Interface, v22);
      v25 = *pos + 4;
      *pos = v25;
      v27 = *&v14[2 * v15];
      *(v27 + 24) = Byte2Float(Interface, v25);
      v28 = *pos + 4;
      *pos = v28;
      v30 = *&v14[2 * v15];
      *(v30 + 28) = Byte2Float(Interface, v28);
      ++v15;
      *pos += 4;
    }
    while (v8 != v15);
  }
  return v9;
}

// 0x19cf7b0
void dds3Effect_DistortionBlurParam_t__Clear(dds3Effect_DistortionBlurParam_t *this) {
  u64 *v3;

  this->distortion = 0.0;
  *&this->speed = 0;
  *&this->blend = 0;
  *&this->number = 0;
  v3 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v3);
  this->center = v3;
  *&this->area = 0;
}

// 0x19cf5b0
void dds3Effect_DistortionBlurParam_t__SetData(dds3Effect_DistortionBlurParam_t *this, u8 **data, s32 *pos) {
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;
  s32 v11;
  s32 v12;
  s32 v13;
  s32 v14;
  struct System_Int32_array *pm;
  s32 v16;
  s32 v18;
  struct System_Int32_array *v19;
  s32 v20;
  s32 v22;
  s32 v23;

  v7 = *pos;
  this->number = ToUInt32(data, v7, 0);
  v8 = *pos + 4;
  *pos = v8;
  this->interval = ToUInt32(data, v8, 0);
  v9 = *pos + 4;
  *pos = v9;
  this->speed = ToSingle(data, v9, 0);
  v10 = *pos + 4;
  *pos = v10;
  this->abgr = ToUInt32(data, v10, 0);
  v11 = *pos + 4;
  *pos = v11;
  this->blend = ToInt32(data, v11, 0);
  v12 = *pos + 4;
  *pos = v12;
  this->rotate = ToSingle(data, v12, 0);
  v13 = *pos + 4;
  *pos = v13;
  this->distortion = ToSingle(data, v13, 0);
  v14 = *pos + 4;
  *pos = v14;
  pm = this->center->pm;
  v16 = ToInt32(data, v14, 0);
  pm->m_Items[0] = v16;
  v18 = *pos + 4;
  *pos = v18;
  v19 = this->center->pm;
  v20 = ToInt32(data, v18, 0);
  v19->m_Items[1] = v20;
  v22 = *pos + 4;
  *pos = v22;
  this->area = ToInt32(data, v22, 0);
  v23 = *pos + 4;
  *pos = v23;
  this->width = ToInt32(data, v23, 0);
  *pos += 4;
}

// 0x19cfd10
void dds3Effect_Filter_t__Clear(dds3Effect_Filter_t *this) {
  struct sdfIVector2_t_array *v3;
  struct sdfIVector2_t_array *v4;
  u64 *v5;
  struct sdfIVector2_t_array *xy;
  u64 *v8;

  *&this->abgr = 0;
  v3 = NewSpecific(sdfIVector2_t, 2u);
  this->xy = v3;
  v4 = v3;
  v5 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v5);
  v4->m_Items[0] = v5;
  xy = this->xy;
  v8 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v8);
  xy->m_Items[1] = v8;
}

// 0x19cf990
void dds3Effect_Filter_t__SetData(dds3Effect_Filter_t *this, u8 **data, s32 *pos) {
  s32 v7;
  s32 v8;
  struct sdfIVector2_t_array *xy;
  u64 *v10;
  struct sdfIVector2_t_array *v12;
  struct System_Int32_array *pm;
  s32 v14;
  s32 v15;
  s32 v17;
  struct sdfIVector2_t_array *v18;
  struct System_Int32_array *v20;
  s32 v21;
  struct sdfIVector2_t_array *v23;
  u64 *v24;
  struct sdfIVector2_t_array *v27;
  struct System_Int32_array *v29;
  s32 v30;
  s32 v31;
  s32 v33;
  struct sdfIVector2_t_array *v34;
  struct System_Int32_array *v36;
  s32 v37;

  v7 = *pos;
  this->abgr = ToUInt32(data, v7, 0);
  v8 = *pos + 4;
  *pos = v8;
  this->blend = ToInt32(data, v8, 0);
  *pos += 4;
  xy = this->xy;
  v10 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v10);
  xy->m_Items[0] = v10;
  v12 = this->xy;
  pm = v12->m_Items[0]->pm;
  v14 = *pos;
  v15 = ToInt32(data, v14, 0);
  pm->m_Items[0] = v15;
  v17 = *pos + 4;
  *pos = v17;
  v18 = this->xy;
  v20 = v18->m_Items[0]->pm;
  v21 = ToInt32(data, v17, 0);
  v20->m_Items[1] = v21;
  *pos += 4;
  v23 = this->xy;
  v24 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v24);
  v23->m_Items[1] = v24;
  v27 = this->xy;
  v29 = v27->m_Items[1]->pm;
  v30 = *pos;
  v31 = ToInt32(data, v30, 0);
  v29->m_Items[0] = v31;
  v33 = *pos + 4;
  *pos = v33;
  v34 = this->xy;
  v36 = v34->m_Items[1]->pm;
  v37 = ToInt32(data, v33, 0);
  v36->m_Items[1] = v37;
  *pos += 4;
}

// 0x19cfed0
void dds3Effect_PartialMultiBlurParam_t__Clear(dds3Effect_PartialMultiBlurParam_t *this) {
  u64 *v3;

  this->area = 0;
  v3 = Allocate(dds3Effect_Blur_t);
  _ctor(v3, 0);
  dds3Effect_Blur_t__Clear(v3);
  this->Blur = v3;
  dds3Effect_Blur_t__Clear(v3);
}

// 0x19cff40
void dds3Effect_PartialMultiBlurParam_t__SetData(dds3Effect_PartialMultiBlurParam_t *this, u8 **data, s32 *pos) {
  s32 v7;
  u64 *v8;

  v7 = *pos;
  this->area = ToInt32(data, v7, 0);
  *pos += 4;
  v8 = Allocate(dds3Effect_Blur_t);
  _ctor(v8, 0);
  dds3Effect_Blur_t__Clear(v8);
  this->Blur = v8;
  dds3Effect_Blur_t__SetData(v8, data, pos);
}

// 0x19d0010
dds3Effect_PartialMultiBlurParam_t **dds3Effect_PartialMultiBlurParam_t__pCopy(dds3Effect_PartialMultiBlurParam_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  u32 *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u32 *v14;
  u64 v15;
  u64 *v16;
  s32 v18;
  u64 *v21;
  dds3Effect_Blur_t_o *v23;
  s64 v26;
  dds3Effect_Blur_t_array *v27;
  u64 v30[3];

  v8 = max;
  v9 = NewSpecific(dds3Effect_PartialMultiBlurParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v30);
      if ((v30[0] & 1) != 0)
        v12 = v30[2];
      else
        v12 = v30 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = v9 + 8;
    v15 = 0;
    do
    {
      v16 = Allocate(dds3Effect_PartialMultiBlurParam_t);
      _ctor(v16, 0);
      *&v14[2 * v15] = v16;
      v18 = *pos;
      *(v16 + 4) = Byte2UInt32(Interface, v18);
      *pos += 4;
      v21 = Allocate(dds3Effect_Blur_t);
      _ctor(v21, 0);
      dds3Effect_Blur_t__Clear(v21);
      v26 = *&v14[2 * v15];
      v27 = dds3Effect_Blur_t__pCopy(v23, Interface, pos, 1);
      ++v15;
      *(v26 + 24) = v27->m_Items[0];
    }
    while (v8 != v15);
  }
  return v9;
}

// 0x19d02d0
void dds3Effect_PartialMultiBlur_t__Clear(dds3Effect_PartialMultiBlur_t *this) {
  u64 *v3;
  u64 *v4;

  v3 = Allocate(dds3Effect_PartialMultiBlurParam_t);
  _ctor(v3, 0);
  this->param = v3;
  *(v3 + 4) = 0;
  v4 = Allocate(dds3Effect_Blur_t);
  _ctor(v4, 0);
  dds3Effect_Blur_t__Clear(v4);
  v3[3] = v4;
  dds3Effect_Blur_t__Clear(v4);
  this->cntRT = 0;
  this->pMesh = 0;
  this->rImage = 0;
  this->hAlphaTex = 0;
}

// 0x19d04e0
void dds3Effect_PartialMultiFilterParam_t__Clear(dds3Effect_PartialMultiFilterParam_t *this) {
  u64 *v3;
  Il2CppObject *v4;

  this->area = 0;
  v3 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v3);
  this->center = v3;
  v4 = Allocate(dds3Effect_Filter_t);
  v4[1].monitor = NewSpecific(sdfIVector2_t, 2u);
  _ctor(v4, 0);
  this->Filter = v4;
  dds3Effect_Filter_t__Clear(v4);
}

// 0x19d03b0
void dds3Effect_PartialMultiFilterParam_t__SetData(dds3Effect_PartialMultiFilterParam_t *this, u8 **data, s32 *pos) {
  s32 v7;
  s32 v8;
  struct System_Int32_array *pm;
  s32 v10;
  s32 v12;
  struct System_Int32_array *v13;
  s32 v15;

  v7 = *pos;
  this->area = ToInt32(data, v7, 0);
  v8 = *pos + 4;
  *pos = v8;
  pm = this->center->pm;
  v10 = ToInt32(data, v8, 0);
  pm->m_Items[0] = v10;
  v12 = *pos + 4;
  *pos = v12;
  v13 = this->center->pm;
  v15 = ToInt32(data, v12, 0);
  v13->m_Items[1] = v15;
  *pos += 4;
  dds3Effect_Filter_t__SetData(this->Filter, data, pos);
}

// 0x19d0890
void dds3Effect_RippleBlurParam_t__Clear(dds3Effect_RippleBlurParam_t *this) {
  u64 *v3;

  *&this->blend = 0;
  *&this->power = 0;
  *&this->number = 0;
  *&this->interval = 0;
  v3 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v3);
  *&this->unitycalc_center_x = 0x3F0000003F000000LL;
  this->center = v3;
  this->area = 0;
  this->unitycalc_area = 1.0;
}

// 0x19d0690
void dds3Effect_RippleBlurParam_t__SetData(dds3Effect_RippleBlurParam_t *this, u8 **data, s32 *pos) {
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;
  s32 v11;
  s32 v12;
  s32 v13;
  s32 v14;
  s32 v15;
  struct System_Int32_array *pm;
  s32 v17;
  s32 v19;
  struct System_Int32_array *v20;
  s32 v21;
  s32 v23;

  v7 = *pos;
  this->number = ToUInt32(data, v7, 0);
  v8 = *pos + 4;
  *pos = v8;
  this->speed = ToSingle(data, v8, 0);
  v9 = *pos + 4;
  *pos = v9;
  this->interval = ToSingle(data, v9, 0);
  v10 = *pos + 4;
  *pos = v10;
  this->abgr = ToUInt32(data, v10, 0);
  v11 = *pos + 4;
  *pos = v11;
  this->blend = ToInt32(data, v11, 0);
  v12 = *pos + 4;
  *pos = v12;
  this->rotate = ToSingle(data, v12, 0);
  v13 = *pos + 4;
  *pos = v13;
  this->power = ToSingle(data, v13, 0);
  v14 = *pos + 4;
  *pos = v14;
  this->frequency = ToSingle(data, v14, 0);
  v15 = *pos + 4;
  *pos = v15;
  pm = this->center->pm;
  v17 = ToInt32(data, v15, 0);
  pm->m_Items[0] = v17;
  v19 = *pos + 4;
  *pos = v19;
  v20 = this->center->pm;
  v21 = ToInt32(data, v19, 0);
  v20->m_Items[1] = v21;
  v23 = *pos + 4;
  *pos = v23;
  this->area = ToInt32(data, v23, 0);
  *pos += 4;
}

// 0x19d0990
void dds3Effect_t__pCopy(dds3Effect_t *this, u8 **bytedata, s32 *pos) {
  s32 v7;
  s32 v8;
  s32 v9;

  v7 = *pos;
  this->major = Byte2UInt32(bytedata, v7);
  v8 = *pos + 4;
  *pos = v8;
  this->minor = Byte2UInt32(bytedata, v8);
  v9 = *pos + 8;
  *pos = v9;
  this->version = Byte2Float(bytedata, v9);
  *pos += 4;
}

// 0x19d0a70
void dds3FlashPolyList_t__Clear(dds3FlashPolyList_t *this, s32 vcnt) {
  u64 v5;
  struct UnityEngine_Vector4_array *v6;
  struct UnityEngine_Vector4_array *pVertex;
  u64 v8;
  s64 v9;
  u64 *v11;
  struct sdfMat_t_o *v13;

  *&this->blend = 0x8080808000000002LL;
  this->point = vcnt;
  this->scale = 1.0;
  v5 = vcnt;
  v6 = NewSpecific(UnityEngine_Vector4, vcnt);
  this->pVertex = v6;
  if (vcnt >= 1)
  {
    pVertex = v6;
    v8 = 0;
    v9 = 32;
    if (!LODWORD(v6->max_length))
    {
LABEL_7:
    }
    while (1)
    {
      v11 = (&pVertex->obj.klass + v9);
      *v11 = 0;
      v11[1] = 0;
      if (v5 - 1 == v8)
        break;
      pVertex = this->pVertex;
      ++v8;
      v9 += 16;
      if (v8 >= LODWORD(pVertex->max_length))
        goto LABEL_7;
    }
  }
  this->pVC = NewSpecific(uint, v5);
  v13 = sdfMatNew();
  this->pMat = v13;
  sdfMatSetConstant(v13, 1.0);
  this->hMem = 0;
  this->pMesh = 0;
}

// 0x19d0bd0
void dds3MultiBillResource_tag__dCopy(dds3MultiBillResource_tag *this, dds3MultiBillResource_tag **dst) {
  dds3MultiBillResource_tag_o *v5;
  struct dds3BillResource_tag_array *hBillRes;
  il2cpp_array_size_t max_length;
  s64 v8;
  u64 v10;
  u32 *v12;
  u64 *v13;
  struct dds3BillResource_tag_array *v15;
  struct dds3BillResource_tag_array *v17;
  s64 v18;
  s64 v20;

  v5 = *dst;
  v5->hBillRes = NewSpecific(
                          dds3BillResource_tag,
                          LODWORD(this->hBillRes->max_length));
  hBillRes = this->hBillRes;
  max_length = hBillRes->max_length;
  if (max_length >= 1)
  {
    v8 = 4;
    do
    {
      v10 = v8 - 4;
      if (*(&hBillRes->obj.klass + v8))
      {
        v12 = (*dst)->hBillRes;
        v13 = Allocate(dds3BillResource_tag);
        _ctor(v13, 0);
        *&v12[2 * v8] = v13;
        v15 = this->hBillRes;
        v17 = (*dst)->hBillRes;
        v18 = *(&v15->obj.klass + v8);
        *(*(&v17->obj.klass + v8) + 16LL) = *(v18 + 16);
        *(*(&v17->obj.klass + v8) + 24LL) = *(v18 + 24);
        *(*(&v17->obj.klass + v8) + 28LL) = *(v18 + 28);
        *(*(&v17->obj.klass + v8) + 32LL) = *(v18 + 32);
        *(*(&v17->obj.klass + v8) + 40LL) = *(v18 + 40);
        *(*(&v17->obj.klass + v8) + 44LL) = *(v18 + 44);
        *(*(&v17->obj.klass + v8) + 48LL) = *(v18 + 48);
        *(*(&v17->obj.klass + v8) + 52LL) = *(v18 + 52);
        *(*(&v17->obj.klass + v8) + 56LL) = *(v18 + 56);
        *(*(&v17->obj.klass + v8) + 64LL) = *(v18 + 64);
        *(*(&v17->obj.klass + v8) + 72LL) = *(v18 + 72);
        *(*(&v17->obj.klass + v8) + 80LL) = *(v18 + 80);
        *(*(&v17->obj.klass + v8) + 88LL) = *(v18 + 88);
      }
      hBillRes = this->hBillRes;
      LODWORD(max_length) = hBillRes->max_length;
      v20 = v8 - 3;
      ++v8;
    }
    while (v20 < max_length);
  }
  (*dst)->type = this->type;
  (*dst)->mode = this->mode;
  (*dst)->abgr = this->abgr;
  (*dst)->pBillTag = this->pBillTag;
  (*dst)->next = this->next;
}

// 0x19d0e70
void dds3P2APolygon_tag__pCopy(dds3P2APolygon_tag *this, u8 **bytedata, s32 *bpos) {
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;
  s32 v11;
  s32 v12;
  s32 v13;
  s32 v14;
  s32 v15;
  s32 v16;
  s32 v17;
  s32 v18;
  s32 v19;
  s32 v20;
  s32 v21;
  s32 v22;
  struct UnityEngine_Matrix4x4_o *p_rot;
  s32 v24;
  s32 v25;
  s32 v26;
  s32 v27;
  s32 v28;
  s32 v29;
  s32 v30;
  s32 v31;
  s32 v32;
  s32 v33;
  s32 v34;
  s32 v35;
  s32 v36;
  s32 v37;
  s32 v38;

  *&this->dir.m00 = 0;
  *&this->dir.m03 = 0;
  *&this->dir.m23 = 0;
  *&this->dir.m20 = 0;
  *&this->dir.m02 = 0;
  *&this->dir.m22 = 0;
  *&this->dir.m01 = 0;
  *&this->dir.m21 = 0;
  v7 = *bpos;
  Byte2Float(bytedata, v7);
  sub_19FFD30(&this->fields, 0, 0);
  v8 = *bpos + 4;
  *bpos = v8;
  Byte2Float(bytedata, v8);
  sub_19FFD30(&this->fields, 0, 1);
  v9 = *bpos + 4;
  *bpos = v9;
  Byte2Float(bytedata, v9);
  sub_19FFD30(&this->fields, 0, 2);
  v10 = *bpos + 4;
  *bpos = v10;
  Byte2Float(bytedata, v10);
  sub_19FFD30(&this->fields, 0, 3);
  v11 = *bpos + 4;
  *bpos = v11;
  Byte2Float(bytedata, v11);
  sub_19FFD30(&this->fields, 1, 0);
  v12 = *bpos + 4;
  *bpos = v12;
  Byte2Float(bytedata, v12);
  sub_19FFD30(&this->fields, 1, 1);
  v13 = *bpos + 4;
  *bpos = v13;
  Byte2Float(bytedata, v13);
  sub_19FFD30(&this->fields, 1, 2);
  v14 = *bpos + 4;
  *bpos = v14;
  Byte2Float(bytedata, v14);
  sub_19FFD30(&this->fields, 1, 3);
  v15 = *bpos + 4;
  *bpos = v15;
  Byte2Float(bytedata, v15);
  sub_19FFD30(&this->fields, 2, 0);
  v16 = *bpos + 4;
  *bpos = v16;
  Byte2Float(bytedata, v16);
  sub_19FFD30(&this->fields, 2, 1);
  v17 = *bpos + 4;
  *bpos = v17;
  Byte2Float(bytedata, v17);
  sub_19FFD30(&this->fields, 2, 2);
  v18 = *bpos + 4;
  *bpos = v18;
  Byte2Float(bytedata, v18);
  sub_19FFD30(&this->fields, 2, 3);
  v19 = *bpos + 4;
  *bpos = v19;
  Byte2Float(bytedata, v19);
  sub_19FFD30(&this->fields, 3, 0);
  v20 = *bpos + 4;
  *bpos = v20;
  Byte2Float(bytedata, v20);
  sub_19FFD30(&this->fields, 3, 1);
  v21 = *bpos + 4;
  *bpos = v21;
  Byte2Float(bytedata, v21);
  sub_19FFD30(&this->fields, 3, 2);
  v22 = *bpos + 4;
  *bpos = v22;
  Byte2Float(bytedata, v22);
  sub_19FFD30(&this->fields, 3, 3);
  *bpos += 4;
  *&this->rot.m00 = 0;
  p_rot = &this->rot;
  *&p_rot->m03 = 0;
  *&p_rot->m23 = 0;
  *&p_rot->m20 = 0;
  *&p_rot->m02 = 0;
  *&p_rot->m22 = 0;
  *&p_rot->m01 = 0;
  *&p_rot->m21 = 0;
  Byte2Float(bytedata, *bpos);
  sub_19FFD30(p_rot, 0, 0);
  v24 = *bpos + 4;
  *bpos = v24;
  Byte2Float(bytedata, v24);
  sub_19FFD30(p_rot, 0, 1);
  v25 = *bpos + 4;
  *bpos = v25;
  Byte2Float(bytedata, v25);
  sub_19FFD30(p_rot, 0, 2);
  v26 = *bpos + 4;
  *bpos = v26;
  Byte2Float(bytedata, v26);
  sub_19FFD30(p_rot, 0, 3);
  v27 = *bpos + 4;
  *bpos = v27;
  Byte2Float(bytedata, v27);
  sub_19FFD30(p_rot, 1, 0);
  v28 = *bpos + 4;
  *bpos = v28;
  Byte2Float(bytedata, v28);
  sub_19FFD30(p_rot, 1, 1);
  v29 = *bpos + 4;
  *bpos = v29;
  Byte2Float(bytedata, v29);
  sub_19FFD30(p_rot, 1, 2);
  v30 = *bpos + 4;
  *bpos = v30;
  Byte2Float(bytedata, v30);
  sub_19FFD30(p_rot, 1, 3);
  v31 = *bpos + 4;
  *bpos = v31;
  Byte2Float(bytedata, v31);
  sub_19FFD30(p_rot, 2, 0);
  v32 = *bpos + 4;
  *bpos = v32;
  Byte2Float(bytedata, v32);
  sub_19FFD30(p_rot, 2, 1);
  v33 = *bpos + 4;
  *bpos = v33;
  Byte2Float(bytedata, v33);
  sub_19FFD30(p_rot, 2, 2);
  v34 = *bpos + 4;
  *bpos = v34;
  Byte2Float(bytedata, v34);
  sub_19FFD30(p_rot, 2, 3);
  v35 = *bpos + 4;
  *bpos = v35;
  Byte2Float(bytedata, v35);
  sub_19FFD30(p_rot, 3, 0);
  v36 = *bpos + 4;
  *bpos = v36;
  Byte2Float(bytedata, v36);
  sub_19FFD30(p_rot, 3, 1);
  v37 = *bpos + 4;
  *bpos = v37;
  Byte2Float(bytedata, v37);
  sub_19FFD30(p_rot, 3, 2);
  v38 = *bpos + 4;
  *bpos = v38;
  Byte2Float(bytedata, v38);
  sub_19FFD30(p_rot, 3, 3);
  *bpos += 4;
}

// 0x19d1560
void dds3ParOffsetBuffParts_t__dCopy(dds3ParOffsetBuffParts_t *this, dds3ParOffsetBuffParts_t **dst) {
  dds3ParOffsetBuffParts_t_o *v5;
  struct UnityEngine_Vector3_array *pPosBuff;
  u32 *max_length;
  s64 v8;
  u64 v9;
  struct UnityEngine_Vector3_array *v10;
  f32 x;
  f32 z;
  f32 y;
  s32 v16;
  s32 v17;
  s64 v19;
  s32 v20;

  (*dst)->point = this->point;
  (*dst)->count = this->count;
  v5 = *dst;
  v5->pPosBuff = NewSpecific(UnityEngine_Vector3, LODWORD(this->pPosBuff->max_length));
  pPosBuff = this->pPosBuff;
  max_length = pPosBuff->max_length;
  if (max_length >= 1)
  {
    v8 = 0;
    v9 = 0;
    do
    {
      v10 = (*dst)->pPosBuff;
      x = pPosBuff->m_Items[v8].x;
      z = pPosBuff->m_Items[v8].z;
      y = pPosBuff->m_Items[v8].y;
      v20 = 0;
      v19 = 0;
      sub_8524C0(&v19, x, y, z);
      v16 = HIDWORD(v19);
      v17 = v20;
      max_length = (v10 + v8 * 12);
      ++v8;
      max_length[8] = v19;
      max_length[9] = v16;
      max_length[10] = v17;
      pPosBuff = this->pPosBuff;
      LODWORD(max_length) = pPosBuff->max_length;
      ++v9;
    }
    while (v9 < max_length);
  }
}

// 0x19d14b0
void dds3ParOffsetBuffParts_t__pCopy(dds3ParOffsetBuffParts_t *this, u8 **bytedata, s32 *bpos) {
  s32 v7;
  s32 v8;

  v7 = *bpos;
  this->point = Byte2UInt32(bytedata, v7);
  v8 = *bpos + 4;
  *bpos = v8;
  this->count = Byte2UInt32(bytedata, v8);
  *bpos += 4;
}

// 0x19d17c0
void dds3ParOffsetBuff_t__dCopy(dds3ParOffsetBuff_t *this, dds3ParOffsetBuff_t **dst) {
  (*dst)->length = this->length;
}

// 0x19d1720
void dds3ParOffsetBuff_t__pCopy(dds3ParOffsetBuff_t *this, u8 **bytedata, s32 *bpos) {
  s32 v7;

  v7 = *bpos;
  this->length = Byte2UInt32(bytedata, v7);
  *bpos += 4;
}

// 0x19d17e0
void dds3ParticleColorAnim_t__Clear(dds3ParticleColorAnim_t *this) {
  struct System_UInt32_array *v3;

  this->type = 0;
  v3 = NewSpecific(uint, 3u);
  this->frame_h = 0;
  *&this->alpha = 0;
  *&this->alpha_e = 0;
  this->color = v3;
  this->r_add = NewSpecific(f32, 2u);
  this->g_add = NewSpecific(f32, 2u);
  this->b_add = NewSpecific(f32, 2u);
  *&this->alpha_s_add = 0;
}

// 0x19d1ca0
void dds3ParticleColorAnim_t__dCopy(dds3ParticleColorAnim_t *this, dds3ParticleColorAnim_t **dst) {
  dds3ParticleColorAnim_t_o *v3;
  struct System_UInt32_array *v6;
  struct System_UInt32_array *color;
  struct System_UInt32_array *v8;
  u32 v9;
  struct System_UInt32_array *v10;
  struct System_UInt32_array *v11;
  u32 v13;
  struct System_UInt32_array *v15;
  struct System_UInt32_array *v16;
  u32 v18;
  struct System_Single_array *r_add;
  struct System_Single_array *v21;
  f32 v22;
  struct System_Single_array *v23;
  struct System_Single_array *v24;
  f32 v26;
  struct System_Single_array *g_add;
  struct System_Single_array *v29;
  f32 v30;
  struct System_Single_array *v31;
  struct System_Single_array *v32;
  f32 v34;
  struct System_Single_array *b_add;
  struct System_Single_array *v37;
  f32 v38;
  struct System_Single_array *v39;
  struct System_Single_array *v40;
  f32 v42;

  v3 = *dst;
  v3->type = 0;
  v6 = NewSpecific(uint, 3u);
  v3->frame_h = 0;
  *&v3->alpha = 0;
  *&v3->alpha_e = 0;
  v3->color = v6;
  v3->r_add = NewSpecific(f32, 2u);
  v3->g_add = NewSpecific(f32, 2u);
  v3->b_add = NewSpecific(f32, 2u);
  *&v3->alpha_s_add = 0;
  (*dst)->type = this->type;
  color = this->color;
  v8 = (*dst)->color;
  v9 = color->m_Items[0];
  v8->m_Items[0] = v9;
  v10 = this->color;
  v11 = (*dst)->color;
  v13 = v10->m_Items[1];
  v11->m_Items[1] = v13;
  v15 = this->color;
  v16 = (*dst)->color;
  v18 = v15->m_Items[2];
  v16->m_Items[2] = v18;
  (*dst)->alpha = this->alpha;
  (*dst)->alpha_s = this->alpha_s;
  (*dst)->alpha_e = this->alpha_e;
  (*dst)->frame_end = this->frame_end;
  (*dst)->frame_h = this->frame_h;
  r_add = this->r_add;
  v21 = (*dst)->r_add;
  v22 = r_add->m_Items[0];
  v21->m_Items[0] = v22;
  v23 = this->r_add;
  v24 = (*dst)->r_add;
  v26 = v23->m_Items[1];
  v24->m_Items[1] = v26;
  g_add = this->g_add;
  v29 = (*dst)->g_add;
  v30 = g_add->m_Items[0];
  v29->m_Items[0] = v30;
  v31 = this->g_add;
  v32 = (*dst)->g_add;
  v34 = v31->m_Items[1];
  v32->m_Items[1] = v34;
  b_add = this->b_add;
  v37 = (*dst)->b_add;
  v38 = b_add->m_Items[0];
  v37->m_Items[0] = v38;
  v39 = this->b_add;
  v40 = (*dst)->b_add;
  v42 = v39->m_Items[1];
  v40->m_Items[1] = v42;
  (*dst)->alpha_s_add = this->alpha_s_add;
  (*dst)->alpha_e_sub = this->alpha_e_sub;
}

// 0x19d1880
void dds3ParticleColorAnim_t__pCopy(dds3ParticleColorAnim_t *this, u8 **bytedata, s32 *bpos) {
  struct System_UInt32_array *v7;
  s32 v9;
  s32 v10;
  struct System_UInt32_array *color;
  u32 v12;
  s32 v14;
  struct System_UInt32_array *v15;
  u32 v16;
  s32 v18;
  struct System_UInt32_array *v19;
  u32 v20;
  s32 v22;
  s32 v23;
  s32 v24;
  s32 v25;
  s32 v26;
  s32 v27;
  struct System_Single_array *r_add;
  f32 v29;
  s32 v31;
  struct System_Single_array *v32;
  f32 v33;
  s32 v35;
  struct System_Single_array *g_add;
  f32 v37;
  s32 v39;
  struct System_Single_array *v40;
  f32 v41;
  s32 v43;
  struct System_Single_array *b_add;
  f32 v45;
  s32 v47;
  struct System_Single_array *v48;
  f32 v49;
  s32 v51;
  s32 v52;

  this->type = 0;
  v7 = NewSpecific(uint, 3u);
  this->frame_h = 0;
  *&this->alpha = 0;
  *&this->alpha_e = 0;
  this->color = v7;
  this->r_add = NewSpecific(f32, 2u);
  this->g_add = NewSpecific(f32, 2u);
  this->b_add = NewSpecific(f32, 2u);
  *&this->alpha_s_add = 0;
  v9 = *bpos;
  this->type = Byte2UInt32(bytedata, v9);
  v10 = *bpos + 4;
  *bpos = v10;
  color = this->color;
  v12 = Byte2UInt32(bytedata, v10);
  color->m_Items[0] = v12;
  v14 = *bpos + 4;
  *bpos = v14;
  v15 = this->color;
  v16 = Byte2UInt32(bytedata, v14);
  v15->m_Items[1] = v16;
  v18 = *bpos + 4;
  *bpos = v18;
  v19 = this->color;
  v20 = Byte2UInt32(bytedata, v18);
  v19->m_Items[2] = v20;
  v22 = *bpos + 4;
  *bpos = v22;
  this->alpha = Byte2UInt32(bytedata, v22);
  v23 = *bpos + 4;
  *bpos = v23;
  this->alpha_s = Byte2UInt32(bytedata, v23);
  v24 = *bpos + 4;
  *bpos = v24;
  this->alpha_e = Byte2UInt32(bytedata, v24);
  v25 = *bpos + 4;
  *bpos = v25;
  this->frame_end = Byte2UInt32(bytedata, v25);
  v26 = *bpos + 4;
  *bpos = v26;
  this->frame_h = Byte2UInt32(bytedata, v26);
  v27 = *bpos + 4;
  *bpos = v27;
  r_add = this->r_add;
  v29 = Byte2Float(bytedata, v27);
  r_add->m_Items[0] = v29;
  v31 = *bpos + 4;
  *bpos = v31;
  v32 = this->r_add;
  v33 = Byte2Float(bytedata, v31);
  v32->m_Items[1] = v33;
  v35 = *bpos + 4;
  *bpos = v35;
  g_add = this->g_add;
  v37 = Byte2Float(bytedata, v35);
  g_add->m_Items[0] = v37;
  v39 = *bpos + 4;
  *bpos = v39;
  v40 = this->g_add;
  v41 = Byte2Float(bytedata, v39);
  v40->m_Items[1] = v41;
  v43 = *bpos + 4;
  *bpos = v43;
  b_add = this->b_add;
  v45 = Byte2Float(bytedata, v43);
  b_add->m_Items[0] = v45;
  v47 = *bpos + 4;
  *bpos = v47;
  v48 = this->b_add;
  v49 = Byte2Float(bytedata, v47);
  v48->m_Items[1] = v49;
  v51 = *bpos + 4;
  *bpos = v51;
  this->alpha_s_add = Byte2UInt32(bytedata, v51);
  v52 = *bpos + 4;
  *bpos = v52;
  this->alpha_e_sub = Byte2UInt32(bytedata, v52);
  *bpos += 4;
}

// 0x19d2090
void dds3Particle_Basic_t__Clear(dds3Particle_Basic_t *this) {
  *&this->rot.m03 = 0;
  *&this->rot.m23 = 0;
  *&this->rot_b.m23 = 0;
  *&this->rot_b.m03 = 0;
  *&this->rot_b.m22 = 0;
  *&this->rot_b.m02 = 0;
  *&this->rot_b.m21 = 0;
  *&this->rot_b.m01 = 0;
  *&this->rot_b.m20 = 0;
  *&this->rot_b.m00 = 0;
  *&this->rot.m02 = 0;
  *&this->rot.m22 = 0;
  *&this->rot.m01 = 0;
  *&this->rot.m21 = 0;
  *&this->rot.m00 = 0;
  *&this->rot.m20 = 0;
  *&this->scale.x = 0;
  *&this->scale.z = 0;
  *&this->pos.x = 0;
  *&this->pos.z = 0;
}

// 0x19d28b0
void dds3Particle_Basic_t__dCopy(dds3Particle_Basic_t *this, dds3Particle_Basic_t **dst) {
  dds3Particle_Basic_t_o *v5;
  u64 *v6;
  struct dds3Particle_Effect_t_o *effect;
  dds3Particle_Basic_t_o *v8;
  struct dds3Particle_Effect_t_o *v9;
  u64 *v10;
  dds3Particle_Basic_t_o *v12;
  u64 *v13;
  dds3Particle_Basic_t_o *v15;
  u64 *v16;
  struct dds3Particle_Expansion_t_o *exp;
  dds3Particle_Basic_t_o *v18;
  dds3Particle_Basic_t_o *v19;
  struct UnityEngine_Matrix4x4_o *p_rot;
  struct UnityEngine_Matrix4x4_o *v21;
  struct UnityEngine_Matrix4x4_o *v22;
  struct UnityEngine_Matrix4x4_o *v23;
  struct UnityEngine_Matrix4x4_o *v24;
  struct UnityEngine_Matrix4x4_o *v25;
  struct UnityEngine_Matrix4x4_o *v26;
  struct UnityEngine_Matrix4x4_o *v27;
  struct UnityEngine_Matrix4x4_o *v28;
  struct UnityEngine_Matrix4x4_o *v29;
  struct UnityEngine_Matrix4x4_o *v30;
  struct UnityEngine_Matrix4x4_o *v31;
  struct UnityEngine_Matrix4x4_o *v32;
  struct UnityEngine_Matrix4x4_o *v33;
  struct UnityEngine_Matrix4x4_o *v34;
  struct UnityEngine_Matrix4x4_o *v35;
  dds3Particle_Basic_t_o *v36;
  dds3Particle_Basic_t_o *v37;
  u64 *v38;
  dds3Particle_Basic_t_o *v39;
  struct dds3Particle_Spiral_t3_o *pSpiral;
  dds3Particle_Basic_t_o *v41;
  u64 *v42;
  dds3Particle_Basic_t_o *v43;
  struct dds3Particle_Smoke_t3_o *pSmoke;
  dds3Particle_Basic_t_o *v45;
  u64 *v46;
  dds3Particle_Basic_t_o *v47;
  struct dds3Particle_Spark_t3_o *pSpark;
  dds3Particle_Basic_t_o *v49;
  u64 *v50;
  dds3Particle_Basic_t_o *v51;
  struct dds3Particle_Radiate_t3_o *pRadiate;
  dds3Particle_Basic_t_o *v53;
  u64 *v54;
  dds3Particle_Basic_t_o *v55;
  struct dds3Particle_SphereSpiral_t3_o *pSphereSpiral;
  dds3Particle_Basic_t_o *v57;
  u64 *v58;
  dds3Particle_Basic_t_o *v59;
  struct dds3Particle_SphereSmoke_t3_o *pSphereSmoke;
  dds3Particle_Basic_t_o *v61;
  u64 *v62;
  dds3Particle_Basic_t_o *v63;
  struct dds3Particle_SphereRing_t3_o *pSphereRing;
  dds3Particle_Basic_t_o *v65;
  u64 *v66;
  dds3Particle_Basic_t_o *v67;
  struct dds3Particle_Spark2_t3_o *pSpark2;
  dds3Particle_Basic_t_o *v69;
  u64 *v70;
  dds3Particle_Basic_t_o *v71;
  struct dds3Particle_SphereAtom_t3_o *pSphereAtom;
  dds3Particle_Basic_t_o *v73;
  u64 *v74;
  dds3Particle_Basic_t_o *v75;
  u64 *v76;
  dds3Particle_Basic_t_o *v78;
  u64 *v79;
  dds3Particle_Basic_t_o *v81;
  u64 *v82;

  (*dst)->pos.x = this->pos.x;
  (*dst)->pos.y = this->pos.y;
  (*dst)->pos.z = this->pos.z;
  (*dst)->pos.w = this->pos.w;
  (*dst)->scale.x = this->scale.x;
  (*dst)->scale.y = this->scale.y;
  (*dst)->scale.z = this->scale.z;
  (*dst)->scale.w = this->scale.w;
  (*dst)->number = this->number;
  (*dst)->numberO = this->numberO;
  (*dst)->frame = this->frame;
  (*dst)->billno = this->billno;
  (*dst)->billmode = this->billmode;
  if (this->effect)
  {
    v5 = *dst;
    v6 = Allocate(dds3Particle_Effect_t);
    _ctor(v6, 0);
    v5->effect = v6;
    effect = this->effect;
    v8 = *dst;
    v8->effect->type = effect->type;
    v9 = v8->effect;
    v10 = Allocate(dds3Particle_EffItem_t);
    _ctor(v10, 0);
    v9->param = v10;
    dds3Particle_EffItem_t__dCopy(effect->param, &v8->effect->param);
  }
  if (this->color)
  {
    v12 = *dst;
    v13 = Allocate(dds3ParticleColorAnim_t);
    _ctor(v13, 0);
    v12->color = v13;
    dds3ParticleColorAnim_t__dCopy(this->color, &(*dst)->color);
  }
  if (this->exp)
  {
    v15 = *dst;
    v16 = Allocate(dds3Particle_Expansion_t);
    _ctor(v16, 0);
    v15->exp = v16;
    exp = this->exp;
    v18 = *dst;
    (*dst)->exp->scl = exp->scl;
    v18->exp->rot_s = exp->rot_s;
    v18->exp->scl_r = exp->scl_r;
    v18->exp->rot_r = exp->rot_r;
    v18->exp->rot_type = exp->rot_type;
  }
  (*dst)->struct_size = this->struct_size;
  (*dst)->d_frame = this->d_frame;
  v19 = *dst;
  *&v19->rot.m03 = 0;
  *&v19->rot.m23 = 0;
  *&v19->rot.m02 = 0;
  *&v19->rot.m22 = 0;
  *&v19->rot.m01 = 0;
  *&v19->rot.m21 = 0;
  *&v19->rot.m00 = 0;
  *&v19->rot.m20 = 0;
  p_rot = &(*dst)->rot;
  sub_19FFB10(&this->rot, 0, 0);
  sub_19FFD30(p_rot, 0, 0);
  v21 = &(*dst)->rot;
  sub_19FFB10(&this->rot, 0, 1);
  sub_19FFD30(v21, 0, 1);
  v22 = &(*dst)->rot;
  sub_19FFB10(&this->rot, 0, 2);
  sub_19FFD30(v22, 0, 2);
  v23 = &(*dst)->rot;
  sub_19FFB10(&this->rot, 0, 3);
  sub_19FFD30(v23, 0, 3);
  v24 = &(*dst)->rot;
  sub_19FFB10(&this->rot, 1, 0);
  sub_19FFD30(v24, 1, 0);
  v25 = &(*dst)->rot;
  sub_19FFB10(&this->rot, 1, 1);
  sub_19FFD30(v25, 1, 1);
  v26 = &(*dst)->rot;
  sub_19FFB10(&this->rot, 1, 2);
  sub_19FFD30(v26, 1, 2);
  v27 = &(*dst)->rot;
  sub_19FFB10(&this->rot, 1, 3);
  sub_19FFD30(v27, 1, 3);
  v28 = &(*dst)->rot;
  sub_19FFB10(&this->rot, 2, 0);
  sub_19FFD30(v28, 2, 0);
  v29 = &(*dst)->rot;
  sub_19FFB10(&this->rot, 2, 1);
  sub_19FFD30(v29, 2, 1);
  v30 = &(*dst)->rot;
  sub_19FFB10(&this->rot, 2, 2);
  sub_19FFD30(v30, 2, 2);
  v31 = &(*dst)->rot;
  sub_19FFB10(&this->rot, 2, 3);
  sub_19FFD30(v31, 2, 3);
  v32 = &(*dst)->rot;
  sub_19FFB10(&this->rot, 3, 0);
  sub_19FFD30(v32, 3, 0);
  v33 = &(*dst)->rot;
  sub_19FFB10(&this->rot, 3, 1);
  sub_19FFD30(v33, 3, 1);
  v34 = &(*dst)->rot;
  sub_19FFB10(&this->rot, 3, 2);
  sub_19FFD30(v34, 3, 2);
  v35 = &(*dst)->rot;
  sub_19FFB10(&this->rot, 3, 3);
  sub_19FFD30(v35, 3, 3);
  (*dst)->abgr = this->abgr;
  (*dst)->hBillboard = this->hBillboard;
  v36 = *dst;
  *&v36->rot_b.m23 = 0;
  *&v36->rot_b.m03 = 0;
  *&v36->rot_b.m22 = 0;
  *&v36->rot_b.m02 = 0;
  *&v36->rot_b.m21 = 0;
  *&v36->rot_b.m01 = 0;
  *&v36->rot_b.m20 = 0;
  *&v36->rot_b.m00 = 0;
  if (this->pSpiral)
  {
    v37 = *dst;
    v38 = Allocate(dds3Particle_Spiral_t3);
    _ctor(v38, 0);
    v37->pSpiral = v38;
    v39 = *dst;
    pSpiral = this->pSpiral;
    (*dst)->pSpiral->basic = *dst;
    v39->pSpiral->type = pSpiral->type;
    v39->pSpiral->loop = pSpiral->loop;
    v39->pSpiral->timing = pSpiral->timing;
    v39->pSpiral->radius = pSpiral->radius;
    v39->pSpiral->simu_num = pSpiral->simu_num;
    v39->pSpiral->up_s = pSpiral->up_s;
    v39->pSpiral->roll_s = pSpiral->roll_s;
    v39->pSpiral->radius_e = pSpiral->radius_e;
    v39->pSpiral->accele = pSpiral->accele;
    v39->pSpiral->radius_s_r = pSpiral->radius_s_r;
    v39->pSpiral->radius_e_r = pSpiral->radius_e_r;
  }
  if (this->pSmoke)
  {
    v41 = *dst;
    v42 = Allocate(dds3Particle_Smoke_t3);
    _ctor(v42, 0);
    v41->pSmoke = v42;
    v43 = *dst;
    pSmoke = this->pSmoke;
    (*dst)->pSmoke->basic = *dst;
    v43->pSmoke->loop = pSmoke->loop;
    v43->pSmoke->timing = pSmoke->timing;
    v43->pSmoke->radius = pSmoke->radius;
    v43->pSmoke->up_s = pSmoke->up_s;
    v43->pSmoke->angle_s = pSmoke->angle_s;
    v43->pSmoke->amplitude = pSmoke->amplitude;
    v43->pSmoke->amplitude_s = pSmoke->amplitude_s;
    v43->pSmoke->accele = pSmoke->accele;
    v43->pSmoke->up_s_r = pSmoke->up_s_r;
    v43->pSmoke->ampli_r = pSmoke->ampli_r;
  }
  if (this->pSpark)
  {
    v45 = *dst;
    v46 = Allocate(dds3Particle_Spark_t3);
    _ctor(v46, 0);
    v45->pSpark = v46;
    v47 = *dst;
    pSpark = this->pSpark;
    (*dst)->pSpark->basic = *dst;
    v47->pSpark->type = pSpark->type;
    v47->pSpark->loop = pSpark->loop;
    v47->pSpark->timing = pSpark->timing;
    v47->pSpark->random = pSpark->random;
    v47->pSpark->radius = pSpark->radius;
    v47->pSpark->spread = pSpark->spread;
    v47->pSpark->gravity = pSpark->gravity;
    v47->pSpark->speed = pSpark->speed;
    v47->pSpark->accele = pSpark->accele;
    v47->pSpark->speed_r = pSpark->speed_r;
  }
  if (this->pRadiate)
  {
    v49 = *dst;
    v50 = Allocate(dds3Particle_Radiate_t3);
    _ctor(v50, 0);
    v49->pRadiate = v50;
    v51 = *dst;
    pRadiate = this->pRadiate;
    (*dst)->pRadiate->basic = *dst;
    v51->pRadiate->type = pRadiate->type;
    v51->pRadiate->loop = pRadiate->loop;
    v51->pRadiate->interval = pRadiate->interval;
    v51->pRadiate->random = pRadiate->random;
    v51->pRadiate->split = pRadiate->split;
    v51->pRadiate->angle = pRadiate->angle;
    v51->pRadiate->speed = pRadiate->speed;
  }
  if (this->pSphereSpiral)
  {
    v53 = *dst;
    v54 = Allocate(dds3Particle_SphereSpiral_t3);
    _ctor(v54, 0);
    v53->pSphereSpiral = v54;
    v55 = *dst;
    pSphereSpiral = this->pSphereSpiral;
    (*dst)->pSphereSpiral->basic = *dst;
    v55->pSphereSpiral->type = pSphereSpiral->type;
    v55->pSphereSpiral->loop = pSphereSpiral->loop;
    v55->pSphereSpiral->timing = pSphereSpiral->timing;
    v55->pSphereSpiral->radius = pSphereSpiral->radius;
    v55->pSphereSpiral->roll_s = pSphereSpiral->roll_s;
    v55->pSphereSpiral->radius_e = pSphereSpiral->radius_e;
    v55->pSphereSpiral->radius_s_r = pSphereSpiral->radius_s_r;
    v55->pSphereSpiral->radius_e_r = pSphereSpiral->radius_e_r;
  }
  if (this->pSphereSmoke)
  {
    v57 = *dst;
    v58 = Allocate(dds3Particle_SphereSmoke_t3);
    _ctor(v58, 0);
    v57->pSphereSmoke = v58;
    v59 = *dst;
    pSphereSmoke = this->pSphereSmoke;
    (*dst)->pSphereSmoke->basic = *dst;
    v59->pSphereSmoke->loop = pSphereSmoke->loop;
    v59->pSphereSmoke->timing = pSphereSmoke->timing;
    v59->pSphereSmoke->radius = pSphereSmoke->radius;
    v59->pSphereSmoke->up_s = pSphereSmoke->up_s;
    v59->pSphereSmoke->angle_s = pSphereSmoke->angle_s;
    v59->pSphereSmoke->amplitude = pSphereSmoke->amplitude;
    v59->pSphereSmoke->amplitude_s = pSphereSmoke->amplitude_s;
    v59->pSphereSmoke->accele = pSphereSmoke->accele;
    v59->pSphereSmoke->up_s_r = pSphereSmoke->up_s_r;
    v59->pSphereSmoke->ampli_r = pSphereSmoke->ampli_r;
    v59->pSphereSmoke->radius_s_r = pSphereSmoke->radius_s_r;
  }
  if (this->pSphereRing)
  {
    v61 = *dst;
    v62 = Allocate(dds3Particle_SphereRing_t3);
    _ctor(v62, 0);
    v61->pSphereRing = v62;
    v63 = *dst;
    pSphereRing = this->pSphereRing;
    (*dst)->pSphereRing->basic = *dst;
    v63->pSphereRing->type = pSphereRing->type;
    v63->pSphereRing->loop = pSphereRing->loop;
    v63->pSphereRing->timing = pSphereRing->timing;
    v63->pSphereRing->radius = pSphereRing->radius;
    v63->pSphereRing->radius_r = pSphereRing->radius_r;
    v63->pSphereRing->simu_num = pSphereRing->simu_num;
    v63->pSphereRing->roll_s = pSphereRing->roll_s;
  }
  if (this->pSpark2)
  {
    v65 = *dst;
    v66 = Allocate(dds3Particle_Spark2_t3);
    _ctor(v66, 0);
    v65->pSpark2 = v66;
    v67 = *dst;
    pSpark2 = this->pSpark2;
    (*dst)->pSpark2->basic = *dst;
    v67->pSpark2->type = pSpark2->type;
    v67->pSpark2->loop = pSpark2->loop;
    v67->pSpark2->timing = pSpark2->timing;
    v67->pSpark2->random = pSpark2->random;
    v67->pSpark2->radius = pSpark2->radius;
    v67->pSpark2->spread = pSpark2->spread;
    v67->pSpark2->gravity = pSpark2->gravity;
    v67->pSpark2->speed = pSpark2->speed;
    v67->pSpark2->accele = pSpark2->accele;
    v67->pSpark2->speed_r = pSpark2->speed_r;
    v67->pSpark2->angle = pSpark2->angle;
    v67->pSpark2->reserve1 = pSpark2->reserve1;
    v67->pSpark2->reserve2 = pSpark2->reserve2;
  }
  if (this->pSphereAtom)
  {
    v69 = *dst;
    v70 = Allocate(dds3Particle_SphereAtom_t3);
    _ctor(v70, 0);
    v69->pSphereAtom = v70;
    v71 = *dst;
    pSphereAtom = this->pSphereAtom;
    (*dst)->pSphereAtom->basic = *dst;
    v71->pSphereAtom->type = pSphereAtom->type;
    v71->pSphereAtom->loop = pSphereAtom->loop;
    v71->pSphereAtom->timing = pSphereAtom->timing;
    v71->pSphereAtom->radius = pSphereAtom->radius;
    v71->pSphereAtom->radius_e = pSphereAtom->radius_e;
    v71->pSphereAtom->speed = pSphereAtom->speed;
    v71->pSphereAtom->accele = pSphereAtom->accele;
  }
  if (this->pNop)
  {
    v73 = *dst;
    v74 = Allocate(dds3Particle_Nop_t3);
    _ctor(v74, 0);
    v73->pNop = v74;
    (*dst)->pNop->basic = *dst;
  }
  if (this->pSparkOffset)
  {
    v75 = *dst;
    v76 = Allocate(dds3Particle_SparkOffset_t3);
    _ctor(v76, 0);
    v75->pSparkOffset = v76;
    dds3Particle_SparkOffset_t3__dCopy(this->pSparkOffset, &(*dst)->pSparkOffset, *dst);
  }
  if (this->pSmokeOffset)
  {
    v78 = *dst;
    v79 = Allocate(dds3Particle_SmokeOffset_t3);
    _ctor(v79, 0);
    v78->pSmokeOffset = v79;
    dds3Particle_SmokeOffset_t3__dCopy(this->pSmokeOffset, &(*dst)->pSmokeOffset, *dst);
  }
  if (this->pSphereSpiral2)
  {
    v81 = *dst;
    v82 = Allocate(dds3Particle_SphereSpiral2_t3);
    _ctor(v82, 0);
    v81->pSphereSpiral2 = v82;
    dds3Particle_SphereSpiral2_t3__dCopy(
      this->pSphereSpiral2,
      &(*dst)->pSphereSpiral2,
      *dst);
  }
  (*dst)->uniqueid = this->uniqueid;
  (*dst)->par_scl_raito = this->par_scl_raito;
  (*dst)->eff_scl_raito = this->eff_scl_raito;
}

// 0x19d20d0
void dds3Particle_Basic_t__pCopy(dds3Particle_Basic_t *this, u8 **bytedata, s32 *bpos) {
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;
  s32 v11;
  s32 v12;
  s32 v13;
  s32 v14;
  s32 v15;
  s32 v16;
  s32 v17;
  u64 *v18;
  u64 *v20;
  u64 *v22;
  s32 v24;
  struct UnityEngine_Matrix4x4_o *p_rot;
  s32 v26;
  s32 v27;
  s32 v28;
  s32 v29;
  s32 v30;
  s32 v31;
  s32 v32;
  s32 v33;
  s32 v34;
  s32 v35;
  s32 v36;
  s32 v37;
  s32 v38;
  s32 v39;
  s32 v40;
  s32 v41;

  v7 = *bpos;
  this->pos.x = Byte2Float(bytedata, v7);
  v8 = *bpos + 4;
  *bpos = v8;
  this->pos.y = Byte2Float(bytedata, v8);
  v9 = *bpos + 4;
  *bpos = v9;
  this->pos.z = Byte2Float(bytedata, v9);
  v10 = *bpos + 4;
  *bpos = v10;
  this->pos.w = Byte2Float(bytedata, v10);
  v11 = *bpos + 4;
  *bpos = v11;
  this->scale.x = Byte2Float(bytedata, v11);
  v12 = *bpos + 4;
  *bpos = v12;
  this->scale.y = Byte2Float(bytedata, v12);
  v13 = *bpos + 4;
  *bpos = v13;
  this->scale.z = Byte2Float(bytedata, v13);
  v14 = *bpos + 4;
  *bpos = v14;
  this->scale.w = Byte2Float(bytedata, v14);
  v15 = *bpos + 4;
  *bpos = v15;
  this->number = Byte2UInt32(bytedata, v15);
  *bpos += 4;
  this->numberO = this->number;
  this->frame = Byte2UInt32(bytedata, *bpos);
  v16 = *bpos + 4;
  *bpos = v16;
  this->billno = Byte2UInt32(bytedata, v16);
  v17 = *bpos + 4;
  *bpos = v17;
  this->billmode = Byte2UInt16(bytedata, v17);
  *bpos += 4;
  v18 = Allocate(dds3Particle_Effect_t);
  _ctor(v18, 0);
  this->effect = v18;
  dds3Particle_Effect_t__pCopy(v18, bytedata, bpos);
  v20 = Allocate(dds3ParticleColorAnim_t);
  _ctor(v20, 0);
  this->color = v20;
  dds3ParticleColorAnim_t__pCopy(v20, bytedata, bpos);
  v22 = Allocate(dds3Particle_Expansion_t);
  _ctor(v22, 0);
  this->exp = v22;
  dds3Particle_Expansion_t__pCopy(v22, bytedata, bpos);
  this->struct_size = Byte2UInt32(bytedata, *bpos);
  v24 = *bpos + 4;
  *bpos = v24;
  this->d_frame = Byte2UInt32(bytedata, v24);
  *bpos += 12;
  *&this->rot.m00 = 0;
  p_rot = &this->rot;
  *&p_rot->m03 = 0;
  *&p_rot->m23 = 0;
  *&p_rot->m20 = 0;
  *&p_rot->m02 = 0;
  *&p_rot->m22 = 0;
  *&p_rot->m01 = 0;
  *&p_rot->m21 = 0;
  Byte2Float(bytedata, *bpos);
  sub_19FFD30(p_rot, 0, 0);
  v26 = *bpos + 4;
  *bpos = v26;
  Byte2Float(bytedata, v26);
  sub_19FFD30(p_rot, 0, 1);
  v27 = *bpos + 4;
  *bpos = v27;
  Byte2Float(bytedata, v27);
  sub_19FFD30(p_rot, 0, 2);
  v28 = *bpos + 4;
  *bpos = v28;
  Byte2Float(bytedata, v28);
  sub_19FFD30(p_rot, 0, 3);
  v29 = *bpos + 4;
  *bpos = v29;
  Byte2Float(bytedata, v29);
  sub_19FFD30(p_rot, 1, 0);
  v30 = *bpos + 4;
  *bpos = v30;
  Byte2Float(bytedata, v30);
  sub_19FFD30(p_rot, 1, 1);
  v31 = *bpos + 4;
  *bpos = v31;
  Byte2Float(bytedata, v31);
  sub_19FFD30(p_rot, 1, 2);
  v32 = *bpos + 4;
  *bpos = v32;
  Byte2Float(bytedata, v32);
  sub_19FFD30(p_rot, 1, 3);
  v33 = *bpos + 4;
  *bpos = v33;
  Byte2Float(bytedata, v33);
  sub_19FFD30(p_rot, 2, 0);
  v34 = *bpos + 4;
  *bpos = v34;
  Byte2Float(bytedata, v34);
  sub_19FFD30(p_rot, 2, 1);
  v35 = *bpos + 4;
  *bpos = v35;
  Byte2Float(bytedata, v35);
  sub_19FFD30(p_rot, 2, 2);
  v36 = *bpos + 4;
  *bpos = v36;
  Byte2Float(bytedata, v36);
  sub_19FFD30(p_rot, 2, 3);
  v37 = *bpos + 4;
  *bpos = v37;
  Byte2Float(bytedata, v37);
  sub_19FFD30(p_rot, 3, 0);
  v38 = *bpos + 4;
  *bpos = v38;
  Byte2Float(bytedata, v38);
  sub_19FFD30(p_rot, 3, 1);
  v39 = *bpos + 4;
  *bpos = v39;
  Byte2Float(bytedata, v39);
  sub_19FFD30(p_rot, 3, 2);
  v40 = *bpos + 4;
  *bpos = v40;
  Byte2Float(bytedata, v40);
  sub_19FFD30(p_rot, 3, 3);
  v41 = *bpos + 4;
  *bpos = v41;
  LODWORD(p_rot[1].m00) = Byte2UInt32(bytedata, v41);
  *bpos += 16;
  *&p_rot[2].m11 = 0;
  *&p_rot[2].m30 = 0;
  *&p_rot[2].m10 = 0;
  *&p_rot[1].m33 = 0;
  *&p_rot[1].m13 = 0;
  *&p_rot[1].m32 = 0;
  *&p_rot[1].m12 = 0;
  *&p_rot[1].m31 = 0;
  *bpos += 80;
}

// 0x19d40c0
void dds3Particle_BlurBuffList_t__pCopy(dds3Particle_BlurBuffList_t *this, u8 **bytedata, s32 *pos) {
  ;
}

// 0x19d40e0
void dds3Particle_BlurBuff_t__pCopy(dds3Particle_BlurBuff_t *this, u8 **bytedata, s32 *pos) {
  s32 v7;
  s32 v8;

  v7 = *pos;
  this->number = Byte2UInt16(bytedata, v7);
  v8 = *pos + 2;
  *pos = v8;
  this->point = Byte2UInt16(bytedata, v8);
  *pos += 14;
}

// 0x19d4260
void dds3Particle_Blur_t__dCopy(dds3Particle_Blur_t *this, dds3Particle_Blur_t **dst) {
  (*dst)->fields = this->fields;
}

// 0x19d41a0
void dds3Particle_Blur_t__pCopy(dds3Particle_Blur_t *this, u8 **bytedata, s32 *pos) {
  s32 v7;
  u64 *v8;

  v7 = *pos;
  this->length = Byte2UInt16(bytedata, v7);
  *pos += 4;
  v8 = Allocate(dds3Particle_BlurBuff_t);
  _ctor(v8, 0);
  this->hBlur = v8;
  *pos += 4;
}

// 0x19d4710
void dds3Particle_EffItem_t__dCopy(dds3Particle_EffItem_t *this, dds3Particle_EffItem_t **dst) {
  dds3Particle_EffItem_t_o *v5;
  u64 *v6;
  struct dds3Particle_Track3_t_o *track3;
  dds3Particle_EffItem_t_o *v8;
  dds3Particle_EffItem_t_o *v9;
  u64 *v10;
  struct dds3Particle_Track2_t_o *track2;
  dds3Particle_EffItem_t_o *v12;
  struct dds3Particle_Track2_t_o *v13;
  u64 *v14;
  dds3Particle_EffItem_t_o *v16;
  u64 *v17;
  struct dds3Particle_Track_t_o *track;
  dds3Particle_EffItem_t_o *v19;
  struct dds3Particle_Track_t_o *v20;
  u64 *v21;
  dds3Particle_EffItem_t_o *v23;
  u64 *v24;
  struct dds3Particle_Blur_t_o *blur;
  dds3Particle_EffItem_t_o *v26;

  (*dst)->track3 = 0;
  (*dst)->track2 = 0;
  (*dst)->track = 0;
  (*dst)->blur = 0;
  if (this->track3)
  {
    v5 = *dst;
    v6 = Allocate(dds3Particle_Track3_t);
    _ctor(v6, 0);
    v5->track3 = v6;
    track3 = this->track3;
    v8 = *dst;
    (*dst)->track3->length = track3->length;
    v8->track3->width = track3->width;
    v8->track3->color_s = track3->color_s;
    v8->track3->color_e = track3->color_e;
  }
  if (this->track2)
  {
    v9 = *dst;
    v10 = Allocate(dds3Particle_Track2_t);
    _ctor(v10, 0);
    v9->track2 = v10;
    track2 = this->track2;
    v12 = *dst;
    v12->track2->length = track2->length;
    v12->track2->width = track2->width;
    v12->track2->color_in = track2->color_in;
    v12->track2->color_out = track2->color_out;
    v13 = v12->track2;
    v14 = Allocate(dds3TrackPoly_t);
    _ctor(v14, 0);
    v13->hTrackPoly = v14;
    dds3TrackPoly_t__dCopy(track2->hTrackPoly, &v12->track2->hTrackPoly);
  }
  if (this->track)
  {
    v16 = *dst;
    v17 = Allocate(dds3Particle_Track_t);
    _ctor(v17, 0);
    v16->track = v17;
    track = this->track;
    v19 = *dst;
    v19->track->length = track->length;
    v19->track->width = track->width;
    v19->track->color = track->color;
    v20 = v19->track;
    v21 = Allocate(dds3TrackPoly_t);
    _ctor(v21, 0);
    v20->hTrackPoly = v21;
    dds3TrackPoly_t__dCopy(track->hTrackPoly, &v19->track->hTrackPoly);
  }
  if (this->blur)
  {
    v23 = *dst;
    v24 = Allocate(dds3Particle_Blur_t);
    _ctor(v24, 0);
    v23->blur = v24;
    blur = this->blur;
    v26 = *dst;
    (*dst)->blur->length = blur->length;
    v26->blur->hBlur = blur->hBlur;
  }
}

// 0x19d4290
void dds3Particle_EffItem_t__pCopy(dds3Particle_EffItem_t *this, u8 **bytedata, s32 *pos, u16 type) {
  dds3Particle_EffItem_t_Fields *p_fields;
  u64 *v10;
  u64 *v12;
  u64 *v14;
  u64 *v16;

  this->track3 = 0;
  p_fields = &this->fields;
  this->track = 0;
  this->blur = 0;
  this->track2 = 0;
  switch (type)
  {
    case 1u:
      v10 = Allocate(dds3Particle_Blur_t);
      _ctor(v10, 0);
      this->blur = v10;
      dds3Particle_Blur_t__pCopy(v10, bytedata, pos);
      break;
    case 2u:
      v12 = Allocate(dds3Particle_Track_t);
      _ctor(v12, 0);
      this->track = v12;
      dds3Particle_Track_t__pCopy(v12, bytedata, pos);
      break;
    case 3u:
      v14 = Allocate(dds3Particle_Track2_t);
      _ctor(v14, 0);
      this->track2 = v14;
      dds3Particle_Track2_t__pCopy(v14, bytedata, pos);
      break;
    case 4u:
      v16 = Allocate(dds3Particle_Track3_t);
      _ctor(v16, 0);
      p_fields->track3 = v16;
      dds3Particle_Track3_t__pCopy(v16, bytedata, pos);
      break;
    default:
      return;
  }
}

// 0x19d3570
void dds3Particle_Effect_t__dCopy(dds3Particle_Effect_t *this, dds3Particle_Effect_t **dst) {
  dds3Particle_Effect_t_o *v5;
  u64 *v6;

  (*dst)->type = this->type;
  v5 = *dst;
  v6 = Allocate(dds3Particle_EffItem_t);
  _ctor(v6, 0);
  v5->param = v6;
  dds3Particle_EffItem_t__dCopy(this->param, &(*dst)->param);
}

// 0x19d26a0
void dds3Particle_Effect_t__pCopy(dds3Particle_Effect_t *this, u8 **bytedata, s32 *pos) {
  s32 v7;
  u64 *v8;
  s32 type;
  s32 v11;

  v7 = *pos;
  this->type = Byte2UInt16(bytedata, v7);
  *pos += 4;
  v8 = Allocate(dds3Particle_EffItem_t);
  _ctor(v8, 0);
  this->param = v8;
  type = this->type;
  v11 = *pos;
  if (type)
    dds3Particle_EffItem_t__pCopy(v8, bytedata, pos, type);
  *pos = v11 + 20;
}

// 0x19d4b40
void dds3Particle_Exp_t__pCopy(dds3Particle_Exp_t *this, u8 **bytedata, s32 *pos) {
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;

  v7 = *pos;
  this->type = Byte2UInt32(bytedata, v7);
  v8 = *pos + 4;
  *pos = v8;
  this->size = Byte2UInt32(bytedata, v8);
  v9 = *pos + 4;
  *pos = v9;
  this->reserve1 = Byte2UInt32(bytedata, v9);
  v10 = *pos + 4;
  *pos = v10;
  this->reserve2 = Byte2UInt32(bytedata, v10);
  *pos += 4;
}

// 0x19d3600
void dds3Particle_Expansion_t__dCopy(dds3Particle_Expansion_t *this, dds3Particle_Expansion_t **dst) {
  (*dst)->fields = this->fields;
}

// 0x19d2790
void dds3Particle_Expansion_t__pCopy(dds3Particle_Expansion_t *this, u8 **bytedata, s32 *bpos) {
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;
  s64 v11;

  v7 = *bpos;
  this->scl = Byte2Float(bytedata, v7);
  v8 = *bpos + 4;
  *bpos = v8;
  this->rot_s = Byte2Float(bytedata, v8);
  v9 = *bpos + 4;
  *bpos = v9;
  this->scl_r = Byte2Float(bytedata, v9);
  v10 = *bpos + 4;
  *bpos = v10;
  this->rot_r = Byte2Float(bytedata, v10);
  v11 = *bpos + 4LL;
  *bpos = v11;
  this->rot_type = bytedata->m_Items[v11];
  *bpos += 4;
}

// 0x19d3b60
void dds3Particle_Nop_t3__dCopy(dds3Particle_Nop_t3 *this, dds3Particle_Nop_t3 **dst, dds3Particle_Basic_t *dstbasic) {
  (*dst)->basic = dstbasic;
}

// 0x19d4c40
void dds3Particle_Nop_t3__pCopy(dds3Particle_Nop_t3 *this, u8 **bytedata, s32 *bpos) {
  u64 *v7;

  v7 = Allocate(dds3Particle_Basic_t);
  _ctor(v7, 0);
  this->basic = v7;
  dds3Particle_Basic_t__pCopy(v7, bytedata, bpos);
}

// 0x19d4cc0
void dds3Particle_Physics_t__dCopy(dds3Particle_Physics_t *this, dds3Particle_Physics_t **dst) {
  struct parPhysics_t_array *pPhysics;
  dds3Particle_Physics_t_o *v6;
  il2cpp_array_size_t max_length;
  s64 v8;
  u64 v9;
  s64 v10;
  u32 *v12;
  u64 *v13;
  struct parPhysics_t_array *v15;
  parPhysics_t_o *v17;
  struct parPhysics_t_array *v18;

  pPhysics = this->pPhysics;
  this->hMem = 0;
  v6 = *dst;
  max_length = pPhysics->max_length;
  v8 = max_length;
  v6->pPhysics = NewSpecific(parPhysics_t, max_length);
  if (max_length >= 1)
  {
    v9 = 0;
    v10 = 32;
    do
    {
      v12 = (*dst)->pPhysics;
      v13 = Allocate(parPhysics_t);
      parPhysics_t___ctor(v13);
      *&v12[2 * v9 + 8] = v13;
      v15 = this->pPhysics;
      v17 = v15->m_Items[v9];
      v18 = (*dst)->pPhysics;
      parPhysics_t__dCopy(v17, (v18 + v10), 0);
      ++v9;
      v10 += 8;
    }
    while (v8 != v9);
  }
}

// 0x19d3830
void dds3Particle_Radiate_t3__dCopy(dds3Particle_Radiate_t3 *this, dds3Particle_Radiate_t3 **dst, dds3Particle_Basic_t *dstbasic) {
  (*dst)->basic = dstbasic;
  (*dst)->type = this->type;
  (*dst)->loop = this->loop;
  (*dst)->interval = this->interval;
  (*dst)->random = this->random;
  (*dst)->split = this->split;
  (*dst)->angle = this->angle;
  (*dst)->speed = this->speed;
}

// 0x19d4e60
void dds3Particle_Radiate_t3__pCopy(dds3Particle_Radiate_t3 *this, u8 **bytedata, s32 *bpos) {
  u64 *v7;
  s64 v10;
  s32 max_length;
  s64 v13;
  s32 v15;
  s64 v16;
  s32 v18;
  s32 v19;
  s32 v20;

  v7 = Allocate(dds3Particle_Basic_t);
  _ctor(v7, 0);
  this->basic = v7;
  dds3Particle_Basic_t__pCopy(v7, bytedata, bpos);
  v10 = *bpos;
  max_length = bytedata->max_length;
  if (v10 < max_length)
  {
    this->type = bytedata->m_Items[v10];
    v13 = *bpos + 1LL;
    *bpos = v13;
    this->loop = bytedata->m_Items[v13];
    v15 = *bpos + 3;
    *bpos = v15;
    this->interval = Byte2UInt32(bytedata, v15);
    v16 = *bpos + 4LL;
    *bpos = v16;
    this->random = bytedata->m_Items[v16];
    v18 = *bpos + 4;
    *bpos = v18;
    this->split = Byte2UInt32(bytedata, v18);
    v19 = *bpos + 4;
    *bpos = v19;
    this->angle = Byte2Float(bytedata, v19);
    v20 = *bpos + 4;
    *bpos = v20;
    this->speed = Byte2Float(bytedata, v20);
    *bpos += 4;
  }
}

// 0x19d3de0
void dds3Particle_SmokeOffset_t3__dCopy(dds3Particle_SmokeOffset_t3 *this, dds3Particle_SmokeOffset_t3 **dst, dds3Particle_Basic_t *dstbasic) {
  dds3Particle_SmokeOffset_t3_o *v7;
  dds3Particle_SmokeOffset_t3_o *v8;
  s64 i;
  struct System_UInt32_array *reserve;
  struct System_UInt32_array *v11;
  s32 v12;

  (*dst)->basic = dstbasic;
  (*dst)->loop = this->loop;
  (*dst)->timing = this->timing;
  (*dst)->radius = this->radius;
  (*dst)->up_s = this->up_s;
  (*dst)->angle_s = this->angle_s;
  (*dst)->amplitude = this->amplitude;
  (*dst)->amplitude_s = this->amplitude_s;
  (*dst)->accele = this->accele;
  (*dst)->up_s_r = this->up_s_r;
  (*dst)->ampli_r = this->ampli_r;
  v7 = *dst;
  v7->pOffset = NewSpecific(UnityEngine_Vector4, dstbasic->number);
  v8 = *dst;
  v8->reserve = NewSpecific(uint, 0x20u);
  for (i = 8; i != 40; ++i)
  {
    reserve = this->reserve;
    v11 = (*dst)->reserve;
    v12 = *(&reserve->obj.klass + i);
    *(&v11->obj.klass + i) = v12;
  }
}

// 0x19d5020
void dds3Particle_SmokeOffset_t3__pCopy(dds3Particle_SmokeOffset_t3 *this, u8 **bytedata, s32 *bpos) {
  u64 *v7;
  s64 v10;
  s32 max_length;
  s32 v13;
  s32 v14;
  s32 v15;
  s32 v16;
  s32 v17;
  s32 v18;
  s32 v19;
  s32 v20;
  s32 v21;
  struct System_UInt32_array *v22;
  s32 v24;
  struct System_UInt32_array *reserve;
  u64 v26;
  u32 v28;

  v7 = Allocate(dds3Particle_Basic_t);
  _ctor(v7, 0);
  this->basic = v7;
  dds3Particle_Basic_t__pCopy(v7, bytedata, bpos);
  v10 = *bpos;
  max_length = bytedata->max_length;
  if (v10 < max_length)
  {
    this->loop = bytedata->m_Items[v10];
    v13 = *bpos + 4;
    *bpos = v13;
    this->timing = Byte2UInt32(bytedata, v13);
    v14 = *bpos + 4;
    *bpos = v14;
    this->radius = Byte2Float(bytedata, v14);
    v15 = *bpos + 4;
    *bpos = v15;
    this->up_s = Byte2Float(bytedata, v15);
    v16 = *bpos + 4;
    *bpos = v16;
    this->angle_s = Byte2Float(bytedata, v16);
    v17 = *bpos + 4;
    *bpos = v17;
    this->amplitude = Byte2Float(bytedata, v17);
    v18 = *bpos + 4;
    *bpos = v18;
    this->amplitude_s = Byte2Float(bytedata, v18);
    v19 = *bpos + 4;
    *bpos = v19;
    this->accele = Byte2Float(bytedata, v19);
    v20 = *bpos + 4;
    *bpos = v20;
    this->up_s_r = Byte2Float(bytedata, v20);
    v21 = *bpos + 4;
    *bpos = v21;
    this->ampli_r = Byte2Float(bytedata, v21);
    *bpos += 12;
    v22 = NewSpecific(uint, 0x20u);
    this->reserve = v22;
    v24 = *bpos;
    reserve = v22;
    v26 = 0;
    {
LABEL_12:
      goto LABEL_14;
    }
    while (1)
    {
LABEL_14:
      v28 = Byte2UInt32(bytedata, v24);
      reserve->m_Items[v26] = v28;
      v24 = *bpos + 4;
      *bpos = v24;
      if (v26 == 31)
        break;
      reserve = this->reserve;
      ++v26;
        goto LABEL_12;
    }
  }
}

// 0x19d36f0
void dds3Particle_Smoke_t3__dCopy(dds3Particle_Smoke_t3 *this, dds3Particle_Smoke_t3 **dst, dds3Particle_Basic_t *dstbasic) {
  (*dst)->basic = dstbasic;
  (*dst)->loop = this->loop;
  (*dst)->timing = this->timing;
  (*dst)->radius = this->radius;
  (*dst)->up_s = this->up_s;
  (*dst)->angle_s = this->angle_s;
  (*dst)->amplitude = this->amplitude;
  (*dst)->amplitude_s = this->amplitude_s;
  (*dst)->accele = this->accele;
  (*dst)->up_s_r = this->up_s_r;
  (*dst)->ampli_r = this->ampli_r;
}

// 0x19d52b0
void dds3Particle_Smoke_t3__pCopy(dds3Particle_Smoke_t3 *this, u8 **bytedata, s32 *bpos) {
  s32 v7;
  u64 *v8;
  s32 v11;
  s32 max_length;
  s32 v14;
  s32 v15;
  s32 v16;
  s32 v17;
  s32 v18;
  s32 v19;
  s32 v20;
  s32 v21;
  s32 v22;

  v7 = *bpos;
  v8 = Allocate(dds3Particle_Basic_t);
  _ctor(v8, 0);
  this->basic = v8;
  dds3Particle_Basic_t__pCopy(v8, bytedata, bpos);
  v11 = *bpos;
  max_length = bytedata->max_length;
  if (*bpos < max_length
    || (v11 = this->basic->struct_size + v7,
        *bpos = v11,
        max_length = bytedata->max_length,
        v11 < max_length))
  {
    this->loop = bytedata->m_Items[v11];
    v14 = *bpos + 4;
    *bpos = v14;
    this->timing = Byte2UInt32(bytedata, v14);
    v15 = *bpos + 4;
    *bpos = v15;
    this->radius = Byte2Float(bytedata, v15);
    v16 = *bpos + 4;
    *bpos = v16;
    this->up_s = Byte2Float(bytedata, v16);
    v17 = *bpos + 4;
    *bpos = v17;
    this->angle_s = Byte2Float(bytedata, v17);
    v18 = *bpos + 4;
    *bpos = v18;
    this->amplitude = Byte2Float(bytedata, v18);
    v19 = *bpos + 4;
    *bpos = v19;
    this->amplitude_s = Byte2Float(bytedata, v19);
    v20 = *bpos + 4;
    *bpos = v20;
    this->accele = Byte2Float(bytedata, v20);
    v21 = *bpos + 4;
    *bpos = v21;
    this->up_s_r = Byte2Float(bytedata, v21);
    v22 = *bpos + 4;
    *bpos = v22;
    this->ampli_r = Byte2Float(bytedata, v22);
    *bpos += 4;
  }
}

// 0x19d3a30
void dds3Particle_Spark2_t3__dCopy(dds3Particle_Spark2_t3 *this, dds3Particle_Spark2_t3 **dst, dds3Particle_Basic_t *dstbasic) {
  (*dst)->basic = dstbasic;
  (*dst)->type = this->type;
  (*dst)->loop = this->loop;
  (*dst)->timing = this->timing;
  (*dst)->random = this->random;
  (*dst)->radius = this->radius;
  (*dst)->spread = this->spread;
  (*dst)->gravity = this->gravity;
  (*dst)->speed = this->speed;
  (*dst)->accele = this->accele;
  (*dst)->speed_r = this->speed_r;
  (*dst)->angle = this->angle;
  (*dst)->reserve1 = this->reserve1;
  (*dst)->reserve2 = this->reserve2;
}

// 0x19d54c0
void dds3Particle_Spark2_t3__pCopy(dds3Particle_Spark2_t3 *this, u8 **bytedata, s32 *bpos) {
  u64 *v7;
  s64 v10;
  s32 max_length;
  s64 v13;
  s32 v15;
  s64 v16;
  s32 v18;
  s32 v19;
  s32 v20;
  s32 v21;
  s32 v22;
  s32 v23;
  s32 v24;
  s32 v25;
  s32 v26;

  v7 = Allocate(dds3Particle_Basic_t);
  _ctor(v7, 0);
  this->basic = v7;
  dds3Particle_Basic_t__pCopy(v7, bytedata, bpos);
  v10 = *bpos;
  max_length = bytedata->max_length;
  if (v10 < max_length)
  {
    this->type = bytedata->m_Items[v10];
    v13 = *bpos + 1LL;
    *bpos = v13;
    this->loop = bytedata->m_Items[v13];
    v15 = *bpos + 3;
    *bpos = v15;
    this->timing = Byte2UInt32(bytedata, v15);
    v16 = *bpos + 4LL;
    *bpos = v16;
    this->random = bytedata->m_Items[v16];
    v18 = *bpos + 4;
    *bpos = v18;
    this->radius = Byte2Float(bytedata, v18);
    v19 = *bpos + 4;
    *bpos = v19;
    this->spread = Byte2Float(bytedata, v19);
    v20 = *bpos + 4;
    *bpos = v20;
    this->gravity = Byte2Float(bytedata, v20);
    v21 = *bpos + 4;
    *bpos = v21;
    this->speed = Byte2Float(bytedata, v21);
    v22 = *bpos + 4;
    *bpos = v22;
    this->accele = Byte2Float(bytedata, v22);
    v23 = *bpos + 4;
    *bpos = v23;
    this->speed_r = Byte2Float(bytedata, v23);
    v24 = *bpos + 4;
    *bpos = v24;
    this->angle = Byte2Float(bytedata, v24);
    v25 = *bpos + 4;
    *bpos = v25;
    this->reserve1 = Byte2Float(bytedata, v25);
    v26 = *bpos + 4;
    *bpos = v26;
    this->reserve2 = Byte2Float(bytedata, v26);
    *bpos += 4;
  }
}

// 0x19d3b80
void dds3Particle_SparkOffset_t3__dCopy(dds3Particle_SparkOffset_t3 *this, dds3Particle_SparkOffset_t3 **dst, dds3Particle_Basic_t *dstbasic) {
  dds3Particle_SparkOffset_t3_o *v7;
  struct System_UInt32_array *reserve;
  struct System_UInt32_array *v9;
  u32 v10;
  struct System_UInt32_array *v11;
  struct System_UInt32_array *v12;
  u32 v13;
  struct System_UInt32_array *v14;
  struct System_UInt32_array *v15;
  u32 v17;
  struct System_UInt32_array *v19;
  struct System_UInt32_array *v20;
  u32 v21;

  (*dst)->basic = dstbasic;
  (*dst)->type = this->type;
  (*dst)->loop = this->loop;
  (*dst)->timing = this->timing;
  (*dst)->random = this->random;
  (*dst)->radius = this->radius;
  (*dst)->spread = this->spread;
  (*dst)->gravity = this->gravity;
  (*dst)->speed = this->speed;
  (*dst)->accele = this->accele;
  (*dst)->speed_r = this->speed_r;
  v7 = *dst;
  v7->reserve = NewSpecific(uint, 4u);
  reserve = this->reserve;
  v9 = (*dst)->reserve;
  v10 = reserve->m_Items[0];
  v9->m_Items[0] = v10;
  v11 = this->reserve;
  v12 = (*dst)->reserve;
  v13 = v11->m_Items[1];
  v12->m_Items[1] = v13;
  v14 = this->reserve;
  v15 = (*dst)->reserve;
  v17 = v14->m_Items[2];
  v15->m_Items[2] = v17;
  v19 = this->reserve;
  v20 = (*dst)->reserve;
  v21 = v19->m_Items[3];
  v20->m_Items[3] = v21;
}

// 0x19d5730
void dds3Particle_SparkOffset_t3__pCopy(dds3Particle_SparkOffset_t3 *this, u8 **bytedata, s32 *bpos) {
  u64 *v7;
  s64 v10;
  s32 max_length;
  s64 v13;
  s32 v15;
  s64 v16;
  s32 v18;
  s32 v19;
  s32 v20;
  s32 v21;
  s32 v22;
  s32 v23;
  struct System_UInt32_array *v24;
  struct System_UInt32_array *v26;
  s32 v27;
  u32 v29;
  s32 v31;
  struct System_UInt32_array *reserve;
  u32 v34;
  s32 v36;
  struct System_UInt32_array *v37;
  u32 v39;
  s32 v41;
  struct System_UInt32_array *v42;
  u32 v43;

  v7 = Allocate(dds3Particle_Basic_t);
  _ctor(v7, 0);
  this->basic = v7;
  dds3Particle_Basic_t__pCopy(v7, bytedata, bpos);
  v10 = *bpos;
  max_length = bytedata->max_length;
  if (v10 < max_length)
  {
    this->type = bytedata->m_Items[v10];
    v13 = *bpos + 1LL;
    *bpos = v13;
    this->loop = bytedata->m_Items[v13];
    v15 = *bpos + 3;
    *bpos = v15;
    this->timing = Byte2UInt32(bytedata, v15);
    v16 = *bpos + 4LL;
    *bpos = v16;
    this->random = bytedata->m_Items[v16];
    v18 = *bpos + 4;
    *bpos = v18;
    this->radius = Byte2Float(bytedata, v18);
    v19 = *bpos + 4;
    *bpos = v19;
    this->spread = Byte2Float(bytedata, v19);
    v20 = *bpos + 4;
    *bpos = v20;
    this->gravity = Byte2Float(bytedata, v20);
    v21 = *bpos + 4;
    *bpos = v21;
    this->speed = Byte2Float(bytedata, v21);
    v22 = *bpos + 4;
    *bpos = v22;
    this->accele = Byte2Float(bytedata, v22);
    v23 = *bpos + 4;
    *bpos = v23;
    this->speed_r = Byte2Float(bytedata, v23);
    *bpos += 4;
    v24 = NewSpecific(uint, 4u);
    this->reserve = v24;
    v26 = v24;
    v27 = *bpos;
    v29 = Byte2UInt32(bytedata, v27);
    v26->m_Items[0] = v29;
    v31 = *bpos + 4;
    *bpos = v31;
    reserve = this->reserve;
    v34 = Byte2UInt32(bytedata, v31);
    reserve->m_Items[1] = v34;
    v36 = *bpos + 4;
    *bpos = v36;
    v37 = this->reserve;
    v39 = Byte2UInt32(bytedata, v36);
    v37->m_Items[2] = v39;
    v41 = *bpos + 4;
    *bpos = v41;
    v42 = this->reserve;
    v43 = Byte2UInt32(bytedata, v41);
    v42->m_Items[3] = v43;
    *bpos += 4;
  }
}

// 0x19d3790
void dds3Particle_Spark_t3__dCopy(dds3Particle_Spark_t3 *this, dds3Particle_Spark_t3 **dst, dds3Particle_Basic_t *dstbasic) {
  (*dst)->basic = dstbasic;
  (*dst)->type = this->type;
  (*dst)->loop = this->loop;
  (*dst)->timing = this->timing;
  (*dst)->random = this->random;
  (*dst)->radius = this->radius;
  (*dst)->spread = this->spread;
  (*dst)->gravity = this->gravity;
  (*dst)->speed = this->speed;
  (*dst)->accele = this->accele;
  (*dst)->speed_r = this->speed_r;
}

// 0x19d5ad0
void dds3Particle_Spark_t3__pCopy(dds3Particle_Spark_t3 *this, u8 **bytedata, s32 *bpos) {
  u64 *v7;
  s64 v10;
  s32 max_length;
  s64 v13;
  s32 v15;
  s64 v16;
  s32 v18;
  s32 v19;
  s32 v20;
  s32 v21;
  s32 v22;
  s32 v23;

  v7 = Allocate(dds3Particle_Basic_t);
  _ctor(v7, 0);
  this->basic = v7;
  dds3Particle_Basic_t__pCopy(v7, bytedata, bpos);
  v10 = *bpos;
  max_length = bytedata->max_length;
  if (v10 < max_length)
  {
    this->type = bytedata->m_Items[v10];
    v13 = *bpos + 1LL;
    *bpos = v13;
    this->loop = bytedata->m_Items[v13];
    v15 = *bpos + 3;
    *bpos = v15;
    this->timing = Byte2UInt32(bytedata, v15);
    v16 = *bpos + 4LL;
    *bpos = v16;
    this->random = bytedata->m_Items[v16];
    v18 = *bpos + 4;
    *bpos = v18;
    this->radius = Byte2Float(bytedata, v18);
    v19 = *bpos + 4;
    *bpos = v19;
    this->spread = Byte2Float(bytedata, v19);
    v20 = *bpos + 4;
    *bpos = v20;
    this->gravity = Byte2Float(bytedata, v20);
    v21 = *bpos + 4;
    *bpos = v21;
    this->speed = Byte2Float(bytedata, v21);
    v22 = *bpos + 4;
    *bpos = v22;
    this->accele = Byte2Float(bytedata, v22);
    v23 = *bpos + 4;
    *bpos = v23;
    this->speed_r = Byte2Float(bytedata, v23);
    *bpos += 4;
  }
}

// 0x19d3af0
void dds3Particle_SphereAtom_t3__dCopy(dds3Particle_SphereAtom_t3 *this, dds3Particle_SphereAtom_t3 **dst, dds3Particle_Basic_t *dstbasic) {
  (*dst)->basic = dstbasic;
  (*dst)->type = this->type;
  (*dst)->loop = this->loop;
  (*dst)->timing = this->timing;
  (*dst)->radius = this->radius;
  (*dst)->radius_e = this->radius_e;
  (*dst)->speed = this->speed;
  (*dst)->accele = this->accele;
}

// 0x19d5ce0
void dds3Particle_SphereAtom_t3__pCopy(dds3Particle_SphereAtom_t3 *this, u8 **bytedata, s32 *bpos) {
  u64 *v7;
  s64 v10;
  s32 max_length;
  s64 v13;
  s32 v15;
  s32 v16;
  s32 v17;
  s32 v18;
  s32 v19;

  v7 = Allocate(dds3Particle_Basic_t);
  _ctor(v7, 0);
  this->basic = v7;
  dds3Particle_Basic_t__pCopy(v7, bytedata, bpos);
  v10 = *bpos;
  max_length = bytedata->max_length;
  if (v10 < max_length)
  {
    this->type = bytedata->m_Items[v10];
    v13 = *bpos + 1LL;
    *bpos = v13;
    this->loop = bytedata->m_Items[v13];
    v15 = *bpos + 3;
    *bpos = v15;
    this->timing = Byte2UInt32(bytedata, v15);
    v16 = *bpos + 4;
    *bpos = v16;
    this->radius = Byte2Float(bytedata, v16);
    v17 = *bpos + 4;
    *bpos = v17;
    this->radius_e = Byte2Float(bytedata, v17);
    v18 = *bpos + 4;
    *bpos = v18;
    this->speed = Byte2Float(bytedata, v18);
    v19 = *bpos + 4;
    *bpos = v19;
    this->accele = Byte2Float(bytedata, v19);
    *bpos += 4;
  }
}

// 0x19d39c0
void dds3Particle_SphereRing_t3__dCopy(dds3Particle_SphereRing_t3 *this, dds3Particle_SphereRing_t3 **dst, dds3Particle_Basic_t *dstbasic) {
  (*dst)->basic = dstbasic;
  (*dst)->type = this->type;
  (*dst)->loop = this->loop;
  (*dst)->timing = this->timing;
  (*dst)->radius = this->radius;
  (*dst)->radius_r = this->radius_r;
  (*dst)->simu_num = this->simu_num;
  (*dst)->roll_s = this->roll_s;
}

// 0x19d5e90
void dds3Particle_SphereRing_t3__pCopy(dds3Particle_SphereRing_t3 *this, u8 **bytedata, s32 *bpos) {
  u64 *v7;
  s64 v10;
  s32 max_length;
  s64 v13;
  s32 v15;
  s32 v16;
  s32 v17;
  s32 v18;
  s32 v19;

  v7 = Allocate(dds3Particle_Basic_t);
  _ctor(v7, 0);
  this->basic = v7;
  dds3Particle_Basic_t__pCopy(v7, bytedata, bpos);
  v10 = *bpos;
  max_length = bytedata->max_length;
  if (v10 < max_length)
  {
    this->type = bytedata->m_Items[v10];
    v13 = *bpos + 1LL;
    *bpos = v13;
    this->loop = bytedata->m_Items[v13];
    v15 = *bpos + 3;
    *bpos = v15;
    this->timing = Byte2UInt32(bytedata, v15);
    v16 = *bpos + 4;
    *bpos = v16;
    this->radius = Byte2Float(bytedata, v16);
    v17 = *bpos + 4;
    *bpos = v17;
    this->radius_r = Byte2Float(bytedata, v17);
    v18 = *bpos + 4;
    *bpos = v18;
    this->simu_num = Byte2UInt32(bytedata, v18);
    v19 = *bpos + 4;
    *bpos = v19;
    this->roll_s = Byte2Float(bytedata, v19);
    *bpos += 4;
  }
}

// 0x19d3920
void dds3Particle_SphereSmoke_t3__dCopy(dds3Particle_SphereSmoke_t3 *this, dds3Particle_SphereSmoke_t3 **dst, dds3Particle_Basic_t *dstbasic) {
  (*dst)->basic = dstbasic;
  (*dst)->loop = this->loop;
  (*dst)->timing = this->timing;
  (*dst)->radius = this->radius;
  (*dst)->up_s = this->up_s;
  (*dst)->angle_s = this->angle_s;
  (*dst)->amplitude = this->amplitude;
  (*dst)->amplitude_s = this->amplitude_s;
  (*dst)->accele = this->accele;
  (*dst)->up_s_r = this->up_s_r;
  (*dst)->ampli_r = this->ampli_r;
  (*dst)->radius_s_r = this->radius_s_r;
}

// 0x19d6040
void dds3Particle_SphereSmoke_t3__pCopy(dds3Particle_SphereSmoke_t3 *this, u8 **bytedata, s32 *bpos) {
  u64 *v7;
  s64 v10;
  s32 max_length;
  s32 v13;
  s32 v14;
  s32 v15;
  s32 v16;
  s32 v17;
  s32 v18;
  s32 v19;
  s32 v20;
  s32 v21;
  s32 v22;

  v7 = Allocate(dds3Particle_Basic_t);
  _ctor(v7, 0);
  this->basic = v7;
  dds3Particle_Basic_t__pCopy(v7, bytedata, bpos);
  v10 = *bpos;
  max_length = bytedata->max_length;
  if (v10 < max_length)
  {
    this->loop = bytedata->m_Items[v10];
    v13 = *bpos + 4;
    *bpos = v13;
    this->timing = Byte2UInt32(bytedata, v13);
    v14 = *bpos + 4;
    *bpos = v14;
    this->radius = Byte2Float(bytedata, v14);
    v15 = *bpos + 4;
    *bpos = v15;
    this->up_s = Byte2Float(bytedata, v15);
    v16 = *bpos + 4;
    *bpos = v16;
    this->angle_s = Byte2Float(bytedata, v16);
    v17 = *bpos + 4;
    *bpos = v17;
    this->amplitude = Byte2Float(bytedata, v17);
    v18 = *bpos + 4;
    *bpos = v18;
    this->amplitude_s = Byte2Float(bytedata, v18);
    v19 = *bpos + 4;
    *bpos = v19;
    this->accele = Byte2Float(bytedata, v19);
    v20 = *bpos + 4;
    *bpos = v20;
    this->up_s_r = Byte2Float(bytedata, v20);
    v21 = *bpos + 4;
    *bpos = v21;
    this->ampli_r = Byte2Float(bytedata, v21);
    v22 = *bpos + 4;
    *bpos = v22;
    this->radius_s_r = Byte2Float(bytedata, v22);
    *bpos += 4;
  }
}

// 0x19d3f90
void dds3Particle_SphereSpiral2_t3__dCopy(dds3Particle_SphereSpiral2_t3 *this, dds3Particle_SphereSpiral2_t3 **dst, dds3Particle_Basic_t *dstbasic) {
  dds3Particle_SphereSpiral2_t3_o *v7;
  u64 *v8;

  (*dst)->basic = dstbasic;
  (*dst)->type = this->type;
  (*dst)->loop = this->loop;
  (*dst)->timing = this->timing;
  (*dst)->radius = this->radius;
  (*dst)->roll_s = this->roll_s;
  (*dst)->radius_e = this->radius_e;
  (*dst)->radius_s_r = this->radius_s_r;
  (*dst)->radius_e_r = this->radius_e_r;
  (*dst)->old_pos.x = this->old_pos.x;
  (*dst)->old_pos.y = this->old_pos.y;
  (*dst)->old_pos.z = this->old_pos.z;
  (*dst)->old_pos.w = this->old_pos.w;
  v7 = *dst;
  v8 = Allocate(dds3ParOffsetBuff_t);
  _ctor(v8, 0);
  v7->OffBuff = v8;
  (*dst)->OffBuff->length = this->OffBuff->length;
}

// 0x19d6240
void dds3Particle_SphereSpiral2_t3__pCopy(dds3Particle_SphereSpiral2_t3 *this, u8 **bytedata, s32 *bpos) {
  u64 *v7;
  s64 v10;
  s32 max_length;
  s64 v13;
  s32 v15;
  s32 v16;
  s32 v17;
  s32 v18;
  s32 v19;
  s32 v20;
  s32 v21;
  s32 v22;
  s32 v23;
  s32 v24;
  u64 *v25;
  s32 v27;

  v7 = Allocate(dds3Particle_Basic_t);
  _ctor(v7, 0);
  this->basic = v7;
  dds3Particle_Basic_t__pCopy(v7, bytedata, bpos);
  v10 = *bpos;
  max_length = bytedata->max_length;
  if (v10 < max_length)
  {
    this->type = bytedata->m_Items[v10];
    v13 = *bpos + 1LL;
    *bpos = v13;
    this->loop = bytedata->m_Items[v13];
    v15 = *bpos + 3;
    *bpos = v15;
    this->timing = Byte2UInt32(bytedata, v15);
    v16 = *bpos + 4;
    *bpos = v16;
    this->radius = Byte2Float(bytedata, v16);
    v17 = *bpos + 4;
    *bpos = v17;
    this->roll_s = Byte2Float(bytedata, v17);
    v18 = *bpos + 4;
    *bpos = v18;
    this->radius_e = Byte2Float(bytedata, v18);
    v19 = *bpos + 4;
    *bpos = v19;
    this->radius_s_r = Byte2Float(bytedata, v19);
    v20 = *bpos + 4;
    *bpos = v20;
    this->radius_e_r = Byte2Float(bytedata, v20);
    v21 = *bpos + 4;
    *bpos = v21;
    this->old_pos.x = Byte2Float(bytedata, v21);
    v22 = *bpos + 4;
    *bpos = v22;
    this->old_pos.y = Byte2Float(bytedata, v22);
    v23 = *bpos + 4;
    *bpos = v23;
    this->old_pos.z = Byte2Float(bytedata, v23);
    v24 = *bpos + 4;
    *bpos = v24;
    this->old_pos.w = Byte2Float(bytedata, v24);
    *bpos += 4;
    v25 = Allocate(dds3ParOffsetBuff_t);
    _ctor(v25, 0);
    this->OffBuff = v25;
    v27 = *bpos;
    *(v25 + 6) = Byte2UInt32(bytedata, v27);
    *bpos += 4;
  }
}

// 0x19d38a0
void dds3Particle_SphereSpiral_t3__dCopy(dds3Particle_SphereSpiral_t3 *this, dds3Particle_SphereSpiral_t3 **dst, dds3Particle_Basic_t *dstbasic) {
  (*dst)->basic = dstbasic;
  (*dst)->type = this->type;
  (*dst)->loop = this->loop;
  (*dst)->timing = this->timing;
  (*dst)->radius = this->radius;
  (*dst)->roll_s = this->roll_s;
  (*dst)->radius_e = this->radius_e;
  (*dst)->radius_s_r = this->radius_s_r;
  (*dst)->radius_e_r = this->radius_e_r;
}

// 0x19d6500
void dds3Particle_SphereSpiral_t3__pCopy(dds3Particle_SphereSpiral_t3 *this, u8 **bytedata, s32 *bpos) {
  u64 *v7;
  s64 v10;
  s32 max_length;
  s64 v13;
  s32 v15;
  s32 v16;
  s32 v17;
  s32 v18;
  s32 v19;
  s32 v20;

  v7 = Allocate(dds3Particle_Basic_t);
  _ctor(v7, 0);
  this->basic = v7;
  dds3Particle_Basic_t__pCopy(v7, bytedata, bpos);
  v10 = *bpos;
  max_length = bytedata->max_length;
  if (v10 < max_length)
  {
    this->type = bytedata->m_Items[v10];
    v13 = *bpos + 1LL;
    *bpos = v13;
    this->loop = bytedata->m_Items[v13];
    v15 = *bpos + 3;
    *bpos = v15;
    this->timing = Byte2UInt32(bytedata, v15);
    v16 = *bpos + 4;
    *bpos = v16;
    this->radius = Byte2Float(bytedata, v16);
    v17 = *bpos + 4;
    *bpos = v17;
    this->roll_s = Byte2Float(bytedata, v17);
    v18 = *bpos + 4;
    *bpos = v18;
    this->radius_e = Byte2Float(bytedata, v18);
    v19 = *bpos + 4;
    *bpos = v19;
    this->radius_s_r = Byte2Float(bytedata, v19);
    v20 = *bpos + 4;
    *bpos = v20;
    this->radius_e_r = Byte2Float(bytedata, v20);
    *bpos += 4;
  }
}

// 0x19d3650
void dds3Particle_Spiral_t3__dCopy(dds3Particle_Spiral_t3 *this, dds3Particle_Spiral_t3 **dst, dds3Particle_Basic_t *dstbasic) {
  (*dst)->basic = dstbasic;
  (*dst)->type = this->type;
  (*dst)->loop = this->loop;
  (*dst)->timing = this->timing;
  (*dst)->radius = this->radius;
  (*dst)->simu_num = this->simu_num;
  (*dst)->up_s = this->up_s;
  (*dst)->roll_s = this->roll_s;
  (*dst)->radius_e = this->radius_e;
  (*dst)->accele = this->accele;
  (*dst)->radius_s_r = this->radius_s_r;
  (*dst)->radius_e_r = this->radius_e_r;
}

// 0x19d66c0
void dds3Particle_Spiral_t3__pCopy(dds3Particle_Spiral_t3 *this, u8 **bytedata, s32 *bpos) {
  u64 *v7;
  s64 v10;
  s32 max_length;
  s64 v13;
  s32 v15;
  s32 v16;
  s32 v17;
  s32 v18;
  s32 v19;
  s32 v20;
  s32 v21;
  s32 v22;
  s32 v23;

  v7 = Allocate(dds3Particle_Basic_t);
  _ctor(v7, 0);
  this->basic = v7;
  dds3Particle_Basic_t__pCopy(v7, bytedata, bpos);
  v10 = *bpos;
  max_length = bytedata->max_length;
  if (v10 < max_length)
  {
    this->type = bytedata->m_Items[v10];
    v13 = *bpos + 1LL;
    *bpos = v13;
    this->loop = bytedata->m_Items[v13];
    v15 = *bpos + 3;
    *bpos = v15;
    this->timing = Byte2UInt32(bytedata, v15);
    v16 = *bpos + 4;
    *bpos = v16;
    this->radius = Byte2Float(bytedata, v16);
    v17 = *bpos + 4;
    *bpos = v17;
    this->simu_num = Byte2UInt32(bytedata, v17);
    v18 = *bpos + 4;
    *bpos = v18;
    this->up_s = Byte2Float(bytedata, v18);
    v19 = *bpos + 4;
    *bpos = v19;
    this->roll_s = Byte2Float(bytedata, v19);
    v20 = *bpos + 4;
    *bpos = v20;
    this->radius_e = Byte2Float(bytedata, v20);
    v21 = *bpos + 4;
    *bpos = v21;
    this->accele = Byte2Float(bytedata, v21);
    v22 = *bpos + 4;
    *bpos = v22;
    this->radius_s_r = Byte2Float(bytedata, v22);
    v23 = *bpos + 4;
    *bpos = v23;
    this->radius_e_r = Byte2Float(bytedata, v23);
    *bpos += 4;
  }
}

// 0x19d49e0
void dds3Particle_Track2_t__dCopy(dds3Particle_Track2_t *this, dds3Particle_Track2_t **dst) {
  dds3Particle_Track2_t_o *v5;
  u64 *v6;

  (*dst)->length = this->length;
  (*dst)->width = this->width;
  (*dst)->color_in = this->color_in;
  (*dst)->color_out = this->color_out;
  v5 = *dst;
  v6 = Allocate(dds3TrackPoly_t);
  _ctor(v6, 0);
  v5->hTrackPoly = v6;
  dds3TrackPoly_t__dCopy(this->hTrackPoly, &(*dst)->hTrackPoly);
}

// 0x19d4520
void dds3Particle_Track2_t__pCopy(dds3Particle_Track2_t *this, u8 **bytedata, s32 *pos) {
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;

  v7 = *pos;
  this->length = Byte2UInt16(bytedata, v7);
  v8 = *pos + 4;
  *pos = v8;
  this->width = Byte2Float(bytedata, v8);
  v9 = *pos + 4;
  *pos = v9;
  this->color_in = Byte2UInt32(bytedata, v9);
  v10 = *pos + 4;
  *pos = v10;
  this->color_out = Byte2UInt32(bytedata, v10);
  *pos += 8;
}

// 0x19d49a0
void dds3Particle_Track3_t__dCopy(dds3Particle_Track3_t *this, dds3Particle_Track3_t **dst) {
  (*dst)->length = this->length;
  (*dst)->width = this->width;
  (*dst)->color_s = this->color_s;
  (*dst)->color_e = this->color_e;
}

// 0x19d4620
void dds3Particle_Track3_t__pCopy(dds3Particle_Track3_t *this, u8 **bytedata, s32 *pos) {
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;

  v7 = *pos;
  this->length = Byte2UInt16(bytedata, v7);
  v8 = *pos + 4;
  *pos = v8;
  this->width = Byte2Float(bytedata, v8);
  v9 = *pos + 4;
  *pos = v9;
  this->color_s = Byte2UInt32(bytedata, v9);
  v10 = *pos + 4;
  *pos = v10;
  this->color_e = Byte2UInt32(bytedata, v10);
  *pos += 8;
}

// 0x19d4a90
void dds3Particle_Track_t__dCopy(dds3Particle_Track_t *this, dds3Particle_Track_t **dst) {
  dds3Particle_Track_t_o *v5;
  u64 *v6;

  (*dst)->length = this->length;
  (*dst)->width = this->width;
  (*dst)->color = this->color;
  v5 = *dst;
  v6 = Allocate(dds3TrackPoly_t);
  _ctor(v6, 0);
  v5->hTrackPoly = v6;
  dds3TrackPoly_t__dCopy(this->hTrackPoly, &(*dst)->hTrackPoly);
}

// 0x19d4440
void dds3Particle_Track_t__pCopy(dds3Particle_Track_t *this, u8 **bytedata, s32 *pos) {
  s32 v7;
  s32 v8;
  s32 v9;

  v7 = *pos;
  this->length = Byte2UInt16(bytedata, v7);
  v8 = *pos + 4;
  *pos = v8;
  this->width = Byte2Float(bytedata, v8);
  v9 = *pos + 4;
  *pos = v9;
  this->color = Byte2UInt32(bytedata, v9);
  *pos += 8;
}

// 0x19d71e0
void dds3SpPoly_Basic_t__pClone(dds3SpPoly_Basic_t *this, dds3SpPoly_Basic_t **dst) {
  dds3SpPoly_Basic_t_o *v3;
  struct UnityEngine_Matrix4x4_o *p_rot;
  struct UnityEngine_Matrix4x4_o *v7;
  struct UnityEngine_Matrix4x4_o *v8;
  struct UnityEngine_Matrix4x4_o *v9;
  struct UnityEngine_Matrix4x4_o *v10;
  struct UnityEngine_Matrix4x4_o *v11;
  struct UnityEngine_Matrix4x4_o *v12;
  struct UnityEngine_Matrix4x4_o *v13;
  struct UnityEngine_Matrix4x4_o *v14;
  struct UnityEngine_Matrix4x4_o *v15;
  struct UnityEngine_Matrix4x4_o *v16;
  struct UnityEngine_Matrix4x4_o *v17;
  struct UnityEngine_Matrix4x4_o *v18;
  struct UnityEngine_Matrix4x4_o *v19;
  struct UnityEngine_Matrix4x4_o *v20;
  struct UnityEngine_Matrix4x4_o *v21;
  struct UnityEngine_Matrix4x4_o *v22;

  (*dst)->pos.x = this->pos.x;
  (*dst)->pos.y = this->pos.y;
  (*dst)->pos.z = this->pos.z;
  (*dst)->pos.w = this->pos.w;
  (*dst)->number = this->number;
  (*dst)->frame = this->frame;
  (*dst)->struct_size = this->struct_size;
  (*dst)->d_frame = this->d_frame;
  v3 = *dst;
  *&v3->rot.m03 = 0;
  *&v3->rot.m23 = 0;
  *&v3->rot.m02 = 0;
  *&v3->rot.m22 = 0;
  p_rot = &this->rot;
  *&v3->rot.m01 = 0;
  *&v3->rot.m21 = 0;
  *&v3->rot.m00 = 0;
  *&v3->rot.m20 = 0;
  v7 = &(*dst)->rot;
  sub_19FFB10(&this->rot, 0, 0);
  sub_19FFD30(v7, 0, 0);
  v8 = &(*dst)->rot;
  sub_19FFB10(p_rot, 0, 1);
  sub_19FFD30(v8, 0, 1);
  v9 = &(*dst)->rot;
  sub_19FFB10(p_rot, 0, 2);
  sub_19FFD30(v9, 0, 2);
  v10 = &(*dst)->rot;
  sub_19FFB10(p_rot, 0, 3);
  sub_19FFD30(v10, 0, 3);
  v11 = &(*dst)->rot;
  sub_19FFB10(p_rot, 1, 0);
  sub_19FFD30(v11, 1, 0);
  v12 = &(*dst)->rot;
  sub_19FFB10(p_rot, 1, 1);
  sub_19FFD30(v12, 1, 1);
  v13 = &(*dst)->rot;
  sub_19FFB10(p_rot, 1, 2);
  sub_19FFD30(v13, 1, 2);
  v14 = &(*dst)->rot;
  sub_19FFB10(p_rot, 1, 3);
  sub_19FFD30(v14, 1, 3);
  v15 = &(*dst)->rot;
  sub_19FFB10(p_rot, 2, 0);
  sub_19FFD30(v15, 2, 0);
  v16 = &(*dst)->rot;
  sub_19FFB10(p_rot, 2, 1);
  sub_19FFD30(v16, 2, 1);
  v17 = &(*dst)->rot;
  sub_19FFB10(p_rot, 2, 2);
  sub_19FFD30(v17, 2, 2);
  v18 = &(*dst)->rot;
  sub_19FFB10(p_rot, 2, 3);
  sub_19FFD30(v18, 2, 3);
  v19 = &(*dst)->rot;
  sub_19FFB10(p_rot, 3, 0);
  sub_19FFD30(v19, 3, 0);
  v20 = &(*dst)->rot;
  sub_19FFB10(p_rot, 3, 1);
  sub_19FFD30(v20, 3, 1);
  v21 = &(*dst)->rot;
  sub_19FFB10(p_rot, 3, 2);
  sub_19FFD30(v21, 3, 2);
  v22 = &(*dst)->rot;
  sub_19FFB10(p_rot, 3, 3);
  sub_19FFD30(v22, 3, 3);
  (*dst)->abgr = this->abgr;
  (*dst)->loop = this->loop;
  (*dst)->mode = this->mode;
  (*dst)->alpha_s = this->alpha_s;
  (*dst)->alpha_e = this->alpha_e;
  (*dst)->pRing_Old = 0;
  (*dst)->pRing = 0;
  (*dst)->pSphereRing = 0;
  (*dst)->pRollRing = 0;
}

// 0x19d6d00
void dds3SpPoly_Basic_t__pCopy(dds3SpPoly_Basic_t *this, u8 **bytedata, s32 *bpos) {
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;
  s32 v11;
  s32 v12;
  s32 v13;
  s32 v14;
  s32 v15;
  s32 v16;
  s32 v17;
  s32 v18;
  s32 v19;
  s32 v20;
  s32 v21;
  s32 v22;
  s32 v23;
  s32 v24;
  s32 v25;
  s32 v26;
  s32 v27;
  s32 v28;
  s32 v29;
  s32 v30;
  s64 v31;
  s32 v33;
  s32 v34;
  s32 v35;

  v7 = *bpos;
  this->pos.x = Byte2Float(bytedata, v7);
  v8 = *bpos + 4;
  *bpos = v8;
  this->pos.y = Byte2Float(bytedata, v8);
  v9 = *bpos + 4;
  *bpos = v9;
  this->pos.z = Byte2Float(bytedata, v9);
  v10 = *bpos + 4;
  *bpos = v10;
  this->pos.w = Byte2Float(bytedata, v10);
  v11 = *bpos + 4;
  *bpos = v11;
  this->number = Byte2UInt32(bytedata, v11);
  v12 = *bpos + 4;
  *bpos = v12;
  this->frame = Byte2UInt32(bytedata, v12);
  v13 = *bpos + 4;
  *bpos = v13;
  this->struct_size = Byte2UInt32(bytedata, v13);
  v14 = *bpos + 4;
  *bpos = v14;
  this->d_frame = Byte2UInt32(bytedata, v14);
  *bpos += 4;
  *&this->rot.m00 = 0;
  *&this->rot.m03 = 0;
  *&this->rot.m23 = 0;
  *&this->rot.m20 = 0;
  *&this->rot.m02 = 0;
  *&this->rot.m22 = 0;
  *&this->rot.m01 = 0;
  *&this->rot.m21 = 0;
  Byte2Float(bytedata, *bpos);
  sub_19FFD30(&this->rot, 0, 0);
  v15 = *bpos + 4;
  *bpos = v15;
  Byte2Float(bytedata, v15);
  sub_19FFD30(&this->rot, 0, 1);
  v16 = *bpos + 4;
  *bpos = v16;
  Byte2Float(bytedata, v16);
  sub_19FFD30(&this->rot, 0, 2);
  v17 = *bpos + 4;
  *bpos = v17;
  Byte2Float(bytedata, v17);
  sub_19FFD30(&this->rot, 0, 3);
  v18 = *bpos + 4;
  *bpos = v18;
  Byte2Float(bytedata, v18);
  sub_19FFD30(&this->rot, 1, 0);
  v19 = *bpos + 4;
  *bpos = v19;
  Byte2Float(bytedata, v19);
  sub_19FFD30(&this->rot, 1, 1);
  v20 = *bpos + 4;
  *bpos = v20;
  Byte2Float(bytedata, v20);
  sub_19FFD30(&this->rot, 1, 2);
  v21 = *bpos + 4;
  *bpos = v21;
  Byte2Float(bytedata, v21);
  sub_19FFD30(&this->rot, 1, 3);
  v22 = *bpos + 4;
  *bpos = v22;
  Byte2Float(bytedata, v22);
  sub_19FFD30(&this->rot, 2, 0);
  v23 = *bpos + 4;
  *bpos = v23;
  Byte2Float(bytedata, v23);
  sub_19FFD30(&this->rot, 2, 1);
  v24 = *bpos + 4;
  *bpos = v24;
  Byte2Float(bytedata, v24);
  sub_19FFD30(&this->rot, 2, 2);
  v25 = *bpos + 4;
  *bpos = v25;
  Byte2Float(bytedata, v25);
  sub_19FFD30(&this->rot, 2, 3);
  v26 = *bpos + 4;
  *bpos = v26;
  Byte2Float(bytedata, v26);
  sub_19FFD30(&this->rot, 3, 0);
  v27 = *bpos + 4;
  *bpos = v27;
  Byte2Float(bytedata, v27);
  sub_19FFD30(&this->rot, 3, 1);
  v28 = *bpos + 4;
  *bpos = v28;
  Byte2Float(bytedata, v28);
  sub_19FFD30(&this->rot, 3, 2);
  v29 = *bpos + 4;
  *bpos = v29;
  Byte2Float(bytedata, v29);
  sub_19FFD30(&this->rot, 3, 3);
  v30 = *bpos + 4;
  *bpos = v30;
  this->abgr = Byte2UInt32(bytedata, v30);
  v31 = *bpos + 4LL;
  *bpos = v31;
  this->loop = bytedata->m_Items[v31];
  v33 = *bpos + 2;
  *bpos = v33;
  this->mode = Byte2UInt16(bytedata, v33);
  v34 = *bpos + 2;
  *bpos = v34;
  this->alpha_s = Byte2UInt32(bytedata, v34);
  v35 = *bpos + 4;
  *bpos = v35;
  this->alpha_e = Byte2UInt32(bytedata, v35);
  *bpos += 84;
  this->pSphereRing = 0;
  this->pRollRing = 0;
  this->pRing_Old = 0;
  this->pRing = 0;
}

// 0x19d75f0
void dds3SpPoly_RingPhysics_t__pCopy(dds3SpPoly_RingPhysics_t *this, u8 **bytedata, s32 *bpos) {
  s32 v7;
  s32 v8;

  v7 = *bpos;
  this->frame = Byte2UInt32(bytedata, v7);
  v8 = *bpos + 4;
  *bpos = v8;
  this->spread_s = Byte2Float(bytedata, v8);
  *bpos += 4;
}

// 0x19d7880
void dds3SpPoly_Ring_Old_t3__pClone(dds3SpPoly_Ring_Old_t3 *this, dds3SpPoly_Ring_Old_t3 **dst) {
  dds3SpPoly_Ring_Old_t3_o *v5;
  u64 *v6;

  v5 = *dst;
  v6 = Allocate(dds3SpPoly_Basic_t);
  _ctor(v6, 0);
  v5->basic = v6;
  dds3SpPoly_Basic_t__pClone(this->basic, &(*dst)->basic);
  (*dst)->loop = this->loop;
  (*dst)->type = this->type;
  (*dst)->interval = this->interval;
  (*dst)->split = this->split;
  (*dst)->width = this->width;
  (*dst)->speed = this->speed;
  (*dst)->color_in = this->color_in;
  (*dst)->color_out = this->color_out;
  (*dst)->basic->pRing_Old = *dst;
}

// 0x19d76c0
void dds3SpPoly_Ring_Old_t3__pCopy(dds3SpPoly_Ring_Old_t3 *this, u8 **bytedata, s32 *bpos) {
  u64 *v7;
  s64 v10;
  s64 v12;
  s32 v14;
  s32 v15;
  s32 v16;
  s32 v17;
  s32 v18;
  s32 v19;

  v7 = Allocate(dds3SpPoly_Basic_t);
  _ctor(v7, 0);
  this->basic = v7;
  dds3SpPoly_Basic_t__pCopy(v7, bytedata, bpos);
  v10 = *bpos;
  this->loop = bytedata->m_Items[v10];
  v12 = *bpos + 1LL;
  *bpos = v12;
  this->type = bytedata->m_Items[v12];
  v14 = *bpos + 3;
  *bpos = v14;
  this->interval = Byte2UInt32(bytedata, v14);
  v15 = *bpos + 4;
  *bpos = v15;
  this->split = Byte2UInt32(bytedata, v15);
  v16 = *bpos + 2;
  *bpos = v16;
  this->width = Byte2Float(bytedata, v16);
  v17 = *bpos + 4;
  *bpos = v17;
  this->speed = Byte2Float(bytedata, v17);
  v18 = *bpos + 4;
  *bpos = v18;
  this->color_in = Byte2UInt32(bytedata, v18);
  v19 = *bpos + 4;
  *bpos = v19;
  this->color_out = Byte2UInt32(bytedata, v19);
  *bpos += 12;
}

// 0x19d7b80
void dds3SpPoly_Ring_t3__pClone(dds3SpPoly_Ring_t3 *this, dds3SpPoly_Ring_t3 **dst) {
  dds3SpPoly_Ring_t3_o *v5;
  u64 *v6;

  v5 = *dst;
  v6 = Allocate(dds3SpPoly_Basic_t);
  _ctor(v6, 0);
  v5->basic = v6;
  dds3SpPoly_Basic_t__pClone(this->basic, &(*dst)->basic);
  (*dst)->timing = this->timing;
  (*dst)->vertex = this->vertex;
  (*dst)->width = this->width;
  (*dst)->radius_s = this->radius_s;
  (*dst)->radius_e = this->radius_e;
  (*dst)->radius_s_r = this->radius_s_r;
  (*dst)->radius_e_r = this->radius_e_r;
  (*dst)->up_s = this->up_s;
  (*dst)->up_a = this->up_a;
  (*dst)->color_edge_in = this->color_edge_in;
  (*dst)->color = this->color;
  (*dst)->color_edge_out = this->color_edge_out;
  (*dst)->basic->pRing = *dst;
}

// 0x19d7980
void dds3SpPoly_Ring_t3__pCopy(dds3SpPoly_Ring_t3 *this, u8 **bytedata, s32 *bpos) {
  u64 *v7;
  s32 v10;
  s32 v11;
  s32 v12;
  s32 v13;
  s32 v14;
  s32 v15;
  s32 v16;
  s32 v17;
  s32 v18;
  s32 v19;
  s32 v20;
  s32 v21;

  v7 = Allocate(dds3SpPoly_Basic_t);
  _ctor(v7, 0);
  this->basic = v7;
  dds3SpPoly_Basic_t__pCopy(v7, bytedata, bpos);
  v10 = *bpos;
  this->timing = Byte2UInt32(bytedata, v10);
  v11 = *bpos + 4;
  *bpos = v11;
  this->vertex = Byte2UInt32(bytedata, v11);
  v12 = *bpos + 4;
  *bpos = v12;
  this->width = Byte2Float(bytedata, v12);
  v13 = *bpos + 4;
  *bpos = v13;
  this->radius_s = Byte2Float(bytedata, v13);
  v14 = *bpos + 4;
  *bpos = v14;
  this->radius_e = Byte2Float(bytedata, v14);
  v15 = *bpos + 4;
  *bpos = v15;
  this->radius_s_r = Byte2Float(bytedata, v15);
  v16 = *bpos + 4;
  *bpos = v16;
  this->radius_e_r = Byte2Float(bytedata, v16);
  v17 = *bpos + 4;
  *bpos = v17;
  this->up_s = Byte2Float(bytedata, v17);
  v18 = *bpos + 4;
  *bpos = v18;
  this->up_a = Byte2Float(bytedata, v18);
  v19 = *bpos + 4;
  *bpos = v19;
  this->color_edge_in = Byte2UInt32(bytedata, v19);
  v20 = *bpos + 4;
  *bpos = v20;
  this->color = Byte2UInt32(bytedata, v20);
  v21 = *bpos + 4;
  *bpos = v21;
  this->color_edge_out = Byte2UInt32(bytedata, v21);
  *bpos += 16;
}

// 0x19d7cb0
void dds3SpPoly_RollRingPhysics_t__pCopy(dds3SpPoly_RollRingPhysics_t *this, u8 **bytedata, s32 *bpos) {
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;
  s32 v11;

  v7 = *bpos;
  this->frame = Byte2UInt32(bytedata, v7);
  v8 = *bpos + 4;
  *bpos = v8;
  this->radius = Byte2Float(bytedata, v8);
  v9 = *bpos + 4;
  *bpos = v9;
  this->spread_s = Byte2Float(bytedata, v9);
  v10 = *bpos + 4;
  *bpos = v10;
  this->rot_x = Byte2Float(bytedata, v10);
  v11 = *bpos + 4;
  *bpos = v11;
  this->rot_y = Byte2Float(bytedata, v11);
  *bpos += 4;
}

// 0x19d7ff0
void dds3SpPoly_RollRing_t3__pClone(dds3SpPoly_RollRing_t3 *this, dds3SpPoly_RollRing_t3 **dst) {
  dds3SpPoly_RollRing_t3_o *v5;
  u64 *v6;

  v5 = *dst;
  v6 = Allocate(dds3SpPoly_Basic_t);
  _ctor(v6, 0);
  v5->basic = v6;
  dds3SpPoly_Basic_t__pClone(this->basic, &(*dst)->basic);
  (*dst)->timing = this->timing;
  (*dst)->vertex = this->vertex;
  (*dst)->width = this->width;
  (*dst)->radius_s = this->radius_s;
  (*dst)->radius_e = this->radius_e;
  (*dst)->radius_s_r = this->radius_s_r;
  (*dst)->radius_e_r = this->radius_e_r;
  (*dst)->simu_num = this->simu_num;
  (*dst)->incline = this->incline;
  (*dst)->roll_s = this->roll_s;
  (*dst)->color_edge_in = this->color_edge_in;
  (*dst)->color = this->color;
  (*dst)->color_edge_out = this->color_edge_out;
  (*dst)->basic->pRollRing = *dst;
}

// 0x19d7dd0
void dds3SpPoly_RollRing_t3__pCopy(dds3SpPoly_RollRing_t3 *this, u8 **bytedata, s32 *bpos) {
  u64 *v7;
  s32 v10;
  s32 v11;
  s32 v12;
  s32 v13;
  s32 v14;
  s32 v15;
  s32 v16;
  s32 v17;
  s32 v18;
  s32 v19;
  s32 v20;
  s32 v21;
  s32 v22;

  v7 = Allocate(dds3SpPoly_Basic_t);
  _ctor(v7, 0);
  this->basic = v7;
  dds3SpPoly_Basic_t__pCopy(v7, bytedata, bpos);
  v10 = *bpos;
  this->timing = Byte2UInt32(bytedata, v10);
  v11 = *bpos + 4;
  *bpos = v11;
  this->vertex = Byte2UInt32(bytedata, v11);
  v12 = *bpos + 4;
  *bpos = v12;
  this->width = Byte2Float(bytedata, v12);
  v13 = *bpos + 4;
  *bpos = v13;
  this->radius_s = Byte2Float(bytedata, v13);
  v14 = *bpos + 4;
  *bpos = v14;
  this->radius_e = Byte2Float(bytedata, v14);
  v15 = *bpos + 4;
  *bpos = v15;
  this->radius_s_r = Byte2Float(bytedata, v15);
  v16 = *bpos + 4;
  *bpos = v16;
  this->radius_e_r = Byte2Float(bytedata, v16);
  v17 = *bpos + 4;
  *bpos = v17;
  this->simu_num = Byte2UInt32(bytedata, v17);
  v18 = *bpos + 4;
  *bpos = v18;
  this->incline = Byte2Float(bytedata, v18);
  v19 = *bpos + 4;
  *bpos = v19;
  this->roll_s = Byte2Float(bytedata, v19);
  v20 = *bpos + 4;
  *bpos = v20;
  this->color_edge_in = Byte2UInt32(bytedata, v20);
  v21 = *bpos + 4;
  *bpos = v21;
  this->color = Byte2UInt32(bytedata, v21);
  v22 = *bpos + 4;
  *bpos = v22;
  this->color_edge_out = Byte2UInt32(bytedata, v22);
  *bpos += 16;
}

// 0x19d82d0
void dds3SpPoly_SphereRing_t3__pClone(dds3SpPoly_SphereRing_t3 *this, dds3SpPoly_SphereRing_t3 **dst) {
  dds3SpPoly_SphereRing_t3_o *v5;
  u64 *v6;

  v5 = *dst;
  v6 = Allocate(dds3SpPoly_Basic_t);
  _ctor(v6, 0);
  v5->basic = v6;
  dds3SpPoly_Basic_t__pClone(this->basic, &(*dst)->basic);
  (*dst)->timing = this->timing;
  (*dst)->vertex = this->vertex;
  (*dst)->width = this->width;
  (*dst)->radius = this->radius;
  (*dst)->radius_r = this->radius_r;
  (*dst)->color_edge_in = this->color_edge_in;
  (*dst)->color = this->color;
  (*dst)->color_edge_out = this->color_edge_out;
  (*dst)->basic->pSphereRing = *dst;
}

// 0x19d8140
void dds3SpPoly_SphereRing_t3__pCopy(dds3SpPoly_SphereRing_t3 *this, u8 **bytedata, s32 *bpos) {
  u64 *v7;
  s32 v10;
  s32 v11;
  s32 v12;
  s32 v13;
  s32 v14;
  s32 v15;
  s32 v16;
  s32 v17;

  v7 = Allocate(dds3SpPoly_Basic_t);
  _ctor(v7, 0);
  this->basic = v7;
  dds3SpPoly_Basic_t__pCopy(v7, bytedata, bpos);
  v10 = *bpos;
  this->timing = Byte2UInt32(bytedata, v10);
  v11 = *bpos + 4;
  *bpos = v11;
  this->vertex = Byte2UInt32(bytedata, v11);
  v12 = *bpos + 4;
  *bpos = v12;
  this->width = Byte2Float(bytedata, v12);
  v13 = *bpos + 4;
  *bpos = v13;
  this->radius = Byte2Float(bytedata, v13);
  v14 = *bpos + 4;
  *bpos = v14;
  this->radius_r = Byte2Float(bytedata, v14);
  v15 = *bpos + 4;
  *bpos = v15;
  this->color_edge_in = Byte2UInt32(bytedata, v15);
  v16 = *bpos + 4;
  *bpos = v16;
  this->color = Byte2UInt32(bytedata, v16);
  v17 = *bpos + 4;
  *bpos = v17;
  this->color_edge_out = Byte2UInt32(bytedata, v17);
  *bpos += 16;
}

// 0x19d83d0
void dds3TrackPolyList_t__dCopy(dds3TrackPolyList_t *this, dds3TrackPolyList_t **dst) {
  dds3TrackPolyList_t_o *v5;
  struct UnityEngine_Vector4_array *pVertex;
  u32 *max_length;
  dds3TrackPolyList_t_o *v8;
  s64 v9;
  u64 v10;
  struct UnityEngine_Vector4_array *v11;
  f32 x;
  f32 y;
  f32 w;
  f32 z;
  s32 v18;
  s32 v19;
  s32 v20;
  struct System_UInt32_array *pVC;
  il2cpp_array_size_t v23;
  dds3TrackPolyList_t_o *v24;
  s64 v25;
  struct System_UInt32_array *v26;
  s32 v28;
  s64 v30;
  s64 v31;
  s64 v32;

  v5 = *dst;
  v5->pVertex = NewSpecific(UnityEngine_Vector4, LODWORD(this->pVertex->max_length));
  pVertex = this->pVertex;
  max_length = pVertex->max_length;
  v8 = *dst;
  if (max_length >= 1)
  {
    v9 = 0;
    v10 = 0;
    do
    {
      v11 = v8->pVertex;
      x = pVertex->m_Items[v9].x;
      y = pVertex->m_Items[v9].y;
      w = pVertex->m_Items[v9].w;
      z = pVertex->m_Items[v9].z;
      v31 = 0;
      v32 = 0;
      sub_854690(&v31, x, y, z, w);
      v18 = HIDWORD(v31);
      v20 = v32;
      v19 = HIDWORD(v32);
      max_length = (v11 + v9 * 16);
      ++v9;
      max_length[8] = v31;
      max_length[9] = v18;
      max_length[10] = v20;
      max_length[11] = v19;
      pVertex = this->pVertex;
      LODWORD(max_length) = pVertex->max_length;
      v8 = *dst;
      ++v10;
    }
    while (v10 < max_length);
  }
  v8->pVC = NewSpecific(uint, LODWORD(this->pVC->max_length));
  pVC = this->pVC;
  v23 = pVC->max_length;
  v24 = *dst;
  if (v23 >= 1)
  {
    v25 = 8;
    do
    {
      v26 = v24->pVC;
      v28 = *(&pVC->obj.klass + v25);
      *(&v26->obj.klass + v25) = v28;
      pVC = this->pVC;
      LODWORD(v23) = pVC->max_length;
      v24 = *dst;
      v30 = v25 - 7;
      ++v25;
    }
    while (v30 < v23);
  }
  v24->count = this->count;
  (*dst)->rec = this->rec;
  (*dst)->color = this->color;
}

// 0x19d68f0
void dds3TrackPoly_t__dCopy(dds3TrackPoly_t *this, dds3TrackPoly_t **dst) {
  dds3TrackPoly_t_o *v5;
  dds3TrackPoly_t_o *v6;
  u64 v7;
  u32 *trackList;
  u64 *v10;
  struct dds3TrackPolyList_t_array *v13;
  dds3TrackPolyList_t_o *v15;
  struct dds3TrackPolyList_t_array *v16;
  struct UnityEngine_Vector4_array *pVertex;
  u32 *max_length;
  dds3TrackPoly_t_o *v20;
  s64 v21;
  u64 v22;
  struct UnityEngine_Vector4_array *v23;
  f32 x;
  f32 y;
  f32 w;
  f32 z;
  s32 v30;
  s32 v31;
  s32 v32;
  struct System_UInt32_array *pVC;
  il2cpp_array_size_t v35;
  dds3TrackPoly_t_o *v36;
  s64 v37;
  struct System_UInt32_array *v38;
  s32 v40;
  s64 v42;
  s64 v43;
  s64 v44;

  (*dst)->type = this->type;
  (*dst)->mode = this->mode;
  (*dst)->number = this->number;
  (*dst)->point = this->point;
  (*dst)->rec = this->rec;
  (*dst)->hMem = this->hMem;
  v5 = *dst;
  v5->trackList = NewSpecific(
                           dds3TrackPolyList_t,
                           LODWORD(this->trackList->max_length));
  v6 = *dst;
  if (SLODWORD(this->trackList->max_length) >= 1)
  {
    v7 = 0;
    do
    {
      trackList = v6->trackList;
      v10 = Allocate(dds3TrackPolyList_t);
      _ctor(v10, 0);
      *&trackList[2 * v7 + 8] = v10;
      v13 = this->trackList;
      v15 = v13->m_Items[v7];
      v16 = (*dst)->trackList;
      dds3TrackPolyList_t__dCopy(v15, &v16->m_Items[v7]);
      v6 = *dst;
      ++v7;
    }
    while (v7 < SLODWORD(this->trackList->max_length));
  }
  v6->pVertex = NewSpecific(UnityEngine_Vector4, LODWORD(this->pVertex->max_length));
  pVertex = this->pVertex;
  max_length = pVertex->max_length;
  v20 = *dst;
  if (max_length >= 1)
  {
    v21 = 0;
    v22 = 0;
    do
    {
      v23 = v20->pVertex;
      x = pVertex->m_Items[v21].x;
      y = pVertex->m_Items[v21].y;
      w = pVertex->m_Items[v21].w;
      z = pVertex->m_Items[v21].z;
      v43 = 0;
      v44 = 0;
      sub_854690(&v43, x, y, z, w);
      v30 = HIDWORD(v43);
      v32 = v44;
      v31 = HIDWORD(v44);
      max_length = (v23 + v21 * 16);
      ++v21;
      max_length[8] = v43;
      max_length[9] = v30;
      max_length[10] = v32;
      max_length[11] = v31;
      pVertex = this->pVertex;
      LODWORD(max_length) = pVertex->max_length;
      v20 = *dst;
      ++v22;
    }
    while (v22 < max_length);
  }
  v20->pVC = NewSpecific(uint, LODWORD(this->pVC->max_length));
  pVC = this->pVC;
  v35 = pVC->max_length;
  v36 = *dst;
  if (v35 >= 1)
  {
    v37 = 8;
    do
    {
      v38 = v36->pVC;
      v40 = *(&pVC->obj.klass + v37);
      *(&v38->obj.klass + v37) = v40;
      pVC = this->pVC;
      LODWORD(v35) = pVC->max_length;
      v36 = *dst;
      v42 = v37 - 7;
      ++v37;
    }
    while (v42 < v35);
  }
  v36->pMat = this->pMat;
  (*dst)->next = this->next;
  (*dst)->d_next = this->d_next;
  (*dst)->alf_raito = this->alf_raito;
}

// 0x19d8670
void dds3TrackPoly_t__pCopy(dds3TrackPoly_t *this, u8 **bytedata, s32 *bpos) {
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;
  s32 v11;

  v7 = *bpos;
  this->type = Byte2UInt32(bytedata, v7);
  v8 = *bpos + 2;
  *bpos = v8;
  this->mode = Byte2UInt32(bytedata, v8);
  v9 = *bpos + 2;
  *bpos = v9;
  this->number = Byte2UInt32(bytedata, v9);
  v10 = *bpos + 4;
  *bpos = v10;
  this->point = Byte2UInt32(bytedata, v10);
  v11 = *bpos + 4;
  *bpos = v11;
  this->rec = Byte2UInt32(bytedata, v11);
  *bpos += 32;
}

// 0x19d87a0
void effBTLCutHandle_t__Clear(effBTLCutHandle_t *this) {
  u64 *v3;
  u64 *v4;
  u64 *v5;
  struct effPartHandle_t_array *v6;
  u32 *hPart;
  u64 i;
  u64 *v9;
  u64 *v12;

  v3 = Allocate(nbFormation_t);
  nbFormation_t___ctor(v3);
  this->pFormation = v3;
  v4 = Allocate(effBTL_t);
  _ctor(v4, 0);
  this->frameF = 0.0;
  this->stat = 0;
  *(&this->cut_frame + 2) = 0;
  this->hBTLEffect = v4;
  *&this->frame = 0;
  v5 = Allocate(effBTL_SkillCutTable_t);
  _ctor(v5, 0);
  this->pSkillCut = v5;
  v6 = NewSpecific(effPartHandle_t, 0x3Cu);
  this->hPart = v6;
  hPart = v6;
  for (i = 0; ; ++i)
  {
    v9 = Allocate(effPartHandle_t);
    effPartHandle_t___ctor(v9);
    *&hPart[2 * i + 8] = v9;
    if (i == 59)
      break;
    hPart = this->hPart;
  }
  this->pUserData = 0;
  v12 = Allocate(effBTLCutHandle_t);
  _ctor(v12, 0);
  this->hCutListNext = v12;
}

// 0x19d9860
s32 effBTL_SkillCameraShake_t__CopyByte(effBTL_SkillCameraShake_t *this, u8 **bytedata, s32 pos) {
  this->number = Byte2UInt16(bytedata, pos);
  this->timing = Byte2UInt16(bytedata, pos + 2);
  this->life = Byte2UInt16(bytedata, pos + 4);
  return pos + 6;
}

// 0x19d9920
s32 effBTL_SkillCamera_t__CopyByte(effBTL_SkillCamera_t *this, u8 **bytedata, s32 pos) {
  u64 *v7;

  this->restriction = Byte2UInt16(bytedata, pos);
  v7 = Allocate(effBTL_SkillCameraShake_t);
  _ctor(v7, 0);
  this->shake = v7;
  *(v7 + 8) = Byte2UInt16(bytedata, pos + 2);
  *(v7 + 9) = Byte2UInt16(bytedata, pos + 4);
  *(v7 + 10) = Byte2UInt16(bytedata, pos + 6);
  return pos + 8;
}

// 0x19d9ac0
void effBTL_SkillColorAnim_t__Copy(effBTL_SkillColorAnim_t *this, effBTL_SkillColorAnim_t *data) {
  this->fields = data->fields;
}

// 0x19d9af0
s32 effBTL_SkillColorAnim_t__CopyByte(effBTL_SkillColorAnim_t *this, u8 **bytedata, s32 pos) {
  this->fade_in_frame = Byte2UInt32(bytedata, pos);
  this->fade_in_pattern = Byte2UInt32(bytedata, pos + 4);
  this->fade_out_frame = Byte2UInt32(bytedata, pos + 8);
  this->fade_out_pattern = Byte2UInt32(bytedata, pos + 12);
  this->anim_pattern = Byte2UInt32(bytedata, pos + 16);
  return pos + 20;
}

// 0x19d9be0
void effBTL_SkillData_t__CopyByte(effBTL_SkillData_t *this, u8 **bytedata) {
  u64 *v5;
  u64 *v6;
  System_Text_Encoding_o *ASCII;
  struct effBTL_SkillCutTable_t_array *v11;
  u32 *v12;
  u64 v13;
  s32 v14;
  u64 *v15;
  struct effBTL_SkillCutTable_t_array *cut;
  effBTL_SkillCutTable_t_o *v20;
  struct effBTL_SkillCutTable_t_array *v21;
  effBTL_SkillCutTable_t_o *v23;
  s32 v24;
  Il2CppObject *v25;
  u64 *v26;
  struct effBTL_SkillCutTable_t_array *v28;
  s32 v30;
  struct effBTL_SkillCutTable_t_array *v31;
  s32 v32;
  effBTL_SkillCutTable_t_o *v34;
  u64 *v35;
  struct effBTL_SkillCutTable_t_array *v37;
  s32 v39;
  struct effBTL_SkillCutTable_t_array *v40;
  s32 v41;
  effBTL_SkillCutTable_t_o *v43;
  u64 *v44;
  struct effBTL_SkillCutTable_t_array *v46;
  s32 v48;
  struct effBTL_SkillCutTable_t_array *v49;
  s32 v50;
  effBTL_SkillCutTable_t_o *v52;
  u64 *v53;
  struct effBTL_SkillCutTable_t_array *v55;
  s32 v57;
  struct effBTL_SkillCutTable_t_array *v58;
  s32 v59;
  effBTL_SkillCutTable_t_o *v61;
  u64 *v62;
  struct effBTL_SkillCutTable_t_array *v64;
  struct effBTL_SkillSE_t_o *se;
  struct effBTL_SkillCutTable_t_array *v67;
  s32 v68;
  effBTL_SkillCutTable_t_o *v70;
  u64 *v71;
  struct effBTL_SkillCutTable_t_array *v73;
  s32 v75;

  v5 = NewSpecific(byte, 6u);
  v6 = v5;
  *(v5 + 32) = bytedata->m_Items[0];
  *(v5 + 33) = bytedata->m_Items[1];
  *(v5 + 34) = bytedata->m_Items[2];
  *(v5 + 35) = bytedata->m_Items[3];
  *(v5 + 36) = bytedata->m_Items[4];
  *(v5 + 37) = bytedata->m_Items[5];
  ASCII = get_ASCII();
  this->version = (ASCII->klass[1]._1.byval_arg.data)(ASCII, v6, *&ASCII->klass[1]._1.byval_arg.bits);
  v11 = NewSpecific(effBTL_SkillCutTable_t, 2u);
  this->cut = v11;
  v12 = v11;
  v13 = 0;
  v14 = 8;
  while (1)
  {
    v15 = Allocate(effBTL_SkillCutTable_t);
    _ctor(v15, 0);
    *&v12[2 * v13 + 8] = v15;
    cut = this->cut;
    v20 = cut->m_Items[v13];
    v20->frame = Byte2UInt32(bytedata, v14);
    v21 = this->cut;
    v23 = v21->m_Items[v13];
    v24 = v14 + 4;
    v25 = Allocate(effBTL_SkillCamera_t);
    v26 = Allocate(effBTL_SkillCameraShake_t);
    _ctor(v26, 0);
    v25[1].monitor = v26;
    _ctor(v25, 0);
    v23->camera = v25;
    v28 = this->cut;
    v30 = effBTL_SkillCamera_t__CopyByte(v28->m_Items[v13]->camera, bytedata, v24);
    v31 = this->cut;
    v32 = v30;
    v34 = v31->m_Items[v13];
    v35 = Allocate(effBTL_SkillLight_t);
    _ctor(v35, 0);
    v34->light = v35;
    v37 = this->cut;
    v39 = effBTL_SkillLight_t__CopyByte(v37->m_Items[v13]->light, bytedata, v32);
    v40 = this->cut;
    v41 = v39;
    v43 = v40->m_Items[v13];
    v44 = Allocate(effBTL_SkillModel_t);
    _ctor(v44, 0);
    v43->model = v44;
    v46 = this->cut;
    v48 = effBTL_SkillModel_t__CopyByte(v46->m_Items[v13]->model, bytedata, v41);
    v49 = this->cut;
    v50 = v48;
    v52 = v49->m_Items[v13];
    v53 = Allocate(effBTL_SkillField_t);
    _ctor(v53, 0);
    v52->field = v53;
    v55 = this->cut;
    v57 = effBTL_SkillField_t__CopyByte(v55->m_Items[v13]->field, bytedata, v50);
    v58 = this->cut;
    v59 = v57;
    v61 = v58->m_Items[v13];
    v62 = Allocate(effBTL_SkillSE_t);
    _ctor(v62, 0);
    v61->se = v62;
    v64 = this->cut;
    se = v64->m_Items[v13]->se;
    se->reserve = Byte2UInt16(bytedata, v59);
    se->dmy = Byte2UInt16(bytedata, v59 + 2);
    se->timing = Byte2UInt32(bytedata, v59 + 4);
    v67 = this->cut;
    v68 = v59 + 8;
    v70 = v67->m_Items[v13];
    v71 = Allocate(effBTL_SkillParts_t);
    _ctor(v71, 0);
    v70->parts = v71;
    v73 = this->cut;
    v75 = effBTL_SkillParts_t__CopyByte(v73->m_Items[v13]->parts, bytedata, v68);
    if (v13)
      break;
    v12 = this->cut;
    v14 = v75;
    v13 = 1;
  }
}

// 0x19da590
s32 effBTL_SkillField_t__CopyByte(effBTL_SkillField_t *this, u8 **bytedata, s32 pos) {
  u64 *v7;

  this->color = Byte2UInt32(bytedata, pos);
  v7 = Allocate(effBTL_SkillColorAnim_t);
  _ctor(v7, 0);
  this->color_anim = v7;
  return effBTL_SkillColorAnim_t__CopyByte(v7, bytedata, pos + 4);
}

// 0x19da990
void effBTL_SkillLight_t__Clear(effBTL_SkillLight_t *this) {
  u64 *v3;
  u64 *v4;

  v3 = Allocate(effBTL_SkillPositionPtr_t);
  _ctor(v3, 0);
  this->pos_ptr = v3;
  *&this->diffuse = 0;
  v4 = Allocate(effBTL_SkillColorAnim_t);
  _ctor(v4, 0);
  this->color_anim = v4;
}

// 0x19daa20
void effBTL_SkillLight_t__Copy(effBTL_SkillLight_t *this, effBTL_SkillLight_t *data) {
  u64 *v5;
  struct effBTL_SkillPositionPtr_t_o *pos_ptr;
  u64 *v7;
  struct effBTL_SkillColorAnim_t_o *color_anim;

  v5 = Allocate(effBTL_SkillPositionPtr_t);
  _ctor(v5, 0);
  this->pos_ptr = v5;
  pos_ptr = data->pos_ptr;
  *(v5 + 16) = pos_ptr->target;
  *(v5 + 17) = pos_ptr->height;
  *(v5 + 18) = pos_ptr->direction;
  *(v5 + 5) = pos_ptr->radius;
  this->diffuse = data->diffuse;
  this->ambient = data->ambient;
  v7 = Allocate(effBTL_SkillColorAnim_t);
  _ctor(v7, 0);
  this->color_anim = v7;
  color_anim = data->color_anim;
  *(v7 + 4) = color_anim->fade_in_frame;
  *(v7 + 5) = color_anim->fade_in_pattern;
  *(v7 + 6) = color_anim->fade_out_frame;
  *(v7 + 7) = color_anim->fade_out_pattern;
  *(v7 + 8) = color_anim->anim_pattern;
}

// 0x19da390
s32 effBTL_SkillLight_t__CopyByte(effBTL_SkillLight_t *this, u8 **bytedata, s32 pos) {
  u64 *v7;
  s32 v10;
  u64 *v11;

  v7 = Allocate(effBTL_SkillPositionPtr_t);
  _ctor(v7, 0);
  this->pos_ptr = v7;
  v10 = effBTL_SkillPositionPtr_t__CopyByte(v7, bytedata, pos);
  this->diffuse = Byte2UInt32(bytedata, v10);
  this->ambient = Byte2UInt32(bytedata, v10 + 4);
  v11 = Allocate(effBTL_SkillColorAnim_t);
  _ctor(v11, 0);
  this->color_anim = v11;
  return effBTL_SkillColorAnim_t__CopyByte(v11, bytedata, v10 + 8);
}

// 0x19dac90
void effBTL_SkillModel_t__Clear(effBTL_SkillModel_t *this) {
  u64 *v3;

  this->color = 0;
  v3 = Allocate(effBTL_SkillColorAnim_t);
  _ctor(v3, 0);
  this->color_anim = v3;
  this->motion_timing = 0;
}

// 0x19dad00
void effBTL_SkillModel_t__Copy(effBTL_SkillModel_t *this, effBTL_SkillModel_t *data) {
  u64 *v5;
  struct effBTL_SkillColorAnim_t_o *color_anim;

  this->color = data->color;
  v5 = Allocate(effBTL_SkillColorAnim_t);
  _ctor(v5, 0);
  this->color_anim = v5;
  color_anim = data->color_anim;
  *(v5 + 4) = color_anim->fade_in_frame;
  *(v5 + 5) = color_anim->fade_in_pattern;
  *(v5 + 6) = color_anim->fade_out_frame;
  *(v5 + 7) = color_anim->fade_out_pattern;
  *(v5 + 8) = color_anim->anim_pattern;
  this->motion_timing = data->motion_timing;
}

// 0x19da4a0
s32 effBTL_SkillModel_t__CopyByte(effBTL_SkillModel_t *this, u8 **bytedata, s32 pos) {
  u64 *v7;
  s32 v9;

  this->color = Byte2UInt32(bytedata, pos);
  v7 = Allocate(effBTL_SkillColorAnim_t);
  _ctor(v7, 0);
  this->color_anim = v7;
  v9 = effBTL_SkillColorAnim_t__CopyByte(v7, bytedata, pos + 4);
  this->motion_timing = Byte2UInt32(bytedata, v9);
  return v9 + 4;
}

// 0x19dadb0
void effBTL_SkillPBFileHeader_t__Clear(effBTL_SkillPBFileHeader_t *this) {
  this->size = 0;
  this->reserve = NewSpecific(uint, 3u);
}

// 0x19dae10
void effBTL_SkillPBFileHeader_t__Copy(effBTL_SkillPBFileHeader_t *this, effBTL_SkillPBFileHeader_t *para) {
  struct System_UInt32_array *v5;
  struct System_UInt32_array *reserve;
  u32 v7;
  struct System_UInt32_array *v8;
  struct System_UInt32_array *v9;
  u32 v11;
  struct System_UInt32_array *v13;
  struct System_UInt32_array *v14;
  u32 v16;

  this->size = para->size;
  v5 = NewSpecific(uint, 3u);
  this->reserve = v5;
  reserve = para->reserve;
  v7 = reserve->m_Items[0];
  v5->m_Items[0] = v7;
  v8 = para->reserve;
  v9 = this->reserve;
  v11 = v8->m_Items[1];
  v9->m_Items[1] = v11;
  v13 = para->reserve;
  v14 = this->reserve;
  v16 = v13->m_Items[2];
  v14->m_Items[2] = v16;
}

// 0x19daf70
s32 effBTL_SkillPartsList_t__CopyByte(effBTL_SkillPartsList_t *this, u8 **bytedata, s32 pos) {
  u64 *v7;
  s32 v9;
  s64 v10;

  this->type = Byte2UInt16(bytedata, pos);
  this->pHandle = 0;
  this->offset = Byte2UInt32(bytedata, pos + 4);
  v7 = Allocate(effBTL_SkillPositionPtr_t);
  _ctor(v7, 0);
  this->pos_ptr = v7;
  v9 = effBTL_SkillPositionPtr_t__CopyByte(v7, bytedata, pos + 8);
  this->timing = Byte2UInt32(bytedata, v9);
  v10 = v9 + 4LL;
  this->reverberations = bytedata->m_Items[v10];
  return v9 + 8;
}

// 0x19da720
s32 effBTL_SkillParts_t__CopyByte(effBTL_SkillParts_t *this, u8 **bytedata, s32 pos) {
  s64 v7;
  s64 v11;
  s32 v13;
  struct effBTL_SkillPartsList_t_array *v14;
  u32 *v15;
  s64 i;
  u64 v17;
  u64 *v18;
  struct effBTL_SkillPartsList_t_array *list;

  this->number = Byte2UInt16(bytedata, pos);
  this->dmy0 = Byte2UInt16(bytedata, pos + 2);
  this->life = Byte2UInt32(bytedata, pos + 4);
  v7 = pos + 8LL;
  this->scaling = bytedata->m_Items[v7];
  this->dmy1 = bytedata->m_Items[pos + 9];
  this->dmy2 = bytedata->m_Items[pos + 10];
  v11 = pos + 11LL;
  this->dmy3 = bytedata->m_Items[v11];
  v13 = pos + 12;
  v14 = NewSpecific(effBTL_SkillPartsList_t, 0x3Cu);
  this->list = v14;
  v15 = v14;
  for (i = 4; ; ++i)
  {
    v17 = i - 4;
    v18 = Allocate(effBTL_SkillPartsList_t);
    _ctor(v18, 0);
    *&v15[2 * i] = v18;
    list = this->list;
    v13 = effBTL_SkillPartsList_t__CopyByte(*(&list->obj.klass + i), bytedata, v13);
    if (i == 63)
      break;
    v15 = this->list;
  }
  return v13;
}

// 0x19dab10
void effBTL_SkillPositionPtr_t__Copy(effBTL_SkillPositionPtr_t *this, effBTL_SkillPositionPtr_t *data) {
  this->target = data->target;
  this->height = data->height;
  this->direction = data->direction;
  this->radius = data->radius;
}

// 0x19dab40
s32 effBTL_SkillPositionPtr_t__CopyByte(effBTL_SkillPositionPtr_t *this, u8 **bytedata, s32 pos) {
  s64 v10;

  this->target = bytedata->m_Items[pos];
  this->height = bytedata->m_Items[pos + 1];
  this->direction = bytedata->m_Items[pos + 2];
  v10 = pos + 3LL;
  this->dmy = bytedata->m_Items[v10];
  this->radius = Byte2UInt32(bytedata, pos + 4);
  return pos + 8;
}

// 0x19da660
s32 effBTL_SkillSE_t__CopyByte(effBTL_SkillSE_t *this, u8 **bytedata, s32 pos) {
  this->reserve = Byte2UInt16(bytedata, pos);
  this->dmy = Byte2UInt16(bytedata, pos + 2);
  this->timing = Byte2UInt32(bytedata, pos + 4);
  return pos + 8;
}

// 0x19db0a0
void effBTL_t__Clear(effBTL_t *this) {
  u64 *v3;
  u64 *v4;

  v3 = Allocate(effBTL_SkillData_t);
  _ctor(v3, 0);
  this->Skill = v3;
  this->hMem = 0;
  this->CutCount = 0;
  v4 = Allocate(effBTLCutHandle_t);
  _ctor(v4, 0);
  this->hCutListTop = v4;
}

// 0x19db130
void effBezier4PPart_t__Clear(effBezier4PPart_t *this) {
  u64 *v3;
  s32 v4;
  s32 v5;
  s32 v7;
  s32 v8;
  s32 v10;
  s32 v11;
  s32 v13;
  s32 v14;
  s64 v16;
  s32 v17;
  s64 v18;
  s32 v19;
  s64 v20;
  s32 v21;
  s64 v22;
  s32 v23;

  v3 = NewSpecific(UnityEngine_Vector3, 4u);
  v23 = 0;
  v22 = 0;
  sub_8524C0(&v22, 0.0, 0.0, 0.0);
  v4 = HIDWORD(v22);
  v5 = v23;
  *(v3 + 8) = v22;
  *(v3 + 9) = v4;
  *(v3 + 10) = v5;
  v21 = 0;
  v20 = 0;
  sub_8524C0(&v20, 0.0, 0.0, 0.0);
  v7 = HIDWORD(v20);
  v8 = v21;
  *(v3 + 11) = v20;
  *(v3 + 12) = v7;
  *(v3 + 13) = v8;
  v19 = 0;
  v18 = 0;
  sub_8524C0(&v18, 0.0, 0.0, 0.0);
  v10 = HIDWORD(v18);
  v11 = v19;
  *(v3 + 14) = v18;
  *(v3 + 15) = v10;
  *(v3 + 16) = v11;
  v17 = 0;
  v16 = 0;
  sub_8524C0(&v16, 0.0, 0.0, 0.0);
  v13 = HIDWORD(v16);
  v14 = v17;
  *(v3 + 17) = v16;
  *(v3 + 18) = v13;
  *(v3 + 19) = v14;
  this->point = v3;
  *&this->weight = 0;
}

// 0x19db2f0
void effBezier7PPart_t__Clear(effBezier7PPart_t *this) {
  struct UnityEngine_Vector3_array *v3;
  struct UnityEngine_Vector3_array *point;
  struct UnityEngine_Vector3_array *v7;
  struct UnityEngine_Vector3_array *v9;
  struct UnityEngine_Vector3_array *v11;
  struct UnityEngine_Vector3_array *v13;
  struct UnityEngine_Vector3_array *v15;

  v3 = NewSpecific(UnityEngine_Vector3, 7u);
  this->point = v3;
  v3->m_Items[0].z = 0.0;
  *&v3->m_Items[0].x = 0;
  point = this->point;
  point->m_Items[1].z = 0.0;
  *&point->m_Items[1].x = 0;
  v7 = this->point;
  v7->m_Items[2].z = 0.0;
  *&v7->m_Items[2].x = 0;
  v9 = this->point;
  v9->m_Items[3].z = 0.0;
  *&v9->m_Items[3].x = 0;
  v11 = this->point;
  v11->m_Items[4].z = 0.0;
  *&v11->m_Items[4].x = 0;
  v13 = this->point;
  v13->m_Items[5].z = 0.0;
  *&v13->m_Items[5].x = 0;
  v15 = this->point;
  v15->m_Items[6].z = 0.0;
  *&v15->m_Items[6].x = 0;
  this->segment = 0;
  *&this->weight = 0;
}

// 0x19db6c0
void effEveBEDParams_t__Clear(effEveBEDParams_t *this) {
  *&this->r = 0;
  *&this->scale = 0;
  *&this->rot.x = 0;
  *&this->rot.z = 0;
  *&this->center.x = 0;
  *&this->center.z = 0;
}

// 0x19db6d0
void effEveBEDParams_t__Copy(effEveBEDParams_t *this, effEveBEDParams_t *para) {
  f32 z;
  f32 w;
  f32 v5;
  f32 v6;

  z = para->center.z;
  w = para->center.w;
  *&this->center.x = *&para->center.x;
  this->center.z = z;
  this->center.w = w;
  v5 = para->rot.z;
  v6 = para->rot.w;
  *&this->rot.x = *&para->rot.x;
  this->rot.z = v5;
  this->rot.w = v6;
  this->r = para->r;
  this->h = para->h;
  this->scale = para->scale;
  this->abgr = para->abgr;
}

// 0x19db860
void effMagaCylinderParam_t__bCopy(effMagaCylinderParam_t *this, u8 **bytedata, s32 *bPos) {
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;
  s64 v11;
  s32 v13;
  s32 v14;
  s32 v15;
  s32 v16;
  s32 v17;
  s32 v18;
  s32 v19;
  s32 v20;
  s32 v21;
  s32 v22;
  s32 v23;
  u64 *v24;
  struct System_UInt32_array *v26;
  s32 v28;
  struct System_UInt32_array *reserve;
  u64 v30;
  u32 v32;

  *&this->pos.x = 0;
  *&this->pos.z = 0;
  v7 = *bPos;
  this->pos.x = Byte2Float(bytedata, v7);
  v8 = *bPos + 4;
  *bPos = v8;
  this->pos.y = Byte2Float(bytedata, v8);
  v9 = *bPos + 4;
  *bPos = v9;
  this->pos.z = Byte2Float(bytedata, v9);
  v10 = *bPos + 4;
  *bPos = v10;
  this->pos.w = Byte2Float(bytedata, v10);
  v11 = *bPos + 4LL;
  *bPos = v11;
  this->loop = bytedata->m_Items[v11];
  v13 = *bPos + 4;
  *bPos = v13;
  this->life = Byte2UInt32(bytedata, v13);
  v14 = *bPos + 4;
  *bPos = v14;
  this->timing = Byte2UInt32(bytedata, v14);
  v15 = *bPos + 4;
  *bPos = v15;
  this->fade_in = Byte2UInt32(bytedata, v15);
  v16 = *bPos + 4;
  *bPos = v16;
  this->fade_out = Byte2UInt32(bytedata, v16);
  v17 = *bPos + 4;
  *bPos = v17;
  this->rotate_s = Byte2Float(bytedata, v17);
  v18 = *bPos + 4;
  *bPos = v18;
  this->rotate_r = Byte2Float(bytedata, v18);
  v19 = *bPos + 4;
  *bPos = v19;
  this->height = Byte2Float(bytedata, v19);
  v20 = *bPos + 4;
  *bPos = v20;
  this->radius_s = Byte2Float(bytedata, v20);
  v21 = *bPos + 4;
  *bPos = v21;
  this->radius_e = Byte2Float(bytedata, v21);
  v22 = *bPos + 4;
  *bPos = v22;
  this->radius_s_r = Byte2Float(bytedata, v22);
  v23 = *bPos + 4;
  *bPos = v23;
  this->radius_e_r = Byte2Float(bytedata, v23);
  *bPos += 4;
  v24 = Allocate(effMagatuhiParams_t);
  _ctor(v24, 0);
  this->MagaParam = v24;
  effMagatuhiParams_t__bCopy(v24, bytedata, bPos);
  v26 = NewSpecific(uint, 0x20u);
  this->reserve = v26;
  v28 = *bPos;
  reserve = v26;
  v30 = 0;
  {
LABEL_11:
    goto LABEL_13;
  }
  while (1)
  {
LABEL_13:
    v32 = Byte2UInt32(bytedata, v28);
    reserve->m_Items[v30] = v32;
    v28 = *bPos + 4;
    *bPos = v28;
    if (v30 == 31)
      break;
    reserve = this->reserve;
    ++v30;
      goto LABEL_11;
  }
}

// 0x19dbcf0
void effMagaCylinderParam_t__pClone(effMagaCylinderParam_t *this, effMagaCylinderParam_t **dst) {
  effMagaCylinderParam_t_o *v5;
  effMagaCylinderParam_t_o *v6;
  u64 *v7;
  u32 *MagaParam;
  effMagaCylinderParam_t_o *v9;
  effMagaCylinderParam_t_o *v10;
  s64 i;
  struct System_UInt32_array *reserve;
  struct System_UInt32_array *v13;
  s32 v14;

  v5 = *dst;
  *&v5->pos.x = 0;
  *&v5->pos.z = 0;
  (*dst)->pos.x = this->pos.x;
  (*dst)->pos.y = this->pos.y;
  (*dst)->pos.z = this->pos.z;
  (*dst)->pos.w = this->pos.w;
  (*dst)->loop = this->loop;
  (*dst)->life = this->life;
  (*dst)->timing = this->timing;
  (*dst)->fade_in = this->fade_in;
  (*dst)->fade_out = this->fade_out;
  (*dst)->rotate_s = this->rotate_s;
  (*dst)->rotate_r = this->rotate_r;
  (*dst)->height = this->height;
  (*dst)->radius_s = this->radius_s;
  (*dst)->radius_e = this->radius_e;
  (*dst)->radius_s_r = this->radius_s_r;
  (*dst)->radius_e_r = this->radius_e_r;
  v6 = *dst;
  v7 = Allocate(effMagatuhiParams_t);
  _ctor(v7, 0);
  v6->MagaParam = v7;
  MagaParam = this->MagaParam;
  v9 = *dst;
  (*dst)->MagaParam->number = MagaParam[4];
  v9->MagaParam->tail = MagaParam[5];
  LODWORD(v9->MagaParam->scale) = MagaParam[6];
  v9->MagaParam->abgr_s = MagaParam[7];
  v9->MagaParam->abgr_e = MagaParam[8];
  v9->MagaParam->blend = MagaParam[9];
  LODWORD(v9->MagaParam->t) = MagaParam[10];
  v10 = *dst;
  v10->reserve = NewSpecific(uint, 0x20u);
  for (i = 8; i != 40; ++i)
  {
    reserve = this->reserve;
    v13 = (*dst)->reserve;
    v14 = *(&reserve->obj.klass + i);
    *(&v13->obj.klass + i) = v14;
  }
}

// 0x19dbfa0
void effMagaP4Point_t__Copy(effMagaP4Point_t *this, effMagaP4Point_t *para) {
  struct UnityEngine_Vector4_array *point;
  struct UnityEngine_Vector4_array *v6;
  f32 x;
  f32 y;
  f32 w;
  f32 z;
  struct System_Single_array *radius;
  struct System_Single_array *v12;
  f32 v13;
  struct UnityEngine_Vector4_array *v14;
  struct UnityEngine_Vector4_array *v15;
  f32 v17;
  f32 v18;
  f32 v19;
  f32 v20;
  struct System_Single_array *v22;
  struct System_Single_array *v23;
  f32 v24;
  u32 *v25;
  u32 *v26;
  u32 v28;
  u32 v29;
  u32 v30;
  u32 v31;
  struct System_Single_array *v33;
  struct System_Single_array *v34;
  f32 v36;
  struct UnityEngine_Vector4_array *v38;
  struct UnityEngine_Vector4_array *v39;
  f32 v41;
  f32 v42;
  f32 v43;
  f32 v44;
  struct System_Single_array *v46;
  struct System_Single_array *v47;
  f32 v48;

  this->point = NewSpecific(UnityEngine_Vector4, 4u);
  this->radius = NewSpecific(f32, 4u);
  point = para->point;
  v6 = this->point;
  x = point->m_Items[0].x;
  y = point->m_Items[0].y;
  z = point->m_Items[0].z;
  w = point->m_Items[0].w;
  v6->m_Items[0].x = x;
  v6->m_Items[0].y = y;
  v6->m_Items[0].z = z;
  v6->m_Items[0].w = w;
  radius = para->radius;
  v12 = this->radius;
  v13 = radius->m_Items[0];
  v12->m_Items[0] = v13;
  v14 = para->point;
  v15 = this->point;
  v17 = v14->m_Items[1].x;
  v18 = v14->m_Items[1].y;
  v20 = v14->m_Items[1].z;
  v19 = v14->m_Items[1].w;
  v15->m_Items[1].x = v17;
  v15->m_Items[1].y = v18;
  v15->m_Items[1].z = v20;
  v15->m_Items[1].w = v19;
  v22 = para->radius;
  v23 = this->radius;
  v24 = v22->m_Items[1];
  v23->m_Items[1] = v24;
  v25 = para->point;
  v26 = this->point;
  v28 = v25[16];
  v29 = v25[17];
  v31 = v25[18];
  v30 = v25[19];
  v26[16] = v28;
  v26[17] = v29;
  v26[18] = v31;
  v26[19] = v30;
  v33 = para->radius;
  v34 = this->radius;
  v36 = v33->m_Items[2];
  v34->m_Items[2] = v36;
  v38 = para->point;
  v39 = this->point;
  v41 = v38->m_Items[3].x;
  v42 = v38->m_Items[3].y;
  v44 = v38->m_Items[3].z;
  v43 = v38->m_Items[3].w;
  v39->m_Items[3].x = v41;
  v39->m_Items[3].y = v42;
  v39->m_Items[3].z = v44;
  v39->m_Items[3].w = v43;
  v46 = para->radius;
  v47 = this->radius;
  v48 = v46->m_Items[3];
  v47->m_Items[3] = v48;
}

// 0x19dc2d0
void effMagaP4Point_t__pClone(effMagaP4Point_t *this, effMagaP4Point_t **dst) {
  effMagaP4Point_t_o *v5;
  effMagaP4Point_t_o *v6;
  struct UnityEngine_Vector4_array *point;
  struct UnityEngine_Vector4_array *v8;
  f32 x;
  f32 y;
  f32 w;
  f32 z;
  struct System_Single_array *radius;
  struct System_Single_array *v14;
  f32 v15;
  struct UnityEngine_Vector4_array *v16;
  struct UnityEngine_Vector4_array *v17;
  f32 v19;
  f32 v20;
  f32 v21;
  f32 v22;
  struct System_Single_array *v24;
  struct System_Single_array *v25;
  f32 v26;
  u32 *v27;
  u32 *v28;
  u32 v30;
  u32 v31;
  u32 v32;
  u32 v33;
  struct System_Single_array *v35;
  struct System_Single_array *v36;
  f32 v38;
  struct UnityEngine_Vector4_array *v40;
  struct UnityEngine_Vector4_array *v41;
  f32 v43;
  f32 v44;
  f32 v45;
  f32 v46;
  struct System_Single_array *v48;
  struct System_Single_array *v49;
  f32 v50;

  v5 = *dst;
  v5->point = NewSpecific(UnityEngine_Vector4, 4u);
  v6 = *dst;
  v6->radius = NewSpecific(f32, 4u);
  point = this->point;
  v8 = (*dst)->point;
  x = point->m_Items[0].x;
  y = point->m_Items[0].y;
  z = point->m_Items[0].z;
  w = point->m_Items[0].w;
  v8->m_Items[0].x = x;
  v8->m_Items[0].y = y;
  v8->m_Items[0].z = z;
  v8->m_Items[0].w = w;
  radius = this->radius;
  v14 = (*dst)->radius;
  v15 = radius->m_Items[0];
  v14->m_Items[0] = v15;
  v16 = this->point;
  v17 = (*dst)->point;
  v19 = v16->m_Items[1].x;
  v20 = v16->m_Items[1].y;
  v22 = v16->m_Items[1].z;
  v21 = v16->m_Items[1].w;
  v17->m_Items[1].x = v19;
  v17->m_Items[1].y = v20;
  v17->m_Items[1].z = v22;
  v17->m_Items[1].w = v21;
  v24 = this->radius;
  v25 = (*dst)->radius;
  v26 = v24->m_Items[1];
  v25->m_Items[1] = v26;
  v27 = this->point;
  v28 = (*dst)->point;
  v30 = v27[16];
  v31 = v27[17];
  v33 = v27[18];
  v32 = v27[19];
  v28[16] = v30;
  v28[17] = v31;
  v28[18] = v33;
  v28[19] = v32;
  v35 = this->radius;
  v36 = (*dst)->radius;
  v38 = v35->m_Items[2];
  v36->m_Items[2] = v38;
  v40 = this->point;
  v41 = (*dst)->point;
  v43 = v40->m_Items[3].x;
  v44 = v40->m_Items[3].y;
  v46 = v40->m_Items[3].z;
  v45 = v40->m_Items[3].w;
  v41->m_Items[3].x = v43;
  v41->m_Items[3].y = v44;
  v41->m_Items[3].z = v46;
  v41->m_Items[3].w = v45;
  v48 = this->radius;
  v49 = (*dst)->radius;
  v50 = v48->m_Items[3];
  v49->m_Items[3] = v50;
}

// 0x19dc630
void effMagaPoint4Param_t__bCopy(effMagaPoint4Param_t *this, u8 **bytedata, s32 *bPos) {
  struct UnityEngine_Vector4_array *v7;
  struct UnityEngine_Vector4_array *v9;
  s64 v10;
  u64 v11;
  char *v13;
  struct UnityEngine_Vector4_array *point;
  s32 v15;
  f32 v16;
  s32 v18;
  struct UnityEngine_Vector4_array *v19;
  f32 v20;
  s32 v22;
  struct UnityEngine_Vector4_array *v23;
  f32 v24;
  s32 v26;
  struct UnityEngine_Vector4_array *v27;
  f32 v28;
  s64 v30;
  s64 v31;
  s32 v33;
  s32 v34;
  s32 v35;
  s32 v36;
  struct System_Single_array *v37;
  struct System_Single_array *v39;
  s32 v40;
  f32 v42;
  s32 v44;
  struct System_Single_array *radius;
  f32 v47;
  s32 v49;
  struct System_Single_array *v50;
  f32 v52;
  s32 v54;
  struct System_Single_array *v55;
  f32 v56;
  u64 *v58;
  struct System_UInt32_array *v60;
  s32 v62;
  struct System_UInt32_array *reserve;
  u64 v64;
  u32 v66;

  v7 = NewSpecific(UnityEngine_Vector4, 4u);
  this->point = v7;
  v9 = v7;
  v10 = 0;
  v11 = 0;
  if (!LODWORD(v7->max_length))
  {
LABEL_6:
  }
  while (1)
  {
    v13 = v9 + v10 * 16;
    *(v13 + 4) = 0;
    *(v13 + 5) = 0;
    point = this->point;
    v15 = *bPos;
    v16 = Byte2Float(bytedata, v15);
    point->m_Items[v10].x = v16;
    v18 = *bPos + 4;
    *bPos = v18;
    v19 = this->point;
    v20 = Byte2Float(bytedata, v18);
    v19->m_Items[v10].y = v20;
    v22 = *bPos + 4;
    *bPos = v22;
    v23 = this->point;
    v24 = Byte2Float(bytedata, v22);
    v23->m_Items[v10].z = v24;
    v26 = *bPos + 4;
    *bPos = v26;
    v27 = this->point;
    v28 = Byte2Float(bytedata, v26);
    v27->m_Items[v10].w = v28;
    v30 = *bPos;
    v31 = v30 + 4;
    *bPos = v30 + 4;
    if (v11 == 3)
      break;
    v9 = this->point;
    ++v11;
    ++v10;
    if (v11 >= LODWORD(v9->max_length))
      goto LABEL_6;
  }
  this->loop = bytedata->m_Items[v31];
  v33 = *bPos + 4;
  *bPos = v33;
  this->life = Byte2UInt32(bytedata, v33);
  v34 = *bPos + 4;
  *bPos = v34;
  this->timing = Byte2UInt32(bytedata, v34);
  v35 = *bPos + 4;
  *bPos = v35;
  this->fade_in = Byte2UInt32(bytedata, v35);
  v36 = *bPos + 4;
  *bPos = v36;
  this->fade_out = Byte2UInt32(bytedata, v36);
  *bPos += 4;
  v37 = NewSpecific(f32, 4u);
  this->radius = v37;
  v39 = v37;
  v40 = *bPos;
  v42 = Byte2Float(bytedata, v40);
  v39->m_Items[0] = v42;
  v44 = *bPos + 4;
  *bPos = v44;
  radius = this->radius;
  v47 = Byte2Float(bytedata, v44);
  radius->m_Items[1] = v47;
  v49 = *bPos + 4;
  *bPos = v49;
  v50 = this->radius;
  v52 = Byte2Float(bytedata, v49);
  v50->m_Items[2] = v52;
  v54 = *bPos + 4;
  *bPos = v54;
  v55 = this->radius;
  v56 = Byte2Float(bytedata, v54);
  v55->m_Items[3] = v56;
  *bPos += 4;
  v58 = Allocate(effMagatuhiParams_t);
  _ctor(v58, 0);
  this->MagaParam = v58;
  effMagatuhiParams_t__bCopy(v58, bytedata, bPos);
  v60 = NewSpecific(uint, 0x40u);
  this->reserve = v60;
  v62 = *bPos;
  reserve = v60;
  v64 = 0;
  {
LABEL_47:
    goto LABEL_49;
  }
  while (1)
  {
LABEL_49:
    v66 = Byte2UInt32(bytedata, v62);
    reserve->m_Items[v64] = v66;
    v62 = *bPos + 4;
    *bPos = v62;
    if (v64 == 63)
      break;
    reserve = this->reserve;
    ++v64;
      goto LABEL_47;
  }
}

// 0x19dcb60
void effMagaPoint4Param_t__pClone(effMagaPoint4Param_t *this, effMagaPoint4Param_t **dst) {
  effMagaPoint4Param_t_o *v5;
  effMagaPoint4Param_t_o *v6;
  u64 v7;
  s64 i;
  struct UnityEngine_Vector4_array *point;
  char *v11;
  struct UnityEngine_Vector4_array *v12;
  struct UnityEngine_Vector4_array *v13;
  s32 v15;
  struct UnityEngine_Vector4_array *v17;
  struct UnityEngine_Vector4_array *v18;
  s32 v20;
  struct UnityEngine_Vector4_array *v22;
  struct UnityEngine_Vector4_array *v23;
  s32 v25;
  struct UnityEngine_Vector4_array *v27;
  struct UnityEngine_Vector4_array *v28;
  s32 v30;
  effMagaPoint4Param_t_o *v32;
  struct System_Single_array *radius;
  struct System_Single_array *v34;
  f32 v35;
  struct System_Single_array *v36;
  struct System_Single_array *v37;
  f32 v38;
  struct System_Single_array *v39;
  struct System_Single_array *v40;
  f32 v42;
  struct System_Single_array *v44;
  struct System_Single_array *v45;
  f32 v46;
  effMagaPoint4Param_t_o *v47;
  u64 *v48;
  u32 *MagaParam;
  effMagaPoint4Param_t_o *v50;
  effMagaPoint4Param_t_o *v51;
  s64 j;
  struct System_UInt32_array *reserve;
  struct System_UInt32_array *v54;
  s32 v55;

  v5 = *dst;
  v5->point = NewSpecific(UnityEngine_Vector4, 4u);
  v6 = *dst;
  v7 = 0;
  for (i = 44; i != 108; i += 16)
  {
    point = v6->point;
    v11 = point + i;
    *(v11 - 4) = 0;
    *(v11 - 12) = 0;
    v12 = this->point;
    v13 = (*dst)->point;
    v15 = *(v12 + i - 12);
    *(v13 + i - 12) = v15;
    v17 = this->point;
    v18 = (*dst)->point;
    v20 = *(v17 + i - 8);
    *(v18 + i - 8) = v20;
    v22 = this->point;
    v23 = (*dst)->point;
    v25 = *(v22 + i - 4);
    *(v23 + i - 4) = v25;
    v27 = this->point;
    v28 = (*dst)->point;
    v30 = *(&v27->obj.klass + i);
    *(&v28->obj.klass + i) = v30;
    v6 = *dst;
    ++v7;
  }
  v6->loop = this->loop;
  (*dst)->life = this->life;
  (*dst)->timing = this->timing;
  (*dst)->fade_in = this->fade_in;
  (*dst)->fade_out = this->fade_out;
  v32 = *dst;
  v32->radius = NewSpecific(f32, 4u);
  radius = this->radius;
  v34 = (*dst)->radius;
  v35 = radius->m_Items[0];
  v34->m_Items[0] = v35;
  v36 = this->radius;
  v37 = (*dst)->radius;
  v38 = v36->m_Items[1];
  v37->m_Items[1] = v38;
  v39 = this->radius;
  v40 = (*dst)->radius;
  v42 = v39->m_Items[2];
  v40->m_Items[2] = v42;
  v44 = this->radius;
  v45 = (*dst)->radius;
  v46 = v44->m_Items[3];
  v45->m_Items[3] = v46;
  v47 = *dst;
  v48 = Allocate(effMagatuhiParams_t);
  _ctor(v48, 0);
  v47->MagaParam = v48;
  MagaParam = this->MagaParam;
  v50 = *dst;
  (*dst)->MagaParam->number = MagaParam[4];
  v50->MagaParam->tail = MagaParam[5];
  LODWORD(v50->MagaParam->scale) = MagaParam[6];
  v50->MagaParam->abgr_s = MagaParam[7];
  v50->MagaParam->abgr_e = MagaParam[8];
  v50->MagaParam->blend = MagaParam[9];
  LODWORD(v50->MagaParam->t) = MagaParam[10];
  v51 = *dst;
  v51->reserve = NewSpecific(uint, 0x40u);
  for (j = 8; j != 72; ++j)
  {
    reserve = this->reserve;
    v54 = (*dst)->reserve;
    v55 = *(&reserve->obj.klass + j);
    *(&v54->obj.klass + j) = v55;
  }
}

// 0x19dd050
void effMagaSCArea_t__Copy(effMagaSCArea_t *this, effMagaSCArea_t *para) {
  f32 z;
  f32 w;
  f32 v5;
  f32 v6;

  z = para->s_center.z;
  w = para->s_center.w;
  *&this->s_center.x = *&para->s_center.x;
  this->s_center.z = z;
  this->s_center.w = w;
  v5 = para->c_center.z;
  v6 = para->c_center.w;
  *&this->c_center.x = *&para->c_center.x;
  this->c_center.z = v5;
  this->c_center.w = v6;
  this->s_radius = para->s_radius;
  this->c_radius = para->c_radius;
}

// 0x19dd090
void effMagaSCArea_t__pClone(effMagaSCArea_t *this, effMagaSCArea_t **dst) {
  effMagaSCArea_t_o *v3;
  f32 z;
  f32 w;
  effMagaSCArea_t_o *v6;
  f32 v7;
  f32 v8;

  v3 = *dst;
  z = this->s_center.z;
  w = this->s_center.w;
  *&v3->s_center.x = *&this->s_center.x;
  v3->s_center.z = z;
  v3->s_center.w = w;
  v6 = *dst;
  v7 = this->c_center.z;
  v8 = this->c_center.w;
  *&v6->c_center.x = *&this->c_center.x;
  v6->c_center.z = v7;
  v6->c_center.w = v8;
  (*dst)->s_radius = this->s_radius;
  (*dst)->c_radius = this->c_radius;
}

// 0x19dd0f0
void effMagaSmokeConvParam_t__bCopy(effMagaSmokeConvParam_t *this, u8 **bytedata, s32 *bPos) {
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;
  s32 v11;
  s32 v12;
  s32 v13;
  s64 v14;
  s32 v16;
  s32 v17;
  s32 v18;
  s32 v19;
  s32 v20;
  s32 v21;
  s32 v22;
  s32 v23;
  s32 v24;
  s32 v25;
  s32 v26;
  s32 v27;
  s32 v28;
  s32 v29;
  s32 v30;
  u64 *v31;
  struct System_UInt32_array *v33;
  s32 v35;
  struct System_UInt32_array *reserve;
  u64 v37;
  u32 v39;

  *&this->s_pos.x = 0;
  *&this->s_pos.z = 0;
  v7 = *bPos;
  this->s_pos.x = Byte2Float(bytedata, v7);
  v8 = *bPos + 4;
  *bPos = v8;
  this->s_pos.y = Byte2Float(bytedata, v8);
  v9 = *bPos + 4;
  *bPos = v9;
  this->s_pos.z = Byte2Float(bytedata, v9);
  v10 = *bPos + 4;
  *bPos = v10;
  this->s_pos.w = Byte2Float(bytedata, v10);
  *bPos += 4;
  *&this->c_pos.x = 0;
  *&this->c_pos.z = 0;
  this->c_pos.x = Byte2Float(bytedata, *bPos);
  v11 = *bPos + 4;
  *bPos = v11;
  this->c_pos.y = Byte2Float(bytedata, v11);
  v12 = *bPos + 4;
  *bPos = v12;
  this->c_pos.z = Byte2Float(bytedata, v12);
  v13 = *bPos + 4;
  *bPos = v13;
  this->c_pos.w = Byte2Float(bytedata, v13);
  v14 = *bPos + 4LL;
  *bPos = v14;
  this->loop = bytedata->m_Items[v14];
  v16 = *bPos + 4;
  *bPos = v16;
  this->life = Byte2UInt32(bytedata, v16);
  v17 = *bPos + 4;
  *bPos = v17;
  this->timing = Byte2UInt32(bytedata, v17);
  v18 = *bPos + 4;
  *bPos = v18;
  this->fade_in = Byte2UInt32(bytedata, v18);
  v19 = *bPos + 4;
  *bPos = v19;
  this->fade_out = Byte2UInt32(bytedata, v19);
  v20 = *bPos + 4;
  *bPos = v20;
  this->s_radius = Byte2Float(bytedata, v20);
  v21 = *bPos + 4;
  *bPos = v21;
  this->s_up_s = Byte2Float(bytedata, v21);
  v22 = *bPos + 4;
  *bPos = v22;
  this->s_up_s_r = Byte2Float(bytedata, v22);
  v23 = *bPos + 4;
  *bPos = v23;
  this->s_angle_s = Byte2Float(bytedata, v23);
  v24 = *bPos + 4;
  *bPos = v24;
  this->s_ampli = Byte2Float(bytedata, v24);
  v25 = *bPos + 4;
  *bPos = v25;
  this->s_ampli_s = Byte2Float(bytedata, v25);
  v26 = *bPos + 4;
  *bPos = v26;
  this->s_ampli_r = Byte2Float(bytedata, v26);
  v27 = *bPos + 4;
  *bPos = v27;
  this->c_radius = Byte2Float(bytedata, v27);
  v28 = *bPos + 4;
  *bPos = v28;
  this->c_ampli = Byte2Float(bytedata, v28);
  v29 = *bPos + 4;
  *bPos = v29;
  this->c_step = Byte2Float(bytedata, v29);
  v30 = *bPos + 4;
  *bPos = v30;
  this->c_step_a = Byte2Float(bytedata, v30);
  *bPos += 4;
  v31 = Allocate(effMagatuhiParams_t);
  _ctor(v31, 0);
  this->MagaParam = v31;
  effMagatuhiParams_t__bCopy(v31, bytedata, bPos);
  v33 = NewSpecific(uint, 0x40u);
  this->reserve = v33;
  v35 = *bPos;
  reserve = v33;
  v37 = 0;
  {
LABEL_11:
    goto LABEL_13;
  }
  while (1)
  {
LABEL_13:
    v39 = Byte2UInt32(bytedata, v35);
    reserve->m_Items[v37] = v39;
    v35 = *bPos + 4;
    *bPos = v35;
    if (v37 == 63)
      break;
    reserve = this->reserve;
    ++v37;
      goto LABEL_11;
  }
}

// 0x19dd510
void effMagaSmokeConvParam_t__pClone(effMagaSmokeConvParam_t *this, effMagaSmokeConvParam_t **dst) {
  effMagaSmokeConvParam_t_o *v5;
  u64 *v6;
  u32 *MagaParam;
  effMagaSmokeConvParam_t_o *v8;
  effMagaSmokeConvParam_t_o *v9;
  s64 i;
  struct System_UInt32_array *reserve;
  struct System_UInt32_array *v12;
  s32 v13;

  (*dst)->s_pos.x = this->s_pos.x;
  (*dst)->s_pos.y = this->s_pos.y;
  (*dst)->s_pos.z = this->s_pos.z;
  (*dst)->s_pos.w = this->s_pos.w;
  (*dst)->c_pos.x = this->c_pos.x;
  (*dst)->c_pos.y = this->c_pos.y;
  (*dst)->c_pos.z = this->c_pos.z;
  (*dst)->c_pos.w = this->c_pos.w;
  (*dst)->loop = this->loop;
  (*dst)->life = this->life;
  (*dst)->timing = this->timing;
  (*dst)->fade_in = this->fade_in;
  (*dst)->fade_out = this->fade_out;
  (*dst)->s_radius = this->s_radius;
  (*dst)->s_up_s = this->s_up_s;
  (*dst)->s_up_s_r = this->s_up_s_r;
  (*dst)->s_angle_s = this->s_angle_s;
  (*dst)->s_ampli = this->s_ampli;
  (*dst)->s_ampli_s = this->s_ampli_s;
  (*dst)->s_ampli_r = this->s_ampli_r;
  (*dst)->c_radius = this->c_radius;
  (*dst)->c_ampli = this->c_ampli;
  (*dst)->c_step = this->c_step;
  (*dst)->c_step_a = this->c_step_a;
  v5 = *dst;
  v6 = Allocate(effMagatuhiParams_t);
  _ctor(v6, 0);
  v5->MagaParam = v6;
  MagaParam = this->MagaParam;
  v8 = *dst;
  (*dst)->MagaParam->number = MagaParam[4];
  v8->MagaParam->tail = MagaParam[5];
  LODWORD(v8->MagaParam->scale) = MagaParam[6];
  v8->MagaParam->abgr_s = MagaParam[7];
  v8->MagaParam->abgr_e = MagaParam[8];
  v8->MagaParam->blend = MagaParam[9];
  LODWORD(v8->MagaParam->t) = MagaParam[10];
  v9 = *dst;
  v9->reserve = NewSpecific(uint, 0x40u);
  for (i = 8; i != 72; ++i)
  {
    reserve = this->reserve;
    v12 = (*dst)->reserve;
    v13 = *(&reserve->obj.klass + i);
    *(&v12->obj.klass + i) = v13;
  }
}

// 0x19dd7c0
void effMagaSmokeParam_t__bCopy(effMagaSmokeParam_t *this, u8 **bytedata, s32 *bPos) {
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;
  s64 v11;
  s32 v13;
  s32 v14;
  s32 v15;
  s32 v16;
  s32 v17;
  s32 v18;
  s32 v19;
  s32 v20;
  s32 v21;
  s32 v22;
  s32 v23;
  u64 *v24;
  struct System_UInt32_array *v26;
  s32 v28;
  struct System_UInt32_array *reserve;
  u64 v30;
  u32 v32;

  *&this->pos.x = 0;
  *&this->pos.z = 0;
  v7 = *bPos;
  this->pos.x = Byte2Float(bytedata, v7);
  v8 = *bPos + 4;
  *bPos = v8;
  this->pos.y = Byte2Float(bytedata, v8);
  v9 = *bPos + 4;
  *bPos = v9;
  this->pos.z = Byte2Float(bytedata, v9);
  v10 = *bPos + 4;
  *bPos = v10;
  this->pos.w = Byte2Float(bytedata, v10);
  v11 = *bPos + 4LL;
  *bPos = v11;
  this->loop = bytedata->m_Items[v11];
  v13 = *bPos + 4;
  *bPos = v13;
  this->life = Byte2UInt32(bytedata, v13);
  v14 = *bPos + 4;
  *bPos = v14;
  this->timing = Byte2UInt32(bytedata, v14);
  v15 = *bPos + 4;
  *bPos = v15;
  this->fade_in = Byte2UInt32(bytedata, v15);
  v16 = *bPos + 4;
  *bPos = v16;
  this->fade_out = Byte2UInt32(bytedata, v16);
  v17 = *bPos + 4;
  *bPos = v17;
  this->radius = Byte2Float(bytedata, v17);
  v18 = *bPos + 4;
  *bPos = v18;
  this->up_s = Byte2Float(bytedata, v18);
  v19 = *bPos + 4;
  *bPos = v19;
  this->up_s_r = Byte2Float(bytedata, v19);
  v20 = *bPos + 4;
  *bPos = v20;
  this->angle_s = Byte2Float(bytedata, v20);
  v21 = *bPos + 4;
  *bPos = v21;
  this->ampli = Byte2Float(bytedata, v21);
  v22 = *bPos + 4;
  *bPos = v22;
  this->ampli_s = Byte2Float(bytedata, v22);
  v23 = *bPos + 4;
  *bPos = v23;
  this->ampli_r = Byte2Float(bytedata, v23);
  *bPos += 4;
  v24 = Allocate(effMagatuhiParams_t);
  _ctor(v24, 0);
  this->MagaParam = v24;
  effMagatuhiParams_t__bCopy(v24, bytedata, bPos);
  v26 = NewSpecific(uint, 0x20u);
  this->reserve = v26;
  v28 = *bPos;
  reserve = v26;
  v30 = 0;
  {
LABEL_11:
    goto LABEL_13;
  }
  while (1)
  {
LABEL_13:
    v32 = Byte2UInt32(bytedata, v28);
    reserve->m_Items[v30] = v32;
    v28 = *bPos + 4;
    *bPos = v28;
    if (v30 == 31)
      break;
    reserve = this->reserve;
    ++v30;
      goto LABEL_11;
  }
}

// 0x19ddb00
void effMagaSmokeParam_t__pClone(effMagaSmokeParam_t *this, effMagaSmokeParam_t **dst) {
  effMagaSmokeParam_t_o *v5;
  effMagaSmokeParam_t_o *v6;
  u64 *v7;
  u32 *MagaParam;
  effMagaSmokeParam_t_o *v9;
  effMagaSmokeParam_t_o *v10;
  s64 i;
  struct System_UInt32_array *reserve;
  struct System_UInt32_array *v13;
  s32 v14;

  v5 = *dst;
  *&v5->pos.x = 0;
  *&v5->pos.z = 0;
  (*dst)->pos.x = this->pos.x;
  (*dst)->pos.y = this->pos.y;
  (*dst)->pos.z = this->pos.z;
  (*dst)->pos.w = this->pos.w;
  (*dst)->loop = this->loop;
  (*dst)->life = this->life;
  (*dst)->timing = this->timing;
  (*dst)->fade_in = this->fade_in;
  (*dst)->fade_out = this->fade_out;
  (*dst)->radius = this->radius;
  (*dst)->up_s = this->up_s;
  (*dst)->up_s_r = this->up_s_r;
  (*dst)->angle_s = this->angle_s;
  (*dst)->ampli = this->ampli;
  (*dst)->ampli_s = this->ampli_s;
  (*dst)->ampli_r = this->ampli_r;
  v6 = *dst;
  v7 = Allocate(effMagatuhiParams_t);
  _ctor(v7, 0);
  v6->MagaParam = v7;
  MagaParam = this->MagaParam;
  v9 = *dst;
  (*dst)->MagaParam->number = MagaParam[4];
  v9->MagaParam->tail = MagaParam[5];
  LODWORD(v9->MagaParam->scale) = MagaParam[6];
  v9->MagaParam->abgr_s = MagaParam[7];
  v9->MagaParam->abgr_e = MagaParam[8];
  v9->MagaParam->blend = MagaParam[9];
  LODWORD(v9->MagaParam->t) = MagaParam[10];
  v10 = *dst;
  v10->reserve = NewSpecific(uint, 0x20u);
  for (i = 8; i != 40; ++i)
  {
    reserve = this->reserve;
    v13 = (*dst)->reserve;
    v14 = *(&reserve->obj.klass + i);
    *(&v13->obj.klass + i) = v14;
  }
}

// 0x19ddd50
void effMagaSpiralParam_t__bCopy(effMagaSpiralParam_t *this, u8 **bytedata, s32 *bPos) {
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;
  s64 v11;
  s32 v13;
  s32 v14;
  s32 v15;
  s32 v16;
  s32 v17;
  s32 v18;
  s32 v19;
  s32 v20;
  s32 v21;
  s32 v22;
  s32 v23;
  s32 v24;
  u64 *v25;
  struct System_UInt32_array *v27;
  s32 v29;
  struct System_UInt32_array *reserve;
  u64 v31;
  u32 v33;

  *&this->pos.x = 0;
  *&this->pos.z = 0;
  v7 = *bPos;
  this->pos.x = Byte2Float(bytedata, v7);
  v8 = *bPos + 4;
  *bPos = v8;
  this->pos.y = Byte2Float(bytedata, v8);
  v9 = *bPos + 4;
  *bPos = v9;
  this->pos.z = Byte2Float(bytedata, v9);
  v10 = *bPos + 4;
  *bPos = v10;
  this->pos.w = Byte2Float(bytedata, v10);
  v11 = *bPos + 4LL;
  *bPos = v11;
  this->loop = bytedata->m_Items[v11];
  v13 = *bPos + 4;
  *bPos = v13;
  this->life = Byte2UInt32(bytedata, v13);
  v14 = *bPos + 4;
  *bPos = v14;
  this->timing = Byte2UInt32(bytedata, v14);
  v15 = *bPos + 4;
  *bPos = v15;
  this->fade_in = Byte2UInt32(bytedata, v15);
  v16 = *bPos + 4;
  *bPos = v16;
  this->fade_out = Byte2UInt32(bytedata, v16);
  v17 = *bPos + 4;
  *bPos = v17;
  this->rotate_s = Byte2Float(bytedata, v17);
  v18 = *bPos + 4;
  *bPos = v18;
  this->rotate_r = Byte2Float(bytedata, v18);
  v19 = *bPos + 4;
  *bPos = v19;
  this->up_s = Byte2Float(bytedata, v19);
  v20 = *bPos + 4;
  *bPos = v20;
  this->up_r = Byte2Float(bytedata, v20);
  v21 = *bPos + 4;
  *bPos = v21;
  this->radius_s = Byte2Float(bytedata, v21);
  v22 = *bPos + 4;
  *bPos = v22;
  this->radius_e = Byte2Float(bytedata, v22);
  v23 = *bPos + 4;
  *bPos = v23;
  this->radius_s_r = Byte2Float(bytedata, v23);
  v24 = *bPos + 4;
  *bPos = v24;
  this->radius_e_r = Byte2Float(bytedata, v24);
  *bPos += 4;
  v25 = Allocate(effMagatuhiParams_t);
  _ctor(v25, 0);
  this->MagaParam = v25;
  effMagatuhiParams_t__bCopy(v25, bytedata, bPos);
  v27 = NewSpecific(uint, 0x20u);
  this->reserve = v27;
  v29 = *bPos;
  reserve = v27;
  v31 = 0;
  {
LABEL_11:
    goto LABEL_13;
  }
  while (1)
  {
LABEL_13:
    v33 = Byte2UInt32(bytedata, v29);
    reserve->m_Items[v31] = v33;
    v29 = *bPos + 4;
    *bPos = v29;
    if (v31 == 31)
      break;
    reserve = this->reserve;
    ++v31;
      goto LABEL_11;
  }
}

// 0x19de0a0
void effMagaSpiralParam_t__pClone(effMagaSpiralParam_t *this, effMagaSpiralParam_t **dst) {
  effMagaSpiralParam_t_o *v5;
  effMagaSpiralParam_t_o *v6;
  u64 *v7;
  u32 *MagaParam;
  effMagaSpiralParam_t_o *v9;
  effMagaSpiralParam_t_o *v10;
  s64 i;
  struct System_UInt32_array *reserve;
  struct System_UInt32_array *v13;
  s32 v14;

  v5 = *dst;
  *&v5->pos.x = 0;
  *&v5->pos.z = 0;
  (*dst)->pos.x = this->pos.x;
  (*dst)->pos.y = this->pos.y;
  (*dst)->pos.z = this->pos.z;
  (*dst)->pos.w = this->pos.w;
  (*dst)->loop = this->loop;
  (*dst)->life = this->life;
  (*dst)->timing = this->timing;
  (*dst)->fade_in = this->fade_in;
  (*dst)->fade_out = this->fade_out;
  (*dst)->rotate_s = this->rotate_s;
  (*dst)->rotate_r = this->rotate_r;
  (*dst)->up_s = this->up_s;
  (*dst)->up_r = this->up_r;
  (*dst)->radius_s = this->radius_s;
  (*dst)->radius_e = this->radius_e;
  (*dst)->radius_s_r = this->radius_s_r;
  (*dst)->radius_e_r = this->radius_e_r;
  v6 = *dst;
  v7 = Allocate(effMagatuhiParams_t);
  _ctor(v7, 0);
  v6->MagaParam = v7;
  MagaParam = this->MagaParam;
  v9 = *dst;
  (*dst)->MagaParam->number = MagaParam[4];
  v9->MagaParam->tail = MagaParam[5];
  LODWORD(v9->MagaParam->scale) = MagaParam[6];
  v9->MagaParam->abgr_s = MagaParam[7];
  v9->MagaParam->abgr_e = MagaParam[8];
  v9->MagaParam->blend = MagaParam[9];
  LODWORD(v9->MagaParam->t) = MagaParam[10];
  v10 = *dst;
  v10->reserve = NewSpecific(uint, 0x20u);
  for (i = 8; i != 40; ++i)
  {
    reserve = this->reserve;
    v13 = (*dst)->reserve;
    v14 = *(&reserve->obj.klass + i);
    *(&v13->obj.klass + i) = v14;
  }
}

// 0x19dbbb0
void effMagatuhiParams_t__bCopy(effMagatuhiParams_t *this, u8 **bytedata, s32 *bPos) {
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;
  s32 v11;
  s32 v12;
  s32 v13;

  v7 = *bPos;
  this->number = Byte2UInt32(bytedata, v7);
  v8 = *bPos + 4;
  *bPos = v8;
  this->tail = Byte2UInt32(bytedata, v8);
  v9 = *bPos + 4;
  *bPos = v9;
  this->scale = Byte2Float(bytedata, v9);
  v10 = *bPos + 4;
  *bPos = v10;
  this->abgr_s = Byte2UInt32(bytedata, v10);
  v11 = *bPos + 4;
  *bPos = v11;
  this->abgr_e = Byte2UInt32(bytedata, v11);
  v12 = *bPos + 4;
  *bPos = v12;
  this->blend = Byte2UInt32(bytedata, v12);
  v13 = *bPos + 4;
  *bPos = v13;
  this->t = Byte2Float(bytedata, v13);
  *bPos += 4;
}

// 0x19dbf30
void effMagatuhiParams_t__pClone(effMagatuhiParams_t *this, effMagatuhiParams_t **dst) {
  (*dst)->fields = this->fields;
}

// 0x19de300
effPCPAgiFireball2Param_t **effPCPAgiFireball2Param_t__pCopy(effPCPAgiFireball2Param_t *this, void *pData, s32 *pos, s32 max) {
  u32 *v8;
  Il2CppClass *v9;
  s64 *Interface;
  char *v11;
  s64 *v12;
  u32 *v13;
  s64 *v14;
  u64 v15;
  Il2CppObject *v24;
  Il2CppClass *klass;
  s32 v28;
  u32 v30;
  s32 v32;
  s64 v34;
  u32 v36;
  s32 v38;
  s64 v40;
  u32 v41;
  u64 *v43;
  u64 *v44;
  s64 *v46;
  s64 *v49;
  s64 v51;
  effPCPAgiFireballParam_t_array *v53;
  s64 *v54;
  u64 *v57;
  s64 *v59;
  s64 v62;
  effPCPAgiFireballParam_t_array *v64;
  s64 *v65;
  u64 *v68;
  s64 *v70;
  s64 v74;
  effPCPAgiFireballParam_t_array *v76;
  s64 *v77;
  s64 v81;
  u64 v82[3];

  v81 = max;
  v8 = NewSpecific(effPCPAgiFireball2Param_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v9, v82);
      if ((v82[0] & 1) != 0)
        v11 = v82[2];
      else
        v11 = v82 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v13 = v8 + 8;
    v14 = &effPCPAgiFireballParam_t;
    v15 = 0;
    do
    {
      v24 = Allocate(effPCPAgiFireball2Param_t);
      v24[1].klass = NewSpecific(s32, 3u);
      v24[1].monitor = NewSpecific(*v14, 3u);
      _ctor(v24, 0);
      *&v13[2 * v15] = v24;
      klass = v24[1].klass;
      v28 = *pos;
      v30 = Byte2UInt32(Interface, v28);
      LODWORD(klass->_1.byval_arg.data) = v30;
      v32 = *pos + 4;
      *pos = v32;
      v34 = *(*&v13[2 * v15] + 16LL);
      v36 = Byte2UInt32(Interface, v32);
      *(v34 + 36) = v36;
      v38 = *pos + 4;
      *pos = v38;
      v40 = *(*&v13[2 * v15] + 16LL);
      v41 = Byte2UInt32(Interface, v38);
      *(v40 + 40) = v41;
      *pos += 4;
      v43 = NewSpecific(*v14, 3u);
      v44 = Allocate(effPCPAgiFireballParam_t);
      effPCPAgiFireballParam_t___ctor(v44);
      if (v44)
      {
        v46 = QueryInterface(v44, *(*v43 + 64LL));
      }
      v43[4] = v44;
      v49 = v14;
      v51 = *(*&v13[2 * v15] + 24LL);
      v53 = effPCPAgiFireballParam_t__pCopy(v46, Interface, pos, 1);
      v54 = v53->m_Items[0];
      *(v51 + 32) = v54;
      v57 = Allocate(effPCPAgiFireballParam_t);
      effPCPAgiFireballParam_t___ctor(v57);
      if (v57)
      {
        v59 = QueryInterface(v57, *(*v43 + 64LL));
      }
      v43[5] = v57;
      v62 = *(*&v13[2 * v15] + 24LL);
      v64 = effPCPAgiFireballParam_t__pCopy(v59, Interface, pos, 1);
      v65 = v64->m_Items[0];
      *(v62 + 40) = v65;
      v68 = Allocate(effPCPAgiFireballParam_t);
      effPCPAgiFireballParam_t___ctor(v68);
      if (v68)
      {
        v70 = QueryInterface(v68, *(*v43 + 64LL));
      }
      v14 = v49;
      v43[6] = v68;
      v74 = *(*&v13[2 * v15] + 24LL);
      v76 = effPCPAgiFireballParam_t__pCopy(v70, Interface, pos, 1);
      v77 = v76->m_Items[0];
      ++v15;
      *(v74 + 48) = v77;
    }
    while (v81 != v15);
  }
  return v8;
}

// 0x19debb0
effPCPAgiFireballParam_t **effPCPAgiFireballParam_t__pCopy(effPCPAgiFireballParam_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  u32 *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u64 v14;
  effPCPAgiFireballParam_t_o *v15;
  u32 *v18;
  u32 *v19;
  s32 v20;
  s32 v23;
  s64 v25;
  s32 v26;
  s64 v28;
  s32 v29;
  s64 v31;
  s32 v32;
  s64 v34;
  s32 v35;
  s64 v37;
  s32 v38;
  s64 v40;
  s32 v42;
  s64 v44;
  u32 v46;
  s32 v48;
  s64 v50;
  u32 v52;
  s32 v54;
  s64 v56;
  u32 v58;
  s32 v60;
  s64 v62;
  f32 v64;
  s32 v66;
  s64 v68;
  f32 v70;
  s32 v72;
  s64 v74;
  f32 v76;
  s32 v78;
  s64 v80;
  f32 v82;
  s32 v84;
  s64 v86;
  f32 v88;
  s32 v90;
  s64 v92;
  f32 v94;
  u64 v96;
  s64 v97;
  s64 v99;
  s64 v100;
  s32 v101;
  f32 v102;
  s32 v104;
  u64 v106[3];

  v8 = max;
  v9 = NewSpecific(effPCPAgiFireballParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v106);
      if ((v106[0] & 1) != 0)
        v12 = v106[2];
      else
        v12 = v106 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = 0;
    do
    {
      v15 = Allocate(effPCPAgiFireballParam_t);
      effPCPAgiFireballParam_t___ctor(v15);
      v18 = &v9[2 * v14];
      *(v18 + 4) = v15;
      v19 = v18 + 8;
      v20 = *pos;
      v15->pos.x = Byte2Float(Interface, v20);
      v23 = *pos + 4;
      *pos = v23;
      v25 = *v19;
      *(v25 + 20) = Byte2Float(Interface, v23);
      v26 = *pos + 4;
      *pos = v26;
      v28 = *v19;
      *(v28 + 24) = Byte2Float(Interface, v26);
      v29 = *pos + 4;
      *pos = v29;
      v31 = *v19;
      *(v31 + 28) = Byte2Float(Interface, v29);
      v32 = *pos + 4;
      *pos = v32;
      v34 = *v19;
      *(v34 + 32) = Byte2UInt32(Interface, v32);
      v35 = *pos + 4;
      *pos = v35;
      v37 = *v19;
      *(v37 + 36) = Byte2UInt32(Interface, v35);
      v38 = *pos + 4;
      *pos = v38;
      v40 = *v19;
      *(v40 + 40) = Byte2Float(Interface, v38);
      v42 = *pos + 4;
      *pos = v42;
      v44 = *(*v19 + 48LL);
      v46 = Byte2UInt32(Interface, v42);
      *(v44 + 32) = v46;
      v48 = *pos + 4;
      *pos = v48;
      v50 = *(*v19 + 48LL);
      v52 = Byte2UInt32(Interface, v48);
      *(v50 + 36) = v52;
      v54 = *pos + 4;
      *pos = v54;
      v56 = *(*v19 + 48LL);
      v58 = Byte2UInt32(Interface, v54);
      *(v56 + 40) = v58;
      v60 = *pos + 4;
      *pos = v60;
      v62 = *(*v19 + 56LL);
      v64 = Byte2Float(Interface, v60);
      *(v62 + 32) = v64;
      v66 = *pos + 4;
      *pos = v66;
      v68 = *(*v19 + 56LL);
      v70 = Byte2Float(Interface, v66);
      *(v68 + 36) = v70;
      v72 = *pos + 4;
      *pos = v72;
      v74 = *(*v19 + 56LL);
      v76 = Byte2Float(Interface, v72);
      *(v74 + 40) = v76;
      v78 = *pos + 4;
      *pos = v78;
      v80 = *(*v19 + 64LL);
      v82 = Byte2Float(Interface, v78);
      *(v80 + 32) = v82;
      v84 = *pos + 4;
      *pos = v84;
      v86 = *(*v19 + 64LL);
      v88 = Byte2Float(Interface, v84);
      *(v86 + 36) = v88;
      v90 = *pos + 4;
      *pos = v90;
      v92 = *(*v19 + 64LL);
      v94 = Byte2Float(Interface, v90);
      *(v92 + 40) = v94;
      v96 = 0;
      *pos += 4;
      if (v14 >= v9[6])
      {
LABEL_98:
      }
      while (1)
      {
        v99 = *v19;
        if (v96 == 3)
          break;
        v100 = *(v99 + 72);
        v101 = *pos;
        v102 = Byte2Float(Interface, v101);
        v97 = v100 + 4 * v96++;
        *(v97 + 32) = v102;
        *pos += 4;
        if (v14 >= v9[6])
          goto LABEL_98;
      }
      v104 = *pos;
      *(v99 + 80) = Byte2UInt32(Interface, v104);
      ++v14;
      *pos += 4;
    }
    while (v14 != v8);
  }
  return v9;
}

// 0x19df640
void effPCPAgiFireballPartList_t__Clear(effPCPAgiFireballPartList_t *this) {
  ;
}

// 0x19df650
effPCPAgiraoFireParam_t **effPCPAgiraoFireParam_t__pCopy(effPCPAgiraoFireParam_t *this, void *pData, s32 *pos, s32 max) {
  u32 *v8;
  Il2CppClass *v9;
  s64 *Interface;
  char *v11;
  s64 *v12;
  u64 v13;
  u64 *v14;
  u32 *v16;
  u32 *v17;
  s32 v18;
  s32 v21;
  s64 v23;
  s32 v24;
  s64 v26;
  s32 v27;
  s64 v29;
  s64 v31;
  s64 v32;
  u64 v33;
  s64 v35;
  s64 v37;
  s64 v38;
  s32 v39;
  f32 v40;
  s32 v42;
  s64 v44;
  f32 v45;
  u64 v47;
  s64 v49;
  s64 v51;
  s64 v52;
  s32 v53;
  u32 v54;
  s32 v58;
  s64 v59;
  u32 v61;
  s32 v63;
  s64 v65;
  u32 v67;
  s32 v69;
  s64 v71;
  u32 v73;
  s32 v75;
  s64 v77;
  u32 v79;
  s32 v81;
  s64 v83;
  u32 v85;
  s32 v87;
  s64 v89;
  u32 v91;
  s32 v93;
  s64 v95;
  u32 v96;
  u64 v99[3];
  s64 v100;

  v100 = max;
  v8 = NewSpecific(effPCPAgiraoFireParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v9, v99);
      if ((v99[0] & 1) != 0)
        v11 = v99[2];
      else
        v11 = v99 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v13 = 0;
    do
    {
      v14 = Allocate(effPCPAgiraoFireParam_t);
      _ctor(v14, 0);
      v16 = &v8[2 * v13];
      *(v16 + 4) = v14;
      v17 = v16 + 8;
      v18 = *pos;
      *(v14 + 4) = Byte2Float(Interface, v18);
      v21 = *pos + 4;
      *pos = v21;
      v23 = *v17;
      *(v23 + 20) = Byte2Float(Interface, v21);
      v24 = *pos + 4;
      *pos = v24;
      v26 = *v17;
      *(v26 + 16) = Byte2Float(Interface, v24);
      v27 = *pos + 4;
      *pos = v27;
      v29 = *v17;
      *(v29 + 28) = Byte2Float(Interface, v27);
      *pos += 4;
      v31 = *v17;
      v32 = 0;
      v33 = 0;
      *(v31 + 32) = NewSpecific(UnityEngine_Vector2, 3u);
      if (v13 >= v8[6])
      {
LABEL_31:
      }
      while (1)
      {
        v37 = *v17;
        if (v33 == 3)
          break;
        v38 = *(v37 + 32);
        v39 = *pos;
        v40 = Byte2Float(Interface, v39);
        *(v38 + v32 + 32) = v40;
        v42 = *pos + 4;
        *pos = v42;
        v44 = *(*v17 + 32LL);
        v45 = Byte2Float(Interface, v42);
        v35 = v44 + v32;
        v32 += 8;
        *(v35 + 36) = v45;
        ++v33;
        *pos += 4;
        if (v13 >= v8[6])
          goto LABEL_31;
      }
      v47 = 0;
      *(v37 + 40) = NewSpecific(s32, 3u);
      if (v13 >= v8[6])
      {
LABEL_45:
      }
      while (1)
      {
        v51 = *v17;
        if (v47 == 3)
          break;
        v52 = *(v51 + 40);
        v53 = *pos;
        v54 = Byte2UInt32(Interface, v53);
        v49 = v52 + 4 * v47++;
        *(v49 + 32) = v54;
        *pos += 4;
        if (v13 >= v8[6])
          goto LABEL_45;
      }
      *(v51 + 48) = NewSpecific(s32, 7u);
      v58 = *pos;
      v59 = *(*v17 + 48LL);
      v61 = Byte2UInt32(Interface, v58);
      *(v59 + 32) = v61;
      v63 = *pos + 4;
      *pos = v63;
      v65 = *(*v17 + 48LL);
      v67 = Byte2UInt32(Interface, v63);
      *(v65 + 36) = v67;
      v69 = *pos + 4;
      *pos = v69;
      v71 = *(*v17 + 48LL);
      v73 = Byte2UInt32(Interface, v69);
      *(v71 + 40) = v73;
      v75 = *pos + 4;
      *pos = v75;
      v77 = *(*v17 + 48LL);
      v79 = Byte2UInt32(Interface, v75);
      *(v77 + 44) = v79;
      v81 = *pos + 4;
      *pos = v81;
      v83 = *(*v17 + 48LL);
      v85 = Byte2UInt32(Interface, v81);
      *(v83 + 48) = v85;
      v87 = *pos + 4;
      *pos = v87;
      v89 = *(*v17 + 48LL);
      v91 = Byte2UInt32(Interface, v87);
      *(v89 + 52) = v91;
      v93 = *pos + 4;
      *pos = v93;
      v95 = *(*v17 + 48LL);
      v96 = Byte2UInt32(Interface, v93);
      *(v95 + 56) = v96;
      *pos += 4;
      ++v13;
    }
    while (v13 != v100);
  }
  return v8;
}

// 0x19e0650
void effPCPBezierBillParam_t__pClone(effPCPBezierBillParam_t *this, effPCPBezierBillParam_t **dst) {
  (*dst)->fields = this->fields;
}

// 0x19dff60
effPCPBezierBillParam_t **effPCPBezierBillParam_t__pCopy(effPCPBezierBillParam_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  effPCPBezierBillParam_t_array *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u64 v14;
  il2cpp_array_size_t *p_max_length;
  u64 *v17;
  u64 **v20;
  s32 v21;
  s32 v22;
  u64 *v24;
  s32 v25;
  u64 *v27;
  s32 v28;
  u64 *v30;
  s32 v31;
  u64 *v33;
  s32 v34;
  u64 *v36;
  s32 v37;
  u64 *v39;
  s32 v40;
  u64 *v42;
  s32 v43;
  u64 *v45;
  s32 v46;
  u64 *v48;
  s32 v49;
  u64 *v51;
  s32 v52;
  u64 *v54;
  s32 v55;
  u64 *v57;
  s32 v58;
  u64 *v60;
  s32 v61;
  u64 *v63;
  s32 v64;
  u64 *v66;
  s32 v67;
  u64 *v69;
  s32 v70;
  u64 *v72;
  s32 v73;
  u64 *v75;
  s32 v76;
  u64 *v78;
  u64 v80[3];

  v8 = max;
  v9 = NewSpecific(effPCPBezierBillParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v80);
      if ((v80[0] & 1) != 0)
        v12 = v80[2];
      else
        v12 = v80 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = 0;
    p_max_length = &v9->max_length;
    do
    {
      v17 = Allocate(effPCPBezierBillParam_t);
      _ctor(v17, 0);
      v20 = &v9->m_Items[v14];
      *v20 = v17;
      v21 = *pos;
      *(v17 + 4) = Byte2Float(Interface, v21);
      v22 = *pos + 4;
      *pos = v22;
      v24 = *v20;
      *(v24 + 5) = Byte2Float(Interface, v22);
      v25 = *pos + 4;
      *pos = v25;
      v27 = *v20;
      *(v27 + 6) = Byte2Float(Interface, v25);
      v28 = *pos + 4;
      *pos = v28;
      v30 = *v20;
      *(v30 + 7) = Byte2Float(Interface, v28);
      v31 = *pos + 4;
      *pos = v31;
      v33 = *v20;
      *(v33 + 8) = Byte2UInt32(Interface, v31);
      v34 = *pos + 4;
      *pos = v34;
      v36 = *v20;
      *(v36 + 9) = Byte2Float(Interface, v34);
      v37 = *pos + 4;
      *pos = v37;
      v39 = *v20;
      *(v39 + 10) = Byte2Float(Interface, v37);
      v40 = *pos + 4;
      *pos = v40;
      v42 = *v20;
      *(v42 + 11) = Byte2Float(Interface, v40);
      v43 = *pos + 4;
      *pos = v43;
      v45 = *v20;
      *(v45 + 12) = Byte2UInt32(Interface, v43);
      v46 = *pos + 4;
      *pos = v46;
      v48 = *v20;
      *(v48 + 13) = Byte2UInt32(Interface, v46);
      v49 = *pos + 4;
      *pos = v49;
      v51 = *v20;
      *(v51 + 14) = Byte2UInt32(Interface, v49);
      v52 = *pos + 4;
      *pos = v52;
      v54 = *v20;
      *(v54 + 15) = Byte2UInt32(Interface, v52);
      v55 = *pos + 4;
      *pos = v55;
      v57 = *v20;
      *(v57 + 16) = Byte2UInt32(Interface, v55);
      v58 = *pos + 4;
      *pos = v58;
      v60 = *v20;
      *(v60 + 17) = Byte2Float(Interface, v58);
      v61 = *pos + 4;
      *pos = v61;
      v63 = *v20;
      *(v63 + 18) = Byte2UInt32(Interface, v61);
      v64 = *pos + 4;
      *pos = v64;
      v66 = *v20;
      *(v66 + 19) = Byte2UInt32(Interface, v64);
      v67 = *pos + 4;
      *pos = v67;
      v69 = *v20;
      *(v69 + 20) = Byte2UInt32(Interface, v67);
      v70 = *pos + 4;
      *pos = v70;
      v72 = *v20;
      *(v72 + 21) = Byte2UInt32(Interface, v70);
      v73 = *pos + 4;
      *pos = v73;
      v75 = *v20;
      *(v75 + 22) = Byte2UInt32(Interface, v73);
      v76 = *pos + 4;
      *pos = v76;
      v78 = *v20;
      *(v78 + 23) = Byte2UInt32(Interface, v76);
      ++v14;
      *pos += 4;
    }
    while (v8 != v14);
  }
  return v9;
}

// 0x19e0760
effPCPBlurExpParam_t **effPCPBlurExpParam_t__pCopy(effPCPBlurExpParam_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  u32 *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u32 *v14;
  u64 v15;
  u64 *v16;
  s32 v18;
  s32 v21;
  s64 v23;
  s32 v24;
  s64 v26;
  s64 v28;
  u64 *v29;
  u64 v34[3];

  v8 = max;
  v9 = NewSpecific(effPCPBlurExpParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v34);
      if ((v34[0] & 1) != 0)
        v12 = v34[2];
      else
        v12 = v34 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = v9 + 8;
    v15 = 0;
    do
    {
      v16 = Allocate(effPCPBlurExpParam_t);
      _ctor(v16, 0);
      *&v14[2 * v15] = v16;
      v18 = *pos;
      *(v16 + 4) = Byte2UInt32(Interface, v18);
      v21 = *pos + 4;
      *pos = v21;
      v23 = *&v14[2 * v15];
      *(v23 + 20) = Byte2UInt32(Interface, v21);
      v24 = *pos + 4;
      *pos = v24;
      v26 = *&v14[2 * v15];
      *(v26 + 24) = Byte2UInt32(Interface, v24);
      *pos += 4;
      v28 = *&v14[2 * v15];
      v29 = Allocate(dds3Effect_Blur_t);
      _ctor(v29, 0);
      dds3Effect_Blur_t__Clear(v29);
      *(v28 + 32) = v29;
      dds3Effect_Blur_t__SetData(*(*&v14[2 * v15++] + 32LL), Interface, pos);
    }
    while (v8 != v15);
  }
  return v9;
}

// 0x19e0c80
effPCPBossBaelParam_t **effPCPBossBaelParam_t__pCopy(effPCPBossBaelParam_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  u32 *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u32 *v14;
  u64 v15;
  Il2CppObject *v18;
  s64 v21;
  s32 v22;
  s32 v23;
  s64 v25;
  s32 v26;
  s64 v28;
  s32 v29;
  s64 v31;
  u64 v33[3];

  v8 = max;
  v9 = NewSpecific(effPCPBossBaelParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v33);
      if ((v33[0] & 1) != 0)
        v12 = v33[2];
      else
        v12 = v33 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = v9 + 8;
    v15 = 0;
    do
    {
      v18 = Allocate(effPCPBossBaelParam_t);
      _ctor(v18, 0);
      *&v14[2 * v15] = v18;
      v18[1].klass = 0;
      v18[1].monitor = 0;
      v21 = *&v14[2 * v15];
      v22 = *pos;
      *(v21 + 16) = Byte2Float(Interface, v22);
      v23 = *pos + 4;
      *pos = v23;
      v25 = *&v14[2 * v15];
      *(v25 + 20) = Byte2Float(Interface, v23);
      v26 = *pos + 4;
      *pos = v26;
      v28 = *&v14[2 * v15];
      *(v28 + 24) = Byte2Float(Interface, v26);
      v29 = *pos + 4;
      *pos = v29;
      v31 = *&v14[2 * v15];
      *(v31 + 28) = Byte2Float(Interface, v29);
      ++v15;
      *pos += 4;
    }
    while (v8 != v15);
  }
  return v9;
}

// 0x19e0fc0
effPCPBossDengekiParam_t **effPCPBossDengekiParam_t__pCopy(effPCPBossDengekiParam_t *this, void *pData, s32 *pos, s32 max) {
  u32 *v8;
  Il2CppClass *v9;
  System_Byte_array *Interface;
  char *v11;
  s64 *v12;
  u64 v13;
  u32 *v14;
  u64 *v16;
  u64 *v18;
  s64 v20;
  s64 v23;
  s32 v24;
  u64 v26[3];

  v8 = NewSpecific(effPCPBossDengekiParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v9, v26);
      if ((v26[0] & 1) != 0)
        v11 = v26[2];
      else
        v11 = v26 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v13 = 0;
    v14 = v8 + 8;
    do
    {
      v16 = Allocate(effPCPBossDengekiParam_t);
      _ctor(v16, 0);
      *&v14[2 * v13] = v16;
      v18 = Allocate(effPCP_ThunderPolyParam_t);
      effPCP_ThunderPolyParam_t___ctor(v18);
      v20 = *&v14[2 * v13];
      *(v20 + 16) = effPCP_ThunderPolyParam_t__pCopy(v18, &Interface->obj, pos, max);
      v23 = *&v14[2 * v13];
      v24 = *pos;
      *(v23 + 24) = Byte2Float(Interface, v24);
      ++v13;
      *pos += 4;
    }
    while (max != v13);
  }
  return v8;
}

// 0x19e1250
effPCPBossKAGU2AttackParam_t **effPCPBossKAGU2AttackParam_t__pCopy(effPCPBossKAGU2AttackParam_t *this, void *pData, s32 *pos, s32 max) {
  u32 *v8;
  Il2CppClass *v9;
  System_Byte_array *Interface;
  char *v11;
  s64 *v12;
  u64 v13;
  u32 *v14;
  u64 *v16;
  u64 *v18;
  s64 v20;
  s64 v23;
  s32 v24;
  s32 v25;
  s64 v27;
  s32 v28;
  s64 v30;
  s32 v31;
  s64 v33;
  s32 v34;
  s64 v36;
  s32 v37;
  s64 v39;
  u64 v41[3];

  v8 = NewSpecific(effPCPBossKAGU2AttackParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v9, v41);
      if ((v41[0] & 1) != 0)
        v11 = v41[2];
      else
        v11 = v41 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v13 = 0;
    v14 = v8 + 8;
    do
    {
      v16 = Allocate(effPCPBossKAGU2AttackParam_t);
      _ctor(v16, 0);
      *&v14[2 * v13] = v16;
      v18 = Allocate(effPCP_ThunderPolyParam_t);
      effPCP_ThunderPolyParam_t___ctor(v18);
      v20 = *&v14[2 * v13];
      *(v20 + 16) = effPCP_ThunderPolyParam_t__pCopy(v18, &Interface->obj, pos, max);
      v23 = *&v14[2 * v13];
      v24 = *pos;
      *(v23 + 24) = Byte2Float(Interface, v24);
      v25 = *pos + 4;
      *pos = v25;
      v27 = *&v14[2 * v13];
      *(v27 + 28) = Byte2UInt32(Interface, v25);
      v28 = *pos + 4;
      *pos = v28;
      v30 = *&v14[2 * v13];
      *(v30 + 32) = Byte2UInt32(Interface, v28);
      v31 = *pos + 4;
      *pos = v31;
      v33 = *&v14[2 * v13];
      *(v33 + 36) = Byte2UInt32(Interface, v31);
      v34 = *pos + 4;
      *pos = v34;
      v36 = *&v14[2 * v13];
      *(v36 + 40) = Byte2UInt32(Interface, v34);
      v37 = *pos + 4;
      *pos = v37;
      v39 = *&v14[2 * v13];
      *(v39 + 44) = Byte2Float(Interface, v37);
      ++v13;
      *pos += 4;
    }
    while (max != v13);
  }
  return v8;
}

// 0x19e1690
effPCPBossKAGUAttackParam_t **effPCPBossKAGUAttackParam_t__pCopy(effPCPBossKAGUAttackParam_t *this, void *pData, s32 *pos, s32 max) {
  u32 *v8;
  Il2CppClass *v9;
  System_Byte_array *Interface;
  char *v11;
  s64 *v12;
  u64 v13;
  u32 *v14;
  u64 *v16;
  u64 *v18;
  s64 v20;
  s64 v23;
  s32 v24;
  s32 v25;
  s64 v27;
  s32 v28;
  s64 v30;
  s32 v31;
  s64 v33;
  s32 v34;
  s64 v36;
  s32 v37;
  s64 v39;
  u64 v41[3];

  v8 = NewSpecific(effPCPBossKAGUAttackParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v9, v41);
      if ((v41[0] & 1) != 0)
        v11 = v41[2];
      else
        v11 = v41 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v13 = 0;
    v14 = v8 + 8;
    do
    {
      v16 = Allocate(effPCPBossKAGUAttackParam_t);
      _ctor(v16, 0);
      *&v14[2 * v13] = v16;
      v18 = Allocate(effPCP_ThunderPolyParam_t);
      effPCP_ThunderPolyParam_t___ctor(v18);
      v20 = *&v14[2 * v13];
      *(v20 + 16) = effPCP_ThunderPolyParam_t__pCopy(v18, &Interface->obj, pos, max);
      v23 = *&v14[2 * v13];
      v24 = *pos;
      *(v23 + 24) = Byte2Float(Interface, v24);
      v25 = *pos + 4;
      *pos = v25;
      v27 = *&v14[2 * v13];
      *(v27 + 28) = Byte2UInt32(Interface, v25);
      v28 = *pos + 4;
      *pos = v28;
      v30 = *&v14[2 * v13];
      *(v30 + 32) = Byte2UInt32(Interface, v28);
      v31 = *pos + 4;
      *pos = v31;
      v33 = *&v14[2 * v13];
      *(v33 + 36) = Byte2UInt32(Interface, v31);
      v34 = *pos + 4;
      *pos = v34;
      v36 = *&v14[2 * v13];
      *(v36 + 40) = Byte2UInt32(Interface, v34);
      v37 = *pos + 4;
      *pos = v37;
      v39 = *&v14[2 * v13];
      *(v39 + 44) = Byte2Float(Interface, v37);
      ++v13;
      *pos += 4;
    }
    while (max != v13);
  }
  return v8;
}

// 0x19e1ab0
effPCPBossKAGUInvokeParam_t **effPCPBossKAGUInvokeParam_t__pCopy(effPCPBossKAGUInvokeParam_t *this, void *pData, s32 *pos, s32 max) {
  u32 *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  u64 v12;
  Il2CppObject *v14;
  u32 *v16;
  u32 *v17;
  u64 v18;
  u32 *v21;
  s64 *v22;
  s64 *v24;
  s64 v26;
  u64 v27;
  s64 v29;
  s64 v31;
  s64 v33;
  s64 v35;
  s64 v37;
  s32 v38;
  s64 v39;
  f32 v40;
  s64 v43;
  s64 v45;
  f32 v46;
  s64 v49;
  s64 v51;
  f32 v52;
  s64 v55;
  s64 v57;
  f32 v58;
  s64 v60;
  u64 *v61;
  s64 v63;
  s64 v66;
  s32 v67;
  s32 v68;
  s64 v70;
  s32 v71;
  s64 v73;
  s32 v74;
  s64 v76;
  s64 v78;
  u64 v79[3];
  s32 maxa;

  maxa = max;
  v78 = maxa;
  v7 = NewSpecific(effPCPBossKAGUInvokeParam_t, maxa);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v8, v79);
      if ((v79[0] & 1) != 0)
        v10 = v79[2];
      else
        v10 = v79 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  if (maxa >= 1)
  {
    v12 = 0;
    do
    {
      v14 = Allocate(effPCPBossKAGUInvokeParam_t);
      _ctor(v14, 0);
      v16 = &v7[2 * v12];
      *(v16 + 4) = v14;
      v17 = v16 + 8;
      v18 = 0;
      v14[1].klass = NewSpecific(UnityEngine_Vector4__, 6u);
      do
      {
        v21 = *(*v17 + 16LL);
        v22 = NewSpecific(UnityEngine_Vector4, 9u);
        v24 = v22;
        v26 = 0;
        v27 = 0;
        *&v21[2 * v18 + 8] = v24;
        do
        {
          v29 = *(*v17 + 16LL);
          v31 = *(v29 + 8 * v18 + 32);
          v33 = v31 + v26;
          *(v33 + 32) = 0;
          *(v33 + 40) = 0;
          v35 = *(*v17 + 16LL);
          v37 = v35 + 8 * v18;
          v38 = *pos;
          v39 = *(v37 + 32);
          v40 = Byte2Float(Interface, v38);
          *(v39 + v26 + 32) = v40;
          *pos += 4;
          v43 = *(*v17 + 16LL);
          v45 = *(v43 + 8 * v18 + 32);
          v46 = Byte2Float(Interface, *pos);
          *(v45 + v26 + 36) = v46;
          *pos += 4;
          v49 = *(*v17 + 16LL);
          v51 = *(v49 + 8 * v18 + 32);
          v52 = Byte2Float(Interface, *pos);
          *(v51 + v26 + 40) = v52;
          *pos += 4;
          v55 = *(*v17 + 16LL);
          v57 = *(v55 + 8 * v18 + 32);
          v58 = Byte2Float(Interface, *pos);
          v60 = v57 + v26;
          v26 += 16;
          *(v60 + 44) = v58;
          ++v27;
          *pos += 4;
        }
        while (v27 != 9);
        ++v18;
      }
      while (v18 != 6);
      v61 = Allocate(effPCP_ThunderPolyParam_t);
      effPCP_ThunderPolyParam_t___ctor(v61);
      v63 = *v17;
      *(v63 + 24) = effPCP_ThunderPolyParam_t__pCopy(v61, Interface, pos, maxa);
      v66 = *v17;
      v67 = *pos;
      *(v66 + 32) = Byte2UInt32(Interface, v67);
      v68 = *pos + 4;
      *pos = v68;
      v70 = *v17;
      *(v70 + 36) = Byte2UInt32(Interface, v68);
      v71 = *pos + 4;
      *pos = v71;
      v73 = *v17;
      *(v73 + 40) = Byte2UInt32(Interface, v71);
      v74 = *pos + 4;
      *pos = v74;
      v76 = *v17;
      *(v76 + 44) = Byte2UInt32(Interface, v74);
      *pos += 4;
      ++v12;
    }
    while (v12 != v78);
  }
  return v7;
}

// 0x19e2240
effPCPBossKAGUThunderboltParam_t **effPCPBossKAGUThunderboltParam_t__pCopy(effPCPBossKAGUThunderboltParam_t *this, void *pData, s32 *pos, s32 max) {
  u32 *v8;
  Il2CppClass *v9;
  s64 *Interface;
  char *v11;
  s64 *v12;
  u64 v13;
  u32 *v14;
  Il2CppObject *v17;
  s64 v20;
  s32 v21;
  s32 v22;
  s64 v24;
  s32 v25;
  s64 v27;
  s32 v28;
  s64 v30;
  u64 *v31;
  s64 v33;
  u64 *v34;
  s64 v36;
  effPCPCrackParam_t_array *v37;
  s64 v40;
  s32 v41;
  s64 v43;
  s32 v44;
  s64 v46;
  s32 v47;
  s64 v49;
  u64 v51[3];

  v8 = NewSpecific(effPCPBossKAGUThunderboltParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v9, v51);
      if ((v51[0] & 1) != 0)
        v11 = v51[2];
      else
        v11 = v51 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v13 = 0;
    v14 = v8 + 8;
    do
    {
      v17 = Allocate(effPCPBossKAGUThunderboltParam_t);
      _ctor(v17, 0);
      *&v14[2 * v13] = v17;
      v17[1].klass = 0;
      v17[1].monitor = 0;
      v20 = *&v14[2 * v13];
      v21 = *pos;
      *(v20 + 16) = Byte2Float(Interface, v21);
      v22 = *pos + 4;
      *pos = v22;
      v24 = *&v14[2 * v13];
      *(v24 + 20) = Byte2Float(Interface, v22);
      v25 = *pos + 4;
      *pos = v25;
      v27 = *&v14[2 * v13];
      *(v27 + 24) = Byte2Float(Interface, v25);
      v28 = *pos + 4;
      *pos = v28;
      v30 = *&v14[2 * v13];
      *(v30 + 28) = Byte2Float(Interface, v28);
      *pos += 4;
      v31 = Allocate(effPCP_ThunderPolyParam_t);
      effPCP_ThunderPolyParam_t___ctor(v31);
      v33 = *&v14[2 * v13];
      *(v33 + 32) = effPCP_ThunderPolyParam_t__pCopy(v31, Interface, pos, max);
      v34 = Allocate(effPCPCrackParam_t);
      effPCPCrackParam_t___ctor(v34);
      v36 = *&v14[2 * v13];
      v37 = effPCPCrackParam_t__pCopy(v34, Interface, pos, max);
      *(v36 + 40) = v37->m_Items[0];
      v40 = *&v14[2 * v13];
      *(v40 + 48) = Byte2Float(Interface, *pos);
      v41 = *pos + 4;
      *pos = v41;
      v43 = *&v14[2 * v13];
      *(v43 + 52) = Byte2UInt32(Interface, v41);
      v44 = *pos + 4;
      *pos = v44;
      v46 = *&v14[2 * v13];
      *(v46 + 56) = Byte2UInt32(Interface, v44);
      v47 = *pos + 4;
      *pos = v47;
      v49 = *&v14[2 * v13];
      *(v49 + 60) = Byte2UInt32(Interface, v47);
      ++v13;
      *pos += 4;
    }
    while (max != v13);
  }
  return v8;
}

// 0x19e2750
effPCPBossMETATOBeamParam_t **effPCPBossMETATOBeamParam_t__pCopy(effPCPBossMETATOBeamParam_t *this, void *pData, s32 *pos, s32 max) {
  u32 *v8;
  Il2CppClass *v9;
  s64 *Interface;
  char *v11;
  s64 *v12;
  u64 v13;
  u32 *v14;
  Il2CppObject *v17;
  s64 v20;
  s32 v21;
  s32 v22;
  s64 v24;
  s32 v25;
  s64 v27;
  s32 v28;
  s64 v30;
  u64 *v31;
  s64 v33;
  s64 v35;
  s32 v36;
  s64 v38;
  s32 v39;
  s64 v41;
  u64 v43[3];

  v8 = NewSpecific(effPCPBossMETATOBeamParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v9, v43);
      if ((v43[0] & 1) != 0)
        v11 = v43[2];
      else
        v11 = v43 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v13 = 0;
    v14 = v8 + 8;
    do
    {
      v17 = Allocate(effPCPBossMETATOBeamParam_t);
      _ctor(v17, 0);
      *&v14[2 * v13] = v17;
      v17[1].klass = 0;
      v17[1].monitor = 0;
      v20 = *&v14[2 * v13];
      v21 = *pos;
      *(v20 + 16) = Byte2Float(Interface, v21);
      v22 = *pos + 4;
      *pos = v22;
      v24 = *&v14[2 * v13];
      *(v24 + 20) = Byte2Float(Interface, v22);
      v25 = *pos + 4;
      *pos = v25;
      v27 = *&v14[2 * v13];
      *(v27 + 24) = Byte2Float(Interface, v25);
      v28 = *pos + 4;
      *pos = v28;
      v30 = *&v14[2 * v13];
      *(v30 + 28) = Byte2Float(Interface, v28);
      *pos += 4;
      v31 = Allocate(effPCP_ThunderPolyParam_t);
      effPCP_ThunderPolyParam_t___ctor(v31);
      v33 = *&v14[2 * v13];
      *(v33 + 32) = effPCP_ThunderPolyParam_t__pCopy(v31, Interface, pos, max);
      v35 = *&v14[2 * v13];
      *(v35 + 40) = Byte2UInt32(Interface, *pos);
      v36 = *pos + 4;
      *pos = v36;
      v38 = *&v14[2 * v13];
      *(v38 + 44) = Byte2UInt32(Interface, v36);
      v39 = *pos + 4;
      *pos = v39;
      v41 = *&v14[2 * v13];
      *(v41 + 48) = Byte2UInt32(Interface, v39);
      ++v13;
      *pos += 4;
    }
    while (max != v13);
  }
  return v8;
}

// 0x1a37c90
effPCPBossThunderboltParam_t **effPCPBossThunderboltParam_t__pCopy(effPCPBossThunderboltParam_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  u32 *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u32 *v14;
  u64 v15;
  Il2CppObject *v18;
  s64 v21;
  s32 v22;
  s32 v23;
  s64 v25;
  s32 v26;
  s64 v28;
  s32 v29;
  s64 v31;
  u64 *v32;
  effPCP_ThunderPolyParam_t_o *v33;
  s32 v34;
  s64 v37;
  u64 v39[3];

  v8 = max;
  v9 = NewSpecific(effPCPBossThunderboltParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v39);
      if ((v39[0] & 1) != 0)
        v12 = v39[2];
      else
        v12 = v39 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = v9 + 8;
    v15 = 0;
    do
    {
      v18 = Allocate(effPCPBossThunderboltParam_t);
      _ctor(v18, 0);
      *&v14[2 * v15] = v18;
      v18[1].klass = 0;
      v18[1].monitor = 0;
      v21 = *&v14[2 * v15];
      v22 = *pos;
      *(v21 + 16) = Byte2Float(Interface, v22);
      v23 = *pos + 4;
      *pos = v23;
      v25 = *&v14[2 * v15];
      *(v25 + 20) = Byte2Float(Interface, v23);
      v26 = *pos + 4;
      *pos = v26;
      v28 = *&v14[2 * v15];
      *(v28 + 24) = Byte2Float(Interface, v26);
      v29 = *pos + 4;
      *pos = v29;
      v31 = *&v14[2 * v15];
      *(v31 + 28) = Byte2Float(Interface, v29);
      *pos += 4;
      v32 = Allocate(effPCP_ThunderPolyParam_t);
      _ctor(v32, 0);
      v37 = *&v14[2 * v15++];
      *(v37 + 32) = effPCP_ThunderPolyParam_t__pCopy(v33, Interface, pos, v34);
    }
    while (v8 != v15);
  }
  return v9;
}

// 0x1a38550
effPCPBreathParam_t **effPCPBreathParam_t__pCopy(effPCPBreathParam_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  u32 *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u32 *v14;
  u64 v15;
  u64 *v16;
  s32 v18;
  s32 v21;
  s64 v23;
  s32 v24;
  s64 v26;
  s32 v27;
  s64 v29;
  s32 v30;
  s64 v32;
  s32 v33;
  s64 v35;
  s32 v36;
  s64 v38;
  s32 v39;
  s64 v41;
  s32 v42;
  s64 v44;
  u64 v46[3];

  v8 = max;
  v9 = NewSpecific(effPCPBreathParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v46);
      if ((v46[0] & 1) != 0)
        v12 = v46[2];
      else
        v12 = v46 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = v9 + 8;
    v15 = 0;
    do
    {
      v16 = Allocate(effPCPBreathParam_t);
      _ctor(v16, 0);
      *&v14[2 * v15] = v16;
      v18 = *pos;
      *(v16 + 4) = Byte2Float(Interface, v18);
      v21 = *pos + 4;
      *pos = v21;
      v23 = *&v14[2 * v15];
      *(v23 + 20) = Byte2Float(Interface, v21);
      v24 = *pos + 4;
      *pos = v24;
      v26 = *&v14[2 * v15];
      *(v26 + 24) = Byte2Float(Interface, v24);
      v27 = *pos + 4;
      *pos = v27;
      v29 = *&v14[2 * v15];
      *(v29 + 28) = Byte2Float(Interface, v27);
      v30 = *pos + 4;
      *pos = v30;
      v32 = *&v14[2 * v15];
      *(v32 + 32) = Byte2UInt32(Interface, v30);
      v33 = *pos + 4;
      *pos = v33;
      v35 = *&v14[2 * v15];
      *(v35 + 36) = Byte2UInt32(Interface, v33);
      v36 = *pos + 4;
      *pos = v36;
      v38 = *&v14[2 * v15];
      *(v38 + 40) = Byte2UInt32(Interface, v36);
      v39 = *pos + 4;
      *pos = v39;
      v41 = *&v14[2 * v15];
      *(v41 + 44) = Byte2Float(Interface, v39);
      v42 = *pos + 4;
      *pos = v42;
      v44 = *&v14[2 * v15];
      *(v44 + 48) = Byte2Float(Interface, v42);
      ++v15;
      *pos += 4;
    }
    while (v8 != v15);
  }
  return v9;
}

// 0x1a38990
effPCPCrack2Param_t **effPCPCrack2Param_t__pCopy(effPCPCrack2Param_t *this, void *pData, s32 *pos, s32 max) {
  u32 *v8;
  Il2CppClass *v9;
  System_Byte_array *Interface;
  char *v11;
  s64 *v12;
  u64 v13;
  u32 *v14;
  u64 *v16;
  u64 *v18;
  effPCPCrackParam_t_o *v19;
  s64 v22;
  effPCPCrackParam_t_array *v23;
  s64 v27;
  s32 v28;
  s32 v29;
  s64 v31;
  u64 v33[3];

  v8 = NewSpecific(effPCPCrack2Param_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v9, v33);
      if ((v33[0] & 1) != 0)
        v11 = v33[2];
      else
        v11 = v33 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v13 = 0;
    v14 = v8 + 8;
    do
    {
      v16 = Allocate(effPCPCrack2Param_t);
      _ctor(v16, 0);
      *&v14[2 * v13] = v16;
      v18 = Allocate(effPCPCrackParam_t);
      _ctor(v18, 0);
      v22 = *&v14[2 * v13];
      v23 = effPCPCrackParam_t__pCopy(v19, &Interface->obj, pos, max);
      *(v22 + 16) = v23->m_Items[0];
      v27 = *&v14[2 * v13];
      v28 = *pos;
      *(v27 + 24) = Byte2UInt32(Interface, v28);
      v29 = *pos + 4;
      *pos = v29;
      v31 = *&v14[2 * v13];
      *(v31 + 28) = Byte2Float(Interface, v29);
      ++v13;
      *pos += 4;
    }
    while (max != v13);
  }
  return v8;
}

// 0x1a39820
void effPCPCrackParam_t__pClone(effPCPCrackParam_t *this, effPCPCrackParam_t **param) {
  f32 x;
  f32 y;
  effPCPCrackParam_t_o *v5;
  f32 z;
  f32 w;
  f32 v10;
  f32 v11;
  s64 v12;
  f32 v13;
  f32 v14;

  x = this->pos.x;
  y = this->pos.y;
  v5 = *param;
  z = this->pos.z;
  w = this->pos.w;
  v12 = 0;
  sub_854690(&v12, x, y, z, w);
  v11 = v13;
  v10 = v14;
  *&v5->pos.x = v12;
  v5->pos.z = v11;
  v5->pos.w = v10;
  (*param)->show = this->show;
  (*param)->speed = this->speed;
  (*param)->scale = this->scale;
  (*param)->width = this->width;
  (*param)->abgr_wait = this->abgr_wait;
  (*param)->abgr_f = this->abgr_f;
  (*param)->abgr_s_in = this->abgr_s_in;
  (*param)->abgr_s_out = this->abgr_s_out;
  (*param)->abgr_e_in = this->abgr_e_in;
  (*param)->abgr_e_out = this->abgr_e_out;
  (*param)->blend = this->blend;
  (*param)->f_show = this->f_show;
  (*param)->f_type = this->f_type;
  (*param)->f_wait = this->f_wait;
  (*param)->f_timing = this->f_timing;
  (*param)->f_life = this->f_life;
  (*param)->f_fade_in = this->f_fade_in;
  (*param)->f_fade_out = this->f_fade_out;
  (*param)->f_scale = this->f_scale;
  (*param)->f_length = this->f_length;
  (*param)->f_length_r = this->f_length_r;
  (*param)->f_width_in = this->f_width_in;
  (*param)->f_width_out = this->f_width_out;
  (*param)->f_width_r = this->f_width_r;
  (*param)->f_abgr_wait = this->f_abgr_wait;
  (*param)->f_abgr_f = this->f_abgr_f;
  (*param)->f_abgr_s_in = this->f_abgr_s_in;
  (*param)->f_abgr_s_out = this->f_abgr_s_out;
  (*param)->f_abgr_e_in = this->f_abgr_e_in;
  (*param)->f_abgr_e_out = this->f_abgr_e_out;
  (*param)->f_blend = this->f_blend;
  (*param)->f_dir = this->f_dir;
}

// 0x1a38c80
effPCPCrackParam_t **effPCPCrackParam_t__pCopy(effPCPCrackParam_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  effPCPCrackParam_t_array *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u64 v14;
  il2cpp_array_size_t *p_max_length;
  Il2CppObject *v18;
  s64 v20;
  s64 v22;
  s32 v23;
  s32 v24;
  s64 v26;
  s32 v27;
  s64 v29;
  s32 v30;
  s64 v32;
  s32 v33;
  s32 v36;
  s64 v38;
  s32 v39;
  s64 v41;
  s32 v42;
  s64 v44;
  s32 v45;
  s64 v47;
  s32 v48;
  s64 v50;
  s32 v51;
  s64 v53;
  s32 v54;
  s64 v56;
  s32 v57;
  s64 v59;
  s32 v60;
  s64 v62;
  s32 v63;
  s64 v65;
  s32 v66;
  s32 v69;
  s32 v72;
  s64 v74;
  s32 v75;
  s64 v77;
  s32 v78;
  s64 v80;
  s32 v81;
  s64 v83;
  s32 v84;
  s64 v86;
  s32 v87;
  s64 v89;
  s32 v90;
  s64 v92;
  s32 v93;
  s64 v95;
  s32 v96;
  s64 v98;
  s32 v99;
  s64 v101;
  s32 v102;
  s64 v104;
  s32 v105;
  s64 v107;
  s32 v108;
  s64 v110;
  s32 v111;
  s64 v113;
  s32 v114;
  s64 v116;
  s32 v117;
  s64 v119;
  s32 v120;
  s64 v122;
  s32 v123;
  s64 v125;
  s32 v126;
  u64 v130[3];

  v8 = max;
  v9 = NewSpecific(effPCPCrackParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v130);
      if ((v130[0] & 1) != 0)
        v12 = v130[2];
      else
        v12 = v130 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = 0;
    p_max_length = &v9->max_length;
    do
    {
      v18 = Allocate(effPCPCrackParam_t);
      _ctor(v18, 0);
      v20 = &v9->m_Items[v14];
      *v20 = v18;
      v18[1].klass = 0;
      v18[1].monitor = 0;
      v22 = *v20;
      v23 = *pos;
      *(v22 + 16) = Byte2Float(Interface, v23);
      v24 = *pos + 4;
      *pos = v24;
      v26 = *v20;
      *(v26 + 20) = Byte2Float(Interface, v24);
      v27 = *pos + 4;
      *pos = v27;
      v29 = *v20;
      *(v29 + 24) = Byte2Float(Interface, v27);
      v30 = *pos + 4;
      *pos = v30;
      v32 = *v20;
      *(v32 + 28) = Byte2Float(Interface, v30);
      v33 = *pos + 4;
      *pos = v33;
      *(*v20 + 32LL) = *(Interface + v33 + 32);
      v36 = *pos + 4;
      *pos = v36;
      v38 = *v20;
      *(v38 + 36) = Byte2Float(Interface, v36);
      v39 = *pos + 4;
      *pos = v39;
      v41 = *v20;
      *(v41 + 40) = Byte2Float(Interface, v39);
      v42 = *pos + 4;
      *pos = v42;
      v44 = *v20;
      *(v44 + 44) = Byte2Float(Interface, v42);
      v45 = *pos + 4;
      *pos = v45;
      v47 = *v20;
      *(v47 + 48) = Byte2UInt32(Interface, v45);
      v48 = *pos + 4;
      *pos = v48;
      v50 = *v20;
      *(v50 + 52) = Byte2UInt32(Interface, v48);
      v51 = *pos + 4;
      *pos = v51;
      v53 = *v20;
      *(v53 + 56) = Byte2UInt32(Interface, v51);
      v54 = *pos + 4;
      *pos = v54;
      v56 = *v20;
      *(v56 + 60) = Byte2UInt32(Interface, v54);
      v57 = *pos + 4;
      *pos = v57;
      v59 = *v20;
      *(v59 + 64) = Byte2UInt32(Interface, v57);
      v60 = *pos + 4;
      *pos = v60;
      v62 = *v20;
      *(v62 + 68) = Byte2UInt32(Interface, v60);
      v63 = *pos + 4;
      *pos = v63;
      v65 = *v20;
      *(v65 + 72) = Byte2UInt32(Interface, v63);
      v66 = *pos + 4;
      *pos = v66;
      *(*v20 + 76LL) = *(Interface + v66 + 32);
      v69 = *pos + 1;
      *pos = v69;
      *(*v20 + 77LL) = *(Interface + v69 + 32);
      v72 = *pos + 3;
      *pos = v72;
      v74 = *v20;
      *(v74 + 80) = Byte2UInt32(Interface, v72);
      v75 = *pos + 4;
      *pos = v75;
      v77 = *v20;
      *(v77 + 84) = Byte2UInt32(Interface, v75);
      v78 = *pos + 4;
      *pos = v78;
      v80 = *v20;
      *(v80 + 88) = Byte2UInt32(Interface, v78);
      v81 = *pos + 4;
      *pos = v81;
      v83 = *v20;
      *(v83 + 92) = Byte2UInt32(Interface, v81);
      v84 = *pos + 4;
      *pos = v84;
      v86 = *v20;
      *(v86 + 96) = Byte2UInt32(Interface, v84);
      v87 = *pos + 4;
      *pos = v87;
      v89 = *v20;
      *(v89 + 100) = Byte2UInt32(Interface, v87);
      v90 = *pos + 4;
      *pos = v90;
      v92 = *v20;
      *(v92 + 104) = Byte2Float(Interface, v90);
      v93 = *pos + 4;
      *pos = v93;
      v95 = *v20;
      *(v95 + 108) = Byte2Float(Interface, v93);
      v96 = *pos + 4;
      *pos = v96;
      v98 = *v20;
      *(v98 + 112) = Byte2Float(Interface, v96);
      v99 = *pos + 4;
      *pos = v99;
      v101 = *v20;
      *(v101 + 116) = Byte2Float(Interface, v99);
      v102 = *pos + 4;
      *pos = v102;
      v104 = *v20;
      *(v104 + 120) = Byte2Float(Interface, v102);
      v105 = *pos + 4;
      *pos = v105;
      v107 = *v20;
      *(v107 + 124) = Byte2UInt32(Interface, v105);
      v108 = *pos + 4;
      *pos = v108;
      v110 = *v20;
      *(v110 + 128) = Byte2UInt32(Interface, v108);
      v111 = *pos + 4;
      *pos = v111;
      v113 = *v20;
      *(v113 + 132) = Byte2UInt32(Interface, v111);
      v114 = *pos + 4;
      *pos = v114;
      v116 = *v20;
      *(v116 + 136) = Byte2UInt32(Interface, v114);
      v117 = *pos + 4;
      *pos = v117;
      v119 = *v20;
      *(v119 + 140) = Byte2UInt32(Interface, v117);
      v120 = *pos + 4;
      *pos = v120;
      v122 = *v20;
      *(v122 + 144) = Byte2UInt32(Interface, v120);
      v123 = *pos + 4;
      *pos = v123;
      v125 = *v20;
      *(v125 + 148) = Byte2UInt32(Interface, v123);
      v126 = *pos + 4;
      *pos = v126;
      *(*v20 + 152LL) = *(Interface + v126 + 32);
      ++v14;
      *pos += 4;
    }
    while (v8 != v14);
  }
  return v9;
}

// 0x1a39d30
void effPCPDANTE_Damage_Param_t__pClone(effPCPDANTE_Damage_Param_t *this, effPCPDANTE_Damage_Param_t **param) {
  u64 *v5;

  v5 = Allocate(effPCPDANTE_Damage_Param_t);
  _ctor(v5, 0);
  *param = v5;
  *(v5 + 4) = this->life;
  (*param)->fade_in = this->fade_in;
  (*param)->fade_out = this->fade_out;
  (*param)->wait = this->wait;
}

// 0x1a39a30
effPCPDANTE_Damage_Param_t **effPCPDANTE_Damage_Param_t__pCopy(effPCPDANTE_Damage_Param_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  u32 *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u32 *v14;
  u64 v15;
  u64 *v16;
  s32 v18;
  s32 v21;
  s64 v23;
  s32 v24;
  s64 v26;
  s32 v27;
  s64 v29;
  u64 v31[3];

  v8 = max;
  v9 = NewSpecific(effPCPDANTE_Damage_Param_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v31);
      if ((v31[0] & 1) != 0)
        v12 = v31[2];
      else
        v12 = v31 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = v9 + 8;
    v15 = 0;
    do
    {
      v16 = Allocate(effPCPDANTE_Damage_Param_t);
      _ctor(v16, 0);
      *&v14[2 * v15] = v16;
      v18 = *pos;
      *(v16 + 4) = Byte2UInt32(Interface, v18);
      v21 = *pos + 4;
      *pos = v21;
      v23 = *&v14[2 * v15];
      *(v23 + 20) = Byte2UInt32(Interface, v21);
      v24 = *pos + 4;
      *pos = v24;
      v26 = *&v14[2 * v15];
      *(v26 + 24) = Byte2UInt32(Interface, v24);
      v27 = *pos + 4;
      *pos = v27;
      v29 = *&v14[2 * v15];
      *(v29 + 28) = Byte2UInt32(Interface, v27);
      ++v15;
      *pos += 4;
    }
    while (v8 != v15);
  }
  return v9;
}

// 0x1a39dd0
effPCPDANTE_ShowTime_Param_t **effPCPDANTE_ShowTime_Param_t__pCopy(effPCPDANTE_ShowTime_Param_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  u32 *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u64 v14;
  u64 *v15;
  s32 v17;
  u64 v21[3];

  v8 = max;
  v9 = NewSpecific(effPCPDANTE_ShowTime_Param_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v21);
      if ((v21[0] & 1) != 0)
        v12 = v21[2];
      else
        v12 = v21 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = 0;
    do
    {
      v15 = Allocate(effPCPDANTE_ShowTime_Param_t);
      _ctor(v15, 0);
      *&v9[2 * v14 + 8] = v15;
      v17 = *pos;
      *(v15 + 4) = Byte2UInt32(Interface, v17);
      ++v14;
      *pos += 4;
    }
    while (v8 != v14);
  }
  return v9;
}

// 0x1a3a340
void effPCPDANTE_Thunder_Param_t__pClone(effPCPDANTE_Thunder_Param_t *this, effPCPDANTE_Thunder_Param_t **param) {
  effPCPDANTE_Thunder_Param_t_o *v5;
  u64 *v6;

  v5 = *param;
  v6 = Allocate(effPCP_ThunderPolyParam_t);
  _ctor(v6, 0);
  v5->tp_param = v6;
  effPCP_ThunderPolyParam_t__pClone(this->tp_param, &(*param)->tp_param);
  (*param)->helper = this->helper;
  (*param)->life = this->life;
  (*param)->fade_in = this->fade_in;
  (*param)->fade_out = this->fade_out;
}

// 0x1a3a010
effPCPDANTE_Thunder_Param_t **effPCPDANTE_Thunder_Param_t__pCopy(effPCPDANTE_Thunder_Param_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  u32 *v9;
  Il2CppClass *v10;
  System_Byte_array *Interface;
  char *v12;
  s64 *v13;
  u32 *v14;
  u64 v15;
  u64 *v17;
  u64 *v19;
  effPCP_ThunderPolyParam_t_o *v20;
  s32 v21;
  s64 v24;
  s64 v27;
  s32 v28;
  s32 v29;
  s64 v31;
  s32 v32;
  s64 v34;
  s32 v35;
  s64 v37;
  u64 v39[3];

  v8 = max;
  v9 = NewSpecific(effPCPDANTE_Thunder_Param_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v39);
      if ((v39[0] & 1) != 0)
        v12 = v39[2];
      else
        v12 = v39 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = v9 + 8;
    v15 = 0;
    do
    {
      v17 = Allocate(effPCPDANTE_Thunder_Param_t);
      _ctor(v17, 0);
      *&v14[2 * v15] = v17;
      v19 = Allocate(effPCP_ThunderPolyParam_t);
      _ctor(v19, 0);
      v24 = *&v14[2 * v15];
      *(v24 + 16) = effPCP_ThunderPolyParam_t__pCopy(v20, &Interface->obj, pos, v21);
      v27 = *&v14[2 * v15];
      v28 = *pos;
      *(v27 + 24) = Byte2UInt32(Interface, v28);
      v29 = *pos + 4;
      *pos = v29;
      v31 = *&v14[2 * v15];
      *(v31 + 28) = Byte2UInt32(Interface, v29);
      v32 = *pos + 4;
      *pos = v32;
      v34 = *&v14[2 * v15];
      *(v34 + 32) = Byte2UInt32(Interface, v32);
      v35 = *pos + 4;
      *pos = v35;
      v37 = *&v14[2 * v15];
      *(v37 + 36) = Byte2UInt32(Interface, v35);
      ++v15;
      *pos += 4;
    }
    while (v8 != v15);
  }
  return v9;
}

// 0x1a3a810
effPCPDistortionBlurExpParam_t **effPCPDistortionBlurExpParam_t__pCopy(effPCPDistortionBlurExpParam_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  u32 *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u32 *v14;
  u64 v15;
  u64 *v18;
  s64 v20;
  s32 v22;
  s64 v24;
  s32 v25;
  s64 v27;
  s32 v28;
  s64 v30;
  s32 v31;
  s64 v33;
  s32 v34;
  s64 v36;
  s64 v38;
  u64 *v39;
  u64 v42[3];

  v8 = max;
  v9 = NewSpecific(effPCPDistortionBlurExpParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v42);
      if ((v42[0] & 1) != 0)
        v12 = v42[2];
      else
        v12 = v42 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = v9 + 8;
    v15 = 0;
    do
    {
      v18 = Allocate(effPCPDistortionBlurExpParam_t);
      _ctor(v18, 0);
      *&v14[2 * v15] = v18;
      v20 = *pos;
      *(v18 + 16) = *(Interface + v20 + 32);
      v22 = *pos + 4;
      *pos = v22;
      v24 = *&v14[2 * v15];
      *(v24 + 20) = Byte2UInt32(Interface, v22);
      v25 = *pos + 4;
      *pos = v25;
      v27 = *&v14[2 * v15];
      *(v27 + 24) = Byte2UInt32(Interface, v25);
      v28 = *pos + 4;
      *pos = v28;
      v30 = *&v14[2 * v15];
      *(v30 + 28) = Byte2UInt32(Interface, v28);
      v31 = *pos + 4;
      *pos = v31;
      v33 = *&v14[2 * v15];
      *(v33 + 32) = Byte2UInt32(Interface, v31);
      v34 = *pos + 4;
      *pos = v34;
      v36 = *&v14[2 * v15];
      *(v36 + 36) = Byte2UInt32(Interface, v34);
      *pos += 4;
      v38 = *&v14[2 * v15];
      v39 = Allocate(dds3Effect_DistortionBlurParam_t);
      dds3Effect_DistortionBlurParam_t___ctor(v39);
      *(v38 + 40) = v39;
      dds3Effect_DistortionBlurParam_t__SetData(*(*&v14[2 * v15++] + 40LL), Interface, pos, 0);
    }
    while (v8 != v15);
  }
  return v9;
}

// 0x1a3ac20
effPCPFLEACHBlurParam_t **effPCPFLEACHBlurParam_t__pCopy(effPCPFLEACHBlurParam_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  u32 *v9;
  Il2CppClass *v10;
  System_Byte_array *Interface;
  char *v12;
  s64 *v13;
  u32 *v14;
  u64 v15;
  u64 *v17;
  u64 *v19;
  s64 v21;
  dds3Effect_PartialMultiBlurParam_t_array *v22;
  u64 *v24;
  s64 v26;
  dds3Effect_PartialMultiBlurParam_t_array *v27;
  s64 v31;
  s32 v32;
  s32 v33;
  s64 v35;
  s32 v36;
  s64 v38;
  u64 v40[3];

  v8 = max;
  v9 = NewSpecific(effPCPFLEACHBlurParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v40);
      if ((v40[0] & 1) != 0)
        v12 = v40[2];
      else
        v12 = v40 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = v9 + 8;
    v15 = 0;
    do
    {
      v17 = Allocate(effPCPFLEACHBlurParam_t);
      _ctor(v17, 0);
      *&v14[2 * v15] = v17;
      v19 = Allocate(dds3Effect_PartialMultiBlurParam_t);
      dds3Effect_PartialMultiBlurParam_t___ctor(v19);
      v21 = *&v14[2 * v15];
      v22 = dds3Effect_PartialMultiBlurParam_t__pCopy(v19, &Interface->obj, pos, 1);
      *(v21 + 16) = v22->m_Items[0];
      v24 = Allocate(dds3Effect_PartialMultiBlurParam_t);
      dds3Effect_PartialMultiBlurParam_t___ctor(v24);
      v26 = *&v14[2 * v15];
      v27 = dds3Effect_PartialMultiBlurParam_t__pCopy(v24, &Interface->obj, pos, 1);
      *(v26 + 24) = v27->m_Items[0];
      v31 = *&v14[2 * v15];
      v32 = *pos;
      *(v31 + 32) = Byte2UInt32(Interface, v32);
      v33 = *pos + 4;
      *pos = v33;
      v35 = *&v14[2 * v15];
      *(v35 + 36) = Byte2UInt32(Interface, v33);
      v36 = *pos + 4;
      *pos = v36;
      v38 = *&v14[2 * v15];
      *(v38 + 40) = Byte2UInt32(Interface, v36);
      ++v15;
      *pos += 4;
    }
    while (v8 != v15);
  }
  return v9;
}

// 0x1a3afb0
effPCPFilterExpParam_t **effPCPFilterExpParam_t__pCopy(effPCPFilterExpParam_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  u32 *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u32 *v14;
  u64 v15;
  u64 *v16;
  s32 v18;
  s32 v21;
  s64 v23;
  s32 v24;
  s64 v26;
  s64 v28;
  u64 *v29;
  u64 v32[3];

  v8 = max;
  v9 = NewSpecific(effPCPFilterExpParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v32);
      if ((v32[0] & 1) != 0)
        v12 = v32[2];
      else
        v12 = v32 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = v9 + 8;
    v15 = 0;
    do
    {
      v16 = Allocate(effPCPFilterExpParam_t);
      _ctor(v16, 0);
      *&v14[2 * v15] = v16;
      v18 = *pos;
      *(v16 + 4) = Byte2UInt32(Interface, v18);
      v21 = *pos + 4;
      *pos = v21;
      v23 = *&v14[2 * v15];
      *(v23 + 20) = Byte2UInt32(Interface, v21);
      v24 = *pos + 4;
      *pos = v24;
      v26 = *&v14[2 * v15];
      *(v26 + 24) = Byte2UInt32(Interface, v24);
      *pos += 4;
      v28 = *&v14[2 * v15];
      v29 = Allocate(dds3Effect_Filter_t);
      dds3Effect_Filter_t___ctor(v29);
      *(v28 + 32) = v29;
      dds3Effect_Filter_t__SetData(*(*&v14[2 * v15++] + 32LL), Interface, pos, 0);
    }
    while (v8 != v15);
  }
  return v9;
}

// 0x1a3b960
void effPCPFlashPolyCircleParam_t__pClone(effPCPFlashPolyCircleParam_t *this, effPCPFlashPolyCircleParam_t **param) {
  f32 x;
  f32 y;
  effPCPFlashPolyCircleParam_t_o *v7;
  f32 z;
  f32 w;
  f32 v11;
  f32 v12;
  effPCPFlashPolyCircleParam_t_o *v13;
  u32 number;
  u32 numberO;
  s64 v16;
  s64 v17;

  x = this->pos.x;
  y = this->pos.y;
  v7 = *param;
  z = this->pos.z;
  w = this->pos.w;
  v16 = 0;
  v17 = 0;
  sub_854690(&v16, x, y, z, w);
  v12 = *&v17;
  v11 = *(&v17 + 1);
  *&v7->pos.x = v16;
  v7->pos.z = v12;
  v7->pos.w = v11;
  (*param)->numberO = this->numberO;
  v13 = *param;
  number = this->number;
  numberO = this->numberO;
  v13->number = CutRaitoGet(number, numberO);
  (*param)->loop = this->loop;
  (*param)->life = this->life;
  (*param)->abgr_s = this->abgr_s;
  (*param)->abgr_e = this->abgr_e;
  (*param)->abgr_in = this->abgr_in;
  (*param)->abgr_out = this->abgr_out;
  (*param)->radius = this->radius;
  (*param)->radius_s = this->radius_s;
  (*param)->radius_a = this->radius_a;
  (*param)->z = this->z;
  (*param)->blend = this->blend;
}

// 0x1a3b2f0
effPCPFlashPolyCircleParam_t **effPCPFlashPolyCircleParam_t__pCopy(effPCPFlashPolyCircleParam_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  u32 *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u32 *v14;
  u64 v15;
  u64 *v16;
  s32 v18;
  s32 v21;
  s64 v23;
  s32 v24;
  s64 v26;
  s32 v27;
  s64 v29;
  s32 v30;
  s64 v32;
  s32 v33;
  s32 v36;
  s64 v38;
  s32 v39;
  s64 v41;
  s32 v42;
  s64 v44;
  s32 v45;
  s64 v47;
  s32 v48;
  s64 v50;
  s32 v51;
  s64 v53;
  s32 v54;
  s64 v56;
  s32 v57;
  s64 v59;
  s32 v60;
  s64 v62;
  s32 v63;
  s64 v65;
  s64 v67;
  u64 v69[3];

  v8 = max;
  v9 = NewSpecific(effPCPFlashPolyCircleParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v69);
      if ((v69[0] & 1) != 0)
        v12 = v69[2];
      else
        v12 = v69 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = v9 + 8;
    v15 = 0;
    do
    {
      v16 = Allocate(effPCPFlashPolyCircleParam_t);
      _ctor(v16, 0);
      *&v14[2 * v15] = v16;
      v18 = *pos;
      *(v16 + 4) = Byte2Float(Interface, v18);
      v21 = *pos + 4;
      *pos = v21;
      v23 = *&v14[2 * v15];
      *(v23 + 20) = Byte2Float(Interface, v21);
      v24 = *pos + 4;
      *pos = v24;
      v26 = *&v14[2 * v15];
      *(v26 + 24) = Byte2Float(Interface, v24);
      v27 = *pos + 4;
      *pos = v27;
      v29 = *&v14[2 * v15];
      *(v29 + 28) = Byte2Float(Interface, v27);
      v30 = *pos + 4;
      *pos = v30;
      v32 = *&v14[2 * v15];
      *(v32 + 32) = Byte2UInt32(Interface, v30);
      v33 = *pos + 4;
      *pos = v33;
      *(*&v14[2 * v15] + 36LL) = *(Interface + v33 + 32);
      v36 = *pos + 4;
      *pos = v36;
      v38 = *&v14[2 * v15];
      *(v38 + 40) = Byte2UInt32(Interface, v36);
      v39 = *pos + 4;
      *pos = v39;
      v41 = *&v14[2 * v15];
      *(v41 + 44) = Byte2UInt32(Interface, v39);
      v42 = *pos + 4;
      *pos = v42;
      v44 = *&v14[2 * v15];
      *(v44 + 48) = Byte2UInt32(Interface, v42);
      v45 = *pos + 4;
      *pos = v45;
      v47 = *&v14[2 * v15];
      *(v47 + 52) = Byte2UInt32(Interface, v45);
      v48 = *pos + 4;
      *pos = v48;
      v50 = *&v14[2 * v15];
      *(v50 + 56) = Byte2UInt32(Interface, v48);
      v51 = *pos + 4;
      *pos = v51;
      v53 = *&v14[2 * v15];
      *(v53 + 60) = Byte2Float(Interface, v51);
      v54 = *pos + 4;
      *pos = v54;
      v56 = *&v14[2 * v15];
      *(v56 + 64) = Byte2Float(Interface, v54);
      v57 = *pos + 4;
      *pos = v57;
      v59 = *&v14[2 * v15];
      *(v59 + 68) = Byte2Float(Interface, v57);
      v60 = *pos + 4;
      *pos = v60;
      v62 = *&v14[2 * v15];
      *(v62 + 72) = Byte2Float(Interface, v60);
      v63 = *pos + 4;
      *pos = v63;
      v65 = *&v14[2 * v15];
      *(v65 + 76) = Byte2UInt32(Interface, v63);
      *pos += 4;
      v67 = *&v14[2 * v15++];
      *(v67 + 80) = *(v67 + 32);
    }
    while (v8 != v15);
  }
  return v9;
}

// 0x1a3c220
void effPCPFlashPolyPipeParam_t__pClone(effPCPFlashPolyPipeParam_t *this, effPCPFlashPolyPipeParam_t **param) {
  f32 x;
  f32 y;
  effPCPFlashPolyPipeParam_t_o *v7;
  f32 z;
  f32 w;
  f32 v11;
  f32 v12;
  effPCPFlashPolyPipeParam_t_o *v13;
  u32 number;
  u32 numberO;
  s64 v16;
  s64 v17;

  x = this->pos.x;
  y = this->pos.y;
  v7 = *param;
  z = this->pos.z;
  w = this->pos.w;
  v16 = 0;
  v17 = 0;
  sub_854690(&v16, x, y, z, w);
  v12 = *&v17;
  v11 = *(&v17 + 1);
  *&v7->pos.x = v16;
  v7->pos.z = v12;
  v7->pos.w = v11;
  (*param)->numberO = this->numberO;
  v13 = *param;
  number = this->number;
  numberO = this->numberO;
  v13->number = CutRaitoGet(number, numberO);
  (*param)->loop = this->loop;
  (*param)->life = this->life;
  (*param)->interval = this->interval;
  (*param)->abgr_s = this->abgr_s;
  (*param)->abgr_e = this->abgr_e;
  (*param)->abgr_in = this->abgr_in;
  (*param)->abgr_out = this->abgr_out;
  (*param)->width_in = this->width_in;
  (*param)->width_out = this->width_out;
  (*param)->radius = this->radius;
  (*param)->length = this->length;
  (*param)->spread = this->spread;
  (*param)->rotate = this->rotate;
  (*param)->up_s = this->up_s;
  (*param)->blend = this->blend;
}

// 0x1a3bac0
effPCPFlashPolyPipeParam_t **effPCPFlashPolyPipeParam_t__pCopy(effPCPFlashPolyPipeParam_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  effPCPFlashPolyPipeParam_t_array *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u64 v14;
  il2cpp_array_size_t *p_max_length;
  u64 *v17;
  s64 v20;
  s32 v21;
  s32 v22;
  s64 v24;
  s32 v25;
  s64 v27;
  s32 v28;
  s64 v30;
  s32 v31;
  s64 v33;
  s32 v34;
  s32 v37;
  s64 v39;
  s32 v40;
  s64 v42;
  s32 v43;
  s64 v45;
  s32 v46;
  s64 v48;
  s32 v49;
  s64 v51;
  s32 v52;
  s64 v54;
  s32 v55;
  s64 v57;
  s32 v58;
  s64 v60;
  s32 v61;
  s64 v63;
  s32 v64;
  s64 v66;
  s32 v67;
  s64 v69;
  s32 v70;
  s64 v72;
  s32 v73;
  s64 v75;
  s32 v76;
  s64 v78;
  u64 v81[3];

  v8 = max;
  v9 = NewSpecific(effPCPFlashPolyPipeParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v81);
      if ((v81[0] & 1) != 0)
        v12 = v81[2];
      else
        v12 = v81 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = 0;
    p_max_length = &v9->max_length;
    do
    {
      v17 = Allocate(effPCPFlashPolyPipeParam_t);
      _ctor(v17, 0);
      v20 = &v9->m_Items[v14];
      *v20 = v17;
      v21 = *pos;
      *(v17 + 4) = Byte2Float(Interface, v21);
      v22 = *pos + 4;
      *pos = v22;
      v24 = *v20;
      *(v24 + 20) = Byte2Float(Interface, v22);
      v25 = *pos + 4;
      *pos = v25;
      v27 = *v20;
      *(v27 + 24) = Byte2Float(Interface, v25);
      v28 = *pos + 4;
      *pos = v28;
      v30 = *v20;
      *(v30 + 28) = Byte2Float(Interface, v28);
      v31 = *pos + 4;
      *pos = v31;
      v33 = *v20;
      *(v33 + 32) = Byte2UInt32(Interface, v31);
      v34 = *pos + 4;
      *pos = v34;
      *(*v20 + 36LL) = *(Interface + v34 + 32);
      v37 = *pos + 4;
      *pos = v37;
      v39 = *v20;
      *(v39 + 40) = Byte2UInt32(Interface, v37);
      v40 = *pos + 4;
      *pos = v40;
      v42 = *v20;
      *(v42 + 44) = Byte2UInt32(Interface, v40);
      v43 = *pos + 4;
      *pos = v43;
      v45 = *v20;
      *(v45 + 48) = Byte2UInt32(Interface, v43);
      v46 = *pos + 4;
      *pos = v46;
      v48 = *v20;
      *(v48 + 52) = Byte2UInt32(Interface, v46);
      v49 = *pos + 4;
      *pos = v49;
      v51 = *v20;
      *(v51 + 56) = Byte2UInt32(Interface, v49);
      v52 = *pos + 4;
      *pos = v52;
      v54 = *v20;
      *(v54 + 60) = Byte2UInt32(Interface, v52);
      v55 = *pos + 4;
      *pos = v55;
      v57 = *v20;
      *(v57 + 64) = Byte2Float(Interface, v55);
      v58 = *pos + 4;
      *pos = v58;
      v60 = *v20;
      *(v60 + 68) = Byte2Float(Interface, v58);
      v61 = *pos + 4;
      *pos = v61;
      v63 = *v20;
      *(v63 + 72) = Byte2Float(Interface, v61);
      v64 = *pos + 4;
      *pos = v64;
      v66 = *v20;
      *(v66 + 76) = Byte2Float(Interface, v64);
      v67 = *pos + 4;
      *pos = v67;
      v69 = *v20;
      *(v69 + 80) = Byte2Float(Interface, v67);
      v70 = *pos + 4;
      *pos = v70;
      v72 = *v20;
      *(v72 + 84) = Byte2Float(Interface, v70);
      v73 = *pos + 4;
      *pos = v73;
      v75 = *v20;
      *(v75 + 88) = Byte2Float(Interface, v73);
      v76 = *pos + 4;
      *pos = v76;
      v78 = *v20;
      *(v78 + 92) = Byte2UInt32(Interface, v76);
      *pos += 4;
      ++v14;
      *(*v20 + 96LL) = *(*v20 + 32LL);
    }
    while (v8 != v14);
  }
  return v9;
}

// 0x1a3cb10
void effPCPFlashPolyRingExp2Param_t__pClone(effPCPFlashPolyRingExp2Param_t *this, effPCPFlashPolyRingExp2Param_t **param) {
  f32 x;
  f32 y;
  effPCPFlashPolyRingExp2Param_t_o *v7;
  f32 z;
  f32 w;
  f32 v11;
  f32 v12;
  effPCPFlashPolyRingExp2Param_t_o *v13;
  u32 number;
  u32 numberO;
  s64 v16;
  s64 v17;

  x = this->pos.x;
  y = this->pos.y;
  v7 = *param;
  z = this->pos.z;
  w = this->pos.w;
  v16 = 0;
  v17 = 0;
  sub_854690(&v16, x, y, z, w);
  v12 = *&v17;
  v11 = *(&v17 + 1);
  *&v7->pos.x = v16;
  v7->pos.z = v12;
  v7->pos.w = v11;
  (*param)->numberO = this->numberO;
  v13 = *param;
  number = this->number;
  numberO = this->numberO;
  v13->number = CutRaitoGet(number, numberO);
  (*param)->loop = this->loop;
  (*param)->life = this->life;
  (*param)->scale_f = this->scale_f;
  (*param)->interval = this->interval;
  (*param)->abgr_s = this->abgr_s;
  (*param)->abgr_e = this->abgr_e;
  (*param)->abgr_in = this->abgr_in;
  (*param)->abgr_out = this->abgr_out;
  (*param)->width_in = this->width_in;
  (*param)->width_out = this->width_out;
  (*param)->radius = this->radius;
  (*param)->length = this->length;
  (*param)->spread = this->spread;
  (*param)->rotate = this->rotate;
  (*param)->blend = this->blend;
}

// 0x1a3c3b0
effPCPFlashPolyRingExp2Param_t **effPCPFlashPolyRingExp2Param_t__pCopy(effPCPFlashPolyRingExp2Param_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  effPCPFlashPolyRingExp2Param_t_array *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u64 v14;
  il2cpp_array_size_t *p_max_length;
  u64 *v17;
  s64 v20;
  s32 v21;
  s32 v22;
  s64 v24;
  s32 v25;
  s64 v27;
  s32 v28;
  s64 v30;
  s32 v31;
  s64 v33;
  s32 v34;
  s32 v37;
  s64 v39;
  s32 v40;
  s64 v42;
  s32 v43;
  s64 v45;
  s32 v46;
  s64 v48;
  s32 v49;
  s64 v51;
  s32 v52;
  s64 v54;
  s32 v55;
  s64 v57;
  s32 v58;
  s64 v60;
  s32 v61;
  s64 v63;
  s32 v64;
  s64 v66;
  s32 v67;
  s64 v69;
  s32 v70;
  s64 v72;
  s32 v73;
  s64 v75;
  s32 v76;
  s64 v78;
  u64 v81[3];

  v8 = max;
  v9 = NewSpecific(effPCPFlashPolyRingExp2Param_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v81);
      if ((v81[0] & 1) != 0)
        v12 = v81[2];
      else
        v12 = v81 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = 0;
    p_max_length = &v9->max_length;
    do
    {
      v17 = Allocate(effPCPFlashPolyRingExp2Param_t);
      _ctor(v17, 0);
      v20 = &v9->m_Items[v14];
      *v20 = v17;
      v21 = *pos;
      *(v17 + 4) = Byte2Float(Interface, v21);
      v22 = *pos + 4;
      *pos = v22;
      v24 = *v20;
      *(v24 + 20) = Byte2Float(Interface, v22);
      v25 = *pos + 4;
      *pos = v25;
      v27 = *v20;
      *(v27 + 24) = Byte2Float(Interface, v25);
      v28 = *pos + 4;
      *pos = v28;
      v30 = *v20;
      *(v30 + 28) = Byte2Float(Interface, v28);
      v31 = *pos + 4;
      *pos = v31;
      v33 = *v20;
      *(v33 + 32) = Byte2UInt32(Interface, v31);
      v34 = *pos + 4;
      *pos = v34;
      *(*v20 + 36LL) = *(Interface + v34 + 32);
      v37 = *pos + 4;
      *pos = v37;
      v39 = *v20;
      *(v39 + 40) = Byte2UInt32(Interface, v37);
      v40 = *pos + 4;
      *pos = v40;
      v42 = *v20;
      *(v42 + 44) = Byte2UInt32(Interface, v40);
      v43 = *pos + 4;
      *pos = v43;
      v45 = *v20;
      *(v45 + 48) = Byte2UInt32(Interface, v43);
      v46 = *pos + 4;
      *pos = v46;
      v48 = *v20;
      *(v48 + 52) = Byte2UInt32(Interface, v46);
      v49 = *pos + 4;
      *pos = v49;
      v51 = *v20;
      *(v51 + 56) = Byte2UInt32(Interface, v49);
      v52 = *pos + 4;
      *pos = v52;
      v54 = *v20;
      *(v54 + 60) = Byte2UInt32(Interface, v52);
      v55 = *pos + 4;
      *pos = v55;
      v57 = *v20;
      *(v57 + 64) = Byte2UInt32(Interface, v55);
      v58 = *pos + 4;
      *pos = v58;
      v60 = *v20;
      *(v60 + 68) = Byte2Float(Interface, v58);
      v61 = *pos + 4;
      *pos = v61;
      v63 = *v20;
      *(v63 + 72) = Byte2Float(Interface, v61);
      v64 = *pos + 4;
      *pos = v64;
      v66 = *v20;
      *(v66 + 76) = Byte2Float(Interface, v64);
      v67 = *pos + 4;
      *pos = v67;
      v69 = *v20;
      *(v69 + 80) = Byte2Float(Interface, v67);
      v70 = *pos + 4;
      *pos = v70;
      v72 = *v20;
      *(v72 + 84) = Byte2Float(Interface, v70);
      v73 = *pos + 4;
      *pos = v73;
      v75 = *v20;
      *(v75 + 88) = Byte2Float(Interface, v73);
      v76 = *pos + 4;
      *pos = v76;
      v78 = *v20;
      *(v78 + 92) = Byte2UInt32(Interface, v76);
      *pos += 4;
      ++v14;
      *(*v20 + 96LL) = *(*v20 + 32LL);
    }
    while (v8 != v14);
  }
  return v9;
}

// 0x1a3d480
void effPCPFlashPolyRingExpParam_t__pClone(effPCPFlashPolyRingExpParam_t *this, effPCPFlashPolyRingExpParam_t **param) {
  f32 x;
  f32 y;
  effPCPFlashPolyRingExpParam_t_o *v7;
  f32 z;
  f32 w;
  f32 v11;
  f32 v12;
  effPCPFlashPolyRingExpParam_t_o *v13;
  u32 number;
  u32 numberO;
  s64 v16;
  s64 v17;

  x = this->pos.x;
  y = this->pos.y;
  v7 = *param;
  z = this->pos.z;
  w = this->pos.w;
  v16 = 0;
  v17 = 0;
  sub_854690(&v16, x, y, z, w);
  v12 = *&v17;
  v11 = *(&v17 + 1);
  *&v7->pos.x = v16;
  v7->pos.z = v12;
  v7->pos.w = v11;
  (*param)->numberO = this->numberO;
  v13 = *param;
  number = this->number;
  numberO = this->numberO;
  v13->number = CutRaitoGet(number, numberO);
  (*param)->loop = this->loop;
  (*param)->life = this->life;
  (*param)->interval = this->interval;
  (*param)->abgr_s = this->abgr_s;
  (*param)->abgr_e = this->abgr_e;
  (*param)->abgr_in = this->abgr_in;
  (*param)->abgr_out = this->abgr_out;
  (*param)->width_in = this->width_in;
  (*param)->width_out = this->width_out;
  (*param)->radius_s = this->radius_s;
  (*param)->radius_e = this->radius_e;
  (*param)->length_s = this->length_s;
  (*param)->length_e = this->length_e;
  (*param)->spread_s = this->spread_s;
  (*param)->spread_e = this->spread_e;
  (*param)->rotate = this->rotate;
  (*param)->blend = this->blend;
}

// 0x1a3cca0
effPCPFlashPolyRingExpParam_t **effPCPFlashPolyRingExpParam_t__pCopy(effPCPFlashPolyRingExpParam_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  effPCPFlashPolyRingExpParam_t_array *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u64 v14;
  il2cpp_array_size_t *p_max_length;
  u64 *v17;
  s64 v20;
  s32 v21;
  s32 v22;
  s64 v24;
  s32 v25;
  s64 v27;
  s32 v28;
  s64 v30;
  s32 v31;
  s64 v33;
  s32 v34;
  s32 v37;
  s64 v39;
  s32 v40;
  s64 v42;
  s32 v43;
  s64 v45;
  s32 v46;
  s64 v48;
  s32 v49;
  s64 v51;
  s32 v52;
  s64 v54;
  s32 v55;
  s64 v57;
  s32 v58;
  s64 v60;
  s32 v61;
  s64 v63;
  s32 v64;
  s64 v66;
  s32 v67;
  s64 v69;
  s32 v70;
  s64 v72;
  s32 v73;
  s64 v75;
  s32 v76;
  s64 v78;
  s32 v79;
  s64 v81;
  s32 v82;
  s64 v84;
  u64 v87[3];

  v8 = max;
  v9 = NewSpecific(effPCPFlashPolyRingExpParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v87);
      if ((v87[0] & 1) != 0)
        v12 = v87[2];
      else
        v12 = v87 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = 0;
    p_max_length = &v9->max_length;
    do
    {
      v17 = Allocate(effPCPFlashPolyRingExpParam_t);
      _ctor(v17, 0);
      v20 = &v9->m_Items[v14];
      *v20 = v17;
      v21 = *pos;
      *(v17 + 4) = Byte2Float(Interface, v21);
      v22 = *pos + 4;
      *pos = v22;
      v24 = *v20;
      *(v24 + 20) = Byte2Float(Interface, v22);
      v25 = *pos + 4;
      *pos = v25;
      v27 = *v20;
      *(v27 + 24) = Byte2Float(Interface, v25);
      v28 = *pos + 4;
      *pos = v28;
      v30 = *v20;
      *(v30 + 28) = Byte2Float(Interface, v28);
      v31 = *pos + 4;
      *pos = v31;
      v33 = *v20;
      *(v33 + 32) = Byte2UInt32(Interface, v31);
      v34 = *pos + 4;
      *pos = v34;
      *(*v20 + 36LL) = *(Interface + v34 + 32);
      v37 = *pos + 4;
      *pos = v37;
      v39 = *v20;
      *(v39 + 40) = Byte2UInt32(Interface, v37);
      v40 = *pos + 4;
      *pos = v40;
      v42 = *v20;
      *(v42 + 44) = Byte2UInt32(Interface, v40);
      v43 = *pos + 4;
      *pos = v43;
      v45 = *v20;
      *(v45 + 48) = Byte2UInt32(Interface, v43);
      v46 = *pos + 4;
      *pos = v46;
      v48 = *v20;
      *(v48 + 52) = Byte2UInt32(Interface, v46);
      v49 = *pos + 4;
      *pos = v49;
      v51 = *v20;
      *(v51 + 56) = Byte2UInt32(Interface, v49);
      v52 = *pos + 4;
      *pos = v52;
      v54 = *v20;
      *(v54 + 60) = Byte2UInt32(Interface, v52);
      v55 = *pos + 4;
      *pos = v55;
      v57 = *v20;
      *(v57 + 64) = Byte2Float(Interface, v55);
      v58 = *pos + 4;
      *pos = v58;
      v60 = *v20;
      *(v60 + 68) = Byte2Float(Interface, v58);
      v61 = *pos + 4;
      *pos = v61;
      v63 = *v20;
      *(v63 + 72) = Byte2Float(Interface, v61);
      v64 = *pos + 4;
      *pos = v64;
      v66 = *v20;
      *(v66 + 76) = Byte2Float(Interface, v64);
      v67 = *pos + 4;
      *pos = v67;
      v69 = *v20;
      *(v69 + 80) = Byte2Float(Interface, v67);
      v70 = *pos + 4;
      *pos = v70;
      v72 = *v20;
      *(v72 + 84) = Byte2Float(Interface, v70);
      v73 = *pos + 4;
      *pos = v73;
      v75 = *v20;
      *(v75 + 88) = Byte2Float(Interface, v73);
      v76 = *pos + 4;
      *pos = v76;
      v78 = *v20;
      *(v78 + 92) = Byte2Float(Interface, v76);
      v79 = *pos + 4;
      *pos = v79;
      v81 = *v20;
      *(v81 + 96) = Byte2Float(Interface, v79);
      v82 = *pos + 4;
      *pos = v82;
      v84 = *v20;
      *(v84 + 100) = Byte2UInt32(Interface, v82);
      *pos += 4;
      ++v14;
      *(*v20 + 104LL) = *(*v20 + 32LL);
    }
    while (v8 != v14);
  }
  return v9;
}

// 0x1a3dd00
void effPCPFlashPolyRingParam_t__pClone(effPCPFlashPolyRingParam_t *this, effPCPFlashPolyRingParam_t **param) {
  f32 x;
  f32 y;
  effPCPFlashPolyRingParam_t_o *v7;
  f32 z;
  f32 w;
  f32 v11;
  f32 v12;
  effPCPFlashPolyRingParam_t_o *v13;
  u32 number;
  u32 numberO;
  s64 v16;
  s64 v17;

  x = this->pos.x;
  y = this->pos.y;
  v7 = *param;
  z = this->pos.z;
  w = this->pos.w;
  v16 = 0;
  v17 = 0;
  sub_854690(&v16, x, y, z, w);
  v12 = *&v17;
  v11 = *(&v17 + 1);
  *&v7->pos.x = v16;
  v7->pos.z = v12;
  v7->pos.w = v11;
  (*param)->numberO = this->numberO;
  v13 = *param;
  number = this->number;
  numberO = this->numberO;
  v13->number = CutRaitoGet(number, numberO);
  (*param)->loop = this->loop;
  (*param)->life = this->life;
  (*param)->scale_f = this->scale_f;
  (*param)->interval = this->interval;
  (*param)->abgr_in = this->abgr_in;
  (*param)->abgr_out = this->abgr_out;
  (*param)->width_in = this->width_in;
  (*param)->width_out = this->width_out;
  (*param)->radius = this->radius;
  (*param)->length = this->length;
  (*param)->spread = this->spread;
  (*param)->rotate = this->rotate;
  (*param)->blend = this->blend;
}

// 0x1a3d620
effPCPFlashPolyRingParam_t **effPCPFlashPolyRingParam_t__pCopy(effPCPFlashPolyRingParam_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  effPCPFlashPolyRingParam_t_array *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u64 v14;
  il2cpp_array_size_t *p_max_length;
  u64 *v17;
  s64 v20;
  s32 v21;
  s32 v22;
  s64 v24;
  s32 v25;
  s64 v27;
  s32 v28;
  s64 v30;
  s32 v31;
  s64 v33;
  s32 v34;
  s32 v37;
  s64 v39;
  s32 v40;
  s64 v42;
  s32 v43;
  s64 v45;
  s32 v46;
  s64 v48;
  s32 v49;
  s64 v51;
  s32 v52;
  s64 v54;
  s32 v55;
  s64 v57;
  s32 v58;
  s64 v60;
  s32 v61;
  s64 v63;
  s32 v64;
  s64 v66;
  s32 v67;
  s64 v69;
  s32 v70;
  s64 v72;
  u64 v75[3];

  v8 = max;
  v9 = NewSpecific(effPCPFlashPolyRingParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v75);
      if ((v75[0] & 1) != 0)
        v12 = v75[2];
      else
        v12 = v75 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = 0;
    p_max_length = &v9->max_length;
    do
    {
      v17 = Allocate(effPCPFlashPolyRingParam_t);
      _ctor(v17, 0);
      v20 = &v9->m_Items[v14];
      *v20 = v17;
      v21 = *pos;
      *(v17 + 4) = Byte2Float(Interface, v21);
      v22 = *pos + 4;
      *pos = v22;
      v24 = *v20;
      *(v24 + 20) = Byte2Float(Interface, v22);
      v25 = *pos + 4;
      *pos = v25;
      v27 = *v20;
      *(v27 + 24) = Byte2Float(Interface, v25);
      v28 = *pos + 4;
      *pos = v28;
      v30 = *v20;
      *(v30 + 28) = Byte2Float(Interface, v28);
      v31 = *pos + 4;
      *pos = v31;
      v33 = *v20;
      *(v33 + 32) = Byte2UInt32(Interface, v31);
      v34 = *pos + 4;
      *pos = v34;
      *(*v20 + 36LL) = *(Interface + v34 + 32);
      v37 = *pos + 4;
      *pos = v37;
      v39 = *v20;
      *(v39 + 40) = Byte2UInt32(Interface, v37);
      v40 = *pos + 4;
      *pos = v40;
      v42 = *v20;
      *(v42 + 44) = Byte2UInt32(Interface, v40);
      v43 = *pos + 4;
      *pos = v43;
      v45 = *v20;
      *(v45 + 48) = Byte2UInt32(Interface, v43);
      v46 = *pos + 4;
      *pos = v46;
      v48 = *v20;
      *(v48 + 52) = Byte2UInt32(Interface, v46);
      v49 = *pos + 4;
      *pos = v49;
      v51 = *v20;
      *(v51 + 56) = Byte2UInt32(Interface, v49);
      v52 = *pos + 4;
      *pos = v52;
      v54 = *v20;
      *(v54 + 60) = Byte2Float(Interface, v52);
      v55 = *pos + 4;
      *pos = v55;
      v57 = *v20;
      *(v57 + 64) = Byte2Float(Interface, v55);
      v58 = *pos + 4;
      *pos = v58;
      v60 = *v20;
      *(v60 + 68) = Byte2Float(Interface, v58);
      v61 = *pos + 4;
      *pos = v61;
      v63 = *v20;
      *(v63 + 72) = Byte2Float(Interface, v61);
      v64 = *pos + 4;
      *pos = v64;
      v66 = *v20;
      *(v66 + 76) = Byte2Float(Interface, v64);
      v67 = *pos + 4;
      *pos = v67;
      v69 = *v20;
      *(v69 + 80) = Byte2Float(Interface, v67);
      v70 = *pos + 4;
      *pos = v70;
      v72 = *v20;
      *(v72 + 84) = Byte2UInt32(Interface, v70);
      *pos += 4;
      ++v14;
      *(*v20 + 88LL) = *(*v20 + 32LL);
    }
    while (v8 != v14);
  }
  return v9;
}

// 0x1a3e4a0
void effPCPFlashPolySphere2ExpParam_t__pClone(effPCPFlashPolySphere2ExpParam_t *this, effPCPFlashPolySphere2ExpParam_t **param) {
  f32 x;
  f32 y;
  effPCPFlashPolySphere2ExpParam_t_o *v7;
  f32 z;
  f32 w;
  f32 v11;
  f32 v12;
  effPCPFlashPolySphere2ExpParam_t_o *v13;
  u32 number;
  u32 numberO;
  s64 v16;
  s64 v17;

  x = this->pos.x;
  y = this->pos.y;
  v7 = *param;
  z = this->pos.z;
  w = this->pos.w;
  v16 = 0;
  v17 = 0;
  sub_854690(&v16, x, y, z, w);
  v12 = *&v17;
  v11 = *(&v17 + 1);
  *&v7->pos.x = v16;
  v7->pos.z = v12;
  v7->pos.w = v11;
  (*param)->numberO = this->numberO;
  v13 = *param;
  number = this->number;
  numberO = this->numberO;
  v13->number = CutRaitoGet(number, numberO);
  (*param)->loop = this->loop;
  (*param)->life = this->life;
  (*param)->abgr_s = this->abgr_s;
  (*param)->abgr_e = this->abgr_e;
  (*param)->abgr_in = this->abgr_in;
  (*param)->abgr_out = this->abgr_out;
  (*param)->radius = this->radius;
  (*param)->radius_s = this->radius_s;
  (*param)->radius_a = this->radius_a;
  (*param)->blend = this->blend;
}

// 0x1a3de70
effPCPFlashPolySphere2ExpParam_t **effPCPFlashPolySphere2ExpParam_t__pCopy(effPCPFlashPolySphere2ExpParam_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  u32 *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u32 *v14;
  u64 v15;
  u64 *v16;
  s32 v18;
  s32 v21;
  s64 v23;
  s32 v24;
  s64 v26;
  s32 v27;
  s64 v29;
  s32 v30;
  s64 v32;
  s32 v33;
  s32 v36;
  s64 v38;
  s32 v39;
  s64 v41;
  s32 v42;
  s64 v44;
  s32 v45;
  s64 v47;
  s32 v48;
  s64 v50;
  s32 v51;
  s64 v53;
  s32 v54;
  s64 v56;
  s32 v57;
  s64 v59;
  s32 v60;
  s64 v62;
  s64 v64;
  u64 v66[3];

  v8 = max;
  v9 = NewSpecific(effPCPFlashPolySphere2ExpParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v66);
      if ((v66[0] & 1) != 0)
        v12 = v66[2];
      else
        v12 = v66 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = v9 + 8;
    v15 = 0;
    do
    {
      v16 = Allocate(effPCPFlashPolySphere2ExpParam_t);
      _ctor(v16, 0);
      *&v14[2 * v15] = v16;
      v18 = *pos;
      *(v16 + 4) = Byte2Float(Interface, v18);
      v21 = *pos + 4;
      *pos = v21;
      v23 = *&v14[2 * v15];
      *(v23 + 20) = Byte2Float(Interface, v21);
      v24 = *pos + 4;
      *pos = v24;
      v26 = *&v14[2 * v15];
      *(v26 + 24) = Byte2Float(Interface, v24);
      v27 = *pos + 4;
      *pos = v27;
      v29 = *&v14[2 * v15];
      *(v29 + 28) = Byte2Float(Interface, v27);
      v30 = *pos + 4;
      *pos = v30;
      v32 = *&v14[2 * v15];
      *(v32 + 32) = Byte2UInt32(Interface, v30);
      v33 = *pos + 4;
      *pos = v33;
      *(*&v14[2 * v15] + 36LL) = *(Interface + v33 + 32);
      v36 = *pos + 4;
      *pos = v36;
      v38 = *&v14[2 * v15];
      *(v38 + 40) = Byte2UInt32(Interface, v36);
      v39 = *pos + 4;
      *pos = v39;
      v41 = *&v14[2 * v15];
      *(v41 + 44) = Byte2UInt32(Interface, v39);
      v42 = *pos + 4;
      *pos = v42;
      v44 = *&v14[2 * v15];
      *(v44 + 48) = Byte2UInt32(Interface, v42);
      v45 = *pos + 4;
      *pos = v45;
      v47 = *&v14[2 * v15];
      *(v47 + 52) = Byte2UInt32(Interface, v45);
      v48 = *pos + 4;
      *pos = v48;
      v50 = *&v14[2 * v15];
      *(v50 + 56) = Byte2UInt32(Interface, v48);
      v51 = *pos + 4;
      *pos = v51;
      v53 = *&v14[2 * v15];
      *(v53 + 60) = Byte2Float(Interface, v51);
      v54 = *pos + 4;
      *pos = v54;
      v56 = *&v14[2 * v15];
      *(v56 + 64) = Byte2Float(Interface, v54);
      v57 = *pos + 4;
      *pos = v57;
      v59 = *&v14[2 * v15];
      *(v59 + 68) = Byte2Float(Interface, v57);
      v60 = *pos + 4;
      *pos = v60;
      v62 = *&v14[2 * v15];
      *(v62 + 72) = Byte2UInt32(Interface, v60);
      *pos += 4;
      v64 = *&v14[2 * v15++];
      *(v64 + 76) = *(v64 + 32);
    }
    while (v8 != v15);
  }
  return v9;
}

// 0x1a3eb60
void effPCPFlashPolySphere2Param_t__pClone(effPCPFlashPolySphere2Param_t *this, effPCPFlashPolySphere2Param_t **param) {
  f32 x;
  f32 y;
  effPCPFlashPolySphere2Param_t_o *v7;
  f32 z;
  f32 w;
  f32 v11;
  f32 v12;
  effPCPFlashPolySphere2Param_t_o *v13;
  u32 number;
  u32 numberO;
  s64 v16;
  s64 v17;

  x = this->pos.x;
  y = this->pos.y;
  v7 = *param;
  z = this->pos.z;
  w = this->pos.w;
  v16 = 0;
  v17 = 0;
  sub_854690(&v16, x, y, z, w);
  v12 = *&v17;
  v11 = *(&v17 + 1);
  *&v7->pos.x = v16;
  v7->pos.z = v12;
  v7->pos.w = v11;
  (*param)->numberO = this->numberO;
  v13 = *param;
  number = this->number;
  numberO = this->numberO;
  v13->number = CutRaitoGet(number, numberO);
  (*param)->loop = this->loop;
  (*param)->life = this->life;
  (*param)->scale_f = this->scale_f;
  (*param)->abgr_in = this->abgr_in;
  (*param)->abgr_out = this->abgr_out;
  (*param)->radius = this->radius;
  (*param)->blend = this->blend;
}

// 0x1a3e5f0
effPCPFlashPolySphere2Param_t **effPCPFlashPolySphere2Param_t__pCopy(effPCPFlashPolySphere2Param_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  u32 *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u32 *v14;
  u64 v15;
  u64 *v16;
  s32 v18;
  s32 v21;
  s64 v23;
  s32 v24;
  s64 v26;
  s32 v27;
  s64 v29;
  s32 v30;
  s64 v32;
  s32 v33;
  s32 v36;
  s64 v38;
  s32 v39;
  s64 v41;
  s32 v42;
  s64 v44;
  s32 v45;
  s64 v47;
  s32 v48;
  s64 v50;
  s32 v51;
  s64 v53;
  s64 v55;
  u64 v57[3];

  v8 = max;
  v9 = NewSpecific(effPCPFlashPolySphere2Param_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v57);
      if ((v57[0] & 1) != 0)
        v12 = v57[2];
      else
        v12 = v57 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = v9 + 8;
    v15 = 0;
    do
    {
      v16 = Allocate(effPCPFlashPolySphere2Param_t);
      _ctor(v16, 0);
      *&v14[2 * v15] = v16;
      v18 = *pos;
      *(v16 + 4) = Byte2Float(Interface, v18);
      v21 = *pos + 4;
      *pos = v21;
      v23 = *&v14[2 * v15];
      *(v23 + 20) = Byte2Float(Interface, v21);
      v24 = *pos + 4;
      *pos = v24;
      v26 = *&v14[2 * v15];
      *(v26 + 24) = Byte2Float(Interface, v24);
      v27 = *pos + 4;
      *pos = v27;
      v29 = *&v14[2 * v15];
      *(v29 + 28) = Byte2Float(Interface, v27);
      v30 = *pos + 4;
      *pos = v30;
      v32 = *&v14[2 * v15];
      *(v32 + 32) = Byte2UInt32(Interface, v30);
      v33 = *pos + 4;
      *pos = v33;
      *(*&v14[2 * v15] + 36LL) = *(Interface + v33 + 32);
      v36 = *pos + 4;
      *pos = v36;
      v38 = *&v14[2 * v15];
      *(v38 + 40) = Byte2UInt32(Interface, v36);
      v39 = *pos + 4;
      *pos = v39;
      v41 = *&v14[2 * v15];
      *(v41 + 44) = Byte2UInt32(Interface, v39);
      v42 = *pos + 4;
      *pos = v42;
      v44 = *&v14[2 * v15];
      *(v44 + 48) = Byte2UInt32(Interface, v42);
      v45 = *pos + 4;
      *pos = v45;
      v47 = *&v14[2 * v15];
      *(v47 + 52) = Byte2UInt32(Interface, v45);
      v48 = *pos + 4;
      *pos = v48;
      v50 = *&v14[2 * v15];
      *(v50 + 56) = Byte2Float(Interface, v48);
      v51 = *pos + 4;
      *pos = v51;
      v53 = *&v14[2 * v15];
      *(v53 + 60) = Byte2UInt32(Interface, v51);
      *pos += 4;
      v55 = *&v14[2 * v15++];
      *(v55 + 64) = *(v55 + 32);
    }
    while (v8 != v15);
  }
  return v9;
}

// 0x1a3f530
void effPCPFlashPolySphere3Param_t__pClone(effPCPFlashPolySphere3Param_t *this, effPCPFlashPolySphere3Param_t **param) {
  f32 x;
  f32 y;
  effPCPFlashPolySphere3Param_t_o *v7;
  f32 z;
  f32 w;
  f32 v11;
  f32 v12;
  effPCPFlashPolySphere3Param_t_o *v13;
  u32 number;
  u32 numberO;
  s64 v16;
  struct System_UInt32_array *reserve;
  struct System_UInt32_array *v18;
  s32 v19;
  s64 v22;
  s64 v23;

  x = this->pos.x;
  y = this->pos.y;
  v7 = *param;
  z = this->pos.z;
  w = this->pos.w;
  v22 = 0;
  v23 = 0;
  sub_854690(&v22, x, y, z, w);
  v12 = *&v23;
  v11 = *(&v23 + 1);
  *&v7->pos.x = v22;
  v7->pos.z = v12;
  v7->pos.w = v11;
  (*param)->numberO = this->numberO;
  v13 = *param;
  number = this->number;
  numberO = this->numberO;
  v13->number = CutRaitoGet(number, numberO);
  (*param)->loop = this->loop;
  (*param)->life = this->life;
  (*param)->interval = this->interval;
  (*param)->abgr_s = this->abgr_s;
  (*param)->abgr_e = this->abgr_e;
  (*param)->abgr_in = this->abgr_in;
  (*param)->abgr_out = this->abgr_out;
  (*param)->width = this->width;
  (*param)->width_r = this->width_r;
  (*param)->radius = this->radius;
  (*param)->rotate = this->rotate;
  (*param)->move = this->move;
  (*param)->move_s = this->move_s;
  (*param)->move_a = this->move_a;
  v16 = 8;
  (*param)->blend = this->blend;
  do
  {
    reserve = this->reserve;
    v18 = (*param)->reserve;
    v19 = *(&reserve->obj.klass + v16);
    *(&v18->obj.klass + v16++) = v19;
  }
  while (v16 != 40);
}

// 0x1a3ec90
effPCPFlashPolySphere3Param_t **effPCPFlashPolySphere3Param_t__pCopy(effPCPFlashPolySphere3Param_t *this, void *pData, s32 *pos, s32 max) {
  effPCPFlashPolySphere3Param_t_array *v8;
  Il2CppClass *v9;
  s64 *Interface;
  char *v11;
  s64 *v12;
  u64 v13;
  il2cpp_array_size_t *p_max_length;
  u64 *v15;
  Il2CppClass **v17;
  char *v18;
  s32 v19;
  s32 v22;
  s64 v24;
  s32 v25;
  s64 v27;
  s32 v28;
  s64 v30;
  s32 v31;
  s64 v33;
  s32 v34;
  s32 v37;
  s64 v39;
  s32 v40;
  s64 v42;
  s32 v43;
  s64 v45;
  s32 v46;
  s64 v48;
  s32 v49;
  s64 v51;
  s32 v52;
  s64 v54;
  s32 v55;
  s64 v57;
  s32 v58;
  s64 v60;
  s32 v61;
  s64 v63;
  s32 v64;
  s64 v66;
  s32 v67;
  s64 v69;
  s32 v70;
  s64 v72;
  s32 v73;
  s64 v75;
  s32 v76;
  s64 v78;
  u64 v80;
  s64 v81;
  s64 v83;
  s64 v84;
  s32 v85;
  u32 v86;
  u64 v90[3];

  v8 = NewSpecific(effPCPFlashPolySphere3Param_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v9, v90);
      if ((v90[0] & 1) != 0)
        v11 = v90[2];
      else
        v11 = v90 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v13 = 0;
    p_max_length = &v8->max_length;
    do
    {
      v15 = Allocate(effPCPFlashPolySphere3Param_t);
      v15[13] = NewSpecific(uint, 0x20u);
      _ctor(v15, 0);
      v17 = &v8->obj.klass + v13;
      v17[4] = v15;
      v18 = (v17 + 4);
      v19 = *pos;
      *(v15 + 4) = Byte2Float(Interface, v19);
      v22 = *pos + 4;
      *pos = v22;
      v24 = *v18;
      *(v24 + 20) = Byte2Float(Interface, v22);
      v25 = *pos + 4;
      *pos = v25;
      v27 = *v18;
      *(v27 + 24) = Byte2Float(Interface, v25);
      v28 = *pos + 4;
      *pos = v28;
      v30 = *v18;
      *(v30 + 28) = Byte2Float(Interface, v28);
      v31 = *pos + 4;
      *pos = v31;
      v33 = *v18;
      *(v33 + 32) = Byte2UInt32(Interface, v31);
      v34 = *pos + 4;
      *pos = v34;
      *(*v18 + 36LL) = *(Interface + v34 + 32);
      v37 = *pos + 4;
      *pos = v37;
      v39 = *v18;
      *(v39 + 40) = Byte2UInt32(Interface, v37);
      v40 = *pos + 4;
      *pos = v40;
      v42 = *v18;
      *(v42 + 44) = Byte2UInt32(Interface, v40);
      v43 = *pos + 4;
      *pos = v43;
      v45 = *v18;
      *(v45 + 48) = Byte2UInt32(Interface, v43);
      v46 = *pos + 4;
      *pos = v46;
      v48 = *v18;
      *(v48 + 52) = Byte2UInt32(Interface, v46);
      v49 = *pos + 4;
      *pos = v49;
      v51 = *v18;
      *(v51 + 56) = Byte2UInt32(Interface, v49);
      v52 = *pos + 4;
      *pos = v52;
      v54 = *v18;
      *(v54 + 60) = Byte2UInt32(Interface, v52);
      v55 = *pos + 4;
      *pos = v55;
      v57 = *v18;
      *(v57 + 64) = Byte2Float(Interface, v55);
      v58 = *pos + 4;
      *pos = v58;
      v60 = *v18;
      *(v60 + 68) = Byte2Float(Interface, v58);
      v61 = *pos + 4;
      *pos = v61;
      v63 = *v18;
      *(v63 + 72) = Byte2Float(Interface, v61);
      v64 = *pos + 4;
      *pos = v64;
      v66 = *v18;
      *(v66 + 76) = Byte2Float(Interface, v64);
      v67 = *pos + 4;
      *pos = v67;
      v69 = *v18;
      *(v69 + 80) = Byte2Float(Interface, v67);
      v70 = *pos + 4;
      *pos = v70;
      v72 = *v18;
      *(v72 + 84) = Byte2Float(Interface, v70);
      v73 = *pos + 4;
      *pos = v73;
      v75 = *v18;
      *(v75 + 88) = Byte2Float(Interface, v73);
      v76 = *pos + 4;
      *pos = v76;
      v78 = *v18;
      *(v78 + 92) = Byte2UInt32(Interface, v76);
      v80 = 0;
      *pos += 4;
      if (v13 >= *p_max_length)
      {
LABEL_65:
      }
      while (1)
      {
        v83 = *v18;
        if (v80 == 32)
          break;
        v84 = *(v83 + 104);
        v85 = *pos;
        v86 = Byte2UInt32(Interface, v85);
        v81 = v84 + 4 * v80++;
        *(v81 + 32) = v86;
        *pos += 4;
        if (v13 >= *p_max_length)
          goto LABEL_65;
      }
      *(v83 + 96) = *(v83 + 32);
      ++v13;
    }
    while (v13 != max);
  }
  return v8;
}

// 0x1a3fe80
void effPCPFlashPolySphereExpParam_t__pClone(effPCPFlashPolySphereExpParam_t *this, effPCPFlashPolySphereExpParam_t **param) {
  f32 x;
  f32 y;
  effPCPFlashPolySphereExpParam_t_o *v7;
  f32 z;
  f32 w;
  f32 v11;
  f32 v12;
  effPCPFlashPolySphereExpParam_t_o *v13;
  u32 number;
  u32 numberO;
  s64 v16;
  s64 v17;

  x = this->pos.x;
  y = this->pos.y;
  v7 = *param;
  z = this->pos.z;
  w = this->pos.w;
  v16 = 0;
  v17 = 0;
  sub_854690(&v16, x, y, z, w);
  v12 = *&v17;
  v11 = *(&v17 + 1);
  *&v7->pos.x = v16;
  v7->pos.z = v12;
  v7->pos.w = v11;
  (*param)->numberO = this->numberO;
  v13 = *param;
  number = this->number;
  numberO = this->numberO;
  v13->number = CutRaitoGet(number, numberO);
  (*param)->loop = this->loop;
  (*param)->life = this->life;
  (*param)->scale_f = this->scale_f;
  (*param)->interval = this->interval;
  (*param)->fix = this->fix;
  (*param)->abgr_s = this->abgr_s;
  (*param)->abgr_e = this->abgr_e;
  (*param)->abgr_in = this->abgr_in;
  (*param)->abgr_out = this->abgr_out;
  (*param)->width_in = this->width_in;
  (*param)->width_out = this->width_out;
  (*param)->radius = this->radius;
  (*param)->rotate = this->rotate;
  (*param)->blend = this->blend;
}

// 0x1a3f740
effPCPFlashPolySphereExpParam_t **effPCPFlashPolySphereExpParam_t__pCopy(effPCPFlashPolySphereExpParam_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  effPCPFlashPolySphereExpParam_t_array *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u64 v14;
  il2cpp_array_size_t *p_max_length;
  u64 *v17;
  s64 v20;
  s32 v21;
  s32 v22;
  s64 v24;
  s32 v25;
  s64 v27;
  s32 v28;
  s64 v30;
  s32 v31;
  s64 v33;
  s32 v34;
  s32 v37;
  s64 v39;
  s32 v40;
  s64 v42;
  s32 v43;
  s64 v45;
  s32 v46;
  s32 v49;
  s64 v51;
  s32 v52;
  s64 v54;
  s32 v55;
  s64 v57;
  s32 v58;
  s64 v60;
  s32 v61;
  s64 v63;
  s32 v64;
  s64 v66;
  s32 v67;
  s64 v69;
  s32 v70;
  s64 v72;
  s32 v73;
  s64 v75;
  u64 v78[3];

  v8 = max;
  v9 = NewSpecific(effPCPFlashPolySphereExpParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v78);
      if ((v78[0] & 1) != 0)
        v12 = v78[2];
      else
        v12 = v78 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = 0;
    p_max_length = &v9->max_length;
    do
    {
      v17 = Allocate(effPCPFlashPolySphereExpParam_t);
      _ctor(v17, 0);
      v20 = &v9->m_Items[v14];
      *v20 = v17;
      v21 = *pos;
      *(v17 + 4) = Byte2Float(Interface, v21);
      v22 = *pos + 4;
      *pos = v22;
      v24 = *v20;
      *(v24 + 20) = Byte2Float(Interface, v22);
      v25 = *pos + 4;
      *pos = v25;
      v27 = *v20;
      *(v27 + 24) = Byte2Float(Interface, v25);
      v28 = *pos + 4;
      *pos = v28;
      v30 = *v20;
      *(v30 + 28) = Byte2Float(Interface, v28);
      v31 = *pos + 4;
      *pos = v31;
      v33 = *v20;
      *(v33 + 32) = Byte2UInt32(Interface, v31);
      v34 = *pos + 4;
      *pos = v34;
      *(*v20 + 36LL) = *(Interface + v34 + 32);
      v37 = *pos + 4;
      *pos = v37;
      v39 = *v20;
      *(v39 + 40) = Byte2UInt32(Interface, v37);
      v40 = *pos + 4;
      *pos = v40;
      v42 = *v20;
      *(v42 + 44) = Byte2UInt32(Interface, v40);
      v43 = *pos + 4;
      *pos = v43;
      v45 = *v20;
      *(v45 + 48) = Byte2UInt32(Interface, v43);
      v46 = *pos + 4;
      *pos = v46;
      *(*v20 + 52LL) = *(Interface + v46 + 32);
      v49 = *pos + 4;
      *pos = v49;
      v51 = *v20;
      *(v51 + 56) = Byte2UInt32(Interface, v49);
      v52 = *pos + 4;
      *pos = v52;
      v54 = *v20;
      *(v54 + 60) = Byte2UInt32(Interface, v52);
      v55 = *pos + 4;
      *pos = v55;
      v57 = *v20;
      *(v57 + 64) = Byte2UInt32(Interface, v55);
      v58 = *pos + 4;
      *pos = v58;
      v60 = *v20;
      *(v60 + 68) = Byte2UInt32(Interface, v58);
      v61 = *pos + 4;
      *pos = v61;
      v63 = *v20;
      *(v63 + 72) = Byte2Float(Interface, v61);
      v64 = *pos + 4;
      *pos = v64;
      v66 = *v20;
      *(v66 + 76) = Byte2Float(Interface, v64);
      v67 = *pos + 4;
      *pos = v67;
      v69 = *v20;
      *(v69 + 80) = Byte2Float(Interface, v67);
      v70 = *pos + 4;
      *pos = v70;
      v72 = *v20;
      *(v72 + 84) = Byte2Float(Interface, v70);
      v73 = *pos + 4;
      *pos = v73;
      v75 = *v20;
      *(v75 + 88) = Byte2UInt32(Interface, v73);
      *pos += 4;
      ++v14;
      *(*v20 + 92LL) = *(*v20 + 32LL);
    }
    while (v8 != v14);
  }
  return v9;
}

// 0x1a40670
void effPCPFlashPolySphereParam_t__pClone(effPCPFlashPolySphereParam_t *this, effPCPFlashPolySphereParam_t **param) {
  f32 x;
  f32 y;
  effPCPFlashPolySphereParam_t_o *v7;
  f32 z;
  f32 w;
  f32 v11;
  f32 v12;
  effPCPFlashPolySphereParam_t_o *v13;
  u32 number;
  u32 numberO;
  s64 v16;
  s64 v17;

  x = this->pos.x;
  y = this->pos.y;
  v7 = *param;
  z = this->pos.z;
  w = this->pos.w;
  v16 = 0;
  v17 = 0;
  sub_854690(&v16, x, y, z, w);
  v12 = *&v17;
  v11 = *(&v17 + 1);
  *&v7->pos.x = v16;
  v7->pos.z = v12;
  v7->pos.w = v11;
  (*param)->numberO = this->numberO;
  v13 = *param;
  number = this->number;
  numberO = this->numberO;
  v13->number = CutRaitoGet(number, numberO);
  (*param)->loop = this->loop;
  (*param)->life = this->life;
  (*param)->scale_f = this->scale_f;
  (*param)->interval = this->interval;
  (*param)->abgr_in = this->abgr_in;
  (*param)->abgr_out = this->abgr_out;
  (*param)->width_in = this->width_in;
  (*param)->width_out = this->width_out;
  (*param)->radius = this->radius;
  (*param)->rotate = this->rotate;
  (*param)->blend = this->blend;
}

// 0x1a40000
effPCPFlashPolySphereParam_t **effPCPFlashPolySphereParam_t__pCopy(effPCPFlashPolySphereParam_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  u32 *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u32 *v14;
  u64 v15;
  u64 *v16;
  s32 v18;
  s32 v21;
  s64 v23;
  s32 v24;
  s64 v26;
  s32 v27;
  s64 v29;
  s32 v30;
  s64 v32;
  s32 v33;
  s32 v36;
  s64 v38;
  s32 v39;
  s64 v41;
  s32 v42;
  s64 v44;
  s32 v45;
  s64 v47;
  s32 v48;
  s64 v50;
  s32 v51;
  s64 v53;
  s32 v54;
  s64 v56;
  s32 v57;
  s64 v59;
  s32 v60;
  s64 v62;
  s32 v63;
  s64 v65;
  s64 v67;
  u64 v69[3];

  v8 = max;
  v9 = NewSpecific(effPCPFlashPolySphereParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v69);
      if ((v69[0] & 1) != 0)
        v12 = v69[2];
      else
        v12 = v69 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = v9 + 8;
    v15 = 0;
    do
    {
      v16 = Allocate(effPCPFlashPolySphereParam_t);
      _ctor(v16, 0);
      *&v14[2 * v15] = v16;
      v18 = *pos;
      *(v16 + 4) = Byte2Float(Interface, v18);
      v21 = *pos + 4;
      *pos = v21;
      v23 = *&v14[2 * v15];
      *(v23 + 20) = Byte2Float(Interface, v21);
      v24 = *pos + 4;
      *pos = v24;
      v26 = *&v14[2 * v15];
      *(v26 + 24) = Byte2Float(Interface, v24);
      v27 = *pos + 4;
      *pos = v27;
      v29 = *&v14[2 * v15];
      *(v29 + 28) = Byte2Float(Interface, v27);
      v30 = *pos + 4;
      *pos = v30;
      v32 = *&v14[2 * v15];
      *(v32 + 32) = Byte2UInt32(Interface, v30);
      v33 = *pos + 4;
      *pos = v33;
      *(*&v14[2 * v15] + 36LL) = *(Interface + v33 + 32);
      v36 = *pos + 4;
      *pos = v36;
      v38 = *&v14[2 * v15];
      *(v38 + 40) = Byte2UInt32(Interface, v36);
      v39 = *pos + 4;
      *pos = v39;
      v41 = *&v14[2 * v15];
      *(v41 + 44) = Byte2UInt32(Interface, v39);
      v42 = *pos + 4;
      *pos = v42;
      v44 = *&v14[2 * v15];
      *(v44 + 48) = Byte2UInt32(Interface, v42);
      v45 = *pos + 4;
      *pos = v45;
      v47 = *&v14[2 * v15];
      *(v47 + 52) = Byte2UInt32(Interface, v45);
      v48 = *pos + 4;
      *pos = v48;
      v50 = *&v14[2 * v15];
      *(v50 + 56) = Byte2UInt32(Interface, v48);
      v51 = *pos + 4;
      *pos = v51;
      v53 = *&v14[2 * v15];
      *(v53 + 60) = Byte2Float(Interface, v51);
      v54 = *pos + 4;
      *pos = v54;
      v56 = *&v14[2 * v15];
      *(v56 + 64) = Byte2Float(Interface, v54);
      v57 = *pos + 4;
      *pos = v57;
      v59 = *&v14[2 * v15];
      *(v59 + 68) = Byte2Float(Interface, v57);
      v60 = *pos + 4;
      *pos = v60;
      v62 = *&v14[2 * v15];
      *(v62 + 72) = Byte2Float(Interface, v60);
      v63 = *pos + 4;
      *pos = v63;
      v65 = *&v14[2 * v15];
      *(v65 + 76) = Byte2UInt32(Interface, v63);
      *pos += 4;
      v67 = *&v14[2 * v15++];
      *(v67 + 80) = *(v67 + 32);
    }
    while (v8 != v15);
  }
  return v9;
}

// 0x1a40ed0
void effPCPHamaCardScatterParam_t__pClone(effPCPHamaCardScatterParam_t *this, effPCPHamaCardScatterParam_t **param) {
  f32 x;
  f32 y;
  effPCPHamaCardScatterParam_t_o *v5;
  f32 z;
  f32 w;
  f32 v10;
  f32 v11;
  s64 v12;
  f32 v13;
  f32 v14;

  x = this->pos.x;
  y = this->pos.y;
  v5 = *param;
  z = this->pos.z;
  w = this->pos.w;
  v12 = 0;
  sub_854690(&v12, x, y, z, w);
  v11 = v13;
  v10 = v14;
  *&v5->pos.x = v12;
  v5->pos.z = v11;
  v5->pos.w = v10;
  (*param)->tex_w = this->tex_w;
  (*param)->tex_h = this->tex_h;
  (*param)->blend = this->blend;
  (*param)->loop = this->loop;
  (*param)->number = this->number;
  (*param)->timing = this->timing;
  (*param)->fade_in = this->fade_in;
  (*param)->fade_out = this->fade_out;
  (*param)->life = this->life;
  (*param)->wait = this->wait;
  (*param)->drop_s = this->drop_s;
  (*param)->drop_a = this->drop_a;
  (*param)->attach = this->attach;
  (*param)->attach_f = this->attach_f;
  (*param)->attach_i = this->attach_i;
}

// 0x1a407d0
effPCPHamaCardScatterParam_t **effPCPHamaCardScatterParam_t__pCopy(effPCPHamaCardScatterParam_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  u32 *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u64 v14;
  u64 *v15;
  s64 v17;
  s32 v18;
  s32 v21;
  s64 v23;
  s32 v24;
  s64 v26;
  s32 v27;
  s64 v29;
  s32 v30;
  s64 v32;
  s32 v33;
  s64 v35;
  s32 v36;
  s64 v38;
  s32 v39;
  s32 v42;
  s64 v44;
  s32 v45;
  s64 v47;
  s32 v48;
  s64 v50;
  s32 v51;
  s64 v53;
  s32 v54;
  s64 v56;
  s32 v57;
  s64 v59;
  s32 v60;
  s64 v62;
  s32 v63;
  s64 v65;
  s32 v66;
  s32 v69;
  s64 v71;
  s32 v72;
  s64 v74;
  u64 v76[3];

  v8 = max;
  v9 = NewSpecific(effPCPHamaCardScatterParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v76);
      if ((v76[0] & 1) != 0)
        v12 = v76[2];
      else
        v12 = v76 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = 0;
    do
    {
      v15 = Allocate(effPCPHamaCardScatterParam_t);
      _ctor(v15, 0);
      v17 = &v9[2 * v14 + 8];
      *v17 = v15;
      v18 = *pos;
      *(v15 + 4) = Byte2Float(Interface, v18);
      v21 = *pos + 4;
      *pos = v21;
      v23 = *v17;
      *(v23 + 20) = Byte2Float(Interface, v21);
      v24 = *pos + 4;
      *pos = v24;
      v26 = *v17;
      *(v26 + 16) = Byte2Float(Interface, v24);
      v27 = *pos + 4;
      *pos = v27;
      v29 = *v17;
      *(v29 + 28) = Byte2Float(Interface, v27);
      v30 = *pos + 4;
      *pos = v30;
      v32 = *v17;
      *(v32 + 32) = Byte2Float(Interface, v30);
      v33 = *pos + 4;
      *pos = v33;
      v35 = *v17;
      *(v35 + 36) = Byte2Float(Interface, v33);
      v36 = *pos + 4;
      *pos = v36;
      v38 = *v17;
      *(v38 + 40) = Byte2UInt32(Interface, v36);
      v39 = *pos + 4;
      *pos = v39;
      *(*v17 + 44LL) = *(Interface + v39 + 32);
      v42 = *pos + 4;
      *pos = v42;
      v44 = *v17;
      *(v44 + 48) = Byte2UInt32(Interface, v42);
      v45 = *pos + 4;
      *pos = v45;
      v47 = *v17;
      *(v47 + 52) = Byte2UInt32(Interface, v45);
      v48 = *pos + 4;
      *pos = v48;
      v50 = *v17;
      *(v50 + 56) = Byte2UInt32(Interface, v48);
      v51 = *pos + 4;
      *pos = v51;
      v53 = *v17;
      *(v53 + 60) = Byte2UInt32(Interface, v51);
      v54 = *pos + 4;
      *pos = v54;
      v56 = *v17;
      *(v56 + 64) = Byte2UInt32(Interface, v54);
      v57 = *pos + 4;
      *pos = v57;
      v59 = *v17;
      *(v59 + 68) = Byte2UInt32(Interface, v57);
      v60 = *pos + 4;
      *pos = v60;
      v62 = *v17;
      *(v62 + 72) = Byte2Float(Interface, v60);
      v63 = *pos + 4;
      *pos = v63;
      v65 = *v17;
      *(v65 + 76) = Byte2Float(Interface, v63);
      v66 = *pos + 4;
      *pos = v66;
      *(*v17 + 80LL) = *(Interface + v66 + 32);
      v69 = *pos + 4;
      *pos = v69;
      v71 = *v17;
      *(v71 + 84) = Byte2UInt32(Interface, v69);
      v72 = *pos + 4;
      *pos = v72;
      v74 = *v17;
      *(v74 + 88) = Byte2UInt32(Interface, v72);
      ++v14;
      *pos += 4;
    }
    while (v8 != v14);
  }
  return v9;
}

// 0x1a41870
void effPCPHamaCardSphereParam_t__pClone(effPCPHamaCardSphereParam_t *this, effPCPHamaCardSphereParam_t **param) {
  f32 x;
  f32 y;
  effPCPHamaCardSphereParam_t_o *v5;
  f32 z;
  f32 w;
  f32 v10;
  f32 v11;
  s64 v12;
  f32 v13;
  f32 v14;

  x = this->pos.x;
  y = this->pos.y;
  v5 = *param;
  z = this->pos.z;
  w = this->pos.w;
  v12 = 0;
  sub_854690(&v12, x, y, z, w);
  v11 = v13;
  v10 = v14;
  *&v5->pos.x = v12;
  v5->pos.z = v11;
  v5->pos.w = v10;
  (*param)->tex_w = this->tex_w;
  (*param)->tex_h = this->tex_h;
  (*param)->blend = this->blend;
  (*param)->loop = this->loop;
  (*param)->number = this->number;
  (*param)->timing = this->timing;
  (*param)->fade_in = this->fade_in;
  (*param)->fade_out = this->fade_out;
  (*param)->life = this->life;
  (*param)->wait = this->wait;
  (*param)->roll_s = this->roll_s;
  (*param)->roll_a = this->roll_a;
  (*param)->radius_s = this->radius_s;
  (*param)->radius_e = this->radius_e;
  (*param)->radius_s_r = this->radius_s_r;
  (*param)->radius_e_r = this->radius_e_r;
  (*param)->vibrate = this->vibrate;
  (*param)->vib_power = this->vib_power;
  (*param)->attach = this->attach;
  (*param)->attach_f = this->attach_f;
  (*param)->attach_i = this->attach_i;
}

// 0x1a40fe0
effPCPHamaCardSphereParam_t **effPCPHamaCardSphereParam_t__pCopy(effPCPHamaCardSphereParam_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  effPCPHamaCardSphereParam_t_array *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u64 v14;
  il2cpp_array_size_t *p_max_length;
  u64 *v17;
  s64 v20;
  s32 v21;
  s32 v22;
  s64 v24;
  s32 v25;
  s64 v27;
  s32 v28;
  s64 v30;
  s32 v31;
  s64 v33;
  s32 v34;
  s64 v36;
  s32 v37;
  s64 v39;
  s32 v40;
  s32 v43;
  s64 v45;
  s32 v46;
  s64 v48;
  s32 v49;
  s64 v51;
  s32 v52;
  s64 v54;
  s32 v55;
  s64 v57;
  s32 v58;
  s64 v60;
  s32 v61;
  s64 v63;
  s32 v64;
  s64 v66;
  s32 v67;
  s64 v69;
  s32 v70;
  s64 v72;
  s32 v73;
  s64 v75;
  s32 v76;
  s64 v78;
  s32 v79;
  s32 v82;
  s64 v84;
  s32 v85;
  s32 v88;
  s64 v90;
  s32 v91;
  s64 v93;
  u64 v95[3];

  v8 = max;
  v9 = NewSpecific(effPCPHamaCardSphereParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v95);
      if ((v95[0] & 1) != 0)
        v12 = v95[2];
      else
        v12 = v95 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = 0;
    p_max_length = &v9->max_length;
    do
    {
      v17 = Allocate(effPCPHamaCardSphereParam_t);
      _ctor(v17, 0);
      v20 = &v9->m_Items[v14];
      *v20 = v17;
      v21 = *pos;
      *(v17 + 4) = Byte2Float(Interface, v21);
      v22 = *pos + 4;
      *pos = v22;
      v24 = *v20;
      *(v24 + 20) = Byte2Float(Interface, v22);
      v25 = *pos + 4;
      *pos = v25;
      v27 = *v20;
      *(v27 + 24) = Byte2Float(Interface, v25);
      v28 = *pos + 4;
      *pos = v28;
      v30 = *v20;
      *(v30 + 28) = Byte2Float(Interface, v28);
      v31 = *pos + 4;
      *pos = v31;
      v33 = *v20;
      *(v33 + 32) = Byte2Float(Interface, v31);
      v34 = *pos + 4;
      *pos = v34;
      v36 = *v20;
      *(v36 + 36) = Byte2Float(Interface, v34);
      v37 = *pos + 4;
      *pos = v37;
      v39 = *v20;
      *(v39 + 40) = Byte2UInt32(Interface, v37);
      v40 = *pos + 4;
      *pos = v40;
      *(*v20 + 44LL) = *(Interface + v40 + 32);
      v43 = *pos + 4;
      *pos = v43;
      v45 = *v20;
      *(v45 + 48) = Byte2UInt32(Interface, v43);
      v46 = *pos + 4;
      *pos = v46;
      v48 = *v20;
      *(v48 + 52) = Byte2UInt32(Interface, v46);
      v49 = *pos + 4;
      *pos = v49;
      v51 = *v20;
      *(v51 + 56) = Byte2UInt32(Interface, v49);
      v52 = *pos + 4;
      *pos = v52;
      v54 = *v20;
      *(v54 + 60) = Byte2UInt32(Interface, v52);
      v55 = *pos + 4;
      *pos = v55;
      v57 = *v20;
      *(v57 + 64) = Byte2UInt32(Interface, v55);
      v58 = *pos + 4;
      *pos = v58;
      v60 = *v20;
      *(v60 + 68) = Byte2UInt32(Interface, v58);
      v61 = *pos + 4;
      *pos = v61;
      v63 = *v20;
      *(v63 + 72) = Byte2Float(Interface, v61);
      v64 = *pos + 4;
      *pos = v64;
      v66 = *v20;
      *(v66 + 76) = Byte2Float(Interface, v64);
      v67 = *pos + 4;
      *pos = v67;
      v69 = *v20;
      *(v69 + 80) = Byte2Float(Interface, v67);
      v70 = *pos + 4;
      *pos = v70;
      v72 = *v20;
      *(v72 + 84) = Byte2Float(Interface, v70);
      v73 = *pos + 4;
      *pos = v73;
      v75 = *v20;
      *(v75 + 88) = Byte2Float(Interface, v73);
      v76 = *pos + 4;
      *pos = v76;
      v78 = *v20;
      *(v78 + 92) = Byte2Float(Interface, v76);
      v79 = *pos + 4;
      *pos = v79;
      *(*v20 + 96LL) = *(Interface + v79 + 32);
      v82 = *pos + 4;
      *pos = v82;
      v84 = *v20;
      *(v84 + 100) = Byte2Float(Interface, v82);
      v85 = *pos + 4;
      *pos = v85;
      *(*v20 + 104LL) = *(Interface + v85 + 32);
      v88 = *pos + 4;
      *pos = v88;
      v90 = *v20;
      *(v90 + 108) = Byte2UInt32(Interface, v88);
      v91 = *pos + 4;
      *pos = v91;
      v93 = *v20;
      *(v93 + 112) = Byte2UInt32(Interface, v91);
      ++v14;
      *pos += 4;
    }
    while (v8 != v14);
  }
  return v9;
}

// 0x1a42360
void effPCPHamaCardSpiralParam_t__pClone(effPCPHamaCardSpiralParam_t *this, effPCPHamaCardSpiralParam_t **param) {
  f32 x;
  f32 y;
  effPCPHamaCardSpiralParam_t_o *v5;
  f32 z;
  f32 w;
  f32 v10;
  f32 v11;
  s64 v12;
  f32 v13;
  f32 v14;

  x = this->pos.x;
  y = this->pos.y;
  v5 = *param;
  z = this->pos.z;
  w = this->pos.w;
  v12 = 0;
  sub_854690(&v12, x, y, z, w);
  v11 = v13;
  v10 = v14;
  *&v5->pos.x = v12;
  v5->pos.z = v11;
  v5->pos.w = v10;
  (*param)->tex_w = this->tex_w;
  (*param)->tex_h = this->tex_h;
  (*param)->blend = this->blend;
  (*param)->loop = this->loop;
  (*param)->number = this->number;
  (*param)->simu_num = this->simu_num;
  (*param)->timing = this->timing;
  (*param)->fade_in = this->fade_in;
  (*param)->fade_out = this->fade_out;
  (*param)->life = this->life;
  (*param)->wait = this->wait;
  (*param)->up_s = this->up_s;
  (*param)->up_a = this->up_a;
  (*param)->roll_s = this->roll_s;
  (*param)->roll_a = this->roll_a;
  (*param)->radius_s = this->radius_s;
  (*param)->radius_e = this->radius_e;
  (*param)->radius_s_r = this->radius_s_r;
  (*param)->radius_e_r = this->radius_e_r;
  (*param)->up_r = this->up_r;
  (*param)->vibrate = this->vibrate;
  (*param)->vib_power = this->vib_power;
  (*param)->attach = this->attach;
  (*param)->attach_f = this->attach_f;
  (*param)->attach_i = this->attach_i;
}

// 0x1a419d0
effPCPHamaCardSpiralParam_t **effPCPHamaCardSpiralParam_t__pCopy(effPCPHamaCardSpiralParam_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  effPCPHamaCardSpiralParam_t_array *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u64 v14;
  il2cpp_array_size_t *p_max_length;
  u64 *v17;
  s64 v20;
  s32 v21;
  s32 v22;
  s64 v24;
  s32 v25;
  s64 v27;
  s32 v28;
  s64 v30;
  s32 v31;
  s64 v33;
  s32 v34;
  s64 v36;
  s32 v37;
  s64 v39;
  s32 v40;
  s32 v43;
  s64 v45;
  s32 v46;
  s64 v48;
  s32 v49;
  s64 v51;
  s32 v52;
  s64 v54;
  s32 v55;
  s64 v57;
  s32 v58;
  s64 v60;
  s32 v61;
  s64 v63;
  s32 v64;
  s64 v66;
  s32 v67;
  s64 v69;
  s32 v70;
  s64 v72;
  s32 v73;
  s64 v75;
  s32 v76;
  s64 v78;
  s32 v79;
  s64 v81;
  s32 v82;
  s64 v84;
  s32 v85;
  s64 v87;
  s32 v88;
  s64 v90;
  s32 v91;
  s32 v94;
  s64 v96;
  s32 v97;
  s32 v100;
  s64 v102;
  s32 v103;
  s64 v105;
  u64 v107[3];

  v8 = max;
  v9 = NewSpecific(effPCPHamaCardSpiralParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v107);
      if ((v107[0] & 1) != 0)
        v12 = v107[2];
      else
        v12 = v107 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = 0;
    p_max_length = &v9->max_length;
    do
    {
      v17 = Allocate(effPCPHamaCardSpiralParam_t);
      _ctor(v17, 0);
      v20 = &v9->m_Items[v14];
      *v20 = v17;
      v21 = *pos;
      *(v17 + 4) = Byte2Float(Interface, v21);
      v22 = *pos + 4;
      *pos = v22;
      v24 = *v20;
      *(v24 + 20) = Byte2Float(Interface, v22);
      v25 = *pos + 4;
      *pos = v25;
      v27 = *v20;
      *(v27 + 24) = Byte2Float(Interface, v25);
      v28 = *pos + 4;
      *pos = v28;
      v30 = *v20;
      *(v30 + 28) = Byte2Float(Interface, v28);
      v31 = *pos + 4;
      *pos = v31;
      v33 = *v20;
      *(v33 + 32) = Byte2Float(Interface, v31);
      v34 = *pos + 4;
      *pos = v34;
      v36 = *v20;
      *(v36 + 36) = Byte2Float(Interface, v34);
      v37 = *pos + 4;
      *pos = v37;
      v39 = *v20;
      *(v39 + 40) = Byte2UInt32(Interface, v37);
      v40 = *pos + 4;
      *pos = v40;
      *(*v20 + 44LL) = *(Interface + v40 + 32);
      v43 = *pos + 4;
      *pos = v43;
      v45 = *v20;
      *(v45 + 48) = Byte2UInt32(Interface, v43);
      v46 = *pos + 4;
      *pos = v46;
      v48 = *v20;
      *(v48 + 52) = Byte2UInt32(Interface, v46);
      v49 = *pos + 4;
      *pos = v49;
      v51 = *v20;
      *(v51 + 56) = Byte2UInt32(Interface, v49);
      v52 = *pos + 4;
      *pos = v52;
      v54 = *v20;
      *(v54 + 60) = Byte2UInt32(Interface, v52);
      v55 = *pos + 4;
      *pos = v55;
      v57 = *v20;
      *(v57 + 64) = Byte2UInt32(Interface, v55);
      v58 = *pos + 4;
      *pos = v58;
      v60 = *v20;
      *(v60 + 68) = Byte2UInt32(Interface, v58);
      v61 = *pos + 4;
      *pos = v61;
      v63 = *v20;
      *(v63 + 72) = Byte2UInt32(Interface, v61);
      v64 = *pos + 4;
      *pos = v64;
      v66 = *v20;
      *(v66 + 76) = Byte2Float(Interface, v64);
      v67 = *pos + 4;
      *pos = v67;
      v69 = *v20;
      *(v69 + 80) = Byte2Float(Interface, v67);
      v70 = *pos + 4;
      *pos = v70;
      v72 = *v20;
      *(v72 + 84) = Byte2Float(Interface, v70);
      v73 = *pos + 4;
      *pos = v73;
      v75 = *v20;
      *(v75 + 88) = Byte2Float(Interface, v73);
      v76 = *pos + 4;
      *pos = v76;
      v78 = *v20;
      *(v78 + 92) = Byte2Float(Interface, v76);
      v79 = *pos + 4;
      *pos = v79;
      v81 = *v20;
      *(v81 + 96) = Byte2Float(Interface, v79);
      v82 = *pos + 4;
      *pos = v82;
      v84 = *v20;
      *(v84 + 100) = Byte2Float(Interface, v82);
      v85 = *pos + 4;
      *pos = v85;
      v87 = *v20;
      *(v87 + 104) = Byte2Float(Interface, v85);
      v88 = *pos + 4;
      *pos = v88;
      v90 = *v20;
      *(v90 + 108) = Byte2Float(Interface, v88);
      v91 = *pos + 4;
      *pos = v91;
      *(*v20 + 112LL) = *(Interface + v91 + 32);
      v94 = *pos + 4;
      *pos = v94;
      v96 = *v20;
      *(v96 + 116) = Byte2Float(Interface, v94);
      v97 = *pos + 4;
      *pos = v97;
      *(*v20 + 120LL) = *(Interface + v97 + 32);
      v100 = *pos + 4;
      *pos = v100;
      v102 = *v20;
      *(v102 + 124) = Byte2UInt32(Interface, v100);
      v103 = *pos + 4;
      *pos = v103;
      v105 = *v20;
      *(v105 + 128) = Byte2UInt32(Interface, v103);
      ++v14;
      *pos += 4;
    }
    while (v8 != v14);
  }
  return v9;
}

// 0x1a428b0
void effPCPHelperBEDParam_t__pClone(effPCPHelperBEDParam_t *this, effPCPHelperBEDParam_t **param) {
  f32 x;
  f32 y;
  effPCPHelperBEDParam_t_o *v5;
  f32 z;
  f32 w;
  f32 v10;
  f32 v11;
  s64 v12;
  f32 v13;
  f32 v14;

  x = this->pos.x;
  y = this->pos.y;
  v5 = *param;
  z = this->pos.z;
  w = this->pos.w;
  v12 = 0;
  sub_854690(&v12, x, y, z, w);
  v11 = v13;
  v10 = v14;
  *&v5->pos.x = v12;
  v5->pos.z = v11;
  v5->pos.w = v10;
  (*param)->fade_in = this->fade_in;
  (*param)->fade_out = this->fade_out;
  (*param)->speed = this->speed;
}

// 0x1a424f0
effPCPHelperBEDParam_t **effPCPHelperBEDParam_t__pCopy(effPCPHelperBEDParam_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  u32 *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u32 *v14;
  u64 v15;
  u64 *v16;
  s32 v18;
  s32 v21;
  s64 v23;
  s32 v24;
  s64 v26;
  s32 v27;
  s64 v29;
  s32 v30;
  s64 v32;
  s32 v33;
  s64 v35;
  s32 v36;
  s64 v38;
  u64 v40[3];

  v8 = max;
  v9 = NewSpecific(effPCPHelperBEDParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v40);
      if ((v40[0] & 1) != 0)
        v12 = v40[2];
      else
        v12 = v40 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = v9 + 8;
    v15 = 0;
    do
    {
      v16 = Allocate(effPCPHelperBEDParam_t);
      _ctor(v16, 0);
      *&v14[2 * v15] = v16;
      v18 = *pos;
      *(v16 + 4) = Byte2Float(Interface, v18);
      v21 = *pos + 4;
      *pos = v21;
      v23 = *&v14[2 * v15];
      *(v23 + 20) = Byte2Float(Interface, v21);
      v24 = *pos + 4;
      *pos = v24;
      v26 = *&v14[2 * v15];
      *(v26 + 24) = Byte2Float(Interface, v24);
      v27 = *pos + 4;
      *pos = v27;
      v29 = *&v14[2 * v15];
      *(v29 + 28) = Byte2Float(Interface, v27);
      v30 = *pos + 4;
      *pos = v30;
      v32 = *&v14[2 * v15];
      *(v32 + 32) = Byte2UInt32(Interface, v30);
      v33 = *pos + 4;
      *pos = v33;
      v35 = *&v14[2 * v15];
      *(v35 + 36) = Byte2UInt32(Interface, v33);
      v36 = *pos + 4;
      *pos = v36;
      v38 = *&v14[2 * v15];
      *(v38 + 40) = Byte2Float(Interface, v36);
      ++v15;
      *pos += 4;
    }
    while (v8 != v15);
  }
  return v9;
}

// 0x1a42930
effPCPMultiBlurExp2Param_t **effPCPMultiBlurExp2Param_t__pCopy(effPCPMultiBlurExp2Param_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  u32 *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u32 *v14;
  u64 v15;
  u64 *v18;
  s64 v20;
  s32 v22;
  s64 v24;
  s32 v25;
  s64 v27;
  s32 v28;
  s64 v30;
  s32 v31;
  s64 v33;
  s32 v34;
  s64 v36;
  s64 v38;
  u64 *v39;
  u64 v42[3];

  v8 = max;
  v9 = NewSpecific(effPCPMultiBlurExp2Param_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v42);
      if ((v42[0] & 1) != 0)
        v12 = v42[2];
      else
        v12 = v42 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = v9 + 8;
    v15 = 0;
    do
    {
      v18 = Allocate(effPCPMultiBlurExp2Param_t);
      _ctor(v18, 0);
      *&v14[2 * v15] = v18;
      v20 = *pos;
      *(v18 + 16) = *(Interface + v20 + 32);
      v22 = *pos + 4;
      *pos = v22;
      v24 = *&v14[2 * v15];
      *(v24 + 20) = Byte2UInt32(Interface, v22);
      v25 = *pos + 4;
      *pos = v25;
      v27 = *&v14[2 * v15];
      *(v27 + 24) = Byte2UInt32(Interface, v25);
      v28 = *pos + 4;
      *pos = v28;
      v30 = *&v14[2 * v15];
      *(v30 + 28) = Byte2UInt32(Interface, v28);
      v31 = *pos + 4;
      *pos = v31;
      v33 = *&v14[2 * v15];
      *(v33 + 32) = Byte2UInt32(Interface, v31);
      v34 = *pos + 4;
      *pos = v34;
      v36 = *&v14[2 * v15];
      *(v36 + 36) = Byte2UInt32(Interface, v34);
      *pos += 4;
      v38 = *&v14[2 * v15];
      v39 = Allocate(dds3Effect_PartialMultiBlurParam_t);
      dds3Effect_PartialMultiBlurParam_t___ctor(v39);
      *(v38 + 40) = v39;
      dds3Effect_PartialMultiBlurParam_t__SetData(*(*&v14[2 * v15++] + 40LL), Interface, pos, 0);
    }
    while (v8 != v15);
  }
  return v9;
}

// 0x1a42d40
void effPCPMultiBlurExpParam_t__pCopy(effPCPMultiBlurExpParam_t *this, u8 **bytedata, s32 *pos) {
  s32 v7;
  struct System_UInt32_array *v8;
  struct System_UInt32_array *v9;
  u32 v10;
  s32 v12;
  struct System_UInt32_array *blink_abgr;
  u32 v14;
  s32 v16;
  s32 v17;
  u64 *v18;

  v7 = *pos;
  this->blink = Byte2UInt32(bytedata, v7);
  *pos += 4;
  v8 = NewSpecific(uint, 2u);
  this->blink_abgr = v8;
  v9 = v8;
  v10 = Byte2UInt32(bytedata, *pos);
  v9->m_Items[0] = v10;
  v12 = *pos + 4;
  *pos = v12;
  blink_abgr = this->blink_abgr;
  v14 = Byte2UInt32(bytedata, v12);
  blink_abgr->m_Items[1] = v14;
  v16 = *pos + 4;
  *pos = v16;
  this->ratio = Byte2Float(bytedata, v16);
  v17 = *pos + 4;
  *pos = v17;
  this->area_min = Byte2UInt32(bytedata, v17);
  *pos += 4;
  v18 = Allocate(dds3Effect_PartialMultiBlurParam_t);
  dds3Effect_PartialMultiBlurParam_t___ctor(v18);
  this->MultiBlur = v18;
  dds3Effect_PartialMultiBlurParam_t__SetData(v18, bytedata, pos);
}

// 0x1a42ef0
effPCPMultiFilterExpParam_t **effPCPMultiFilterExpParam_t__pCopy(effPCPMultiFilterExpParam_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  u32 *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u32 *v14;
  u64 v15;
  u64 *v18;
  s64 v20;
  s32 v22;
  s64 v24;
  s32 v25;
  s64 v27;
  s32 v28;
  s64 v30;
  s32 v31;
  s64 v33;
  s32 v34;
  s64 v36;
  s64 v38;
  u64 *v39;
  u64 v42[3];

  v8 = max;
  v9 = NewSpecific(effPCPMultiFilterExpParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v42);
      if ((v42[0] & 1) != 0)
        v12 = v42[2];
      else
        v12 = v42 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = v9 + 8;
    v15 = 0;
    do
    {
      v18 = Allocate(effPCPMultiFilterExpParam_t);
      _ctor(v18, 0);
      *&v14[2 * v15] = v18;
      v20 = *pos;
      *(v18 + 16) = *(Interface + v20 + 32);
      v22 = *pos + 4;
      *pos = v22;
      v24 = *&v14[2 * v15];
      *(v24 + 20) = Byte2UInt32(Interface, v22);
      v25 = *pos + 4;
      *pos = v25;
      v27 = *&v14[2 * v15];
      *(v27 + 24) = Byte2UInt32(Interface, v25);
      v28 = *pos + 4;
      *pos = v28;
      v30 = *&v14[2 * v15];
      *(v30 + 28) = Byte2UInt32(Interface, v28);
      v31 = *pos + 4;
      *pos = v31;
      v33 = *&v14[2 * v15];
      *(v33 + 32) = Byte2UInt32(Interface, v31);
      v34 = *pos + 4;
      *pos = v34;
      v36 = *&v14[2 * v15];
      *(v36 + 36) = Byte2UInt32(Interface, v34);
      *pos += 4;
      v38 = *&v14[2 * v15];
      v39 = Allocate(dds3Effect_PartialMultiFilterParam_t);
      dds3Effect_PartialMultiFilterParam_t___ctor(v39);
      *(v38 + 40) = v39;
      dds3Effect_PartialMultiFilterParam_t__SetData(*(*&v14[2 * v15++] + 40LL), Interface, pos, 0);
    }
    while (v8 != v15);
  }
  return v9;
}

// 0x1a43300
effPCPMuzzleFlashParam_t **effPCPMuzzleFlashParam_t__pCopy(effPCPMuzzleFlashParam_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  u32 *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u32 *v14;
  u64 v15;
  u64 *v16;
  s32 v18;
  s32 v21;
  s64 v23;
  u64 v25[3];

  v8 = max;
  v9 = NewSpecific(effPCPMuzzleFlashParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v25);
      if ((v25[0] & 1) != 0)
        v12 = v25[2];
      else
        v12 = v25 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = v9 + 8;
    v15 = 0;
    do
    {
      v16 = Allocate(effPCPMuzzleFlashParam_t);
      _ctor(v16, 0);
      *&v14[2 * v15] = v16;
      v18 = *pos;
      *(v16 + 4) = Byte2Float(Interface, v18);
      v21 = *pos + 4;
      *pos = v21;
      v23 = *&v14[2 * v15];
      *(v23 + 20) = Byte2Float(Interface, v21);
      ++v15;
      *pos += 4;
    }
    while (v8 != v15);
  }
  return v9;
}

// 0x1a43e20
void effPCPNeedleSpiralParam_t__pClone(effPCPNeedleSpiralParam_t *this, effPCPNeedleSpiralParam_t **param) {
  f32 x;
  f32 y;
  effPCPNeedleSpiralParam_t_o *v5;
  f32 z;
  f32 w;
  f32 v10;
  f32 v11;
  struct System_UInt32_array *n_vc;
  struct System_UInt32_array *v13;
  u32 v14;
  struct System_UInt32_array *v15;
  struct System_UInt32_array *v16;
  u32 v18;
  s64 v22;
  s64 v23;

  x = this->pos.x;
  y = this->pos.y;
  v5 = *param;
  z = this->pos.z;
  w = this->pos.w;
  v22 = 0;
  v23 = 0;
  sub_854690(&v22, x, y, z, w);
  v11 = *&v23;
  v10 = *(&v23 + 1);
  *&v5->pos.x = v22;
  v5->pos.z = v11;
  v5->pos.w = v10;
  (*param)->number = this->number;
  (*param)->life = this->life;
  (*param)->blend = this->blend;
  (*param)->fade_in = this->fade_in;
  (*param)->fade_out = this->fade_out;
  (*param)->timing = this->timing;
  (*param)->speed = this->speed;
  (*param)->accele = this->accele;
  (*param)->radius = this->radius;
  (*param)->radius_r = this->radius_r;
  (*param)->roll_s = this->roll_s;
  (*param)->n_split = this->n_split;
  (*param)->n_radius = this->n_radius;
  (*param)->n_length = this->n_length;
  n_vc = this->n_vc;
  v13 = (*param)->n_vc;
  v14 = n_vc->m_Items[0];
  v13->m_Items[0] = v14;
  v15 = this->n_vc;
  v16 = (*param)->n_vc;
  v18 = v15->m_Items[1];
  v16->m_Items[1] = v18;
  (*param)->t_width = this->t_width;
  (*param)->t_length = this->t_length;
  (*param)->t_abgr = this->t_abgr;
}

// 0x1a43580
effPCPNeedleSpiralParam_t **effPCPNeedleSpiralParam_t__pCopy(effPCPNeedleSpiralParam_t *this, void *pData, s32 *pos, s32 max) {
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  u64 v12;
  il2cpp_array_size_t *p_max_length;
  u64 *v15;
  s64 v18;
  s32 v19;
  s32 v20;
  s64 v22;
  s32 v23;
  s64 v25;
  s32 v26;
  s64 v28;
  s32 v29;
  s64 v31;
  s32 v32;
  s64 v34;
  s32 v35;
  s64 v37;
  s32 v38;
  s64 v40;
  s32 v41;
  s64 v43;
  s32 v44;
  s64 v46;
  s32 v47;
  s64 v49;
  s32 v50;
  s64 v52;
  s32 v53;
  s64 v55;
  s32 v56;
  s64 v58;
  s32 v59;
  s64 v61;
  s32 v62;
  s64 v64;
  s32 v65;
  s64 v67;
  s32 v68;
  s64 v70;
  s32 v71;
  s64 v73;
  u32 v74;
  s32 v76;
  s64 v78;
  u32 v79;
  s32 v81;
  s64 v83;
  s32 v84;
  s64 v86;
  s32 v87;
  s64 v89;
  effPCPNeedleSpiralParam_t_array *v91;
  u64 v92[3];

  v91 = NewSpecific(effPCPNeedleSpiralParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v8, v92);
      if ((v92[0] & 1) != 0)
        v10 = v92[2];
      else
        v10 = v92 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v12 = 0;
    p_max_length = &v91->max_length;
    do
    {
      v15 = Allocate(effPCPNeedleSpiralParam_t);
      v15[11] = NewSpecific(uint, 2u);
      _ctor(v15, 0);
      v18 = &v91->m_Items[v12];
      *v18 = v15;
      v19 = *pos;
      *(v15 + 4) = Byte2Float(Interface, v19);
      v20 = *pos + 4;
      *pos = v20;
      v22 = *v18;
      *(v22 + 20) = Byte2Float(Interface, v20);
      v23 = *pos + 4;
      *pos = v23;
      v25 = *v18;
      *(v25 + 24) = Byte2Float(Interface, v23);
      v26 = *pos + 4;
      *pos = v26;
      v28 = *v18;
      *(v28 + 28) = Byte2Float(Interface, v26);
      v29 = *pos + 4;
      *pos = v29;
      v31 = *v18;
      *(v31 + 32) = Byte2UInt32(Interface, v29);
      v32 = *pos + 4;
      *pos = v32;
      v34 = *v18;
      *(v34 + 36) = Byte2UInt32(Interface, v32);
      v35 = *pos + 4;
      *pos = v35;
      v37 = *v18;
      *(v37 + 40) = Byte2UInt32(Interface, v35);
      v38 = *pos + 4;
      *pos = v38;
      v40 = *v18;
      *(v40 + 44) = Byte2UInt32(Interface, v38);
      v41 = *pos + 4;
      *pos = v41;
      v43 = *v18;
      *(v43 + 48) = Byte2UInt32(Interface, v41);
      v44 = *pos + 4;
      *pos = v44;
      v46 = *v18;
      *(v46 + 52) = Byte2UInt32(Interface, v44);
      v47 = *pos + 4;
      *pos = v47;
      v49 = *v18;
      *(v49 + 56) = Byte2Float(Interface, v47);
      v50 = *pos + 4;
      *pos = v50;
      v52 = *v18;
      *(v52 + 60) = Byte2Float(Interface, v50);
      v53 = *pos + 4;
      *pos = v53;
      v55 = *v18;
      *(v55 + 64) = Byte2Float(Interface, v53);
      v56 = *pos + 4;
      *pos = v56;
      v58 = *v18;
      *(v58 + 68) = Byte2Float(Interface, v56);
      v59 = *pos + 4;
      *pos = v59;
      v61 = *v18;
      *(v61 + 72) = Byte2Float(Interface, v59);
      v62 = *pos + 4;
      *pos = v62;
      v64 = *v18;
      *(v64 + 76) = Byte2UInt32(Interface, v62);
      v65 = *pos + 4;
      *pos = v65;
      v67 = *v18;
      *(v67 + 80) = Byte2Float(Interface, v65);
      v68 = *pos + 4;
      *pos = v68;
      v70 = *v18;
      *(v70 + 84) = Byte2Float(Interface, v68);
      v71 = *pos + 4;
      *pos = v71;
      v73 = *(*v18 + 88LL);
      v74 = Byte2UInt32(Interface, v71);
      *(v73 + 32) = v74;
      v76 = *pos + 4;
      *pos = v76;
      v78 = *(*v18 + 88LL);
      v79 = Byte2UInt32(Interface, v76);
      *(v78 + 36) = v79;
      v81 = *pos + 4;
      *pos = v81;
      v83 = *v18;
      *(v83 + 96) = Byte2Float(Interface, v81);
      v84 = *pos + 4;
      *pos = v84;
      v86 = *v18;
      *(v86 + 100) = Byte2UInt32(Interface, v84);
      v87 = *pos + 4;
      *pos = v87;
      v89 = *v18;
      *(v89 + 104) = Byte2UInt32(Interface, v87);
      ++v12;
      *pos += 4;
    }
    while (max != v12);
  }
  return v91;
}

// 0x1a43ff0
effPCPRadiateBEDParam_t **effPCPRadiateBEDParam_t__pCopy(effPCPRadiateBEDParam_t *this, void *pData, s32 *pos, s32 max) {
  effPCPRadiateBEDParam_t_array *v8;
  Il2CppClass *v9;
  s64 *Interface;
  char *v11;
  s64 *v12;
  u64 v13;
  il2cpp_array_size_t *p_max_length;
  u64 *v15;
  Il2CppClass **v17;
  char *v18;
  s32 v19;
  s32 v22;
  s64 v24;
  s32 v25;
  s64 v27;
  s32 v28;
  s64 v30;
  s32 v32;
  s64 v33;
  s64 v35;
  s32 v36;
  s64 v37;
  s32 v38;
  s64 v40;
  s32 v41;
  s64 v43;
  s32 v44;
  s64 v46;
  s32 v48;
  s64 v50;
  s32 v51;
  s64 v53;
  s32 v54;
  s64 v56;
  s32 v57;
  s64 v59;
  s32 v60;
  s64 v62;
  s32 v63;
  s64 v65;
  s32 v66;
  s64 v68;
  s32 v69;
  s64 v71;
  s32 v72;
  s64 v74;
  s32 v75;
  s64 v77;
  s32 v78;
  s64 v80;
  s32 v81;
  s64 v83;
  s64 v85;
  u64 v86;
  s32 v89;
  s64 v90;
  u32 v91;
  s64 v93;
  u64 v95[3];

  v8 = NewSpecific(effPCPRadiateBEDParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v9, v95);
      if ((v95[0] & 1) != 0)
        v11 = v95[2];
      else
        v11 = v95 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v13 = 0;
    p_max_length = &v8->max_length;
    do
    {
      v15 = Allocate(effPCPRadiateBEDParam_t);
      v15[19] = NewSpecific(uint, 0x20u);
      _ctor(v15, 0);
      v17 = &v8->obj.klass + v13;
      v17[4] = v15;
      v18 = (v17 + 4);
      v19 = *pos;
      *(v15 + 4) = Byte2Float(Interface, v19);
      v22 = *pos + 4;
      *pos = v22;
      v24 = *v18;
      *(v24 + 20) = Byte2Float(Interface, v22);
      v25 = *pos + 4;
      *pos = v25;
      v27 = *v18;
      *(v27 + 24) = Byte2Float(Interface, v25);
      v28 = *pos + 4;
      *pos = v28;
      v30 = *v18;
      *(v30 + 28) = Byte2Float(Interface, v28);
      v32 = 0;
      *pos += 4;
      if (v13 >= *p_max_length)
      {
LABEL_31:
      }
      while (1)
      {
        v35 = *v18;
        if (v32 == 4)
          break;
        v36 = *pos;
        v37 = v35 + 32;
        Byte2Float(Interface, v36);
        sub_19FFD30(v37, v32, 0);
        v38 = *pos + 4;
        *pos = v38;
        v40 = *v18 + 32LL;
        Byte2Float(Interface, v38);
        sub_19FFD30(v40, v32, 1);
        v41 = *pos + 4;
        *pos = v41;
        v43 = *v18 + 32LL;
        Byte2Float(Interface, v41);
        sub_19FFD30(v43, v32, 2);
        v44 = *pos + 4;
        *pos = v44;
        v33 = *v18 + 32LL;
        Byte2Float(Interface, v44);
        sub_19FFD30(v33, v32++, 3);
        *pos += 4;
        if (v13 >= *p_max_length)
          goto LABEL_31;
      }
      v46 = *pos;
      *(v35 + 96) = *(Interface + v46 + 32);
      v48 = *pos + 4;
      *pos = v48;
      v50 = *v18;
      *(v50 + 100) = Byte2UInt32(Interface, v48);
      v51 = *pos + 4;
      *pos = v51;
      v53 = *v18;
      *(v53 + 104) = Byte2UInt32(Interface, v51);
      v54 = *pos + 4;
      *pos = v54;
      v56 = *v18;
      *(v56 + 108) = Byte2UInt32(Interface, v54);
      v57 = *pos + 4;
      *pos = v57;
      v59 = *v18;
      *(v59 + 112) = Byte2UInt32(Interface, v57);
      v60 = *pos + 4;
      *pos = v60;
      v62 = *v18;
      *(v62 + 116) = Byte2UInt32(Interface, v60);
      v63 = *pos + 4;
      *pos = v63;
      v65 = *v18;
      *(v65 + 120) = Byte2Float(Interface, v63);
      v66 = *pos + 4;
      *pos = v66;
      v68 = *v18;
      *(v68 + 124) = Byte2Float(Interface, v66);
      v69 = *pos + 4;
      *pos = v69;
      v71 = *v18;
      *(v71 + 128) = Byte2Float(Interface, v69);
      v72 = *pos + 4;
      *pos = v72;
      v74 = *v18;
      *(v74 + 132) = Byte2Float(Interface, v72);
      v75 = *pos + 4;
      *pos = v75;
      v77 = *v18;
      *(v77 + 136) = Byte2Float(Interface, v75);
      v78 = *pos + 4;
      *pos = v78;
      v80 = *v18;
      *(v80 + 140) = Byte2Float(Interface, v78);
      v81 = *pos + 4;
      *pos = v81;
      v83 = *v18;
      *(v83 + 144) = Byte2Float(Interface, v81);
      *pos += 4;
      v85 = *v18;
      v86 = 0;
      *(v85 + 152) = NewSpecific(uint, 0x20u);
      do
      {
        v89 = *pos;
        v90 = *(*v18 + 152LL);
        v91 = Byte2UInt32(Interface, v89);
        v93 = v90 + 4 * v86++;
        *(v93 + 32) = v91;
        *pos += 4;
      }
      while (v86 != 32);
      ++v13;
    }
    while (v13 != max);
  }
  return v8;
}

// 0x1a44950
effPCPRadiateTBParam_t **effPCPRadiateTBParam_t__pCopy(effPCPRadiateTBParam_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  u32 *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u32 *v14;
  u64 v15;
  u64 *v16;
  s32 v18;
  s32 v21;
  s64 v23;
  s32 v24;
  s64 v26;
  s32 v27;
  s64 v29;
  s32 v30;
  s32 v33;
  s64 v35;
  s32 v36;
  s64 v38;
  s32 v39;
  s64 v41;
  s32 v42;
  s64 v44;
  s32 v45;
  s64 v47;
  s32 v48;
  s64 v50;
  s32 v51;
  s64 v53;
  s32 v54;
  s64 v56;
  s32 v57;
  s64 v59;
  u64 *v60;
  effPCP_ThunderPolyParam_t_o *v61;
  s32 v62;
  s64 v65;
  u64 v67[3];

  v8 = max;
  v9 = NewSpecific(effPCPRadiateTBParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v67);
      if ((v67[0] & 1) != 0)
        v12 = v67[2];
      else
        v12 = v67 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = v9 + 8;
    v15 = 0;
    do
    {
      v16 = Allocate(effPCPRadiateTBParam_t);
      _ctor(v16, 0);
      *&v14[2 * v15] = v16;
      v18 = *pos;
      *(v16 + 4) = Byte2Float(Interface, v18);
      v21 = *pos + 4;
      *pos = v21;
      v23 = *&v14[2 * v15];
      *(v23 + 20) = Byte2Float(Interface, v21);
      v24 = *pos + 4;
      *pos = v24;
      v26 = *&v14[2 * v15];
      *(v26 + 24) = Byte2Float(Interface, v24);
      v27 = *pos + 4;
      *pos = v27;
      v29 = *&v14[2 * v15];
      *(v29 + 28) = Byte2Float(Interface, v27);
      v30 = *pos + 4;
      *pos = v30;
      *(*&v14[2 * v15] + 32LL) = *(Interface + v30 + 32);
      v33 = *pos + 4;
      *pos = v33;
      v35 = *&v14[2 * v15];
      *(v35 + 36) = Byte2UInt32(Interface, v33);
      v36 = *pos + 4;
      *pos = v36;
      v38 = *&v14[2 * v15];
      *(v38 + 40) = Byte2UInt32(Interface, v36);
      v39 = *pos + 4;
      *pos = v39;
      v41 = *&v14[2 * v15];
      *(v41 + 44) = Byte2UInt32(Interface, v39);
      v42 = *pos + 4;
      *pos = v42;
      v44 = *&v14[2 * v15];
      *(v44 + 48) = Byte2UInt32(Interface, v42);
      v45 = *pos + 4;
      *pos = v45;
      v47 = *&v14[2 * v15];
      *(v47 + 52) = Byte2UInt32(Interface, v45);
      v48 = *pos + 4;
      *pos = v48;
      v50 = *&v14[2 * v15];
      *(v50 + 56) = Byte2Float(Interface, v48);
      v51 = *pos + 4;
      *pos = v51;
      v53 = *&v14[2 * v15];
      *(v53 + 60) = Byte2Float(Interface, v51);
      v54 = *pos + 4;
      *pos = v54;
      v56 = *&v14[2 * v15];
      *(v56 + 64) = Byte2Float(Interface, v54);
      v57 = *pos + 4;
      *pos = v57;
      v59 = *&v14[2 * v15];
      *(v59 + 68) = Byte2Float(Interface, v57);
      *pos += 4;
      v60 = Allocate(effPCP_ThunderPolyParam_t);
      _ctor(v60, 0);
      v65 = *&v14[2 * v15++];
      *(v65 + 72) = effPCP_ThunderPolyParam_t__pCopy(v61, Interface, pos, v62);
    }
    while (v8 != v15);
  }
  return v9;
}

// 0x1a44f40
effPCPRadiateThunderAttach_t **effPCPRadiateThunderAttach_t__pCopy(effPCPRadiateThunderAttach_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  s64 *v9;
  u32 *v10;
  Il2CppClass *v11;
  s64 *Interface;
  char *v13;
  s64 *v14;
  u64 v15;
  u32 *v16;
  Il2CppObject *v18;
  s64 *v20;
  s64 v21;
  Il2CppClass *klass;
  char v24;
  s32 v26;
  s64 v28;
  s32 v31;
  s64 v33;
  s32 v36;
  s64 v38;
  u64 v42[3];

  v8 = max;
  v9 = &byte;
  v10 = NewSpecific(effPCPRadiateThunderAttach_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v11, v42);
      if ((v42[0] & 1) != 0)
        v13 = v42[2];
      else
        v13 = v42 + 1;
      v14 = sub_8C4940(v13);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v15 = 0;
    v16 = v10 + 8;
    do
    {
      v18 = Allocate(effPCPRadiateThunderAttach_t);
      v18[1].klass = NewSpecific(*v9, 4u);
      _ctor(v18, 0);
      v20 = v9;
      *&v16[2 * v15] = v18;
      v21 = *pos;
      klass = v18[1].klass;
      v24 = *(Interface + v21 + 32);
      LOBYTE(klass->_1.byval_arg.data) = v24;
      v26 = *pos + 1;
      *pos = v26;
      v28 = *(*&v16[2 * v15] + 16LL);
      *(v28 + 33) = *(Interface + v26 + 32);
      v31 = *pos + 1;
      *pos = v31;
      v33 = *(*&v16[2 * v15] + 16LL);
      *(v33 + 34) = *(Interface + v31 + 32);
      v36 = *pos + 1;
      *pos = v36;
      v38 = *(*&v16[2 * v15] + 16LL);
      *(v38 + 35) = *(Interface + v36 + 32);
      ++v15;
      v9 = v20;
      ++*pos;
    }
    while (v8 != v15);
  }
  return v10;
}

// 0x1a45e70
void effPCPRadiateThunderParam_t__pClone(effPCPRadiateThunderParam_t *this, effPCPRadiateThunderParam_t **param) {
  f32 x;
  f32 y;
  effPCPRadiateThunderParam_t_o *v7;
  f32 z;
  f32 w;
  f32 v10;
  f32 v11;
  struct UnityEngine_Matrix4x4_o *p_matrix;
  struct UnityEngine_Matrix4x4_o *v13;
  struct UnityEngine_Matrix4x4_o *v14;
  struct UnityEngine_Matrix4x4_o *v15;
  struct UnityEngine_Matrix4x4_o *v16;
  struct UnityEngine_Matrix4x4_o *v17;
  struct UnityEngine_Matrix4x4_o *v18;
  struct UnityEngine_Matrix4x4_o *v19;
  struct UnityEngine_Matrix4x4_o *v20;
  struct UnityEngine_Matrix4x4_o *v21;
  struct UnityEngine_Matrix4x4_o *v22;
  struct UnityEngine_Matrix4x4_o *v23;
  struct UnityEngine_Matrix4x4_o *v24;
  struct UnityEngine_Matrix4x4_o *v25;
  struct UnityEngine_Matrix4x4_o *v26;
  struct UnityEngine_Matrix4x4_o *v27;
  effPCPRadiateThunderParam_t_o *v28;
  u64 *v29;
  effPCPRadiateThunderParam_t_o *v31;
  s64 i;
  struct System_UInt32_array *reserve;
  struct System_UInt32_array *v34;
  s32 v35;
  s64 v38;
  s64 v39;

  x = this->pos.x;
  y = this->pos.y;
  v7 = *param;
  z = this->pos.z;
  w = this->pos.w;
  v38 = 0;
  v39 = 0;
  sub_854690(&v38, x, y, z, w);
  v11 = *&v39;
  v10 = *(&v39 + 1);
  *&v7->pos.x = v38;
  v7->pos.z = v11;
  v7->pos.w = v10;
  p_matrix = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 0, 0);
  sub_19FFD30(p_matrix, 0, 0);
  v13 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 0, 1);
  sub_19FFD30(v13, 0, 1);
  v14 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 0, 2);
  sub_19FFD30(v14, 0, 2);
  v15 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 0, 3);
  sub_19FFD30(v15, 0, 3);
  v16 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 1, 0);
  sub_19FFD30(v16, 1, 0);
  v17 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 1, 1);
  sub_19FFD30(v17, 1, 1);
  v18 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 1, 2);
  sub_19FFD30(v18, 1, 2);
  v19 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 1, 3);
  sub_19FFD30(v19, 1, 3);
  v20 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 2, 0);
  sub_19FFD30(v20, 2, 0);
  v21 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 2, 1);
  sub_19FFD30(v21, 2, 1);
  v22 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 2, 2);
  sub_19FFD30(v22, 2, 2);
  v23 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 2, 3);
  sub_19FFD30(v23, 2, 3);
  v24 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 3, 0);
  sub_19FFD30(v24, 3, 0);
  v25 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 3, 1);
  sub_19FFD30(v25, 3, 1);
  v26 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 3, 2);
  sub_19FFD30(v26, 3, 2);
  v27 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 3, 3);
  sub_19FFD30(v27, 3, 3);
  (*param)->loop = this->loop;
  (*param)->life = this->life;
  (*param)->number = this->number;
  (*param)->timing = this->timing;
  (*param)->fade_in = this->fade_in;
  (*param)->fade_out = this->fade_out;
  (*param)->radius_s = this->radius_s;
  (*param)->radius_e = this->radius_e;
  (*param)->radius_s_r = this->radius_s_r;
  (*param)->radius_e_r = this->radius_e_r;
  (*param)->radian_s = this->radian_s;
  (*param)->radian_a = this->radian_a;
  (*param)->radian_r = this->radian_r;
  (*param)->spread_s = this->spread_s;
  (*param)->spread_e = this->spread_e;
  (*param)->attach = this->attach;
  v28 = *param;
  v29 = Allocate(effPCP_ThunderPolyParam_t);
  _ctor(v29, 0);
  v28->ThunderParam = v29;
  effPCP_ThunderPolyParam_t__pClone(this->ThunderParam, &(*param)->ThunderParam);
  v31 = *param;
  v31->reserve = NewSpecific(uint, 0x20u);
  for (i = 8; i != 40; ++i)
  {
    reserve = this->reserve;
    v34 = (*param)->reserve;
    v35 = *(&reserve->obj.klass + i);
    *(&v34->obj.klass + i) = v35;
  }
}

// 0x1a45390
effPCPRadiateThunderParam_t **effPCPRadiateThunderParam_t__pCopy(effPCPRadiateThunderParam_t *this, void *pData, s32 *pos, s32 max) {
  effPCPRadiateThunderParam_t_array *v8;
  Il2CppClass *v9;
  s64 *Interface;
  char *v11;
  s64 *v12;
  u64 v13;
  il2cpp_array_size_t *p_max_length;
  u64 *v15;
  Il2CppClass **v17;
  char *v18;
  s32 v19;
  s32 v22;
  s64 v24;
  s32 v25;
  s64 v27;
  s32 v28;
  s64 v30;
  s32 v32;
  s64 v33;
  s64 v35;
  s32 v36;
  s64 v37;
  s32 v38;
  s64 v40;
  s32 v41;
  s64 v43;
  s32 v44;
  s64 v46;
  s32 v48;
  s64 v50;
  s32 v51;
  s64 v53;
  s32 v54;
  s64 v56;
  s32 v57;
  s64 v59;
  s32 v60;
  s64 v62;
  s32 v63;
  s64 v65;
  s32 v66;
  s64 v68;
  s32 v69;
  s64 v71;
  s32 v72;
  s64 v74;
  s32 v75;
  s64 v77;
  s32 v78;
  s64 v80;
  s32 v81;
  s64 v83;
  s32 v84;
  s64 v86;
  s32 v87;
  s64 v89;
  Il2CppObject *v90;
  effPCPRadiateThunderAttach_t_o *v91;
  s64 v94;
  effPCPRadiateThunderAttach_t_array *v95;
  u64 *v97;
  effPCP_ThunderPolyParam_t_o *v98;
  s32 v99;
  s64 v102;
  s64 v104;
  u64 v105;
  s32 v108;
  s64 v109;
  u32 v110;
  s64 v112;
  s64 v114;
  u64 v115[3];

  v114 = max;
  v8 = NewSpecific(effPCPRadiateThunderParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v9, v115);
      if ((v115[0] & 1) != 0)
        v11 = v115[2];
      else
        v11 = v115 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v13 = 0;
    p_max_length = &v8->max_length;
    do
    {
      v15 = Allocate(effPCPRadiateThunderParam_t);
      v15[22] = NewSpecific(uint, 0x20u);
      _ctor(v15, 0);
      v17 = &v8->obj.klass + v13;
      v17[4] = v15;
      v18 = (v17 + 4);
      v19 = *pos;
      *(v15 + 4) = Byte2Float(Interface, v19);
      v22 = *pos + 4;
      *pos = v22;
      v24 = *v18;
      *(v24 + 20) = Byte2Float(Interface, v22);
      v25 = *pos + 4;
      *pos = v25;
      v27 = *v18;
      *(v27 + 24) = Byte2Float(Interface, v25);
      v28 = *pos + 4;
      *pos = v28;
      v30 = *v18;
      *(v30 + 28) = Byte2Float(Interface, v28);
      v32 = 0;
      *pos += 4;
      if (v13 >= *p_max_length)
      {
LABEL_31:
      }
      while (1)
      {
        v35 = *v18;
        if (v32 == 4)
          break;
        v36 = *pos;
        v37 = v35 + 32;
        Byte2Float(Interface, v36);
        sub_19FFD30(v37, v32, 0);
        v38 = *pos + 4;
        *pos = v38;
        v40 = *v18 + 32LL;
        Byte2Float(Interface, v38);
        sub_19FFD30(v40, v32, 1);
        v41 = *pos + 4;
        *pos = v41;
        v43 = *v18 + 32LL;
        Byte2Float(Interface, v41);
        sub_19FFD30(v43, v32, 2);
        v44 = *pos + 4;
        *pos = v44;
        v33 = *v18 + 32LL;
        Byte2Float(Interface, v44);
        sub_19FFD30(v33, v32++, 3);
        *pos += 4;
        if (v13 >= *p_max_length)
          goto LABEL_31;
      }
      v46 = *pos;
      *(v35 + 96) = *(Interface + v46 + 32);
      v48 = *pos + 4;
      *pos = v48;
      v50 = *v18;
      *(v50 + 100) = Byte2UInt32(Interface, v48);
      v51 = *pos + 4;
      *pos = v51;
      v53 = *v18;
      *(v53 + 104) = Byte2UInt32(Interface, v51);
      v54 = *pos + 4;
      *pos = v54;
      v56 = *v18;
      *(v56 + 108) = Byte2UInt32(Interface, v54);
      v57 = *pos + 4;
      *pos = v57;
      v59 = *v18;
      *(v59 + 112) = Byte2UInt32(Interface, v57);
      v60 = *pos + 4;
      *pos = v60;
      v62 = *v18;
      *(v62 + 116) = Byte2UInt32(Interface, v60);
      v63 = *pos + 4;
      *pos = v63;
      v65 = *v18;
      *(v65 + 120) = Byte2Float(Interface, v63);
      v66 = *pos + 4;
      *pos = v66;
      v68 = *v18;
      *(v68 + 124) = Byte2Float(Interface, v66);
      v69 = *pos + 4;
      *pos = v69;
      v71 = *v18;
      *(v71 + 128) = Byte2Float(Interface, v69);
      v72 = *pos + 4;
      *pos = v72;
      v74 = *v18;
      *(v74 + 132) = Byte2Float(Interface, v72);
      v75 = *pos + 4;
      *pos = v75;
      v77 = *v18;
      *(v77 + 136) = Byte2Float(Interface, v75);
      v78 = *pos + 4;
      *pos = v78;
      v80 = *v18;
      *(v80 + 140) = Byte2Float(Interface, v78);
      v81 = *pos + 4;
      *pos = v81;
      v83 = *v18;
      *(v83 + 144) = Byte2Float(Interface, v81);
      v84 = *pos + 4;
      *pos = v84;
      v86 = *v18;
      *(v86 + 148) = Byte2Float(Interface, v84);
      v87 = *pos + 4;
      *pos = v87;
      v89 = *v18;
      *(v89 + 152) = Byte2Float(Interface, v87);
      *pos += 4;
      v90 = Allocate(effPCPRadiateThunderAttach_t);
      v90[1].klass = NewSpecific(byte, 4u);
      _ctor(v90, 0);
      v94 = *v18;
      v95 = effPCPRadiateThunderAttach_t__pCopy(v91, Interface, pos, 1);
      *(v94 + 160) = v95->m_Items[0];
      v97 = Allocate(effPCP_ThunderPolyParam_t);
      _ctor(v97, 0);
      v102 = *v18;
      *(v102 + 168) = effPCP_ThunderPolyParam_t__pCopy(v98, Interface, pos, v99);
      v104 = *v18;
      v105 = 0;
      *(v104 + 176) = NewSpecific(uint, 0x20u);
      do
      {
        v108 = *pos;
        v109 = *(*v18 + 176LL);
        v110 = Byte2UInt32(Interface, v108);
        v112 = v109 + 4 * v105++;
        *(v112 + 32) = v110;
        *pos += 4;
      }
      while (v105 != 32);
      ++v13;
    }
    while (v13 != v114);
  }
  return v8;
}

// 0x1a46390
effPCPRingPolyExp2Param_t **effPCPRingPolyExp2Param_t__pCopy(effPCPRingPolyExp2Param_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  effPCPRingPolyExp2Param_t_array *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u64 v14;
  il2cpp_array_size_t *p_max_length;
  u64 *v17;
  s64 v20;
  s32 v21;
  s32 v22;
  s64 v24;
  s32 v25;
  s64 v27;
  s32 v28;
  s64 v30;
  s32 v31;
  s64 v33;
  s32 v34;
  s64 v36;
  s32 v37;
  s64 v39;
  s32 v40;
  s64 v42;
  s32 v43;
  s32 v46;
  s64 v48;
  s32 v49;
  s64 v51;
  s32 v52;
  s64 v54;
  s32 v55;
  s64 v57;
  s32 v58;
  s64 v60;
  s32 v61;
  s64 v63;
  s32 v64;
  s64 v66;
  s32 v67;
  s64 v69;
  s32 v70;
  s64 v72;
  s32 v73;
  s64 v75;
  s32 v76;
  s64 v78;
  s32 v79;
  s64 v81;
  s32 v82;
  s64 v84;
  s32 v85;
  s64 v87;
  u64 v89[3];

  v8 = max;
  v9 = NewSpecific(effPCPRingPolyExp2Param_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v89);
      if ((v89[0] & 1) != 0)
        v12 = v89[2];
      else
        v12 = v89 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = 0;
    p_max_length = &v9->max_length;
    do
    {
      v17 = Allocate(effPCPRingPolyExp2Param_t);
      _ctor(v17, 0);
      v20 = &v9->m_Items[v14];
      *v20 = v17;
      v21 = *pos;
      *(v17 + 4) = Byte2Float(Interface, v21);
      v22 = *pos + 4;
      *pos = v22;
      v24 = *v20;
      *(v24 + 20) = Byte2Float(Interface, v22);
      v25 = *pos + 4;
      *pos = v25;
      v27 = *v20;
      *(v27 + 24) = Byte2Float(Interface, v25);
      v28 = *pos + 4;
      *pos = v28;
      v30 = *v20;
      *(v30 + 28) = Byte2Float(Interface, v28);
      v31 = *pos + 4;
      *pos = v31;
      v33 = *v20;
      *(v33 + 32) = Byte2Float(Interface, v31);
      v34 = *pos + 4;
      *pos = v34;
      v36 = *v20;
      *(v36 + 36) = Byte2Float(Interface, v34);
      v37 = *pos + 4;
      *pos = v37;
      v39 = *v20;
      *(v39 + 40) = Byte2Float(Interface, v37);
      v40 = *pos + 4;
      *pos = v40;
      v42 = *v20;
      *(v42 + 44) = Byte2Float(Interface, v40);
      v43 = *pos + 4;
      *pos = v43;
      *(*v20 + 48LL) = *(Interface + v43 + 32);
      v46 = *pos + 4;
      *pos = v46;
      v48 = *v20;
      *(v48 + 52) = Byte2UInt32(Interface, v46);
      v49 = *pos + 4;
      *pos = v49;
      v51 = *v20;
      *(v51 + 56) = Byte2UInt32(Interface, v49);
      v52 = *pos + 4;
      *pos = v52;
      v54 = *v20;
      *(v54 + 60) = Byte2UInt32(Interface, v52);
      v55 = *pos + 4;
      *pos = v55;
      v57 = *v20;
      *(v57 + 64) = Byte2Float(Interface, v55);
      v58 = *pos + 4;
      *pos = v58;
      v60 = *v20;
      *(v60 + 68) = Byte2Float(Interface, v58);
      v61 = *pos + 4;
      *pos = v61;
      v63 = *v20;
      *(v63 + 72) = Byte2Float(Interface, v61);
      v64 = *pos + 4;
      *pos = v64;
      v66 = *v20;
      *(v66 + 76) = Byte2UInt32(Interface, v64);
      v67 = *pos + 4;
      *pos = v67;
      v69 = *v20;
      *(v69 + 80) = Byte2UInt32(Interface, v67);
      v70 = *pos + 4;
      *pos = v70;
      v72 = *v20;
      *(v72 + 84) = Byte2Float(Interface, v70);
      v73 = *pos + 4;
      *pos = v73;
      v75 = *v20;
      *(v75 + 88) = Byte2UInt32(Interface, v73);
      v76 = *pos + 4;
      *pos = v76;
      v78 = *v20;
      *(v78 + 92) = Byte2Float(Interface, v76);
      v79 = *pos + 4;
      *pos = v79;
      v81 = *v20;
      *(v81 + 96) = Byte2UInt32(Interface, v79);
      v82 = *pos + 4;
      *pos = v82;
      v84 = *v20;
      *(v84 + 100) = Byte2Float(Interface, v82);
      v85 = *pos + 4;
      *pos = v85;
      v87 = *v20;
      *(v87 + 104) = Byte2UInt32(Interface, v85);
      ++v14;
      *pos += 4;
    }
    while (v8 != v14);
  }
  return v9;
}

// 0x1a46b60
effPCPRingPolyExpParam_t **effPCPRingPolyExpParam_t__pCopy(effPCPRingPolyExpParam_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  effPCPRingPolyExpParam_t_array *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u64 v14;
  il2cpp_array_size_t *p_max_length;
  u64 *v17;
  u64 **v20;
  s32 v21;
  s32 v22;
  u64 *v24;
  s32 v25;
  u64 *v27;
  s32 v28;
  u64 *v30;
  s32 v31;
  u64 *v33;
  s32 v34;
  u64 *v36;
  s32 v37;
  u64 *v39;
  s32 v40;
  u64 *v42;
  s32 v43;
  u64 *v45;
  s32 v46;
  u64 *v48;
  s32 v49;
  u64 *v51;
  s32 v52;
  u64 *v54;
  s32 v55;
  u64 *v57;
  s32 v58;
  u64 *v60;
  s32 v61;
  u64 *v63;
  s32 v64;
  u64 *v66;
  s32 v67;
  u64 *v69;
  s32 v70;
  u64 *v72;
  s32 v73;
  u64 *v75;
  s32 v76;
  u64 *v78;
  u64 v80[3];

  v8 = max;
  v9 = NewSpecific(effPCPRingPolyExpParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v80);
      if ((v80[0] & 1) != 0)
        v12 = v80[2];
      else
        v12 = v80 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = 0;
    p_max_length = &v9->max_length;
    do
    {
      v17 = Allocate(effPCPRingPolyExpParam_t);
      _ctor(v17, 0);
      v20 = &v9->m_Items[v14];
      *v20 = v17;
      v21 = *pos;
      *(v17 + 4) = Byte2Float(Interface, v21);
      v22 = *pos + 4;
      *pos = v22;
      v24 = *v20;
      *(v24 + 5) = Byte2Float(Interface, v22);
      v25 = *pos + 4;
      *pos = v25;
      v27 = *v20;
      *(v27 + 6) = Byte2Float(Interface, v25);
      v28 = *pos + 4;
      *pos = v28;
      v30 = *v20;
      *(v30 + 7) = Byte2Float(Interface, v28);
      v31 = *pos + 4;
      *pos = v31;
      v33 = *v20;
      *(v33 + 8) = Byte2UInt32(Interface, v31);
      v34 = *pos + 4;
      *pos = v34;
      v36 = *v20;
      *(v36 + 9) = Byte2UInt32(Interface, v34);
      v37 = *pos + 4;
      *pos = v37;
      v39 = *v20;
      *(v39 + 10) = Byte2UInt32(Interface, v37);
      v40 = *pos + 4;
      *pos = v40;
      v42 = *v20;
      *(v42 + 11) = Byte2UInt32(Interface, v40);
      v43 = *pos + 4;
      *pos = v43;
      v45 = *v20;
      *(v45 + 12) = Byte2UInt32(Interface, v43);
      v46 = *pos + 4;
      *pos = v46;
      v48 = *v20;
      *(v48 + 13) = Byte2UInt32(Interface, v46);
      v49 = *pos + 4;
      *pos = v49;
      v51 = *v20;
      *(v51 + 14) = Byte2Float(Interface, v49);
      v52 = *pos + 4;
      *pos = v52;
      v54 = *v20;
      *(v54 + 15) = Byte2Float(Interface, v52);
      v55 = *pos + 4;
      *pos = v55;
      v57 = *v20;
      *(v57 + 16) = Byte2UInt32(Interface, v55);
      v58 = *pos + 4;
      *pos = v58;
      v60 = *v20;
      *(v60 + 17) = Byte2UInt32(Interface, v58);
      v61 = *pos + 4;
      *pos = v61;
      v63 = *v20;
      *(v63 + 18) = Byte2Float(Interface, v61);
      v64 = *pos + 4;
      *pos = v64;
      v66 = *v20;
      *(v66 + 19) = Byte2UInt32(Interface, v64);
      v67 = *pos + 4;
      *pos = v67;
      v69 = *v20;
      *(v69 + 20) = Byte2Float(Interface, v67);
      v70 = *pos + 4;
      *pos = v70;
      v72 = *v20;
      *(v72 + 21) = Byte2UInt32(Interface, v70);
      v73 = *pos + 4;
      *pos = v73;
      v75 = *v20;
      *(v75 + 22) = Byte2Float(Interface, v73);
      v76 = *pos + 4;
      *pos = v76;
      v78 = *v20;
      *(v78 + 23) = Byte2UInt32(Interface, v76);
      ++v14;
      *pos += 4;
    }
    while (v8 != v14);
  }
  return v9;
}

// 0x1a47250
effPCPRippleBlurExpParam_t **effPCPRippleBlurExpParam_t__pCopy(effPCPRippleBlurExpParam_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  u32 *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u32 *v14;
  u64 v15;
  u64 *v18;
  s64 v20;
  s32 v22;
  s64 v24;
  s32 v25;
  s64 v27;
  s32 v28;
  s64 v30;
  s32 v31;
  s64 v33;
  s32 v34;
  s64 v36;
  s64 v38;
  u64 *v39;
  u64 v42[3];

  v8 = max;
  v9 = NewSpecific(effPCPRippleBlurExpParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v42);
      if ((v42[0] & 1) != 0)
        v12 = v42[2];
      else
        v12 = v42 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = v9 + 8;
    v15 = 0;
    do
    {
      v18 = Allocate(effPCPRippleBlurExpParam_t);
      _ctor(v18, 0);
      *&v14[2 * v15] = v18;
      v20 = *pos;
      *(v18 + 16) = *(Interface + v20 + 32);
      v22 = *pos + 4;
      *pos = v22;
      v24 = *&v14[2 * v15];
      *(v24 + 20) = Byte2UInt32(Interface, v22);
      v25 = *pos + 4;
      *pos = v25;
      v27 = *&v14[2 * v15];
      *(v27 + 24) = Byte2UInt32(Interface, v25);
      v28 = *pos + 4;
      *pos = v28;
      v30 = *&v14[2 * v15];
      *(v30 + 28) = Byte2UInt32(Interface, v28);
      v31 = *pos + 4;
      *pos = v31;
      v33 = *&v14[2 * v15];
      *(v33 + 32) = Byte2UInt32(Interface, v31);
      v34 = *pos + 4;
      *pos = v34;
      v36 = *&v14[2 * v15];
      *(v36 + 36) = Byte2UInt32(Interface, v34);
      *pos += 4;
      v38 = *&v14[2 * v15];
      v39 = Allocate(dds3Effect_RippleBlurParam_t);
      dds3Effect_RippleBlurParam_t___ctor(v39);
      *(v38 + 40) = v39;
      dds3Effect_RippleBlurParam_t__SetData(*(*&v14[2 * v15++] + 40LL), Interface, pos, 0);
    }
    while (v8 != v15);
  }
  return v9;
}

// 0x1a47660
effPCPScreenCrackModelParam_t **effPCPScreenCrackModelParam_t__pCopy(effPCPScreenCrackModelParam_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  u32 *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u64 v14;
  u64 *v15;
  s32 v17;
  u64 v21[3];

  v8 = max;
  v9 = NewSpecific(effPCPScreenCrackModelParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v21);
      if ((v21[0] & 1) != 0)
        v12 = v21[2];
      else
        v12 = v21 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = 0;
    do
    {
      v15 = Allocate(effPCPScreenCrackModelParam_t);
      _ctor(v15, 0);
      *&v9[2 * v14 + 8] = v15;
      v17 = *pos;
      *(v15 + 4) = Byte2Float(Interface, v17);
      ++v14;
      *pos += 4;
    }
    while (v8 != v14);
  }
  return v9;
}

// 0x1a478c0
effPCPSpiralBEDParam_t **effPCPSpiralBEDParam_t__pCopy(effPCPSpiralBEDParam_t *this, void *pData, s32 *pos, s32 max) {
  effPCPSpiralBEDParam_t_array *v8;
  Il2CppClass *v9;
  s64 *Interface;
  char *v11;
  s64 *v12;
  u64 v13;
  il2cpp_array_size_t *p_max_length;
  u64 *v15;
  Il2CppClass **v17;
  s64 *v18;
  s32 v19;
  s32 v22;
  s64 v24;
  s32 v25;
  s64 v27;
  s32 v28;
  s64 v30;
  s32 v32;
  s64 v33;
  s64 v35;
  s32 v36;
  s64 v37;
  s32 v38;
  s64 v40;
  s32 v41;
  s64 v43;
  s32 v44;
  s64 v46;
  s32 v48;
  s64 v50;
  s32 v51;
  s64 v53;
  s32 v54;
  s64 v56;
  s32 v57;
  s64 v59;
  s32 v60;
  s64 v62;
  s32 v63;
  s64 v65;
  s32 v66;
  s64 v68;
  s32 v69;
  s64 v71;
  s32 v72;
  s64 v74;
  s32 v75;
  s64 v77;
  s32 v78;
  s64 v80;
  s32 v81;
  s64 v83;
  s32 v84;
  s64 v86;
  s32 v87;
  s64 v89;
  s32 v90;
  s64 v92;
  s64 v94;
  u64 v95[3];

  v94 = max;
  v8 = NewSpecific(effPCPSpiralBEDParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v9, v95);
      if ((v95[0] & 1) != 0)
        v11 = v95[2];
      else
        v11 = v95 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v13 = 0;
    p_max_length = &v8->max_length;
    do
    {
      v15 = Allocate(effPCPSpiralBEDParam_t);
      _ctor(v15, 0);
      v17 = &v8->obj.klass + v13;
      v17[4] = v15;
      v18 = (v17 + 4);
      v19 = *pos;
      *(v15 + 4) = Byte2Float(Interface, v19);
      v22 = *pos + 4;
      *pos = v22;
      v24 = *v18;
      *(v24 + 20) = Byte2Float(Interface, v22);
      v25 = *pos + 4;
      *pos = v25;
      v27 = *v18;
      *(v27 + 24) = Byte2Float(Interface, v25);
      v28 = *pos + 4;
      *pos = v28;
      v30 = *v18;
      *(v30 + 28) = Byte2Float(Interface, v28);
      v32 = 0;
      *pos += 4;
      if (v13 >= *p_max_length)
      {
LABEL_29:
      }
      while (1)
      {
        v35 = *v18;
        if (v32 == 4)
          break;
        v36 = *pos;
        v37 = v35 + 32;
        Byte2Float(Interface, v36);
        sub_19FFD30(v37, v32, 0);
        v38 = *pos + 4;
        *pos = v38;
        v40 = *v18 + 32;
        Byte2Float(Interface, v38);
        sub_19FFD30(v40, v32, 1);
        v41 = *pos + 4;
        *pos = v41;
        v43 = *v18 + 32;
        Byte2Float(Interface, v41);
        sub_19FFD30(v43, v32, 2);
        v44 = *pos + 4;
        *pos = v44;
        v33 = *v18 + 32;
        Byte2Float(Interface, v44);
        sub_19FFD30(v33, v32++, 3);
        *pos += 4;
        if (v13 >= *p_max_length)
          goto LABEL_29;
      }
      v46 = *pos;
      *(v35 + 96) = *(Interface + v46 + 32);
      v48 = *pos + 4;
      *pos = v48;
      v50 = *v18;
      *(v50 + 100) = Byte2UInt32(Interface, v48);
      v51 = *pos + 4;
      *pos = v51;
      v53 = *v18;
      *(v53 + 104) = Byte2UInt32(Interface, v51);
      v54 = *pos + 4;
      *pos = v54;
      v56 = *v18;
      *(v56 + 108) = Byte2UInt32(Interface, v54);
      v57 = *pos + 4;
      *pos = v57;
      v59 = *v18;
      *(v59 + 112) = Byte2UInt32(Interface, v57);
      v60 = *pos + 4;
      *pos = v60;
      v62 = *v18;
      *(v62 + 116) = Byte2UInt32(Interface, v60);
      v63 = *pos + 4;
      *pos = v63;
      v65 = *v18;
      *(v65 + 120) = Byte2Float(Interface, v63);
      v66 = *pos + 4;
      *pos = v66;
      v68 = *v18;
      *(v68 + 124) = Byte2Float(Interface, v66);
      v69 = *pos + 4;
      *pos = v69;
      v71 = *v18;
      *(v71 + 128) = Byte2Float(Interface, v69);
      v72 = *pos + 4;
      *pos = v72;
      v74 = *v18;
      *(v74 + 132) = Byte2Float(Interface, v72);
      v75 = *pos + 4;
      *pos = v75;
      v77 = *v18;
      *(v77 + 136) = Byte2Float(Interface, v75);
      v78 = *pos + 4;
      *pos = v78;
      v80 = *v18;
      *(v80 + 140) = Byte2Float(Interface, v78);
      v81 = *pos + 4;
      *pos = v81;
      v83 = *v18;
      *(v83 + 144) = Byte2Float(Interface, v81);
      v84 = *pos + 4;
      *pos = v84;
      v86 = *v18;
      *(v86 + 148) = Byte2Float(Interface, v84);
      v87 = *pos + 4;
      *pos = v87;
      v89 = *v18;
      *(v89 + 152) = Byte2Float(Interface, v87);
      v90 = *pos + 4;
      *pos = v90;
      v92 = *v18;
      *(v92 + 156) = Byte2Float(Interface, v90);
      *pos += 4;
      ++v13;
    }
    while (v13 != v94);
  }
  return v8;
}

// 0x1a48170
effPCPThunderSphereExpParam_t **effPCPThunderSphereExpParam_t__pCopy(effPCPThunderSphereExpParam_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  u32 *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u32 *v14;
  u64 v15;
  u64 *v16;
  s32 v18;
  s32 v21;
  s64 v23;
  s32 v24;
  s64 v26;
  s32 v27;
  s64 v29;
  s32 v30;
  s64 v32;
  u64 *v33;
  effPCPThunderSpherePolyParam_t_o *v34;
  s64 v37;
  effPCPThunderSpherePolyParam_t_array *v38;
  u64 v41[3];

  v8 = max;
  v9 = NewSpecific(effPCPThunderSphereExpParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v41);
      if ((v41[0] & 1) != 0)
        v12 = v41[2];
      else
        v12 = v41 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = v9 + 8;
    v15 = 0;
    do
    {
      v16 = Allocate(effPCPThunderSphereExpParam_t);
      _ctor(v16, 0);
      *&v14[2 * v15] = v16;
      v18 = *pos;
      *(v16 + 4) = Byte2UInt32(Interface, v18);
      v21 = *pos + 4;
      *pos = v21;
      v23 = *&v14[2 * v15];
      *(v23 + 20) = Byte2UInt32(Interface, v21);
      v24 = *pos + 4;
      *pos = v24;
      v26 = *&v14[2 * v15];
      *(v26 + 24) = Byte2UInt32(Interface, v24);
      v27 = *pos + 4;
      *pos = v27;
      v29 = *&v14[2 * v15];
      *(v29 + 28) = Byte2UInt32(Interface, v27);
      v30 = *pos + 4;
      *pos = v30;
      v32 = *&v14[2 * v15];
      *(v32 + 32) = Byte2UInt32(Interface, v30);
      *pos += 4;
      v33 = Allocate(effPCPThunderSpherePolyParam_t);
      _ctor(v33, 0);
      v37 = *&v14[2 * v15];
      v38 = effPCPThunderSpherePolyParam_t__pCopy(v34, Interface, pos, 1);
      ++v15;
      *(v37 + 40) = v38->m_Items[0];
    }
    while (v8 != v15);
  }
  return v9;
}

// 0x1a48c20
void effPCPThunderSpherePolyParam_t__pClone(effPCPThunderSpherePolyParam_t *this, effPCPThunderSpherePolyParam_t **param) {
  (*param)->fields = this->fields;
}

// 0x1a48530
effPCPThunderSpherePolyParam_t **effPCPThunderSpherePolyParam_t__pCopy(effPCPThunderSpherePolyParam_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  u32 *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u64 v14;
  u64 *v15;
  s64 v17;
  s32 v18;
  s32 v21;
  s64 v23;
  s32 v24;
  s64 v26;
  s32 v27;
  s64 v29;
  s32 v30;
  s64 v32;
  s32 v33;
  s64 v35;
  s32 v36;
  s32 v39;
  s64 v41;
  s32 v42;
  s64 v44;
  s32 v45;
  s64 v47;
  s32 v48;
  s64 v50;
  s32 v51;
  s64 v53;
  s32 v54;
  s64 v56;
  s32 v57;
  s64 v59;
  s32 v60;
  s64 v62;
  s32 v63;
  s64 v65;
  s32 v66;
  s64 v68;
  s32 v69;
  s64 v71;
  s32 v72;
  s64 v74;
  u64 v76[3];

  v8 = max;
  v9 = NewSpecific(effPCPThunderSpherePolyParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v76);
      if ((v76[0] & 1) != 0)
        v12 = v76[2];
      else
        v12 = v76 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = 0;
    do
    {
      v15 = Allocate(effPCPThunderSpherePolyParam_t);
      _ctor(v15, 0);
      v17 = &v9[2 * v14 + 8];
      *v17 = v15;
      v18 = *pos;
      *(v15 + 4) = Byte2Float(Interface, v18);
      v21 = *pos + 4;
      *pos = v21;
      v23 = *v17;
      *(v23 + 20) = Byte2Float(Interface, v21);
      v24 = *pos + 4;
      *pos = v24;
      v26 = *v17;
      *(v26 + 24) = Byte2Float(Interface, v24);
      v27 = *pos + 4;
      *pos = v27;
      v29 = *v17;
      *(v29 + 28) = Byte2Float(Interface, v27);
      v30 = *pos + 4;
      *pos = v30;
      v32 = *v17;
      *(v32 + 32) = Byte2UInt32(Interface, v30);
      v33 = *pos + 4;
      *pos = v33;
      v35 = *v17;
      *(v35 + 36) = Byte2UInt32(Interface, v33);
      v36 = *pos + 4;
      *pos = v36;
      *(*v17 + 40LL) = *(Interface + v36 + 32);
      v39 = *pos + 4;
      *pos = v39;
      v41 = *v17;
      *(v41 + 44) = Byte2Float(Interface, v39);
      v42 = *pos + 4;
      *pos = v42;
      v44 = *v17;
      *(v44 + 48) = Byte2Float(Interface, v42);
      v45 = *pos + 4;
      *pos = v45;
      v47 = *v17;
      *(v47 + 52) = Byte2Float(Interface, v45);
      v48 = *pos + 4;
      *pos = v48;
      v50 = *v17;
      *(v50 + 56) = Byte2UInt32(Interface, v48);
      v51 = *pos + 4;
      *pos = v51;
      v53 = *v17;
      *(v53 + 60) = Byte2UInt32(Interface, v51);
      v54 = *pos + 4;
      *pos = v54;
      v56 = *v17;
      *(v56 + 64) = Byte2UInt16(Interface, v54);
      v57 = *pos + 4;
      *pos = v57;
      v59 = *v17;
      *(v59 + 68) = Byte2Float(Interface, v57);
      v60 = *pos + 4;
      *pos = v60;
      v62 = *v17;
      *(v62 + 72) = Byte2UInt32(Interface, v60);
      v63 = *pos + 4;
      *pos = v63;
      v65 = *v17;
      *(v65 + 76) = Byte2Float(Interface, v63);
      v66 = *pos + 4;
      *pos = v66;
      v68 = *v17;
      *(v68 + 80) = Byte2UInt32(Interface, v66);
      v69 = *pos + 4;
      *pos = v69;
      v71 = *v17;
      *(v71 + 84) = Byte2Float(Interface, v69);
      v72 = *pos + 4;
      *pos = v72;
      v74 = *v17;
      *(v74 + 88) = Byte2UInt32(Interface, v72);
      ++v14;
      *pos += 4;
    }
    while (v8 != v14);
  }
  return v9;
}

// 0x1a499d0
void effPCPWhirlwind2PolyParam_t__pClone(effPCPWhirlwind2PolyParam_t *this, effPCPWhirlwind2PolyParam_t **param) {
  f32 x;
  f32 y;
  effPCPWhirlwind2PolyParam_t_o *v7;
  f32 z;
  f32 w;
  f32 v10;
  f32 v11;
  effPCPWhirlwind2PolyParam_t_o *v12;
  s64 i;
  struct System_UInt32_array *reserve;
  struct System_UInt32_array *v15;
  s32 v16;
  s64 v19;
  s64 v20;

  x = this->pos.x;
  y = this->pos.y;
  v7 = *param;
  z = this->pos.z;
  w = this->pos.w;
  v19 = 0;
  v20 = 0;
  sub_854690(&v19, x, y, z, w);
  v11 = *&v20;
  v10 = *(&v20 + 1);
  *&v7->pos.x = v19;
  v7->pos.z = v11;
  v7->pos.w = v10;
  memmove(&(*param)->matrix, &this->matrix, 0x40u);
  (*param)->blend = this->blend;
  (*param)->loop = this->loop;
  (*param)->life = this->life;
  (*param)->number = this->number;
  (*param)->split = this->split;
  (*param)->timing = this->timing;
  (*param)->fade_in = this->fade_in;
  (*param)->fade_out = this->fade_out;
  (*param)->radian_w = this->radian_w;
  (*param)->radian_w_r = this->radian_w_r;
  (*param)->radian_w_u = this->radian_w_u;
  (*param)->incline = this->incline;
  (*param)->width = this->width;
  (*param)->width_r = this->width_r;
  (*param)->up_s = this->up_s;
  (*param)->up_a = this->up_a;
  (*param)->up_r = this->up_r;
  (*param)->roll_s = this->roll_s;
  (*param)->roll_a = this->roll_a;
  (*param)->radius = this->radius;
  (*param)->radius_r = this->radius_r;
  (*param)->radius_s = this->radius_s;
  (*param)->radius_s_r = this->radius_s_r;
  (*param)->radius_a = this->radius_a;
  (*param)->abgr = this->abgr;
  (*param)->repeat_u = this->repeat_u;
  (*param)->repeat_v = this->repeat_v;
  v12 = *param;
  v12->reserve = NewSpecific(uint, 0x20u);
  for (i = 8; i != 40; ++i)
  {
    reserve = this->reserve;
    v15 = (*param)->reserve;
    v16 = *(&reserve->obj.klass + i);
    *(&v15->obj.klass + i) = v16;
  }
}

// 0x1a48d30
effPCPWhirlwind2PolyParam_t **effPCPWhirlwind2PolyParam_t__pCopy(effPCPWhirlwind2PolyParam_t *this, void *pData, s32 *pos, s32 max) {
  effPCPWhirlwind2PolyParam_t_array *v8;
  Il2CppClass *v9;
  s64 *Interface;
  char *v11;
  s64 *v12;
  u64 v13;
  il2cpp_array_size_t *p_max_length;
  Il2CppObject *v17;
  Il2CppClass **v19;
  char *v20;
  f32 *v22;
  s32 v23;
  s32 v24;
  f32 *v26;
  s32 v27;
  f32 *v29;
  s32 v30;
  f32 *v32;
  f32 *v35;
  s32 v36;
  s64 v37;
  f32 *v39;
  s32 v40;
  s64 v41;
  s32 v42;
  s64 v44;
  s32 v45;
  s64 v47;
  s32 v48;
  s32 v50;
  s32 v51;
  s32 v54;
  f32 *v56;
  s32 v57;
  f32 *v59;
  s32 v60;
  f32 *v62;
  s32 v63;
  f32 *v65;
  s32 v66;
  f32 *v68;
  s32 v69;
  f32 *v71;
  s32 v72;
  f32 *v74;
  s32 v75;
  f32 *v77;
  s32 v78;
  f32 *v80;
  s32 v81;
  f32 *v83;
  s32 v84;
  f32 *v86;
  s32 v87;
  f32 *v89;
  s32 v90;
  f32 *v92;
  s32 v93;
  f32 *v95;
  s32 v96;
  f32 *v98;
  s32 v99;
  f32 *v101;
  s32 v102;
  f32 *v104;
  s32 v105;
  f32 *v107;
  s32 v108;
  f32 *v110;
  s32 v111;
  f32 *v113;
  s32 v114;
  f32 *v116;
  s32 v117;
  f32 *v119;
  s32 v120;
  f32 *v122;
  s32 v123;
  f32 *v125;
  s32 v126;
  f32 *v128;
  f32 *v130;
  u64 v131;
  s32 v134;
  s64 v135;
  u32 v136;
  s64 v138;
  s64 v140;
  u64 v141[3];

  v140 = max;
  v8 = NewSpecific(effPCPWhirlwind2PolyParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v9, v141);
      if ((v141[0] & 1) != 0)
        v11 = v141[2];
      else
        v11 = v141 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v13 = 0;
    p_max_length = &v8->max_length;
    do
    {
      v17 = Allocate(effPCPWhirlwind2PolyParam_t);
      _ctor(v17, 0);
      v19 = &v8->obj.klass + v13;
      v19[4] = v17;
      v20 = (v19 + 4);
      v17[1].klass = 0;
      v17[1].monitor = 0;
      v22 = *v20;
      v23 = *pos;
      v22[4] = Byte2Float(Interface, v23);
      v24 = *pos + 4;
      *pos = v24;
      v26 = *v20;
      v26[5] = Byte2Float(Interface, v24);
      v27 = *pos + 4;
      *pos = v27;
      v29 = *v20;
      v29[6] = Byte2Float(Interface, v27);
      v30 = *pos + 4;
      *pos = v30;
      v32 = *v20;
      v32[7] = Byte2Float(Interface, v30);
      *pos += 4;
      v35 = *v20;
      v36 = 0;
      *(v35 + 10) = 0;
      *(v35 + 11) = 0;
      *(v35 + 8) = 0;
      *(v35 + 9) = 0;
      *(v35 + 6) = 0;
      *(v35 + 7) = 0;
      *(v35 + 4) = 0;
      *(v35 + 5) = 0;
      if (v13 >= *p_max_length)
      {
LABEL_33:
      }
      while (1)
      {
        v39 = *v20;
        if (v36 == 4)
          break;
        v40 = *pos;
        v41 = (v39 + 8);
        Byte2Float(Interface, v40);
        sub_19FFD30(v41, v36, 0);
        v42 = *pos + 4;
        *pos = v42;
        v44 = *v20 + 32LL;
        Byte2Float(Interface, v42);
        sub_19FFD30(v44, v36, 1);
        v45 = *pos + 4;
        *pos = v45;
        v47 = *v20 + 32LL;
        Byte2Float(Interface, v45);
        sub_19FFD30(v47, v36, 2);
        v48 = *pos + 4;
        *pos = v48;
        v37 = *v20 + 32LL;
        Byte2Float(Interface, v48);
        sub_19FFD30(v37, v36++, 3);
        *pos += 4;
        if (v13 >= *p_max_length)
          goto LABEL_33;
      }
      v50 = *pos;
      *(v39 + 24) = Byte2UInt32(Interface, v50);
      v51 = *pos + 4;
      *pos = v51;
      *(*v20 + 100LL) = *(Interface + v51 + 32);
      v54 = *pos + 4;
      *pos = v54;
      v56 = *v20;
      *(v56 + 26) = Byte2UInt32(Interface, v54);
      v57 = *pos + 4;
      *pos = v57;
      v59 = *v20;
      *(v59 + 27) = Byte2UInt32(Interface, v57);
      v60 = *pos + 4;
      *pos = v60;
      v62 = *v20;
      *(v62 + 28) = Byte2UInt32(Interface, v60);
      v63 = *pos + 4;
      *pos = v63;
      v65 = *v20;
      *(v65 + 29) = Byte2UInt32(Interface, v63);
      v66 = *pos + 4;
      *pos = v66;
      v68 = *v20;
      *(v68 + 30) = Byte2UInt32(Interface, v66);
      v69 = *pos + 4;
      *pos = v69;
      v71 = *v20;
      *(v71 + 31) = Byte2UInt32(Interface, v69);
      v72 = *pos + 4;
      *pos = v72;
      v74 = *v20;
      v74[32] = Byte2Float(Interface, v72);
      v75 = *pos + 4;
      *pos = v75;
      v77 = *v20;
      v77[33] = Byte2Float(Interface, v75);
      v78 = *pos + 4;
      *pos = v78;
      v80 = *v20;
      v80[34] = Byte2Float(Interface, v78);
      v81 = *pos + 4;
      *pos = v81;
      v83 = *v20;
      v83[35] = Byte2Float(Interface, v81);
      v84 = *pos + 4;
      *pos = v84;
      v86 = *v20;
      v86[36] = Byte2Float(Interface, v84);
      v87 = *pos + 4;
      *pos = v87;
      v89 = *v20;
      v89[37] = Byte2Float(Interface, v87);
      v90 = *pos + 4;
      *pos = v90;
      v92 = *v20;
      v92[38] = Byte2Float(Interface, v90);
      v93 = *pos + 4;
      *pos = v93;
      v95 = *v20;
      v95[39] = Byte2Float(Interface, v93);
      v96 = *pos + 4;
      *pos = v96;
      v98 = *v20;
      v98[40] = Byte2Float(Interface, v96);
      v99 = *pos + 4;
      *pos = v99;
      v101 = *v20;
      v101[41] = Byte2Float(Interface, v99);
      v102 = *pos + 4;
      *pos = v102;
      v104 = *v20;
      v104[42] = Byte2Float(Interface, v102);
      v105 = *pos + 4;
      *pos = v105;
      v107 = *v20;
      v107[43] = Byte2Float(Interface, v105);
      v108 = *pos + 4;
      *pos = v108;
      v110 = *v20;
      v110[44] = Byte2Float(Interface, v108);
      v111 = *pos + 4;
      *pos = v111;
      v113 = *v20;
      v113[45] = Byte2Float(Interface, v111);
      v114 = *pos + 4;
      *pos = v114;
      v116 = *v20;
      v116[46] = Byte2Float(Interface, v114);
      v117 = *pos + 4;
      *pos = v117;
      v119 = *v20;
      v119[47] = Byte2Float(Interface, v117);
      v120 = *pos + 4;
      *pos = v120;
      v122 = *v20;
      *(v122 + 48) = Byte2UInt32(Interface, v120);
      v123 = *pos + 4;
      *pos = v123;
      v125 = *v20;
      *(v125 + 49) = Byte2UInt32(Interface, v123);
      v126 = *pos + 4;
      *pos = v126;
      v128 = *v20;
      *(v128 + 50) = Byte2UInt32(Interface, v126);
      *pos += 4;
      v130 = *v20;
      v131 = 0;
      *(v130 + 26) = NewSpecific(uint, 0x20u);
      do
      {
        v134 = *pos;
        v135 = *(*v20 + 208LL);
        v136 = Byte2UInt32(Interface, v134);
        v138 = v135 + 4 * v131++;
        *(v138 + 32) = v136;
        *pos += 4;
      }
      while (v131 != 32);
      ++v13;
    }
    while (v13 != v140);
  }
  return v8;
}

// 0x1a4a970
void effPCPWhirlwind3PolyParam_t__pClone(effPCPWhirlwind3PolyParam_t *this, effPCPWhirlwind3PolyParam_t **param) {
  f32 x;
  f32 y;
  effPCPWhirlwind3PolyParam_t_o *v7;
  f32 z;
  f32 w;
  f32 v10;
  f32 v11;
  effPCPWhirlwind3PolyParam_t_o *v12;
  struct UnityEngine_Matrix4x4_o *p_matrix;
  struct UnityEngine_Matrix4x4_o *v14;
  struct UnityEngine_Matrix4x4_o *v15;
  struct UnityEngine_Matrix4x4_o *v16;
  struct UnityEngine_Matrix4x4_o *v17;
  struct UnityEngine_Matrix4x4_o *v18;
  struct UnityEngine_Matrix4x4_o *v19;
  struct UnityEngine_Matrix4x4_o *v20;
  struct UnityEngine_Matrix4x4_o *v21;
  struct UnityEngine_Matrix4x4_o *v22;
  struct UnityEngine_Matrix4x4_o *v23;
  struct UnityEngine_Matrix4x4_o *v24;
  struct UnityEngine_Matrix4x4_o *v25;
  struct UnityEngine_Matrix4x4_o *v26;
  struct UnityEngine_Matrix4x4_o *v27;
  struct UnityEngine_Matrix4x4_o *v28;
  effPCPWhirlwind3PolyParam_t_o *v29;
  s64 i;
  struct System_UInt32_array *reserve;
  struct System_UInt32_array *v32;
  s32 v33;
  s64 v36;
  s64 v37;

  x = this->pos.x;
  y = this->pos.y;
  v7 = *param;
  z = this->pos.z;
  w = this->pos.w;
  v36 = 0;
  v37 = 0;
  sub_854690(&v36, x, y, z, w);
  v11 = *&v37;
  v10 = *(&v37 + 1);
  *&v7->pos.x = v36;
  v7->pos.z = v11;
  v7->pos.w = v10;
  v12 = *param;
  *&v12->matrix.m02 = 0;
  *&v12->matrix.m22 = 0;
  *&v12->matrix.m01 = 0;
  *&v12->matrix.m21 = 0;
  *&v12->matrix.m00 = 0;
  *&v12->matrix.m20 = 0;
  *&v12->matrix.m03 = 0;
  *&v12->matrix.m23 = 0;
  p_matrix = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 0, 0);
  sub_19FFD30(p_matrix, 0, 0);
  v14 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 0, 1);
  sub_19FFD30(v14, 0, 1);
  v15 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 0, 2);
  sub_19FFD30(v15, 0, 2);
  v16 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 0, 3);
  sub_19FFD30(v16, 0, 3);
  v17 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 1, 0);
  sub_19FFD30(v17, 1, 0);
  v18 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 1, 1);
  sub_19FFD30(v18, 1, 1);
  v19 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 1, 2);
  sub_19FFD30(v19, 1, 2);
  v20 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 1, 3);
  sub_19FFD30(v20, 1, 3);
  v21 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 2, 0);
  sub_19FFD30(v21, 2, 0);
  v22 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 2, 1);
  sub_19FFD30(v22, 2, 1);
  v23 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 2, 2);
  sub_19FFD30(v23, 2, 2);
  v24 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 2, 3);
  sub_19FFD30(v24, 2, 3);
  v25 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 3, 0);
  sub_19FFD30(v25, 3, 0);
  v26 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 3, 1);
  sub_19FFD30(v26, 3, 1);
  v27 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 3, 2);
  sub_19FFD30(v27, 3, 2);
  v28 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 3, 3);
  sub_19FFD30(v28, 3, 3);
  (*param)->blend = this->blend;
  (*param)->loop = this->loop;
  (*param)->life = this->life;
  (*param)->number = this->number;
  (*param)->split = this->split;
  (*param)->timing = this->timing;
  (*param)->fade_in = this->fade_in;
  (*param)->fade_out = this->fade_out;
  (*param)->radian_w = this->radian_w;
  (*param)->radian_w_r = this->radian_w_r;
  (*param)->incline = this->incline;
  (*param)->height = this->height;
  (*param)->slant = this->slant;
  (*param)->width = this->width;
  (*param)->width_r = this->width_r;
  (*param)->up_s = this->up_s;
  (*param)->up_a = this->up_a;
  (*param)->up_r = this->up_r;
  (*param)->roll_s = this->roll_s;
  (*param)->roll_a = this->roll_a;
  (*param)->radius = this->radius;
  (*param)->radius_r = this->radius_r;
  (*param)->radius_s = this->radius_s;
  (*param)->radius_s_r = this->radius_s_r;
  (*param)->radius_a = this->radius_a;
  (*param)->abgr_s = this->abgr_s;
  (*param)->abgr_e = this->abgr_e;
  (*param)->repeat_u = this->repeat_u;
  (*param)->repeat_v = this->repeat_v;
  v29 = *param;
  v29->reserve = NewSpecific(uint, 0x20u);
  for (i = 8; i != 40; ++i)
  {
    reserve = this->reserve;
    v32 = (*param)->reserve;
    v33 = *(&reserve->obj.klass + i);
    *(&v32->obj.klass + i) = v33;
  }
}

// 0x1a49c50
effPCPWhirlwind3PolyParam_t **effPCPWhirlwind3PolyParam_t__pCopy(effPCPWhirlwind3PolyParam_t *this, void *pData, s32 *pos, s32 max) {
  effPCPWhirlwind3PolyParam_t_array *v8;
  Il2CppClass *v9;
  s64 *Interface;
  char *v11;
  s64 *v12;
  u64 v13;
  il2cpp_array_size_t *p_max_length;
  Il2CppObject *v17;
  Il2CppClass **v19;
  char *v20;
  f32 *v22;
  s32 v23;
  s32 v24;
  f32 *v26;
  s32 v27;
  f32 *v29;
  s32 v30;
  f32 *v32;
  f32 *v35;
  s32 v36;
  s64 v37;
  f32 *v39;
  s32 v40;
  s64 v41;
  s32 v42;
  s64 v44;
  s32 v45;
  s64 v47;
  s32 v48;
  s32 v50;
  s32 v51;
  s32 v54;
  f32 *v56;
  s32 v57;
  f32 *v59;
  s32 v60;
  f32 *v62;
  s32 v63;
  f32 *v65;
  s32 v66;
  f32 *v68;
  s32 v69;
  f32 *v71;
  s32 v72;
  f32 *v74;
  s32 v75;
  f32 *v77;
  s32 v78;
  f32 *v80;
  s32 v81;
  f32 *v83;
  s32 v84;
  f32 *v86;
  s32 v87;
  f32 *v89;
  s32 v90;
  f32 *v92;
  s32 v93;
  f32 *v95;
  s32 v96;
  f32 *v98;
  s32 v99;
  f32 *v101;
  s32 v102;
  f32 *v104;
  s32 v105;
  f32 *v107;
  s32 v108;
  f32 *v110;
  s32 v111;
  f32 *v113;
  s32 v114;
  f32 *v116;
  s32 v117;
  f32 *v119;
  s32 v120;
  f32 *v122;
  s32 v123;
  f32 *v125;
  s32 v126;
  f32 *v128;
  s32 v129;
  f32 *v131;
  s32 v132;
  f32 *v134;
  f32 *v136;
  u64 v137;
  s32 v140;
  s64 v141;
  u32 v142;
  s64 v144;
  s64 v146;
  u64 v147[3];

  v146 = max;
  v8 = NewSpecific(effPCPWhirlwind3PolyParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v9, v147);
      if ((v147[0] & 1) != 0)
        v11 = v147[2];
      else
        v11 = v147 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v13 = 0;
    p_max_length = &v8->max_length;
    do
    {
      v17 = Allocate(effPCPWhirlwind3PolyParam_t);
      _ctor(v17, 0);
      v19 = &v8->obj.klass + v13;
      v19[4] = v17;
      v20 = (v19 + 4);
      v17[1].klass = 0;
      v17[1].monitor = 0;
      v22 = *v20;
      v23 = *pos;
      v22[4] = Byte2Float(Interface, v23);
      v24 = *pos + 4;
      *pos = v24;
      v26 = *v20;
      v26[5] = Byte2Float(Interface, v24);
      v27 = *pos + 4;
      *pos = v27;
      v29 = *v20;
      v29[6] = Byte2Float(Interface, v27);
      v30 = *pos + 4;
      *pos = v30;
      v32 = *v20;
      v32[7] = Byte2Float(Interface, v30);
      *pos += 4;
      v35 = *v20;
      v36 = 0;
      *(v35 + 10) = 0;
      *(v35 + 11) = 0;
      *(v35 + 8) = 0;
      *(v35 + 9) = 0;
      *(v35 + 6) = 0;
      *(v35 + 7) = 0;
      *(v35 + 4) = 0;
      *(v35 + 5) = 0;
      if (v13 >= *p_max_length)
      {
LABEL_33:
      }
      while (1)
      {
        v39 = *v20;
        if (v36 == 4)
          break;
        v40 = *pos;
        v41 = (v39 + 8);
        Byte2Float(Interface, v40);
        sub_19FFD30(v41, v36, 0);
        v42 = *pos + 4;
        *pos = v42;
        v44 = *v20 + 32LL;
        Byte2Float(Interface, v42);
        sub_19FFD30(v44, v36, 1);
        v45 = *pos + 4;
        *pos = v45;
        v47 = *v20 + 32LL;
        Byte2Float(Interface, v45);
        sub_19FFD30(v47, v36, 2);
        v48 = *pos + 4;
        *pos = v48;
        v37 = *v20 + 32LL;
        Byte2Float(Interface, v48);
        sub_19FFD30(v37, v36++, 3);
        *pos += 4;
        if (v13 >= *p_max_length)
          goto LABEL_33;
      }
      v50 = *pos;
      *(v39 + 24) = Byte2UInt32(Interface, v50);
      v51 = *pos + 4;
      *pos = v51;
      *(*v20 + 100LL) = *(Interface + v51 + 32);
      v54 = *pos + 4;
      *pos = v54;
      v56 = *v20;
      *(v56 + 26) = Byte2UInt32(Interface, v54);
      v57 = *pos + 4;
      *pos = v57;
      v59 = *v20;
      *(v59 + 27) = Byte2UInt32(Interface, v57);
      v60 = *pos + 4;
      *pos = v60;
      v62 = *v20;
      *(v62 + 28) = Byte2UInt32(Interface, v60);
      v63 = *pos + 4;
      *pos = v63;
      v65 = *v20;
      *(v65 + 29) = Byte2UInt32(Interface, v63);
      v66 = *pos + 4;
      *pos = v66;
      v68 = *v20;
      *(v68 + 30) = Byte2UInt32(Interface, v66);
      v69 = *pos + 4;
      *pos = v69;
      v71 = *v20;
      *(v71 + 31) = Byte2UInt32(Interface, v69);
      v72 = *pos + 4;
      *pos = v72;
      v74 = *v20;
      v74[32] = Byte2Float(Interface, v72);
      v75 = *pos + 4;
      *pos = v75;
      v77 = *v20;
      v77[33] = Byte2Float(Interface, v75);
      v78 = *pos + 4;
      *pos = v78;
      v80 = *v20;
      v80[34] = Byte2Float(Interface, v78);
      v81 = *pos + 4;
      *pos = v81;
      v83 = *v20;
      v83[35] = Byte2Float(Interface, v81);
      v84 = *pos + 4;
      *pos = v84;
      v86 = *v20;
      v86[36] = Byte2Float(Interface, v84);
      v87 = *pos + 4;
      *pos = v87;
      v89 = *v20;
      v89[37] = Byte2Float(Interface, v87);
      v90 = *pos + 4;
      *pos = v90;
      v92 = *v20;
      v92[38] = Byte2Float(Interface, v90);
      v93 = *pos + 4;
      *pos = v93;
      v95 = *v20;
      v95[39] = Byte2Float(Interface, v93);
      v96 = *pos + 4;
      *pos = v96;
      v98 = *v20;
      v98[40] = Byte2Float(Interface, v96);
      v99 = *pos + 4;
      *pos = v99;
      v101 = *v20;
      v101[41] = Byte2Float(Interface, v99);
      v102 = *pos + 4;
      *pos = v102;
      v104 = *v20;
      v104[42] = Byte2Float(Interface, v102);
      v105 = *pos + 4;
      *pos = v105;
      v107 = *v20;
      v107[43] = Byte2Float(Interface, v105);
      v108 = *pos + 4;
      *pos = v108;
      v110 = *v20;
      v110[44] = Byte2Float(Interface, v108);
      v111 = *pos + 4;
      *pos = v111;
      v113 = *v20;
      v113[45] = Byte2Float(Interface, v111);
      v114 = *pos + 4;
      *pos = v114;
      v116 = *v20;
      v116[46] = Byte2Float(Interface, v114);
      v117 = *pos + 4;
      *pos = v117;
      v119 = *v20;
      v119[47] = Byte2Float(Interface, v117);
      v120 = *pos + 4;
      *pos = v120;
      v122 = *v20;
      v122[48] = Byte2Float(Interface, v120);
      v123 = *pos + 4;
      *pos = v123;
      v125 = *v20;
      *(v125 + 49) = Byte2UInt32(Interface, v123);
      v126 = *pos + 4;
      *pos = v126;
      v128 = *v20;
      *(v128 + 50) = Byte2UInt32(Interface, v126);
      v129 = *pos + 4;
      *pos = v129;
      v131 = *v20;
      *(v131 + 51) = Byte2UInt32(Interface, v129);
      v132 = *pos + 4;
      *pos = v132;
      v134 = *v20;
      *(v134 + 52) = Byte2UInt32(Interface, v132);
      *pos += 4;
      v136 = *v20;
      v137 = 0;
      *(v136 + 27) = NewSpecific(uint, 0x20u);
      do
      {
        v140 = *pos;
        v141 = *(*v20 + 216LL);
        v142 = Byte2UInt32(Interface, v140);
        v144 = v141 + 4 * v137++;
        *(v144 + 32) = v142;
        *pos += 4;
      }
      while (v137 != 32);
      ++v13;
    }
    while (v13 != v146);
  }
  return v8;
}

// 0x1a4bb70
void effPCPWhirlwindPolyParam_t__pClone(effPCPWhirlwindPolyParam_t *this, effPCPWhirlwindPolyParam_t **param) {
  f32 x;
  f32 y;
  effPCPWhirlwindPolyParam_t_o *v7;
  f32 z;
  f32 w;
  f32 v10;
  f32 v11;
  effPCPWhirlwindPolyParam_t_o *v12;
  struct UnityEngine_Matrix4x4_o *p_matrix;
  struct UnityEngine_Matrix4x4_o *v14;
  struct UnityEngine_Matrix4x4_o *v15;
  struct UnityEngine_Matrix4x4_o *v16;
  struct UnityEngine_Matrix4x4_o *v17;
  struct UnityEngine_Matrix4x4_o *v18;
  struct UnityEngine_Matrix4x4_o *v19;
  struct UnityEngine_Matrix4x4_o *v20;
  struct UnityEngine_Matrix4x4_o *v21;
  struct UnityEngine_Matrix4x4_o *v22;
  struct UnityEngine_Matrix4x4_o *v23;
  struct UnityEngine_Matrix4x4_o *v24;
  struct UnityEngine_Matrix4x4_o *v25;
  struct UnityEngine_Matrix4x4_o *v26;
  struct UnityEngine_Matrix4x4_o *v27;
  struct UnityEngine_Matrix4x4_o *v28;
  effPCPWhirlwindPolyParam_t_o *v29;
  s64 i;
  struct System_UInt32_array *reserve;
  struct System_UInt32_array *v32;
  s32 v33;
  s64 v36;
  s64 v37;

  x = this->pos.x;
  y = this->pos.y;
  v7 = *param;
  z = this->pos.z;
  w = this->pos.w;
  v36 = 0;
  v37 = 0;
  sub_854690(&v36, x, y, z, w);
  v11 = *&v37;
  v10 = *(&v37 + 1);
  *&v7->pos.x = v36;
  v7->pos.z = v11;
  v7->pos.w = v10;
  v12 = *param;
  *&v12->matrix.m02 = 0;
  *&v12->matrix.m22 = 0;
  *&v12->matrix.m01 = 0;
  *&v12->matrix.m21 = 0;
  *&v12->matrix.m00 = 0;
  *&v12->matrix.m20 = 0;
  *&v12->matrix.m03 = 0;
  *&v12->matrix.m23 = 0;
  p_matrix = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 0, 0);
  sub_19FFD30(p_matrix, 0, 0);
  v14 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 0, 1);
  sub_19FFD30(v14, 0, 1);
  v15 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 0, 2);
  sub_19FFD30(v15, 0, 2);
  v16 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 0, 3);
  sub_19FFD30(v16, 0, 3);
  v17 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 1, 0);
  sub_19FFD30(v17, 1, 0);
  v18 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 1, 1);
  sub_19FFD30(v18, 1, 1);
  v19 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 1, 2);
  sub_19FFD30(v19, 1, 2);
  v20 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 1, 3);
  sub_19FFD30(v20, 1, 3);
  v21 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 2, 0);
  sub_19FFD30(v21, 2, 0);
  v22 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 2, 1);
  sub_19FFD30(v22, 2, 1);
  v23 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 2, 2);
  sub_19FFD30(v23, 2, 2);
  v24 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 2, 3);
  sub_19FFD30(v24, 2, 3);
  v25 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 3, 0);
  sub_19FFD30(v25, 3, 0);
  v26 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 3, 1);
  sub_19FFD30(v26, 3, 1);
  v27 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 3, 2);
  sub_19FFD30(v27, 3, 2);
  v28 = &(*param)->matrix;
  sub_19FFB10(&this->matrix, 3, 3);
  sub_19FFD30(v28, 3, 3);
  (*param)->blend = this->blend;
  (*param)->loop = this->loop;
  (*param)->life = this->life;
  (*param)->number = this->number;
  (*param)->split = this->split;
  (*param)->timing = this->timing;
  (*param)->fade_in = this->fade_in;
  (*param)->fade_out = this->fade_out;
  (*param)->radian_w = this->radian_w;
  (*param)->radian_w_r = this->radian_w_r;
  (*param)->radian_w_u = this->radian_w_u;
  (*param)->incline = this->incline;
  (*param)->width = this->width;
  (*param)->width_r = this->width_r;
  (*param)->up_s = this->up_s;
  (*param)->up_a = this->up_a;
  (*param)->up_r = this->up_r;
  (*param)->roll_s = this->roll_s;
  (*param)->roll_a = this->roll_a;
  (*param)->radius_s = this->radius_s;
  (*param)->radius_s_r = this->radius_s_r;
  (*param)->radius_e = this->radius_e;
  (*param)->radius_e_r = this->radius_e_r;
  (*param)->abgr = this->abgr;
  (*param)->repeat_u = this->repeat_u;
  (*param)->repeat_v = this->repeat_v;
  v29 = *param;
  v29->reserve = NewSpecific(uint, 0x20u);
  for (i = 8; i != 40; ++i)
  {
    reserve = this->reserve;
    v32 = (*param)->reserve;
    v33 = *(&reserve->obj.klass + i);
    *(&v32->obj.klass + i) = v33;
  }
}

// 0x1a4af10
effPCPWhirlwindPolyParam_t **effPCPWhirlwindPolyParam_t__pCopy(effPCPWhirlwindPolyParam_t *this, void *pData, s32 *pos, s32 max) {
  effPCPWhirlwindPolyParam_t_array *v8;
  Il2CppClass *v9;
  s64 *Interface;
  char *v11;
  s64 *v12;
  u64 v13;
  il2cpp_array_size_t *p_max_length;
  Il2CppObject *v17;
  Il2CppClass **v19;
  char *v20;
  f32 *v22;
  s32 v23;
  s32 v24;
  f32 *v26;
  s32 v27;
  f32 *v29;
  s32 v30;
  f32 *v32;
  f32 *v35;
  s32 v36;
  s64 v37;
  f32 *v39;
  s32 v40;
  s64 v41;
  s32 v42;
  s64 v44;
  s32 v45;
  s64 v47;
  s32 v48;
  s32 v50;
  s32 v51;
  s32 v54;
  f32 *v56;
  s32 v57;
  f32 *v59;
  s32 v60;
  f32 *v62;
  s32 v63;
  f32 *v65;
  s32 v66;
  f32 *v68;
  s32 v69;
  f32 *v71;
  s32 v72;
  f32 *v74;
  s32 v75;
  f32 *v77;
  s32 v78;
  f32 *v80;
  s32 v81;
  f32 *v83;
  s32 v84;
  f32 *v86;
  s32 v87;
  f32 *v89;
  s32 v90;
  f32 *v92;
  s32 v93;
  f32 *v95;
  s32 v96;
  f32 *v98;
  s32 v99;
  f32 *v101;
  s32 v102;
  f32 *v104;
  s32 v105;
  f32 *v107;
  s32 v108;
  f32 *v110;
  s32 v111;
  f32 *v113;
  s32 v114;
  f32 *v116;
  s32 v117;
  f32 *v119;
  s32 v120;
  f32 *v122;
  s32 v123;
  f32 *v125;
  f32 *v127;
  u64 v128;
  s32 v131;
  s64 v132;
  u32 v133;
  s64 v135;
  s64 v137;
  u64 v138[3];

  v137 = max;
  v8 = NewSpecific(effPCPWhirlwindPolyParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v9, v138);
      if ((v138[0] & 1) != 0)
        v11 = v138[2];
      else
        v11 = v138 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v13 = 0;
    p_max_length = &v8->max_length;
    do
    {
      v17 = Allocate(effPCPWhirlwindPolyParam_t);
      _ctor(v17, 0);
      v19 = &v8->obj.klass + v13;
      v19[4] = v17;
      v20 = (v19 + 4);
      v17[1].klass = 0;
      v17[1].monitor = 0;
      v22 = *v20;
      v23 = *pos;
      v22[4] = Byte2Float(Interface, v23);
      v24 = *pos + 4;
      *pos = v24;
      v26 = *v20;
      v26[5] = Byte2Float(Interface, v24);
      v27 = *pos + 4;
      *pos = v27;
      v29 = *v20;
      v29[6] = Byte2Float(Interface, v27);
      v30 = *pos + 4;
      *pos = v30;
      v32 = *v20;
      v32[7] = Byte2Float(Interface, v30);
      *pos += 4;
      v35 = *v20;
      v36 = 0;
      *(v35 + 10) = 0;
      *(v35 + 11) = 0;
      *(v35 + 8) = 0;
      *(v35 + 9) = 0;
      *(v35 + 6) = 0;
      *(v35 + 7) = 0;
      *(v35 + 4) = 0;
      *(v35 + 5) = 0;
      if (v13 >= *p_max_length)
      {
LABEL_33:
      }
      while (1)
      {
        v39 = *v20;
        if (v36 == 4)
          break;
        v40 = *pos;
        v41 = (v39 + 8);
        Byte2Float(Interface, v40);
        sub_19FFD30(v41, v36, 0);
        v42 = *pos + 4;
        *pos = v42;
        v44 = *v20 + 32LL;
        Byte2Float(Interface, v42);
        sub_19FFD30(v44, v36, 1);
        v45 = *pos + 4;
        *pos = v45;
        v47 = *v20 + 32LL;
        Byte2Float(Interface, v45);
        sub_19FFD30(v47, v36, 2);
        v48 = *pos + 4;
        *pos = v48;
        v37 = *v20 + 32LL;
        Byte2Float(Interface, v48);
        sub_19FFD30(v37, v36++, 3);
        *pos += 4;
        if (v13 >= *p_max_length)
          goto LABEL_33;
      }
      v50 = *pos;
      *(v39 + 24) = Byte2UInt32(Interface, v50);
      v51 = *pos + 4;
      *pos = v51;
      *(*v20 + 100LL) = *(Interface + v51 + 32);
      v54 = *pos + 4;
      *pos = v54;
      v56 = *v20;
      *(v56 + 26) = Byte2UInt32(Interface, v54);
      v57 = *pos + 4;
      *pos = v57;
      v59 = *v20;
      *(v59 + 27) = Byte2UInt32(Interface, v57);
      v60 = *pos + 4;
      *pos = v60;
      v62 = *v20;
      *(v62 + 28) = Byte2UInt32(Interface, v60);
      v63 = *pos + 4;
      *pos = v63;
      v65 = *v20;
      *(v65 + 29) = Byte2UInt32(Interface, v63);
      v66 = *pos + 4;
      *pos = v66;
      v68 = *v20;
      *(v68 + 30) = Byte2UInt32(Interface, v66);
      v69 = *pos + 4;
      *pos = v69;
      v71 = *v20;
      *(v71 + 31) = Byte2UInt32(Interface, v69);
      v72 = *pos + 4;
      *pos = v72;
      v74 = *v20;
      v74[32] = Byte2Float(Interface, v72);
      v75 = *pos + 4;
      *pos = v75;
      v77 = *v20;
      v77[33] = Byte2Float(Interface, v75);
      v78 = *pos + 4;
      *pos = v78;
      v80 = *v20;
      v80[34] = Byte2Float(Interface, v78);
      v81 = *pos + 4;
      *pos = v81;
      v83 = *v20;
      v83[35] = Byte2Float(Interface, v81);
      v84 = *pos + 4;
      *pos = v84;
      v86 = *v20;
      v86[36] = Byte2Float(Interface, v84);
      v87 = *pos + 4;
      *pos = v87;
      v89 = *v20;
      v89[37] = Byte2Float(Interface, v87);
      v90 = *pos + 4;
      *pos = v90;
      v92 = *v20;
      v92[38] = Byte2Float(Interface, v90);
      v93 = *pos + 4;
      *pos = v93;
      v95 = *v20;
      v95[39] = Byte2Float(Interface, v93);
      v96 = *pos + 4;
      *pos = v96;
      v98 = *v20;
      v98[40] = Byte2Float(Interface, v96);
      v99 = *pos + 4;
      *pos = v99;
      v101 = *v20;
      v101[41] = Byte2Float(Interface, v99);
      v102 = *pos + 4;
      *pos = v102;
      v104 = *v20;
      v104[42] = Byte2Float(Interface, v102);
      v105 = *pos + 4;
      *pos = v105;
      v107 = *v20;
      v107[43] = Byte2Float(Interface, v105);
      v108 = *pos + 4;
      *pos = v108;
      v110 = *v20;
      v110[44] = Byte2Float(Interface, v108);
      v111 = *pos + 4;
      *pos = v111;
      v113 = *v20;
      v113[45] = Byte2Float(Interface, v111);
      v114 = *pos + 4;
      *pos = v114;
      v116 = *v20;
      v116[46] = Byte2Float(Interface, v114);
      v117 = *pos + 4;
      *pos = v117;
      v119 = *v20;
      *(v119 + 47) = Byte2UInt32(Interface, v117);
      v120 = *pos + 4;
      *pos = v120;
      v122 = *v20;
      *(v122 + 48) = Byte2UInt32(Interface, v120);
      v123 = *pos + 4;
      *pos = v123;
      v125 = *v20;
      *(v125 + 49) = Byte2UInt32(Interface, v123);
      *pos += 4;
      v127 = *v20;
      v128 = 0;
      *(v127 + 25) = NewSpecific(uint, 0x20u);
      do
      {
        v131 = *pos;
        v132 = *(*v20 + 200LL);
        v133 = Byte2UInt32(Interface, v131);
        v135 = v132 + 4 * v128++;
        *(v135 + 32) = v133;
        *pos += 4;
      }
      while (v128 != 32);
      ++v13;
    }
    while (v13 != v137);
  }
  return v8;
}

// 0x1a4ca90
void effPCPWwSpherePolyParam_t__pClone(effPCPWwSpherePolyParam_t *this, effPCPWwSpherePolyParam_t **param) {
  f32 x;
  f32 y;
  effPCPWwSpherePolyParam_t_o *v7;
  f32 z;
  f32 w;
  f32 v10;
  f32 v11;
  effPCPWwSpherePolyParam_t_o *v12;
  s64 i;
  struct System_UInt32_array *reserve;
  struct System_UInt32_array *v15;
  s32 v16;
  s64 v19;
  s64 v20;

  x = this->pos.x;
  y = this->pos.y;
  v7 = *param;
  z = this->pos.z;
  w = this->pos.w;
  v19 = 0;
  v20 = 0;
  sub_854690(&v19, x, y, z, w);
  v11 = *&v20;
  v10 = *(&v20 + 1);
  *&v7->pos.x = v19;
  v7->pos.z = v11;
  v7->pos.w = v10;
  (*param)->blend = this->blend;
  (*param)->loop = this->loop;
  (*param)->life = this->life;
  (*param)->number = this->number;
  (*param)->split = this->split;
  (*param)->timing = this->timing;
  (*param)->fade_in = this->fade_in;
  (*param)->fade_out = this->fade_out;
  (*param)->radian_w = this->radian_w;
  (*param)->radian_w_r = this->radian_w_r;
  (*param)->width = this->width;
  (*param)->width_r = this->width_r;
  (*param)->roll_s = this->roll_s;
  (*param)->roll_a = this->roll_a;
  (*param)->radius = this->radius;
  (*param)->radius_r = this->radius_r;
  (*param)->radius_s = this->radius_s;
  (*param)->radius_a = this->radius_a;
  (*param)->radius_aw = this->radius_aw;
  (*param)->abgr = this->abgr;
  (*param)->repeat_u = this->repeat_u;
  (*param)->repeat_v = this->repeat_v;
  v12 = *param;
  v12->reserve = NewSpecific(uint, 0x20u);
  for (i = 8; i != 40; ++i)
  {
    reserve = this->reserve;
    v15 = (*param)->reserve;
    v16 = *(&reserve->obj.klass + i);
    *(&v15->obj.klass + i) = v16;
  }
}

// 0x1a4c0f0
effPCPWwSpherePolyParam_t **effPCPWwSpherePolyParam_t__pCopy(effPCPWwSpherePolyParam_t *this, void *pData, s32 *pos, s32 max) {
  effPCPWwSpherePolyParam_t_array *v8;
  Il2CppClass *v9;
  s64 *Interface;
  char *v11;
  s64 *v12;
  u64 v13;
  il2cpp_array_size_t *p_max_length;
  Il2CppObject *v17;
  Il2CppClass **v19;
  char *v20;
  s64 v22;
  s32 v23;
  s32 v24;
  s64 v26;
  s32 v27;
  s64 v29;
  s32 v30;
  s64 v32;
  s32 v33;
  s64 v35;
  s32 v36;
  s32 v39;
  s64 v41;
  s32 v42;
  s64 v44;
  s32 v45;
  s64 v47;
  s32 v48;
  s64 v50;
  s32 v51;
  s64 v53;
  s32 v54;
  s64 v56;
  s32 v57;
  s64 v59;
  s32 v60;
  s64 v62;
  s32 v63;
  s64 v65;
  s32 v66;
  s64 v68;
  s32 v69;
  s64 v71;
  s32 v72;
  s64 v74;
  s32 v75;
  s64 v77;
  s32 v78;
  s64 v80;
  s32 v81;
  s64 v83;
  s32 v84;
  s64 v86;
  s32 v87;
  s64 v89;
  s32 v90;
  s64 v92;
  s32 v93;
  s64 v95;
  s32 v96;
  s64 v98;
  s64 v100;
  u64 v101;
  s32 v104;
  s64 v105;
  u32 v106;
  s64 v108;
  s64 v110;
  u64 v111[3];

  v110 = max;
  v8 = NewSpecific(effPCPWwSpherePolyParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v9, v111);
      if ((v111[0] & 1) != 0)
        v11 = v111[2];
      else
        v11 = v111 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v13 = 0;
    p_max_length = &v8->max_length;
    do
    {
      v17 = Allocate(effPCPWwSpherePolyParam_t);
      _ctor(v17, 0);
      v19 = &v8->obj.klass + v13;
      v19[4] = v17;
      v20 = (v19 + 4);
      v17[1].klass = 0;
      v17[1].monitor = 0;
      v22 = *v20;
      v23 = *pos;
      *(v22 + 16) = Byte2Float(Interface, v23);
      v24 = *pos + 4;
      *pos = v24;
      v26 = *v20;
      *(v26 + 20) = Byte2Float(Interface, v24);
      v27 = *pos + 4;
      *pos = v27;
      v29 = *v20;
      *(v29 + 24) = Byte2Float(Interface, v27);
      v30 = *pos + 4;
      *pos = v30;
      v32 = *v20;
      *(v32 + 28) = Byte2Float(Interface, v30);
      v33 = *pos + 4;
      *pos = v33;
      v35 = *v20;
      *(v35 + 32) = Byte2UInt32(Interface, v33);
      v36 = *pos + 4;
      *pos = v36;
      *(*v20 + 36LL) = *(Interface + v36 + 32);
      v39 = *pos + 4;
      *pos = v39;
      v41 = *v20;
      *(v41 + 40) = Byte2UInt32(Interface, v39);
      v42 = *pos + 4;
      *pos = v42;
      v44 = *v20;
      *(v44 + 44) = Byte2UInt32(Interface, v42);
      v45 = *pos + 4;
      *pos = v45;
      v47 = *v20;
      *(v47 + 48) = Byte2UInt32(Interface, v45);
      v48 = *pos + 4;
      *pos = v48;
      v50 = *v20;
      *(v50 + 52) = Byte2UInt32(Interface, v48);
      v51 = *pos + 4;
      *pos = v51;
      v53 = *v20;
      *(v53 + 56) = Byte2UInt32(Interface, v51);
      v54 = *pos + 4;
      *pos = v54;
      v56 = *v20;
      *(v56 + 60) = Byte2UInt32(Interface, v54);
      v57 = *pos + 4;
      *pos = v57;
      v59 = *v20;
      *(v59 + 64) = Byte2Float(Interface, v57);
      v60 = *pos + 4;
      *pos = v60;
      v62 = *v20;
      *(v62 + 68) = Byte2Float(Interface, v60);
      v63 = *pos + 4;
      *pos = v63;
      v65 = *v20;
      *(v65 + 72) = Byte2Float(Interface, v63);
      v66 = *pos + 4;
      *pos = v66;
      v68 = *v20;
      *(v68 + 76) = Byte2Float(Interface, v66);
      v69 = *pos + 4;
      *pos = v69;
      v71 = *v20;
      *(v71 + 80) = Byte2Float(Interface, v69);
      v72 = *pos + 4;
      *pos = v72;
      v74 = *v20;
      *(v74 + 84) = Byte2Float(Interface, v72);
      v75 = *pos + 4;
      *pos = v75;
      v77 = *v20;
      *(v77 + 88) = Byte2Float(Interface, v75);
      v78 = *pos + 4;
      *pos = v78;
      v80 = *v20;
      *(v80 + 92) = Byte2Float(Interface, v78);
      v81 = *pos + 4;
      *pos = v81;
      v83 = *v20;
      *(v83 + 96) = Byte2Float(Interface, v81);
      v84 = *pos + 4;
      *pos = v84;
      v86 = *v20;
      *(v86 + 100) = Byte2Float(Interface, v84);
      v87 = *pos + 4;
      *pos = v87;
      v89 = *v20;
      *(v89 + 104) = Byte2UInt32(Interface, v87);
      v90 = *pos + 4;
      *pos = v90;
      v92 = *v20;
      *(v92 + 108) = Byte2UInt32(Interface, v90);
      v93 = *pos + 4;
      *pos = v93;
      v95 = *v20;
      *(v95 + 112) = Byte2UInt32(Interface, v93);
      v96 = *pos + 4;
      *pos = v96;
      v98 = *v20;
      *(v98 + 116) = Byte2UInt32(Interface, v96);
      *pos += 4;
      v100 = *v20;
      v101 = 0;
      *(v100 + 120) = NewSpecific(uint, 0x20u);
      do
      {
        v104 = *pos;
        v105 = *(*v20 + 120LL);
        v106 = Byte2UInt32(Interface, v104);
        v108 = v105 + 4 * v101++;
        *(v108 + 32) = v106;
        *pos += 4;
      }
      while (v101 != 32);
      ++v13;
    }
    while (v13 != v110);
  }
  return v8;
}

// 0x1a4ccc0
effPCP_BED_Param_t **effPCP_BED_Param_t__pCopy(effPCP_BED_Param_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  u32 *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u32 *v14;
  u64 v15;
  u64 *v16;
  s32 v18;
  s32 v21;
  s64 v23;
  s32 v24;
  s64 v26;
  u64 v28[3];

  v8 = max;
  v9 = NewSpecific(effPCP_BED_Param_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v28);
      if ((v28[0] & 1) != 0)
        v12 = v28[2];
      else
        v12 = v28 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = v9 + 8;
    v15 = 0;
    do
    {
      v16 = Allocate(effPCP_BED_Param_t);
      _ctor(v16, 0);
      *&v14[2 * v15] = v16;
      v18 = *pos;
      *(v16 + 4) = Byte2UInt32(Interface, v18);
      v21 = *pos + 4;
      *pos = v21;
      v23 = *&v14[2 * v15];
      *(v23 + 20) = Byte2UInt32(Interface, v21);
      v24 = *pos + 4;
      *pos = v24;
      v26 = *&v14[2 * v15];
      *(v26 + 24) = Byte2UInt32(Interface, v24);
      ++v15;
      *pos += 4;
    }
    while (v8 != v15);
  }
  return v9;
}

// 0x1a4cf80
effPCP_HBED2_Param_t **effPCP_HBED2_Param_t__pCopy(effPCP_HBED2_Param_t *this, void *pData, s32 *pos, s32 max) {
  u32 *v8;
  Il2CppClass *v9;
  s64 *Interface;
  char *v11;
  s64 *v12;
  u64 v13;
  Il2CppObject *v15;
  u64 *v17;
  effPCPHelperBEDParam_t_o *v18;
  u64 v22[3];

  v8 = NewSpecific(effPCP_HBED2_Param_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v9, v22);
      if ((v22[0] & 1) != 0)
        v11 = v22[2];
      else
        v11 = v22 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v13 = 0;
    do
    {
      v15 = Allocate(effPCP_HBED2_Param_t);
      _ctor(v15, 0);
      *&v8[2 * v13 + 8] = v15;
      v17 = Allocate(effPCPHelperBEDParam_t);
      _ctor(v17, 0);
      v15[1].klass = v17;
      effPCPHelperBEDParam_t__pCopy(v18, Interface, pos, max);
      ++v13;
    }
    while (max != v13);
  }
  return v8;
}

// 0x1a4d1b0
effPCP_PBCamera_Param_t **effPCP_PBCamera_Param_t__pCopy(effPCP_PBCamera_Param_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  u32 *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u64 v14;
  u64 *v15;
  s32 v17;
  u64 v21[3];

  v8 = max;
  v9 = NewSpecific(effPCP_PBCamera_Param_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v21);
      if ((v21[0] & 1) != 0)
        v12 = v21[2];
      else
        v12 = v21 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = 0;
    do
    {
      v15 = Allocate(effPCP_PBCamera_Param_t);
      _ctor(v15, 0);
      *&v9[2 * v14 + 8] = v15;
      v17 = *pos;
      *(v15 + 4) = Byte2UInt32(Interface, v17);
      ++v14;
      *pos += 4;
    }
    while (v8 != v14);
  }
  return v9;
}

// 0x1a4db70
void effPCP_ThunderColumnPolyLowParam_t__pClone(effPCP_ThunderColumnPolyLowParam_t *this, effPCP_ThunderColumnPolyLowParam_t **param) {
  effPCP_ThunderColumnPolyLowParam_t_o *v5;
  u64 *v6;

  (*param)->pos.x = this->pos.x;
  (*param)->pos.y = this->pos.y;
  (*param)->pos.z = this->pos.z;
  (*param)->pos.w = this->pos.w;
  v5 = *param;
  v6 = Allocate(effPCP_ThunderPolyParam_t);
  _ctor(v6, 0);
  v5->TP = v6;
  effPCP_ThunderPolyParam_t__pClone(this->TP, &(*param)->TP);
  (*param)->length = this->length;
  (*param)->number = this->number;
  (*param)->loop = this->loop;
  (*param)->life = this->life;
  (*param)->timing = this->timing;
  (*param)->fade_in = this->fade_in;
  (*param)->fade_out = this->fade_out;
  (*param)->radius = this->radius;
  (*param)->radius_r = this->radius_r;
  (*param)->height = this->height;
  (*param)->roll_s = this->roll_s;
  (*param)->roll_r = this->roll_r;
  (*param)->roll_a = this->roll_a;
  (*param)->up_s = this->up_s;
  (*param)->up_r = this->up_r;
  (*param)->up_a = this->up_a;
}

// 0x1a4d3f0
effPCP_ThunderColumnPolyLowParam_t **effPCP_ThunderColumnPolyLowParam_t__pCopy(effPCP_ThunderColumnPolyLowParam_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  effPCP_ThunderColumnPolyLowParam_t_array *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u64 v14;
  il2cpp_array_size_t *p_max_length;
  u64 *v17;
  s64 v20;
  s32 v21;
  s32 v22;
  s64 v24;
  s32 v25;
  s64 v27;
  s32 v28;
  s64 v30;
  s64 v32;
  u64 *v33;
  effPCP_ThunderPolyParam_t_o *v34;
  s32 v35;
  s64 v39;
  s32 v40;
  s64 v42;
  s32 v43;
  s32 v46;
  s64 v48;
  s32 v49;
  s64 v51;
  s32 v52;
  s64 v54;
  s32 v55;
  s64 v57;
  s32 v58;
  s64 v60;
  s32 v61;
  s64 v63;
  s32 v64;
  s64 v66;
  s32 v67;
  s64 v69;
  s32 v70;
  s64 v72;
  s32 v73;
  s64 v75;
  s32 v76;
  s64 v78;
  s32 v79;
  s64 v81;
  s32 v82;
  s64 v84;
  u64 v86[3];

  v8 = max;
  v9 = NewSpecific(effPCP_ThunderColumnPolyLowParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v86);
      if ((v86[0] & 1) != 0)
        v12 = v86[2];
      else
        v12 = v86 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = 0;
    p_max_length = &v9->max_length;
    do
    {
      v17 = Allocate(effPCP_ThunderColumnPolyLowParam_t);
      _ctor(v17, 0);
      v20 = &v9->m_Items[v14];
      *v20 = v17;
      v21 = *pos;
      *(v17 + 4) = Byte2Float(Interface, v21);
      v22 = *pos + 4;
      *pos = v22;
      v24 = *v20;
      *(v24 + 20) = Byte2Float(Interface, v22);
      v25 = *pos + 4;
      *pos = v25;
      v27 = *v20;
      *(v27 + 24) = Byte2Float(Interface, v25);
      v28 = *pos + 4;
      *pos = v28;
      v30 = *v20;
      *(v30 + 28) = Byte2Float(Interface, v28);
      *pos += 4;
      v32 = *v20;
      v33 = Allocate(effPCP_ThunderPolyParam_t);
      _ctor(v33, 0);
      *(v32 + 32) = v33;
      effPCP_ThunderPolyParam_t__pCopy(v34, Interface, pos, v35);
      *pos = 0;
      v39 = *v20;
      *(v39 + 40) = Byte2Float(Interface, 0);
      v40 = *pos + 4;
      *pos = v40;
      v42 = *v20;
      *(v42 + 44) = Byte2UInt32(Interface, v40);
      v43 = *pos + 4;
      *pos = v43;
      *(*v20 + 48LL) = *(Interface + v43 + 32);
      v46 = *pos + 4;
      *pos = v46;
      v48 = *v20;
      *(v48 + 52) = Byte2UInt32(Interface, v46);
      v49 = *pos + 4;
      *pos = v49;
      v51 = *v20;
      *(v51 + 56) = Byte2UInt32(Interface, v49);
      v52 = *pos + 4;
      *pos = v52;
      v54 = *v20;
      *(v54 + 60) = Byte2UInt32(Interface, v52);
      v55 = *pos + 4;
      *pos = v55;
      v57 = *v20;
      *(v57 + 64) = Byte2UInt32(Interface, v55);
      v58 = *pos + 4;
      *pos = v58;
      v60 = *v20;
      *(v60 + 68) = Byte2Float(Interface, v58);
      v61 = *pos + 4;
      *pos = v61;
      v63 = *v20;
      *(v63 + 72) = Byte2Float(Interface, v61);
      v64 = *pos + 4;
      *pos = v64;
      v66 = *v20;
      *(v66 + 76) = Byte2Float(Interface, v64);
      v67 = *pos + 4;
      *pos = v67;
      v69 = *v20;
      *(v69 + 80) = Byte2Float(Interface, v67);
      v70 = *pos + 4;
      *pos = v70;
      v72 = *v20;
      *(v72 + 84) = Byte2Float(Interface, v70);
      v73 = *pos + 4;
      *pos = v73;
      v75 = *v20;
      *(v75 + 88) = Byte2Float(Interface, v73);
      v76 = *pos + 4;
      *pos = v76;
      v78 = *v20;
      *(v78 + 92) = Byte2Float(Interface, v76);
      v79 = *pos + 4;
      *pos = v79;
      v81 = *v20;
      *(v81 + 96) = Byte2Float(Interface, v79);
      v82 = *pos + 4;
      *pos = v82;
      v84 = *v20;
      *(v84 + 100) = Byte2Float(Interface, v82);
      ++v14;
      *pos += 4;
    }
    while (v8 != v14);
  }
  return v9;
}

// 0x1a4dd00
void effPCP_ThunderPolyListParam_t__Clear(effPCP_ThunderPolyListParam_t *this) {
  struct UnityEngine_Vector4_array *pos;
  s64 v4;
  u64 v5;
  s32 v6;
  s32 v7;
  s32 v8;
  u32 *v10;
  s64 v11;
  s64 v12;

  pos = NewSpecific(UnityEngine_Vector4, 0xAu);
  v4 = 0;
  v5 = 0;
  this->pos = pos;
  while (1)
  {
    v11 = 0;
    v12 = 0;
    sub_854690(&v11, 0.0, 0.0, 0.0, 0.0);
    v6 = HIDWORD(v11);
    v8 = v12;
    v7 = HIDWORD(v12);
    v10 = (pos + v4);
    v10[8] = v11;
    v10[9] = v6;
    v10[10] = v8;
    v10[11] = v7;
    if (v5 == 9)
      break;
    pos = this->pos;
    ++v5;
    v4 += 16;
  }
  this->point = 0;
  this->TPParam = 0;
}

// 0x1a4de00
void effPCP_ThunderPolyListParam_t__pClone(effPCP_ThunderPolyListParam_t *this, effPCP_ThunderPolyListParam_t **param) {
  effPCP_ThunderPolyListParam_t_o *v5;
  effPCP_ThunderPolyListParam_t_o *v6;
  u64 v7;
  s64 v8;
  struct UnityEngine_Vector4_array *pos;
  struct UnityEngine_Vector4_array *v10;
  s32 *v12;
  s32 v13;
  s32 v14;
  s32 v15;
  s32 v16;
  u32 *v18;
  effPCP_ThunderPolyListParam_t_o *v19;
  u64 *v20;

  v5 = *param;
  v5->pos = NewSpecific(UnityEngine_Vector4, 0xAu);
  v6 = *param;
  v7 = 0;
  v8 = 44;
  do
  {
    pos = this->pos;
    v10 = v6->pos;
    v12 = (pos + v8);
    v13 = *(pos + v8 - 12);
    v14 = *(pos + v8 - 8);
    v15 = *(pos + v8 - 4);
    v16 = *v12;
    v18 = (v10 + v8);
    v8 += 16;
    *(v18 - 3) = v13;
    *(v18 - 2) = v14;
    *(v18 - 1) = v15;
    *v18 = v16;
    v6 = *param;
    ++v7;
  }
  while (v8 != 204);
  v6->point = this->point;
  v19 = *param;
  v20 = Allocate(effPCP_ThunderPolyParam_t);
  _ctor(v20, 0);
  v19->TPParam = v20;
  effPCP_ThunderPolyParam_t__pClone(this->TPParam, &(*param)->TPParam);
}

// 0x1a3a3f0
void effPCP_ThunderPolyParam_t__pClone(effPCP_ThunderPolyParam_t *this, effPCP_ThunderPolyParam_t **param) {
  effPCP_ThunderPolyParam_t_o *v5;
  struct UnityEngine_Vector4_array *pos;
  struct UnityEngine_Vector4_array *v8;
  struct UnityEngine_Vector4_array *v9;
  f32 x;
  struct UnityEngine_Vector4_array *v11;
  struct UnityEngine_Vector4_array *v12;
  f32 y;
  struct UnityEngine_Vector4_array *v14;
  struct UnityEngine_Vector4_array *v15;
  f32 z;
  struct UnityEngine_Vector4_array *v17;
  struct UnityEngine_Vector4_array *v18;
  f32 w;
  struct UnityEngine_Vector4_array *v20;
  struct UnityEngine_Vector4_array *v22;
  struct UnityEngine_Vector4_array *v23;
  f32 v24;
  struct UnityEngine_Vector4_array *v25;
  struct UnityEngine_Vector4_array *v26;
  f32 v27;
  struct UnityEngine_Vector4_array *v28;
  struct UnityEngine_Vector4_array *v29;
  f32 v30;
  struct UnityEngine_Vector4_array *v31;
  struct UnityEngine_Vector4_array *v32;
  f32 v33;

  v5 = *param;
  v5->pos = NewSpecific(UnityEngine_Vector4, 2u);
  pos = (*param)->pos;
  *&pos->m_Items[0].x = 0;
  *&pos->m_Items[0].z = 0;
  v8 = this->pos;
  v9 = (*param)->pos;
  x = v8->m_Items[0].x;
  v9->m_Items[0].x = x;
  v11 = this->pos;
  v12 = (*param)->pos;
  y = v11->m_Items[0].y;
  v12->m_Items[0].y = y;
  v14 = this->pos;
  v15 = (*param)->pos;
  z = v14->m_Items[0].z;
  v15->m_Items[0].z = z;
  v17 = this->pos;
  v18 = (*param)->pos;
  w = v17->m_Items[0].w;
  v18->m_Items[0].w = w;
  v20 = (*param)->pos;
  *&v20->m_Items[1].x = 0;
  *&v20->m_Items[1].z = 0;
  v22 = this->pos;
  v23 = (*param)->pos;
  v24 = v22->m_Items[1].x;
  v23->m_Items[1].x = v24;
  v25 = this->pos;
  v26 = (*param)->pos;
  v27 = v25->m_Items[1].y;
  v26->m_Items[1].y = v27;
  v28 = this->pos;
  v29 = (*param)->pos;
  v30 = v28->m_Items[1].z;
  v29->m_Items[1].z = v30;
  v31 = this->pos;
  v32 = (*param)->pos;
  v33 = v31->m_Items[1].w;
  v32->m_Items[1].w = v33;
  (*param)->blend = this->blend;
  (*param)->number = this->number;
  (*param)->life = this->life;
  (*param)->refraction = this->refraction;
  (*param)->interval = this->interval;
  (*param)->refresh = this->refresh;
  (*param)->split = this->split;
  (*param)->width_center = this->width_center;
  (*param)->color_center = this->color_center;
  (*param)->width_border = this->width_border;
  (*param)->color_border = this->color_border;
  (*param)->width_edge = this->width_edge;
  (*param)->color_edge = this->color_edge;
}

// 0x1a38010
effPCP_ThunderPolyParam_t *effPCP_ThunderPolyParam_t__pCopy(effPCP_ThunderPolyParam_t *this, void *pData, s32 *pos, s32 max) {
  u64 *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  u64 *v12;
  u64 v15;
  s32 v16;
  f32 v17;
  s32 v19;
  u64 v20;
  f32 v21;
  s32 v23;
  u64 v24;
  f32 v25;
  s32 v27;
  u64 v28;
  f32 v30;
  u64 v32;
  u64 v34;
  s32 v35;
  f32 v36;
  s32 v38;
  u64 v39;
  f32 v40;
  s32 v42;
  u64 v43;
  f32 v44;
  s32 v46;
  u64 v47;
  f32 v49;
  s32 v51;
  s32 v52;
  s32 v53;
  s32 v54;
  s32 v55;
  s32 v56;
  s32 v57;
  s32 v58;
  s32 v59;
  s32 v60;
  s32 v61;
  s32 v62;
  s32 v63;
  u64 v65[3];

  v7 = Allocate(effPCP_ThunderPolyParam_t);
  _ctor(v7, 0);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v8, v65);
      if ((v65[0] & 1) != 0)
        v10 = v65[2];
      else
        v10 = v65 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  v12 = NewSpecific(UnityEngine_Vector4, 2u);
  v7[2] = v12;
  v12[4] = 0;
  v12[5] = 0;
  v15 = v7[2];
  v16 = *pos;
  v17 = Byte2Float(Interface, v16);
  *(v15 + 32) = v17;
  v19 = *pos + 4;
  *pos = v19;
  v20 = v7[2];
  v21 = Byte2Float(Interface, v19);
  *(v20 + 36) = v21;
  v23 = *pos + 4;
  *pos = v23;
  v24 = v7[2];
  v25 = Byte2Float(Interface, v23);
  *(v24 + 40) = v25;
  v27 = *pos + 4;
  *pos = v27;
  v28 = v7[2];
  v30 = Byte2Float(Interface, v27);
  *(v28 + 44) = v30;
  *pos += 4;
  v32 = v7[2];
  *(v32 + 48) = 0;
  *(v32 + 56) = 0;
  v34 = v7[2];
  v35 = *pos;
  v36 = Byte2Float(Interface, v35);
  *(v34 + 48) = v36;
  v38 = *pos + 4;
  *pos = v38;
  v39 = v7[2];
  v40 = Byte2Float(Interface, v38);
  *(v39 + 52) = v40;
  v42 = *pos + 4;
  *pos = v42;
  v43 = v7[2];
  v44 = Byte2Float(Interface, v42);
  *(v43 + 56) = v44;
  v46 = *pos + 4;
  *pos = v46;
  v47 = v7[2];
  v49 = Byte2Float(Interface, v46);
  *(v47 + 60) = v49;
  v51 = *pos + 4;
  *pos = v51;
  *(v7 + 6) = Byte2UInt32(Interface, v51);
  v52 = *pos + 4;
  *pos = v52;
  *(v7 + 7) = Byte2UInt32(Interface, v52);
  v53 = *pos + 4;
  *pos = v53;
  *(v7 + 8) = Byte2UInt32(Interface, v53);
  v54 = *pos + 4;
  *pos = v54;
  *(v7 + 9) = Byte2Float(Interface, v54);
  v55 = *pos + 4;
  *pos = v55;
  *(v7 + 10) = Byte2UInt32(Interface, v55);
  v56 = *pos + 4;
  *pos = v56;
  *(v7 + 11) = Byte2UInt32(Interface, v56);
  v57 = *pos + 4;
  *pos = v57;
  *(v7 + 24) = Byte2UInt16(Interface, v57);
  v58 = *pos + 4;
  *pos = v58;
  *(v7 + 13) = Byte2Float(Interface, v58);
  v59 = *pos + 4;
  *pos = v59;
  *(v7 + 14) = Byte2UInt32(Interface, v59);
  v60 = *pos + 4;
  *pos = v60;
  *(v7 + 15) = Byte2Float(Interface, v60);
  v61 = *pos + 4;
  *pos = v61;
  *(v7 + 16) = Byte2UInt32(Interface, v61);
  v62 = *pos + 4;
  *pos = v62;
  *(v7 + 17) = Byte2Float(Interface, v62);
  v63 = *pos + 4;
  *pos = v63;
  *(v7 + 18) = Byte2UInt32(Interface, v63);
  *pos += 4;
  return v7;
}

// 0x1a4df60
effPCP_ThunderPolyPart_t **effPCP_ThunderPolyPart_t__pCopy(effPCP_ThunderPolyPart_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  u32 *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u32 *v14;
  u64 v15;
  u64 *v16;
  s32 v18;
  s32 v21;
  s64 v23;
  s32 v24;
  s64 v26;
  u64 v28[3];

  v8 = max;
  v9 = NewSpecific(effPCP_ThunderPolyPart_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v28);
      if ((v28[0] & 1) != 0)
        v12 = v28[2];
      else
        v12 = v28 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = v9 + 8;
    v15 = 0;
    do
    {
      v16 = Allocate(effPCP_ThunderPolyPart_t);
      _ctor(v16, 0);
      *&v14[2 * v15] = v16;
      v18 = *pos;
      *(v16 + 4) = Byte2UInt32(Interface, v18);
      v21 = *pos + 4;
      *pos = v21;
      v23 = *&v14[2 * v15];
      *(v23 + 20) = Byte2UInt32(Interface, v21);
      v24 = *pos + 4;
      *pos = v24;
      v26 = *&v14[2 * v15];
      *(v26 + 24) = Byte2UInt32(Interface, v24);
      ++v15;
      *pos += 4;
    }
    while (v8 != v15);
  }
  return v9;
}

// 0x1a4e8d0
void effPCP_ThunderRadiatePolyParam_t__pClone(effPCP_ThunderRadiatePolyParam_t *this, effPCP_ThunderRadiatePolyParam_t **param) {
  (*param)->fields = this->fields;
}

// 0x1a4e230
effPCP_ThunderRadiatePolyParam_t **effPCP_ThunderRadiatePolyParam_t__pCopy(effPCP_ThunderRadiatePolyParam_t *this, void *pData, s32 *pos, s32 max) {
  s64 v8;
  u32 *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u32 *v14;
  u64 v15;
  u64 *v16;
  s32 v18;
  s32 v21;
  s64 v23;
  s32 v24;
  s64 v26;
  s32 v27;
  s64 v29;
  s32 v30;
  s64 v32;
  s32 v33;
  s64 v35;
  s32 v36;
  s64 v38;
  s32 v39;
  s32 v42;
  s64 v44;
  s32 v45;
  s64 v47;
  s32 v48;
  s64 v50;
  s32 v51;
  s64 v53;
  s32 v54;
  s64 v56;
  s32 v57;
  s64 v59;
  s32 v60;
  s64 v62;
  s32 v63;
  s64 v65;
  s32 v66;
  s64 v68;
  s32 v69;
  s64 v71;
  u64 v73[3];

  v8 = max;
  v9 = NewSpecific(effPCP_ThunderRadiatePolyParam_t, max);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v10, v73);
      if ((v73[0] & 1) != 0)
        v12 = v73[2];
      else
        v12 = v73 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  if (max >= 1)
  {
    v14 = v9 + 8;
    v15 = 0;
    do
    {
      v16 = Allocate(effPCP_ThunderRadiatePolyParam_t);
      _ctor(v16, 0);
      *&v14[2 * v15] = v16;
      v18 = *pos;
      *(v16 + 4) = Byte2Float(Interface, v18);
      v21 = *pos + 4;
      *pos = v21;
      v23 = *&v14[2 * v15];
      *(v23 + 20) = Byte2Float(Interface, v21);
      v24 = *pos + 4;
      *pos = v24;
      v26 = *&v14[2 * v15];
      *(v26 + 24) = Byte2Float(Interface, v24);
      v27 = *pos + 4;
      *pos = v27;
      v29 = *&v14[2 * v15];
      *(v29 + 28) = Byte2Float(Interface, v27);
      v30 = *pos + 4;
      *pos = v30;
      v32 = *&v14[2 * v15];
      *(v32 + 32) = Byte2UInt32(Interface, v30);
      v33 = *pos + 4;
      *pos = v33;
      v35 = *&v14[2 * v15];
      *(v35 + 36) = Byte2Float(Interface, v33);
      v36 = *pos + 4;
      *pos = v36;
      v38 = *&v14[2 * v15];
      *(v38 + 40) = Byte2UInt32(Interface, v36);
      v39 = *pos + 4;
      *pos = v39;
      *(*&v14[2 * v15] + 44LL) = *(Interface + v39 + 32);
      v42 = *pos + 4;
      *pos = v42;
      v44 = *&v14[2 * v15];
      *(v44 + 48) = Byte2Float(Interface, v42);
      v45 = *pos + 4;
      *pos = v45;
      v47 = *&v14[2 * v15];
      *(v47 + 52) = Byte2UInt32(Interface, v45);
      v48 = *pos + 4;
      *pos = v48;
      v50 = *&v14[2 * v15];
      *(v50 + 56) = Byte2UInt32(Interface, v48);
      v51 = *pos + 4;
      *pos = v51;
      v53 = *&v14[2 * v15];
      *(v53 + 60) = Byte2UInt16(Interface, v51);
      v54 = *pos + 4;
      *pos = v54;
      v56 = *&v14[2 * v15];
      *(v56 + 64) = Byte2Float(Interface, v54);
      v57 = *pos + 4;
      *pos = v57;
      v59 = *&v14[2 * v15];
      *(v59 + 68) = Byte2UInt32(Interface, v57);
      v60 = *pos + 4;
      *pos = v60;
      v62 = *&v14[2 * v15];
      *(v62 + 72) = Byte2Float(Interface, v60);
      v63 = *pos + 4;
      *pos = v63;
      v65 = *&v14[2 * v15];
      *(v65 + 76) = Byte2UInt32(Interface, v63);
      v66 = *pos + 4;
      *pos = v66;
      v68 = *&v14[2 * v15];
      *(v68 + 80) = Byte2Float(Interface, v66);
      v69 = *pos + 4;
      *pos = v69;
      v71 = *&v14[2 * v15];
      *(v71 + 84) = Byte2UInt32(Interface, v69);
      ++v15;
      *pos += 4;
    }
    while (v8 != v15);
  }
  return v9;
}

// 0x1860180
void nbCameraAnim_t__Clear(nbCameraAnim_t *this) {
  *&this->rotate_f = 0;
  *&this->distance_f = 0;
}

// 0x1860190
void nbCameraAnim_t__Copy(nbCameraAnim_t *this, nbCameraAnim_t *data) {
  this->fields = data->fields;
}

// 0x18601f0
void nbCameraState_Start_t__Clear(nbCameraState_Start_t *this) {
  u64 *v3;
  u64 *v4;

  v3 = Allocate(effBezier4PPart_t);
  effBezier4PPart_t___ctor(v3);
  this->B4P_Target = v3;
  effBezier4PPart_t__Clear(v3);
  v4 = Allocate(effBezier4PPart_t);
  effBezier4PPart_t___ctor(v4);
  this->B4P_Eye = v4;
  effBezier4PPart_t__Clear(v4);
}

// 0x18602b0
void nbCamera_t__Clear(nbCamera_t *this) {
  f32 v3;
  f32 v4;
  f32 v5;
  f32 v6;
  Il2CppObject *v7;
  s64 v8;
  s64 v9;
  s64 v10;
  s64 v11;

  v10 = 0;
  v11 = 0;
  sub_854690(&v10, 0.0, 0.0, 0.0, 0.0);
  v4 = *&v11;
  v3 = *(&v11 + 1);
  *&this->target.x = v10;
  this->target.z = v4;
  this->target.w = v3;
  v8 = 0;
  v9 = 0;
  sub_854690(&v8, 0.0, 0.0, 0.0, 0.0);
  v6 = *&v9;
  v5 = *(&v9 + 1);
  *&this->direction.x = v8;
  this->direction.z = v6;
  this->direction.w = v5;
  *&this->state_old = 0;
  *&this->phase = 0;
  *&this->type = 0;
  *&this->distance = 0;
  *&this->state_change = 0;
  v7 = Allocate(nbCameraAnim_t);
  _ctor(v7, 0);
  this->anim = v7;
  v7[1].klass = 0;
  v7[1].monitor = 0;
}

// 0x18603a0
void nbCamera_t__Copy(nbCamera_t *this, nbCamera_t *data) {
  f32 z;
  f32 w;
  f32 v7;
  f32 v8;
  u64 *v9;
  struct nbCameraAnim_t_o *anim;

  z = data->target.z;
  w = data->target.w;
  *&this->target.x = *&data->target.x;
  this->target.z = z;
  this->target.w = w;
  v7 = data->direction.z;
  v8 = data->direction.w;
  *&this->direction.x = *&data->direction.x;
  this->direction.z = v7;
  this->direction.w = v8;
  this->distance = data->distance;
  this->fovy = data->fovy;
  this->state_change = data->state_change;
  this->state = data->state;
  this->state_old = data->state_old;
  this->state_old2 = data->state_old2;
  this->phase = data->phase;
  this->frame = data->frame;
  this->type = data->type;
  this->angle = data->angle;
  v9 = Allocate(nbCameraAnim_t);
  _ctor(v9, 0);
  this->anim = v9;
  anim = data->anim;
  *(v9 + 4) = anim->rotate_f;
  *(v9 + 5) = LODWORD(anim->rotate_s);
  *(v9 + 6) = anim->distance_f;
  *(v9 + 7) = LODWORD(anim->distance_s);
}

// 0x18604b0
void parPhysics_t__dCopy(parPhysics_t *this, parPhysics_t **dst) {
  parPhysics_t_o *v3;
  f32 z;
  f32 w;
  parPhysics_t_o *v6;
  f32 v7;
  f32 v8;
  parPhysics_t_o *v9;
  f32 v10;
  f32 v11;

  v3 = *dst;
  z = this->pos.z;
  w = this->pos.w;
  *&v3->pos.x = *&this->pos.x;
  v3->pos.z = z;
  v3->pos.w = w;
  v6 = *dst;
  v7 = this->dir.z;
  v8 = this->dir.w;
  *&v6->dir.x = *&this->dir.x;
  v6->dir.z = v7;
  v6->dir.w = v8;
  (*dst)->frame = this->frame;
  (*dst)->color = this->color;
  (*dst)->scale = this->scale;
  (*dst)->rot = this->rot;
  v9 = *dst;
  v10 = this->val_f.z;
  v11 = this->val_f.w;
  *&v9->val_f.x = *&this->val_f.x;
  v9->val_f.z = v10;
  v9->val_f.w = v11;
}
