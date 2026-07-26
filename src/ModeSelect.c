#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct AssetBundles AssetBundles;
typedef struct _FRQ _FRQ;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct fclencyceelem_t fclencyceelem_t;
typedef struct mselGlobal mselGlobal;
typedef struct pacFileHandle_t pacFileHandle_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

static s32 msel_msg_hiki;
static s32 msel_msg_hiki2;
static s32 msel_msg_hiki2_sel;
static s32 msel_msg_hiki3;
static s32 msel_msg_hiki4;
static s32 msel_msg_hiki4_sel;
static s32 msel_msg_hiki5;
static s32 F061_SMG;
static s32 F061_01;
static s32 modeCursurCnt;
static s32 modeSelectTextIdxCnt;
static s32 modeSelectChoiceflag;
static s32 modeSelectEndflag;
static s32 modeSelectChoice;
static s32 DLCFlag;
static s32 ModeSelectFlag;
static s32 ModeCursurMoveflag;
static s32 ButtonGuideDrawflag;
static s32 DLCMenuCnt;
static char *gMode00_00[2];
static char *gMode00_01[2];
static char *Choicedec;
static char *Choicestr[2];
static char *ChoiceDLCstr[2];
static char *ChoicestrRcl[2];
static char *ChoiceDLCstrRcl[2];
static s32 LapChoiceflag;
static s32 LapChoiceInit;
static s32 mainMenuCnt;
static s32 mainMenuPos;
static char *mainMenu_str;
static void *mainMenu;
static void *mainMenuTM;
static s32 BGMLoadflag;
static char Lclstr[UNKNOWN_ARRAY_SIZE];
static char Lclstr_a[UNKNOWN_ARRAY_SIZE];
static char *delstr[1];
static char *modeSelectLcl[3];
static char *modeSelectTextL[3];
static char *modeSelectM[3];
static char *modeSelectM_[3];
static char *modeSelectText[3];
static char *enddec;
static void *ModeObj;
static void *modeobj;
static char *modeCursur_str;
static void *modeCursur;
static void *modeCursur_anim;
static char *modeSelectTextIdx_str;
static void *modeSelectTextIdx;
static void *modeSelectTM;
static char *modeSelectTextMenu_str;
static void *modeSelectTextMenu;
static void *modeSelectMenuTM;
static void *modeSelectChoiceText;
static void *modeSelectChoiceAnswer;
static void *modeSelectChoiceAnswerStr;
static void *modeSelectChoiceAnswerStrTM;
static void *modeSelectChoiceAnswer_anim;
static void *mode_endcursorNo;
static void *mode_endcursorNoText;
static void *mode_endcursorNoTM;
static void *mode_endcursorYes;
static void *mode_endcursorYesText;
static void *mode_endcursorYesTM;
static mselGlobal *gGlobal;
static s32 gGemeMode;
static void *oModeselect_UI;
static void *Modeselectobj;

