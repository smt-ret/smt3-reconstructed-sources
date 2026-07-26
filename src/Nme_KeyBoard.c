#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct ImeKeyboard ImeKeyboard;
typedef struct Nme_KeyBoard_NME_TYPE Nme_KeyBoard_NME_TYPE;
typedef struct Nme_KeyBoard_NME_Transition Nme_KeyBoard_NME_Transition;
typedef struct SwitchIME SwitchIME;
typedef struct TextManager TextManager;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct nmeData_t nmeData_t;

struct Nme_KeyBoard_NME_Transition {
    s32 value__;
};

struct Nme_KeyBoard_NME_TYPE {
    s32 value__;
};

static s32 CharNo;
static s32 UseLang;
static s32 ChackLang;
static s32 MojiNum;
static s32 MojiType;
static s32 TransitionNo;
static s32 KeyBoardUseflag;
static s32 ForeignCountriesInit;
static bool Judgment;
static s32 NameUIPos;
static s32 NameKeyBoardflag;
static s32 NameEndflag;
static s32 NameYseNoflag;
static s32 yesnoflag;
static s32 yesnoswith;
static s32 yesnoOpeCnt;
static s32 yesnoInitflag;
static s32 yesnoBackflag;
static s8 gProcessStat;
static nmeData_t *GBWK;
static void *NameUIObj;
static void *name_backloop;
static void *name_backloopAnime;
static void *keyboardObj;
static ImeKeyboard *keyboardObj_a;
static void *NameMode;
static void *nemeend_no;
static void *nemeend_noTM;
static void *nemeend_yes;
static void *nemeend_yesTM;
static void *name_endcursorNo;
static void *name_endcursorNo_anim;
static void *name_endcursorYes;
static void *name_endcursorYes_anim;
static void *name_end;
static void *name_end_anim;
static void *name_end2;
static void *nameend_dec;
static void *nameend_decTM;
static u8 gFadeCol[3];
static char *UseName;
static char *UseHelp;
static char *tblDefName[12];
static char *tblHelp[3];
static char *tblHelp_[3];
static char *kariStr1;
static char *kariStr2;
static char *ChoicestrRcl[3];
static s32 FormNum;
static f32 FilterAlpha;
static bool MojiSize;
static bool FramePos;
static bool FadeMove;
static bool FrameMove;
static bool Fadeflag;
static bool BackInit;
static bool ChangeColor;
static bool PS4Nextflag;
static char *FormStr;
static char *MojiSizeStr;
static char *NameFrameOnStr;
static char *StrAssist;
static char *NameDecRcl[4];
static char *NameDesRcl[3];
static char NameSave[UNKNOWN_ARRAY_SIZE];
static char *NameSave2[3];
static char *kariif;
static char *NameDecRcl_[3];
static char *NameDesRcl_[3];
static void *NameKeyBoardUI;
static void NameSet[UNKNOWN_ARRAY_SIZE];
static void NameSetTM[UNKNOWN_ARRAY_SIZE];
static void *NameSize;
static void *NameSizeAnim;
static void *NameFrame;
static void *SelFrameAnim;
static void *NickSetAnim;
static void *EndSetAnim;
static void *NameDescription;
static void *NameDescriptionTM;
static void *NameDescriptionFrame;
static void *NameDes;
static void *Filter;
static void *NameDesTM;
static bool Capflag;
static void *BackImageCap;
static void *BackImageSpr;
static void *CameraObj;
static void *RenImageObj;
static void *CameraR;
static void *Tex;
static void *RenImage;
static void *RenTex;
static void *MainCanvas;
static void *CanvasMenu;
static void *oName_UI;

void BackImageCreate(void);
void ButtonGuideDispOff(void);
void ButtonGuideDispSet(char *name, bool timer, bool empty, s32 waitTimer);
void ClearNameUI(void);
void EndKeyMove(void);
s32 GetLanguage(void);
char *GetLocalizeText(char *ID);
void KeyBoardDraw(char *Help, char *Name, s32 Num, s32 Lang);
void KeyBoradEnd(void);
void KeyMove(void);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
void MojiColorChange(void);
void MojiInput(void);
void MojiSave(char *name);
void OpenIME(SwitchIME *this, char *titleText, char *initText, s32 maxLength, s32 lang, s32 minLength);
char *RepColTag(char *txt, void **LegacyParamArray);
bool TextZyage(void);
u8 **UnicodeToIndexByte2(TextManager *this, char *str);
s32 dds3FadeCheck(void);
void dds3FadeClear(void);
void dds3FadeIn(u32 r, u32 g, u32 b, u32 frame);
void *dds3GetProcessData(dds3ProcessID_t **id);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
bool evtBitCheck(s32 no);
void frDelFontStyle(u8 StyleNo);
void nmeChack(char *name, bool judg);
void nmeFadeOut(void);
void nmeKeyBoardInit(void);
void nmeKeyBoardProcessStart(s8 TargetNo, s8 DebugMode);
void nmeSetFontImageToGW(s8 TargetNo, nmeData_t **pData);
s32 scrGetIntPara(s32 n);
void scrSetIntReturnValue(s32 i);

