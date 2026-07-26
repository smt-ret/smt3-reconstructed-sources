#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct AssetBundles AssetBundles;
typedef struct PostBlur PostBlur;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;
typedef struct stfGlobal stfGlobal;

static stfGlobal *gGlobal;
static s32 IMGcnt;
static s32 IMGcnt2;
static char *EndingBackImageStr;
static void *EndingBackImage;
static char *EndingLineImageStr;
static void *EndingLineImage;
static char *EndingMaskImageStr;
static void *EndingMaskImage;
static void *CapcomLogo;
static void *EndingUseBackImage;
static void *EndingUseLineImage;
static f32 red;
static f32 green;
static f32 blue;
static f32 alpha;
static f32 alpha_;
static f32 fill;
static s32 debugFlg;
static s32 debugPos;
static s32 debugStrPos;
static void *debugImage;
static s32 ImageTiming;
static f32 alphaSpeed;
static f32 alpha_Speed;
static f32 fill_Speed;
static f32 lineAdjust;
static f32 fillAdjust;
static bool PicDispflag;
static bool FadeOutflag;
static bool LastFade;
static f32 fx;
static f32 fa;
static f32 fmx;
static f32 fw1;
static f32 fa1;
static s32 STAFF_IMAGE_MAX_NO;
static s32 STAFF_IMAGE_ONE_TIME;
static void *ButtonObj;
static void *FFobj;
static void *Skyobj;
static void *Kuti;
static void *ShadowC;
static void *FFCobj;
static void *TalkObj;
static void *CameraObj;
static void *MainCamera;
static PostBlur *Blur;
static void *PostObj;
static void *EndingLineImage_;
static void *EndingBackImage_;
static char *g_staff_pic_filename[15];
static char *g_staff_mpic_filename[15];
static s32 center_cnt;
static s32 staffname_cnt;
static s32 jobname_cnt;
static s32 Mojimoveflag;
static s32 centername_cnt;
static s32 staffnameobj_cnt;
static s32 jobnameobj_cnt;
static s32 centerobj_max;
static s32 jobobj_max;
static s32 staffobj_max;
static f32 mojispeed;
static s32 LogoPos;
static s32 newStaffAdjust;
static f32 lastposAdjust;
static s32 LogoPosAdjust;
static f32 posAdjust;
static f32 FrameWidth;
static f32 FrameHeight;
static s32 useLang;
static void *useFont;
static char *centername_str;
static char *jobname_str;
static char *staffname_str;
static void *FrameWH;
static void *StaffUIObj;
static void staff_nameobj[UNKNOWN_ARRAY_SIZE];
static void center_nameobj[UNKNOWN_ARRAY_SIZE];
static void job_nameobj[UNKNOWN_ARRAY_SIZE];
static void centerNameTM[UNKNOWN_ARRAY_SIZE];
static void staffNameTM[UNKNOWN_ARRAY_SIZE];
static void jobNameTM[UNKNOWN_ARRAY_SIZE];
static void *oStaff_UI;

void ClearStaffUI(void);
void EndingStaffRollUnlock(void);
void FilterDelete(void);
s32 FindId(s32 type, char *name);
s32 GetLanguage(void);
void *GetMainCamera(dds3DefaultMain *this);
bool IsLoad(AssetBundles *this, char *key);
void Load(char *key, char *filePath);
void *LoadAsset(AssetBundleCtrl *this, char *key, char *path, char *name);
void LoadKeys(s32 type, char *key, char *path);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
void ObjDispON(void);
void ObjDispOff(void);
void RemoveKeys(s32 type, char *key);
void SetNormalFrameRate(dds3DefaultMain *this);
void StaffImageManager(void);
void UnloadAB(AssetBundleCtrl *this, char *key);
void dds3AdminiCallSequence(s32 sequence, void *data, s32 datasize, s32 restore);
s32 dds3FadeCheck(void);
void dds3FadeIn(u32 r, u32 g, u32 b, u32 frame);
void dds3FadeOut(u32 r, u32 g, u32 b, u32 frame);
s32 dds3KillProcessName(char *name, s32 shutdowntimer);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
bool evtBitCheck(s32 no);
s32 p2sdPlayBGM(s32 a);
void rsetAlpha(s32 mode);
void rsetOtOfs(s32 otofs);
void rsetTest(s32 ate, s32 atst, s32 aref, s32 afail, s32 date, s32 datm, s32 zte, s32 ztst);
void sdfTexFree(sdfTexHandle_t *aHandle);
void sdfTexFreeDelayed(sdfTexHandle_t *aHandle);
sdfTexHandle_t *sdfTexSet(void *aTex);
void stfDrawImage2(void);
void stfFreeTex(void);
void stfImageEnd(void);
void stfImageStart(s32 no, s32 life, s32 dir);
void stfInit(void);
void stfSetTex(s32 i);

