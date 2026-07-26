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
static u8 EffDat[UNKNOWN_ARRAY_SIZE];
static pmdSceneLightTable_t *SLightFrameFunc_sl;
static pmdSceneFogTable_t *SFogFrameFunc_sf;
static dds3Effect_Blur_t *Blur2FrameFunc_bl2;
static dds3Effect_PartialMultiBlurParam_t *MBlurFrameFunc_mbl;
static dds3Effect_DistortionBlurParam_t *DBlurFrameFunc_dbl;
static dds3Effect_RippleBlurParam_t *RBlurFrameFunc_rbl;
static dds3Effect_PartialMultiFilterParam_t *MFilterFrameFunc_mfl;
static dds3Effect_Filter_t *FilterFrameFunc_fl;
static evtPolygonMovie_FrameRunStruct framefunc[UNKNOWN_ARRAY_SIZE];
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
    dds3EffectObjectBasicStatOn(0, 0);
    dds3StartBEDEffectObjectBasic(0, 0);
    billCutRaitoSet(0);
    billAlfRaitoSet(0);
    billBriRaitoSet(0);
    dds3AddD3PEffectObjectBasic2(0, (sdfVector4_t){0}, (sdfVector4_t){0});
    GetPibIndex(0, 0);
    Log(0, 0);
    BillSetPB(0);
    dds3AddBEDEffectObjectBasic2(0, (sdfVector4_t){0}, (sdfVector4_t){0});
    dds3AddMG12EffectObjectBasic2(0, 0);
    return 0;
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
  v18 = AddEffect(wdata, f, f);
  eff = v18;
  if (!v18)
  {
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
    AddEffect(0, 0);
    dds3GetActiveScene();
    dds3SceneBasicSearchNameAndType_(0, 0, 0);
    dds3EffectObjectSetMG12Pos(0, 0, 0, 0, 0);
    dds3EffectObjectPresetMG12(0);
    return 0;
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
  }
  Data = f->Data;
  Frame = f->Frame;
  if (!LODWORD(Data->max_length))
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
    evtPlayBgm(0, 0);
    evtFadeInBgm(0, 0);
    evtFadeOutBgm(0, 0);
    evtTransBgm(0, 0);
    p2sdBGMVolHalfDown();
    p2sdBGMVolHalfUp();
    p2sdBGMStopAll();
}

// 0x10fb030
void Blur2FrameFunc(pmdProcessWork_t *wdata, pmdFrameTable_t *f, pmdFrameTable_t *nf, s32 now) {
    evtHokanBlur2(0, 0, 0, 0, 0);
    Eve_BlurSetParam(0);
    Eve_BlurON();
    Eve_BlurOFF();
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
  }
  Data = f->Data;
  if (LODWORD(Data->max_length) <= 1)
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
    dds3GetControlScene();
    dds3SceneBasicSearchNameAndType_(0, 0, 0);
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
    evtHokanDistBlur(0, 0, 0, 0, 0);
    Eve_DistortionBlurSetParam(0);
    Eve_DistortionBlurON();
    Eve_DistortionBlurOFF();
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
  }
  if (*&Data->m_Items[0].c2 < 1)
  v20 = f->Data;
  if (*&v20->m_Items[0].c2 != now)
  {
    v26 = f->Data;
    if (LODWORD(v26->max_length))
  }
  v21 = f->Data;
  c0 = v21->m_Items[0].c0;
  DelEffectTable(wdata, c0, nf);
  v24 = f->Data;
  v24->m_Items[0].c0 = -1;
  v26 = f->Data;
  if (!LODWORD(v26->max_length))
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
    GetDLCTag(0);
    InitializeReplaceList(0);
    SetPMFileName(0, 0, 0, 0);
    Log(0, 0);
    GetData(0);
    LoadFileByte(0, 0, 0);
    evtGetPolygonMovieWorkData1(0, 0, 0);
    read_module(0, 0, 0, 0);
    LoadKeys(0, 0, 0);
    Initialize(0, 0, 0);
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
    dds3LinkProcess(0, 0);
    SetShadowMode(0, 0);
    InitDanteEventMsg();
    return 0;
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
  }
  else
  {
    Frame = f->Frame;
    if (wdata->EventNo != 634)
    {
      if (Frame != now)
        return;
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
    Data = f->Data;
    switch (*&Data->m_Items[0].c0)
    {
      case 0:
        Length = f->Length;
        v12 = 255;
        v13 = 255;
        v14 = 255;
      case 1:
        v16 = f->Length;
        v17 = 255;
        v18 = 255;
        v19 = 255;
      case 2:
        Length = f->Length;
        v12 = 0;
        v13 = 0;
        v14 = 0;
        dds3FadeIn(v12, v13, v14, Length);
        return;
      case 3:
        v16 = f->Length;
        v17 = 0;
        v18 = 0;
        v19 = 0;
        dds3FadeOut(v17, v18, v19, v16);
        break;
      default:
        return;
    }
  }
}