void ButtonGuideDispOff(void);
void ButtonGuideDispSet(char *name, bool timer, bool empty, s32 waitTimer);
void ClearMainmenuUI(void);
void ClearModeselectUI(void);
char *DAT_STR_REF_DVNAME(s32 idx);
bool DDS3_PADCHECK_REP(s32 id);
bool DDS3_PADCHECK_TRIG(s32 id);
void FilterDelete(void);
s32 FindId(s32 type, char *name);
char *GetLocalizeText(char *ID);
bool IsLoad(AssetBundles *this, char *key);
void Load(char *key, char *filePath);
void LoadKeys(s32 type, char *key, char *path);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
void RemoveKeys(s32 type, char *key);
char *RepColTag(char *txt, void **LegacyParamArray);
void UnloadAB(AssetBundleCtrl *this, char *key);
void UpdateAudioVolume(s32 type);
void __Msel_DrawSelectDevil(s32 **buffer, u32 fcol, u32 fcol_n);
void __Msel_TOverData_Clear(void);
void __Msel_TOverData_Copy(void);
void __Msel_bufferShift(u32 **buff1, u32 **buff2, u32 loop, u32 loopmax, s8 flg);
void dds3AdminiCallSequence(s32 sequence, void *data, s32 datasize, s32 restore);
bool dds3CheckDLC1(void);
bool dds3CheckDLC2(void);
void dds3CreateGameData(s32 no);
s32 dds3FadeCheck(void);
void dds3FadeIn(u32 r, u32 g, u32 b, u32 frame);
void dds3FadeOut(u32 r, u32 g, u32 b, u32 frame);
u32 dds3GetRandIntA(u32 aLimit, char *name);
void dds3GlobalWorkUserInit2(s32 mode);
s32 dds3KillProcessName(char *name, s32 shutdowntimer);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void eglLinkAlpha(s32 mode);
void eglLinkSprite(s32 x, s32 y, s32 w, s32 h, s32 u, s32 v, s32 uw, s32 vh, s32 rgba0, s32 rgba1, s32 rgba2, s32 rgba3, sdfTexHandle_t *th);
void eglLinkTest(s32 ate, s32 atst, s32 aref, s32 afail, s32 date, s32 datm, s32 zte, s32 ztst);
void eglSetOt(s32 ot);
void evtBitOff(s32 no);
void evtBitOn(s32 no);
s8 fclChkMessage(void);
s8 fclChkSelMessage(void);
s8 fclDestroyMessage(void);
s32 fclEncycRegist2(fclencyceelem_t *pelemsrc, s32 overwrite);
s8 fclEndMessage(void);
s8 fclGetSelMessagePos(void);
sdfTexHandle_t *fclLoadTexture(char *pFileName);
void fclSetSelMessagePos(s8 SelPos);
s8 fclStartMessage(s32 MsgNo);
s8 fclStartSelMessage(s32 SelMsgNo);
void fclUpdateMessage(void);
void fldProcNext(s32 fld, s32 eveno);
void fmProcTrigSequence(s32 mode, bool callDebug);
s32 fmProcessChk(void);
_FRQ *frDestroyFontRequestAfter(_FRQ *pFRQ);
s32 frDrawFontEx(_FRQ *pFRQ, s8 Mode);
_FRQ *frwGetSmallFontFRQ_20602048(s32 X, s32 Y, s32 Pri, u32 Col, char *pStr, _FRQ *pFRQ, s32 ftype);
_FRQ *frwGetSmallNumFontFRQ_20603536(s32 X, s32 Y, s32 Pri, u32 Color, char *pStr, _FRQ *pFRQ);
void modeSelectDLCPad(void);
void mselCheckPadInput(void);
void mselDestroySprite(void);
void mselDevilChoice(void);
void mselDrawDevilSelect(u32 flg);
void mselDrawHikitugisimasuka(void);
void mselDrawModeString(void);
void mselInit(s32 mode);
void mselStartDataSet(void);
void mselStartGame(void);
s32 p2sdFadeOut(s32 a);
s32 p2sdPlayBGM(s32 a);
s32 p2sdPlaySE(s32 a);
void rsetAlpha(s32 mode);
void rsetOtOfs(s32 otofs);
void rsetTest(s32 ate, s32 atst, s32 aref, s32 afail, s32 date, s32 datm, s32 zte, s32 ztst);
sdfMemHandle_t *sdfDevLoadFile(char *aFilename, void *aTopPtr, s32 aSizePtr);
void *sdfMemGetPtr(sdfMemHandle_t *aHandle);
void sdfTexFreeDelayed(sdfTexHandle_t *aHandle);
s32 slGetExitMode(void);

// 0x129cdc0
void ClearModeselectUI(void) {
  UnityEngine_Object_o *Modeselectobj;
  UnityEngine_Object_o *oModeselect_UI;

  if (op_Inequality(Modeselectobj, 0, 0))
  {
    Destroy_27360000(oModeselect_UI);
    Modeselectobj = 0;
  }
}

// 0x1296670
void *GetModeSelectUI(void) {
  return oModeselect_UI;
}

// 0x1295920
void __Msel_DrawSelectDevil(s32 **buffer, u32 fcol, u32 fcol_n) {
    sdfMemGetPtr(0);
    DAT_STR_REF_DVNAME(0);
    frwGetSmallFontFRQ_20602048(0, 0, 0, 0, 0, 0, 0);
    frDrawFontEx(0, 0);
    frDestroyFontRequestAfter(0);
    frwGetSmallNumFontFRQ_20603536(0, 0, 0, 0, 0, 0);
}

// 0x1295f40
void __Msel_DrawSelectDevil_Color(u8 cnt, u32 rgba, s8 flg) {
  ;
}

