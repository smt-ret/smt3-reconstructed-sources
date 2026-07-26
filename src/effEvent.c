#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct AssetBundles AssetBundles;
typedef struct XRD773Unity_CommonMesh XRD773Unity_CommonMesh;
typedef struct XRD773Unity_GraphicManager XRD773Unity_GraphicManager;
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
typedef struct effAPPoint4Param_t effAPPoint4Param_t;
typedef struct effAPPoint4_tag effAPPoint4_tag;
typedef struct effBTLCutHandle_t effBTLCutHandle_t;
typedef struct effBTL_SkillPositionPtr_t effBTL_SkillPositionPtr_t;
typedef struct effBTL_t effBTL_t;
typedef struct effBezier4PPart_t effBezier4PPart_t;
typedef struct effBezier4P_t effBezier4P_t;
typedef struct effDistortionBlurHandle_t effDistortionBlurHandle_t;
typedef struct effEVECombParSmokeParam_t effEVECombParSmokeParam_t;
typedef struct effEVECombParSmoke_t effEVECombParSmoke_t;
typedef struct effEveAPP4Point_t effEveAPP4Point_t;
typedef struct effEveBEDCutHandle_t effEveBEDCutHandle_t;
typedef struct effEveBEDParams_t effEveBEDParams_t;
typedef struct effHandle_t effHandle_t;
typedef struct effPartHandle_t effPartHandle_t;
typedef struct effRippleBlurHandle_t effRippleBlurHandle_t;
typedef struct effSimpleBED_t effSimpleBED_t;
typedef struct effViewer_Menu_Item_t effViewer_Menu_Item_t;
typedef struct effViewer_Menu_t effViewer_Menu_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct mdlManager_mdlTbMbAbLoadCb_t mdlManager_mdlTbMbAbLoadCb_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfGrPacketHeader_t sdfGrPacketHeader_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

static dds3Effect_Blur_t *Eve_Blur;
static effDistortionBlurHandle_t *hEve_DistortionBlur;
static dds3Effect_DistortionBlurParam_t *Eve_DistortionBlurParam;
static dds3Effect_PartialMultiBlur_t *hEve_PartialMultiBlur;
static dds3Effect_PartialMultiBlurParam_t *Eve_PartialMultiBlurParam;
static dds3Effect_Filter_t *Eve_Filter;
static dds3Effect_PartialMultiFilter_t *hEve_PartialMultiFilter;
static dds3Effect_PartialMultiFilterParam_t *Eve_PartialMultiFilterParam;
static effRippleBlurHandle_t *hEve_RippleBlur;
static dds3Effect_RippleBlurParam_t *Eve_RippleBlurParam;
static s32 Eve_BlurShow;
static s32 Eve_PartialMultiBlurShow;
static s32 Eve_DistortionBlurShow;
static s32 Eve_FilterShow;
static s32 Eve_PartialMultiFilterShow;
static s32 Eve_RippleBlurShow;
static dds3Effect_Blur_t *effEvent_Edit_Blur_Def;
static dds3Effect_Blur_t *effEvent_Edit_Blur;
static effViewer_Menu_Item_t effEvent_Edit_MenuItem[UNKNOWN_ARRAY_SIZE];
static dds3Effect_Blur_t *pEffEvent_Edit_Blur;
static effViewer_Menu_t *effEvent_Edit_Blur_Menu;
static s32 Eve_BlurEditorRunFlag;
static dds3Effect_PartialMultiBlur_t *hEffEvent_Edit_PartialMultiBlur;
static dds3Effect_PartialMultiBlurParam_t *effEvent_Edit_PartialMultiBlurParam_Def;
static dds3Effect_PartialMultiBlurParam_t *effEvent_Edit_PartialMultiBlurParam;
static effViewer_Menu_Item_t effEvent_Edit_PartialMultiBlur_MenuItem[UNKNOWN_ARRAY_SIZE];
static effViewer_Menu_t *effEvent_Edit_PartialMultiBlur_Menu;
static s32 Eve_PartialMultiBlurEditorRunFlag;
static effDistortionBlurHandle_t *hEffEvent_Edit_DistortionBlur;
static dds3Effect_DistortionBlurParam_t *effEvent_Edit_DistortionBlurParam_Def;
static dds3Effect_DistortionBlurParam_t *effEvent_Edit_DistortionBlurParam;
static effViewer_Menu_Item_t effEvent_Edit_DistortionBlur_MenuItem[UNKNOWN_ARRAY_SIZE];
static effViewer_Menu_t *effEvent_Edit_DistortionBlur_Menu;
static s32 Eve_DistortionBlurEditorRunFlag;
static dds3Effect_Filter_t *effEvent_Edit_Filter_Def;
static dds3Effect_Filter_t *effEvent_Edit_Filter;
static effViewer_Menu_Item_t effEvent_Edit_Filter_MenuItem[UNKNOWN_ARRAY_SIZE];
static dds3Effect_Filter_t *pEffEvent_Edit_Filter;
static effViewer_Menu_t *effEvent_Edit_Filter_Menu;
static s32 Eve_FilterEditorRunFlag;
static dds3Effect_PartialMultiFilter_t *hEffEvent_Edit_PartialMultiFilter;
static dds3Effect_PartialMultiFilterParam_t *effEvent_Edit_PartialMultiFilterParam_Def;
static dds3Effect_PartialMultiFilterParam_t *effEvent_Edit_PartialMultiFilterParam;
static effViewer_Menu_Item_t effEvent_Edit_PartialMultiFilter_MenuItem[UNKNOWN_ARRAY_SIZE];
static effViewer_Menu_t *effEvent_Edit_PartialMultiFilter_Menu;
static s32 Eve_PartialMultiFilterEditorRunFlag;
static effRippleBlurHandle_t *hEffEvent_Edit_RippleBlur;
static dds3Effect_RippleBlurParam_t *effEvent_Edit_RippleBlurParam_Def;
static dds3Effect_RippleBlurParam_t *effEvent_Edit_RippleBlurParam;
static effViewer_Menu_Item_t effEvent_Edit_RippleBlur_MenuItem[UNKNOWN_ARRAY_SIZE];
static effViewer_Menu_t *effEvent_Edit_RippleBlur_Menu;
static s32 Eve_RippleBlurEditorRunFlag;
static f32 effEveBED_Ptr_H[6];
static f32 effEveBED_Ptr_D[11];
static u32 EffEveCPSmokeCount;
static billHandle_t *hEffEveCPSmokeBill01;
static billHandle_t *hEffEveCPSmokeBill02;
static void *hEffEveCPSmokeBill01Tex;
static void *hEffEveCPSmokeBill02Tex;
static effEVECombParSmokeParam_t *EVE_ParSmokeParam;