// 0x169b5d0
void ClearStaffUI(void) {
  UnityEngine_Object_o *oStaff_UI;
  UnityEngine_Object_o *v6;

  if (op_Inequality(oStaff_UI, 0, 0))
  {
    v6 = oStaff_UI;
    Destroy_27360000(v6);
    oStaff_UI = 0;
  }
}

// 0x169ad50
void *GetoStaffUI(void) {
  return oStaff_UI;
}

// 0x169b6d0
void ObjDispON(void) {
  UnityEngine_Object_o *ButtonObj;
  UnityEngine_Object_o *Skyobj;
  UnityEngine_Object_o *Kuti;
  UnityEngine_Object_o *TalkObj;
  UnityEngine_Object_o *ShadowC;
  UnityEngine_Object_o *FFCobj;

  set_enabled(Blur, 1);
  set_enabled(PostObj, 1);
  if (op_Inequality(ButtonObj, 0, 0))
  {
    if (!get_activeSelf(ButtonObj))
    {
      SetActive(ButtonObj, 1, 0);
    }
  }
  if (op_Inequality(Skyobj, 0, 0))
  {
    if (!get_activeSelf(Skyobj))
    {
      SetActive(Skyobj, 1, 0);
    }
  }
  if (op_Inequality(Kuti, 0, 0))
  {
    if (!get_activeSelf(Kuti))
    {
      SetActive(Kuti, 1, 0);
    }
  }
  if (op_Inequality(TalkObj, 0, 0))
  {
    if (get_activeSelf(TalkObj))
    {
      SetActive(TalkObj, 1, 0);
    }
  }
  if (op_Inequality(ShadowC, 0, 0))
  {
    if (!get_activeSelf(ShadowC))
    {
      SetActive(ShadowC, 1, 0);
    }
  }
  if (op_Inequality(FFCobj, 0, 0))
  {
    if (!get_activeSelf(FFCobj))
    {
      SetActive(FFCobj, 1, 0);
    }
  }
}

// 0x169adc0
void ObjDispOff(void) {
  UnityEngine_GameObject_o *MainCamera;
  Il2CppObject *Component_object;
  Il2CppObject *v8;
  Il2CppObject *v10;
  struct UnityEngine_GameObject_o *v12;
  UnityEngine_Object_o *ButtonObj;
  UnityEngine_GameObject_o *v20;
  UnityEngine_Object_o *Skyobj;
  UnityEngine_GameObject_o *v28;
  UnityEngine_Object_o *Kuti;
  UnityEngine_GameObject_o *v36;
  UnityEngine_Object_o *TalkObj;
  UnityEngine_GameObject_o *v44;
  UnityEngine_Object_o *ShadowC;
  UnityEngine_GameObject_o *v52;
  UnityEngine_Object_o *FFCobj;

  MainCamera = GetMainCamera(kernelObject);
  CameraObj = MainCamera;
  Component_object = GetComponent_object_(CameraObj);
  Blur = Component_object;
  v8 = GetComponent_object_(CameraObj);
  MainCamera = v8;
  v10 = GetComponent_object_(CameraObj);
  PostObj = v10;
  set_enabled(Blur, 0);
  set_enabled(PostObj, 0);
  v12 = Find(StringLiteral_22418, 0);
  ButtonObj = v12;
  if (op_Inequality(ButtonObj, 0, 0))
  {
    if (get_activeSelf(ButtonObj))
    {
      SetActive(ButtonObj, 0, 0);
    }
  }
  FilterDelete();
  v20 = Find(StringLiteral_5595, 0);
  Skyobj = v20;
  if (op_Inequality(Skyobj, 0, 0))
  {
    if (get_activeSelf(Skyobj))
    {
      SetActive(Skyobj, 0, 0);
    }
  }
  v28 = Find(StringLiteral_22419, 0);
  Kuti = v28;
  if (op_Inequality(Kuti, 0, 0))
  {
    if (get_activeSelf(Kuti))
    {
      SetActive(Kuti, 0, 0);
    }
  }
  v36 = Find(StringLiteral_22420, 0);
  TalkObj = v36;
  if (op_Inequality(TalkObj, 0, 0))
  {
    if (get_activeSelf(TalkObj))
    {
      SetActive(TalkObj, 0, 0);
    }
  }
  v44 = Find(StringLiteral_5604, 0);
  ShadowC = v44;
  if (op_Inequality(ShadowC, 0, 0))
  {
    if (get_activeSelf(ShadowC))
    {
      SetActive(ShadowC, 0, 0);
    }
  }
  v52 = Find(StringLiteral_5603, 0);
  FFCobj = v52;
  if (op_Inequality(FFCobj, 0, 0))
  {
    if (get_activeSelf(FFCobj))
    {
      SetActive(FFCobj, 0, 0);
    }
  }
}

