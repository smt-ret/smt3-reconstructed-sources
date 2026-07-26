#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct AssetBundles AssetBundles;
typedef struct FieldChrHD FieldChrHD;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3MoverBasicObjFunc_t dds3MoverBasicObjFunc_t;
typedef struct dds3PoseSet_t dds3PoseSet_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct fldFollowCameraControl_t fldFollowCameraControl_t;
typedef struct fldResourcePoint_t fldResourcePoint_t;
typedef struct fldSceneParam_t fldSceneParam_t;
typedef struct fldUnitControl_t fldUnitControl_t;
typedef struct fldWave_tag fldWave_tag;
typedef struct sdfGrOt_t sdfGrOt_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfModelOt_t sdfModelOt_t;
typedef struct sdfRandCB_t sdfRandCB_t;

static void *DispMemoryObj;
static fldUnitControl_t *fldUnitControl;
static fldFollowCameraControl_t *fldFollowCameraControl;
static fldSceneParam_t fldSceneParam;
static s32 l_UseCollision;
static sdfRandCB_t *grnd_cb;
static s32 gFldNowDZone;
static fldResourcePoint_t ppos01Point;
static sdfMemHandle_t *mhfldPlayerFile;
static void *gfldPlayerPtr;
static s32 gfldPlayerSize;
static s32 gfldPlayerSizeBk;
static void *mhfldPlayerFileBk;
static void *mhfldPlayerFileBkKage;
static void *mhfldPlayerFileM;
static void *PlayerCeiling;
static void *FldChar;
static void *gfldAnaPtr;
static s32 gfldAnaSize;
static dds3Basic_t *fldAnaBasic;
static void *mhfldAnaFile;
static void *mhfldWaveFile;
static void *gfldWavePtr;
static s32 gfldWaveSize;
static fldWave_tag *fldWaveBuff[40];
static char *playerPrefab;
static s32 loadtimer;
static bool fldDataCheckFlg;
static void *m_head;
static void *m_key;
static void *m_akey;
static void *m_ppath;
static void *m_pname;
static void *m_fname;
static s32 gFldAnahoriAkumaIdx;
static s32 gFldAnahoriAkumaIdxMax;

