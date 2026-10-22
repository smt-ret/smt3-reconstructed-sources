#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct EffectHD EffectHD;
typedef struct SOBED_PB_LIST SOBED_PB_LIST;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3EffectPCPData_Part_t dds3EffectPCPData_Part_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3SpPoly_RollRing_t3 dds3SpPoly_RollRing_t3;
typedef struct effBTLCutHandle_t effBTLCutHandle_t;
typedef struct effBTLSysHandle_t effBTLSysHandle_t;
typedef struct effBTL_SkillLight_t effBTL_SkillLight_t;
typedef struct effBTL_SkillModel_t effBTL_SkillModel_t;
typedef struct effBTL_SkillPositionPtr_t effBTL_SkillPositionPtr_t;
typedef struct effBTL_t effBTL_t;
typedef struct effBattleSystem_effBTLSystem_AttackC_tag effBattleSystem_effBTLSystem_AttackC_tag;
typedef struct effBattleSystem_effBTLSystem_Attack_tag effBattleSystem_effBTLSystem_Attack_tag;
typedef struct effBattleSystem_effBTLSystem_Bind_tag effBattleSystem_effBTLSystem_Bind_tag;
typedef struct effBattleSystem_effBTLSystem_Charm_tag effBattleSystem_effBTLSystem_Charm_tag;
typedef struct effBattleSystem_effBTLSystem_Close_tag effBattleSystem_effBTLSystem_Close_tag;
typedef struct effBattleSystem_effBTLSystem_CurseCAMP_tag effBattleSystem_effBTLSystem_CurseCAMP_tag;
typedef struct effBattleSystem_effBTLSystem_Curse_tag effBattleSystem_effBTLSystem_Curse_tag;
typedef struct effBattleSystem_effBTLSystem_Cut1_tag effBattleSystem_effBTLSystem_Cut1_tag;
typedef struct effBattleSystem_effBTLSystem_Encount_tag effBattleSystem_effBTLSystem_Encount_tag;
typedef struct effBattleSystem_effBTLSystem_Fly_tag effBattleSystem_effBTLSystem_Fly_tag;
typedef struct effBattleSystem_effBTLSystem_Freeze_tag effBattleSystem_effBTLSystem_Freeze_tag;
typedef struct effBattleSystem_effBTLSystem_FuncTable_tag effBattleSystem_effBTLSystem_FuncTable_tag;
typedef struct effBattleSystem_effBTLSystem_FuncTable_tag_CreateDelegate effBattleSystem_effBTLSystem_FuncTable_tag_CreateDelegate;
typedef struct effBattleSystem_effBTLSystem_FuncTable_tag_DataFreeDelegate effBattleSystem_effBTLSystem_FuncTable_tag_DataFreeDelegate;
typedef struct effBattleSystem_effBTLSystem_FuncTable_tag_DataLoadDelegate effBattleSystem_effBTLSystem_FuncTable_tag_DataLoadDelegate;
typedef struct effBattleSystem_effBTLSystem_FuncTable_tag_Delete2Delegate effBattleSystem_effBTLSystem_FuncTable_tag_Delete2Delegate;
typedef struct effBattleSystem_effBTLSystem_FuncTable_tag_DeleteDelegate effBattleSystem_effBTLSystem_FuncTable_tag_DeleteDelegate;
typedef struct effBattleSystem_effBTLSystem_FuncTable_tag_DrawDelegate effBattleSystem_effBTLSystem_FuncTable_tag_DrawDelegate;
typedef struct effBattleSystem_effBTLSystem_FuncTable_tag_GetLengthDelegate effBattleSystem_effBTLSystem_FuncTable_tag_GetLengthDelegate;
typedef struct effBattleSystem_effBTLSystem_FuncTable_tag_PartHandleCreateDelegate effBattleSystem_effBTLSystem_FuncTable_tag_PartHandleCreateDelegate;
typedef struct effBattleSystem_effBTLSystem_FuncTable_tag_PartHandleDeleteDelegate effBattleSystem_effBTLSystem_FuncTable_tag_PartHandleDeleteDelegate;
typedef struct effBattleSystem_effBTLSystem_FuncTable_tag_SetColorDelegate effBattleSystem_effBTLSystem_FuncTable_tag_SetColorDelegate;
typedef struct effBattleSystem_effBTLSystem_Hansya_tag effBattleSystem_effBTLSystem_Hansya_tag;
typedef struct effBattleSystem_effBTLSystem_Kyusyuu_tag effBattleSystem_effBTLSystem_Kyusyuu_tag;
typedef struct effBattleSystem_effBTLSystem_Nego_Kaihuku_tag effBattleSystem_effBTLSystem_Nego_Kaihuku_tag;
typedef struct effBattleSystem_effBTLSystem_Nego_Kyusyu_tag effBattleSystem_effBTLSystem_Nego_Kyusyu_tag;
typedef struct effBattleSystem_effBTLSystem_Nego_Stone_tag effBattleSystem_effBTLSystem_Nego_Stone_tag;
typedef struct effBattleSystem_effBTLSystem_PacInfo_tag effBattleSystem_effBTLSystem_PacInfo_tag;
typedef struct effBattleSystem_effBTLSystem_Panic_tag effBattleSystem_effBTLSystem_Panic_tag;
typedef struct effBattleSystem_effBTLSystem_Paralyze_tag effBattleSystem_effBTLSystem_Paralyze_tag;
typedef struct effBattleSystem_effBTLSystem_Part_tag effBattleSystem_effBTLSystem_Part_tag;
typedef struct effBattleSystem_effBTLSystem_Poison_tag effBattleSystem_effBTLSystem_Poison_tag;
typedef struct effBattleSystem_effBTLSystem_Return_tag effBattleSystem_effBTLSystem_Return_tag;
typedef struct effBattleSystem_effBTLSystem_Shock_tag effBattleSystem_effBTLSystem_Shock_tag;
typedef struct effBattleSystem_effBTLSystem_Sleep_tag effBattleSystem_effBTLSystem_Sleep_tag;
typedef struct effBattleSystem_effBTLSystem_Stone_Dead_tag effBattleSystem_effBTLSystem_Stone_Dead_tag;
typedef struct effBattleSystem_effBTLSystem_Stone_tag effBattleSystem_effBTLSystem_Stone_tag;
typedef struct effBattleSystem_effBTLSystem_tag effBattleSystem_effBTLSystem_tag;
typedef struct effBattleSystem_effCAMPBad_tag effBattleSystem_effCAMPBad_tag;
typedef struct effCAMPBadParams_t effCAMPBadParams_t;
typedef struct effPCPThunderSpherePolyLow_t effPCPThunderSpherePolyLow_t;
typedef struct effPCPThunderSpherePolyParam_t effPCPThunderSpherePolyParam_t;
typedef struct effPartHandle_t effPartHandle_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct sdf3DLightParallelPacket_t sdf3DLightParallelPacket_t;
typedef struct sdf3DLight_t sdf3DLight_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfModelOt_t sdfModelOt_t;

struct effBattleSystem_effCAMPBad_tag {
    nbFormation_t *Formation;
    effCAMPBadParams_t *params;
    effBTLSysHandle_t *hEffBTLSys;
    u32 id;
    s32 frame;
};

struct effBattleSystem_effBTLSystem_Part_tag {
    u16 type;
    char *pFilename;
    u8 *pData;
    char *pFilenamePF;
    void *oData;
    u16 use;
    effPartHandle_t *hPart;
    effBTL_t *hBED;
    sdfMemHandle_t *hMem;
    char *pTganame;
    void *pTexture;
};

struct effBattleSystem_effBTLSystem_FuncTable_tag {
    effBattleSystem_effBTLSystem_FuncTable_tag_CreateDelegate *Create;
    effBattleSystem_effBTLSystem_FuncTable_tag_DeleteDelegate *Delete;
    effBattleSystem_effBTLSystem_FuncTable_tag_Delete2Delegate *Delete2;
    effBattleSystem_effBTLSystem_FuncTable_tag_SetColorDelegate *SetColor;
    effBattleSystem_effBTLSystem_FuncTable_tag_DrawDelegate *Draw;
    effBattleSystem_effBTLSystem_FuncTable_tag_GetLengthDelegate *GetLength;
    effBattleSystem_effBTLSystem_FuncTable_tag_DataLoadDelegate *DataLoad;
    effBattleSystem_effBTLSystem_FuncTable_tag_DataFreeDelegate *DataFree;
    effBattleSystem_effBTLSystem_FuncTable_tag_PartHandleCreateDelegate *PartHandleCreate;
    effBattleSystem_effBTLSystem_FuncTable_tag_PartHandleDeleteDelegate *PartHandleDelete;
    u32 model_color;
    s32 battle;
    u32 PartNumber;
    effBattleSystem_effBTLSystem_Part_tag *pPartList;
};

struct effBattleSystem_effBTLSystem_Cut1_tag {
    char *pFilename;
    effBTL_t *hBTLEffect;
    u32 use;
    u8 *pData;
    sdfMemHandle_t *hMem;
    char *tex_fname;
    void *pTexture;
};

struct effBattleSystem_effBTLSystem_PacInfo_tag {
    dds3EffectPCPData_Part_t *PCPPart;
    u32 space;
    void *pData;
    sdfMemHandle_t *hMem;
};

struct effBattleSystem_effBTLSystem_Shock_tag {
    nbFormation_t *pFormation;
    u32 frame;
    effPCPThunderSpherePolyLow_t *pThunderSpherePoly;
};

struct effBattleSystem_effBTLSystem_Freeze_tag {
    nbFormation_t *pFormation;
    u32 frame;
    effPartHandle_t *hPartD3P;
};

struct effBattleSystem_effBTLSystem_Sleep_tag {
    nbFormation_t *pFormation;
    u32 frame;
    effPartHandle_t *hPartD3P;
};

struct effBattleSystem_effBTLSystem_Panic_tag {
    nbFormation_t *pFormation;
    u32 frame;
    effPartHandle_t *hPartD3P;
};

struct effBattleSystem_effBTLSystem_Bind_tag {
    nbFormation_t *pFormation;
    u32 frame;
    effPCPThunderSpherePolyLow_t *pThunderSpherePoly;
};

struct effBattleSystem_effBTLSystem_Close_tag {
    nbFormation_t *pFormation;
    u32 frame;
    effPartHandle_t *hPartD3P0;
    effPartHandle_t *hPartD3P1;
    dds3ModelHandle_t *hModel;
};

struct effBattleSystem_effBTLSystem_Poison_tag {
    nbFormation_t *pFormation;
    u32 frame;
    effPartHandle_t *hPartD3P;
    dds3ModelHandle_t *hModel;
};

struct effBattleSystem_effBTLSystem_Charm_tag {
    nbFormation_t *pFormation;
    u32 frame;
    effPartHandle_t *hSmoke;
    effPartHandle_t *hHeart;
};

struct effBattleSystem_effBTLSystem_Paralyze_tag {
    nbFormation_t *pFormation;
    u32 frame;
    effPCPThunderSpherePolyLow_t *pThunderSpherePoly;
};

struct effBattleSystem_effBTLSystem_Fly_tag {
    nbFormation_t *pFormation;
    u32 frame;
};

struct effBattleSystem_effBTLSystem_Stone_tag {
    nbFormation_t *pFormation;
    u32 frame;
};

struct effBattleSystem_effBTLSystem_Curse_tag {
    nbFormation_t *pFormation;
    u32 frame;
    effPartHandle_t *hPartD3P;
};

struct effBattleSystem_effBTLSystem_CurseCAMP_tag {
    nbFormation_t *pFormation;
    u32 frame;
    effPartHandle_t *hPartD3P0;
    effPartHandle_t *hPartD3P1;
};

struct effBattleSystem_effBTLSystem_Stone_Dead_tag {
    nbFormation_t *pFormation;
    u32 frame;
    effPartHandle_t *hPartPB;
    effPartHandle_t *hPartD3P1;
    effPartHandle_t *hPartD3P2;
};

struct effBattleSystem_effBTLSystem_Hansya_tag {
    sdf3DLightParallelPacket_t *LightPacket;
    nbFormation_t *pFormation;
    u32 frame;
    effPartHandle_t *hPartPB;
    effPartHandle_t *hPartPCF;
};

struct effBattleSystem_effBTLSystem_Kyusyuu_tag {
    nbFormation_t *pFormation;
    u32 frame;
    effPartHandle_t *hRing[3];
    effPartHandle_t *hBlur;
};

struct effBattleSystem_effBTLSystem_Return_tag {
    nbFormation_t *pFormation;
    u32 frame;
    effBTLCutHandle_t *hBEDCut;
};

struct effBattleSystem_effBTLSystem_Attack_tag {
    nbFormation_t *pFormation;
    u32 frame;
    effPartHandle_t *hMainD3P;
    effPartHandle_t *hFlash1PCF;
    effPartHandle_t *hFlash2PCF;
    effPartHandle_t *hFlash3PCF;
    effPartHandle_t *hSmoke1D3P;
    effPartHandle_t *hSmoke2D3P;
};

struct effBattleSystem_effBTLSystem_AttackC_tag {
    nbFormation_t *pFormation;
    u32 frame;
    effPartHandle_t *hMainD3P;
    effPartHandle_t *hFlash1PCF;
    effPartHandle_t *hFlash2PCF;
    effPartHandle_t *hFlash3PCF;
    effPartHandle_t *hSmoke1D3P;
    effPartHandle_t *hSmoke2D3P;
    effPartHandle_t *hFlash4PCF;
    effPartHandle_t *hFilterPCF;
    effPartHandle_t *hRing1PCF;
    effPartHandle_t *hRing2PCF;
    effPartHandle_t *hRing3PCF;
    effPartHandle_t *hRing4PCF;
};

struct effBattleSystem_effBTLSystem_Encount_tag {
    nbFormation_t *pFormation;
    u32 frame;
    effBTLCutHandle_t *hBEDCut;
};

struct effBattleSystem_effBTLSystem_Nego_Kaihuku_tag {
    nbFormation_t *pFormation;
    u32 frame;
    effBTLCutHandle_t *hBEDCut;
};

struct effBattleSystem_effBTLSystem_Nego_Kyusyu_tag {
    nbFormation_t *pFormation;
    u32 frame;
    effBTLCutHandle_t *hBEDCut;
};

struct effBattleSystem_effBTLSystem_Nego_Stone_tag {
    nbFormation_t *pFormation;
    u32 frame;
    effBTLCutHandle_t *hBEDCut;
};

struct effBattleSystem_effBTLSystem_tag {
    u32 id;
    void *pHandle;
    nbFormation_t *pFormation;
};

static sdfModelOt_t *dds3ModelOt[11];
static u8 effBTLSystemFilePac_spaceBuff[16];
static effPCPThunderSpherePolyParam_t *effBTLSystem_Shock_ThunderSpherePolyLowParam;
static effBattleSystem_effBTLSystem_Part_tag *effBTLSystem_Shock_PartList;
static effBattleSystem_effBTLSystem_Part_tag *effBTLSystem_Freeze_PartList[1];
static effBattleSystem_effBTLSystem_Part_tag *effBTLSystem_Sleep_PartList[1];
static effBattleSystem_effBTLSystem_Part_tag *effBTLSystem_Panic_PartList[1];
static effPCPThunderSpherePolyParam_t *effBTLSystem_Bind_ThunderSpherePolyLowParam;
static effBattleSystem_effBTLSystem_Part_tag *effBTLSystem_Bind_PartList[1];
static effBattleSystem_effBTLSystem_Part_tag *effBTLSystem_Close_PartList[2];
static effBattleSystem_effBTLSystem_Part_tag *effBTLSystem_Poison_PartList[1];
static effBattleSystem_effBTLSystem_Part_tag *effBTLSystem_Charm_PartList[2];
static effPCPThunderSpherePolyParam_t *effBTLSystem_Paralyze_ThunderSpherePolyLowParam;
static effBattleSystem_effBTLSystem_Part_tag *effBTLSystem_Paralyze_PartList[1];
static effBattleSystem_effBTLSystem_Part_tag *effBTLSystem_Fly_PartList[1];
static effBattleSystem_effBTLSystem_Part_tag *effBTLSystem_Stone_PartList[1];
static effBattleSystem_effBTLSystem_Part_tag *effBTLSystem_Curse_PartList[1];
static effBattleSystem_effBTLSystem_Part_tag *effBTLSystem_CurseCAMP_PartList[2];
static effBattleSystem_effBTLSystem_Part_tag *effBTLSystem_Stone_Dead_PartList[3];
static effBattleSystem_effBTLSystem_Part_tag *effBTLSystem_Hansya_PartList[3];
static effBattleSystem_effBTLSystem_Part_tag *effBTLSystem_Kyusyuu_PartList[2];
static effBattleSystem_effBTLSystem_Part_tag *effBTLSystem_Return_PartList[1];
static effBattleSystem_effBTLSystem_Part_tag *effBTLSystem_Attack_PartList[6];
static effBattleSystem_effBTLSystem_Part_tag *effBTLSystem_AttackC_PartList[6];
static effBattleSystem_effBTLSystem_Part_tag *effBTLSystem_Encount_PartList[1];
static effBattleSystem_effBTLSystem_Part_tag *effBTLSystem_Nego_Kaihuku_PartList[1];
static effBattleSystem_effBTLSystem_Part_tag *effBTLSystem_Nego_Kyusyu_PartList[1];
static effBattleSystem_effBTLSystem_Part_tag *effBTLSystem_Nego_Stone_PartList[1];
static u32 EFFBTL_SYSTEM_SHOCK_COLOR;
static u32 EFFBTL_SYSTEM_FREEZE_COLOR;
static u32 EFFBTL_SYSTEM_SLEEP_COLOR;
static u32 EFFBTL_SYSTEM_PANIC_COLOR;
static u32 EFFBTL_SYSTEM_BIND_COLOR;
static u32 EFFBTL_SYSTEM_CLOSE_COLOR;
static u32 EFFBTL_SYSTEM_POISON_COLOR;
static u32 EFFBTL_SYSTEM_CHARM_COLOR;
static u32 EFFBTL_SYSTEM_PARALYZE_COLOR;
static u32 EFFBTL_SYSTEM_FLY_COLOR;
static u32 EFFBTL_SYSTEM_HANSYA_COLOR;
static u32 EFFBTL_SYSTEM_KYUSYUU_COLOR;
static effBattleSystem_effBTLSystem_FuncTable_tag *effBTLSystemFuncTable[30];
static effBattleSystem_effBTLSystem_Cut1_tag *effBTLSystemCut1Data[25];
static u32 BTLDebugHatudouEffectCount;
static effBTL_t *hBTLDebugHatudouEffect;
static bool initflg;

