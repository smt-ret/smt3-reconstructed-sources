#include "types.h"

typedef struct AnimCheckerPMV AnimCheckerPMV;
typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct AssetBundles AssetBundles;
typedef struct EventEMsgData EventEMsgData;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3Effect_Blur_t dds3Effect_Blur_t;
typedef struct dds3Effect_DistortionBlurParam_t dds3Effect_DistortionBlurParam_t;
typedef struct dds3Effect_Filter_t dds3Effect_Filter_t;
typedef struct dds3Effect_PartialMultiBlurParam_t dds3Effect_PartialMultiBlurParam_t;
typedef struct dds3Effect_PartialMultiFilterParam_t dds3Effect_PartialMultiFilterParam_t;
typedef struct dds3Effect_RippleBlurParam_t dds3Effect_RippleBlurParam_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ObjectBaseControlWorkData_t dds3ObjectBaseControlWorkData_t;
typedef struct dds3PathBasicControl_t dds3PathBasicControl_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct dds3SceneBasic_t dds3SceneBasic_t;
typedef struct evtPolygonMovie_FrameRunStruct evtPolygonMovie_FrameRunStruct;
typedef struct evtPolygonMovie_FrameRunStruct_funcDelegate evtPolygonMovie_FrameRunStruct_funcDelegate;
typedef struct evtPolygonMovie_PM2Class evtPolygonMovie_PM2Class;
typedef struct evtPolygonMovie_sLoadMode evtPolygonMovie_sLoadMode;
typedef struct evtTexManager evtTexManager;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;
typedef struct pmdCameraTable_t pmdCameraTable_t;
typedef struct pmdCutInfo_t pmdCutInfo_t;
typedef struct pmdEffectTable_t pmdEffectTable_t;
typedef struct pmdFrameTable_t pmdFrameTable_t;
typedef struct pmdHeader_t pmdHeader_t;
typedef struct pmdProcessWork_t pmdProcessWork_t;
typedef struct pmdSceneFogTable_t pmdSceneFogTable_t;
typedef struct pmdSceneLightTable_t pmdSceneLightTable_t;
typedef struct pmdStageTable_t pmdStageTable_t;
typedef struct pmdTypeTable_t pmdTypeTable_t;
typedef struct pmdUnitTable_t pmdUnitTable_t;

struct evtPolygonMovie_FrameRunStruct {
    evtPolygonMovie_FrameRunStruct_funcDelegate *func;
};

struct evtPolygonMovie_sLoadMode {
    s32 cutno;
    char *FldName;
    void *ChrName;
};

struct evtPolygonMovie_PM2Class {
    pmdHeader_t *header;
    pmdTypeTable_t *typetable;
    pmdCutInfo_t *cutinfo;
};

static s32 MSGTRG;
static void *replace_list;
static s32 CurrentEventNo;
static void *EventCTree;
static void *EventFTree;
static void *EventID;
static void *LoadMode;
static dds3Basic_t *nowcamera;
static f32 nowfovy;
static s32 CameraFrameFunc_nowframe;
static u8 *EffDat;
static pmdSceneLightTable_t *SLightFrameFunc_sl;
static pmdSceneFogTable_t *SFogFrameFunc_sf;
static dds3Effect_Blur_t *Blur2FrameFunc_bl2;
static dds3Effect_PartialMultiBlurParam_t *MBlurFrameFunc_mbl;
static dds3Effect_DistortionBlurParam_t *DBlurFrameFunc_dbl;
static dds3Effect_RippleBlurParam_t *RBlurFrameFunc_rbl;
static dds3Effect_PartialMultiFilterParam_t *MFilterFrameFunc_mfl;
static dds3Effect_Filter_t *FilterFrameFunc_fl;
static evtPolygonMovie_FrameRunStruct *framefunc;
static void *PMchkname;
static void *UnitList;
static s32 Last_wdata_NowFrame;
static u8 pm2_dummydata[64];

dds3Basic_t *AddEffect(pmdProcessWork_t *wdata, pmdFrameTable_t *f);
s32 AddEffectTable(s32 now, pmdProcessWork_t *wdata, pmdFrameTable_t *f, char *effname, char *targetname, s32 posindex, s32 cutno);
s32 AddEffectTableMG12(s32 now, pmdProcessWork_t *wdata, pmdFrameTable_t *f);
void AttachHD(void *obj, dds3Basic_t *basic, char *name, s32 cb);
s32 AttachModel_26586560(dds3Basic_t *basic, char *key, char *chkname, char *name);
void BillSetPB(s32 index);
void BillSetTexture(evtTexManager *this);
s32 CheckLoad(nbMainProcessData_t **data);
void ClrDrawFlag(u32 flag);
u64 DDS3EFFECT_BLEND_ADD(void);
u64 DDS3EFFECT_BLEND_SEMI(void);
u32 DDS3_GETBASICTYPEL(dds3Basic_t *pAreaBasic);
void DelEffectTable(s32 no);
void DeletePB(bool unload);
void Destroy(evtTexManager *this, bool unload);
void DispAnimation(pmdProcessWork_t *wdata);
void Eve_BlurOFF(void);
void Eve_BlurON(void);
void Eve_BlurSetParam(dds3Effect_Blur_t *pParam);
void Eve_DistortionBlurOFF(void);
void Eve_DistortionBlurON(void);
void Eve_DistortionBlurSetParam(dds3Effect_DistortionBlurParam_t *pParam);
void Eve_FilterOFF(void);
void Eve_FilterON(void);
void Eve_FilterSetParam(dds3Effect_Filter_t *pParam);
void Eve_PartialMultiBlurOFF(void);
void Eve_PartialMultiBlurON(void);
void Eve_PartialMultiBlurSetParam(dds3Effect_PartialMultiBlurParam_t *pParam);
void Eve_PartialMultiFilterOFF(void);
void Eve_PartialMultiFilterON(void);
void Eve_PartialMultiFilterSetParam(dds3Effect_PartialMultiFilterParam_t *pParam);
void Eve_RippleBlurOFF(void);
void Eve_RippleBlurON(void);
void Eve_RippleBlurSetParam(dds3Effect_RippleBlurParam_t *pParam);
dds3ProcessID_t *EvtStartPMDuplicate(s32 priority, void *pr, s32 eventno, s32 cutno);
void FinalDanteEventMsg(void);
void FrameRun(pmdProcessWork_t *wdata);
void FrameTableOverWrite(pmdProcessWork_t *wdata);
void *GetAnimator(void *obj);
char *GetDLCTag(s32 eventno);
EventEMsgData *GetData(char *key);
s32 GetPibIndex(u8 **bData, s32 bPos);
bool Get_Skip_PM_Sky(s32 idx, s32 alp, s32 flame);
void InitDanteEventMsg(void);
void Initialize(evtTexManager *this, char *key, char *path);
void InitializeReplaceList(s32 event_no);
bool IsLoad(AssetBundles *this, char *key);
bool IsStartModelLoaded(void);
void Load(char *key, char *filePath);
void LoadEventModel(void);
u8 **LoadFileByte(AssetBundleCtrl *this, char *key, char *path_name);
void LoadKeys(s32 type, char *key, char *path);
void Log(char *fmt, void **parray);
void MarkPibIndex(u8 ***bData);
void MarkTmxIndex(u8 ***bData);
void PriChrHDSet(void *obj);
void RemoveKeys(s32 type, char *key);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__COPYVECTOR_A_TO_B(void);
f32 SDF_VU0__GETVECTOR_W(void);
f32 SDF_VU0__GETVECTOR_X(void);
f32 SDF_VU0__GETVECTOR_Y(void);
f32 SDF_VU0__GETVECTOR_Z(void);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__SCALEVECTOR(f32 v);
void SDF_VU0__SCALEVECTOR_B(f32 v);
void SDF_VU0__SETVECTOR_W(f32 v);
void SDF_VU0__SETVECTOR_X(f32 v);
void SDF_VU0__SETVECTOR_Y(f32 v);
void SDF_VU0__SETVECTOR_Z(f32 v);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__VECTOR_W_SET_ONE(void);
u32 SDF_VU0__dds3ColorFtoI(f32 ratio);
void SDF_VU0__dds3ColorItoF(u32 rgba);
dds3Basic_t *SearchBasicFromNameIndex(s32 nameindex);
void SetDrawFlag(u32 flag, u32 cnt);
void SetEventNo(s32 event_no);
void SetFrame(AnimCheckerPMV *this, s32 frame, bool linkage);
void SetPMFileName(s32 eventno, s32 cutno, char **pm1file, char **pm2file);
void SetShadowMode(dds3DefaultMain *this, s32 mode);
void SpEvtUnloadAll(s32 eventno);
void StartAnimation(pmdProcessWork_t *wdata);
void SwitchAnimation(pmdProcessWork_t *wdata, bool sw);
void UnityEx_SetPM_NowCamera(void);
void UpdateDying(void *plyobj);
void _mdlHide(pmdProcessWork_t *wdata, dds3ModelHandle_t *mdl);
void _mdlShow(pmdProcessWork_t *wdata, dds3ModelHandle_t *mdl);
void attach(dds3Basic_t *basic, void *obj);
void billAlfRaitoSet(f32 raito);
void billBriRaitoSet(f32 raito);
void billCutRaitoSet(f32 raito);
dds3Basic_t *dds3AddBEDEffectObjectBasic2(void *data, sdfVector4_t pos, sdfVector4_t rot);
dds3Basic_t *dds3AddD3PEffectObjectBasic2(void *effdata, sdfVector4_t pos, sdfVector4_t rot);
dds3Basic_t *dds3AddMG12EffectObjectBasic2(s32 type, void *effdata);
dds3ObjectBaseControlWorkData_t *dds3CameraObjectBasicGetControlWorkData(dds3Basic_t **pBasic);
void dds3DeleteSceneBasicData(dds3Basic_t **basic);
s32 dds3EffectObjectBasicLinkObject(dds3Basic_t **basic, dds3Basic_t **target);
s32 dds3EffectObjectBasicLinkObjectIndex(dds3Basic_t **basic, dds3Basic_t **target, s32 index);
void dds3EffectObjectBasicStatOn(dds3Basic_t **basic, u32 s);
void dds3EffectObjectPresetMG12(dds3Basic_t **eff);
s32 dds3EffectObjectSetMG12Pos(dds3Basic_t **eff, dds3Basic_t **p1, dds3Basic_t **p2, dds3Basic_t **p3, dds3Basic_t **p4);
void dds3Effect_Blur_t__SetData(dds3Effect_Blur_t *this, u8 **data, s32 *pos);
void dds3Effect_DistortionBlurParam_t__Clear(dds3Effect_DistortionBlurParam_t *this);
void dds3Effect_DistortionBlurParam_t__SetData(dds3Effect_DistortionBlurParam_t *this, u8 **data, s32 *pos);
void dds3Effect_Filter_t__Clear(dds3Effect_Filter_t *this);
void dds3Effect_Filter_t__SetData(dds3Effect_Filter_t *this, u8 **data, s32 *pos);
void dds3Effect_PartialMultiBlurParam_t__Clear(dds3Effect_PartialMultiBlurParam_t *this);
void dds3Effect_PartialMultiBlurParam_t__SetData(dds3Effect_PartialMultiBlurParam_t *this, u8 **data, s32 *pos);
void dds3Effect_PartialMultiFilterParam_t__Clear(dds3Effect_PartialMultiFilterParam_t *this);
void dds3Effect_PartialMultiFilterParam_t__SetData(dds3Effect_PartialMultiFilterParam_t *this, u8 **data, s32 *pos);
void dds3Effect_RippleBlurParam_t__Clear(dds3Effect_RippleBlurParam_t *this);
void dds3Effect_RippleBlurParam_t__SetData(dds3Effect_RippleBlurParam_t *this, u8 **data, s32 *pos);
void dds3FadeIn(u32 r, u32 g, u32 b, u32 frame);
void dds3FadeOut(u32 r, u32 g, u32 b, u32 frame);
dds3Basic_t *dds3GetActiveScene(void);
dds3ObjectBaseControlWorkData_t *dds3GetBaseControlWorkData(dds3Basic_t **pObjectBasic);
dds3Basic_t *dds3GetControlScene(void);
s32 dds3GetMapNo(dds3Basic_t **scene);
void *dds3GetProcessData(dds3ProcessID_t **id);
evtUnitHandle_t *dds3GetUnitHandleObjectBasic(dds3Basic_t **b);
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
void dds3MoverBasicMakePath(dds3Basic_t **pMoverBasic);
void dds3MoverBasicSetPath(dds3Basic_t **pMoverBasic, dds3Basic_t **pPathBasic);
void dds3ObjectBaseOffFlag(dds3Basic_t **pObjectBasic, u32 flag);
void dds3ObjectBaseOnFlag(dds3Basic_t **pObjectBasic, u32 flag, bool alock);
void dds3PathBasicControlSetRatio(dds3PathBasicControl_t **pControl, f32 ratio);
void dds3PathBasicPause(dds3PathBasicControl_t **pControl);
void dds3PathBasicPauseOff(dds3PathBasicControl_t **pControl);
dds3Basic_t *dds3SceneBasicSearchName(dds3Basic_t **scene, char *name);
dds3Basic_t *dds3SceneBasicSearchNameAndType_(dds3SceneBasic_t *scene, u32 type, char *name);
dds3Basic_t *dds3SetActiveCameraSceneBasic(dds3Basic_t **pSceneBasic, dds3Basic_t **pCameraBasic);
void dds3SetAmbientColor(u32 frame, sdfVector4_t col);
void dds3SetFogPara(u32 frame, f32 max, f32 min, f32 near, f32 far);
void dds3SetLightColor(u32 frame, u32 no, sdfVector4_t col);
void dds3SetLightDir(u32 frame, u32 no, sdfVector4_t dir);
void dds3SetProcessData(dds3ProcessID_t **id, void *data);
void dds3SetQuake(s32 frame, u32 range);
void dds3SetScreenFovy(f32 fovy);
void dds3StartBEDEffectObjectBasic(dds3Basic_t **basic, u32 cutno);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void dds3StopQuake(void);
bool evtBitCheck(s32 no);
void evtEffectLoopControl(dds3Basic_t *eff, s32 sw);
s32 evtFadeInBgm(s32 eventno, s32 bgmno);
s32 evtFadeOutBgm(s32 eventno, s32 bgmno);
void evtFreePolygonMovieWorkData(pmdProcessWork_t *wdata);
pmdProcessWork_t *evtGetPolygonMovieWorkData1(pmdProcessWork_t *wdata, u8 **pm1data, u8 **pm2data);
evtUnitHandle_t *evtGetUnitHandle2(dds3Basic_t *unit);
void evtHokanBlur2(s32 hokan, f32 ratio, dds3Effect_Blur_t *key1, dds3Effect_Blur_t *key2, dds3Effect_Blur_t **d);
void evtHokanDistBlur(s32 hokan, f32 ratio, dds3Effect_DistortionBlurParam_t *key1, dds3Effect_DistortionBlurParam_t *key2, dds3Effect_DistortionBlurParam_t **d);
void evtHokanFilter(s32 hokan, f32 ratio, dds3Effect_Filter_t *key1, dds3Effect_Filter_t *key2, dds3Effect_Filter_t **d);
void evtHokanMultBlur(s32 hokan, f32 ratio, dds3Effect_PartialMultiBlurParam_t *key1, dds3Effect_PartialMultiBlurParam_t *key2, dds3Effect_PartialMultiBlurParam_t **d);
void evtHokanMultFilter(s32 hokan, f32 ratio, dds3Effect_PartialMultiFilterParam_t *key1, dds3Effect_PartialMultiFilterParam_t *key2, dds3Effect_PartialMultiFilterParam_t **d);
void evtHokanRipBlur(s32 hokan, f32 ratio, dds3Effect_RippleBlurParam_t *key1, dds3Effect_RippleBlurParam_t *key2, dds3Effect_RippleBlurParam_t **d);
void evtHokanSceneFog(s32 hokan, f32 ratio, pmdSceneFogTable_t *key1, pmdSceneFogTable_t *key2, pmdSceneFogTable_t **d);
void evtHokanSceneLight(s32 hokan, f32 ratio, pmdSceneLightTable_t *key1, pmdSceneLightTable_t *key2, pmdSceneLightTable_t **d);
void evtLinkLightObjectBasic(evtUnitHandle_t **h, dds3Basic_t **light, s32 frame);
s32 evtLoadArea_FromMemory(s32 fld, s32 area, u8 **pF1, u8 **pF2, u8 **pTB, u8 **pBF);
s32 evtPathLinkAndMake(dds3Basic_t *path, dds3Basic_t *obj);
s32 evtPlayBgm(s32 eventno, s32 bgmno);
s32 evtPlaySe(s32 eventno, s32 seno);
void evtRunUnitMode(pmdProcessWork_t *wdata, dds3Basic_t *unit, s32 mode);
void evtSetBokasi(s32 sw);
s32 evtSetRegistUnit(s32 major, s32 minor);
void evtSetSkyAlpha(s32 frame, s32 a);
void evtStopMover(dds3Basic_t *mover, s32 sw, s32 baseframe, s32 nowframe);
void evtTransBgm(s32 eventno, s32 bgmno);
void evtUnlinkLightObjectBasic(evtUnitHandle_t **h, s32 frame);
void fldFreeNextFile(void);
void fldSetCharClr(void);
void fldSkySetFilter(s32 idx, s32 mode, s32 hokan);
void itfMesMngRelease(s32 id);
void mdlShow(dds3ModelHandle_t *mdl);
void mdlSmoothSingleMotion(dds3ModelHandle_t **aHandle, s32 aGroup, s32 aNumber, f32 aBeforeLeng, f32 aSmoothLeng);
void p2sdBGMStopAll(void);
void p2sdBGMVolHalfDown(void);
void p2sdBGMVolHalfUp(void);
void pmdCameraTable_t__SetData(pmdCameraTable_t *this, u8 **data, s32 *pos);
void pmdCutInfo_t__SetData(pmdCutInfo_t *this, u8 **data, s32 *pos);
void pmdEffectTable_t__SetData(pmdEffectTable_t *this, u8 **data, s32 *pos);
void pmdFrameTable_t__SetData(pmdFrameTable_t *this, u8 **d, s32 *p);
void pmdHeader_t__SetData(pmdHeader_t *this, u8 **data, s32 *pos);
void pmdSceneFogTable_t__SetData(pmdSceneFogTable_t *this, u8 **data, s32 *pos);
void pmdSceneLightTable_t__SetData(pmdSceneLightTable_t *this, u8 **data, s32 *pos);
void pmdStageTable_t__SetData(pmdStageTable_t *this, u8 **data, s32 *pos);
void pmdTypeTable_t__SetData(pmdTypeTable_t *this, u8 **data, s32 *pos);
void pmdUnitTable_t__SetData(pmdUnitTable_t *this, u8 **data, s32 *pos);
void read_module(evtPolygonMovie_sLoadMode *mode, pmdProcessWork_t *wdata, void *ChrObj, void *FldObj);
void read_module_17851248(pmdProcessWork_t *wdata);

// 0x10f7b90
dds3Basic_t *AddEffect(pmdProcessWork_t *wdata, pmdFrameTable_t *f) {
  struct pmdNameTable_t_array *NameTable2;
  System_String_o *Name;
  s64 v8;
  struct pmdEffectTable_t_array *EffectTable;
  struct pmdNameTable_t_array *NameTable1;
  u32 v11;
  s64 v13;
  s64 v16;
  s32 v17;
  struct pmdDataInfo_t_array *Data;
  struct pmdEffectTable_t_array *v21;
  s32 v24;
  struct System_Byte_array *EffDat;
  System_Array_o *UnitData;
  s32 v32;
  struct System_Byte_array *v35;
  struct pmdEffectTable_t_array *v37;
  s32 EventNo;
  System_Array_o *v41;
  struct pmdEffectTable_t_array *v42;
  s32 v44;
  System_Byte_array *v47;
  s32 v48;
  u64 *v49;
  System_String_o *v50;
  System_Object_array *v52;
  s32 PibIndex;
  UnityEngine_Vector4_o v57;
  dds3Basic_t_o *basic;
  UnityEngine_Vector4_o zero;

  *&v57.x = 0;
  *&v57.z = 0;
  basic = 0;
  zero = get_zero();
  sub_854690(&v57.x, 0.0, 0.0, 0.0, 1.0);
  basic = 0;
  NameTable2 = wdata->NameTable2;
  if (wdata->EffectCount < 1)
  {
LABEL_16:
    v17 = 0;
LABEL_17:
    if (basic)
    {
LABEL_18:
      dds3EffectObjectBasicStatOn(&basic, 1u);
      if (v17 == 1)
      {
        Data = f->Data;
        dds3StartBEDEffectObjectBasic(&basic, SLOBYTE(Data->m_Items[0].i), 0);
      }
    }
    return basic;
  }
  Name = NameTable2->m_Items[f->NameIndex]->Name;
  v8 = 4;
  while (1)
  {
    EffectTable = wdata->EffectTable;
    NameTable1 = wdata->NameTable1;
    v11 = v8 - 4;
    v13 = *(*(&EffectTable->obj.klass + v8) + 16LL);
    if (!Compare_5253904(Name, NameTable1->m_Items[v13]->Name, 4))
      break;
    v16 = v8 - 3;
    ++v8;
    if (v16 >= wdata->EffectCount)
      goto LABEL_16;
  }
  v21 = wdata->EffectTable;
  v17 = *(*(&v21->obj.klass + v8) + 24LL);
  v24 = LODWORD(wdata->UnitData->max_length) - *(*(&wdata->EffectTable->obj.klass + v8) + 20LL);
  else
  {
    if (EffDat)
    {
LABEL_28:
      else if (v24 > SLODWORD(EffDat->max_length))
      {
        goto LABEL_31;
      }
      v41 = wdata->UnitData;
      v42 = wdata->EffectTable;
      v44 = *(*(&v42->obj.klass + v8) + 20LL);
      BlockCopy(v41, v44, EffDat, 0, v24);
      EventNo = wdata->EventNo;
      if (EventNo == 661)
        goto LABEL_45;
LABEL_58:
      if (EventNo != 726)
      {
LABEL_64:
        if (EventNo == 673)
        {
          billCutRaitoSet(30.0);
          EventNo = wdata->EventNo;
        }
        if (EventNo == 723)
        {
          billAlfRaitoSet(3.0);
          billCutRaitoSet(20.0);
        }
        goto LABEL_74;
      }
      goto LABEL_59;
    }
  }
  v35 = NewSpecific(byte, v24);
  EffDat = v35;
  UnitData = wdata->UnitData;
  v37 = wdata->EffectTable;
  v32 = *(*(&v37->obj.klass + v8) + 20LL);
LABEL_44:
  Copy_3880080(UnitData, v32, EffDat, 0, v24);
  EventNo = wdata->EventNo;
  if (EventNo != 661)
    goto LABEL_58;
LABEL_45:
  if (f->NameIndex - 15 > 1)
    goto LABEL_74;
  billAlfRaitoSet(8.0);
  billCutRaitoSet(50.0);
  EventNo = wdata->EventNo;
  if (EventNo != 726)
    goto LABEL_64;
LABEL_59:
  if (f->NameIndex - 7 <= 2)
  {
    billBriRaitoSet(2.0);
    EventNo = wdata->EventNo;
    goto LABEL_64;
  }
LABEL_74:
  switch (v17)
  {
    case 0:
      v17 = 0;
      basic = dds3AddD3PEffectObjectBasic2(&EffDat->obj, zero, v57);
      if (basic)
        goto LABEL_18;
      break;
    case 1:
      v47 = EffDat;
      PibIndex = GetPibIndex(v47, 0);
      v48 = PibIndex;
      v49 = sub_8D3950(s32, &PibIndex);
      v50 = Concat_5269984("!!!!! PMD_EFFTYPE.PMD_EFFTYPE_BED : index = ", v49, " !!!!!");
      v52 = Empty_string_();
      Log(v50, v52, 0);
      BillSetPB(v48);
      basic = dds3AddBEDEffectObjectBasic2(&EffDat->obj, zero, v57);
      v17 = 1;
      if (basic)
        goto LABEL_18;
      break;
    case 2:
      basic = dds3AddMG12EffectObjectBasic2(1, &EffDat->obj);
      v17 = 2;
      if (basic)
        goto LABEL_18;
      break;
    case 3:
      basic = dds3AddMG12EffectObjectBasic2(2, &EffDat->obj);
      v17 = 3;
      if (basic)
        goto LABEL_18;
      break;
    default:
      goto LABEL_17;
  }
  return basic;
}

// 0x10f8320
s32 AddEffectTable(s32 now, pmdProcessWork_t *wdata, pmdFrameTable_t *f, char *effname, char *targetname, s32 posindex, s32 cutno) {
  u64 v13;
  struct dds3Basic_t_array *EffectBasicTable;
  s32 v16;
  dds3Basic_t_o *v18;
  struct dds3Basic_t_array *v19;
  dds3Basic_t_o *v20;
  struct pmdDataInfo_t_array *Data;
  dds3Basic_t_o *v27;
  dds3Basic_t_o *v29;
  u32 v30;
  dds3Basic_t_o *v33;
  dds3Basic_t_o *v34;
  struct dds3Basic_t_array *pBasic;
  dds3Basic_t_o *v39;
  dds3Basic_t_o *scene;
  dds3Basic_t_o *target;
  dds3Basic_t_o *eff;

  v13 = 0;
  target = 0;
  eff = 0;
  scene = 0;
  while (1)
  {
    EffectBasicTable = wdata->EffectBasicTable;
    if (!EffectBasicTable->m_Items[v13])
      break;
    v16 = v13 + 1;
    if (v13++ > 0x7D)
    {
      LODWORD(v13) = v16;
      break;
    }
  }
  if (v13 == 127)
    goto LABEL_37;
  v18 = AddEffect(wdata, f, f);
  eff = v18;
  if (!v18)
  {
LABEL_37:
    LODWORD(v13) = -1;
    return v13;
  }
  v18->name = effname;
  v19 = wdata->EffectBasicTable;
  v20 = v18;
  v19->m_Items[v13] = v20;
  Data = f->Data;
  if (LOBYTE(Data->m_Items[0].i))
    dds3EffectObjectPresetMG12(&eff);
  if (targetname)
  {
    scene = dds3GetActiveScene();
    v27 = dds3SceneBasicSearchName(&scene, targetname);
    target = v27;
    if (v27)
    {
      v29 = v27;
      v30 = DDS3_GETBASICTYPEL(v29);
      if (v30 <= 0x11)
      {
        if (((1 << v30) & 0x203D0) != 0)
        {
LABEL_36:
          dds3EffectObjectBasicLinkObject(&eff, &target);
          return v13;
        }
        if (v30 == 5)
        {
          if ((posindex & 0x80000000) == 0)
          {
            dds3EffectObjectBasicLinkObjectIndex(&eff, &target, posindex);
            return v13;
          }
          goto LABEL_36;
        }
        if (v30 == 16)
        {
          v33 = target;
          v34 = eff;
          evtPathLinkAndMake(v33, v34);
          pBasic = dds3GetBaseControlWorkData(&eff)->pBasic;
          v39 = pBasic->m_Items[1];
          evtStopMover(v39, 1, 0, 0);
        }
      }
    }
  }
  return v13;
}

