#include "types.h"

typedef struct XRD773Unity_CommonMesh XRD773Unity_CommonMesh;
typedef struct XRD773Unity_GraphicManager XRD773Unity_GraphicManager;
typedef struct XRD773Unity_GraphicManager_CommonObject XRD773Unity_GraphicManager_CommonObject;
typedef struct billHandle_t billHandle_t;
typedef struct dds3EffectPCPData_t dds3EffectPCPData_t;
typedef struct dds3Effect_Blur_t dds3Effect_Blur_t;
typedef struct dds3Effect_DistortionBlurParam_t dds3Effect_DistortionBlurParam_t;
typedef struct dds3Effect_Filter_t dds3Effect_Filter_t;
typedef struct dds3Effect_PartialMultiBlurParam_t dds3Effect_PartialMultiBlurParam_t;
typedef struct dds3Effect_PartialMultiBlur_t dds3Effect_PartialMultiBlur_t;
typedef struct dds3Effect_PartialMultiFilterParam_t dds3Effect_PartialMultiFilterParam_t;
typedef struct dds3Effect_PartialMultiFilter_t dds3Effect_PartialMultiFilter_t;
typedef struct dds3Effect_RippleBlurParam_t dds3Effect_RippleBlurParam_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3RingPolyExpList_tag dds3RingPolyExpList_tag;
typedef struct effBTL_SkillPositionPtr_t effBTL_SkillPositionPtr_t;
typedef struct effBTL_t effBTL_t;
typedef struct effDistortionBlurHandle_t effDistortionBlurHandle_t;
typedef struct effEveBEDCutHandle_t effEveBEDCutHandle_t;
typedef struct effEveBEDParams_t effEveBEDParams_t;
typedef struct effHandle_t effHandle_t;
typedef struct effPCPAgiFireball2Param_t effPCPAgiFireball2Param_t;
typedef struct effPCPAgiFireball2PartList_t effPCPAgiFireball2PartList_t;
typedef struct effPCPAgiFireball2_tag effPCPAgiFireball2_tag;
typedef struct effPCPAgiFireballParam_t effPCPAgiFireballParam_t;
typedef struct effPCPAgiFireballPartList_t effPCPAgiFireballPartList_t;
typedef struct effPCPAgiFireball_tag effPCPAgiFireball_tag;
typedef struct effPCPAgiraoFireParam_t effPCPAgiraoFireParam_t;
typedef struct effPCPAgiraoFirePartList_t effPCPAgiraoFirePartList_t;
typedef struct effPCPAgiraoFire_tag effPCPAgiraoFire_tag;
typedef struct effPCPAnalyzeBED_tag effPCPAnalyzeBED_tag;
typedef struct effPCPBlinkMultiBlurBase_tag effPCPBlinkMultiBlurBase_tag;
typedef struct effPCPBlinkMultiBlur_tag effPCPBlinkMultiBlur_tag;
typedef struct effPCPBlurExpParam_t effPCPBlurExpParam_t;
typedef struct effPCPBlurExp_tag effPCPBlurExp_tag;
typedef struct effPCPBreathParam_t effPCPBreathParam_t;
typedef struct effPCPBreath_tag effPCPBreath_tag;
typedef struct effPCPBufuIce_tag effPCPBufuIce_tag;
typedef struct effPCPBufudnIce_tag effPCPBufudnIce_tag;
typedef struct effPCPBufuraIce_tag effPCPBufuraIce_tag;
typedef struct effPCPDistortionBlurExpParam_t effPCPDistortionBlurExpParam_t;
typedef struct effPCPDistortionBlurExp_tag effPCPDistortionBlurExp_tag;
typedef struct effPCPEyeThunder_tag effPCPEyeThunder_tag;
typedef struct effPCPFLEACHBlurParam_t effPCPFLEACHBlurParam_t;
typedef struct effPCPFLEACHBlur_tag effPCPFLEACHBlur_tag;
typedef struct effPCPFilterExpParam_t effPCPFilterExpParam_t;
typedef struct effPCPFilterExp_tag effPCPFilterExp_tag;
typedef struct effPCPHama01_tag effPCPHama01_tag;
typedef struct effPCPHama02_tag effPCPHama02_tag;
typedef struct effPCPHamaon_tag effPCPHamaon_tag;
typedef struct effPCPHelperBEDParam_t effPCPHelperBEDParam_t;
typedef struct effPCPHelperBED_tag effPCPHelperBED_tag;
typedef struct effPCPHouden01_tag effPCPHouden01_tag;
typedef struct effPCPHwave01_tag effPCPHwave01_tag;
typedef struct effPCPMHanma01_tag effPCPMHanma01_tag;
typedef struct effPCPMZiodin01_tag effPCPMZiodin01_tag;
typedef struct effPCPMZiodin02_tag effPCPMZiodin02_tag;
typedef struct effPCPMakka_tag effPCPMakka_tag;
typedef struct effPCPMegidora01_tag effPCPMegidora01_tag;
typedef struct effPCPMegidoraon01_tag effPCPMegidoraon01_tag;
typedef struct effPCPMisc_effPCPBufuLight_t effPCPMisc_effPCPBufuLight_t;
typedef struct effPCPMudo_tag effPCPMudo_tag;
typedef struct effPCPMultiBlurExp2Param_t effPCPMultiBlurExp2Param_t;
typedef struct effPCPMultiBlurExp2_tag effPCPMultiBlurExp2_tag;
typedef struct effPCPMultiBlurExp_tag effPCPMultiBlurExp_tag;
typedef struct effPCPMultiFilterExp_tag effPCPMultiFilterExp_tag;
typedef struct effPCPRadiateBEDParam_t effPCPRadiateBEDParam_t;
typedef struct effPCPRadiateBED_tag effPCPRadiateBED_tag;
typedef struct effPCPRadiateTBParam_t effPCPRadiateTBParam_t;
typedef struct effPCPRadiateTB_tag effPCPRadiateTB_tag;
typedef struct effPCPRadiateThunderParam_t effPCPRadiateThunderParam_t;
typedef struct effPCPRadiateThunder_tag effPCPRadiateThunder_tag;
typedef struct effPCPRingPolyExp2_tag effPCPRingPolyExp2_tag;
typedef struct effPCPRingPolyExpParam_t effPCPRingPolyExpParam_t;
typedef struct effPCPRingPolyExp_tag effPCPRingPolyExp_tag;
typedef struct effPCPRippleBlurExpParam_t effPCPRippleBlurExpParam_t;
typedef struct effPCPRippleBlurExp_tag effPCPRippleBlurExp_tag;
typedef struct effPCPShockWave01_tag effPCPShockWave01_tag;
typedef struct effPCPShockWave02_tag effPCPShockWave02_tag;
typedef struct effPCPSparkleSphere_tag effPCPSparkleSphere_tag;
typedef struct effPCPSpiralBEDParam_t effPCPSpiralBEDParam_t;
typedef struct effPCPSpiralBED_tag effPCPSpiralBED_tag;
typedef struct effPCPThunderSphereExpParam_t effPCPThunderSphereExpParam_t;
typedef struct effPCPThunderSphereExp_tag effPCPThunderSphereExp_tag;
typedef struct effPCPThunderSpherePolyParam_t effPCPThunderSpherePolyParam_t;
typedef struct effPCPThunderSpherePoly_t effPCPThunderSpherePoly_t;
typedef struct effPCPZiodin01_tag effPCPZiodin01_tag;
typedef struct effPCPZiodin02_tag effPCPZiodin02_tag;
typedef struct effPCPZiodin03_tag effPCPZiodin03_tag;
typedef struct effPCPZiodin04_tag effPCPZiodin04_tag;
typedef struct effPCP_ThunderPolyParam_t effPCP_ThunderPolyParam_t;
typedef struct effPCP_ThunderPoly_t effPCP_ThunderPoly_t;
typedef struct effPartHandle_t effPartHandle_t;
typedef struct effRippleBlurHandle_t effRippleBlurHandle_t;
typedef struct mdlManager_mdlTbMbAbLoadCb_t mdlManager_mdlTbMbAbLoadCb_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct sdf3DPrimPolyParm_t sdf3DPrimPolyParm_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfMat_t sdfMat_t;
typedef struct sdfModelOt_t sdfModelOt_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;

static sdfModelOt_t *dds3ModelOt[11];
static effPCP_ThunderPolyParam_t *effPCP_Eye_ThunderPoly_Param00_0;
static effPCP_ThunderPolyParam_t *effPCP_Eye_ThunderPoly_Param00_1;
static effPCP_ThunderPolyParam_t *effPCP_Eye_ThunderPoly_Param01_0;
static effPCP_ThunderPolyParam_t *effPCP_Eye_ThunderPoly_Param01_1;
static effPCP_ThunderPolyParam_t *effPCP_Eye_ThunderPoly_Param02_0;
static effPCP_ThunderPolyParam_t *effPCP_Eye_ThunderPoly_Param02_1;
static effPCP_ThunderPolyParam_t *effPCP_Eye_ThunderPoly_Param03_0;
static effPCP_ThunderPolyParam_t *effPCP_Eye_ThunderPoly_Param03_1;
static effPCP_ThunderPolyParam_t *effPCP_Eye_ThunderPoly_Param04_0;
static effPCP_ThunderPolyParam_t *effPCP_Eye_ThunderPoly_Param04_1;
static effPCP_ThunderPolyParam_t *effPCP_Eye_ThunderPoly_Param05_0;
static effPCP_ThunderPolyParam_t *effPCP_Eye_ThunderPoly_Param05_1;
static u16 effPCPMudoInterval[7];
static f32 effPCPMudoScale[7];
static effPCP_ThunderPolyParam_t *effPCP_Ziodin01_ThunderPoly_Param;
static effPCP_ThunderPolyParam_t *effPCP_Ziodin02_ThunderPoly_Param;
static effPCP_ThunderPolyParam_t *effPCP_Ziodin03_ThunderPoly_Param;
static effPCP_ThunderPolyParam_t *effPCP_Ziodin04_ThunderPoly_Param;
static effPCP_ThunderPolyParam_t *effPCP_MZiodin01_ThunderPoly_Param[2];
static effPCP_ThunderPolyParam_t *effPCP_MZiodin02_ThunderPoly_Param[2];
static f32 EFPCP_SWAVE01_WIDTH_S;
static f32 EFPCP_SWAVE01_HEIGHT_S;
static f32 EFPCP_SWAVE01_WIDTH;
static f32 EFPCP_SWAVE01_HEIGHT;
static effPCPThunderSpherePolyParam_t *effPCP_ShockWave01_ThunderSpherePoly_Param;
static effPCP_ThunderPolyParam_t *effPCP_ShockWave02_ThunderPoly_Param;
static effPCPThunderSpherePolyParam_t *effPCP_Houden01_ThunderSpherePoly_Param;
static u32 BlinkMultiBlurCount;
static effPCPBlinkMultiBlurBase_tag *pBlinkMultiBlurBase;
static f32 EFPCP_MEGIDORA01_WIDTH_S;
static f32 EFPCP_MEGIDORA01_HEIGHT_S;
static f32 EFPCP_MEGIDORA01_WIDTH;
static f32 EFPCP_MEGIDORA01_HEIGHT;
static f32 EFPCP_MEGIDORA01_WIDTH_S_2;
static f32 EFPCP_MEGIDORA01_HEIGHT_S_2;
static f32 EFPCP_MEGIDORA01_WIDTH_2;
static f32 EFPCP_MEGIDORA01_HEIGHT_2;
static effPCPThunderSpherePolyParam_t *effPCP_Megidora01_ThunderSpherePoly_Param;
static f32 EFPCP_MEGIDORAON01_WIDTH_S;
static f32 EFPCP_MEGIDORAON01_HEIGHT_S;
static f32 EFPCP_MEGIDORAON01_WIDTH;
static f32 EFPCP_MEGIDORAON01_HEIGHT;
static f32 EFPCP_MEGIDORAON01_WIDTH_S_2;
static f32 EFPCP_MEGIDORAON01_HEIGHT_S_2;
static f32 EFPCP_MEGIDORAON01_WIDTH_2;
static f32 EFPCP_MEGIDORAON01_HEIGHT_2;
static effPCPThunderSpherePolyParam_t *effPCP_Megidoraon01_ThunderSpherePoly_Param;
static s8 effPCPBufuLight_Start;
static u32 RingPolyExpIndex[54];
static sdf3DPrimPolyParm_t *RPE_PrimPolyParm;