// 0x1882f20
void BackImageCreate(void) {
}

// 0x18817e0
void ClearNameUI(void) {
  UnityEngine_Object_o *oName_UI;
  UnityEngine_Object_o *v6;

  if (op_Inequality(oName_UI, 0, 0))
  {
    v6 = oName_UI;
    Destroy_27360000(v6);
    oName_UI = 0;
  }
}

// 0x1884b90
void EndKeyMove(void) {
  u32 v3;
  Nme_KeyBoard_c *v4;
  Nme_KeyBoard_c *v5;
  s16 v6;
  s32 v7;
  struct Nme_KeyBoard_StaticFields *v8;
  s16 v9;
  s32 v10;
  s16 v11;
  s32 v12;
  struct Nme_KeyBoard_StaticFields *static_fields;
  struct Nme_KeyBoard_StaticFields **p_static_fields;
  struct cmpSeqInfo_t_o *SeqInfo;
  Nme_KeyBoard_c *v19;
  struct Nme_KeyBoard_StaticFields **v20;
  struct Nme_KeyBoard_StaticFields *v21;

  v3 = cmpChkCommonInput(0xF3u);
  if (v3 <= 2)
  {
    if (v3 != 1)
    {
      if (v3 != 2)
      yesnoBackflag = 1;
    }
    if ((v9 & 0x200) != 0)
    {
      v10 = v9 & 0x200;
    }
    else
    {
      v10 = 0;
    }
    p_static_fields = &v4->static_fields;
    static_fields = v4->static_fields;
    if (static_fields->yesnoswith == 1)
    {
      static_fields->yesnoBackflag = 1;
      if ((v4->_2.bitflags2 & 2) == 0)
    }
    else
    {
      static_fields->yesnoflag = 0;
      (*p_static_fields)->yesnoInitflag = 0;
      nmeFadeOut();
      SeqInfo = GBWK->SeqInfo;
      SeqInfo->Flag |= 0x10u;
      GBWK->CfmFlag = 2;
      if ((v4->_2.bitflags2 & 2) == 0)
    }
    if (GetInteger(name_end_anim, StringLiteral_5148))
    {
      SetInteger(name_end_anim, StringLiteral_5148, 0);
    }
  }
  if (v3 == 16)
  {
    if ((v11 & 0x200) != 0)
    {
      v12 = v11 & 0x200;
      v8 = v5->static_fields;
      if (v8->yesnoswith)
      {
        if (!v12)
      }
    }
    else
    {
      v12 = 0;
      v8 = Nme_KeyBoard->static_fields;
      if (v8->yesnoswith)
    }
    if (!v12)
  }
  if (v3 != 32)
  if ((v6 & 0x200) != 0)
  {
    v7 = v6 & 0x200;
    v8 = v5->static_fields;
    if (v8->yesnoswith)
    {
      if (!v7)
      v8->yesnoswith = 0;
    }
  }
  else
  {
    v7 = 0;
    v8 = Nme_KeyBoard->static_fields;
    if (v8->yesnoswith)
  }
  v8->yesnoswith = 1;
  cmpPlaySE2(v3, 2);
  v20 = &v19->static_fields;
  v21 = v19->static_fields;
  if (v21->yesnoBackflag == 1)
  {
    v21->NameUIPos = 0;
    (*v20)->NameEndflag = 0;
    (*v20)->KeyBoardUseflag = 0;
    (*v20)->yesnoflag = 0;
    (*v20)->yesnoswith = 0;
    (*v20)->yesnoInitflag = 0;
    (*v20)->NameYseNoflag = 0;
    (*v20)->yesnoBackflag = 0;
    SetActive((*v20)->name_end, 0, 0);
    SetActive(name_end2, 0, 0);
    ChangeColor = 0;
    MojiColorChange();
    if (!get_activeSelf(NameDescriptionFrame))
    {
      SetActive(NameDescriptionFrame, 1, 0);
    }
    TransitionNo = 0;
  }
}

