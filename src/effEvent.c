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
static effViewer_Menu_Item_t *effEvent_Edit_MenuItem;
static dds3Effect_Blur_t *pEffEvent_Edit_Blur;
static effViewer_Menu_t *effEvent_Edit_Blur_Menu;
static s32 Eve_BlurEditorRunFlag;
static dds3Effect_PartialMultiBlur_t *hEffEvent_Edit_PartialMultiBlur;
static dds3Effect_PartialMultiBlurParam_t *effEvent_Edit_PartialMultiBlurParam_Def;
static dds3Effect_PartialMultiBlurParam_t *effEvent_Edit_PartialMultiBlurParam;
static effViewer_Menu_Item_t *effEvent_Edit_PartialMultiBlur_MenuItem;
static effViewer_Menu_t *effEvent_Edit_PartialMultiBlur_Menu;
static s32 Eve_PartialMultiBlurEditorRunFlag;
static effDistortionBlurHandle_t *hEffEvent_Edit_DistortionBlur;
static dds3Effect_DistortionBlurParam_t *effEvent_Edit_DistortionBlurParam_Def;
static dds3Effect_DistortionBlurParam_t *effEvent_Edit_DistortionBlurParam;
static effViewer_Menu_Item_t *effEvent_Edit_DistortionBlur_MenuItem;
static effViewer_Menu_t *effEvent_Edit_DistortionBlur_Menu;
static s32 Eve_DistortionBlurEditorRunFlag;
static dds3Effect_Filter_t *effEvent_Edit_Filter_Def;
static dds3Effect_Filter_t *effEvent_Edit_Filter;
static effViewer_Menu_Item_t *effEvent_Edit_Filter_MenuItem;
static dds3Effect_Filter_t *pEffEvent_Edit_Filter;
static effViewer_Menu_t *effEvent_Edit_Filter_Menu;
static s32 Eve_FilterEditorRunFlag;
static dds3Effect_PartialMultiFilter_t *hEffEvent_Edit_PartialMultiFilter;
static dds3Effect_PartialMultiFilterParam_t *effEvent_Edit_PartialMultiFilterParam_Def;
static dds3Effect_PartialMultiFilterParam_t *effEvent_Edit_PartialMultiFilterParam;
static effViewer_Menu_Item_t *effEvent_Edit_PartialMultiFilter_MenuItem;
static effViewer_Menu_t *effEvent_Edit_PartialMultiFilter_Menu;
static s32 Eve_PartialMultiFilterEditorRunFlag;
static effRippleBlurHandle_t *hEffEvent_Edit_RippleBlur;
static dds3Effect_RippleBlurParam_t *effEvent_Edit_RippleBlurParam_Def;
static dds3Effect_RippleBlurParam_t *effEvent_Edit_RippleBlurParam;
static effViewer_Menu_Item_t *effEvent_Edit_RippleBlur_MenuItem;
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
  else
  {
    if (Eve_BlurShow != 1)
      return;
  }
  Eve_BlurShow = 0;
}

// 0x138aef0
void Eve_BlurON(void) {
  else
  {
    if (Eve_BlurShow)
      return;
  }
  Eve_BlurShow = 1;
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

LABEL_10:
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
  else
  {
    if (Eve_PartialMultiBlurShow != 1)
      return;
  }
  Eve_PartialMultiBlurShow = 0;
}

// 0x138b4c0
void Eve_PartialMultiBlurON(void) {
  else
  {
    if (Eve_PartialMultiBlurShow)
      return;
  }
  Eve_PartialMultiBlurShow = 1;
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
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 namespaze_high;
  effAPPoint4_tag_o *v11;
  struct effAPPoint4Part_tag_array *v12;
  struct effAPPoint4Param_t_o *param;
  s64 timing;
  s64 v15;
  s64 v16;
  u32 *pPart;
  u64 v19;
  u64 *v20;
  struct effAPPoint4Part_tag_array *v23;
  u64 *monitor;
  s64 v26;
  u32 v29;
  effPartHandle_t_o *v31;
  u64 v32[3];

  v31 = 0;
  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effAPPoint4_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effAPPoint4_tag, v32);
      if ((v32[0] & 1) != 0)
        v8 = v32[2];
      else
        v8 = v32 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  namespaze_high = HIDWORD(v5[1].klass->_1.namespaze);
  v11 = Allocate(effAPPoint4_tag);
  _ctor(v11, 0);
  v11->param = v5[1].klass;
  v12 = NewSpecific(effAPPoint4Part_tag, namespaze_high);
  param = v11->param;
  v11->pPart = v12;
  v11->hMem = 0;
  if (param->timing <= 0)
    param->timing = 1;
  v11->pBezier4P = dds3Bezier4PCreate(namespaze_high);
  if (namespaze_high)
  {
    timing = v11->param->timing;
    v15 = -namespaze_high;
    v16 = 4;
    do
    {
      pPart = v11->pPart;
      v19 = v16 - 4;
      v20 = Allocate(effAPPoint4Part_tag);
      _ctor(v20, 0);
      *&pPart[2 * v16] = v20;
      v23 = v11->pPart;
      monitor = v5[1].monitor;
      v26 = *(&v23->obj.klass + v16);
      v31 = *(monitor[v16] + 24LL);
      *(v26 + 24) = dds3EffectPartCopy(&v31, 0, 0);
      v29 = DDS3EFFECT_RAND_I();
      ++v16;
      *(v26 + 16) = v29 / timing * timing - v29;
    }
    while (v15 + v16 != 4);
  }
  return v11;
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
  u64 *v6;
  Il2CppObject *v7;
  Il2CppClass *v8;
  s64 *Interface;
  System_Byte_array *v10;
  dds3EffectPCPData_t_o *v11;
  char *v12;
  s64 *v13;
  Il2CppObject *Data;
  struct dds3EffectPCPData_Part_t_array *pcpData;
  Il2CppObject *v18;
  effAPPoint4Param_t_o *v19;
  u32 offset;
  Il2CppObject *EffPCPAgiFireballPart;
  u16 Type;
  effAPPoint4Param_t_c *klass;
  s64 typeHierarchyDepth;
  char *v28;
  s64 *v29;
  dds3EffectPCPData_t_o *v31;
  u64 v32[2];
  char *v33;
  s32 pos;

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v31 = v6;
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v7->klass->_1.element_class, v8, v32);
      if ((v32[0] & 1) != 0)
        v12 = v33;
      else
        v12 = v32 + 1;
      v13 = sub_8C4940(v12);
    }
    v10 = Interface;
    v11 = v6;
  }
  else
  {
    v10 = 0;
    v11 = v6;
  }
  dds3EffectPCPData_t__pCopy(v11, v10, &pos);
  Data = dds3EffectPCPDataGetData(v6, 0, 0);
  pcpData = v11->pcpData;
  v18 = *hData;
  v19 = Data;
  offset = pcpData->m_Items[1]->offset;
  EffPCPAgiFireballPart = GetEffPCPAgiFireballPart(v18, offset + bPos);
  Type = dds3EffectPCPDataGetType(&v31, 1u);
  else if (!v19)
  {
    return effAPPoint4Create(v19, Type, EffPCPAgiFireballPart);
  }
  klass = v19->klass;
  if (v19->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effAPPoint4Param_t)
  {
    sub_8FC2C0(klass->_1.element_class, effAPPoint4Param_t, v32);
    if ((v32[0] & 1) != 0)
      v28 = v33;
    else
      v28 = v32 + 1;
    v29 = sub_8C4940(v28);
  }
  return effAPPoint4Create(v19, Type, EffPCPAgiFireballPart);
}

// 0x13961b0
void effAPPoint4Delete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s64 namespaze_high;
  u64 i;
  u64 *monitor;
  effPartHandle_t_o **v13;
  u64 v14[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effAPPoint4_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effAPPoint4_tag, v14);
      if ((v14[0] & 1) != 0)
        v6 = v14[2];
      else
        v6 = v14 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  dds3Bezier4PDelete(v3[2].klass);
  namespaze_high = HIDWORD(v3[1].klass->_1.namespaze);
  if (namespaze_high)
  {
    for (i = 0; i != namespaze_high; ++i)
    {
      monitor = v3[1].monitor;
      v13 = (monitor[i + 4] + 24LL);
      dds3EffectPartDelete(v13);
    }
  }
}

// 0x1396cf0
void effAPPoint4Draw(void **hData) {
  effAPPoint4_tag_o *v3;
  effAPPoint4_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  struct effAPPoint4Param_t_o *param;
  s32 loop;
  s64 number;
  s32 life;
  s32 timing;
  u64 i;
  struct effAPPoint4Part_tag_array *pPart;
  effAPPoint4Part_tag_o *v16;
  s32 frame;
  f32 v22;
  u32 v23;
  f32 v24;
  s32 v25;
  u32 v26;
  s32 fade_out;
  s32 fade_in;
  UnityEngine_Vector4_o pOut;
  effBezier4P_t_o *pEffBezier4P;
  effAPPoint4_tag_o *pAPPoint4;
  u64 v32[3];

  pEffBezier4P = 0;
  pAPPoint4 = 0;
  *&pOut.x = 0;
  *&pOut.z = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effAPPoint4_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effAPPoint4_tag, v32);
      if ((v32[0] & 1) != 0)
        v6 = v32[2];
      else
        v6 = v32 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  *&pOut.x = 0;
  *&pOut.z = 0;
  param = v3->param;
  loop = param->loop;
  number = param->number;
  life = param->life;
  fade_out = param->fade_out;
  fade_in = param->fade_in;
  timing = param->timing;
  pEffBezier4P = v3->pBezier4P;
  pAPPoint4 = v3;
  dds3Bezier4PGetPart(&pEffBezier4P, 0);
  if (number)
  {
    for (i = 0; number != i; ++i)
    {
      while (1)
      {
        pPart = v3->pPart;
        v16 = pPart->m_Items[i];
        dds3Bezier4PGetPart(&pEffBezier4P, i);
        frame = v16->frame;
        if (frame)
          break;
        effAPPoint4PartInit(&pAPPoint4, i);
LABEL_25:
        if (loop)
          goto LABEL_26;
LABEL_40:
        ++i;
        ++v16->frame;
        if (number == i)
          return;
      }
      if (frame < 1 || life < frame)
        goto LABEL_25;
      dds3Bezier4PRun(&pEffBezier4P, i, &pOut);
      if (frame >= fade_in)
      {
        v22 = 1.0;
        if (life - frame <= fade_out)
          v22 = (life - frame) / fade_out;
      }
      else
      {
        v22 = frame / fade_in;
      }
      v24 = v22 * 127.0;
      v25 = v24;
      if (v24 >= 0.0)
        LOBYTE(v25) = v24;
      v26 = (v25 << 24) | 0x808080;
      dds3EffectPartSetColor(&v16->hPart, v26);
      dds3EffectPartSetPosition(&v16->hPart, pOut);
      dds3EffectPartDraw(&v16->hPart);
      if (!loop)
        goto LABEL_40;
LABEL_26:
      if (life > frame)
        goto LABEL_40;
      v23 = DDS3EFFECT_RAND_I();
      v16->frame = v23 / timing * timing - v23;
    }
  }
}