void Clear(mdlManager_mdlTbMbAbLoadCb_t *this);
f32 DDS3EFFECT_RAND_F(void);
f32 DDS3EFFECT_RAND_FA(f32 r);
u32 DDS3EFFECT_RAND_I(void);
f32 DDS3EFFECT_RAND_PM(void);
void *GetEffPCPAgiFireballPart(void *hData, s32 offset);
XRD773Unity_CommonMesh *GetMesh(XRD773Unity_GraphicManager *this, s32 index, bool outlinechk);
bool IsLoad(AssetBundles *this, char *key);
void Load(char *key, char *filePath);
void *LoadFileObject(AssetBundleCtrl *this, char *key, char *path_name);
void LookAtMatrix(sdfVector4_t aTarget, sdfVector4_t aEye, sdfVector4_t aDown);
void Mult(void);
void MultMatrixNoArg(void);
void ReverseMatrix(void);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__ADDVECTOR_A_C(void);
void SDF_VU0__APPLYMATRIX(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__COPYVECTOR_A_TO_C(void);
void SDF_VU0__LOADMATRIX_B(sdfMatrix4_t *aMatrix);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__MULVECTOR(void);
void SDF_VU0__NORMALIZE(void);
void SDF_VU0__OUTERPRODUCT(void);
sdfVector4_t SDF_VU0__Retdds3ColorItoF(u32 rgba, f32 ratio);
void SDF_VU0__STOREMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
void SDF_VU0__VECTOR_W_SET_ZERO(void);
void SetColor_20241296(XRD773Unity_CommonMesh *this, sdfColor_t **col);
void SetIndexTable(XRD773Unity_CommonMesh *this, s32 **idx);
void SetMatTexture(XRD773Unity_CommonMesh *this, void *texture);
void SetPosition_20241056(XRD773Unity_CommonMesh *this, sdfVector3_t **pos);
void SetRotateMatrixY_B(f32 aAngle);
void SetUvTable_20243232(XRD773Unity_CommonMesh *this, sdfVector2_t **pos);
void ToMatrix(void);
void UnloadAB(AssetBundleCtrl *this, char *key);
effBezier4P_t *dds3Bezier4PCreate(u32 number);
void dds3Bezier4PDelete(effBezier4P_t *pEffBezier4P);
effBezier4PPart_t *dds3Bezier4PGetPart(effBezier4P_t **pEffBezier4P, u32 index);
s32 dds3Bezier4PRun(effBezier4P_t **pEffBezier4P, u32 index, sdfVector4_t *pOut);
void dds3BillboardDelete(void **hData);
sdfTexHandle_t *dds3BillboardGetGeneralTex(s32 number);
void dds3EffectBlur(dds3Effect_Blur_t **pBlur, bool bPS2mode, s32 SkillID);
void dds3EffectDistortionBlurDraw(effDistortionBlurHandle_t **hDistortionBlur, bool bPS2mode, s32 SkillID);
void dds3EffectFilter(dds3Effect_Filter_t *pFilter);
void *dds3EffectPCPDataGetData(void *hData, u32 number, s32 type);
u32 dds3EffectPCPDataGetType(dds3EffectPCPData_t **hPCPData, u32 number);
void dds3EffectPCPData_t__pCopy(dds3EffectPCPData_t *this, u8 **bytedata, s32 *pos);
effPartHandle_t *dds3EffectPartCopy(effPartHandle_t **hEffPartSrc);
effPartHandle_t *dds3EffectPartCreate(u16 type, void *pData);
void dds3EffectPartDelete(effPartHandle_t **hEffPart);
void dds3EffectPartDraw(effPartHandle_t **hEffPart);
void dds3EffectPartSetColor(effPartHandle_t **hEffPart, u32 abgr);
void dds3EffectPartSetPosition(effPartHandle_t **hEffPart, sdfVector4_t pPos);
void dds3EffectPartSetRotateMatrix(effPartHandle_t **hEffPart, sdfMatrix4_t *pMatrix);
void dds3EffectPartialMultiBlurDraw(dds3Effect_PartialMultiBlur_t **hPartialMultiBlur, bool bPS2mode, s32 SkillID);
void dds3EffectPartialMultiFilterDraw(dds3Effect_PartialMultiFilter_t **hPartialMultiFilter);
effRippleBlurHandle_t *dds3EffectRippleBlurCreate(dds3Effect_RippleBlurParam_t *pParam);
void dds3EffectRippleBlurDelete(effRippleBlurHandle_t **hRippleBlur);
void dds3EffectRippleBlurDraw(effRippleBlurHandle_t **hRippleBlur, bool UnityCalc);
effAPPoint4_tag *effAPPoint4Create(effAPPoint4Param_t *pParams, u16 type, void *pData);
void effAPPoint4PartInit(effAPPoint4_tag **pAPPoint4, u32 index);
effBTL_t *effBTLCreate(u8 **pData);
effBTLCutHandle_t *effBTLCutCreate(effBTL_t **hBTLEffect, u16 CutNum, nbFormation_t *pFormation, u32 stat);
void effBTLCutDelete(effBTLCutHandle_t **hBTLCutEffect);
void effBTLCutSetScale(effBTLCutHandle_t **hBTLCutEffect, f32 scale);
void effBTLDelete(effBTL_t **hBTLEffect);
u32 effColorBlend(u32 abgr0, u32 abgr1, f32 rate);
effEVECombParSmoke_t *effEVECombParSmokeCreate(effEVECombParSmokeParam_t *pParam);
void effEVECombParSmokePartInit(effEVECombParSmoke_t **pCombParSmoke, u32 index);
effEveBEDCutHandle_t *effEveBEDCutCreate(effBTL_t *hEveBED, u16 CutNum, effEveBEDParams_t *pParams);
void effEveBEDCutDraw(effEveBEDCutHandle_t **hEveBEDCut);
void effEveBEDPartGetPositionPtr(effEveBEDParams_t *pParams, effBTL_SkillPositionPtr_t *pPosPtr);
f32 sdfCos(f32 aRadius);
s32 sdfModelGetMarkPosMatrixUnity(sdfModelRootNode_t *aRoot, s32 aId);
s32 sdfModelGetMarkPosUnity(sdfModelRootNode_t *aRoot, s32 aId);
f32 sdfSin(f32 aRadius);

// 0x138d640
s32 Eve_BlurEditorDraw(void) {
  return Eve_BlurEditorRunFlag;
}

// 0x138d6b0
dds3Effect_Blur_t *Eve_BlurEditorGetParams(void) {
  return effEvent_Edit_Blur;
}

// 0x138b450
dds3Effect_Blur_t *Eve_BlurGetParam(void) {
  return Eve_Blur;
}

// 0x138afa0
void Eve_BlurOFF(void) {
  struct effEvent_StaticFields *static_fields;

  else
  {
    static_fields = effEvent->static_fields;
    if (static_fields->Eve_BlurShow != 1)
      return;
  }
  static_fields->Eve_BlurShow = 0;
}

// 0x138aef0
void Eve_BlurON(void) {
  struct effEvent_StaticFields *static_fields;

  else
  {
    static_fields = effEvent->static_fields;
    if (static_fields->Eve_BlurShow)
      return;
  }
  static_fields->Eve_BlurShow = 1;
}

// 0x138b050
void Eve_BlurSetParam(dds3Effect_Blur_t *pParam) {
  struct System_Int32_array *pm;
  struct System_Int32_array *v5;
  s32 v6;
  struct System_Int32_array *v7;
  struct System_Int32_array *v8;
  s32 v10;
  struct sdfIVector2_t_array *xy;
  struct sdfIVector2_t_array *v14;
  struct System_Int32_array *v15;
  struct System_Int32_array *v16;
  s32 v17;
  struct sdfIVector2_t_array *v18;
  struct sdfIVector2_t_array *v20;
  struct System_Int32_array *v21;
  struct System_Int32_array *v23;
  s32 v25;
  struct sdfIVector2_t_array *v27;
  struct sdfIVector2_t_array *v29;
  struct System_Int32_array *v30;
  struct System_Int32_array *v31;
  s32 v32;
  struct sdfIVector2_t_array *v33;
  struct sdfIVector2_t_array *v35;
  struct System_Int32_array *v36;
  struct System_Int32_array *v38;
  s32 v40;

  Eve_Blur->abgr = pParam->abgr;
  Eve_Blur->blend = pParam->blend;
  Eve_Blur->rotate = pParam->rotate;
  Eve_Blur->scale = pParam->scale;
  pm = Eve_Blur->center->pm;
  v5 = pParam->center->pm;
  v6 = v5->m_Items[0];
  pm->m_Items[0] = v6;
  v7 = Eve_Blur->center->pm;
  v8 = pParam->center->pm;
  v10 = v8->m_Items[1];
  v7->m_Items[1] = v10;
  xy = Eve_Blur->xy;
  v14 = pParam->xy;
  v15 = xy->m_Items[0]->pm;
  v16 = v14->m_Items[0]->pm;
  v17 = v16->m_Items[0];
  v15->m_Items[0] = v17;
  v18 = Eve_Blur->xy;
  v20 = pParam->xy;
  v21 = v18->m_Items[0]->pm;
  v23 = v20->m_Items[0]->pm;
  v25 = v23->m_Items[1];
  v21->m_Items[1] = v25;
  v27 = Eve_Blur->xy;
  v29 = pParam->xy;
  v30 = v27->m_Items[1]->pm;
  v31 = v29->m_Items[1]->pm;
  v32 = v31->m_Items[0];
  v30->m_Items[0] = v32;
  v33 = Eve_Blur->xy;
  v35 = pParam->xy;
  v36 = v33->m_Items[1]->pm;
  v38 = v35->m_Items[1]->pm;
  v40 = v38->m_Items[1];
  v36->m_Items[1] = v40;
}

// 0x138d720
void Eve_BlurSetParam2(dds3Effect_Blur_t *pParam) {
  struct System_Int32_array *pm;
  struct System_Int32_array *v5;
  s32 v6;
  struct System_Int32_array *v7;
  struct System_Int32_array *v8;
  s32 v10;
  struct sdfIVector2_t_array *xy;
  struct sdfIVector2_t_array *v14;
  struct System_Int32_array *v15;
  struct System_Int32_array *v16;
  s32 v17;
  struct sdfIVector2_t_array *v18;
  struct sdfIVector2_t_array *v20;
  struct System_Int32_array *v21;
  struct System_Int32_array *v23;
  s32 v25;
  struct sdfIVector2_t_array *v27;
  struct sdfIVector2_t_array *v29;
  struct System_Int32_array *v30;
  struct System_Int32_array *v31;
  s32 v32;
  struct sdfIVector2_t_array *v33;
  struct sdfIVector2_t_array *v35;
  struct System_Int32_array *v36;
  struct System_Int32_array *v38;
  s32 v40;

  Eve_Blur->abgr = pParam->abgr;
  Eve_Blur->blend = pParam->blend;
  Eve_Blur->rotate = pParam->rotate;
  Eve_Blur->scale = pParam->scale;
  pm = Eve_Blur->center->pm;
  v5 = pParam->center->pm;
  v6 = v5->m_Items[0];
  pm->m_Items[0] = v6;
  v7 = Eve_Blur->center->pm;
  v8 = pParam->center->pm;
  v10 = v8->m_Items[1];
  v7->m_Items[1] = v10;
  xy = Eve_Blur->xy;
  v14 = pParam->xy;
  v15 = xy->m_Items[0]->pm;
  v16 = v14->m_Items[0]->pm;
  v17 = v16->m_Items[0];
  v15->m_Items[0] = v17;
  v18 = Eve_Blur->xy;
  v20 = pParam->xy;
  v21 = v18->m_Items[0]->pm;
  v23 = v20->m_Items[0]->pm;
  v25 = v23->m_Items[1];
  v21->m_Items[1] = v25;
  v27 = Eve_Blur->xy;
  v29 = pParam->xy;
  v30 = v27->m_Items[1]->pm;
  v31 = v29->m_Items[1]->pm;
  v32 = v31->m_Items[0];
  v30->m_Items[0] = v32;
  v33 = Eve_Blur->xy;
  v35 = pParam->xy;
  v36 = v33->m_Items[1]->pm;
  v38 = v35->m_Items[1]->pm;
  v40 = v38->m_Items[1];
  v36->m_Items[1] = v40;
}

// 0x138e060
s32 Eve_DistortionBlurEditorDraw(void) {
  return Eve_DistortionBlurEditorRunFlag;
}

// 0x138bf40
dds3Effect_DistortionBlurParam_t *Eve_DistortionBlurEditorGetParams(void) {
  return hEve_DistortionBlur->param;
}

// 0x138e0d0
dds3Effect_DistortionBlurParam_t *Eve_DistortionBlurEditorGetParams2(void) {
  return effEvent_Edit_DistortionBlurParam;
}

// 0x138bcc0
void Eve_DistortionBlurOFF(void) {
  Eve_DistortionBlurShow = 0;
}

// 0x138bc50
void Eve_DistortionBlurON(void) {
  Eve_DistortionBlurShow = 1;
}

// 0x138c020
void Eve_DistortionBlurSetDefTex(void) {
  hEve_DistortionBlur->hAlphaTex = 0;
}

// 0x138bd50
void Eve_DistortionBlurSetParam(dds3Effect_DistortionBlurParam_t *pParam) {
  struct System_Int32_array *pm;
  struct System_Int32_array *v5;
  s32 v6;
  struct System_Int32_array *v7;
  struct System_Int32_array *v8;
  s32 v10;

  hEve_DistortionBlur->param->number = pParam->number;
  hEve_DistortionBlur->param->interval = pParam->interval;
  hEve_DistortionBlur->param->speed = pParam->speed;
  hEve_DistortionBlur->param->abgr = pParam->abgr;
  hEve_DistortionBlur->param->blend = pParam->blend;
  hEve_DistortionBlur->param->rotate = pParam->rotate;
  hEve_DistortionBlur->param->distortion = pParam->distortion;
  pm = hEve_DistortionBlur->param->center->pm;
  v5 = pParam->center->pm;
  v6 = v5->m_Items[0];
  pm->m_Items[0] = v6;
  v7 = hEve_DistortionBlur->param->center->pm;
  v8 = pParam->center->pm;
  v10 = v8->m_Items[1];
  v7->m_Items[1] = v10;
  hEve_DistortionBlur->param->area = pParam->area;
  hEve_DistortionBlur->param->width = pParam->width;
}

// 0x138e140
void Eve_DistortionBlurSetParam2(dds3Effect_DistortionBlurParam_t *pParam) {
  struct System_Int32_array *pm;
  struct System_Int32_array *v5;
  s32 v6;
  struct System_Int32_array *v7;
  struct System_Int32_array *v8;
  s32 v10;

  effEvent_Edit_DistortionBlurParam->number = pParam->number;
  effEvent_Edit_DistortionBlurParam->interval = pParam->interval;
  effEvent_Edit_DistortionBlurParam->speed = pParam->speed;
  effEvent_Edit_DistortionBlurParam->abgr = pParam->abgr;
  effEvent_Edit_DistortionBlurParam->blend = pParam->blend;
  effEvent_Edit_DistortionBlurParam->rotate = pParam->rotate;
  effEvent_Edit_DistortionBlurParam->distortion = pParam->distortion;
  pm = effEvent_Edit_DistortionBlurParam->center->pm;
  v5 = pParam->center->pm;
  v6 = v5->m_Items[0];
  pm->m_Items[0] = v6;
  v7 = effEvent_Edit_DistortionBlurParam->center->pm;
  v8 = pParam->center->pm;
  v10 = v8->m_Items[1];
  v7->m_Items[1] = v10;
  effEvent_Edit_DistortionBlurParam->area = pParam->area;
  effEvent_Edit_DistortionBlurParam->width = pParam->width;
}

// 0x138bfb0
void Eve_DistortionBlurSetTex(void *hTex) {
  hEve_DistortionBlur->hAlphaTex = hTex;
}

// 0x138d340
void Eve_EffectDraw(void) {
  if (Eve_BlurShow)
  {
    dds3EffectBlur(&Eve_Blur, 0, 0);
  }
  if (Eve_PartialMultiBlurShow)
  {
    dds3EffectPartialMultiBlurDraw(&hEve_PartialMultiBlur, 1, 0);
  }
  if (Eve_DistortionBlurShow)
  {
    dds3EffectDistortionBlurDraw(&hEve_DistortionBlur, 1, 0);
  }
  if (Eve_RippleBlurShow)
  {
    dds3EffectRippleBlurDraw(&hEve_RippleBlur, 0);
  }
  if (Eve_FilterShow)
  {
    dds3EffectFilter(&Eve_Filter, 0);
  }
  else if (!Eve_PartialMultiFilterShow)
  {
    return;
  }
  dds3EffectPartialMultiFilterDraw(&hEve_PartialMultiFilter);
}

// 0x138d130
void Eve_EffectInit(void) {
  struct dds3Effect_PartialMultiBlurParam_t_o *Eve_PartialMultiBlurParam;
  dds3Effect_PartialMultiBlur_t_o *v4;
  struct dds3Effect_DistortionBlurParam_t_o *Eve_DistortionBlurParam;
  effDistortionBlurHandle_t_o *v7;
  struct dds3Effect_PartialMultiFilterParam_t_o *Eve_PartialMultiFilterParam;
  dds3Effect_PartialMultiFilter_t_o *v10;
  struct effRippleBlurHandle_t_o *v14;

  v4 = Allocate(dds3Effect_PartialMultiBlur_t);
  dds3Effect_PartialMultiBlur_t___ctor(v4);
  v4->param = Eve_PartialMultiBlurParam;
  hEve_PartialMultiBlur = v4;
  v7 = Allocate(effDistortionBlurHandle_t);
  effDistortionBlurHandle_t___ctor(v7);
  v7->param = Eve_DistortionBlurParam;
  hEve_DistortionBlur = v7;
  v10 = Allocate(dds3Effect_PartialMultiFilter_t);
  dds3Effect_PartialMultiFilter_t___ctor(v10);
  v10->param = Eve_PartialMultiFilterParam;
  hEve_PartialMultiFilter = v10;
  v14 = dds3EffectRippleBlurCreate(Eve_RippleBlurParam);
  hEve_RippleBlur = v14;
  hEve_RippleBlur->param->number = 4;
}

// 0x138e300
s32 Eve_FilterEditorDraw(void) {
  return Eve_FilterEditorRunFlag;
}

// 0x138c910
dds3Effect_Filter_t *Eve_FilterEditorGetParams(void) {
  return Eve_Filter;
}

// 0x138e370
dds3Effect_Filter_t *Eve_FilterEditorGetParams2(void) {
  return effEvent_Edit_Filter;
}

// 0x138c580
void Eve_FilterOFF(void) {
  Eve_FilterShow = 0;
}

// 0x138c510
void Eve_FilterON(void) {
  Eve_FilterShow = 1;
}

// 0x138c5f0
void Eve_FilterSetParam(dds3Effect_Filter_t *pParam) {
  struct sdfIVector2_t_array *xy;
  struct sdfIVector2_t_array *v6;
  struct System_Int32_array *pm;
  struct System_Int32_array *v8;
  s32 v9;
  struct sdfIVector2_t_array *v10;
  struct sdfIVector2_t_array *v12;
  struct System_Int32_array *v13;
  struct System_Int32_array *v15;
  s32 v17;
  struct sdfIVector2_t_array *v19;
  struct sdfIVector2_t_array *v21;
  struct System_Int32_array *v22;
  struct System_Int32_array *v23;
  s32 v24;
  struct sdfIVector2_t_array *v25;
  struct sdfIVector2_t_array *v27;
  struct System_Int32_array *v28;
  struct System_Int32_array *v30;
  s32 v32;

  Eve_Filter->abgr = pParam->abgr;
  Eve_Filter->blend = pParam->blend;
  xy = Eve_Filter->xy;
  v6 = pParam->xy;
  pm = xy->m_Items[0]->pm;
  v8 = v6->m_Items[0]->pm;
  v9 = v8->m_Items[0];
  pm->m_Items[0] = v9;
  v10 = Eve_Filter->xy;
  v12 = pParam->xy;
  v13 = v10->m_Items[0]->pm;
  v15 = v12->m_Items[0]->pm;
  v17 = v15->m_Items[1];
  v13->m_Items[1] = v17;
  v19 = Eve_Filter->xy;
  v21 = pParam->xy;
  v22 = v19->m_Items[1]->pm;
  v23 = v21->m_Items[1]->pm;
  v24 = v23->m_Items[0];
  v22->m_Items[0] = v24;
  v25 = Eve_Filter->xy;
  v27 = pParam->xy;
  v28 = v25->m_Items[1]->pm;
  v30 = v27->m_Items[1]->pm;
  v32 = v30->m_Items[1];
  v28->m_Items[1] = v32;
}

// 0x138e3e0
void Eve_FilterSetParam2(dds3Effect_Filter_t *pParam) {
  struct sdfIVector2_t_array *xy;
  struct sdfIVector2_t_array *v6;
  struct System_Int32_array *pm;
  struct System_Int32_array *v8;
  s32 v9;
  struct sdfIVector2_t_array *v10;
  struct sdfIVector2_t_array *v12;
  struct System_Int32_array *v13;
  struct System_Int32_array *v15;
  s32 v17;
  struct sdfIVector2_t_array *v19;
  struct sdfIVector2_t_array *v21;
  struct System_Int32_array *v22;
  struct System_Int32_array *v23;
  s32 v24;
  struct sdfIVector2_t_array *v25;
  struct sdfIVector2_t_array *v27;
  struct System_Int32_array *v28;
  struct System_Int32_array *v30;
  s32 v32;

  effEvent_Edit_Filter->abgr = pParam->abgr;
  effEvent_Edit_Filter->blend = pParam->blend;
  xy = effEvent_Edit_Filter->xy;
  v6 = pParam->xy;
  pm = xy->m_Items[0]->pm;
  v8 = v6->m_Items[0]->pm;
  v9 = v8->m_Items[0];
  pm->m_Items[0] = v9;
  v10 = effEvent_Edit_Filter->xy;
  v12 = pParam->xy;
  v13 = v10->m_Items[0]->pm;
  v15 = v12->m_Items[0]->pm;
  v17 = v15->m_Items[1];
  v13->m_Items[1] = v17;
  v19 = effEvent_Edit_Filter->xy;
  v21 = pParam->xy;
  v22 = v19->m_Items[1]->pm;
  v23 = v21->m_Items[1]->pm;
  v24 = v23->m_Items[0];
  v22->m_Items[0] = v24;
  v25 = effEvent_Edit_Filter->xy;
  v27 = pParam->xy;
  v28 = v25->m_Items[1]->pm;
  v30 = v27->m_Items[1]->pm;
  v32 = v30->m_Items[1];
  v28->m_Items[1] = v32;
}

// 0x138db20
s32 Eve_PartialMultiBlurEditorDraw(void) {
  return Eve_PartialMultiBlurEditorRunFlag;
}

// 0x138bad0
dds3Effect_PartialMultiBlurParam_t *Eve_PartialMultiBlurEditorGetParams(void) {
  return hEve_PartialMultiBlur->param;
}

// 0x138db90
dds3Effect_PartialMultiBlurParam_t *Eve_PartialMultiBlurEditorGetParams2(void) {
  return effEvent_Edit_PartialMultiBlurParam;
}

// 0x138b570
void Eve_PartialMultiBlurOFF(void) {
  struct effEvent_StaticFields *static_fields;

  else
  {
    static_fields = effEvent->static_fields;
    if (static_fields->Eve_PartialMultiBlurShow != 1)
      return;
  }
  static_fields->Eve_PartialMultiBlurShow = 0;
}

// 0x138b4c0
void Eve_PartialMultiBlurON(void) {
  struct effEvent_StaticFields *static_fields;

  else
  {
    static_fields = effEvent->static_fields;
    if (static_fields->Eve_PartialMultiBlurShow)
      return;
  }
  static_fields->Eve_PartialMultiBlurShow = 1;
}

// 0x138bbb0
void Eve_PartialMultiBlurSetDefTex(void) {
  struct dds3Effect_PartialMultiBlur_t_o *hEve_PartialMultiBlur;

  hEve_PartialMultiBlur->hAlphaTex = dds3BillboardGetGeneralTex(2);
}

// 0x138b640
void Eve_PartialMultiBlurSetParam(dds3Effect_PartialMultiBlurParam_t *pParam) {
  struct System_Int32_array *pm;
  struct System_Int32_array *v5;
  s32 v6;
  struct System_Int32_array *v7;
  struct System_Int32_array *v8;
  s32 v10;
  struct sdfIVector2_t_array *xy;
  struct System_Int32_array *v14;
  struct sdfIVector2_t_array *v15;
  struct System_Int32_array *v16;
  s32 v17;
  struct sdfIVector2_t_array *v18;
  struct System_Int32_array *v20;
  struct sdfIVector2_t_array *v21;
  struct System_Int32_array *v23;
  s32 v25;
  struct sdfIVector2_t_array *v27;
  struct System_Int32_array *v29;
  struct sdfIVector2_t_array *v30;
  struct System_Int32_array *v31;
  s32 v32;
  struct sdfIVector2_t_array *v33;
  struct System_Int32_array *v35;
  struct sdfIVector2_t_array *v36;
  struct System_Int32_array *v38;
  s32 v40;

  hEve_PartialMultiBlur->param->area = pParam->area;
  hEve_PartialMultiBlur->param->Blur->abgr = pParam->Blur->abgr;
  hEve_PartialMultiBlur->param->Blur->blend = pParam->Blur->blend;
  hEve_PartialMultiBlur->param->Blur->rotate = pParam->Blur->rotate;
  hEve_PartialMultiBlur->param->Blur->scale = pParam->Blur->scale;
  pm = hEve_PartialMultiBlur->param->Blur->center->pm;
  v5 = pParam->Blur->center->pm;
  v6 = v5->m_Items[0];
  pm->m_Items[0] = v6;
  v7 = hEve_PartialMultiBlur->param->Blur->center->pm;
  v8 = pParam->Blur->center->pm;
  v10 = v8->m_Items[1];
  v7->m_Items[1] = v10;
  xy = hEve_PartialMultiBlur->param->Blur->xy;
  v14 = xy->m_Items[0]->pm;
  v15 = pParam->Blur->xy;
  v16 = v15->m_Items[0]->pm;
  v17 = v16->m_Items[0];
  v14->m_Items[0] = v17;
  v18 = hEve_PartialMultiBlur->param->Blur->xy;
  v20 = v18->m_Items[0]->pm;
  v21 = pParam->Blur->xy;
  v23 = v21->m_Items[0]->pm;
  v25 = v23->m_Items[1];
  v20->m_Items[1] = v25;
  v27 = hEve_PartialMultiBlur->param->Blur->xy;
  v29 = v27->m_Items[1]->pm;
  v30 = pParam->Blur->xy;
  v31 = v30->m_Items[1]->pm;
  v32 = v31->m_Items[0];
  v29->m_Items[0] = v32;
  v33 = hEve_PartialMultiBlur->param->Blur->xy;
  v35 = v33->m_Items[1]->pm;
  v36 = pParam->Blur->xy;
  v38 = v36->m_Items[1]->pm;
  v40 = v38->m_Items[1];
  v35->m_Items[1] = v40;
}

// 0x138dc00
void Eve_PartialMultiBlurSetParam2(dds3Effect_PartialMultiBlurParam_t *pParam) {
  struct System_Int32_array *pm;
  struct System_Int32_array *v5;
  s32 v6;
  struct System_Int32_array *v7;
  struct System_Int32_array *v8;
  s32 v10;
  struct sdfIVector2_t_array *xy;
  struct System_Int32_array *v14;
  struct sdfIVector2_t_array *v15;
  struct System_Int32_array *v16;
  s32 v17;
  struct sdfIVector2_t_array *v18;
  struct System_Int32_array *v20;
  struct sdfIVector2_t_array *v21;
  struct System_Int32_array *v23;
  s32 v25;
  struct sdfIVector2_t_array *v27;
  struct System_Int32_array *v29;
  struct sdfIVector2_t_array *v30;
  struct System_Int32_array *v31;
  s32 v32;
  struct sdfIVector2_t_array *v33;
  struct System_Int32_array *v35;
  struct sdfIVector2_t_array *v36;
  struct System_Int32_array *v38;
  s32 v40;

  effEvent_Edit_PartialMultiBlurParam->area = pParam->area;
  effEvent_Edit_PartialMultiBlurParam->Blur->abgr = pParam->Blur->abgr;
  effEvent_Edit_PartialMultiBlurParam->Blur->blend = pParam->Blur->blend;
  effEvent_Edit_PartialMultiBlurParam->Blur->rotate = pParam->Blur->rotate;
  effEvent_Edit_PartialMultiBlurParam->Blur->scale = pParam->Blur->scale;
  pm = effEvent_Edit_PartialMultiBlurParam->Blur->center->pm;
  v5 = pParam->Blur->center->pm;
  v6 = v5->m_Items[0];
  pm->m_Items[0] = v6;
  v7 = effEvent_Edit_PartialMultiBlurParam->Blur->center->pm;
  v8 = pParam->Blur->center->pm;
  v10 = v8->m_Items[1];
  v7->m_Items[1] = v10;
  xy = effEvent_Edit_PartialMultiBlurParam->Blur->xy;
  v14 = xy->m_Items[0]->pm;
  v15 = pParam->Blur->xy;
  v16 = v15->m_Items[0]->pm;
  v17 = v16->m_Items[0];
  v14->m_Items[0] = v17;
  v18 = effEvent_Edit_PartialMultiBlurParam->Blur->xy;
  v20 = v18->m_Items[0]->pm;
  v21 = pParam->Blur->xy;
  v23 = v21->m_Items[0]->pm;
  v25 = v23->m_Items[1];
  v20->m_Items[1] = v25;
  v27 = effEvent_Edit_PartialMultiBlurParam->Blur->xy;
  v29 = v27->m_Items[1]->pm;
  v30 = pParam->Blur->xy;
  v31 = v30->m_Items[1]->pm;
  v32 = v31->m_Items[0];
  v29->m_Items[0] = v32;
  v33 = effEvent_Edit_PartialMultiBlurParam->Blur->xy;
  v35 = v33->m_Items[1]->pm;
  v36 = pParam->Blur->xy;
  v38 = v36->m_Items[1]->pm;
  v40 = v38->m_Items[1];
  v35->m_Items[1] = v40;
}

// 0x138bb40
void Eve_PartialMultiBlurSetTex(sdfTexHandle_t *hTex) {
  hEve_PartialMultiBlur->hAlphaTex = hTex;
}

// 0x138e700
s32 Eve_PartialMultiFilterEditorDraw(void) {
  return Eve_PartialMultiFilterEditorRunFlag;
}

// 0x138cfb0
dds3Effect_PartialMultiFilterParam_t *Eve_PartialMultiFilterEditorGetParams(void) {
  return hEve_PartialMultiFilter->param;
}

// 0x138e770
dds3Effect_PartialMultiFilterParam_t *Eve_PartialMultiFilterEditorGetParams2(void) {
  return effEvent_Edit_PartialMultiFilterParam;
}

// 0x138c9f0
void Eve_PartialMultiFilterOFF(void) {
  Eve_PartialMultiFilterShow = 0;
}

// 0x138c980
void Eve_PartialMultiFilterON(void) {
  Eve_PartialMultiFilterShow = 1;
}

// 0x138d090
void Eve_PartialMultiFilterSetDefTex(void) {
  struct dds3Effect_PartialMultiFilter_t_o *hEve_PartialMultiFilter;

  hEve_PartialMultiFilter->hAlphaTex = dds3BillboardGetGeneralTex(0);
}

// 0x138ca60
void Eve_PartialMultiFilterSetParam(dds3Effect_PartialMultiFilterParam_t *pParam) {
  struct System_Int32_array *pm;
  struct System_Int32_array *v5;
  s32 v6;
  struct System_Int32_array *v7;
  struct System_Int32_array *v8;
  s32 v10;
  struct sdfIVector2_t_array *xy;
  u64 *v14;
  struct sdfIVector2_t_array *v16;
  u64 *v17;
  struct sdfIVector2_t_array *v19;
  struct System_Int32_array *v21;
  struct sdfIVector2_t_array *v22;
  struct System_Int32_array *v23;
  s32 v24;
  struct sdfIVector2_t_array *v25;
  struct System_Int32_array *v27;
  struct sdfIVector2_t_array *v28;
  struct System_Int32_array *v30;
  s32 v32;
  struct sdfIVector2_t_array *v34;
  struct System_Int32_array *v36;
  struct sdfIVector2_t_array *v37;
  struct System_Int32_array *v38;
  s32 v39;
  struct sdfIVector2_t_array *v40;
  struct System_Int32_array *v42;
  struct sdfIVector2_t_array *v43;
  struct System_Int32_array *v45;
  s32 v47;

  hEve_PartialMultiFilter->param->area = pParam->area;
  pm = hEve_PartialMultiFilter->param->center->pm;
  v5 = pParam->center->pm;
  v6 = v5->m_Items[0];
  pm->m_Items[0] = v6;
  v7 = hEve_PartialMultiFilter->param->center->pm;
  v8 = pParam->center->pm;
  v10 = v8->m_Items[1];
  v7->m_Items[1] = v10;
  hEve_PartialMultiFilter->param->Filter->abgr = pParam->Filter->abgr;
  hEve_PartialMultiFilter->param->Filter->blend = pParam->Filter->blend;
  xy = hEve_PartialMultiFilter->param->Filter->xy;
  v14 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v14);
  xy->m_Items[0] = v14;
  v16 = hEve_PartialMultiFilter->param->Filter->xy;
  v17 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v17);
  v16->m_Items[1] = v17;
  v19 = hEve_PartialMultiFilter->param->Filter->xy;
  v21 = v19->m_Items[0]->pm;
  v22 = pParam->Filter->xy;
  v23 = v22->m_Items[0]->pm;
  v24 = v23->m_Items[0];
  v21->m_Items[0] = v24;
  v25 = hEve_PartialMultiFilter->param->Filter->xy;
  v27 = v25->m_Items[0]->pm;
  v28 = pParam->Filter->xy;
  v30 = v28->m_Items[0]->pm;
  v32 = v30->m_Items[1];
  v27->m_Items[1] = v32;
  v34 = hEve_PartialMultiFilter->param->Filter->xy;
  v36 = v34->m_Items[1]->pm;
  v37 = pParam->Filter->xy;
  v38 = v37->m_Items[1]->pm;
  v39 = v38->m_Items[0];
  v36->m_Items[0] = v39;
  v40 = hEve_PartialMultiFilter->param->Filter->xy;
  v42 = v40->m_Items[1]->pm;
  v43 = pParam->Filter->xy;
  v45 = v43->m_Items[1]->pm;
  v47 = v45->m_Items[1];
  v42->m_Items[1] = v47;
}