void FadeoutBGM(char *name, f32 fadeTime);
void FilterDelete(void);
void FromRotation(f32 aAngle);
bool IsDLCField(s32 area);
bool IsLoad(AssetBundles *this, char *key);
void KageSetRenserQueue(FieldChrHD *this, s32 OverlayQueue);
void KageSet_Size_BlendPower(FieldChrHD *this, f32 OverlaySize, f32 aBlendPower);
void KillOoyTest(void);
void LoadAssetExt(char *key, char *name, char *dlc);
void *LoadManiacsChar_18104096(s32 *phase);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
void Mult(void);
void ReleaseChar(void);
void RetryMapLoad(void);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__STOREIDENTITYVECTOR(sdfVector4_t *p);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SetLayerAll2(FieldChrHD *this, void *rootobj, s32 setlayer);
void SetModelObject(FieldChrHD *this, void *chr, void *kage);
void UnloadAB(AssetBundleCtrl *this, char *key);
void UnloadALL(bool all);
void UpdateAudioVolume(s32 type);
s32 datDelDevil(s32 id);
dds3Basic_t *dds3AddCameraObjectBasicTypeLookAt(u32 serialID, sdfVector4_t eyePos, sdfVector4_t targetPos, sdfVector4_t vertical);
dds3Basic_t *dds3AddPointBasic(u32 serialID, fldResourcePoint_t *pData, char *pName);
dds3Basic_t *dds3AddUnitObjectBasic(u32 serialID, sdfVector4_t aPos, sdfVector4_t aRot);
void dds3AdminiCallSequence(s32 sequence, void *data, s32 datasize, s32 restore);
void dds3CameraObjectBasicSetTargetPos(dds3Basic_t **pBasic, sdfVector4_t targetPos);
bool dds3CheckDLC2(void);
dds3Basic_t *dds3GetControlScene(void);
void dds3GetPosPoseSet(dds3Basic_t **pBasic);
void dds3GetRotPoseSet(dds3Basic_t **pBasic);
void dds3GlobalWorkUserInit2(s32 mode);
void *dds3ObjectBaseGetModelHandle(dds3Basic_t **pObjectBasic);
void dds3ObjectBaseMakeUnit(dds3Basic_t **pObjectBasic, s32 major, s32 minor);
void dds3ObjectBaseOffFlag(dds3Basic_t **pObjectBasic, u32 flag);
void dds3ObjectBaseOnFlag(dds3Basic_t **pObjectBasic, u32 flag, bool alock);
s32 dds3ObjectBaseSetPrimaryControl(dds3Basic_t **basic, dds3MoverBasicObjFunc_t *func);
void *dds3PointBasicGetResource(dds3Basic_t *pPointBasic);
dds3Basic_t *dds3SceneBasicSearchNameAndType(dds3Basic_t *scene, u32 type, char *name);
dds3ProcessID_t *dds3SearchProcessName(char *namestr);
u32 dds3SerializeID(void);
dds3Basic_t *dds3SetActiveCameraSceneBasic(dds3Basic_t **pSceneBasic, dds3Basic_t **pCameraBasic);
void dds3SetActiveScene(dds3Basic_t *scene);
dds3Basic_t *dds3SetActiveUnitSceneBasic(dds3Basic_t *pSceneBasic, dds3Basic_t *pUnitBasic);
void dds3SetBasicName(dds3Basic_t **basic, char *name);
void dds3SetPosPoseSet(dds3Basic_t **pBasic, sdfVector4_t pos);
void dds3SetRadiusPoseSet(dds3Basic_t **pBasic, f32 radius);
void dds3SetSclPoseSet(dds3Basic_t **pBasic, sdfVector4_t scl);
void dds3UnitObjectBasicSetOt(dds3Basic_t **aPtr, s32 idx);
bool evtBitCheck(s32 no);
void evtBitOff(s32 no);
void evtBitOn(s32 no);
void evtFreeStage(void);
evtUnitHandle_t *evtGetUnitHandle2(dds3Basic_t *unit);
s32 evtLoadArea(s32 fld, s32 area);
void fldAutoMapLoad(void);
void fldAutoMapNameD(s32 nameID);
void fldAutoMapNameU(s32 nameID);
void fldDbgPrintStr2DC(s32 x, s32 y, s32 col, char *str, s32 second);
void fldDrawInit(void);
void fldEveHit_End(void);
void fldGbInit_System(s32 mode);
void fldGbTblLoad(void);
s32 fldGetRestoreMode(void);
void fldHitChkUnit(sdfVector4_t phys_pos);
void fldInitAllValue(void);
void fldJDataClear(void);
void fldJDataLoad(void);
s32 fldLightMaIdxCalc(void);
void fldLightMaStart(void);
void fldLoadNextFile_SetId_BtlRet(s32 field, s32 area);
void fldNpcLoad1st(void);
void fldPlayerAFree(void);
void fldPlayerALoad(void);
void *fldPlayerALoadForUnity(void);
void fldPlayerCalc_Hit(void);
void fldPlayerDelete(void);
s32 fldPlayerFastSet(void);
void fldPlayerLoadCheck(void);
bool fldPlayerMirAreaChk(void);
void fldPlayerPosRot_RESTORE(void);
void fldProcNext(s32 fld, s32 eveno);
void fldProcOffFlag(u32 flag);
void fldProcOnFlag(u32 flag);
void fldProcShutDown(void);
void fldRegistUnitPad(void);
void fldRunDanteFree(void);
void fldRunDanteInit(void);
void fldRunInit(void);
void fldSePlay(s32 seid);
void fldSe_Init(void);
void fldSetCharClr(void);
void fldSetSceneParam2(fldSceneParam_t *pParam, s32 loadField, s32 loadArea, char *pointResName);
void fldSetUnit(fldResourcePoint_t *point);
void fldSetUnitFollowCamera(void);
void fldSetUnitFollowCameraForUnity(void);
void fldShutoff(void);
void fldSkyDefaultLoad(void);
void fldSkySetTableAnime(s32 type);
void fldSkySetTbl(s32 idx, s32 hokan);
void fldSkySetTblLightMa(s32 idx, s32 hokan);
void fldSkySetTblLightMaDZ(s32 idx);
void fldStatusSet(void);
void fldTitleMiniStart(s32 fld);
void fldUnloadAll(s32 field, s32 area);
void fldWapAnimCheck(bool sw);
bool fldWap_Load(s32 tmnltype, s32 tmnlid, fldSceneParam_t *param);
bool fldWap_Suspend(s32 fld, s32 area, s32 CamIdx, s32 BgmId, s32 SeId, s32 WapIdx, fldSceneParam_t *param);
void fldWaveInit(void);
void mdlLoopMotion(dds3ModelHandle_t **aHandle, s32 aGroup, s32 aNumber);
FieldChrHD *mdlSetHD(void *obj, s32 mode, evtUnitHandle_t *hunit, s32 layer);
s32 mselGemeMode(void);
void nbBgmFadeOut(void);
void nbResetEncountCount(void);
void resetCamNormal(void);
void resetCamNormal2(void);
void resetCamTgtPlayer(void);
void resetCamWM2(void);
void sdfModelOtInit(sdfModelOt_t **aModelOt, sdfGrOt_t *aOt0, sdfGrOt_t *aOt1, sdfGrOt_t *aOt2, sdfGrOt_t *aOt3);
void sdfRandomize(sdfRandCB_t **aCB, u32 aSeed);
s32 slGetExitType(void);

// 0x10c4260
bool FldDataCheck(s32 field, s32 area) {
    IsDLCField(0);
    IsLoad(0, 0);
    LoadAssetExt(0, 0, 0);
    return 0;
}

// 0x10c3d50
void FldDataLoadRequest(void) {
    fldUnloadAll(0, 0);
    IsDLCField(0);
    IsLoad(0, 0);
    LoadAssetExt(0, 0, 0);
}

// 0x10c41b0
bool IsFldDataLoaded(void) {
  AssetBundleCtrl_o *asset_bc;
  System_String_o *v5;

  asset_bc = get_asset_bc();
  v5 = (m_akey->klass->vtable._3_ToString.methodPtr)(
         m_akey,
         m_akey->klass->vtable._3_ToString.method);
  return IsLoad(asset_bc, v5);
}

// 0x10c72a0
bool IsfldSetChar(char *name) {
  return Animator___ContainsKey(FldChar, name);
}

// 0x10c7320
void NpcHitChkCamera(sdfVector3_t eyepos, sdfVector3_t dsppos, sdfVector3_t *hitpos) {
}

// 0x10c2ed0
void fldAllShutDown(void) {
  fldEveHit_End();
  KillOoyTest();
  fldShutoff();
  evtFreeStage();
  fldProcShutDown();
  fldFollowCameraControl->handle = 0;
  UnloadUnusedAssets();
  PShadow_VecClipOnOff = 0.0;
  PShadow_YClipOnOff = 0.0;
  PShadow_OnOff = 0.0;
}

// 0x10c3680
void fldAnaStart(f32 x, f32 y, f32 z) {
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
    dds3ObjectBaseOffFlag(0, 0);
    fldSePlay(0);
}