void *LoadFileObject(AssetBundleCtrl *this, char *key, char *path_name);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
void MarkTmxIndex(u8 ***bData);
void Mult(void);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__APPLYMATRIX(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__SCALEVECTOR(f32 v);
void SDF_VU0__STOREMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SetPbList(SOBED_PB_LIST *gList);
void SethFrom(EffectHD *this, nbFormation_t *sFrom);
void ToMatrix(void);
void billClrTexture(bool allclear);
void billSetTexture(void **pTexture);
effPartHandle_t *dds3EffectPartCopy(effPartHandle_t **hEffPartSrc);
effPartHandle_t *dds3EffectPartCreate(u16 type, void *pData);
void dds3EffectPartDelete(effPartHandle_t **hEffPart);
void dds3EffectPartDraw(effPartHandle_t **hEffPart);
dds3ModelHandle_t *dds3EffectPartGetHandle(effPartHandle_t *hEffPart);
void dds3EffectPartModelDraw(void **hData);
void dds3EffectPartSetColor(effPartHandle_t **hEffPart, u32 abgr);
void dds3EffectPartSetDirection(effPartHandle_t **hEffPart, sdfMatrix4_t *pMatrix);
void dds3EffectPartSetPosition(effPartHandle_t **hEffPart, sdfVector4_t pPos);
void dds3EffectPartSetRotateMatrix(effPartHandle_t **hEffPart, sdfMatrix4_t *pMatrix);
void dds3EffectPartSetScale(effPartHandle_t **hEffPart, f32 scale);
void dds3SetQuake(s32 frame, u32 range);
void dds3SpPoly_RollRingSetEndless(dds3SpPoly_RollRing_t3 **pRollRing);
effBTL_t *effBTLCreate(u8 **pData);
effBTLCutHandle_t *effBTLCutCreate(effBTL_t **hBTLEffect, u16 CutNum, nbFormation_t *pFormation, u32 stat);
void effBTLCutDelete(effBTLCutHandle_t **hBTLCutEffect);
void effBTLCutDraw(effBTLCutHandle_t **hBTLCutEffect);
u32 effBTLCutGetCutEndFrame(effBTLCutHandle_t **hBTLCutEffect);
void *effBTLCutGetUserData(effBTLCutHandle_t **hBTLCutEffect);
void effBTLCutSetUserData(effBTLCutHandle_t **hBTLCutEffect, void *pData);
void effBTLDelete(effBTL_t **hBTLEffect);
void effBTLModelColorSet(effBTL_SkillModel_t **pModel, nbFormation_t **pFormation);
void effBTLModelGetMarkPosition2(nbFormation_t **pFormation, u32 mark);
void effBTLPartGetPositionPtr(nbFormation_t **pFormation, effBTL_SkillPositionPtr_t **pPosPtr, sdfVector4_t *pPos);
void effBTLPartGetRotateMatrixPtr(effBTL_SkillPositionPtr_t **pPosPtr, sdfMatrix4_t *pMatrix);
f32 effBTLPartGetScalePtr(nbFormation_t **pFormation);
void effBTLPointLightCompulsionOFF(void);
void effBTLPointLightSet(effBTL_SkillLight_t **pLight, nbFormation_t **pFormation);
void effBTLSkillEnd(void);
u32 effBTLSkillGetID(void);
nbFormation_t *effBTLSkillGetInvokeFormation(s32 idx);
nbFormation_t *effBTLSkillGetTargetFormation(u32 number);
void effBTLSkillStart(u32 id, u32 stat);
effBTLSysHandle_t *effBTLSystemCreate(nbFormation_t **pFormation, u32 id);
void effBTLSystemCut1DataFree(void);
void effBTLSystemCut1DataLoad(void);
void effBTLSystemCut1PartHandleDelete(void);
void effBTLSystemDelete(effBTLSysHandle_t **hEffBTLSys);
f32 effBTLSystem_GetScalePtr(nbFormation_t **pFormation);
void effBTLSystem_Part_DataFree(effBattleSystem_effBTLSystem_Part_tag ***pPartList, u32 count);
void effBTLSystem_Part_DataLoad(effBattleSystem_effBTLSystem_Part_tag ***pPartList, u32 count);
void effBTLSystem_Part_HandleCreate(effBattleSystem_effBTLSystem_Part_tag ***pPartList, u32 count);
void effBTLSystem_Part_HandleDelete(effBattleSystem_effBTLSystem_Part_tag ***pPartList, u32 count);
void effBTL_SkillLight_t__Clear(effBTL_SkillLight_t *this);
void effBTL_SkillModel_t__Clear(effBTL_SkillModel_t *this);
void effCAMPBadMatRGB(effBattleSystem_effCAMPBad_tag **hCAMPBadEffect, u32 color);
u32 effColorBlend(u32 abgr0, u32 abgr1, f32 rate);
effPCPThunderSpherePolyLow_t *effPCPThunderSpherePolyLowCreate(effPCPThunderSpherePolyParam_t *pParam);
void effPCPThunderSpherePolyLowDelete(void **hData);
void effPCPThunderSpherePolyLowDraw(void **hData);
effPCPThunderSpherePolyParam_t *effPCPThunderSpherePolyLowGetParam(effPCPThunderSpherePolyLow_t *pThunderPoly);
void effPCPThunderSpherePolyLowSetColor(void **hData, u32 abgr);
void effPCPThunderSpherePolyLowSetPosition(void **hData, sdfVector4_t pPos);
void effPCPThunderSpherePolyLowSetScale(void **hData, f32 scale);
void evtSetUnitColorRGB(evtUnitHandle_t **h, u32 frame, u32 rgb);
u32 mdlGetColor(dds3ModelHandle_t **aHandle);
void mdlHideEffect(dds3ModelHandle_t **HNDL);
void mdlSetColor(dds3ModelHandle_t **aHandle, u32 aColor);
void mdlSetLightUnity(dds3ModelHandle_t **HNDL, sdf3DLight_t **uLight, sdfVector4_t uAmbient);
void mdlShowEffect(dds3ModelHandle_t **HNDL);
void nbGetFormForward(nbFormation_t *form);
datUnitWork_t *nbGetUnitWorkFromFormindex(s32 formindex);
void *sdfDevLoadFileUnity_25061072(char *aFilename, u8 ***aTopPtr, s32 aSizePtr, char *akey);

// 0x14c4be0
u32 DDS3EFFECT_RGBA(u32 r, u32 g, u32 b, u32 a) {
  return r | (g << 8) | (b << 16) | (a << 24);
}

// 0x14d6f40
void effBTLEncountEnd(void) {
  else
  {
    effBTLSkillEnd();
  }
}

// 0x14d6ed0
void effBTLEncountStart(void) {
  effBTLSkillStart(0x200u, 0);
}

// 0x14d2010
effBattleSystem_effBTLSystem_AttackC_tag *effBTLSys_AttackC_Create(nbFormation_t *pFormation) {
  effBattleSystem_effBTLSystem_AttackC_tag_o *v3;
  struct effBattleSystem_effBTLSystem_Part_tag_array *effBTLSystem_Attack_PartList;
  effPartHandle_t_o **p_hPart;
  struct effBattleSystem_effBTLSystem_Part_tag_array *v8;
  struct effBattleSystem_effBTLSystem_Part_tag_array *v10;
  struct effBattleSystem_effBTLSystem_Part_tag_array *v12;
  struct effBattleSystem_effBTLSystem_Part_tag_array *v14;
  struct effBattleSystem_effBTLSystem_Part_tag_array *v16;
  struct effBattleSystem_effBTLSystem_Part_tag_array *effBTLSystem_AttackC_PartList;
  struct effBattleSystem_effBTLSystem_Part_tag_array *v20;
  struct effBattleSystem_effBTLSystem_Part_tag_array *v22;
  struct effBattleSystem_effBTLSystem_Part_tag_array *v24;
  struct effBattleSystem_effBTLSystem_Part_tag_array *v26;
  struct effBattleSystem_effBTLSystem_Part_tag_array *v28;

  v3 = Allocate(effBattleSystem_effBTLSystem_AttackC_tag);
  _ctor(v3, 0);
  v3->pFormation = pFormation;
  v3->frame = 0;
  else
  {
    if (!LODWORD(effBTLSystem_Attack_PartList->max_length))
      goto LABEL_6;
  }
  p_hPart = &effBTLSystem_Attack_PartList->m_Items[0]->hPart;
  v3->hMainD3P = dds3EffectPartCopy(p_hPart, 0, 0);
  v8 = effBTLSystem_Attack_PartList;
  v3->hFlash1PCF = dds3EffectPartCopy(&v8->m_Items[1]->hPart, 0, 0);
  v10 = effBTLSystem_Attack_PartList;
  v3->hFlash2PCF = dds3EffectPartCopy(&v10->m_Items[2]->hPart, 0, 0);
  v12 = effBTLSystem_Attack_PartList;
  v3->hFlash3PCF = dds3EffectPartCopy(&v12->m_Items[3]->hPart, 0, 0);
  v14 = effBTLSystem_Attack_PartList;
  v3->hSmoke1D3P = dds3EffectPartCopy(&v14->m_Items[4]->hPart, 0, 0);
  v16 = effBTLSystem_Attack_PartList;
  v3->hSmoke2D3P = dds3EffectPartCopy(&v16->m_Items[5]->hPart, 0, 0);
  v3->hFlash4PCF = dds3EffectPartCopy(&effBTLSystem_AttackC_PartList->m_Items[0]->hPart, 0, 0);
  v20 = effBTLSystem_AttackC_PartList;
  v3->hFilterPCF = dds3EffectPartCopy(&v20->m_Items[1]->hPart, 0, 0);
  v22 = effBTLSystem_AttackC_PartList;
  v3->hRing1PCF = dds3EffectPartCopy(&v22->m_Items[2]->hPart, 0, 0);
  v24 = effBTLSystem_AttackC_PartList;
  v3->hRing2PCF = dds3EffectPartCopy(&v24->m_Items[3]->hPart, 0, 0);
  v26 = effBTLSystem_AttackC_PartList;
  v3->hRing3PCF = dds3EffectPartCopy(&v26->m_Items[4]->hPart, 0, 0);
  v28 = effBTLSystem_AttackC_PartList;
  v3->hRing4PCF = dds3EffectPartCopy(&v28->m_Items[5]->hPart, 0, 0);
  return v3;
}

// 0x14d3970
void effBTLSys_AttackC_DataFree(void) {
  effBTLSystem_Part_DataFree(&effBTLSystem_AttackC_PartList, effBTLSystem_AttackC_PartList->max_length);
}

// 0x14d3900
void effBTLSys_AttackC_DataLoad(void) {
  effBTLSystem_Part_DataLoad(&effBTLSystem_AttackC_PartList, effBTLSystem_AttackC_PartList->max_length);
}

// 0x14d23d0
void effBTLSys_AttackC_Delete(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  u64 v8[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_AttackC_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_AttackC_tag, v8);
      if ((v8[0] & 1) != 0)
        v5 = v8[2];
      else
        v5 = v8 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  dds3EffectPartDelete(&hData[7].monitor);
  dds3EffectPartDelete(&hData[7]);
  dds3EffectPartDelete(&hData[6].monitor);
  dds3EffectPartDelete(&hData[6]);
  dds3EffectPartDelete(&hData[5].monitor);
  dds3EffectPartDelete(&hData[5]);
  dds3EffectPartDelete(&hData[4].monitor);
  dds3EffectPartDelete(&hData[4]);
  dds3EffectPartDelete(&hData[3].monitor);
  dds3EffectPartDelete(&hData[3]);
  dds3EffectPartDelete(&hData[2].monitor);
  dds3EffectPartDelete(&hData[2]);
}

// 0x14d25b0
void effBTLSys_AttackC_Delete2(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  u64 v8[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_AttackC_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_AttackC_tag, v8);
      if ((v8[0] & 1) != 0)
        v5 = v8[2];
      else
        v5 = v8 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  dds3EffectPartDelete(&hData[7].monitor);
  dds3EffectPartDelete(&hData[7]);
  dds3EffectPartDelete(&hData[6].monitor);
  dds3EffectPartDelete(&hData[6]);
  dds3EffectPartDelete(&hData[5].monitor);
  dds3EffectPartDelete(&hData[5]);
  dds3EffectPartDelete(&hData[4].monitor);
  dds3EffectPartDelete(&hData[4]);
  dds3EffectPartDelete(&hData[3].monitor);
  dds3EffectPartDelete(&hData[3]);
  dds3EffectPartDelete(&hData[2].monitor);
  dds3EffectPartDelete(&hData[2]);
}

// 0x14d27d0
void effBTLSys_AttackC_Draw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  effBTL_SkillModel_t_o *v9;
  u64 *v10;
  s64 v12;
  s64 v13;
  nbFormation_t_o *TargetFormation;
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;
  u32 v20;
  effBTL_SkillPositionPtr_t_o *v27;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  effBTL_SkillPositionPtr_t_o *v34;
  effBTL_SkillPositionPtr_t_o *v37;
  effBTL_SkillPositionPtr_t_o *v40;
  effBTL_SkillPositionPtr_t_o *v43;
  effBTL_SkillPositionPtr_t_o *v48;
  f32 v50;
  f32 v51;
  f32 v52;
  f32 v53;
  effBTL_SkillPositionPtr_t_o *v55;
  f32 v57;
  f32 v58;
  f32 v59;
  f32 v60;
  effBTL_SkillPositionPtr_t_o *v62;
  effBTL_SkillPositionPtr_t_o *v65;
  effBTL_SkillPositionPtr_t_o *v70;
  f32 v72;
  f32 v73;
  f32 v74;
  f32 v75;
  effBTL_SkillPositionPtr_t_o *v77;
  f32 v79;
  f32 v80;
  f32 v81;
  f32 v82;
  effBTL_SkillPositionPtr_t_o *v84;
  f32 v86;
  f32 v87;
  f32 v88;
  f32 v89;
  UnityEngine_Matrix4x4_o v91;
  UnityEngine_Matrix4x4_o v92;
  UnityEngine_Matrix4x4_o v93;
  UnityEngine_Matrix4x4_o v94;
  UnityEngine_Matrix4x4_o v95;
  UnityEngine_Matrix4x4_o v96;
  UnityEngine_Matrix4x4_o v97;
  UnityEngine_Matrix4x4_o v98;
  UnityEngine_Matrix4x4_o v99;
  UnityEngine_Matrix4x4_o v100;
  UnityEngine_Matrix4x4_o v101;
  UnityEngine_Matrix4x4_o v102;
  UnityEngine_Matrix4x4_o v103;
  UnityEngine_Matrix4x4_o v104;
  UnityEngine_Matrix4x4_o v105;
  UnityEngine_Matrix4x4_o v106;
  UnityEngine_Matrix4x4_o v107;
  UnityEngine_Matrix4x4_o v108;
  UnityEngine_Matrix4x4_o v109;
  UnityEngine_Matrix4x4_o v110;
  UnityEngine_Matrix4x4_o v111;
  UnityEngine_Matrix4x4_o v112;
  UnityEngine_Matrix4x4_o v113;
  UnityEngine_Matrix4x4_o v114;
  UnityEngine_Matrix4x4_o pMatrix;
  UnityEngine_Matrix4x4_o aMatrix;
  UnityEngine_Vector4_o pPos;
  effBTL_SkillPositionPtr_t_o *pPosPtr;
  effBTL_SkillModel_t_o *pModel;
  effBTL_SkillLight_t_o *pLight;
  nbFormation_t_o *v121;
  s64 v122;
  s64 v123;
  char *v124;
  nbFormation_t_o *pFormation;
  UnityEngine_Vector4_o v126;
  UnityEngine_Vector4_o v127;
  UnityEngine_Vector4_o v128;
  UnityEngine_Vector4_o v129;
  UnityEngine_Vector4_o v130;
  UnityEngine_Vector4_o v131;
  UnityEngine_Vector4_o v132;

  pFormation = 0;
  pLight = 0;
  v121 = 0;
  memset(&pMatrix, 0, sizeof(pMatrix));
  pPosPtr = 0;
  pModel = 0;
  *&pPos.x = 0;
  *&pPos.z = 0;
  memset(&aMatrix, 0, sizeof(aMatrix));
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_AttackC_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_AttackC_tag, &v122);
      if ((v122 & 1) != 0)
        v6 = v124;
      else
        v6 = &v122 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v122 = 0;
  v123 = 0;
  sub_854690(&v122, 0.0, 1.0, 0.0, 0.0);
  v8 = Allocate(effBTL_SkillLight_t);
  effBTL_SkillLight_t___ctor(v8);
  pLight = v8;
  effBTL_SkillLight_t__Clear(v8);
  v9 = Allocate(effBTL_SkillModel_t);
  effBTL_SkillModel_t___ctor(v9);
  pModel = v9;
  effBTL_SkillModel_t__Clear(v9);
  v10 = Allocate(effBTL_SkillPositionPtr_t);
  effBTL_SkillPositionPtr_t___ctor(v10);
  *&pPos.z = 0;
  pPosPtr = v10;
  memset(&aMatrix, 0, sizeof(aMatrix));
  v12 = v122;
  v13 = v123;
  memset(&pMatrix, 0, sizeof(pMatrix));
  *&pPos.x = 0;
  if (!LODWORD(v3[1].monitor))
  {
    if ((BYTE1(v3[1].klass->_1.events) & 1) != 0)
    {
      dds3SetQuake(20, 0x32u);
      if (!LODWORD(v3[1].monitor))
        goto LABEL_21;
    }
    else
    {
      dds3SetQuake(15, 0x28u);
      if (!LODWORD(v3[1].monitor))
      {
LABEL_21:
        pFormation = effBTLSkillGetInvokeFormation(0);
        TargetFormation = effBTLSkillGetTargetFormation(0);
        v121 = TargetFormation;
        if (!TargetFormation || (TargetFormation->stat & 1) == 0)
          goto LABEL_41;
        formindex = TargetFormation->formindex;
        UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
        if ((UnitWorkFromFormindex->flag & 4) == 0
          && (v20 = UnitWorkFromFormindex->id - 258, v20 <= 0x22)
          && ((1LL << v20) & 0x600000003LL) != 0)
        {
          effBTLPointLightCompulsionOFF();
        }
        else
        {
LABEL_41:
          *(v8[2] + 16) = 0;
          *(v8[2] + 17) = 1;
          *(v8[2] + 18) = 0;
          *(v8[2] + 20) = 0;
          v8[3] = 0x80303030809196A5LL;
          *(v8[4] + 16) = 0;
          *(v8[4] + 20) = 0;
          *(v8[4] + 24) = 10;
          *(v8[4] + 28) = 1;
          v9->color = -2139717504;
          v9->color_anim->fade_in_frame = 0;
          v9->color_anim->fade_in_pattern = 0;
          v9->color_anim->fade_out_frame = 10;
          v9->color_anim->fade_out_pattern = 1;
          effBTLPointLightSet(&pLight, &pFormation);
          effBTLPointLightSet(&pLight, &v121);
          effBTLModelColorSet(&pModel, &pFormation);
          effBTLModelColorSet(&pModel, &v121);
        }
      }
    }
  }
  SDF_VU0__LOADVECTOR(*&v3[1].klass->_1.element_class);
  *&v126.x = v12;
  *&v126.z = v13;
  SDF_VU0__LOADVECTOR_B(v126);
  Mult();
  ToMatrix();
  SDF_VU0__STOREMATRIX(&aMatrix);
  v27 = pPosPtr;
  *&pPosPtr->target = 256;
  v27->direction = 9;
  v27->radius = 0;
  effBTLPartGetPositionPtr(&v3[1], &pPosPtr, &pPos);
  x = pPos.x;
  y = pPos.y;
  z = pPos.z;
  w = pPos.w;
  v127.x = x;
  v127.y = y;
  v127.z = z;
  v127.w = w;
  dds3EffectPartSetPosition(&v3[2], v127);
  v114 = aMatrix;
  dds3EffectPartSetRotateMatrix(&v3[2], &v114);
  effBTLPartGetRotateMatrixPtr(&pPosPtr, &pMatrix);
  v113 = pMatrix;
  dds3EffectPartSetDirection(&v3[2], &v113);
  dds3EffectPartDraw(&v3[2]);
  v34 = pPosPtr;
  *&pPosPtr->target = 256;
  v34->direction = 9;
  v34->radius = 0;
  effBTLPartGetPositionPtr(&v3[1], &pPosPtr, &pPos);
  dds3EffectPartSetPosition(&v3[2].monitor, pPos);
  v112 = aMatrix;
  dds3EffectPartSetRotateMatrix(&v3[2].monitor, &v112);
  effBTLPartGetRotateMatrixPtr(&pPosPtr, &pMatrix);
  v111 = pMatrix;
  dds3EffectPartSetDirection(&v3[2].monitor, &v111);
  dds3EffectPartDraw(&v3[2].monitor);
  v37 = pPosPtr;
  *&pPosPtr->target = 256;
  v37->direction = 8;
  v37->radius = 0;
  effBTLPartGetPositionPtr(&v3[1], &pPosPtr, &pPos);
  dds3EffectPartSetPosition(&v3[3], pPos);
  v110 = aMatrix;
  dds3EffectPartSetRotateMatrix(&v3[3], &v110);
  effBTLPartGetRotateMatrixPtr(&pPosPtr, &pMatrix);
  v109 = pMatrix;
  dds3EffectPartSetDirection(&v3[3], &v109);
  dds3EffectPartDraw(&v3[3]);
  v40 = pPosPtr;
  *&pPosPtr->target = 256;
  v40->direction = 8;
  v40->radius = 0;
  effBTLPartGetPositionPtr(&v3[1], &pPosPtr, &pPos);
  dds3EffectPartSetPosition(&v3[3].monitor, pPos);
  v108 = aMatrix;
  dds3EffectPartSetRotateMatrix(&v3[3].monitor, &v108);
  effBTLPartGetRotateMatrixPtr(&pPosPtr, &pMatrix);
  v107 = pMatrix;
  dds3EffectPartSetDirection(&v3[3].monitor, &v107);
  dds3EffectPartDraw(&v3[3].monitor);
  v43 = pPosPtr;
  *&pPosPtr->target = 256;
  v43->direction = 8;
  v43->radius = 0;
  effBTLPartGetPositionPtr(&v3[1], &pPosPtr, &pPos);
  dds3EffectPartSetPosition(&v3[4], pPos);
  v106 = aMatrix;
  dds3EffectPartSetRotateMatrix(&v3[4], &v106);
  effBTLPartGetRotateMatrixPtr(&pPosPtr, &pMatrix);
  v105 = pMatrix;
  dds3EffectPartSetDirection(&v3[4], &v105);
  dds3EffectPartDraw(&v3[4]);
  if (LODWORD(v3[1].monitor) >= 2)
  {
    v48 = pPosPtr;
    *&pPosPtr->target = 256;
    v48->direction = 8;
    v48->radius = 0;
    effBTLPartGetPositionPtr(&v3[1], &pPosPtr, &pPos);
    v51 = pPos.x;
    v50 = pPos.y;
    v53 = pPos.z;
    v52 = pPos.w;
    v128.x = v51;
    v128.y = v50;
    v128.z = v53;
    v128.w = v52;
    dds3EffectPartSetPosition(&v3[4].monitor, v128);
    v104 = aMatrix;
    dds3EffectPartSetRotateMatrix(&v3[4].monitor, &v104);
    effBTLPartGetRotateMatrixPtr(&pPosPtr, &pMatrix);
    v103 = pMatrix;
    dds3EffectPartSetDirection(&v3[4].monitor, &v103);
    dds3EffectPartDraw(&v3[4].monitor);
  }
  v55 = pPosPtr;
  *&pPosPtr->target = 256;
  v55->direction = 9;
  v55->radius = 0;
  effBTLPartGetPositionPtr(&v3[1], &pPosPtr, &pPos);
  v58 = pPos.x;
  v57 = pPos.y;
  v60 = pPos.z;
  v59 = pPos.w;
  v129.x = v58;
  v129.y = v57;
  v129.z = v60;
  v129.w = v59;
  dds3EffectPartSetPosition(&v3[5], v129);
  v102 = aMatrix;
  dds3EffectPartSetRotateMatrix(&v3[5], &v102);
  effBTLPartGetRotateMatrixPtr(&pPosPtr, &pMatrix);
  v101 = pMatrix;
  dds3EffectPartSetDirection(&v3[5], &v101);
  dds3EffectPartDraw(&v3[5]);
  v62 = pPosPtr;
  *&pPosPtr->target = 256;
  v62->direction = 9;
  v62->radius = 0;
  effBTLPartGetPositionPtr(&v3[1], &pPosPtr, &pPos);
  dds3EffectPartSetPosition(&v3[5].monitor, pPos);
  v100 = aMatrix;
  dds3EffectPartSetRotateMatrix(&v3[5].monitor, &v100);
  effBTLPartGetRotateMatrixPtr(&pPosPtr, &pMatrix);
  v99 = pMatrix;
  dds3EffectPartSetDirection(&v3[5].monitor, &v99);
  dds3EffectPartDraw(&v3[5].monitor);
  v65 = pPosPtr;
  *&pPosPtr->target = 256;
  v65->direction = 9;
  v65->radius = 0;
  effBTLPartGetPositionPtr(&v3[1], &pPosPtr, &pPos);
  dds3EffectPartSetPosition(&v3[6], pPos);
  v98 = aMatrix;
  dds3EffectPartSetRotateMatrix(&v3[6], &v98);
  effBTLPartGetRotateMatrixPtr(&pPosPtr, &pMatrix);
  v97 = pMatrix;
  dds3EffectPartSetDirection(&v3[6], &v97);
  dds3EffectPartDraw(&v3[6]);
  if (LODWORD(v3[1].monitor) >= 3)
  {
    v70 = pPosPtr;
    *&pPosPtr->target = 256;
    v70->direction = 9;
    v70->radius = 0;
    effBTLPartGetPositionPtr(&v3[1], &pPosPtr, &pPos);
    v73 = pPos.x;
    v72 = pPos.y;
    v75 = pPos.z;
    v74 = pPos.w;
    v130.x = v73;
    v130.y = v72;
    v130.z = v75;
    v130.w = v74;
    dds3EffectPartSetPosition(&v3[6].monitor, v130);
    v96 = aMatrix;
    dds3EffectPartSetRotateMatrix(&v3[6].monitor, &v96);
    effBTLPartGetRotateMatrixPtr(&pPosPtr, &pMatrix);
    v95 = pMatrix;
    dds3EffectPartSetDirection(&v3[6].monitor, &v95);
    dds3EffectPartDraw(&v3[6].monitor);
    if (LODWORD(v3[1].monitor) >= 3)
    {
      v77 = pPosPtr;
      *&pPosPtr->target = 256;
      v77->direction = 9;
      v77->radius = 0;
      effBTLPartGetPositionPtr(&v3[1], &pPosPtr, &pPos);
      v80 = pPos.x;
      v79 = pPos.y;
      v82 = pPos.z;
      v81 = pPos.w;
      v131.x = v80;
      v131.y = v79;
      v131.z = v82;
      v131.w = v81;
      dds3EffectPartSetPosition(&v3[7], v131);
      v94 = aMatrix;
      dds3EffectPartSetRotateMatrix(&v3[7], &v94);
      effBTLPartGetRotateMatrixPtr(&pPosPtr, &pMatrix);
      v93 = pMatrix;
      dds3EffectPartSetDirection(&v3[7], &v93);
      dds3EffectPartDraw(&v3[7]);
    }
  }
  v84 = pPosPtr;
  *&pPosPtr->target = 256;
  v84->direction = 9;
  v84->radius = 0;
  effBTLPartGetPositionPtr(&v3[1], &pPosPtr, &pPos);
  v87 = pPos.x;
  v86 = pPos.y;
  v89 = pPos.z;
  v88 = pPos.w;
  v132.x = v87;
  v132.y = v86;
  v132.z = v89;
  v132.w = v88;
  dds3EffectPartSetPosition(&v3[7].monitor, v132);
  v92 = aMatrix;
  dds3EffectPartSetRotateMatrix(&v3[7].monitor, &v92);
  effBTLPartGetRotateMatrixPtr(&pPosPtr, &pMatrix);
  v91 = pMatrix;
  dds3EffectPartSetDirection(&v3[7].monitor, &v91);
  dds3EffectPartDraw(&v3[7].monitor);
  ++LODWORD(v3[1].monitor);
}

// 0x14d38c0
u32 effBTLSys_AttackC_GetLength(void *hData) {
  return 20;
}

// 0x14d39e0
void effBTLSys_AttackC_PartHandleCreate(void) {
  effBTLSystem_Part_HandleCreate(&effBTLSystem_AttackC_PartList, effBTLSystem_AttackC_PartList->max_length);
}

// 0x14d3a50
void effBTLSys_AttackC_PartHandleDelete(void) {
  effBTLSystem_Part_HandleDelete(&effBTLSystem_AttackC_PartList, effBTLSystem_AttackC_PartList->max_length);
}

// 0x14d2790
void effBTLSys_AttackC_SetColor(void **hData, u32 abgr) {

}

// 0x14d0de0
effBattleSystem_effBTLSystem_Attack_tag *effBTLSys_Attack_Create(nbFormation_t *pFormation) {
  effBattleSystem_effBTLSystem_Attack_tag_o *v3;
  struct effBattleSystem_effBTLSystem_Part_tag_array *effBTLSystem_Attack_PartList;
  effPartHandle_t_o **p_hPart;
  struct effBattleSystem_effBTLSystem_Part_tag_array *v8;
  struct effBattleSystem_effBTLSystem_Part_tag_array *v10;
  struct effBattleSystem_effBTLSystem_Part_tag_array *v12;
  struct effBattleSystem_effBTLSystem_Part_tag_array *v14;
  struct effBattleSystem_effBTLSystem_Part_tag_array *v16;

  v3 = Allocate(effBattleSystem_effBTLSystem_Attack_tag);
  _ctor(v3, 0);
  v3->pFormation = pFormation;
  v3->frame = 0;
  else
  {
    if (!LODWORD(effBTLSystem_Attack_PartList->max_length))
      goto LABEL_6;
  }
  p_hPart = &effBTLSystem_Attack_PartList->m_Items[0]->hPart;
  v3->hMainD3P = dds3EffectPartCopy(p_hPart, 0, 0);
  v8 = effBTLSystem_Attack_PartList;
  v3->hFlash1PCF = dds3EffectPartCopy(&v8->m_Items[1]->hPart, 0, 0);
  v10 = effBTLSystem_Attack_PartList;
  v3->hFlash2PCF = dds3EffectPartCopy(&v10->m_Items[2]->hPart, 0, 0);
  v12 = effBTLSystem_Attack_PartList;
  v3->hFlash3PCF = dds3EffectPartCopy(&v12->m_Items[3]->hPart, 0, 0);
  v14 = effBTLSystem_Attack_PartList;
  v3->hSmoke1D3P = dds3EffectPartCopy(&v14->m_Items[4]->hPart, 0, 0);
  v16 = effBTLSystem_Attack_PartList;
  v3->hSmoke2D3P = dds3EffectPartCopy(&v16->m_Items[5]->hPart, 0, 0);
  return v3;
}

// 0x14d1ec0
void effBTLSys_Attack_DataFree(void) {
  effBTLSystem_Part_DataFree(&effBTLSystem_Attack_PartList, effBTLSystem_Attack_PartList->max_length);
}

// 0x14d1e50
void effBTLSys_Attack_DataLoad(void) {
  effBTLSystem_Part_DataLoad(&effBTLSystem_Attack_PartList, effBTLSystem_Attack_PartList->max_length);
}

// 0x14d1030
void effBTLSys_Attack_Delete(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  u64 v8[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Attack_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Attack_tag, v8);
      if ((v8[0] & 1) != 0)
        v5 = v8[2];
      else
        v5 = v8 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  dds3EffectPartDelete(&hData[4].monitor);
  dds3EffectPartDelete(&hData[4]);
  dds3EffectPartDelete(&hData[3].monitor);
  dds3EffectPartDelete(&hData[3]);
  dds3EffectPartDelete(&hData[2].monitor);
  dds3EffectPartDelete(&hData[2]);
}

// 0x14d11c0
void effBTLSys_Attack_Delete2(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  u64 v8[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Attack_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Attack_tag, v8);
      if ((v8[0] & 1) != 0)
        v5 = v8[2];
      else
        v5 = v8 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  dds3EffectPartDelete(&hData[4].monitor);
  dds3EffectPartDelete(&hData[4]);
  dds3EffectPartDelete(&hData[3].monitor);
  dds3EffectPartDelete(&hData[3]);
  dds3EffectPartDelete(&hData[2].monitor);
  dds3EffectPartDelete(&hData[2]);
}