// 0x138e7e0
void Eve_PartialMultiFilterSetParam2(dds3Effect_PartialMultiFilterParam_t *pParam) {
  struct System_Int32_array *pm;
  struct System_Int32_array *v5;
  s32 v6;
  struct System_Int32_array *v7;
  struct System_Int32_array *v8;
  s32 v10;
  struct sdfIVector2_t_array *xy;
  struct System_Int32_array *v15;
  struct sdfIVector2_t_array *v16;
  struct System_Int32_array *v17;
  s32 v18;
  struct sdfIVector2_t_array *v19;
  struct System_Int32_array *v21;
  struct sdfIVector2_t_array *v22;
  struct System_Int32_array *v24;
  s32 v26;
  struct sdfIVector2_t_array *v28;
  struct System_Int32_array *v30;
  struct sdfIVector2_t_array *v31;
  struct System_Int32_array *v32;
  s32 v33;
  struct sdfIVector2_t_array *v34;
  struct System_Int32_array *v36;
  struct sdfIVector2_t_array *v37;
  struct System_Int32_array *v39;
  s32 v41;

  effEvent_Edit_PartialMultiFilterParam->area = pParam->area;
  pm = effEvent_Edit_PartialMultiFilterParam->center->pm;
  v5 = pParam->center->pm;
  v6 = v5->m_Items[0];
  pm->m_Items[0] = v6;
  v7 = effEvent_Edit_PartialMultiFilterParam->center->pm;
  v8 = pParam->center->pm;
  v10 = v8->m_Items[1];
  v7->m_Items[1] = v10;
  effEvent_Edit_PartialMultiFilterParam->Filter->abgr = pParam->Filter->abgr;
  effEvent_Edit_PartialMultiFilterParam->Filter->blend = pParam->Filter->blend;
  xy = effEvent_Edit_PartialMultiFilterParam->Filter->xy;
  v15 = xy->m_Items[0]->pm;
  v16 = pParam->Filter->xy;
  v17 = v16->m_Items[0]->pm;
  v18 = v17->m_Items[0];
  v15->m_Items[0] = v18;
  v19 = effEvent_Edit_PartialMultiFilterParam->Filter->xy;
  v21 = v19->m_Items[0]->pm;
  v22 = pParam->Filter->xy;
  v24 = v22->m_Items[0]->pm;
  v26 = v24->m_Items[1];
  v21->m_Items[1] = v26;
  v28 = effEvent_Edit_PartialMultiFilterParam->Filter->xy;
  v30 = v28->m_Items[1]->pm;
  v31 = pParam->Filter->xy;
  v32 = v31->m_Items[1]->pm;
  v33 = v32->m_Items[0];
  v30->m_Items[0] = v33;
  v34 = effEvent_Edit_PartialMultiFilterParam->Filter->xy;
  v36 = v34->m_Items[1]->pm;
  v37 = pParam->Filter->xy;
  v39 = v37->m_Items[1]->pm;
  v41 = v39->m_Items[1];
  v36->m_Items[1] = v41;
}

