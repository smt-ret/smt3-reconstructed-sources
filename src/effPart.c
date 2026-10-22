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
  Il2CppClass *v7;
  s64 *Interface;
  char *v9;
  s64 *v10;
  dds3EffectPCPData_t_o *v11;
  dds3EffectPCPData_Part_t_o *v13;
  u32 part;
  u32 v16;
  s32 v17;
  u64 v19[3];

  if (hPCPData)
  {
    Interface = QueryInterface(hPCPData, byte);
    if (!Interface)
    {
      sub_8FC2C0(hPCPData->klass->_1.element_class, v7, v19);
      if ((v19[0] & 1) != 0)
        v9 = v19[2];
      else
        v9 = v19 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  else
  {
    Interface = 0;
  }
  v11 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v11);
  v11->kateg = Byte2UInt32(Interface, bPos);
  v11->param = Byte2UInt32(Interface, bPos + 4);
  v11->part = Byte2UInt32(Interface, bPos + 8);
  v11->reserve = Byte2UInt32(Interface, bPos + 12);
  v13 = Allocate(dds3EffectPCPData_Part_t);
  dds3EffectPCPData_Part_t___ctor(v13);
  part = v11->part;
  if (part)
  {
    v16 = 0;
    v17 = bPos + 28;
    while (number != v16)
    {
      ++v16;
      v17 += 16;
      if (v16 >= part)
        return v13;
    }
    v13->size = Byte2UInt32(Interface, v17 - 12);
    v13->offset = Byte2UInt32(Interface, v17 - 8);
    v13->type = Byte2UInt32(Interface, v17 - 4);
    v13->reserve = Byte2UInt32(Interface, v17);
  }
  return v13;
}

// 0x12323c0
dds3EffectPCP_t *dds3EffectPCPCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v6;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  dds3EffectPCP_t_o *v11;
  u32 kateg;
  struct effPart_dds3EffectPartFuncTable_tag_array *EffectPCPFuncTable;
  il2cpp_array_size_t max_length;
  s64 v18;
  struct effPart_dds3EffectPartFuncTable_tag_array *v20;
  s64 v21;
  il2cpp_array_size_t v22;
  struct effPart_dds3EffectPartFuncTable_tag_array *v25;
  s64 v26;
  Il2CppObject *v28;
  struct effPart_dds3EffectPartFuncTable_tag_array *v29;
  s64 v30;
  il2cpp_array_size_t v31;
  u32 param;
  u32 v34;
  struct effPart_dds3EffectPartFuncTable_tag_array *v38;
  s64 v39;
  Il2CppObject *effPCPParamTable;
  u64 v43[3];

  effPCPParamTable = 0;
  v6 = *hData;
  if (*hData)
  {
    klass = v6->klass;
    if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectPCP_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3EffectPCP_t, v43);
      if ((v43[0] & 1) != 0)
        v9 = v43[2];
      else
        v9 = v43 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  v11 = Allocate(dds3EffectPCP_t);
  dds3EffectPCP_t___ctor(v11);
  kateg = v6[1].klass;
  v11->kateg = kateg;
  v11->param = HIDWORD(v6[1].klass);
  max_length = EffectPCPFuncTable->max_length;
  v18 = kateg;
  if (kateg < max_length)
  {
    if (EffectPCPFuncTable->m_Items[v18]->mCopy)
    {
      v20 = EffectPCPFuncTable;
      v21 = v11->kateg;
      v22 = v20->max_length;
      if (v21 < v22)
      {
        if (v20->m_Items[v21]->mCreate)
        {
          v25 = EffectPCPFuncTable;
          v26 = v11->kateg;
          v28 = Invoke(
                  v25->m_Items[v26]->mCopy,
                  &v6[1].monitor,
                  bPos,
                  0);
LABEL_55:
          v11->pHandle = v28;
        }
      }
    }
    else
    {
      v29 = EffectPCPFuncTable;
      v30 = v11->kateg;
      v31 = v29->max_length;
      if (v30 < v31)
      {
        if (v29->m_Items[v30]->mCreate)
        {
          v34 = v11->kateg;
          param = v11->param;
          effPCPParamTable = _Get_effPCPParamTable(v34, param);
          v38 = EffectPCPFuncTable;
          v39 = v11->kateg;
          v28 = Invoke(
                  v38->m_Items[v39]->mCreate,
                  &effPCPParamTable,
                  bPos,
                  1);
          goto LABEL_55;
        }
      }
    }
  }
  return v11;
}

// 0x1231a10
dds3EffectPCP_t *dds3EffectPCPCreate(void **hData, s32 bPos, bool tbldata) {
  dds3EffectPCP_t_o *v6;
  Il2CppObject *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  dds3EffectPCPData_t_o *v12;
  s64 kateg;
  struct effPart_dds3EffectPartFuncTable_tag_array *EffectPCPFuncTable;
  il2cpp_array_size_t max_length;
  struct effPart_dds3EffectPartFuncTable_tag_array *v21;
  s64 v22;
  il2cpp_array_size_t v23;
  struct effPart_dds3EffectPartFuncTable_tag_array *v26;
  s64 v27;
  effPart_dds3EffectPartFuncTable_tag_CreateDelegate_o *mCreate;
  Il2CppObject **p_pData;
  s32 v31;
  bool v32;
  u32 param;
  u32 v34;
  struct effPart_dds3EffectPartFuncTable_tag_array *v37;
  s64 v38;
  il2cpp_array_size_t v39;
  struct effPart_dds3EffectPartFuncTable_tag_array *v42;
  s64 v43;
  Il2CppObject *pData;
  s32 pos;
  u64 v48[3];

  pos = bPos;
  pData = 0;
  v6 = Allocate(dds3EffectPCP_t);
  dds3EffectPCP_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v7->klass->_1.element_class, v8, v48);
      if ((v48[0] & 1) != 0)
        v10 = v48[2];
      else
        v10 = v48 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  v12 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v12);
  dds3EffectPCPData_t__pCopy(v12, Interface, &pos);
  kateg = v12->kateg;
  v6->kateg = kateg;
  v6->param = v12->param;
  max_length = EffectPCPFuncTable->max_length;
  if (kateg < max_length)
  {
    if (EffectPCPFuncTable->m_Items[kateg]->mCopy)
    {
      v21 = EffectPCPFuncTable;
      v22 = v6->kateg;
      v23 = v21->max_length;
      if (v22 < v23)
      {
        if (v21->m_Items[v22]->mCreate)
        {
          v26 = EffectPCPFuncTable;
          v27 = v6->kateg;
          mCreate = v26->m_Items[v27]->mCreate;
          p_pData = hData;
          v31 = bPos;
          v32 = 0;
LABEL_55:
          v6->pHandle = Invoke(
                                 mCreate,
                                 p_pData,
                                 v31,
                                 v32);
        }
      }
    }
    else
    {
      v34 = v6->kateg;
      param = v6->param;
      pData = _Get_effPCPParamTable(v34, param);
      v37 = EffectPCPFuncTable;
      v38 = v6->kateg;
      v39 = v37->max_length;
      if (v38 < v39)
      {
        if (v37->m_Items[v38]->mCreate)
        {
          v42 = EffectPCPFuncTable;
          v43 = v6->kateg;
          mCreate = v42->m_Items[v43]->mCreate;
          v31 = pos;
          p_pData = &pData;
          v32 = 1;
          goto LABEL_55;
        }
      }
    }
  }
  return v6;
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

LABEL_7:
  offset = GetByte2Parts(hData, number, bPos, *&bPos)->offset;
  return dds3EffectPCPDataGetDataUnityOffSet(hData, offset + bPos, type);
}

