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
static void *effPCPDANTE_Sprite[UNKNOWN_ARRAY_SIZE];
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
    effPCPBossBUNSINDraw(0);
}

// 0x11ddfa0
s32 effPCPBossBUNSIN2GetLength(void) {
    return 48;
  return 48;
}

// 0x11dd610
effPCPBossBUNSIN_t *effPCPBossBUNSINCreate(effPCPBossBUNSINParam_t *pParam) {
    return 0;
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
  p_pStartForm = &v3->param->pStartForm;
  nbFormDispOn2(p_pStartForm);
  nbFormDispOn2(&(*pPCPBossBUNSIN)->param->pEndForm, 0);
  v3 = *pPCPBossBUNSIN;
  frame = (*pPCPBossBUNSIN)->frame;
  if (frame <= 9)
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
    dds3EffectPartCopy(0);
    return 0;
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
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    GetEffPCPAgiFireballPart(0, 0);
    effPCPBossBaelCreate(0, 0, 0);
    return 0;
}

// 0x11e19b0
void effPCPBossBaelDelete(void **hData) {
    dds3EffectPartDelete(0);
}

// 0x11e1ae0
void effPCPBossBaelDraw(void **hData) {
    effBTLSkillCheckRun();
    SDF_VU0__STOREIDENTITYVECTOR(0);
    SDF_VU0__STOREIDENTITY(0);
    effBTLSkillGetTargetFormation(0);
    effBTLModelGetSphereCenter(0);
    SDF_VU0__STOREVECTOR(0);
    LookAtMatrix((sdfVector4_t){0}, (sdfVector4_t){0}, (sdfVector4_t){0});
    ReverseMatrix();
    SDF_VU0__RESET_ROW3();
    SDF_VU0__STOREMATRIX(0);
    dds3EffectPartSetRotateMatrix(0, 0);
    dds3EffectPartSetPosition(0, (sdfVector4_t){0});
    dds3EffectPartSetColor(0, 0);
    dds3EffectPartDraw(0);
}

// 0x11e2060
void effPCPBossBaelSetColor(void **hData, u32 abgr) {
}

// 0x11e1f40
void effPCPBossBaelSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x11e2880
effPCPBossDengeki_t *effPCPBossDengekiCopy(void **hData, s32 bPos, bool tbldata) {
    effPCPBossDengekiCreate(0, 0);
    effEveBEDCutCreate(0, 0, 0);
    return 0;
}

// 0x11e2150
effPCPBossDengeki_t *effPCPBossDengekiCreate(effPCPBossDengekiParam_t *pParam, void *pBEDData) {
    effPCP_ThunderPolyListParam_t__Clear(0);
    effEveBEDCreate(0);
    effEveBEDCutCreate(0, 0, 0);
    effPCP_ThunderPolyListCreate(0, 0, 0);
    return 0;
}

// 0x11e25d0
effPCPBossDengeki_t *effPCPBossDengekiCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    GetEffPCPAgiFireballPart(0, 0);
    effPCPBossDengekiCreate(0, 0);
    return 0;
}

// 0x11e2ae0
void effPCPBossDengekiDelete(void **hData) {
    effEveBEDCutDelete(0);
    effEveBEDDelete(0);
    effPCP_ThunderPolyListDelete(0);
}

