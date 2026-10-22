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
  bool IsDLCField;
  s64 *v5;
  System_String_o *v6;
  System_String_o *v7;
  System_String_o *v9;
  AssetBundleCtrl_o *asset_bc;
  System_String_o *v11;
  bool IsLoad;
  char v15;
  bool v16;
  s32 v22;

  v22 = field;
  IsDLCField = IsDLCField(field);
  v5 = &"m";
  if (!IsDLCField)
    v5 = &"";
  v6 = *v5;
  v7 = sub_232A70(&v22, "D3");
  v9 = Concat_5224608("f", v7);
  asset_bc = get_asset_bc();
  v11 = Concat_5224608(v9, v6);
  IsLoad = IsLoad(asset_bc, v11);
  if (IsLoad)
  {
    else
    {
      v15 = 0;
      v16 = 1;
    }
LABEL_28:
    fldDataCheckFlg = v15;
    return v16;
  }
  if (!fldDataCheckFlg)
    goto LABEL_21;
  return 0;
}

// 0x10c3d50
void FldDataLoadRequest(void) {
  s32 loadField;
  System_Text_StringBuilder_o *m_head;
  s32 v7;
  bool IsDLCField;
  s64 *v9;
  System_Text_StringBuilder_o *m_key;
  System_String_o *v14;
  System_Text_StringBuilder_o *m_akey;
  System_String_o *v17;
  System_Text_StringBuilder_o *v19;
  System_String_o *v20;
  System_Text_StringBuilder_o *m_ppath;
  System_String_o *v23;
  System_Text_StringBuilder_o *m_pname;
  System_String_o *v26;
  System_Text_StringBuilder_o *v28;
  System_String_o *v29;
  System_Text_StringBuilder_o *m_fname;
  System_String_o *v32;
  AssetBundleCtrl_o *asset_bc;
  System_String_o *v35;
  System_String_o *v38;
  System_String_o *v39;
  System_String_o *v41;

  loadField = fldSceneParam.loadField;
  fldUnloadAll(loadField, 0);
  Clear(m_head, 0);
  v7 = fldSceneParam.loadField;
  IsDLCField = IsDLCField(v7);
  v9 = &"m";
  if (!IsDLCField)
    v9 = &"";
  Append_5380272(m_head, *v9);
  Clear(m_key, 0);
  Append_5380272(m_key, "f");
  v14 = sub_232A70(&fldSceneParam.loadField, "D3");
  Append_5380272(m_key, v14);
  Clear(m_akey, 0);
  v17 = (m_key->klass->vtable._3_ToString.methodPtr)(m_key, m_key->klass->vtable._3_ToString.method);
  Append_5380272(m_akey, v17);
  v19 = m_akey;
  v20 = (m_head->klass->vtable._3_ToString.methodPtr)(m_head, m_head->klass->vtable._3_ToString.method);
  Append_5380272(v19, v20);
  Clear(m_ppath, 0);
  Append_5380272(m_ppath, "field/f/");
  v23 = (m_akey->klass->vtable._3_ToString.methodPtr)(m_akey, m_akey->klass->vtable._3_ToString.method);
  Append_5380272(m_ppath, v23);
  Clear(m_pname, 0);
  v26 = (m_key->klass->vtable._3_ToString.methodPtr)(m_key, m_key->klass->vtable._3_ToString.method);
  Append_5380272(m_pname, v26);
  Append_5380272(m_pname, "_");
  v28 = m_pname;
  v29 = sub_232A70(&fldSceneParam.loadArea, "D3");
  Append_5380272(v28, v29);
  Clear(m_fname, 0);
  Append_5380272(m_fname, "Field/");
  v32 = (m_pname->klass->vtable._3_ToString.methodPtr)(
          m_pname,
          m_pname->klass->vtable._3_ToString.method);
  Append_5380272(m_fname, v32);
  Append_5380272(m_fname, "(Clone)", 0);
  asset_bc = get_asset_bc();
  v35 = (m_akey->klass->vtable._3_ToString.methodPtr)(
          m_akey,
          m_akey->klass->vtable._3_ToString.method);
  if (!IsLoad(asset_bc, v35))
  {
    v38 = (m_akey->klass->vtable._3_ToString.methodPtr)(
            m_akey,
            m_akey->klass->vtable._3_ToString.method);
    v39 = (m_akey->klass->vtable._3_ToString.methodPtr)(
            m_akey,
            m_akey->klass->vtable._3_ToString.method);
    v41 = (m_head->klass->vtable._3_ToString.methodPtr)(
            m_head,
            m_head->klass->vtable._3_ToString.method);
    LoadAssetExt(v38, v39, v41);
  }
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
  f32 v5;
  f32 v6;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  System_Collections_Generic_Dictionary_ValueCollection_TKey__TValue__o *Values;
  UnityEngine_GameObject_o *v14;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v17;
  UnityEngine_GUILayer_o *Component_GUILayer;
  s64 v20;
  f32 z;
  s64 v23;
  f32 v24;
  s64 v25;
  f32 v26;
  f32 v27;
  f32 v28;
  f32 v29;
  f32 v30;
  f32 v31;
  f32 v32;
  f32 v33;
  f32 v34;
  f32 v35;
  f32 v36;
  f32 v37;
  f32 v38;
  UnityEngine_Ray_o v39;
  System_Collections_Generic_Dictionary_ValueCollection_Enumerator_TKey__TValue__o v40;
  UnityEngine_Vector3_o v41;
  UnityEngine_RaycastHit_o v42;
  UnityEngine_Ray_o v43;
  System_Collections_Generic_Dictionary_ValueCollection_Enumerator_TKey__TValue__o v44;
  s64 v45;
  f32 b;
  UnityEngine_Vector3_o v47;
  UnityEngine_Vector3_o v48;
  UnityEngine_Vector3_o v49;
  UnityEngine_Vector3_o v50;
  UnityEngine_Vector3_o v51;
  UnityEngine_Vector3_o v52;
  UnityEngine_Vector3_o v53;

  v49 = eyepos;
  v48 = dsppos;
  memset(&v44, 0, sizeof(v44));
  memset(&v42, 0, sizeof(v42));
  v41.z = 0.0;
  *&v41.x = 0;
  v47.z = 0.0;
  *&v47.x = 0;
  b = 0.0;
  v45 = 0;
  memset(&v43, 0, sizeof(v43));
  v5 = sub_8527D0(&v49.x, 0);
  sub_8529B0(&v47, 0, v5 / 100.0);
  v6 = sub_8527D0(&v49.x, 1);
  sub_8529B0(&v47, 1, v6 / -100.0);
  v7 = sub_8527D0(&v49.x, 2);
  sub_8529B0(&v47, 2, v7 / 100.0);
  v8 = sub_8527D0(&v48.x, 0);
  sub_8529B0(&v45, 0, v8 / 100.0);
  v9 = sub_8527D0(&v48.x, 1);
  sub_8529B0(&v45, 1, v9 / -100.0);
  v10 = sub_8527D0(&v48.x, 2);
  sub_8529B0(&v45, 2, v10 / 100.0);
  Values = Type___get_Values(FldChar);
  Type___GetEnumerator(&v40, Values);
  v44 = v40;
  while ((sub_4D4B20(&v44) & 1) != 0)
  {
    v14 = sub_4D4CB0(&v44);
    transform = get_transform(v14, 0);
    v17 = Find(transform, "Ceiling", 0);
    if (op_Inequality(v17, 0, 0))
    {
      Component_GUILayer = GetComponent_GUILayer_(v17);
      v50 = ClosestPoint(Component_GUILayer, v47);
      v20 = *&v47.x;
      z = v47.z;
      *&v52.x = v20;
      v52.z = z;
      if (op_Equality(v50, v52, 0))
      {
        v23 = v45;
        v24 = b;
        v25 = *&v47.x;
        v26 = v47.z;
        *&v51.x = v25;
        v51.z = v26;
        *&v53.x = v23;
        v53.z = v24;
        v41 = op_Subtraction(v51, v53);
        v27 = sub_8533B0(&v41.x, 0);
        sub_1A1D460(&v43, *&v23, *(&v23 + 1), v24, v27, v28, v29);
        v39 = v43;
        Raycast_8854912(Component_GUILayer, &v39, &v42, 100.0);
        v41.x = sub_874C00(&v42);
        v41.y = v30;
        v41.z = v31;
        v32 = sub_8527D0(&v41.x, 0);
        sub_8529B0(hitpos, 0, v32 * 100.0);
        v41.x = sub_874C00(&v42);
        v41.y = v33;
        v41.z = v34;
        v35 = sub_8527D0(&v41.x, 1);
        sub_8529B0(hitpos, 1, v35 * -100.0);
        v41.x = sub_874C00(&v42);
        v41.y = v36;
        v41.z = v37;
        v38 = sub_8527D0(&v41.x, 2);
        sub_8529B0(hitpos, 2, v38 * 100.0);
      }
    }
  }
  nullsub_48(&v44);
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
  UnityEngine_Object_o *mhfldAnaFile;
  s64 v8;
  s64 v9;
  s64 v11;
  s64 v12;
  UnityEngine_Vector4_o v13;

  v11 = 0;
  v12 = 0;
  sub_854690(&v11, 0.0, 0.0, 0.0, 1.0);
  if (!op_Equality(mhfldAnaFile, 0, 0))
  {
    sub_854930(&v11, 0);
    sub_854930(&v11, 1u);
    sub_854930(&v11, 2u);
    v8 = v11;
    v9 = v12;
    *&v13.x = v8;
    *&v13.z = v9;
    dds3SetPosPoseSet(&fldAnaBasic, v13);
    dds3ObjectBaseOffFlag(&fldAnaBasic, 1u);
    fldSePlay(38);
  }
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
      goto LABEL_39;
    v8 = DDS3_GBWK->unitwork;
    if ((v8->m_Items[v2]->flag & 4) != 0)
      goto LABEL_39;
    v11 = DDS3_GBWK->unitwork;
    if ((v11->m_Items[v2]->flag & 0x10) != 0)
      goto LABEL_39;
    v14 = DDS3_GBWK->unitwork;
    if ((v14->m_Items[v2]->flag & 0x800) != 0)
      goto LABEL_39;
    v17 = DDS3_GBWK->unitwork;
    if (!v17->m_Items[v2]->hp)
      goto LABEL_39;
    if (gFldAnahoriAkumaIdx == v3)
      break;
    ++v3;
LABEL_39:
    if (v2++ >= 0xF)
      return;
  }
  v22 = DDS3_GBWK->unitwork;
  param = v22->m_Items[v2]->param;
  if (param->m_Items[0] < 21)
  {
      goto LABEL_55;
LABEL_53:
    goto LABEL_55;
  }
  evtBitOn(1284);
    goto LABEL_53;
