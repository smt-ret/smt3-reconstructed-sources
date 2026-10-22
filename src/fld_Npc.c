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
  dds3ObjectBaseControlWorkData_t_o *BaseControlWorkData;
  Il2CppObject *pModel;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v12;
  s64 *v13;
  dds3ModelResrc_t_o *v14;
  u64 *monitor;
  u64 *v16;
  u64 *v17;
  System_String_o *v18;
  System_Byte_array *v20;
  dds3ModelHandle_t_o *v21;
  struct dds3Basic_t_o *Owner;
  struct dds3PoseSet_t_o *poseset;
  f32 v25;
  f32 v26;
  AssetBundleCtrl_o *asset_bc;
  System_Byte_array *FileByte;
  AssetBundleCtrl_o *v30;
  System_Byte_array *v31;
  mdlEffectResrcList_t_o *effectResrcList;
  System_Byte_array *aTopPtr;
  dds3ModelHandle_t_o *aHandle;
  s64 v36;
  s64 v37;
  char *v38;

  effectResrcList = 0;
  aTopPtr = 0;
  aHandle = 0;
  BaseControlWorkData = dds3GetBaseControlWorkData(bas);
  pModel = BaseControlWorkData->pModel;
  if (pModel)
  {
    klass = pModel->klass;
    if (pModel->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, &v36);
      if ((v36 & 1) != 0)
        v12 = v38;
      else
        v12 = &v36 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  aHandle = BaseControlWorkData->pModel;
  v14 = Allocate(dds3ModelResrc_t);
  dds3ModelResrc_t___ctor(v14);
  pModel[2].monitor = v14;
  v14->major = 1;
  *(pModel[2].monitor + 17) = id;
  monitor = pModel[2].monitor;
  pModel[3].monitor = 0;
  monitor[12] = 0;
  v16 = pModel[2].monitor;
  v17 = Allocate(mdlEffectResrcList_t);
  mdlEffectResrcList_t___ctor(v17);
  v16[13] = v17;
  v18 = Concat_5221536("dds3data/fld/f/bin/", pbname, ".PB.bytes");
  aTopPtr = 0;
  sdfDevLoadFileUnity_25061072(v18, &aTopPtr, 0, "f_bin");
  v20 = aTopPtr;
  v21 = pModel;
  {
    v21 = pModel;
  }
  pModel[4].klass = sdfModelMakeUnity(0, v20, 0);
  v21->modelRoot->modelobj = (*bas)->gameObject;
  v21->resrc->effectData = &aTopPtr->obj;
  effectResrcList = v21->resrc->effectResrcList;
  if (id == 43)
  {
    Owner = v21->Owner;
    if (Owner)
    {
      poseset = Owner->poseset;
      v36 = 0;
      v37 = 0;
      sub_854690(&v36, 1.2, 1.1, 1.1, 1.0);
      v26 = *&v37;
      v25 = *(&v37 + 1);
      *&poseset->scl.x = v36;
      poseset->scl.z = v26;
      poseset->scl.w = v25;
    }
  }
  asset_bc = get_asset_bc();
  FileByte = LoadFileByte(asset_bc, "f_bin", "dds3data/fld/f/bin/npc_eff0.D3P.bytes");
  mdlCreateEffectResrc_D3P(&effectResrcList, &FileByte->obj, 0);
  v30 = get_asset_bc();
  v31 = LoadFileByte(v30, "f_bin", "dds3data/fld/f/bin/npc_eff1.D3P.bytes");
  mdlCreateEffectResrc_D3P(&effectResrcList, &v31->obj, 0);
  aHandle->resrc->effectResrcList = effectResrcList;
  if (!mdlGenEffect(&aHandle, -1, -1))
  {
    mdlGenEffect(&aHandle, 0, 0);
  }
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
  struct fldGlobalWork_t_o *fldGb;
  struct fldGlobalWork_t_o *v7;
  struct fldGlobalWork_t_o *v8;
  struct fldGlobalWork_t_o *v9;
  struct fldGlobalWork_t_o *v10;
  Il2CppObject *eFldDmgEff;
  UnityEngine_Vector4_o v14;
  Il2CppObject *pData;

  *&v14.x = 0;
  *&v14.z = 0;
  pData = 0;
  sub_854690(&v14.x, 0.0, 0.0, 0.0, 1.0);
  if (fldGb->fieldID != 42)
    goto LABEL_52;
  if (fldGb->areaID != 13)
  {
LABEL_52:
    v7 = fldGb;
    if (v7->fieldID != 42)
      goto LABEL_53;
    if (v7->areaID != 25)
    {
LABEL_53:
      v8 = fldGb;
      if (v8->fieldID != 44)
        goto LABEL_54;
      if (v8->areaID != 2)
      {
LABEL_54:
        v9 = fldGb;
        if (v9->fieldID != 44)
          goto LABEL_55;
        if (v9->areaID != 4)
        {
LABEL_55:
          v10 = fldGb;
          if (v10->fieldID != 44)
            goto LABEL_43;
          if (v10->areaID != 24)
          {
LABEL_43:
            sub_854930(&v14, 0);
            sub_854930(&v14, 1u);
            sub_854930(&v14, 2u);
            pData = eFldDmgEff;
            dds3EffectReset(eFldDmgEff);
            dds3EffectSetPosition(&pData, v14);
            gFldDmgEff = 1;
          }
        }
      }
    }
  }
}

// 0x148d000
void fldEADraw(void) {
  fld_Npc_c *v4;
  dds3DefaultMain_o *kernelObject;
  f32 v7;
  bool v8;
  s32 v9;
  s32 v10;
  s32 v11;
  bool v12;
  bool v13;
  f32 v14;
  f32 gFldEACnt;
  f32 v20;
  f32 v21;
  fldGlobal_c *v23;
  s16 v24;
  s32 fieldID;
  s32 PlayerStatus;
  char v28;
  s32 v29;
  s32 v30;
  f32 fldEADraw_aanm;
  s32 v33;
  struct fldGlobalWork_t_o *fldGb;
  f32 v36;
  s32 EncountCnt;
  s32 EncountMax;
  s32 v41;
  s32 v42;
  char *v43;
  f32 v45;
  f32 v46;
  fld_Npc_c *v47;
  struct fld_Npc_StaticFields **p_static_fields;
  s32 v50;
  s32 encpid;

  encpid = 0;
  if (fldGb->fieldID < 200)
  {
    else if (gFldElvFloorNow == -999)
    {
LABEL_10:
      switch (fldGb->AllPanelMode)
      {
        case 0:
        case 4:
          gFldEACnt = 0.0;
          if ((v4->_2.bitflags2 & 2) != 0)
            goto LABEL_18;
          goto LABEL_57;
        case 1:
        case 5:
            goto LABEL_28;
          goto LABEL_27;
        case 2:
        case 6:
          if (gFldEACnt <= 0.0)
            goto LABEL_56;
          gFldEACnt = gFldEACnt + -0.2;
          if (gFldEACnt >= 0.0)
            goto LABEL_56;
          gFldEACnt = 0.0;
          if ((v4->_2.bitflags2 & 2) == 0)
            goto LABEL_57;
          goto LABEL_18;
        case 3:
        case 7:
          v20 = gFldEACnt;
          if (v20 >= 1.0)
            goto LABEL_56;
          gFldEACnt = v20 + 0.2;
          if (gFldEACnt <= 1.0)
            goto LABEL_56;
          gFldEACnt = 1.0;
          if ((v4->_2.bitflags2 & 2) == 0)
            goto LABEL_57;
          goto LABEL_18;
        default:
LABEL_56:
          if ((v4->_2.bitflags2 & 2) == 0)
            goto LABEL_57;
LABEL_18:
LABEL_57:
          v21 = gFldEACnt;
          rsetOtOfs(71);
          rsetAlpha(0);
          rsetTest(1, 0, 128, 3, 0, 0, 1, 1);
          if ((v24 & 0x200) == 0)
          {
            fieldID = fldGb->fieldID;
            goto LABEL_86;
          }
          v29 = v24 & 0x200;
          fieldID = fldGb->fieldID;
          if (!v29)
          {
LABEL_86:
            if (fieldID == 1)
              goto LABEL_87;
            goto LABEL_64;
          }
          else
          {
            if (fldGb->fieldID == 1)
              goto LABEL_87;
          }
LABEL_64:
          PlayerStatus = fldDbg->PlayerStatus;
          if ((PlayerStatus & 1) != 0)
            goto LABEL_80;
          if ((PlayerStatus & 4) != 0)
            goto LABEL_80;
          if ((PlayerStatus & 8) != 0)
            goto LABEL_80;
          if ((PlayerStatus & 0x10) != 0)
          {
LABEL_80:
            v28 = 1;
            if ((v23->_2.bitflags2 & 2) == 0)
              goto LABEL_88;
            goto LABEL_81;
          }
LABEL_87:
          v28 = 0;
          if ((v23->_2.bitflags2 & 2) == 0)
            goto LABEL_88;
LABEL_81:
LABEL_88:
          v30 = fldGb->fieldID;
          if (v30 != 11)
          {
            if (v30 != 14)
            {
              v33 = 0;
              if ((v23->_2.bitflags2 & 2) == 0)
                goto LABEL_103;
              goto LABEL_100;
            }
          }
          sdfSin(fldEADraw_aanm);
          v33 = 1;
          fldEADraw_aanm = fldEADraw_aanm + 0.1;
          {
LABEL_100:
          }
LABEL_103:
          encpid = fldGb->EncPIDUpper;
          if (!encpid)
          {
            encpid = fldGb->EncPID;
          }
          fldDLCEncountCheck(&encpid);
          v36 = 0.0;
          if (!fldChkVortex())
            goto LABEL_175;
          EncountCnt = nbGetEncountCnt();
          EncountMax = nbGetEncountMax(encpid);
          if (EncountMax < 1)
          {
            v43 = &xmmword_0 + 4;
          }
          else
          {
            if (EncountCnt <= EncountMax)
              v41 = EncountCnt;
            else
              v41 = EncountMax;
            v42 = 100 * v41 / EncountMax;
            if (v42 >= 67)
              LODWORD(v43) = 2;
            else
              LODWORD(v43) = v42 > 33;
          }
          v45 = fldEADraw_aanm;
          v46 = sdfSin(v45);
          v50 = vcvts_n_s32_f32(v46, 6u) + 64;
          if (fldEADraw_oldpat)
          {
            if (fldEADraw_oldalp < v50)
            {
              fldEADraw_texptn ^= 1u;
              (*p_static_fields)->fldEADraw_oldpat = 0;
              if ((v47->_2.bitflags2 & 2) == 0)
                goto LABEL_155;
LABEL_143:
LABEL_155:
              fldEADraw_oldalp = v50;
              goto LABEL_156;
            }
          }
          else
          {
            if (fldEADraw_oldalp > v50)
            {
              fldEADraw_oldpat = 1;
            }
          }
          if ((v47->_2.bitflags2 & 2) == 0)
            goto LABEL_155;
          goto LABEL_143;
      }
    }
  }
  v7 = 0.0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0.0;
LABEL_199:
  SetEnemyUI(kernelObject, v8, v9, v10, v11, v12, v13, v7, v14);
}

// 0x148cd80
void fldEsDrawR(s32 cx, s32 cy, s32 ox, s32 oy, s32 w, s32 h, s32 u, s32 v, s32 uw, s32 vh, f32 r) {
  ;
}

// 0x1489850
void fldItemBoxAdd(s32 idx, f32 x, f32 y, f32 z, sdfVector4_t rot) {
  u64 *v10;
  s32 v14;
  struct fldNpc_tag_array *fldNpc;
  struct fldNpc_tag_array *v17;
  struct fldNpc_tag_array *v19;
  struct fldNpc_tag_array *v21;
  struct fldNpc_tag_array *v23;
  struct fldNpc_tag_array *v25;
  s64 p_rot;
  struct fldNpc_tag_array *v28;
  s64 v30;
  struct fldNpc_tag_array *v31;
  s64 v33;
  struct fldNpc_tag_array *v34;
  s64 v36;
  struct fldNpc_tag_array *v38;
  u32 v39;
  s64 v40;
  Il2CppClass **v42;
  s64 v43;
  struct fldNpc_tag_array *v44;
  struct fldNpc_tag_array *v46;
  struct fldNpc_tag_array *v48;
  struct fldNpc_tag_array *v50;
  struct fldNpc_tag_array *v52;
  struct fldNpc_tag_array *v54;
  struct fldNpc_tag_array *v56;
  s32 v62;
  struct fldTakaraWork_tag_array *gfldTakaraWork;
  s64 gfldTakaraNum;
  fldTakaraWork_tag_o *v67;
  fld_Npc_c *v69;
  s32 v70;
  UnityEngine_Object_o *mhfldTakara02FileC;
  struct fldNpc_tag_array *v76;
  s64 v78;
  Il2CppObject *v79;
  s64 v80;
  UnityEngine_GameObject_o *v81;
  UnityEngine_Transform_o *v83;
  struct fldNpc_tag_array *v84;
  System_String_o *v86;
  System_String_o *v87;
  struct fldNpc_tag_array *v89;
  System_String_o *v90;
  UnityEngine_GameObject_o *v92;
  struct fldNpc_tag_array *v94;
  UnityEngine_GameObject_o *v96;
  FieldChrHD_o *v97;
  struct fldNpc_tag_array *v98;
  UnityEngine_Object_o *mhfldTakara03FileC;
  struct fldNpc_tag_array *v104;
  s64 v106;
  Il2CppObject *v107;
  s64 v108;
  UnityEngine_GameObject_o *v109;
  UnityEngine_Transform_o *v111;
  struct fldNpc_tag_array *v112;
  System_String_o *v114;
  System_String_o *v115;
  struct fldNpc_tag_array *v117;
  System_String_o *v118;
  UnityEngine_GameObject_o *v120;
  struct fldNpc_tag_array *v122;
  UnityEngine_GameObject_o *v124;
  FieldChrHD_o *v125;
  struct fldNpc_tag_array *v126;
  struct fldTakaraWork_tag_array *v128;
  s64 v129;
  fldTakaraWork_tag_o *v131;
  struct fldTakaraWork_tag_array *v133;
  s64 v134;
  UnityEngine_Object_o *mhfldTakara01FileC;
  struct fldNpc_tag_array *v139;
  s64 v141;
  Il2CppObject *v142;
  s64 v143;
  UnityEngine_GameObject_o *v144;
  UnityEngine_Transform_o *transform;
  struct fldNpc_tag_array *v147;
  System_String_o *v149;
  System_String_o *v150;
  struct fldNpc_tag_array *v152;
  System_String_o *v153;
  UnityEngine_GameObject_o *fldObj;
  struct fldNpc_tag_array *v157;
  UnityEngine_GameObject_o *v159;
  FieldChrHD_o *v160;
  struct fldNpc_tag_array *v161;
  u32 v164;
  s64 v166;
  s64 v167;
  u32 v168;
  f32 v169;
  f32 v170;
  f32 v171;
  f32 w;
  s32 v175;
  struct fldNpc_tag_array *v177;
  UnityEngine_GameObject_o *v179;
  struct fldTakaraWork_tag_array *v182;
  s64 v183;
  s64 v185;
  s32 v186;
  struct fldNpc_tag_array *v187;
  UnityEngine_GameObject_o *v189;
  struct fldTakaraWork_tag_array *v191;
  s64 v192;
  struct fldTakaraWork_tag_array *v196;
  s64 v197;
  struct fldTakaraWork_tag_array *v200;
  s64 v201;
  struct fldTakaraWork_tag_array *v204;
  s64 v205;
  struct fldTakaraWork_tag_array *v208;
  s64 v209;
  struct fldTakaraWork_tag_array *v212;
  s64 v213;
  struct fldTakaraWork_tag_array *v216;
  s64 v217;
  fldTakaraWork_tag_o *v219;
  f32 v221;
  struct fldTakaraWork_tag_array *v224;
  s64 v225;
  fldTakaraWork_tag_o *v228;
  struct fldTakaraWork_tag_array *v232;
  s64 v233;
  struct fldNpcLightTbl_tag_array *fldNpcLightTbl;
  s64 v236;
  u8 *v238;
  u64 *v239;
  f32 v240;
  f32 v242;
  dds3Basic_t_o *v243;
  f32 v244;
  struct fldNpc_tag_array *v246;
  u32 v247;
  s64 v248;
  Il2CppClass **v250;
  s64 v251;
  struct fldNpc_tag_array *v252;
  struct fldNpc_tag_array *v254;
  Il2CppObject *Component_object;
  s32 v259;
  u32 v260;
  u32 v261;
  f32 v262;
  f32 v265;
  f32 v266;
  f32 v267;
  f32 v268;
  f32 v269;
  f32 v270;
  f32 v272;
  f32 v273;
  struct fldNpc_tag_array *v276;
  UnityEngine_Object_o *v278;
  struct fldNpc_tag_array *v281;
  f32 v283;
  f32 v284;
  f32 v285;
  UnityEngine_Transform_o *v286;
  struct fldNpc_tag_array *v287;
  UnityEngine_Transform_o *v289;
  f32 v290;
  UnityEngine_Vector4_o v291;
  evtUnitHandle_t_o *h;
  Il2CppObject *pD3P;
  Il2CppObject *pFldTakara1Pika;
  UnityEngine_Vector4_o v295;
  UnityEngine_Vector4_o v296;
  UnityEngine_Vector4_o p;
  s64 v298;
  s64 v299;
  dds3Basic_t_o *basic;
  u32 fldNpcNum;
  UnityEngine_Vector4_o v302;
  UnityEngine_Vector3_o v303;
  UnityEngine_Vector4_o v304;
  UnityEngine_Vector4_o v305;

  v302 = rot;
  v299 = 0;
  basic = 0;
  *&p.z = 0;
  v298 = 0;
  fldNpcNum = 0;
  *&v296.z = 0;
  *&p.x = 0;
  *&v296.x = 0;
  pFldTakara1Pika = 0;
  h = 0;
  pD3P = 0;
  sub_854690(&v298, 0.0, 0.0, 0.0, 1.0);
  sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v296.x, 1.0, 1.0, 1.0, 1.0);
  v10 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v10);
  *&v295.x = 0;
  *&v295.z = 0;
  v14 = fldNpcNum;
  fldNpcNum = fldNpcNum + 1;
  fldNpc->m_Items[v14]->tType = 1;
  v17 = fldNpc;
  v17->m_Items[v14]->Type = 999;
  v19 = fldNpc;
  v19->m_Items[v14]->x = x;
  v21 = fldNpc;
  v21->m_Items[v14]->y = y;
  v23 = fldNpc;
  v23->m_Items[v14]->z = z;
  v25 = fldNpc;
  p_rot = &v25->m_Items[v14]->rot;
  sub_854710(&v302, 0);
  sub_854930(p_rot, 0);
  v28 = fldNpc;
  v30 = &v28->m_Items[fldNpcNum]->rot;
  sub_854710(&v302, 1u);
  sub_854930(v30, 1u);
  v31 = fldNpc;
  v33 = &v31->m_Items[fldNpcNum]->rot;
  sub_854710(&v302, 2u);
  sub_854930(v33, 2u);
  v34 = fldNpc;
  v36 = &v34->m_Items[fldNpcNum]->rot;
  sub_854710(&v302, 3u);
  sub_854930(v36, 3u);
  v38 = fldNpc;
  v39 = fldNpcNum;
  v40 = fldNpcNum;
  v42 = &v38->obj.klass + fldNpcNum;
  v43 = fldNpcNum;
  LODWORD(v42[4]->_1.declaringType) = 0;
  v44 = fldNpc;
  v44->m_Items[v40]->cnti = 0;
  v46 = fldNpc;
  v46->m_Items[v43]->cntAnmf = 0.0;
  v48 = fldNpc;
  v48->m_Items[v40]->cntAnmi = 0;
  v50 = fldNpc;
  v50->m_Items[v43]->npcmodel = 0;
  v52 = fldNpc;
  v52->m_Items[v40]->hojiID = 0;
  v54 = fldNpc;
  v54->m_Items[v43]->ItemBoxIdx = idx;
  v56 = fldNpc;
  v56->m_Items[v40]->d3p = 0;
  sub_854930(&v298, 0);
  sub_854930(&v298, 1u);
  sub_854930(&v298, 2u);
  switch (*&_get_Item(
               fldHitData->_fldItemBoxTbl,
               idx)->isLongReference)
  {
    case 0:
    case 3:
      {
        else
        {
          if (eFldTakara1Pika)
            goto LABEL_47;
        }
      }
      else
      {
        v62 = 0;
        if (eFldTakara1Pika)
        {
LABEL_47:
          pD3P = pFldTakara1Pika;
          v67 = gfldTakaraWork->m_Items[gfldTakaraNum];
          v67->d3p = dds3EffectLoad(&pD3P, 0, 0, 0);
          {
LABEL_56:
          }
LABEL_137:
          if (op_Inequality(mhfldTakara01FileC, 0, 0))
          {
            v139 = fldNpc;
            v141 = v139 + 8 * fldNpcNum;
            v142 = mhfldTakara01FileC;
            v143 = *(v141 + 32);
            v144 = Find("Character", 0);
            transform = get_transform(v144, 0);
            *(v143 + 136) = Instantiate_object__425664(v142, transform, 0);
            v147 = fldNpc;
            set_layer(v147->m_Items[fldNpcNum]->fldObj, 15);
            v149 = sub_232A70(&fldNpcNum, "D2");
            v150 = Concat_5224608("NPC_ITEM", v149);
            v152 = fldNpc;
            v153 = v150;
            fldObj = v152->m_Items[fldNpcNum]->fldObj;
            fldSetCharAdd(v153, fldObj);
            v157 = fldNpc;
            v159 = v157->m_Items[fldNpcNum]->fldObj;
            v160 = mdlSetHD(v159, 5, 0, 15);
            v161 = fldNpc;
            SetLayerAll2(v160, v161->m_Items[fldNpcNum]->fldObj, 14);
          }
          v70 = 28;
            goto LABEL_59;
          goto LABEL_165;
        }
      }
      v128 = gfldTakaraWork;
      v129 = gfldTakaraNum;
      v131 = v128->m_Items[v129];
      v131->d3p = dds3EffectLoad(&pFldTakara1Pika, 0, 0, 0);
      v133 = gfldTakaraWork;
      v134 = gfldTakaraNum;
      eFldTakara1Pika = v133->m_Items[v134]->d3p;
      if ((v69->_2.bitflags2 & 2) != 0)
        goto LABEL_56;
      goto LABEL_137;
    case 1:
      if (op_Inequality(mhfldTakara02FileC, 0, 0))
      {
        v76 = fldNpc;
        v78 = v76 + 8 * fldNpcNum;
        v79 = mhfldTakara02FileC;
        v80 = *(v78 + 32);
        v81 = Find("Character", 0);
        v83 = get_transform(v81, 0);
        *(v80 + 136) = Instantiate_object__425664(v79, v83, 0);
        v84 = fldNpc;
        set_layer(v84->m_Items[fldNpcNum]->fldObj, 15);
        v86 = sub_232A70(&fldNpcNum, "D2");
        v87 = Concat_5224608("NPC_ITEM", v86);
        v89 = fldNpc;
        v90 = v87;
        v92 = v89->m_Items[fldNpcNum]->fldObj;
        fldSetCharAdd(v90, v92);
        v94 = fldNpc;
        v96 = v94->m_Items[fldNpcNum]->fldObj;
        v97 = mdlSetHD(v96, 5, 0, 15);
        v98 = fldNpc;
        SetLayerAll2(v97, v98->m_Items[fldNpcNum]->fldObj, 14);
        v70 = 29;
          goto LABEL_59;
      }
      else
      {
        v70 = 29;
          goto LABEL_59;
      }
      goto LABEL_165;
    case 2:
      if (op_Inequality(mhfldTakara03FileC, 0, 0))
      {
        v104 = fldNpc;
        v106 = v104 + 8 * fldNpcNum;
        v107 = mhfldTakara03FileC;
        v108 = *(v106 + 32);
        v109 = Find("Character", 0);
        v111 = get_transform(v109, 0);
        *(v108 + 136) = Instantiate_object__425664(v107, v111, 0);
        v112 = fldNpc;
        set_layer(v112->m_Items[fldNpcNum]->fldObj, 15);
        v114 = sub_232A70(&fldNpcNum, "D2");
        v115 = Concat_5224608("NPC_ITEM", v114);
        v117 = fldNpc;
        v118 = v115;
        v120 = v117->m_Items[fldNpcNum]->fldObj;
        fldSetCharAdd(v118, v120);
        v122 = fldNpc;
        v124 = v122->m_Items[fldNpcNum]->fldObj;
        v125 = mdlSetHD(v124, 5, 0, 15);
        v126 = fldNpc;
        SetLayerAll2(v125, v126->m_Items[fldNpcNum]->fldObj, 14);
      }
      v70 = 30;
        goto LABEL_59;
      goto LABEL_165;
    default:
      v70 = 3;
      {
LABEL_59:
      }
LABEL_165:
      v290 = z;
      *&v291.x = 0;
      *&v291.z = 0;
      sub_854690(&v291.x, 0.0, 1.0, 0.0, 1.0);
      SDF_VU0__LOADVECTOR(v291);
      FromRotation(3.1416);
      SDF_VU0__LOADVECTOR_B(v302);
      Mult();
      SDF_VU0__STOREVECTOR(&p);
      v164 = dds3SerializeID();
      v166 = v298;
      v167 = v299;
      v168 = v164;
      v169 = p.x;
      v170 = p.y;
      v171 = p.z;
      w = p.w;
      *&v304.x = v166;
      *&v304.z = v167;
      v305.x = v169;
      v305.y = v170;
      v305.z = v171;
      v305.w = w;
      basic = dds3AddUnitObjectBasic(v168, v304, v305);
      dds3SetBasicName(&basic, "TAKARA_UNIT");
      dds3ObjectBaseMakeUnit(&basic, 2, v70);
      dds3SetSclPoseSet(&basic, v296);
      dds3ObjectBaseOnFlag(&basic, 0x100u, 0);
      dds3ObjectBaseGetModelHandle(&basic);
      v175 = fldGbChkTakaraOpen(idx);
      if (v175)
      {
        v177 = fldNpc;
        v179 = v177->m_Items[fldNpcNum]->fldObj;
        mdlLoopMotionForUnity(v179, "anim", 2);
        v182 = gfldTakaraWork;
        v183 = gfldTakaraNum;
        v185 = &v182->m_Items[v183];
        v186 = 3;
      }
      else
      {
        v187 = fldNpc;
        v189 = v187->m_Items[fldNpcNum]->fldObj;
        mdlSingleMotionForUnity(v189, "anim", 0, 0, 0);
        v191 = gfldTakaraWork;
        v192 = gfldTakaraNum;
        v186 = 0;
        v185 = &v191->m_Items[v192];
      }
      *(*v185 + 28LL) = v186;
      v196 = gfldTakaraWork;
      v197 = gfldTakaraNum;
      v196->m_Items[v197]->TakaraIdx = idx;
      v200 = gfldTakaraWork;
      v201 = gfldTakaraNum;
      v200->m_Items[v201]->Basic = basic;
      v204 = gfldTakaraWork;
      v205 = gfldTakaraNum;
      v204->m_Items[v205]->x = x;
      v208 = gfldTakaraWork;
      v209 = gfldTakaraNum;
      v208->m_Items[v209]->y = y;
      v212 = gfldTakaraWork;
      v213 = gfldTakaraNum;
      v212->m_Items[v213]->z = v290;
      dds3GetRotPoseSet(&basic);
      v216 = gfldTakaraWork;
      v217 = gfldTakaraNum;
      v219 = v216->m_Items[v217];
      v221 = EulerAngleAxisY();
      v219->r = OOYDEG(v221);
      v224 = gfldTakaraWork;
      v225 = gfldTakaraNum;
      v228 = v224->m_Items[v225];
      v228->type = *&_get_Item(
                              fldHitData->_fldItemBoxTbl,
                              idx)->isLongReference;
      v232 = gfldTakaraWork;
      v233 = gfldTakaraNum;
      v232->m_Items[v233]->fldTakaraTblIdx = idx;
      ++gfldTakaraNum;
      fldHitProgramAdd(x, y, v290, 20.0, 100.0, -1);
      v236 = fldGb->areaID + 1LL;
      v238 = fldNpcLightTbl->m_Items[v236];
      v239 = Allocate(evtUnitHandle_t);
      evtUnitHandle_t___ctor(v239);
      h = v239;
      SDF_VU0__LOADVECTOR(p);
      v240 = EulerAngleAxisY();
      v242 = OOYDEG(v240);
      v243 = basic;
      v244 = v242;
      h = evtGetUnitHandle2(v243);
      evtUnitLightOn(&h);
      v246 = fldNpc;
      v247 = fldNpcNum;
      v248 = fldNpcNum;
      v250 = &v246->obj.klass + fldNpcNum;
      v251 = fldNpcNum;
      h->Owner = v250[4]->_1.this_arg.data;
      v252 = fldNpc;
      basic->gameObject = v252->m_Items[v248]->fldObj;
      v254 = fldNpc;
      Component_object = GetComponent_object_(v254->m_Items[v251]->fldObj);
      if (op_Inequality(Component_object, 0, 0))
        SetEveUnit(Component_object, h);
      v259 = v238[19] | (v238[20] << 8) | (v238[21] << 16);
      v260 = v238[16] | (v238[17] << 8) | (v238[18] << 16) | 0x80000000;
      v261 = v259 | 0x80000000;
      v262 = v244 + 80.0;
      evtSetUnitLightAndAmbient(&h, 0, v260, v261);
      v265 = OOYRAD(v262);
      sdfSin(v265);
      sub_854930(&v295, 0);
      sub_854930(&v295, 1u);
      v266 = OOYRAD(v262);
      sdfCos(v266);
      sub_854930(&v295, 2u);
      sub_854930(&v295, 3u);
      SDF_VU0__LOADVECTOR(v295);
      SDF_VU0__NORMALIZE();
      evtSetUnitLightDir(&h, 0);
      sub_854710(&v298, 0);
      v268 = v267;
      sub_854710(&v298, 1u);
      v270 = v269;
      sub_854710(&v298, 2u);
      v273 = v272;
      fldEveHit_AddEveHitItemBox(idx, v268, v270, v273, 160.0);
      v276 = fldNpc;
      v278 = v276->m_Items[fldNpcNum]->fldObj;
      if (op_Inequality(v278, 0, 0))
      {
        v281 = fldNpc;
        v283 = v281->m_Items[fldNpcNum]->x;
        v284 = fldNpc->m_Items[fldNpcNum]->y / -100.0;
        v285 = v281->m_Items[fldNpcNum]->z / 100.0;
        v286 = get_transform(v281->m_Items[fldNpcNum]->fldObj, 0);
        v303.x = v283 / 100.0;
        v303.y = v284;
        v303.z = v285;
        set_localPosition(v286, v303);
        v287 = fldNpc;
        v289 = get_transform(v287->m_Items[fldNpcNum]->fldObj, 0);
        *&v291.x = 0;
        *&v291.z = 0;
        sub_1A1BDD0(&v291.x, v302.x, -v302.y, v302.z, v302.w);
        set_localRotation(v289, v291);
      }
      return;
  }
}