// 0x11e2d10
void effPCPBossDengekiDraw(void **hData) {
    effBTLSkillCheckRun();
    effBTLSkillGetInvokeFormation(0);
    effBTLModelGetMarkPosition2(0, 0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    ToMatrix();
    SDF_VU0__COPYMATRIX_A_TO_C();
    SDF_VU0__LOADIDENTITYVECTOR();
    SDF_VU0__SETVECTOR_Z(0);
    DDS3EFFECT_RAND_PM();
    SetRotateMatrixY_B(0);
    MultMatrixNoArg();
    SDF_VU0__APPLYMATRIX_XYZ();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__MULVECTOR();
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__INTERPOLATE(0);
    SDF_VU0__ADDVECTOR_A_C();
    SDF_VU0__COPYMATRIX_C_TO_A();
    effPCP_ThunderPolyListGetParam(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    effPCP_ThunderPolyListSetColor(0, 0);
    effPCP_ThunderPolyListDraw(0);
    SDF_VU0__COPYVECTOR_C_TO_A();
    effEveBEDCutSetParams(0, 0);
    effEveBEDCutDraw(0);
    nbGetMainProcessData();
    effBTLModelGetID(0);
}

// 0x11e3bd0
void effPCPBossDengekiSetColor(void **hData, u32 abgr) {
}

// 0x11e8960
effPCPBossKAGU2Attack_t *effPCPBossKAGU2AttackCopy(void **hData, s32 bPos, bool tbldata) {
    effPCPBossKAGU2AttackCreate(0, 0);
    effEveBEDCutCreate(0, 0, 0);
    return 0;
}

// 0x11e8380
effPCPBossKAGU2Attack_t *effPCPBossKAGU2AttackCreate(effPCPBossKAGU2AttackParam_t *pParam, void *pBEDData) {
    effPCP_ThunderPolyListParam_t__Clear(0);
    effEveBEDCreate(0);
    effEveBEDCutCreate(0, 0, 0);
    effPCP_ThunderPolyListCreate(0, 0, 0);
    return 0;
}

// 0x11e86b0
effPCPBossKAGU2Attack_t *effPCPBossKAGU2AttackCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    GetEffPCPAgiFireballPart(0, 0);
    effPCPBossKAGU2AttackCreate(0, 0);
    return 0;
}

// 0x11e8bc0
void effPCPBossKAGU2AttackDelete(void **hData) {
    effEveBEDCutDelete(0);
    effEveBEDDelete(0);
    effPCP_ThunderPolyListDelete(0);
}

// 0x11e9250
void effPCPBossKAGU2AttackDraw(void **hData) {
    effBTLSkillCheckRun();
    effBTLSkillGetInvokeFormation(0);
    nbGetMainProcessData();
    effBTLModelGetID(0);
    effColorBlend(0, 0, 0);
    effBTLModelGetMarkPosition2(0, 0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    effPCP_ThunderPolyListGetParam(0);
    effPCPBossKAGU2AttackGetSplitPoint(0, (sdfVector4_t){0}, (sdfVector4_t){0}, (sdfVector4_t){0}, 0, 0);
    effPCP_ThunderPolyListSetColor(0, 0);
    effPCP_ThunderPolyListDraw(0);
    effEveBEDCutSetParams(0, 0);
    effEveBEDCutDraw(0);
}

// 0x11e8d70
void effPCPBossKAGU2AttackGetSplitPoint(sdfVector4_t ***pPosBuff, sdfVector4_t pPoint1, sdfVector4_t pPoint2, sdfVector4_t pCenter, f32 rand, f32 rotate) {
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__GETLENGTH();
    SDF_VU0__COPYVECTOR_B_TO_C();
    SDF_VU0__SETVECTOR_X(0);
    DDS3EFFECT_RAND_FA(0);
    SetRotateMatrixAxis(0, (sdfVector4_t){0});
    SDF_VU0__INTERPOLATE(0);
    SDF_VU0__APPLYMATRIX_XYZ();
    SDF_VU0__MULVECTOR();
    SDF_VU0__ADDVECTOR_A_C();
    SDF_VU0__ADDVECTOR_B_A();
    SDF_VU0__STOREVECTOR_B(0);
    SDF_VU0__SCALEVECTOR_B(0);
}

// 0x11e9cd0
void effPCPBossKAGU2AttackSetColor(void **hData, u32 abgr) {
}

// 0x11ea220
effPCPBossKAGU2MUHENK_t *effPCPBossKAGU2MUHENKCopy(void **hData, s32 bPos, bool tbldata) {
    return 0;
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
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    return 0;
}

// 0x11ea390
void effPCPBossKAGU2MUHENKDelete(effPCPBossKAGU2MUHENK_t *pPCPBossKAGU2MUHENK) {
  ;
}

// 0x11ea3a0
void effPCPBossKAGU2MUHENKDraw(effPCPBossKAGU2MUHENK_t *pPCPBossKAGU2MUHENK) {
    effBTLSkillCheckRun();
    effBTLSkillGetInvokeFormation(0);
    effBTLModelGetMarkPosition2(0, 0);
    SDF_VU0__STOREVECTOR(0);
    sdfModelGetMarkPosMatrixUnity(0, 0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    nbGetMainProcessData();
    effBTLModelGetID(0);
}

// 0x11ea700
void effPCPBossKAGU2MUHENKSetColor(void **hData, u32 abgr) {
}

// 0x11e9dc0
void effPCPBossKAGU2ThunderboltDraw(void **hData) {
    effPCPBossKAGUThunderboltDrawSub(0, (sdfVector4_t){0});
}

// 0x11e5fe0
effPCPBossKAGUAttack_t *effPCPBossKAGUAttackCopy(void **hData, s32 bPos, bool tbldata) {
    effPCPBossKAGUAttackCreate(0, 0);
    effEveBEDCutCreate(0, 0, 0);
    return 0;
}

// 0x11e5a00
effPCPBossKAGUAttack_t *effPCPBossKAGUAttackCreate(effPCPBossKAGUAttackParam_t *pParam, void *pBEDData) {
    effPCP_ThunderPolyListParam_t__Clear(0);
    effEveBEDCreate(0);
    effEveBEDCutCreate(0, 0, 0);
    effPCP_ThunderPolyListCreate(0, 0, 0);
    return 0;
}

// 0x11e5d30
effPCPBossKAGUAttack_t *effPCPBossKAGUAttackCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    GetEffPCPAgiFireballPart(0, 0);
    effPCPBossKAGUAttackCreate(0, 0);
    return 0;
}

// 0x11e6240
void effPCPBossKAGUAttackDelete(void **hData) {
    effEveBEDCutDelete(0);
    effEveBEDDelete(0);
    effPCP_ThunderPolyListDelete(0);
}

// 0x11e6670
void effPCPBossKAGUAttackDraw(void **hData) {
    effBTLSkillCheckRun();
    effBTLSkillGetInvokeFormation(0);
    nbGetMainProcessData();
    effBTLModelGetID(0);
    effColorBlend(0, 0, 0);
    effBTLModelGetMarkPosition2(0, 0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    effPCP_ThunderPolyListGetParam(0);
    effPCPBossKAGUAttackGetSplitPoint(0, (sdfVector4_t){0}, (sdfVector4_t){0}, (sdfVector4_t){0});
    effPCP_ThunderPolyListSetColor(0, 0);
    effPCP_ThunderPolyListDraw(0);
    effEveBEDCutSetParams(0, 0);
    effEveBEDCutDraw(0);
}

// 0x11e63f0
void effPCPBossKAGUAttackGetSplitPoint(sdfVector4_t ***pPosBuff, sdfVector4_t pPoint1, sdfVector4_t pPoint2, sdfVector4_t pCenter) {
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__COPYVECTOR_B_TO_C();
    SDF_VU0__INTERPOLATE(0);
    SDF_VU0__MULVECTOR();
    SDF_VU0__ADDVECTOR_A_C();
    SDF_VU0__ADDVECTOR_B_A();
    SDF_VU0__STOREVECTOR_B(0);
}

// 0x11e6ea0
void effPCPBossKAGUAttackSetColor(void **hData, u32 abgr) {
}

// 0x11e4ed0
effPCPBossKAGUInvoke_t *effPCPBossKAGUInvokeCopy(void **hData, s32 bPos, bool tbldata) {
    effPCPBossKAGUInvokeCreate(0);
    return 0;
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
    effPCPBossKAGUInvokeCreate(0);
    return 0;
}

// 0x11e4c90
effPCPBossKAGUInvoke_t *effPCPBossKAGUInvokeCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    effPCPBossKAGUInvokeCreate(0);
    return 0;
}

// 0x11e4fe0
void effPCPBossKAGUInvokeDelete(void **hData) {
    effPCP_ThunderPolyListDelete(0);
}

// 0x11e5140
void effPCPBossKAGUInvokeDraw(void **hData) {
    effBTLSkillCheckRun();
    effBTLSkillGetInvokeFormation(0);
    nbGetMainProcessData();
    effBTLModelGetID(0);
    effColorBlend(0, 0, 0);
    effBTLModelGetMarkPosition2(0, 0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    effPCP_ThunderPolyListGetParam(0);
    SDF_VU0__ZEROVECTOR_W();
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__ADDVECTOR();
    effPCP_ThunderPolyListSetColor(0, 0);
    effPCP_ThunderPolyListDraw(0);
}

// 0x11e5910
void effPCPBossKAGUInvokeSetColor(void **hData, u32 abgr) {
}

// 0x11e7560
effPCPBossKAGUThunderbolt_t *effPCPBossKAGUThunderboltCopy(void **hData, s32 bPos, bool tbldata) {
    effPCPBossKAGUThunderboltCreate(0, 0, 0);
    effPCPCrackCopy(0, 0, 0);
    effEveBEDCutCreate(0, 0, 0);
    return 0;
}

// 0x11e6f90
effPCPBossKAGUThunderbolt_t *effPCPBossKAGUThunderboltCreate(effPCPBossKAGUThunderboltParam_t *pParam, void *pBP, void *pBED) {
    effPCP_ThunderPolyListParam_t__Clear(0);
    effPCP_ThunderPolyListCreate(0, 0, 0);
    effPCPCrackCreate(0, 0);
    effEveBEDCreate(0);
    effEveBEDCutCreate(0, 0, 0);
    return 0;
}

// 0x11e7270
effPCPBossKAGUThunderbolt_t *effPCPBossKAGUThunderboltCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    GetEffPCPAgiFireballPart(0, 0);
    effPCPBossKAGUThunderboltCreate(0, 0, 0);
    return 0;
}

// 0x11e7820
void effPCPBossKAGUThunderboltDelete(void **hData) {
    effEveBEDCutDelete(0);
    effEveBEDDelete(0);
    effPCP_ThunderPolyListDelete(0);
    effPCPCrackDelete(0);
}

// 0x11e8010
void effPCPBossKAGUThunderboltDraw(void **hData) {
    effPCPBossKAGUThunderboltDrawSub(0, (sdfVector4_t){0});
}

// 0x11e79c0
void effPCPBossKAGUThunderboltDrawSub(effPCPBossKAGUThunderbolt_t *pPCPBossKAGUThunderbolt, sdfVector4_t pConvPos) {
    effBTLSkillCheckRun();
    effBTLSkillGetInvokeFormation(0);
    nbGetMainProcessData();
    effBTLModelGetID(0);
    effPCPCrackSetPosition(0, (sdfVector4_t){0});
    effPCPCrackSetColor(0, 0);
    effPCPCrackDraw(0);
    dds3EffectPartGetHandle(0);
    sdfModelGetMarkPosUnity(0, 0);
    SDF_VU0__STOREVECTOR(0);
    effColorBlend(0, 0, 0);
    effEveBEDCutSetParams(0, 0);
    effEveBEDCutDraw(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    effPCP_ThunderPolyListGetParam(0);
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__INTERPOLATE(0);
    SDF_VU0__COPYVECTOR_C_TO_A();
    SDF_VU0__STOREVECTOR_B(0);
    effPCP_ThunderPolyListSetColor(0, 0);
    effPCP_ThunderPolyListDraw(0);
}

// 0x11e8290
void effPCPBossKAGUThunderboltSetColor(void **hData, u32 abgr) {
}

// 0x11e8170
void effPCPBossKAGUThunderboltSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x11eb570
effPCPBossMETATOBeam_t *effPCPBossMETATOBeamCopy(void **hData, s32 bPos, bool tbldata) {
    effPCPBossMETATOBeamCreate(0);
    return 0;
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
    effPCPBossMETATOBeamCreate(0);
    return 0;
}

// 0x11eb330
effPCPBossMETATOBeam_t *effPCPBossMETATOBeamCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    effPCPBossMETATOBeamCreate(0);
    return 0;
}

// 0x11eb680
void effPCPBossMETATOBeamDelete(void **hData) {
    effPCP_ThunderPolyListDelete(0);
}

// 0x11eb7d0
void effPCPBossMETATOBeamDraw(void **hData) {
    effBTLSkillCheckRun();
    effBTLSkillGetInvokeFormation(0);
    nbGetMainProcessData();
    effBTLModelGetID(0);
    effColorBlend(0, 0, 0);
    effBTLModelGetMarkPosition2(0, 0);
    SDF_VU0__STOREVECTOR(0);
    effPCP_ThunderPolyListGetParam(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__INTERPOLATE(0);
    SDF_VU0__COPYVECTOR_C_TO_A();
    SDF_VU0__STOREVECTOR_B(0);
    effPCP_ThunderPolyListSetColor(0, 0);
    effPCP_ThunderPolyListDraw(0);
}

// 0x11ebf00
void effPCPBossMETATOBeamSetColor(void **hData, u32 abgr) {
}

// 0x11ebde0
void effPCPBossMETATOBeamSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
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
    effPCPBossThunderboltCreate(0);
    return 0;
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
    effPCPBossThunderboltCreate(0);
    return 0;
}

// 0x11e3f20
effPCPBossThunderbolt_t *effPCPBossThunderboltCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    effPCPBossThunderboltCreate(0);
    return 0;
}

// 0x11e4270
void effPCPBossThunderboltDelete(void **hData) {
    effPCP_ThunderPolyListDelete(0);
}

// 0x11e43c0
void effPCPBossThunderboltDraw(void **hData) {
    effBTLSkillCheckRun();
    effBTLSkillGetInvokeFormation(0);
    effBTLModelGetMarkPosition2(0, 0);
    SDF_VU0__STOREVECTOR(0);
    effPCP_ThunderPolyListGetParam(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__INTERPOLATE(0);
    SDF_VU0__COPYVECTOR_C_TO_A();
    SDF_VU0__STOREVECTOR_B(0);
    effPCP_ThunderPolyListDraw(0);
    effPCP_ThunderPolyListSetColor(0, 0);
    nbGetMainProcessData();
    effBTLModelGetID(0);
}

// 0x11e48d0
void effPCPBossThunderboltSetColor(void **hData, u32 abgr) {
}

// 0x11e47b0
void effPCPBossThunderboltSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x11eabe0
effPCPCrack_t *effPCPCrack2Copy(void **hData, s32 bPos, bool tbldata) {
    effPCPCrackCopy(0, 0, 0);
    return 0;
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
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    GetEffPCPAgiFireballPart(0, 0);
    effPCPCrack2Create(0, 0);
    return 0;
}

// 0x11eae50
void effPCPCrack2Delete(void **hData) {
    effPCPCrackDelete(0);
}

// 0x11eaed0
void effPCPCrack2Draw(void **hData) {
    effPCPCrackDraw(0);
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
    effPCPCrackParam_t__pClone(0, 0);
    dds3EffectPartCopy(0);
    effPCPCrackInit(0);
    return 0;
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
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    GetEffPCPAgiFireballPart(0, 0);
    effPCPCrackCreate(0, 0);
    return 0;
}

// 0x11df160
void effPCPCrackDelete(void **hData) {
    pMeshDelete(0);
    dds3TrackPolyDelete(0);
    dds3EffectPartDelete(0);
}

// 0x11df430
void effPCPCrackDraw(void **hData) {
    dds3EffectPartGetHandle(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    mdlSetPosition(0);
    mdlSetScale(0);
    dds3EffectPartModelDraw(0);
    effColorBlend(0, 0, 0);
    sdfModelGetMarkPosMatrixUnity(0, 0);
    SDF_VU0__APPLYMATRIX_XYZ();
    SDF_VU0__STOREVECTOR(0);
    sdfModelGetMarkPosUnity(0, 0);
    SDF_VU0__LOADVECTOR_C((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    SDF_VU0__COPYVECTOR_C_TO_B();
    SDF_VU0__OUTERPRODUCT();
    SDF_VU0__NORMALIZE();
    SDF_VU0__SCALEVECTOR_B(0);
    SDF_VU0__MULVECTOR();
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__ADDVECTOR();
    dds3TrackPolyDraw(0, 0);
    dds3FlashPolyListDraw(0, 0, 0);
    SetRotateMatrixAxis(0, (sdfVector4_t){0});
    SDF_VU0__LOADIDENTITYVECTOR();
    SDF_VU0__ADDVECTOR_A_C();
    effColorMultiply(0, 0);
}

// 0x11de150
void effPCPCrackInit(effPCPCrack_t **pPCPCrack) {
    dds3EffectPartGetHandle(0);
    mdlSetMotionSpeed(0, 0);
    dds3EffectPartModelDraw(0);
    mdlGetMotionLengthUnity(0);
    sdfModelGetMarkPosCountUnity(0);
    dds3EffectPartModelDelete(0);
    dds3TrackPolyCreate(0, 0, 0, 0);
    dds3TrackPolySetMode(0, 0);
    dds3FlashPolyListCreate(0);
    SDF_VU0__LOADIDENTITYVECTOR();
    SDF_VU0__STOREVECTOR(0);
    effPCPCrackSizeInit(0, 0);
}

// 0x11e1390
void effPCPCrackSetColor(void **hData, u32 abgr) {
}

// 0x11e1270
void effPCPCrackSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
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
    effPCPDANTE_Damage_Create(0, 0);
    return 0;
}

// 0x11eebb0
effPCPDANTE_Damage_tag *effPCPDANTE_Damage_Create(effPCPDANTE_Damage_Param_t *pParam, void *pBED) {
    effPCPDANTE_Damage_Param_t__pClone(0, 0);
    effEveBEDCreate(0);
    nbGetMainProcessData();
    effBTLSkillGetTargetBit();
    dds3GetRandIntA(0, 0);
    return 0;
}

// 0x11ef070
effPCPDANTE_Damage_tag *effPCPDANTE_Damage_CreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    GetEffPCPAgiFireballPart(0, 0);
    effPCPDANTE_Damage_Create(0, 0);
    return 0;
}

// 0x11ef450
void effPCPDANTE_Damage_Delete(void **hData) {
    effEveBEDCutDelete(0);
    effEveBEDDelete(0);
}

// 0x11ef610
void effPCPDANTE_Damage_Run(void **hData) {
    nbGetMainProcessData();
    effBTLSkillGetTargetBit();
    effBTLModelGetSphereCenter(0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    effBTLPartGetScalePtr(0);
    nbSetUnitMotion(0, 0, 0, 0);
    effEveBEDCutCreate(0, 0, 0);
    effEveBEDCutDelete(0);
    effColorBlend(0, 0, 0);
    effEveBEDCutDraw(0);
}

// 0x11efc20
void effPCPDANTE_Damage_SetColor(void **hData, u32 abgr) {
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
    }
  }
  v23 = v5 - 10;
  if ((v5 - 10) <= 0x10)
  {
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
  }
  v24 = v5 - 27;
  if ((v5 - 27) > 0x14)
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
  effPCPDANTE_Sprite_Draw(v38, 244, v37, v39, effPCPDANTE_Bingo_UV, v26, 0, v41);
  v58 = (*pPCPShowTime)->frameParts;
  ++v58->m_Items[0];
}

// 0x11f1430
effPCPDANTE_ShowTime_tag *effPCPDANTE_ShowTime_Copy(void **hData, s32 bPos, bool tbldata) {
    Clear(0);
    LoadPrefab_16624656(0, 0, 0, 0);
    return 0;
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
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    GetEffPCPAgiFireballPart(0, 0);
    Clear(0);
    return 0;
}

// 0x11f1f30
void effPCPDANTE_ShowTime_Delete(void **hData) {
}

// 0x11f3c70
void effPCPDANTE_ShowTime_Draw(void **hData) {
    nbPanelFlashInit(0, 0, 0, 0, 0, 0, 0);
    effPCPDANTE_Sprite_DrawOff();
    nbPanelFlashDraw(0, 0);
    effPCPDANTE_ShowTime_Bingo_Draw(0);
    effPCPDANTE_ShowTime_AreYouReady_Draw(0);
    effPCPDANTE_ShowTime_ShowTime_Draw(0);
}

// 0x11f4050
void effPCPDANTE_ShowTime_SetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
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
  }
  if (v5 - 10 <= 0xC)
  {
    nbPnl_rsetAlpha(0);
    effPCPDANTE_Sprite_Draw(162, 172, 1.0, 0x80808080, effPCPDANTE_ShowTime_UV, v28, 2, 1);
    if (v5 > 0xC)
  }
  else  nbPnl_rsetAlpha(1);
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
  }
  if (v5 - 8 > 0xE)
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
  effPCPDANTE_Sprite_Draw(162, 172, v18, v19, effPCPDANTE_ShowTime_UV, v15, 2, v20);
  v43 = (*pPCPShowTime)->frameParts;
  ++v43->m_Items[2];
}

