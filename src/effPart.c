#include "types.h"

typedef struct EffectHD EffectHD;
typedef struct ModelHD ModelHD;
typedef struct SOBED_PB_LIST SOBED_PB_LIST;
typedef struct XRD773Unity_GraphicManager_CommonObject XRD773Unity_GraphicManager_CommonObject;
typedef struct billHandle_t billHandle_t;
typedef struct dds3EffectPCPData_Part_t dds3EffectPCPData_Part_t;
typedef struct dds3EffectPCPData_t dds3EffectPCPData_t;
typedef struct dds3EffectPCP_t dds3EffectPCP_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct effPCPAgiFireball2Param_t effPCPAgiFireball2Param_t;
typedef struct effPCPAgiFireballParam_t effPCPAgiFireballParam_t;
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
typedef struct effPCPMultiFilterExpParam_t effPCPMultiFilterExpParam_t;
typedef struct effPCPMuzzleFlashParam_t effPCPMuzzleFlashParam_t;
typedef struct effPCPNeedleSpiralParam_t effPCPNeedleSpiralParam_t;
typedef struct effPCPRadiateBEDParam_t effPCPRadiateBEDParam_t;
typedef struct effPCPRadiateTBParam_t effPCPRadiateTBParam_t;
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
typedef struct effPartHandle_t effPartHandle_t;
typedef struct effPart_dds3EffectPartFuncTable_tag effPart_dds3EffectPartFuncTable_tag;
typedef struct effPart_dds3EffectPartFuncTable_tag_CopyDelegate effPart_dds3EffectPartFuncTable_tag_CopyDelegate;
typedef struct effPart_dds3EffectPartFuncTable_tag_CreateDelegate effPart_dds3EffectPartFuncTable_tag_CreateDelegate;
typedef struct effPart_dds3EffectPartFuncTable_tag_DeleteDelegate effPart_dds3EffectPartFuncTable_tag_DeleteDelegate;
typedef struct effPart_dds3EffectPartFuncTable_tag_DrawDelegate effPart_dds3EffectPartFuncTable_tag_DrawDelegate;
typedef struct effPart_dds3EffectPartFuncTable_tag_SetAreaDelegate effPart_dds3EffectPartFuncTable_tag_SetAreaDelegate;
typedef struct effPart_dds3EffectPartFuncTable_tag_SetColorDelegate effPart_dds3EffectPartFuncTable_tag_SetColorDelegate;
typedef struct effPart_dds3EffectPartFuncTable_tag_SetDirectionDelegate effPart_dds3EffectPartFuncTable_tag_SetDirectionDelegate;
typedef struct effPart_dds3EffectPartFuncTable_tag_SetPositionDelegate effPart_dds3EffectPartFuncTable_tag_SetPositionDelegate;
typedef struct effPart_dds3EffectPartFuncTable_tag_SetRotateMatrixDelegate effPart_dds3EffectPartFuncTable_tag_SetRotateMatrixDelegate;
typedef struct effPart_dds3EffectPartFuncTable_tag_SetScaleDelegate effPart_dds3EffectPartFuncTable_tag_SetScaleDelegate;
typedef struct sdfModelOt_t sdfModelOt_t;

struct effPart_dds3EffectPartFuncTable_tag {
    effPart_dds3EffectPartFuncTable_tag_CreateDelegate *mCreate;
    effPart_dds3EffectPartFuncTable_tag_DrawDelegate *mDraw;
    effPart_dds3EffectPartFuncTable_tag_DeleteDelegate *mDelete;
    effPart_dds3EffectPartFuncTable_tag_CopyDelegate *mCopy;
    effPart_dds3EffectPartFuncTable_tag_SetPositionDelegate *mSetPosition;
    effPart_dds3EffectPartFuncTable_tag_SetScaleDelegate *mSetScale;
    effPart_dds3EffectPartFuncTable_tag_SetRotateMatrixDelegate *mSetRotateMatrix;
    effPart_dds3EffectPartFuncTable_tag_SetColorDelegate *mSetColor;
    effPart_dds3EffectPartFuncTable_tag_SetDirectionDelegate *mSetDirection;
    effPart_dds3EffectPartFuncTable_tag_SetAreaDelegate *mSetArea;
    effPart_dds3EffectPartFuncTable_tag_DrawDelegate *mDrawOff;
};

static sdfModelOt_t *dds3ModelOt[11];
static effPart_dds3EffectPartFuncTable_tag *EffectPartFuncTable[7];
static s32 effPart_nextp;
static effPart_dds3EffectPartFuncTable_tag *EffectPCPFuncTable[106];