void Clear(mdlManager_mdlTbMbAbLoadCb_t *this);
f32 DDS3EFFECT_RAND_F(void);
f32 DDS3EFFECT_RAND_FA(f32 r);
u32 DDS3EFFECT_RAND_I(void);
f32 DDS3EFFECT_RAND_PM(void);
void FromEuler(f32 aRotateX, f32 aRotateY, f32 aRotateZ);
sdfColor_t **GetColor(XRD773Unity_CommonMesh *this);
void *GetEffPCPAgiFireballPart(void *hData, s32 offset);
void *GetEffPCPpBEDData(void *hData, s32 offset);
s32 **GetIndexTable(XRD773Unity_CommonMesh *this);
XRD773Unity_CommonMesh *GetMesh(XRD773Unity_GraphicManager *this, s32 index, bool outlinechk);
sdfVector3_t **GetPosition(XRD773Unity_CommonMesh *this);
void LookAtMatrix(sdfVector4_t aTarget, sdfVector4_t aEye, sdfVector4_t aDown);
void Mult(void);
void MultMatrixNoArg(void);
void MultMatrixRevNoArg(void);
void ReverseMatrix(void);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__ADDVECTOR_A_C(void);
void SDF_VU0__APPLYMATRIX(void);
void SDF_VU0__APPLYMATRIX_XYZ(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__COPYVECTOR_A_TO_B(void);
void SDF_VU0__COPYVECTOR_A_TO_C(void);
void SDF_VU0__COPYVECTOR_B_TO_C(void);
void SDF_VU0__COPYVECTOR_C_TO_B(void);
f32 SDF_VU0__GETLENGTH(void);
void SDF_VU0__LOADMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__LOADMATRIX_B(sdfMatrix4_t *aMatrix);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__MULVECTOR(void);
void SDF_VU0__NORMALIZE(void);
void SDF_VU0__OUTERPRODUCT(void);
void SDF_VU0__RESET_ROW3(void);
void SDF_VU0__STOREIDENTITY(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
void SDF_VU0__VECTOR_W_SET_ZERO(void);
void SetActive(XRD773Unity_GraphicManager_CommonObject *this, bool act);
void SetAutoHide(XRD773Unity_GraphicManager_CommonObject *this, bool act);
void SetColor_20241296(XRD773Unity_CommonMesh *this, sdfColor_t **col);
void SetIndexTable(XRD773Unity_CommonMesh *this, s32 **idx);
void SetPosition_20241056(XRD773Unity_CommonMesh *this, sdfVector3_t **pos);
void SetRotateMatrixAxis(f32 aAngle, sdfVector4_t aAxis);
void SetRotateMatrixX(f32 aAngle);
void SetRotateMatrixX_B(f32 aAngle);
void SetRotateMatrixY(f32 aAngle);
void SetRotateMatrixY_B(f32 aAngle);
void SetRotateMatrixZ(f32 aAngle);
void SetRotateMatrixZ_B(f32 aAngle);
void StoreMatrix(sdfMatrix4_t *aMatrix);
void dds3BillboardDelete(void **hData);
void dds3BillboardDraw(void **hData);
void *dds3BillboardGeneral(s32 number);
void dds3BillboardSetAnimKey(billHandle_t **hBillboard, s32 frame);
void dds3BillboardSetMode(billHandle_t **hBillboard, s16 mode);
void dds3BillboardSetPosition(billHandle_t **hBillboard, sdfVector4_t pPos);
void dds3BillboardSetRGBA(billHandle_t **hBillboard, u32 abgr);
void dds3BillboardSetScale(billHandle_t **hBillboard, f32 x, f32 y);
void dds3EffectBlur(dds3Effect_Blur_t **pBlur, bool bPS2mode, s32 SkillID);
effHandle_t *dds3EffectCopy(void **pData, s32 bPos, bool tbldata);
void dds3EffectDelete(void **pData);
effDistortionBlurHandle_t *dds3EffectDistortionBlurCreate(dds3Effect_DistortionBlurParam_t *pParam);
void dds3EffectDistortionBlurDelete(effDistortionBlurHandle_t **hDistortionBlur);
void dds3EffectDistortionBlurDraw(effDistortionBlurHandle_t **hDistortionBlur, bool bPS2mode, s32 SkillID);
void dds3EffectDraw(void **pData);
void dds3EffectFilter(dds3Effect_Filter_t *pFilter);
effHandle_t *dds3EffectLoad(void **pD3P, s32 bPos, bool tbldata);
void *dds3EffectPCPDataGetDataUnity(void *hData, u32 number, s32 type, s32 bPos);
void *dds3EffectPCPDataGetDataUnityOffSet(void *hData, s32 offset, s32 type);
effPartHandle_t *dds3EffectPCPDataPartCreate(dds3EffectPCPData_t *hPCPData, u8 **bytedata, s32 bPos, u32 number);
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
void dds3EffectPartSetScale(effPartHandle_t **hEffPart, f32 scale);
dds3Effect_PartialMultiBlur_t *dds3EffectPartialMultiBlurCreate(dds3Effect_PartialMultiBlurParam_t *pParam);
void dds3EffectPartialMultiBlurDelete(dds3Effect_PartialMultiBlur_t **hPartialMultiBlur);
void dds3EffectPartialMultiBlurDraw(dds3Effect_PartialMultiBlur_t **hPartialMultiBlur, bool bPS2mode, s32 SkillID);
void dds3EffectPartialMultiBlurSetParam(dds3Effect_PartialMultiBlur_t **hPartialMultiBlur, dds3Effect_PartialMultiBlurParam_t *pParam);
dds3Effect_PartialMultiFilter_t *dds3EffectPartialMultiFilterCreate(dds3Effect_PartialMultiFilterParam_t *pParam);
void dds3EffectPartialMultiFilterDelete(dds3Effect_PartialMultiFilter_t *hPartialMultiFilter);
void dds3EffectPartialMultiFilterDraw(dds3Effect_PartialMultiFilter_t **hPartialMultiFilter);
effRippleBlurHandle_t *dds3EffectRippleBlurCreate(dds3Effect_RippleBlurParam_t *pParam);
void dds3EffectRippleBlurDelete(effRippleBlurHandle_t **hRippleBlur);
void dds3EffectRippleBlurDraw(effRippleBlurHandle_t **hRippleBlur, bool UnityCalc);
void dds3EffectRippleBlurReset(effRippleBlurHandle_t **hRippleBlur);
void dds3EffectSetPosition(void **pData, sdfVector4_t pPos);
void dds3EffectSetRGBA(void **pData, u32 abgr);
void dds3EffectSetRotateMatrix(void **pData, sdfMatrix4_t *pMatrix);
void dds3Effect_PartialMultiBlurParam_t__Clear(dds3Effect_PartialMultiBlurParam_t *this);
void dds3Effect_PartialMultiBlur_t__Clear(dds3Effect_PartialMultiBlur_t *this);
dds3RingPolyExpList_tag *dds3RingPolyExpListCreate(u32 face);
void dds3RingPolyExpListDelete(void **hData);
void dds3RingPolyExpListDraw(void **hData);
void effBTLFieldLightAnimationSet(s32 frame, f32 angle);
void effBTLFieldLightAxisSet(sdfVector4_t pAxis);
void effBTLFieldLightDirectionSet(sdfVector4_t pDir);
u32 effBTLModelGetID(nbFormation_t **pFormation);
void effBTLModelGetSphereCenter(nbFormation_t **pFormation);
void effBTLModelGroupGetCenter(u32 group);
void effBTLPartGetPositionPtr(nbFormation_t **pFormation, effBTL_SkillPositionPtr_t **pPosPtr, sdfVector4_t *pPos);
s32 effBTLSkillCheckRun(void);
u32 effBTLSkillGetID(void);
nbFormation_t *effBTLSkillGetInvokeFormation(s32 idx);
nbFormation_t *effBTLSkillGetTargetFormation(u32 number);
u32 effBTLSkillGetTargetParty(void);
u32 effColorBlend(u32 abgr0, u32 abgr1, f32 rate);
u32 effColorMultiply(u32 abgr0, u32 abgr1);
effBTL_t *effEveBEDCreate(u8 **pData);
effEveBEDCutHandle_t *effEveBEDCutCreate(effBTL_t *hEveBED, u16 CutNum, effEveBEDParams_t *pParams);
void effEveBEDCutDelete(effEveBEDCutHandle_t *hEveBEDCut);
void effEveBEDCutDraw(effEveBEDCutHandle_t **hEveBEDCut);
void effEveBEDCutSetParams(effEveBEDCutHandle_t **hEveBEDCut, effEveBEDParams_t *pParams);
void effEveBEDCutSetScale(effEveBEDCutHandle_t **hEveBEDCut, f32 scale);
void effEveBEDDelete(effBTL_t *hEveBED);
void effEveBEDParams_t__Clear(effEveBEDParams_t *this);
sdfColor_t effGetBlendColor(u32 icol);
sdfColor_t effGetVertexColor(u32 icol, sdfColor_t blend_col);
effPCPAgiFireball2_tag *effPCPAgiFireball2Create(effPCPAgiFireball2Param_t *pAFB2Param, effPCPAgiFireball2PartList_t *pAFB2Part);
void effPCPAgiFireballCopySub(effPCPAgiFireball_tag **pPCPAgiFireball, effPCPAgiFireball_tag *pPCPAgiFireballSrc);
effPCPAgiFireball_tag *effPCPAgiFireballCreate(effPCPAgiFireballParam_t *pParam, effPCPAgiFireballPartList_t *pPart);
effPCPAgiFireball_tag *effPCPAgiFireballCreatePCF(void **hData, s32 bPos, bool tbldata);
void effPCPAgiFireballDelete(void **hData);
void effPCPAgiFireballDraw(void **hData);
void effPCPAgiFireballSetColor(void **hData, u32 abgr);
void effPCPAgiFireballSetPosition(void **hData, sdfVector4_t pPos);
void effPCPAgiFireballSetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix);
effPCPAgiraoFire_tag *effPCPAgiraoFireCreate(effPCPAgiraoFireParam_t *pParam, effPCPAgiraoFirePartList_t *pPartList);
effPCPAnalyzeBED_tag *effPCPAnalyzeBEDCreate(void *pBEDData);
void effPCPAnalyzeInit(effPCPAnalyzeBED_tag **pAnalyzeBED);
effPCPBreath_tag *effPCPBreathCreate(effPCPBreathParam_t *pParam, void *pData, s32 bPos);
effPCPDistortionBlurExp_tag *effPCPDistortionBlurExpCreate(effPCPDistortionBlurExpParam_t *pParam);
effPCPEyeThunder_tag *effPCPEyeThunderCreate00_0(void **hData, s32 bPos, bool tbldata);
effPCPEyeThunder_tag *effPCPEyeThunderCreate00_1(void **hData, s32 bPos, bool tbldata);
effPCPEyeThunder_tag *effPCPEyeThunderCreate01_0(void **hData, s32 bPos, bool tbldata);
effPCPEyeThunder_tag *effPCPEyeThunderCreate01_1(void **hData, s32 bPos, bool tbldata);
effPCPEyeThunder_tag *effPCPEyeThunderCreate02_0(void **hData, s32 bPos, bool tbldata);
effPCPEyeThunder_tag *effPCPEyeThunderCreate02_1(void **hData, s32 bPos, bool tbldata);
effPCPEyeThunder_tag *effPCPEyeThunderCreate03_0(void **hData, s32 bPos, bool tbldata);
effPCPEyeThunder_tag *effPCPEyeThunderCreate03_1(void **hData, s32 bPos, bool tbldata);
effPCPEyeThunder_tag *effPCPEyeThunderCreate04_0(void **hData, s32 bPos, bool tbldata);
effPCPEyeThunder_tag *effPCPEyeThunderCreate04_1(void **hData, s32 bPos, bool tbldata);
effPCPEyeThunder_tag *effPCPEyeThunderCreate05_0(void **hData, s32 bPos, bool tbldata);
effPCPEyeThunder_tag *effPCPEyeThunderCreate05_1(void **hData, s32 bPos, bool tbldata);
void effPCPHama01PartInit(effPCPHama01_tag **pPCPHama01, u32 number);
void effPCPHama02PartInit(effPCPHama02_tag **pPCPHama02, u32 number);
void effPCPHamaonPartInit(effPCPHamaon_tag **pPCPHamaon, u32 kind, u32 attach);
effPCPHelperBED_tag *effPCPHelperBEDCreate(effPCPHelperBEDParam_t *pParam, void *pPBData, void *pBEDData);
void effPCPHelperBEDParam_t__pClone(effPCPHelperBEDParam_t *this, effPCPHelperBEDParam_t **param);
void effPCPHelperInit(effPCPHelperBED_tag **pHelperBED);
void effPCPMHanma01PartInit(effPCPMHanma01_tag **pPCPMHanma01, s32 number);
void effPCPMZiodin01Init(effPCPMZiodin01_tag **pPCPMZiodin01);
void effPCPMZiodin02Init(effPCPMZiodin02_tag **pPCPMZiodin02);
effPCPMultiBlurExp2_tag *effPCPMultiBlurExp2Create(effPCPMultiBlurExp2Param_t *pParam);
effPCPMultiFilterExp_tag *effPCPMultiFilterExpCreate(void **hData, s32 bPos, bool tbldata);
effPCPRadiateBED_tag *effPCPRadiateBEDCreate(effPCPRadiateBEDParam_t *pParam, void *pBEDData);
void effPCPRadiateBEDPartInit(effPCPRadiateBED_tag **pRadiateBED, s32 index);
effPCPRadiateTB_tag *effPCPRadiateTBCreate(effPCPRadiateTBParam_t *pParam, void *pBEDData0, void *pBEDData1);
void effPCPRadiateTBPartInit(effPCPRadiateTB_tag **pRadiateTB, s32 index);
effPCPRadiateThunder_tag *effPCPRadiateThunderCreate(effPCPRadiateThunderParam_t *pParam, void **pData);
void effPCPRadiateThunderParam_t__pClone(effPCPRadiateThunderParam_t *this, effPCPRadiateThunderParam_t **param);
void effPCPRadiateThunderPartInit(effPCPRadiateThunder_tag **pRadiateThunder, s32 index);
effPCPRingPolyExp2_tag *effPCPRingPolyExp2Create(void **hData);
void effPCPRingPolyExp2Init(effPCPRingPolyExp2_tag **pPCPRingPolyExp2);
void effPCPRingPolyExp2SetVertex(effPCPRingPolyExp2_tag **pPCPRingPolyExp2, f32 radius);
effPCPRingPolyExp_tag *effPCPRingPolyExpCreate(effPCPRingPolyExpParam_t *pParam);
void effPCPRingPolyExpSetVertex(effPCPRingPolyExp_tag **pPCPRingPolyExp, f32 radius);
effPCPRippleBlurExp_tag *effPCPRippleBlurExpCreate(effPCPRippleBlurExpParam_t *pParam);
void effPCPShockWave02Init(effPCPShockWave02_tag **pPCPShockWave02);
effPCPSpiralBED_tag *effPCPSpiralBEDCreate(effPCPSpiralBEDParam_t *pParam, void *pBEDData);
void effPCPSpiralBEDPartInit(effPCPSpiralBED_tag **pSpiralBED, s32 index);
effPCPThunderSphereExp_tag *effPCPThunderSphereExpCreate(effPCPThunderSphereExpParam_t *pParam);
effPCPThunderSpherePoly_t *effPCPThunderSpherePolyCreate(void **hData, s32 bPos, bool tbldata);
void effPCPThunderSpherePolyDelete(void **hData);
void effPCPThunderSpherePolyDraw(void **hData);
effPCPThunderSpherePolyParam_t *effPCPThunderSpherePolyGetParam(effPCPThunderSpherePoly_t *pThunderPoly);
void effPCPThunderSpherePolySetColor(void **hData, u32 abgr);
void effPCPThunderSpherePolySetPosition(void **hData, sdfVector4_t pPos);
void effPCPThunderSpherePolySetScale(void **hData, f32 scale);
void effPCPZiodin01Init(effPCPZiodin01_tag **pPCPZiodin01);
void effPCPZiodin02Init(effPCPZiodin02_tag **pPCPZiodin02);
void effPCPZiodin03Init(effPCPZiodin03_tag **pPCPZiodin03);
void effPCPZiodin04Init(effPCPZiodin04_tag **pPCPZiodin04);
effPCP_ThunderPoly_t *effPCP_ThunderPolyCreate(void **hData, s32 bPos, bool tbldata);
void effPCP_ThunderPolyDelete(void **hData);
void effPCP_ThunderPolyDraw(void **hData);
effPCP_ThunderPolyParam_t *effPCP_ThunderPolyGetParam(effPCP_ThunderPoly_t *pThunderPoly);
void effPCP_ThunderPolySetColor(void **hData, u32 abgr);
s32 effScreenArea(f32 area);
void effScreenOffset(void);
s32 mdlGetMotionLengthUnity(dds3ModelHandle_t *aHandle);
void mdlSetColor(dds3ModelHandle_t **aHandle, u32 aColor);
void mdlSetPosition(dds3ModelHandle_t **aHandle);
void mdlSetRotate(dds3ModelHandle_t **aHandle);
void mdlSetScale(dds3ModelHandle_t **aHandle);
f32 sdfAtan2(f32 aY, f32 aX);
f32 sdfCos(f32 aRadius);
f32 sdfFabs(f32 c);
sdfMat_t *sdfMatNew(void);
s32 sdfModelGetMarkPosCountUnity(sdfModelRootNode_t *aRoot);
s32 sdfModelGetMarkPosUnity(sdfModelRootNode_t *aRoot, s32 aId);
f32 sdfSin(f32 aRadius);

// 0x11726b0
void *GetEffPCPAgiFireballPart(void *hData, s32 offset) {
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    return 0;
}

// 0x1186df0
void *GetEffPCPpBEDData(void *hData, s32 offset) {
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    return 0;
}

// 0x117fa40
dds3RingPolyExpList_tag *dds3RingPolyExpListCreate(u32 face) {
  u64 v3;
  u64 *v4;
  u64 *v5;

  v3 = 4 * face + 4;
  v4 = Allocate(dds3RingPolyExpList_tag);
  _ctor(v4, 0);
  v4[22] = NewSpecific(UnityEngine_Vector4, v3);
  v5 = NewSpecific(uint, v3);
  *(v4 + 42) = -2139062144;
  *(v4 + 43) = v3;
  v4[23] = v5;
  v4[25] = 0;
  v4[20] = 0x23F800000LL;
  *(v4 + 52) = 1;
  v4[24] = sdfMatNew();
  SDF_VU0__STOREIDENTITY((v4 + 10), 0);
  SDF_VU0__STOREIDENTITY((v4 + 2), 0);
  RPE_PrimPolyParm->attr = 0x4000;
  return v4;
}

// 0x117fb70
void dds3RingPolyExpListDelete(void **hData) {
}

// 0x117fd70
void dds3RingPolyExpListDraw(void **hData) {
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__LOADMATRIX_B(0);
    MultMatrixNoArg();
    StoreMatrix(0);
    GetMesh(0, 0, 0);
    SetAutoHide(0, 0);
    effGetBlendColor(0);
    GetPosition(0);
    SetPosition_20241056(0, 0);
    SetColor_20241296(0, 0);
    SetIndexTable(0, 0);
    GetColor(0);
    effGetVertexColor(0, (sdfColor_t){0});
    GetIndexTable(0);
    SetActive(0, 0);
}

// 0x1179200
effPCPAgiFireball2_tag *effPCPAgiFireball2Copy(void **hData, s32 bPos, bool tbldata) {
    Clear(0);
    SDF_VU0__STOREIDENTITY(0);
    return 0;
}

// 0x11786f0
effPCPAgiFireball2_tag *effPCPAgiFireball2Create(effPCPAgiFireball2Param_t *pAFB2Param, effPCPAgiFireball2PartList_t *pAFB2Part) {
  effPCPAgiFireball2_tag_o *v5;
  struct effPCPAgiFireball_tag_array *v6;
  u32 *v7;
  u64 i;
  u64 *v9;
  struct effPCPAgiFireball_tag_array *pAgiFireball;
  struct System_Object_array *pHelper;
  struct effPCPAgiFireballParam_t_array *param;
  u32 *v18;
  effPCPAgiFireballParam_t_o *v20;
  effPCPAgiFireballPartList_t_o *PartList;
  s64 *v22;
  s64 *v23;

  v5 = Allocate(effPCPAgiFireball2_tag);
  _ctor(v5, 0);
  Clear(v5, 0);
  v5->param = pAFB2Param;
  v5->frame = 0;
  v6 = NewSpecific(effPCPAgiFireball_tag, 3u);
  v5->pAgiFireball = v6;
  v7 = v6;
  for (i = 0; ; ++i)
  {
    v9 = Allocate(effPCPAgiFireball_tag);
    _ctor(v9, 0);
    *&v7[2 * i + 8] = v9;
    pAgiFireball = v5->pAgiFireball;
    Clear(pAgiFireball->m_Items[i], 0);
    pHelper = pAFB2Part->pHelper;
    pAFB2Part->PartList->pHelper = pHelper->m_Items[i];
    param = pAFB2Param->param;
    v18 = v5->pAgiFireball;
    v20 = param->m_Items[i];
    PartList = pAFB2Part->PartList;
    v22 = effPCPAgiFireballCreate(v20, PartList);
    v23 = v22;
    *&v18[2 * i + 8] = v23;
    if (i == 2)
      break;
    v7 = v5->pAgiFireball;
  }
  return v5;
}

// 0x1178950
effPCPAgiFireball2_tag *effPCPAgiFireball2CreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    GetEffPCPAgiFireballPart(0, 0);
    effPCPAgiFireball2Create(0, 0);
    return 0;
}

