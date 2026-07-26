#include "types.h"

typedef struct ImeKeyboard ImeKeyboard;
typedef struct _FRQ _FRQ;
typedef struct cmpCursorPos_t cmpCursorPos_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct fclSprTblArry_t fclSprTblArry_t;
typedef struct nmeData_t nmeData_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

static s32 cUDcnt;
static s32 kanUDcnt;
static s32 ckanUDcnt;
static s32 cLRcnt_max_b;
static s32 eLRcnt_max;
static s32 cNamecnt;
static s32 mUDcnt;
static s32 mojilist;
static s32 markflag;
static s32 codenmeflag;
static s32 name_fadecnt;
static char *moji;
static s32 kanabox_num;
static s32 box_num;
static s32 letter_num;
static s32 underline_num;
static s32 underline_num_c;
static s32 nameend_namenum;
static s32 nameend_cnamenum;
static s32 bup_namenum;
static s32 bup_cnamenum;
static s32 kanabox_nummax;
static s32 box_nummax;
static s32 letter_nummax;
static s32 kanabox_numbup;
static s32 defnameflag;
static s32 kanjiscrollflag;
static s32 kanjiIndex;
static s32 kanjiIndex_bup;
static s32 kanjiScrollcnt;
static s32 kanjiIndexObjcnt;
static s32 namemoji;
static s32 nameEndflag;
static s32 nameEndChackflag;
static s32 nameEndCheck1;
static s32 nameEndCheck2;
static s32 nameOpeflag;
static s32 nameInitflag;
static s32 nameEndDefflag;
static s32 nameRightflag;
static s32 nameLeftflag;
static s32 namepushflag;
static s32 kanjiLineCnt;
static s32 funccursorPos;
static s32 underLineflag;
static s32 defnameChackflag;
static s32 kariflag;
static s32 PlistUpdateflag;
static s32 endChoiceflag;
static s32 kanjibarInitflag;
static s32 EventObjDelateflag;
static s32 kanaListCnt;
static char *mojiCousur_str;
static void *nameTmpTextTP;
static void *cnameTmpTextTP;
static void *kanjiIndexTmpList_;
static void *kanjiScrIndexTmpText_;
static void *nameTmpTextTPbup[8];
static void *cnameTmpTextTPbup[8];
static s32 nameTMPCnt;
static s32 nameTMPColor;
static char defname[UNKNOWN_ARRAY_SIZE];
static char *nameTMPStr[8];
static char *nameTMPStr2[8];
static char *cnameTMPStr[8];
static s32 Chackflag;
static s32 Chackflag2;
static s32 Chackflag3;
static s32 moveCorsolEndfag;
static s32 NameAnim0;
static s32 NameAnim1;
static s32 NameAnim2;
static s32 NameAnim3;
static s32 kansurollmojidelateflag;
static char *name_des[2];
static char *name_desRcl[2];
static char *namefull[2];
static char *ChoicestrRcl[3];
static char *namedec[2];
static char *kanaListMoji[4];
static s32 yesnoflag;
static s32 yesnoOpeCnt;
static s32 yesnoOpeflag;
static s32 yesnoswith;
static void *NameUIObj;
static void *kanalist_hira;
static void *kanalist_hira_anim;
static void *kanalist_kata;
static void *kanalist_kata_anim;
static void *kanalist_alphabet;
static void *kanalist_alphabet_anim;
static void *kanalist_kanji;
static void *kanalist_kanji_anim;
static void *functionImage;
static void *namelist_rightbutton;
static void *namelist_buttonAnim_r;
static void *namelist_leftbutton;
static void *namelist_buttonAnim_l;
static void *namelist_deletebutton;
static void *namelist_buttonAnim_del;
static void *namelist_endbutton;
static void *namelist_buttonAnim_end;
static void *name_list;
static void *list_hira;
static void *list_alphabet;
static void *list_kanji;
static void *kanji_scrollbar_up;
static void *kanji_scrollbar_up_anime;
static void *kanji_scrollbar_down;
static void *kanji_scrollbar_down_anime;
static void *kanji_scrollbar;
static void *kanji_scrollbar_anime;
static void *listcursur;
static sdfVector3_t listcursurPos;
static void *listcursur_hira_a;
static sdfVector3_t listcursur_hirafirstPos;
static void *listcursur_alpha_a;
static sdfVector3_t listcursur_alphafirstPos;
static void *panel_cursor;
static void *name_input;
static void *_name_input;
static void *name_description;
static void *name_descriptionTM;
static void *mynameImage;
static sdfVector3_t mynameImagePos;
static void *codenameImage;
static sdfVector3_t codenameImagePos;
static void *Tmpnameone_obj;
static void *Tmpnametwo_obj;
static void *Tmpnamethree_obj;
static void *Tmpnamefour_obj;
static void *Tmpnamefive_obj;
static void *Tmpnamesix_obj;
static void *Tmpnameseven_obj;
static void *Tmpnameeight_obj;
static void *Tmpcodenameone_obj;
static void *Tmpcodenametwo_obj;
static void *Tmpcodenamethree_obj;
static void *Tmpcodenamefour_obj;
static void *Tmpcodenamefive_obj;
static void *Tmpcodenamesix_obj;
static void *Tmpcodenameseven_obj;
static void *Tmpcodenameeight_obj;
static char *kanjiIndexTmpText_str;
static char *kanjiIndexText_str;
static void *kanjiScrIndexTmpText;
static void *kanjiScrIndexText;
static char *kanjiIndexObj_str;
static void *kanjiIndexObj;
static void *kanjiIndexObj_anim;
static char *scrollindex_text;
static char *scrollindex_tmptext;
static void *kanjiIndexList;
static void *kanjiIndexTmpList;
static char *name_obj_str;
static char *tmpname_obj_str;
static void *name_obj;
static void *tmpname_obj;
static char *cname_obj_str;
static char *tmpcname_obj_str;
static void *cname_obj;
static void *tmpcname_obj;
static char *nameend_name_str;
static char *tmpnameend_name_str;
static void *nameend_name;
static void *tmpnameend_name;
static char *nameend_cname_str;
static char *tmpnameend_cname_str;
static void *nameend_cname;
static void *tmpnameend_cname;
static void *name_backloop;
static void *name_backloopAnime;
static char *name_underline_str;
static void *name_underline;
static char *cname_underline_str;
static void *cname_underline;
static char *kanaList_str;
static void *kanaList[4];
static void *kanaListTP[4];
static void *nametmptext_one;
static void *nametmptext_two;
static void *nametmptext_three;
static void *nametmptext_four;
static void *nametmptext_five;
static void *nametmptext_six;
static void *nametmptext_seven;
static void *nametmptext_eight;
static void *codenametmptext_one;
static void *codenametmptext_two;
static void *codenametmptext_three;
static void *codenametmptext_four;
static void *codenametmptext_five;
static void *codenametmptext_six;
static void *codenametmptext_seven;
static void *codenametmptext_eight;
static void *mojiColor;
static void *mojiColorTP;
static void *namedes_text;
static void *namedes_textTM;
static void *SeiText;
static void *SeiTextTM;
static void *SeiEndText;
static void *SeiEndTextTM;
static void *MeiText;
static void *MeiTextTM;
static void *MeiEndText;
static void *MeiEndTextTM;
static void *FullNameText;
static void *NickNameText;
static void *FullNameTextTM;
static void *NickNameTextTM;
static sdfVector3_t panel_cursorPos;
static char *cursor_str;
static char *ptext_str;
static char *ptext_str_null;
static s32 ptcnt;
static void *panel_text_tmp;
static void *panel_tmp;
static cmpCursorPos_t *cpos;
static void *tmpname;
static void *tmpcname;
static void *DelSky;
static void *DelCSky;
static void *DelCUI_maneger;
static void *DelUI_T_maneager;
static void *DelField;
static void *DelChar;
static void *DelCharY;
static void *DelCharF1;
static void *DelCharF2;
static void *DelEvent;
static void *DelFFCamera;
static void *DelSCamera;
static void *DelMCamera;
static void *DelStCamera;
static void *ButtonL;
static void *ButtonR;
static void *ButtonL_PS4;
static void *ButtonR_PS4;
static void *keyboardObj;
static ImeKeyboard *keyboardObj_a;
static s32 apoCnt;
static f32 apoPosAdj;
static bool apoflag;
static bool apoInitflag;
static bool apoUseflag[8];
static bool apoCalcflag[8];
static sdfVector3_t apoPos[8];
static sdfVector3_t apoPos_[8];
static bool apoEndInitflag;
static bool apoEndUseflag[8];
static bool apoEndCalcflag[8];
static sdfVector3_t apoEndPos[8];
static sdfVector3_t apoEndPos_[8];
static nmeData_t *GBWK;
static s8 nmeOfsEisuTbl[UNKNOWN_ARRAY_SIZE];
static s8 nmeOfsHiraTbl[4];
static s8 nmeOfsKataTbl[4];