// 0x1396330
void effAPPoint4PartInit(effAPPoint4_tag **pAPPoint4, u32 index) {
  struct effAPPoint4Part_tag_array *pPart;
  effAPPoint4Part_tag_o *v7;
  f32 v9;
  effBezier4PPart_t_o *v10;
  effBezier4PPart_t_o *v12;
  struct UnityEngine_Vector4_array *point;
  struct UnityEngine_Vector4_array *v16;
  struct UnityEngine_Vector3_array *v18;
  f32 v19;
  struct UnityEngine_Vector3_array *v21;
  f32 v22;
  struct UnityEngine_Vector3_array *v24;
  f32 v25;
  struct UnityEngine_Vector4_array *v28;
  struct UnityEngine_Vector4_array *v30;
  struct UnityEngine_Vector3_array *v32;
  f32 v33;
  struct UnityEngine_Vector3_array *v35;
  f32 v36;
  struct UnityEngine_Vector3_array *v38;
  f32 v39;
  struct UnityEngine_Vector4_array *v42;
  struct UnityEngine_Vector4_array *v44;
  struct UnityEngine_Vector3_array *v46;
  f32 v47;
  struct UnityEngine_Vector3_array *v49;
  f32 v50;
  struct UnityEngine_Vector3_array *v52;
  f32 v53;
  struct UnityEngine_Vector4_array *v56;
  struct UnityEngine_Vector3_array *v58;
  f32 v59;
  struct UnityEngine_Vector3_array *v61;
  f32 v62;
  struct UnityEngine_Vector3_array *v64;
  f32 v65;
  UnityEngine_Vector4_o v68;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v70;
  UnityEngine_Vector4_o v71;

  *&v71.x = 0;
  *&v71.z = 0;
  *&v70.x = 0;
  *&v70.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v68.x = 0;
  *&v68.z = 0;
  pPart = (*pAPPoint4)->pPart;
  v7 = pPart->m_Items[index];
  SDF_VU0__LOADVECTOR(dds3CameraEyePos);
  SDF_VU0__LOADVECTOR_B(dds3CameraTargetPos);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__STOREVECTOR(&p);
  v9 = 1.0 / (*pAPPoint4)->param->life;
  v10 = dds3Bezier4PGetPart(&(*pAPPoint4)->pBezier4P, index, 0);
  v10->weight = 0.0;
  v10->step = v9;
  v12 = v10;
  DDS3EFFECT_RAND_PM();
  sub_854930(&v71, 0);
  sub_854710(&v71, 0);
  sub_854930(&v71, 1u);
  sub_854930(&v71, 2u);
  point = (*pAPPoint4)->param->point;
  SDF_VU0__LOADVECTOR(point->m_Items[0]);
  v16 = (*pAPPoint4)->param->point;
  SDF_VU0__LOADVECTOR_B(v16->m_Items[1]);
  SDF_VU0__COPYVECTOR_A_TO_C();
  SDF_VU0__SUBVECTOR();
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__NORMALIZE();
  SDF_VU0__LOADVECTOR_B(v71);
  SDF_VU0__MULVECTOR();
  SDF_VU0__ADDVECTOR_A_C();
  SDF_VU0__STOREVECTOR(&v68);
  v18 = v12->point;
  sub_854710(&v68, 0);
  sub_8529B0(v18->m_Items, 0, v19);
  v21 = v12->point;
  sub_854710(&v68, 1u);
  sub_8529B0(v21->m_Items, 1, v22);
  v24 = v12->point;
  sub_854710(&v68, 2u);
  sub_8529B0(v24->m_Items, 2, v25);
  DDS3EFFECT_RAND_PM();
  sub_854930(&v71, 0);
  sub_854710(&v71, 0);
  sub_854930(&v71, 1u);
  sub_854930(&v71, 2u);
  v28 = (*pAPPoint4)->param->point;
  SDF_VU0__LOADVECTOR(v28->m_Items[1]);
  v30 = (*pAPPoint4)->param->point;
  SDF_VU0__LOADVECTOR_B(v30->m_Items[2]);
  SDF_VU0__COPYVECTOR_A_TO_C();
  SDF_VU0__SUBVECTOR();
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__NORMALIZE();
  SDF_VU0__LOADVECTOR_B(v71);
  SDF_VU0__MULVECTOR();
  SDF_VU0__ADDVECTOR_A_C();
  SDF_VU0__STOREVECTOR(&v68);
  v32 = v12->point;
  sub_854710(&v68, 0);
  sub_8529B0(&v32->m_Items[1], 0, v33);
  v35 = v12->point;
  sub_854710(&v68, 1u);
  sub_8529B0(&v35->m_Items[1], 1, v36);
  v38 = v12->point;
  sub_854710(&v68, 2u);
  sub_8529B0(&v38->m_Items[1], 2, v39);
  DDS3EFFECT_RAND_PM();
  sub_854930(&v71, 0);
  sub_854710(&v71, 0);
  sub_854930(&v71, 1u);
  sub_854930(&v71, 2u);
  v42 = (*pAPPoint4)->param->point;
  SDF_VU0__LOADVECTOR(v42->m_Items[2]);
  v44 = (*pAPPoint4)->param->point;
  SDF_VU0__LOADVECTOR_B(v44->m_Items[3]);
  SDF_VU0__COPYVECTOR_A_TO_C();
  SDF_VU0__SUBVECTOR();
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v70);
  SDF_VU0__LOADVECTOR_B(v71);
  SDF_VU0__MULVECTOR();
  SDF_VU0__ADDVECTOR_A_C();
  SDF_VU0__STOREVECTOR(&v68);
  v46 = v12->point;
  sub_854710(&v68, 0);
  sub_8529B0(&v46->m_Items[2], 0, v47);
  v49 = v12->point;
  sub_854710(&v68, 1u);
  sub_8529B0(&v49->m_Items[2], 1, v50);
  v52 = v12->point;
  sub_854710(&v68, 2u);
  sub_8529B0(&v52->m_Items[2], 2, v53);
  DDS3EFFECT_RAND_PM();
  sub_854930(&v71, 0);
  sub_854710(&v71, 0);
  sub_854930(&v71, 1u);
  sub_854930(&v71, 2u);
  SDF_VU0__LOADVECTOR(v70);
  SDF_VU0__LOADVECTOR_B(v71);
  SDF_VU0__MULVECTOR();
  v56 = (*pAPPoint4)->param->point;
  SDF_VU0__LOADVECTOR_B(v56->m_Items[3]);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&v68);
  v58 = v12->point;
  sub_854710(&v68, 0);
  sub_8529B0(&v58->m_Items[3], 0, v59);
  v61 = v12->point;
  sub_854710(&v68, 1u);
  sub_8529B0(&v61->m_Items[3], 1, v62);
  v64 = v12->point;
  sub_854710(&v68, 2u);
  sub_8529B0(&v64->m_Items[3], 2, v65);
  dds3EffectPartSetColor(&v7->hPart, 0);
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
      goto LABEL_5;
LABEL_26:
    param[16] = 1;
    param = v4->param;
    if (param[10] > 0)
      goto LABEL_6;
LABEL_27:
    param[10] = 1;
    goto LABEL_6;
  }
  param[15] = 1;
  param = v4->param;
  if (param[16] <= 0)
    goto LABEL_26;
LABEL_5:
  if (param[10] <= 0)
    goto LABEL_27;
LABEL_6:
  EffEveCPSmokeCount = EffEveCPSmokeCount + 1;
  if (!EffEveCPSmokeCount)
  {
    asset_bc = get_asset_bc();
    Load(asset_bc, "efftool", "efftool", 0);
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
  struct XRD773Unity_CommonMesh_array *pMesh;
  il2cpp_array_size_t max_length;
  s64 v6;
  u64 v7;
  UnityEngine_Object_o *v9;
  struct XRD773Unity_CommonMesh_array *v10;
  UnityEngine_Object_o *gameObject;
  struct XRD773Unity_CommonMesh_array *v14;
  s64 v16;
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
    v18 = EffEveCPSmokeCount - 1;
    EffEveCPSmokeCount = v18;
    if (!v18)
    {
      hData = hEffEveCPSmokeBill01;
      dds3BillboardDelete(&hData);
      hData = hEffEveCPSmokeBill02;
      dds3BillboardDelete(&hData);
    }
    asset_bc = get_asset_bc();
    UnloadAB(asset_bc, "efftool");
    hEffEveCPSmokeBill01Tex = 0;
    hEffEveCPSmokeBill02Tex = 0;
    UnloadUnusedAssets();
  }
}