u32 Byte2UInt32(u8 **bytedata, s32 pos);
dds3EffectPCPData_Part_t *GetByte2Parts(void *hPCPData, u32 number, s32 bPos);
SOBED_PB_LIST *GetPbList(void);
void SDF_VU0__LOADMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SetAutoHide(XRD773Unity_GraphicManager_CommonObject *this, bool act);
void SetFrameAnime(ModelHD *this, bool act);
void SethModel(EffectHD *this, dds3ModelHandle_t *sModel);
void SobedPbSet(u8 **bytedata, s32 bPos);
void StepFrame(ModelHD *this);
void *_Get_effPCPParamTable(u32 kateg, u32 param);
billHandle_t *dds3BillboardCreate(s32 type, void *pTex, s32 bPos, char *callname);
void dds3BillboardSetScale(billHandle_t **hBillboard, f32 x, f32 y);
void *dds3EffectPCPDataGetDataUnityOffSet(void *hData, s32 offset, s32 type);
void dds3EffectPCPData_t__pCopy(dds3EffectPCPData_t *this, u8 **bytedata, s32 *pos);
effPartHandle_t *dds3EffectPartCopy(effPartHandle_t **hEffPartSrc);
effPartHandle_t *dds3EffectPartCreate(u16 type, void *pData);
void dds3EffectPartDelete(effPartHandle_t **hEffPart);
void dds3EffectPartDraw(effPartHandle_t **hEffPart);
void dds3EffectPartDrawOff(effPartHandle_t **hEffPart);
void dds3EffectPartModelInit(dds3ModelHandle_t **hModel);
void dds3EffectPartSetColor(effPartHandle_t **hEffPart, u32 abgr);
void dds3EffectPartSetPosition(effPartHandle_t **hEffPart, sdfVector4_t pPos);
void dds3EffectPartSetRotateMatrix(effPartHandle_t **hEffPart, sdfMatrix4_t *pMatrix);
void dds3EffectPartSetScale(effPartHandle_t **hEffPart, f32 scale);
void dds3ModelHandle_t__dCopy(dds3ModelHandle_t *this, dds3ModelHandle_t **dst);
effPCPAgiFireball2Param_t **effPCPAgiFireball2Param_t__pCopy(effPCPAgiFireball2Param_t *this, void *pData, s32 *pos, s32 max);
effPCPAgiFireballParam_t **effPCPAgiFireballParam_t__pCopy(effPCPAgiFireballParam_t *this, void *pData, s32 *pos, s32 max);
effPCPAgiraoFireParam_t **effPCPAgiraoFireParam_t__pCopy(effPCPAgiraoFireParam_t *this, void *pData, s32 *pos, s32 max);
effPCPBezierBillParam_t **effPCPBezierBillParam_t__pCopy(effPCPBezierBillParam_t *this, void *pData, s32 *pos, s32 max);
effPCPBlurExpParam_t **effPCPBlurExpParam_t__pCopy(effPCPBlurExpParam_t *this, void *pData, s32 *pos, s32 max);
effPCPBossBaelParam_t **effPCPBossBaelParam_t__pCopy(effPCPBossBaelParam_t *this, void *pData, s32 *pos, s32 max);
effPCPBossDengekiParam_t **effPCPBossDengekiParam_t__pCopy(effPCPBossDengekiParam_t *this, void *pData, s32 *pos, s32 max);
effPCPBossKAGU2AttackParam_t **effPCPBossKAGU2AttackParam_t__pCopy(effPCPBossKAGU2AttackParam_t *this, void *pData, s32 *pos, s32 max);
effPCPBossKAGUAttackParam_t **effPCPBossKAGUAttackParam_t__pCopy(effPCPBossKAGUAttackParam_t *this, void *pData, s32 *pos, s32 max);
effPCPBossKAGUInvokeParam_t **effPCPBossKAGUInvokeParam_t__pCopy(effPCPBossKAGUInvokeParam_t *this, void *pData, s32 *pos, s32 max);
effPCPBossKAGUThunderboltParam_t **effPCPBossKAGUThunderboltParam_t__pCopy(effPCPBossKAGUThunderboltParam_t *this, void *pData, s32 *pos, s32 max);
effPCPBossMETATOBeamParam_t **effPCPBossMETATOBeamParam_t__pCopy(effPCPBossMETATOBeamParam_t *this, void *pData, s32 *pos, s32 max);
effPCPBossThunderboltParam_t **effPCPBossThunderboltParam_t__pCopy(effPCPBossThunderboltParam_t *this, void *pData, s32 *pos, s32 max);
effPCPBreathParam_t **effPCPBreathParam_t__pCopy(effPCPBreathParam_t *this, void *pData, s32 *pos, s32 max);
effPCPCrack2Param_t **effPCPCrack2Param_t__pCopy(effPCPCrack2Param_t *this, void *pData, s32 *pos, s32 max);
effPCPCrackParam_t **effPCPCrackParam_t__pCopy(effPCPCrackParam_t *this, void *pData, s32 *pos, s32 max);
effPCPDANTE_Damage_Param_t **effPCPDANTE_Damage_Param_t__pCopy(effPCPDANTE_Damage_Param_t *this, void *pData, s32 *pos, s32 max);
effPCPDANTE_ShowTime_Param_t **effPCPDANTE_ShowTime_Param_t__pCopy(effPCPDANTE_ShowTime_Param_t *this, void *pData, s32 *pos, s32 max);
effPCPDANTE_Thunder_Param_t **effPCPDANTE_Thunder_Param_t__pCopy(effPCPDANTE_Thunder_Param_t *this, void *pData, s32 *pos, s32 max);
effPCPDistortionBlurExpParam_t **effPCPDistortionBlurExpParam_t__pCopy(effPCPDistortionBlurExpParam_t *this, void *pData, s32 *pos, s32 max);
effPCPFLEACHBlurParam_t **effPCPFLEACHBlurParam_t__pCopy(effPCPFLEACHBlurParam_t *this, void *pData, s32 *pos, s32 max);
effPCPFilterExpParam_t **effPCPFilterExpParam_t__pCopy(effPCPFilterExpParam_t *this, void *pData, s32 *pos, s32 max);
effPCPFlashPolyCircleParam_t **effPCPFlashPolyCircleParam_t__pCopy(effPCPFlashPolyCircleParam_t *this, void *pData, s32 *pos, s32 max);
effPCPFlashPolyPipeParam_t **effPCPFlashPolyPipeParam_t__pCopy(effPCPFlashPolyPipeParam_t *this, void *pData, s32 *pos, s32 max);
effPCPFlashPolyRingExp2Param_t **effPCPFlashPolyRingExp2Param_t__pCopy(effPCPFlashPolyRingExp2Param_t *this, void *pData, s32 *pos, s32 max);
effPCPFlashPolyRingExpParam_t **effPCPFlashPolyRingExpParam_t__pCopy(effPCPFlashPolyRingExpParam_t *this, void *pData, s32 *pos, s32 max);
effPCPFlashPolyRingParam_t **effPCPFlashPolyRingParam_t__pCopy(effPCPFlashPolyRingParam_t *this, void *pData, s32 *pos, s32 max);
effPCPFlashPolySphere2ExpParam_t **effPCPFlashPolySphere2ExpParam_t__pCopy(effPCPFlashPolySphere2ExpParam_t *this, void *pData, s32 *pos, s32 max);
effPCPFlashPolySphere2Param_t **effPCPFlashPolySphere2Param_t__pCopy(effPCPFlashPolySphere2Param_t *this, void *pData, s32 *pos, s32 max);
effPCPFlashPolySphere3Param_t **effPCPFlashPolySphere3Param_t__pCopy(effPCPFlashPolySphere3Param_t *this, void *pData, s32 *pos, s32 max);
effPCPFlashPolySphereExpParam_t **effPCPFlashPolySphereExpParam_t__pCopy(effPCPFlashPolySphereExpParam_t *this, void *pData, s32 *pos, s32 max);
effPCPFlashPolySphereParam_t **effPCPFlashPolySphereParam_t__pCopy(effPCPFlashPolySphereParam_t *this, void *pData, s32 *pos, s32 max);
effPCPHamaCardScatterParam_t **effPCPHamaCardScatterParam_t__pCopy(effPCPHamaCardScatterParam_t *this, void *pData, s32 *pos, s32 max);
effPCPHamaCardSphereParam_t **effPCPHamaCardSphereParam_t__pCopy(effPCPHamaCardSphereParam_t *this, void *pData, s32 *pos, s32 max);
effPCPHamaCardSpiralParam_t **effPCPHamaCardSpiralParam_t__pCopy(effPCPHamaCardSpiralParam_t *this, void *pData, s32 *pos, s32 max);
effPCPHelperBEDParam_t **effPCPHelperBEDParam_t__pCopy(effPCPHelperBEDParam_t *this, void *pData, s32 *pos, s32 max);
effPCPMultiBlurExp2Param_t **effPCPMultiBlurExp2Param_t__pCopy(effPCPMultiBlurExp2Param_t *this, void *pData, s32 *pos, s32 max);
effPCPMultiFilterExpParam_t **effPCPMultiFilterExpParam_t__pCopy(effPCPMultiFilterExpParam_t *this, void *pData, s32 *pos, s32 max);
effPCPMuzzleFlashParam_t **effPCPMuzzleFlashParam_t__pCopy(effPCPMuzzleFlashParam_t *this, void *pData, s32 *pos, s32 max);
effPCPNeedleSpiralParam_t **effPCPNeedleSpiralParam_t__pCopy(effPCPNeedleSpiralParam_t *this, void *pData, s32 *pos, s32 max);
effPCPRadiateBEDParam_t **effPCPRadiateBEDParam_t__pCopy(effPCPRadiateBEDParam_t *this, void *pData, s32 *pos, s32 max);
effPCPRadiateTBParam_t **effPCPRadiateTBParam_t__pCopy(effPCPRadiateTBParam_t *this, void *pData, s32 *pos, s32 max);
effPCPRadiateThunderParam_t **effPCPRadiateThunderParam_t__pCopy(effPCPRadiateThunderParam_t *this, void *pData, s32 *pos, s32 max);
effPCPRingPolyExp2Param_t **effPCPRingPolyExp2Param_t__pCopy(effPCPRingPolyExp2Param_t *this, void *pData, s32 *pos, s32 max);
effPCPRingPolyExpParam_t **effPCPRingPolyExpParam_t__pCopy(effPCPRingPolyExpParam_t *this, void *pData, s32 *pos, s32 max);
effPCPRippleBlurExpParam_t **effPCPRippleBlurExpParam_t__pCopy(effPCPRippleBlurExpParam_t *this, void *pData, s32 *pos, s32 max);
effPCPScreenCrackModelParam_t **effPCPScreenCrackModelParam_t__pCopy(effPCPScreenCrackModelParam_t *this, void *pData, s32 *pos, s32 max);
effPCPSpiralBEDParam_t **effPCPSpiralBEDParam_t__pCopy(effPCPSpiralBEDParam_t *this, void *pData, s32 *pos, s32 max);
effPCPThunderSphereExpParam_t **effPCPThunderSphereExpParam_t__pCopy(effPCPThunderSphereExpParam_t *this, void *pData, s32 *pos, s32 max);
effPCPThunderSpherePolyParam_t **effPCPThunderSpherePolyParam_t__pCopy(effPCPThunderSpherePolyParam_t *this, void *pData, s32 *pos, s32 max);
effPCPWhirlwind2PolyParam_t **effPCPWhirlwind2PolyParam_t__pCopy(effPCPWhirlwind2PolyParam_t *this, void *pData, s32 *pos, s32 max);
effPCPWhirlwind3PolyParam_t **effPCPWhirlwind3PolyParam_t__pCopy(effPCPWhirlwind3PolyParam_t *this, void *pData, s32 *pos, s32 max);
effPCPWhirlwindPolyParam_t **effPCPWhirlwindPolyParam_t__pCopy(effPCPWhirlwindPolyParam_t *this, void *pData, s32 *pos, s32 max);
effPCPWwSpherePolyParam_t **effPCPWwSpherePolyParam_t__pCopy(effPCPWwSpherePolyParam_t *this, void *pData, s32 *pos, s32 max);
effPCP_BED_Param_t **effPCP_BED_Param_t__pCopy(effPCP_BED_Param_t *this, void *pData, s32 *pos, s32 max);
effPCP_HBED2_Param_t **effPCP_HBED2_Param_t__pCopy(effPCP_HBED2_Param_t *this, void *pData, s32 *pos, s32 max);
effPCP_PBCamera_Param_t **effPCP_PBCamera_Param_t__pCopy(effPCP_PBCamera_Param_t *this, void *pData, s32 *pos, s32 max);
void mdlFreeSub(void **pData);
void mdlLinkBlur(dds3ModelHandle_t **aHandle);
dds3ModelHandle_t *mdlLoad(s32 aMajor, s32 aMinor, u8 **byteData, s32 bPos);
void mdlSetColor(dds3ModelHandle_t **aHandle, u32 aColor);
void mdlSetPosition(dds3ModelHandle_t **aHandle);
void mdlSetRotate(dds3ModelHandle_t **aHandle);
void mdlSetScale(dds3ModelHandle_t **aHandle);
void mdlShow(dds3ModelHandle_t *mdl);

