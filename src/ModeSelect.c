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
static char *Lclstr;
static char *Lclstr_a;
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
  System_Char_array *v5;
  ModeSelect_c **v7;
  sdfMemHandle_t_o *mh_zen;
  Il2CppObject *Ptr;
  Il2CppObject *v12;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v15;
  s64 *v16;
  u64 v17;
  s32 v18;
  u64 *v19;
  s32 v21;
  Il2CppClass *v22;
  s64 v25;
  s32 v26;
  System_String_o *v28;
  u64 v29;
  _FRQ_o *SmallFontFRQ_20602048;
  System_String_o *v32;
  _FRQ_o *v34;
  u32 v35;
  u64 *v36;
  System_String_o *v38;
  u64 v39;
  _FRQ_o *SmallNumFontFRQ_20603536;
  u64 v44[3];

  v5 = NewSpecific(char, 0x20u);
  CreateString_5280336(0, v5);
  v7 = &ModeSelect;
  mh_zen = gGlobal->mh_zen;
  Ptr = sdfMemGetPtr(mh_zen);
  v12 = Ptr;
  if (Ptr)
  {
    klass = Ptr->klass;
    if (Ptr->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncycRecord_t)
    {
      sub_8FC2C0(klass->_1.element_class, fclEncycRecord_t, v44);
      if ((v44[0] & 1) != 0)
        v15 = v44[2];
      else
        v15 = v44 + 1;
      v16 = sub_8C4940(v15);
    }
  }
  v17 = 0;
  v18 = 832;
  do
  {
    v21 = buffer->m_Items[v17];
    if (v21 != -1)
    {
      v22 = v12[2].klass;
      v25 = *(&v22->_1.byval_arg.data + v21);
      v26 = *(v25 + 16);
      v28 = DAT_STR_REF_DVNAME(v26);
      v29 = *v7;
      if (((*v7)->_2.bitflags2 & 2) != 0 && !*(v29 + 216))
      {
        v19 = v7;
        if ((byte_3F59209 & 1) != 0)
          goto LABEL_35;
      }
      else
      {
        v19 = v7;
        if ((byte_3F59209 & 1) != 0)
        {
LABEL_35:
          SmallFontFRQ_20602048 = frwGetSmallFontFRQ_20602048(2624, v18 - 32, 0, fcol_n, v28, 0, -1);
          frDrawFontEx(SmallFontFRQ_20602048, 1);
          frDestroyFontRequestAfter(SmallFontFRQ_20602048);
          v32 = "Lv";
          v34 = frwGetSmallFontFRQ_20602048(5120, v18 - 32, 0, fcol, v32, 0, -1);
          frDrawFontEx(v34, 1);
          frDestroyFontRequestAfter(v34);
          v35 = *(v25 + 28);
          if (v35 >= 0x63)
            v35 = 99;
          LODWORD(v44[0]) = v35;
          v36 = sub_8D3950(s32, v44);
          v38 = Format("{0,2:D}", v36, 0);
          v39 = *v19;
          v7 = v19;
          if ((*(*v19 + 295) & 2) != 0 && !*(v39 + 216))
          {
            if ((byte_3F5920A & 1) != 0)
            {
LABEL_49:
              SmallNumFontFRQ_20603536 = frwGetSmallNumFontFRQ_20603536(5536, v18, 0, fcol, v38, 0);
              frDrawFontEx(SmallNumFontFRQ_20603536, 1);
              frDestroyFontRequestAfter(SmallNumFontFRQ_20603536);
              goto LABEL_53;
            }
          }
          else if ((byte_3F5920A & 1) != 0)
          {
            goto LABEL_49;
          }
          goto LABEL_49;
        }
      }
      goto LABEL_35;
    }
LABEL_53:
    ++v17;
    v18 += 256;
  }
  while (v17 != 5);
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
  Write("DEBUG_DATA_CLEAR\n", 0);
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
  UnityEngine_GameObject_o *oModeselect_UI;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v5;
  UnityEngine_GameObject_o *gameObject;
  s64 v8;
  ModeSelect_c *v9;
  s32 v10;
  u64 v11;
  u64 *v12;
  System_String_o *v13;
  UnityEngine_Transform_o *v14;
  UnityEngine_Component_o *v15;
  struct UnityEngine_GameObject_o *v16;
  Il2CppObject *Component_object;
  TMPro_TMP_Text_o *mainMenuTM;
  struct System_String_array *titleMainMenuText;
  System_String_o *v27;
  System_String_o *LocalizeText;
  System_Object_array *v29;
  struct System_String_array *v30;
  System_String_o *v32;
  s64 *v33;
  s64 *v35;
  System_String_o *v38;
  u32 v39;
  u64 *v40;
  System_String_o *v41;
  UnityEngine_Transform_o *v42;
  UnityEngine_Component_o *v43;
  struct UnityEngine_GameObject_o *v44;
  u64 *v49;
  System_String_o *v50;
  UnityEngine_Transform_o *v51;
  UnityEngine_Component_o *v52;
  struct UnityEngine_GameObject_o *v53;
  u64 *v58;
  System_String_o *v59;
  UnityEngine_Transform_o *v60;
  UnityEngine_Component_o *v61;
  struct UnityEngine_GameObject_o *v62;
  s32 mainMenuCnt;

LABEL_7:
  transform = get_transform(oModeselect_UI, 0);
  v5 = Find(transform, "titlemain", 0);
  gameObject = get_gameObject(v5);
  if (!get_activeSelf(gameObject))
    SetActive(gameObject, 1, 0);
  v8 = 4;
  do
  {
    v11 = v8 - 4;
    v12 = sub_8D3950(s32, &mainMenuCnt);
    v13 = Format("titlemain_item{0:00}/slide/Text_TM", v12, 0);
    mainMenu_str = Concat_5224608("titlemain/titlemainmenu/stretch/", v13);
    v14 = get_transform(oModeselect_UI, 0);
    v15 = Find(v14, mainMenu_str, 0);
    v16 = get_gameObject(v15);
    mainMenu = v16;
    Component_object = GetComponent_object_(mainMenu);
    mainMenuTM = Component_object;
    if (v11 == mainMenuPos)
    {
      else
      {
          goto LABEL_20;
      }
      v27 = *(&titleMainMenuText->obj.klass + v8);
      LocalizeText = GetLocalizeText(v27);
      v29 = NewSpecific(object, 1u);
      mainMenuCnt = 0;
      goto LABEL_41;
    }
    else
    {
        goto LABEL_25;
    }
    v30 = titleMainMenuText;
    v32 = *(&v30->obj.klass + v8);
    LocalizeText = GetLocalizeText(v32);
    v29 = NewSpecific(object, 1u);
    mainMenuCnt = 15;
LABEL_41:
    v33 = sub_8D3950(s32, &mainMenuCnt);
    v35 = v33;
    v29->m_Items[0] = v35;
    v38 = RepColTag(LocalizeText, v29);
    set_text(mainMenuTM, v38);
    ++mainMenuCnt;
    v39 = *&v9->_2.bitflags1;
    ++v8;
    v10 = (v39 >> 9) & 1;
  }
  while (v8 != 11);
  mainMenuCnt = 1;
  v40 = sub_8D3950(s32, &mainMenuCnt);
  v41 = Format("titlemain_item{0:00}", v40, 0);
  mainMenu_str = Concat_5224608("titlemain/titlemainmenu/stretch/", v41);
  v42 = get_transform(oModeselect_UI, 0);
  v43 = Find(v42, mainMenu_str, 0);
  v44 = get_gameObject(v43);
  mainMenu = v44;
  if (get_activeSelf(mainMenu))
  {
    SetActive(mainMenu, 0, 0);
  }
  mainMenuCnt = 2;
  v49 = sub_8D3950(s32, &mainMenuCnt);
  v50 = Format("titlemain_item{0:00}", v49, 0);
  mainMenu_str = Concat_5224608("titlemain/titlemainmenu/stretch/", v50);
  v51 = get_transform(oModeselect_UI, 0);
  v52 = Find(v51, mainMenu_str, 0);
  v53 = get_gameObject(v52);
  mainMenu = v53;
  if (get_activeSelf(mainMenu))
  {
    SetActive(mainMenu, 0, 0);
  }
  mainMenuCnt = 5;
  v58 = sub_8D3950(s32, &mainMenuCnt);
  v59 = Format("titlemain_item{0:00}", v58, 0);
  mainMenu_str = Concat_5224608("titlemain/titlemainmenu/stretch/", v59);
  v60 = get_transform(oModeselect_UI, 0);
  v61 = Find(v60, mainMenu_str, 0);
  v62 = get_gameObject(v61);
  mainMenu = v62;
  if (get_activeSelf(mainMenu))
  {
    SetActive(mainMenu, 0, 0);
  }
}