// 0x1390d60
void effEVECombParSmokeDraw(effEVECombParSmoke_t **pCombParSmoke) {
  UnityEngine_Object_o *hEffEveCPSmokeBill01Tex;
  AssetBundleCtrl_o *asset_bc;
  AssetBundleCtrl_o *v8;
  Il2CppObject *FileObject;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v14;
  s64 *v15;
  AssetBundleCtrl_o *v16;
  Il2CppObject *v17;
  Il2CppClass *v18;
  s64 v19;
  char *v20;
  s64 *v21;
  u64 *v22;
  u64 *v24;
  u64 *v26;
  u64 *v27;
  struct effEVECombParSmokeParam_t_o *param;
  s32 loop;
  s64 number;
  f32 accele;
  effEVECombParSmoke_t_o *v34;
  struct XRD773Unity_CommonMesh_array *pMesh;
  XRD773Unity_GraphicManager_o *Instance;
  s64 *Mesh;
  s64 *v39;
  struct XRD773Unity_CommonMesh_array *v42;
  UnityEngine_Object_o *gameObject;
  System_String_o *name;
  System_String_o *v46;
  struct XRD773Unity_CommonMesh_array *v47;
  XRD773Unity_GraphicManager_o *v48;
  s64 *v49;
  s64 *v50;
  struct XRD773Unity_CommonMesh_array *v53;
  UnityEngine_Object_o *v55;
  System_String_o *v56;
  System_String_o *v57;
  u64 *v58;
  u64 *v59;
  u64 v60;
  s64 *v61;
  s64 *v62;
  s64 *v64;
  s64 *v65;
  u64 v68;
  s64 *v69;
  s64 *v70;
  s64 *v72;
  s64 *v73;
  u32 *v75;
  s64 *v77;
  s64 *v78;
  s64 *v80;
  s64 *v81;
  s64 *v83;
  s64 *v84;
  u64 *v86;
  s64 *v88;
  s64 *v91;
  s32 v93;
  s64 v94;
  effEVECombParSmoke_t_o *v96;
  f32 v97;
  u64 v98;
  struct XRD773Unity_CommonMesh_array *v101;
  UnityEngine_GameObject_o *v103;
  struct XRD773Unity_CommonMesh_array *v150;
  UnityEngine_GameObject_o *v152;
  struct effEVECombParSmokePart_t_array *pPart;
  effEVECombParSmokePart_t_o *v186;
  s32 frame;
  s32 wait;
  f32 angle;
  f32 amplitude;
  f32 v193;
  f32 v194;
  u64 v196;
  s32 v197;
  f32 v198;
  f32 v199;
  f32 v200;
  u32 v201;
  u32 v202;
  f32 v203;
  u32 v204;
  f32 s_w_r;
  u64 v207;
  s64 v208;
  u64 v210;
  u64 v212;
  s64 v214;
  s64 v215;
  u64 v216;
  s64 v217;
  s64 v218;
  u64 v220;
  s64 v222;
  s64 v224;
  u64 v226;
  s64 v228;
  s64 v230;
  u64 v232;
  s64 v234;
  s64 v236;
  u64 v238;
  s64 v240;
  s64 v242;
  u64 v244;
  s64 v246;
  s64 v248;
  u64 v250;
  s64 v252;
  s64 v254;
  f32 v256;
  f32 v257;
  u64 v258;
  s64 v260;
  f32 v262;
  f32 v263;
  s64 v264;
  u64 v266;
  s64 v268;
  s64 v270;
  u64 v272;
  s64 v274;
  f32 v276;
  s64 v277;
  u64 v279;
  s64 v281;
  f32 v283;
  s64 v284;
  u64 v286;
  s64 v288;
  s64 v290;
  u64 v292;
  s64 v294;
  s64 v296;
  u64 v298;
  s64 v300;
  s64 v302;
  f32 v303;
  u64 v305;
  s64 v307;
  s64 v309;
  struct XRD773Unity_CommonMesh_array *v311;
  UnityEngine_GameObject_o *v313;
  s64 v314;
  u64 v315;
  s64 v316;
  s64 v317;
  s64 v318;
  f32 v319;
  u64 v320;
  s64 v321;
  s64 v322;
  f32 v324;
  s32 v325;
  s32 v326;
  u32 *v328;
  s64 v329;
  u64 v330;
  s64 v331;
  s64 v333;
  s64 v335;
  f32 v337;
  u64 v338;
  s64 v340;
  s64 v342;
  f32 v344;
  s32 v345;
  s32 v346;
  u32 *v348;
  s64 v349;
  u64 v350;
  s64 v351;
  s64 v353;
  s64 v355;
  f32 v357;
  u64 v358;
  s64 v360;
  s64 v362;
  f32 v364;
  s32 v365;
  s32 v366;
  u32 *v368;
  s64 v369;
  u64 v370;
  s64 v371;
  s64 v373;
  s64 v375;
  f32 v377;
  u64 v378;
  s64 v380;
  s64 v382;
  f32 v384;
  u32 v385;
  s32 v386;
  s32 v387;
  u32 *v389;
  s64 v390;
  u64 v391;
  s64 v392;
  s64 v393;
  s64 v394;
  u64 v395;
  u32 v396;
  s64 v397;
  s64 v398;
  u32 v400;
  s32 v401;
  s64 v402;
  s64 v403;
  u64 v404;
  s64 v405;
  s64 v407;
  s64 v409;
  u64 v411;
  u32 v412;
  s64 v414;
  s64 v416;
  u32 v418;
  s32 v419;
  s64 v420;
  s64 v421;
  u64 v422;
  s64 v423;
  s64 v425;
  s64 v427;
  u64 v429;
  u32 v430;
  s64 v432;
  s64 v434;
  u32 v436;
  s32 v437;
  s64 v438;
  s64 v439;
  u64 v440;
  s64 v441;
  s64 v443;
  s64 v445;
  u64 v447;
  u32 v448;
  s64 v450;
  s64 v452;
  s64 v454;
  bool v455;
  s32 v456;
  s64 v458;
  u64 v459;
  s64 v461;
  s64 v462;
  s32 v463;
  s32 v464;
  s32 v465;
  u32 *v467;
  s64 v468;
  s64 v469;
  s32 v470;
  s32 v471;
  s32 v472;
  s64 v473;
  u32 *v475;
  s64 v476;
  s64 v477;
  s32 v478;
  s32 v479;
  s32 v480;
  s64 v481;
  u32 *v483;
  s64 v484;
  s64 v485;
  s32 v486;
  s32 v487;
  s32 v488;
  s64 v489;
  u32 *v491;
  s64 v493;
  s64 v494;
  s64 v495;
  s64 v496;
  s64 v497;
  s64 v498;
  s64 v499;
  s64 v500;
  s64 v501;
  s64 v502;
  s64 v503;
  s64 v504;
  u64 v508;
  s64 v509;
  u64 v512;
  u64 v514;
  s64 v515;
  s64 v516;
  u64 v517;
  s64 v518;
  s64 v519;
  u64 v521;
  s64 v523;
  s64 v525;
  u64 v527;
  s64 v529;
  s64 v531;
  u64 v533;
  s64 v535;
  s64 v537;
  u64 v539;
  s64 v541;
  s64 v543;
  u64 v545;
  s64 v547;
  s64 v549;
  u64 v551;
  s64 v553;
  s64 v555;
  f32 roll;
  f32 v558;
  f32 v559;
  u64 v560;
  s64 v562;
  f32 v564;
  f32 v565;
  s64 v566;
  u64 v568;
  s64 v570;
  s64 v572;
  u64 v574;
  s64 v576;
  f32 v578;
  s64 v579;
  u64 v581;
  s64 v583;
  f32 v585;
  s64 v586;
  u64 v588;
  s64 v590;
  s64 v592;
  u64 v594;
  s64 v596;
  s64 v598;
  u64 v600;
  s64 v602;
  s64 v604;
  f32 v605;
  u64 v607;
  s64 v609;
  s64 v611;
  struct XRD773Unity_CommonMesh_array *v613;
  UnityEngine_GameObject_o *v615;
  s64 v616;
  u64 v618;
  s64 v619;
  s64 v620;
  s64 v621;
  f32 v622;
  u64 v623;
  s64 v624;
  s64 v625;
  f32 v627;
  s32 v628;
  s32 v629;
  u32 *v631;
  s64 v633;
  u64 v635;
  s64 v636;
  s64 v638;
  s64 v640;
  f32 v642;
  u64 v643;
  s64 v645;
  s64 v647;
  f32 v649;
  s32 v650;
  s32 v651;
  u32 *v653;
  s64 v655;
  u64 v657;
  s64 v658;
  s64 v660;
  s64 v662;
  f32 v664;
  u64 v665;
  s64 v667;
  s64 v669;
  f32 v671;
  s32 v672;
  s32 v673;
  u32 *v675;
  s64 v677;
  u64 v679;
  s64 v680;
  s64 v682;
  s64 v684;
  f32 v686;
  u64 v687;
  s64 v689;
  s64 v691;
  f32 v693;
  u32 v694;
  s32 v695;
  s32 v696;
  u32 *v698;
  s64 v700;
  u64 v702;
  s64 v703;
  s64 v704;
  s64 v705;
  u64 v706;
  u32 v707;
  s64 v708;
  s64 v709;
  u32 v711;
  s32 v712;
  s64 v714;
  s64 v716;
  u64 v718;
  s64 v719;
  s64 v721;
  s64 v723;
  u64 v725;
  u32 v726;
  s64 v728;
  s64 v730;
  u32 v732;
  s32 v733;
  s64 v735;
  s64 v737;
  u64 v739;
  s64 v740;
  s64 v742;
  s64 v744;
  u64 v746;
  u32 v747;
  s64 v749;
  s64 v751;
  u32 v753;
  s32 v754;
  s64 v756;
  s64 v758;
  u64 v760;
  s64 v761;
  s64 v763;
  s64 v765;
  u64 v767;
  u32 v768;
  s64 v770;
  s64 v772;
  s64 v774;
  s32 v775;
  s64 v777;
  u64 v778;
  f32 v780;
  s64 v782;
  s64 v784;
  s32 v785;
  s32 v786;
  s32 v787;
  u32 *v789;
  s64 v791;
  s64 v793;
  s32 v794;
  s32 v795;
  s32 v796;
  s64 v797;
  u32 *v799;
  s64 v801;
  s64 v803;
  s32 v804;
  s32 v805;
  s32 v806;
  s64 v807;
  u32 *v809;
  s64 v811;
  s64 v813;
  s32 v814;
  s32 v815;
  s32 v816;
  s64 v817;
  u32 *v819;
  s64 v821;
  s64 v823;
  s64 v827;
  s64 v830;
  s64 v833;
  s64 v836;
  s64 v839;
  s64 v842;
  s64 v845;
  s64 v848;
  s64 v851;
  s64 v854;
  s32 v858;
  f32 s_h_r;
  f32 s_h_s;
  struct XRD773Unity_CommonMesh_array *v862;
  XRD773Unity_CommonMesh_o *v863;
  struct XRD773Unity_CommonMesh_array *v864;
  XRD773Unity_CommonMesh_o *v865;
  struct XRD773Unity_CommonMesh_array *v866;
  XRD773Unity_CommonMesh_o *v867;
  struct XRD773Unity_CommonMesh_array *v868;
  XRD773Unity_CommonMesh_o *v869;
  struct XRD773Unity_CommonMesh_array *v871;
  XRD773Unity_CommonMesh_o *v873;
  struct XRD773Unity_CommonMesh_array *v875;
  XRD773Unity_CommonMesh_o *v877;
  struct XRD773Unity_CommonMesh_array *v879;
  XRD773Unity_CommonMesh_o *v881;
  struct XRD773Unity_CommonMesh_array *v883;
  XRD773Unity_CommonMesh_o *v885;
  struct XRD773Unity_CommonMesh_array *v887;
  XRD773Unity_CommonMesh_o *v889;
  struct XRD773Unity_CommonMesh_array *v891;
  f32 w;
  s32 color_f;
  f32 v911;
  s32 fade_out;
  f32 amplitude_s;
  f32 angle_s;
  u32 abgr1;
  s32 color_t;
  s32 fade_in;
  s32 v918;
  s64 v919;
  u32 v920;
  u64 v921;
  effEVECombParSmoke_t_o **v922;
  u64 *v923;
  u64 *v924;
  s32 v925;
  signed s32 life;
  u64 *v927;
  u64 *v928;
  u32 *v929;
  s32 *v930;
  u64 *v931;
  s64 v932;
  s64 v933;
  s64 v934;
  s64 v935;
  s64 v936;
  s64 v937;
  s64 v938;
  s64 v939;
  s64 v940;
  s64 v941;
  s64 v942;
  s32 v943;
  s64 v944;
  s32 v945;
  s64 v946;
  s32 v947;
  s64 v948;
  s32 v949;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o v952;
  s64 v953;
  s64 v954;
  char *v955;
  UnityEngine_Vector4_o v956;

  *&v952.x = 0;
  *&v952.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  if (op_Equality(hEffEveCPSmokeBill01Tex, 0, 0))
  {
    asset_bc = get_asset_bc();
    if (IsLoad(asset_bc, "efftool"))
    {
      v8 = get_asset_bc();
      FileObject = LoadFileObject(v8, "efftool", "dds3data/efftool/bill/dbball01.tga");
      if (FileObject)
      {
        klass = FileObject->klass;
        if (FileObject->klass->_2.typeHierarchyDepth < typeHierarchyDepth
          || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != UnityEngine_Texture)
        {
          sub_8FC2C0(klass->_1.element_class, UnityEngine_Texture, &v953);
          if ((v953 & 1) != 0)
            v14 = v955;
          else
            v14 = &v953 + 1;
          v15 = sub_8C4940(v14);
        }
      }
      hEffEveCPSmokeBill01Tex = FileObject;
      v16 = get_asset_bc();
      v17 = LoadFileObject(v16, "efftool", "dds3data/efftool/bill/dbball02.tga");
      if (v17)
      {
        v18 = v17->klass;
        if (v17->klass->_2.typeHierarchyDepth < v19 || v18->_2.typeHierarchy[v19 - 1] != UnityEngine_Texture)
        {
          sub_8FC2C0(v18->_1.element_class, UnityEngine_Texture, &v953);
          if ((v953 & 1) != 0)
            v20 = v955;
          else
            v20 = &v953 + 1;
          v21 = sub_8C4940(v20);
        }
      }
      hEffEveCPSmokeBill02Tex = v17;
    }
    return;
  }
  v22 = Allocate(effEVECombParDrawBuff_tag);
  _ctor(v22, 0);
  Clear(v22);
  v24 = Allocate(effEVECombParDrawBuff_tag);
  _ctor(v24, 0);
  Clear(v24);
  v26 = Allocate(sdfTexHandle_t);
  sdfTexHandle_t___ctor(v26);
  v27 = Allocate(sdfTexHandle_t);
  sdfTexHandle_t___ctor(v27);
  *&v952.x = 0;
  *&v952.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *(v22 + 12) = 0;
  *(v24 + 12) = 0;
  SDF_VU0__LOADVECTOR(dds3CameraTargetPos);
  SDF_VU0__LOADVECTOR_B(dds3CameraEyePos);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__LOADVECTOR_B(dds3CameraUpVector);
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&p);
  param = (*pCombParSmoke)->param;
  loop = param->loop;
  number = param->number;
  life = param->life;
  fade_in = param->fade_in;
  fade_out = param->fade_out;
  color_t = param->color_t;
  color_f = param->color_f;
  abgr1 = param->abgr;
  accele = param->accele;
  angle_s = param->angle_s;
  amplitude_s = param->amplitude_s;
  SDF_VU0__COPYVECTOR(&dst, param->pos);
  v919 = number;
  if (!(*pCombParSmoke)->pMesh)
  {
    v34 = *pCombParSmoke;
    v34->pMesh = NewSpecific(XRD773Unity_CommonMesh, 2u);
    pMesh = (*pCombParSmoke)->pMesh;
    {
    }
    Instance = get_Instance();
    Mesh = GetMesh(Instance, (*pCombParSmoke)->param->blend + 4, 0, 0);
    v39 = Mesh;
    pMesh->m_Items[0] = v39;
    v42 = (*pCombParSmoke)->pMesh;
    gameObject = get_gameObject(v42->m_Items[0]);
    name = get_name(gameObject);
    v46 = Concat_5224608(name, ":effEVECombParSmokeDraw");
    set_name(gameObject, v46);
    v47 = (*pCombParSmoke)->pMesh;
    v48 = get_Instance();
    v49 = GetMesh(v48, (*pCombParSmoke)->param->blend + 4, 0, 0);
    v50 = v49;
    v47->m_Items[1] = v50;
    v53 = (*pCombParSmoke)->pMesh;
    v55 = get_gameObject(v53->m_Items[1]);
    v56 = get_name(v55);
    v57 = Concat_5224608(v56, ":effEVECombParSmokeDraw");
    set_name(v55, v57);
    LODWORD(number) = v919;
  }
  v918 = loop;
  v58 = NewSpecific(UnityEngine_Vector3__, 2u);
  v924 = NewSpecific(UnityEngine_Vector2__, 2u);
  v928 = NewSpecific(UnityEngine_Color__, 2u);
  v59 = NewSpecific(int__, 2u);
  v931 = NewSpecific(s32, 2u);
  v929 = NewSpecific(s32, 2u);
  v60 = (4 * number);
  v61 = NewSpecific(UnityEngine_Vector3, v60);
  v62 = v61;
  v58[4] = v62;
  v64 = NewSpecific(UnityEngine_Vector2, (4 * number));
  v65 = v64;
  v923 = v59;
  v927 = v58;
  v924[4] = v65;
  v68 = (6 * v919);
  v69 = NewSpecific(UnityEngine_Color, v60);
  v70 = v69;
  v928[4] = v70;
  v72 = NewSpecific(s32, v68);
  v73 = v72;
  v75 = v931 + 3;
  v923[4] = v73;
  *(v931 + 8) = 0;
  v929[8] = 0;
  v77 = NewSpecific(UnityEngine_Vector3, v60);
  v78 = v77;
  v58[5] = v78;
  v80 = NewSpecific(UnityEngine_Vector2, v60);
  v81 = v80;
  v924[5] = v81;
  v83 = NewSpecific(UnityEngine_Color, v60);
  v84 = v83;
  v86 = v923;
  v928[5] = v84;
  v88 = NewSpecific(s32, v68);
  v91 = v88;
  v93 = v918;
  v94 = v919;
  v923[5] = v91;
  *(v931 + 9) = 0;
  v930 = v931 + 9;
  v929[9] = 0;
  v96 = *pCombParSmoke;
  if (v919)
  {
    v97 = 1.0;
    v911 = (accele / 100.0) + 1.0;
    v98 = 0;
    v922 = pCombParSmoke;
    do
    {
      pPart = v96->pPart;
      v186 = pPart->m_Items[v98];
      frame = v186->frame;
      if (!frame)
      {
        v196 = v98;
        effEVECombParSmokePartInit(pCombParSmoke, v98);
        v98 = v196;
LABEL_200:
        if (!v93)
          goto LABEL_801;
        goto LABEL_201;
      }
      if (frame < 1 || life < frame)
        goto LABEL_200;
      wait = v186->wait;
      v925 = v186->frame;
      v921 = v98;
      sub_854710(&v186->fields, 0);
      if (wait < 0)
      {
        sub_854930(&v952, 0);
        sub_854710(&v186->fields, 1u);
        sub_854930(&v952, 1u);
        sub_854710(&v186->fields, 2u);
        sub_854930(&v952, 2u);
        ++v186->wait;
      }
      else
      {
        sub_854710(&p, 0);
        sub_854930(&v186->fields, 0);
        sub_854710(&v186->fields, 1u);
        sub_854710(&p, 1u);
        sub_854930(&v186->fields, 1u);
        sub_854710(&v186->fields, 2u);
        sub_854710(&p, 2u);
        sub_854930(&v186->fields, 2u);
        angle = v186->angle;
        sdfSin(angle);
        sub_854710(&v186->dirUp, 1u);
        sub_854930(&v186->dirUp, 1u);
        sub_854710(&v186->fields, 0);
        sub_854710(&v186->dirUp, 0);
        sub_854930(&v952, 0);
        sub_854710(&v186->fields, 1u);
        sub_854710(&v186->dirUp, 1u);
        sub_854930(&v952, 1u);
        sub_854710(&v186->fields, 2u);
        sub_854710(&v186->dirUp, 2u);
        sub_854930(&v952, 2u);
        amplitude = v186->amplitude;
        v193 = v186->angle;
        v194 = v911 * v186->shift_s;
        v186->up_s = v911 * v186->up_s;
        v186->shift_s = v194;
        v186->amplitude = amplitude_s + amplitude;
        v186->angle = angle_s + v193;
      }
      if (frame >= fade_in)
      {
        v200 = v97;
        if (life - frame > fade_out)
          goto LABEL_209;
        v199 = (life - frame);
        v198 = fade_out;
      }
      else
      {
        v198 = fade_in;
        v199 = frame;
      }
      v200 = v199 / v198;
LABEL_209:
      if (frame >= color_t)
      {
        if (color_f + color_t <= frame)
        {
          v202 = abgr1 & 0xFFFFFF;
          v201 = abgr1;
        }
        else
        {
          v203 = v97;
          if (color_f >= 1)
          {
            v203 = (frame - color_t) / color_f;
            if (v203 > v97)
              v203 = v97;
          }
          v201 = effColorBlend(abgr1 & 0xFF000000, abgr1, v203);
          v202 = v201 & 0xFFFFFF;
        }
      }
      else
      {
        v201 = abgr1 & 0xFF000000;
        v202 = 0;
      }
      v204 = effColorBlend(v202, v201, v200);
      v920 = effColorBlend(abgr1 & 0xFFFFFF, abgr1, v200);
      s_w_r = v186->s_w_r;
      sdfCos(s_w_r);
      sdfCos(v186->s_h_r);
      SDF_VU0__LOADVECTOR(v952);
      SDF_VU0__LOADVECTOR_B(dst);
      SDF_VU0__ADDVECTOR();
      SDF_VU0__STOREVECTOR(&v952);
      v207 = v22[2];
      v208 = *(v22 + 12);
      SDF_VU0__COPYVECTOR((v207 + 16 * v208 + 32), v952, 0);
      v210 = v22[3];
      *(v210 + 4 * v208 + 32) = v204;
      v212 = v22[4];
      v214 = *(v212 + 8 * v208 + 32);
      v215 = *(v214 + 32);
      *(v215 + 32) = 0;
      v216 = v22[4];
      v217 = *(v216 + 8 * v208 + 32);
      v218 = *(v217 + 32);
      *(v218 + 34) = 0;
      v220 = v22[4];
      v222 = *(v220 + 8 * v208 + 32);
      v224 = *(v222 + 40);
      *(v224 + 32) = 1;
      v226 = v22[4];
      v228 = *(v226 + 8 * v208 + 32);
      v230 = *(v228 + 40);
      *(v230 + 34) = 0;
      v232 = v22[4];
      v234 = *(v232 + 8 * v208 + 32);
      v236 = *(v234 + 48);
      *(v236 + 32) = 1;
      v238 = v22[4];
      v240 = *(v238 + 8 * v208 + 32);
      v242 = *(v240 + 48);
      *(v242 + 34) = 1;
      v244 = v22[4];
      v246 = *(v244 + 8 * v208 + 32);
      v248 = *(v246 + 56);
      *(v248 + 32) = 0;
      v250 = v22[4];
      v252 = *(v250 + 8 * v208 + 32);
      v254 = *(v252 + 56);
      *(v254 + 34) = 1;
      v256 = sdfCos(v186->roll);
      v257 = sdfSin(v186->roll);
      v258 = v22[5];
      v260 = *(v258 + 8 * v208 + 32);
      v262 = v256 * -32.0;
      v263 = v257 * -32.0;
      v264 = *(v260 + 32);
      *(v264 + 32) = (v256 * -32.0) - (v257 * -32.0);
      v266 = v22[5];
      v268 = *(v266 + 8 * v208 + 32);
      v270 = *(v268 + 32);
      *(v270 + 36) = v262 + v263;
      v272 = v22[5];
      v274 = *(v272 + 8 * v208 + 32);
      v276 = v256 * 32.0;
      v277 = *(v274 + 40);
      *(v277 + 32) = v276 - v263;
      v279 = v22[5];
      v281 = *(v279 + 8 * v208 + 32);
      v283 = v257 * 32.0;
      v284 = *(v281 + 40);
      *(v284 + 36) = v262 + v283;
      v286 = v22[5];
      v288 = *(v286 + 8 * v208 + 32);
      v290 = *(v288 + 48);
      *(v290 + 32) = v276 - v283;
      v292 = v22[5];
      v294 = *(v292 + 8 * v208 + 32);
      v296 = *(v294 + 48);
      *(v296 + 36) = v276 + v283;
      v298 = v22[5];
      v300 = *(v298 + 8 * v208 + 32);
      v302 = *(v300 + 56);
      v303 = v262 - v283;
      *(v302 + 32) = v303;
      v305 = v22[5];
      v307 = *(v305 + 8 * v208 + 32);
      v309 = *(v307 + 56);
      *(v309 + 36) = v276 + v263;
      v311 = (*pCombParSmoke)->pMesh;
      v313 = get_gameObject(v311->m_Items[0]);
      if (get_activeSelf(v313))
      {
        if (!*(v927 + 6))
          goto LABEL_104;
      }
      else
      {
        v101 = (*pCombParSmoke)->pMesh;
        v103 = get_gameObject(v101->m_Items[0]);
        SetActive(v103, 1, 0);
        if (!*(v927 + 6))
        {
LABEL_104:
        }
      }
      v314 = v927[4];
      v315 = v22[5];
      v316 = *(v931 + 8);
      v317 = *(v315 + 8 * v208 + 32);
      v318 = *(v317 + 32);
      v319 = *(v318 + 32);
      v320 = v22[5];
      v321 = *(v320 + 8 * v208 + 32);
      v322 = *(v321 + 32);
      v324 = (v952.y + *(v322 + 36)) * -0.01;
      v949 = 0;
      v948 = 0;
      sub_8524C0(&v948, (v952.x + v319) * 0.01, v324, v952.z * 0.01);
      v325 = HIDWORD(v948);
      v326 = v949;
      v328 = (v314 + 12 * v316);
      v328[8] = v948;
      v328[9] = v325;
      v328[10] = v326;
      v329 = v927[4];
      v330 = v22[5];
      v331 = *(v931 + 8);
      v333 = *(v330 + 8 * v208 + 32);
      v335 = *(v333 + 40);
      v337 = *(v335 + 32);
      v338 = v22[5];
      v340 = *(v338 + 8 * v208 + 32);
      v342 = *(v340 + 40);
      v344 = (v952.y + *(v342 + 36)) * -0.01;
      v947 = 0;
      v946 = 0;
      sub_8524C0(&v946, (v952.x + v337) * 0.01, v344, v952.z * 0.01);
      v345 = v947;
      v346 = HIDWORD(v946);
      v348 = (v329 + 12 * (v331 + 1));
      v348[8] = v946;
      v348[9] = v346;
      v348[10] = v345;
      v349 = v927[4];
      v350 = v22[5];
      v351 = *(v931 + 8);
      v353 = *(v350 + 8 * v208 + 32);
      v355 = *(v353 + 48);
      v357 = *(v355 + 32);
      v358 = v22[5];
      v360 = *(v358 + 8 * v208 + 32);
      v362 = *(v360 + 48);
      v364 = (v952.y + *(v362 + 36)) * -0.01;
      v945 = 0;
      v944 = 0;
      sub_8524C0(&v944, (v952.x + v357) * 0.01, v364, v952.z * 0.01);
      v365 = v945;
      v366 = HIDWORD(v944);
      v368 = (v349 + 12 * (v351 + 2));
      v368[8] = v944;
      v368[9] = v366;
      v368[10] = v365;
      v369 = v927[4];
      v370 = v22[5];
      v371 = *(v931 + 8);
      v373 = *(v370 + 8 * v208 + 32);
      v375 = *(v373 + 56);
      v377 = *(v375 + 32);
      v378 = v22[5];
      v380 = *(v378 + 8 * v208 + 32);
      v382 = *(v380 + 56);
      v384 = (v952.y + *(v382 + 36)) * -0.01;
      v943 = 0;
      v942 = 0;
      sub_8524C0(&v942, (v952.x + v377) * 0.01, v384, v952.z * 0.01);
      v386 = v943;
      v387 = HIDWORD(v942);
      v389 = (v369 + 12 * (v371 + 3));
      v389[8] = v942;
      v389[9] = v387;
      v389[10] = v386;
      v390 = v924[4];
      v391 = v22[4];
      v392 = *(v931 + 8);
      v393 = *(v391 + 8 * v208 + 32);
      v394 = *(v393 + 32);
      v395 = v22[4];
      v396 = *(v394 + 32);
      v397 = *(v395 + 8 * v208 + 32);
      v398 = *(v397 + 32);
      LOWORD(v385) = *(v398 + 34);
      v941 = 0;
      sub_851710(&v941, v396, v385);
      v401 = HIDWORD(v941);
      v402 = v390 + 8 * v392;
      *(v402 + 32) = v941;
      *(v402 + 36) = v401;
      v403 = v924[4];
      v404 = v22[4];
      v405 = *(v931 + 8);
      v407 = *(v404 + 8 * v208 + 32);
      v409 = *(v407 + 40);
      v411 = v22[4];
      v412 = *(v409 + 32);
      v414 = *(v411 + 8 * v208 + 32);
      v416 = *(v414 + 40);
      LOWORD(v400) = *(v416 + 34);
      v940 = 0;
      sub_851710(&v940, v412, v400);
      v419 = HIDWORD(v940);
      v420 = v403 + 8 * (v405 + 1);
      *(v420 + 32) = v940;
      *(v420 + 36) = v419;
      v421 = v924[4];
      v422 = v22[4];
      v423 = *(v931 + 8);
      v425 = *(v422 + 8 * v208 + 32);
      v427 = *(v425 + 48);
      v429 = v22[4];
      v430 = *(v427 + 32);
      v432 = *(v429 + 8 * v208 + 32);
      v434 = *(v432 + 48);
      LOWORD(v418) = *(v434 + 34);
      v939 = 0;
      sub_851710(&v939, v430, v418);
      v437 = HIDWORD(v939);
      v438 = v421 + 8 * (v423 + 2);
      *(v438 + 32) = v939;
      *(v438 + 36) = v437;
      v439 = v924[4];
      v440 = v22[4];
      v441 = *(v931 + 8);
      v443 = *(v440 + 8 * v208 + 32);
      v445 = *(v443 + 56);
      v447 = v22[4];
      v448 = *(v445 + 32);
      v450 = *(v447 + 8 * v208 + 32);
      v452 = *(v450 + 56);
      LOWORD(v436) = *(v452 + 34);
      v938 = 0;
      sub_851710(&v938, v448, v436);
      v454 = v441 + 3;
      v455 = (v441 + 3) >= *(v439 + 24);
      v456 = HIDWORD(v938);
      v458 = v439 + 8 * v454;
      *(v458 + 32) = v938;
      *(v458 + 36) = v456;
      v459 = v22[3];
      v956 = SDF_VU0__Retdds3ColorItoF(*(v459 + 4 * v208 + 32), 128.0, 0);
      v461 = v928[4];
      v462 = *(v931 + 8);
      v953 = 0;
      v954 = 0;
      sub_19EC630(&v953, v956.x, v956.y, v956.z, v956.w);
      v463 = HIDWORD(v953);
      v465 = v954;
      v464 = HIDWORD(v954);
      v467 = (v461 + 16 * v462);
      v467[8] = v953;
      v467[9] = v463;
      v467[10] = v465;
      v467[11] = v464;
      v468 = v928[4];
      v469 = *(v931 + 8);
      v936 = 0;
      v937 = 0;
      sub_19EC630(&v936, v956.x, v956.y, v956.z, v956.w);
      v470 = HIDWORD(v936);
      v472 = v937;
      v471 = HIDWORD(v937);
      v473 = v469 + 1;
      v475 = (v468 + 16 * v473);
      v475[8] = v936;
      v475[9] = v470;
      v475[10] = v472;
      v475[11] = v471;
      v476 = v928[4];
      v477 = *(v931 + 8);
      v934 = 0;
      v935 = 0;
      sub_19EC630(&v934, v956.x, v956.y, v956.z, v956.w);
      v478 = HIDWORD(v934);
      v480 = v935;
      v479 = HIDWORD(v935);
      v481 = v477 + 2;
      v483 = (v476 + 16 * v481);
      v483[8] = v934;
      v483[9] = v478;
      v483[10] = v480;
      v483[11] = v479;
      v484 = v928[4];
      v485 = *(v931 + 8);
      v932 = 0;
      v933 = 0;
      sub_19EC630(&v932, v956.x, v956.y, v956.z, v956.w);
      v486 = HIDWORD(v932);
      v488 = v933;
      v487 = HIDWORD(v933);
      v489 = v485 + 3;
      v491 = (v484 + 16 * v489);
      v491[8] = v932;
      v491[9] = v486;
      v491[10] = v488;
      v491[11] = v487;
      v493 = v923[4];
      v494 = v929[8];
      *(v493 + 4 * v494 + 32) = *(v931 + 8);
      v495 = v923[4];
      v496 = v929[8] + 1LL;
      *(v495 + 4 * v496 + 32) = *(v931 + 8) + 1;
      v497 = v923[4];
      v498 = v929[8] + 2LL;
      *(v497 + 4 * v498 + 32) = *(v931 + 8) + 3;
      v499 = v923[4];
      v500 = v929[8] + 3LL;
      *(v499 + 4 * v500 + 32) = *(v931 + 8) + 1;
      v501 = v923[4];
      v502 = v929[8] + 4LL;
      *(v501 + 4 * v502 + 32) = *(v931 + 8) + 2;
      v503 = v923[4];
      v504 = v929[8] + 5LL;
      *(v503 + 4 * v504 + 32) = *(v931 + 8) + 3;
      *(v931 + 8) += 4;
      v929[8] += 6;
      ++*(v22 + 12);
      v508 = v24[2];
      v509 = *(v24 + 12);
      SDF_VU0__COPYVECTOR((v508 + 16 * v509 + 32), v952, 0);
      v512 = v24[3];
      *(v512 + 4 * v509 + 32) = v920;
      v514 = v24[4];
      v515 = *(v514 + 8 * v509 + 32);
      v516 = *(v515 + 32);
      *(v516 + 32) = 0;
      v517 = v24[4];
      v518 = *(v517 + 8 * v509 + 32);
      v519 = *(v518 + 32);
      *(v519 + 34) = 0;
      v521 = v24[4];
      v523 = *(v521 + 8 * v509 + 32);
      v525 = *(v523 + 40);
      *(v525 + 32) = 1;
      v527 = v24[4];
      v529 = *(v527 + 8 * v509 + 32);
      v531 = *(v529 + 40);
      *(v531 + 34) = 0;
      v533 = v24[4];
      v535 = *(v533 + 8 * v509 + 32);
      v537 = *(v535 + 48);
      *(v537 + 32) = 1;
      v539 = v24[4];
      v541 = *(v539 + 8 * v509 + 32);
      v543 = *(v541 + 48);
      *(v543 + 34) = 1;
      v545 = v24[4];
      v547 = *(v545 + 8 * v509 + 32);
      v549 = *(v547 + 56);
      *(v549 + 32) = 0;
      v551 = v24[4];
      v553 = *(v551 + 8 * v509 + 32);
      v555 = *(v553 + 56);
      *(v555 + 34) = 1;
      roll = v186->roll;
      v558 = sdfCos(roll);
      v559 = sdfSin(v186->roll);
      v560 = v24[5];
      v562 = *(v560 + 8 * v509 + 32);
      v564 = v558 * -32.0;
      v565 = v559 * -32.0;
      v566 = *(v562 + 32);
      *(v566 + 32) = (v558 * -32.0) - (v559 * -32.0);
      v568 = v24[5];
      v570 = *(v568 + 8 * v509 + 32);
      v572 = *(v570 + 32);
      *(v572 + 36) = v564 + v565;
      v574 = v24[5];
      v576 = *(v574 + 8 * v509 + 32);
      v578 = v558 * 32.0;
      v579 = *(v576 + 40);
      *(v579 + 32) = v578 - v565;
      v581 = v24[5];
      v583 = *(v581 + 8 * v509 + 32);
      v585 = v559 * 32.0;
      v586 = *(v583 + 40);
      *(v586 + 36) = v564 + v585;
      v588 = v24[5];
      v590 = *(v588 + 8 * v509 + 32);
      v592 = *(v590 + 48);
      *(v592 + 32) = v578 - v585;
      v594 = v24[5];
      v596 = *(v594 + 8 * v509 + 32);
      v598 = *(v596 + 48);
      *(v598 + 36) = v578 + v585;
      v600 = v24[5];
      v602 = *(v600 + 8 * v509 + 32);
      v604 = *(v602 + 56);
      v605 = v564 - v585;
      *(v604 + 32) = v605;
      v607 = v24[5];
      v609 = *(v607 + 8 * v509 + 32);
      v611 = *(v609 + 56);
      *(v611 + 36) = v578 + v565;
      v613 = (*v922)->pMesh;
      v615 = get_gameObject(v613->m_Items[1]);
      if (get_activeSelf(v615))
      {
        if (*(v927 + 6) <= 1u)
          goto LABEL_153;
      }
      else
      {
        v150 = (*v922)->pMesh;
        v152 = get_gameObject(v150->m_Items[1]);
        SetActive(v152, 1, 0);
        if (*(v927 + 6) <= 1u)
        {
LABEL_153:
        }
      }
      v616 = v927[5];
      v618 = v24[5];
      v619 = *v930;
      v620 = *(v618 + 8 * v509 + 32);
      v621 = *(v620 + 32);
      v622 = *(v621 + 32);
      v623 = v24[5];
      v624 = *(v623 + 8 * v509 + 32);
      v625 = *(v624 + 32);
      v627 = (v952.y + *(v625 + 36)) * -0.01;
      v949 = 0;
      v948 = 0;
      sub_8524C0(&v948, (v952.x + v622) * 0.01, v627, (v952.z * 0.01) + -0.05);
      v628 = HIDWORD(v948);
      v629 = v949;
      v631 = (v616 + 12 * v619);
      v631[8] = v948;
      v631[9] = v628;
      v631[10] = v629;
      v633 = v927[5];
      v635 = v24[5];
      v636 = *v930;
      v638 = *(v635 + 8 * v509 + 32);
      v640 = *(v638 + 40);
      v642 = *(v640 + 32);
      v643 = v24[5];
      v645 = *(v643 + 8 * v509 + 32);
      v647 = *(v645 + 40);
      v649 = (v952.y + *(v647 + 36)) * -0.01;
      v947 = 0;
      v946 = 0;
      sub_8524C0(&v946, (v952.x + v642) * 0.01, v649, (v952.z * 0.01) + -0.05);
      v650 = v947;
      v651 = HIDWORD(v946);
      v653 = (v633 + 12 * (v636 + 1));
      v653[8] = v946;
      v653[9] = v651;
      v653[10] = v650;
      v655 = v927[5];
      v657 = v24[5];
      v658 = *v930;
      v660 = *(v657 + 8 * v509 + 32);
      v662 = *(v660 + 48);
      v664 = *(v662 + 32);
      v665 = v24[5];
      v667 = *(v665 + 8 * v509 + 32);
      v669 = *(v667 + 48);
      v671 = (v952.y + *(v669 + 36)) * -0.01;
      v945 = 0;
      v944 = 0;
      sub_8524C0(&v944, (v952.x + v664) * 0.01, v671, (v952.z * 0.01) + -0.05);
      v672 = v945;
      v673 = HIDWORD(v944);
      v675 = (v655 + 12 * (v658 + 2));
      v675[8] = v944;
      v675[9] = v673;
      v675[10] = v672;
      v677 = v927[5];
      v679 = v24[5];
      v680 = *v930;
      v682 = *(v679 + 8 * v509 + 32);
      v684 = *(v682 + 56);
      v686 = *(v684 + 32);
      v687 = v24[5];
      v689 = *(v687 + 8 * v509 + 32);
      v691 = *(v689 + 56);
      v693 = (v952.y + *(v691 + 36)) * -0.01;
      v943 = 0;
      v942 = 0;
      sub_8524C0(&v942, (v952.x + v686) * 0.01, v693, (v952.z * 0.01) + -0.05);
      v695 = v943;
      v696 = HIDWORD(v942);
      v698 = (v677 + 12 * (v680 + 3));
      v698[8] = v942;
      v698[9] = v696;
      v698[10] = v695;
      v97 = 1.0;
      v700 = v924[5];
      v702 = v24[4];
      v703 = *v930;
      v704 = *(v702 + 8 * v509 + 32);
      v705 = *(v704 + 32);
      v706 = v24[4];
      v707 = *(v705 + 32);
      v708 = *(v706 + 8 * v509 + 32);
      v709 = *(v708 + 32);
      LOWORD(v694) = *(v709 + 34);
      v941 = 0;
      sub_851710(&v941, v707, v694);
      v712 = HIDWORD(v941);
      v714 = v700 + 8 * v703;
      *(v714 + 32) = v941;
      *(v714 + 36) = v712;
      v716 = v924[5];
      v718 = v24[4];
      v719 = *v930;
      v721 = *(v718 + 8 * v509 + 32);
      v723 = *(v721 + 40);
      v725 = v24[4];
      v726 = *(v723 + 32);
      v728 = *(v725 + 8 * v509 + 32);
      v730 = *(v728 + 40);
      LOWORD(v711) = *(v730 + 34);
      v940 = 0;
      sub_851710(&v940, v726, v711);
      v733 = HIDWORD(v940);
      v735 = v716 + 8 * (v719 + 1);
      *(v735 + 32) = v940;
      *(v735 + 36) = v733;
      v737 = v924[5];
      v739 = v24[4];
      v740 = *v930;
      v742 = *(v739 + 8 * v509 + 32);
      v744 = *(v742 + 48);
      v746 = v24[4];
      v747 = *(v744 + 32);
      v749 = *(v746 + 8 * v509 + 32);
      v751 = *(v749 + 48);
      LOWORD(v732) = *(v751 + 34);
      v939 = 0;
      sub_851710(&v939, v747, v732);
      v754 = HIDWORD(v939);
      v756 = v737 + 8 * (v740 + 2);
      *(v756 + 32) = v939;
      *(v756 + 36) = v754;
      v758 = v924[5];
      v760 = v24[4];
      v761 = *v930;
      v763 = *(v760 + 8 * v509 + 32);
      v765 = *(v763 + 56);
      v767 = v24[4];
      v768 = *(v765 + 32);
      v770 = *(v767 + 8 * v509 + 32);
      v772 = *(v770 + 56);
      LOWORD(v753) = *(v772 + 34);
      v938 = 0;
      sub_851710(&v938, v768, v753);
      v774 = v761 + 3;
      v455 = (v761 + 3) >= *(v758 + 24);
      v775 = HIDWORD(v938);
      v777 = v758 + 8 * v774;
      *(v777 + 32) = v938;
      *(v777 + 36) = v775;
      v778 = v24[3];
      w = SDF_VU0__Retdds3ColorItoF(*(v778 + 4 * v509 + 32), 128.0, 0).w;
      v780 = w;
      v782 = v928[5];
      v784 = *v930;
      v953 = 0;
      v954 = 0;
      sub_19EC630(&v953, 0.0, 0.0, 0.0, w);
      v785 = HIDWORD(v953);
      v787 = v954;
      v786 = HIDWORD(v954);
      v789 = (v782 + 16 * v784);
      v789[8] = v953;
      v789[9] = v785;
      v789[10] = v787;
      v789[11] = v786;
      v791 = v928[5];
      v793 = *v930;
      v936 = 0;
      v937 = 0;
      sub_19EC630(&v936, 0.0, 0.0, 0.0, v780);
      v794 = HIDWORD(v936);
      v796 = v937;
      v795 = HIDWORD(v937);
      v797 = v793 + 1;
      v799 = (v791 + 16 * v797);
      v799[8] = v936;
      v799[9] = v794;
      v799[10] = v796;
      v799[11] = v795;
      v801 = v928[5];
      v803 = *v930;
      v934 = 0;
      v935 = 0;
      sub_19EC630(&v934, 0.0, 0.0, 0.0, v780);
      v804 = HIDWORD(v934);
      v806 = v935;
      v805 = HIDWORD(v935);
      v807 = v803 + 2;
      v809 = (v801 + 16 * v807);
      v809[8] = v934;
      v809[9] = v804;
      v809[10] = v806;
      v809[11] = v805;
      v811 = v928[5];
      v813 = *v930;
      v932 = 0;
      v933 = 0;
      sub_19EC630(&v932, 0.0, 0.0, 0.0, v780);
      v814 = HIDWORD(v932);
      v816 = v933;
      v815 = HIDWORD(v933);
      v817 = v813 + 3;
      v819 = (v811 + 16 * v817);
      v819[8] = v932;
      v819[9] = v814;
      v819[10] = v816;
      v819[11] = v815;
      v86 = v923;
      v821 = v923[5];
      pCombParSmoke = v922;
      v823 = v929[9];
      *(v821 + 4 * v823 + 32) = *v930;
      v827 = v923[5];
      v830 = v929[9] + 1LL;
      *(v827 + 4 * v830 + 32) = *v930 + 1;
      v833 = v923[5];
      v836 = v929[9] + 2LL;
      *(v833 + 4 * v836 + 32) = *v930 + 3;
      v839 = v923[5];
      v842 = v929[9] + 3LL;
      *(v839 + 4 * v842 + 32) = *v930 + 1;
      v845 = v923[5];
      v848 = v929[9] + 4LL;
      *(v845 + 4 * v848 + 32) = *v930 + 2;
      v851 = v923[5];
      v854 = v929[9] + 5LL;
      *(v851 + 4 * v854 + 32) = *v930 + 3;
      *v930 += 4;
      v93 = v918;
      v94 = v919;
      v929[9] += 6;
      v858 = *(v24 + 12) + 1;
      *(v24 + 12) = v858;
      if (*(v22 + 12) == 32)
      {
        *(v22 + 12) = 0;
        v858 = *(v24 + 12);
      }
      v98 = v921;
      frame = v925;
      if (v858 == 32)
        *(v24 + 12) = 0;
      s_h_r = v186->s_h_r;
      s_h_s = v186->s_h_s;
      v186->s_w_r = v186->s_w_r + v186->s_w_s;
      v186->s_h_r = s_h_r + s_h_s;
      v186->roll = v186->roll + v186->roll_s;
      if (!v918)
      {
LABEL_801:
        v197 = v186->frame + 1;
        goto LABEL_802;
      }
LABEL_201:
      if (life != frame)
        goto LABEL_801;
      v197 = 0;
LABEL_802:
      v186->frame = v197;
      v96 = *pCombParSmoke;
      ++v98;
    }
    while (v94 != v98);
  }
  if (v96->pMesh)
  {
    if (*(v931 + 8))
    {
      v862 = (*pCombParSmoke)->pMesh;
      v863 = v862->m_Items[0];
      SetPosition_20241056(v863, v927[4]);
      v864 = (*pCombParSmoke)->pMesh;
      v865 = v864->m_Items[0];
      SetIndexTable(v865, v86[4]);
      v866 = (*pCombParSmoke)->pMesh;
      v867 = v866->m_Items[0];
      SetColor_20241296(v867, v928[4]);
      v868 = (*pCombParSmoke)->pMesh;
      v869 = v868->m_Items[0];
      SetUvTable_20243232(v869, v924[4]);
      v871 = (*pCombParSmoke)->pMesh;
      v873 = v871->m_Items[0];
      SetMatTexture(v873, hEffEveCPSmokeBill01Tex);
      v875 = (*pCombParSmoke)->pMesh;
      v877 = v875->m_Items[1];
      SetPosition_20241056(v877, v927[5]);
      v879 = (*pCombParSmoke)->pMesh;
      v881 = v879->m_Items[1];
      SetIndexTable(v881, v86[5]);
      v883 = (*pCombParSmoke)->pMesh;
      v885 = v883->m_Items[1];
      SetColor_20241296(v885, v928[5]);
      v887 = (*pCombParSmoke)->pMesh;
      v889 = v887->m_Items[1];
      SetUvTable_20243232(v889, v924[5]);
      v891 = (*pCombParSmoke)->pMesh;
      SetMatTexture(v891->m_Items[1], hEffEveCPSmokeBill02Tex);
    }
  }
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
  struct effEVECombParSmokePart_t_array *pPart;
  struct effEVECombParSmokeParam_t_o *param;
  effEVECombParSmokePart_t_o *v8;
  s64 wait;
  s64 timing;
  u32 v11;
  u32 v12;
  f32 v13;
  f32 scl_s;
  f32 v15;
  f32 scl_w;
  f32 scl_h;
  char v19;
  f32 roll_s;
  f32 v22;
  struct effEVECombParSmokeParam_t_o *v23;
  f32 amplitude;
  struct effEVECombParSmokeParam_t_o *v25;
  f32 up_s;
  struct effEVECombParSmokeParam_t_o *v27;
  f32 shift_s;
  UnityEngine_Vector4_o v29;

  *&v29.x = 0;
  *&v29.z = 0;
  pPart = (*pCombParSmoke)->pPart;
  param = (*pCombParSmoke)->param;
  v8 = pPart->m_Items[index];
  timing = param->timing;
  wait = param->wait;
  v11 = DDS3EFFECT_RAND_I();
  v8->frame = v11 / timing * timing - v11;
  v12 = DDS3EFFECT_RAND_I();
  v8->wait = v12 / wait * wait - v12;
  v13 = DDS3EFFECT_RAND_FA((*pCombParSmoke)->param->scale_r, 0);
  v8->scale = v13 * (*pCombParSmoke)->param->scale;
  v8->s_w_r = DDS3EFFECT_RAND_F() * 6.2832;
  v8->s_h_r = DDS3EFFECT_RAND_F() * 6.2832;
  scl_s = (*pCombParSmoke)->param->scl_s;
  v8->s_w_s = scl_s * DDS3EFFECT_RAND_FA(0.5);
  v15 = (*pCombParSmoke)->param->scl_s;
  v8->s_h_s = v15 * DDS3EFFECT_RAND_FA(0.5);
  scl_w = (*pCombParSmoke)->param->scl_w;
  v8->s_w = v13 * (scl_w * DDS3EFFECT_RAND_FA(0.3));
  scl_h = (*pCombParSmoke)->param->scl_h;
  v8->s_h = v13 * (scl_h * DDS3EFFECT_RAND_FA(0.3));
  v8->roll = DDS3EFFECT_RAND_F() * 6.2832;
  v19 = DDS3EFFECT_RAND_I();
  roll_s = (*pCombParSmoke)->param->roll_s;
  if ((v19 & 1) != 0)
  {
    v22 = roll_s * DDS3EFFECT_RAND_FA(0.3);
  }
  else
  {
    v22 = -(roll_s * DDS3EFFECT_RAND_FA(0.3));
  }
  v8->roll_s = v22;
  DDS3EFFECT_RAND_PM();
  sub_854930(&v29, 0);
  DDS3EFFECT_RAND_PM();
  sub_854930(&v29, 1u);
  DDS3EFFECT_RAND_PM();
  sub_854930(&v29, 2u);
  SDF_VU0__LOADVECTOR(v29);
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v29);
  DDS3EFFECT_RAND_F();
  sub_854710(&v29, 0);
  sub_854930(&v8->fields, 0);
  DDS3EFFECT_RAND_F();
  sub_854710(&v29, 1u);
  sub_854930(&v8->fields, 1u);
  DDS3EFFECT_RAND_F();
  sub_854710(&v29, 2u);
  sub_854930(&v8->fields, 2u);
  DDS3EFFECT_RAND_PM();
  sub_854930(&v8->dirUp, 0);
  sub_854930(&v8->dirUp, 1u);
  DDS3EFFECT_RAND_PM();
  sub_854930(&v8->dirUp, 2u);
  SDF_VU0__LOADVECTOR(v8->dirUp);
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v8->dirUp);
  v23 = (*pCombParSmoke)->param;
  amplitude = v23->amplitude;
  v8->amplitude = amplitude * DDS3EFFECT_RAND_FA(v23->amplitude_r);
  v8->angle = 0.0;
  v25 = (*pCombParSmoke)->param;
  up_s = v25->up_s;
  v8->up_s = up_s * DDS3EFFECT_RAND_FA(v25->up_s_r);
  v27 = (*pCombParSmoke)->param;
  shift_s = v27->shift_s;
  v8->shift_s = shift_s * DDS3EFFECT_RAND_FA(v27->shift_s_r);
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
LABEL_3:
      if (param->timing > 0)
        return;