// 0x187f660
void *GetoNameUI(void) {
  return oName_UI;
}

// 0x18853d0
void *ImageBlur(void *Text) {
    return 0;
}

// 0x18831e0
void KeyBoardDraw(char *Help, char *Name, s32 Num, s32 Lang) {
  Nme_KeyBoard_c *v9;
  struct Nme_KeyBoard_StaticFields *static_fields;

  static_fields = v9->static_fields;
  switch (static_fields->CharNo)
  {
    case 0:
    case 1:
    case 2:
    case 3:
      OpenIME(static_fields->keyboardObj_a, Help, Name, Num, Lang, 0);
      break;
    default:
      return;
  }
}

// 0x18836c0
void KeyBoradEnd(void) {
    EndKeyMove();
    GetLocalizeText(0);
    RepColTag(0, 0);
    ButtonGuideDispOff();
}

// 0x1882720
void KeyMove(void) {
    TextZyage();
}

// 0x1882180
void MojiColorChange(void) {
    RepColTag(0, 0);
}

// 0x18832d0
void MojiInput(void) {
  bool IsCancel;
  struct Nme_KeyBoard_StaticFields *static_fields;
  Nme_KeyBoard_c *v8;
  struct Nme_KeyBoard_StaticFields **p_static_fields;
  struct Nme_KeyBoard_StaticFields *v10;
  System_String_o *InputText;
  System_String_o *v13;
  u64 v16;
  bool v17;
  s16 v18;
  s32 v19;
  struct Nme_KeyBoard_StaticFields *v20;
  s32 NameUIPos;
  s32 v22;
  bool v23;
  struct Nme_KeyBoard_StaticFields *v24;

  IsCancel = get_IsCancel(keyboardObj_a);
  if (!IsCancel)
  {
    else
    {
      static_fields = Nme_KeyBoard->static_fields;
      if (static_fields->NameUIPos == 3)
    }
    InputText = get_InputText(static_fields->keyboardObj_a);
    nmeChack(InputText, 0);
    v13 = get_InputText(keyboardObj_a);
    MojiSave(v13);
    if (FrameMove)
    {
      if (**(v16 + 184))
      {
        if ((*(v16 + 295) & 2) != 0 && !*(v16 + 216))
        v23 = TextZyage(v16);
        if (v23)
        {
          v24 = *(v16 + 184);
          if (v24->NameUIPos == 2)
          {
            if ((*(v16 + 295) & 2) != 0 && !*(v16 + 216))
            {
              v24 = Nme_KeyBoard->static_fields;
            }
            v24->NameUIPos = 3;
          }
        }
      }
      p_static_fields = (v16 + 184);
    }
    v17 = TextZyage(v16);
    if (!v17)
    {
      if ((v18 & 0x200) != 0)
      {
        v19 = v18 & 0x200;
        v20 = *(v16 + 184);
        if (!v20->CharNo)
        {
          if (v19 && !*(v16 + 216))
          {
            v20 = Nme_KeyBoard->static_fields;
          }
          NameUIPos = v20->NameUIPos;
          if (NameUIPos)
          {
            if (v19 && !*(v16 + 216))
            {
              v20 = Nme_KeyBoard->static_fields;
              NameUIPos = v20->NameUIPos;
            }
            if (NameUIPos == 1)
            {
              if (v19 && !*(v16 + 216))
              {
                v20 = Nme_KeyBoard->static_fields;
              }
              v20->NameUIPos = 2;
              if ((*(v16 + 295) & 2) == 0)
            }
            if (v19 && !*(v16 + 216))
            {
              v20 = Nme_KeyBoard->static_fields;
              NameUIPos = v20->NameUIPos;
            }
            if (NameUIPos != 2)
          }
          if (v19 && !*(v16 + 216))
          {
            v20 = Nme_KeyBoard->static_fields;
          }
          v20->NameUIPos = 1;
          if ((*(v16 + 295) & 2) == 0)
        }
      }
      else
      {
        v19 = 0;
        v20 = Nme_KeyBoard->static_fields;
        if (!v20->CharNo)
      }
      if (v19 && !*(v16 + 216))
      {
        v20 = Nme_KeyBoard->static_fields;
      }
      v22 = v20->NameUIPos;
      if (!v22)
      if (v19 && !*(v16 + 216))
      {
        v20 = Nme_KeyBoard->static_fields;
        v22 = v20->NameUIPos;
      }
      if (v22 == 1)
      {
        if ((*(v16 + 295) & 2) != 0 && !*(v16 + 216))
        {
          v20 = Nme_KeyBoard->static_fields;
        }
        v20->NameUIPos = 0;
      }
    }
    if ((*(v16 + 295) & 2) == 0)
    {
      *(*(v16 + 184) + 323LL) = 1;
    }
  }
  if (get_IsCancel(keyboardObj_a))
  {
    v10 = v8->static_fields;
    p_static_fields = &v8->static_fields;
    v10->NameKeyBoardflag = 0;
    (*p_static_fields)->KeyBoardUseflag = 0;
    (*p_static_fields)->TransitionNo = 4;
  }
}