// 0x12345b0
dds3EffectPCPData_Part_t *GetByte2Parts(void *hPCPData, u32 number, s32 bPos) {
    Byte2UInt32(0, 0);
    return 0;
}

// 0x12323c0
dds3EffectPCP_t *dds3EffectPCPCopy(void **hData, s32 bPos, bool tbldata) {
    _Get_effPCPParamTable(0, 0);
    return 0;
}

// 0x1231a10
dds3EffectPCP_t *dds3EffectPCPCreate(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    _Get_effPCPParamTable(0, 0);
    return 0;
}

// 0x1233380
void *dds3EffectPCPDataGetData(void *hData, u32 number, s32 type) {
  return 0;
}

// 0x1233480
u32 dds3EffectPCPDataGetDataOffSet(void *hPCPData, u32 number, s32 bPos) {
  return GetByte2Parts(hPCPData, number, bPos)->offset + bPos;
}

// 0x1233390
void *dds3EffectPCPDataGetDataUnity(void *hData, u32 number, s32 type, s32 bPos) {
  u32 offset;

  offset = GetByte2Parts(hData, number, bPos, *&bPos)->offset;
  return dds3EffectPCPDataGetDataUnityOffSet(hData, offset + bPos, type);
}

// 0x1233510
void *dds3EffectPCPDataGetDataUnityOffSet(void *hData, s32 offset, s32 type) {
    effPCPFlashPolySphere2Param_t__pCopy(0, 0, 0, 0);
    effPCPFlashPolySphereParam_t__pCopy(0, 0, 0, 0);
    effPCPFlashPolyRingParam_t__pCopy(0, 0, 0, 0);
    effPCPFlashPolyPipeParam_t__pCopy(0, 0, 0, 0);
    effPCPFlashPolyRingExpParam_t__pCopy(0, 0, 0, 0);
    effPCPFlashPolySphereExpParam_t__pCopy(0, 0, 0, 0);
    effPCPFlashPolySphere2ExpParam_t__pCopy(0, 0, 0, 0);
    effPCPFlashPolySphere3Param_t__pCopy(0, 0, 0, 0);
    effPCPFlashPolyRingExp2Param_t__pCopy(0, 0, 0, 0);
    effPCPFlashPolyCircleParam_t__pCopy(0, 0, 0, 0);
    effPCPMultiFilterExpParam_t__pCopy(0, 0, 0, 0);
    effPCPMultiBlurExp2Param_t__pCopy(0, 0, 0, 0);
    effPCPFilterExpParam_t__pCopy(0, 0, 0, 0);
    effPCPBlurExpParam_t__pCopy(0, 0, 0, 0);
    effPCPDistortionBlurExpParam_t__pCopy(0, 0, 0, 0);
    effPCPRippleBlurExpParam_t__pCopy(0, 0, 0, 0);
    effPCPBreathParam_t__pCopy(0, 0, 0, 0);
    effPCPAgiFireballParam_t__pCopy(0, 0, 0, 0);
    effPCPAgiFireball2Param_t__pCopy(0, 0, 0, 0);
    effPCPThunderSphereExpParam_t__pCopy(0, 0, 0, 0);
    effPCPRingPolyExpParam_t__pCopy(0, 0, 0, 0);
    effPCPRingPolyExp2Param_t__pCopy(0, 0, 0, 0);
    effPCPRadiateThunderParam_t__pCopy(0, 0, 0, 0);
    effPCPRadiateBEDParam_t__pCopy(0, 0, 0, 0);
    effPCPRadiateTBParam_t__pCopy(0, 0, 0, 0);
    effPCPSpiralBEDParam_t__pCopy(0, 0, 0, 0);
    effPCPHelperBEDParam_t__pCopy(0, 0, 0, 0);
    effPCPFLEACHBlurParam_t__pCopy(0, 0, 0, 0);
    effPCPAgiraoFireParam_t__pCopy(0, 0, 0, 0);
    effPCPHamaCardSpiralParam_t__pCopy(0, 0, 0, 0);
    effPCPHamaCardSphereParam_t__pCopy(0, 0, 0, 0);
    effPCPHamaCardScatterParam_t__pCopy(0, 0, 0, 0);
    effPCPWhirlwindPolyParam_t__pCopy(0, 0, 0, 0);
    effPCPWhirlwind2PolyParam_t__pCopy(0, 0, 0, 0);
    effPCPWhirlwind3PolyParam_t__pCopy(0, 0, 0, 0);
    effPCPWwSpherePolyParam_t__pCopy(0, 0, 0, 0);
    effPCPThunderSpherePolyParam_t__pCopy(0, 0, 0, 0);
    effPCPCrackParam_t__pCopy(0, 0, 0, 0);
    effPCPBossBaelParam_t__pCopy(0, 0, 0, 0);
    effPCPBossDengekiParam_t__pCopy(0, 0, 0, 0);
    effPCPBossThunderboltParam_t__pCopy(0, 0, 0, 0);
    effPCPBossKAGUInvokeParam_t__pCopy(0, 0, 0, 0);
    effPCPBossKAGUAttackParam_t__pCopy(0, 0, 0, 0);
    effPCPBossKAGUThunderboltParam_t__pCopy(0, 0, 0, 0);
    effPCPBossKAGU2AttackParam_t__pCopy(0, 0, 0, 0);
    effPCPCrack2Param_t__pCopy(0, 0, 0, 0);
    effPCPBossMETATOBeamParam_t__pCopy(0, 0, 0, 0);
    effPCPScreenCrackModelParam_t__pCopy(0, 0, 0, 0);
    effPCPMuzzleFlashParam_t__pCopy(0, 0, 0, 0);
    effPCPDANTE_Thunder_Param_t__pCopy(0, 0, 0, 0);
    effPCPDANTE_Damage_Param_t__pCopy(0, 0, 0, 0);
    effPCP_PBCamera_Param_t__pCopy(0, 0, 0, 0);
    effPCPDANTE_ShowTime_Param_t__pCopy(0, 0, 0, 0);
    effPCP_BED_Param_t__pCopy(0, 0, 0, 0);
    effPCP_HBED2_Param_t__pCopy(0, 0, 0, 0);
    effPCPBezierBillParam_t__pCopy(0, 0, 0, 0);
    effPCPNeedleSpiralParam_t__pCopy(0, 0, 0, 0);
    return 0;
}