LABEL_7:
      param->timing = 1;
      return;
    }
  }
  else if (param->fade_out > 0)
  {
    goto LABEL_3;
  }
  param->fade_out = 1;
  param = (*pCombParSmoke)->param;
  if (param->timing <= 0)
    goto LABEL_7;
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
  Il2CppObject *pwork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  Il2CppClass *v9;
  s64 namespaze_high;
  s32 data;
  u64 i;
  u64 *monitor;
  s64 v15;
  effBezier4PPart_t_o *v17;
  Il2CppObject *v18;
  u64 v19[3];

  v18 = 0;
  pwork = (*hEffect)->pwork;
  if (pwork)
  {
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effAPPoint4_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effAPPoint4_tag, v19);
      if ((v19[0] & 1) != 0)
        v7 = v19[2];
      else
        v7 = v19 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  v18 = (*hEffect)->pwork;
  v9 = pwork[1].klass;
  namespaze_high = HIDWORD(v9->_1.namespaze);
  if (namespaze_high)
  {
    data = v9->_1.byval_arg.data;
    for (i = 0; i != namespaze_high; ++i)
    {
      monitor = pwork[1].monitor;
      v15 = monitor[i + 4];
      effAPPoint4PartInit(&v18, i);
      *(v15 + 16) = DDS3EFFECT_RAND_I() % data;
      v17 = dds3Bezier4PGetPart(&pwork[2], i);
      v17->weight = v17->step * (*(v15 + 16))++;
    }
  }
}