// 0x10f87a0
s32 AddEffectTableMG12(s32 now, pmdProcessWork_t *wdata, pmdFrameTable_t *f) {
  u64 *v8;
  u64 v9;
  struct dds3Basic_t_array *EffectBasicTable;
  s32 v12;
  dds3Basic_t_o *v14;
  struct pmdNameTable_t_array *NameTable2;
  dds3Basic_t_o *v16;
  struct dds3Basic_t_array *v18;
  struct pmdDataInfo_t_array *Data;
  s32 i;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v30;
  s64 *v31;
  struct pmdNameTable_t_array *v32;
  System_String_o *Name;
  s64 *v35;
  s64 *v36;
  struct pmdNameTable_t_array *v39;
  System_String_o *v41;
  s64 *v42;
  s64 *v43;
  u32 v47;
  struct pmdDataInfo_t_array *v49;
  struct pmdNameTable_t_array *v53;
  System_String_o *v55;
  s64 *v56;
  s64 *v57;
  struct pmdNameTable_t_array *v61;
  System_String_o *v63;
  s64 *v64;
  s64 *v65;
  dds3Basic_t_o *v72[3];
  dds3Basic_t_o *eff;

  eff = 0;
  v8 = NewSpecific(dds3Basic_t, 4u);
  v9 = 0;
  while (1)
  {
    EffectBasicTable = wdata->EffectBasicTable;
    if (!EffectBasicTable->m_Items[v9])
      break;
    v12 = v9 + 1;
    if (v9++ > 0x7D)
    {
      LODWORD(v9) = v12;
      break;
    }
  }
  if (v9 == 127)
    goto LABEL_68;
  v14 = AddEffect(wdata, f);
  eff = v14;
  if (!v14)
  {
LABEL_68:
    LODWORD(v9) = -1;
    return v9;
  }
  NameTable2 = wdata->NameTable2;
  v16 = v14;
  v14->name = NameTable2->m_Items[f->NameIndex]->Name;
  v18 = wdata->EffectBasicTable;
  v18->m_Items[v9] = v16;
  Data = f->Data;
  i = Data->m_Items[0].i;
  else
  {
    workdata = dds3GetActiveScene()->workdata;
    if (workdata)
    {
LABEL_26:
      klass = workdata->klass;
      if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v72);
        if ((v72[0] & 1) != 0)
          v30 = v72[2];
        else
          v30 = v72 + 1;
        v31 = sub_8C4940(v30);
      }
    }
  }
  v8[4] = 0;
  if ((i & 0x80) != 0)
  {
    if ((v8[3] & 0xFFFFFFFE) == 0)
      goto LABEL_44;
  }
  else
  {
    v32 = wdata->NameTable2;
    Name = v32->m_Items[i]->Name;
    v35 = dds3SceneBasicSearchNameAndType_(workdata, 7u, Name);
    v36 = v35;
    v8[4] = v36;
    if ((v8[3] & 0xFFFFFFFE) == 0)
    {
LABEL_44:
    }
  }
  v8[5] = 0;
  if ((i & 0x8000) != 0)
  {
    if (*(v8 + 6) <= 2uLL)
      goto LABEL_84;
  }
  else
  {
    v53 = wdata->NameTable2;
    v55 = v53->m_Items[SBYTE1(i)]->Name;
    v56 = dds3SceneBasicSearchNameAndType_(workdata, 7u, v55);
    v57 = v56;
    v8[5] = v57;
    if (*(v8 + 6) <= 2uLL)
    {
LABEL_84:
    }
  }
  v8[6] = 0;
  if ((i & 0x800000) != 0)
  {
    if ((v8[3] & 0xFFFFFFFC) == 0)
      goto LABEL_58;
  }
  else
  {
    v39 = wdata->NameTable2;
    v41 = v39->m_Items[SBYTE2(i)]->Name;
    v42 = dds3SceneBasicSearchNameAndType_(workdata, 7u, v41);
    v43 = v42;
    v8[6] = v43;
    if ((v8[3] & 0xFFFFFFFC) == 0)
    {
LABEL_58:
    }
  }
  v8[7] = 0;
  if (i < 0)
  {
    v47 = *(v8 + 6);
    if (!v47)
      goto LABEL_97;
  }
  else
  {
    v61 = wdata->NameTable2;
    v63 = v61->m_Items[SHIBYTE(i)]->Name;
    v64 = dds3SceneBasicSearchNameAndType_(workdata, 7u, v63);
    v65 = v64;
    v8[7] = v65;
    v47 = *(v8 + 6);
    if (!v47)
    {
LABEL_97:
    }
  }
  dds3EffectObjectSetMG12Pos(&eff, v8 + 4, v8 + 5, v8 + 6, v8 + 7);
  v49 = f->Data;
  if (v49->m_Items[0].c1)
    dds3EffectObjectPresetMG12(&eff);
  return v9;
}

// 0x10f9810
void BEDFrameFunc(pmdProcessWork_t *wdata, pmdFrameTable_t *f, pmdFrameTable_t *nf, s32 now) {
  s32 v5;
  struct pmdDataInfo_t_array *Data;
  s32 Frame;
  struct pmdDataInfo_t_array *v12;
  struct pmdNameTable_t_array *NameTable2;
  s64 v15;
  System_String_o *Name;
  struct pmdDataInfo_t_array *v19;
  struct pmdDataInfo_t_array *v20;
  s32 i_high;
  struct pmdDataInfo_t_array *v23;
  struct pmdNameTable_t_array *v25;
  System_String_o *v27;
  s32 v29;
  s16 v30;
  struct pmdDataInfo_t_array *v31;

  if ((byte_3F589C5 & 1) != 0)
  {
    Data = f->Data;
    Frame = f->Frame;
    if (LODWORD(Data->max_length))
      goto LABEL_3;
LABEL_11:
  }
  Data = f->Data;
  Frame = f->Frame;
  if (!LODWORD(Data->max_length))
    goto LABEL_11;
LABEL_3:
  if (Frame == now)
  {
    if (*&Data->m_Items[0].c2 < 0)
    {
      Name = 0;
    }
    else
    {
      v12 = f->Data;
      NameTable2 = wdata->NameTable2;
      v15 = *&v12->m_Items[0].c2;
      Name = NameTable2->m_Items[v15]->Name;
    }
    v25 = wdata->NameTable2;
    v27 = v25->m_Items[f->NameIndex]->Name;
    v30 = AddEffectTable(v29, wdata, f, v27, Name, -1, v5);
    v31 = f->Data;
    HIWORD(v31->m_Items[0].i) = v30;
  }
  else if (*&Data->m_Items[0].c0 >= 1)
  {
    v19 = f->Data;
    if (*&v19->m_Items[0].c0 == now)
    {
      v20 = f->Data;
      i_high = SHIWORD(v20->m_Items[0].i);
      DelEffectTable(wdata, i_high, nf);
      v23 = f->Data;
      HIWORD(v23->m_Items[0].i) = -1;
    }
  }
}

// 0x10f7760
void BgmFrameFunc(pmdProcessWork_t *wdata, pmdFrameTable_t *f, pmdFrameTable_t *nf, s32 now) {
  struct pmdDataInfo_t_array *Data;
  s32 EventNo;
  s32 v11;
  u64 *v12;
  u64 *v14;
  struct pmdDataInfo_t_array *v16;
  s32 v18;
  s32 v19;

  if (f->Frame == now)
  {
    Data = f->Data;
    EventNo = wdata->EventNo;
    v11 = *&Data->m_Items[0].c2;
    v19 = EventNo;
    v12 = sub_8D3950(s32, &v19);
    v18 = v11;
    v14 = sub_8D3950(s32, &v18);
    Write_2930752("bgm_frame e{0:D3}, bgm {1:D}\n", v12, v14, 0);
    v16 = f->Data;
    switch (*&v16->m_Items[0].c0)
    {
      case 0:
        evtPlayBgm(EventNo, v11);
        break;
      case 1:
        evtFadeInBgm(EventNo, v11);
        break;
      case 2:
        evtFadeOutBgm(EventNo, v11);
        break;
      case 3:
        evtTransBgm(EventNo, v11);
        break;
      case 4:
        p2sdBGMVolHalfDown();
        break;
      case 5:
        p2sdBGMVolHalfUp();
        break;
      case 6:
        p2sdBGMStopAll();
        break;
      default:
        return;
    }
  }
}

// 0x10fb030
void Blur2FrameFunc(pmdProcessWork_t *wdata, pmdFrameTable_t *f, pmdFrameTable_t *nf, s32 now) {
  s32 Frame;
  s32 FirstFrame;
  s32 v11;
  f32 v12;
  struct pmdDataInfo_t_array *Data;
  struct dds3Effect_Blur_t_array *Blur2Table;
  s64 v16;
  pmdFrameTable_t_o *v18;
  s32 v19;
  struct pmdDataInfo_t_array *v21;
  struct pmdDataInfo_t_array *v23;
  struct dds3Effect_Blur_t_array *v24;
  s64 v26;
  dds3Effect_Blur_t_o *Blur2FrameFunc_bl2;

  Frame = f->Frame;
  if (Frame <= now)
    goto LABEL_38;
LABEL_6:
  FirstFrame = wdata->CutInfo->FirstFrame;
  v11 = Frame - FirstFrame;
  if (Frame != FirstFrame)
    goto LABEL_7;
LABEL_42:
  v12 = 0.0;
  Data = f->Data;
  Blur2Table = wdata->Blur2Table;
  if (!LODWORD(Data->max_length))
  {
LABEL_8:
  }
LABEL_9:
  v16 = *&Data->m_Items[0].c2;
  v18 = Blur2Table->m_Items[v16];
  if (Frame > now)
  {
    v19 = 1;
    nf = v18;
    v18 = 0;
      goto LABEL_25;
    goto LABEL_23;
  }
  v21 = f->Data;
  v19 = *&v21->m_Items[0].c0;
  if (nf)
  {
    v23 = nf->Data;
    v24 = wdata->Blur2Table;
    v26 = *&v23->m_Items[0].c2;
    nf = v24->m_Items[v26];
  }
  {
LABEL_23:
  }
LABEL_25:
  evtHokanBlur2(v19, v12, v18, nf, &Blur2FrameFunc_bl2);
  Eve_BlurSetParam(Blur2FrameFunc_bl2);
  if (HIBYTE(Blur2FrameFunc_bl2->abgr) > 2u)
  {
    Eve_BlurON();
  }
  else
  {
    Eve_BlurOFF();
  }
}

// 0x10f7970
void BlurFrameFunc(pmdProcessWork_t *wdata, pmdFrameTable_t *f, pmdFrameTable_t *nf, s32 now) {
  struct pmdDataInfo_t_array *Data;
  struct pmdDataInfo_t_array *v9;
  s32 Frame;
  s32 v12;
  s32 v13;
  s32 v14;
  struct pmdDataInfo_t_array *v15;
  s32 v17;
  struct pmdDataInfo_t_array *v18;
  s32 v19;
  struct pmdDataInfo_t_array *v20;
  s32 v21;

  if ((byte_3F589BD & 1) == 0)
  {
    Data = f->Data;
    if (LODWORD(Data->max_length) > 1)
      goto LABEL_3;
LABEL_13:
  }
  Data = f->Data;
  if (LODWORD(Data->max_length) <= 1)
    goto LABEL_13;
LABEL_3:
  if (LOWORD(Data->m_Items[0].i) && nf)
  {
    v9 = f->Data;
    Frame = f->Frame;
    v12 = now - Frame;
    v13 = nf->Frame - Frame;
    v14 = *&v9->m_Items[0].c0;
    v15 = nf->Data;
    v17 = (v13 - v12) * v14;
    v18 = f->Data;
    v19 = (v17 + v12 * *&v15->m_Items[0].c0) / v13;
    v20 = nf->Data;
    v21 = *&v18->m_Items[0].c2;
    LODWORD(v20) = ((v13 - v12) * v21 + v12 * *&v20->m_Items[0].c2) / v13;
  }
  else
  {
    v20 = f->Data;
    LOWORD(v19) = *&v20->m_Items[0].c0;
    LOWORD(v20) = *&v20->m_Items[0].c2;
  }
  if (v19 | v20)
  {
    dds3ScreenBlurFlag = 1;
    dds3ScreenBlurAlpha = v19;
    dds3ScreenBlurScale = v20;
  }
  else
  {
    dds3ScreenBlurFlag = 0;
  }
}

// 0x10fa420
void BokasiFrameFunc(pmdProcessWork_t *wdata, pmdFrameTable_t *f, pmdFrameTable_t *nf, s32 now) {
  struct pmdDataInfo_t_array *Data;
  s32 v9;

  if (f->Frame == now)
  {
    Data = f->Data;
    if (*&Data->m_Items[0].c0)
    {
      v9 = 1;
    }
    else
    {
      v9 = 0;
    }
    evtSetBokasi(v9);
  }
}

// 0x10f7120
void CameraFrameFunc(pmdProcessWork_t *wdata, pmdFrameTable_t *f, pmdFrameTable_t *nf, s32 now) {
  dds3Basic_t_o *ControlScene;
  struct pmdNameTable_t_array *NameTable2;
  dds3SceneBasic_t_o *workdata;
  System_String_o *Name;
  dds3SceneBasic_t_c *klass;
  s64 typeHierarchyDepth;
  char *v16;
  s64 *v17;
  dds3Basic_t_o *v18;
  struct dds3Basic_t_o *v20;
  evtPolygonMovie_c *v21;
  u64 v27[3];

  if ((f->NameIndex & 0x80000000) == 0)
  {
    ControlScene = dds3GetControlScene();
    NameTable2 = wdata->NameTable2;
    workdata = ControlScene->workdata;
    Name = NameTable2->m_Items[f->NameIndex]->Name;
    else if (!workdata)
    {
      goto LABEL_18;
    }
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v27);
      if ((v27[0] & 1) != 0)
        v16 = v27[2];
      else
        v16 = v27 + 1;
      v17 = sub_8C4940(v16);
    }
LABEL_18:
    v18 = dds3SceneBasicSearchNameAndType_(workdata, 4u, Name);
    if (!v18)
      return;
    v20 = v18;
    else
    {
      if (nowcamera)
        goto LABEL_22;
    }
    CameraFrameFunc_nowframe = -1;
    if ((v21->_2.bitflags2 & 2) == 0)
      goto LABEL_32;
    goto LABEL_23;
  }
}

// 0x10ffb00
bool CheckLoad(pmdProcessWork_t *wdata) {
  AssetBundleCtrl_o *asset_bc;
  u32 flag;
  System_Byte_array *UnitData;
  System_Byte_array *pm2;
  bool result;

  asset_bc = get_asset_bc();
  if (!IsLoad(asset_bc, wdata->fkey))
    return 0;
  flag = wdata->flag;
  if ((flag & 8) != 0)
    return 1;
  if ((flag & 2) != 0)
  {
    wdata->flag = flag & 0xFFFFFFFD;
    return 0;
  }
  else if ((flag & 4) != 0)
  {
    result = 0;
    if (wdata->FileHandle2)
      wdata->flag = flag & 0xFFFFFFFB;
  }
  else
  {
    UnitData = wdata->UnitData;
    if (UnitData)
    {
      pm2 = wdata->pm2;
      if (pm2)
      {
        evtGetPolygonMovieWorkData1(wdata, UnitData, pm2);
        wdata->flag |= 8u;
        return 1;
      }
      return 0;
    }
    else
    {
      return 0;
    }
  }
  return result;
}

// 0x10fcc50
void DBlurFrameFunc(pmdProcessWork_t *wdata, pmdFrameTable_t *f, pmdFrameTable_t *nf, s32 now) {
  s32 Frame;
  s32 FirstFrame;
  s32 v11;
  f32 v12;
  struct pmdDataInfo_t_array *Data;
  struct dds3Effect_DistortionBlurParam_t_array *DBlurTable;
  s64 v16;
  pmdFrameTable_t_o *v18;
  s32 v19;
  struct pmdDataInfo_t_array *v21;
  struct pmdDataInfo_t_array *v23;
  struct dds3Effect_DistortionBlurParam_t_array *v24;
  s64 v26;
  dds3Effect_DistortionBlurParam_t_o *DBlurFrameFunc_dbl;

  Frame = f->Frame;
  if (Frame <= now)
    goto LABEL_38;
LABEL_6:
  FirstFrame = wdata->CutInfo->FirstFrame;
  v11 = Frame - FirstFrame;
  if (Frame != FirstFrame)
    goto LABEL_7;
LABEL_42:
  v12 = 0.0;
  Data = f->Data;
  DBlurTable = wdata->DBlurTable;
  if (!LODWORD(Data->max_length))
  {
LABEL_8:
  }
LABEL_9:
  v16 = *&Data->m_Items[0].c2;
  v18 = DBlurTable->m_Items[v16];
  if (Frame > now)
  {
    v19 = 1;
    nf = v18;
    v18 = 0;
      goto LABEL_25;
    goto LABEL_23;
  }
  v21 = f->Data;
  v19 = *&v21->m_Items[0].c0;
  if (nf)
  {
    v23 = nf->Data;
    v24 = wdata->DBlurTable;
    v26 = *&v23->m_Items[0].c2;
    nf = v24->m_Items[v26];
  }
  {
LABEL_23:
  }
LABEL_25:
  evtHokanDistBlur(v19, v12, v18, nf, &DBlurFrameFunc_dbl);
  Eve_DistortionBlurSetParam(DBlurFrameFunc_dbl);
  if (HIBYTE(DBlurFrameFunc_dbl->abgr) > 2u)
  {
    Eve_DistortionBlurON();
  }
  else
  {
    Eve_DistortionBlurOFF();
  }
}

// 0x10f8ec0
void DelEffectTable(pmdProcessWork_t *wdata, s32 no) {
  struct dds3Basic_t_array *EffectBasicTable;
  struct dds3Basic_t_array *v7;
  struct dds3Basic_t_array *v9;

  if ((no & 0x80000000) == 0)
  {
    EffectBasicTable = wdata->EffectBasicTable;
    if (EffectBasicTable->m_Items[no])
    {
      v7 = wdata->EffectBasicTable;
      dds3DeleteSceneBasicData(&v7->m_Items[no]);
      v9 = wdata->EffectBasicTable;
      v9->m_Items[no] = 0;
    }
  }
}

// 0x10f6bd0
void DispAnimation(pmdProcessWork_t *wdata) {
  s32 EventNo;
  s32 NowFrame;
  s32 FirstFrame;
  s32 v6;
  s32 v7;
  System_WeakReference_o *Item;

  EventNo = wdata->EventNo;
  NowFrame = wdata->NowFrame;
  FirstFrame = wdata->CutInfo->FirstFrame;
  if (_get_Count(wdata->anim_list) >= 1)
  {
    v6 = 0;
    v7 = NowFrame - FirstFrame;
    do
    {
      Item = _get_Item(
               wdata->anim_list,
               v6);
      SetFrame(Item, v7, EventNo != 705, 0);
      ++v6;
    }
    while (v6 < _get_Count(wdata->anim_list));
  }
}

// 0x10f8fc0
void EffectFrameFunc(pmdProcessWork_t *wdata, pmdFrameTable_t *f, pmdFrameTable_t *nf, s32 now) {
  s32 v5;
  struct pmdDataInfo_t_array *Data;
  u32 max_length;
  struct pmdDataInfo_t_array *v13;
  struct pmdNameTable_t_array *NameTable2;
  s64 i_high;
  System_String_o *Name;
  struct pmdDataInfo_t_array *v20;
  struct pmdDataInfo_t_array *v21;
  s32 c0;
  struct pmdDataInfo_t_array *v24;
  struct pmdDataInfo_t_array *v26;
  struct pmdNameTable_t_array *v27;
  struct pmdDataInfo_t_array *v29;
  System_String_o *v30;
  s32 v32;
  s32 v33;
  s8 v34;
  struct pmdDataInfo_t_array *v35;
  struct pmdDataInfo_t_array *v37;
  struct dds3Basic_t_array *EffectBasicTable;
  s64 v40;
  dds3Basic_t_o *v42;

  Data = f->Data;
  max_length = Data->max_length;
  if (f->Frame == now)
  {
    if (SHIWORD(Data->m_Items[0].i) < 0)
    {
      Name = 0;
    }
    else
    {
      v13 = f->Data;
      NameTable2 = wdata->NameTable2;
      i_high = SHIWORD(v13->m_Items[0].i);
      Name = NameTable2->m_Items[i_high]->Name;
    }
    v27 = wdata->NameTable2;
    v29 = f->Data;
    v30 = v27->m_Items[f->NameIndex]->Name;
    v33 = SBYTE1(v29->m_Items[0].i);
    v34 = AddEffectTable(v32, wdata, f, v30, Name, v33, v5);
    v35 = f->Data;
    v35->m_Items[0].c0 = v34;
    goto LABEL_37;
  }
  if (*&Data->m_Items[0].c2 < 1)
    goto LABEL_37;
  v20 = f->Data;
  if (*&v20->m_Items[0].c2 != now)
  {
LABEL_37:
    v26 = f->Data;
    if (LODWORD(v26->max_length))
      goto LABEL_38;
LABEL_50:
  }
  v21 = f->Data;
  c0 = v21->m_Items[0].c0;
  DelEffectTable(wdata, c0, nf);
  v24 = f->Data;
  v24->m_Items[0].c0 = -1;
  v26 = f->Data;
  if (!LODWORD(v26->max_length))
    goto LABEL_50;
LABEL_38:
  if ((v26->m_Items[0].c0 & 0x80000000) == 0)
  {
    v37 = f->Data;
    EffectBasicTable = wdata->EffectBasicTable;
    v40 = v37->m_Items[0].c0;
    v42 = EffectBasicTable->m_Items[v40];
    if (v42 && f->Length && f->Length == now)
    {
      evtEffectLoopControl(v42, 0);
    }
  }
}

// 0x1104aa0
dds3ProcessID_t *EvtStartPMDuplicate(s32 priority, void *pr, s32 eventno, s32 cutno) {
  u64 *v9;
  u64 *v10;
  System_String_o *v12;
  System_String_o *DLCTag;
  System_String_o *v15;
  pmdProcessWork_t_o *data;
  UnityEngine_GameObject_o *v19;
  Il2CppObject *Component_object;
  UnityEngine_Transform_o *transform;
  UnityEngine_GameObject_o *v22;
  Il2CppObject *v23;
  UnityEngine_Transform_o *v25;
  UnityEngine_Object_o *EventCTree;
  u64 *v28;
  UnityEngine_Transform_o *v31;
  UnityEngine_Object_o *EventFTree;
  u64 *v34;
  UnityEngine_Transform_o *v37;
  u64 *v38;
  u64 *v39;
  System_String_o *v40;
  u64 *v41;
  UnityEngine_Transform_o *v43;
  UnityEngine_Transform_o *v45;
  u64 *v46;
  u64 *v47;
  System_String_o *v48;
  u64 *v49;
  UnityEngine_Transform_o *v50;
  UnityEngine_Transform_o *v51;
  System_String_o *v53;
  System_String_o *v54;
  System_Object_array *v56;
  s64 *v58;
  Il2CppClass *v60;
  s64 *v61;
  System_Byte_array *Interface;
  char *ChrName;
  s64 *v64;
  AssetBundleCtrl_o *asset_bc;
  System_String_o *v67;
  System_String_o *v68;
  System_Object_array *v70;
  s64 *v72;
  System_Byte_array *FileByte;
  AssetBundleCtrl_o *v84;
  evtPolygonMovie_sLoadMode_o *Item;
  s32 v88;
  u64 *v89;
  s32 v90;
  u64 *v91;
  u64 *v92;
  System_String_o *v93;
  u64 *v94;
  u64 *v95;
  u64 *v97;
  u64 *v98;
  s32 v104;
  System_String_o *key;
  s32 v106;
  s32 v107;
  s32 v108;
  s32 v109;
  dds3ProcessID_t_o *target;
  System_String_o *pm2file;
  System_String_o *pm1file;
  dds3ProcessID_t_o *parent;
  evtPolygonMovie_sLoadMode_o v114;

  pm2file = 0;
  pm1file = 0;
  target = 0;
  v9 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v9);
  parent = v9;
  v114.cutno = eventno;
  v10 = sub_8D3950(s32, &v114);
  v12 = Format("e{0:D3}", v10, 0);
  DLCTag = GetDLCTag(eventno);
  v15 = Concat_5224608(v12, DLCTag);
  get_table(pr);
  if (!evtPolygonMovie_sLoadMode___ContainsKey(LoadMode, cutno))
    return 0;
  if (CurrentEventNo != eventno)
  {
    InitializeReplaceList(eventno);
  }
  v104 = priority;
  key = v15;
  CurrentEventNo = eventno;
  data = Allocate(pmdProcessWork_t);
  pmdProcessWork_t___ctor(data);
  data->EventNo = eventno;
  data->CutNo = cutno;
  v19 = Find("kernel", 0);
  Component_object = GetComponent_object_(v19);
  transform = get_transform(Component_object[13].klass, 0);
  v22 = Find("kernel", 0);
  v23 = GetComponent_object_(v22);
  v25 = get_transform(v23[14].klass, 0);
  if (op_Equality(EventCTree, 0, 0))
  {
    v28 = Allocate(UnityEngine_GameObject);
    _ctor(v28, "PMV", 0);
    EventCTree = v28;
    v31 = get_transform(EventCTree, 0);
    SetParent(v31, transform);
  }
  if (op_Equality(EventFTree, 0, 0))
  {
    v34 = Allocate(UnityEngine_GameObject);
    _ctor(v34, "PMV", 0);
    EventFTree = v34;
    v37 = get_transform(EventFTree, 0);
    SetParent(v37, v25);
  }
  v109 = eventno;
  v38 = sub_8D3950(s32, &v109);
  v108 = cutno;
  v39 = sub_8D3950(s32, &v108);
  v40 = Format_5268592("E{0:D3}_{1:D3}", v38, v39);
  v41 = Allocate(UnityEngine_GameObject);
  _ctor(v41, v40, 0);
  v43 = get_transform(v41, 0);
  v45 = get_transform(EventFTree, 0);
  SetParent(v43, v45);
  v107 = eventno;
  v46 = sub_8D3950(s32, &v107);
  v106 = cutno;
  v47 = sub_8D3950(s32, &v106);
  v48 = Format_5268592("E{0:D3}_{1:D3}", v46, v47);
  v49 = Allocate(UnityEngine_GameObject);
  _ctor(v49, v48, 0);
  v50 = get_transform(v49, 0);
  v51 = get_transform(EventCTree, 0);
  SetParent(v50, v51);
  SetPMFileName(eventno, cutno, &pm1file, &pm2file);
  v53 = pm1file;
  v54 = Concat_5221536("@@@@@ PM1Load : ", pm1file, " @@@@@@");
  v56 = Empty_string_();
  Log(v54, v56, 0);
  v58 = GetData(v53);
  if (v58)
  {
    v61 = v58;
    Interface = QueryInterface(v58, byte);
    if (!Interface)
    {
      sub_8FC2C0(*(*v61 + 64), v60, &v114);
      if ((v114.cutno & 1) != 0)
        ChrName = v114.ChrName;
      else
        ChrName = &v114.cutno + 1;
      v64 = sub_8C4940(ChrName);
    }
  }
  else
  {
    Interface = 0;
  }
  if (!Interface)
  {
    asset_bc = get_asset_bc();
    Interface = LoadFileByte(asset_bc, key, v53);
  }
  v67 = pm2file;
  v68 = Concat_5221536("@@@@@ PM2Load : ", pm2file, " @@@@@@");
  v70 = Empty_string_();
  Log(v68, v70, 0);
  else
  {
    v72 = GetData(v67);
    if (v72)
      goto LABEL_68;
  }
  v84 = get_asset_bc();
  FileByte = LoadFileByte(v84, key, v67);
    goto LABEL_81;
LABEL_70:
LABEL_81:
  evtGetPolygonMovieWorkData1(data, Interface, FileByte);
  data->flag |= 9u;
  Item = evtPolygonMovie_sLoadMode___get_Item(&v114, LoadMode, cutno);
  read_module(Item, data, v49, v41);
  v88 = data->EventNo;
  if ((v88 - 804) < 3 || v88 == 676)
  {
    LoadKeys(3, key, 0);
    LoadKeys(1, key, 0);
  }
  v89 = Allocate(evtTexManager);
  _ctor(v89, 0);
  v90 = data->EventNo;
  data->TexMngr = v89;
  v114.cutno = v90;
  v91 = sub_8D3950(s32, &v114);
  v109 = data->CutNo;
  v92 = sub_8D3950(s32, &v109);
  v93 = Format_5268592("E{0:D3}_{1:D3}_TEX", v91, v92);
  Initialize(v89, key, v93, 0);
  v94 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v94,
    0,
    Method_evtPolygonMovie_evtPolygonMovieProcess1e__);
  v95 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v95,
    0,
    Method_evtPolygonMovie_evtPolygonMovieShutdown1e__);
  parent = dds3StartProcess("PolygonMovie", v104, 1, 1, v94, 0, v95, 0, data, 0);
  v97 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v97);
  v98 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v98,
    0,
    Method_dds3UnityEx_evtPolygonMovieUpdateEx_Unity__);
  target = dds3StartProcess("PolygonMovieEx", 0x2B0Au, 1, 1, v98, 0, 0, 0, data, 0);
  dds3LinkProcess(&parent, &target);
  _Add(EventID, data->CutNo);
  data->ProcessID = parent;
  SetShadowMode(kernelObject, 3);
  InitDanteEventMsg();
  return parent;
}