// 0x148b9a0
void fldItemBoxAllFree(void) {
  s64 v2;
  fld_Npc_c *v3;
  u64 v4;
  struct fldTakaraWork_tag_array *gfldTakaraWork;
  u64 max_length_low;
  u32 v7;
  struct fldTakaraWork_tag_array *v10;
  struct fldTakaraWork_tag_array *v12;
  s32 v14;
  s64 v15;
  s64 v16;
  u64 v17;
  struct effPartHandle_t_array *gfldTakaraGtEff;
  struct effPartHandle_t_array *v21;
  struct effPartHandle_t_array *v23;
  u32 v25;
  UnityEngine_Object_o *mhfldTakara01FileC;
  bool v28;
  UnityEngine_Object_o *mhfldTakara02FileC;
  bool v32;
  UnityEngine_Object_o *mhfldTakara03FileC;
  Il2CppObject *pData;

  pData = 0;
  v2 = 4;
  v4 = 0;
  {
LABEL_6:
  }
  while (1)
  {
    max_length_low = LODWORD(gfldTakaraWork->max_length);
    v7 = *&v3->_2.bitflags1;
    if (v4 >= max_length_low)
      break;
    else if (v4 >= max_length_low)
    {
      goto LABEL_12;
    }
    if (*(*(&gfldTakaraWork->obj.klass + v2) + 56LL))
    {
      v10 = gfldTakaraWork;
      pData = *(*(&v10->obj.klass + v2) + 56LL);
      dds3EffectDelete(&pData);
      v12 = gfldTakaraWork;
      *(*(&v12->obj.klass + v2) + 56LL) = 0;
    }
    ++v2;
    v4 = v2 - 4;
      goto LABEL_6;
  }
  v14 = (v7 >> 9) & 1;
  v15 = -32;
  v16 = 32;
  do
  {
    v17 = v15 + 32;
    if (*(&gfldTakaraGtEff->obj.klass + v16))
    {
      v21 = gfldTakaraGtEff;
      else if (v17 >= LODWORD(v21->max_length))
      {
LABEL_42:
      }
      dds3EffectPartDelete((v21 + v16), 0);
      v23 = gfldTakaraGtEff;
      *(&v23->obj.klass + v16) = 0;
    }
    v14 = (v25 >> 9) & 1;
    ++v15;
    v16 += 8;
  }
  while (v15);
  v28 = op_Inequality(mhfldTakara01FileC, 0, 0);
  if (v28)
  {
    mhfldTakara01FileC = 0;
  }
  v32 = op_Inequality(mhfldTakara02FileC, 0, 0);
  if (v32)
  {
    mhfldTakara02FileC = 0;
  }
  if (op_Inequality(mhfldTakara03FileC, 0, 0))
  {
    mhfldTakara03FileC = 0;
  }
}

// 0x148bdc0
void fldItemBoxCalcTask(void) {
  u64 *v1;
  u64 v3;
  s64 v4;
  struct fldTakaraWork_tag_array *gfldTakaraWork;
  u32 type;
  struct fldTakaraWork_tag_array *v13;
  f32 r;
  f32 v16;
  struct fldTakaraWork_tag_array *v18;
  s64 v20;
  dds3Basic_t_o **p_Basic;
  f32 w;
  f32 z;
  struct fldTakaraWork_tag_array *v24;
  struct fldTakaraWork_tag_array *v27;
  struct fldTakaraWork_tag_array *v30;
  struct fldTakaraWork_tag_array *v32;
  struct fldTakaraWork_tag_array *v37;
  struct fldTakaraWork_tag_array *v39;
  UnityEngine_GameObject_o *v41;
  struct fldTakaraWork_tag_array *v43;
  fldTakaraWork_tag_o *v45;
  struct fldTakaraWork_tag_array *v47;
  UnityEngine_GameObject_o *v49;
  struct fldTakaraWork_tag_array *v51;
  fldTakaraWork_tag_o *v53;
  struct effPartHandle_t_array *v55;
  struct effPartHandle_t_array *v58;
  struct effPartHandle_t_array *v60;
  struct fldTakaraWork_tag_array *v63;
  struct fldTakaraWork_tag_array *v65;
  UnityEngine_GameObject_o *gameObject;
  struct effPartHandle_t_array *gfldTakaraGtEff;
  u32 *v75;
  Il2CppObject *gfldTakaraGtPtr;
  s64 *v77;
  s64 *v78;
  effHandle_t_o *eFldTDmgEff;
  UnityEngine_Vector4_o v82;
  UnityEngine_Vector4_o v83;
  UnityEngine_Vector4_o v84;

  *&v83.x = 0;
  *&v83.z = 0;
  v1 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v1);
  sub_854690(&v83.x, 0.0, 1.0, 0.0, 1.0);
  *&v82.x = 0;
  *&v82.z = 0;
  v3 = 0;
  v4 = 32;
  {
LABEL_6:
  }
  while (1)
  {
    if (v3 >= gfldTakaraNum)
      break;
    else
    {
      if (v3 >= LODWORD(gfldTakaraWork->max_length))
        goto LABEL_12;
    }
    type = gfldTakaraWork->m_Items[v3]->type;
    if (type <= 3 && type != 1)
    {
      SDF_VU0__LOADVECTOR(v83);
      v13 = gfldTakaraWork;
      r = v13->m_Items[v3]->r;
      v16 = OOYRAD(r);
      FromRotation(v16);
      SDF_VU0__STOREVECTOR(&v82);
      v18 = gfldTakaraWork;
      v20 = *&v82.x;
      p_Basic = &v18->m_Items[v3]->Basic;
      z = v82.z;
      w = v82.w;
      *&v84.x = v20;
      v84.z = z;
      v84.w = w;
      dds3SetRotPoseSet(p_Basic, v84);
      v24 = gfldTakaraWork;
      v24->m_Items[v3]->r = v24->m_Items[v3]->r + 1.5;
    }
    v27 = gfldTakaraWork;
    switch (v27->m_Items[v3]->MotPhase)
    {
      case 0:
        v30 = gfldTakaraWork;
        if (v30->m_Items[v3]->MotPhaseNext == 1)
        {
          v32 = gfldTakaraWork;
          dds3ObjectBaseGetModelHandle(&v32->m_Items[v3]->Basic);
          takara_animset(v3, 1);
          v37 = gfldTakaraWork;
          v37->m_Items[v3]->MotPhase = gfldTakaraWork->m_Items[v3]->MotPhaseNext;
          if (gfldTakaraGtEff->m_Items[v3])
          {
              goto LABEL_141;
          }
          else
          {
            v75 = gfldTakaraGtEff;
            v77 = dds3EffectPartCreate(6u, gfldTakaraGtPtr, 0, 0);
            v78 = v77;
            *&v75[2 * v3 + 8] = v78;
            {
LABEL_141:
            }
          }
          dds3EffectReset(eFldTDmgEff);
          goto LABEL_5;
        }
        v65 = gfldTakaraWork;
        gameObject = v65->m_Items[v3]->Basic->gameObject;
        if (op_Inequality(gameObject, 0, 0))
        {
          if (mdlChkMotionEndForUnity_26964128(gameObject, 0))
          {
            takara_animset(v3, 0);
          }
        }
LABEL_5:
        ++v3;
        v4 += 8;
          goto LABEL_6;
        break;
      case 1:
        v39 = gfldTakaraWork;
        v41 = v39->m_Items[v3]->Basic->gameObject;
        if (op_Inequality(v41, 0, 0))
        {
          if (mdlChkMotionEndForUnity_26964128(v41, 0))
          {
            mdlLoopMotionForUnity(v41, "anim", 2);
            v43 = gfldTakaraWork;
            v45 = v43->m_Items[v3];
            gfldTakaraWork->m_Items[v3]->MotPhaseNext = 2;
            v45->MotPhase = 2;
          }
        }
        goto LABEL_5;
      case 2:
        if (!fldProcCheckFlag(0x40u))
          goto LABEL_5;
        v47 = gfldTakaraWork;
        v49 = v47->m_Items[v3]->Basic->gameObject;
        if (op_Inequality(v49, 0, 0))
        {
          mdlLoopMotionForUnity(v49, "anim", 3);
          v51 = gfldTakaraWork;
          v53 = v51->m_Items[v3];
          gfldTakaraWork->m_Items[v3]->MotPhaseNext = 3;
          v53->MotPhase = 3;
        }
        v55 = gfldTakaraGtEff;
        if (!v55->m_Items[v3])
          goto LABEL_5;
        v58 = gfldTakaraGtEff;
        else if (v3 >= LODWORD(v58->max_length))
        {
          goto LABEL_108;
        }
        dds3EffectPartDelete((v58 + v4), 0);
        v60 = gfldTakaraGtEff;
        v60->m_Items[v3] = 0;
        goto LABEL_5;
      case 3:
        v63 = gfldTakaraWork;
        dds3ObjectBaseGetModelHandle(&v63->m_Items[v3]->Basic);
        goto LABEL_5;
      default:
        goto LABEL_5;
    }
  }
}