// 0x10c6280
void fldAnahoriSelectDel(void) {
  u64 v2;
  s32 v3;
  struct datUnitWork_t_array *unitwork;
  struct datUnitWork_t_array *v8;
  struct datUnitWork_t_array *v11;
  struct datUnitWork_t_array *v14;
  struct datUnitWork_t_array *v17;
  struct datUnitWork_t_array *v22;
  struct System_SByte_array *param;
  struct datUnitWork_t_array *v27;
  s32 id;

  v2 = 0;
  v3 = 0;
  while (1)
  {
    unitwork = DDS3_GBWK->unitwork;
    if ((unitwork->m_Items[v2]->flag & 1) == 0)
    v8 = DDS3_GBWK->unitwork;
    if ((v8->m_Items[v2]->flag & 4) != 0)
    v11 = DDS3_GBWK->unitwork;
    if ((v11->m_Items[v2]->flag & 0x10) != 0)
    v14 = DDS3_GBWK->unitwork;
    if ((v14->m_Items[v2]->flag & 0x800) != 0)
    v17 = DDS3_GBWK->unitwork;
    if (!v17->m_Items[v2]->hp)
    if (gFldAnahoriAkumaIdx == v3)
      break;
    ++v3;
    if (v2++ >= 0xF)
      return;
  }
  v22 = DDS3_GBWK->unitwork;
  param = v22->m_Items[v2]->param;
  evtBitOn(1284);
  v27 = DDS3_GBWK->unitwork;
  id = v27->m_Items[v2]->id;
  datDelDevil(id);
}

// 0x10c5ef0
s32 fldAnahoriSelectGet(void) {
  u64 v2;
  s32 v3;
  struct datUnitWork_t_array *unitwork;
  struct datUnitWork_t_array *v8;
  struct datUnitWork_t_array *v11;
  struct datUnitWork_t_array *v14;
  struct datUnitWork_t_array *v17;
  struct datUnitWork_t_array *v23;

  if (!gFldAnahoriAkumaIdxMax)
    return 0;
  v2 = 0;
  v3 = 0;
  while (1)
  {
    unitwork = DDS3_GBWK->unitwork;
    if ((unitwork->m_Items[v2]->flag & 1) == 0)
    v8 = DDS3_GBWK->unitwork;
    if ((v8->m_Items[v2]->flag & 4) != 0)
    v11 = DDS3_GBWK->unitwork;
    if ((v11->m_Items[v2]->flag & 0x10) != 0)
    v14 = DDS3_GBWK->unitwork;
    if ((v14->m_Items[v2]->flag & 0x800) != 0)
    v17 = DDS3_GBWK->unitwork;
    if (!v17->m_Items[v2]->hp)
    if (gFldAnahoriAkumaIdx == v3)
      break;
    ++v3;
    if (v2++ >= 0xF)
      return 0;
  }
  v23 = DDS3_GBWK->unitwork;
  return v23->m_Items[v2]->id;
}

// 0x10c5c90
void fldAnahoriSelectInit(void) {
  u64 i;
  struct datUnitWork_t_array *unitwork;
  struct datUnitWork_t_array *v8;
  struct datUnitWork_t_array *v11;
  struct datUnitWork_t_array *v14;
  struct datUnitWork_t_array *v17;

  gFldAnahoriAkumaIdx = 0;
  gFldAnahoriAkumaIdxMax = 0;
  for (i = 0; i != 16; ++i)
  {
    unitwork = DDS3_GBWK->unitwork;
    if ((unitwork->m_Items[i]->flag & 1) != 0)
    {
      v8 = DDS3_GBWK->unitwork;
      if ((v8->m_Items[i]->flag & 4) == 0)
      {
        v11 = DDS3_GBWK->unitwork;
        if ((v11->m_Items[i]->flag & 0x10) == 0)
        {
          v14 = DDS3_GBWK->unitwork;
          if ((v14->m_Items[i]->flag & 0x800) == 0)
          {
            v17 = DDS3_GBWK->unitwork;
            if (v17->m_Items[i]->hp)
            {
              ++gFldAnahoriAkumaIdxMax;
            }
          }
        }
      }
    }
  }
}

// 0x10c61d0
void fldAnahoriSelectNext(void) {
  fldMain_c *v2;
  struct fldMain_StaticFields *static_fields;

  ++gFldAnahoriAkumaIdx;
  static_fields = v2->static_fields;
  if (static_fields->gFldAnahoriAkumaIdxMax <= static_fields->gFldAnahoriAkumaIdx)
  {
    static_fields->gFldAnahoriAkumaIdx = 0;
  }
}

// 0x10c4850
s32 fldChkVortex(void) {
  System_Array_o *v1;
  void *monitor;
  u64 v6;
  s32 fieldID;

  v1 = NewSpecific(s32, 3u);
  InitializeArray_1543888(v1, Field__PrivateImplementationDetails__822D60DA6BDF9B9CC295F2A00E424CDA218D3B73);
  monitor = v1[1].monitor;
  if (monitor >= 1)
  {
    v6 = 0;
    do
    {
      if (fldGb->fieldID == *(&v1[2].klass + v6))
        return 0;
      LODWORD(monitor) = v1[1].monitor;
      ++v6;
    }
    while (v6 < monitor);
  }
  fieldID = fldGb->fieldID;
  if (fieldID < 601)
    return 1;
  else if (fieldID >= 617)
  {
    return 1;
  }
  return 0;
}

// 0x10c4480
bool fldDataCheck(s32 field, s32 area) {
    IsDLCField(0);
    IsLoad(0, 0);
    LoadPrefab_16624656(0, 0, 0, 0);
    fldDbgPrintStr2DC(0, 0, 0, 0, 0);
    UnloadAB(0, 0);
    LoadAssetExt(0, 0, 0);
    return 0;
}