// 0x10f7530
void FadeFrameFunc(pmdProcessWork_t *wdata, pmdFrameTable_t *f, pmdFrameTable_t *nf, s32 now) {
  s32 Frame;
  struct pmdDataInfo_t_array *Data;
  u32 Length;
  u32 v12;
  u32 v13;
  u32 v14;
  s32 v15;
  u32 v16;
  u32 v17;
  u32 v18;
  u32 v19;

  if ((byte_3F589BB & 1) != 0)
  {
    Frame = f->Frame;
    if (wdata->EventNo != 634)
      goto LABEL_3;
  }
  else
  {
    Frame = f->Frame;
    if (wdata->EventNo != 634)
    {
LABEL_3:
      if (Frame != now)
        return;
      goto LABEL_4;
    }
  }
  if (Frame == 280)
    v15 = 290;
  else
    v15 = Frame;
  if (wdata->CutNo == 50)
    Frame = v15;
  if (Frame == now)
  {
LABEL_4:
    Data = f->Data;
    switch (*&Data->m_Items[0].c0)
    {
      case 0:
        Length = f->Length;
        v12 = 255;
        v13 = 255;
        v14 = 255;
        goto LABEL_27;
      case 1:
        v16 = f->Length;
        v17 = 255;
        v18 = 255;
        v19 = 255;
        goto LABEL_32;
      case 2:
        Length = f->Length;
        v12 = 0;
        v13 = 0;
        v14 = 0;
LABEL_27:
        dds3FadeIn(v12, v13, v14, Length);
        return;
      case 3:
        v16 = f->Length;
        v17 = 0;
        v18 = 0;
        v19 = 0;
LABEL_32:
        dds3FadeOut(v17, v18, v19, v16);
        break;
      default:
        return;
    }
  }
}

// 0x10fe620
void FilterFrameFunc(pmdProcessWork_t *wdata, pmdFrameTable_t *f, pmdFrameTable_t *nf, s32 now) {
  s32 Frame;
  s32 FirstFrame;
  s32 v11;
  f32 v12;
  struct pmdDataInfo_t_array *Data;
  struct dds3Effect_Filter_t_array *FilterTable;
  s64 v16;
  pmdFrameTable_t_o *v18;
  s32 v19;
  struct pmdDataInfo_t_array *v21;
  struct pmdDataInfo_t_array *v23;
  struct dds3Effect_Filter_t_array *v24;
  s64 v26;
  dds3Effect_Filter_t_o *FilterFrameFunc_fl;

  Frame = f->Frame;
  if (Frame <= now)
    goto LABEL_38;
LABEL_6:
  FirstFrame = wdata->CutInfo->FirstFrame;
  v11 = Frame - FirstFrame;
  if (Frame != FirstFrame)
    goto LABEL_7;
LABEL_42:
  v12 = 0.0;
  Data = f->Data;
  FilterTable = wdata->FilterTable;
  if (!LODWORD(Data->max_length))
  {
LABEL_8:
  }
LABEL_9:
  v16 = *&Data->m_Items[0].c2;
  v18 = FilterTable->m_Items[v16];
  if (Frame > now)
  {
    v19 = 1;
    nf = v18;
    v18 = 0;
      goto LABEL_25;
    goto LABEL_23;
  }
  v21 = f->Data;
  v19 = *&v21->m_Items[0].c0;
  if (nf)
  {
    v23 = nf->Data;
    v24 = wdata->FilterTable;
    v26 = *&v23->m_Items[0].c2;
    nf = v24->m_Items[v26];
  }
  {
LABEL_23:
  }
LABEL_25:
  evtHokanFilter(v19, v12, v18, nf, &FilterFrameFunc_fl);
  Eve_FilterSetParam(FilterFrameFunc_fl);
  if (FilterFrameFunc_fl->abgr >> 25)
  {
    Eve_FilterON();
  }
  else
  {
    Eve_FilterOFF();
  }
}

// 0x10ff110
void FrameRun(pmdProcessWork_t *wdata) {
  signed s64 FrameCount;
  u64 v5;
  pmdFrameTable_t_o *v6;
  pmdFrameTable_t_o *v8;
  struct pmdFrameTable_t_array *FrameTable;
  u64 v11;
  struct pmdFrameTable_t_array *v12;
  struct pmdFrameTable_t_array *v14;
  pmdFrameTable_t_o *v16;
  u32 v17;
  s32 v18;
  s32 ObjectType;
  s32 Length;
  struct evtPolygonMovie_FrameRunStruct_array *framefunc;
  s64 v23;
  struct evtPolygonMovie_FrameRunStruct_array *v26;
  s64 v27;
  struct pmdDataInfo_t_array *Data;
  struct pmdDataInfo_t_array *v30;
  s32 v32;
  struct pmdDataInfo_t_array *v34;
  struct pmdDataInfo_t_array *v35;
  s32 NowFrame;
  s32 Frame;
  s32 v39;
  f32 nowfovy;
  dds3Basic_t_o *pSceneBasic;

  pSceneBasic = 0;
  nowcamera = 0;
  LODWORD(FrameCount) = wdata->FrameCount;
  if (FrameCount >= 1)
  {
    v5 = 0;
    v6 = 0;
    while (1)
    {
      v8 = v6;
      FrameTable = wdata->FrameTable;
      v6 = FrameTable->m_Items[v5];
      v11 = v5 + 1;
      if ((v5 + 1) >= FrameCount)
        goto LABEL_25;
      v12 = wdata->FrameTable;
      if (v12->m_Items[v5 + 1]->ObjectType == v6->ObjectType)
      {
        v14 = wdata->FrameTable;
        v16 = v14->m_Items[v5 + 1];
        if (!v8)
        {
LABEL_20:
          v17 = v6->ObjectType - 3;
          goto LABEL_21;
        }
      }
      else
      {
LABEL_25:
        v16 = 0;
        if (!v8)
          goto LABEL_20;
      }
      ObjectType = v6->ObjectType;
      if (v8->ObjectType != ObjectType)
        v8 = 0;
      v17 = ObjectType - 3;
      if (v17 <= 0x14)
      {
LABEL_21:
        switch (v17)
        {
          case 0u:
          case 0x11u:
          case 0x12u:
            Data = v6->Data;
            if (!*&Data->m_Items[0].c2)
              goto LABEL_9;
            v30 = v6->Data;
            v32 = *&v30->m_Items[0].c2;
            break;
          case 6u:
          case 9u:
          case 0x13u:
            goto LABEL_9;
          case 7u:
          case 8u:
          case 0xAu:
          case 0xBu:
          case 0xCu:
          case 0xDu:
          case 0xEu:
          case 0x14u:
            goto LABEL_22;
          case 0xFu:
            v34 = v6->Data;
            if (!*&v34->m_Items[0].c0)
              goto LABEL_9;
            v35 = v6->Data;
            v32 = *&v35->m_Items[0].c0;
            break;
          default:
            goto LABEL_29;
        }
        Length = v32 + 1 - v6->Frame;
        if (Length < 1)
          goto LABEL_30;
LABEL_59:
        NowFrame = wdata->NowFrame;
        Frame = v6->Frame;
        v39 = Length + Frame;
        if (NowFrame < Frame || NowFrame >= v39)
          goto LABEL_63;
LABEL_34:
        v23 = v6->ObjectType;
        if (!framefunc->m_Items[v23].func)
          goto LABEL_63;
        v26 = framefunc;
        v27 = v6->ObjectType;
        Invoke(
          v26->m_Items[v27].func,
          wdata,
          v6,
          v16,
          wdata->NowFrame,
          0);
        FrameCount = wdata->FrameCount;
        v5 = v11;
        if (v11 >= FrameCount)
        {
LABEL_64:
          break;
        }
      }
      else
      {
LABEL_29:
        Length = v6->Length;
        if (v6->Length)
          goto LABEL_59;
LABEL_30:
        if (Length)
        {
LABEL_22:
          v18 = wdata->NowFrame;
          if (v18 >= v6->Frame)
          {
            if (!v16 || v18 < v16->Frame)
              goto LABEL_34;
          }
          else if (!v8)
          {
            goto LABEL_34;
          }
        }
        else
        {
LABEL_9:
          if (wdata->NowFrame >= v6->Frame)
            goto LABEL_34;
        }
LABEL_63:
        FrameCount = wdata->FrameCount;
        v5 = v11;
        if (v11 >= FrameCount)
          goto LABEL_64;
      }
    }
  }
  if (nowcamera)
  {
    pSceneBasic = dds3GetActiveScene();
    dds3SetActiveCameraSceneBasic(&pSceneBasic, &nowcamera);
    dds3SetScreenFovy(nowfovy);
    UnityEx_SetPM_NowCamera();
  }
}

// 0x10ff5a0
void FrameTableOverWrite(pmdProcessWork_t *wdata) {
  s32 FrameCount;
  struct pmdStageTable_t_o *StageTable;
  s32 MinorNum;
  s32 MajorNum;
  s32 i;
  u64 v10;
  struct pmdFrameTable_t_array *FrameTable;
  pmdFrameTable_t_o *v13;
  u64 *v14;
  u64 *v15;
  Il2CppObject *v17;
  u16 v18[2];
  s32 v19;

  FrameCount = wdata->FrameCount;
  if (FrameCount >= 1)
  {
    StageTable = wdata->StageTable;
    MajorNum = StageTable->MajorNum;
    MinorNum = StageTable->MinorNum;
    if (MajorNum == 693 && MinorNum == 10)
    {
      v10 = 0;
      do
      {
        FrameTable = wdata->FrameTable;
        v13 = FrameTable->m_Items[v10];
        if (v13->ObjectType == 16)
        {
          v19 = v10;
          v14 = sub_8D3950(s32, &v19);
          v18[0] = v13->Frame;
          v15 = sub_8D3950(ushort, v18);
          v17 = Concat_5269984(v14, " 強制書き換え  f.Frame", v15);
          Log(v17, 0);
          if (v13->Frame == 100)
            v13->Frame = 99;
        }
        ++v10;
      }
      while (v10 < wdata->FrameCount);
    }
    else
    {
      for (i = 0; i < FrameCount; ++i)
      {
      }
    }
  }
}

// 0x10fa4f0
f32 GetKeyFrameRatio(pmdProcessWork_t *wdata, pmdFrameTable_t *f, pmdFrameTable_t *nf, s32 now) {
  s32 Frame;
  s32 v6;

  Frame = f->Frame;
  if (Frame <= now)
  {
    if (nf)
    {
      v6 = nf->Frame - Frame;
      if (v6)
        return (now - Frame) / v6;
    }
    else
    {
      v6 = wdata->CutInfo->LastFrame - Frame;
      if (v6)
        return (now - Frame) / v6;
    }
  }
  else
  {
    Frame = wdata->CutInfo->FirstFrame;
    v6 = f->Frame - Frame;
    if (v6)
      return (now - Frame) / v6;
  }
  return 0.0;
}

// 0x10f73a0
char *GetNowCameraName(void) {
  return nowcamera->name;
}

// 0x11038a0
s32 GetNowFrame(void) {
  return Last_wdata_NowFrame;
}

// 0x1103910
pmdProcessWork_t *InitPolygonMovieWorkData(void) {
  u64 *v1;

  v1 = Allocate(pmdProcessWork_t);
  pmdProcessWork_t___ctor(v1);
  return v1;
}

// 0x10f6160
void InitializeReplaceList(s32 event_no) {
  struct dds3ModelFileTable_t_array *eventModelFileTable2;
  il2cpp_array_size_t max_length;
  System_String_o *DLCTag;
  u64 *v7;
  System_String_o *v8;
  System_String_o *v10;
  u64 v13;
  s64 v14;
  dds3ModelFileTable_t_o **m_Items;
  _BOOL4 v19;
  char v20;
  s64 *v23;
  System_String_o *fname;
  System_String_o *v26;
  System_String_o *modelFile;
  s32 IndexOf;
  s32 v30;
  s32 Length;
  s32 v32;
  s32 v34;
  s32 v35;
  bool v37;
  s32 v38;

  max_length = eventModelFileTable2->max_length;
  DLCTag = GetDLCTag(event_no);
  v37 = op_Equality(DLCTag, "m", 0);
  v38 = event_no;
  v7 = sub_8D3950(s32, &v38);
  v8 = Format("e{0:D3}", v7, 0);
  v10 = Concat_5224608(v8, DLCTag);
  SetEventNo(event_no);
  PropertySheet___Clear(replace_list);
  if (max_length >= 1)
  {
    v13 = 0;
    v14 = max_length;
    m_Items = eventModelFileTable2->m_Items;
    do
    {
      if (IsNullOrEmpty(m_Items[v13]->akey))
        goto LABEL_54;
      if (!Equals_5239888(m_Items[v13]->akey, v10, 5))
        goto LABEL_54;
      if (IsNullOrEmpty(m_Items[v13]->texFile))
      {
        v19 = 0;
        v20 = 1;
        if (v13 >= LODWORD(eventModelFileTable2->max_length))
          goto LABEL_31;
      }
      else
      {
        v20 = 0;
        v19 = Equals_5239888(m_Items[v13]->texFile, "D", 5);
        if (v13 >= LODWORD(eventModelFileTable2->max_length))
        {
LABEL_31:
        }
      }
      if (v19)
      {
        if (v37)
          v23 = &"dante/dante_";
        else
          v23 = &"raidou/raidou_";
        fname = Concat_5224608(*v23, v10);
        if ((v20 & 1) != 0)
          goto LABEL_44;
      }
      else
      {
        fname = m_Items[v13]->fname;
        if ((v20 & 1) != 0)
          goto LABEL_44;
      }
      if (!Equals_5239888(m_Items[v13]->texFile, "P", 5)
        || (v26 = Concat_5224608("player_tatoo/player_tatoo_", v10), fname = v26, v37))
      {
LABEL_44:
        if (v13 >= LODWORD(eventModelFileTable2->max_length))
        {
LABEL_45:
        }
        goto LABEL_46;
      }
      fname = Concat_5224608(v26, "_raidou");
      if (v13 >= LODWORD(eventModelFileTable2->max_length))
        goto LABEL_45;
LABEL_46:
      modelFile = m_Items[v13]->modelFile;
      IndexOf = LastIndexOf(modelFile, 0x2Fu, 0);
      if (IndexOf != -1)
      {
        v30 = IndexOf;
        Length = get_Length(modelFile);
        modelFile = Substring_5248048(modelFile, v30 + 1, Length + ~v30);
      }
      v32 = LastIndexOf(fname, 0x2Fu, 0);
      if (v32 != -1)
      {
        v34 = v32;
        v35 = get_Length(fname);
        fname = Substring_5248048(fname, v34 + 1, v35 + ~v34);
      }
      PropertySheet___Add(replace_list, modelFile, fname);
LABEL_54:
      ++v13;
    }
    while (v14 != v13);
  }
}

// 0x10f60e0
bool IsPolygonMovie(s32 eventno) {
  return CurrentEventNo == eventno;
}

// 0x10f9a80
void LightFrameFunc(pmdProcessWork_t *wdata, pmdFrameTable_t *f, pmdFrameTable_t *nf, s32 now) {
  struct pmdDataInfo_t_array *Data;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v15;
  s64 *v16;
  struct pmdNameTable_t_array *NameTable2;
  System_String_o *Name;
  struct pmdDataInfo_t_array *v21;
  struct pmdNameTable_t_array *v22;
  s64 v24;
  Il2CppObject *Item;
  struct pmdStageTable_t_o *StageTable;
  s32 MinorNum;
  dds3Basic_t_o *v33;
  dds3Basic_t_o *v35;
  struct pmdDataInfo_t_array *v37;
  s32 Length;
  struct pmdDataInfo_t_array *v40;
  struct pmdNameTable_t_array *v41;
  s64 v43;
  System_String_o *v45;
  System_Object_array *v47;
  evtUnitHandle_t_o *h;
  dds3Basic_t_o *light;
  u64 v50[3];

  h = 0;
  light = 0;
  if (f->Frame == now)
  {
    Data = f->Data;
    if ((*&Data->m_Items[0].c0 & 0x80000000) == 0)
    {
      else
      {
        workdata = dds3GetActiveScene()->workdata;
        if (workdata)
        {
LABEL_11:
          klass = workdata->klass;
          if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
            || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
          {
            sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v50);
            if ((v50[0] & 1) != 0)
              v15 = v50[2];
            else
              v15 = v50 + 1;
            v16 = sub_8C4940(v15);
          }
        }
      }
      NameTable2 = wdata->NameTable2;
      Name = NameTable2->m_Items[f->NameIndex]->Name;
      light = dds3SceneBasicSearchNameAndType_(workdata, 9u, Name);
      if (light)
      {
        v21 = f->Data;
        v22 = wdata->NameTable2;
        v24 = *&v21->m_Items[0].c0;
        Item = v22->m_Items[v24]->Name;
        if (Animator___ContainsKey(replace_list, Item))
        {
          Item = object___get_Item(replace_list, Item);
        }
        StageTable = wdata->StageTable;
        if (StageTable->MajorNum == 800)
        {
          MinorNum = StageTable->MinorNum;
          if ((MinorNum == 80 || MinorNum == 70) && Equals_5239888(Item, "JAKYO_01.PB", 5))
            Item = "npc_jakyo_e807";
        }
        v33 = dds3SceneBasicSearchNameAndType_(workdata, 5u, Item);
        if (v33)
        {
          v35 = v33;
          h = evtGetUnitHandle2(v35);
          v37 = f->Data;
          Length = f->Length;
          if (*&v37->m_Items[0].c2)
          {
            evtLinkLightObjectBasic(&h, &light, Length);
          }
          else
          {
            evtUnlinkLightObjectBasic(&h, Length);
          }
        }
        else
        {
          v40 = f->Data;
          v41 = wdata->NameTable2;
          v43 = *&v40->m_Items[0].c0;
          v45 = Concat_5271136("＠＠＠配置ライトのリンク先ユニットを検索", v41->m_Items[v43]->Name, "が見つからなかった！！！！！！ : ", Item);
          v47 = Empty_string_();
          Log(v45, v47, 0);
        }
      }
    }
  }
}

// 0x10fbec0
void MBlurFrameFunc(pmdProcessWork_t *wdata, pmdFrameTable_t *f, pmdFrameTable_t *nf, s32 now) {
  s32 Frame;
  s32 FirstFrame;
  s32 v11;
  f32 v12;
  struct pmdDataInfo_t_array *Data;
  struct dds3Effect_PartialMultiBlurParam_t_array *MBlurTable;
  s64 v16;
  pmdFrameTable_t_o *v18;
  s32 v19;
  struct pmdDataInfo_t_array *v21;
  struct pmdDataInfo_t_array *v23;
  struct dds3Effect_PartialMultiBlurParam_t_array *v24;
  s64 v26;
  dds3Effect_PartialMultiBlurParam_t_o *MBlurFrameFunc_mbl;

  Frame = f->Frame;
  if (Frame <= now)
    goto LABEL_38;
LABEL_6:
  FirstFrame = wdata->CutInfo->FirstFrame;
  v11 = Frame - FirstFrame;
  if (Frame != FirstFrame)
    goto LABEL_7;
LABEL_42:
  v12 = 0.0;
  Data = f->Data;
  MBlurTable = wdata->MBlurTable;
  if (!LODWORD(Data->max_length))
  {
LABEL_8:
  }
LABEL_9:
  v16 = *&Data->m_Items[0].c2;
  v18 = MBlurTable->m_Items[v16];
  if (Frame > now)
  {
    v19 = 1;
    nf = v18;
    v18 = 0;
      goto LABEL_25;
    goto LABEL_23;
  }
  v21 = f->Data;
  v19 = *&v21->m_Items[0].c0;
  if (nf)
  {
    v23 = nf->Data;
    v24 = wdata->MBlurTable;
    v26 = *&v23->m_Items[0].c2;
    nf = v24->m_Items[v26];
  }
  {
LABEL_23:
  }
LABEL_25:
  evtHokanMultBlur(v19, v12, v18, nf, &MBlurFrameFunc_mbl);
  Eve_PartialMultiBlurSetParam(MBlurFrameFunc_mbl);
  if (HIBYTE(MBlurFrameFunc_mbl->Blur->abgr) > 2u)
  {
    Eve_PartialMultiBlurON();
  }
  else
  {
    Eve_PartialMultiBlurOFF();
  }
}

// 0x10fde40
void MFilterFrameFunc(pmdProcessWork_t *wdata, pmdFrameTable_t *f, pmdFrameTable_t *nf, s32 now) {
  s32 Frame;
  s32 FirstFrame;
  s32 v11;
  f32 v12;
  struct pmdDataInfo_t_array *Data;
  struct dds3Effect_PartialMultiFilterParam_t_array *MFilterTable;
  s64 v16;
  pmdFrameTable_t_o *v18;
  s32 v19;
  struct pmdDataInfo_t_array *v21;
  struct pmdDataInfo_t_array *v23;
  struct dds3Effect_PartialMultiFilterParam_t_array *v24;
  s64 v26;
  dds3Effect_PartialMultiFilterParam_t_o *MFilterFrameFunc_mfl;

  Frame = f->Frame;
  if (Frame <= now)
    goto LABEL_38;
LABEL_6:
  FirstFrame = wdata->CutInfo->FirstFrame;
  v11 = Frame - FirstFrame;
  if (Frame != FirstFrame)
    goto LABEL_7;
LABEL_42:
  v12 = 0.0;
  Data = f->Data;
  MFilterTable = wdata->MFilterTable;
  if (!LODWORD(Data->max_length))
  {
LABEL_8:
  }
LABEL_9:
  v16 = *&Data->m_Items[0].c2;
  v18 = MFilterTable->m_Items[v16];
  if (Frame > now)
  {
    v19 = 1;
    nf = v18;
    v18 = 0;
      goto LABEL_25;
    goto LABEL_23;
  }
  v21 = f->Data;
  v19 = *&v21->m_Items[0].c0;
  if (nf)
  {
    v23 = nf->Data;
    v24 = wdata->MFilterTable;
    v26 = *&v23->m_Items[0].c2;
    nf = v24->m_Items[v26];
  }
  {
LABEL_23:
  }
LABEL_25:
  evtHokanMultFilter(v19, v12, v18, nf, &MFilterFrameFunc_mfl);
  Eve_PartialMultiFilterSetParam(MFilterFrameFunc_mfl);
  if (HIBYTE(MFilterFrameFunc_mfl->Filter->abgr) > 2u)
  {
    Eve_PartialMultiFilterON();
  }
  else
  {
    Eve_PartialMultiFilterOFF();
  }
}

// 0x10f9490
void MG12FrameFunc(pmdProcessWork_t *wdata, pmdFrameTable_t *f, pmdFrameTable_t *nf, s32 now) {
  struct pmdDataInfo_t_array *Data;
  s32 v9;
  s8 v10;
  struct pmdDataInfo_t_array *v12;
  struct pmdDataInfo_t_array *v14;
  struct pmdDataInfo_t_array *v15;
  s32 c0;
  struct pmdDataInfo_t_array *v18;
  struct pmdDataInfo_t_array *v22;
  struct dds3Basic_t_array *EffectBasicTable;
  s64 v25;
  dds3Basic_t_o *v27;
  struct pmdDataInfo_t_array *v28;
  s32 i_low;
  struct pmdDataInfo_t_array *v32;
  struct pmdDataInfo_t_array *v35;
  struct pmdDataInfo_t_array *v38;
  dds3Basic_t_o *v40;
  dds3Basic_t_o *p3;
  dds3Basic_t_o *p2;
  dds3Basic_t_o *p1;
  dds3Basic_t_o *eff;

  eff = 0;
  p2 = 0;
  p1 = 0;
  v40 = 0;
  p3 = 0;
  Data = f->Data;
  if (f->Frame == now)
  {
    v10 = AddEffectTableMG12(v9, wdata, f, *&now);
    Data->m_Items[0].c0 = v10;
    v12 = f->Data;
    if (!LODWORD(v12->max_length))
      goto LABEL_27;
  }
  else
  {
    if (*&Data->m_Items[0].c2 < 1)
      goto LABEL_26;
    v14 = f->Data;
    if (*&v14->m_Items[0].c2 == now)
    {
      v15 = f->Data;
      c0 = v15->m_Items[0].c0;
      DelEffectTable(wdata, c0, nf);
      v18 = f->Data;
      v18->m_Items[0].c0 = -1;
      v12 = f->Data;
      if (!LODWORD(v12->max_length))
      {
LABEL_27:
      }
    }
    else
    {
LABEL_26:
      v12 = f->Data;
      if (!LODWORD(v12->max_length))
        goto LABEL_27;
    }
  }
  if ((v12->m_Items[0].c0 & 0x80000000) == 0)
  {
    v22 = f->Data;
    EffectBasicTable = wdata->EffectBasicTable;
    v25 = v22->m_Items[0].c0;
    v27 = EffectBasicTable->m_Items[v25];
    eff = v27;
    if (v27)
    {
      if (f->Length && f->Length == now)
      {
        evtEffectLoopControl(v27, 0);
      }
      if (f->ObjectType == 21)
      {
        v28 = f->Data;
        i_low = SLOBYTE(v28->m_Items[0].i);
        p1 = SearchBasicFromNameIndex(wdata, i_low, nf);
        v32 = f->Data;
        p2 = SearchBasicFromNameIndex(wdata, SBYTE1(v32->m_Items[0].i));
        v35 = f->Data;
        p3 = SearchBasicFromNameIndex(wdata, SBYTE2(v35->m_Items[0].i));
        v38 = f->Data;
        v40 = SearchBasicFromNameIndex(wdata, SHIBYTE(v38->m_Items[0].i));
        dds3EffectObjectSetMG12Pos(&eff, &p1, &p2, &p3, &v40);
      }
    }
  }
}

// 0x10f7410
void QuakeFrameFunc(pmdProcessWork_t *wdata, pmdFrameTable_t *f, pmdFrameTable_t *nf, s32 now) {
  struct pmdDataInfo_t_array *Data;
  s32 Length;
  struct pmdDataInfo_t_array *v9;
  u32 v11;

  if (f->Frame == now)
  {
    Data = f->Data;
    if (*&Data->m_Items[0].c0)
    {
      Length = f->Length;
      v9 = f->Data;
      v11 = *&v9->m_Items[0].c0;
      dds3SetQuake(Length, v11);
    }
    else
    {
      dds3StopQuake();
    }
  }
}

// 0x10fd560
void RBlurFrameFunc(pmdProcessWork_t *wdata, pmdFrameTable_t *f, pmdFrameTable_t *nf, s32 now) {
  s32 Frame;
  s32 FirstFrame;
  s32 v11;
  f32 v12;
  struct pmdDataInfo_t_array *Data;
  struct dds3Effect_RippleBlurParam_t_array *RBlurTable;
  s64 v16;
  pmdFrameTable_t_o *v18;
  s32 v19;
  struct pmdDataInfo_t_array *v21;
  struct pmdDataInfo_t_array *v23;
  struct dds3Effect_RippleBlurParam_t_array *v24;
  s64 v26;
  dds3Effect_RippleBlurParam_t_o *RBlurFrameFunc_rbl;

  Frame = f->Frame;
  if (Frame <= now)
    goto LABEL_38;
LABEL_6:
  FirstFrame = wdata->CutInfo->FirstFrame;
  v11 = Frame - FirstFrame;
  if (Frame != FirstFrame)
    goto LABEL_7;
LABEL_42:
  v12 = 0.0;
  Data = f->Data;
  RBlurTable = wdata->RBlurTable;
  if (!LODWORD(Data->max_length))
  {
LABEL_8:
  }
LABEL_9:
  v16 = *&Data->m_Items[0].c2;
  v18 = RBlurTable->m_Items[v16];
  if (Frame > now)
  {
    v19 = 1;
    nf = v18;
    v18 = 0;
      goto LABEL_25;
    goto LABEL_23;
  }
  v21 = f->Data;
  v19 = *&v21->m_Items[0].c0;
  if (nf)
  {
    v23 = nf->Data;
    v24 = wdata->RBlurTable;
    v26 = *&v23->m_Items[0].c2;
    nf = v24->m_Items[v26];
  }
  {
LABEL_23:
  }
LABEL_25:
  evtHokanRipBlur(v19, v12, v18, nf, &RBlurFrameFunc_rbl);
  Eve_RippleBlurSetParam(RBlurFrameFunc_rbl);
  if (HIBYTE(RBlurFrameFunc_rbl->abgr) > 2u)
  {
    Eve_RippleBlurON();
  }
  else
  {
    Eve_RippleBlurOFF();
  }
}

