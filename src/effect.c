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
    dds3Effect_Blur_t__Clear(0);
    Byte2UInt32(0, 0);
    Byte2Float(0, 0);
    return 0;
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
    Byte2UInt32(0, 0);
    dds3Effect_Blur_t__Clear(0);
    dds3Effect_Blur_t__pCopy(0, 0, 0, 0);
    return 0;
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
    Byte2Float(0, 0);
}

// 0x19d1560
void dds3ParOffsetBuffParts_t__dCopy(dds3ParOffsetBuffParts_t *this, dds3ParOffsetBuffParts_t **dst) {
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
    dds3Particle_EffItem_t__dCopy(0, 0);
    dds3ParticleColorAnim_t__dCopy(0, 0);
    dds3Particle_SparkOffset_t3__dCopy(0, 0, 0);
    dds3Particle_SmokeOffset_t3__dCopy(0, 0, 0);
    dds3Particle_SphereSpiral2_t3__dCopy(0, 0, 0);
}

// 0x19d20d0
void dds3Particle_Basic_t__pCopy(dds3Particle_Basic_t *this, u8 **bytedata, s32 *bpos) {
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    Byte2UInt16(0, 0);
    dds3Particle_Effect_t__pCopy(0, 0, 0);
    dds3ParticleColorAnim_t__pCopy(0, 0, 0);
    dds3Particle_Expansion_t__pCopy(0, 0, 0);
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
    }
    while (1)
    {
      v28 = Byte2UInt32(bytedata, v24);
      reserve->m_Items[v26] = v28;
      v24 = *bpos + 4;
      *bpos = v24;
      if (v26 == 31)
        break;
      reserve = this->reserve;
      ++v26;
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
}

// 0x19d6d00
void dds3SpPoly_Basic_t__pCopy(dds3SpPoly_Basic_t *this, u8 **bytedata, s32 *bpos) {
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    Byte2UInt16(0, 0);
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
}

// 0x19d68f0
void dds3TrackPoly_t__dCopy(dds3TrackPoly_t *this, dds3TrackPoly_t **dst) {
    dds3TrackPolyList_t__dCopy(0, 0);
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
  }
  while (1)
  {
    v32 = Byte2UInt32(bytedata, v28);
    reserve->m_Items[v30] = v32;
    v28 = *bPos + 4;
    *bPos = v28;
    if (v30 == 31)
      break;
    reserve = this->reserve;
    ++v30;
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
  }
  while (1)
  {
    v66 = Byte2UInt32(bytedata, v62);
    reserve->m_Items[v64] = v66;
    v62 = *bPos + 4;
    *bPos = v62;
    if (v64 == 63)
      break;
    reserve = this->reserve;
    ++v64;
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
  }
  while (1)
  {
    v39 = Byte2UInt32(bytedata, v35);
    reserve->m_Items[v37] = v39;
    v35 = *bPos + 4;
    *bPos = v35;
    if (v37 == 63)
      break;
    reserve = this->reserve;
    ++v37;
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
  }
  while (1)
  {
    v32 = Byte2UInt32(bytedata, v28);
    reserve->m_Items[v30] = v32;
    v28 = *bPos + 4;
    *bPos = v28;
    if (v30 == 31)
      break;
    reserve = this->reserve;
    ++v30;
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
  }
  while (1)
  {
    v33 = Byte2UInt32(bytedata, v29);
    reserve->m_Items[v31] = v33;
    v29 = *bPos + 4;
    *bPos = v29;
    if (v31 == 31)
      break;
    reserve = this->reserve;
    ++v31;
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
    Byte2UInt32(0, 0);
    effPCPAgiFireballParam_t__pCopy(0, 0, 0, 0);
    return 0;
}

// 0x19debb0
effPCPAgiFireballParam_t **effPCPAgiFireballParam_t__pCopy(effPCPAgiFireballParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    return 0;
}

// 0x19df640
void effPCPAgiFireballPartList_t__Clear(effPCPAgiFireballPartList_t *this) {
  ;
}

// 0x19df650
effPCPAgiraoFireParam_t **effPCPAgiraoFireParam_t__pCopy(effPCPAgiraoFireParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    return 0;
}

// 0x19e0650
void effPCPBezierBillParam_t__pClone(effPCPBezierBillParam_t *this, effPCPBezierBillParam_t **dst) {
  (*dst)->fields = this->fields;
}

// 0x19dff60
effPCPBezierBillParam_t **effPCPBezierBillParam_t__pCopy(effPCPBezierBillParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    return 0;
}