// 0x1695e30
s32 STAFF_IMAGE_DRAWTIME(s32 keisu) {
  return STAFF_IMAGE_ONE_TIME * keisu;
}

// 0x1695ea0
void StaffImageManager(void) {
    stfImageStart(0, 0, 0);
    stfDrawImage2();
}

// 0x1695e20
void frwFreeStaffFont(void) {
  ;
}

// 0x1695e10
void frwLoadStaffFont(void) {
  ;
}

// 0x169bdf0
s32 stfDebugStart(void) {
  LODWORD(v2[2].klass->_1.interopData) = 1;
  stfInit();
  return -1;
}

// 0x169b400
dds3ProcessFunc_t *stfDestroy(dds3ProcessID_t *id) {
  AssetBundleCtrl_o *asset_bc;

  RemoveKeys(1, StringLiteral_22402);
  RemoveKeys(3, StringLiteral_22402);
  asset_bc = get_asset_bc();
  UnloadAB(asset_bc, StringLiteral_22402);
  ClearStaffUI();
  if (get_activeSelf(EndingUseBackImage))
  {
    SetActive(EndingUseBackImage, 0, 0);
  }
  if (get_activeSelf(EndingUseLineImage))
  {
    SetActive(EndingUseLineImage, 0, 0);
  }
  ObjDispON();
  FadeOutflag = 0;
  LastFade = 0;
  gGlobal->mh = 0;
  return 0;
}

// 0x1696460
void stfDrawImage2(void) {
    evtBitCheck(0);
    stfImageEnd();
    rsetOtOfs(0);
    rsetTest(0, 0, 0, 0, 0, 0, 0, 0);
    rsetAlpha(0);
}

// 0x1698620
void stfFontDraw(f32 x, f32 y, s32 mode, s32 rgba, char **moji) {
  ;
}

// 0x1698630
s32 stfFontGetWidth(s32 mode, s32 rgba, char **moji) {
  return 0;
}