// 0x10fab80
void SFogFrameFunc(pmdProcessWork_t *wdata, pmdFrameTable_t *f, pmdFrameTable_t *nf, s32 now) {
  s32 Frame;
  s32 FirstFrame;
  s32 v11;
  f32 v12;
  struct pmdSceneFogTable_t_array *SFogTable;
  s64 Length;
  pmdFrameTable_t_o *v16;
  s32 v17;
  struct pmdDataInfo_t_array *Data;
  struct pmdSceneFogTable_t_array *v21;
  s64 v22;
  struct pmdSceneFogTable_t_o *SFogFrameFunc_sf;
  f32 Min;
  f32 Max;
  f32 Far;
  f32 Near;

  Frame = f->Frame;
  if (Frame <= now)
    goto LABEL_9;
LABEL_6:
  FirstFrame = wdata->CutInfo->FirstFrame;
  v11 = Frame - FirstFrame;
  if (Frame != FirstFrame)
  {
LABEL_7:
    v12 = (now - FirstFrame) / v11;
    goto LABEL_14;
  }
LABEL_13:
  v12 = 0.0;
LABEL_14:
  SFogTable = wdata->SFogTable;
  Length = f->Length;
  v16 = SFogTable->m_Items[Length];
  if (Frame > now)
  {
    v17 = 1;
    nf = v16;
    v16 = 0;
      goto LABEL_28;
    goto LABEL_26;
  }
  Data = f->Data;
  v17 = *&Data->m_Items[0].c0;
  if (nf)
  {
    v21 = wdata->SFogTable;
    v22 = nf->Length;
    nf = v21->m_Items[v22];
  }
  {
LABEL_26:
  }
LABEL_28:
  evtHokanSceneFog(v17, v12, v16, nf, &SFogFrameFunc_sf);
  Min = SFogFrameFunc_sf->Min;
  Max = SFogFrameFunc_sf->Max;
  Near = SFogFrameFunc_sf->Near;
  Far = SFogFrameFunc_sf->Far;
  dds3SetFogPara(0, Max, Min, Near, Far);
  dds3FogParam->color = SFogFrameFunc_sf->Color;
}

// 0x10fa550
void SLightFrameFunc(pmdProcessWork_t *wdata, pmdFrameTable_t *f, pmdFrameTable_t *nf, s32 now) {
  u64 *v9;
  u64 *v10;
  s32 Frame;
  s32 FirstFrame;
  s32 v15;
  f32 v16;
  struct pmdSceneLightTable_t_array *SLightTable;
  s64 Length;
  struct pmdDataInfo_t_array *Data;
  pmdSceneLightTable_t_o *v21;
  u32 max_length;
  f32 v23;
  f32 v24;
  f32 v25;
  s32 NameIndex;
  pmdSceneLightTable_t_o *v27;
  struct pmdSceneLightTable_t_array *v31;
  s64 v32;
  struct pmdDataInfo_t_array *v34;
  u32 v35;
  struct pmdSceneLightTable_t_o *SLightFrameFunc_sl;
  f32 x;
  f32 y;
  f32 w;
  f32 z;
  f32 v46;
  UnityEngine_Vector4_o v47;

  v9 = Allocate(pmdSceneLightTable_t);
  pmdSceneLightTable_t___ctor(v9);
  v10 = Allocate(pmdSceneLightTable_t);
  pmdSceneLightTable_t___ctor(v10);
  Frame = f->Frame;
  if (Frame <= now)
    goto LABEL_9;
LABEL_6:
  FirstFrame = wdata->CutInfo->FirstFrame;
  v15 = Frame - FirstFrame;
  if (Frame != FirstFrame)
  {
LABEL_7:
    v16 = (now - FirstFrame) / v15;
    goto LABEL_14;
  }
LABEL_13:
  v16 = 0.0;
LABEL_14:
  SLightTable = wdata->SLightTable;
  Length = f->Length;
  Data = f->Data;
  v21 = SLightTable->m_Items[Length];
  max_length = Data->max_length;
  v23 = *&Data->m_Items[0].c0;
  v24 = *&Data->m_Items[0].i;
  if (Frame > now)
  {
    v25 = *&Data->m_Items[0].c0;
    v23 = 7.0;
    v46 = *&Data->m_Items[0].i;
    v24 = 0.0;
    NameIndex = 1;
    v27 = v21;
    v21 = 0;
      goto LABEL_33;
    goto LABEL_20;
  }
  NameIndex = f->NameIndex;
  if (!nf)
  {
    v27 = 0;
    v25 = 7.0;
    v46 = 0.0;
      goto LABEL_33;
    goto LABEL_20;
  }
  v31 = wdata->SLightTable;
  v32 = nf->Length;
  v34 = nf->Data;
  v27 = v31->m_Items[v32];
  v35 = v34->max_length;
  v25 = *&v34->m_Items[0].c0;
  v46 = *&nf->Data->m_Items[0].i;
  {
LABEL_20:
  }
LABEL_33:
  evtHokanSceneLight(NameIndex, v16, v21, v27, &SLightFrameFunc_sl);
  x = SLightFrameFunc_sl->Color.x;
  y = SLightFrameFunc_sl->Color.y;
  z = SLightFrameFunc_sl->Color.z;
  w = SLightFrameFunc_sl->Color.w;
  v47.x = x;
  v47.y = y;
  v47.z = z;
  v47.w = w;
  dds3SetLightColor(0, 0, v47);
  dds3SetLightDir(0, 0, SLightFrameFunc_sl->Dir);
  dds3SetAmbientColor(0, SLightFrameFunc_sl->Ambient);
  if (NameIndex)
    v23 = (v16 * v25) + ((1.0 - v16) * v23);
  sdfFaceDivSoften = v23;
  if (NameIndex)
    v24 = (v16 * v46) + ((1.0 - v16) * v24);
  sdfFaceDivBias = v24;
}

// 0x10f7700
void SeFrameFunc(pmdProcessWork_t *wdata, pmdFrameTable_t *f, pmdFrameTable_t *nf, s32 now) {
  struct pmdDataInfo_t_array *Data;

  if (f->Frame == now)
  {
    Data = f->Data;
    evtPlaySe(wdata->EventNo, *&Data->m_Items[0].c0);
  }
}

// 0x10f9300
dds3Basic_t *SearchBasicFromNameIndex(pmdProcessWork_t *wdata, s32 nameindex) {
  dds3Basic_t_o *ActiveScene;
  struct pmdNameTable_t_array *NameTable2;
  dds3SceneBasic_t_o *workdata;
  System_String_o *Name;
  dds3SceneBasic_t_c *klass;
  s64 typeHierarchyDepth;
  char *v14;
  s64 *v15;
  u64 v17[3];

  if ((nameindex & 0x80000000) == 0)
  {
    ActiveScene = dds3GetActiveScene();
    NameTable2 = wdata->NameTable2;
    workdata = ActiveScene->workdata;
    Name = NameTable2->m_Items[nameindex]->Name;
    else if (workdata)
    {
LABEL_12:
      klass = workdata->klass;
      if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v17);
        if ((v17[0] & 1) != 0)
          v14 = v17[2];
        else
          v14 = v17 + 1;
        v15 = sub_8C4940(v14);
      }
    }
    return dds3SceneBasicSearchNameAndType_(workdata, 7u, Name);
  }
  return 0;
}

// 0x1103970
void SetPMFileName(s32 eventno, s32 cutno, char **pm1file, char **pm2file) {
  s64 *DLCTag;
  System_Object_array *v10;
  s64 *v11;
  s64 *v12;
  s64 *v16;
  s64 *v17;
  s64 *v19;
  s64 *v20;
  System_Object_array *v22;
  s64 *v23;
  s64 *v24;
  s64 *v31;
  s64 *v32;
  s64 *v34;
  s64 *v35;
  s32 v40;
  s32 v41;
  s32 v42;
  s32 v43;
  s32 v44;
  s32 v45;

  DLCTag = GetDLCTag(eventno);
  v45 = eventno;
  v10 = NewSpecific(object, 4u);
  v11 = sub_8D3950(s32, &v45);
  v12 = v11;
  v10->m_Items[0] = v12;
  v10->m_Items[1] = DLCTag;
  v44 = eventno;
  v16 = sub_8D3950(s32, &v44);
  v17 = v16;
  v10->m_Items[2] = v17;
  v43 = cutno;
  v19 = sub_8D3950(s32, &v43);
  v20 = v19;
  v10->m_Items[3] = v20;
  *pm1file = Format_5268784("dds3data/event/e{0:D3}{1}/e{2:D3}_{3:D3}.PM1.bytes", v10);
  v22 = NewSpecific(object, 4u);
  v42 = eventno;
  v23 = sub_8D3950(s32, &v42);
  v24 = v23;
  v22->m_Items[0] = v24;
  v22->m_Items[1] = DLCTag;
  v41 = eventno;
  v31 = sub_8D3950(s32, &v41);
  v32 = v31;
  v22->m_Items[2] = v32;
  v40 = cutno;
  v34 = sub_8D3950(s32, &v40);
  v35 = v34;
  v22->m_Items[3] = v35;
  *pm2file = Format_5268784("dds3data/event/e{0:D3}{1}/e{2:D3}_{3:D3}.PM2.bytes", v22);
}

// 0x10f9f20
void SkyFrameFunc(pmdProcessWork_t *wdata, pmdFrameTable_t *f, pmdFrameTable_t *nf, s32 now) {
  System_Object_array *v7;
  s64 *v9;
  s64 *v10;
  struct pmdDataInfo_t_array *Data;
  s64 *v15;
  s64 *v16;
  struct pmdDataInfo_t_array *v19;
  s64 *v21;
  s64 *v22;
  System_String_o *v24;
  System_Object_array *v26;
  struct pmdDataInfo_t_array *v28;
  s32 v30;
  s32 v31;
  s32 Frame;
  struct pmdDataInfo_t_array *v34;
  s32 v36;
  s32 v37;
  s32 v38;
  s32 v40;
  struct pmdDataInfo_t_array *v41;
  s32 v43;
  char v50[4];
  s32 i;
  u16 Length;

  if (f->Frame == now)
  {
    v7 = NewSpecific(object, 6u);
    v7->m_Items[0] = "フレームファンクション(フィールドフィルタ) Length:";
    Length = f->Length;
    v9 = sub_8D3950(ushort, &Length);
    v10 = v9;
    v7->m_Items[1] = v10;
    v7->m_Items[2] = " idx:";
    Data = f->Data;
    i = Data->m_Items[0].i;
    v15 = sub_8D3950(s32, &i);
    v16 = v15;
    v7->m_Items[3] = v16;
    v7->m_Items[4] = " alp:";
    v19 = f->Data;
    *v50 = *&v19->m_Items[0].c2;
    v21 = sub_8D3950(s16, v50);
    v22 = v21;
    v7->m_Items[5] = v22;
    v24 = Concat_5270224(v7);
    v26 = Empty_string_();
    Log(v24, v26, 0);
    v28 = f->Data;
    v30 = v28->m_Items[0].i;
    v31 = *&f->Data->m_Items[0].c2;
    Frame = f->Frame;
    if (!Get_Skip_PM_Sky(v30, v31, Frame))
    {
      v34 = f->Data;
      v36 = v34->m_Items[0].i;
      v37 = *&f->Data->m_Items[0].c0;
      v38 = f->Length;
      fldSkySetFilter(v36, v37, v38);
      v40 = f->Length;
      v41 = f->Data;
      v43 = *&v41->m_Items[0].c2;
      evtSetSkyAlpha(v40, v43);
    }
  }
}

// 0x10f65f0
void StartAnimation(pmdProcessWork_t *wdata) {
  u64 *v3;
  u64 v5;
  struct pmdUnitTable_t_array *UnitTable;
  Il2CppClass **v9;
  struct pmdNameTable_t_array *NameTable1;
  s64 name_low;
  Il2CppObject *Name;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v21;
  s64 *v22;
  dds3Basic_t_o *v23;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Component_o *Animator;
  UnityEngine_Object_o *Component_GUILayer;
  UnityEngine_GameObject_o *v29;
  Il2CppObject *v30;
  s32 frame;
  s32 EventNo;
  u64 v33[3];
  char *v34;

  v3 = Allocate(System_Collections_Generic_List_AnimCheckerPMV_);
  __ctor(
    v3);
  wdata->anim_list = v3;
  _Clear(v3);
  if (wdata->UnitCount >= 1)
  {
    EventNo = wdata->EventNo;
    frame = wdata->NowFrame - wdata->CutInfo->FirstFrame;
    v5 = 0;
    v34 = v33 + 1;
    do
    {
      UnitTable = wdata->UnitTable;
      v9 = &UnitTable->obj.klass + v5;
      NameTable1 = wdata->NameTable1;
      name_low = SLODWORD(v9[4]->_1.name);
      Name = NameTable1->m_Items[name_low]->Name;
      if (Animator___ContainsKey(replace_list, Name))
      {
        Name = object___get_Item(replace_list, Name);
      }
      workdata = dds3GetControlScene()->workdata;
      else if (workdata)
      {
LABEL_25:
        klass = workdata->klass;
        if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
          || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
        {
          sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v33);
          if ((v33[0] & 1) != 0)
            v21 = v33[2];
          else
            v21 = v34;
          v22 = sub_8C4940(v21);
        }
      }
      v23 = dds3SceneBasicSearchNameAndType_(workdata, 5u, Name);
      if (v23)
      {
        gameObject = v23->gameObject;
        if (!op_Equality(gameObject, 0, 0))
        {
          Animator = GetAnimator(gameObject);
          if (!op_Equality(Animator, 0, 0))
          {
            Component_GUILayer = GetComponent_GUILayer_(Animator);
            Destroy(Component_GUILayer, 1.0, 0);
            v29 = get_gameObject(Animator);
            v30 = AddComponent_object_(v29);
            SetFrame(v30, frame, EventNo != 705, 0);
            _Add(wdata->anim_list, v30);
          }
        }
      }
      ++v5;
    }
    while (v5 < wdata->UnitCount);
  }
}

// 0x1106040
void SwitchAnimation(pmdProcessWork_t *wdata, bool sw) {
  UnityEngine_GameObject_o *ChrObj;
  UnityEngine_Transform_o *transform;
  System_Collections_Generic_Dictionary_ValueCollection_TKey__TValue__o *Values;
  f32 v8;
  UnityEngine_GameObject_o *v9;
  UnityEngine_Transform_o *v10;
  Il2CppObject *Item;
  UnityEngine_GameObject_o *v12;
  UnityEngine_Transform_o *v13;
  Il2CppObject *v14;
  System_Collections_Generic_Dictionary_ValueCollection_Enumerator_TKey__TValue__o v15;
  System_Collections_Generic_Dictionary_ValueCollection_Enumerator_TKey__TValue__o v16;
  UnityEngine_Vector3_o localPosition;
  UnityEngine_Vector3_o v18;
  UnityEngine_Vector3_o v19;
  UnityEngine_Vector3_o v20;

  memset(&v16, 0, sizeof(v16));
  ChrObj = wdata->ChrObj;
  if (!op_Equality(ChrObj, 0, 0))
  {
    transform = get_transform(ChrObj, 0);
    get_childCount(transform);
    Values = Type___get_Values(wdata->ChrList);
    Type___GetEnumerator(&v15, Values);
    v16 = v15;
    if (sw)
      v8 = 0.0;
    else
      v8 = 100000.0;
    if (sw)
    {
      while ((sub_4D4B20(&v16) & 1) != 0)
      {
        v9 = sub_4D4CB0(&v16);
        v10 = get_transform(v9, 0);
        localPosition = get_localPosition(v10);
        v19.y = localPosition.y;
        v19.z = localPosition.z;
        v19.x = v8;
        set_localPosition(v10, v19);
        if (Animator___ContainsKey(wdata->AnmList, v9))
        {
          Item = object___get_Item(wdata->AnmList, v9);
          set_enabled(Item, 1);
        }
      }
    }
    else
    {
      while ((sub_4D4B20(&v16) & 1) != 0)
      {
        v12 = sub_4D4CB0(&v16);
        v13 = get_transform(v12, 0);
        v18 = get_localPosition(v13);
        v20.y = v18.y;
        v20.z = v18.z;
        v20.x = v8;
        set_localPosition(v13, v20);
        if (Animator___ContainsKey(wdata->AnmList, v12))
        {
          v14 = object___get_Item(wdata->AnmList, v12);
          set_enabled(v14, 0);
        }
      }
    }
    nullsub_48(&v16);
  }
}

// 0x10f6cb0
void UnitFrameFunc(pmdProcessWork_t *wdata, pmdFrameTable_t *f, pmdFrameTable_t *nf, s32 now) {
  s64 NameIndex;
  struct pmdNameTable_t_array *NameTable2;
  Il2CppObject *Name;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v20;
  s64 *v21;
  evtUnitHandle_t_o *UnitHandleObjectBasic;
  dds3Basic_t_o *v26;
  struct pmdDataInfo_t_array *Data;
  s32 c0;
  dds3Basic_t_o *v30[3];
  dds3Basic_t_o *b;

  b = 0;
  if (f->Frame == now)
  {
    NameIndex = f->NameIndex;
    if ((NameIndex & 0x8000000000000000LL) == 0)
    {
      NameTable2 = wdata->NameTable2;
      Name = NameTable2->m_Items[NameIndex]->Name;
      if (Animator___ContainsKey(replace_list, Name))
      {
        Name = object___get_Item(replace_list, Name);
      }
      workdata = dds3GetControlScene()->workdata;
      else if (workdata)
      {
LABEL_21:
        klass = workdata->klass;
        if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
          || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
        {
          sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v30);
          if ((v30[0] & 1) != 0)
            v20 = v30[2];
          else
            v20 = v30 + 1;
          v21 = sub_8C4940(v20);
        }
      }
      b = dds3SceneBasicSearchNameAndType_(workdata, 5u, Name);
      if (b)
      {
        UnitHandleObjectBasic = dds3GetUnitHandleObjectBasic(&b);
        v26 = b;
        UnitHandleObjectBasic->Model->Owner = b;
        Data = f->Data;
        c0 = Data->m_Items[0].c0;
        evtRunUnitMode(wdata, v26, c0);
      }
    }
  }
}

// 0x1103360
void _mdlHide(pmdProcessWork_t *wdata, dds3ModelHandle_t *mdl) {
  struct dds3Basic_t_o *Owner;
  UnityEngine_Object_o *gameObject;
  bool v7;
  f32 y;
  bool v9;
  System_Collections_Generic_Dictionary_string__float__o *hide_ypos;
  System_String_o *name;

  Owner = mdl->Owner;
  if (Owner)
  {
    gameObject = Owner->gameObject;
    if (op_Inequality(gameObject, 0, 0) && !IsNullOrEmpty(Owner->name))
    {
      v7 = float___ContainsKey(wdata->hide_ypos, Owner->name);
      y = Owner->poseset->pos.y;
      v9 = v7;
      hide_ypos = wdata->hide_ypos;
      name = Owner->name;
      if (v9)
        float___set_Item(hide_ypos, name, y);
      else
        float___Add(hide_ypos, name, y);
      Owner->poseset->pos.y = 100000.0;
    }
  }
  else
  {
    mdlShow(mdl);
  }
}

// 0x1103220
void _mdlShow(pmdProcessWork_t *wdata, dds3ModelHandle_t *mdl) {
  struct dds3Basic_t_o *Owner;
  UnityEngine_Object_o *gameObject;
  struct dds3PoseSet_t_o *poseset;

  Owner = mdl->Owner;
  if (Owner)
  {
    gameObject = Owner->gameObject;
    if (op_Inequality(gameObject, 0, 0)
      && !IsNullOrEmpty(Owner->name)
      && float___ContainsKey(wdata->hide_ypos, Owner->name))
    {
      poseset = Owner->poseset;
      poseset->pos.y = float___get_Item(wdata->hide_ypos, Owner->name);
      float___Remove(wdata->hide_ypos, Owner->name);
    }
  }
  else
  {
    mdlShow(mdl);
  }
}

// 0x1106f70
void attach(dds3Basic_t *basic, void *obj) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v9;
  System_String_o *name;
  char *v11;
  s64 *v12;
  u64 v13[3];

  workdata = basic->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3UnitObjectBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3UnitObjectBasicWorkData_t, v13);
    if ((v13[0] & 1) != 0)
      v11 = v13[2];
    else
      v11 = v13 + 1;
    v12 = sub_8C4940(v11);
  }
  v9 = workdata[2].klass;
  if (v9->_1.interfaceOffsets)
    v9->vtable[1].method = obj;
  name = basic->name;
  AttachHD(obj, basic, name, 0);
  UpdateDying(obj);
}

// 0x10f6a20
dds3Basic_t *dds3SceneBasicSearchNameAndType_(dds3SceneBasic_t *scene, u32 type, char *name) {
  dds3Basic_t_o *firstbasic;
  struct dds3SceneBasicTable_t_array *basictable;
  System_String_o *v10;
  struct dds3SceneBasicTable_t_array *v11;
  System_String_o *v13;
  System_String_o *v14;
  System_Object_array *v16;

  firstbasic = 0;
  if (scene && name)
  {
    basictable = scene->basictable;
    firstbasic = basictable->m_Items[type]->firstbasic;
    if (firstbasic)
    {
      while (1)
      {
        v10 = firstbasic->name;
        if (v10)
        {
          if (get_Length(firstbasic->name) && Equals_5239888(v10, name, 4))
            break;
        }
        firstbasic = firstbasic->next;
        if (!firstbasic)
          goto LABEL_12;
      }
    }
    else
    {
LABEL_12:
      v11 = scene->basictable;
      firstbasic = v11->m_Items[type]->firstbasic;
      if (firstbasic)
      {
        while (1)
        {
          v13 = firstbasic->name;
          if (v13)
          {
            if (get_Length(firstbasic->name) && Contains(v13, name, 0))
              break;
          }
          firstbasic = firstbasic->next;
          if (!firstbasic)
            goto LABEL_19;
        }
      }
      else
      {
LABEL_19:
        v14 = Concat_5221536("@@@@ not found : ", name, " @@@@");
        v16 = Empty_string_();
        Log(v14, v16, 0);
        return 0;
      }
    }
  }
  return firstbasic;
}

// 0x1102a90
dds3Basic_t *dds3SearchSceneBasic_(dds3SceneBasic_t *scene, u32 serialID, u32 type) {
  struct dds3SceneBasicTable_t_array *basictable;

  if (scene)
  {
    basictable = scene->basictable;
    for (scene = basictable->m_Items[type]->firstbasic; scene; scene = scene->pScrFileData)
    {
      if (*(&scene->mapno + 1) == serialID)
        break;
    }
  }
  return scene;
}

// 0x1103780
s32 evtCheckPolygonMovieFlag(dds3ProcessID_t *id, u32 flag) {
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  dds3ProcessID_t_o *v10;
  u64 v11[3];

  v10 = id;
  ProcessData = dds3GetProcessData(&v10);
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pmdProcessWork_t)
  {
    sub_8FC2C0(klass->_1.element_class, pmdProcessWork_t, v11);
    if ((v11[0] & 1) != 0)
      v8 = v11[2];
    else
      v8 = v11 + 1;
    v9 = sub_8C4940(v8);
  }
  return (ProcessData[1].klass & flag) != 0;
}

// 0x11014e0
s32 evtCheckPolygonMovieRun(dds3ProcessID_t *id) {
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  dds3ProcessID_t_o *v8[3];
  dds3ProcessID_t_o *ida;

  ida = id;
  else
  {
    ProcessData = dds3GetProcessData(&ida);
    if (!ProcessData)
      return 1;
  }
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pmdProcessWork_t)
  {
    sub_8FC2C0(klass->_1.element_class, pmdProcessWork_t, v8);
    if ((v8[0] & 1) != 0)
      v5 = v8[2];
    else
      v5 = v8 + 1;
    v6 = sub_8C4940(v5);
  }
  return 1;
}

// 0x1103040
void evtFreePolygonMovieWorkData(pmdProcessWork_t *wdata) {
  struct dds3Basic_t_array *EffectBasicTable;
  Il2CppClass **max_length;
  u64 v5;
  s32 MesHandle;

  if (wdata)
  {
    EffectBasicTable = wdata->EffectBasicTable;
    if (EffectBasicTable)
    {
      max_length = EffectBasicTable->max_length;
      if (max_length >= 1)
      {
        v5 = 0;
        do
        {
          max_length = &EffectBasicTable->obj.klass + v5++;
          max_length[4] = 0;
          EffectBasicTable = wdata->EffectBasicTable;
          LODWORD(max_length) = EffectBasicTable->max_length;
        }
        while (v5 < max_length);
      }
      wdata->EffectBasicTable = 0;
    }
    MesHandle = wdata->MesHandle;
    if ((MesHandle & 0x80000000) == 0)
    {
      itfMesMngRelease(MesHandle);
    }
  }
}