void ButtonGuideDispSet(char *name, bool timer, bool empty, s32 waitTimer);
s32 CMP_X(s32 a);
s32 CMP_Y(s32 b);
void *GetoNameUI(void);
char *RepColTag(char *txt, void **LegacyParamArray);
bool evtBitCheck(s32 no);
void fclDrawParts(s32 X, s32 Y, u32 Z, u32 **pCol, u8 TblNo, u16 PartsNo, sdfTexHandle_t **pTexHandle, fclSprTblArry_t *pSprTblArry, u32 OtNo);
_FRQ *frDestroyFontRequestAfter(_FRQ *pFRQ);
s32 frDrawFontEx2(_FRQ *pFRQ, s8 Mode, u32 Ot);
_FRQ *frLinkFontString(char *pStr, s8 Style, s8 ColNo, s8 Tp, _FRQ *pFRQ);
void frSetDrawPosition(_FRQ *pFRQ, s32 X, s32 Y);
void frSetFontColor(_FRQ *pFRQ, u32 Color);
void frSetFontColorNo(_FRQ *pFRQ, u8 ColorNo);
void frSetPriority(_FRQ *pFRQ, u32 Pri);
void nmeChangeSelectCharColor(s32 X, s32 Y, u16 Line, s8 Column, _FRQ **pFRQ);
s8 nmeChkEntryType(nmeData_t **pData);
void nmeDrawInputBasePanel(s32 X, s32 Y, s32 Z);
void nmeDrawInputCName(s32 X, s32 Y, u32 Col, s32 Mode);
void nmeDrawInputHelpBasePanel(s32 X, s32 Y, s32 Z);
void nmeDrawInputListCapKan(s32 X, s32 Y, u32 Z, u32 OtNo);
void nmeDrawInputListHira(s32 X, s32 Y, u32 Z, s8 InputMode, u32 OtNo);
void nmeDrawInputListKan(s32 X, s32 Y, u32 Z, u32 OtNo);
void nmeDrawInputListPanel(void);
void nmeDrawInputName(s32 X1, s32 Y1, s32 X2, s32 Y2, u32 Col, s32 Mode);
void nmeDrawScrollBar(void);
void nmeDrawYesNoCursorBase(s32 X, s32 Y, u32 Z);
s8 nmeGetInputCharPos(nmeData_t **pData);

// 0xf1efe0
void DalateEventObject(void) {
  UnityEngine_GameObject_o *v2;
  struct UnityEngine_GameObject_o *v4;
  UnityEngine_Object_o *DelSky;
  UnityEngine_Object_o *DelCSky;
  UnityEngine_Object_o *DelUI_T_maneager;
  UnityEngine_Object_o *DelField;
  UnityEngine_Object_o *DelFFCamera;
  UnityEngine_Object_o *DelSCamera;
  UnityEngine_Object_o *DelChar;
  UnityEngine_Object_o *DelCharY;
  Il2CppObject *Component_object;
  UnityEngine_Object_o *DelMCamera;
  Il2CppObject *v41;
  Il2CppObject *v42;

  v2 = Find(StringLiteral_5594, 0);
  DelSky = v2;
  DelCSky = Find(StringLiteral_5595, 0);
  DelCUI_maneger = Find(StringLiteral_5596, 0);
  DelUI_T_maneager = Find(StringLiteral_5597, 0);
  DelField = Find(StringLiteral_5598, 0);
  DelChar = Find(StringLiteral_4879, 0);
  DelCharY = Find(StringLiteral_5599, 0);
  DelCharF1 = Find(StringLiteral_5600, 0);
  DelCharF2 = Find(StringLiteral_5601, 0);
  DelEvent = Find(StringLiteral_5602, 0);
  DelFFCamera = Find(StringLiteral_5603, 0);
  DelSCamera = Find(StringLiteral_5604, 0);
  v4 = Find(StringLiteral_5605, 0);
  DelMCamera = v4;
  if (op_Inequality(DelSky, 0, 0))
  {
    SetActive(DelSky, 0, 0);
  }
  if (op_Inequality(DelCSky, 0, 0))
  {
    SetActive(DelCSky, 0, 0);
  }
  if (op_Inequality(DelUI_T_maneager, 0, 0))
  {
    SetActive(DelUI_T_maneager, 0, 0);
  }
  if (op_Inequality(DelField, 0, 0))
  {
    SetActive(DelField, 0, 0);
  }
  if (op_Inequality(DelFFCamera, 0, 0))
  {
    SetActive(DelFFCamera, 0, 0);
  }
  if (op_Inequality(DelSCamera, 0, 0))
  {
    SetActive(DelSCamera, 0, 0);
  }
  if (op_Inequality(DelChar, 0, 0))
  {
    if (op_Inequality(DelCharY, 0, 0))
    {
      Component_object = GetComponent_object_(DelCharY);
      set_enabled(Component_object, 0);
    }
  }
  if (op_Inequality(DelMCamera, 0, 0))
  {
    v41 = GetComponent_object_(DelMCamera);
    set_enabled(v41, 0);
    v42 = GetComponent_object_(DelMCamera);
    set_enabled(v42, 0);
  }
}

// 0xf22610
void DefNameDraw(void) {
    GetoNameUI();
    evtBitCheck(0);
    RepColTag(0, 0);
}

// 0xf00bb0
s32 FCL_MAKE_COL(s32 r, s32 g, s32 b, u32 a) {
  return (g << 16) | (r << 24) | (b << 8) | a;
}

// 0xf20810
void ListCursorDispOff(void **obj) {
}

// 0xf20900
void MojiChack_apo(void) {
}

// 0xf1f680
void MojiPanelInit(void) {
}

// 0xf1cc40
void NameInit(void) {
    GetoNameUI();
}

// 0xf1e1b0
void NameInit2(void) {
    GetoNameUI();
    ButtonGuideDispSet(0, 0, 0, 0);
    RepColTag(0, 0);
}

// 0xf22280
void NameInputAnim(void) {
}