// 0x1295070
void __Msel_TOverData_Clear(void) {
  struct System_Int32_array *ZensyoSelect;
  struct System_Int32_array *v5;
  struct System_Int32_array *v7;
  struct System_Int32_array *v9;
  struct System_Int32_array *v11;

  ZensyoSelect = gGlobal->ZensyoSelect;
  ZensyoSelect->m_Items[0] = -1;
  v5 = gGlobal->ZensyoSelect;
  v5->m_Items[1] = -1;
  v7 = gGlobal->ZensyoSelect;
  v7->m_Items[2] = -1;
  v9 = gGlobal->ZensyoSelect;
  v9->m_Items[3] = -1;
  v11 = gGlobal->ZensyoSelect;
  v11->m_Items[4] = -1;
  gGlobal->ZensyoNum = 0;
  Write(StringLiteral_5132, 0);
}

// 0x12952b0
void __Msel_TOverData_Copy(void) {
  struct mselGlobal_o *gGlobal;
  struct System_Int32_array *ZensyoSelect;
  struct System_Int32_array *ZBSelect;
  s32 v6;
  struct mselGlobal_o *v10;
  struct System_Int32_array *v11;
  struct System_Int32_array *v12;
  s32 v13;
  struct mselGlobal_o *v17;
  struct System_Int32_array *v18;
  struct System_Int32_array *v19;
  s32 v20;
  struct mselGlobal_o *v24;
  struct System_Int32_array *v25;
  struct System_Int32_array *v26;
  s32 v27;
  struct mselGlobal_o *v31;
  struct System_Int32_array *v32;
  struct System_Int32_array *v33;
  s32 v34;
  ModeSelect_c *v35;
  struct ModeSelect_StaticFields **p_static_fields;
  struct mselGlobal_o *v39;

  ZensyoSelect = gGlobal->ZensyoSelect;
  ZBSelect = gGlobal->ZBSelect;
  v6 = ZensyoSelect->m_Items[0];
  ZBSelect->m_Items[0] = v6;
  v10 = gGlobal;
  v11 = v10->ZensyoSelect;
  v12 = v10->ZBSelect;
  v13 = v11->m_Items[1];
  v12->m_Items[1] = v13;
  v17 = gGlobal;
  v18 = v17->ZensyoSelect;
  v19 = v17->ZBSelect;
  v20 = v18->m_Items[2];
  v19->m_Items[2] = v20;
  v24 = gGlobal;
  v25 = v24->ZensyoSelect;
  v26 = v24->ZBSelect;
  v27 = v25->m_Items[3];
  v26->m_Items[3] = v27;
  v31 = gGlobal;
  v32 = v31->ZensyoSelect;
  v33 = v31->ZBSelect;
  v34 = v32->m_Items[4];
  v33->m_Items[4] = v34;
  p_static_fields = &v35->static_fields;
  gGlobal->ZBNum = gGlobal->ZensyoNum;
  v39 = gGlobal;
  if (v39->ZBNum)
  {
    v39->ZB_RGBA = 1684113280;
    (*p_static_fields)->gGlobal->ZBalpha_cnt = 0;
  }
}

// 0x1295640
void __Msel_bufferShift(u32 **buff1, u32 **buff2, u32 loop, u32 loopmax, s8 flg) {
  s64 v6;
  char *v7;
  s64 v8;
  s64 v9;
  u32 v10;
  u32 max_length;
  u32 v14;
  u32 v17;
  u32 v18;
  u32 v19;
  s64 v20;
  u32 v23;
  u64 v26;
  u64 max_length_low;
  u32 v30;
  u32 v31;
  u32 v32;
  char *v36;

  if (flg)
  {
    if (loop < loopmax)
    {
      if (buff1)
      {
        v6 = 4LL * loop + 28;
        v7 = buff1 + v6;
        v8 = 4LL * loop + 32;
        v9 = 0;
        v10 = loop - 1;
        v36 = buff2 + v6;
        do
        {
          max_length = buff1->max_length;
          *&v7[4 * v9] = *(&buff1->obj.klass + 4 * v9 + v8);
          if (buff2)
          {
            v14 = buff2->max_length;
            *&v36[4 * v9] = *(&buff2->obj.klass + 4 * v9 + v8);
          }
          ++v9;
        }
        while (loop + v9 < loopmax);
      }
      else
      {
        v26 = loop;
        do
        {
          if (buff2)
          {
            max_length_low = LODWORD(buff2->max_length);
            buff2->m_Items[v26 - 1] = buff2->m_Items[v26];
          }
          ++v26;
        }
        while (loopmax != v26);
      }
    }
  }
  else if (loopmax - 1 >= loop)
  {
    if (buff1)
    {
      v17 = loopmax - 2;
      do
      {
        v18 = buff1->max_length;
        v19 = v17 + 1;
        v20 = v17;
        buff1->m_Items[v19] = buff1->m_Items[v17];
        if (buff2)
        {
          v23 = buff2->max_length;
          buff2->m_Items[v19] = buff2->m_Items[v20];
        }
        v17 = v20 - 1;
      }
      while (v20 >= loop);
    }
    else
    {
      v30 = loopmax - 2;
      do
      {
        if (buff2)
        {
          v31 = buff2->max_length;
          v32 = v30 + 1;
          buff2->m_Items[v32] = buff2->m_Items[v30];
        }
      }
      while (v30-- >= loop);
    }
  }
}