// 0x129ced0
void modeSelectDLCPad(void) {
  UnityEngine_GameObject_o *oModeselect_UI;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v5;
  UnityEngine_Transform_o *v6;
  UnityEngine_Component_o *v7;
  struct UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v10;
  UnityEngine_Component_o *v11;
  UnityEngine_Transform_o *v12;
  UnityEngine_Component_o *v13;
  struct UnityEngine_GameObject_o *v14;
  UnityEngine_Transform_o *v16;
  UnityEngine_Component_o *v17;
  UnityEngine_GameObject_o *v18;
  Il2CppObject *Component_object;
  System_String_o *Choicedec;
  TMPro_TMP_Text_o *v21;
  System_Object_array *v22;
  s64 *v23;
  s64 *v25;
  System_String_o *v27;
  s32 v31;
  s32 v35;
  s16 v38;
  s32 v39;
  struct System_String_array *ChoiceDLCstr;
  TMPro_TMP_Text_o *mode_endcursorYesTM;
  System_String_o *v51;
  System_Object_array *v52;
  s64 *v53;
  s64 *v55;
  struct System_String_array *v64;
  TMPro_TMP_Text_o *v65;
  System_String_o *v67;
  System_Object_array *v68;
  s64 *v69;
  s64 *v71;
  System_String_o *v74;
  struct System_String_array *v76;
  TMPro_TMP_Text_o *mode_endcursorNoTM;
  System_String_o *v79;
  System_Object_array *v80;
  s32 v81;
  System_String_o *v84;
  struct System_String_array *v86;
  s64 *v88;
  s64 *v89;
  System_String_o *v91;
  s32 v93;
  s32 v94;

LABEL_7:
  transform = get_transform(oModeselect_UI, 0);
  v5 = Find(transform, "LapOnChoice/talk01_choice/choice_answer02/choice_cursur", 0);
  mode_endcursorNo = get_gameObject(v5);
  v6 = get_transform(oModeselect_UI, 0);
  v7 = Find(v6, "LapOnChoice/talk01_choice/choice_answer02/answer01TM", 0);
  gameObject = get_gameObject(v7);
  mode_endcursorNoText = gameObject;
  mode_endcursorNoTM = GetComponent_object_(mode_endcursorNoText);
  v10 = get_transform(oModeselect_UI, 0);
  v11 = Find(v10, "LapOnChoice/talk01_choice/choice_answer01/choice_cursur", 0);
  mode_endcursorYes = get_gameObject(v11);
  v12 = get_transform(oModeselect_UI, 0);
  v13 = Find(v12, "LapOnChoice/talk01_choice/choice_answer01/answer01TM", 0);
  v14 = get_gameObject(v13);
  mode_endcursorYesText = v14;
  mode_endcursorYesTM = GetComponent_object_(mode_endcursorYesText);
  v16 = get_transform(oModeselect_UI, 0);
  v17 = Find(v16, "LapOnChoice/namechoice/talk_window/Text01TM", 0);
  v18 = get_gameObject(v17);
  Component_object = GetComponent_object_(v18);
  v21 = Component_object;
  v94 = 0;
  v22 = NewSpecific(object, 1u);
  v23 = sub_8D3950(s32, &v94);
  v25 = v23;
  v22->m_Items[0] = v25;
  v27 = RepColTag(Choicedec, v22);
  set_text(v21, v27);
  else if (!DDS3_PADCHECK_REP(6))
  {
    goto LABEL_36;
  }
  {
    v31 = 0;
    if (modeSelectChoice)
      goto LABEL_22;
LABEL_28:
    v31 = 1;
    goto LABEL_32;
  }
  else
  {
    if (!modeSelectChoice)
      goto LABEL_28;
  }
LABEL_22:
  if (v31)
  {
    v31 = 0;
  }
LABEL_32:
  modeSelectChoice = v31;
  p2sdPlaySE(0);
LABEL_36:
  if (!DDS3_PADCHECK_REP(7))
    goto LABEL_91;
LABEL_39:
  {
    else
    {
      if (!modeSelectChoice)
        goto LABEL_47;
    }
LABEL_41:
    if (v35)
    {
      v35 = 0;
    }
    goto LABEL_51;
  }
  v35 = 0;
  if (modeSelectChoice)
    goto LABEL_41;
LABEL_47:
  v35 = 1;
LABEL_51:
  modeSelectChoice = v35;
  p2sdPlaySE(0);
  if ((v38 & 0x200) != 0)
  {
LABEL_55:
    v39 = v38 & 0x200;
    if (modeSelectChoice == 1)
      goto LABEL_58;
    goto LABEL_93;
  }
LABEL_92:
  v39 = 0;
  if (modeSelectChoice == 1)
  {
LABEL_58:
    if (!get_activeSelf(mode_endcursorNo))
    {
      SetActive(mode_endcursorNo, 1, 0);
    }
    if (get_activeSelf(mode_endcursorYes))
    {
      SetActive(mode_endcursorYes, 0, 0);
    }
    v51 = ChoiceDLCstr->m_Items[0];
    v52 = NewSpecific(object, 1u);
    v94 = 22;
    v53 = sub_8D3950(s32, &v94);
    v55 = v53;
    v52->m_Items[0] = v55;
    v74 = RepColTag(v51, v52);
    set_text(mode_endcursorYesTM, v74);
    v76 = ChoiceDLCstr;
    v79 = v76->m_Items[1];
    v80 = NewSpecific(object, 1u);
    v81 = 8;
    goto LABEL_130;
  }
LABEL_93:
  if (get_activeSelf(mode_endcursorNo))
  {
    SetActive(mode_endcursorNo, 0, 0);
  }
  if (!get_activeSelf(mode_endcursorYes))
  {
    SetActive(mode_endcursorYes, 1, 0);
  }
  v64 = ChoiceDLCstr;
  v65 = mode_endcursorYesTM;
  v67 = v64->m_Items[0];
  v68 = NewSpecific(object, 1u);
  v94 = 8;
  v69 = sub_8D3950(s32, &v94);
  v71 = v69;
  v68->m_Items[0] = v71;
  v84 = RepColTag(v67, v68);
  set_text(v65, v84);
  v86 = ChoiceDLCstr;
  v79 = v86->m_Items[1];
  v80 = NewSpecific(object, 1u);
  v81 = 22;
LABEL_130:
  v93 = v81;
  v88 = sub_8D3950(s32, &v93);
  v89 = v88;
  v80->m_Items[0] = v89;
  v91 = RepColTag(v79, v80);
  set_text(mode_endcursorNoTM, v91);
}

