#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct FieldChrHD FieldChrHD;
typedef struct GunHD GunHD;
typedef struct Sprite3D_t Sprite3D_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3Effect_DistortionBlurParam_t dds3Effect_DistortionBlurParam_t;
typedef struct dds3Effect_PartialMultiFilterParam_t dds3Effect_PartialMultiFilterParam_t;
typedef struct dds3Effect_PartialMultiFilter_t dds3Effect_PartialMultiFilter_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ObjectBaseControlWorkData_t dds3ObjectBaseControlWorkData_t;
typedef struct effDistortionBlurHandle_t effDistortionBlurHandle_t;
typedef struct effHandle_t effHandle_t;
typedef struct effPartHandle_t effPartHandle_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct fldNpcLightTbl_tag fldNpcLightTbl_tag;
typedef struct fldNpc_tag fldNpc_tag;
typedef struct fldTakaraWork_tag fldTakaraWork_tag;
typedef struct fldUnitControl_t fldUnitControl_t;
typedef struct fld_Npc_fldNpcSdwWork_tag fld_Npc_fldNpcSdwWork_tag;
typedef struct mdlEffectResrcList_t mdlEffectResrcList_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;
typedef struct sdfModelTexList_t sdfModelTexList_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

struct fld_Npc_fldNpcSdwWork_tag {
    evtUnitHandle_t *hEveUnit;
    dds3Basic_t *unitBasic;
    s32 id1;
    s32 id2;
    f32 x;
    f32 y;
    f32 z;
    f32 dir;
    f32 size;
    bool lookIn;
    bool RangeIn;
    f32 len;
    f32 dot;
    bool bSkip;
};

static fldNpcLightTbl_tag *fldNpcLightTbl[32];
static f32 gFldNpcX;
static f32 gFldNpcY;
static f32 gFldNpcZ;
static f32 gFldNpcR;
static f32 gFldNpcOY;
static f32 gFldNpcCY;
static f32 gFldNpcCS;
static s32 gFldNowTalk;
static s32 gFldNowTalkIdx;
static fldNpc_tag *fldNpc[32];
static s32 fldNpcNum;
static sdfTexHandle_t *fldIFTexHandle1;
static sdfTexHandle_t *fldIFTexHandle2;
static sdfTexHandle_t *fldIFTexHandle3;
static sdfTexHandle_t *fldIFTexHandle4;
static void *fldMaga01TexHandle[1];
static sdfMemHandle_t *hFldItfWM;
static void *pFldItfWM;
static sdfMemHandle_t *hFldItfWM2;
static void *pFldItfWM2;
static sdfMemHandle_t *hFldItfWM3;
static void *pFldItfWM3;
static sdfMemHandle_t *hFldItfFld;
static void *pFldItfFld;
static sdfMemHandle_t *hFldItfFld2;
static void *pFldItfFld2;
static sdfMemHandle_t *hFldMaga;
static void *pFldMaga;
static sdfMemHandle_t *hFldNpcIcon;
static void *pFldNpcIcon;
static effHandle_t *eFldNpcIcon;
static sdfMemHandle_t *hFldDmgEff;
static void *pFldDmgEff;
static effHandle_t *eFldDmgEff;
static s32 gFldDmgEff;
static sdfMemHandle_t *hFldSibukiEff;
static void *pFldSibukiEff;
static effHandle_t *eFldSibukiEff[8];
static s32 gFldSibukiEff;
static sdfMemHandle_t *hFldTDmgEff;
static void *pFldTDmgEff;
static effHandle_t *eFldTDmgEff;
static dds3Basic_t *fldNpc01Basic;
static s32 gfldNpc01Id;
static s32 fldNpc01RGBA;
static f32 fldNpc01RGBA_Cnt;
static void *mhfldNpcFile[64];
static s32 gfldNpcSize[64];
static sdfMemHandle_t *mhfldGenNpcFile;
static void *gfldGenNpcPtr;
static s32 gfldGenNpcSize;
static sdfMemHandle_t *mhfldTakara01File;
static void *gfldTakara01Ptr;
static s32 gfldTakara01Size;
static sdfMemHandle_t *mhfldTakara02File;
static void *gfldTakara02Ptr;
static s32 gfldTakara02Size;
static sdfMemHandle_t *mhfldTakara03File;
static void *gfldTakara03Ptr;
static s32 gfldTakara03Size;
static void *mhfldTakara01FileC;
static void *mhfldTakara02FileC;
static void *mhfldTakara03FileC;
static sdfMemHandle_t *mhfldTakaraGtFile;
static void *gfldTakaraGtPtr;
static s32 gfldTakaraGtSize;
static effPartHandle_t *gfldTakaraGtEff[32];
static sdfTexHandle_t *gfldTakaraLtTex;
static sdfMemHandle_t *mhfldTakaraBBFile;
static void *gfldTakaraBBPtr;
static sdfMemHandle_t *hFldTakara1Pika;
static void *pFldTakara1Pika;
static effHandle_t *eFldTakara1Pika;
static s32 gfldTakaraNum;
static fldTakaraWork_tag *gfldTakaraWork[32];
static effDistortionBlurHandle_t *fldNpcBlurD;
static dds3Effect_PartialMultiFilter_t *fldNpcBlur_MultiFilterBuff;
static dds3Effect_PartialMultiFilterParam_t *fldNpcBlur_MultiFilter_Param;
static f32 gFldEACnt;
static f32 fldEADraw_aanm;
static s32 fldEADraw_oldalp;
static s32 fldEADraw_oldpat;
static s32 fldEADraw_texptn;
static f32 fldVLDraw_cntf;
static char *npc_modelname[12];
static char *npc_modelname2[24];
static char *npc_pbname[12];
static char *npc_pbname2[24];
static sdfVector4_t gFldWavePosOld;
static f32 gFldWaveLen;
static s32 fldNpcCalc_wavecnt;
static fld_Npc_fldNpcSdwWork_tag *npcsdw_work[16];
static s32 npcsdw_work_num;
static s32 npcsdw_nowidx;
static f32 npcsdw_nowalp;
static f32 testdir;

