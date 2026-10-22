#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct billHandle_t billHandle_t;
typedef struct dds3EffectPCPData_t dds3EffectPCPData_t;
typedef struct dds3FlashPolyList_t dds3FlashPolyList_t;
typedef struct dds3HermitianTrackPoly_tag dds3HermitianTrackPoly_tag;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct dds3TrackPoly_t dds3TrackPoly_t;
typedef struct effBTL_t effBTL_t;
typedef struct effEveBEDCutHandle_t effEveBEDCutHandle_t;
typedef struct effEveBEDParams_t effEveBEDParams_t;
typedef struct effPCPBossBUNSIN2Param_t effPCPBossBUNSIN2Param_t;
typedef struct effPCPBossBUNSIN2_t effPCPBossBUNSIN2_t;
typedef struct effPCPBossBUNSINParam_t effPCPBossBUNSINParam_t;
typedef struct effPCPBossBUNSIN_t effPCPBossBUNSIN_t;
typedef struct effPCPBossBaelParam_t effPCPBossBaelParam_t;
typedef struct effPCPBossBael_t effPCPBossBael_t;
typedef struct effPCPBossDengekiParam_t effPCPBossDengekiParam_t;
typedef struct effPCPBossDengeki_t effPCPBossDengeki_t;
typedef struct effPCPBossKAGU2AttackParam_t effPCPBossKAGU2AttackParam_t;
typedef struct effPCPBossKAGU2Attack_t effPCPBossKAGU2Attack_t;
typedef struct effPCPBossKAGU2MUHENKParam_t effPCPBossKAGU2MUHENKParam_t;
typedef struct effPCPBossKAGU2MUHENK_t effPCPBossKAGU2MUHENK_t;
typedef struct effPCPBossKAGUAttackParam_t effPCPBossKAGUAttackParam_t;
typedef struct effPCPBossKAGUAttack_t effPCPBossKAGUAttack_t;
typedef struct effPCPBossKAGUInvokeParam_t effPCPBossKAGUInvokeParam_t;
typedef struct effPCPBossKAGUInvoke_t effPCPBossKAGUInvoke_t;
typedef struct effPCPBossKAGUThunderboltParam_t effPCPBossKAGUThunderboltParam_t;
typedef struct effPCPBossKAGUThunderbolt_t effPCPBossKAGUThunderbolt_t;
typedef struct effPCPBossMETATOBeamParam_t effPCPBossMETATOBeamParam_t;
typedef struct effPCPBossMETATOBeam_t effPCPBossMETATOBeam_t;
typedef struct effPCPBossONGY2Param_t effPCPBossONGY2Param_t;
typedef struct effPCPBossONGY2_t effPCPBossONGY2_t;
typedef struct effPCPBossONGYParam_t effPCPBossONGYParam_t;
typedef struct effPCPBossONGY_t effPCPBossONGY_t;
typedef struct effPCPBossThunderboltParam_t effPCPBossThunderboltParam_t;
typedef struct effPCPBossThunderbolt_t effPCPBossThunderbolt_t;
typedef struct effPCPCrack2Param_t effPCPCrack2Param_t;
typedef struct effPCPCrackParam_t effPCPCrackParam_t;
typedef struct effPCPCrackPartFlash_t effPCPCrackPartFlash_t;
typedef struct effPCPCrack_t effPCPCrack_t;
typedef struct effPCPDANTE_Damage_Param_t effPCPDANTE_Damage_Param_t;
typedef struct effPCPDANTE_Damage_tag effPCPDANTE_Damage_tag;
typedef struct effPCPDANTE_ShowTime_Param_t effPCPDANTE_ShowTime_Param_t;
typedef struct effPCPDANTE_ShowTime_tag effPCPDANTE_ShowTime_tag;
typedef struct effPCPDANTE_Thunder_Param_t effPCPDANTE_Thunder_Param_t;
typedef struct effPCPDANTE_Thunder_tag effPCPDANTE_Thunder_tag;
typedef struct effPCPDANTE_UV_tag effPCPDANTE_UV_tag;
typedef struct effPCPHelperBEDParam_t effPCPHelperBEDParam_t;
typedef struct effPCPHelperBED_tag effPCPHelperBED_tag;
typedef struct effPCPMuzzleFlashParam_t effPCPMuzzleFlashParam_t;
typedef struct effPCPMuzzleFlash_tag effPCPMuzzleFlash_tag;
typedef struct effPCPScreenCrackModelParam_t effPCPScreenCrackModelParam_t;
typedef struct effPCPScreenCrackModel_t effPCPScreenCrackModel_t;
typedef struct effPCP_BED_Param_t effPCP_BED_Param_t;
typedef struct effPCP_BED_tag effPCP_BED_tag;
typedef struct effPCP_HBED2_Param_t effPCP_HBED2_Param_t;
typedef struct effPCP_HBED2_tag effPCP_HBED2_tag;
typedef struct effPCP_PBCamera_Param_t effPCP_PBCamera_Param_t;
typedef struct effPCP_PBCamera_tag effPCP_PBCamera_tag;
typedef struct effPCP_ThunderPolyListParam_t effPCP_ThunderPolyListParam_t;
typedef struct effPCP_ThunderPolyList_t effPCP_ThunderPolyList_t;
typedef struct effPCP_ThunderPolyParam_t effPCP_ThunderPolyParam_t;
typedef struct effPCP_ThunderPoly_t effPCP_ThunderPoly_t;
typedef struct effPartHandle_t effPartHandle_t;
typedef struct mdlManager_mdlTbMbAbLoadCb_t mdlManager_mdlTbMbAbLoadCb_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;
typedef struct nbPanelFlashData_t nbPanelFlashData_t;
typedef struct sdf3DLightParallelPacket_t sdf3DLightParallelPacket_t;
typedef struct sdf3DPrimPolyParm_t sdf3DPrimPolyParm_t;
typedef struct sdfMat_t sdfMat_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

static u32 dds3RBackColor;
static sdfVector4_t dds3RCameraTargetPos;
static sdfVector4_t dds3RCameraEyePos;
static sdfVector4_t dds3RCameraUpVector;
static dds3ModelHandle_t *hEffPCPBossONGY_Model;
static u32 effPCPBossONGY_Count;
static u32 effPCPBossONGY_RFrame;
static sdf3DLightParallelPacket_t *effPCPBossONGY_LightPacket;
static sdf3DPrimPolyParm_t *effPCPBossONGY_PolyParm;
static u32 effPCPBossONGY_FaceIndex[20];
static sdfVector4_t effPCPBossKAGUAttackConvergePoint;
static sdfVector4_t effPCPBossKAGU2AttackConvergePoint;
static effPCPDANTE_UV_tag *effPCPDANTE_Bingo_UV;
static effPCPDANTE_UV_tag *effPCPDANTE_AreYouReady_UV;
static effPCPDANTE_UV_tag *effPCPDANTE_ShowTime_UV;
static void **effPCPDANTE_Sprite;
static s32 effBossEvePadVibeFrameStart[2];
static s32 effBossEvePadVibeFrame[2];
static u8 effBossEvePadVibePower[2];
static u8 effBossEvePadVibeType[2];

void Clear(mdlManager_mdlTbMbAbLoadCb_t *this);
f32 DDS3EFFECT_RAND_FA(f32 r);
u32 DDS3EFFECT_RAND_I(void);
f32 DDS3EFFECT_RAND_PM(void);
void FromEuler(f32 aRotateX, f32 aRotateY, f32 aRotateZ);
void *GetEffPCPAgiFireballPart(void *hData, s32 offset);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
void LookAtMatrix(sdfVector4_t aTarget, sdfVector4_t aEye, sdfVector4_t aDown);
void Mult(void);
void MultMatrixNoArg(void);
void ReverseMatrix(void);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__ADDVECTOR_A_C(void);
void SDF_VU0__ADDVECTOR_B_A(void);
void SDF_VU0__APPLYMATRIX(void);
void SDF_VU0__APPLYMATRIX_B(void);
void SDF_VU0__APPLYMATRIX_XYZ(void);
void SDF_VU0__COPYMATRIX_A_TO_B(void);
void SDF_VU0__COPYMATRIX_A_TO_C(void);
void SDF_VU0__COPYMATRIX_C_TO_A(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__COPYVECTOR_A_TO_B(void);
void SDF_VU0__COPYVECTOR_A_TO_C(void);
void SDF_VU0__COPYVECTOR_B_TO_C(void);
void SDF_VU0__COPYVECTOR_C_TO_A(void);
void SDF_VU0__COPYVECTOR_C_TO_B(void);
f32 SDF_VU0__GETLENGTH(void);
void SDF_VU0__INTERPOLATE(f32 rate);
void SDF_VU0__LOADIDENTITYVECTOR(void);
void SDF_VU0__LOADMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_C(sdfVector4_t p);
void SDF_VU0__MULVECTOR(void);
void SDF_VU0__NORMALIZE(void);
void SDF_VU0__OUTERPRODUCT(void);
void SDF_VU0__RESET_ROW3(void);
sdfVector4_t SDF_VU0__Retdds3ColorItoF(u32 rgba, f32 ratio);
void SDF_VU0__SCALEVECTOR(f32 v);
void SDF_VU0__SCALEVECTOR_B(f32 v);
void SDF_VU0__SETVECTOR_X(f32 v);
void SDF_VU0__SETVECTOR_Z(f32 v);
void SDF_VU0__STOREIDENTITY(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREIDENTITYVECTOR(sdfVector4_t *p);
void SDF_VU0__STOREMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__STOREVECTOR_B(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
void SDF_VU0__ZEROVECTOR_W(void);
void SetRotateMatrixAxis(f32 aAngle, sdfVector4_t aAxis);
void SetRotateMatrixY_B(f32 aAngle);
void SetRotateMatrixZ(f32 aAngle);
void SetTransparent(void *obj, u32 rgba, f32 alfrgb);
void ToMatrix(void);
billHandle_t *dds3BillboardCopy(billHandle_t *hBillboard);
billHandle_t *dds3BillboardCreate(s32 type, void *pTex, s32 bPos, char *callname);
void dds3BillboardDelete(void **hData);
void dds3BillboardDraw(void **hData);
s32 dds3BillboardGetAnimFrame(billHandle_t *hBillboard);
f32 dds3BillboardGetDirectionRotate(sdfVector4_t pPos, sdfVector4_t pVec);
f32 dds3BillboardGetDirectionScale(sdfVector4_t pPos, sdfVector4_t pVec);
void dds3BillboardSetAnimKey2(billHandle_t **hBillboard, s32 frame);
void dds3BillboardSetPosition(billHandle_t **hBillboard, sdfVector4_t pPos);
void dds3BillboardSetRGBA(billHandle_t **hBillboard, u32 abgr);
void dds3BillboardSetRotate(billHandle_t **hBillboard, f32 rot);
void dds3BillboardSetScale(billHandle_t **hBillboard, f32 x, f32 y);
void *dds3EffectPCPDataGetDataUnityOffSet(void *hData, s32 offset, s32 type);
void dds3EffectPCPData_t__pCopy(dds3EffectPCPData_t *this, u8 **bytedata, s32 *pos);
effPartHandle_t *dds3EffectPartCopy(effPartHandle_t **hEffPartSrc);
effPartHandle_t *dds3EffectPartCreate(u16 type, void *pData);
void dds3EffectPartDelete(effPartHandle_t **hEffPart);
void dds3EffectPartDraw(effPartHandle_t **hEffPart);
dds3ModelHandle_t *dds3EffectPartGetHandle(effPartHandle_t *hEffPart);
void dds3EffectPartModelDelete(void **hData);
void dds3EffectPartModelDraw(void **hData);
void dds3EffectPartSetColor(effPartHandle_t **hEffPart, u32 abgr);
void dds3EffectPartSetPosition(effPartHandle_t **hEffPart, sdfVector4_t pPos);
void dds3EffectPartSetRotateMatrix(effPartHandle_t **hEffPart, sdfMatrix4_t *pMatrix);
dds3FlashPolyList_t *dds3FlashPolyListCreate(u32 face);
void dds3FlashPolyListDraw(dds3FlashPolyList_t **hPoly, s32 count, char *idstr);
u32 dds3GetKernelCount(void);
void *dds3GetProcessData(dds3ProcessID_t **id);
u32 dds3GetRandIntA(u32 aLimit, char *name);
s32 dds3KillProcess(dds3ProcessID_t **id, s32 shutdowntimer);
void dds3PadAct(u32 mode, u8 pow, u32 frame);
void dds3SetProcessData(dds3ProcessID_t **id, void *data);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
dds3TrackPoly_t *dds3TrackPolyCreate(s32 number, s32 face, s32 rec, s32 type);
void dds3TrackPolyDelete(dds3TrackPoly_t **hTrackPoly);
void dds3TrackPolyDraw(dds3TrackPoly_t **hTrackPoly, char *funcname);
void dds3TrackPolySetMode(dds3TrackPoly_t **hTrackPoly, u16 mode);
u32 effBTLModelGetID(nbFormation_t **pFormation);
void effBTLModelGetMarkMatrix2(nbFormation_t **pFormation, u32 mark);
void effBTLModelGetMarkPosition2(nbFormation_t **pFormation, u32 mark);
void effBTLModelGetSphereCenter(nbFormation_t **pFormation);
f32 effBTLPartGetScalePtr(nbFormation_t **pFormation);
s32 effBTLSkillCheckRun(void);
u32 effBTLSkillGetID(void);
nbFormation_t *effBTLSkillGetInvokeFormation(s32 idx);
u32 effBTLSkillGetTargetBit(void);
nbFormation_t *effBTLSkillGetTargetFormation(u32 number);
u32 effColorBlend(u32 abgr0, u32 abgr1, f32 rate);
u32 effColorMultiply(u32 abgr0, u32 abgr1);
effBTL_t *effEveBEDCreate(u8 **pData);
effEveBEDCutHandle_t *effEveBEDCutCreate(effBTL_t *hEveBED, u16 CutNum, effEveBEDParams_t *pParams);
void effEveBEDCutDelete(effEveBEDCutHandle_t *hEveBEDCut);
void effEveBEDCutDraw(effEveBEDCutHandle_t **hEveBEDCut);
void effEveBEDCutSetParams(effEveBEDCutHandle_t **hEveBEDCut, effEveBEDParams_t *pParams);
void effEveBEDDelete(effBTL_t *hEveBED);
effPCPBossBUNSIN_t *effPCPBossBUNSINCreate(effPCPBossBUNSINParam_t *pParam);
void effPCPBossBUNSINDelete(effPCPBossBUNSIN_t *pPCPBossBUNSIN);
void effPCPBossBUNSINDraw(effPCPBossBUNSIN_t **pPCPBossBUNSIN);
effPCPBossBael_t *effPCPBossBaelCreate(effPCPBossBaelParam_t *pParam, void *pPB, void *pPCF);
effPCPBossDengeki_t *effPCPBossDengekiCreate(effPCPBossDengekiParam_t *pParam, void *pBEDData);
effPCPBossKAGU2Attack_t *effPCPBossKAGU2AttackCreate(effPCPBossKAGU2AttackParam_t *pParam, void *pBEDData);
void effPCPBossKAGU2AttackGetSplitPoint(sdfVector4_t ***pPosBuff, sdfVector4_t pPoint1, sdfVector4_t pPoint2, sdfVector4_t pCenter, f32 rand, f32 rotate);
effPCPBossKAGUAttack_t *effPCPBossKAGUAttackCreate(effPCPBossKAGUAttackParam_t *pParam, void *pBEDData);
void effPCPBossKAGUAttackGetSplitPoint(sdfVector4_t ***pPosBuff, sdfVector4_t pPoint1, sdfVector4_t pPoint2, sdfVector4_t pCenter);
effPCPBossKAGUInvoke_t *effPCPBossKAGUInvokeCreate(effPCPBossKAGUInvokeParam_t *pParam);
effPCPBossKAGUThunderbolt_t *effPCPBossKAGUThunderboltCreate(effPCPBossKAGUThunderboltParam_t *pParam, void *pBP, void *pBED);
void effPCPBossKAGUThunderboltDrawSub(effPCPBossKAGUThunderbolt_t *pPCPBossKAGUThunderbolt, sdfVector4_t pConvPos);
effPCPBossMETATOBeam_t *effPCPBossMETATOBeamCreate(effPCPBossMETATOBeamParam_t *pParam);
effPCPBossThunderbolt_t *effPCPBossThunderboltCreate(effPCPBossThunderboltParam_t *pParam);
effPCPCrack_t *effPCPCrack2Create(effPCPCrack2Param_t *pParam, void *pPB);
effPCPCrack_t *effPCPCrackCopy(void **hData, s32 bPos, bool tbldata);
effPCPCrack_t *effPCPCrackCreate(effPCPCrackParam_t *pParam, void *pPB);
void effPCPCrackDelete(void **hData);
void effPCPCrackDraw(void **hData);
void effPCPCrackInit(effPCPCrack_t **pPCPCrack);
void effPCPCrackParam_t__pClone(effPCPCrackParam_t *this, effPCPCrackParam_t **param);
void effPCPCrackSetColor(void **hData, u32 abgr);
void effPCPCrackSetPosition(void **hData, sdfVector4_t pPos);
void effPCPCrackSizeInit(effPCPCrack_t **pPCPCrack, effPCPCrackPartFlash_t **pSize);
effPCPDANTE_Damage_tag *effPCPDANTE_Damage_Create(effPCPDANTE_Damage_Param_t *pParam, void *pBED);
void effPCPDANTE_Damage_Param_t__pClone(effPCPDANTE_Damage_Param_t *this, effPCPDANTE_Damage_Param_t **param);
void effPCPDANTE_ShowTime_AreYouReady_Draw(effPCPDANTE_ShowTime_tag **pPCPShowTime);
void effPCPDANTE_ShowTime_Bingo_Draw(effPCPDANTE_ShowTime_tag **pPCPShowTime);
void effPCPDANTE_ShowTime_ShowTime_Draw(effPCPDANTE_ShowTime_tag **pPCPShowTime);
void effPCPDANTE_Sprite_Draw(s32 x, s32 y, f32 scale, u32 abgr, effPCPDANTE_UV_tag *pUV, sdfTexHandle_t *hTex, s32 type, s32 index);
void effPCPDANTE_Sprite_DrawOff(void);
effPCPDANTE_Thunder_tag *effPCPDANTE_Thunder_Create(effPCPDANTE_Thunder_Param_t *pParam);
void effPCPDANTE_Thunder_Draw(void **hData);
void effPCPDANTE_Thunder_Param_t__pClone(effPCPDANTE_Thunder_Param_t *this, effPCPDANTE_Thunder_Param_t **param);
void effPCPDANTE_Thunder_SetPosition(void **hData, sdfVector4_t pPos);
void effPCPDANTE_Thunder_SetRotateMatrix(void **hData, sdfMatrix4_t *pRot);
effPCPHelperBED_tag *effPCPHelperBEDCopy(void **hData, s32 bPos, bool tbldata);
effPCPHelperBED_tag *effPCPHelperBEDCreate(effPCPHelperBEDParam_t *pParam, void *pPBData, void *pBEDData);
void effPCPHelperBEDDelete(void **hData);
void effPCPHelperBEDDraw(void **hData);
dds3ModelHandle_t *effPCPHelperBEDGetModel(effPCPHelperBED_tag *pHelperBED);
void effPCPHelperBEDSetColor(void **hData, u32 abgr);
void effPCPHelperBEDSetPosition(void **hData, sdfVector4_t pPos);
void effPCPHelperBEDSetScale(void **hData, f32 scale);
effPCPMuzzleFlash_tag *effPCPMuzzleFlashCreate(effPCPMuzzleFlashParam_t *pParam, void *pP2A);
effPCPScreenCrackModel_t *effPCPScreenCrackModelCreate(effPCPScreenCrackModelParam_t *pParam, void *pPB);
effPCP_BED_tag *effPCP_BED_Create(effPCP_BED_Param_t *pParam, void *pBED);
void effPCP_BED_MatrixToQuaternion(sdfMatrix4_t *pMatrix);
effPCP_PBCamera_tag *effPCP_PBCamera_Create(effPCP_PBCamera_Param_t *pParam, void *pPB);
void effPCP_PBCamera_SetPosition(void **hData, sdfVector4_t pPos);
effPCP_ThunderPoly_t *effPCP_ThunderPolyCreate(void **hData, s32 bPos, bool tbldata);
void effPCP_ThunderPolyDelete(void **hData);
void effPCP_ThunderPolyDraw(void **hData);
effPCP_ThunderPolyParam_t *effPCP_ThunderPolyGetParam(effPCP_ThunderPoly_t *pThunderPoly);
effPCP_ThunderPolyList_t *effPCP_ThunderPolyListCreate(void **hData, s32 bPos, bool tbldata);
void effPCP_ThunderPolyListDelete(void **hData);
void effPCP_ThunderPolyListDraw(void **hData);
effPCP_ThunderPolyListParam_t *effPCP_ThunderPolyListGetParam(effPCP_ThunderPolyList_t *pTPolyList);
void effPCP_ThunderPolyListParam_t__Clear(effPCP_ThunderPolyListParam_t *this);
void effPCP_ThunderPolyListSetColor(void **hData, u32 abgr);
void effPCP_ThunderPolySetColor(void **hData, u32 abgr);
void mdlEffectUpdateRot(void *obj, s32 rot);
s32 mdlGetMotionLengthUnity(dds3ModelHandle_t *aHandle);
void mdlGetPosition(dds3ModelHandle_t **aHandle);
void mdlRasterLevel(void *obj, f32 val);
void mdlSetMotionSpeed(dds3ModelHandle_t **aHandle, f32 speed);
void mdlSetPosition(dds3ModelHandle_t **aHandle);
void mdlSetRotate(dds3ModelHandle_t **aHandle);
void mdlSetScale(dds3ModelHandle_t **aHandle);
s32 nbCameraDANTE_KAGIRI_Set(s32 frame);
void nbCameraHelperModelSetSub(dds3ModelHandle_t *hModel, u32 target, u32 eye);
void nbCameraSetState(u16 state);
void nbFormDispOn2(nbFormation_t **form);
nbMainProcessData_t *nbGetMainProcessData(void);
void nbPanelFlashDraw(nbPanelFlashData_t **pFlash, u32 abgrBase);
void nbPanelFlashInit(nbPanelFlashData_t **pFlash, f32 scale_x, f32 scale_y, u32 abgr, u32 abgr_c, s32 addX, s32 addY);
void nbPnl_rsetAlpha(s32 mode);
void nbSetFormPos(nbFormation_t **form, sdfVector4_t pos);
void nbSetUnitMotion(nbFormation_t **form, s32 motion2, s32 mode, f32 ritu);
void pMeshDelete(dds3HermitianTrackPoly_tag **hPoly);
f32 sdfAtan2(f32 aY, f32 aX);
sdfMat_t *sdfMatNew(void);
void sdfMatSetConstant(sdfMat_t *aMat, f32 aRatio);
s32 sdfModelGetMarkPosCountUnity(sdfModelRootNode_t *aRoot);
s32 sdfModelGetMarkPosMatrixUnity(sdfModelRootNode_t *aRoot, s32 aId);
s32 sdfModelGetMarkPosUnity(sdfModelRootNode_t *aRoot, s32 aId);
f32 sdfSqrt(f32 aValue);

// 0x11dd130
u32 DDS3EFFECT_RGBA(u32 r, u32 g, u32 b, u32 a) {
  return r | (g << 8) | (b << 16) | (a << 24);
}

// 0x11dd0c0
sdfTexHandle_t *dds3GetRenderTexture(void) {
  return 0;
}

// 0x11ddcb0
effPCPBossBUNSIN2_t *effPCPBossBUNSIN2Create(effPCPBossBUNSIN2Param_t *pParam) {
  u64 *v3;
  effPCPBossBUNSINParam_t_o *v4;
  effPCPBossBUNSINParam_t_o *v6;
  effPCPBossBUNSINParam_t_o *v8;

  v3 = Allocate(effPCPBossBUNSIN2_t);
  effPCPBossBUNSIN2_t___ctor(v3);
  v3[2] = pParam;
  v3[3] = 0;
  v4 = Allocate(effPCPBossBUNSINParam_t);
  effPCPBossBUNSINParam_t___ctor(v4);
  v4->pStartForm = *(v3[2] + 16);
  v4->pEndForm = *(v3[2] + 24);
  v3[4] = effPCPBossBUNSINCreate(v4);
  v6 = Allocate(effPCPBossBUNSINParam_t);
  effPCPBossBUNSINParam_t___ctor(v6);
  v6->pStartForm = *(v3[2] + 16);
  v6->pEndForm = *(v3[2] + 32);
  v3[5] = effPCPBossBUNSINCreate(v6);
  v8 = Allocate(effPCPBossBUNSINParam_t);
  effPCPBossBUNSINParam_t___ctor(v8);
  v8->pStartForm = *(v3[2] + 24);
  v8->pEndForm = *(v3[2] + 40);
  v3[6] = effPCPBossBUNSINCreate(v8);
  return v3;
}

// 0x11dddf0
void effPCPBossBUNSIN2Delete(effPCPBossBUNSIN2_t *pPCPBossBUNSIN2) {
  effPCPBossBUNSIN_t_o *pCut2_2;

  pCut2_2 = pPCPBossBUNSIN2->pCut2_2;
  effPCPBossBUNSINDelete(pCut2_2);
  effPCPBossBUNSINDelete(pPCPBossBUNSIN2->pCut2_1);
  effPCPBossBUNSINDelete(pPCPBossBUNSIN2->pCut1);
}

// 0x11dde70
void effPCPBossBUNSIN2Draw(effPCPBossBUNSIN2_t *pPCPBossBUNSIN2) {
  u32 process;

  else
  {
    process = pPCPBossBUNSIN2->process;
    if (process != 1)
      goto LABEL_6;
  }
  if (pPCPBossBUNSIN2->frame <= 24)
  {
    effPCPBossBUNSINDraw(&pPCPBossBUNSIN2->pCut1);
  }
  effPCPBossBUNSINDraw(&pPCPBossBUNSIN2->pCut2_1);
  effPCPBossBUNSINDraw(&pPCPBossBUNSIN2->pCut2_2);
LABEL_22:
  ++pPCPBossBUNSIN2->frame;
}

// 0x11ddfa0
s32 effPCPBossBUNSIN2GetLength(void) {
    return 48;
  return 48;
}

// 0x11dd610
effPCPBossBUNSIN_t *effPCPBossBUNSINCreate(effPCPBossBUNSINParam_t *pParam) {
  u64 *v3;
  struct UnityEngine_Vector4_o *p_pos;
  s64 v5;
  u64 *v6;
  u64 v9;
  u64 v11;
  u64 v13;

  v3 = Allocate(effPCPBossBUNSIN_t);
  effPCPBossBUNSIN_t___ctor(v3);
  v3[6] = pParam;
  v3[8] = 0;
  p_pos = &pParam->pStartForm->pos;
  sub_854710(p_pos, 0);
  sub_854930((v3 + 2), 0);
  sub_854710(p_pos, 1u);
  sub_854930((v3 + 2), 1u);
  sub_854710(p_pos, 2u);
  sub_854930((v3 + 2), 2u);
  sub_854930((v3 + 2), 3u);
  v5 = *(v3[6] + 24) + 48LL;
  sub_854710(v5, 0);
  sub_854930((v3 + 4), 0);
  sub_854710(v5, 1u);
  sub_854930((v3 + 4), 1u);
  sub_854710(v5, 2u);
  sub_854930((v3 + 4), 2u);
  sub_854930((v3 + 4), 3u);
  v6 = NewSpecific(UnityEngine_Vector4, 4u);
  v3[7] = v6;
  v6[4] = 0;
  v6[5] = 0;
  v9 = v3[7];
  *(v9 + 48) = 0;
  *(v9 + 56) = 0;
  v11 = v3[7];
  *(v11 + 64) = 0;
  *(v11 + 72) = 0;
  v13 = v3[7];
  *(v13 + 80) = 0;
  *(v13 + 88) = 0;
  v3[9] = 0;
  effPCPBossONGY_PolyParm->attr = 0x4000;
  effPCPBossONGY_PolyParm->faceIndex = effPCPBossONGY_FaceIndex;
  effPCPBossONGY_PolyParm->color = -2139062144;
  return v3;
}

// 0x11dd890
void effPCPBossBUNSINDelete(effPCPBossBUNSIN_t *pPCPBossBUNSIN) {
  struct XRD773Unity_CommonMesh_array *pMesh;
  il2cpp_array_size_t max_length;
  s64 v5;
  u64 v6;
  UnityEngine_Object_o *v8;
  struct XRD773Unity_CommonMesh_array *v9;
  UnityEngine_Object_o *gameObject;
  struct XRD773Unity_CommonMesh_array *v13;
  s64 v15;

  pMesh = pPCPBossBUNSIN->pMesh;
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
          v9 = pPCPBossBUNSIN->pMesh;
          gameObject = get_gameObject(*(&v9->obj.klass + v5), 0);
          Destroy_27360000(gameObject);
          v13 = pPCPBossBUNSIN->pMesh;
          *(&v13->obj.klass + v5) = 0;
        }
        pMesh = pPCPBossBUNSIN->pMesh;
        LODWORD(max_length) = pMesh->max_length;
        v15 = v5 - 3;
        ++v5;
      }
      while (v15 < max_length);
    }
  }
  pPCPBossBUNSIN->pMesh = 0;
}

// 0x11dda20
void effPCPBossBUNSINDraw(effPCPBossBUNSIN_t **pPCPBossBUNSIN) {
  effPCPBossBUNSIN_t_o *v3;
  s32 frame;
  nbFormation_t_o **p_pStartForm;
  f32 v6;
  f32 v8;
  nbFormation_t_o **p_pEndForm;
  s64 v10;
  f32 w;
  f32 z;
  UnityEngine_GameObject_o *modelobj;
  f32 v15;
  nbFormation_t_o **v16;
  s64 v17;
  f32 v18;
  f32 v19;
  UnityEngine_Vector4_o v21;
  UnityEngine_Vector4_o v22;
  UnityEngine_Vector4_o v23;

  *&v21.x = 0;
  *&v21.z = 0;
  v3 = *pPCPBossBUNSIN;
  frame = (*pPCPBossBUNSIN)->frame;
  if (frame < 1)
    goto LABEL_9;
  p_pStartForm = &v3->param->pStartForm;
  nbFormDispOn2(p_pStartForm);
  nbFormDispOn2(&(*pPCPBossBUNSIN)->param->pEndForm, 0);
  v3 = *pPCPBossBUNSIN;
  frame = (*pPCPBossBUNSIN)->frame;
  if (frame <= 9)
LABEL_9:
    v6 = frame / 10.0;
  else
    v6 = 1.0;
  SDF_VU0__LOADVECTOR(v3->pos_s);
  SDF_VU0__LOADVECTOR_B((*pPCPBossBUNSIN)->pos_e, 0);
  SDF_VU0__INTERPOLATE(v6);
  SDF_VU0__STOREVECTOR(&v21);
  if (frame >= 24)
  {
    p_pEndForm = &(*pPCPBossBUNSIN)->param->pEndForm;
    v10 = *&v21.x;
    z = v21.z;
    w = v21.w;
    *&v22.x = v10;
    v22.z = z;
    v22.w = w;
    nbSetFormPos(p_pEndForm, v22);
    modelobj = (*pPCPBossBUNSIN)->param->pEndForm->modelobj;
    v15 = 0.0;
  }
  else
  {
    if (frame >= 10)
      v8 = (((frame - 10) / -14.0) + 1.0) * 0.5;
    else
      v8 = 0.5;
    v16 = &(*pPCPBossBUNSIN)->param->pEndForm;
    v17 = *&v21.x;
    v19 = v21.z;
    v18 = v21.w;
    *&v23.x = v17;
    v23.z = v19;
    v23.w = v18;
    nbSetFormPos(v16, v23);
    modelobj = (*pPCPBossBUNSIN)->param->pEndForm->modelobj;
    v15 = v8;
  }
  mdlRasterLevel(modelobj, v15);
  ++(*pPCPBossBUNSIN)->frame;
}

// 0x11ddca0
s32 effPCPBossBUNSINGetLength(void) {
  return 24;
}

// 0x11e1840
effPCPBossBael_t *effPCPBossBaelCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 *v10;
  u64 v13[3];

  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossBael_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBossBael_t, v13);
      if ((v13[0] & 1) != 0)
        v8 = v13[2];
      else
        v8 = v13 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = Allocate(effPCPBossBael_t);
  effPCPBossBael_t___ctor(v10);
  v10[4] = v5[2].klass;
  v10[5] = 0x8080808000000000LL;
  v10[6] = dds3EffectPartCopy(&v5[3], 0, 0);
  v10[7] = dds3EffectPartCopy(&v5[3].monitor, 0, 0);
  return v10;
}

// 0x11e1480
effPCPBossBael_t *effPCPBossBaelCreate(effPCPBossBaelParam_t *pParam, void *pPB, void *pPCF) {
  u64 *v7;

  v7 = Allocate(effPCPBossBael_t);
  effPCPBossBael_t___ctor(v7);
  v7[4] = pParam;
  v7[5] = 0x8080808000000000LL;
  v7[6] = dds3EffectPartCreate(3u, pPB, 0, 0);
  v7[7] = dds3EffectPartCreate(6u, pPCF, 0, 0);
  return v7;
}

// 0x11e1550
effPCPBossBael_t *effPCPBossBaelCreatePCF(void **hData, s32 bPos, bool tbldata) {
  dds3EffectPCPData_t_o *v6;
  Il2CppObject *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  struct dds3EffectPCPData_Part_t_array *pcpData;
  Il2CppObject *v14;
  u32 offset;
  Il2CppObject *DataUnityOffSet;
  struct dds3EffectPCPData_Part_t_array *v19;
  Il2CppObject *v20;
  effPCPBossBaelParam_t_o *v21;
  u32 v23;
  Il2CppObject *EffPCPAgiFireballPart;
  struct dds3EffectPCPData_Part_t_array *v25;
  Il2CppObject *v26;
  Il2CppObject *v27;
  Il2CppObject *v31;
  effPCPBossBaelParam_t_c *klass;
  s64 typeHierarchyDepth;
  char *v34;
  s64 *v35;
  s32 pos;
  u64 v38[2];
  char *v39;

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v7->klass->_1.element_class, v8, v38);
      if ((v38[0] & 1) != 0)
        v10 = v39;
      else
        v10 = v38 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v6, Interface, &pos);
  pcpData = v6->pcpData;
  v14 = *hData;
  offset = pcpData->m_Items[0]->offset;
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 38);
  v19 = v6->pcpData;
  v20 = *hData;
  v21 = DataUnityOffSet;
  v23 = v19->m_Items[1]->offset;
  EffPCPAgiFireballPart = GetEffPCPAgiFireballPart(v20, v23 + bPos);
  v25 = v6->pcpData;
  v26 = *hData;
  v27 = EffPCPAgiFireballPart;
  v31 = GetEffPCPAgiFireballPart(v26, v25->m_Items[2]->offset + bPos);
  else if (!v21)
  {
    return effPCPBossBaelCreate(v21, v27, v31);
  }
  klass = v21->klass;
  if (v21->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossBaelParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBossBaelParam_t, v38);
    if ((v38[0] & 1) != 0)
      v34 = v39;
    else
      v34 = v38 + 1;
    v35 = sub_8C4940(v34);
  }
  return effPCPBossBaelCreate(v21, v27, v31);
}