// 0x10ffc70
pmdProcessWork_t *evtGetPolygonMovieWorkData1(pmdProcessWork_t *wdata, u8 **pm1data, u8 **pm2data) {
  u64 *v7;
  struct dds3Basic_t_array *EffectBasicTable;
  s64 v9;
  u64 *v11;
  u64 TypeTableCount;
  struct pmdTypeTable_t_array *v13;
  u32 *v15;
  u64 v16;
  u64 v17;
  u64 *v18;
  struct pmdTypeTable_t_array *TypeTable1;
  struct pmdHeader_t_o *Header1;
  u64 v24;
  struct pmdTypeTable_t_array *v25;
  u64 v27;
  char v28;
  u64 *v30;
  u64 k;
  s32 v33;
  u64 v34;
  System_Text_Encoding_o *ASCII;
  s64 v38;
  u32 *NameTable1;
  System_String_o *v40;
  u64 *v41;
  struct pmdNameTable_t_array *v43;
  pmdNameTable_t_o *v45;
  u64 *v46;
  u64 *v47;
  AssetBundleCtrl_o *asset_bc;
  AssetBundleCtrl_o *v51;
  struct pmdUnitTable_t_array *v52;
  u32 *v53;
  u64 i;
  u64 *v55;
  struct pmdUnitTable_t_array *UnitTable;
  struct pmdEffectTable_t_array *v60;
  u32 *v61;
  u64 j;
  u64 *v63;
  struct pmdEffectTable_t_array *EffectTable;
  struct pmdTypeTable_t_array *v68;
  u64 v70;
  struct System_Byte_array *v71;
  struct pmdTypeTable_t_array *v72;
  struct pmdTypeTable_t_array *v74;
  u64 *v76;
  u64 v77;
  struct pmdTypeTable_t_array *v78;
  u32 *v79;
  u64 v80;
  u64 v81;
  u64 *v82;
  struct pmdTypeTable_t_array *TypeTable2;
  struct pmdCutInfo_t_o **p_CutInfo;
  u64 v88;
  struct pmdTypeTable_t_array *v89;
  struct pmdTypeTable_t_array *v90;
  Il2CppClass **v92;
  struct pmdTypeTable_t_array *v93;
  u64 v94;
  u64 *v95;
  u64 v96;
  char v97;
  u64 *v99;
  u64 i4;
  s32 v102;
  u64 v103;
  System_Text_Encoding_o *v106;
  s64 v107;
  u32 *NameTable2;
  System_String_o *v109;
  u64 *v110;
  struct pmdNameTable_t_array *v112;
  pmdNameTable_t_o *v114;
  struct pmdFrameTable_t_array *v115;
  u32 *v116;
  u64 m;
  u64 *v118;
  struct pmdFrameTable_t_array *FrameTable;
  struct pmdCameraTable_t_array *v123;
  u32 *v124;
  u64 n;
  u64 *v126;
  struct pmdCameraTable_t_array *CameraTable;
  struct pmdSceneLightTable_t_array *v131;
  u32 *v132;
  u64 ii;
  u64 *v134;
  struct pmdSceneLightTable_t_array *SLightTable;
  struct pmdSceneFogTable_t_array *v139;
  u32 *v140;
  u64 jj;
  u64 *v142;
  struct pmdSceneFogTable_t_array *SFogTable;
  struct dds3Effect_Blur_t_array *v147;
  u32 *v148;
  u64 kk;
  u64 *v150;
  struct dds3Effect_Blur_t_array *Blur2Table;
  struct dds3Effect_PartialMultiBlurParam_t_array *v155;
  u32 *v156;
  u64 mm;
  u64 *v158;
  struct dds3Effect_PartialMultiBlurParam_t_array *MBlurTable;
  struct dds3Effect_DistortionBlurParam_t_array *v163;
  u32 *v164;
  u64 nn;
  u64 *v166;
  struct dds3Effect_DistortionBlurParam_t_array *DBlurTable;
  struct dds3Effect_Filter_t_array *v171;
  u32 *v172;
  u64 i1;
  u64 *v174;
  struct dds3Effect_Filter_t_array *FilterTable;
  struct dds3Effect_PartialMultiFilterParam_t_array *v179;
  u32 *v180;
  u64 i2;
  u64 *v182;
  struct dds3Effect_PartialMultiFilterParam_t_array *MFilterTable;
  struct dds3Effect_RippleBlurParam_t_array *v187;
  u32 *v188;
  u64 i3;
  u64 *v190;
  struct dds3Effect_RippleBlurParam_t_array *RBlurTable;
  u64 ItemCount;
  s32 MajorNum;
  s32 pos;

  pos = 0;
  v7 = Allocate(System_Collections_Generic_Dictionary_string__float_);
  float____ctor(
    v7);
  wdata->hide_ypos = v7;
  float___Clear(v7);
  if (!pm1data)
    return 0;
  wdata->MesHandle = -1;
  wdata->NowFrame = 0;
  wdata->CameraFirst = 0;
  EffectBasicTable = NewSpecific(dds3Basic_t, 0x7Fu);
  v9 = 0;
  wdata->EffectBasicTable = EffectBasicTable;
  if (!LODWORD(EffectBasicTable->max_length))
  {
LABEL_7:
  }
  while (1)
  {
    EffectBasicTable->m_Items[v9] = 0;
    if (v9 == 126)
      break;
    EffectBasicTable = wdata->EffectBasicTable;
    if (++v9 >= LODWORD(EffectBasicTable->max_length))
      goto LABEL_7;
  }
  pos = 0;
  v11 = Allocate(pmdHeader_t);
  pmdHeader_t___ctor(v11);
  wdata->Header1 = v11;
  pmdHeader_t__SetData(v11, pm1data, &pos);
  TypeTableCount = wdata->Header1->TypeTableCount;
  v13 = NewSpecific(pmdTypeTable_t, TypeTableCount);
  wdata->TypeTable1 = v13;
  if (TypeTableCount >= 1)
  {
    v15 = v13;
    v16 = 0;
    v17 = TypeTableCount - 1;
    while (1)
    {
      v18 = Allocate(pmdTypeTable_t);
      pmdTypeTable_t___ctor(v18);
      *&v15[2 * v16 + 8] = v18;
      TypeTable1 = wdata->TypeTable1;
      pmdTypeTable_t__SetData(TypeTable1->m_Items[v16], pm1data, &pos);
      if (v17 == v16)
        break;
      v15 = wdata->TypeTable1;
      ++v16;
    }
  }
  wdata->UnitData = pm1data;
  MarkTmxIndex(&wdata->UnitData);
  MarkPibIndex(&wdata->UnitData);
  wdata->StageF1 = 0;
  Header1 = wdata->Header1;
  wdata->NameTable1 = 0;
  wdata->NameCount1 = 0;
  wdata->StageTable = 0;
  wdata->StageCount = 0;
  wdata->EffectTable = 0;
  wdata->EffectCount = 0;
  wdata->EffectData = 0;
  wdata->UnitCount = 0;
  wdata->StageF2 = 0;
  wdata->StageTB = 0;
  wdata->UnitTable = 0;
  if (Header1->TypeTableCount >= 1)
  {
    v24 = 0;
    do
    {
      v25 = wdata->TypeTable1;
      pos = v25->m_Items[v24]->ItemAddress;
      ItemCount = v25->m_Items[v24]->ItemCount;
      switch (v25->m_Items[v24]->Type)
      {
        case 1:
          wdata->NameTable1 = NewSpecific(pmdNameTable_t, ItemCount);
          if (ItemCount < 1)
            goto LABEL_50;
          v27 = 0;
          v28 = 1;
          break;
        case 2:
          v46 = Allocate(pmdStageTable_t);
          pmdStageTable_t___ctor(v46);
          wdata->StageTable = v46;
          pmdStageTable_t__SetData(v46, pm1data, &pos);
          MajorNum = wdata->StageTable->MajorNum;
          v47 = sub_8D3950(s32, &MajorNum);
          wdata->fkey = Format("f{0:D3}", v47, 0);
          asset_bc = get_asset_bc();
          if (!IsLoad(asset_bc, wdata->fkey))
          {
            v51 = get_asset_bc();
            Load(v51, wdata->fkey, wdata->fkey, 0);
          }
          wdata->StageCount = ItemCount;
          goto LABEL_96;
        case 3:
          v52 = NewSpecific(pmdUnitTable_t, ItemCount);
          wdata->UnitTable = v52;
          if (ItemCount >= 1)
          {
            v53 = v52;
            for (i = 0; ; ++i)
            {
              v55 = Allocate(pmdUnitTable_t);
              pmdUnitTable_t___ctor(v55);
              *&v53[2 * i + 8] = v55;
              UnitTable = wdata->UnitTable;
              pmdUnitTable_t__SetData(UnitTable->m_Items[i], pm1data, &pos);
              if (ItemCount - 1 == i)
                break;
              v53 = wdata->UnitTable;
            }
          }
          wdata->UnitCount = ItemCount;
          goto LABEL_96;
        case 7:
          v60 = NewSpecific(pmdEffectTable_t, ItemCount);
          wdata->EffectTable = v60;
          if (ItemCount >= 1)
          {
            v61 = v60;
            for (j = 0; ; ++j)
            {
              v63 = Allocate(pmdEffectTable_t);
              pmdEffectTable_t___ctor(v63);
              *&v61[2 * j + 8] = v63;
              EffectTable = wdata->EffectTable;
              pmdEffectTable_t__SetData(EffectTable->m_Items[j], pm1data, &pos);
              if (ItemCount - 1 == j)
                break;
              v61 = wdata->EffectTable;
            }
          }
          wdata->EffectCount = ItemCount;
          goto LABEL_96;
        case 0xA:
          v68 = wdata->TypeTable1;
          v70 = (v68->m_Items[v24]->ItemSize * ItemCount);
          v71 = NewSpecific(byte, v70);
          wdata->StageF1 = v71;
          goto LABEL_93;
        case 0xB:
          v72 = wdata->TypeTable1;
          v70 = (v72->m_Items[v24]->ItemSize * ItemCount);
          v71 = NewSpecific(byte, v70);
          wdata->StageF2 = v71;
          goto LABEL_93;
        case 0xC:
          v74 = wdata->TypeTable1;
          v70 = (v74->m_Items[v24]->ItemSize * ItemCount);
          v71 = NewSpecific(byte, v70);
          wdata->StageTB = v71;
LABEL_93:
          BlockCopy(pm1data, pos, v71, 0, v70);
          goto LABEL_96;
        default:
          goto LABEL_96;
      }
      do
      {
        v30 = NewSpecific(byte, 0x20u);
        for (k = 0; k != 32; ++k)
        {
          if ((v28 & 1) != 0)
          {
            v33 = pm1data->m_Items[k + pos];
            v34 = *(v30 + 6);
            if (k >= v34)
            {
LABEL_39:
            }
          }
          else
          {
            v33 = 0;
            v34 = *(v30 + 6);
            if (k >= v34)
              goto LABEL_39;
          }
          *(v30 + k + 32) = v33;
          v28 &= v33 != 0;
        }
        ASCII = get_ASCII();
        v38 = (ASCII->klass[1]._1.this_arg.data)(ASCII, pm1data, pos, 32, *&ASCII->klass[1]._1.this_arg.bits);
        NameTable1 = wdata->NameTable1;
        v40 = v38;
        v41 = Allocate(pmdNameTable_t);
        pmdNameTable_t___ctor(v41);
        *&NameTable1[2 * v27 + 8] = v41;
        v43 = wdata->NameTable1;
        v45 = v43->m_Items[v27];
        v45->Name = Replace_5267216(v40, " ", "");
        pos += 32;
        ++v27;
      }
      while (v27 != ItemCount);
LABEL_50:
      wdata->NameCount1 = ItemCount;
LABEL_96:
      ++v24;
    }
    while (v24 < wdata->Header1->TypeTableCount);
  }
  pos = 0;
  v76 = Allocate(pmdHeader_t);
  pmdHeader_t___ctor(v76);
  wdata->Header2 = v76;
  pmdHeader_t__SetData(v76, pm2data, &pos);
  if (pm2data)
  {
    v77 = wdata->Header2->TypeTableCount;
    v78 = NewSpecific(pmdTypeTable_t, v77);
    wdata->TypeTable2 = v78;
    if (v77 >= 1)
    {
      v79 = v78;
      v80 = 0;
      v81 = v77 - 1;
      while (1)
      {
        v82 = Allocate(pmdTypeTable_t);
        pmdTypeTable_t___ctor(v82);
        *&v79[2 * v80 + 8] = v82;
        TypeTable2 = wdata->TypeTable2;
        pmdTypeTable_t__SetData(TypeTable2->m_Items[v80], pm2data, &pos);
        if (v81 == v80)
          break;
        v79 = wdata->TypeTable2;
        ++v80;
      }
    }
  }
  else
  {
    wdata->TypeTable2 = 0;
  }
  wdata->NameTable2 = 0;
  wdata->NameCount2 = 0;
  wdata->CameraTable = 0;
  wdata->CameraCount = 0;
  wdata->SLightTable = 0;
  wdata->SLightCount = 0;
  wdata->SFogTable = 0;
  wdata->SFogCount = 0;
  wdata->Blur2Table = 0;
  wdata->Blur2Count = 0;
  wdata->MBlurTable = 0;
  wdata->MBlurCount = 0;
  wdata->DBlurTable = 0;
  wdata->DBlurCount = 0;
  wdata->FilterTable = 0;
  wdata->FilterCount = 0;
  wdata->MFilterTable = 0;
  wdata->MFilterCount = 0;
  wdata->RBlurTable = 0;
  wdata->RBlurCount = 0;
  wdata->CutInfo = 0;
  p_CutInfo = &wdata->CutInfo;
  wdata->FrameCount = 0;
  wdata->FrameTable = 0;
  if (pm2data && wdata->Header2->TypeTableCount >= 1)
  {
    v88 = 0;
    do
    {
      v89 = wdata->TypeTable2;
      v90 = v89;
      v92 = &v89->obj.klass + v88;
      v93 = wdata->TypeTable2;
      pos = HIDWORD(v92[4]->_1.namespaze);
      v94 = v90->m_Items[v88]->ItemCount;
      switch (v93->m_Items[v88]->Type)
      {
        case 0:
          v95 = Allocate(pmdCutInfo_t);
          pmdCutInfo_t___ctor(v95);
          *p_CutInfo = v95;
          pmdCutInfo_t__SetData(v95, pm2data, &pos);
          goto LABEL_271;
        case 1:
          wdata->NameTable2 = NewSpecific(pmdNameTable_t, v94);
          if (v94 < 1)
            goto LABEL_140;
          v96 = 0;
          v97 = 1;
          break;
        case 4:
          v115 = NewSpecific(pmdFrameTable_t, v94);
          wdata->FrameTable = v115;
          if (v94 >= 1)
          {
            v116 = v115;
            for (m = 0; ; ++m)
            {
              v118 = Allocate(pmdFrameTable_t);
              pmdFrameTable_t___ctor(v118);
              *&v116[2 * m + 8] = v118;
              FrameTable = wdata->FrameTable;
              pmdFrameTable_t__SetData(FrameTable->m_Items[m], pm2data, &pos);
              if (v94 - 1 == m)
                break;
              v116 = wdata->FrameTable;
            }
          }
          wdata->FrameCount = v94;
          goto LABEL_271;
        case 5:
          v123 = NewSpecific(pmdCameraTable_t, v94);
          wdata->CameraTable = v123;
          if (v94 >= 1)
          {
            v124 = v123;
            for (n = 0; ; ++n)
            {
              v126 = Allocate(pmdCameraTable_t);
              pmdCameraTable_t___ctor(v126);
              *&v124[2 * n + 8] = v126;
              CameraTable = wdata->CameraTable;
              pmdCameraTable_t__SetData(CameraTable->m_Items[n], pm2data, &pos);
              if (v94 - 1 == n)
                break;
              v124 = wdata->CameraTable;
            }
          }
          wdata->CameraCount = v94;
          goto LABEL_271;
        case 0xD:
          v131 = NewSpecific(pmdSceneLightTable_t, v94);
          wdata->SLightTable = v131;
          if (v94 >= 1)
          {
            v132 = v131;
            for (ii = 0; ; ++ii)
            {
              v134 = Allocate(pmdSceneLightTable_t);
              pmdSceneLightTable_t___ctor(v134);
              *&v132[2 * ii + 8] = v134;
              SLightTable = wdata->SLightTable;
              pmdSceneLightTable_t__SetData(SLightTable->m_Items[ii], pm2data, &pos);
              if (v94 - 1 == ii)
                break;
              v132 = wdata->SLightTable;
            }
          }
          wdata->SLightCount = v94;
          goto LABEL_271;
        case 0xE:
          v139 = NewSpecific(pmdSceneFogTable_t, v94);
          wdata->SFogTable = v139;
          if (v94 >= 1)
          {
            v140 = v139;
            for (jj = 0; ; ++jj)
            {
              v142 = Allocate(pmdSceneFogTable_t);
              pmdSceneFogTable_t___ctor(v142);
              *&v140[2 * jj + 8] = v142;
              SFogTable = wdata->SFogTable;
              pmdSceneFogTable_t__SetData(SFogTable->m_Items[jj], pm2data, &pos);
              if (v94 - 1 == jj)
                break;
              v140 = wdata->SFogTable;
            }
          }
          wdata->SFogCount = v94;
          goto LABEL_271;
        case 0xF:
          v147 = NewSpecific(dds3Effect_Blur_t, v94);
          wdata->Blur2Table = v147;
          if (v94 >= 1)
          {
            v148 = v147;
            for (kk = 0; ; ++kk)
            {
              v150 = Allocate(dds3Effect_Blur_t);
              dds3Effect_Blur_t___ctor(v150);
              *&v148[2 * kk + 8] = v150;
              Blur2Table = wdata->Blur2Table;
              dds3Effect_Blur_t__SetData(Blur2Table->m_Items[kk], pm2data, &pos);
              if (v94 - 1 == kk)
                break;
              v148 = wdata->Blur2Table;
            }
          }
          wdata->Blur2Count = v94;
          goto LABEL_271;
        case 0x10:
          v155 = NewSpecific(dds3Effect_PartialMultiBlurParam_t, v94);
          wdata->MBlurTable = v155;
          if (v94 >= 1)
          {
            v156 = v155;
            for (mm = 0; ; ++mm)
            {
              v158 = Allocate(dds3Effect_PartialMultiBlurParam_t);
              dds3Effect_PartialMultiBlurParam_t___ctor(v158);
              *&v156[2 * mm + 8] = v158;
              MBlurTable = wdata->MBlurTable;
              dds3Effect_PartialMultiBlurParam_t__SetData(MBlurTable->m_Items[mm], pm2data, &pos);
              if (v94 - 1 == mm)
                break;
              v156 = wdata->MBlurTable;
            }
          }
          wdata->MBlurCount = v94;
          goto LABEL_271;
        case 0x11:
          v163 = NewSpecific(dds3Effect_DistortionBlurParam_t, v94);
          wdata->DBlurTable = v163;
          if (v94 >= 1)
          {
            v164 = v163;
            for (nn = 0; ; ++nn)
            {
              v166 = Allocate(dds3Effect_DistortionBlurParam_t);
              dds3Effect_DistortionBlurParam_t___ctor(v166);
              *&v164[2 * nn + 8] = v166;
              DBlurTable = wdata->DBlurTable;
              dds3Effect_DistortionBlurParam_t__SetData(DBlurTable->m_Items[nn], pm2data, &pos);
              if (v94 - 1 == nn)
                break;
              v164 = wdata->DBlurTable;
            }
          }
          wdata->DBlurCount = v94;
          goto LABEL_271;
        case 0x12:
          v171 = NewSpecific(dds3Effect_Filter_t, v94);
          wdata->FilterTable = v171;
          if (v94 >= 1)
          {
            v172 = v171;
            for (i1 = 0; ; ++i1)
            {
              v174 = Allocate(dds3Effect_Filter_t);
              dds3Effect_Filter_t___ctor(v174);
              *&v172[2 * i1 + 8] = v174;
              FilterTable = wdata->FilterTable;
              dds3Effect_Filter_t__SetData(FilterTable->m_Items[i1], pm2data, &pos);
              if (v94 - 1 == i1)
                break;
              v172 = wdata->FilterTable;
            }
          }
          wdata->FilterCount = v94;
          goto LABEL_271;
        case 0x13:
          v179 = NewSpecific(dds3Effect_PartialMultiFilterParam_t, v94);
          wdata->MFilterTable = v179;
          if (v94 >= 1)
          {
            v180 = v179;
            for (i2 = 0; ; ++i2)
            {
              v182 = Allocate(dds3Effect_PartialMultiFilterParam_t);
              dds3Effect_PartialMultiFilterParam_t___ctor(v182);
              *&v180[2 * i2 + 8] = v182;
              MFilterTable = wdata->MFilterTable;
              dds3Effect_PartialMultiFilterParam_t__SetData(MFilterTable->m_Items[i2], pm2data, &pos);
              if (v94 - 1 == i2)
                break;
              v180 = wdata->MFilterTable;
            }
          }
          wdata->MFilterCount = v94;
          goto LABEL_271;
        case 0x14:
          v187 = NewSpecific(dds3Effect_RippleBlurParam_t, v94);
          wdata->RBlurTable = v187;
          if (v94 >= 1)
          {
            v188 = v187;
            for (i3 = 0; ; ++i3)
            {
              v190 = Allocate(dds3Effect_RippleBlurParam_t);
              dds3Effect_RippleBlurParam_t___ctor(v190);
              *&v188[2 * i3 + 8] = v190;
              RBlurTable = wdata->RBlurTable;
              dds3Effect_RippleBlurParam_t__SetData(RBlurTable->m_Items[i3], pm2data, &pos);
              if (v94 - 1 == i3)
                break;
              v188 = wdata->RBlurTable;
            }
          }
          wdata->RBlurCount = v94;
          goto LABEL_271;
        default:
          goto LABEL_271;
      }
      do
      {
        v99 = NewSpecific(byte, 0x20u);
        for (i4 = 0; i4 != 32; ++i4)
        {
          if ((v97 & 1) != 0)
          {
            v102 = pm2data->m_Items[i4 + pos];
            v103 = *(v99 + 6);
            if (i4 >= v103)
            {
LABEL_129:
            }
          }
          else
          {
            v102 = 0;
            v103 = *(v99 + 6);
            if (i4 >= v103)
              goto LABEL_129;
          }
          *(v99 + i4 + 32) = v102;
          v97 &= v102 != 0;
        }
        v106 = get_ASCII();
        v107 = (v106->klass[1]._1.this_arg.data)(v106, pm2data, pos, 32, *&v106->klass[1]._1.this_arg.bits);
        NameTable2 = wdata->NameTable2;
        v109 = v107;
        v110 = Allocate(pmdNameTable_t);
        pmdNameTable_t___ctor(v110);
        *&NameTable2[2 * v96 + 8] = v110;
        v112 = wdata->NameTable2;
        v114 = v112->m_Items[v96];
        v114->Name = Replace_5267216(v109, " ", "");
        ++v96;
        pos += 32;
      }
      while (v96 != v94);
LABEL_140:
      p_CutInfo = &wdata->CutInfo;
      wdata->NameCount2 = v94;
LABEL_271:
      ++v88;
    }
    while (v88 < wdata->Header2->TypeTableCount);
  }
  return wdata;
}

// 0x1103dc0
pmdProcessWork_t *evtGetPolygonMovieWorkData2(s32 eventno, s32 cutno, s32 type) {
  u64 *v7;
  u64 *v8;
  System_String_o *v10;
  System_String_o *DLCTag;
  System_String_o *v14;
  System_String_o *v16;
  s64 *Data;
  System_Byte_array *FileByte;
  AssetBundleCtrl_o *v24;
  System_Byte_array *pm2_dummydata;
  evtPolygonMovie_c *v26;
  AssetBundleCtrl_o *asset_bc;
  pmdProcessWork_t_o *v31;
  s32 v35;
  System_String_o *pm2file;
  System_String_o *pm1file;

  v7 = Allocate(pmdProcessWork_t);
  pmdProcessWork_t___ctor(v7);
  pm2file = 0;
  pm1file = 0;
  v35 = eventno;
  v8 = sub_8D3950(s32, &v35);
  v10 = Format("e{0:D3}", v8, 0);
  DLCTag = GetDLCTag(eventno);
  v14 = Concat_5224608(v10, DLCTag);
  SetPMFileName(eventno, cutno, &pm1file, &pm2file);
  v16 = pm1file;
  else
  {
    Data = GetData(pm1file);
    if (Data)
      goto LABEL_12;
  }
  asset_bc = get_asset_bc();
  FileByte = LoadFileByte(asset_bc, v14, v16);
  if (!FileByte)
    return 0;
  if (!type)
  {
LABEL_14:
    v24 = get_asset_bc();
    pm2_dummydata = LoadFileByte(v24, v14, pm2file);
      goto LABEL_18;
LABEL_35:
    if ((byte_3F58A01 & 1) != 0)
      goto LABEL_37;
    goto LABEL_36;
  }
LABEL_31:
  if ((v26->_2.bitflags2 & 2) == 0)
    goto LABEL_35;
LABEL_18:
    goto LABEL_35;
  if ((byte_3F58A01 & 1) != 0)
    goto LABEL_37;
LABEL_36:
LABEL_37:
  v31 = Allocate(pmdProcessWork_t);
  pmdProcessWork_t___ctor(v31);
  evtGetPolygonMovieWorkData1(v31, FileByte, pm2_dummydata);
  if (!v31)
  {
    evtFreePolygonMovieWorkData(0);
    return 0;
  }
  v31->EventNo = eventno;
  v31->CutNo = cutno;
  return v31;
}

// 0x10fb2f0
void evtHokanBlur2(s32 hokan, f32 ratio, dds3Effect_Blur_t *key1, dds3Effect_Blur_t *key2, dds3Effect_Blur_t **d) {
  dds3Effect_Blur_t_o *v10;
  sdfIVector2_t_o *v12;
  struct System_Int32_array *v13;
  u32 max_length;
  u64 *v16;
  sdfIVector2_t_o *v17;
  sdfIVector2_t_o *v19;
  struct System_Int32_array *v21;
  s32 screen_wid;
  u32 v24;
  dds3Effect_Blur_t_o *v28;
  dds3Effect_Blur_t_o *v29;
  u32 abgr;
  u32 v31;
  f32 rotate;
  dds3Effect_Blur_t_o *v33;
  f32 v34;
  struct System_Int32_array *v35;
  struct System_Int32_array *v36;
  struct System_Int32_array *v38;
  s32 v39;
  s32 v40;
  struct System_Int32_array *pm;
  struct System_Int32_array *v43;
  s32 v45;
  s32 v49;
  struct System_Int32_array *v51;
  struct System_Int32_array *v52;
  struct System_Int32_array *v54;
  s32 v55;
  s32 v56;
  s32 v58;
  s64 v60;
  u64 v61;
  u32 *xy;
  u64 *v63;
  struct sdfIVector2_t_array *v66;
  u64 max_length_low;
  struct sdfIVector2_t_array *v69;
  struct System_Int32_array *v70;
  struct System_Int32_array *v72;
  struct sdfIVector2_t_array *v74;
  s32 v75;
  struct System_Int32_array *v77;
  s32 v78;
  struct sdfIVector2_t_array *v80;
  struct System_Int32_array *v81;
  struct System_Int32_array *v83;
  struct sdfIVector2_t_array *v85;
  s32 v86;
  s32 v90;
  struct sdfIVector2_t_array *v92;
  struct sdfIVector2_t_array *v94;
  struct System_Int32_array *v95;
  struct System_Int32_array *v97;
  struct sdfIVector2_t_array *v99;
  s32 v100;
  struct System_Int32_array *v102;
  s32 v103;
  s32 v105;
  struct sdfIVector2_t_array *v108;
  struct sdfIVector2_t_array *v110;
  struct System_Int32_array *v112;
  struct sdfIVector2_t_array *v114;
  struct System_Int32_array *v120;

  v10 = Allocate(dds3Effect_Blur_t);
  dds3Effect_Blur_t___ctor(v10);
  v10->abgr = 8421504;
  v10->blend = DDS3EFFECT_BLEND_SEMI();
  *&v10->rotate = 0x3F7C6A7F3CA3D70ALL;
  v12 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v12);
  v13 = NewSpecific(s32, 2u);
  max_length = v13->max_length;
  v13->m_Items[0] = -6;
  v13->m_Items[1] = 26;
  v12->pm = v13;
  v10->center = v12;
  v16 = NewSpecific(sdfIVector2_t, 2u);
  v17 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v17);
  v17->pm = NewSpecific(s32, 2u);
  v16[4] = v17;
  v19 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v19);
  v21 = NewSpecific(s32, 2u);
  else
  {
    v24 = v21->max_length;
    if (!v24)
      goto LABEL_16;
  }
  v21->m_Items[0] = screen_wid;
  v21->m_Items[1] = screen_hei;
  v19->pm = v21;
  if (!hokan)
    ratio = 0.0;
  v16[5] = v19;
  v10->xy = v16;
  v28 = *d;
  if (key1)
    v29 = key1;
  else
    v29 = v10;
  abgr = v29->abgr;
  if (key2)
    v10 = key2;
  v31 = v10->abgr;
  if (hokan)
  {
    SDF_VU0__dds3ColorItoF(abgr);
    SDF_VU0__SCALEVECTOR(1.0 - ratio);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__dds3ColorItoF(v31);
    SDF_VU0__SCALEVECTOR(ratio);
    SDF_VU0__ADDVECTOR();
    abgr = SDF_VU0__dds3ColorFtoI(128.0);
  }
  v28->abgr = abgr;
  (*d)->blend = v29->blend;
  rotate = v29->rotate;
  v33 = *d;
  if (!hokan)
  {
    v33->rotate = rotate;
    (*d)->scale = v29->scale;
    pm = (*d)->center->pm;
    v43 = v29->center->pm;
    v45 = v43->m_Items[0];

    {
      if (!LODWORD(pm->max_length))
      {
LABEL_139:
      }
    }
    pm->m_Items[0] = v45;
    v51 = (*d)->center->pm;
    v120 = v29->center->pm;
    v58 = v120->m_Items[1];

    {
      v34 = 1.0 - ratio;
      if ((v51->max_length & 0xFFFFFFFE) == 0)
        goto LABEL_63;
    }
    goto LABEL_64;
  }
  v34 = 1.0 - ratio;
  v33->rotate = ((1.0 - ratio) * rotate) + (ratio * v10->rotate);
  (*d)->scale = ((1.0 - ratio) * v29->scale) + (ratio * v10->scale);
  v35 = (*d)->center->pm;
  v36 = v29->center->pm;
  v38 = v10->center->pm;
  v39 = v36->m_Items[0];
  v40 = v38->m_Items[0];
  v49 = ((v34 * v39) + (ratio * v40));
  v35->m_Items[0] = v49;
  v51 = (*d)->center->pm;
  v52 = v29->center->pm;
  v54 = v10->center->pm;
  v55 = v52->m_Items[1];
  v56 = v54->m_Items[1];
  v58 = ((v34 * v55) + (ratio * v56));
  if ((v51->max_length & 0xFFFFFFFE) == 0)
  {
LABEL_63:
  }
LABEL_64:
  v60 = 0;
  v51->m_Items[1] = v58;
  do
  {
    v61 = v60;
    xy = (*d)->xy;
    v63 = Allocate(sdfIVector2_t);
    sdfIVector2_t___ctor(v63);
    *&xy[2 * v61 + 8] = v63;
    v66 = (*d)->xy;
    max_length_low = LODWORD(v66->max_length);
    if (hokan)
    {
      v69 = v29->xy;
      v70 = v66->m_Items[v61]->pm;
      v72 = v69->m_Items[v61]->pm;
      v74 = v10->xy;
      v75 = v72->m_Items[0];
      v77 = v74->m_Items[v61]->pm;
      v78 = v77->m_Items[0];
      v90 = ((v34 * v75) + (ratio * v78));
      v70->m_Items[0] = v90;
      v92 = (*d)->xy;
      v94 = v29->xy;
      v95 = v92->m_Items[v61]->pm;
      v97 = v94->m_Items[v61]->pm;
      v99 = v10->xy;
      v100 = v97->m_Items[1];
      v102 = v99->m_Items[v61]->pm;
      v103 = v102->m_Items[1];
      v105 = ((v34 * v100) + (ratio * v103));
      if ((v95->max_length & 0xFFFFFFFE) == 0)
      {
LABEL_134:
      }
    }
    else
    {
      v80 = v29->xy;
      v81 = v66->m_Items[v61]->pm;
      v83 = v80->m_Items[v61]->pm;
      v85 = v10->xy;
      v86 = v83->m_Items[0];

      {
        if (!LODWORD(v81->max_length))
          goto LABEL_116;
      }
      v81->m_Items[0] = v86;
      v108 = (*d)->xy;
      v110 = v29->xy;
      v95 = v108->m_Items[v61]->pm;
      v112 = v110->m_Items[v61]->pm;
      v114 = v10->xy;
      v105 = v112->m_Items[1];

      {
        if ((v95->max_length & 0xFFFFFFFE) == 0)
          goto LABEL_134;
      }
    }
    v60 = 1;
    v95->m_Items[1] = v105;
  }
  while (!v61);
}