// 0x138d020
void Eve_PartialMultiFilterSetTex(sdfTexHandle_t *hTex) {
  hEve_PartialMultiFilter->hAlphaTex = hTex;
}

// 0x138ec00
s32 Eve_RippleBlurEditorDraw(void) {
  return Eve_RippleBlurEditorRunFlag;
}

// 0x138c390
dds3Effect_RippleBlurParam_t *Eve_RippleBlurEditorGetParams(void) {
  return hEve_RippleBlur->param;
}

// 0x138ec70
dds3Effect_RippleBlurParam_t *Eve_RippleBlurEditorGetParams2(void) {
  return effEvent_Edit_RippleBlurParam;
}

// 0x138c100
void Eve_RippleBlurOFF(void) {
  Eve_RippleBlurShow = 0;
  dds3EffectRippleBlurDelete(&hEve_RippleBlur);
}

// 0x138c090
void Eve_RippleBlurON(void) {
  Eve_RippleBlurShow = 1;
}

// 0x138c470
void Eve_RippleBlurSetDefTex(void) {
  struct effRippleBlurHandle_t_o *hEve_RippleBlur;

  hEve_RippleBlur->hAlphaTex = dds3BillboardGetGeneralTex(3);
}

// 0x138c1a0
void Eve_RippleBlurSetParam(dds3Effect_RippleBlurParam_t *pParam) {
  struct System_Int32_array *pm;
  struct System_Int32_array *v5;
  s32 v6;
  struct System_Int32_array *v7;
  struct System_Int32_array *v8;
  s32 v10;

  hEve_RippleBlur->param->number = pParam->number;
  hEve_RippleBlur->param->speed = pParam->speed;
  hEve_RippleBlur->param->interval = pParam->interval;
  hEve_RippleBlur->param->abgr = pParam->abgr;
  hEve_RippleBlur->param->blend = pParam->blend;
  hEve_RippleBlur->param->rotate = pParam->rotate;
  hEve_RippleBlur->param->power = pParam->power;
  hEve_RippleBlur->param->frequency = pParam->frequency;
  pm = hEve_RippleBlur->param->center->pm;
  v5 = pParam->center->pm;
  v6 = v5->m_Items[0];
  pm->m_Items[0] = v6;
  v7 = hEve_RippleBlur->param->center->pm;
  v8 = pParam->center->pm;
  v10 = v8->m_Items[1];
  v7->m_Items[1] = v10;
  hEve_RippleBlur->param->area = pParam->area;
}