// 0x1233510
void *dds3EffectPCPDataGetDataUnityOffSet(void *hData, s32 offset, s32 type) {
  u64 *v7;
  void *v8;
  u64 *v10;
  u64 *v12;
  u64 *v13;
  u64 *v14;
  u64 *v15;
  u64 *v16;
  u64 *v17;
  u64 *v18;
  u64 *v19;
  u64 *v20;
  u64 *v21;
  u64 *v22;
  u64 *v23;
  u64 *v24;
  u64 *v25;
  u64 *v26;
  u64 *v27;
  u64 *v28;
  u64 *v29;
  u64 *v30;
  u64 *v31;
  u64 *v32;
  u64 *v33;
  u64 *v34;
  u64 *v35;
  u64 *v36;
  u64 *v37;
  u64 *v38;
  u64 *v39;
  u64 *v40;
  u64 *v41;
  u64 *v42;
  u64 *v43;
  u64 *v44;
  u64 *v45;
  u64 *v46;
  u64 *v47;
  u64 *v48;
  u64 *v49;
  u64 *v50;
  u64 *v51;
  u64 *v52;
  u64 *v53;
  u64 *v54;
  Il2CppClass *v55;
  s64 *Interface;
  char *v57;
  s64 *v58;
  u64 *v59;
  u64 *v60;
  u64 *v61;
  u64 *v62;
  u64 *v63;
  u64 *v64;
  u64 *v65;
  u64 *v66;
  u64 *v67;
  u64 *v68;
  u64 *v69;
  u64 *v70;
  u64 *v71;
  s32 pos;
  u64 v73[3];

  pos = offset;
  switch (type)
  {
    case 0:
      v7 = Allocate(effPCPFlashPolySphere2Param_t);
      effPCPFlashPolySphere2Param_t___ctor(v7);
      v8 = effPCPFlashPolySphere2Param_t__pCopy(v7, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 1:
      v12 = Allocate(effPCPFlashPolySphereParam_t);
      effPCPFlashPolySphereParam_t___ctor(v12);
      v8 = effPCPFlashPolySphereParam_t__pCopy(v12, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 2:
      v13 = Allocate(effPCPFlashPolyRingParam_t);
      effPCPFlashPolyRingParam_t___ctor(v13);
      v8 = effPCPFlashPolyRingParam_t__pCopy(v13, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 3:
      v14 = Allocate(effPCPFlashPolyPipeParam_t);
      effPCPFlashPolyPipeParam_t___ctor(v14);
      v8 = effPCPFlashPolyPipeParam_t__pCopy(v14, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 4:
      v15 = Allocate(effPCPFlashPolyRingExpParam_t);
      effPCPFlashPolyRingExpParam_t___ctor(v15);
      v8 = effPCPFlashPolyRingExpParam_t__pCopy(v15, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 5:
      v16 = Allocate(effPCPFlashPolySphereExpParam_t);
      effPCPFlashPolySphereExpParam_t___ctor(v16);
      v8 = effPCPFlashPolySphereExpParam_t__pCopy(v16, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 6:
      v17 = Allocate(effPCPFlashPolySphere2ExpParam_t);
      effPCPFlashPolySphere2ExpParam_t___ctor(v17);
      v8 = effPCPFlashPolySphere2ExpParam_t__pCopy(v17, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 7:
      v18 = Allocate(effPCPFlashPolySphere3Param_t);
      effPCPFlashPolySphere3Param_t___ctor(v18);
      v8 = effPCPFlashPolySphere3Param_t__pCopy(v18, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 8:
      v19 = Allocate(effPCPFlashPolyRingExp2Param_t);
      effPCPFlashPolyRingExp2Param_t___ctor(v19);
      v8 = effPCPFlashPolyRingExp2Param_t__pCopy(v19, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 9:
      v20 = Allocate(effPCPFlashPolyCircleParam_t);
      effPCPFlashPolyCircleParam_t___ctor(v20);
      v8 = effPCPFlashPolyCircleParam_t__pCopy(v20, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 10:
      v21 = Allocate(effPCPMultiFilterExpParam_t);
      effPCPMultiFilterExpParam_t___ctor(v21);
      v8 = effPCPMultiFilterExpParam_t__pCopy(v21, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 11:
      v22 = Allocate(effPCPMultiBlurExp2Param_t);
      effPCPMultiBlurExp2Param_t___ctor(v22);
      v8 = effPCPMultiBlurExp2Param_t__pCopy(v22, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 12:
      v23 = Allocate(effPCPFilterExpParam_t);
      effPCPFilterExpParam_t___ctor(v23);
      v8 = effPCPFilterExpParam_t__pCopy(v23, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 13:
      v24 = Allocate(effPCPBlurExpParam_t);
      effPCPBlurExpParam_t___ctor(v24);
      v8 = effPCPBlurExpParam_t__pCopy(v24, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 14:
      v25 = Allocate(effPCPDistortionBlurExpParam_t);
      effPCPDistortionBlurExpParam_t___ctor(v25);
      v8 = effPCPDistortionBlurExpParam_t__pCopy(v25, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 15:
      v26 = Allocate(effPCPRippleBlurExpParam_t);
      effPCPRippleBlurExpParam_t___ctor(v26);
      v8 = effPCPRippleBlurExpParam_t__pCopy(v26, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 16:
      v27 = Allocate(effPCPBreathParam_t);
      effPCPBreathParam_t___ctor(v27);
      v8 = effPCPBreathParam_t__pCopy(v27, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 17:
      v28 = Allocate(effPCPAgiFireballParam_t);
      effPCPAgiFireballParam_t___ctor(v28);
      v8 = effPCPAgiFireballParam_t__pCopy(v28, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 18:
      v29 = Allocate(effPCPAgiFireball2Param_t);
      effPCPAgiFireball2Param_t___ctor(v29);
      v8 = effPCPAgiFireball2Param_t__pCopy(v29, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 19:
      v59 = Allocate(effPCPThunderSphereExpParam_t);
      effPCPThunderSphereExpParam_t___ctor(v59);
      v8 = effPCPThunderSphereExpParam_t__pCopy(v59, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 20:
      v30 = Allocate(effPCPRingPolyExpParam_t);
      effPCPRingPolyExpParam_t___ctor(v30);
      v8 = effPCPRingPolyExpParam_t__pCopy(v30, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 21:
      v31 = Allocate(effPCPRingPolyExp2Param_t);
      effPCPRingPolyExp2Param_t___ctor(v31);
      v8 = effPCPRingPolyExp2Param_t__pCopy(v31, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 22:
      v32 = Allocate(effPCPRadiateThunderParam_t);
      effPCPRadiateThunderParam_t___ctor(v32);
      v8 = effPCPRadiateThunderParam_t__pCopy(v32, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 23:
      v60 = Allocate(effPCPRadiateBEDParam_t);
      effPCPRadiateBEDParam_t___ctor(v60);
      v8 = effPCPRadiateBEDParam_t__pCopy(v60, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 24:
      v33 = Allocate(effPCPRadiateTBParam_t);
      effPCPRadiateTBParam_t___ctor(v33);
      v8 = effPCPRadiateTBParam_t__pCopy(v33, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 25:
      v34 = Allocate(effPCPSpiralBEDParam_t);
      effPCPSpiralBEDParam_t___ctor(v34);
      v8 = effPCPSpiralBEDParam_t__pCopy(v34, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 26:
      v61 = Allocate(effPCPHelperBEDParam_t);
      effPCPHelperBEDParam_t___ctor(v61);
      v8 = effPCPHelperBEDParam_t__pCopy(v61, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 27:
      v35 = Allocate(effPCPFLEACHBlurParam_t);
      effPCPFLEACHBlurParam_t___ctor(v35);
      v8 = effPCPFLEACHBlurParam_t__pCopy(v35, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 28:
      v62 = Allocate(effPCPAgiraoFireParam_t);
      effPCPAgiraoFireParam_t___ctor(v62);
      v8 = effPCPAgiraoFireParam_t__pCopy(v62, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 29:
      v63 = Allocate(effPCPHamaCardSpiralParam_t);
      effPCPHamaCardSpiralParam_t___ctor(v63);
      v8 = effPCPHamaCardSpiralParam_t__pCopy(v63, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 30:
      v36 = Allocate(effPCPHamaCardSphereParam_t);
      effPCPHamaCardSphereParam_t___ctor(v36);
      v8 = effPCPHamaCardSphereParam_t__pCopy(v36, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 31:
      v37 = Allocate(effPCPHamaCardScatterParam_t);
      effPCPHamaCardScatterParam_t___ctor(v37);
      v8 = effPCPHamaCardScatterParam_t__pCopy(v37, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 32:
      v38 = Allocate(effPCPWhirlwindPolyParam_t);
      effPCPWhirlwindPolyParam_t___ctor(v38);
      v8 = effPCPWhirlwindPolyParam_t__pCopy(v38, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 33:
      v39 = Allocate(effPCPWhirlwind2PolyParam_t);
      effPCPWhirlwind2PolyParam_t___ctor(v39);
      v8 = effPCPWhirlwind2PolyParam_t__pCopy(v39, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 34:
      v40 = Allocate(effPCPWhirlwind3PolyParam_t);
      effPCPWhirlwind3PolyParam_t___ctor(v40);
      v8 = effPCPWhirlwind3PolyParam_t__pCopy(v40, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 35:
      v41 = Allocate(effPCPWwSpherePolyParam_t);
      effPCPWwSpherePolyParam_t___ctor(v41);
      v8 = effPCPWwSpherePolyParam_t__pCopy(v41, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 36:
      v42 = Allocate(effPCPThunderSpherePolyParam_t);
      effPCPThunderSpherePolyParam_t___ctor(v42);
      v8 = effPCPThunderSpherePolyParam_t__pCopy(v42, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 37:
      v43 = Allocate(effPCPCrackParam_t);
      effPCPCrackParam_t___ctor(v43);
      v8 = effPCPCrackParam_t__pCopy(v43, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 38:
      v64 = Allocate(effPCPBossBaelParam_t);
      effPCPBossBaelParam_t___ctor(v64);
      v8 = effPCPBossBaelParam_t__pCopy(v64, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 39:
      v44 = Allocate(effPCPBossDengekiParam_t);
      effPCPBossDengekiParam_t___ctor(v44);
      v8 = effPCPBossDengekiParam_t__pCopy(v44, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 40:
      v45 = Allocate(effPCPBossThunderboltParam_t);
      effPCPBossThunderboltParam_t___ctor(v45);
      v8 = effPCPBossThunderboltParam_t__pCopy(v45, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 41:
      v46 = Allocate(effPCPBossKAGUInvokeParam_t);
      effPCPBossKAGUInvokeParam_t___ctor(v46);
      v8 = effPCPBossKAGUInvokeParam_t__pCopy(v46, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 42:
      v65 = Allocate(effPCPBossKAGUAttackParam_t);
      effPCPBossKAGUAttackParam_t___ctor(v65);
      v8 = effPCPBossKAGUAttackParam_t__pCopy(v65, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 43:
      v47 = Allocate(effPCPBossKAGUThunderboltParam_t);
      effPCPBossKAGUThunderboltParam_t___ctor(v47);
      v8 = effPCPBossKAGUThunderboltParam_t__pCopy(v47, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 44:
      v48 = Allocate(effPCPBossKAGU2AttackParam_t);
      effPCPBossKAGU2AttackParam_t___ctor(v48);
      v8 = effPCPBossKAGU2AttackParam_t__pCopy(v48, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 45:
      v10 = Allocate(effPCPBossKAGU2MUHENKParam_t);
      effPCPBossKAGU2MUHENKParam_t___ctor(v10);
      return v10;
    case 46:
      v66 = Allocate(effPCPCrack2Param_t);
      effPCPCrack2Param_t___ctor(v66);
      v8 = effPCPCrack2Param_t__pCopy(v66, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 47:
      v49 = Allocate(effPCPBossMETATOBeamParam_t);
      effPCPBossMETATOBeamParam_t___ctor(v49);
      v8 = effPCPBossMETATOBeamParam_t__pCopy(v49, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 48:
      v50 = Allocate(effPCPScreenCrackModelParam_t);
      effPCPScreenCrackModelParam_t___ctor(v50);
      v8 = effPCPScreenCrackModelParam_t__pCopy(v50, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 49:
      v51 = Allocate(effPCPMuzzleFlashParam_t);
      effPCPMuzzleFlashParam_t___ctor(v51);
      v8 = effPCPMuzzleFlashParam_t__pCopy(v51, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 50:
      v52 = Allocate(effPCPDANTE_Thunder_Param_t);
      effPCPDANTE_Thunder_Param_t___ctor(v52);
      v8 = effPCPDANTE_Thunder_Param_t__pCopy(v52, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 51:
      v67 = Allocate(effPCPDANTE_Damage_Param_t);
      effPCPDANTE_Damage_Param_t___ctor(v67);
      v8 = effPCPDANTE_Damage_Param_t__pCopy(v67, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 52:
      v68 = Allocate(effPCP_PBCamera_Param_t);
      effPCP_PBCamera_Param_t___ctor(v68);
      v8 = effPCP_PBCamera_Param_t__pCopy(v68, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 53:
      v53 = Allocate(effPCPDANTE_ShowTime_Param_t);
      effPCPDANTE_ShowTime_Param_t___ctor(v53);
      v8 = effPCPDANTE_ShowTime_Param_t__pCopy(v53, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 54:
      v69 = Allocate(effPCP_BED_Param_t);
      effPCP_BED_Param_t___ctor(v69);
      v8 = effPCP_BED_Param_t__pCopy(v69, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 55:
      v70 = Allocate(effPCP_HBED2_Param_t);
      effPCP_HBED2_Param_t___ctor(v70);
      v8 = effPCP_HBED2_Param_t__pCopy(v70, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 56:
      v54 = Allocate(effPCPBezierBillParam_t);
      effPCPBezierBillParam_t___ctor(v54);
      v8 = effPCPBezierBillParam_t__pCopy(v54, hData, &pos, 1);
      if (!*(v8 + 6))
        goto LABEL_5;
      goto LABEL_6;
    case 57:
      v71 = Allocate(effPCPNeedleSpiralParam_t);
      effPCPNeedleSpiralParam_t___ctor(v71);
      v8 = effPCPNeedleSpiralParam_t__pCopy(v71, hData, &pos, 1);
      if (!*(v8 + 6))
      {
LABEL_5:
      }
LABEL_6:
      v10 = *(v8 + 4);
      break;
    case 58:
      v10 = Allocate(effPCP_object_Param_t);
      effPCP_object_Param_t___ctor(v10);
      if (hData)
      {
        Interface = QueryInterface(hData, byte);
        if (!Interface)
        {
          sub_8FC2C0(hData->klass->_1.element_class, v55, v73);
          if ((v73[0] & 1) != 0)
            v57 = v73[2];
          else
            v57 = v73 + 1;
          v58 = sub_8C4940(v57);
        }
      }
      else
      {
        Interface = 0;
      }
      v10[2] = Interface;
      *(v10 + 6) = offset;
      break;
    default:
      v10 = 0;
      break;
  }
  return v10;
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
  struct dds3EffectPCPData_Part_t_array *pcpData;
  s32 type_low;
  Il2CppObject *DataUnityOffSet;
  Il2CppObject *v13;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v16;
  s64 *v17;
  System_Array_o *v18;
  struct dds3EffectPCPData_Part_t_array *v21;
  u32 offset;
  u64 v25[3];

  pcpData = hPCPData->pcpData;
  type_low = LOWORD(pcpData->m_Items[number]->type);
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(&bytedata->obj, hPCPData->pcpData->m_Items[number]->offset + bPos, 58, *&number);
  v13 = DataUnityOffSet;
  if (DataUnityOffSet)
  {
    klass = DataUnityOffSet->klass;
    if (DataUnityOffSet->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_object_Param_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCP_object_Param_t, v25);
      if ((v25[0] & 1) != 0)
        v16 = v25[2];
      else
        v16 = v25 + 1;
      v17 = sub_8C4940(v16);
    }
  }
  v18 = NewSpecific(byte, LODWORD(DataUnityOffSet[1].klass->_1.namespaze));
  Copy_3880080(
    v13[1].klass,
    v13[1].monitor,
    v18,
    0,
    LODWORD(v13[1].klass->_1.namespaze) - LODWORD(v13[1].monitor),
    0);
  if (type_low == 3)
  {
    v21 = hPCPData->pcpData;
    offset = v21->m_Items[number]->offset;
    SobedPbSet(bytedata, offset + bPos);
  }
  return dds3EffectPartCreate(type_low, v18, 0);
}

// 0x1231e20
void dds3EffectPCPDelete(void **hData) {
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  struct effPart_dds3EffectPartFuncTable_tag_array *EffectPCPFuncTable;
  s64 klass_low;
  il2cpp_array_size_t max_length;
  struct effPart_dds3EffectPartFuncTable_tag_array *v15;
  s64 v16;
  u64 v18[3];

  v4 = *hData;
  if (v4)
  {
    klass = v4->klass;
    if (v4->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectPCP_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3EffectPCP_t, v18);
      if ((v18[0] & 1) != 0)
        v7 = v18[2];
      else
        v7 = v18 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  klass_low = LODWORD(v4[1].klass);
  max_length = EffectPCPFuncTable->max_length;
  if (klass_low < max_length)
  {
    if (EffectPCPFuncTable->m_Items[klass_low]->mDelete)
    {
      v15 = EffectPCPFuncTable;
      v16 = LODWORD(v4[1].klass);
      Invoke(v15->m_Items[v16]->mDelete, &v4[1].monitor);
    }
  }
}

// 0x1232000
void dds3EffectPCPDraw(void **hData) {
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  struct effPart_dds3EffectPartFuncTable_tag_array *EffectPCPFuncTable;
  s64 klass_low;
  il2cpp_array_size_t max_length;
  struct effPart_dds3EffectPartFuncTable_tag_array *v15;
  s64 v16;
  u64 v18[3];

  v4 = *hData;
  if (v4)
  {
    klass = v4->klass;
    if (v4->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectPCP_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3EffectPCP_t, v18);
      if ((v18[0] & 1) != 0)
        v7 = v18[2];
      else
        v7 = v18 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  klass_low = LODWORD(v4[1].klass);
  max_length = EffectPCPFuncTable->max_length;
  if (klass_low < max_length)
  {
    if (EffectPCPFuncTable->m_Items[klass_low]->mDraw)
    {
      v15 = EffectPCPFuncTable;
      v16 = LODWORD(v4[1].klass);
      Invoke(v15->m_Items[v16]->mDraw, &v4[1].monitor);
    }
  }
}

// 0x12321e0
void dds3EffectPCPDrawOff(void **hData) {
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  struct effPart_dds3EffectPartFuncTable_tag_array *EffectPCPFuncTable;
  s64 klass_low;
  il2cpp_array_size_t max_length;
  struct effPart_dds3EffectPartFuncTable_tag_array *v15;
  s64 v16;
  u64 v18[3];

  v4 = *hData;
  if (v4)
  {
    klass = v4->klass;
    if (v4->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectPCP_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3EffectPCP_t, v18);
      if ((v18[0] & 1) != 0)
        v7 = v18[2];
      else
        v7 = v18 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  klass_low = LODWORD(v4[1].klass);
  max_length = EffectPCPFuncTable->max_length;
  if (klass_low < max_length)
  {
    if (EffectPCPFuncTable->m_Items[klass_low]->mDrawOff)
    {
      v15 = EffectPCPFuncTable;
      v16 = LODWORD(v4[1].klass);
      Invoke(v15->m_Items[v16]->mDrawOff, &v4[1].monitor);
    }
  }
}

// 0x1233190
void dds3EffectPCPSetArea(void **hData, f32 area) {
  Il2CppObject *v6;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  struct effPart_dds3EffectPartFuncTable_tag_array *EffectPCPFuncTable;
  s64 klass_low;
  il2cpp_array_size_t max_length;
  struct effPart_dds3EffectPartFuncTable_tag_array *v17;
  s64 v18;
  u64 v20[3];

  v6 = *hData;
  if (v6)
  {
    klass = v6->klass;
    if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectPCP_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3EffectPCP_t, v20);
      if ((v20[0] & 1) != 0)
        v9 = v20[2];
      else
        v9 = v20 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  klass_low = LODWORD(v6[1].klass);
  max_length = EffectPCPFuncTable->max_length;
  if (klass_low < max_length)
  {
    if (EffectPCPFuncTable->m_Items[klass_low]->mSetArea)
    {
      v17 = EffectPCPFuncTable;
      v18 = LODWORD(v6[1].klass);
      Invoke(
        v17->m_Items[v18]->mSetArea,
        &v6[1].monitor,
        area);
    }
  }
}

// 0x1232fa0
void dds3EffectPCPSetColor(void **hData, u32 abgr) {
  u32 v4;
  Il2CppObject *v6;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  struct effPart_dds3EffectPartFuncTable_tag_array *EffectPCPFuncTable;
  s64 klass_low;
  il2cpp_array_size_t max_length;
  struct effPart_dds3EffectPartFuncTable_tag_array *v17;
  s64 v18;
  u64 v20[3];

  v4 = abgr;
  v6 = *hData;
  if (v6)
  {
    klass = v6->klass;
    if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectPCP_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3EffectPCP_t, v20);
      if ((v20[0] & 1) != 0)
        v9 = v20[2];
      else
        v9 = v20 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  klass_low = LODWORD(v6[1].klass);
  max_length = EffectPCPFuncTable->max_length;
  if (klass_low < max_length)
  {
    if (EffectPCPFuncTable->m_Items[klass_low]->mSetColor)
    {
      v17 = EffectPCPFuncTable;
      v18 = LODWORD(v6[1].klass);
      Invoke(
        v17->m_Items[v18]->mSetColor,
        &v6[1].monitor,
        v4);
    }
  }
}

// 0x1232d90
void dds3EffectPCPSetDirection(void **hData, sdfMatrix4_t *pMatrix) {
  UnityEngine_Matrix4x4_o *v4;
  Il2CppObject *v6;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  struct effPart_dds3EffectPartFuncTable_tag_array *EffectPCPFuncTable;
  s64 klass_low;
  il2cpp_array_size_t max_length;
  struct effPart_dds3EffectPartFuncTable_tag_array *v17;
  s64 v18;
  s64 v20;
  s64 v21;
  s64 v22;
  effPart_dds3EffectPartFuncTable_tag_SetDirectionDelegate_o *mSetDirection;
  s64 v24;
  s64 v25;
  s64 v26;
  UnityEngine_Matrix4x4_o v27;
  u64 v28[3];

  v4 = pMatrix;
  v6 = *hData;
  if (v6)
  {
    klass = v6->klass;
    if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectPCP_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3EffectPCP_t, v28);
      if ((v28[0] & 1) != 0)
        v9 = v28[2];
      else
        v9 = v28 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  klass_low = LODWORD(v6[1].klass);
  max_length = EffectPCPFuncTable->max_length;
  if (klass_low < max_length)
  {
    if (EffectPCPFuncTable->m_Items[klass_low]->mSetDirection)
    {
      v17 = EffectPCPFuncTable;
      v18 = LODWORD(v6[1].klass);
      v20 = *&v4->m00;
      v21 = *&v4->m20;
      v22 = *&v4->m21;
      mSetDirection = v17->m_Items[v18]->mSetDirection;
      *&v27.m01 = *&v4->m01;
      *&v27.m21 = v22;
      *&v27.m00 = v20;
      *&v27.m20 = v21;
      v24 = *&v4->m02;
      v25 = *&v4->m22;
      v26 = *&v4->m23;
      *&v27.m03 = *&v4->m03;
      *&v27.m23 = v26;
      *&v27.m02 = v24;
      *&v27.m22 = v25;
      Invoke(mSetDirection, &v6[1].monitor, &v27);
    }
  }
}

// 0x1232780
void dds3EffectPCPSetPosition(void **hData, sdfVector4_t pPos) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  Il2CppObject *v9;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v12;
  s64 *v13;
  struct effPart_dds3EffectPartFuncTable_tag_array *EffectPCPFuncTable;
  s64 klass_low;
  il2cpp_array_size_t max_length;
  struct effPart_dds3EffectPartFuncTable_tag_array *v20;
  s64 v21;
  u64 v23[3];
  UnityEngine_Vector4_o v24;

  w = pPos.w;
  z = pPos.z;
  y = pPos.y;
  x = pPos.x;
  v9 = *hData;
  if (v9)
  {
    klass = v9->klass;
    if (v9->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectPCP_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3EffectPCP_t, v23);
      if ((v23[0] & 1) != 0)
        v12 = v23[2];
      else
        v12 = v23 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  klass_low = LODWORD(v9[1].klass);
  max_length = EffectPCPFuncTable->max_length;
  if (klass_low < max_length)
  {
    if (EffectPCPFuncTable->m_Items[klass_low]->mSetPosition)
    {
      v20 = EffectPCPFuncTable;
      v21 = LODWORD(v9[1].klass);
      v24.x = x;
      v24.y = y;
      v24.z = z;
      v24.w = w;
      Invoke(
        v20->m_Items[v21]->mSetPosition,
        &v9[1].monitor,
        v24);
    }
  }
}

// 0x1232b80
void dds3EffectPCPSetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
  UnityEngine_Matrix4x4_o *v4;
  Il2CppObject *v6;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  struct effPart_dds3EffectPartFuncTable_tag_array *EffectPCPFuncTable;
  s64 klass_low;
  il2cpp_array_size_t max_length;
  struct effPart_dds3EffectPartFuncTable_tag_array *v17;
  s64 v18;
  s64 v20;
  s64 v21;
  s64 v22;
  effPart_dds3EffectPartFuncTable_tag_SetRotateMatrixDelegate_o *mSetRotateMatrix;
  s64 v24;
  s64 v25;
  s64 v26;
  UnityEngine_Matrix4x4_o v27;
  u64 v28[3];

  v4 = pMatrix;
  v6 = *hData;
  if (v6)
  {
    klass = v6->klass;
    if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectPCP_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3EffectPCP_t, v28);
      if ((v28[0] & 1) != 0)
        v9 = v28[2];
      else
        v9 = v28 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  klass_low = LODWORD(v6[1].klass);
  max_length = EffectPCPFuncTable->max_length;
  if (klass_low < max_length)
  {
    if (EffectPCPFuncTable->m_Items[klass_low]->mSetRotateMatrix)
    {
      v17 = EffectPCPFuncTable;
      v18 = LODWORD(v6[1].klass);
      v20 = *&v4->m00;
      v21 = *&v4->m20;
      v22 = *&v4->m21;
      mSetRotateMatrix = v17->m_Items[v18]->mSetRotateMatrix;
      *&v27.m01 = *&v4->m01;
      *&v27.m21 = v22;
      *&v27.m00 = v20;
      *&v27.m20 = v21;
      v24 = *&v4->m02;
      v25 = *&v4->m22;
      v26 = *&v4->m23;
      *&v27.m03 = *&v4->m03;
      *&v27.m23 = v26;
      *&v27.m02 = v24;
      *&v27.m22 = v25;
      Invoke(mSetRotateMatrix, &v6[1].monitor, &v27);
    }
  }
}

// 0x1232990
void dds3EffectPCPSetScale(void **hData, f32 scale) {
  Il2CppObject *v6;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  struct effPart_dds3EffectPartFuncTable_tag_array *EffectPCPFuncTable;
  s64 klass_low;
  il2cpp_array_size_t max_length;
  struct effPart_dds3EffectPartFuncTable_tag_array *v17;
  s64 v18;
  u64 v20[3];

  v6 = *hData;
  if (v6)
  {
    klass = v6->klass;
    if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectPCP_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3EffectPCP_t, v20);
      if ((v20[0] & 1) != 0)
        v9 = v20[2];
      else
        v9 = v20 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  klass_low = LODWORD(v6[1].klass);
  max_length = EffectPCPFuncTable->max_length;
  if (klass_low < max_length)
  {
    if (EffectPCPFuncTable->m_Items[klass_low]->mSetScale)
    {
      v17 = EffectPCPFuncTable;
      v18 = LODWORD(v6[1].klass);
      Invoke(
        v17->m_Items[v18]->mSetScale,
        &v6[1].monitor,
        scale);
    }
  }
}

// 0x1230550
void dds3EffectPartBillboardScale(billHandle_t **hBillboard, f32 scale) {
  dds3BillboardSetScale(hBillboard, scale, scale);
}

// 0x12305d0
void dds3EffectPartBillboardScaleO(void **hData, f32 scale) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  billHandle_t_o *v10[3];
  billHandle_t_o *hBillboard;

  hBillboard = 0;
  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != billHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, billHandle_t, v10);
      if ((v10[0] & 1) != 0)
        v8 = v10[2];
      else
        v8 = v10 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  hBillboard = *hData;
  dds3BillboardSetScale(&hBillboard, scale, scale);
}

// 0x122d290
effPartHandle_t *dds3EffectPartCopy(effPartHandle_t **hEffPartSrc, s32 bPos) {
  effPartHandle_t_o *v5;
  struct effPart_dds3EffectPartFuncTable_tag_array *EffectPartFuncTable;
  s64 type;
  s32 max_length;
  struct effPart_dds3EffectPartFuncTable_tag_array *v14;
  s64 v15;

  v5 = Allocate(effPartHandle_t);
  effPartHandle_t___ctor(v5);
  v5->type = (*hEffPartSrc)->type;
  type = (*hEffPartSrc)->type;
  max_length = EffectPartFuncTable->max_length;
  if (max_length > type)
  {
    else if (type >= max_length)
    {
      goto LABEL_10;
    }
    if (EffectPartFuncTable->m_Items[type]->mCopy)
    {
      v14 = EffectPartFuncTable;
      v15 = (*hEffPartSrc)->type;
      v5->pHandle = Invoke(
                             v14->m_Items[v15]->mCopy,
                             &(*hEffPartSrc)->pHandle,
                             bPos,
                             0);
    }
  }
  return v5;
}

// 0x122d830
effPartHandle_t *dds3EffectPartCopyO(void **hData, s32 bPos) {
  s32 v3;
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  effPartHandle_t_o *v11[3];
  effPartHandle_t_o *hEffPartSrc;

  v3 = bPos;
  hEffPartSrc = 0;
  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPartHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPartHandle_t, v11);
      if ((v11[0] & 1) != 0)
        v8 = v11[2];
      else
        v8 = v11 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  hEffPartSrc = *hData;
  return dds3EffectPartCopy(&hEffPartSrc, v3);
}

// 0x122bd60
effPartHandle_t *dds3EffectPartCreate(u16 type, void *pData, s32 bPos) {
  effPartHandle_t_o *v7;
  s64 *Interface;
  struct effPart_dds3EffectPartFuncTable_tag_array *EffectPartFuncTable;
  s32 max_length;
  struct effPart_dds3EffectPartFuncTable_tag_array *v19;
  Il2CppObject *v22;

  v22 = pData;
  v7 = Allocate(effPartHandle_t);
  effPartHandle_t___ctor(v7);
  v7->type = type;
  if (type == 3)
  {
    else if (pData)
    {
      goto LABEL_7;
    }
    Interface = 0;
LABEL_14:
    SobedPbSet(Interface, bPos);
  }
  max_length = EffectPartFuncTable->max_length;
  if (max_length > type)
  {
    if (EffectPartFuncTable->m_Items[type]->mCreate)
    {
      v19 = EffectPartFuncTable;
      v7->pHandle = Invoke(
                             v19->m_Items[type]->mCreate,
                             &v22,
                             bPos,
                             0);
    }
  }
  return v7;
}

// 0x122c3b0
void dds3EffectPartDelete(effPartHandle_t **hEffPart) {
  struct effPart_dds3EffectPartFuncTable_tag_array *EffectPartFuncTable;
  s64 type;
  s32 max_length;
  struct effPart_dds3EffectPartFuncTable_tag_array *v10;
  s64 v11;

  type = (*hEffPart)->type;
  max_length = EffectPartFuncTable->max_length;
  if (max_length > type)
  {
    else if (type >= max_length)
    {
      goto LABEL_10;
    }
    if (EffectPartFuncTable->m_Items[type]->mDelete)
    {
      v10 = EffectPartFuncTable;
      v11 = (*hEffPart)->type;
      Invoke(
        v10->m_Items[v11]->mDelete,
        &(*hEffPart)->pHandle);
    }
  }
}

// 0x122c8c0
void dds3EffectPartDeleteO(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppObject *v8;
  u64 v9[3];

  v8 = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPartHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPartHandle_t, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = *hData;
  dds3EffectPartDelete(&v8);
}

// 0x122c9e0
void dds3EffectPartDraw(effPartHandle_t **hEffPart) {
  struct effPart_dds3EffectPartFuncTable_tag_array *EffectPartFuncTable;
  s64 type;
  s32 max_length;
  struct effPart_dds3EffectPartFuncTable_tag_array *v10;
  s64 v11;

  type = (*hEffPart)->type;
  max_length = EffectPartFuncTable->max_length;
  if (max_length > type)
  {
    else if (type >= max_length)
    {
      goto LABEL_10;
    }
    if (EffectPartFuncTable->m_Items[type]->mDraw)
    {
      v10 = EffectPartFuncTable;
      v11 = (*hEffPart)->type;
      Invoke(
        v10->m_Items[v11]->mDraw,
        &(*hEffPart)->pHandle);
    }
  }
}

// 0x122cef0
void dds3EffectPartDrawO(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppObject *v8;
  u64 v9[3];

  v8 = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPartHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPartHandle_t, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = *hData;
  dds3EffectPartDraw(&v8);
}

// 0x122d010
void dds3EffectPartDrawOff(effPartHandle_t **hEffPart) {
  struct effPart_dds3EffectPartFuncTable_tag_array *EffectPartFuncTable;
  s64 type;
  s32 max_length;
  struct effPart_dds3EffectPartFuncTable_tag_array *v10;
  s64 v11;

  type = (*hEffPart)->type;
  max_length = EffectPartFuncTable->max_length;
  if (max_length > type)
  {
    else if (type >= max_length)
    {
      goto LABEL_10;
    }
    if (EffectPartFuncTable->m_Items[type]->mDrawOff)
    {
      v10 = EffectPartFuncTable;
      v11 = (*hEffPart)->type;
      Invoke(
        v10->m_Items[v11]->mDrawOff,
        &(*hEffPart)->pHandle);
    }
  }
}

// 0x122d170
void dds3EffectPartDrawOffO(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppObject *v8;
  u64 v9[3];

  v8 = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPartHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPartHandle_t, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = *hData;
  dds3EffectPartDrawOff(&v8);
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
  Il2CppObject *v5;
  u64 *v6;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  dds3ModelHandle_t_o *v13[3];
  dds3ModelHandle_t_o *dst;

  v5 = *hData;
  v6 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v6);
  dst = v6;
  if (v5)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, v13);
      if ((v13[0] & 1) != 0)
        v9 = v13[2];
      else
        v9 = v13 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  dds3ModelHandle_t__dCopy(v5, &dst);
  dds3EffectPartModelInit(&dst);
  return dst;
}

// 0x12308a0
dds3ModelHandle_t *dds3EffectPartModelCreate(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v6;
  Il2CppClass *v7;
  s64 *Interface;
  char *v9;
  s64 *v10;
  SOBED_PB_LIST_o *PbList;
  dds3ModelHandle_t_o *v14;
  dds3ModelHandle_t_o *v16;
  u64 v17[3];

  v16 = 0;
  v6 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v6->klass->_1.element_class, v7, v17);
      if ((v17[0] & 1) != 0)
        v9 = v17[2];
      else
        v9 = v17 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  else
  {
    Interface = 0;
  }
  v16 = mdlLoad(7, 0, Interface, bPos, 0);
  PbList = GetPbList();
  if (PbList)
  {
    v14 = v16;
    v16->modelRoot->oData = PbList->gobj;
    v14->modelRoot->reversePB = PbList->reversePB;
  }
  dds3EffectPartModelInit(&v16);
  return v16;
}

// 0x12310e0
void dds3EffectPartModelDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  UnityEngine_Object_o *v9;
  UnityEngine_Object_o *v11;
  u64 v12[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, v12);
      if ((v12[0] & 1) != 0)
        v6 = v12[2];
      else
        v6 = v12 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  mdlFreeSub(hData);
  v9 = *&v3[4].klass->_2.initializationExceptionGCHandle;
  if (op_Inequality(v9, 0, 0))
  {
    v11 = *&v3[4].klass->_2.initializationExceptionGCHandle;
    Destroy_27360000(v11);
    *&v3[4].klass->_2.initializationExceptionGCHandle = 0;
  }
}

// 0x1230b90
void dds3EffectPartModelDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppObject *v8;
  dds3ModelHandle_t_o *v10;
  UnityEngine_Object_o *oData;
  Il2CppObject *v12;
  UnityEngine_GameObject_o *v13;
  UnityEngine_Transform_o *transform;
  Il2CppObject *Component_object;
  Il2CppObject *v17;
  struct sdfModelRootNode_t_o *modelRoot;
  s64 v19;
  s64 v20;
  s64 v21;
  s64 v22;
  s64 v23;
  s64 v24;
  s64 v25;
  UnityEngine_Transform_o *v26;
  f32 v28;
  f32 v29;
  f32 v30;
  f32 v31;
  f32 v32;
  f32 v33;
  f32 v34;
  f32 v35;
  f32 *p_SDF_CC_NDNM;
  f32 v39;
  f32 v40;
  f32 v41;
  UnityEngine_Transform_o *v42;
  UnityEngine_Transform_o *v44;
  s64 v45;
  s64 v46;
  s64 v47;
  s64 v48;
  s64 v49;
  s64 v50;
  s64 v51;
  UnityEngine_Transform_o *v53;
  dds3ModelHandle_t_o *v54;
  UnityEngine_Transform_o *v55;
  UnityEngine_Matrix4x4_o v57;
  UnityEngine_Matrix4x4_o v58;
  UnityEngine_Matrix4x4_o v59;
  UnityEngine_Matrix4x4_o v60;
  UnityEngine_Matrix4x4_o v61;
  UnityEngine_Matrix4x4_o v62;
  s64 v63;
  s64 v64;
  s64 v65;
  s64 v66;
  s64 v67;
  s64 v68;
  s64 v69;
  s64 v70;
  dds3ModelHandle_t_o *aHandle;
  UnityEngine_Vector3_o v72;
  UnityEngine_Vector3_o v73;
  UnityEngine_Vector3_o v74;
  UnityEngine_Vector3_o v75;
  UnityEngine_Vector4_o v76;
  UnityEngine_Quaternion_o v77;

  aHandle = 0;
  v69 = 0;
  v70 = 0;
  v67 = 0;
  v68 = 0;
  v65 = 0;
  v66 = 0;
  v63 = 0;
  v64 = 0;
  memset(&v62, 0, sizeof(v62));
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, &v61);
      if ((LOBYTE(v61.m00) & 1) != 0)
        v6 = *&v61.m01;
      else
        v6 = &v61.m00 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  aHandle = *hData;
  v8 = *&v3[4].klass->_2.initializationExceptionGCHandle;
  v10 = aHandle;
  if (!op_Equality(v8, 0, 0))
    goto LABEL_24;
  oData = aHandle->modelRoot->oData;
  if (!op_Equality(oData, 0, 0))
  {
    v12 = aHandle->modelRoot->oData;
    v13 = Find("Character", 0);
    transform = get_transform(v13, 0);
    v8 = Instantiate_object__425664(v12, transform, 0);
    Component_object = GetComponent_object_(v8);
    if (op_Equality(Component_object, 0, 0))
      Component_object = AddComponent_object_(v8);
    SethModel(Component_object, aHandle);
    SetAutoHide(Component_object, 1);
    SetFrameAnime(Component_object, 1);
    v10 = aHandle;
    aHandle->modelRoot->modelobj = v8;
LABEL_24:
    if ((v10->stat & 1) == 0)
    {
      v17 = GetComponent_object_(v8);
      StepFrame(v17);
      modelRoot = v10->modelRoot;
      v19 = *&modelRoot->tm.m00;
      v20 = *&modelRoot->tm.m20;
      v21 = *&modelRoot->tm.m21;
      v65 = *&modelRoot->tm.m01;
      v66 = v21;
      v63 = v19;
      v64 = v20;
      v22 = *&modelRoot->tm.m02;
      v23 = *&modelRoot->tm.m22;
      v25 = *&modelRoot->tm.m03;
      v24 = *&modelRoot->tm.m23;
      v69 = v25;
      v70 = v24;
      v67 = v22;
      v68 = v23;
      v26 = get_transform(v8, 0);
      sub_1A00880(&v63, 3u);
      v29 = v28;
      v31 = v30;
      v33 = v32;
      v35 = v34;
      v76.x = v29;
      v76.y = v31;
      v76.z = v33;
      v76.w = v35;
      v72 = op_Implicit_8738992(v76);
      p_SDF_CC_NDNM = &SDF_CC_NDNM;
      v39 = p_SDF_CC_NDNM[41];
      v40 = p_SDF_CC_NDNM[42];
      v41 = p_SDF_CC_NDNM[43];
      v75.x = v39;
      v75.y = v40;
      v75.z = v41;
      v73 = Scale(v72, v75);
      set_position(v26, v73);
      v42 = get_transform(v8, 0);
      v44 = v42;
      v45 = *&mod_matrix.m00;
      v46 = *&mod_matrix.m20;
      v47 = *&mod_matrix.m21;
      *&v61.m01 = *&mod_matrix.m01;
      *&v61.m21 = v47;
      *&v61.m00 = v45;
      *&v61.m20 = v46;
      v48 = *&mod_matrix.m02;
      v49 = *&mod_matrix.m22;
      v51 = *&mod_matrix.m03;
      v50 = *&mod_matrix.m23;
      *&v61.m03 = v51;
      *&v61.m23 = v50;
      *&v61.m02 = v48;
      *&v61.m22 = v49;
      sub_19FF440(&v63, 0, &v60);
      v58 = v61;
      v57 = v60;
      op_Multiply(&v59, &v58, &v57, 0);
      v62 = v59;
      v77.x = sub_19FEAD0(&v62, 0);
      set_rotation(v44, v77);
      v53 = get_transform(v8, 0);
      v54 = aHandle;
      v55 = v53;
      v74 = op_Implicit_8738992(aHandle->modelRoot->scale);
      set_localScale(v55, v74);
      (v17->klass->vtable[12].methodPtr)(v17, v54->modelRoot->color, v17->klass->vtable[12].method);
      if ((v54->stat & 6) == 0 && v54->blur)
      {
        mdlLinkBlur(&aHandle);
      }
    }
  }
}

// 0x1230a40
void dds3EffectPartModelDrawOff(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  UnityEngine_Object_o *v6;
  char *v7;
  s64 *v8;
  u64 v9[3];

  v3 = *hData;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  v6 = *&v3[4].klass->_2.initializationExceptionGCHandle;
  if (op_Inequality(v6, 0, 0)
    && get_activeSelf(*&v3[4].klass->_2.initializationExceptionGCHandle))
  {
    SetActive(*&v3[4].klass->_2.initializationExceptionGCHandle, 0, 0);
  }
}

// 0x1230700
void dds3EffectPartModelInit(dds3ModelHandle_t **hModel) {
  dds3ModelHandle_t_o *v6;
  UnityEngine_Vector4_o v7;
  UnityEngine_Vector4_o v8;
  UnityEngine_Vector4_o v9;

  *&v9.x = 0;
  *&v9.z = 0;
  *&v8.x = 0;
  *&v8.z = 0;
  *&v7.x = 0;
  *&v7.z = 0;
  sub_854690(&v7.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v9.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v8.x, 1.0, 1.0, 1.0, 0.0);
  SDF_VU0__LOADVECTOR(v7);
  mdlSetPosition(hModel);
  SDF_VU0__LOADVECTOR(v9);
  mdlSetRotate(hModel);
  SDF_VU0__LOADVECTOR(v8);
  mdlSetScale(hModel);
  mdlSetColor(hModel, 0x80808080);
  else
  {
    v6 = *hModel;
      goto LABEL_12;
  }
LABEL_12:
  mdlShow(v6);
}

// 0x1231840
void dds3EffectPartModelSetColor(void **hData, u32 abgr) {
  u32 v3;
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  struct sdfModelRootNode_t_o *modelRoot;
  UnityEngine_Object_o *modelobj;
  Il2CppObject *Component_object;
  dds3ModelHandle_t_o *v15[3];
  dds3ModelHandle_t_o *aHandle;

  v3 = abgr;
  aHandle = 0;
  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, v15);
      if ((v15[0] & 1) != 0)
        v8 = v15[2];
      else
        v8 = v15 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  aHandle = *hData;
  mdlSetColor(&aHandle, v3);
  modelRoot = aHandle->modelRoot;
  if (modelRoot)
  {
    modelobj = modelRoot->modelobj;
    if (op_Inequality(modelobj, 0, 0))
    {
      Component_object = GetComponent_object_(aHandle->modelRoot->modelobj);
      if (op_Inequality(Component_object, 0, 0))
        (Component_object->klass->vtable[10].methodPtr)(
          Component_object,
          v3,
          Component_object->klass->vtable[10].method);
    }
  }
}

// 0x12313c0
void dds3EffectPartModelSetPosition(void **hData, sdfVector4_t pPos) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  Il2CppObject *v8;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  Il2CppObject *v14;
  u64 v15[3];
  UnityEngine_Vector4_o v16;

  w = pPos.w;
  z = pPos.z;
  y = pPos.y;
  x = pPos.x;
  v14 = 0;
  v8 = *hData;
  if (*hData)
  {
    klass = v8->klass;
    if (v8->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, v15);
      if ((v15[0] & 1) != 0)
        v11 = v15[2];
      else
        v11 = v15 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  v16.x = x;
  v16.y = y;
  v16.z = z;
  v16.w = w;
  v14 = *hData;
  SDF_VU0__LOADVECTOR(v16);
  mdlSetPosition(&v14);
}

// 0x12316a0
void dds3EffectPartModelSetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  s64 v10;
  s64 v11;
  s64 v12;
  s64 v13;
  s64 v14;
  s64 v15;
  Il2CppClass *v16;
  Il2CppClass *v17;
  void *v18;
  void *v19;
  void *v20;
  void *v21;
  Il2CppClass *v22;
  Il2CppClass *v23;
  Il2CppClass *v24;
  void *v25;
  void *v26;
  void *v27;
  void *v28;
  UnityEngine_Matrix4x4_o v29;
  Il2CppClass *v30;
  Il2CppClass *v31;
  Il2CppClass *v32;
  void *v33;
  void *v34;
  void *v35;
  Il2CppClass *v36;
  void *v37;
  u64 v38[3];

  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v5 = *hData;
  if (v5)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, v38);
      if ((v38[0] & 1) != 0)
        v8 = v38[2];
      else
        v8 = v38 + 1;
      v9 = sub_8C4940(v8);
    }
    if (v5[4].klass)
    {
      v10 = *&pMatrix->m00;
      v11 = *&pMatrix->m20;
      v12 = *&pMatrix->m21;
      *&v29.m01 = *&pMatrix->m01;
      *&v29.m21 = v12;
      *&v29.m00 = v10;
      *&v29.m20 = v11;
      v13 = *&pMatrix->m02;
      v14 = *&pMatrix->m22;
      v15 = *&pMatrix->m23;
      *&v29.m03 = *&pMatrix->m03;
      *&v29.m23 = v15;
      *&v29.m02 = v13;
      *&v29.m22 = v14;
      SDF_VU0__LOADMATRIX(&v29);
      v16 = *&pMatrix->m00;
      v17 = *&pMatrix->m20;
      v18 = *&pMatrix->m21;
      v32 = *&pMatrix->m01;
      v33 = v18;
      v30 = v16;
      v31 = v17;
      v19 = *&pMatrix->m02;
      v20 = *&pMatrix->m22;
      v21 = *&pMatrix->m23;
      v36 = *&pMatrix->m03;
      v37 = v21;
      v34 = v19;
      v35 = v20;
      sub_1A00880(&v5[4].klass->_1.castClass, 3u);
      sub_1A00AD0(&v30, 3u);
      v22 = v5[4].klass;
      v24 = v30;
      v23 = v31;
      v25 = v33;
      v22->_1.parent = v32;
      v22->_1.generic_class = v25;
      v22->_1.castClass = v24;
      v22->_1.declaringType = v23;
      v27 = v34;
      v26 = v35;
      v28 = v37;
      v22->_1.klass = v36;
      v22->_1.fields = v28;
      v22->_1.typeDefinition = v27;
      v22->_1.interopData = v26;
    }
  }
}

// 0x1231520
void dds3EffectPartModelSetScale(void **hData, f32 scale) {
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  UnityEngine_Vector4_o v10;
  dds3ModelHandle_t_o *v11[3];
  dds3ModelHandle_t_o *aHandle;

  aHandle = 0;
  *&v10.x = 0;
  *&v10.z = 0;
  v4 = *hData;
  if (*hData)
  {
    klass = v4->klass;
    if (v4->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, v11);
      if ((v11[0] & 1) != 0)
        v7 = v11[2];
      else
        v7 = v11 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  aHandle = *hData;
  *&v10.x = 0;
  *&v10.z = 0;
  sub_854930(&v10, 2u);
  sub_854930(&v10, 1u);
  sub_854930(&v10, 0);
  SDF_VU0__LOADVECTOR(v10);
  mdlSetScale(&aHandle);
}

// 0x12304c0
billHandle_t *dds3EffectPartP2ABillboardCreate(void **pData, s32 bPos, bool tbldata) {
  Il2CppObject *v6;

  v6 = *pData;
  return dds3BillboardCreate(1, v6, bPos, "dds3EffectPartP2ABillboardCreate");
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
  u32 v3;
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  effPartHandle_t_o *v10[3];
  effPartHandle_t_o *hEffPart;

  v3 = abgr;
  hEffPart = 0;
  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPartHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPartHandle_t, v10);
      if ((v10[0] & 1) != 0)
        v8 = v10[2];
      else
        v8 = v10 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  hEffPart = *hData;
  dds3EffectPartSetColor(&hEffPart, v3);
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
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  Il2CppObject *v8;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  Il2CppObject *v13;
  u64 v14[3];
  UnityEngine_Vector4_o v15;

  w = pPos.w;
  z = pPos.z;
  y = pPos.y;
  x = pPos.x;
  v13 = 0;
  v8 = *hData;
  if (*hData)
  {
    klass = v8->klass;
    if (v8->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPartHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPartHandle_t, v14);
      if ((v14[0] & 1) != 0)
        v11 = v14[2];
      else
        v11 = v14 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  v13 = *hData;
  v15.x = x;
  v15.y = y;
  v15.z = z;
  v15.w = w;
  dds3EffectPartSetPosition(&v13, v15);
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
  UnityEngine_Matrix4x4_o *v3;
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  s64 v10;
  s64 v11;
  s64 v12;
  s64 v13;
  s64 v14;
  s64 v15;
  UnityEngine_Matrix4x4_o v16;
  UnityEngine_Matrix4x4_o v17;
  Il2CppObject *v18;

  v3 = pMatrix;
  v18 = 0;
  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPartHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPartHandle_t, &v17);
      if ((LOBYTE(v17.m00) & 1) != 0)
        v8 = *&v17.m01;
      else
        v8 = &v17.m00 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v18 = *hData;
  v10 = *&v3->m00;
  v11 = *&v3->m20;
  v12 = *&v3->m21;
  *&v17.m01 = *&v3->m01;
  *&v17.m21 = v12;
  *&v17.m00 = v10;
  *&v17.m20 = v11;
  v13 = *&v3->m23;
  v14 = *&v3->m02;
  v15 = *&v3->m22;
  *&v17.m03 = *&v3->m03;
  *&v17.m23 = v13;
  *&v17.m02 = v14;
  *&v17.m22 = v15;
  v16 = v17;
  dds3EffectPartSetRotateMatrix(&v18, &v16);
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
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  effPartHandle_t_o *v10[3];
  effPartHandle_t_o *hEffPart;

  hEffPart = 0;
  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPartHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPartHandle_t, v10);
      if ((v10[0] & 1) != 0)
        v8 = v10[2];
      else
        v8 = v10 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  hEffPart = *hData;
  dds3EffectPartSetScale(&hEffPart, scale);
}

// 0x1230430
billHandle_t *dds3EffectPartTMXBillboardCreate(void **pData, s32 bPos, bool tbldata) {
  Il2CppObject *v6;

  v6 = *pData;
  return dds3BillboardCreate(0, v6, bPos, "dds3EffectPartTMXBillboardCreate");
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