// 0x11f2920
void effPCPDANTE_Sprite_Draw(s32 x, s32 y, f32 scale, u32 abgr, effPCPDANTE_UV_tag *pUV, sdfTexHandle_t *hTex, s32 type, s32 index) {
    SDF_VU0__Retdds3ColorItoF(0, 0);
}

// 0x11f25d0
void effPCPDANTE_Sprite_DrawOff(void) {
}

// 0x11ee8c0
effPCPDANTE_Thunder_tag *effPCPDANTE_Thunder_Copy(void **hData, s32 bPos, bool tbldata) {
    effPCPDANTE_Thunder_Create(0);
    return 0;
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
  v3[16] = dds3StartProcess(StringLiteral_15524, 0x2B0Au, 0, 0, v13, 0, 0, 0, 0, 0);
  dds3SetProcessData(v3 + 16, v3);
  return v3;
}

// 0x11ee170
effPCPDANTE_Thunder_tag *effPCPDANTE_Thunder_CreateP(void **pData, s32 bPos, bool tbldata) {
    effPCPDANTE_Thunder_Create(0);
    return 0;
}

// 0x11ee540
effPCPDANTE_Thunder_tag *effPCPDANTE_Thunder_CreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    effPCPDANTE_Thunder_Create(0);
    return 0;
}