// 0x11e19b0
void effPCPBossBaelDelete(void **hData) {
  effPartHandle_t_o **v3;
  effPartHandle_t_o *v4;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v8[3];

  v3 = *hData;
  if (*hData)
  {
    v4 = *v3;
    if (LOBYTE((*v3)[9].klass) < typeHierarchyDepth
      || *(v4[6].monitor + typeHierarchyDepth - 1) != effPCPBossBael_t)
    {
      sub_8FC2C0(v4[2].klass, effPCPBossBael_t, v8);
      if ((v8[0] & 1) != 0)
        v6 = v8[2];
      else
        v6 = v8 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  dds3EffectPartDelete(v3 + 7);
  dds3EffectPartDelete(v3 + 6);
}

// 0x11e1ae0
void effPCPBossBaelDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  f32 *v12;
  f32 v13;
  f32 v14;
  f32 v15;
  f32 v16;
  UnityEngine_Matrix4x4_o v25;
  UnityEngine_Matrix4x4_o v26;
  UnityEngine_Matrix4x4_o v27;
  UnityEngine_Matrix4x4_o aMatrix;
  nbFormation_t_o *pFormation;
  u64 v30[2];
  UnityEngine_Vector4_o v31;
  UnityEngine_Vector4_o v32;
  UnityEngine_Vector4_o v33;

  v30[0] = 0;
  v30[1] = 0;
  memset(&aMatrix, 0, sizeof(aMatrix));
  pFormation = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossBael_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBossBael_t, &v27);
      if ((LOBYTE(v27.m00) & 1) != 0)
        v6 = *&v27.m01;
      else
        v6 = &v27.m00 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  sub_854690(v30, 0.0, 1.0, 0.0, 0.0);
  pFormation = 0;
  get_identity(&v27, 0);
  aMatrix = v27;
  if (!effBTLSkillCheckRun())
    goto LABEL_29;
LABEL_16:
  if (!LODWORD(v3[2].monitor))
  {
    pFormation = effBTLSkillGetTargetFormation(0);
    effBTLModelGetSphereCenter(&pFormation);
    SDF_VU0__STOREVECTOR(&v3[1]);
  }
  v12 = v3[2].klass;
  v13 = v12[4];
  v14 = v12[5];
  v15 = v12[6];
  v16 = v12[7];
  v32 = v3[1];
  v33.x = v13;
  v33.y = v14;
  v33.z = v15;
  v33.w = v16;
  *&v31.x = 0;
  LookAtMatrix(v32, v33, v31);
  ReverseMatrix();
  SDF_VU0__RESET_ROW3();
  SDF_VU0__STOREMATRIX(&aMatrix);
LABEL_30:
  v27 = aMatrix;
  v26 = v27;
  dds3EffectPartSetRotateMatrix(&v3[3], &v26);
  v25 = aMatrix;
  dds3EffectPartSetRotateMatrix(&v3[3].monitor, &v25);
  dds3EffectPartSetPosition(&v3[3], *&v3[2].klass->_1.name);
  dds3EffectPartSetPosition(&v3[3].monitor, *&v3[2].klass->_1.name);
  dds3EffectPartSetColor(&v3[3], HIDWORD(v3[2].monitor), 0);
  dds3EffectPartSetColor(&v3[3].monitor, HIDWORD(v3[2].monitor), 0);
  dds3EffectPartDraw(&v3[3]);
  dds3EffectPartDraw(&v3[3].monitor);
  ++LODWORD(v3[2].monitor);
}

// 0x11e2060
void effPCPBossBaelSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossBael_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBossBael_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[2].monitor) = abgr;
}

// 0x11e1f40
void effPCPBossBaelSetPosition(void **hData, sdfVector4_t pPos) {
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
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossBael_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBossBael_t, v12);
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
  SDF_VU0__COPYVECTOR(&(*hData)[2].klass->_1.name, v13, 0);
}

// 0x11e2880
effPCPBossDengeki_t *effPCPBossDengekiCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 *v10;
  effPCPBossDengekiParam_t_o *v13;
  effPCPBossDengeki_t_o *v14;
  effPCPBossDengeki_t_o *v15;
  effBTL_t_o *hBED;
  u64 v19[3];

  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossDengeki_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBossDengeki_t, v19);
      if ((v19[0] & 1) != 0)
        v8 = v19[2];
      else
        v8 = v19 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = Allocate(effEveBEDParams_t);
  effEveBEDParams_t___ctor(v10);
  v13 = v5[1].klass;
  v14 = effPCPBossDengekiCreate(v13, 0);
  v14->hBED = v5[2].klass;
  v15 = v14;
  sub_854930((v10 + 2), 0);
  sub_854930((v10 + 2), 1u);
  sub_854930((v10 + 2), 2u);
  sub_854930((v10 + 2), 3u);
  sub_854930((v10 + 4), 0);
  sub_854930((v10 + 4), 1u);
  sub_854930((v10 + 4), 2u);
  sub_854930((v10 + 4), 3u);
  v10[6] = 0x42C8000042C80000LL;
  *(v10 + 14) = LODWORD(v15->param->scale);
  *(v10 + 15) = -2139062144;
  hBED = v15->hBED;
  v15->hBEDCut = effEveBEDCutCreate(hBED, 2u, v10);
  return v15;
}

// 0x11e2150
effPCPBossDengeki_t *effPCPBossDengekiCreate(effPCPBossDengekiParam_t *pParam, void *pBEDData) {
  effPCP_ThunderPolyListParam_t_o *v5;
  u64 *v6;
  u64 *v7;
  Il2CppClass *v9;
  s64 *Interface;
  char *v11;
  s64 *v12;
  effBTL_t_o *v13;
  effEveBEDCutHandle_t_o *v14;
  u64 *v15;
  s64 *v16;
  s64 *v17;
  u64 v19;
  s64 *v20;
  s64 *v21;
  u64 v23;
  s64 *v24;
  s64 *v25;
  u64 v27;
  s64 *v28;
  s64 *v29;
  Il2CppObject *v36[3];
  Il2CppObject *hData;

  hData = 0;
  v5 = Allocate(effPCP_ThunderPolyListParam_t);
  effPCP_ThunderPolyListParam_t___ctor(v5);
  effPCP_ThunderPolyListParam_t__Clear(v5);
  v6 = Allocate(effEveBEDParams_t);
  effEveBEDParams_t___ctor(v6);
  v7 = Allocate(effPCPBossDengeki_t);
  effPCPBossDengeki_t___ctor(v7);
  v7[2] = pParam;
  v7[6] = 0x8080808000000000LL;
  if (pBEDData)
  {
    sub_854930((v6 + 2), 0);
    sub_854930((v6 + 2), 1u);
    sub_854930((v6 + 2), 2u);
    sub_854930((v6 + 2), 3u);
    sub_854930((v6 + 4), 0);
    sub_854930((v6 + 4), 1u);
    sub_854930((v6 + 4), 2u);
    sub_854930((v6 + 4), 3u);
    v6[6] = 0x42C8000042C80000LL;
    *(v6 + 14) = *(v7[2] + 24);
    *(v6 + 15) = -2139062144;
    Interface = QueryInterface(pBEDData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pBEDData->klass->_1.element_class, v9, v36);
      if ((v36[0] & 1) != 0)
        v11 = v36[2];
      else
        v11 = v36 + 1;
      v12 = sub_8C4940(v11);
    }
    v13 = effEveBEDCreate(Interface);
    v7[4] = v13;
    v14 = effEveBEDCutCreate(v13, 2u, v6);
    pParam = v7[2];
    v7[5] = v14;
  }
  v5->TPParam = pParam->TPParam;
  v5->point = 4;
  v15 = NewSpecific(effPCP_ThunderPolyList_t, 4u);
  v7[3] = v15;
  hData = v5;
  v16 = effPCP_ThunderPolyListCreate(&hData, 0, 1);
  v17 = v16;
  v15[4] = v17;
  hData = v5;
  v19 = v7[3];
  v20 = effPCP_ThunderPolyListCreate(&hData, 0, 1);
  v21 = v20;
  *(v19 + 40) = v21;
  hData = v5;
  v23 = v7[3];
  v24 = effPCP_ThunderPolyListCreate(&hData, 0, 1);
  v25 = v24;
  *(v23 + 48) = v25;
  hData = v5;
  v27 = v7[3];
  v28 = effPCP_ThunderPolyListCreate(&hData, 0, 1);
  v29 = v28;
  *(v27 + 56) = v29;
  return v7;
}

// 0x11e25d0
effPCPBossDengeki_t *effPCPBossDengekiCreatePCF(void **hData, s32 bPos, bool tbldata) {
  dds3EffectPCPData_t_o *v6;
  Il2CppObject *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  struct dds3EffectPCPData_Part_t_array *pcpData;
  Il2CppObject *v14;
  u32 offset;
  Il2CppObject *DataUnityOffSet;
  struct dds3EffectPCPData_Part_t_array *v19;
  Il2CppObject *v20;
  effPCPBossDengekiParam_t_o *v21;
  u32 v23;
  Il2CppObject *EffPCPAgiFireballPart;
  effPCPBossDengekiParam_t_c *klass;
  s64 typeHierarchyDepth;
  char *v29;
  s64 *v30;
  u64 v32[2];
  char *v33;
  s32 pos;

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v7->klass->_1.element_class, v8, v32);
      if ((v32[0] & 1) != 0)
        v10 = v33;
      else
        v10 = v32 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v6, Interface, &pos);
  pcpData = v6->pcpData;
  v14 = *hData;
  offset = pcpData->m_Items[0]->offset;
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 39);
  v19 = v6->pcpData;
  v20 = *hData;
  v21 = DataUnityOffSet;
  v23 = v19->m_Items[1]->offset;
  EffPCPAgiFireballPart = GetEffPCPAgiFireballPart(v20, v23 + bPos);
  else if (!v21)
  {
    return effPCPBossDengekiCreate(v21, EffPCPAgiFireballPart);
  }
  klass = v21->klass;
  if (v21->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossDengekiParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBossDengekiParam_t, v32);
    if ((v32[0] & 1) != 0)
      v29 = v33;
    else
      v29 = v32 + 1;
    v30 = sub_8C4940(v29);
  }
  return effPCPBossDengekiCreate(v21, EffPCPAgiFireballPart);
}

// 0x11e2ae0
void effPCPBossDengekiDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  effEveBEDCutHandle_t_o *monitor;
  effBTL_t_o *v10;
  void *v11;
  void *v12;
  u32 *v14;
  void *v16;
  Il2CppObject *v19[3];
  Il2CppObject *hDataa;

  hDataa = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossDengeki_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBossDengeki_t, v19);
      if ((v19[0] & 1) != 0)
        v6 = v19[2];
      else
        v6 = v19 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  monitor = v3[2].monitor;
  effEveBEDCutDelete(monitor);
  v10 = v3[2].klass;
  if (v10->CutCount)
  {
    v11 = v3[1].monitor;
    if (*(v11 + 6))
      goto LABEL_15;
LABEL_26:
  }
  effEveBEDDelete(v10);
  v11 = v3[1].monitor;
  if (!*(v11 + 6))
    goto LABEL_26;
LABEL_15:
  hDataa = *(v11 + 4);
  effPCP_ThunderPolyListDelete(&hDataa);
  v12 = v3[1].monitor;
  hDataa = *(v12 + 5);
  effPCP_ThunderPolyListDelete(&hDataa);
  v14 = v3[1].monitor;
  hDataa = *(v14 + 6);
  effPCP_ThunderPolyListDelete(&hDataa);
  v16 = v3[1].monitor;
  hDataa = *(v16 + 7);
  effPCP_ThunderPolyListDelete(&hDataa);
}

// 0x11e2d10
void effPCPBossDengekiDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  nbMainProcessData_t_o *MainProcessData;
  u64 v74;
  struct nbFormation_t_array *form;
  u32 ID;
  Il2CppObject *v79;
  UnityEngine_Vector4_o v80;
  UnityEngine_Vector4_o v81;
  UnityEngine_Vector4_o v82;
  UnityEngine_Vector4_o v83;
  UnityEngine_Vector4_o v84;
  UnityEngine_Vector4_o v85;
  UnityEngine_Vector4_o v86;
  UnityEngine_Vector4_o v87;
  UnityEngine_Vector4_o v88;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *v90[3];
  nbFormation_t_o *pFormation;

  pFormation = 0;
  *&p.x = 0;
  *&p.z = 0;
  v79 = 0;
  *&v88.x = 0;
  *&v88.z = 0;
  *&v87.x = 0;
  *&v87.z = 0;
  *&v86.x = 0;
  *&v86.z = 0;
  *&v85.x = 0;
  *&v85.z = 0;
  *&v84.x = 0;
  *&v84.z = 0;
  *&v83.x = 0;
  *&v83.z = 0;
  *&v82.x = 0;
  *&v82.z = 0;
  *&v81.x = 0;
  *&v81.z = 0;
  *&v80.x = 0;
  *&v80.z = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossDengeki_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBossDengeki_t, v90);
      if ((v90[0] & 1) != 0)
        v6 = v90[2];
      else
        v6 = v90 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  pFormation = 0;
  v8 = Allocate(effEveBEDParams_t);
  effEveBEDParams_t___ctor(v8);
  *&p.x = 0;
  *&p.z = 0;
  *&v88.x = 0;
  *&v88.z = 0;
  *&v87.x = 0;
  *&v87.z = 0;
  *&v86.x = 0;
  *&v86.z = 0;
  *&v85.x = 0;
  *&v85.z = 0;
  *&v84.x = 0;
  *&v84.z = 0;
  *&v83.x = 0;
  *&v83.z = 0;
  *&v82.x = 0;
  *&v82.z = 0;
  *&v81.x = 0;
  *&v81.z = 0;
  *&v80.x = 0;
  *&v80.z = 0;
  else if (effBTLSkillCheckRun())
  {
    goto LABEL_13;
  }
  MainProcessData = nbGetMainProcessData();
  v74 = 0;
  while (1)
  {
    form = MainProcessData->form;
    pFormation = form->m_Items[v74];
    if ((~pFormation->stat & 3) == 0)
    {
      ID = effBTLModelGetID(&pFormation);
      if (ID == 259 || ID == 292)
        break;
    }
    if (v74++ > 0x1E)
      return;
  }
  if (pFormation)
    goto LABEL_17;
}

// 0x11e3bd0
void effPCPBossDengekiSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossDengeki_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBossDengeki_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[3].klass) = abgr;
}

// 0x11e8960
effPCPBossKAGU2Attack_t *effPCPBossKAGU2AttackCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 *v10;
  effPCPBossKAGU2AttackParam_t_o *v13;
  effPCPBossKAGU2Attack_t_o *v14;
  effPCPBossKAGU2Attack_t_o *v15;
  effBTL_t_o *hBED;
  u64 v19[3];

  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossKAGU2Attack_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBossKAGU2Attack_t, v19);
      if ((v19[0] & 1) != 0)
        v8 = v19[2];
      else
        v8 = v19 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = Allocate(effEveBEDParams_t);
  effEveBEDParams_t___ctor(v10);
  v13 = v5[1].klass;
  v14 = effPCPBossKAGU2AttackCreate(v13, 0);
  v14->hBED = v5[2].klass;
  v15 = v14;
  sub_854930((v10 + 2), 0);
  sub_854930((v10 + 2), 1u);
  sub_854930((v10 + 2), 2u);
  sub_854930((v10 + 2), 3u);
  sub_854930((v10 + 4), 0);
  sub_854930((v10 + 4), 1u);
  sub_854930((v10 + 4), 2u);
  sub_854930((v10 + 4), 3u);
  v10[6] = 0x42C8000042C80000LL;
  *(v10 + 14) = LODWORD(v15->param->scale);
  *(v10 + 15) = -2139062144;
  hBED = v15->hBED;
  v15->hBEDCut = effEveBEDCutCreate(hBED, 2u, v10);
  return v15;
}

// 0x11e8380
effPCPBossKAGU2Attack_t *effPCPBossKAGU2AttackCreate(effPCPBossKAGU2AttackParam_t *pParam, void *pBEDData) {
  effPCP_ThunderPolyListParam_t_o *v5;
  u64 *v6;
  u64 *v7;
  Il2CppClass *v9;
  s64 *Interface;
  char *v11;
  s64 *v12;
  effBTL_t_o *v13;
  effEveBEDCutHandle_t_o *v14;
  struct effPCP_ThunderPolyParam_t_o *TPParam;
  s32 v16;
  u64 v17;
  u64 v18;
  u32 *v20;
  s64 *v21;
  s64 *v22;
  u32 *v24;
  Il2CppObject *v26[3];
  Il2CppObject *hData;

  hData = 0;
  v5 = Allocate(effPCP_ThunderPolyListParam_t);
  effPCP_ThunderPolyListParam_t___ctor(v5);
  effPCP_ThunderPolyListParam_t__Clear(v5);
  v6 = Allocate(effEveBEDParams_t);
  effEveBEDParams_t___ctor(v6);
  v7 = Allocate(effPCPBossKAGU2Attack_t);
  effPCPBossKAGU2Attack_t___ctor(v7);
  v7[2] = pParam;
  v7[6] = 0x8080808000000000LL;
  if (pBEDData)
  {
    sub_854930((v6 + 2), 0);
    sub_854930((v6 + 2), 1u);
    sub_854930((v6 + 2), 2u);
    sub_854930((v6 + 2), 3u);
    sub_854930((v6 + 4), 0);
    sub_854930((v6 + 4), 1u);
    sub_854930((v6 + 4), 2u);
    sub_854930((v6 + 4), 3u);
    v6[6] = 0x42C8000042C80000LL;
    *(v6 + 14) = *(v7[2] + 24);
    *(v6 + 15) = -2139062144;
    Interface = QueryInterface(pBEDData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pBEDData->klass->_1.element_class, v9, v26);
      if ((v26[0] & 1) != 0)
        v11 = v26[2];
      else
        v11 = v26 + 1;
      v12 = sub_8C4940(v11);
    }
    v13 = effEveBEDCreate(Interface);
    v7[4] = v13;
    v14 = effEveBEDCutCreate(v13, 2u, v6);
    pParam = v7[2];
    v7[5] = v14;
  }
  TPParam = pParam->TPParam;
  v5->TPParam = TPParam;
  TPParam->number = 1;
  v5->point = 5;
  v16 = *(v7[2] + 40);
  if (v16)
  {
    v17 = 0;
    v18 = (4 * v16);
    do
    {
      hData = v5;
      v20 = v7[3];
      v21 = effPCP_ThunderPolyListCreate(&hData, 0, 1);
      v22 = v21;
      v24 = &v20[2 * v17++];
      *(v24 + 4) = v22;
    }
    while (v17 < v18);
  }
  return v7;
}

// 0x11e86b0
effPCPBossKAGU2Attack_t *effPCPBossKAGU2AttackCreatePCF(void **hData, s32 bPos, bool tbldata) {
  dds3EffectPCPData_t_o *v6;
  Il2CppObject *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  struct dds3EffectPCPData_Part_t_array *pcpData;
  Il2CppObject *v14;
  u32 offset;
  Il2CppObject *DataUnityOffSet;
  struct dds3EffectPCPData_Part_t_array *v19;
  Il2CppObject *v20;
  effPCPBossKAGU2AttackParam_t_o *v21;
  u32 v23;
  Il2CppObject *EffPCPAgiFireballPart;
  effPCPBossKAGU2AttackParam_t_c *klass;
  s64 typeHierarchyDepth;
  char *v29;
  s64 *v30;
  u64 v32[2];
  char *v33;
  s32 pos;

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v7->klass->_1.element_class, v8, v32);
      if ((v32[0] & 1) != 0)
        v10 = v33;
      else
        v10 = v32 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v6, Interface, &pos);
  pcpData = v6->pcpData;
  v14 = *hData;
  offset = pcpData->m_Items[0]->offset;
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 44);
  v19 = v6->pcpData;
  v20 = *hData;
  v21 = DataUnityOffSet;
  v23 = v19->m_Items[1]->offset;
  EffPCPAgiFireballPart = GetEffPCPAgiFireballPart(v20, v23 + bPos);
  else if (!v21)
  {
    return effPCPBossKAGU2AttackCreate(v21, EffPCPAgiFireballPart);
  }
  klass = v21->klass;
  if (v21->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossKAGU2AttackParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBossKAGU2AttackParam_t, v32);
    if ((v32[0] & 1) != 0)
      v29 = v33;
    else
      v29 = v32 + 1;
    v30 = sub_8C4940(v29);
  }
  return effPCPBossKAGU2AttackCreate(v21, EffPCPAgiFireballPart);
}

// 0x11e8bc0
void effPCPBossKAGU2AttackDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  effEveBEDCutHandle_t_o *monitor;
  effBTL_t_o *v10;
  u32 bits;
  u64 v12;
  u64 v13;
  u64 *v14;
  Il2CppObject *v16;
  u64 v17[3];

  v16 = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossKAGU2Attack_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBossKAGU2Attack_t, v17);
      if ((v17[0] & 1) != 0)
        v6 = v17[2];
      else
        v6 = v17 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  monitor = v3[2].monitor;
  effEveBEDCutDelete(monitor);
  v10 = v3[2].klass;
  if (!v10->CutCount)
  {
    effEveBEDDelete(v10);
  }
  bits = v3[1].klass->_1.byval_arg.bits;
  if (bits)
  {
    v12 = 0;
    v13 = 4 * bits;
    do
    {
      v14 = v3[1].monitor;
      v16 = v14[v12 + 4];
      effPCP_ThunderPolyListDelete(&v16);
      ++v12;
    }
    while (v12 < v13);
  }
}

// 0x11e9250
void effPCPBossKAGU2AttackDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  u64 *v10;
  Il2CppClass *v12;
  s32 namespaze_high;
  s32 v14;
  bool v15;
  s32 v16;
  s32 data_high;
  s32 data;
  f32 v19;
  f32 v20;
  nbMainProcessData_t_o *MainProcessData;
  u64 v23;
  struct nbFormation_t_array *form;
  u32 ID;
  f32 v28;
  u32 v29;
  u64 v31;
  UnityEngine_Vector4_o *v32;
  u32 bits;
  u64 v40;
  effPCP_ThunderPolyList_t_o **monitor;
  effPCP_ThunderPolyListParam_t_Fields *p_fields;
  f32 v46;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  f32 rand;
  s64 v54;
  u64 *v55;
  effPCP_ThunderPolyList_t_o **v57;
  effPCP_ThunderPolyListParam_t_o *Param;
  u64 *v62;
  effPCP_ThunderPolyList_t_o **v64;
  effPCP_ThunderPolyListParam_t_o *v66;
  u64 *v69;
  effPCP_ThunderPolyList_t_o **v71;
  effPCP_ThunderPolyListParam_t_o *v73;
  u64 *v76;
  u64 *v79;
  Il2CppObject *hDataa;
  UnityEngine_Vector4_o p;
  s64 v86;
  s64 v87;
  nbFormation_t_o *pFormation;
  u64 v89[4];
  UnityEngine_Vector4_o v90;
  UnityEngine_Vector4_o v91;
  UnityEngine_Vector4_o v92;
  UnityEngine_Vector4_o v93;
  UnityEngine_Vector4_o v94;
  UnityEngine_Vector4_o v95;

  v87 = 0;
  pFormation = 0;
  *&p.z = 0;
  v86 = 0;
  hDataa = 0;
  *&p.x = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossKAGU2Attack_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBossKAGU2Attack_t, v89);
      if ((v89[0] & 1) != 0)
        v6 = v89[2];
      else
        v6 = v89 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  pFormation = 0;
  v8 = Allocate(effEveBEDParams_t);
  effEveBEDParams_t___ctor(v8);
  v86 = 0;
  v87 = 0;
  v10 = NewSpecific(UnityEngine_Vector4, 6u);
  *&p.x = 0;
  *&p.z = 0;
  else if (effBTLSkillCheckRun())
  {
    goto LABEL_13;
  }
  MainProcessData = nbGetMainProcessData();
  v23 = 0;
  while (1)
  {
    form = MainProcessData->form;
    pFormation = form->m_Items[v23];
    if ((~pFormation->stat & 3) == 0)
    {
      ID = effBTLModelGetID(&pFormation);
      if (ID == 264 || ID == 293)
        break;
    }
    if (v23++ > 0x1E)
      return;
  }
  if (pFormation)
  {
LABEL_17:
    v12 = v3[1].klass;
    namespaze_high = HIDWORD(v12->_1.namespaze);
    v14 = v3[3].klass;
    v15 = __OFSUB__(namespaze_high, v14);
    v16 = namespaze_high - v14;
    if ((v16 < 0) ^ v15 | (v16 == 0))
    {
LABEL_91:
      LODWORD(v3[3].klass) = v14 + 1;
      return;
    }
    data = v12->_1.byval_arg.data;
    data_high = HIDWORD(v12->_1.byval_arg.data);
    v79 = v8;
    if (v14 < data && data)
    {
      v19 = v14;
      v20 = data;
    }
    else
    {
      v28 = 1.0;
      if (v16 > data_high || !data_high)
      {
LABEL_41:
        v29 = effColorBlend(HIDWORD(v3[3].klass) & 0xFFFFFF, HIDWORD(v3[3].klass), v28, 0);
        sub_854930(&v86, 0);
        sub_854930(&v86, 1u);
        sub_854930(&v86, 2u);
        v31 = 0;
        v32 = (v10 + 4);
        do
        {
          effBTLModelGetMarkPosition2(&pFormation, v31 + 30);
          SDF_VU0__STOREVECTOR(v32);
          sub_854710(&v86, 0);
          sub_854710(v32, 0);
          sub_854930(&v86, 0);
          sub_854710(&v86, 1u);
          sub_854710(v32, 1u);
          sub_854930(&v86, 1u);
          sub_854710(&v86, 2u);
          sub_854710(v32, 2u);
          sub_854930(&v86, 2u);
          ++v31;
          ++v32;
        }
        while (v31 != 6);
        sub_854710(&v86, 0);
        sub_854930(&v86, 0);
        sub_854710(&v86, 1u);
        sub_854930(&v86, 1u);
        sub_854710(&v86, 2u);
        sub_854930(&v86, 2u);
        sub_854930(&v86, 3u);
        SDF_VU0__LOADVECTOR(pFormation->pos);
        SDF_VU0__LOADVECTOR_B(effPCPBossKAGU2AttackConvergePoint);
        SDF_VU0__ADDVECTOR();
        SDF_VU0__STOREVECTOR(&p);
        bits = v3[1].klass->_1.byval_arg.bits;
        if (bits)
        {
          v40 = 0;
          do
          {
            monitor = v3[1].monitor;
            p_fields = &effPCP_ThunderPolyListGetParam(monitor[v40 + 4])->fields;
            v46 = *(v10 + 12);
            v94.y = *(v10 + 13);
            v94.z = *(v10 + 14);
            v94.w = *(v10 + 15);
            x = p.x;
            y = p.y;
            z = p.z;
            w = p.w;
            rand = *&v86;
            v54 = v87;
            v94.x = v46;
            v95.x = x;
            v95.y = y;
            v95.z = z;
            v95.w = w;
            effPCPBossKAGU2AttackGetSplitPoint(&p_fields->pos, v94, v95, v90, rand, *&v54);
            v55 = v3[1].monitor;
            hDataa = v55[v40 + 4];
            effPCP_ThunderPolyListSetColor(&hDataa, v29);
            effPCP_ThunderPolyListDraw(&hDataa);
            v57 = v3[1].monitor;
            Param = effPCP_ThunderPolyListGetParam(v57[v40 + 5]);
            effPCPBossKAGU2AttackGetSplitPoint(&Param->pos, *(v10 + 4), p, v91, *&v86, *&v87);
            v62 = v3[1].monitor;
            hDataa = v62[v40 + 5];
            effPCP_ThunderPolyListSetColor(&hDataa, v29);
            effPCP_ThunderPolyListDraw(&hDataa);
            v64 = v3[1].monitor;
            v66 = effPCP_ThunderPolyListGetParam(v64[v40 + 6]);
            effPCPBossKAGU2AttackGetSplitPoint(&v66->pos, *(v10 + 6), p, v92, *&v86, *&v87);
            v69 = v3[1].monitor;
            hDataa = v69[v40 + 6];
            effPCP_ThunderPolyListSetColor(&hDataa, v29);
            effPCP_ThunderPolyListDraw(&hDataa);
            v71 = v3[1].monitor;
            v73 = effPCP_ThunderPolyListGetParam(v71[v40 + 7]);
            effPCPBossKAGU2AttackGetSplitPoint(&v73->pos, *(v10 + 7), p, v93, *&v86, *&v87);
            v76 = v3[1].monitor;
            hDataa = v76[v40 + 7];
            effPCP_ThunderPolyListSetColor(&hDataa, v29);
            effPCP_ThunderPolyListDraw(&hDataa);
            --bits;
            v40 += 4LL;
          }
          while (bits);
        }
        sub_854930((v79 + 4), 0);
        sub_854930((v79 + 4), 1u);
        sub_854930((v79 + 4), 2u);
        sub_854930((v79 + 4), 3u);
        v79[6] = 0x42C8000042C80000LL;
        *(v79 + 14) = v3[1].klass->_1.namespaze;
        sub_854710(&p, 0);
        sub_854930((v79 + 2), 0);
        sub_854710(&p, 1u);
        sub_854930((v79 + 2), 1u);
        sub_854710(&p, 2u);
        sub_854930((v79 + 2), 2u);
        sub_854930((v79 + 2), 3u);
        *(v79 + 15) = v29;
        effEveBEDCutSetParams(&v3[2].monitor, v79);
        effEveBEDCutDraw(&v3[2].monitor);
        v14 = v3[3].klass;
        goto LABEL_91;
      }
      v19 = v16;
      v20 = data_high;
    }
    v28 = v19 / v20;
    goto LABEL_41;
  }
}

// 0x11e8d70
void effPCPBossKAGU2AttackGetSplitPoint(sdfVector4_t ***pPosBuff, sdfVector4_t pPoint1, sdfVector4_t pPoint2, sdfVector4_t pCenter, f32 rand, f32 rotate) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 v12;
  f32 v13;
  f32 v16;
  f32 v17;
  f32 v18;
  f32 v19;
  f32 v20;
  f32 v21;
  u64 v22;
  f32 v23;
  s64 v24;
  s64 v26;
  UnityEngine_Vector4_o aAxis;
  UnityEngine_Vector4_o v29;
  UnityEngine_Vector4_o v30;
  UnityEngine_Vector4_o v31;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v33;
  f32 v34;
  f32 v35;
  UnityEngine_Vector4_o v37;
  UnityEngine_Vector4_o v38;
  UnityEngine_Vector4_o v39;
  UnityEngine_Vector4_o v40;

  w = pPoint1.w;
  z = pPoint1.z;
  y = pPoint1.y;
  x = pPoint1.x;
  v33 = pPoint2;
  *&p.x = 0;
  *&p.z = 0;
  v37.x = rand;
  v37.y = *(&rand + 1);
  v37.z = rotate;
  v37.w = *(&rotate + 1);
  *&v31.x = 0;
  *&v31.z = 0;
  *&v30.x = 0;
  *&v30.z = 0;
  *&v29.x = 0;
  *&v29.z = 0;
  *&aAxis.x = 0;
  *&aAxis.z = 0;
  SDF_VU0__LOADVECTOR_B(v37);
  v38.x = x;
  v38.y = y;
  v38.z = z;
  v38.w = w;
  SDF_VU0__LOADVECTOR(v38);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&p);
  SDF_VU0__LOADVECTOR(pPoint2);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__GETLENGTH();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v31);
  SDF_VU0__COPYVECTOR_B_TO_C();
  sub_854930(&v30, 0);
  sub_854930(&v30, 1u);
  sub_854930(&v30, 2u);
  v12 = 0.0;
  sub_854930(&v30, 3u);
  sub_854930(&v29, 0);
  sub_854930(&v29, 1u);
  sub_854930(&v29, 2u);
  sub_854930(&v29, 3u);
  SDF_VU0__LOADVECTOR_B(pPoint2);
  v39.x = x;
  v39.y = y;
  v39.w = w;
  v39.z = z;
  SDF_VU0__LOADVECTOR(v39);
  sub_854710(&v33, 0);
  SDF_VU0__SETVECTOR_X(v13);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&aAxis);
  v16 = DDS3EFFECT_RAND_FA(v34);
  v17 = aAxis.x;
  v18 = ((1.0 - v16) * 0.61087) + v35;
  v19 = aAxis.y;
  v20 = aAxis.z;
  v21 = aAxis.w;
  v40.x = v17;
  v40.y = v19;
  v40.z = v20;
  v40.w = v21;
  SetRotateMatrixAxis(v18, v40);
  v22 = 0;
  if (v18 == 0.0)
  {
    v23 = 0.0;
    v24 = 32;
    do
    {
      SDF_VU0__LOADVECTOR(p);
      SDF_VU0__LOADVECTOR_B(v31);
      SDF_VU0__INTERPOLATE(v23);
      SDF_VU0__NORMALIZE();
      SDF_VU0__APPLYMATRIX_XYZ();
      SDF_VU0__LOADVECTOR_B(v30);
      SDF_VU0__MULVECTOR();
      SDF_VU0__ADDVECTOR_A_C();
      SDF_VU0__STOREVECTOR((*pPosBuff + v24), 0);
      SDF_VU0__LOADVECTOR_B(v30);
      SDF_VU0__LOADVECTOR(v29);
      SDF_VU0__ADDVECTOR_B_A();
      SDF_VU0__STOREVECTOR_B(&v30);
      v23 = v23 + 0.25;
      ++v22;
      v24 += 16;
    }
    while (v22 != 5);
  }
  else
  {
    v26 = 32;
    do
    {
      SDF_VU0__LOADVECTOR(p);
      SDF_VU0__LOADVECTOR_B(v31);
      SDF_VU0__INTERPOLATE(v12);
      SDF_VU0__NORMALIZE();
      SDF_VU0__APPLYMATRIX_XYZ();
      SDF_VU0__LOADVECTOR_B(v30);
      if (v22 == 2)
        SDF_VU0__SCALEVECTOR_B(0.75);
      SDF_VU0__MULVECTOR();
      SDF_VU0__ADDVECTOR_A_C();
      SDF_VU0__STOREVECTOR((*pPosBuff + v26), 0);
      SDF_VU0__LOADVECTOR_B(v30);
      SDF_VU0__LOADVECTOR(v29);
      SDF_VU0__ADDVECTOR_B_A();
      SDF_VU0__STOREVECTOR_B(&v30);
      v12 = v12 + 0.25;
      ++v22;
      v26 += 16;
    }
    while (v22 != 5);
  }
}

// 0x11e9cd0
void effPCPBossKAGU2AttackSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossKAGU2Attack_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBossKAGU2Attack_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[3].klass) = abgr;
}

// 0x11ea220
effPCPBossKAGU2MUHENK_t *effPCPBossKAGU2MUHENKCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v7;
  u64 *v8;
  char *v10;
  s64 *v11;
  u64 v12[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossKAGU2MUHENK_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBossKAGU2MUHENK_t, v12);
    if ((v12[0] & 1) != 0)
      v10 = v12[2];
    else
      v10 = v12 + 1;
    v11 = sub_8C4940(v10);
  }
  v7 = (*hData)[1].klass;
LABEL_9:
  v8 = Allocate(effPCPBossKAGU2MUHENK_t);
  effPCPBossKAGU2MUHENK_t___ctor(v8);
  v8[2] = v7;
  v8[3] = 0x8080808000000000LL;
  return v8;
}

// 0x11e9f20
effPCPBossKAGU2MUHENK_t *effPCPBossKAGU2MUHENKCreate(effPCPBossKAGU2MUHENKParam_t *pParam) {
  u64 *v3;

  v3 = Allocate(effPCPBossKAGU2MUHENK_t);
  effPCPBossKAGU2MUHENK_t___ctor(v3);
  v3[2] = pParam;
  v3[3] = 0x8080808000000000LL;
  return v3;
}