// 0x129d890
void modeSelectDLC(s32 mode) {
  ;
}

// 0x129cec0
void modeSelectDLCDraw(void) {
  ;
}

// 0x129d8a0
void modeSelectDLCInit(void) {
    GetLocalizeText(0);
    RepColTag(0, 0);
}

// 0x129ced0
void modeSelectDLCPad(void) {
    RepColTag(0, 0);
    DDS3_PADCHECK_REP(0);
    p2sdPlaySE(0);
}

// 0x1295f50
void mselCheckPadInput(void) {
    DDS3_PADCHECK_REP(0);
    p2sdPlaySE(0);
    dds3CheckDLC1();
}

// 0x129a2c0
void mselDestroy(dds3ProcessID_t *id) {
  mselDestroySprite();
  fclDestroyMessage();
  gGlobal = 0;
}

// 0x1299b40
void mselDestroySprite(void) {
  sdfTexHandle_t_o *BgSpriteHandle;
  sdfTexHandle_t_o *AttSpriteHandle;
  sdfTexHandle_t_o *SelSpriteHandle;

  BgSpriteHandle = gGlobal->BgSpriteHandle;
  if (BgSpriteHandle)
  {
    sdfTexFreeDelayed(BgSpriteHandle);
    gGlobal->BgSpriteHandle = 0;
  }
  AttSpriteHandle = gGlobal->AttSpriteHandle;
  if (AttSpriteHandle)
  {
    sdfTexFreeDelayed(AttSpriteHandle);
    gGlobal->AttSpriteHandle = 0;
  }
  SelSpriteHandle = gGlobal->SelSpriteHandle;
  if (SelSpriteHandle)
  {
    sdfTexFreeDelayed(SelSpriteHandle);
    gGlobal->SelSpriteHandle = 0;
  }
}

// 0x12990d0
void mselDevilChoice(void) {
    sdfMemGetPtr(0);
    __Msel_bufferShift(0, 0, 0, 0, 0);
    __Msel_TOverData_Copy();
    __Msel_TOverData_Clear();
    dds3GetRandIntA(0, 0);
}

// 0x1298e00
void mselDrawDevilSelect(u32 flg) {
  s32 v4;
  s32 rgba1;
  s32 rgba2;
  s32 rgba3;
  ModeSelect_c *v12;
  struct mselGlobal_o *gGlobal;
  u32 ZNalpha_cnt;

  eglSetOt(71);
  eglLinkTest(1, 0, 128, 3, 0, 0, 1, 1);
  eglLinkAlpha(0);
  v4 = ToInt32_2965280(0x80808080);
  rgba1 = ToInt32_2965280(0x80808080);
  rgba2 = ToInt32_2965280(0x80808080);
  rgba3 = ToInt32_2965280(0x80808080);
  eglLinkSprite(0, 0, 512, 448, 0, 0, 512, 448, v4, rgba1, rgba2, rgba3, gGlobal->SelSpriteHandle);
  if (flg)
  {
    ZNalpha_cnt = gGlobal->ZNalpha_cnt;
    if (!ZNalpha_cnt)
    else if (ZNalpha_cnt <= 0xB3)
    {
      gGlobal->ZNalpha_cnt = ZNalpha_cnt;
      if ((v12->_2.bitflags2 & 2) == 0)
      __Msel_DrawSelectDevil(gGlobal->ZensyoSelect, gGlobal->Z_RGBA, gGlobal->Z_RGBA & 0xFFFFFF00 | gGlobal->ZN_RGBA);
    }
    ZNalpha_cnt = 180;
  }
  __Msel_DrawSelectDevil(gGlobal->ZensyoSelect, gGlobal->Z_RGBA, gGlobal->Z_RGBA);
  {
  }
  __Msel_DrawSelectDevil(gGlobal->ZBSelect, gGlobal->ZB_RGBA, gGlobal->ZB_RGBA);
}