// 0x10be280
void fldDbgWmapStart(void) {
  s16 v3;
  s32 v4;

  if ((v3 & 0x200) != 0)
  {
    v4 = v3 & 0x200;
  }
  else
  {
    v4 = 0;
  }
  if (!DDS3_GBWK->GameFileInfo->newfile)
  {
    dds3GlobalWorkUserInit2(0);
    else    evtBitOn(2802);
  }
  dds3GlobalWorkUserInit2(1);
  if (cfgChkFlagChange())
  {
    cfgCopyFlagBakToGbl();
  }
  else
  {
    cfgCopyFlagGblToBak();
  }
  evtBitOn(3087);
  fldDbg->NoClip = 0;
  fldDbg->EncountOn = 1;
  fldProcNext(11, 601);
}

// 0x10c5c20
s32 fldEsutoMaChk(void) {
  return DDS3_GBWK->stat & 1;
}

// 0x10c5ab0
void fldEsutoMaClear(void) {
  DDS3_GBWK->stat &= ~1u;
  fldGb->flag &= ~8u;
}

// 0x10c5940
void fldEsutoMaClearMsg(void) {
  else if ((DDS3_GBWK->stat & 1) == 0)
  {
    return;
  }
  DDS3_GBWK->stat &= ~1u;
  fldGb->flag &= ~8u;
  fldGb->flag |= 8u;
}

// 0x10c5b60
void fldEsutoMaStart(void) {
  DDS3_GBWK->stat |= 1u;
  DDS3_GBWK->stat &= ~2u;
  fldGb->flag &= ~8u;
}

// 0x10be960
void fldFirstInit(void) {
    fldDrawInit();
    fldInitAllValue();
    fldSe_Init();
    sdfRandomize(0, 0);
    fldNpcLoad1st();
    fldSkyDefaultLoad();
    fldAutoMapLoad();
    fldGbTblLoad();
}

// 0x10c6e50
void *fldGetCharObj(char *name) {
  if (!Animator___ContainsKey(FldChar, name))
    return 0;
  return object___get_Item(FldChar, name);
}

// 0x10becc0
fldFollowCameraControl_t *fldGetFollowCameraControl(void) {
  return fldFollowCameraControl;
}

// 0x10bf210
s32 fldGetRestoreMode(void) {
  struct fldMain_StaticFields *static_fields;
  s32 callmode;

  else
  {
    static_fields = fldMain->static_fields;
    if (static_fields->fldSceneParam.mode == 1)
      return 1;
  }
  else
  {
    callmode = static_fields->fldSceneParam.callmode;
    if (callmode == 3)
      return 3;
  }
  else if (callmode == 4)
  {
    return 4;
  }
  if (callmode == 5)
    return 5;
  if (callmode == 6)
    return 2;
  return 2 * (static_fields->fldSceneParam.mode != 0);
}

// 0x10bec50
fldUnitControl_t *fldGetUnitControl(void) {
  return fldUnitControl;
}

// 0x10ba700
dds3Basic_t *fldGetUnitFollowCamera(void) {
  return fldFollowCameraControl->handle;
}

// 0x10beb00
void fldInitAllValue(void) {
  struct fldSceneParam_t_o *p_fldSceneParam;
  UnityEngine_Vector4_o v5;
  UnityEngine_Vector4_o v6;
  s64 v7;
  s64 v8;

  v7 = 0;
  v8 = 0;
  *&v6.x = 0;
  *&v6.z = 0;
  *&v5.x = 0;
  *&v5.z = 0;
  p_fldSceneParam = &fldSceneParam;
  memmove(&v5, p_fldSceneParam, 0x30u);
  memmove(&v5, p_fldSceneParam, 0x30u);
  SDF_VU0__STOREIDENTITYVECTOR(&v5);
  SDF_VU0__STOREIDENTITYVECTOR(&v6);
}

// 0x10c2640
void fldJDataClear(void) {
  fldMain_c *v2;
  struct fldMain_StaticFields *static_fields;
  UnityEngine_Object_o *mhfldAnaFile;
  bool v6;
  struct dds3Basic_t_o *fldAnaBasic;
  UnityEngine_Object_o *gameObject;
  bool v10;
  UnityEngine_Object_o *v11;
  UnityEngine_Object_o *mhfldWaveFile;
  bool v14;
  u64 v15;
  u64 v16;
  s32 v17;
  s64 v18;
  struct fldWave_tag_array *fldWaveBuff;
  struct fldWave_tag_array *v24;
  UnityEngine_Object_o *v26;
  struct fldWave_tag_array *v28;
  UnityEngine_Object_o *v30;
  struct fldWave_tag_array *v31;
  u32 v33;

  static_fields = v2->static_fields;
  if (static_fields->mhfldPlayerFile)
  {
    static_fields->mhfldPlayerFile = 0;
  }
  v6 = op_Inequality(mhfldAnaFile, 0, 0);
  if (v6)
  {
    if (fldAnaBasic)
    {
      gameObject = fldAnaBasic->gameObject;
      v10 = op_Inequality(gameObject, 0, 0);
      if (v10)
      {
        v11 = fldAnaBasic->gameObject;
        Destroy_27360000(v11);
        fldAnaBasic->gameObject = 0;
      }
    }
    mhfldAnaFile = 0;
  }
  v14 = op_Inequality(mhfldWaveFile, 0, 0);
  if (v14)
  {
    v16 = 0;
    do
    {
      v18 = *(*(v15 + 184) + 352LL);
      if (*(v18 + 8 * v16 + 32))
      {
        if (fldWaveBuff->m_Items[v16]->pBasic)
        {
          v24 = fldWaveBuff;
          v26 = v24->m_Items[v16]->pBasic->gameObject;
          if (op_Inequality(v26, 0, 0))
          {
            v28 = fldWaveBuff;
            v30 = v28->m_Items[v16]->pBasic->gameObject;
            Destroy_27360000(v30);
            v31 = fldWaveBuff;
            v31->m_Items[v16]->pBasic->gameObject = 0;
          }
        }
      }
      ++v16;
      v17 = (v33 >> 9) & 1;
    }
    while (v16 != 40);
    *(*(v15 + 184) + 328LL) = 0;
  }
  if ((*(v15 + 295) & 2) != 0 && !*(v15 + 216))
  fldPlayerAFree(v15);
  else if (fldGb->AreaToArea)
  {
    return;
  }
  else if (gFldRndEncBtl)
  {
    return;
  }
  fldPlayerAFree();
  fldLoadNextFile_SetId_BtlRet(0, 0);
}