// 0x11e9f90
effPCPBossKAGU2MUHENK_t *effPCPBossKAGU2MUHENKCreatePCF(void **hData, s32 bPos, bool tbldata) {
  dds3EffectPCPData_t_o *v6;
  Il2CppObject *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  struct dds3EffectPCPData_Part_t_array *pcpData;
  Il2CppObject *v14;
  u32 offset;
  Il2CppObject *DataUnityOffSet;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v21;
  s64 *v22;
  u64 *v23;
  u64 v25[2];
  char *v26;
  s32 pos;

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v7->klass->_1.element_class, v8, v25);
      if ((v25[0] & 1) != 0)
        v10 = v26;
      else
        v10 = v25 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v6, Interface, &pos);
  pcpData = v6->pcpData;
  v14 = *hData;
  offset = pcpData->m_Items[0]->offset;
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 45);
  else if (!DataUnityOffSet)
  {
    goto LABEL_24;
  }
  klass = DataUnityOffSet->klass;
  if (DataUnityOffSet->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossKAGU2MUHENKParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBossKAGU2MUHENKParam_t, v25);
    if ((v25[0] & 1) != 0)
      v21 = v26;
    else
      v21 = v25 + 1;
    v22 = sub_8C4940(v21);
  }
LABEL_24:
  v23 = Allocate(effPCPBossKAGU2MUHENK_t);
  effPCPBossKAGU2MUHENK_t___ctor(v23);
  v23[2] = DataUnityOffSet;
  v23[3] = 0x8080808000000000LL;
  return v23;
}

// 0x11ea390
void effPCPBossKAGU2MUHENKDelete(effPCPBossKAGU2MUHENK_t *pPCPBossKAGU2MUHENK) {
  ;
}

// 0x11ea3a0
void effPCPBossKAGU2MUHENKDraw(effPCPBossKAGU2MUHENK_t *pPCPBossKAGU2MUHENK) {
  nbMainProcessData_t_o *MainProcessData;
  u64 v9;
  struct nbFormation_t_array *form;
  u32 ID;
  UnityEngine_Vector4_o v14;
  s64 v15;
  s64 v16;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *pFormation;

  v15 = 0;
  v16 = 0;
  *&v14.x = 0;
  *&v14.z = 0;
  pFormation = 0;
  *&p.x = 0;
  *&p.z = 0;
  else if (effBTLSkillCheckRun())
  {
    goto LABEL_6;
  }
  MainProcessData = nbGetMainProcessData();
  v9 = 0;
  while (1)
  {
    form = MainProcessData->form;
    pFormation = form->m_Items[v9];
    if ((~pFormation->stat & 3) == 0)
    {
      ID = effBTLModelGetID(&pFormation);
      if (ID == 264 || ID == 293)
        break;
    }
    if (v9++ > 0x1E)
      return;
  }
  if (pFormation)
    goto LABEL_10;
}

// 0x11ea700
void effPCPBossKAGU2MUHENKSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossKAGU2MUHENK_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBossKAGU2MUHENK_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[1].monitor) = abgr;
}

// 0x11e9dc0
void effPCPBossKAGU2ThunderboltDraw(void **hData) {
  Il2CppObject *v3;
  f32 x;
  f32 y;
  f32 z;
  f32 w;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  u64 v14[3];
  UnityEngine_Vector4_o v15;

  v3 = *hData;
  else
  {
    x = effPCPBossKAGU2AttackConvergePoint.x;
    y = effPCPBossKAGU2AttackConvergePoint.y;
    z = effPCPBossKAGU2AttackConvergePoint.z;
    w = effPCPBossKAGU2AttackConvergePoint.w;
    if (!v3)
      goto LABEL_12;
  }
  klass = v3->klass;
  if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossKAGUThunderbolt_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBossKAGUThunderbolt_t, v14);
    if ((v14[0] & 1) != 0)
      v11 = v14[2];
    else
      v11 = v14 + 1;
    v12 = sub_8C4940(v11);
  }
LABEL_12:
  v15.x = x;
  v15.y = y;
  v15.z = z;
  v15.w = w;
  effPCPBossKAGUThunderboltDrawSub(v3, v15);
}

// 0x11e5fe0
effPCPBossKAGUAttack_t *effPCPBossKAGUAttackCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 *v10;
  effPCPBossKAGUAttackParam_t_o *v13;
  effPCPBossKAGUAttack_t_o *v14;
  effPCPBossKAGUAttack_t_o *v15;
  effBTL_t_o *hBED;
  u64 v19[3];

  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossKAGUAttack_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBossKAGUAttack_t, v19);
      if ((v19[0] & 1) != 0)
        v8 = v19[2];
      else
        v8 = v19 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = Allocate(effEveBEDParams_t);
  effEveBEDParams_t___ctor(v10);
  v13 = v5[1].klass;
  v14 = effPCPBossKAGUAttackCreate(v13, 0);
  v14->hBED = v5[2].klass;
  v15 = v14;
  sub_854930((v10 + 2), 0);
  sub_854930((v10 + 2), 1u);
  sub_854930((v10 + 2), 2u);
  sub_854930((v10 + 2), 3u);
  sub_854930((v10 + 4), 0);
  sub_854930((v10 + 4), 1u);
  sub_854930((v10 + 4), 2u);
  sub_854930((v10 + 4), 3u);
  v10[6] = 0x42C8000042C80000LL;
  *(v10 + 14) = LODWORD(v15->param->scale);
  *(v10 + 15) = -2139062144;
  hBED = v15->hBED;
  v15->hBEDCut = effEveBEDCutCreate(hBED, 2u, v10);
  return v15;
}

// 0x11e5a00
effPCPBossKAGUAttack_t *effPCPBossKAGUAttackCreate(effPCPBossKAGUAttackParam_t *pParam, void *pBEDData) {
  effPCP_ThunderPolyListParam_t_o *v5;
  u64 *v6;
  u64 *v7;
  Il2CppClass *v9;
  s64 *Interface;
  char *v11;
  s64 *v12;
  effBTL_t_o *v13;
  effEveBEDCutHandle_t_o *v14;
  struct effPCP_ThunderPolyParam_t_o *TPParam;
  s32 v16;
  u64 v17;
  u64 v18;
  u32 *v20;
  s64 *v21;
  s64 *v22;
  u32 *v24;
  Il2CppObject *v26[3];
  Il2CppObject *hData;

  hData = 0;
  v5 = Allocate(effPCP_ThunderPolyListParam_t);
  effPCP_ThunderPolyListParam_t___ctor(v5);
  effPCP_ThunderPolyListParam_t__Clear(v5);
  v6 = Allocate(effEveBEDParams_t);
  effEveBEDParams_t___ctor(v6);
  v7 = Allocate(effPCPBossKAGUAttack_t);
  effPCPBossKAGUAttack_t___ctor(v7);
  v7[2] = pParam;
  v7[6] = 0x8080808000000000LL;
  if (pBEDData)
  {
    sub_854930((v6 + 2), 0);
    sub_854930((v6 + 2), 1u);
    sub_854930((v6 + 2), 2u);
    sub_854930((v6 + 2), 3u);
    sub_854930((v6 + 4), 0);
    sub_854930((v6 + 4), 1u);
    sub_854930((v6 + 4), 2u);
    sub_854930((v6 + 4), 3u);
    v6[6] = 0x42C8000042C80000LL;
    *(v6 + 14) = *(v7[2] + 24);
    *(v6 + 15) = -2139062144;
    Interface = QueryInterface(pBEDData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pBEDData->klass->_1.element_class, v9, v26);
      if ((v26[0] & 1) != 0)
        v11 = v26[2];
      else
        v11 = v26 + 1;
      v12 = sub_8C4940(v11);
    }
    v13 = effEveBEDCreate(Interface);
    v7[4] = v13;
    v14 = effEveBEDCutCreate(v13, 2u, v6);
    pParam = v7[2];
    v7[5] = v14;
  }
  TPParam = pParam->TPParam;
  v5->TPParam = TPParam;
  TPParam->number = 1;
  v5->point = 5;
  v16 = *(v7[2] + 40);
  if (v16)
  {
    v17 = 0;
    v18 = (8 * v16);
    do
    {
      hData = v5;
      v20 = v7[3];
      v21 = effPCP_ThunderPolyListCreate(&hData, 0, 1);
      v22 = v21;
      v24 = &v20[2 * v17++];
      *(v24 + 4) = v22;
    }
    while (v17 < v18);
  }
  return v7;
}

// 0x11e5d30
effPCPBossKAGUAttack_t *effPCPBossKAGUAttackCreatePCF(void **hData, s32 bPos, bool tbldata) {
  dds3EffectPCPData_t_o *v6;
  Il2CppObject *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  struct dds3EffectPCPData_Part_t_array *pcpData;
  Il2CppObject *v14;
  u32 offset;
  Il2CppObject *DataUnityOffSet;
  struct dds3EffectPCPData_Part_t_array *v19;
  Il2CppObject *v20;
  effPCPBossKAGUAttackParam_t_o *v21;
  u32 v23;
  Il2CppObject *EffPCPAgiFireballPart;
  effPCPBossKAGUAttackParam_t_c *klass;
  s64 typeHierarchyDepth;
  char *v29;
  s64 *v30;
  u64 v32[2];
  char *v33;
  s32 pos;

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v7->klass->_1.element_class, v8, v32);
      if ((v32[0] & 1) != 0)
        v10 = v33;
      else
        v10 = v32 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v6, Interface, &pos);
  pcpData = v6->pcpData;
  v14 = *hData;
  offset = pcpData->m_Items[0]->offset;
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 42);
  v19 = v6->pcpData;
  v20 = *hData;
  v21 = DataUnityOffSet;
  v23 = v19->m_Items[1]->offset;
  EffPCPAgiFireballPart = GetEffPCPAgiFireballPart(v20, v23 + bPos);
  else if (!v21)
  {
    return effPCPBossKAGUAttackCreate(v21, EffPCPAgiFireballPart);
  }
  klass = v21->klass;
  if (v21->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossKAGUAttackParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBossKAGUAttackParam_t, v32);
    if ((v32[0] & 1) != 0)
      v29 = v33;
    else
      v29 = v32 + 1;
    v30 = sub_8C4940(v29);
  }
  return effPCPBossKAGUAttackCreate(v21, EffPCPAgiFireballPart);
}

// 0x11e6240
void effPCPBossKAGUAttackDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  effEveBEDCutHandle_t_o *monitor;
  effBTL_t_o *v10;
  u32 bits;
  u64 v12;
  u64 v13;
  u64 *v14;
  Il2CppObject *v16;
  u64 v17[3];

  v16 = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossKAGUAttack_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBossKAGUAttack_t, v17);
      if ((v17[0] & 1) != 0)
        v6 = v17[2];
      else
        v6 = v17 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  monitor = v3[2].monitor;
  effEveBEDCutDelete(monitor);
  v10 = v3[2].klass;
  if (!v10->CutCount)
  {
    effEveBEDDelete(v10);
  }
  bits = v3[1].klass->_1.byval_arg.bits;
  if (bits)
  {
    v12 = 0;
    v13 = 8 * bits;
    do
    {
      v14 = v3[1].monitor;
      v16 = v14[v12 + 4];
      effPCP_ThunderPolyListDelete(&v16);
      ++v12;
    }
    while (v12 < v13);
  }
}

// 0x11e6670
void effPCPBossKAGUAttackDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  UnityEngine_Vector4_o *v10;
  Il2CppClass *v12;
  s32 namespaze_high;
  s32 v14;
  bool v15;
  s32 v16;
  s32 data_high;
  s32 data;
  f32 v19;
  f32 v20;
  nbMainProcessData_t_o *MainProcessData;
  u64 v23;
  struct nbFormation_t_array *form;
  u32 ID;
  f32 v28;
  u64 v30;
  UnityEngine_Vector4_o *v31;
  s32 v38;
  s32 v39;
  f32 *p_w;
  u64 v41;
  s32 v42;
  u32 *monitor;
  s64 v44;
  effPCP_ThunderPolyListParam_t_Fields *p_fields;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  u32 *v56;
  u64 *v59;
  u32 bits;
  u32 abgr;
  Il2CppObject *hDataa;
  UnityEngine_Vector4_o p;
  s64 v68;
  s64 v69;
  nbFormation_t_o *pFormation;
  u64 v71[4];
  UnityEngine_Vector4_o v72;
  UnityEngine_Vector4_o v73;
  UnityEngine_Vector4_o v74;

  v69 = 0;
  pFormation = 0;
  *&p.z = 0;
  v68 = 0;
  hDataa = 0;
  *&p.x = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossKAGUAttack_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBossKAGUAttack_t, v71);
      if ((v71[0] & 1) != 0)
        v6 = v71[2];
      else
        v6 = v71 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  pFormation = 0;
  v8 = Allocate(effEveBEDParams_t);
  effEveBEDParams_t___ctor(v8);
  v68 = 0;
  v69 = 0;
  v10 = NewSpecific(UnityEngine_Vector4, 8u);
  *&p.x = 0;
  *&p.z = 0;
  else if (effBTLSkillCheckRun())
  {
    goto LABEL_13;
  }
  MainProcessData = nbGetMainProcessData();
  v23 = 0;
  while (1)
  {
    form = MainProcessData->form;
    pFormation = form->m_Items[v23];
    if ((~pFormation->stat & 3) == 0)
    {
      ID = effBTLModelGetID(&pFormation);
      if (ID == 264 || ID == 293)
        break;
    }
    if (v23++ > 0x1E)
      return;
  }
  if (pFormation)
  {
LABEL_17:
    v12 = v3[1].klass;
    namespaze_high = HIDWORD(v12->_1.namespaze);
    v14 = v3[3].klass;
    v15 = __OFSUB__(namespaze_high, v14);
    v16 = namespaze_high - v14;
    if ((v16 < 0) ^ v15 | (v16 == 0))
    {
LABEL_77:
      LODWORD(v3[3].klass) = v14 + 1;
      return;
    }
    data = v12->_1.byval_arg.data;
    data_high = HIDWORD(v12->_1.byval_arg.data);
    if (v14 < data && data)
    {
      v19 = v14;
      v20 = data;
    }
    else
    {
      v28 = 1.0;
      if (v16 > data_high || !data_high)
      {
LABEL_41:
        abgr = effColorBlend(HIDWORD(v3[3].klass) & 0xFFFFFF, HIDWORD(v3[3].klass), v28, 0);
        sub_854930(&v68, 0);
        sub_854930(&v68, 1u);
        sub_854930(&v68, 2u);
        v30 = 0;
        v31 = v10 + 2;
        do
        {
          effBTLModelGetMarkPosition2(&pFormation, v30 + 20);
          SDF_VU0__STOREVECTOR(v31);
          sub_854710(&v68, 0);
          sub_854710(v31, 0);
          sub_854930(&v68, 0);
          sub_854710(&v68, 1u);
          sub_854710(v31, 1u);
          sub_854930(&v68, 1u);
          sub_854710(&v68, 2u);
          sub_854710(v31, 2u);
          sub_854930(&v68, 2u);
          ++v30;
          ++v31;
        }
        while (v30 != 8);
        sub_854710(&v68, 0);
        sub_854930(&v68, 0);
        sub_854710(&v68, 1u);
        sub_854930(&v68, 1u);
        sub_854710(&v68, 2u);
        sub_854930(&v68, 2u);
        sub_854930(&v68, 3u);
        SDF_VU0__LOADVECTOR(pFormation->pos);
        v59 = v8;
        SDF_VU0__LOADVECTOR_B(effPCPBossKAGUAttackConvergePoint);
        SDF_VU0__ADDVECTOR();
        SDF_VU0__STOREVECTOR(&p);
        bits = v3[1].klass->_1.byval_arg.bits;
        if (bits)
        {
          v38 = 0;
          v39 = 0;
          do
          {
            p_w = &v10[2].w;
            v41 = 0;
            v42 = v39;
            do
            {
              if (v41 != 6)
              {
                monitor = v3[1].monitor;
                v44 = (v42 + v41);
                p_fields = &effPCP_ThunderPolyListGetParam(*&monitor[2 * v44 + 8])->fields;
                v73 = *(p_w - 3);
                x = p.x;
                y = p.y;
                z = p.z;
                w = p.w;
                v74.x = x;
                v74.y = y;
                v74.z = z;
                v74.w = w;
                effPCPBossKAGUAttackGetSplitPoint(&p_fields->pos, v73, v74, v72);
                v56 = v3[1].monitor;
                hDataa = *&v56[2 * v44 + 8];
                effPCP_ThunderPolyListSetColor(&hDataa, abgr);
                effPCP_ThunderPolyListDraw(&hDataa);
              }
              ++v41;
              p_w += 4;
            }
            while (v41 != 8);
            ++v38;
            v39 = v42 + 8;
          }
          while (v38 != bits);
        }
        sub_854930((v59 + 4), 0);
        sub_854930((v59 + 4), 1u);
        sub_854930((v59 + 4), 2u);
        sub_854930((v59 + 4), 3u);
        v59[6] = 0x42C8000042C80000LL;
        *(v59 + 14) = v3[1].klass->_1.namespaze;
        sub_854710(&p, 0);
        sub_854930((v59 + 2), 0);
        sub_854710(&p, 1u);
        sub_854930((v59 + 2), 1u);
        sub_854710(&p, 2u);
        sub_854930((v59 + 2), 2u);
        sub_854930((v59 + 2), 3u);
        *(v59 + 15) = abgr;
        effEveBEDCutSetParams(&v3[2].monitor, v59);
        effEveBEDCutDraw(&v3[2].monitor);
        v14 = v3[3].klass;
        goto LABEL_77;
      }
      v19 = v16;
      v20 = data_high;
    }
    v28 = v19 / v20;
    goto LABEL_41;
  }
}

// 0x11e63f0
void effPCPBossKAGUAttackGetSplitPoint(sdfVector4_t ***pPosBuff, sdfVector4_t pPoint1, sdfVector4_t pPoint2, sdfVector4_t pCenter) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 v10;
  f32 v11;
  f32 v12;
  f32 v13;
  f32 v14;
  u64 v15;
  s64 v16;
  UnityEngine_Vector4_o v18;
  UnityEngine_Vector4_o v19;
  UnityEngine_Vector4_o v20;
  UnityEngine_Vector4_o p;
  s64 v22;
  s64 v23;
  UnityEngine_Vector4_o v24;
  UnityEngine_Vector4_o v25;
  UnityEngine_Vector4_o v26;

  w = pPoint1.w;
  z = pPoint1.z;
  y = pPoint1.y;
  x = pPoint1.x;
  *&v24.x = v22;
  *&v24.z = v23;
  v10 = pPoint2.w;
  v11 = pPoint2.z;
  v12 = pPoint2.y;
  v13 = pPoint2.x;
  *&p.x = 0;
  *&p.z = 0;
  *&v20.x = 0;
  *&v20.z = 0;
  *&v19.x = 0;
  *&v19.z = 0;
  *&v18.x = 0;
  *&v18.z = 0;
  SDF_VU0__LOADVECTOR_B(v24);
  v25.x = x;
  v25.y = y;
  v25.z = z;
  v25.w = w;
  SDF_VU0__LOADVECTOR(v25);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__GETLENGTH();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&p);
  v26.x = v13;
  v26.y = v12;
  v26.z = v11;
  v26.w = v10;
  SDF_VU0__LOADVECTOR(v26);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__GETLENGTH();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v20);
  SDF_VU0__COPYVECTOR_B_TO_C();
  sub_854930(&v19, 0);
  sub_854930(&v19, 1u);
  sub_854930(&v19, 2u);
  v14 = 0.0;
  sub_854930(&v19, 3u);
  sub_854930(&v18, 0);
  sub_854930(&v18, 1u);
  sub_854930(&v18, 2u);
  sub_854930(&v18, 3u);
  v15 = 0;
  v16 = 32;
  do
  {
    SDF_VU0__LOADVECTOR(p);
    SDF_VU0__LOADVECTOR_B(v20);
    SDF_VU0__INTERPOLATE(v14);
    SDF_VU0__NORMALIZE();
    SDF_VU0__LOADVECTOR_B(v19);
    SDF_VU0__MULVECTOR();
    SDF_VU0__ADDVECTOR_A_C();
    SDF_VU0__STOREVECTOR((*pPosBuff + v16), 0);
    SDF_VU0__LOADVECTOR(v18);
    SDF_VU0__ADDVECTOR_B_A();
    SDF_VU0__STOREVECTOR_B(&v19);
    v14 = v14 + 0.25;
    ++v15;
    v16 += 16;
  }
  while (v15 != 5);
}

// 0x11e6ea0
void effPCPBossKAGUAttackSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossKAGUAttack_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBossKAGUAttack_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[3].klass) = abgr;
}

// 0x11e4ed0
effPCPBossKAGUInvoke_t *effPCPBossKAGUInvokeCopy(void **hData, s32 bPos, bool tbldata) {
  effPCPBossKAGUInvoke_t_c *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v8;
  char *v10;
  s64 *v11;
  u64 v12[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossKAGUInvoke_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBossKAGUInvoke_t, v12);
    if ((v12[0] & 1) != 0)
      v10 = v12[2];
    else
      v10 = v12 + 1;
    v11 = sub_8C4940(v10);
  }
  v8 = (*hData)[1].klass;
  return effPCPBossKAGUInvokeCreate(v8, v5);
}

// 0x11e4ae0
effPCPBossKAGUInvoke_t *effPCPBossKAGUInvokeCreate(effPCPBossKAGUInvokeParam_t *pParam) {
  u64 *v3;
  effPCP_ThunderPolyListParam_t_o *v4;
  u64 *v5;
  struct effPCP_ThunderPolyParam_t_o *TPParam;
  s64 v7;
  s64 v8;
  u32 *v9;
  u32 *v10;
  u64 v11;
  s64 *v12;
  s64 *v13;
  u32 *v15;
  Il2CppObject *hData;

  hData = 0;
  v3 = Allocate(effPCPBossKAGUInvoke_t);
  effPCPBossKAGUInvoke_t___ctor(v3);
  v4 = Allocate(effPCP_ThunderPolyListParam_t);
  effPCP_ThunderPolyListParam_t___ctor(v4);
  effPCP_ThunderPolyListParam_t__Clear(v4);
  v5 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v5);
  v3[2] = pParam;
  v3[5] = 0x8080808000000000LL;
  v3[6] = v5;
  TPParam = pParam->TPParam;
  v4->TPParam = TPParam;
  TPParam->number = 1;
  v4->point = 9;
  v7 = *(v3[2] + 44);
  v8 = 6 * v7;
  v9 = NewSpecific(effPCP_ThunderPolyList_t, (6 * v7) & 0xFFFFFFFELL);
  v3[3] = v9;
  if (v7 >= 1)
  {
    v10 = v9;
    v11 = 0;
    while (1)
    {
      hData = v4;
      v12 = effPCP_ThunderPolyListCreate(&hData, 0, 1);
      v13 = v12;
      v15 = &v10[2 * v11++];
      *(v15 + 4) = v13;
      if (v11 >= v8)
        break;
      v10 = v3[3];
    }
  }
  return v3;
}

// 0x11e49c0
effPCPBossKAGUInvoke_t *effPCPBossKAGUInvokeCreateP(void **pData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v11[3];

  v5 = *pData;
  else if (!v5)
  {
    return effPCPBossKAGUInvokeCreate(v5, *&bPos);
  }
  klass = v5->klass;
  if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossKAGUInvokeParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBossKAGUInvokeParam_t, v11);
    if ((v11[0] & 1) != 0)
      v8 = v11[2];
    else
      v8 = v11 + 1;
    v9 = sub_8C4940(v8);
  }
  return effPCPBossKAGUInvokeCreate(v5, *&bPos);
}

// 0x11e4c90
effPCPBossKAGUInvoke_t *effPCPBossKAGUInvokeCreatePCF(void **hData, s32 bPos, bool tbldata) {
  dds3EffectPCPData_t_o *v6;
  Il2CppObject *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  struct dds3EffectPCPData_Part_t_array *pcpData;
  Il2CppObject *v14;
  u32 offset;
  effPCPBossKAGUInvokeParam_t_c *v17;
  Il2CppObject *DataUnityOffSet;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v21;
  s64 *v22;
  u64 v24[2];
  char *v25;
  s32 pos;

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v7->klass->_1.element_class, v8, v24);
      if ((v24[0] & 1) != 0)
        v10 = v25;
      else
        v10 = v24 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v6, Interface, &pos);
  pcpData = v6->pcpData;
  v14 = *hData;
  offset = pcpData->m_Items[0]->offset;
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 41);
  else if (!DataUnityOffSet)
  {
    return effPCPBossKAGUInvokeCreate(DataUnityOffSet, v17);
  }
  klass = DataUnityOffSet->klass;
  if (DataUnityOffSet->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossKAGUInvokeParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBossKAGUInvokeParam_t, v24);
    if ((v24[0] & 1) != 0)
      v21 = v25;
    else
      v21 = v24 + 1;
    v22 = sub_8C4940(v21);
  }
  return effPCPBossKAGUInvokeCreate(DataUnityOffSet, v17);
}

// 0x11e4fe0
void effPCPBossKAGUInvokeDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s64 v8;
  u64 v9;
  s64 v10;
  u64 *monitor;
  Il2CppObject *v13;
  u64 v14[3];

  v13 = 0;
  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossKAGUInvoke_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBossKAGUInvoke_t, v14);
      if ((v14[0] & 1) != 0)
        v6 = v14[2];
      else
        v6 = v14 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = *(&v3[1].klass->_1.byval_arg.bits + 1);
  if (v8 >= 1)
  {
    v9 = 0;
    v10 = 6 * v8;
    do
    {
      monitor = v3[1].monitor;
      v13 = monitor[v9 + 4];
      effPCP_ThunderPolyListDelete(&v13);
      ++v9;
    }
    while (v9 < v10);
  }
}

// 0x11e5140
void effPCPBossKAGUInvokeDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v9;
  Il2CppClass *v11;
  s32 data;
  s32 monitor;
  bool v14;
  s32 v15;
  s32 bits;
  s32 data_high;
  f32 v18;
  f32 v19;
  nbMainProcessData_t_o *MainProcessData;
  u64 v22;
  struct nbFormation_t_array *form;
  u32 ID;
  f32 v27;
  u32 v29;
  f32 v47;
  s32 v48;
  s32 v49;
  u32 v50;
  u64 v51;
  f32 v52;
  u32 *v53;
  s64 v54;
  effPCP_ThunderPolyListParam_t_o *Param;
  s64 v57;
  u64 i;
  const char *name;
  s64 v61;
  const char *v63;
  s64 v65;
  f32 v67;
  struct UnityEngine_Vector4_array *pos;
  u32 *v70;
  Il2CppObject *v72;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *v74[3];
  nbFormation_t_o *pFormation;

  pFormation = 0;
  *&p.x = 0;
  *&p.z = 0;
  v72 = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossKAGUInvoke_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBossKAGUInvoke_t, v74);
      if ((v74[0] & 1) != 0)
        v6 = v74[2];
      else
        v6 = v74 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  pFormation = 0;
  v9 = NewSpecific(UnityEngine_Vector4, 8u);
  *&p.x = 0;
  *&p.z = 0;
  else if (effBTLSkillCheckRun())
  {
    goto LABEL_13;
  }
  MainProcessData = nbGetMainProcessData();
  v22 = 0;
  while (1)
  {
    form = MainProcessData->form;
    pFormation = form->m_Items[v22];
    if ((~pFormation->stat & 3) == 0)
    {
      ID = effBTLModelGetID(&pFormation);
      if (ID == 264 || ID == 293)
        break;
    }
    if (v22++ > 0x1E)
      return;
  }
  if (pFormation)
  {
LABEL_17:
    v11 = v3[1].klass;
    data = v11->_1.byval_arg.data;
    monitor = v3[2].monitor;
    v14 = __OFSUB__(data, monitor);
    v15 = data - monitor;
    if ((v15 < 0) ^ v14 | (v15 == 0))
    {
LABEL_107:
      ++LODWORD(v3[2].monitor);
      return;
    }
    data_high = HIDWORD(v11->_1.byval_arg.data);
    bits = v11->_1.byval_arg.bits;
    if (monitor < data_high && data_high)
    {
      v18 = monitor;
      v19 = data_high;
    }
    else
    {
      v27 = 1.0;
      if (v15 > bits || !bits)
        goto LABEL_41;
      v18 = v15;
      v19 = bits;
    }
    v27 = v18 / v19;
LABEL_41:
    v29 = effColorBlend(HIDWORD(v3[2].monitor) & 0xFFFFFF, HIDWORD(v3[2].monitor), v27, 0);
    effBTLModelGetMarkPosition2(&pFormation, 0x14u);
    SDF_VU0__STOREVECTOR(v9 + 2);
    effBTLModelGetMarkPosition2(&pFormation, 0x15u);
    SDF_VU0__STOREVECTOR(v9 + 3);
    effBTLModelGetMarkPosition2(&pFormation, 0x16u);
    SDF_VU0__STOREVECTOR(v9 + 4);
    effBTLModelGetMarkPosition2(&pFormation, 0x17u);
    SDF_VU0__STOREVECTOR(v9 + 5);
    effBTLModelGetMarkPosition2(&pFormation, 0x18u);
    SDF_VU0__STOREVECTOR(v9 + 6);
    effBTLModelGetMarkPosition2(&pFormation, 0x19u);
    SDF_VU0__STOREVECTOR(v9 + 7);
    effBTLModelGetMarkPosition2(&pFormation, 0x1Au);
    SDF_VU0__STOREVECTOR(v9 + 8);
    effBTLModelGetMarkPosition2(&pFormation, 0x1Bu);
    SDF_VU0__STOREVECTOR(v9 + 9);
    effBTLModelGetMarkPosition2(&pFormation, 0);
    SDF_VU0__STOREVECTOR(&p);
    SDF_VU0__LOADVECTOR_B(p);
    SDF_VU0__LOADVECTOR(*(v9 + 2), 0);
    SDF_VU0__SUBVECTOR();
    v47 = SDF_VU0__GETLENGTH();
    v48 = *(&v3[1].klass->_1.byval_arg.bits + 1);
    if (v48)
    {
      v49 = 0;
      v50 = 0;
      v51 = 0;
      v52 = v47 + -200.0;
      while (1)
      {
        do
        {
          v53 = v3[1].monitor;
          v54 = v50;
          Param = effPCP_ThunderPolyListGetParam(*&v53[2 * v50 + 8]);
          SDF_VU0__LOADVECTOR_B(p);
          v57 = 0;
          for (i = 0; i != 9; ++i)
          {
            name = v3[1].klass->_1.name;
            v61 = *&name[8 * v51 + 32];
            SDF_VU0__LOADVECTOR(*(v61 + v57 * 16 + 32), 0);
            SDF_VU0__ZEROVECTOR_W();
            v63 = v3[1].klass->_1.name;
            v65 = *&v63[8 * v51 + 32];
            sub_854710(v65 + v57 * 16 + 32, 3u);
            SDF_VU0__SCALEVECTOR(v52 + v67);
            SDF_VU0__ADDVECTOR();
            pos = Param->pos;
            SDF_VU0__STOREVECTOR(&pos->m_Items[v57++]);
          }
          v70 = v3[1].monitor;
          v72 = *&v70[2 * v54 + 8];
          effPCP_ThunderPolyListSetColor(&v72, v29);
          effPCP_ThunderPolyListDraw(&v72);
          ++v51;
          v50 = v54 + 1;
        }
        while (v51 != 6);
        if (++v49 == v48)
          break;
        v51 = 0;
      }
    }
    goto LABEL_107;
  }
}

// 0x11e5910
void effPCPBossKAGUInvokeSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossKAGUInvoke_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBossKAGUInvoke_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[2].monitor) = abgr;
}

// 0x11e7560
effPCPBossKAGUThunderbolt_t *effPCPBossKAGUThunderboltCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 *v10;
  effPCPBossKAGUThunderboltParam_t_o *v13;
  effPCPBossKAGUThunderbolt_t_o *v14;
  s64 v15;
  Il2CppObject *v17;
  effPCPBossKAGUThunderbolt_t_o *v18;
  effBTL_t_o *monitor;
  Il2CppObject *hDataa[3];

  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossKAGUThunderbolt_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBossKAGUThunderbolt_t, hDataa);
      if ((hDataa[0] & 1) != 0)
        v8 = hDataa[2];
      else
        v8 = hDataa + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = Allocate(effEveBEDParams_t);
  effEveBEDParams_t___ctor(v10);
  v13 = v5[1].klass;
  v14 = effPCPBossKAGUThunderboltCreate(v13, 0, 0);
  v17 = v5[2].klass;
  v18 = v14;
  hDataa[0] = v17;
  v18->pCrack = effPCPCrackCopy(hDataa, v15, 0);
  sub_854930((v10 + 2), 0);
  sub_854930((v10 + 2), 1u);
  sub_854930((v10 + 2), 2u);
  sub_854930((v10 + 2), 3u);
  sub_854930((v10 + 4), 0);
  sub_854930((v10 + 4), 1u);
  sub_854930((v10 + 4), 2u);
  sub_854930((v10 + 4), 3u);
  v10[6] = 0x42C8000042C80000LL;
  *(v10 + 14) = LODWORD(v18->param->scale);
  *(v10 + 15) = -2139062144;
  monitor = v5[2].monitor;
  v18->hBED = monitor;
  v18->hBEDCut = effEveBEDCutCreate(monitor, 2u, v10);
  return v18;
}

// 0x11e6f90
effPCPBossKAGUThunderbolt_t *effPCPBossKAGUThunderboltCreate(effPCPBossKAGUThunderboltParam_t *pParam, void *pBP, void *pBED) {
  effPCP_ThunderPolyListParam_t_o *v7;
  u64 *v8;
  u64 *v9;
  effPCPCrackParam_t_o *v12;
  Il2CppClass *v14;
  s64 *Interface;
  char *v16;
  s64 *v17;
  effBTL_t_o *v18;
  Il2CppObject *v20[3];
  Il2CppObject *hData;

  v7 = Allocate(effPCP_ThunderPolyListParam_t);
  effPCP_ThunderPolyListParam_t___ctor(v7);
  effPCP_ThunderPolyListParam_t__Clear(v7);
  v8 = Allocate(effEveBEDParams_t);
  effEveBEDParams_t___ctor(v8);
  v9 = Allocate(effPCPBossKAGUThunderbolt_t);
  effPCPBossKAGUThunderbolt_t___ctor(v9);
  v9[2] = pParam;
  v9[7] = 0x8080808000000000LL;
  v7->TPParam = pParam->TPParam;
  v7->point = 4;
  hData = v7;
  v9[3] = effPCP_ThunderPolyListCreate(&hData, 0, 1);
  if (pBP)
  {
    v12 = *(v9[2] + 40);
    v9[4] = effPCPCrackCreate(v12, pBP);
  }
  if (pBED)
  {
    sub_854930((v8 + 2), 0);
    sub_854930((v8 + 2), 1u);
    sub_854930((v8 + 2), 2u);
    sub_854930((v8 + 2), 3u);
    sub_854930((v8 + 4), 0);
    sub_854930((v8 + 4), 1u);
    sub_854930((v8 + 4), 2u);
    sub_854930((v8 + 4), 3u);
    v8[6] = 0x42C8000042C80000LL;
    *(v8 + 14) = *(v9[2] + 48);
    *(v8 + 15) = -2139062144;
    Interface = QueryInterface(pBED, byte);
    if (!Interface)
    {
      sub_8FC2C0(pBED->klass->_1.element_class, v14, v20);
      if ((v20[0] & 1) != 0)
        v16 = v20[2];
      else
        v16 = v20 + 1;
      v17 = sub_8C4940(v16);
    }
    v18 = effEveBEDCreate(Interface);
    v9[5] = v18;
    v9[6] = effEveBEDCutCreate(v18, 2u, v8);
  }
  return v9;
}