// 0x1179530
void effPCPAgiFireball2Delete(void **hData) {
    effPCPAgiFireballDelete(0);
}

// 0x1179700
void effPCPAgiFireball2Draw(void **hData) {
    effPCPAgiFireballDraw(0);
}

// 0x1179bd0
void effPCPAgiFireball2SetColor(void **hData, u32 abgr) {
    effPCPAgiFireballSetColor(0, 0);
}

// 0x11799b0
void effPCPAgiFireball2SetPosition(void **hData, sdfVector4_t pPos) {
    effPCPAgiFireballSetPosition(0, (sdfVector4_t){0});
}

// 0x1179db0
void effPCPAgiFireball2SetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
    effPCPAgiFireballSetRotateMatrix(0, 0);
}

// 0x1175790
effPCPAgiFireball_tag *effPCPAgiFireballCopy(void **hData, s32 bPos, bool tbldata) {
    Clear(0);
    SDF_VU0__STOREIDENTITY(0);
    effPCPAgiFireballCopySub(0, 0);
    return 0;
}

// 0x1174c40
void effPCPAgiFireballCopySub(effPCPAgiFireball_tag **pPCPAgiFireball, effPCPAgiFireball_tag *pPCPAgiFireballSrc) {
    dds3EffectPartCopy(0);
}

// 0x1173560
effPCPAgiFireball_tag *effPCPAgiFireballCreate(effPCPAgiFireballParam_t *pParam, effPCPAgiFireballPartList_t *pPart) {
    Clear(0);
    SDF_VU0__STOREIDENTITY(0);
    dds3EffectPartCreate(0, 0);
    dds3EffectPartGetHandle(0);
    dds3EffectPartModelDraw(0);
    mdlGetMotionLengthUnity(0);
    dds3EffectPartModelDelete(0);
    return 0;
}

// 0x1174090
effPCPAgiFireball_tag *effPCPAgiFireballCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    GetEffPCPAgiFireballPart(0, 0);
    effPCPAgiFireballCreate(0, 0);
    return 0;
}

// 0x1175900
void effPCPAgiFireballDelete(void **hData) {
    dds3EffectPartDelete(0);
}

// 0x1175ee0
void effPCPAgiFireballDraw(void **hData) {
    effPCPAgiFireballCopySub(0, 0);
    dds3EffectPartSetScale(0, 0);
    effColorBlend(0, 0, 0);
    dds3EffectPartGetHandle(0);
    dds3EffectPartSetPosition(0, (sdfVector4_t){0});
    effBTLSkillCheckRun();
    effBTLSkillGetInvokeFormation(0);
    effBTLModelGetSphereCenter(0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__COPYVECTOR_B_TO_C();
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__MULVECTOR();
    SDF_VU0__COPYVECTOR_C_TO_B();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__GETLENGTH();
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__STOREMATRIX(0);
    LookAtMatrix((sdfVector4_t){0}, (sdfVector4_t){0}, (sdfVector4_t){0});
    ReverseMatrix();
    SDF_VU0__RESET_ROW3();
    dds3EffectPartSetRotateMatrix(0, 0);
    dds3EffectPartSetColor(0, 0);
    dds3EffectPartModelDraw(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    sdfModelGetMarkPosUnity(0, 0);
    dds3EffectPartDraw(0);
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__OUTERPRODUCT();
    dds3EffectPartCopy(0);
    DDS3EFFECT_RAND_FA(0);
    DDS3EFFECT_RAND_PM();
    SDF_VU0__ADDVECTOR_A_C();
}

// 0x1178130
void effPCPAgiFireballSetColor(void **hData, u32 abgr) {
}

// 0x1178010
void effPCPAgiFireballSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1178220
void effPCPAgiFireballSetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__STOREMATRIX(0);
}

// 0x11785b0
effPCPAgiFireball_tag *effPCPAgiFireballSp2Copy(void **hData, s32 bPos, bool tbldata) {
    Clear(0);
    SDF_VU0__STOREIDENTITY(0);
    return 0;
}

// 0x1178520
effPCPAgiFireball_tag *effPCPAgiFireballSp2CreatePCF(void **hData, s32 bPos, bool tbldata) {
  effPCPAgiFireball_tag_o *result;

  result = effPCPAgiFireballCreatePCF(hData, bPos, 0);
  result->type = 2;
  return result;
}

// 0x11783e0
effPCPAgiFireball_tag *effPCPAgiFireballSpCopy(void **hData, s32 bPos, bool tbldata) {
    Clear(0);
    SDF_VU0__STOREIDENTITY(0);
    return 0;
}

// 0x1178350
effPCPAgiFireball_tag *effPCPAgiFireballSpCreatePCF(void **hData, s32 bPos, bool tbldata) {
  effPCPAgiFireball_tag_o *result;

  result = effPCPAgiFireballCreatePCF(hData, bPos, 0);
  result->type = 1;
  return result;
}

// 0x1172820
effPCPAgiraoFire_tag *effPCPAgiraoFireCopy(void **hData, s32 bPos, bool tbldata) {
    Clear(0);
    dds3EffectCopy(0, 0, 0);
    return 0;
}

// 0x1172050
effPCPAgiraoFire_tag *effPCPAgiraoFireCreate(effPCPAgiraoFireParam_t *pParam, effPCPAgiraoFirePartList_t *pPartList) {
    Clear(0);
    dds3EffectLoad(0, 0, 0);
    dds3EffectCopy(0, 0, 0);
    return 0;
}

// 0x1172370
effPCPAgiraoFire_tag *effPCPAgiraoFireCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    GetEffPCPAgiFireballPart(0, 0);
    effPCPAgiraoFireCreate(0, 0);
    return 0;
}

// 0x1172c60
void effPCPAgiraoFireDelete(void **hData) {
    dds3EffectDelete(0);
}

// 0x1172eb0
void effPCPAgiraoFireDraw(void **hData) {
    LookAtMatrix((sdfVector4_t){0}, (sdfVector4_t){0}, (sdfVector4_t){0});
    SDF_VU0__STOREMATRIX(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__VECTOR_W_SET_ZERO();
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(0);
    dds3EffectSetRGBA(0, 0);
    dds3EffectSetPosition(0, (sdfVector4_t){0});
    dds3EffectDraw(0);
}

// 0x1173470
void effPCPAgiraoFireSetColor(void **hData, u32 abgr) {
}

// 0x1173350
void effPCPAgiraoFireSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x118cec0
effPCPAnalyzeBED_tag *effPCPAnalyzeBEDCopy(void **hData, s32 bPos, bool tbldata) {
    effPCPAnalyzeInit(0);
    return 0;
}

// 0x118cbd0
effPCPAnalyzeBED_tag *effPCPAnalyzeBEDCreate(void *pBEDData) {
    effEveBEDCreate(0);
    effPCPAnalyzeInit(0);
    return 0;
}

// 0x118cd40
effPCPAnalyzeBED_tag *effPCPAnalyzeBEDCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    GetEffPCPpBEDData(0, 0);
    effPCPAnalyzeBEDCreate(0);
    return 0;
}

// 0x118d050
void effPCPAnalyzeBEDDelete(void **hData) {
    effEveBEDCutDelete(0);
    effEveBEDDelete(0);
}

// 0x118d1c0
void effPCPAnalyzeBEDDraw(void **hData) {
    effBTLSkillCheckRun();
    effBTLSkillGetTargetFormation(0);
    effBTLPartGetPositionPtr(0, 0, 0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    effBTLModelGetID(0);
    effEveBEDCutSetParams(0, 0);
    effEveBEDCutDraw(0);
}

// 0x118d720
void effPCPAnalyzeBEDSetColor(void **hData, u32 abgr) {
}

// 0x118d630
void effPCPAnalyzeBEDSetScale(void **hData, f32 scale) {
}

// 0x118ca50
void effPCPAnalyzeInit(effPCPAnalyzeBED_tag **pAnalyzeBED) {
    effEveBEDCutCreate(0, 0, 0);
}

// 0x1169ee0
effPCPBlinkMultiBlur_tag *effPCPBlinkMultiBlurCreate(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPartialMultiBlurCreate(0);
    return 0;
}

// 0x116a290
void effPCPBlinkMultiBlurDelete(void **hData) {
  effPCPMisc_c *v2;
  struct effPCPMisc_StaticFields *static_fields;
  dds3Effect_PartialMultiBlur_t_o **p_hBlur;

  --BlinkMultiBlurCount;
  static_fields = v2->static_fields;
  if (!static_fields->BlinkMultiBlurCount)
  {
    p_hBlur = &static_fields->pBlinkMultiBlurBase->hBlur;
    dds3EffectPartialMultiBlurDelete(p_hBlur);
  }
}

// 0x116a370
void effPCPBlinkMultiBlurDraw(void **hData) {
    dds3Effect_PartialMultiBlur_t__Clear(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    effScreenArea(0);
    SDF_VU0__STOREVECTOR(0);
    effColorMultiply(0, 0);
    effBTLSkillCheckRun();
    effBTLSkillGetID();
    dds3EffectPartialMultiBlurDraw(0, 0, 0);
}

// 0x116a990
void effPCPBlinkMultiBlurSetArea(void **hData, f32 area) {
  pBlinkMultiBlurBase->area = area;
}

// 0x116a920
void effPCPBlinkMultiBlurSetColor(void **hData, u32 abgr) {
  pBlinkMultiBlurBase->abgr = abgr;
}

// 0x116a880
void effPCPBlinkMultiBlurSetPosition(void **hData, sdfVector4_t pPos) {
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
  SDF_VU0__COPYVECTOR(&pBlinkMultiBlurBase->pos, v8);
}

// 0x116dd20
effPCPBlurExp_tag *effPCPBlurExpCopy(void **hData, s32 bPos, bool tbldata) {
    return 0;
}

// 0x116da00
effPCPBlurExp_tag *effPCPBlurExpCreate(effPCPBlurExpParam_t *pParam) {
  effPCPBlurExp_tag_o *v3;

  v3 = Allocate(effPCPBlurExp_tag);
  _ctor(v3, 0);
  v3->param = pParam;
  v3->frame = 0;
  v3->abgr = -2139062144;
  v3->abgr_base = pParam->Blur->abgr;
  return v3;
}

// 0x116d890
effPCPBlurExp_tag *effPCPBlurExpCreateP(void **pData, s32 bPos, bool tbldata) {
    return 0;
}

// 0x116da80
effPCPBlurExp_tag *effPCPBlurExpCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    return 0;
}

// 0x116dea0
void effPCPBlurExpDelete(void **hData) {

}

// 0x116dee0
void effPCPBlurExpDraw(void **hData) {
    effColorBlend(0, 0, 0);
    effColorMultiply(0, 0);
    effBTLSkillCheckRun();
    effBTLSkillGetID();
    dds3EffectBlur(0, 0, 0);
}

// 0x116e2a0
void effPCPBlurExpSetColor(void **hData, u32 abgr) {
}

// 0x1171330
effPCPBreath_tag *effPCPBreathCopy(void **hData, s32 bPos, bool tbldata) {
    SDF_VU0__STOREIDENTITY(0);
    dds3EffectCopy(0, 0, 0);
    return 0;
}

// 0x1170f60
effPCPBreath_tag *effPCPBreathCreate(effPCPBreathParam_t *pParam, void *pData, s32 bPos) {
  effPCPBreath_tag_o *v7;
  f32 v8;
  f32 v9;
  Il2CppObject *pD3P;

  pD3P = pData;
  v7 = Allocate(effPCPBreath_tag);
  _ctor(v7, 0);
  v7->param = pParam;
  v7->frame = 0;
  v8 = pParam->angle * 0.017453;
  v7->rotate = v8 * -0.5;
  v9 = (pParam->life - (pParam->fade_out >> 1) - pParam->start);
  v7->abgr = -2139062144;
  v7->speed = v8 / v9;
  SDF_VU0__STOREIDENTITY(&v7->matrix);
  v7->hD3P = 0;
  if (pData)
  {
    v7->hD3P = dds3EffectLoad(&pD3P, bPos, 0, 0);
  }
  return v7;
}

// 0x1171070
effPCPBreath_tag *effPCPBreathCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    effPCPBreathCreate(0, 0, 0);
    return 0;
}

// 0x1171530
void effPCPBreathDelete(void **hData) {
    dds3EffectDelete(0);
}

// 0x1171650
void effPCPBreathDraw(void **hData) {
    effBTLSkillCheckRun();
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillGetTargetParty();
    effBTLModelGroupGetCenter(0);
    SDF_VU0__STOREVECTOR(0);
    effBTLModelGetSphereCenter(0);
    sdfAtan2(0, 0);
    SDF_VU0__LOADMATRIX(0);
    SetRotateMatrixY_B(0);
    MultMatrixNoArg();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX_XYZ();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__MULVECTOR();
    SDF_VU0__ADDVECTOR();
    dds3EffectSetPosition(0, (sdfVector4_t){0});
    SetRotateMatrixY(0);
    SDF_VU0__STOREMATRIX(0);
    dds3EffectSetRotateMatrix(0, 0);
    effColorBlend(0, 0, 0);
    dds3EffectSetRGBA(0, 0);
    dds3EffectDraw(0);
}

// 0x1171df0
void effPCPBreathSetColor(void **hData, u32 abgr) {
}

// 0x1171cd0
void effPCPBreathSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1171ee0
void effPCPBreathSetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
    SetRotateMatrixY(0);
    SDF_VU0__LOADMATRIX_B(0);
    MultMatrixNoArg();
    SDF_VU0__STOREMATRIX(0);
}