// 0x19e0760
effPCPBlurExpParam_t **effPCPBlurExpParam_t__pCopy(effPCPBlurExpParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2UInt32(0, 0);
    dds3Effect_Blur_t__Clear(0);
    dds3Effect_Blur_t__SetData(0, 0, 0);
    return 0;
}

// 0x19e0c80
effPCPBossBaelParam_t **effPCPBossBaelParam_t__pCopy(effPCPBossBaelParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    return 0;
}

// 0x19e0fc0
effPCPBossDengekiParam_t **effPCPBossDengekiParam_t__pCopy(effPCPBossDengekiParam_t *this, void *pData, s32 *pos, s32 max) {
    effPCP_ThunderPolyParam_t__pCopy(0, 0, 0, 0);
    Byte2Float(0, 0);
    return 0;
}

// 0x19e1250
effPCPBossKAGU2AttackParam_t **effPCPBossKAGU2AttackParam_t__pCopy(effPCPBossKAGU2AttackParam_t *this, void *pData, s32 *pos, s32 max) {
    effPCP_ThunderPolyParam_t__pCopy(0, 0, 0, 0);
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    return 0;
}

// 0x19e1690
effPCPBossKAGUAttackParam_t **effPCPBossKAGUAttackParam_t__pCopy(effPCPBossKAGUAttackParam_t *this, void *pData, s32 *pos, s32 max) {
    effPCP_ThunderPolyParam_t__pCopy(0, 0, 0, 0);
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    return 0;
}

// 0x19e1ab0
effPCPBossKAGUInvokeParam_t **effPCPBossKAGUInvokeParam_t__pCopy(effPCPBossKAGUInvokeParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    effPCP_ThunderPolyParam_t__pCopy(0, 0, 0, 0);
    Byte2UInt32(0, 0);
    return 0;
}

// 0x19e2240
effPCPBossKAGUThunderboltParam_t **effPCPBossKAGUThunderboltParam_t__pCopy(effPCPBossKAGUThunderboltParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    effPCP_ThunderPolyParam_t__pCopy(0, 0, 0, 0);
    effPCPCrackParam_t__pCopy(0, 0, 0, 0);
    Byte2UInt32(0, 0);
    return 0;
}

// 0x19e2750
effPCPBossMETATOBeamParam_t **effPCPBossMETATOBeamParam_t__pCopy(effPCPBossMETATOBeamParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    effPCP_ThunderPolyParam_t__pCopy(0, 0, 0, 0);
    Byte2UInt32(0, 0);
    return 0;
}

// 0x1a37c90
effPCPBossThunderboltParam_t **effPCPBossThunderboltParam_t__pCopy(effPCPBossThunderboltParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    effPCP_ThunderPolyParam_t__pCopy(0, 0, 0, 0);
    return 0;
}

// 0x1a38550
effPCPBreathParam_t **effPCPBreathParam_t__pCopy(effPCPBreathParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    return 0;
}

// 0x1a38990
effPCPCrack2Param_t **effPCPCrack2Param_t__pCopy(effPCPCrack2Param_t *this, void *pData, s32 *pos, s32 max) {
    effPCPCrackParam_t__pCopy(0, 0, 0, 0);
    Byte2UInt32(0, 0);
    Byte2Float(0, 0);
    return 0;
}

// 0x1a39820
void effPCPCrackParam_t__pClone(effPCPCrackParam_t *this, effPCPCrackParam_t **param) {
}

// 0x1a38c80
effPCPCrackParam_t **effPCPCrackParam_t__pCopy(effPCPCrackParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    return 0;
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
    Byte2UInt32(0, 0);
    return 0;
}

// 0x1a39dd0
effPCPDANTE_ShowTime_Param_t **effPCPDANTE_ShowTime_Param_t__pCopy(effPCPDANTE_ShowTime_Param_t *this, void *pData, s32 *pos, s32 max) {
    Byte2UInt32(0, 0);
    return 0;
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
    effPCP_ThunderPolyParam_t__pCopy(0, 0, 0, 0);
    Byte2UInt32(0, 0);
    return 0;
}

// 0x1a3a810
effPCPDistortionBlurExpParam_t **effPCPDistortionBlurExpParam_t__pCopy(effPCPDistortionBlurExpParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2UInt32(0, 0);
    dds3Effect_DistortionBlurParam_t__SetData(0, 0, 0);
    return 0;
}

// 0x1a3ac20
effPCPFLEACHBlurParam_t **effPCPFLEACHBlurParam_t__pCopy(effPCPFLEACHBlurParam_t *this, void *pData, s32 *pos, s32 max) {
    dds3Effect_PartialMultiBlurParam_t__pCopy(0, 0, 0, 0);
    Byte2UInt32(0, 0);
    return 0;
}