// 0x1298d60
void mselDrawHikitugisimasuka(void) {
  eglSetOt(71);
  eglLinkTest(1, 0, 128, 3, 0, 0, 1, 1);
  eglLinkAlpha(0);
}

// 0x12966e0
void mselDrawModeString(void) {
    eglSetOt(0);
    eglLinkTest(0, 0, 0, 0, 0, 0, 0, 0);
    eglLinkAlpha(0);
    dds3CheckDLC1();
    GetLocalizeText(0);
    RepColTag(0, 0);
    DDS3_PADCHECK_REP(0);
    p2sdPlaySE(0);
    DDS3_PADCHECK_TRIG(0);
}

// 0x129e0f0
s32 mselGemeMode(void) {
  return gGemeMode;
}

// 0x1299d20
void mselInit(s32 mode) {
  u64 *v3;
  u64 *v4;
  u64 *v5;
  struct System_Int32_array *ZensyoSelect;
  struct System_Int32_array *v10;
  struct System_Int32_array *v12;
  struct System_Int32_array *v14;
  struct System_Int32_array *v16;
  struct mselGlobal_o *gGlobal;
  u64 *v19;
  struct mselGlobal_o *v20;
  u64 *v21;
  struct mselGlobal_o *v22;
  AssetBundleCtrl_o *asset_bc;
  AssetBundleCtrl_o *v27;
  AssetBundleCtrl_o *v28;
  UnityEngine_GameObject_o *Prefab_16624656;
  Il2CppObject *Modeselectobj;
  UnityEngine_GameObject_o *v33;
  UnityEngine_Transform_o *transform;
  Il2CppObject *v36;
  u64 *v38;

  v3 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v3);
  v4 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v4);
  v5 = Allocate(mselGlobal);
  _ctor(v5, 0);
  gGlobal = v5;
  gGlobal->step = 0;
  gGlobal->cnt = 0;
  gGlobal->ModePos = 1;
  modeCursurCnt = 2;
  ZensyoSelect = gGlobal->ZensyoSelect;
  ZensyoSelect->m_Items[0] = -1;
  v10 = gGlobal->ZensyoSelect;
  v10->m_Items[1] = -1;
  v12 = gGlobal->ZensyoSelect;
  v12->m_Items[2] = -1;
  v14 = gGlobal->ZensyoSelect;
  v14->m_Items[3] = -1;
  v16 = gGlobal->ZensyoSelect;
  v16->m_Items[4] = -1;
  gGlobal->ZensyoNum = 0;
  gGlobal->mode = mode;
  LapChoiceInit = 0;
  FilterDelete();
  v19 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v19);
  gGlobal->mh_gbwk = v19;
  v20 = gGlobal;
  v21 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v21);
  v20->mh_zen = v21;
  v22 = gGlobal;
  v22->MessageMH = sdfDevLoadFile(StringLiteral_5153, &v22->pMessage, 0);
  dds3BackColor = 0x80000000;
  asset_bc = get_asset_bc();
  if (!IsLoad(asset_bc, StringLiteral_5154))
  {
    v27 = get_asset_bc();
    Load(v27, StringLiteral_5154, StringLiteral_5155, 0);
  }
  v28 = get_asset_bc();
  Prefab_16624656 = LoadPrefab_16624656(v28, StringLiteral_4611, StringLiteral_5156, StringLiteral_5157);
  Modeselectobj = Prefab_16624656;
  v33 = Find(StringLiteral_4905, 0);
  transform = get_transform(v33, 0);
  v36 = Instantiate_object__425664(Modeselectobj, transform, 0);
  oModeselect_UI = v36;
  AddComponent_object_(oModeselect_UI);
  v38 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v38,
    0,
    Method_ModeSelect_mselMain__);
  dds3StartProcess(StringLiteral_5158, 0x2B19u, 0, 0, v38, 0, 0, 0, 0, 0);
}