// 0x10bcc60
void fldJDataLoad(void) {
  u64 *v1;
  s32 fieldID;
  fldGlobal_c *v6;
  s32 v9;
  AssetBundleCtrl_o *asset_bc;
  UnityEngine_GameObject_o *Prefab_16624656;
  s32 v13;
  AssetBundleCtrl_o *v14;
  System_String_o *v15;
  System_String_o *v16;
  s64 *v17;
  UnityEngine_GameObject_o *v19;

  v1 = Allocate(object);
  _ctor(v1, 0);
  fieldID = fldGb->fieldID;
  if (fieldID == 11)
  if (fieldID == 14)
  if (fieldID > 9)
  {
    fldPlayerALoad();
    gfldPlayerSize = gfldPlayerSizeBk;
    gfldPlayerPtr = v1;
    mhfldPlayerFile = 0;
  }
  fldPlayerALoad();
  v9 = fldGb->fieldID;
  if (v9 != 21)
  {
    else    if (v9 < 36)
    {
      if ((v6->_2.bitflags2 & 2) == 0)
    }
  }
  asset_bc = get_asset_bc();
  Prefab_16624656 = LoadPrefab_16624656(asset_bc, StringLiteral_8905, StringLiteral_16697, StringLiteral_16698);
  mhfldAnaFile = Prefab_16624656;
  {
  }
  v13 = fldGb->fieldID;
  if (v13 == 22)
  {
    v14 = get_asset_bc();
    v15 = StringLiteral_8913;
    v16 = StringLiteral_16699;
    v17 = &StringLiteral_16700;
    v19 = LoadPrefab_16624656(v14, v15, v16, *v17);
    mhfldWaveFile = v19;
    return;
  }
  if (v13 == 45)
  {
    v14 = get_asset_bc();
    v15 = StringLiteral_8913;
    v16 = StringLiteral_16699;
    v17 = &StringLiteral_16701;
  }
}

// 0x10bd330
s32 fldLightMaChk(void) {
  if ((DDS3_GBWK->stat & 8) != 0)
    return 1;
  if (gFldNowDZone)
    return 0;
  else
    return -1;
}

// 0x10c4ee0
void fldLightMaClear(void) {
  DDS3_GBWK->stat &= ~8u;
  fldGb->flag &= ~1u;
}

// 0x10c4d70
void fldLightMaClearMsg(void) {
  else if ((DDS3_GBWK->stat & 8) == 0)
  {
    return;
  }
  DDS3_GBWK->stat &= ~8u;
  fldGb->flag &= ~1u;
  fldGb->flag |= 1u;
}

// 0x10c49c0
s32 fldLightMaIdxCalc(void) {
    return 0;
}

// 0x10bd400
void fldLightMaStart(void) {
    fldSePlay(0);
    fldLightMaIdxCalc();
    fldSkySetTblLightMa(0, 0);
}

// 0x10c4f90
void fldLightMaTask(void) {
    evtGetUnitHandle2(0);
    fldSkySetTblLightMa(0, 0);
    fldSePlay(0);
    fldLightMaIdxCalc();
}

// 0x10be470
void fldMainLoadStart(void) {
    slGetExitType();
    UpdateAudioVolume(0);
    fldGbInit_System(0);
    evtBitOn(0);
    fldProcNext(0, 0);
    fldSetSceneParam2(0, 0, 0, 0);
    dds3CheckDLC2();
    dds3AdminiCallSequence(0, 0, 0, 0);
}

// 0x10c65f0
void fldOtInit(void) {
    sdfModelOtInit(0, 0, 0, 0, 0);
}

// 0x10c25b0
void *fldPlayer3LoadForUnity(void) {
  return LoadManiacsChar_18104096(&loadtimer);
}

// 0x10c20d0
void fldPlayerAFree(void) {
  UnityEngine_Object_o *mhfldPlayerFileM;
  UnityEngine_Object_o *v8;
  UnityEngine_Object_o *mhfldPlayerFileBk;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *Child;
  UnityEngine_GameObject_o *v16;
  UnityEngine_Object_o *PlayerCeiling;
  UnityEngine_GameObject_o *v21;
  UnityEngine_Vector3_o localPosition;
  UnityEngine_Vector3_o v23;

  fldSetCharClr();
  UnloadALL(0);
  if (op_Inequality(mhfldPlayerFileM, 0, 0))
  {
    v8 = mhfldPlayerFileM;
    Destroy_27360000(v8);
  }
  mhfldPlayerFileM = 0;
  if (op_Inequality(mhfldPlayerFileBk, 0, 0))
  {
    transform = get_transform(mhfldPlayerFileBk, 0);
    Child = GetChild(transform, 0);
    localPosition = get_localPosition(Child);
    v23.x = localPosition.x;
    v23.z = localPosition.z;
    v23.y = 0.0;
    set_localPosition(Child, v23);
    v16 = mhfldPlayerFileBk;
    cmpSetupObject(v16, 0);
  }
  if (op_Inequality(PlayerCeiling, 0, 0))
  {
    v21 = PlayerCeiling;
    cmpSetupObject(v21, 0);
  }
}