// 0x148b800
void fldItemBoxOpen(s32 idx) {
  s64 v3;
  u64 v5;
  struct fldTakaraWork_tag_array *gfldTakaraWork;
  struct fldTakaraWork_tag_array *v10;
  struct fldTakaraWork_tag_array *v13;

  v3 = 4;
  v5 = 0;
  {
LABEL_6:
  }
  while (1)
  {
    if (v5 >= gfldTakaraNum)
      break;
    else
    {
      if (v5 >= LODWORD(gfldTakaraWork->max_length))
        goto LABEL_12;
    }
    if (*(*(&gfldTakaraWork->obj.klass + v3) + 24LL) == idx)
    {
      v10 = gfldTakaraWork;
      if (!*(*(&v10->obj.klass + v3) + 28LL))
      {
        v13 = gfldTakaraWork;
        *(*(&v13->obj.klass + v3) + 32LL) = 1;
      }
    }
    ++v3;
    v5 = v3 - 4;
      goto LABEL_6;
  }
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
  f32 v14;
  f32 v15;
  u64 *v16;
  u64 *v17;
  s64 *v18;
  s64 *v21;
  s64 *v24;
  s64 *v27;
  s64 *v30;
  s64 *v33;
  s64 *v36;
  s64 *v39;
  s64 *v42;
  s64 *v45;
  u64 *v50;
  s64 *v52;
  u32 *v53;
  s64 *v56;
  s64 *v59;
  s64 *v62;
  s64 *v65;
  s64 *v68;
  s64 *v71;
  s64 *v74;
  s64 *v77;
  s64 *v80;
  s64 *v83;
  s64 *v86;
  s64 *v89;
  s64 *v92;
  s64 *v95;
  s64 *v98;
  s64 *v101;
  s64 *v104;
  s64 *v107;
  s64 *v110;
  s64 *v113;
  s64 *v116;
  s64 *v119;
  s64 *v122;
  s64 *v125;
  u64 *v128;
  u32 *v129;
  u64 *v154;
  s32 fldNpcNum;
  struct fldNpc_tag_array *fldNpc;
  struct fldNpc_tag_array *v161;
  struct fldNpc_tag_array *v163;
  struct fldNpc_tag_array *v165;
  struct fldNpc_tag_array *v167;
  s64 p_rot;
  struct fldNpc_tag_array *v170;
  s64 v172;
  struct fldNpc_tag_array *v173;
  s64 v175;
  struct fldNpc_tag_array *v176;
  s64 v178;
  struct fldNpc_tag_array *v181;
  u32 v182;
  s64 v183;
  Il2CppClass **v185;
  s64 v186;
  struct fldNpc_tag_array *v187;
  struct fldNpc_tag_array *v189;
  struct fldNpc_tag_array *v191;
  struct fldNpc_tag_array *v193;
  Il2CppClass **v195;
  s64 v196;
  struct fldNpc_tag_array *v197;
  Il2CppClass **v199;
  s64 v200;
  struct fldNpc_tag_array *v201;
  Il2CppClass **v203;
  s64 v204;
  struct fldNpc_tag_array *v205;
  struct fldNpc_tag_array *v207;
  struct fldNpc_tag_array *v209;
  s32 v212;
  s32 handle_low;
  s32 v214;
  s32 Count;
  s32 v217;
  s32 v218;
  s32 isLongReference;
  s32 v222;
  System_WeakReference_o *Item;
  struct fldNpc_tag_array *v226;
  u32 v227;
  s64 v228;
  Il2CppClass **v230;
  s64 v231;
  struct fldNpc_tag_array *v232;
  struct fldNpc_tag_array *v234;
  s64 v235;
  struct fldNpc_tag_array *v237;
  s32 v239;
  f32 v240;
  s32 v241;
  struct fldNpc_tag_array *v243;
  s32 fieldID;
  struct UnityEngine_GameObject_array *mhfldNpcFile;
  UnityEngine_Object_o *v250;
  struct UnityEngine_GameObject_array *v253;
  AssetBundleCtrl_o *v254;
  s64 *v256;
  UnityEngine_GameObject_c **v257;
  u32 v260;
  s64 v262;
  s64 v263;
  u32 v264;
  f32 v265;
  f32 v266;
  f32 w;
  f32 v268;
  struct fldNpc_tag_array *v300;
  u32 v301;
  s64 v302;
  Il2CppClass **v304;
  dds3Basic_t_o *v305;
  struct fldNpc_tag_array *v306;
  s32 v308;
  s64 v310;
  s64 v311;
  s32 serialID;
  struct fldNpc_tag_array *v316;
  UnityEngine_GameObject_o *fldObj;
  evtUnitHandle_t_o *UnitHandle2;
  s32 v322;
  System_WeakReference_o *v326;
  s32 v328;
  s32 monitor_low;
  AssetBundleCtrl_o *asset_bc;
  s64 *FileObject;
  struct UnityEngine_GameObject_array *v338;
  UnityEngine_Object_o *v340;
  struct fldNpc_tag_array *v344;
  s64 v346;
  struct UnityEngine_GameObject_array *v347;
  s64 v348;
  Il2CppObject *v350;
  UnityEngine_GameObject_o *v351;
  UnityEngine_Transform_o *transform;
  struct fldNpc_tag_array *v354;
  System_String_o *v356;
  System_String_o *v357;
  struct fldNpc_tag_array *v359;
  System_String_o *v360;
  UnityEngine_GameObject_o *v362;
  struct fldNpc_tag_array *v364;
  s32 v367;
  u32 v369;
  s64 v371;
  s64 v372;
  u32 v373;
  f32 v374;
  f32 v375;
  f32 v376;
  f32 v377;
  f32 v379;
  struct fldNpc_tag_array *v382;
  UnityEngine_GameObject_o *v384;
  FieldChrHD_o *v386;
  dds3Basic_t_o *v387;
  evtUnitHandle_t_o *v388;
  struct fldNpc_tag_array *v389;
  s32 v393;
  System_String_o **v394;
  f32 v395;
  f32 v396;
  f32 v397;
  f32 v398;
  s32 v399;
  struct fldNpc_tag_array *v403;
  UnityEngine_Object_o *v405;
  struct fldNpc_tag_array *v408;
  f32 v410;
  f32 v411;
  f32 v412;
  UnityEngine_Transform_o *v413;
  struct fldNpc_tag_array *v415;
  fldNpc_tag_o *v417;
  u32 v418;
  s64 v420;
  s64 v421;
  u32 v422;
  f32 v423;
  f32 v424;
  f32 v425;
  f32 v426;
  struct fldNpc_tag_array *v429;
  u32 v430;
  s64 v431;
  Il2CppClass **v433;
  dds3Basic_t_o *v434;
  struct fldNpc_tag_array *v435;
  struct fldNpc_tag_array *v438;
  UnityEngine_GameObject_o *v440;
  FieldChrHD_o *v441;
  struct fldNpc_tag_array *v442;
  Il2CppObject *eFldNpcIcon;
  struct fldNpc_tag_array *v447;
  fldNpc_tag_o *v449;
  struct fldNpc_tag_array *v450;
  fldNpc_tag_o *v452;
  struct fldNpc_tag_array *v454;
  f32 v456;
  f32 v457;
  f32 v458;
  f32 v459;
  f32 v460;
  f32 v461;
  s32 handle_high;
  s32 npcID;
  s32 klass_low;
  s32 v466;
  Il2CppObject *pData;
  Il2CppObject *pD3P;
  UnityEngine_Vector4_o v470;
  s64 v471;
  s64 v472;
  UnityEngine_Vector4_o p;
  s64 v474;
  s64 v475;
  dds3Basic_t_o *basic;
  u32 v477;
  UnityEngine_Vector4_o v478;
  UnityEngine_Vector3_o v479;
  UnityEngine_Vector4_o v480;
  UnityEngine_Vector4_o v481;
  UnityEngine_Vector4_o v482;
  UnityEngine_Vector4_o v483;
  UnityEngine_Vector4_o v484;
  UnityEngine_Vector4_o v485;
  UnityEngine_Vector4_o v486;

  v478 = rot;
  v14 = 0.0;
  v15 = 1.0;
  v475 = 0;
  basic = 0;
  *&p.z = 0;
  v474 = 0;
  v477 = 0;
  v472 = 0;
  *&p.x = 0;
  pData = 0;
  *&v470.z = 0;
  v471 = 0;
  pD3P = 0;
  *&v470.x = 0;
  sub_854690(&v474, 0.0, 0.0, 0.0, 1.0);
  sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v471, v15, v15, v15, v15);
  sub_854690(&v470.x, 0.0, v15, 0.0, v15);
  v16 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v16);
  v17 = NewSpecific(string, 0xDu);
  v18 = "charactor/f/shinentai/shinentai.prefab";
  v17[4] = "charactor/f/shinentai/shinentai.prefab";
  v21 = "charactor/f/shinentai/shinentai.prefab";
  v17[5] = "charactor/f/shinentai/shinentai.prefab";
  v24 = "charactor/f/shinentai/shinentai.prefab";
  v17[6] = "charactor/f/shinentai/shinentai.prefab";
  v27 = "charactor/f/shinentai/shinentai.prefab";
  v17[7] = "charactor/f/shinentai/shinentai.prefab";
  v30 = "charactor/f/shinentai/shinentai.prefab";
  v17[8] = "charactor/f/shinentai/shinentai.prefab";
  v33 = "charactor/f/shinentai/shinentai.prefab";
  v17[9] = "charactor/f/shinentai/shinentai.prefab";
  v36 = "charactor/f/shinentai/shinentai.prefab";
  v17[10] = "charactor/f/shinentai/shinentai.prefab";
  v39 = "charactor/f/shinentai/shinentai.prefab";
  v17[11] = "charactor/f/shinentai/shinentai.prefab";
  v42 = "charactor/f/shinentai/shinentai.prefab";
  v17[12] = "charactor/f/shinentai/shinentai.prefab";
  v45 = "charactor/f/shinentai/shinentai.prefab";
  v17[13] = "charactor/f/shinentai/shinentai.prefab";
  v17[14] = "charactor/f/shinentai/shinentai.prefab";
  v17[15] = "field/wpc/mark_npc.prefab";
  v17[16] = "charactor/f/shinentai/shinentai_m.prefab";
  v50 = NewSpecific(string, 0x1Au);
  v52 = "charactor/f/shinentai/shinentai.prefab";
  v53 = v50 + 3;
  v50[4] = "charactor/f/shinentai/shinentai.prefab";
  v56 = "charactor/f/shinentai/shinentai.prefab";
  v50[5] = "charactor/f/shinentai/shinentai.prefab";
  v59 = "charactor/f/shinentai/shinentai.prefab";
  v50[6] = "charactor/f/shinentai/shinentai.prefab";
  v62 = "charactor/f/shinentai/shinentai.prefab";
  v50[7] = "charactor/f/shinentai/shinentai.prefab";
  v65 = "charactor/f/shinentai/shinentai.prefab";
  v50[8] = "charactor/f/shinentai/shinentai.prefab";
  v68 = "charactor/f/shinentai/shinentai.prefab";
  v50[9] = "charactor/f/shinentai/shinentai.prefab";
  v71 = "charactor/f/shinentai/shinentai.prefab";
  v50[10] = "charactor/f/shinentai/shinentai.prefab";
  v74 = "charactor/f/shinentai/shinentai.prefab";
  v50[11] = "charactor/f/shinentai/shinentai.prefab";
  v77 = "charactor/f/shinentai/shinentai.prefab";
  v50[12] = "charactor/f/shinentai/shinentai.prefab";
  v80 = "charactor/f/shinentai/shinentai.prefab";
  v50[13] = "charactor/f/shinentai/shinentai.prefab";
  v83 = "charactor/f/shinentai/shinentai.prefab";
  v50[14] = "charactor/f/shinentai/shinentai.prefab";
  v86 = "charactor/f/shinentai/shinentai.prefab";
  v50[15] = "charactor/f/shinentai/shinentai.prefab";
  v89 = "charactor/f/shinentai/shinentai.prefab";
  v50[16] = "charactor/f/shinentai/shinentai.prefab";
  v92 = "charactor/f/shinentai/shinentai.prefab";
  v50[17] = "charactor/f/shinentai/shinentai.prefab";
  v95 = "charactor/f/shinentai/shinentai.prefab";
  v50[18] = "charactor/f/shinentai/shinentai.prefab";
  v98 = "charactor/f/shinentai/shinentai.prefab";
  v50[19] = "charactor/f/shinentai/shinentai.prefab";
  v101 = "charactor/f/shinentai/shinentai.prefab";
  v50[20] = "charactor/f/shinentai/shinentai.prefab";
  v104 = "charactor/f/shinentai/shinentai.prefab";
  v50[21] = "charactor/f/shinentai/shinentai.prefab";
  v107 = "charactor/f/shinentai/shinentai.prefab";
  v50[22] = "charactor/f/shinentai/shinentai.prefab";
  v110 = "charactor/f/shinentai/shinentai.prefab";
  v50[23] = "charactor/f/shinentai/shinentai.prefab";
  v113 = "charactor/f/shinentai/shinentai.prefab";
  v50[24] = "charactor/f/shinentai/shinentai.prefab";
  v116 = "charactor/f/shinentai/shinentai.prefab";
  v50[25] = "charactor/f/shinentai/shinentai.prefab";
  v119 = "charactor/f/shinentai/shinentai.prefab";
  v50[26] = "charactor/f/shinentai/shinentai.prefab";
  v122 = "charactor/f/shinentai/shinentai.prefab";
  v50[27] = "charactor/f/shinentai/shinentai.prefab";
  v125 = "charactor/f/shinentai/shinentai.prefab";
  v50[28] = "charactor/f/shinentai/shinentai.prefab";
  v50[29] = "charactor/f/shinentai/shinentai.prefab";
  v128 = NewSpecific(string, 0x18u);
  v129 = v128 + 3;
  v128[4] = "/field/f/bin/npc35.PB";
  v128[5] = "/fld/f/bin/npc36.PB";
  v128[6] = "/fld/f/bin/npc37.PB";
  v128[7] = "/fld/f/bin/npc38.PB";
  v128[8] = "/fld/f/bin/npc39.PB";
  v128[9] = "/fld/f/bin/npc40.PB";
  v128[10] = "/fld/f/bin/npc41.PB";
  v128[11] = "/fld/f/bin/npc42.PB";
  v128[12] = "/fld/f/bin/npc43.PB";
  v128[13] = "/fld/f/bin/npc44.PB";
  v128[14] = "/fld/f/bin/npc45.PB";
  v128[15] = "/fld/f/bin/npc46.PB";
  v128[16] = "/fld/f/bin/npc47.PB";
  v128[17] = "/fld/f/bin/npc48.PB";
  v128[18] = "/fld/f/bin/npc49.PB";
  v128[19] = "/fld/f/bin/npc50.PB";
  v128[20] = "/fld/f/bin/npc51.PB";
  v128[21] = "/fld/f/bin/npc52.PB";
  v128[22] = "/fld/f/bin/npc53.PB";
  v128[23] = "/fld/f/bin/npc54.PB";
  v128[24] = "/fld/f/bin/npc55.PB";
  v128[25] = "/fld/f/bin/npc56.PB";
  v128[26] = "/fld/f/bin/npc57.PB";
  v128[27] = "/fld/f/bin/npc58.PB";
  v154 = Allocate(evtUnitHandle_t);
  evtUnitHandle_t___ctor(v154);
  v477 = fldNpcNum;
  fldNpc->m_Items[fldNpcNum]->Type = Type;
  v161 = fldNpc;
  v161->m_Items[fldNpcNum]->x = x;
  v163 = fldNpc;
  v163->m_Items[fldNpcNum]->y = y;
  v165 = fldNpc;
  v165->m_Items[fldNpcNum]->z = z;
  v167 = fldNpc;
  p_rot = &v167->m_Items[fldNpcNum]->rot;
  sub_854710(&v478, 0);
  sub_854930(p_rot, 0);
  v170 = fldNpc;
  v172 = &v170->m_Items[v477]->rot;
  sub_854710(&v478, 1u);
  sub_854930(v172, 1u);
  v173 = fldNpc;
  v175 = &v173->m_Items[v477]->rot;
  sub_854710(&v478, 2u);
  sub_854930(v175, 2u);
  v176 = fldNpc;
  v178 = &v176->m_Items[v477]->rot;
  sub_854710(&v478, 3u);
  sub_854930(v178, 3u);
  v181 = fldNpc;
  v182 = v477;
  v183 = v477;
  v185 = &v181->obj.klass + v477;
  v186 = v477;
  LODWORD(v185[4]->_1.declaringType) = 0;
  v187 = fldNpc;
  v187->m_Items[v183]->cnti = 0;
  v189 = fldNpc;
  v189->m_Items[v186]->cntAnmf = 0.0;
  v191 = fldNpc;
  v191->m_Items[v183]->cntAnmi = 0;
  v193 = fldNpc;
  v195 = &v193->obj.klass + v186;
  v196 = v186;
  LODWORD(v195[4]->_1.generic_class) = 0;
  v197 = fldNpc;
  v199 = &v197->obj.klass + v183;
  v200 = v183;
  HIDWORD(v199[4]->_1.generic_class) = hojiID;
  v201 = fldNpc;
  v203 = &v201->obj.klass + v196;
  v204 = v196;
  LODWORD(v203[4]->_1.typeDefinition) = 0;
  v205 = fldNpc;
  v205->m_Items[v200]->d3p = 0;
  v207 = fldNpc;
  v207->m_Items[v204]->Basic = 0;
  v209 = fldNpc;
  npcID = hojiID;
  v209->m_Items[v200]->name = *name;
  v212 = *&_get_Item(
             fldHitData->_fldNpcTable,
             Type)->isLongReference;
  klass_low = SLOWORD(_get_Item(
                        fldHitData->_fldNpcTable,
                        Type)[1].klass);
  v466 = *(&_get_Item(
              fldHitData->_fldNpcTable,
              Type)->isLongReference
         + 1);
  handle_low = SLOWORD(_get_Item(
                         fldHitData->_fldNpcTable,
                         Type)->gcHandle.handle);
  handle_high = SHIWORD(_get_Item(
                          fldHitData->_fldNpcTable,
                          Type)->gcHandle.handle);
  v214 = SWORD1(_get_Item(
                  fldHitData->_fldNpcTable,
                  Type)[1].klass);
  Count = _get_Count(fldHitData->_fldNpcUp);
  if (Count < 1)
  {
LABEL_347:
      goto LABEL_350;
    goto LABEL_348;
  }
  v217 = Count;
  v218 = 0;
  while (1)
  {
    isLongReference = _get_Item(
                        fldHitData->_fldNpcUp,
                        v218)->isLongReference;
    if (fldGb->fieldID == isLongReference)
    {
      v222 = *(&_get_Item(
                  fldHitData->_fldNpcUp,
                  v218)->isLongReference
             + 1);
      if (fldGb->areaID + 1 == v222)
      {
        Item = _get_Item(
                 fldHitData->_fldNpcUp,
                 v218);
        if (!Compare(Item[1].klass, *name, 0))
          break;
      }
    }
    if (++v218 >= v217)
      goto LABEL_347;
  }
  if (!HIWORD(_get_Item(
                 fldHitData->_fldNpcUp,
                 v218)[1].monitor))
    goto LABEL_479;
  v326 = _get_Item(
           fldHitData->_fldNpcUp,
           v218);
  if (evtBitCheck(SHIWORD(v326[1].monitor), 0))
  {
LABEL_479:
    v328 = SBYTE3(_get_Item(
                    fldHitData->_fldNpcUp,
                    v218)[1].monitor);
    monitor_low = LOBYTE(_get_Item(
                           fldHitData->_fldNpcUp,
                           v218)[1].monitor);
    v212 = monitor_low != 0;
    klass_low = v328;
    v466 = SLOBYTE(_get_Item(
                     fldHitData->_fldNpcUp,
                     v218)[1].monitor);
    handle_low = BYTE1(_get_Item(
                         fldHitData->_fldNpcUp,
                         v218)[1].monitor);
    handle_high = SBYTE2(_get_Item(
                           fldHitData->_fldNpcUp,
                           v218)[1].monitor);
    v214 = SBYTE4(_get_Item(
                    fldHitData->_fldNpcUp,
                    v218)[1].monitor);
    {
LABEL_350:
      v226 = fldNpc;
      v227 = v477;
      v228 = v477;
      v230 = &v226->obj.klass + v477;
      v231 = v477;
      HIDWORD(v230[4]->_1.typeDefinition) = v212;
      v232 = fldNpc;
      v232->m_Items[v228]->tCamera = v214;
      v234 = fldNpc;
      v235 = v231;
      v234->m_Items[v231]->tId1 = v466;
      v237 = fldNpc;
      v239 = handle_low;
      v237->m_Items[v235]->tId2 = handle_low;
      if (klass_low == 1)
      {
        v240 = 50.0;
        *&v241 = 180.0;
        v14 = 30.0;
          goto LABEL_367;
      }
      else if (klass_low == 2)
      {
        v240 = 100.0;
        *&v241 = 230.0;
        v14 = 80.0;
          goto LABEL_367;
      }
      else
      {
        *&v241 = 160.0;
        v240 = 20.0;
          goto LABEL_367;
      }
LABEL_367:
      v243 = fldNpc;
      v243->m_Items[v477]->csize = v14;
      if (v212 == 1)
      {
        v456 = v240;
        v458 = x;
        sub_854930(&v474, 0);
        sub_854930(&v474, 1u);
        v460 = z;
        sub_854930(&v474, 2u);
        SDF_VU0__LOADVECTOR(v470);
        FromRotation(3.1416);
        SDF_VU0__LOADVECTOR_B(v478);
        Mult();
        SDF_VU0__STOREVECTOR(&p);
        v260 = dds3SerializeID();
        v262 = v474;
        v263 = v475;
        v264 = v260;
        v265 = p.x;
        v266 = p.y;
        v268 = p.z;
        w = p.w;
        *&v480.x = v262;
        *&v480.z = v263;
        v484.x = v265;
        v484.y = v266;
        v484.z = v268;
        v484.w = w;
        basic = dds3AddUnitObjectBasic(v264, v480, v484);
        dds3SetBasicName(&basic, "NPC_MDL_UNIT");
        {
          v240 = v456;
          x = v458;
        }
        else
        {
          v240 = v456;
          x = v458;
        }
        v300 = fldNpc;
        v301 = v477;
        v302 = v477;
        v304 = &v300->obj.klass + v477;
        v305 = basic;
        v304[4]->_1.this_arg.data = basic;
        v306 = fldNpc;
        v305->gameObject = v306->m_Items[v302]->fldObj;
        if (v466 == 1)
          v308 = 6;
        else
          v308 = v466;
        dds3ObjectBaseMakeUnit(&basic, v308, v239);
        v310 = v471;
        v311 = v472;
        *&v481.x = v310;
        *&v481.z = v311;
        dds3SetSclPoseSet(&basic, v481);
        serialID = basic->serialID;
        evtGetUnitHandle(serialID)->NowMotion = handle_high;
        AttachModel(basic, v308, v239);
        dds3ObjectBaseGetModelHandle(&basic);
        z = v460;
        v316 = fldNpc;
        fldObj = v316->m_Items[v477]->fldObj;
        mdlLoopMotionForUnity(fldObj, "anim", handle_high);
        dds3ObjectBaseOnFlag(&basic, 0x400u, 0);
        UnitHandle2 = evtGetUnitHandle2(basic);
        fldNpcLightSet(UnitHandle2);
      }
      else if (!v212)
      {
        fieldID = fldGb->fieldID;
        if (fieldID <= 9)
        {
          if (fieldID == 1)
            v239 = 11;
          else
            v239 = 12;
        }
        v250 = mhfldNpcFile->m_Items[v239];
        if (!op_Equality(v250, 0, 0))
        {
LABEL_504:
          v338 = mhfldNpcFile;
          v340 = v338->m_Items[v239];
          if (op_Inequality(v340, 0, 0))
          {
            v344 = fldNpc;
            v346 = v344 + 8 * v477;
            v347 = mhfldNpcFile;
            v348 = *(v346 + 32);
            v350 = v347->m_Items[v239];
            v351 = Find("Character", 0);
            transform = get_transform(v351, 0);
            *(v348 + 136) = Instantiate_object__425664(v350, transform, 0);
            v354 = fldNpc;
            set_layer(v354->m_Items[v477]->fldObj, 15);
            v356 = sub_232A70(&v477, "D2");
            v357 = Concat_5224608("NPC_SINEN", v356);
            v359 = fldNpc;
            v360 = v357;
            v362 = v359->m_Items[v477]->fldObj;
            fldSetCharAdd(v360, v362);
          }
          v364 = fldNpc;
          v364->m_Items[v477]->npcmodel = 0;
          v367 = fldGb->fieldID;
          v461 = z;
          v457 = v240;
          v459 = x;
          if (v367 == 1)
          {
            sub_854930(&v474, 0);
            sub_854930(&v474, 1u);
            sub_854930(&v474, 2u);
            v369 = dds3SerializeID();
            v371 = v474;
            v372 = v475;
            v373 = v369;
            v374 = p.x;
            v375 = p.y;
            v377 = p.z;
            v376 = p.w;
            {
            }
            *&v482.x = v371;
            *&v482.z = v372;
            v485.x = v374;
            v485.y = v375;
            v485.z = v377;
            v485.w = v376;
            basic = dds3AddUnitObjectBasic(v373, v482, v485);
            dds3SetBasicName(&basic, "GENNPC_UNIT");
            dds3ObjectBaseMakeUnit(&basic, 2, 31);
            dds3ObjectBaseGetModelHandle(&basic);
            v379 = OOYRAD(-60.0);
            FromEuler(v379, 0.0, 0.0);
            SDF_VU0__STOREVECTOR(&p);
            dds3SetRotPoseSet(&basic, p);
            z = v461;
            v240 = v457;
            x = v459;
            v382 = fldNpc;
            v384 = v382->m_Items[v477]->fldObj;
            v386 = mdlSetHD(v384, 4, 0, 15);
            v387 = basic;
            v388 = evtGetUnitHandle2(v387);
            SetEveUnit(v386, v388);
            v389 = fldNpc;
            SetLayerAll2(v386, v389->m_Items[v477]->fldObj, 14);
              goto LABEL_563;
          }
          else
          {
            if (v367 <= 9)
            {
              v415 = fldNpc;
              v417 = v415->m_Items[v477];
              v417->y = v417->y + 90.0;
            }
            v418 = dds3SerializeID();
            v420 = v474;
            v421 = v475;
            v422 = v418;
            v423 = p.x;
            v424 = p.y;
            v426 = p.z;
            v425 = p.w;
            {
            }
            *&v483.x = v420;
            *&v483.z = v421;
            v486.x = v423;
            v486.y = v424;
            v486.z = v426;
            v486.w = v425;
            basic = dds3AddUnitObjectBasic(v422, v483, v486);
            dds3SetBasicName(&basic, "NPC_SINEN_UNIT");
            {
              z = v461;
              v240 = v457;
              x = v459;
            }
            else
            {
              z = v461;
              v240 = v457;
              x = v459;
            }
            v429 = fldNpc;
            v430 = v477;
            v431 = v477;
            v433 = &v429->obj.klass + v477;
            v434 = basic;
            v433[4]->_1.this_arg.data = basic;
            v435 = fldNpc;
            v434->gameObject = v435->m_Items[v431]->fldObj;
            dds3ObjectBaseMakeUnit(&basic, 2, 31);
            dds3ObjectBaseGetModelHandle(&basic);
            v438 = fldNpc;
            v440 = v438->m_Items[v477]->fldObj;
            v441 = mdlSetHD(v440, 2, 0, 15);
            v442 = fldNpc;
            SetLayerAll2(v441, v442->m_Items[v477]->fldObj, 14);
            if (eFldNpcIcon)
            {
              pData = eFldNpcIcon;
              v447 = fldNpc;
              v449 = v447->m_Items[v477];
              v449->d3p = dds3EffectCopy(&pData, 0, 0);
                goto LABEL_563;
            }
            else
            {
              pD3P = pFldNpcIcon;
              v450 = fldNpc;
              v452 = v450->m_Items[v477];
              v452->d3p = dds3EffectLoad(&pD3P, 0, 0, 0);
              v454 = fldNpc;
              eFldNpcIcon = v454->m_Items[v477]->d3p;
                goto LABEL_563;
            }
          }
          goto LABEL_470;
        }
        if (v239 <= 34)
        {
          v253 = mhfldNpcFile;
          asset_bc = get_asset_bc();
          FileObject = LoadFileObject(asset_bc, "fldplayer", v17[v239 + 4]);
          v257 = FileObject;
          if (FileObject)
          {
            if (*FileObject == UnityEngine_GameObject
              && !QueryInterface(FileObject, v253->obj.klass->_1.element_class))
            {
            }
            if (*v257 != UnityEngine_GameObject)
              v257 = 0;
          }
          if (v239 < LODWORD(v253->max_length))
            goto LABEL_503;
        }
        else
        {
          v253 = mhfldNpcFile;
          v254 = get_asset_bc();
          v256 = LoadFileObject(v254, "fldplayer", v50[v239 - 31]);
          v257 = v256;
          if (v256)
          {
            if (*v256 == UnityEngine_GameObject
              && !QueryInterface(v256, v253->obj.klass->_1.element_class))
            {
            }
            if (*v257 != UnityEngine_GameObject)
              v257 = 0;
          }
          if (v239 < LODWORD(v253->max_length))
          {
LABEL_503:
            v253->m_Items[v239] = v257;
            goto LABEL_504;
          }
        }
      }
      {
LABEL_563:
        v322 = npcID;
        goto LABEL_565;
      }
LABEL_470:
      v322 = npcID;
LABEL_565:
      if (fldGb->fieldID <= 9)
      {
        v393 = fldNpcNum;
        v398 = 40.0;
        v394 = name;
        v399 = eveidx;
        v395 = x;
        v396 = y;
        v397 = z;
      }
      else
      {
        fldHitProgramAdd(x, y, z, v240, 100.0, v322);
        v393 = fldNpcNum;
        v394 = name;
        v395 = x;
        v396 = y;
        v397 = z;
        v398 = *&v241;
        v399 = eveidx;
      }
      fldEveHit_AddEveHitNpc(v394, v399, v395, v396, v397, v398, v322, v393);
      ++fldNpcNum;
      v403 = fldNpc;
      v405 = v403->m_Items[v477]->fldObj;
      if (op_Inequality(v405, 0, 0))
      {
        v408 = fldNpc;
        v410 = v408->m_Items[v477]->x / 100.0;
        v411 = fldNpc->m_Items[v477]->y / -100.0;
        v412 = v408->m_Items[v477]->z / 100.0;
        v413 = get_transform(v408->m_Items[v477]->fldObj, 0);
        v479.x = v410;
        v479.y = v411;
        v479.z = v412;
        set_localPosition(v413, v479);
      }
      return;
    }
LABEL_348:
    goto LABEL_350;
  }
}