// 0x1231e00
u32 dds3EffectPCPDataGetKateg(dds3EffectPCPData_t **hPCPData) {
  return (*hPCPData)->kateg;
}

// 0x1231e10
u32 dds3EffectPCPDataGetParam(dds3EffectPCPData_t **hPCPData) {
  return (*hPCPData)->param;
}

// 0x12347f0
u32 dds3EffectPCPDataGetSize(dds3EffectPCPData_t **hPCPData, u32 number) {
  struct dds3EffectPCPData_Part_t_array *pcpData;

  pcpData = (*hPCPData)->pcpData;
  return pcpData->m_Items[number]->size;
}

// 0x1234840
u32 dds3EffectPCPDataGetSizeByte(void *hPCPData, u32 number, s32 bPos) {
  return GetByte2Parts(hPCPData, number, bPos)->size;
}

// 0x12348d0
u32 dds3EffectPCPDataGetType(dds3EffectPCPData_t **hPCPData, u32 number) {
  struct dds3EffectPCPData_Part_t_array *pcpData;

  pcpData = (*hPCPData)->pcpData;
  return pcpData->m_Items[number]->type;
}

// 0x1234920
u32 dds3EffectPCPDataGetTypeByte(void *hPCPData, u32 number, s32 bPos) {
  return GetByte2Parts(hPCPData, number, bPos)->type;
}

