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
    u8 pData[UNKNOWN_ARRAY_SIZE];
    char *pFilenamePF;
    void *oData;
    u16 use;
    effPartHandle_t *hPart;
    effBTL_t *hBED;
    sdfMemHandle_t *hMem;
    char pTganame[UNKNOWN_ARRAY_SIZE];
    void pTexture[UNKNOWN_ARRAY_SIZE];
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
    effBattleSystem_effBTLSystem_Part_tag pPartList[UNKNOWN_ARRAY_SIZE];
};

struct effBattleSystem_effBTLSystem_Cut1_tag {
    char *pFilename;
    effBTL_t *hBTLEffect;
    u32 use;
    u8 pData[UNKNOWN_ARRAY_SIZE];
    sdfMemHandle_t *hMem;
    char tex_fname[UNKNOWN_ARRAY_SIZE];
    void pTexture[UNKNOWN_ARRAY_SIZE];
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
static effBattleSystem_effBTLSystem_Part_tag effBTLSystem_Shock_PartList[UNKNOWN_ARRAY_SIZE];
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
    effBTLSkillEnd();
}

// 0x14d6ed0
void effBTLEncountStart(void) {
  effBTLSkillStart(0x200u, 0);
}

// 0x14d2010
effBattleSystem_effBTLSystem_AttackC_tag *effBTLSys_AttackC_Create(nbFormation_t *pFormation) {
    dds3EffectPartCopy(0);
    return 0;
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
    dds3EffectPartDelete(0);
}

// 0x14d25b0
void effBTLSys_AttackC_Delete2(void *hData) {
    dds3EffectPartDelete(0);
}