// 0x148ed00
void fldNpcCalc(void) {
  struct effHandle_t_array *eFldSibukiEff;
  effHandle_t_o *v12;
  fldUnitControl_t_o *UnitControl;
  struct effHandle_t_array *v18;
  s64 v20;
  s64 v21;
  f32 v23;
  f32 v26;
  f32 v27;
  f32 v28;
  f32 v29;
  f32 v31;
  f32 v32;
  struct fldGlobalWork_t_o *fldGb;
  fldUnitControl_t_o *v37;
  f32 v39;
  f32 v40;
  f32 v41;
  f32 v44;
  f32 v45;
  u64 v46;
  u64 v47;
  s16 v48;
  s32 v49;
  s64 v50;
  struct fldNpc_tag_array *fldNpc;
  struct fldGlobalWork_t_o *v56;
  s32 fieldID;
  s32 areaID;
  struct fldNpc_tag_array *v59;
  struct fldNpc_tag_array *v62;
  Il2CppClass **v64;
  struct fldNpc_tag_array *v65;
  f32 v66;
  f32 y;
  f32 z;
  struct fldNpc_tag_array *v70;
  s32 tType;
  struct fldNpc_tag_array *v75;
  struct fldNpc_tag_array *v77;
  struct fldNpc_tag_array *v79;
  struct fldNpc_tag_array *v81;
  struct fldNpc_tag_array *v87;
  struct fldNpc_tag_array *v89;
  struct fldNpc_tag_array *v91;
  f32 v94;
  f32 v95;
  s32 v98;
  struct fldNpc_tag_array *v100;
  s32 ItemBoxIdx;
  struct fldNpc_tag_array *v104;
  struct fldNpc_tag_array *v106;
  struct fldNpc_tag_array *v109;
  struct fldNpc_tag_array *v112;
  struct fldNpc_tag_array *v114;
  struct fldNpc_tag_array *v117;
  struct fldNpc_tag_array *v120;
  f32 v123;
  f32 v125;
  struct fldNpc_tag_array *v128;
  struct fldNpc_tag_array *v132;
  System_String_o **p_name;
  struct fldNpc_tag_array *v136;
  struct fldNpc_tag_array *v144;
  struct fldNpc_tag_array *v147;
  struct fldNpc_tag_array *v149;
  f32 v152;
  f32 v153;
  struct fldNpc_tag_array *v156;
  struct fldNpc_tag_array *v158;
  struct fldNpc_tag_array *v160;
  struct fldNpc_tag_array *v162;
  struct fldNpc_tag_array *v164;
  UnityEngine_Object_o *v166;
  struct fldNpc_tag_array *v168;
  Il2CppClass **v170;
  struct fldNpc_tag_array *v171;
  f32 v172;
  f32 v173;
  f32 v174;
  UnityEngine_Transform_o *v175;
  struct fldNpc_tag_array *v178;
  UnityEngine_Transform_o *v181;
  struct fldNpc_tag_array *v183;
  struct fldNpc_tag_array *v185;
  f32 v188;
  f32 v189;
  struct fldNpc_tag_array *v190;
  struct fldNpc_tag_array *v192;
  f32 v195;
  f32 v196;
  struct fldNpc_tag_array *v199;
  struct fldNpc_tag_array *v201;
  UnityEngine_Object_o *fldObj;
  struct fldNpc_tag_array *v205;
  Il2CppClass **v207;
  struct fldNpc_tag_array *v208;
  f32 v209;
  f32 v210;
  f32 v211;
  UnityEngine_Transform_o *transform;
  struct fldNpc_tag_array *v213;
  struct fldNpc_tag_array *v215;
  f32 v218;
  f32 v219;
  struct fldNpc_tag_array *v220;
  struct fldNpc_tag_array *v223;
  f32 v226;
  f32 v227;
  Il2CppObject *pData;
  s64 v229;
  s64 v230;
  UnityEngine_Vector3_o v231;
  UnityEngine_Vector3_o v232;
  UnityEngine_Vector4_o v233;
  UnityEngine_Quaternion_o v234;

  v229 = 0;
  v230 = 0;
  pData = 0;
  gFldNowTalk = 0;
  if (fldGb->fieldID <= 199)
  {
    if (fldSeqCheckFlag(1u) != 1)
    {
      if (!fldProcCampChk())
      {
        if (!fldProcAmChk())
        {
          if (gFldSibukiEff)
          {
            sub_854690(&v229, 0.0, 0.0, 0.0, 1.0);
            v12 = eFldSibukiEff->m_Items[0];
            if (!dds3EffectGetState(v12))
              goto LABEL_68;
            if (fldGb->WaterIdx == -1)
            {
LABEL_68:
              gFldSibukiEff = 0;
            }
            else
            {
              UnitControl = fldGetUnitControl();
              sub_854710(&UnitControl->handle->poseset->pos2, 0);
              sub_854930(&v229, 0);
              sub_854930(&v229, 1u);
              sub_854710(&UnitControl->handle->poseset->pos2, 2u);
              sub_854930(&v229, 2u);
              v18 = eFldSibukiEff;
              pData = v18->m_Items[0];
              v20 = v229;
              v21 = v230;
              *&v233.x = v20;
              *&v233.z = v21;
              dds3EffectSetPosition(&pData, v233);
              sub_854710(&UnitControl->handle->poseset->pos, 0);
              sub_854930(&v229, 0);
              sub_854930(&v229, 1u);
              sub_854710(&UnitControl->handle->poseset->pos, 2u);
              sub_854930(&v229, 2u);
              dds3GetPosPoseSet(&player);
              SDF_VU0__LOADVECTOR_B(gFldWavePosOld);
              SDF_VU0__STOREVECTOR(&gFldWavePosOld);
              SDF_VU0__SUBVECTOR();
              v23 = SDF_VU0__GETLENGTH();
              gFldWaveLen = v23 + gFldWaveLen;
              if (gFldWaveLen > 100.0)
              {
                gFldWaveLen = 0.0;
                sub_854710(&v229, 0);
                v27 = v26;
                sub_854710(&v229, 1u);
                v29 = v28;
                sub_854710(&v229, 2u);
                v32 = v31;
                fldWaveStart(v27, v29, v32);
              }
              ++fldNpcCalc_wavecnt;
            }
          }
          else
          {
            if (fldGb->WaterIdx != -1)
            {
              if (fldGb->LastMoveLeng > 3.0)
              {
                v37 = fldGetUnitControl();
                v39 = fldGb->WaterY + -5.0;
                sub_854710(&v37->handle->poseset->pos2, 0);
                v41 = v40;
                sub_854710(&v37->handle->poseset->pos2, 2u);
                v45 = v44;
                fldSibukiStart(v41, v39, v45);
              }
            }
          }
          v46 = 0;
          if ((v48 & 0x200) != 0)
            goto LABEL_95;
LABEL_93:
          v49 = 0;
          v50 = *(v47 + 184);
          if (v46 >= *(v50 + 56))
          {
LABEL_415:
            fldNpcShadow_Calc(v47);
            return;
          }
          while (1)
          {
            if (v49 && !*(v47 + 216))
            {
              if (v46 >= LODWORD(fldNpc->max_length))
              {
LABEL_101:
              }
            }
            else
            {
              fldNpc = *(v50 + 48);
              if (v46 >= LODWORD(fldNpc->max_length))
                goto LABEL_101;
            }
            if (fldNpc->m_Items[v46]->hojiID)
            {
              v56 = fldGb;
              fieldID = v56->fieldID;
              areaID = v56->areaID;
              v59 = fldNpc;
              if (fldGbChkNpc(fieldID, areaID + 1, v59->m_Items[v46]->hojiID))
                goto LABEL_92;
            }
            v62 = fldNpc;
            v64 = &v62->obj.klass + v46;
            v65 = fldNpc;
            v66 = *(&v64[4]->_1.name + 1);
            y = v65->m_Items[v46]->y;
            z = v65->m_Items[v46]->z;
            if (v65->m_Items[v46]->Type == 999)
            {
              if (!fldProcCheckFlag(0x40u))
              {
                v100 = fldNpc;
                ItemBoxIdx = v100->m_Items[v46]->ItemBoxIdx;
                if (fldEveHit_ChkTakaraScr(ItemBoxIdx) == 1)
                {
                  v104 = fldNpc;
                  v104->m_Items[v46]->cntAnmf = v104->m_Items[v46]->cntAnmf + 1.05;
                  v106 = fldNpc;
                  if (v106->m_Items[v46]->cntAnmf > 1.0)
                  {
                    v109 = fldNpc;
                    v109->m_Items[v46]->cntAnmf = 1.0;
                  }
                  v112 = fldNpc;
                  v112->m_Items[v46]->cntAnmi += 2;
                  v114 = fldNpc;
                  if (v114->m_Items[v46]->cntAnmi >= 49)
                  {
                    v117 = fldNpc;
                    v117->m_Items[v46]->cntAnmi = 48;
                  }
                  gFldNowTalk = 2;
                  gFldNpcX = v66;
                  gFldNpcY = y;
                  gFldNpcZ = z;
                  v120 = fldNpc;
                  SDF_VU0__LOADVECTOR(v120->m_Items[v46]->rot);
                  v123 = EulerAngleAxisY();
                  v125 = OOYDEG(v123);
                  gFldNpcR = v125;
                  v128 = fldNpc;
                  switch (*&_get_Item(
                               fldHitData->_fldItemBoxTbl,
                               v128->m_Items[v46]->ItemBoxIdx)->isLongReference)
                  {
                    case 0:
                    case 2:
                    case 3:
                      gFldNpcOY = -110.0;
                      break;
                    case 1:
                      gFldNpcOY = -90.0;
                      break;
                    default:
                      goto LABEL_92;
                  }
                }
                goto LABEL_92;
              }
            }
            v70 = fldNpc;
            tType = v70->m_Items[v46]->tType;
            if (tType == 1)
            {
              if (fldSeqCheckFlag(1u))
                goto LABEL_370;
              if (fldProcCheckFlag(0x40u))
                goto LABEL_370;
              if (fldEveHit_ChkNpcScr(v46) != 1)
                goto LABEL_370;
              v87 = fldNpc;
              if (v87->m_Items[v46]->tCamera)
              {
                v89 = fldNpc;
                if (v89->m_Items[v46]->tCamera == 1)
                {
                  gFldNowTalk = 1;
                  gFldNowTalkIdx = -1;
                  gFldNpcX = v66;
                  gFldNpcY = y;
                  gFldNpcZ = z;
                  v91 = fldNpc;
                  SDF_VU0__LOADVECTOR(v91->m_Items[v46]->rot);
                  v94 = EulerAngleAxisY();
                  v95 = OOYDEG(v94);
                  gFldNpcR = v95;
                  v98 = -1025769472;
                  goto LABEL_366;
                }
                v183 = fldNpc;
                if (v183->m_Items[v46]->tCamera == 2)
                {
                  gFldNowTalk = 1;
                  gFldNowTalkIdx = -1;
                  gFldNpcX = v66;
                  gFldNpcY = y;
                  gFldNpcZ = z;
                  v185 = fldNpc;
                  SDF_VU0__LOADVECTOR(v185->m_Items[v46]->rot);
                  v188 = EulerAngleAxisY();
                  v189 = OOYDEG(v188);
                  gFldNpcR = v189;
                  v98 = -1035468800;
                  goto LABEL_366;
                }
                v190 = fldNpc;
                if (v190->m_Items[v46]->tCamera == 3)
                {
                  gFldNowTalk = 1;
                  gFldNowTalkIdx = -1;
                  gFldNpcX = v66;
                  gFldNpcY = y;
                  gFldNpcZ = z;
                  v192 = fldNpc;
                  SDF_VU0__LOADVECTOR(v192->m_Items[v46]->rot);
                  v195 = EulerAngleAxisY();
                  v196 = OOYDEG(v195);
                  gFldNpcR = v196;
                  v98 = -1020002304;
LABEL_366:
                  LODWORD(gFldNpcOY) = v98;
LABEL_367:
                  LODWORD(gFldNpcCY) = v98;
                  v199 = fldNpc;
                  gFldNpcCS = v199->m_Items[v46]->csize;
                }
                else
                {
                  v213 = fldNpc;
                  if (v213->m_Items[v46]->tCamera == 4)
                  {
                    gFldNowTalk = 1;
                    gFldNowTalkIdx = -1;
                    gFldNpcX = v66;
                    gFldNpcY = y;
                    gFldNpcZ = z;
                    v215 = fldNpc;
                    SDF_VU0__LOADVECTOR(v215->m_Items[v46]->rot);
                    v218 = EulerAngleAxisY();
                    v219 = OOYDEG(v218);
                    gFldNpcR = v219;
                    gFldNpcOY = -10.0;
                    v98 = -1020657664;
                    goto LABEL_367;
                  }
                  v220 = fldNpc;
                  if (v220->m_Items[v46]->tCamera == 5)
                  {
                    gFldNowTalk = 1;
                    gFldNowTalkIdx = -1;
                    gFldNpcX = v66;
                    gFldNpcY = y;
                    gFldNpcZ = z;
                    v223 = fldNpc;
                    SDF_VU0__LOADVECTOR(v223->m_Items[v46]->rot);
                    v226 = EulerAngleAxisY();
                    v227 = OOYDEG(v226);
                    gFldNpcR = v227;
                    gFldNpcOY = -210.0;
                    v98 = -1020002304;
                    goto LABEL_367;
                  }
                }
LABEL_370:
                {
LABEL_371:
                }
              }
              else
              {
                gFldNowTalk = 0;
                  goto LABEL_371;
              }
              v201 = fldNpc;
              fldObj = v201->m_Items[v46]->fldObj;
              {
              }
              if (op_Inequality(fldObj, 0, 0))
              {
                v205 = fldNpc;
                v207 = &v205->obj.klass + v46;
                v208 = fldNpc;
                v209 = *(&v207[4]->_1.name + 1);
                v210 = v208->m_Items[v46]->y;
                v211 = v208->m_Items[v46]->z / 100.0;
                transform = get_transform(v208->m_Items[v46]->fldObj, 0);
                v232.x = v209 / 100.0;
                v232.y = v210 / -100.0;
                v232.z = v211;
                set_localPosition(transform, v232);
              }
              goto LABEL_92;
            }
            if (!tType)
              break;
LABEL_92:
            ++v46;
            if ((v48 & 0x200) == 0)
              goto LABEL_93;
LABEL_95:
            v49 = v48 & 0x200;
            v50 = *(v47 + 184);
            if (v46 >= *(v50 + 56))
              goto LABEL_415;
          }
          if (fldSeqCheckFlag(1u))
            goto LABEL_137;
          if (fldProcCheckFlag(0x40u))
            goto LABEL_137;
          if (fldEveHit_ChkNpcScr(v46) != 1)
          {
            v132 = fldNpc;
            p_name = &v132->m_Items[v46]->name;
            if (fldCamNpcCamChk(p_name) != 1)
            {
LABEL_137:
              v75 = fldNpc;
              v75->m_Items[v46]->cntf = v75->m_Items[v46]->cntf + 0.1;
              v77 = fldNpc;
              ++v77->m_Items[v46]->cnti;
              v79 = fldNpc;
              v79->m_Items[v46]->cnti &= 1u;
              v81 = fldNpc;
              v81->m_Items[v46]->cntAnmi = 0;
              fldNpcModelEnd(v46);
                goto LABEL_307;
              goto LABEL_149;
            }
          }
          v136 = fldNpc;
          if (v136->m_Items[v46]->cntAnmi)
          {
              goto LABEL_290;
          }
          else
          {
            gFldNowTalkIdx = v46;
            if (fldGb->fieldID >= 11)
            {
              fldSePlay(45);
              v144 = fldNpc;
              fldNpcModelStart(v46, v66, y + -10.0, z, v144->m_Items[v46]->rot);
            }
            v147 = fldNpc;
            v147->m_Items[v46]->cntAnmi = 128;
            {
LABEL_290:
              gFldNowTalk = 1;
              gFldNpcX = v66;
              gFldNpcY = y;
              gFldNpcZ = z;
              v149 = fldNpc;
              SDF_VU0__LOADVECTOR(v149->m_Items[v46]->rot);
              v152 = EulerAngleAxisY();
              v153 = OOYDEG(v152);
              gFldNpcR = v153;
              gFldNpcOY = -140.0;
              gFldNpcCY = -140.0;
              v156 = fldNpc;
              gFldNpcCS = v156->m_Items[v46]->csize;
              v158 = fldNpc;
              v158->m_Items[v46]->cntf = v158->m_Items[v46]->cntf + 0.05;
              v160 = fldNpc;
              ++v160->m_Items[v46]->cnti;
              v162 = fldNpc;
              v162->m_Items[v46]->cnti &= 1u;
                goto LABEL_307;
LABEL_149:
LABEL_307:
              v164 = fldNpc;
              v166 = v164->m_Items[v46]->fldObj;
              {
              }
              if (op_Inequality(v166, 0, 0))
              {
                v168 = fldNpc;
                v170 = &v168->obj.klass + v46;
                v171 = fldNpc;
                v172 = *(&v170[4]->_1.name + 1);
                v173 = v171->m_Items[v46]->y;
                v174 = v171->m_Items[v46]->z / 100.0;
                v175 = get_transform(v171->m_Items[v46]->fldObj, 0);
                v231.x = v172 / 100.0;
                v231.y = v173 / -100.0;
                v231.z = v174;
                set_localPosition(v175, v231);
                if (fldGb->fieldID == 1)
                {
                  v178 = fldNpc;
                  v181 = get_transform(v178->m_Items[v46]->fldObj, 0);
                  {
                  }
                  v234 = Euler(45.0, 0.0, 0.0);
                  set_rotation(v181, v234);
                }
              }
              goto LABEL_92;
            }
          }
          goto LABEL_290;
        }
      }
    }
  }
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
    if (fldNpc->m_Items[v4])
    {
        goto LABEL_22;
LABEL_11:
      goto LABEL_22;
    }
    v11 = fldNpc;
    v12 = Allocate(fldNpc_tag);
    _ctor(v12, 0);
    *&v11[2 * v4 + 8] = v12;
      goto LABEL_11;
LABEL_22:
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
  u64 *v1;
  u64 *v2;
  u64 v6;
  s64 v7;
  fld_Npc_c *v8;
  struct fldTakaraWork_tag_array *gfldTakaraWork;
  u32 data_high;
  bool v13;
  struct fldTakaraWork_tag_array *v15;
  s32 namespaze_high;
  struct fldTakaraWork_tag_array *v19;
  dds3Basic_t_o **p_name;
  sdfModelRootNode_t_o *modelRoot;
  struct fldTakaraWork_tag_array *v28;
  s32 v30;
  struct fldTakaraWork_tag_array *v33;
  struct fldTakaraWork_tag_array *v36;
  dds3Basic_t_o **v38;
  sdfModelRootNode_t_o *v40;
  struct fldTakaraWork_tag_array *v45;
  UnityEngine_Object_o *v47;
  struct fldTakaraWork_tag_array *v49;
  UnityEngine_Transform_o *transform;
  struct fldTakaraWork_tag_array *v52;
  struct fldTakaraWork_tag_array *v55;
  System_Collections_Generic_List_WeakReference__o *fldItemBoxTbl;
  struct fldTakaraWork_tag_array *v61;
  s32 v63;
  effHandle_t_o *eFldTDmgEff;
  f32 v67;
  f32 x;
  f32 w;
  f32 v70;
  struct effPartHandle_t_array *gfldTakaraGtEff;
  struct effPartHandle_t_array *v74;
  f32 v75;
  f32 v76;
  f32 v77;
  f32 v78;
  struct effPartHandle_t_array *v80;
  struct fldTakaraWork_tag_array *v83;
  UnityEngine_Object_o *v85;
  struct fldTakaraWork_tag_array *v87;
  UnityEngine_Transform_o *v89;
  struct fldTakaraWork_tag_array *v90;
  f32 v92;
  f32 v93;
  f32 v94;
  f32 v95;
  struct fldTakaraWork_tag_array *v97;
  dds3Basic_t_o **v99;
  sdfModelRootNode_t_o **p_modelRoot;
  f32 v104;
  f32 v105;
  f32 v106;
  f32 v107;
  f32 v108;
  f32 v109;
  f32 v110;
  f32 v111;
  f32 v112;
  f32 v113;
  f32 v115;
  f32 v116;
  f32 v117;
  u64 v119;
  s32 v122;
  u64 v123;
  struct fldNpc_tag_array *v125;
  struct fldGlobalWork_t_o *v130;
  s32 v131;
  s32 v132;
  struct fldNpc_tag_array *v133;
  struct fldNpc_tag_array *v136;
  struct fldNpc_tag_array *v139;
  dds3Basic_t_o **p_Basic;
  bool v142;
  struct fldNpc_tag_array *v144;
  Il2CppClass **v146;
  struct fldNpc_tag_array *v147;
  f32 v148;
  f32 y;
  f32 z;
  struct fldNpc_tag_array *v152;
  s32 tType;
  struct fldNpc_tag_array *v156;
  struct fldNpc_tag_array *v160;
  struct fldNpc_tag_array *v163;
  UnityEngine_GameObject_o *fldObj;
  bool v166;
  struct fldNpc_tag_array *v169;
  struct fldNpc_tag_array *v172;
  struct fldNpc_tag_array *v175;
  dds3Basic_t_o **v177;
  f32 v178;
  f32 v179;
  f32 v180;
  f32 v181;
  f32 v182;
  f32 v183;
  f32 v184;
  f32 v185;
  f32 v186;
  f32 v187;
  f32 v189;
  f32 v190;
  f32 v191;
  f32 v193;
  struct fldNpc_tag_array *v194;
  struct fldNpc_tag_array *v197;
  struct fldNpc_tag_array *v200;
  struct fldNpc_tag_array *v203;
  s32 v206;
  f32 v209;
  struct fldNpc_tag_array *v211;
  struct fldNpc_tag_array *v214;
  struct fldNpc_tag_array *v217;
  struct fldNpc_tag_array *v220;
  struct fldNpc_tag_array *v223;
  struct fldNpc_tag_array *v230;
  f32 cntf;
  struct fldNpc_tag_array *v233;
  s32 gFldNowTalkIdx;
  struct fldNpc_tag_array *fldNpc;
  struct fld_Npc_StaticFields **p_static_fields;
  u64 *v244;
  Il2CppObject *ModelHandle;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v251;
  UnityEngine_Object_o *v252;
  Il2CppObject *Component_object;
  struct fldGlobalWork_t_o *fldGb;
  s32 fieldID;
  s32 areaID;
  f32 fldNpc01RGBA_Cnt;
  f32 v261;
  struct fldGlobalWork_t_o *v265;
  struct System_Int32_array *pm;
  struct System_Int32_array *v271;
  struct dds3Effect_PartialMultiFilter_t_o *v273;
  fld_Npc_c *v275;
  effHandle_t_o *eFldDmgEff;
  s16 v278;
  s32 v279;
  struct effHandle_t_array *v281;
  effHandle_t_o *v283;
  struct effHandle_t_array *v286;
  u64 v288;
  struct effHandle_t_array *eFldSibukiEff;
  effHandle_t_o *v291;
  struct effHandle_t_array *v293;
  f32 v297;
  f32 v298;
  struct dds3Effect_DistortionBlurParam_t_o *param;
  s32 v300;
  f32 v302;
  f32 v303;
  f32 v304;
  f32 v305;
  char *v306;
  s64 *v307;
  Il2CppObject *v308;
  Il2CppObject *v309;
  Il2CppObject *v310;
  Il2CppObject *v311;
  Il2CppObject *pData;
  Il2CppObject *v313;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o v315;
  UnityEngine_Vector4_o v316;
  UnityEngine_Vector4_o p;
  u64 v318[4];
  UnityEngine_Vector3_o localPosition;
  UnityEngine_Vector3_o v320;
  UnityEngine_Vector4_o v321;
  UnityEngine_Vector4_o v322;
  UnityEngine_Vector4_o v323;

  *&p.x = 0;
  *&p.z = 0;
  pData = 0;
  v313 = 0;
  v310 = 0;
  v311 = 0;
  v308 = 0;
  v309 = 0;
  sub_854690(&p.x, 0.0, 0.0, 0.0, 1.0);
  *&v316.x = 0;
  *&v316.z = 0;
  *&v315.x = 0;
  *&v315.z = 0;
  v1 = Allocate(Sprite3D_t);
  Sprite3D_t___ctor(v1);
  v2 = Allocate(evtUnitHandle_t);
  evtUnitHandle_t___ctor(v2);
  *&dst.x = 0;
  *&dst.z = 0;
  if (fldGb->fieldID <= 199)
  {
    if (!fldSeqCheckFlag(1u))
    {
      v6 = 0;
      v7 = 32;
        goto LABEL_16;
LABEL_14:
      while (1)
      {
LABEL_16:
        if (v6 >= gfldTakaraNum)
        {
          v123 = 0;
          if ((v8->_2.bitflags2 & 2) == 0)
            goto LABEL_213;
          while (2)
          {
LABEL_213:
            if (v123 >= fldNpcNum)
            {
              if (fldGb->fieldID < 11)
                goto LABEL_502;
              if (gFldNowTalk != 1)
                goto LABEL_502;
              if (gFldNowTalkIdx == -1)
                goto LABEL_502;
              if (fldNpc->m_Items[gFldNowTalkIdx]->tType)
                goto LABEL_502;
              fldNpc01RGBA += 5;
              if (fldNpc01RGBA >= 128)
              {
                fldNpc01RGBA = 128;
                (*p_static_fields)->fldNpc01RGBA_Cnt = (*p_static_fields)->fldNpc01RGBA_Cnt + 0.05;
              }
              else
              {
                fldNpc01RGBA_Cnt = 0.0;
              }
              v244 = Allocate(dds3ModelHandle_t);
              dds3ModelHandle_t___ctor(v244);
              ModelHandle = dds3ObjectBaseGetModelHandle(&fldNpc01Basic);
              klass = ModelHandle->klass;
              if (ModelHandle->klass->_2.typeHierarchyDepth < typeHierarchyDepth
                || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
              {
                sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, v318);
                if ((v318[0] & 1) != 0)
                  v306 = v318[2];
                else
                  v306 = v318 + 1;
                v307 = sub_8C4940(v306);
              }
              v251 = ModelHandle[4].klass;
              if (!v251)
                goto LABEL_467;
              v252 = *&v251->_2.initializationExceptionGCHandle;
              {
              }
              if (!op_Inequality(v252, 0, 0))
                goto LABEL_467;
              Component_object = GetComponent_object_(*&v251->_2.initializationExceptionGCHandle);
              {
              }
              if (op_Inequality(Component_object, 0, 0))
              {
                fieldID = fldGb->fieldID;
                areaID = fldGb->areaID;
                if (fieldID == 15 && areaID == 5 || fieldID == 17 && !areaID || fieldID == 45 && areaID == 29)
                {
                  v261 = sdfSin(fldNpc01RGBA_Cnt);
                  SetBlendPower(
                    Component_object,
                    (v261 * 5.0) + ((fldNpc01RGBA * 95.0) * 0.0078125),
                    0);
                  fldNpcBlurD->param->abgr = 1082163328;
                  goto LABEL_467;
                }
                if (fieldID == 18 && areaID == 8)
                {
                  v297 = fldNpc01RGBA_Cnt;
                  v298 = sdfSin(v297);
                  SetBlendPower(
                    Component_object,
                    (v298 * 5.0) + ((fldNpc01RGBA * 95.0) * 0.0078125),
                    0);
                  param = fldNpcBlurD->param;
                  v300 = 813727872;
                }
                else
                {
                  if (fieldID == 34 && ((areaID + 1) | 1) == 3)
                  {
                    v302 = fldNpc01RGBA_Cnt;
                    v303 = sdfSin(v302);
                    SetBlendPower(
                      Component_object,
                      (v303 * 5.0) + ((fldNpc01RGBA * 50.0) * 0.0078125),
                      0);
                    param = fldNpcBlurD->param;
                    v300 = 545292416;
                  }
                  else
                  {
                    v304 = fldNpc01RGBA_Cnt;
                    v305 = sdfSin(v304);
                    SetBlendPower(
                      Component_object,
                      (v305 * 25.0) + ((fldNpc01RGBA * 75.0) * 0.0078125),
                      0);
                    param = fldNpcBlurD->param;
                    v300 = 1619034240;
                  }
                }
                param->abgr = v300;
                {
LABEL_470:
                  dds3EffectDistortionBlurDraw(&fldNpcBlurD, 0, 0);
                  v265 = fldGb;
                  if (v265->fieldID == 18)
                  {
                    if (v265->areaID == 8)
                    {
                      if (gFldNowTalkIdx == 2 && evtBitCheck(1195))
                      {
                        {
                        }
                        dds3EffectDistortionBlur_SetMoya(-0.4);
                        dds3EffectDistortionBlur_SetArea(0.12, 0.6);
                        fldNpcBlur_MultiFilter_Param->Filter->blend = 3;
                        fldNpcBlur_MultiFilter_Param->Filter->abgr = 679510144;
                        fldNpcBlur_MultiFilter_Param->area = 125;
                        pm = fldNpcBlur_MultiFilter_Param->center->pm;
                        pm->m_Items[0] = 64;
                        v271 = fldNpcBlur_MultiFilter_Param->center->pm;
                        v271->m_Items[1] = -180;
                        v273 = dds3EffectPartialMultiFilterCreate(fldNpcBlur_MultiFilter_Param);
                        fldNpcBlur_MultiFilterBuff = v273;
                        dds3EffectPartialMultiFilterDraw(&fldNpcBlur_MultiFilterBuff);
                        {
LABEL_505:
                          if (!gFldDmgEff)
                            goto LABEL_520;
                          v13 = dds3EffectGetState(eFldDmgEff) == 0;
                          if (v13)
                          {
                            gFldDmgEff = 0;
                            v278 = *&v275->_2.bitflags1;
                            if ((v278 & 0x200) == 0)
                              goto LABEL_521;
                          }
                          else
                          {
                            v310 = eFldDmgEff;
                            dds3EffectDraw(&v310);
LABEL_520:
                            v278 = *&v275->_2.bitflags1;
                            if ((v278 & 0x200) == 0)
                            {
LABEL_521:
                              v279 = 0;
                              if (gFldSibukiEff)
                                goto LABEL_522;
LABEL_548:
                              v291 = eFldSibukiEff->m_Items[0];
                              {
                              }
                              if (dds3EffectGetState(v291))
                              {
                                v293 = eFldSibukiEff;
                                v308 = v293->m_Items[0];
                                {
                                }
                                dds3EffectDrawOff(&v308);
                              }
                              goto LABEL_566;
                            }
                          }
                          v279 = v278 & 0x200;
                          if (!gFldSibukiEff)
                            goto LABEL_548;
LABEL_522:
                          v281 = eFldSibukiEff;
                          v283 = v281->m_Items[0];
                          if (dds3EffectGetState(v283))
                          {
                            v286 = eFldSibukiEff;
                            v309 = v286->m_Items[0];
                            dds3EffectDraw(&v309);
                            {
LABEL_569:
                              fldEADraw(v288);
                              fldVLDraw();
                              return;
                            }
                          }
                          else
                          {
LABEL_566:
                              goto LABEL_569;
                          }
                          goto LABEL_569;
                        }
LABEL_503:
                        goto LABEL_505;
                      }
                    }
                  }
                  dds3EffectDistortionBlur_SetMoya(-0.1);
                  dds3EffectDistortionBlur_SetArea(0.12, 0.6);
LABEL_502:
                    goto LABEL_505;
                  goto LABEL_503;
                }
              }
              else
              {
LABEL_467:
                  goto LABEL_470;
              }
              goto LABEL_470;
            }
            else
            {
              v125 = fldNpc;
              if (v123 >= LODWORD(v125->max_length))
                goto LABEL_217;
            }
            if (v125->m_Items[v123]->hojiID)
            {
              v130 = fldGb;
              v131 = v130->fieldID;
              v132 = v130->areaID;
              v133 = fldNpc;
              if (fldGbChkNpc(v131, v132 + 1, v133->m_Items[v123]->hojiID))
              {
                v136 = fldNpc;
                if (v136->m_Items[v123]->Basic)
                {
                  v139 = fldNpc;
                  p_Basic = &v139->m_Items[v123]->Basic;
                  v142 = 0;
                  goto LABEL_240;
                }
                goto LABEL_210;
              }
            }
            v144 = fldNpc;
            v146 = &v144->obj.klass + v123;
            v147 = fldNpc;
            v148 = *(&v146[4]->_1.name + 1);
            y = v147->m_Items[v123]->y;
            z = v147->m_Items[v123]->z;
            if (v147->m_Items[v123]->Type == 999)
              goto LABEL_210;
            v152 = fldNpc;
            tType = v152->m_Items[v123]->tType;
            if (tType != 1)
            {
              if (tType)
                goto LABEL_210;
              v156 = fldNpc;
              if (v156->m_Items[v123]->cntAnmi)
              {
                if (fldGb->fieldID >= 11)
                {
                  v160 = fldNpc;
                  if (get_activeSelf(v160->m_Items[v123]->fldObj))
                  {
                    v163 = fldNpc;
                    fldObj = v163->m_Items[v123]->fldObj;
                    v166 = 0;
                    goto LABEL_329;
                  }
                }
              }
              else
              {
                v200 = fldNpc;
                if (!get_activeSelf(v200->m_Items[v123]->fldObj))
                {
                  v203 = fldNpc;
                  fldObj = v203->m_Items[v123]->fldObj;
                  v166 = 1;
LABEL_329:
                  SetActive(fldObj, v166, 0);
                }
              }
              v206 = fldGb->fieldID;
              if (v206 == 1)
                goto LABEL_210;
              else
              {
                if (v206 < 11)
                {
LABEL_337:
                  v209 = (y + -10.0) + -90.0;
LABEL_372:
                  ooyTestDrawMaruKage(v148, v209, z, 60.0, 96);
                  v223 = fldNpc;
                  if (!v223->m_Items[v123]->cntAnmi)
                    goto LABEL_382;
                  if (fldGb->fieldID <= 9)
                  {
LABEL_382:
                    sub_854930(&p, 0);
                    if (fldGb->fieldID == 1)
                    {
                      v230 = fldNpc;
                      cntf = v230->m_Items[v123]->cntf;
                    }
                    else
                    {
                      v233 = fldNpc;
                      cntf = v233->m_Items[v123]->cntf;
                    }
                    sdfSin(cntf * 1.5);
                    sub_854930(&p, 1u);
                    sub_854930(&p, 2u);
                  }
                  goto LABEL_210;
                }
              }
              v209 = y + -10.0;
              goto LABEL_372;
            }
            SDF_VU0__COPYVECTOR(&dst, dds3CameraEyePos);
            v169 = fldNpc;
            if (!v169->m_Items[v123]->Basic)
              goto LABEL_210;
            v172 = fldNpc;
            dds3ObjectBaseOffFlag(&v172->m_Items[v123]->Basic, 1u);
            v175 = fldNpc;
            v177 = &v175->m_Items[v123]->Basic;
            dds3GetPosPoseSet(v177);
            SDF_VU0__STOREVECTOR(&p);
            sub_854710(&dst, 1u);
            v179 = v178;
            sub_854710(&p, 1u);
            v181 = v179 - v180;
            if (v181 < 0.0)
              v181 = -v181;
            if (v181 >= 250.0)
              goto LABEL_210;
            sub_854710(&dst, 0);
            v183 = v182;
            sub_854710(&p, 0);
            v185 = v183 - v184;
            sub_854710(&dst, 2u);
            v187 = v186;
            sub_854710(&p, 2u);
            v190 = v187 - v189;
            v191 = sdfSqrt((v185 * v185) + (v190 * v190), 0);
            v193 = v191;
            v194 = fldNpc;
            if (v194->m_Items[v123]->csize >= 79.0)
            {
              if (v193 < 95.0)
                goto LABEL_342;
            }
            else
            {
              v197 = fldNpc;
              if (v197->m_Items[v123]->csize >= 29.0)
              {
                if (v193 >= 75.0)
                  goto LABEL_348;
              }
              else if (v193 >= 60.0)
              {
                goto LABEL_348;
              }
LABEL_342:
              v211 = fldNpc;
              dds3ObjectBaseOnFlag(&v211->m_Items[v123]->Basic, 1u, 1);
            }
LABEL_348:
            v214 = fldNpc;
            if (v214->m_Items[v123]->tId1 == 6)
            {
              v217 = fldNpc;
              if (v193 < 110.0 && v217->m_Items[v123]->tId2 == 73)
              {
                v220 = fldNpc;
                p_Basic = &v220->m_Items[v123]->Basic;
                v142 = 1;
LABEL_240:
                dds3ObjectBaseOnFlag(p_Basic, 1u, v142);
              }
            }
LABEL_210:
            ++v123;
              continue;
            goto LABEL_213;
          }
        }
        else
        {
          if (v6 >= LODWORD(gfldTakaraWork->max_length))
            goto LABEL_20;
        }
        data_high = HIDWORD((*(&gfldTakaraWork->obj.klass + v7))->_1.this_arg.data);
        v13 = data_high > 3 || data_high == 1;
        if (!v13)
        {
          v15 = gfldTakaraWork;
          namespaze_high = HIDWORD((*(&v15->obj.klass + v7))->_1.namespaze);
          if ((namespaze_high - 1) < 2)
          {
            v19 = gfldTakaraWork;
            p_name = &(*(&v19->obj.klass + v7))->_1.name;
            {
            }
            modelRoot = dds3GetUnitHandleObjectBasic(p_name)->Model->modelRoot;
            if (sdfModelGetMarkPosUnity(modelRoot, 1))
            {
              SDF_VU0__STOREVECTOR(&p);
                goto LABEL_96;
LABEL_94:
            }
            else
            {
              v45 = gfldTakaraWork;
              v47 = *((*(&v45->obj.klass + v7))->_1.name + 16);
              {
              }
              if (op_Inequality(v47, 0, 0))
              {
                v49 = gfldTakaraWork;
                transform = get_transform(*((*(&v49->obj.klass + v7))->_1.name + 16), 0);
                localPosition = get_localPosition(transform);
                p.x = localPosition.x * 100.0;
                p.y = -80.0 - (localPosition.y * 100.0);
                p.z = localPosition.z * 100.0;
                p.w = 0.0;
              }
                goto LABEL_94;
            }
LABEL_96:
            v52 = gfldTakaraWork;
            pData = *&(*(&v52->obj.klass + v7))->_1.this_arg.bits;
            if (pData)
            {
              dds3EffectDelete(&pData);
              v55 = gfldTakaraWork;
              *&(*(&v55->obj.klass + v7))->_1.this_arg.bits = 0;
            }
            fldItemBoxTbl = fldHitData->_fldItemBoxTbl;
            v61 = gfldTakaraWork;
            v63 = _get_Item(
                    fldItemBoxTbl,
                    (*(&v61->obj.klass + v7))->_1.element_class)[1].klass;
            if ((v63 & 0xFFFFFFFE) == 2)
            {
              if (dds3EffectGetState(eFldTDmgEff))
              {
                v311 = eFldTDmgEff;
                x = p.x;
                v67 = p.y;
                v70 = p.z;
                w = p.w;
                v321.x = x;
                v321.y = v67;
                v321.z = v70;
                v321.w = w;
                dds3EffectSetPosition(&v311, v321);
                dds3EffectDraw(&v311);
              }
            }
            else
            {
              if (*(&gfldTakaraGtEff->obj.klass + v7))
              {
                v74 = gfldTakaraGtEff;
                v76 = p.x;
                v75 = p.y;
                v78 = p.z;
                v77 = p.w;
                else if (v6 >= LODWORD(v74->max_length))
                {
                  goto LABEL_143;
                }
                v322.x = v76;
                v322.y = v75;
                v322.z = v78;
                v322.w = v77;
                dds3EffectPartSetPosition((v74 + v7), v322, 0);
                v80 = gfldTakaraGtEff;
                dds3EffectPartDraw((v80 + v7), 0);
              }
            }
            goto LABEL_13;
          }
          if (!namespaze_high)
          {
            v28 = gfldTakaraWork;
            v30 = HIDWORD((*(&v28->obj.klass + v7))->_1.this_arg.data);
            if (v30 == 3 || v30 == 0)
            {
              v33 = gfldTakaraWork;
              if (*&(*(&v33->obj.klass + v7))->_1.this_arg.bits)
              {
                v36 = gfldTakaraWork;
                v38 = &(*(&v36->obj.klass + v7))->_1.name;
                {
                }
                v40 = dds3GetUnitHandleObjectBasic(v38)->Model->modelRoot;
                if (sdfModelGetMarkPosUnity(v40, 2))
                {
                  SDF_VU0__STOREVECTOR(&p);
                    goto LABEL_165;
LABEL_163:
                }
                else
                {
                  v83 = gfldTakaraWork;
                  v85 = *((*(&v83->obj.klass + v7))->_1.name + 16);
                  {
                  }
                  if (op_Inequality(v85, 0, 0))
                  {
                    v87 = gfldTakaraWork;
                    v89 = get_transform(*((*(&v87->obj.klass + v7))->_1.name + 16), 0);
                    v320 = get_localPosition(v89);
                    p.x = v320.x * 100.0;
                    p.y = -80.0 - (v320.y * 100.0);
                    p.z = v320.z * 100.0;
                    p.w = 0.0;
                  }
                    goto LABEL_163;
                }
LABEL_165:
                v90 = gfldTakaraWork;
                v93 = p.x;
                v92 = p.y;
                v313 = *&(*(&v90->obj.klass + v7))->_1.this_arg.bits;
                v95 = p.z;
                v94 = p.w;
                v323.x = v93;
                v323.y = v92;
                v323.z = v95;
                v323.w = v94;
                dds3EffectSetPosition(&v313, v323);
                dds3EffectDraw(&v313);
              }
            }
            v97 = gfldTakaraWork;
            v99 = &(*(&v97->obj.klass + v7))->_1.name;
            {
            }
            p_modelRoot = &dds3GetUnitHandleObjectBasic(v99)->Model->modelRoot;
            if (sdfModelGetMarkPos(p_modelRoot, 1))
              SDF_VU0__STOREVECTOR(&p);
            sub_854710(&dds3CameraEyePos, 0);
            v105 = v104;
            sub_854710(&p, 0);
            v107 = v105 - v106;
            sub_854710(&dds3CameraEyePos, 1u);
            v109 = v108;
            sub_854710(&p, 1u);
            v111 = v109 - v110;
            sub_854710(&dds3CameraEyePos, 2u);
            v113 = v112;
            sub_854710(&p, 2u);
            v116 = v113 - v115;
            v117 = sdfSqrt(((v107 * v107) + (v111 * v111)) + (v116 * v116), 0);
            sub_854930(&v316, 0);
            sub_854930(&v316, 1u);
            sub_854930(&v316, 2u);
            sub_854930(&v316, 3u);
            SDF_VU0__LOADVECTOR(v316);
            SDF_VU0__NORMALIZE();
            SDF_VU0__STOREVECTOR(&v315);
            sub_854710(&p, 0);
            sub_854710(&v315, 0);
            sub_854930(&p, 0);
            sub_854710(&p, 1u);
            sub_854710(&v315, 1u);
            sub_854930(&p, 1u);
            sub_854710(&p, 2u);
            sub_854710(&v315, 2u);
            sub_854930(&p, 2u);
            v119 = v1[4];
            *(v119 + 16) = 0;
            *(v1[4] + 18) = 0;
            *(v1[5] + 16) = 512;
            *(v1[6] + 16) = 512;
            *(v1[6] + 18) = 512;
            *(v1[7] + 16) = 0;
            *(v1[7] + 18) = 512;
            *(v1[8] + 16) = -1065353216;
            *(v1[8] + 20) = -1065353216;
            *(v1[9] + 16) = 1082130432;
            *(v1[9] + 20) = -1065353216;
            *(v1[10] + 16) = 1082130432;
            *(v1[10] + 20) = 1082130432;
            *(v1[11] + 16) = -1065353216;
            *(v1[11] + 20) = 1082130432;
            v1[12] = 2155905152LL;
            sub_854710(&p, 0);
            sub_854930((v1 + 2), 0);
            sub_854710(&p, 1u);
            sub_854930((v1 + 2), 1u);
            sub_854710(&p, 2u);
            sub_854930((v1 + 2), 2u);
            LOBYTE(v119) = 0;
            if (v117 < 500.0)
            {
LABEL_196:
                goto LABEL_202;
            }
            else
            {
              if (v117 > 3000.0)
              {
                LOBYTE(v119) = 0x80;
                goto LABEL_196;
              }
              v122 = (((v117 + -500.0) * 128.0) / 2500.0);
              if (v122 >= 128)
                v122 = 128;
              LODWORD(v119) = v122 & ~(v122 >> 31);
              {
LABEL_202:
                *(v1 + 24) = (v119 << 24) | 0x808080;
                rsetOtOfs(44);
                drawSprite3D(gfldTakaraLtTex, v1);
                goto LABEL_13;
              }
            }
            goto LABEL_202;
          }
        }
LABEL_13:
        ++v6;
        v7 += 8;
          goto LABEL_14;
      }
    }
  }
}