void AttachModel(dds3Basic_t *basic, s32 major, s32 minor);
void AttachModel_26590400(dds3Basic_t *basic, char *key, char *name);
bool ChkUseSceneLight(evtUnitHandle_t **h);
void CreateNPCEffect(dds3Basic_t **bas, s32 idx, s32 id, char *pbname);
void DetachModel(dds3Basic_t *basic, bool ul);
void DrwSprite2D_17010048(s32 x, s32 y, s32 w, s32 h, s32 u, s32 v, s32 uw, s32 vh, u32 rgba, sdfTexHandle_t *th);
f32 EulerAngleAxisY(void);
void FromEuler(f32 aRotateX, f32 aRotateY, f32 aRotateZ);
void FromRotation(f32 aAngle);
bool IsDLCField(s32 area);
u8 **LoadFileByte(AssetBundleCtrl *this, char *key, char *path_name);
void *LoadFileObject(AssetBundleCtrl *this, char *key, char *path_name);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
void Mult(void);
f32 OOYDEG(f32 a);
f32 OOYRAD(f32 a);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
f32 SDF_VU0__GETLENGTH(void);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__NORMALIZE(void);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
void SetBlendPower(FieldChrHD *this, f32 aBlendPower);
void SetEnemyUI(dds3DefaultMain *this, bool disp, s32 x, s32 y, s32 type, bool bad, bool direction, f32 cameraDir, f32 playerDir);
void SetEveUnit(GunHD *this, evtUnitHandle_t *hunit_tmp);
void SetLayerAll2(FieldChrHD *this, void *rootobj, s32 setlayer);
void SetRadarUI(dds3DefaultMain *this, bool disp, s32 x, s32 y, s32 type);
dds3Basic_t *dds3AddUnitObjectBasic(u32 serialID, sdfVector4_t aPos, sdfVector4_t aRot);
f32 dds3CameraObjectBasicGetFovy(dds3Basic_t **pBasic);
void dds3CameraObjectBasicGetTgtCam(dds3Basic_t **pBasic, sdfVector4_t *tgtpos, sdfVector4_t *campos);
void dds3DeleteUnitObjectBasic(dds3Basic_t **aPtr);
effHandle_t *dds3EffectCopy(void **pData, s32 bPos, bool tbldata);
void dds3EffectDelete(void **pData);
effDistortionBlurHandle_t *dds3EffectDistortionBlurCreate(dds3Effect_DistortionBlurParam_t *pParam);
void dds3EffectDistortionBlurDelete(effDistortionBlurHandle_t **hDistortionBlur);
void dds3EffectDistortionBlurDraw(effDistortionBlurHandle_t **hDistortionBlur, bool bPS2mode, s32 SkillID);
void dds3EffectDistortionBlur_SetArea(f32 area_x, f32 area_y);
void dds3EffectDistortionBlur_SetMoya(f32 moyaalp);
void dds3EffectDraw(void **pData);
void dds3EffectDrawOff(void **pData);
u16 dds3EffectGetState(effHandle_t *hEffect);
effHandle_t *dds3EffectLoad(void **pD3P, s32 bPos, bool tbldata);
effPartHandle_t *dds3EffectPartCreate(u16 type, void *pData);
void dds3EffectPartDelete(effPartHandle_t **hEffPart);
void dds3EffectPartDraw(effPartHandle_t **hEffPart);
void dds3EffectPartSetPosition(effPartHandle_t **hEffPart, sdfVector4_t pPos);
dds3Effect_PartialMultiFilter_t *dds3EffectPartialMultiFilterCreate(dds3Effect_PartialMultiFilterParam_t *pParam);
void dds3EffectPartialMultiFilterDraw(dds3Effect_PartialMultiFilter_t **hPartialMultiFilter);
void dds3EffectReset(effHandle_t *hEffect);
void dds3EffectSetLoop(effHandle_t **hEffect, u8 loop);
void dds3EffectSetPosition(void **pData, sdfVector4_t pPos);
dds3Basic_t *dds3GetActiveCameraSceneBasic(dds3Basic_t **pBasic);
dds3Basic_t *dds3GetActiveScene(void);
dds3ObjectBaseControlWorkData_t *dds3GetBaseControlWorkData(dds3Basic_t **pObjectBasic);
void dds3GetPosPoseSet(dds3Basic_t **pBasic);
void dds3GetRotPoseSet(dds3Basic_t **pBasic);
char *dds3GetScriptProcName(void);
evtUnitHandle_t *dds3GetUnitHandleObjectBasic(dds3Basic_t **b);
s32 dds3ObjectBaseCheckFlag(dds3Basic_t **pObjectBasic, u32 flag);
void *dds3ObjectBaseGetModelHandle(dds3Basic_t **pObjectBasic);
void dds3ObjectBaseMakeUnit(dds3Basic_t **pObjectBasic, s32 major, s32 minor);
void dds3ObjectBaseOffFlag(dds3Basic_t **pObjectBasic, u32 flag);
void dds3ObjectBaseOnFlag(dds3Basic_t **pObjectBasic, u32 flag, bool alock);
u32 dds3SerializeID(void);
void dds3SetBasicName(dds3Basic_t **basic, char *name);
void dds3SetRotPoseSet(dds3Basic_t **pBasic, sdfVector4_t rot);
void dds3SetSclPoseSet(dds3Basic_t **pBasic, sdfVector4_t scl);
void dds3UnitObjectBasicSetOt(dds3Basic_t **aPtr, s32 idx);
void drawSprite3D(sdfTexHandle_t *th, Sprite3D_t *spr3d);
bool evtBitCheck(s32 no);
evtUnitHandle_t *evtGetUnitHandle(s32 serial);
evtUnitHandle_t *evtGetUnitHandle2(dds3Basic_t *unit);
void evtSetUnitLightAndAmbient(evtUnitHandle_t **h, u32 frame, u32 lrgb, u32 argb);
void evtSetUnitLightDir(evtUnitHandle_t **h, s32 frame);
void evtUnitLightOn(evtUnitHandle_t **h);
s32 fldCamNpcCamChk(char **pName);
s32 fldChkVortex(void);
void fldDLCEncountCheck(s32 *encpid);
void fldEADraw(void);
void fldEveHit_AddEveHitItemBox(s32 idx, f32 x, f32 y, f32 z, f32 r);
void fldEveHit_AddEveHitNpc(char **resname, s32 eveidx, f32 x, f32 y, f32 z, f32 r, s32 hojiID, s32 npcidx);
s32 fldEveHit_ChkNpcScr(s32 npcidx);
s32 fldEveHit_ChkTakaraScr(s32 takaraidx);
void fldEventUpdateEx_Unity(s32 fld, s32 area, char *scr_label, char *cam_name);
s32 fldGbChkNpc(s32 fld, s32 area, s32 hojiID);
s32 fldGbChkTakaraOpen(s32 idx);
fldUnitControl_t *fldGetUnitControl(void);
void fldHitProgramAdd(f32 x, f32 y, f32 z, f32 r, f32 h, s32 npcID);
void fldMakeFilePath(char **pathstr, s32 field, s32 area);
void fldNpcLightSet(evtUnitHandle_t *hEveUnit);
void fldNpcModelEnd(s32 id);
void fldNpcModelStart(s32 id, f32 x, f32 y, f32 z, sdfVector4_t rot);
void fldNpcShadow_Add(evtUnitHandle_t **hEveUnit, dds3Basic_t **aBasic, s32 id1, s32 id2, f32 x, f32 y, f32 z, f32 dir, f32 size);
void fldNpcShadow_Calc(void);
void fldNpcShadow_Clear(void);
s32 fldProcAmChk(void);
s32 fldProcCampChk(void);
s8 fldProcCheckFlag(u32 flag);
void fldSePlay(s32 seid);
s8 fldSeqCheckFlag(u32 flag);
void fldSetCharAdd(char *name, void *obj);
void fldSibukiStart(f32 x, f32 y, f32 z);
void fldVLDraw(void);
void fldWaveStart(f32 x, f32 y, f32 z);
s32 mdlChkMotionEndForUnity_26964128(void *obj, s32 index);
void mdlCreateEffectResrc_D3P(mdlEffectResrcList_t **listPtr, void *data, void **pTexture);
bool mdlGenEffect(dds3ModelHandle_t **aHandle, s32 aGroup, s32 aPlayGroup);
void mdlLoopMotionForUnity(void *obj, char *name, s32 value);
FieldChrHD *mdlSetHD(void *obj, s32 mode, evtUnitHandle_t *hunit, s32 layer);
void mdlSingleMotionForUnity(void *obj, char *name, s32 value, bool reset, s32 index);
s32 nbGetEncountCnt(void);
s32 nbGetEncountMax(s32 id);
void ooyTestDrawMaruKage(f32 x, f32 y, f32 z, f32 r, s32 a);
void rsetAlpha(s32 mode);
void rsetOtOfs(s32 otofs);
void rsetTest(s32 ate, s32 atst, s32 aref, s32 afail, s32 date, s32 datm, s32 zte, s32 ztst);
f32 sdfAtan2(f32 aY, f32 aX);
f32 sdfCos(f32 aRadius);
void *sdfDevLoadFileUnity_25061072(char *aFilename, u8 ***aTopPtr, s32 aSizePtr, char *akey);
f32 sdfFabs(f32 c);
s32 sdfModelGetMarkPos(sdfModelRootNode_t **aRoot, s32 aId);
s32 sdfModelGetMarkPosUnity(sdfModelRootNode_t *aRoot, s32 aId);
sdfModelRootNode_t *sdfModelMakeUnity(sdfModelTexList_t *aTexList, u8 **bData, s32 bPos);
f32 sdfSin(f32 aRadius);
f32 sdfSqrt(f32 aValue);
void sdfTexFreeDelayed(sdfTexHandle_t *aHandle);
sdfTexHandle_t *sdfTexSet(void *aTex);
void takara_animset(s32 index, s32 mode);