// 0x11e7270
effPCPBossKAGUThunderbolt_t *effPCPBossKAGUThunderboltCreatePCF(void **hData, s32 bPos, bool tbldata) {
  dds3EffectPCPData_t_o *v6;
  Il2CppObject *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  struct dds3EffectPCPData_Part_t_array *pcpData;
  Il2CppObject *v14;
  u32 offset;
  Il2CppObject *DataUnityOffSet;
  struct dds3EffectPCPData_Part_t_array *v19;
  Il2CppObject *v20;
  effPCPBossKAGUThunderboltParam_t_o *v21;
  u32 v23;
  Il2CppObject *EffPCPAgiFireballPart;
  struct dds3EffectPCPData_Part_t_array *v25;
  Il2CppObject *v26;
  Il2CppObject *v27;
  Il2CppObject *v31;
  effPCPBossKAGUThunderboltParam_t_c *klass;
  s64 typeHierarchyDepth;
  char *v34;
  s64 *v35;
  s32 pos;
  u64 v38[2];
  char *v39;

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v7->klass->_1.element_class, v8, v38);
      if ((v38[0] & 1) != 0)
        v10 = v39;
      else
        v10 = v38 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v6, Interface, &pos);
  pcpData = v6->pcpData;
  v14 = *hData;
  offset = pcpData->m_Items[0]->offset;
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 43);
  v19 = v6->pcpData;
  v20 = *hData;
  v21 = DataUnityOffSet;
  v23 = v19->m_Items[1]->offset;
  EffPCPAgiFireballPart = GetEffPCPAgiFireballPart(v20, v23 + bPos);
  v25 = v6->pcpData;
  v26 = *hData;
  v27 = EffPCPAgiFireballPart;
  v31 = GetEffPCPAgiFireballPart(v26, v25->m_Items[2]->offset + bPos);
  else if (!v21)
  {
    return effPCPBossKAGUThunderboltCreate(v21, v27, v31);
  }
  klass = v21->klass;
  if (v21->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossKAGUThunderboltParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBossKAGUThunderboltParam_t, v38);
    if ((v38[0] & 1) != 0)
      v34 = v39;
    else
      v34 = v38 + 1;
    v35 = sub_8C4940(v34);
  }
  return effPCPBossKAGUThunderboltCreate(v21, v27, v31);
}

// 0x11e7820
void effPCPBossKAGUThunderboltDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  effEveBEDCutHandle_t_o *v8;
  effBTL_t_o *monitor;
  Il2CppClass *v12;
  Il2CppObject *v13[3];
  Il2CppObject *hDataa;

  hDataa = 0;
  v12 = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossKAGUThunderbolt_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBossKAGUThunderbolt_t, v13);
      if ((v13[0] & 1) != 0)
        v6 = v13[2];
      else
        v6 = v13 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = v3[3].klass;
  effEveBEDCutDelete(v8);
  monitor = v3[2].monitor;
  if (!monitor->CutCount)
  {
    effEveBEDDelete(monitor);
  }
  hDataa = v3[1].monitor;
  effPCP_ThunderPolyListDelete(&hDataa);
  v12 = v3[2].klass;
  effPCPCrackDelete(&v12);
}

// 0x11e8010
void effPCPBossKAGUThunderboltDraw(void **hData) {
  Il2CppObject *v3;
  f32 x;
  f32 y;
  f32 z;
  f32 w;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  u64 v14[3];
  UnityEngine_Vector4_o v15;

  v3 = *hData;
  else
  {
    x = effPCPBossKAGUAttackConvergePoint.x;
    y = effPCPBossKAGUAttackConvergePoint.y;
    z = effPCPBossKAGUAttackConvergePoint.z;
    w = effPCPBossKAGUAttackConvergePoint.w;
    if (!v3)
      goto LABEL_12;
  }
  klass = v3->klass;
  if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossKAGUThunderbolt_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBossKAGUThunderbolt_t, v14);
    if ((v14[0] & 1) != 0)
      v11 = v14[2];
    else
      v11 = v14 + 1;
    v12 = sub_8C4940(v11);
  }
LABEL_12:
  v15.x = x;
  v15.y = y;
  v15.z = z;
  v15.w = w;
  effPCPBossKAGUThunderboltDrawSub(v3, v15);
}

// 0x11e79c0
void effPCPBossKAGUThunderboltDrawSub(effPCPBossKAGUThunderbolt_t *pPCPBossKAGUThunderbolt, sdfVector4_t pConvPos) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  u64 *v8;
  u64 *v9;
  struct effPCPBossKAGUThunderboltParam_t_o *param;
  s32 frame;
  s32 fade_in;
  s32 life;
  s32 fade_out;
  f32 v18;
  f32 v19;
  f32 v20;
  f32 v21;
  effPartHandle_t_o **p_hHelper;
  Il2CppObject *Handle;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  sdfModelRootNode_t_o *v29;
  s32 v30;
  f32 v31;
  f32 v32;
  nbMainProcessData_t_o *MainProcessData;
  u64 v34;
  struct nbFormation_t_array *form;
  u32 ID;
  f32 v39;
  u32 v40;
  effPCP_ThunderPolyListParam_t_o *v42;
  struct UnityEngine_Vector4_array *pos;
  struct UnityEngine_Vector4_array *v45;
  struct UnityEngine_Vector4_array *v47;
  struct UnityEngine_Vector4_array *v49;
  char *v51;
  s64 *v52;
  Il2CppObject *pCrack;
  Il2CppObject *hData;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v56;
  nbFormation_t_o *pFormation;
  u64 v58[3];
  UnityEngine_Vector4_o v59;
  UnityEngine_Vector4_o v60;

  w = pConvPos.w;
  z = pConvPos.z;
  y = pConvPos.y;
  x = pConvPos.x;
  pCrack = 0;
  hData = 0;
  pFormation = 0;
  v8 = Allocate(effEveBEDParams_t);
  effEveBEDParams_t___ctor(v8);
  v9 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v9);
  *&v56.x = 0;
  *&v56.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  else if (effBTLSkillCheckRun())
  {
    goto LABEL_6;
  }
  MainProcessData = nbGetMainProcessData();
  v34 = 0;
  while (1)
  {
    form = MainProcessData->form;
    pFormation = form->m_Items[v34];
    if ((~pFormation->stat & 3) == 0)
    {
      ID = effBTLModelGetID(&pFormation);
      if (ID == 264 || ID == 293)
        break;
    }
    if (v34++ > 0x1E)
      return;
  }
  if (pFormation)
  {
LABEL_10:
    param = pPCPBossKAGUThunderbolt->param;
    frame = pPCPBossKAGUThunderbolt->frame;
    life = param->life;
    fade_in = param->fade_in;
    fade_out = param->fade_out;
    hData = pPCPBossKAGUThunderbolt->pCrack;
    v18 = param->pos.x;
    v19 = param->pos.y;
    v21 = param->pos.z;
    v20 = param->pos.w;
    v59.x = v18;
    v59.y = v19;
    v59.z = v21;
    v59.w = v20;
    effPCPCrackSetPosition(&hData, v59);
    effPCPCrackSetColor(&hData, pPCPBossKAGUThunderbolt->abgr);
    pCrack = pPCPBossKAGUThunderbolt->pCrack;
    effPCPCrackDraw(&pCrack);
    p_hHelper = &pPCPBossKAGUThunderbolt->pCrack->hHelper;
    Handle = dds3EffectPartGetHandle(p_hHelper);
    klass = Handle->klass;
    if (Handle->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, v58);
      if ((v58[0] & 1) != 0)
        v51 = v58[2];
      else
        v51 = v58 + 1;
      v52 = sub_8C4940(v51);
    }
    v29 = Handle[4].klass;
    sdfModelGetMarkPosUnity(v29, 0);
    SDF_VU0__STOREVECTOR(&p);
    v30 = life - frame;
    if (life <= frame)
      goto LABEL_57;
    if (frame < fade_in && fade_in)
    {
      v31 = frame;
      v32 = fade_in;
    }
    else
    {
      v39 = 1.0;
      if (v30 > fade_out || !fade_out)
        goto LABEL_45;
      v31 = v30;
      v32 = fade_out;
    }
    v39 = v31 / v32;
LABEL_45:
    v40 = effColorBlend(pPCPBossKAGUThunderbolt->abgr & 0xFFFFFF, pPCPBossKAGUThunderbolt->abgr, v39);
    sub_854930((v8 + 4), 0);
    sub_854930((v8 + 4), 1u);
    sub_854930((v8 + 4), 2u);
    sub_854930((v8 + 4), 3u);
    v8[6] = 0x42C8000042C80000LL;
    *(v8 + 14) = LODWORD(pPCPBossKAGUThunderbolt->param->scale);
    *(v8 + 15) = v40;
    sub_854710(&p, 0);
    sub_854930((v8 + 2), 0);
    sub_854710(&p, 1u);
    sub_854930((v8 + 2), 1u);
    sub_854710(&p, 2u);
    sub_854930((v8 + 2), 2u);
    effEveBEDCutSetParams(&pPCPBossKAGUThunderbolt->hBEDCut, v8);
    effEveBEDCutDraw(&pPCPBossKAGUThunderbolt->hBEDCut);
    SDF_VU0__LOADVECTOR(pFormation->pos);
    v60.x = x;
    v60.y = y;
    v60.z = z;
    v60.w = w;
    SDF_VU0__LOADVECTOR_B(v60);
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(&v56);
    v42 = effPCP_ThunderPolyListGetParam(pPCPBossKAGUThunderbolt->pTPolyList);
    SDF_VU0__LOADVECTOR(v56);
    SDF_VU0__COPYVECTOR_A_TO_C();
    pos = v42->pos;
    SDF_VU0__STOREVECTOR(pos->m_Items);
    SDF_VU0__LOADVECTOR_B(p);
    SDF_VU0__INTERPOLATE(0.33);
    v45 = v42->pos;
    SDF_VU0__STOREVECTOR(&v45->m_Items[1]);
    SDF_VU0__COPYVECTOR_C_TO_A();
    SDF_VU0__INTERPOLATE(0.66);
    v47 = v42->pos;
    SDF_VU0__STOREVECTOR(&v47->m_Items[2]);
    v49 = v42->pos;
    SDF_VU0__STOREVECTOR_B(&v49->m_Items[3]);
    hData = pPCPBossKAGUThunderbolt->pTPolyList;
    effPCP_ThunderPolyListSetColor(&hData, v40);
    effPCP_ThunderPolyListDraw(&hData);
LABEL_57:
    ++pPCPBossKAGUThunderbolt->frame;
  }
}

// 0x11e8290
void effPCPBossKAGUThunderboltSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossKAGUThunderbolt_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBossKAGUThunderbolt_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[3].monitor) = abgr;
}

// 0x11e8170
void effPCPBossKAGUThunderboltSetPosition(void **hData, sdfVector4_t pPos) {
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
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossKAGUThunderbolt_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBossKAGUThunderbolt_t, v12);
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

// 0x11eb570
effPCPBossMETATOBeam_t *effPCPBossMETATOBeamCopy(void **hData, s32 bPos, bool tbldata) {
  effPCPBossMETATOBeam_t_c *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v8;
  char *v10;
  s64 *v11;
  u64 v12[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossMETATOBeam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBossMETATOBeam_t, v12);
    if ((v12[0] & 1) != 0)
      v10 = v12[2];
    else
      v10 = v12 + 1;
    v11 = sub_8C4940(v10);
  }
  v8 = (*hData)[1].klass;
  return effPCPBossMETATOBeamCreate(v8, v5);
}

// 0x11eb190
effPCPBossMETATOBeam_t *effPCPBossMETATOBeamCreate(effPCPBossMETATOBeamParam_t *pParam) {
  effPCP_ThunderPolyListParam_t_o *v3;
  u64 *v4;
  u64 v5;
  s64 *v6;
  s64 *v7;
  u64 v9;
  s64 *v10;
  s64 *v11;
  Il2CppObject *hData;

  v3 = Allocate(effPCP_ThunderPolyListParam_t);
  effPCP_ThunderPolyListParam_t___ctor(v3);
  effPCP_ThunderPolyListParam_t__Clear(v3);
  v4 = Allocate(effPCPBossMETATOBeam_t);
  effPCPBossMETATOBeam_t___ctor(v4);
  v4[2] = pParam;
  v4[4] = 0x8080808000000000LL;
  v3->TPParam = pParam->TPParam;
  v3->point = 4;
  hData = v3;
  v5 = v4[3];
  v6 = effPCP_ThunderPolyListCreate(&hData, 0, 1);
  v7 = v6;
  *(v5 + 32) = v7;
  v9 = v4[3];
  v10 = effPCP_ThunderPolyListCreate(&hData, 0, 1);
  v11 = v10;
  *(v9 + 40) = v11;
  return v4;
}

// 0x11eb070
effPCPBossMETATOBeam_t *effPCPBossMETATOBeamCreateP(void **pData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v11[3];

  v5 = *pData;
  else if (!v5)
  {
    return effPCPBossMETATOBeamCreate(v5, *&bPos);
  }
  klass = v5->klass;
  if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossMETATOBeamParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBossMETATOBeamParam_t, v11);
    if ((v11[0] & 1) != 0)
      v8 = v11[2];
    else
      v8 = v11 + 1;
    v9 = sub_8C4940(v8);
  }
  return effPCPBossMETATOBeamCreate(v5, *&bPos);
}

// 0x11eb330
effPCPBossMETATOBeam_t *effPCPBossMETATOBeamCreatePCF(void **hData, s32 bPos, bool tbldata) {
  dds3EffectPCPData_t_o *v6;
  Il2CppObject *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  struct dds3EffectPCPData_Part_t_array *pcpData;
  Il2CppObject *v14;
  u32 offset;
  effPCPBossMETATOBeamParam_t_c *v17;
  Il2CppObject *DataUnityOffSet;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v21;
  s64 *v22;
  u64 v24[2];
  char *v25;
  s32 pos;

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v7->klass->_1.element_class, v8, v24);
      if ((v24[0] & 1) != 0)
        v10 = v25;
      else
        v10 = v24 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v6, Interface, &pos);
  pcpData = v6->pcpData;
  v14 = *hData;
  offset = pcpData->m_Items[0]->offset;
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 47);
  else if (!DataUnityOffSet)
  {
    return effPCPBossMETATOBeamCreate(DataUnityOffSet, v17);
  }
  klass = DataUnityOffSet->klass;
  if (DataUnityOffSet->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossMETATOBeamParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBossMETATOBeamParam_t, v24);
    if ((v24[0] & 1) != 0)
      v21 = v25;
    else
      v21 = v24 + 1;
    v22 = sub_8C4940(v21);
  }
  return effPCPBossMETATOBeamCreate(DataUnityOffSet, v17);
}

// 0x11eb680
void effPCPBossMETATOBeamDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  u32 *monitor;
  u32 *v8;
  char *v10;
  s64 *v11;
  Il2CppObject *v12;
  u64 v13[3];

  v12 = 0;
  v3 = *hData;
  klass = v3->klass;
  if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossMETATOBeam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBossMETATOBeam_t, v13);
    if ((v13[0] & 1) != 0)
      v10 = v13[2];
    else
      v10 = v13 + 1;
    v11 = sub_8C4940(v10);
  }
  monitor = v3[1].monitor;
  v12 = *(monitor + 5);
  effPCP_ThunderPolyListDelete(&v12);
  v8 = v3[1].monitor;
  v12 = *(v8 + 4);
  effPCP_ThunderPolyListDelete(&v12);
}

// 0x11eb7d0
void effPCPBossMETATOBeamDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppClass *v8;
  s32 v9;
  s32 v10;
  signed s32 bits;
  s32 data;
  s32 v14;
  f32 v15;
  f32 v16;
  nbMainProcessData_t_o *MainProcessData;
  u64 v19;
  struct nbFormation_t_array *form;
  u32 ID;
  f32 v24;
  u32 v26;
  void *monitor;
  effPCP_ThunderPolyListParam_t_o *Param;
  struct UnityEngine_Vector4_array *pos;
  struct UnityEngine_Vector4_array *v32;
  struct UnityEngine_Vector4_array *v34;
  struct UnityEngine_Vector4_array *v36;
  u32 *v38;
  void *v41;
  effPCP_ThunderPolyListParam_t_o *v43;
  struct UnityEngine_Vector4_array *v44;
  struct UnityEngine_Vector4_array *v46;
  struct UnityEngine_Vector4_array *v48;
  struct UnityEngine_Vector4_array *v50;
  u32 *v52;
  Il2CppObject *v54;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *v56[3];
  nbFormation_t_o *pFormation;

  pFormation = 0;
  *&p.x = 0;
  *&p.z = 0;
  v54 = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossMETATOBeam_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBossMETATOBeam_t, v56);
      if ((v56[0] & 1) != 0)
        v6 = v56[2];
      else
        v6 = v56 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  pFormation = 0;
  *&p.x = 0;
  *&p.z = 0;
  v8 = v3[1].klass;
  v9 = v3[2].klass;
  bits = v8->_1.byval_arg.bits;
  v10 = *(&v8->_1.byval_arg.bits + 1);
  data = v8->_1.this_arg.data;
  else if (effBTLSkillCheckRun())
  {
    goto LABEL_13;
  }
  MainProcessData = nbGetMainProcessData();
  v19 = 0;
  while (1)
  {
    form = MainProcessData->form;
    pFormation = form->m_Items[v19];
    if ((~pFormation->stat & 3) == 0)
    {
      ID = effBTLModelGetID(&pFormation);
      if (ID == 193 || ID == 342)
        break;
    }
    if (v19++ > 0x1E)
      return;
  }
  if (pFormation)
  {
LABEL_17:
    v14 = bits - v9;
    if (bits <= v9)
    {
LABEL_72:
      ++LODWORD(v3[2].klass);
      return;
    }
    if (v9 < v10 && v10)
    {
      v15 = v9;
      v16 = v10;
    }
    else
    {
      v24 = 1.0;
      if (v14 > data || !data)
        goto LABEL_41;
      v15 = v14;
      v16 = data;
    }
    v24 = v15 / v16;
LABEL_41:
    v26 = effColorBlend(HIDWORD(v3[2].klass) & 0xFFFFFF, HIDWORD(v3[2].klass), v24, 0);
    effBTLModelGetMarkPosition2(&pFormation, 0x14u);
    SDF_VU0__STOREVECTOR(&p);
    monitor = v3[1].monitor;
    Param = effPCP_ThunderPolyListGetParam(*(monitor + 4), 0);
    SDF_VU0__LOADVECTOR(p);
    SDF_VU0__COPYVECTOR_A_TO_C();
    pos = Param->pos;
    SDF_VU0__STOREVECTOR(pos->m_Items);
    SDF_VU0__LOADVECTOR_B(*&v3[1].klass->_1.name);
    SDF_VU0__INTERPOLATE(0.33);
    v32 = Param->pos;
    SDF_VU0__STOREVECTOR(&v32->m_Items[1]);
    SDF_VU0__COPYVECTOR_C_TO_A();
    SDF_VU0__INTERPOLATE(0.66);
    v34 = Param->pos;
    SDF_VU0__STOREVECTOR(&v34->m_Items[2]);
    v36 = Param->pos;
    SDF_VU0__STOREVECTOR_B(&v36->m_Items[3]);
    v38 = v3[1].monitor;
    v54 = *(v38 + 4);
    effPCP_ThunderPolyListSetColor(&v54, v26);
    effPCP_ThunderPolyListDraw(&v54);
    effBTLModelGetMarkPosition2(&pFormation, 0x15u);
    SDF_VU0__STOREVECTOR(&p);
    v41 = v3[1].monitor;
    v43 = effPCP_ThunderPolyListGetParam(*(v41 + 5), 0);
    SDF_VU0__LOADVECTOR(p);
    SDF_VU0__COPYVECTOR_A_TO_C();
    v44 = v43->pos;
    SDF_VU0__STOREVECTOR(v44->m_Items);
    SDF_VU0__LOADVECTOR_B(*&v3[1].klass->_1.name);
    SDF_VU0__INTERPOLATE(0.33);
    v46 = v43->pos;
    SDF_VU0__STOREVECTOR(&v46->m_Items[1]);
    SDF_VU0__COPYVECTOR_C_TO_A();
    SDF_VU0__INTERPOLATE(0.66);
    v48 = v43->pos;
    SDF_VU0__STOREVECTOR(&v48->m_Items[2]);
    v50 = v43->pos;
    SDF_VU0__STOREVECTOR_B(&v50->m_Items[3]);
    v52 = v3[1].monitor;
    v54 = *(v52 + 5);
    effPCP_ThunderPolyListSetColor(&v54, v26);
    effPCP_ThunderPolyListDraw(&v54);
    goto LABEL_72;
  }
}

// 0x11ebf00
void effPCPBossMETATOBeamSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossMETATOBeam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBossMETATOBeam_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[2].klass) = abgr;
}

// 0x11ebde0
void effPCPBossMETATOBeamSetPosition(void **hData, sdfVector4_t pPos) {
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
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossMETATOBeam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBossMETATOBeam_t, v12);
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

// 0x11dd380
effPCPBossONGY2_t *effPCPBossONGY2Create(effPCPBossONGY2Param_t *pParam) {
  u64 *v3;
  sdfMat_t_o *v5;

  v3 = Allocate(effPCPBossONGY2_t);
  effPCPBossONGY2_t___ctor(v3);
  v3[2] = pParam;
  v3[4] = 0;
  v5 = sdfMatNew();
  v3[3] = v5;
  sdfMatSetConstant(v5, 1.0);
  effPCPBossONGY_PolyParm->attr = 0x4000;
  effPCPBossONGY_PolyParm->faceIndex = effPCPBossONGY_FaceIndex;
  return v3;
}

// 0x11dd460
void effPCPBossONGY2Delete(effPCPBossONGY2_t *pPCPBossONGY2) {

}

// 0x11dd4d0
void effPCPBossONGY2Draw(effPCPBossONGY2_t **pPCPBossONGY2) {
  f32 v3;
  f32 v4;
  f32 v5;
  UnityEngine_GameObject_o *modelobj;
  u32 v8;
  u32 v9;
  nbFormation_t_o *form;

  v3 = (*pPCPBossONGY2)->frame / -17.0;
  form = (*pPCPBossONGY2)->param->pFormation;
  v4 = v3 + 1.0;
  v5 = fmaxf(v4, 0.0);
  nbFormDispOn2(&form);
  modelobj = form->modelobj;
  mdlRasterLevel(modelobj, (1.0 - v5) * 0.5, 0);
  v8 = vcvts_n_s32_f32(v5, 7u);
  v9 = vcvts_n_u32_f32(v5, 7u);
  if ((v5 * 128.0) < 0.0)
    v9 = v8;
  SetTransparent(form->modelobj, v9 << 24, 0.0, 0);
  ++(*pPCPBossONGY2)->frame;
}

// 0x11dd600
s32 effPCPBossONGY2GetLength(void) {
  return 27;
}

// 0x11dd210
effPCPBossONGY_t *effPCPBossONGYCreate(effPCPBossONGYParam_t *pParam) {
  u64 *v3;
  sdfMat_t_o *v5;

  v3 = Allocate(effPCPBossONGY_t);
  effPCPBossONGY_t___ctor(v3);
  v3[2] = pParam;
  v3[4] = 0;
  v5 = sdfMatNew();
  v3[3] = v5;
  sdfMatSetConstant(v5, 1.0);
  effPCPBossONGY_PolyParm->attr = 0x4000;
  effPCPBossONGY_PolyParm->faceIndex = effPCPBossONGY_FaceIndex;
  return v3;
}

// 0x11dd2f0
void effPCPBossONGYDelete(effPCPBossONGY_t *pPCPBossONGY) {

}

// 0x11dd360
void effPCPBossONGYDraw(effPCPBossONGY_t *pPCPBossONGY) {
  ;
}

// 0x11dd370
s32 effPCPBossONGYGetLength(void) {
  return 22;
}

// 0x11dd160
void effPCPBossONGYModelTexRender(sdfVector4_t pTarget, f32 width, nbFormation_t *pFormation) {
  ;
}

// 0x11dd170
bool effPCPBossONGYModelTexRenderCheck(void) {
  u32 KernelCount;

  KernelCount = dds3GetKernelCount();
  return effPCPBossONGY_RFrame != KernelCount;
}

// 0x11dd150
void effPCPBossONGYTexRenderEnd(void) {
  ;
}

// 0x11dd140
void effPCPBossONGYTexRenderStart(void) {
  ;
}

// 0x11e4160
effPCPBossThunderbolt_t *effPCPBossThunderboltCopy(void **hData, s32 bPos, bool tbldata) {
  effPCPBossThunderbolt_t_c *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v8;
  char *v10;
  s64 *v11;
  u64 v12[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossThunderbolt_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBossThunderbolt_t, v12);
    if ((v12[0] & 1) != 0)
      v10 = v12[2];
    else
      v10 = v12 + 1;
    v11 = sub_8C4940(v10);
  }
  v8 = (*hData)[1].klass;
  return effPCPBossThunderboltCreate(v8, v5);
}

// 0x11e3de0
effPCPBossThunderbolt_t *effPCPBossThunderboltCreate(effPCPBossThunderboltParam_t *pParam) {
  effPCP_ThunderPolyListParam_t_o *v3;
  u64 *v4;
  u64 *v5;
  s64 *v6;
  s64 *v7;
  Il2CppObject *hData;

  v3 = Allocate(effPCP_ThunderPolyListParam_t);
  effPCP_ThunderPolyListParam_t___ctor(v3);
  effPCP_ThunderPolyListParam_t__Clear(v3);
  v4 = Allocate(effPCPBossThunderbolt_t);
  effPCPBossThunderbolt_t___ctor(v4);
  v4[2] = pParam;
  v4[4] = 0x8080808000000000LL;
  v3->TPParam = pParam->TPParam;
  v3->point = 4;
  hData = v3;
  v5 = NewSpecific(effPCP_ThunderPolyList_t, 1u);
  v4[3] = v5;
  v6 = effPCP_ThunderPolyListCreate(&hData, 0, 1);
  v7 = v6;
  v5[4] = v7;
  return v4;
}

// 0x11e3cc0
effPCPBossThunderbolt_t *effPCPBossThunderboltCreateP(void **pData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v11[3];

  v5 = *pData;
  else if (!v5)
  {
    return effPCPBossThunderboltCreate(v5, *&bPos);
  }
  klass = v5->klass;
  if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossThunderboltParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBossThunderboltParam_t, v11);
    if ((v11[0] & 1) != 0)
      v8 = v11[2];
    else
      v8 = v11 + 1;
    v9 = sub_8C4940(v8);
  }
  return effPCPBossThunderboltCreate(v5, *&bPos);
}

// 0x11e3f20
effPCPBossThunderbolt_t *effPCPBossThunderboltCreatePCF(void **hData, s32 bPos, bool tbldata) {
  dds3EffectPCPData_t_o *v6;
  Il2CppObject *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  struct dds3EffectPCPData_Part_t_array *pcpData;
  Il2CppObject *v14;
  u32 offset;
  effPCPBossThunderboltParam_t_c *v17;
  Il2CppObject *DataUnityOffSet;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v21;
  s64 *v22;
  u64 v24[2];
  char *v25;
  s32 pos;

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v7->klass->_1.element_class, v8, v24);
      if ((v24[0] & 1) != 0)
        v10 = v25;
      else
        v10 = v24 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v6, Interface, &pos);
  pcpData = v6->pcpData;
  v14 = *hData;
  offset = pcpData->m_Items[0]->offset;
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 40);
  else if (!DataUnityOffSet)
  {
    return effPCPBossThunderboltCreate(DataUnityOffSet, v17);
  }
  klass = DataUnityOffSet->klass;
  if (DataUnityOffSet->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossThunderboltParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBossThunderboltParam_t, v24);
    if ((v24[0] & 1) != 0)
      v21 = v25;
    else
      v21 = v24 + 1;
    v22 = sub_8C4940(v21);
  }
  return effPCPBossThunderboltCreate(DataUnityOffSet, v17);
}

// 0x11e4270
void effPCPBossThunderboltDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  u64 *monitor;
  s64 v7;
  u64 v8;
  char *v10;
  s64 *v11;
  Il2CppObject *v12[3];
  Il2CppObject *hDataa;

  hDataa = 0;
  v3 = *hData;
  klass = v3->klass;
  if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossThunderbolt_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBossThunderbolt_t, v12);
    if ((v12[0] & 1) != 0)
      v10 = v12[2];
    else
      v10 = v12 + 1;
    v11 = sub_8C4940(v10);
  }
  monitor = v3[1].monitor;
  v7 = monitor[3];
  if (v7 >= 1)
  {
    v8 = 0;
    do
    {
      hDataa = monitor[v8 + 4];
      effPCP_ThunderPolyListDelete(&hDataa);
      monitor = v3[1].monitor;
      LODWORD(v7) = *(monitor + 6);
      ++v8;
    }
    while (v8 < v7);
  }
}

// 0x11e43c0
void effPCPBossThunderboltDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  nbMainProcessData_t_o *MainProcessData;
  u64 v24;
  struct nbFormation_t_array *form;
  u32 ID;
  Il2CppObject *v29;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *v31[3];
  nbFormation_t_o *pFormation;

  pFormation = 0;
  *&p.x = 0;
  *&p.z = 0;
  v29 = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossThunderbolt_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBossThunderbolt_t, v31);
      if ((v31[0] & 1) != 0)
        v6 = v31[2];
      else
        v6 = v31 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  pFormation = 0;
  *&p.x = 0;
  *&p.z = 0;
  else if (effBTLSkillCheckRun())
  {
    goto LABEL_13;
  }
  MainProcessData = nbGetMainProcessData();
  v24 = 0;
  while (1)
  {
    form = MainProcessData->form;
    pFormation = form->m_Items[v24];
    if ((~pFormation->stat & 3) == 0)
    {
      ID = effBTLModelGetID(&pFormation);
      if (ID == 259 || ID == 292)
        break;
    }
    if (v24++ > 0x1E)
      return;
  }
  if (pFormation)
    goto LABEL_17;
}

// 0x11e48d0
void effPCPBossThunderboltSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossThunderbolt_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBossThunderbolt_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[2].klass) = abgr;
}

// 0x11e47b0
void effPCPBossThunderboltSetPosition(void **hData, sdfVector4_t pPos) {
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
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossThunderbolt_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBossThunderbolt_t, v12);
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

// 0x11eabe0
effPCPCrack_t *effPCPCrack2Copy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  effPCPCrack_t_o *result;
  s64 v11;
  struct effPCPCrackPart_t_array *pPart;
  u64 v13;
  struct effPCPCrackPart_t_array *v15;
  u64 *monitor;
  s64 v18;
  struct effPCPCrackPart_t_array *v20;
  u64 *v22;
  s64 v23;
  s64 v25;
  Il2CppObject *hDataa[3];

  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPCrack_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPCrack_t, hDataa);
      if ((hDataa[0] & 1) != 0)
        v8 = hDataa[2];
      else
        v8 = hDataa + 1;
      v9 = sub_8C4940(v8);
    }
  }
LABEL_14:
  hDataa[0] = v5;
  result = effPCPCrackCopy(hDataa, bPos, 0);
  if (result->MarkCount >= 1)
  {
    v11 = 4;
    do
    {
      pPart = result->pPart;
      v13 = v11 - 4;
      *(*(&pPart->obj.klass + v11) + 40LL) = 0;
      v15 = result->pPart;
      monitor = v5[1].monitor;
      v18 = *(&v15->obj.klass + v11);
      *(v18 + 44) = *(monitor[v11] + 44LL);
      v20 = result->pPart;
      v22 = v5[1].monitor;
      v23 = *(&v20->obj.klass + v11);
      *(v23 + 48) = *(v22[v11] + 48LL);
      v25 = v11 - 3;
      ++v11;
    }
    while (v25 < result->MarkCount);
  }
  return result;
}

// 0x11ea7f0
effPCPCrack_t *effPCPCrack2Create(effPCPCrack2Param_t *pParam, void *pPB) {
  effPCPCrackParam_t_o *crack;
  effPCPCrack_t_o *result;
  s64 v7;
  struct effPCPCrackPart_t_array *pPart;
  u64 v9;
  struct effPCPCrackPart_t_array *v11;
  struct effPCPCrackPart_t_array *v13;
  s64 v15;

  crack = pParam->crack;
  result = effPCPCrackCreate(crack, pPB);
  if (result->MarkCount >= 1)
  {
    v7 = 4;
    do
    {
      pPart = result->pPart;
      v9 = v7 - 4;
      *(*(&pPart->obj.klass + v7) + 40LL) = 0;
      v11 = result->pPart;
      *(*(&v11->obj.klass + v7) + 44LL) = pParam->rotate_w;
      v13 = result->pPart;
      *(*(&v13->obj.klass + v7) + 48LL) = pParam->rotate_s;
      v15 = v7 - 3;
      ++v7;
    }
    while (v15 < result->MarkCount);
  }
  return result;
}

// 0x11ea930
effPCPCrack_t *effPCPCrack2CreatePCF(void **hData, s32 bPos, bool tbldata) {
  dds3EffectPCPData_t_o *v6;
  Il2CppObject *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  struct dds3EffectPCPData_Part_t_array *pcpData;
  Il2CppObject *v14;
  u32 offset;
  Il2CppObject *DataUnityOffSet;
  struct dds3EffectPCPData_Part_t_array *v19;
  Il2CppObject *v20;
  effPCPCrack2Param_t_o *v21;
  u32 v23;
  Il2CppObject *EffPCPAgiFireballPart;
  effPCPCrack2Param_t_c *klass;
  s64 typeHierarchyDepth;
  char *v29;
  s64 *v30;
  u64 v32[2];
  char *v33;
  s32 pos;

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v7->klass->_1.element_class, v8, v32);
      if ((v32[0] & 1) != 0)
        v10 = v33;
      else
        v10 = v32 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v6, Interface, &pos);
  pcpData = v6->pcpData;
  v14 = *hData;
  offset = pcpData->m_Items[0]->offset;
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 46);
  v19 = v6->pcpData;
  v20 = *hData;
  v21 = DataUnityOffSet;
  v23 = v19->m_Items[1]->offset;
  EffPCPAgiFireballPart = GetEffPCPAgiFireballPart(v20, v23 + bPos);
  else if (!v21)
  {
    return effPCPCrack2Create(v21, EffPCPAgiFireballPart);
  }
  klass = v21->klass;
  if (v21->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPCrack2Param_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPCrack2Param_t, v32);
    if ((v32[0] & 1) != 0)
      v29 = v33;
    else
      v29 = v32 + 1;
    v30 = sub_8C4940(v29);
  }
  return effPCPCrack2Create(v21, EffPCPAgiFireballPart);
}

// 0x11eae50
void effPCPCrack2Delete(void **hData) {
  Il2CppObject **v3;

  else
  {
    v3 = hData;
  }
  effPCPCrackDelete(v3);
}

// 0x11eaed0
void effPCPCrack2Draw(void **hData) {
  Il2CppObject **v3;

  else
  {
    v3 = hData;
  }
  effPCPCrackDraw(v3);
}

// 0x11eaff0
void effPCPCrack2SetColor(void **hData, u32 abgr) {
  effPCPCrackSetColor(hData, abgr);
}

// 0x11eaf50
void effPCPCrack2SetPosition(void **hData, sdfVector4_t pPos) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  UnityEngine_Vector4_o v8;

  w = pPos.w;
  z = pPos.z;
  y = pPos.y;
  x = pPos.x;
  v8.z = z;
  v8.w = w;
  v8.x = x;
  v8.y = y;
  effPCPCrackSetPosition(hData, v8);
}

// 0x11def30
effPCPCrack_t *effPCPCrackCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 *v10;
  u64 *v11;
  effPCPCrack_t_o *v15[3];
  effPCPCrack_t_o *pPCPCrack;

  pPCPCrack = 0;
  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPCrack_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPCrack_t, v15);
      if ((v15[0] & 1) != 0)
        v8 = v15[2];
      else
        v8 = v15 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = Allocate(effPCPCrack_t);
  effPCPCrack_t___ctor(v10);
  pPCPCrack = v10;
  v11 = Allocate(effPCPCrackParam_t);
  effPCPCrackParam_t___ctor(v11);
  v10[2] = v11;
  effPCPCrackParam_t__pClone(v5[1].klass, v10 + 2);
  v10[6] = 0x8080808000000000LL;
  v10[8] = dds3EffectPartCopy(&v5[4], 0, 0);
  effPCPCrackInit(&pPCPCrack);
  return pPCPCrack;
}