// 0x1a3afb0
effPCPFilterExpParam_t **effPCPFilterExpParam_t__pCopy(effPCPFilterExpParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2UInt32(0, 0);
    dds3Effect_Filter_t__SetData(0, 0, 0);
    return 0;
}

// 0x1a3b960
void effPCPFlashPolyCircleParam_t__pClone(effPCPFlashPolyCircleParam_t *this, effPCPFlashPolyCircleParam_t **param) {
    CutRaitoGet(0, 0);
}

// 0x1a3b2f0
effPCPFlashPolyCircleParam_t **effPCPFlashPolyCircleParam_t__pCopy(effPCPFlashPolyCircleParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    return 0;
}

// 0x1a3c220
void effPCPFlashPolyPipeParam_t__pClone(effPCPFlashPolyPipeParam_t *this, effPCPFlashPolyPipeParam_t **param) {
    CutRaitoGet(0, 0);
}

// 0x1a3bac0
effPCPFlashPolyPipeParam_t **effPCPFlashPolyPipeParam_t__pCopy(effPCPFlashPolyPipeParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    return 0;
}

// 0x1a3cb10
void effPCPFlashPolyRingExp2Param_t__pClone(effPCPFlashPolyRingExp2Param_t *this, effPCPFlashPolyRingExp2Param_t **param) {
    CutRaitoGet(0, 0);
}

// 0x1a3c3b0
effPCPFlashPolyRingExp2Param_t **effPCPFlashPolyRingExp2Param_t__pCopy(effPCPFlashPolyRingExp2Param_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    return 0;
}

// 0x1a3d480
void effPCPFlashPolyRingExpParam_t__pClone(effPCPFlashPolyRingExpParam_t *this, effPCPFlashPolyRingExpParam_t **param) {
    CutRaitoGet(0, 0);
}

// 0x1a3cca0
effPCPFlashPolyRingExpParam_t **effPCPFlashPolyRingExpParam_t__pCopy(effPCPFlashPolyRingExpParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    return 0;
}

// 0x1a3dd00
void effPCPFlashPolyRingParam_t__pClone(effPCPFlashPolyRingParam_t *this, effPCPFlashPolyRingParam_t **param) {
    CutRaitoGet(0, 0);
}

// 0x1a3d620
effPCPFlashPolyRingParam_t **effPCPFlashPolyRingParam_t__pCopy(effPCPFlashPolyRingParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    return 0;
}

// 0x1a3e4a0
void effPCPFlashPolySphere2ExpParam_t__pClone(effPCPFlashPolySphere2ExpParam_t *this, effPCPFlashPolySphere2ExpParam_t **param) {
    CutRaitoGet(0, 0);
}

// 0x1a3de70
effPCPFlashPolySphere2ExpParam_t **effPCPFlashPolySphere2ExpParam_t__pCopy(effPCPFlashPolySphere2ExpParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    return 0;
}

// 0x1a3eb60
void effPCPFlashPolySphere2Param_t__pClone(effPCPFlashPolySphere2Param_t *this, effPCPFlashPolySphere2Param_t **param) {
    CutRaitoGet(0, 0);
}

// 0x1a3e5f0
effPCPFlashPolySphere2Param_t **effPCPFlashPolySphere2Param_t__pCopy(effPCPFlashPolySphere2Param_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    return 0;
}

// 0x1a3f530
void effPCPFlashPolySphere3Param_t__pClone(effPCPFlashPolySphere3Param_t *this, effPCPFlashPolySphere3Param_t **param) {
    CutRaitoGet(0, 0);
}

// 0x1a3ec90
effPCPFlashPolySphere3Param_t **effPCPFlashPolySphere3Param_t__pCopy(effPCPFlashPolySphere3Param_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    return 0;
}

// 0x1a3fe80
void effPCPFlashPolySphereExpParam_t__pClone(effPCPFlashPolySphereExpParam_t *this, effPCPFlashPolySphereExpParam_t **param) {
    CutRaitoGet(0, 0);
}

// 0x1a3f740
effPCPFlashPolySphereExpParam_t **effPCPFlashPolySphereExpParam_t__pCopy(effPCPFlashPolySphereExpParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    return 0;
}

// 0x1a40670
void effPCPFlashPolySphereParam_t__pClone(effPCPFlashPolySphereParam_t *this, effPCPFlashPolySphereParam_t **param) {
    CutRaitoGet(0, 0);
}

// 0x1a40000
effPCPFlashPolySphereParam_t **effPCPFlashPolySphereParam_t__pCopy(effPCPFlashPolySphereParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    return 0;
}