// 0x1483dd0
void fldNpcFree(void) {
  sdfTexHandle_t_o *fldIFTexHandle1;
  sdfTexHandle_t_o *fldIFTexHandle2;
  sdfTexHandle_t_o *fldIFTexHandle3;
  sdfTexHandle_t_o *fldIFTexHandle4;
  struct UnityEngine_Texture_array *fldMaga01TexHandle;
  s64 i;
  u64 v11;
  struct UnityEngine_GameObject_array *mhfldNpcFile;
  UnityEngine_Object_o *v14;
  struct UnityEngine_GameObject_array *v16;
  s64 v18;
  s32 v19;
  u64 v20;
  struct fldNpc_tag_array *fldNpc;
  struct fldNpc_tag_array *v24;
  struct fldNpc_tag_array *v26;
  u32 v28;
  Il2CppObject *eFldTDmgEff;
  Il2CppObject *eFldDmgEff;
  struct effHandle_t_array *eFldSibukiEff;
  struct effHandle_t_array *v35;
  struct effHandle_t_array *v37;
  Il2CppObject *v39;
  Il2CppObject *v40;
  Il2CppObject *v41;
  Il2CppObject *pData;

  pData = 0;
  v40 = 0;
  v41 = 0;
  v39 = 0;
  dds3EffectDistortionBlurDelete(&fldNpcBlurD);
  if (fldIFTexHandle1)
  {
    sdfTexFreeDelayed(fldIFTexHandle1);
    fldIFTexHandle1 = 0;
  }
  if (fldIFTexHandle2)
  {
    sdfTexFreeDelayed(fldIFTexHandle2);
    fldIFTexHandle2 = 0;
  }
  if (fldIFTexHandle3)
  {
    sdfTexFreeDelayed(fldIFTexHandle3);
    fldIFTexHandle3 = 0;
  }
  if (fldIFTexHandle4)
  {
    sdfTexFreeDelayed(fldIFTexHandle4);
    fldIFTexHandle4 = 0;
  }
  if (fldMaga01TexHandle)
  {
    else if (!LODWORD(fldMaga01TexHandle->max_length))
    {
      goto LABEL_57;
    }
    fldMaga01TexHandle->m_Items[0] = 0;
    fldMaga01TexHandle = 0;
  }
  for (i = 4; i != 68; ++i)
  {
    v11 = i - 4;
    v14 = *(&mhfldNpcFile->obj.klass + i);
    if (op_Inequality(v14, 0, 0))
    {
      v16 = mhfldNpcFile;
      *(&v16->obj.klass + i) = 0;
    }
  }
  v18 = 4;
  do
  {
    v20 = v18 - 4;
    if (*(*(&fldNpc->obj.klass + v18) + 72LL))
    {
      v24 = fldNpc;
      pData = *(*(&v24->obj.klass + v18) + 72LL);
      dds3EffectDelete(&pData);
      v26 = fldNpc;
      *(*(&v26->obj.klass + v18) + 72LL) = 0;
    }
    ++v18;
    v19 = (v28 >> 9) & 1;
  }
  while (v18 != 36);
  if (eFldTDmgEff)
  {
    else
    {
      v41 = eFldTDmgEff;
        goto LABEL_102;
    }
    dds3EffectDelete(&v41);
    eFldTDmgEff = 0;
  }
  if (eFldDmgEff)
  {
    else
    {
      v40 = eFldDmgEff;
        goto LABEL_115;
    }
    dds3EffectDelete(&v40);
    eFldDmgEff = 0;
  }
  else
  {
    if (!LODWORD(eFldSibukiEff->max_length))
      goto LABEL_122;
  }
  if (eFldSibukiEff->m_Items[0])
  {
    else
    {
      v35 = eFldSibukiEff;
      if (!LODWORD(v35->max_length))
        goto LABEL_127;
    }
    v39 = v35->m_Items[0];
    dds3EffectDelete(&v39);
    v37 = eFldSibukiEff;
    v37->m_Items[0] = 0;
  }
}