// 0x138ece0
void Eve_RippleBlurSetParam2(dds3Effect_RippleBlurParam_t *pParam) {
  struct System_Int32_array *pm;
  struct System_Int32_array *v5;
  s32 v6;
  struct System_Int32_array *v7;
  struct System_Int32_array *v8;
  s32 v10;

  effEvent_Edit_RippleBlurParam->number = pParam->number;
  effEvent_Edit_RippleBlurParam->speed = pParam->speed;
  effEvent_Edit_RippleBlurParam->interval = pParam->interval;
  effEvent_Edit_RippleBlurParam->abgr = pParam->abgr;
  effEvent_Edit_RippleBlurParam->blend = pParam->blend;
  effEvent_Edit_RippleBlurParam->rotate = pParam->rotate;
  effEvent_Edit_RippleBlurParam->power = pParam->power;
  effEvent_Edit_RippleBlurParam->frequency = pParam->frequency;
  pm = effEvent_Edit_RippleBlurParam->center->pm;
  v5 = pParam->center->pm;
  v6 = v5->m_Items[0];
  pm->m_Items[0] = v6;
  v7 = effEvent_Edit_RippleBlurParam->center->pm;
  v8 = pParam->center->pm;
  v10 = v8->m_Items[1];
  v7->m_Items[1] = v10;
  effEvent_Edit_RippleBlurParam->area = pParam->area;
}

