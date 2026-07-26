#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct sdfMovieCb_t sdfMovieCb_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;
typedef struct titleGlobal titleGlobal;

static s32 mainMenuIdxCnt;
static s32 mainMenuTextIdxCnt;
static s32 movieChangeflag;
static s32 dlcChackflag;
static s32 continueCursurflag;
static s32 fadeoutTime;
static s32 movTitleInitflag;
static void *modeobj;
static void *MainMenuObj;
static void *mainMenuCursur;
static sdfVector3_t mainMenuCursurPos;
static void *mainMenuCursur_r;
static char *mainMenuIdx_str;
static void *mainMenuIdx;
static sdfVector3_t mainMenuIdxPos;
static char *mainMenuText_str;
static void *mainMenu;
static void *mainMenuTM;
static char *mainMenuTextIdx_str;
static void *mainMenuTextIdx;
static void *mainMenuTextTM;
static void *TitleObj;
static void *titleobj;
static void *titleStartLogo;
static void *titleSprite[7];
static s32 titleStartInitflag;
static s32 titleStartLogoAnimflag;
static f32 titleStartLogoAnimtime;
static void *titleStartLogoAnim;
static s32 WarningCnt;
static u32 WarningFadeSpeed;
static bool Warningflag;
static void *WarningObj;
static s32 title2Pos;
static s32 title2flag;
static s32 title2mode;
static bool title2Posflag;
static bool MovieSkipflag;
static char *titleMainText[4];
static char Lclstr[UNKNOWN_ARRAY_SIZE];
static char Lclstr_a[UNKNOWN_ARRAY_SIZE];
static char *Dellcl[1];
static char *titleMainMenuText[7];
static char *titleMainMenuText_K[7];
static s32 titleMainInitflag;
static s32 titileMainCursorflag;
static s32 menuCursurCnt;
static char *titleMainHELPText[7];
static u8 dlcMesData[983];
static s32 dlcMsgNum;
static bool dlcMsgSave;
static void *DLCMsgFunc;
static dds3ProcessID_t *DLCMsgID;
static sdfMovieCb_t *dds3MovieCb;
static titleGlobal *gGlobal;
static s32 gGemeMode;
static f32 dds3DrawMenuString_cntf;
static f32 dds3DrawNameSprite_fcnt;
static s32 dds3TitleMain_mode;
static void *oMainmenu_UI;
static void *oA_logo_UI;
static void *oD_logo_UI;

void ButtonGuideDispOff(void);
void ButtonGuideDispSet(char *name, bool timer, bool empty, s32 waitTimer);
void ClearA_logoUI(void);
void ClearD_logoUI(void);
void ClearMainmenuUI(void);
bool DDS3_PADCHECK_PRESS(s32 id);
bool DDS3_PADCHECK_REP(s32 id);
bool DDS3_PADCHECK_TRIG(s32 id);
void FilterDelete(void);
s32 FindId(s32 type, char *name);
char *GetLocalizeText(char *ID);
char *GetPlatformStr(void);
void LoadLocalizeText(char *key, char *filename);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
void Remove(char *key);
char *RepColTag(char *txt, void **LegacyParamArray);
void aDrawBoxG(s32 x, s32 y, s32 w, s32 h, s32 r0, s32 g0, s32 b0, s32 a0, s32 r1, s32 g1, s32 b1, s32 a1, s32 r2, s32 g2, s32 b2, s32 a2, s32 r3, s32 g3, s32 b3, s32 a3);
void dds3AdminiCallSequence(s32 sequence, void *data, s32 datasize, s32 restore);
bool dds3CheckDLC1(void);
bool dds3CheckDLC2(void);
bool dds3CheckDLC3(void);
bool dds3CheckDLC4(void);
bool dds3CheckDLC5(void);
bool dds3CheckDLC6(void);
bool dds3CheckDLC7(void);
bool dds3CheckDLC8(void);
void dds3CheckPadInput(void);
void dds3CheckPadInput2(void);
void dds3DestroyTitleSprite(void);
void dds3DrawLogoSprite(void);
void dds3DrawMenuString(void);
void dds3DrawNameSprite(void);
s32 dds3FadeCheck(void);
void dds3FadeIn(u32 r, u32 g, u32 b, u32 frame);
void dds3FadeIn2(u32 frame);
void dds3FadeOut(u32 r, u32 g, u32 b, u32 frame);
void dds3InitTitleSprite(void);
s32 dds3KillProcessName(char *name, s32 shutdowntimer);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void dds3TitleInit(s32 mode);
void dlcMsgInit(void);
void dlcMsgLast(void);
s8 fclChkMessage(void);
s8 fclDestroyMessage(void);
s8 fclEndMessage(void);
s8 fclInitMessage(void *pData);
void fclSetMessageInvalid(s8 Mode);
s8 fclStartMessage(s32 MsgNo);
void fclUpdateMessage(void);
void fldAutoMapDelete(void);
void fldPlayerDelete(void);
s32 frame(void);
s32 movieCheckEnd(void);
s32 moviePlay(s32 aNum, s32 Layer);
void movieStop(void);
s32 p2sdFadeOut(s32 a);
s32 p2sdPlayBGM(s32 a);
s32 p2sdPlaySE(s32 a);
void rsetAlpha(s32 mode);
void rsetOtOfs(s32 otofs);
void rsetTest(s32 ate, s32 atst, s32 aref, s32 afail, s32 date, s32 datm, s32 zte, s32 ztst);
f32 sdfSin(f32 aRadius);
void sdfTexFree(sdfTexHandle_t *aHandle);
void slDLCMsgKill(void);
void *slDLCMsgProc(void);
s32 slGetInfo(void);
bool slSuspendDataCheck(void);
bool titleDLCMsgCheck(void);
bool titleDLCMsgDraw(void);
void titleMovePlayCheck(void);