// 0x11df0e0
effPCPCrack_t *effPCPCrackCopyO(effPCPCrack_t *pPCPCrackSrc) {
  Il2CppObject *hData;

  hData = pPCPCrackSrc;
  return effPCPCrackCopy(&hData, 0);
}

// 0x11deb60
effPCPCrack_t *effPCPCrackCreate(effPCPCrackParam_t *pParam, void *pPB) {
  u64 *v5;
  u64 *v6;
  effPCPCrack_t_o *pPCPCrack;

  v5 = Allocate(effPCPCrack_t);
  effPCPCrack_t___ctor(v5);
  pPCPCrack = v5;
  v6 = Allocate(effPCPCrackParam_t);
  effPCPCrackParam_t___ctor(v6);
  v5[2] = v6;
  effPCPCrackParam_t__pClone(pParam, v5 + 2);
  v5[6] = 0x8080808000000000LL;
  v5[8] = dds3EffectPartCreate(3u, pPB, 0, 0);
  effPCPCrackInit(&pPCPCrack);
  return pPCPCrack;
}

// 0x11dec80
effPCPCrack_t *effPCPCrackCreatePCF(void **hData, s32 bPos, bool tbldata) {
  dds3EffectPCPData_t_o *v6;
  Il2CppObject *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  struct dds3EffectPCPData_Part_t_array *pcpData;
  Il2CppObject *v14;
  u32 offset;
  Il2CppObject *DataUnityOffSet;
  struct dds3EffectPCPData_Part_t_array *v19;
  Il2CppObject *v20;
  effPCPCrackParam_t_o *v21;
  u32 v23;
  Il2CppObject *EffPCPAgiFireballPart;
  effPCPCrackParam_t_c *klass;
  s64 typeHierarchyDepth;
  char *v29;
  s64 *v30;
  u64 v32[2];
  char *v33;
  s32 pos;

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v7->klass->_1.element_class, v8, v32);
      if ((v32[0] & 1) != 0)
        v10 = v33;
      else
        v10 = v32 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v6, Interface, &pos);
  pcpData = v6->pcpData;
  v14 = *hData;
  offset = pcpData->m_Items[0]->offset;
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 37);
  v19 = v6->pcpData;
  v20 = *hData;
  v21 = DataUnityOffSet;
  v23 = v19->m_Items[1]->offset;
  EffPCPAgiFireballPart = GetEffPCPAgiFireballPart(v20, v23 + bPos);
  else if (!v21)
  {
    return effPCPCrackCreate(v21, EffPCPAgiFireballPart);
  }
  klass = v21->klass;
  if (v21->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPCrackParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPCrackParam_t, v32);
    if ((v32[0] & 1) != 0)
      v29 = v33;
    else
      v29 = v32 + 1;
    v30 = sub_8C4940(v29);
  }
  return effPCPCrackCreate(v21, EffPCPAgiFireballPart);
}

// 0x11df160
void effPCPCrackDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s64 v8;
  u64 *monitor;
  u64 *v11;
  dds3FlashPolyList_t_o *v13;
  s64 v14;
  dds3FlashPolyList_t_o *hPoly[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPCrack_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPCrack_t, hPoly);
      if ((hPoly[0] & 1) != 0)
        v6 = hPoly[2];
      else
        v6 = hPoly + 1;
      v7 = sub_8C4940(v6);
    }
  }
  if (SLODWORD(v3[2].monitor) >= 1)
  {
    v8 = 4;
    while (1)
    {
      monitor = v3[1].monitor;
      if (!monitor)
        goto LABEL_28;
      if (!monitor[v8])
        goto LABEL_28;
      v11 = v3[1].monitor;
      v13 = *(v11[v8] + 16LL);
        break;
      hPoly[0] = v13;
      if ((byte_3F59009 & 1) == 0)
        goto LABEL_23;
LABEL_24:
      pMeshDelete(hPoly);
LABEL_28:
      v14 = v8 - 3;
      ++v8;
      if (v14 >= SLODWORD(v3[2].monitor))
        goto LABEL_29;
    }
    hPoly[0] = *(v11[v8] + 16LL);
    if ((byte_3F59009 & 1) != 0)
      goto LABEL_24;
LABEL_23:
    goto LABEL_24;
  }
LABEL_29:
  dds3TrackPolyDelete(&v3[3].monitor);
  dds3EffectPartDelete(&v3[4]);
}

// 0x11df430
void effPCPCrackDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s32 v9;
  dds3ModelHandle_t_o *Handle;
  dds3ModelHandle_t_c *v11;
  s64 v12;
  char *v13;
  s64 *v14;
  sdfModelRootNode_t_o *modelRoot;
  Il2CppClass *v17;
  s32 data;
  bool v19;
  s32 v20;
  s32 data_high;
  f32 v22;
  u32 bits;
  u32 element_class_high;
  signed s64 monitor_low;
  u64 v26;
  s64 v27;
  s64 v29;
  u64 v30;
  u32 v31;
  u64 v32;
  u32 *v34;
  u64 v35;
  u64 v37;
  System_String_o *v40;
  u64 v42;
  s64 v43;
  s64 v45;
  s64 v46;
  u64 *monitor;
  s64 v50;
  u64 *v51;
  s64 v53;
  u64 *v54;
  s64 v56;
  s64 v57;
  s64 v60;
  f32 v62;
  u64 v63;
  s64 v64;
  s32 v65;
  Il2CppClass *v71;
  s32 v72;
  s32 parent_high;
  s32 fields;
  s32 klass_high;
  s32 generic_class;
  s32 v77;
  u64 v78;
  u64 *v79;
  s64 v81;
  u32 v83;
  u64 v84;
  u64 v85;
  s64 v86;
  s64 v87;
  u32 v88;
  char *v90;
  u32 *v91;
  u32 v92;
  u32 v93;
  s64 v94;
  u32 v97;
  s64 v98;
  s64 v99;
  s64 v101;
  s32 v102;
  struct System_UInt32_array *pVC;
  struct UnityEngine_Vector4_array *pVertex;
  Il2CppClass *v105;
  u32 events;
  f32 v108;
  u32 v109;
  f32 v113;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  u32 v120;
  s64 v122;
  s64 v124;
  s64 v126;
  s64 v130;
  s64 v132;
  s64 v134;
  s64 v136;
  s32 v139;
  u32 v140;
  f32 v141;
  f32 v142;
  f32 v143;
  u32 v144;
  u32 v145;
  u32 v146;
  s64 v148;
  u32 v149;
  s64 v151;
  u32 v152;
  char *v154;
  u32 *v155;
  u32 v156;
  u32 max_length;
  s64 v158;
  s32 point;
  s64 v163;
  f32 v164;
  u64 v165;
  f32 v166;
  f32 v167;
  s32 v168;
  s32 v169;
  s32 v170;
  s32 parent;
  s64 v172;
  u32 abgr1;
  s32 methods_low;
  Il2CppObject *v175;
  s32 v176;
  s64 v177;
  signed s64 v178;
  dds3FlashPolyList_t_o **hPoly;
  u32 fields_high;
  s64 v181;
  s64 v182;
  Il2CppObject *hDataa;
  UnityEngine_Vector4_o v184;
  UnityEngine_Vector4_o v185;
  UnityEngine_Vector4_o v186;
  UnityEngine_Vector4_o v187;
  UnityEngine_Vector4_o v188;
  UnityEngine_Vector4_o v189;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v191;
  dds3ModelHandle_t_o *aHandle;
  UnityEngine_Vector4_o v193;
  u64 v194[2];
  char *v195;
  UnityEngine_Vector4_o v196;

  *&v193.x = 0;
  *&v193.z = 0;
  *&p.x = 0;
  hDataa = 0;
  *&v191.z = 0;
  aHandle = 0;
  *&p.z = 0;
  *&v191.x = 0;
  *&v189.x = 0;
  *&v189.z = 0;
  *&v188.x = 0;
  *&v188.z = 0;
  *&v187.x = 0;
  *&v187.z = 0;
  *&v186.x = 0;
  *&v186.z = 0;
  *&v185.x = 0;
  *&v185.z = 0;
  *&v184.x = 0;
  *&v184.z = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPCrack_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPCrack_t, v194);
      if ((v194[0] & 1) != 0)
        v6 = v195;
      else
        v6 = v194 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  sub_854690(&v193.x, 0.0, 1.0, 0.0, 0.0);
  *&v191.z = 0;
  aHandle = 0;
  *&p.z = 0;
  *&v191.x = 0;
  *&p.x = 0;
  *&v189.x = 0;
  *&v189.z = 0;
  *&v188.x = 0;
  *&v188.z = 0;
  *&v187.x = 0;
  *&v187.z = 0;
  *&v186.x = 0;
  *&v186.z = 0;
  *&v185.x = 0;
  *&v185.z = 0;
  *&v184.x = 0;
  *&v184.z = 0;
  v9 = v3[3].klass;
  methods_low = LOBYTE(v3[1].klass->_1.methods);
  else
  {
    Handle = dds3EffectPartGetHandle(&v3[4]);
    if (!Handle)
      goto LABEL_19;
  }
  v11 = Handle->klass;
  if (Handle->klass->_2.typeHierarchyDepth < v12
    || v11->_2.typeHierarchy[v12 - 1] != dds3ModelHandle_t)
  {
    sub_8FC2C0(v11->_1.element_class, dds3ModelHandle_t, v194);
    if ((v194[0] & 1) != 0)
      v13 = v195;
    else
      v13 = v194 + 1;
    v14 = sub_8C4940(v13);
  }
LABEL_19:
  aHandle = Handle;
  modelRoot = Handle->modelRoot;
  SDF_VU0__LOADVECTOR(*&v3[1].klass->_1.name);
  mdlSetPosition(&aHandle);
  sub_854930(&v188, 0);
  sub_854710(&v188, 0);
  sub_854930(&v188, 1u);
  sub_854930(&v188, 2u);
  sub_854930(&v188, 3u);
  SDF_VU0__LOADVECTOR(v188);
  mdlSetScale(&aHandle);
  hDataa = aHandle;
  dds3EffectPartModelDraw(&hDataa);
  v17 = v3[1].klass;
  if (!LOBYTE(v17->_1.byval_arg.data))
  {
    LODWORD(monitor_low) = v3[2].monitor;
    goto LABEL_46;
  }
  data = v17->_1.this_arg.data;
  v19 = __OFSUB__(v9, data);
  v20 = v9 - data;
  if ((v20 < 0) ^ v19 | (v20 == 0))
  {
    bits = v17->_1.this_arg.bits;
    element_class_high = *(&v17->_1.this_arg.bits + 1);
    LODWORD(monitor_low) = v3[2].monitor;
    if (monitor_low < 1)
      goto LABEL_46;
  }
  else
  {
    data_high = HIDWORD(v17->_1.this_arg.data);
    if (data_high < 1)
    {
      bits = v17->_1.element_class;
      element_class_high = HIDWORD(v17->_1.element_class);
      LODWORD(monitor_low) = v3[2].monitor;
      if (monitor_low < 1)
        goto LABEL_46;
    }
    else
    {
      v22 = v20 / data_high;
      bits = effColorBlend(v17->_1.this_arg.bits, v17->_1.element_class, v22);
      element_class_high = effColorBlend(
                             *(&v3[1].klass->_1.this_arg.bits + 1),
                             HIDWORD(v3[1].klass->_1.element_class),
                             v22,
                             0);
      LODWORD(monitor_low) = v3[2].monitor;
      if (monitor_low < 1)
        goto LABEL_46;
    }
  }
  v26 = 0;
  do
  {
    v27 = *(v3[3].monitor + 5);
    if (WORD2(v3[2].monitor))
    {
      v29 = *(*(v27 + 8 * v26 + 32) + 24LL);
      v30 = 0;
      v31 = 0;
      do
      {
        v32 = *(v29 + 24);
        v34 = (v29 + 4 * v30);
        v35 = v30 + 1;
        v34[8] = element_class_high;
        v37 = v35 + 1;
        v34[9] = bits;
        v34[10] = element_class_high;
        ++v31;
        v30 = v37 + 1;
      }
      while (v31 < WORD2(v3[2].monitor));
    }
    monitor_low = SLODWORD(v3[2].monitor);
    ++v26;
  }
  while (v26 < monitor_low);
LABEL_46:
  abgr1 = HIDWORD(v3[3].klass);
  sub_854710(&v188, 0);
  sub_854930(&v187, 0);
  sub_854710(&v187, 0);
  sub_854930(&v187, 1u);
  sub_854930(&v187, 2u);
  sub_854930(&v187, 3u);
  sub_854930(&v191, 3u);
  sub_854930(&v191, 2u);
  sub_854930(&v191, 1u);
  sub_854930(&v191, 0);
  v175 = v3;
  if (monitor_low >= 1)
  {
    v42 = 0;
    do
    {
      v43 = *(v3[3].monitor + 5);
      v45 = *(v43 + 8 * v42 + 32);
      *(v45 + 40) = abgr1;
      v46 = *(v45 + 16);
      if (methods_low == 2)
      {
        sub_854930(&p, 0);
        sub_854930(&p, 1u);
        sub_854930(&p, 2u);
        sdfModelGetMarkPosMatrixUnity(modelRoot, v42);
        SDF_VU0__LOADVECTOR(p);
        SDF_VU0__APPLYMATRIX_XYZ();
        SDF_VU0__STOREVECTOR(&p);
        monitor = v3[1].monitor;
        v50 = monitor[v42 + 4] + 24LL;
        sub_854710(&p, 0);
        sub_854930(v50, 0);
        v51 = v3[1].monitor;
        v53 = v51[v42 + 4] + 24LL;
        sub_854710(&p, 1u);
        sub_854930(v53, 1u);
        v54 = v3[1].monitor;
        v56 = v54[v42 + 4] + 24LL;
        sub_854710(&p, 2u);
        sub_854930(v56, 2u);
      }
      sdfModelGetMarkPosUnity(modelRoot, v42);
      if (v9 < WORD2(v3[2].monitor))
      {
        v57 = *(v45 + 32);
        SDF_VU0__STOREVECTOR((v46 + 16 * v57 + 32), 0);
        SDF_VU0__STOREVECTOR((v46 + 16 * (v57 + 1) + 32), 0);
        v60 = v57 + 2;
        SDF_VU0__STOREVECTOR((v46 + 16 * v60 + 32), 0);
        *(v45 + 32) += 3;
        SDF_VU0__LOADVECTOR_C(v193);
        if (v9 >= 1)
        {
          v62 = 1.0;
          v63 = 0;
          v64 = v46 + 56;
          v65 = v9;
          do
          {
            SDF_VU0__LOADVECTOR(*(v64 + 40), 0);
            SDF_VU0__LOADVECTOR_B(*(v64 - 8), 0);
            SDF_VU0__SUBVECTOR();
            if (SDF_VU0__GETLENGTH() <= 1.0)
            {
              SDF_VU0__LOADVECTOR(v191);
            }
            else
            {
              SDF_VU0__COPYVECTOR_C_TO_B();
              SDF_VU0__OUTERPRODUCT();
              SDF_VU0__NORMALIZE();
              SDF_VU0__STOREVECTOR(&v191);
            }
            SDF_VU0__LOADVECTOR_B(v187);
            SDF_VU0__SCALEVECTOR_B(v62);
            SDF_VU0__MULVECTOR();
            SDF_VU0__COPYVECTOR_A_TO_B();
            SDF_VU0__LOADVECTOR(*(v64 - 8), 0);
            SDF_VU0__ADDVECTOR();
            SDF_VU0__STOREVECTOR((v64 - 24), 0);
            SDF_VU0__SUBVECTOR();
            SDF_VU0__SUBVECTOR();
            SDF_VU0__STOREVECTOR((v64 + 8), 0);
            v62 = v62 - (1.0 / v9);
            v63 += 3LL;
            --v65;
            v64 += 48;
          }
          while (v65);
        }
      }
      v3 = v175;
      ++v42;
    }
    while (v42 != monitor_low);
  }
  v71 = v3[1].klass;
  if (LOBYTE(v71->_1.byval_arg.data))
  {
    dds3TrackPolyDraw(&v3[3].monitor, "");
    v71 = v3[1].klass;
  }
  if (BYTE4(v71->_1.castClass))
  {
    v72 = v9 - LODWORD(v71->_1.declaringType);
    if (v72 >= 1)
    {
      if (BYTE5(v71->_1.castClass) == 1)
        v72 = v9;
      if (monitor_low >= 1)
      {
        parent_high = HIDWORD(v71->_1.parent);
        parent = v71->_1.parent;
        klass_high = HIDWORD(v71->_1.klass);
        fields = v71->_1.fields;
        generic_class = v71->_1.generic_class;
        v167 = fields;
        v166 = parent_high;
        if (v72 <= WORD2(v3[2].monitor))
          v77 = v72;
        else
          v77 = WORD2(v3[2].monitor);
        v168 = generic_class;
        v169 = parent_high;
        v176 = klass_high;
        v170 = fields + klass_high;
        v178 = v77 - 1;
        v164 = generic_class;
        v163 = monitor_low;
        v78 = 0;
        while (1)
        {
          v79 = v3[1].monitor;
          v181 = v79[v78 + 4];
          v81 = *(v3[3].monitor + 5);
          v177 = *(*(v81 + 8 * v78 + 32) + 16LL);
          hPoly = (v181 + 16);
          v165 = v78;
          (*hPoly)->abgr = abgr1;
          if (v178 >= 1)
            break;
LABEL_197:
          point = (*hPoly)->point;
          dds3FlashPolyListDraw(hPoly, point, v40);
          v78 = v165 + 1;
          if (v165 + 1 == v163)
            goto LABEL_201;
        }
        v172 = v181 + 24;
        v83 = 0;
        v84 = 0;
        v85 = 4;
        v86 = v177 + 108;
        while (1)
        {
          v99 = *(v181 + 56);
          v101 = *(v99 + 8 * v84 + 32);
          v102 = *(v101 + 28);
          pVertex = (*hPoly)->pVertex;
          pVC = (*hPoly)->pVC;
          v105 = v3[1].klass;
          if (v102 <= v176)
          {
            events = v105->_1.events;
            fields_high = HIDWORD(v105->_1.fields);
            if (v102 < 0)
              goto LABEL_196;
          }
          else if (v102 >= v170 || SLODWORD(v105->_1.fields) < 1)
          {
            events = v105->_1.properties;
            fields_high = HIDWORD(v105->_1.events);
            if (v102 < 0)
              goto LABEL_196;
          }
          else
          {
            v108 = (v102 - v176) / v167;
            fields_high = effColorBlend(HIDWORD(v105->_1.fields), HIDWORD(v105->_1.events), v108, 0);
            v109 = effColorBlend(v3[1].klass->_1.events, v3[1].klass->_1.properties, v108);
            events = v109;
            if ((*(v101 + 28) & 0x80000000) != 0)
              goto LABEL_196;
          }
          v182 = v101;
          sub_854930(&p, 1u);
          sub_854710(v172, 0);
          sub_854710(&p, 1u);
          sub_854930(&v186, 0);
          sub_854710(v172, 1u);
          sub_854710(&p, 1u);
          sub_854930(&v186, 1u);
          sub_854710(v172, 2u);
          sub_854710(&p, 1u);
          sub_854930(&v186, 2u);
          sub_854930(&v186, 3u);
          if (methods_low == 2 && *(v181 + 44) <= *(v101 + 28))
          {
            SDF_VU0__LOADVECTOR(*(v86 - 12), 0);
            SDF_VU0__LOADVECTOR_B(*(v86 - 60), 0);
            SDF_VU0__SUBVECTOR();
            SDF_VU0__NORMALIZE();
            SDF_VU0__STOREVECTOR(&v189);
            v113 = *(v181 + 40);
            x = v189.x;
            y = v189.y;
            z = v189.z;
            w = v189.w;
            v196.x = x;
            v196.y = y;
            v196.z = z;
            v196.w = w;
            SetRotateMatrixAxis(v113, v196);
            SDF_VU0__LOADVECTOR(v186);
            SDF_VU0__APPLYMATRIX_XYZ();
            SDF_VU0__STOREVECTOR(&v186);
            *(v181 + 40) = *(v181 + 40) + *(v181 + 48);
          }
          sub_854930(&v185, 0);
          sub_854710(&v185, 0);
          sub_854930(&v185, 1u);
          sub_854930(&v185, 2u);
          sub_854930(&v185, 3u);
          sub_854930(&v184, 0);
          sub_854710(&v184, 0);
          sub_854930(&v184, 1u);
          sub_854930(&v184, 2u);
          sub_854930(&v184, 3u);
          SDF_VU0__LOADVECTOR(*(v86 - 12), 0);
          v120 = events & 0xFFFFFF;
          SDF_VU0__LOADVECTOR_B(*(v86 - 60), 0);
          SDF_VU0__SUBVECTOR();
          if (SDF_VU0__GETLENGTH() <= 1.0)
          {
            SDF_VU0__LOADIDENTITYVECTOR();
            SDF_VU0__STOREVECTOR(&pVertex->m_Items[v83]);
            v132 = v83 + 1;
            SDF_VU0__STOREVECTOR(&pVertex->m_Items[v132]);
            v134 = v83 + 2;
            SDF_VU0__STOREVECTOR(&pVertex->m_Items[v134]);
            v136 = v83 + 3;
            SDF_VU0__STOREVECTOR(&pVertex->m_Items[v136]);
            v130 = v83 + 4;
            if (v130 >= LODWORD(pVertex->max_length))
            {
LABEL_170:
            }
          }
          else
          {
            SDF_VU0__NORMALIZE();
            SDF_VU0__COPYVECTOR_A_TO_B();
            SDF_VU0__LOADVECTOR(v184);
            SDF_VU0__MULVECTOR();
            SDF_VU0__STOREVECTOR(&v184);
            SDF_VU0__LOADVECTOR(v185);
            SDF_VU0__MULVECTOR();
            SDF_VU0__STOREVECTOR(&v185);
            SDF_VU0__LOADVECTOR_C(v186);
            SDF_VU0__LOADVECTOR(*(v86 - 12), 0);
            SDF_VU0__LOADVECTOR_B(v185);
            v122 = v83 + 3;
            SDF_VU0__STOREVECTOR(&pVertex->m_Items[v122]);
            SDF_VU0__ADDVECTOR();
            v124 = v83 + 2;
            SDF_VU0__STOREVECTOR(&pVertex->m_Items[v124]);
            SDF_VU0__SUBVECTOR();
            SDF_VU0__SUBVECTOR();
            v126 = v83 + 4;
            SDF_VU0__STOREVECTOR(&pVertex->m_Items[v126]);
            SDF_VU0__LOADVECTOR(*(v86 - 12), 0);
            SDF_VU0__LOADVECTOR_B(v184);
            SDF_VU0__ADDVECTOR_A_C();
            SDF_VU0__ADDVECTOR();
            SDF_VU0__STOREVECTOR(&pVertex->m_Items[v83]);
            SDF_VU0__SUBVECTOR();
            SDF_VU0__SUBVECTOR();
            v130 = v83 + 1;
            if (v130 >= LODWORD(pVertex->max_length))
              goto LABEL_170;
          }
          SDF_VU0__STOREVECTOR(&pVertex->m_Items[v130]);
          v139 = parent - v102;
          if (parent >= v102)
          {
            if (v169 && v102 < v169)
            {
              v141 = v166;
              v142 = v102;
LABEL_179:
              v143 = v142 / v141;
              v144 = vcvts_n_s32_f32(v143, 0x1Fu);
              v145 = vcvts_n_u32_f32(v143, 0x1Fu);
              if ((v143 * 2147500000.0) >= 0.0)
                v144 = v145;
              v140 = effColorMultiply(v144 & 0xFF000000 | 0x808080, abgr1);
              goto LABEL_182;
            }
            v140 = abgr1;
            if (v168)
            {
              v140 = abgr1;
              if (v139 <= v168)
              {
                v142 = v139;
                v141 = v164;
                goto LABEL_179;
              }
            }
          }
          else
          {
            v140 = 0;
          }
LABEL_182:
          v146 = effColorMultiply(v120, v140);
          pVC->m_Items[v83] = v146;
          v148 = v83 + 1;
          v149 = effColorMultiply(v120, v140);
          pVC->m_Items[v148] = v149;
          if (*(v101 + 32))
          {
            v151 = v83 + 2;
            v152 = effColorMultiply(0x80000000, v140);
            v154 = pVC + 4 * v151;
            *(v154 + 8) = v152;
            v155 = (v154 + 32);
            v156 = effColorMultiply(fields_high | 0xFF000000, v140);
            max_length = pVC->max_length;
            v158 = v83 + 3;
            pVC->m_Items[v158] = v156;
            v97 = *v155;
            v3 = v175;
            v98 = v83 + 4;
            if (v98 >= max_length)
              goto LABEL_194;
          }
          else
          {
            v87 = v83 + 2;
            v88 = effColorMultiply(0xFF000000, v140);
            v90 = pVC + 4 * v87;
            *(v90 + 8) = v88;
            v91 = (v90 + 32);
            v92 = effColorMultiply(fields_high & 0xFFFFFF | 0x40000000, v140);
            v93 = pVC->max_length;
            v94 = v83 + 3;
            v3 = v175;
            pVC->m_Items[v94] = v92;
            v97 = *v91;
            v98 = v83 + 4;
            if (v98 >= v93)
            {
LABEL_194:
            }
          }
          pVC->m_Items[v98] = v97;
          v101 = v182;
LABEL_196:
          ++*(v101 + 28);
          ++v84;
          v83 += 5;
          v85 += 3LL;
          v86 += 48;
          if (v84 >= v178)
            goto LABEL_197;
        }
      }
    }
  }
LABEL_201:
  ++LODWORD(v3[3].klass);
}

// 0x11de150
void effPCPCrackInit(effPCPCrack_t **pPCPCrack) {
  effPartHandle_t_o **p_hHelper;
  Il2CppObject *Handle;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  struct effPCPCrackParam_t_o *param;
  f32 speed;
  struct sdfModelRootNode_t_o *modelRoot;
  s64 v15;
  s64 v16;
  s64 v17;
  s64 v18;
  s64 v19;
  s64 v20;
  effPCPCrack_t_o *v21;
  effPCPCrack_t_o *v23;
  sdfModelRootNode_t_o *v24;
  effPCPCrack_t_o *v26;
  s32 MarkCount;
  s32 MarkLength;
  effPCPCrack_t_o *v29;
  effPCPCrack_t_o *v30;
  u64 v31;
  u32 *pPart;
  u64 *v34;
  struct effPCPCrackPart_t_array *v37;
  effPCPCrackPart_t_o *v39;
  u32 v40;
  effPCPCrack_t_o *v42;
  u64 v43;
  u64 v44;
  s64 v45;
  struct dds3FlashPolyList_t_o *hFlash;
  struct UnityEngine_Vector4_array *pVertex;
  struct System_UInt32_array *pVC;
  u64 max_length_low;
  u32 *v54;
  s64 v57;
  u32 f_blend;
  u32 *v63;
  u32 *v64;
  s64 i;
  u64 v66;
  u64 *v67;
  struct effPCPCrackPartFlash_t_array *v71;
  u64 v74;
  effPCPCrackPart_t_o *v75;
  UnityEngine_Matrix4x4_o v76;
  Il2CppObject *hData;
  effPCPCrackPartFlash_t_o *pSize;
  dds3ModelHandle_t_o *aHandle;

  hData = 0;
  pSize = 0;
  aHandle = 0;
  p_hHelper = &(*pPCPCrack)->hHelper;
  else
  {
    Handle = dds3EffectPartGetHandle(&(*pPCPCrack)->hHelper, 0);
    if (!Handle)
      goto LABEL_12;
  }
  klass = Handle->klass;
  if (Handle->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, &v76);
    if ((LOBYTE(v76.m00) & 1) != 0)
      v8 = *&v76.m01;
    else
      v8 = &v76.m00 + 1;
    v9 = sub_8C4940(v8);
  }
LABEL_12:
  aHandle = Handle;
  param = (*pPCPCrack)->param;
  if (param->f_timing <= 0)
  {
    param->f_timing = 1;
    param = (*pPCPCrack)->param;
  }
  speed = param->speed;
  mdlSetMotionSpeed(&aHandle, speed, 0);
  modelRoot = aHandle->modelRoot;
  get_identity(&v76, 0);
  v16 = *&v76.m00;
  v15 = *&v76.m20;
  v17 = *&v76.m21;
  *&modelRoot->tm.m01 = *&v76.m01;
  *&modelRoot->tm.m21 = v17;
  *&modelRoot->tm.m00 = v16;
  *&modelRoot->tm.m20 = v15;
  v19 = *&v76.m02;
  v18 = *&v76.m22;
  v20 = *&v76.m23;
  *&modelRoot->tm.m03 = *&v76.m03;
  *&modelRoot->tm.m23 = v20;
  *&modelRoot->tm.m02 = v19;
  *&modelRoot->tm.m22 = v18;
  hData = aHandle;
  dds3EffectPartModelDraw(&hData);
  v21 = *pPCPCrack;
  v21->MarkLength = mdlGetMotionLengthUnity(aHandle);
  v23 = *pPCPCrack;
  v24 = aHandle->modelRoot;
  v23->MarkCount = sdfModelGetMarkPosCountUnity(v24);
  dds3EffectPartModelDelete(&hData);
  v26 = *pPCPCrack;
  MarkCount = (*pPCPCrack)->MarkCount;
  MarkLength = (*pPCPCrack)->MarkLength;
  v26->hPoly = dds3TrackPolyCreate(MarkCount, MarkLength, 1, 1);
  dds3TrackPolySetMode(&(*pPCPCrack)->hPoly, (*pPCPCrack)->param->blend, 0);
  (*pPCPCrack)->hPartMem = 0;
  if ((*pPCPCrack)->param->f_show)
  {
    v29 = *pPCPCrack;
    v29->pPart = NewSpecific(effPCPCrackPart_t, v29->MarkCount);
    v30 = *pPCPCrack;
    if ((*pPCPCrack)->MarkCount >= 1)
    {
      v31 = 0;
      do
      {
        pPart = v30->pPart;
        v34 = Allocate(effPCPCrackPart_t);
        effPCPCrackPart_t___ctor(v34);
        *&pPart[2 * v31 + 8] = v34;
        v37 = (*pPCPCrack)->pPart;
        v39 = v37->m_Items[v31];
        v40 = (*pPCPCrack)->MarkLength;
        v39->hFlash = dds3FlashPolyListCreate(v40);
        sub_854930(&v39->dir, 0);
        sub_854930(&v39->dir, 1u);
        sub_854930(&v39->dir, 2u);
        v39->rotate = 0.0;
        v39->rotate_add = 0.0017453;
        v42 = *pPCPCrack;
        if ((*pPCPCrack)->MarkLength)
        {
          v43 = 0;
          v44 = 0;
          v45 = 96;
          v74 = v31;
          v75 = v39;
          do
          {
            hFlash = v39->hFlash;
            pVertex = hFlash->pVertex;
            pVC = hFlash->pVC;
            max_length_low = LODWORD(pVC->max_length);
            v54 = (pVC + 4 * v43);
            v54[8] = 0;
            v54[9] = 0;
            v54[10] = 0;
            v54[11] = 0;
            v54[12] = 0;
            SDF_VU0__LOADIDENTITYVECTOR();
            v57 = pVertex + v45;
            SDF_VU0__STOREVECTOR((pVertex + v45 - 64), 0);
            SDF_VU0__STOREVECTOR((v57 - 48), 0);
            SDF_VU0__STOREVECTOR((v57 - 32), 0);
            SDF_VU0__STOREVECTOR((v57 - 16), 0);
            SDF_VU0__STOREVECTOR((pVertex + v45), 0);
            v42 = *pPCPCrack;
            v39 = v75;
            ++v44;
            v45 += 80;
            v43 += 5LL;
          }
          while (v44 < (*pPCPCrack)->MarkLength);
          v31 = v74;
        }
        f_blend = v42->param->f_blend;
        v39->hFlash->blend = f_blend;
        v63 = NewSpecific(effPCPCrackPartFlash_t, (*pPCPCrack)->MarkLength);
        v39->pSize = v63;
        v30 = *pPCPCrack;
        if ((*pPCPCrack)->MarkLength)
        {
          v64 = v63;
          for (i = 4; ; ++i)
          {
            v66 = i - 4;
            v67 = Allocate(effPCPCrackPartFlash_t);
            effPCPCrackPartFlash_t___ctor(v67);
            *&v64[2 * i] = v67;
            v71 = v39->pSize;
            pSize = *(&v71->obj.klass + i);
            effPCPCrackSizeInit(pPCPCrack, &pSize);
            v30 = *pPCPCrack;
            if (i - 3 >= (*pPCPCrack)->MarkLength)
              break;
            v64 = v39->pSize;
          }
        }
        ++v31;
      }
      while (v31 < v30->MarkCount);
    }
  }
}

// 0x11e1390
void effPCPCrackSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPCrack_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPCrack_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[3].klass) = abgr;
}

// 0x11e1270
void effPCPCrackSetPosition(void **hData, sdfVector4_t pPos) {
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
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPCrack_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPCrack_t, v12);
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

// 0x11de010
void effPCPCrackSizeInit(effPCPCrack_t **pPCPCrack, effPCPCrackPartFlash_t **pSize) {
  struct effPCPCrackParam_t_o *param;
  f32 scale;
  f32 f_length_r;
  f32 f_length;
  effPCPCrackPartFlash_t_o *v9;
  f32 v10;
  effPCPCrackPartFlash_t_o *v11;
  effPCPCrackPartFlash_t_o *v12;
  u32 v13;
  s64 f_timing;

  param = (*pPCPCrack)->param;
  scale = param->scale;
  f_length = param->f_length;
  f_length_r = param->f_length_r;
  v9 = *pSize;
  v9->length = scale * (f_length * DDS3EFFECT_RAND_FA(f_length_r));
  v10 = DDS3EFFECT_RAND_FA((*pPCPCrack)->param->f_width_r, 0);
  (*pSize)->width_in = scale * (v10 * (*pPCPCrack)->param->f_width_in);
  (*pSize)->width_out = scale * (v10 * (*pPCPCrack)->param->f_width_out);
  v11 = *pSize;
  v11->type = DDS3EFFECT_RAND_I() & 1;
  v12 = *pSize;
  v13 = DDS3EFFECT_RAND_I();
  f_timing = (*pPCPCrack)->param->f_timing;
  v12->frame = v13 / f_timing * f_timing - v13;
}

// 0x11ef320
effPCPDANTE_Damage_tag *effPCPDANTE_Damage_Copy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  effPCPDANTE_Damage_Param_t_o *v10;
  effPCPDANTE_Damage_tag_o *result;
  u64 v12[3];

  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPDANTE_Damage_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPDANTE_Damage_tag, v12);
      if ((v12[0] & 1) != 0)
        v8 = v12[2];
      else
        v8 = v12 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = v5[1].klass;
  result = effPCPDANTE_Damage_Create(v10, 0, tbldata);
  result->original = 0;
  result->hBED = v5[2].monitor;
  return result;
}