// 0x10c1a60
void fldPlayerALoad(void) {
    fldPlayerLoadCheck();
    LoadPrefab_16624656(0, 0, 0, 0);
    mdlSetHD(0, 0, 0, 0);
    SetModelObject(0, 0, 0);
    KageSetRenserQueue(0, 0);
    KageSet_Size_BlendPower(0, 0, 0);
    fldPlayerALoadForUnity();
    SetLayerAll2(0, 0, 0);
}

// 0x10bd030
void *fldPlayerALoadForUnity(void) {
    evtBitCheck(0);
    LoadPrefab_16624656(0, 0, 0, 0);
    return 0;
}

// 0x10c17f0
void fldPlayerDelete(void) {
  UnityEngine_Object_o *mhfldPlayerFileBk;
  UnityEngine_Object_o *v6;
  UnityEngine_Object_o *mhfldPlayerFileBkKage;
  bool v10;
  UnityEngine_Object_o *v12;
  UnityEngine_Object_o *PlayerCeiling;
  UnityEngine_Object_o *v16;

  if (op_Inequality(mhfldPlayerFileBk, 0, 0))
  {
    v6 = mhfldPlayerFileBk;
    Destroy_27360000(v6);
  }
  mhfldPlayerFileBk = 0;
  v10 = op_Inequality(mhfldPlayerFileBkKage, 0, 0);
  if (v10)
  {
    v12 = mhfldPlayerFileBkKage;
    Destroy_27360000(v12);
    mhfldPlayerFileBkKage = 0;
  }
  if (op_Inequality(PlayerCeiling, 0, 0))
  {
    v16 = PlayerCeiling;
    Destroy_27360000(v16);
  }
  PlayerCeiling = 0;
  playerPrefab = StringLiteral_416;
}

// 0x10c15b0
void fldPlayerLoadCheck(void) {
  s32 fieldID;
  s64 *v4;
  bool v5;
  System_String_o *v6;
  bool v9;
  UnityEngine_Object_o *v11;
  UnityEngine_GameObject_o *mhfldPlayerFileBk;

  fieldID = fldGb->fieldID;
  if (fieldID < 10)
  {
    v4 = &StringLiteral_16693;
  }
  else if (fieldID != 14)
  {
    v4 = &StringLiteral_16692;
  }
  v5 = evtBitCheck(2224);
  v4 = &StringLiteral_16691;
  if (v5)
    v4 = &StringLiteral_16690;
  v6 = *v4;
  v9 = Equals_5234480(playerPrefab, v6);
  if (v9)
  {
    v11 = *&v10[2].klass->_2.thread_static_fields_size;
    if (op_Inequality(v11, 0, 0))
    {
      cmpSetupObject(mhfldPlayerFileBk, 1);
    }
  }
  else
  {
    fldPlayerDelete();
  }
}

// 0x10bb2d0
bool fldPlayerMirAreaChk(void) {
  struct fldGlobalWork_t_o *fldGb;
  s32 fieldID;
  struct fldGlobalWork_t_o *v6;
  struct fldGlobalWork_t_o *v7;
  struct fldGlobalWork_t_o *v8;
  struct fldGlobalWork_t_o *v9;
  struct fldGlobalWork_t_o *v10;
  struct fldGlobalWork_t_o *v11;
  struct fldGlobalWork_t_o *v12;

  fieldID = fldGb->fieldID;
  if (fieldID == 18)
    return 1;
  else if (fieldID == 28)
  {
    return 1;
  }
  else if (fieldID == 30)
  {
    return 1;
  }
  if (fieldID != 33)
  if (!fldGb->areaID)
    return 1;
  v6 = fldGb;
  if (v6->fieldID != 17)
  if (v6->areaID == 1)
    return 1;
  v7 = fldGb;
  if (v7->fieldID != 17)
  if (v7->areaID == 2)
    return 1;
  v8 = fldGb;
  if (v8->fieldID != 17)
  if (v8->areaID == 3)
    return 1;
  v9 = fldGb;
  if (v9->fieldID != 14)
  if (v9->areaID == 16)
    return 1;
  v10 = fldGb;
  if (v10->fieldID != 15)
  if (v10->areaID == 16)
    return 1;
  v11 = fldGb;
  if (v11->fieldID != 15)
  if (v11->areaID == 9)
    return 1;
  v12 = fldGb;
  if (v12->fieldID != 34)
    return 0;
  return !v12->areaID;
}