// 0x14d1390
void effBTLSys_Attack_Draw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  effBTL_SkillModel_t_o *v9;
  u64 *v10;
  s64 v12;
  s64 v13;
  nbFormation_t_o *TargetFormation;
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;
  u32 v20;
  effBTL_SkillPositionPtr_t_o *v27;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  effBTL_SkillPositionPtr_t_o *v34;
  effBTL_SkillPositionPtr_t_o *v37;
  effBTL_SkillPositionPtr_t_o *v40;
  effBTL_SkillPositionPtr_t_o *v43;
  u32 monitor;
  effBTL_SkillPositionPtr_t_o *v49;
  f32 v51;
  f32 v52;
  f32 v53;
  f32 v54;
  UnityEngine_Matrix4x4_o v56;
  UnityEngine_Matrix4x4_o v57;
  UnityEngine_Matrix4x4_o v58;
  UnityEngine_Matrix4x4_o v59;
  UnityEngine_Matrix4x4_o v60;
  UnityEngine_Matrix4x4_o v61;
  UnityEngine_Matrix4x4_o v62;
  UnityEngine_Matrix4x4_o v63;
  UnityEngine_Matrix4x4_o v64;
  UnityEngine_Matrix4x4_o v65;
  UnityEngine_Matrix4x4_o v66;
  UnityEngine_Matrix4x4_o v67;
  UnityEngine_Matrix4x4_o pMatrix;
  UnityEngine_Matrix4x4_o aMatrix;
  UnityEngine_Vector4_o pPos;
  effBTL_SkillPositionPtr_t_o *pPosPtr;
  effBTL_SkillModel_t_o *pModel;
  effBTL_SkillLight_t_o *pLight;
  nbFormation_t_o *v74;
  nbFormation_t_o *pFormation;
  s64 v76;
  s64 v77;
  char *v78;
  UnityEngine_Vector4_o v79;
  UnityEngine_Vector4_o v80;
  UnityEngine_Vector4_o v81;

  v74 = 0;
  pFormation = 0;
  memset(&aMatrix, 0, sizeof(aMatrix));
  memset(&pMatrix, 0, sizeof(pMatrix));
  pModel = 0;
  pLight = 0;
  *&pPos.z = 0;
  pPosPtr = 0;
  *&pPos.x = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Attack_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Attack_tag, &v76);
      if ((v76 & 1) != 0)
        v6 = v78;
      else
        v6 = &v76 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v76 = 0;
  v77 = 0;
  sub_854690(&v76, 0.0, 1.0, 0.0, 0.0);
  v8 = Allocate(effBTL_SkillLight_t);
  effBTL_SkillLight_t___ctor(v8);
  pLight = v8;
  effBTL_SkillLight_t__Clear(v8);
  v9 = Allocate(effBTL_SkillModel_t);
  effBTL_SkillModel_t___ctor(v9);
  pModel = v9;
  effBTL_SkillModel_t__Clear(v9);
  v10 = Allocate(effBTL_SkillPositionPtr_t);
  effBTL_SkillPositionPtr_t___ctor(v10);
  *&pPos.z = 0;
  pPosPtr = v10;
  memset(&aMatrix, 0, sizeof(aMatrix));
  v12 = v76;
  v13 = v77;
  memset(&pMatrix, 0, sizeof(pMatrix));
  *&pPos.x = 0;
  if (!LODWORD(v3[1].monitor))
  {
    if ((BYTE1(v3[1].klass->_1.events) & 1) != 0)
    {
      dds3SetQuake(20, 0x32u);
      if (!LODWORD(v3[1].monitor))
        goto LABEL_21;
    }
    else
    {
      dds3SetQuake(15, 0x28u);
      if (!LODWORD(v3[1].monitor))
      {
LABEL_21:
        pFormation = effBTLSkillGetInvokeFormation(0);
        TargetFormation = effBTLSkillGetTargetFormation(0);
        v74 = TargetFormation;
        if (!TargetFormation || (TargetFormation->stat & 1) == 0)
          goto LABEL_41;
        formindex = TargetFormation->formindex;
        UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
        if ((UnitWorkFromFormindex->flag & 4) == 0
          && (v20 = UnitWorkFromFormindex->id - 258, v20 <= 0x22)
          && ((1LL << v20) & 0x600000003LL) != 0)
        {
          effBTLPointLightCompulsionOFF();
        }
        else
        {
LABEL_41:
          *(v8[2] + 16) = 0;
          *(v8[2] + 17) = 1;
          *(v8[2] + 18) = 0;
          *(v8[2] + 20) = 0;
          v8[3] = 0x80303030809196A5LL;
          *(v8[4] + 16) = 0;
          *(v8[4] + 20) = 0;
          *(v8[4] + 24) = 10;
          *(v8[4] + 28) = 1;
          v9->color = -2139717504;
          v9->color_anim->fade_in_frame = 0;
          v9->color_anim->fade_in_pattern = 0;
          v9->color_anim->fade_out_frame = 10;
          v9->color_anim->fade_out_pattern = 1;
          effBTLPointLightSet(&pLight, &pFormation);
          effBTLPointLightSet(&pLight, &v74);
          effBTLModelColorSet(&pModel, &pFormation);
          effBTLModelColorSet(&pModel, &v74);
        }
      }
    }
  }
  SDF_VU0__LOADVECTOR(*&v3[1].klass->_1.element_class);
  *&v79.x = v12;
  *&v79.z = v13;
  SDF_VU0__LOADVECTOR_B(v79);
  Mult();
  ToMatrix();
  SDF_VU0__STOREMATRIX(&aMatrix);
  v27 = pPosPtr;
  *&pPosPtr->target = 256;
  v27->direction = 9;
  v27->radius = 0;
  effBTLPartGetPositionPtr(&v3[1], &pPosPtr, &pPos);
  x = pPos.x;
  y = pPos.y;
  z = pPos.z;
  w = pPos.w;
  v80.x = x;
  v80.y = y;
  v80.z = z;
  v80.w = w;
  dds3EffectPartSetPosition(&v3[2], v80);
  v67 = aMatrix;
  dds3EffectPartSetRotateMatrix(&v3[2], &v67);
  effBTLPartGetRotateMatrixPtr(&pPosPtr, &pMatrix);
  v66 = pMatrix;
  dds3EffectPartSetDirection(&v3[2], &v66);
  dds3EffectPartDraw(&v3[2]);
  v34 = pPosPtr;
  *&pPosPtr->target = 256;
  v34->direction = 9;
  v34->radius = 0;
  effBTLPartGetPositionPtr(&v3[1], &pPosPtr, &pPos);
  dds3EffectPartSetPosition(&v3[2].monitor, pPos);
  v65 = aMatrix;
  dds3EffectPartSetRotateMatrix(&v3[2].monitor, &v65);
  effBTLPartGetRotateMatrixPtr(&pPosPtr, &pMatrix);
  v64 = pMatrix;
  dds3EffectPartSetDirection(&v3[2].monitor, &v64);
  dds3EffectPartDraw(&v3[2].monitor);
  v37 = pPosPtr;
  *&pPosPtr->target = 256;
  v37->direction = 8;
  v37->radius = 0;
  effBTLPartGetPositionPtr(&v3[1], &pPosPtr, &pPos);
  dds3EffectPartSetPosition(&v3[3], pPos);
  v63 = aMatrix;
  dds3EffectPartSetRotateMatrix(&v3[3], &v63);
  effBTLPartGetRotateMatrixPtr(&pPosPtr, &pMatrix);
  v62 = pMatrix;
  dds3EffectPartSetDirection(&v3[3], &v62);
  dds3EffectPartDraw(&v3[3]);
  v40 = pPosPtr;
  *&pPosPtr->target = 256;
  v40->direction = 8;
  v40->radius = 0;
  effBTLPartGetPositionPtr(&v3[1], &pPosPtr, &pPos);
  dds3EffectPartSetPosition(&v3[3].monitor, pPos);
  v61 = aMatrix;
  dds3EffectPartSetRotateMatrix(&v3[3].monitor, &v61);
  effBTLPartGetRotateMatrixPtr(&pPosPtr, &pMatrix);
  v60 = pMatrix;
  dds3EffectPartSetDirection(&v3[3].monitor, &v60);
  dds3EffectPartDraw(&v3[3].monitor);
  v43 = pPosPtr;
  *&pPosPtr->target = 256;
  v43->direction = 8;
  v43->radius = 0;
  effBTLPartGetPositionPtr(&v3[1], &pPosPtr, &pPos);
  dds3EffectPartSetPosition(&v3[4], pPos);
  v59 = aMatrix;
  dds3EffectPartSetRotateMatrix(&v3[4], &v59);
  effBTLPartGetRotateMatrixPtr(&pPosPtr, &pMatrix);
  v58 = pMatrix;
  dds3EffectPartSetDirection(&v3[4], &v58);
  dds3EffectPartDraw(&v3[4]);
  monitor = v3[1].monitor;
  if (monitor >= 2)
  {
    v49 = pPosPtr;
    *&pPosPtr->target = 256;
    v49->direction = 8;
    v49->radius = 0;
    effBTLPartGetPositionPtr(&v3[1], &pPosPtr, &pPos);
    v52 = pPos.x;
    v51 = pPos.y;
    v54 = pPos.z;
    v53 = pPos.w;
    v81.x = v52;
    v81.y = v51;
    v81.z = v54;
    v81.w = v53;
    dds3EffectPartSetPosition(&v3[4].monitor, v81);
    v57 = aMatrix;
    dds3EffectPartSetRotateMatrix(&v3[4].monitor, &v57);
    effBTLPartGetRotateMatrixPtr(&pPosPtr, &pMatrix);
    v56 = pMatrix;
    dds3EffectPartSetDirection(&v3[4].monitor, &v56);
    dds3EffectPartDraw(&v3[4].monitor);
    monitor = v3[1].monitor;
  }
  LODWORD(v3[1].monitor) = monitor + 1;
}

// 0x14d1e10
u32 effBTLSys_Attack_GetLength(void *hData) {
  return 20;
}

// 0x14d1f30
void effBTLSys_Attack_PartHandleCreate(void) {
  effBTLSystem_Part_HandleCreate(&effBTLSystem_Attack_PartList, effBTLSystem_Attack_PartList->max_length);
}

// 0x14d1fa0
void effBTLSys_Attack_PartHandleDelete(void) {
  effBTLSystem_Part_HandleDelete(&effBTLSystem_Attack_PartList, effBTLSystem_Attack_PartList->max_length);
}

// 0x14d1350
void effBTLSys_Attack_SetColor(void **hData, u32 abgr) {

}

// 0x14c8080
effBattleSystem_effBTLSystem_Bind_tag *effBTLSys_Bind_Create(nbFormation_t *pFormation) {
  u64 *v3;
  f32 ScalePtr;
  Il2CppObject *hData;

  hData = 0;
  v3 = Allocate(effBattleSystem_effBTLSystem_Bind_tag);
  _ctor(v3, 0);
  v3[2] = pFormation;
  *(v3 + 6) = 0;
  v3[4] = effPCPThunderSpherePolyLowCreate(effBTLSystem_Bind_ThunderSpherePolyLowParam);
  ScalePtr = effBTLSystem_GetScalePtr(v3 + 2);
  hData = v3[4];
  effPCPThunderSpherePolyLowSetScale(&hData, ScalePtr);
  return v3;
}

// 0x14c8800
void effBTLSys_Bind_DataFree(void) {
  effBTLSystem_Part_DataFree(&effBTLSystem_Bind_PartList, effBTLSystem_Bind_PartList->max_length);
}

// 0x14c8790
void effBTLSys_Bind_DataLoad(void) {
  effBTLSystem_Part_DataLoad(&effBTLSystem_Bind_PartList, effBTLSystem_Bind_PartList->max_length);
}

// 0x14c8150
void effBTLSys_Bind_Delete(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  Il2CppClass *v7;
  evtUnitHandle_t_o **p_implementedInterfaces;
  Il2CppClass **implementedInterfaces;
  Il2CppClass *v10;
  u64 v11[3];

  v10 = 0;
  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Bind_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Bind_tag, v11);
      if ((v11[0] & 1) != 0)
        v5 = v11[2];
      else
        v5 = v11 + 1;
      v6 = sub_8C4940(v5);
    }
  }
LABEL_14:
  v7 = hData[1].klass;
  implementedInterfaces = v7->_1.implementedInterfaces;
  p_implementedInterfaces = &v7->_1.implementedInterfaces;
  if (implementedInterfaces)
  {
    evtSetUnitColorRGB(p_implementedInterfaces, 4u, 0x80808080);
    LODWORD(hData[1].klass->rgctx_data) = (BYTE3(hData[1].klass->rgctx_data) << 24) | 0x808080;
  }
  v10 = hData[2].klass;
  effPCPThunderSpherePolyLowDelete(&v10);
}

// 0x14c8300
void effBTLSys_Bind_Delete2(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppClass *v8;
  u64 v9[3];

  v8 = 0;
  klass = hData->klass;
  if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Bind_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Bind_tag, v9);
    if ((v9[0] & 1) != 0)
      v6 = v9[2];
    else
      v6 = v9 + 1;
    v7 = sub_8C4940(v6);
  }
  v8 = hData[2].klass;
  effPCPThunderSpherePolyLowDelete(&v8);
}

// 0x14c8540
void effBTLSys_Bind_Draw(void **hData) {
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  Il2CppClass *v9;
  evtUnitHandle_t_o **p_implementedInterfaces;
  Il2CppClass **implementedInterfaces;
  Il2CppClass *v12;
  UnityEngine_Vector4_o p;
  u64 v14[3];

  *&p.x = 0;
  *&p.z = 0;
  v12 = 0;
  v4 = *hData;
  if (*hData)
  {
    klass = v4->klass;
    if (v4->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Bind_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Bind_tag, v14);
      if ((v14[0] & 1) != 0)
        v7 = v14[2];
      else
        v7 = v14 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  *&p.x = 0;
  *&p.z = 0;
  if (!LODWORD(v4[1].monitor))
  {
    v9 = v4[1].klass;
    implementedInterfaces = v9->_1.implementedInterfaces;
    p_implementedInterfaces = &v9->_1.implementedInterfaces;
    if (implementedInterfaces)
    {
      evtSetUnitColorRGB(p_implementedInterfaces, 4u, 0x80407F6B);
      LODWORD(v4[1].klass->rgctx_data) = (BYTE3(v4[1].klass->rgctx_data) << 24) | 0x407F6B;
    }
  }
  effBTLModelGetMarkPosition2(&v4[1], 0);
  SDF_VU0__STOREVECTOR(&p);
  v12 = v4[2].klass;
  effPCPThunderSpherePolyLowSetPosition(&v12, p);
  effPCPThunderSpherePolyLowDraw(&v12);
  ++LODWORD(v4[1].monitor);
}

// 0x14c8750
u32 effBTLSys_Bind_GetLength(void *hData) {
  return 0;
}

// 0x14c8870
void effBTLSys_Bind_PartHandleCreate(void) {
  effBTLSystem_Part_HandleCreate(&effBTLSystem_Bind_PartList, effBTLSystem_Bind_PartList->max_length);
}

// 0x14c88e0
void effBTLSys_Bind_PartHandleDelete(void) {
  effBTLSystem_Part_HandleDelete(&effBTLSystem_Bind_PartList, effBTLSystem_Bind_PartList->max_length);
}

// 0x14c8430
void effBTLSys_Bind_SetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  Il2CppObject *v9[3];
  Il2CppObject *hDataa;

  hDataa = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Bind_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Bind_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  hDataa = (*hData)[2].klass;
  effPCPThunderSpherePolyLowSetColor(&hDataa, abgr);
}

// 0x14ca020
effBattleSystem_effBTLSystem_Charm_tag *effBTLSys_Charm_Create(nbFormation_t *pFormation) {
  effBattleSystem_effBTLSystem_Charm_tag_o *v3;
  struct effBattleSystem_effBTLSystem_Part_tag_array *effBTLSystem_Charm_PartList;
  effPartHandle_t_o **p_hPart;
  struct effBattleSystem_effBTLSystem_Part_tag_array *v8;
  f32 ScalePtr;

  v3 = Allocate(effBattleSystem_effBTLSystem_Charm_tag);
  _ctor(v3, 0);
  v3->pFormation = pFormation;
  v3->frame = 0;
  else
  {
    if (!LODWORD(effBTLSystem_Charm_PartList->max_length))
      goto LABEL_6;
  }
  p_hPart = &effBTLSystem_Charm_PartList->m_Items[0]->hPart;
  v3->hSmoke = dds3EffectPartCopy(p_hPart, 0, 0);
  v8 = effBTLSystem_Charm_PartList;
  v3->hHeart = dds3EffectPartCopy(&v8->m_Items[1]->hPart, 0, 0);
  ScalePtr = effBTLSystem_GetScalePtr(&v3->pFormation);
  dds3EffectPartSetScale(&v3->hSmoke, ScalePtr);
  dds3EffectPartSetScale(&v3->hHeart, ScalePtr);
  return v3;
}

// 0x14ca920
void effBTLSys_Charm_DataFree(void) {
  effBTLSystem_Part_DataFree(&effBTLSystem_Charm_PartList, effBTLSystem_Charm_PartList->max_length);
}

// 0x14ca8b0
void effBTLSys_Charm_DataLoad(void) {
  effBTLSystem_Part_DataLoad(&effBTLSystem_Charm_PartList, effBTLSystem_Charm_PartList->max_length);
}

// 0x14ca1a0
void effBTLSys_Charm_Delete(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  Il2CppClass *v7;
  evtUnitHandle_t_o **p_implementedInterfaces;
  Il2CppClass **implementedInterfaces;
  u64 v10[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Charm_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Charm_tag, v10);
      if ((v10[0] & 1) != 0)
        v5 = v10[2];
      else
        v5 = v10 + 1;
      v6 = sub_8C4940(v5);
    }
  }
LABEL_14:
  v7 = hData[1].klass;
  implementedInterfaces = v7->_1.implementedInterfaces;
  p_implementedInterfaces = &v7->_1.implementedInterfaces;
  if (implementedInterfaces)
  {
    evtSetUnitColorRGB(p_implementedInterfaces, 4u, 0x80808080);
    LODWORD(hData[1].klass->rgctx_data) = (BYTE3(hData[1].klass->rgctx_data) << 24) | 0x808080;
  }
  dds3EffectPartDelete(&hData[2]);
  dds3EffectPartDelete(&hData[2].monitor);
}

// 0x14ca370
void effBTLSys_Charm_Delete2(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  u64 v8[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Charm_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Charm_tag, v8);
      if ((v8[0] & 1) != 0)
        v5 = v8[2];
      else
        v5 = v8 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  dds3EffectPartDelete(&hData[2]);
  dds3EffectPartDelete(&hData[2].monitor);
}