// 0xf23d20
void ReturnEventObject(void) {
  UnityEngine_Object_o *DelSky;
  UnityEngine_Object_o *DelCSky;
  UnityEngine_Object_o *DelUI_T_maneager;
  UnityEngine_Object_o *DelField;
  UnityEngine_Object_o *DelFFCamera;
  UnityEngine_Object_o *DelSCamera;
  UnityEngine_Object_o *DelChar;
  UnityEngine_Object_o *DelCharY;
  Il2CppObject *Component_object;
  UnityEngine_Object_o *DelMCamera;
  Il2CppObject *v37;
  Il2CppObject *v38;

  if (op_Inequality(DelSky, 0, 0))
  {
    SetActive(DelSky, 1, 0);
  }
  if (op_Inequality(DelCSky, 0, 0))
  {
    SetActive(DelCSky, 1, 0);
  }
  if (op_Inequality(DelUI_T_maneager, 0, 0))
  {
    SetActive(DelUI_T_maneager, 1, 0);
  }
  if (op_Inequality(DelField, 0, 0))
  {
    SetActive(DelField, 1, 0);
  }
  if (op_Inequality(DelFFCamera, 0, 0))
  {
    SetActive(DelFFCamera, 1, 0);
  }
  if (op_Inequality(DelSCamera, 0, 0))
  {
    SetActive(DelSCamera, 1, 0);
  }
  if (op_Inequality(DelChar, 0, 0))
  {
    if (op_Inequality(DelCharY, 0, 0))
    {
      Component_object = GetComponent_object_(DelCharY);
      set_enabled(Component_object, 1);
    }
  }
  if (op_Inequality(DelMCamera, 0, 0))
  {
    v37 = GetComponent_object_(DelMCamera);
    set_enabled(v37, 1);
    v38 = GetComponent_object_(DelMCamera);
    set_enabled(v38, 1);
  }
  EventObjDelateflag = 0;
}

// 0xf03380
void nmeChangeSelectCharColor(s32 X, s32 Y, u16 Line, s8 Column, _FRQ **pFRQ) {
  s8 CfmFlag;
  s8 FuncFlag;
  s8 ListCapFlag;
  cmpCursorInfo_t_o *ModeCursor;
  bool v22;
  u16 v25;
  struct cmpCursorInfo_t_array *CharCursor;
  cmpCursorInfo_t_o *v28;
  struct cmpCursorInfo_t_array *v31;
  cmpCursorInfo_t_o *v33;
  s32 v35;
  s32 v37;
  struct nmeData_t_o *GBWK;
  sdfTexHandle_t_array *Tex;
  fclSprTblArry_t_array *nmeSprTblArry;
  _FRQ_o *v44;

  CfmFlag = GBWK->CfmFlag;
  else if (ToBoolean_2953808(CfmFlag))
  {
    return;
  }
  FuncFlag = GBWK->FuncFlag;
  else if (ToBoolean_2953808(FuncFlag))
  {
    return;
  }
  ListCapFlag = GBWK->ListCapFlag;
  else if (ToBoolean_2953808(ListCapFlag))
  {
    return;
  }
  ModeCursor = GBWK->ModeCursor;
  v22 = cmpGetCursorIndex(ModeCursor) == 3;
  if (v22)
    v25 = 72;
  else
    v25 = 71;
  CharCursor = GBWK->CharCursor;
  v28 = CharCursor->m_Items[0];
  if (cmpGetCursorIndex(v28) == Line)
  {
    v31 = GBWK->CharCursor;
    v33 = v31->m_Items[1];
    if (cmpGetCursorIndex(v33) == Column)
    {
      v35 = CMP_X(X);
      v37 = CMP_Y(Y);
      Tex = GBWK->Tex;
      fclDrawParts(v35, v37, 0, 0, 0, v25, Tex, nmeSprTblArry, 0x47u);
      v44 = *pFRQ;
      frSetFontColor(v44, 0xFFD19280);
    }
  }
}

// 0xf06380
dds3ProcessFunc_t *nmeDraw(dds3ProcessID_t *PID) {
    return 0;
}

// 0xf05730
void nmeDrawFuncIcon(void) {
  struct nmeData_t_o *GBWK;
  cmpCursorInfo_t_o *FuncCursor;
  UnityEngine_Animator_o *namelist_buttonAnim_l;
  UnityEngine_Animator_o *namelist_buttonAnim_del;
  UnityEngine_Animator_o *namelist_buttonAnim_end;

  CMP_Y(60);
  if (GetInteger(namelist_buttonAnim_r, StringLiteral_5366))
  {
    SetInteger(namelist_buttonAnim_r, StringLiteral_5366, 0);
  }
  if (GetInteger(namelist_buttonAnim_l, StringLiteral_5366))
  {
    SetInteger(namelist_buttonAnim_l, StringLiteral_5366, 0);
  }
  if (GetInteger(namelist_buttonAnim_del, StringLiteral_5366))
  {
    SetInteger(namelist_buttonAnim_del, StringLiteral_5366, 0);
  }
  if (GetInteger(namelist_buttonAnim_end, StringLiteral_5366))
  {
    SetInteger(namelist_buttonAnim_end, StringLiteral_5366, 0);
  }
  else
  {
    if (!GBWK->FuncFlag)
      return;
  }
  else if (GBWK->CfmFlag)
  {
    return;
  }
  FuncCursor = GBWK->FuncCursor;
  switch (cmpGetCursorIndex(FuncCursor))
  {
    case 0:
      if (GetInteger(namelist_buttonAnim_r, StringLiteral_5366) != 1)
      {
        SetInteger(namelist_buttonAnim_r, StringLiteral_5366, 1);
      }
      if (!GetInteger(namelist_buttonAnim_l, StringLiteral_5366))
    case 1:
      if (GetInteger(namelist_buttonAnim_l, StringLiteral_5366) != 1)
      {
        SetInteger(namelist_buttonAnim_l, StringLiteral_5366, 1);
      }
      if (GetInteger(namelist_buttonAnim_r, StringLiteral_5366))
      {
        namelist_buttonAnim_l = namelist_buttonAnim_r;
        SetInteger(namelist_buttonAnim_l, StringLiteral_5366, 0);
      }
      if (!GetInteger(namelist_buttonAnim_del, StringLiteral_5366))
    case 2:
      if (GetInteger(namelist_buttonAnim_del, StringLiteral_5366) != 1)
      {
        SetInteger(namelist_buttonAnim_del, StringLiteral_5366, 1);
      }
      if (GetInteger(namelist_buttonAnim_r, StringLiteral_5366))
      {
        SetInteger(namelist_buttonAnim_r, StringLiteral_5366, 0);
      }
      if (!GetInteger(namelist_buttonAnim_l, StringLiteral_5366))
      namelist_buttonAnim_del = namelist_buttonAnim_l;
      SetInteger(namelist_buttonAnim_del, StringLiteral_5366, 0);
      if (!GetInteger(namelist_buttonAnim_end, StringLiteral_5366))
        return;
      SetInteger(namelist_buttonAnim_end, StringLiteral_5366, 0);
      break;
    case 3:
      if (GetInteger(namelist_buttonAnim_end, StringLiteral_5366) != 1)
      {
        SetInteger(namelist_buttonAnim_end, StringLiteral_5366, 1);
      }
      if (GetInteger(namelist_buttonAnim_r, StringLiteral_5366))
      {
        SetInteger(namelist_buttonAnim_r, StringLiteral_5366, 0);
      }
      if (GetInteger(namelist_buttonAnim_l, StringLiteral_5366))
      {
        SetInteger(namelist_buttonAnim_l, StringLiteral_5366, 0);
      }
      if (!GetInteger(namelist_buttonAnim_del, StringLiteral_5366))
        return;
      namelist_buttonAnim_end = namelist_buttonAnim_del;
    default:
      return;
  }
}