// 0x187fc00
void MojiSave(char *name) {
  System_Byte_array *v4;
  Nme_KeyBoard_c *v5;
  struct Nme_KeyBoard_StaticFields *static_fields;
  struct System_SByte_array *InputNums;
  s64 MojiType;
  Nme_KeyBoard_c *v10;
  struct Nme_KeyBoard_StaticFields *v11;
  struct System_SByte_array *v12;
  s64 v13;
  u64 i;
  Nme_KeyBoard_c *v21;
  struct Nme_KeyBoard_StaticFields *v22;
  struct System_Byte_array *InputCode;
  s64 v24;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;
  il2cpp_array_size_t v27;
  struct Nme_KeyBoard_StaticFields *v28;
  struct System_Byte_array *v29;
  s64 v30;
  Il2CppArrayBounds *v31;
  il2cpp_array_size_t v32;
  il2cpp_array_size_t v33;
  u64 v35;
  u64 v37;
  u64 v38;
  Nme_KeyBoard_c *v44;
  struct Nme_KeyBoard_StaticFields *v45;
  s64 v46;
  struct System_Byte_array *v47;
  Il2CppArrayBounds *v49;
  il2cpp_array_size_t v50;
  il2cpp_array_size_t v51;
  struct Nme_KeyBoard_StaticFields *v52;
  struct System_Byte_array *v53;
  s64 v54;
  Il2CppArrayBounds *v56;
  il2cpp_array_size_t v57;
  il2cpp_array_size_t v58;
  struct Nme_KeyBoard_StaticFields *v60;
  struct System_SByte_array *v61;
  s64 v62;

  v4 = UnicodeToIndexByte2(txtMgr, name);
  static_fields = v5->static_fields;
  InputNums = static_fields->GBWK->InputNums;
  MojiType = static_fields->MojiType;
  if (InputNums->m_Items[MojiType])
  {
    v11 = v10->static_fields;
    v12 = v11->GBWK->InputNums;
    v13 = v11->MojiType;
    v12->m_Items[v13] = 0;
  }
  for (i = 0; i != 8; ++i)
  {
    v22 = v21->static_fields;
    InputCode = v22->GBWK->InputCode;
    v24 = v22->MojiType;
    bounds = InputCode->bounds;
    length = bounds[1].length;
    v27 = bounds[2].length;
    InputCode->m_Items[v27 * (i + length * v24)] = 0;
    v28 = Nme_KeyBoard->static_fields;
    v29 = v28->GBWK->InputCode;
    v30 = v28->MojiType;
    v31 = v29->bounds;
    v32 = v31[1].length;
    v33 = v31[2].length;
    v35 = i + v32 * v30;
    v29->m_Items[v33 * v35 + 1] = 0;
  }
  if (get_Length(name) >= 1)
  {
    v37 = 0;
    v38 = 0;
    do
    {
      v45 = v44->static_fields;
      v46 = v45->MojiType;
      v47 = v45->GBWK->InputCode;
      v49 = v47->bounds;
      v50 = v49[1].length;
      v51 = v49[2].length;
      v47->m_Items[v51 * (v38 + v50 * v46)] = v4->m_Items[v37];
      v52 = Nme_KeyBoard->static_fields;
      v53 = v52->GBWK->InputCode;
      v54 = v52->MojiType;
      v56 = v53->bounds;
      v57 = v56[1].length;
      v58 = v56[2].length;
      v53->m_Items[v58 * (v38 + v57 * v54) + 1] = v4->m_Items[v37 + 1];
      v60 = Nme_KeyBoard->static_fields;
      v61 = v60->GBWK->InputNums;
      v62 = v60->MojiType;
      ++v38;
      ++v61->m_Items[v62];
      v37 += 2LL;
    }
    while (v38 < get_Length(name));
  }
}

// 0x1885020
void NameUIPosMoveCorect(void) {
    TextZyage();
}