// 0x10fe620
void FilterFrameFunc(pmdProcessWork_t *wdata, pmdFrameTable_t *f, pmdFrameTable_t *nf, s32 now) {
    evtHokanFilter(0, 0, 0, 0, 0);
    Eve_FilterSetParam(0);
    Eve_FilterON();
    Eve_FilterOFF();
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
      v12 = wdata->FrameTable;
      if (v12->m_Items[v5 + 1]->ObjectType == v6->ObjectType)
      {
        v14 = wdata->FrameTable;
        v16 = v14->m_Items[v5 + 1];
        if (!v8)
        {
          v17 = v6->ObjectType - 3;
        }
      }
      else
      {
        v16 = 0;
        if (!v8)
      }
      ObjectType = v6->ObjectType;
      if (v8->ObjectType != ObjectType)
        v8 = 0;
      v17 = ObjectType - 3;
      if (v17 <= 0x14)
      {
        switch (v17)
        {
          case 0u:
          case 0x11u:
          case 0x12u:
            Data = v6->Data;
            if (!*&Data->m_Items[0].c2)
            v30 = v6->Data;
            v32 = *&v30->m_Items[0].c2;
            break;
          case 6u:
          case 9u:
          case 0x13u:
          case 7u:
          case 8u:
          case 0xAu:
          case 0xBu:
          case 0xCu:
          case 0xDu:
          case 0xEu:
          case 0x14u:
          case 0xFu:
            v34 = v6->Data;
            if (!*&v34->m_Items[0].c0)
            v35 = v6->Data;
            v32 = *&v35->m_Items[0].c0;
            break;
          default:
        }
        Length = v32 + 1 - v6->Frame;
        if (Length < 1)
        NowFrame = wdata->NowFrame;
        Frame = v6->Frame;
        v39 = Length + Frame;
        if (NowFrame < Frame || NowFrame >= v39)
        v23 = v6->ObjectType;
        if (!framefunc->m_Items[v23].func)
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
          break;
        }
      }
      else
      {
        Length = v6->Length;
        if (v6->Length)
        if (Length)
        {
          v18 = wdata->NowFrame;
          if (v18 >= v6->Frame)
          {
            if (!v16 || v18 < v16->Frame)
          }
          else        }
        else
        {
          if (wdata->NowFrame >= v6->Frame)
        }
        FrameCount = wdata->FrameCount;
        v5 = v11;
        if (v11 >= FrameCount)
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
    GetDLCTag(0);
    SetEventNo(0);
}

// 0x10f60e0
bool IsPolygonMovie(s32 eventno) {
  return CurrentEventNo == eventno;
}

// 0x10f9a80
void LightFrameFunc(pmdProcessWork_t *wdata, pmdFrameTable_t *f, pmdFrameTable_t *nf, s32 now) {
    dds3GetActiveScene();
    dds3SceneBasicSearchNameAndType_(0, 0, 0);
    evtGetUnitHandle2(0);
    evtLinkLightObjectBasic(0, 0, 0);
    evtUnlinkLightObjectBasic(0, 0);
    Log(0, 0);
}

// 0x10fbec0
void MBlurFrameFunc(pmdProcessWork_t *wdata, pmdFrameTable_t *f, pmdFrameTable_t *nf, s32 now) {
    evtHokanMultBlur(0, 0, 0, 0, 0);
    Eve_PartialMultiBlurSetParam(0);
    Eve_PartialMultiBlurON();
    Eve_PartialMultiBlurOFF();
}