// 0x138c400
void Eve_RippleBlurSetTex(sdfTexHandle_t *hTex) {
  hEve_RippleBlur->hAlphaTex = hTex;
}

// 0x138ae50
bool SDF_PADCHECK_TRIG(s32 a) {
  return 0;
}

// 0x1395ed0
effAPPoint4_tag *effAPPoint4Copy(void **hData, s32 bPos, bool tbldata) {
    dds3Bezier4PCreate(0);
    dds3EffectPartCopy(0);
    DDS3EFFECT_RAND_I();
    return 0;
}

// 0x13958e0
effAPPoint4_tag *effAPPoint4Create(effAPPoint4Param_t *pParams, u16 type, void *pData) {
  u64 number;
  effAPPoint4_tag_o *v8;
  struct effAPPoint4Part_tag_array *v9;
  struct effAPPoint4Param_t_o *param;
  struct effAPPoint4Part_tag_array *pPart;
  u64 *v12;
  struct effAPPoint4Part_tag_array *v14;
  effAPPoint4Part_tag_o *v15;
  s64 timing;
  u32 v18;
  u64 v19;
  s64 v20;
  u32 *v22;
  u64 v23;
  u64 *v24;
  struct effAPPoint4Part_tag_array *v27;
  s64 v29;
  u32 v31;
  effPartHandle_t_o *hEffPartSrc;

  hEffPartSrc = 0;
  number = pParams->number;
  v8 = Allocate(effAPPoint4_tag);
  _ctor(v8, 0);
  v8->param = pParams;
  v9 = NewSpecific(effAPPoint4Part_tag, number);
  param = v8->param;
  v8->pPart = v9;
  v8->hMem = 0;
  if (param->timing <= 0)
    param->timing = 1;
  v8->pBezier4P = dds3Bezier4PCreate(number);
  if (number)
  {
    pPart = v8->pPart;
    v12 = Allocate(effAPPoint4Part_tag);
    _ctor(v12, 0);
    pPart->m_Items[0] = v12;
    v14 = v8->pPart;
    v15 = v14->m_Items[0];
    timing = v8->param->timing;
    hEffPartSrc = dds3EffectPartCreate(type, pData, 0, 0);
    v15->hPart = hEffPartSrc;
    v18 = DDS3EFFECT_RAND_I();
    v15->frame = v18 / timing * timing - v18;
    if (number >= 2)
    {
      v19 = 1 - number;
      v20 = 5;
      do
      {
        v22 = v8->pPart;
        v23 = v20 - 4;
        v24 = Allocate(effAPPoint4Part_tag);
        _ctor(v24, 0);
        *&v22[2 * v20] = v24;
        v27 = v8->pPart;
        v29 = *(&v27->obj.klass + v20);
        *(v29 + 24) = dds3EffectPartCopy(&hEffPartSrc, 0, 0);
        v31 = DDS3EFFECT_RAND_I();
        ++v20;
        *(v29 + 16) = v31 / timing * timing - v31;
      }
      while (v19 + v20 != 5);
    }
  }
  return v8;
}