// 0x1697f90
void stfFree(void) {
  struct sdfMemHandle_t_array *hFileLine;
  struct sdfMemHandle_t_array *v6;
  struct sdfMemHandle_t_array *v9;
  struct sdfMemHandle_t_array *v12;
  struct sdfMemHandle_t_array *v15;
  struct sdfMemHandle_t_array *v18;
  struct sdfMemHandle_t_array *v21;
  struct sdfMemHandle_t_array *v24;
  struct sdfMemHandle_t_array *hFileMask;
  struct sdfMemHandle_t_array *v30;
  struct sdfMemHandle_t_array *v33;
  struct sdfMemHandle_t_array *v36;
  struct sdfMemHandle_t_array *v39;
  struct sdfMemHandle_t_array *v42;
  struct sdfMemHandle_t_array *v45;
  struct sdfMemHandle_t_array *v48;
  s32 v51;
  s64 i;
  u64 v53;
  struct sdfMemHandle_t_array *hFilePic;
  struct sdfMemHandle_t_array *v57;
  u32 v59;
  sdfTexHandle_t_o *CapcomSpriteHandle;
  struct stfGlobal_o *gGlobal;

  hFileLine = gGlobal->hFileLine;
  if (hFileLine->m_Items[0])
  {
    v6 = gGlobal->hFileLine;
    v6->m_Items[0] = 0;
  }
  v9 = gGlobal->hFileLine;
  if (v9->m_Items[1])
  {
    v12 = gGlobal->hFileLine;
    v12->m_Items[1] = 0;
  }
  v15 = gGlobal->hFileLine;
  if (v15->m_Items[2])
  {
    v18 = gGlobal->hFileLine;
    v18->m_Items[2] = 0;
  }
  v21 = gGlobal->hFileLine;
  if (v21->m_Items[3])
  {
    v24 = gGlobal->hFileLine;
    v24->m_Items[3] = 0;
  }
  hFileMask = gGlobal->hFileMask;
  if (hFileMask->m_Items[0])
  {
    v30 = gGlobal->hFileMask;
    v30->m_Items[0] = 0;
  }
  v33 = gGlobal->hFileMask;
  if (v33->m_Items[1])
  {
    v36 = gGlobal->hFileMask;
    v36->m_Items[1] = 0;
  }
  v39 = gGlobal->hFileMask;
  if (v39->m_Items[2])
  {
    v42 = gGlobal->hFileMask;
    v42->m_Items[2] = 0;
  }
  v45 = gGlobal->hFileMask;
  if (v45->m_Items[3])
  {
    v48 = gGlobal->hFileMask;
    v48->m_Items[3] = 0;
  }
  for (i = 4; i != 19; ++i)
  {
    v53 = i - 4;
    hFilePic = gGlobal->hFilePic;
    if (*(&hFilePic->obj.klass + i))
    {
      v57 = gGlobal->hFilePic;
      *(&v57->obj.klass + i) = 0;
    }
    v51 = (v59 >> 9) & 1;
  }
  CapcomSpriteHandle = gGlobal->CapcomSpriteHandle;
  if (CapcomSpriteHandle)
  {
    sdfTexFreeDelayed(CapcomSpriteHandle);
  }
  gGlobal->CapcomSpriteHandle = 0;
  if (gGlobal->hFileCapcom)
  {
    gGlobal->hFileCapcom = 0;
  }
}

// 0x1697d80
void stfFreeTex(void) {
  sdfTexHandle_t_o *LineSpriteHandle;
  sdfTexHandle_t_o *MaskSpriteHandle;
  sdfTexHandle_t_o *PicSpriteHandle;

  LineSpriteHandle = gGlobal->LineSpriteHandle;
  if (LineSpriteHandle)
  {
    sdfTexFree(LineSpriteHandle);
  }
  MaskSpriteHandle = gGlobal->MaskSpriteHandle;
  if (MaskSpriteHandle)
  {
    sdfTexFree(MaskSpriteHandle);
  }
  PicSpriteHandle = gGlobal->PicSpriteHandle;
  if (PicSpriteHandle)
  {
    sdfTexFree(PicSpriteHandle);
  }
  gGlobal->LineSpriteHandle = 0;
  gGlobal->MaskSpriteHandle = 0;
  gGlobal->PicSpriteHandle = 0;
}

// 0x1697b80
void stfImageEnd(void) {
  stfMain_c *v6;
  struct stfMain_StaticFields *static_fields;
  struct stfMain_StaticFields *v8;

  stfFreeTex();
  gGlobal->ImgNo = 0;
  gGlobal->ImgCnt = 0;
  gGlobal->ImgAlpCnt = 0;
  gGlobal->FadeOutImgAlphaCnt = 0;
  gGlobal->ImgLife = 0;
  gGlobal->ImgDir = 0;
  gGlobal->ImageDrawing = 0;
  PicDispflag = 0;
  FadeOutflag = 1;
  ++IMGcnt;
  ++IMGcnt2;
  if (get_activeSelf(EndingMaskImage))
  {
    SetActive(EndingMaskImage, 0, 0);
  }
  else
  {
    static_fields = stfMain->static_fields;
    if (static_fields->IMGcnt < 16)
  }
  static_fields->IMGcnt = 16;
  else
  {
    v8 = v6->static_fields;
    if (v8->IMGcnt2 < 5)
      return;
  }
  v8->IMGcnt2 = 1;
}