// 0x10fde40
void MFilterFrameFunc(pmdProcessWork_t *wdata, pmdFrameTable_t *f, pmdFrameTable_t *nf, s32 now) {
    evtHokanMultFilter(0, 0, 0, 0, 0);
    Eve_PartialMultiFilterSetParam(0);
    Eve_PartialMultiFilterON();
    Eve_PartialMultiFilterOFF();
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
  }
  else
  {
    if (*&Data->m_Items[0].c2 < 1)
    v14 = f->Data;
    if (*&v14->m_Items[0].c2 == now)
    {
      v15 = f->Data;
      c0 = v15->m_Items[0].c0;
      DelEffectTable(wdata, c0, nf);
      v18 = f->Data;
      v18->m_Items[0].c0 = -1;
      v12 = f->Data;
    }
    else
    {
      v12 = f->Data;
      if (!LODWORD(v12->max_length))
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
    evtHokanRipBlur(0, 0, 0, 0, 0);
    Eve_RippleBlurSetParam(0);
    Eve_RippleBlurON();
    Eve_RippleBlurOFF();
}

// 0x10fab80
void SFogFrameFunc(pmdProcessWork_t *wdata, pmdFrameTable_t *f, pmdFrameTable_t *nf, s32 now) {
    evtHokanSceneFog(0, 0, 0, 0, 0);
    dds3SetFogPara(0, 0, 0, 0, 0);
}

// 0x10fa550
void SLightFrameFunc(pmdProcessWork_t *wdata, pmdFrameTable_t *f, pmdFrameTable_t *nf, s32 now) {
    evtHokanSceneLight(0, 0, 0, 0, 0);
    dds3SetLightColor(0, 0, (sdfVector4_t){0});
    dds3SetLightDir(0, 0, (sdfVector4_t){0});
    dds3SetAmbientColor(0, (sdfVector4_t){0});
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
    dds3GetActiveScene();
    dds3SceneBasicSearchNameAndType_(0, 0, 0);
    return 0;
}

// 0x1103970
void SetPMFileName(s32 eventno, s32 cutno, char **pm1file, char **pm2file) {
    GetDLCTag(0);
}

// 0x10f9f20
void SkyFrameFunc(pmdProcessWork_t *wdata, pmdFrameTable_t *f, pmdFrameTable_t *nf, s32 now) {
    Log(0, 0);
    Get_Skip_PM_Sky(0, 0, 0);
    fldSkySetFilter(0, 0, 0);
    evtSetSkyAlpha(0, 0);
}

// 0x10f65f0
void StartAnimation(pmdProcessWork_t *wdata) {
    dds3GetControlScene();
    dds3SceneBasicSearchNameAndType_(0, 0, 0);
    GetAnimator(0);
    SetFrame(0, 0, 0);
}

// 0x1106040
void SwitchAnimation(pmdProcessWork_t *wdata, bool sw) {
}

// 0x10f6cb0
void UnitFrameFunc(pmdProcessWork_t *wdata, pmdFrameTable_t *f, pmdFrameTable_t *nf, s32 now) {
    dds3GetControlScene();
    dds3SceneBasicSearchNameAndType_(0, 0, 0);
    dds3GetUnitHandleObjectBasic(0);
    evtRunUnitMode(0, 0, 0);
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
    AttachHD(0, 0, 0, 0);
    UpdateDying(0);
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
      }
    }
    else
    {
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
        }
      }
      else
      {
        v14 = Concat_5221536(StringLiteral_15974, name, StringLiteral_12197);
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
    dds3GetProcessData(0);
    return 0;
}

// 0x11014e0
s32 evtCheckPolygonMovieRun(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
    return 0;
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
    pmdHeader_t__SetData(0, 0, 0);
    pmdTypeTable_t__SetData(0, 0, 0);
    MarkTmxIndex(0);
    MarkPibIndex(0);
    pmdStageTable_t__SetData(0, 0, 0);
    IsLoad(0, 0);
    Load(0, 0);
    pmdUnitTable_t__SetData(0, 0, 0);
    pmdEffectTable_t__SetData(0, 0, 0);
    pmdCutInfo_t__SetData(0, 0, 0);
    pmdFrameTable_t__SetData(0, 0, 0);
    pmdCameraTable_t__SetData(0, 0, 0);
    pmdSceneLightTable_t__SetData(0, 0, 0);
    pmdSceneFogTable_t__SetData(0, 0, 0);
    dds3Effect_Blur_t__SetData(0, 0, 0);
    dds3Effect_PartialMultiBlurParam_t__SetData(0, 0, 0);
    dds3Effect_DistortionBlurParam_t__SetData(0, 0, 0);
    dds3Effect_Filter_t__SetData(0, 0, 0);
    dds3Effect_PartialMultiFilterParam_t__SetData(0, 0, 0);
    dds3Effect_RippleBlurParam_t__SetData(0, 0, 0);
    return 0;
}