// 0x10bf3c0
void fldReadyScene(void) {
    FilterDelete();
    fldWap_Load(0, 0, 0);
    fldWap_Suspend(0, 0, 0, 0, 0, 0, 0);
    evtLoadArea(0, 0);
    dds3SetActiveScene(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    FromRotation(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    Mult();
    SDF_VU0__STOREVECTOR(0);
    fldPlayerPosRot_RESTORE();
    nbBgmFadeOut();
    dds3GetControlScene();
    dds3SceneBasicSearchNameAndType(0, 0, 0);
    dds3PointBasicGetResource(0);
    fldGetRestoreMode();
    fldTitleMiniStart(0);
    fldSetUnit(0);
    fldRegistUnitPad();
    fldSetUnitFollowCamera();
    resetCamTgtPlayer();
    resetCamWM2();
    resetCamNormal();
    resetCamNormal2();
    evtBitCheck(0);
    fldAutoMapNameU(0);
    fldAutoMapNameD(0);
    RetryMapLoad();
}

// 0x10c1010
void fldRegistUnitPad(void) {
    fldProcOnFlag(0);
    fldWapAnimCheck(0);
    dds3ObjectBaseSetPrimaryControl(0, 0);
    fldStatusSet();
    fldPlayerCalc_Hit();
    dds3GetPosPoseSet(0);
    SDF_VU0__STOREVECTOR(0);
    fldHitChkUnit((sdfVector4_t){0});
}

// 0x10c34f0
void fldReleaseUnitPad(void) {
  struct fldUnitControl_t_o *fldUnitControl;
  dds3Basic_t_o **p_handle;
  struct dds3Basic_t_o *handle;

  handle = fldUnitControl->handle;
  p_handle = &fldUnitControl->handle;
  if (handle)
  {
    fldProcOffFlag(0x40u);
    dds3ObjectBaseSetPrimaryControl(p_handle, 0);
    if (fldGb->fieldID <= 9)
    {
      fldWapAnimCheck(0);
    }
  }
  fldGb->NoEncountCnt = 4;
}

// 0x10c58d0
s32 fldRiberaMaChk(void) {
  return (DDS3_GBWK->stat >> 1) & 1;
}

// 0x10c5760
void fldRiberaMaClear(void) {
  DDS3_GBWK->stat &= ~2u;
  fldGb->flag &= ~4u;
}

// 0x10c55f0
void fldRiberaMaClearMsg(void) {
  else if ((DDS3_GBWK->stat & 2) == 0)
  {
    return;
  }
  DDS3_GBWK->stat &= ~2u;
  fldGb->flag &= ~4u;
  fldGb->flag |= 4u;
}

// 0x10c5810
void fldRiberaMaStart(void) {
  DDS3_GBWK->stat |= 2u;
  DDS3_GBWK->stat &= ~1u;
  fldGb->flag &= ~4u;
}

// 0x10c5580
s32 fldRifutoMaChk(void) {
  return (DDS3_GBWK->stat >> 2) & 1;
}

// 0x10c5420
void fldRifutoMaClear(void) {
  DDS3_GBWK->stat &= ~4u;
  fldGb->flag &= ~2u;
}

// 0x10c52b0
void fldRifutoMaClearMsg(void) {
  else if ((DDS3_GBWK->stat & 4) == 0)
  {
    return;
  }
  DDS3_GBWK->stat &= ~4u;
  fldGb->flag &= ~2u;
  fldGb->flag |= 2u;
}

// 0x10c54d0
void fldRifutoMaStart(void) {
  DDS3_GBWK->stat |= 4u;
  fldGb->flag &= ~2u;
}

// 0x10c7090
void fldSetAllCharDisp(bool sw) {
}

// 0x10c6dc0
void fldSetCharAdd(char *name, void *obj) {
  PropertySheet___Add(FldChar, name, obj);
}

// 0x10c2380
void fldSetCharClr(void) {
}

// 0x10c6f20
void fldSetCharDel(char *name) {
  Il2CppObject *Item;

  if (Animator___ContainsKey(FldChar, name))
  {
    Item = object___get_Item(FldChar, name);
    if (op_Inequality(Item, 0, 0))
    {
      Destroy_27360000(Item);
    }
    HashSet_Text____Remove(FldChar, name);
  }
}

// 0x10be7a0
void fldSetSceneParam2(fldSceneParam_t *pParam, s32 loadField, s32 loadArea, char *pointResName) {
  struct fldGlobalWork_t_o *fldGb;
  System_Array_o *camName;

  if (dds3SearchProcessName(StringLiteral_16586))
  {
    if (fldGb->fieldID == loadField)
    {
      fldGb->AreaToArea = 1;
    }
    else
    {
      nbResetEncountCount();
    }
  }
  pParam->flag = 0;
  *&pParam->pointResrcID = 0;
  pParam->pointResName = ToCharArray(pointResName);
  camName = pParam->camName;
  pParam->loadField = loadField;
  pParam->loadArea = loadArea;
  *&pParam->loadScript = 0x200000001LL;
  *&pParam->bgm = 0;
  Clear(camName, 0, 16, 0);
  Clear(pParam->FoceScript, 0, 16, 0);
  pParam->loadMode = 0;
  gFldWap_after_flag = 0;
  Clear(gFldWap_after_scr, 0, 15, 0);
}

// 0x10bed30
void fldSetSceneParam3(fldSceneParam_t *pParam, s32 loadField, s32 loadArea, char *pointResName) {
  struct fldGlobalWork_t_o *fldGb;

  if (dds3SearchProcessName(StringLiteral_16586))
  {
    if (fldGb->fieldID == loadField)
    {
      fldGb->AreaToArea = 1;
    }
    else
    {
      nbResetEncountCount();
    }
  }
  pParam->flag = 0;
  *&pParam->pointResrcID = 0;
  pParam->pointResName = ToCharArray(pointResName);
  pParam->loadField = loadField;
  pParam->loadArea = loadArea;
  pParam->loadMode = 0;
  *&pParam->loadScript = 0x300000001LL;
  *&pParam->bgm = 0;
}

// 0x10bee80
void fldSetSceneParam4(fldSceneParam_t *pParam, s32 loadField, s32 loadArea, char *pointResName, s32 bgm, s32 camMode, char *camName) {
  s16 v10;
  struct fldGlobalWork_t_o *fldGb;

  v10 = bgm;
  if (dds3SearchProcessName(StringLiteral_16586))
  {
    if (fldGb->fieldID == loadField)
    {
      fldGb->AreaToArea = 1;
    }
    else
    {
      nbResetEncountCount();
    }
  }
  pParam->flag = 0;
  *&pParam->pointResrcID = 0;
  pParam->pointResName = ToCharArray(pointResName);
  pParam->loadField = loadField;
  pParam->loadArea = loadArea;
  *&pParam->loadScript = 0x200000001LL;
  pParam->bgm = v10;
  pParam->bgmMode = 0;
  pParam->camMode = camMode;
  pParam->camName = ToCharArray(camName);
  pParam->loadMode = 0;
}

// 0x10bf000
void fldSetSceneParam5(fldSceneParam_t *pParam, s32 loadField, s32 loadArea, char *pointResName, s32 bgm, char *FoceScript) {
  s16 v8;
  struct fldGlobalWork_t_o *fldGb;

  v8 = bgm;
  if (dds3SearchProcessName(StringLiteral_16586))
  {
    if (fldGb->fieldID == loadField)
    {
      fldGb->AreaToArea = 1;
    }
    else
    {
      nbResetEncountCount();
    }
  }
  pParam->flag = 0;
  *&pParam->pointResrcID = 0;
  pParam->pointResName = ToCharArray(pointResName);
  pParam->loadField = loadField;
  pParam->loadArea = loadArea;
  *&pParam->loadScript = 0x200000001LL;
  pParam->bgm = v8;
  pParam->bgmMode = 0;
  pParam->camMode = 0;
  pParam->FoceScript = ToCharArray(FoceScript);
  pParam->loadMode = 0;
}

// 0x10bf180
void fldSetSceneParamLoad(fldSceneParam_t *pParam, s32 loadField, s32 loadArea, char *pointResName, s32 bgm, s32 camMode, char *camName) {
  s16 v12;

  pParam->flag = 0;
  v12 = bgm;
  *&pParam->pointResrcID = 0;
  pParam->pointResName = ToCharArray(pointResName);
  pParam->loadField = loadField;
  pParam->loadArea = loadArea;
  *&pParam->loadScript = 0x200000001LL;
  pParam->bgm = v12;
  pParam->bgmMode = 0;
  pParam->camMode = camMode;
  pParam->camName = ToCharArray(camName);
  pParam->loadMode = 0;
}

// 0x10bb720
void fldSetUnit(fldResourcePoint_t *point) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    FromRotation(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    Mult();
    SDF_VU0__STOREVECTOR(0);
    dds3SerializeID();
    dds3AddUnitObjectBasic(0, (sdfVector4_t){0}, (sdfVector4_t){0});
    dds3SetBasicName(0, 0);
    dds3GetControlScene();
    dds3SetActiveUnitSceneBasic(0, 0);
    dds3ObjectBaseOffFlag(0, 0);
    fldJDataLoad();
    dds3ObjectBaseMakeUnit(0, 0, 0);
    dds3UnitObjectBasicSetOt(0, 0);
    dds3ObjectBaseOnFlag(0, 0, 0);
    dds3SetSclPoseSet(0, (sdfVector4_t){0});
    dds3ObjectBaseGetModelHandle(0);
    dds3SetRadiusPoseSet(0, 0);
    fldPlayerMirAreaChk();
    fldPlayerALoadForUnity();
    mdlSetHD(0, 0, 0, 0);
    SetLayerAll2(0, 0, 0);
    evtBitCheck(0);
    evtBitOff(0);
    ReleaseChar();
    evtBitOn(0);
    mdlLoopMotion(0, 0, 0);
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
    fldRunDanteInit();
    fldRunInit();
    FadeoutBGM(0, 0);
    FilterDelete();
    fldSkySetTblLightMa(0, 0);
    fldSkySetTbl(0, 0);
    fldSkySetTableAnime(0);
    fldLightMaStart();
    fldSkySetTblLightMaDZ(0);
    fldPlayerFastSet();
    fldWaveInit();
    dds3AddPointBasic(0, 0, 0);
}

// 0x10c13b0
void fldSetUnitFollowCamera(void) {
    dds3SerializeID();
    dds3AddCameraObjectBasicTypeLookAt(0, (sdfVector4_t){0}, (sdfVector4_t){0}, (sdfVector4_t){0});
    dds3SetBasicName(0, 0);
    dds3CameraObjectBasicSetTargetPos(0, (sdfVector4_t){0});
    dds3SetRadiusPoseSet(0, 0);
    dds3GetControlScene();
    dds3SetActiveCameraSceneBasic(0, 0);
    fldSetUnitFollowCameraForUnity();
}

// 0x10c2b70
void fldShutoff(void) {
    dds3GetControlScene();
    dds3GetPosPoseSet(0);
    SDF_VU0__STOREVECTOR(0);
    dds3GetRotPoseSet(0);
    fldJDataClear();
    fldRunDanteFree();
}

// 0x10c3d40
s32 fldUnitPad(dds3PoseSet_t *pUpdatePoseSet, dds3Basic_t *pBasic) {
  return 0;
}

// 0x10bdca0
void fldWaveInit(void) {
    dds3SerializeID();
    dds3AddUnitObjectBasic(0, (sdfVector4_t){0}, (sdfVector4_t){0});
    dds3SetBasicName(0, 0);
    dds3ObjectBaseMakeUnit(0, 0, 0);
    dds3ObjectBaseOnFlag(0, 0, 0);
}

// 0x10c3850
void fldWaveStart(f32 x, f32 y, f32 z) {
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
    dds3ObjectBaseOffFlag(0, 0);
}

// 0x10c3b10
void fldWaveTask(void) {
  UnityEngine_Object_o *mhfldWaveFile;
  u64 i;
  struct fldWave_tag_array *fldWaveBuff;
  struct fldWave_tag_array *v10;
  struct fldWave_tag_array *v12;
  struct fldWave_tag_array *v15;
  struct fldWave_tag_array *v17;

  if (!op_Equality(mhfldWaveFile, 0, 0))
  {
    for (i = 0; i != 40; ++i)
    {
      if (fldWaveBuff->m_Items[i]->use)
      {
        v10 = fldWaveBuff;
        ++v10->m_Items[i]->cnt;
        v12 = fldWaveBuff;
        if (v12->m_Items[i]->cnt >= 71)
        {
          v15 = fldWaveBuff;
          dds3ObjectBaseOnFlag(&v15->m_Items[i]->pBasic, 1u, 0);
          v17 = fldWaveBuff;
          v17->m_Items[i]->use = 0;
        }
      }
    }
  }
}