// 0x1397020
void effEveAPP4SetPoint(effHandle_t *hEffect, effEveAPP4Point_t **pEveAP4Point) {
  Il2CppObject *pwork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  s64 v10;
  s64 i;
  const char *name;
  struct UnityEngine_Vector4_array *point;
  u64 v14;
  const char *v17;
  struct UnityEngine_Vector4_array *v18;
  const char *v21;
  struct UnityEngine_Vector4_array *v22;
  u32 *data;
  struct System_Single_array *radius;
  s32 v28;
  u64 v30[3];

  pwork = hEffect->pwork;
  if (pwork)
  {
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effAPPoint4_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effAPPoint4_tag, v30);
      if ((v30[0] & 1) != 0)
        v8 = v30[2];
      else
        v8 = v30 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = 8;
  for (i = 32; i != 96; i += 16)
  {
    name = pwork[1].klass->_1.name;
    point = (*pEveAP4Point)->point;
    v14 = v10 - 8;
    sub_854710(point + i, 0);
    sub_854930(&name[i], 0);
    v17 = pwork[1].klass->_1.name;
    v18 = (*pEveAP4Point)->point;
    sub_854710(v18 + i, 1u);
    sub_854930(&v17[i], 1u);
    v21 = pwork[1].klass->_1.name;
    v22 = (*pEveAP4Point)->point;
    sub_854710(v22 + i, 2u);
    sub_854930(&v21[i], 2u);
    data = pwork[1].klass->_1.this_arg.data;
    radius = (*pEveAP4Point)->radius;
    v28 = *(&radius->obj.klass + v10);
    data[v10++] = v28;
  }
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
  struct effBTLCutHandle_t_o *hBTLCutEffect;
  u32 frame;
  struct effBTL_SkillCutTable_t_o *pSkillCut;
  struct effBTL_SkillParts_t_o *parts;
  s64 number;
  u32 abgr;
  u64 v11;
  struct effBTL_SkillPartsList_t_array *list;
  effBTL_SkillPartsList_t_o *v14;
  struct effPartHandle_t_array *hPart;
  effBTL_SkillPositionPtr_t_o *pos_ptr;
  effEveBEDCutHandle_t_o *v18;
  struct evtUnitHandle_t_o *hUnit;
  sdfModelRootNode_t_o *modelRoot;
  s32 height;
  struct effPartHandle_t_array *v23;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  struct effPartHandle_t_array *v30;
  UnityEngine_Matrix4x4_o *v32;
  effEveBEDParams_t_o *pParams;
  struct effPartHandle_t_array *v35;
  f32 v36;
  f32 v37;
  f32 v38;
  f32 v39;
  struct effPartHandle_t_array *v43;
  struct effPartHandle_t_array *v45;
  effBTLCutHandle_t_CutEndCallbackDelegate_o *CutEndCallback;
  UnityEngine_Matrix4x4_o v48;
  UnityEngine_Matrix4x4_o v49;
  UnityEngine_Matrix4x4_o v50;
  UnityEngine_Matrix4x4_o v51;
  UnityEngine_Matrix4x4_o v52;
  UnityEngine_Matrix4x4_o aMatrix;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v55;
  UnityEngine_Vector4_o v56;

  *&p.x = 0;
  *&p.z = 0;
  memset(&aMatrix, 0, sizeof(aMatrix));
  memset(&v52, 0, sizeof(v52));
  *&v51.m00 = 0;
  *&v51.m20 = 0;
  sub_854690(&v51.m00, 0.0, 1.0, 0.0, 0.0);
  hBTLCutEffect = (*hEveBEDCut)->hBTLCutEffect;
  frame = hBTLCutEffect->frame;
  pSkillCut = hBTLCutEffect->pSkillCut;
  SDF_VU0__LOADVECTOR((*hEveBEDCut)->pParams->rot, 0);
  SDF_VU0__LOADVECTOR_B(*&v51.m00);
  Mult();
  ToMatrix();
  SDF_VU0__STOREMATRIX(&aMatrix);
  parts = pSkillCut->parts;
  number = parts->number;
  if (parts->number)
  {
    abgr = (*hEveBEDCut)->pParams->abgr;
    v11 = 0;
    list = parts->list;
    if (!LODWORD(list->max_length))
    {
LABEL_12:
    }
    while (1)
    {
      v14 = list->m_Items[v11];
      if (v14->timing < frame)
      {
        hPart = hBTLCutEffect->hPart;
        if (hPart->m_Items[v11])
        {
          pos_ptr = v14->pos_ptr;
          v18 = *hEveBEDCut;
          if (pos_ptr->target == 5 && (hUnit = v18->hUnit) != 0)
          {
            modelRoot = hUnit->Model->modelRoot;
            height = pos_ptr->height;
            sdfModelGetMarkPosUnity(modelRoot, height);
            SDF_VU0__STOREVECTOR(&p);
            v23 = hBTLCutEffect->hPart;
            x = p.x;
            y = p.y;
            z = p.z;
            w = p.w;
            else if (v11 >= LODWORD(v23->max_length))
            {
LABEL_26:
            }
            v55.x = x;
            v55.y = y;
            v55.z = z;
            v55.w = w;
            dds3EffectPartSetPosition(&v23->m_Items[v11], v55);
            sdfModelGetMarkPosMatrixUnity(modelRoot, v14->pos_ptr->height);
            v49 = aMatrix;
            SDF_VU0__LOADMATRIX_B(&v49);
            MultMatrixNoArg();
            SDF_VU0__STOREMATRIX(&v52);
            v30 = hBTLCutEffect->hPart;
            v51 = v52;
            v32 = &v48;
            v48 = v51;
          }
          else
          {
            pParams = v18->pParams;
            effEveBEDPartGetPositionPtr(pParams, pos_ptr);
            SDF_VU0__STOREVECTOR(&p);
            v35 = hBTLCutEffect->hPart;
            v37 = p.x;
            v36 = p.y;
            v39 = p.z;
            v38 = p.w;
            else if (v11 >= LODWORD(v35->max_length))
            {
LABEL_39:
            }
            v56.x = v37;
            v56.y = v36;
            v56.z = v39;
            v56.w = v38;
            dds3EffectPartSetPosition(&v35->m_Items[v11], v56);
            v30 = hBTLCutEffect->hPart;
            v51 = aMatrix;
            v32 = &v50;
            v50 = v51;
          }
          dds3EffectPartSetRotateMatrix(&v30->m_Items[v11], v32);
          v43 = hBTLCutEffect->hPart;
          else if (v11 >= LODWORD(v43->max_length))
          {
LABEL_46:
          }
          dds3EffectPartSetColor(&v43->m_Items[v11], abgr);
          v45 = hBTLCutEffect->hPart;
          dds3EffectPartDraw(&v45->m_Items[v11]);
        }
      }
      if (++v11 == number)
        break;
      list = pSkillCut->parts->list;
      if (v11 >= LODWORD(list->max_length))
        goto LABEL_12;
    }
  }
  if (hBTLCutEffect->cut_frame == frame)
  {
    CutEndCallback = hBTLCutEffect->CutEndCallback;
    if (CutEndCallback)
      effBTLCutHandle_t_CutEndCallbackDelegate__Invoke(CutEndCallback, hBTLCutEffect);
  }
  ++hBTLCutEffect->frame;
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
  u32 height;
  s64 direction;
  s32 max_length;
  s64 v13;
  f32 y;
  f32 w;
  f32 x;
  f32 z;
  f32 *static_fields;
  f32 v21;
  f32 v22;
  f32 v23;
  f32 v24;
  struct System_Single_array *effEveBED_Ptr_D;
  f32 v29;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v36;
  UnityEngine_Vector4_o v37;
  UnityEngine_Vector4_o v38;
  UnityEngine_Vector4_o v39;

  *&dst.x = 0;
  *&dst.z = 0;
  *&v36.x = 0;
  *&v36.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  height = pPosPtr->height;
  direction = pPosPtr->direction;
  SDF_VU0__COPYVECTOR(&dst, pParams->center);
  if (height != 5)
  {
    max_length = effEveBED_Ptr_H->max_length;
    sub_854710(&dst, 1u);
    if (height == 4)
      goto LABEL_17;
  }
  if (direction == 9)
  {
LABEL_17:
    sub_854930(&p, 2u);
    sub_854930(&p, 1u);
    sub_854930(&p, 0);
    sub_854930(&dst, 1u);
    v38 = dst;
    v21 = static_fields[38];
    v22 = static_fields[39];
    v23 = static_fields[40];
    v24 = static_fields[41];
    v39.x = v21;
    v39.y = v22;
    v39.z = v23;
    v39.w = v24;
    *&v37.x = 0;
    *&v37.z = v13;
    LookAtMatrix(v38, v39, v37);
    ReverseMatrix();
    SDF_VU0__LOADVECTOR(p);
    SDF_VU0__VECTOR_W_SET_ZERO();
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__LOADVECTOR_B(dst);
    SDF_VU0__ADDVECTOR();
  }
  else
  {
    if ((direction | 2) == 0xA)
    {
      sub_854710(&dst, 0);
      sub_854930(&v36, 0);
      sub_854930(&v36, 1u);
      sub_854710(&dst, 2u);
    }
    else
    {
      sub_854930(&p, 0);
      sub_854930(&p, 1u);
      sub_854930(&p, 2u);
      SDF_VU0__LOADVECTOR(pParams->rot);
      ToMatrix();
      v29 = effEveBED_Ptr_D->m_Items[direction];
      SetRotateMatrixY_B(v29);
      MultMatrixNoArg();
      SDF_VU0__LOADVECTOR(p);
      SDF_VU0__VECTOR_W_SET_ZERO();
      SDF_VU0__APPLYMATRIX();
      SDF_VU0__STOREVECTOR(&p);
      sub_854710(&dst, 0);
      sub_854710(&p, 0);
      sub_854930(&v36, 0);
      sub_854710(&p, 1u);
      sub_854930(&v36, 1u);
      sub_854710(&dst, 2u);
      sub_854710(&p, 2u);
    }
    sub_854930(&v36, 2u);
    SDF_VU0__LOADVECTOR(v36);
  }
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
  effSimpleBED_t_o *v5;
  effBTL_t_o *v7;
  effEveBEDParams_t_o *pParams;

  v5 = Allocate(effSimpleBED_t);
  effSimpleBED_t___ctor(v5);
  sub_854930(&v5->pParams->rot, 0);
  sub_854930(&v5->pParams->rot, 1u);
  sub_854930(&v5->pParams->rot, 2u);
  sub_854930(&v5->pParams->rot, 3u);
  v5->pParams->r = 50.0;
  v5->pParams->h = 180.0;
  sub_854930(&v5->pParams->fields, 0);
  sub_854930(&v5->pParams->fields, 1u);
  sub_854930(&v5->pParams->fields, 2u);
  sub_854930(&v5->pParams->fields, 3u);
  v5->pParams->scale = scale;
  v5->pParams->abgr = -2139062144;
LABEL_7:
  v7 = effBTLCreate(pData);
  pParams = v5->pParams;
  v5->hBED = v7;
  v5->hCut = effEveBEDCutCreate(v7, 0, pParams);
  v5->original = 1;
  return v5;
}