// 0xf05430
void nmeDrawInfo(s8 Type) {
  s32 v3;
  s32 v5;
  s32 v7;
  struct nmeData_t_o *v10;
  sdfTexHandle_t_array *v12;
  fclSprTblArry_t_array *v13;
  struct nmeData_t_o *GBWK;
  sdfTexHandle_t_array *Tex;
  fclSprTblArry_t_array *nmeSprTblArry;

  v3 = CMP_X(84);
  v7 = CMP_Y(123);
  nmeDrawInputHelpBasePanel(v3, v7, v5);
  if (Type < 2u)
  {
    Tex = GBWK->Tex;
    fclDrawParts(0, 0, 0, 0, 3u, 0x15u, Tex, nmeSprTblArry, 0x47u);
  }
  else if (Type == 2)
  {
    v10 = GBWK;
    v12 = v10->Tex;
    v13 = nmeSprTblArry;
    fclDrawParts(0, 0, 0, 0, 3u, 0x16u, v12, v13, 0x47u);
  }
}

// 0xf00c10
void nmeDrawInputBasePanel(s32 X, s32 Y, s32 Z) {
  struct nmeData_t_o *GBWK;
  sdfTexHandle_t_array *Tex;
  fclSprTblArry_t_array *nmeSprTblArry;

  Tex = GBWK->Tex;
  fclDrawParts(X, Y, 0, 0, 3u, 0x12u, Tex, nmeSprTblArry, 0x47u);
  fclDrawParts(X, Y, 0, 0, 3u, 0x13u, GBWK->Tex, nmeSprTblArry, 0x47u);
  fclDrawParts(X, Y, 0, 0, 3u, 0x14u, GBWK->Tex, nmeSprTblArry, 0x47u);
}

// 0xf018e0
void nmeDrawInputCName(s32 X, s32 Y, u32 Col, s32 Mode) {
  s8 InputCharPos;
  u64 *v10;
  s32 v11;
  s32 v12;
  s32 v13;
  s32 v16;
  s32 v17;
  s32 v18;
  s32 v20;
  Nme_Draw_c *v21;
  struct Nme_Draw_StaticFields *static_fields;
  sdfTexHandle_t_array *Tex;
  fclSprTblArry_t_array *nmeSprTblArry;
  s32 v26;
  u16 v27;
  s32 v28;
  s32 v30;
  sdfTexHandle_t_array *v32;
  fclSprTblArry_t_array *v34;
  u64 v35;
  s32 v36;
  _FRQ_o *v38;
  struct System_SByte_array *InputNums;
  struct System_Byte_array *InputCode;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;
  il2cpp_array_size_t v45;
  u8 v46;
  struct System_Byte_array *v48;
  Il2CppArrayBounds *v49;
  il2cpp_array_size_t v50;
  il2cpp_array_size_t v51;
  u8 v53;
  s32 v60;
  s32 v61;
  s32 v62;
  System_String_o *pStr;

  pStr = StringLiteral_368;
  InputCharPos = nmeGetInputCharPos(&GBWK);
  v10 = NewSpecific(byte, 2u);
  v11 = CMP_X(X - 54);
  v12 = CMP_Y(Y - 8);
  nmeDrawInputBasePanel(v11, v12, v13);
  v60 = Y;
  v16 = Y + 18;
  v17 = 0;
  v62 = X;
  if (Mode)
  {
    do
    {
      v18 = CMP_X(v62 + v17);
      v20 = CMP_Y(v16);
      static_fields = v21->static_fields;
      Tex = static_fields->GBWK->Tex;
      fclDrawParts(v18, v20, 0, 0, 0, 0x41u, Tex, nmeSprTblArry, 0x47u);
      v17 += 18;
    }
    while (v17 != 144);
  }
  else
  {
    v26 = X;
    v61 = InputCharPos;
    do
    {
      if (v61 == v17)
        v27 = 66;
      else
        v27 = 65;
      v28 = CMP_X(v26);
      v30 = CMP_Y(v16);
      v32 = GBWK->Tex;
      v34 = nmeSprTblArry;
      fclDrawParts(v28, v30, 0, 0, 0, v27, v32, v34, 0x47u);
      ++v17;
      v26 += 18;
    }
    while (v17 != 8);
  }
  v35 = 0;
  v36 = 16 * v62;
  {
  }
  while (1)
  {
    InputNums = GBWK->InputNums;
    if (v35 >= InputNums->m_Items[2])
      break;
    InputCode = GBWK->InputCode;
    bounds = InputCode->bounds;
    length = bounds[1].length;
    v45 = bounds[2].length;
    v46 = InputCode->m_Items[v45 * (v35 + 2 * length)];
    *(v10 + 32) = v46;
    v48 = GBWK->InputCode;
    v49 = v48->bounds;
    v50 = v49[1].length;
    v51 = v49[2].length;
    v53 = v48->m_Items[v51 * (v35 + 2 * v50) + 1];
    *(v10 + 33) = v53;
    v38 = frLinkFontString(pStr, 1, 0, 0, 0);
    frSetDrawPosition(v38, v36, 8 * v60);
    frSetFontColor(v38, Col);
    frSetPriority(v38, 0);
    frDrawFontEx2(v38, 0, 0x47u);
    frDestroyFontRequestAfter(v38);
    ++v35;
    v36 += 288;
  }
}

// 0xf02d40
void nmeDrawInputCaption(s8 Sel, u8 Flag) {
  u64 *v4;
  u64 *v6;
  u64 *v7;
  u32 v8;
  u64 *v9;
  System_Array_o *v11;
  System_Array_o *v13;
  System_Array_o *v15;
  u64 v18;
  u64 *v19;
  s64 v20;
  s64 v22;
  u32 v23;
  Nme_Draw_c *v24;
  u16 v25;
  Nme_Draw_c *v27;
  u16 v28;
  struct Nme_Draw_StaticFields *static_fields;
  sdfTexHandle_t_array *Tex;
  fclSprTblArry_t_array *nmeSprTblArry;
  s64 v34;
  s64 v37;
  struct Nme_Draw_StaticFields *v40;
  sdfTexHandle_t_array *v42;
  fclSprTblArry_t_array *v43;
  System_UInt32_array *v50;
  struct Nme_Draw_StaticFields *v51;
  sdfTexHandle_t_array *v53;
  fclSprTblArry_t_array *v54;
  System_UInt32_array *pCol;

  v4 = NewSpecific(uint, 1u);
  pCol = v4;
  *(v4 + 8) = 1077952640;
  v6 = NewSpecific(byte__, 4u);
  v7 = NewSpecific(byte, 3u);
  v8 = *(v7 + 6);
  v9 = v7;
  *(v7 + 32) = 19;
  *(v7 + 34) = 12;
  v6[4] = v9;
  v11 = NewSpecific(byte, 3u);
  InitializeArray_1543888(v11, Field__PrivateImplementationDetails__8D89A13646BCC06C9D06F2730FE55210C07D7C28);
  v6[5] = v11;
  v13 = NewSpecific(byte, 3u);
  InitializeArray_1543888(v13, Field__PrivateImplementationDetails__92DEE4ECC81D0AF22DEB52B5087F40A86A8D0278);
  v6[6] = v13;
  v15 = NewSpecific(byte, 3u);
  InitializeArray_1543888(v15, Field__PrivateImplementationDetails__93DCD800E45A3DFCDBB4B375F70EEC9CBC7C9825);
  v6[7] = v15;
  v18 = 0;
  v19 = v6 + 4;
  v20 = Sel & 0xFFFFFFFFLL;
  while (1)
  {
    v22 = v19[v18];
    v23 = *(v22 + 24);
    if (v20 == v18)
    {
      v25 = *(v22 + 32);
    }
    v28 = *(v22 + 33);
    static_fields = v27->static_fields;
    Tex = static_fields->GBWK->Tex;
    fclDrawParts(0, 0, 0, 0, 0, v28, Tex, nmeSprTblArry, 0x47u);
    if (Flag < 2u)
    {
      v37 = v19[v18];
      v25 = *(v37 + 34);
      v40 = v24->static_fields;
      v42 = v40->GBWK->Tex;
      v43 = nmeSprTblArry;
      fclDrawParts(0, 0, 0, 0, 0, v25, v42, v43, 0x47u);
    }
    if (Flag == 2)
      break;
    if (++v18 == 4)
      return;
  }
  v34 = v19[v18];
  v25 = *(v34 + 34);
  {
    v50 = pCol;
  }
  else
  {
    v50 = pCol;
  }
  v51 = v24->static_fields;
  v53 = v51->GBWK->Tex;
  v54 = nmeSprTblArry;
  fclDrawParts(0, 0, 0, v50, 0, v25, v53, v54, 0x47u);
}