// 0x10000f0
void ClearA_logoUI(void) {
  UnityEngine_Object_o *oA_logo_UI;
  UnityEngine_Object_o *v6;

  if (op_Inequality(oA_logo_UI, 0, 0))
  {
    v6 = oA_logo_UI;
    Destroy_27360000(v6);
    oA_logo_UI = 0;
  }
}

// 0x10001f0
void ClearD_logoUI(void) {
  UnityEngine_Object_o *oD_logo_UI;
  UnityEngine_Object_o *v6;

  if (op_Inequality(oD_logo_UI, 0, 0))
  {
    v6 = oD_logo_UI;
    Destroy_27360000(v6);
    oD_logo_UI = 0;
  }
}

// 0xfffff0
void ClearMainmenuUI(void) {
  UnityEngine_Object_o *oMainmenu_UI;
  UnityEngine_Object_o *v6;

  if (op_Inequality(oMainmenu_UI, 0, 0))
  {
    v6 = oMainmenu_UI;
    Destroy_27360000(v6);
    oMainmenu_UI = 0;
  }
}

// 0xffaa00
void *GetMainMenuUI(void) {
  return oMainmenu_UI;
}

// 0xffff10
void *GetoA_logoUI(void) {
  return oA_logo_UI;
}

// 0xffff80
void *GetoD_logoUI(void) {
  return oD_logo_UI;
}

// 0xff6a90
void dds3CheckPadInput(void) {
    DDS3_PADCHECK_REP(0);
    slSuspendDataCheck();
    dds3CheckDLC2();
    p2sdPlaySE(0);
}

// 0xff70b0
void dds3CheckPadInput2(void) {
  struct titleGlobal_o *gGlobal;
  s32 pos;
  s32 v7;
  struct titleGlobal_o *v12;
  s32 v13;
  s32 v14;

  else  --gGlobal->pos;
  p2sdPlaySE(0);
  pos = gGlobal->pos;
  if (pos > 1)
  {
    if (pos != 4)
    v7 = 3;
  }
  else
  {
    v7 = 6;
  }
  gGlobal->pos = v7;
  titileMainCursorflag = 0;
  else if (!DDS3_PADCHECK_REP(7))
  {
    return;
  }
  ++gGlobal->pos;
  p2sdPlaySE(0);
  v12 = gGlobal;
  v13 = v12->pos;
  if (v13 == 4)
  {
    v14 = 5;
  }
  else
  {
    if (v13 < 7)
    v14 = 2;
  }
  v12->pos = v14;
  titileMainCursorflag = 0;
}