// 0x11ee780
void effPCPDANTE_Thunder_Delete(void **hData) {
    dds3KillProcess(0, 0);
    effPCP_ThunderPolyDelete(0);
}

// 0x11edef0
void effPCPDANTE_Thunder_Draw(void **hData) {
    effPCP_ThunderPolyGetParam(0);
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX_B();
    SDF_VU0__SCALEVECTOR_B(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__ADDVECTOR();
    effColorBlend(0, 0, 0);
    effPCP_ThunderPolySetColor(0, 0);
    effPCP_ThunderPolyDraw(0);
}

// 0x11ee9d0
void effPCPDANTE_Thunder_DrawSub(void **hData) {
}

// 0x11ed9e0
void *effPCPDANTE_Thunder_ProcessDraw(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
    effBTLSkillCheckRun();
    effBTLSkillGetInvokeFormation(0);
    effBTLModelGetMarkMatrix2(0, 0);
    SDF_VU0__STOREMATRIX(0);
    effPCPDANTE_Thunder_SetRotateMatrix(0, 0);
    effBTLModelGetMarkPosition2(0, 0);
    SDF_VU0__STOREVECTOR(0);
    effPCPDANTE_Thunder_SetPosition(0, (sdfVector4_t){0});
    effPCPDANTE_Thunder_Draw(0);
    return 0;
}

// 0x11eeac0
void effPCPDANTE_Thunder_SetColor(void **hData, u32 abgr) {
}

// 0x11eddc0
void effPCPDANTE_Thunder_SetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x11edc90
void effPCPDANTE_Thunder_SetRotateMatrix(void **hData, sdfMatrix4_t *pRot) {
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__STOREMATRIX(0);
}

// 0x11ecee0
effPCPMuzzleFlash_tag *effPCPMuzzleFlashCopy(void **hData, s32 bPos, bool tbldata) {
    SDF_VU0__STOREIDENTITY(0);
    dds3BillboardCopy(0);
    return 0;
}

// 0x11ecb60
effPCPMuzzleFlash_tag *effPCPMuzzleFlashCreate(effPCPMuzzleFlashParam_t *pParam, void *pP2A) {
  u64 *v5;

  v5 = Allocate(effPCPMuzzleFlash_tag);
  _ctor(v5, 0);
  v5[12] = pParam;
  v5[14] = 0x3F80000000000000LL;
  SDF_VU0__STOREIDENTITY((v5 + 2), 0);
  v5[13] = dds3BillboardCreate(1, pP2A, 0, StringLiteral_416);
  return v5;
}

// 0x11ecc30
effPCPMuzzleFlash_tag *effPCPMuzzleFlashCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    GetEffPCPAgiFireballPart(0, 0);
    effPCPMuzzleFlashCreate(0, 0);
    return 0;
}