// 0xf02630
void nmeDrawInputConfirm(void) {
  ;
}

// 0xf052a0
void nmeDrawInputHelpBasePanel(s32 X, s32 Y, s32 Z) {
  struct nmeData_t_o *GBWK;
  sdfTexHandle_t_array *Tex;
  fclSprTblArry_t_array *nmeSprTblArry;

  Tex = GBWK->Tex;
  fclDrawParts(X, Y, 0, 0, 3u, 0xFu, Tex, nmeSprTblArry, 0x47u);
  fclDrawParts(X, Y, 0, 0, 3u, 0x10u, GBWK->Tex, nmeSprTblArry, 0x47u);
  fclDrawParts(X, Y, 0, 0, 3u, 0x11u, GBWK->Tex, nmeSprTblArry, 0x47u);
}

// 0xf04d30
void nmeDrawInputList(void) {
  cmpCursorInfo_t_o *ModeCursor;
  s8 CursorIndex;
  u64 *v5;
  u64 *v6;
  u32 v7;
  u64 *v8;
  u64 *v10;
  u32 v11;
  u64 *v12;
  u64 *v15;
  u32 v16;
  u64 *v17;
  u64 *v20;
  u32 v21;
  u64 *v22;
  u32 v25;
  u32 v28;
  u64 *v30;
  s64 v31;
  u64 *v32;
  s64 v33;
  s32 v34;
  s32 v37;
  s32 v39;
  u32 v40;

  ModeCursor = GBWK->ModeCursor;
  CursorIndex = cmpGetCursorIndex(ModeCursor);
  v5 = NewSpecific(int__, 4u);
  v6 = NewSpecific(s32, 2u);
  v7 = *(v6 + 6);
  v8 = v6;
  *(v6 + 8) = 41;
  *(v6 + 9) = 218;
  v5[4] = v8;
  v10 = NewSpecific(s32, 2u);
  v11 = *(v10 + 6);
  v12 = v10;
  *(v10 + 8) = 41;
  *(v10 + 9) = 218;
  v5[5] = v12;
  v15 = NewSpecific(s32, 2u);
  v16 = *(v15 + 6);
  v17 = v15;
  *(v15 + 8) = 41;
  *(v15 + 9) = 218;
  v5[6] = v17;
  v20 = NewSpecific(s32, 2u);
  v21 = *(v20 + 6);
  v22 = v20;
  *(v20 + 8) = 75;
  *(v20 + 9) = 218;
  v28 = *(v5 + 6);
  v5[7] = v22;
  v30 = &v5[CursorIndex];
  v33 = v30[4];
  v32 = v30 + 4;
  v31 = v33;
  v34 = *(v31 + 32);
  v37 = *(*v32 + 36LL);
  if (CursorIndex == 3)
  {
    nmeDrawInputListKan(v34, v37, 0, v25);
    nmeDrawScrollBar();
    nmeDrawInputListCapKan(v39, *(*v32 + 36LL), 0, v40);
  }
  else
  {
    nmeDrawInputListHira(v34, v37, 0, CursorIndex);
  }
}

// 0xf040a0
void nmeDrawInputListCapKan(s32 X, s32 Y, u32 Z, u32 OtNo) {
  System_String_o *v7;
  u64 *v9;
  struct cmpCursorInfo_t_array *CharCursor;
  s16 Index;
  s32 ShiftMax;
  s32 v14;
  s32 v15;
  struct System_SByte_array *nmeTblList;
  struct System_SByte_array *v21;
  s32 v27;
  sdfTexHandle_t_array *Tex;
  fclSprTblArry_t_array *nmeSprTblArry;
  s32 v33;
  sdfTexHandle_t_array *v35;
  fclSprTblArry_t_array *v37;
  _FRQ_o *v38;
  u32 Pri;

  v7 = StringLiteral_368;
  v9 = NewSpecific(sbyte, 3u);
  CharCursor = GBWK->CharCursor;
  Index = CharCursor->m_Items[0]->CursorPos->Index;
  ShiftMax = CharCursor->m_Items[0]->CursorPos->ShiftMax;
  if (ShiftMax >= 1)
  {
    Pri = 16 * Z;
    v14 = 0;
    v15 = 8 * Y;
    do
    {
      *(v9 + 32) = nmeTblList->m_Items[3] + 32 * Index;
      v21 = nmeTblList;
      *(v9 + 33) = ((32 * Index) | 1) + v21->m_Items[3];
      if (get_Chars(v7, 0) != 128 || get_Chars(v7, 1) != 128)
      {
        if (GBWK->ListCapFlag)
        {
          v27 = CMP_Y(v14);
          Tex = GBWK->Tex;
          fclDrawParts(0, v27, 0, 0, 1u, 0x17u, Tex, nmeSprTblArry, 0x47u);
        }
        else
        {
          v33 = CMP_Y(v14);
          v35 = GBWK->Tex;
          v37 = nmeSprTblArry;
          fclDrawParts(0, v33, 0, 0, 1u, 0x16u, v35, v37, 0x47u);
        }
      }
      v38 = frLinkFontString(v7, 1, 0, 0, 0);
      frSetDrawPosition(v38, 688, v15);
      frSetPriority(v38, Pri);
      else if (GBWK->ListCapFlag)
      {
        frSetFontColor(v38, 0xFFD19280);
      }
      frDrawFontEx2(v38, 0, 0x47u);
      frDestroyFontRequestAfter(v38);
      v15 += 240;
      v14 += 30;
      --ShiftMax;
      LOBYTE(Index) = Index + 1;
    }
    while (ShiftMax);
  }
}