// 0x1482cc0
s32 CCOL(s32 r, s32 g, s32 b, s32 a) {
  return r | (g << 8) | (b << 16) | (a << 24);
}

// 0x1482cd0
f32 CROT(f32 a) {
  return (a * 3.14) / 180.0;
}

// 0x1482ca0
u16 CUV(s32 a) {
  return 16 * a;
}

// 0x1482cb0
f32 CVT(f32 a) {
  return a * 0.0625;
}

// 0x148e7d0
void CreateNPCEffect(dds3Basic_t **bas, s32 idx, s32 id, char *pbname) {
    dds3GetBaseControlWorkData(0);
    sdfDevLoadFileUnity_25061072(0, 0, 0, 0);
    sdfModelMakeUnity(0, 0, 0);
    LoadFileByte(0, 0, 0);
    mdlCreateEffectResrc_D3P(0, 0, 0);
    mdlGenEffect(0, 0, 0);
}

// 0x14834e0
void EffDelete(effHandle_t **handle) {
  Il2CppObject *pData;

  pData = 0;
  if (*handle)
  {
    pData = *handle;
    dds3EffectDelete(&pData);
    *handle = 0;
  }
}

// 0x148cd90
void fldBasyoDraw(s32 w, s32 x, s32 y) {
  ;
}