// 0x11ed040
void effPCPMuzzleFlashDelete(void **hData) {
    dds3BillboardDelete(0);
}

// 0x11ed160
void effPCPMuzzleFlashDraw(void **hData) {
    dds3BillboardGetAnimFrame(0);
    dds3BillboardSetAnimKey2(0, 0);
    effBTLSkillCheckRun();
    effBTLSkillGetInvokeFormation(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    Mult();
    ToMatrix();
    ReverseMatrix();
    SDF_VU0__COPYMATRIX_A_TO_B();
    SDF_VU0__LOADMATRIX(0);
    MultMatrixNoArg();
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(0);
    dds3BillboardGetDirectionRotate((sdfVector4_t){0}, (sdfVector4_t){0});
    dds3BillboardGetDirectionScale((sdfVector4_t){0}, (sdfVector4_t){0});
    dds3BillboardSetScale(0, 0, 0);
    dds3BillboardSetRotate(0, 0);
    dds3BillboardSetPosition(0, (sdfVector4_t){0});
    dds3BillboardDraw(0);
}

// 0x11ed560
void effPCPMuzzleFlashSetColor(void **hData, u32 abgr) {
    dds3BillboardSetRGBA(0, 0);
}

// 0x11ed690
void effPCPMuzzleFlashSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x11ed8b0
void effPCPMuzzleFlashSetRotateMatrix(void **hData, sdfMatrix4_t *pRot) {
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__STOREMATRIX(0);
}

// 0x11ed7c0
void effPCPMuzzleFlashSetScale(void **hData, f32 scale) {
}

// 0x11ec390
effPCPScreenCrackModel_t *effPCPScreenCrackModelCopy(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPartCopy(0);
    return 0;
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
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    GetEffPCPAgiFireballPart(0, 0);
    effPCPScreenCrackModelCreate(0, 0);
    return 0;
}

// 0x11ec570
void effPCPScreenCrackModelDelete(void **hData) {
    dds3EffectPartDelete(0);
}

// 0x11ec690
void effPCPScreenCrackModelDraw(void **hData) {
    dds3EffectPartGetHandle(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    sdfAtan2(0, 0);
    FromEuler(0, 0, 0);
    mdlSetRotate(0);
    SDF_VU0__SCALEVECTOR_B(0);
    SDF_VU0__ADDVECTOR();
    mdlSetPosition(0);
    dds3EffectPartModelDraw(0);
    mdlEffectUpdateRot(0, 0);
}

// 0x11ebff0
void effPCPScreenCrackModelInit(effPCPScreenCrackModel_t **pPCPScrCrackModel) {
  ;
}

// 0x11eca70
void effPCPScreenCrackModelSetColor(void **hData, u32 abgr) {
}

// 0x11f4680
effPCP_BED_tag *effPCP_BED_Copy(void **hData, s32 bPos, bool tbldata) {
    effPCP_BED_Create(0, 0);
    effEveBEDCutCreate(0, 0, 0);
    return 0;
}

// 0x11f4180
effPCP_BED_tag *effPCP_BED_Create(effPCP_BED_Param_t *pParam, void *pBED) {
    SDF_VU0__STOREIDENTITYVECTOR(0);
    SDF_VU0__STOREIDENTITY(0);
    effEveBEDCreate(0);
    effEveBEDCutCreate(0, 0, 0);
    return 0;
}

// 0x11f43d0
effPCP_BED_tag *effPCP_BED_CreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    GetEffPCPAgiFireballPart(0, 0);
    effPCP_BED_Create(0, 0);
    return 0;
}

// 0x11f48e0
void effPCP_BED_Delete(void **hData) {
    effEveBEDCutDelete(0);
    effEveBEDDelete(0);
}

// 0x11f4ec0
void effPCP_BED_Draw(void **hData) {
    effColorBlend(0, 0, 0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    effPCP_BED_MatrixToQuaternion(0);
    SDF_VU0__STOREVECTOR(0);
    effEveBEDCutSetParams(0, 0);
    effEveBEDCutDraw(0);
}

// 0x11f4a30
void effPCP_BED_MatrixToQuaternion(sdfMatrix4_t *pMatrix) {
    sdfSqrt(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
}

// 0x11f5380
void effPCP_BED_SetColor(void **hData, u32 abgr) {
}

// 0x11f5120
void effPCP_BED_SetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x11f5250
void effPCP_BED_SetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__STOREMATRIX(0);
}

// 0x11f58a0
effPCP_HBED2_tag *effPCP_HBED2_Copy(void **hData, s32 bPos, bool tbldata) {
    effPCPHelperBEDCopy(0, 0, 0);
    return 0;
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
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    GetEffPCPAgiFireballPart(0, 0);
    effPCPHelperBEDCreate(0, 0, 0);
    return 0;
}

// 0x11f5a50
void effPCP_HBED2_Delete(void **hData) {
    effPCPHelperBEDDelete(0);
}

// 0x11f5b70
void effPCP_HBED2_Draw(void **hData) {
    effPCPHelperBEDDraw(0);
}

// 0x11f5fa0
void effPCP_HBED2_SetColor(void **hData, u32 abgr) {
    effPCPHelperBEDSetColor(0, 0);
}

// 0x11f5c90
void effPCP_HBED2_SetPosition(void **hData, sdfVector4_t pPos) {
    effPCPHelperBEDSetPosition(0, (sdfVector4_t){0});
}

// 0x11f5de0
void effPCP_HBED2_SetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
    effPCPHelperBEDGetModel(0);
    effPCP_BED_MatrixToQuaternion(0);
    mdlSetRotate(0);
}

// 0x11f60d0
void effPCP_HBED2_SetScale(void **hData, f32 scale) {
    effPCPHelperBEDSetScale(0, 0);
}

// 0x11f0080
effPCP_PBCamera_tag *effPCP_PBCamera_Copy(void **hData, s32 bPos, bool tbldata) {
    Clear(0);
    dds3EffectPartCopy(0);
    return 0;
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
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    GetEffPCPAgiFireballPart(0, 0);
    effPCP_PBCamera_Create(0, 0);
    return 0;
}

// 0x11f0230
void effPCP_PBCamera_Delete(void **hData) {
    dds3EffectPartDelete(0);
}

// 0x11f0350
void effPCP_PBCamera_Run(void **hData) {
    effBTLSkillCheckRun();
    effBTLSkillGetID();
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillGetTargetFormation(0);
    mdlGetPosition(0);
    SDF_VU0__STOREVECTOR(0);
    effPCP_PBCamera_SetPosition(0, (sdfVector4_t){0});
    dds3EffectPartSetRotateMatrix(0, 0);
    dds3EffectPartSetPosition(0, (sdfVector4_t){0});
    dds3EffectPartDraw(0);
    effBTLModelGetID(0);
    nbCameraDANTE_KAGIRI_Set(0);
    dds3EffectPartGetHandle(0);
    nbCameraSetState(0);
    nbCameraHelperModelSetSub(0, 0, 0);
}

// 0x11f0b20
void effPCP_PBCamera_SetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x11f0c50
void effPCP_PBCamera_SetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__STOREMATRIX(0);
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
  effPCPBoss_c *v10;
  struct effPCPBoss_StaticFields *static_fields;
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
      if (effBossEvePadVibeFrame->m_Items[v4] < 1)
        break;
      static_fields = v10->static_fields;
      v12 = static_fields->effBossEvePadVibeFrame;
      v14 = static_fields->effBossEvePadVibeFrameStart;
      v15 = v12->m_Items[v4];
      v17 = v15;
      effBossEvePadVibeType = static_fields->effBossEvePadVibeType;
      v19 = v17 / v14->m_Items[v4];
      v21 = 1.0 - v19;
      if (effBossEvePadVibeType->m_Items[v4])
        v19 = 1.0 - v19;
      LOBYTE(v21) = effBossEvePadVibePower->m_Items[v4];
      v24 = (v19 * LODWORD(v21));
      dds3PadAct(v4, v24, 0x64u);
      v25 = effBossEvePadVibeFrame;
      --v25->m_Items[v4];
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