// 0x1103dc0
pmdProcessWork_t *evtGetPolygonMovieWorkData2(s32 eventno, s32 cutno, s32 type) {
    GetDLCTag(0);
    SetPMFileName(0, 0, 0, 0);
    GetData(0);
    LoadFileByte(0, 0, 0);
    evtGetPolygonMovieWorkData1(0, 0, 0);
    evtFreePolygonMovieWorkData(0);
    return 0;
}

// 0x10fb2f0
void evtHokanBlur2(s32 hokan, f32 ratio, dds3Effect_Blur_t *key1, dds3Effect_Blur_t *key2, dds3Effect_Blur_t **d) {
    DDS3EFFECT_BLEND_SEMI();
    SDF_VU0__dds3ColorItoF(0);
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__dds3ColorFtoI(0);
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
    }
    pm->m_Items[0] = v45;
    v49 = (*d)->center->pm;
    v66 = key1->center->pm;
    v56 = v66->m_Items[1];

    {
      v32 = 1.0 - ratio;
      if ((v49->max_length & 0xFFFFFFFE) == 0)
    }
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
    DDS3EFFECT_BLEND_ADD();
    SDF_VU0__dds3ColorItoF(0);
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__dds3ColorFtoI(0);
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
    DDS3EFFECT_BLEND_SEMI();
    SDF_VU0__dds3ColorItoF(0);
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__dds3ColorFtoI(0);
}

// 0x10fe110
void evtHokanMultFilter(s32 hokan, f32 ratio, dds3Effect_PartialMultiFilterParam_t *key1, dds3Effect_PartialMultiFilterParam_t *key2, dds3Effect_PartialMultiFilterParam_t **d) {
    DDS3EFFECT_BLEND_ADD();
    SDF_VU0__dds3ColorItoF(0);
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__dds3ColorFtoI(0);
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
    }
    pm->m_Items[0] = v40;
    v44 = (*d)->center->pm;
    v61 = key1->center->pm;
    v51 = v61->m_Items[1];

    {
      v30 = 1.0 - ratio;
      if ((v44->max_length & 0xFFFFFFFE) == 0)
    }
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
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SCALEVECTOR_B(0);
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__VECTOR_W_SET_ONE();
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
    dds3GetProcessData(0);
    CheckLoad(0);
    Log(0, 0);
    GetDLCTag(0);
    SetShadowMode(0, 0);
    dds3Effect_PartialMultiBlurParam_t__Clear(0);
    dds3Effect_DistortionBlurParam_t__Clear(0);
    dds3Effect_RippleBlurParam_t__Clear(0);
    dds3Effect_PartialMultiFilterParam_t__Clear(0);
    dds3Effect_Filter_t__Clear(0);
    InitializeReplaceList(0);
    fldSetCharClr();
    dds3GetControlScene();
    dds3GetMapNo(0);
    evtLoadArea_FromMemory(0, 0, 0, 0, 0, 0);
    evtBitCheck(0);
    dds3GetActiveScene();
    evtSetRegistUnit(0, 0);
    AttachModel_26586560(0, 0, 0, 0);
    mdlSmoothSingleMotion(0, 0, 0, 0, 0);
    LoadEventModel();
    dds3SceneBasicSearchNameAndType_(0, 0, 0);
    dds3CameraObjectBasicGetControlWorkData(0);
    dds3MoverBasicSetPath(0, 0);
    dds3MoverBasicMakePath(0);
    evtPathLinkAndMake(0, 0);
    FrameTableOverWrite(0);
    Destroy(0, 0);
    Initialize(0, 0, 0);
    Initialize(0, 0, 0);
    BillSetTexture(0);
    SetDrawFlag(0, 0);
    ClrDrawFlag(0);
    FrameRun(0);
    StartAnimation(0);
    return 0;
}