// 0x12349b0
effPartHandle_t *dds3EffectPCPDataPartCreate(dds3EffectPCPData_t *hPCPData, u8 **bytedata, s32 bPos, u32 number) {
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    SobedPbSet(0, 0);
    dds3EffectPartCreate(0, 0);
    return 0;
}

// 0x1231e20
void dds3EffectPCPDelete(void **hData) {
}

// 0x1232000
void dds3EffectPCPDraw(void **hData) {
}

// 0x12321e0
void dds3EffectPCPDrawOff(void **hData) {
}

// 0x1233190
void dds3EffectPCPSetArea(void **hData, f32 area) {
}

// 0x1232fa0
void dds3EffectPCPSetColor(void **hData, u32 abgr) {
}

// 0x1232d90
void dds3EffectPCPSetDirection(void **hData, sdfMatrix4_t *pMatrix) {
}

// 0x1232780
void dds3EffectPCPSetPosition(void **hData, sdfVector4_t pPos) {
}

// 0x1232b80
void dds3EffectPCPSetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
}

// 0x1232990
void dds3EffectPCPSetScale(void **hData, f32 scale) {
}

// 0x1230550
void dds3EffectPartBillboardScale(billHandle_t **hBillboard, f32 scale) {
  dds3BillboardSetScale(hBillboard, scale, scale);
}