// 0x1696330
void stfImageStart(s32 no, s32 life, s32 dir) {
  u64 v7;

  if (*(**(v7 + 184) + 204LL) == 1)
  {
    if ((*(v7 + 295) & 2) != 0 && !*(v7 + 216))
    stfImageEnd(v7);
  }
  *(**(v7 + 184) + 176LL) = no;
  *(**(v7 + 184) + 180LL) = 0;
  *(**(v7 + 184) + 184LL) = 0;
  *(**(v7 + 184) + 200LL) = 0;
  *(**(v7 + 184) + 188LL) = life;
  *(**(v7 + 184) + 192LL) = dir;
  stfSetTex(no, *&life);
  FadeOutflag = 0;
  gGlobal->ImageDrawing = 1;
}

// 0x169bb80
void stfInit(void) {
  u64 *v3;
  AssetBundleCtrl_o *asset_bc;
  u64 *v8;
  u64 *v9;

  dds3BackColor = 0x80000000;
  v3 = Allocate(stfGlobal);
  _ctor(v3, 0);
  gGlobal = v3;
  gGlobal->step = 0;
  gGlobal->pos = 0;
  gGlobal->cnt = 0;
  gGlobal->max = 0;
  gGlobal->roll = 0.0;
  gGlobal->speed = 0.1;
  gGlobal->LineSpriteHandle = 0;
  gGlobal->MaskSpriteHandle = 0;
  gGlobal->PicSpriteHandle = 0;
  IMGcnt = 1;
  IMGcnt2 = 1;
  Mojimoveflag = 0;
  job_nameobj = 0;
  staff_nameobj = 0;
  center_nameobj = 0;
  PicDispflag = 0;
  FadeOutflag = 1;
  asset_bc = get_asset_bc();
  Load(asset_bc, StringLiteral_22402, StringLiteral_22402, 0);
  v8 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v8,
    0,
    Method_stfMain_stfMain2__);
  v9 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v9,
    0,
    Method_stfMain_stfDestroy__);
  dds3StartProcess(StringLiteral_22417, 0x2B19u, 0, 0, v8, 0, v9, 0, 0, 0);
}

// 0x1697f80
void stfLoad(void) {
  ;
}

// 0x16987f0
dds3ProcessFunc_t *stfMain2(dds3ProcessID_t *id) {
    IsLoad(0, 0);
    LoadPrefab_16624656(0, 0, 0, 0);
    EndingStaffRollUnlock();
    StaffImageManager();
    dds3FadeOut(0, 0, 0, 0);
    dds3FadeCheck();
    evtBitCheck(0);
    dds3AdminiCallSequence(0, 0, 0, 0);
    dds3FadeIn(0, 0, 0, 0);
    LoadKeys(0, 0, 0);
    FindId(0, 0);
    p2sdPlayBGM(0);
    ObjDispOff();
    GetLanguage();
    LoadAsset(0, 0, 0, 0);
    return 0;
}

// 0x1698640
void stfSetTex(s32 i) {
  u64 *v3;
  u64 *v4;
  u64 *v6;
  struct stfGlobal_o *gGlobal;
  s32 v9;
  signed s32 v10;
  s64 v11;
  Il2CppObject *v13;
  struct stfGlobal_o *v14;
  struct stfGlobal_o *v16;

  v3 = NewSpecific(object, 4u);
  v4 = NewSpecific(object, 4u);
  v6 = NewSpecific(object, 0xFu);
  v9 = i + 3;
  if (i >= 0)
    v9 = i;
  v10 = i - (v9 & 0xFFFFFFFC);
  v11 = v10;
  v13 = v3[v10 + 4];
  gGlobal->LineSpriteHandle = sdfTexSet(v13);
  v14 = gGlobal;
  v14->MaskSpriteHandle = sdfTexSet(v4[v11 + 4]);
  v16 = gGlobal;
  v16->PicSpriteHandle = sdfTexSet(v6[i + 4]);
}

// 0x169bee0
s32 stfShutDown(void) {
  dds3KillProcessName(StringLiteral_22417, 1);
  SetNormalFrameRate(kernelObject);
  return 0;
}

// 0x169be70
s32 stfStart(void) {
  stfInit();
  return -1;
}
