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
  Il2CppObject *DataUnityOffSet;
  Il2CppObject *v6;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  System_Array_o *v11;
  u64 v13[3];

  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(hData, offset, 58);
  v6 = DataUnityOffSet;
  if (DataUnityOffSet)
  {
    klass = DataUnityOffSet->klass;
    if (DataUnityOffSet->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_object_Param_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCP_object_Param_t, v13);
      if ((v13[0] & 1) != 0)
        v9 = v13[2];
      else
        v9 = v13 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  v11 = NewSpecific(byte, LODWORD(DataUnityOffSet[1].klass->_1.namespaze));
  Copy_3880080(
    v6[1].klass,
    v6[1].monitor,
    v11,
    0,
    LODWORD(v6[1].klass->_1.namespaze) - LODWORD(v6[1].monitor),
    0);
  return v11;
}

// 0x1186df0
void *GetEffPCPpBEDData(void *hData, s32 offset) {
  Il2CppObject *DataUnityOffSet;
  Il2CppObject *v6;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  System_Array_o *v11;
  u64 v13[3];

  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(hData, offset, 58);
  v6 = DataUnityOffSet;
  if (DataUnityOffSet)
  {
    klass = DataUnityOffSet->klass;
    if (DataUnityOffSet->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCP_object_Param_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCP_object_Param_t, v13);
      if ((v13[0] & 1) != 0)
        v9 = v13[2];
      else
        v9 = v13 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  v11 = NewSpecific(byte, LODWORD(DataUnityOffSet[1].klass->_1.namespaze));
  Copy_3880080(
    v6[1].klass,
    v6[1].monitor,
    v11,
    0,
    LODWORD(v6[1].klass->_1.namespaze) - LODWORD(v6[1].monitor),
    0);
  return v11;
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
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v7;
  const char *namespaze;
  s64 v9;
  u64 v10;
  UnityEngine_Object_o *v12;
  Il2CppClass *v13;
  UnityEngine_Object_o *gameObject;
  Il2CppClass *v17;
  s64 v19;
  char *v20;
  s64 *v21;
  u64 v22[3];

  v3 = *hData;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3RingPolyExpList_tag)
  {
    sub_8FC2C0(klass->_1.element_class, dds3RingPolyExpList_tag, v22);
    if ((v22[0] & 1) != 0)
      v20 = v22[2];
    else
      v20 = v22 + 1;
    v21 = sub_8C4940(v20);
  }
  v7 = v3[14].klass;
  if (v7)
  {
    namespaze = v7->_1.namespaze;
    if (namespaze >= 1)
    {
      v9 = 4;
      do
      {
        v10 = v9 - 4;
        v12 = *(&v7->_1.image + v9);
        if (op_Inequality(v12, 0, 0))
        {
          v13 = v3[14].klass;
          gameObject = get_gameObject(*(&v13->_1.image + v9), 0);
          Destroy_27360000(gameObject);
          v17 = v3[14].klass;
          *(&v17->_1.image + v9) = 0;
        }
        v7 = v3[14].klass;
        LODWORD(namespaze) = v7->_1.namespaze;
        v19 = v9 - 3;
        ++v9;
      }
      while (v19 < namespaze);
    }
    v3[14].klass = 0;
  }
}

// 0x117fd70
void dds3RingPolyExpListDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppClass *v8;
  void *monitor;
  Il2CppClass *v10;
  Il2CppClass *v11;
  void *v12;
  Il2CppClass *v13;
  s64 v18;
  s64 v19;
  s64 v20;
  s64 v21;
  s64 v22;
  s64 v23;
  f32 z;
  f32 x;
  f32 y;
  f32 v30;
  f32 v32;
  f32 v33;
  f32 v34;
  f32 v35;
  Il2CppClass *v36;
  Il2CppClass *v38;
  s32 v39;
  XRD773Unity_GraphicManager_o *Instance;
  s64 *Mesh;
  s64 *v43;
  Il2CppClass *v45;
  UnityEngine_Object_o *gameObject;
  System_String_o *name;
  System_String_o *v49;
  System_String_o *v50;
  Il2CppClass *v51;
  s32 monitor_high;
  s32 v55;
  u64 v56;
  Il2CppClass *v57;
  Il2CppClass *v59;
  XRD773Unity_CommonMesh_o *v61;
  UnityEngine_Vector3_array *v62;
  Il2CppClass *v63;
  XRD773Unity_CommonMesh_o *v65;
  UnityEngine_Color_array *v66;
  Il2CppClass *v67;
  XRD773Unity_CommonMesh_o *v69;
  System_Int32_array *v70;
  Il2CppClass *v71;
  UnityEngine_Vector3_array *Position;
  Il2CppClass *v74;
  UnityEngine_Vector3_array *v75;
  UnityEngine_Color_array *Color;
  UnityEngine_Color_array *v79;
  u64 v80;
  u32 *p_z;
  f32 *p_a;
  s64 v83;
  Il2CppClass *v84;
  f32 v86;
  f32 v87;
  f32 v88;
  f32 v89;
  long f64 v90;
  long f64 v91;
  s32 v92;
  s32 v93;
  u32 *v95;
  Il2CppClass *v98;
  System_Int32_array *IndexTable;
  System_Int32_array *v102;
  s32 v103;
  s32 v104;
  s32 i;
  s32 v106;
  u64 v107;
  s64 v108;
  struct System_UInt32_array *RingPolyExpIndex;
  s32 v113;
  il2cpp_array_size_t max_length;
  s64 v115;
  s64 v116;
  Il2CppClass *v118;
  u64 v120;
  s32 v121;
  s32 v122;
  u64 v123;
  Il2CppObject *v124;
  UnityEngine_Matrix4x4_o v125;
  UnityEngine_Matrix4x4_o v126;
  UnityEngine_Matrix4x4_o v127;
  UnityEngine_Matrix4x4_o v128;
  UnityEngine_Matrix4x4_o v129;
  UnityEngine_Matrix4x4_o v130;
  UnityEngine_Matrix4x4_o v131;
  UnityEngine_Matrix4x4_o v132;
  UnityEngine_Matrix4x4_o v133;
  UnityEngine_Matrix4x4_o dest;
  UnityEngine_Matrix4x4_o v135;
  u32 v136;
  UnityEngine_Matrix4x4_o aMatrix;
  UnityEngine_Vector3_o v138;
  UnityEngine_Color_o BlendColor;
  UnityEngine_Color_o VertexColor;
  UnityEngine_Vector3_o v141;
  UnityEngine_Vector3_o v142;
  UnityEngine_Vector3_o v143;
  UnityEngine_Vector3_o v144;
  UnityEngine_Vector4_o v145;
  UnityEngine_Vector4_o v146;

  v136 = 0;
  memset(&aMatrix, 0, sizeof(aMatrix));
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3RingPolyExpList_tag)
    {
      sub_8FC2C0(klass->_1.element_class, dds3RingPolyExpList_tag, &v133);
      if ((LOBYTE(v133.m00) & 1) != 0)
        v6 = *&v133.m01;
      else
        v6 = &v133.m00 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  if (HIDWORD(v3[10].monitor))
  {
    v8 = v3[5].klass;
    monitor = v3[5].monitor;
    v10 = v3[6].klass;
    *&v135.m21 = v3[6].monitor;
    *&v135.m01 = v10;
    *&v135.m20 = monitor;
    *&v135.m00 = v8;
    v11 = v3[7].klass;
    v12 = v3[7].monitor;
    v13 = v3[8].klass;
    *&v135.m23 = v3[8].monitor;
    *&v135.m03 = v13;
    *&v135.m22 = v12;
    *&v135.m02 = v11;
    SDF_VU0__LOADMATRIX(&v135);
    memmove(&dest, &v3[1], 0x40u);
    SDF_VU0__LOADMATRIX_B(&dest);
    MultMatrixNoArg();
    StoreMatrix(&aMatrix);
    v18 = *&mod_matrix.m00;
    v19 = *&mod_matrix.m20;
    v20 = *&mod_matrix.m01;
    *&v133.m21 = *&mod_matrix.m21;
    *&v133.m01 = v20;
    *&v133.m20 = v19;
    *&v133.m00 = v18;
    v21 = *&mod_matrix.m02;
    v22 = *&mod_matrix.m22;
    v23 = *&mod_matrix.m03;
    *&v133.m23 = *&mod_matrix.m23;
    *&v133.m03 = v23;
    *&v133.m22 = v22;
    *&v133.m02 = v21;
    sub_19FF440(&aMatrix, 0, &v132);
    v130 = v133;
    v129 = v132;
    op_Multiply(&v131, &v130, &v129, 0);
    z = mod_vertex.z;
    x = mod_vertex.x;
    y = mod_vertex.y;
    v30 = *&v3[10].klass;
    v141.x = x;
    v141.y = y;
    v141.z = z;
    v142 = op_Multiply(v141, v30, 0);
    Scale(&v128, v142);
    v126 = v131;
    v125 = v128;
    op_Multiply(&v127, &v126, &v125, 0);
    aMatrix = v127;
    v32 = *&v3[9].klass;
    v33 = *(&v3[9].klass + 1);
    v35 = *&v3[9].monitor;
    v34 = *(&v3[9].monitor + 1);
    v145.x = v32;
    v145.y = v33;
    v145.z = v35;
    v145.w = v34;
    v143 = op_Implicit_8738992(v145);
    v144 = Scale(v143, mod_pos);
    op_Implicit(v144, 0);
    sub_1A009D0(&aMatrix, 3);
    if (!v3[14].klass)
    {
      v36 = NewSpecific(XRD773Unity_CommonMesh, LODWORD(v3[13].klass));
      v3[14].klass = v36;
      v136 = 0;
      if (SLODWORD(v3[13].klass) >= 1)
      {
        v38 = v36;
        v39 = 0;
          goto LABEL_33;
LABEL_31:
        while (1)
        {
LABEL_33:
          Instance = get_Instance();
          Mesh = GetMesh(Instance, HIDWORD(v3[10].klass), 0, 0);
          v43 = Mesh;
          *(&v38->_1.byval_arg.data + v39) = v43;
          v45 = v3[14].klass;
          gameObject = get_gameObject(*(&v45->_1.byval_arg.data + v136), 0);
          name = get_name(gameObject);
          v49 = sub_232970(&v136);
          v50 = Concat_5221536(name, ":dds3RingPolyExpListDraw:", v49);
          set_name(gameObject, v50);
          v51 = v3[14].klass;
          SetAutoHide(*(&v51->_1.byval_arg.data + v136), 1, 0);
          v39 = v136 + 1;
          v136 = v39;
          if (v39 >= SLODWORD(v3[13].klass))
            break;
          v38 = v3[14].klass;
            goto LABEL_31;
        }
      }
    }
    BlendColor = effGetBlendColor(v3[10].monitor);
    monitor_high = HIDWORD(v3[10].monitor);
    v55 = monitor_high + 3;
    v123 = monitor_high;
    if (monitor_high >= 0)
      v55 = HIDWORD(v3[10].monitor);
    if (SLODWORD(v3[13].klass) >= 1)
    {
      v121 = (v55 >> 2) - 1;
      v122 = 0;
      v56 = 0;
      v124 = v3;
      while (1)
      {
        v57 = v3[14].klass;
        if (v123 > SLODWORD(GetPosition(*(&v57->_1.byval_arg.data + v56), 0)->max_length))
        {
          v59 = v3[14].klass;
          v61 = *(&v59->_1.byval_arg.data + v56);
          v62 = NewSpecific(UnityEngine_Vector3, v123);
          SetPosition_20241056(v61, v62);
          v63 = v3[14].klass;
          v65 = *(&v63->_1.byval_arg.data + v56);
          v66 = NewSpecific(UnityEngine_Color, v123);
          SetColor_20241296(v65, v66);
          v67 = v3[14].klass;
          v69 = *(&v67->_1.byval_arg.data + v56);
          v70 = NewSpecific(s32, (18 * v121));
          SetIndexTable(v69, v70);
        }
        v71 = v3[14].klass;
        Position = GetPosition(*(&v71->_1.byval_arg.data + v56), 0);
        v74 = v3[14].klass;
        v75 = Position;
        v120 = v56;
        Color = GetColor(*(&v74->_1.byval_arg.data + v56), 0);
        if (v123 >= 1)
        {
          v79 = Color;
          v80 = 0;
          p_z = &v75->m_Items[0].z;
          p_a = &Color->m_Items[0].a;
          v83 = 16LL * v122 + 32;
          do
          {
            v84 = v124[11].klass;
            v86 = *(&v84->_1.image + v83);
            v87 = *(&v84->_1.image + v83 + 4);
            v88 = *(&v84->_1.gc_desc + v83);
            v89 = *(&v84->_1.gc_desc + v83 + 4);
            {
            }
            v146.x = v86;
            v146.y = v87;
            v146.z = v88;
            v146.w = v89;
            v138 = op_Implicit_8738992(v146);
            v91 = sub_1A00CF0(&aMatrix.m00, v138.x, v138.y, v138.z, v90);
            *(p_z - 2) = LODWORD(v91);
            *(p_z - 1) = v92;
            *p_z = v93;
            v95 = v124[11].monitor;
            VertexColor = effGetVertexColor(v95[v122 + 8 + v80], BlendColor);
            ++v80;
            *(p_a - 3) = VertexColor;
            v83 += 16;
            p_z += 3;
            p_a += 4;
          }
          while (v123 != v80);
        }
        v3 = v124;
        v98 = v124[14].klass;
        IndexTable = GetIndexTable(*(&v98->_1.byval_arg.data + v56), 0);
        v102 = IndexTable;
        if (v121 >= 1)
          break;
        v113 = 0;
        LODWORD(max_length) = IndexTable->max_length;
        if (max_length > 0)
          goto LABEL_93;
LABEL_97:
        v118 = v3[14].klass;
        SetActive(*(&v118->_1.byval_arg.data + v56++), 1, 0);
        v122 += v123;
        if (v56 >= SLODWORD(v3[13].klass))
          return;
      }
      v103 = 0;
      v104 = 0;
      for (i = 0; i != v121; ++i)
      {
        v106 = v103;
        v107 = 0;
        v108 = &v102->m_Items[v103];
        do
        {
          *(v108 + 4 * v107) = RingPolyExpIndex->m_Items[v107] + v104;
          ++v107;
        }
        while (v107 != 18);
        v103 = v106 + 18;
        v104 += 4;
      }
      v3 = v124;
      v56 = v120;
      v113 = v106 + 18;
      LODWORD(max_length) = v102->max_length;
      if (v106 + 18 >= max_length)
        goto LABEL_97;
LABEL_93:
      v115 = v113;
      do
      {
        v116 = v115 + 1;
        v102->m_Items[v115] = 0;
        max_length = v102->max_length;
        ++v115;
      }
      while (v116 < max_length);
      goto LABEL_97;
    }
  }
}

// 0x1179200
effPCPAgiFireball2_tag *effPCPAgiFireball2Copy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  effPCPAgiFireball2_tag_o *v10;
  Il2CppClass *v11;
  u64 v12;
  u32 *pAgiFireball;
  u32 *v16;
  s64 v17;
  struct effPCPAgiFireball_tag_array *v19;
  u64 *monitor;
  effPCPAgiFireball_tag_o *v22;
  struct effPCPAgiFireball_tag_array *v24;
  struct effPCPAgiFireball_tag_array *v26;
  struct effPCPAgiFireball_tag_array *v28;
  struct effPCPAgiFireball_tag_array *v30;
  struct effPCPAgiFireball_tag_array *v32;
  u32 *v34;
  effPCPAgiFireball_tag_o *v35;
  u32 *v37;
  u64 v39[3];

  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPAgiFireball2_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPAgiFireball2_tag, v39);
      if ((v39[0] & 1) != 0)
        v8 = v39[2];
      else
        v8 = v39 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = Allocate(effPCPAgiFireball2_tag);
  _ctor(v10, 0);
  Clear(v10, 0);
  v11 = v5[1].klass;
  v12 = 0;
  v10->frame = 0;
  v10->param = v11;
  do
  {
    pAgiFireball = v10->pAgiFireball;
    v16 = &pAgiFireball[2 * v12];
    v17 = *(v16 + 4);
    *(v16 + 4) = v17;
    v19 = v10->pAgiFireball;
    monitor = v5[1].monitor;
    v22 = v19->m_Items[v12];
    v22->param = *(monitor[v12 + 4] + 112LL);
    v24 = v10->pAgiFireball;
    v24->m_Items[v12]->frame = 0;
    v26 = v10->pAgiFireball;
    v26->m_Items[v12]->abgr = -2139062144;
    v28 = v10->pAgiFireball;
    v28->m_Items[v12]->type = 0;
    v30 = v10->pAgiFireball;
    SDF_VU0__STOREIDENTITY(&v30->m_Items[v12]->matrix);
    v32 = v10->pAgiFireball;
    v34 = v5[1].monitor;
    v35 = v32->m_Items[v12];
    v37 = &v34[2 * v12++];
    v35->pCopySrc = *(v37 + 4);
  }
  while (v12 != 3);
  return v10;
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
  dds3EffectPCPData_t_o *v6;
  Il2CppObject *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  effPCPAgiFireball2PartList_t_o *v12;
  struct dds3EffectPCPData_Part_t_array *pcpData;
  Il2CppObject *v15;
  u32 offset;
  Il2CppObject *DataUnityOffSet;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v23;
  s64 *v24;
  struct dds3EffectPCPData_Part_t_array *v25;
  struct System_Object_array *pHelper;
  Il2CppObject *v27;
  u32 v29;
  s64 *EffPCPAgiFireballPart;
  s64 *v33;
  struct dds3EffectPCPData_Part_t_array *v35;
  struct System_Object_array *v36;
  Il2CppObject *v37;
  u32 v39;
  s64 *v40;
  s64 *v43;
  struct dds3EffectPCPData_Part_t_array *v45;
  struct System_Object_array *v46;
  Il2CppObject *v47;
  u32 v49;
  s64 *v50;
  s64 *v53;
  u64 v55;
  struct dds3EffectPCPData_Part_t_array *v57;
  u64 v58;
  u32 *pAttach;
  Il2CppObject *v60;
  u32 v62;
  s64 *v63;
  s64 *v64;
  u32 *v66;
  struct dds3EffectPCPData_Part_t_array *v67;
  struct System_Object_array *pTrack;
  Il2CppObject *v69;
  u32 v71;
  s64 *v72;
  s64 *v75;
  struct dds3EffectPCPData_Part_t_array *v77;
  Il2CppObject *v78;
  struct System_Object_array *v79;
  u32 v81;
  s64 *v82;
  s64 *v85;
  struct dds3EffectPCPData_Part_t_array *v87;
  Il2CppObject *v88;
  struct System_Object_array *v89;
  u32 v91;
  s64 *v92;
  s64 *v95;
  struct effPCPAgiFireballPartList_t_o *PartList;
  u64 v98;
  u64 v99;
  struct dds3EffectPCPData_Part_t_array *v101;
  u32 *pStart;
  Il2CppObject *v103;
  u32 v105;
  s64 *v106;
  s64 *v107;
  u32 *v109;
  struct dds3EffectPCPData_Part_t_array *v110;
  Il2CppObject *v111;
  u32 v113;
  effPCPAgiFireball2Param_t_o *pAFB2Param;
  s32 pos;
  u64 v124[2];
  char *v125;

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v7->klass->_1.element_class, v8, v124);
      if ((v124[0] & 1) != 0)
        v10 = v125;
      else
        v10 = v124 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v6, Interface, &pos);
  v12 = Allocate(effPCPAgiFireball2PartList_t);
  effPCPAgiFireball2PartList_t___ctor(v12);
  pcpData = v6->pcpData;
  v15 = *hData;
  offset = pcpData->m_Items[0]->offset;
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v15, offset + bPos, 18);
  if (DataUnityOffSet)
  {
    klass = DataUnityOffSet->klass;
    if (DataUnityOffSet->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPAgiFireball2Param_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPAgiFireball2Param_t, v124);
      if ((v124[0] & 1) != 0)
        v23 = v125;
      else
        v23 = v124 + 1;
      v24 = sub_8C4940(v23);
    }
  }
  v25 = v6->pcpData;
  pHelper = v12->pHelper;
  v27 = *hData;
  pAFB2Param = DataUnityOffSet;
  v29 = v25->m_Items[1]->offset;
  EffPCPAgiFireballPart = GetEffPCPAgiFireballPart(v27, v29 + bPos);
  v33 = EffPCPAgiFireballPart;
  pHelper->m_Items[0] = v33;
  v35 = v6->pcpData;
  v36 = v12->pHelper;
  v37 = *hData;
  v39 = v35->m_Items[2]->offset;
  v40 = GetEffPCPAgiFireballPart(v37, v39 + bPos);
  v43 = v40;
  v36->m_Items[1] = v43;
  v45 = v6->pcpData;
  v46 = v12->pHelper;
  v47 = *hData;
  v49 = v45->m_Items[3]->offset;
  v50 = GetEffPCPAgiFireballPart(v47, v49 + bPos);
  v53 = v50;
  v55 = 0;
  v46->m_Items[2] = v53;
  do
  {
    v57 = v6->pcpData;
    pAttach = v12->PartList->pAttach;
    v60 = *hData;
    v62 = v57->m_Items[v55 + 4]->offset;
    v63 = GetEffPCPAgiFireballPart(v60, v62 + bPos);
    v64 = v63;
    v58 = v55 + 4;
    v66 = &pAttach[2 * v55++];
    *(v66 + 4) = v64;
  }
  while (v58 != 8);
  v67 = v6->pcpData;
  pTrack = v12->PartList->pTrack;
  v69 = *hData;
  v71 = v67->m_Items[v55 + 4]->offset;
  v72 = GetEffPCPAgiFireballPart(v69, v71 + bPos);
  v75 = v72;
  pTrack->m_Items[0] = v75;
  v77 = v6->pcpData;
  v78 = *hData;
  v79 = v12->PartList->pTrack;
  v81 = v77->m_Items[v55 + 5]->offset;
  v82 = GetEffPCPAgiFireballPart(v78, v81 + bPos);
  v85 = v82;
  v79->m_Items[1] = v85;
  v87 = v6->pcpData;
  v88 = *hData;
  v89 = v12->PartList->pTrack;
  v91 = v87->m_Items[v55 + 6]->offset;
  v92 = GetEffPCPAgiFireballPart(v88, v91 + bPos);
  v95 = v92;
  v89->m_Items[2] = v95;
  PartList = v12->PartList;
  v98 = 0;
  v99 = v55 + 7;
  do
  {
    v101 = v6->pcpData;
    pStart = PartList->pStart;
    v103 = *hData;
    v105 = v101->m_Items[v99]->offset;
    v106 = GetEffPCPAgiFireballPart(v103, v105 + bPos);
    v107 = v106;
    ++v99;
    v109 = &pStart[2 * v98++];
    *(v109 + 4) = v107;
    PartList = v12->PartList;
  }
  while (v98 != 5);
  v110 = v6->pcpData;
  v111 = *hData;
  v113 = v110->m_Items[v99]->offset;
  PartList->pOkSmoke = GetEffPCPAgiFireballPart(v111, v113 + bPos);
  return effPCPAgiFireball2Create(pAFB2Param, v12);
}

// 0x1179530
void effPCPAgiFireball2Delete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  void *monitor;
  void *v11;
  u32 *v14;
  Il2CppObject *v16[3];
  Il2CppObject *hDataa;

  hDataa = 0;
  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPAgiFireball2_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPAgiFireball2_tag, v16);
      if ((v16[0] & 1) != 0)
        v6 = v16[2];
      else
        v6 = v16 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  monitor = v3[1].monitor;
  hDataa = *(monitor + 4);
  effPCPAgiFireballDelete(&hDataa);
  v11 = v3[1].monitor;
  hDataa = *(v11 + 5);
  effPCPAgiFireballDelete(&hDataa);
  v14 = v3[1].monitor;
  hDataa = *(v14 + 6);
  effPCPAgiFireballDelete(&hDataa);
}

// 0x1179700
void effPCPAgiFireball2Draw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  const char *name;
  void *monitor;
  const char *v12;
  void *v13;
  const char *v16;
  u32 *v18;
  Il2CppObject *v20[3];
  Il2CppObject *hDataa;

  hDataa = 0;
  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPAgiFireball2_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPAgiFireball2_tag, v20);
      if ((v20[0] & 1) != 0)
        v6 = v20[2];
      else
        v6 = v20 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  name = v3[1].klass->_1.name;
  if (SLODWORD(v3[2].klass) >= *(name + 8))
  {
    monitor = v3[1].monitor;
    hDataa = *(monitor + 4);
    effPCPAgiFireballDraw(&hDataa);
  }
  v12 = v3[1].klass->_1.name;
  if (SLODWORD(v3[2].klass) >= *(v12 + 9))
  {
    v13 = v3[1].monitor;
    hDataa = *(v13 + 5);
    effPCPAgiFireballDraw(&hDataa);
  }
  v16 = v3[1].klass->_1.name;
  if (SLODWORD(v3[2].klass) >= *(v16 + 10))
  {
    v18 = v3[1].monitor;
    hDataa = *(v18 + 6);
    effPCPAgiFireballDraw(&hDataa);
  }
  ++LODWORD(v3[2].klass);
}

// 0x1179bd0
void effPCPAgiFireball2SetColor(void **hData, u32 abgr) {
  u32 v3;
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u32 *monitor;
  u32 *v14;
  u64 *v18;
  Il2CppObject *v20;
  u64 v21[3];

  v3 = abgr;
  v20 = 0;
  v5 = *hData;
  if (v5)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPAgiFireball2_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPAgiFireball2_tag, v21);
      if ((v21[0] & 1) != 0)
        v8 = v21[2];
      else
        v8 = v21 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  monitor = v5[1].monitor;
  v20 = *(monitor + 4);
  effPCPAgiFireballSetColor(&v20, v3);
  v14 = v5[1].monitor;
  v20 = *(v14 + 5);
  effPCPAgiFireballSetColor(&v20, v3);
  v18 = v5[1].monitor;
  v20 = v18[6];
  effPCPAgiFireballSetColor(&v20, v3);
}

// 0x11799b0
void effPCPAgiFireball2SetPosition(void **hData, sdfVector4_t pPos) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  Il2CppObject *v8;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  void *monitor;
  void *v16;
  u32 *v19;
  Il2CppObject *v21[3];
  Il2CppObject *hDataa;
  UnityEngine_Vector4_o v23;
  UnityEngine_Vector4_o v24;
  UnityEngine_Vector4_o v25;

  w = pPos.w;
  z = pPos.z;
  y = pPos.y;
  x = pPos.x;
  hDataa = 0;
  v8 = *hData;
  if (v8)
  {
    klass = v8->klass;
    if (v8->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPAgiFireball2_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPAgiFireball2_tag, v21);
      if ((v21[0] & 1) != 0)
        v11 = v21[2];
      else
        v11 = v21 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  monitor = v8[1].monitor;
  hDataa = *(monitor + 4);
  v23.x = x;
  v23.y = y;
  v23.z = z;
  v23.w = w;
  effPCPAgiFireballSetPosition(&hDataa, v23);
  v16 = v8[1].monitor;
  hDataa = *(v16 + 5);
  v24.x = x;
  v24.y = y;
  v24.z = z;
  v24.w = w;
  effPCPAgiFireballSetPosition(&hDataa, v24);
  v19 = v8[1].monitor;
  hDataa = *(v19 + 6);
  v25.x = x;
  v25.y = y;
  v25.z = z;
  v25.w = w;
  effPCPAgiFireballSetPosition(&hDataa, v25);
}

// 0x1179db0
void effPCPAgiFireball2SetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
  UnityEngine_Matrix4x4_o *v3;
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u32 *monitor;
  s64 v12;
  s64 v13;
  s64 v14;
  s64 v15;
  s64 v16;
  s64 v17;
  u32 *v20;
  s64 v22;
  s64 v23;
  s64 v24;
  s64 v25;
  s64 v26;
  s64 v27;
  u64 *v30;
  s64 v32;
  s64 v33;
  s64 v34;
  s64 v35;
  s64 v36;
  s64 v37;
  UnityEngine_Matrix4x4_o v38;
  UnityEngine_Matrix4x4_o v39;
  Il2CppObject *v40;

  v3 = pMatrix;
  v40 = 0;
  v5 = *hData;
  if (v5)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPAgiFireball2_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPAgiFireball2_tag, &v39);
      if ((LOBYTE(v39.m00) & 1) != 0)
        v8 = *&v39.m01;
      else
        v8 = &v39.m00 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  monitor = v5[1].monitor;
  v40 = *(monitor + 4);
  v12 = *&v3->m00;
  v13 = *&v3->m20;
  v14 = *&v3->m21;
  *&v39.m01 = *&v3->m01;
  *&v39.m21 = v14;
  *&v39.m00 = v12;
  *&v39.m20 = v13;
  v15 = *&v3->m23;
  v16 = *&v3->m02;
  v17 = *&v3->m22;
  *&v39.m03 = *&v3->m03;
  *&v39.m23 = v15;
  *&v39.m02 = v16;
  *&v39.m22 = v17;
  v38 = v39;
  effPCPAgiFireballSetRotateMatrix(&v40, &v38);
  v20 = v5[1].monitor;
  v40 = *(v20 + 5);
  v22 = *&v3->m00;
  v23 = *&v3->m20;
  v24 = *&v3->m21;
  *&v39.m01 = *&v3->m01;
  *&v39.m21 = v24;
  *&v39.m00 = v22;
  *&v39.m20 = v23;
  v25 = *&v3->m02;
  v26 = *&v3->m22;
  v27 = *&v3->m23;
  *&v39.m03 = *&v3->m03;
  *&v39.m23 = v27;
  *&v39.m02 = v25;
  *&v39.m22 = v26;
  v38 = v39;
  effPCPAgiFireballSetRotateMatrix(&v40, &v38);
  v30 = v5[1].monitor;
  v40 = v30[6];
  v32 = *&v3->m00;
  v33 = *&v3->m20;
  v34 = *&v3->m21;
  *&v39.m01 = *&v3->m01;
  *&v39.m21 = v34;
  *&v39.m00 = v32;
  *&v39.m20 = v33;
  v35 = *&v3->m02;
  v36 = *&v3->m22;
  v37 = *&v3->m23;
  *&v39.m03 = *&v3->m03;
  *&v39.m23 = v37;
  *&v39.m02 = v35;
  *&v39.m22 = v36;
  v38 = v39;
  effPCPAgiFireballSetRotateMatrix(&v40, &v38);
}

// 0x1175790
effPCPAgiFireball_tag *effPCPAgiFireballCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 *v10;
  Il2CppClass *v11;
  effPCPAgiFireball_tag_o *v15;
  u64 v16[3];

  v15 = 0;
  v5 = *hData;
  if (v5)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPAgiFireball_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPAgiFireball_tag, v16);
      if ((v16[0] & 1) != 0)
        v8 = v16[2];
      else
        v8 = v16 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = Allocate(effPCPAgiFireball_tag);
  _ctor(v10, 0);
  v15 = v10;
  Clear(v10, 0);
  v11 = v5[7].klass;
  *(v10 + 30) = 0;
  v10[14] = v11;
  v10[16] = 2155905152LL;
  SDF_VU0__STOREIDENTITY((v10 + 2), 0);
  effPCPAgiFireballCopySub(&v15, v5);
  v10[23] = 0;
  return v10;
}

// 0x1174c40
void effPCPAgiFireballCopySub(effPCPAgiFireball_tag **pPCPAgiFireball, effPCPAgiFireball_tag *pPCPAgiFireballSrc) {
  effPCPAgiFireball_tag_o *v5;
  struct effPartHandle_t_array *hAttach;
  struct effPartHandle_t_array *v8;
  s64 *v10;
  s64 *v12;
  struct effPartHandle_t_array *v14;
  struct effPartHandle_t_array *v15;
  s64 *v17;
  s64 *v19;
  struct effPartHandle_t_array *v21;
  struct effPartHandle_t_array *v22;
  s64 *v24;
  s64 *v26;
  struct effPartHandle_t_array *v28;
  struct effPartHandle_t_array *v29;
  s64 *v31;
  s64 *v33;
  struct effPartHandle_t_array *v35;
  struct effPartHandle_t_array *v36;
  s64 *v38;
  s64 *v40;
  u64 i;
  effPCPAgiFireball_tag_o *v43;
  struct System_Int32_array *TrackCount;
  struct System_Int32_array *v46;
  s32 motion_f;
  u32 *v49;
  s32 v50;
  u64 *v51;
  u32 v52;
  u32 *phTrack;
  s64 *v55;
  s64 *v57;
  struct effPartHandle_t_array_array *v59;
  Il2CppClass **v61;
  struct effPartHandle_t_array_array *v62;
  Il2CppClass *v63;
  effPartHandle_t_array *v65;
  s64 *v67;
  s64 *v68;
  struct sdfMemHandle_t_array *hTrackMem;
  s64 v75;
  struct effPartHandle_t_array_array *v76;
  effPartHandle_t_array *v78;
  Il2CppClass **v80;
  struct effPartHandle_t_array *hStart;
  struct effPartHandle_t_array *v82;
  s64 *v84;
  s64 *v86;
  struct effPartHandle_t_array *v88;
  struct effPartHandle_t_array *v89;
  s64 *v91;
  s64 *v93;
  struct effPartHandle_t_array *v95;
  struct effPartHandle_t_array *v96;
  s64 *v98;
  s64 *v100;
  struct effPartHandle_t_array *v102;
  struct effPartHandle_t_array *v103;
  s64 *v105;
  s64 *v107;
  struct effPartHandle_t_array *v109;
  struct effPartHandle_t_array *v110;
  s64 *v112;
  s64 *v114;
  effPCPAgiFireball_tag_o *v116;
  effPartHandle_t_o **p_hOkSmoke;

  v5 = *pPCPAgiFireball;
  v5->hHelper = dds3EffectPartCopy(&pPCPAgiFireballSrc->hHelper, 0, 0);
  hAttach = (*pPCPAgiFireball)->hAttach;
  v8 = pPCPAgiFireballSrc->hAttach;
  else if (!LODWORD(v8->max_length))
  {
    goto LABEL_9;
  }
  v10 = dds3EffectPartCopy(v8->m_Items, 0, 0);
  v12 = v10;
  hAttach->m_Items[0] = v12;
  v14 = (*pPCPAgiFireball)->hAttach;
  v15 = pPCPAgiFireballSrc->hAttach;
  else if ((v15->max_length & 0xFFFFFFFE) == 0)
  {
    goto LABEL_17;
  }
  v17 = dds3EffectPartCopy(&v15->m_Items[1], 0, 0);
  v19 = v17;
  v14->m_Items[1] = v19;
  v21 = (*pPCPAgiFireball)->hAttach;
  v22 = pPCPAgiFireballSrc->hAttach;
  else if (LODWORD(v22->max_length) <= 2uLL)
  {
    goto LABEL_25;
  }
  v24 = dds3EffectPartCopy(&v22->m_Items[2], 0, 0);
  v26 = v24;
  v21->m_Items[2] = v26;
  v28 = (*pPCPAgiFireball)->hAttach;
  v29 = pPCPAgiFireballSrc->hAttach;
  else if ((v29->max_length & 0xFFFFFFFC) == 0)
  {
    goto LABEL_33;
  }
  v31 = dds3EffectPartCopy(&v29->m_Items[3], 0, 0);
  v33 = v31;
  v28->m_Items[3] = v33;
  v35 = (*pPCPAgiFireball)->hAttach;
  v36 = pPCPAgiFireballSrc->hAttach;
  else if (LODWORD(v36->max_length) <= 4uLL)
  {
    goto LABEL_41;
  }
  v38 = dds3EffectPartCopy(&v36->m_Items[4], 0, 0);
  v40 = v38;
  v35->m_Items[4] = v40;
  (*pPCPAgiFireball)->motion_f = pPCPAgiFireballSrc->motion_f;
  for (i = 0; i != 3; ++i)
  {
    while (1)
    {
      v43 = *pPCPAgiFireball;
      TrackCount = (*pPCPAgiFireball)->param->TrackCount;
      if (TrackCount->m_Items[i] >= 1)
        break;
      hTrackMem = v43->hTrackMem;
      hTrackMem->m_Items[i++] = 0;
      if (i == 3)
        goto LABEL_90;
    }
    v46 = v43->param->TrackCount;
    motion_f = v43->motion_f;
    v49 = v43->hTrackMem;
    v50 = v46->m_Items[i];
    v51 = Allocate(sdfMemHandle_t);
    sdfMemHandle_t___ctor(v51);
    v52 = v50 * motion_f;
    *&v49[2 * i + 8] = v51;
    phTrack = (*pPCPAgiFireball)->phTrack;
    v55 = NewSpecific(effPartHandle_t, v52);
    v57 = v55;
    *&phTrack[2 * i + 8] = v57;
    v59 = (*pPCPAgiFireball)->phTrack;
    v61 = &v59->obj.klass + i;
    v62 = pPCPAgiFireballSrc->phTrack;
    v63 = v61[4];
    v65 = v62->m_Items[i];
    else if (!LODWORD(v65->max_length))
    {
LABEL_69:
    }
    v67 = dds3EffectPartCopy(v65->m_Items, 0, 0);
    v68 = v67;
    v63->_1.byval_arg.data = v68;
    if (v52 >= 2)
    {
      v75 = 0;
      do
      {
        v76 = (*pPCPAgiFireball)->phTrack;
        v78 = v76->m_Items[i];
        v80 = &v78->obj.klass + v75++;
        v80[5] = 0;
      }
      while (v52 - 1LL != v75);
    }
  }
LABEL_90:
  hStart = pPCPAgiFireballSrc->hStart;
  v82 = (*pPCPAgiFireball)->hStart;
  else if (!LODWORD(hStart->max_length))
  {
    goto LABEL_93;
  }
  v84 = dds3EffectPartCopy(hStart->m_Items, 0, 0);
  v86 = v84;
  v82->m_Items[0] = v86;
  v88 = (*pPCPAgiFireball)->hStart;
  v89 = pPCPAgiFireballSrc->hStart;
  else if ((v89->max_length & 0xFFFFFFFE) == 0)
  {
    goto LABEL_101;
  }
  v91 = dds3EffectPartCopy(&v89->m_Items[1], 0, 0);
  v93 = v91;
  v88->m_Items[1] = v93;
  v95 = (*pPCPAgiFireball)->hStart;
  v96 = pPCPAgiFireballSrc->hStart;
  else if (LODWORD(v96->max_length) <= 2uLL)
  {
    goto LABEL_109;
  }
  v98 = dds3EffectPartCopy(&v96->m_Items[2], 0, 0);
  v100 = v98;
  v95->m_Items[2] = v100;
  v102 = (*pPCPAgiFireball)->hStart;
  v103 = pPCPAgiFireballSrc->hStart;
  else if ((v103->max_length & 0xFFFFFFFC) == 0)
  {
    goto LABEL_117;
  }
  v105 = dds3EffectPartCopy(&v103->m_Items[3], 0, 0);
  v107 = v105;
  v102->m_Items[3] = v107;
  v109 = (*pPCPAgiFireball)->hStart;
  v110 = pPCPAgiFireballSrc->hStart;
  else if (LODWORD(v110->max_length) <= 4uLL)
  {
    goto LABEL_125;
  }
  v112 = dds3EffectPartCopy(&v110->m_Items[4], 0, 0);
  v114 = v112;
  v109->m_Items[4] = v114;
  v116 = *pPCPAgiFireball;
  p_hOkSmoke = &pPCPAgiFireballSrc->hOkSmoke;
  v116->hOkSmoke = dds3EffectPartCopy(p_hOkSmoke, 0, 0);
}

// 0x1173560
effPCPAgiFireball_tag *effPCPAgiFireballCreate(effPCPAgiFireballParam_t *pParam, effPCPAgiFireballPartList_t *pPart) {
  u64 *v5;
  Il2CppObject *pHelper;
  struct System_Object_array *pAttach;
  u64 v9;
  s64 *v11;
  s64 *v12;
  struct System_Object_array *v14;
  u64 v15;
  s64 *v17;
  s64 *v18;
  struct System_Object_array *v20;
  u64 v21;
  s64 *v23;
  s64 *v24;
  struct System_Object_array *v26;
  u64 v27;
  s64 *v29;
  s64 *v30;
  struct System_Object_array *v32;
  u64 v33;
  s64 *v35;
  s64 *v36;
  Il2CppObject *Handle;
  dds3ModelHandle_t_o *v40;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v43;
  s64 *v44;
  Il2CppClass *v45;
  Il2CppClass *v46;
  Il2CppClass *v47;
  void *v48;
  void *v49;
  void *v50;
  void *v51;
  u64 i;
  s64 v55;
  s64 v57;
  s32 v58;
  u32 *v60;
  s32 v61;
  u64 *v62;
  u32 v63;
  u32 *v65;
  s64 *v66;
  s64 *v68;
  u64 v70;
  u64 v72;
  struct System_Object_array *pTrack;
  s64 v74;
  Il2CppObject *v76;
  s64 *v77;
  s64 *v78;
  u64 v79;
  s64 v85;
  u64 v86;
  s64 v88;
  s64 v90;
  struct System_Object_array *pStart;
  u64 v92;
  Il2CppObject *v93;
  s64 *v95;
  s64 *v96;
  struct System_Object_array *v98;
  u64 v99;
  s64 *v101;
  s64 *v102;
  struct System_Object_array *v104;
  u64 v105;
  s64 *v107;
  s64 *v108;
  struct System_Object_array *v110;
  u64 v111;
  s64 *v113;
  s64 *v114;
  struct System_Object_array *v116;
  u64 v117;
  s64 *v119;
  s64 *v120;
  UnityEngine_Matrix4x4_o v133;
  Il2CppObject *hData;

  hData = 0;
  v5 = Allocate(effPCPAgiFireball_tag);
  _ctor(v5, 0);
  Clear(v5, 0);
  v5[14] = pParam;
  *(v5 + 30) = 0;
  v5[16] = 2155905152LL;
  SDF_VU0__STOREIDENTITY((v5 + 2), 0);
  pHelper = pPart->pHelper;
  v5[17] = dds3EffectPartCreate(3u, pHelper, 0, 0);
  pAttach = pPart->pAttach;
  v9 = v5[18];
  v11 = dds3EffectPartCreate(0, pAttach->m_Items[0], 0, 0);
  v12 = v11;
  *(v9 + 32) = v12;
  v14 = pPart->pAttach;
  v15 = v5[18];
  v17 = dds3EffectPartCreate(0, v14->m_Items[1], 0, 0);
  v18 = v17;
  *(v15 + 40) = v18;
  v20 = pPart->pAttach;
  v21 = v5[18];
  v23 = dds3EffectPartCreate(0, v20->m_Items[2], 0, 0);
  v24 = v23;
  *(v21 + 48) = v24;
  v26 = pPart->pAttach;
  v27 = v5[18];
  v29 = dds3EffectPartCreate(0, v26->m_Items[3], 0, 0);
  v30 = v29;
  *(v27 + 56) = v30;
  v32 = pPart->pAttach;
  v33 = v5[18];
  v35 = dds3EffectPartCreate(3u, v32->m_Items[4], 0, 0);
  v36 = v35;
  *(v33 + 64) = v36;
  Handle = dds3EffectPartGetHandle(v5 + 17);
  v40 = Handle;
  if (Handle)
  {
    klass = Handle->klass;
    if (Handle->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, &v133);
      if ((LOBYTE(v133.m00) & 1) != 0)
        v43 = *&v133.m01;
      else
        v43 = &v133.m00 + 1;
      v44 = sub_8C4940(v43);
    }
  }
  hData = Handle;
  v45 = Handle[4].klass;
  get_identity(&v133, 0);
  v47 = *&v133.m00;
  v46 = *&v133.m20;
  v48 = *&v133.m21;
  v45->_1.parent = *&v133.m01;
  v45->_1.generic_class = v48;
  v45->_1.castClass = v47;
  v45->_1.declaringType = v46;
  v50 = *&v133.m02;
  v49 = *&v133.m22;
  v51 = *&v133.m23;
  v45->_1.klass = *&v133.m03;
  v45->_1.fields = v51;
  v45->_1.typeDefinition = v50;
  v45->_1.interopData = v49;
  dds3EffectPartModelDraw(&hData);
  *(v5 + 31) = mdlGetMotionLengthUnity(v40);
  dds3EffectPartModelDelete(&hData);
  for (i = 0; i != 3; ++i)
  {
    while (1)
    {
      v55 = *(v5[14] + 48);
      if (*(v55 + 4 * i + 32) < 1)
        break;
      v57 = *(v5[14] + 48);
      v58 = *(v5 + 31);
      v60 = v5[22];
      v61 = *(v57 + 4 * i + 32);
      v62 = Allocate(sdfMemHandle_t);
      sdfMemHandle_t___ctor(v62);
      v63 = v61 * v58;
      *&v60[2 * i + 8] = v62;
      v65 = v5[19];
      v66 = NewSpecific(effPartHandle_t, v63);
      v68 = v66;
      *&v65[2 * i + 8] = v68;
      v70 = v5[19];
      v72 = v70 + 8 * i;
      pTrack = pPart->pTrack;
      v74 = *(v72 + 32);
      v76 = pTrack->m_Items[i];
      v77 = dds3EffectPartCreate(0, v76, 0, 0);
      v78 = v77;
      *(v74 + 32) = v78;
      if (v63 >= 2)
      {
        v85 = 0;
        do
        {
          v86 = v5[19];
          v88 = *(v86 + 8 * i + 32);
          v90 = v88 + 8 * v85++;
          *(v90 + 40) = 0;
        }
        while (v63 - 1LL != v85);
      }
      if (++i == 3)
        goto LABEL_90;
    }
    v79 = v5[22];
    *(v79 + 8 * i + 32) = 0;
  }
LABEL_90:
  pStart = pPart->pStart;
  v92 = v5[20];
  v93 = pStart->m_Items[0];
  v95 = dds3EffectPartCreate(0, v93, 0, 0);
  v96 = v95;
  *(v92 + 32) = v96;
  v98 = pPart->pStart;
  v99 = v5[20];
  v101 = dds3EffectPartCreate(0, v98->m_Items[1], 0, 0);
  v102 = v101;
  *(v99 + 40) = v102;
  v104 = pPart->pStart;
  v105 = v5[20];
  v107 = dds3EffectPartCreate(0, v104->m_Items[2], 0, 0);
  v108 = v107;
  *(v105 + 48) = v108;
  v110 = pPart->pStart;
  v111 = v5[20];
  v113 = dds3EffectPartCreate(0, v110->m_Items[3], 0, 0);
  v114 = v113;
  *(v111 + 56) = v114;
  v116 = pPart->pStart;
  v117 = v5[20];
  v119 = dds3EffectPartCreate(6u, v116->m_Items[4], 0, 0);
  v120 = v119;
  *(v117 + 64) = v120;
  v5[21] = dds3EffectPartCreate(0, pPart->pOkSmoke, 0, 0);
  return v5;
}

// 0x1174090
effPCPAgiFireball_tag *effPCPAgiFireballCreatePCF(void **hData, s32 bPos, bool tbldata) {
  dds3EffectPCPData_t_o *v6;
  Il2CppObject *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  effPCPAgiFireballPartList_t_o *v12;
  struct dds3EffectPCPData_Part_t_array *pcpData;
  Il2CppObject *v15;
  u32 offset;
  Il2CppObject *DataUnityOffSet;
  effPCPAgiFireballParam_t_o *v21;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v24;
  s64 *v25;
  struct dds3EffectPCPData_Part_t_array *v26;
  Il2CppObject *v27;
  u32 v29;
  struct dds3EffectPCPData_Part_t_array *v32;
  struct System_Object_array *pAttach;
  Il2CppObject *v34;
  u32 v36;
  s64 *EffPCPAgiFireballPart;
  s64 *v40;
  struct dds3EffectPCPData_Part_t_array *v42;
  struct System_Object_array *v43;
  Il2CppObject *v44;
  u32 v46;
  s64 *v47;
  s64 *v50;
  struct dds3EffectPCPData_Part_t_array *v52;
  struct System_Object_array *v53;
  Il2CppObject *v54;
  u32 v56;
  s64 *v57;
  s64 *v60;
  struct dds3EffectPCPData_Part_t_array *v62;
  struct System_Object_array *v63;
  Il2CppObject *v64;
  u32 v66;
  s64 *v67;
  s64 *v70;
  struct dds3EffectPCPData_Part_t_array *v72;
  struct System_Object_array *v73;
  Il2CppObject *v74;
  u32 v76;
  s64 *v77;
  s64 *v80;
  struct dds3EffectPCPData_Part_t_array *v82;
  struct System_Object_array *pTrack;
  Il2CppObject *v84;
  u32 v86;
  s64 *v87;
  s64 *v89;
  struct dds3EffectPCPData_Part_t_array *v91;
  struct System_Object_array *v92;
  s64 *v94;
  s64 *v96;
  struct dds3EffectPCPData_Part_t_array *v98;
  struct System_Object_array *v99;
  s64 *v101;
  s64 *v104;
  struct dds3EffectPCPData_Part_t_array *v106;
  struct System_Object_array *pStart;
  Il2CppObject *v108;
  u32 v110;
  s64 *v111;
  s64 *v114;
  struct dds3EffectPCPData_Part_t_array *v116;
  struct System_Object_array *v117;
  Il2CppObject *v118;
  u32 v120;
  s64 *v121;
  s64 *v124;
  struct dds3EffectPCPData_Part_t_array *v126;
  struct System_Object_array *v127;
  Il2CppObject *v128;
  u32 v130;
  s64 *v131;
  s64 *v134;
  struct dds3EffectPCPData_Part_t_array *v136;
  struct System_Object_array *v137;
  Il2CppObject *v138;
  u32 v140;
  s64 *v141;
  s64 *v144;
  struct dds3EffectPCPData_Part_t_array *v146;
  struct System_Object_array *v147;
  Il2CppObject *v148;
  u32 v150;
  s64 *v151;
  s64 *v154;
  struct dds3EffectPCPData_Part_t_array *v156;
  Il2CppObject *v157;
  u32 v159;
  u64 v175[2];
  char *v176;
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
      sub_8FC2C0(v7->klass->_1.element_class, v8, v175);
      if ((v175[0] & 1) != 0)
        v10 = v176;
      else
        v10 = v175 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v6, Interface, &pos);
  v12 = Allocate(effPCPAgiFireballPartList_t);
  effPCPAgiFireballPartList_t___ctor(v12);
  pcpData = v6->pcpData;
  v15 = *hData;
  offset = pcpData->m_Items[0]->offset;
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v15, offset + bPos, 17);
  v21 = DataUnityOffSet;
  if (DataUnityOffSet)
  {
    klass = DataUnityOffSet->klass;
    if (DataUnityOffSet->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPAgiFireballParam_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPAgiFireballParam_t, v175);
      if ((v175[0] & 1) != 0)
        v24 = v176;
      else
        v24 = v175 + 1;
      v25 = sub_8C4940(v24);
    }
  }
  v26 = v6->pcpData;
  v27 = *hData;
  v29 = v26->m_Items[1]->offset;
  v12->pHelper = GetEffPCPAgiFireballPart(v27, v29 + bPos);
  v32 = v6->pcpData;
  pAttach = v12->pAttach;
  v34 = *hData;
  v36 = v32->m_Items[2]->offset;
  EffPCPAgiFireballPart = GetEffPCPAgiFireballPart(v34, v36 + bPos);
  v40 = EffPCPAgiFireballPart;
  pAttach->m_Items[0] = v40;
  v42 = v6->pcpData;
  v43 = v12->pAttach;
  v44 = *hData;
  v46 = v42->m_Items[3]->offset;
  v47 = GetEffPCPAgiFireballPart(v44, v46 + bPos);
  v50 = v47;
  v43->m_Items[1] = v50;
  v52 = v6->pcpData;
  v53 = v12->pAttach;
  v54 = *hData;
  v56 = v52->m_Items[4]->offset;
  v57 = GetEffPCPAgiFireballPart(v54, v56 + bPos);
  v60 = v57;
  v53->m_Items[2] = v60;
  v62 = v6->pcpData;
  v63 = v12->pAttach;
  v64 = *hData;
  v66 = v62->m_Items[5]->offset;
  v67 = GetEffPCPAgiFireballPart(v64, v66 + bPos);
  v70 = v67;
  v63->m_Items[3] = v70;
  v72 = v6->pcpData;
  v73 = v12->pAttach;
  v74 = *hData;
  v76 = v72->m_Items[6]->offset;
  v77 = GetEffPCPAgiFireballPart(v74, v76 + bPos);
  v80 = v77;
  v73->m_Items[4] = v80;
  v82 = v6->pcpData;
  pTrack = v12->pTrack;
  v84 = *hData;
  v86 = v82->m_Items[7]->offset;
  v87 = GetEffPCPAgiFireballPart(v84, v86 + bPos);
  v89 = v87;
  pTrack->m_Items[0] = v89;
  v91 = v6->pcpData;
  v92 = v12->pTrack;
  v94 = GetEffPCPAgiFireballPart(*hData, v91->m_Items[8]->offset + bPos);
  v96 = v94;
  v92->m_Items[1] = v96;
  v98 = v6->pcpData;
  v99 = v12->pTrack;
  v101 = GetEffPCPAgiFireballPart(*hData, v98->m_Items[9]->offset + bPos);
  v104 = v101;
  v99->m_Items[2] = v104;
  v106 = v6->pcpData;
  pStart = v12->pStart;
  v108 = *hData;
  v110 = v106->m_Items[10]->offset;
  v111 = GetEffPCPAgiFireballPart(v108, v110 + bPos);
  v114 = v111;
  pStart->m_Items[0] = v114;
  v116 = v6->pcpData;
  v117 = v12->pStart;
  v118 = *hData;
  v120 = v116->m_Items[11]->offset;
  v121 = GetEffPCPAgiFireballPart(v118, v120 + bPos);
  v124 = v121;
  v117->m_Items[1] = v124;
  v126 = v6->pcpData;
  v127 = v12->pStart;
  v128 = *hData;
  v130 = v126->m_Items[12]->offset;
  v131 = GetEffPCPAgiFireballPart(v128, v130 + bPos);
  v134 = v131;
  v127->m_Items[2] = v134;
  v136 = v6->pcpData;
  v137 = v12->pStart;
  v138 = *hData;
  v140 = v136->m_Items[13]->offset;
  v141 = GetEffPCPAgiFireballPart(v138, v140 + bPos);
  v144 = v141;
  v137->m_Items[3] = v144;
  v146 = v6->pcpData;
  v147 = v12->pStart;
  v148 = *hData;
  v150 = v146->m_Items[14]->offset;
  v151 = GetEffPCPAgiFireballPart(v148, v150 + bPos);
  v154 = v151;
  v147->m_Items[4] = v154;
  v156 = v6->pcpData;
  v157 = *hData;
  v159 = v156->m_Items[15]->offset;
  v12->pOkSmoke = GetEffPCPAgiFireballPart(v157, v159 + bPos);
  return effPCPAgiFireballCreate(v21, v12);
}

// 0x1175900
void effPCPAgiFireballDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppClass *v9;
  Il2CppClass *v12;
  Il2CppClass *v15;
  Il2CppClass *v18;
  Il2CppClass *v21;
  u64 i;
  u32 *data;
  u32 v27;
  u64 v28;
  s64 v29;
  s64 v30;
  u64 *monitor;
  u64 *v33;
  s64 v35;
  u64 *v37;
  s64 v39;
  Il2CppClass *v41;
  void **v43;
  Il2CppClass *v44;
  Il2CppClass *v47;
  Il2CppClass *v50;
  Il2CppClass *v53;
  Il2CppClass *v56;
  u64 v59[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPAgiFireball_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPAgiFireball_tag, v59);
      if ((v59[0] & 1) != 0)
        v6 = v59[2];
      else
        v6 = v59 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  if (!v3[11].monitor)
  {
    dds3EffectPartDelete(&v3[8].monitor);
    v9 = v3[9].klass;
    else if (!LODWORD(v9->_1.namespaze))
    {
      goto LABEL_17;
    }
    dds3EffectPartDelete(&v9->_1.byval_arg);
    v12 = v3[9].klass;
    else if ((v12->_1.namespaze & 0xFFFFFFFE) == 0)
    {
      goto LABEL_21;
    }
    dds3EffectPartDelete(&v12->_1.byval_arg.bits);
    v15 = v3[9].klass;
    dds3EffectPartDelete(&v15->_1.this_arg);
    v18 = v3[9].klass;
    else if ((v18->_1.namespaze & 0xFFFFFFFC) == 0)
    {
      goto LABEL_30;
    }
    dds3EffectPartDelete(&v18->_1.this_arg.bits);
    v21 = v3[9].klass;
    dds3EffectPartDelete(&v21->_1.element_class);
    for (i = 0; i != 3; ++i)
    {
      data = v3[7].klass->_1.this_arg.data;
      v27 = data[i + 8] * HIDWORD(v3[7].monitor);
      if (v27)
      {
        v28 = 0;
        v29 = v27;
        v30 = 32;
        do
        {
          monitor = v3[9].monitor;
          if (monitor[i + 4])
          {
            v33 = v3[9].monitor;
            v35 = v33[i + 4];
            if (*(v35 + v30))
            {
              v37 = v3[9].monitor;
              v39 = v37[i + 4];
              else if (v28 >= *(v39 + 24))
              {
LABEL_56:
              }
              dds3EffectPartDelete((v39 + v30), 0);
            }
          }
          ++v28;
          v30 += 8;
        }
        while (v29 != v28);
      }
      v41 = v3[11].klass;
      v43 = &v41->_1.image + i;
      v43[4] = 0;
    }
    v44 = v3[10].klass;
    else if (!LODWORD(v44->_1.namespaze))
    {
      goto LABEL_65;
    }
    dds3EffectPartDelete(&v44->_1.byval_arg);
    v47 = v3[10].klass;
    else if ((v47->_1.namespaze & 0xFFFFFFFE) == 0)
    {
      goto LABEL_69;
    }
    dds3EffectPartDelete(&v47->_1.byval_arg.bits);
    v50 = v3[10].klass;
    dds3EffectPartDelete(&v50->_1.this_arg);
    v53 = v3[10].klass;
    else if ((v53->_1.namespaze & 0xFFFFFFFC) == 0)
    {
      goto LABEL_78;
    }
    dds3EffectPartDelete(&v53->_1.this_arg.bits);
    v56 = v3[10].klass;
    dds3EffectPartDelete(&v56->_1.element_class);
    dds3EffectPartDelete(&v3[10].monitor);
  }
}

// 0x1175ee0
void effPCPAgiFireballDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  effPCPAgiFireball_tag_o *v11;
  s32 frame;
  effPCPAgiFireball_tag_o *pCopySrc;
  struct effPCPAgiFireballParam_t_o *v14;
  s32 fade_out;
  s32 fade_in;
  f32 v17;
  f32 v18;
  struct effPartHandle_t_array *hAttach;
  f32 scale;
  struct effPartHandle_t_array *v23;
  f32 v24;
  struct effPartHandle_t_array *v27;
  f32 v28;
  struct effPartHandle_t_array *v31;
  f32 v32;
  struct effPartHandle_t_array *v35;
  f32 v36;
  struct effPCPAgiFireballParam_t_o *param;
  f32 v39;
  u32 v41;
  effPartHandle_t_o **p_hHelper;
  Il2CppObject *Handle;
  Il2CppObject *v45;
  Il2CppClass *v46;
  s64 v47;
  char *v48;
  s64 *v49;
  u32 type;
  effPartHandle_t_o **v51;
  struct effPCPAgiFireballParam_t_o *v52;
  f32 v53;
  f32 v54;
  f32 v55;
  f32 v56;
  struct effPCPAgiFireballParam_t_o *v61;
  f32 v62;
  f32 v66;
  f32 v67;
  f32 v68;
  effPartHandle_t_o **v71;
  struct effPCPAgiFireballParam_t_o *v72;
  f32 x;
  f32 y;
  f32 z;
  f32 w;
  f32 v81;
  effPartHandle_t_o **v82;
  f32 v83;
  struct effPCPAgiFireballParam_t_o *v84;
  f32 v85;
  f32 v86;
  f32 v87;
  effPartHandle_t_o **v91;
  f32 v92;
  f32 v93;
  f32 v94;
  f32 v95;
  f32 v96;
  f32 v97;
  f32 v98;
  f32 v99;
  UnityEngine_Matrix4x4_o *v100;
  effPartHandle_t_o **v101;
  sdfModelRootNode_t_o *v103;
  u64 v104;
  s64 v105;
  effPCPAgiFireball_tag_o *v106;
  struct effPartHandle_t_array *v107;
  f32 v109;
  f32 v110;
  f32 v111;
  f32 v112;
  struct effPartHandle_t_array *v113;
  effPartHandle_t_o **v115;
  struct effPartHandle_t_array *v116;
  struct effPartHandle_t_array *v119;
  struct effPartHandle_t_array *v121;
  struct effPartHandle_t_array *hStart;
  f32 v124;
  f32 v125;
  f32 v126;
  f32 v127;
  s64 v129;
  s64 v130;
  s64 v131;
  struct effPartHandle_t_array *v132;
  s64 v133;
  s64 v134;
  s64 v135;
  struct effPartHandle_t_array *v138;
  f32 v139;
  f32 v140;
  f32 v141;
  f32 v142;
  s64 v144;
  s64 v145;
  s64 v146;
  struct effPartHandle_t_array *v147;
  s64 v148;
  s64 v149;
  s64 v150;
  struct effPartHandle_t_array *v153;
  f32 v154;
  f32 v155;
  f32 v156;
  f32 v157;
  s64 v159;
  s64 v160;
  s64 v161;
  struct effPartHandle_t_array *v162;
  s64 v163;
  s64 v164;
  s64 v165;
  struct effPartHandle_t_array *v168;
  f32 v169;
  f32 v170;
  f32 v171;
  f32 v172;
  s64 v174;
  s64 v175;
  s64 v176;
  struct effPartHandle_t_array *v177;
  s64 v178;
  s64 v179;
  s64 v180;
  struct effPartHandle_t_array *v183;
  f32 v184;
  f32 v185;
  f32 v186;
  f32 v187;
  s64 v189;
  s64 v190;
  s64 v191;
  struct effPartHandle_t_array *v192;
  s64 v193;
  s64 v194;
  s64 v195;
  struct effPartHandle_t_array *v197;
  u32 abgr;
  struct effPartHandle_t_array *v200;
  struct effPartHandle_t_array *v203;
  u32 v204;
  struct effPartHandle_t_array *v206;
  struct effPartHandle_t_array *v209;
  u32 v210;
  struct effPartHandle_t_array *v212;
  struct effPartHandle_t_array *v215;
  u32 v216;
  struct effPartHandle_t_array *v218;
  struct effPartHandle_t_array *v221;
  u32 v222;
  struct effPartHandle_t_array *v224;
  effPCPAgiFireball_tag_o *v226;
  s32 OkSmokeFrame;
  f32 v228;
  f32 v229;
  f32 v230;
  f32 v231;
  effPartHandle_t_o **p_hOkSmoke;
  effPartHandle_t_o **v233;
  u32 v234;
  u64 v235;
  struct System_Int32_array *TrackCount;
  struct System_Int32_array *v238;
  u32 v240;
  struct System_Int32_array *v241;
  s32 v242;
  s32 v244;
  s64 i;
  struct System_Int32_array *v249;
  struct effPartHandle_t_array_array *phTrack;
  effPartHandle_t_array *v253;
  u32 v254;
  s64 v255;
  struct effPartHandle_t_array_array *v257;
  effPartHandle_t_array *v259;
  effPartHandle_t_array *v260;
  s64 *v262;
  s64 *v264;
  struct effPCPAgiFireballParam_t_o *v266;
  struct System_Single_array *TrackScale;
  f32 v268;
  f32 *v270;
  struct System_Single_array *TrackScale_r;
  f32 v272;
  f32 v274;
  f32 v275;
  struct effPartHandle_t_array_array *v276;
  f32 v277;
  effPartHandle_t_array *v279;
  struct effPartHandle_t_array_array *v284;
  f32 v286;
  f32 v287;
  f32 v288;
  f32 v289;
  effPartHandle_t_array *v290;
  struct effPartHandle_t_array_array *v292;
  effPartHandle_t_array *v294;
  u64 v297;
  s64 v298;
  s64 v299;
  struct effPartHandle_t_array_array *v301;
  effPartHandle_t_array *v303;
  struct effPartHandle_t_array_array *v305;
  u32 *v307;
  effPartHandle_t_array *v308;
  s64 *v310;
  s64 *v312;
  struct effPCPAgiFireballParam_t_o *v314;
  struct System_Single_array *v315;
  f32 v316;
  f32 *v318;
  struct System_Single_array *v319;
  f32 v320;
  f32 v322;
  f32 v323;
  struct effPartHandle_t_array_array *v324;
  f32 v325;
  effPartHandle_t_array *v327;
  struct effPartHandle_t_array_array *v329;
  effPartHandle_t_array *v331;
  s64 v332;
  s64 v333;
  s64 v334;
  s64 v335;
  s64 v336;
  s64 v337;
  struct effPartHandle_t_array_array *v339;
  effPartHandle_t_array *v341;
  s32 v355;
  s32 motion_f;
  UnityEngine_Matrix4x4_o v357;
  UnityEngine_Matrix4x4_o v358;
  UnityEngine_Matrix4x4_o v359;
  UnityEngine_Matrix4x4_o v360;
  UnityEngine_Matrix4x4_o v361;
  UnityEngine_Matrix4x4_o v362;
  u8 v363[64];
  UnityEngine_Matrix4x4_o v364;
  u8 dest[64];
  Il2CppObject *hDataa;
  nbFormation_t_o *pFormation;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o aTarget;
  UnityEngine_Vector4_o v370;
  UnityEngine_Vector4_o v371;
  UnityEngine_Vector4_o v372;
  UnityEngine_Matrix4x4_o aMatrix;
  u64 v374[2];
  effPCPAgiFireball_tag_o *pPCPAgiFireball;
  UnityEngine_Vector4_o v376;
  UnityEngine_Vector4_o v377;
  UnityEngine_Vector4_o pos;
  UnityEngine_Vector4_o v379;
  UnityEngine_Vector4_o v380;
  UnityEngine_Vector4_o v381;
  UnityEngine_Vector4_o v382;
  UnityEngine_Vector4_o v383;
  UnityEngine_Vector4_o v384;
  UnityEngine_Vector4_o v385;
  UnityEngine_Vector4_o v386;
  UnityEngine_Vector4_o v387;
  UnityEngine_Vector4_o v388;
  UnityEngine_Vector4_o v389;

  v374[1] = 0;
  pPCPAgiFireball = 0;
  *&v372.x = 0;
  *&v371.z = 0;
  *&v371.x = 0;
  *&v370.z = 0;
  *&v370.x = 0;
  *&aTarget.z = 0;
  *&aTarget.x = 0;
  *&p.z = 0;
  *&p.x = 0;
  pFormation = 0;
  hDataa = 0;
  v374[0] = 0;
  *&v372.z = 0;
  memset(&aMatrix, 0, sizeof(aMatrix));
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPAgiFireball_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPAgiFireball_tag, &v362);
      if ((LOBYTE(v362.m00) & 1) != 0)
        v6 = *&v362.m01;
      else
        v6 = &v362.m00 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  pPCPAgiFireball = *hData;
  sub_854690(v374, 0.0, 1.0, 0.0, 0.0);
  *&v371.z = 0;
  *&v371.x = 0;
  *&v370.z = 0;
  *&v370.x = 0;
  *&aTarget.z = 0;
  *&aTarget.x = 0;
  memset(&aMatrix, 0, sizeof(aMatrix));
  *&v372.x = 0;
  *&v372.z = 0;
  *&p.z = 0;
  *&p.x = 0;
  v8 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v8);
  v11 = pPCPAgiFireball;
  frame = pPCPAgiFireball->frame;
  pCopySrc = pPCPAgiFireball->pCopySrc;
  motion_f = pPCPAgiFireball->motion_f;
  if (pCopySrc)
  {
    effPCPAgiFireballCopySub(&pPCPAgiFireball, pCopySrc);
    v11 = pPCPAgiFireball;
    pPCPAgiFireball->pCopySrc = 0;
  }
  if (!frame)
  {
    hAttach = v11->hAttach;
    scale = v11->param->scale;
    else if (!LODWORD(hAttach->max_length))
    {
      goto LABEL_22;
    }
    dds3EffectPartSetScale(hAttach->m_Items, scale);
    v23 = pPCPAgiFireball->hAttach;
    v24 = pPCPAgiFireball->param->scale;
    else if ((v23->max_length & 0xFFFFFFFE) == 0)
    {
      goto LABEL_26;
    }
    dds3EffectPartSetScale(&v23->m_Items[1], v24);
    v27 = pPCPAgiFireball->hAttach;
    v28 = pPCPAgiFireball->param->scale;
    dds3EffectPartSetScale(&v27->m_Items[2], v28);
    v31 = pPCPAgiFireball->hAttach;
    v32 = pPCPAgiFireball->param->scale;
    else if ((v31->max_length & 0xFFFFFFFC) == 0)
    {
      goto LABEL_35;
    }
    dds3EffectPartSetScale(&v31->m_Items[3], v32);
    v35 = pPCPAgiFireball->hAttach;
    v36 = pPCPAgiFireball->param->scale;
    dds3EffectPartSetScale(&v35->m_Items[4], v36);
    v11 = pPCPAgiFireball;
    param = pPCPAgiFireball->param;
    fade_in = param->fade_in;
    fade_out = param->fade_out;
    if (fade_in <= 0)
      goto LABEL_42;
    goto LABEL_17;
  }
  v14 = v11->param;
  fade_in = v14->fade_in;
  fade_out = v14->fade_out;
  if (frame >= fade_in)
    goto LABEL_42;
LABEL_17:
  if (fade_in)
  {
    v17 = frame;
    v18 = fade_in;
LABEL_45:
    v39 = v17 / v18;
    goto LABEL_46;
  }
LABEL_42:
  v39 = 1.0;
  if (motion_f - frame <= fade_out)
  {
    v39 = 1.0;
    if (fade_out)
    {
      v17 = (motion_f - frame);
      v18 = fade_out;
      goto LABEL_45;
    }
  }
LABEL_46:
  v41 = effColorBlend(v11->abgr & 0xFFFFFF, v11->abgr, v39);
  p_hHelper = &pPCPAgiFireball->hHelper;
  Handle = dds3EffectPartGetHandle(p_hHelper);
  v45 = Handle;
  if (Handle)
  {
    v46 = Handle->klass;
    if (Handle->klass->_2.typeHierarchyDepth < v47
      || v46->_2.typeHierarchy[v47 - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(v46->_1.element_class, dds3ModelHandle_t, &v362);
      if ((LOBYTE(v362.m00) & 1) != 0)
        v48 = *&v362.m01;
      else
        v48 = &v362.m00 + 1;
      v49 = sub_8C4940(v48);
    }
  }
  type = pPCPAgiFireball->type;
  switch (type)
  {
    case 2u:
      v71 = &pPCPAgiFireball->hHelper;
      v72 = pPCPAgiFireball->param;
      x = v72->pos.x;
      y = v72->pos.y;
      z = v72->pos.z;
      w = v72->pos.w;
      v379.x = x;
      v379.y = y;
      v379.z = z;
      v379.w = w;
      dds3EffectPartSetPosition(v71, v379);
      if (effBTLSkillCheckRun())
      {
        pFormation = effBTLSkillGetInvokeFormation(0);
        effBTLModelGetSphereCenter(&pFormation);
        SDF_VU0__STOREVECTOR(&p);
        sub_854930(&p, 1u);
        sub_854930(&v372, 0);
        sub_854930(&v372, 1u);
        sub_854930(&v372, 2u);
        sub_854710(&pPCPAgiFireball->param->fields, 0);
        sub_854930(&aTarget, 0);
        sub_854930(&aTarget, 1u);
        sub_854710(&pPCPAgiFireball->param->fields, 2u);
        sub_854930(&aTarget, 2u);
        SDF_VU0__LOADVECTOR(aTarget);
        SDF_VU0__LOADVECTOR_B(p);
        SDF_VU0__COPYVECTOR_B_TO_C();
        SDF_VU0__SUBVECTOR();
        SDF_VU0__NORMALIZE();
        SDF_VU0__LOADVECTOR_B(v372);
        SDF_VU0__MULVECTOR();
        SDF_VU0__COPYVECTOR_C_TO_B();
        SDF_VU0__ADDVECTOR();
        SDF_VU0__STOREVECTOR(&p);
        SDF_VU0__LOADVECTOR_B(aTarget);
        SDF_VU0__SUBVECTOR();
        v81 = SDF_VU0__GETLENGTH();
        v82 = &pPCPAgiFireball->hHelper;
        v83 = v81;
        dds3EffectPartSetScale(v82, v83 / 400.0);
        v84 = pPCPAgiFireball->param;
        v85 = p.y;
        pos = v84->pos;
        v86 = p.x;
        v67 = p.w;
        v87 = p.z;
        v389.x = v86;
        v389.y = v85;
        v389.z = v87;
        goto LABEL_96;
      }
      memmove(v363, &pPCPAgiFireball->fields, 0x40u);
      v100 = v363;
LABEL_115:
      SDF_VU0__LOADMATRIX(v100);
      SDF_VU0__STOREMATRIX(&aMatrix);
      break;
    case 1u:
      pFormation = effBTLSkillGetInvokeFormation(0);
      effBTLModelGetSphereCenter(&pFormation);
      SDF_VU0__STOREVECTOR(&p);
      sub_854930(&p, 1u);
      v91 = &pPCPAgiFireball->hHelper;
      v92 = p.y;
      v93 = p.x;
      v94 = p.w;
      v95 = p.z;
      v380.x = v93;
      v380.y = v92;
      v380.z = v95;
      v380.w = v94;
      dds3EffectPartSetPosition(v91, v380);
      if (!effBTLSkillCheckRun())
      {
        memmove(&v364, &pPCPAgiFireball->fields, 0x40u);
        SDF_VU0__LOADMATRIX(&v364);
        goto LABEL_112;
      }
      sub_854710(&pPCPAgiFireball->param->fields, 0);
      sub_854930(&aTarget, 0);
      sub_854930(&aTarget, 1u);
      sub_854710(&pPCPAgiFireball->param->fields, 2u);
      sub_854930(&aTarget, 2u);
      sub_854930(&aTarget, 3u);
      pos.y = aTarget.y;
      v96 = aTarget.x;
      pos.w = aTarget.w;
      v97 = aTarget.z;
      v389.y = p.y;
      v98 = p.x;
      v389.w = p.w;
      v99 = p.z;
      pos.x = v96;
      pos.z = v97;
      v389.x = v98;
      v389.z = v99;
LABEL_111:
      *&v376.x = 0;
      LookAtMatrix(pos, v389, v376);
      ReverseMatrix();
      SDF_VU0__RESET_ROW3();
LABEL_112:
      SDF_VU0__STOREMATRIX(&aMatrix);
      break;
    case 0u:
      v51 = &pPCPAgiFireball->hHelper;
      v52 = pPCPAgiFireball->param;
      v53 = v52->pos.x;
      v54 = v52->pos.y;
      v55 = v52->pos.z;
      v56 = v52->pos.w;
      v377.x = v53;
      v377.y = v54;
      v377.z = v55;
      v377.w = v56;
      dds3EffectPartSetPosition(v51, v377);
      if (effBTLSkillCheckRun())
      {
        pFormation = effBTLSkillGetInvokeFormation(0);
        effBTLModelGetSphereCenter(&pFormation);
        SDF_VU0__STOREVECTOR(&p);
        v61 = pPCPAgiFireball->param;
        v62 = p.y;
        pos = v61->pos;
        v66 = p.x;
        v67 = p.w;
        v68 = p.z;
        v389.x = v66;
        v389.y = v62;
        v389.z = v68;
LABEL_96:
        v389.w = v67;
        goto LABEL_111;
      }
      memmove(dest, &pPCPAgiFireball->fields, 0x40u);
      v100 = dest;
      goto LABEL_115;
  }
  v362 = aMatrix;
  v101 = &pPCPAgiFireball->hHelper;
  v361 = v362;
  dds3EffectPartSetRotateMatrix(v101, &v361);
  dds3EffectPartSetColor(&pPCPAgiFireball->hHelper, v41);
  hDataa = v45;
  dds3EffectPartModelDraw(&hDataa);
  SDF_VU0__COPYVECTOR(&pPCPAgiFireball->pos_old, pPCPAgiFireball->pos);
  if (v45)
  {
    v103 = v45[4].klass;
    sdfModelGetMarkPosUnity(v103, 1);
    SDF_VU0__STOREVECTOR(&pPCPAgiFireball->pos);
  }
  if (frame >= 1 && motion_f > frame)
  {
    v104 = 0;
    v105 = 32;
    do
    {
      v106 = pPCPAgiFireball;
      if (v104 == 4)
      {
        if (pPCPAgiFireball->type - 1 <= 1)
        {
          v107 = pPCPAgiFireball->hAttach;
          v362 = aMatrix;
          else if (LODWORD(v107->max_length) <= 4uLL)
          {
LABEL_140:
          }
          v360 = v362;
          dds3EffectPartSetRotateMatrix(&v107->m_Items[4], &v360);
          v106 = pPCPAgiFireball;
        }
        v109 = v106->pos_old.x;
        v110 = v106->pos_old.y;
        v111 = v106->pos_old.z;
        v112 = v106->pos_old.w;
        v113 = v106->hAttach;
        else if (LODWORD(v113->max_length) <= 4uLL)
        {
LABEL_145:
        }
        v115 = &v113->m_Items[4];
      }
      else
      {
        v109 = pPCPAgiFireball->pos.x;
        v110 = pPCPAgiFireball->pos.y;
        v111 = pPCPAgiFireball->pos.z;
        v112 = pPCPAgiFireball->pos.w;
        v116 = pPCPAgiFireball->hAttach;
        else if (v104 >= LODWORD(v116->max_length))
        {
LABEL_150:
        }
        v115 = (v116 + v105);
      }
      v381.x = v109;
      v381.y = v110;
      v381.z = v111;
      v381.w = v112;
      dds3EffectPartSetPosition(v115, v381);
      v119 = pPCPAgiFireball->hAttach;
      else if (v104 >= LODWORD(v119->max_length))
      {
LABEL_155:
      }
      dds3EffectPartSetColor((v119 + v105), v41, 0);
      v121 = pPCPAgiFireball->hAttach;
      dds3EffectPartDraw((v121 + v105), 0);
      ++v104;
      v105 += 8;
    }
    while (v104 != 5);
  }
  if ((frame & 0x80000000) == 0)
  {
    if (!frame)
    {
      hStart = pPCPAgiFireball->hStart;
      v124 = pPCPAgiFireball->pos.x;
      v125 = pPCPAgiFireball->pos.y;
      v126 = pPCPAgiFireball->pos.z;
      v127 = pPCPAgiFireball->pos.w;
      v382.x = v124;
      v382.y = v125;
      v382.z = v126;
      v382.w = v127;
      dds3EffectPartSetPosition(hStart->m_Items, v382);
      v129 = *&pPCPAgiFireball->matrix.m00;
      v130 = *&pPCPAgiFireball->matrix.m20;
      v131 = *&pPCPAgiFireball->matrix.m21;
      v132 = pPCPAgiFireball->hStart;
      *&v362.m01 = *&pPCPAgiFireball->matrix.m01;
      *&v362.m21 = v131;
      *&v362.m00 = v129;
      *&v362.m20 = v130;
      v133 = *&pPCPAgiFireball->matrix.m02;
      v134 = *&pPCPAgiFireball->matrix.m22;
      v135 = *&pPCPAgiFireball->matrix.m23;
      *&v362.m03 = *&pPCPAgiFireball->matrix.m03;
      *&v362.m23 = v135;
      *&v362.m02 = v133;
      *&v362.m22 = v134;
      v359 = v362;
      dds3EffectPartSetRotateMatrix(v132->m_Items, &v359);
      v138 = pPCPAgiFireball->hStart;
      v139 = pPCPAgiFireball->pos.x;
      v140 = pPCPAgiFireball->pos.y;
      v141 = pPCPAgiFireball->pos.z;
      v142 = pPCPAgiFireball->pos.w;
      v383.x = v139;
      v383.y = v140;
      v383.z = v141;
      v383.w = v142;
      dds3EffectPartSetPosition(&v138->m_Items[1], v383);
      v144 = *&pPCPAgiFireball->matrix.m00;
      v145 = *&pPCPAgiFireball->matrix.m20;
      v146 = *&pPCPAgiFireball->matrix.m21;
      v147 = pPCPAgiFireball->hStart;
      *&v362.m01 = *&pPCPAgiFireball->matrix.m01;
      *&v362.m21 = v146;
      *&v362.m00 = v144;
      *&v362.m20 = v145;
      v148 = *&pPCPAgiFireball->matrix.m02;
      v149 = *&pPCPAgiFireball->matrix.m22;
      v150 = *&pPCPAgiFireball->matrix.m23;
      *&v362.m03 = *&pPCPAgiFireball->matrix.m03;
      *&v362.m23 = v150;
      *&v362.m02 = v148;
      *&v362.m22 = v149;
      v359 = v362;
      dds3EffectPartSetRotateMatrix(&v147->m_Items[1], &v359);
      v153 = pPCPAgiFireball->hStart;
      v154 = pPCPAgiFireball->pos.x;
      v155 = pPCPAgiFireball->pos.y;
      v156 = pPCPAgiFireball->pos.z;
      v157 = pPCPAgiFireball->pos.w;
      v384.x = v154;
      v384.y = v155;
      v384.z = v156;
      v384.w = v157;
      dds3EffectPartSetPosition(&v153->m_Items[2], v384);
      v159 = *&pPCPAgiFireball->matrix.m00;
      v160 = *&pPCPAgiFireball->matrix.m20;
      v161 = *&pPCPAgiFireball->matrix.m21;
      v162 = pPCPAgiFireball->hStart;
      *&v362.m01 = *&pPCPAgiFireball->matrix.m01;
      *&v362.m21 = v161;
      *&v362.m00 = v159;
      *&v362.m20 = v160;
      v163 = *&pPCPAgiFireball->matrix.m02;
      v164 = *&pPCPAgiFireball->matrix.m22;
      v165 = *&pPCPAgiFireball->matrix.m23;
      *&v362.m03 = *&pPCPAgiFireball->matrix.m03;
      *&v362.m23 = v165;
      *&v362.m02 = v163;
      *&v362.m22 = v164;
      v359 = v362;
      dds3EffectPartSetRotateMatrix(&v162->m_Items[2], &v359);
      v168 = pPCPAgiFireball->hStart;
      v169 = pPCPAgiFireball->pos.x;
      v170 = pPCPAgiFireball->pos.y;
      v171 = pPCPAgiFireball->pos.z;
      v172 = pPCPAgiFireball->pos.w;
      v385.x = v169;
      v385.y = v170;
      v385.z = v171;
      v385.w = v172;
      dds3EffectPartSetPosition(&v168->m_Items[3], v385);
      v174 = *&pPCPAgiFireball->matrix.m00;
      v175 = *&pPCPAgiFireball->matrix.m20;
      v176 = *&pPCPAgiFireball->matrix.m21;
      v177 = pPCPAgiFireball->hStart;
      *&v362.m01 = *&pPCPAgiFireball->matrix.m01;
      *&v362.m21 = v176;
      *&v362.m00 = v174;
      *&v362.m20 = v175;
      v178 = *&pPCPAgiFireball->matrix.m02;
      v179 = *&pPCPAgiFireball->matrix.m22;
      v180 = *&pPCPAgiFireball->matrix.m23;
      *&v362.m03 = *&pPCPAgiFireball->matrix.m03;
      *&v362.m23 = v180;
      *&v362.m02 = v178;
      *&v362.m22 = v179;
      v359 = v362;
      dds3EffectPartSetRotateMatrix(&v177->m_Items[3], &v359);
      v183 = pPCPAgiFireball->hStart;
      v184 = pPCPAgiFireball->pos.x;
      v185 = pPCPAgiFireball->pos.y;
      v186 = pPCPAgiFireball->pos.z;
      v187 = pPCPAgiFireball->pos.w;
      v386.x = v184;
      v386.y = v185;
      v386.z = v186;
      v386.w = v187;
      dds3EffectPartSetPosition(&v183->m_Items[4], v386);
      v189 = *&pPCPAgiFireball->matrix.m00;
      v190 = *&pPCPAgiFireball->matrix.m20;
      v191 = *&pPCPAgiFireball->matrix.m21;
      v192 = pPCPAgiFireball->hStart;
      *&v362.m01 = *&pPCPAgiFireball->matrix.m01;
      *&v362.m21 = v191;
      *&v362.m00 = v189;
      *&v362.m20 = v190;
      v193 = *&pPCPAgiFireball->matrix.m02;
      v194 = *&pPCPAgiFireball->matrix.m22;
      v195 = *&pPCPAgiFireball->matrix.m23;
      *&v362.m03 = *&pPCPAgiFireball->matrix.m03;
      *&v362.m23 = v195;
      *&v362.m02 = v193;
      *&v362.m22 = v194;
      v359 = v362;
      dds3EffectPartSetRotateMatrix(&v192->m_Items[4], &v359);
    }
    v197 = pPCPAgiFireball->hStart;
    abgr = pPCPAgiFireball->abgr;
    else if (!LODWORD(v197->max_length))
    {
      goto LABEL_200;
    }
    dds3EffectPartSetColor(v197->m_Items, abgr);
    v200 = pPCPAgiFireball->hStart;
    dds3EffectPartDraw(v200->m_Items);
    v203 = pPCPAgiFireball->hStart;
    v204 = pPCPAgiFireball->abgr;
    else if ((v203->max_length & 0xFFFFFFFE) == 0)
    {
      goto LABEL_206;
    }
    dds3EffectPartSetColor(&v203->m_Items[1], v204);
    v206 = pPCPAgiFireball->hStart;
    dds3EffectPartDraw(&v206->m_Items[1]);
    v209 = pPCPAgiFireball->hStart;
    v210 = pPCPAgiFireball->abgr;
    dds3EffectPartSetColor(&v209->m_Items[2], v210);
    v212 = pPCPAgiFireball->hStart;
    dds3EffectPartDraw(&v212->m_Items[2]);
    v215 = pPCPAgiFireball->hStart;
    v216 = pPCPAgiFireball->abgr;
    else if ((v215->max_length & 0xFFFFFFFC) == 0)
    {
      goto LABEL_219;
    }
    dds3EffectPartSetColor(&v215->m_Items[3], v216);
    v218 = pPCPAgiFireball->hStart;
    dds3EffectPartDraw(&v218->m_Items[3]);
    v221 = pPCPAgiFireball->hStart;
    v222 = pPCPAgiFireball->abgr;
    dds3EffectPartSetColor(&v221->m_Items[4], v222);
    v224 = pPCPAgiFireball->hStart;
    dds3EffectPartDraw(&v224->m_Items[4]);
  }
  v226 = pPCPAgiFireball;
  OkSmokeFrame = pPCPAgiFireball->param->OkSmokeFrame;
  if (frame >= OkSmokeFrame)
  {
    if (frame == OkSmokeFrame)
    {
      v228 = pPCPAgiFireball->pos.x;
      v229 = pPCPAgiFireball->pos.y;
      v230 = pPCPAgiFireball->pos.z;
      v231 = pPCPAgiFireball->pos.w;
      p_hOkSmoke = &pPCPAgiFireball->hOkSmoke;
      v387.x = v228;
      v387.y = v229;
      v387.z = v230;
      v387.w = v231;
      dds3EffectPartSetPosition(p_hOkSmoke, v387);
      v358 = aMatrix;
      dds3EffectPartSetRotateMatrix(&pPCPAgiFireball->hOkSmoke, &v358);
      v226 = pPCPAgiFireball;
    }
    v233 = &v226->hOkSmoke;
    v234 = v226->abgr;
    dds3EffectPartSetColor(v233, v234);
    dds3EffectPartDraw(&pPCPAgiFireball->hOkSmoke);
  }
  if (frame >= 1)
  {
    v235 = 0;
    v355 = frame;
    do
    {
      TrackCount = pPCPAgiFireball->param->TrackCount;
      if (TrackCount->m_Items[v235] >= 1)
      {
        if (motion_f > frame)
        {
          v241 = pPCPAgiFireball->param->TrackCount;
          v242 = pPCPAgiFireball->frame;
          v244 = v241->m_Items[v235];
          SDF_VU0__LOADVECTOR(pPCPAgiFireball->pos);
          SDF_VU0__LOADVECTOR_B(pPCPAgiFireball->pos_old);
          SDF_VU0__SUBVECTOR();
          SDF_VU0__COPYVECTOR_A_TO_C();
          v240 = v244 * (v242 - 1);
          sub_854930(&v372, 0);
          sub_854710(&v372, 0);
          sub_854930(&v372, 1u);
          sub_854930(&v372, 2u);
          SDF_VU0__LOADVECTOR_B(v372);
          SDF_VU0__MULVECTOR();
          SDF_VU0__STOREVECTOR(&v372);
          SDF_VU0__COPYVECTOR(&aTarget, pPCPAgiFireball->pos_old);
          SDF_VU0__LOADVECTOR(dds3CameraEyePos);
          SDF_VU0__LOADVECTOR_B(dds3CameraTargetPos);
          SDF_VU0__SUBVECTOR();
          SDF_VU0__COPYVECTOR_C_TO_B();
          SDF_VU0__OUTERPRODUCT();
          SDF_VU0__NORMALIZE();
          SDF_VU0__STOREVECTOR(&v371);
          for (i = 0; ; ++i)
          {
            v249 = pPCPAgiFireball->param->TrackCount;
            if (i >= v249->m_Items[v235])
              break;
            phTrack = pPCPAgiFireball->phTrack;
            v253 = phTrack->m_Items[v235];
            v254 = v240 + i;
            v255 = (v240 + i);
            if (!v253->m_Items[v255])
            {
              v257 = pPCPAgiFireball->phTrack;
              v259 = v257->m_Items[v235];
              v260 = pPCPAgiFireball->phTrack->m_Items[v235];
              else if (!LODWORD(v260->max_length))
              {
                goto LABEL_272;
              }
              v262 = dds3EffectPartCopy(v260->m_Items, 0, 0);
              v264 = v262;
              v259->m_Items[v255] = v264;
              v266 = pPCPAgiFireball->param;
              TrackScale = v266->TrackScale;
              v268 = v266->scale;
              v270 = (TrackScale + 4 * v235);
              TrackScale_r = v266->TrackScale_r;
              v272 = v270[8];
              v274 = TrackScale_r->m_Items[v235];
              v275 = DDS3EFFECT_RAND_FA(v274);
              v276 = pPCPAgiFireball->phTrack;
              v277 = v268 * v272;
              v279 = v276->m_Items[v235];
              dds3EffectPartSetScale(&v279->m_Items[v255], v277 * v275);
            }
            SDF_VU0__LOADVECTOR(aTarget);
            SDF_VU0__LOADVECTOR_B(v372);
            SDF_VU0__ADDVECTOR();
            SDF_VU0__COPYVECTOR_A_TO_C();
            DDS3EFFECT_RAND_PM();
            sub_854930(&v370, 0);
            sub_854710(&v370, 0);
            sub_854930(&v370, 1u);
            sub_854930(&v370, 2u);
            SDF_VU0__LOADVECTOR(v371);
            SDF_VU0__LOADVECTOR_B(v370);
            SDF_VU0__MULVECTOR();
            SDF_VU0__ADDVECTOR_A_C();
            SDF_VU0__STOREVECTOR(&aTarget);
            v284 = pPCPAgiFireball->phTrack;
            v286 = aTarget.y;
            v287 = aTarget.x;
            v288 = aTarget.w;
            v289 = aTarget.z;
            v290 = v284->m_Items[v235];
            else if (v254 >= LODWORD(v290->max_length))
            {
              goto LABEL_299;
            }
            v388.x = v287;
            v388.y = v286;
            v388.z = v289;
            v388.w = v288;
            dds3EffectPartSetPosition(&v290->m_Items[v255], v388);
            v292 = pPCPAgiFireball->phTrack;
            v294 = v292->m_Items[v235];
            dds3EffectPartSetColor(&v294->m_Items[v255], pPCPAgiFireball->abgr);
          }
          frame = v355;
          if (!v240)
            goto LABEL_354;
LABEL_310:
          v297 = 0;
          v298 = v240;
          v299 = 32;
          do
          {
            v301 = pPCPAgiFireball->phTrack;
            v303 = v301->m_Items[v235];
            if (!*(&v303->obj.klass + v299))
            {
              v305 = pPCPAgiFireball->phTrack;
              v307 = v305->m_Items[v235];
              v308 = pPCPAgiFireball->phTrack->m_Items[v235];
              else if (!LODWORD(v308->max_length))
              {
LABEL_326:
              }
              v310 = dds3EffectPartCopy(v308->m_Items, 0, 0);
              v312 = v310;
              *&v307[v299 / 4] = v312;
              v314 = pPCPAgiFireball->param;
              v315 = v314->TrackScale;
              v316 = v314->scale;
              v318 = (v315 + 4 * v235);
              v319 = v314->TrackScale_r;
              v320 = v318[8];
              v322 = v319->m_Items[v235];
              v323 = DDS3EFFECT_RAND_FA(v322);
              v324 = pPCPAgiFireball->phTrack;
              v325 = v316 * v320;
              v327 = v324->m_Items[v235];
              dds3EffectPartSetScale((v327 + v299), v325 * v323, 0);
            }
            v329 = pPCPAgiFireball->phTrack;
            v331 = v329->m_Items[v235];
            v332 = *&pPCPAgiFireball->matrix.m00;
            v333 = *&pPCPAgiFireball->matrix.m20;
            v334 = *&pPCPAgiFireball->matrix.m21;
            *&v362.m01 = *&pPCPAgiFireball->matrix.m01;
            *&v362.m21 = v334;
            *&v362.m00 = v332;
            *&v362.m20 = v333;
            v335 = *&pPCPAgiFireball->matrix.m02;
            v336 = *&pPCPAgiFireball->matrix.m22;
            v337 = *&pPCPAgiFireball->matrix.m23;
            *&v362.m03 = *&pPCPAgiFireball->matrix.m03;
            *&v362.m23 = v337;
            *&v362.m02 = v335;
            *&v362.m22 = v336;
            else if (v297 >= LODWORD(v331->max_length))
            {
LABEL_348:
            }
            v357 = v362;
            dds3EffectPartSetRotateMatrix((v331 + v299), &v357, 0);
            v339 = pPCPAgiFireball->phTrack;
            v341 = v339->m_Items[v235];
            dds3EffectPartDraw((v341 + v299), 0);
            ++v297;
            v299 += 8;
          }
          while (v298 != v297);
          goto LABEL_354;
        }
        v238 = pPCPAgiFireball->param->TrackCount;
        v240 = v238->m_Items[v235] * (motion_f - 1);
        if (v240)
          goto LABEL_310;
      }
LABEL_354:
      ++v235;
    }
    while (v235 != 3);
  }
  ++pPCPAgiFireball->frame;
}

// 0x1178130
void effPCPAgiFireballSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPAgiFireball_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPAgiFireball_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[8].klass) = abgr;
}

// 0x1178010
void effPCPAgiFireballSetPosition(void **hData, sdfVector4_t pPos) {
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
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPAgiFireball_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPAgiFireball_tag, v12);
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
  SDF_VU0__COPYVECTOR(&(*hData)[7].klass->_1.name, v13, 0);
}

// 0x1178220
void effPCPAgiFireballSetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
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
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPAgiFireball_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPAgiFireball_tag, v17);
      if ((v17[0] & 1) != 0)
        v14 = v17[2];
      else
        v14 = v17 + 1;
      v15 = sub_8C4940(v14);
    }
  }
  SDF_VU0__STOREMATRIX(&v7[1]);
}

// 0x11785b0
effPCPAgiFireball_tag *effPCPAgiFireballSp2Copy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 *v10;
  Il2CppClass *v11;
  u64 v13[3];

  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPAgiFireball_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPAgiFireball_tag, v13);
      if ((v13[0] & 1) != 0)
        v8 = v13[2];
      else
        v8 = v13 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = Allocate(effPCPAgiFireball_tag);
  _ctor(v10, 0);
  Clear(v10, 0);
  v11 = v5[7].klass;
  *(v10 + 30) = 0;
  v10[14] = v11;
  v10[16] = 0x280808080LL;
  SDF_VU0__STOREIDENTITY((v10 + 2), 0);
  v10[23] = v5;
  return v10;
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
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 *v10;
  Il2CppClass *v11;
  u64 v13[3];

  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPAgiFireball_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPAgiFireball_tag, v13);
      if ((v13[0] & 1) != 0)
        v8 = v13[2];
      else
        v8 = v13 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = Allocate(effPCPAgiFireball_tag);
  _ctor(v10, 0);
  Clear(v10, 0);
  v11 = v5[7].klass;
  *(v10 + 30) = 0;
  v10[14] = v11;
  v10[16] = 0x180808080LL;
  SDF_VU0__STOREIDENTITY((v10 + 2), 0);
  v10[23] = v5;
  return v10;
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
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 *v10;
  u64 i;
  Il2CppClass *v16;
  u64 *data;
  Il2CppClass *v19;
  s64 v21;
  Il2CppClass *v23;
  u64 *v25;
  u64 v27;
  u32 *v28;
  s64 *v31;
  s64 *v32;
  u64 v34;
  u32 *v36;
  s64 *v37;
  s64 *v38;
  u64 v40;
  u32 *v42;
  s64 *v43;
  s64 *v44;
  u32 *v46;
  Il2CppObject *v48;
  Il2CppObject *v49;
  Il2CppObject *pData;
  u64 v51[3];

  v49 = 0;
  pData = 0;
  v48 = 0;
  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPAgiraoFire_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPAgiraoFire_tag, v51);
      if ((v51[0] & 1) != 0)
        v8 = v51[2];
      else
        v8 = v51 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = Allocate(effPCPAgiraoFire_tag);
  _ctor(v10, 0);
  Clear(v10, 0);
  v10[2] = v5[1].klass;
  v10[3] = 0x8080808000000000LL;
  for (i = 0; i != 7; ++i)
  {
    v16 = v5[2].klass;
    data = v16->_1.byval_arg.data;
    pData = data[i + 4];
    v19 = v5[2].klass;
    v21 = *&v19->_1.byval_arg.bits;
    v49 = *(v21 + 8 * i + 32);
    v23 = v5[2].klass;
    v25 = v23->_1.this_arg.data;
    v48 = v25[i + 4];
    v27 = v10[4];
    v28 = *(v27 + 32);
    v31 = dds3EffectCopy(&pData, 0, 0);
    v32 = v31;
    *&v28[2 * i + 8] = v32;
    v34 = v10[4];
    v36 = *(v34 + 40);
    v37 = dds3EffectCopy(&v49, 0, 0);
    v38 = v37;
    *&v36[2 * i + 8] = v38;
    v40 = v10[4];
    v42 = *(v40 + 48);
    v43 = dds3EffectCopy(&v48, 0, 0);
    v44 = v43;
    v46 = &v42[2 * i];
    *(v46 + 4) = v44;
  }
  return v10;
}

// 0x1172050
effPCPAgiraoFire_tag *effPCPAgiraoFireCreate(effPCPAgiraoFireParam_t *pParam, effPCPAgiraoFirePartList_t *pPartList) {
  u64 *v5;
  u64 v7;
  s64 v8;
  u64 v14;
  u32 *v16;
  struct System_Object_array *pD3PData;
  s64 *v19;
  s64 *v20;
  u64 v21;
  s64 v22;
  u64 v24;
  u32 *v26;
  s64 *v27;
  s64 *v28;
  u64 v30;
  u32 *v32;
  s64 *v33;
  s64 *v34;
  Il2CppObject *pData;

  pData = 0;
  v5 = Allocate(effPCPAgiraoFire_tag);
  _ctor(v5, 0);
  Clear(v5, 0);
  v5[2] = pParam;
  v5[3] = 0x8080808000000000LL;
  v7 = 0;
  v8 = 8;
  do
  {
    v14 = v5[4];
    v16 = *(v14 + 32);
    pD3PData = pPartList->pD3PData;
    else if (v7 >= LODWORD(pD3PData->max_length))
    {
LABEL_16:
    }
    v19 = dds3EffectLoad((pD3PData + v8 * 4), 0, 0, 0);
    v20 = v19;
    *&v16[v8] = v20;
    v21 = v5[4];
    v22 = *(v21 + 32);
    pData = *(v22 + v8 * 4);
    v24 = v5[4];
    v26 = *(v24 + 40);
    v27 = dds3EffectCopy(&pData, 0, 0);
    v28 = v27;
    *&v26[v8] = v28;
    v30 = v5[4];
    v32 = *(v30 + 48);
    v33 = dds3EffectCopy(&pData, 0, 0);
    v34 = v33;
    ++v7;
    *&v32[v8] = v34;
    v8 += 2;
  }
  while (v7 != 7);
  return v5;
}

// 0x1172370
effPCPAgiraoFire_tag *effPCPAgiraoFireCreatePCF(void **hData, s32 bPos, bool tbldata) {
  dds3EffectPCPData_t_o *v6;
  Il2CppObject *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  effPCPAgiraoFirePartList_t_o *v12;
  struct dds3EffectPCPData_Part_t_array *pcpData;
  Il2CppObject *v15;
  u32 offset;
  Il2CppObject *DataUnityOffSet;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v23;
  s64 *v24;
  u64 v25;
  struct dds3EffectPCPData_Part_t_array *v27;
  u32 *pD3PData;
  Il2CppObject *v29;
  u64 v30;
  u32 v32;
  s64 *EffPCPAgiFireballPart;
  s64 *v34;
  u32 *v36;
  effPCPAgiraoFireParam_t_o *pParam;
  s32 pos;
  u64 v40[2];
  char *v41;

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v7->klass->_1.element_class, v8, v40);
      if ((v40[0] & 1) != 0)
        v10 = v41;
      else
        v10 = v40 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v6, Interface, &pos);
  v12 = Allocate(effPCPAgiraoFirePartList_t);
  effPCPAgiraoFirePartList_t___ctor(v12);
  pcpData = v6->pcpData;
  v15 = *hData;
  offset = pcpData->m_Items[0]->offset;
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v15, offset + bPos, 28);
  if (DataUnityOffSet)
  {
    klass = DataUnityOffSet->klass;
    if (DataUnityOffSet->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPAgiraoFireParam_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPAgiraoFireParam_t, v40);
      if ((v40[0] & 1) != 0)
        v23 = v41;
      else
        v23 = v40 + 1;
      v24 = sub_8C4940(v23);
    }
  }
  pParam = DataUnityOffSet;
  v25 = 0;
  do
  {
    v27 = v6->pcpData;
    pD3PData = v12->pD3PData;
    v29 = *hData;
    v30 = v25 + 1;
    v32 = v27->m_Items[v25 + 1]->offset;
    EffPCPAgiFireballPart = GetEffPCPAgiFireballPart(v29, v32 + bPos);
    v34 = EffPCPAgiFireballPart;
    v36 = &pD3PData[2 * v25++];
    *(v36 + 4) = v34;
  }
  while (v30 != 7);
  return effPCPAgiraoFireCreate(pParam, v12);
}

// 0x1172c60
void effPCPAgiraoFireDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s64 i;
  Il2CppClass *v10;
  u64 v11;
  u64 *data;
  Il2CppClass *v15;
  s64 v17;
  Il2CppClass *v19;
  u64 *v20;
  Il2CppObject *v22;
  Il2CppObject *v23;
  Il2CppObject *v24[3];
  Il2CppObject *pData;

  pData = 0;
  v22 = 0;
  v23 = 0;
  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPAgiraoFire_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPAgiraoFire_tag, v24);
      if ((v24[0] & 1) != 0)
        v6 = v24[2];
      else
        v6 = v24 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  for (i = 4; i != 11; ++i)
  {
    v10 = v3[2].klass;
    v11 = i - 4;
    data = v10->_1.this_arg.data;
    pData = data[i];
    v15 = v3[2].klass;
    v17 = *&v15->_1.byval_arg.bits;
    v23 = *(v17 + 8 * i);
    v19 = v3[2].klass;
    v20 = v19->_1.byval_arg.data;
    v22 = v20[i];
    dds3EffectDelete(&pData);
    dds3EffectDelete(&v23);
    dds3EffectDelete(&v22);
  }
}

// 0x1172eb0
void effPCPAgiraoFireDraw(void **hData) {
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u32 monitor_high;
  s32 monitor;
  f32 x;
  f32 y;
  f32 z;
  f32 w;
  u64 i;
  s64 v21;
  s32 v23;
  f32 *data;
  f32 *v26;
  u64 j;
  u32 *v30;
  Il2CppClass *v32;
  s64 v34;
  Il2CppClass *v36;
  s64 v38;
  UnityEngine_Matrix4x4_o v44;
  Il2CppObject *v45;
  UnityEngine_Matrix4x4_o aMatrix;
  UnityEngine_Vector4_o p;
  Il2CppObject *v48[3];
  Il2CppObject *pData;
  UnityEngine_Vector4_o v50;
  UnityEngine_Vector4_o dds3CameraTargetPos;
  UnityEngine_Vector4_o v52;

  *&p.x = 0;
  *&p.z = 0;
  pData = 0;
  v45 = 0;
  memset(&aMatrix, 0, sizeof(aMatrix));
  v4 = *hData;
  if (*hData)
  {
    klass = v4->klass;
    if (v4->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPAgiraoFire_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPAgiraoFire_tag, v48);
      if ((v48[0] & 1) != 0)
        v7 = v48[2];
      else
        v7 = v48 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  *&p.x = 0;
  *&p.z = 0;
  memset(&aMatrix, 0, sizeof(aMatrix));
  monitor = v4[1].monitor;
  monitor_high = HIDWORD(v4[1].monitor);
  x = dds3CameraEyePos.x;
  y = dds3CameraEyePos.y;
  z = dds3CameraEyePos.z;
  w = dds3CameraEyePos.w;
  v52.x = x;
  v52.y = y;
  v52.z = z;
  v52.w = w;
  *&v50.x = 0;
  *&v50.z = method;
  LookAtMatrix(dds3CameraTargetPos, v52, v50);
  SDF_VU0__STOREMATRIX(&aMatrix);
  for (i = 0; i != 3; ++i)
  {
    v21 = *&v4[1].klass->_1.byval_arg.bits;
    v23 = *(v21 + 4 * i + 32);
    if (monitor >= v23)
    {
      SDF_VU0__LOADVECTOR_B(*&v4[1].klass->_1.name);
      v44 = aMatrix;
      SDF_VU0__LOADMATRIX(&v44);
      data = v4[1].klass->_1.byval_arg.data;
      sub_851730(&data[2 * i + 8], 0);
      sub_854930(&p, 0);
      v26 = v4[1].klass->_1.byval_arg.data;
      sub_851730(&v26[2 * i + 8], 1);
      sub_854930(&p, 1u);
      sub_854930(&p, 2u);
      SDF_VU0__LOADVECTOR(p);
      SDF_VU0__VECTOR_W_SET_ZERO();
      SDF_VU0__APPLYMATRIX();
      SDF_VU0__ADDVECTOR();
      SDF_VU0__STOREVECTOR(&p);
      for (j = 0; j != 7; ++j)
      {
        v30 = v4[1].klass->_1.this_arg.data;
        if (monitor >= v30[j + 8] + v23)
        {
          v32 = v4[2].klass;
          v34 = *(&v32->_1.byval_arg.data + i);
          pData = *(v34 + 8 * j + 32);
          dds3EffectSetRGBA(&pData, monitor_high);
          v36 = v4[2].klass;
          v38 = *(&v36->_1.byval_arg.data + i);
          v45 = *(v38 + 8 * j + 32);
          dds3EffectSetPosition(&v45, p);
          dds3EffectDraw(&v45);
        }
      }
    }
  }
  ++LODWORD(v4[1].monitor);
}

// 0x1173470
void effPCPAgiraoFireSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPAgiraoFire_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPAgiraoFire_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[1].monitor) = abgr;
}

// 0x1173350
void effPCPAgiraoFireSetPosition(void **hData, sdfVector4_t pPos) {
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
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPAgiraoFire_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPAgiraoFire_tag, v12);
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

// 0x118cec0
effPCPAnalyzeBED_tag *effPCPAnalyzeBEDCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 *v10;
  effPCPAnalyzeBED_tag_o *v13[3];
  effPCPAnalyzeBED_tag_o *pAnalyzeBED;

  pAnalyzeBED = 0;
  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPAnalyzeBED_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPAnalyzeBED_tag, v13);
      if ((v13[0] & 1) != 0)
        v8 = v13[2];
      else
        v8 = v13 + 1;
      v9 = sub_8C4940(v8);
    }
  }
LABEL_14:
  v10 = Allocate(effPCPAnalyzeBED_tag);
  _ctor(v10, 0);
  v10[2] = 0;
  v10[4] = 0x808080803F800000LL;
  pAnalyzeBED = v10;
  v10[2] = v5[1].klass;
  effPCPAnalyzeInit(&pAnalyzeBED);
  return v10;
}

// 0x118cbd0
effPCPAnalyzeBED_tag *effPCPAnalyzeBEDCreate(void *pBEDData) {
  u64 *v3;
  Il2CppClass *v5;
  s64 *Interface;
  char *v7;
  s64 *v8;
  effBTL_t_o *v9;
  effPCPAnalyzeBED_tag_o *v12;
  u64 v13[3];

  v3 = Allocate(effPCPAnalyzeBED_tag);
  _ctor(v3, 0);
  v12 = v3;
  v3[2] = 0;
  v3[4] = 0x808080803F800000LL;
  if (pBEDData)
  {
    Interface = QueryInterface(pBEDData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pBEDData->klass->_1.element_class, v5, v13);
      if ((v13[0] & 1) != 0)
        v7 = v13[2];
      else
        v7 = v13 + 1;
      v8 = sub_8C4940(v7);
    }
    v9 = effEveBEDCreate(Interface);
    v3[2] = v9;
    if (v9)
    {
      effPCPAnalyzeInit(&v12);
    }
  }
  return v3;
}

// 0x118cd40
effPCPAnalyzeBED_tag *effPCPAnalyzeBEDCreatePCF(void **hData, s32 bPos, bool tbldata) {
  dds3EffectPCPData_t_o *v6;
  Il2CppObject *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  struct dds3EffectPCPData_Part_t_array *pcpData;
  Il2CppObject *v15;
  u32 offset;
  Il2CppObject *EffPCPpBEDData;
  u64 v21[3];
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
      sub_8FC2C0(v7->klass->_1.element_class, v8, v21);
      if ((v21[0] & 1) != 0)
        v10 = v21[2];
      else
        v10 = v21 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v6, Interface, &pos);
  pcpData = v6->pcpData;
  v15 = *hData;
  offset = pcpData->m_Items[0]->offset;
  EffPCPpBEDData = GetEffPCPpBEDData(v15, offset + bPos);
  return effPCPAnalyzeBEDCreate(EffPCPpBEDData);
}

// 0x118d050
void effPCPAnalyzeBEDDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  effEveBEDCutHandle_t_o *monitor;
  effBTL_t_o *v9;
  u64 v10[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPAnalyzeBED_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPAnalyzeBED_tag, v10);
      if ((v10[0] & 1) != 0)
        v6 = v10[2];
      else
        v6 = v10 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  monitor = v3[1].monitor;
  if (monitor)
  {
    effEveBEDCutDelete(monitor);
  }
  if (v3)
  {
    v9 = v3[1].klass;
    if (v9)
    {
      if (!v9->CutCount)
      {
        effEveBEDDelete(v9);
      }
    }
  }
}

// 0x118d1c0
void effPCPAnalyzeBEDDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  u64 *v9;
  nbFormation_t_o *TargetFormation;
  effBTL_SkillPositionPtr_t_o *v14;
  s64 v17;
  nbFormation_t_o *v19;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o pPos;
  effBTL_SkillPositionPtr_t_o *v22[3];
  effBTL_SkillPositionPtr_t_o *pPosPtr;

  pPosPtr = 0;
  *&pPos.x = 0;
  *&pPos.z = 0;
  v19 = 0;
  *&p.x = 0;
  *&p.z = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPAnalyzeBED_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPAnalyzeBED_tag, v22);
      if ((v22[0] & 1) != 0)
        v6 = v22[2];
      else
        v6 = v22 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = Allocate(effEveBEDParams_t);
  effEveBEDParams_t___ctor(v8);
  v9 = Allocate(effBTL_SkillPositionPtr_t);
  effBTL_SkillPositionPtr_t___ctor(v9);
  pPosPtr = v9;
  *&pPos.x = 0;
  *&pPos.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  sub_854930((v8 + 4), 0);
  sub_854930((v8 + 4), 1u);
  sub_854930((v8 + 4), 2u);
  sub_854930((v8 + 4), 3u);
  v8[6] = 0;
  *(v8 + 14) = v3[2].klass;
  if (!effBTLSkillCheckRun())
    goto LABEL_24;
LABEL_13:
  TargetFormation = effBTLSkillGetTargetFormation(0);
  v14 = pPosPtr;
  v19 = TargetFormation;
  *&pPosPtr->target = 260;
  v14->direction = 0;
  v14->radius = 0;
  effBTLPartGetPositionPtr(&v19, &pPosPtr, &pPos);
  SDF_VU0__LOADVECTOR(dds3CameraEyePos);
  SDF_VU0__LOADVECTOR_B(dds3CameraTargetPos);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&p);
  effBTLModelGetID(&v19);
  v17 = (v8 + 2);
  sub_854710(&pPos, 0);
  sub_854710(&p, 0);
  sub_854930((v8 + 2), 0);
  sub_854710(&pPos, 1u);
  sub_854710(&p, 1u);
  sub_854930((v8 + 2), 1u);
  sub_854710(&pPos, 2u);
  sub_854710(&p, 2u);
  sub_854930((v8 + 2), 2u);
LABEL_25:
  sub_854930(v17, 3u);
  *(v8 + 15) = HIDWORD(v3[2].klass);
  effEveBEDCutSetParams(&v3[1].monitor, v8);
  effEveBEDCutDraw(&v3[1].monitor);
}

// 0x118d720
void effPCPAnalyzeBEDSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPAnalyzeBED_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPAnalyzeBED_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[2].klass) = abgr;
}

// 0x118d630
void effPCPAnalyzeBEDSetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPAnalyzeBED_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPAnalyzeBED_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *&(*hData)[2].klass = scale;
}

// 0x118ca50
void effPCPAnalyzeInit(effPCPAnalyzeBED_tag **pAnalyzeBED) {
  u64 *v3;
  effPCPAnalyzeBED_tag_o *v5;
  effBTL_t_o *hBED;

  v3 = Allocate(effEveBEDParams_t);
  effEveBEDParams_t___ctor(v3);
  sub_854930((v3 + 2), 0);
  sub_854930((v3 + 2), 1u);
  sub_854930((v3 + 2), 2u);
  sub_854930((v3 + 2), 3u);
  sub_854930((v3 + 4), 0);
  sub_854930((v3 + 4), 1u);
  sub_854930((v3 + 4), 2u);
  sub_854930((v3 + 4), 3u);
  v3[6] = 0x42C8000042C80000LL;
  v3[7] = 0x808080803F800000LL;
  v5 = *pAnalyzeBED;
  hBED = (*pAnalyzeBED)->hBED;
  v5->hBEDCut = effEveBEDCutCreate(hBED, 2u, v3);
}

// 0x1169ee0
effPCPBlinkMultiBlur_tag *effPCPBlinkMultiBlurCreate(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  effPCPBlinkMultiBlur_tag_o *v10;
  effPCPMisc_c *v12;
  u64 *v13;
  struct effPCPBlinkMultiBlurBase_tag_o *pBlinkMultiBlurBase;
  dds3Effect_PartialMultiBlurParam_t_o *monitor;
  u32 *v20;
  struct System_UInt32_array *blink_abgr;
  u32 v22;
  u32 *v23;
  struct System_UInt32_array *v24;
  u32 v26;
  u64 v31[3];

  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBlinkMultiBlurParam_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBlinkMultiBlurParam_t, v31);
      if ((v31[0] & 1) != 0)
        v8 = v31[2];
      else
        v8 = v31 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = Allocate(effPCPBlinkMultiBlur_tag);
  _ctor(v10, 0);
  v10->frame = 0;
  else if (BlinkMultiBlurCount)
  {
    goto LABEL_13;
  }
  v13 = Allocate(effPCPBlinkMultiBlurBase_tag);
  _ctor(v13, 0);
  pBlinkMultiBlurBase = v13;
  monitor = v5[2].monitor;
  pBlinkMultiBlurBase->hBlur = dds3EffectPartialMultiBlurCreate(monitor);
  pBlinkMultiBlurBase->abgr_base = *(*(v5[2].monitor + 3) + 16LL);
  pBlinkMultiBlurBase->abgr = -2139062144;
  sub_854930(&pBlinkMultiBlurBase->fields, 0);
  sub_854930(&pBlinkMultiBlurBase->fields, 1u);
  sub_854930(&pBlinkMultiBlurBase->fields, 2u);
  pBlinkMultiBlurBase->area = 0.0;
  pBlinkMultiBlurBase->frame = 0;
  pBlinkMultiBlurBase->blink = v5[1].klass;
  pBlinkMultiBlurBase->blink_base = v5[1].klass;
  v20 = v5[1].monitor;
  blink_abgr = pBlinkMultiBlurBase->blink_abgr;
  v22 = v20[8];
  blink_abgr->m_Items[0] = v22;
  v23 = v5[1].monitor;
  v24 = pBlinkMultiBlurBase->blink_abgr;
  v26 = v23[9];
  v24->m_Items[1] = v26;
  pBlinkMultiBlurBase->ratio = *&v5[2].klass;
  pBlinkMultiBlurBase->area_min = HIDWORD(v5[2].klass);
  if ((v12->_2.bitflags2 & 2) != 0)
  {
LABEL_14:
  }
LABEL_30:
  ++BlinkMultiBlurCount;
  return v10;
}

// 0x116a290
void effPCPBlinkMultiBlurDelete(void **hData) {
  dds3Effect_PartialMultiBlur_t_o **p_hBlur;

  --BlinkMultiBlurCount;
  if (!BlinkMultiBlurCount)
  {
    p_hBlur = &pBlinkMultiBlurBase->hBlur;
    dds3EffectPartialMultiBlurDelete(p_hBlur);
  }
}

// 0x116a370
void effPCPBlinkMultiBlurDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  u32 frame;
  effPCPMisc_c *v11;
  struct effPCPBlinkMultiBlurBase_tag_o *pBlinkMultiBlurBase;
  u32 v13;
  struct effPCPBlinkMultiBlurBase_tag_o *v14;
  u32 v15;
  struct System_UInt32_array *blink_abgr;
  s64 v17;
  dds3Effect_PartialMultiBlur_t_o *v19;
  struct System_Int32_array *pm;
  f32 v21;
  struct System_Int32_array *v23;
  f32 v25;
  struct dds3Effect_PartialMultiBlurParam_t_o *param;
  s32 area_min;
  struct dds3Effect_Blur_t_o *Blur;
  s32 ID;
  UnityEngine_Vector4_o v36;
  dds3Effect_PartialMultiBlur_t_o *hPartialMultiBlur;
  u64 v38[3];

  *&v36.z = 0;
  hPartialMultiBlur = 0;
  *&v36.x = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBlinkMultiBlur_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBlinkMultiBlur_tag, v38);
      if ((v38[0] & 1) != 0)
        v6 = v38[2];
      else
        v6 = v38 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = Allocate(dds3Effect_PartialMultiBlur_t);
  dds3Effect_PartialMultiBlur_t___ctor(v8);
  hPartialMultiBlur = v8;
  dds3Effect_PartialMultiBlur_t__Clear(v8);
  *&v36.x = 0;
  *&v36.z = 0;
  frame = v3[1].klass;
  if (frame)
  {
      goto LABEL_26;
    goto LABEL_12;
  }
  pBlinkMultiBlurBase->frame &= 1u;
  if (pBlinkMultiBlurBase->frame)
  {
    pBlinkMultiBlurBase->blink = pBlinkMultiBlurBase->blink_base + 1;
  }
  frame = pBlinkMultiBlurBase->frame;
  LODWORD(v3[1].klass) = frame;
  if ((v11->_2.bitflags2 & 2) != 0)
  {
LABEL_12:
  }
LABEL_26:
  v13 = pBlinkMultiBlurBase->frame;
  if (frame == v13)
  {
    ++LODWORD(v3[1].klass);
    v14 = pBlinkMultiBlurBase;
    hPartialMultiBlur = v14->hBlur;
    v15 = v14->frame;
    if (v15 < v14->blink)
    {
      blink_abgr = v14->blink_abgr;
      v17 = v15 & 1;
      v14->abgr_base = blink_abgr->m_Items[v17];
      SDF_VU0__LOADVECTOR(pBlinkMultiBlurBase->pos);
      v19 = hPartialMultiBlur;
      hPartialMultiBlur->param->area = (pBlinkMultiBlurBase->ratio
                                                    * effScreenArea(pBlinkMultiBlurBase->area));
      SDF_VU0__STOREVECTOR(&v36);
      pm = v19->param->Blur->center->pm;
      sub_854710(&v36, 0);
      pm->m_Items[0] = v21;
      v23 = v19->param->Blur->center->pm;
      sub_854710(&v36, 1u);
      v23->m_Items[1] = v25;
      param = v19->param;
      area_min = pBlinkMultiBlurBase->area_min;
      if (param->area < area_min)
      {
        param->area = area_min;
        param = v19->param;
      }
      Blur = param->Blur;
      Blur->abgr = effColorMultiply(pBlinkMultiBlurBase->abgr, pBlinkMultiBlurBase->abgr_base);
      if (effBTLSkillCheckRun())
      {
        ID = effBTLSkillGetID();
      }
      else
      {
        ID = 0;
      }
      dds3EffectPartialMultiBlurDraw(&hPartialMultiBlur, 0, ID);
      ++pBlinkMultiBlurBase->frame;
    }
  }
  else
  {
    LODWORD(v3[1].klass) = v13;
  }
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
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v7;
  effPCPBlurExp_tag_o *v8;
  char *v10;
  s64 *v11;
  u64 v12[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBlurExp_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBlurExp_tag, v12);
    if ((v12[0] & 1) != 0)
      v10 = v12[2];
    else
      v10 = v12 + 1;
    v11 = sub_8C4940(v10);
  }
  v7 = (*hData)[1].klass;
LABEL_9:
  v8 = Allocate(effPCPBlurExp_tag);
  _ctor(v8, 0);
  v8->param = v7;
  v8->frame = 0;
  v8->abgr = -2139062144;
  v8->abgr_base = *(v7->_1.byval_arg.data + 4);
  return v8;
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
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  effPCPBlurExp_tag_o *v10;
  u64 v12[3];

  v5 = *pData;
  else if (!v5)
  {
    goto LABEL_12;
  }
  klass = v5->klass;
  if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBlurExpParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBlurExpParam_t, v12);
    if ((v12[0] & 1) != 0)
      v8 = v12[2];
    else
      v8 = v12 + 1;
    v9 = sub_8C4940(v8);
  }
LABEL_12:
  v10 = Allocate(effPCPBlurExp_tag);
  _ctor(v10, 0);
  v10->param = v5;
  v10->frame = 0;
  v10->abgr = -2139062144;
  v10->abgr_base = v5[2].klass->_1.name;
  return v10;
}

// 0x116da80
effPCPBlurExp_tag *effPCPBlurExpCreatePCF(void **hData, s32 bPos, bool tbldata) {
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
  effPCPBlurExp_tag_o *v23;
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
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 13);
  else if (!DataUnityOffSet)
  {
    goto LABEL_24;
  }
  klass = DataUnityOffSet->klass;
  if (DataUnityOffSet->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBlurExpParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBlurExpParam_t, v25);
    if ((v25[0] & 1) != 0)
      v21 = v26;
    else
      v21 = v25 + 1;
    v22 = sub_8C4940(v21);
  }
LABEL_24:
  v23 = Allocate(effPCPBlurExp_tag);
  _ctor(v23, 0);
  v23->param = DataUnityOffSet;
  v23->frame = 0;
  v23->abgr = -2139062144;
  v23->abgr_base = DataUnityOffSet[2].klass->_1.name;
  return v23;
}

// 0x116dea0
void effPCPBlurExpDelete(void **hData) {

}

// 0x116dee0
void effPCPBlurExpDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppClass *v8;
  s32 v9;
  s32 name;
  s32 v11;
  s32 namespaze;
  s32 name_high;
  s64 v14;
  s64 v16;
  s64 v18;
  s64 v19;
  s64 v20;
  s64 v22;
  s64 v24;
  s64 v26;
  s64 v28;
  s64 v30;
  f32 v32;
  f32 v33;
  f32 v34;
  u32 v35;
  u32 *data;
  s32 ID;
  dds3Effect_Blur_t_o **p_byval_arg;
  u64 v43[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBlurExp_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBlurExp_tag, v43);
      if ((v43[0] & 1) != 0)
        v6 = v43[2];
      else
        v6 = v43 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = v3[1].klass;
  v9 = v3[2].klass;
  name = v8->_1.name;
  v11 = name - v9;
  if (name >= v9)
  {
    name_high = HIDWORD(v8->_1.name);
    namespaze = v8->_1.namespaze;
    v14 = *(*(v8->_1.byval_arg.data + 4) + 16LL);
    *(v14 + 32) = 0;
    v16 = *(*(v3[1].klass->_1.byval_arg.data + 4) + 16LL);
    *(v16 + 36) = 0;
    v18 = *(v3[1].klass->_1.byval_arg.data + 5);
    v19 = *(*(v18 + 32) + 16LL);
    *(v19 + 32) = 0;
    v20 = *(v3[1].klass->_1.byval_arg.data + 5);
    v22 = *(*(v20 + 32) + 16LL);
    *(v22 + 36) = 0;
    v24 = *(v3[1].klass->_1.byval_arg.data + 5);
    v26 = *(*(v24 + 40) + 16LL);
    *(v26 + 32) = 512;
    v28 = *(v3[1].klass->_1.byval_arg.data + 5);
    v30 = *(*(v28 + 40) + 16LL);
    *(v30 + 36) = 448;
    if (v9 < name_high && name_high)
    {
      v32 = v9;
      v33 = name_high;
    }
    else
    {
      v34 = 1.0;
      if (v11 > namespaze || !namespaze)
      {
LABEL_36:
        v35 = effColorBlend(v3[1].monitor & 0xFFFFFF, v3[1].monitor, v34);
        data = v3[1].klass->_1.byval_arg.data;
        data[4] = effColorMultiply(v35, HIDWORD(v3[1].monitor), 0);
        else if (effBTLSkillCheckRun())
        {
          goto LABEL_39;
        }
        ID = 0;
LABEL_47:
        p_byval_arg = &v3[1].klass->_1.byval_arg;
        dds3EffectBlur(p_byval_arg, 0, ID);
        ++LODWORD(v3[2].klass);
        return;
      }
      v32 = v11;
      v33 = namespaze;
    }
    v34 = v32 / v33;
    goto LABEL_36;
  }
}

// 0x116e2a0
void effPCPBlurExpSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBlurExp_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBlurExp_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[1].monitor) = abgr;
}

// 0x1171330
effPCPBreath_tag *effPCPBreathCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  struct effPCPBreathParam_t_o *v10;
  effPCPBreath_tag_o *v11;
  f32 v12;
  f32 v13;
  Il2CppObject **p_monitor;
  void *monitor;
  u64 v18[3];

  v5 = *hData;
  if (v5)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBreath_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBreath_tag, v18);
      if ((v18[0] & 1) != 0)
        v8 = v18[2];
      else
        v8 = v18 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = v5[5].klass;
LABEL_14:
  v11 = Allocate(effPCPBreath_tag);
  _ctor(v11, 0);
  v11->param = v10;
  v11->frame = 0;
  v12 = v10->angle * 0.017453;
  v11->rotate = v12 * -0.5;
  v13 = (v10->life - (v10->fade_out >> 1) - v10->start);
  v11->abgr = -2139062144;
  v11->speed = v12 / v13;
  SDF_VU0__STOREIDENTITY(&v11->matrix);
  v11->hD3P = 0;
  monitor = v5[6].monitor;
  p_monitor = &v5[6].monitor;
  if (monitor)
  {
    v11->hD3P = dds3EffectCopy(p_monitor, 0, 0);
  }
  return v11;
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
  struct dds3EffectPCPData_Part_t_array *v18;
  Il2CppObject *v19;
  effPCPBreathParam_t_o *v20;
  struct dds3EffectPCPData_Part_t_array *v24;
  u32 v26;
  effPCPBreathParam_t_c *klass;
  s64 typeHierarchyDepth;
  char *v29;
  s64 *v30;
  s32 pos;
  u64 v33[2];
  char *v34;

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v7->klass->_1.element_class, v8, v33);
      if ((v33[0] & 1) != 0)
        v10 = v34;
      else
        v10 = v33 + 1;
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
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 16);
  v18 = v6->pcpData;
  v19 = *hData;
  v20 = DataUnityOffSet;
  dds3EffectPCPDataGetDataUnityOffSet(v19, v18->m_Items[1]->offset + bPos, 16);
  v24 = v6->pcpData;
  v26 = v24->m_Items[1]->offset;
  else if (!v20)
  {
    return effPCPBreathCreate(v20, Interface, v26 + bPos);
  }
  klass = v20->klass;
  if (v20->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBreathParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBreathParam_t, v33);
    if ((v33[0] & 1) != 0)
      v29 = v34;
    else
      v29 = v33 + 1;
    v30 = sub_8C4940(v29);
  }
  return effPCPBreathCreate(v20, Interface, v26 + bPos);
}

// 0x1171530
void effPCPBreathDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppObject **p_monitor;
  void *monitor;
  char *v8;
  s64 *v9;
  u64 v10[3];

  v3 = *hData;
  klass = v3->klass;
  if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBreath_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBreath_tag, v10);
    if ((v10[0] & 1) != 0)
      v8 = v10[2];
    else
      v8 = v10 + 1;
    v9 = sub_8C4940(v8);
  }
  monitor = v3[6].monitor;
  p_monitor = &v3[6].monitor;
  if (monitor)
  {
    dds3EffectDelete(p_monitor);
  }
}

// 0x1171650
void effPCPBreathDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  Il2CppClass *v10;
  Il2CppObject *monitor;
  Il2CppClass *v12;
  s64 v13;
  char *v14;
  s64 *v15;
  s64 bits;
  s64 monitor_high;
  s64 v18;
  u32 TargetParty;
  f32 v22;
  f32 v23;
  f32 v25;
  f32 v26;
  f32 v28;
  f32 v29;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  f32 v36;
  u32 v39;
  UnityEngine_Matrix4x4_o v40;
  UnityEngine_Matrix4x4_o v41;
  UnityEngine_Matrix4x4_o dest;
  Il2CppObject *v43;
  Il2CppObject *pData;
  s64 v45;
  s64 v46;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *pFormation;
  UnityEngine_Vector4_o v49;
  UnityEngine_Vector4_o v50;
  UnityEngine_Matrix4x4_o aMatrix;
  UnityEngine_Vector4_o v52;

  pFormation = 0;
  memset(&aMatrix, 0, sizeof(aMatrix));
  *&v50.x = 0;
  *&v50.z = 0;
  *&v49.x = 0;
  *&v49.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  pData = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBreath_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBreath_tag, &v41);
      if ((LOBYTE(v41.m00) & 1) != 0)
        v6 = *&v41.m01;
      else
        v6 = &v41.m00 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  memset(&aMatrix, 0, sizeof(aMatrix));
  *&v50.x = 0;
  *&v50.z = 0;
  *&v49.x = 0;
  *&v49.z = 0;
  v8 = Allocate(effHandle_t);
  effHandle_t___ctor(v8);
  v10 = v3[5].klass;
  monitor = v3[6].monitor;
  if (monitor)
  {
    v12 = monitor->klass;
    if (monitor->klass->_2.typeHierarchyDepth < v13 || v12->_2.typeHierarchy[v13 - 1] != effHandle_t)
    {
      sub_8FC2C0(v12->_1.element_class, effHandle_t, &v41);
      if ((LOBYTE(v41.m00) & 1) != 0)
        v14 = *&v41.m01;
      else
        v14 = &v41.m00 + 1;
      v15 = sub_8C4940(v14);
    }
  }
  bits = v10->_1.byval_arg.bits;
  monitor_high = HIDWORD(v3[5].monitor);
  v18 = SHIDWORD(v10->_1.byval_arg.data) + bits;
  if (monitor_high <= v18)
  {
    if (effBTLSkillCheckRun() && !HIDWORD(v3[5].monitor))
    {
      *&p.x = 0;
      *&p.z = 0;
      v45 = 0;
      v46 = 0;
      pFormation = effBTLSkillGetInvokeFormation(0);
      TargetParty = effBTLSkillGetTargetParty();
      effBTLModelGroupGetCenter(TargetParty);
      SDF_VU0__STOREVECTOR(&p);
      effBTLModelGetSphereCenter(&pFormation);
      SDF_VU0__STOREVECTOR(&v50);
      sub_854710(&p, 0);
      sub_854710(&v50, 0);
      sub_854930(&v45, 0);
      sub_854710(&p, 2u);
      sub_854710(&v50, 2u);
      sub_854930(&v45, 2u);
      sub_854710(&v45, 0);
      v23 = v22;
      sub_854710(&v45, 2u);
      v26 = v25;
      *&v3[6].klass = sdfAtan2(v23, v26) + ((*(&v10->_1.byval_arg.bits + 1) * -0.017453) * 0.5);
    }
    if (monitor)
    {
      memmove(&dest, &v3[1], 0x40u);
      SDF_VU0__LOADMATRIX(&dest);
      v28 = *&v3[6].klass;
      SetRotateMatrixY_B(v28);
      MultMatrixNoArg();
      sub_854930(&v49, 1u);
      sub_854930(&v49, 0);
      v29 = 1.0;
      sub_854930(&v49, 2u);
      SDF_VU0__LOADVECTOR(v49);
      SDF_VU0__APPLYMATRIX_XYZ();
      sub_854930(&v50, 0);
      sub_854710(&v50, 0);
      sub_854930(&v50, 1u);
      sub_854930(&v50, 2u);
      SDF_VU0__LOADVECTOR_B(v50);
      SDF_VU0__MULVECTOR();
      SDF_VU0__LOADVECTOR_B(*&v10->_1.name);
      SDF_VU0__ADDVECTOR();
      SDF_VU0__STOREVECTOR(&v50);
      pData = monitor;
      x = v50.x;
      y = v50.y;
      z = v50.z;
      w = v50.w;
      v52.x = x;
      v52.y = y;
      v52.z = z;
      v52.w = w;
      dds3EffectSetPosition(&pData, v52);
      v36 = *&v3[6].klass;
      if (HIDWORD(v3[5].monitor) > SLODWORD(v10->_1.byval_arg.data))
      {
        v36 = v36 + *(&v3[6].klass + 1);
        *&v3[6].klass = v36;
      }
      SetRotateMatrixY(v36);
      SDF_VU0__STOREMATRIX(&aMatrix);
      v41 = aMatrix;
      v40 = v41;
      dds3EffectSetRotateMatrix(&pData, &v40);
      if (bits && v18 - monitor_high <= bits)
        v29 = (v18 - monitor_high) / bits;
      v39 = effColorBlend(v3[5].monitor & 0xFFFFFF, v3[5].monitor, v29);
      v43 = monitor;
      dds3EffectSetRGBA(&v43, v39);
      pData = monitor;
      dds3EffectDraw(&pData);
    }
    ++HIDWORD(v3[5].monitor);
  }
}

// 0x1171df0
void effPCPBreathSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBreath_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBreath_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[5].monitor) = abgr;
}

// 0x1171cd0
void effPCPBreathSetPosition(void **hData, sdfVector4_t pPos) {
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
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBreath_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBreath_tag, v12);
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
  SDF_VU0__COPYVECTOR(&(*hData)[5].klass->_1.name, v13, 0);
}

// 0x1171ee0
void effPCPBreathSetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
  Il2CppObject *v5;
  s64 v6;
  s64 v7;
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

  v5 = *hData;
  SetRotateMatrixY(3.1416);
  v6 = *&pMatrix->m00;
  v7 = *&pMatrix->m20;
  v8 = *&pMatrix->m21;
  *&v16.m01 = *&pMatrix->m01;
  *&v16.m21 = v8;
  *&v16.m00 = v6;
  *&v16.m20 = v7;
  v9 = *&pMatrix->m02;
  v10 = *&pMatrix->m22;
  v11 = *&pMatrix->m23;
  *&v16.m03 = *&pMatrix->m03;
  *&v16.m23 = v11;
  *&v16.m02 = v9;
  *&v16.m22 = v10;
  SDF_VU0__LOADMATRIX_B(&v16);
  MultMatrixNoArg();
  if (v5)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBreath_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBreath_tag, v17);
      if ((v17[0] & 1) != 0)
        v14 = v17[2];
      else
        v14 = v17 + 1;
      v15 = sub_8C4940(v14);
    }
  }
  SDF_VU0__STOREMATRIX(&v5[1]);
}

// 0x117a250
effPCPBufuIce_tag *effPCPBufuIceCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v6;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  u64 *v11;
  effPartHandle_t_o **v14;
  u64 v16[3];

  v6 = *hData;
  if (*hData)
  {
    klass = v6->klass;
    if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBufuIce_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBufuIce_tag, v16);
      if ((v16[0] & 1) != 0)
        v9 = v16[2];
      else
        v9 = v16 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  v11 = Allocate(effPCPBufuIce_tag);
  _ctor(v11, 0);
  *(v11 + 24) = 0;
  v11[13] = 0x808080803F800000LL;
  SDF_VU0__STOREIDENTITY((v11 + 4), 0);
  *(v11 + 25) = DDS3EFFECT_RAND_PM() * 0.87266;
  if ((DDS3EFFECT_RAND_I() & 1) != 0)
    *(v11 + 25) = *(v11 + 25) + 3.1416;
  v14 = &v6[7];
  v11[14] = dds3EffectPartCopy(v14, bPos, 0);
  return v11;
}

// 0x117a050
effPCPBufuIce_tag *effPCPBufuIceCreate(void **hData, s32 bPos, bool tbldata) {
  u64 *v6;
  s64 *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  u64 *v12;
  u64 v16[3];
  s32 pos;

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(v7, byte);
    if (!Interface)
    {
      sub_8FC2C0(*(*v7 + 64), v8, v16);
      if ((v16[0] & 1) != 0)
        v10 = v16[2];
      else
        v10 = v16 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v6, Interface, &pos);
  v12 = Allocate(effPCPBufuIce_tag);
  _ctor(v12, 0);
  *(v12 + 24) = 0;
  v12[13] = 0x808080803F800000LL;
  v12[14] = dds3EffectPCPDataPartCreate(v6, Interface, bPos, 0);
  SDF_VU0__STOREIDENTITY((v12 + 4), 0);
  *(v12 + 25) = DDS3EFFECT_RAND_PM() * 0.87266;
  if ((DDS3EFFECT_RAND_I() & 1) != 0)
    *(v12 + 25) = *(v12 + 25) + 3.1416;
  return v12;
}

// 0x117a410
void effPCPBufuIceDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  effPartHandle_t_o **v8;
  u64 v9[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBufuIce_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBufuIce_tag, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = &v3[7];
  dds3EffectPartDelete(v8);
}

// 0x117a530
void effPCPBufuIceDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  f32 v10;
  f32 v11;
  f32 v12;
  f32 v13;
  f32 v15;
  UnityEngine_Matrix4x4_o v16;
  UnityEngine_Matrix4x4_o dest;
  UnityEngine_Matrix4x4_o aMatrix;
  effPartHandle_t_o *v19[3];
  effPartHandle_t_o *hEffPart;
  UnityEngine_Vector4_o v21;

  hEffPart = 0;
  memset(&aMatrix, 0, sizeof(aMatrix));
  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBufuIce_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBufuIce_tag, v19);
      if ((v19[0] & 1) != 0)
        v6 = v19[2];
      else
        v6 = v19 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = Allocate(effPartHandle_t);
  effPartHandle_t___ctor(v8);
  memset(&aMatrix, 0, sizeof(aMatrix));
  hEffPart = v3[7].klass;
  v10 = *&v3[1].klass;
  v11 = *(&v3[1].klass + 1);
  v13 = *&v3[1].monitor;
  v12 = *(&v3[1].monitor + 1);
  v21.x = v10;
  v21.y = v11;
  v21.z = v13;
  v21.w = v12;
  dds3EffectPartSetPosition(&hEffPart, v21);
  dds3EffectPartSetScale(&hEffPart, *&v3[6].monitor);
  dds3EffectPartSetColor(&hEffPart, HIDWORD(v3[6].monitor), 0);
  v15 = *(&v3[6].klass + 1);
  SetRotateMatrixY(v15);
  memmove(&dest, &v3[2], 0x40u);
  SDF_VU0__LOADMATRIX_B(&dest);
  MultMatrixNoArg();
  SDF_VU0__STOREMATRIX(&aMatrix);
  v16 = aMatrix;
  dds3EffectPartSetRotateMatrix(&hEffPart, &v16);
  dds3EffectPartDraw(&hEffPart);
  ++LODWORD(v3[6].klass);
}

// 0x117a8b0
void effPCPBufuIceSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBufuIce_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBufuIce_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[6].monitor) = abgr;
}

// 0x117a780
void effPCPBufuIceSetPosition(void **hData, sdfVector4_t pPos) {
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
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != effPCPBufuIce_tag)
    {
      sub_8FC2C0(*(v9 + 64), effPCPBufuIce_tag, v13);
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

// 0x117aa90
void effPCPBufuIceSetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
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
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBufuIce_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBufuIce_tag, v17);
      if ((v17[0] & 1) != 0)
        v14 = v17[2];
      else
        v14 = v17 + 1;
      v15 = sub_8C4940(v14);
    }
  }
  SDF_VU0__STOREMATRIX(&v7[2]);
}

// 0x117a9a0
void effPCPBufuIceSetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBufuIce_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBufuIce_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *&(*hData)[6].monitor = scale;
}

// 0x117cdd0
effPCPMisc_effPCPBufuLight_t *effPCPBufuLightCopy(void **hData, s32 bPos, bool tbldata) {
  effPCPBufuLight_Start = 1;
  return 0;
}

// 0x117cc80
effPCPMisc_effPCPBufuLight_t *effPCPBufuLightCreate(void **hData, s32 bPos, bool tbldata) {
  u64 *v5;
  s64 *v6;
  Il2CppClass *v7;
  s64 *Interface;
  char *v9;
  s64 *v10;
  u64 v14[3];
  s32 pos;

  pos = bPos;
  v5 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v5);
  v6 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(v6, byte);
    if (!Interface)
    {
      sub_8FC2C0(*(*v6 + 64), v7, v14);
      if ((v14[0] & 1) != 0)
        v9 = v14[2];
      else
        v9 = v14 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v5, Interface, &pos);
  effPCPBufuLight_Start = 1;
  return 0;
}

// 0x117ce40
void effPCPBufuLightDelete(void **hData) {

}

// 0x117ce80
void effPCPBufuLightDraw(void **hData) {
  s64 v4;
  s64 v5;
  UnityEngine_Vector4_o v8;
  s64 v9;
  s64 v10;
  UnityEngine_Vector4_o v11;

  v9 = 0;
  v10 = 0;
  if (effPCPBufuLight_Start)
  {
    sub_854690(&v9, 1.41, -0.89, 0.48, 0.0);
    *&v8.x = 0;
    *&v8.z = 0;
    sub_854690(&v8.x, 0.70711, 0.70711, 0.0, 0.0);
    v4 = v9;
    v5 = v10;
    *&v11.x = v4;
    *&v11.z = v5;
    effBTLFieldLightDirectionSet(v11);
    effBTLFieldLightAxisSet(v8);
    effBTLFieldLightAnimationSet(14, 3.927);
    effPCPBufuLight_Start = 0;
  }
}

// 0x117bed0
effPCPBufudnIce_tag *effPCPBufudnIceCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v6;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  u64 *v11;
  u64 v13;
  Il2CppClass *v14;
  s64 *v16;
  s64 *v17;
  Il2CppClass *v19;
  u64 v20;
  s64 *v22;
  s64 *v23;
  u64 v29[3];

  v6 = *hData;
  if (*hData)
  {
    klass = v6->klass;
    if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBufudnIce_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBufudnIce_tag, v29);
      if ((v29[0] & 1) != 0)
        v9 = v29[2];
      else
        v9 = v29 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  v11 = Allocate(effPCPBufudnIce_tag);
  _ctor(v11, 0);
  *(v11 + 24) = 0;
  v13 = v11[14];
  v11[13] = 0x808080803F800000LL;
  v14 = v6[7].klass;
  else if (!LODWORD(v14->_1.namespaze))
  {
    goto LABEL_13;
  }
  v16 = dds3EffectPartCopy(&v14->_1.byval_arg, bPos, 0);
  v17 = v16;
  *(v13 + 32) = v17;
  v19 = v6[7].klass;
  v20 = v11[14];
  v22 = dds3EffectPartCopy(&v19->_1.byval_arg.bits, bPos, 0);
  v23 = v22;
  *(v20 + 40) = v23;
  SDF_VU0__STOREIDENTITY((v11 + 4), 0);
  *(v11 + 25) = DDS3EFFECT_RAND_PM() * 0.87266;
  return v11;
}

// 0x117bc20
effPCPBufudnIce_tag *effPCPBufudnIceCreate(void **hData, s32 bPos, bool tbldata) {
  u64 *v6;
  s64 *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  u64 *v12;
  u64 v14;
  s64 *v15;
  s64 *v16;
  u64 v18;
  s64 *v19;
  s64 *v20;
  s32 pos;
  u64 v27[3];

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(v7, byte);
    if (!Interface)
    {
      sub_8FC2C0(*(*v7 + 64), v8, v27);
      if ((v27[0] & 1) != 0)
        v10 = v27[2];
      else
        v10 = v27 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v6, Interface, &pos);
  v12 = Allocate(effPCPBufudnIce_tag);
  _ctor(v12, 0);
  *(v12 + 24) = 0;
  v12[13] = 0x808080803F800000LL;
  v14 = v12[14];
  v15 = dds3EffectPCPDataPartCreate(v6, Interface, bPos, 0);
  v16 = v15;
  *(v14 + 32) = v16;
  v18 = v12[14];
  v19 = dds3EffectPCPDataPartCreate(v6, Interface, bPos, 1u);
  v20 = v19;
  *(v18 + 40) = v20;
  SDF_VU0__STOREIDENTITY((v12 + 4), 0);
  *(v12 + 25) = DDS3EFFECT_RAND_PM() * 0.87266;
  return v12;
}

// 0x117c180
void effPCPBufudnIceDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v6;
  Il2CppClass *v8;
  char *v10;
  s64 *v11;
  u64 v12[3];

  v3 = *hData;
  klass = v3->klass;
  if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBufudnIce_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBufudnIce_tag, v12);
    if ((v12[0] & 1) != 0)
      v10 = v12[2];
    else
      v10 = v12 + 1;
    v11 = sub_8C4940(v10);
  }
  v6 = v3[7].klass;
  else if (LODWORD(v6->_1.namespaze) <= 1)
  {
    goto LABEL_8;
  }
  dds3EffectPartDelete(&v6->_1.byval_arg.bits);
  v8 = v3[7].klass;
  dds3EffectPartDelete(&v8->_1.byval_arg);
}

// 0x117c2f0
void effPCPBufudnIceDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  u64 *v10;
  Il2CppClass *v11;
  void *data;
  Il2CppClass *v15;
  s64 v17;
  f32 v19;
  f32 v20;
  f32 v21;
  f32 v22;
  f32 v30;
  s32 v35;
  UnityEngine_Matrix4x4_o v39;
  UnityEngine_Matrix4x4_o v40;
  UnityEngine_Matrix4x4_o v41;
  UnityEngine_Matrix4x4_o v42;
  UnityEngine_Matrix4x4_o dest;
  UnityEngine_Matrix4x4_o aMatrix;
  UnityEngine_Vector4_o v45;

  memset(&aMatrix, 0, sizeof(aMatrix));
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBufudnIce_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBufudnIce_tag, &v42);
      if ((LOBYTE(v42.m00) & 1) != 0)
        v6 = *&v42.m01;
      else
        v6 = &v42.m00 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = NewSpecific(effPartHandle_t, 2u);
  v10 = v8;
  memset(&aMatrix, 0, sizeof(aMatrix));
  v11 = v3[7].klass;
  data = v11->_1.byval_arg.data;
  v10[4] = data;
  v15 = v3[7].klass;
  v17 = *&v15->_1.byval_arg.bits;
  v10[5] = v17;
  v19 = *&v3[1].klass;
  v20 = *(&v3[1].klass + 1);
  v22 = *&v3[1].monitor;
  v21 = *(&v3[1].monitor + 1);
  else if (!*(v10 + 6))
  {
    goto LABEL_25;
  }
  v45.x = v19;
  v45.y = v20;
  v45.z = v22;
  v45.w = v21;
  dds3EffectPartSetPosition(v10 + 4, v45);
  dds3EffectPartSetPosition(v10 + 5, v3[1]);
  dds3EffectPartSetScale(v10 + 4, *&v3[6].monitor);
  dds3EffectPartSetScale(v10 + 5, *&v3[6].monitor);
  dds3EffectPartSetColor(v10 + 4, HIDWORD(v3[6].monitor), 0);
  dds3EffectPartSetColor(v10 + 5, HIDWORD(v3[6].monitor), 0);
  v30 = *(&v3[6].klass + 1);
  SetRotateMatrixY(v30);
  memmove(&dest, &v3[2], 0x40u);
  SDF_VU0__LOADMATRIX_B(&dest);
  MultMatrixNoArg();
  SDF_VU0__STOREMATRIX(&aMatrix);
  v42 = aMatrix;
  v41 = v42;
  dds3EffectPartSetRotateMatrix(v10 + 4, &v41);
  v40 = aMatrix;
  v39 = v40;
  dds3EffectPartSetRotateMatrix(v10 + 5, &v39);
  dds3EffectPartDraw(v10 + 4);
  v35 = v3[6].klass;
  if (v35 >= 31)
  {
    dds3EffectPartDraw(v10 + 5);
    v35 = v3[6].klass;
  }
  LODWORD(v3[6].klass) = v35 + 1;
}

// 0x117c970
void effPCPBufudnIceSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBufudnIce_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBufudnIce_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[6].monitor) = abgr;
}

// 0x117c840
void effPCPBufudnIceSetPosition(void **hData, sdfVector4_t pPos) {
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
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != effPCPBufudnIce_tag)
    {
      sub_8FC2C0(*(v9 + 64), effPCPBufudnIce_tag, v13);
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

// 0x117cb50
void effPCPBufudnIceSetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
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
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBufudnIce_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBufudnIce_tag, v17);
      if ((v17[0] & 1) != 0)
        v14 = v17[2];
      else
        v14 = v17 + 1;
      v15 = sub_8C4940(v14);
    }
  }
  SDF_VU0__STOREMATRIX(&v7[2]);
}

// 0x117ca60
void effPCPBufudnIceSetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBufudnIce_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBufudnIce_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *&(*hData)[6].monitor = scale;
}

// 0x117ae70
effPCPBufuraIce_tag *effPCPBufuraIceCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v6;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  u64 *v11;
  u64 v13;
  Il2CppClass *v14;
  s64 *v16;
  s64 *v17;
  Il2CppClass *v19;
  u64 v20;
  s64 *v22;
  s64 *v23;
  u64 v29[3];

  v6 = *hData;
  if (*hData)
  {
    klass = v6->klass;
    if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBufuraIce_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBufuraIce_tag, v29);
      if ((v29[0] & 1) != 0)
        v9 = v29[2];
      else
        v9 = v29 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  v11 = Allocate(effPCPBufuraIce_tag);
  _ctor(v11, 0);
  *(v11 + 24) = 0;
  v13 = v11[14];
  v11[13] = 0x808080803F800000LL;
  v14 = v6[7].klass;
  else if (!LODWORD(v14->_1.namespaze))
  {
    goto LABEL_13;
  }
  v16 = dds3EffectPartCopy(&v14->_1.byval_arg, bPos, 0);
  v17 = v16;
  *(v13 + 32) = v17;
  v19 = v6[7].klass;
  v20 = v11[14];
  v22 = dds3EffectPartCopy(&v19->_1.byval_arg.bits, bPos, 0);
  v23 = v22;
  *(v20 + 40) = v23;
  SDF_VU0__STOREIDENTITY((v11 + 4), 0);
  *(v11 + 25) = DDS3EFFECT_RAND_PM() * 0.87266;
  return v11;
}

// 0x117abc0
effPCPBufuraIce_tag *effPCPBufuraIceCreate(void **hData, s32 bPos, bool tbldata) {
  u64 *v6;
  s64 *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  u64 *v12;
  u64 v14;
  s64 *v15;
  s64 *v16;
  u64 v18;
  s64 *v19;
  s64 *v20;
  s32 pos;
  u64 v27[3];

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(v7, byte);
    if (!Interface)
    {
      sub_8FC2C0(*(*v7 + 64), v8, v27);
      if ((v27[0] & 1) != 0)
        v10 = v27[2];
      else
        v10 = v27 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v6, Interface, &pos);
  v12 = Allocate(effPCPBufuraIce_tag);
  _ctor(v12, 0);
  *(v12 + 24) = 0;
  v12[13] = 0x808080803F800000LL;
  v14 = v12[14];
  v15 = dds3EffectPCPDataPartCreate(v6, Interface, bPos, 0);
  v16 = v15;
  *(v14 + 32) = v16;
  v18 = v12[14];
  v19 = dds3EffectPCPDataPartCreate(v6, Interface, bPos, 1u);
  v20 = v19;
  *(v18 + 40) = v20;
  SDF_VU0__STOREIDENTITY((v12 + 4), 0);
  *(v12 + 25) = DDS3EFFECT_RAND_PM() * 0.87266;
  return v12;
}

// 0x117b120
void effPCPBufuraIceDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v6;
  Il2CppClass *v8;
  char *v10;
  s64 *v11;
  u64 v12[3];

  v3 = *hData;
  klass = v3->klass;
  if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBufuraIce_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBufuraIce_tag, v12);
    if ((v12[0] & 1) != 0)
      v10 = v12[2];
    else
      v10 = v12 + 1;
    v11 = sub_8C4940(v10);
  }
  v6 = v3[7].klass;
  else if (LODWORD(v6->_1.namespaze) <= 1)
  {
    goto LABEL_8;
  }
  dds3EffectPartDelete(&v6->_1.byval_arg.bits);
  v8 = v3[7].klass;
  dds3EffectPartDelete(&v8->_1.byval_arg);
}

// 0x117b290
void effPCPBufuraIceDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  u64 *v10;
  Il2CppClass *v11;
  void *data;
  Il2CppClass *v15;
  s64 v17;
  f32 v19;
  f32 v20;
  f32 v21;
  f32 v22;
  f32 v30;
  s32 v35;
  UnityEngine_Matrix4x4_o v39;
  UnityEngine_Matrix4x4_o v40;
  UnityEngine_Matrix4x4_o v41;
  UnityEngine_Matrix4x4_o v42;
  UnityEngine_Matrix4x4_o dest;
  UnityEngine_Matrix4x4_o aMatrix;
  UnityEngine_Vector4_o v45;

  memset(&aMatrix, 0, sizeof(aMatrix));
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBufuraIce_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBufuraIce_tag, &v42);
      if ((LOBYTE(v42.m00) & 1) != 0)
        v6 = *&v42.m01;
      else
        v6 = &v42.m00 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = NewSpecific(effPartHandle_t, 2u);
  v10 = v8;
  memset(&aMatrix, 0, sizeof(aMatrix));
  v11 = v3[7].klass;
  data = v11->_1.byval_arg.data;
  v10[4] = data;
  v15 = v3[7].klass;
  v17 = *&v15->_1.byval_arg.bits;
  v10[5] = v17;
  v19 = *&v3[1].klass;
  v20 = *(&v3[1].klass + 1);
  v22 = *&v3[1].monitor;
  v21 = *(&v3[1].monitor + 1);
  else if (!*(v10 + 6))
  {
    goto LABEL_25;
  }
  v45.x = v19;
  v45.y = v20;
  v45.z = v22;
  v45.w = v21;
  dds3EffectPartSetPosition(v10 + 4, v45);
  dds3EffectPartSetPosition(v10 + 5, v3[1]);
  dds3EffectPartSetScale(v10 + 4, *&v3[6].monitor);
  dds3EffectPartSetScale(v10 + 5, *&v3[6].monitor);
  dds3EffectPartSetColor(v10 + 4, HIDWORD(v3[6].monitor), 0);
  dds3EffectPartSetColor(v10 + 5, HIDWORD(v3[6].monitor), 0);
  v30 = *(&v3[6].klass + 1);
  SetRotateMatrixY(v30);
  memmove(&dest, &v3[2], 0x40u);
  SDF_VU0__LOADMATRIX_B(&dest);
  MultMatrixNoArg();
  SDF_VU0__STOREMATRIX(&aMatrix);
  v42 = aMatrix;
  v41 = v42;
  dds3EffectPartSetRotateMatrix(v10 + 4, &v41);
  v40 = aMatrix;
  v39 = v40;
  dds3EffectPartSetRotateMatrix(v10 + 5, &v39);
  dds3EffectPartDraw(v10 + 4);
  v35 = v3[6].klass;
  if (v35 >= 31)
  {
    dds3EffectPartDraw(v10 + 5);
    v35 = v3[6].klass;
  }
  LODWORD(v3[6].klass) = v35 + 1;
}

// 0x117b910
void effPCPBufuraIceSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBufuraIce_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBufuraIce_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[6].monitor) = abgr;
}

// 0x117b7e0
void effPCPBufuraIceSetPosition(void **hData, sdfVector4_t pPos) {
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
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != effPCPBufuraIce_tag)
    {
      sub_8FC2C0(*(v9 + 64), effPCPBufuraIce_tag, v13);
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

// 0x117baf0
void effPCPBufuraIceSetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
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
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBufuraIce_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPBufuraIce_tag, v17);
      if ((v17[0] & 1) != 0)
        v14 = v17[2];
      else
        v14 = v17 + 1;
      v15 = sub_8C4940(v14);
    }
  }
  SDF_VU0__STOREMATRIX(&v7[2]);
}

// 0x117ba00
void effPCPBufuraIceSetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBufuraIce_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPBufuraIce_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *&(*hData)[6].monitor = scale;
}

// 0x116e7d0
effPCPDistortionBlurExp_tag *effPCPDistortionBlurExpCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  effPCPDistortionBlurExpParam_t_o *v10;
  u64 v13[3];

  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPDistortionBlurExp_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPDistortionBlurExp_tag, v13);
      if ((v13[0] & 1) != 0)
        v8 = v13[2];
      else
        v8 = v13 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = Allocate(effPCPDistortionBlurExpParam_t);
  effPCPDistortionBlurExpParam_t___ctor(v10);
  v10->type = v5[2].klass;
  v10->life = HIDWORD(v5[2].klass);
  v10->fade_in = v5[2].monitor;
  v10->fade_out = HIDWORD(v5[2].monitor);
  v10->area_s = v5[3].monitor;
  v10->area_e = HIDWORD(v5[3].monitor);
  v10->DistBlur = *(v5[4].monitor + 2);
  return effPCPDistortionBlurExpCreate(v10);
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
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v11[3];

  v5 = *pData;
  else if (!v5)
  {
    return effPCPDistortionBlurExpCreate(v5, *&bPos);
  }
  klass = v5->klass;
  if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPDistortionBlurExpParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPDistortionBlurExpParam_t, v11);
    if ((v11[0] & 1) != 0)
      v8 = v11[2];
    else
      v8 = v11 + 1;
    v9 = sub_8C4940(v8);
  }
  return effPCPDistortionBlurExpCreate(v5, *&bPos);
}

// 0x116e590
effPCPDistortionBlurExp_tag *effPCPDistortionBlurExpCreatePCF(void **hData, s32 bPos, bool tbldata) {
  dds3EffectPCPData_t_o *v6;
  Il2CppObject *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  struct dds3EffectPCPData_Part_t_array *pcpData;
  Il2CppObject *v14;
  u32 offset;
  effPCPDistortionBlurExpParam_t_c *v17;
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
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 14);
  else if (!DataUnityOffSet)
  {
    return effPCPDistortionBlurExpCreate(DataUnityOffSet, v17);
  }
  klass = DataUnityOffSet->klass;
  if (DataUnityOffSet->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPDistortionBlurExpParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPDistortionBlurExpParam_t, v24);
    if ((v24[0] & 1) != 0)
      v21 = v25;
    else
      v21 = v24 + 1;
    v22 = sub_8C4940(v21);
  }
  return effPCPDistortionBlurExpCreate(DataUnityOffSet, v17);
}

// 0x116e940
void effPCPDistortionBlurExpDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  effDistortionBlurHandle_t_o **p_monitor;
  u64 v9[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPDistortionBlurExp_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPDistortionBlurExp_tag, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  p_monitor = &v3[4].monitor;
  dds3EffectDistortionBlurDelete(p_monitor);
}

// 0x116ea60
void effPCPDistortionBlurExpDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s32 v8;
  s32 klass_high;
  s32 v10;
  void **p_monitor;
  s32 monitor_high;
  s32 monitor;
  s64 v14;
  s64 v16;
  s64 v18;
  f32 v19;
  s64 v21;
  f32 v22;
  f32 v24;
  u32 v25;
  s64 v26;
  s32 ID;
  UnityEngine_Vector4_o p;
  u64 v31[3];

  *&p.x = 0;
  *&p.z = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPDistortionBlurExp_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPDistortionBlurExp_tag, v31);
      if ((v31[0] & 1) != 0)
        v6 = v31[2];
      else
        v6 = v31 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  *&p.x = 0;
  *&p.z = 0;
  v8 = v3[4].klass;
  klass_high = HIDWORD(v3[2].klass);
  v10 = klass_high - v8;
  if (klass_high >= v8)
  {
    p_monitor = &v3[4].monitor;
    monitor = v3[2].monitor;
    monitor_high = HIDWORD(v3[2].monitor);
    *(*(v3[4].monitor + 2) + 56LL) = (SLODWORD(v3[3].monitor)
                                    + ((v8 * (HIDWORD(v3[3].monitor) - LODWORD(v3[3].monitor))) / klass_high));
    if (LOBYTE(v3[2].klass))
    {
      v14 = *(*(*(*p_monitor + 2) + 48LL) + 16LL);
      *(v14 + 32) = 0;
      v16 = *(*(*(*p_monitor + 2) + 48LL) + 16LL);
      *(v16 + 36) = 0;
      if (v8 >= monitor)
        goto LABEL_25;
    }
    else
    {
      SDF_VU0__LOADVECTOR(v3[1]);
      effScreenOffset();
      SDF_VU0__STOREVECTOR(&p);
      v18 = *(*(*(v3[4].monitor + 2) + 48LL) + 16LL);
      sub_854710(&p, 0);
      *(v18 + 32) = v19;
      v21 = *(*(*(*p_monitor + 2) + 48LL) + 16LL);
      sub_854710(&p, 1u);
      *(v21 + 36) = -v22;
      if (v8 >= monitor)
        goto LABEL_25;
    }
    if (monitor)
    {
      v24 = v8 / monitor;
      goto LABEL_28;
    }
LABEL_25:
    v24 = 1.0;
    if (v10 <= monitor_high && monitor_high)
      v24 = v10 / monitor_high;
LABEL_28:
    v25 = effColorBlend(v3[3].klass & 0xFFFFFF, v3[3].klass, v24);
    v26 = *(v3[4].monitor + 2);
    *(v26 + 28) = effColorMultiply(v25, HIDWORD(v3[3].klass), 0);
    else if (effBTLSkillCheckRun())
    {
      goto LABEL_31;
    }
    ID = 0;
LABEL_37:
    dds3EffectDistortionBlurDraw(&v3[4].monitor, 0, ID);
    ++LODWORD(v3[4].klass);
  }
}

// 0x116ef20
void effPCPDistortionBlurExpSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPDistortionBlurExp_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPDistortionBlurExp_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[3].klass) = abgr;
}

// 0x116edf0
void effPCPDistortionBlurExpSetPosition(void **hData, sdfVector4_t pPos) {
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
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != effPCPDistortionBlurExp_tag)
    {
      sub_8FC2C0(*(v9 + 64), effPCPDistortionBlurExp_tag, v13);
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
  effPCPEyeThunder_tag_o *v6;
  effPCPEyeThunder_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  Il2CppObject *v13[3];
  Il2CppObject *hDataa;

  hDataa = 0;
  if (tbldata)
  {
    v6 = *hData;
    if (v6)
    {
      klass = v6->klass;
      if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPEyeThunder_tag)
      {
        sub_8FC2C0(klass->_1.element_class, effPCPEyeThunder_tag, v13);
        if ((v13[0] & 1) != 0)
          v9 = v13[2];
        else
          v9 = v13 + 1;
        v10 = sub_8C4940(v9);
      }
    }
  }
  else
  {
    v6 = Allocate(effPCPEyeThunder_tag);
    _ctor(v6, 0);
  }
  *&v6->start = 0x43BB800000000000LL;
  hDataa = effPCP_Eye_ThunderPoly_Param00_0;
  v6->pThunderPoly = effPCP_ThunderPolyCreate(&hDataa, 0, 1, 0);
  return v6;
}

// 0x117d1d0
effPCPEyeThunder_tag *effPCPEyeThunderCreate00_1(void **hData, s32 bPos, bool tbldata) {
  effPCPEyeThunder_tag_o *v6;
  effPCPEyeThunder_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  Il2CppObject *v13[3];
  Il2CppObject *hDataa;

  hDataa = 0;
  if (tbldata)
  {
    v6 = *hData;
    if (v6)
    {
      klass = v6->klass;
      if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPEyeThunder_tag)
      {
        sub_8FC2C0(klass->_1.element_class, effPCPEyeThunder_tag, v13);
        if ((v13[0] & 1) != 0)
          v9 = v13[2];
        else
          v9 = v13 + 1;
        v10 = sub_8C4940(v9);
      }
    }
  }
  else
  {
    v6 = Allocate(effPCPEyeThunder_tag);
    _ctor(v6, 0);
  }
  *&v6->start = 0x4361000043A28000LL;
  hDataa = effPCP_Eye_ThunderPoly_Param00_1;
  v6->pThunderPoly = effPCP_ThunderPolyCreate(&hDataa, 0, 1, 0);
  return v6;
}

// 0x117d3c0
effPCPEyeThunder_tag *effPCPEyeThunderCreate01_0(void **hData, s32 bPos, bool tbldata) {
  effPCPEyeThunder_tag_o *v6;
  effPCPEyeThunder_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  Il2CppObject *v13[3];
  Il2CppObject *hDataa;

  hDataa = 0;
  if (tbldata)
  {
    v6 = *hData;
    if (v6)
    {
      klass = v6->klass;
      if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPEyeThunder_tag)
      {
        sub_8FC2C0(klass->_1.element_class, effPCPEyeThunder_tag, v13);
        if ((v13[0] & 1) != 0)
          v9 = v13[2];
        else
          v9 = v13 + 1;
        v10 = sub_8C4940(v9);
      }
    }
  }
  else
  {
    v6 = Allocate(effPCPEyeThunder_tag);
    _ctor(v6, 0);
  }
  *&v6->start = 0x43BB800000000000LL;
  hDataa = effPCP_Eye_ThunderPoly_Param01_0;
  v6->pThunderPoly = effPCP_ThunderPolyCreate(&hDataa, 0, 1, 0);
  return v6;
}

// 0x117d5b0
effPCPEyeThunder_tag *effPCPEyeThunderCreate01_1(void **hData, s32 bPos, bool tbldata) {
  effPCPEyeThunder_tag_o *v6;
  effPCPEyeThunder_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  Il2CppObject *v13[3];
  Il2CppObject *hDataa;

  hDataa = 0;
  if (tbldata)
  {
    v6 = *hData;
    if (v6)
    {
      klass = v6->klass;
      if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPEyeThunder_tag)
      {
        sub_8FC2C0(klass->_1.element_class, effPCPEyeThunder_tag, v13);
        if ((v13[0] & 1) != 0)
          v9 = v13[2];
        else
          v9 = v13 + 1;
        v10 = sub_8C4940(v9);
      }
    }
  }
  else
  {
    v6 = Allocate(effPCPEyeThunder_tag);
    _ctor(v6, 0);
  }
  *&v6->start = 0x4361000043A28000LL;
  hDataa = effPCP_Eye_ThunderPoly_Param01_1;
  v6->pThunderPoly = effPCP_ThunderPolyCreate(&hDataa, 0, 1, 0);
  return v6;
}

// 0x117d7a0
effPCPEyeThunder_tag *effPCPEyeThunderCreate02_0(void **hData, s32 bPos, bool tbldata) {
  effPCPEyeThunder_tag_o *v6;
  effPCPEyeThunder_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  Il2CppObject *v13[3];
  Il2CppObject *hDataa;

  hDataa = 0;
  if (tbldata)
  {
    v6 = *hData;
    if (v6)
    {
      klass = v6->klass;
      if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPEyeThunder_tag)
      {
        sub_8FC2C0(klass->_1.element_class, effPCPEyeThunder_tag, v13);
        if ((v13[0] & 1) != 0)
          v9 = v13[2];
        else
          v9 = v13 + 1;
        v10 = sub_8C4940(v9);
      }
    }
  }
  else
  {
    v6 = Allocate(effPCPEyeThunder_tag);
    _ctor(v6, 0);
  }
  *&v6->start = 0x43BB800000000000LL;
  hDataa = effPCP_Eye_ThunderPoly_Param02_0;
  v6->pThunderPoly = effPCP_ThunderPolyCreate(&hDataa, 0, 1, 0);
  return v6;
}

// 0x117d990
effPCPEyeThunder_tag *effPCPEyeThunderCreate02_1(void **hData, s32 bPos, bool tbldata) {
  effPCPEyeThunder_tag_o *v6;
  effPCPEyeThunder_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  Il2CppObject *v13[3];
  Il2CppObject *hDataa;

  hDataa = 0;
  if (tbldata)
  {
    v6 = *hData;
    if (v6)
    {
      klass = v6->klass;
      if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPEyeThunder_tag)
      {
        sub_8FC2C0(klass->_1.element_class, effPCPEyeThunder_tag, v13);
        if ((v13[0] & 1) != 0)
          v9 = v13[2];
        else
          v9 = v13 + 1;
        v10 = sub_8C4940(v9);
      }
    }
  }
  else
  {
    v6 = Allocate(effPCPEyeThunder_tag);
    _ctor(v6, 0);
  }
  *&v6->start = 0x4361000043A28000LL;
  hDataa = effPCP_Eye_ThunderPoly_Param02_1;
  v6->pThunderPoly = effPCP_ThunderPolyCreate(&hDataa, 0, 1, 0);
  return v6;
}

// 0x117db80
effPCPEyeThunder_tag *effPCPEyeThunderCreate03_0(void **hData, s32 bPos, bool tbldata) {
  effPCPEyeThunder_tag_o *v6;
  effPCPEyeThunder_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  Il2CppObject *v13[3];
  Il2CppObject *hDataa;

  hDataa = 0;
  if (tbldata)
  {
    v6 = *hData;
    if (v6)
    {
      klass = v6->klass;
      if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPEyeThunder_tag)
      {
        sub_8FC2C0(klass->_1.element_class, effPCPEyeThunder_tag, v13);
        if ((v13[0] & 1) != 0)
          v9 = v13[2];
        else
          v9 = v13 + 1;
        v10 = sub_8C4940(v9);
      }
    }
  }
  else
  {
    v6 = Allocate(effPCPEyeThunder_tag);
    _ctor(v6, 0);
  }
  *&v6->start = 0x43BB800000000000LL;
  hDataa = effPCP_Eye_ThunderPoly_Param03_0;
  v6->pThunderPoly = effPCP_ThunderPolyCreate(&hDataa, 0, 1, 0);
  return v6;
}

// 0x117dd70
effPCPEyeThunder_tag *effPCPEyeThunderCreate03_1(void **hData, s32 bPos, bool tbldata) {
  effPCPEyeThunder_tag_o *v6;
  effPCPEyeThunder_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  Il2CppObject *v13[3];
  Il2CppObject *hDataa;

  hDataa = 0;
  if (tbldata)
  {
    v6 = *hData;
    if (v6)
    {
      klass = v6->klass;
      if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPEyeThunder_tag)
      {
        sub_8FC2C0(klass->_1.element_class, effPCPEyeThunder_tag, v13);
        if ((v13[0] & 1) != 0)
          v9 = v13[2];
        else
          v9 = v13 + 1;
        v10 = sub_8C4940(v9);
      }
    }
  }
  else
  {
    v6 = Allocate(effPCPEyeThunder_tag);
    _ctor(v6, 0);
  }
  *&v6->start = 0x4361000043A28000LL;
  hDataa = effPCP_Eye_ThunderPoly_Param03_1;
  v6->pThunderPoly = effPCP_ThunderPolyCreate(&hDataa, 0, 1, 0);
  return v6;
}

// 0x117df60
effPCPEyeThunder_tag *effPCPEyeThunderCreate04_0(void **hData, s32 bPos, bool tbldata) {
  effPCPEyeThunder_tag_o *v6;
  effPCPEyeThunder_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  Il2CppObject *v13[3];
  Il2CppObject *hDataa;

  hDataa = 0;
  if (tbldata)
  {
    v6 = *hData;
    if (v6)
    {
      klass = v6->klass;
      if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPEyeThunder_tag)
      {
        sub_8FC2C0(klass->_1.element_class, effPCPEyeThunder_tag, v13);
        if ((v13[0] & 1) != 0)
          v9 = v13[2];
        else
          v9 = v13 + 1;
        v10 = sub_8C4940(v9);
      }
    }
  }
  else
  {
    v6 = Allocate(effPCPEyeThunder_tag);
    _ctor(v6, 0);
  }
  *&v6->start = 0x43BB800000000000LL;
  hDataa = effPCP_Eye_ThunderPoly_Param04_0;
  v6->pThunderPoly = effPCP_ThunderPolyCreate(&hDataa, 0, 1, 0);
  return v6;
}

// 0x117e150
effPCPEyeThunder_tag *effPCPEyeThunderCreate04_1(void **hData, s32 bPos, bool tbldata) {
  effPCPEyeThunder_tag_o *v6;
  effPCPEyeThunder_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  u64 *v11;
  s64 *v12;
  Il2CppClass *v13;
  s64 *Interface;
  char *v15;
  s64 *v16;
  Il2CppObject *effPCP_Eye_ThunderPoly_Param04_1;
  u64 v20[2];
  char *v21;
  s32 pos;

  pos = bPos;
  effPCP_Eye_ThunderPoly_Param04_1 = 0;
  if (tbldata)
  {
    v6 = *hData;
    if (*hData)
    {
      klass = v6->klass;
      if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPEyeThunder_tag)
      {
        sub_8FC2C0(klass->_1.element_class, effPCPEyeThunder_tag, v20);
        if ((v20[0] & 1) != 0)
          v9 = v21;
        else
          v9 = v20 + 1;
        v10 = sub_8C4940(v9);
      }
    }
  }
  else
  {
    v11 = Allocate(dds3EffectPCPData_t);
    dds3EffectPCPData_t___ctor(v11);
    v12 = *hData;
    if (*hData)
    {
      Interface = QueryInterface(v12, byte);
      if (!Interface)
      {
        sub_8FC2C0(*(*v12 + 64), v13, v20);
        if ((v20[0] & 1) != 0)
          v15 = v21;
        else
          v15 = v20 + 1;
        v16 = sub_8C4940(v15);
      }
    }
    else
    {
      Interface = 0;
    }
    dds3EffectPCPData_t__pCopy(v11, Interface, &pos);
    v6 = Allocate(effPCPEyeThunder_tag);
    _ctor(v6, 0);
  }
  *&v6->start = 0x4361000043A28000LL;
  v6->pThunderPoly = effPCP_ThunderPolyCreate(&effPCP_Eye_ThunderPoly_Param04_1, 0, 1, 0);
  return v6;
}

// 0x117e3f0
effPCPEyeThunder_tag *effPCPEyeThunderCreate05_0(void **hData, s32 bPos, bool tbldata) {
  effPCPEyeThunder_tag_o *v6;
  effPCPEyeThunder_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  Il2CppObject *v13[3];
  Il2CppObject *hDataa;

  hDataa = 0;
  if (tbldata)
  {
    v6 = *hData;
    if (v6)
    {
      klass = v6->klass;
      if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPEyeThunder_tag)
      {
        sub_8FC2C0(klass->_1.element_class, effPCPEyeThunder_tag, v13);
        if ((v13[0] & 1) != 0)
          v9 = v13[2];
        else
          v9 = v13 + 1;
        v10 = sub_8C4940(v9);
      }
    }
  }
  else
  {
    v6 = Allocate(effPCPEyeThunder_tag);
    _ctor(v6, 0);
  }
  *&v6->start = 0x43BB800000000000LL;
  hDataa = effPCP_Eye_ThunderPoly_Param05_0;
  v6->pThunderPoly = effPCP_ThunderPolyCreate(&hDataa, 0, 1, 0);
  return v6;
}

// 0x117e5e0
effPCPEyeThunder_tag *effPCPEyeThunderCreate05_1(void **hData, s32 bPos, bool tbldata) {
  effPCPEyeThunder_tag_o *v6;
  effPCPEyeThunder_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  Il2CppObject *v13[3];
  Il2CppObject *hDataa;

  hDataa = 0;
  if (tbldata)
  {
    v6 = *hData;
    if (v6)
    {
      klass = v6->klass;
      if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPEyeThunder_tag)
      {
        sub_8FC2C0(klass->_1.element_class, effPCPEyeThunder_tag, v13);
        if ((v13[0] & 1) != 0)
          v9 = v13[2];
        else
          v9 = v13 + 1;
        v10 = sub_8C4940(v9);
      }
    }
  }
  else
  {
    v6 = Allocate(effPCPEyeThunder_tag);
    _ctor(v6, 0);
  }
  *&v6->start = 0x4361000043A28000LL;
  hDataa = effPCP_Eye_ThunderPoly_Param05_1;
  v6->pThunderPoly = effPCP_ThunderPolyCreate(&hDataa, 0, 1, 0);
  return v6;
}

// 0x117e7d0
void effPCPEyeThunderDelete(void **hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  Il2CppClass *v7;
  u64 v8[3];

  v7 = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPEyeThunder_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPEyeThunder_tag, v8);
    if ((v8[0] & 1) != 0)
      v5 = v8[2];
    else
      v5 = v8 + 1;
    v6 = sub_8C4940(v5);
  }
  v7 = (*hData)[3].klass;
  effPCP_ThunderPolyDelete(&v7);
}

// 0x117e8d0
void effPCPEyeThunderDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  effPCP_ThunderPolyParam_t_o *Param;
  struct UnityEngine_Vector4_array *pos;
  struct UnityEngine_Vector4_array *v13;
  Il2CppClass *v15;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v17;
  nbFormation_t_o *v18[3];
  nbFormation_t_o *pFormation;

  pFormation = 0;
  *&v17.x = 0;
  *&v17.z = 0;
  v15 = 0;
  *&p.x = 0;
  *&p.z = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPEyeThunder_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPEyeThunder_tag, v18);
      if ((v18[0] & 1) != 0)
        v6 = v18[2];
      else
        v6 = v18 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  *&v17.x = 0;
  *&v17.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  if (effBTLSkillCheckRun())
  {
    pFormation = effBTLSkillGetTargetFormation(0);
    effBTLModelGetSphereCenter(&pFormation);
    SDF_VU0__LOADVECTOR_B(v3[1]);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(&p);
    Param = effPCP_ThunderPolyGetParam(v3[3].klass);
    sub_854710(&v3[1], 0);
    sub_854710(&p, 0);
    sub_854930(&v17, 0);
    sub_854710(&v3[1], 1u);
    sub_854710(&p, 1u);
    sub_854930(&v17, 1u);
    sub_854710(&v3[1], 2u);
    sub_854710(&p, 2u);
    sub_854930(&v17, 2u);
    pos = Param->pos;
    SDF_VU0__COPYVECTOR(pos->m_Items, v17);
    sub_854710(&v17, 0);
    sub_854710(&p, 0);
    sub_854930(&v17, 0);
    sub_854710(&v17, 1u);
    sub_854710(&p, 1u);
    sub_854930(&v17, 1u);
    sub_854710(&v17, 2u);
    sub_854710(&p, 2u);
    sub_854930(&v17, 2u);
    v13 = Param->pos;
    SDF_VU0__COPYVECTOR(&v13->m_Items[1], v17);
    v15 = v3[3].klass;
    effPCP_ThunderPolySetColor(&v15, v3[2].klass);
    v15 = v3[3].klass;
    effPCP_ThunderPolyDraw(&v15);
  }
}

// 0x117ee00
void effPCPEyeThunderSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPEyeThunder_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPEyeThunder_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[2].klass) = abgr;
}

// 0x117ecd0
void effPCPEyeThunderSetPosition(void **hData, sdfVector4_t pPos) {
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
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != effPCPEyeThunder_tag)
    {
      sub_8FC2C0(*(v9 + 64), effPCPEyeThunder_tag, v13);
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

// 0x118dd20
effPCPFLEACHBlur_tag *effPCPFLEACHBlurCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v7;
  u64 *v8;
  dds3Effect_PartialMultiBlurParam_t_o *name;
  char *v12;
  s64 *v13;
  u64 v14[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFLEACHBlur_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFLEACHBlur_tag, v14);
    if ((v14[0] & 1) != 0)
      v12 = v14[2];
    else
      v12 = v14 + 1;
    v13 = sub_8C4940(v12);
  }
  v7 = (*hData)[1].klass;
LABEL_9:
  v8 = Allocate(effPCPFLEACHBlur_tag);
  _ctor(v8, 0);
  v8[4] = 0x8080808000000000LL;
  v8[2] = v7;
  v8[3] = 0;
  name = v7->_1.name;
  v8[3] = dds3EffectPartialMultiBlurCreate(name);
  return v8;
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
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 *v10;
  dds3Effect_PartialMultiBlurParam_t_o *v12;
  u64 v14[3];

  v5 = *pData;
  else if (!v5)
  {
    goto LABEL_12;
  }
  klass = v5->klass;
  if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFLEACHBlurParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFLEACHBlurParam_t, v14);
    if ((v14[0] & 1) != 0)
      v8 = v14[2];
    else
      v8 = v14 + 1;
    v9 = sub_8C4940(v8);
  }
LABEL_12:
  v10 = Allocate(effPCPFLEACHBlur_tag);
  _ctor(v10, 0);
  v10[4] = 0x8080808000000000LL;
  v10[2] = v5;
  v10[3] = 0;
  v12 = v5[1].klass;
  v10[3] = dds3EffectPartialMultiBlurCreate(v12);
  return v10;
}

// 0x118da60
effPCPFLEACHBlur_tag *effPCPFLEACHBlurCreatePCF(void **hData, s32 bPos, bool tbldata) {
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
  dds3Effect_PartialMultiBlurParam_t_o *v25;
  u64 v27[2];
  char *v28;
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
      sub_8FC2C0(v7->klass->_1.element_class, v8, v27);
      if ((v27[0] & 1) != 0)
        v10 = v28;
      else
        v10 = v27 + 1;
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
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 27);
  else if (!DataUnityOffSet)
  {
    goto LABEL_24;
  }
  klass = DataUnityOffSet->klass;
  if (DataUnityOffSet->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFLEACHBlurParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFLEACHBlurParam_t, v27);
    if ((v27[0] & 1) != 0)
      v21 = v28;
    else
      v21 = v27 + 1;
    v22 = sub_8C4940(v21);
  }
LABEL_24:
  v23 = Allocate(effPCPFLEACHBlur_tag);
  _ctor(v23, 0);
  v23[4] = 0x8080808000000000LL;
  v23[2] = DataUnityOffSet;
  v23[3] = 0;
  v25 = DataUnityOffSet[1].klass;
  v23[3] = dds3EffectPartialMultiBlurCreate(v25);
  return v23;
}

// 0x118dec0
void effPCPFLEACHBlurDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3Effect_PartialMultiBlur_t_o **p_monitor;
  u64 v9[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFLEACHBlur_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFLEACHBlur_tag, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  p_monitor = &v3[1].monitor;
  dds3EffectPartialMultiBlurDelete(p_monitor);
}

// 0x118dfe0
void effPCPFLEACHBlurDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3Effect_PartialMultiBlurParam_t_o *v8;
  Il2CppClass *v9;
  s32 data;
  s32 v11;
  s32 v12;
  s32 bits;
  s32 data_high;
  f32 v15;
  f32 v16;
  f32 v17;
  u32 v18;
  f32 v19;
  u32 v20;
  struct dds3Effect_Blur_t_o *Blur;
  Il2CppClass *v23;
  f32 v24;
  Il2CppClass *v25;
  f32 v26;
  Il2CppClass *v27;
  s64 v28;
  s64 v30;
  struct System_Int32_array *pm;
  Il2CppClass *v34;
  s64 v35;
  s64 v37;
  s32 v38;
  f32 v40;
  struct System_Int32_array *v41;
  u64 v43[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFLEACHBlur_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFLEACHBlur_tag, v43);
      if ((v43[0] & 1) != 0)
        v6 = v43[2];
      else
        v6 = v43 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = Allocate(dds3Effect_PartialMultiBlurParam_t);
  dds3Effect_PartialMultiBlurParam_t___ctor(v8);
  dds3Effect_PartialMultiBlurParam_t__Clear(v8);
  v9 = v3[1].klass;
  data = v9->_1.byval_arg.data;
  v11 = v3[2].klass;
  v12 = data - v11;
  if (data >= v11)
  {
    data_high = HIDWORD(v9->_1.byval_arg.data);
    bits = v9->_1.byval_arg.bits;
    if (v11 < data_high && data_high)
    {
      v15 = v11;
      v16 = data_high;
    }
    else
    {
      v17 = 1.0;
      if (v12 > bits || !bits)
      {
LABEL_18:
        v18 = effColorBlend(HIDWORD(v3[2].klass) & 0xFFFFFF, HIDWORD(v3[2].klass), v17, 0);
        if (v11)
          v19 = v11 / data;
        else
          v19 = 1.0;
        v8->area = *(v3[1].klass->_1.name + 4)
                        + (v19 * (*(v3[1].klass->_1.namespaze + 4) - *(v3[1].klass->_1.name + 4)));
        v20 = effColorBlend(
                *(*(v3[1].klass->_1.name + 3) + 16LL),
                *(*(v3[1].klass->_1.namespaze + 3) + 16LL),
                v19,
                0);
        Blur = v8->Blur;
        Blur->abgr = effColorMultiply(v20, v18);
        v8->Blur->blend = *(*(v3[1].klass->_1.namespaze + 3) + 20LL);
        v23 = v3[1].klass;
        v24 = *(*(v23->_1.name + 3) + 24LL);
        v8->Blur->rotate = v24 + (v19 * (*(*(v23->_1.namespaze + 3) + 24LL) - v24));
        v25 = v3[1].klass;
        v26 = *(*(v25->_1.name + 3) + 28LL);
        v8->Blur->scale = v26 + (v19 * (*(*(v25->_1.namespaze + 3) + 28LL) - v26));
        v27 = v3[1].klass;
        v28 = *(*(*(v27->_1.namespaze + 3) + 32LL) + 16LL);
        v30 = *(*(*(v27->_1.name + 3) + 32LL) + 16LL);
        pm = v8->Blur->center->pm;
        pm->m_Items[0] = *(v30 + 32) + (v19 * (*(v28 + 32) - *(v30 + 32)));
        v34 = v3[1].klass;
        v35 = *(*(*(v34->_1.namespaze + 3) + 32LL) + 16LL);
        v37 = *(*(*(v34->_1.name + 3) + 32LL) + 16LL);
        v38 = *(v35 + 36);
        v40 = v38;
        v41 = v8->Blur->center->pm;
        v41->m_Items[1] = *(v37 + 36) + (v19 * (v40 - *(v37 + 36)));
        dds3EffectPartialMultiBlurSetParam(&v3[1].monitor, v8);
        dds3EffectPartialMultiBlurDraw(&v3[1].monitor, 0, 0);
        ++LODWORD(v3[2].klass);
        return;
      }
      v15 = v12;
      v16 = bits;
    }
    v17 = v15 / v16;
    goto LABEL_18;
  }
}

// 0x118e460
void effPCPFLEACHBlurSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFLEACHBlur_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFLEACHBlur_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[2].klass) = abgr;
}

// 0x116d280
effPCPFilterExp_tag *effPCPFilterExpCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v7;
  effPCPFilterExp_tag_o *v8;
  char *v10;
  s64 *v11;
  u64 v12[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFilterExp_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFilterExp_tag, v12);
    if ((v12[0] & 1) != 0)
      v10 = v12[2];
    else
      v10 = v12 + 1;
    v11 = sub_8C4940(v10);
  }
  v7 = (*hData)[1].klass;
LABEL_9:
  v8 = Allocate(effPCPFilterExp_tag);
  _ctor(v8, 0);
  v8->param = v7;
  v8->frame = 0;
  v8->abgr = -2139062144;
  v8->abgr_base = *(v7->_1.byval_arg.data + 4);
  return v8;
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
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  effPCPFilterExp_tag_o *v10;
  u64 v12[3];

  v5 = *pData;
  else if (!v5)
  {
    goto LABEL_12;
  }
  klass = v5->klass;
  if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFilterExpParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFilterExpParam_t, v12);
    if ((v12[0] & 1) != 0)
      v8 = v12[2];
    else
      v8 = v12 + 1;
    v9 = sub_8C4940(v8);
  }
LABEL_12:
  v10 = Allocate(effPCPFilterExp_tag);
  _ctor(v10, 0);
  v10->param = v5;
  v10->frame = 0;
  v10->abgr = -2139062144;
  v10->abgr_base = v5[2].klass->_1.name;
  return v10;
}

// 0x116cfe0
effPCPFilterExp_tag *effPCPFilterExpCreatePCF(void **hData, s32 bPos, bool tbldata) {
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
  effPCPFilterExp_tag_o *v23;
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
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 12);
  else if (!DataUnityOffSet)
  {
    goto LABEL_24;
  }
  klass = DataUnityOffSet->klass;
  if (DataUnityOffSet->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFilterExpParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFilterExpParam_t, v25);
    if ((v25[0] & 1) != 0)
      v21 = v26;
    else
      v21 = v25 + 1;
    v22 = sub_8C4940(v21);
  }
LABEL_24:
  v23 = Allocate(effPCPFilterExp_tag);
  _ctor(v23, 0);
  v23->param = DataUnityOffSet;
  v23->frame = 0;
  v23->abgr = -2139062144;
  v23->abgr_base = DataUnityOffSet[2].klass->_1.name;
  return v23;
}

// 0x116d400
void effPCPFilterExpDelete(void **hData) {

}

// 0x116d440
void effPCPFilterExpDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppClass *v8;
  s32 v9;
  s32 name;
  s32 v11;
  s32 namespaze;
  s32 name_high;
  s64 v14;
  s64 v15;
  s64 v16;
  s64 v18;
  s64 v20;
  s64 v22;
  s64 v24;
  s64 v26;
  f32 v28;
  f32 v29;
  f32 v30;
  u32 v31;
  u32 *data;
  s32 ID;
  dds3Effect_Filter_t_o **p_byval_arg;
  u64 v39[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFilterExp_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPFilterExp_tag, v39);
      if ((v39[0] & 1) != 0)
        v6 = v39[2];
      else
        v6 = v39 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = v3[1].klass;
  v9 = v3[2].klass;
  name = v8->_1.name;
  v11 = name - v9;
  if (name >= v9)
  {
    name_high = HIDWORD(v8->_1.name);
    namespaze = v8->_1.namespaze;
    v14 = *(v8->_1.byval_arg.data + 3);
    v15 = *(*(v14 + 32) + 16LL);
    *(v15 + 32) = 0;
    v16 = *(v3[1].klass->_1.byval_arg.data + 3);
    v18 = *(*(v16 + 32) + 16LL);
    *(v18 + 36) = 0;
    v20 = *(v3[1].klass->_1.byval_arg.data + 3);
    v22 = *(*(v20 + 40) + 16LL);
    *(v22 + 32) = 512;
    v24 = *(v3[1].klass->_1.byval_arg.data + 3);
    v26 = *(*(v24 + 40) + 16LL);
    *(v26 + 36) = 448;
    if (v9 < name_high && name_high)
    {
      v28 = v9;
      v29 = name_high;
    }
    else
    {
      v30 = 1.0;
      if (v11 > namespaze || !namespaze)
      {
LABEL_32:
        v31 = effColorBlend(v3[1].monitor & 0xFFFFFF, v3[1].monitor, v30);
        data = v3[1].klass->_1.byval_arg.data;
        data[4] = effColorMultiply(v31, HIDWORD(v3[1].monitor), 0);
        else if (effBTLSkillCheckRun())
        {
          goto LABEL_35;
        }
        ID = 0;
LABEL_43:
        p_byval_arg = &v3[1].klass->_1.byval_arg;
        dds3EffectFilter(p_byval_arg, ID, 0);
        ++LODWORD(v3[2].klass);
        return;
      }
      v28 = v11;
      v29 = namespaze;
    }
    v30 = v28 / v29;
    goto LABEL_32;
  }
}

// 0x116d7a0
void effPCPFilterExpSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPFilterExp_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPFilterExp_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[1].monitor) = abgr;
}

// 0x1159a10
effPCPHama01_tag *effPCPHama01Copy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v6;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  u64 *v11;
  u64 i;
  u64 v17;
  u64 v19;
  Il2CppClass *v20;
  s64 v21;
  u64 v22;
  s64 v24;
  s64 *v26;
  s64 *v27;
  u64 v29;
  u64 v31;
  Il2CppClass *v32;
  s64 v33;
  s64 v35;
  s64 *v37;
  s64 *v38;
  void *monitor;
  u32 *v41;
  s64 *v43;
  s64 *v46;
  u64 v48;
  effPCPHama01_tag_o *v51;
  u64 v52[3];

  v51 = 0;
  v6 = *hData;
  if (*hData)
  {
    klass = v6->klass;
    if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHama01_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPHama01_tag, v52);
      if ((v52[0] & 1) != 0)
        v9 = v52[2];
      else
        v9 = v52 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  v11 = Allocate(effPCPHama01_tag);
  _ctor(v11, 0);
  v51 = v11;
  v11[6] = NewSpecific(effPartHandle_t__, 8u);
  v11[7] = NewSpecific(effPartHandle_t, 8u);
  v11[8] = NewSpecific(uint, 8u);
  v11[9] = NewSpecific(uint, 8u);
  for (i = 0; i != 8; ++i)
  {
    v17 = v11[6];
    v19 = v17 + 8 * i;
    v20 = v6[3].klass;
    v21 = *(v19 + 32);
    v22 = i & 1;
    v24 = *(&v20->_1.byval_arg.data + v22);
    else if (!*(v24 + 24))
    {
LABEL_25:
    }
    v26 = dds3EffectPartCopy((v24 + 32), bPos, 0);
    v27 = v26;
    *(v21 + 32) = v27;
    v29 = v11[6];
    v31 = v29 + 8 * i;
    v32 = v6[3].klass;
    v33 = *(v31 + 32);
    v35 = *(&v32->_1.byval_arg.data + v22);
    v37 = dds3EffectPartCopy((v35 + 40), bPos, 0);
    v38 = v37;
    *(v33 + 40) = v38;
    monitor = v6[3].monitor;
    v41 = v11[7];
    v43 = dds3EffectPartCopy(monitor + 4, bPos, 0);
    v46 = v43;
    *&v41[2 * i + 8] = v46;
    v48 = v11[8];
    *(v48 + 4 * i + 32) = 0;
    effPCPHama01PartInit(&v51, i);
  }
  sub_854930((v11 + 2), 0);
  sub_854930((v11 + 2), 1u);
  sub_854930((v11 + 2), 2u);
  v11[4] = 2155905152LL;
  *(v11 + 10) = 1065353216;
  return v11;
}

// 0x1158f30
effPCPHama01_tag *effPCPHama01Create(void **hData, s32 bPos, bool tbldata) {
  s32 v4;
  u64 *v6;
  s64 *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  u64 *v12;
  effPCPMisc_c **v14;
  u64 v15;
  u64 v23;
  s64 v24;
  u64 v25;
  s64 v27;
  s64 *v28;
  s64 *v29;
  u64 v31;
  s64 v33;
  u64 v34;
  s64 v36;
  s64 *v40;
  u64 v41;
  u64 *v42;
  s32 v43;
  effPCPMisc_c **v44;
  u64 v46;
  u64 v47;
  s64 v48;
  u64 v49;
  u64 v51;
  s32 v52;
  s64 v53;
  s64 *v55;
  s64 *v56;
  u64 v58;
  u64 v59;
  s64 v61;
  s64 v63;
  s64 *v65;
  s64 *v66;
  u64 v68;
  s64 *v70;
  s64 *v71;
  u64 v72;
  u64 v74;
  s64 *v75;
  s64 *v77;
  u64 v78;
  s64 v79;
  u64 v81;
  s32 v82;
  u64 v84;
  s64 *v85;
  s64 *v86;
  u64 v88;
  u64 v90;
  s64 *v95;
  effPCPHama01_tag_o *pPCPHama01;
  u64 v97[3];
  s32 pos;

  v4 = bPos;
  pos = bPos;
  pPCPHama01 = 0;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(v7, byte);
    if (!Interface)
    {
      sub_8FC2C0(*(*v7 + 64), v8, v97);
      if ((v97[0] & 1) != 0)
        v10 = v97[2];
      else
        v10 = v97 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v6, Interface, &pos);
  v12 = Allocate(effPCPHama01_tag);
  _ctor(v12, 0);
  pPCPHama01 = v12;
  v12[6] = NewSpecific(effPartHandle_t__, 8u);
  v12[7] = NewSpecific(effPartHandle_t, 8u);
  v12[8] = NewSpecific(uint, 8u);
  v12[9] = NewSpecific(uint, 8u);
  v14 = &effPCPMisc;
  v15 = 0;
  v95 = Interface;
  do
  {
    if (v15 == 1)
    {
      v25 = v12[6];
      v27 = *(v25 + 40);
      v28 = dds3EffectPCPDataPartCreate(v6, Interface, v4, 1u);
      v29 = v28;
      *(v27 + 32) = v29;
      v31 = v12[6];
      v33 = *(v31 + 40);
      v34 = v12[6];
      v36 = *(v34 + 32);
      v40 = dds3EffectPartCopy((v36 + 40), pos, 0);
      if (v40)
        goto LABEL_75;
      goto LABEL_76;
    }
    if (!v15)
    {
      v23 = v12[6];
      v24 = *(v23 + 32);
      v70 = dds3EffectPCPDataPartCreate(v6, Interface, v4, 0);
      v71 = v70;
      *(v24 + 32) = v71;
      v72 = v12[6];
      v33 = *(v72 + 32);
      v40 = dds3EffectPCPDataPartCreate(v6, Interface, v4, 2u);
      if (v40)
      {
LABEL_75:
      }
LABEL_76:
      *(v33 + 40) = v40;
      v68 = *v14;
      if (((*v14)->_2.bitflags2 & 2) != 0)
        goto LABEL_79;
      goto LABEL_81;
    }
    v41 = v12[6];
    v42 = v6;
    v43 = v4;
    v44 = v14;
    v46 = v41 + 8 * v15;
    v47 = v12[6];
    v48 = *(v46 + 32);
    v49 = v15 & 1;
    v51 = v47 + 8 * v49;
    v52 = pos;
    v53 = *(v51 + 32);
    else if (!*(v53 + 24))
    {
LABEL_52:
    }
    v55 = dds3EffectPartCopy((v53 + 32), v52, 0);
    v56 = v55;
    *(v48 + 32) = v56;
    v58 = v12[6];
    v59 = *(v58 + 24);
    v61 = *(v58 + 8 * v15 + 32);
    v63 = *(v12[6] + 8 * v49 + 32);
    v65 = dds3EffectPartCopy((v63 + 40), pos, 0);
    v66 = v65;
    v14 = v44;
    v4 = v43;
    v6 = v42;
    Interface = v95;
    *(v61 + 40) = v66;
    v68 = *v14;
    if (((*v14)->_2.bitflags2 & 2) != 0)
    {
LABEL_79:
      if (!*(v68 + 216))
    }
LABEL_81:
    effPCPHama01PartInit(&pPCPHama01, v15++);
  }
  while (v15 != 8);
  v74 = v12[7];
  v75 = dds3EffectPCPDataPartCreate(v6, Interface, v4, 3u);
  v77 = v75;
  *(v74 + 32) = v77;
  v78 = v12[8];
  v79 = 0;
  *(v78 + 32) = 0;
  do
  {
    v81 = v12[7];
    v82 = pos;
    else if (!*(v81 + 24))
    {
LABEL_96:
    }
    v84 = v79 + 1;
    v85 = dds3EffectPartCopy((v81 + 32), v82, 0);
    v86 = v85;
    *(v81 + 8 * v79 + 40) = v86;
    v88 = v12[8];
    v90 = v88 + 4 * v79++;
    *(v90 + 36) = 0;
  }
  while (v79 != 7);
  sub_854930((v12 + 2), 0);
  sub_854930((v12 + 2), 1u);
  sub_854930((v12 + 2), 2u);
  v12[4] = 2155905152LL;
  *(v12 + 10) = 1065353216;
  return v12;
}

// 0x1159800
void effPCPHama01Delete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s64 v8;
  s64 v9;
  u32 *monitor;
  u64 v11;
  Il2CppClass *v13;
  s64 v15;
  Il2CppClass *v17;
  s64 v19;
  u64 v21[3];

  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHama01_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPHama01_tag, v21);
      if ((v21[0] & 1) != 0)
        v6 = v21[2];
      else
        v6 = v21 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = -8;
  v9 = 8;
  do
  {
    monitor = v3[3].monitor;
    v11 = v8 + 8;
    else if (v11 >= monitor[6])
    {
LABEL_16:
    }
    dds3EffectPartDelete(&monitor[v9]);
    v13 = v3[3].klass;
    v15 = *(&v13->_1.image + v9 * 4);
    dds3EffectPartDelete((v15 + 40), 0);
    v17 = v3[3].klass;
    v19 = *(&v17->_1.image + v9 * 4);
    dds3EffectPartDelete((v19 + 32), 0);
    ++v8;
    v9 += 2;
  }
  while (v8);
}

// 0x1159ef0
void effPCPHama01Draw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3ModelHandle_t_o **v9;
  u64 v10;
  dds3ModelHandle_t_o **v11;
  dds3ModelHandle_t_o **v12;
  s64 v13;
  u32 *monitor;
  u32 *v17;
  bool v19;
  Il2CppClass *v20;
  s64 v22;
  s64 *Handle;
  s64 *v25;
  s64 v26;
  s64 v27;
  char *v28;
  s64 *v29;
  s64 v31;
  s64 v32;
  char *v33;
  s64 *v34;
  Il2CppClass *v36;
  s64 v38;
  s64 *v40;
  s64 *v41;
  s64 v42;
  s64 v43;
  char *v44;
  s64 *v45;
  s64 v47;
  s64 v48;
  char *v49;
  s64 *v50;
  Il2CppClass *v54;
  s64 v56;
  Il2CppClass *v58;
  s64 v60;
  sdfModelRootNode_t_o *modelRoot;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  u32 *v74;
  u32 *v76;
  dds3ModelHandle_t_o *v78;
  UnityEngine_Vector4_o p;
  u64 v80[2];
  char *v81;
  UnityEngine_Vector4_o v82;

  *&p.x = 0;
  *&p.z = 0;
  v78 = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHama01_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPHama01_tag, v80);
      if ((v80[0] & 1) != 0)
        v6 = v81;
      else
        v6 = v80 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  *&p.x = 0;
  *&p.z = 0;
  v9 = NewSpecific(dds3ModelHandle_t, 2u);
  v10 = 0;
  v11 = v9 + 4;
  v12 = v9 + 5;
  v13 = 8;
  do
  {
    while (1)
    {
      monitor = v3[4].monitor;
      if (!monitor[v10 + 8])
        break;
      v17 = v3[4].monitor;
      --v17[v10 + 8];
      v19 = v10++ >= 7;
      v13 += 2;
      if (v19)
        goto LABEL_115;
    }
    v20 = v3[3].klass;
    v22 = *(&v20->_1.byval_arg.data + v10);
    else if (!*(v22 + 24))
    {
      goto LABEL_31;
    }
    Handle = dds3EffectPartGetHandle((v22 + 32), 0);
    v25 = Handle;
    if (Handle)
    {
      v26 = *Handle;
      if (*(*Handle + 288) < v27 || *(*(v26 + 200) + 8 * v27 - 8) != dds3ModelHandle_t)
      {
        sub_8FC2C0(*(v26 + 64), dds3ModelHandle_t, v80);
        if ((v80[0] & 1) != 0)
          v28 = v81;
        else
          v28 = v80 + 1;
        v29 = sub_8C4940(v28);
      }
      v31 = *v25;
      if (*(*v25 + 288) < v32 || *(*(v31 + 200) + 8 * v32 - 8) != dds3ModelHandle_t)
      {
        sub_8FC2C0(*(v31 + 64), dds3ModelHandle_t, v80);
        if ((v80[0] & 1) != 0)
          v33 = v81;
        else
          v33 = v80 + 1;
        v34 = sub_8C4940(v33);
      }
    }
    *v11 = v25;
    v36 = v3[3].klass;
    v38 = *(&v36->_1.byval_arg.data + v10);
    v40 = dds3EffectPartGetHandle((v38 + 40), 0);
    v41 = v40;
    if (v40)
    {
      v42 = *v40;
      if (*(*v40 + 288) < v43 || *(*(v42 + 200) + 8 * v43 - 8) != dds3ModelHandle_t)
      {
        sub_8FC2C0(*(v42 + 64), dds3ModelHandle_t, v80);
        if ((v80[0] & 1) != 0)
          v44 = v81;
        else
          v44 = v80 + 1;
        v45 = sub_8C4940(v44);
      }
      v47 = *v41;
      if (*(*v41 + 288) < v48 || *(*(v47 + 200) + 8 * v48 - 8) != dds3ModelHandle_t)
      {
        sub_8FC2C0(*(v47 + 64), dds3ModelHandle_t, v80);
        if ((v80[0] & 1) != 0)
          v49 = v81;
        else
          v49 = v80 + 1;
        v50 = sub_8C4940(v49);
      }
    }
    *v12 = v41;
    SDF_VU0__LOADVECTOR(v3[1]);
    else if (!*(v9 + 6))
    {
LABEL_75:
    }
    mdlSetPosition(v11);
    v54 = v3[3].klass;
    v56 = *(&v54->_1.byval_arg.data + v10);
    dds3EffectPartSetScale((v56 + 32), *&v3[2].monitor * 1.5, 0);
    v58 = v3[3].klass;
    v60 = *(&v58->_1.byval_arg.data + v10);
    dds3EffectPartSetScale((v60 + 40), 1.75, 0);
    mdlSetColor(v12, v3[2].klass);
    v78 = v9[4];
    dds3EffectPartModelDraw(&v78);
    if (*v11)
    {
      modelRoot = (*v11)->modelRoot;
      sdfModelGetMarkPosUnity(modelRoot, 1);
      SDF_VU0__STOREVECTOR(&p);
      else if (*(v9 + 6) <= 1u)
      {
LABEL_98:
      }
      mdlSetPosition(v12);
      v78 = *v12;
      dds3EffectPartModelDraw(&v78);
    }
    if (HIDWORD(v3[2].klass) >= 0x19)
    {
      x = p.x;
      y = p.y;
      z = p.z;
      w = p.w;
      v74 = v3[3].monitor;
      else if (v10 >= v74[6])
      {
LABEL_109:
      }
      v82.x = x;
      v82.y = y;
      v82.z = z;
      v82.w = w;
      dds3EffectPartSetPosition(&v74[v13], v82);
      v76 = v3[3].monitor;
      dds3EffectPartDraw(&v76[v13]);
    }
    v19 = v10++ >= 7;
    v13 += 2;
  }
  while (!v19);
LABEL_115:
  ++HIDWORD(v3[2].klass);
}

// 0x1158a90
void effPCPHama01PartInit(effPCPHama01_tag **pPCPHama01, u32 number) {
  u64 *v5;
  f32 v8;
  struct effPartHandle_t_array_array *hPart;
  effPartHandle_t_array *v12;
  struct effPartHandle_t_array_array *v14;
  effPartHandle_t_array *v16;
  struct effPartHandle_t_array_array *v18;
  effPartHandle_t_array *v19;
  Il2CppObject *Handle;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v26;
  s64 *v27;
  struct effPartHandle_t_array_array *v28;
  effPartHandle_t_array *v30;
  Il2CppObject *v32;
  Il2CppClass *v33;
  s64 v34;
  char *v35;
  s64 *v36;
  struct System_UInt32_array *interval;
  u32 v38;
  UnityEngine_Matrix4x4_o v40;
  UnityEngine_Matrix4x4_o v41;
  UnityEngine_Matrix4x4_o v42;
  UnityEngine_Matrix4x4_o v43;
  UnityEngine_Matrix4x4_o aMatrix;
  u64 v45[2];
  char *v46;

  memset(&aMatrix, 0, sizeof(aMatrix));
  v5 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v5);
  v8 = DDS3EFFECT_RAND_PM();
  SetRotateMatrixY(v8 * 6.2832);
  SDF_VU0__STOREMATRIX(&aMatrix);
  hPart = (*pPCPHama01)->hPart;
  v12 = hPart->m_Items[number];
  v43 = aMatrix;
  else if (!LODWORD(v12->max_length))
  {
    goto LABEL_14;
  }
  v42 = v43;
  dds3EffectPartSetRotateMatrix(v12->m_Items, &v42);
  v14 = (*pPCPHama01)->hPart;
  v16 = v14->m_Items[number];
  v41 = aMatrix;
  v40 = v41;
  dds3EffectPartSetRotateMatrix(&v16->m_Items[1], &v40);
  v18 = (*pPCPHama01)->hPart;
  v19 = v18->m_Items[number];
  Handle = dds3EffectPartGetHandle(v19->m_Items);
  if (Handle)
  {
    klass = Handle->klass;
    if (Handle->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, v45);
      if ((v45[0] & 1) != 0)
        v26 = v46;
      else
        v26 = v45 + 1;
      v27 = sub_8C4940(v26);
    }
  }
  v28 = (*pPCPHama01)->hPart;
  v30 = v28->m_Items[number];
  v32 = dds3EffectPartGetHandle(&v30->m_Items[1]);
  if (v32)
  {
    v33 = v32->klass;
    if (v32->klass->_2.typeHierarchyDepth < v34 || v33->_2.typeHierarchy[v34 - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(v33->_1.element_class, dds3ModelHandle_t, v45);
      if ((v45[0] & 1) != 0)
        v35 = v46;
      else
        v35 = v45 + 1;
      v36 = sub_8C4940(v35);
    }
  }
  interval = (*pPCPHama01)->interval;
  v38 = DDS3EFFECT_RAND_I() % 0xA;
  interval->m_Items[number] = v38;
}

// 0x115a990
void effPCPHama01SetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHama01_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPHama01_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[2].klass) = abgr;
}

// 0x115a770
void effPCPHama01SetPosition(void **hData, sdfVector4_t pPos) {
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
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != effPCPHama01_tag)
    {
      sub_8FC2C0(*(v9 + 64), effPCPHama01_tag, v13);
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

// 0x115a8a0
void effPCPHama01SetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHama01_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPHama01_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *&(*hData)[2].monitor = scale;
}

// 0x115b610
effPCPHama02_tag *effPCPHama02Copy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v6;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  Il2CppObject *v11;
  u64 i;
  Il2CppClass *v18;
  void **v20;
  Il2CppClass *v21;
  u32 *v22;
  void *data;
  s64 *v26;
  s64 *v27;
  Il2CppClass *v29;
  void **v31;
  Il2CppClass *v32;
  u32 *v33;
  void *v34;
  s64 *v36;
  s64 *v39;
  effPCPHama02_tag_o *v42[3];
  effPCPHama02_tag_o *pPCPHama02;

  pPCPHama02 = 0;
  v6 = *hData;
  if (*hData)
  {
    klass = v6->klass;
    if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHama02_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPHama02_tag, v42);
      if ((v42[0] & 1) != 0)
        v9 = v42[2];
      else
        v9 = v42 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  v11 = Allocate(effPCPHama02_tag);
  _ctor(v11, 0);
  pPCPHama02 = v11;
  Clear(v11);
  for (i = 0; i != 8; ++i)
  {
    v18 = v11[3].klass;
    v20 = &v18->_1.image + i;
    v21 = v6[3].klass;
    v22 = v20[4];
    data = v21->_1.byval_arg.data;
    else
    {
      if (!*(data + 6))
        goto LABEL_23;
    }
    v26 = dds3EffectPartCopy(data + 4, bPos, 0);
    v27 = v26;
    *(v22 + 4) = v27;
    v29 = v11[3].klass;
    v31 = &v29->_1.image + i;
    v32 = v6[3].klass;
    v33 = v31[4];
    v34 = v32->_1.byval_arg.data;
    v36 = dds3EffectPartCopy(v34 + 5, bPos, 0);
    v39 = v36;
    *(v33 + 5) = v39;
    effPCPHama02PartInit(&pPCPHama02, i);
  }
  sub_854930(&v11[1], 0);
  sub_854930(&v11[1], 1u);
  sub_854930(&v11[1], 2u);
  v11[2].klass = 0x3F80000080808080LL;
  return v11;
}

// 0x115af60
effPCPHama02_tag *effPCPHama02Create(void **hData, s32 bPos, bool tbldata) {
  u64 *v6;
  s64 *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  Il2CppObject *v12;
  u64 i;
  Il2CppClass *klass;
  u64 namespaze_low;
  s64 v23;
  void *data;
  s32 v26;
  s64 *v28;
  s64 *v29;
  Il2CppClass *v31;
  u64 v32;
  u32 *v34;
  void *v36;
  s64 *v40;
  u32 *v41;
  s64 *v44;
  s64 *v45;
  Il2CppClass *v46;
  Il2CppObject *v49;
  u64 v50[3];
  s32 pos;

  pos = bPos;
  v49 = 0;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(v7, byte);
    if (!Interface)
    {
      sub_8FC2C0(*(*v7 + 64), v8, v50);
      if ((v50[0] & 1) != 0)
        v10 = v50[2];
      else
        v10 = v50 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v6, Interface, &pos);
  v12 = Allocate(effPCPHama02_tag);
  _ctor(v12, 0);
  v49 = v12;
  Clear(v12);
  for (i = 0; i != 8; ++i)
  {
    klass = v12[3].klass;
    namespaze_low = LODWORD(klass->_1.namespaze);
    if (i)
    {
      v23 = *(&klass->_1.byval_arg.data + i);
      data = klass->_1.byval_arg.data;
      v26 = pos;
      else if (!*(data + 6))
      {
LABEL_25:
      }
      v28 = dds3EffectPartCopy(data + 4, v26, 0);
      v29 = v28;
      *(v23 + 32) = v29;
      v31 = v12[3].klass;
      v32 = LODWORD(v31->_1.namespaze);
      v34 = *(&v31->_1.byval_arg.data + i);
      v36 = v12[3].klass->_1.byval_arg.data;
      v40 = dds3EffectPartCopy(v36 + 5, pos, 0);
      if (v40)
      {
LABEL_49:
      }
    }
    else
    {
      v41 = klass->_1.byval_arg.data;
      v44 = dds3EffectPCPDataPartCreate(v6, Interface, bPos, 0);
      v45 = v44;
      *(v41 + 4) = v45;
      v46 = v12[3].klass;
      v34 = v46->_1.byval_arg.data;
      v40 = dds3EffectPCPDataPartCreate(v6, Interface, bPos, 1u);
      if (v40)
        goto LABEL_49;
    }
    *(v34 + 5) = v40;
    effPCPHama02PartInit(&v49, i);
  }
  sub_854930(&v12[1], 0);
  sub_854930(&v12[1], 1u);
  sub_854930(&v12[1], 2u);
  v12[2].klass = 0x3F80000080808080LL;
  return v12;
}

// 0x115b440
void effPCPHama02Delete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s64 i;
  Il2CppClass *v9;
  s64 v11;
  Il2CppClass *v13;
  s64 v15;
  u64 v17[3];

  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHama02_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPHama02_tag, v17);
      if ((v17[0] & 1) != 0)
        v6 = v17[2];
      else
        v6 = v17 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  for (i = 4; i != 12; ++i)
  {
    v9 = v3[3].klass;
    v11 = *(&v9->_1.image + i);
    else if (!*(v11 + 24))
    {
LABEL_18:
    }
    dds3EffectPartDelete((v11 + 32), 0);
    v13 = v3[3].klass;
    v15 = *(&v13->_1.image + i);
    dds3EffectPartDelete((v15 + 40), 0);
  }
}

// 0x115b9c0
void effPCPHama02Draw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3ModelHandle_t_o **v9;
  u64 v10;
  dds3ModelHandle_t_o **v11;
  dds3ModelHandle_t_o **v12;
  u32 *monitor;
  u32 *v16;
  bool v18;
  Il2CppClass *v19;
  s64 v21;
  s64 *Handle;
  s64 *v24;
  s64 v25;
  s64 v26;
  char *v27;
  s64 *v28;
  s64 v30;
  s64 v31;
  char *v32;
  s64 *v33;
  Il2CppClass *v35;
  s64 v37;
  s64 *v39;
  s64 *v40;
  s64 v41;
  s64 v42;
  char *v43;
  s64 *v44;
  s64 v46;
  s64 v47;
  char *v48;
  s64 *v49;
  Il2CppClass *v54;
  s64 v56;
  Il2CppClass *v58;
  s64 v60;
  sdfModelRootNode_t_o *modelRoot;
  UnityEngine_Vector4_o v70;
  u64 v71[2];
  char *v72;
  Il2CppObject *hDataa;

  *&v70.x = 0;
  *&v70.z = 0;
  hDataa = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHama02_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPHama02_tag, v71);
      if ((v71[0] & 1) != 0)
        v6 = v72;
      else
        v6 = v71 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  *&v70.x = 0;
  *&v70.z = 0;
  v9 = NewSpecific(dds3ModelHandle_t, 2u);
  v10 = 0;
  v11 = v9 + 4;
  v12 = v9 + 5;
  do
  {
    while (1)
    {
      monitor = v3[3].monitor;
      if (!monitor[v10 + 8])
        break;
      v16 = v3[3].monitor;
      --v16[v10 + 8];
      v18 = v10++ >= 7;
      if (v18)
        return;
    }
    v19 = v3[3].klass;
    v21 = *(&v19->_1.byval_arg.data + v10);
    else if (!*(v21 + 24))
    {
      goto LABEL_29;
    }
    Handle = dds3EffectPartGetHandle((v21 + 32), 0);
    v24 = Handle;
    if (Handle)
    {
      v25 = *Handle;
      if (*(*Handle + 288) < v26 || *(*(v25 + 200) + 8 * v26 - 8) != dds3ModelHandle_t)
      {
        sub_8FC2C0(*(v25 + 64), dds3ModelHandle_t, v71);
        if ((v71[0] & 1) != 0)
          v27 = v72;
        else
          v27 = v71 + 1;
        v28 = sub_8C4940(v27);
      }
      v30 = *v24;
      if (*(*v24 + 288) < v31 || *(*(v30 + 200) + 8 * v31 - 8) != dds3ModelHandle_t)
      {
        sub_8FC2C0(*(v30 + 64), dds3ModelHandle_t, v71);
        if ((v71[0] & 1) != 0)
          v32 = v72;
        else
          v32 = v71 + 1;
        v33 = sub_8C4940(v32);
      }
    }
    *v11 = v24;
    v35 = v3[3].klass;
    v37 = *(&v35->_1.byval_arg.data + v10);
    v39 = dds3EffectPartGetHandle((v37 + 40), 0);
    v40 = v39;
    if (v39)
    {
      v41 = *v39;
      if (*(*v39 + 288) < v42 || *(*(v41 + 200) + 8 * v42 - 8) != dds3ModelHandle_t)
      {
        sub_8FC2C0(*(v41 + 64), dds3ModelHandle_t, v71);
        if ((v71[0] & 1) != 0)
          v43 = v72;
        else
          v43 = v71 + 1;
        v44 = sub_8C4940(v43);
      }
      v46 = *v40;
      if (*(*v40 + 288) < v47 || *(*(v46 + 200) + 8 * v47 - 8) != dds3ModelHandle_t)
      {
        sub_8FC2C0(*(v46 + 64), dds3ModelHandle_t, v71);
        if ((v71[0] & 1) != 0)
          v48 = v72;
        else
          v48 = v71 + 1;
        v49 = sub_8C4940(v48);
      }
    }
    *v12 = v40;
    sub_854710(&v3[1], 0);
    sub_854930(&v70, 0);
    sub_854710(&v3[1], 1u);
    sub_854930(&v70, 1u);
    sub_854710(&v3[1], 2u);
    sub_854930(&v70, 2u);
    SDF_VU0__LOADVECTOR(v70);
    else if (!*(v9 + 6))
    {
LABEL_75:
    }
    mdlSetPosition(v11);
    v54 = v3[3].klass;
    v56 = *(&v54->_1.byval_arg.data + v10);
    dds3EffectPartSetScale((v56 + 32), *(&v3[2].klass + 1) * 1.5, 0);
    v58 = v3[3].klass;
    v60 = *(&v58->_1.byval_arg.data + v10);
    dds3EffectPartSetScale((v60 + 40), 1.5, 0);
    mdlSetColor(v12, v3[2].klass);
    hDataa = v9[4];
    dds3EffectPartModelDraw(&hDataa);
    if (*v11)
    {
      modelRoot = (*v11)->modelRoot;
      sdfModelGetMarkPosUnity(modelRoot, 1);
      else if (*(v9 + 6) <= 1u)
      {
LABEL_98:
      }
      mdlSetPosition(v12);
      hDataa = *v12;
      dds3EffectPartModelDraw(&hDataa);
    }
    v18 = v10++ >= 7;
  }
  while (!v18);
}

// 0x115aa80
void effPCPHama02PartInit(effPCPHama02_tag **pPCPHama02, u32 number) {
  u64 *v5;
  f32 v8;
  struct effPartHandle_t_array_array *hPart;
  effPartHandle_t_array *v12;
  struct effPartHandle_t_array_array *v14;
  effPartHandle_t_array *v16;
  struct effPartHandle_t_array_array *v18;
  effPartHandle_t_array *v19;
  Il2CppObject *Handle;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v26;
  s64 *v27;
  struct effPartHandle_t_array_array *v28;
  effPartHandle_t_array *v30;
  Il2CppObject *v32;
  Il2CppClass *v33;
  s64 v34;
  char *v35;
  s64 *v36;
  struct System_Single_array *h_add;
  f32 v38;
  struct System_UInt32_array *interval;
  u32 v41;
  UnityEngine_Matrix4x4_o v43;
  UnityEngine_Matrix4x4_o v44;
  UnityEngine_Matrix4x4_o v45;
  UnityEngine_Matrix4x4_o v46;
  UnityEngine_Matrix4x4_o aMatrix;
  u64 v48[2];
  char *v49;

  memset(&aMatrix, 0, sizeof(aMatrix));
  v5 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v5);
  v8 = DDS3EFFECT_RAND_PM();
  SetRotateMatrixY(v8 * 6.2832);
  SDF_VU0__STOREMATRIX(&aMatrix);
  hPart = (*pPCPHama02)->hPart;
  v12 = hPart->m_Items[number];
  v46 = aMatrix;
  else if (!LODWORD(v12->max_length))
  {
    goto LABEL_14;
  }
  v45 = v46;
  dds3EffectPartSetRotateMatrix(v12->m_Items, &v45);
  v14 = (*pPCPHama02)->hPart;
  v16 = v14->m_Items[number];
  v44 = aMatrix;
  v43 = v44;
  dds3EffectPartSetRotateMatrix(&v16->m_Items[1], &v43);
  v18 = (*pPCPHama02)->hPart;
  v19 = v18->m_Items[number];
  Handle = dds3EffectPartGetHandle(v19->m_Items);
  if (Handle)
  {
    klass = Handle->klass;
    if (Handle->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, v48);
      if ((v48[0] & 1) != 0)
        v26 = v49;
      else
        v26 = v48 + 1;
      v27 = sub_8C4940(v26);
    }
  }
  v28 = (*pPCPHama02)->hPart;
  v30 = v28->m_Items[number];
  v32 = dds3EffectPartGetHandle(&v30->m_Items[1]);
  if (v32)
  {
    v33 = v32->klass;
    if (v32->klass->_2.typeHierarchyDepth < v34 || v33->_2.typeHierarchy[v34 - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(v33->_1.element_class, dds3ModelHandle_t, v48);
      if ((v48[0] & 1) != 0)
        v35 = v49;
      else
        v35 = v48 + 1;
      v36 = sub_8C4940(v35);
    }
  }
  h_add = (*pPCPHama02)->h_add;
  v38 = DDS3EFFECT_RAND_F();
  h_add->m_Items[number] = v38 * 150.0;
  interval = (*pPCPHama02)->interval;
  v41 = DDS3EFFECT_RAND_I() % 0xA;
  interval->m_Items[number] = v41;
}

// 0x115c430
void effPCPHama02SetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHama02_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPHama02_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[2].klass) = abgr;
}

// 0x115c210
void effPCPHama02SetPosition(void **hData, sdfVector4_t pPos) {
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
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != effPCPHama02_tag)
    {
      sub_8FC2C0(*(v9 + 64), effPCPHama02_tag, v13);
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

// 0x115c340
void effPCPHama02SetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHama02_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPHama02_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *(&(*hData)[2].klass + 1) = scale;
}

// 0x115d070
effPCPHamaon_tag *effPCPHamaonCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v6;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  u64 *v11;
  u64 *v12;
  Il2CppObject *Handle;
  Il2CppClass *v17;
  s64 v18;
  char *v19;
  s64 *v20;
  u64 i;
  u64 v23;
  u64 v25;
  Il2CppClass *v26;
  s64 v27;
  s64 v29;
  s64 *v31;
  s64 *v34;
  u64 v38;
  u64 v40;
  Il2CppClass *v41;
  s64 v42;
  s64 v44;
  s64 *v46;
  s64 *v49;
  u64 v53;
  u64 v55;
  Il2CppClass *v56;
  s64 v57;
  s64 v59;
  s64 *v61;
  s64 *v64;
  u64 v67[2];
  char *v68;
  effPCPHamaon_tag_o *pPCPHamaon;

  pPCPHamaon = 0;
  v6 = *hData;
  if (*hData)
  {
    klass = v6->klass;
    if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHamaon_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPHamaon_tag, v67);
      if ((v67[0] & 1) != 0)
        v9 = v68;
      else
        v9 = v67 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  v11 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v11);
  v12 = Allocate(effPCPHamaon_tag);
  _ctor(v12, 0);
  pPCPHamaon = v12;
  Clear(v12);
  v12[5] = dds3EffectPartCopy(&v6[2].monitor, bPos, 0);
  Handle = dds3EffectPartGetHandle(v12 + 5);
  if (Handle)
  {
    v17 = Handle->klass;
    if (Handle->klass->_2.typeHierarchyDepth < v18
      || v17->_2.typeHierarchy[v18 - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(v17->_1.element_class, dds3ModelHandle_t, v67);
      if ((v67[0] & 1) != 0)
        v19 = v68;
      else
        v19 = v67 + 1;
      v20 = sub_8C4940(v19);
    }
  }
  for (i = 0; i != 4; ++i)
  {
    v23 = v12[6];
    v25 = v23 + 8 * i;
    v26 = v6[3].klass;
    v27 = *(v25 + 32);
    v29 = *(&v26->_1.byval_arg.data + i);
    else if (!*(v29 + 24))
    {
LABEL_38:
    }
    v31 = dds3EffectPartCopy((v29 + 32), bPos, 0);
    v34 = v31;
    *(v27 + 32) = v34;
    effPCPHamaonPartInit(&pPCPHamaon, i, 0);
    v38 = v12[6];
    v40 = v38 + 8 * i;
    v41 = v6[3].klass;
    v42 = *(v40 + 32);
    v44 = *(&v41->_1.byval_arg.data + i);
    else if (!*(v44 + 24))
    {
LABEL_54:
    }
    v46 = dds3EffectPartCopy((v44 + 32), bPos, 0);
    v49 = v46;
    *(v42 + 40) = v49;
    effPCPHamaonPartInit(&pPCPHamaon, i, 1u);
    v53 = v12[6];
    v55 = v53 + 8 * i;
    v56 = v6[3].klass;
    v57 = *(v55 + 32);
    v59 = *(&v56->_1.byval_arg.data + i);
    else if (!*(v59 + 24))
    {
LABEL_70:
    }
    v61 = dds3EffectPartCopy((v59 + 32), bPos, 0);
    v64 = v61;
    *(v57 + 48) = v64;
    effPCPHamaonPartInit(&pPCPHamaon, i, 2u);
  }
  sub_854930((v12 + 2), 0);
  sub_854930((v12 + 2), 1u);
  sub_854930((v12 + 2), 2u);
  v12[4] = 0x3F80000080808080LL;
  return v12;
}

// 0x115c910
effPCPHamaon_tag *effPCPHamaonCreate(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *v6;
  s64 *Interface;
  char *v8;
  s64 *v9;
  u64 *v10;
  u64 *v11;
  Il2CppObject *Handle;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v18;
  s64 *v19;
  u64 v20;
  u64 v21;
  u64 v22;
  u64 v23;
  s64 v25;
  u64 v26;
  s64 v28;
  s32 v29;
  s64 *v31;
  s64 *v34;
  s64 *v37;
  s64 *v38;
  dds3EffectPCPData_t_o *hPCPData;
  effPCPHamaon_tag_o *pPCPHamaon;
  u64 v45[2];
  char *v46;
  s32 bPosa;
  s32 pos;

  bPosa = bPos;
  pos = bPos;
  pPCPHamaon = 0;
  hPCPData = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(hPCPData);
  v5 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v5->klass->_1.element_class, v6, v45);
      if ((v45[0] & 1) != 0)
        v8 = v46;
      else
        v8 = v45 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(hPCPData, Interface, &pos);
  v10 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v10);
  v11 = Allocate(effPCPHamaon_tag);
  _ctor(v11, 0);
  pPCPHamaon = v11;
  Clear(v11);
  v11[5] = dds3EffectPCPDataPartCreate(hPCPData, Interface, bPosa, 0);
  Handle = dds3EffectPartGetHandle(v11 + 5);
  if (Handle)
  {
    klass = Handle->klass;
    if (Handle->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, v45);
      if ((v45[0] & 1) != 0)
        v18 = v46;
      else
        v18 = v45 + 1;
      v19 = sub_8C4940(v18);
    }
  }
  v20 = 0;
  do
  {
    v21 = 0;
    v22 = v20++;
    do
    {
      v23 = v11[6];
      v25 = *(v23 + 8 * v22 + 32);
      if (v21)
      {
        v26 = v11[6];
        v28 = *(v26 + 8 * v22 + 32);
        v29 = pos;
        else if (!*(v28 + 24))
        {
          goto LABEL_33;
        }
        v31 = dds3EffectPartCopy((v28 + 32), v29, 0);
        v34 = v31;
        *(v25 + 8 * v21 + 32) = v34;
        {
LABEL_39:
        }
      }
      else
      {
        v37 = dds3EffectPCPDataPartCreate(hPCPData, Interface, bPosa, v20);
        v38 = v37;
        *(v25 + 32) = v38;
          goto LABEL_39;
      }
      effPCPHamaonPartInit(&pPCPHamaon, v22, v21++);
    }
    while (v21 != 3);
  }
  while (v20 != 4);
  sub_854930((v11 + 2), 0);
  sub_854930((v11 + 2), 1u);
  sub_854930((v11 + 2), 2u);
  v11[4] = 0x3F80000080808080LL;
  return v11;
}

// 0x115cdd0
void effPCPHamaonDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s64 i;
  Il2CppClass *v10;
  u64 v11;
  s64 v13;
  Il2CppClass *v16;
  s64 v18;
  Il2CppClass *v21;
  s64 v23;
  u64 v25[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHamaon_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPHamaon_tag, v25);
      if ((v25[0] & 1) != 0)
        v6 = v25[2];
      else
        v6 = v25 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  dds3EffectPartDelete(&v3[2].monitor);
  for (i = 4; i != 8; ++i)
  {
    v10 = v3[3].klass;
    v11 = i - 4;
    v13 = *(&v10->_1.image + i);
    else if (!*(v13 + 24))
    {
LABEL_25:
    }
    dds3EffectPartDelete((v13 + 32), 0);
    v16 = v3[3].klass;
    v18 = *(&v16->_1.image + i);
    else if ((*(v18 + 24) & 0xFFFFFFFE) == 0)
    {
LABEL_31:
    }
    dds3EffectPartDelete((v18 + 40), 0);
    v21 = v3[3].klass;
    v23 = *(&v21->_1.image + i);
    else if (*(v23 + 24) <= 2uLL)
    {
LABEL_37:
    }
    dds3EffectPartDelete((v23 + 48), 0);
  }
}

// 0x115d690
void effPCPHamaonDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  u64 *v9;
  Il2CppObject *Handle;
  Il2CppClass *v12;
  s64 v13;
  char *v14;
  s64 *v15;
  u64 v18;
  u64 v19;
  u64 *monitor;
  s64 v22;
  u64 *v24;
  s64 v26;
  bool v28;
  Il2CppClass *v29;
  s64 v31;
  Il2CppObject *v33;
  Il2CppClass *v35;
  s64 v36;
  char *v37;
  s64 *v38;
  u32 v39;
  sdfModelRootNode_t_o *modelRoot;
  dds3ModelHandle_t_o *v43;
  dds3ModelHandle_t_o *v44;
  dds3ModelHandle_t_o *aHandle;
  u64 v46[2];
  char *v47;

  v44 = 0;
  aHandle = 0;
  v43 = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHamaon_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPHamaon_tag, v46);
      if ((v46[0] & 1) != 0)
        v6 = v47;
      else
        v6 = v46 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v8);
  aHandle = v8;
  v9 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v9);
  v44 = v9;
  else
  {
    Handle = dds3EffectPartGetHandle(&v3[2].monitor);
    if (Handle)
    {
LABEL_13:
      v12 = Handle->klass;
      if (Handle->klass->_2.typeHierarchyDepth < v13
        || v12->_2.typeHierarchy[v13 - 1] != dds3ModelHandle_t)
      {
        sub_8FC2C0(v12->_1.element_class, dds3ModelHandle_t, v46);
        if ((v46[0] & 1) != 0)
          v14 = v47;
        else
          v14 = v46 + 1;
        v15 = sub_8C4940(v14);
      }
    }
  }
  aHandle = Handle;
  SDF_VU0__LOADVECTOR(v3[1]);
  mdlSetPosition(&aHandle);
  dds3EffectPartSetScale(&v3[2].monitor, *(&v3[2].klass + 1), 0);
  v43 = aHandle;
  dds3EffectPartModelDraw(&v43);
  v18 = 0;
  do
  {
    v19 = 0;
    do
    {
      while (1)
      {
        monitor = v3[4].monitor;
        v22 = monitor[v18 + 4];
        if (!*(v22 + 4 * v19 + 32))
          break;
        v24 = v3[4].monitor;
        v26 = v24[v18 + 4];
        --*(v26 + 4 * v19 + 32);
        v28 = v19++ >= 2;
        if (v28)
          goto LABEL_60;
      }
      v29 = v3[3].klass;
      v31 = *(&v29->_1.byval_arg.data + v18);
      else if (v19 >= *(v31 + 24))
      {
        goto LABEL_41;
      }
      v33 = dds3EffectPartGetHandle((v31 + 8 * v19 + 32), 0);
      if (v33)
      {
        v35 = v33->klass;
        if (v33->klass->_2.typeHierarchyDepth < v36
          || v35->_2.typeHierarchy[v36 - 1] != dds3ModelHandle_t)
        {
          sub_8FC2C0(v35->_1.element_class, dds3ModelHandle_t, v46);
          if ((v46[0] & 1) != 0)
            v37 = v47;
          else
            v37 = v46 + 1;
          v38 = sub_8C4940(v37);
        }
      }
      v44 = v33;
      v39 = v3[2].klass;
      mdlSetColor(&v44, v39);
      modelRoot = aHandle->modelRoot;
      sdfModelGetMarkPosUnity(modelRoot, v19 + 1 + 4 * v18);
      mdlSetPosition(&v44);
      v43 = v44;
      dds3EffectPartModelDraw(&v43);
      v28 = v19++ >= 2;
    }
    while (!v28);
LABEL_60:
    ;
  }
  while (v18++ <= 2);
}

// 0x115c520
void effPCPHamaonPartInit(effPCPHamaon_tag **pPCPHamaon, u32 kind, u32 attach) {
  u64 *v7;
  struct effPartHandle_t_array_array *hPart;
  effPartHandle_t_array *v11;
  s64 v12;
  Il2CppObject *Handle;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v18;
  s64 *v19;
  f32 v20;
  f32 v21;
  f32 v22;
  f32 v23;
  struct effPartHandle_t_array_array *v25;
  effPartHandle_t_array *v27;
  struct System_UInt32_array_array *interval;
  System_UInt32_array *v31;
  u32 max_length;
  s32 v34;
  UnityEngine_Matrix4x4_o v36;
  UnityEngine_Matrix4x4_o v37;
  UnityEngine_Matrix4x4_o aMatrix;

  memset(&aMatrix, 0, sizeof(aMatrix));
  v7 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v7);
  hPart = (*pPCPHamaon)->hPart;
  v11 = hPart->m_Items[kind];
  else
  {
    v12 = attach;
    if (LODWORD(v11->max_length) <= attach)
      goto LABEL_8;
  }
  Handle = dds3EffectPartGetHandle(&v11->m_Items[v12]);
  if (Handle)
  {
    klass = Handle->klass;
    if (Handle->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, &v37);
      if ((LOBYTE(v37.m00) & 1) != 0)
        v18 = *&v37.m01;
      else
        v18 = &v37.m00 + 1;
      v19 = sub_8C4940(v18);
    }
  }
  v20 = attach;
  v21 = v20 * -1.0472;
  switch (kind)
  {
    case 2u:
      v23 = -v21;
      break;
    case 1u:
      v22 = -v21;
      goto LABEL_34;
    case 0u:
      v22 = v21;
LABEL_34:
      SetRotateMatrixY(v22);
      goto LABEL_40;
    default:
      v23 = v21;
      break;
  }
  SetRotateMatrixZ(v23);
LABEL_40:
  SDF_VU0__STOREMATRIX(&aMatrix);
  v25 = (*pPCPHamaon)->hPart;
  v27 = v25->m_Items[kind];
  v37 = aMatrix;
  else if (LODWORD(v27->max_length) <= attach)
  {
    goto LABEL_45;
  }
  v36 = v37;
  dds3EffectPartSetRotateMatrix(&v27->m_Items[v12], &v36);
  interval = (*pPCPHamaon)->interval;
  v31 = interval->m_Items[kind];
  max_length = v31->max_length;
  if ((attach & 1) != 0)
  {
    v34 = 5;
  }
  else
  {
    v34 = 0;
  }
  v31->m_Items[v12] = v34;
}

// 0x115ddb0
void effPCPHamaonSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHamaon_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPHamaon_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[2].klass) = abgr;
}

// 0x115db90
void effPCPHamaonSetPosition(void **hData, sdfVector4_t pPos) {
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
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != effPCPHamaon_tag)
    {
      sub_8FC2C0(*(v9 + 64), effPCPHamaon_tag, v13);
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

// 0x115dcc0
void effPCPHamaonSetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHamaon_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPHamaon_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *(&(*hData)[2].klass + 1) = scale;
}

// 0x118bb70
effPCPHelperBED_tag *effPCPHelperBEDCopy(void **hData, s32 bPos, bool tbldata) {
  s32 v4;
  Il2CppObject *v6;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  effPCPHelperBEDParam_t_o *v11;
  effPCPHelperBED_tag_o *v13;
  effPCPHelperBED_tag_o *v16;
  u64 v17[3];

  v4 = bPos;
  v16 = 0;
  v6 = *hData;
  if (*hData)
  {
    klass = v6->klass;
    if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHelperBED_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPHelperBED_tag, v17);
      if ((v17[0] & 1) != 0)
        v9 = v17[2];
      else
        v9 = v17 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  v11 = v6[1].klass;
  v16 = effPCPHelperBEDCreate(v11, 0, 0);
  v13 = v16;
  v16->hHelper = dds3EffectPartCopy(&v6[3], v4, 0);
  v13->hBED = v6[2].monitor;
  effPCPHelperInit(&v16);
  return v13;
}

// 0x118b6b0
effPCPHelperBED_tag *effPCPHelperBEDCreate(effPCPHelperBEDParam_t *pParam, void *pPBData, void *pBEDData) {
  u64 *v7;
  u64 *v8;
  effBTL_t_o **v10;
  Il2CppClass *v11;
  s64 *Interface;
  char *v13;
  s64 *v14;
  effBTL_t_o *v15;
  effPCPHelperBED_tag_o *v17[3];
  effPCPHelperBED_tag_o *pHelperBED;

  v7 = Allocate(effPCPHelperBED_tag);
  _ctor(v7, 0);
  pHelperBED = v7;
  v8 = Allocate(effPCPHelperBEDParam_t);
  effPCPHelperBEDParam_t___ctor(v8);
  v7[2] = v8;
  effPCPHelperBEDParam_t__pClone(pParam, v7 + 2);
  v7[3] = 0;
  v7[5] = 0;
  v10 = (v7 + 5);
  *(v7 + 18) = -2139062144;
  v7[6] = 0;
  v7[7] = 1065353216;
  if (pPBData)
  {
    v7[6] = dds3EffectPartCreate(3u, pPBData, 0, 0);
  }
  if (!pBEDData)
  {
    if (!*v10)
      return v7;
    goto LABEL_20;
  }
  Interface = QueryInterface(pBEDData, byte);
  if (!Interface)
  {
    sub_8FC2C0(pBEDData->klass->_1.element_class, v11, v17);
    if ((v17[0] & 1) != 0)
      v13 = v17[2];
    else
      v13 = v17 + 1;
    v14 = sub_8C4940(v13);
  }
  v15 = effEveBEDCreate(Interface);
  *v10 = v15;
  if (v15)
  {
LABEL_20:
    effPCPHelperInit(&pHelperBED);
  }
  return v7;
}

// 0x118b8b0
effPCPHelperBED_tag *effPCPHelperBEDCreatePCF(void **hData, s32 bPos, bool tbldata) {
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
  struct dds3EffectPCPData_Part_t_array *v20;
  Il2CppObject *v21;
  effPCPHelperBEDParam_t_o *v22;
  u32 v24;
  Il2CppObject *EffPCPpBEDData;
  struct dds3EffectPCPData_Part_t_array *v27;
  Il2CppObject *v28;
  Il2CppObject *v29;
  Il2CppObject *v32;
  effPCPHelperBEDParam_t_c *klass;
  s64 typeHierarchyDepth;
  char *v35;
  s64 *v36;
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
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 26);
  v20 = v6->pcpData;
  v21 = *hData;
  v22 = DataUnityOffSet;
  v24 = v20->m_Items[1]->offset;
  EffPCPpBEDData = GetEffPCPpBEDData(v21, v24 + bPos);
  v27 = v6->pcpData;
  v28 = *hData;
  v29 = EffPCPpBEDData;
  v32 = GetEffPCPpBEDData(v28, v27->m_Items[2]->offset + bPos);
  if (v22)
  {
    klass = v22->klass;
    if (v22->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHelperBEDParam_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPHelperBEDParam_t, v39);
      if ((v39[0] & 1) != 0)
        v35 = v40;
      else
        v35 = v39 + 1;
      v36 = sub_8C4940(v35);
    }
  }
  return effPCPHelperBEDCreate(v22, v29, v32);
}

// 0x118bcf0
void effPCPHelperBEDDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s64 klass_high;
  u64 i;
  u64 *monitor;
  effEveBEDCutHandle_t_o *v13;
  effBTL_t_o *v14;
  u64 v15[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHelperBED_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPHelperBED_tag, v15);
      if ((v15[0] & 1) != 0)
        v6 = v15[2];
      else
        v6 = v15 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  dds3EffectPartDelete(&v3[3]);
  klass_high = HIDWORD(v3[4].klass);
  if (klass_high)
  {
    for (i = 0; i != klass_high; ++i)
    {
      monitor = v3[1].monitor;
      v13 = *(monitor[i + 4] + 48LL);
      if (v13)
      {
        effEveBEDCutDelete(v13);
      }
    }
  }
  v14 = v3[2].monitor;
  if (!v14->CutCount)
  {
    effEveBEDDelete(v14);
  }
}

// 0x118bed0
void effPCPHelperBEDDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  u64 *v9;
  s32 v11;
  s32 monitor_high;
  s32 v13;
  dds3ModelHandle_t_o *Handle;
  dds3ModelHandle_t_c *v15;
  s64 v16;
  char *v17;
  s64 *v18;
  sdfModelRootNode_t_o *modelRoot;
  s64 klass_high;
  Il2CppClass *v24;
  s32 data;
  f32 v26;
  f32 v27;
  u64 v28;
  f32 v29;
  s32 v31;
  s32 v32;
  s32 v33;
  bool v34;
  s32 v35;
  u64 *v36;
  s64 v38;
  f32 v39;
  s32 v40;
  s32 v41;
  bool v42;
  u32 monitor;
  s32 v44;
  Il2CppObject *hDataa;
  UnityEngine_Vector4_o v46;
  UnityEngine_Vector4_o v47;
  UnityEngine_Vector4_o p;
  u64 v49[2];
  char *v50;
  dds3ModelHandle_t_o *aHandle;

  aHandle = 0;
  *&p.x = 0;
  *&p.z = 0;
  hDataa = 0;
  *&v47.x = 0;
  *&v47.z = 0;
  *&v46.x = 0;
  *&v46.z = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHelperBED_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPHelperBED_tag, v49);
      if ((v49[0] & 1) != 0)
        v6 = v50;
      else
        v6 = v49 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v8);
  aHandle = v8;
  v9 = Allocate(effEveBEDParams_t);
  effEveBEDParams_t___ctor(v9);
  *&p.x = 0;
  *&p.z = 0;
  *&v47.x = 0;
  *&v47.z = 0;
  *&v46.x = 0;
  *&v46.z = 0;
  sub_854930(&v46, 0);
  sub_854930(&v46, 1u);
  sub_854930(&v46, 2u);
  sub_854930(&v46, 3u);
  sub_854930((v9 + 4), 0);
  sub_854930((v9 + 4), 1u);
  sub_854930((v9 + 4), 2u);
  sub_854930((v9 + 4), 3u);
  sub_854930((v9 + 2), 3u);
  v9[6] = 0x42C8000042C80000LL;
  *(v9 + 14) = 1065353216;
  monitor_high = HIDWORD(v3[3].monitor);
  v11 = v3[4].klass;
  v13 = v11 - monitor_high;
  if (v11 < monitor_high)
    return;
  Handle = dds3EffectPartGetHandle(&v3[3]);
  if (!Handle)
    goto LABEL_21;
LABEL_14:
  v15 = Handle->klass;
  if (Handle->klass->_2.typeHierarchyDepth < v16
    || v15->_2.typeHierarchy[v16 - 1] != dds3ModelHandle_t)
  {
    sub_8FC2C0(v15->_1.element_class, dds3ModelHandle_t, v49);
    if ((v49[0] & 1) != 0)
      v17 = v50;
    else
      v17 = v49 + 1;
    v18 = sub_8C4940(v17);
  }
  aHandle = Handle;
  modelRoot = Handle->modelRoot;
  SDF_VU0__LOADVECTOR(*&v3[1].klass->_1.name);
  mdlSetPosition(&aHandle);
  SDF_VU0__LOADVECTOR(v46);
  mdlSetScale(&aHandle);
  hDataa = aHandle;
  dds3EffectPartModelDraw(&hDataa);
  klass_high = HIDWORD(v3[4].klass);
  if (klass_high)
  {
    v24 = v3[1].klass;
    data = v24->_1.byval_arg.data;
    LODWORD(v24) = HIDWORD(v24->_1.byval_arg.data);
    v26 = data;
    v27 = v24;
    monitor = v3[4].monitor;
    v44 = data;
    v28 = 0;
    v42 = v13 > v24 || v24 == 0;
    while (1)
    {
      while (1)
      {
        v36 = v3[1].monitor;
        v38 = v36[v28 + 4];
        if (monitor_high)
        {
          if (monitor_high < 0)
            goto LABEL_65;
        }
        else
        {
          v39 = *&v3[3].monitor;
          effEveBEDCutSetScale((v38 + 48), v39, 0);
        }
        sdfModelGetMarkPosUnity(modelRoot, v28);
        SDF_VU0__STOREVECTOR(&p);
        if (monitor_high)
          break;
        sub_854710(&p, 0);
        sub_854930(v38 + 16, 0);
        sub_854710(&p, 1u);
        sub_854930(v38 + 16, 1u);
        sub_854710(&p, 2u);
        sub_854930(v38 + 16, 2u);
        sub_854930(v38 + 16, 3u);
        if (klass_high == ++v28)
          goto LABEL_66;
      }
      v31 = *(v38 + 32);
      if (*(v38 + 32))
      {
        v33 = *(v38 + 36);
        v40 = *(v38 + 40);
        v34 = __OFSUB__(v40, v33);
        v35 = v40 - v33;
        if (!((v35 < 0) ^ v34 | (v35 == 0)))
          goto LABEL_56;
LABEL_65:
        if (klass_high == ++v28)
          break;
      }
      else
      {
        sub_854710(v38 + 16, 0);
        sub_854930(&v47, 0);
        sub_854710(v38 + 16, 1u);
        sub_854930(&v47, 1u);
        sub_854710(v38 + 16, 2u);
        sub_854930(&v47, 2u);
        sub_854930(&v47, 3u);
        SDF_VU0__LOADVECTOR(p);
        SDF_VU0__LOADVECTOR_B(v47);
        SDF_VU0__SUBVECTOR();
        if (SDF_VU0__GETLENGTH() <= 1.0)
        {
          v31 = *(v38 + 32);
          v33 = *(v38 + 36);
          v32 = *(v38 + 40);
          v34 = __OFSUB__(v32, v33);
          v35 = v32 - v33;
          if ((v35 < 0) ^ v34 | (v35 == 0))
            goto LABEL_65;
        }
        else
        {
          v31 = 1;
          *(v38 + 32) = 1;
          *(v38 + 40) = v13;
          v33 = *(v38 + 36);
          v41 = *(v38 + 40);
          v34 = __OFSUB__(v41, v33);
          v35 = v41 - v33;
          if ((v35 < 0) ^ v34 | (v35 == 0))
            goto LABEL_65;
        }
LABEL_56:
        if (!v31)
          goto LABEL_65;
        if (v44 && v33 < v44)
        {
          v29 = v33 / v26;
        }
        else
        {
          v29 = 1.0;
          if (!v42)
            v29 = v35 / v27;
        }
        *(v9 + 15) = effColorBlend(monitor & 0xFFFFFF, monitor, v29);
        sub_854710(&p, 0);
        sub_854930((v9 + 2), 0);
        sub_854710(&p, 1u);
        sub_854930((v9 + 2), 1u);
        sub_854710(&p, 2u);
        sub_854930((v9 + 2), 2u);
        effEveBEDCutSetParams((v38 + 48), v9, 0);
        effEveBEDCutDraw((v38 + 48), 0);
        ++*(v38 + 36);
        if (klass_high == ++v28)
          break;
      }
    }
  }
LABEL_66:
  ++HIDWORD(v3[3].monitor);
}

// 0x118c920
dds3ModelHandle_t *effPCPHelperBEDGetModel(effPCPHelperBED_tag *pHelperBED) {
  effPartHandle_t_o **p_hHelper;
  dds3ModelHandle_t_o *result;
  dds3ModelHandle_t_c *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  p_hHelper = &pHelperBED->hHelper;
  else
  {
    result = dds3EffectPartGetHandle(p_hHelper);
    if (!result)
      return result;
  }
  klass = result->klass;
  if (result->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  return result;
}

// 0x118c830
void effPCPHelperBEDSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHelperBED_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPHelperBED_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[4].monitor) = abgr;
}

// 0x118c620
void effPCPHelperBEDSetPosition(void **hData, sdfVector4_t pPos) {
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
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHelperBED_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPHelperBED_tag, v12);
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

// 0x118c740
void effPCPHelperBEDSetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHelperBED_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPHelperBED_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *&(*hData)[3].monitor = scale;
}

// 0x118b1b0
void effPCPHelperInit(effPCPHelperBED_tag **pHelperBED) {
  u64 *v3;
  u64 *v4;
  effPartHandle_t_o **p_hHelper;
  Il2CppObject *Handle;
  Il2CppObject *v9;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v12;
  s64 *v13;
  Il2CppClass *v14;
  Il2CppClass *v15;
  Il2CppClass *v16;
  void *v17;
  void *v18;
  void *v19;
  void *v20;
  effPCPHelperBED_tag_o *v22;
  effPCPHelperBED_tag_o *v24;
  sdfModelRootNode_t_o *v25;
  effPCPHelperBED_tag_o *v27;
  u64 MarkCount;
  s64 v29;
  s64 v30;
  u64 v32;
  u32 *pPart;
  u64 *v34;
  struct effPCPHelperBEDPart_tag_array *v37;
  struct effPCPHelperBEDPart_tag_array *v39;
  struct effPCPHelperBEDPart_tag_array *v41;
  struct effPCPHelperBEDPart_tag_array *v43;
  s64 v45;
  effBTL_t_o *hBED;
  UnityEngine_Matrix4x4_o v47;
  Il2CppObject *hData;

  hData = 0;
  v3 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v3);
  v4 = Allocate(effEveBEDParams_t);
  effEveBEDParams_t___ctor(v4);
  p_hHelper = &(*pHelperBED)->hHelper;
  Handle = dds3EffectPartGetHandle(p_hHelper);
  v9 = Handle;
  if (Handle)
  {
    klass = Handle->klass;
    if (Handle->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, &v47);
      if ((LOBYTE(v47.m00) & 1) != 0)
        v12 = *&v47.m01;
      else
        v12 = &v47.m00 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  hData = v9;
  v14 = v9[4].klass;
  get_identity(&v47, 0);
  v16 = *&v47.m00;
  v15 = *&v47.m20;
  v17 = *&v47.m21;
  v14->_1.parent = *&v47.m01;
  v14->_1.generic_class = v17;
  v14->_1.castClass = v16;
  v14->_1.declaringType = v15;
  v19 = *&v47.m02;
  v18 = *&v47.m22;
  v20 = *&v47.m23;
  v14->_1.klass = *&v47.m03;
  v14->_1.fields = v20;
  v14->_1.typeDefinition = v19;
  v14->_1.interopData = v18;
  dds3EffectPartModelDraw(&hData);
  v22 = *pHelperBED;
  v22->MarkLength = mdlGetMotionLengthUnity(v9);
  v24 = *pHelperBED;
  v25 = v9[4].klass;
  v24->MarkCount = sdfModelGetMarkPosCountUnity(v25);
  dds3EffectPartModelDelete(&hData);
  v27 = *pHelperBED;
  MarkCount = (*pHelperBED)->MarkCount;
  v27->pPart = NewSpecific(effPCPHelperBEDPart_tag, MarkCount);
  sub_854930((v4 + 2), 0);
  sub_854930((v4 + 2), 1u);
  sub_854930((v4 + 2), 2u);
  sub_854930((v4 + 2), 3u);
  sub_854930((v4 + 4), 0);
  sub_854930((v4 + 4), 1u);
  sub_854930((v4 + 4), 2u);
  sub_854930((v4 + 4), 3u);
  v4[6] = 0x42C8000042C80000LL;
  v4[7] = 0x808080803F800000LL;
  if (MarkCount)
  {
    v29 = 4;
    v30 = -MarkCount;
    do
    {
      v32 = v29 - 4;
      pPart = (*pHelperBED)->pPart;
      v34 = Allocate(effPCPHelperBEDPart_tag);
      _ctor(v34, 0);
      *&pPart[2 * v29] = v34;
      v37 = (*pHelperBED)->pPart;
      *(*(&v37->obj.klass + v29) + 32LL) = 0;
      v39 = (*pHelperBED)->pPart;
      *(*(&v39->obj.klass + v29) + 36LL) = 0;
      v41 = (*pHelperBED)->pPart;
      *(*(&v41->obj.klass + v29) + 40LL) = 0;
      v43 = (*pHelperBED)->pPart;
      v45 = *(&v43->obj.klass + v29);
      hBED = (*pHelperBED)->hBED;
      ++v29;
      *(v45 + 48) = effEveBEDCutCreate(hBED, 2u, v4);
    }
    while (v30 + v29 != 4);
  }
}

// 0x11698f0
effPCPHouden01_tag *effPCPHouden01Copy(void **hData, s32 bPos, bool tbldata) {
  u64 *v4;
  Il2CppObject *hDataa;

  v4 = Allocate(effPCPHouden01_tag);
  _ctor(v4, 0);
LABEL_7:
  hDataa = 0;
  hDataa = effPCP_Houden01_ThunderSpherePoly_Param;
  v4[6] = effPCPThunderSpherePolyCreate(&hDataa, 0, 0);
  *(v4 + 10) = 0;
  return v4;
}

// 0x1169620
effPCPHouden01_tag *effPCPHouden01Create(void **hData, s32 bPos, bool tbldata) {
  u64 *v5;
  s64 *v6;
  Il2CppClass *v7;
  s64 *Interface;
  char *v9;
  s64 *v10;
  u64 *v11;
  Il2CppObject *hDataa[3];
  s32 pos;

  pos = bPos;
  v5 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v5);
  v6 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(v6, byte);
    if (!Interface)
    {
      sub_8FC2C0(*(*v6 + 64), v7, hDataa);
      if ((hDataa[0] & 1) != 0)
        v9 = hDataa[2];
      else
        v9 = hDataa + 1;
      v10 = sub_8C4940(v9);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v5, Interface, &pos);
  v11 = Allocate(effPCPHouden01_tag);
  _ctor(v11, 0);
LABEL_14:
  hDataa[0] = 0;
  hDataa[0] = effPCP_Houden01_ThunderSpherePoly_Param;
  v11[6] = effPCPThunderSpherePolyCreate(hDataa, 0, 0);
  *(v11 + 10) = 0;
  return v11;
}

// 0x11697f0
void effPCPHouden01Delete(void **hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  Il2CppClass *v7;
  u64 v8[3];

  v7 = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHouden01_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPHouden01_tag, v8);
    if ((v8[0] & 1) != 0)
      v5 = v8[2];
    else
      v5 = v8 + 1;
    v6 = sub_8C4940(v5);
  }
  v7 = (*hData)[3].klass;
  effPCPThunderSpherePolyDelete(&v7);
}

// 0x11699f0
void effPCPHouden01Draw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u32 monitor;
  effPCPThunderSpherePolyParam_t_o *Param;
  f32 v10;
  f32 v11;
  f32 v12;
  u32 klass_high;
  Il2CppClass *v14;
  u64 v15[3];

  v14 = 0;
  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHouden01_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPHouden01_tag, v15);
      if ((v15[0] & 1) != 0)
        v6 = v15[2];
      else
        v6 = v15 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  monitor = v3[2].monitor;
  if (monitor != 65)
  {
    if (monitor > 0x1D)
    {
      if (monitor >= 0x39)
      {
        v12 = monitor;
        klass_high = effColorBlend(HIDWORD(v3[2].klass), 0, (v12 + -57.0) * 0.125, 0);
        v14 = v3[3].klass;
LABEL_16:
        effPCPThunderSpherePolySetColor(&v14, klass_high);
        v14 = v3[3].klass;
        effPCPThunderSpherePolySetPosition(&v14, v3[1]);
        v14 = v3[3].klass;
        effPCPThunderSpherePolyDraw(&v14);
        ++LODWORD(v3[2].monitor);
        return;
      }
    }
    else
    {
      Param = effPCPThunderSpherePolyGetParam(v3[3].klass);
      v10 = monitor;
      v11 = ((v10 / 30.0) * 200.0) + 150.0;
      Param->width = v11;
      Param->height = v11;
    }
    v14 = v3[3].klass;
    klass_high = HIDWORD(v3[2].klass);
    goto LABEL_16;
  }
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
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHouden01_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPHouden01_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[2].klass) = abgr;
}

// 0x1169bd0
void effPCPHouden01SetPosition(void **hData, sdfVector4_t pPos) {
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
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != effPCPHouden01_tag)
    {
      sub_8FC2C0(*(v9 + 64), effPCPHouden01_tag, v13);
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

// 0x1169d00
void effPCPHouden01SetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHouden01_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPHouden01_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *&(*hData)[2].klass = scale;
}

// 0x1160a50
effPCPHwave01_tag *effPCPHwave01Copy(void **hData, s32 bPos, bool tbldata) {
  effPartHandle_t_o **v6;
  effPartHandle_t_o *v7;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  u64 *v11;
  u64 v14[3];

  v6 = *hData;
  if (*hData)
  {
    v7 = *v6;
    if (LOBYTE((*v6)[9].klass) < typeHierarchyDepth
      || *(v7[6].monitor + typeHierarchyDepth - 1) != effPCPHwave01_tag)
    {
      sub_8FC2C0(v7[2].klass, effPCPHwave01_tag, v14);
      if ((v14[0] & 1) != 0)
        v9 = v14[2];
      else
        v9 = v14 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  v11 = Allocate(effPCPHwave01_tag);
  _ctor(v11, 0);
  v11[5] = dds3EffectPartCopy(v6 + 5, bPos, 0);
  v11[6] = dds3EffectPartCopy(v6 + 6, bPos, 0);
  sub_854930((v11 + 2), 0);
  sub_854930((v11 + 2), 1u);
  sub_854930((v11 + 2), 2u);
  *(v11 + 8) = -2139062144;
  return v11;
}

// 0x1160730
effPCPHwave01_tag *effPCPHwave01Create(void **hData, s32 bPos, bool tbldata) {
  u64 *v6;
  s64 *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  u64 *v12;
  s32 pos;
  u64 v16[3];

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(v7, byte);
    if (!Interface)
    {
      sub_8FC2C0(*(*v7 + 64), v8, v16);
      if ((v16[0] & 1) != 0)
        v10 = v16[2];
      else
        v10 = v16 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v6, Interface, &pos);
  v12 = Allocate(effPCPHwave01_tag);
  _ctor(v12, 0);
  v12[5] = dds3EffectPCPDataPartCreate(v6, Interface, bPos, 0);
  v12[6] = dds3EffectPCPDataPartCreate(v6, Interface, bPos, 1u);
  sub_854930((v12 + 2), 0);
  sub_854930((v12 + 2), 1u);
  sub_854930((v12 + 2), 2u);
  *(v12 + 8) = -2139062144;
  return v12;
}

// 0x1160920
void effPCPHwave01Delete(void **hData) {
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
      || *(v4[6].monitor + typeHierarchyDepth - 1) != effPCPHwave01_tag)
    {
      sub_8FC2C0(v4[2].klass, effPCPHwave01_tag, v8);
      if ((v8[0] & 1) != 0)
        v6 = v8[2];
      else
        v6 = v8 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  dds3EffectPartDelete(v3 + 5);
  dds3EffectPartDelete(v3 + 6);
}

// 0x1160c00
void effPCPHwave01Draw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  Il2CppObject *Handle;
  Il2CppClass *v11;
  s64 v12;
  char *v13;
  s64 *v14;
  effPartHandle_t_o **v16;
  sdfModelRootNode_t_o *modelRoot;
  dds3ModelHandle_t_o *v19;
  UnityEngine_Vector4_o p;
  u64 v21[2];
  char *v22;
  dds3ModelHandle_t_o *aHandle;

  aHandle = 0;
  *&p.x = 0;
  *&p.z = 0;
  v19 = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHwave01_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPHwave01_tag, v21);
      if ((v21[0] & 1) != 0)
        v6 = v22;
      else
        v6 = v21 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v8);
  aHandle = v8;
  *&p.x = 0;
  *&p.z = 0;
  else
  {
    Handle = dds3EffectPartGetHandle(&v3[2].monitor);
    if (!Handle)
      goto LABEL_19;
  }
  v11 = Handle->klass;
  if (Handle->klass->_2.typeHierarchyDepth < v12
    || v11->_2.typeHierarchy[v12 - 1] != dds3ModelHandle_t)
  {
    sub_8FC2C0(v11->_1.element_class, dds3ModelHandle_t, v21);
    if ((v21[0] & 1) != 0)
      v13 = v22;
    else
      v13 = v21 + 1;
    v14 = sub_8C4940(v13);
  }
LABEL_19:
  aHandle = Handle;
  SDF_VU0__LOADVECTOR(v3[1]);
  mdlSetPosition(&aHandle);
  v16 = &v3[3];
  dds3EffectPartSetColor(&v3[3], v3[2].klass);
  v19 = aHandle;
  dds3EffectPartModelDraw(&v19);
  modelRoot = aHandle->modelRoot;
  sdfModelGetMarkPosUnity(modelRoot, 1);
  SDF_VU0__STOREVECTOR(&p);
  dds3EffectPartSetPosition(v16, p);
  dds3EffectPartDraw(v16);
}

// 0x1160ff0
void effPCPHwave01SetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPHwave01_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPHwave01_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[2].klass) = abgr;
}

// 0x1160ec0
void effPCPHwave01SetPosition(void **hData, sdfVector4_t pPos) {
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
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != effPCPHwave01_tag)
    {
      sub_8FC2C0(*(v9 + 64), effPCPHwave01_tag, v13);
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

// 0x115e7e0
effPCPMHanma01_tag *effPCPMHanma01Copy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v6;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  Il2CppObject *v11;
  s64 i;
  u64 *monitor;
  u64 v18;
  s64 v20;
  u64 *v21;
  s64 v23;
  s64 *v25;
  s64 *v26;
  u64 *v28;
  s64 v30;
  u64 *v31;
  s64 v33;
  s64 *v35;
  s64 *v38;
  Il2CppObject *v41;
  u64 v42[3];

  v41 = 0;
  v6 = *hData;
  if (*hData)
  {
    klass = v6->klass;
    if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMHanma01_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPMHanma01_tag, v42);
      if ((v42[0] & 1) != 0)
        v9 = v42[2];
      else
        v9 = v42 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  v11 = Allocate(effPCPMHanma01_tag);
  _ctor(v11, 0);
  v41 = v11;
  Clear(v11);
  for (i = 4; i != 10; ++i)
  {
    monitor = v11[2].monitor;
    v18 = i - 4;
    v20 = monitor[i];
    v21 = v6[2].monitor;
    v23 = v21[i];
    else if (!*(v23 + 24))
    {
LABEL_22:
    }
    v25 = dds3EffectPartCopy((v23 + 32), bPos, 0);
    v26 = v25;
    *(v20 + 32) = v26;
    v28 = v11[2].monitor;
    v30 = v28[i];
    v31 = v6[2].monitor;
    v33 = v31[i];
    v35 = dds3EffectPartCopy((v33 + 40), bPos, 0);
    v38 = v35;
    *(v30 + 40) = v38;
    effPCPMHanma01PartInit(&v41, i - 4);
  }
  sub_854930(&v11[1], 0);
  sub_854930(&v11[1], 1u);
  sub_854930(&v11[1], 2u);
  v11[2].klass = 0x3F80000080808080LL;
  return v11;
}

// 0x115e1a0
effPCPMHanma01_tag *effPCPMHanma01Create(void **hData, s32 bPos, bool tbldata) {
  u64 *v6;
  s64 *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  Il2CppObject *v12;
  u64 i;
  u32 *v16;
  s64 v17;
  s64 *v21;
  s64 *v22;
  u32 *monitor;
  s64 v27;
  s64 *v28;
  s64 *v29;
  u64 *v31;
  u64 v32;
  s64 v34;
  s64 v36;
  s64 *v38;
  s64 *v41;
  Il2CppObject *v44;
  u64 v45[3];
  s32 pos;

  pos = bPos;
  v44 = 0;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(v7, byte);
    if (!Interface)
    {
      sub_8FC2C0(*(*v7 + 64), v8, v45);
      if ((v45[0] & 1) != 0)
        v10 = v45[2];
      else
        v10 = v45 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v6, Interface, &pos);
  v12 = Allocate(effPCPMHanma01_tag);
  _ctor(v12, 0);
  v44 = v12;
  Clear(v12);
  for (i = 0; i != 6; ++i)
  {
    if (i)
    {
      monitor = v12[2].monitor;
      if (i >= monitor[6])
        goto LABEL_27;
    }
    else
    {
      v16 = v12[2].monitor;
      v17 = *(v16 + 4);
      v21 = dds3EffectPCPDataPartCreate(v6, Interface, bPos, 6u);
      v22 = v21;
      *(v17 + 40) = v22;
      monitor = v12[2].monitor;
      if (!monitor[6])
      {
LABEL_27:
      }
    }
    v27 = *&monitor[2 * i + 8];
    v28 = dds3EffectPCPDataPartCreate(v6, Interface, bPos, i);
    v29 = v28;
    *(v27 + 32) = v29;
    v31 = v12[2].monitor;
    v32 = *(v31 + 6);
    v34 = v31[i + 4];
    v36 = *(v12[2].monitor + 4);
    v38 = dds3EffectPartCopy((v36 + 40), pos, 0);
    v41 = v38;
    *(v34 + 40) = v41;
    effPCPMHanma01PartInit(&v44, i);
  }
  sub_854930(&v12[1], 0);
  sub_854930(&v12[1], 1u);
  sub_854930(&v12[1], 2u);
  v12[2].klass = 0x3F80000080808080LL;
  return v12;
}

// 0x115e610
void effPCPMHanma01Delete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s64 i;
  u64 *monitor;
  s64 v11;
  u64 *v13;
  s64 v15;
  u64 v17[3];

  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMHanma01_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPMHanma01_tag, v17);
      if ((v17[0] & 1) != 0)
        v6 = v17[2];
      else
        v6 = v17 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  for (i = 4; i != 10; ++i)
  {
    monitor = v3[2].monitor;
    v11 = monitor[i];
    else if (!*(v11 + 24))
    {
LABEL_18:
    }
    dds3EffectPartDelete((v11 + 32), 0);
    v13 = v3[2].monitor;
    v15 = v13[i];
    dds3EffectPartDelete((v15 + 40), 0);
  }
}

// 0x115eb80
void effPCPMHanma01Draw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3ModelHandle_t_o **v9;
  u64 v10;
  dds3ModelHandle_t_o **v11;
  dds3ModelHandle_t_o **v12;
  Il2CppClass *v14;
  Il2CppClass *v16;
  bool v18;
  u64 *monitor;
  s64 v21;
  s64 *Handle;
  s64 *v24;
  s64 v25;
  s64 v26;
  char *v27;
  s64 *v28;
  s64 v30;
  s64 v31;
  char *v32;
  s64 *v33;
  u64 *v35;
  s64 v37;
  s64 *v39;
  s64 *v40;
  s64 v41;
  s64 v42;
  char *v43;
  s64 *v44;
  s64 v46;
  s64 v47;
  char *v48;
  s64 *v49;
  sdfModelRootNode_t_o *modelRoot;
  dds3ModelHandle_t_o *v61;
  UnityEngine_Vector4_o p;
  u64 v63[2];
  char *v64;

  *&p.x = 0;
  *&p.z = 0;
  v61 = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMHanma01_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPMHanma01_tag, v63);
      if ((v63[0] & 1) != 0)
        v6 = v64;
      else
        v6 = v63 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  *&p.x = 0;
  *&p.z = 0;
  v9 = NewSpecific(dds3ModelHandle_t, 2u);
  v10 = 0;
  v11 = v9 + 4;
  v12 = v9 + 5;
  do
  {
    while (1)
    {
      v14 = v3[3].klass;
      if (!*(&v14->_1.byval_arg.data + v10))
        break;
      v16 = v3[3].klass;
      --*(&v16->_1.byval_arg.data + v10);
      v18 = v10++ >= 5;
      if (v18)
        return;
    }
    monitor = v3[2].monitor;
    v21 = monitor[v10 + 4];
    else if (!*(v21 + 24))
    {
      goto LABEL_29;
    }
    Handle = dds3EffectPartGetHandle((v21 + 32), 0);
    v24 = Handle;
    if (Handle)
    {
      v25 = *Handle;
      if (*(*Handle + 288) < v26 || *(*(v25 + 200) + 8 * v26 - 8) != dds3ModelHandle_t)
      {
        sub_8FC2C0(*(v25 + 64), dds3ModelHandle_t, v63);
        if ((v63[0] & 1) != 0)
          v27 = v64;
        else
          v27 = v63 + 1;
        v28 = sub_8C4940(v27);
      }
      v30 = *v24;
      if (*(*v24 + 288) < v31 || *(*(v30 + 200) + 8 * v31 - 8) != dds3ModelHandle_t)
      {
        sub_8FC2C0(*(v30 + 64), dds3ModelHandle_t, v63);
        if ((v63[0] & 1) != 0)
          v32 = v64;
        else
          v32 = v63 + 1;
        v33 = sub_8C4940(v32);
      }
    }
    *v11 = v24;
    v35 = v3[2].monitor;
    v37 = v35[v10 + 4];
    v39 = dds3EffectPartGetHandle((v37 + 40), 0);
    v40 = v39;
    if (v39)
    {
      v41 = *v39;
      if (*(*v39 + 288) < v42 || *(*(v41 + 200) + 8 * v42 - 8) != dds3ModelHandle_t)
      {
        sub_8FC2C0(*(v41 + 64), dds3ModelHandle_t, v63);
        if ((v63[0] & 1) != 0)
          v43 = v64;
        else
          v43 = v63 + 1;
        v44 = sub_8C4940(v43);
      }
      v46 = *v40;
      if (*(*v40 + 288) < v47 || *(*(v46 + 200) + 8 * v47 - 8) != dds3ModelHandle_t)
      {
        sub_8FC2C0(*(v46 + 64), dds3ModelHandle_t, v63);
        if ((v63[0] & 1) != 0)
          v48 = v64;
        else
          v48 = v63 + 1;
        v49 = sub_8C4940(v48);
      }
    }
    *v12 = v40;
    SDF_VU0__LOADVECTOR(v3[1]);
    else if (!*(v9 + 6))
    {
LABEL_73:
    }
    mdlSetPosition(v11);
    mdlSetColor(v12, v3[2].klass);
    v61 = v9[4];
    dds3EffectPartModelDraw(&v61);
    if (*v11)
    {
      modelRoot = (*v11)->modelRoot;
      sdfModelGetMarkPosUnity(modelRoot, 1);
      SDF_VU0__STOREVECTOR(&p);
      else if (*(v9 + 6) <= 1u)
      {
LABEL_88:
      }
      mdlSetPosition(v12);
      v61 = *v12;
      dds3EffectPartModelDraw(&v61);
    }
    v18 = v10++ >= 5;
  }
  while (!v18);
}

// 0x115dea0
void effPCPMHanma01PartInit(effPCPMHanma01_tag **pPCPMHanma01, s32 number) {
  u64 *v5;
  struct effPartHandle_t_array_array *hPart;
  effPartHandle_t_array *v9;
  Il2CppObject *Handle;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v15;
  s64 *v16;
  struct effPartHandle_t_array_array *v17;
  effPartHandle_t_array *v19;
  Il2CppObject *v21;
  Il2CppClass *v23;
  s64 v24;
  char *v25;
  s64 *v26;
  struct System_UInt32_array *interval;
  u32 v28;
  u64 v30[2];
  char *v31;

  v5 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v5);
  hPart = (*pPCPMHanma01)->hPart;
  v9 = hPart->m_Items[number];
  if (!LODWORD(v9->max_length))
    goto LABEL_11;
LABEL_8:
  Handle = dds3EffectPartGetHandle(v9->m_Items);
  if (Handle)
  {
    klass = Handle->klass;
    if (Handle->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, v30);
      if ((v30[0] & 1) != 0)
        v15 = v31;
      else
        v15 = v30 + 1;
      v16 = sub_8C4940(v15);
    }
  }
  v17 = (*pPCPMHanma01)->hPart;
  v19 = v17->m_Items[number];
  v21 = dds3EffectPartGetHandle(&v19->m_Items[1]);
  if (v21)
  {
    v23 = v21->klass;
    if (v21->klass->_2.typeHierarchyDepth < v24 || v23->_2.typeHierarchy[v24 - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(v23->_1.element_class, dds3ModelHandle_t, v30);
      if ((v30[0] & 1) != 0)
        v25 = v31;
      else
        v25 = v30 + 1;
      v26 = sub_8C4940(v25);
    }
  }
  interval = (*pPCPMHanma01)->interval;
  v28 = DDS3EFFECT_RAND_I() % 0xA;
  interval->m_Items[number] = v28;
}

// 0x115f490
void effPCPMHanma01SetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMHanma01_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPMHanma01_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[2].klass) = abgr;
}

// 0x115f270
void effPCPMHanma01SetPosition(void **hData, sdfVector4_t pPos) {
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
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != effPCPMHanma01_tag)
    {
      sub_8FC2C0(*(v9 + 64), effPCPMHanma01_tag, v13);
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

// 0x115f3a0
void effPCPMHanma01SetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMHanma01_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPMHanma01_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *(&(*hData)[2].klass + 1) = scale;
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
  u64 *v5;
  s64 *v6;
  Il2CppClass *v7;
  s64 *Interface;
  char *v9;
  s64 *v10;
  u64 *v11;
  effPCPMZiodin01_tag_o *v14;
  u64 v15[3];
  s32 pos;

  pos = bPos;
  v14 = 0;
  v5 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v5);
  v6 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(v6, byte);
    if (!Interface)
    {
      sub_8FC2C0(*(*v6 + 64), v7, v15);
      if ((v15[0] & 1) != 0)
        v9 = v15[2];
      else
        v9 = v15 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v5, Interface, &pos);
  v11 = Allocate(effPCPMZiodin01_tag);
  _ctor(v11, 0);
  v14 = v11;
  effPCPMZiodin01Init(&v14);
  return v11;
}

// 0x1165fe0
void effPCPMZiodin01Delete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppClass *v8;
  Il2CppClass *v10;
  Il2CppClass *v12;
  Il2CppClass *v14;
  Il2CppClass *v16;
  Il2CppClass *v18;
  Il2CppClass *v20;
  Il2CppClass *v22;
  Il2CppClass *v24;
  Il2CppClass *v26;
  Il2CppClass *v28;
  Il2CppClass *v30;
  Il2CppObject *data;
  u64 v33[3];

  data = 0;
  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMZiodin01_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPMZiodin01_tag, v33);
      if ((v33[0] & 1) != 0)
        v6 = v33[2];
      else
        v6 = v33 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = v3[3].klass;
  data = v8->_1.byval_arg.data;
  effPCP_ThunderPolyDelete(&data);
  v10 = v3[3].klass;
  data = *&v10->_1.byval_arg.bits;
  effPCP_ThunderPolyDelete(&data);
  v12 = v3[3].klass;
  data = v12->_1.this_arg.data;
  effPCP_ThunderPolyDelete(&data);
  v14 = v3[3].klass;
  data = *&v14->_1.this_arg.bits;
  effPCP_ThunderPolyDelete(&data);
  v16 = v3[3].klass;
  data = v16->_1.element_class;
  effPCP_ThunderPolyDelete(&data);
  v18 = v3[3].klass;
  data = v18->_1.castClass;
  effPCP_ThunderPolyDelete(&data);
  v20 = v3[3].klass;
  data = v20->_1.declaringType;
  effPCP_ThunderPolyDelete(&data);
  v22 = v3[3].klass;
  data = v22->_1.parent;
  effPCP_ThunderPolyDelete(&data);
  v24 = v3[3].klass;
  data = v24->_1.generic_class;
  effPCP_ThunderPolyDelete(&data);
  v26 = v3[3].klass;
  data = v26->_1.typeDefinition;
  effPCP_ThunderPolyDelete(&data);
  v28 = v3[3].klass;
  data = v28->_1.interopData;
  effPCP_ThunderPolyDelete(&data);
  v30 = v3[3].klass;
  data = v30->_1.klass;
  effPCP_ThunderPolyDelete(&data);
}

// 0x11663e0
void effPCPMZiodin01Draw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  s64 i;
  Il2CppClass *v12;
  effPCP_ThunderPolyParam_t_o *Param;
  struct UnityEngine_Vector4_array *pos;
  effPCP_ThunderPolyParam_t_o *v16;
  struct UnityEngine_Vector4_array *v19;
  struct UnityEngine_Vector4_array *v21;
  struct UnityEngine_Vector4_array *v24;
  Il2CppClass *v26;
  struct UnityEngine_Vector4_array *v28;
  struct UnityEngine_Vector4_array *v29;
  Il2CppObject *v32;
  u64 v33[3];

  v32 = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMZiodin01_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPMZiodin01_tag, v33);
      if ((v33[0] & 1) != 0)
        v6 = v33[2];
      else
        v6 = v33 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = NewSpecific(UnityEngine_Vector4, 2u);
  for (i = 4; i != 16; ++i)
  {
    v12 = v3[3].klass;
    Param = effPCP_ThunderPolyGetParam(*(&v12->_1.image + i), 0);
    pos = Param->pos;
    v16 = Param;
    SDF_VU0__LOADVECTOR(pos->m_Items[1]);
    SDF_VU0__STOREVECTOR(v8 + 3);
    SDF_VU0__LOADVECTOR_B(v3[1]);
    SDF_VU0__ADDVECTOR();
    v19 = v16->pos;
    SDF_VU0__STOREVECTOR(&v19->m_Items[1]);
    v21 = v16->pos;
    SDF_VU0__LOADVECTOR(v21->m_Items[0]);
    SDF_VU0__STOREVECTOR(v8 + 2);
    SDF_VU0__ADDVECTOR();
    v24 = v16->pos;
    SDF_VU0__STOREVECTOR(v24->m_Items);
    v26 = v3[3].klass;
    v32 = *(&v26->_1.image + i);
    effPCP_ThunderPolyDraw(&v32);
    v28 = v16->pos;
    SDF_VU0__COPYVECTOR(v28->m_Items, *(v8 + 2), 0);
    v29 = v16->pos;
    SDF_VU0__COPYVECTOR(&v29->m_Items[1], *(v8 + 3), 0);
  }
}

// 0x1165a40
void effPCPMZiodin01Init(effPCPMZiodin01_tag **pPCPMZiodin01) {
  __int128 v2;
  effPCPMZiodin01_tag_o *v4;
  u64 i;
  struct effPCP_ThunderPolyParam_t_array *effPCP_MZiodin01_ThunderPoly_Param;
  s64 v10;
  effPCP_ThunderPolyParam_t_o *v12;
  u32 v13;
  struct UnityEngine_Vector4_array *pos;
  struct UnityEngine_Vector4_array *v16;
  struct UnityEngine_Vector4_array *v18;
  __int128 v20;
  f32 v21;
  struct UnityEngine_Vector4_array *v22;
  f32 v24;
  struct UnityEngine_Vector4_array *v27;
  struct UnityEngine_Vector4_array *v30;
  u32 *pThunderPoly;
  s64 *v33;
  s64 *v34;
  u32 *v36;
  Il2CppObject *hData;

  hData = 0;
  v4 = *pPCPMZiodin01;
  v4->pThunderPoly = NewSpecific(effPCP_ThunderPoly_t, 0xCu);
  LODWORD(v2) = 0;
  for (i = 0; i != 12; ++i)
  {
    v10 = DDS3EFFECT_RAND_I() & 1;
    v12 = effPCP_MZiodin01_ThunderPoly_Param->m_Items[v10];
    v12->refraction = (DDS3EFFECT_RAND_PM() * 5.0) + 20.0;
    v13 = DDS3EFFECT_RAND_I();
    pos = v12->pos;
    v12->split = v13 % 6 + 15;
    sub_854930(pos->m_Items, 0);
    v16 = v12->pos;
    sub_854930(v16->m_Items, 1u);
    v18 = v12->pos;
    v20 = v2;
    sub_854930(v18->m_Items, 2u);
    v21 = DDS3EFFECT_RAND_F() * 1.5708;
    DDS3EFFECT_RAND_FA(0.25);
    v22 = v12->pos;
    v24 = v21 + 0.3927;
    sub_854710(v22->m_Items, 0);
    sdfCos(v24);
    sub_854930(&v22->m_Items[1], 0);
    v27 = v12->pos;
    sub_854710(v27->m_Items, 1u);
    sdfSin(v24);
    sub_854930(&v27->m_Items[1], 1u);
    v30 = v12->pos;
    v2 = v20;
    sub_854930(&v30->m_Items[1], 2u);
    hData = v12;
    pThunderPoly = (*pPCPMZiodin01)->pThunderPoly;
    v33 = effPCP_ThunderPolyCreate(&hData, 0, 1, 0);
    v34 = v33;
    v36 = &pThunderPoly[2 * i];
    *(v36 + 4) = v34;
  }
}

// 0x11669a0
void effPCPMZiodin01SetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMZiodin01_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPMZiodin01_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[2].monitor) = abgr;
}

// 0x1166780
void effPCPMZiodin01SetPosition(void **hData, sdfVector4_t pPos) {
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
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != effPCPMZiodin01_tag)
    {
      sub_8FC2C0(*(v9 + 64), effPCPMZiodin01_tag, v13);
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

// 0x11668b0
void effPCPMZiodin01SetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMZiodin01_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPMZiodin01_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *(&(*hData)[2].klass + 1) = scale;
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
  u64 *v5;
  s64 *v6;
  Il2CppClass *v7;
  s64 *Interface;
  char *v9;
  s64 *v10;
  u64 *v11;
  effPCPMZiodin02_tag_o *v14;
  u64 v15[3];
  s32 pos;

  pos = bPos;
  v14 = 0;
  v5 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v5);
  v6 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(v6, byte);
    if (!Interface)
    {
      sub_8FC2C0(*(*v6 + 64), v7, v15);
      if ((v15[0] & 1) != 0)
        v9 = v15[2];
      else
        v9 = v15 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v5, Interface, &pos);
  v11 = Allocate(effPCPMZiodin02_tag);
  _ctor(v11, 0);
  v14 = v11;
  effPCPMZiodin02Init(&v14);
  return v11;
}

// 0x1167130
void effPCPMZiodin02Delete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppClass *v8;
  Il2CppClass *v10;
  Il2CppClass *v12;
  Il2CppClass *v14;
  Il2CppClass *v16;
  Il2CppClass *v18;
  Il2CppClass *v20;
  Il2CppClass *v22;
  Il2CppObject *data;
  u64 v25[3];

  data = 0;
  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMZiodin02_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPMZiodin02_tag, v25);
      if ((v25[0] & 1) != 0)
        v6 = v25[2];
      else
        v6 = v25 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = v3[3].klass;
  data = v8->_1.byval_arg.data;
  effPCP_ThunderPolyDelete(&data);
  v10 = v3[3].klass;
  data = *&v10->_1.byval_arg.bits;
  effPCP_ThunderPolyDelete(&data);
  v12 = v3[3].klass;
  data = v12->_1.this_arg.data;
  effPCP_ThunderPolyDelete(&data);
  v14 = v3[3].klass;
  data = *&v14->_1.this_arg.bits;
  effPCP_ThunderPolyDelete(&data);
  v16 = v3[3].klass;
  data = v16->_1.element_class;
  effPCP_ThunderPolyDelete(&data);
  v18 = v3[3].klass;
  data = v18->_1.castClass;
  effPCP_ThunderPolyDelete(&data);
  v20 = v3[3].klass;
  data = v20->_1.declaringType;
  effPCP_ThunderPolyDelete(&data);
  v22 = v3[3].klass;
  data = v22->_1.parent;
  effPCP_ThunderPolyDelete(&data);
}

// 0x1167450
void effPCPMZiodin02Draw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  s64 i;
  Il2CppClass *v12;
  effPCP_ThunderPolyParam_t_o *Param;
  struct UnityEngine_Vector4_array *pos;
  effPCP_ThunderPolyParam_t_o *v16;
  struct UnityEngine_Vector4_array *v19;
  struct UnityEngine_Vector4_array *v21;
  struct UnityEngine_Vector4_array *v24;
  Il2CppClass *v26;
  struct UnityEngine_Vector4_array *v28;
  struct UnityEngine_Vector4_array *v29;
  Il2CppObject *v32;
  u64 v33[3];

  v32 = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMZiodin02_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPMZiodin02_tag, v33);
      if ((v33[0] & 1) != 0)
        v6 = v33[2];
      else
        v6 = v33 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = NewSpecific(UnityEngine_Vector4, 2u);
  for (i = 4; i != 12; ++i)
  {
    v12 = v3[3].klass;
    Param = effPCP_ThunderPolyGetParam(*(&v12->_1.image + i), 0);
    pos = Param->pos;
    v16 = Param;
    SDF_VU0__LOADVECTOR(pos->m_Items[1]);
    SDF_VU0__STOREVECTOR(v8 + 3);
    SDF_VU0__LOADVECTOR_B(v3[1]);
    SDF_VU0__ADDVECTOR();
    v19 = v16->pos;
    SDF_VU0__STOREVECTOR(&v19->m_Items[1]);
    v21 = v16->pos;
    SDF_VU0__LOADVECTOR(v21->m_Items[0]);
    SDF_VU0__STOREVECTOR(v8 + 2);
    SDF_VU0__ADDVECTOR();
    v24 = v16->pos;
    SDF_VU0__STOREVECTOR(v24->m_Items);
    v26 = v3[3].klass;
    v32 = *(&v26->_1.image + i);
    effPCP_ThunderPolyDraw(&v32);
    v28 = v16->pos;
    SDF_VU0__COPYVECTOR(v28->m_Items, *(v8 + 2), 0);
    v29 = v16->pos;
    SDF_VU0__COPYVECTOR(&v29->m_Items[1], *(v8 + 3), 0);
  }
}

// 0x1166a90
void effPCPMZiodin02Init(effPCPMZiodin02_tag **pPCPMZiodin02) {
  effPCPMZiodin02_tag_o *v3;
  u64 i;
  struct effPCP_ThunderPolyParam_t_array *effPCP_MZiodin02_ThunderPoly_Param;
  s64 v10;
  Il2CppObject *v12;
  Il2CppClass *klass;
  s64 p_this_arg;
  Il2CppClass *v17;
  Il2CppClass *v20;
  Il2CppClass *v22;
  Il2CppClass *v24;
  Il2CppClass *v26;
  f32 v29;
  f32 v30;
  Il2CppClass *v31;
  Il2CppClass *v33;
  Il2CppClass *v35;
  s64 p_byval_arg;
  Il2CppClass *v38;
  Il2CppClass *v40;
  s64 v42;
  Il2CppClass *v43;
  u32 *pThunderPoly;
  s64 *v46;
  s64 *v47;
  u32 *v49;
  Il2CppObject *hData;

  hData = 0;
  v3 = *pPCPMZiodin02;
  v3->pThunderPoly = NewSpecific(effPCP_ThunderPoly_t, 8u);
  for (i = 0; i != 8; ++i)
  {
    v10 = DDS3EFFECT_RAND_I() & 1;
    v12 = effPCP_MZiodin02_ThunderPoly_Param->m_Items[v10];
    klass = v12[1].klass;
    if ((i & 1) != 0)
    {
      DDS3EFFECT_RAND_F();
      p_this_arg = &klass->_1.this_arg;
    }
    else
    {
      DDS3EFFECT_RAND_F();
      p_this_arg = &klass->_1.this_arg;
    }
    sub_854930(p_this_arg, 0);
    v17 = v12[1].klass;
    sub_854930(&v17->_1.this_arg, 1u);
    v20 = v12[1].klass;
    DDS3EFFECT_RAND_PM();
    sub_854930(&v20->_1.this_arg, 2u);
    v22 = v12[1].klass;
    sub_854930(&v22->_1.byval_arg, 0);
    v24 = v12[1].klass;
    sub_854930(&v24->_1.byval_arg, 1u);
    v26 = v12[1].klass;
    sub_854930(&v26->_1.byval_arg, 2u);
    v29 = DDS3EFFECT_RAND_PM();
    SetRotateMatrixX(v29 * 0.5236);
    v30 = DDS3EFFECT_RAND_PM();
    SetRotateMatrixZ_B(v30 * 0.5236);
    MultMatrixRevNoArg();
    v31 = v12[1].klass;
    SDF_VU0__LOADVECTOR(v31->_1.byval_arg);
    SDF_VU0__APPLYMATRIX_XYZ();
    v33 = v12[1].klass;
    SDF_VU0__STOREVECTOR(&v33->_1.byval_arg);
    v35 = v12[1].klass;
    p_byval_arg = &v35->_1.byval_arg;
    sub_854710(p_byval_arg, 0);
    v38 = v12[1].klass;
    sub_854710(&v38->_1.this_arg, 0);
    sub_854930(p_byval_arg, 0);
    v40 = v12[1].klass;
    v42 = &v40->_1.byval_arg;
    sub_854710(v42, 2u);
    v43 = v12[1].klass;
    sub_854710(&v43->_1.this_arg, 2u);
    sub_854930(v42, 2u);
    hData = v12;
    pThunderPoly = (*pPCPMZiodin02)->pThunderPoly;
    v46 = effPCP_ThunderPolyCreate(&hData, 0, 1, 0);
    v47 = v46;
    v49 = &pThunderPoly[2 * i];
    *(v49 + 4) = v47;
  }
}

// 0x1167a10
void effPCPMZiodin02SetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMZiodin02_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPMZiodin02_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[2].monitor) = abgr;
}

// 0x11677f0
void effPCPMZiodin02SetPosition(void **hData, sdfVector4_t pPos) {
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
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != effPCPMZiodin02_tag)
    {
      sub_8FC2C0(*(v9 + 64), effPCPMZiodin02_tag, v13);
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

// 0x1167920
void effPCPMZiodin02SetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMZiodin02_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPMZiodin02_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *(&(*hData)[2].klass + 1) = scale;
}

// 0x1185730
effPCPMakka_tag *effPCPMakkaCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v6;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  u64 *v11;
  u64 *v12;
  s32 monitor;
  u64 *v15;
  u64 v16;
  u64 v18;
  u64 v20;
  f32 v21;
  u64 v23;
  Il2CppClass *v24;
  s64 *v26;
  s64 *v27;
  u64 v31[3];

  v6 = *hData;
  if (*hData)
  {
    klass = v6->klass;
    if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMakka_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPMakka_tag, v31);
      if ((v31[0] & 1) != 0)
        v9 = v31[2];
      else
        v9 = v31 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  v11 = Allocate(effPCPMakka_tag);
  _ctor(v11, 0);
  v11[4] = 0;
  v11[5] = 0;
  v11[2] = 0;
  v11[3] = 0;
  v11[6] = NewSpecific(s32, 0xAu);
  v11[7] = NewSpecific(f32, 0xAu);
  v12 = NewSpecific(effPartHandle_t, 0xAu);
  v11[8] = v12;
  *(v11 + 11) = 0;
  *(v11 + 8) = v6[2].klass;
  monitor = v6[2].monitor;
  v15 = v12;
  *(v11 + 9) = -2139062144;
  *(v11 + 10) = monitor;
  if (monitor)
  {
    v16 = 0;
    do
    {
      v15[v16 + 4] = 0;
      v18 = v11[6];
      *(v18 + 4 * v16 + 32) = v16;
      v20 = v11[7];
      v21 = DDS3EFFECT_RAND_PM() * 0.87266;
      v23 = v20 + 4 * v16++;
      *(v23 + 32) = v21 + 3.1416;
      v15 = v11[8];
    }
    while (v16 < *(v11 + 10));
  }
  v24 = v6[4].klass;
  else if (!LODWORD(v24->_1.namespaze))
  {
    goto LABEL_27;
  }
  v26 = dds3EffectPartCopy(&v24->_1.byval_arg, bPos, 0);
  v27 = v26;
  v15[4] = v27;
  return v11;
}

// 0x11853f0
effPCPMakka_tag *effPCPMakkaCreat(void **hData, s32 bPos, bool tbldata) {
  u64 *v6;
  s64 *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  Il2CppObject *v12;
  Il2CppClass *v13;
  Il2CppClass *v15;
  u64 v16;
  Il2CppClass *klass;
  u32 *monitor;
  f32 v21;
  f32 *v23;
  s64 *v24;
  s64 *v25;
  u64 v29[3];
  s32 pos;

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(v7, byte);
    if (!Interface)
    {
      sub_8FC2C0(*(*v7 + 64), v8, v29);
      if ((v29[0] & 1) != 0)
        v10 = v29[2];
      else
        v10 = v29 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v6, Interface, &pos);
  v12 = Allocate(effPCPMakka_tag);
  _ctor(v12, 0);
  v12[2].klass = 0;
  v12[2].monitor = 0;
  v12[1].klass = 0;
  v12[1].monitor = 0;
  v12[3].klass = NewSpecific(s32, 0xAu);
  v12[3].monitor = NewSpecific(f32, 0xAu);
  v13 = NewSpecific(effPartHandle_t, 0xAu);
  v12[4].klass = v13;
  v12[2].klass = 0x808080803F800000LL;
  v12[2].monitor = &xmmword_0 + 10;
  v15 = v13;
  v16 = 0;
  do
  {
    *(&v15->_1.byval_arg.data + v16) = 0;
    klass = v12[3].klass;
    *(&klass->_1.byval_arg.data + v16) = v16;
    monitor = v12[3].monitor;
    v21 = DDS3EFFECT_RAND_PM() * 0.87266;
    v23 = &monitor[v16++];
    v23[8] = v21 + 3.1416;
    v15 = v12[4].klass;
  }
  while (v16 < LODWORD(v12[2].monitor));
  v24 = dds3EffectPCPDataPartCreate(v6, Interface, bPos, 0);
  v25 = v24;
  v15->_1.byval_arg.data = v25;
  return v12;
}

// 0x1185a70
void effPCPMakkaDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v8;
  s64 v9;
  Il2CppClass *v10;
  Il2CppClass *v12;
  u64 v14[3];

  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMakka_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPMakka_tag, v14);
      if ((v14[0] & 1) != 0)
        v6 = v14[2];
      else
        v6 = v14 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  if (LODWORD(v3[2].monitor))
  {
    v8 = 0;
    v9 = 32;
    do
    {
      v10 = v3[4].klass;
      if (*(&v10->_1.image + v9))
      {
        v12 = v3[4].klass;
        else if (v8 >= LODWORD(v12->_1.namespaze))
        {
LABEL_20:
        }
        dds3EffectPartDelete((v12 + v9), 0);
      }
      ++v8;
      v9 += 8;
    }
    while (v8 < LODWORD(v3[2].monitor));
  }
}

// 0x1185c20
void effPCPMakkaDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  u64 monitor_low;
  u64 v12;
  s32 v13;
  Il2CppClass *v14;
  s64 *v16;
  s64 *v17;
  Il2CppClass *v19;
  Il2CppClass *v22;
  Il2CppClass *v24;
  Il2CppClass *v27;
  Il2CppClass *v29;
  Il2CppObject *Handle;
  Il2CppClass *v32;
  s64 v33;
  char *v34;
  s64 *v35;
  f32 *monitor;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *Child;
  s64 *Enumerator;
  UnityEngine_Transform_o *v44;
  UnityEngine_Transform_c *v45;
  s64 v46;
  char *v47;
  s64 *v48;
  s32 v49;
  s64 *Interface;
  Il2CppObject *hDataa;
  UnityEngine_Vector4_o v52;
  UnityEngine_Vector4_o v53;
  dds3ModelHandle_t_o *aHandle;
  u64 v55[3];
  u64 v56[2];
  char *v57;
  UnityEngine_Vector3_o v58;
  UnityEngine_Vector3_o one;

  *&v53.z = 0;
  aHandle = 0;
  *&v52.z = 0;
  *&v53.x = 0;
  hDataa = 0;
  *&v52.x = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMakka_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPMakka_tag, v56);
      if ((v56[0] & 1) != 0)
        v6 = v57;
      else
        v6 = v56 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v8);
  *&v53.z = 0;
  aHandle = v8;
  *&v53.x = 0;
  sub_854690(&v52.x, 0.0, 1.0, 0.0, 0.0);
  effBTLSkillGetTargetFormation(0);
  monitor_low = LODWORD(v3[2].monitor);
  if (monitor_low)
  {
    v12 = 0;
    v13 = -1;
    while (1)
    {
      v22 = v3[3].klass;
      if (*(&v22->_1.byval_arg.data + v12) != HIDWORD(v3[2].monitor))
        goto LABEL_40;
      v24 = v3[4].klass;
      if (!*(&v24->_1.byval_arg.data + v12))
      {
        v14 = v3[4].klass;
        else if (!LODWORD(v14->_1.namespaze))
        {
          goto LABEL_18;
        }
        v16 = dds3EffectPartCopy(&v14->_1.byval_arg, 0, 0);
        v17 = v16;
        *(&v14->_1.byval_arg.data + v12) = v17;
        v19 = v3[4].klass;
        if (v12 >= LODWORD(v19->_1.namespaze))
        {
LABEL_41:
        }
      }
      else
      {
LABEL_40:
        v19 = v3[4].klass;
        if (v12 >= LODWORD(v19->_1.namespaze))
          goto LABEL_41;
      }
      if (!*(&v19->_1.byval_arg.data + v12))
        goto LABEL_90;
      v27 = v3[3].klass;
      if (*(&v27->_1.byval_arg.data + v12) + 50 < SHIDWORD(v3[2].monitor))
        goto LABEL_90;
      v29 = v3[4].klass;
      else if (v12 >= LODWORD(v29->_1.namespaze))
      {
LABEL_49:
      }
      Handle = dds3EffectPartGetHandle(&v29->_1.byval_arg.data + v12);
      if (Handle)
      {
        v32 = Handle->klass;
        if (Handle->klass->_2.typeHierarchyDepth < v33
          || v32->_2.typeHierarchy[v33 - 1] != dds3ModelHandle_t)
        {
          sub_8FC2C0(v32->_1.element_class, dds3ModelHandle_t, v55);
          if ((v55[0] & 1) != 0)
            v34 = v55[2];
          else
            v34 = v55 + 1;
          v35 = sub_8C4940(v34);
        }
      }
      aHandle = Handle;
      monitor = v3[3].monitor;
      FromEuler(0.0, monitor[v12 + 8], 0.0);
      else if (effBTLSkillCheckRun())
      {
LABEL_62:
        if ((effBTLSkillGetTargetFormation(0)->stat & 0x200) != 0)
        {
          SDF_VU0__LOADVECTOR_B(v52);
          Mult();
        }
      }
      mdlSetRotate(&aHandle);
      sub_854930(&v53, 0);
      sub_854710(&v53, 0);
      sub_854930(&v53, 1u);
      sub_854930(&v53, 2u);
      sub_854930(&v53, 3u);
      SDF_VU0__LOADVECTOR(v53);
      mdlSetScale(&aHandle);
      mdlSetColor(&aHandle, HIDWORD(v3[2].klass), 0);
      SDF_VU0__LOADVECTOR(v3[1]);
      mdlSetPosition(&aHandle);
      hDataa = aHandle;
      dds3EffectPartModelDraw(&hDataa);
      transform = get_transform(aHandle->modelRoot->modelobj, 0);
      Child = GetChild(transform, 0);
      one = get_one();
      v58 = op_Division(one, *&v3[2].klass);
      set_localScale(Child, v58);
      Enumerator = GetEnumerator(Child);
      while ((sub_69BB0(0, System_Collections_IEnumerator, Enumerator) & 1) != 0)
      {
        v44 = sub_69A60(1u, System_Collections_IEnumerator, Enumerator);
        if (v44)
        {
          v45 = v44->klass;
          if (v44->klass->_2.typeHierarchyDepth < v46
            || v45->_2.typeHierarchy[v46 - 1] != UnityEngine_Transform)
          {
            sub_8FC2C0(v45->_1.element_class, UnityEngine_Transform, v56);
            if ((v56[0] & 1) != 0)
              v47 = v57;
            else
              v47 = v56 + 1;
            v48 = sub_8C4940(v47);
          }
        }
        set_localScale(v44, v58);
      }
      v49 = v13 + 1;
      Interface = QueryInterface(Enumerator, System_IDisposable);
      if (Interface)
        sub_22F10(0, System_IDisposable, Interface);
      if (v49 == -1)
      {
        v13 = -1;
        if (++v12 >= monitor_low)
          break;
      }
      else
      {
        v13 = v49 + ~(v49 >> 31);
LABEL_90:
        if (++v12 >= monitor_low)
          break;
      }
    }
  }
  ++HIDWORD(v3[2].monitor);
}

// 0x1186570
void effPCPMakkaSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMakka_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPMakka_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[2].klass) = abgr;
}

// 0x1186440
void effPCPMakkaSetPosition(void **hData, sdfVector4_t pPos) {
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
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != effPCPMakka_tag)
    {
      sub_8FC2C0(*(v9 + 64), effPCPMakka_tag, v13);
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

// 0x1186660
void effPCPMakkaSetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMakka_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPMakka_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *&(*hData)[2].klass = scale;
}

// 0x116fff0
effPCPMegidora01_tag *effPCPMegidora01Copy(void **hData, s32 bPos, bool tbldata) {
  u64 *v4;
  Il2CppObject *hDataa;

  v4 = Allocate(effPCPMegidora01_tag);
  _ctor(v4, 0);
LABEL_7:
  hDataa = 0;
  hDataa = effPCP_Megidora01_ThunderSpherePoly_Param;
  v4[6] = effPCPThunderSpherePolyCreate(&hDataa, 0, 0);
  *(v4 + 10) = 0;
  return v4;
}

// 0x116fd20
effPCPMegidora01_tag *effPCPMegidora01Create(void **hData, s32 bPos, bool tbldata) {
  u64 *v5;
  s64 *v6;
  Il2CppClass *v7;
  s64 *Interface;
  char *v9;
  s64 *v10;
  u64 *v11;
  Il2CppObject *hDataa[3];
  s32 pos;

  pos = bPos;
  v5 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v5);
  v6 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(v6, byte);
    if (!Interface)
    {
      sub_8FC2C0(*(*v6 + 64), v7, hDataa);
      if ((hDataa[0] & 1) != 0)
        v9 = hDataa[2];
      else
        v9 = hDataa + 1;
      v10 = sub_8C4940(v9);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v5, Interface, &pos);
  v11 = Allocate(effPCPMegidora01_tag);
  _ctor(v11, 0);
LABEL_14:
  hDataa[0] = 0;
  hDataa[0] = effPCP_Megidora01_ThunderSpherePoly_Param;
  v11[6] = effPCPThunderSpherePolyCreate(hDataa, 0, 0);
  *(v11 + 10) = 0;
  return v11;
}

// 0x116fef0
void effPCPMegidora01Delete(void **hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  Il2CppClass *v7;
  u64 v8[3];

  v7 = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMegidora01_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPMegidora01_tag, v8);
    if ((v8[0] & 1) != 0)
      v5 = v8[2];
    else
      v5 = v8 + 1;
    v6 = sub_8C4940(v5);
  }
  v7 = (*hData)[3].klass;
  effPCPThunderSpherePolyDelete(&v7);
}

// 0x11700f0
void effPCPMegidora01Draw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u32 monitor;
  effPCPThunderSpherePolyParam_t_o *Param;
  f32 v10;
  u32 v11;
  f32 v12;
  f32 v13;
  f32 v14;
  u32 v15;
  bool v16;
  u32 v17;
  f32 v18;
  u32 klass_high;
  Il2CppClass *v20;
  u64 v21[3];

  v20 = 0;
  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMegidora01_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPMegidora01_tag, v21);
      if ((v21[0] & 1) != 0)
        v6 = v21[2];
      else
        v6 = v21 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  monitor = v3[2].monitor;
  if (monitor <= 0x1E)
  {
    Param = effPCPThunderSpherePolyGetParam(v3[3].klass);
    v10 = 100.0;
    v11 = v3[2].monitor;
    v12 = 30.0;
LABEL_15:
    v13 = v11;
    v14 = ((v13 / v12) * 150.0) + v10;
    Param->width = v14;
    Param->height = v14;
    goto LABEL_16;
  }
  if (monitor < 0x2D)
  {
LABEL_19:
    klass_high = HIDWORD(v3[2].klass);
    goto LABEL_20;
  }
  if (monitor <= 0x3C)
  {
    Param = effPCPThunderSpherePolyGetParam(v3[3].klass);
    v12 = 15.0;
    v10 = 250.0;
    v11 = LODWORD(v3[2].monitor) - 45;
    goto LABEL_15;
  }
LABEL_16:
  v15 = v3[2].monitor;
  v16 = v15 >= 0x2D;
  v17 = v15 - 45;
  if (!v16)
    goto LABEL_19;
  v18 = v17;
  klass_high = effColorBlend(HIDWORD(v3[2].klass), 0, v18 / 35.0, 0);
LABEL_20:
  v20 = v3[3].klass;
  effPCPThunderSpherePolySetColor(&v20, klass_high);
  effPCPThunderSpherePolySetPosition(&v20, v3[1]);
  effPCPThunderSpherePolyDraw(&v20);
  ++LODWORD(v3[2].monitor);
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
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMegidora01_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPMegidora01_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[2].klass) = abgr;
}

// 0x11702e0
void effPCPMegidora01SetPosition(void **hData, sdfVector4_t pPos) {
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
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != effPCPMegidora01_tag)
    {
      sub_8FC2C0(*(v9 + 64), effPCPMegidora01_tag, v13);
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

// 0x1170410
void effPCPMegidora01SetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMegidora01_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPMegidora01_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *&(*hData)[2].klass = scale;
}

// 0x1170960
effPCPMegidoraon01_tag *effPCPMegidoraon01Copy(void **hData, s32 bPos, bool tbldata) {
  u64 *v4;
  Il2CppObject *hDataa;

  v4 = Allocate(effPCPMegidoraon01_tag);
  _ctor(v4, 0);
LABEL_7:
  hDataa = 0;
  hDataa = effPCP_Megidoraon01_ThunderSpherePoly_Param;
  v4[6] = effPCPThunderSpherePolyCreate(&hDataa, 0, 0);
  *(v4 + 10) = 0;
  return v4;
}

// 0x1170690
effPCPMegidoraon01_tag *effPCPMegidoraon01Create(void **hData, s32 bPos, bool tbldata) {
  u64 *v5;
  s64 *v6;
  Il2CppClass *v7;
  s64 *Interface;
  char *v9;
  s64 *v10;
  u64 *v11;
  Il2CppObject *hDataa[3];
  s32 pos;

  pos = bPos;
  v5 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v5);
  v6 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(v6, byte);
    if (!Interface)
    {
      sub_8FC2C0(*(*v6 + 64), v7, hDataa);
      if ((hDataa[0] & 1) != 0)
        v9 = hDataa[2];
      else
        v9 = hDataa + 1;
      v10 = sub_8C4940(v9);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v5, Interface, &pos);
  v11 = Allocate(effPCPMegidoraon01_tag);
  _ctor(v11, 0);
LABEL_14:
  hDataa[0] = 0;
  hDataa[0] = effPCP_Megidoraon01_ThunderSpherePoly_Param;
  v11[6] = effPCPThunderSpherePolyCreate(hDataa, 0, 0);
  *(v11 + 10) = 0;
  return v11;
}

// 0x1170860
void effPCPMegidoraon01Delete(void **hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  Il2CppClass *v7;
  u64 v8[3];

  v7 = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMegidoraon01_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPMegidoraon01_tag, v8);
    if ((v8[0] & 1) != 0)
      v5 = v8[2];
    else
      v5 = v8 + 1;
    v6 = sub_8C4940(v5);
  }
  v7 = (*hData)[3].klass;
  effPCPThunderSpherePolyDelete(&v7);
}

// 0x1170a60
void effPCPMegidoraon01Draw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u32 monitor;
  effPCPThunderSpherePolyParam_t_o *Param;
  f32 v10;
  f32 v11;
  f32 v12;
  u32 v13;
  f32 v14;
  f32 v15;
  u32 v16;
  bool v17;
  u32 v18;
  f32 v19;
  u32 klass_high;
  Il2CppClass *v21;
  u64 v22[3];

  v21 = 0;
  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMegidoraon01_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPMegidoraon01_tag, v22);
      if ((v22[0] & 1) != 0)
        v6 = v22[2];
      else
        v6 = v22 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  monitor = v3[2].monitor;
  if (monitor <= 0x2D)
  {
    Param = effPCPThunderSpherePolyGetParam(v3[3].klass);
    v10 = 200.0;
    v11 = 950.0;
    v12 = 45.0;
    v13 = v3[2].monitor;
LABEL_15:
    v14 = v13;
    v15 = ((v14 / v12) * v11) + v10;
    Param->width = v15;
    Param->height = v15;
    goto LABEL_16;
  }
  if (monitor < 0x3C)
  {
LABEL_19:
    klass_high = HIDWORD(v3[2].klass);
    goto LABEL_20;
  }
  if (monitor <= 0x4B)
  {
    Param = effPCPThunderSpherePolyGetParam(v3[3].klass);
    v10 = 1050.0;
    v12 = 15.0;
    v11 = 150.0;
    v13 = LODWORD(v3[2].monitor) - 60;
    goto LABEL_15;
  }
LABEL_16:
  v16 = v3[2].monitor;
  v17 = v16 >= 0x3C;
  v18 = v16 - 60;
  if (!v17)
    goto LABEL_19;
  v19 = v18;
  klass_high = effColorBlend(HIDWORD(v3[2].klass), 0, v19 / 15.0, 0);
LABEL_20:
  v21 = v3[3].klass;
  effPCPThunderSpherePolySetColor(&v21, klass_high);
  effPCPThunderSpherePolySetPosition(&v21, v3[1]);
  effPCPThunderSpherePolyDraw(&v21);
  ++LODWORD(v3[2].monitor);
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
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMegidoraon01_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPMegidoraon01_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[2].klass) = abgr;
}

// 0x1170c50
void effPCPMegidoraon01SetPosition(void **hData, sdfVector4_t pPos) {
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
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != effPCPMegidoraon01_tag)
    {
      sub_8FC2C0(*(v9 + 64), effPCPMegidoraon01_tag, v13);
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

// 0x1170d80
void effPCPMegidoraon01SetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMegidoraon01_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPMegidoraon01_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *&(*hData)[2].klass = scale;
}

// 0x115f910
effPCPMudo_tag *effPCPMudoCopy(void **hData, s32 bPos, bool tbldata) {
  effPartHandle_t_o **v6;
  effPartHandle_t_o *v7;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  u64 *v11;
  u64 v15[3];

  v6 = *hData;
  if (*hData)
  {
    v7 = *v6;
    if (LOBYTE((*v6)[9].klass) < typeHierarchyDepth
      || *(v7[6].monitor + typeHierarchyDepth - 1) != effPCPMudo_tag)
    {
      sub_8FC2C0(v7[2].klass, effPCPMudo_tag, v15);
      if ((v15[0] & 1) != 0)
        v9 = v15[2];
      else
        v9 = v15 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  v11 = Allocate(effPCPMudo_tag);
  _ctor(v11, 0);
  Clear(v11, 0);
  v11[13] = 0;
  v11[12] = dds3EffectPartCopy(v6 + 12, bPos, 0);
  v11[11] = dds3EffectPartCopy(v6 + 11, bPos, 0);
  v11[9] = 0;
  *(v11 + 20) = -2139062144;
  sub_854930((v11 + 3), 0);
  sub_854930((v11 + 3), 1u);
  sub_854930((v11 + 3), 2u);
  v11[8] = 0x3F80000080808080LL;
  return v11;
}

// 0x115f5a0
effPCPMudo_tag *effPCPMudoCreate(void **hData, s32 bPos, bool tbldata) {
  u64 *v6;
  s64 *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  u64 *v12;
  s32 pos;
  u64 v17[3];

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(v7, byte);
    if (!Interface)
    {
      sub_8FC2C0(*(*v7 + 64), v8, v17);
      if ((v17[0] & 1) != 0)
        v10 = v17[2];
      else
        v10 = v17 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v6, Interface, &pos);
  v12 = Allocate(effPCPMudo_tag);
  _ctor(v12, 0);
  Clear(v12, 0);
  v12[13] = 0;
  v12[12] = dds3EffectPCPDataPartCreate(v6, Interface, bPos, 0);
  v12[11] = dds3EffectPCPDataPartCreate(v6, Interface, bPos, 1u);
  v12[9] = 0;
  *(v12 + 20) = -2139062144;
  sub_854930((v12 + 3), 0);
  sub_854930((v12 + 3), 1u);
  sub_854930((v12 + 3), 2u);
  v12[8] = 0x3F80000080808080LL;
  return v12;
}

// 0x115f7e0
void effPCPMudoDelete(void **hData) {
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
      || *(v4[6].monitor + typeHierarchyDepth - 1) != effPCPMudo_tag)
    {
      sub_8FC2C0(v4[2].klass, effPCPMudo_tag, v8);
      if ((v8[0] & 1) != 0)
        v6 = v8[2];
      else
        v6 = v8 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  dds3EffectPartDelete(v3 + 12);
  dds3EffectPartDelete(v3 + 11);
}

// 0x115fb10
void effPCPMudoDraw(void **hData) {
  f64 v2;
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 *v9;
  u64 *v10;
  u32 v11;
  u32 monitor_high;
  u32 v13;
  u32 v15;
  Il2CppObject *Handle;
  Il2CppObject *v17;
  Il2CppClass *v18;
  s64 v19;
  char *v20;
  s64 *v21;
  f32 v22;
  s64 monitor_low;
  u64 v25;
  struct System_UInt16_array *effPCPMudoInterval;
  sdfModelRootNode_t_o *v29;
  u64 v30;
  Il2CppClass *v31;
  s64 v33;
  u32 *monitor;
  s64 v38;
  u32 v39;
  Il2CppClass *v41;
  s64 v43;
  u32 *v45;
  s64 v47;
  s64 v49;
  u64 v51;
  s64 v52;
  u64 v53;
  s64 v54;
  u64 v56;
  struct System_UInt16_array *v57;
  u64 *v59;
  s64 v61;
  s64 v63;
  u64 *v64;
  s64 v66;
  Il2CppClass *v68;
  f32 v69;
  f32 v71;
  s64 v73;
  struct System_Single_array *effPCPMudoScale;
  f32 v75;
  Il2CppClass *v78;
  s64 v80;
  s64 v82;
  Il2CppClass *v83;
  f32 v84;
  s64 v86;
  f32 v88;
  Il2CppClass *v89;
  s64 v91;
  u64 *v93;
  s64 v95;
  u64 *v97;
  s64 v99;
  u32 v101;
  Il2CppObject *v102;
  Il2CppObject *hDataa;
  UnityEngine_Vector4_o p;
  u64 v105[2];
  char *v106;
  billHandle_t_o *hBillboard;

  hBillboard = 0;
  *&p.x = 0;
  *&p.z = 0;
  v102 = 0;
  hDataa = 0;
  v4 = *hData;
  if (*hData)
  {
    klass = v4->klass;
    if (v4->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMudo_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPMudo_tag, v105);
      if ((v105[0] & 1) != 0)
        v7 = v106;
      else
        v7 = v105 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  v9 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v9);
  v10 = Allocate(billHandle_t);
  billHandle_t___ctor(v10);
  hBillboard = v10;
  *&p.x = 0;
  *&p.z = 0;
  monitor_high = HIDWORD(v4[4].monitor);
  v11 = v4[5].klass;
  if (monitor_high >= 0x33 && v11 >> 27)
  {
    v11 -= 0x8000000;
    LODWORD(v4[5].klass) = v11;
  }
  v13 = v4[4].klass;
  HIDWORD(v4[4].monitor) = monitor_high + 1;
  hBillboard = 0;
  v15 = effColorMultiply(v13, v11);
  Handle = dds3EffectPartGetHandle(&v4[5].monitor);
  v17 = Handle;
  if (Handle)
  {
    v18 = Handle->klass;
    if (Handle->klass->_2.typeHierarchyDepth < v19
      || v18->_2.typeHierarchy[v19 - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(v18->_1.element_class, dds3ModelHandle_t, v105);
      if ((v105[0] & 1) != 0)
        v20 = v106;
      else
        v20 = v105 + 1;
      v21 = sub_8C4940(v20);
    }
  }
  v22 = *(&v4[4].klass + 1) * 1.5;
  dds3EffectPartSetScale(&v4[5].monitor, v22);
  dds3EffectPartSetPosition(&v4[5].monitor, *(v4 + 24), 0);
  hDataa = v17;
  dds3EffectPartModelDraw(&hDataa);
  monitor_low = LODWORD(v4[4].monitor);
  if (monitor_low <= 0x18)
  {
    v101 = v15;
    v25 = 0;
    do
    {
      while (1)
      {
        if (!(monitor_low % effPCPMudoInterval->m_Items[v25]))
          break;
        if (++v25 == 7)
          goto LABEL_56;
      }
      v29 = v17[4].klass;
      v30 = v25 + 1;
      sdfModelGetMarkPosUnity(v29, v25 + 1);
      SDF_VU0__STOREVECTOR(&p);
      v31 = v4[1].klass;
      v33 = *(&v31->_1.byval_arg.data + monitor_low);
      SDF_VU0__COPYVECTOR((v33 + 16 * v25 + 32), p, 0);
      monitor = v4[2].monitor;
      v38 = *&monitor[2 * monitor_low + 8];
      v39 = DDS3EFFECT_RAND_I();
      *(v38 + 4 * v25 + 32) = v39;
      v41 = v4[3].klass;
      v43 = *(&v41->_1.byval_arg.data + monitor_low);
      *(v43 + 4 * v25 + 32) = 0;
      v45 = v4[3].monitor;
      v47 = *&v45[2 * monitor_low + 8];
      v49 = v47 + 4 * v25++;
      *(v49 + 32) = 0;
    }
    while (v30 != 7);
LABEL_56:
    v15 = v101;
    LODWORD(monitor_low) = LODWORD(v4[4].monitor) + 1;
    LODWORD(v4[4].monitor) = monitor_low;
  }
  dds3BillboardSetRGBA(&hBillboard, v15);
  if (monitor_low)
  {
    v51 = 0;
    v52 = monitor_low;
    do
    {
      v53 = 0;
      v54 = 16;
      do
      {
        while (1)
        {
          v56 = v54 - 16;
          v57 = effPCPMudoInterval;
          if (!(v51 % *(&v57->obj.klass + v54)))
            break;
          v53 += 4LL;
          ++v54;
          if (v53 == 28)
            goto LABEL_112;
        }
        v59 = v4[3].monitor;
        v61 = v59[v51 + 4];
        v63 = v61 + v53;
        v64 = v4[3].monitor;
        LODWORD(v2) = *(v63 + 32);
        v2 = *&v2;
        v66 = v64[v51 + 4];
        ++*(v66 + v53 + 32);
        v68 = v4[3].klass;
        v69 = v2;
        v71 = v69 / 12.0;
        v73 = *(&v68->_1.byval_arg.data + v51);
        v75 = fminf(v71, 1.0);
        *(v73 + v53 + 32) = v22 * (v75 * effPCPMudoScale->m_Items[v53 / 4]);
        v78 = v4[3].klass;
        v80 = *(&v78->_1.byval_arg.data + v51);
        v82 = v80 + v53;
        v83 = v4[3].klass;
        v84 = *(v82 + 32);
        v86 = *(&v83->_1.byval_arg.data + v51);
        v88 = *(v86 + v53 + 32);
        dds3BillboardSetScale(&hBillboard, v84, v88);
        v89 = v4[1].klass;
        v91 = *(&v89->_1.byval_arg.data + v51);
        dds3BillboardSetPosition(&hBillboard, *(v91 + 4 * v53 + 32), 0);
        v102 = hBillboard;
        dds3BillboardDraw(&v102);
        v93 = v4[2].monitor;
        v95 = v93[v51 + 4];
        dds3BillboardSetAnimKey(&hBillboard, *(v95 + v53 + 32), 0);
        v97 = v4[2].monitor;
        v99 = v97[v51 + 4];
        ++*(v99 + v53 + 32);
        v53 += 4LL;
        ++v54;
      }
      while (v53 != 28);
LABEL_112:
      ++v51;
    }
    while (v51 != v52);
  }
}

// 0x115f580
void effPCPMudoPartInit(effPCPMudo_tag **pPCPMudo) {
  (*pPCPMudo)->frame = 0;
  (*pPCPMudo)->fade_frame = 0;
  (*pPCPMudo)->fade_abgr = -2139062144;
}

// 0x1160640
void effPCPMudoSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMudo_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPMudo_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[4].klass) = abgr;
}

// 0x1160420
void effPCPMudoSetPosition(void **hData, sdfVector4_t pPos) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  Il2CppObject *v8;
  Il2CppClass *klass;
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
    klass = v8->klass;
    if (v8->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMudo_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPMudo_tag, v13);
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
  SDF_VU0__COPYVECTOR(&v8[1].monitor, v14);
}

// 0x1160550
void effPCPMudoSetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMudo_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPMudo_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *(&(*hData)[4].klass + 1) = scale;
}

// 0x116c4b0
effPCPMultiBlurExp2_tag *effPCPMultiBlurExp2Copy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  effPCPMultiBlurExp2Param_t_o *v10;
  u64 v13[3];

  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMultiBlurExp2_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPMultiBlurExp2_tag, v13);
      if ((v13[0] & 1) != 0)
        v8 = v13[2];
      else
        v8 = v13 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = Allocate(effPCPMultiBlurExp2Param_t);
  effPCPMultiBlurExp2Param_t___ctor(v10);
  v10->type = v5[2].klass;
  v10->life = v5[3].klass;
  v10->fade_in = HIDWORD(v5[3].klass);
  v10->fade_out = v5[3].monitor;
  v10->area_s = HIDWORD(v5[3].monitor);
  v10->area_e = v5[4].klass;
  v10->MultiBlur = *(v5[4].monitor + 2);
  return effPCPMultiBlurExp2Create(v10);
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
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v11[3];

  v5 = *pData;
  else if (!v5)
  {
    return effPCPMultiBlurExp2Create(v5, *&bPos);
  }
  klass = v5->klass;
  if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMultiBlurExp2Param_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPMultiBlurExp2Param_t, v11);
    if ((v11[0] & 1) != 0)
      v8 = v11[2];
    else
      v8 = v11 + 1;
    v9 = sub_8C4940(v8);
  }
  return effPCPMultiBlurExp2Create(v5, *&bPos);
}

// 0x116c270
effPCPMultiBlurExp2_tag *effPCPMultiBlurExp2CreatePCF(void **hData, s32 bPos, bool tbldata) {
  dds3EffectPCPData_t_o *v6;
  Il2CppObject *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  struct dds3EffectPCPData_Part_t_array *pcpData;
  Il2CppObject *v14;
  u32 offset;
  effPCPMultiBlurExp2Param_t_c *v17;
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
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 11);
  else if (!DataUnityOffSet)
  {
    return effPCPMultiBlurExp2Create(DataUnityOffSet, v17);
  }
  klass = DataUnityOffSet->klass;
  if (DataUnityOffSet->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMultiBlurExp2Param_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPMultiBlurExp2Param_t, v24);
    if ((v24[0] & 1) != 0)
      v21 = v25;
    else
      v21 = v24 + 1;
    v22 = sub_8C4940(v21);
  }
  return effPCPMultiBlurExp2Create(DataUnityOffSet, v17);
}

// 0x116c620
void effPCPMultiBlurExp2Delete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3Effect_PartialMultiBlur_t_o **p_monitor;
  u64 v9[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMultiBlurExp2_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPMultiBlurExp2_tag, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  p_monitor = &v3[4].monitor;
  dds3EffectPartialMultiBlurDelete(p_monitor);
}

// 0x116c740
void effPCPMultiBlurExp2Draw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  dds3Effect_PartialMultiBlur_t_o *monitor;
  s32 monitor_high;
  s32 v11;
  s32 v12;
  s32 v13;
  s32 klass_high;
  struct System_Int32_array *pm;
  struct System_Int32_array *v17;
  s32 v19;
  struct System_Int32_array *v20;
  f32 v21;
  f32 v23;
  f32 v25;
  f32 v26;
  dds3Effect_PartialMultiBlur_t_o *v27;
  f32 v28;
  f32 v29;
  u32 v30;
  struct dds3Effect_Blur_t_o *Blur;
  s32 ID;
  UnityEngine_Vector4_o v35;
  dds3Effect_PartialMultiBlur_t_o *hPartialMultiBlur;
  u64 v37[3];

  *&v35.z = 0;
  hPartialMultiBlur = 0;
  *&v35.x = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMultiBlurExp2_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPMultiBlurExp2_tag, v37);
      if ((v37[0] & 1) != 0)
        v6 = v37[2];
      else
        v6 = v37 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = Allocate(dds3Effect_PartialMultiBlur_t);
  dds3Effect_PartialMultiBlur_t___ctor(v8);
  dds3Effect_PartialMultiBlur_t__Clear(v8);
  *&v35.x = 0;
  *&v35.z = 0;
  monitor = v3[4].monitor;
  hPartialMultiBlur = monitor;
  monitor_high = HIDWORD(v3[2].monitor);
  v11 = v3[3].klass;
  v12 = v11 - monitor_high;
  if (v11 >= monitor_high)
  {
    klass_high = HIDWORD(v3[3].klass);
    v13 = v3[3].monitor;
    if (LOBYTE(v3[2].klass))
    {
      pm = monitor->param->Blur->center->pm;
      pm->m_Items[0] = 0;
      v17 = monitor->param->Blur->center->pm;
      v19 = 0;
    }
    else
    {
      SDF_VU0__LOADVECTOR(v3[1]);
      effScreenOffset();
      SDF_VU0__STOREVECTOR(&v35);
      v20 = hPartialMultiBlur->param->Blur->center->pm;
      sub_854710(&v35, 0);
      v20->m_Items[0] = v21;
      v17 = hPartialMultiBlur->param->Blur->center->pm;
      sub_854710(&v35, 1u);
      v19 = -v23;
    }
    v17->m_Items[1] = v19;
    v25 = monitor_high;
    v26 = v11;
    v27 = hPartialMultiBlur;
    hPartialMultiBlur->param->area = HIDWORD(v3[3].monitor)
                                                 + ((monitor_high * (LODWORD(v3[4].klass) - HIDWORD(v3[3].monitor)))
                                                  / v26);
    if (monitor_high < klass_high && klass_high)
    {
      v28 = klass_high;
    }
    else
    {
      v29 = 1.0;
      if (v12 > v13 || !v13)
      {
LABEL_28:
        v30 = effColorBlend(HIDWORD(v3[2].klass) & 0xFFFFFF, HIDWORD(v3[2].klass), v29, 0);
        Blur = v27->param->Blur;
        Blur->abgr = effColorMultiply(v30, v3[2].monitor);
        else if (effBTLSkillCheckRun())
        {
          goto LABEL_31;
        }
        ID = 0;
LABEL_37:
        dds3EffectPartialMultiBlurDraw(&hPartialMultiBlur, 0, ID);
        ++HIDWORD(v3[2].monitor);
        return;
      }
      v25 = v12;
      v28 = v13;
    }
    v29 = v25 / v28;
    goto LABEL_28;
  }
}

// 0x116cd00
void effPCPMultiBlurExp2SetArea(void **hData, f32 area) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMultiBlurExp2_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPMultiBlurExp2_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *(&(*hData)[4].klass + 1) = area;
}

// 0x116cc10
void effPCPMultiBlurExp2SetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMultiBlurExp2_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPMultiBlurExp2_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[2].klass) = abgr;
}

// 0x116cae0
void effPCPMultiBlurExp2SetPosition(void **hData, sdfVector4_t pPos) {
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
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != effPCPMultiBlurExp2_tag)
    {
      sub_8FC2C0(*(v9 + 64), effPCPMultiBlurExp2_tag, v13);
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

// 0x116aa10
effPCPMultiBlurExp_tag *effPCPMultiBlurExpCreate(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 *v10;
  dds3Effect_PartialMultiBlurParam_t_o *monitor;
  s32 v13;
  u64 *v14;
  u32 *v15;
  s32 v16;
  u32 *v17;
  u64 v18;
  s32 v20;
  u64 v25[3];

  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMultiBlurExpParam_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPMultiBlurExpParam_t, v25);
      if ((v25[0] & 1) != 0)
        v8 = v25[2];
      else
        v8 = v25 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = Allocate(effPCPMultiBlurExp_tag);
  _ctor(v10, 0);
  monitor = v5[2].monitor;
  v10[9] = dds3EffectPartialMultiBlurCreate(monitor);
  v13 = *(*(v5[2].monitor + 3) + 16LL);
  *(v10 + 8) = -2139062144;
  *(v10 + 9) = v13;
  sub_854930((v10 + 2), 0);
  sub_854930((v10 + 2), 1u);
  sub_854930((v10 + 2), 2u);
  v10[5] = 0;
  *(v10 + 12) = v5[1].klass;
  v14 = NewSpecific(uint, 2u);
  v10[7] = v14;
  v15 = v5[1].monitor;
  v16 = v15[8];
  *(v14 + 8) = v16;
  v17 = v5[1].monitor;
  v18 = v10[7];
  v20 = v17[9];
  *(v18 + 36) = v20;
  *(v10 + 16) = v5[2].klass;
  *(v10 + 17) = HIDWORD(v5[2].klass);
  return v10;
}

// 0x116ac80
void effPCPMultiBlurExpDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3Effect_PartialMultiBlur_t_o **p_monitor;
  u64 v9[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMultiBlurExp_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPMultiBlurExp_tag, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  p_monitor = &v3[4].monitor;
  dds3EffectPartialMultiBlurDelete(p_monitor);
}

// 0x116ada0
void effPCPMultiBlurExpDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  dds3Effect_PartialMultiBlur_t_o *v9;
  struct System_Int32_array *pm;
  f32 v11;
  struct System_Int32_array *v13;
  f32 v14;
  struct dds3Effect_PartialMultiBlurParam_t_o *param;
  s32 klass_high;
  u32 monitor;
  u32 *v19;
  s64 v20;
  u32 v23;
  s32 v24;
  struct dds3Effect_Blur_t_o *Blur;
  s32 ID;
  UnityEngine_Vector4_o v29;
  dds3Effect_PartialMultiBlur_t_o *hPartialMultiBlur;
  u64 v31[3];

  *&v29.z = 0;
  hPartialMultiBlur = 0;
  *&v29.x = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMultiBlurExp_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPMultiBlurExp_tag, v31);
      if ((v31[0] & 1) != 0)
        v6 = v31[2];
      else
        v6 = v31 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = Allocate(dds3Effect_PartialMultiBlur_t);
  dds3Effect_PartialMultiBlur_t___ctor(v8);
  dds3Effect_PartialMultiBlur_t__Clear(v8);
  *&v29.x = 0;
  *&v29.z = 0;
  hPartialMultiBlur = v3[4].monitor;
  v9 = hPartialMultiBlur;
  SDF_VU0__LOADVECTOR(v3[1]);
  hPartialMultiBlur->param->area = (*&v3[4].klass * effScreenArea(*(&v3[2].monitor + 1), 0));
  SDF_VU0__STOREVECTOR(&v29);
  pm = v9->param->Blur->center->pm;
  sub_854710(&v29, 0);
  pm->m_Items[0] = v11;
  v13 = v9->param->Blur->center->pm;
  sub_854710(&v29, 1u);
  v13->m_Items[1] = v14;
  param = v9->param;
  klass_high = HIDWORD(v3[4].klass);
  if (param->area < klass_high)
    param->area = klass_high;
  monitor = v3[2].monitor;
  v19 = v3[3].monitor;
  if (monitor >= LODWORD(v3[3].klass))
  {
    v20 = 0;
  }
  else
  {
    v20 = monitor & 1;
  }
  v23 = v19[v20 + 8];
  v24 = LODWORD(v3[2].monitor) + 1;
  HIDWORD(v3[2].klass) = v23;
  LODWORD(v3[2].monitor) = v24;
  Blur = hPartialMultiBlur->param->Blur;
  Blur->abgr = effColorMultiply(v3[2].klass, v23);
  if (!effBTLSkillCheckRun())
    goto LABEL_30;
LABEL_25:
  ID = effBTLSkillGetID();
LABEL_31:
  dds3EffectPartialMultiBlurDraw(&hPartialMultiBlur, 0, ID);
}

// 0x116b2f0
void effPCPMultiBlurExpSetArea(void **hData, f32 area) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMultiBlurExp_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPMultiBlurExp_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *(&(*hData)[2].monitor + 1) = area;
}

// 0x116b200
void effPCPMultiBlurExpSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMultiBlurExp_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPMultiBlurExp_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[2].klass) = abgr;
}

// 0x116b0d0
void effPCPMultiBlurExpSetPosition(void **hData, sdfVector4_t pPos) {
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
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != effPCPMultiBlurExp_tag)
    {
      sub_8FC2C0(*(v9 + 64), effPCPMultiBlurExp_tag, v13);
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

// 0x116b7b0
effPCPMultiFilterExp_tag *effPCPMultiFilterExpCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  effPCPMultiFilterExpParam_t_o *v10;
  s64 v11;
  effPCPMultiFilterExpParam_t_o *v14;
  u64 v15[3];

  v14 = 0;
  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMultiFilterExp_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPMultiFilterExp_tag, v15);
      if ((v15[0] & 1) != 0)
        v8 = v15[2];
      else
        v8 = v15 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = Allocate(effPCPMultiFilterExpParam_t);
  effPCPMultiFilterExpParam_t___ctor(v10);
  v10->type = v5[2].klass;
  v10->life = v5[3].klass;
  v10->fade_in = HIDWORD(v5[3].klass);
  v10->fade_out = v5[3].monitor;
  v10->area_s = HIDWORD(v5[3].monitor);
  v10->area_e = v5[4].klass;
  v10->MultiFilter = *(v5[4].monitor + 2);
  v14 = v10;
  return effPCPMultiFilterExpCreate(&v14, v11, 0);
}

// 0x116b3e0
effPCPMultiFilterExp_tag *effPCPMultiFilterExpCreate(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  effPCPMultiFilterExp_tag_o *v10;
  dds3Effect_PartialMultiFilterParam_t_o *monitor;
  u64 v14[3];

  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMultiFilterExpParam_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPMultiFilterExpParam_t, v14);
      if ((v14[0] & 1) != 0)
        v8 = v14[2];
      else
        v8 = v14 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = Allocate(effPCPMultiFilterExp_tag);
  _ctor(v10, 0);
  monitor = v5[2].monitor;
  v10->hFilter = dds3EffectPartialMultiFilterCreate(monitor);
  v10->frame = 0;
  v10->abgr = -2139062144;
  v10->type = v5[1].klass;
  v10->life = HIDWORD(v5[1].klass);
  v10->fade_in = v5[1].monitor;
  v10->fade_out = HIDWORD(v5[1].monitor);
  v10->area_s = v5[2].klass;
  v10->area_e = HIDWORD(v5[2].klass);
  v10->abgr_base = *(*(v5[2].monitor + 4) + 16LL);
  return v10;
}

// 0x116b570
effPCPMultiFilterExp_tag *effPCPMultiFilterExpCreatePCF(void **hData, s32 bPos, bool tbldata) {
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
  effPCPMultiFilterExpParam_t_c *v18;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v22;
  s64 *v23;
  Il2CppObject *v25;
  u64 v26[2];
  char *v27;
  s32 pos;

  pos = bPos;
  v25 = 0;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v7->klass->_1.element_class, v8, v26);
      if ((v26[0] & 1) != 0)
        v10 = v27;
      else
        v10 = v26 + 1;
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
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 10);
  if (DataUnityOffSet)
  {
    klass = DataUnityOffSet->klass;
    if (DataUnityOffSet->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMultiFilterExpParam_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPMultiFilterExpParam_t, v26);
      if ((v26[0] & 1) != 0)
        v22 = v27;
      else
        v22 = v26 + 1;
      v23 = sub_8C4940(v22);
    }
  }
  v25 = DataUnityOffSet;
  return effPCPMultiFilterExpCreate(&v25, v18, 0);
}

// 0x116b930
void effPCPMultiFilterExpDelete(void **hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3Effect_PartialMultiFilter_t_o *monitor;
  char *v6;
  s64 *v7;
  u64 v8[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMultiFilterExp_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPMultiFilterExp_tag, v8);
    if ((v8[0] & 1) != 0)
      v6 = v8[2];
    else
      v6 = v8 + 1;
    v7 = sub_8C4940(v6);
  }
  monitor = (*hData)[4].monitor;
  dds3EffectPartialMultiFilterDelete(monitor);
}

// 0x116ba40
void effPCPMultiFilterExpDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  dds3Effect_PartialMultiFilter_t_o *monitor;
  s32 monitor_high;
  s32 v11;
  s32 v12;
  s32 v13;
  s32 klass_high;
  struct System_Int32_array *pm;
  struct System_Int32_array *v17;
  s32 v19;
  struct System_Int32_array *v20;
  f32 v21;
  f32 v23;
  f32 v25;
  f32 v26;
  dds3Effect_PartialMultiFilter_t_o *v27;
  f32 v28;
  f32 v29;
  u32 v30;
  struct dds3Effect_Filter_t_o *Filter;
  UnityEngine_Vector4_o v33;
  dds3Effect_PartialMultiFilter_t_o *hPartialMultiFilter;
  u64 v35[3];

  *&v33.z = 0;
  hPartialMultiFilter = 0;
  *&v33.x = 0;
  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMultiFilterExp_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPMultiFilterExp_tag, v35);
      if ((v35[0] & 1) != 0)
        v6 = v35[2];
      else
        v6 = v35 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = Allocate(dds3Effect_PartialMultiFilter_t);
  dds3Effect_PartialMultiFilter_t___ctor(v8);
  *&v33.x = 0;
  *&v33.z = 0;
  monitor = v3[4].monitor;
  hPartialMultiFilter = monitor;
  monitor_high = HIDWORD(v3[2].monitor);
  v11 = v3[3].klass;
  v12 = v11 - monitor_high;
  if (v11 >= monitor_high)
  {
    klass_high = HIDWORD(v3[3].klass);
    v13 = v3[3].monitor;
    if (LOBYTE(v3[2].klass))
    {
      pm = monitor->param->center->pm;
      pm->m_Items[0] = 0;
      v17 = monitor->param->center->pm;
      v19 = 0;
    }
    else
    {
      SDF_VU0__LOADVECTOR(v3[1]);
      effScreenOffset();
      SDF_VU0__STOREVECTOR(&v33);
      v20 = hPartialMultiFilter->param->center->pm;
      sub_854710(&v33, 0);
      v20->m_Items[0] = v21;
      v17 = hPartialMultiFilter->param->center->pm;
      sub_854710(&v33, 1u);
      v19 = -v23;
    }
    v17->m_Items[1] = v19;
    v25 = monitor_high;
    v26 = v11;
    v27 = hPartialMultiFilter;
    hPartialMultiFilter->param->area = HIDWORD(v3[3].monitor)
                                                   + ((monitor_high * (LODWORD(v3[4].klass) - HIDWORD(v3[3].monitor)))
                                                    / v26);
    if (monitor_high < klass_high && klass_high)
    {
      v28 = klass_high;
    }
    else
    {
      v29 = 1.0;
      if (v12 > v13 || !v13)
        goto LABEL_28;
      v25 = v12;
      v28 = v13;
    }
    v29 = v25 / v28;
LABEL_28:
    v30 = effColorBlend(HIDWORD(v3[2].klass) & 0xFFFFFF, HIDWORD(v3[2].klass), v29, 0);
    Filter = v27->param->Filter;
    Filter->abgr = effColorMultiply(v30, v3[2].monitor);
    dds3EffectPartialMultiFilterDraw(&hPartialMultiFilter);
    ++HIDWORD(v3[2].monitor);
  }
}

// 0x116bf70
void effPCPMultiFilterExpSetArea(void **hData, f32 area) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMultiFilterExp_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPMultiFilterExp_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *(&(*hData)[4].klass + 1) = area;
}

// 0x116be80
void effPCPMultiFilterExpSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPMultiFilterExp_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPMultiFilterExp_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[2].klass) = abgr;
}

// 0x116bd50
void effPCPMultiFilterExpSetPosition(void **hData, sdfVector4_t pPos) {
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
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != effPCPMultiFilterExp_tag)
    {
      sub_8FC2C0(*(v9 + 64), effPCPMultiFilterExp_tag, v13);
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

// 0x1186f60
effPCPRadiateBED_tag *effPCPRadiateBEDCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 typeDefinition_low;
  u64 *v11;
  u64 *v12;
  s64 v13;
  s64 v14;
  s64 v15;
  u32 *v18;
  u64 v19;
  u64 *v20;
  u64 v23;
  s64 v25;
  effBTL_t_o *v26;
  u32 v28;
  s32 v29;
  u32 *v30;
  u64 v33[3];

  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRadiateBED_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPRadiateBED_tag, v33);
      if ((v33[0] & 1) != 0)
        v8 = v33[2];
      else
        v8 = v33 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  typeDefinition_low = LODWORD(v5[1].klass->_1.typeDefinition);
  v11 = Allocate(effPCPRadiateBED_tag);
  _ctor(v11, 0);
  v11[2] = v5[1].klass;
  v11[3] = NewSpecific(effPCPRadiateBEDPart_tag, typeDefinition_low);
  v11[7] = 0;
  *(v11 + 40) = 0;
  *(v11 + 44) = 0x808080803F800000LL;
  v11[4] = v5[2].klass;
  v12 = Allocate(effEveBEDParams_t);
  effEveBEDParams_t___ctor(v12);
  effEveBEDParams_t__Clear(v12);
  sub_854930((v12 + 2), 0);
  sub_854930((v12 + 2), 1u);
  sub_854930((v12 + 2), 2u);
  sub_854930((v12 + 2), 3u);
  sub_854930((v12 + 4), 0);
  sub_854930((v12 + 4), 1u);
  sub_854930((v12 + 4), 2u);
  sub_854930((v12 + 4), 3u);
  v12[6] = 0x42C8000042C80000LL;
  v12[7] = 0x808080803F800000LL;
  if (typeDefinition_low)
  {
    v13 = *(v11[2] + 108);
    v14 = -typeDefinition_low;
    v15 = 4;
    do
    {
      v18 = v11[3];
      v19 = v15 - 4;
      v20 = Allocate(effPCPRadiateBEDPart_tag);
      _ctor(v20, 0);
      *&v18[2 * v15] = v20;
      v23 = v11[3];
      v25 = *(v23 + 8 * v15);
      v26 = v5[2].klass;
      *(v25 + 16) = effEveBEDCutCreate(v26, 2u, v12);
      if (v13 < 1)
      {
        v29 = 0;
      }
      else
      {
        v28 = DDS3EFFECT_RAND_I();
        v29 = v28 / v13 * v13 - v28;
      }
      *(v25 + 24) = v29;
      v30 = v11[3];
      *&v30[2 * v15++] = v25;
    }
    while (v14 + v15 != 4);
  }
  return v11;
}

// 0x1186750
effPCPRadiateBED_tag *effPCPRadiateBEDCreate(effPCPRadiateBEDParam_t *pParam, void *pBEDData) {
  u64 *v5;
  s64 number;
  u64 *v7;
  Il2CppClass *v9;
  s64 *Interface;
  char *v11;
  s64 *v12;
  s64 v13;
  s64 v14;
  s64 v15;
  u32 *v18;
  u64 v19;
  u64 *v20;
  u64 v23;
  s64 v25;
  effBTL_t_o *v26;
  u32 v28;
  s32 v29;
  u32 *v30;
  u64 v33[3];

  v5 = Allocate(effEveBEDParams_t);
  effEveBEDParams_t___ctor(v5);
  number = pParam->number;
  v7 = Allocate(effPCPRadiateBED_tag);
  _ctor(v7, 0);
  v7[2] = pParam;
  v7[3] = NewSpecific(effPCPRadiateBEDPart_tag, pParam->number);
  v7[7] = 0;
  *(v7 + 44) = 0x808080803F800000LL;
  *(v7 + 40) = 1;
  if (!pBEDData)
    goto LABEL_12;
LABEL_6:
  Interface = QueryInterface(pBEDData, byte);
  if (!Interface)
  {
    sub_8FC2C0(pBEDData->klass->_1.element_class, v9, v33);
    if ((v33[0] & 1) != 0)
      v11 = v33[2];
    else
      v11 = v33 + 1;
    v12 = sub_8C4940(v11);
  }
LABEL_13:
  v7[4] = effEveBEDCreate(Interface);
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
  if (number)
  {
    v13 = *(v7[2] + 108);
    v14 = -number;
    v15 = 4;
    do
    {
      v18 = v7[3];
      v19 = v15 - 4;
      v20 = Allocate(effPCPRadiateBEDPart_tag);
      _ctor(v20, 0);
      *&v18[2 * v15] = v20;
      v23 = v7[3];
      v25 = *(v23 + 8 * v15);
      v26 = v7[4];
      *(v25 + 16) = effEveBEDCutCreate(v26, 2u, v5);
      if (v13 < 1)
      {
        v29 = 0;
      }
      else
      {
        v28 = DDS3EFFECT_RAND_I();
        v29 = v28 / v13 * v13 - v28;
      }
      *(v25 + 24) = v29;
      v30 = v7[3];
      *&v30[2 * v15++] = v25;
    }
    while (v14 + v15 != 4);
  }
  return v7;
}

// 0x1186b70
effPCPRadiateBED_tag *effPCPRadiateBEDCreatePCF(void **hData, s32 bPos, bool tbldata) {
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
  struct dds3EffectPCPData_Part_t_array *v20;
  Il2CppObject *v21;
  effPCPRadiateBEDParam_t_o *v22;
  u32 v24;
  Il2CppObject *EffPCPpBEDData;
  effPCPRadiateBEDParam_t_c *klass;
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
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 23);
  v20 = v6->pcpData;
  v21 = *hData;
  v22 = DataUnityOffSet;
  v24 = v20->m_Items[1]->offset;
  EffPCPpBEDData = GetEffPCPpBEDData(v21, v24 + bPos);
  if (v22)
  {
    klass = v22->klass;
    if (v22->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRadiateBEDParam_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPRadiateBEDParam_t, v32);
      if ((v32[0] & 1) != 0)
        v29 = v33;
      else
        v29 = v32 + 1;
      v30 = sub_8C4940(v29);
    }
  }
  return effPCPRadiateBEDCreate(v22, EffPCPpBEDData);
}

// 0x1187360
void effPCPRadiateBEDDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s64 typeDefinition_low;
  u64 i;
  u64 *monitor;
  effEveBEDCutHandle_t_o *v12;
  effBTL_t_o *v13;
  u64 v14[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRadiateBED_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPRadiateBED_tag, v14);
      if ((v14[0] & 1) != 0)
        v6 = v14[2];
      else
        v6 = v14 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  typeDefinition_low = LODWORD(v3[1].klass->_1.typeDefinition);
  if (typeDefinition_low)
  {
    for (i = 0; i != typeDefinition_low; ++i)
    {
      monitor = v3[1].monitor;
      v12 = *(monitor[i + 4] + 16LL);
      effEveBEDCutDelete(v12);
    }
  }
  else if (!v3)
  {
    return;
  }
  v13 = v3[2].klass;
  if (v13 && !v13->CutCount)
  {
    effEveBEDDelete(v13);
  }
}

// 0x1187680
void effPCPRadiateBEDDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  Il2CppClass *v9;
  s32 interopData;
  f32 v11;
  s32 generic_class_high;
  s64 typeDefinition_low;
  u64 v16;
  u64 *monitor;
  s64 v19;
  s32 v20;
  f32 v21;
  f32 v22;
  f32 v23;
  f32 v24;
  s32 interopData_high;
  u32 abgr1;
  UnityEngine_Vector4_o dst;
  effPCPRadiateBED_tag_o *v29[3];
  effPCPRadiateBED_tag_o *pRadiateBED;

  pRadiateBED = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRadiateBED_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPRadiateBED_tag, v29);
      if ((v29[0] & 1) != 0)
        v6 = v29[2];
      else
        v6 = v29 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  pRadiateBED = *hData;
  v8 = Allocate(effEveBEDParams_t);
  effEveBEDParams_t___ctor(v8);
  *&dst.x = 0;
  *&dst.z = 0;
  v9 = v3[1].klass;
  interopData = v9->_1.interopData;
  v11 = *(&v9->_1.events + 1);
  generic_class_high = HIDWORD(v9->_1.generic_class);
  typeDefinition_low = LODWORD(v9->_1.typeDefinition);
  interopData_high = HIDWORD(v9->_1.interopData);
  abgr1 = v3[3].klass;
  SDF_VU0__COPYVECTOR(&dst, *&v9->_1.name);
  if (generic_class_high)
  {
    sub_854930((v8 + 4), 0);
    sub_854930((v8 + 4), 1u);
    sub_854930((v8 + 4), 2u);
    sub_854930((v8 + 4), 3u);
    v8[6] = 0x42C8000042C80000LL;
    *(v8 + 14) = 1065353216;
    if (typeDefinition_low)
    {
      v16 = 0;
      while (1)
      {
        monitor = v3[1].monitor;
        v19 = monitor[v16 + 4];
        v20 = *(v19 + 24);
        if (v20 > generic_class_high)
          goto LABEL_37;
        if (!v20)
          break;
        if ((v20 & 0x80000000) == 0)
          goto LABEL_23;
LABEL_36:
        *(v19 + 24) = v20 + 1;
LABEL_37:
        if (typeDefinition_low == ++v16)
          return;
      }
      effPCPRadiateBEDPartInit(&pRadiateBED, v16);
      v20 = *(v19 + 24);
      if (v20 < 0)
        goto LABEL_36;
LABEL_23:
      v21 = *(v19 + 36);
      sdfCos(v21);
      sdfSin(v21);
      sub_854710(&dst, 0);
      sub_854930((v8 + 2), 0);
      sub_854710(&dst, 1u);
      sub_854930((v8 + 2), 1u);
      sub_854710(&dst, 2u);
      sub_854930((v8 + 2), 2u);
      v22 = *(v19 + 40);
      v23 = *(v19 + 36) + v22;
      *(v19 + 28) = *(v19 + 28) + *(v19 + 32);
      *(v19 + 36) = v23;
      *(v19 + 40) = v11 * v22;
      if (interopData && v20 < interopData)
      {
        v24 = v20 / interopData;
      }
      else
      {
        v24 = 1.0;
        if (interopData_high)
        {
          v24 = 1.0;
          if (generic_class_high - v20 <= interopData_high)
            v24 = (generic_class_high - v20) / interopData_high;
        }
      }
      *(v8 + 15) = effColorBlend(abgr1 & 0xFFFFFF, abgr1, v24);
      effEveBEDCutSetParams((v19 + 16), v8, 0);
      effEveBEDCutDraw((v19 + 16), 0);
      v20 = *(v19 + 24);
      goto LABEL_36;
    }
  }
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
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRadiateBED_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPRadiateBED_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[3].klass) = abgr;
}

// 0x1187a90
void effPCPRadiateBEDSetPosition(void **hData, sdfVector4_t pPos) {
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
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRadiateBED_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPRadiateBED_tag, v12);
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

// 0x1187bb0
void effPCPRadiateBEDSetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRadiateBED_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPRadiateBED_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *(&(*hData)[2].monitor + 1) = scale;
}

// 0x1188710
effPCPRadiateTB_tag *effPCPRadiateTBCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 *v10;
  u64 bits;
  effPCPRadiateTB_tag_o *v12;
  struct effBTL_t_array *v13;
  Il2CppClass *v14;
  struct effBTL_t_array *v15;
  s64 *data;
  Il2CppClass *v19;
  struct effBTL_t_array *hBED;
  s64 *v22;
  s64 timing;
  s64 v25;
  s64 v26;
  u32 *pPart;
  u64 v32;
  u64 *v33;
  struct effPCPRadiateTBPart_tag_array *v35;
  s64 v37;
  u64 *v38;
  Il2CppClass *v40;
  u64 *v41;
  effBTL_t_o *v43;
  s64 *v44;
  s64 *v45;
  Il2CppClass *v47;
  s64 v48;
  s64 *v50;
  s64 *v52;
  u32 v54;
  u32 *v55;
  Il2CppObject *v60[3];
  Il2CppObject *hDataa;

  hDataa = 0;
  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRadiateTB_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPRadiateTB_tag, v60);
      if ((v60[0] & 1) != 0)
        v8 = v60[2];
      else
        v8 = v60 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = Allocate(effEveBEDParams_t);
  effEveBEDParams_t___ctor(v10);
  bits = v5[1].klass->_1.byval_arg.bits;
  v12 = Allocate(effPCPRadiateTB_tag);
  _ctor(v12, 0);
  v12->param = v5[1].klass;
  v12->pPart = NewSpecific(effPCPRadiateTBPart_tag, bits);
  v12->abgr = -2139062144;
  v12->hMem = 0;
  v12->original = 0;
  v13 = NewSpecific(effBTL_t, 2u);
  v12->hBED = v13;
  v14 = v5[2].klass;
  v15 = v13;
  data = v14->_1.byval_arg.data;
  v15->m_Items[0] = data;
  v19 = v5[2].klass;
  hBED = v12->hBED;
  v22 = *&v19->_1.byval_arg.bits;
  hBED->m_Items[1] = v22;
  sub_854930((v10 + 2), 0);
  sub_854930((v10 + 2), 1u);
  sub_854930((v10 + 2), 2u);
  sub_854930((v10 + 2), 3u);
  sub_854930((v10 + 4), 0);
  sub_854930((v10 + 4), 1u);
  sub_854930((v10 + 4), 2u);
  sub_854930((v10 + 4), 3u);
  v10[6] = 0x42C8000042C80000LL;
  *(v10 + 14) = 1065353216;
  *(v10 + 15) = -2139062144;
  if (bits)
  {
    timing = v12->param->timing;
    v25 = -bits;
    v26 = 4;
    do
    {
      pPart = v12->pPart;
      v32 = v26 - 4;
      v33 = Allocate(effPCPRadiateTBPart_tag);
      _ctor(v33, 0);
      *&pPart[2 * v26] = v33;
      v35 = v12->pPart;
      v37 = *(&v35->obj.klass + v26);
      hDataa = v5[1].klass->_1.castClass;
      *(v37 + 16) = effPCP_ThunderPolyCreate(&hDataa, 0, 1, 0);
      v38 = NewSpecific(effEveBEDCutHandle_t, 2u);
      *(v37 + 24) = v38;
      v40 = v5[2].klass;
      v41 = v38;
      v43 = v40->_1.byval_arg.data;
      v44 = effEveBEDCutCreate(v43, 2u, v10);
      v45 = v44;
      v41[4] = v45;
      v47 = v5[2].klass;
      v48 = *(v37 + 24);
      v50 = effEveBEDCutCreate(*&v47->_1.byval_arg.bits, 2u, v10);
      v52 = v50;
      *(v48 + 40) = v52;
      v54 = DDS3EFFECT_RAND_I();
      *(v37 + 48) = v54 / timing * timing - v54;
      v55 = v12->pPart;
      *&v55[2 * v26++] = v37;
    }
    while (v25 + v26 != 4);
  }
  return v12;
}

// 0x1187d90
effPCPRadiateTB_tag *effPCPRadiateTBCreate(effPCPRadiateTBParam_t *pParam, void *pBEDData0, void *pBEDData1) {
  u64 *v7;
  s64 number;
  effPCPRadiateTB_tag_o *v9;
  struct effPCPRadiateTBPart_tag_array *v10;
  struct effPCPRadiateTBParam_t_o *param;
  struct effBTL_t_array *v12;
  struct effBTL_t_array *v14;
  Il2CppClass *v15;
  s64 *Interface;
  char *v17;
  s64 *v18;
  s64 *v19;
  s64 *v20;
  struct effBTL_t_array *hBED;
  Il2CppClass *v24;
  char *v25;
  s64 *v26;
  s64 *v27;
  s64 *v28;
  s64 *v29;
  s64 timing;
  s64 v32;
  s64 v33;
  u32 *pPart;
  u64 v39;
  u64 *v40;
  struct effPCPRadiateTBPart_tag_array *v42;
  s64 v44;
  u64 *v45;
  struct effBTL_t_array *v47;
  u64 *v48;
  effBTL_t_o *v50;
  s64 *v51;
  s64 *v52;
  struct effBTL_t_array *v54;
  s64 v55;
  s64 *v57;
  s64 *v59;
  u32 v61;
  u32 *v62;
  u64 v66[2];
  char *v67;
  Il2CppObject *hData;

  hData = 0;
  v7 = Allocate(effEveBEDParams_t);
  effEveBEDParams_t___ctor(v7);
  number = pParam->number;
  v9 = Allocate(effPCPRadiateTB_tag);
  _ctor(v9, 0);
  v9->param = pParam;
  v10 = NewSpecific(effPCPRadiateTBPart_tag, pParam->number);
  param = v9->param;
  v9->pPart = v10;
  v9->abgr = -2139062144;
  v9->hMem = 0;
  if (param->timing <= 0)
    param->timing = 1;
  v9->original = 1;
  v12 = NewSpecific(effBTL_t, 2u);
  v9->hBED = v12;
  v14 = v12;
  if (!pBEDData0)
    goto LABEL_14;
LABEL_8:
  Interface = QueryInterface(pBEDData0, byte);
  if (!Interface)
  {
    sub_8FC2C0(pBEDData0->klass->_1.element_class, v15, v66);
    if ((v66[0] & 1) != 0)
      v17 = v67;
    else
      v17 = v66 + 1;
    v18 = sub_8C4940(v17);
  }
LABEL_15:
  v19 = effEveBEDCreate(Interface);
  v20 = v19;
  v14->m_Items[0] = v20;
  hBED = v9->hBED;
  if (pBEDData1)
  {
    v27 = QueryInterface(pBEDData1, byte);
    if (!v27)
    {
      sub_8FC2C0(pBEDData1->klass->_1.element_class, v24, v66);
      if ((v66[0] & 1) != 0)
        v25 = v67;
      else
        v25 = v66 + 1;
      v26 = sub_8C4940(v25);
    }
  }
  else
  {
    v27 = 0;
  }
  v28 = effEveBEDCreate(v27);
  v29 = v28;
  hBED->m_Items[1] = v29;
  sub_854930((v7 + 2), 0);
  sub_854930((v7 + 2), 1u);
  sub_854930((v7 + 2), 2u);
  sub_854930((v7 + 2), 3u);
  sub_854930((v7 + 4), 0);
  sub_854930((v7 + 4), 1u);
  sub_854930((v7 + 4), 2u);
  sub_854930((v7 + 4), 3u);
  v7[6] = 0x42C8000042C80000LL;
  *(v7 + 14) = 1065353216;
  *(v7 + 15) = -2139062144;
  if (number)
  {
    timing = v9->param->timing;
    v32 = -number;
    v33 = 4;
    do
    {
      pPart = v9->pPart;
      v39 = v33 - 4;
      v40 = Allocate(effPCPRadiateTBPart_tag);
      _ctor(v40, 0);
      *&pPart[2 * v33] = v40;
      v42 = v9->pPart;
      v44 = *(&v42->obj.klass + v33);
      hData = pParam->ThunderParam;
      *(v44 + 16) = effPCP_ThunderPolyCreate(&hData, 0, 1, 0);
      v45 = NewSpecific(effEveBEDCutHandle_t, 2u);
      *(v44 + 24) = v45;
      v47 = v9->hBED;
      v48 = v45;
      v50 = v47->m_Items[0];
      v51 = effEveBEDCutCreate(v50, 2u, v7);
      v52 = v51;
      v48[4] = v52;
      v54 = v9->hBED;
      v55 = *(v44 + 24);
      v57 = effEveBEDCutCreate(v54->m_Items[1], 2u, v7);
      v59 = v57;
      *(v55 + 40) = v59;
      v61 = DDS3EFFECT_RAND_I();
      *(v44 + 48) = v61 / timing * timing - v61;
      v62 = v9->pPart;
      *&v62[2 * v33++] = v44;
    }
    while (v32 + v33 != 4);
  }
  return v9;
}

// 0x1188450
effPCPRadiateTB_tag *effPCPRadiateTBCreatePCF(void **hData, s32 bPos, bool tbldata) {
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
  struct dds3EffectPCPData_Part_t_array *v20;
  Il2CppObject *v21;
  effPCPRadiateTBParam_t_o *v22;
  u32 v24;
  Il2CppObject *EffPCPpBEDData;
  struct dds3EffectPCPData_Part_t_array *v27;
  Il2CppObject *v28;
  Il2CppObject *v29;
  Il2CppObject *v32;
  effPCPRadiateTBParam_t_c *klass;
  s64 typeHierarchyDepth;
  char *v35;
  s64 *v36;
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
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 24);
  v20 = v6->pcpData;
  v21 = *hData;
  v22 = DataUnityOffSet;
  v24 = v20->m_Items[1]->offset;
  EffPCPpBEDData = GetEffPCPpBEDData(v21, v24 + bPos);
  v27 = v6->pcpData;
  v28 = *hData;
  v29 = EffPCPpBEDData;
  v32 = GetEffPCPpBEDData(v28, v27->m_Items[2]->offset + bPos);
  if (v22)
  {
    klass = v22->klass;
    if (v22->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRadiateTBParam_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPRadiateTBParam_t, v39);
      if ((v39[0] & 1) != 0)
        v35 = v40;
      else
        v35 = v39 + 1;
      v36 = sub_8C4940(v35);
    }
  }
  return effPCPRadiateTBCreate(v22, v29, v32);
}

// 0x1188d40
void effPCPRadiateTBDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s64 bits;
  u64 i;
  u64 *monitor;
  s64 v12;
  s64 v13;
  effEveBEDCutHandle_t_o *v14;
  s64 v16;
  Il2CppClass *v18;
  Il2CppClass *v20;
  Il2CppClass *v21;
  Il2CppClass *v23;
  Il2CppClass *v25;
  effBTL_t_o *v27;
  Il2CppClass *v29;
  effBTL_t_o *data;
  Il2CppObject *v32;
  u64 v33[3];

  v32 = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRadiateTB_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPRadiateTB_tag, v33);
      if ((v33[0] & 1) != 0)
        v6 = v33[2];
      else
        v6 = v33 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  bits = v3[1].klass->_1.byval_arg.bits;
  if (bits)
  {
    for (i = 0; i != bits; ++i)
    {
      monitor = v3[1].monitor;
      v12 = monitor[i + 4];
      v13 = *(v12 + 24);
      v14 = *(v13 + 32);
      effEveBEDCutDelete(v14);
      v16 = *(v12 + 24);
      effEveBEDCutDelete(*(v16 + 40), 0);
      v32 = *(v12 + 16);
      effPCP_ThunderPolyDelete(&v32);
    }
  }
  v18 = v3[2].klass;
  if (!v18->_1.byval_arg.data)
    goto LABEL_27;
  v20 = v3[2].klass;
  if (!*(v20->_1.byval_arg.data + 8))
  {
    v29 = v3[2].klass;
    data = v29->_1.byval_arg.data;
    effEveBEDDelete(data);
    v21 = v3[2].klass;
    if (LODWORD(v21->_1.namespaze) <= 1)
    {
LABEL_28:
    }
  }
  else
  {
LABEL_27:
    v21 = v3[2].klass;
    if (LODWORD(v21->_1.namespaze) <= 1)
      goto LABEL_28;
  }
  if (*&v21->_1.byval_arg.bits)
  {
    v23 = v3[2].klass;
    if (!*(*&v23->_1.byval_arg.bits + 32LL))
    {
      v25 = v3[2].klass;
      v27 = *&v25->_1.byval_arg.bits;
      effEveBEDDelete(v27);
    }
  }
}

// 0x11891f0
void effPCPRadiateTBDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  Il2CppClass *v9;
  s32 data_high;
  s64 bits;
  u64 i;
  u64 *monitor;
  s64 v19;
  s32 v20;
  s32 v21;
  u32 v22;
  s32 v23;
  effPCP_ThunderPolyParam_t_o *Param;
  f32 v26;
  effPCP_ThunderPolyParam_t_o *v27;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  struct UnityEngine_Vector4_array *pos;
  struct UnityEngine_Vector4_array *v34;
  struct UnityEngine_Vector4_array *v36;
  struct UnityEngine_Vector4_array *v38;
  struct UnityEngine_Vector4_array *v40;
  struct UnityEngine_Vector4_array *v42;
  f32 v44;
  u32 v45;
  struct UnityEngine_Vector4_array *v46;
  s64 v49;
  s64 v51;
  struct UnityEngine_Vector4_array *v53;
  s64 v55;
  s64 v57;
  s64 v59;
  s32 v60;
  u32 abgr1;
  s32 data;
  s32 data_low;
  Il2CppObject *hDataa;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v66;
  UnityEngine_Vector4_o v67;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o v69;
  effPCPRadiateTB_tag_o *pRadiateTB;
  u64 v71[4];
  UnityEngine_Vector4_o v72;

  *&v69.z = 0;
  pRadiateTB = 0;
  *&dst.z = 0;
  *&v69.x = 0;
  *&v67.z = 0;
  *&dst.x = 0;
  *&v66.z = 0;
  *&v67.x = 0;
  *&p.z = 0;
  *&v66.x = 0;
  hDataa = 0;
  *&p.x = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRadiateTB_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPRadiateTB_tag, v71);
      if ((v71[0] & 1) != 0)
        v6 = v71[2];
      else
        v6 = v71 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  pRadiateTB = *hData;
  sub_854690(&v69.x, 0.0, 1.0, 0.0, 0.0);
  v8 = Allocate(effEveBEDParams_t);
  effEveBEDParams_t___ctor(v8);
  *&dst.x = 0;
  *&dst.z = 0;
  *&v67.x = 0;
  *&v67.z = 0;
  *&v66.x = 0;
  *&v66.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  v9 = v3[1].klass;
  data_high = HIDWORD(v9->_1.byval_arg.data);
  bits = v9->_1.byval_arg.bits;
  data_low = LOBYTE(v9->_1.byval_arg.data);
  v59 = *(&v9->_1.byval_arg.bits + 1);
  data = v9->_1.this_arg.data;
  v60 = HIDWORD(v9->_1.this_arg.data);
  abgr1 = HIDWORD(v3[2].monitor);
  SDF_VU0__COPYVECTOR(&dst, *&v9->_1.name);
  if (data_high)
  {
    sub_854930((v8 + 4), 0);
    sub_854930((v8 + 4), 1u);
    sub_854930((v8 + 4), 2u);
    sub_854930((v8 + 4), 3u);
    v8[6] = 0x42C8000042C80000LL;
    *(v8 + 14) = 1065353216;
    SDF_VU0__LOADVECTOR(dds3CameraTargetPos);
    SDF_VU0__LOADVECTOR_B(dds3CameraEyePos);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(&p);
    if (bits)
    {
      for (i = 0; bits != i; ++i)
      {
        monitor = v3[1].monitor;
        v19 = monitor[i + 4];
        v20 = *(v19 + 48);
        if (v20 > data_high)
          continue;
        if (v20)
        {
          if (v20 < 0)
            goto LABEL_23;
        }
        else
        {
          effPCPRadiateTBPartInit(&pRadiateTB, i);
          v20 = *(v19 + 48);
          if (v20 < 0)
          {
LABEL_23:
            v21 = *(v19 + 48);
            if (!data_low)
              goto LABEL_69;
            goto LABEL_24;
          }
        }
        Param = effPCP_ThunderPolyGetParam(*(v19 + 16), 0);
        v26 = *(v19 + 32);
        v27 = Param;
        x = p.x;
        y = p.y;
        z = p.z;
        w = p.w;
        v72.x = x;
        v72.y = y;
        v72.z = z;
        v72.w = w;
        SetRotateMatrixAxis(v26, v72);
        SDF_VU0__LOADVECTOR(v69);
        SDF_VU0__LOADVECTOR_B(p);
        SDF_VU0__OUTERPRODUCT();
        SDF_VU0__NORMALIZE();
        SDF_VU0__APPLYMATRIX_XYZ();
        SDF_VU0__STOREVECTOR(&v67);
        SDF_VU0__LOADVECTOR_B(v69);
        SDF_VU0__OUTERPRODUCT();
        SDF_VU0__NORMALIZE();
        SDF_VU0__STOREVECTOR(&v66);
        SetRotateMatrixAxis(*(v19 + 40), v66, 0);
        SDF_VU0__LOADVECTOR(v67);
        SDF_VU0__APPLYMATRIX_XYZ();
        SDF_VU0__STOREVECTOR(&v67);
        pos = v27->pos;
        sub_854710(&dst, 0);
        sub_854710(&v67, 0);
        sub_854930(pos->m_Items, 0);
        v34 = v27->pos;
        sub_854710(&dst, 1u);
        sub_854710(&v67, 1u);
        sub_854930(v34->m_Items, 1u);
        v36 = v27->pos;
        sub_854710(&dst, 2u);
        sub_854710(&v67, 2u);
        sub_854930(v36->m_Items, 2u);
        v38 = v27->pos;
        sub_854710(&dst, 0);
        sub_854930(&v38->m_Items[1], 0);
        v40 = v27->pos;
        sub_854710(&dst, 1u);
        sub_854930(&v40->m_Items[1], 1u);
        v42 = v27->pos;
        sub_854710(&dst, 2u);
        sub_854930(&v42->m_Items[1], 2u);
        *(v19 + 40) = *(v19 + 40) + *(v19 + 44);
        if (data && v20 < data)
        {
          v44 = v20 / data;
        }
        else
        {
          v44 = 1.0;
          if (v60)
          {
            v44 = 1.0;
            if (data_high - v20 <= v60)
              v44 = (data_high - v20) / v60;
          }
        }
        v45 = effColorBlend(abgr1 & 0xFFFFFF, abgr1, v44);
        hDataa = *(v19 + 16);
        effPCP_ThunderPolySetColor(&hDataa, v45);
        hDataa = *(v19 + 16);
        effPCP_ThunderPolyDraw(&hDataa);
        *(v8 + 15) = v45;
        v46 = v27->pos;
        SDF_VU0__COPYVECTOR(v8 + 1, v46->m_Items[1]);
        v49 = *(v19 + 24);
        else if (!*(v49 + 24))
        {
LABEL_59:
        }
        effEveBEDCutSetParams((v49 + 32), v8, 0);
        v51 = *(v19 + 24);
        effEveBEDCutDraw((v51 + 32), 0);
        v53 = v27->pos;
        SDF_VU0__COPYVECTOR(v8 + 1, v53->m_Items[0]);
        v55 = *(v19 + 24);
        effEveBEDCutSetParams((v55 + 40), v8, 0);
        v57 = *(v19 + 24);
        effEveBEDCutDraw((v57 + 40), 0);
        v21 = *(v19 + 48);
        if (!data_low)
          goto LABEL_69;
LABEL_24:
        if (v21 >= data_high)
        {
          v22 = DDS3EFFECT_RAND_I();
          v23 = v22 / v59 * v59 - v22;
          goto LABEL_70;
        }
LABEL_69:
        v23 = v21 + 1;
LABEL_70:
        *(v19 + 48) = v23;
      }
    }
  }
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
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRadiateTB_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPRadiateTB_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[2].monitor) = abgr;
}

// 0x1189a70
void effPCPRadiateTBSetPosition(void **hData, sdfVector4_t pPos) {
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
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRadiateTB_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPRadiateTB_tag, v12);
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

// 0x1183fb0
effPCPRadiateThunder_tag *effPCPRadiateThunderCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v6;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  u64 *v11;
  effPCPRadiateThunderParam_t_o *v14;
  effPCPRadiateThunder_tag_o *v15;
  u64 typeDefinition_low;
  struct effPartHandle_t_array_array *v17;
  u32 *phAttach;
  u64 i;
  s64 *v21;
  s64 *v22;
  u64 v25;
  u32 v26;
  s64 v28;
  Il2CppClass *v30;
  u32 *data;
  u64 j;
  struct effPartHandle_t_array_array *v36;
  effPartHandle_t_array *v38;
  s64 *v39;
  s64 *v40;
  Il2CppObject *v43;
  effPartHandle_t_o *hEffPartSrc;
  u64 v45[3];

  hEffPartSrc = 0;
  v6 = *hData;
  if (*hData)
  {
    klass = v6->klass;
    if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRadiateThunder_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPRadiateThunder_tag, v45);
      if ((v45[0] & 1) != 0)
        v9 = v45[2];
      else
        v9 = v45 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  v11 = Allocate(effPartHandle_t);
  effPartHandle_t___ctor(v11);
  hEffPartSrc = v11;
  v14 = v6[1].klass;
  v15 = effPCPRadiateThunderCreate(v14, 0);
  if (v6[3].klass)
  {
    typeDefinition_low = LODWORD(v6[1].klass->_1.typeDefinition);
    v17 = NewSpecific(effPartHandle_t__, typeDefinition_low);
    v15->phAttach = v17;
    if (typeDefinition_low)
    {
      phAttach = v17;
      for (i = 0; ; ++i)
      {
        v21 = NewSpecific(effPartHandle_t, 4u);
        v22 = v21;
        *&phAttach[2 * i + 8] = v22;
        if (typeDefinition_low - 1 == i)
          break;
        phAttach = v15->phAttach;
      }
    }
    v25 = 0;
    v26 = 0;
    v43 = v6;
    do
    {
      v28 = *(v6[1].klass->_1.nestedTypes + 2);
      if (*(v28 + v25 + 32))
      {
        v30 = v6[3].klass;
        data = v30->_1.byval_arg.data;
        hEffPartSrc = *&data[2 * v26 + 8];
        if (typeDefinition_low)
        {
          for (j = 0; j != typeDefinition_low; ++j)
          {
            v36 = v15->phAttach;
            v38 = v36->m_Items[j];
            v39 = dds3EffectPartCopy(&hEffPartSrc, bPos, 0);
            v40 = v39;
            v38->m_Items[v26] = v40;
          }
        }
        v6 = v43;
        ++v26;
      }
      ++v25;
    }
    while (v25 != 4);
  }
  return v15;
}

// 0x1183670
effPCPRadiateThunder_tag *effPCPRadiateThunderCreate(effPCPRadiateThunderParam_t *pParam, void **pData) {
  u64 *v5;
  u64 *v6;
  u64 *v7;
  u64 *v8;
  struct UnityEngine_Vector4_array *pos;
  s32 v11;
  u32 *v12;
  u32 *v14;
  u64 i;
  s64 *v16;
  s64 *v17;
  System_Object_array *v20;
  u64 v21;
  u32 v22;
  u64 v24;
  u32 *v26;
  struct System_Byte_array *use;
  Il2CppObject *v30;
  u16 v31;
  s64 *v32;
  effPartHandle_t_o *v33;
  s64 v36;
  u64 v38;
  u32 *v40;
  s64 *v41;
  s64 *v42;
  s64 v44;
  u32 *v47;
  u64 v48;
  u64 *v49;
  u64 v51;
  s64 v53;
  u32 *v54;
  System_Object_array *v57;
  u64 number;
  Il2CppObject *hData;
  effPartHandle_t_o *hEffPartSrc;

  hData = 0;
  v5 = Allocate(effPartHandle_t);
  effPartHandle_t___ctor(v5);
  hEffPartSrc = v5;
  number = pParam->number;
  v6 = Allocate(effPCPRadiateThunder_tag);
  _ctor(v6, 0);
  v7 = Allocate(effPCPRadiateThunderParam_t);
  effPCPRadiateThunderParam_t___ctor(v7);
  v6[2] = v7;
  effPCPRadiateThunderParam_t__pClone(pParam, v6 + 2);
  v8 = NewSpecific(effPCPRadiateThunderPart_tag, pParam->number);
  *(v6 + 10) = -2139062144;
  v6[3] = v8;
  *(v6 + 8) = 1065353216;
  pos = pParam->ThunderParam->pos;
  sub_854710(pos->m_Items, 1u);
  *(v6 + 9) = v11;
  v6[6] = 0;
  v6[8] = 0;
  if (pData)
  {
    v57 = pData;
    v12 = NewSpecific(effPartHandle_t__, number);
    v6[6] = v12;
    if (number)
    {
      v14 = v12;
      for (i = 0; ; ++i)
      {
        v16 = NewSpecific(effPartHandle_t, 4u);
        v17 = v16;
        *&v14[2 * i + 8] = v17;
        if (number - 1 == i)
          break;
        v14 = v6[6];
      }
    }
    v20 = v57;
    v21 = 0;
    v22 = 0;
    do
    {
      v24 = v6[6];
      v26 = *(v24 + 32);
      use = pParam->attach->use;
      if (use->m_Items[v21])
      {
        v30 = v20->m_Items[v21];
        if (v21 > 1)
        {
          v31 = 6;
        }
        else
        {
          v31 = 0;
        }
        v32 = dds3EffectPartCreate(v31, v30, 0, 0);
        v33 = v32;
        *&v26[2 * v22 + 8] = v33;
        hEffPartSrc = v33;
        if (number >= 2)
        {
          v36 = 0;
          do
          {
            v38 = v6[6];
            v40 = *(v38 + 8 * v36 + 40);
            v41 = dds3EffectPartCopy(&hEffPartSrc, 0, 0);
            v42 = v41;
            ++v36;
            *&v40[2 * v22 + 8] = v42;
          }
          while (number - 1 != v36);
        }
        v20 = v57;
        ++v22;
      }
      ++v21;
    }
    while (v21 != 4);
  }
  if (number)
  {
    v44 = 4;
    do
    {
      v47 = v6[3];
      v48 = v44 - 4;
      v49 = Allocate(effPCPRadiateThunderPart_tag);
      _ctor(v49, 0);
      *&v47[2 * v44] = v49;
      v51 = v6[3];
      v53 = *(v51 + 8 * v44);
      hData = pParam->ThunderParam;
      *(v53 + 16) = effPCP_ThunderPolyCreate(&hData, 0, 1, 0);
      *(v53 + 24) = 0;
      v54 = v6[3];
      *&v54[2 * v44++] = v53;
    }
    while (v44 - number != 4);
  }
  return v6;
}

// 0x1183c10
effPCPRadiateThunder_tag *effPCPRadiateThunderCreatePCF(void **hData, s32 bPos, bool tbldata) {
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
  effPCPRadiateThunderParam_t_o *v18;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v21;
  s64 *v22;
  u32 *v25;
  u64 i;
  struct System_Byte_array *use;
  struct dds3EffectPCPData_Part_t_array *v29;
  Il2CppObject *v30;
  u64 v31;
  u32 v33;
  s64 *EffPCPAgiFireballPart;
  s64 *v35;
  u32 *v37;
  u32 *v39;
  s32 pos;
  u64 v43[2];
  char *v44;

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v7->klass->_1.element_class, v8, v43);
      if ((v43[0] & 1) != 0)
        v10 = v44;
      else
        v10 = v43 + 1;
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
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 22);
  v18 = DataUnityOffSet;
  if (DataUnityOffSet)
  {
    klass = DataUnityOffSet->klass;
    if (DataUnityOffSet->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRadiateThunderParam_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPRadiateThunderParam_t, v43);
      if ((v43[0] & 1) != 0)
        v21 = v44;
      else
        v21 = v43 + 1;
      v22 = sub_8C4940(v21);
    }
  }
  v25 = NewSpecific(object, 4u);
  for (i = 0; i != 4; ++i)
  {
    while (1)
    {
      use = v18->attach->use;
      if (!use->m_Items[i])
        break;
      v29 = v6->pcpData;
      v30 = *hData;
      v31 = i + 1;
      v33 = v29->m_Items[v31]->offset;
      EffPCPAgiFireballPart = GetEffPCPAgiFireballPart(v30, v33 + bPos);
      v35 = EffPCPAgiFireballPart;
      v37 = &v25[2 * i++];
      *(v37 + 4) = v35;
      if (v31 == 4)
        goto LABEL_42;
    }
    v39 = &v25[2 * i];
    *(v39 + 4) = 0;
  }
LABEL_42:
  return effPCPRadiateThunderCreate(v18, v25);
}

// 0x1184370
void effPCPRadiateThunderDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s64 typeDefinition_low;
  u64 i;
  u64 *monitor;
  Il2CppClass *v13;
  s64 v14;
  s64 v15;
  u64 v16;
  s64 v18;
  Il2CppClass *v19;
  s64 v20;
  Il2CppClass *v21;
  s64 v22;
  Il2CppClass *v23;
  s64 v28;
  Il2CppObject *hDataa;
  effPartHandle_t_o *hEffPart;
  u64 v34[3];

  hDataa = 0;
  hEffPart = 0;
  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRadiateThunder_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPRadiateThunder_tag, v34);
      if ((v34[0] & 1) != 0)
        v6 = v34[2];
      else
        v6 = v34 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  typeDefinition_low = LODWORD(v3[1].klass->_1.typeDefinition);
  if (typeDefinition_low)
  {
    for (i = 0; i != typeDefinition_low; ++i)
    {
      monitor = v3[1].monitor;
      hDataa = *(monitor[i + 4] + 16LL);
      effPCP_ThunderPolyDelete(&hDataa);
    }
    v13 = v3[3].klass;
    if (v13)
    {
      v14 = 1 - typeDefinition_low;
      v15 = 4;
      v16 = 0;
      if (!LODWORD(v13->_1.namespaze))
      {
LABEL_19:
      }
      while (1)
      {
        v18 = *(&v13->_1.image + v15);
        hEffPart = *(v18 + 32);
        if (hEffPart)
        {
          dds3EffectPartDelete(&hEffPart);
        }
        v19 = v3[3].klass;
        v20 = *(&v19->_1.image + v15);
        hEffPart = *(v20 + 40);
        if (hEffPart)
        {
          dds3EffectPartDelete(&hEffPart);
        }
        v21 = v3[3].klass;
        v22 = *(&v21->_1.image + v15);
        hEffPart = *(v22 + 48);
        if (hEffPart)
        {
          dds3EffectPartDelete(&hEffPart);
          v23 = v3[3].klass;
          if (v16 >= LODWORD(v23->_1.namespaze))
          {
LABEL_54:
          }
        }
        else
        {
          v23 = v3[3].klass;
          if (v16 >= LODWORD(v23->_1.namespaze))
            goto LABEL_54;
        }
        v28 = *(&v23->_1.image + v15);
        hEffPart = *(v28 + 56);
        if (hEffPart)
        {
          dds3EffectPartDelete(&hEffPart);
        }
        if (v14 + v15 == 4)
          break;
        v13 = v3[3].klass;
        v16 = ++v15 - 4;
        if (v15 - 4 >= LODWORD(v13->_1.namespaze))
          goto LABEL_19;
      }
    }
  }
}

// 0x1184910
void effPCPRadiateThunderDraw(void **hData) {
  effPCPRadiateThunder_tag_o *v3;
  effPCPRadiateThunder_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  struct effPCPRadiateThunderParam_t_o *param;
  f32 radian_a;
  s32 life;
  s64 number;
  f32 spread_e;
  f32 spread_s;
  f32 v16;
  u64 v17;
  effPartHandle_t_array *v18;
  struct effPCPRadiateThunderPart_tag_array *pPart;
  effPCPRadiateThunderPart_tag_o *v21;
  struct effPartHandle_t_array_array *phAttach;
  s32 frame;
  struct effPCPRadiateThunderPart_tag_array *v25;
  f32 radian;
  effPCP_ThunderPoly_t_o *pThunderPoly;
  f32 v29;
  f32 radian_s;
  effPCP_ThunderPolyParam_t_o *v31;
  struct UnityEngine_Vector4_array *pos;
  struct UnityEngine_Vector4_array *v34;
  struct UnityEngine_Vector4_array *v36;
  struct UnityEngine_Vector4_array *v38;
  struct UnityEngine_Vector4_array *v40;
  struct UnityEngine_Vector4_array *v42;
  f32 v44;
  u32 v45;
  u64 v46;
  effPartHandle_t_o **m_Items;
  f32 *v49;
  f32 v51;
  f32 v52;
  f32 v53;
  f32 v54;
  s32 v58;
  s32 v60;
  f32 v61;
  s32 fade_out;
  u32 abgr1;
  s32 fade_in;
  s64 v65;
  s32 loop;
  s32 v67;
  Il2CppObject *hDataa;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o dst;
  s64 v71;
  s64 v72;
  effPCPRadiateThunder_tag_o *pRadiateThunder;
  u64 v74[4];
  UnityEngine_Vector4_o v75;

  v72 = 0;
  pRadiateThunder = 0;
  *&dst.z = 0;
  v71 = 0;
  *&p.z = 0;
  *&dst.x = 0;
  hDataa = 0;
  *&p.x = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRadiateThunder_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPRadiateThunder_tag, v74);
      if ((v74[0] & 1) != 0)
        v6 = v74[2];
      else
        v6 = v74 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v72 = 0;
  pRadiateThunder = v3;
  *&dst.z = 0;
  v71 = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&dst.x = 0;
  param = v3->param;
  radian_a = param->radian_a;
  life = param->life;
  number = param->number;
  loop = param->loop;
  fade_in = param->fade_in;
  fade_out = param->fade_out;
  spread_s = param->spread_s;
  spread_e = param->spread_e;
  abgr1 = v3->abgr;
  SDF_VU0__COPYVECTOR(&dst, param->pos);
  if (life && number)
  {
    v61 = spread_e - spread_s;
    v16 = life;
    v17 = 0;
    v18 = 0;
    v67 = life;
    v65 = number;
    do
    {
      pPart = v3->pPart;
      v21 = pPart->m_Items[v17];
      hDataa = v21->pThunderPoly;
      phAttach = v3->phAttach;
      if (phAttach)
      {
        v18 = phAttach->m_Items[v17];
      }
      frame = v21->frame;
      if (frame > life)
        goto LABEL_76;
      if (frame)
      {
        if ((frame & 0x80000000) == 0)
          goto LABEL_29;
      }
      else
      {
        effPCPRadiateThunderPartInit(&pRadiateThunder, v17);
        v25 = v3->pPart;
        v21 = v25->m_Items[v17];
        frame = v21->frame;
        if ((frame & 0x80000000) == 0)
        {
LABEL_29:
          radian = v21->radian;
          sdfCos(radian);
          sdfSin(radian);
          sub_854710(&dst, 0);
          sub_854930(&v71, 0);
          sub_854710(&dst, 1u);
          sub_854930(&v71, 1u);
          sub_854710(&dst, 2u);
          sub_854930(&v71, 2u);
          pThunderPoly = v21->pThunderPoly;
          v29 = v21->radian;
          radian_s = v21->radian_s;
          v21->radius = v21->radius + v21->radius_s;
          v21->radian = v29 + radian_s;
          v21->radian_s = radian_a * radian_s;
          v31 = effPCP_ThunderPolyGetParam(pThunderPoly);
          sub_854930(&p, 0);
          sdfFabs(spread_s + (v61 * (frame / v16)), 0);
          sub_854930(&p, 1u);
          sub_854930(&p, 2u);
          SDF_VU0__LOADVECTOR(p);
          SDF_VU0__NORMALIZE();
          SDF_VU0__STOREVECTOR(&p);
          pos = v31->pos;
          sub_854710(&v71, 0);
          sub_854710(&p, 0);
          sub_854930(pos->m_Items, 0);
          v34 = v31->pos;
          sub_854710(&v71, 1u);
          sub_854710(&p, 1u);
          sub_854930(v34->m_Items, 1u);
          v36 = v31->pos;
          sub_854710(&v71, 2u);
          sub_854710(&p, 2u);
          sub_854930(v36->m_Items, 2u);
          v38 = v31->pos;
          sub_854710(&v71, 0);
          sub_854930(&v38->m_Items[1], 0);
          v40 = v31->pos;
          sub_854710(&v71, 1u);
          sub_854930(&v40->m_Items[1], 1u);
          v42 = v31->pos;
          sub_854710(&v71, 2u);
          sub_854930(&v42->m_Items[1], 2u);
          if (fade_in && frame < fade_in)
          {
            v44 = frame / fade_in;
          }
          else
          {
            v44 = 1.0;
            if (fade_out)
            {
              v44 = 1.0;
              if (v67 - frame <= fade_out)
                v44 = (v67 - frame) / fade_out;
            }
          }
          v45 = effColorBlend(abgr1 & 0xFFFFFF, abgr1, v44);
          hDataa = v21->pThunderPoly;
          effPCP_ThunderPolySetColor(&hDataa, v45);
          hDataa = v21->pThunderPoly;
          effPCP_ThunderPolyDraw(&hDataa);
          if (v18)
          {
            v46 = 0;
            m_Items = v18->m_Items;
            do
            {
              if (*m_Items)
              {
                v49 = v31->pos;
                v51 = v49[12];
                v52 = v49[13];
                v53 = v49[14];
                v54 = v49[15];
                else if (v46 >= LODWORD(v18->max_length))
                {
LABEL_62:
                }
                v75.x = v51;
                v75.y = v52;
                v75.z = v53;
                v75.w = v54;
                dds3EffectPartSetPosition(m_Items, v75);
                dds3EffectPartSetColor(m_Items, v45);
                dds3EffectPartDraw(m_Items);
              }
              ++v46;
              ++m_Items;
            }
            while (v46 != 4);
          }
        }
      }
      v58 = v21->frame;
      life = v67;
      number = v65;
      if (v58 < v67 || loop == 0)
        v60 = v58 + 1;
      else
        v60 = 0;
      v21->frame = v60;
LABEL_76:
      ++v17;
    }
    while (v17 != number);
  }
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
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRadiateThunder_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPRadiateThunder_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[2].monitor) = abgr;
}

// 0x11850f0
void effPCPRadiateThunderSetPosition(void **hData, sdfVector4_t pPos) {
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
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRadiateThunder_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPRadiateThunder_tag, v12);
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

// 0x1185210
void effPCPRadiateThunderSetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRadiateThunder_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPRadiateThunder_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *&(*hData)[2].klass = scale;
}

// 0x1182de0
effPCPRingPolyExp2_tag *effPCPRingPolyExp2Copy(void **hData, s32 bPos, bool tbldata) {
  effPCPRingPolyExp2_tag_c *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  Il2CppClass *v11;
  u64 v12[3];

  v11 = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRingPolyExp2_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPRingPolyExp2_tag, v12);
    if ((v12[0] & 1) != 0)
      v9 = v12[2];
    else
      v9 = v12 + 1;
    v10 = sub_8C4940(v9);
  }
  v11 = (*hData)[1].klass;
  return effPCPRingPolyExp2Create(&v11, v5);
}

// 0x1182930
effPCPRingPolyExp2_tag *effPCPRingPolyExp2Create(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  u32 monitor_high;
  dds3RingPolyExpList_tag_o *v11;
  s32 v13;
  struct System_UInt32_array *pVC;
  u64 v15;
  u64 max_length_low;
  u32 *v18;
  u64 v19;
  s32 v20;
  u64 v22;
  effPCPRingPolyExp2_tag_o *v26[3];
  effPCPRingPolyExp2_tag_o *pPCPRingPolyExp2;

  pPCPRingPolyExp2 = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRingPolyExp2Param_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPRingPolyExp2Param_t, v26);
      if ((v26[0] & 1) != 0)
        v6 = v26[2];
      else
        v6 = v26 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = Allocate(effPCPRingPolyExp2_tag);
  _ctor(v8, 0);
  pPCPRingPolyExp2 = v8;
  v8[2] = v3;
  v8[3] = 0x8080808000000000LL;
  monitor_high = HIDWORD(v3[4].monitor);
  if (monitor_high <= 2)
  {
    monitor_high = 3;
    HIDWORD(v3[4].monitor) = 3;
  }
  v11 = dds3RingPolyExpListCreate(monitor_high);
  v8[7] = v11;
  v13 = v11->point >> 2;
  if (v13)
  {
    pVC = v11->pVC;
    v15 = 0;
    do
    {
      max_length_low = LODWORD(pVC->max_length);
      v18 = (pVC + 4 * v15);
      v19 = v15 + 2;
      v18[8] = v3[5].monitor;
      v20 = v3[6].klass;
      v22 = v19 - 1;
      v18[10] = v20;
      v18[9] = v20;
      --v13;
      v15 = v22 + 3;
      v18[11] = v3[6].monitor;
    }
    while (v13);
  }
  effPCPRingPolyExp2Init(&pPCPRingPolyExp2);
  *(v8[7] + 164) = v3[5].klass;
  return v8;
}

// 0x11828b0
effPCPRingPolyExp2_tag *effPCPRingPolyExp2CreateP(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject **v5;

  else
  {
    v5 = hData;
  }
  return effPCPRingPolyExp2Create(v5, *&bPos);
}

// 0x1182ba0
effPCPRingPolyExp2_tag *effPCPRingPolyExp2CreatePCF(void **hData, s32 bPos, bool tbldata) {
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
  effPCPRingPolyExp2Param_t_c *v18;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v21;
  s64 *v22;
  Il2CppObject *v24;
  u64 v25[2];
  char *v26;
  s32 pos;

  pos = bPos;
  v24 = 0;
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
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 21);
  if (DataUnityOffSet)
  {
    klass = DataUnityOffSet->klass;
    if (DataUnityOffSet->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRingPolyExp2Param_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPRingPolyExp2Param_t, v25);
      if ((v25[0] & 1) != 0)
        v21 = v26;
      else
        v21 = v25 + 1;
      v22 = sub_8C4940(v21);
    }
  }
  v24 = DataUnityOffSet;
  return effPCPRingPolyExp2Create(&v24, v18);
}

// 0x1182f00
void effPCPRingPolyExp2Delete(void **hData) {
  effPCPRingPolyExp2_tag_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppObject *monitor;
  u64 v9[3];

  monitor = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRingPolyExp2_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPRingPolyExp2_tag, v9);
    if ((v9[0] & 1) != 0)
      v6 = v9[2];
    else
      v6 = v9 + 1;
    v7 = sub_8C4940(v6);
  }
  monitor = (*hData)[3].monitor;
  dds3RingPolyExpListDelete(&monitor, v3);
}

// 0x1183020
void effPCPRingPolyExp2Draw(void **hData) {
  effPCPRingPolyExp2_tag_o *v3;
  effPCPRingPolyExp2_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  struct effPCPRingPolyExp2Param_t_o *param;
  s32 frame;
  s32 life;
  s32 v11;
  s32 fade_out;
  s32 fade_in;
  f32 v14;
  f32 v15;
  f32 v16;
  f32 v17;
  struct dds3RingPolyExpList_tag_o *hPoly;
  Il2CppObject *v20;
  effPCPRingPolyExp2_tag_o *v21[3];
  effPCPRingPolyExp2_tag_o *pPCPRingPolyExp2;

  pPCPRingPolyExp2 = 0;
  v20 = 0;
  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRingPolyExp2_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPRingPolyExp2_tag, v21);
      if ((v21[0] & 1) != 0)
        v6 = v21[2];
      else
        v6 = v21 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  pPCPRingPolyExp2 = v3;
  param = v3->param;
  frame = v3->frame;
  life = param->life;
  v11 = life - frame;
  if (life >= frame)
  {
    fade_in = param->fade_in;
    fade_out = param->fade_out;
    v14 = v3->radius + v3->radius_s;
    v3->radius = v14;
    effPCPRingPolyExp2SetVertex(&pPCPRingPolyExp2, v14);
    v3->radius_s = v3->radius_s * v3->param->radius_a;
    if (frame < fade_in && fade_in)
    {
      v15 = frame;
      v16 = fade_in;
    }
    else
    {
      v17 = 1.0;
      if (v11 > fade_out || !fade_out)
        goto LABEL_21;
      v15 = v11;
      v16 = fade_out;
    }
    v17 = v15 / v16;
LABEL_21:
    hPoly = v3->hPoly;
    hPoly->abgr = effColorBlend(v3->abgr & 0xFFFFFF, v3->abgr, v17);
    SDF_VU0__COPYVECTOR(&v3->hPoly->pos, v3->param->pos);
    v20 = v3->hPoly;
    dds3RingPolyExpListDraw(&v20);
    ++v3->frame;
  }
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
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRingPolyExp2_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPRingPolyExp2_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[1].monitor) = abgr;
}

// 0x1183230
void effPCPRingPolyExp2SetPosition(void **hData, sdfVector4_t pPos) {
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
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRingPolyExp2_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPRingPolyExp2_tag, v12);
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

// 0x1183540
void effPCPRingPolyExp2SetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
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
  klass = v7->klass;
  if (v7->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRingPolyExp2_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPRingPolyExp2_tag, v17);
    if ((v17[0] & 1) != 0)
      v14 = v17[2];
    else
      v14 = v17 + 1;
    v15 = sub_8C4940(v14);
  }
  SDF_VU0__STOREMATRIX((v7[3].monitor + 80), 0);
}

// 0x1183350
void effPCPRingPolyExp2SetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRingPolyExp2_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPRingPolyExp2_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *((*hData)[3].monitor + 40) = scale;
}

// 0x1181f60
void effPCPRingPolyExp2SetVertex(effPCPRingPolyExp2_tag **pPCPRingPolyExp2, f32 radius) {
  u64 v3;
  u64 *v5;
  u64 *v6;
  s32 v27;
  struct effPCPRingPolyExp2Param_t_o *param;
  f32 rotate_z;
  f32 x;
  f32 y;
  f32 z;
  f32 w;
  effPCPRingPolyExp2_tag_o *v40;
  struct UnityEngine_Vector4_array *pVertex;
  UnityEngine_Vector4_o *v42;
  f32 v43;
  f32 v44;
  f32 v45;
  u64 v46;
  s32 i;
  u64 v51;
  u64 v54;
  u64 v57;
  UnityEngine_Vector4_o v63;
  u64 v64;
  UnityEngine_Vector4_o v65;
  UnityEngine_Vector4_o dds3CameraTargetPos;
  UnityEngine_Vector4_o v67;

  *&v63.x = 0;
  *&v63.z = 0;
  v5 = NewSpecific(UnityEngine_Vector4, 4u);
  v6 = v5;
  sub_854930((v5 + 4), 0);
  sub_854710((v6 + 4), 0);
  sub_854930((v6 + 4), 1u);
  sub_854930((v6 + 4), 2u);
  sub_854710((v6 + 4), 0);
  sub_854930((v6 + 6), 0);
  sub_854710((v6 + 6), 0);
  sub_854930((v6 + 6), 1u);
  sub_854930((v6 + 6), 2u);
  sub_854710((v6 + 6), 0);
  sub_854930((v6 + 8), 0);
  sub_854710((v6 + 8), 0);
  sub_854930((v6 + 8), 1u);
  sub_854930((v6 + 8), 2u);
  sub_854710((v6 + 8), 0);
  sub_854930((v6 + 10), 0);
  sub_854710((v6 + 10), 0);
  sub_854930((v6 + 10), 1u);
  sub_854930((v6 + 10), 2u);
  v27 = (*pPCPRingPolyExp2)->hPoly->point >> 2;
  param = (*pPCPRingPolyExp2)->param;
  LODWORD(v3) = param->split;
  if (param->type)
  {
    rotate_z = (*pPCPRingPolyExp2)->rotate_z;
    SetRotateMatrixZ(rotate_z);
    SetRotateMatrixY_B((*pPCPRingPolyExp2)->rotate_y, 0);
    MultMatrixRevNoArg();
    (*pPCPRingPolyExp2)->rotate_y = (*pPCPRingPolyExp2)->rotate_y + (*pPCPRingPolyExp2)->rotate_s;
    (*pPCPRingPolyExp2)->rotate_s = (*pPCPRingPolyExp2)->rotate_s
                                         * (*pPCPRingPolyExp2)->param->rotate_a;
    if (!v27)
      return;
LABEL_54:
    v40 = *pPCPRingPolyExp2;
    pVertex = (*pPCPRingPolyExp2)->hPoly->pVertex;
    v42 = &pVertex->m_Items[3];
    v43 = v3;
    v44 = 6.2832 / v43;
    v45 = 0.0;
    v46 = 0;
    for (i = v27 - 1; ; --i)
    {
      if (v40->param->type)
      {
        sdfCos(v45);
        sub_854930(&v63, 0);
        sub_854930(&v63, 1u);
        sdfSin(v45);
      }
      else
      {
        sdfCos(v45);
        sub_854930(&v63, 0);
        sdfSin(v45);
        sub_854930(&v63, 1u);
      }
      sub_854930(&v63, 2u);
      sub_854930(&v63, 3u);
      SDF_VU0__LOADVECTOR(v63);
      SDF_VU0__APPLYMATRIX();
      SDF_VU0__COPYVECTOR_A_TO_B();
      SDF_VU0__LOADVECTOR(*(v6 + 2), 0);
      SDF_VU0__MULVECTOR();
      SDF_VU0__STOREVECTOR(v42 - 3);
      SDF_VU0__LOADVECTOR(*(v6 + 3), 0);
      SDF_VU0__MULVECTOR();
      v51 = v46 + 1;
      SDF_VU0__STOREVECTOR(v42 - 2);
      SDF_VU0__LOADVECTOR(*(v6 + 4), 0);
      SDF_VU0__MULVECTOR();
      v54 = v51 + 1;
      SDF_VU0__STOREVECTOR(v42 - 1);
      SDF_VU0__LOADVECTOR(*(v6 + 5), 0);
      SDF_VU0__MULVECTOR();
      v57 = v54 + 1;
      SDF_VU0__STOREVECTOR(v42);
      if (!i)
        break;
      v40 = *pPCPRingPolyExp2;
      v45 = v44 + v45;
      v42 += 4;
      v46 = v57 + 1;
    }
    return;
  }
  v64 = v3;
  x = dds3CameraEyePos.x;
  y = dds3CameraEyePos.y;
  z = dds3CameraEyePos.z;
  w = dds3CameraEyePos.w;
  v67.x = x;
  v67.y = y;
  v67.z = z;
  v67.w = w;
  *&v65.x = 0;
  LookAtMatrix(dds3CameraTargetPos, v67, v65);
  ReverseMatrix();
  v3 = v64;
  if (v27)
    goto LABEL_54;
}

// 0x11814f0
effPCPRingPolyExp_tag *effPCPRingPolyExpCopy(void **hData, s32 bPos, bool tbldata) {
  effPCPRingPolyExp_tag_c *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v8;
  char *v10;
  s64 *v11;
  u64 v12[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRingPolyExp_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPRingPolyExp_tag, v12);
    if ((v12[0] & 1) != 0)
      v10 = v12[2];
    else
      v10 = v12 + 1;
    v11 = sub_8C4940(v10);
  }
  v8 = (*hData)[1].klass;
  return effPCPRingPolyExpCreate(v8, v5);
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
LABEL_23:
  v20 = *(v3[2] + 56);
  effPCPRingPolyExpSetVertex(&pPCPRingPolyExp, v20);
  *(v3 + 6) = 0;
  *(v3[5] + 164) = pParam->blend;
  return v3;
}

// 0x1180f60
effPCPRingPolyExp_tag *effPCPRingPolyExpCreateP(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v11[3];

  v5 = *hData;
  else if (!v5)
  {
    return effPCPRingPolyExpCreate(v5, *&bPos);
  }
  klass = v5->klass;
  if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRingPolyExpParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPRingPolyExpParam_t, v11);
    if ((v11[0] & 1) != 0)
      v8 = v11[2];
    else
      v8 = v11 + 1;
    v9 = sub_8C4940(v8);
  }
  return effPCPRingPolyExpCreate(v5, *&bPos);
}

// 0x11812b0
effPCPRingPolyExp_tag *effPCPRingPolyExpCreatePCF(void **hData, s32 bPos, bool tbldata) {
  dds3EffectPCPData_t_o *v6;
  Il2CppObject *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  struct dds3EffectPCPData_Part_t_array *pcpData;
  Il2CppObject *v14;
  u32 offset;
  effPCPRingPolyExpParam_t_c *v17;
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
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 20);
  else if (!DataUnityOffSet)
  {
    return effPCPRingPolyExpCreate(DataUnityOffSet, v17);
  }
  klass = DataUnityOffSet->klass;
  if (DataUnityOffSet->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRingPolyExpParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPRingPolyExpParam_t, v24);
    if ((v24[0] & 1) != 0)
      v21 = v25;
    else
      v21 = v24 + 1;
    v22 = sub_8C4940(v21);
  }
  return effPCPRingPolyExpCreate(DataUnityOffSet, v17);
}

// 0x1181600
void effPCPRingPolyExpDelete(void **hData) {
  effPCPRingPolyExp_tag_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppObject *monitor;
  u64 v9[3];

  monitor = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRingPolyExp_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPRingPolyExp_tag, v9);
    if ((v9[0] & 1) != 0)
      v6 = v9[2];
    else
      v6 = v9 + 1;
    v7 = sub_8C4940(v6);
  }
  monitor = (*hData)[2].monitor;
  dds3RingPolyExpListDelete(&monitor, v3);
}

// 0x1181720
void effPCPRingPolyExpDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppClass *v8;
  s32 data_high;
  s32 v10;
  s32 monitor;
  signed s32 v12;
  s32 v13;
  s32 v14;
  s32 data;
  f32 v16;
  f32 v17;
  s32 v18;
  s32 v19;
  Il2CppClass *v20;
  s32 v21;
  f32 v23;
  f32 v24;
  f32 v25;
  f32 v26;
  u32 *v27;
  Il2CppObject *hDataa;
  effPCPRingPolyExp_tag_o *pPCPRingPolyExp;
  u64 v31[3];

  hDataa = 0;
  pPCPRingPolyExp = 0;
  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRingPolyExp_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPRingPolyExp_tag, v31);
      if ((v31[0] & 1) != 0)
        v6 = v31[2];
      else
        v6 = v31 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  pPCPRingPolyExp = v3;
  v8 = v3[1].klass;
  data_high = HIDWORD(v8->_1.this_arg.data);
  v10 = *(&v8->_1.byval_arg.bits + 1);
  monitor = v3[1].monitor;
  if (data_high <= v10)
    data_high = *(&v8->_1.byval_arg.bits + 1);
  v12 = v8->_1.byval_arg.bits + data_high;
  v13 = v12 - monitor;
  if (v12 >= monitor)
  {
    data = v8->_1.byval_arg.data;
    v14 = HIDWORD(v8->_1.byval_arg.data);
    if (monitor >= v10)
    {
      v19 = v3[2].klass;
    }
    else
    {
      v16 = (LODWORD(v3[2].klass) >> 2);
      v17 = (monitor / v10) * v16;
      v18 = v17;
      if (v17 >= 0.0)
        v18 = v17;
      v19 = 4 * v18;
    }
    *(v3[2].monitor + 43) = v19;
    v20 = v3[1].klass;
    v21 = HIDWORD(v20->_1.this_arg.data);
    if (monitor >= v21)
    {
      v23 = *(&v20->_1.this_arg.bits + 1);
        goto LABEL_23;
    }
    else
    {
      v23 = *&v20->_1.this_arg.bits
          + ((SLODWORD(v3[1].monitor) / v21) * (*(&v20->_1.this_arg.bits + 1) - *&v20->_1.this_arg.bits));
        goto LABEL_23;
    }
LABEL_23:
    effPCPRingPolyExpSetVertex(&pPCPRingPolyExp, v23);
    if (monitor < data && data)
    {
      v24 = monitor;
      v25 = data;
    }
    else
    {
      v26 = 1.0;
      if (v13 > v14 || !v14)
        goto LABEL_30;
      v24 = v13;
      v25 = v14;
    }
    v26 = v24 / v25;
LABEL_30:
    v27 = v3[2].monitor;
    v27[42] = effColorBlend(HIDWORD(v3[1].monitor) & 0xFFFFFF, HIDWORD(v3[1].monitor), v26, 0);
    SDF_VU0__COPYVECTOR(v3[2].monitor + 9, *&v3[1].klass->_1.name);
    hDataa = v3[2].monitor;
    dds3RingPolyExpListDraw(&hDataa);
    ++LODWORD(v3[1].monitor);
  }
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
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRingPolyExp_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPRingPolyExp_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[1].monitor) = abgr;
}

// 0x1181e00
void effPCPRingPolyExpSetDirection(void **hData, sdfMatrix4_t *pMatrix) {
  s64 v5;
  s64 v6;
  Il2CppObject *v7;
  s64 v8;
  s64 v9;
  s64 v10;
  s64 v11;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v15;
  s64 *v16;
  UnityEngine_Matrix4x4_o v17;
  u64 v18[3];

  v5 = *&pMatrix->m00;
  v6 = *&pMatrix->m20;
  v7 = *hData;
  v8 = *&pMatrix->m21;
  *&v17.m01 = *&pMatrix->m01;
  *&v17.m21 = v8;
  *&v17.m00 = v5;
  *&v17.m20 = v6;
  v9 = *&pMatrix->m02;
  v10 = *&pMatrix->m22;
  v11 = *&pMatrix->m23;
  *&v17.m03 = *&pMatrix->m03;
  *&v17.m23 = v11;
  *&v17.m02 = v9;
  *&v17.m22 = v10;
  SDF_VU0__LOADMATRIX(&v17);
  SetRotateMatrixX_B(1.5708);
  MultMatrixNoArg();
  klass = v7->klass;
  if (v7->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRingPolyExp_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPRingPolyExp_tag, v18);
    if ((v18[0] & 1) != 0)
      v15 = v18[2];
    else
      v15 = v18 + 1;
    v16 = sub_8C4940(v15);
  }
  SDF_VU0__STOREMATRIX((v7[2].monitor + 16), 0);
}

// 0x11819c0
void effPCPRingPolyExpSetPosition(void **hData, sdfVector4_t pPos) {
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
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRingPolyExp_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPRingPolyExp_tag, v12);
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

// 0x1181cd0
void effPCPRingPolyExpSetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
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
  klass = v7->klass;
  if (v7->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRingPolyExp_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPRingPolyExp_tag, v17);
    if ((v17[0] & 1) != 0)
      v14 = v17[2];
    else
      v14 = v17 + 1;
    v15 = sub_8C4940(v14);
  }
  SDF_VU0__STOREMATRIX((v7[2].monitor + 80), 0);
}

// 0x1181ae0
void effPCPRingPolyExpSetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRingPolyExp_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPRingPolyExp_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *((*hData)[2].monitor + 40) = scale;
}

// 0x1180850
void effPCPRingPolyExpSetVertex(effPCPRingPolyExp_tag **pPCPRingPolyExp, f32 radius) {
  u64 v3;
  u64 *v5;
  u64 *v6;
  struct dds3RingPolyExpList_tag_o *hPoly;
  f32 v27;
  struct UnityEngine_Vector4_array *pVertex;
  s32 v29;
  UnityEngine_Vector4_o *v31;
  f32 v32;
  f32 v33;
  u64 v34;
  u64 v38;
  u64 v41;
  u64 v44;
  UnityEngine_Vector4_o v46;

  *&v46.x = 0;
  *&v46.z = 0;
  v5 = NewSpecific(UnityEngine_Vector4, 4u);
  v6 = v5;
  sub_854930((v5 + 4), 0);
  sub_854710((v6 + 4), 0);
  sub_854930((v6 + 4), 1u);
  sub_854930((v6 + 4), 2u);
  sub_854710((v6 + 4), 0);
  sub_854930((v6 + 6), 0);
  sub_854710((v6 + 6), 0);
  sub_854930((v6 + 6), 1u);
  sub_854930((v6 + 6), 2u);
  sub_854710((v6 + 6), 0);
  sub_854930((v6 + 8), 0);
  sub_854710((v6 + 8), 0);
  sub_854930((v6 + 8), 1u);
  sub_854930((v6 + 8), 2u);
  sub_854710((v6 + 8), 0);
  sub_854930((v6 + 10), 0);
  sub_854710((v6 + 10), 0);
  sub_854930((v6 + 10), 1u);
  sub_854930((v6 + 10), 2u);
  hPoly = (*pPCPRingPolyExp)->hPoly;
  v27 = 0.0;
  LODWORD(v3) = (*pPCPRingPolyExp)->param->split;
  pVertex = hPoly->pVertex;
  v29 = hPoly->point >> 2;
  sub_854930(&v46, 1u);
  if (v29)
  {
    v31 = &pVertex->m_Items[3];
    v32 = v3;
    v33 = 6.2832 / v32;
    v34 = 0;
    do
    {
      sdfCos(v27);
      sub_854930(&v46, 0);
      sdfSin(v27);
      sub_854930(&v46, 2u);
      SDF_VU0__LOADVECTOR_B(v46);
      SDF_VU0__LOADVECTOR(*(v6 + 2), 0);
      SDF_VU0__MULVECTOR();
      SDF_VU0__STOREVECTOR(v31 - 3);
      SDF_VU0__LOADVECTOR(*(v6 + 3), 0);
      SDF_VU0__MULVECTOR();
      v38 = v34 + 1;
      SDF_VU0__STOREVECTOR(v31 - 2);
      SDF_VU0__LOADVECTOR(*(v6 + 4), 0);
      SDF_VU0__MULVECTOR();
      v41 = v38 + 1;
      SDF_VU0__STOREVECTOR(v31 - 1);
      SDF_VU0__LOADVECTOR(*(v6 + 5), 0);
      SDF_VU0__MULVECTOR();
      v44 = v41 + 1;
      SDF_VU0__STOREVECTOR(v31);
      v27 = v33 + v27;
      v31 += 4;
      --v29;
      v34 = v44 + 1;
    }
    while (v29);
  }
}

// 0x116f470
effPCPRippleBlurExp_tag *effPCPRippleBlurExpCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  effPCPRippleBlurExpParam_t_o *v10;
  u64 v13[3];

  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRippleBlurExp_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPRippleBlurExp_tag, v13);
      if ((v13[0] & 1) != 0)
        v8 = v13[2];
      else
        v8 = v13 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = Allocate(effPCPRippleBlurExpParam_t);
  effPCPRippleBlurExpParam_t___ctor(v10);
  v10->type = v5[2].klass;
  v10->life = HIDWORD(v5[2].klass);
  v10->fade_in = v5[2].monitor;
  v10->fade_out = HIDWORD(v5[2].monitor);
  v10->area_s = v5[3].monitor;
  v10->area_e = HIDWORD(v5[3].monitor);
  v10->RippleBlur = *(v5[4].monitor + 2);
  return effPCPRippleBlurExpCreate(v10);
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
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v11[3];

  v5 = *pData;
  else if (!v5)
  {
    return effPCPRippleBlurExpCreate(v5, *&bPos);
  }
  klass = v5->klass;
  if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRippleBlurExpParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPRippleBlurExpParam_t, v11);
    if ((v11[0] & 1) != 0)
      v8 = v11[2];
    else
      v8 = v11 + 1;
    v9 = sub_8C4940(v8);
  }
  return effPCPRippleBlurExpCreate(v5, *&bPos);
}

// 0x116f230
effPCPRippleBlurExp_tag *effPCPRippleBlurExpCreatePCF(void **hData, s32 bPos, bool tbldata) {
  dds3EffectPCPData_t_o *v6;
  Il2CppObject *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  struct dds3EffectPCPData_Part_t_array *pcpData;
  Il2CppObject *v14;
  u32 offset;
  effPCPRippleBlurExpParam_t_c *v17;
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
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 15);
  else if (!DataUnityOffSet)
  {
    return effPCPRippleBlurExpCreate(DataUnityOffSet, v17);
  }
  klass = DataUnityOffSet->klass;
  if (DataUnityOffSet->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRippleBlurExpParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPRippleBlurExpParam_t, v24);
    if ((v24[0] & 1) != 0)
      v21 = v25;
    else
      v21 = v24 + 1;
    v22 = sub_8C4940(v21);
  }
  return effPCPRippleBlurExpCreate(DataUnityOffSet, v17);
}

// 0x116f5e0
void effPCPRippleBlurExpDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  effRippleBlurHandle_t_o **p_monitor;
  u64 v9[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRippleBlurExp_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPRippleBlurExp_tag, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  p_monitor = &v3[4].monitor;
  dds3EffectRippleBlurDelete(p_monitor);
}

// 0x116f700
void effPCPRippleBlurExpDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s32 v8;
  s32 klass_high;
  s32 klass_low;
  void **p_monitor;
  s32 monitor_high;
  s32 monitor;
  s64 v14;
  f32 v15;
  s64 v16;
  f32 v17;
  f32 v18;
  s64 v19;
  s64 v21;
  u32 v23;
  s64 v24;
  UnityEngine_Vector4_o p;
  u64 v27[3];

  *&p.x = 0;
  *&p.z = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRippleBlurExp_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPRippleBlurExp_tag, v27);
      if ((v27[0] & 1) != 0)
        v6 = v27[2];
      else
        v6 = v27 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  *&p.x = 0;
  *&p.z = 0;
  v8 = v3[4].klass;
  klass_high = HIDWORD(v3[2].klass);
  klass_low = LOBYTE(v3[2].klass);
  if (v8 > klass_high)
  {
    if (klass_low != 2)
      return;
    LODWORD(v3[4].klass) = 0;
    dds3EffectRippleBlurReset(&v3[4].monitor);
    v8 = 0;
  }
  p_monitor = &v3[4].monitor;
  monitor = v3[2].monitor;
  monitor_high = HIDWORD(v3[2].monitor);
  *(*(v3[4].monitor + 2) + 56LL) = (SLODWORD(v3[3].monitor)
                                  + ((v8 * (HIDWORD(v3[3].monitor) - LODWORD(v3[3].monitor))) / klass_high));
  if ((klass_low | 2) == 2)
  {
    SDF_VU0__LOADVECTOR(v3[1]);
    effScreenOffset();
    SDF_VU0__STOREVECTOR(&p);
    v14 = *(v3[4].monitor + 2);
    sub_854710(&p, 0);
    *(v14 + 60) = (v15 + 960.0) / 1920.0;
    v16 = *(v3[4].monitor + 2);
    sub_854710(&p, 1u);
    *(v16 + 64) = (v17 + 540.0) / 1080.0;
    *(*(v3[4].monitor + 2) + 68LL) = *(*(v3[4].monitor + 2) + 56LL) / 448.0;
    if (v8 >= monitor)
    {
LABEL_25:
      v18 = 1.0;
      if (klass_high - v8 <= monitor_high && monitor_high)
        v18 = (klass_high - v8) / monitor_high;
      goto LABEL_28;
    }
  }
  else
  {
    v19 = *(*(*(*p_monitor + 2) + 48LL) + 16LL);
    *(v19 + 32) = 0;
    v21 = *(*(*(*p_monitor + 2) + 48LL) + 16LL);
    *(v21 + 36) = 0;
    if (v8 >= monitor)
      goto LABEL_25;
  }
  if (!monitor)
    goto LABEL_25;
  v18 = v8 / monitor;
LABEL_28:
  v23 = effColorBlend(v3[3].klass & 0xFFFFFF, v3[3].klass, v18);
  v24 = *(v3[4].monitor + 2);
  *(v24 + 28) = effColorMultiply(v23, HIDWORD(v3[3].klass), 0);
  dds3EffectRippleBlurDraw(&v3[4].monitor, 1);
  ++LODWORD(v3[4].klass);
}

// 0x116fb90
void effPCPRippleBlurExpSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPRippleBlurExp_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPRippleBlurExp_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[3].klass) = abgr;
}

// 0x116fa60
void effPCPRippleBlurExpSetPosition(void **hData, sdfVector4_t pPos) {
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
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != effPCPRippleBlurExp_tag)
    {
      sub_8FC2C0(*(v9 + 64), effPCPRippleBlurExp_tag, v13);
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

// 0x1167e70
effPCPShockWave01_tag *effPCPShockWave01Copy(void **hData, s32 bPos, bool tbldata) {
  effPCPShockWave01_tag_o *v4;
  Il2CppObject *hDataa;

  v4 = Allocate(effPCPShockWave01_tag);
  _ctor(v4, 0);
LABEL_7:
  hDataa = 0;
  hDataa = effPCP_ShockWave01_ThunderSpherePoly_Param;
  v4->pThunderPoly = effPCPThunderSpherePolyCreate(&hDataa, 0, 0);
  v4->frame = 0;
  return v4;
}

// 0x1167ba0
effPCPShockWave01_tag *effPCPShockWave01Create(void **hData, s32 bPos, bool tbldata) {
  u64 *v5;
  s64 *v6;
  Il2CppClass *v7;
  s64 *Interface;
  char *v9;
  s64 *v10;
  effPCPShockWave01_tag_o *v11;
  Il2CppObject *hDataa[3];
  s32 pos;

  pos = bPos;
  v5 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v5);
  v6 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(v6, byte);
    if (!Interface)
    {
      sub_8FC2C0(*(*v6 + 64), v7, hDataa);
      if ((hDataa[0] & 1) != 0)
        v9 = hDataa[2];
      else
        v9 = hDataa + 1;
      v10 = sub_8C4940(v9);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v5, Interface, &pos);
  v11 = Allocate(effPCPShockWave01_tag);
  _ctor(v11, 0);
LABEL_14:
  hDataa[0] = 0;
  hDataa[0] = effPCP_ShockWave01_ThunderSpherePoly_Param;
  v11->pThunderPoly = effPCPThunderSpherePolyCreate(hDataa, 0, 0);
  v11->frame = 0;
  return v11;
}

// 0x1167d70
void effPCPShockWave01Delete(void **hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  Il2CppClass *v7;
  u64 v8[3];

  v7 = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPShockWave01_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPShockWave01_tag, v8);
    if ((v8[0] & 1) != 0)
      v5 = v8[2];
    else
      v5 = v8 + 1;
    v6 = sub_8C4940(v5);
  }
  v7 = (*hData)[3].klass;
  effPCPThunderSpherePolyDelete(&v7);
}

// 0x1167f70
void effPCPShockWave01Draw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u32 monitor;
  effPCPThunderSpherePolyParam_t_o *Param;
  u64 v10;
  bool v11;
  u32 v12;
  f32 v13;
  u32 klass_high;
  Il2CppClass *v15;
  u64 v16[3];

  v15 = 0;
  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPShockWave01_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPShockWave01_tag, v16);
      if ((v16[0] & 1) != 0)
        v6 = v16[2];
      else
        v6 = v16 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  monitor = v3[2].monitor;
  if (monitor <= 0x16)
  {
    Param = effPCPThunderSpherePolyGetParam(v3[3].klass);
    LODWORD(v10) = v3[2].monitor;
    *&v10 = v10;
    *&v10 = *&v10 / 22.0;
    Param->width = (*&v10 * 600.0) + 200.0;
    Param->height = (*&v10 * 300.0) + 100.0;
    monitor = v3[2].monitor;
  }
  v11 = monitor >= 0x2D;
  v12 = monitor - 45;
  if (v11)
  {
    v13 = v12;
    klass_high = effColorBlend(HIDWORD(v3[2].klass), 0, v13 / 30.0, 0);
  }
  else
  {
    klass_high = HIDWORD(v3[2].klass);
  }
  v15 = v3[3].klass;
  effPCPThunderSpherePolySetColor(&v15, klass_high);
  effPCPThunderSpherePolySetPosition(&v15, v3[1]);
  effPCPThunderSpherePolyDraw(&v15);
  ++LODWORD(v3[2].monitor);
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
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPShockWave01_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPShockWave01_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[2].klass) = abgr;
}

// 0x1168140
void effPCPShockWave01SetPosition(void **hData, sdfVector4_t pPos) {
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
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != effPCPShockWave01_tag)
    {
      sub_8FC2C0(*(v9 + 64), effPCPShockWave01_tag, v13);
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

// 0x1168270
void effPCPShockWave01SetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPShockWave01_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPShockWave01_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *&(*hData)[2].klass = scale;
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
  u64 *v5;
  s64 *v6;
  Il2CppClass *v7;
  s64 *Interface;
  char *v9;
  s64 *v10;
  u64 *v11;
  effPCPShockWave02_tag_o *v14;
  u64 v15[3];
  s32 pos;

  pos = bPos;
  v14 = 0;
  v5 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v5);
  v6 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(v6, byte);
    if (!Interface)
    {
      sub_8FC2C0(*(*v6 + 64), v7, v15);
      if ((v15[0] & 1) != 0)
        v9 = v15[2];
      else
        v9 = v15 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v5, Interface, &pos);
  v11 = Allocate(effPCPShockWave02_tag);
  _ctor(v11, 0);
  v14 = v11;
  effPCPShockWave02Init(&v14);
  return v11;
}

// 0x1168d00
void effPCPShockWave02Delete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 i;
  Il2CppClass *v9;
  Il2CppObject *v11[3];
  Il2CppObject *hDataa;

  hDataa = 0;
  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPShockWave02_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPShockWave02_tag, v11);
      if ((v11[0] & 1) != 0)
        v6 = v11[2];
      else
        v6 = v11 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  for (i = 0; i != 30; ++i)
  {
    v9 = v3[3].klass;
    hDataa = *(&v9->_1.byval_arg.data + i);
    effPCP_ThunderPolyDelete(&hDataa);
  }
}

// 0x1168ed0
void effPCPShockWave02Draw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  s64 i;
  Il2CppClass *v12;
  effPCP_ThunderPolyParam_t_o *Param;
  struct UnityEngine_Vector4_array *pos;
  effPCP_ThunderPolyParam_t_o *v16;
  struct UnityEngine_Vector4_array *v19;
  struct UnityEngine_Vector4_array *v21;
  struct UnityEngine_Vector4_array *v24;
  Il2CppClass *v26;
  struct UnityEngine_Vector4_array *v28;
  struct UnityEngine_Vector4_array *v29;
  Il2CppObject *v32;
  u64 v33[3];

  v32 = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPShockWave02_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPShockWave02_tag, v33);
      if ((v33[0] & 1) != 0)
        v6 = v33[2];
      else
        v6 = v33 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = NewSpecific(UnityEngine_Vector4, 2u);
  for (i = 4; i != 34; ++i)
  {
    v12 = v3[3].klass;
    Param = effPCP_ThunderPolyGetParam(*(&v12->_1.image + i), 0);
    pos = Param->pos;
    v16 = Param;
    SDF_VU0__LOADVECTOR(pos->m_Items[1]);
    SDF_VU0__STOREVECTOR(v8 + 3);
    SDF_VU0__LOADVECTOR_B(v3[1]);
    SDF_VU0__ADDVECTOR();
    v19 = v16->pos;
    SDF_VU0__STOREVECTOR(&v19->m_Items[1]);
    v21 = v16->pos;
    SDF_VU0__LOADVECTOR(v21->m_Items[0]);
    SDF_VU0__STOREVECTOR(v8 + 2);
    SDF_VU0__ADDVECTOR();
    v24 = v16->pos;
    SDF_VU0__STOREVECTOR(v24->m_Items);
    v26 = v3[3].klass;
    v32 = *(&v26->_1.image + i);
    effPCP_ThunderPolyDraw(&v32);
    v28 = v16->pos;
    SDF_VU0__COPYVECTOR(v28->m_Items, *(v8 + 2), 0);
    v29 = v16->pos;
    SDF_VU0__COPYVECTOR(&v29->m_Items[1], *(v8 + 3), 0);
  }
}

// 0x1168450
void effPCPShockWave02Init(effPCPShockWave02_tag **pPCPShockWave02) {
  __int128 v2;
  effPCPShockWave02_tag_o *v4;
  u64 v6;
  f32 v9;
  f32 v11;
  struct UnityEngine_Vector4_array *pos;
  struct UnityEngine_Vector4_array *v14;
  __int128 v16;
  struct UnityEngine_Vector4_array *v17;
  f32 v20;
  s64 v21;
  s64 v22;
  f32 v23;
  f32 v24;
  struct UnityEngine_Vector4_array *v25;
  f32 v27;
  struct UnityEngine_Vector4_array *v28;
  struct UnityEngine_Vector4_array *v30;
  struct UnityEngine_Vector4_array *v32;
  struct UnityEngine_Vector4_array *v34;
  struct UnityEngine_Vector4_array *v36;
  s64 m_Items;
  struct UnityEngine_Vector4_array *v39;
  struct UnityEngine_Vector4_array *v41;
  s64 v43;
  struct UnityEngine_Vector4_array *v44;
  f32 v47;
  f32 v48;
  u32 v49;
  s16 v50;
  f32 v51;
  u32 v53;
  u16 v55;
  u32 *pThunderPoly;
  s64 *v57;
  s64 *v58;
  u32 *v60;
  f32 aRadius;
  s64 v62;
  s64 v63;
  Il2CppObject *hData;
  UnityEngine_Vector4_o v65;

  hData = 0;
  v62 = 0;
  v63 = 0;
  v4 = *pPCPShockWave02;
  v4->pThunderPoly = NewSpecific(effPCP_ThunderPoly_t, 0x1Eu);
  LODWORD(v2) = 0.25;
  v6 = 0;
  aRadius = 0.0;
  do
  {
    if ((v6 & 1) == 0)
    {
      sdfCos(aRadius);
      sdfSin(aRadius);
      aRadius = aRadius + 0.41888;
    }
    v9 = DDS3EFFECT_RAND_FA(0.5);
    v11 = v9;
    effPCP_ShockWave02_ThunderPoly_Param->width_border = v11 * 1.25;
    effPCP_ShockWave02_ThunderPoly_Param->width_edge = v11 * 12.5;
    pos = effPCP_ShockWave02_ThunderPoly_Param->pos;
    sub_854930(&pos->m_Items[1], 1u);
    DDS3EFFECT_RAND_FA(*&v2);
    v14 = effPCP_ShockWave02_ThunderPoly_Param->pos;
    sub_854930(&v14->m_Items[1], 0);
    v16 = v2;
    DDS3EFFECT_RAND_FA(*&v2);
    v17 = effPCP_ShockWave02_ThunderPoly_Param->pos;
    sub_854930(&v17->m_Items[1], 2u);
    sub_854930(&v62, 0);
    sub_854930(&v62, 1u);
    sub_854930(&v62, 2u);
    v20 = DDS3EFFECT_RAND_F();
    v21 = v62;
    v22 = v63;
    v23 = -((v20 * 0.95993) + 0.087266);
    *&v65.x = v21;
    *&v65.z = v22;
    SetRotateMatrixAxis(v23, v65);
    v24 = DDS3EFFECT_RAND_FA(0.65);
    v25 = effPCP_ShockWave02_ThunderPoly_Param->pos;
    v27 = v24 * 500.0;
    sub_854930(v25->m_Items, 0);
    v28 = effPCP_ShockWave02_ThunderPoly_Param->pos;
    sub_854930(v28->m_Items, 1u);
    v30 = effPCP_ShockWave02_ThunderPoly_Param->pos;
    sub_854930(v30->m_Items, 2u);
    v32 = effPCP_ShockWave02_ThunderPoly_Param->pos;
    SDF_VU0__LOADVECTOR(v32->m_Items[0]);
    SDF_VU0__APPLYMATRIX_XYZ();
    v34 = effPCP_ShockWave02_ThunderPoly_Param->pos;
    SDF_VU0__STOREVECTOR(v34->m_Items);
    v36 = effPCP_ShockWave02_ThunderPoly_Param->pos;
    m_Items = v36->m_Items;
    sub_854710(m_Items, 0);
    v39 = effPCP_ShockWave02_ThunderPoly_Param->pos;
    sub_854710(&v39->m_Items[1], 0);
    sub_854930(m_Items, 0);
    v41 = effPCP_ShockWave02_ThunderPoly_Param->pos;
    v43 = v41->m_Items;
    sub_854710(v43, 2u);
    v44 = effPCP_ShockWave02_ThunderPoly_Param->pos;
    sub_854710(&v44->m_Items[1], 2u);
    sub_854930(v43, 2u);
    if (v27 >= 300.0)
    {
      v47 = 5.0;
      v48 = 10.0;
      v50 = 15;
      v49 = 6;
    }
    else
    {
      v47 = 2.5;
      v48 = 5.0;
      v49 = 5;
      v50 = 5;
      {
        v47 = 2.5;
        v48 = 5.0;
        v49 = 5;
        v50 = 5;
      }
    }
    v51 = (DDS3EFFECT_RAND_PM() * v47) + v48;
    v53 = DDS3EFFECT_RAND_I() % v49;
    v55 = v53 + v50;
    effPCP_ShockWave02_ThunderPoly_Param->split = v55;
    effPCP_ShockWave02_ThunderPoly_Param->refraction = v51;
    hData = effPCP_ShockWave02_ThunderPoly_Param;
    pThunderPoly = (*pPCPShockWave02)->pThunderPoly;
    v2 = v16;
    v57 = effPCP_ThunderPolyCreate(&hData, 0, 1, 0);
    v58 = v57;
    v60 = &pThunderPoly[2 * v6++];
    *(v60 + 4) = v58;
  }
  while (v6 != 30);
}

// 0x1169490
void effPCPShockWave02SetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPShockWave02_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPShockWave02_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[2].monitor) = abgr;
}

// 0x1169270
void effPCPShockWave02SetPosition(void **hData, sdfVector4_t pPos) {
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
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != effPCPShockWave02_tag)
    {
      sub_8FC2C0(*(v9 + 64), effPCPShockWave02_tag, v13);
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

// 0x11693a0
void effPCPShockWave02SetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPShockWave02_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPShockWave02_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *(&(*hData)[2].klass + 1) = scale;
}

// 0x1158110
effPCPSparkleSphere_tag *effPCPSparkleSphereCreate(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 *v10;
  Il2CppObject *v12;
  Il2CppClass *v13;
  s64 v14;
  char *v15;
  s64 *v16;
  u64 v18[2];
  char *v19;

  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPSparkleSphereParam_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPSparkleSphereParam_t, v18);
      if ((v18[0] & 1) != 0)
        v8 = v19;
      else
        v8 = v18 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = Allocate(effPCPSparkleSphere_tag);
  _ctor(v10, 0);
  v10[4] = v5;
  else
  {
    v12 = dds3BillboardGeneral(2);
    if (!v12)
      goto LABEL_19;
  }
  v13 = v12->klass;
  if (v12->klass->_2.typeHierarchyDepth < v14 || v13->_2.typeHierarchy[v14 - 1] != billHandle_t)
  {
    sub_8FC2C0(v13->_1.element_class, billHandle_t, v18);
    if ((v18[0] & 1) != 0)
      v15 = v19;
    else
      v15 = v18 + 1;
    v16 = sub_8C4940(v15);
  }
LABEL_19:
  v10[6] = v12;
  dds3BillboardSetMode(v10 + 6, 2);
  v10[5] = 0x42C8000080808080LL;
  return v10;
}

// 0x1158320
void effPCPSparkleSphereDelete(void **hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  Il2CppClass *v7;
  u64 v8[3];

  v7 = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPSparkleSphere_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPSparkleSphere_tag, v8);
    if ((v8[0] & 1) != 0)
      v5 = v8[2];
    else
      v5 = v8 + 1;
    v6 = sub_8C4940(v5);
  }
  v7 = (*hData)[3].klass;
  dds3BillboardDelete(&v7);
}

// 0x1158440
void effPCPSparkleSphereDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  f32 v17;
  u32 v18;
  s32 v19;
  u32 v20;
  u32 v21;
  billHandle_t_o *v22;
  UnityEngine_Vector4_o v23;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v25;
  billHandle_t_o *v26[3];
  billHandle_t_o *hBillboard;
  UnityEngine_Vector4_o v28;

  hBillboard = 0;
  *&v25.x = 0;
  *&v25.z = 0;
  v22 = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v23.x = 0;
  *&v23.z = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPSparkleSphere_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPSparkleSphere_tag, v26);
      if ((v26[0] & 1) != 0)
        v6 = v26[2];
      else
        v6 = v26 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = Allocate(billHandle_t);
  billHandle_t___ctor(v8);
  hBillboard = v8;
  *&v25.x = 0;
  *&v25.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v23.x = 0;
  *&v23.z = 0;
  SDF_VU0__LOADVECTOR(dds3CameraEyePos);
  SDF_VU0__LOADVECTOR_B(dds3CameraTargetPos);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&p);
  hBillboard = v3[3].klass;
  sub_854930(&v23, 0);
  sub_854710(&v23, 0);
  sub_854930(&v23, 1u);
  sub_854930(&v23, 2u);
  SDF_VU0__LOADVECTOR(v23);
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__MULVECTOR();
  SDF_VU0__LOADVECTOR_B(v3[1]);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&v25);
  x = v25.x;
  y = v25.y;
  z = v25.z;
  w = v25.w;
  v28.x = x;
  v28.y = y;
  v28.z = z;
  v28.w = w;
  dds3BillboardSetPosition(&hBillboard, v28);
  v17 = *(&v3[2].monitor + 1);
  v18 = 276856960;
  v19 = 10;
  do
  {
    dds3BillboardSetScale(&hBillboard, v17, v17);
    v17 = v17 * 0.975;
    v20 = effColorMultiply(v18, v3[2].monitor);
    v21 = effColorMultiply(v20, v3[2].klass->_1.name);
    dds3BillboardSetRGBA(&hBillboard, v21);
    v18 += 83886080;
    v22 = hBillboard;
    dds3BillboardDraw(&v22);
    --v19;
  }
  while (v19);
}

// 0x11589a0
void effPCPSparkleSphereSetArea(void **hData, f32 area) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPSparkleSphere_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPSparkleSphere_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *(&(*hData)[2].monitor + 1) = area;
}

// 0x11588b0
void effPCPSparkleSphereSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPSparkleSphere_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPSparkleSphere_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[2].monitor) = abgr;
}

// 0x1158780
void effPCPSparkleSphereSetPosition(void **hData, sdfVector4_t pPos) {
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
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != effPCPSparkleSphere_tag)
    {
      sub_8FC2C0(*(v9 + 64), effPCPSparkleSphere_tag, v13);
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

// 0x118a320
effPCPSpiralBED_tag *effPCPSpiralBEDCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 *v10;
  u64 typeDefinition_low;
  u64 *v12;
  s64 v13;
  s64 v14;
  s64 v15;
  u32 *v18;
  u64 v19;
  u64 *v20;
  u64 v23;
  s64 v25;
  effBTL_t_o *v26;
  u32 v28;
  s32 v29;
  u32 *v30;
  u64 v33[3];

  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPSpiralBED_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPSpiralBED_tag, v33);
      if ((v33[0] & 1) != 0)
        v8 = v33[2];
      else
        v8 = v33 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = Allocate(effEveBEDParams_t);
  effEveBEDParams_t___ctor(v10);
  typeDefinition_low = LODWORD(v5[1].klass->_1.typeDefinition);
  v12 = Allocate(effPCPSpiralBED_tag);
  _ctor(v12, 0);
  v12[2] = v5[1].klass;
  v12[3] = NewSpecific(effPCPSpiralBEDPart_tag, typeDefinition_low);
  *(v12 + 44) = 0x808080803F800000LL;
  v12[7] = 0;
  *(v12 + 40) = 0;
  v12[4] = v5[2].klass;
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
  if (typeDefinition_low)
  {
    v13 = -typeDefinition_low;
    v14 = *(v12[2] + 108);
    v15 = 4;
    do
    {
      v18 = v12[3];
      v19 = v15 - 4;
      v20 = Allocate(effPCPSpiralBEDPart_tag);
      _ctor(v20, 0);
      *&v18[2 * v15] = v20;
      v23 = v12[3];
      v25 = *(v23 + 8 * v15);
      v26 = v12[4];
      *(v25 + 16) = effEveBEDCutCreate(v26, 2u, v10);
      if (v14 < 1)
      {
        v29 = 0;
      }
      else
      {
        v28 = DDS3EFFECT_RAND_I();
        v29 = v28 / v14 * v14 - v28;
      }
      *(v25 + 24) = v29;
      v30 = v12[3];
      *&v30[2 * v15++] = v25;
    }
    while (v13 + v15 != 4);
  }
  return v12;
}

// 0x1189c80
effPCPSpiralBED_tag *effPCPSpiralBEDCreate(effPCPSpiralBEDParam_t *pParam, void *pBEDData) {
  u64 *v5;
  s64 number;
  u64 *v7;
  Il2CppClass *v9;
  s64 *Interface;
  char *v11;
  s64 *v12;
  s64 v13;
  s64 v14;
  s64 v15;
  u32 *v18;
  u64 v19;
  u64 *v20;
  u64 v23;
  s64 v25;
  effBTL_t_o *v26;
  u32 v28;
  s32 v29;
  u32 *v30;
  u64 v33[3];

  v5 = Allocate(effEveBEDParams_t);
  effEveBEDParams_t___ctor(v5);
  number = pParam->number;
  v7 = Allocate(effPCPSpiralBED_tag);
  _ctor(v7, 0);
  v7[2] = pParam;
  v7[3] = NewSpecific(effPCPSpiralBEDPart_tag, pParam->number);
  v7[7] = 0;
  *(v7 + 44) = 0x808080803F800000LL;
  *(v7 + 40) = 1;
  if (!pBEDData)
    goto LABEL_12;
LABEL_6:
  Interface = QueryInterface(pBEDData, byte);
  if (!Interface)
  {
    sub_8FC2C0(pBEDData->klass->_1.element_class, v9, v33);
    if ((v33[0] & 1) != 0)
      v11 = v33[2];
    else
      v11 = v33 + 1;
    v12 = sub_8C4940(v11);
  }
LABEL_13:
  v7[4] = effEveBEDCreate(Interface);
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
  if (number)
  {
    v13 = *(v7[2] + 108);
    v14 = -number;
    v15 = 4;
    do
    {
      v18 = v7[3];
      v19 = v15 - 4;
      v20 = Allocate(effPCPSpiralBEDPart_tag);
      _ctor(v20, 0);
      *&v18[2 * v15] = v20;
      v23 = v7[3];
      v25 = *(v23 + 8 * v15);
      v26 = v7[4];
      *(v25 + 16) = effEveBEDCutCreate(v26, 2u, v5);
      if (v13 < 1)
      {
        v29 = 0;
      }
      else
      {
        v28 = DDS3EFFECT_RAND_I();
        v29 = v28 / v13 * v13 - v28;
      }
      *(v25 + 24) = v29;
      v30 = v7[3];
      *&v30[2 * v15++] = v25;
    }
    while (v14 + v15 != 4);
  }
  return v7;
}

// 0x118a0a0
effPCPSpiralBED_tag *effPCPSpiralBEDCreatePCF(void **hData, s32 bPos, bool tbldata) {
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
  struct dds3EffectPCPData_Part_t_array *v20;
  Il2CppObject *v21;
  effPCPSpiralBEDParam_t_o *v22;
  u32 v24;
  Il2CppObject *EffPCPpBEDData;
  effPCPSpiralBEDParam_t_c *klass;
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
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 25);
  v20 = v6->pcpData;
  v21 = *hData;
  v22 = DataUnityOffSet;
  v24 = v20->m_Items[1]->offset;
  EffPCPpBEDData = GetEffPCPpBEDData(v21, v24 + bPos);
  if (v22)
  {
    klass = v22->klass;
    if (v22->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPSpiralBEDParam_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPSpiralBEDParam_t, v32);
      if ((v32[0] & 1) != 0)
        v29 = v33;
      else
        v29 = v32 + 1;
      v30 = sub_8C4940(v29);
    }
  }
  return effPCPSpiralBEDCreate(v22, EffPCPpBEDData);
}

// 0x118a710
void effPCPSpiralBEDDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s64 typeDefinition_low;
  u64 i;
  u64 *monitor;
  effEveBEDCutHandle_t_o *v12;
  effBTL_t_o *v13;
  u64 v14[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPSpiralBED_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPSpiralBED_tag, v14);
      if ((v14[0] & 1) != 0)
        v6 = v14[2];
      else
        v6 = v14 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  typeDefinition_low = LODWORD(v3[1].klass->_1.typeDefinition);
  if (typeDefinition_low)
  {
    for (i = 0; i != typeDefinition_low; ++i)
    {
      monitor = v3[1].monitor;
      v12 = *(monitor[i + 4] + 16LL);
      effEveBEDCutDelete(v12);
    }
  }
  v13 = v3[2].klass;
  if (v13 && !v13->CutCount)
  {
    effEveBEDDelete(v13);
  }
}

// 0x118aa40
void effPCPSpiralBEDDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  Il2CppClass *v9;
  s32 interopData;
  f32 v11;
  s32 generic_class_high;
  s64 typeDefinition_low;
  f32 v14;
  u64 v17;
  u64 *monitor;
  s64 v20;
  s32 v21;
  f32 v23;
  f32 v24;
  f32 v25;
  f32 v26;
  f32 v27;
  f32 v28;
  s32 interopData_high;
  u32 abgr1;
  UnityEngine_Vector4_o dst;
  effPCPSpiralBED_tag_o *pSpiralBED;
  u64 v34[3];

  *&dst.z = 0;
  pSpiralBED = 0;
  *&dst.x = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPSpiralBED_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPSpiralBED_tag, v34);
      if ((v34[0] & 1) != 0)
        v6 = v34[2];
      else
        v6 = v34 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  pSpiralBED = *hData;
  v8 = Allocate(effEveBEDParams_t);
  effEveBEDParams_t___ctor(v8);
  *&dst.x = 0;
  *&dst.z = 0;
  v9 = v3[1].klass;
  interopData = v9->_1.interopData;
  v11 = *&v9->_1.fields;
  generic_class_high = HIDWORD(v9->_1.generic_class);
  typeDefinition_low = LODWORD(v9->_1.typeDefinition);
  interopData_high = HIDWORD(v9->_1.interopData);
  abgr1 = v3[3].klass;
  v14 = *(&v9->_1.events + 1);
  SDF_VU0__COPYVECTOR(&dst, *&v9->_1.name);
  if (generic_class_high)
  {
    sub_854930((v8 + 4), 0);
    sub_854930((v8 + 4), 1u);
    sub_854930((v8 + 4), 2u);
    sub_854930((v8 + 4), 3u);
    v8[6] = 0x42C8000042C80000LL;
    *(v8 + 14) = 1065353216;
    if (typeDefinition_low)
    {
      v17 = 0;
      while (1)
      {
        monitor = v3[1].monitor;
        v20 = monitor[v17 + 4];
        v21 = *(v20 + 24);
        if (v21 > generic_class_high)
          goto LABEL_40;
        if (!v21)
          break;
        if ((v21 & 0x80000000) == 0)
          goto LABEL_26;
LABEL_39:
        *(v20 + 24) = v21 + 1;
LABEL_40:
        if (typeDefinition_low == ++v17)
          return;
      }
      effPCPSpiralBEDPartInit(&pSpiralBED, v17);
      v23 = *(&v3[2].monitor + 1);
      effEveBEDCutSetScale((v20 + 16), v23, 0);
      v21 = *(v20 + 24);
      if (v21 < 0)
        goto LABEL_39;
LABEL_26:
      v24 = *(v20 + 36);
      sdfCos(v24);
      sdfSin(v24);
      sub_854710(&dst, 0);
      sub_854930((v8 + 2), 0);
      sub_854710(&dst, 1u);
      sub_854930((v8 + 2), 1u);
      sub_854710(&dst, 2u);
      sub_854930((v8 + 2), 2u);
      v25 = *(v20 + 44) + *(v20 + 48);
      v26 = *(v20 + 32);
      *(v20 + 28) = *(v20 + 28) + v26;
      *(v20 + 44) = v25;
      v27 = *(v20 + 40);
      *(v20 + 36) = *(v20 + 36) + v27;
      *(v20 + 40) = v11 * v27;
      *(v20 + 32) = v14 * v26;
      if (interopData && v21 < interopData)
      {
        v28 = v21 / interopData;
      }
      else
      {
        v28 = 1.0;
        if (interopData_high)
        {
          v28 = 1.0;
          if (generic_class_high - v21 <= interopData_high)
            v28 = (generic_class_high - v21) / interopData_high;
        }
      }
      *(v8 + 15) = effColorBlend(abgr1 & 0xFFFFFF, abgr1, v28);
      effEveBEDCutSetParams((v20 + 16), v8, 0);
      effEveBEDCutDraw((v20 + 16), 0);
      v21 = *(v20 + 24);
      goto LABEL_39;
    }
  }
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
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPSpiralBED_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPSpiralBED_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[3].klass) = abgr;
}

// 0x118aeb0
void effPCPSpiralBEDSetPosition(void **hData, sdfVector4_t pPos) {
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
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPSpiralBED_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPSpiralBED_tag, v12);
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

// 0x118afd0
void effPCPSpiralBEDSetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPSpiralBED_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPSpiralBED_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *(&(*hData)[2].monitor + 1) = scale;
}

// 0x117f2c0
effPCPThunderSphereExp_tag *effPCPThunderSphereExpCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  effPCPThunderSphereExpParam_t_o *v10;
  effPCPThunderSpherePolyParam_t_o *Param;
  u64 v14[3];

  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPThunderSphereExp_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPThunderSphereExp_tag, v14);
      if ((v14[0] & 1) != 0)
        v8 = v14[2];
      else
        v8 = v14 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = Allocate(effPCPThunderSphereExpParam_t);
  effPCPThunderSphereExpParam_t___ctor(v10);
  Param = effPCPThunderSpherePolyGetParam(v5[4].klass);
  v10->life = v5[2].klass;
  v10->fade_in = HIDWORD(v5[2].klass);
  v10->fade_out = v5[2].monitor;
  v10->radius_s = HIDWORD(v5[2].monitor);
  v10->radius_e = v5[3].klass;
  v10->ThunderSpherePoly = Param;
  return effPCPThunderSphereExpCreate(v10);
}

// 0x117f010
effPCPThunderSphereExp_tag *effPCPThunderSphereExpCreate(effPCPThunderSphereExpParam_t *pParam) {
  u64 *v3;
  Il2CppObject *hData;

  v3 = Allocate(effPCPThunderSphereExp_tag);
  _ctor(v3, 0);
  pParam->ThunderSpherePoly->width = pParam->radius_s;
  pParam->ThunderSpherePoly->height = pParam->radius_s;
  hData = pParam->ThunderSpherePoly;
  v3[8] = effPCPThunderSpherePolyCreate(&hData, 0, 0);
  *(v3 + 8) = pParam->life;
  *(v3 + 9) = pParam->fade_in;
  *(v3 + 10) = pParam->fade_out;
  *(v3 + 11) = pParam->radius_s;
  *(v3 + 12) = pParam->radius_e;
  *(v3 + 15) = 1065353216;
  *(v3 + 52) = 2155905152LL;
  sub_854710(&pParam->ThunderSpherePoly->fields, 0);
  sub_854930((v3 + 2), 0);
  sub_854710(&pParam->ThunderSpherePoly->fields, 1u);
  sub_854930((v3 + 2), 1u);
  sub_854710(&pParam->ThunderSpherePoly->fields, 2u);
  sub_854930((v3 + 2), 2u);
  return v3;
}

// 0x117eef0
effPCPThunderSphereExp_tag *effPCPThunderSphereExpCreateP(void **pData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v11[3];

  v5 = *pData;
  else if (!v5)
  {
    return effPCPThunderSphereExpCreate(v5, *&bPos);
  }
  klass = v5->klass;
  if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPThunderSphereExpParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPThunderSphereExpParam_t, v11);
    if ((v11[0] & 1) != 0)
      v8 = v11[2];
    else
      v8 = v11 + 1;
    v9 = sub_8C4940(v8);
  }
  return effPCPThunderSphereExpCreate(v5, *&bPos);
}

// 0x117f160
effPCPThunderSphereExp_tag *effPCPThunderSphereExpCreatePCF(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v6;
  effPCPThunderSphereExpParam_t_c *v7;
  Il2CppObject *DataUnity;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  u64 v14[3];

  v6 = *hData;
  DataUnity = dds3EffectPCPDataGetDataUnity(v6, 0, 19, bPos);
  else if (!DataUnity)
  {
    return effPCPThunderSphereExpCreate(DataUnity, v7);
  }
  klass = DataUnity->klass;
  if (DataUnity->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPThunderSphereExpParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPThunderSphereExpParam_t, v14);
    if ((v14[0] & 1) != 0)
      v11 = v14[2];
    else
      v11 = v14 + 1;
    v12 = sub_8C4940(v11);
  }
  return effPCPThunderSphereExpCreate(DataUnity, v7);
}

// 0x117f430
void effPCPThunderSphereExpDelete(void **hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  Il2CppClass *v7;
  u64 v8[3];

  v7 = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPThunderSphereExp_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPThunderSphereExp_tag, v8);
    if ((v8[0] & 1) != 0)
      v5 = v8[2];
    else
      v5 = v8 + 1;
    v6 = sub_8C4940(v5);
  }
  v7 = (*hData)[4].klass;
  effPCPThunderSpherePolyDelete(&v7);
}

// 0x117f530
void effPCPThunderSphereExpDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s32 monitor;
  s32 v9;
  s32 v10;
  s32 v11;
  s32 klass_high;
  f32 v13;
  f32 v14;
  u32 v15;
  Il2CppObject *v16[3];
  Il2CppObject *hDataa;

  hDataa = 0;
  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPThunderSphereExp_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPThunderSphereExp_tag, v16);
      if ((v16[0] & 1) != 0)
        v6 = v16[2];
      else
        v6 = v16 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  effPCPThunderSpherePolyGetParam(v3[4].klass);
  monitor = v3[3].monitor;
  v9 = v3[2].klass;
  v10 = v9 - monitor;
  if (v9 >= monitor)
  {
    klass_high = HIDWORD(v3[2].klass);
    v11 = v3[2].monitor;
    v13 = (((monitor / v9) * (SLODWORD(v3[3].klass) - SHIDWORD(v3[2].monitor))) + SHIDWORD(v3[2].monitor))
        / SHIDWORD(v3[2].monitor);
    if (monitor < klass_high && klass_high)
    {
      v14 = monitor / klass_high;
    }
    else
    {
      v14 = v10 / v11;
      if (!v11)
        v14 = 1.0;
      if (v10 > v11)
        v14 = 1.0;
    }
    v15 = effColorBlend(HIDWORD(v3[3].klass) & 0xFFFFFF, HIDWORD(v3[3].klass), v14, 0);
    hDataa = v3[4].klass;
    effPCPThunderSpherePolySetColor(&hDataa, v15);
    hDataa = v3[4].klass;
    effPCPThunderSpherePolySetPosition(&hDataa, v3[1]);
    hDataa = v3[4].klass;
    effPCPThunderSpherePolySetScale(&hDataa, v13 * *(&v3[3].monitor + 1), 0);
    hDataa = v3[4].klass;
    effPCPThunderSpherePolyDraw(&hDataa);
    ++LODWORD(v3[3].monitor);
  }
}

// 0x117f860
void effPCPThunderSphereExpSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPThunderSphereExp_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPThunderSphereExp_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD((*hData)[3].klass) = abgr;
}

// 0x117f730
void effPCPThunderSphereExpSetPosition(void **hData, sdfVector4_t pPos) {
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
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != effPCPThunderSphereExp_tag)
    {
      sub_8FC2C0(*(v9 + 64), effPCPThunderSphereExp_tag, v13);
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

// 0x117f950
void effPCPThunderSphereExpSetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPThunderSphereExp_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPThunderSphereExp_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *(&(*hData)[3].monitor + 1) = scale;
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
  u64 *v5;
  s64 *v6;
  Il2CppClass *v7;
  s64 *Interface;
  char *v9;
  s64 *v10;
  u64 *v11;
  effPCPZiodin01_tag_o *v14;
  u64 v15[3];
  s32 pos;

  pos = bPos;
  v14 = 0;
  v5 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v5);
  v6 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(v6, byte);
    if (!Interface)
    {
      sub_8FC2C0(*(*v6 + 64), v7, v15);
      if ((v15[0] & 1) != 0)
        v9 = v15[2];
      else
        v9 = v15 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v5, Interface, &pos);
  v11 = Allocate(effPCPZiodin01_tag);
  _ctor(v11, 0);
  v14 = v11;
  effPCPZiodin01Init(&v14);
  return v11;
}

// 0x11617c0
void effPCPZiodin01Delete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppClass *v8;
  Il2CppClass *v10;
  Il2CppClass *v12;
  Il2CppClass *v14;
  Il2CppClass *v16;
  Il2CppClass *v18;
  Il2CppClass *v20;
  Il2CppClass *v22;
  Il2CppClass *v24;
  Il2CppClass *v26;
  Il2CppClass *v28;
  Il2CppClass *v30;
  Il2CppObject *data;
  u64 v33[3];

  data = 0;
  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPZiodin01_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPZiodin01_tag, v33);
      if ((v33[0] & 1) != 0)
        v6 = v33[2];
      else
        v6 = v33 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = v3[3].klass;
  data = v8->_1.byval_arg.data;
  effPCP_ThunderPolyDelete(&data);
  v10 = v3[3].klass;
  data = *&v10->_1.byval_arg.bits;
  effPCP_ThunderPolyDelete(&data);
  v12 = v3[3].klass;
  data = v12->_1.this_arg.data;
  effPCP_ThunderPolyDelete(&data);
  v14 = v3[3].klass;
  data = *&v14->_1.this_arg.bits;
  effPCP_ThunderPolyDelete(&data);
  v16 = v3[3].klass;
  data = v16->_1.element_class;
  effPCP_ThunderPolyDelete(&data);
  v18 = v3[3].klass;
  data = v18->_1.castClass;
  effPCP_ThunderPolyDelete(&data);
  v20 = v3[3].klass;
  data = v20->_1.declaringType;
  effPCP_ThunderPolyDelete(&data);
  v22 = v3[3].klass;
  data = v22->_1.parent;
  effPCP_ThunderPolyDelete(&data);
  v24 = v3[3].klass;
  data = v24->_1.generic_class;
  effPCP_ThunderPolyDelete(&data);
  v26 = v3[3].klass;
  data = v26->_1.typeDefinition;
  effPCP_ThunderPolyDelete(&data);
  v28 = v3[3].klass;
  data = v28->_1.interopData;
  effPCP_ThunderPolyDelete(&data);
  v30 = v3[3].klass;
  data = v30->_1.klass;
  effPCP_ThunderPolyDelete(&data);
}

// 0x1161bc0
void effPCPZiodin01Draw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  s64 i;
  Il2CppClass *v12;
  effPCP_ThunderPolyParam_t_o *Param;
  struct UnityEngine_Vector4_array *pos;
  effPCP_ThunderPolyParam_t_o *v16;
  struct UnityEngine_Vector4_array *v19;
  struct UnityEngine_Vector4_array *v21;
  struct UnityEngine_Vector4_array *v24;
  Il2CppClass *v26;
  struct UnityEngine_Vector4_array *v28;
  struct UnityEngine_Vector4_array *v29;
  Il2CppObject *v32;
  u64 v33[3];

  v32 = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPZiodin01_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPZiodin01_tag, v33);
      if ((v33[0] & 1) != 0)
        v6 = v33[2];
      else
        v6 = v33 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = NewSpecific(UnityEngine_Vector4, 2u);
  for (i = 4; i != 16; ++i)
  {
    v12 = v3[3].klass;
    Param = effPCP_ThunderPolyGetParam(*(&v12->_1.image + i), 0);
    pos = Param->pos;
    v16 = Param;
    SDF_VU0__LOADVECTOR(pos->m_Items[1]);
    SDF_VU0__STOREVECTOR(v8 + 3);
    SDF_VU0__LOADVECTOR_B(v3[1]);
    SDF_VU0__ADDVECTOR();
    v19 = v16->pos;
    SDF_VU0__STOREVECTOR(&v19->m_Items[1]);
    v21 = v16->pos;
    SDF_VU0__LOADVECTOR(v21->m_Items[0]);
    SDF_VU0__STOREVECTOR(v8 + 2);
    SDF_VU0__ADDVECTOR();
    v24 = v16->pos;
    SDF_VU0__STOREVECTOR(v24->m_Items);
    v26 = v3[3].klass;
    v32 = *(&v26->_1.image + i);
    effPCP_ThunderPolyDraw(&v32);
    v28 = v16->pos;
    SDF_VU0__COPYVECTOR(v28->m_Items, *(v8 + 2), 0);
    v29 = v16->pos;
    SDF_VU0__COPYVECTOR(&v29->m_Items[1], *(v8 + 3), 0);
  }
}

// 0x11610e0
void effPCPZiodin01Init(effPCPZiodin01_tag **pPCPZiodin01) {
  effPCPZiodin01_tag_o *v3;
  f32 v5;
  u64 i;
  f32 v9;
  f32 v11;
  struct UnityEngine_Vector4_array *pos;
  struct UnityEngine_Vector4_array *v14;
  struct UnityEngine_Vector4_array *v16;
  struct UnityEngine_Vector4_array *v18;
  struct UnityEngine_Vector4_array *v20;
  f32 v23;
  f32 v24;
  f32 v25;
  u32 v26;
  s16 v27;
  f32 v28;
  u32 v30;
  u16 v32;
  u32 *pThunderPoly;
  s64 *v34;
  s64 *v35;
  u32 *v37;
  Il2CppObject *hData;
  UnityEngine_Vector4_o v39;
  UnityEngine_Vector4_o p;

  hData = 0;
  *&v39.x = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v39.z = 0;
  v3 = *pPCPZiodin01;
  v3->pThunderPoly = NewSpecific(effPCP_ThunderPoly_t, 0xCu);
  v5 = 0.0;
  for (i = 0; i != 12; ++i)
  {
    if ((i & 1) == 0)
    {
      sdfCos(v5);
      sdfSin(v5);
      v5 = v5 + 1.0472;
    }
    v9 = DDS3EFFECT_RAND_FA(0.5);
    v11 = v9;
    effPCP_Ziodin01_ThunderPoly_Param->width_border = v11 * 1.25;
    effPCP_Ziodin01_ThunderPoly_Param->width_edge = v11 * 12.5;
    DDS3EFFECT_RAND_FA(0.25);
    pos = effPCP_Ziodin01_ThunderPoly_Param->pos;
    sub_854930(&pos->m_Items[1], 0);
    v14 = effPCP_Ziodin01_ThunderPoly_Param->pos;
    sub_854930(&v14->m_Items[1], 1u);
    v16 = effPCP_Ziodin01_ThunderPoly_Param->pos;
    sub_854930(&v16->m_Items[1], 2u);
    sub_854930(&p, 0);
    DDS3EFFECT_RAND_PM();
    sub_854930(&p, 1u);
    sub_854930(&p, 2u);
    SDF_VU0__LOADVECTOR(p);
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(&p);
    DDS3EFFECT_RAND_FA(0.65);
    sub_854930(&v39, 0);
    sub_854710(&v39, 0);
    sub_854930(&v39, 1u);
    sub_854710(&v39, 0);
    sub_854930(&v39, 2u);
    SDF_VU0__LOADVECTOR(p);
    SDF_VU0__LOADVECTOR_B(v39);
    SDF_VU0__MULVECTOR();
    v18 = effPCP_Ziodin01_ThunderPoly_Param->pos;
    SDF_VU0__LOADVECTOR_B(v18->m_Items[1]);
    SDF_VU0__ADDVECTOR();
    v20 = effPCP_Ziodin01_ThunderPoly_Param->pos;
    SDF_VU0__STOREVECTOR(v20->m_Items);
    sub_854710(&v39, 0);
    if (v23 >= 250.0)
    {
      v24 = 5.0;
      v25 = 10.0;
      v27 = 15;
      v26 = 6;
    }
    else
    {
      v24 = 2.5;
      v25 = 5.0;
      v26 = 5;
      v27 = 5;
      {
        v24 = 2.5;
        v25 = 5.0;
        v26 = 5;
        v27 = 5;
      }
    }
    v28 = (DDS3EFFECT_RAND_PM() * v24) + v25;
    v30 = DDS3EFFECT_RAND_I() % v26;
    v32 = v30 + v27;
    effPCP_Ziodin01_ThunderPoly_Param->split = v32;
    effPCP_Ziodin01_ThunderPoly_Param->refraction = v28;
    hData = effPCP_Ziodin01_ThunderPoly_Param;
    pThunderPoly = (*pPCPZiodin01)->pThunderPoly;
    v34 = effPCP_ThunderPolyCreate(&hData, 0, 1, 0);
    v35 = v34;
    v37 = &pThunderPoly[2 * i];
    *(v37 + 4) = v35;
  }
}

// 0x1162180
void effPCPZiodin01SetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPZiodin01_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPZiodin01_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[2].monitor) = abgr;
}

// 0x1161f60
void effPCPZiodin01SetPosition(void **hData, sdfVector4_t pPos) {
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
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != effPCPZiodin01_tag)
    {
      sub_8FC2C0(*(v9 + 64), effPCPZiodin01_tag, v13);
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

// 0x1162090
void effPCPZiodin01SetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPZiodin01_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPZiodin01_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *(&(*hData)[2].klass + 1) = scale;
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
  u64 *v5;
  s64 *v6;
  Il2CppClass *v7;
  s64 *Interface;
  char *v9;
  s64 *v10;
  u64 *v11;
  effPCPZiodin02_tag_o *v14;
  u64 v15[3];
  s32 pos;

  pos = bPos;
  v14 = 0;
  v5 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v5);
  v6 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(v6, byte);
    if (!Interface)
    {
      sub_8FC2C0(*(*v6 + 64), v7, v15);
      if ((v15[0] & 1) != 0)
        v9 = v15[2];
      else
        v9 = v15 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v5, Interface, &pos);
  v11 = Allocate(effPCPZiodin02_tag);
  _ctor(v11, 0);
  v14 = v11;
  effPCPZiodin02Init(&v14);
  return v11;
}

// 0x1162b10
void effPCPZiodin02Delete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppClass *v8;
  Il2CppClass *v10;
  Il2CppClass *v12;
  Il2CppClass *v14;
  Il2CppClass *v16;
  Il2CppClass *v18;
  Il2CppClass *v20;
  Il2CppClass *v22;
  Il2CppClass *v24;
  Il2CppClass *v26;
  Il2CppClass *v28;
  Il2CppClass *v30;
  Il2CppObject *data;
  u64 v33[3];

  data = 0;
  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPZiodin02_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPZiodin02_tag, v33);
      if ((v33[0] & 1) != 0)
        v6 = v33[2];
      else
        v6 = v33 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = v3[3].klass;
  data = v8->_1.byval_arg.data;
  effPCP_ThunderPolyDelete(&data);
  v10 = v3[3].klass;
  data = *&v10->_1.byval_arg.bits;
  effPCP_ThunderPolyDelete(&data);
  v12 = v3[3].klass;
  data = v12->_1.this_arg.data;
  effPCP_ThunderPolyDelete(&data);
  v14 = v3[3].klass;
  data = *&v14->_1.this_arg.bits;
  effPCP_ThunderPolyDelete(&data);
  v16 = v3[3].klass;
  data = v16->_1.element_class;
  effPCP_ThunderPolyDelete(&data);
  v18 = v3[3].klass;
  data = v18->_1.castClass;
  effPCP_ThunderPolyDelete(&data);
  v20 = v3[3].klass;
  data = v20->_1.declaringType;
  effPCP_ThunderPolyDelete(&data);
  v22 = v3[3].klass;
  data = v22->_1.parent;
  effPCP_ThunderPolyDelete(&data);
  v24 = v3[3].klass;
  data = v24->_1.generic_class;
  effPCP_ThunderPolyDelete(&data);
  v26 = v3[3].klass;
  data = v26->_1.typeDefinition;
  effPCP_ThunderPolyDelete(&data);
  v28 = v3[3].klass;
  data = v28->_1.interopData;
  effPCP_ThunderPolyDelete(&data);
  v30 = v3[3].klass;
  data = v30->_1.klass;
  effPCP_ThunderPolyDelete(&data);
}

// 0x1162f10
void effPCPZiodin02Draw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  s64 i;
  Il2CppClass *v12;
  effPCP_ThunderPolyParam_t_o *Param;
  struct UnityEngine_Vector4_array *pos;
  effPCP_ThunderPolyParam_t_o *v16;
  struct UnityEngine_Vector4_array *v19;
  struct UnityEngine_Vector4_array *v21;
  struct UnityEngine_Vector4_array *v24;
  Il2CppClass *v26;
  struct UnityEngine_Vector4_array *v28;
  struct UnityEngine_Vector4_array *v29;
  Il2CppObject *v32;
  u64 v33[3];

  v32 = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPZiodin02_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPZiodin02_tag, v33);
      if ((v33[0] & 1) != 0)
        v6 = v33[2];
      else
        v6 = v33 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = NewSpecific(UnityEngine_Vector4, 2u);
  for (i = 4; i != 16; ++i)
  {
    v12 = v3[3].klass;
    Param = effPCP_ThunderPolyGetParam(*(&v12->_1.image + i), 0);
    pos = Param->pos;
    v16 = Param;
    SDF_VU0__LOADVECTOR(pos->m_Items[1]);
    SDF_VU0__STOREVECTOR(v8 + 3);
    SDF_VU0__LOADVECTOR_B(v3[1]);
    SDF_VU0__ADDVECTOR();
    v19 = v16->pos;
    SDF_VU0__STOREVECTOR(&v19->m_Items[1]);
    v21 = v16->pos;
    SDF_VU0__LOADVECTOR(v21->m_Items[0]);
    SDF_VU0__STOREVECTOR(v8 + 2);
    SDF_VU0__ADDVECTOR();
    v24 = v16->pos;
    SDF_VU0__STOREVECTOR(v24->m_Items);
    v26 = v3[3].klass;
    v32 = *(&v26->_1.image + i);
    effPCP_ThunderPolyDraw(&v32);
    v28 = v16->pos;
    SDF_VU0__COPYVECTOR(v28->m_Items, *(v8 + 2), 0);
    v29 = v16->pos;
    SDF_VU0__COPYVECTOR(&v29->m_Items[1], *(v8 + 3), 0);
  }
}

// 0x1162270
void effPCPZiodin02Init(effPCPZiodin02_tag **pPCPZiodin02) {
  effPCPZiodin02_tag_o *v3;
  u64 v5;
  f32 v8;
  f32 v10;
  struct UnityEngine_Vector4_array *pos;
  struct UnityEngine_Vector4_array *v13;
  struct UnityEngine_Vector4_array *v15;
  f32 v18;
  s64 v19;
  s64 v20;
  f32 v21;
  f32 v22;
  struct UnityEngine_Vector4_array *v23;
  f32 v25;
  struct UnityEngine_Vector4_array *v26;
  struct UnityEngine_Vector4_array *v28;
  struct UnityEngine_Vector4_array *v30;
  struct UnityEngine_Vector4_array *v32;
  struct UnityEngine_Vector4_array *v34;
  s64 m_Items;
  struct UnityEngine_Vector4_array *v37;
  struct UnityEngine_Vector4_array *v39;
  s64 v41;
  struct UnityEngine_Vector4_array *v42;
  f32 v45;
  f32 v46;
  u32 v47;
  s16 v48;
  f32 v49;
  u32 v51;
  u16 v53;
  u32 *pThunderPoly;
  s64 *v55;
  s64 *v56;
  u32 *v58;
  f32 aRadius;
  s64 v60;
  s64 v61;
  Il2CppObject *hData;
  UnityEngine_Vector4_o v63;

  hData = 0;
  v60 = 0;
  v61 = 0;
  v3 = *pPCPZiodin02;
  v3->pThunderPoly = NewSpecific(effPCP_ThunderPoly_t, 0xCu);
  v5 = 0;
  aRadius = 0.0;
  do
  {
    if ((v5 & 1) == 0)
    {
      sdfCos(aRadius);
      sdfSin(aRadius);
      aRadius = aRadius + 1.0472;
    }
    v8 = DDS3EFFECT_RAND_FA(0.5);
    v10 = v8;
    effPCP_Ziodin02_ThunderPoly_Param->width_border = v10 * 1.25;
    effPCP_Ziodin02_ThunderPoly_Param->width_edge = v10 * 12.5;
    DDS3EFFECT_RAND_FA(0.25);
    pos = effPCP_Ziodin02_ThunderPoly_Param->pos;
    sub_854930(&pos->m_Items[1], 0);
    v13 = effPCP_Ziodin02_ThunderPoly_Param->pos;
    sub_854930(&v13->m_Items[1], 1u);
    v15 = effPCP_Ziodin02_ThunderPoly_Param->pos;
    sub_854930(&v15->m_Items[1], 2u);
    sub_854930(&v60, 0);
    sub_854930(&v60, 1u);
    sub_854930(&v60, 2u);
    v18 = DDS3EFFECT_RAND_F();
    v19 = v60;
    v20 = v61;
    v21 = -((v18 * 0.87266) + 0.087266);
    *&v63.x = v19;
    *&v63.z = v20;
    SetRotateMatrixAxis(v21, v63);
    v22 = DDS3EFFECT_RAND_FA(0.65);
    v23 = effPCP_Ziodin02_ThunderPoly_Param->pos;
    v25 = v22 * 500.0;
    sub_854930(v23->m_Items, 0);
    v26 = effPCP_Ziodin02_ThunderPoly_Param->pos;
    sub_854930(v26->m_Items, 1u);
    v28 = effPCP_Ziodin02_ThunderPoly_Param->pos;
    sub_854930(v28->m_Items, 2u);
    v30 = effPCP_Ziodin02_ThunderPoly_Param->pos;
    SDF_VU0__LOADVECTOR(v30->m_Items[0]);
    SDF_VU0__APPLYMATRIX_XYZ();
    v32 = effPCP_Ziodin02_ThunderPoly_Param->pos;
    SDF_VU0__STOREVECTOR(v32->m_Items);
    v34 = effPCP_Ziodin02_ThunderPoly_Param->pos;
    m_Items = v34->m_Items;
    sub_854710(m_Items, 0);
    v37 = effPCP_Ziodin02_ThunderPoly_Param->pos;
    sub_854710(&v37->m_Items[1], 0);
    sub_854930(m_Items, 0);
    v39 = effPCP_Ziodin02_ThunderPoly_Param->pos;
    v41 = v39->m_Items;
    sub_854710(v41, 2u);
    v42 = effPCP_Ziodin02_ThunderPoly_Param->pos;
    sub_854710(&v42->m_Items[1], 2u);
    sub_854930(v41, 2u);
    if (v25 >= 300.0)
    {
      v45 = 5.0;
      v46 = 10.0;
      v48 = 15;
      v47 = 6;
    }
    else
    {
      v45 = 2.5;
      v46 = 5.0;
      v47 = 5;
      v48 = 5;
      {
        v45 = 2.5;
        v46 = 5.0;
        v47 = 5;
        v48 = 5;
      }
    }
    v49 = (DDS3EFFECT_RAND_PM() * v45) + v46;
    v51 = DDS3EFFECT_RAND_I() % v47;
    v53 = v51 + v48;
    effPCP_Ziodin02_ThunderPoly_Param->split = v53;
    effPCP_Ziodin02_ThunderPoly_Param->refraction = v49;
    hData = effPCP_Ziodin02_ThunderPoly_Param;
    pThunderPoly = (*pPCPZiodin02)->pThunderPoly;
    v55 = effPCP_ThunderPolyCreate(&hData, 0, 1, 0);
    v56 = v55;
    v58 = &pThunderPoly[2 * v5++];
    *(v58 + 4) = v56;
  }
  while (v5 != 12);
}

// 0x11634d0
void effPCPZiodin02SetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPZiodin02_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPZiodin02_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[2].monitor) = abgr;
}

// 0x11632b0
void effPCPZiodin02SetPosition(void **hData, sdfVector4_t pPos) {
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
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != effPCPZiodin02_tag)
    {
      sub_8FC2C0(*(v9 + 64), effPCPZiodin02_tag, v13);
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

// 0x11633e0
void effPCPZiodin02SetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPZiodin02_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPZiodin02_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *(&(*hData)[2].klass + 1) = scale;
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
  u64 *v5;
  s64 *v6;
  Il2CppClass *v7;
  s64 *Interface;
  char *v9;
  s64 *v10;
  u64 *v11;
  effPCPZiodin03_tag_o *v14;
  u64 v15[3];
  s32 pos;

  pos = bPos;
  v14 = 0;
  v5 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v5);
  v6 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(v6, byte);
    if (!Interface)
    {
      sub_8FC2C0(*(*v6 + 64), v7, v15);
      if ((v15[0] & 1) != 0)
        v9 = v15[2];
      else
        v9 = v15 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v5, Interface, &pos);
  v11 = Allocate(effPCPZiodin03_tag);
  _ctor(v11, 0);
  v14 = v11;
  effPCPZiodin03Init(&v14);
  return v11;
}

// 0x1163e70
void effPCPZiodin03Delete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 i;
  Il2CppClass *v9;
  Il2CppObject *v11[3];
  Il2CppObject *hDataa;

  hDataa = 0;
  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPZiodin03_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPZiodin03_tag, v11);
      if ((v11[0] & 1) != 0)
        v6 = v11[2];
      else
        v6 = v11 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  for (i = 0; i != 30; ++i)
  {
    v9 = v3[3].klass;
    hDataa = *(&v9->_1.byval_arg.data + i);
    effPCP_ThunderPolyDelete(&hDataa);
  }
}

// 0x1164040
void effPCPZiodin03Draw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  s64 i;
  Il2CppClass *v12;
  effPCP_ThunderPolyParam_t_o *Param;
  struct UnityEngine_Vector4_array *pos;
  effPCP_ThunderPolyParam_t_o *v16;
  struct UnityEngine_Vector4_array *v19;
  struct UnityEngine_Vector4_array *v21;
  struct UnityEngine_Vector4_array *v24;
  Il2CppClass *v26;
  struct UnityEngine_Vector4_array *v28;
  struct UnityEngine_Vector4_array *v29;
  Il2CppObject *v32;
  u64 v33[3];

  v32 = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPZiodin03_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPZiodin03_tag, v33);
      if ((v33[0] & 1) != 0)
        v6 = v33[2];
      else
        v6 = v33 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = NewSpecific(UnityEngine_Vector4, 2u);
  for (i = 4; i != 34; ++i)
  {
    v12 = v3[3].klass;
    Param = effPCP_ThunderPolyGetParam(*(&v12->_1.image + i), 0);
    pos = Param->pos;
    v16 = Param;
    SDF_VU0__LOADVECTOR(pos->m_Items[1]);
    SDF_VU0__STOREVECTOR(v8 + 3);
    SDF_VU0__LOADVECTOR_B(v3[1]);
    SDF_VU0__ADDVECTOR();
    v19 = v16->pos;
    SDF_VU0__STOREVECTOR(&v19->m_Items[1]);
    v21 = v16->pos;
    SDF_VU0__LOADVECTOR(v21->m_Items[0]);
    SDF_VU0__STOREVECTOR(v8 + 2);
    SDF_VU0__ADDVECTOR();
    v24 = v16->pos;
    SDF_VU0__STOREVECTOR(v24->m_Items);
    v26 = v3[3].klass;
    v32 = *(&v26->_1.image + i);
    effPCP_ThunderPolyDraw(&v32);
    v28 = v16->pos;
    SDF_VU0__COPYVECTOR(v28->m_Items, *(v8 + 2), 0);
    v29 = v16->pos;
    SDF_VU0__COPYVECTOR(&v29->m_Items[1], *(v8 + 3), 0);
  }
}

// 0x11635c0
void effPCPZiodin03Init(effPCPZiodin03_tag **pPCPZiodin03) {
  __int128 v2;
  effPCPZiodin03_tag_o *v4;
  u64 v6;
  f32 v9;
  f32 v11;
  struct UnityEngine_Vector4_array *pos;
  struct UnityEngine_Vector4_array *v14;
  __int128 v16;
  struct UnityEngine_Vector4_array *v17;
  f32 v20;
  s64 v21;
  s64 v22;
  f32 v23;
  f32 v24;
  struct UnityEngine_Vector4_array *v25;
  f32 v27;
  struct UnityEngine_Vector4_array *v28;
  struct UnityEngine_Vector4_array *v30;
  struct UnityEngine_Vector4_array *v32;
  struct UnityEngine_Vector4_array *v34;
  struct UnityEngine_Vector4_array *v36;
  s64 m_Items;
  struct UnityEngine_Vector4_array *v39;
  struct UnityEngine_Vector4_array *v41;
  s64 v43;
  struct UnityEngine_Vector4_array *v44;
  f32 v47;
  f32 v48;
  u32 v49;
  s16 v50;
  f32 v51;
  u32 v53;
  u16 v55;
  u32 *pThunderPoly;
  s64 *v57;
  s64 *v58;
  u32 *v60;
  f32 aRadius;
  s64 v62;
  s64 v63;
  Il2CppObject *hData;
  UnityEngine_Vector4_o v65;

  hData = 0;
  v62 = 0;
  v63 = 0;
  v4 = *pPCPZiodin03;
  v4->pThunderPoly = NewSpecific(effPCP_ThunderPoly_t, 0x1Eu);
  LODWORD(v2) = 0.25;
  v6 = 0;
  aRadius = 0.0;
  do
  {
    if ((v6 & 1) == 0)
    {
      sdfCos(aRadius);
      sdfSin(aRadius);
      aRadius = aRadius + 0.41888;
    }
    v9 = DDS3EFFECT_RAND_FA(0.5);
    v11 = v9;
    effPCP_Ziodin03_ThunderPoly_Param->width_border = v11 * 1.25;
    effPCP_Ziodin03_ThunderPoly_Param->width_edge = v11 * 12.5;
    pos = effPCP_Ziodin03_ThunderPoly_Param->pos;
    sub_854930(&pos->m_Items[1], 1u);
    DDS3EFFECT_RAND_FA(*&v2);
    v14 = effPCP_Ziodin03_ThunderPoly_Param->pos;
    sub_854930(&v14->m_Items[1], 0);
    v16 = v2;
    DDS3EFFECT_RAND_FA(*&v2);
    v17 = effPCP_Ziodin03_ThunderPoly_Param->pos;
    sub_854930(&v17->m_Items[1], 2u);
    sub_854930(&v62, 0);
    sub_854930(&v62, 1u);
    sub_854930(&v62, 2u);
    v20 = DDS3EFFECT_RAND_F();
    v21 = v62;
    v22 = v63;
    v23 = -((v20 * 0.95993) + 0.087266);
    *&v65.x = v21;
    *&v65.z = v22;
    SetRotateMatrixAxis(v23, v65);
    v24 = DDS3EFFECT_RAND_FA(0.65);
    v25 = effPCP_Ziodin03_ThunderPoly_Param->pos;
    v27 = v24 * 500.0;
    sub_854930(v25->m_Items, 0);
    v28 = effPCP_Ziodin03_ThunderPoly_Param->pos;
    sub_854930(v28->m_Items, 1u);
    v30 = effPCP_Ziodin03_ThunderPoly_Param->pos;
    sub_854930(v30->m_Items, 2u);
    v32 = effPCP_Ziodin03_ThunderPoly_Param->pos;
    SDF_VU0__LOADVECTOR(v32->m_Items[0]);
    SDF_VU0__APPLYMATRIX_XYZ();
    v34 = effPCP_Ziodin03_ThunderPoly_Param->pos;
    SDF_VU0__STOREVECTOR(v34->m_Items);
    v36 = effPCP_Ziodin03_ThunderPoly_Param->pos;
    m_Items = v36->m_Items;
    sub_854710(m_Items, 0);
    v39 = effPCP_Ziodin03_ThunderPoly_Param->pos;
    sub_854710(&v39->m_Items[1], 0);
    sub_854930(m_Items, 0);
    v41 = effPCP_Ziodin03_ThunderPoly_Param->pos;
    v43 = v41->m_Items;
    sub_854710(v43, 2u);
    v44 = effPCP_Ziodin03_ThunderPoly_Param->pos;
    sub_854710(&v44->m_Items[1], 2u);
    sub_854930(v43, 2u);
    if (v27 >= 300.0)
    {
      v47 = 5.0;
      v48 = 10.0;
      v50 = 15;
      v49 = 6;
    }
    else
    {
      v47 = 2.5;
      v48 = 5.0;
      v49 = 5;
      v50 = 5;
      {
        v47 = 2.5;
        v48 = 5.0;
        v49 = 5;
        v50 = 5;
      }
    }
    v51 = (DDS3EFFECT_RAND_PM() * v47) + v48;
    v53 = DDS3EFFECT_RAND_I() % v49;
    v55 = v53 + v50;
    effPCP_Ziodin03_ThunderPoly_Param->split = v55;
    effPCP_Ziodin03_ThunderPoly_Param->refraction = v51;
    hData = effPCP_Ziodin03_ThunderPoly_Param;
    pThunderPoly = (*pPCPZiodin03)->pThunderPoly;
    v2 = v16;
    v57 = effPCP_ThunderPolyCreate(&hData, 0, 1, 0);
    v58 = v57;
    v60 = &pThunderPoly[2 * v6++];
    *(v60 + 4) = v58;
  }
  while (v6 != 30);
}

// 0x1164600
void effPCPZiodin03SetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPZiodin03_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPZiodin03_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[2].monitor) = abgr;
}

// 0x11643e0
void effPCPZiodin03SetPosition(void **hData, sdfVector4_t pPos) {
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
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != effPCPZiodin03_tag)
    {
      sub_8FC2C0(*(v9 + 64), effPCPZiodin03_tag, v13);
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

// 0x1164510
void effPCPZiodin03SetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPZiodin03_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPZiodin03_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *(&(*hData)[2].klass + 1) = scale;
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
  u64 *v5;
  s64 *v6;
  Il2CppClass *v7;
  s64 *Interface;
  char *v9;
  s64 *v10;
  u64 *v11;
  effPCPZiodin04_tag_o *v14;
  u64 v15[3];
  s32 pos;

  pos = bPos;
  v14 = 0;
  v5 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v5);
  v6 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(v6, byte);
    if (!Interface)
    {
      sub_8FC2C0(*(*v6 + 64), v7, v15);
      if ((v15[0] & 1) != 0)
        v9 = v15[2];
      else
        v9 = v15 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v5, Interface, &pos);
  v11 = Allocate(effPCPZiodin04_tag);
  _ctor(v11, 0);
  v14 = v11;
  effPCPZiodin04Init(&v14);
  return v11;
}

// 0x1164f90
void effPCPZiodin04Delete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppClass *v8;
  Il2CppClass *v10;
  Il2CppClass *v12;
  Il2CppClass *v14;
  Il2CppClass *v16;
  Il2CppClass *v18;
  Il2CppClass *v20;
  Il2CppClass *v22;
  Il2CppClass *v24;
  Il2CppClass *v26;
  Il2CppClass *v28;
  Il2CppClass *v30;
  Il2CppObject *data;
  u64 v33[3];

  data = 0;
  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPZiodin04_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPZiodin04_tag, v33);
      if ((v33[0] & 1) != 0)
        v6 = v33[2];
      else
        v6 = v33 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = v3[3].klass;
  data = v8->_1.byval_arg.data;
  effPCP_ThunderPolyDelete(&data);
  v10 = v3[3].klass;
  data = *&v10->_1.byval_arg.bits;
  effPCP_ThunderPolyDelete(&data);
  v12 = v3[3].klass;
  data = v12->_1.this_arg.data;
  effPCP_ThunderPolyDelete(&data);
  v14 = v3[3].klass;
  data = *&v14->_1.this_arg.bits;
  effPCP_ThunderPolyDelete(&data);
  v16 = v3[3].klass;
  data = v16->_1.element_class;
  effPCP_ThunderPolyDelete(&data);
  v18 = v3[3].klass;
  data = v18->_1.castClass;
  effPCP_ThunderPolyDelete(&data);
  v20 = v3[3].klass;
  data = v20->_1.declaringType;
  effPCP_ThunderPolyDelete(&data);
  v22 = v3[3].klass;
  data = v22->_1.parent;
  effPCP_ThunderPolyDelete(&data);
  v24 = v3[3].klass;
  data = v24->_1.generic_class;
  effPCP_ThunderPolyDelete(&data);
  v26 = v3[3].klass;
  data = v26->_1.typeDefinition;
  effPCP_ThunderPolyDelete(&data);
  v28 = v3[3].klass;
  data = v28->_1.interopData;
  effPCP_ThunderPolyDelete(&data);
  v30 = v3[3].klass;
  data = v30->_1.klass;
  effPCP_ThunderPolyDelete(&data);
}

// 0x1165390
void effPCPZiodin04Draw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  s64 i;
  Il2CppClass *v12;
  effPCP_ThunderPolyParam_t_o *Param;
  struct UnityEngine_Vector4_array *pos;
  effPCP_ThunderPolyParam_t_o *v16;
  struct UnityEngine_Vector4_array *v19;
  struct UnityEngine_Vector4_array *v21;
  struct UnityEngine_Vector4_array *v24;
  Il2CppClass *v26;
  struct UnityEngine_Vector4_array *v28;
  struct UnityEngine_Vector4_array *v29;
  Il2CppObject *v32;
  u64 v33[3];

  v32 = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPZiodin04_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPZiodin04_tag, v33);
      if ((v33[0] & 1) != 0)
        v6 = v33[2];
      else
        v6 = v33 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = NewSpecific(UnityEngine_Vector4, 2u);
  for (i = 4; i != 16; ++i)
  {
    v12 = v3[3].klass;
    Param = effPCP_ThunderPolyGetParam(*(&v12->_1.image + i), 0);
    pos = Param->pos;
    v16 = Param;
    SDF_VU0__LOADVECTOR(pos->m_Items[1]);
    SDF_VU0__STOREVECTOR(v8 + 3);
    SDF_VU0__LOADVECTOR_B(v3[1]);
    SDF_VU0__ADDVECTOR();
    v19 = v16->pos;
    SDF_VU0__STOREVECTOR(&v19->m_Items[1]);
    v21 = v16->pos;
    SDF_VU0__LOADVECTOR(v21->m_Items[0]);
    SDF_VU0__STOREVECTOR(v8 + 2);
    SDF_VU0__ADDVECTOR();
    v24 = v16->pos;
    SDF_VU0__STOREVECTOR(v24->m_Items);
    v26 = v3[3].klass;
    v32 = *(&v26->_1.image + i);
    effPCP_ThunderPolyDraw(&v32);
    v28 = v16->pos;
    SDF_VU0__COPYVECTOR(v28->m_Items, *(v8 + 2), 0);
    v29 = v16->pos;
    SDF_VU0__COPYVECTOR(&v29->m_Items[1], *(v8 + 3), 0);
  }
}

// 0x11646f0
void effPCPZiodin04Init(effPCPZiodin04_tag **pPCPZiodin04) {
  effPCPZiodin04_tag_o *v3;
  u64 v5;
  f32 v8;
  f32 v10;
  struct UnityEngine_Vector4_array *pos;
  struct UnityEngine_Vector4_array *v13;
  struct UnityEngine_Vector4_array *v15;
  f32 v18;
  s64 v19;
  s64 v20;
  f32 v21;
  f32 v22;
  struct UnityEngine_Vector4_array *v23;
  f32 v25;
  struct UnityEngine_Vector4_array *v26;
  struct UnityEngine_Vector4_array *v28;
  struct UnityEngine_Vector4_array *v30;
  struct UnityEngine_Vector4_array *v32;
  struct UnityEngine_Vector4_array *v34;
  s64 m_Items;
  struct UnityEngine_Vector4_array *v37;
  struct UnityEngine_Vector4_array *v39;
  s64 v41;
  struct UnityEngine_Vector4_array *v42;
  f32 v45;
  f32 v46;
  u32 v47;
  s16 v48;
  f32 v49;
  u32 v51;
  u16 v53;
  u32 *pThunderPoly;
  s64 *v55;
  s64 *v56;
  u32 *v58;
  f32 aRadius;
  s64 v60;
  s64 v61;
  Il2CppObject *hData;
  UnityEngine_Vector4_o v63;

  hData = 0;
  v60 = 0;
  v61 = 0;
  v3 = *pPCPZiodin04;
  v3->pThunderPoly = NewSpecific(effPCP_ThunderPoly_t, 0xCu);
  v5 = 0;
  aRadius = 0.0;
  do
  {
    if ((v5 & 1) == 0)
    {
      sdfCos(aRadius);
      sdfSin(aRadius);
      aRadius = aRadius + 1.0472;
    }
    v8 = DDS3EFFECT_RAND_FA(0.5);
    v10 = v8;
    effPCP_Ziodin04_ThunderPoly_Param->width_border = v10 * 1.25;
    effPCP_Ziodin04_ThunderPoly_Param->width_edge = v10 * 12.5;
    DDS3EFFECT_RAND_FA(0.25);
    pos = effPCP_Ziodin04_ThunderPoly_Param->pos;
    sub_854930(&pos->m_Items[1], 0);
    v13 = effPCP_Ziodin04_ThunderPoly_Param->pos;
    sub_854930(&v13->m_Items[1], 1u);
    v15 = effPCP_Ziodin04_ThunderPoly_Param->pos;
    sub_854930(&v15->m_Items[1], 2u);
    sub_854930(&v60, 0);
    sub_854930(&v60, 1u);
    sub_854930(&v60, 2u);
    v18 = DDS3EFFECT_RAND_F();
    v19 = v60;
    v20 = v61;
    v21 = -((v18 * 0.95993) + 0.087266);
    *&v63.x = v19;
    *&v63.z = v20;
    SetRotateMatrixAxis(v21, v63);
    v22 = DDS3EFFECT_RAND_FA(0.65);
    v23 = effPCP_Ziodin04_ThunderPoly_Param->pos;
    v25 = v22 * 500.0;
    sub_854930(v23->m_Items, 0);
    v26 = effPCP_Ziodin04_ThunderPoly_Param->pos;
    sub_854930(v26->m_Items, 1u);
    v28 = effPCP_Ziodin04_ThunderPoly_Param->pos;
    sub_854930(v28->m_Items, 2u);
    v30 = effPCP_Ziodin04_ThunderPoly_Param->pos;
    SDF_VU0__LOADVECTOR(v30->m_Items[0]);
    SDF_VU0__APPLYMATRIX_XYZ();
    v32 = effPCP_Ziodin04_ThunderPoly_Param->pos;
    SDF_VU0__STOREVECTOR(v32->m_Items);
    v34 = effPCP_Ziodin04_ThunderPoly_Param->pos;
    m_Items = v34->m_Items;
    sub_854710(m_Items, 0);
    v37 = effPCP_Ziodin04_ThunderPoly_Param->pos;
    sub_854710(&v37->m_Items[1], 0);
    sub_854930(m_Items, 0);
    v39 = effPCP_Ziodin04_ThunderPoly_Param->pos;
    v41 = v39->m_Items;
    sub_854710(v41, 2u);
    v42 = effPCP_Ziodin04_ThunderPoly_Param->pos;
    sub_854710(&v42->m_Items[1], 2u);
    sub_854930(v41, 2u);
    if (v25 >= 300.0)
    {
      v45 = 5.0;
      v46 = 10.0;
      v48 = 15;
      v47 = 6;
    }
    else
    {
      v45 = 2.5;
      v46 = 5.0;
      v47 = 5;
      v48 = 5;
      {
        v45 = 2.5;
        v46 = 5.0;
        v47 = 5;
        v48 = 5;
      }
    }
    v49 = (DDS3EFFECT_RAND_PM() * v45) + v46;
    v51 = DDS3EFFECT_RAND_I() % v47;
    v53 = v51 + v48;
    effPCP_Ziodin04_ThunderPoly_Param->split = v53;
    effPCP_Ziodin04_ThunderPoly_Param->refraction = v49;
    hData = effPCP_Ziodin04_ThunderPoly_Param;
    pThunderPoly = (*pPCPZiodin04)->pThunderPoly;
    v55 = effPCP_ThunderPolyCreate(&hData, 0, 1, 0);
    v56 = v55;
    v58 = &pThunderPoly[2 * v5++];
    *(v58 + 4) = v56;
  }
  while (v5 != 12);
}

// 0x1165950
void effPCPZiodin04SetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPZiodin04_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPZiodin04_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[2].monitor) = abgr;
}

// 0x1165730
void effPCPZiodin04SetPosition(void **hData, sdfVector4_t pPos) {
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
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != effPCPZiodin04_tag)
    {
      sub_8FC2C0(*(v9 + 64), effPCPZiodin04_tag, v13);
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

// 0x1165860
void effPCPZiodin04SetScale(void **hData, f32 scale) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPZiodin04_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPZiodin04_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  *(&(*hData)[2].klass + 1) = scale;
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