// 0x14ca600
void effBTLSys_Charm_Draw(void **hData) {
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  Il2CppClass *v9;
  evtUnitHandle_t_o **p_implementedInterfaces;
  Il2CppClass **implementedInterfaces;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  UnityEngine_Vector4_o p;
  u64 v18[3];
  UnityEngine_Vector4_o v19;

  *&p.x = 0;
  *&p.z = 0;
  v4 = *hData;
  if (*hData)
  {
    klass = v4->klass;
    if (v4->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Charm_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Charm_tag, v18);
      if ((v18[0] & 1) != 0)
        v7 = v18[2];
      else
        v7 = v18 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  *&p.x = 0;
  *&p.z = 0;
  if (!LODWORD(v4[1].monitor))
  {
    v9 = v4[1].klass;
    implementedInterfaces = v9->_1.implementedInterfaces;
    p_implementedInterfaces = &v9->_1.implementedInterfaces;
    if (implementedInterfaces)
    {
      evtSetUnitColorRGB(p_implementedInterfaces, 4u, 0x8040327F);
      LODWORD(v4[1].klass->rgctx_data) = (BYTE3(v4[1].klass->rgctx_data) << 24) | 0x40327F;
    }
  }
  effBTLModelGetMarkPosition2(&v4[1], 2u);
  SDF_VU0__STOREVECTOR(&p);
  x = p.x;
  y = p.y;
  z = p.z;
  w = p.w;
  v19.x = x;
  v19.y = y;
  v19.z = z;
  v19.w = w;
  dds3EffectPartSetPosition(&v4[2], v19);
  dds3EffectPartSetPosition(&v4[2].monitor, p);
  dds3EffectPartDraw(&v4[2]);
  dds3EffectPartDraw(&v4[2].monitor);
  ++LODWORD(v4[1].monitor);
}

// 0x14ca870
u32 effBTLSys_Charm_GetLength(void *hData) {
  return 0;
}

// 0x14ca990
void effBTLSys_Charm_PartHandleCreate(void) {
  effBTLSystem_Part_HandleCreate(&effBTLSystem_Charm_PartList, effBTLSystem_Charm_PartList->max_length);
}

// 0x14caa00
void effBTLSys_Charm_PartHandleDelete(void) {
  effBTLSystem_Part_HandleDelete(&effBTLSystem_Charm_PartList, effBTLSystem_Charm_PartList->max_length);
}

// 0x14ca4c0
void effBTLSys_Charm_SetColor(void **hData, u32 abgr) {
  u32 v3;
  effPartHandle_t_o **v5;
  effPartHandle_t_o *v6;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  v3 = abgr;
  v5 = *hData;
  if (*hData)
  {
    v6 = *v5;
    if (LOBYTE((*v5)[9].klass) < typeHierarchyDepth
      || *(v6[6].monitor + typeHierarchyDepth - 1) != effBattleSystem_effBTLSystem_Charm_tag)
    {
      sub_8FC2C0(v6[2].klass, effBattleSystem_effBTLSystem_Charm_tag, v10);
      if ((v10[0] & 1) != 0)
        v8 = v10[2];
      else
        v8 = v10 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  dds3EffectPartSetColor(v5 + 4, v3);
  dds3EffectPartSetColor(v5 + 5, v3);
}

// 0x14c8950
effBattleSystem_effBTLSystem_Close_tag *effBTLSys_Close_Create(nbFormation_t *pFormation) {
  effBattleSystem_effBTLSystem_Close_tag_o *v3;
  struct evtUnitHandle_t_o *hunit;
  struct effBattleSystem_effBTLSystem_Part_tag_array *effBTLSystem_Close_PartList;
  effPartHandle_t_o **p_hPart;
  struct effBattleSystem_effBTLSystem_Part_tag_array *v9;
  f32 ScalePtr;

  v3 = Allocate(effBattleSystem_effBTLSystem_Close_tag);
  _ctor(v3, 0);
  v3->pFormation = pFormation;
  v3->frame = 0;
  hunit = pFormation->hunit;
  if (hunit)
    v3->hModel = hunit->Model;
  else
    v3->hModel = 0;
  else
  {
    if (!LODWORD(effBTLSystem_Close_PartList->max_length))
      goto LABEL_9;
  }
  p_hPart = &effBTLSystem_Close_PartList->m_Items[0]->hPart;
  v3->hPartD3P0 = dds3EffectPartCopy(p_hPart, 0, 0);
  v9 = effBTLSystem_Close_PartList;
  v3->hPartD3P1 = dds3EffectPartCopy(&v9->m_Items[1]->hPart, 0, 0);
  ScalePtr = effBTLSystem_GetScalePtr(&v3->pFormation);
  dds3EffectPartSetScale(&v3->hPartD3P0, ScalePtr);
  dds3EffectPartSetScale(&v3->hPartD3P1, ScalePtr);
  return v3;
}

// 0x14c9500
void effBTLSys_Close_DataFree(void) {
  effBTLSystem_Part_DataFree(&effBTLSystem_Close_PartList, effBTLSystem_Close_PartList->max_length);
}

// 0x14c9490
void effBTLSys_Close_DataLoad(void) {
  effBTLSystem_Part_DataLoad(&effBTLSystem_Close_PartList, effBTLSystem_Close_PartList->max_length);
}

// 0x14c8af0
void effBTLSys_Close_Delete(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  Il2CppClass *v7;
  evtUnitHandle_t_o **p_implementedInterfaces;
  Il2CppClass **implementedInterfaces;
  u64 v10[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Close_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Close_tag, v10);
      if ((v10[0] & 1) != 0)
        v5 = v10[2];
      else
        v5 = v10 + 1;
      v6 = sub_8C4940(v5);
    }
  }
LABEL_14:
  v7 = hData[1].klass;
  implementedInterfaces = v7->_1.implementedInterfaces;
  p_implementedInterfaces = &v7->_1.implementedInterfaces;
  if (implementedInterfaces)
  {
    evtSetUnitColorRGB(p_implementedInterfaces, 4u, 0x80808080);
    LODWORD(hData[1].klass->rgctx_data) = (BYTE3(hData[1].klass->rgctx_data) << 24) | 0x808080;
  }
  dds3EffectPartDelete(&hData[2].monitor);
  dds3EffectPartDelete(&hData[2]);
}

// 0x14c8cc0
void effBTLSys_Close_Delete2(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  u64 v8[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Close_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Close_tag, v8);
      if ((v8[0] & 1) != 0)
        v5 = v8[2];
      else
        v5 = v8 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  dds3EffectPartDelete(&hData[2]);
  dds3EffectPartDelete(&hData[2].monitor);
}

// 0x14c8f50
void effBTLSys_Close_Draw(void **hData) {
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  Il2CppClass *v9;
  evtUnitHandle_t_o **p_implementedInterfaces;
  Il2CppClass **implementedInterfaces;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  Il2CppObject *Handle;
  Il2CppClass *v18;
  s64 v19;
  dds3SpPoly_RollRing_t3_o **monitor;
  dds3SpPoly_RollRing_t3_o *v21;
  s64 v22;
  Il2CppObject *v23;
  Il2CppClass *v24;
  s64 v25;
  dds3SpPoly_RollRing_t3_o **v26;
  dds3SpPoly_RollRing_t3_o *v27;
  s64 v28;
  char *v29;
  s64 *v30;
  char *v31;
  s64 *v32;
  char *v33;
  s64 *v34;
  char *v35;
  s64 *v36;
  UnityEngine_Vector4_o p;
  u64 v38[2];
  char *v39;
  dds3SpPoly_RollRing_t3_o *pRollRing;
  UnityEngine_Vector4_o v41;

  *&p.x = 0;
  *&p.z = 0;
  pRollRing = 0;
  v4 = *hData;
  if (*hData)
  {
    klass = v4->klass;
    if (v4->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Close_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Close_tag, v38);
      if ((v38[0] & 1) != 0)
        v7 = v39;
      else
        v7 = v38 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  *&p.x = 0;
  *&p.z = 0;
  if (!LODWORD(v4[1].monitor))
  {
    v9 = v4[1].klass;
    implementedInterfaces = v9->_1.implementedInterfaces;
    p_implementedInterfaces = &v9->_1.implementedInterfaces;
    if (implementedInterfaces)
    {
      evtSetUnitColorRGB(p_implementedInterfaces, 4u, 0x807F6666);
      LODWORD(v4[1].klass->rgctx_data) = (BYTE3(v4[1].klass->rgctx_data) << 24) | 0x7F6666;
    }
  }
  effBTLModelGetMarkPosition2(&v4[1], 2u);
  SDF_VU0__STOREVECTOR(&p);
  x = p.x;
  y = p.y;
  z = p.z;
  w = p.w;
  v41.x = x;
  v41.y = y;
  v41.z = z;
  v41.w = w;
  dds3EffectPartSetPosition(&v4[2], v41);
  dds3EffectPartSetPosition(&v4[2].monitor, p);
  Handle = dds3EffectPartGetHandle(&v4[2]);
  v18 = Handle->klass;
  if (Handle->klass->_2.typeHierarchyDepth < v19 || v18->_2.typeHierarchy[v19 - 1] != effHandle_t)
  {
    sub_8FC2C0(v18->_1.element_class, effHandle_t, v38);
    if ((v38[0] & 1) != 0)
      v29 = v39;
    else
      v29 = v38 + 1;
    v30 = sub_8C4940(v29);
  }
  monitor = Handle[1].monitor;
  v21 = *monitor;
  if (LOBYTE((*monitor)[2].hTrackPoly) < v22
    || *(v21[1].hMem + v22 - 1) != dds3SpPoly_Basic_t)
  {
    sub_8FC2C0(*&v21->color_edge_in, dds3SpPoly_Basic_t, v38);
    if ((v38[0] & 1) != 0)
      v31 = v39;
    else
      v31 = v38 + 1;
    v32 = sub_8C4940(v31);
  }
  pRollRing = monitor[28];
  dds3SpPoly_RollRingSetEndless(&pRollRing);
  v23 = dds3EffectPartGetHandle(&v4[2].monitor);
  v24 = v23->klass;
  if (v23->klass->_2.typeHierarchyDepth < v25 || v24->_2.typeHierarchy[v25 - 1] != effHandle_t)
  {
    sub_8FC2C0(v24->_1.element_class, effHandle_t, v38);
    if ((v38[0] & 1) != 0)
      v33 = v39;
    else
      v33 = v38 + 1;
    v34 = sub_8C4940(v33);
  }
  v26 = v23[1].monitor;
  v27 = *v26;
  if (LOBYTE((*v26)[2].hTrackPoly) < v28
    || *(v27[1].hMem + v28 - 1) != dds3SpPoly_Basic_t)
  {
    sub_8FC2C0(*&v27->color_edge_in, dds3SpPoly_Basic_t, v38);
    if ((v38[0] & 1) != 0)
      v35 = v39;
    else
      v35 = v38 + 1;
    v36 = sub_8C4940(v35);
  }
  pRollRing = v26[28];
  dds3SpPoly_RollRingSetEndless(&pRollRing);
  dds3EffectPartDraw(&v4[2]);
  dds3EffectPartDraw(&v4[2].monitor);
  ++LODWORD(v4[1].monitor);
}

// 0x14c9450
u32 effBTLSys_Close_GetLength(void *hData) {
  return 0;
}

// 0x14c9570
void effBTLSys_Close_PartHandleCreate(void) {
  effBTLSystem_Part_HandleCreate(&effBTLSystem_Close_PartList, effBTLSystem_Close_PartList->max_length);
}

// 0x14c95e0
void effBTLSys_Close_PartHandleDelete(void) {
  effBTLSystem_Part_HandleDelete(&effBTLSystem_Close_PartList, effBTLSystem_Close_PartList->max_length);
}

// 0x14c8e10
void effBTLSys_Close_SetColor(void **hData, u32 abgr) {
  u32 v3;
  effPartHandle_t_o **v5;
  effPartHandle_t_o *v6;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  v3 = abgr;
  v5 = *hData;
  if (*hData)
  {
    v6 = *v5;
    if (LOBYTE((*v5)[9].klass) < typeHierarchyDepth
      || *(v6[6].monitor + typeHierarchyDepth - 1) != effBattleSystem_effBTLSystem_Close_tag)
    {
      sub_8FC2C0(v6[2].klass, effBattleSystem_effBTLSystem_Close_tag, v10);
      if ((v10[0] & 1) != 0)
        v8 = v10[2];
      else
        v8 = v10 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  dds3EffectPartSetColor(v5 + 4, v3);
  dds3EffectPartSetColor(v5 + 5, v3);
}

// 0x14ccac0
effBattleSystem_effBTLSystem_CurseCAMP_tag *effBTLSys_CurseCAMP_Create(nbFormation_t *pFormation) {
  effBattleSystem_effBTLSystem_CurseCAMP_tag_o *v3;
  struct effBattleSystem_effBTLSystem_Part_tag_array *effBTLSystem_CurseCAMP_PartList;
  effPartHandle_t_o **p_hPart;
  struct effBattleSystem_effBTLSystem_Part_tag_array *v8;
  f32 ScalePtr;

  v3 = Allocate(effBattleSystem_effBTLSystem_CurseCAMP_tag);
  _ctor(v3, 0);
  v3->pFormation = pFormation;
  v3->frame = 0;
  else
  {
    if (!LODWORD(effBTLSystem_CurseCAMP_PartList->max_length))
      goto LABEL_6;
  }
  p_hPart = &effBTLSystem_CurseCAMP_PartList->m_Items[0]->hPart;
  v3->hPartD3P0 = dds3EffectPartCopy(p_hPart, 0, 0);
  v8 = effBTLSystem_CurseCAMP_PartList;
  v3->hPartD3P1 = dds3EffectPartCopy(&v8->m_Items[1]->hPart, 0, 0);
  ScalePtr = effBTLSystem_GetScalePtr(&v3->pFormation);
  dds3EffectPartSetScale(&v3->hPartD3P0, ScalePtr);
  dds3EffectPartSetScale(&v3->hPartD3P1, ScalePtr);
  return v3;
}

// 0x14cd2e0
void effBTLSys_CurseCAMP_DataFree(void) {
  effBTLSystem_Part_DataFree(&effBTLSystem_CurseCAMP_PartList, effBTLSystem_CurseCAMP_PartList->max_length);
}

// 0x14cd270
void effBTLSys_CurseCAMP_DataLoad(void) {
  effBTLSystem_Part_DataLoad(&effBTLSystem_CurseCAMP_PartList, effBTLSystem_CurseCAMP_PartList->max_length);
}

// 0x14ccc40
void effBTLSys_CurseCAMP_Delete(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  u64 v8[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_CurseCAMP_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_CurseCAMP_tag, v8);
      if ((v8[0] & 1) != 0)
        v5 = v8[2];
      else
        v5 = v8 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  dds3EffectPartDelete(&hData[2]);
  dds3EffectPartDelete(&hData[2].monitor);
}

// 0x14ccd90
void effBTLSys_CurseCAMP_Delete2(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  u64 v8[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_CurseCAMP_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_CurseCAMP_tag, v8);
      if ((v8[0] & 1) != 0)
        v5 = v8[2];
      else
        v5 = v8 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  dds3EffectPartDelete(&hData[2]);
  dds3EffectPartDelete(&hData[2].monitor);
}

// 0x14cd020
void effBTLSys_CurseCAMP_Draw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  f32 *v8;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  UnityEngine_Vector4_o v13;
  u64 v14[3];
  UnityEngine_Vector4_o v15;

  *&v13.x = 0;
  *&v13.z = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_CurseCAMP_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_CurseCAMP_tag, v14);
      if ((v14[0] & 1) != 0)
        v6 = v14[2];
      else
        v6 = v14 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  *&v13.x = 0;
  *&v13.z = 0;
  v8 = v3[1].klass;
  v9 = v8[12];
  v10 = v8[13];
  v12 = v8[14];
  v11 = v8[15];
  v15.x = v9;
  v15.y = v10;
  v15.z = v12;
  v15.w = v11;
  dds3EffectPartSetPosition(&v3[2], v15);
  sub_854710(&v3[1].klass->_1.this_arg, 0);
  sub_854930(&v13, 0);
  sub_854710(&v3[1].klass->_1.this_arg, 1u);
  sub_854930(&v13, 1u);
  sub_854710(&v3[1].klass->_1.this_arg, 2u);
  sub_854930(&v13, 2u);
  dds3EffectPartSetPosition(&v3[2].monitor, v13);
  dds3EffectPartDraw(&v3[2]);
  dds3EffectPartDraw(&v3[2].monitor);
  ++LODWORD(v3[1].monitor);
}

// 0x14cd230
u32 effBTLSys_CurseCAMP_GetLength(void *hData) {
  return 0;
}

// 0x14cd350
void effBTLSys_CurseCAMP_PartHandleCreate(void) {
  effBTLSystem_Part_HandleCreate(&effBTLSystem_CurseCAMP_PartList, effBTLSystem_CurseCAMP_PartList->max_length);
}

// 0x14cd3c0
void effBTLSys_CurseCAMP_PartHandleDelete(void) {
  effBTLSystem_Part_HandleDelete(&effBTLSystem_CurseCAMP_PartList, effBTLSystem_CurseCAMP_PartList->max_length);
}

// 0x14ccee0
void effBTLSys_CurseCAMP_SetColor(void **hData, u32 abgr) {
  u32 v3;
  effPartHandle_t_o **v5;
  effPartHandle_t_o *v6;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  v3 = abgr;
  v5 = *hData;
  if (*hData)
  {
    v6 = *v5;
    if (LOBYTE((*v5)[9].klass) < typeHierarchyDepth
      || *(v6[6].monitor + typeHierarchyDepth - 1) != effBattleSystem_effBTLSystem_CurseCAMP_tag)
    {
      sub_8FC2C0(v6[2].klass, effBattleSystem_effBTLSystem_CurseCAMP_tag, v10);
      if ((v10[0] & 1) != 0)
        v8 = v10[2];
      else
        v8 = v10 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  dds3EffectPartSetColor(v5 + 4, v3);
  dds3EffectPartSetColor(v5 + 5, v3);
}

// 0x14cc270
effBattleSystem_effBTLSystem_Curse_tag *effBTLSys_Curse_Create(nbFormation_t *pFormation) {
  effBattleSystem_effBTLSystem_Curse_tag_o *v3;
  struct effBattleSystem_effBTLSystem_Part_tag_array *effBTLSystem_Curse_PartList;
  effPartHandle_t_o **p_hPart;
  f32 ScalePtr;

  v3 = Allocate(effBattleSystem_effBTLSystem_Curse_tag);
  _ctor(v3, 0);
  v3->pFormation = pFormation;
  v3->frame = 0;
  else
  {
    if (!LODWORD(effBTLSystem_Curse_PartList->max_length))
      goto LABEL_6;
  }
  p_hPart = &effBTLSystem_Curse_PartList->m_Items[0]->hPart;
  v3->hPartD3P = dds3EffectPartCopy(p_hPart, 0, 0);
  ScalePtr = effBTLSystem_GetScalePtr(&v3->pFormation);
  dds3EffectPartSetScale(&v3->hPartD3P, ScalePtr);
  return v3;
}

// 0x14cc970
void effBTLSys_Curse_DataFree(void) {
  effBTLSystem_Part_DataFree(&effBTLSystem_Curse_PartList, effBTLSystem_Curse_PartList->max_length);
}

// 0x14cc900
void effBTLSys_Curse_DataLoad(void) {
  effBTLSystem_Part_DataLoad(&effBTLSystem_Curse_PartList, effBTLSystem_Curse_PartList->max_length);
}

// 0x14cc390
void effBTLSys_Curse_Delete(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  effPartHandle_t_o **v7;
  u64 v9[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Curse_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Curse_tag, v9);
      if ((v9[0] & 1) != 0)
        v5 = v9[2];
      else
        v5 = v9 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  v7 = &hData[2];
  dds3EffectPartDelete(v7);
}

// 0x14cc4e0
void effBTLSys_Curse_Delete2(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  effPartHandle_t_o **v7;
  u64 v9[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Curse_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Curse_tag, v9);
      if ((v9[0] & 1) != 0)
        v5 = v9[2];
      else
        v5 = v9 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  v7 = &hData[2];
  dds3EffectPartDelete(v7);
}

// 0x14cc760
void effBTLSys_Curse_Draw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  f32 *v8;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  u64 v13[3];
  UnityEngine_Vector4_o v14;

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Curse_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Curse_tag, v13);
      if ((v13[0] & 1) != 0)
        v6 = v13[2];
      else
        v6 = v13 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = v3[1].klass;
  v9 = v8[12];
  v10 = v8[13];
  v12 = v8[14];
  v11 = v8[15];
  v14.x = v9;
  v14.y = v10;
  v14.z = v12;
  v14.w = v11;
  dds3EffectPartSetPosition(&v3[2], v14);
  dds3EffectPartDraw(&v3[2]);
  ++LODWORD(v3[1].monitor);
}

// 0x14cc8c0
u32 effBTLSys_Curse_GetLength(void *hData) {
  return 0;
}

// 0x14cc9e0
void effBTLSys_Curse_PartHandleCreate(void) {
  effBTLSystem_Part_HandleCreate(&effBTLSystem_Curse_PartList, effBTLSystem_Curse_PartList->max_length);
}

// 0x14cca50
void effBTLSys_Curse_PartHandleDelete(void) {
  effBTLSystem_Part_HandleDelete(&effBTLSystem_Curse_PartList, effBTLSystem_Curse_PartList->max_length);
}

// 0x14cc630
void effBTLSys_Curse_SetColor(void **hData, u32 abgr) {
  u32 v3;
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  effPartHandle_t_o **v10;
  u64 v11[3];

  v3 = abgr;
  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Curse_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Curse_tag, v11);
      if ((v11[0] & 1) != 0)
        v8 = v11[2];
      else
        v8 = v11 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = &v5[2];
  dds3EffectPartSetColor(v10, v3);
}

// 0x14d3ac0
effBattleSystem_effBTLSystem_Encount_tag *effBTLSys_Encount_Create(nbFormation_t *pFormation) {
  effBattleSystem_effBTLSystem_Encount_tag_o *v3;
  struct effBattleSystem_effBTLSystem_Part_tag_array *effBTLSystem_Encount_PartList;
  effBTL_t_o **p_hBED;

  v3 = Allocate(effBattleSystem_effBTLSystem_Encount_tag);
  _ctor(v3, 0);
  v3->pFormation = pFormation;
  v3->frame = 0;
  else
  {
    if (!LODWORD(effBTLSystem_Encount_PartList->max_length))
      goto LABEL_6;
  }
  p_hBED = &effBTLSystem_Encount_PartList->m_Items[0]->hBED;
  v3->hBEDCut = effBTLCutCreate(p_hBED, 3u, pFormation, 0);
  return v3;
}

// 0x14d4170
void effBTLSys_Encount_DataFree(void) {
  effBTLSystem_Part_DataFree(&effBTLSystem_Encount_PartList, effBTLSystem_Encount_PartList->max_length);
}

// 0x14d4100
void effBTLSys_Encount_DataLoad(void) {
  effBTLSystem_Part_DataLoad(&effBTLSystem_Encount_PartList, effBTLSystem_Encount_PartList->max_length);
}

// 0x14d3bd0
void effBTLSys_Encount_Delete(void *pData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  effBTLCutHandle_t_o **v7;
  u64 v9[3];

  if (pData)
  {
    klass = pData->klass;
    if (pData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Encount_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Encount_tag, v9);
      if ((v9[0] & 1) != 0)
        v5 = v9[2];
      else
        v5 = v9 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  v7 = &pData[2];
  effBTLCutDelete(v7);
}

// 0x14d3d20
void effBTLSys_Encount_Delete2(void *pData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  effBTLCutHandle_t_o **v7;
  u64 v9[3];

  if (pData)
  {
    klass = pData->klass;
    if (pData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Encount_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Encount_tag, v9);
      if ((v9[0] & 1) != 0)
        v5 = v9[2];
      else
        v5 = v9 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  v7 = &pData[2];
  effBTLCutDelete(v7);
}

// 0x14d3e70
void effBTLSys_Encount_Draw(void **pData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v8[3];

  v3 = *pData;
  if (*pData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Encount_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Encount_tag, v8);
      if ((v8[0] & 1) != 0)
        v6 = v8[2];
      else
        v6 = v8 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  effBTLCutDraw(&v3[2]);
  ++LODWORD(v3[1].monitor);
}

// 0x14d3fe0
u32 effBTLSys_Encount_GetLength(void *pData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  effBTLCutHandle_t_o **v7;
  u64 v9[3];

  if (pData)
  {
    klass = pData->klass;
    if (pData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Encount_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Encount_tag, v9);
      if ((v9[0] & 1) != 0)
        v5 = v9[2];
      else
        v5 = v9 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  v7 = &pData[2];
  return effBTLCutGetCutEndFrame(v7);
}

// 0x14d41e0
void effBTLSys_Encount_PartHandleCreate(void) {
  effBTLSystem_Part_HandleCreate(&effBTLSystem_Encount_PartList, effBTLSystem_Encount_PartList->max_length);
}

// 0x14d4250
void effBTLSys_Encount_PartHandleDelete(void) {
  effBTLSystem_Part_HandleDelete(&effBTLSystem_Encount_PartList, effBTLSystem_Encount_PartList->max_length);
}

// 0x14d3fa0
void effBTLSys_Encount_SetColor(void **pData, u32 abgr) {

}

// 0x14cb370
effBattleSystem_effBTLSystem_Fly_tag *effBTLSys_Fly_Create(nbFormation_t *pFormation) {
  effBattleSystem_effBTLSystem_Fly_tag_o *v3;

  v3 = Allocate(effBattleSystem_effBTLSystem_Fly_tag);
  _ctor(v3, 0);
  v3->pFormation = pFormation;
  v3->frame = 0;
  return v3;
}

// 0x14cb920
void effBTLSys_Fly_DataFree(void) {
  effBTLSystem_Part_DataFree(&effBTLSystem_Fly_PartList, effBTLSystem_Fly_PartList->max_length);
}

// 0x14cb8b0
void effBTLSys_Fly_DataLoad(void) {
  effBTLSystem_Part_DataLoad(&effBTLSystem_Fly_PartList, effBTLSystem_Fly_PartList->max_length);
}

// 0x14cb3e0
void effBTLSys_Fly_Delete(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  Il2CppClass *v7;
  evtUnitHandle_t_o **p_implementedInterfaces;
  Il2CppClass **implementedInterfaces;
  u64 v10[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Fly_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Fly_tag, v10);
      if ((v10[0] & 1) != 0)
        v5 = v10[2];
      else
        v5 = v10 + 1;
      v6 = sub_8C4940(v5);
    }
  }
LABEL_14:
  v7 = hData[1].klass;
  implementedInterfaces = v7->_1.implementedInterfaces;
  p_implementedInterfaces = &v7->_1.implementedInterfaces;
  if (implementedInterfaces)
  {
    evtSetUnitColorRGB(p_implementedInterfaces, 4u, 0x80808080);
    LODWORD(hData[1].klass->rgctx_data) = (BYTE3(hData[1].klass->rgctx_data) << 24) | 0x808080;
  }
}

// 0x14cb570
void effBTLSys_Fly_Delete2(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  u64 v7[3];

  else if (!hData)
  {
    return;
  }
  klass = hData->klass;
  if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Fly_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Fly_tag, v7);
    if ((v7[0] & 1) != 0)
      v5 = v7[2];
    else
      v5 = v7 + 1;
    v6 = sub_8C4940(v5);
  }
}

// 0x14cb6d0
void effBTLSys_Fly_Draw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppClass *v8;
  evtUnitHandle_t_o **p_implementedInterfaces;
  Il2CppClass **implementedInterfaces;
  u64 v11[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Fly_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Fly_tag, v11);
      if ((v11[0] & 1) != 0)
        v6 = v11[2];
      else
        v6 = v11 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  if (!LODWORD(v3[1].monitor))
  {
    v8 = v3[1].klass;
    implementedInterfaces = v8->_1.implementedInterfaces;
    p_implementedInterfaces = &v8->_1.implementedInterfaces;
    if (implementedInterfaces)
    {
      evtSetUnitColorRGB(p_implementedInterfaces, 4u, 0x807F6666);
      LODWORD(v3[1].klass->rgctx_data) = (BYTE3(v3[1].klass->rgctx_data) << 24) | 0x7F6666;
    }
  }
  ++LODWORD(v3[1].monitor);
}

// 0x14cb870
u32 effBTLSys_Fly_GetLength(void *hData) {
  return 0;
}

// 0x14cb990
void effBTLSys_Fly_PartHandleCreate(void) {
  effBTLSystem_Part_HandleCreate(&effBTLSystem_Fly_PartList, effBTLSystem_Fly_PartList->max_length);
}

// 0x14cba00
void effBTLSys_Fly_PartHandleDelete(void) {
  effBTLSystem_Part_HandleDelete(&effBTLSystem_Fly_PartList, effBTLSystem_Fly_PartList->max_length);
}

// 0x14cb690
void effBTLSys_Fly_SetColor(void **hData, u32 abgr) {

}

// 0x14c6300
effBattleSystem_effBTLSystem_Freeze_tag *effBTLSys_Freeze_Create(nbFormation_t *pFormation) {
  effBattleSystem_effBTLSystem_Freeze_tag_o *v3;
  struct effBattleSystem_effBTLSystem_Part_tag_array *effBTLSystem_Freeze_PartList;
  effPartHandle_t_o **p_hPart;
  f32 ScalePtr;

  v3 = Allocate(effBattleSystem_effBTLSystem_Freeze_tag);
  _ctor(v3, 0);
  v3->pFormation = pFormation;
  v3->frame = 0;
  else
  {
    if (!LODWORD(effBTLSystem_Freeze_PartList->max_length))
      goto LABEL_6;
  }
  p_hPart = &effBTLSystem_Freeze_PartList->m_Items[0]->hPart;
  v3->hPartD3P = dds3EffectPartCopy(p_hPart, 0, 0);
  ScalePtr = effBTLSystem_GetScalePtr(&v3->pFormation);
  dds3EffectPartSetScale(&v3->hPartD3P, ScalePtr);
  return v3;
}

// 0x14c6bd0
void effBTLSys_Freeze_DataFree(void) {
  effBTLSystem_Part_DataFree(&effBTLSystem_Freeze_PartList, effBTLSystem_Freeze_PartList->max_length);
}

// 0x14c6b60
void effBTLSys_Freeze_DataLoad(void) {
  effBTLSystem_Part_DataLoad(&effBTLSystem_Freeze_PartList, effBTLSystem_Freeze_PartList->max_length);
}

// 0x14c6420
void effBTLSys_Freeze_Delete(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  dds3ModelHandle_t_o **v7;
  Il2CppClass *v9;
  evtUnitHandle_t_o **p_implementedInterfaces;
  Il2CppClass **implementedInterfaces;
  effPartHandle_t_o **v12;
  u64 v13[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Freeze_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Freeze_tag, v13);
      if ((v13[0] & 1) != 0)
        v5 = v13[2];
      else
        v5 = v13 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  v7 = (hData[1].klass->_1.implementedInterfaces + 22);
  mdlShowEffect(v7);
LABEL_17:
  v9 = hData[1].klass;
  implementedInterfaces = v9->_1.implementedInterfaces;
  p_implementedInterfaces = &v9->_1.implementedInterfaces;
  if (implementedInterfaces)
  {
    evtSetUnitColorRGB(p_implementedInterfaces, 0, 0x80808080);
    LODWORD(hData[1].klass->rgctx_data) = (BYTE3(hData[1].klass->rgctx_data) << 24) | 0x808080;
  }
  v12 = &hData[2];
  dds3EffectPartDelete(v12);
}

// 0x14c6620
void effBTLSys_Freeze_Delete2(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  effPartHandle_t_o **v7;
  u64 v9[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Freeze_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Freeze_tag, v9);
      if ((v9[0] & 1) != 0)
        v5 = v9[2];
      else
        v5 = v9 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  v7 = &hData[2];
  dds3EffectPartDelete(v7);
}

// 0x14c68a0
void effBTLSys_Freeze_Draw(void **hData) {
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  Il2CppClass *v9;
  Il2CppClass **v10;
  evtUnitHandle_t_o **p_implementedInterfaces;
  Il2CppClass **implementedInterfaces;
  dds3ModelHandle_t_o **v13;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  UnityEngine_Vector4_o p;
  u64 v20[3];
  UnityEngine_Vector4_o v21;

  *&p.x = 0;
  *&p.z = 0;
  v4 = *hData;
  if (*hData)
  {
    klass = v4->klass;
    if (v4->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Freeze_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Freeze_tag, v20);
      if ((v20[0] & 1) != 0)
        v7 = v20[2];
      else
        v7 = v20 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  *&p.x = 0;
  *&p.z = 0;
  if (!LODWORD(v4[1].monitor))
  {
    v9 = v4[1].klass;
    implementedInterfaces = v9->_1.implementedInterfaces;
    p_implementedInterfaces = &v9->_1.implementedInterfaces;
    v10 = implementedInterfaces;
    if (implementedInterfaces)
    {
      evtSetUnitColorRGB(p_implementedInterfaces, 0, 0x807F783C);
      LODWORD(v4[1].klass->rgctx_data) = (BYTE3(v4[1].klass->rgctx_data) << 24) | 0x7F783C;
      v10 = v4[1].klass->_1.implementedInterfaces;
    }
    v13 = (v10 + 22);
    mdlHideEffect(v13);
  }
  effBTLModelGetMarkPosition2(&v4[1], 0);
  SDF_VU0__STOREVECTOR(&p);
  x = p.x;
  y = p.y;
  z = p.z;
  w = p.w;
  v21.x = x;
  v21.y = y;
  v21.z = z;
  v21.w = w;
  dds3EffectPartSetPosition(&v4[2], v21);
  dds3EffectPartDraw(&v4[2]);
  ++LODWORD(v4[1].monitor);
}

// 0x14c6b20
u32 effBTLSys_Freeze_GetLength(void *hData) {
  return 0;
}

// 0x14c6c40
void effBTLSys_Freeze_PartHandleCreate(void) {
  effBTLSystem_Part_HandleCreate(&effBTLSystem_Freeze_PartList, effBTLSystem_Freeze_PartList->max_length);
}

// 0x14c6cb0
void effBTLSys_Freeze_PartHandleDelete(void) {
  effBTLSystem_Part_HandleDelete(&effBTLSystem_Freeze_PartList, effBTLSystem_Freeze_PartList->max_length);
}

// 0x14c6770
void effBTLSys_Freeze_SetColor(void **hData, u32 abgr) {
  u32 v3;
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  effPartHandle_t_o **v10;
  u64 v11[3];

  v3 = abgr;
  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Freeze_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Freeze_tag, v11);
      if ((v11[0] & 1) != 0)
        v8 = v11[2];
      else
        v8 = v11 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = &v5[2];
  dds3EffectPartSetColor(v10, v3);
}

// 0x14cded0
effBattleSystem_effBTLSystem_Hansya_tag *effBTLSys_Hansya_Create(nbFormation_t *pFormation) {
  u64 *v3;
  effBattleSystem_effBTLSystem_Hansya_tag_o *v4;
  struct effBattleSystem_effBTLSystem_Part_tag_array *effBTLSystem_Hansya_PartList;
  effPartHandle_t_o **p_hPart;
  Il2CppObject *Handle;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v13;
  s64 *v14;
  signed s32 ID;
  struct datNormalSkill_t_array *tbl;
  u32 v19;
  s64 v20;
  struct effBattleSystem_effBTLSystem_Part_tag_array *v23;
  effPartHandle_t_o **v26;
  struct effBattleSystem_effBTLSystem_Part_tag_array *v27;
  f32 ScalePtr;
  u64 v33[3];

  v3 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v3);
  v4 = Allocate(effBattleSystem_effBTLSystem_Hansya_tag);
  _ctor(v4, 0);
  v4->pFormation = pFormation;
  v4->frame = 0;
  else
  {
    if (!LODWORD(effBTLSystem_Hansya_PartList->max_length))
      goto LABEL_6;
  }
  p_hPart = &effBTLSystem_Hansya_PartList->m_Items[0]->hPart;
  v4->hPartPB = dds3EffectPartCopy(p_hPart, 0, 0);
  Handle = dds3EffectPartGetHandle(&v4->hPartPB);
  if (Handle)
  {
    klass = Handle->klass;
    if (Handle->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, v33);
      if ((v33[0] & 1) != 0)
        v13 = v33[2];
      else
        v13 = v33 + 1;
      v14 = sub_8C4940(v13);
    }
  }
  ID = effBTLSkillGetID();
  if (ID >= SLODWORD(tbl->max_length))
  {
      goto LABEL_37;
    goto LABEL_34;
  }
  v19 = effBTLSkillGetID();
  v20 = v19;
  if (!tbl->m_Items[v20]->koukatype)
  {
    v27 = effBTLSystem_Hansya_PartList;
    v26 = &v27->m_Items[1]->hPart;
      goto LABEL_40;
    goto LABEL_50;
  }
  {
LABEL_34:
  }
LABEL_37:
  v23 = effBTLSystem_Hansya_PartList;
  v26 = &v23->m_Items[2]->hPart;
  {
LABEL_40:
  }
LABEL_50:
  v4->hPartPCF = dds3EffectPartCopy(v26, 0, 0);
  ScalePtr = effBTLSystem_GetScalePtr(&v4->pFormation);
  dds3EffectPartSetScale(&v4->hPartPB, ScalePtr);
  dds3EffectPartSetScale(&v4->hPartPCF, ScalePtr);
  return v4;
}

// 0x14cf120
void effBTLSys_Hansya_DataFree(void) {
  effBTLSystem_Part_DataFree(&effBTLSystem_Hansya_PartList, effBTLSystem_Hansya_PartList->max_length);
}

// 0x14cf0b0
void effBTLSys_Hansya_DataLoad(void) {
  effBTLSystem_Part_DataLoad(&effBTLSystem_Hansya_PartList, effBTLSystem_Hansya_PartList->max_length);
}

// 0x14ce2c0
void effBTLSys_Hansya_Delete(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  u64 v8[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Hansya_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Hansya_tag, v8);
      if ((v8[0] & 1) != 0)
        v5 = v8[2];
      else
        v5 = v8 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  dds3EffectPartDelete(&hData[3]);
  dds3EffectPartDelete(&hData[2].monitor);
}

// 0x14ce410
void effBTLSys_Hansya_Delete2(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  u64 v8[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Hansya_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Hansya_tag, v8);
      if ((v8[0] & 1) != 0)
        v5 = v8[2];
      else
        v5 = v8 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  dds3EffectPartDelete(&hData[3]);
  dds3EffectPartDelete(&hData[2].monitor);
}