// 0xffb6c0
void dds3DestroyTitleSprite(void) {
  sdfTexHandle_t_o *LogoSpriteHandle;
  sdfTexHandle_t_o *TlogoSpriteHandle;
  sdfTexHandle_t_o *PressSpriteHandle;
  sdfTexHandle_t_o *Win1SpriteHandle;
  sdfTexHandle_t_o *Win1BSpriteHandle;

  LogoSpriteHandle = gGlobal->LogoSpriteHandle;
  if (LogoSpriteHandle)
  {
    sdfTexFree(LogoSpriteHandle);
    gGlobal->LogoSpriteHandle = 0;
  }
  TlogoSpriteHandle = gGlobal->TlogoSpriteHandle;
  if (TlogoSpriteHandle)
  {
    sdfTexFree(TlogoSpriteHandle);
    gGlobal->TlogoSpriteHandle = 0;
  }
  PressSpriteHandle = gGlobal->PressSpriteHandle;
  if (PressSpriteHandle)
  {
    sdfTexFree(PressSpriteHandle);
    gGlobal->PressSpriteHandle = 0;
  }
  Win1SpriteHandle = gGlobal->Win1SpriteHandle;
  if (Win1SpriteHandle)
  {
    sdfTexFree(Win1SpriteHandle);
    gGlobal->Win1SpriteHandle = 0;
  }
  Win1BSpriteHandle = gGlobal->Win1BSpriteHandle;
  if (Win1BSpriteHandle)
  {
    sdfTexFree(Win1BSpriteHandle);
    gGlobal->Win1BSpriteHandle = 0;
  }
}