// 0x1103190
u32 evtHokanColor(s32 hokan, f32 ratio, u32 c1, u32 c2) {
  if (!hokan)
    return c1;
  SDF_VU0__dds3ColorItoF(c1);
  SDF_VU0__SCALEVECTOR(1.0 - ratio);
  SDF_VU0__COPYVECTOR_A_TO_B();
  SDF_VU0__dds3ColorItoF(c2);
  SDF_VU0__SCALEVECTOR(ratio);
  SDF_VU0__ADDVECTOR();
  return SDF_VU0__dds3ColorFtoI(128.0);
}

// 0x10fcf10
void evtHokanDistBlur(s32 hokan, f32 ratio, dds3Effect_DistortionBlurParam_t *key1, dds3Effect_DistortionBlurParam_t *key2, dds3Effect_DistortionBlurParam_t **d) {
  char *v11;
  sdfIVector2_t_o *v13;
  struct System_Int32_array *v14;
  u64 v16;
  u64 v17;
  dds3Effect_DistortionBlurParam_t_o *v18;
  u32 number;
  u32 v20;
  f32 v21;
  f64 v22;
  f64 v23;
  s32 v24;
  f32 v25;
  f32 v26;
  u32 v27;
  dds3Effect_DistortionBlurParam_t_o *v28;
  u32 v29;
  u32 abgr;
  dds3Effect_DistortionBlurParam_t_o *v31;
  f32 v32;
  f32 v33;
  f32 v34;
  s32 v35;
  struct System_Int32_array *v36;
  struct System_Int32_array *v37;
  s64 v39;
  s32 v40;
  s32 v41;
  struct System_Int32_array *pm;
  struct System_Int32_array *v43;
  s32 v45;
  s32 v47;
  struct System_Int32_array *v49;
  struct System_Int32_array *v50;
  s64 v52;
  s32 v53;
  s32 v54;
  s32 v56;
  dds3Effect_DistortionBlurParam_t_o *v58;
  u32 width;
  u32 v60;
  f32 v61;
  f32 v62;
  f32 v63;
  struct System_Int32_array *v66;

  v11 = Allocate(dds3Effect_DistortionBlurParam_t);
  dds3Effect_DistortionBlurParam_t___ctor(v11);
  *(v11 + 2) = 0xF0000003CLL;
  *(v11 + 3) = 0x8484843E6353F8LL;
  *(v11 + 8) = DDS3EFFECT_BLEND_SEMI();
  *(v11 + 36) = 0x3E051EB83BA3D70ALL;
  v13 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v13);
  v14 = NewSpecific(s32, 2u);
  if (!hokan)
    ratio = 0.0;
  v13->pm = v14;
  *(v11 + 6) = v13;
  *(v11 + 7) = 0x8800000100LL;
  if (!key1)
    key1 = v11;
  if (key2)
    v11 = key2;
  v18 = *d;
  number = key1->number;
  v20 = *(v11 + 4);
  if (!hokan)
    goto LABEL_21;
LABEL_15:
  v23 = number;
  *&v23 = number;
  v21 = 1.0 - ratio;
  v22 = v20;
  *&v22 = v20;
  *&v23 = ((1.0 - ratio) * *&v23) + (ratio * *&v22);
  v24 = *&v23;
  if (*&v23 >= 0.0)
    v24 = *&v23;
  v18->number = v24;
  LODWORD(v23) = key1->interval;
  LODWORD(v22) = *(v11 + 5);
  v25 = *&v23;
  v26 = *&v22;
  *&v23 = (v21 * v25) + (ratio * v26);
  v27 = *&v23;
  if (*&v23 >= 0.0)
    v27 = *&v23;
  (*d)->interval = v27;
  (*d)->speed = (v21 * key1->speed) + (ratio * *(v11 + 6));
  v28 = *d;
  v29 = *(v11 + 7);
  SDF_VU0__dds3ColorItoF(key1->abgr);
  SDF_VU0__SCALEVECTOR(v21);
  SDF_VU0__COPYVECTOR_A_TO_B();
  SDF_VU0__dds3ColorItoF(v29);
  SDF_VU0__SCALEVECTOR(ratio);
  SDF_VU0__ADDVECTOR();
  abgr = SDF_VU0__dds3ColorFtoI(128.0);
LABEL_22:
  v28->abgr = abgr;
  (*d)->blend = key1->blend;
  *&v16 = key1->rotate;
  v31 = *d;
  if (!hokan)
  {
    LODWORD(v31->rotate) = v16;
    (*d)->distortion = key1->distortion;
    (*d)->area = key1->area;
    pm = (*d)->center->pm;
    v43 = key1->center->pm;
    v45 = v43->m_Items[0];

    {
      if (!LODWORD(pm->max_length))
      {
LABEL_60:
      }
    }
    pm->m_Items[0] = v45;
    v49 = (*d)->center->pm;
    v66 = key1->center->pm;
    v56 = v66->m_Items[1];

    {
      v32 = 1.0 - ratio;
      if ((v49->max_length & 0xFFFFFFFE) == 0)
        goto LABEL_49;
    }
    goto LABEL_50;
  }
  v32 = 1.0 - ratio;
  v31->rotate = ((1.0 - ratio) * *&v16) + (ratio * *(v11 + 9));
  (*d)->distortion = ((1.0 - ratio) * key1->distortion) + (ratio * *(v11 + 10));
  LODWORD(v16) = key1->area;
  LODWORD(v17) = *(v11 + 14);
  v33 = v16;
  v34 = v17;
  *&v16 = ((1.0 - ratio) * v33) + (ratio * v34);
  v35 = *&v16;
  if (*&v16 >= 0.0)
    v35 = *&v16;
  (*d)->area = v35;
  v36 = (*d)->center->pm;
  v37 = key1->center->pm;
  v39 = *(*(v11 + 6) + 16LL);
  v40 = v37->m_Items[0];
  v41 = *(v39 + 32);
  v47 = ((v32 * v40) + (ratio * v41));
  v36->m_Items[0] = v47;
  v49 = (*d)->center->pm;
  v50 = key1->center->pm;
  v52 = *(*(v11 + 6) + 16LL);
  v53 = v50->m_Items[1];
  v54 = *(v52 + 36);
  v56 = ((v32 * v53) + (ratio * v54));
  if ((v49->max_length & 0xFFFFFFFE) == 0)
  {
LABEL_49:
  }
LABEL_50:
  v49->m_Items[1] = v56;
  v58 = *d;
  width = key1->width;
  v60 = *(v11 + 15);
  if (hokan)
  {
    v61 = width;
    v62 = v60;
    v63 = (v32 * v61) + (ratio * v62);
    if (v63 >= 0.0)
      width = v63;
    else
      width = v63;
  }
  v58->width = width;
}

// 0x10fe8e0
void evtHokanFilter(s32 hokan, f32 ratio, dds3Effect_Filter_t *key1, dds3Effect_Filter_t *key2, dds3Effect_Filter_t **d) {
  dds3Effect_Filter_t_o *v10;
  u64 *v12;
  sdfIVector2_t_o *v13;
  sdfIVector2_t_o *v15;
  struct System_Int32_array *v17;
  s32 screen_wid;
  u32 max_length;
  dds3Effect_Filter_t_o *v24;
  f32 v25;
  dds3Effect_Filter_t_o *v26;
  s64 v27;
  u32 *xy;
  u64 v29;
  u64 *v30;
  struct sdfIVector2_t_array *v33;
  u64 max_length_low;
  struct sdfIVector2_t_array *v36;
  struct System_Int32_array *pm;
  struct System_Int32_array *v39;
  struct sdfIVector2_t_array *v41;
  s32 v42;
  struct System_Int32_array *v44;
  s32 v45;
  struct sdfIVector2_t_array *v47;
  struct System_Int32_array *v48;
  struct System_Int32_array *v50;
  struct sdfIVector2_t_array *v52;
  s32 v53;
  s32 v57;
  struct sdfIVector2_t_array *v59;
  struct sdfIVector2_t_array *v61;
  struct System_Int32_array *v62;
  struct System_Int32_array *v64;
  struct sdfIVector2_t_array *v66;
  s32 v67;
  struct System_Int32_array *v69;
  s32 v70;
  s32 v72;
  struct sdfIVector2_t_array *v75;
  struct sdfIVector2_t_array *v77;
  struct System_Int32_array *v79;
  struct sdfIVector2_t_array *v81;
  u32 abgr;
  u32 v86;

  v10 = Allocate(dds3Effect_Filter_t);
  dds3Effect_Filter_t___ctor(v10);
  v10->abgr = 8421504;
  v10->blend = DDS3EFFECT_BLEND_ADD();
  v12 = NewSpecific(sdfIVector2_t, 2u);
  v13 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v13);
  v13->pm = NewSpecific(s32, 2u);
  v12[4] = v13;
  v15 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v15);
  v17 = NewSpecific(s32, 2u);
  else
  {
    max_length = v17->max_length;
    if (!max_length)
      goto LABEL_13;
  }
  v17->m_Items[0] = screen_wid;
  v17->m_Items[1] = screen_hei;
  v15->pm = v17;
  if (!hokan)
    ratio = 0.0;
  v12[5] = v15;
  v10->xy = v12;
  v24 = *d;
  v25 = 1.0 - ratio;
  if (key1)
    v26 = key1;
  else
    v26 = v10;
  v27 = 0;
  if (key2)
    v10 = key2;
  do
  {
    xy = v24->xy;
    v29 = v27;
    v30 = Allocate(sdfIVector2_t);
    sdfIVector2_t___ctor(v30);
    *&xy[2 * v29 + 8] = v30;
    v33 = (*d)->xy;
    max_length_low = LODWORD(v33->max_length);
    if (hokan)
    {
      v36 = v26->xy;
      pm = v33->m_Items[v29]->pm;
      v39 = v36->m_Items[v29]->pm;
      v41 = v10->xy;
      v42 = v39->m_Items[0];
      v44 = v41->m_Items[v29]->pm;
      v45 = v44->m_Items[0];
      v57 = ((v25 * v42) + (ratio * v45));
      pm->m_Items[0] = v57;
      v59 = (*d)->xy;
      v61 = v26->xy;
      v62 = v59->m_Items[v29]->pm;
      v64 = v61->m_Items[v29]->pm;
      v66 = v10->xy;
      v67 = v64->m_Items[1];
      v69 = v66->m_Items[v29]->pm;
      v70 = v69->m_Items[1];
      v72 = ((v25 * v67) + (ratio * v70));
      if ((v62->max_length & 0xFFFFFFFE) == 0)
      {
LABEL_96:
      }
    }
    else
    {
      v47 = v26->xy;
      v48 = v33->m_Items[v29]->pm;
      v50 = v47->m_Items[v29]->pm;
      v52 = v10->xy;
      v53 = v50->m_Items[0];

      {
        if (!LODWORD(v48->max_length))
          goto LABEL_78;
      }
      v48->m_Items[0] = v53;
      v75 = (*d)->xy;
      v77 = v26->xy;
      v62 = v75->m_Items[v29]->pm;
      v79 = v77->m_Items[v29]->pm;
      v81 = v10->xy;
      v72 = v79->m_Items[1];

      {
        if ((v62->max_length & 0xFFFFFFFE) == 0)
          goto LABEL_96;
      }
    }
    v62->m_Items[1] = v72;
    v24 = *d;
    v27 = 1;
  }
  while (!v29);
  abgr = v26->abgr;
  v86 = v10->abgr;
  if (hokan)
  {
LABEL_100:
    SDF_VU0__dds3ColorItoF(abgr);
    SDF_VU0__SCALEVECTOR(v25);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__dds3ColorItoF(v86);
    SDF_VU0__SCALEVECTOR(ratio);
    SDF_VU0__ADDVECTOR();
    abgr = SDF_VU0__dds3ColorFtoI(128.0);
  }
LABEL_101:
  v24->abgr = abgr;
  (*d)->blend = v26->blend;
}

// 0x10fab60
f32 evtHokanFloat(s32 hokan, f32 ratio, f32 f1, f32 f2) {
  if (hokan)
    return ((1.0 - ratio) * f1) + (ratio * f2);
  return f1;
}

// 0x1103120
s32 evtHokanInt(s32 hokan, f32 ratio, s32 i1, s32 i2) {
  if (hokan)
    return (((1.0 - ratio) * i1) + (i2 * ratio));
  return i1;
}

// 0x10fc190
void evtHokanMultBlur(s32 hokan, f32 ratio, dds3Effect_PartialMultiBlurParam_t *key1, dds3Effect_PartialMultiBlurParam_t *key2, dds3Effect_PartialMultiBlurParam_t **d) {
  dds3Effect_PartialMultiBlurParam_t_o *v11;
  u64 *v12;
  sdfIVector2_t_o *v14;
  struct System_Int32_array *v15;
  dds3Effect_PartialMultiBlurParam_t_o *v17;
  u32 area;
  u32 v19;
  f32 v20;
  f32 v21;
  f32 v22;
  struct dds3Effect_Blur_t_o *Blur;
  u32 abgr;
  u32 v25;
  f32 rotate;
  f32 scale;
  struct dds3Effect_Blur_t_o *v28;
  f32 v29;
  struct System_Int32_array *v30;
  struct System_Int32_array *v31;
  struct System_Int32_array *v33;
  s32 v34;
  s32 v35;
  struct System_Int32_array *pm;
  struct System_Int32_array *v37;
  s32 v39;
  s32 v41;
  struct System_Int32_array *v43;
  struct System_Int32_array *v44;
  struct System_Int32_array *v46;
  s32 v47;
  s32 v48;
  s32 v50;
  s64 v52;
  u64 v53;
  u32 *xy;
  u64 *v55;
  struct sdfIVector2_t_array *v58;
  u64 max_length_low;
  struct System_Int32_array *v61;
  struct sdfIVector2_t_array *v62;
  struct System_Int32_array *v64;
  struct sdfIVector2_t_array *v66;
  s32 v67;
  struct System_Int32_array *v69;
  s32 v70;
  struct System_Int32_array *v72;
  struct sdfIVector2_t_array *v73;
  struct System_Int32_array *v75;
  struct sdfIVector2_t_array *v77;
  s32 v78;
  s32 v82;
  struct sdfIVector2_t_array *v84;
  struct System_Int32_array *v86;
  struct sdfIVector2_t_array *v87;
  struct System_Int32_array *v89;
  struct sdfIVector2_t_array *v91;
  s32 v92;
  struct System_Int32_array *v94;
  s32 v95;
  s32 v97;
  struct sdfIVector2_t_array *v100;
  struct sdfIVector2_t_array *v102;
  struct System_Int32_array *v104;
  struct sdfIVector2_t_array *v106;
  struct System_Int32_array *v112;

  v11 = Allocate(dds3Effect_PartialMultiBlurParam_t);
  dds3Effect_PartialMultiBlurParam_t___ctor(v11);
  v11->area = 150;
  v12 = Allocate(dds3Effect_Blur_t);
  dds3Effect_Blur_t___ctor(v12);
  *(v12 + 4) = 8421504;
  *(v12 + 5) = DDS3EFFECT_BLEND_SEMI();
  v12[3] = 0x3F6D0E563D8F5C29LL;
  v14 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v14);
  v15 = NewSpecific(s32, 2u);
  if (!hokan)
    ratio = 0.0;
  v14->pm = v15;
  v12[4] = v14;
  v11->Blur = v12;
  if (!key1)
    key1 = v11;
  if (key2)
    v11 = key2;
  v17 = *d;
  area = key1->area;
  v19 = v11->area;
  if (hokan)
  {
    v20 = area;
    v21 = v19;
    v22 = ((1.0 - ratio) * v20) + (ratio * v21);
    if (v22 >= 0.0)
      area = v22;
    else
      area = v22;
  }
  v17->area = area;
  Blur = (*d)->Blur;
  abgr = key1->Blur->abgr;
  if (hokan)
  {
    v25 = v11->Blur->abgr;
    SDF_VU0__dds3ColorItoF(abgr);
    SDF_VU0__SCALEVECTOR(1.0 - ratio);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__dds3ColorItoF(v25);
    SDF_VU0__SCALEVECTOR(ratio);
    SDF_VU0__ADDVECTOR();
    abgr = SDF_VU0__dds3ColorFtoI(128.0);
  }
  Blur->abgr = abgr;
  (*d)->Blur->blend = key1->Blur->blend;
  rotate = key1->Blur->rotate;
  if (hokan)
    rotate = ((1.0 - ratio) * rotate) + (ratio * v11->Blur->rotate);
  (*d)->Blur->rotate = rotate;
  scale = key1->Blur->scale;
  v28 = (*d)->Blur;
  if (!hokan)
  {
    v28->scale = scale;
    pm = (*d)->Blur->center->pm;
    v37 = key1->Blur->center->pm;
    v39 = v37->m_Items[0];

    {
      if (!LODWORD(pm->max_length))
      {
LABEL_122:
      }
    }
    pm->m_Items[0] = v39;
    v43 = (*d)->Blur->center->pm;
    v112 = key1->Blur->center->pm;
    v50 = v112->m_Items[1];

    {
      v29 = 1.0 - ratio;
      if ((v43->max_length & 0xFFFFFFFE) == 0)
        goto LABEL_48;
    }
    goto LABEL_49;
  }
  v29 = 1.0 - ratio;
  v28->scale = ((1.0 - ratio) * scale) + (ratio * v11->Blur->scale);
  v30 = (*d)->Blur->center->pm;
  v31 = key1->Blur->center->pm;
  v33 = v11->Blur->center->pm;
  v34 = v31->m_Items[0];
  v35 = v33->m_Items[0];
  v41 = ((v29 * v34) + (ratio * v35));
  v30->m_Items[0] = v41;
  v43 = (*d)->Blur->center->pm;
  v44 = key1->Blur->center->pm;
  v46 = v11->Blur->center->pm;
  v47 = v44->m_Items[1];
  v48 = v46->m_Items[1];
  v50 = ((v29 * v47) + (ratio * v48));
  if ((v43->max_length & 0xFFFFFFFE) == 0)
  {
LABEL_48:
  }
LABEL_49:
  v52 = 0;
  v43->m_Items[1] = v50;
  do
  {
    v53 = v52;
    xy = (*d)->Blur->xy;
    v55 = Allocate(sdfIVector2_t);
    sdfIVector2_t___ctor(v55);
    *&xy[2 * v53 + 8] = v55;
    v58 = (*d)->Blur->xy;
    max_length_low = LODWORD(v58->max_length);
    if (hokan)
    {
      v61 = v58->m_Items[v53]->pm;
      v62 = key1->Blur->xy;
      v64 = v62->m_Items[v53]->pm;
      v66 = v11->Blur->xy;
      v67 = v64->m_Items[0];
      v69 = v66->m_Items[v53]->pm;
      v70 = v69->m_Items[0];
      v82 = ((v29 * v67) + (ratio * v70));
      v61->m_Items[0] = v82;
      v84 = (*d)->Blur->xy;
      v86 = v84->m_Items[v53]->pm;
      v87 = key1->Blur->xy;
      v89 = v87->m_Items[v53]->pm;
      v91 = v11->Blur->xy;
      v92 = v89->m_Items[1];
      v94 = v91->m_Items[v53]->pm;
      v95 = v94->m_Items[1];
      v97 = ((v29 * v92) + (ratio * v95));
      if ((v86->max_length & 0xFFFFFFFE) == 0)
      {
LABEL_119:
      }
    }
    else
    {
      v72 = v58->m_Items[v53]->pm;
      v73 = key1->Blur->xy;
      v75 = v73->m_Items[v53]->pm;
      v77 = v11->Blur->xy;
      v78 = v75->m_Items[0];

      {
        if (!LODWORD(v72->max_length))
          goto LABEL_101;
      }
      v72->m_Items[0] = v78;
      v100 = (*d)->Blur->xy;
      v86 = v100->m_Items[v53]->pm;
      v102 = key1->Blur->xy;
      v104 = v102->m_Items[v53]->pm;
      v106 = v11->Blur->xy;
      v97 = v104->m_Items[1];

      {
        if ((v86->max_length & 0xFFFFFFFE) == 0)
          goto LABEL_119;
      }
    }
    v52 = 1;
    v86->m_Items[1] = v97;
  }
  while (!v53);
}

// 0x10fe110
void evtHokanMultFilter(s32 hokan, f32 ratio, dds3Effect_PartialMultiFilterParam_t *key1, dds3Effect_PartialMultiFilterParam_t *key2, dds3Effect_PartialMultiFilterParam_t **d) {
  dds3Effect_PartialMultiFilterParam_t_o *v11;
  sdfIVector2_t_o *v12;
  dds3Effect_Filter_t_o *v13;
  s32 v15;
  dds3Effect_PartialMultiFilterParam_t_o *v17;
  dds3Effect_PartialMultiFilterParam_t_o *v18;
  u32 area;
  u32 v20;
  f32 v21;
  f32 v22;
  f32 v23;
  f32 v24;
  s32 v25;
  struct System_Int32_array *v26;
  struct System_Int32_array *v27;
  struct System_Int32_array *v29;
  s32 v30;
  s32 v31;
  s32 v33;
  struct System_Int32_array *v35;
  struct System_Int32_array *v36;
  struct System_Int32_array *v38;
  s32 v39;
  s32 v40;
  s32 v42;
  struct dds3Effect_Filter_t_o *Filter;
  u32 abgr;
  u32 v46;
  struct System_Int32_array *pm;

  v11 = Allocate(dds3Effect_PartialMultiFilterParam_t);
  dds3Effect_PartialMultiFilterParam_t___ctor(v11);
  v11->area = 150;
  v12 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v12);
  v12->pm = NewSpecific(s32, 2u);
  v11->center = v12;
  v13 = Allocate(dds3Effect_Filter_t);
  dds3Effect_Filter_t___ctor(v13);
  v13->abgr = 8421504;
  v15 = DDS3EFFECT_BLEND_ADD();
  if (!hokan)
    ratio = 0.0;
  v13->blend = v15;
  v11->Filter = v13;
  if (key1)
    v17 = key1;
  else
    v17 = v11;
  if (!key2)
    key2 = v11;
  v18 = *d;
  area = v17->area;
  v20 = key2->area;
  if (!hokan)
    goto LABEL_43;
LABEL_16:
  v21 = 1.0 - ratio;
  v22 = area;
  v23 = v20;
  v24 = ((1.0 - ratio) * v22) + (ratio * v23);
  v25 = v24;
  if (v24 >= 0.0)
    v25 = v24;
  v18->area = v25;
  v26 = (*d)->center->pm;
  v27 = v17->center->pm;
  v29 = key2->center->pm;
  v30 = v27->m_Items[0];
  v31 = v29->m_Items[0];
  v33 = ((v21 * v30) + (ratio * v31));
  v26->m_Items[0] = v33;
  v35 = (*d)->center->pm;
  v36 = v17->center->pm;
  v38 = key2->center->pm;
  v39 = v36->m_Items[1];
  v40 = v38->m_Items[1];
  v42 = ((v21 * v39) + (ratio * v40));
  if ((v35->max_length & 0xFFFFFFFE) == 0)
  {
LABEL_35:
  }
LABEL_36:
  v35->m_Items[1] = v42;
  Filter = (*d)->Filter;
  abgr = v17->Filter->abgr;
  v46 = key2->Filter->abgr;
  if (hokan)
  {
    SDF_VU0__dds3ColorItoF(abgr);
    SDF_VU0__SCALEVECTOR(v21);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__dds3ColorItoF(v46);
    SDF_VU0__SCALEVECTOR(ratio);
    SDF_VU0__ADDVECTOR();
    abgr = SDF_VU0__dds3ColorFtoI(128.0);
  }
  Filter->abgr = abgr;
  (*d)->Filter->blend = v17->Filter->blend;
}

// 0x10fd820
void evtHokanRipBlur(s32 hokan, f32 ratio, dds3Effect_RippleBlurParam_t *key1, dds3Effect_RippleBlurParam_t *key2, dds3Effect_RippleBlurParam_t **d) {
  char *v11;
  s32 v13;
  sdfIVector2_t_o *v14;
  struct System_Int32_array *v15;
  dds3Effect_RippleBlurParam_t_o *v17;
  u32 number;
  u32 v19;
  f32 v20;
  f32 v21;
  f32 v22;
  f32 v23;
  s32 v24;
  dds3Effect_RippleBlurParam_t_o *v25;
  u32 v26;
  u32 abgr;
  f32 rotate;
  dds3Effect_RippleBlurParam_t_o *v29;
  f32 v30;
  struct System_Int32_array *v31;
  struct System_Int32_array *v32;
  s64 v34;
  s32 v35;
  s32 v36;
  struct System_Int32_array *pm;
  struct System_Int32_array *v38;
  s32 v40;
  s32 v42;
  struct System_Int32_array *v44;
  struct System_Int32_array *v45;
  s64 v47;
  s32 v48;
  s32 v49;
  s32 v51;
  dds3Effect_RippleBlurParam_t_o *v53;
  u32 area;
  u32 v55;
  f32 v56;
  f32 v57;
  f32 v58;
  struct System_Int32_array *v61;

  v11 = Allocate(dds3Effect_RippleBlurParam_t);
  dds3Effect_RippleBlurParam_t___ctor(v11);
  *(v11 + 2) = 0x3D23D70A00000004LL;
  *(v11 + 3) = 0x8080803E4CCCCDLL;
  v13 = DDS3EFFECT_BLEND_SEMI();
  *(v11 + 36) = 0x3E0F5C293CCCCCCDLL;
  *(v11 + 8) = v13;
  *(v11 + 11) = 1045690319;
  v14 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v14);
  v15 = NewSpecific(s32, 2u);
  if (!hokan)
    ratio = 0.0;
  v14->pm = v15;
  *(v11 + 6) = v14;
  *(v11 + 14) = 256;
  if (!key1)
    key1 = v11;
  if (key2)
    v11 = key2;
  v17 = *d;
  number = key1->number;
  v19 = *(v11 + 4);
  if (!hokan)
    goto LABEL_19;
LABEL_15:
  v20 = number;
  v21 = 1.0 - ratio;
  v22 = v19;
  v23 = ((1.0 - ratio) * v20) + (ratio * v22);
  v24 = v23;
  if (v23 >= 0.0)
    v24 = v23;
  v17->number = v24;
  (*d)->speed = (v21 * key1->speed) + (ratio * *(v11 + 5));
  (*d)->interval = (v21 * key1->interval) + (ratio * *(v11 + 6));
  v25 = *d;
  v26 = *(v11 + 7);
  SDF_VU0__dds3ColorItoF(key1->abgr);
  SDF_VU0__SCALEVECTOR(v21);
  SDF_VU0__COPYVECTOR_A_TO_B();
  SDF_VU0__dds3ColorItoF(v26);
  SDF_VU0__SCALEVECTOR(ratio);
  SDF_VU0__ADDVECTOR();
  abgr = SDF_VU0__dds3ColorFtoI(128.0);
LABEL_20:
  v25->abgr = abgr;
  (*d)->blend = key1->blend;
  rotate = key1->rotate;
  v29 = *d;
  if (!hokan)
  {
    v29->rotate = rotate;
    (*d)->power = key1->power;
    (*d)->frequency = key1->frequency;
    pm = (*d)->center->pm;
    v38 = key1->center->pm;
    v40 = v38->m_Items[0];

    {
      if (!LODWORD(pm->max_length))
      {
LABEL_56:
      }
    }
    pm->m_Items[0] = v40;
    v44 = (*d)->center->pm;
    v61 = key1->center->pm;
    v51 = v61->m_Items[1];

    {
      v30 = 1.0 - ratio;
      if ((v44->max_length & 0xFFFFFFFE) == 0)
        goto LABEL_45;
    }
    goto LABEL_46;
  }
  v30 = 1.0 - ratio;
  v29->rotate = ((1.0 - ratio) * rotate) + (ratio * *(v11 + 9));
  (*d)->power = ((1.0 - ratio) * key1->power) + (ratio * *(v11 + 10));
  (*d)->frequency = ((1.0 - ratio) * key1->frequency) + (ratio * *(v11 + 11));
  v31 = (*d)->center->pm;
  v32 = key1->center->pm;
  v34 = *(*(v11 + 6) + 16LL);
  v35 = v32->m_Items[0];
  v36 = *(v34 + 32);
  v42 = ((v30 * v35) + (ratio * v36));
  v31->m_Items[0] = v42;
  v44 = (*d)->center->pm;
  v45 = key1->center->pm;
  v47 = *(*(v11 + 6) + 16LL);
  v48 = v45->m_Items[1];
  v49 = *(v47 + 36);
  v51 = ((v30 * v48) + (ratio * v49));
  if ((v44->max_length & 0xFFFFFFFE) == 0)
  {
LABEL_45:
  }