// 0x138fe30
void effSimpleBEDDelete(effSimpleBED_t *hSimpleBED) {
  struct effEveBEDCutHandle_t_o *hCut;
  effBTLCutHandle_t_o **p_hBTLCutEffect;
  effBTL_t_o *hBED;
  effBTL_t_o *hBTLEffect;

  hCut = hSimpleBED->hCut;
LABEL_7:
  p_hBTLCutEffect = &hCut->hBTLCutEffect;
  effBTLCutDelete(p_hBTLCutEffect);
  if (hSimpleBED->original)
  {
    hBED = hSimpleBED->hBED;
    else
    {
      hBTLEffect = hBED;
      if ((byte_3F5959B & 1) != 0)
        goto LABEL_18;
    }
    goto LABEL_18;
  }
LABEL_22:
}

// 0x1390080
void effSimpleBEDDraw(effSimpleBED_t *hSimpleBED) {
  struct effEveBEDCutHandle_t_o **p_hCut;
  effEveBEDCutHandle_t_o **v4;

  p_hCut = &hSimpleBED->hCut;
  else
  {
    v4 = p_hCut;
  }
  effEveBEDCutDraw(v4);
}

// 0x1390100
void effSimpleBEDSetPosition(effSimpleBED_t *hSimpleBED, sdfVector4_t pPos) {
  effEveBEDParams_t_Fields *p_fields;
  effEveBEDParams_t_Fields *v5;
  effEveBEDParams_t_Fields *v6;
  struct effEveBEDParams_t_o *pParams;
  UnityEngine_Vector4_o v9;

  v9 = pPos;
  p_fields = &hSimpleBED->pParams->fields;
  sub_854710(&v9, 0);
  sub_854930(p_fields, 0);
  v5 = &hSimpleBED->pParams->fields;
  sub_854710(&v9, 1u);
  sub_854930(v5, 1u);
  v6 = &hSimpleBED->pParams->fields;
  sub_854710(&v9, 2u);
  sub_854930(v6, 2u);
  sub_854930(&hSimpleBED->pParams->fields, 3u);
  pParams = hSimpleBED->pParams;
  hSimpleBED->hCut->pParams = pParams;
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
  s32 v3;

  v3 = 0;
  return sub_8D3950(s32, &v3);
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