// 0x14d27d0
void effBTLSys_AttackC_Draw(void **hData) {
    effBTL_SkillLight_t__Clear(0);
    effBTL_SkillModel_t__Clear(0);
    dds3SetQuake(0, 0);
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillGetTargetFormation(0);
    nbGetUnitWorkFromFormindex(0);
    effBTLPointLightCompulsionOFF();
    effBTLPointLightSet(0, 0);
    effBTLModelColorSet(0, 0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    Mult();
    ToMatrix();
    SDF_VU0__STOREMATRIX(0);
    effBTLPartGetPositionPtr(0, 0, 0);
    dds3EffectPartSetPosition(0, (sdfVector4_t){0});
    dds3EffectPartSetRotateMatrix(0, 0);
    effBTLPartGetRotateMatrixPtr(0, 0);
    dds3EffectPartSetDirection(0, 0);
    dds3EffectPartDraw(0);
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
    dds3EffectPartCopy(0);
    return 0;
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
    dds3EffectPartDelete(0);
}

// 0x14d11c0
void effBTLSys_Attack_Delete2(void *hData) {
    dds3EffectPartDelete(0);
}

// 0x14d1390
void effBTLSys_Attack_Draw(void **hData) {
    effBTL_SkillLight_t__Clear(0);
    effBTL_SkillModel_t__Clear(0);
    dds3SetQuake(0, 0);
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillGetTargetFormation(0);
    nbGetUnitWorkFromFormindex(0);
    effBTLPointLightCompulsionOFF();
    effBTLPointLightSet(0, 0);
    effBTLModelColorSet(0, 0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    Mult();
    ToMatrix();
    SDF_VU0__STOREMATRIX(0);
    effBTLPartGetPositionPtr(0, 0, 0);
    dds3EffectPartSetPosition(0, (sdfVector4_t){0});
    dds3EffectPartSetRotateMatrix(0, 0);
    effBTLPartGetRotateMatrixPtr(0, 0);
    dds3EffectPartSetDirection(0, 0);
    dds3EffectPartDraw(0);
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
    evtSetUnitColorRGB(0, 0, 0);
    effPCPThunderSpherePolyLowDelete(0);
}

// 0x14c8300
void effBTLSys_Bind_Delete2(void *hData) {
    effPCPThunderSpherePolyLowDelete(0);
}

// 0x14c8540
void effBTLSys_Bind_Draw(void **hData) {
    evtSetUnitColorRGB(0, 0, 0);
    effBTLModelGetMarkPosition2(0, 0);
    SDF_VU0__STOREVECTOR(0);
    effPCPThunderSpherePolyLowSetPosition(0, (sdfVector4_t){0});
    effPCPThunderSpherePolyLowDraw(0);
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
    effPCPThunderSpherePolyLowSetColor(0, 0);
}

// 0x14ca020
effBattleSystem_effBTLSystem_Charm_tag *effBTLSys_Charm_Create(nbFormation_t *pFormation) {
    dds3EffectPartCopy(0);
    effBTLSystem_GetScalePtr(0);
    dds3EffectPartSetScale(0, 0);
    return 0;
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
    evtSetUnitColorRGB(0, 0, 0);
    dds3EffectPartDelete(0);
}

// 0x14ca370
void effBTLSys_Charm_Delete2(void *hData) {
    dds3EffectPartDelete(0);
}

// 0x14ca600
void effBTLSys_Charm_Draw(void **hData) {
    evtSetUnitColorRGB(0, 0, 0);
    effBTLModelGetMarkPosition2(0, 0);
    SDF_VU0__STOREVECTOR(0);
    dds3EffectPartSetPosition(0, (sdfVector4_t){0});
    dds3EffectPartDraw(0);
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
    dds3EffectPartSetColor(0, 0);
}

// 0x14c8950
effBattleSystem_effBTLSystem_Close_tag *effBTLSys_Close_Create(nbFormation_t *pFormation) {
    dds3EffectPartCopy(0);
    effBTLSystem_GetScalePtr(0);
    dds3EffectPartSetScale(0, 0);
    return 0;
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
    evtSetUnitColorRGB(0, 0, 0);
    dds3EffectPartDelete(0);
}

// 0x14c8cc0
void effBTLSys_Close_Delete2(void *hData) {
    dds3EffectPartDelete(0);
}

// 0x14c8f50
void effBTLSys_Close_Draw(void **hData) {
    evtSetUnitColorRGB(0, 0, 0);
    effBTLModelGetMarkPosition2(0, 0);
    SDF_VU0__STOREVECTOR(0);
    dds3EffectPartSetPosition(0, (sdfVector4_t){0});
    dds3EffectPartGetHandle(0);
    dds3SpPoly_RollRingSetEndless(0);
    dds3EffectPartDraw(0);
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
    dds3EffectPartSetColor(0, 0);
}

// 0x14ccac0
effBattleSystem_effBTLSystem_CurseCAMP_tag *effBTLSys_CurseCAMP_Create(nbFormation_t *pFormation) {
    dds3EffectPartCopy(0);
    effBTLSystem_GetScalePtr(0);
    dds3EffectPartSetScale(0, 0);
    return 0;
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
    dds3EffectPartDelete(0);
}

// 0x14ccd90
void effBTLSys_CurseCAMP_Delete2(void *hData) {
    dds3EffectPartDelete(0);
}

// 0x14cd020
void effBTLSys_CurseCAMP_Draw(void **hData) {
    dds3EffectPartSetPosition(0, (sdfVector4_t){0});
    dds3EffectPartDraw(0);
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
    dds3EffectPartSetColor(0, 0);
}

// 0x14cc270
effBattleSystem_effBTLSystem_Curse_tag *effBTLSys_Curse_Create(nbFormation_t *pFormation) {
    dds3EffectPartCopy(0);
    effBTLSystem_GetScalePtr(0);
    dds3EffectPartSetScale(0, 0);
    return 0;
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
    dds3EffectPartDelete(0);
}

// 0x14cc4e0
void effBTLSys_Curse_Delete2(void *hData) {
    dds3EffectPartDelete(0);
}

// 0x14cc760
void effBTLSys_Curse_Draw(void **hData) {
    dds3EffectPartSetPosition(0, (sdfVector4_t){0});
    dds3EffectPartDraw(0);
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
    dds3EffectPartSetColor(0, 0);
}

// 0x14d3ac0
effBattleSystem_effBTLSystem_Encount_tag *effBTLSys_Encount_Create(nbFormation_t *pFormation) {
    effBTLCutCreate(0, 0, 0, 0);
    return 0;
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
    effBTLCutDelete(0);
}

// 0x14d3d20
void effBTLSys_Encount_Delete2(void *pData) {
    effBTLCutDelete(0);
}

// 0x14d3e70
void effBTLSys_Encount_Draw(void **pData) {
    effBTLCutDraw(0);
}

// 0x14d3fe0
u32 effBTLSys_Encount_GetLength(void *pData) {
    effBTLCutGetCutEndFrame(0);
    return 0;
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
    evtSetUnitColorRGB(0, 0, 0);
}

// 0x14cb570
void effBTLSys_Fly_Delete2(void *hData) {
}

// 0x14cb6d0
void effBTLSys_Fly_Draw(void **hData) {
    evtSetUnitColorRGB(0, 0, 0);
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
    dds3EffectPartCopy(0);
    effBTLSystem_GetScalePtr(0);
    dds3EffectPartSetScale(0, 0);
    return 0;
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
    mdlShowEffect(0);
    evtSetUnitColorRGB(0, 0, 0);
    dds3EffectPartDelete(0);
}

// 0x14c6620
void effBTLSys_Freeze_Delete2(void *hData) {
    dds3EffectPartDelete(0);
}

// 0x14c68a0
void effBTLSys_Freeze_Draw(void **hData) {
    evtSetUnitColorRGB(0, 0, 0);
    mdlHideEffect(0);
    effBTLModelGetMarkPosition2(0, 0);
    SDF_VU0__STOREVECTOR(0);
    dds3EffectPartSetPosition(0, (sdfVector4_t){0});
    dds3EffectPartDraw(0);
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
    dds3EffectPartSetColor(0, 0);
}

// 0x14cded0
effBattleSystem_effBTLSystem_Hansya_tag *effBTLSys_Hansya_Create(nbFormation_t *pFormation) {
    dds3EffectPartCopy(0);
    dds3EffectPartGetHandle(0);
    effBTLSkillGetID();
    effBTLSystem_GetScalePtr(0);
    dds3EffectPartSetScale(0, 0);
    return 0;
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
    dds3EffectPartDelete(0);
}

// 0x14ce410
void effBTLSys_Hansya_Delete2(void *hData) {
    dds3EffectPartDelete(0);
}

// 0x14ce5a0
void effBTLSys_Hansya_Draw(void **hData) {
    effBTL_SkillLight_t__Clear(0);
    effBTL_SkillModel_t__Clear(0);
    effBTLSkillGetID();
    effBTLPointLightSet(0, 0);
    effBTLModelColorSet(0, 0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    Mult();
    ToMatrix();
    SDF_VU0__STOREMATRIX(0);
    dds3EffectPartSetRotateMatrix(0, 0);
    effBTLPartGetRotateMatrixPtr(0, 0);
    dds3EffectPartSetDirection(0, 0);
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(0);
    dds3EffectPartSetPosition(0, (sdfVector4_t){0});
    nbGetFormForward(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    dds3EffectPartGetHandle(0);
    SethFrom(0, 0);
    mdlSetLightUnity(0, 0, (sdfVector4_t){0});
    dds3EffectPartModelDraw(0);
    dds3EffectPartDraw(0);
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
    dds3EffectPartCopy(0);
    effBTLSystem_GetScalePtr(0);
    dds3EffectPartSetScale(0, 0);
    return 0;
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
    dds3EffectPartDelete(0);
}

// 0x14cf7d0
void effBTLSys_Kyusyuu_Delete2(void *hData) {
    dds3EffectPartDelete(0);
}

// 0x14cf9e0
void effBTLSys_Kyusyuu_Draw(void **hData) {
    effBTL_SkillLight_t__Clear(0);
    effBTL_SkillModel_t__Clear(0);
    effBTLPointLightSet(0, 0);
    effBTLModelColorSet(0, 0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    Mult();
    ToMatrix();
    SDF_VU0__STOREMATRIX(0);
    effBTLPartGetPositionPtr(0, 0, 0);
    dds3EffectPartSetPosition(0, (sdfVector4_t){0});
    dds3EffectPartSetRotateMatrix(0, 0);
    effBTLPartGetRotateMatrixPtr(0, 0);
    dds3EffectPartSetDirection(0, 0);
    dds3EffectPartDraw(0);
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
    effBTLCutCreate(0, 0, 0, 0);
    return 0;
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
    effBTLCutDelete(0);
}

// 0x14d4520
void effBTLSys_Nego_Kaihuku_Delete2(void *hData) {
    effBTLCutDelete(0);
}

// 0x14d4670
void effBTLSys_Nego_Kaihuku_Draw(void **hData) {
    effBTLCutDraw(0);
}

// 0x14d47a0
u32 effBTLSys_Nego_Kaihuku_GetLength(void *hData) {
    effBTLCutGetCutEndFrame(0);
    return 0;
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
    effBTLCutCreate(0, 0, 0, 0);
    return 0;
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
    effBTLCutDelete(0);
}

// 0x14d4ce0
void effBTLSys_Nego_Kyusyu_Delete2(void *hData) {
    effBTLCutDelete(0);
}

// 0x14d4e30
void effBTLSys_Nego_Kyusyu_Draw(void **hData) {
    effBTLCutDraw(0);
}

// 0x14d4f60
u32 effBTLSys_Nego_Kyusyu_GetLength(void *hData) {
    effBTLCutGetCutEndFrame(0);
    return 0;
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
    effBTLCutCreate(0, 0, 0, 0);
    return 0;
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
    effBTLCutDelete(0);
}

// 0x14d54a0
void effBTLSys_Nego_Stone_Delete2(void *hData) {
    effBTLCutDelete(0);
}

// 0x14d55f0
void effBTLSys_Nego_Stone_Draw(void **hData) {
    effBTLCutDraw(0);
}

// 0x14d5720
u32 effBTLSys_Nego_Stone_GetLength(void *hData) {
    effBTLCutGetCutEndFrame(0);
    return 0;
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
    dds3EffectPartCopy(0);
    effBTLSystem_GetScalePtr(0);
    dds3EffectPartSetScale(0, 0);
    return 0;
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
    evtSetUnitColorRGB(0, 0, 0);
    dds3EffectPartDelete(0);
}

// 0x14c79b0
void effBTLSys_Panic_Delete2(void *hData) {
    dds3EffectPartDelete(0);
}

// 0x14c7c30
void effBTLSys_Panic_Draw(void **hData) {
    evtSetUnitColorRGB(0, 0, 0);
    effBTLModelGetMarkPosition2(0, 0);
    SDF_VU0__STOREVECTOR(0);
    dds3EffectPartSetPosition(0, (sdfVector4_t){0});
    dds3EffectPartDraw(0);
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
    dds3EffectPartSetColor(0, 0);
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
    evtSetUnitColorRGB(0, 0, 0);
    effPCPThunderSpherePolyLowDelete(0);
}

// 0x14cad20
void effBTLSys_Paralyze_Delete2(void *hData) {
    effPCPThunderSpherePolyLowDelete(0);
}

// 0x14caf60
void effBTLSys_Paralyze_Draw(void **hData) {
    evtSetUnitColorRGB(0, 0, 0);
    effBTLModelGetMarkPosition2(0, 0);
    SDF_VU0__STOREVECTOR(0);
    effPCPThunderSpherePolyLowSetPosition(0, (sdfVector4_t){0});
    effPCPThunderSpherePolyLowDraw(0);
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
    effPCPThunderSpherePolyLowSetColor(0, 0);
}

// 0x14c9650
effBattleSystem_effBTLSystem_Poison_tag *effBTLSys_Poison_Create(nbFormation_t *pFormation) {
    dds3EffectPartCopy(0);
    effBTLSystem_GetScalePtr(0);
    dds3EffectPartSetScale(0, 0);
    return 0;
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
    evtSetUnitColorRGB(0, 0, 0);
    dds3EffectPartDelete(0);
}

// 0x14c9950
void effBTLSys_Poison_Delete2(void *hData) {
    dds3EffectPartDelete(0);
}

// 0x14c9bd0
void effBTLSys_Poison_Draw(void **hData) {
    evtSetUnitColorRGB(0, 0, 0);
    effBTLModelGetMarkPosition2(0, 0);
    SDF_VU0__STOREVECTOR(0);
    dds3EffectPartSetPosition(0, (sdfVector4_t){0});
    dds3EffectPartDraw(0);
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
    dds3EffectPartSetColor(0, 0);
}

// 0x14d05e0
effBattleSystem_effBTLSystem_Return_tag *effBTLSys_Return_Create(nbFormation_t *pFormation) {
    effBTLCutCreate(0, 0, 0, 0);
    return 0;
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
    effBTLCutDelete(0);
}

// 0x14d0840
void effBTLSys_Return_Delete2(void *hData) {
    effBTLCutDelete(0);
}

// 0x14d09d0
void effBTLSys_Return_Draw(void **hData) {
    effBTLCutDraw(0);
}

// 0x14d0b00
u32 effBTLSys_Return_GetLength(void *hData) {
    effBTLCutGetCutEndFrame(0);
    return 0;
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
    evtSetUnitColorRGB(0, 0, 0);
    effPCPThunderSpherePolyLowDelete(0);
}

// 0x14c5cb0
void effBTLSys_Shock_Delete2(void *pData) {
    effPCPThunderSpherePolyLowDelete(0);
}

// 0x14c5ef0
void effBTLSys_Shock_Draw(void **pData) {
    evtSetUnitColorRGB(0, 0, 0);
    effBTLModelGetMarkPosition2(0, 0);
    SDF_VU0__STOREVECTOR(0);
    effPCPThunderSpherePolyLowSetPosition(0, (sdfVector4_t){0});
    effPCPThunderSpherePolyLowDraw(0);
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
    effPCPThunderSpherePolyLowSetColor(0, 0);
}

// 0x14c6d20
effBattleSystem_effBTLSystem_Sleep_tag *effBTLSys_Sleep_Create(nbFormation_t *pFormation) {
    dds3EffectPartCopy(0);
    effBTLSystem_GetScalePtr(0);
    dds3EffectPartSetScale(0, 0);
    return 0;
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
    evtSetUnitColorRGB(0, 0, 0);
    dds3EffectPartDelete(0);
}

// 0x14c7000
void effBTLSys_Sleep_Delete2(void *hData) {
    dds3EffectPartDelete(0);
}

// 0x14c7280
void effBTLSys_Sleep_Draw(void **hData) {
    evtSetUnitColorRGB(0, 0, 0);
    effBTLModelGetMarkPosition2(0, 0);
    SDF_VU0__STOREVECTOR(0);
    dds3EffectPartSetPosition(0, (sdfVector4_t){0});
    dds3EffectPartDraw(0);
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
    dds3EffectPartSetColor(0, 0);
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
    dds3EffectPartCopy(0);
    dds3EffectPartGetHandle(0);
    effBTLSystem_GetScalePtr(0);
    dds3EffectPartSetScale(0, 0);
    return 0;
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
    dds3EffectPartDelete(0);
}

// 0x14cd820
void effBTLSys_Stone_Dead_Delete2(void *hData) {
    dds3EffectPartDelete(0);
}

// 0x14cd9c0
void effBTLSys_Stone_Dead_Draw(void **hData) {
    mdlHideEffect(0);
    effBTLModelGetMarkPosition2(0, 0);
    SDF_VU0__STOREVECTOR(0);
    dds3EffectPartSetPosition(0, (sdfVector4_t){0});
    dds3EffectPartDraw(0);
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
    mdlShowEffect(0);
}

// 0x14cbcf0
void effBTLSys_Stone_Delete2(void *hData) {
}

// 0x14cbe50
void effBTLSys_Stone_Draw(void **hData) {
    mdlHideEffect(0);
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
    sdfDevLoadFileUnity_25061072(0, 0, 0, 0);
    MarkTmxIndex(0);
    LoadFileObject(0, 0, 0);
}

// 0x14d6bc0
void effBTLSystemCut1Delete(effBTLCutHandle_t **hBTLCutEffect) {
    effBTLCutGetUserData(0);
    effBTLCutDelete(0);
    effBTLDelete(0);
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
      while (v5 < SLODWORD(v6->m_Items[i]->pTganame->max_length))
      {
        pTexture = (*pPartList)->m_Items[i]->pTexture;
        v7 = &pTexture->obj.klass + v5++;
        v7[4] = 0;
        v6 = *pPartList;
        if (i >= LODWORD((*pPartList)->max_length))
      }
    }
  }
}

// 0x14c4db0
void effBTLSystem_Part_DataLoad(effBattleSystem_effBTLSystem_Part_tag ***pPartList, u32 count) {
    sdfDevLoadFileUnity_25061072(0, 0, 0, 0);
    MarkTmxIndex(0);
    LoadPrefab_16624656(0, 0, 0, 0);
    LoadFileObject(0, 0, 0);
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
      }
      else
      {
        type = v15->type;
        v21 = (*pPartList)->m_Items[i]->pData;
        v15->hPart = dds3EffectPartCreate(type, &v21->obj, 0, 0);
        {
        }
      }
      billClrTexture(0);
      v22 = *pPartList;
      if (i >= LODWORD((*pPartList)->max_length))
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
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    effBTLSystemCreate(0, 0);
    return 0;
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