// 0x117a250
effPCPBufuIce_tag *effPCPBufuIceCopy(void **hData, s32 bPos, bool tbldata) {
    SDF_VU0__STOREIDENTITY(0);
    DDS3EFFECT_RAND_PM();
    DDS3EFFECT_RAND_I();
    dds3EffectPartCopy(0);
    return 0;
}

// 0x117a050
effPCPBufuIce_tag *effPCPBufuIceCreate(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataPartCreate(0, 0, 0, 0);
    SDF_VU0__STOREIDENTITY(0);
    DDS3EFFECT_RAND_PM();
    DDS3EFFECT_RAND_I();
    return 0;
}

// 0x117a410
void effPCPBufuIceDelete(void **hData) {
    dds3EffectPartDelete(0);
}

// 0x117a530
void effPCPBufuIceDraw(void **hData) {
    dds3EffectPartSetPosition(0, (sdfVector4_t){0});
    dds3EffectPartSetScale(0, 0);
    dds3EffectPartSetColor(0, 0);
    SetRotateMatrixY(0);
    SDF_VU0__LOADMATRIX_B(0);
    MultMatrixNoArg();
    SDF_VU0__STOREMATRIX(0);
    dds3EffectPartSetRotateMatrix(0, 0);
    dds3EffectPartDraw(0);
}

// 0x117a8b0
void effPCPBufuIceSetColor(void **hData, u32 abgr) {
}

// 0x117a780
void effPCPBufuIceSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x117aa90
void effPCPBufuIceSetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__STOREMATRIX(0);
}

// 0x117a9a0
void effPCPBufuIceSetScale(void **hData, f32 scale) {
}

// 0x117cdd0
effPCPMisc_effPCPBufuLight_t *effPCPBufuLightCopy(void **hData, s32 bPos, bool tbldata) {
  effPCPBufuLight_Start = 1;
  return 0;
}

// 0x117cc80
effPCPMisc_effPCPBufuLight_t *effPCPBufuLightCreate(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    return 0;
}

// 0x117ce40
void effPCPBufuLightDelete(void **hData) {

}

// 0x117ce80
void effPCPBufuLightDraw(void **hData) {
    effBTLFieldLightDirectionSet((sdfVector4_t){0});
    effBTLFieldLightAxisSet((sdfVector4_t){0});
    effBTLFieldLightAnimationSet(0, 0);
}

// 0x117bed0
effPCPBufudnIce_tag *effPCPBufudnIceCopy(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPartCopy(0);
    SDF_VU0__STOREIDENTITY(0);
    DDS3EFFECT_RAND_PM();
    return 0;
}

// 0x117bc20
effPCPBufudnIce_tag *effPCPBufudnIceCreate(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataPartCreate(0, 0, 0, 0);
    SDF_VU0__STOREIDENTITY(0);
    DDS3EFFECT_RAND_PM();
    return 0;
}

// 0x117c180
void effPCPBufudnIceDelete(void **hData) {
    dds3EffectPartDelete(0);
}

// 0x117c2f0
void effPCPBufudnIceDraw(void **hData) {
    dds3EffectPartSetPosition(0, (sdfVector4_t){0});
    dds3EffectPartSetScale(0, 0);
    dds3EffectPartSetColor(0, 0);
    SetRotateMatrixY(0);
    SDF_VU0__LOADMATRIX_B(0);
    MultMatrixNoArg();
    SDF_VU0__STOREMATRIX(0);
    dds3EffectPartSetRotateMatrix(0, 0);
    dds3EffectPartDraw(0);
}

// 0x117c970
void effPCPBufudnIceSetColor(void **hData, u32 abgr) {
}

// 0x117c840
void effPCPBufudnIceSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x117cb50
void effPCPBufudnIceSetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__STOREMATRIX(0);
}

// 0x117ca60
void effPCPBufudnIceSetScale(void **hData, f32 scale) {
}

// 0x117ae70
effPCPBufuraIce_tag *effPCPBufuraIceCopy(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPartCopy(0);
    SDF_VU0__STOREIDENTITY(0);
    DDS3EFFECT_RAND_PM();
    return 0;
}

// 0x117abc0
effPCPBufuraIce_tag *effPCPBufuraIceCreate(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataPartCreate(0, 0, 0, 0);
    SDF_VU0__STOREIDENTITY(0);
    DDS3EFFECT_RAND_PM();
    return 0;
}

// 0x117b120
void effPCPBufuraIceDelete(void **hData) {
    dds3EffectPartDelete(0);
}

// 0x117b290
void effPCPBufuraIceDraw(void **hData) {
    dds3EffectPartSetPosition(0, (sdfVector4_t){0});
    dds3EffectPartSetScale(0, 0);
    dds3EffectPartSetColor(0, 0);
    SetRotateMatrixY(0);
    SDF_VU0__LOADMATRIX_B(0);
    MultMatrixNoArg();
    SDF_VU0__STOREMATRIX(0);
    dds3EffectPartSetRotateMatrix(0, 0);
    dds3EffectPartDraw(0);
}

// 0x117b910
void effPCPBufuraIceSetColor(void **hData, u32 abgr) {
}

// 0x117b7e0
void effPCPBufuraIceSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x117baf0
void effPCPBufuraIceSetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__STOREMATRIX(0);
}

// 0x117ba00
void effPCPBufuraIceSetScale(void **hData, f32 scale) {
}

// 0x116e7d0
effPCPDistortionBlurExp_tag *effPCPDistortionBlurExpCopy(void **hData, s32 bPos, bool tbldata) {
    effPCPDistortionBlurExpCreate(0);
    return 0;
}

// 0x116e4b0
effPCPDistortionBlurExp_tag *effPCPDistortionBlurExpCreate(effPCPDistortionBlurExpParam_t *pParam) {
  effPCPDistortionBlurExp_tag_o *v3;
  dds3Effect_DistortionBlurParam_t_o *DistBlur;

  v3 = Allocate(effPCPDistortionBlurExp_tag);
  _ctor(v3, 0);
  DistBlur = pParam->DistBlur;
  v3->hDistBlur = dds3EffectDistortionBlurCreate(DistBlur);
  v3->type = pParam->type;
  v3->life = pParam->life;
  v3->fade_in = pParam->fade_in;
  v3->fade_out = pParam->fade_out;
  v3->area_s = pParam->area_s;
  v3->area_e = pParam->area_e;
  v3->frame = 0;
  v3->abgr = -2139062144;
  v3->abgr_base = pParam->DistBlur->abgr;
  return v3;
}

// 0x116e390
effPCPDistortionBlurExp_tag *effPCPDistortionBlurExpCreateP(void **pData, s32 bPos, bool tbldata) {
    effPCPDistortionBlurExpCreate(0);
    return 0;
}

// 0x116e590
effPCPDistortionBlurExp_tag *effPCPDistortionBlurExpCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    effPCPDistortionBlurExpCreate(0);
    return 0;
}

// 0x116e940
void effPCPDistortionBlurExpDelete(void **hData) {
    dds3EffectDistortionBlurDelete(0);
}

// 0x116ea60
void effPCPDistortionBlurExpDraw(void **hData) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    effScreenOffset();
    SDF_VU0__STOREVECTOR(0);
    effColorBlend(0, 0, 0);
    effColorMultiply(0, 0);
    effBTLSkillCheckRun();
    effBTLSkillGetID();
    dds3EffectDistortionBlurDraw(0, 0, 0);
}

// 0x116ef20
void effPCPDistortionBlurExpSetColor(void **hData, u32 abgr) {
}

// 0x116edf0
void effPCPDistortionBlurExpSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x117d160
effPCPEyeThunder_tag *effPCPEyeThunderCopy00_0(void **hData, s32 bPos, bool tbldata) {
  return effPCPEyeThunderCreate00_0(hData, bPos, 1);
}

// 0x117d350
effPCPEyeThunder_tag *effPCPEyeThunderCopy00_1(void **hData, s32 bPos, bool tbldata) {
  return effPCPEyeThunderCreate00_1(hData, bPos, 1);
}

// 0x117d540
effPCPEyeThunder_tag *effPCPEyeThunderCopy01_0(void **hData, s32 bPos, bool tbldata) {
  return effPCPEyeThunderCreate01_0(hData, bPos, 1);
}

// 0x117d730
effPCPEyeThunder_tag *effPCPEyeThunderCopy01_1(void **hData, s32 bPos, bool tbldata) {
  return effPCPEyeThunderCreate01_1(hData, bPos, 1);
}

// 0x117d920
effPCPEyeThunder_tag *effPCPEyeThunderCopy02_0(void **hData, s32 bPos, bool tbldata) {
  return effPCPEyeThunderCreate02_0(hData, bPos, 1);
}

// 0x117db10
effPCPEyeThunder_tag *effPCPEyeThunderCopy02_1(void **hData, s32 bPos, bool tbldata) {
  return effPCPEyeThunderCreate02_1(hData, bPos, 1);
}

// 0x117dd00
effPCPEyeThunder_tag *effPCPEyeThunderCopy03_0(void **hData, s32 bPos, bool tbldata) {
  return effPCPEyeThunderCreate03_0(hData, bPos, 1);
}

// 0x117def0
effPCPEyeThunder_tag *effPCPEyeThunderCopy03_1(void **hData, s32 bPos, bool tbldata) {
  return effPCPEyeThunderCreate03_1(hData, bPos, 1);
}

// 0x117e0e0
effPCPEyeThunder_tag *effPCPEyeThunderCopy04_0(void **hData, s32 bPos, bool tbldata) {
  return effPCPEyeThunderCreate04_0(hData, bPos, 1);
}

// 0x117e380
effPCPEyeThunder_tag *effPCPEyeThunderCopy04_1(void **hData, s32 bPos, bool tbldata) {
  return effPCPEyeThunderCreate04_1(hData, 0, 1);
}

// 0x117e570
effPCPEyeThunder_tag *effPCPEyeThunderCopy05_0(void **hData, s32 bPos, bool tbldata) {
  return effPCPEyeThunderCreate05_0(hData, bPos, 1);
}

// 0x117e760
effPCPEyeThunder_tag *effPCPEyeThunderCopy05_1(void **hData, s32 bPos, bool tbldata) {
  return effPCPEyeThunderCreate05_1(hData, bPos, 1);
}

// 0x117cfe0
effPCPEyeThunder_tag *effPCPEyeThunderCreate00_0(void **hData, s32 bPos, bool tbldata) {
    effPCP_ThunderPolyCreate(0, 0, 0);
    return 0;
}

// 0x117d1d0
effPCPEyeThunder_tag *effPCPEyeThunderCreate00_1(void **hData, s32 bPos, bool tbldata) {
    effPCP_ThunderPolyCreate(0, 0, 0);
    return 0;
}

// 0x117d3c0
effPCPEyeThunder_tag *effPCPEyeThunderCreate01_0(void **hData, s32 bPos, bool tbldata) {
    effPCP_ThunderPolyCreate(0, 0, 0);
    return 0;
}

// 0x117d5b0
effPCPEyeThunder_tag *effPCPEyeThunderCreate01_1(void **hData, s32 bPos, bool tbldata) {
    effPCP_ThunderPolyCreate(0, 0, 0);
    return 0;
}

// 0x117d7a0
effPCPEyeThunder_tag *effPCPEyeThunderCreate02_0(void **hData, s32 bPos, bool tbldata) {
    effPCP_ThunderPolyCreate(0, 0, 0);
    return 0;
}

// 0x117d990
effPCPEyeThunder_tag *effPCPEyeThunderCreate02_1(void **hData, s32 bPos, bool tbldata) {
    effPCP_ThunderPolyCreate(0, 0, 0);
    return 0;
}

// 0x117db80
effPCPEyeThunder_tag *effPCPEyeThunderCreate03_0(void **hData, s32 bPos, bool tbldata) {
    effPCP_ThunderPolyCreate(0, 0, 0);
    return 0;
}

// 0x117dd70
effPCPEyeThunder_tag *effPCPEyeThunderCreate03_1(void **hData, s32 bPos, bool tbldata) {
    effPCP_ThunderPolyCreate(0, 0, 0);
    return 0;
}

// 0x117df60
effPCPEyeThunder_tag *effPCPEyeThunderCreate04_0(void **hData, s32 bPos, bool tbldata) {
    effPCP_ThunderPolyCreate(0, 0, 0);
    return 0;
}

// 0x117e150
effPCPEyeThunder_tag *effPCPEyeThunderCreate04_1(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    effPCP_ThunderPolyCreate(0, 0, 0);
    return 0;
}

// 0x117e3f0
effPCPEyeThunder_tag *effPCPEyeThunderCreate05_0(void **hData, s32 bPos, bool tbldata) {
    effPCP_ThunderPolyCreate(0, 0, 0);
    return 0;
}

// 0x117e5e0
effPCPEyeThunder_tag *effPCPEyeThunderCreate05_1(void **hData, s32 bPos, bool tbldata) {
    effPCP_ThunderPolyCreate(0, 0, 0);
    return 0;
}

// 0x117e7d0
void effPCPEyeThunderDelete(void **hData) {
    effPCP_ThunderPolyDelete(0);
}

// 0x117e8d0
void effPCPEyeThunderDraw(void **hData) {
    effBTLSkillCheckRun();
    effBTLSkillGetTargetFormation(0);
    effBTLModelGetSphereCenter(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    effPCP_ThunderPolyGetParam(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    effPCP_ThunderPolySetColor(0, 0);
    effPCP_ThunderPolyDraw(0);
}

// 0x117ee00
void effPCPEyeThunderSetColor(void **hData, u32 abgr) {
}

// 0x117ecd0
void effPCPEyeThunderSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x118dd20
effPCPFLEACHBlur_tag *effPCPFLEACHBlurCopy(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPartialMultiBlurCreate(0);
    return 0;
}

// 0x118d9b0
effPCPFLEACHBlur_tag *effPCPFLEACHBlurCreate(effPCPFLEACHBlurParam_t *pFLEACHBlurParam) {
  u64 *v3;
  dds3Effect_PartialMultiBlurParam_t_o *start;

  v3 = Allocate(effPCPFLEACHBlur_tag);
  _ctor(v3, 0);
  v3[4] = 0x8080808000000000LL;
  v3[2] = pFLEACHBlurParam;
  v3[3] = 0;
  start = pFLEACHBlurParam->start;
  v3[3] = dds3EffectPartialMultiBlurCreate(start);
  return v3;
}

// 0x118d810
effPCPFLEACHBlur_tag *effPCPFLEACHBlurCreateP(void **pData, s32 bPos, bool tbldata) {
    dds3EffectPartialMultiBlurCreate(0);
    return 0;
}

// 0x118da60
effPCPFLEACHBlur_tag *effPCPFLEACHBlurCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    dds3EffectPartialMultiBlurCreate(0);
    return 0;
}

// 0x118dec0
void effPCPFLEACHBlurDelete(void **hData) {
    dds3EffectPartialMultiBlurDelete(0);
}

// 0x118dfe0
void effPCPFLEACHBlurDraw(void **hData) {
    dds3Effect_PartialMultiBlurParam_t__Clear(0);
    effColorBlend(0, 0, 0);
    effColorMultiply(0, 0);
    dds3EffectPartialMultiBlurSetParam(0, 0);
    dds3EffectPartialMultiBlurDraw(0, 0, 0);
}

// 0x118e460
void effPCPFLEACHBlurSetColor(void **hData, u32 abgr) {
}

// 0x116d280
effPCPFilterExp_tag *effPCPFilterExpCopy(void **hData, s32 bPos, bool tbldata) {
    return 0;
}

// 0x116cf60
effPCPFilterExp_tag *effPCPFilterExpCreate(effPCPFilterExpParam_t *pParam) {
  effPCPFilterExp_tag_o *v3;

  v3 = Allocate(effPCPFilterExp_tag);
  _ctor(v3, 0);
  v3->param = pParam;
  v3->frame = 0;
  v3->abgr = -2139062144;
  v3->abgr_base = pParam->Filter->abgr;
  return v3;
}

// 0x116cdf0
effPCPFilterExp_tag *effPCPFilterExpCreateP(void **pData, s32 bPos, bool tbldata) {
    return 0;
}

// 0x116cfe0
effPCPFilterExp_tag *effPCPFilterExpCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    return 0;
}