// 0x14ce5a0
void effBTLSys_Hansya_Draw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  sdf3DLight_t_o *v9;
  u64 *v10;
  u64 *v11;
  effBTL_SkillLight_t_o *v13;
  effBTL_SkillModel_t_o *v14;
  u64 *v15;
  u32 v17;
  signed s32 ID;
  struct datNormalSkill_t_array *tbl;
  u32 v23;
  s32 koukatype;
  s32 v27;
  s32 v28;
  struct effBTL_SkillColorAnim_t_o *color_anim;
  nbFormation_t_o *monitor;
  signed s32 v39;
  struct datNormalSkill_t_array *v41;
  u32 v42;
  s64 p_fields;
  s64 p_v;
  dds3ModelHandle_t_o *Handle;
  dds3ModelHandle_t_c *v49;
  s64 v50;
  char *v51;
  s64 *v52;
  UnityEngine_Object_o *modelobj;
  Il2CppObject *Component_object;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  UnityEngine_Matrix4x4_o v62;
  UnityEngine_Matrix4x4_o v63;
  UnityEngine_Matrix4x4_o v64;
  UnityEngine_Matrix4x4_o v65;
  Il2CppObject *hDataa;
  UnityEngine_Vector4_o p;
  effBTL_SkillPositionPtr_t_o *pPosPtr;
  effBTL_SkillModel_t_o *pModel;
  effBTL_SkillLight_t_o *pLight;
  UnityEngine_Matrix4x4_o aMatrix;
  UnityEngine_Vector4_o v72;
  UnityEngine_Vector4_o dst;
  dds3ModelHandle_t_o *HNDL;
  UnityEngine_Vector4_o v75;

  *&dst.z = 0;
  HNDL = 0;
  hDataa = 0;
  *&v72.z = 0;
  *&dst.x = 0;
  *&v72.x = 0;
  pLight = 0;
  memset(&aMatrix, 0, sizeof(aMatrix));
  pPosPtr = 0;
  pModel = 0;
  *&p.x = 0;
  *&p.z = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Hansya_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Hansya_tag, &v65);
      if ((LOBYTE(v65.m00) & 1) != 0)
        v6 = *&v65.m01;
      else
        v6 = &v65.m00 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v8);
  HNDL = v8;
  v9 = Allocate(sdf3DLight_t);
  sdf3DLight_t___ctor(v9);
  *&dst.x = 0;
  *&dst.z = 0;
  v10 = NewSpecific(sdf3DLight_t, 3u);
  v11 = v10;
  v11[4] = v9;
  *&v72.x = 0;
  *&v72.z = 0;
  memset(&aMatrix, 0, sizeof(aMatrix));
  v13 = Allocate(effBTL_SkillLight_t);
  effBTL_SkillLight_t___ctor(v13);
  pLight = v13;
  effBTL_SkillLight_t__Clear(v13);
  v14 = Allocate(effBTL_SkillModel_t);
  effBTL_SkillModel_t___ctor(v14);
  pModel = v14;
  effBTL_SkillModel_t__Clear(v14);
  v15 = Allocate(effBTL_SkillPositionPtr_t);
  effBTL_SkillPositionPtr_t___ctor(v15);
  pPosPtr = v15;
  sub_854690(&p.x, 0.0, 1.0, 0.0, 0.0);
  v17 = v3[2].klass;
  if (v17 >= 3)
  {
    if (v17 != 3)
      goto LABEL_43;
    ID = effBTLSkillGetID();
    if (ID >= SLODWORD(tbl->max_length))
    {
      v13->pos_ptr->target = 0;
      v13->pos_ptr->height = 2;
      v13->pos_ptr->direction = 0;
      v13->pos_ptr->radius = 0;
      v27 = -2130739072;
      v28 = -2144329198;
        goto LABEL_39;
    }
    else
    {
      v23 = effBTLSkillGetID();
      koukatype = tbl->m_Items[v23]->koukatype;
      v13->pos_ptr->target = 0;
      v13->pos_ptr->height = 2;
      v13->pos_ptr->direction = 0;
      v13->pos_ptr->radius = 0;
      if (koukatype)
      {
        v27 = -2130739072;
        v28 = -2144329198;
        {
LABEL_39:
          v13->diffuse = -2135640908;
          v13->ambient = v28;
          v13->color_anim->fade_in_frame = 0;
          v13->color_anim->fade_in_pattern = 0;
          v13->color_anim->fade_out_frame = 8;
          v13->color_anim->fade_out_pattern = 1;
          color_anim = v14->color_anim;
          v14->color = v27;
          color_anim->fade_in_frame = 0;
          v14->color_anim->fade_in_pattern = 0;
          v14->color_anim->fade_out_frame = 8;
          v14->color_anim->fade_out_pattern = 1;
          effBTLPointLightSet(&pLight, &v3[1].monitor);
          effBTLModelColorSet(&pModel, &v3[1].monitor);
LABEL_43:
          SDF_VU0__LOADVECTOR(*(v3[1].monitor + 4), 0);
          SDF_VU0__LOADVECTOR_B(p);
          Mult();
          ToMatrix();
          SDF_VU0__STOREMATRIX(&aMatrix);
          v65 = aMatrix;
          v64 = v65;
          dds3EffectPartSetRotateMatrix(&v3[2].monitor, &v64);
          v63 = aMatrix;
          dds3EffectPartSetRotateMatrix(&v3[3], &v63);
          *(v15 + 8) = 256;
          *(v15 + 18) = 0;
          *(v15 + 5) = 0;
          effBTLPartGetRotateMatrixPtr(&pPosPtr, &aMatrix);
          v62 = aMatrix;
          dds3EffectPartSetDirection(&v3[3], &v62);
          SDF_VU0__LOADVECTOR(*(v3[1].monitor + 4), 0);
          ToMatrix();
          SDF_VU0__LOADVECTOR(*(v3[1].monitor + 5), 0);
          SDF_VU0__SCALEVECTOR(*(v3[1].monitor + 27), 0);
          SDF_VU0__APPLYMATRIX();
          SDF_VU0__LOADVECTOR_B(*(v3[1].monitor + 3), 0);
          SDF_VU0__ADDVECTOR();
          SDF_VU0__STOREVECTOR(&v72);
          dds3EffectPartSetPosition(&v3[2].monitor, v72);
          monitor = v3[1].monitor;
          nbGetFormForward(monitor);
          SDF_VU0__STOREVECTOR(&v72);
          dds3EffectPartSetPosition(&v3[3], v72);
          v39 = effBTLSkillGetID();
          v41 = tbl;
          if (v39 >= SLODWORD(v41->max_length))
          {
            p_fields = &v9->fields;
          }
          else
          {
            v42 = effBTLSkillGetID();
            p_fields = &v9->fields;
            if (!v41->m_Items[v42]->koukatype)
            {
              sub_854930(&v9->fields, 0);
              sub_854930(&v9->fields, 1u);
LABEL_71:
              sub_854930(p_fields, 2u);
              sub_854930(p_fields, 3u);
              SDF_VU0__COPYVECTOR(&dst, v9->color);
              p_v = &v9->v;
              sub_854930(p_v, 0);
              sub_854930(p_v, 1u);
              sub_854930(p_v, 2u);
              sub_854930(p_v, 3u);
              else
              {
                Handle = dds3EffectPartGetHandle(&v3[2].monitor);
                if (Handle)
                {
LABEL_74:
                  v49 = Handle->klass;
                  if (Handle->klass->_2.typeHierarchyDepth < v50
                    || v49->_2.typeHierarchy[v50 - 1] != dds3ModelHandle_t)
                  {
                    sub_8FC2C0(v49->_1.element_class, dds3ModelHandle_t, &v65);
                    if ((LOBYTE(v65.m00) & 1) != 0)
                      v51 = *&v65.m01;
                    else
                      v51 = &v65.m00 + 1;
                    v52 = sub_8C4940(v51);
                  }
                }
              }
              HNDL = Handle;
              modelobj = Handle->modelRoot->modelobj;
              {
              }
              if (op_Inequality(modelobj, 0, 0))
              {
                Component_object = GetComponent_object_(HNDL->modelRoot->modelobj);
                {
                }
                if (op_Inequality(Component_object, 0, 0))
                  SethFrom(Component_object, v3[1].monitor);
              }
              x = dst.x;
              y = dst.y;
              z = dst.z;
              w = dst.w;
              v75.x = x;
              v75.y = y;
              v75.z = z;
              v75.w = w;
              mdlSetLightUnity(&HNDL, v11, v75);
              hDataa = HNDL;
              dds3EffectPartModelDraw(&hDataa);
              dds3EffectPartDraw(&v3[3]);
              v17 = v3[2].klass;
              goto LABEL_96;
            }
          }
          sub_854930(p_fields, 0);
          sub_854930(p_fields, 1u);
          goto LABEL_71;
        }
      }
      else
      {
        v27 = -2139062102;
        v28 = -2145182178;
          goto LABEL_39;
      }
    }
    goto LABEL_39;
  }
LABEL_96:
  LODWORD(v3[2].klass) = v17 + 1;
}

// 0x14cf070
u32 effBTLSys_Hansya_GetLength(void *hData) {
  return 15;
}

// 0x14cf190
void effBTLSys_Hansya_PartHandleCreate(void) {
  effBTLSystem_Part_HandleCreate(&effBTLSystem_Hansya_PartList, effBTLSystem_Hansya_PartList->max_length);
}

// 0x14cf200
void effBTLSys_Hansya_PartHandleDelete(void) {
  effBTLSystem_Part_HandleDelete(&effBTLSystem_Hansya_PartList, effBTLSystem_Hansya_PartList->max_length);
}

// 0x14ce560
void effBTLSys_Hansya_SetColor(void **hData, u32 abgr) {

}

// 0x14cf270
effBattleSystem_effBTLSystem_Kyusyuu_tag *effBTLSys_Kyusyuu_Create(nbFormation_t *pFormation) {
  effBattleSystem_effBTLSystem_Kyusyuu_tag_o *v3;
  struct effPartHandle_t_array *hRing;
  struct effBattleSystem_effBTLSystem_Part_tag_array *effBTLSystem_Kyusyuu_PartList;
  effPartHandle_t_o **p_hPart;
  s64 *v9;
  s64 *v10;
  struct effBattleSystem_effBTLSystem_Part_tag_array *v12;
  struct effPartHandle_t_array *v13;
  s64 *v15;
  s64 *v16;
  struct effBattleSystem_effBTLSystem_Part_tag_array *v18;
  struct effPartHandle_t_array *v19;
  s64 *v21;
  s64 *v22;
  struct effBattleSystem_effBTLSystem_Part_tag_array *v24;
  f32 ScalePtr;
  struct effPartHandle_t_array *v28;
  f32 v29;
  struct effPartHandle_t_array *v31;
  struct effPartHandle_t_array *v33;

  v3 = Allocate(effBattleSystem_effBTLSystem_Kyusyuu_tag);
  _ctor(v3, 0);
  v3->pFormation = pFormation;
  v3->frame = 0;
  hRing = v3->hRing;
  else
  {
    if (!LODWORD(effBTLSystem_Kyusyuu_PartList->max_length))
      goto LABEL_6;
  }
  p_hPart = &effBTLSystem_Kyusyuu_PartList->m_Items[0]->hPart;
  v9 = dds3EffectPartCopy(p_hPart, 0, 0);
  v10 = v9;
  hRing->m_Items[0] = v10;
  v12 = effBTLSystem_Kyusyuu_PartList;
  v13 = v3->hRing;
  v15 = dds3EffectPartCopy(&v12->m_Items[0]->hPart, 0, 0);
  v16 = v15;
  v13->m_Items[1] = v16;
  v18 = effBTLSystem_Kyusyuu_PartList;
  v19 = v3->hRing;
  v21 = dds3EffectPartCopy(&v18->m_Items[0]->hPart, 0, 0);
  v22 = v21;
  v19->m_Items[2] = v22;
  v24 = effBTLSystem_Kyusyuu_PartList;
  v3->hBlur = dds3EffectPartCopy(&v24->m_Items[1]->hPart, 0, 0);
  ScalePtr = effBTLSystem_GetScalePtr(&v3->pFormation);
  v28 = v3->hRing;
  v29 = ScalePtr;
  dds3EffectPartSetScale(v28->m_Items, ScalePtr);
  v31 = v3->hRing;
  dds3EffectPartSetScale(&v31->m_Items[1], v29);
  v33 = v3->hRing;
  dds3EffectPartSetScale(&v33->m_Items[2], v29);
  dds3EffectPartSetScale(&v3->hBlur, v29);
  return v3;
}

// 0x14d0490
void effBTLSys_Kyusyuu_DataFree(void) {
  effBTLSystem_Part_DataFree(&effBTLSystem_Kyusyuu_PartList, effBTLSystem_Kyusyuu_PartList->max_length);
}

// 0x14d0420
void effBTLSys_Kyusyuu_DataLoad(void) {
  effBTLSystem_Part_DataLoad(&effBTLSystem_Kyusyuu_PartList, effBTLSystem_Kyusyuu_PartList->max_length);
}

// 0x14cf600
void effBTLSys_Kyusyuu_Delete(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  Il2CppClass *v7;
  Il2CppClass *v9;
  Il2CppClass *v11;
  u64 v14[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Kyusyuu_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Kyusyuu_tag, v14);
      if ((v14[0] & 1) != 0)
        v5 = v14[2];
      else
        v5 = v14 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  dds3EffectPartDelete(&hData[2].monitor);
  v7 = hData[2].klass;
  dds3EffectPartDelete(&v7->_1.this_arg);
  v9 = hData[2].klass;
  dds3EffectPartDelete(&v9->_1.byval_arg.bits);
  v11 = hData[2].klass;
  dds3EffectPartDelete(&v11->_1.byval_arg);
}

// 0x14cf7d0
void effBTLSys_Kyusyuu_Delete2(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  Il2CppClass *v7;
  Il2CppClass *v9;
  Il2CppClass *v11;
  u64 v14[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Kyusyuu_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Kyusyuu_tag, v14);
      if ((v14[0] & 1) != 0)
        v5 = v14[2];
      else
        v5 = v14 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  dds3EffectPartDelete(&hData[2].monitor);
  v7 = hData[2].klass;
  dds3EffectPartDelete(&v7->_1.this_arg);
  v9 = hData[2].klass;
  dds3EffectPartDelete(&v9->_1.byval_arg.bits);
  v11 = hData[2].klass;
  dds3EffectPartDelete(&v11->_1.byval_arg);
}

// 0x14cf9e0
void effBTLSys_Kyusyuu_Draw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  u64 *v9;
  effBTL_SkillModel_t_o *v10;
  f32 m10;
  f32 m00;
  f32 m30;
  f32 m20;
  effBTL_SkillPositionPtr_t_o *v20;
  Il2CppClass *v22;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  Il2CppClass *v28;
  Il2CppClass *v31;
  Il2CppClass *v33;
  effBTL_SkillPositionPtr_t_o *v37;
  f32 v39;
  f32 v40;
  f32 v41;
  f32 v42;
  Il2CppClass *v43;
  Il2CppClass *v45;
  Il2CppClass *v48;
  Il2CppClass *v50;
  effBTL_SkillPositionPtr_t_o *v52;
  f32 v54;
  f32 v55;
  f32 v56;
  f32 v57;
  Il2CppClass *v58;
  Il2CppClass *v60;
  Il2CppClass *v63;
  Il2CppClass *v65;
  effBTL_SkillPositionPtr_t_o *v67;
  f32 v69;
  f32 v70;
  f32 v71;
  f32 v72;
  UnityEngine_Matrix4x4_o v74;
  UnityEngine_Matrix4x4_o v75;
  UnityEngine_Matrix4x4_o v76;
  UnityEngine_Matrix4x4_o v77;
  UnityEngine_Matrix4x4_o v78;
  UnityEngine_Matrix4x4_o v79;
  UnityEngine_Matrix4x4_o v80;
  UnityEngine_Matrix4x4_o v81;
  UnityEngine_Matrix4x4_o v82;
  UnityEngine_Matrix4x4_o v83;
  UnityEngine_Matrix4x4_o pMatrix;
  UnityEngine_Matrix4x4_o aMatrix;
  UnityEngine_Vector4_o pPos;
  effBTL_SkillModel_t_o *pModel;
  effBTL_SkillLight_t_o *pLight;
  effBTL_SkillPositionPtr_t_o *pPosPtr;
  UnityEngine_Vector4_o v90;
  UnityEngine_Vector4_o v91;
  UnityEngine_Vector4_o v92;
  UnityEngine_Vector4_o v93;
  UnityEngine_Vector4_o v94;

  pPosPtr = 0;
  pModel = 0;
  pLight = 0;
  *&pPos.x = 0;
  *&pPos.z = 0;
  memset(&aMatrix, 0, sizeof(aMatrix));
  memset(&pMatrix, 0, sizeof(pMatrix));
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Kyusyuu_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Kyusyuu_tag, &v83);
      if ((LOBYTE(v83.m00) & 1) != 0)
        v6 = *&v83.m01;
      else
        v6 = &v83.m00 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  *&v83.m20 = 0;
  *&v83.m00 = 0;
  sub_854690(&v83.m00, 0.0, 1.0, 0.0, 0.0);
  v8 = Allocate(effBTL_SkillPositionPtr_t);
  effBTL_SkillPositionPtr_t___ctor(v8);
  pPosPtr = v8;
  v9 = Allocate(effBTL_SkillLight_t);
  effBTL_SkillLight_t___ctor(v9);
  pLight = v9;
  effBTL_SkillLight_t__Clear(v9);
  v10 = Allocate(effBTL_SkillModel_t);
  effBTL_SkillModel_t___ctor(v10);
  pModel = v10;
  effBTL_SkillModel_t__Clear(v10);
  *&pPos.x = 0;
  *&pPos.z = 0;
  m10 = v83.m10;
  m00 = v83.m00;
  m30 = v83.m30;
  m20 = v83.m20;
  memset(&aMatrix, 0, sizeof(aMatrix));
  memset(&pMatrix, 0, sizeof(pMatrix));
  if (!LODWORD(v3[1].monitor))
  {
    *(v9[2] + 16) = 3;
    *(v9[2] + 17) = 3;
    *(v9[2] + 18) = 8;
    *(v9[2] + 20) = 0;
    v9[3] = 0x801E1E1E808A8A8ALL;
    *(v9[4] + 16) = 0;
    *(v9[4] + 20) = 2;
    *(v9[4] + 24) = 0;
    *(v9[4] + 28) = 2;
    v10->color = -2137265274;
    v10->color_anim->fade_in_frame = 0;
    v10->color_anim->fade_in_pattern = 2;
    v10->color_anim->fade_out_frame = 40;
    v10->color_anim->fade_out_pattern = 1;
    effBTLPointLightSet(&pLight, &v3[1]);
    effBTLModelColorSet(&pModel, &v3[1]);
  }
  SDF_VU0__LOADVECTOR(*&v3[1].klass->_1.element_class);
  v90.x = m00;
  v90.y = m10;
  v90.z = m20;
  v90.w = m30;
  SDF_VU0__LOADVECTOR_B(v90);
  Mult();
  ToMatrix();
  SDF_VU0__STOREMATRIX(&aMatrix);
  v20 = pPosPtr;
  *&pPosPtr->target = 256;
  v20->direction = 9;
  v20->radius = 0;
  effBTLPartGetPositionPtr(&v3[1], &pPosPtr, &pPos);
  v22 = v3[2].klass;
  x = pPos.x;
  y = pPos.y;
  z = pPos.z;
  w = pPos.w;
  else if (!LODWORD(v22->_1.namespaze))
  {
    goto LABEL_24;
  }
  v91.x = x;
  v91.y = y;
  v91.z = z;
  v91.w = w;
  dds3EffectPartSetPosition(&v22->_1.byval_arg, v91);
  v28 = v3[2].klass;
  v83 = aMatrix;
  v82 = v83;
  dds3EffectPartSetRotateMatrix(&v28->_1.byval_arg, &v82);
  effBTLPartGetRotateMatrixPtr(&pPosPtr, &pMatrix);
  v31 = v3[2].klass;
  v81 = pMatrix;
  v80 = v81;
  dds3EffectPartSetDirection(&v31->_1.byval_arg, &v80);
  v33 = v3[2].klass;
  dds3EffectPartDraw(&v33->_1.byval_arg);
  if (LODWORD(v3[1].monitor) >= 4)
  {
    v37 = pPosPtr;
    *&pPosPtr->target = 1024;
    v37->direction = 9;
    v37->radius = 0;
    effBTLPartGetPositionPtr(&v3[1], &pPosPtr, &pPos);
    v40 = pPos.x;
    v39 = pPos.y;
    v42 = pPos.z;
    v41 = pPos.w;
    v43 = v3[2].klass;
    v92.x = v40;
    v92.y = v39;
    v92.z = v42;
    v92.w = v41;
    dds3EffectPartSetPosition(&v43->_1.byval_arg.bits, v92);
    v45 = v3[2].klass;
    v83 = aMatrix;
    v79 = v83;
    dds3EffectPartSetRotateMatrix(&v45->_1.byval_arg.bits, &v79);
    effBTLPartGetRotateMatrixPtr(&pPosPtr, &pMatrix);
    v48 = v3[2].klass;
    v81 = pMatrix;
    v78 = v81;
    dds3EffectPartSetDirection(&v48->_1.byval_arg.bits, &v78);
    v50 = v3[2].klass;
    dds3EffectPartDraw(&v50->_1.byval_arg.bits);
    if (LODWORD(v3[1].monitor) >= 8)
    {
      v52 = pPosPtr;
      *&pPosPtr->target = 1024;
      v52->direction = 9;
      v52->radius = 0;
      effBTLPartGetPositionPtr(&v3[1], &pPosPtr, &pPos);
      v55 = pPos.x;
      v54 = pPos.y;
      v57 = pPos.z;
      v56 = pPos.w;
      v58 = v3[2].klass;
      v93.x = v55;
      v93.y = v54;
      v93.z = v57;
      v93.w = v56;
      dds3EffectPartSetPosition(&v58->_1.this_arg, v93);
      v60 = v3[2].klass;
      v83 = aMatrix;
      v77 = v83;
      dds3EffectPartSetRotateMatrix(&v60->_1.this_arg, &v77);
      effBTLPartGetRotateMatrixPtr(&pPosPtr, &pMatrix);
      v63 = v3[2].klass;
      v81 = pMatrix;
      v76 = v81;
      dds3EffectPartSetDirection(&v63->_1.this_arg, &v76);
      v65 = v3[2].klass;
      dds3EffectPartDraw(&v65->_1.this_arg);
    }
  }
  v67 = pPosPtr;
  *&pPosPtr->target = 256;
  v67->direction = 8;
  v67->radius = 0;
  effBTLPartGetPositionPtr(&v3[1], &pPosPtr, &pPos);
  v70 = pPos.x;
  v69 = pPos.y;
  v72 = pPos.z;
  v71 = pPos.w;
  v94.x = v70;
  v94.y = v69;
  v94.z = v72;
  v94.w = v71;
  dds3EffectPartSetPosition(&v3[2].monitor, v94);
  v75 = aMatrix;
  dds3EffectPartSetRotateMatrix(&v3[2].monitor, &v75);
  effBTLPartGetRotateMatrixPtr(&pPosPtr, &pMatrix);
  v74 = pMatrix;
  dds3EffectPartSetDirection(&v3[2].monitor, &v74);
  dds3EffectPartDraw(&v3[2].monitor);
  ++LODWORD(v3[1].monitor);
}

// 0x14d03e0
u32 effBTLSys_Kyusyuu_GetLength(void *hData) {
  return 25;
}

// 0x14d0500
void effBTLSys_Kyusyuu_PartHandleCreate(void) {
  effBTLSystem_Part_HandleCreate(&effBTLSystem_Kyusyuu_PartList, effBTLSystem_Kyusyuu_PartList->max_length);
}

// 0x14d0570
void effBTLSys_Kyusyuu_PartHandleDelete(void) {
  effBTLSystem_Part_HandleDelete(&effBTLSystem_Kyusyuu_PartList, effBTLSystem_Kyusyuu_PartList->max_length);
}

// 0x14cf9a0
void effBTLSys_Kyusyuu_SetColor(void **hData, u32 abgr) {

}

// 0x14d42c0
effBattleSystem_effBTLSystem_Nego_Kaihuku_tag *effBTLSys_Nego_Kaihuku_Create(nbFormation_t *pFormation) {
  effBattleSystem_effBTLSystem_Nego_Kaihuku_tag_o *v3;
  struct effBattleSystem_effBTLSystem_Part_tag_array *effBTLSystem_Nego_Kaihuku_PartList;
  effBTL_t_o **p_hBED;

  v3 = Allocate(effBattleSystem_effBTLSystem_Nego_Kaihuku_tag);
  _ctor(v3, 0);
  v3->pFormation = pFormation;
  v3->frame = 0;
  else
  {
    if (!LODWORD(effBTLSystem_Nego_Kaihuku_PartList->max_length))
      goto LABEL_6;
  }
  p_hBED = &effBTLSystem_Nego_Kaihuku_PartList->m_Items[0]->hBED;
  v3->hBEDCut = effBTLCutCreate(p_hBED, 3u, pFormation, 0);
  return v3;
}

// 0x14d4930
void effBTLSys_Nego_Kaihuku_DataFree(void) {
  effBTLSystem_Part_DataFree(&effBTLSystem_Nego_Kaihuku_PartList, effBTLSystem_Nego_Kaihuku_PartList->max_length);
}

// 0x14d48c0
void effBTLSys_Nego_Kaihuku_DataLoad(void) {
  effBTLSystem_Part_DataLoad(&effBTLSystem_Nego_Kaihuku_PartList, effBTLSystem_Nego_Kaihuku_PartList->max_length);
}

// 0x14d43d0
void effBTLSys_Nego_Kaihuku_Delete(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  effBTLCutHandle_t_o **v7;
  u64 v9[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Nego_Kaihuku_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Nego_Kaihuku_tag, v9);
      if ((v9[0] & 1) != 0)
        v5 = v9[2];
      else
        v5 = v9 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  v7 = &hData[2];
  effBTLCutDelete(v7);
}

// 0x14d4520
void effBTLSys_Nego_Kaihuku_Delete2(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  effBTLCutHandle_t_o **v7;
  u64 v9[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Nego_Kaihuku_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Nego_Kaihuku_tag, v9);
      if ((v9[0] & 1) != 0)
        v5 = v9[2];
      else
        v5 = v9 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  v7 = &hData[2];
  effBTLCutDelete(v7);
}

// 0x14d4670
void effBTLSys_Nego_Kaihuku_Draw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v8[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Nego_Kaihuku_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Nego_Kaihuku_tag, v8);
      if ((v8[0] & 1) != 0)
        v6 = v8[2];
      else
        v6 = v8 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  effBTLCutDraw(&v3[2]);
  ++LODWORD(v3[1].monitor);
}

// 0x14d47a0
u32 effBTLSys_Nego_Kaihuku_GetLength(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  effBTLCutHandle_t_o **v7;
  u64 v9[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Nego_Kaihuku_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Nego_Kaihuku_tag, v9);
      if ((v9[0] & 1) != 0)
        v5 = v9[2];
      else
        v5 = v9 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  v7 = &hData[2];
  return effBTLCutGetCutEndFrame(v7);
}

// 0x14d49a0
void effBTLSys_Nego_Kaihuku_PartHandleCreate(void) {
  effBTLSystem_Part_HandleCreate(&effBTLSystem_Nego_Kaihuku_PartList, effBTLSystem_Nego_Kaihuku_PartList->max_length);
}

// 0x14d4a10
void effBTLSys_Nego_Kaihuku_PartHandleDelete(void) {
  effBTLSystem_Part_HandleDelete(&effBTLSystem_Nego_Kaihuku_PartList, effBTLSystem_Nego_Kaihuku_PartList->max_length);
}