// 0x11eebb0
effPCPDANTE_Damage_tag *effPCPDANTE_Damage_Create(effPCPDANTE_Damage_Param_t *pParam, void *pBED) {
  u64 *v5;
  u64 *v6;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  nbMainProcessData_t_o *MainProcessData;
  u32 TargetBit;
  u64 v16;
  u32 v17;
  s32 v18;
  struct nbFormation_t_array *form;
  u64 v21;
  u32 v23;
  u32 RandIntA;
  u32 v25;
  u64 v26;
  u32 v27;
  s64 v28;
  char v30;
  u64 v33;
  u64 v36[3];

  v5 = Allocate(effPCPDANTE_Damage_tag);
  _ctor(v5, 0);
  v5[2] = 0;
  v5[3] = NewSpecific(byte, 0x20u);
  *(v5 + 8) = 0;
  *(v5 + 36) = 0;
  v5[5] = 0;
  v5[6] = NewSpecific(effEveBEDCutHandle_t, 0x20u);
  v5[7] = NewSpecific(s32, 0x20u);
  *(v5 + 16) = 0;
  v6 = Allocate(effPCPDANTE_Damage_Param_t);
  effPCPDANTE_Damage_Param_t___ctor(v6);
  v5[2] = v6;
  effPCPDANTE_Damage_Param_t__pClone(pParam, v5 + 2);
  *(v5 + 8) = 0;
  *(v5 + 16) = -2139062144;
  if (pBED)
  {
    *(v5 + 36) = 1;
    Interface = QueryInterface(pBED, byte);
    if (!Interface)
    {
      sub_8FC2C0(pBED->klass->_1.element_class, v8, v36);
      if ((v36[0] & 1) != 0)
        v10 = v36[2];
      else
        v10 = v36 + 1;
      v11 = sub_8C4940(v10);
    }
    v5[5] = effEveBEDCreate(Interface);
  }
  MainProcessData = nbGetMainProcessData();
  TargetBit = effBTLSkillGetTargetBit();
  v16 = 0;
  v17 = 0;
  v18 = 1;
  do
  {
    form = MainProcessData->form;
    if ((form->m_Items[v16]->stat & 1) != 0 && ((1 << v16) & TargetBit) != 0)
    {
      v21 = v5[3];
      *(v21 + v17 + 32) = v18;
      v18 += pParam->wait;
      ++v17;
    }
    ++v16;
  }
  while (v16 != 32);
  if (v17)
  {
    v23 = 0;
    do
    {
      RandIntA = dds3GetRandIntA(v17, "");
      v25 = dds3GetRandIntA(v17, "");
      v26 = v5[3];
      v27 = *(v26 + 24);
      v28 = RandIntA;
      v30 = *(v26 + RandIntA + 32);
      *(v5[3] + v28 + 32) = *(v5[3] + v25 + 32);
      v33 = v5[3];
      ++v23;
      *(v33 + v25 + 32) = v30;
    }
    while (v23 < 2 * v17);
  }
  return v5;
}

// 0x11ef070
effPCPDANTE_Damage_tag *effPCPDANTE_Damage_CreatePCF(void **hData, s32 bPos, bool tbldata) {
  dds3EffectPCPData_t_o *v6;
  Il2CppObject *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  struct dds3EffectPCPData_Part_t_array *pcpData;
  Il2CppObject *v14;
  u32 offset;
  Il2CppObject *DataUnityOffSet;
  struct dds3EffectPCPData_Part_t_array *v19;
  Il2CppObject *v20;
  effPCPDANTE_Damage_Param_t_o *v21;
  u32 v23;
  Il2CppObject *EffPCPAgiFireballPart;
  effPCPDANTE_Damage_Param_t_c *klass;
  s64 typeHierarchyDepth;
  char *v29;
  s64 *v30;
  u64 v32[2];
  char *v33;
  s32 pos;

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v7->klass->_1.element_class, v8, v32);
      if ((v32[0] & 1) != 0)
        v10 = v33;
      else
        v10 = v32 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v6, Interface, &pos);
  pcpData = v6->pcpData;
  v14 = *hData;
  offset = pcpData->m_Items[0]->offset;
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 51);
  v19 = v6->pcpData;
  v20 = *hData;
  v21 = DataUnityOffSet;
  v23 = v19->m_Items[1]->offset;
  EffPCPAgiFireballPart = GetEffPCPAgiFireballPart(v20, v23 + bPos);
  else if (!v21)
  {
    return effPCPDANTE_Damage_Create(v21, EffPCPAgiFireballPart);
  }
  klass = v21->klass;
  if (v21->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPDANTE_Damage_Param_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPDANTE_Damage_Param_t, v32);
    if ((v32[0] & 1) != 0)
      v29 = v33;
    else
      v29 = v32 + 1;
    v30 = sub_8C4940(v29);
  }
  return effPCPDANTE_Damage_Create(v21, EffPCPAgiFireballPart);
}

// 0x11ef450
void effPCPDANTE_Damage_Delete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s64 i;
  Il2CppClass *v9;
  Il2CppClass *v11;
  effEveBEDCutHandle_t_o *v13;
  effBTL_t_o *monitor;
  u64 v15[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPDANTE_Damage_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPDANTE_Damage_tag, v15);
      if ((v15[0] & 1) != 0)
        v6 = v15[2];
      else
        v6 = v15 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  for (i = 4; i != 36; ++i)
  {
    v9 = v3[3].klass;
    if (*(&v9->_1.image + i))
    {
      v11 = v3[3].klass;
      v13 = *(&v11->_1.image + i);
      effEveBEDCutDelete(v13);
    }
  }
  if (BYTE4(v3[2].klass))
  {
    monitor = v3[2].monitor;
    effEveBEDDelete(monitor);
  }
}

// 0x11ef610
void effPCPDANTE_Damage_Run(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppClass *v8;
  s32 name;
  s32 name_high;
  s32 namespaze;
  nbMainProcessData_t_o *MainProcessData;
  f32 v14;
  f32 v15;
  u64 v16;
  u32 v17;
  struct nbFormation_t_array *form;
  effEveBEDParams_t_o *v21;
  nbFormation_t_o *v23;
  u32 *monitor;
  u32 *v27;
  Il2CppClass *v30;
  u32 *v32;
  s32 v34;
  s32 v35;
  f32 v36;
  Il2CppClass *v37;
  effEveBEDCutHandle_t_o *v39;
  Il2CppClass *v40;
  s32 v42;
  s32 v43;
  effBTL_t_o *v45;
  Il2CppClass *v46;
  s64 *v47;
  s64 *v48;
  u32 *v50;
  Il2CppClass *v53;
  u32 *v55;
  s32 v57;
  u32 TargetBit;
  nbFormation_t_o *pFormation;
  u64 v60[3];

  pFormation = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPDANTE_Damage_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPDANTE_Damage_tag, v60);
      if ((v60[0] & 1) != 0)
        v6 = v60[2];
      else
        v6 = v60 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = v3[1].klass;
  name = v8->_1.name;
  name_high = HIDWORD(v8->_1.name);
  namespaze = v8->_1.namespaze;
  MainProcessData = nbGetMainProcessData();
  v14 = name_high;
  v15 = namespaze;
  v16 = 0;
  v17 = 0;
  v57 = namespaze;
  TargetBit = effBTLSkillGetTargetBit();
  do
  {
    form = MainProcessData->form;
    pFormation = form->m_Items[v16];
    if ((pFormation->stat & 1) != 0 && ((1 << v16) & TargetBit) != 0)
    {
      v21 = Allocate(effEveBEDParams_t);
      effEveBEDParams_t___ctor(v21);
      sub_854930(&v21->fields, 0);
      sub_854930(&v21->fields, 1u);
      sub_854930(&v21->fields, 2u);
      sub_854930(&v21->fields, 3u);
      effBTLModelGetSphereCenter(&pFormation);
      SDF_VU0__STOREVECTOR(&v21->center);
      SDF_VU0__COPYVECTOR(&v21->rot, pFormation->rot);
      v23 = pFormation;
      v21->r = pFormation->r * pFormation->scl;
      v21->h = v23->h * v23->scl;
      v21->scale = effBTLPartGetScalePtr(&pFormation);
      monitor = v3[1].monitor;
      if (!*(monitor + v17 + 32))
        goto LABEL_33;
      v27 = v3[1].monitor;
      if (--*(v27 + v17 + 32) == 0)
      {
        v42 = name_high;
        v43 = name;
        nbSetUnitMotion(&pFormation, 1, 0, 1.0);
        v21->abgr = -2139062144;
        v45 = v3[2].monitor;
        v46 = v3[3].klass;
        v47 = effEveBEDCutCreate(v45, 2u, v21);
        v48 = v47;
        *(&v46->_1.byval_arg.data + v17) = v48;
        v50 = v3[3].monitor;
        name = v43;
        name_high = v42;
        namespaze = v57;
        v50[v17 + 8] = 0;
        v30 = v3[3].klass;
        if (v17 >= LODWORD(v30->_1.namespaze))
        {
LABEL_34:
        }
      }
      else
      {
LABEL_33:
        v30 = v3[3].klass;
        if (v17 >= LODWORD(v30->_1.namespaze))
          goto LABEL_34;
      }
      if (*(&v30->_1.byval_arg.data + v17))
      {
        v32 = v3[3].monitor;
        v34 = v32[v17 + 8];
        v35 = name - v34;
        if (name <= v34)
        {
          v37 = v3[3].klass;
          v39 = *(&v37->_1.byval_arg.data + v17);
          effEveBEDCutDelete(v39);
          v40 = v3[3].klass;
          *(&v40->_1.byval_arg.data + v17) = 0;
        }
        else
        {
          if (name_high && v34 < name_high)
          {
            v36 = v34 / v14;
          }
          else
          {
            v36 = 1.0;
            if (namespaze)
            {
              v36 = 1.0;
              if (v35 <= namespaze)
                v36 = v35 / v15;
            }
          }
          v21->abgr = effColorBlend(v3[4].klass & 0xFFFFFF, v3[4].klass, v36);
          v53 = v3[3].klass;
          else if (v17 >= LODWORD(v53->_1.namespaze))
          {
LABEL_67:
          }
          effEveBEDCutDraw(&v53->_1.byval_arg.data + v17);
          v55 = v3[3].monitor;
          ++v55[v17 + 8];
        }
      }
      ++v17;
    }
    ++v16;
  }
  while (v16 != 32);
}

// 0x11efc20
void effPCPDANTE_Damage_SetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPDANTE_Damage_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPDANTE_Damage_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[4].klass) = abgr;
}

// 0x11f31a0
void effPCPDANTE_ShowTime_AreYouReady_Draw(effPCPDANTE_ShowTime_tag **pPCPShowTime) {
  struct System_Int32_array *frameParts;
  s32 v5;
  f64 v6;
  s32 i;
  s32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  u32 v12;
  sdfTexHandle_t_o *v14;
  f32 v16;
  s32 v17;
  u32 v18;
  sdfTexHandle_t_o *v22;
  sdfTexHandle_t_o *v27;
  f64 v31;
  s32 v32;
  s32 v33;
  s32 v34;
  f32 v35;
  u32 v36;
  sdfTexHandle_t_o *v38;
  f32 v40;
  f32 v41;
  f32 v42;
  s32 v43;
  u32 v44;
  s32 v46;
  sdfTexHandle_t_o *v49;
  f32 v51;
  f32 v52;
  s32 v53;
  u32 v55;
  sdfTexHandle_t_o *v57;
  struct System_Int32_array *v60;
  s32 v62;

  frameParts = (*pPCPShowTime)->frameParts;
  v5 = frameParts->m_Items[1];
  v6 = 0.0;
  for (i = 6; i != 12; ++i)
  {
    v8 = v5 + i - 12;
    if (v8 <= 0x10)
    {
      v9 = v8 * 0.125;
      v10 = v9 <= 1.0 ? v8 * 0.125 : 2.0 - v9;
      if (v8 <= 8)
      {
        v11 = v6;
        v12 = ((v11 / 6.0) * 80.0) + 48;
        nbPnl_rsetAlpha(0);
        v16 = v12;
        v17 = 184 - (v9 * (v9 * 92.0));
        v18 = (((v10 * v10) * v16) << 24) | 0x808080;
        effPCPDANTE_Sprite_Draw(32, v17, 1.0, v18, effPCPDANTE_AreYouReady_UV, v14, 1, i - 6);
        if (v5 + i == 20)
        {
          nbPnl_rsetAlpha(1);
          effPCPDANTE_Sprite_Draw(32, v17, 1.0, 0x20808080u, effPCPDANTE_AreYouReady_UV, v22, 1, i);
        }
      }
    }
    v6 = v6 + 1.0;
  }
  v62 = v5 - 10;
  if ((v5 - 10) <= 0x10)
  {
    nbPnl_rsetAlpha(0);
    effPCPDANTE_Sprite_Draw(32, 92, 1.0, 0x80808080, effPCPDANTE_AreYouReady_UV, v27, 1, 12);
  }
  v31 = 0.0;
  v32 = 0;
  v33 = v5 - 30;
  do
  {
    v34 = v33 + v32;
    if ((v33 + v32) <= 0xC)
    {
      v35 = v31;
      v36 = ((v35 * 0.25) * 112.0) + 16;
      nbPnl_rsetAlpha(0);
      v40 = v36;
      v41 = ((v34 / -12.0) + 1.0) * v40;
      v42 = (v34 * v34) * 3.0;
      v43 = v41;
      if (v41 >= 0.0)
        LOBYTE(v43) = v41;
      v44 = (v43 << 24) | 0x808080;
      v46 = 92 - v42;
      effPCPDANTE_Sprite_Draw(32, v46, 1.0, v44, effPCPDANTE_AreYouReady_UV, v38, 1, v32 + 13);
    }
    v31 = v31 + 1.0;
    ++v32;
  }
  while (v32 != 4);
  if (v62 <= 0x10)
  {
    nbPnl_rsetAlpha(1);
    v51 = v62 * 0.0625;
    v52 = (1.0 - v51) * 80.0;
    v53 = v52;
    if (v52 >= 0.0)
      LOBYTE(v53) = v52;
    v55 = (v53 << 24) | 0x808080;
    effPCPDANTE_Sprite_Draw(
      32,
      92,
      (v51 * (v51 * 0.75)) + 1.0,
      v55,
      effPCPDANTE_AreYouReady_UV,
      v49,
      1,
      17);
    effPCPDANTE_Sprite_Draw(
      32,
      92,
      (v51 * (v51 * 0.325)) + 1.0,
      v55,
      effPCPDANTE_AreYouReady_UV,
      v57,
      1,
      18);
  }
  v60 = (*pPCPShowTime)->frameParts;
  ++v60->m_Items[1];
}

// 0x11f2c60
void effPCPDANTE_ShowTime_Bingo_Draw(effPCPDANTE_ShowTime_tag **pPCPShowTime) {
  struct System_Int32_array *frameParts;
  s32 v5;
  f32 v6;
  f32 v7;
  f32 v8;
  sdfTexHandle_t_o *v10;
  s32 v12;
  u8 v13;
  u8 v14;
  u32 v16;
  sdfTexHandle_t_o *v19;
  s32 v23;
  s32 v24;
  sdfTexHandle_t_o *v26;
  f32 v28;
  u8 v29;
  u8 v30;
  u8 v31;
  s32 v33;
  s32 v34;
  effPCPDANTE_UV_tag_o *v35;
  f32 v37;
  s32 v38;
  u32 v39;
  effPCPDANTE_UV_tag_o *effPCPDANTE_Bingo_UV;
  s32 v41;
  sdfTexHandle_t_o *v43;
  sdfTexHandle_t_o *v49;
  f32 v51;
  u8 v52;
  u8 v53;
  u32 v55;
  struct System_Int32_array *v58;

  frameParts = (*pPCPShowTime)->frameParts;
  v5 = frameParts->m_Items[0];
  if (v5 <= 0x14)
  {
    v6 = v5 / 10.0;
    v7 = 1.0;
    v8 = v6 <= 1.0 ? v5 / 10.0 : 2.0 - v6;
    if (v5 >= 11)
    {
      nbPnl_rsetAlpha(1);
    }
    else
    {
      nbPnl_rsetAlpha(0);
      v8 = v8 * v8;
      v7 = v5 / 10.0;
    }
    v12 = (v7 * 370.0);
    v13 = vcvts_n_s32_f32(v8, 7u);
    v14 = vcvts_n_u32_f32(v8, 7u);
    if ((v8 * 128.0) < 0.0)
      v14 = v13;
    v16 = (v14 << 24) | 0x808080;
    effPCPDANTE_Sprite_Draw(v12, 244, 1.0, v16, effPCPDANTE_Bingo_UV, v10, 0, 0);
    if (v5 == 10)
    {
      nbPnl_rsetAlpha(1);
      effPCPDANTE_Sprite_Draw(v12, 244, 1.0, 0x20808080u, effPCPDANTE_Bingo_UV, v19, 0, 1);
      v23 = 0;
      goto LABEL_49;
    }
  }
  v23 = v5 - 10;
  if ((v5 - 10) <= 0x10)
  {
LABEL_49:
    nbPnl_rsetAlpha(0);
    effPCPDANTE_Sprite_Draw(370, 244, 1.0, 0x80808080, effPCPDANTE_Bingo_UV, v43, 0, 2);
    nbPnl_rsetAlpha(1);
    v51 = v23 * 0.0625;
    v52 = vcvts_n_s32_f32(1.0 - v51, 6u);
    v53 = vcvts_n_u32_f32(1.0 - v51, 6u);
    if (((1.0 - v51) * 64.0) >= 0.0)
      v52 = v53;
    v55 = (v52 << 24) | 0x808080;
    effPCPDANTE_Sprite_Draw(
      370,
      244,
      (v51 * v51) + 1.0,
      v55,
      effPCPDANTE_Bingo_UV,
      v49,
      0,
      4);
    v38 = 370;
    v41 = 5;
    v37 = (v51 * (v51 * 0.5)) + 1.0;
    v39 = v55;
    goto LABEL_70;
  }
  v24 = v5 - 27;
  if ((v5 - 27) > 0x14)
    goto LABEL_71;
  nbPnl_rsetAlpha(0);
  v28 = (v24 / -20.0) + 1.0;
  v29 = vcvts_n_s32_f32(v28, 7u);
  v30 = vcvts_n_u32_f32(v28, 7u);
  if ((v28 * 128.0) >= 0.0)
    v31 = v30;
  else
    v31 = v29;
  v33 = (v31 << 24) | 0x808080;
  v34 = ((v24 * v24) * 1.5) + 370;
  v35 = effPCPDANTE_Bingo_UV;
  v37 = 1.0;
  v38 = v34;
  v39 = v33;
  effPCPDANTE_Bingo_UV = v35;
  v41 = 3;
LABEL_70:
  effPCPDANTE_Sprite_Draw(v38, 244, v37, v39, effPCPDANTE_Bingo_UV, v26, 0, v41);
LABEL_71:
  v58 = (*pPCPShowTime)->frameParts;
  ++v58->m_Items[0];
}

// 0x11f1430
effPCPDANTE_ShowTime_tag *effPCPDANTE_ShowTime_Copy(void **hData, s32 bPos, bool tbldata) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v7;
  u64 *v8;
  AssetBundleCtrl_o *asset_bc;
  UnityEngine_GameObject_o *Prefab_16624656;
  u64 v13;
  Il2CppObject *v14;
  s64 v16;
  UnityEngine_GameObject_o *v17;
  UnityEngine_Transform_o *transform;
  struct nbPanelFlashData_t_array *flash;
  nbPanelFlashData_t_o *v22;
  UnityEngine_GameObject_o *v23;
  UnityEngine_Transform_o *v24;
  struct nbPanelFlashData_t_array *v25;
  nbPanelFlashData_t_o *v27;
  UnityEngine_GameObject_o *v28;
  UnityEngine_Transform_o *v29;
  struct nbPanelFlashData_t_array *v30;
  struct nbPanelFlashData_t_array *v32;
  struct nbPanelFlashData_t_array *v34;
  struct UnityEngine_GameObject_array_array *v37;
  struct UnityEngine_GameObject_array_array *effPCPDANTE_Sprite;
  s64 *v40;
  s64 *v41;
  struct UnityEngine_GameObject_array_array *v43;
  s64 *v44;
  s64 *v45;
  struct UnityEngine_GameObject_array_array *v48;
  s64 *v49;
  s64 *v51;
  AssetBundleCtrl_o *v54;
  Il2CppObject *v55;
  AssetBundleCtrl_o *v56;
  Il2CppObject *v57;
  AssetBundleCtrl_o *v58;
  Il2CppObject *v60;
  s64 v61;
  struct UnityEngine_GameObject_array_array *v63;
  u64 v64;
  struct UnityEngine_GameObject_array_array *v66;
  u32 *v68;
  UnityEngine_GameObject_o *v69;
  UnityEngine_Transform_o *v71;
  s64 *v72;
  s64 *v73;
  struct UnityEngine_GameObject_array_array *v75;
  UnityEngine_GameObject_array *v76;
  s64 v80;
  struct UnityEngine_GameObject_array_array *v82;
  u64 v83;
  struct UnityEngine_GameObject_array_array *v86;
  u32 *v88;
  UnityEngine_GameObject_o *v89;
  UnityEngine_Transform_o *v91;
  s64 *v92;
  s64 *v93;
  struct UnityEngine_GameObject_array_array *v95;
  UnityEngine_GameObject_array *v97;
  s64 v100;
  struct UnityEngine_GameObject_array_array *v102;
  u64 v103;
  struct UnityEngine_GameObject_array_array *v106;
  u32 *v108;
  UnityEngine_GameObject_o *v109;
  UnityEngine_Transform_o *v111;
  s64 *v112;
  s64 *v113;
  struct UnityEngine_GameObject_array_array *v115;
  UnityEngine_GameObject_array *v117;
  char *v122;
  s64 *v123;
  effPCPDANTE_ShowTime_tag_o *v124;
  u64 v125[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPDANTE_ShowTime_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPDANTE_ShowTime_tag, v125);
    if ((v125[0] & 1) != 0)
      v122 = v125[2];
    else
      v122 = v125 + 1;
    v123 = sub_8C4940(v122);
  }
  v7 = (*hData)[2].klass;
LABEL_9:
  v8 = Allocate(effPCPDANTE_ShowTime_tag);
  _ctor(v8, 0);
  Clear(v8);
  v8[4] = v7;
  *(v8 + 14) = 0;
  *(v8 + 72) = 0;
  v124 = v8;
  asset_bc = get_asset_bc();
  Prefab_16624656 = LoadPrefab_16624656(asset_bc, "sobed_pb", "dds3data/sobed_pb/so10d_d", "so10d_d_eff1");
  v13 = v8[5];
  v14 = Prefab_16624656;
  v16 = *(v13 + 32);
  v17 = Find("Canvas_UI", 0);
  transform = get_transform(v17, 0);
  *(v16 + 72) = Instantiate_object__425664(v14, transform, 0);
  flash = v124->flash;
  v22 = flash->m_Items[1];
  v23 = Find("Canvas_UI", 0);
  v24 = get_transform(v23, 0);
  v22->obj = Instantiate_object__425664(v14, v24, 0);
  v25 = v124->flash;
  v27 = v25->m_Items[2];
  v28 = Find("Canvas_UI", 0);
  v29 = get_transform(v28, 0);
  v27->obj = Instantiate_object__425664(v14, v29, 0);
  v30 = v124->flash;
  SetActive(v30->m_Items[0]->obj, 0, 0);
  v32 = v124->flash;
  SetActive(v32->m_Items[1]->obj, 0, 0);
  v34 = v124->flash;
  SetActive(v34->m_Items[2]->obj, 0, 0);
  if (!effPCPDANTE_Sprite)
  {
    v37 = NewSpecific(UnityEngine_GameObject__, 3u);
    effPCPDANTE_Sprite = v37;
    v40 = NewSpecific(UnityEngine_GameObject, 6u);
    v41 = v40;
    effPCPDANTE_Sprite->m_Items[0] = v41;
    v43 = effPCPDANTE_Sprite;
    v44 = NewSpecific(UnityEngine_GameObject, 0x13u);
    v45 = v44;
    v43->m_Items[1] = v45;
    v48 = effPCPDANTE_Sprite;
    v49 = NewSpecific(UnityEngine_GameObject, 8u);
    v51 = v49;
    v48->m_Items[2] = v51;
    v54 = get_asset_bc();
    v55 = LoadPrefab_16624656(v54, "sobed_pb", "dds3data/sobed_pb/so10d_d", "so10d_d_0_sprite_a");
    v56 = get_asset_bc();
    v57 = LoadPrefab_16624656(v56, "sobed_pb", "dds3data/sobed_pb/so10d_d", "so10d_d_0_sprite_b");
    v58 = get_asset_bc();
    v60 = LoadPrefab_16624656(v58, "sobed_pb", "dds3data/sobed_pb/so10d_d", "so10d_d_1_sprite_a");
    v61 = 4;
    {
LABEL_51:
      goto LABEL_53;
    }
    while (1)
    {
LABEL_53:
      v63 = effPCPDANTE_Sprite;
      v64 = v61 - 4;
      if (v64 >= SLODWORD(v63->m_Items[0]->max_length))
        break;
      else
      {
        v66 = effPCPDANTE_Sprite;
        if (!LODWORD(v66->max_length))
          goto LABEL_59;
      }
      v68 = v66->m_Items[0];
      v69 = Find("Canvas_UI", 0);
      v71 = get_transform(v69, 0);
      v72 = Instantiate_object__425664(v55, v71, 0);
      v73 = v72;
      *&v68[2 * v61] = v73;
      v75 = effPCPDANTE_Sprite;
      v76 = v75->m_Items[0];
      SetActive(*(&v76->obj.klass + v61++), 0, 0);
        goto LABEL_51;
    }
    v80 = 4;
      goto LABEL_79;
LABEL_77:
    while (1)
    {
LABEL_79:
      v82 = effPCPDANTE_Sprite;
      v83 = v80 - 4;
      if (v83 >= SLODWORD(v82->m_Items[1]->max_length))
        break;
      v86 = effPCPDANTE_Sprite;
      v88 = v86->m_Items[1];
      v89 = Find("Canvas_UI", 0);
      v91 = get_transform(v89, 0);
      v92 = Instantiate_object__425664(v57, v91, 0);
      v93 = v92;
      *&v88[2 * v80] = v93;
      v95 = effPCPDANTE_Sprite;
      v97 = v95->m_Items[1];
      SetActive(*(&v97->obj.klass + v80++), 0, 0);
        goto LABEL_77;
    }
    v100 = 4;
      goto LABEL_104;
LABEL_102:
    while (1)
    {
LABEL_104:
      v102 = effPCPDANTE_Sprite;
      v103 = v100 - 4;
      if (v103 >= SLODWORD(v102->m_Items[2]->max_length))
        break;
      v106 = effPCPDANTE_Sprite;
      v108 = v106->m_Items[2];
      v109 = Find("Canvas_UI", 0);
      v111 = get_transform(v109, 0);
      v112 = Instantiate_object__425664(v60, v111, 0);
      v113 = v112;
      *&v108[2 * v100] = v113;
      v115 = effPCPDANTE_Sprite;
      v117 = v115->m_Items[2];
      SetActive(*(&v117->obj.klass + v100++), 0, 0);
        goto LABEL_102;
    }
  }
  return v124;
}

// 0x11f0d80
effPCPDANTE_ShowTime_tag *effPCPDANTE_ShowTime_Create(effPCPDANTE_ShowTime_Param_t *pParam, void *pTMX0, void *pTMX1) {
  u64 *v7;

  v7 = Allocate(effPCPDANTE_ShowTime_tag);
  _ctor(v7, 0);
  Clear(v7);
  v7[4] = pParam;
  *(v7 + 14) = 0;
  if (pTMX0 && pTMX1)
    *(v7 + 72) = 1;
  return v7;
}

// 0x11f10f0
effPCPDANTE_ShowTime_tag *effPCPDANTE_ShowTime_CreatePCF(void **hData, s32 bPos, bool tbldata) {
  dds3EffectPCPData_t_o *v6;
  Il2CppObject *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  struct dds3EffectPCPData_Part_t_array *pcpData;
  Il2CppObject *v14;
  u32 offset;
  Il2CppObject *DataUnityOffSet;
  struct dds3EffectPCPData_Part_t_array *v19;
  Il2CppObject *v20;
  Il2CppObject *v21;
  u32 v23;
  Il2CppObject *EffPCPAgiFireballPart;
  struct dds3EffectPCPData_Part_t_array *v25;
  Il2CppObject *v26;
  Il2CppObject *v27;
  Il2CppObject *v30;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v33;
  s64 *v34;
  u64 *v35;
  s32 pos;
  u64 v39[2];
  char *v40;

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v7->klass->_1.element_class, v8, v39);
      if ((v39[0] & 1) != 0)
        v10 = v40;
      else
        v10 = v39 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v6, Interface, &pos);
  pcpData = v6->pcpData;
  v14 = *hData;
  offset = pcpData->m_Items[0]->offset;
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 53);
  v19 = v6->pcpData;
  v20 = *hData;
  v21 = DataUnityOffSet;
  v23 = v19->m_Items[1]->offset;
  EffPCPAgiFireballPart = GetEffPCPAgiFireballPart(v20, v23 + bPos);
  v25 = v6->pcpData;
  v26 = *hData;
  v27 = EffPCPAgiFireballPart;
  v30 = GetEffPCPAgiFireballPart(v26, v25->m_Items[2]->offset + bPos);
  else if (!v21)
  {
    goto LABEL_31;
  }
  klass = v21->klass;
  if (v21->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPDANTE_ShowTime_Param_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPDANTE_ShowTime_Param_t, v39);
    if ((v39[0] & 1) != 0)
      v33 = v40;
    else
      v33 = v39 + 1;
    v34 = sub_8C4940(v33);
  }
LABEL_31:
  v35 = Allocate(effPCPDANTE_ShowTime_tag);
  _ctor(v35, 0);
  Clear(v35);
  v35[4] = v21;
  *(v35 + 14) = 0;
  if (v27 && v30)
    *(v35 + 72) = 1;
  return v35;
}

// 0x11f1f30
void effPCPDANTE_ShowTime_Delete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  effPCPBoss_c *v8;
  s64 v9;
  struct UnityEngine_GameObject_array_array *effPCPDANTE_Sprite;
  u64 v11;
  struct UnityEngine_GameObject_array_array *v13;
  UnityEngine_GameObject_array *v14;
  UnityEngine_Object_o *v15;
  struct UnityEngine_GameObject_array_array *v18;
  UnityEngine_GameObject_array *v19;
  s64 v22;
  struct UnityEngine_GameObject_array_array *v24;
  u64 v25;
  struct UnityEngine_GameObject_array_array *v28;
  UnityEngine_GameObject_array *v29;
  UnityEngine_Object_o *v30;
  struct UnityEngine_GameObject_array_array *v33;
  UnityEngine_GameObject_array *v35;
  s64 v37;
  struct UnityEngine_GameObject_array_array *v39;
  u64 v40;
  struct UnityEngine_GameObject_array_array *v42;
  UnityEngine_GameObject_array *v43;
  UnityEngine_Object_o *v44;
  struct UnityEngine_GameObject_array_array *v47;
  UnityEngine_GameObject_array *v49;
  u64 *monitor;
  s64 v52;
  s64 v53;
  u64 v54;
  UnityEngine_Object_o *v56;
  u64 *v57;
  UnityEngine_Object_o *v59;
  u64 *v60;
  s64 v62;
  u64 v63[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPDANTE_ShowTime_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPDANTE_ShowTime_tag, v63);
      if ((v63[0] & 1) != 0)
        v6 = v63[2];
      else
        v6 = v63 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  if (effPCPDANTE_Sprite)
  {
    v9 = 4;
    if ((v8->_2.bitflags2 & 2) == 0)
      goto LABEL_19;
LABEL_17:
    while (1)
    {
LABEL_19:
      v11 = v9 - 4;
      if (v11 >= SLODWORD(effPCPDANTE_Sprite->m_Items[0]->max_length))
        break;
      else
      {
        v13 = effPCPDANTE_Sprite;
        if (!LODWORD(v13->max_length))
          goto LABEL_30;
      }
      v14 = v13->m_Items[0];
      v15 = *(&v14->obj.klass + v9);
      Destroy_27360000(v15);
      v18 = effPCPDANTE_Sprite;
      v19 = v18->m_Items[0];
      *(&v19->obj.klass + v9) = 0;
      ++v9;
        goto LABEL_17;
    }
    v22 = 4;
      goto LABEL_41;
LABEL_39:
    while (1)
    {
LABEL_41:
      v24 = effPCPDANTE_Sprite;
      v25 = v22 - 4;
      if (v25 >= SLODWORD(v24->m_Items[1]->max_length))
        break;
      v28 = effPCPDANTE_Sprite;
      v29 = v28->m_Items[1];
      v30 = *(&v29->obj.klass + v22);
      Destroy_27360000(v30);
      v33 = effPCPDANTE_Sprite;
      v35 = v33->m_Items[1];
      *(&v35->obj.klass + v22++) = 0;
        goto LABEL_39;
    }
    v37 = 4;
      goto LABEL_63;
LABEL_61:
    while (1)
    {
LABEL_63:
      v39 = effPCPDANTE_Sprite;
      v40 = v37 - 4;
      if (v40 >= SLODWORD(v39->m_Items[2]->max_length))
        break;
      v42 = effPCPDANTE_Sprite;
      v43 = v42->m_Items[2];
      v44 = *(&v43->obj.klass + v37);
      Destroy_27360000(v44);
      v47 = effPCPDANTE_Sprite;
      v49 = v47->m_Items[2];
      *(&v49->obj.klass + v37++) = 0;
        goto LABEL_61;
    }
  }
  effPCPDANTE_Sprite = 0;
  monitor = v3[2].monitor;
  v52 = monitor[3];
  if (v52 >= 1)
  {
    v53 = 4;
    do
    {
      v54 = v53 - 4;
      v56 = *(monitor[v53] + 72LL);
      if (op_Inequality(v56, 0, 0))
      {
        v57 = v3[2].monitor;
        v59 = *(v57[v53] + 72LL);
        Destroy_27360000(v59);
        v60 = v3[2].monitor;
        *(v60[v53] + 72LL) = 0;
      }
      monitor = v3[2].monitor;
      LODWORD(v52) = *(monitor + 6);
      v62 = v53 - 3;
      ++v53;
    }
    while (v62 < v52);
  }
}

// 0x11f3c70
void effPCPDANTE_ShowTime_Draw(void **hData) {
  effPCPDANTE_ShowTime_tag_o *v3;
  effPCPDANTE_ShowTime_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s32 frame;
  struct nbPanelFlashData_t_array *flash;
  struct nbPanelFlashData_t_array *v11;
  struct nbPanelFlashData_t_array *v13;
  struct nbPanelFlashData_t_array *v17;
  struct nbPanelFlashData_t_array *v21;
  struct nbPanelFlashData_t_array *v25;
  effPCPDANTE_ShowTime_tag_o *v28;
  u64 v29[3];

  v28 = 0;
  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPDANTE_ShowTime_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPDANTE_ShowTime_tag, v29);
      if ((v29[0] & 1) != 0)
        v6 = v29[2];
      else
        v6 = v29 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v28 = v3;
  frame = v3->frame;
  if (!frame)
  {
    flash = v3->flash;
    else if (!LODWORD(flash->max_length))
    {
      goto LABEL_17;
    }
    nbPanelFlashInit(flash->m_Items, 0.45, 0.35, 0x43BBFFu, 0x12A2F5u, 160, 92);
    v11 = v3->flash;
    nbPanelFlashInit(&v11->m_Items[1], 0.55, 0.45, 0x3664FFu, 0x3CF0u, -140, -60);
    v13 = v3->flash;
    nbPanelFlashInit(&v13->m_Items[2], 1.5, 2.0, 0x31109Fu, 0x8D64C8u, 0, 20);
  }
  effPCPDANTE_Sprite_DrawOff();
  if ((frame & 0x80000000) == 0)
  {
    v17 = v3->flash;
    else if (!LODWORD(v17->max_length))
    {
      goto LABEL_30;
    }
    nbPanelFlashDraw(v17->m_Items, 0x80808080);
    effPCPDANTE_ShowTime_Bingo_Draw(&v28);
    if (frame >= 22)
    {
      v21 = v3->flash;
      nbPanelFlashDraw(&v21->m_Items[1], 0x80808080);
      effPCPDANTE_ShowTime_AreYouReady_Draw(&v28);
      if (frame >= 92)
      {
        v25 = v3->flash;
        nbPanelFlashDraw(&v25->m_Items[2], 0x80808080);
        effPCPDANTE_ShowTime_ShowTime_Draw(&v28);
      }
    }
  }
  ++v3->frame;
}