// 0xf037b0
void nmeDrawInputListHira(s32 X, s32 Y, u32 Z, s8 InputMode, u32 OtNo) {
  u64 *v9;
  u32 v11;
  u64 *v12;
  s32 v15;
  struct cmpCursorInfo_t_array *CharCursor;
  s32 v18;
  s32 v19;
  u32 v20;
  s32 v21;
  _FRQ_o *v22;
  s32 v23;
  s32 v26;
  s32 v28;
  s32 v29;
  s32 v31;
  sdfTexHandle_t_array *Tex;
  s32 v35;
  fclSprTblArry_t_array *nmeSprTblArry;
  s32 v37;
  u32 v40;
  struct System_String_array_array *nmeTblList24;
  System_String_array *v43;
  System_String_o *v45;
  s32 ShiftMax;
  u32 Pri;
  s32 v49;
  s32 v50;
  u64 *v51;
  u16 Line[2];
  s32 v54;
  s32 v55;
  char *v56;
  _FRQ_o *pFRQ;

  pFRQ = 0;
  v9 = NewSpecific(sbyte, 3u);
  v11 = *(v9 + 6);
  v12 = v9;
  *(v9 + 32) = 1;
  *(v9 + 33) = 1;
  if (InputMode == 2)
    v15 = 23;
  else
    v15 = 22;
  v55 = v15;
  CharCursor = GBWK->CharCursor;
  ShiftMax = CharCursor->m_Items[0]->CursorPos->ShiftMax;
  if (ShiftMax >= 1)
  {
    v56 = v12 + InputMode + 32;
    v50 = 16 * X;
    v51 = v12;
    v49 = 8 * Y;
    v54 = 0;
    v18 = 0;
    Pri = 16 * Z;
    do
    {
      v19 = 0;
      v20 = 0;
      v21 = 30 * v18;
      *Line = v18;
      while (1)
      {
        v26 = *v56;
        if (v20 >= 16 - v26)
          break;
        if (InputMode == 2)
          v28 = v20 * v55;
        else
          v28 = v19 + ((4 * ((3435973837u * v20) >> 32)) & 0xFFFFFFF0);
        v29 = CMP_X(v28);
        v31 = CMP_Y(v21);
        Tex = GBWK->Tex;
        v35 = v54 + v26;
        v37 = v35 + v20;
        fclDrawParts(v29, v31, 0, 0, 0, 0x2Bu, Tex, nmeSprTblArry, 0x47u);
        v40 = 2 * v37;
        v43 = nmeTblList24->m_Items[InputMode];
        v45 = v43->m_Items[v40];
        v22 = frLinkFontString(v45, 4, 0, 0, 0);
        pFRQ = v22;
        frSetDrawPosition(v22, v50, v49);
        frSetPriority(v22, Pri);
        v23 = v28;
        v18 = *Line;
        nmeChangeSelectCharColor(v23, v21, Line[0], v20, &pFRQ);
        frDrawFontEx2(v22, 0, 0x47u);
        frDestroyFontRequestAfter(v22);
        v12 = v51;
        ++v20;
        v19 += v55;
        if (InputMode >= *(v51 + 6))
      }
      v54 += 16;
      ++v18;
    }
    while (v18 != ShiftMax);
  }
}

// 0xf03c60
void nmeDrawInputListKan(s32 X, s32 Y, u32 Z, u32 OtNo) {
  u64 *v9;
  struct cmpCursorInfo_t_array *CharCursor;
  s32 v12;
  char v13;
  s32 v14;
  u16 v15;
  s32 v16;
  s32 v18;
  sdfTexHandle_t_array *Tex;
  fclSprTblArry_t_array *nmeSprTblArry;
  struct System_SByte_array *nmeTblList;
  char v27;
  char v28;
  struct System_SByte_array *v30;
  char v32;
  _FRQ_o *v34;
  s32 ShiftMax;
  s16 Index;
  s32 v39;
  s32 v40;
  s32 v41;
  System_String_o *pStr;
  _FRQ_o *pFRQ;

  pFRQ = 0;
  pStr = StringLiteral_368;
  v9 = NewSpecific(sbyte, 3u);
  CharCursor = GBWK->CharCursor;
  Index = CharCursor->m_Items[0]->CursorPos->Index;
  ShiftMax = CharCursor->m_Items[0]->CursorPos->ShiftMax;
  if (ShiftMax >= 1)
  {
    v41 = 16 * X;
    v40 = 8 * Y;
    v12 = 0;
    v13 = 16 * Index;
    do
    {
      v14 = 0;
      v39 = v12;
      v15 = v12 + Index;
      do
      {
        v16 = CMP_X(0);
        v18 = CMP_Y(0);
        Tex = GBWK->Tex;
        fclDrawParts(v16, v18, 0, 0, 0, 0x3Au, Tex, nmeSprTblArry, 0x47u);
        v27 = 2 * (v13 + v14) + 2;
        v28 = nmeTblList->m_Items[3] + v27;
        *(v9 + 32) = v28;
        v30 = nmeTblList;
        v32 = (v27 | 1) + v30->m_Items[3];
        *(v9 + 33) = v32;
        v34 = frLinkFontString(pStr, 4, 0, 0, 0);
        pFRQ = v34;
        frSetDrawPosition(v34, v41, v40);
        frSetPriority(v34, 16 * Z);
        nmeChangeSelectCharColor(0, 0, v15, v14, &pFRQ);
        frDrawFontEx2(v34, 0, 0x47u);
        frDestroyFontRequestAfter(v34);
        ++v14;
      }
      while (v14 != 15);
      v13 += 16;
      v12 = v39 + 1;
    }
    while (v39 + 1 != ShiftMax);
  }
}

// 0xf02640
void nmeDrawInputListPanel(void) {
  System_UInt32_array *v2;
  struct nmeData_t_o *GBWK;
  sdfTexHandle_t_array *Tex;
  fclSprTblArry_t_array *nmeSprTblArry;
  il2cpp_array_size_t max_length;

  v2 = NewSpecific(uint, 4u);
  Tex = GBWK->Tex;
  fclDrawParts(0, 0, 0, 0, 3u, 5u, Tex, nmeSprTblArry, 0x47u);
  fclDrawParts(0, 0, 0, 0, 3u, 6u, GBWK->Tex, nmeSprTblArry, 0x47u);
  fclDrawParts(0, 0, 0, 0, 3u, 7u, GBWK->Tex, nmeSprTblArry, 0x47u);
  fclDrawParts(0, 0, 0, 0, 3u, 8u, GBWK->Tex, nmeSprTblArry, 0x47u);
  fclDrawParts(0, 0, 0, 0, 3u, 9u, GBWK->Tex, nmeSprTblArry, 0x47u);
  fclDrawParts(0, 0, 0, 0, 3u, 0xAu, GBWK->Tex, nmeSprTblArry, 0x47u);
  fclDrawParts(0, 0, 0, 0, 3u, 0xBu, GBWK->Tex, nmeSprTblArry, 0x47u);
  fclDrawParts(0, 0, 0, 0, 3u, 0xCu, GBWK->Tex, nmeSprTblArry, 0x47u);
  max_length = v2->max_length;
  v2->m_Items[0] = -2139062189;
  v2->m_Items[1] = -2139062189;
  v2->m_Items[2] = v2->m_Items[0];
  v2->m_Items[3] = v2->m_Items[0];
  fclDrawParts(0, 0, 0, v2, 3u, 0xDu, GBWK->Tex, nmeSprTblArry, 0x47u);
  fclDrawParts(0, 0, 0, v2, 3u, 0xEu, GBWK->Tex, nmeSprTblArry, 0x47u);
}