// 0x14d4a80
effBattleSystem_effBTLSystem_Nego_Kyusyu_tag *effBTLSys_Nego_Kyusyu_Create(nbFormation_t *pFormation) {
  effBattleSystem_effBTLSystem_Nego_Kyusyu_tag_o *v3;
  struct effBattleSystem_effBTLSystem_Part_tag_array *effBTLSystem_Nego_Kyusyu_PartList;
  effBTL_t_o **p_hBED;

  v3 = Allocate(effBattleSystem_effBTLSystem_Nego_Kyusyu_tag);
  _ctor(v3, 0);
  v3->pFormation = pFormation;
  v3->frame = 0;
  else
  {
    if (!LODWORD(effBTLSystem_Nego_Kyusyu_PartList->max_length))
      goto LABEL_6;
  }
  p_hBED = &effBTLSystem_Nego_Kyusyu_PartList->m_Items[0]->hBED;
  v3->hBEDCut = effBTLCutCreate(p_hBED, 3u, pFormation, 0);
  return v3;
}

// 0x14d50f0
void effBTLSys_Nego_Kyusyu_DataFree(void) {
  effBTLSystem_Part_DataFree(&effBTLSystem_Nego_Kyusyu_PartList, effBTLSystem_Nego_Kyusyu_PartList->max_length);
}

// 0x14d5080
void effBTLSys_Nego_Kyusyu_DataLoad(void) {
  effBTLSystem_Part_DataLoad(&effBTLSystem_Nego_Kyusyu_PartList, effBTLSystem_Nego_Kyusyu_PartList->max_length);
}

// 0x14d4b90
void effBTLSys_Nego_Kyusyu_Delete(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  effBTLCutHandle_t_o **v7;
  u64 v9[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Nego_Kyusyu_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Nego_Kyusyu_tag, v9);
      if ((v9[0] & 1) != 0)
        v5 = v9[2];
      else
        v5 = v9 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  v7 = &hData[2];
  effBTLCutDelete(v7);
}

// 0x14d4ce0
void effBTLSys_Nego_Kyusyu_Delete2(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  effBTLCutHandle_t_o **v7;
  u64 v9[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Nego_Kyusyu_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Nego_Kyusyu_tag, v9);
      if ((v9[0] & 1) != 0)
        v5 = v9[2];
      else
        v5 = v9 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  v7 = &hData[2];
  effBTLCutDelete(v7);
}

// 0x14d4e30
void effBTLSys_Nego_Kyusyu_Draw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v8[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Nego_Kyusyu_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Nego_Kyusyu_tag, v8);
      if ((v8[0] & 1) != 0)
        v6 = v8[2];
      else
        v6 = v8 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  effBTLCutDraw(&v3[2]);
  ++LODWORD(v3[1].monitor);
}

// 0x14d4f60
u32 effBTLSys_Nego_Kyusyu_GetLength(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  effBTLCutHandle_t_o **v7;
  u64 v9[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Nego_Kyusyu_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Nego_Kyusyu_tag, v9);
      if ((v9[0] & 1) != 0)
        v5 = v9[2];
      else
        v5 = v9 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  v7 = &hData[2];
  return effBTLCutGetCutEndFrame(v7);
}

// 0x14d5160
void effBTLSys_Nego_Kyusyu_PartHandleCreate(void) {
  effBTLSystem_Part_HandleCreate(&effBTLSystem_Nego_Kyusyu_PartList, effBTLSystem_Nego_Kyusyu_PartList->max_length);
}

// 0x14d51d0
void effBTLSys_Nego_Kyusyu_PartHandleDelete(void) {
  effBTLSystem_Part_HandleDelete(&effBTLSystem_Nego_Kyusyu_PartList, effBTLSystem_Nego_Kyusyu_PartList->max_length);
}

// 0x14d5240
effBattleSystem_effBTLSystem_Nego_Stone_tag *effBTLSys_Nego_Stone_Create(nbFormation_t *pFormation) {
  effBattleSystem_effBTLSystem_Nego_Stone_tag_o *v3;
  struct effBattleSystem_effBTLSystem_Part_tag_array *effBTLSystem_Nego_Stone_PartList;
  effBTL_t_o **p_hBED;

  v3 = Allocate(effBattleSystem_effBTLSystem_Nego_Stone_tag);
  _ctor(v3, 0);
  v3->pFormation = pFormation;
  v3->frame = 0;
  else
  {
    if (!LODWORD(effBTLSystem_Nego_Stone_PartList->max_length))
      goto LABEL_6;
  }
  p_hBED = &effBTLSystem_Nego_Stone_PartList->m_Items[0]->hBED;
  v3->hBEDCut = effBTLCutCreate(p_hBED, 3u, pFormation, 0);
  return v3;
}

// 0x14d58b0
void effBTLSys_Nego_Stone_DataFree(void) {
  effBTLSystem_Part_DataFree(&effBTLSystem_Nego_Stone_PartList, effBTLSystem_Nego_Stone_PartList->max_length);
}

// 0x14d5840
void effBTLSys_Nego_Stone_DataLoad(void) {
  effBTLSystem_Part_DataLoad(&effBTLSystem_Nego_Stone_PartList, effBTLSystem_Nego_Stone_PartList->max_length);
}

// 0x14d5350
void effBTLSys_Nego_Stone_Delete(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  effBTLCutHandle_t_o **v7;
  u64 v9[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Nego_Stone_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Nego_Stone_tag, v9);
      if ((v9[0] & 1) != 0)
        v5 = v9[2];
      else
        v5 = v9 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  v7 = &hData[2];
  effBTLCutDelete(v7);
}

// 0x14d54a0
void effBTLSys_Nego_Stone_Delete2(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  effBTLCutHandle_t_o **v7;
  u64 v9[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Nego_Stone_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Nego_Stone_tag, v9);
      if ((v9[0] & 1) != 0)
        v5 = v9[2];
      else
        v5 = v9 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  v7 = &hData[2];
  effBTLCutDelete(v7);
}

// 0x14d55f0
void effBTLSys_Nego_Stone_Draw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v8[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Nego_Stone_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Nego_Stone_tag, v8);
      if ((v8[0] & 1) != 0)
        v6 = v8[2];
      else
        v6 = v8 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  effBTLCutDraw(&v3[2]);
  ++LODWORD(v3[1].monitor);
}

// 0x14d5720
u32 effBTLSys_Nego_Stone_GetLength(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  effBTLCutHandle_t_o **v7;
  u64 v9[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Nego_Stone_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Nego_Stone_tag, v9);
      if ((v9[0] & 1) != 0)
        v5 = v9[2];
      else
        v5 = v9 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  v7 = &hData[2];
  return effBTLCutGetCutEndFrame(v7);
}

// 0x14d5920
void effBTLSys_Nego_Stone_PartHandleCreate(void) {
  effBTLSystem_Part_HandleCreate(&effBTLSystem_Nego_Stone_PartList, effBTLSystem_Nego_Stone_PartList->max_length);
}

// 0x14d5990
void effBTLSys_Nego_Stone_PartHandleDelete(void) {
  effBTLSystem_Part_HandleDelete(&effBTLSystem_Nego_Stone_PartList, effBTLSystem_Nego_Stone_PartList->max_length);
}

// 0x14c76d0
effBattleSystem_effBTLSystem_Panic_tag *effBTLSys_Panic_Create(nbFormation_t *pFormation) {
  effBattleSystem_effBTLSystem_Panic_tag_o *v3;
  struct effBattleSystem_effBTLSystem_Part_tag_array *effBTLSystem_Panic_PartList;
  effPartHandle_t_o **p_hPart;
  f32 ScalePtr;

  v3 = Allocate(effBattleSystem_effBTLSystem_Panic_tag);
  _ctor(v3, 0);
  v3->pFormation = pFormation;
  v3->frame = 0;
  else
  {
    if (!LODWORD(effBTLSystem_Panic_PartList->max_length))
      goto LABEL_6;
  }
  p_hPart = &effBTLSystem_Panic_PartList->m_Items[0]->hPart;
  v3->hPartD3P = dds3EffectPartCopy(p_hPart, 0, 0);
  ScalePtr = effBTLSystem_GetScalePtr(&v3->pFormation);
  dds3EffectPartSetScale(&v3->hPartD3P, ScalePtr);
  return v3;
}

// 0x14c7f30
void effBTLSys_Panic_DataFree(void) {
  effBTLSystem_Part_DataFree(&effBTLSystem_Panic_PartList, effBTLSystem_Panic_PartList->max_length);
}

// 0x14c7ec0
void effBTLSys_Panic_DataLoad(void) {
  effBTLSystem_Part_DataLoad(&effBTLSystem_Panic_PartList, effBTLSystem_Panic_PartList->max_length);
}

// 0x14c77f0
void effBTLSys_Panic_Delete(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  Il2CppClass *v7;
  evtUnitHandle_t_o **p_implementedInterfaces;
  Il2CppClass **implementedInterfaces;
  effPartHandle_t_o **v10;
  u64 v11[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Panic_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Panic_tag, v11);
      if ((v11[0] & 1) != 0)
        v5 = v11[2];
      else
        v5 = v11 + 1;
      v6 = sub_8C4940(v5);
    }
  }
LABEL_14:
  v7 = hData[1].klass;
  implementedInterfaces = v7->_1.implementedInterfaces;
  p_implementedInterfaces = &v7->_1.implementedInterfaces;
  if (implementedInterfaces)
  {
    evtSetUnitColorRGB(p_implementedInterfaces, 4u, 0x80808080);
    LODWORD(hData[1].klass->rgctx_data) = (BYTE3(hData[1].klass->rgctx_data) << 24) | 0x808080;
  }
  v10 = &hData[2];
  dds3EffectPartDelete(v10);
}

// 0x14c79b0
void effBTLSys_Panic_Delete2(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  effPartHandle_t_o **v7;
  u64 v9[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Panic_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Panic_tag, v9);
      if ((v9[0] & 1) != 0)
        v5 = v9[2];
      else
        v5 = v9 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  v7 = &hData[2];
  dds3EffectPartDelete(v7);
}

// 0x14c7c30
void effBTLSys_Panic_Draw(void **hData) {
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  Il2CppClass *v9;
  evtUnitHandle_t_o **p_implementedInterfaces;
  Il2CppClass **implementedInterfaces;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  UnityEngine_Vector4_o p;
  u64 v18[3];
  UnityEngine_Vector4_o v19;

  *&p.x = 0;
  *&p.z = 0;
  v4 = *hData;
  if (*hData)
  {
    klass = v4->klass;
    if (v4->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Panic_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Panic_tag, v18);
      if ((v18[0] & 1) != 0)
        v7 = v18[2];
      else
        v7 = v18 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  *&p.x = 0;
  *&p.z = 0;
  if (!LODWORD(v4[1].monitor))
  {
    v9 = v4[1].klass;
    implementedInterfaces = v9->_1.implementedInterfaces;
    p_implementedInterfaces = &v9->_1.implementedInterfaces;
    if (implementedInterfaces)
    {
      evtSetUnitColorRGB(p_implementedInterfaces, 4u, 0x802C5C7F);
      LODWORD(v4[1].klass->rgctx_data) = (BYTE3(v4[1].klass->rgctx_data) << 24) | 0x2C5C7F;
    }
  }
  effBTLModelGetMarkPosition2(&v4[1], 2u);
  SDF_VU0__STOREVECTOR(&p);
  x = p.x;
  y = p.y;
  z = p.z;
  w = p.w;
  v19.x = x;
  v19.y = y;
  v19.z = z;
  v19.w = w;
  dds3EffectPartSetPosition(&v4[2], v19);
  dds3EffectPartDraw(&v4[2]);
  ++LODWORD(v4[1].monitor);
}

// 0x14c7e80
u32 effBTLSys_Panic_GetLength(void *hData) {
  return 0;
}

// 0x14c7fa0
void effBTLSys_Panic_PartHandleCreate(void) {
  effBTLSystem_Part_HandleCreate(&effBTLSystem_Panic_PartList, effBTLSystem_Panic_PartList->max_length);
}

// 0x14c8010
void effBTLSys_Panic_PartHandleDelete(void) {
  effBTLSystem_Part_HandleDelete(&effBTLSystem_Panic_PartList, effBTLSystem_Panic_PartList->max_length);
}

// 0x14c7b00
void effBTLSys_Panic_SetColor(void **hData, u32 abgr) {
  u32 v3;
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  effPartHandle_t_o **v10;
  u64 v11[3];

  v3 = abgr;
  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Panic_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Panic_tag, v11);
      if ((v11[0] & 1) != 0)
        v8 = v11[2];
      else
        v8 = v11 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = &v5[2];
  dds3EffectPartSetColor(v10, v3);
}

// 0x14caa70
effBattleSystem_effBTLSystem_Paralyze_tag *effBTLSys_Paralyze_Create(nbFormation_t *pFormation) {
  u64 *v3;
  f32 ScalePtr;
  Il2CppObject *hData;

  hData = 0;
  v3 = Allocate(effBattleSystem_effBTLSystem_Paralyze_tag);
  _ctor(v3, 0);
  v3[2] = pFormation;
  *(v3 + 6) = 0;
  v3[4] = effPCPThunderSpherePolyLowCreate(effBTLSystem_Paralyze_ThunderSpherePolyLowParam);
  ScalePtr = effBTLSystem_GetScalePtr(v3 + 2);
  hData = v3[4];
  effPCPThunderSpherePolyLowSetScale(&hData, ScalePtr);
  effPCPThunderSpherePolyLowGetParam(v3[4])->height = (*(v3[2] + 100) * *(v3[2] + 108)) * 0.85;
  return v3;
}

// 0x14cb220
void effBTLSys_Paralyze_DataFree(void) {
  effBTLSystem_Part_DataFree(&effBTLSystem_Paralyze_PartList, effBTLSystem_Paralyze_PartList->max_length);
}

// 0x14cb1b0
void effBTLSys_Paralyze_DataLoad(void) {
  effBTLSystem_Part_DataLoad(&effBTLSystem_Paralyze_PartList, effBTLSystem_Paralyze_PartList->max_length);
}

// 0x14cab70
void effBTLSys_Paralyze_Delete(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  Il2CppClass *v7;
  evtUnitHandle_t_o **p_implementedInterfaces;
  Il2CppClass **implementedInterfaces;
  Il2CppClass *v10;
  u64 v11[3];

  v10 = 0;
  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Paralyze_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Paralyze_tag, v11);
      if ((v11[0] & 1) != 0)
        v5 = v11[2];
      else
        v5 = v11 + 1;
      v6 = sub_8C4940(v5);
    }
  }
LABEL_14:
  v7 = hData[1].klass;
  implementedInterfaces = v7->_1.implementedInterfaces;
  p_implementedInterfaces = &v7->_1.implementedInterfaces;
  if (implementedInterfaces)
  {
    evtSetUnitColorRGB(p_implementedInterfaces, 4u, 0x80808080);
    LODWORD(hData[1].klass->rgctx_data) = (BYTE3(hData[1].klass->rgctx_data) << 24) | 0x808080;
  }
  v10 = hData[2].klass;
  effPCPThunderSpherePolyLowDelete(&v10);
}

// 0x14cad20
void effBTLSys_Paralyze_Delete2(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppClass *v8;
  u64 v9[3];

  v8 = 0;
  klass = hData->klass;
  if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Paralyze_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Paralyze_tag, v9);
    if ((v9[0] & 1) != 0)
      v6 = v9[2];
    else
      v6 = v9 + 1;
    v7 = sub_8C4940(v6);
  }
  v8 = hData[2].klass;
  effPCPThunderSpherePolyLowDelete(&v8);
}

// 0x14caf60
void effBTLSys_Paralyze_Draw(void **hData) {
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  Il2CppClass *v9;
  evtUnitHandle_t_o **p_implementedInterfaces;
  Il2CppClass **implementedInterfaces;
  Il2CppClass *v12;
  UnityEngine_Vector4_o p;
  u64 v14[3];

  *&p.x = 0;
  *&p.z = 0;
  v12 = 0;
  v4 = *hData;
  if (*hData)
  {
    klass = v4->klass;
    if (v4->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Paralyze_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Paralyze_tag, v14);
      if ((v14[0] & 1) != 0)
        v7 = v14[2];
      else
        v7 = v14 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  *&p.x = 0;
  *&p.z = 0;
  if (!LODWORD(v4[1].monitor))
  {
    v9 = v4[1].klass;
    implementedInterfaces = v9->_1.implementedInterfaces;
    p_implementedInterfaces = &v9->_1.implementedInterfaces;
    if (implementedInterfaces)
    {
      evtSetUnitColorRGB(p_implementedInterfaces, 4u, 0x802C4D7F);
      LODWORD(v4[1].klass->rgctx_data) = (BYTE3(v4[1].klass->rgctx_data) << 24) | 0x2C4D7F;
    }
  }
  effBTLModelGetMarkPosition2(&v4[1], 0);
  SDF_VU0__STOREVECTOR(&p);
  v12 = v4[2].klass;
  effPCPThunderSpherePolyLowSetPosition(&v12, p);
  effPCPThunderSpherePolyLowDraw(&v12);
  ++LODWORD(v4[1].monitor);
}

// 0x14cb170
u32 effBTLSys_Paralyze_GetLength(void *hData) {
  return 0;
}

// 0x14cb290
void effBTLSys_Paralyze_PartHandleCreate(void) {
  effBTLSystem_Part_HandleCreate(&effBTLSystem_Paralyze_PartList, effBTLSystem_Paralyze_PartList->max_length);
}

// 0x14cb300
void effBTLSys_Paralyze_PartHandleDelete(void) {
  effBTLSystem_Part_HandleDelete(&effBTLSystem_Paralyze_PartList, effBTLSystem_Paralyze_PartList->max_length);
}

// 0x14cae50
void effBTLSys_Paralyze_SetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  Il2CppObject *v9[3];
  Il2CppObject *hDataa;

  hDataa = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Paralyze_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Paralyze_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  hDataa = (*hData)[2].klass;
  effPCPThunderSpherePolyLowSetColor(&hDataa, abgr);
}

// 0x14c9650
effBattleSystem_effBTLSystem_Poison_tag *effBTLSys_Poison_Create(nbFormation_t *pFormation) {
  effBattleSystem_effBTLSystem_Poison_tag_o *v3;
  struct evtUnitHandle_t_o *hunit;
  struct effBattleSystem_effBTLSystem_Part_tag_array *effBTLSystem_Poison_PartList;
  effPartHandle_t_o **p_hPart;
  f32 ScalePtr;

  v3 = Allocate(effBattleSystem_effBTLSystem_Poison_tag);
  _ctor(v3, 0);
  v3->pFormation = pFormation;
  v3->frame = 0;
  hunit = pFormation->hunit;
  if (hunit)
    v3->hModel = hunit->Model;
  else
    v3->hModel = 0;
  else
  {
    if (!LODWORD(effBTLSystem_Poison_PartList->max_length))
      goto LABEL_9;
  }
  p_hPart = &effBTLSystem_Poison_PartList->m_Items[0]->hPart;
  v3->hPartD3P = dds3EffectPartCopy(p_hPart, 0, 0);
  ScalePtr = effBTLSystem_GetScalePtr(&v3->pFormation);
  dds3EffectPartSetScale(&v3->hPartD3P, ScalePtr);
  return v3;
}

// 0x14c9ed0
void effBTLSys_Poison_DataFree(void) {
  effBTLSystem_Part_DataFree(&effBTLSystem_Poison_PartList, effBTLSystem_Poison_PartList->max_length);
}

// 0x14c9e60
void effBTLSys_Poison_DataLoad(void) {
  effBTLSystem_Part_DataLoad(&effBTLSystem_Poison_PartList, effBTLSystem_Poison_PartList->max_length);
}

// 0x14c9790
void effBTLSys_Poison_Delete(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  Il2CppClass *v7;
  evtUnitHandle_t_o **p_implementedInterfaces;
  Il2CppClass **implementedInterfaces;
  effPartHandle_t_o **v10;
  u64 v11[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Poison_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Poison_tag, v11);
      if ((v11[0] & 1) != 0)
        v5 = v11[2];
      else
        v5 = v11 + 1;
      v6 = sub_8C4940(v5);
    }
  }
LABEL_14:
  v7 = hData[1].klass;
  implementedInterfaces = v7->_1.implementedInterfaces;
  p_implementedInterfaces = &v7->_1.implementedInterfaces;
  if (implementedInterfaces)
  {
    evtSetUnitColorRGB(p_implementedInterfaces, 4u, 0x80808080);
    LODWORD(hData[1].klass->rgctx_data) = (BYTE3(hData[1].klass->rgctx_data) << 24) | 0x808080;
  }
  v10 = &hData[2];
  dds3EffectPartDelete(v10);
}

// 0x14c9950
void effBTLSys_Poison_Delete2(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  effPartHandle_t_o **v7;
  u64 v9[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Poison_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Poison_tag, v9);
      if ((v9[0] & 1) != 0)
        v5 = v9[2];
      else
        v5 = v9 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  v7 = &hData[2];
  dds3EffectPartDelete(v7);
}

// 0x14c9bd0
void effBTLSys_Poison_Draw(void **hData) {
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  Il2CppClass *v9;
  evtUnitHandle_t_o **p_implementedInterfaces;
  Il2CppClass **implementedInterfaces;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  UnityEngine_Vector4_o p;
  u64 v18[3];
  UnityEngine_Vector4_o v19;

  *&p.x = 0;
  *&p.z = 0;
  v4 = *hData;
  if (*hData)
  {
    klass = v4->klass;
    if (v4->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Poison_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Poison_tag, v18);
      if ((v18[0] & 1) != 0)
        v7 = v18[2];
      else
        v7 = v18 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  *&p.x = 0;
  *&p.z = 0;
  if (!LODWORD(v4[1].monitor))
  {
    v9 = v4[1].klass;
    implementedInterfaces = v9->_1.implementedInterfaces;
    p_implementedInterfaces = &v9->_1.implementedInterfaces;
    if (implementedInterfaces)
    {
      evtSetUnitColorRGB(p_implementedInterfaces, 4u, 0x80521D36);
      LODWORD(v4[1].klass->rgctx_data) = (BYTE3(v4[1].klass->rgctx_data) << 24) | 0x521D36;
    }
  }
  effBTLModelGetMarkPosition2(&v4[1], 2u);
  SDF_VU0__STOREVECTOR(&p);
  x = p.x;
  y = p.y;
  z = p.z;
  w = p.w;
  v19.x = x;
  v19.y = y;
  v19.z = z;
  v19.w = w;
  dds3EffectPartSetPosition(&v4[2], v19);
  dds3EffectPartDraw(&v4[2]);
  ++LODWORD(v4[1].monitor);
}

// 0x14c9e20
u32 effBTLSys_Poison_GetLength(void *hData) {
  return 0;
}

// 0x14c9f40
void effBTLSys_Poison_PartHandleCreate(void) {
  effBTLSystem_Part_HandleCreate(&effBTLSystem_Poison_PartList, effBTLSystem_Poison_PartList->max_length);
}

// 0x14c9fb0
void effBTLSys_Poison_PartHandleDelete(void) {
  effBTLSystem_Part_HandleDelete(&effBTLSystem_Poison_PartList, effBTLSystem_Poison_PartList->max_length);
}

// 0x14c9aa0
void effBTLSys_Poison_SetColor(void **hData, u32 abgr) {
  u32 v3;
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  effPartHandle_t_o **v10;
  u64 v11[3];

  v3 = abgr;
  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Poison_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Poison_tag, v11);
      if ((v11[0] & 1) != 0)
        v8 = v11[2];
      else
        v8 = v11 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = &v5[2];
  dds3EffectPartSetColor(v10, v3);
}

// 0x14d05e0
effBattleSystem_effBTLSystem_Return_tag *effBTLSys_Return_Create(nbFormation_t *pFormation) {
  effBattleSystem_effBTLSystem_Return_tag_o *v3;
  struct effBattleSystem_effBTLSystem_Part_tag_array *effBTLSystem_Return_PartList;
  effBTL_t_o **p_hBED;

  v3 = Allocate(effBattleSystem_effBTLSystem_Return_tag);
  _ctor(v3, 0);
  v3->pFormation = pFormation;
  v3->frame = 0;
  else
  {
    if (!LODWORD(effBTLSystem_Return_PartList->max_length))
      goto LABEL_6;
  }
  p_hBED = &effBTLSystem_Return_PartList->m_Items[0]->hBED;
  v3->hBEDCut = effBTLCutCreate(p_hBED, 3u, pFormation, 0);
  return v3;
}

// 0x14d0c90
void effBTLSys_Return_DataFree(void) {
  effBTLSystem_Part_DataFree(&effBTLSystem_Return_PartList, effBTLSystem_Return_PartList->max_length);
}

// 0x14d0c20
void effBTLSys_Return_DataLoad(void) {
  effBTLSystem_Part_DataLoad(&effBTLSystem_Return_PartList, effBTLSystem_Return_PartList->max_length);
}

// 0x14d06f0
void effBTLSys_Return_Delete(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  effBTLCutHandle_t_o **v7;
  u64 v9[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Return_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Return_tag, v9);
      if ((v9[0] & 1) != 0)
        v5 = v9[2];
      else
        v5 = v9 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  v7 = &hData[2];
  effBTLCutDelete(v7);
}

// 0x14d0840
void effBTLSys_Return_Delete2(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  effBTLCutHandle_t_o **v7;
  u64 v9[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Return_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Return_tag, v9);
      if ((v9[0] & 1) != 0)
        v5 = v9[2];
      else
        v5 = v9 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  v7 = &hData[2];
  effBTLCutDelete(v7);
}

// 0x14d09d0
void effBTLSys_Return_Draw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v8[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Return_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Return_tag, v8);
      if ((v8[0] & 1) != 0)
        v6 = v8[2];
      else
        v6 = v8 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  effBTLCutDraw(&v3[2]);
  ++LODWORD(v3[1].monitor);
}

// 0x14d0b00
u32 effBTLSys_Return_GetLength(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  effBTLCutHandle_t_o **v7;
  u64 v9[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Return_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Return_tag, v9);
      if ((v9[0] & 1) != 0)
        v5 = v9[2];
      else
        v5 = v9 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  v7 = &hData[2];
  return effBTLCutGetCutEndFrame(v7);
}

// 0x14d0d00
void effBTLSys_Return_PartHandleCreate(void) {
  effBTLSystem_Part_HandleCreate(&effBTLSystem_Return_PartList, effBTLSystem_Return_PartList->max_length);
}

// 0x14d0d70
void effBTLSys_Return_PartHandleDelete(void) {
  effBTLSystem_Part_HandleDelete(&effBTLSystem_Return_PartList, effBTLSystem_Return_PartList->max_length);
}

// 0x14d0990
void effBTLSys_Return_SetColor(void **hData, u32 abgr) {

}

// 0x14c5a00
effBattleSystem_effBTLSystem_Shock_tag *effBTLSys_Shock_Create(nbFormation_t *pFormation) {
  u64 *v3;
  f32 ScalePtr;
  Il2CppObject *hData;

  hData = 0;
  v3 = Allocate(effBattleSystem_effBTLSystem_Shock_tag);
  _ctor(v3, 0);
  v3[2] = pFormation;
  *(v3 + 6) = 0;
  v3[4] = effPCPThunderSpherePolyLowCreate(effBTLSystem_Shock_ThunderSpherePolyLowParam);
  ScalePtr = effBTLSystem_GetScalePtr(v3 + 2);
  hData = v3[4];
  effPCPThunderSpherePolyLowSetScale(&hData, ScalePtr);
  effPCPThunderSpherePolyLowGetParam(v3[4])->height = (*(v3[2] + 100) * *(v3[2] + 108)) * 0.85;
  return v3;
}

// 0x14c61b0
void effBTLSys_Shock_DataFree(void) {
  effBTLSystem_Part_DataFree(&effBTLSystem_Shock_PartList, effBTLSystem_Shock_PartList->max_length);
}