// 0x148c890
void fldDmgStart(f32 x, f32 y, f32 z) {
    dds3EffectReset(0);
    dds3EffectSetPosition(0, (sdfVector4_t){0});
}

// 0x148d000
void fldEADraw(void) {
    rsetOtOfs(0);
    rsetAlpha(0);
    rsetTest(0, 0, 0, 0, 0, 0, 0, 0);
    sdfSin(0);
    fldDLCEncountCheck(0);
    fldChkVortex();
    nbGetEncountCnt();
    nbGetEncountMax(0);
    SetEnemyUI(0, 0, 0, 0, 0, 0, 0, 0, 0);
}

// 0x148cd80
void fldEsDrawR(s32 cx, s32 cy, s32 ox, s32 oy, s32 w, s32 h, s32 u, s32 v, s32 uw, s32 vh, f32 r) {
  ;
}

// 0x1489850
void fldItemBoxAdd(s32 idx, f32 x, f32 y, f32 z, sdfVector4_t rot) {
    dds3EffectLoad(0, 0, 0);
    fldSetCharAdd(0, 0);
    mdlSetHD(0, 0, 0, 0);
    SetLayerAll2(0, 0, 0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    FromRotation(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    Mult();
    SDF_VU0__STOREVECTOR(0);
    dds3SerializeID();
    dds3AddUnitObjectBasic(0, (sdfVector4_t){0}, (sdfVector4_t){0});
    dds3SetBasicName(0, 0);
    dds3ObjectBaseMakeUnit(0, 0, 0);
    dds3SetSclPoseSet(0, (sdfVector4_t){0});
    dds3ObjectBaseOnFlag(0, 0, 0);
    dds3ObjectBaseGetModelHandle(0);
    fldGbChkTakaraOpen(0);
    mdlLoopMotionForUnity(0, 0, 0);
    mdlSingleMotionForUnity(0, 0, 0, 0, 0);
    dds3GetRotPoseSet(0);
    EulerAngleAxisY();
    OOYDEG(0);
    fldHitProgramAdd(0, 0, 0, 0, 0, 0);
    evtGetUnitHandle2(0);
    evtUnitLightOn(0);
    SetEveUnit(0, 0);
    evtSetUnitLightAndAmbient(0, 0, 0, 0);
    OOYRAD(0);
    sdfSin(0);
    sdfCos(0);
    SDF_VU0__NORMALIZE();
    evtSetUnitLightDir(0, 0);
    fldEveHit_AddEveHitItemBox(0, 0, 0, 0, 0);
}

// 0x148b9a0
void fldItemBoxAllFree(void) {
    dds3EffectDelete(0);
    dds3EffectPartDelete(0);
}

// 0x148bdc0
void fldItemBoxCalcTask(void) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    OOYRAD(0);
    FromRotation(0);
    SDF_VU0__STOREVECTOR(0);
    dds3SetRotPoseSet(0, (sdfVector4_t){0});
    dds3ObjectBaseGetModelHandle(0);
    takara_animset(0, 0);
    dds3EffectPartCreate(0, 0);
    dds3EffectReset(0);
    mdlChkMotionEndForUnity_26964128(0, 0);
    mdlLoopMotionForUnity(0, 0, 0);
    fldProcCheckFlag(0);
    dds3EffectPartDelete(0);
}

// 0x148b800
void fldItemBoxOpen(s32 idx) {
}

// 0x148cff0
void fldKoudouBtnDraw(s32 x, s32 y) {
  ;
}

// 0x148cda0
void fldKoudouDraw(void) {
  if (fldGb->fieldID <= 199)
  {
    rsetOtOfs(71);
    rsetAlpha(0);
    rsetTest(1, 0, 128, 3, 0, 0, 1, 1);
    DrwSprite2D_17010048(135, 292, 121, 24, 1, 93, 121, 24, 0x80808080, fldIFTexHandle1);
    DrwSprite2D_17010048(135, 316, 121, 24, 1, 116, 121, -24, 0x80808080, fldIFTexHandle1);
    DrwSprite2D_17010048(256, 292, 121, 24, 121, 93, -121, 24, 0x80808080, fldIFTexHandle1);
    DrwSprite2D_17010048(256, 316, 121, 24, 121, 116, -121, -24, 0x80808080, fldIFTexHandle1);
    rsetAlpha(0);
  }
}

// 0x1486270
void fldNpcAdd(s32 Type, f32 x, f32 y, f32 z, sdfVector4_t rot, s32 hojiID, char **name, s32 eveidx) {
    evtBitCheck(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    FromRotation(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    Mult();
    SDF_VU0__STOREVECTOR(0);
    dds3SerializeID();
    dds3AddUnitObjectBasic(0, (sdfVector4_t){0}, (sdfVector4_t){0});
    dds3SetBasicName(0, 0);
    dds3ObjectBaseMakeUnit(0, 0, 0);
    dds3SetSclPoseSet(0, (sdfVector4_t){0});
    evtGetUnitHandle(0);
    AttachModel(0, 0, 0);
    dds3ObjectBaseGetModelHandle(0);
    mdlLoopMotionForUnity(0, 0, 0);
    dds3ObjectBaseOnFlag(0, 0, 0);
    evtGetUnitHandle2(0);
    fldNpcLightSet(0);
    fldSetCharAdd(0, 0);
    OOYRAD(0);
    FromEuler(0, 0, 0);
    dds3SetRotPoseSet(0, (sdfVector4_t){0});
    mdlSetHD(0, 0, 0, 0);
    SetEveUnit(0, 0);
    SetLayerAll2(0, 0, 0);
    dds3EffectCopy(0, 0, 0);
    dds3EffectLoad(0, 0, 0);
    LoadFileObject(0, 0, 0);
    fldHitProgramAdd(0, 0, 0, 0, 0, 0);
    fldEveHit_AddEveHitNpc(0, 0, 0, 0, 0, 0, 0, 0);
}

// 0x148ed00
void fldNpcCalc(void) {
    fldSeqCheckFlag(0);
    fldProcCampChk();
    fldProcAmChk();
    dds3EffectGetState(0);
    fldGetUnitControl();
    dds3EffectSetPosition(0, (sdfVector4_t){0});
    dds3GetPosPoseSet(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    fldWaveStart(0, 0, 0);
    fldSibukiStart(0, 0, 0);
    fldNpcShadow_Calc();
    fldGbChkNpc(0, 0, 0);
    fldProcCheckFlag(0);
    fldEveHit_ChkTakaraScr(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    EulerAngleAxisY();
    OOYDEG(0);
    fldEveHit_ChkNpcScr(0);
    fldCamNpcCamChk(0);
    fldNpcModelEnd(0);
    fldSePlay(0);
    fldNpcModelStart(0, 0, 0, 0, (sdfVector4_t){0});
}

// 0x14844d0
void fldNpcClear(bool clrflg) {
  fld_Npc_c *v3;
  u64 v4;
  s32 v5;
  struct fldNpc_tag_array *fldNpc;
  u32 *v11;
  u64 *v12;
  struct fldNpc_tag_array *v14;
  struct fldNpc_tag_array *v16;
  struct fldNpc_tag_array *v18;
  struct fldNpc_tag_array *v20;
  struct fldNpc_tag_array *v22;
  struct fldNpc_tag_array *v24;
  struct fldNpc_tag_array *v26;
  struct fldNpc_tag_array *v28;
  struct fldNpc_tag_array *v30;
  struct fldNpc_tag_array *v32;
  struct fldNpc_tag_array *v34;
  struct fldNpc_tag_array *v36;
  struct fldNpc_tag_array *v38;
  struct fldNpc_tag_array *v41;
  struct fldNpc_tag_array *v44;
  struct fldNpc_tag_array *v47;
  u32 v49;
  Il2CppObject *pData;

  pData = 0;
  v4 = 0;
  do
  {
    v11 = fldNpc;
    v12 = Allocate(fldNpc_tag);
    _ctor(v12, 0);
    *&v11[2 * v4 + 8] = v12;
    v14 = fldNpc;
    v14->m_Items[v4]->Type = 0;
    v16 = fldNpc;
    v16->m_Items[v4]->x = 0.0;
    v18 = fldNpc;
    v18->m_Items[v4]->y = 0.0;
    v20 = fldNpc;
    v20->m_Items[v4]->z = 0.0;
    v22 = fldNpc;
    v22->m_Items[v4]->Basic = 0;
    v24 = fldNpc;
    v24->m_Items[v4]->cntf = 0.0;
    v26 = fldNpc;
    v26->m_Items[v4]->cnti = 0;
    v28 = fldNpc;
    v28->m_Items[v4]->cntAnmf = 0.0;
    v30 = fldNpc;
    v30->m_Items[v4]->cntAnmi = 0;
    v32 = fldNpc;
    v32->m_Items[v4]->npcmodel = 0;
    v34 = fldNpc;
    v34->m_Items[v4]->hojiID = 0;
    v36 = fldNpc;
    v36->m_Items[v4]->ItemBoxIdx = 0;
    v38 = fldNpc;
    if (v38->m_Items[v4]->d3p)
    {
      v41 = fldNpc;
      pData = v41->m_Items[v4]->d3p;
      dds3EffectDelete(&pData);
    }
    v44 = fldNpc;
    v44->m_Items[v4]->d3p = 0;
    if (clrflg)
    {
      v47 = fldNpc;
      v47->m_Items[v4]->fldObj = 0;
    }
    ++v4;
    v5 = (v49 >> 9) & 1;
  }
  while (v4 != 32);
  fldNpcNum = 0;
  eFldNpcIcon = 0;
  gFldNowTalk = 0;
  fldNpcShadow_Clear(v3);
}

// 0x1493350
void fldNpcDraw(void) {
    fldSeqCheckFlag(0);
    dds3ObjectBaseGetModelHandle(0);
    sdfSin(0);
    SetBlendPower(0, 0);
    dds3EffectDistortionBlurDraw(0, 0, 0);
    evtBitCheck(0);
    dds3EffectDistortionBlur_SetMoya(0);
    dds3EffectDistortionBlur_SetArea(0, 0);
    dds3EffectPartialMultiFilterCreate(0);
    dds3EffectPartialMultiFilterDraw(0);
    dds3EffectGetState(0);
    dds3EffectDraw(0);
    dds3EffectDrawOff(0);
    fldEADraw();
    fldVLDraw();
    fldGbChkNpc(0, 0, 0);
    ooyTestDrawMaruKage(0, 0, 0, 0, 0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    dds3ObjectBaseOffFlag(0, 0);
    dds3GetPosPoseSet(0);
    SDF_VU0__STOREVECTOR(0);
    sdfSqrt(0);
    dds3ObjectBaseOnFlag(0, 0, 0);
    dds3GetUnitHandleObjectBasic(0);
    sdfModelGetMarkPosUnity(0, 0);
    dds3EffectDelete(0);
    dds3EffectSetPosition(0, (sdfVector4_t){0});
    dds3EffectPartSetPosition(0, (sdfVector4_t){0});
    dds3EffectPartDraw(0);
    sdfModelGetMarkPos(0, 0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__NORMALIZE();
    rsetOtOfs(0);
    drawSprite3D(0, 0);
}

// 0x1483dd0
void fldNpcFree(void) {
    dds3EffectDistortionBlurDelete(0);
    sdfTexFreeDelayed(0);
    dds3EffectDelete(0);
}

// 0x1495b40
void fldNpcHojiRefresh(void) {
    fldGbChkNpc(0, 0, 0);
    dds3ObjectBaseOnFlag(0, 0, 0);
    dds3ObjectBaseOffFlag(0, 0);
}

// 0x1495e20
void fldNpcLightLoad(s32 field) {
    fldMakeFilePath(0, 0, 0);
    evtBitCheck(0);
    IsDLCField(0);
    LoadFileByte(0, 0, 0);
}

// 0x14853e0
void fldNpcLightSet(evtUnitHandle_t *hEveUnit) {
    dds3ObjectBaseGetModelHandle(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    EulerAngleAxisY();
    OOYDEG(0);
    evtUnitLightOn(0);
    dds3ObjectBaseOnFlag(0, 0, 0);
    OOYRAD(0);
    sdfSin(0);
    sdfCos(0);
    SDF_VU0__NORMALIZE();
    evtSetUnitLightDir(0, 0);
    evtSetUnitLightAndAmbient(0, 0, 0, 0);
    dds3GetPosPoseSet(0);
    SDF_VU0__STOREVECTOR(0);
    fldNpcShadow_Add(0, 0, 0, 0, 0, 0, 0, 0, 0);
}

// 0x1483570
void fldNpcLoad(void) {
    dds3EffectDelete(0);
    dds3EffectLoad(0, 0, 0);
    sdfTexSet(0);
    LoadFileObject(0, 0, 0);
    dds3EffectDistortionBlurCreate(0);
}

// 0x1482e20
void fldNpcLoad1st(void) {
    LoadFileByte(0, 0, 0);
    LoadPrefab_16624656(0, 0, 0, 0);
}

// 0x148ecf0
void fldNpcModelAllEnd(void) {
  ;
}

// 0x148eb50
void fldNpcModelEnd(s32 id) {
    DetachModel(0, 0);
    dds3DeleteUnitObjectBasic(0);
}

// 0x148e040
void fldNpcModelStart(s32 id, f32 x, f32 y, f32 z, sdfVector4_t rot) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    FromRotation(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    Mult();
    SDF_VU0__STOREVECTOR(0);
    dds3SerializeID();
    dds3AddUnitObjectBasic(0, (sdfVector4_t){0}, (sdfVector4_t){0});
    dds3UnitObjectBasicSetOt(0, 0);
    dds3SetBasicName(0, 0);
    dds3ObjectBaseOnFlag(0, 0, 0);
    dds3ObjectBaseMakeUnit(0, 0, 0);
    AttachModel_26590400(0, 0, 0);
    evtGetUnitHandle2(0);
    evtUnitLightOn(0);
    evtSetUnitLightAndAmbient(0, 0, 0, 0);
    evtSetUnitLightDir(0, 0);
    CreateNPCEffect(0, 0, 0, 0);
}

// 0x1485cf0
void fldNpcShadow_Add(evtUnitHandle_t **hEveUnit, dds3Basic_t **aBasic, s32 id1, s32 id2, f32 x, f32 y, f32 z, f32 dir, f32 size) {
  struct fld_Npc_StaticFields *static_fields;
  s64 npcsdw_work_num;
  struct fld_Npc_fldNpcSdwWork_tag_array *npcsdw_work;
  struct fld_Npc_fldNpcSdwWork_tag_array *v26;
  u64 *v27;
  struct fld_Npc_fldNpcSdwWork_tag_array *v30;
  struct fld_Npc_fldNpcSdwWork_tag_array *v32;
  struct fld_Npc_fldNpcSdwWork_tag_array *v34;
  struct fld_Npc_fldNpcSdwWork_tag_array *v36;
  struct fld_Npc_fldNpcSdwWork_tag_array *v38;
  struct fld_Npc_fldNpcSdwWork_tag_array *v40;
  struct fld_Npc_fldNpcSdwWork_tag_array *v42;
  struct fld_Npc_fldNpcSdwWork_tag_array *v44;
  struct fld_Npc_fldNpcSdwWork_tag_array *v46;
  struct fld_Npc_fldNpcSdwWork_tag_array *v48;
  struct fld_Npc_fldNpcSdwWork_tag_array *v50;
  struct fld_Npc_fldNpcSdwWork_tag_array *v52;
  struct fld_Npc_fldNpcSdwWork_tag_array *v54;
  struct fld_Npc_fldNpcSdwWork_tag_array *v56;
  System_String_o *name;
  struct fld_Npc_fldNpcSdwWork_tag_array *v60;

  else
  {
    static_fields = fld_Npc->static_fields;
    npcsdw_work_num = static_fields->npcsdw_work_num;
    if (npcsdw_work_num > 14)
      return;
  }
  npcsdw_work = static_fields->npcsdw_work;
  if (!npcsdw_work->m_Items[npcsdw_work_num])
  {
    v26 = npcsdw_work;
    v27 = Allocate(fld_Npc_fldNpcSdwWork_tag);
    _ctor(v27, 0);
    v26->m_Items[npcsdw_work_num] = v27;
  }
  {
  }
  v30 = npcsdw_work;
  v30->m_Items[npcsdw_work_num]->hEveUnit = *hEveUnit;
  v32 = npcsdw_work;
  v32->m_Items[npcsdw_work_num]->unitBasic = *aBasic;
  v34 = npcsdw_work;
  v34->m_Items[npcsdw_work_num]->id1 = id1;
  v36 = npcsdw_work;
  v36->m_Items[npcsdw_work_num]->id2 = id2;
  v38 = npcsdw_work;
  v38->m_Items[npcsdw_work_num]->x = x;
  v40 = npcsdw_work;
  v40->m_Items[npcsdw_work_num]->y = y;
  v42 = npcsdw_work;
  v42->m_Items[npcsdw_work_num]->z = z;
  v44 = npcsdw_work;
  v44->m_Items[npcsdw_work_num]->dir = dir;
  v46 = npcsdw_work;
  v46->m_Items[npcsdw_work_num]->size = size;
  v48 = npcsdw_work;
  v48->m_Items[npcsdw_work_num]->lookIn = 0;
  v50 = npcsdw_work;
  v50->m_Items[npcsdw_work_num]->RangeIn = 0;
  v52 = npcsdw_work;
  v52->m_Items[npcsdw_work_num]->len = 99999.0;
  v54 = npcsdw_work;
  v54->m_Items[npcsdw_work_num]->dot = 0.0;
  v56 = npcsdw_work;
  v56->m_Items[npcsdw_work_num]->bSkip = 0;
  if (*aBasic)
  {
    name = (*aBasic)->name;
    if (name)
    {
      if (Equals_5234480(name, StringLiteral_16886))
      {
        v60 = npcsdw_work;
        v60->m_Items[npcsdw_work_num]->bSkip = 1;
      }
    }
  }
  ++npcsdw_work_num;
  npcsdw_nowalp = 1.0;
}

// 0x1490b20
void fldNpcShadow_Calc(void) {
    dds3GetActiveScene();
    dds3GetActiveCameraSceneBasic(0);
    dds3CameraObjectBasicGetTgtCam(0, 0, 0);
    dds3CameraObjectBasicGetFovy(0);
    dds3GetUnitHandleObjectBasic(0);
    sdfSqrt(0);
    sdfFabs(0);
    sdfAtan2(0, 0);
    OOYDEG(0);
    sdfModelGetMarkPosUnity(0, 0);
    SDF_VU0__STOREVECTOR(0);
    dds3ObjectBaseCheckFlag(0, 0);
    ChkUseSceneLight(0);
    OOYRAD(0);
    sdfSin(0);
    sdfCos(0);
    evtBitCheck(0);
    dds3GetScriptProcName();
    fldEventUpdateEx_Unity(0, 0, 0, 0);
}

// 0x1484a70
void fldNpcShadow_Clear(void) {
  fld_Npc_c *v2;
  u64 v3;
  s32 v4;
  struct fld_Npc_fldNpcSdwWork_tag_array *npcsdw_work;
  u32 *v9;
  u64 *v10;
  struct fld_Npc_fldNpcSdwWork_tag_array *v12;
  struct fld_Npc_fldNpcSdwWork_tag_array *v14;
  struct fld_Npc_fldNpcSdwWork_tag_array *v16;
  struct fld_Npc_fldNpcSdwWork_tag_array *v18;
  struct fld_Npc_fldNpcSdwWork_tag_array *v20;
  struct fld_Npc_fldNpcSdwWork_tag_array *v22;
  struct fld_Npc_fldNpcSdwWork_tag_array *v24;
  struct fld_Npc_fldNpcSdwWork_tag_array *v26;
  struct fld_Npc_fldNpcSdwWork_tag_array *v28;
  struct fld_Npc_fldNpcSdwWork_tag_array *v30;
  struct fld_Npc_fldNpcSdwWork_tag_array *v32;
  struct fld_Npc_fldNpcSdwWork_tag_array *v34;
  struct fld_Npc_fldNpcSdwWork_tag_array *v36;
  struct fld_Npc_fldNpcSdwWork_tag_array *v38;
  Il2CppClass **v40;
  u32 v41;

  v3 = 0;
  do
  {
    v9 = npcsdw_work;
    v10 = Allocate(fld_Npc_fldNpcSdwWork_tag);
    _ctor(v10, 0);
    *&v9[2 * v3 + 8] = v10;
    v12 = npcsdw_work;
    v12->m_Items[v3]->hEveUnit = 0;
    v14 = npcsdw_work;
    v14->m_Items[v3]->unitBasic = 0;
    v16 = npcsdw_work;
    v16->m_Items[v3]->id1 = 0;
    v18 = npcsdw_work;
    v18->m_Items[v3]->id2 = 0;
    v20 = npcsdw_work;
    v20->m_Items[v3]->x = 0.0;
    v22 = npcsdw_work;
    v22->m_Items[v3]->y = 0.0;
    v24 = npcsdw_work;
    v24->m_Items[v3]->z = 0.0;
    v26 = npcsdw_work;
    v26->m_Items[v3]->dir = 0.0;
    v28 = npcsdw_work;
    v28->m_Items[v3]->size = 0.0;
    v30 = npcsdw_work;
    v30->m_Items[v3]->lookIn = 0;
    v32 = npcsdw_work;
    v32->m_Items[v3]->RangeIn = 0;
    v34 = npcsdw_work;
    v34->m_Items[v3]->len = 99999.0;
    v36 = npcsdw_work;
    v36->m_Items[v3]->dot = 0.0;
    v38 = npcsdw_work;
    v40 = &v38->obj.klass + v3++;
    LOBYTE(v40[4]->_1.castClass) = 0;
    v41 = *&v2->_2.bitflags1;
    v4 = (v41 >> 9) & 1;
  }
  while (v3 != 16);
  npcsdw_work_num = 0;
  npcsdw_nowidx = 0;
  npcsdw_nowalp = 1.0;
}

// 0x14963b0
void fldNpcShadow_Del(dds3Basic_t **aBasic) {
}

// 0x14963a0
void fldNplLoadFromMem(void *data) {
  ;
}

// 0x148cba0
void fldSibukiStart(f32 x, f32 y, f32 z) {
    dds3EffectReset(0);
    dds3EffectSetPosition(0, (sdfVector4_t){0});
    dds3EffectSetLoop(0, 0);
}

// 0x1482cf0
void fldTDmgStart(f32 x, f32 y, f32 z) {
    dds3EffectReset(0);
    dds3EffectSetPosition(0, (sdfVector4_t){0});
}

// 0x1484f20
void fldTakaraWorkClear(void) {
  u64 i;
  struct fldTakaraWork_tag_array *gfldTakaraWork;
  u32 *v9;
  u64 *v10;
  struct fldTakaraWork_tag_array *v12;
  struct fldTakaraWork_tag_array *v14;
  struct fldTakaraWork_tag_array *v16;
  struct fldTakaraWork_tag_array *v18;
  struct fldTakaraWork_tag_array *v20;
  struct fldTakaraWork_tag_array *v23;
  struct fldTakaraWork_tag_array *v26;
  Il2CppClass **v28;
  s64 v29;
  s32 v30;
  u64 v31;
  struct effPartHandle_t_array *gfldTakaraGtEff;
  struct effPartHandle_t_array *v35;
  struct effPartHandle_t_array *v37;
  u32 v39;
  Il2CppObject *pData;

  pData = 0;
  gfldTakaraNum = 0;
  for (i = 0; i != 32; ++i)
  {
    v9 = gfldTakaraWork;
    v10 = Allocate(fldTakaraWork_tag);
    _ctor(v10, 0);
    *&v9[2 * i + 8] = v10;
    v12 = gfldTakaraWork;
    v12->m_Items[i]->TakaraIdx = -1;
    v14 = gfldTakaraWork;
    v14->m_Items[i]->Basic = 0;
    v16 = gfldTakaraWork;
    v16->m_Items[i]->MotPhase = 0;
    v18 = gfldTakaraWork;
    v18->m_Items[i]->MotPhaseNext = 0;
    v20 = gfldTakaraWork;
    if (v20->m_Items[i]->d3p)
    {
      v23 = gfldTakaraWork;
      pData = v23->m_Items[i]->d3p;
      dds3EffectDelete(&pData);
    }
    v26 = gfldTakaraWork;
    v28 = &v26->obj.klass + i;
    *&v28[4]->_1.this_arg.bits = 0;
  }
  v29 = -32;
  do
  {
    v31 = v29 + 32;
    if (*(&gfldTakaraGtEff->obj.klass + i))
    {
      v35 = gfldTakaraGtEff;
      else      dds3EffectPartDelete((v35 + i), 0);
      v37 = gfldTakaraGtEff;
      *(&v37->obj.klass + i) = 0;
    }
    v30 = (v39 >> 9) & 1;
    ++v29;
    i += 8LL;
  }
  while (v29);
  eFldTakara1Pika = 0;
}

// 0x148dbb0
void fldVLDraw(void) {
    rsetOtOfs(0);
    rsetAlpha(0);
    rsetTest(0, 0, 0, 0, 0, 0, 0, 0);
    sdfSin(0);
    SetRadarUI(0, 0, 0, 0, 0);
}

// 0x148b4f0
void takara_animset(s32 index, s32 mode) {
  struct fldTakaraWork_tag_array *gfldTakaraWork;
  s64 v8;
  s32 fldTakaraTblIdx;
  u64 v11;
  struct fldNpc_tag_array *fldNpc;
  struct fldNpc_tag_array *v15;
  UnityEngine_Object_o *v17;
  struct fldNpc_tag_array *v19;
  struct fldNpc_tag_array *v22;
  u32 v24;
  struct fldNpc_tag_array *v26;
  UnityEngine_GameObject_o *fldObj;

  v8 = 4;
  fldTakaraTblIdx = gfldTakaraWork->m_Items[index]->fldTakaraTblIdx;
  do
  {
    v11 = v8 - 4;
    if (*(&fldNpc->obj.klass + v8))
    {
      v15 = fldNpc;
      v17 = *(*(&v15->obj.klass + v8) + 136LL);
      if (!op_Equality(v17, 0, 0))
      {
        v19 = fldNpc;
        if (*(*(&v19->obj.klass + v8) + 16LL) == 999)
        {
          v22 = fldNpc;
          if (*(*(&v22->obj.klass + v8) + 104LL) == fldTakaraTblIdx)
            break;
        }
      }
    }
    ++v8;
  }
  while (v11 <= 0x1E);
  v24 = v8 - 4;
  if (v8 != 36)
  {
    v26 = fldNpc;
    fldObj = v26->m_Items[v24]->fldObj;
    if (!op_Equality(fldObj, 0, 0))
    {
      mdlSingleMotionForUnity(fldObj, StringLiteral_4572, mode, 0, 0);
    }
  }
}