// 0x12305d0
void dds3EffectPartBillboardScaleO(void **hData, f32 scale) {
    dds3BillboardSetScale(0, 0, 0);
}

// 0x122d290
effPartHandle_t *dds3EffectPartCopy(effPartHandle_t **hEffPartSrc, s32 bPos) {
    return 0;
}

// 0x122d830
effPartHandle_t *dds3EffectPartCopyO(void **hData, s32 bPos) {
    dds3EffectPartCopy(0);
    return 0;
}

// 0x122bd60
effPartHandle_t *dds3EffectPartCreate(u16 type, void *pData, s32 bPos) {
    SobedPbSet(0, 0);
    return 0;
}

// 0x122c3b0
void dds3EffectPartDelete(effPartHandle_t **hEffPart) {
}

// 0x122c8c0
void dds3EffectPartDeleteO(void **hData) {
    dds3EffectPartDelete(0);
}

// 0x122c9e0
void dds3EffectPartDraw(effPartHandle_t **hEffPart) {
}

// 0x122cef0
void dds3EffectPartDrawO(void **hData) {
    dds3EffectPartDraw(0);
}

// 0x122d010
void dds3EffectPartDrawOff(effPartHandle_t **hEffPart) {
}

// 0x122d170
void dds3EffectPartDrawOffO(void **hData) {
    dds3EffectPartDrawOff(0);
}

// 0x122bd40
void *dds3EffectPartGetHandle(effPartHandle_t **hEffPart) {
  return (*hEffPart)->pHandle;
}

// 0x122bd50
u16 dds3EffectPartGetType(effPartHandle_t **hEffPart) {
  return (*hEffPart)->type;
}

// 0x1231270
dds3ModelHandle_t *dds3EffectPartModelCopy(void **hData, s32 bPos, bool tbldata) {
    dds3ModelHandle_t__dCopy(0, 0);
    dds3EffectPartModelInit(0);
    return 0;
}

// 0x12308a0
dds3ModelHandle_t *dds3EffectPartModelCreate(void **hData, s32 bPos, bool tbldata) {
    mdlLoad(0, 0, 0, 0);
    GetPbList();
    dds3EffectPartModelInit(0);
    return 0;
}