// 0x14c6140
void effBTLSys_Shock_DataLoad(void) {
  effBTLSystem_Part_DataLoad(&effBTLSystem_Shock_PartList, effBTLSystem_Shock_PartList->max_length);
}

// 0x14c5b00
void effBTLSys_Shock_Delete(void *pData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  Il2CppClass *v7;
  evtUnitHandle_t_o **p_implementedInterfaces;
  Il2CppClass **implementedInterfaces;
  Il2CppClass *v10;
  u64 v11[3];

  v10 = 0;
  if (pData)
  {
    klass = pData->klass;
    if (pData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Shock_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Shock_tag, v11);
      if ((v11[0] & 1) != 0)
        v5 = v11[2];
      else
        v5 = v11 + 1;
      v6 = sub_8C4940(v5);
    }
  }
LABEL_14:
  v7 = pData[1].klass;
  implementedInterfaces = v7->_1.implementedInterfaces;
  p_implementedInterfaces = &v7->_1.implementedInterfaces;
  if (implementedInterfaces)
  {
    evtSetUnitColorRGB(p_implementedInterfaces, 4u, 0x80808080);
    LODWORD(pData[1].klass->rgctx_data) = (BYTE3(pData[1].klass->rgctx_data) << 24) | 0x808080;
  }
  v10 = pData[2].klass;
  effPCPThunderSpherePolyLowDelete(&v10);
}

// 0x14c5cb0
void effBTLSys_Shock_Delete2(void *pData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppClass *v8;
  u64 v9[3];

  v8 = 0;
  klass = pData->klass;
  if (pData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Shock_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Shock_tag, v9);
    if ((v9[0] & 1) != 0)
      v6 = v9[2];
    else
      v6 = v9 + 1;
    v7 = sub_8C4940(v6);
  }
  v8 = pData[2].klass;
  effPCPThunderSpherePolyLowDelete(&v8);
}

// 0x14c5ef0
void effBTLSys_Shock_Draw(void **pData) {
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  Il2CppClass *v9;
  evtUnitHandle_t_o **p_implementedInterfaces;
  Il2CppClass **implementedInterfaces;
  Il2CppClass *v12;
  UnityEngine_Vector4_o p;
  u64 v14[3];

  *&p.x = 0;
  *&p.z = 0;
  v12 = 0;
  v4 = *pData;
  if (*pData)
  {
    klass = v4->klass;
    if (v4->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Shock_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Shock_tag, v14);
      if ((v14[0] & 1) != 0)
        v7 = v14[2];
      else
        v7 = v14 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  *&p.x = 0;
  *&p.z = 0;
  if (!LODWORD(v4[1].monitor))
  {
    v9 = v4[1].klass;
    implementedInterfaces = v9->_1.implementedInterfaces;
    p_implementedInterfaces = &v9->_1.implementedInterfaces;
    if (implementedInterfaces)
    {
      evtSetUnitColorRGB(p_implementedInterfaces, 4u, 0x807F6666);
      LODWORD(v4[1].klass->rgctx_data) = (BYTE3(v4[1].klass->rgctx_data) << 24) | 0x7F6666;
    }
  }
  effBTLModelGetMarkPosition2(&v4[1], 0);
  SDF_VU0__STOREVECTOR(&p);
  v12 = v4[2].klass;
  effPCPThunderSpherePolyLowSetPosition(&v12, p);
  effPCPThunderSpherePolyLowDraw(&v12);
  ++LODWORD(v4[1].monitor);
}

// 0x14c6100
u32 effBTLSys_Shock_GetLength(void *pData) {
  return 0;
}

// 0x14c6220
void effBTLSys_Shock_PartHandleCreate(void) {
  effBTLSystem_Part_HandleCreate(&effBTLSystem_Shock_PartList, effBTLSystem_Shock_PartList->max_length);
}

// 0x14c6290
void effBTLSys_Shock_PartHandleDelete(void) {
  effBTLSystem_Part_HandleDelete(&effBTLSystem_Shock_PartList, effBTLSystem_Shock_PartList->max_length);
}

// 0x14c5de0
void effBTLSys_Shock_SetColor(void **pData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  Il2CppObject *v9[3];
  Il2CppObject *hData;

  hData = 0;
  klass = (*pData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Shock_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Shock_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  hData = (*pData)[2].klass;
  effPCPThunderSpherePolyLowSetColor(&hData, abgr);
}

// 0x14c6d20
effBattleSystem_effBTLSystem_Sleep_tag *effBTLSys_Sleep_Create(nbFormation_t *pFormation) {
  effBattleSystem_effBTLSystem_Sleep_tag_o *v3;
  struct effBattleSystem_effBTLSystem_Part_tag_array *effBTLSystem_Sleep_PartList;
  effPartHandle_t_o **p_hPart;
  f32 ScalePtr;

  v3 = Allocate(effBattleSystem_effBTLSystem_Sleep_tag);
  _ctor(v3, 0);
  v3->pFormation = pFormation;
  v3->frame = 0;
  else
  {
    if (!LODWORD(effBTLSystem_Sleep_PartList->max_length))
      goto LABEL_6;
  }
  p_hPart = &effBTLSystem_Sleep_PartList->m_Items[0]->hPart;
  v3->hPartD3P = dds3EffectPartCopy(p_hPart, 0, 0);
  ScalePtr = effBTLSystem_GetScalePtr(&v3->pFormation);
  dds3EffectPartSetScale(&v3->hPartD3P, ScalePtr);
  return v3;
}

// 0x14c7580
void effBTLSys_Sleep_DataFree(void) {
  effBTLSystem_Part_DataFree(&effBTLSystem_Sleep_PartList, effBTLSystem_Sleep_PartList->max_length);
}

// 0x14c7510
void effBTLSys_Sleep_DataLoad(void) {
  effBTLSystem_Part_DataLoad(&effBTLSystem_Sleep_PartList, effBTLSystem_Sleep_PartList->max_length);
}

// 0x14c6e40
void effBTLSys_Sleep_Delete(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  Il2CppClass *v7;
  evtUnitHandle_t_o **p_implementedInterfaces;
  Il2CppClass **implementedInterfaces;
  effPartHandle_t_o **v10;
  u64 v11[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Sleep_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Sleep_tag, v11);
      if ((v11[0] & 1) != 0)
        v5 = v11[2];
      else
        v5 = v11 + 1;
      v6 = sub_8C4940(v5);
    }
  }
LABEL_14:
  v7 = hData[1].klass;
  implementedInterfaces = v7->_1.implementedInterfaces;
  p_implementedInterfaces = &v7->_1.implementedInterfaces;
  if (implementedInterfaces)
  {
    evtSetUnitColorRGB(p_implementedInterfaces, 4u, 0x80808080);
    LODWORD(hData[1].klass->rgctx_data) = (BYTE3(hData[1].klass->rgctx_data) << 24) | 0x808080;
  }
  v10 = &hData[2];
  dds3EffectPartDelete(v10);
}

// 0x14c7000
void effBTLSys_Sleep_Delete2(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  effPartHandle_t_o **v7;
  u64 v9[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Sleep_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Sleep_tag, v9);
      if ((v9[0] & 1) != 0)
        v5 = v9[2];
      else
        v5 = v9 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  v7 = &hData[2];
  dds3EffectPartDelete(v7);
}

// 0x14c7280
void effBTLSys_Sleep_Draw(void **hData) {
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  Il2CppClass *v9;
  evtUnitHandle_t_o **p_implementedInterfaces;
  Il2CppClass **implementedInterfaces;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  UnityEngine_Vector4_o p;
  u64 v18[3];
  UnityEngine_Vector4_o v19;

  *&p.x = 0;
  *&p.z = 0;
  v4 = *hData;
  if (*hData)
  {
    klass = v4->klass;
    if (v4->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Sleep_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Sleep_tag, v18);
      if ((v18[0] & 1) != 0)
        v7 = v18[2];
      else
        v7 = v18 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  *&p.x = 0;
  *&p.z = 0;
  if (!LODWORD(v4[1].monitor))
  {
    v9 = v4[1].klass;
    implementedInterfaces = v9->_1.implementedInterfaces;
    p_implementedInterfaces = &v9->_1.implementedInterfaces;
    if (implementedInterfaces)
    {
      evtSetUnitColorRGB(p_implementedInterfaces, 4u, 0x807F5C3E);
      LODWORD(v4[1].klass->rgctx_data) = (BYTE3(v4[1].klass->rgctx_data) << 24) | 0x7F5C3E;
    }
  }
  effBTLModelGetMarkPosition2(&v4[1], 2u);
  SDF_VU0__STOREVECTOR(&p);
  x = p.x;
  y = p.y;
  z = p.z;
  w = p.w;
  v19.x = x;
  v19.y = y;
  v19.z = z;
  v19.w = w;
  dds3EffectPartSetPosition(&v4[2], v19);
  dds3EffectPartDraw(&v4[2]);
  ++LODWORD(v4[1].monitor);
}

// 0x14c74d0
u32 effBTLSys_Sleep_GetLength(void *hData) {
  return 0;
}

// 0x14c75f0
void effBTLSys_Sleep_PartHandleCreate(void) {
  effBTLSystem_Part_HandleCreate(&effBTLSystem_Sleep_PartList, effBTLSystem_Sleep_PartList->max_length);
}

// 0x14c7660
void effBTLSys_Sleep_PartHandleDelete(void) {
  effBTLSystem_Part_HandleDelete(&effBTLSystem_Sleep_PartList, effBTLSystem_Sleep_PartList->max_length);
}

// 0x14c7150
void effBTLSys_Sleep_SetColor(void **hData, u32 abgr) {
  u32 v3;
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  effPartHandle_t_o **v10;
  u64 v11[3];

  v3 = abgr;
  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Sleep_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Sleep_tag, v11);
      if ((v11[0] & 1) != 0)
        v8 = v11[2];
      else
        v8 = v11 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = &v5[2];
  dds3EffectPartSetColor(v10, v3);
}

// 0x14cba70
effBattleSystem_effBTLSystem_Stone_tag *effBTLSys_Stone_Create(nbFormation_t *pFormation) {
  effBattleSystem_effBTLSystem_Stone_tag_o *v3;

  v3 = Allocate(effBattleSystem_effBTLSystem_Stone_tag);
  _ctor(v3, 0);
  v3->pFormation = pFormation;
  v3->frame = 0;
  return v3;
}

// 0x14cc120
void effBTLSys_Stone_DataFree(void) {
  effBTLSystem_Part_DataFree(&effBTLSystem_Stone_PartList, effBTLSystem_Stone_PartList->max_length);
}

// 0x14cc0b0
void effBTLSys_Stone_DataLoad(void) {
  effBTLSystem_Part_DataLoad(&effBTLSystem_Stone_PartList, effBTLSystem_Stone_PartList->max_length);
}

// 0x14cd430
effBattleSystem_effBTLSystem_Stone_Dead_tag *effBTLSys_Stone_Dead_Create(nbFormation_t *pFormation) {
  u64 *v3;
  effBattleSystem_effBTLSystem_Stone_Dead_tag_o *v4;
  struct effBattleSystem_effBTLSystem_Part_tag_array *effBTLSystem_Stone_Dead_PartList;
  effPartHandle_t_o **p_hPart;
  Il2CppObject *Handle;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v12;
  s64 *v13;
  struct effBattleSystem_effBTLSystem_Part_tag_array *v14;
  struct effBattleSystem_effBTLSystem_Part_tag_array *v16;
  f32 ScalePtr;
  u64 v21[3];

  v3 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v3);
  v4 = Allocate(effBattleSystem_effBTLSystem_Stone_Dead_tag);
  _ctor(v4, 0);
  v4->pFormation = pFormation;
  v4->frame = 0;
  else
  {
    if (!LODWORD(effBTLSystem_Stone_Dead_PartList->max_length))
      goto LABEL_6;
  }
  p_hPart = &effBTLSystem_Stone_Dead_PartList->m_Items[0]->hPart;
  v4->hPartPB = dds3EffectPartCopy(p_hPart, 0, 0);
  Handle = dds3EffectPartGetHandle(&v4->hPartPB);
  if (Handle)
  {
    klass = Handle->klass;
    if (Handle->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, v21);
      if ((v21[0] & 1) != 0)
        v12 = v21[2];
      else
        v12 = v21 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  v14 = effBTLSystem_Stone_Dead_PartList;
  v4->hPartD3P1 = dds3EffectPartCopy(&v14->m_Items[1]->hPart, 0, 0);
  v16 = effBTLSystem_Stone_Dead_PartList;
  v4->hPartD3P2 = dds3EffectPartCopy(&v16->m_Items[2]->hPart, 0, 0);
  ScalePtr = effBTLSystem_GetScalePtr(&v4->pFormation);
  dds3EffectPartSetScale(&v4->hPartPB, ScalePtr);
  dds3EffectPartSetScale(&v4->hPartD3P1, ScalePtr);
  dds3EffectPartSetScale(&v4->hPartD3P2, ScalePtr);
  return v4;
}

// 0x14cdd80
void effBTLSys_Stone_Dead_DataFree(void) {
  effBTLSystem_Part_DataFree(&effBTLSystem_Stone_Dead_PartList, effBTLSystem_Stone_Dead_PartList->max_length);
}

// 0x14cdd10
void effBTLSys_Stone_Dead_DataLoad(void) {
  effBTLSystem_Part_DataLoad(&effBTLSystem_Stone_Dead_PartList, effBTLSystem_Stone_Dead_PartList->max_length);
}

// 0x14cd6d0
void effBTLSys_Stone_Dead_Delete(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  u64 v7[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Stone_Dead_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Stone_Dead_tag, v7);
      if ((v7[0] & 1) != 0)
        v5 = v7[2];
      else
        v5 = v7 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  dds3EffectPartDelete(&hData[3]);
  dds3EffectPartDelete(&hData[2].monitor);
  dds3EffectPartDelete(&hData[2]);
}

// 0x14cd820
void effBTLSys_Stone_Dead_Delete2(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  u64 v8[3];

  if (hData)
  {
    klass = hData->klass;
    if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Stone_Dead_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Stone_Dead_tag, v8);
      if ((v8[0] & 1) != 0)
        v5 = v8[2];
      else
        v5 = v8 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  dds3EffectPartDelete(&hData[3]);
  dds3EffectPartDelete(&hData[2].monitor);
  dds3EffectPartDelete(&hData[2]);
}

// 0x14cd9c0
void effBTLSys_Stone_Dead_Draw(void **hData) {
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  struct System_Byte_array *effBTLModelShowFlag;
  dds3ModelHandle_t_o **v12;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  u32 monitor;
  UnityEngine_Vector4_o p;
  u64 v21[3];
  UnityEngine_Vector4_o v22;

  *&p.x = 0;
  *&p.z = 0;
  v4 = *hData;
  if (*hData)
  {
    klass = v4->klass;
    if (v4->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Stone_Dead_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Stone_Dead_tag, v21);
      if ((v21[0] & 1) != 0)
        v7 = v21[2];
      else
        v7 = v21 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  *&p.x = 0;
  *&p.z = 0;
  if (!LODWORD(v4[1].monitor))
  {
    effBTLModelShowFlag->m_Items[SWORD1(v4[1].klass->_1.interfaceOffsets)] = 0;
    v12 = (v4[1].klass->_1.implementedInterfaces + 22);
    mdlHideEffect(v12);
  }
  effBTLModelGetMarkPosition2(&v4[1], 0);
  SDF_VU0__STOREVECTOR(&p);
  x = p.x;
  y = p.y;
  z = p.z;
  w = p.w;
  v22.x = x;
  v22.y = y;
  v22.z = z;
  v22.w = w;
  dds3EffectPartSetPosition(&v4[3], v22);
  dds3EffectPartSetPosition(&v4[2].monitor, p);
  dds3EffectPartSetPosition(&v4[2], p);
  dds3EffectPartDraw(&v4[3]);
  dds3EffectPartDraw(&v4[2].monitor);
  monitor = v4[1].monitor;
  if (monitor >= 2)
  {
    dds3EffectPartDraw(&v4[2]);
    monitor = v4[1].monitor;
  }
  LODWORD(v4[1].monitor) = monitor + 1;
}

// 0x14cdcd0
u32 effBTLSys_Stone_Dead_GetLength(void *hData) {
  return 50;
}

// 0x14cddf0
void effBTLSys_Stone_Dead_PartHandleCreate(void) {
  effBTLSystem_Part_HandleCreate(&effBTLSystem_Stone_Dead_PartList, effBTLSystem_Stone_Dead_PartList->max_length);
}

// 0x14cde60
void effBTLSys_Stone_Dead_PartHandleDelete(void) {
  effBTLSystem_Part_HandleDelete(&effBTLSystem_Stone_Dead_PartList, effBTLSystem_Stone_Dead_PartList->max_length);
}

// 0x14cd980
void effBTLSys_Stone_Dead_SetColor(void **hData, u32 abgr) {

}

// 0x14cbae0
void effBTLSys_Stone_Delete(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3ModelHandle_t_o **v5;
  s64 v7;
  UnityEngine_Object_o *v8;
  Il2CppObject *Component_object;
  char *v11;
  s64 *v12;
  u64 v13[3];

  klass = hData->klass;
  if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Stone_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Stone_tag, v13);
    if ((v13[0] & 1) != 0)
      v11 = v13[2];
    else
      v11 = v13 + 1;
    v12 = sub_8C4940(v11);
  }
  v5 = (hData[1].klass->_1.implementedInterfaces + 22);
  mdlShowEffect(v5);
  v7 = *(*(hData[1].klass->_1.implementedInterfaces + 22) + 96LL);
  if (v7)
  {
    v8 = *(v7 + 128);
    if (op_Implicit(v8, 0))
    {
      Component_object = GetComponent_object_(
                           *(*(*(hData[1].klass->_1.implementedInterfaces + 22) + 96LL) + 128LL));
      if (op_Inequality(Component_object, 0, 0))
        (Component_object->klass->vtable[24].methodPtr)(
          Component_object,
          Component_object->klass->vtable[24].0.0);
    }
  }
}

// 0x14cbcf0
void effBTLSys_Stone_Delete2(void *hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  u64 v7[3];

  else if (!hData)
  {
    return;
  }
  klass = hData->klass;
  if (hData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Stone_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Stone_tag, v7);
    if ((v7[0] & 1) != 0)
      v5 = v7[2];
    else
      v5 = v7 + 1;
    v6 = sub_8C4940(v5);
  }
}

// 0x14cbe50
void effBTLSys_Stone_Draw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3ModelHandle_t_o **v8;
  s64 v10;
  UnityEngine_Object_o *v11;
  Il2CppObject *Component_object;
  u64 v14[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Stone_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Stone_tag, v14);
      if ((v14[0] & 1) != 0)
        v6 = v14[2];
      else
        v6 = v14 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  if (!LODWORD(v3[1].monitor))
  {
    v8 = (v3[1].klass->_1.implementedInterfaces + 22);
    mdlHideEffect(v8);
    v10 = *(*(v3[1].klass->_1.implementedInterfaces + 22) + 96LL);
    if (v10)
    {
      v11 = *(v10 + 128);
      if (op_Implicit(v11, 0))
      {
        Component_object = GetComponent_object_(
                             *(*(*(v3[1].klass->_1.implementedInterfaces + 22) + 96LL) + 128LL));
        if (op_Inequality(Component_object, 0, 0))
          (Component_object->klass->vtable[24].methodPtr)(
            Component_object,
            Component_object->klass->vtable[24].1.0);
      }
    }
  }
  ++LODWORD(v3[1].monitor);
}

// 0x14cc070
u32 effBTLSys_Stone_GetLength(void *hData) {
  return 0;
}

// 0x14cc190
void effBTLSys_Stone_PartHandleCreate(void) {
  effBTLSystem_Part_HandleCreate(&effBTLSystem_Stone_PartList, effBTLSystem_Stone_PartList->max_length);
}

// 0x14cc200
void effBTLSys_Stone_PartHandleDelete(void) {
  effBTLSystem_Part_HandleDelete(&effBTLSystem_Stone_PartList, effBTLSystem_Stone_PartList->max_length);
}

// 0x14cbe10
void effBTLSys_Stone_SetColor(void **hData, u32 abgr) {

}

// 0x14d5a00
effBTLSysHandle_t *effBTLSystemCreate(nbFormation_t **pFormation, u32 id) {
  effBTLSysHandle_t_o *v5;
  struct effBattleSystem_effBTLSystem_FuncTable_tag_array *effBTLSystemFuncTable;
  struct effBattleSystem_effBTLSystem_FuncTable_tag_array *v11;

  v5 = Allocate(effBTLSysHandle_t);
  effBTLSysHandle_t___ctor(v5);
  v5->id = id;
  v5->pFormation = *pFormation;
  if (effBTLSystemFuncTable->m_Items[id]->Create)
  {
    v11 = effBTLSystemFuncTable;
    v5->pHandle = Invoke(
                           v11->m_Items[id]->Create,
                           *pFormation,
                           0);
  }
  return v5;
}

// 0x14d6980
effBTLCutHandle_t *effBTLSystemCut1Create(nbFormation_t **pFormation, u32 index) {
  u64 *v5;
  struct effBattleSystem_effBTLSystem_Cut1_tag_array *effBTLSystemCut1Data;
  effBattleSystem_effBTLSystem_Cut1_tag_o *v11;
  u32 use;
  UnityEngine_Texture_array *pTexture;
  System_Byte_array *pData;
  effBTL_t_o *v16;
  nbFormation_t_o *v17;
  effBTLCutHandle_t_o *hBTLCutEffect;

  v5 = Allocate(effBTLCutHandle_t);
  effBTLCutHandle_t___ctor(v5);
  hBTLCutEffect = v5;
  v11 = effBTLSystemCut1Data->m_Items[index];
  if (v11->pData)
  {
    use = v11->use;
    if (!use)
    {
      pTexture = v11->pTexture;
      billSetTexture(pTexture);
      pData = v11->pData;
      v16 = effBTLCreate(pData);
      use = v11->use;
      v11->hBTLEffect = v16;
    }
    v11->use = use + 1;
    v17 = *pFormation;
    hBTLCutEffect = effBTLCutCreate(&v11->hBTLEffect, 0, v17, 0);
    effBTLCutSetUserData(&hBTLCutEffect, v11);
    return hBTLCutEffect;
  }
  else
  {
    return effBTLSystemCut1Create(pFormation, 1u);
  }
}

// 0x14d67a0
void effBTLSystemCut1DataFree(void) {
  s64 i;
  u64 v4;
  struct effBattleSystem_effBTLSystem_Cut1_tag_array *effBTLSystemCut1Data;
  struct effBattleSystem_effBTLSystem_Cut1_tag_array *v7;
  effBTL_t_o **v9;
  struct effBattleSystem_effBTLSystem_Cut1_tag_array *v11;
  struct effBattleSystem_effBTLSystem_Cut1_tag_array *v13;

  for (i = 4; i != 29; ++i)
  {
    while (1)
    {
      v4 = i - 4;
      if (*(*(&effBTLSystemCut1Data->obj.klass + i) + 24LL))
        break;
      if (++i == 29)
        return;
    }
    v7 = effBTLSystemCut1Data;
    v9 = (*(&v7->obj.klass + i) + 24LL);
    effBTLDelete(v9);
    v11 = effBTLSystemCut1Data;
    *(*(&v11->obj.klass + i) + 24LL) = 0;
    v13 = effBTLSystemCut1Data;
    *(*(&v13->obj.klass + i) + 32LL) = 0;
  }
}

// 0x14d61e0
void effBTLSystemCut1DataLoad(void) {
  u64 v2;
  struct effBattleSystem_effBTLSystem_Cut1_tag_array *effBTLSystemCut1Data;
  struct effBattleSystem_effBTLSystem_Cut1_tag_array *v6;
  struct effBattleSystem_effBTLSystem_Cut1_tag_array *v8;
  struct effBattleSystem_effBTLSystem_Cut1_tag_array *v11;
  System_Byte_array **p_pData;
  s64 v14;
  struct effBattleSystem_effBTLSystem_Cut1_tag_array *v16;
  struct effBattleSystem_effBTLSystem_Cut1_tag_array *v18;
  struct effBattleSystem_effBTLSystem_Cut1_tag_array *v20;
  u64 v21;
  struct effBattleSystem_effBTLSystem_Cut1_tag_array *v23;
  u32 *pTexture;
  AssetBundleCtrl_o *asset_bc;
  struct effBattleSystem_effBTLSystem_Cut1_tag_array *v27;
  struct System_String_array *tex_fname;
  s64 *FileObject;
  s64 *v32;
  s64 v33;
  s64 typeHierarchyDepth;
  char *v35;
  s64 *v36;
  s64 v38;
  s64 v39;
  char *v40;
  s64 *v41;
  struct effBattleSystem_effBTLSystem_Cut1_tag_array *v43;
  struct effBattleSystem_effBTLSystem_Cut1_tag_array *v45;
  effBattleSystem_effBTLSystem_Cut1_tag_o *v47;
  bool v48;
  u64 v49[2];
  char *v50;

  v2 = 0;
  do
  {
    if (effBTLSystemCut1Data->m_Items[v2]->pFilename)
    {
      v6 = effBTLSystemCut1Data;
      v6->m_Items[v2]->hMem = 0;
      v8 = effBTLSystemCut1Data;
      sdfDevLoadFileUnity_25061072(v8->m_Items[v2]->pFilename, &effBTLSystemCut1Data->m_Items[v2]->pData, 0, "battle");
      v11 = effBTLSystemCut1Data;
      p_pData = &v11->m_Items[v2]->pData;
      MarkTmxIndex(p_pData);
      v14 = 4;
        goto LABEL_36;
LABEL_34:
      goto LABEL_36;
    }
    v16 = effBTLSystemCut1Data;
    v16->m_Items[v2]->hMem = 0;
    v18 = effBTLSystemCut1Data;
    v18->m_Items[v2]->pData = 0;
    v14 = 4;
      goto LABEL_34;
    while (1)
    {
LABEL_36:
      v20 = effBTLSystemCut1Data;
      v21 = v14 - 4;
      if (v21 >= SLODWORD(v20->m_Items[v2]->tex_fname->max_length))
        break;
      v23 = effBTLSystemCut1Data;
      pTexture = v23->m_Items[v2]->pTexture;
      asset_bc = get_asset_bc();
      v27 = effBTLSystemCut1Data;
      tex_fname = v27->m_Items[v2]->tex_fname;
      FileObject = LoadFileObject(asset_bc, "battle", *(&tex_fname->obj.klass + v14), 0);
      v32 = FileObject;
      if (FileObject)
      {
        v33 = *FileObject;
        if (*(*FileObject + 288) < typeHierarchyDepth
          || *(*(v33 + 200) + 8 * typeHierarchyDepth - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v33 + 64), UnityEngine_Texture, v49);
          if ((v49[0] & 1) != 0)
            v35 = v50;
          else
            v35 = v49 + 1;
          v36 = sub_8C4940(v35);
        }
        v38 = *v32;
        if (*(*v32 + 288) < v39 || *(*(v38 + 200) + 8 * v39 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v38 + 64), UnityEngine_Texture, v49);
          if ((v49[0] & 1) != 0)
            v40 = v50;
          else
            v40 = v49 + 1;
          v41 = sub_8C4940(v40);
        }
      }
      *&pTexture[2 * v14++] = v32;
        goto LABEL_34;
    }
    v43 = effBTLSystemCut1Data;
    v43->m_Items[v2]->hBTLEffect = 0;
    v45 = effBTLSystemCut1Data;
    v47 = v45->m_Items[v2];
    v48 = v2++ >= 0x18;
    v47->use = 0;
  }
  while (!v48);
}