// 0x1a40ed0
void effPCPHamaCardScatterParam_t__pClone(effPCPHamaCardScatterParam_t *this, effPCPHamaCardScatterParam_t **param) {
}

// 0x1a407d0
effPCPHamaCardScatterParam_t **effPCPHamaCardScatterParam_t__pCopy(effPCPHamaCardScatterParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    return 0;
}

// 0x1a41870
void effPCPHamaCardSphereParam_t__pClone(effPCPHamaCardSphereParam_t *this, effPCPHamaCardSphereParam_t **param) {
}

// 0x1a40fe0
effPCPHamaCardSphereParam_t **effPCPHamaCardSphereParam_t__pCopy(effPCPHamaCardSphereParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    return 0;
}

// 0x1a42360
void effPCPHamaCardSpiralParam_t__pClone(effPCPHamaCardSpiralParam_t *this, effPCPHamaCardSpiralParam_t **param) {
}

// 0x1a419d0
effPCPHamaCardSpiralParam_t **effPCPHamaCardSpiralParam_t__pCopy(effPCPHamaCardSpiralParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    return 0;
}

// 0x1a428b0
void effPCPHelperBEDParam_t__pClone(effPCPHelperBEDParam_t *this, effPCPHelperBEDParam_t **param) {
}

// 0x1a424f0
effPCPHelperBEDParam_t **effPCPHelperBEDParam_t__pCopy(effPCPHelperBEDParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    return 0;
}

// 0x1a42930
effPCPMultiBlurExp2Param_t **effPCPMultiBlurExp2Param_t__pCopy(effPCPMultiBlurExp2Param_t *this, void *pData, s32 *pos, s32 max) {
    Byte2UInt32(0, 0);
    dds3Effect_PartialMultiBlurParam_t__SetData(0, 0, 0);
    return 0;
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
    Byte2UInt32(0, 0);
    dds3Effect_PartialMultiFilterParam_t__SetData(0, 0, 0);
    return 0;
}

// 0x1a43300
effPCPMuzzleFlashParam_t **effPCPMuzzleFlashParam_t__pCopy(effPCPMuzzleFlashParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    return 0;
}

// 0x1a43e20
void effPCPNeedleSpiralParam_t__pClone(effPCPNeedleSpiralParam_t *this, effPCPNeedleSpiralParam_t **param) {
}

// 0x1a43580
effPCPNeedleSpiralParam_t **effPCPNeedleSpiralParam_t__pCopy(effPCPNeedleSpiralParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    return 0;
}

// 0x1a43ff0
effPCPRadiateBEDParam_t **effPCPRadiateBEDParam_t__pCopy(effPCPRadiateBEDParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    return 0;
}

// 0x1a44950
effPCPRadiateTBParam_t **effPCPRadiateTBParam_t__pCopy(effPCPRadiateTBParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    effPCP_ThunderPolyParam_t__pCopy(0, 0, 0, 0);
    return 0;
}

// 0x1a44f40
effPCPRadiateThunderAttach_t **effPCPRadiateThunderAttach_t__pCopy(effPCPRadiateThunderAttach_t *this, void *pData, s32 *pos, s32 max) {
    return 0;
}

// 0x1a45e70
void effPCPRadiateThunderParam_t__pClone(effPCPRadiateThunderParam_t *this, effPCPRadiateThunderParam_t **param) {
    effPCP_ThunderPolyParam_t__pClone(0, 0);
}

// 0x1a45390
effPCPRadiateThunderParam_t **effPCPRadiateThunderParam_t__pCopy(effPCPRadiateThunderParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    effPCPRadiateThunderAttach_t__pCopy(0, 0, 0, 0);
    effPCP_ThunderPolyParam_t__pCopy(0, 0, 0, 0);
    return 0;
}

// 0x1a46390
effPCPRingPolyExp2Param_t **effPCPRingPolyExp2Param_t__pCopy(effPCPRingPolyExp2Param_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    return 0;
}

// 0x1a46b60
effPCPRingPolyExpParam_t **effPCPRingPolyExpParam_t__pCopy(effPCPRingPolyExpParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    return 0;
}

// 0x1a47250
effPCPRippleBlurExpParam_t **effPCPRippleBlurExpParam_t__pCopy(effPCPRippleBlurExpParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2UInt32(0, 0);
    dds3Effect_RippleBlurParam_t__SetData(0, 0, 0);
    return 0;
}

// 0x1a47660
effPCPScreenCrackModelParam_t **effPCPScreenCrackModelParam_t__pCopy(effPCPScreenCrackModelParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    return 0;
}