// 0x12310e0
void dds3EffectPartModelDelete(void **hData) {
    mdlFreeSub(0);
}

// 0x1230b90
void dds3EffectPartModelDraw(void **hData) {
    SethModel(0, 0);
    SetAutoHide(0, 0);
    SetFrameAnime(0, 0);
    StepFrame(0);
    mdlLinkBlur(0);
}

// 0x1230a40
void dds3EffectPartModelDrawOff(void **hData) {
}

// 0x1230700
void dds3EffectPartModelInit(dds3ModelHandle_t **hModel) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    mdlSetPosition(0);
    mdlSetRotate(0);
    mdlSetScale(0);
    mdlSetColor(0, 0);
    mdlShow(0);
}

// 0x1231840
void dds3EffectPartModelSetColor(void **hData, u32 abgr) {
    mdlSetColor(0, 0);
}

// 0x12313c0
void dds3EffectPartModelSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    mdlSetPosition(0);
}

// 0x12316a0
void dds3EffectPartModelSetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
    SDF_VU0__LOADMATRIX(0);
}

// 0x1231520
void dds3EffectPartModelSetScale(void **hData, f32 scale) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    mdlSetScale(0);
}

// 0x12304c0
billHandle_t *dds3EffectPartP2ABillboardCreate(void **pData, s32 bPos, bool tbldata) {
  Il2CppObject *v6;

  v6 = *pData;
  return dds3BillboardCreate(1, v6, bPos, StringLiteral_15556);
}

// 0x122fef0
void dds3EffectPartSetArea(effPartHandle_t **hEffPart, f32 area) {
  struct effPart_dds3EffectPartFuncTable_tag_array *EffectPartFuncTable;
  s64 type;
  struct effPart_dds3EffectPartFuncTable_tag_array *v11;
  s64 v12;

  type = (*hEffPart)->type;
  if (EffectPartFuncTable->m_Items[type]->mSetArea)
  {
    v11 = EffectPartFuncTable;
    v12 = (*hEffPart)->type;
    Invoke(
      v11->m_Items[v12]->mSetArea,
      &(*hEffPart)->pHandle,
      area);
  }
}

// 0x122f090
void dds3EffectPartSetColor(effPartHandle_t **hEffPart, u32 abgr) {
  struct effPart_dds3EffectPartFuncTable_tag_array *EffectPartFuncTable;
  s64 type;
  struct effPart_dds3EffectPartFuncTable_tag_array *v11;
  s64 v12;

  type = (*hEffPart)->type;
  if (EffectPartFuncTable->m_Items[type]->mSetColor)
  {
    v11 = EffectPartFuncTable;
    v12 = (*hEffPart)->type;
    Invoke(
      v11->m_Items[v12]->mSetColor,
      &(*hEffPart)->pHandle,
      abgr);
  }
}

// 0x122f5b0
void dds3EffectPartSetColorO(void **hData, u32 abgr) {
    dds3EffectPartSetColor(0, 0);
}

// 0x122f6e0
void dds3EffectPartSetDirection(effPartHandle_t **hEffPart, sdfMatrix4_t *pMatrix) {
  struct effPart_dds3EffectPartFuncTable_tag_array *EffectPartFuncTable;
  s64 type;
  struct effPart_dds3EffectPartFuncTable_tag_array *v11;
  effPartHandle_t_o *v12;
  s64 v13;
  s64 v15;
  s64 v16;
  s64 v17;
  effPart_dds3EffectPartFuncTable_tag_SetDirectionDelegate_o *mSetDirection;
  s64 v19;
  s64 v20;
  s64 v21;
  UnityEngine_Matrix4x4_o v22;

  type = (*hEffPart)->type;
  if (EffectPartFuncTable->m_Items[type]->mSetDirection)
  {
    v11 = EffectPartFuncTable;
    v12 = *hEffPart;
    v13 = (*hEffPart)->type;
    v15 = *&pMatrix->m00;
    v16 = *&pMatrix->m20;
    v17 = *&pMatrix->m21;
    mSetDirection = v11->m_Items[v13]->mSetDirection;
    *&v22.m01 = *&pMatrix->m01;
    *&v22.m21 = v17;
    *&v22.m00 = v15;
    *&v22.m20 = v16;
    v19 = *&pMatrix->m02;
    v20 = *&pMatrix->m22;
    v21 = *&pMatrix->m23;
    *&v22.m03 = *&pMatrix->m03;
    *&v22.m23 = v21;
    *&v22.m02 = v19;
    *&v22.m22 = v20;
    Invoke(mSetDirection, &v12->pHandle, &v22);
  }
}