// 0x1395c10
effAPPoint4_tag *effAPPoint4CreatePCF(void **hData, s32 bPos, bool tbldata) {
    dds3EffectPCPData_t__pCopy(0, 0, 0);
    dds3EffectPCPDataGetData(0, 0, 0);
    GetEffPCPAgiFireballPart(0, 0);
    dds3EffectPCPDataGetType(0, 0);
    effAPPoint4Create(0, 0, 0);
    return 0;
}

// 0x13961b0
void effAPPoint4Delete(void **hData) {
    dds3Bezier4PDelete(0);
    dds3EffectPartDelete(0);
}

// 0x1396cf0
void effAPPoint4Draw(void **hData) {
    dds3Bezier4PGetPart(0, 0);
    effAPPoint4PartInit(0, 0);
    dds3Bezier4PRun(0, 0, 0);
    dds3EffectPartSetColor(0, 0);
    dds3EffectPartSetPosition(0, (sdfVector4_t){0});
    dds3EffectPartDraw(0);
    DDS3EFFECT_RAND_I();
}

// 0x1396330
void effAPPoint4PartInit(effAPPoint4_tag **pAPPoint4, u32 index) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__STOREVECTOR(0);
    dds3Bezier4PGetPart(0, 0);
    DDS3EFFECT_RAND_PM();
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__OUTERPRODUCT();
    SDF_VU0__NORMALIZE();
    SDF_VU0__MULVECTOR();
    SDF_VU0__ADDVECTOR_A_C();
    SDF_VU0__ADDVECTOR();
    dds3EffectPartSetColor(0, 0);
}

// 0x1390bf0
void effEVECombParSmokeBTLDraw(effEVECombParSmoke_t *pCombParSmoke) {
  ;
}

// 0x13902a0
effEVECombParSmoke_t *effEVECombParSmokeCreate(effEVECombParSmokeParam_t *pParam) {
  u64 number;
  effEVECombParSmoke_t_o *v4;
  struct effEVECombParSmokePart_t_array *v5;
  s32 *param;
  effEvent_c *v8;
  struct effEvent_StaticFields *static_fields;
  u32 EffEveCPSmokeCount;
  AssetBundleCtrl_o *asset_bc;
  s64 v12;
  u64 i;
  u32 *pPart;
  u64 *v16;
  struct effEVECombParSmokePart_t_array *v18;
  Il2CppClass **v20;

  number = pParam->number;
  v4 = Allocate(effEVECombParSmoke_t);
  effEVECombParSmoke_t___ctor(v4);
  v4->param = effEVECombParSmokeParam_t__Clone(pParam);
  v5 = NewSpecific(effEVECombParSmokePart_t, number);
  param = v4->param;
  v4->pPart = v5;
  v4->Ztest = 0;
  v4->hMem = 0;
  if (param[15] > 0)
  {
    if (param[16] > 0)
    param[16] = 1;
    param = v4->param;
    if (param[10] > 0)
    param[10] = 1;
  }
  param[15] = 1;
  param = v4->param;
  if (param[16] <= 0)
  if (param[10] <= 0)
  static_fields = v8->static_fields;
  EffEveCPSmokeCount = static_fields->EffEveCPSmokeCount;
  static_fields->EffEveCPSmokeCount = EffEveCPSmokeCount + 1;
  if (!EffEveCPSmokeCount)
  {
    asset_bc = get_asset_bc();
    Load(asset_bc, StringLiteral_15508, StringLiteral_15508, 0);
  }
  v12 = v4->param->number;
  if (v12)
  {
    for (i = 0; i != v12; ++i)
    {
      pPart = v4->pPart;
      v16 = Allocate(effEVECombParSmokePart_t);
      effEVECombParSmokePart_t___ctor(v16);
      *&pPart[2 * i + 8] = v16;
      v18 = v4->pPart;
      v20 = &v18->obj.klass + i;
      LODWORD(v20[4]->_1.this_arg.data) = 0;
    }
  }
  return v4;
}

// 0x1395870
effEVECombParSmoke_t *effEVECombParSmokeCreate2(void) {
  return effEVECombParSmokeCreate(EVE_ParSmokeParam);
}

// 0x13904f0
void effEVECombParSmokeDelete(effEVECombParSmoke_t *pCombParSmoke) {
  effEvent_c *v3;
  struct XRD773Unity_CommonMesh_array *pMesh;
  il2cpp_array_size_t max_length;
  s64 v6;
  u64 v7;
  UnityEngine_Object_o *v9;
  struct XRD773Unity_CommonMesh_array *v10;
  UnityEngine_Object_o *gameObject;
  struct XRD773Unity_CommonMesh_array *v14;
  s64 v16;
  struct effEvent_StaticFields *static_fields;
  s32 v18;
  AssetBundleCtrl_o *asset_bc;
  Il2CppObject *hData;

  hData = 0;
  if (EffEveCPSmokeCount)
  {
    if (pCombParSmoke)
    {
      pMesh = pCombParSmoke->pMesh;
      if (pMesh)
      {
        max_length = pMesh->max_length;
        if (max_length >= 1)
        {
          v6 = 4;
          do
          {
            v7 = v6 - 4;
            v9 = *(&pMesh->obj.klass + v6);
            if (op_Inequality(v9, 0, 0))
            {
              v10 = pCombParSmoke->pMesh;
              gameObject = get_gameObject(*(&v10->obj.klass + v6), 0);
              {
              }
              Destroy_27360000(gameObject);
              v14 = pCombParSmoke->pMesh;
              *(&v14->obj.klass + v6) = 0;
            }
            pMesh = pCombParSmoke->pMesh;
            LODWORD(max_length) = pMesh->max_length;
            v16 = v6 - 3;
            ++v6;
          }
          while (v16 < max_length);
        }
        pCombParSmoke->pMesh = 0;
      }
    }
    static_fields = v3->static_fields;
    v18 = static_fields->EffEveCPSmokeCount - 1;
    static_fields->EffEveCPSmokeCount = v18;
    if (!v18)
    {
      hData = hEffEveCPSmokeBill01;
      dds3BillboardDelete(&hData);
      hData = hEffEveCPSmokeBill02;
      dds3BillboardDelete(&hData);
    }
    asset_bc = get_asset_bc();
    UnloadAB(asset_bc, StringLiteral_15508);
    hEffEveCPSmokeBill01Tex = 0;
    hEffEveCPSmokeBill02Tex = 0;
    UnloadUnusedAssets();
  }
}

// 0x1390d60
void effEVECombParSmokeDraw(effEVECombParSmoke_t **pCombParSmoke) {
    IsLoad(0, 0);
    LoadFileObject(0, 0, 0);
    Clear(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__OUTERPRODUCT();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    GetMesh(0, 0, 0);
    effEVECombParSmokePartInit(0, 0);
    sdfSin(0);
    effColorBlend(0, 0, 0);
    sdfCos(0);
    SDF_VU0__ADDVECTOR();
    SDF_VU0__Retdds3ColorItoF(0, 0);
    SetPosition_20241056(0, 0);
    SetIndexTable(0, 0);
    SetColor_20241296(0, 0);
    SetUvTable_20243232(0, 0);
    SetMatTexture(0, 0);
}

// 0x1390c00
void effEVECombParSmokeDrawOff(effEVECombParSmoke_t **pCombParSmoke) {
  struct XRD773Unity_CommonMesh_array *pMesh;
  il2cpp_array_size_t max_length;
  s64 v5;
  u64 v6;
  UnityEngine_Object_o *v8;
  struct XRD773Unity_CommonMesh_array *v9;
  UnityEngine_GameObject_o *gameObject;
  struct XRD773Unity_CommonMesh_array *v12;
  UnityEngine_GameObject_o *v14;
  s64 v15;

  if (*pCombParSmoke)
  {
    pMesh = (*pCombParSmoke)->pMesh;
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
            v9 = (*pCombParSmoke)->pMesh;
            gameObject = get_gameObject(*(&v9->obj.klass + v5), 0);
            if (get_activeSelf(gameObject))
            {
              v12 = (*pCombParSmoke)->pMesh;
              v14 = get_gameObject(*(&v12->obj.klass + v5), 0);
              SetActive(v14, 0, 0);
            }
          }
          pMesh = (*pCombParSmoke)->pMesh;
          LODWORD(max_length) = pMesh->max_length;
          v15 = v5 - 3;
          ++v5;
        }
        while (v15 < max_length);
      }
    }
  }
}