// 0x116d400
void effPCPFilterExpDelete(void **hData) {

}

// 0x116d440
void effPCPFilterExpDraw(void **hData) {
    effColorBlend(0, 0, 0);
    effColorMultiply(0, 0);
    effBTLSkillCheckRun();
    effBTLSkillGetID();
    dds3EffectFilter(0);
}

// 0x116d7a0
void effPCPFilterExpSetColor(void **hData, u32 abgr) {
}

// 0x1159a10
effPCPHama01_tag *effPCPHama01Copy(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPartCopy(0);
    effPCPHama01PartInit(0, 0);
    return 0;
}

// 0x1158f30
effPCPHama01_tag *effPCPHama01Create(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataPartCreate(0, 0, 0, 0);
    dds3EffectPartCopy(0);
    effPCPHama01PartInit(0, 0);
    return 0;
}

// 0x1159800
void effPCPHama01Delete(void **hData) {
    dds3EffectPartDelete(0);
}

// 0x1159ef0
void effPCPHama01Draw(void **hData) {
    dds3EffectPartGetHandle(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    mdlSetPosition(0);
    dds3EffectPartSetScale(0, 0);
    mdlSetColor(0, 0);
    dds3EffectPartModelDraw(0);
    sdfModelGetMarkPosUnity(0, 0);
    SDF_VU0__STOREVECTOR(0);
    dds3EffectPartSetPosition(0, (sdfVector4_t){0});
    dds3EffectPartDraw(0);
}

// 0x1158a90
void effPCPHama01PartInit(effPCPHama01_tag **pPCPHama01, u32 number) {
    DDS3EFFECT_RAND_PM();
    SetRotateMatrixY(0);
    SDF_VU0__STOREMATRIX(0);
    dds3EffectPartSetRotateMatrix(0, 0);
    dds3EffectPartGetHandle(0);
    DDS3EFFECT_RAND_I();
}

// 0x115a990
void effPCPHama01SetColor(void **hData, u32 abgr) {
}

// 0x115a770
void effPCPHama01SetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x115a8a0
void effPCPHama01SetScale(void **hData, f32 scale) {
}

// 0x115b610
effPCPHama02_tag *effPCPHama02Copy(void **hData, s32 bPos, bool tbldata) {
    Clear(0);
    dds3EffectPartCopy(0);
    effPCPHama02PartInit(0, 0);
    return 0;
}

// 0x115af60
effPCPHama02_tag *effPCPHama02Create(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    Clear(0);
    dds3EffectPartCopy(0);
    dds3EffectPCPDataPartCreate(0, 0, 0, 0);
    effPCPHama02PartInit(0, 0);
    return 0;
}

// 0x115b440
void effPCPHama02Delete(void **hData) {
    dds3EffectPartDelete(0);
}

// 0x115b9c0
void effPCPHama02Draw(void **hData) {
    dds3EffectPartGetHandle(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    mdlSetPosition(0);
    dds3EffectPartSetScale(0, 0);
    mdlSetColor(0, 0);
    dds3EffectPartModelDraw(0);
    sdfModelGetMarkPosUnity(0, 0);
}

// 0x115aa80
void effPCPHama02PartInit(effPCPHama02_tag **pPCPHama02, u32 number) {
    DDS3EFFECT_RAND_PM();
    SetRotateMatrixY(0);
    SDF_VU0__STOREMATRIX(0);
    dds3EffectPartSetRotateMatrix(0, 0);
    dds3EffectPartGetHandle(0);
    DDS3EFFECT_RAND_F();
    DDS3EFFECT_RAND_I();
}

// 0x115c430
void effPCPHama02SetColor(void **hData, u32 abgr) {
}

// 0x115c210
void effPCPHama02SetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x115c340
void effPCPHama02SetScale(void **hData, f32 scale) {
}

// 0x115d070
effPCPHamaon_tag *effPCPHamaonCopy(void **hData, s32 bPos, bool tbldata) {
    Clear(0);
    dds3EffectPartCopy(0);
    dds3EffectPartGetHandle(0);
    effPCPHamaonPartInit(0, 0, 0);
    return 0;
}

// 0x115c910
effPCPHamaon_tag *effPCPHamaonCreate(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    Clear(0);
    dds3EffectPCPDataPartCreate(0, 0, 0, 0);
    dds3EffectPartGetHandle(0);
    dds3EffectPartCopy(0);
    effPCPHamaonPartInit(0, 0, 0);
    return 0;
}

// 0x115cdd0
void effPCPHamaonDelete(void **hData) {
    dds3EffectPartDelete(0);
}

// 0x115d690
void effPCPHamaonDraw(void **hData) {
    dds3EffectPartGetHandle(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    mdlSetPosition(0);
    dds3EffectPartSetScale(0, 0);
    dds3EffectPartModelDraw(0);
    mdlSetColor(0, 0);
    sdfModelGetMarkPosUnity(0, 0);
}

// 0x115c520
void effPCPHamaonPartInit(effPCPHamaon_tag **pPCPHamaon, u32 kind, u32 attach) {
    dds3EffectPartGetHandle(0);
    SetRotateMatrixY(0);
    SetRotateMatrixZ(0);
    SDF_VU0__STOREMATRIX(0);
    dds3EffectPartSetRotateMatrix(0, 0);
}

// 0x115ddb0
void effPCPHamaonSetColor(void **hData, u32 abgr) {
}

// 0x115db90
void effPCPHamaonSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x115dcc0
void effPCPHamaonSetScale(void **hData, f32 scale) {
}

// 0x118bb70
effPCPHelperBED_tag *effPCPHelperBEDCopy(void **hData, s32 bPos, bool tbldata) {
    effPCPHelperBEDCreate(0, 0, 0);
    dds3EffectPartCopy(0);
    effPCPHelperInit(0);
    return 0;
}

// 0x118b6b0
effPCPHelperBED_tag *effPCPHelperBEDCreate(effPCPHelperBEDParam_t *pParam, void *pPBData, void *pBEDData) {
    effPCPHelperBEDParam_t__pClone(0, 0);
    dds3EffectPartCreate(0, 0);
    effEveBEDCreate(0);
    effPCPHelperInit(0);
    return 0;
}

// 0x118b8b0
effPCPHelperBED_tag *effPCPHelperBEDCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    GetEffPCPpBEDData(0, 0);
    effPCPHelperBEDCreate(0, 0, 0);
    return 0;
}

// 0x118bcf0
void effPCPHelperBEDDelete(void **hData) {
    dds3EffectPartDelete(0);
    effEveBEDCutDelete(0);
    effEveBEDDelete(0);
}

// 0x118bed0
void effPCPHelperBEDDraw(void **hData) {
    dds3EffectPartGetHandle(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    mdlSetPosition(0);
    mdlSetScale(0);
    dds3EffectPartModelDraw(0);
    effEveBEDCutSetScale(0, 0);
    sdfModelGetMarkPosUnity(0, 0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    effColorBlend(0, 0, 0);
    effEveBEDCutSetParams(0, 0);
    effEveBEDCutDraw(0);
}

// 0x118c920
dds3ModelHandle_t *effPCPHelperBEDGetModel(effPCPHelperBED_tag *pHelperBED) {
    dds3EffectPartGetHandle(0);
    return 0;
}

// 0x118c830
void effPCPHelperBEDSetColor(void **hData, u32 abgr) {
}

// 0x118c620
void effPCPHelperBEDSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x118c740
void effPCPHelperBEDSetScale(void **hData, f32 scale) {
}

// 0x118b1b0
void effPCPHelperInit(effPCPHelperBED_tag **pHelperBED) {
    dds3EffectPartGetHandle(0);
    dds3EffectPartModelDraw(0);
    mdlGetMotionLengthUnity(0);
    sdfModelGetMarkPosCountUnity(0);
    dds3EffectPartModelDelete(0);
    effEveBEDCutCreate(0, 0, 0);
}

// 0x11698f0
effPCPHouden01_tag *effPCPHouden01Copy(void **hData, s32 bPos, bool tbldata) {
  u64 *v4;
  Il2CppObject *hDataa;

  v4 = Allocate(effPCPHouden01_tag);
  _ctor(v4, 0);
  hDataa = 0;
  hDataa = effPCP_Houden01_ThunderSpherePoly_Param;
  v4[6] = effPCPThunderSpherePolyCreate(&hDataa, 0, 0);
  *(v4 + 10) = 0;
  return v4;
}

// 0x1169620
effPCPHouden01_tag *effPCPHouden01Create(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    effPCPThunderSpherePolyCreate(0, 0, 0);
    return 0;
}

// 0x11697f0
void effPCPHouden01Delete(void **hData) {
    effPCPThunderSpherePolyDelete(0);
}

// 0x11699f0
void effPCPHouden01Draw(void **hData) {
    effColorBlend(0, 0, 0);
    effPCPThunderSpherePolySetColor(0, 0);
    effPCPThunderSpherePolySetPosition(0, (sdfVector4_t){0});
    effPCPThunderSpherePolyDraw(0);
    effPCPThunderSpherePolyGetParam(0);
}

// 0x1169580
void effPCPHouden01Init(effPCPHouden01_tag **pPCPHouden01) {
  effPCPHouden01_tag_o *v4;
  Il2CppObject *hData;

  hData = 0;
  hData = effPCP_Houden01_ThunderSpherePoly_Param;
  v4 = *pPCPHouden01;
  v4->pThunderPoly = effPCPThunderSpherePolyCreate(&hData, 0, 0);
  (*pPCPHouden01)->frame = 0;
}

// 0x1169df0
void effPCPHouden01SetColor(void **hData, u32 abgr) {
}

// 0x1169bd0
void effPCPHouden01SetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1169d00
void effPCPHouden01SetScale(void **hData, f32 scale) {
}

// 0x1160a50
effPCPHwave01_tag *effPCPHwave01Copy(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPartCopy(0);
    return 0;
}

// 0x1160730
effPCPHwave01_tag *effPCPHwave01Create(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataPartCreate(0, 0, 0, 0);
    return 0;
}

// 0x1160920
void effPCPHwave01Delete(void **hData) {
    dds3EffectPartDelete(0);
}

// 0x1160c00
void effPCPHwave01Draw(void **hData) {
    dds3EffectPartGetHandle(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    mdlSetPosition(0);
    dds3EffectPartSetColor(0, 0);
    dds3EffectPartModelDraw(0);
    sdfModelGetMarkPosUnity(0, 0);
    SDF_VU0__STOREVECTOR(0);
    dds3EffectPartSetPosition(0, (sdfVector4_t){0});
    dds3EffectPartDraw(0);
}

// 0x1160ff0
void effPCPHwave01SetColor(void **hData, u32 abgr) {
}

// 0x1160ec0
void effPCPHwave01SetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x115e7e0
effPCPMHanma01_tag *effPCPMHanma01Copy(void **hData, s32 bPos, bool tbldata) {
    Clear(0);
    dds3EffectPartCopy(0);
    effPCPMHanma01PartInit(0, 0);
    return 0;
}

// 0x115e1a0
effPCPMHanma01_tag *effPCPMHanma01Create(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    Clear(0);
    dds3EffectPCPDataPartCreate(0, 0, 0, 0);
    dds3EffectPartCopy(0);
    effPCPMHanma01PartInit(0, 0);
    return 0;
}

// 0x115e610
void effPCPMHanma01Delete(void **hData) {
    dds3EffectPartDelete(0);
}

// 0x115eb80
void effPCPMHanma01Draw(void **hData) {
    dds3EffectPartGetHandle(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    mdlSetPosition(0);
    mdlSetColor(0, 0);
    dds3EffectPartModelDraw(0);
    sdfModelGetMarkPosUnity(0, 0);
    SDF_VU0__STOREVECTOR(0);
}

// 0x115dea0
void effPCPMHanma01PartInit(effPCPMHanma01_tag **pPCPMHanma01, s32 number) {
    dds3EffectPartGetHandle(0);
    DDS3EFFECT_RAND_I();
}

// 0x115f490
void effPCPMHanma01SetColor(void **hData, u32 abgr) {
}

// 0x115f270
void effPCPMHanma01SetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x115f3a0
void effPCPMHanma01SetScale(void **hData, f32 scale) {
}

// 0x1166350
effPCPMZiodin01_tag *effPCPMZiodin01Copy(void **hData, s32 bPos, bool tbldata) {
  u64 *v4;
  effPCPMZiodin01_tag_o *pPCPMZiodin01;

  v4 = Allocate(effPCPMZiodin01_tag);
  _ctor(v4, 0);
  pPCPMZiodin01 = v4;
  effPCPMZiodin01Init(&pPCPMZiodin01);
  return v4;
}

// 0x1165e70
effPCPMZiodin01_tag *effPCPMZiodin01Create(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    effPCPMZiodin01Init(0);
    return 0;
}

// 0x1165fe0
void effPCPMZiodin01Delete(void **hData) {
    effPCP_ThunderPolyDelete(0);
}

// 0x11663e0
void effPCPMZiodin01Draw(void **hData) {
    effPCP_ThunderPolyGetParam(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    effPCP_ThunderPolyDraw(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1165a40
void effPCPMZiodin01Init(effPCPMZiodin01_tag **pPCPMZiodin01) {
    DDS3EFFECT_RAND_I();
    DDS3EFFECT_RAND_PM();
    DDS3EFFECT_RAND_F();
    DDS3EFFECT_RAND_FA(0);
    sdfCos(0);
    sdfSin(0);
    effPCP_ThunderPolyCreate(0, 0, 0);
}

// 0x11669a0
void effPCPMZiodin01SetColor(void **hData, u32 abgr) {
}

// 0x1166780
void effPCPMZiodin01SetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x11668b0
void effPCPMZiodin01SetScale(void **hData, f32 scale) {
}

// 0x11673c0
effPCPMZiodin02_tag *effPCPMZiodin02Copy(void **hData, s32 bPos, bool tbldata) {
  u64 *v4;
  effPCPMZiodin02_tag_o *pPCPMZiodin02;

  v4 = Allocate(effPCPMZiodin02_tag);
  _ctor(v4, 0);
  pPCPMZiodin02 = v4;
  effPCPMZiodin02Init(&pPCPMZiodin02);
  return v4;
}

// 0x1166fc0
effPCPMZiodin02_tag *effPCPMZiodin02Create(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    effPCPMZiodin02Init(0);
    return 0;
}

// 0x1167130
void effPCPMZiodin02Delete(void **hData) {
    effPCP_ThunderPolyDelete(0);
}

// 0x1167450
void effPCPMZiodin02Draw(void **hData) {
    effPCP_ThunderPolyGetParam(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    effPCP_ThunderPolyDraw(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1166a90
void effPCPMZiodin02Init(effPCPMZiodin02_tag **pPCPMZiodin02) {
    DDS3EFFECT_RAND_I();
    DDS3EFFECT_RAND_F();
    DDS3EFFECT_RAND_PM();
    SetRotateMatrixX(0);
    SetRotateMatrixZ_B(0);
    MultMatrixRevNoArg();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX_XYZ();
    SDF_VU0__STOREVECTOR(0);
    effPCP_ThunderPolyCreate(0, 0, 0);
}

// 0x1167a10
void effPCPMZiodin02SetColor(void **hData, u32 abgr) {
}

// 0x11677f0
void effPCPMZiodin02SetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1167920
void effPCPMZiodin02SetScale(void **hData, f32 scale) {
}

// 0x1185730
effPCPMakka_tag *effPCPMakkaCopy(void **hData, s32 bPos, bool tbldata) {
    DDS3EFFECT_RAND_PM();
    dds3EffectPartCopy(0);
    return 0;
}

// 0x11853f0
effPCPMakka_tag *effPCPMakkaCreat(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    DDS3EFFECT_RAND_PM();
    dds3EffectPCPDataPartCreate(0, 0, 0, 0);
    return 0;
}

// 0x1185a70
void effPCPMakkaDelete(void **hData) {
    dds3EffectPartDelete(0);
}

// 0x1185c20
void effPCPMakkaDraw(void **hData) {
    effBTLSkillGetTargetFormation(0);
    dds3EffectPartCopy(0);
    dds3EffectPartGetHandle(0);
    FromEuler(0, 0, 0);
    effBTLSkillCheckRun();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    Mult();
    mdlSetRotate(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    mdlSetScale(0);
    mdlSetColor(0, 0);
    mdlSetPosition(0);
    dds3EffectPartModelDraw(0);
}

// 0x1186570
void effPCPMakkaSetColor(void **hData, u32 abgr) {
}

// 0x1186440
void effPCPMakkaSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1186660
void effPCPMakkaSetScale(void **hData, f32 scale) {
}

// 0x116fff0
effPCPMegidora01_tag *effPCPMegidora01Copy(void **hData, s32 bPos, bool tbldata) {
  u64 *v4;
  Il2CppObject *hDataa;

  v4 = Allocate(effPCPMegidora01_tag);
  _ctor(v4, 0);
  hDataa = 0;
  hDataa = effPCP_Megidora01_ThunderSpherePoly_Param;
  v4[6] = effPCPThunderSpherePolyCreate(&hDataa, 0, 0);
  *(v4 + 10) = 0;
  return v4;
}

// 0x116fd20
effPCPMegidora01_tag *effPCPMegidora01Create(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    effPCPThunderSpherePolyCreate(0, 0, 0);
    return 0;
}

// 0x116fef0
void effPCPMegidora01Delete(void **hData) {
    effPCPThunderSpherePolyDelete(0);
}

// 0x11700f0
void effPCPMegidora01Draw(void **hData) {
    effPCPThunderSpherePolyGetParam(0);
    effColorBlend(0, 0, 0);
    effPCPThunderSpherePolySetColor(0, 0);
    effPCPThunderSpherePolySetPosition(0, (sdfVector4_t){0});
    effPCPThunderSpherePolyDraw(0);
}

// 0x116fc80
void effPCPMegidora01Init(effPCPMegidora01_tag **pPCPMegidora01) {
  effPCPMegidora01_tag_o *v4;
  Il2CppObject *hData;

  hData = 0;
  hData = effPCP_Megidora01_ThunderSpherePoly_Param;
  v4 = *pPCPMegidora01;
  v4->pThunderPoly = effPCPThunderSpherePolyCreate(&hData, 0, 0);
  (*pPCPMegidora01)->frame = 0;
}

// 0x1170500
void effPCPMegidora01SetColor(void **hData, u32 abgr) {
}

// 0x11702e0
void effPCPMegidora01SetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1170410
void effPCPMegidora01SetScale(void **hData, f32 scale) {
}

// 0x1170960
effPCPMegidoraon01_tag *effPCPMegidoraon01Copy(void **hData, s32 bPos, bool tbldata) {
  u64 *v4;
  Il2CppObject *hDataa;

  v4 = Allocate(effPCPMegidoraon01_tag);
  _ctor(v4, 0);
  hDataa = 0;
  hDataa = effPCP_Megidoraon01_ThunderSpherePoly_Param;
  v4[6] = effPCPThunderSpherePolyCreate(&hDataa, 0, 0);
  *(v4 + 10) = 0;
  return v4;
}

// 0x1170690
effPCPMegidoraon01_tag *effPCPMegidoraon01Create(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    effPCPThunderSpherePolyCreate(0, 0, 0);
    return 0;
}

// 0x1170860
void effPCPMegidoraon01Delete(void **hData) {
    effPCPThunderSpherePolyDelete(0);
}

// 0x1170a60
void effPCPMegidoraon01Draw(void **hData) {
    effPCPThunderSpherePolyGetParam(0);
    effColorBlend(0, 0, 0);
    effPCPThunderSpherePolySetColor(0, 0);
    effPCPThunderSpherePolySetPosition(0, (sdfVector4_t){0});
    effPCPThunderSpherePolyDraw(0);
}

// 0x11705f0
void effPCPMegidoraon01Init(effPCPMegidoraon01_tag **pPCPMegidoraon01) {
  effPCPMegidoraon01_tag_o *v4;
  Il2CppObject *hData;

  hData = 0;
  hData = effPCP_Megidoraon01_ThunderSpherePoly_Param;
  v4 = *pPCPMegidoraon01;
  v4->pThunderPoly = effPCPThunderSpherePolyCreate(&hData, 0, 0);
  (*pPCPMegidoraon01)->frame = 0;
}

// 0x1170e70
void effPCPMegidoraon01SetColor(void **hData, u32 abgr) {
}

// 0x1170c50
void effPCPMegidoraon01SetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1170d80
void effPCPMegidoraon01SetScale(void **hData, f32 scale) {
}

// 0x115f910
effPCPMudo_tag *effPCPMudoCopy(void **hData, s32 bPos, bool tbldata) {
    Clear(0);
    dds3EffectPartCopy(0);
    return 0;
}

// 0x115f5a0
effPCPMudo_tag *effPCPMudoCreate(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    Clear(0);
    dds3EffectPCPDataPartCreate(0, 0, 0, 0);
    return 0;
}

// 0x115f7e0
void effPCPMudoDelete(void **hData) {
    dds3EffectPartDelete(0);
}

// 0x115fb10
void effPCPMudoDraw(void **hData) {
    effColorMultiply(0, 0);
    dds3EffectPartGetHandle(0);
    dds3EffectPartSetScale(0, 0);
    dds3EffectPartSetPosition(0, (sdfVector4_t){0});
    dds3EffectPartModelDraw(0);
    sdfModelGetMarkPosUnity(0, 0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    DDS3EFFECT_RAND_I();
    dds3BillboardSetRGBA(0, 0);
    dds3BillboardSetScale(0, 0, 0);
    dds3BillboardSetPosition(0, (sdfVector4_t){0});
    dds3BillboardDraw(0);
    dds3BillboardSetAnimKey(0, 0);
}

// 0x115f580
void effPCPMudoPartInit(effPCPMudo_tag **pPCPMudo) {
  (*pPCPMudo)->frame = 0;
  (*pPCPMudo)->fade_frame = 0;
  (*pPCPMudo)->fade_abgr = -2139062144;
}

// 0x1160640
void effPCPMudoSetColor(void **hData, u32 abgr) {
}

// 0x1160420
void effPCPMudoSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1160550
void effPCPMudoSetScale(void **hData, f32 scale) {
}

// 0x116c4b0
effPCPMultiBlurExp2_tag *effPCPMultiBlurExp2Copy(void **hData, s32 bPos, bool tbldata) {
    effPCPMultiBlurExp2Create(0);
    return 0;
}

// 0x116c180
effPCPMultiBlurExp2_tag *effPCPMultiBlurExp2Create(effPCPMultiBlurExp2Param_t *pParam) {
  effPCPMultiBlurExp2_tag_o *v3;
  dds3Effect_PartialMultiBlurParam_t_o *MultiBlur;

  v3 = Allocate(effPCPMultiBlurExp2_tag);
  _ctor(v3, 0);
  MultiBlur = pParam->MultiBlur;
  v3->hBlur = dds3EffectPartialMultiBlurCreate(MultiBlur);
  v3->frame = 0;
  v3->abgr = -2139062144;
  v3->type = pParam->type;
  v3->life = pParam->life;
  v3->fade_in = pParam->fade_in;
  v3->fade_out = pParam->fade_out;
  v3->area_s = pParam->area_s;
  v3->area_e = pParam->area_e;
  v3->abgr_base = pParam->MultiBlur->Blur->abgr;
  return v3;
}

// 0x116c060
effPCPMultiBlurExp2_tag *effPCPMultiBlurExp2CreateP(void **pData, s32 bPos, bool tbldata) {
    effPCPMultiBlurExp2Create(0);
    return 0;
}

// 0x116c270
effPCPMultiBlurExp2_tag *effPCPMultiBlurExp2CreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    effPCPMultiBlurExp2Create(0);
    return 0;
}

// 0x116c620
void effPCPMultiBlurExp2Delete(void **hData) {
    dds3EffectPartialMultiBlurDelete(0);
}

// 0x116c740
void effPCPMultiBlurExp2Draw(void **hData) {
    dds3Effect_PartialMultiBlur_t__Clear(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    effScreenOffset();
    SDF_VU0__STOREVECTOR(0);
    effColorBlend(0, 0, 0);
    effColorMultiply(0, 0);
    effBTLSkillCheckRun();
    effBTLSkillGetID();
    dds3EffectPartialMultiBlurDraw(0, 0, 0);
}

// 0x116cd00
void effPCPMultiBlurExp2SetArea(void **hData, f32 area) {
}

// 0x116cc10
void effPCPMultiBlurExp2SetColor(void **hData, u32 abgr) {
}

// 0x116cae0
void effPCPMultiBlurExp2SetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x116aa10
effPCPMultiBlurExp_tag *effPCPMultiBlurExpCreate(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPartialMultiBlurCreate(0);
    return 0;
}

// 0x116ac80
void effPCPMultiBlurExpDelete(void **hData) {
    dds3EffectPartialMultiBlurDelete(0);
}

// 0x116ada0
void effPCPMultiBlurExpDraw(void **hData) {
    dds3Effect_PartialMultiBlur_t__Clear(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    effScreenArea(0);
    SDF_VU0__STOREVECTOR(0);
    effColorMultiply(0, 0);
    effBTLSkillCheckRun();
    effBTLSkillGetID();
    dds3EffectPartialMultiBlurDraw(0, 0, 0);
}

// 0x116b2f0
void effPCPMultiBlurExpSetArea(void **hData, f32 area) {
}

// 0x116b200
void effPCPMultiBlurExpSetColor(void **hData, u32 abgr) {
}

// 0x116b0d0
void effPCPMultiBlurExpSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x116b7b0
effPCPMultiFilterExp_tag *effPCPMultiFilterExpCopy(void **hData, s32 bPos, bool tbldata) {
    effPCPMultiFilterExpCreate(0, 0, 0);
    return 0;
}

// 0x116b3e0
effPCPMultiFilterExp_tag *effPCPMultiFilterExpCreate(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPartialMultiFilterCreate(0);
    return 0;
}

// 0x116b570
effPCPMultiFilterExp_tag *effPCPMultiFilterExpCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    effPCPMultiFilterExpCreate(0, 0, 0);
    return 0;
}

// 0x116b930
void effPCPMultiFilterExpDelete(void **hData) {
    dds3EffectPartialMultiFilterDelete(0);
}

// 0x116ba40
void effPCPMultiFilterExpDraw(void **hData) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    effScreenOffset();
    SDF_VU0__STOREVECTOR(0);
    effColorBlend(0, 0, 0);
    effColorMultiply(0, 0);
    dds3EffectPartialMultiFilterDraw(0);
}

// 0x116bf70
void effPCPMultiFilterExpSetArea(void **hData, f32 area) {
}

// 0x116be80
void effPCPMultiFilterExpSetColor(void **hData, u32 abgr) {
}

// 0x116bd50
void effPCPMultiFilterExpSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1186f60
effPCPRadiateBED_tag *effPCPRadiateBEDCopy(void **hData, s32 bPos, bool tbldata) {
    effEveBEDParams_t__Clear(0);
    effEveBEDCutCreate(0, 0, 0);
    DDS3EFFECT_RAND_I();
    return 0;
}

// 0x1186750
effPCPRadiateBED_tag *effPCPRadiateBEDCreate(effPCPRadiateBEDParam_t *pParam, void *pBEDData) {
    effEveBEDCreate(0);
    effEveBEDCutCreate(0, 0, 0);
    DDS3EFFECT_RAND_I();
    return 0;
}

// 0x1186b70
effPCPRadiateBED_tag *effPCPRadiateBEDCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    GetEffPCPpBEDData(0, 0);
    effPCPRadiateBEDCreate(0, 0);
    return 0;
}

// 0x1187360
void effPCPRadiateBEDDelete(void **hData) {
    effEveBEDCutDelete(0);
    effEveBEDDelete(0);
}

// 0x1187680
void effPCPRadiateBEDDraw(void **hData) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    effPCPRadiateBEDPartInit(0, 0);
    sdfCos(0);
    sdfSin(0);
    effColorBlend(0, 0, 0);
    effEveBEDCutSetParams(0, 0);
    effEveBEDCutDraw(0);
}

// 0x1187510
void effPCPRadiateBEDPartInit(effPCPRadiateBED_tag **pRadiateBED, s32 index) {
  effPCPRadiateBED_tag_o *v5;
  struct effPCPRadiateBEDPart_tag_array *pPart;
  f32 scale;
  struct effPCPRadiateBEDParam_t_o *param;
  f32 *v10;
  f32 radius_s_r;
  f32 radius_s;
  struct effPCPRadiateBEDParam_t_o *v13;
  f32 radius_e;
  u64 v15;
  struct effPCPRadiateBEDParam_t_o *v16;
  f32 radian_s;

  v5 = *pRadiateBED;
  pPart = (*pRadiateBED)->pPart;
  scale = v5->scale;
  param = v5->param;
  v10 = pPart->m_Items[index];
  radius_s_r = param->radius_s_r;
  radius_s = param->radius_s;
  v10[7] = scale * (radius_s * DDS3EFFECT_RAND_FA(radius_s_r));
  v13 = (*pRadiateBED)->param;
  radius_e = v13->radius_e;
  v10[8] = ((scale * (radius_e * DDS3EFFECT_RAND_FA(v13->radius_e_r))) - v10[7])
         / v13->life;
  LODWORD(v15) = (*pRadiateBED)->param->number;
  *&v15 = v15;
  v10[9] = (6.2832 / *&v15) * index;
  v16 = (*pRadiateBED)->param;
  radian_s = v16->radian_s;
  v10[10] = radian_s * DDS3EFFECT_RAND_FA(v16->radian_r);
}

// 0x1187ca0
void effPCPRadiateBEDSetColor(void **hData, u32 abgr) {
}

// 0x1187a90
void effPCPRadiateBEDSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1187bb0
void effPCPRadiateBEDSetScale(void **hData, f32 scale) {
}

// 0x1188710
effPCPRadiateTB_tag *effPCPRadiateTBCopy(void **hData, s32 bPos, bool tbldata) {
    effPCP_ThunderPolyCreate(0, 0, 0);
    effEveBEDCutCreate(0, 0, 0);
    DDS3EFFECT_RAND_I();
    return 0;
}

// 0x1187d90
effPCPRadiateTB_tag *effPCPRadiateTBCreate(effPCPRadiateTBParam_t *pParam, void *pBEDData0, void *pBEDData1) {
    effEveBEDCreate(0);
    effPCP_ThunderPolyCreate(0, 0, 0);
    effEveBEDCutCreate(0, 0, 0);
    DDS3EFFECT_RAND_I();
    return 0;
}

// 0x1188450
effPCPRadiateTB_tag *effPCPRadiateTBCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    GetEffPCPpBEDData(0, 0);
    effPCPRadiateTBCreate(0, 0, 0);
    return 0;
}

// 0x1188d40
void effPCPRadiateTBDelete(void **hData) {
    effEveBEDCutDelete(0);
    effPCP_ThunderPolyDelete(0);
    effEveBEDDelete(0);
}

// 0x11891f0
void effPCPRadiateTBDraw(void **hData) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    effPCPRadiateTBPartInit(0, 0);
    effPCP_ThunderPolyGetParam(0);
    SetRotateMatrixAxis(0, (sdfVector4_t){0});
    SDF_VU0__OUTERPRODUCT();
    SDF_VU0__APPLYMATRIX_XYZ();
    effColorBlend(0, 0, 0);
    effPCP_ThunderPolySetColor(0, 0);
    effPCP_ThunderPolyDraw(0);
    effEveBEDCutSetParams(0, 0);
    effEveBEDCutDraw(0);
    DDS3EFFECT_RAND_I();
}

// 0x1189080
void effPCPRadiateTBPartInit(effPCPRadiateTB_tag **pRadiateTB, s32 index) {
  u64 v3;
  struct effPCPRadiateTBPart_tag_array *pPart;
  f32 v8;
  effPCPRadiateTBPart_tag_o *v9;
  struct effPCPRadiateTBParam_t_o *param;
  f32 radius_r;
  f32 radius;
  f32 rotate_r;
  char v15;
  f32 rotate_s;
  f32 v17;

  pPart = (*pRadiateTB)->pPart;
  LODWORD(v3) = (*pRadiateTB)->param->number;
  v8 = v3;
  v9 = pPart->m_Items[index];
  v9->radian = (6.2832 / v8) * index;
  param = (*pRadiateTB)->param;
  radius = param->radius;
  radius_r = param->radius_r;
  v9->radius = radius * DDS3EFFECT_RAND_FA(radius_r);
  v9->rotate = 0.0;
  rotate_r = (*pRadiateTB)->param->rotate_r;
  v15 = DDS3EFFECT_RAND_I();
  rotate_s = (*pRadiateTB)->param->rotate_s;
  if ((v15 & 1) != 0)
  {
    v17 = rotate_s * DDS3EFFECT_RAND_FA(rotate_r);
  }
  else
  {
    v17 = -(rotate_s * DDS3EFFECT_RAND_FA(rotate_r));
  }
  v9->rotate_s = v17;
}

// 0x1189b90
void effPCPRadiateTBSetColor(void **hData, u32 abgr) {
}

// 0x1189a70
void effPCPRadiateTBSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1183fb0
effPCPRadiateThunder_tag *effPCPRadiateThunderCopy(void **hData, s32 bPos, bool tbldata) {
    effPCPRadiateThunderCreate(0, 0);
    dds3EffectPartCopy(0);
    return 0;
}

// 0x1183670
effPCPRadiateThunder_tag *effPCPRadiateThunderCreate(effPCPRadiateThunderParam_t *pParam, void **pData) {
    effPCPRadiateThunderParam_t__pClone(0, 0);
    dds3EffectPartCreate(0, 0);
    dds3EffectPartCopy(0);
    effPCP_ThunderPolyCreate(0, 0, 0);
    return 0;
}

// 0x1183c10
effPCPRadiateThunder_tag *effPCPRadiateThunderCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    GetEffPCPAgiFireballPart(0, 0);
    effPCPRadiateThunderCreate(0, 0);
    return 0;
}

// 0x1184370
void effPCPRadiateThunderDelete(void **hData) {
    effPCP_ThunderPolyDelete(0);
    dds3EffectPartDelete(0);
}

// 0x1184910
void effPCPRadiateThunderDraw(void **hData) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    effPCPRadiateThunderPartInit(0, 0);
    sdfCos(0);
    sdfSin(0);
    effPCP_ThunderPolyGetParam(0);
    sdfFabs(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    effColorBlend(0, 0, 0);
    effPCP_ThunderPolySetColor(0, 0);
    effPCP_ThunderPolyDraw(0);
    dds3EffectPartSetPosition(0, (sdfVector4_t){0});
    dds3EffectPartSetColor(0, 0);
    dds3EffectPartDraw(0);
}

// 0x1184750
void effPCPRadiateThunderPartInit(effPCPRadiateThunder_tag **pRadiateThunder, s32 index) {
  effPCPRadiateThunder_tag_o *v5;
  struct effPCPRadiateThunderPart_tag_array *pPart;
  f32 scale;
  struct effPCPRadiateThunderParam_t_o *param;
  effPCPRadiateThunderPart_tag_o *v10;
  s64 timing;
  u32 v12;
  f32 radius_s_r;
  f32 radius_s;
  struct effPCPRadiateThunderParam_t_o *v15;
  f32 radius_e;
  u64 v17;
  struct effPCPRadiateThunderParam_t_o *v18;
  f32 radian_s;

  v5 = *pRadiateThunder;
  pPart = (*pRadiateThunder)->pPart;
  scale = v5->scale;
  param = v5->param;
  v10 = pPart->m_Items[index];
  timing = param->timing;
  if (timing >= 1)
  {
    v12 = DDS3EFFECT_RAND_I();
    v10->frame = v12 / timing * timing - v12;
    param = (*pRadiateThunder)->param;
  }
  radius_s_r = param->radius_s_r;
  radius_s = param->radius_s;
  v10->radius = scale * (radius_s * DDS3EFFECT_RAND_FA(radius_s_r));
  v15 = (*pRadiateThunder)->param;
  radius_e = v15->radius_e;
  v10->radius_s = ((scale * (radius_e * DDS3EFFECT_RAND_FA(v15->radius_e_r)))
                        - v10->radius)
                       / v15->life;
  LODWORD(v17) = (*pRadiateThunder)->param->number;
  *&v17 = v17;
  v10->radian = (6.2832 / *&v17) * index;
  v18 = (*pRadiateThunder)->param;
  radian_s = v18->radian_s;
  v10->radian_s = radian_s * DDS3EFFECT_RAND_FA(v18->radian_r);
}

// 0x1185300
void effPCPRadiateThunderSetColor(void **hData, u32 abgr) {
}

// 0x11850f0
void effPCPRadiateThunderSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1185210
void effPCPRadiateThunderSetScale(void **hData, f32 scale) {
}

// 0x1182de0
effPCPRingPolyExp2_tag *effPCPRingPolyExp2Copy(void **hData, s32 bPos, bool tbldata) {
    effPCPRingPolyExp2Create(0);
    return 0;
}

// 0x1182930
effPCPRingPolyExp2_tag *effPCPRingPolyExp2Create(void **hData) {
    dds3RingPolyExpListCreate(0);
    effPCPRingPolyExp2Init(0);
    return 0;
}

// 0x11828b0
effPCPRingPolyExp2_tag *effPCPRingPolyExp2CreateP(void **hData, s32 bPos, bool tbldata) {
    effPCPRingPolyExp2Create(0);
    return 0;
}

// 0x1182ba0
effPCPRingPolyExp2_tag *effPCPRingPolyExp2CreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    effPCPRingPolyExp2Create(0);
    return 0;
}

// 0x1182f00
void effPCPRingPolyExp2Delete(void **hData) {
    dds3RingPolyExpListDelete(0);
}

// 0x1183020
void effPCPRingPolyExp2Draw(void **hData) {
    effPCPRingPolyExp2SetVertex(0, 0);
    effColorBlend(0, 0, 0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    dds3RingPolyExpListDraw(0);
}

// 0x11827c0
void effPCPRingPolyExp2Init(effPCPRingPolyExp2_tag **pPCPRingPolyExp2) {
  f32 radius;

  (*pPCPRingPolyExp2)->rotate_z = (*pPCPRingPolyExp2)->param->incline * 0.017453;
  (*pPCPRingPolyExp2)->rotate_y = (*pPCPRingPolyExp2)->param->rotate * 0.017453;
  (*pPCPRingPolyExp2)->rotate_s = (*pPCPRingPolyExp2)->param->rotate_s * 0.017453;
  (*pPCPRingPolyExp2)->radius = (*pPCPRingPolyExp2)->param->radius;
  (*pPCPRingPolyExp2)->radius_s = (*pPCPRingPolyExp2)->param->radius_s;
  radius = (*pPCPRingPolyExp2)->radius;
  effPCPRingPolyExp2SetVertex(pPCPRingPolyExp2, radius);
  (*pPCPRingPolyExp2)->frame = 0;
}

// 0x1183450
void effPCPRingPolyExp2SetColor(void **hData, u32 abgr) {
}

// 0x1183230
void effPCPRingPolyExp2SetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1183540
void effPCPRingPolyExp2SetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__STOREMATRIX(0);
}

// 0x1183350
void effPCPRingPolyExp2SetScale(void **hData, f32 scale) {
}

// 0x1181f60
void effPCPRingPolyExp2SetVertex(effPCPRingPolyExp2_tag **pPCPRingPolyExp2, f32 radius) {
    SetRotateMatrixZ(0);
    SetRotateMatrixY_B(0);
    MultMatrixRevNoArg();
    sdfCos(0);
    sdfSin(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__MULVECTOR();
    SDF_VU0__STOREVECTOR(0);
    LookAtMatrix((sdfVector4_t){0}, (sdfVector4_t){0}, (sdfVector4_t){0});
    ReverseMatrix();
}

// 0x11814f0
effPCPRingPolyExp_tag *effPCPRingPolyExpCopy(void **hData, s32 bPos, bool tbldata) {
    effPCPRingPolyExpCreate(0);
    return 0;
}

// 0x1181080
effPCPRingPolyExp_tag *effPCPRingPolyExpCreate(effPCPRingPolyExpParam_t *pParam) {
  u64 *v3;
  u32 split;
  dds3RingPolyExpList_tag_o *v6;
  s32 v8;
  struct System_UInt32_array *pVC;
  u64 v10;
  u64 max_length_low;
  u32 *v13;
  u64 v14;
  u32 color_c;
  u64 v17;
  f32 v20;
  effPCPRingPolyExp_tag_o *pPCPRingPolyExp;

  v3 = Allocate(effPCPRingPolyExp_tag);
  _ctor(v3, 0);
  pPCPRingPolyExp = v3;
  v3[2] = pParam;
  v3[3] = 0x8080808000000000LL;
  split = pParam->split;
  if (split <= 2)
  {
    split = 3;
    pParam->split = 3;
  }
  v6 = dds3RingPolyExpListCreate(split);
  v3[5] = v6;
  *(v3 + 8) = v6->point;
  v8 = v6->point >> 2;
  if (v8)
  {
    pVC = v6->pVC;
    v10 = 0;
    do
    {
      max_length_low = LODWORD(pVC->max_length);
      v13 = (pVC + 4 * v10);
      v14 = v10 + 2;
      v13[8] = pParam->color_e_in;
      color_c = pParam->color_c;
      v17 = v14 - 1;
      v13[10] = color_c;
      v13[9] = color_c;
      --v8;
      v10 = v17 + 3;
      v13[11] = pParam->color_e_out;
    }
    while (v8);
  }
  v20 = *(v3[2] + 56);
  effPCPRingPolyExpSetVertex(&pPCPRingPolyExp, v20);
  *(v3 + 6) = 0;
  *(v3[5] + 164) = pParam->blend;
  return v3;
}

// 0x1180f60
effPCPRingPolyExp_tag *effPCPRingPolyExpCreateP(void **hData, s32 bPos, bool tbldata) {
    effPCPRingPolyExpCreate(0);
    return 0;
}

// 0x11812b0
effPCPRingPolyExp_tag *effPCPRingPolyExpCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    effPCPRingPolyExpCreate(0);
    return 0;
}

// 0x1181600
void effPCPRingPolyExpDelete(void **hData) {
    dds3RingPolyExpListDelete(0);
}

// 0x1181720
void effPCPRingPolyExpDraw(void **hData) {
    effPCPRingPolyExpSetVertex(0, 0);
    effColorBlend(0, 0, 0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    dds3RingPolyExpListDraw(0);
}

// 0x1180ed0
void effPCPRingPolyExpInit(effPCPRingPolyExp_tag **pPCPRingPolyExp) {
  f32 radius_s;

  radius_s = (*pPCPRingPolyExp)->param->radius_s;
  effPCPRingPolyExpSetVertex(pPCPRingPolyExp, radius_s);
  (*pPCPRingPolyExp)->frame = 0;
}

// 0x1181be0
void effPCPRingPolyExpSetColor(void **hData, u32 abgr) {
}

// 0x1181e00
void effPCPRingPolyExpSetDirection(void **hData, sdfMatrix4_t *pMatrix) {
    SDF_VU0__LOADMATRIX(0);
    SetRotateMatrixX_B(0);
    MultMatrixNoArg();
    SDF_VU0__STOREMATRIX(0);
}

// 0x11819c0
void effPCPRingPolyExpSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1181cd0
void effPCPRingPolyExpSetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__STOREMATRIX(0);
}

// 0x1181ae0
void effPCPRingPolyExpSetScale(void **hData, f32 scale) {
}

// 0x1180850
void effPCPRingPolyExpSetVertex(effPCPRingPolyExp_tag **pPCPRingPolyExp, f32 radius) {
    sdfCos(0);
    sdfSin(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__MULVECTOR();
    SDF_VU0__STOREVECTOR(0);
}

// 0x116f470
effPCPRippleBlurExp_tag *effPCPRippleBlurExpCopy(void **hData, s32 bPos, bool tbldata) {
    effPCPRippleBlurExpCreate(0);
    return 0;
}

// 0x116f130
effPCPRippleBlurExp_tag *effPCPRippleBlurExpCreate(effPCPRippleBlurExpParam_t *pParam) {
  effPCPRippleBlurExp_tag_o *v3;
  dds3Effect_RippleBlurParam_t_o *RippleBlur;

  v3 = Allocate(effPCPRippleBlurExp_tag);
  _ctor(v3, 0);
  pParam->RippleBlur->interval = pParam->RippleBlur->interval * 1.5;
  RippleBlur = pParam->RippleBlur;
  v3->hRippleBlur = dds3EffectRippleBlurCreate(RippleBlur);
  v3->type = pParam->type;
  v3->life = pParam->life;
  v3->fade_in = pParam->fade_in;
  v3->fade_out = pParam->fade_out;
  v3->area_s = pParam->area_s;
  v3->area_e = pParam->area_e;
  v3->frame = 0;
  v3->abgr = -2139062144;
  v3->abgr_base = pParam->RippleBlur->abgr;
  return v3;
}

// 0x116f010
effPCPRippleBlurExp_tag *effPCPRippleBlurExpCreateP(void **pData, s32 bPos, bool tbldata) {
    effPCPRippleBlurExpCreate(0);
    return 0;
}

// 0x116f230
effPCPRippleBlurExp_tag *effPCPRippleBlurExpCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    effPCPRippleBlurExpCreate(0);
    return 0;
}

// 0x116f5e0
void effPCPRippleBlurExpDelete(void **hData) {
    dds3EffectRippleBlurDelete(0);
}

// 0x116f700
void effPCPRippleBlurExpDraw(void **hData) {
    dds3EffectRippleBlurReset(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    effScreenOffset();
    SDF_VU0__STOREVECTOR(0);
    effColorBlend(0, 0, 0);
    effColorMultiply(0, 0);
    dds3EffectRippleBlurDraw(0, 0);
}

// 0x116fb90
void effPCPRippleBlurExpSetColor(void **hData, u32 abgr) {
}

// 0x116fa60
void effPCPRippleBlurExpSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1167e70
effPCPShockWave01_tag *effPCPShockWave01Copy(void **hData, s32 bPos, bool tbldata) {
  effPCPShockWave01_tag_o *v4;
  Il2CppObject *hDataa;

  v4 = Allocate(effPCPShockWave01_tag);
  _ctor(v4, 0);
  hDataa = 0;
  hDataa = effPCP_ShockWave01_ThunderSpherePoly_Param;
  v4->pThunderPoly = effPCPThunderSpherePolyCreate(&hDataa, 0, 0);
  v4->frame = 0;
  return v4;
}

// 0x1167ba0
effPCPShockWave01_tag *effPCPShockWave01Create(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    effPCPThunderSpherePolyCreate(0, 0, 0);
    return 0;
}

// 0x1167d70
void effPCPShockWave01Delete(void **hData) {
    effPCPThunderSpherePolyDelete(0);
}

// 0x1167f70
void effPCPShockWave01Draw(void **hData) {
    effPCPThunderSpherePolyGetParam(0);
    effColorBlend(0, 0, 0);
    effPCPThunderSpherePolySetColor(0, 0);
    effPCPThunderSpherePolySetPosition(0, (sdfVector4_t){0});
    effPCPThunderSpherePolyDraw(0);
}

// 0x1167b00
void effPCPShockWave01Init(effPCPShockWave01_tag **pPCPShockWave01) {
  effPCPShockWave01_tag_o *v4;
  Il2CppObject *hData;

  hData = 0;
  hData = effPCP_ShockWave01_ThunderSpherePoly_Param;
  v4 = *pPCPShockWave01;
  v4->pThunderPoly = effPCPThunderSpherePolyCreate(&hData, 0, 0);
  (*pPCPShockWave01)->frame = 0;
}

// 0x1168360
void effPCPShockWave01SetColor(void **hData, u32 abgr) {
}

// 0x1168140
void effPCPShockWave01SetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1168270
void effPCPShockWave01SetScale(void **hData, f32 scale) {
}

// 0x1168e40
effPCPShockWave02_tag *effPCPShockWave02Copy(void **hData, s32 bPos, bool tbldata) {
  u64 *v4;
  effPCPShockWave02_tag_o *pPCPShockWave02;

  v4 = Allocate(effPCPShockWave02_tag);
  _ctor(v4, 0);
  pPCPShockWave02 = v4;
  effPCPShockWave02Init(&pPCPShockWave02);
  return v4;
}

// 0x1168b90
effPCPShockWave02_tag *effPCPShockWave02Create(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    effPCPShockWave02Init(0);
    return 0;
}

// 0x1168d00
void effPCPShockWave02Delete(void **hData) {
    effPCP_ThunderPolyDelete(0);
}

// 0x1168ed0
void effPCPShockWave02Draw(void **hData) {
    effPCP_ThunderPolyGetParam(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    effPCP_ThunderPolyDraw(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1168450
void effPCPShockWave02Init(effPCPShockWave02_tag **pPCPShockWave02) {
    sdfCos(0);
    sdfSin(0);
    DDS3EFFECT_RAND_FA(0);
    DDS3EFFECT_RAND_F();
    SetRotateMatrixAxis(0, (sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX_XYZ();
    SDF_VU0__STOREVECTOR(0);
    DDS3EFFECT_RAND_PM();
    DDS3EFFECT_RAND_I();
    effPCP_ThunderPolyCreate(0, 0, 0);
}

// 0x1169490
void effPCPShockWave02SetColor(void **hData, u32 abgr) {
}

// 0x1169270
void effPCPShockWave02SetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x11693a0
void effPCPShockWave02SetScale(void **hData, f32 scale) {
}

// 0x1158110
effPCPSparkleSphere_tag *effPCPSparkleSphereCreate(void **hData, s32 bPos, bool tbldata) {
    dds3BillboardGeneral(0);
    dds3BillboardSetMode(0, 0);
    return 0;
}

// 0x1158320
void effPCPSparkleSphereDelete(void **hData) {
    dds3BillboardDelete(0);
}

// 0x1158440
void effPCPSparkleSphereDraw(void **hData) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__MULVECTOR();
    SDF_VU0__ADDVECTOR();
    dds3BillboardSetPosition(0, (sdfVector4_t){0});
    dds3BillboardSetScale(0, 0, 0);
    effColorMultiply(0, 0);
    dds3BillboardSetRGBA(0, 0);
    dds3BillboardDraw(0);
}

// 0x11589a0
void effPCPSparkleSphereSetArea(void **hData, f32 area) {
}

// 0x11588b0
void effPCPSparkleSphereSetColor(void **hData, u32 abgr) {
}

// 0x1158780
void effPCPSparkleSphereSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x118a320
effPCPSpiralBED_tag *effPCPSpiralBEDCopy(void **hData, s32 bPos, bool tbldata) {
    effEveBEDCutCreate(0, 0, 0);
    DDS3EFFECT_RAND_I();
    return 0;
}

// 0x1189c80
effPCPSpiralBED_tag *effPCPSpiralBEDCreate(effPCPSpiralBEDParam_t *pParam, void *pBEDData) {
    effEveBEDCreate(0);
    effEveBEDCutCreate(0, 0, 0);
    DDS3EFFECT_RAND_I();
    return 0;
}

// 0x118a0a0
effPCPSpiralBED_tag *effPCPSpiralBEDCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetDataUnityOffSet(0, 0, 0);
    GetEffPCPpBEDData(0, 0);
    effPCPSpiralBEDCreate(0, 0);
    return 0;
}

// 0x118a710
void effPCPSpiralBEDDelete(void **hData) {
    effEveBEDCutDelete(0);
    effEveBEDDelete(0);
}

// 0x118aa40
void effPCPSpiralBEDDraw(void **hData) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    effPCPSpiralBEDPartInit(0, 0);
    effEveBEDCutSetScale(0, 0);
    sdfCos(0);
    sdfSin(0);
    effColorBlend(0, 0, 0);
    effEveBEDCutSetParams(0, 0);
    effEveBEDCutDraw(0);
}

// 0x118a8c0
void effPCPSpiralBEDPartInit(effPCPSpiralBED_tag **pSpiralBED, s32 index) {
  struct effPCPSpiralBEDPart_tag_array *pPart;
  effPCPSpiralBEDPart_tag_o *v7;
  f32 scale;
  f32 height;
  struct effPCPSpiralBEDParam_t_o *param;
  f32 up_s;
  struct effPCPSpiralBEDParam_t_o *v12;
  f32 rotate_s;
  struct effPCPSpiralBEDParam_t_o *v14;
  f32 radius_s;
  struct effPCPSpiralBEDParam_t_o *v16;
  f32 radius_e;

  pPart = (*pSpiralBED)->pPart;
  v7 = pPart->m_Items[index];
  scale = (*pSpiralBED)->scale;
  v7->frame = 0;
  height = (*pSpiralBED)->param->height;
  v7->up = -(height * DDS3EFFECT_RAND_F());
  param = (*pSpiralBED)->param;
  up_s = param->up_s;
  v7->up_s = up_s * DDS3EFFECT_RAND_FA(param->up_r);
  v7->rotate = DDS3EFFECT_RAND_F() * 6.2832;
  v12 = (*pSpiralBED)->param;
  rotate_s = v12->rotate_s;
  v7->rotate_s = rotate_s * DDS3EFFECT_RAND_FA(v12->rotate_r);
  v14 = (*pSpiralBED)->param;
  radius_s = v14->radius_s;
  v7->radius = scale * (radius_s * DDS3EFFECT_RAND_FA(v14->radius_s_r));
  v16 = (*pSpiralBED)->param;
  radius_e = v16->radius_e;
  v7->radius_s = ((scale * (radius_e * DDS3EFFECT_RAND_FA(v16->radius_e_r)))
                       - v7->radius)
                      / v16->life;
}

// 0x118b0c0
void effPCPSpiralBEDSetColor(void **hData, u32 abgr) {
}

// 0x118aeb0
void effPCPSpiralBEDSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x118afd0
void effPCPSpiralBEDSetScale(void **hData, f32 scale) {
}

// 0x117f2c0
effPCPThunderSphereExp_tag *effPCPThunderSphereExpCopy(void **hData, s32 bPos, bool tbldata) {
    effPCPThunderSpherePolyGetParam(0);
    effPCPThunderSphereExpCreate(0);
    return 0;
}

// 0x117f010
effPCPThunderSphereExp_tag *effPCPThunderSphereExpCreate(effPCPThunderSphereExpParam_t *pParam) {
    effPCPThunderSpherePolyCreate(0, 0, 0);
    return 0;
}

// 0x117eef0
effPCPThunderSphereExp_tag *effPCPThunderSphereExpCreateP(void **pData, s32 bPos, bool tbldata) {
    effPCPThunderSphereExpCreate(0);
    return 0;
}

// 0x117f160
effPCPThunderSphereExp_tag *effPCPThunderSphereExpCreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPDataGetDataUnity(0, 0, 0, 0);
    effPCPThunderSphereExpCreate(0);
    return 0;
}

// 0x117f430
void effPCPThunderSphereExpDelete(void **hData) {
    effPCPThunderSpherePolyDelete(0);
}

// 0x117f530
void effPCPThunderSphereExpDraw(void **hData) {
    effPCPThunderSpherePolyGetParam(0);
    effColorBlend(0, 0, 0);
    effPCPThunderSpherePolySetColor(0, 0);
    effPCPThunderSpherePolySetPosition(0, (sdfVector4_t){0});
    effPCPThunderSpherePolySetScale(0, 0);
    effPCPThunderSpherePolyDraw(0);
}

// 0x117f860
void effPCPThunderSphereExpSetColor(void **hData, u32 abgr) {
}

// 0x117f730
void effPCPThunderSphereExpSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x117f950
void effPCPThunderSphereExpSetScale(void **hData, f32 scale) {
}

// 0x1161b30
effPCPZiodin01_tag *effPCPZiodin01Copy(void **hData, s32 bPos, bool tbldata) {
  u64 *v4;
  effPCPZiodin01_tag_o *pPCPZiodin01;

  v4 = Allocate(effPCPZiodin01_tag);
  _ctor(v4, 0);
  pPCPZiodin01 = v4;
  effPCPZiodin01Init(&pPCPZiodin01);
  return v4;
}

// 0x1161650
effPCPZiodin01_tag *effPCPZiodin01Create(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    effPCPZiodin01Init(0);
    return 0;
}

// 0x11617c0
void effPCPZiodin01Delete(void **hData) {
    effPCP_ThunderPolyDelete(0);
}

// 0x1161bc0
void effPCPZiodin01Draw(void **hData) {
    effPCP_ThunderPolyGetParam(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    effPCP_ThunderPolyDraw(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x11610e0
void effPCPZiodin01Init(effPCPZiodin01_tag **pPCPZiodin01) {
    sdfCos(0);
    sdfSin(0);
    DDS3EFFECT_RAND_FA(0);
    DDS3EFFECT_RAND_PM();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__MULVECTOR();
    SDF_VU0__ADDVECTOR();
    DDS3EFFECT_RAND_I();
    effPCP_ThunderPolyCreate(0, 0, 0);
}

// 0x1162180
void effPCPZiodin01SetColor(void **hData, u32 abgr) {
}

// 0x1161f60
void effPCPZiodin01SetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1162090
void effPCPZiodin01SetScale(void **hData, f32 scale) {
}

// 0x1162e80
effPCPZiodin02_tag *effPCPZiodin02Copy(void **hData, s32 bPos, bool tbldata) {
  u64 *v4;
  effPCPZiodin02_tag_o *pPCPZiodin02;

  v4 = Allocate(effPCPZiodin02_tag);
  _ctor(v4, 0);
  pPCPZiodin02 = v4;
  effPCPZiodin02Init(&pPCPZiodin02);
  return v4;
}

// 0x11629a0
effPCPZiodin02_tag *effPCPZiodin02Create(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    effPCPZiodin02Init(0);
    return 0;
}

// 0x1162b10
void effPCPZiodin02Delete(void **hData) {
    effPCP_ThunderPolyDelete(0);
}

// 0x1162f10
void effPCPZiodin02Draw(void **hData) {
    effPCP_ThunderPolyGetParam(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    effPCP_ThunderPolyDraw(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1162270
void effPCPZiodin02Init(effPCPZiodin02_tag **pPCPZiodin02) {
    sdfCos(0);
    sdfSin(0);
    DDS3EFFECT_RAND_FA(0);
    DDS3EFFECT_RAND_F();
    SetRotateMatrixAxis(0, (sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX_XYZ();
    SDF_VU0__STOREVECTOR(0);
    DDS3EFFECT_RAND_PM();
    DDS3EFFECT_RAND_I();
    effPCP_ThunderPolyCreate(0, 0, 0);
}

// 0x11634d0
void effPCPZiodin02SetColor(void **hData, u32 abgr) {
}

// 0x11632b0
void effPCPZiodin02SetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x11633e0
void effPCPZiodin02SetScale(void **hData, f32 scale) {
}

// 0x1163fb0
effPCPZiodin03_tag *effPCPZiodin03Copy(void **hData, s32 bPos, bool tbldata) {
  u64 *v4;
  effPCPZiodin03_tag_o *pPCPZiodin03;

  v4 = Allocate(effPCPZiodin03_tag);
  _ctor(v4, 0);
  pPCPZiodin03 = v4;
  effPCPZiodin03Init(&pPCPZiodin03);
  return v4;
}

// 0x1163d00
effPCPZiodin03_tag *effPCPZiodin03Create(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    effPCPZiodin03Init(0);
    return 0;
}

// 0x1163e70
void effPCPZiodin03Delete(void **hData) {
    effPCP_ThunderPolyDelete(0);
}

// 0x1164040
void effPCPZiodin03Draw(void **hData) {
    effPCP_ThunderPolyGetParam(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    effPCP_ThunderPolyDraw(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x11635c0
void effPCPZiodin03Init(effPCPZiodin03_tag **pPCPZiodin03) {
    sdfCos(0);
    sdfSin(0);
    DDS3EFFECT_RAND_FA(0);
    DDS3EFFECT_RAND_F();
    SetRotateMatrixAxis(0, (sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX_XYZ();
    SDF_VU0__STOREVECTOR(0);
    DDS3EFFECT_RAND_PM();
    DDS3EFFECT_RAND_I();
    effPCP_ThunderPolyCreate(0, 0, 0);
}

// 0x1164600
void effPCPZiodin03SetColor(void **hData, u32 abgr) {
}

// 0x11643e0
void effPCPZiodin03SetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1164510
void effPCPZiodin03SetScale(void **hData, f32 scale) {
}

// 0x1165300
effPCPZiodin04_tag *effPCPZiodin04Copy(void **hData, s32 bPos, bool tbldata) {
  u64 *v4;
  effPCPZiodin04_tag_o *pPCPZiodin04;

  v4 = Allocate(effPCPZiodin04_tag);
  _ctor(v4, 0);
  pPCPZiodin04 = v4;
  effPCPZiodin04Init(&pPCPZiodin04);
  return v4;
}

// 0x1164e20
effPCPZiodin04_tag *effPCPZiodin04Create(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    effPCPZiodin04Init(0);
    return 0;
}

// 0x1164f90
void effPCPZiodin04Delete(void **hData) {
    effPCP_ThunderPolyDelete(0);
}

// 0x1165390
void effPCPZiodin04Draw(void **hData) {
    effPCP_ThunderPolyGetParam(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    effPCP_ThunderPolyDraw(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x11646f0
void effPCPZiodin04Init(effPCPZiodin04_tag **pPCPZiodin04) {
    sdfCos(0);
    sdfSin(0);
    DDS3EFFECT_RAND_FA(0);
    DDS3EFFECT_RAND_F();
    SetRotateMatrixAxis(0, (sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX_XYZ();
    SDF_VU0__STOREVECTOR(0);
    DDS3EFFECT_RAND_PM();
    DDS3EFFECT_RAND_I();
    effPCP_ThunderPolyCreate(0, 0, 0);
}

// 0x1165950
void effPCPZiodin04SetColor(void **hData, u32 abgr) {
}

// 0x1165730
void effPCPZiodin04SetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1165860
void effPCPZiodin04SetScale(void **hData, f32 scale) {
}

// 0x11580f0
void effPkt3DPrimLinkPoly(sdfDrawTag_t *pTag, sdf3DPrimPolyParm_t *pParam) {
  ;
}

// 0x11580d0
void mdlLink(dds3ModelHandle_t *aHandle, sdfModelOt_t *aModelOt) {
  ;
}

// 0x11580e0
void mdlSetMotionSpeed(dds3ModelHandle_t **aHandle, f32 speed) {
  ;
}

// 0x1158100
void mdlSingleMotion(dds3ModelHandle_t **aHandle, s32 aGroup, s32 aNumber) {
  ;
}