// 0x1299b30
void mselInitSprite(void) {
  ;
}

// 0x1295dc0
void mselKanjiDraw(s32 x, s32 y, s32 rgba, char *moji) {
  _FRQ_o *SmallFontFRQ_20602048;

  SmallFontFRQ_20602048 = frwGetSmallFontFRQ_20602048(16 * x, 16 * y, 0, rgba, moji, 0, -1);
  frDrawFontEx(SmallFontFRQ_20602048, 1);
  frDestroyFontRequestAfter(SmallFontFRQ_20602048);
}

// 0x129a360
dds3ProcessFunc_t *mselMain(dds3ProcessID_t *id) {
    rsetOtOfs(0);
    rsetAlpha(0);
    rsetTest(0, 0, 0, 0, 0, 0, 0, 0);
    IsLoad(0, 0);
    LoadKeys(0, 0, 0);
    dds3CheckDLC2();
    ButtonGuideDispSet(0, 0, 0, 0);
    FindId(0, 0);
    p2sdPlayBGM(0);
    dds3FadeIn(0, 0, 0, 0);
    mselStartDataSet();
    mselDrawModeString();
    dds3FadeCheck();
    DDS3_PADCHECK_TRIG(0);
    evtBitOn(0);
    evtBitOff(0);
    ButtonGuideDispOff();
    p2sdPlaySE(0);
    mselCheckPadInput();
    dds3FadeOut(0, 0, 0, 0);
    p2sdFadeOut(0);
    __Msel_TOverData_Clear();
    mselDrawHikitugisimasuka();
    fclChkMessage();
    fclEndMessage();
    fclSetSelMessagePos(0);
    fclStartMessage(0);
    fclChkSelMessage();
    fclGetSelMessagePos();
    sdfMemGetPtr(0);
    fmProcessChk();
    slGetExitMode();
    mselDevilChoice();
    mselDrawDevilSelect(0);
    fclStartSelMessage(0);
    fclUpdateMessage();
    fclEncycRegist2(0, 0);
    sdfTexFreeDelayed(0);
    fclLoadTexture(0);
    ClearModeselectUI();
    ClearMainmenuUI();
    mselStartGame();
    RemoveKeys(0, 0);
    UnloadAB(0, 0);
    fmProcTrigSequence(0, 0);
    dds3AdminiCallSequence(0, 0, 0, 0);
    modeSelectDLCPad();
    return 0;
}

// 0x1295e80
void mselNumDraw(s32 x, s32 y, s32 rgba, char **numstr) {
  _FRQ_o *SmallNumFontFRQ_20603536;

  SmallNumFontFRQ_20603536 = frwGetSmallNumFontFRQ_20603536(16 * x, 16 * y, 0, rgba, *numstr, 0);
  frDrawFontEx(SmallNumFontFRQ_20603536, 1);
  frDestroyFontRequestAfter(SmallNumFontFRQ_20603536);
}

// 0x129e070
s32 mselShutDown(void) {
  dds3KillProcessName(StringLiteral_5158, 1);
  return 0;
}

// 0x129e000
s32 mselStart(s32 mode) {
  mselInit(mode);
  return -1;
}

// 0x1294de0
void mselStartDataSet(void) {
  s16 v3;
  s32 v4;
  s32 v5;

  if (!gGlobal->mode)
    dds3CreateGameData(0);
  if ((v3 & 0x200) != 0)
  {
    v4 = v3 & 0x200;
  }
  else
  {
    v4 = 0;
  }
  if (DDS3_GBWK->GameFileInfo->newfile)
  {
    v5 = 1;
  }
  else
  {
    v5 = 0;
  }
  dds3GlobalWorkUserInit2(v5);
  if (cfgChkFlagChange())
  {
    cfgCopyFlagBakToGbl();
  }
  else
  {
    cfgCopyFlagGblToBak();
  }
  UpdateAudioVolume(3);
  evtBitOn(3087);
}

// 0x1294f90
void mselStartGame(void) {
    fldProcNext(0, 0);
    dds3AdminiCallSequence(0, 0, 0, 0);
}

// 0x1294dc0
void pacSync(pacFileHandle_t *pacFileHandle) {
  ;
}

// 0x1294dd0
void *sdfChipAllocZero(s32 aSize) {
  return 0;
}