// 0x13957e0
void effEVECombParSmokeGetParams(effEVECombParSmoke_t **pCombParSmoke, effEVECombParSmokeParam_t *pParam) {
  ;
}

// 0x1390790
void effEVECombParSmokePartInit(effEVECombParSmoke_t **pCombParSmoke, u32 index) {
    DDS3EFFECT_RAND_I();
    DDS3EFFECT_RAND_FA(0);
    DDS3EFFECT_RAND_F();
    DDS3EFFECT_RAND_PM();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
}

// 0x13957f0
void effEVECombParSmokeSetParams(effEVECombParSmoke_t **pCombParSmoke, effEVECombParSmokeParam_t *pParam) {
  struct effEVECombParSmokeParam_t_o *param;

  (*pCombParSmoke)->param = pParam;
  param = (*pCombParSmoke)->param;
  if (param->fade_in <= 0)
  {
    param->fade_in = 1;
    param = (*pCombParSmoke)->param;
    if (param->fade_out > 0)
    {
      if (param->timing > 0)
        return;
      param->timing = 1;
      return;
    }
  }
  else  param->fade_out = 1;
  param = (*pCombParSmoke)->param;
  if (param->timing <= 0)
}

// 0x13957b0
void effEVECombParSmokeSetPosition(effEVECombParSmoke_t **pCombParSmoke, sdfVector4_t pPos) {
  SDF_VU0__COPYVECTOR(&(*pCombParSmoke)->param->pos, pPos, 0);
}

// 0x13957d0
void effEVECombParSmokeSetZtest(effEVECombParSmoke_t **pCombParSmoke, u8 test) {
  (*pCombParSmoke)->Ztest = test;
}

// 0x13972f0
void effEveAPP4Randomize(effHandle_t **hEffect) {
    effAPPoint4PartInit(0, 0);
    DDS3EFFECT_RAND_I();
    dds3Bezier4PGetPart(0, 0);
}

// 0x1397020
void effEveAPP4SetPoint(effHandle_t *hEffect, effEveAPP4Point_t **pEveAP4Point) {
}

// 0x138f3d0
effBTL_t *effEveBEDCreate(u8 **pData) {
  return effBTLCreate(pData);
}

// 0x138f4b0
effEveBEDCutHandle_t *effEveBEDCutCreate(effBTL_t *hEveBED, u16 CutNum, effEveBEDParams_t *pParams) {
  effEveBEDCutHandle_t_o *v6;
  effBTL_t_o *hBTLEffect;

  hBTLEffect = hEveBED;
  v6 = Allocate(effEveBEDCutHandle_t);
  effEveBEDCutHandle_t___ctor(v6);
  v6->pParams = pParams;
  v6->hUnit = 0;
  v6->hBTLCutEffect = effBTLCutCreate(&hBTLEffect, CutNum, 0, 0);
  effBTLCutSetScale(&v6->hBTLCutEffect, pParams->scale);
  return v6;
}

// 0x138f580
void effEveBEDCutDelete(effEveBEDCutHandle_t *hEveBEDCut) {
  effBTLCutHandle_t_o **p_hBTLCutEffect;

  p_hBTLCutEffect = &hEveBEDCut->hBTLCutEffect;
  effBTLCutDelete(p_hBTLCutEffect);
}

// 0x138f6d0
void effEveBEDCutDraw(effEveBEDCutHandle_t **hEveBEDCut) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    Mult();
    ToMatrix();
    SDF_VU0__STOREMATRIX(0);
    sdfModelGetMarkPosUnity(0, 0);
    SDF_VU0__STOREVECTOR(0);
    dds3EffectPartSetPosition(0, (sdfVector4_t){0});
    sdfModelGetMarkPosMatrixUnity(0, 0);
    SDF_VU0__LOADMATRIX_B(0);
    MultMatrixNoArg();
    effEveBEDPartGetPositionPtr(0, 0);
    dds3EffectPartSetRotateMatrix(0, 0);
    dds3EffectPartSetColor(0, 0);
    dds3EffectPartDraw(0);
}

// 0x138f630
void effEveBEDCutGetParams(effEveBEDCutHandle_t *hEveBEDCut, effEveBEDParams_t *pParams) {
  ;
}

// 0x138f620
void effEveBEDCutSetParams(effEveBEDCutHandle_t **hEveBEDCut, effEveBEDParams_t *pParams) {
  (*hEveBEDCut)->pParams = pParams;
}

// 0x138f640
void effEveBEDCutSetScale(effEveBEDCutHandle_t **hEveBEDCut, f32 scale) {
  effBTLCutHandle_t_o **p_hBTLCutEffect;

  p_hBTLCutEffect = &(*hEveBEDCut)->hBTLCutEffect;
  effBTLCutSetScale(p_hBTLCutEffect, scale);
}

// 0x138f6c0
void effEveBEDCutSetUnitHandle(effEveBEDCutHandle_t **hEveBEDCut, evtUnitHandle_t *hUnit) {
  (*hEveBEDCut)->hUnit = hUnit;
}

// 0x138f440
void effEveBEDDelete(effBTL_t *hEveBED) {
  effBTL_t_o *hBTLEffect;

  hBTLEffect = hEveBED;
  effBTLDelete(&hBTLEffect);
}

// 0x138eea0
void effEveBEDPartGetPositionPtr(effEveBEDParams_t *pParams, effBTL_SkillPositionPtr_t *pPosPtr) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    LookAtMatrix((sdfVector4_t){0}, (sdfVector4_t){0}, (sdfVector4_t){0});
    ReverseMatrix();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__VECTOR_W_SET_ZERO();
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    ToMatrix();
    SetRotateMatrixY_B(0);
    MultMatrixNoArg();
    SDF_VU0__STOREVECTOR(0);
}

// 0x138ffc0
effSimpleBED_t *effSimpleBEDCopy(effSimpleBED_t *hSimpleBEDSrc) {
  effSimpleBED_t_o *v3;
  effBTL_t_o *hBED;
  effEveBEDParams_t_o *pParams;

  v3 = Allocate(effSimpleBED_t);
  effSimpleBED_t___ctor(v3);
  hBED = hSimpleBEDSrc->hBED;
  pParams = hSimpleBEDSrc->pParams;
  v3->hCut = effEveBEDCutCreate(hBED, 0, pParams);
  v3->hBED = hSimpleBEDSrc->hBED;
  v3->pParams = hSimpleBEDSrc->pParams;
  v3->original = 0;
  return v3;
}

// 0x138fc20
effSimpleBED_t *effSimpleBEDCreate(u8 **pData, f32 scale) {
    effBTLCreate(0);
    effEveBEDCutCreate(0, 0, 0);
    return 0;
}

// 0x138fe30
void effSimpleBEDDelete(effSimpleBED_t *hSimpleBED) {
    effBTLCutDelete(0);
    effBTLDelete(0);
}

// 0x1390080
void effSimpleBEDDraw(effSimpleBED_t *hSimpleBED) {
    effEveBEDCutDraw(0);
}

// 0x1390100
void effSimpleBEDSetPosition(effSimpleBED_t *hSimpleBED, sdfVector4_t pPos) {
}

// 0x1390220
void effSimpleBEDSetRGBA(effSimpleBED_t *hSimpleBED, u32 abgr) {
  struct effEveBEDParams_t_o *pParams;

  hSimpleBED->pParams->abgr = abgr;
  pParams = hSimpleBED->pParams;
  hSimpleBED->hCut->pParams = pParams;
}

// 0x138ae60
void *sdfChipAlloc(void *aSize) {
    return 0;
}

// 0x138aec0
void sdfChipFree(void *aPtr) {
  ;
}

// 0x138aed0
void sdfDrawTagLink(sdfDrawTag_t *aTag, void *aPacket) {
  ;
}

// 0x138aee0
void sdfSetPacketHeader(sdfGrPacketHeader_t *aHdr, s32 aSize) {
  ;
}