// 0xf00da0
void nmeDrawInputName(s32 X1, s32 Y1, s32 X2, s32 Y2, u32 Col, s32 Mode) {
  s8 InputCharPos;
  u64 *v10;
  s32 v11;
  s32 v12;
  s32 v13;
  s32 v16;
  u16 v17;
  bool v18;
  s32 v19;
  s32 v21;
  sdfTexHandle_t_array *Tex;
  fclSprTblArry_t_array *nmeSprTblArry;
  s32 v26;
  s32 i;
  u16 v28;
  s32 v30;
  s32 v32;
  sdfTexHandle_t_array *v34;
  fclSprTblArry_t_array *v36;
  s32 v37;
  s32 v39;
  sdfTexHandle_t_array *v41;
  fclSprTblArry_t_array *v43;
  s32 v45;
  u64 v46;
  _FRQ_o *v48;
  struct System_SByte_array *InputNums;
  struct System_Byte_array *InputCode;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;
  u8 v55;
  struct System_Byte_array *v56;
  Il2CppArrayBounds *v57;
  il2cpp_array_size_t v58;
  u8 v60;
  s32 v68;
  s32 v70;
  sdfTexHandle_t_array *v72;
  fclSprTblArry_t_array *v74;
  u64 v76;
  s32 v77;
  _FRQ_o *v79;
  struct System_SByte_array *v80;
  struct System_Byte_array *v83;
  Il2CppArrayBounds *v84;
  il2cpp_array_size_t v85;
  il2cpp_array_size_t v86;
  u8 v87;
  struct System_Byte_array *v89;
  Il2CppArrayBounds *v90;
  il2cpp_array_size_t v91;
  il2cpp_array_size_t v92;
  u8 v94;
  s32 v101;
  s32 v106;
  System_String_o *pStr;

  pStr = StringLiteral_368;
  InputCharPos = nmeGetInputCharPos(&GBWK);
  v10 = NewSpecific(byte, 2u);
  v11 = CMP_X(X1 - 37);
  v12 = CMP_Y(Y1 - 4);
  nmeDrawInputBasePanel(v11, v12, v13);
  v16 = 0;
  v106 = InputCharPos;
  v101 = X1;
  do
  {
    if (Mode)
    {
      v17 = 8;
    }
    else
    {
      if (nmeChkEntryType(&GBWK))
        v18 = 0;
      else
        v18 = v106 == v16;
      if (v18)
        v17 = 9;
      else
        v17 = 8;
    }
    v19 = CMP_X(X1);
    v21 = CMP_Y(Y1 + 22);
    Tex = GBWK->Tex;
    fclDrawParts(v19, v21, 0, 0, 0, v17, Tex, nmeSprTblArry, 0x47u);
    ++v16;
    X1 += 21;
  }
  while (v16 != 4);
  v26 = X2;
  for (i = 0; i != 4; ++i)
  {
    if (Mode)
    {
      v28 = 8;
    }
    else
    {
      if (nmeChkEntryType(&GBWK) == 1 && v106 == i)
        v28 = 9;
      else
        v28 = 8;
    }
    v30 = CMP_X(v26);
    v32 = CMP_Y(Y2 + 22);
    v34 = GBWK->Tex;
    v36 = nmeSprTblArry;
    fclDrawParts(v30, v32, 0, 0, 0, v28, v34, v36, 0x47u);
    v26 += 21;
  }
  v37 = CMP_X(v101 - 19);
  v39 = CMP_Y(Y1 + 9);
  v41 = GBWK->Tex;
  v43 = nmeSprTblArry;
  fclDrawParts(v37, v39, 0, 0, 0, 0x11u, v41, v43, 0x47u);
  v45 = 16 * v101;
  v46 = 0;
  {
  }
  while (1)
  {
    InputNums = GBWK->InputNums;
    if (v46 >= InputNums->m_Items[0])
      break;
    InputCode = GBWK->InputCode;
    bounds = InputCode->bounds;
    length = bounds[2].length;
    v55 = InputCode->m_Items[length * v46];
    *(v10 + 32) = v55;
    v56 = GBWK->InputCode;
    v57 = v56->bounds;
    v58 = v57[2].length;
    v60 = v56->m_Items[v58 * v46 + 1];
    *(v10 + 33) = v60;
    v48 = frLinkFontString(pStr, 4, 0, 0, 0);
    frSetDrawPosition(v48, v45, 8 * Y1);
    frSetFontColor(v48, Col);
    frSetPriority(v48, 0);
    frDrawFontEx2(v48, 0, 0x47u);
    frDestroyFontRequestAfter(v48);
    ++v46;
    v45 += 336;
  }
  v68 = CMP_X(X2 - 19);
  v70 = CMP_Y(Y2 + 9);
  v72 = GBWK->Tex;
  v74 = nmeSprTblArry;
  fclDrawParts(v68, v70, 0, 0, 0, 0x12u, v72, v74, 0x47u);
  v76 = 0;
  v77 = 16 * X2;
  {
  }
  while (1)
  {
    v80 = GBWK->InputNums;
    if (v76 >= v80->m_Items[1])
      break;
    v83 = GBWK->InputCode;
    v84 = v83->bounds;
    v85 = v84[1].length;
    v86 = v84[2].length;
    v87 = v83->m_Items[v86 * (v76 + v85)];
    *(v10 + 32) = v87;
    v89 = GBWK->InputCode;
    v90 = v89->bounds;
    v91 = v90[1].length;
    v92 = v90[2].length;
    v94 = v89->m_Items[v92 * (v76 + v91) + 1];
    *(v10 + 33) = v94;
    v79 = frLinkFontString(pStr, 4, 0, 0, 0);
    frSetDrawPosition(v79, v77, 8 * Y2);
    frSetFontColor(v79, Col);
    frSetPriority(v79, 0);
    frDrawFontEx2(v79, 0, 0x47u);
    frDestroyFontRequestAfter(v79);
    ++v76;
    v77 += 336;
  }
}

// 0xf05f80
void nmeDrawInputPanel(void) {
  s32 v4;
  s32 v6;
  sdfTexHandle_t_array *Tex;
  fclSprTblArry_t_array *nmeSprTblArry;
  s32 v10;
  s32 v11;
  s32 v12;
  s32 v13;
  s32 v14;
  s32 v15;
  s32 v16;
  s32 v17;
  s32 v18;
  s32 v19;
  s32 v20;
  s32 v21;
  s32 v22;

  nmeDrawInputListPanel();
  v4 = CMP_X(228);
  v6 = CMP_Y(412);
  Tex = GBWK->Tex;
  fclDrawParts(v4, v6, 0, 0, 3u, 3u, Tex, nmeSprTblArry, 0x47u);
  v10 = CMP_X(228);
  v11 = CMP_Y(412);
  fclDrawParts(v10, v11, 0, 0, 3u, 4u, GBWK->Tex, nmeSprTblArry, 0x47u);
  v12 = CMP_X(309);
  v13 = CMP_Y(412);
  fclDrawParts(v12, v13, 0, 0, 3u, 3u, GBWK->Tex, nmeSprTblArry, 0x47u);
  v14 = CMP_X(309);
  v15 = CMP_Y(412);
  fclDrawParts(v14, v15, 0, 0, 3u, 4u, GBWK->Tex, nmeSprTblArry, 0x47u);
  v16 = CMP_X(390);
  v17 = CMP_Y(412);
  fclDrawParts(v16, v17, 0, 0, 3u, 3u, GBWK->Tex, nmeSprTblArry, 0x47u);
  v18 = CMP_X(390);
  v19 = CMP_Y(412);
  fclDrawParts(v18, v19, 0, 0, 3u, 4u, GBWK->Tex, nmeSprTblArry, 0x47u);
  v20 = CMP_X(50);
  fclDrawParts(v20, 0, 0, 0, 0, 0x25u, GBWK->Tex, nmeSprTblArry, 0x47u);
  v21 = CMP_X(50);
  fclDrawParts(v21, 0, 0, 0, 0, 0x26u, GBWK->Tex, nmeSprTblArry, 0x47u);
  v22 = CMP_X(50);
  fclDrawParts(v22, 0, 0, 0, 0, 0x27u, GBWK->Tex, nmeSprTblArry, 0x47u);
}