// 0x122d960
void dds3EffectPartSetPosition(effPartHandle_t **hEffPart, sdfVector4_t pPos) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  struct effPart_dds3EffectPartFuncTable_tag_array *EffectPartFuncTable;
  s64 type;
  struct effPart_dds3EffectPartFuncTable_tag_array *v14;
  s64 v15;
  UnityEngine_Vector4_o v17;

  w = pPos.w;
  z = pPos.z;
  y = pPos.y;
  x = pPos.x;
  type = (*hEffPart)->type;
  if (EffectPartFuncTable->m_Items[type]->mSetPosition)
  {
    v14 = EffectPartFuncTable;
    v15 = (*hEffPart)->type;
    v17.z = z;
    v17.w = w;
    v17.x = x;
    v17.y = y;
    Invoke(
      v14->m_Items[v15]->mSetPosition,
      &(*hEffPart)->pHandle,
      v17);
  }
}

// 0x122df50
void dds3EffectPartSetPositionO(void **hData, sdfVector4_t pPos) {
    dds3EffectPartSetPosition(0, (sdfVector4_t){0});
}

// 0x122e710
void dds3EffectPartSetRotateMatrix(effPartHandle_t **hEffPart, sdfMatrix4_t *pMatrix) {
  struct effPart_dds3EffectPartFuncTable_tag_array *EffectPartFuncTable;
  s64 type;
  struct effPart_dds3EffectPartFuncTable_tag_array *v11;
  effPartHandle_t_o *v12;
  s64 v13;
  s64 v15;
  s64 v16;
  s64 v17;
  effPart_dds3EffectPartFuncTable_tag_SetRotateMatrixDelegate_o *mSetRotateMatrix;
  s64 v19;
  s64 v20;
  s64 v21;
  UnityEngine_Matrix4x4_o v22;

  type = (*hEffPart)->type;
  if (EffectPartFuncTable->m_Items[type]->mSetRotateMatrix)
  {
    v11 = EffectPartFuncTable;
    v12 = *hEffPart;
    v13 = (*hEffPart)->type;
    v15 = *&pMatrix->m00;
    v16 = *&pMatrix->m20;
    v17 = *&pMatrix->m21;
    mSetRotateMatrix = v11->m_Items[v13]->mSetRotateMatrix;
    *&v22.m01 = *&pMatrix->m01;
    *&v22.m21 = v17;
    *&v22.m00 = v15;
    *&v22.m20 = v16;
    v19 = *&pMatrix->m02;
    v20 = *&pMatrix->m22;
    v21 = *&pMatrix->m23;
    *&v22.m03 = *&pMatrix->m03;
    *&v22.m23 = v21;
    *&v22.m02 = v19;
    *&v22.m22 = v20;
    Invoke(
      mSetRotateMatrix,
      &v12->pHandle,
      &v22);
  }
}

// 0x122ef20
void dds3EffectPartSetRotateMatrixO(void **hData, sdfMatrix4_t *pMatrix) {
    dds3EffectPartSetRotateMatrix(0, 0);
}

// 0x122e0a0
void dds3EffectPartSetScale(effPartHandle_t **hEffPart, f32 scale) {
  struct effPart_dds3EffectPartFuncTable_tag_array *EffectPartFuncTable;
  s64 type;
  struct effPart_dds3EffectPartFuncTable_tag_array *v11;
  s64 v12;

  type = (*hEffPart)->type;
  if (EffectPartFuncTable->m_Items[type]->mSetScale)
  {
    v11 = EffectPartFuncTable;
    v12 = (*hEffPart)->type;
    Invoke(
      v11->m_Items[v12]->mSetScale,
      &(*hEffPart)->pHandle,
      scale);
  }
}

// 0x122e5e0
void dds3EffectPartSetScaleO(void **hData, f32 scale) {
    dds3EffectPartSetScale(0, 0);
}

// 0x1230430
billHandle_t *dds3EffectPartTMXBillboardCreate(void **pData, s32 bPos, bool tbldata) {
  Il2CppObject *v6;

  v6 = *pData;
  return dds3BillboardCreate(0, v6, bPos, StringLiteral_15555);
}

// 0x122bcd0
s32 mdlGetMajorNum(dds3ModelHandle_t **aHandle) {
  return 0;
}

// 0x122bce0
s32 mdlGetMinorNum(dds3ModelHandle_t **aHandle) {
  return 0;
}

// 0x122bcf0
bool mdlHasMotion(dds3ModelHandle_t *HNDL) {
  return 0;
}

// 0x122bd10
void mdlLoopMotion(dds3ModelHandle_t *aHandle, s32 aGroup, s32 aNumber) {
  ;
}

// 0x122bd00
void mdlPackDecode(void) {
  ;
}

// 0x122bd20
void mdlPackDecode_19053856(s32 major, s32 minor, u32 regFlags, void *buff, s32 leng) {
  ;
}

// 0x122bd30
void mdlSetMotionSpeed(dds3ModelHandle_t *aHandle, f32 speed) {
  aHandle->motionCtrlr->speed = speed;
}