// 0x1495b40
void fldNpcHojiRefresh(void) {
  s64 v2;
  u64 v4;
  struct fldNpc_tag_array *fldNpc;
  struct fldGlobalWork_t_o *fldGb;
  s32 fieldID;
  s32 areaID;
  struct fldNpc_tag_array *v14;
  s32 v16;
  struct fldNpc_tag_array *v18;
  struct fldNpc_tag_array *v21;
  struct fldNpc_tag_array *v23;
  struct fldNpc_tag_array *v26;

  v2 = 4;
  v4 = 0;
  {
LABEL_6:
  }
  while (1)
  {
    if (v4 >= fldNpcNum)
      break;
    else
    {
      if (v4 >= LODWORD(fldNpc->max_length))
        goto LABEL_12;
    }
    if (*(*(&fldNpc->obj.klass + v2) + 100LL))
    {
      fieldID = fldGb->fieldID;
      areaID = fldGb->areaID;
      v14 = fldNpc;
      v16 = fldGbChkNpc(fieldID, areaID + 1, *(*(&v14->obj.klass + v2) + 100LL), 0);
      if (v16)
      {
        v18 = fldNpc;
        if (*(*(&v18->obj.klass + v2) + 48LL))
        {
          v21 = fldNpc;
          dds3ObjectBaseOnFlag((*(&v21->obj.klass + v2) + 48LL), 1u, 0, 0);
        }
      }
      else
      {
        v23 = fldNpc;
        if (*(*(&v23->obj.klass + v2) + 48LL))
        {
          v26 = fldNpc;
          dds3ObjectBaseOffFlag((*(&v26->obj.klass + v2) + 48LL), 1u, 0);
        }
      }
    }
    ++v2;
    v4 = v2 - 4;
      goto LABEL_6;
  }
}

// 0x1495e20
void fldNpcLightLoad(s32 field) {
  System_Char_array *v3;
  System_Char_array *v4;
  Il2CppObject *v6;
  u64 *v7;
  s64 *v8;
  System_String_o *v9;
  System_String_o *v10;
  u64 *v11;
  System_String_o *v13;
  bool IsDLCField;
  s64 *v15;
  System_String_o *v17;
  AssetBundleCtrl_o *asset_bc;
  System_Byte_array *FileByte;
  u64 v21;
  s64 v22;
  struct fldNpcLightTbl_tag_array *fldNpcLightTbl;
  u64 max_length_low;
  s64 v27;
  struct fldNpcLightTbl_tag_array *v29;
  s64 v31;
  struct fldNpcLightTbl_tag_array *v33;
  s64 v35;
  struct fldNpcLightTbl_tag_array *v37;
  s64 v39;
  struct fldNpcLightTbl_tag_array *v41;
  s64 v43;
  struct fldNpcLightTbl_tag_array *v45;
  s64 v47;
  struct fldNpcLightTbl_tag_array *v49;
  s64 v51;
  struct fldNpcLightTbl_tag_array *v53;
  s64 v55;
  s64 v56;
  s32 v58;
  System_String_o *pathstr;

  v3 = NewSpecific(char, 0x40u);
  CreateString_5280336(0, v3);
  v4 = NewSpecific(char, 0x20u);
  pathstr = CreateString_5280336(0, v4);
  if (field <= 99)
  {
    fldMakeFilePath(&pathstr, field, 1);
    if (field == 24 && evtBitCheck(79))
    {
      v58 = 24;
      v6 = pathstr;
      v7 = sub_8D3950(s32, &v58);
      v8 = &"{0}F{1:D3}b.NPL.bytes";
    }
    else
    {
      v58 = field;
      v6 = pathstr;
      v7 = sub_8D3950(s32, &v58);
      v8 = &"{0}F{1:D3}.NPL.bytes";
    }
    v9 = Format_5268592(*v8, v6, v7);
    v58 = field;
    v10 = v9;
    v11 = sub_8D3950(s32, &v58);
    v13 = Format("f{0:D3}", v11, 0);
    IsDLCField = IsDLCField(field);
    v15 = &"m";
    if (!IsDLCField)
      v15 = &"";
    v17 = Concat_5224608(v13, *v15);
    asset_bc = get_asset_bc();
    FileByte = LoadFileByte(asset_bc, v17, v10);
    v21 = 0;
    v22 = 32;
    {
LABEL_20:
    }
    while (1)
    {
      max_length_low = LODWORD(fldNpcLightTbl->max_length);
      if (v21 >= max_length_low)
        break;
      else if (v21 >= max_length_low)
      {
        goto LABEL_27;
      }
      v27 = *(&fldNpcLightTbl->obj.klass + v22);
      *(v27 + 16) = FileByte->m_Items[(v22 - 32)];
      v29 = fldNpcLightTbl;
      v31 = *(&v29->obj.klass + v22);
      *(v31 + 17) = FileByte->m_Items[(v22 - 31)];
      v33 = fldNpcLightTbl;
      v35 = *(&v33->obj.klass + v22);
      *(v35 + 18) = FileByte->m_Items[(v22 - 30)];
      v37 = fldNpcLightTbl;
      v39 = *(&v37->obj.klass + v22);
      *(v39 + 19) = FileByte->m_Items[(v22 - 29)];
      v41 = fldNpcLightTbl;
      v43 = *(&v41->obj.klass + v22);
      *(v43 + 20) = FileByte->m_Items[(v22 - 28)];
      v45 = fldNpcLightTbl;
      v47 = *(&v45->obj.klass + v22);
      *(v47 + 21) = FileByte->m_Items[(v22 - 27)];
      v49 = fldNpcLightTbl;
      v51 = *(&v49->obj.klass + v22);
      *(v51 + 22) = FileByte->m_Items[(v22 - 26)];
      v53 = fldNpcLightTbl;
      v55 = *(&v53->obj.klass + v22);
      v56 = (v22 - 25);
      ++v21;
      v22 += 8;
      *(v55 + 23) = FileByte->m_Items[v56];
        goto LABEL_20;
    }
  }
}

// 0x14853e0
void fldNpcLightSet(evtUnitHandle_t *hEveUnit) {
  u64 *v3;
  struct fldNpcLightTbl_tag_array *fldNpcLightTbl;
  s64 v8;
  u8 *v10;
  f32 v12;
  s32 v13;
  f32 v14;
  f32 v16;
  f32 v18;
  f32 v19;
  f32 v22;
  f32 v23;
  s32 v25;
  s32 v26;
  s32 v27;
  u8 v28;
  u32 v29;
  u32 v30;
  u32 v32;
  u32 v33;
  struct fldGlobalWork_t_o *fldGb;
  f32 v35;
  s32 v36;
  s32 v37;
  s32 v38;
  struct fldGlobalWork_t_o *v39;
  f32 v40;
  struct fldGlobalWork_t_o *v41;
  s32 areaID;
  f32 v43;
  struct fldGlobalWork_t_o *v44;
  s32 v45;
  s32 v46;
  f32 v47;
  s32 v48;
  s32 v49;
  struct fldGlobalWork_t_o *v53;
  s64 v58;
  f32 z;
  UnityEngine_Vector4_o v60;
  UnityEngine_Vector4_o v61;
  dds3Basic_t_o *pObjectBasic;
  evtUnitHandle_t_o *h;

  h = hEveUnit;
  *&v60.x = 0;
  *&v60.z = 0;
  *&v61.x = 0;
  *&v61.z = 0;
  v3 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v3);
  pObjectBasic = hEveUnit->Owner;
  dds3ObjectBaseGetModelHandle(&pObjectBasic);
  SDF_VU0__LOADVECTOR(pObjectBasic->poseset->rot);
  v8 = fldGb->areaID + 1LL;
  v10 = fldNpcLightTbl->m_Items[v8];
  v12 = EulerAngleAxisY();
  v13 = v10[23];
  v14 = -v12;
  if (v13 == 2)
  {
    v16 = -70.0;
      goto LABEL_25;
  }
  else if (v13 == 1)
  {
    v16 = -70.0;
      goto LABEL_25;
  }
  else if (v10[23])
  {
    if (v13 == 3)
    {
      v16 = 70.0;
        goto LABEL_25;
    }
    else
    {
      v16 = 70.0;
        goto LABEL_25;
    }
  }
  else
  {
    v16 = 70.0;
      goto LABEL_25;
  }
LABEL_25:
  v18 = OOYDEG(v14);
  v19 = v18 + v16;
  evtUnitLightOn(&h);
  dds3ObjectBaseOnFlag(&pObjectBasic, 0x100u, 0);
  v22 = OOYRAD(v19);
  sdfSin(v22);
  sub_854930(&v61, 0);
  sub_854930(&v61, 1u);
  v23 = OOYRAD(v19);
  sdfCos(v23);
  sub_854930(&v61, 2u);
  sub_854930(&v61, 3u);
  SDF_VU0__LOADVECTOR(v61);
  SDF_VU0__NORMALIZE();
  evtSetUnitLightDir(&h, 0);
  v25 = v10[16];
  v26 = v10[17];
  v27 = v10[18];
  v28 = v10[19];
  v29 = v10[20];
  v30 = v10[21];
  v32 = v25 | (v26 << 8) & 0xFF00FFFF | (v27 << 16) | 0x80000000;
  v33 = v28 | (v29 << 8) & 0xFF00FFFF | (v30 << 16) | 0x80000000;
  if (fldGb->fieldID == 37)
  {
    if (fldGb->areaID == 6)
    {
      v35 = v30 * 0.9;
      if ((v26 * 0.9) >= 255)
        v26 = 255;
      else
        v26 = (v26 * 0.9);
      if ((v27 * 0.9) >= 255)
        v27 = 255;
      else
        v27 = (v27 * 0.9);
      if ((v29 * 0.6) >= 255)
        v36 = 255;
      else
        v36 = (v29 * 0.6);
      v37 = v28 | (v36 << 8);
      v32 = v25 | (v26 << 8) | (v27 << 16) | 0x80000000;
      v38 = v35;
      if (v35 >= 255)
        v38 = 255;
      v33 = v37 | (v38 << 16) | 0x80000000;
    }
  }
  v39 = fldGb;
  if (v39->fieldID == 15)
  {
    if (v39->areaID == 4)
    {
      v40 = v26 * 0.7;
      if ((v25 * 0.7) >= 255)
        v25 = 255;
      else
        v25 = (v25 * 0.7);
      if (v40 >= 255)
        v26 = 255;
      else
        v26 = v40;
      if ((v27 * 0.7) >= 255)
        v27 = 255;
      else
        v27 = (v27 * 0.7);
      v32 = (v27 << 16) | (v26 << 8) | v25 | 0x80000000;
    }
  }
  v41 = fldGb;
  if (v41->fieldID == 23)
  {
    else
    {
      areaID = v41->areaID;
      if (!areaID)
        goto LABEL_90;
    }
    else if (areaID == 1)
    {
      goto LABEL_90;
    }
    if (areaID != 6)
      goto LABEL_100;
LABEL_90:
    v43 = v26 * 0.9;
    if ((v25 * 0.9) >= 255)
      v25 = 255;
    else
      v25 = (v25 * 0.9);
    if (v43 >= 255)
      v26 = 255;
    else
      v26 = v43;
    if ((v27 * 0.9) >= 255)
      v27 = 255;
    else
      v27 = (v27 * 0.9);
    v32 = (v27 << 16) | (v26 << 8) | v25 | 0x80000000;
  }
LABEL_100:
  v44 = fldGb;
  if (v44->fieldID != 27)
  {
LABEL_119:
      goto LABEL_124;
    goto LABEL_120;
  }
  v45 = v44->areaID;
  if (v45 < 0)
    goto LABEL_123;
LABEL_107:
  if (v45 > 4)
    goto LABEL_119;
  v46 = (v25 * 0.8);
  v47 = v26 * 0.8;
  if (v46 >= 255)
    v46 = 255;
  v48 = v47;
  v49 = (v27 * 0.8);
  if (v47 >= 255)
    v48 = 255;
  if (v49 >= 255)
    v49 = 255;
  v32 = (v49 << 16) | (v48 << 8) | v46 | 0x80000000;
  {
LABEL_120:
  }
LABEL_124:
  evtSetUnitLightAndAmbient(&h, 0, v32, v33);
  SDF_VU0__LOADVECTOR(v61);
  SDF_VU0__NORMALIZE();
  evtSetUnitLightDir(&h, 0);
  evtSetUnitLightAndAmbient(&h, 0, v32, v33);
  v53 = fldGb;
  if (v53->fieldID != 15)
    goto LABEL_133;
  if (v53->areaID != 2)
    goto LABEL_133;
LABEL_131:
  *&h->soften = 0;
LABEL_134:
  sub_854690(&v60.x, 0.0, 0.0, 0.0, 1.0);
  dds3GetPosPoseSet(&pObjectBasic);
  SDF_VU0__STOREVECTOR(&v60);
  v58 = *&v60.x;
  z = v60.z;
  fldNpcShadow_Add(&h, &pObjectBasic, 0, 0, *&v58, *(&v58 + 1), z, v19, 200.0);
}

// 0x1483570
void fldNpcLoad(void) {
  struct effHandle_t_o *v9;
  struct effHandle_t_array *eFldSibukiEff;
  Il2CppObject *v13;
  struct effHandle_t_array *v16;
  s64 *v17;
  s64 *v18;
  Il2CppObject *pFldItfFld;
  struct sdfTexHandle_t_o *v25;
  fld_Npc_c *v26;
  Il2CppObject *pFldItfWM;
  struct sdfTexHandle_t_o *v28;
  struct sdfTexHandle_t_o *v30;
  struct sdfTexHandle_t_o *v32;
  Il2CppObject *pFldItfFld2;
  struct UnityEngine_Texture_array *v34;
  struct UnityEngine_Texture_array *fldMaga01TexHandle;
  AssetBundleCtrl_o *asset_bc;
  s64 *FileObject;
  s64 *v41;
  s64 v42;
  s64 typeHierarchyDepth;
  char *v44;
  s64 *v45;
  s64 v47;
  s64 v48;
  char *v49;
  s64 *v50;
  u64 v53;
  s32 v54;
  struct UnityEngine_GameObject_array *mhfldNpcFile;
  struct System_Int32_array *gfldNpcSize;
  char *v59;
  u32 v60;
  u64 *v61;
  s64 v63;
  s64 v65;
  Il2CppObject *pData[2];
  char *v68;

  if (fldGb->fieldID <= 199)
  {
    pData[0] = 0;
    if (eFldTDmgEff)
    {
      pData[0] = eFldTDmgEff;
      dds3EffectDelete(pData);
      eFldTDmgEff = 0;
    }
    eFldTDmgEff = dds3EffectLoad(
                                                     &pFldTDmgEff,
                                                     0,
                                                     0,
                                                     0);
    if (fldGb->fieldID < 11)
    {
LABEL_52:
      if (fldGb->fieldID <= 9)
      {
        v28 = sdfTexSet(pFldItfWM);
        fldIFTexHandle1 = v28;
        v30 = sdfTexSet(pFldItfWM2);
        fldIFTexHandle3 = v30;
        v32 = sdfTexSet(pFldItfWM3);
        fldIFTexHandle4 = v32;
        if ((v26->_2.bitflags2 & 2) == 0)
          goto LABEL_72;
      }
      else
      {
        v25 = sdfTexSet(pFldItfFld);
        fldIFTexHandle1 = v25;
        fldIFTexHandle3 = 0;
        fldIFTexHandle4 = 0;
        if ((v26->_2.bitflags2 & 2) == 0)
          goto LABEL_72;
      }
LABEL_72:
      fldIFTexHandle2 = sdfTexSet(pFldItfFld2);
      v34 = NewSpecific(UnityEngine_Texture, 1u);
      fldMaga01TexHandle = v34;
      asset_bc = get_asset_bc();
      FileObject = LoadFileObject(asset_bc, "f_bin", "dds3data/fld/f/bin/f_maga01.png");
      v41 = FileObject;
      if (FileObject)
      {
        v42 = *FileObject;
        if (*(*FileObject + 288) < typeHierarchyDepth
          || *(*(v42 + 200) + 8 * typeHierarchyDepth - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v42 + 64), UnityEngine_Texture, pData);
          if ((pData[0] & 1) != 0)
            v44 = v68;
          else
            v44 = pData + 1;
          v45 = sub_8C4940(v44);
        }
        v47 = *v41;
        if (*(*v41 + 288) < v48 || *(*(v47 + 200) + 8 * v48 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v47 + 64), UnityEngine_Texture, pData);
          if ((pData[0] & 1) != 0)
            v49 = v68;
          else
            v49 = pData + 1;
          v50 = sub_8C4940(v49);
        }
      }
      fldMaga01TexHandle->m_Items[0] = v41;
      v53 = 0;
      do
      {
        mhfldNpcFile->m_Items[v53] = 0;
        v59 = gfldNpcSize + 4 * v53++;
        *(v59 + 8) = 0;
        v54 = (v60 >> 9) & 1;
      }
      while (v53 != 64);
      fldNpc01Basic = 0;
      gfldNpc01Id = -1;
      v61 = Allocate(dds3Effect_DistortionBlurParam_t);
      dds3Effect_DistortionBlurParam_t___ctor(v61);
      v61[2] = 0xF0000003CLL;
      v61[3] = 0x608080803D23D70ALL;
      *(v61 + 8) = 1;
      *(v61 + 36) = 0x3E4CCCCD00000000LL;
      v63 = *(v61[6] + 16);
      *(v63 + 32) = 0;
      v65 = *(v61[6] + 16);
      *(v65 + 36) = -48;
      v61[7] = 0x6000000048LL;
      fldNpcBlurD = dds3EffectDistortionBlurCreate(v61);
      return;
    }
    pData[0] = 0;
    if (eFldDmgEff)
    {
      pData[0] = eFldDmgEff;
      dds3EffectDelete(pData);
      eFldDmgEff = 0;
    }
    v9 = dds3EffectLoad(&pFldDmgEff, 0, 0, 0);
    eFldDmgEff = v9;
    gFldDmgEff = 0;
    if ((byte_3F5989E & 1) != 0)
    {
      pData[0] = 0;
      v13 = eFldSibukiEff->m_Items[0];
      if (v13)
        goto LABEL_40;
    }
    else
    {
      pData[0] = 0;
      v13 = eFldSibukiEff->m_Items[0];
      if (v13)
      {
LABEL_40:
        pData[0] = v13;
        dds3EffectDelete(pData);
        eFldSibukiEff->m_Items[0] = 0;
      }
    }
    v16 = eFldSibukiEff;
    v17 = dds3EffectLoad(&pFldSibukiEff, 0, 0, 0);
    v18 = v17;
    v16->m_Items[0] = v18;
    gFldSibukiEff = 0;
    goto LABEL_52;
  }
}