// 0x11f4050
void effPCPDANTE_ShowTime_SetPosition(void **hData, sdfVector4_t pPos) {
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
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != effPCPDANTE_ShowTime_tag)
    {
      sub_8FC2C0(*(v9 + 64), effPCPDANTE_ShowTime_tag, v13);
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

// 0x11f3780
void effPCPDANTE_ShowTime_ShowTime_Draw(effPCPDANTE_ShowTime_tag **pPCPShowTime) {
  struct System_Int32_array *frameParts;
  u32 v5;
  sdfTexHandle_t_o *v8;
  f32 v10;
  f32 v11;
  s32 v12;
  u32 v14;
  sdfTexHandle_t_o *v15;
  effPCPDANTE_UV_tag_o *effPCPDANTE_ShowTime_UV;
  f32 v18;
  u32 v19;
  s32 v20;
  f32 v22;
  u8 v23;
  u8 v24;
  s32 v26;
  sdfTexHandle_t_o *v28;
  sdfTexHandle_t_o *v32;
  f32 v34;
  sdfTexHandle_t_o *v36;
  sdfTexHandle_t_o *v39;
  f32 v41;
  struct System_Int32_array *v43;

  frameParts = (*pPCPShowTime)->frameParts;
  v5 = frameParts->m_Items[2];
  if (v5 - 23 <= 0xC)
  {
    nbPnl_rsetAlpha(0);
    v22 = ((v5 - 23) / -12.0) + 1.0;
    v23 = vcvts_n_s32_f32(v22, 7u);
    v24 = vcvts_n_u32_f32(v22, 7u);
    if ((v22 * 128.0) < 0.0)
      v24 = v23;
    v26 = (v24 << 24) | 0x808080;
    v18 = 1.0;
    v19 = v26;
    v20 = 0;
    goto LABEL_50;
  }
  if (v5 - 10 <= 0xC)
  {
    nbPnl_rsetAlpha(0);
    effPCPDANTE_Sprite_Draw(162, 172, 1.0, 0x80808080, effPCPDANTE_ShowTime_UV, v28, 2, 1);
    if (v5 > 0xC)
      goto LABEL_10;
  }
  else if (v5 > 0xC)
  {
    goto LABEL_10;
  }
  nbPnl_rsetAlpha(1);
  v34 = (v5 / -12.0) + 1.0;
  effPCPDANTE_Sprite_Draw(
    162,
    172,
    (v34 * (v34 + v34)) + 1.0,
    0x20808080u,
    effPCPDANTE_ShowTime_UV,
    v32,
    2,
    2);
  effPCPDANTE_Sprite_Draw(
    162,
    172,
    (v34 * (v34 * 1.5)) + 1.0,
    0x20808080u,
    effPCPDANTE_ShowTime_UV,
    v36,
    2,
    3);
  if (v5 <= 6)
  {
    nbPnl_rsetAlpha(1);
    v41 = v5 / 6.0;
    effPCPDANTE_Sprite_Draw(
      162,
      172,
      (v41 * v41) + 1.0,
      0x10808080u,
      effPCPDANTE_ShowTime_UV,
      v39,
      2,
      4);
    v20 = 5;
    v19 = 276856960;
    v18 = (v41 * (v41 * 0.75)) + 1.0;
    goto LABEL_50;
  }
LABEL_10:
  if (v5 - 8 > 0xE)
    goto LABEL_51;
  nbPnl_rsetAlpha(1);
  v10 = (v5 - 8) / 14.0;
  v11 = (1.0 - v10) * 84.0;
  v12 = v11;
  if (v11 >= 0.0)
    LOBYTE(v12) = v11;
  v14 = (v12 << 24) | 0x808080;
  effPCPDANTE_Sprite_Draw(
    162,
    172,
    (v10 * 0.75) + 1.0,
    v14,
    effPCPDANTE_ShowTime_UV,
    v8,
    2,
    6);
  v18 = (v10 * 0.325) + 1.0;
  v19 = v14;
  v20 = 7;
LABEL_50:
  effPCPDANTE_Sprite_Draw(162, 172, v18, v19, effPCPDANTE_ShowTime_UV, v15, 2, v20);
LABEL_51:
  v43 = (*pPCPShowTime)->frameParts;
  ++v43->m_Items[2];
}

// 0x11f2920
void effPCPDANTE_Sprite_Draw(s32 x, s32 y, f32 scale, u32 abgr, effPCPDANTE_UV_tag *pUV, sdfTexHandle_t *hTex, s32 type, s32 index) {
  struct UnityEngine_GameObject_array_array *effPCPDANTE_Sprite;
  s64 v18;
  UnityEngine_GameObject_array *v20;
  UnityEngine_GameObject_o *v22;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v24;
  f32 v25;
  f32 v26;
  f32 v27;
  f32 v28;
  s32 width;
  s32 v30;
  f32 v31;
  s32 height;
  s32 v33;
  f32 v34;
  UnityEngine_Transform_o *v35;
  UnityEngine_Transform_o *v36;
  UnityEngine_Transform_o *v37;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  s64 v43;
  s64 v44;
  UnityEngine_Vector4_o v45;
  UnityEngine_Vector3_o v46;
  UnityEngine_Vector3_o v47;

  if (effPCPDANTE_Sprite)
  {
    else
    {
      v18 = type;
      if (LODWORD(effPCPDANTE_Sprite->max_length) <= type)
        goto LABEL_10;
    }
    v20 = effPCPDANTE_Sprite->m_Items[v18];
    v22 = v20->m_Items[index];
    SetActive(v22, 1, 0);
    transform = get_transform(v22, 0);
    get_position(transform);
    v24 = get_transform(v22, 0);
    get_localScale(v24);
    v25 = ((pUV->w >> 1) + x) + -256.0;
    v26 = ((pUV->h >> 1) + y) + -224.0;
    v27 = (get_width(0) * 0.0019531) * v25;
    v28 = (get_height(0) / -448.0) * v26;
    width = get_width(0);
    if (width >= 0)
      v30 = width;
    else
      v30 = width + 1;
    v31 = v27 + (v30 >> 1);
    height = get_height(0);
    if (height >= 0)
      v33 = height;
    else
      v33 = height + 1;
    v34 = (v33 >> 1) + v28;
    v35 = get_transform(v22, 0);
    v46.z = 0.0;
    v46.x = v31;
    v46.y = v34;
    set_position(v35, v46);
    v36 = get_transform(v22, 0);
    v47.z = 1.0;
    v47.x = scale * 2.5;
    v47.y = scale * 2.5;
    set_localScale(v36, v47);
    v37 = get_transform(v22, 0);
    Child = GetChild(v37, 0);
    gameObject = get_gameObject(Child);
    if (op_Inequality(gameObject, 0, 0))
    {
      Component_object = GetComponent_object_(gameObject);
      if (op_Inequality(Component_object, 0, 0))
      {
        v45 = SDF_VU0__Retdds3ColorItoF(abgr, 128.0);
        v43 = 0;
        v44 = 0;
        sub_19EC630(&v43, v45.x, v45.y, v45.z, v45.w);
        (Component_object->klass->vtable[23].methodPtr)(
          Component_object,
          Component_object->klass->vtable[23].*&v43,
          *(&v43 + 1),
          *&v44,
          *(&v44 + 1));
      }
    }
  }
}

// 0x11f25d0
void effPCPDANTE_Sprite_DrawOff(void) {
  effPCPBoss_c *v2;
  u64 v3;
  struct UnityEngine_GameObject_array_array *effPCPDANTE_Sprite;
  struct UnityEngine_GameObject_array_array *v6;
  UnityEngine_GameObject_array *v7;
  u64 v10;
  struct UnityEngine_GameObject_array_array *v12;
  struct UnityEngine_GameObject_array_array *v15;
  UnityEngine_GameObject_array *v17;
  u64 v19;
  struct UnityEngine_GameObject_array_array *v21;
  struct UnityEngine_GameObject_array_array *v24;
  UnityEngine_GameObject_array *v26;

  else if (!effPCPDANTE_Sprite)
  {
    return;
  }
  v3 = 0;
  if ((v2->_2.bitflags2 & 2) != 0)
    goto LABEL_9;
LABEL_10:
  if (!LODWORD(effPCPDANTE_Sprite->max_length))
  {
LABEL_11:
  }
  while (v3 < SLODWORD(effPCPDANTE_Sprite->m_Items[0]->max_length))
  {
    else
    {
      v6 = effPCPDANTE_Sprite;
      if (!LODWORD(v6->max_length))
        goto LABEL_21;
    }
    v7 = v6->m_Items[0];
    SetActive(v7->m_Items[v3], 0, 0);
    ++v3;
      goto LABEL_10;
LABEL_9:
      goto LABEL_10;
    if (!LODWORD(effPCPDANTE_Sprite->max_length))
      goto LABEL_11;
  }
  v10 = 0;
    goto LABEL_27;
LABEL_25:
  while (1)
  {
LABEL_27:
    v12 = effPCPDANTE_Sprite;
    if (v10 >= SLODWORD(v12->m_Items[1]->max_length))
      break;
    v15 = effPCPDANTE_Sprite;
    v17 = v15->m_Items[1];
    SetActive(v17->m_Items[v10++], 0, 0);
      goto LABEL_25;
  }
  v19 = 0;
    goto LABEL_42;
LABEL_40:
  while (1)
  {
LABEL_42:
    v21 = effPCPDANTE_Sprite;
    if (v19 >= SLODWORD(v21->m_Items[2]->max_length))
      break;
    v24 = effPCPDANTE_Sprite;
    v26 = v24->m_Items[2];
    SetActive(v26->m_Items[v19++], 0, 0);
      goto LABEL_40;
  }
}

// 0x11ee8c0
effPCPDANTE_Thunder_tag *effPCPDANTE_Thunder_Copy(void **hData, s32 bPos, bool tbldata) {
  effPCPDANTE_Thunder_tag_c *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v8;
  char *v10;
  s64 *v11;
  u64 v12[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPDANTE_Thunder_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPDANTE_Thunder_tag, v12);
    if ((v12[0] & 1) != 0)
      v10 = v12[2];
    else
      v10 = v12 + 1;
    v11 = sub_8C4940(v10);
  }
  v8 = (*hData)[6].klass;
  return effPCPDANTE_Thunder_Create(v8, v5);
}

// 0x11ee290
effPCPDANTE_Thunder_tag *effPCPDANTE_Thunder_Create(effPCPDANTE_Thunder_Param_t *pParam) {
  u64 *v3;
  u64 *v4;
  effPCP_ThunderPoly_t_o *v6;
  effPCP_ThunderPolyParam_t_o *Param;
  struct UnityEngine_Vector4_array *pos;
  effPCP_ThunderPolyParam_t_o *v9;
  struct UnityEngine_Vector4_array *v11;
  u64 *v13;
  Il2CppObject *hData;

  hData = 0;
  v3 = Allocate(effPCPDANTE_Thunder_tag);
  _ctor(v3, 0);
  v3[2] = 0;
  v3[16] = 0;
  *(v3 + 117) = 0;
  v3[13] = 0;
  v3[14] = 0;
  v3[10] = 0;
  v3[11] = 0;
  v3[5] = 0;
  v3[8] = 0;
  v3[9] = 0;
  v3[12] = 0;
  v3[6] = 0;
  v3[7] = 0;
  v3[3] = 0;
  v3[4] = 0;
  v4 = Allocate(effPCPDANTE_Thunder_Param_t);
  effPCPDANTE_Thunder_Param_t___ctor(v4);
  v3[12] = v4;
  effPCPDANTE_Thunder_Param_t__pClone(pParam, v3 + 12);
  *(v3 + 27) = -2139062144;
  SetRotateMatrixZ(-1.5708);
  SDF_VU0__STOREMATRIX((v3 + 4), 0);
  SDF_VU0__STOREIDENTITYVECTOR(v3 + 1);
  hData = *(v3[12] + 16);
  v6 = effPCP_ThunderPolyCreate(&hData, 0, 1, 0);
  v3[14] = v6;
  Param = effPCP_ThunderPolyGetParam(v6);
  pos = Param->pos;
  v9 = Param;
  SDF_VU0__LOADVECTOR(pos->m_Items[0]);
  v11 = v9->pos;
  SDF_VU0__LOADVECTOR_B(v11->m_Items[1]);
  SDF_VU0__SUBVECTOR();
  *(v3 + 26) = SDF_VU0__GETLENGTH();
  *(v3 + 124) = 0;
  *(v3 + 30) = 0;
  v13 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v13,
    0,
    Method_effPCPBoss_effPCPDANTE_Thunder_ProcessDraw__);
  v3[16] = dds3StartProcess("eff_DANTE_thunder", 0x2B0Au, 0, 0, v13, 0, 0, 0, 0, 0);
  dds3SetProcessData(v3 + 16, v3);
  return v3;
}

// 0x11ee170
effPCPDANTE_Thunder_tag *effPCPDANTE_Thunder_CreateP(void **pData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v11[3];

  v5 = *pData;
  else if (!v5)
  {
    return effPCPDANTE_Thunder_Create(v5, *&bPos);
  }
  klass = v5->klass;
  if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPDANTE_Thunder_Param_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPDANTE_Thunder_Param_t, v11);
    if ((v11[0] & 1) != 0)
      v8 = v11[2];
    else
      v8 = v11 + 1;
    v9 = sub_8C4940(v8);
  }
  return effPCPDANTE_Thunder_Create(v5, *&bPos);
}

// 0x11ee540
effPCPDANTE_Thunder_tag *effPCPDANTE_Thunder_CreatePCF(void **hData, s32 bPos, bool tbldata) {
  dds3EffectPCPData_t_o *v6;
  Il2CppObject *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  struct dds3EffectPCPData_Part_t_array *pcpData;
  Il2CppObject *v14;
  u32 offset;
  effPCPDANTE_Thunder_Param_t_c *v17;
  Il2CppObject *DataUnityOffSet;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v21;
  s64 *v22;
  u64 v24[2];
  char *v25;
  s32 pos;

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v7->klass->_1.element_class, v8, v24);
      if ((v24[0] & 1) != 0)
        v10 = v25;
      else
        v10 = v24 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v6, Interface, &pos);
  pcpData = v6->pcpData;
  v14 = *hData;
  offset = pcpData->m_Items[0]->offset;
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 50);
  else if (!DataUnityOffSet)
  {
    return effPCPDANTE_Thunder_Create(DataUnityOffSet, v17);
  }
  klass = DataUnityOffSet->klass;
  if (DataUnityOffSet->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPDANTE_Thunder_Param_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPDANTE_Thunder_Param_t, v24);
    if ((v24[0] & 1) != 0)
      v21 = v25;
    else
      v21 = v24 + 1;
    v22 = sub_8C4940(v21);
  }
  return effPCPDANTE_Thunder_Create(DataUnityOffSet, v17);
}

// 0x11ee780
void effPCPDANTE_Thunder_Delete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppClass *v8;
  u64 v9[3];

  v8 = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPDANTE_Thunder_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPDANTE_Thunder_tag, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  dds3KillProcess(&v3[8], 0);
  v8 = v3[7].klass;
  effPCP_ThunderPolyDelete(&v8);
}

// 0x11edef0
void effPCPDANTE_Thunder_Draw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  f32 v8;
  Il2CppClass *v9;
  s32 namespaze_high;
  s32 monitor;
  s32 v12;
  s32 data_high;
  s32 data;
  effPCP_ThunderPolyParam_t_o *Param;
  struct UnityEngine_Vector4_array *pos;
  struct UnityEngine_Vector4_array *v18;
  f32 v20;
  f32 v21;
  u32 v22;
  UnityEngine_Matrix4x4_o v23;
  Il2CppObject *hDataa;
  UnityEngine_Vector4_o v25;
  u64 v26[3];

  *&v25.x = 0;
  *&v25.z = 0;
  hDataa = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPDANTE_Thunder_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPDANTE_Thunder_tag, v26);
      if ((v26[0] & 1) != 0)
        v6 = v26[2];
      else
        v6 = v26 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = 1.0;
  sub_854690(&v25.x, 1.0, 0.0, 0.0, 0.0);
  v9 = v3[6].klass;
  namespaze_high = HIDWORD(v9->_1.namespaze);
  monitor = v3[7].monitor;
  v12 = namespaze_high - monitor;
  if (namespaze_high >= monitor)
  {
    data = v9->_1.byval_arg.data;
    data_high = HIDWORD(v9->_1.byval_arg.data);
    Param = effPCP_ThunderPolyGetParam(v3[7].klass);
    memmove(&v23, &v3[2], 0x40u);
    SDF_VU0__LOADMATRIX(&v23);
    SDF_VU0__LOADVECTOR_B(v25);
    SDF_VU0__APPLYMATRIX_B();
    SDF_VU0__SCALEVECTOR_B(*&v3[6].monitor);
    SDF_VU0__LOADVECTOR(v3[1]);
    pos = Param->pos;
    SDF_VU0__STOREVECTOR(pos->m_Items);
    SDF_VU0__ADDVECTOR();
    v18 = Param->pos;
    SDF_VU0__STOREVECTOR(&v18->m_Items[1]);
    if (monitor < data && data)
    {
      v20 = monitor;
      v21 = data;
    }
    else
    {
      if (v12 > data_high || !data_high)
        goto LABEL_22;
      v20 = v12;
      v21 = data_high;
    }
    v8 = v20 / v21;
LABEL_22:
    v22 = effColorBlend(HIDWORD(v3[6].monitor) & 0xFFFFFF, HIDWORD(v3[6].monitor), v8, 0);
    hDataa = v3[7].klass;
    effPCP_ThunderPolySetColor(&hDataa, v22);
    effPCP_ThunderPolyDraw(&hDataa);
    ++LODWORD(v3[7].monitor);
  }
}

// 0x11ee9d0
void effPCPDANTE_Thunder_DrawSub(void **hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  u64 v7[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPDANTE_Thunder_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPDANTE_Thunder_tag, v7);
    if ((v7[0] & 1) != 0)
      v5 = v7[2];
    else
      v5 = v7 + 1;
    v6 = sub_8C4940(v5);
  }
  BYTE4((*hData)[7].monitor) = 1;
}

// 0x11ed9e0
void *effPCPDANTE_Thunder_ProcessDraw(dds3ProcessID_t *id) {
  Il2CppObject *ProcessData;
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u32 namespaze;
  UnityEngine_Matrix4x4_o v16;
  UnityEngine_Matrix4x4_o v17;
  Il2CppObject *hData;
  UnityEngine_Vector4_o p;
  UnityEngine_Matrix4x4_o aMatrix;
  nbFormation_t_o *pFormation;
  dds3ProcessID_t_o *ida;

  ida = id;
  hData = 0;
  pFormation = 0;
  memset(&aMatrix, 0, sizeof(aMatrix));
  *&p.x = 0;
  *&p.z = 0;
  ProcessData = dds3GetProcessData(&ida);
  v4 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPDANTE_Thunder_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPDANTE_Thunder_tag, &v17);
      if ((LOBYTE(v17.m00) & 1) != 0)
        v7 = *&v17.m01;
      else
        v7 = &v17.m00 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  if (BYTE4(ProcessData[7].monitor))
  {
    hData = ProcessData;
    if (effBTLSkillCheckRun())
    {
      pFormation = effBTLSkillGetInvokeFormation(0);
      namespaze = v4[6].klass->_1.namespaze;
      effBTLModelGetMarkMatrix2(&pFormation, namespaze);
      SDF_VU0__STOREMATRIX(&aMatrix);
      v17 = aMatrix;
      v16 = v17;
      effPCPDANTE_Thunder_SetRotateMatrix(&hData, &v16);
      effBTLModelGetMarkPosition2(&pFormation, v4[6].klass->_1.namespaze);
      SDF_VU0__STOREVECTOR(&p);
      effPCPDANTE_Thunder_SetPosition(&hData, p);
    }
    effPCPDANTE_Thunder_Draw(&hData);
    BYTE4(v4[7].monitor) = 0;
  }
  return 0;
}

// 0x11eeac0
void effPCPDANTE_Thunder_SetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPDANTE_Thunder_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPDANTE_Thunder_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[6].monitor) = abgr;
}

// 0x11eddc0
void effPCPDANTE_Thunder_SetPosition(void **hData, sdfVector4_t pPos) {
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
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != effPCPDANTE_Thunder_tag)
    {
      sub_8FC2C0(*(v9 + 64), effPCPDANTE_Thunder_tag, v13);
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

// 0x11edc90
void effPCPDANTE_Thunder_SetRotateMatrix(void **hData, sdfMatrix4_t *pRot) {
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

  v5 = *&pRot->m00;
  v6 = *&pRot->m20;
  v7 = *hData;
  v8 = *&pRot->m21;
  *&v16.m01 = *&pRot->m01;
  *&v16.m21 = v8;
  *&v16.m00 = v5;
  *&v16.m20 = v6;
  v9 = *&pRot->m02;
  v10 = *&pRot->m22;
  v11 = *&pRot->m23;
  *&v16.m03 = *&pRot->m03;
  *&v16.m23 = v11;
  *&v16.m02 = v9;
  *&v16.m22 = v10;
  SDF_VU0__LOADMATRIX(&v16);
  if (v7)
  {
    klass = v7->klass;
    if (v7->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPDANTE_Thunder_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPDANTE_Thunder_tag, v17);
      if ((v17[0] & 1) != 0)
        v14 = v17[2];
      else
        v14 = v17 + 1;
      v15 = sub_8C4940(v14);
    }
  }
  SDF_VU0__STOREMATRIX(&v7[2]);
}

// 0x11ecee0
effPCPMuzzleFlash_tag *effPCPMuzzleFlashCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 *v10;
  billHandle_t_o *monitor;
  u64 v14[3];

  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMuzzleFlash_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPMuzzleFlash_tag, v14);
      if ((v14[0] & 1) != 0)
        v8 = v14[2];
      else
        v8 = v14 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = Allocate(effPCPMuzzleFlash_tag);
  _ctor(v10, 0);
  v10[12] = v5[6].klass;
  v10[14] = 0x3F80000000000000LL;
  SDF_VU0__STOREIDENTITY((v10 + 2), 0);
  monitor = v5[6].monitor;
  v10[13] = dds3BillboardCopy(monitor);
  return v10;
}

// 0x11ecb60
effPCPMuzzleFlash_tag *effPCPMuzzleFlashCreate(effPCPMuzzleFlashParam_t *pParam, void *pP2A) {
  u64 *v5;

  v5 = Allocate(effPCPMuzzleFlash_tag);
  _ctor(v5, 0);
  v5[12] = pParam;
  v5[14] = 0x3F80000000000000LL;
  SDF_VU0__STOREIDENTITY((v5 + 2), 0);
  v5[13] = dds3BillboardCreate(1, pP2A, 0, "");
  return v5;
}

// 0x11ecc30
effPCPMuzzleFlash_tag *effPCPMuzzleFlashCreatePCF(void **hData, s32 bPos, bool tbldata) {
  dds3EffectPCPData_t_o *v6;
  Il2CppObject *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  struct dds3EffectPCPData_Part_t_array *pcpData;
  Il2CppObject *v14;
  u32 offset;
  Il2CppObject *DataUnityOffSet;
  struct dds3EffectPCPData_Part_t_array *v19;
  Il2CppObject *v20;
  effPCPMuzzleFlashParam_t_o *v21;
  u32 v23;
  Il2CppObject *EffPCPAgiFireballPart;
  effPCPMuzzleFlashParam_t_c *klass;
  s64 typeHierarchyDepth;
  char *v29;
  s64 *v30;
  u64 v32[2];
  char *v33;
  s32 pos;

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v7->klass->_1.element_class, v8, v32);
      if ((v32[0] & 1) != 0)
        v10 = v33;
      else
        v10 = v32 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v6, Interface, &pos);
  pcpData = v6->pcpData;
  v14 = *hData;
  offset = pcpData->m_Items[0]->offset;
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 49);
  v19 = v6->pcpData;
  v20 = *hData;
  v21 = DataUnityOffSet;
  v23 = v19->m_Items[1]->offset;
  EffPCPAgiFireballPart = GetEffPCPAgiFireballPart(v20, v23 + bPos);
  else if (!v21)
  {
    return effPCPMuzzleFlashCreate(v21, EffPCPAgiFireballPart);
  }
  klass = v21->klass;
  if (v21->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMuzzleFlashParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPMuzzleFlashParam_t, v32);
    if ((v32[0] & 1) != 0)
      v29 = v33;
    else
      v29 = v32 + 1;
    v30 = sub_8C4940(v29);
  }
  return effPCPMuzzleFlashCreate(v21, EffPCPAgiFireballPart);
}

// 0x11ed040
void effPCPMuzzleFlashDelete(void **hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  Il2CppObject *monitor;
  u64 v8[3];

  monitor = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMuzzleFlash_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPMuzzleFlash_tag, v8);
    if ((v8[0] & 1) != 0)
      v5 = v8[2];
    else
      v5 = v8 + 1;
    v6 = sub_8C4940(v5);
  }
  monitor = (*hData)[6].monitor;
  dds3BillboardDelete(&monitor);
}

// 0x11ed160
void effPCPMuzzleFlashDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  billHandle_t_o *monitor;
  s32 AnimFrame;
  s32 v12;
  f32 v17;
  f32 v18;
  f32 v19;
  f32 v20;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  f32 DirectionRotate;
  f32 DirectionScale;
  f32 v28;
  Il2CppClass *v29;
  f32 v30;
  f32 v31;
  UnityEngine_Matrix4x4_o v32;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v35;
  UnityEngine_Vector4_o v36;
  Il2CppObject *v37[3];
  Il2CppObject *hDataa;
  UnityEngine_Vector4_o v40;
  UnityEngine_Vector4_o v41;

  *&v36.x = 0;
  *&v36.z = 0;
  hDataa = 0;
  *&v35.x = 0;
  *&v35.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMuzzleFlash_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPMuzzleFlash_tag, v37);
      if ((v37[0] & 1) != 0)
        v6 = v37[2];
      else
        v6 = v37 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  sub_854690(&v36.x, 1.0, 0.0, 0.0, 0.0);
  sub_854690(&v35.x, 0.0, 1.0, 0.0, 0.0);
  *&p.x = 0;
  *&p.z = 0;
  monitor = v3[6].monitor;
  AnimFrame = dds3BillboardGetAnimFrame(monitor);
  v12 = v3[7].klass;
  if (AnimFrame > v12)
  {
    dds3BillboardSetAnimKey2(&v3[6].monitor, v12);
    else if (effBTLSkillCheckRun())
    {
      goto LABEL_20;
    }
    memmove(&v32, &v3[1], 0x40u);
    SDF_VU0__LOADMATRIX(&v32);
LABEL_29:
    SDF_VU0__LOADVECTOR(v36);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(&p);
    v17 = *&v3[5].klass;
    v18 = *(&v3[5].klass + 1);
    v19 = *&v3[5].monitor;
    v20 = *(&v3[5].monitor + 1);
    x = p.x;
    y = p.y;
    z = p.z;
    w = p.w;
    v40.x = v17;
    v40.y = v18;
    v40.z = v19;
    v40.w = v20;
    v41.x = x;
    v41.y = y;
    v41.z = z;
    v41.w = w;
    DirectionRotate = dds3BillboardGetDirectionRotate(v40, v41);
    DirectionScale = dds3BillboardGetDirectionScale(v3[5], p);
    v28 = *(&v3[7].klass + 1);
    v29 = v3[6].klass;
    v30 = v28 * *&v29->_1.name;
    v31 = (v28 * fmaxf(DirectionScale, 0.5)) * *(&v29->_1.name + 1);
    dds3BillboardSetScale(&v3[6].monitor, v31, v30);
    dds3BillboardSetRotate(&v3[6].monitor, DirectionRotate);
    dds3BillboardSetPosition(&v3[6].monitor, v3[5]);
    hDataa = v3[6].monitor;
    dds3BillboardDraw(&hDataa);
    ++LODWORD(v3[7].klass);
  }
}

// 0x11ed560
void effPCPMuzzleFlashSetColor(void **hData, u32 abgr) {
  u32 v3;
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  billHandle_t_o **p_monitor;
  u64 v11[3];

  v3 = abgr;
  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMuzzleFlash_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPMuzzleFlash_tag, v11);
      if ((v11[0] & 1) != 0)
        v8 = v11[2];
      else
        v8 = v11 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  p_monitor = &v5[6].monitor;
  dds3BillboardSetRGBA(p_monitor, v3);
}

// 0x11ed690
void effPCPMuzzleFlashSetPosition(void **hData, sdfVector4_t pPos) {
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
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != effPCPMuzzleFlash_tag)
    {
      sub_8FC2C0(*(v9 + 64), effPCPMuzzleFlash_tag, v13);
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
  SDF_VU0__COPYVECTOR(v8 + 5, v14);
}

// 0x11ed8b0
void effPCPMuzzleFlashSetRotateMatrix(void **hData, sdfMatrix4_t *pRot) {
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

  v5 = *&pRot->m00;
  v6 = *&pRot->m20;
  v7 = *hData;
  v8 = *&pRot->m21;
  *&v16.m01 = *&pRot->m01;
  *&v16.m21 = v8;
  *&v16.m00 = v5;
  *&v16.m20 = v6;
  v9 = *&pRot->m02;
  v10 = *&pRot->m22;
  v11 = *&pRot->m23;
  *&v16.m03 = *&pRot->m03;
  *&v16.m23 = v11;
  *&v16.m02 = v9;
  *&v16.m22 = v10;
  SDF_VU0__LOADMATRIX(&v16);
  if (v7)
  {
    klass = v7->klass;
    if (v7->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMuzzleFlash_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPMuzzleFlash_tag, v17);
      if ((v17[0] & 1) != 0)
        v14 = v17[2];
      else
        v14 = v17 + 1;
      v15 = sub_8C4940(v14);
    }
  }
  SDF_VU0__STOREMATRIX(&v7[1]);
}

// 0x11ed7c0
void effPCPMuzzleFlashSetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v8[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMuzzleFlash_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPMuzzleFlash_tag, v8);
    if ((v8[0] & 1) != 0)
      v6 = v8[2];
    else
      v6 = v8 + 1;
    v7 = sub_8C4940(v6);
  }
  HIDWORD((*hData)[7].klass) = 1065353216;
}

// 0x11ec390
effPCPScreenCrackModel_t *effPCPScreenCrackModelCopy(void **hData, s32 bPos, bool tbldata) {
  effPartHandle_t_o **v5;
  effPartHandle_t_o *v6;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  effPCPScreenCrackModel_t_o *v10;
  struct effPCPScreenCrackModelParam_t_o *param;
  u64 *v13;
  u64 v16[3];

  v5 = *hData;
  if (*hData)
  {
    v6 = *v5;
    if (LOBYTE((*v5)[9].klass) < typeHierarchyDepth
      || *(v6[6].monitor + typeHierarchyDepth - 1) != effPCPScreenCrackModel_t)
    {
      sub_8FC2C0(v6[2].klass, effPCPScreenCrackModel_t, v16);
      if ((v16[0] & 1) != 0)
        v8 = v16[2];
      else
        v8 = v16 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = Allocate(effPCPScreenCrackModel_t);
  effPCPScreenCrackModel_t___ctor(v10);
  param = v10->param;
LABEL_14:
  v13 = Allocate(effPCPScreenCrackModel_t);
  effPCPScreenCrackModel_t___ctor(v13);
  v13[2] = param;
  v13[4] = 0x8080808000000000LL;
  v13[3] = dds3EffectPartCopy(v5 + 3, 0, 0);
  return v13;
}

// 0x11ec000
effPCPScreenCrackModel_t *effPCPScreenCrackModelCreate(effPCPScreenCrackModelParam_t *pParam, void *pPB) {
  u64 *v5;

  v5 = Allocate(effPCPScreenCrackModel_t);
  effPCPScreenCrackModel_t___ctor(v5);
  v5[2] = pParam;
  v5[4] = 0x8080808000000000LL;
  if (pPB)
  {
    v5[3] = dds3EffectPartCreate(3u, pPB, 0, 0);
  }
  return v5;
}

// 0x11ec0e0
effPCPScreenCrackModel_t *effPCPScreenCrackModelCreatePCF(void **hData, s32 bPos, bool tbldata) {
  dds3EffectPCPData_t_o *v6;
  Il2CppObject *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  struct dds3EffectPCPData_Part_t_array *pcpData;
  Il2CppObject *v14;
  u32 offset;
  Il2CppObject *DataUnityOffSet;
  struct dds3EffectPCPData_Part_t_array *v19;
  Il2CppObject *v20;
  effPCPScreenCrackModelParam_t_o *v21;
  u32 v23;
  Il2CppObject *EffPCPAgiFireballPart;
  effPCPScreenCrackModelParam_t_c *klass;
  s64 typeHierarchyDepth;
  char *v29;
  s64 *v30;
  u64 v32[2];
  char *v33;
  s32 pos;

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v7->klass->_1.element_class, v8, v32);
      if ((v32[0] & 1) != 0)
        v10 = v33;
      else
        v10 = v32 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v6, Interface, &pos);
  pcpData = v6->pcpData;
  v14 = *hData;
  offset = pcpData->m_Items[0]->offset;
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 48);
  v19 = v6->pcpData;
  v20 = *hData;
  v21 = DataUnityOffSet;
  v23 = v19->m_Items[1]->offset;
  EffPCPAgiFireballPart = GetEffPCPAgiFireballPart(v20, v23 + bPos);
  else if (!v21)
  {
    return effPCPScreenCrackModelCreate(v21, EffPCPAgiFireballPart);
  }
  klass = v21->klass;
  if (v21->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPScreenCrackModelParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPScreenCrackModelParam_t, v32);
    if ((v32[0] & 1) != 0)
      v29 = v33;
    else
      v29 = v32 + 1;
    v30 = sub_8C4940(v29);
  }
  return effPCPScreenCrackModelCreate(v21, EffPCPAgiFireballPart);
}

// 0x11ec570
void effPCPScreenCrackModelDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  effPartHandle_t_o **p_monitor;
  u64 v9[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPScreenCrackModel_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPScreenCrackModel_t, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  p_monitor = &v3[1].monitor;
  dds3EffectPartDelete(p_monitor);
}

// 0x11ec690
void effPCPScreenCrackModelDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppObject *Handle;
  Il2CppClass *v10;
  s64 v11;
  char *v12;
  s64 *v13;
  f32 v16;
  f32 v17;
  f32 v18;
  f32 v19;
  f32 v20;
  f32 v22;
  f32 v23;
  f32 v24;
  f32 v26;
  dds3ModelHandle_t_o *v27;
  UnityEngine_Vector4_o p;
  u64 v29[2];
  char *v30;
  dds3ModelHandle_t_o *aHandle;

  v27 = 0;
  *&p.x = 0;
  v3 = *hData;
  aHandle = 0;
  *&p.z = 0;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPScreenCrackModel_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPScreenCrackModel_t, v29);
      if ((v29[0] & 1) != 0)
        v6 = v30;
      else
        v6 = v29 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  else
  {
    Handle = dds3EffectPartGetHandle(&v3[1].monitor);
    if (!Handle)
      goto LABEL_19;
  }
  v10 = Handle->klass;
  if (Handle->klass->_2.typeHierarchyDepth < v11
    || v10->_2.typeHierarchy[v11 - 1] != dds3ModelHandle_t)
  {
    sub_8FC2C0(v10->_1.element_class, dds3ModelHandle_t, v29);
    if ((v29[0] & 1) != 0)
      v12 = v30;
    else
      v12 = v29 + 1;
    v13 = sub_8C4940(v12);
  }