// 0xf05630
void nmeDrawInputUBar(s8 Type) {
  if (Type < 2u)
  {
    nmeDrawInputName(155, 150, 267, 150, 0xA09DC380, 0);
  }
  else if (Type == 2)
  {
    nmeDrawInputName(62, 84, 174, 84, 0x5A503980u, 1);
    nmeDrawInputCName(172, 154, 0xA09DC380, 0);
  }
}

// 0xf02ac0
void nmeDrawLRCursor(void) {
  struct nmeData_t_o *GBWK;
  sdfTexHandle_t_array *Tex;
  fclSprTblArry_t_array *nmeSprTblArry;

  Tex = GBWK->Tex;
  fclDrawParts(0, 0, 0, 0, 3u, 0, Tex, nmeSprTblArry, 0x47u);
  fclDrawParts(0, 0, 0, 0, 3u, 1u, GBWK->Tex, nmeSprTblArry, 0x47u);
  fclDrawParts(0, 0, 0, 0, 3u, 2u, GBWK->Tex, nmeSprTblArry, 0x47u);
  fclDrawParts(0, 0, 0, 0, 0, 4u, GBWK->Tex, nmeSprTblArry, 0x47u);
  fclDrawParts(0, 0, 0, 0, 0, 5u, GBWK->Tex, nmeSprTblArry, 0x47u);
  fclDrawParts(0, 0, 0, 0, 0, 0xBu, GBWK->Tex, nmeSprTblArry, 0x47u);
  fclDrawParts(0, 0, 0, 0, 0, 0x10u, GBWK->Tex, nmeSprTblArry, 0x47u);
}

// 0xf04620
void nmeDrawScrollBar(void) {
  s8 ListCapFlag;
  s32 v6;
  struct nmeData_t_o *GBWK;
  sdfTexHandle_t_array *Tex;
  fclSprTblArry_t_array *nmeSprTblArry;
  s32 v12;
  s32 v15;
  struct nmeData_t_o *v17;
  sdfTexHandle_t_array *v19;
  fclSprTblArry_t_array *v20;
  s32 v21;
  s32 v22;
  struct cmpCursorInfo_t_array *CharCursor;
  s32 v26;
  s32 v29;
  struct nmeData_t_o *v31;
  sdfTexHandle_t_array *v33;
  fclSprTblArry_t_array *v34;
  s32 v37;
  struct nmeData_t_o *v39;
  sdfTexHandle_t_array *v41;
  fclSprTblArry_t_array *v42;
  struct cmpCursorInfo_t_array *v44;
  s32 v46;
  s32 v49;
  struct nmeData_t_o *v51;
  sdfTexHandle_t_array *v53;
  fclSprTblArry_t_array *v54;
  s32 v56;
  struct nmeData_t_o *v58;
  sdfTexHandle_t_array *v60;
  fclSprTblArry_t_array *v61;

  ListCapFlag = GBWK->ListCapFlag;
  if (ToBoolean_2953808(ListCapFlag))
  {
    v6 = CMP_X(-34);
    Tex = GBWK->Tex;
    fclDrawParts(v6, 0, 0, 0, 0, 0x38u, Tex, nmeSprTblArry, 0x47u);
    v12 = CMP_X(-34);
    fclDrawParts(v12, 0, 0, 0, 0, 0x39u, GBWK->Tex, nmeSprTblArry, 0x47u);
  }
  else
  {
    v15 = CMP_X(-34);
    v17 = GBWK;
    v19 = v17->Tex;
    v20 = nmeSprTblArry;
    fclDrawParts(v15, 0, 0, 0, 0, 0x3Bu, v19, v20, 0x47u);
    v21 = CMP_X(-34);
    fclDrawParts(v21, 0, 0, 0, 0, 0x3Cu, GBWK->Tex, nmeSprTblArry, 0x47u);
    v22 = CMP_X(-34);
    fclDrawParts(v22, 0, 0, 0, 0, 0x3Du, GBWK->Tex, nmeSprTblArry, 0x47u);
  }
  CharCursor = GBWK->CharCursor;
  v26 = CharCursor->m_Items[0]->CursorPos->Index == 0;
  if (ToBoolean_2953872(v26))
  {
    v29 = CMP_X(-34);
    v31 = GBWK;
    v33 = v31->Tex;
    v34 = nmeSprTblArry;
    fclDrawParts(v29, 0, 0, 0, 0, 0x34u, v33, v34, 0x47u);
  }
  else
  {
    v37 = CMP_X(-34);
    v39 = GBWK;
    v41 = v39->Tex;
    v42 = nmeSprTblArry;
    fclDrawParts(v37, 0, 0, 0, 0, 0x35u, v41, v42, 0x47u);
  }
  v44 = GBWK->CharCursor;
  v46 = v44->m_Items[0]->CursorPos->ShiftMax + v44->m_Items[0]->CursorPos->Index == v44->m_Items[0]->CursorPos->ListNums;
  if (ToBoolean_2953872(v46))
  {
    v49 = CMP_X(-34);
    v51 = GBWK;
    v53 = v51->Tex;
    v54 = nmeSprTblArry;
    fclDrawParts(v49, 0, 0, 0, 0, 0x36u, v53, v54, 0x47u);
  }
  else
  {
    v56 = CMP_X(-34);
    v58 = GBWK;
    v60 = v58->Tex;
    v61 = nmeSprTblArry;
    fclDrawParts(v56, 0, 0, 0, 0, 0x37u, v60, v61, 0x47u);
  }
}

// 0xf02200
void nmeDrawYesNo(s8 Pos) {
  u64 *v4;
  System_String_o *v8;
  _FRQ_o *v9;
  _FRQ_o *v11;
  _FRQ_o *v17;

  v4 = NewSpecific(string, 3u);
  v4[4] = StringLiteral_5365;
  v4[5] = StringLiteral_5175;
  v4[6] = StringLiteral_5176;
  v8 = v4[4];
  v9 = frLinkFontString(v8, 0, 0, 0, 0);
  frSetDrawPosition(v9, 9600, 5600);
  frSetPriority(v9, 0xFF0u);
  frDrawFontEx2(v9, 0, 0x47u);
  frDestroyFontRequestAfter(v9);
  v11 = frLinkFontString(v4[5], 0, 0, 0, 0);
  frSetDrawPosition(v11, 9600, 6400);
  frSetFontColorNo(v11, 1u);
  nmeDrawYesNoCursorBase(9552, 6416, 0xFFu);
  {
  }
  frSetPriority(v11, 0xFF0u);
  frDrawFontEx2(v11, 0, 0x47u);
  frDestroyFontRequestAfter(v11);
  v17 = frLinkFontString(v4[6], 0, 0, 0, 0);
  frSetDrawPosition(v17, 9600, 6880);
  if (Pos == 1)
  {
    frSetFontColorNo(v17, 1u);
    nmeDrawYesNoCursorBase(9552, 6888, 0xFFu);
  }
  frSetPriority(v17, 0xFF0u);
  frDrawFontEx2(v17, 0, 0x47u);
  frDestroyFontRequestAfter(v17);
}

// 0xf02060
void nmeDrawYesNoCursorBase(s32 X, s32 Y, u32 Z) {
}

// 0xf01ee0
void nmeDrawYesNoPanel(void) {
  u64 *v1;
  s64 v2;

  v1 = NewSpecific(uint, 4u);
  v2 = v1[3];
  *(v1 + 8) = -2139062151;
  *(v1 + 9) = -2139062151;
  *(v1 + 10) = *(v1 + 8);
  *(v1 + 11) = *(v1 + 8);
}