LABEL_46:
  v44->m_Items[1] = v51;
  v53 = *d;
  area = key1->area;
  v55 = *(v11 + 14);
  if (hokan)
  {
    v56 = area;
    v57 = v55;
    v58 = (v30 * v56) + (ratio * v57);
    if (v58 >= 0.0)
      area = v58;
    else
      area = v58;
  }
  v53->area = area;
}

// 0x10fadd0
void evtHokanSceneFog(s32 hokan, f32 ratio, pmdSceneFogTable_t *key1, pmdSceneFogTable_t *key2, pmdSceneFogTable_t **d) {
  u64 *v11;
  f32 Far;
  f32 v13;
  pmdSceneFogTable_t_o *v14;
  pmdSceneFogTable_t_o *v15;
  pmdSceneFogTable_t_o *v16;
  pmdSceneFogTable_t_o *v17;
  u32 Color;
  u32 v19;
  pmdSceneFogTable_t_o *v20;

  v11 = Allocate(sdf3DFogParam_t);
  sdf3DFogParam_t___ctor(v11);
  if (!hokan)
    ratio = 0.0;
  v11[2] = 1132396544;
  v11[3] = 0x469C4000453B8000LL;
  *(v11 + 8) = 6312000;
  if (key1)
  {
    SDF_VU0__SETVECTOR_X(key1->Min);
    SDF_VU0__SETVECTOR_Y(key1->Max);
    SDF_VU0__SETVECTOR_Z(key1->Near);
    Far = key1->Far;
  }
  else
  {
    SDF_VU0__SETVECTOR_X(0.0);
    SDF_VU0__SETVECTOR_Y(*(v11 + 4), 0);
    SDF_VU0__SETVECTOR_Z(*(v11 + 6), 0);
    Far = *(v11 + 7);
  }
  SDF_VU0__SETVECTOR_W(Far);
  SDF_VU0__SCALEVECTOR(1.0 - ratio);
  SDF_VU0__COPYVECTOR_A_TO_B();
  if (key2)
  {
    SDF_VU0__SETVECTOR_X(key2->Min);
    SDF_VU0__SETVECTOR_Y(key2->Max);
    SDF_VU0__SETVECTOR_Z(key2->Near);
    v13 = key2->Far;
  }
  else
  {
    SDF_VU0__SETVECTOR_X(*(v11 + 5), 0);
    SDF_VU0__SETVECTOR_Y(*(v11 + 4), 0);
    SDF_VU0__SETVECTOR_Z(*(v11 + 6), 0);
    v13 = *(v11 + 7);
  }
  SDF_VU0__SETVECTOR_W(v13);
  SDF_VU0__SCALEVECTOR(ratio);
  SDF_VU0__ADDVECTOR();
  v14 = *d;
  v14->Min = SDF_VU0__GETVECTOR_X();
  v15 = *d;
  v15->Max = SDF_VU0__GETVECTOR_Y();
  v16 = *d;
  v16->Near = SDF_VU0__GETVECTOR_Z();
  v17 = *d;
  v17->Far = SDF_VU0__GETVECTOR_W();
  if (key1)
    Color = key1->Color;
  else
    Color = *(v11 + 8);
  SDF_VU0__dds3ColorItoF(Color);
  SDF_VU0__SCALEVECTOR(1.0 - ratio);
  SDF_VU0__COPYVECTOR_A_TO_B();
  if (key2)
    v19 = key2->Color;
  else
    v19 = *(v11 + 8);
  SDF_VU0__dds3ColorItoF(v19);
  SDF_VU0__SCALEVECTOR(ratio);
  SDF_VU0__ADDVECTOR();
  v20 = *d;
  v20->Color = SDF_VU0__dds3ColorFtoI(128.0);
}

// 0x10fa940
void evtHokanSceneLight(s32 hokan, f32 ratio, pmdSceneLightTable_t *key1, pmdSceneLightTable_t *key2, pmdSceneLightTable_t **d) {
  f32 v11;
  UnityEngine_Vector4_o v12;
  UnityEngine_Vector4_o v13;
  UnityEngine_Vector4_o v14;
  UnityEngine_Vector4_o Color;
  UnityEngine_Vector4_o v16;
  UnityEngine_Vector4_o Dir;
  UnityEngine_Vector4_o v18;
  UnityEngine_Vector4_o Ambient;
  UnityEngine_Vector4_o v20;

  *&v14.x = 0;
  *&v14.z = 0;
  *&v13.x = 0;
  *&v13.z = 0;
  *&v12.x = 0;
  *&v12.z = 0;
  sub_854690(&v14.x, 0.8, 0.8, 0.8, 0.0);
  sub_854690(&v13.x, 0.0, 1.0, 0.5, 0.0);
  sub_854690(&v12.x, 0.2, 0.2, 0.2, 1.0);
  if (!hokan)
    ratio = 0.0;
  if (key1)
    Color = key1->Color;
  else
    Color = v14;
  SDF_VU0__LOADVECTOR(Color);
  v11 = 1.0 - ratio;
  SDF_VU0__SCALEVECTOR(1.0 - ratio);
  if (key2)
    v16 = key2->Color;
  else
    v16 = v14;
  SDF_VU0__LOADVECTOR_B(v16);
  SDF_VU0__SCALEVECTOR_B(ratio);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&(*d)->Color, 0);
  if (key1)
    Dir = key1->Dir;
  else
    Dir = v13;
  SDF_VU0__LOADVECTOR(Dir);
  SDF_VU0__SCALEVECTOR(v11);
  if (key2)
    v18 = key2->Dir;
  else
    v18 = v13;
  SDF_VU0__LOADVECTOR_B(v18);
  SDF_VU0__SCALEVECTOR_B(ratio);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&(*d)->Dir, 0);
  if (key1)
    Ambient = key1->Ambient;
  else
    Ambient = v12;
  SDF_VU0__LOADVECTOR(Ambient);
  SDF_VU0__SCALEVECTOR(v11);
  if (key2)
    v20 = key2->Ambient;
  else
    v20 = v12;
  SDF_VU0__LOADVECTOR_B(v20);
  SDF_VU0__SCALEVECTOR_B(ratio);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__VECTOR_W_SET_ONE();
  SDF_VU0__STOREVECTOR(&(*d)->Ambient, 0);
}

// 0x1103150
u32 evtHokanUInt(s32 hokan, f32 ratio, u32 i1, u32 i2) {
  f32 v5;
  f32 v6;
  f32 v7;

  if (hokan)
  {
    v5 = i1;
    v6 = i2;
    v7 = ((1.0 - ratio) * v5) + (v6 * ratio);
    if (v7 >= 0.0)
      return v7;
    else
      return v7;
  }
  return i1;
}

// 0x1101610
void *evtPolygonMovieProcess1(dds3ProcessID_t *id) {
  Il2CppObject *ProcessData;
  pmdProcessWork_t_c *v3;
  pmdProcessWork_t_o *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  System_Object_array *v9;
  System_Object_array *v10;
  s64 *v11;
  s64 *v12;
  s64 *v15;
  s64 *v17;
  u64 *v20;
  System_String_o *v22;
  s32 v23;
  System_String_o *DLCTag;
  UnityEngine_GameObject_o *v31;
  UnityEngine_Transform_o *transform;
  s32 v34;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Object_o *FildMapObj;
  UnityEngine_GameObject_o *v41;
  Il2CppClass *v42;
  struct pmdStageTable_t_o *StageTable;
  s32 MajorNum;
  s32 MinorNum;
  u64 *v47;
  u64 *v49;
  System_Byte_array *StageF1;
  System_Byte_array *StageF2;
  System_Byte_array *StageTB;
  bool v55;
  Il2CppObject *workdata;
  Il2CppClass *v58;
  s64 v59;
  char *v60;
  s64 *v61;
  UnityEngine_GameObject_o *v62;
  UnityEngine_GameObject_o *monitor;
  u64 *v64;
  System_String_o *v65;
  System_String_o *v67;
  u64 i;
  struct pmdUnitTable_t_array *UnitTable;
  s32 v71;
  s32 v72;
  s32 v74;
  dds3Basic_t_o *j;
  Il2CppObject *v78;
  Il2CppClass *v79;
  s64 v80;
  struct pmdUnitTable_t_array *v81;
  struct pmdNameTable_t_array *NameTable1;
  s64 NameIndex;
  dds3Basic_t_o *v86;
  s64 v87;
  System_String_o *name;
  System_String_o *v90;
  System_String_o *v91;
  System_Object_array *v93;
  dds3SceneBasic_t_c *v96;
  Il2CppObject *v98;
  Il2CppClass *v99;
  s64 v100;
  char *v101;
  s64 *v102;
  s64 v103;
  struct pmdCameraTable_t_array *CameraTable;
  struct pmdCameraTable_t_array *v106;
  struct pmdNameTable_t_array *NameTable2;
  s64 v109;
  System_String_o *v111;
  System_String_o *v113;
  struct dds3Basic_t_array *v116;
  s64 v118;
  Il2CppClass *v119;
  struct dds3Basic_t_o *next;
  Il2CppClass *v122;
  struct dds3Basic_t_o *v124;
  System_String_o *v126;
  System_String_o *v127;
  dds3Basic_t_o *v128;
  dds3Basic_t_o *v129;
  Il2CppClass *v130;
  struct dds3Basic_t_o *v132;
  Il2CppClass *v133;
  struct dds3Basic_t_o *namespaze;
  System_String_o *v137;
  System_String_o *v138;
  dds3Basic_t_o *v139;
  dds3Basic_t_o *v140;
  evtTexManager_o *currTexMngr;
  u64 *v144;
  evtTexManager_o *v147;
  u64 *v148;
  u64 *v149;
  System_String_o *v150;
  u64 *v151;
  u64 *v152;
  System_String_o *v155;
  dds3KernelDraw_c *v157;
  u64 *v159;
  char *v162;
  s64 *v163;
  System_String_o *key;
  s32 v165;
  s32 EventNo;
  s32 CutNo;
  dds3ModelHandle_t_o *aHandle;
  dds3Basic_t_o *scene;
  dds3Basic_t_o *pMoverBasic;
  dds3Basic_t_o *pPathBasic;
  dds3Basic_t_o *pBasic;
  char v173[16];
  char *v174;
  dds3ProcessID_t_o *ida;

  ida = id;
  pPathBasic = 0;
  pBasic = 0;
  scene = 0;
  pMoverBasic = 0;
  aHandle = 0;
  ProcessData = dds3GetProcessData(&ida);
  v4 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pmdProcessWork_t)
    {
      sub_8FC2C0(klass->_1.element_class, pmdProcessWork_t, v173);
      if ((v173[0] & 1) != 0)
        v7 = v174;
      else
        v7 = &v173[1];
      v8 = sub_8C4940(v7);
    }
  }
  else if (!CheckLoad(ProcessData, v3))
  {
    return 0;
  }
  if ((v4->flag & 9) != 8)
    return 0;
  v9 = NewSpecific(object, 2u);
  *v173 = v4->EventNo;
  v10 = v9;
  v11 = sub_8D3950(s32, v173);
  v12 = v11;
  v10->m_Items[0] = v12;
  CutNo = v4->CutNo;
  v15 = sub_8D3950(s32, &CutNo);
  v17 = v15;
  v10->m_Items[1] = v17;
  Log("ポリゴンムービースタート ({0:D},{1:D})\n", v10, 0);
  EventNo = v4->EventNo;
  v20 = sub_8D3950(s32, &EventNo);
  v22 = Format("e{0:D3}", v20, 0);
  v23 = v4->EventNo;
  DLCTag = GetDLCTag(v23);
  key = Concat_5224608(v22, DLCTag);
  SetShadowMode(kernelObject, 3);
  dds3Effect_PartialMultiBlurParam_t__Clear(MBlurFrameFunc_mbl);
  dds3Effect_DistortionBlurParam_t__Clear(DBlurFrameFunc_dbl);
  dds3Effect_RippleBlurParam_t__Clear(RBlurFrameFunc_rbl);
  dds3Effect_PartialMultiFilterParam_t__Clear(MFilterFrameFunc_mfl);
  dds3Effect_Filter_t__Clear(FilterFrameFunc_fl);
  InitializeReplaceList(v4->EventNo);
  v31 = Find("Character", 0);
  if (op_Inequality(v31, 0, 0))
  {
    SetActive(v31, 1, 0);
    if (v4->EventNo != 800)
    {
      transform = get_transform(v31, 0);
      if (get_childCount(transform) >= 1)
      {
        v34 = 0;
        do
        {
          Child = GetChild(transform, v34);
          gameObject = get_gameObject(Child);
          SetActive(gameObject, 0, 0);
          ++v34;
        }
        while (v34 < get_childCount(transform));
      }
    }
  }
  if (op_Inequality(FildMapObj, 0, 0))
  {
    SetActive(FildMapObj, 1, 0);
  }
  fldSetCharClr();
  v41 = Find("kernel", 0);
  v42 = GetComponent_object_(v41)[14].klass;
  if (!get_activeSelf(v42))
    SetActive(v42, 1, 0);
  StageTable = v4->StageTable;
  if (StageTable)
  {
    MajorNum = StageTable->MajorNum;
    MinorNum = StageTable->MinorNum;
    *v173 = MajorNum;
    v47 = sub_8D3950(s32, v173);
    CutNo = MinorNum;
    v49 = sub_8D3950(s32, &CutNo);
    Write_2930752("まっぷ ({0:D}_{1:D})\n", v47, v49, 0);
    scene = dds3GetControlScene();
    if (dds3GetMapNo(&scene) != MinorNum + (MajorNum << 16))
    {
      StageF1 = v4->StageF1;
      StageF2 = v4->StageF2;
      StageTB = v4->StageTB;
      evtLoadArea_FromMemory(MajorNum, MinorNum, StageF1, StageF2, StageTB, 0);
      v55 = evtBitCheck(3716);
      if (MinorNum == 90 && MajorNum == 800 && v55)
      {
        gSkipSeZiko = 4;
      }
    }
  }
  workdata = dds3GetActiveScene()->workdata;
  if (workdata)
  {
    v58 = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < v59
      || v58->_2.typeHierarchy[v59 - 1] != dds3SceneBasic_t)
    {
      sub_8FC2C0(v58->_1.element_class, dds3SceneBasic_t, v173);
      if ((v173[0] & 1) != 0)
        v60 = v174;
      else
        v60 = &v173[1];
      v61 = sub_8C4940(v60);
    }
  }
  v62 = Find("kernel", 0);
  monitor = GetComponent_object_(v62)[15].monitor;
  if (!get_activeSelf(monitor))
    SetActive(monitor, 1, 0);
  *v173 = v4->EventNo;
  v64 = sub_8D3950(s32, v173);
  v65 = Format("EVENT/E{0:D3}/", v64, 0);
  if (v4->UnitCount >= 1)
  {
    v67 = v65;
    for (i = 0; i < v4->UnitCount; ++i)
    {
      UnitTable = v4->UnitTable;
      v71 = UnitTable->m_Items[i]->MajorNum;
      v72 = v4->UnitTable->m_Items[i]->MinorNum;
      v74 = evtSetRegistUnit(v71, v72);
      else if (workdata)
      {
        goto LABEL_106;
      }
      j = 0;
LABEL_114:
      pBasic = j;
      v78 = j->workdata;
      v79 = v78->klass;
      if (v78->klass->_2.typeHierarchyDepth < v80
        || v79->_2.typeHierarchy[v80 - 1] != dds3UnitObjectBasicWorkData_t)
      {
        sub_8FC2C0(v79->_1.element_class, dds3UnitObjectBasicWorkData_t, v173);
        if ((v173[0] & 1) != 0)
          v162 = v174;
        else
          v162 = &v173[1];
        v163 = sub_8C4940(v162);
      }
      aHandle = v78[2].klass->_1.interfaceOffsets;
      v81 = v4->UnitTable;
      NameTable1 = v4->NameTable1;
      NameIndex = v81->m_Items[i]->NameIndex;
      j->name = NameTable1->m_Items[NameIndex]->Name;
      Clear(PMchkname, 0);
      Append_5380272(PMchkname, v67);
      Append_5380272(PMchkname, pBasic->name);
      v86 = pBasic;
      v87 = (PMchkname->klass->vtable._3_ToString.methodPtr)(
              PMchkname,
              PMchkname->klass->vtable._3_ToString.method);
      name = pBasic->name;
      v90 = v87;
      AttachModel_26586560(v86, key, v90, name);
      v91 = Concat_5224608("ModelPackDecode : ", v67);
      v93 = Empty_string_();
      Log(v91, v93, 0);
      mdlSmoothSingleMotion(&aHandle, 0, 0, 0.0, 0.0);
      LoadEventModel();
    }
  }
  v98 = dds3GetControlScene()->workdata;
  if (v98)
  {
    v99 = v98->klass;
    if (v98->klass->_2.typeHierarchyDepth < v100
      || v99->_2.typeHierarchy[v100 - 1] != dds3SceneBasic_t)
    {
      sub_8FC2C0(v99->_1.element_class, dds3SceneBasic_t, v173);
      if ((v173[0] & 1) != 0)
        v101 = v174;
      else
        v101 = &v173[1];
      v102 = sub_8C4940(v101);
    }
  }
  if (v4->CameraCount >= 1)
  {
    v103 = 4;
    do
    {
      CameraTable = v4->CameraTable;
      if ((*(*(&CameraTable->obj.klass + v103) + 16LL) & 0x80000000) == 0)
      {
        v106 = v4->CameraTable;
        NameTable2 = v4->NameTable2;
        v109 = *(*(&v106->obj.klass + v103) + 16LL);
        v111 = NameTable2->m_Items[v109]->Name;
        pBasic = dds3SceneBasicSearchNameAndType_(v98, 4u, v111);
        if (pBasic)
        {
          Clear(PMchkname, 0);
          Append_5380272(PMchkname, pBasic->name);
          Append_5380272(PMchkname, "_MOTION");
          v113 = (PMchkname->klass->vtable._3_ToString.methodPtr)(
                   PMchkname,
                   PMchkname->klass->vtable._3_ToString.method);
          pPathBasic = dds3SceneBasicSearchNameAndType_(v98, 0x10u, v113);
          if (pPathBasic)
          {
            v116 = dds3CameraObjectBasicGetControlWorkData(&pBasic)->pBasic;
            pMoverBasic = v116->m_Items[1];
            dds3MoverBasicSetPath(&pMoverBasic, &pPathBasic);
            dds3MoverBasicMakePath(&pMoverBasic);
          }
        }
      }
      v118 = v103 - 3;
      ++v103;
    }
    while (v118 < v4->CameraCount);
  }
  v119 = workdata[2].klass;
  next = *(v119->_1.nestedTypes + 3);
  for (pBasic = next; next; pBasic = next)
  {
    while (1)
    {
      if (!IsNullOrEmpty(next->name))
      {
        v122 = workdata[2].klass;
        v124 = *(v122->_1.typeDefinition + 3);
        pPathBasic = v124;
        if (v124)
          break;
      }
LABEL_180:
      next = pBasic->next;
      pBasic = next;
      if (!next)
        goto LABEL_186;
    }
    while (1)
    {
      if (!IsNullOrEmpty(v124->name))
      {
        Clear(PMchkname, 0);
        Append_5380272(PMchkname, pPathBasic->name);
        Append_5380272(PMchkname, "_MOTION");
        v126 = pBasic->name;
        v127 = (PMchkname->klass->vtable._3_ToString.methodPtr)(
                 PMchkname,
                 PMchkname->klass->vtable._3_ToString.method);
        if (op_Equality(v126, v127, 0))
          break;
      }
      v124 = pPathBasic->next;
      pPathBasic = v124;
      if (!v124)
        goto LABEL_180;
    }
    v129 = pPathBasic;
    v128 = pBasic;
    evtPathLinkAndMake(v128, v129);
    next = pBasic->next;
  }
LABEL_186:
  v130 = workdata[2].klass;
  v132 = *(v130->_1.nestedTypes + 3);
  for (pBasic = v132; v132; pBasic = v132)
  {
    while (1)
    {
      if (!IsNullOrEmpty(v132->name))
      {
        v133 = workdata[2].klass;
        namespaze = v133->_1.parent->_1.namespaze;
        pPathBasic = namespaze;
        if (namespaze)
          break;
      }
LABEL_199:
      v132 = pBasic->next;
      pBasic = v132;
      if (!v132)
        goto LABEL_205;
    }
    while (1)
    {
      if (!IsNullOrEmpty(namespaze->name))
      {
        Clear(PMchkname, 0);
        Append_5380272(PMchkname, pPathBasic->name);
        Append_5380272(PMchkname, "_MOTION");
        v137 = pBasic->name;
        v138 = (PMchkname->klass->vtable._3_ToString.methodPtr)(
                 PMchkname,
                 PMchkname->klass->vtable._3_ToString.method);
        if (op_Equality(v137, v138, 0))
          break;
      }
      namespaze = pPathBasic->next;
      pPathBasic = namespaze;
      if (!namespaze)
        goto LABEL_199;
    }
    v140 = pPathBasic;
    v139 = pBasic;
    evtPathLinkAndMake(v139, v140);
    v132 = pBasic->next;
  }
LABEL_205:
  FrameTableOverWrite(v4, v96);
  v4->NowFrame = v4->CutInfo->FirstFrame;
  if (currTexMngr)
  {
    Destroy(currTexMngr, 1, 0);
  }
  v144 = Allocate(evtTexManager);
  _ctor(v144, 0);
  currTexMngr = v144;
  v147 = currTexMngr;
  *v173 = v4->EventNo;
  v148 = sub_8D3950(s32, v173);
  CutNo = v4->CutNo;
  v149 = sub_8D3950(s32, &CutNo);
  v150 = Format_5268592("E{0:D3}_{1:D3}_TEX", v148, v149);
  Initialize(v147, key, v150, 0);
  EventNo = v4->EventNo;
  v151 = sub_8D3950(s32, &EventNo);
  v165 = v4->CutNo;
  v152 = sub_8D3950(s32, &v165);
  v155 = Format_5268592("E{0:D3}_{1:D3}_PB", v151, v152);
  Initialize(key, v155);
  BillSetTexture(currTexMngr);
  if (v4->EventNo != 800)
  {
    SetDrawFlag(0x2000000u, 1u);
    switch (v4->EventNo)
    {
      case 0x27C:
      case 0x295:
      case 0x29F:
      case 0x2A1:
      case 0x2A8:
      case 0x2AE:
      case 0x2B5:
        goto LABEL_227;
      case 0x2BB:
        if (v4->CutNo != 5)
          goto LABEL_228;
        Postblur_AccumTex_NowMode = 1;
        if ((v157->_2.bitflags2 & 2) == 0)
          goto LABEL_231;
        goto LABEL_229;
      case 0x2D3:
        if (!evtBitCheck(3712))
          break;
LABEL_227:
LABEL_228:
        if ((v157->_2.bitflags2 & 2) != 0)
        {
LABEL_229:
        }
LABEL_231:
        ClrDrawFlag(0x2000000u);
        break;
      default:
        break;
    }
  }
  FrameRun(v4);
  ++v4->NowFrame;
  StartAnimation(v4);
  Last_wdata_NowFrame = v4->NowFrame;
  v159 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v159,
    0,
    Method_evtPolygonMovie_evtPolygonMovieProcess3__);
  return v159;
}

// 0x11070b0
void *evtPolygonMovieProcess1e(dds3ProcessID_t *id) {
  u64 *v2;
  Il2CppObject *ProcessData;
  pmdProcessWork_t_c *v5;
  pmdProcessWork_t_o *v6;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  u64 *v15;
  dds3ProcessID_t_o *v18;
  u64 v19[3];

  v18 = id;
  v2 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v2);
  ProcessData = dds3GetProcessData(&v18);
  v6 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pmdProcessWork_t)
    {
      sub_8FC2C0(klass->_1.element_class, pmdProcessWork_t, v19);
      if ((v19[0] & 1) != 0)
        v9 = v19[2];
      else
        v9 = v19 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  if ((ProcessData[1].klass & 1) == 0)
  {
    read_module_17851248(v6, v5);
    SwitchAnimation(v6, 1);
    dds3Effect_PartialMultiBlurParam_t__Clear(MBlurFrameFunc_mbl);
    dds3Effect_DistortionBlurParam_t__Clear(DBlurFrameFunc_dbl);
    dds3Effect_RippleBlurParam_t__Clear(RBlurFrameFunc_rbl);
    dds3Effect_PartialMultiFilterParam_t__Clear(MFilterFrameFunc_mfl);
    dds3Effect_Filter_t__Clear(FilterFrameFunc_fl);
    BillSetTexture(v6->TexMngr);
    if (v6->EventNo == 723 && evtBitCheck(3712))
    {
      ClrDrawFlag(0x2000000u);
        goto LABEL_30;
    }
    else
    {
      SetDrawFlag(0x2000000u, 1u);
        goto LABEL_30;
    }
LABEL_30:
    FrameRun(v6);
    ++v6->NowFrame;
    StartAnimation(v6);
    Last_wdata_NowFrame = v6->NowFrame;
    v15 = Allocate(System_Func_dds3ProcessID_t__object_);
    object____ctor(
      v15,
      0,
      Method_evtPolygonMovie_evtPolygonMovieProcess3__);
    return v15;
  }
  return 0;
}

// 0x10ff740
dds3ProcessFunc_t *evtPolygonMovieProcess2(dds3ProcessID_t *id) {
  Il2CppObject *ProcessData;
  pmdProcessWork_t_c *v3;
  pmdProcessWork_t_o *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  s32 v9;
  u64 *v12;
  dds3ProcessID_t_o *v14;
  u64 v15[3];

  v14 = id;
  ProcessData = dds3GetProcessData(&v14);
  v4 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pmdProcessWork_t)
    {
      sub_8FC2C0(klass->_1.element_class, pmdProcessWork_t, v15);
      if ((v15[0] & 1) != 0)
        v7 = v15[2];
      else
        v7 = v15 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  FrameRun(v4, v3);
  v9 = v4->NowFrame + 1;
  v4->NowFrame = v9;
  Last_wdata_NowFrame = v9;
  DispAnimation(v4);
  if (v4->NowFrame >= v4->CutInfo->LastFrame)
  {
    LODWORD(v15[0]) = v4->NowFrame;
    v12 = sub_8D3950(s32, v15);
    Write_2930400("end polygon movie! frame:{0:D}\n", v12);
    v14->func_ans = -1;
  }
  return 0;
}

// 0x10ff920
void *evtPolygonMovieProcess3(dds3ProcessID_t *id) {
  u64 *v3;
  Il2CppObject *ProcessData;
  pmdProcessWork_t_c *v5;
  pmdProcessWork_t_o *v6;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  s32 v11;
  dds3ProcessID_t_o *v14;
  u64 v15[3];

  v14 = id;
  else
  {
    v3 = 0;
    if (!IsStartModelLoaded())
      return v3;
  }
  ProcessData = dds3GetProcessData(&v14);
  v6 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pmdProcessWork_t)
    {
      sub_8FC2C0(klass->_1.element_class, pmdProcessWork_t, v15);
      if ((v15[0] & 1) != 0)
        v9 = v15[2];
      else
        v9 = v15 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  FrameRun(v6, v5);
  v11 = v6->NowFrame + 1;
  v6->NowFrame = v11;
  Last_wdata_NowFrame = v11;
  DispAnimation(v6);
  v3 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v3,
    0,
    Method_evtPolygonMovie_evtPolygonMovieProcess2__);
  return v3;
}

// 0x1102b00
void *evtPolygonMovieShutdown(dds3ProcessID_t *id) {
  Il2CppObject *ProcessData;
  pmdProcessWork_t_c *v3;
  pmdProcessWork_t_o *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  evtTexManager_o *currTexMngr;
  u64 *v12;
  u64 *v15;
  System_String_o *v17;
  s32 EventNo;
  System_String_o *DLCTag;
  System_String_o *v20;
  struct pmdStageTable_t_o *StageTable;
  System_String_o *v23;
  evtTexManager_o *v25;
  u64 *v26;
  System_String_o *v27;
  u64 *v28;
  System_String_o *v31;
  evtTexManager_o *v34;
  s32 v39;
  dds3ProcessID_t_o *v40[3];
  dds3ProcessID_t_o *ida;

  ida = id;
  ProcessData = dds3GetProcessData(&ida);
  v4 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pmdProcessWork_t)
    {
      sub_8FC2C0(klass->_1.element_class, pmdProcessWork_t, v40);
      if ((v40[0] & 1) != 0)
        v7 = v40[2];
      else
        v7 = v40 + 1;
      v8 = sub_8C4940(v7);
    }
  }