// 0x1a478c0
effPCPSpiralBEDParam_t **effPCPSpiralBEDParam_t__pCopy(effPCPSpiralBEDParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    return 0;
}

// 0x1a48170
effPCPThunderSphereExpParam_t **effPCPThunderSphereExpParam_t__pCopy(effPCPThunderSphereExpParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2UInt32(0, 0);
    effPCPThunderSpherePolyParam_t__pCopy(0, 0, 0, 0);
    return 0;
}

// 0x1a48c20
void effPCPThunderSpherePolyParam_t__pClone(effPCPThunderSpherePolyParam_t *this, effPCPThunderSpherePolyParam_t **param) {
  (*param)->fields = this->fields;
}

// 0x1a48530
effPCPThunderSpherePolyParam_t **effPCPThunderSpherePolyParam_t__pCopy(effPCPThunderSpherePolyParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    Byte2UInt16(0, 0);
    return 0;
}

// 0x1a499d0
void effPCPWhirlwind2PolyParam_t__pClone(effPCPWhirlwind2PolyParam_t *this, effPCPWhirlwind2PolyParam_t **param) {
}

// 0x1a48d30
effPCPWhirlwind2PolyParam_t **effPCPWhirlwind2PolyParam_t__pCopy(effPCPWhirlwind2PolyParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    return 0;
}

// 0x1a4a970
void effPCPWhirlwind3PolyParam_t__pClone(effPCPWhirlwind3PolyParam_t *this, effPCPWhirlwind3PolyParam_t **param) {
}

// 0x1a49c50
effPCPWhirlwind3PolyParam_t **effPCPWhirlwind3PolyParam_t__pCopy(effPCPWhirlwind3PolyParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    return 0;
}

// 0x1a4bb70
void effPCPWhirlwindPolyParam_t__pClone(effPCPWhirlwindPolyParam_t *this, effPCPWhirlwindPolyParam_t **param) {
}

// 0x1a4af10
effPCPWhirlwindPolyParam_t **effPCPWhirlwindPolyParam_t__pCopy(effPCPWhirlwindPolyParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    return 0;
}

// 0x1a4ca90
void effPCPWwSpherePolyParam_t__pClone(effPCPWwSpherePolyParam_t *this, effPCPWwSpherePolyParam_t **param) {
}

// 0x1a4c0f0
effPCPWwSpherePolyParam_t **effPCPWwSpherePolyParam_t__pCopy(effPCPWwSpherePolyParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    return 0;
}

// 0x1a4ccc0
effPCP_BED_Param_t **effPCP_BED_Param_t__pCopy(effPCP_BED_Param_t *this, void *pData, s32 *pos, s32 max) {
    Byte2UInt32(0, 0);
    return 0;
}

// 0x1a4cf80
effPCP_HBED2_Param_t **effPCP_HBED2_Param_t__pCopy(effPCP_HBED2_Param_t *this, void *pData, s32 *pos, s32 max) {
    effPCPHelperBEDParam_t__pCopy(0, 0, 0, 0);
    return 0;
}

// 0x1a4d1b0
effPCP_PBCamera_Param_t **effPCP_PBCamera_Param_t__pCopy(effPCP_PBCamera_Param_t *this, void *pData, s32 *pos, s32 max) {
    Byte2UInt32(0, 0);
    return 0;
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
    Byte2Float(0, 0);
    effPCP_ThunderPolyParam_t__pCopy(0, 0, 0, 0);
    Byte2UInt32(0, 0);
    return 0;
}

// 0x1a4dd00
void effPCP_ThunderPolyListParam_t__Clear(effPCP_ThunderPolyListParam_t *this) {
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
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    Byte2UInt16(0, 0);
    return 0;
}

// 0x1a4df60
effPCP_ThunderPolyPart_t **effPCP_ThunderPolyPart_t__pCopy(effPCP_ThunderPolyPart_t *this, void *pData, s32 *pos, s32 max) {
    Byte2UInt32(0, 0);
    return 0;
}

// 0x1a4e8d0
void effPCP_ThunderRadiatePolyParam_t__pClone(effPCP_ThunderRadiatePolyParam_t *this, effPCP_ThunderRadiatePolyParam_t **param) {
  (*param)->fields = this->fields;
}

// 0x1a4e230
effPCP_ThunderRadiatePolyParam_t **effPCP_ThunderRadiatePolyParam_t__pCopy(effPCP_ThunderRadiatePolyParam_t *this, void *pData, s32 *pos, s32 max) {
    Byte2Float(0, 0);
    Byte2UInt32(0, 0);
    Byte2UInt16(0, 0);
    return 0;
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