// 0x1482e20
void fldNpcLoad1st(void) {
  fld_Npc_c *v2;
  AssetBundleCtrl_o *asset_bc;
  System_String_o *v6;
  System_Byte_array *FileByte;
  AssetBundleCtrl_o *v9;
  System_String_o *v11;
  System_Byte_array *v12;
  AssetBundleCtrl_o *v19;
  System_String_o *v21;
  System_Byte_array *v22;
  AssetBundleCtrl_o *v29;
  System_String_o *v31;
  System_Byte_array *v32;
  AssetBundleCtrl_o *v34;
  UnityEngine_GameObject_o *Prefab_16624656;
  AssetBundleCtrl_o *v38;
  AssetBundleCtrl_o *v39;

  mhfldTakara01FileC = 0;
  mhfldTakara02FileC = 0;
  mhfldTakara03FileC = 0;
  if (pFldDmgEff)
  {
    if ((v2->_2.bitflags2 & 2) == 0)
      goto LABEL_21;
  }
  else
  {
    asset_bc = get_asset_bc();
    {
    }
    v6 = Concat_5224608(ParamDataAssetPath, "/D04.D3P.bytes");
    FileByte = LoadFileByte(asset_bc, "f_bin", v6);
    pFldDmgEff = &FileByte->obj;
    if ((v2->_2.bitflags2 & 2) == 0)
      goto LABEL_21;
  }
LABEL_21:
  if (!pFldNpcIcon)
  {
LABEL_26:
    v9 = get_asset_bc();
    {
    }
    v11 = Concat_5224608(ParamDataAssetPath, "/NPC01.D3P.bytes");
    v12 = LoadFileByte(v9, "f_bin", v11);
    pFldNpcIcon = &v12->obj;
    if ((v2->_2.bitflags2 & 2) == 0)
      goto LABEL_36;
    goto LABEL_23;
  }
LABEL_22:
  if ((v2->_2.bitflags2 & 2) == 0)
    goto LABEL_36;
LABEL_23:
LABEL_36:
  if (!pFldTakara1Pika)
    goto LABEL_41;
LABEL_37:
  if ((v2->_2.bitflags2 & 2) == 0)
    goto LABEL_51;
LABEL_38:
LABEL_51:
  if (!pFldSibukiEff)
  {
LABEL_56:
    v19 = get_asset_bc();
    {
    }
    v21 = Concat_5224608(ParamDataAssetPath, "/WATER.D3P.bytes");
    v22 = LoadFileByte(v19, "f_bin", v21);
    pFldSibukiEff = &v22->obj;
    if ((v2->_2.bitflags2 & 2) == 0)
      goto LABEL_66;
    goto LABEL_53;
  }
LABEL_52:
  if ((v2->_2.bitflags2 & 2) == 0)
    goto LABEL_66;
LABEL_53:
LABEL_66:
  if (!pFldTDmgEff)
    goto LABEL_71;
LABEL_67:
  if ((v2->_2.bitflags2 & 2) == 0)
    goto LABEL_81;
LABEL_68:
LABEL_81:
  if (gfldTakaraGtPtr)
    goto LABEL_92;
LABEL_82:
  v29 = get_asset_bc();
  {
  }
  v31 = Concat_5224608(ParamDataAssetPath, "/takara_get.PCF.bytes");
  v32 = LoadFileByte(v29, "f_bin", v31);
  gfldTakaraGtPtr = &v32->obj;
LABEL_92:
  v34 = get_asset_bc();
  Prefab_16624656 = LoadPrefab_16624656(v34, "common", "charactor/f/itembox", "itembox1");
  mhfldTakara01FileC = Prefab_16624656;
  v38 = get_asset_bc();
  mhfldTakara02FileC = LoadPrefab_16624656(v38, "common", "charactor/f/itembox", "itembox2");
  v39 = get_asset_bc();
  mhfldTakara03FileC = LoadPrefab_16624656(v39, "common", "charactor/f/itembox", "itembox3");
}

// 0x148ecf0
void fldNpcModelAllEnd(void) {
  ;
}

// 0x148eb50
void fldNpcModelEnd(s32 id) {
  u64 *v5;
  dds3Basic_t_o *fldNpc01Basic;
  s32 gfldNpc01Id;

  else
  {
    if (gfldNpc01Id != id)
      return;
  }
  if (fldNpc01Basic)
  {
    v5 = sub_8D3950(s32, &gfldNpc01Id);
    Format("/npc_data/npc_{0:D3}", v5, 0);
    DetachModel(fldNpc01Basic, 1);
    dds3DeleteUnitObjectBasic(&fldNpc01Basic);
    fldNpc01Basic = 0;
    gfldNpc01Id = -1;
    gFldNowTalk = 0;
  }
}

// 0x148e040
void fldNpcModelStart(s32 id, f32 x, f32 y, f32 z, sdfVector4_t rot) {
  f32 w;
  f32 v7;
  f32 v8;
  u64 *v10;
  struct fldNpc_tag_array *fldNpc;
  s32 tType;
  struct fldNpc_tag_array *v19;
  s32 tId2;
  u32 v22;
  s64 v24;
  s64 v25;
  u32 v26;
  f32 v27;
  f32 v28;
  f32 v29;
  f32 v30;
  dds3Basic_t_o *v32;
  struct System_String_array *npc_modelname;
  u32 max_length;
  s64 v39;
  Il2CppClass **v41;
  struct System_String_array *npc_pbname;
  System_String_o *v43;
  System_String_o *v45;
  struct System_String_array *npc_modelname2;
  u32 v48;
  Il2CppClass **v50;
  s64 v52;
  dds3Basic_t_o *fldNpc01Basic;
  System_String_o *v58;
  u64 *v60;
  dds3Basic_t_o *v62;
  f32 v63;
  UnityEngine_Vector4_o v64;
  UnityEngine_Vector4_o v65;
  UnityEngine_Vector4_o p;
  s64 v67;
  s64 v68;
  evtUnitHandle_t_o *h;
  UnityEngine_Vector4_o v70;
  UnityEngine_Vector4_o v71;
  UnityEngine_Vector4_o v72;

  w = rot.w;
  v7 = rot.z;
  v8 = rot.x;
  v63 = rot.y;
  v67 = 0;
  v68 = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v65.x = 0;
  *&v65.z = 0;
  h = 0;
  *&v64.x = 0;
  *&v64.z = 0;
  sub_854690(&v67, 0.0, 0.0, 0.0, 1.0);
  sub_854690(&p.x, 0.0, 0.0, 0.0, 1.0);
  sub_854690(&v65.x, 0.0, 1.0, 0.0, 1.0);
  v10 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v10);
  else
  {
    if (fldNpc01Basic)
      return;
  }
  gfldNpc01Id = id;
  sub_854930(&v67, 0);
  sub_854930(&v67, 1u);
  sub_854930(&v67, 2u);
  sub_854930(&v67, 3u);
  tType = fldNpc->m_Items[id]->tType;
  if (tType != 1)
  {
    if (tType)
    {
      tId2 = -1;
    }
    else
    {
      v19 = fldNpc;
      tId2 = v19->m_Items[id]->tId2;
      SDF_VU0__LOADVECTOR(v65);
      FromRotation(3.1416);
      v70.x = v8;
      v70.y = v63;
      v70.z = v7;
      v70.w = w;
      SDF_VU0__LOADVECTOR_B(v70);
      Mult();
      SDF_VU0__STOREVECTOR(&p);
    }
    v22 = dds3SerializeID();
    v24 = v67;
    v25 = v68;
    v26 = v22;
    v28 = p.x;
    v27 = p.y;
    v30 = p.z;
    v29 = p.w;
    *&v71.x = v24;
    *&v71.z = v25;
    v72.x = v28;
    v72.y = v27;
    v72.z = v30;
    v72.w = v29;
    v32 = dds3AddUnitObjectBasic(v26, v71, v72);
    fldNpc01Basic = v32;
    dds3UnitObjectBasicSetOt(&fldNpc01Basic, 8);
    dds3SetBasicName(&fldNpc01Basic, "NPC_UNIT");
    dds3ObjectBaseOnFlag(&fldNpc01Basic, 0x100u, 0);
    if ((tId2 & 0x80000000) == 0)
    {
      max_length = npc_modelname->max_length;
      if (tId2 < (max_length - 1))
      {
        v39 = tId2;
        v41 = &npc_modelname->obj.klass + tId2;
        v43 = v41[4];
        if (tId2 >= LODWORD(npc_pbname->max_length))
          goto LABEL_42;
        goto LABEL_43;
      }
      if (tId2 >= 35)
      {
        v48 = npc_modelname2->max_length;
        if (tId2 < (v48 + 35))
        {
          v39 = tId2 - 35LL;
          v50 = &npc_modelname2->obj.klass + v39;
          npc_pbname = npc_pbname2;
          v43 = v50[4];
          if (v39 >= LODWORD(npc_pbname->max_length))
          {
LABEL_42:
          }
LABEL_43:
          v45 = npc_pbname->m_Items[v39];
            goto LABEL_59;
LABEL_44:
LABEL_59:
          dds3ObjectBaseMakeUnit(&fldNpc01Basic, 0, 0);
          if (IsNullOrEmpty(v43))
          {
            if (IsNullOrEmpty(v45))
              goto LABEL_61;
          }
          else
          {
            v58 = Concat_5224608("npc_data/", v43);
            AttachModel_26590400(fldNpc01Basic, "common", v58);
            if (IsNullOrEmpty(v45))
            {
LABEL_61:
              {
LABEL_75:
                fldNpc01RGBA = 0;
                v60 = Allocate(evtUnitHandle_t);
                evtUnitHandle_t___ctor(v60);
                h = v60;
                *&v64.x = 0;
                *&v64.z = 0;
                v62 = fldNpc01Basic;
                h = evtGetUnitHandle2(v62);
                evtUnitLightOn(&h);
                evtSetUnitLightAndAmbient(&h, 0, 0x80666666, 0x80737373);
                sub_854930(&v64, 0);
                sub_854930(&v64, 1u);
                sub_854930(&v64, 2u);
                sub_854930(&v64, 3u);
                SDF_VU0__LOADVECTOR(v64);
                evtSetUnitLightDir(&h, 0);
                return;
              }
LABEL_62:
              goto LABEL_75;
            }
          }
          CreateNPCEffect(&fldNpc01Basic, v52, tId2, v45);
            goto LABEL_75;
          goto LABEL_62;
        }
      }
    }
    v45 = 0;
    v43 = 0;
      goto LABEL_59;
    goto LABEL_44;
  }
}

// 0x1485cf0
void fldNpcShadow_Add(evtUnitHandle_t **hEveUnit, dds3Basic_t **aBasic, s32 id1, s32 id2, f32 x, f32 y, f32 z, f32 dir, f32 size) {
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
    if (npcsdw_work_num > 14)
      return;
  }
  if (!npcsdw_work->m_Items[npcsdw_work_num])
  {
    v26 = npcsdw_work;
    v27 = Allocate(fld_Npc_fldNpcSdwWork_tag);
    _ctor(v27, 0);
    v26->m_Items[npcsdw_work_num] = v27;
      goto LABEL_24;
    goto LABEL_12;
  }
  {
LABEL_12:
  }
LABEL_24:
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
      if (Equals_5234480(name, "devil_0x73_1"))
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
  f32 v1;
  f32 Fovy;
  f32 v6;
  f32 v7;
  f32 v8;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  f32 v14;
  f32 v15;
  f32 v16;
  f32 v17;
  f32 v18;
  f32 v19;
  f32 v20;
  s32 v22;
  struct dds3Basic_t_o *player3;
  f32 v25;
  f32 v26;
  f32 v27;
  f32 v28;
  f32 v29;
  f32 v30;
  u64 *v31;
  evtUnitHandle_t_o *UnitHandleObjectBasic;
  f32 v35;
  f32 v36;
  f32 v37;
  f32 v40;
  f32 v41;
  fld_Npc_c *v42;
  s64 v43;
  s16 v44;
  u64 v45;
  s32 v46;
  signed s64 npcsdw_work_num;
  struct fld_Npc_fldNpcSdwWork_tag_array *npcsdw_work;
  sdfModelRootNode_t_o *v51;
  struct fld_Npc_fldNpcSdwWork_tag_array *v53;
  struct fld_Npc_fldNpcSdwWork_tag_array *v55;
  struct fld_Npc_fldNpcSdwWork_tag_array *v57;
  u64 v60;
  u64 v61;
  s32 v62;
  struct fld_Npc_fldNpcSdwWork_tag_array *v64;
  struct fld_Npc_fldNpcSdwWork_tag_array *v66;
  struct fld_Npc_fldNpcSdwWork_tag_array *v68;
  struct fld_Npc_fldNpcSdwWork_tag_array *v70;
  struct fld_Npc_fldNpcSdwWork_tag_array *v73;
  struct fld_Npc_fldNpcSdwWork_tag_array *v76;
  f32 v79;
  f32 v80;
  f32 v81;
  f32 v82;
  s64 v83;
  s64 v84;
  f32 v87;
  struct fld_Npc_fldNpcSdwWork_tag_array *v89;
  f32 v90;
  struct fld_Npc_fldNpcSdwWork_tag_array *v92;
  f32 v94;
  f32 v95;
  f32 v96;
  f32 v97;
  struct fld_Npc_fldNpcSdwWork_tag_array *v98;
  f32 v99;
  struct fld_Npc_fldNpcSdwWork_tag_array *v102;
  struct fld_Npc_fldNpcSdwWork_tag_array *v105;
  struct fld_Npc_fldNpcSdwWork_tag_array *v108;
  f32 v112;
  s64 v113;
  u64 v114;
  struct fld_Npc_fldNpcSdwWork_tag_array *v116;
  s64 v120;
  f32 v121;
  s32 v122;
  s64 v123;
  u64 v124;
  struct fld_Npc_fldNpcSdwWork_tag_array *v126;
  struct fld_Npc_fldNpcSdwWork_tag_array *v129;
  struct fld_Npc_fldNpcSdwWork_tag_array *v132;
  f32 len;
  u64 v135;
  s32 v136;
  struct fld_Npc_fldNpcSdwWork_tag_array *v138;
  struct fld_Npc_fldNpcSdwWork_tag_array *v141;
  struct fld_Npc_fldNpcSdwWork_tag_array *v144;
  struct fld_Npc_fldNpcSdwWork_tag_array *v146;
  u32 max_length;
  f32 v154;
  f32 v155;
  f32 v156;
  f32 v157;
  struct fld_Npc_fldNpcSdwWork_tag_array *v159;
  u32 v160;
  fld_Npc_fldNpcSdwWork_tag_o *v162;
  struct fld_Npc_fldNpcSdwWork_tag_array *v164;
  u32 v165;
  fld_Npc_fldNpcSdwWork_tag_o *v167;
  struct fld_Npc_fldNpcSdwWork_tag_array *v169;
  u32 v170;
  fld_Npc_fldNpcSdwWork_tag_o *v172;
  struct fld_Npc_fldNpcSdwWork_tag_array *v174;
  u32 v175;
  fld_Npc_fldNpcSdwWork_tag_o *v177;
  struct fld_Npc_fldNpcSdwWork_tag_array *v179;
  u32 v180;
  fld_Npc_fldNpcSdwWork_tag_o *v182;
  struct fld_Npc_fldNpcSdwWork_tag_array *v184;
  struct fld_Npc_fldNpcSdwWork_tag_array *v187;
  struct fld_Npc_fldNpcSdwWork_tag_array *v190;
  u32 v191;
  struct fld_Npc_fldNpcSdwWork_tag_array *v195;
  struct fld_Npc_fldNpcSdwWork_tag_array *v198;
  struct fld_Npc_fldNpcSdwWork_tag_array *v201;
  f32 v205;
  struct fld_Npc_fldNpcSdwWork_tag_array *v206;
  f32 dir;
  evtUnitHandle_t_o **p_hEveUnit;
  struct sdf3DLight_t_array *dds3DirLights;
  f32 v214;
  f32 v215;
  f32 v216;
  f32 v217;
  struct fld_Npc_fldNpcSdwWork_tag_array *v219;
  f32 v221;
  f32 v222;
  f32 v223;
  f32 v226;
  f32 v228;
  f32 v229;
  f32 v231;
  f32 v233;
  struct fldGlobalWork_t_o *fldGb;
  struct fldGlobalWork_t_o *v236;
  f32 v239;
  f32 npcsdw_nowalp;
  struct fld_Npc_fldNpcSdwWork_tag_array *v242;
  f32 v243;
  struct fld_Npc_fldNpcSdwWork_tag_array *v245;
  f32 v247;
  struct fld_Npc_fldNpcSdwWork_tag_array *v248;
  struct fldGlobalWork_t_o *v251;
  s32 areaID;
  struct fldGlobalWork_t_o *v254;
  struct fldGlobalWork_t_o *v257;
  f32 playerY;
  struct fld_Npc_fldNpcSdwWork_tag_array *v260;
  struct fld_Npc_fldNpcSdwWork_tag_array *v264;
  struct fld_Npc_fldNpcSdwWork_tag_array *v267;
  struct fldGlobalWork_t_o *v271;
  struct fldGlobalWork_t_o *v273;
  struct fldGlobalWork_t_o *v275;
  f32 v277;
  struct fld_Npc_fldNpcSdwWork_tag_array *v278;
  struct fldGlobalWork_t_o *v282;
  f32 v284;
  struct fld_Npc_fldNpcSdwWork_tag_array *v285;
  struct fldGlobalWork_t_o *v289;
  s32 fieldID;
  struct fldGlobalWork_t_o *v294;
  s32 v295;
  s32 v296;
  System_String_o *ScriptProcName;
  System_String_o *name;
  f32 v300;
  f32 v301;
  f32 v302;
  f32 v303;
  u64 v304[2];
  s64 v305;
  s64 v306;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v308;
  UnityEngine_Vector4_o tgtpos;
  UnityEngine_Vector4_o campos;
  dds3Basic_t_o *ActiveCameraSceneBasic;
  dds3Basic_t_o *pBasic;
  UnityEngine_Vector3_o v313;
  UnityEngine_Vector3_o v314;
  UnityEngine_Vector4_o v315;
  UnityEngine_Vector4_o v316;
  UnityEngine_Vector4_o v317;
  UnityEngine_Vector4_o v318;
  UnityEngine_Vector4_o v319;
  UnityEngine_Vector4_o v320;

  v1 = 0.0;
  ActiveCameraSceneBasic = 0;
  pBasic = 0;
  *&campos.x = 0;
  *&campos.z = 0;
  *&tgtpos.x = 0;
  *&tgtpos.z = 0;
  *&v308.x = 0;
  *&v308.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  v305 = 0;
  v306 = 0;
  v304[0] = 0;
  v304[1] = 0;
  sub_854690(v304, 0.0, 0.0, 0.0, 1.0);
  pBasic = dds3GetActiveScene();
  ActiveCameraSceneBasic = 0;
  campos = get_zero();
  Fovy = 0.7;
  tgtpos = get_zero();
  if (pBasic)
  {
    v6 = 0.0;
    v7 = 0.0;
    v8 = 0.0;
    ActiveCameraSceneBasic = dds3GetActiveCameraSceneBasic(&pBasic);
    if (ActiveCameraSceneBasic)
    {
      dds3CameraObjectBasicGetTgtCam(&ActiveCameraSceneBasic, &tgtpos, &campos);
      x = campos.x;
      y = campos.y;
      z = campos.z;
      w = campos.w;
      v15 = tgtpos.x;
      v14 = tgtpos.y;
      v17 = tgtpos.z;
      v16 = tgtpos.w;
      v315.x = x;
      v315.y = y;
      v315.z = z;
      v315.w = w;
      v319.x = v15;
      v319.y = v14;
      v319.z = v17;
      v319.w = v16;
      v308 = op_Subtraction(v315, v319);
      v1 = sub_855290(&v308.x, 0);
      v6 = v18;
      v7 = v19;
      v8 = v20;
      Fovy = dds3CameraObjectBasicGetFovy(&ActiveCameraSceneBasic);
    }
  }
  else
  {
    v6 = 0.0;
    v7 = 0.0;
    v8 = 0.0;
  }
  {
    else
    {
      if (!player3)
        goto LABEL_41;
    }
LABEL_21:
    sub_854710(&player3->poseset->pos, 0);
    v26 = v25;
    sub_854710(&player3->poseset->pos, 1u);
    v28 = v27;
    sub_854710(&player3->poseset->pos, 2u);
    v30 = v29;
    v31 = Allocate(evtUnitHandle_t);
    evtUnitHandle_t___ctor(v31);
    UnitHandleObjectBasic = dds3GetUnitHandleObjectBasic(&player3);
    if (UnitHandleObjectBasic)
    {
      v35 = UnitHandleObjectBasic->NowLightDir.x;
      v36 = UnitHandleObjectBasic->NowLightDir.z;
      v37 = sdfSqrt((v35 * v35) + (v36 * v36), 0);
      if (sdfFabs(v37) <= 0.001)
      {
        v41 = 0.0;
      }
      else
      {
        v40 = sdfAtan2(v35, v36);
        v41 = OOYDEG(v40);
      }
      PShadow2_CamX = (v26 - (v35 * 40.0)) / 100.0;
      PShadow2_CamY = (v28 + -200.0) / -100.0;
      PShadow2_CamZ = (v30 - (v36 * 40.0)) / 100.0;
      PShadow2_RotX = 70.0;
      PShadow2_RotY = v41;
      PShadow2_CamSize = 1.2;
      PShadow2_Alp = 0.2;
      PShadow2_OnOff = 1.0;
    }
    return;
  }
  v22 = 0;
  if (player3)
    goto LABEL_21;
LABEL_41:
  if (fldGb->fieldID < 11 || !pBasic || !ActiveCameraSceneBasic)
    goto LABEL_172;
  if (!npcsdw_work_num)
    goto LABEL_172;
  v301 = v8;
  v302 = v7;
  v303 = v6;
  v43 = 4;
  v44 = *&v42->_2.bitflags1;
  v45 = 0;
  if ((v44 & 0x200) != 0)
    goto LABEL_73;
  while (1)
  {
    v46 = 0;
    if (v45 >= npcsdw_work_num)
      break;
    while (1)
    {
      else
      {
        if (v45 >= LODWORD(npcsdw_work->max_length))
          goto LABEL_58;
      }
      v51 = *(*(*(*(&npcsdw_work->obj.klass + v43) + 16LL) + 176LL) + 64LL);
      if (sdfModelGetMarkPosUnity(v51, 0))
      {
        sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
        SDF_VU0__STOREVECTOR(&p);
        v53 = npcsdw_work;
        *(*(&v53->obj.klass + v43) + 40LL) = p.x;
        v55 = npcsdw_work;
        *(*(&v55->obj.klass + v43) + 44LL) = p.y;
        v57 = npcsdw_work;
        *(*(&v57->obj.klass + v43) + 48LL) = p.z;
      }
      ++v43;
      v45 = v43 - 4;
      if ((v44 & 0x200) == 0)
        break;
LABEL_73:
      v46 = v44 & 0x200;
      if (v45 >= npcsdw_work_num)
        goto LABEL_86;
    }
  }
LABEL_86:
  if (npcsdw_work_num == 1)
  {
    LODWORD(v60) = 0;
LABEL_91:
      goto LABEL_92;
    goto LABEL_331;
  }
  v300 = Fovy + -0.03;
  v61 = 0;
  v62 = 0;
  if ((v42->_2.bitflags2 & 2) == 0)
    goto LABEL_99;