LABEL_17:
  DeletePB(1, v3);
  if (currTexMngr)
  {
    Destroy(currTexMngr, 1, 0);
  }
  v12 = Allocate(evtTexManager);
  _ctor(v12, 0);
  currTexMngr = v12;
  LODWORD(v40[0]) = v4->EventNo;
  v15 = sub_8D3950(s32, v40);
  v17 = Format("e{0:D3}", v15, 0);
  EventNo = v4->EventNo;
  DLCTag = GetDLCTag(EventNo);
  v20 = Concat_5224608(v17, DLCTag);
  StageTable = v4->StageTable;
  v23 = v20;
  if (StageTable->MajorNum == 676 && StageTable->MinorNum == 30 || (v4->EventNo - 804) <= 2)
  {
    RemoveKeys(3, v23);
    RemoveKeys(1, v23);
  }
  v25 = currTexMngr;
  LODWORD(v40[0]) = v4->EventNo;
  v26 = sub_8D3950(s32, v40);
  v27 = Format("E{0:D3}_BE_TEX", v26, 0);
  Initialize(v25, v23, v27, 0);
  v39 = v4->EventNo;
  v28 = sub_8D3950(s32, &v39);
  v31 = Format("E{0:D3}_BE_PB", v28, 0);
  Initialize(v23, v31);
  if ((v4->EventNo - 601) <= 0x12A)
  {
    v34 = currTexMngr;
    if (v34)
    {
      BillSetTexture(v34);
    }
  }
  evtFreePolygonMovieWorkData(v4);
  ida->func_ans = -1;
  dds3SetProcessData(&ida, 0);
  if ((v4->EventNo & 0xFFFFFFFC) == 0x324)
  {
    fldSetCharClr();
  }
  fldFreeNextFile();
  UnloadUnusedAssets();
  Collect(0);
  return 0;
}

// 0x11073a0
void *evtPolygonMovieShutdown1e(dds3ProcessID_t *id) {
  Il2CppObject *ProcessData;
  pmdProcessWork_t_o *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  s32 Count;
  evtTexManager_o *TexMngr;
  u64 *v20;
  System_String_o *v22;
  s32 EventNo;
  System_String_o *DLCTag;
  System_String_o *v27;
  UnityEngine_Object_o *EventFTree;
  UnityEngine_Object_o *v32;
  UnityEngine_Object_o *EventCTree;
  UnityEngine_Object_o *v37;
  s32 v42;
  dds3ProcessID_t_o *v45;
  u64 v46[3];

  v45 = id;
  ProcessData = dds3GetProcessData(&v45);
  v4 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pmdProcessWork_t)
    {
      sub_8FC2C0(klass->_1.element_class, pmdProcessWork_t, v46);
      if ((v46[0] & 1) != 0)
        v7 = v46[2];
      else
        v7 = v46 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  if (_get_Count(EventID))
  {
    _RemoveAt(EventID, 0);
  }
  Count = _get_Count(EventID);
  TexMngr = v4->TexMngr;
  if (Count)
  {
    if (TexMngr)
      Destroy(TexMngr, 0, 0);
    SwitchAnimation(v4, 0);
    fldFreeNextFile();
    {
LABEL_34:
    }
  }
  else
  {
    if (TexMngr)
      Destroy(TexMngr, 1, 0);
    LODWORD(v46[0]) = v4->EventNo;
    v20 = sub_8D3950(s32, v46);
    v22 = Format("e{0:D3}", v20, 0);
    EventNo = v4->EventNo;
    DLCTag = GetDLCTag(EventNo);
    v27 = Concat_5224608(v22, DLCTag);
    SwitchAnimation(v4, 0);
    if (op_Inequality(EventFTree, 0, 0))
    {
      v32 = EventFTree;
      Destroy_27360000(v32);
    }
    EventFTree = 0;
    if (op_Inequality(EventCTree, 0, 0))
    {
      v37 = EventCTree;
      Destroy_27360000(v37);
    }
    EventCTree = 0;
    RemoveKeys(3, v27);
    RemoveKeys(1, v27);
    FinalDanteEventMsg();
    fldFreeNextFile();
    v42 = v4->EventNo;
    SpEvtUnloadAll(v42);
    UnloadUnusedAssets();
      goto LABEL_34;
  }
  evtFreePolygonMovieWorkData(v4);
  v45->func_ans = -1;
  dds3SetProcessData(&v45, 0);
  return 0;
}

// 0x1103660
void evtResetPolygonMovieFlag(dds3ProcessID_t *id, u32 flag) {
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  dds3ProcessID_t_o *v9;
  u64 v10[3];

  v9 = id;
  ProcessData = dds3GetProcessData(&v9);
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pmdProcessWork_t)
  {
    sub_8FC2C0(klass->_1.element_class, pmdProcessWork_t, v10);
    if ((v10[0] & 1) != 0)
      v7 = v10[2];
    else
      v7 = v10 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD(ProcessData[1].klass) &= ~flag;
}

// 0x10f6f60
void evtRunUnitMode(pmdProcessWork_t *wdata, dds3Basic_t *unit, s32 mode) {
  dds3ModelHandle_t_o *Model;
  dds3ModelHandle_t_o *v11;
  dds3Basic_t_o *b;

  b = unit;
  switch (mode)
  {
    case 0:
      Model = dds3GetUnitHandleObjectBasic(&b)->Model;
      _mdlShow(wdata, Model);
      break;
    case 1:
      v11 = dds3GetUnitHandleObjectBasic(&b)->Model;
      _mdlHide(wdata, v11);
      break;
    case 2:
      dds3ObjectBaseOffFlag(&b, 0x400u);
      goto LABEL_20;
    case 3:
      dds3ObjectBaseOnFlag(&b, 0x400u, 0);
LABEL_20:
      dds3ObjectBaseOffFlag(&b, 0x200u);
      break;
    case 4:
      dds3ObjectBaseOffFlag(&b, 0x400u);
      dds3ObjectBaseOnFlag(&b, 0x200u, 0);
      break;
    default:
      return;
  }
}

// 0x11034a0
void evtRunUnitMode_17839264(dds3Basic_t *unit, s32 mode) {
  dds3Basic_t_o *pObjectBasic;

  pObjectBasic = unit;
  switch (mode)
  {
    case 4:
      dds3ObjectBaseOffFlag(&pObjectBasic, 0x400u);
      dds3ObjectBaseOnFlag(&pObjectBasic, 0x200u, 0);
      break;
    case 3:
      dds3ObjectBaseOnFlag(&pObjectBasic, 0x400u, 0);
      goto LABEL_8;
    case 2:
      dds3ObjectBaseOffFlag(&pObjectBasic, 0x400u);
LABEL_8:
      dds3ObjectBaseOffFlag(&pObjectBasic, 0x200u);
      break;
  }
}

// 0x1103540
void evtSetPolygonMovieFlag(dds3ProcessID_t *id, u32 flag) {
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  dds3ProcessID_t_o *v9;
  u64 v10[3];

  v9 = id;
  ProcessData = dds3GetProcessData(&v9);
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pmdProcessWork_t)
  {
    sub_8FC2C0(klass->_1.element_class, pmdProcessWork_t, v10);
    if ((v10[0] & 1) != 0)
      v7 = v10[2];
    else
      v7 = v10 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD(ProcessData[1].klass) |= flag;
}

// 0x1104120
dds3ProcessID_t *evtStartPolygonMovie2(s32 priority, s32 eventno, s32 cutno) {
  u64 *v7;
  System_String_o *v9;
  Il2CppObject *v12;
  dds3ProcessID_t_o *result;
  u64 *v16;
  u64 *v17;
  System_String_o *v19;
  System_String_o *DLCTag;
  System_String_o *v21;
  pmdProcessWork_t_o *data;
  System_String_o *v24;
  System_String_o *v25;
  System_Object_array *v27;
  s64 *v29;
  Il2CppClass *v31;
  s64 *v32;
  System_Byte_array *Interface;
  char *v34;
  s64 *v35;
  AssetBundleCtrl_o *asset_bc;
  System_String_o *v37;
  System_Byte_array *v38;
  System_String_o *v39;
  System_Object_array *v41;
  s64 *v43;
  System_Byte_array *FileByte;
  AssetBundleCtrl_o *v55;
  s32 v57;
  System_Object_array *v59;
  u64 *v60;
  u64 *v61;
  u64 *v63;
  u64 *v64;
  System_Object_array *v65;
  dds3ProcessID_t_o *v67;
  dds3ProcessID_t_o *v70;
  System_String_o *v73;
  System_Object_array *v74;
  s32 v80;
  s32 v81;
  dds3ProcessID_t_o *target;
  System_String_o *pm2file;
  System_String_o *pm1file;
  dds3ProcessID_t_o *parent;
  char v86[16];
  char *v87;

  pm1file = 0;
  parent = 0;
  target = 0;
  pm2file = 0;
  *v86 = eventno;
  v7 = sub_8D3950(s32, v86);
  v9 = Format("e{0:D3}pm.bytes", v7, 0);
  v12 = GetData(v9);
  MSGTRG = 0;
  else
  {
    bDanteEvent = 0;
    if (!v12)
      goto LABEL_18;
  }
  result = EvtStartPMDuplicate(priority, v12, eventno, cutno);
  if (!result)
  {
LABEL_18:
    CurrentEventNo = eventno;
    v16 = Allocate(dds3ProcessID_t);
    dds3ProcessID_t___ctor(v16);
    parent = v16;
    v81 = eventno;
    v17 = sub_8D3950(s32, &v81);
    v19 = Format("e{0:D3}", v17, 0);
    v80 = priority;
    DLCTag = GetDLCTag(eventno);
    v21 = Concat_5224608(v19, DLCTag);
    SetPMFileName(eventno, cutno, &pm1file, &pm2file);
    data = Allocate(pmdProcessWork_t);
    pmdProcessWork_t___ctor(data);
    data->EventNo = eventno;
    data->CutNo = cutno;
    v24 = pm1file;
    v25 = Concat_5221536("@@@@@ PM1Load : ", pm1file, " @@@@@@");
    v27 = Empty_string_();
    Log(v25, v27, 0);
    v29 = GetData(v24);
    if (v29)
    {
      v32 = v29;
      Interface = QueryInterface(v29, byte);
      if (!Interface)
      {
        sub_8FC2C0(*(*v32 + 64), v31, v86);
        if ((v86[0] & 1) != 0)
          v34 = v87;
        else
          v34 = &v86[1];
        v35 = sub_8C4940(v34);
      }
    }
    else
    {
      asset_bc = get_asset_bc();
      Interface = LoadFileByte(asset_bc, v21, v24);
    }
    v37 = pm2file;
    v38 = Interface;
    v39 = Concat_5221536("@@@@@ PM2Load : ", pm2file, " @@@@@@");
    v41 = Empty_string_();
    Log(v39, v41, 0);
    else
    {
      v43 = GetData(v37);
      if (v43)
        goto LABEL_48;
    }
    v55 = get_asset_bc();
    FileByte = LoadFileByte(v55, v21, v37);
      goto LABEL_61;
LABEL_50:
LABEL_61:
    evtGetPolygonMovieWorkData1(data, v38, FileByte);
    data->flag |= 8u;
    v57 = data->EventNo;
    if ((v57 - 804) < 3 || v57 == 676)
    {
      LoadKeys(3, v21, 0);
      LoadKeys(1, v21, 0);
    }
    v59 = Empty_string_();
    Log("@@@@@ StartPolygonMovie !!!!! @@@@@", v59, 0);
    v60 = Allocate(System_Func_dds3ProcessID_t__object_);
    object____ctor(
      v60,
      0,
      Method_evtPolygonMovie_evtPolygonMovieProcess1__);
    v61 = Allocate(System_Func_dds3ProcessID_t__object_);
    object____ctor(
      v61,
      0,
      Method_evtPolygonMovie_evtPolygonMovieShutdown__);
    parent = dds3StartProcess("PolygonMovie", v80, 1, 1, v60, 0, v61, 0, data, 0);
    v63 = Allocate(dds3ProcessID_t);
    dds3ProcessID_t___ctor(v63);
    v64 = Allocate(System_Func_dds3ProcessID_t__object_);
    object____ctor(
      v64,
      0,
      Method_dds3UnityEx_evtPolygonMovieUpdateEx_Unity__);
    target = dds3StartProcess("PolygonMovieEx", 0x2B0Au, 1, 1, v64, 0, 0, 0, data, 0);
    dds3LinkProcess(&parent, &target);
    v65 = NewSpecific(object, 5u);
    v65->m_Items[0] = "@@@@@ Init PolygonMovie End ";
    v67 = parent;
    v65->m_Items[1] = v67;
    v65->m_Items[2] = " : ";
    v70 = target;
    v65->m_Items[3] = v70;
    v65->m_Items[4] = " @@@@@";
    v73 = Concat_5270224(v65);
    v74 = Empty_string_();
    Log(v73, v74, 0);
    result = parent;
    data->ProcessID = parent;
  }
  return result;
}

// 0x10f8640
void evtStopMover(dds3Basic_t *mover, s32 sw, s32 baseframe, s32 nowframe) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3PathBasicControl_t_o *monitor;
  s32 frameMax;
  s32 v14;
  char *v15;
  s64 *v16;
  dds3PathBasicControl_t_o *v17[3];
  dds3PathBasicControl_t_o *pControl;

  pControl = 0;
  workdata = mover->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3MoverBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3MoverBasicWorkData_t, v17);
    if ((v17[0] & 1) != 0)
      v15 = v17[2];
    else
      v15 = v17 + 1;
    v16 = sub_8C4940(v15);
  }
  monitor = workdata[1].monitor;
  pControl = monitor;
  if (monitor)
  {
    frameMax = monitor->frameMax;
    v14 = (nowframe - baseframe) & ~((nowframe - baseframe) >> 31);
    if (v14 >= frameMax)
      v14 = frameMax;
    dds3PathBasicControlSetRatio(&pControl, v14 / frameMax);
    if (sw)
      dds3PathBasicPauseOff(&pControl);
    else
      dds3PathBasicPause(&pControl);
  }
}

// 0x1105ae0
void read_module(evtPolygonMovie_sLoadMode *mode, pmdProcessWork_t *wdata, void *ChrObj, void *FldObj) {
  u64 *v7;
  System_String_o *v9;
  s32 EventNo;
  System_String_o *DLCTag;
  u64 *v12;
  System_StringComparer_o *OrdinalIgnoreCase;
  u64 *v15;
  u64 *v16;
  u64 i;
  Il2CppObject *Data;
  struct pmdUnitTable_t_array *UnitTable;
  struct pmdNameTable_t_array *NameTable1;
  s64 NameIndex;
  Il2CppObject *Name;
  char *v32;
  s64 *v33;
  UnityEngine_Transform_o *transform;
  Il2CppObject *v36;
  UnityEngine_Transform_o *v37;
  System_String_o *v38;
  System_String_o *v39;
  UnityEngine_Animator_o *Animator;
  s32 v45;
  u64 v46[3];

  LODWORD(v46[0]) = wdata->EventNo;
  v7 = sub_8D3950(s32, v46);
  v9 = Format("e{0:D3}", v7, 0);
  EventNo = wdata->EventNo;
  DLCTag = GetDLCTag(EventNo);
  Concat_5224608(v9, DLCTag);
  v45 = wdata->EventNo;
  v12 = sub_8D3950(s32, &v45);
  Format("EVENT/E{0:D3}/", v12, 0);
  OrdinalIgnoreCase = get_OrdinalIgnoreCase();
  v15 = Allocate(System_Collections_Generic_Dictionary_string__GameObject_);
  GameObject____ctor(v15, OrdinalIgnoreCase);
  wdata->ChrList = v15;
  PropertySheet___Clear(v15);
  v16 = Allocate(System_Collections_Generic_Dictionary_GameObject__Animator_);
  PropertySheet____ctor(v16);
  wdata->AnmList = v16;
  PropertySheet___Clear(v16);
  if (wdata->UnitCount >= 1)
  {
    for (i = 0; i < wdata->UnitCount; ++i)
    {
      UnitTable = wdata->UnitTable;
      NameTable1 = wdata->NameTable1;
      NameIndex = UnitTable->m_Items[i]->NameIndex;
      Name = NameTable1->m_Items[NameIndex]->Name;
      if (Animator___ContainsKey(replace_list, Name))
      {
        Name = object___get_Item(replace_list, Name);
      }
      else
      {
        Data = GetData(Name);
        if (!Data)
          goto LABEL_33;
      }
      if (Data->klass != UnityEngine_GameObject)
      {
        sub_8FC2C0(Data->klass->_1.element_class, UnityEngine_GameObject, v46);
        if ((v46[0] & 1) != 0)
          v32 = v46[2];
        else
          v32 = v46 + 1;
        v33 = sub_8C4940(v32);
      }
LABEL_33:
      if (!op_Inequality(Data, 0, 0))
        continue;
      transform = get_transform(ChrObj, 0);
      v36 = Instantiate_object__425520(Data, transform);
      v37 = get_transform(v36, 0);
      Rotate_27486992(v37, 0.0, 180.0, 0.0);
      v38 = get_name(v36);
      v39 = Replace_5267216(v38, "(Clone)", "", 0);
      set_name(v36, v39);
      PropertySheet___Add(wdata->ChrList, Name, v36);
      Animator = GetAnimator(v36);
      if (op_Inequality(Animator, 0, 0))
      {
        PropertySheet___Add(wdata->AnmList, v36, Animator);
          goto LABEL_45;
      }
      else
      {
        HashSet_Text____Remove(wdata->ChrList, Name);
        {
LABEL_45:
        }
      }
      PriChrHDSet(v36);
    }
  }
  wdata->ChrObj = ChrObj;
  wdata->FldObj = FldObj;
  SwitchAnimation(wdata, 0);
}

// 0x1106370
void read_module_17851248(pmdProcessWork_t *wdata) {
  struct pmdStageTable_t_o *StageTable;
  s32 MinorNum;
  s32 MajorNum;
  System_Byte_array *StageF1;
  System_Byte_array *StageF2;
  System_Byte_array *StageTB;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v14;
  s64 *v15;
  u64 i;
  struct pmdUnitTable_t_array *UnitTable;
  s32 v19;
  s32 v20;
  s32 v22;
  Il2CppClass *v23;
  dds3Basic_t_o *j;
  Il2CppClass *v26;
  s64 v27;
  struct pmdUnitTable_t_array *v28;
  struct pmdNameTable_t_array *NameTable1;
  s64 NameIndex;
  Il2CppObject *name;
  Il2CppObject *Item;
  dds3Basic_t_o *v40;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v42;
  struct dds3PoseSet_t_o *poseset;
  f32 x;
  f32 y;
  f32 z;
  f32 w;
  struct dds3PoseSet_t_o *v49;
  Il2CppObject *v52;
  Il2CppClass *v53;
  s64 v54;
  char *v55;
  s64 *v56;
  s64 v57;
  struct pmdCameraTable_t_array *CameraTable;
  struct pmdCameraTable_t_array *v60;
  struct pmdNameTable_t_array *NameTable2;
  s64 v63;
  System_String_o *v65;
  System_String_o *v67;
  struct dds3Basic_t_array *pBasic;
  s64 v72;
  Il2CppClass *v73;
  struct dds3Basic_t_o *v75;
  System_String_o *v76;
  Il2CppClass *v77;
  struct dds3Basic_t_o *next;
  System_String_o *v80;
  System_String_o *v82;
  System_String_o *v83;
  dds3Basic_t_o *v84;
  dds3Basic_t_o *v85;
  Il2CppClass *v86;
  struct dds3Basic_t_o *namespaze;
  System_String_o *v89;
  System_String_o *v91;
  System_String_o *v92;
  dds3Basic_t_o *v93;
  dds3Basic_t_o *v94;
  char *v96;
  s64 *v97;
  dds3Basic_t_o *scene;
  dds3Basic_t_o *pMoverBasic;
  dds3Basic_t_o *pPathBasic;
  dds3Basic_t_o *basic;
  u64 v102[2];
  char *v103;
  UnityEngine_Vector3_o localPosition;
  UnityEngine_Vector3_o v105;
  UnityEngine_Vector3_o v106;
  UnityEngine_Vector3_o v107;
  UnityEngine_Vector4_o v108;

  pPathBasic = 0;
  basic = 0;
  scene = 0;
  pMoverBasic = 0;
  StageTable = wdata->StageTable;
  if (StageTable)
  {
    MajorNum = StageTable->MajorNum;
    MinorNum = StageTable->MinorNum;
    scene = dds3GetControlScene();
    if (dds3GetMapNo(&scene) != MinorNum + (MajorNum << 16))
    {
      StageF1 = wdata->StageF1;
      StageF2 = wdata->StageF2;
      StageTB = wdata->StageTB;
      evtLoadArea_FromMemory(MajorNum, MinorNum, StageF1, StageF2, StageTB, 0);
    }
  }
  workdata = dds3GetActiveScene()->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v102);
      if ((v102[0] & 1) != 0)
        v14 = v103;
      else
        v14 = v102 + 1;
      v15 = sub_8C4940(v14);
    }
  }
  if (wdata->UnitCount >= 1)
  {
    for (i = 0; i < wdata->UnitCount; ++i)
    {
      UnitTable = wdata->UnitTable;
      v19 = UnitTable->m_Items[i]->MajorNum;
      v20 = wdata->UnitTable->m_Items[i]->MinorNum;
      v22 = evtSetRegistUnit(v19, v20);
      else if (!workdata)
      {
        goto LABEL_42;
      }
      v23 = workdata[2].klass;
      for (j = v23->_1.castClass->_1.namespaze; j; j = j->next)
      {
        if (j->serialID == v22)
          break;
      }
LABEL_43:
      basic = j;
      v26 = j->workdata->klass;
      if (v26->_2.typeHierarchyDepth < v27
        || v26->_2.typeHierarchy[v27 - 1] != dds3UnitObjectBasicWorkData_t)
      {
        sub_8FC2C0(v26->_1.element_class, dds3UnitObjectBasicWorkData_t, v102);
        if ((v102[0] & 1) != 0)
          v96 = v103;
        else
          v96 = v102 + 1;
        v97 = sub_8C4940(v96);
      }
      v28 = wdata->UnitTable;
      NameTable1 = wdata->NameTable1;
      NameIndex = v28->m_Items[i]->NameIndex;
      j->name = NameTable1->m_Items[NameIndex]->Name;
      name = basic->name;
      if (Animator___ContainsKey(replace_list, name))
      {
        name = object___get_Item(replace_list, name);
      }
      if (Animator___ContainsKey(wdata->ChrList, name))
      {
        Item = object___get_Item(wdata->ChrList, name);
          goto LABEL_56;
      }
      else
      {
        Item = 0;
        {
LABEL_56:
        }
      }
      if (op_Inequality(Item, 0, 0))
      {
        v40 = basic;
        attach(v40, Item);
      }
      if (wdata->EventNo == 723
        && wdata->CutNo == 10
        && Equals_5239888(basic->name, "player_j.PB", 5))
      {
        transform = get_transform(Item, 0);
        localPosition = get_localPosition(transform);
        v42 = get_transform(Item, 0);
        v106.x = localPosition.x;
        v106.y = 0.08;
        v106.z = localPosition.z;
        set_localPosition(v42, v106);
        poseset = basic->poseset;
        x = poseset->pos.x;
        y = poseset->pos.y;
        z = poseset->pos.z;
        w = poseset->pos.w;
        v108.x = x;
        v108.y = y;
        v108.z = z;
        v108.w = w;
        v105 = op_Implicit_8738992(v108);
        v107.x = v105.x;
        v107.z = v105.z;
        v49 = basic->poseset;
        v107.y = -8.0;
        v49->pos = op_Implicit(v107, 0);
      }
    }
  }
  else
  {
    v52 = dds3GetControlScene()->workdata;
    if (!v52)
      goto LABEL_81;
  }
  v53 = v52->klass;
  if (v52->klass->_2.typeHierarchyDepth < v54 || v53->_2.typeHierarchy[v54 - 1] != dds3SceneBasic_t)
  {
    sub_8FC2C0(v53->_1.element_class, dds3SceneBasic_t, v102);
    if ((v102[0] & 1) != 0)
      v55 = v103;
    else
      v55 = v102 + 1;
    v56 = sub_8C4940(v55);
  }
LABEL_81:
  if (wdata->CameraCount >= 1)
  {
    v57 = 4;
    do
    {
      CameraTable = wdata->CameraTable;
      if ((*(*(&CameraTable->obj.klass + v57) + 16LL) & 0x80000000) == 0)
      {
        v60 = wdata->CameraTable;
        NameTable2 = wdata->NameTable2;
        v63 = *(*(&v60->obj.klass + v57) + 16LL);
        v65 = NameTable2->m_Items[v63]->Name;
        basic = dds3SceneBasicSearchNameAndType_(v52, 4u, v65);
        if (basic)
        {
          Clear(PMchkname, 0);
          Append_5380272(PMchkname, basic->name);
          Append_5380272(PMchkname, "_MOTION");
          v67 = (PMchkname->klass->vtable._3_ToString.methodPtr)(
                  PMchkname,
                  PMchkname->klass->vtable._3_ToString.method);
          pPathBasic = dds3SceneBasicSearchNameAndType_(v52, 0x10u, v67);
          if (pPathBasic)
          {
            pBasic = dds3CameraObjectBasicGetControlWorkData(&basic)->pBasic;
            pMoverBasic = pBasic->m_Items[1];
            dds3MoverBasicSetPath(&pMoverBasic, &pPathBasic);
            dds3MoverBasicMakePath(&pMoverBasic);
          }
        }
      }
      v72 = v57 - 3;
      ++v57;
    }
    while (v72 < wdata->CameraCount);
  }
  v73 = workdata[2].klass;
  v75 = *(v73->_1.nestedTypes + 3);
  for (basic = v75; v75; basic = v75)
  {
    while (1)
    {
      v76 = v75->name;
      if (v76 && get_Length(v76))
      {
        v77 = workdata[2].klass;
        next = *(v77->_1.typeDefinition + 3);
        pPathBasic = next;
        if (next)
        {
          while (1)
          {
            v80 = next->name;
            if (v80 && get_Length(v80))
            {
              Clear(PMchkname, 0);
              Append_5380272(PMchkname, pPathBasic->name);
              Append_5380272(PMchkname, "_MOTION");
              v82 = basic->name;
              v83 = (PMchkname->klass->vtable._3_ToString.methodPtr)(
                      PMchkname,
                      PMchkname->klass->vtable._3_ToString.method);
              if (op_Equality(v82, v83, 0))
                break;
            }
            next = pPathBasic->next;
            pPathBasic = next;
            if (!next)
              goto LABEL_125;
          }
          v85 = pPathBasic;
          v84 = basic;
          evtPathLinkAndMake(v84, v85);
        }
LABEL_125:
        v86 = workdata[2].klass;
        namespaze = v86->_1.parent->_1.namespaze;
        pPathBasic = namespaze;
        if (namespaze)
          break;
      }
LABEL_128:
      v75 = basic->next;
      basic = v75;
      if (!v75)
        goto LABEL_141;
    }
    while (1)
    {
      v89 = namespaze->name;
      if (v89 && get_Length(v89))
      {
        Clear(PMchkname, 0);
        Append_5380272(PMchkname, pPathBasic->name);
        Append_5380272(PMchkname, "_MOTION");
        v91 = basic->name;
        v92 = (PMchkname->klass->vtable._3_ToString.methodPtr)(
                PMchkname,
                PMchkname->klass->vtable._3_ToString.method);
        if (op_Equality(v91, v92, 0))
          break;
      }
      namespaze = pPathBasic->next;
      pPathBasic = namespaze;
      if (!namespaze)
        goto LABEL_128;
    }
    v94 = pPathBasic;
    v93 = basic;
    evtPathLinkAndMake(v93, v94);
    v75 = basic->next;
  }
LABEL_141:
  wdata->NowFrame = wdata->CutInfo->FirstFrame;
  if (wdata->EventNo != 800)
  {
    SetDrawFlag(0x2000000u, 1u);
    if (wdata->EventNo == 723 && evtBitCheck(3712))
    {
      ClrDrawFlag(0x2000000u);
    }
  }
}