// 0x18818e0
bool TextZyage(void) {
    return 0;
}

// 0x187f6d0
void nmeChack(char *name, bool judg) {
    GetLocalizeText(0);
    RepColTag(0, 0);
}

// 0x1886010
s8 nmeChkKeyBoardProcess(void) {
  return gProcessStat == 1;
}

// 0x1886760
dds3ProcessFunc_t *nmeKeyBoardCalc(dds3ProcessID_t *PID) {
    dds3GetProcessData(0);
    dds3FadeCheck();
    return 0;
}

// 0x18847e0
dds3ProcessFunc_t *nmeKeyBoardDestroy(dds3ProcessID_t *PID) {
  Nme_KeyBoard_c *v2;
  struct Nme_KeyBoard_StaticFields *static_fields;
  struct nmeData_t_o *GBWK;
  s8 TargetNo;
  struct System_String_array *NameSave2;
  struct System_String_array *v12;
  struct System_String_array *v14;
  UnityEngine_Object_o *CanvasMenu;
  UnityEngine_Object_o *CameraObj;

  static_fields = v2->static_fields;
  GBWK = static_fields->GBWK;
  if (GBWK)
  {
    TargetNo = GBWK->TargetNo;
    nmeSetFontImageToGW(TargetNo, &static_fields->GBWK);
    frDelFontStyle(4u);
    GBWK = 0;
    gProcessStat = 2;
    dds3KernelDebugSign = 0;
    dds3FadeClear();
  }
  if (!LODWORD(NameSave2->max_length))
  NameSave2->m_Items[0] = 0;
  v12 = NameSave2;
  v12->m_Items[1] = 0;
  v14 = NameSave2;
  v14->m_Items[2] = 0;
  yesnoflag = 0;
  NameUIPos = 0;
  NameEndflag = 0;
  TransitionNo = 0;
  NameYseNoflag = 0;
  yesnoInitflag = 0;
  KeyBoardUseflag = 0;
  ForeignCountriesInit = 0;
  BackInit = 0;
  if (op_Inequality(CanvasMenu, 0, 0))
  {
    set_renderMode(CanvasMenu, 0);
  }
  Destroy_27360000(CameraObj);
  ButtonGuideDispOff();
  ClearNameUI();
  return 0;
}

// 0x18842a0
dds3ProcessFunc_t *nmeKeyBoardDraw(dds3ProcessID_t *PID) {
    dds3GetProcessData(0);
    dds3FadeCheck();
    TextZyage();
    ButtonGuideDispSet(0, 0, 0, 0);
    return 0;
}

// 0x187e170
void nmeKeyBoardInit(void) {
    ButtonGuideDispSet(0, 0, 0, 0);
    evtBitCheck(0);
    GetLanguage();
    GetLocalizeText(0);
    RepColTag(0, 0);
    nmeChack(0, 0);
    MojiSave(0);
}

// 0x1886080
s32 nmeKeyBoardNameEntry(void) {
  struct Nme_KeyBoard_StaticFields *static_fields;
  s32 gProcessStat;
  s64 v5;
  s8 IntPara;
  s32 v8;
  s32 v9;

  else
  {
    static_fields = Nme_KeyBoard->static_fields;
    gProcessStat = static_fields->gProcessStat;
    if (gProcessStat != 2)
    {
      if (!gProcessStat)
      {
        IntPara = scrGetIntPara(0);
        nmeKeyBoardProcessStart(IntPara, v5);
      }
      v8 = 0;
      v9 = 1;
    }
  }
  v9 = 0;
  v8 = 1;
  static_fields->gProcessStat = 0;
  scrSetIntReturnValue(v9);
  return v8;
}

// 0x18861c0
void nmeKeyBoardProcessStart(s8 TargetNo, s8 DebugMode) {
    LoadPrefab_16624656(0, 0, 0, 0);
    nmeKeyBoardInit();
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
    evtBitCheck(0);
    dds3FadeIn(0, 0, 0, 0);
}

// 0x18800c0
dds3ProcessFunc_t *nmeKeyBoardUpdata(dds3ProcessID_t *PID) {
    dds3GetProcessData(0);
    dds3FadeCheck();
    ClearNameUI();
    TextZyage();
    GetLocalizeText(0);
    MojiColorChange();
    RepColTag(0, 0);
    KeyMove();
    KeyBoardDraw(0, 0, 0, 0);
    MojiInput();
    ButtonGuideDispSet(0, 0, 0, 0);
    KeyBoradEnd();
    BackImageCreate();
    return 0;
}