LABEL_55:
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
LABEL_6:
  v2 = 0;
  v3 = 0;
  while (1)
  {
    unitwork = DDS3_GBWK->unitwork;
    if ((unitwork->m_Items[v2]->flag & 1) == 0)
      goto LABEL_42;
    v8 = DDS3_GBWK->unitwork;
    if ((v8->m_Items[v2]->flag & 4) != 0)
      goto LABEL_42;
    v11 = DDS3_GBWK->unitwork;
    if ((v11->m_Items[v2]->flag & 0x10) != 0)
      goto LABEL_42;
    v14 = DDS3_GBWK->unitwork;
    if ((v14->m_Items[v2]->flag & 0x800) != 0)
      goto LABEL_42;
    v17 = DDS3_GBWK->unitwork;
    if (!v17->m_Items[v2]->hp)
      goto LABEL_42;
    if (gFldAnahoriAkumaIdx == v3)
      break;
    ++v3;
LABEL_42:
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
  ++gFldAnahoriAkumaIdx;
  if (gFldAnahoriAkumaIdxMax <= gFldAnahoriAkumaIdx)
  {
    gFldAnahoriAkumaIdx = 0;
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
  bool IsDLCField;
  s64 *v5;
  System_String_o *v6;
  System_String_o *v7;
  System_String_o *v9;
  AssetBundleCtrl_o *asset_bc;
  System_String_o *v11;
  System_String_o *v13;
  System_String_o *v14;
  System_String_o *v15;
  Il2CppObject *v17;
  AssetBundleCtrl_o *v19;
  System_String_o *v20;
  UnityEngine_Object_o *Prefab_16624656;
  AssetBundleCtrl_o *v26;
  System_String_o *v27;
  bool v28;
  System_String_o *v29;
  System_String_o *v31;
  s32 v35;
  s32 v36;

  v35 = area;
  v36 = field;
  IsDLCField = IsDLCField(field);
  v5 = &"m";
  if (!IsDLCField)
    v5 = &"";
  v6 = *v5;
  v7 = sub_232A70(&v36, "D3");
  v9 = Concat_5224608("f", v7);
  asset_bc = get_asset_bc();
  v11 = Concat_5224608(v9, v6);
  if (IsLoad(asset_bc, v11))
  {
    v13 = Concat_5221536("field/f/", v9, v6);
    v14 = sub_232A70(&v35, "D3");
    v15 = Concat_5221536(v9, "_", v14);
    v17 = Concat_5224608("fldDataCheck : ", v15);
    Log(v17, 0);
    v19 = get_asset_bc();
    v20 = Concat_5224608(v9, v6);
    Prefab_16624656 = LoadPrefab_16624656(v19, v20, v13, v15);
    fldDataCheckFlg = 0;
    if (!op_Equality(Prefab_16624656, 0, 0))
      return 1;
    fldDbgPrintStr2DC(84, 240, -65408, "マップデータがありません", 0);
    v26 = get_asset_bc();
    v27 = Concat_5224608(v9, v6);
    UnloadAB(v26, v27);
    return 0;
  }
  else if (fldDataCheckFlg)
  {
    return 0;
  }
  v29 = Concat_5224608(v9, v6);
  v31 = Concat_5224608(v9, v6);
  LoadAssetExt(v29, v31, v6);
  v28 = 0;
  fldDataCheckFlg = 1;
  return v28;
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
    else if (mselGemeMode())
    {
      goto LABEL_20;
    }
    evtBitOn(2802);
    goto LABEL_20;
  }
  dds3GlobalWorkUserInit2(1);
LABEL_20:
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
LABEL_10:
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
  sdfRandomize(&grnd_cb, 0x1E240u);
  fldNpcLoad1st();
  fldSkyDefaultLoad();
  fldAutoMapLoad();
  else
  {
    fldGbTblLoad();
  }
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
  s32 callmode;

  else
  {
    if (fldSceneParam.mode == 1)
      return 1;
  }
  else
  {
    callmode = fldSceneParam.callmode;
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
  return 2 * (fldSceneParam.mode != 0);
}

// 0x10bec50
fldUnitControl_t *fldGetUnitControl(void) {
  return fldUnitControl;
}

// 0x10ba700
dds3Basic_t *fldGetUnitFollowCamera(void) {
LABEL_7:
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
LABEL_12:
}

// 0x10c2640
void fldJDataClear(void) {
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

  if (mhfldPlayerFile)
  {
    mhfldPlayerFile = 0;
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
    goto LABEL_10;
  if (fieldID == 14)
    goto LABEL_10;
LABEL_14:
  if (fieldID > 9)
  {
    fldPlayerALoad();
    gfldPlayerSize = gfldPlayerSizeBk;
    gfldPlayerPtr = v1;
    mhfldPlayerFile = 0;
      goto LABEL_27;
LABEL_11:
    goto LABEL_27;
  }
  fldPlayerALoad();
    goto LABEL_11;
LABEL_27:
  v9 = fldGb->fieldID;
  if (v9 != 21)
  {
    else if (v9 == 26)
    {
      goto LABEL_39;
    }
    if (v9 < 36)
    {
      if ((v6->_2.bitflags2 & 2) == 0)
        goto LABEL_46;
      goto LABEL_36;
    }
  }
LABEL_39:
  asset_bc = get_asset_bc();
  Prefab_16624656 = LoadPrefab_16624656(asset_bc, "fldplayer", "charactor/e/hole", "hole");
  mhfldAnaFile = Prefab_16624656;
  {
LABEL_36:
  }
LABEL_46:
  v13 = fldGb->fieldID;
  if (v13 == 22)
  {
    v14 = get_asset_bc();
    v15 = "f_bin";
    v16 = "charactor/e/suimen_hamon";
    v17 = &"suimen_hamon02";
LABEL_59:
    v19 = LoadPrefab_16624656(v14, v15, v16, *v17);
    mhfldWaveFile = v19;
    return;
  }
  if (v13 == 45)
  {
    v14 = get_asset_bc();
    v15 = "f_bin";
    v16 = "charactor/e/suimen_hamon";
    v17 = &"suimen_hamon";
    goto LABEL_59;
  }
}

// 0x10bd330
s32 fldLightMaChk(void) {
  if ((DDS3_GBWK->stat & 8) != 0)
    return 1;
LABEL_6:
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
LABEL_10:
  DDS3_GBWK->stat &= ~8u;
  fldGb->flag &= ~1u;
  fldGb->flag |= 1u;
}

// 0x10c49c0
s32 fldLightMaIdxCalc(void) {
  fldGlobal_c *v2;
  struct fldGlobalWork_t_o *fldGb;
  s32 areaID;
  s32 v5;
  struct fldGlobalWork_t_o *v6;
  s32 v7;
  _BOOL4 v8;
  s32 v9;
  struct fldGlobalWork_t_o *v10;
  s32 v11;
  _BOOL4 v12;
  struct fldGlobalWork_t_o *v13;

  if (fldGb->fieldID != 21)
  {
    v5 = 100;
    if ((v2->_2.bitflags2 & 2) == 0)
      goto LABEL_29;
    goto LABEL_12;
  }
  if ((v2->_2.bitflags2 & 2) == 0)
  {
    areaID = fldGb->areaID;
    if (areaID == 2)
      v5 = 100;
    else
      v5 = 102;
    goto LABEL_26;
  }
  else
  {
    areaID = fldGb->areaID;
    if (areaID == 2)
      v5 = 100;
    else
      v5 = 102;
      goto LABEL_25;
  }
LABEL_26:
  if (areaID == 23)
    v5 = 101;
  if ((v2->_2.bitflags2 & 2) != 0)
  {
LABEL_12:
  }
LABEL_29:
  v6 = fldGb;
  if (v6->fieldID != 26)
    goto LABEL_45;
  if ((v2->_2.bitflags2 & 2) == 0)
  {
    v7 = v6->areaID;
    v8 = v7 == 18;
LABEL_32:
    v9 = v8 || v7 == 19;
    goto LABEL_42;
  }
  v7 = fldGb->areaID;
  v8 = v7 == 18;
    goto LABEL_32;
  v7 = fldGb->areaID;
  v9 = v8 || v7 == 19;
    goto LABEL_42;
LABEL_41:
  v7 = fldGb->areaID;
LABEL_42:
  if (v9 | (v7 == 21))
    v5 = 101;
  else
    v5 = 102;
LABEL_45:
  v10 = fldGb;
  if (v10->fieldID == 29)
  {
    if ((v2->_2.bitflags2 & 2) == 0)
    {
      v11 = v10->areaID;
      if (v11 == 1)
        v5 = 100;
      else
        v5 = 102;
LABEL_53:
      v12 = v11 == 9;
      goto LABEL_70;
    }
    else
    {
      v11 = fldGb->areaID;
      if (v11 == 1)
        v5 = 100;
      else
        v5 = 102;
        goto LABEL_53;
    }
    v12 = v11 == 9;
      goto LABEL_70;
    goto LABEL_69;
  }
LABEL_72:
  v13 = fldGb;
  if (v13->fieldID != 37)
    return v5;
  if (v13->areaID == 15)
    return 100;
  else
    return v5;
}

// 0x10bd400
void fldLightMaStart(void) {
  struct fldGlobalWork_t_o *fldGb;
  s32 LightMa;

  else if (!gFldNowDZone)
  {
    return;
  }
  else if ((DDS3_GBWK->stat & 8) == 0)
  {
    goto LABEL_9;
  }
  fldGb->LightMa = fldLightMaIdxCalc();
  DDS3_GBWK->stat |= 8u;
  fldGb->flag &= ~1u;
  LightMa = fldGb->LightMa;
  fldSkySetTblLightMa(LightMa, 0);
}

// 0x10c4f90
void fldLightMaTask(void) {
  dds3Basic_t_o *player;
  struct fldGlobalWork_t_o *v8;
  struct fldGlobalWork_t_o *v10;
  s32 LightMa;
  s32 v14;
  s32 v15;
  struct fldGlobalWork_t_o *fldGb;

  else if (!evtGetUnitHandle2(player))
  {
    return;
  }
  if (!gFldNowDZone)
    goto LABEL_47;
LABEL_12:
  if ((DDS3_GBWK->stat & 8) == 0)
  {
    v8 = fldGb;
    if (v8->LightMa)
    {
      v8->LightMa = 0;
      fldSkySetTblLightMa(0, 20);
      fldSePlay(42);
    }
    return;
  }
  v10 = fldGb;
  if (!v10->LightMa)
  {
    v10->LightMa = fldLightMaIdxCalc();
    LightMa = fldGb->LightMa;
    v14 = 20;
    v15 = LightMa;
    goto LABEL_57;
  }
}

// 0x10be470
void fldMainLoadStart(void) {
  fldSceneParam_t_o pParam;

  memset(&pParam, 0, sizeof(pParam));
  sub_F87580(&pParam);
  if (slGetExitType() != 1)
    goto LABEL_6;
}

// 0x10c65f0
void fldOtInit(void) {
  struct fldGlobalWork_t_o *fldGb;
  struct fldGlobalWork_t_o *v4;
  struct fldGlobalWork_t_o *v5;
  struct fldGlobalWork_t_o *v6;
  s32 fieldID;
  struct sdfGrOt_t_array *dds3Ot;
  struct sdfModelOt_t_array *dds3ModelOt;
  u32 max_length;
  struct sdfGrOt_t_array *v13;
  sdfGrOt_t_o *v14;
  struct sdfGrOt_t_array *v15;
  sdfGrOt_t_o *v16;
  sdfGrOt_t_o *v17;
  struct sdfGrOt_t_array *v20;
  struct sdfModelOt_t_array *v21;
  u32 v22;
  struct sdfGrOt_t_array *v23;
  sdfGrOt_t_o *v24;
  struct sdfGrOt_t_array *v25;
  sdfGrOt_t_o *v26;
  sdfGrOt_t_o *v27;
  sdfGrOt_t_o *v31;
  struct sdfModelOt_t_array *v34;
  sdfModelOt_t_o *v36;
  struct sdfGrOt_t_array *v37;
  struct sdfGrOt_t_array *ot;
  s64 *v40;
  struct sdfGrOt_t_array *v43;
  struct sdfModelOt_t_array *v44;
  u32 v45;
  struct sdfGrOt_t_array *v46;
  sdfGrOt_t_o *v47;
  struct sdfGrOt_t_array *v48;
  sdfGrOt_t_o *v49;
  sdfGrOt_t_o *v50;
  sdfGrOt_t_o *v54;
  struct sdfModelOt_t_array *v57;
  sdfModelOt_t_o *v59;
  struct sdfGrOt_t_array *v60;
  sdfGrOt_t_o *v67;

  if (fldGb->fieldID == 42)
  {
    else if (fldGb->areaID == 15)
    {
      goto LABEL_56;
    }
  }
  v4 = fldGb;
  if (v4->fieldID == 43)
  {
    else if (v4->areaID == 8)
    {
      goto LABEL_56;
    }
  }
  v5 = fldGb;
  if (v5->fieldID == 43)
  {
    else if (v5->areaID == 9)
    {
      goto LABEL_56;
    }
  }
  v6 = fldGb;
  if (v6->fieldID != 43)
  {
LABEL_31:
    fieldID = fldGb->fieldID;
    if (fieldID != 32)
    {
      else if (fieldID == 36)
      {
        goto LABEL_79;
      }
      if (fieldID != 37)
      {
        max_length = dds3Ot->max_length;
        v13 = dds3Ot;
        v14 = dds3Ot->m_Items[34];
        v15 = v13;
        v16 = v13->m_Items[40];
        v17 = v15->m_Items[42];
        v67 = v15->m_Items[41];
        sdfModelOtInit(&dds3ModelOt->m_Items[6], v14, v16, v17, v67);
        return;
      }
    }
LABEL_79:
    v43 = dds3Ot;
    v44 = dds3ModelOt;
    v45 = v43->max_length;
    v46 = v43;
    v47 = v43->m_Items[34];
    v48 = v46;
    v49 = v46->m_Items[40];
    v50 = v48->m_Items[42];
    v54 = v48->m_Items[41];
    sdfModelOtInit(&v44->m_Items[6], v47, v49, v50, v54);
    v57 = dds3ModelOt;
    v59 = v57->m_Items[6];
    v60 = dds3Ot;
    ot = v59->ot;
    v40 = v60->m_Items[35];
    if (!v40)
      goto LABEL_100;
    goto LABEL_99;
  }
  else if (v6->areaID != 10)
  {
    goto LABEL_31;
  }
LABEL_56:
  v20 = dds3Ot;
  v21 = dds3ModelOt;
  v22 = v20->max_length;
  v23 = v20;
  v24 = v20->m_Items[34];
  v25 = v23;
  v26 = v23->m_Items[40];
  v27 = v25->m_Items[42];
  v31 = v25->m_Items[41];
  else if (LODWORD(v21->max_length) <= 6)
  {
    goto LABEL_69;
  }
  sdfModelOtInit(&v21->m_Items[6], v24, v26, v27, v31);
  v34 = dds3ModelOt;
  v36 = v34->m_Items[6];
  v37 = dds3Ot;
  ot = v36->ot;
  v40 = v37->m_Items[46];
  if (!v40)
    goto LABEL_100;
LABEL_99:
LABEL_100:
  ot->m_Items[1] = v40;
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
  UnityEngine_Object_o *mhfldPlayerFileBk;
  UnityEngine_Transform_o *v7;
  struct UnityEngine_GameObject_o *v11;
  AssetBundleCtrl_o *v15;
  Il2CppObject *v17;
  UnityEngine_GameObject_o *v18;
  UnityEngine_Transform_o *v20;
  Il2CppObject *v21;
  UnityEngine_GameObject_o *v24;
  FieldChrHD_o *v25;
  AssetBundleCtrl_o *asset_bc;
  Il2CppObject *Prefab_16624656;
  UnityEngine_GameObject_o *v31;
  UnityEngine_Transform_o *transform;
  Il2CppObject *v34;
  UnityEngine_GameObject_o *v37;
  FieldChrHD_o *v38;
  System_String_o *v39;
  AssetBundleCtrl_o *v40;
  Il2CppObject *v41;
  UnityEngine_Transform_o *v42;
  Il2CppObject *v43;
  UnityEngine_GameObject_o *v50;
  s32 v51;
  FieldChrHD_o *v52;
  UnityEngine_Vector3_o v54;

  fldPlayerLoadCheck();
  if (!op_Inequality(mhfldPlayerFileBk, 0, 0))
  {
    if (fldGb->fieldID <= 9)
    {
      v10[2].klass->vtable[4].methodPtr = "mark_wpc";
      asset_bc = get_asset_bc();
      {
      }
      Prefab_16624656 = LoadPrefab_16624656(asset_bc, "fldplayer", FieldWpcFullPath, "mark_wpc");
      v31 = Find("Character", 0);
      transform = get_transform(v31, 0);
      v34 = Instantiate_object__425664(Prefab_16624656, transform, 0);
      mhfldPlayerFileBk = v34;
      v37 = mhfldPlayerFileBk;
      v38 = mdlSetHD(v37, 0, 0, 15);
      v39 = "charactor/b/common/battle_chara_shadow";
      v25 = v38;
      v40 = get_asset_bc();
      v41 = LoadPrefab_16624656(v40, "common", v39, "battle_chara_shadow");
      v42 = get_transform(mhfldPlayerFileBk, 0);
      v43 = Instantiate_object__425664(v41, v42, 0);
      mhfldPlayerFileBkKage = v43;
      SetModelObject(v25, mhfldPlayerFileBk, v43);
      KageSetRenserQueue(v25, 3002);
      KageSet_Size_BlendPower(v25, 0.3, 100.0);
      gWmRotSetOn = 0;
      if (fldGb->fieldID <= 1)
      {
        v52 = v25;
        v50 = mhfldPlayerFileBk;
        v51 = 14;
        goto LABEL_70;
      }
    }
    else
    {
      v11 = fldPlayerALoadForUnity();
      mhfldPlayerFileBk = v11;
      set_name(mhfldPlayerFileBk, "PLAYER_UNIT");
      v15 = get_asset_bc();
      {
      }
      v17 = LoadPrefab_16624656(v15, "fldplayer", FieldCharaCeilingFullPath, "PlayerCeiling");
      v18 = Find("Character", 0);
      v20 = get_transform(v18, 0);
      v21 = Instantiate_object__425664(v17, v20, 0);
      PlayerCeiling = v21;
      SetActive(PlayerCeiling, 0, 0);
      v24 = mhfldPlayerFileBk;
      v25 = mdlSetHD(v24, 0, 0, 15);
      SetModelObject(v25, mhfldPlayerFileBk, 0);
    }
    v50 = mhfldPlayerFileBk;
    v51 = 13;
    v52 = v25;
LABEL_70:
    SetLayerAll2(v52, v50, v51);
    return;
  }
  v7 = get_transform(mhfldPlayerFileBk, 0);
  v54.z = 0.0;
  *&v54.x = 0;
  sub_8524C0(&v54.x, 0.0, 0.0, 0.0);
  set_localPosition(v7, v54);
}

// 0x10bd030
void *fldPlayerALoadForUnity(void) {
  s32 fieldID;
  AssetBundleCtrl_o *asset_bc;
  s64 *v10;
  System_String_o **p_FieldCharactorBFullPath;
  Il2CppObject *Prefab_16624656;
  UnityEngine_GameObject_o *v18;
  UnityEngine_Transform_o *transform;

  fieldID = fldGb->fieldID;
  if (fieldID == 11)
    goto LABEL_10;
  else if (fieldID == 14)
  {
    goto LABEL_10;
  }
  playerPrefab = "player_tatoo";
  asset_bc = get_asset_bc();
  {
  }
  v10 = &"player_tatoo";
  p_FieldCharactorBFullPath = &FieldCharactorAFullPath;
LABEL_42:
  Prefab_16624656 = LoadPrefab_16624656(asset_bc, "fldplayer", *p_FieldCharactorBFullPath, *v10);
  v18 = Find("Character", 0);
  transform = get_transform(v18, 0);
  return Instantiate_object__425664(Prefab_16624656, transform, 0);
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
  playerPrefab = "";
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
    v4 = &"mark_wpc";
    goto LABEL_20;
  }
  else if (fieldID == 11)
  {
    goto LABEL_18;
  }
  else if (fieldID != 14)
  {
LABEL_13:
    v4 = &"player_tatoo";
    goto LABEL_20;
  }
LABEL_18:
  v5 = evtBitCheck(2224);
  v4 = &"player_first2";
  if (v5)
    v4 = &"player_first";
LABEL_20:
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
    goto LABEL_93;
  if (!fldGb->areaID)
    return 1;
LABEL_93:
  v6 = fldGb;
  if (v6->fieldID != 17)
    goto LABEL_94;
  if (v6->areaID == 1)
    return 1;
LABEL_94:
  v7 = fldGb;
  if (v7->fieldID != 17)
    goto LABEL_95;
  if (v7->areaID == 2)
    return 1;
LABEL_95:
  v8 = fldGb;
  if (v8->fieldID != 17)
    goto LABEL_96;
  if (v8->areaID == 3)
    return 1;
LABEL_96:
  v9 = fldGb;
  if (v9->fieldID != 14)
    goto LABEL_97;
  if (v9->areaID == 16)
    return 1;
LABEL_97:
  v10 = fldGb;
  if (v10->fieldID != 15)
    goto LABEL_98;
  if (v10->areaID == 16)
    return 1;
LABEL_98:
  v11 = fldGb;
  if (v11->fieldID != 15)
    goto LABEL_99;
  if (v11->areaID == 9)
    return 1;
LABEL_99:
  v12 = fldGb;
  if (v12->fieldID != 34)
    return 0;
  return !v12->areaID;
}

// 0x10bf3c0
void fldReadyScene(void) {
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  f32 v5;
  f32 v6;
  f32 v7;
  slMain_c *v11;
  f32 v13;
  f32 v14;
  struct dds3AdditionWork_t_o *AdditionWork;
  s32 SeId;
  s32 fieldID;
  s32 areaID;
  u8 WarpIndex;
  s32 CamTableIdx;
  s32 BgmId;
  u8 CamMode;
  s32 v23;
  s64 *v24;
  struct fldSave_t_o *fldSave;
  s32 tmnltype;
  s32 tmnlid;
  s32 AreaToArea;
  s32 loadArea;
  s32 loadField;
  s32 mode;
  dds3Basic_t_o *ControlScene;
  System_String_o *String_5280336;
  System_String_o *v49;
  dds3Basic_t_o *v50;
  Il2CppObject *Resource;
  s64 v52;
  Il2CppClass *element_class;
  char *v54;
  s64 *v55;
  u64 *v57;
  s64 v58;
  s64 v59;
  s64 v60;
  s64 v61;
  struct dds3AdditionWork_t_o *v63;
  f32 v64;
  f32 v65;
  f32 v66;
  f32 v67;
  s32 nameU;
  s32 gFldNowDZone;
  struct datEncountFld_t_array *tbl;
  s64 v79;
  s32 flag;
  bool v82;
  struct fldGlobalWork_t_o *v86;
  struct datEncountFld_t_array *v89;
  s64 v91;
  struct System_Int16_array *Encount2;
  s64 v94;
  struct datEncountFld_t_array *v99;
  s64 v101;
  s32 v105;
  s32 v106;
  s32 RestoreMode;
  struct fldGlobalWork_t_o *fldGb;
  s32 v112;
  struct fldGlobalWork_t_o *v117;
  struct fldGlobalWork_t_o *v118;
  struct fldGlobalWork_t_o *v119;
  struct fldGlobalWork_t_o *v120;
  struct fldGlobalWork_t_o *v121;
  struct fldGlobalWork_t_o *v122;
  struct fldGlobalWork_t_o *v123;
  struct fldGlobalWork_t_o *v124;
  struct fldGlobalWork_t_o *v125;
  struct fldGlobalWork_t_o *v126;
  struct fldGlobalWork_t_o *v127;
  struct fldGlobalWork_t_o *v128;
  struct fldGlobalWork_t_o *v129;
  struct fldGlobalWork_t_o *v130;
  struct fldGlobalWork_t_o *v131;
  struct fldGlobalWork_t_o *v132;
  struct fldGlobalWork_t_o *v133;
  struct fldGlobalWork_t_o *v134;
  s32 v135;
  struct fldGlobalWork_t_o *v138;
  struct fldGlobalWork_t_o *v139;
  struct fldGlobalWork_t_o *v140;
  struct fldGlobalWork_t_o *v141;
  struct fldGlobalWork_t_o *v142;
  struct fldGlobalWork_t_o *v143;
  s32 v150;
  s32 v164;
  f32 v166;
  f32 v167;
  f32 v168;
  f32 v169;
  f32 v170;
  f32 v171;
  fldResourcePoint_t_o v172;
  fldResourcePoint_t_o v173;
  UnityEngine_Vector4_o v174;
  s64 v175;
  s64 v176;
  s64 v177;
  s64 v178;
  fldResourcePoint_t_o dest;
  UnityEngine_Vector4_o v180;
  fldResourcePoint_t_o v181;
  struct UnityEngine_Vector4_o v182;

  memset(&v181, 0, sizeof(v181));
  *&v180.x = 0;
  *&v180.z = 0;
  memset(&dest, 0, sizeof(dest));
  *&v182.x = 0;
  *&v182.z = 0;
  *&v173.pos.x = 0;
  *&v173.pos.z = 0;
  sub_854690(&v173.pos.x, 0.0, 0.0, 0.0, 1.0);
  x = v173.pos.x;
  y = v173.pos.y;
  z = v173.pos.z;
  w = v173.pos.w;
  v177 = 0;
  v178 = 0;
  sub_854690(&v177, 0.0, 0.0, 0.0, 1.0);
  v5 = *&v178;
  v6 = *&v177;
  v7 = *(&v177 + 1);
  v167 = *(&v178 + 1);
  memset(&v181, 0, sizeof(v181));
  v175 = 0;
  v176 = 0;
  sub_854690(&v175, 0.0, 0.0, 0.0, 1.0);
  *&v181.pos.x = v175;
  *&v181.pos.z = v176;
  *&v174.x = 0;
  *&v174.z = 0;
  sub_854690(&v174.x, 0.0, 0.0, 0.0, 1.0);
  v181.rot = v174;
  sub_854690(&v180.x, 0.0, 1.0, 0.0, 1.0);
  sub_F86A10(&dest);
  FilterDelete();
  v170 = v6;
  v171 = w;
  v168 = v7;
  v169 = v5;
  if (fldSceneParam.loadMode != 1)
    goto LABEL_40;
  if (!loadMode)
  {
LABEL_30:
    fldSave = DDS3_GBWK->fldSave;
    tmnltype = fldSave->tmnltype;
    tmnlid = fldSave->tmnlid;
    if (!fldWap_Load(tmnltype, tmnlid, &fldSceneParam))
    {
      v24 = &"Retry Load Map Data1";
      goto LABEL_91;
    }
LABEL_40:
    v23 = 0;
    goto LABEL_41;
  }
LABEL_13:
  v166 = z;
  v13 = y;
  if ((v11->_2.bitflags2 & 2) != 0)
  {
    v14 = x;
  }
  else
  {
    v14 = x;
  }
  SeId = AdditionWork->SeId;
  fieldID = AdditionWork->fieldID;
  areaID = AdditionWork->areaID;
  WarpIndex = AdditionWork->WarpIndex;
  CamTableIdx = AdditionWork->CamTableIdx;
  BgmId = AdditionWork->BgmId;
  CamMode = AdditionWork->CamMode;
  if (fldWap_Suspend(
         fieldID,
         areaID,
         CamTableIdx,
         BgmId,
         SeId,
         WarpIndex | (CamTableIdx << 16) | (CamMode << 8),
         &fldSceneParam,
         0))
  {
    x = v14;
    y = v13;
    z = v166;
    v23 = 1;
LABEL_41:
    AreaToArea = fldGb->AreaToArea;
    loadField = fldSceneParam.loadField;
    loadArea = fldSceneParam.loadArea;
    evtLoadArea(loadField, loadArea);
    dds3SetActiveScene(0);
    mode = fldSceneParam.mode;
    if (mode)
    {
      if (mode == 1)
      {
        memmove(&dest, &fldSceneParam, 0x30u);
        SDF_VU0__LOADVECTOR(v180);
        FromRotation(3.1416);
        SDF_VU0__LOADVECTOR_B(dest.rot);
        Mult();
        SDF_VU0__STOREVECTOR(&dest.rot);
        fldPlayerPosRot_RESTORE();
        nbBgmFadeOut();
      }
      goto LABEL_411;
    }
    ControlScene = dds3GetControlScene();
    String_5280336 = CreateString_5280336(0, fldSceneParam.pointResName);
    v49 = Replace_5267216(String_5280336, " ", "");
    v50 = dds3SceneBasicSearchNameAndType(ControlScene, 0x11u, v49);
    if (v50)
    {
      Resource = dds3PointBasicGetResource(v50);
      v52 = Resource;
      if (!Resource)
        sub_8C38A0();
      element_class = Resource->klass->_1.element_class;
      {
        sub_8FC2C0(element_class, fldResourcePoint_t, &v173);
        if ((LOBYTE(v173.pos.x) & 1) != 0)
          v54 = *&v173.rot.x;
        else
          v54 = &v173.pos.x + 1;
        v55 = sub_8C4940(v54);
      }
      v57 = sub_8D3F90(v52);
      v58 = v57[1];
      *&dest.pos.x = *v57;
      *&dest.pos.z = v58;
      v59 = v57[2];
      v60 = v57[3];
      v61 = v57[5];
      *&dest.scl.x = v57[4];
      *&dest.scl.z = v61;
      *&dest.rot.x = v59;
      *&dest.rot.z = v60;
      if (!v23)
      {
LABEL_109:
        if (fldSceneParam.callmode == 3)
        {
          sub_854710(&dest, 0);
          sub_854930(&v181, 0);
          sub_854710(&dest, 1u);
          sub_854930(&v181, 1u);
          sub_854710(&dest, 2u);
          sub_854930(&v181, 2u);
          memmove(&dest, &fldSceneParam, 0x30u);
          SDF_VU0__LOADVECTOR(v180);
          FromRotation(3.1416);
          SDF_VU0__LOADVECTOR_B(dest.rot);
          Mult();
          SDF_VU0__STOREVECTOR(&dest.rot);
          sub_854710(&dest.rot, 0);
          sub_854930(&v181.rot, 0);
          sub_854710(&dest.rot, 1u);
          sub_854930(&v181.rot, 1u);
          sub_854710(&dest.rot, 2u);
          sub_854930(&v181.rot, 2u);
          sub_854710(&dest.rot, 3u);
          sub_854930(&v181.rot, 3u);
          dest = v181;
        }
        if (fldSceneParam.loadField > 45)
        {
LABEL_160:
          v105 = fldGb->fieldID;
          if (v105 >= 11)
          {
            if (v105 <= 45)
            {
              if (v105 != 39)
                goto LABEL_184;
            }
          }
          v106 = fldGb->fieldID;
          if (v106 == 60)
            goto LABEL_184;
          if (v106 == 61)
          {
LABEL_184:
            RestoreMode = fldGetRestoreMode();
            if (!AreaToArea && RestoreMode != 4)
            {
              if (fldGetRestoreMode() == 5)
              {
                v112 = fldGb->fieldID;
                if (fldGb->fieldOldID != v112)
                {
                    goto LABEL_410;
                  goto LABEL_197;
                }
              }
              else
              {
                if (fldGetRestoreMode() == 2)
                {
                  v117 = fldGb;
                  if (v117->fieldOldID == 40)
                  {
                    if (v117->fieldID == 41)
                      goto LABEL_478;
                  }
                  v118 = fldGb;
                  if (v118->fieldOldID == 40)
                  {
                    if (v118->fieldID == 42)
                      goto LABEL_478;
                  }
                  v119 = fldGb;
                  if (v119->fieldOldID == 40)
                  {
                    if (v119->fieldID == 43)
                      goto LABEL_478;
                  }
                  v120 = fldGb;
                  if (v120->fieldOldID == 40)
                  {
                    if (v120->fieldID == 44)
                      goto LABEL_478;
                  }
                  v121 = fldGb;
                  if (v121->fieldOldID == 40)
                  {
                    if (v121->fieldID == 45)
                      goto LABEL_478;
                  }
                  v122 = fldGb;
                  if (v122->fieldOldID == 41)
                  {
                    if (v122->fieldID == 40)
                      goto LABEL_478;
                  }
                  v123 = fldGb;
                  if (v123->fieldOldID == 41)
                  {
                    if (v123->fieldID == 42)
                      goto LABEL_478;
                  }
                  v124 = fldGb;
                  if (v124->fieldOldID == 42)
                  {
                    if (v124->fieldID == 40)
                      goto LABEL_478;
                  }
                  v125 = fldGb;
                  if (v125->fieldOldID == 42)
                  {
                    if (v125->fieldID == 41)
                      goto LABEL_478;
                  }
                  v126 = fldGb;
                  if (v126->fieldOldID == 42)
                  {
                    if (v126->fieldID == 43)
                      goto LABEL_478;
                  }
                  v127 = fldGb;
                  if (v127->fieldOldID == 43)
                  {
                    if (v127->fieldID == 40)
                      goto LABEL_478;
                  }
                  v128 = fldGb;
                  if (v128->fieldOldID == 43)
                  {
                    if (v128->fieldID == 42)
                      goto LABEL_478;
                  }
                  v129 = fldGb;
                  if (v129->fieldOldID == 43)
                  {
                    if (v129->fieldID == 44)
                      goto LABEL_478;
                  }
                  v130 = fldGb;
                  if (v130->fieldOldID == 44)
                  {
                    if (v130->fieldID == 40)
                      goto LABEL_478;
                  }
                  v131 = fldGb;
                  if (v131->fieldOldID == 44)
                  {
                    if (v131->fieldID == 43)
                      goto LABEL_478;
                  }
                  v132 = fldGb;
                  if (v132->fieldOldID == 44)
                  {
                    if (v132->fieldID == 45)
                      goto LABEL_478;
                  }
                  v133 = fldGb;
                  if (v133->fieldOldID == 45)
                  {
                    if (v133->fieldID == 44)
                      goto LABEL_478;
                  }
                  v134 = fldGb;
                  if (v134->fieldOldID == 45)
                  {
                    if (v134->fieldID == 40)
                    {
LABEL_478:
                      v135 = fldGb->fieldID;
                      fldTitleMiniStart(v135);
                    }
                  }
                }
                if (fldGetRestoreMode() != 2)
                {
                  v138 = fldGb;
                  if (v138->fieldOldID != 32)
                    goto LABEL_405;
                  if (v138->fieldID != 36)
                  {
LABEL_405:
                    v139 = fldGb;
                    if (v139->fieldOldID != 32)
                      goto LABEL_479;
                    if (v139->fieldID != 37)
                    {
LABEL_479:
                      v140 = fldGb;
                      if (v140->fieldOldID != 36)
                        goto LABEL_480;
                      if (v140->fieldID != 32)
                      {
LABEL_480:
                        v141 = fldGb;
                        if (v141->fieldOldID != 36)
                          goto LABEL_481;
                        if (v141->fieldID != 37)
                        {
LABEL_481:
                          v142 = fldGb;
                          if (v142->fieldOldID != 37)
                            goto LABEL_482;
                          if (v142->fieldID != 32)
                          {
LABEL_482:
                            v143 = fldGb;
                            if (v143->fieldOldID != 37)
                              goto LABEL_483;
                            if (v143->fieldID != 36)
                            {
LABEL_483:
                              v112 = fldGb->fieldID;
                                goto LABEL_410;
LABEL_197:
LABEL_410:
                              fldTitleMiniStart(v112);
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
LABEL_411:
          v173 = dest;
          v172 = v173;
          fldSetUnit(&v172);
          fldRegistUnitPad();
          fldSetUnitFollowCamera();
          if (fldSceneParam.mode)
            goto LABEL_415;
          else
          {
            v150 = fldSceneParam.camMode;
            if (v150 == 1)
              goto LABEL_422;
          }
          if (v150 == 2)
          {
            v164 = 3;
          }
          else
          {
            v164 = 0;
          }
          fldGb->cammode = v164;
          if (fldSceneParam.callmode == 3)
          {
            resetCamNormal2();
            goto LABEL_415;
          }
          goto LABEL_467;
        }
        v79 = fldSceneParam.loadField;
        flag = tbl->m_Items[v79]->flag;
        if (flag)
        {
          v82 = evtBitCheck(flag);
          if (v82)
          {
            v86 = fldGb;
            v89 = tbl;
            v91 = fldSceneParam.loadField;
            Encount2 = v89->m_Items[v91]->Encount2;
            v94 = fldSceneParam.loadArea;
            if (v94 < LODWORD(Encount2->max_length))
            {
LABEL_159:
              v86->EncPID = Encount2->m_Items[v94];
              goto LABEL_160;
            }
LABEL_158:
          }
          {
LABEL_149:
            v86 = fldGb;
            v99 = tbl;
            v101 = fldSceneParam.loadField;
            Encount2 = v99->m_Items[v101]->Encount1;
            v94 = fldSceneParam.loadArea;
            if (v94 < LODWORD(Encount2->max_length))
              goto LABEL_159;
            goto LABEL_158;
          }
        }
        else
        {
            goto LABEL_149;
        }
        goto LABEL_149;
      }
    }
    else
    {
      *&dest.pos.z = __PAIR64__(LODWORD(v171), LODWORD(z));
      dest.rot.y = v168;
      dest.rot.x = v170;
      dest.rot.w = v167;
      dest.rot.z = v169;
      *&dest.pos.x = __PAIR64__(LODWORD(y), LODWORD(x));
      dest.scl = v182;
      if (!v23)
        goto LABEL_109;
    }
    v63 = AdditionWork;
    v64 = v63->playerPos.z;
    v65 = v63->playerPos.w;
    *&dest.pos.x = *&v63->playerPos.x;
    *&dest.pos.z = __PAIR64__(LODWORD(v65), LODWORD(v64));
    v66 = v63->playerRot.z;
    v67 = v63->playerRot.w;
    *&dest.rot.x = *&v63->playerRot.x;
    dest.rot.z = v66;
    dest.rot.w = v67;
    nameU = v63->nameU;
    fldAutoMapNameU(nameU);
    fldAutoMapNameD(AdditionWork->nameD);
    fldGb->AmFloor = AdditionWork->AmFloor;
    gFldNowDZone = AdditionWork->gFldNowDZone;
    SDF_VU0__LOADVECTOR(v180);
    FromRotation(3.1416);
    SDF_VU0__LOADVECTOR_B(dest.rot);
    Mult();
    SDF_VU0__STOREVECTOR(&dest.rot);
    goto LABEL_109;
  }
  v24 = &"Retry Load Map Data2";
LABEL_91:
  Log(*v24, 0);
  RetryMapLoad();
}

// 0x10c1010
void fldRegistUnitPad(void) {
  struct fldUnitControl_t_o *fldUnitControl;
  dds3Basic_t_o **p_handle;
  struct dds3Basic_t_o *handle;
  u64 *v8;
  struct fldGlobalWork_t_o *fldGb;
  struct fldGlobalWork_t_o *v11;
  s64 v17;
  f32 w;
  f32 z;
  UnityEngine_Vector4_o v20;
  UnityEngine_Vector4_o v21;

  *&v20.x = 0;
  *&v20.z = 0;
LABEL_7:
  handle = fldUnitControl->handle;
  p_handle = &fldUnitControl->handle;
  if (handle)
  {
    fldProcOnFlag(0x40u);
    if (fldGb->fieldID <= 9)
    {
      fldWapAnimCheck(1);
    }
    v8 = Allocate(dds3MoverBasicObjFunc_t);
    dds3MoverBasicObjFunc_t___ctor(v8, 0, Method_fldMain_fldUnitPad__);
    dds3ObjectBaseSetPrimaryControl(p_handle, v8);
  }
  fldGb->NoEncountCnt = 4;
  if (fldGb->NoInpAmCnt <= 3)
  {
    fldGb->NoInpAmCnt = 4;
  }
  v11 = fldGb;
  if (v11->NoInpPlCnt <= 7)
  {
    v11->NoInpPlCnt = 8;
  }
  fldStatusSet();
  fldGb->ElvIdx = -1;
  fldPlayerCalc_Hit();
  *&v20.x = 0;
  *&v20.z = 0;
  dds3GetPosPoseSet(p_handle);
  SDF_VU0__STOREVECTOR(&v20);
  sub_854710(&v20, 1u);
  sub_854930(&v20, 1u);
  v17 = *&v20.x;
  z = v20.z;
  w = v20.w;
  *&v21.x = v17;
  v21.z = z;
  v21.w = w;
  fldHitChkUnit(v21);
}

// 0x10c34f0
void fldReleaseUnitPad(void) {
  struct fldUnitControl_t_o *fldUnitControl;
  dds3Basic_t_o **p_handle;
  struct dds3Basic_t_o *handle;

LABEL_7:
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
LABEL_10:
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
LABEL_10:
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
  _BOOL4 v2;
  s64 v4;
  UnityEngine_Object_o *v6;
  UnityEngine_GameObject_o *v7;
  UnityEngine_GameObject_o *v8;
  s64 v9;
  s64 v10;
  System_Collections_Generic_Dictionary_Enumerator_TKey__TValue__o v11;

  v2 = sw;
  memset(&v11, 0, sizeof(v11));
  v9 = 0;
  v10 = 0;
  string___GetEnumerator(&v11, FldChar);
  while ((sub_437E50(&v11) & 1) != 0)
  {
    v9 = sub_438060(&v11);
    v10 = v4;
    v6 = sub_1A0C5B0(&v9);
    if (op_Inequality(v6, 0, 0))
    {
      v7 = sub_1A0C5B0(&v9);
      if (((get_activeSelf(v7) ^ v2) & 1) != 0)
      {
        v8 = sub_1A0C5B0(&v9);
        SetActive(v8, v2, 0);
      }
    }
  }
  nullsub_30(&v11);
}

// 0x10c6dc0
void fldSetCharAdd(char *name, void *obj) {
  PropertySheet___Add(FldChar, name, obj);
}

// 0x10c2380
void fldSetCharClr(void) {
  s64 v3;
  UnityEngine_Object_o *v5;
  UnityEngine_Object_o *v7;
  s64 v10;
  s64 v11;
  System_Collections_Generic_Dictionary_Enumerator_TKey__TValue__o v12;

  memset(&v12, 0, sizeof(v12));
  v10 = 0;
  v11 = 0;
  string___GetEnumerator(&v12, FldChar);
  while ((sub_437E50(&v12) & 1) != 0)
  {
    v10 = sub_438060(&v12);
    v11 = v3;
    v5 = sub_1A0C5B0(&v10);
    if (op_Inequality(v5, 0, 0))
    {
      v7 = sub_1A0C5B0(&v10);
      Destroy_27360000(v7);
    }
  }
  nullsub_30(&v12);
  PropertySheet___Clear(FldChar);
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

  if (dds3SearchProcessName("fldProcSequence"))
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

  if (dds3SearchProcessName("fldProcSequence"))
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
  if (dds3SearchProcessName("fldProcSequence"))
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
  if (dds3SearchProcessName("fldProcSequence"))
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
  struct fldUnitControl_t_o *fldUnitControl;
  u64 *v6;
  u32 v8;
  f32 x;
  f32 y;
  f32 z;
  f32 w;
  u32 v14;
  f32 v15;
  f32 v16;
  f32 v17;
  f32 v18;
  dds3Basic_t_o **p_handle;
  dds3Basic_t_o *ControlScene;
  dds3Basic_t_o *v23;
  struct dds3Basic_t_o *v26;
  s64 v32;
  s64 v33;
  Il2CppObject *ModelHandle;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v38;
  s64 *v39;
  f32 v41;
  u32 v46;
  f32 v47;
  f32 v48;
  f32 v49;
  f32 v50;
  f32 v51;
  f32 v52;
  f32 v53;
  f32 v54;
  dds3Basic_t_o **p_handle2;
  dds3Basic_t_o *v58;
  Il2CppObject *v60;
  Il2CppClass *v61;
  s64 v62;
  char *v63;
  s64 *v64;
  struct UnityEngine_GameObject_o *v66;
  UnityEngine_GameObject_o *mhfldPlayerFileM;
  FieldChrHD_o *v70;
  bool v75;
  bool v77;
  u32 v87;
  f32 v88;
  f32 v89;
  f32 v90;
  f32 v91;
  f32 v92;
  f32 v93;
  f32 v94;
  f32 v95;
  dds3Basic_t_o *v97;
  Il2CppObject *v99;
  Il2CppClass *v100;
  s64 v101;
  char *v102;
  s64 *v103;
  struct fldGlobalWork_t_o *fldGb;
  s32 fieldID;
  u64 v116;
  s32 gFldNowDZone;
  UnityEngine_Object_o *mhfldAnaFile;
  u32 v128;
  s64 v129;
  s64 v130;
  f32 v131;
  f32 v132;
  f32 v133;
  f32 v134;
  dds3Basic_t_o *v136;
  Il2CppObject *v139;
  struct dds3Basic_t_o *fldAnaBasic;
  UnityEngine_GameObject_o *v141;
  UnityEngine_Transform_o *transform;
  u32 v147;
  s64 v150;
  s64 v151;
  s64 v152;
  s64 v153;
  s64 v154;
  fldResourcePoint_t_o v155;
  UnityEngine_Vector4_o v156;
  UnityEngine_Vector4_o v157;
  dds3ModelHandle_t_o *aHandle;
  UnityEngine_Vector4_o v159;
  s64 v160;
  s64 v161;
  UnityEngine_Vector4_o v162;
  UnityEngine_Vector4_o p;
  s64 v164;
  s64 v165;
  u64 v166[2];
  char *v167;
  UnityEngine_Vector4_o v168;
  UnityEngine_Vector4_o v169;
  UnityEngine_Vector4_o v170;
  UnityEngine_Vector4_o v171;
  UnityEngine_Vector4_o v172;
  UnityEngine_Vector4_o v173;
  UnityEngine_Vector4_o v174;
  UnityEngine_Vector4_o v175;
  UnityEngine_Vector4_o v176;

  v164 = 0;
  v165 = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v162.x = 0;
  *&v162.z = 0;
  *&v156.x = 0;
  v160 = 0;
  v161 = 0;
  *&v159.x = 0;
  *&v159.z = 0;
  *&v157.z = 0;
  aHandle = 0;
  *&v156.z = 0;
  *&v157.x = 0;
  sub_854690(&v164, 0.0, 0.0, 0.0, 1.0);
  sub_854690(&p.x, 0.0, 0.0, 0.0, 1.0);
  sub_854690(&v162.x, 0.0, 1.0, 0.0, 1.0);
  sub_854690(&v160, 1.0, 1.0, 1.0, 1.0);
  sub_854690(&v159.x, 1.0, -1.0, 1.0, 1.0);
  v6 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v6);
  aHandle = v6;
  sub_854690(&v157.x, 0.0, -10.0, 0.0, 1.0);
  sub_854690(&v156.x, 1.05, 1.05, 1.05, 1.0);
  SDF_VU0__LOADVECTOR(v162);
  FromRotation(3.1416);
  SDF_VU0__LOADVECTOR_B(point->rot);
  Mult();
  SDF_VU0__STOREVECTOR(&p);
  v8 = dds3SerializeID();
  x = point->pos.x;
  y = point->pos.y;
  z = point->pos.z;
  w = point->pos.w;
  v14 = v8;
  v16 = p.x;
  v15 = p.y;
  v17 = p.z;
  v18 = p.w;
  v168.x = x;
  v168.y = y;
  v168.z = z;
  v168.w = w;
  v173.x = v16;
  v173.y = v15;
  v173.z = v17;
  v173.w = v18;
  fldUnitControl->handle = dds3AddUnitObjectBasic(v14, v168, v173);
  p_handle = &fldUnitControl->handle;
  dds3SetBasicName(&fldUnitControl->handle, "PLAYER_UNIT");
  ControlScene = dds3GetControlScene();
  v23 = *p_handle;
  dds3SetActiveUnitSceneBasic(ControlScene, v23);
  v26 = *p_handle;
  player = v26;
  if (l_UseCollision)
  {
    dds3ObjectBaseOffFlag(&fldUnitControl->handle, 0x20u);
  }
  if (fldGb->fieldID <= 9)
  {
    fldJDataLoad();
    dds3ObjectBaseMakeUnit(&fldUnitControl->handle, 2, 4);
    if (fldGb->fieldID == 1)
    {
      dds3UnitObjectBasicSetOt(&fldUnitControl->handle, 7);
    }
    else
    {
      dds3ObjectBaseOnFlag(&fldUnitControl->handle, 0x400u, 0);
    }
  }
  else
  {
    fldJDataLoad();
    dds3ObjectBaseMakeUnit(&fldUnitControl->handle, 2, fldSceneParam.noUnit);
  }
  v32 = v160;
  v33 = v161;
  *&v169.x = v32;
  *&v169.z = v33;
  dds3SetSclPoseSet(&fldUnitControl->handle, v169);
  ModelHandle = dds3ObjectBaseGetModelHandle(&fldUnitControl->handle);
  if (ModelHandle)
  {
    klass = ModelHandle->klass;
    if (ModelHandle->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, v166);
      if ((v166[0] & 1) != 0)
        v38 = v167;
      else
        v38 = v166 + 1;
      v39 = sub_8C4940(v38);
    }
  }
  aHandle = ModelHandle;
  if (fldGb->fieldID <= 9)
  {
    v41 = 30.0;
  }
  else
  {
    v41 = 90.0;
  }
  dds3SetRadiusPoseSet(&fldUnitControl->handle, v41);
  player2 = 0;
  if (!fldPlayerMirAreaChk(fldMain))
    goto LABEL_97;
LABEL_71:
  SDF_VU0__LOADVECTOR(v162);
  FromRotation(3.1416);
  SDF_VU0__LOADVECTOR_B(point->rot);
  Mult();
  SDF_VU0__STOREVECTOR(&p);
  v46 = dds3SerializeID();
  v47 = point->pos.x;
  v48 = point->pos.y;
  v49 = point->pos.z;
  v50 = point->pos.w;
  v52 = p.x;
  v51 = p.y;
  v54 = p.z;
  v53 = p.w;
  v170.x = v47;
  v170.y = v48;
  v170.z = v49;
  v170.w = v50;
  v174.x = v52;
  v174.y = v51;
  v174.z = v54;
  v174.w = v53;
  fldUnitControl->handle2 = dds3AddUnitObjectBasic(v46, v170, v174);
  p_handle2 = &fldUnitControl->handle2;
  dds3SetBasicName(p_handle2, "PLAYER_UNIT2");
  v58 = *p_handle2;
  player2 = v58;
  dds3ObjectBaseMakeUnit(p_handle2, 2, fldSceneParam.noUnit);
  dds3SetSclPoseSet(p_handle2, v159);
  v60 = dds3ObjectBaseGetModelHandle(p_handle2);
  if (v60)
  {
    v61 = v60->klass;
    if (v60->klass->_2.typeHierarchyDepth < v62 || v61->_2.typeHierarchy[v62 - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(v61->_1.element_class, dds3ModelHandle_t, v166);
      if ((v166[0] & 1) != 0)
        v63 = v167;
      else
        v63 = v166 + 1;
      v64 = sub_8C4940(v63);
    }
  }
  aHandle = v60;
  dds3SetRadiusPoseSet(p_handle, 90.0);
  dds3ObjectBaseOnFlag(p_handle, 0x200u, 0);
  v66 = fldPlayerALoadForUnity();
  mhfldPlayerFileM = v66;
  v70 = mdlSetHD(mhfldPlayerFileM, 7, 0, 15);
  SetLayerAll2(v70, mhfldPlayerFileM, 14);
  {
LABEL_94:
  }
LABEL_98:
  player3 = 0;
  v75 = evtBitCheck(2803);
  if (SuspendData->IsRestored)
  {
    v77 = evtBitCheck(2803);
    if (!v77)
    {
      SuspendData->IsRestored = 0;
    }
  }
  else if (SuspendData->IsRestored)
  {
    goto LABEL_110;
  }
  evtBitOff(2803);
  evtBitOff(2804);
    goto LABEL_115;
LABEL_111:
LABEL_115:
  if (fldGb->fieldID == 43 && !evtBitCheck(261))
  {
    switch (fldGb->areaID)
    {
      case 3:
        if (evtBitCheck(1977))
          goto LABEL_139;
        break;
      case 4:
        if (evtBitCheck(1978))
          goto LABEL_139;
        break;
      case 5:
        if (evtBitCheck(1978) || evtBitCheck(1969) && evtBitCheck(1970))
          goto LABEL_139;
        break;
      case 7:
      case 8:
      case 9:
      case 0xA:
        if (evtBitCheck(1979))
          goto LABEL_139;
        break;
      default:
        loadtimer = 0;
        ReleaseChar();
        if (!evtBitCheck(2803))
          goto LABEL_171;
        goto LABEL_140;
    }
    if (!SuspendData->IsRestored)
    {
      evtBitOn(2803);
      evtBitOn(2804);
    }
    fldGb->CamTableIdx = 24;
  }
LABEL_139:
  if (evtBitCheck(2803))
  {
LABEL_140:
    SDF_VU0__LOADVECTOR(v162);
    FromRotation(4.7124);
    SDF_VU0__LOADVECTOR_B(point->rot);
    Mult();
    SDF_VU0__STOREVECTOR(&p);
    v87 = dds3SerializeID();
    v88 = point->pos.x;
    v89 = point->pos.y;
    v90 = point->pos.z;
    v91 = point->pos.w;
    v93 = p.x;
    v92 = p.y;
    v95 = p.z;
    v94 = p.w;
    v171.x = v88;
    v171.y = v89;
    v171.z = v90;
    v171.w = v91;
    v175.x = v93;
    v175.y = v92;
    v175.z = v95;
    v175.w = v94;
    v97 = dds3AddUnitObjectBasic(v87, v171, v175);
    player3 = v97;
    dds3SetBasicName(&player3, "DANTE_UNIT");
    dds3ObjectBaseMakeUnit(&player3, 2, 7);
    dds3SetSclPoseSet(&player3, v156);
    v99 = dds3ObjectBaseGetModelHandle(&player3);
    if (v99)
    {
      v100 = v99->klass;
      if (v99->klass->_2.typeHierarchyDepth < v101
        || v100->_2.typeHierarchy[v101 - 1] != dds3ModelHandle_t)
      {
        sub_8FC2C0(v100->_1.element_class, dds3ModelHandle_t, v166);
        if ((v166[0] & 1) != 0)
          v102 = v167;
        else
          v102 = v166 + 1;
        v103 = sub_8C4940(v102);
      }
    }
    aHandle = v99;
    dds3SetRadiusPoseSet(&player3, 90.0);
    mdlLoopMotion(&aHandle, 0, 3);
    dds3ObjectBaseOffFlag(&player3, 1u);
    dds3SetPosPoseSet(&player3, v157);
    fldRunDanteInit();
      goto LABEL_182;
LABEL_180:
    goto LABEL_182;
  }
LABEL_171:
  fldRunInit();
  if (v75)
  {
    FadeoutBGM("B1100_B1101_BGM01", 0.1);
  }
    goto LABEL_180;
LABEL_182:
  fieldID = fldGb->fieldID;
  if (fieldID > 199)
    goto LABEL_243;
  if (fieldID == 20)
  {
    if (fldGb->areaID == 25)
    {
      FilterDelete();
    }
  }
  fldSkySetTblLightMa(0, 0);
  fldSkySetTbl(fldDbg->SkyTblID, 0);
  fldSkySetTableAnime(fldDbg->SkyTblAnm);
  if ((DDS3_GBWK->stat & 8) != 0)
  {
    if (!*(*(v116 + 184) + 176LL))
    {
      fldGb->LightMa = 0;
      fldSkySetTblLightMa(0, 0);
      fldSkySetTbl(fldDbg->SkyTblID, 0);
      fldSkySetTableAnime(fldDbg->SkyTblAnm);
        goto LABEL_239;
      goto LABEL_230;
    }
    fldLightMaStart(v116);
  }
  else
  {
    {
            v116 = fldMain,
      {
      }
    }
    if (!*(*(v116 + 184) + 176LL))
    {
      fldGb->LightMa = 0;
        goto LABEL_239;
      goto LABEL_230;
    }
  }
  {
LABEL_230:
  }
LABEL_239:
  fldSkySetTblLightMaDZ(gFldNowDZone);
LABEL_243:
  else
  {
    fldPlayerFastSet(fldPlayer);
      goto LABEL_249;
  }
LABEL_249:
  if (op_Inequality(mhfldAnaFile, 0, 0))
  {
    sub_854930(&v164, 0);
    sub_854930(&v164, 1u);
    sub_854930(&v164, 2u);
    sub_854930(&v164, 3u);
    sub_854930(&p, 0);
    sub_854930(&p, 1u);
    sub_854930(&p, 2u);
    sub_854930(&p, 3u);
    v128 = dds3SerializeID();
    v129 = v164;
    v130 = v165;
    v132 = p.x;
    v131 = p.y;
    v134 = p.z;
    v133 = p.w;
    *&v172.x = v129;
    *&v172.z = v130;
    v176.x = v132;
    v176.y = v131;
    v176.z = v134;
    v176.w = v133;
    v136 = dds3AddUnitObjectBasic(v128, v172, v176);
    fldAnaBasic = v136;
    v139 = mhfldAnaFile;
    v141 = Find("Character", 0);
    transform = get_transform(v141, 0);
    fldAnaBasic->gameObject = Instantiate_object__425664(v139, transform, 0);
    SetActive(fldAnaBasic->gameObject, 0, 0);
    set_name(fldAnaBasic->gameObject, "ANA_UNIT");
    dds3ObjectBaseMakeUnit(&fldAnaBasic, 2, 5);
    dds3ObjectBaseOnFlag(&fldAnaBasic, 1u, 0);
    dds3ObjectBaseOnFlag(&fldAnaBasic, 0x100u, 0);
    dds3SetBasicName(&fldAnaBasic, "ANA_UNIT");
  }
  if (fldGb->fieldID >= 11)
  {
    fldWaveInit();
  }
  v147 = dds3SerializeID();
  v150 = *&ppos01Point.pos.z;
  *&v155.pos.x = *&ppos01Point.pos.x;
  *&v155.pos.z = v150;
  v151 = *&ppos01Point.rot.x;
  v152 = *&ppos01Point.rot.z;
  v153 = *&ppos01Point.scl.x;
  v154 = *&ppos01Point.scl.z;
  *&v155.scl.x = v153;
  *&v155.scl.z = v154;
  *&v155.rot.x = v151;
  *&v155.rot.z = v152;
  dds3AddPointBasic(v147, &v155, "ppos01");
}

// 0x10c13b0
void fldSetUnitFollowCamera(void) {
  struct fldFollowCameraControl_t_o *fldFollowCameraControl;
  u32 v4;
  dds3Basic_t_o **p_handle;
  UnityEngine_Vector4_o v10;
  UnityEngine_Vector4_o v11;
  u64 v12[2];
  dds3Basic_t_o *pSceneBasic;
  UnityEngine_Vector4_o v14;

  pSceneBasic = 0;
  v12[0] = 0;
  v12[1] = 0;
  *&v11.x = 0;
  *&v11.z = 0;
  *&v10.x = 0;
  *&v10.z = 0;
  sub_854690(v12, 0.0, 1.0, 0.0, 1.0);
  sub_854690(&v11.x, 0.0, 0.0, 0.0, 1.0);
  sub_854690(&v10.x, 0.0, 0.0, 10.0, 1.0);
  v4 = dds3SerializeID();
  *&v14.x = 0;
  fldFollowCameraControl->handle = dds3AddCameraObjectBasicTypeLookAt(v4, v11, v10, v14);
  p_handle = &fldFollowCameraControl->handle;
  dds3SetBasicName(p_handle, "P_Cam");
  dds3CameraObjectBasicSetTargetPos(p_handle, v10);
  dds3SetRadiusPoseSet(p_handle, 2.0);
  pSceneBasic = dds3GetControlScene();
  dds3SetActiveCameraSceneBasic(&pSceneBasic, p_handle);
  fldSetUnitFollowCameraForUnity();
}

// 0x10c2b70
void fldShutoff(void) {
  dds3Basic_t_o *ControlScene;
  fldMain_c *v8;
  UnityEngine_Vector4_o v11;
  UnityEngine_Vector4_o v12;
  s64 v13;
  s64 v14;
  dds3Basic_t_o *pBasic;

  v13 = 0;
  v14 = 0;
  *&v12.x = 0;
  *&v12.z = 0;
  *&v11.x = 0;
  *&v11.z = 0;
  pBasic = 0;
LABEL_7:
  if (fldUnitControl->handle)
  {
    else if ((byte_3F58918 & 1) != 0)
    {
LABEL_15:
      pBasic = fldUnitControl->handle;
      ControlScene = dds3GetControlScene();
      if (ControlScene)
      {
        memmove(&v11, &fldSceneParam, 0x30u);
        dds3GetPosPoseSet(&pBasic);
        SDF_VU0__STOREVECTOR(&v11);
        dds3GetRotPoseSet(&pBasic);
        SDF_VU0__STOREVECTOR(&v12);
        memmove(&fldSceneParam, &v11, 0x30u);
      }
      else if ((byte_3F58918 & 1) != 0)
      {
LABEL_33:
        else
        {
          fldUnitControl->handle = 0;
        }
        if ((v8->_2.bitflags2 & 2) != 0)
          goto LABEL_37;
        goto LABEL_47;
      }
      goto LABEL_33;
    }
    goto LABEL_15;
  }
}

// 0x10c3d40
s32 fldUnitPad(dds3PoseSet_t *pUpdatePoseSet, dds3Basic_t *pBasic) {
  return 0;
}

// 0x10bdca0
void fldWaveInit(void) {
  UnityEngine_Object_o *mhfldWaveFile;
  u64 v5;
  struct fldWave_tag_array *fldWaveBuff;
  u32 *v12;
  u64 *v13;
  struct fldWave_tag_array *v15;
  struct fldWave_tag_array *v17;
  struct fldWave_tag_array *v19;
  struct fldWave_tag_array *v21;
  fldWave_tag_o *v23;
  u32 v24;
  s64 v26;
  s64 v27;
  u32 v28;
  s64 v29;
  s64 v30;
  struct fldWave_tag_array *v32;
  Il2CppClass **v34;
  Il2CppObject *v35;
  u64 *data;
  UnityEngine_GameObject_o *v37;
  UnityEngine_Transform_o *transform;
  struct fldWave_tag_array *v40;
  u64 *v42;
  System_String_o *v43;
  struct fldWave_tag_array *v44;
  System_String_o *v45;
  struct fldWave_tag_array *v47;
  struct fldWave_tag_array *v49;
  struct fldWave_tag_array *v51;
  s32 v53;
  s64 v54;
  s64 v55;
  s64 v56;
  s64 v57;
  UnityEngine_Vector4_o v58;
  UnityEngine_Vector4_o v59;

  v56 = 0;
  v57 = 0;
  v54 = 0;
  v55 = 0;
  sub_854690(&v56, 0.0, 0.0, 0.0, 1.0);
  sub_854690(&v54, 0.0, 0.0, 0.0, 1.0);
  if (!op_Equality(mhfldWaveFile, 0, 0))
  {
    v5 = 0;
    while (1)
    {
      if (!fldWaveBuff->m_Items[v5])
        break;
        goto LABEL_18;
LABEL_29:
      v15 = fldWaveBuff;
      v15->m_Items[v5]->use = 0;
      v17 = fldWaveBuff;
      v17->m_Items[v5]->cnt = 0;
      v19 = fldWaveBuff;
      v19->m_Items[v5]->pBasic = 0;
      v21 = fldWaveBuff;
      v23 = v21->m_Items[v5];
      v24 = dds3SerializeID();
      v26 = v56;
      v27 = v57;
      v28 = v24;
      v29 = v54;
      v30 = v55;
      *&v58.x = v26;
      *&v58.z = v27;
      *&v59.x = v29;
      *&v59.z = v30;
      v23->pBasic = dds3AddUnitObjectBasic(v28, v58, v59);
      v32 = fldWaveBuff;
      v34 = &v32->obj.klass + v5;
      v35 = mhfldWaveFile;
      data = v34[4]->_1.byval_arg.data;
      v37 = Find("Character", 0);
      transform = get_transform(v37, 0);
      data[16] = Instantiate_object__425664(v35, transform, 0);
      v40 = fldWaveBuff;
      SetActive(v40->m_Items[v5]->pBasic->gameObject, 0, 0);
      v53 = v5;
      v42 = sub_8D3950(s32, &v53);
      v43 = Format("WAVE_UNIT{0:D2}", v42, 0);
      v44 = fldWaveBuff;
      v45 = v43;
      set_name(v44->m_Items[v5]->pBasic->gameObject, v43);
      v47 = fldWaveBuff;
      dds3SetBasicName(&v47->m_Items[v5]->pBasic, v45);
      v49 = fldWaveBuff;
      dds3ObjectBaseMakeUnit(&v49->m_Items[v5]->pBasic, 2, 27);
      v51 = fldWaveBuff;
      dds3ObjectBaseOnFlag(&v51->m_Items[v5++]->pBasic, 1u, 0);
      if (v5 == 40)
        return;
    }
    v12 = fldWaveBuff;
    v13 = Allocate(fldWave_tag);
    _ctor(v13, 0);
    *&v12[2 * v5 + 8] = v13;
      goto LABEL_29;
LABEL_18:
    goto LABEL_29;
  }
}

// 0x10c3850
void fldWaveStart(f32 x, f32 y, f32 z) {
  UnityEngine_Object_o *mhfldWaveFile;
  s64 i;
  u64 v10;
  struct fldWave_tag_array *fldWaveBuff;
  struct fldWave_tag_array *v14;
  struct fldWave_tag_array *v16;
  struct fldWave_tag_array *v19;
  dds3Basic_t_o **v21;
  s64 v22;
  s64 v23;
  struct fldWave_tag_array *v24;
  s64 v26;
  s64 v27;
  UnityEngine_Vector4_o v28;

  v26 = 0;
  v27 = 0;
  sub_854690(&v26, 0.0, 0.0, 0.0, 1.0);
  if (!op_Equality(mhfldWaveFile, 0, 0))
  {
    for (i = 4; ; ++i)
    {
      v10 = i - 4;
      if (!*(*(&fldWaveBuff->obj.klass + i) + 16LL))
        break;
      if (v10 >= 0x27)
        return;
    }
    v14 = fldWaveBuff;
    *(*(&v14->obj.klass + i) + 16LL) = 1;
    v16 = fldWaveBuff;
    *(*(&v16->obj.klass + i) + 20LL) = 0;
    sub_854930(&v26, 0);
    sub_854930(&v26, 1u);
    sub_854930(&v26, 2u);
    v19 = fldWaveBuff;
    v21 = (*(&v19->obj.klass + i) + 32LL);
    v22 = v26;
    v23 = v27;
    *&v28.x = v22;
    *&v28.z = v23;
    dds3SetPosPoseSet(v21, v28);
    v24 = fldWaveBuff;
    dds3ObjectBaseOffFlag((*(&v24->obj.klass + i) + 32LL), 1u, 0);
  }
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