// 0x14d6bc0
void effBTLSystemCut1Delete(effBTLCutHandle_t **hBTLCutEffect) {
  Il2CppObject *UserData;
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  s32 v10;
  u64 v11[3];

  if (*hBTLCutEffect)
  {
    UserData = effBTLCutGetUserData(hBTLCutEffect);
    v4 = UserData;
    if (UserData)
    {
      klass = UserData->klass;
      if (UserData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Cut1_tag)
      {
        sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Cut1_tag, v11);
        if ((v11[0] & 1) != 0)
          v7 = v11[2];
        else
          v7 = v11 + 1;
        v8 = sub_8C4940(v7);
      }
    }
    effBTLCutDelete(hBTLCutEffect);
    v10 = LODWORD(v4[2].klass) - 1;
    LODWORD(v4[2].klass) = v10;
    if (!v10)
    {
      effBTLDelete(&v4[1].monitor);
      v4[1].monitor = 0;
    }
  }
}

// 0x14d6b50
void effBTLSystemCut1Draw(effBTLCutHandle_t **hBTLCutEffect) {
  effBTLCutDraw(hBTLCutEffect);
}

// 0x14d6d30
void effBTLSystemCut1PartHandleCreate(void) {
  ;
}

// 0x14d6d40
void effBTLSystemCut1PartHandleDelete(void) {
  s64 i;
  u64 v4;
  struct effBattleSystem_effBTLSystem_Cut1_tag_array *effBTLSystemCut1Data;
  struct effBattleSystem_effBTLSystem_Cut1_tag_array *v8;
  effBTL_t_o **v10;
  struct effBattleSystem_effBTLSystem_Cut1_tag_array *v12;
  struct effBattleSystem_effBTLSystem_Cut1_tag_array *v14;

  for (i = 4; i != 29; ++i)
  {
    v4 = i - 4;
    if (*(*(&effBTLSystemCut1Data->obj.klass + i) + 24LL))
    {
      v8 = effBTLSystemCut1Data;
      v10 = (*(&v8->obj.klass + i) + 24LL);
      effBTLDelete(v10);
      v12 = effBTLSystemCut1Data;
      *(*(&v12->obj.klass + i) + 24LL) = 0;
      v14 = effBTLSystemCut1Data;
      *(*(&v14->obj.klass + i) + 32LL) = 0;
    }
  }
}

// 0x14d5b40
void effBTLSystemDelete(effBTLSysHandle_t **hEffBTLSys) {
  s64 id;
  struct effBattleSystem_effBTLSystem_FuncTable_tag_array *effBTLSystemFuncTable;
  struct effBattleSystem_effBTLSystem_FuncTable_tag_array *v8;

  id = (*hEffBTLSys)->id;
  if (effBTLSystemFuncTable->m_Items[id]->Delete)
  {
    v8 = effBTLSystemFuncTable;
    Invoke(
      v8->m_Items[id]->Delete,
      (*hEffBTLSys)->pHandle,
      0);
  }
}

// 0x14d5c70
void effBTLSystemDelete2(effBTLSysHandle_t **hEffBTLSys) {
  s64 id;
  struct effBattleSystem_effBTLSystem_FuncTable_tag_array *effBTLSystemFuncTable;
  struct effBattleSystem_effBTLSystem_FuncTable_tag_array *v8;

  if (*hEffBTLSys)
  {
    id = (*hEffBTLSys)->id;
    if (effBTLSystemFuncTable->m_Items[id]->Delete2)
    {
      v8 = effBTLSystemFuncTable;
      Invoke(
        v8->m_Items[id]->Delete2,
        (*hEffBTLSys)->pHandle,
        0);
    }
  }
}

// 0x14d5da0
void effBTLSystemDraw(effBTLSysHandle_t **hEffBTLSys) {
  effBTLSysHandle_t_o *v3;
  s64 id;
  struct effBattleSystem_effBTLSystem_FuncTable_tag_array *effBTLSystemFuncTable;
  struct nbFormation_t_o *v8;
  struct evtUnitHandle_t_o *hunit;
  dds3ModelHandle_t_o **p_Model;
  struct dds3ModelHandle_t_o *Model;
  u32 Color;
  u32 v15;
  struct effBattleSystem_effBTLSystem_FuncTable_tag_array *v16;
  struct effBattleSystem_effBTLSystem_FuncTable_tag_array *v19;
  struct effBattleSystem_effBTLSystem_FuncTable_tag_array *v22;
  struct nbFormation_t_o *pFormation;

  v3 = *hEffBTLSys;
  if (*hEffBTLSys)
  {
    id = v3->id;
    if (id != 20)
    {
      pFormation = v3->pFormation;
      if ((pFormation->stat & 1) == 0 || !pFormation->hunit)
        return;
    }
    if (effBTLSystemFuncTable->m_Items[id]->SetColor)
    {
      v8 = (*hEffBTLSys)->pFormation;
      if ((v8->stat & 2) != 0)
      {
        hunit = v8->hunit;
        Model = hunit->Model;
        p_Model = &hunit->Model;
        if (Model)
        {
          Color = mdlGetColor(p_Model);
          v15 = Color & 0xFF000000 | 0x808080;
          v16 = effBTLSystemFuncTable;
          Invoke(
            v16->m_Items[id]->SetColor,
            &(*hEffBTLSys)->pHandle,
            v15,
            0);
        }
      }
    }
    v19 = effBTLSystemFuncTable;
    if (v19->m_Items[id]->Draw)
    {
      v22 = effBTLSystemFuncTable;
      Invoke(
        v22->m_Items[id]->Draw,
        &(*hEffBTLSys)->pHandle,
        0);
    }
  }
}

// 0x14d7120
void effBTLSystemEnd(void) {
  s64 i;
  u64 v6;
  struct effBattleSystem_effBTLSystem_FuncTable_tag_array *effBTLSystemFuncTable;
  struct effBattleSystem_effBTLSystem_FuncTable_tag_array *v10;

  effBTLSystemCut1DataFree();
  for (i = 4; i != 34; ++i)
  {
    v6 = i - 4;
    if (*(*(&effBTLSystemFuncTable->obj.klass + i) + 72LL))
    {
      v10 = effBTLSystemFuncTable;
      Invoke(*(*(&v10->obj.klass + i) + 72LL), 0);
    }
  }
}

// 0x14c4c20
void effBTLSystemFilePac(void) {
  ;
}

// 0x14d6130
u32 effBTLSystemGetID(effBTLSysHandle_t **hEffBTLSys) {
  return (*hEffBTLSys)->id;
}

// 0x14d6010
u32 effBTLSystemGetLength(effBTLSysHandle_t **hEffBTLSys) {
  s64 id;
  struct effBattleSystem_effBTLSystem_FuncTable_tag_array *effBTLSystemFuncTable;
  struct effBattleSystem_effBTLSystem_FuncTable_tag_array *v8;

  id = (*hEffBTLSys)->id;
  if (!effBTLSystemFuncTable->m_Items[id]->GetLength)
    return 0;
  v8 = effBTLSystemFuncTable;
  return Invoke(
           v8->m_Items[id]->GetLength,
           (*hEffBTLSys)->pHandle,
           0);
}

// 0x14d6140
u32 effBTLSystemGetRGBA(u32 id) {
  struct effBattleSystem_effBTLSystem_FuncTable_tag_array *effBTLSystemFuncTable;

  return effBTLSystemFuncTable->m_Items[id]->model_color;
}

// 0x14d6fb0
void effBTLSystemInit(void) {
  u64 v2;
  s32 v3;
  s64 i;
  u64 v5;
  s64 v6;
  struct effBattleSystem_effBTLSystem_FuncTable_tag_array *effBTLSystemFuncTable;
  u32 v11;

  else if (initflg)
  {
    return;
  }
  v3 = (*(v2 + 295) >> 1) & 1;
  for (i = 4; i != 34; ++i)
  {
    v5 = i - 4;
    v6 = *(*(v2 + 184) + 272LL);
    if (*(*(v6 + 8 * i) + 64LL))
    {
      Invoke(
        *(*(&effBTLSystemFuncTable->obj.klass + i) + 64LL),
        0);
    }
    v3 = (v11 >> 9) & 1;
  }
  effBTLSystemCut1DataLoad(v2);
  initflg = 1;
}

// 0x14d7240
void effBTLSystemPartHandleCreate(void) {
  s64 i;
  u64 v4;
  struct effBattleSystem_effBTLSystem_FuncTable_tag_array *effBTLSystemFuncTable;
  struct effBattleSystem_effBTLSystem_FuncTable_tag_array *v8;
  struct effBattleSystem_effBTLSystem_FuncTable_tag_array *v11;

  for (i = 4; i != 34; ++i)
  {
    v4 = i - 4;
    if (*(*(&effBTLSystemFuncTable->obj.klass + i) + 100LL))
    {
      v8 = effBTLSystemFuncTable;
      if (*(*(&v8->obj.klass + i) + 80LL))
      {
        v11 = effBTLSystemFuncTable;
        Invoke(*(*(&v11->obj.klass + i) + 80LL), 0);
      }
    }
  }
}

// 0x14d73a0
void effBTLSystemPartHandleDelete(void) {
  s64 i;
  u64 v6;
  struct effBattleSystem_effBTLSystem_FuncTable_tag_array *effBTLSystemFuncTable;
  struct effBattleSystem_effBTLSystem_FuncTable_tag_array *v10;
  struct effBattleSystem_effBTLSystem_FuncTable_tag_array *v13;

  effBTLSystemCut1PartHandleDelete();
  for (i = 4; i != 34; ++i)
  {
    v6 = i - 4;
    if (*(*(&effBTLSystemFuncTable->obj.klass + i) + 100LL))
    {
      v10 = effBTLSystemFuncTable;
      if (*(*(&v10->obj.klass + i) + 88LL))
      {
        v13 = effBTLSystemFuncTable;
        Invoke(*(*(&v13->obj.klass + i) + 88LL), 0);
      }
    }
  }
}

// 0x14c4cd0
f32 effBTLSystem_GetScalePtr(nbFormation_t **pFormation) {
  nbFormation_t_o *v3;
  nbFormation_t_o **v4;
  f32 v5;
  f32 result;

  v3 = *pFormation;
  if ((*pFormation)->hunit)
  {
    else
    {
      v4 = pFormation;
    }
    return effBTLPartGetScalePtr(v4);
  }
  else
  {
    v5 = (v3->scl * ((v3->r + (v3->h * 0.5)) * 0.5)) * 0.014286;
    result = 2.0;
    if (v5 <= 2.0)
      return fmaxf(v5, 0.8);
  }
  return result;
}

// 0x14c5390
void effBTLSystem_Part_DataFree(effBattleSystem_effBTLSystem_Part_tag ***pPartList, u32 count) {
  u64 i;
  u64 v5;
  effBattleSystem_effBTLSystem_Part_tag_array *v6;
  Il2CppClass **v7;
  struct UnityEngine_Texture_array *pTexture;

  if (count)
  {
    for (i = 0; i != count; ++i)
    {
      v5 = 0;
      (*pPartList)->m_Items[i]->pData = 0;
      v6 = *pPartList;
      if (i >= LODWORD((*pPartList)->max_length))
      {
LABEL_8:
      }
      while (v5 < SLODWORD(v6->m_Items[i]->pTganame->max_length))
      {
        pTexture = (*pPartList)->m_Items[i]->pTexture;
        v7 = &pTexture->obj.klass + v5++;
        v7[4] = 0;
        v6 = *pPartList;
        if (i >= LODWORD((*pPartList)->max_length))
          goto LABEL_8;
      }
    }
  }
}

// 0x14c4db0
void effBTLSystem_Part_DataLoad(effBattleSystem_effBTLSystem_Part_tag ***pPartList, u32 count) {
  u64 *v5;
  u64 *v6;
  u64 i;
  s32 type;
  System_Byte_array **p_pData;
  effBattleSystem_effBTLSystem_Part_tag_o *v17;
  AssetBundleCtrl_o *asset_bc;
  s64 j;
  u64 v22;
  effBattleSystem_effBTLSystem_Part_tag_o *v23;
  struct UnityEngine_Texture_array *pTexture;
  UnityEngine_Object_o *v26;
  u32 *v28;
  AssetBundleCtrl_o *v29;
  struct System_String_array *pTganame;
  s64 *FileObject;
  s64 *v34;
  s64 v35;
  s64 typeHierarchyDepth;
  char *v37;
  s64 *v38;
  s64 v40;
  s64 v41;
  char *v42;
  s64 *v43;
  u64 v45;
  u64 v46[2];
  char *v47;

  v5 = Allocate(sdfFileCmdHandle_t);
  sdfFileCmdHandle_t___ctor(v5);
  v6 = Allocate(effBTL_SkillPBFileHeader_t);
  effBTL_SkillPBFileHeader_t___ctor(v6);
  if (count)
  {
    v45 = count;
    for (i = 0; i < v45; ++i)
    {
      type = (*pPartList)->m_Items[i]->type;
      (*pPartList)->m_Items[i]->hMem = 0;
      sdfDevLoadFileUnity_25061072(
        (*pPartList)->m_Items[i]->pFilename,
        &(*pPartList)->m_Items[i]->pData,
        0,
        "battle",
        0);
      p_pData = &(*pPartList)->m_Items[i]->pData;
      if (type == 3)
      {
        MarkTmxIndex(p_pData);
        if ((*pPartList)->m_Items[i]->pFilenamePF)
        {
          v17 = (*pPartList)->m_Items[i];
          asset_bc = get_asset_bc();
          v17->oData = LoadPrefab_16624656(
                                asset_bc,
                                "battle",
                                "dds3data",
                                (*pPartList)->m_Items[i]->pFilenamePF,
                                0);
        }
      }
      else
      {
        MarkTmxIndex(p_pData);
      }
      for (j = 4; ; ++j)
      {
        v22 = j - 4;
        v23 = (*pPartList)->m_Items[i];
        if (j - 4 >= SLODWORD(v23->pTganame->max_length))
          break;
        pTexture = v23->pTexture;
        v26 = *(&pTexture->obj.klass + j);
        if (op_Equality(v26, 0, 0))
        {
          v28 = (*pPartList)->m_Items[i]->pTexture;
          v29 = get_asset_bc();
          pTganame = (*pPartList)->m_Items[i]->pTganame;
          FileObject = LoadFileObject(v29, "battle", *(&pTganame->obj.klass + j), 0);
          v34 = FileObject;
          if (FileObject)
          {
            v35 = *FileObject;
            if (*(*FileObject + 288) < typeHierarchyDepth
              || *(*(v35 + 200) + 8 * typeHierarchyDepth - 8) != UnityEngine_Texture)
            {
              sub_8FC2C0(*(v35 + 64), UnityEngine_Texture, v46);
              if ((v46[0] & 1) != 0)
                v37 = v47;
              else
                v37 = v46 + 1;
              v38 = sub_8C4940(v37);
            }
            v40 = *v34;
            if (*(*v34 + 288) < v41 || *(*(v40 + 200) + 8 * v41 - 8) != UnityEngine_Texture)
            {
              sub_8FC2C0(*(v40 + 64), UnityEngine_Texture, v46);
              if ((v46[0] & 1) != 0)
                v42 = v47;
              else
                v42 = v46 + 1;
              v43 = sub_8C4940(v42);
            }
          }
          *&v28[2 * j] = v34;
        }
      }
      v23->use = 0;
    }
  }
}

// 0x14c54b0
void effBTLSystem_Part_HandleCreate(effBattleSystem_effBTLSystem_Part_tag ***pPartList, u32 count) {
  s64 v5;
  u64 i;
  UnityEngine_Texture_array *pTexture;
  SOBED_PB_LIST_o *v10;
  effBattleSystem_effBTLSystem_Part_tag_o *v15;
  System_Byte_array *pData;
  u16 type;
  struct System_Byte_array *v21;
  effBattleSystem_effBTLSystem_Part_tag_array *v22;
  Il2CppClass **v24;

  if (count)
  {
    v5 = count;
    for (i = 0; v5 != i; ++i)
    {
      if ((*pPartList)->m_Items[i]->use)
      {
        v22 = *pPartList;
        if (i >= LODWORD((*pPartList)->max_length))
        {
LABEL_36:
        }
        goto LABEL_37;
      }
      pTexture = (*pPartList)->m_Items[i]->pTexture;
      billSetTexture(pTexture);
      v10 = Allocate(SOBED_PB_LIST);
      SOBED_PB_LIST___ctor(v10);
      v10->gobj = (*pPartList)->m_Items[i]->oData;
      v10->reversePB = 0;
      SetPbList(v10);
      v15 = (*pPartList)->m_Items[i];
      if (v15->type == 65533)
      {
        pData = v15->pData;
        v15->hBED = effBTLCreate(pData);
          goto LABEL_23;
      }
      else
      {
        type = v15->type;
        v21 = (*pPartList)->m_Items[i]->pData;
        v15->hPart = dds3EffectPartCreate(type, &v21->obj, 0, 0);
        {
LABEL_23:
        }
      }
      billClrTexture(0);
      v22 = *pPartList;
      if (i >= LODWORD((*pPartList)->max_length))
        goto LABEL_36;
LABEL_37:
      v24 = &v22->obj.klass + i;
      ++LOWORD(v24[4]->_1.this_arg.bits);
    }
  }
}

// 0x14c5810
void effBTLSystem_Part_HandleDelete(effBattleSystem_effBTLSystem_Part_tag ***pPartList, u32 count) {
  s64 v5;
  s64 v6;
  u64 v7;
  s64 v10;
  effBTL_t_o **v11;
  effPartHandle_t_o **v13;

  if (count)
  {
    v5 = -count;
    v6 = 4;
    do
    {
      while (1)
      {
        while (1)
        {
          v7 = v6 - 4;
          --*(*(&(*pPartList)->obj.klass + v6) + 56LL);
          if (!*(*(&(*pPartList)->obj.klass + v6) + 56LL))
            break;
          ++v6;
          if (v5 + v6 == 4)
            return;
        }
        v10 = *(&(*pPartList)->obj.klass + v6);
        if (*(v10 + 16) != 65533)
          break;
        v11 = (v10 + 72);
        effBTLDelete(v11);
        ++v6;
        if (v5 + v6 == 4)
          return;
      }
      v13 = (v10 + 64);
      dds3EffectPartDelete(v13);
      ++v6;
    }
    while (v5 + v6 != 4);
  }
}

// 0x14c4c30
void effBTLSystem_SetUnitColorRGB(nbFormation_t **pFormation, u32 frame, u32 bgr) {
  evtUnitHandle_t_o **p_hunit;

  p_hunit = &(*pFormation)->hunit;
  if (*p_hunit)
  {
    evtSetUnitColorRGB(p_hunit, frame, bgr);
    (*pFormation)->modelcol = bgr & 0xFFFFFF | (HIBYTE((*pFormation)->modelcol) << 24);
  }
}

// 0x14d7510
effBattleSystem_effCAMPBad_tag *effCAMPBadCreate(effCAMPBadParams_t **pParams, u32 id) {
  u64 *v5;
  effBattleSystem_effCAMPBad_tag_o *v6;
  nbFormation_t_o *v7;
  UnityEngine_Vector4_o *params;
  struct effBattleSystem_effBTLSystem_FuncTable_tag_array *effBTLSystemFuncTable;
  s64 v13;
  struct effBattleSystem_effBTLSystem_FuncTable_tag_array *v16;
  s64 v17;
  u32 v19;
  effBTLSysHandle_t_o *v20;
  u32 v21;
  Il2CppObject *v22;
  Il2CppClass *v23;
  s64 v24;
  Il2CppObject *pHandle;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v29;
  s64 *v30;
  char *v31;
  s64 *v32;
  u64 v33[2];
  char *v34;

  v5 = Allocate(effBattleSystem_effCAMPBad_tag);
  _ctor(v5, 0);
  v6 = Allocate(effBattleSystem_effCAMPBad_tag);
  _ctor(v6, 0);
  v6->params = *pParams;
  v6->id = id;
  v6->frame = 0;
  v7 = Allocate(nbFormation_t);
  nbFormation_t___ctor(v7);
  params = v6->params;
  v6->Formation = v7;
  SDF_VU0__COPYVECTOR(&v7->pos, params[1]);
  SDF_VU0__COPYVECTOR(&v6->Formation->rot, v6->params->rot);
  SDF_VU0__COPYVECTOR(&v6->Formation->center, v6->params->center);
  v6->Formation->r = v6->params->r;
  v6->Formation->h = v6->params->h;
  v6->Formation->scl = v6->params->scl;
  v6->Formation->stat = 0;
  v6->Formation->stat |= 1u;
  v6->Formation->stat |= 2u;
  v13 = v6->id;
  if (effBTLSystemFuncTable->m_Items[v13]->PartHandleCreate)
  {
    v16 = effBTLSystemFuncTable;
    v17 = v6->id;
    Invoke(
      v16->m_Items[v17]->PartHandleCreate,
      0);
  }
  v19 = v6->id;
  v20 = effBTLSystemCreate(&v6->Formation, v19);
  v21 = v6->id;
  v6->hEffBTLSys = v20;
  if (v21 == 6)
  {
    pHandle = v20->pHandle;
    klass = pHandle->klass;
    if (pHandle->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBattleSystem_effBTLSystem_Close_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effBattleSystem_effBTLSystem_Close_tag, v33);
      if ((v33[0] & 1) != 0)
        v31 = v34;
      else
        v31 = v33 + 1;
      v32 = sub_8C4940(v31);
    }
    pHandle[3].klass = v6->params->hModel;
  }
  else if (v21 == 7)
  {
    v22 = v20->pHandle;
    v23 = v22->klass;
    if (v22->klass->_2.typeHierarchyDepth < v24
      || v23->_2.typeHierarchy[v24 - 1] != effBattleSystem_effBTLSystem_Poison_tag)
    {
      sub_8FC2C0(v23->_1.element_class, effBattleSystem_effBTLSystem_Poison_tag, v33);
      if ((v33[0] & 1) != 0)
        v29 = v34;
      else
        v29 = v33 + 1;
      v30 = sub_8C4940(v29);
    }
    v22[2].monitor = v6->params->hModel;
  }
  return v6;
}

// 0x14d7bf0
void effCAMPBadDelete(effBattleSystem_effCAMPBad_tag **hCAMPBadEffect) {
  effBTLSysHandle_t_o **p_hEffBTLSys;
  struct effCAMPBadParams_t_o *params;
  dds3ModelHandle_t_o **p_hModel;
  struct dds3ModelHandle_t_o *hModel;
  struct effBattleSystem_effBTLSystem_FuncTable_tag_array *effBTLSystemFuncTable;
  s64 id;
  struct effBattleSystem_effBTLSystem_FuncTable_tag_array *v15;
  s64 v16;

  p_hEffBTLSys = &(*hCAMPBadEffect)->hEffBTLSys;
  effBTLSystemDelete(p_hEffBTLSys);
  params = (*hCAMPBadEffect)->params;
  hModel = params->hModel;
  p_hModel = &params->hModel;
  if (hModel)
  {
    mdlSetColor(p_hModel, 0x80808080);
    effCAMPBadMatRGB(hCAMPBadEffect, 0x80808080);
  }
  id = (*hCAMPBadEffect)->id;
  if (effBTLSystemFuncTable->m_Items[id]->PartHandleDelete)
  {
    v15 = effBTLSystemFuncTable;
    v16 = (*hCAMPBadEffect)->id;
    Invoke(
      v15->m_Items[v16]->PartHandleDelete,
      0);
  }
}

// 0x14d78a0
void effCAMPBadDraw(effBattleSystem_effCAMPBad_tag **hCAMPBadEffect) {
  struct effBattleSystem_effBTLSystem_FuncTable_tag_array *effBTLSystemFuncTable;
  s64 id;
  struct effBattleSystem_effBTLSystem_FuncTable_tag_array *v8;
  s64 v9;
  effBattleSystem_effCAMPBad_tag_o *v11;
  struct effBattleSystem_effBTLSystem_FuncTable_tag_array *v13;
  s64 v14;
  u32 model_color;
  s32 frame;
  u32 v18;
  dds3ModelHandle_t_o **p_hModel;

  id = (*hCAMPBadEffect)->id;
  if (effBTLSystemFuncTable->m_Items[id]->Draw)
  {
    v8 = effBTLSystemFuncTable;
    v9 = (*hCAMPBadEffect)->id;
    Invoke(
      v8->m_Items[v9]->Draw,
      &(*hCAMPBadEffect)->hEffBTLSys->pHandle,
      0);
  }
  v11 = *hCAMPBadEffect;
  if ((*hCAMPBadEffect)->params->hModel)
  {
    v13 = effBTLSystemFuncTable;
    v14 = v11->id;
    model_color = v13->m_Items[v14]->model_color;
    frame = v11->frame;
    if (frame <= 7)
    {
      v18 = effColorBlend(0x80808080, model_color, frame * 0.125);
      v11 = *hCAMPBadEffect;
      model_color = v18;
    }
    p_hModel = &v11->params->hModel;
    mdlSetColor(p_hModel, model_color);
    effCAMPBadMatRGB(hCAMPBadEffect, model_color);
    v11 = *hCAMPBadEffect;
  }
  ++v11->frame;
}

// 0x14d7ac0
void effCAMPBadMatRGB(effBattleSystem_effCAMPBad_tag **hCAMPBadEffect, u32 color) {
  struct sdfModelRootNode_t_o *modelRoot;
  UnityEngine_Object_o *modelobj;
  Il2CppObject *Component_object;

  modelRoot = (*hCAMPBadEffect)->params->hModel->modelRoot;
  if (modelRoot)
  {
    modelobj = modelRoot->modelobj;
    if (op_Inequality(modelobj, 0, 0))
    {
      Component_object = GetComponent_object_(
                           (*hCAMPBadEffect)->params->hModel->modelRoot->modelobj);
      if (op_Inequality(Component_object, 0, 0))
      {
        (Component_object->klass->vtable[23].methodPtr)(
          Component_object,
          color,
          Component_object->klass->vtable[23].method);
        (Component_object->klass->vtable[24].methodPtr)(
          Component_object,
          Component_object->klass->vtable[24].0.0);
      }
    }
  }
}

// 0x14c4b90
s32 mdlChkHide(dds3ModelHandle_t *HNDL) {
  return 0;
}

// 0x14c4bb0
void mdlLink(dds3ModelHandle_t *aHandle, sdfModelOt_t *aModelOt) {
  ;
}

// 0x14c4ba0
void mdlLoopMotion(dds3ModelHandle_t *aHandle, s32 aGroup, s32 aNumber) {
  ;
}

// 0x14c4bc0
void mdlSetClutColor(dds3ModelHandle_t **aHandle, u32 aColor, f32 aRatio) {
  ;
}

// 0x14c4bd0
void mdlSingleMotion(dds3ModelHandle_t **aHandle, s32 aGroup, s32 aNumber) {
  ;
}

// 0x14c4bf0
void sdfChipFree(void *aPtr) {
  ;
}

// 0x14c4c10
sdfMemHandle_t *sdfDevLoadFile(char *aFilename, void *aTopPtr, s32 aSizePtr) {
  return 0;
}

// 0x14c4c00
void sdfDrawTagLink(sdfDrawTag_t *aTag, s32 aPacket) {
  ;
}