// 0x1295f50
void mselCheckPadInput(void) {
  UnityEngine_GameObject_o *oModeselect_UI;
  u64 *v5;
  System_String_o *v6;
  System_String_o *v7;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v9;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  bool v15;
  struct ModeSelect_StaticFields *v18;
  s32 v19;
  struct ModeSelect_StaticFields **p_static_fields;
  struct mselGlobal_o *gGlobal;
  s32 ModePos;
  bool v25;
  struct ModeSelect_StaticFields *v28;
  s32 v29;
  struct ModeSelect_StaticFields **v30;
  struct mselGlobal_o *v31;
  s32 v32;
  ModeSelect_c *v34;
  struct mselGlobal_o *v35;
  struct mselGlobal_o *v36;
  s32 modeCursurCnt;

LABEL_7:
  v5 = sub_8D3950(s32, &modeCursurCnt);
  v6 = Format("titlemode_item{0:00}", v5, 0);
  v7 = Concat_5224608("titlemode/titlemodeselect/", v6);
  transform = get_transform(oModeselect_UI, 0);
  v9 = Find(transform, v7, 0);
  gameObject = get_gameObject(v9);
  Component_object = GetComponent_object_(gameObject);
  if (GetInteger(Component_object, "titlemode_item") != 1)
    SetInteger(Component_object, "titlemode_item", 1);
  else if (!DDS3_PADCHECK_REP(6))
  {
    goto LABEL_53;
  }
  p2sdPlaySE(0);
  if (GetInteger(Component_object, "titlemode_item"))
    SetInteger(Component_object, "titlemode_item", 0);
  v15 = dds3CheckDLC1();
  if (v15)
  {
    --gGlobal->ModePos;
    v19 = modeCursurCnt - 1;
  }
  else
  {
    ModePos = gGlobal->ModePos;
    if (ModePos == 2)
    {
      gGlobal->ModePos = 1;
      v19 = 2;
    }
    else
    {
      if (ModePos != 1)
        goto LABEL_49;
      gGlobal->ModePos = 2;
      v18 = *p_static_fields;
      v19 = 3;
    }
  }
  modeCursurCnt = v19;
LABEL_49:
  ModeCursurMoveflag = 1;
LABEL_53:
  else if (!DDS3_PADCHECK_REP(7))
  {
    goto LABEL_92;
  }
  p2sdPlaySE(0);
  if (GetInteger(Component_object, "titlemode_item"))
    SetInteger(Component_object, "titlemode_item", 0);
  v25 = dds3CheckDLC1();
  if (v25)
  {
    ++gGlobal->ModePos;
    v29 = modeCursurCnt + 1;
  }
  else
  {
    v31 = gGlobal;
    v32 = v31->ModePos;
    if (v32 == 2)
    {
      v31->ModePos = 1;
      v29 = 2;
    }
    else
    {
      if (v32 != 1)
        goto LABEL_88;
      v31->ModePos = 2;
      v28 = *v30;
      v29 = 3;
    }
  }
  modeCursurCnt = v29;
LABEL_88:
  ModeCursurMoveflag = 1;
LABEL_92:
  else if (!dds3CheckDLC1())
  {
    return;
  }
  else
  {
    v35 = gGlobal;
    if ((v35->ModePos & 0x80000000) == 0)
      goto LABEL_98;
  }
  v35->ModePos = 2;
  if ((v34->_2.bitflags2 & 2) != 0)
  {
LABEL_99:
  }
LABEL_108:
  v36 = gGlobal;
  if (v36->ModePos >= 3)
  {
    v36->ModePos = 0;
  }
  if (modeCursurCnt <= 0)
    goto LABEL_121;
LABEL_116:
  if ((v34->_2.bitflags2 & 2) == 0)
    goto LABEL_125;
LABEL_117:
LABEL_125:
  if (modeCursurCnt < 4)
    return;
LABEL_126:
  modeCursurCnt = 1;
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
  u64 *v1;
  u64 *v2;
  u32 *v3;
  sdfMemHandle_t_o *mh_zen;
  u32 *Ptr;
  u32 *v10;
  s64 v11;
  s64 typeHierarchyDepth;
  char *v13;
  s64 *v14;
  s64 v15;
  u64 i;
  s64 v17;
  u32 *v19;
  s64 v20;
  u32 v22;
  u32 v34;
  u32 RandIntA;
  struct System_Int32_array *ZensyoSelect;
  char *v45;
  s32 *v46;
  s32 v47;
  s32 v48;
  s32 v51;
  u32 v56;
  struct System_Int32_array *v58;
  char *v60;
  s32 *v61;
  s32 v62;
  s32 v63;
  s32 v66;
  u32 v71;
  struct System_Int32_array *v73;
  char *v75;
  s32 *v76;
  s32 v77;
  s32 v78;
  s32 v81;
  u32 *v94;
  u64 v95[3];

  v1 = NewSpecific(uint, 0xAu);
  v2 = NewSpecific(uint, 0xAu);
  v3 = NewSpecific(s32, 5u);
  NewSpecific(uint, 2u);
  mh_zen = gGlobal->mh_zen;
  Ptr = sdfMemGetPtr(mh_zen);
  v10 = Ptr;
  if (Ptr)
  {
    v11 = *Ptr;
    if (*(*Ptr + 288LL) < typeHierarchyDepth
      || *(*(v11 + 200) + 8 * typeHierarchyDepth - 8) != fclEncycRecord_t)
    {
      sub_8FC2C0(*(v11 + 64), fclEncycRecord_t, v95);
      if ((v95[0] & 1) != 0)
        v13 = v95[2];
      else
        v13 = v95 + 1;
      v14 = sub_8C4940(v13);
    }
  }
  v15 = Ptr[4];
  v94 = v3;
  if (v15 >= 1)
  {
    for (i = 0; v15 != i; ++i)
    {
      v20 = *(v10 + 4);
      v22 = *(*(v20 + 8 * i + 32) + 24LL);
      if (*(v2 + 8) <= v22)
      {
        v17 = 0;
        v19 = (v2 + 4);
      }
      else
      {
        v19 = (v2 + 5);
        if (*(v2 + 9) <= v22)
        {
          v17 = 1;
          v19 = v2 + 9;
        }
        else
        {
          if (*(v2 + 10) <= v22)
          {
            v17 = 2;
          }
          else
          {
            if (*(v2 + 11) <= v22)
            {
              v19 = v2 + 11;
              v17 = 3;
            }
            else
            {
              v19 = (v2 + 6);
              if (*(v2 + 12) <= v22)
              {
                v17 = 4;
              }
              else
              {
                v19 = v2 + 13;
                v17 = 5;
                if (*(v2 + 13) > v22)
                {
                  v19 = (v2 + 7);
                  if (*(v2 + 14) <= v22)
                  {
                    v17 = 6;
                  }
                  else
                  {
                    v19 = v2 + 15;
                    if (*(v2 + 15) <= v22)
                    {
                      v17 = 7;
                    }
                    else
                    {
                      if (*(v2 + 16) <= v22)
                      {
                        v19 = (v2 + 8);
                        v17 = 8;
                      }
                      else
                      {
                        v19 = v2 + 17;
                        v17 = 9;
                        if (*(v2 + 17) > v22)
                          continue;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      __Msel_bufferShift(v2, v1, v17 + 1, 0xAu, 0);
      *v19 = v22;
      *(v1 + v17 + 8) = i;
    }
  }
  v34 = *(v1 + 6);
  __Msel_TOverData_Copy();
  __Msel_TOverData_Clear();
  RandIntA = dds3GetRandIntA(0xAu, "");
  ZensyoSelect = gGlobal->ZensyoSelect;
  v45 = v1 + 4 * RandIntA;
  v48 = *(v45 + 8);
  v46 = (v45 + 32);
  v47 = v48;
  ZensyoSelect->m_Items[0] = v47;
  ++gGlobal->ZensyoNum;
  v51 = *v46;
  v3[8] = v51;
  __Msel_bufferShift(v2, v1, RandIntA + 1, 0xAu, 1);
  v56 = dds3GetRandIntA(9u, "");
  v58 = gGlobal->ZensyoSelect;
  v60 = v1 + 4 * v56;
  v63 = *(v60 + 8);
  v61 = (v60 + 32);
  v62 = v63;
  v58->m_Items[1] = v62;
  ++gGlobal->ZensyoNum;
  v66 = *v61;
  v3[9] = v66;
  __Msel_bufferShift(v2, v1, v56 + 1, 0xAu, 1);
  v71 = dds3GetRandIntA(8u, "");
  v73 = gGlobal->ZensyoSelect;
  v75 = v1 + 4 * v71;
  v78 = *(v75 + 8);
  v76 = (v75 + 32);
  v77 = v78;
  v73->m_Items[2] = v77;
  ++gGlobal->ZensyoNum;
  v81 = *v76;
  v94[10] = v81;
  __Msel_bufferShift(v2, v1, v71 + 1, 0xAu, 1);
  gGlobal->Z_RGBA = 1684113152;
  gGlobal->Zalpha_cnt = 0;
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
      goto LABEL_32;
    else if (ZNalpha_cnt <= 0xB3)
    {
LABEL_20:
LABEL_32:
      gGlobal->ZNalpha_cnt = ZNalpha_cnt;
      if ((v12->_2.bitflags2 & 2) == 0)
        goto LABEL_35;
LABEL_33:
LABEL_35:
      __Msel_DrawSelectDevil(gGlobal->ZensyoSelect, gGlobal->Z_RGBA, gGlobal->Z_RGBA & 0xFFFFFF00 | gGlobal->ZN_RGBA);
        goto LABEL_36;
      goto LABEL_28;
    }
    ZNalpha_cnt = 180;
    goto LABEL_32;
  }
  __Msel_DrawSelectDevil(gGlobal->ZensyoSelect, gGlobal->Z_RGBA, gGlobal->Z_RGBA);
  {
LABEL_28:
  }
LABEL_36:
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
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v5;
  struct UnityEngine_GameObject_o *gameObject;
  u64 *v11;
  System_String_o *v12;
  struct System_String_o *v13;
  UnityEngine_Transform_o *v15;
  UnityEngine_Component_o *v16;
  struct UnityEngine_GameObject_o *v17;
  Il2CppObject *Component_object;
  u64 *v21;
  System_String_o *v22;
  struct System_String_o *v23;
  UnityEngine_Transform_o *v25;
  UnityEngine_Component_o *v26;
  struct UnityEngine_GameObject_o *v27;
  Il2CppObject *v29;
  u64 *v31;
  System_String_o *v32;
  struct System_String_o *v33;
  UnityEngine_Transform_o *v35;
  UnityEngine_Component_o *v36;
  struct UnityEngine_GameObject_o *v37;
  Il2CppObject *v39;
  UnityEngine_Transform_o *v41;
  UnityEngine_Component_o *v42;
  struct UnityEngine_GameObject_o *v43;
  UnityEngine_Transform_o *v45;
  UnityEngine_Component_o *v46;
  struct UnityEngine_GameObject_o *v47;
  UnityEngine_Transform_o *v49;
  UnityEngine_Component_o *v50;
  struct UnityEngine_GameObject_o *v51;
  Il2CppObject *v53;
  Il2CppObject *v55;
  UnityEngine_Transform_o *v57;
  UnityEngine_Component_o *v58;
  struct UnityEngine_GameObject_o *v59;
  UnityEngine_Transform_o *v61;
  UnityEngine_Component_o *v62;
  struct UnityEngine_GameObject_o *v63;
  Il2CppObject *v65;
  UnityEngine_Transform_o *v67;
  UnityEngine_Component_o *v68;
  struct UnityEngine_GameObject_o *v69;
  UnityEngine_Transform_o *v71;
  UnityEngine_Component_o *v72;
  struct UnityEngine_GameObject_o *v73;
  bool v77;
  ModeSelect_c *v78;
  struct ModeSelect_StaticFields **p_static_fields;
  s16 v81;
  s32 v82;
  TMPro_TMP_Text_o *modeSelectChoiceAnswerStrTM;
  System_String_o *enddec;
  System_String_o *LocalizeText;
  System_Object_array *v89;
  System_Object_array *v90;
  s64 *v91;
  s64 *v93;
  System_String_o *v95;
  s16 v100;
  s32 v101;
  s32 v103;
  struct System_String_array *ChoicestrRcl;
  TMPro_TMP_Text_o *mode_endcursorYesTM;
  TMPro_TMP_Text_o *mode_endcursorNoTM;
  u64 *v142;
  System_String_o *v143;
  struct System_String_o *v144;
  UnityEngine_Transform_o *v146;
  UnityEngine_Component_o *v147;
  struct UnityEngine_GameObject_o *v148;
  u64 *v153;
  System_String_o *v154;
  struct System_String_o *v155;
  UnityEngine_Transform_o *v157;
  UnityEngine_Component_o *v158;
  struct UnityEngine_GameObject_o *v159;
  Il2CppObject *v161;
  bool v166;
  ModeSelect_c *v167;
  s32 v169;
  u64 v170;
  s16 v171;
  s32 v172;
  u64 v174;
  u64 *v175;
  System_String_o *v176;
  System_String_o *v178;
  UnityEngine_Transform_o *v180;
  UnityEngine_Component_o *v181;
  struct UnityEngine_GameObject_o *v182;
  Il2CppObject *v184;
  struct System_String_array *modeSelectM;
  TMPro_TMP_Text_o *modeSelectMenuTM;
  System_String_o *v191;
  System_String_o *v192;
  System_Object_array *v193;
  u64 *v194;
  System_String_o *v195;
  System_String_o *v197;
  UnityEngine_Transform_o *v199;
  UnityEngine_Component_o *v200;
  struct UnityEngine_GameObject_o *v201;
  Il2CppObject *v203;
  struct System_String_array *v207;
  System_String_o *v209;
  s64 *v210;
  s64 *v212;
  System_String_o *v214;
  s32 ModePos;
  struct System_String_array *v218;
  struct System_String_array *modeSelectLcl;
  System_String_o *v222;
  System_String_o *v223;
  struct System_String_array *v224;
  s64 v225;
  s32 v226;
  struct System_String_array *Lclstr;
  u32 *Lclstr_a;
  u32 *v233;
  s64 *v234;
  u64 v235;
  u64 max_length_low;
  s64 *v239;
  u64 *v243;
  System_String_o *v244;
  struct System_String_o *v245;
  UnityEngine_Transform_o *v247;
  UnityEngine_Component_o *v248;
  struct UnityEngine_GameObject_o *v249;
  Il2CppObject *v251;
  struct System_String_array *v254;
  TMPro_TMP_Text_o *modeSelectTM;
  System_String_o *v257;
  System_Object_array *v258;
  System_Object_array *v259;
  s64 *v260;
  s64 *v262;
  System_String_o *v264;
  u32 v265;
  s32 v266;
  struct System_String_array *v268;
  struct System_String_array *v270;
  System_String_o *v272;
  System_String_o *v273;
  struct System_String_array *v274;
  s64 v275;
  s32 v276;
  struct System_String_array *v281;
  u32 *v282;
  u32 *v283;
  s64 *v284;
  u64 v285;
  u64 v287;
  s64 *v289;
  u64 *v293;
  System_String_o *v294;
  struct System_String_o *v295;
  UnityEngine_Transform_o *v297;
  UnityEngine_Component_o *v298;
  struct UnityEngine_GameObject_o *v299;
  Il2CppObject *v301;
  struct System_String_array *v304;
  TMPro_TMP_Text_o *v305;
  System_String_o *v307;
  System_Object_array *v308;
  System_Object_array *v309;
  s64 *v310;
  s64 *v312;
  System_String_o *v314;
  u32 v315;
  struct System_String_array *v317;
  struct System_String_array *v319;
  System_String_o *v321;
  System_String_o *v322;
  struct System_String_array *v323;
  s64 v324;
  s32 v325;
  struct System_String_array *v330;
  u32 *v331;
  u32 *v332;
  s64 *v333;
  u64 v334;
  u64 v336;
  s64 *v338;
  u64 *v342;
  System_String_o *v343;
  struct System_String_o *v344;
  UnityEngine_Transform_o *v346;
  UnityEngine_Component_o *v347;
  struct UnityEngine_GameObject_o *v348;
  Il2CppObject *v350;
  struct System_String_array *v353;
  TMPro_TMP_Text_o *v354;
  System_String_o *v356;
  System_Object_array *v357;
  System_Object_array *v358;
  s64 *v359;
  s64 *v361;
  System_String_o *v363;
  u32 v364;
  struct System_String_array *v372;
  TMPro_TMP_Text_o *v373;
  System_String_o *v375;
  System_String_o *v376;
  System_Object_array *v377;
  System_Object_array *v378;
  s64 *v379;
  s64 *v381;
  System_String_o *v384;
  struct System_String_array *v387;
  TMPro_TMP_Text_o *v388;
  System_String_o *v390;
  System_Object_array *v391;
  s32 v392;
  s32 v394;
  s32 modeSelectChoice;
  s32 v397;
  struct System_String_array *v405;
  TMPro_TMP_Text_o *v406;
  System_String_o *v408;
  System_String_o *v409;
  System_Object_array *v410;
  System_Object_array *v411;
  s64 *v412;
  s64 *v414;
  System_String_o *v416;
  struct System_String_array *v419;
  s64 *v421;
  s64 *v422;
  System_String_o *v424;
  s32 v428;
  s32 modeSelectTextIdxCnt;
  s32 modeCursurCnt;

  eglSetOt(71);
  eglLinkTest(1, 0, 128, 3, 0, 0, 1, 1);
  eglLinkAlpha(0);
LABEL_10:
  ModeObj = oModeselect_UI;
  transform = get_transform(ModeObj, 0);
  v5 = Find(transform, "titlemode", 0);
  gameObject = get_gameObject(v5);
  modeobj = gameObject;
  if (!get_activeSelf(modeobj))
  {
    SetActive(modeobj, 1, 0);
  }
  v11 = sub_8D3950(s32, &modeCursurCnt);
  v12 = Format("titlemode_item{0:00}", v11, 0);
  v13 = Concat_5224608("titlemode/titlemodeselect/", v12);
  modeCursur_str = v13;
  v15 = get_transform(ModeObj, 0);
  v16 = Find(v15, modeCursur_str, 0);
  v17 = get_gameObject(v16);
  modeCursur = v17;
  Component_object = GetComponent_object_(modeCursur);
  modeCursur_anim = Component_object;
  v21 = sub_8D3950(s32, &modeSelectTextIdxCnt);
  v22 = Format("Text_modenote{0:00}TM", v21, 0);
  v23 = Concat_5224608("titlemode/titlemode_note/", v22);
  modeSelectTextIdx_str = v23;
  v25 = get_transform(ModeObj, 0);
  v26 = Find(v25, modeSelectTextIdx_str, 0);
  v27 = get_gameObject(v26);
  modeSelectTextIdx = v27;
  v29 = GetComponent_object_(modeSelectTextIdx);
  modeSelectTM = v29;
  v428 = modeSelectTextIdxCnt;
  v31 = sub_8D3950(s32, &v428);
  v32 = Format("titlemode_item{0:00}", v31, 0);
  v33 = Concat_5224608("titlemode/titlemodeselect/", v32);
  modeSelectTextMenu_str = v33;
  v35 = get_transform(ModeObj, 0);
  v36 = Find(v35, modeSelectTextMenu_str, 0);
  v37 = get_gameObject(v36);
  modeSelectTextMenu = v37;
  v39 = GetComponent_object_(modeSelectTextMenu);
  modeSelectMenuTM = v39;
  v41 = get_transform(ModeObj, 0);
  v42 = Find(v41, "titlemode/namechoice", 0);
  v43 = get_gameObject(v42);
  modeSelectChoiceText = v43;
  v45 = get_transform(ModeObj, 0);
  v46 = Find(v45, "titlemode/talk01_choice", 0);
  v47 = get_gameObject(v46);
  modeSelectChoiceAnswer = v47;
  v49 = get_transform(ModeObj, 0);
  v50 = Find(v49, "titlemode/namechoice/talk_window/Text01TM", 0);
  v51 = get_gameObject(v50);
  modeSelectChoiceAnswerStr = v51;
  v53 = GetComponent_object_(modeSelectChoiceAnswerStr);
  modeSelectChoiceAnswerStrTM = v53;
  v55 = GetComponent_object_(modeSelectChoiceAnswer);
  modeSelectChoiceAnswer_anim = v55;
  set_enabled(modeSelectChoiceAnswer_anim, 1);
  v57 = get_transform(ModeObj, 0);
  v58 = Find(v57, "titlemode/talk01_choice/choice_answer02/choice_cursur", 0);
  v59 = get_gameObject(v58);
  mode_endcursorNo = v59;
  v61 = get_transform(ModeObj, 0);
  v62 = Find(v61, "titlemode/talk01_choice/choice_answer02/answer01TM", 0);
  v63 = get_gameObject(v62);
  mode_endcursorNoText = v63;
  v65 = GetComponent_object_(mode_endcursorNoText);
  mode_endcursorNoTM = v65;
  v67 = get_transform(ModeObj, 0);
  v68 = Find(v67, "titlemode/talk01_choice/choice_answer01/choice_cursur", 0);
  v69 = get_gameObject(v68);
  mode_endcursorYes = v69;
  v71 = get_transform(ModeObj, 0);
  v72 = Find(v71, "titlemode/talk01_choice/choice_answer01/answer01TM", 0);
  v73 = get_gameObject(v72);
  mode_endcursorYesText = v73;
  mode_endcursorYesTM = GetComponent_object_(mode_endcursorYesText);
  v77 = dds3CheckDLC1();
  if (v77)
    goto LABEL_28;
  if (DLCFlag)
    goto LABEL_28;
LABEL_113:
  modeCursurCnt = 1;
  modeCursurCnt = (*p_static_fields)->modeCursurCnt;
  v142 = sub_8D3950(s32, &modeCursurCnt);
  v143 = Format("titlemode_item{0:00}", v142, 0);
  v144 = Concat_5224608("titlemode/titlemodeselect/", v143);
  modeCursur_str = v144;
  v146 = get_transform(ModeObj, 0);
  v147 = Find(v146, modeCursur_str, 0);
  v148 = get_gameObject(v147);
  modeCursur = v148;
  if (get_activeSelf(modeCursur))
  {
    SetActive(modeCursur, 0, 0);
  }
  modeCursurCnt = 2;
  DLCFlag = 1;
  v153 = sub_8D3950(s32, &modeCursurCnt);
  v154 = Format("titlemode_item{0:00}", v153, 0);
  v155 = Concat_5224608("titlemode/titlemodeselect/", v154);
  modeCursur_str = v155;
  v157 = get_transform(ModeObj, 0);
  v158 = Find(v157, modeCursur_str, 0);
  v159 = get_gameObject(v158);
  modeCursur = v159;
  v161 = GetComponent_object_(modeCursur);
  modeCursur_anim = v161;
  v81 = *&v78->_2.bitflags1;
  if ((v81 & 0x200) != 0)
    goto LABEL_125;
LABEL_29:
  v82 = 0;
  if (modeSelectChoiceflag)
  {
LABEL_30:
    SetActive(modeSelectChoiceText, 1, 0);
    SetActive(modeSelectChoiceAnswer, 1, 0);
    LocalizeText = GetLocalizeText(enddec);
    v89 = NewSpecific(object, 1u);
    modeCursurCnt = 0;
    v90 = v89;
    v91 = sub_8D3950(s32, &modeCursurCnt);
    v93 = v91;
    v90->m_Items[0] = v93;
    v95 = RepColTag(LocalizeText, v90);
    set_text(modeSelectChoiceAnswerStrTM, v95);
    if (GetInteger(modeSelectChoiceAnswer_anim, "talk_choice") != 1)
    {
      SetInteger(modeSelectChoiceAnswer_anim, "talk_choice", 1);
    }
    else if (DDS3_PADCHECK_REP(6))
    {
      goto LABEL_399;
    }
    else if (!DDS3_PADCHECK_REP(7))
    {
      goto LABEL_54;
    }
LABEL_399:
    {
      v394 = 0;
      if (modeSelectChoice)
        goto LABEL_401;
LABEL_411:
      v397 = 1;
      goto LABEL_415;
    }
    else
    {
      if (!modeSelectChoice)
        goto LABEL_411;
    }
LABEL_401:
    if (modeSelectChoice != 1)
    {
LABEL_416:
      p2sdPlaySE(0);
      if ((v100 & 0x200) == 0)
      {
LABEL_55:
        v101 = 0;
        v103 = modeSelectChoice;
        if (v103 != 1)
        {
LABEL_56:
          else if (v103)
          {
            goto LABEL_59;
          }
          if (get_activeSelf(mode_endcursorNo))
          {
            SetActive(mode_endcursorNo, 0, 0);
          }
          if (!get_activeSelf(mode_endcursorYes))
          {
            SetActive(mode_endcursorYes, 1, 0);
          }
          v372 = ChoicestrRcl;
          v373 = mode_endcursorYesTM;
          v375 = v372->m_Items[0];
          v376 = GetLocalizeText(v375);
          v377 = NewSpecific(object, 1u);
          modeCursurCnt = 8;
          v378 = v377;
          v379 = sub_8D3950(s32, &modeCursurCnt);
          v381 = v379;
          v378->m_Items[0] = v381;
          v384 = RepColTag(v376, v378);
          set_text(v373, v384);
          v387 = ChoicestrRcl;
          v388 = mode_endcursorNoTM;
          v390 = GetLocalizeText(v387->m_Items[1]);
          v391 = NewSpecific(object, 1u);
          v392 = 22;
LABEL_457:
          modeSelectTextIdxCnt = v392;
          v421 = sub_8D3950(s32, &modeSelectTextIdxCnt);
          v422 = v421;
          v391->m_Items[0] = v422;
          v424 = RepColTag(v390, v391);
          set_text(v388, v424);
            goto LABEL_462;
          goto LABEL_60;
        }
LABEL_423:
        if (!get_activeSelf(mode_endcursorNo))
        {
          SetActive(mode_endcursorNo, 1, 0);
        }
        if (get_activeSelf(mode_endcursorYes))
        {
          SetActive(mode_endcursorYes, 0, 0);
        }
        v405 = ChoicestrRcl;
        v406 = mode_endcursorYesTM;
        v408 = v405->m_Items[0];
        v409 = GetLocalizeText(v408);
        v410 = NewSpecific(object, 1u);
        modeCursurCnt = 22;
        v411 = v410;
        v412 = sub_8D3950(s32, &modeCursurCnt);
        v414 = v412;
        v411->m_Items[0] = v414;
        v416 = RepColTag(v409, v411);
        set_text(v406, v416);
        v419 = ChoicestrRcl;
        v388 = mode_endcursorNoTM;
        v390 = GetLocalizeText(v419->m_Items[1]);
        v391 = NewSpecific(object, 1u);
        v392 = 8;
        goto LABEL_457;
      }
LABEL_420:
      v101 = v100 & 0x200;
      v103 = modeSelectChoice;
      if (v103 != 1)
        goto LABEL_56;
      goto LABEL_423;
    }
    v397 = 0;
LABEL_415:
    modeSelectChoice = v397;
    goto LABEL_416;
  }
LABEL_127:
  if (GetInteger(modeSelectChoiceAnswer_anim, "talk_choice"))
  {
    SetInteger(modeSelectChoiceAnswer_anim, "talk_choice", 0);
  }
  modeSelectChoice = 0;
  {
LABEL_471:
    if (ModeCursurMoveflag != 1)
      return;
    goto LABEL_141;
  }
LABEL_139:
    goto LABEL_471;
  if (ModeCursurMoveflag != 1)
    return;
LABEL_141:
  v166 = dds3CheckDLC1();
  if (v166)
    goto LABEL_481;
  if (DLCFlag)
  {
LABEL_481:
    v169 = 3;
  }
  {
    v169 = 2;
  }
  else
  {
    v169 = 2;
  }
  DLCMenuCnt = v169;
  v170 = 0;
  v171 = *&v167->_2.bitflags1;
  if ((v171 & 0x200) == 0)
    goto LABEL_187;
  while (1)
  {
    v172 = v171 & 0x200;
    if (v170 >= DLCMenuCnt)
      break;
    while (1)
    {
      v174 = v170 + 1;
      if (v170 == gGlobal->ModePos)
      {
        modeCursurCnt = v170 + 1;
        v175 = sub_8D3950(s32, &modeCursurCnt);
        v176 = Format("titlemode_item{0:00}/Text_mode_g", v175, 0);
        v178 = Concat_5224608("titlemode/titlemodeselect/", v176);
        modeSelectTextMenu_str = v178;
        v180 = get_transform(ModeObj, 0);
        v181 = Find(v180, modeSelectTextMenu_str, 0);
        v182 = get_gameObject(v181);
        modeSelectTextMenu = v182;
        v184 = GetComponent_object_(modeSelectTextMenu);
        modeSelectMenuTM = v184;
        modeSelectM = modeSelectM_;
        v191 = modeSelectM->m_Items[v170];
        v192 = GetLocalizeText(v191);
        v193 = NewSpecific(object, 1u);
        modeSelectTextIdxCnt = 3;
      }
      else
      {
        modeCursurCnt = v170 + 1;
        v194 = sub_8D3950(s32, &modeCursurCnt);
        v195 = Format("titlemode_item{0:00}/Text_mode_g", v194, 0);
        v197 = Concat_5224608("titlemode/titlemodeselect/", v195);
        modeSelectTextMenu_str = v197;
        v199 = get_transform(ModeObj, 0);
        v200 = Find(v199, modeSelectTextMenu_str, 0);
        v201 = get_gameObject(v200);
        modeSelectTextMenu = v201;
        v203 = GetComponent_object_(modeSelectTextMenu);
        modeSelectMenuTM = v203;
        v207 = modeSelectM_;
        v209 = v207->m_Items[v170];
        v192 = GetLocalizeText(v209);
        v193 = NewSpecific(object, 1u);
        modeSelectTextIdxCnt = 2;
      }
      v210 = sub_8D3950(s32, &modeSelectTextIdxCnt);
      v212 = v210;
      v193->m_Items[0] = v212;
      v214 = RepColTag(v192, v193);
      set_text(modeSelectMenuTM, v214);
      v170 = v174;
      if ((v171 & 0x200) != 0)
        break;
LABEL_187:
      v172 = 0;
      if (v170 >= DLCMenuCnt)
        goto LABEL_190;
    }
  }
LABEL_190:
  else
  {
    ModePos = gGlobal->ModePos;
    if (ModePos != 2)
    {
LABEL_193:
      if (ModePos != 1)
      {
        if (ModePos)
          goto LABEL_355;
        v218 = NewSpecific(string, 3u);
        Lclstr_a = v218;
        v222 = modeSelectLcl->m_Items[2];
        v223 = GetLocalizeText(v222);
        v224 = Split_5246672(v223, delstr, 0);
        Lclstr = v224;
        v225 = 4;
        v226 = (v167->_2.bitflags2 >> 1) & 1;
        while (1)
        {
          v235 = v225 - 4;
          max_length_low = LODWORD(Lclstr->max_length);
          if (v235 >= max_length_low)
            break;
          else
          {
            if (v235 >= max_length_low)
            {
LABEL_218:
            }
          }
          v239 = *(&Lclstr->obj.klass + v225);
          *&Lclstr_a[2 * v225] = v239;
            goto LABEL_233;
LABEL_224:
LABEL_233:
          modeCursurCnt = modeSelectTextIdxCnt;
          v243 = sub_8D3950(s32, &modeCursurCnt);
          v244 = Format("Text_modenote{0:00}TM", v243, 0);
          v245 = Concat_5224608("titlemode/titlemode_note/", v244);
          modeSelectTextIdx_str = v245;
          v247 = get_transform(ModeObj, 0);
          v248 = Find(v247, modeSelectTextIdx_str, 0);
          v249 = get_gameObject(v248);
          modeSelectTextIdx = v249;
          v251 = GetComponent_object_(modeSelectTextIdx);
          modeSelectTM = v251;
          v254 = Lclstr_a;
          v257 = *(&v254->obj.klass + v225);
          v258 = NewSpecific(object, 1u);
          modeSelectTextIdxCnt = 0;
          v259 = v258;
          v260 = sub_8D3950(s32, &modeSelectTextIdxCnt);
          v262 = v260;
          v259->m_Items[0] = v262;
          v264 = RepColTag(v257, v259);
          set_text(modeSelectTM, v264);
          ++modeSelectTextIdxCnt;
          v265 = *&v167->_2.bitflags1;
          ++v225;
          v226 = (v265 >> 9) & 1;
          if (v225 == 7)
          {
            v266 = 0;
            goto LABEL_354;
          }
        }
        else
        {
          v233 = Lclstr_a;
          v234 = "";
          if (!"")
            goto LABEL_230;
        }
LABEL_230:
        *&v233[2 * v225] = "";
          goto LABEL_233;
        goto LABEL_224;
      }
      v268 = NewSpecific(string, 3u);
      Lclstr_a = v268;
      v270 = modeSelectLcl;
      v272 = v270->m_Items[0];
      v273 = GetLocalizeText(v272);
      v274 = Split_5246672(v273, delstr, 0);
      Lclstr = v274;
      v275 = 4;
      v276 = (v167->_2.bitflags2 >> 1) & 1;
      while (1)
      {
        v285 = v275 - 4;
        v281 = Lclstr;
        v287 = LODWORD(v281->max_length);
        if (v285 >= v287)
          break;
        else
        {
          v282 = Lclstr_a;
          if (v285 >= v287)
          {
LABEL_272:
          }
        }
        v289 = *(&v281->obj.klass + v275);
        *&v282[2 * v275] = v289;
          goto LABEL_287;
LABEL_278:
LABEL_287:
        modeCursurCnt = modeSelectTextIdxCnt;
        v293 = sub_8D3950(s32, &modeCursurCnt);
        v294 = Format("Text_modenote{0:00}TM", v293, 0);
        v295 = Concat_5224608("titlemode/titlemode_note/", v294);
        modeSelectTextIdx_str = v295;
        v297 = get_transform(ModeObj, 0);
        v298 = Find(v297, modeSelectTextIdx_str, 0);
        v299 = get_gameObject(v298);
        modeSelectTextIdx = v299;
        v301 = GetComponent_object_(modeSelectTextIdx);
        modeSelectTM = v301;
        v304 = Lclstr_a;
        v305 = modeSelectTM;
        v307 = *(&v304->obj.klass + v275);
        v308 = NewSpecific(object, 1u);
        modeSelectTextIdxCnt = 0;
        v309 = v308;
        v310 = sub_8D3950(s32, &modeSelectTextIdxCnt);
        v312 = v310;
        v309->m_Items[0] = v312;
        v314 = RepColTag(v307, v309);
        set_text(v305, v314);
        ++modeSelectTextIdxCnt;
        v315 = *&v167->_2.bitflags1;
        ++v275;
        v276 = (v315 >> 9) & 1;
        if (v275 == 7)
        {
          v266 = 1;
          goto LABEL_354;
        }
      }
      else
      {
        v283 = Lclstr_a;
        v284 = "";
        if (!"")
          goto LABEL_284;
      }
LABEL_284:
      *&v283[2 * v275] = "";
        goto LABEL_287;
      goto LABEL_278;
    }
  }
  v317 = NewSpecific(string, 3u);
  Lclstr_a = v317;
  v319 = modeSelectLcl;
  v321 = v319->m_Items[1];
  v322 = GetLocalizeText(v321);
  v323 = Split_5246672(v322, delstr, 0);
  Lclstr = v323;
  v324 = 4;
  v325 = (v167->_2.bitflags2 >> 1) & 1;
  do
  {
    v334 = v324 - 4;
    v330 = Lclstr;
    v336 = LODWORD(v330->max_length);
    if (v334 >= v336)
    {
      else
      {
        v332 = Lclstr_a;
        v333 = "";
        if (!"")
          goto LABEL_337;
      }
LABEL_337:
      *&v332[2 * v324] = "";
        goto LABEL_331;
      goto LABEL_340;
    }
    else
    {
      v331 = Lclstr_a;
      if (v334 >= v336)
      {
LABEL_325:
      }
    }
    v338 = *(&v330->obj.klass + v324);
    *&v331[2 * v324] = v338;
    {
LABEL_331:
    }
LABEL_340:
    modeCursurCnt = modeSelectTextIdxCnt;
    v342 = sub_8D3950(s32, &modeCursurCnt);
    v343 = Format("Text_modenote{0:00}TM", v342, 0);
    v344 = Concat_5224608("titlemode/titlemode_note/", v343);
    modeSelectTextIdx_str = v344;
    v346 = get_transform(ModeObj, 0);
    v347 = Find(v346, modeSelectTextIdx_str, 0);
    v348 = get_gameObject(v347);
    modeSelectTextIdx = v348;
    v350 = GetComponent_object_(modeSelectTextIdx);
    modeSelectTM = v350;
    v353 = Lclstr_a;
    v354 = modeSelectTM;
    v356 = *(&v353->obj.klass + v324);
    v357 = NewSpecific(object, 1u);
    modeSelectTextIdxCnt = 0;
    v358 = v357;
    v359 = sub_8D3950(s32, &modeSelectTextIdxCnt);
    v361 = v359;
    v358->m_Items[0] = v361;
    v363 = RepColTag(v356, v358);
    set_text(v354, v363);
    ++modeSelectTextIdxCnt;
    v364 = *&v167->_2.bitflags1;
    ++v324;
    v325 = (v364 >> 9) & 1;
  }
  while (v324 != 7);
  v266 = 2;
LABEL_354:
  ModeSelectFlag = v266;
  modeSelectTextIdxCnt = 1;
LABEL_355:
  ModeCursurMoveflag = 0;
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
  v22->MessageMH = sdfDevLoadFile("/title/mseldata.bmd", &v22->pMessage, 0);
  dds3BackColor = 0x80000000;
  asset_bc = get_asset_bc();
  if (!IsLoad(asset_bc, "e043"))
  {
    v27 = get_asset_bc();
    Load(v27, "e043", "fcmn", 0);
  }
  v28 = get_asset_bc();
  Prefab_16624656 = LoadPrefab_16624656(v28, "common", "dds3data/UI", "titleUI");
  Modeselectobj = Prefab_16624656;
  v33 = Find("Canvas_UI", 0);
  transform = get_transform(v33, 0);
  v36 = Instantiate_object__425664(Modeselectobj, transform, 0);
  oModeselect_UI = v36;
  AddComponent_object_(oModeselect_UI);
  v38 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v38,
    0,
    Method_ModeSelect_mselMain__);
  dds3StartProcess("mselProc", 0x2B19u, 0, 0, v38, 0, 0, 0, 0, 0);
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
  u64 *v2;
  AssetBundleCtrl_o *asset_bc;
  u64 v7;
  struct ModeSelect_StaticFields **p_static_fields;
  struct ModeSelect_StaticFields *static_fields;
  struct mselGlobal_o *gGlobal;
  s64 *v11;
  u64 v14;
  s16 v17;
  s32 v18;
  struct ModeSelect_StaticFields **v19;
  s32 modeSelectChoice;
  s32 msel_msg_hiki2_sel;
  bool v30;
  s16 v31;
  s8 SelMessagePos;
  s32 v37;
  struct mselGlobal_o *v39;
  s32 v40;
  s32 ExitMode;
  sdfMemHandle_t_o *mh_zen;
  struct sdfMemHandle_t_o *mh;
  Il2CppObject *Ptr;
  s32 msel_msg_hiki3;
  s8 v59;
  s32 endcnt;
  s32 v66;
  s32 PlayTime;
  s32 v69;
  u64 v71;
  s32 cnt;
  UnityEngine_GameObject_o *oModeselect_UI;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v76;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v78;
  UnityEngine_Component_o *v79;
  UnityEngine_GameObject_o *v80;
  s16 v85;
  s32 v86;
  AssetBundleCtrl_o *v90;
  sdfTexHandle_t_o *v98;
  struct mselGlobal_o *v99;
  s32 msel_msg_hiki;
  struct ModeSelect_StaticFields **v111;
  struct mselGlobal_o *v113;
  s32 v114;
  s32 v119;
  s16 v120;
  s32 v121;
  s32 v122;
  UnityEngine_Transform_o *v124;
  UnityEngine_Component_o *v125;
  UnityEngine_GameObject_o *v126;
  struct ModeSelect_StaticFields **v129;
  struct mselGlobal_o *v130;
  s32 v131;
  s32 v132;
  sdfMemHandle_t_o *v135;
  Il2CppObject *v136;
  Il2CppObject *v138;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v141;
  s64 *v142;
  s64 v144;
  s32 v145;
  u64 v146;
  struct System_Int32_array *ZensyoSelect;
  Il2CppClass *v150;
  struct System_Int32_array *v151;
  s64 v153;
  fclencyceelem_t_o *v155;
  u32 v156;
  s32 v157;
  sdfTexHandle_t_o *BgSpriteHandle;
  struct mselGlobal_o *v161;
  u64 v163;
  sdfMemHandle_t_o *mh_gbwk;
  u32 v172;
  s64 *v178;
  s32 v184;
  u64 *v188;
  u64 v191;
  s64 *v194;
  struct ModeSelect_StaticFields *v202;
  s16 v203;
  s32 v204;
  struct mselGlobal_o *v205;
  s32 F061_01;
  s32 ModeSelectFlag;
  s32 v212;
  u64 v217[3];

  v2 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v2);
  rsetOtOfs(72);
  rsetAlpha(0);
  rsetTest(1, 0, 128, 3, 0, 0, 1, 1);
  asset_bc = get_asset_bc();
  if (!IsLoad(asset_bc, "e043"))
    return 0;
  if (!BGMLoadflag)
    goto LABEL_17;
LABEL_13:
  if ((*(v7 + 295) & 2) != 0)
  {
LABEL_14:
  }
LABEL_24:
  p_static_fields = (v7 + 184);
  static_fields = *(v7 + 184);
  switch (gGlobal->step)
  {
    case 0:
      gGlobal->cnt = 0;
      (*p_static_fields)->gGlobal->step = 2;
      return 0;
    case 1:
      gGlobal->cnt = 0;
      ++(*p_static_fields)->gGlobal->step;
      return 0;
    case 2:
      if (!ButtonGuideDrawflag)
      {
        if (gGlobal->mode != 1)
          goto LABEL_802;
        if (!dds3CheckDLC2())
        {
          v11 = &"MENU02";
        }
        else
        {
LABEL_802:
          v11 = &"TITLE02";
        }
        ButtonGuideDispSet(*v11, 0, 0, 90);
        *(*(v7 + 184) + 68LL) = 1;
      }
      if (*(*(*(v7 + 184) + 432LL) + 160LL) == 1)
      {
        if (!dds3CheckDLC2())
        {
          ButtonGuideDispSet("MENU02", 0, 0, 90);
        }
      }
      v184 = FindId(0, "F061_01");
      p2sdPlayBGM(v184);
      dds3FadeIn(0, 0, 0, 0x14u);
      *(&v187[2].klass->vtable[8].method->bitflags + 1) = 0;
      ++*&v187[2].klass->vtable[8].method->slot;
      mselStartDataSet();
      return 0;
    case 3:
      mselDrawModeString(v7);
      if (dds3FadeCheck())
        return 0;
      if (*(*(v14 + 184) + 44LL))
      {
        if (DDS3_PADCHECK_TRIG(1))
        {
          if ((v17 & 0x200) != 0)
          {
            v18 = v17 & 0x200;
            if (!modeSelectChoice)
              goto LABEL_66;
          }
          else
          {
            v18 = 0;
            if (!modeSelectChoice)
            {
LABEL_66:
              modeSelectEndflag = 1;
              (*v19)->modeSelectChoiceflag = 0;
LABEL_716:
              if (dlcChackflag == 1)
              {
                evtBitOn(3712);
                  goto LABEL_726;
                goto LABEL_724;
              }
              evtBitOff(3712);
              goto LABEL_723;
            }
          }
          if (modeSelectChoice == 1)
          {
            ButtonGuideDispOff();
            if (gGlobal->mode != 1)
              goto LABEL_803;
            if (!dds3CheckDLC2())
            {
              v194 = &"MENU02";
            }
            else
            {
LABEL_803:
              v194 = &"TITLE02";
            }
            ButtonGuideDispSet(*v194, 0, 0, 90);
            modeSelectChoiceflag = 0;
            p2sdPlaySE(10);
          }
          goto LABEL_716;
        }
        if (DDS3_PADCHECK_TRIG(3))
        {
          if (gGlobal->mode != 1)
            goto LABEL_804;
          if (!dds3CheckDLC2())
          {
            ButtonGuideDispOff();
            v178 = &"MENU02";
          }
          else
          {
LABEL_804:
            v178 = &"TITLE02";
          }
          ButtonGuideDispSet(*v178, 0, 0, 90);
          modeSelectChoiceflag = 0;
          p2sdPlaySE(10);
            goto LABEL_726;
LABEL_724:
          goto LABEL_726;
        }
LABEL_723:
          goto LABEL_726;
        goto LABEL_724;
      }
      mselCheckPadInput(v14);
      if (!gGlobal->mode)
      {
        if (DDS3_PADCHECK_TRIG(3))
        {
          gGlobal->cnt = 0;
          BGMLoadflag = 0;
          ButtonGuideDrawflag = 0;
          ButtonGuideDispOff();
LABEL_593:
          gGlobal->step = 22;
          dds3FadeOut(0, 0, 0, 0x14u);
          p2sdFadeOut(7405569);
          p2sdPlaySE(10);
          return 0;
        }
      }
      if (dds3CheckDLC2())
      {
        if (DDS3_PADCHECK_TRIG(3))
        {
          gGlobal->cnt = 0;
          BGMLoadflag = 0;
          ButtonGuideDrawflag = 0;
          ButtonGuideDispOff();
          DDS3_GBWK->GameFileInfo->newfile = 1;
          goto LABEL_593;
        }
      }
      if (!DDS3_PADCHECK_TRIG(1))
      {
        if (!DDS3_PADCHECK_TRIG(12))
          goto LABEL_723;
      }
      if (gGlobal->mode == 1)
      {
        ButtonGuideDispOff();
        ButtonGuideDispSet("TITLE02", 0, 0, 90);
      }
      p2sdPlaySE(8);
      modeSelectChoiceflag = 1;
        goto LABEL_724;
LABEL_726:
      v202 = *(v191 + 184);
      if (modeSelectEndflag == 1)
      {
        v203 = *(v191 + 294);
        if ((v203 & 0x200) != 0)
        {
          v204 = v203 & 0x200;
          v205 = gGlobal;
          if (!v205->mode)
          {
LABEL_729:
            if (v204 && !*(v191 + 216))
            {
              v205 = gGlobal;
            }
            v205->step = 15;
              goto LABEL_746;
            goto LABEL_744;
          }
        }
        else
        {
          v204 = 0;
          v205 = gGlobal;
          if (!v205->mode)
            goto LABEL_729;
        }
        __Msel_TOverData_Clear(v191);
        p2sdFadeOut(F061_01);
        gGlobal->step = 16;
          goto LABEL_746;
LABEL_744:
LABEL_746:
        dds3FadeOut(0, 0, 0, 0x14u);
      }
      if (modeSelectEndflag == 1)
      {
        if (ModeSelectFlag)
        {
          if (ModeSelectFlag == 1)
          {
            v212 = 1;
          }
          else
          {
            if (ModeSelectFlag == 2)
            {
              v212 = 2;
            }
            else
            {
              if (ModeSelectFlag != 3)
              {
LABEL_784:
                title2Posflag = 0;
                modeSelectChoice = 0;
                modeSelectEndflag = 0;
                ButtonGuideDispOff();
                gGlobal->step = 13;
                p2sdPlaySE(8);
                gGlobal->cnt = 0;
                p2sdFadeOut(7405569);
                  goto LABEL_557;
                goto LABEL_797;
              }
              v212 = 3;
            }
          }
        }
        else
        {
          v212 = 0;
        }
        cfgSetBit_22187328(9u, v212);
        goto LABEL_784;
      }
      return 0;
    case 4:
      mselDrawHikitugisimasuka(v7);
      if (fclChkMessage())
        goto LABEL_171;
      gGlobal->cnt = 0;
      gGlobal->step = 5;
      fclEndMessage();
      fclSetSelMessagePos(0);
      fclStartMessage(msel_msg_hiki2);
      goto LABEL_159;
    case 5:
      mselDrawHikitugisimasuka(v7);
      if (!fclChkSelMessage())
        goto LABEL_171;
      gGlobal->cnt = 0;
      gGlobal->step = 6;
        goto LABEL_200;
      goto LABEL_172;
    case 6:
      mselDrawHikitugisimasuka(v7);
      v30 = fclChkSelMessage() == 0;
      if (!v30)
        goto LABEL_199;
      SelMessagePos = fclGetSelMessagePos();
      fclEndMessage();
      __Msel_TOverData_Clear();
      if (SelMessagePos)
      {
        v37 = F061_01;
        p2sdFadeOut(v37);
        v39 = gGlobal;
        v40 = 19;
      }
      else
      {
        mh_gbwk = gGlobal->mh_gbwk;
        sdfMemGetPtr(mh_gbwk);
        gGlobal->cnt = 0;
        v39 = gGlobal;
        v40 = 18;
      }
      goto LABEL_556;
    case 7:
      if (fmProcessChk())
        return 0;
      ExitMode = slGetExitMode();
      if (!ExitMode)
      {
        gGlobal->cnt = 0;
        gGlobal->step = 17;
        v172 = 0;
        goto LABEL_798;
      }
      if (ExitMode != 2)
        return 0;
      mh_zen = gGlobal->mh_zen;
      sdfMemGetPtr(mh_zen);
      mh = DDS3_GBWK->mh;
      Ptr = sdfMemGetPtr(gGlobal->mh_gbwk);
      DDS3_GBWK->mh = mh;
      mselDevilChoice(Ptr);
      if (!gGlobal->ZensyoNum)
      {
        dds3FadeIn(0, 0, 0, 0x5Au);
        gGlobal->cnt = 0;
        gGlobal->step = 12;
        return 0;
      }
      dds3FadeIn(0, 0, 0, 0xFu);
      gGlobal->cnt = 0;
      gGlobal->step = 8;
        goto LABEL_549;
      goto LABEL_551;
    case 8:
      if ((*(v7 + 295) & 2) != 0 && !*(v7 + 216))
      mselDrawDevilSelect(0);
      if (fclChkMessage())
        goto LABEL_171;
      gGlobal->cnt = 0;
      gGlobal->step = 9;
      fclSetSelMessagePos(0);
      fclStartMessage(msel_msg_hiki4);
      msel_msg_hiki2_sel = msel_msg_hiki4_sel;
LABEL_159:
      fclStartSelMessage(msel_msg_hiki2_sel);
      return 0;
    case 9:
      if ((*(v7 + 295) & 2) != 0 && !*(v7 + 216))
      mselDrawDevilSelect(0);
      if (fclChkSelMessage())
      {
        gGlobal->cnt = 0;
        gGlobal->step = 10;
      }
LABEL_171:
        goto LABEL_172;
      goto LABEL_200;
    case 0xA:
      if ((*(v7 + 295) & 2) != 0 && !*(v7 + 216))
      mselDrawDevilSelect(0);
      v30 = fclChkSelMessage() == 0;
      if (!v30)
        goto LABEL_199;
      v59 = fclGetSelMessagePos();
      fclEndMessage();
      if (v59 == 1)
      {
        *(&v173[2].klass->vtable[8].method->bitflags + 1) = 0;
        *&v173[2].klass->vtable[8].method->slot = 8;
        mselDevilChoice();
          goto LABEL_551;
      }
      else
      {
        if (v59)
        {
          gGlobal->cnt = 0;
          v39 = gGlobal;
          v40 = 20;
LABEL_556:
          v39->step = v40;
          {
LABEL_557:
          }
LABEL_797:
          v172 = 20;
LABEL_798:
          dds3FadeOut(0, 0, 0, v172);
          return 0;
        }
        gGlobal->cnt = 0;
        gGlobal->step = 11;
        msel_msg_hiki3 = msel_msg_hiki5;
        {
LABEL_551:
          fclStartMessage(msel_msg_hiki3);
          return 0;
        }
      }
LABEL_549:
      goto LABEL_551;
    case 0xB:
      if ((*(v7 + 295) & 2) != 0 && !*(v7 + 216))
      mselDrawDevilSelect(1u);
      v30 = fclChkMessage() == 0;
      if (v30)
      {
        fclEndMessage();
        gGlobal->cnt = 0;
        v39 = gGlobal;
        v40 = 21;
        goto LABEL_556;
      }
LABEL_199:
      if ((v31 & 0x200) != 0)
      {
LABEL_172:
      }
LABEL_200:
      fclUpdateMessage();
      return 0;
    case 0xC:
      evtBitOn(2225);
      endcnt = gGlobal->GameFileInfo->endcnt;
      if (endcnt >= 0)
        v66 = endcnt + 1;
      else
        v66 = 1;
      if (v66 >= 1)
      {
        evtBitOn(2230);
        if (v66 != 1)
        {
          evtBitOn(2231);
          if (v66 != 2)
          {
            evtBitOn(2232);
            if (v66 >= 4)
            {
              evtBitOn(2233);
              if (v66 != 4)
                evtBitOn(2234);
            }
          }
        }
      }
      PlayTime = gGlobal->GameFileInfo->PlayTime;
      if (PlayTime >= 107998200)
        PlayTime = 107998200;
      switch (PlayTime % 108000 / 1800 % 10)
      {
        case 0:
          v69 = 2226;
          goto LABEL_439;
        case 4:
          v69 = 2228;
          goto LABEL_439;
        case 5:
          v69 = 2229;
          goto LABEL_439;
        case 8:
          v69 = 2227;
LABEL_439:
          evtBitOn(v69);
          break;
        default:
          break;
      }
      v135 = gGlobal->mh_zen;
      v136 = sdfMemGetPtr(v135);
      v138 = v136;
      if (v136)
      {
        klass = v136->klass;
        if (v136->klass->_2.typeHierarchyDepth < typeHierarchyDepth
          || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncycRecord_t)
        {
          sub_8FC2C0(klass->_1.element_class, fclEncycRecord_t, v217);
          if ((v217[0] & 1) != 0)
            v141 = v217[2];
          else
            v141 = v217 + 1;
          v142 = sub_8C4940(v141);
        }
      }
      v144 = 8;
      do
      {
        v146 = v144 - 8;
        ZensyoSelect = gGlobal->ZensyoSelect;
        if (*(&ZensyoSelect->obj.klass + v144) != -1)
        {
          v150 = v138[2].klass;
          v151 = gGlobal->ZensyoSelect;
          v153 = *(&v151->obj.klass + v144);
          v155 = *(&v150->_1.byval_arg.data + v153);
          fclEncycRegist2(v155, 1);
        }
        ++v144;
        v145 = (v156 >> 9) & 1;
      }
      while (v144 != 13);
      v157 = F061_01;
      p2sdFadeOut(v157);
      BgSpriteHandle = gGlobal->BgSpriteHandle;
      if (BgSpriteHandle)
      {
        sdfTexFreeDelayed(BgSpriteHandle);
        gGlobal->BgSpriteHandle = 0;
      }
      v161 = gGlobal;
      v161->AttSpriteHandle = fclLoadTexture("/title/att_font.tmx");
      gGlobal->cnt = 0;
      gGlobal->step = 13;
      return 0;
    case 0xD:
      rsetOtOfs(71);
      rsetAlpha(0);
      rsetTest(1, 0, 128, 3, 0, 0, 1, 1);
      cnt = *(*(*(v71 + 184) + 432LL) + 76LL);
      if (cnt >= 240)
      {
        if ((*(v71 + 295) & 2) != 0 && !*(v71 + 216))
        {
          cnt = gGlobal->cnt;
        }
        if (cnt <= 330)
        {
          transform = get_transform(oModeselect_UI, 0);
          v76 = Find(transform, "titlemode", 0);
          gameObject = get_gameObject(v76);
          if (get_activeSelf(gameObject))
            SetActive(gameObject, 0, 0);
          v78 = get_transform(oModeselect_UI, 0);
          v79 = Find(v78, "finction", 0);
          v80 = get_gameObject(v79);
          if (!get_activeSelf(v80))
            SetActive(v80, 1, 0);
          dds3FadeOut(0, 0, 0, 0x3Cu);
        }
      }
      if ((*(v71 + 295) & 2) != 0)
      {
        {
        }
      }
      if (*(*(*(v71 + 184) + 432LL) + 76LL) == 330)
      {
        dds3FadeOut(0xFFu, 0xFFu, 0xFFu, 0x3Cu);
        ClearModeselectUI();
        ClearMainmenuUI();
      }
      v85 = *(v71 + 294);
      if ((v85 & 0x200) != 0)
      {
        v86 = v85 & 0x200;
      }
      else
      {
        v86 = 0;
      }
      v129 = (v71 + 184);
      v130 = *(*(v71 + 184) + 432LL);
      v131 = v130->cnt;
      if (v131 >= 390)
      {
        if (v86 && !*(v71 + 216))
        {
          v130 = gGlobal;
        }
        v130->cnt = 0;
        (*v129)->ModeCursurMoveflag = 1;
        (*v129)->gGlobal->step = 14;
        mselStartGame(v71);
      }
      else
      {
        if (v86 && !*(v71 + 216))
        {
          v130 = gGlobal;
          v131 = v130->cnt;
        }
        v130->cnt = v131 + 1;
      }
      return 0;
    case 0xE:
      DLCFlag = 0;
      ClearModeselectUI(v7);
      ClearMainmenuUI();
      RemoveKeys(1, "e043");
      v90 = get_asset_bc();
      UnloadAB(v90, "e043");
      return 0;
    case 0xF:
      mselDrawModeString(v7);
      goto LABEL_336;
    case 0x10:
      mselDrawModeString(v7);
      goto LABEL_309;
    case 0x11:
      goto LABEL_336;
    case 0x12:
      mselDrawHikitugisimasuka(v7);
      if (!dds3FadeCheck())
      {
        dds3FadeIn(0, 0, 0, 0x14u);
        gGlobal->cnt = 0;
        gGlobal->step = 7;
        fmProcTrigSequence(4, 0);
      }
      return 0;
    case 0x13:
      mselDrawHikitugisimasuka(v7);
LABEL_309:
      if (dds3FadeCheck())
        return 0;
      v98 = gGlobal->BgSpriteHandle;
      if (v98)
      {
        sdfTexFreeDelayed(v98);
        gGlobal->BgSpriteHandle = 0;
      }
      v99 = gGlobal;
      v99->AttSpriteHandle = fclLoadTexture("/title/att_font.tmx");
      gGlobal->cnt = 0;
      gGlobal->step = 13;
        goto LABEL_363;
      goto LABEL_361;
    case 0x14:
      if ((*(v7 + 295) & 2) != 0 && !*(v7 + 216))
      mselDrawDevilSelect(0);
LABEL_336:
      if (!dds3FadeCheck())
      {
        dds3FadeIn(0, 0, 0, 0x14u);
        fclStartMessage(msel_msg_hiki);
        gGlobal->step = 4;
      }
      return 0;
    case 0x15:
      if ((*(v7 + 295) & 2) != 0 && !*(v7 + 216))
      mselDrawDevilSelect(1u);
      if (dds3FadeCheck())
        return 0;
      gGlobal->cnt = 0;
      gGlobal->step = 12;
      {
LABEL_361:
      }
LABEL_363:
      dds3FadeIn(0, 0, 0, 0x5Au);
      return 0;
    case 0x16:
      mselDrawModeString(v7);
      v113 = gGlobal;
      v114 = v113->cnt;
      if (v114 < 21)
      {
        v113->cnt = v114 + 1;
        return 0;
      }
      {
        else
        {
          if (gGlobal->mode)
            v132 = 3;
          else
            v132 = 2;
            goto LABEL_639;
        }
      }
      else if (v113->mode)
      {
        v132 = 3;
      }
      else
      {
        v132 = 2;
      }
LABEL_639:
      DLCFlag = 0;
      (*v111)->gGlobal->cnt = 0;
      (*v111)->ModeCursurMoveflag = 1;
      (*v111)->gGlobal->step = 14;
      LODWORD(v217[0]) = v132;
      v188 = sub_8D3950(s32, v217);
      dds3AdminiCallSequence(2, v188, 0, 0);
      return 0;
    case 0x18:
      if (DDS3_PADCHECK_TRIG(1))
      {
        LapChoiceflag = 1;
        if (modeSelectChoice)
        {
          v119 = 1;
        }
        else
        {
          v119 = 0;
        }
        dlcChackflag = v119;
        p2sdPlaySE(8);
      }
      if (*(*(v163 + 184) + 136LL))
      {
        dds3FadeOut(0, 0, 0, 0x14u);
        gGlobal->step = 25;
      }
      else
      {
        modeSelectDLCPad(v163);
        gGlobal->cnt = 0;
      }
      return 0;
    case 0x19:
      v120 = *(v7 + 294);
      if ((v120 & 0x200) != 0)
      {
        v121 = v120 & 0x200;
        v122 = gGlobal->cnt;
        if (v122 > 59)
          goto LABEL_386;
      }
      else
      {
        v121 = 0;
        v122 = gGlobal->cnt;
        if (v122 > 59)
        {
LABEL_386:
          v124 = get_transform(oModeselect_UI, 0);
          v125 = Find(v124, "LapOnChoice", 0);
          v126 = get_gameObject(v125);
          if (get_activeSelf(v126))
            SetActive(v126, 0, 0);
          gGlobal->cnt = 0;
          LapChoiceflag = 0;
          modeSelectChoice = 0;
          gGlobal->step = 0;
          return 0;
        }
      }
      if (v121 && !*(v7 + 216))
      {
        v122 = gGlobal->cnt;
      }
      gGlobal->cnt = v122 + 1;
      return 0;
    default:
      return 0;
  }
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
  dds3KillProcessName("mselProc", 1);
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
LABEL_6:
    dds3CreateGameData(0);
LABEL_7:
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
  u64 *v3;
  s32 v4;

  fldDbg->NoClip = 0;
  fldDbg->EncountOn = 1;
  fldProcNext(11, 601);
  v4 = 601;
  v3 = sub_8D3950(s32, &v4);
  dds3AdminiCallSequence(8, v3, 4, 0);
}

// 0x1294dc0
void pacSync(pacFileHandle_t *pacFileHandle) {
  ;
}

// 0x1294dd0
void *sdfChipAllocZero(s32 aSize) {
  return 0;
}