// 0x11070b0
void *evtPolygonMovieProcess1e(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
    read_module_17851248(0);
    SwitchAnimation(0, 0);
    dds3Effect_PartialMultiBlurParam_t__Clear(0);
    dds3Effect_DistortionBlurParam_t__Clear(0);
    dds3Effect_RippleBlurParam_t__Clear(0);
    dds3Effect_PartialMultiFilterParam_t__Clear(0);
    dds3Effect_Filter_t__Clear(0);
    BillSetTexture(0);
    evtBitCheck(0);
    ClrDrawFlag(0);
    SetDrawFlag(0, 0);
    FrameRun(0);
    StartAnimation(0);
    return 0;
}

// 0x10ff740
dds3ProcessFunc_t *evtPolygonMovieProcess2(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
    FrameRun(0);
    DispAnimation(0);
    return 0;
}

// 0x10ff920
void *evtPolygonMovieProcess3(dds3ProcessID_t *id) {
    IsStartModelLoaded();
    dds3GetProcessData(0);
    FrameRun(0);
    DispAnimation(0);
    return 0;
}

// 0x1102b00
void *evtPolygonMovieShutdown(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
    DeletePB(0);
    Destroy(0, 0);
    GetDLCTag(0);
    RemoveKeys(0, 0);
    Initialize(0, 0, 0);
    Initialize(0, 0, 0);
    BillSetTexture(0);
    evtFreePolygonMovieWorkData(0);
    dds3SetProcessData(0, 0);
    fldSetCharClr();
    fldFreeNextFile();
    return 0;
}

// 0x11073a0
void *evtPolygonMovieShutdown1e(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
    Destroy(0, 0);
    SwitchAnimation(0, 0);
    fldFreeNextFile();
    GetDLCTag(0);
    RemoveKeys(0, 0);
    FinalDanteEventMsg();
    SpEvtUnloadAll(0);
    evtFreePolygonMovieWorkData(0);
    dds3SetProcessData(0, 0);
    return 0;
}

// 0x1103660
void evtResetPolygonMovieFlag(dds3ProcessID_t *id, u32 flag) {
    dds3GetProcessData(0);
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
    case 3:
      dds3ObjectBaseOnFlag(&b, 0x400u, 0);
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
    case 2:
      dds3ObjectBaseOffFlag(&pObjectBasic, 0x400u);
      dds3ObjectBaseOffFlag(&pObjectBasic, 0x200u);
      break;
  }
}

// 0x1103540
void evtSetPolygonMovieFlag(dds3ProcessID_t *id, u32 flag) {
    dds3GetProcessData(0);
}

// 0x1104120
dds3ProcessID_t *evtStartPolygonMovie2(s32 priority, s32 eventno, s32 cutno) {
    GetData(0);
    EvtStartPMDuplicate(0, 0, 0, 0);
    GetDLCTag(0);
    SetPMFileName(0, 0, 0, 0);
    Log(0, 0);
    LoadFileByte(0, 0, 0);
    evtGetPolygonMovieWorkData1(0, 0, 0);
    LoadKeys(0, 0, 0);
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
    dds3LinkProcess(0, 0);
    return 0;
}

// 0x10f8640
void evtStopMover(dds3Basic_t *mover, s32 sw, s32 baseframe, s32 nowframe) {
    dds3PathBasicControlSetRatio(0, 0);
    dds3PathBasicPauseOff(0);
    dds3PathBasicPause(0);
}

// 0x1105ae0
void read_module(evtPolygonMovie_sLoadMode *mode, pmdProcessWork_t *wdata, void *ChrObj, void *FldObj) {
    GetDLCTag(0);
    GetData(0);
    GetAnimator(0);
    PriChrHDSet(0);
    SwitchAnimation(0, 0);
}

// 0x1106370
void read_module_17851248(pmdProcessWork_t *wdata) {
    dds3GetControlScene();
    dds3GetMapNo(0);
    evtLoadArea_FromMemory(0, 0, 0, 0, 0, 0);
    dds3GetActiveScene();
    evtSetRegistUnit(0, 0);
    attach(0, 0);
    dds3SceneBasicSearchNameAndType_(0, 0, 0);
    dds3CameraObjectBasicGetControlWorkData(0);
    dds3MoverBasicSetPath(0, 0);
    dds3MoverBasicMakePath(0);
    evtPathLinkAndMake(0, 0);
    SetDrawFlag(0, 0);
    evtBitCheck(0);
    ClrDrawFlag(0);
}