LABEL_97:
LABEL_99:
  while (1)
  {
    if (v61 >= npcsdw_work_num)
      break;
    else
    {
      v64 = npcsdw_work;
      if (v61 >= LODWORD(v64->max_length))
        goto LABEL_103;
    }
    v64->m_Items[v61]->lookIn = 0;
    v66 = npcsdw_work;
    v66->m_Items[v61]->RangeIn = 0;
    v68 = npcsdw_work;
    v68->m_Items[v61]->len = 99999.0;
    v70 = npcsdw_work;
    if (v70->m_Items[v61]->unitBasic)
    {
      v73 = npcsdw_work;
      if (!dds3ObjectBaseCheckFlag(&v73->m_Items[v61]->unitBasic, 1u))
      {
        v76 = npcsdw_work;
        sub_854690(&v305, v76->m_Items[v61]->x, npcsdw_work->m_Items[v61]->y, npcsdw_work->m_Items[v61]->z, 1.0);
        v80 = campos.x;
        v79 = campos.y;
        v82 = campos.z;
        v81 = campos.w;
        v83 = v305;
        v84 = v306;
        v316.x = v80;
        v316.y = v79;
        v316.z = v82;
        v316.w = v81;
        *&v320.x = v83;
        *&v320.z = v84;
        v308 = op_Subtraction(v316, v320);
        v317.x = sub_855290(&v308.x, 0);
        v313 = op_Implicit_8738992(v317);
        v318.w = v301;
        v318.z = v302;
        v318.y = v303;
        v318.x = v1;
        v314 = op_Implicit_8738992(v318);
        v87 = Dot(v313, v314);
        v89 = npcsdw_work;
        v90 = v87;
        v89->m_Items[v61]->dot = v87;
        v92 = npcsdw_work;
        v94 = campos.x - v92->m_Items[v61]->x;
        v95 = campos.y - v92->m_Items[v61]->y;
        v96 = campos.z - v92->m_Items[v61]->z;
        v97 = sdfSqrt(((v94 * v94) + (v95 * v95)) + (v96 * v96), 0);
        v98 = npcsdw_work;
        v99 = v97;
        v98->m_Items[v61]->len = v97;
        if (v90 >= v300)
        {
          v102 = npcsdw_work;
          v102->m_Items[v61]->lookIn = 1;
          if (v99 < 1500.0)
          {
            v105 = npcsdw_work;
            ++v62;
            v105->m_Items[v61]->RangeIn = 1;
          }
        }
      }
    }
    ++v61;
      goto LABEL_97;
  }
  if (!v62)
  {
    v112 = 99999.0;
    LODWORD(v60) = -1;
    v113 = 4;
    v114 = 0;
    if ((v42->_2.bitflags2 & 2) == 0)
      goto LABEL_182;
LABEL_180:
LABEL_182:
    while (1)
    {
      if (v114 >= npcsdw_work_num)
        break;
      v116 = npcsdw_work;
      if (*(*(&v116->obj.klass + v113) + 64LL) < v112)
      {
        v60 = npcsdw_work;
        v120 = *(v60 + 8 * v113);
        LODWORD(v60) = v113 - 4;
        v112 = *(v120 + 64);
      }
      v114 = ++v113 - 4;
        goto LABEL_180;
    }
LABEL_329:
    if (v60 != -1)
    {
        goto LABEL_331;
      goto LABEL_92;
    }
      goto LABEL_173;
    goto LABEL_175;
  }
  if (v62 == 1)
  {
    v60 = 0;
    if ((v42->_2.bitflags2 & 2) == 0)
      goto LABEL_160;
LABEL_158:
LABEL_160:
    while (1)
    {
      if (v60 >= npcsdw_work_num)
        break;
      v108 = npcsdw_work;
      if (v108->m_Items[v60]->RangeIn)
      {
        goto LABEL_91;
      }
      ++v60;
        goto LABEL_158;
    }
LABEL_172:
    if ((v42->_2.bitflags2 & 2) != 0)
    {
LABEL_173:
    }
LABEL_175:
    npcsdw_nowidx = 0;
    npcsdw_nowalp = 1.0;
    return;
  }
  v121 = 99999.0;
  v122 = -1;
  v123 = 4;
  v124 = 0;
  if ((v42->_2.bitflags2 & 2) == 0)
    goto LABEL_200;
LABEL_198:
LABEL_200:
  while (1)
  {
    if (v124 >= npcsdw_work_num)
      break;
    v126 = npcsdw_work;
    if (*(*(&v126->obj.klass + v123) + 61LL))
    {
      v129 = npcsdw_work;
      if (*(*(&v129->obj.klass + v123) + 64LL) < v121)
      {
        v132 = npcsdw_work;
        v121 = *(*(&v132->obj.klass + v123) + 64LL);
        v122 = v123 - 4;
      }
    }
    v124 = ++v123 - 4;
      goto LABEL_198;
  }
  len = 99999.0;
  v135 = 0;
  v136 = -1;
  if ((v42->_2.bitflags2 & 2) == 0)
    goto LABEL_224;
LABEL_222:
LABEL_224:
  while (1)
  {
    if (v135 >= npcsdw_work_num)
      break;
    if (v122 != v135)
    {
      v138 = npcsdw_work;
      if (v138->m_Items[v135]->RangeIn)
      {
        v141 = npcsdw_work;
        if (v141->m_Items[v135]->len < len)
        {
          v144 = npcsdw_work;
          len = v144->m_Items[v135]->len;
          v136 = v135;
        }
      }
    }
    ++v135;
      goto LABEL_222;
  }
  v146 = npcsdw_work;
  max_length = v146->max_length;
  v154 = v146->m_Items[v122]->x - v146->m_Items[v136]->x;
  v155 = v146->m_Items[v122]->y - v146->m_Items[v136]->y;
  v156 = v146->m_Items[v122]->z - v146->m_Items[v136]->z;
  v157 = sdfSqrt(((v154 * v154) + (v155 * v155)) + (v156 * v156), 0);
  if (v157 >= 400.0)
  {
    v184 = npcsdw_work;
    LODWORD(v60) = v122;
    if (v184->m_Items[v136]->dot >= 0.9)
    {
      v187 = npcsdw_work;
      LODWORD(v60) = v122;
      if (v187->m_Items[v122]->dot <= 0.82)
      {
        v190 = npcsdw_work;
        v191 = v190->max_length;
        LODWORD(v60) = v122;
        if ((v190->m_Items[v136]->y - v190->m_Items[v122]->y) > -200.0)
        {
          v195 = npcsdw_work;
          if (v195->m_Items[v136]->bSkip)
            LODWORD(v60) = v122;
          else
            LODWORD(v60) = v136;
        }
      }
    }
    v198 = npcsdw_work;
    if (v198->m_Items[v122]->dot >= 0.9)
    {
      v201 = npcsdw_work;
      if (!v201->m_Items[v122]->bSkip)
        LODWORD(v60) = v122;
    }
    goto LABEL_329;
  }
  v159 = npcsdw_work;
  v160 = v159->max_length;
  v162 = v159->m_Items[15];
  v162->x = npcsdw_work->m_Items[v122]->x + (v154 * -0.5);
  v164 = npcsdw_work;
  v165 = v164->max_length;
  v167 = v164->m_Items[15];
  v167->y = npcsdw_work->m_Items[v122]->y + (v155 * -0.5);
  v169 = npcsdw_work;
  v170 = v169->max_length;
  v172 = v169->m_Items[15];
  v172->z = npcsdw_work->m_Items[v122]->z + (v156 * -0.5);
  v174 = npcsdw_work;
  v175 = v174->max_length;
  v177 = v174->m_Items[15];
  v177->dir = npcsdw_work->m_Items[v122]->dir;
  v179 = npcsdw_work;
  v180 = v179->max_length;
  v182 = v179->m_Items[15];
  LODWORD(v60) = 15;
  v182->hEveUnit = npcsdw_work->m_Items[v122]->hEveUnit;
  {
LABEL_92:
  }
LABEL_331:
  if (npcsdw_nowidx != v60)
  {
    npcsdw_nowidx = v60;
    v205 = 0.1;
    goto LABEL_343;
  }
  npcsdw_nowalp = npcsdw_nowalp + 0.1;
  if (npcsdw_nowalp > 1.0)
  {
    v205 = 1.0;
LABEL_343:
    npcsdw_nowalp = v205;
  }
  v206 = npcsdw_work;
  dir = v206->m_Items[v60]->dir;
  p_hEveUnit = &v206->m_Items[v60]->hEveUnit;
  if (ChkUseSceneLight(p_hEveUnit))
  {
    v214 = dds3DirLights->m_Items[0]->v.x;
    v215 = dds3DirLights->m_Items[0]->v.z;
    v216 = v214;
    v217 = v215;
LABEL_375:
    v226 = sdfAtan2(v216, v217);
    dir = OOYDEG(v226);
    goto LABEL_379;
  }
  v219 = npcsdw_work;
  v221 = v219->m_Items[v60]->hEveUnit->NowLightDir.x;
  v222 = npcsdw_work->m_Items[v60]->hEveUnit->NowLightDir.z;
  v223 = sdfSqrt((v221 * v221) + (v222 * v222), 0);
  if (sdfFabs(v223) > 0.001)
  {
    v216 = v221;
    v217 = v222;
    goto LABEL_375;
  }
LABEL_379:
  v228 = OOYRAD(dir);
  v229 = sdfSin(v228);
  v231 = sdfCos(v228);
  v233 = v231;
  if (fldGb->fieldID == 24)
  {
    if (fldGb->areaID == 26)
    {
      PShadow2_CamSize = 3.5;
      PShadow2_Alp = 0.2;
      PShadow2_CamX = -32.0;
      PShadow2_CamY = 3.5;
      PShadow2_CamZ = 34.5;
      PShadow2_RotX = 70.0;
      PShadow2_RotY = 40.0;
      return;
    }
  }
  v236 = fldGb;
  if (v236->fieldID == 15)
  {
    if (v236->areaID == 1)
    {
      dir = 0.0;
      PShadow2_CamSize = 3.0;
    }
  }
  if (v60 == 15)
  {
    v239 = 2.5;
      goto LABEL_415;
  }
  else
  {
    v239 = 2.0;
      goto LABEL_415;
  }
LABEL_415:
  PShadow2_CamSize = v239;
  PShadow2_Alp = npcsdw_nowalp * 0.2;
  v242 = npcsdw_work;
  v243 = v229 * 60.0;
  PShadow2_CamX = (v242->m_Items[v60]->x - v243) / 100.0;
  v245 = npcsdw_work;
  v247 = v233 * 60.0;
  PShadow2_CamY = (v245->m_Items[v60]->y + -300.0) / -100.0;
  v248 = npcsdw_work;
  PShadow2_CamZ = (v248->m_Items[v60]->z - v247) / 100.0;
  PShadow2_RotX = 70.0;
  PShadow2_RotY = dir;
  v251 = fldGb;
  if (v251->fieldID == 20)
  {
    areaID = v251->areaID;
    if (!areaID)
      goto LABEL_447;
    if (areaID == 1)
      goto LABEL_447;
    if (areaID == 13)
      goto LABEL_447;
    if (areaID == 24)
    {
LABEL_447:
      PShadow2_Alp = PShadow2_Alp * 0.6;
    }
  }
  v254 = fldGb;
  if (v254->fieldID == 25)
  {
    if (v254->areaID == 4 && evtBitCheck(1433) && evtBitCheck(1438))
    {
      PShadow2_CamX = -7.0;
      PShadow2_CamY = 3.4;
      PShadow2_CamZ = 18.0;
      PShadow2_RotX = 70.0;
      PShadow2_RotY = 215.0;
      PShadow2_CamSize = 4.0;
      PShadow2_Alp = 0.2;
    }
  }
  v257 = fldGb;
  if (v257->fieldID != 35)
    goto LABEL_508;
  if (v257->areaID != 4)
    goto LABEL_508;
  playerY = v257->playerY;
  v260 = npcsdw_work;
  if ((playerY - v260->m_Items[v60]->y) >= -300.0)
  {
    PShadow2_Alp = PShadow2_Alp + PShadow2_Alp;
      goto LABEL_495;
  }
  else
  {
    PShadow2_Alp = 0.0;
      goto LABEL_495;
  }
LABEL_495:
  v264 = npcsdw_work;
  if (v264->m_Items[v60]->unitBasic)
  {
    v267 = npcsdw_work;
    if (op_Equality(v267->m_Items[v60]->unitBasic->name, "npc_mane_d_0", 0))
    {
      PShadow2_RotX = 60.0;
      PShadow2_RotY = 126.0;
      PShadow2_Alp = 0.2;
    }
  }
LABEL_508:
  v271 = fldGb;
  if (v271->fieldID == 32)
  {
    if (v271->areaID == 1)
    {
      if (v271->playerY < -4000.0)
      {
        PShadow2_Alp = 0.0;
      }
    }
  }
  v273 = fldGb;
  if (v273->fieldID == 32)
  {
    if (v273->areaID == 10)
    {
      if (v273->playerY < -4000.0)
      {
        PShadow2_Alp = 0.0;
      }
    }
  }
  v275 = fldGb;
  if (v275->fieldID == 32)
  {
    if (v275->areaID == 17)
    {
      v277 = v275->playerY;
      v278 = npcsdw_work;
      if ((v277 - v278->m_Items[v60]->y) > 500.0)
      {
        PShadow2_Alp = 0.0;
      }
    }
  }
  v282 = fldGb;
  if (v282->fieldID == 35)
  {
    if (v282->areaID == 7)
    {
      v284 = v282->playerY;
      v285 = npcsdw_work;
      if ((v284 - v285->m_Items[v60]->y) < -1000.0)
      {
        PShadow2_Alp = 0.0;
      }
    }
  }
  v289 = fldGb;
  if (v289->fieldID == 37)
  {
    if (v289->areaID == 22)
    {
      PShadow2_RotY = 260.0;
    }
  }
  fieldID = fldGb->fieldID;
  if (fieldID >= 41)
  {
    if (fieldID <= 45)
    {
      PShadow2_Alp = PShadow2_Alp + PShadow2_Alp;
    }
  }
  if (ActiveCameraSceneBasic)
  {
    v294 = fldGb;
    v295 = v294->fieldID;
    v296 = v294->areaID;
    ScriptProcName = dds3GetScriptProcName();
    name = ActiveCameraSceneBasic->name;
    fldEventUpdateEx_Unity(v295, v296 + 1, ScriptProcName, name);
  }
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
    if (npcsdw_work->m_Items[v3])
    {
        goto LABEL_22;
LABEL_11:
      goto LABEL_22;
    }
    v9 = npcsdw_work;
    v10 = Allocate(fld_Npc_fldNpcSdwWork_tag);
    _ctor(v10, 0);
    *&v9[2 * v3 + 8] = v10;
      goto LABEL_11;
LABEL_22:
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
  u64 v3;
  fld_Npc_c *v4;
  struct fld_Npc_fldNpcSdwWork_tag_array *npcsdw_work;
  u64 v8;
  u32 v9;
  struct fld_Npc_fldNpcSdwWork_tag_array *v12;
  il2cpp_array_size_t max_length;
  struct fld_Npc_fldNpcSdwWork_tag_array *v14;
  fld_Npc_fldNpcSdwWork_tag_o *v15;
  struct fld_Npc_fldNpcSdwWork_tag_array *v18;
  il2cpp_array_size_t v19;
  fld_Npc_fldNpcSdwWork_tag_o *v20;
  struct fld_Npc_fldNpcSdwWork_tag_array *v23;
  il2cpp_array_size_t v24;
  fld_Npc_fldNpcSdwWork_tag_o *v25;
  struct fld_Npc_fldNpcSdwWork_tag_array *v28;
  il2cpp_array_size_t v29;
  fld_Npc_fldNpcSdwWork_tag_o *v30;
  struct fld_Npc_fldNpcSdwWork_tag_array *v33;
  il2cpp_array_size_t v34;
  fld_Npc_fldNpcSdwWork_tag_o *v35;
  struct fld_Npc_fldNpcSdwWork_tag_array *v38;
  il2cpp_array_size_t v39;
  fld_Npc_fldNpcSdwWork_tag_o *v40;
  struct fld_Npc_fldNpcSdwWork_tag_array *v43;
  il2cpp_array_size_t v44;
  fld_Npc_fldNpcSdwWork_tag_o *v45;
  struct fld_Npc_fldNpcSdwWork_tag_array *v48;
  il2cpp_array_size_t v49;
  fld_Npc_fldNpcSdwWork_tag_o *v50;
  struct fld_Npc_fldNpcSdwWork_tag_array *v53;
  il2cpp_array_size_t v54;
  fld_Npc_fldNpcSdwWork_tag_o *v55;
  struct fld_Npc_fldNpcSdwWork_tag_array *v58;
  il2cpp_array_size_t v59;
  fld_Npc_fldNpcSdwWork_tag_o *v60;
  struct fld_Npc_fldNpcSdwWork_tag_array *v63;
  il2cpp_array_size_t v64;
  fld_Npc_fldNpcSdwWork_tag_o *v65;
  struct fld_Npc_fldNpcSdwWork_tag_array *v68;
  il2cpp_array_size_t v69;
  fld_Npc_fldNpcSdwWork_tag_o *v70;
  struct fld_Npc_fldNpcSdwWork_tag_array *v73;
  il2cpp_array_size_t v74;
  fld_Npc_fldNpcSdwWork_tag_o *v75;
  struct fld_Npc_fldNpcSdwWork_tag_array *v78;
  fld_Npc_fldNpcSdwWork_tag_o *v79;

  v3 = 0;
  {
LABEL_6:
    goto LABEL_8;
  }
  while (1)
  {
LABEL_8:
    if (v3 >= npcsdw_work_num)
    {
      v3 = 0xFFFFFFFFLL;
      v8 = 0;
      v9 = 0;
      if ((v4->_2.bitflags2 & 2) == 0)
        goto LABEL_32;
      goto LABEL_30;
    }
    else
    {
      if (v3 >= LODWORD(npcsdw_work->max_length))
        goto LABEL_12;
    }
    if (npcsdw_work->m_Items[v3]->unitBasic == *aBasic)
      break;
    ++v3;
      goto LABEL_6;
  }
  if (npcsdw_nowidx == v3)
  {
    npcsdw_nowidx = 0;
    npcsdw_nowalp = 1.0;
  }
  v8 = 0;
  v9 = 0;
  if ((v4->_2.bitflags2 & 2) != 0)
  {
LABEL_30:
  }
LABEL_32:
  while (1)
  {
    if (v8 >= npcsdw_work_num)
      break;
    if (v3 != v8)
    {
      v12 = npcsdw_work;
      max_length = v12->max_length;
      v14 = v12;
      v15 = v12->m_Items[v9];
      v15->hEveUnit = v14->m_Items[v8]->hEveUnit;
      v18 = npcsdw_work;
      v19 = v18->max_length;
      v20 = v18->m_Items[v9];
      v20->unitBasic = npcsdw_work->m_Items[v8]->unitBasic;
      v23 = npcsdw_work;
      v24 = v23->max_length;
      v25 = v23->m_Items[v9];
      v25->id1 = npcsdw_work->m_Items[v8]->id1;
      v28 = npcsdw_work;
      v29 = v28->max_length;
      v30 = v28->m_Items[v9];
      v30->id2 = npcsdw_work->m_Items[v8]->id2;
      v33 = npcsdw_work;
      v34 = v33->max_length;
      v35 = v33->m_Items[v9];
      v35->x = npcsdw_work->m_Items[v8]->x;
      v38 = npcsdw_work;
      v39 = v38->max_length;
      v40 = v38->m_Items[v9];
      v40->y = npcsdw_work->m_Items[v8]->y;
      v43 = npcsdw_work;
      v44 = v43->max_length;
      v45 = v43->m_Items[v9];
      v45->z = npcsdw_work->m_Items[v8]->z;
      v48 = npcsdw_work;
      v49 = v48->max_length;
      v50 = v48->m_Items[v9];
      v50->dir = npcsdw_work->m_Items[v8]->dir;
      v53 = npcsdw_work;
      v54 = v53->max_length;
      v55 = v53->m_Items[v9];
      v55->size = npcsdw_work->m_Items[v8]->size;
      v58 = npcsdw_work;
      v59 = v58->max_length;
      v60 = v58->m_Items[v9];
      v60->lookIn = npcsdw_work->m_Items[v8]->lookIn;
      v63 = npcsdw_work;
      v64 = v63->max_length;
      v65 = v63->m_Items[v9];
      v65->RangeIn = npcsdw_work->m_Items[v8]->RangeIn;
      v68 = npcsdw_work;
      v69 = v68->max_length;
      v70 = v68->m_Items[v9];
      v70->len = npcsdw_work->m_Items[v8]->len;
      v73 = npcsdw_work;
      v74 = v73->max_length;
      v75 = v73->m_Items[v9];
      v75->dot = npcsdw_work->m_Items[v8]->dot;
      v78 = npcsdw_work;
      v79 = v78->m_Items[v9];
      ++v9;
      v79->bSkip = v78->m_Items[v8]->bSkip;
    }
    ++v8;
    if ((v4->_2.bitflags2 & 2) != 0)
      goto LABEL_30;
  }
  npcsdw_work_num = v9;
}

// 0x14963a0
void fldNplLoadFromMem(void *data) {
  ;
}

// 0x148cba0
void fldSibukiStart(f32 x, f32 y, f32 z) {
  struct effHandle_t_array *eFldSibukiEff;
  effHandle_t_o *v7;
  struct effHandle_t_array *v8;
  Il2CppObject *pData;
  UnityEngine_Vector4_o v12;

  *&v12.x = 0;
  *&v12.z = 0;
  pData = 0;
  sub_854690(&v12.x, 0.0, 0.0, 0.0, 1.0);
  sub_854930(&v12, 0);
  sub_854930(&v12, 1u);
  sub_854930(&v12, 2u);
  pData = eFldSibukiEff->m_Items[0];
  v7 = eFldSibukiEff->m_Items[0];
  dds3EffectReset(v7);
  dds3EffectSetPosition(&pData, v12);
  v8 = eFldSibukiEff;
  dds3EffectSetLoop(v8->m_Items, 0);
  gFldSibukiEff = 1;
}

// 0x1482cf0
void fldTDmgStart(f32 x, f32 y, f32 z) {
  Il2CppObject *eFldTDmgEff;
  Il2CppObject *pData;
  UnityEngine_Vector4_o v8;

  *&v8.x = 0;
  *&v8.z = 0;
  pData = 0;
  sub_854690(&v8.x, 0.0, 0.0, 0.0, 1.0);
  sub_854930(&v8, 0);
  sub_854930(&v8, 1u);
  sub_854930(&v8, 2u);
  pData = eFldTDmgEff;
  dds3EffectReset(eFldTDmgEff);
  dds3EffectSetPosition(&pData, v8);
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
    if (gfldTakaraWork->m_Items[i])
    {
        goto LABEL_25;
LABEL_14:
      goto LABEL_25;
    }
    v9 = gfldTakaraWork;
    v10 = Allocate(fldTakaraWork_tag);
    _ctor(v10, 0);
    *&v9[2 * i + 8] = v10;
      goto LABEL_14;
LABEL_25:
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
      else if (v31 >= LODWORD(v35->max_length))
      {
LABEL_66:
      }
      dds3EffectPartDelete((v35 + i), 0);
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
  s32 fieldID;
  dds3DefaultMain_o *kernelObject;
  bool v19;
  s32 v20;
  s32 v21;
  s32 v22;

  fieldID = fldGb->fieldID;
  if (fieldID != 1)
  {
    else if (fieldID < 11)
    {
      goto LABEL_10;
    }
  }
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v22 = 0;
LABEL_65:
  SetRadarUI(kernelObject, v19, v20, v21, v22);
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
      mdlSingleMotionForUnity(fldObj, "anim", mode, 0, 0);
    }
  }
}