// 0xffaa70
void dds3DrawLogoSprite(void) {
    rsetAlpha(0);
    aDrawBoxG(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

// 0xff73a0
void dds3DrawMenuString(void) {
    rsetOtOfs(0);
    rsetAlpha(0);
    rsetTest(0, 0, 0, 0, 0, 0, 0, 0);
    aDrawBoxG(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    sdfSin(0);
    slSuspendDataCheck();
    GetLocalizeText(0);
    RepColTag(0, 0);
    dds3CheckDLC2();
}

// 0xffaf50
void dds3DrawNameSprite(void) {
    rsetOtOfs(0);
    rsetAlpha(0);
    rsetTest(0, 0, 0, 0, 0, 0, 0, 0);
    sdfSin(0);
    dds3DrawLogoSprite();
}

// 0xffb5f0
void dds3InitTitleSprite(void) {
  u64 *v3;
  u64 *v4;

  gGlobal->LogoSpriteHandle = 0;
  gGlobal->TlogoSpriteHandle = 0;
  gGlobal->PressSpriteHandle = 0;
  gGlobal->Win1SpriteHandle = 0;
  gGlobal->Win1BSpriteHandle = 0;
  v3 = Allocate(pacFileHandle_t);
  pacFileHandle_t___ctor(v3);
  v4 = Allocate(sdfPacDecodeResrc_t);
  sdfPacDecodeResrc_t___ctor(v4);
}

// 0xffae50
void dds3LogoStart(void) {
  gGlobal->LogoCnt = 0;
  gGlobal->pressFadeinCnt = 0;
}

// 0xffaed0
void dds3LogoStart2(void) {
  gGlobal->LogoCnt = 192;
  gGlobal->pressFadeinCnt = 50;
}

// 0x1000470
s32 dds3Title(void) {
  dds3TitleInit(0);
  return 0;
}

// 0xffbf70
void dds3TitleDestroy(dds3ProcessID_t **id) {
    dds3DestroyTitleSprite();
    movieStop();
}

// 0xffb9b0
void dds3TitleInit(s32 mode) {
  u64 *v3;
  dds3TitleMain_c *v8;
  struct dds3TitleMain_StaticFields *static_fields;
  struct dds3TitleMain_StaticFields *v10;
  u64 *v15;
  AssetBundleCtrl_o *asset_bc;
  Il2CppObject *Prefab_16624656;
  UnityEngine_GameObject_o *v20;
  UnityEngine_Transform_o *transform;
  Il2CppObject *v24;
  AssetBundleCtrl_o *v26;
  Il2CppObject *v27;
  UnityEngine_GameObject_o *v28;
  UnityEngine_Transform_o *v29;
  Il2CppObject *v30;
  AssetBundleCtrl_o *v32;
  Il2CppObject *v33;
  UnityEngine_GameObject_o *v34;
  UnityEngine_Transform_o *v35;
  u64 *v36;

  v3 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v3);
  FilterDelete();
  v6[2].klass->vtable[4].method->token = 0;
  *&v6[2].klass->vtable[4].method->flags = 0;
  *&v6[2].klass->vtable[4].method->slot = 0;
  LODWORD(v6[2].klass->vtable[4].method[1].invoker_method) = 0;
  HIDWORD(v6[2].klass->vtable[4].method[1].invoker_method) = -1;
  LODWORD(v6[2].klass->vtable[4].method[1].name) = 0;
  HIDWORD(v6[2].klass->vtable[4].method[1].name) = 0;
  HIDWORD(v6[2].klass->vtable[4].method[1].methodPointer) = 0;
  dds3InitTitleSprite();
  MovieSkipflag = 1;
  static_fields = v8->static_fields;
  if (static_fields->titleStartInitflag)
  {
    static_fields->titleStartInitflag = 0;
  }
  else
  {
    v10 = v8->static_fields;
    if (v10->title2mode != 1)
  }
  v10->gGlobal->pos = 2;
  if (mode)
  {
    if (mode == 3)
    {
      gGlobal->pos = 2;
      title2flag = 1;
      title2mode = 1;
    }
    else if (mode == 2)
    {
      gGlobal->pos = 0;
    }
    p2sdFadeOut(3801088);
    dds3FadeIn2(0xFu);
    movieStop();
    gGlobal->bgalp = 128;
    gGlobal->cnt = 0;
    gGlobal->pressFadeinCnt = 0;
    gGlobal->step = 22;
  }
  dds3BackColor = 0x80000000;
  v15 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v15,
    0,
    Method_dds3TitleMain_dds3Titlemain__);
  dds3StartProcess(StringLiteral_14979, 0x2B19u, 0, 0, v15, 0, 0, 0, 0, 0);
  asset_bc = get_asset_bc();
  Prefab_16624656 = LoadPrefab_16624656(asset_bc, StringLiteral_4611, StringLiteral_5156, StringLiteral_5157);
  v20 = Find(StringLiteral_4905, 0);
  transform = get_transform(v20, 0);
  v24 = Instantiate_object__425664(Prefab_16624656, transform, 0);
  oMainmenu_UI = v24;
  AddComponent_object_(oMainmenu_UI);
  v26 = get_asset_bc();
  v27 = LoadPrefab_16624656(v26, StringLiteral_14720, StringLiteral_14980, StringLiteral_14981);
  v28 = Find(StringLiteral_4905, 0);
  v29 = get_transform(v28, 0);
  v30 = Instantiate_object__425664(v27, v29, 0);
  oA_logo_UI = v30;
  AddComponent_object_(oA_logo_UI);
  v32 = get_asset_bc();
  v33 = LoadPrefab_16624656(v32, StringLiteral_14720, StringLiteral_14980, StringLiteral_14982);
  v34 = Find(StringLiteral_4905, 0);
  v35 = get_transform(v34, 0);
  oD_logo_UI = Instantiate_object__425664(v33, v35, 0);
  v36 = Allocate(sdfMovieCb_t);
  sdfMovieCb_t___ctor(v36);
  dds3MovieCb = v36;
}

// 0xffc010
dds3ProcessFunc_t *dds3Titlemain(dds3ProcessID_t *id) {
    aDrawBoxG(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    dds3FadeIn(0, 0, 0, 0);
    dds3FadeCheck();
    movieStop();
    DDS3_PADCHECK_PRESS(0);
    dds3FadeOut(0, 0, 0, 0);
    dds3CheckDLC2();
    moviePlay(0, 0);
    frame();
    movieCheckEnd();
    dds3DrawNameSprite();
    p2sdPlaySE(0);
    slSuspendDataCheck();
    dds3FadeIn2(0);
    titleMovePlayCheck();
    ButtonGuideDispSet(0, 0, 0, 0);
    dds3CheckPadInput2();
    dds3CheckPadInput();
    dds3DrawMenuString();
    DDS3_PADCHECK_TRIG(0);
    ButtonGuideDispOff();
    dds3AdminiCallSequence(0, 0, 0, 0);
    ClearMainmenuUI();
    ClearA_logoUI();
    ClearD_logoUI();
    FindId(0, 0);
    p2sdPlayBGM(0);
    fldAutoMapDelete();
    fldPlayerDelete();
    titleDLCMsgCheck();
    dlcMsgInit();
    titleDLCMsgDraw();
    slDLCMsgProc();
    slGetInfo();
    slDLCMsgKill();
    dlcMsgLast();
    return 0;
}

// 0xff5be0
void dlcMsgInit(void) {
  System_String_o *PlatformStr;
  System_String_o *v3;
  System_String_o *v4;
  System_String_o *v5;
  Il2CppObject *p_obj;

  LoadLocalizeText(StringLiteral_4611, StringLiteral_14974);
  PlatformStr = GetPlatformStr();
  v3 = Concat_5224608(StringLiteral_4611, PlatformStr);
  v4 = GetPlatformStr();
  v5 = Concat_5224608(StringLiteral_14974, v4);
  LoadLocalizeText(v3, v5);
  p_obj = &dlcMesData->obj;
  fclInitMessage(p_obj);
}

// 0xff5d00
void dlcMsgLast(void) {
  System_String_o *PlatformStr;
  System_String_o *v4;

  fclEndMessage();
  fclDestroyMessage();
  Remove(StringLiteral_14974, 0);
  PlatformStr = GetPlatformStr();
  v4 = Concat_5224608(StringLiteral_14974, PlatformStr);
  Remove(v4, 0);
}

// 0xff5bd0
void *pacGetResrc(void *a) {
  return 0;
}

// 0xff5dc0
bool titleDLCMsgCheck(void) {
    dds3CheckDLC1();
    dds3CheckDLC2();
    dds3CheckDLC6();
    dds3CheckDLC7();
    dds3CheckDLC3();
    dds3CheckDLC4();
    dds3CheckDLC5();
    dds3CheckDLC8();
    return 0;
}

// 0xff63e0
bool titleDLCMsgDraw(void) {
  struct System_SByte_array *dlcflg;
  s8 *m_Items;
  struct System_SByte_array *v8;
  struct System_SByte_array *v11;
  struct System_SByte_array *v14;
  struct System_SByte_array *v17;
  struct System_SByte_array *v20;
  struct System_SByte_array *v23;
  struct System_SByte_array *v26;

  switch (dlcMsgNum)
  {
    case 1:
      fclSetMessageInvalid(1);
      fclStartMessage(0);
      dlcflg = SystemWork->dlcflg;
      m_Items = dlcflg->m_Items;
    case 2:
      fclSetMessageInvalid(1);
      fclStartMessage(1);
      v8 = SystemWork->dlcflg;
      m_Items = &v8->m_Items[1];
    case 3:
      fclSetMessageInvalid(1);
      fclStartMessage(2);
      v11 = SystemWork->dlcflg;
      m_Items = &v11->m_Items[5];
    case 4:
      fclSetMessageInvalid(1);
      fclStartMessage(3);
      v14 = SystemWork->dlcflg;
      m_Items = &v14->m_Items[6];
    case 5:
      fclSetMessageInvalid(1);
      fclStartMessage(4);
      v17 = SystemWork->dlcflg;
      m_Items = &v17->m_Items[2];
    case 6:
      fclSetMessageInvalid(1);
      fclStartMessage(5);
      v20 = SystemWork->dlcflg;
      m_Items = &v20->m_Items[3];
    case 7:
      fclSetMessageInvalid(1);
      fclStartMessage(6);
      v23 = SystemWork->dlcflg;
      m_Items = &v23->m_Items[4];
    case 8:
      fclSetMessageInvalid(1);
      fclStartMessage(7);
      v26 = SystemWork->dlcflg;
      m_Items = &v26->m_Items[7];
      *m_Items = 1;
      break;
    default:
      break;
  }
  dlcMsgSave = 1;
  dlcMsgNum = 0;
  fclUpdateMessage();
  return fclChkMessage() == 0;
}

// 0xff6940
void titleMovePlayCheck(void) {
  struct titleGlobal_o *gGlobal;

  if (gGlobal->loopflg == 1)
  {
    gGlobal->loopflg = 0;
    moviePlay(13, -1);
  }
  else
  {
    if (movieCheckEnd())
    {
      movieStop();
      gGlobal->loopflg = 1;
    }
  }
}

// 0x1000360
s32 titleShutDown(void) {
  dds3DestroyTitleSprite();
  movieStop();
  dds3KillProcessName(StringLiteral_14979, 1);
  return 0;
}

// 0x10002f0
s32 titleStart(s32 mode) {
  dds3TitleInit(mode);
  return -1;
}