LABEL_19:
  aHandle = Handle;
  SDF_VU0__LOADVECTOR(dds3CameraEyePos);
  SDF_VU0__LOADVECTOR_B(dds3CameraTargetPos);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&p);
  sub_854710(&p, 1u);
  v17 = v16;
  v18 = acosf(v17);
  sub_854710(&p, 0);
  v20 = v19;
  sub_854710(&p, 2u);
  v23 = v22;
  v24 = sdfAtan2(v20, v23);
  FromEuler(3.1416 - v18, v24 + 3.1416, 0.0);
  mdlSetRotate(&aHandle);
  v26 = tanf(dds3ScreenParam->fovy * 0.5);
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__SCALEVECTOR_B(-384.0 / (v26 + v26), 0);
  SDF_VU0__LOADVECTOR(dds3CameraEyePos);
  SDF_VU0__ADDVECTOR();
  mdlSetPosition(&aHandle);
  v27 = aHandle;
  dds3EffectPartModelDraw(&v27);
  mdlEffectUpdateRot(aHandle->modelRoot->modelobj, 0);
  ++LODWORD(v3[2].klass);
}

// 0x11ebff0
void effPCPScreenCrackModelInit(effPCPScreenCrackModel_t **pPCPScrCrackModel) {
  ;
}

// 0x11eca70
void effPCPScreenCrackModelSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPScreenCrackModel_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPScreenCrackModel_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[2].klass) = abgr;
}

// 0x11f4680
effPCP_BED_tag *effPCP_BED_Copy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 *v10;
  effPCP_BED_Param_t_o *v13;
  effPCP_BED_tag_o *v14;
  effPCP_BED_tag_o *v15;
  effBTL_t_o *hBED;
  u64 v19[3];

  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_BED_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCP_BED_tag, v19);
      if ((v19[0] & 1) != 0)
        v8 = v19[2];
      else
        v8 = v19 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = Allocate(effEveBEDParams_t);
  effEveBEDParams_t___ctor(v10);
  v13 = v5[6].klass;
  v14 = effPCP_BED_Create(v13, 0);
  v14->hBED = v5[7].klass;
  v15 = v14;
  sub_854930((v10 + 2), 0);
  sub_854930((v10 + 2), 1u);
  sub_854930((v10 + 2), 2u);
  sub_854930((v10 + 2), 3u);
  sub_854930((v10 + 4), 0);
  sub_854930((v10 + 4), 1u);
  sub_854930((v10 + 4), 2u);
  sub_854930((v10 + 4), 3u);
  v10[6] = 0x42C8000042C80000LL;
  v10[7] = 0x808080803F800000LL;
  hBED = v15->hBED;
  v15->hBEDCut = effEveBEDCutCreate(hBED, 2u, v10);
  return v15;
}

// 0x11f4180
effPCP_BED_tag *effPCP_BED_Create(effPCP_BED_Param_t *pParam, void *pBED) {
  u64 *v5;
  u64 *v6;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  effBTL_t_o *v12;
  u64 v14[3];

  v5 = Allocate(effEveBEDParams_t);
  effEveBEDParams_t___ctor(v5);
  v6 = Allocate(effPCP_BED_tag);
  _ctor(v6, 0);
  v6[12] = pParam;
  v6[13] = 2155905152LL;
  SDF_VU0__STOREIDENTITYVECTOR(v6 + 5);
  SDF_VU0__STOREIDENTITY((v6 + 2), 0);
  if (pBED)
  {
    sub_854930((v5 + 2), 0);
    sub_854930((v5 + 2), 1u);
    sub_854930((v5 + 2), 2u);
    sub_854930((v5 + 2), 3u);
    sub_854930((v5 + 4), 0);
    sub_854930((v5 + 4), 1u);
    sub_854930((v5 + 4), 2u);
    sub_854930((v5 + 4), 3u);
    v5[6] = 0x42C8000042C80000LL;
    *(v5 + 14) = 1065353216;
    *(v5 + 15) = -2139062144;
    Interface = QueryInterface(pBED, byte);
    if (!Interface)
    {
      sub_8FC2C0(pBED->klass->_1.element_class, v8, v14);
      if ((v14[0] & 1) != 0)
        v10 = v14[2];
      else
        v10 = v14 + 1;
      v11 = sub_8C4940(v10);
    }
    v12 = effEveBEDCreate(Interface);
    v6[14] = v12;
    v6[15] = effEveBEDCutCreate(v12, 2u, v5);
  }
  return v6;
}

// 0x11f43d0
effPCP_BED_tag *effPCP_BED_CreatePCF(void **hData, s32 bPos, bool tbldata) {
  dds3EffectPCPData_t_o *v6;
  Il2CppObject *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  struct dds3EffectPCPData_Part_t_array *pcpData;
  Il2CppObject *v14;
  u32 offset;
  Il2CppObject *DataUnityOffSet;
  struct dds3EffectPCPData_Part_t_array *v19;
  Il2CppObject *v20;
  effPCP_BED_Param_t_o *v21;
  u32 v23;
  Il2CppObject *EffPCPAgiFireballPart;
  effPCP_BED_Param_t_c *klass;
  s64 typeHierarchyDepth;
  char *v29;
  s64 *v30;
  u64 v32[2];
  char *v33;
  s32 pos;

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v7->klass->_1.element_class, v8, v32);
      if ((v32[0] & 1) != 0)
        v10 = v33;
      else
        v10 = v32 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v6, Interface, &pos);
  pcpData = v6->pcpData;
  v14 = *hData;
  offset = pcpData->m_Items[0]->offset;
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 54);
  v19 = v6->pcpData;
  v20 = *hData;
  v21 = DataUnityOffSet;
  v23 = v19->m_Items[1]->offset;
  EffPCPAgiFireballPart = GetEffPCPAgiFireballPart(v20, v23 + bPos);
  else if (!v21)
  {
    return effPCP_BED_Create(v21, EffPCPAgiFireballPart);
  }
  klass = v21->klass;
  if (v21->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_BED_Param_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCP_BED_Param_t, v32);
    if ((v32[0] & 1) != 0)
      v29 = v33;
    else
      v29 = v32 + 1;
    v30 = sub_8C4940(v29);
  }
  return effPCP_BED_Create(v21, EffPCPAgiFireballPart);
}

// 0x11f48e0
void effPCP_BED_Delete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  effEveBEDCutHandle_t_o *monitor;
  effBTL_t_o *v10;
  u64 v11[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_BED_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCP_BED_tag, v11);
      if ((v11[0] & 1) != 0)
        v6 = v11[2];
      else
        v6 = v11 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  monitor = v3[7].monitor;
  effEveBEDCutDelete(monitor);
  v10 = v3[7].klass;
  if (!v10->CutCount)
  {
    effEveBEDDelete(v10);
  }
}

// 0x11f4ec0
void effPCP_BED_Draw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  Il2CppClass *v9;
  s32 monitor_high;
  s32 name;
  bool v12;
  s32 v13;
  s32 namespaze;
  s32 name_high;
  f32 v16;
  f32 v17;
  f32 v18;
  u32 v19;
  Il2CppClass *v21;
  void *monitor;
  void *v23;
  void *v24;
  Il2CppClass *v25;
  void *v26;
  UnityEngine_Matrix4x4_o v28;
  UnityEngine_Matrix4x4_o v29;

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_BED_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCP_BED_tag, &v29);
      if ((LOBYTE(v29.m00) & 1) != 0)
        v6 = *&v29.m01;
      else
        v6 = &v29.m00 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = Allocate(effEveBEDParams_t);
  effEveBEDParams_t___ctor(v8);
  v9 = v3[6].klass;
  monitor_high = HIDWORD(v3[6].monitor);
  name = v9->_1.name;
  v12 = __OFSUB__(name, monitor_high);
  v13 = name - monitor_high;
  if (v13 < 0 == v12)
  {
    name_high = HIDWORD(v9->_1.name);
    namespaze = v9->_1.namespaze;
    if (monitor_high < name_high && name_high)
    {
      v16 = monitor_high;
      v17 = name_high;
    }
    else
    {
      v18 = 1.0;
      if (v13 > namespaze || !namespaze)
        goto LABEL_18;
      v16 = v13;
      v17 = namespaze;
    }
    v18 = v16 / v17;
LABEL_18:
    v19 = effColorBlend(v3[6].monitor & 0xFFFFFF, v3[6].monitor, v18);
    SDF_VU0__COPYVECTOR(v8 + 1, v3[5]);
    v21 = v3[1].klass;
    monitor = v3[1].monitor;
    v23 = v3[2].monitor;
    *&v29.m01 = v3[2].klass;
    *&v29.m21 = v23;
    *&v29.m00 = v21;
    *&v29.m20 = monitor;
    v24 = v3[4].monitor;
    v25 = v3[3].klass;
    v26 = v3[3].monitor;
    *&v29.m03 = v3[4].klass;
    *&v29.m23 = v24;
    *&v29.m02 = v25;
    *&v29.m22 = v26;
    v28 = v29;
    effPCP_BED_MatrixToQuaternion(&v28);
    SDF_VU0__STOREVECTOR(v8 + 2);
    v8[6] = 0x42C8000042C80000LL;
    *(v8 + 14) = 1065353216;
    *(v8 + 15) = v19;
    effEveBEDCutSetParams(&v3[7].monitor, v8);
    effEveBEDCutDraw(&v3[7].monitor);
    ++HIDWORD(v3[6].monitor);
  }
}

// 0x11f4a30
void effPCP_BED_MatrixToQuaternion(sdfMatrix4_t *pMatrix) {
  f32 v3;
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;
  f32 v8;
  f32 v10;
  f32 v11;
  f32 v12;
  f32 v13;
  f32 v14;
  _BOOL4 v15;
  f32 v16;
  f32 v17;
  f32 v18;
  s32 v19;
  u32 v20;
  u32 v21;
  f32 v22;
  f32 v23;
  f32 v24;
  f32 v25;
  f32 v27;
  f32 v28;
  u32 v29;
  UnityEngine_Vector4_o v30;

  *&v30.x = 0;
  *&v30.z = 0;
  sub_19FFB10(pMatrix, 0, 0);
  v4 = v3;
  sub_19FFB10(pMatrix, 1, 1);
  v6 = v5;
  sub_19FFB10(pMatrix, 2, 2);
  v8 = v7;
  sub_19FFB10(pMatrix, 3, 3);
  v11 = ((v4 + v6) + v8) + v10;
  if (v11 >= 1.0)
  {
    sdfSqrt(v11);
    sub_854930(&v30, 3u);
    sub_19FFB10(pMatrix, 1, 2);
    sub_19FFB10(pMatrix, 2, 1);
    sub_854930(&v30, 0);
    sub_19FFB10(pMatrix, 2, 0);
    sub_19FFB10(pMatrix, 0, 2);
    sub_854930(&v30, 1u);
    sub_19FFB10(pMatrix, 0, 1);
    sub_19FFB10(pMatrix, 1, 0);
    v29 = 2;
  }
  else
  {
    sub_19FFB10(pMatrix, 0, 0);
    v13 = v12;
    sub_19FFB10(pMatrix, 1, 1);
    v15 = v13 <= v14;
    sub_19FFB10(pMatrix, 2, 2);
    v17 = v16;
    sub_19FFB10(pMatrix, v15, v15);
    if (v17 <= v18)
      v19 = v15;
    else
      v19 = 2;
    v20 = (v19 + 1) % 3u;
    v21 = (v20 + 1) % 3;
    sub_19FFB10(pMatrix, v19, v19);
    v23 = v22;
    sub_19FFB10(pMatrix, v20, v20);
    v25 = v24;
    sub_19FFB10(pMatrix, v21, v21);
    v28 = ((v23 - v25) - v27) + 1.0;
    if (v28 == 0.0)
    {
      sub_854930(&v30, v19);
      sub_854930(&v30, v20);
      sub_854930(&v30, v21);
    }
    else
    {
      sdfSqrt(v28);
      sub_854930(&v30, v19);
      sub_19FFB10(pMatrix, v20, v19);
      sub_19FFB10(pMatrix, v19, v20);
      sub_854930(&v30, v20);
      sub_19FFB10(pMatrix, v21, v19);
      sub_19FFB10(pMatrix, v19, v21);
      sub_854930(&v30, v21);
      sub_19FFB10(pMatrix, v20, v21);
      sub_19FFB10(pMatrix, v21, v20);
    }
    v29 = 3;
  }
  sub_854930(&v30, v29);
  sub_854710(&v30, 0);
  sub_854930(&v30, 0);
  sub_854710(&v30, 1u);
  sub_854930(&v30, 1u);
  SDF_VU0__LOADVECTOR(v30);
}

// 0x11f5380
void effPCP_BED_SetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_BED_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCP_BED_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[6].monitor) = abgr;
}

// 0x11f5120
void effPCP_BED_SetPosition(void **hData, sdfVector4_t pPos) {
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
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != effPCP_BED_tag)
    {
      sub_8FC2C0(*(v9 + 64), effPCP_BED_tag, v13);
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
  SDF_VU0__COPYVECTOR(v8 + 5, v14);
}

// 0x11f5250
void effPCP_BED_SetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
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
  if (v7)
  {
    klass = v7->klass;
    if (v7->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_BED_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCP_BED_tag, v17);
      if ((v17[0] & 1) != 0)
        v14 = v17[2];
      else
        v14 = v17 + 1;
      v15 = sub_8C4940(v14);
    }
  }
  SDF_VU0__STOREMATRIX(&v7[1]);
}

// 0x11f58a0
effPCP_HBED2_tag *effPCP_HBED2_Copy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  Il2CppClass *v10;
  effPCP_HBED2_tag_o *v11;
  Il2CppObject *monitor;
  u64 v15[3];

  monitor = 0;
  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_HBED2_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCP_HBED2_tag, v15);
      if ((v15[0] & 1) != 0)
        v8 = v15[2];
      else
        v8 = v15 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = v5[1].klass;
LABEL_14:
  v11 = Allocate(effPCP_HBED2_tag);
  _ctor(v11, 0);
  v11->param = v10;
  monitor = v5[1].monitor;
  v11->pHelperBED = effPCPHelperBEDCopy(&monitor, 0, 0);
  return v11;
}

// 0x11f5470
effPCP_HBED2_tag *effPCP_HBED2_Create(effPCP_HBED2_Param_t *pParam, void *pPBData, void *pBEDData) {
  effPCP_HBED2_tag_o *v7;
  effPCPHelperBEDParam_t_o *hbed;

  v7 = Allocate(effPCP_HBED2_tag);
  _ctor(v7, 0);
  v7->param = pParam;
  if (pPBData && pBEDData)
  {
    hbed = pParam->hbed;
    v7->pHelperBED = effPCPHelperBEDCreate(hbed, pPBData, pBEDData);
  }
  return v7;
}

// 0x11f5530
effPCP_HBED2_tag *effPCP_HBED2_CreatePCF(void **hData, s32 bPos, bool tbldata) {
  dds3EffectPCPData_t_o *v6;
  Il2CppObject *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  struct dds3EffectPCPData_Part_t_array *pcpData;
  Il2CppObject *v14;
  u32 offset;
  Il2CppObject *DataUnityOffSet;
  struct dds3EffectPCPData_Part_t_array *v19;
  Il2CppObject *v20;
  Il2CppObject *v21;
  u32 v23;
  Il2CppObject *EffPCPAgiFireballPart;
  struct dds3EffectPCPData_Part_t_array *v25;
  Il2CppObject *v26;
  Il2CppObject *v27;
  Il2CppObject *v30;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v33;
  s64 *v34;
  effPCP_HBED2_tag_o *v35;
  effPCPHelperBEDParam_t_o *v37;
  u64 v39[2];
  char *v40;
  s32 pos;

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v7->klass->_1.element_class, v8, v39);
      if ((v39[0] & 1) != 0)
        v10 = v40;
      else
        v10 = v39 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v6, Interface, &pos);
  pcpData = v6->pcpData;
  v14 = *hData;
  offset = pcpData->m_Items[0]->offset;
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 55);
  v19 = v6->pcpData;
  v20 = *hData;
  v21 = DataUnityOffSet;
  v23 = v19->m_Items[1]->offset;
  EffPCPAgiFireballPart = GetEffPCPAgiFireballPart(v20, v23 + bPos);
  v25 = v6->pcpData;
  v26 = *hData;
  v27 = EffPCPAgiFireballPart;
  v30 = GetEffPCPAgiFireballPart(v26, v25->m_Items[2]->offset + bPos);
  else if (!v21)
  {
    goto LABEL_31;
  }
  klass = v21->klass;
  if (v21->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_HBED2_Param_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCP_HBED2_Param_t, v39);
    if ((v39[0] & 1) != 0)
      v33 = v40;
    else
      v33 = v39 + 1;
    v34 = sub_8C4940(v33);
  }
LABEL_31:
  v35 = Allocate(effPCP_HBED2_tag);
  _ctor(v35, 0);
  v35->param = v21;
  if (v27 && v30)
  {
    v37 = v21[1].klass;
    v35->pHelperBED = effPCPHelperBEDCreate(v37, v27, v30);
  }
  return v35;
}

// 0x11f5a50
void effPCP_HBED2_Delete(void **hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  Il2CppObject *monitor;
  u64 v8[3];

  monitor = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_HBED2_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCP_HBED2_tag, v8);
    if ((v8[0] & 1) != 0)
      v5 = v8[2];
    else
      v5 = v8 + 1;
    v6 = sub_8C4940(v5);
  }
  monitor = (*hData)[1].monitor;
  effPCPHelperBEDDelete(&monitor);
}

// 0x11f5b70
void effPCP_HBED2_Draw(void **hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  Il2CppObject *monitor;
  u64 v8[3];

  monitor = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_HBED2_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCP_HBED2_tag, v8);
    if ((v8[0] & 1) != 0)
      v5 = v8[2];
    else
      v5 = v8 + 1;
    v6 = sub_8C4940(v5);
  }
  monitor = (*hData)[1].monitor;
  effPCPHelperBEDDraw(&monitor);
}

// 0x11f5fa0
void effPCP_HBED2_SetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  Il2CppObject *v9[3];
  Il2CppObject *hDataa;

  hDataa = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_HBED2_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCP_HBED2_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  hDataa = (*hData)[1].monitor;
  effPCPHelperBEDSetColor(&hDataa, abgr);
}

// 0x11f5c90
void effPCP_HBED2_SetPosition(void **hData, sdfVector4_t pPos) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v10;
  s64 *v11;
  Il2CppObject *monitor;
  u64 v13[3];
  UnityEngine_Vector4_o v14;

  w = pPos.w;
  z = pPos.z;
  y = pPos.y;
  x = pPos.x;
  monitor = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_HBED2_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCP_HBED2_tag, v13);
    if ((v13[0] & 1) != 0)
      v10 = v13[2];
    else
      v10 = v13 + 1;
    v11 = sub_8C4940(v10);
  }
  monitor = (*hData)[1].monitor;
  v14.x = x;
  v14.y = y;
  v14.z = z;
  v14.w = w;
  effPCPHelperBEDSetPosition(&monitor, v14);
}

// 0x11f5de0
void effPCP_HBED2_SetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  effPCPHelperBED_tag_o *monitor;
  s64 v9;
  s64 v10;
  s64 v11;
  s64 v12;
  s64 v13;
  s64 v14;
  char *v16;
  s64 *v17;
  UnityEngine_Matrix4x4_o v18;
  UnityEngine_Matrix4x4_o v19;
  dds3ModelHandle_t_o *aHandle;

  aHandle = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_HBED2_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCP_HBED2_tag, &v19);
    if ((LOBYTE(v19.m00) & 1) != 0)
      v16 = *&v19.m01;
    else
      v16 = &v19.m00 + 1;
    v17 = sub_8C4940(v16);
  }
  monitor = (*hData)[1].monitor;
  aHandle = effPCPHelperBEDGetModel(monitor);
  v9 = *&pMatrix->m00;
  v10 = *&pMatrix->m20;
  v11 = *&pMatrix->m21;
  *&v19.m01 = *&pMatrix->m01;
  *&v19.m21 = v11;
  *&v19.m00 = v9;
  *&v19.m20 = v10;
  v12 = *&pMatrix->m23;
  v13 = *&pMatrix->m02;
  v14 = *&pMatrix->m22;
  *&v19.m03 = *&pMatrix->m03;
  *&v19.m23 = v12;
  *&v19.m02 = v13;
  *&v19.m22 = v14;
  v18 = v19;
  effPCP_BED_MatrixToQuaternion(&v18);
  mdlSetRotate(&aHandle);
}

// 0x11f60d0
void effPCP_HBED2_SetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  Il2CppObject *v9[3];
  Il2CppObject *hDataa;

  hDataa = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_HBED2_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCP_HBED2_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  hDataa = (*hData)[1].monitor;
  effPCPHelperBEDSetScale(&hDataa, scale);
}

// 0x11f0080
effPCP_PBCamera_tag *effPCP_PBCamera_Copy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  Il2CppClass *v10;
  effPCP_PBCamera_tag_o *v11;
  effPartHandle_t_o **p_monitor;
  u64 v15[3];

  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_PBCamera_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCP_PBCamera_tag, v15);
      if ((v15[0] & 1) != 0)
        v8 = v15[2];
      else
        v8 = v15 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = v5[6].klass;
LABEL_14:
  v11 = Allocate(effPCP_PBCamera_tag);
  _ctor(v11, 0);
  Clear(v11, 0);
  v11->param = v10;
  v11->frame = 0;
  v11->ex = 0;
  p_monitor = &v5[6].monitor;
  v11->hPB = dds3EffectPartCopy(p_monitor, 0, 0);
  return v11;
}

// 0x11efd10
effPCP_PBCamera_tag *effPCP_PBCamera_Create(effPCP_PBCamera_Param_t *pParam, void *pPB) {
  effPCP_PBCamera_tag_o *v5;

  v5 = Allocate(effPCP_PBCamera_tag);
  _ctor(v5, 0);
  Clear(v5, 0);
  v5->param = pParam;
  v5->frame = 0;
  v5->ex = 0;
  if (pPB)
  {
    v5->hPB = dds3EffectPartCreate(3u, pPB, 0, 0);
  }
  return v5;
}

// 0x11efdd0
effPCP_PBCamera_tag *effPCP_PBCamera_CreatePCF(void **hData, s32 bPos, bool tbldata) {
  dds3EffectPCPData_t_o *v6;
  Il2CppObject *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  struct dds3EffectPCPData_Part_t_array *pcpData;
  Il2CppObject *v14;
  u32 offset;
  Il2CppObject *DataUnityOffSet;
  struct dds3EffectPCPData_Part_t_array *v19;
  Il2CppObject *v20;
  effPCP_PBCamera_Param_t_o *v21;
  u32 v23;
  Il2CppObject *EffPCPAgiFireballPart;
  effPCP_PBCamera_Param_t_c *klass;
  s64 typeHierarchyDepth;
  char *v29;
  s64 *v30;
  u64 v32[2];
  char *v33;
  s32 pos;

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v7->klass->_1.element_class, v8, v32);
      if ((v32[0] & 1) != 0)
        v10 = v33;
      else
        v10 = v32 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v6, Interface, &pos);
  pcpData = v6->pcpData;
  v14 = *hData;
  offset = pcpData->m_Items[0]->offset;
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 52);
  v19 = v6->pcpData;
  v20 = *hData;
  v21 = DataUnityOffSet;
  v23 = v19->m_Items[1]->offset;
  EffPCPAgiFireballPart = GetEffPCPAgiFireballPart(v20, v23 + bPos);
  else if (!v21)
  {
    return effPCP_PBCamera_Create(v21, EffPCPAgiFireballPart);
  }
  klass = v21->klass;
  if (v21->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_PBCamera_Param_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCP_PBCamera_Param_t, v32);
    if ((v32[0] & 1) != 0)
      v29 = v33;
    else
      v29 = v32 + 1;
    v30 = sub_8C4940(v29);
  }
  return effPCP_PBCamera_Create(v21, EffPCPAgiFireballPart);
}

// 0x11f0230
void effPCP_PBCamera_Delete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  effPartHandle_t_o **p_monitor;
  u64 v9[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_PBCamera_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCP_PBCamera_tag, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  p_monitor = &v3[6].monitor;
  dds3EffectPartDelete(p_monitor);
}

// 0x11f0350
void effPCP_PBCamera_Run(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  u32 ID;
  nbFormation_t_o *v12;
  dds3ModelHandle_t_o **p_Model;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  struct nbCamera_t_o *nbCameraCurrent;
  Il2CppClass *v21;
  void *monitor;
  void *v23;
  void *v24;
  Il2CppClass *v25;
  void *v26;
  u32 v28;
  u32 v29;
  u32 v30;
  s32 klass_high;
  u32 v32;
  u32 v33;
  s32 v34;
  u32 v35;
  Il2CppObject *Handle;
  Il2CppClass *v38;
  s64 v39;
  dds3ModelHandle_t_o *v40;
  char *v41;
  s64 *v42;
  Il2CppClass *v43;
  s64 v44;
  char *v45;
  s64 *v46;
  s32 v49;
  UnityEngine_Matrix4x4_o v50;
  UnityEngine_Matrix4x4_o v51;
  Il2CppObject *hDataa;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *pFormation;
  UnityEngine_Vector4_o v55;

  pFormation = 0;
  *&p.x = 0;
  *&p.z = 0;
  hDataa = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_PBCamera_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCP_PBCamera_tag, &v51);
      if ((LOBYTE(v51.m00) & 1) != 0)
        v6 = *&v51.m01;
      else
        v6 = &v51.m00 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  pFormation = 0;
  v8 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v8);
  *&p.x = 0;
  *&p.z = 0;
  if (SLODWORD(v3[6].klass->_1.name) <= SHIDWORD(v3[7].klass))
    return;
  pFormation = 0;
  else if (effBTLSkillCheckRun())
  {
LABEL_14:
    ID = effBTLSkillGetID();
    v12 = effBTLSkillGetInvokeFormation(0);
    pFormation = effBTLSkillGetTargetFormation(0);
    if ((~v12->stat & 3) == 0)
    {
      p_Model = &v12->hunit->Model;
      mdlGetPosition(p_Model);
      SDF_VU0__STOREVECTOR(&p);
      hDataa = v3;
      x = p.x;
      y = p.y;
      z = p.z;
      w = p.w;
      v55.x = x;
      v55.y = y;
      v55.z = z;
      v55.w = w;
      effPCP_PBCamera_SetPosition(&hDataa, v55);
    }
    if (SHIDWORD(v3[7].klass) < 1)
    {
LABEL_37:
      v21 = v3[1].klass;
      monitor = v3[1].monitor;
      v23 = v3[2].monitor;
      *&v51.m01 = v3[2].klass;
      *&v51.m21 = v23;
      *&v51.m00 = v21;
      *&v51.m20 = monitor;
      v24 = v3[4].monitor;
      v25 = v3[3].klass;
      v26 = v3[3].monitor;
      *&v51.m03 = v3[4].klass;
      *&v51.m23 = v24;
      *&v51.m02 = v25;
      *&v51.m22 = v26;
      v50 = v51;
      dds3EffectPartSetRotateMatrix(&v3[6].monitor, &v50);
      dds3EffectPartSetPosition(&v3[6].monitor, v3[5]);
      dds3EffectPartDraw(&v3[6].monitor);
      if (pFormation)
      {
        v28 = 0;
        v29 = 1;
        switch (ID)
        {
          case 0x107u:
            v30 = effBTLModelGetID(&pFormation);
            v29 = 1;
            if (v30 == 264 || v30 == 344 || v30 == 293)
            {
              klass_high = HIDWORD(v3[7].klass);
              LOBYTE(v3[7].klass) = 1;
              HIDWORD(v3[7].klass) = klass_high + 1;
              goto LABEL_111;
            }
            v28 = 0;
            if (!LOBYTE(v3[7].klass))
              break;
            goto LABEL_111;
          case 0x108u:
            v32 = effBTLModelGetID(&pFormation);
            if (v32 == 344)
              v29 = 3;
            else
              v29 = 1;
            v28 = 2 * (v32 == 344);
            if (!LOBYTE(v3[7].klass))
              break;
            goto LABEL_111;
          case 0x10Bu:
            v33 = effBTLModelGetID(&pFormation);
            if (v33 != 258 && v33 != 344 && v33 != 291)
              goto LABEL_73;
            v34 = HIDWORD(v3[7].klass);
            nbCameraDANTE_KAGIRI_Set(v34);
            LOBYTE(v3[7].klass) = 1;
            goto LABEL_111;
          case 0x10Du:
            v35 = effBTLModelGetID(&pFormation);
            if (v35 > 0x109)
            {
              v28 = 0;
              v29 = 1;
              if (v35 - 291 > 0x35 || ((1LL << (v35 - 35)) & 0x20000000000005LL) == 0)
                goto LABEL_74;
            }
            else if ((v35 | 2) != 0x102 && (v35 & 0xFFFFFFFE) != 0x108)
            {
              goto LABEL_73;
            }
            v28 = 2;
            v29 = 3;
            if (LOBYTE(v3[7].klass))
              goto LABEL_111;
            break;
          default:
            goto LABEL_74;
        }
      }
      else
      {
LABEL_73:
        v28 = 0;
        v29 = 1;
LABEL_74:
        if (LOBYTE(v3[7].klass))
          goto LABEL_111;
      }
      Handle = dds3EffectPartGetHandle(&v3[6].monitor);
      if (Handle)
      {
        v38 = Handle->klass;
        if (Handle->klass->_2.typeHierarchyDepth < v39
          || (v40 = Handle, v38->_2.typeHierarchy[v39 - 1] != dds3ModelHandle_t))
        {
          sub_8FC2C0(v38->_1.element_class, dds3ModelHandle_t, &v51);
          if ((LOBYTE(v51.m00) & 1) != 0)
            v41 = *&v51.m01;
          else
            v41 = &v51.m00 + 1;
          v42 = sub_8C4940(v41);
        }
      }
      else
      {
        v40 = 0;
      }
      if (HIDWORD(v3[7].klass))
      {
        if (Handle)
        {
          v43 = Handle->klass;
          if (Handle->klass->_2.typeHierarchyDepth < v44
            || (v40 = Handle, v43->_2.typeHierarchy[v44 - 1] != dds3ModelHandle_t))
          {
            sub_8FC2C0(v43->_1.element_class, dds3ModelHandle_t, &v51);
            if ((LOBYTE(v51.m00) & 1) != 0)
              v45 = *&v51.m01;
            else
              v45 = &v51.m00 + 1;
            v46 = sub_8C4940(v45);
          }
        }
        else
        {
          v40 = 0;
        }
      }
      else
      {
        nbCameraSetState(0x17u);
      }
      nbCameraHelperModelSetSub(v40, v28, v29);
      if (ID - 263 < 2)
      {
        v49 = 1063216883;
          goto LABEL_110;
      }
      else
      {
        if (ID != 267 && ID != 269)
          goto LABEL_111;
        v49 = 1064680971;
        {
LABEL_110:
          LODWORD(nbCameraCurrent->fovy) = v49;
LABEL_111:
          ++HIDWORD(v3[7].klass);
          return;
        }
      }
      goto LABEL_110;
    }
    goto LABEL_29;
  }
  ID = 0;
  if (SHIDWORD(v3[7].klass) < 1)
    goto LABEL_37;
LABEL_29:
  if (nbCameraCurrent->state != 10)
  {
    if (nbCameraCurrent->state_change != 10)
      goto LABEL_37;
  }
}

// 0x11f0b20
void effPCP_PBCamera_SetPosition(void **hData, sdfVector4_t pPos) {
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
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != effPCP_PBCamera_tag)
    {
      sub_8FC2C0(*(v9 + 64), effPCP_PBCamera_tag, v13);
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
  SDF_VU0__COPYVECTOR(v8 + 5, v14);
}

// 0x11f0c50
void effPCP_PBCamera_SetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
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
  if (v7)
  {
    klass = v7->klass;
    if (v7->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_PBCamera_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCP_PBCamera_tag, v17);
      if ((v17[0] & 1) != 0)
        v14 = v17[2];
      else
        v14 = v17 + 1;
      v15 = sub_8C4940(v14);
    }
  }
  SDF_VU0__STOREMATRIX(&v7[1]);
}

// 0x11f6670
void effPadVibeFadeIN(u32 mode, u8 power, s32 frame) {
  struct System_Int32_array *effBossEvePadVibeFrameStart;
  struct System_Int32_array *effBossEvePadVibeFrame;
  struct System_Byte_array *effBossEvePadVibePower;
  struct System_Byte_array *effBossEvePadVibeType;

  if (mode <= 1)
  {
    effBossEvePadVibeFrameStart->m_Items[mode] = frame;
    effBossEvePadVibeFrame->m_Items[mode] = frame;
    effBossEvePadVibePower->m_Items[mode] = power;
    effBossEvePadVibeType->m_Items[mode] = 1;
  }
}

// 0x11f6520
void effPadVibeFadeOUT(u32 mode, u8 power, s32 frame) {
  struct System_Int32_array *effBossEvePadVibeFrameStart;
  struct System_Int32_array *effBossEvePadVibeFrame;
  struct System_Byte_array *effBossEvePadVibePower;
  struct System_Byte_array *effBossEvePadVibeType;

  if (mode <= 1)
  {
    effBossEvePadVibeFrameStart->m_Items[mode] = frame;
    effBossEvePadVibeFrame->m_Items[mode] = frame;
    effBossEvePadVibePower->m_Items[mode] = power;
    effBossEvePadVibeType->m_Items[mode] = 0;
  }
}

// 0x11f6200
void effPadVibeFadeUpdate(void) {
  s64 v2;
  u64 v4;
  struct System_Int32_array *effBossEvePadVibeFrameStart;
  struct System_Int32_array *effBossEvePadVibeFrame;
  struct System_Int32_array *v12;
  struct System_Int32_array *v14;
  s32 v15;
  f32 v17;
  struct System_Byte_array *effBossEvePadVibeType;
  f32 v19;
  f32 v21;
  struct System_Byte_array *effBossEvePadVibePower;
  u8 v24;
  struct System_Int32_array *v25;
  struct System_Int32_array *v28;

  v2 = 0;
  do
  {
    while (1)
    {
      v4 = v2;
      if (!effBossEvePadVibeFrameStart->m_Items[v4])
        goto LABEL_38;
      if (effBossEvePadVibeFrame->m_Items[v4] < 1)
        break;
      v12 = effBossEvePadVibeFrame;
      v14 = effBossEvePadVibeFrameStart;
      v15 = v12->m_Items[v4];
      v17 = v15;
      v19 = v17 / v14->m_Items[v4];
      v21 = 1.0 - v19;
      if (effBossEvePadVibeType->m_Items[v4])
        v19 = 1.0 - v19;
      LOBYTE(v21) = effBossEvePadVibePower->m_Items[v4];
      v24 = (v19 * LODWORD(v21));
      dds3PadAct(v4, v24, 0x64u);
      v25 = effBossEvePadVibeFrame;
      --v25->m_Items[v4];
LABEL_38:
      v2 = 1;
      if (v4)
        return;
    }
    dds3PadAct(v4, 0, 0);
    v28 = effBossEvePadVibeFrameStart;
    v28->m_Items[v4] = 0;
    v2 = 1;
  }
  while (!v4);
}

// 0x11dd070
s32 mdlGetMotionFrame(dds3ModelHandle_t **aHandle) {
  return 0;
}

// 0x11dd090
u16 mdlGetMotionLength(dds3ModelHandle_t *aHandle) {
  return 0;
}

// 0x11dd080
s32 mdlGetMotionNum(dds3ModelHandle_t **aHandle, s32 aGroup) {
  return 0;
}

// 0x11dd0d0
dds3ModelHandle_t *mdlLoad(s32 aMajor, s32 aMinor) {
  u64 *v3;

  v3 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v3);
  return v3;
}

// 0x11dd0a0
void mdlSingleMotion(dds3ModelHandle_t **aHandle, s32 aGroup, s32 aNumber) {
  ;
}

// 0x11dd0b0
void mdlSmoothLoopMotion(dds3ModelHandle_t **aHandle, s32 aGroup, s32 aNumber, f32 aBeforeLeng, f32 aSmoothLeng) {
  ;
}
