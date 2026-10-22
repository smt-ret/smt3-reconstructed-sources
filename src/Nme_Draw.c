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
static char *defname;
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
static s8 *nmeOfsEisuTbl;
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

  v2 = Find("FieldFilter", 0);
  DelSky = v2;
  DelCSky = Find("Canvas_UI/Sky", 0);
  DelCUI_maneger = Find("Canvas_UI/UIManager", 0);
  DelUI_T_maneager = Find("Canvas_UI/UIManager/Text", 0);
  DelField = Find("Field", 0);
  DelChar = Find("Character", 0);
  DelCharY = Find("Character/npc_yuuko_e601", 0);
  DelCharF1 = Find("Character/e601flash01", 0);
  DelCharF2 = Find("Character/e601flash02", 0);
  DelEvent = Find("EventSystem", 0);
  DelFFCamera = Find("FieldFilterCamera", 0);
  DelSCamera = Find("ShadowCameras", 0);
  v4 = Find("Main Camera", 0);
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
  UnityEngine_GameObject_o *inited;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v6;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  s32 char_sel;
  System_String_o *v12;
  UnityEngine_Animator_o *v13;
  s32 v14;
  bool v15;
  s32 Integer;
  Nme_Draw_c *v19;
  struct System_String_array *v20;
  struct System_String_array *v24;
  struct System_String_array *tblDefName;
  s64 *v28;
  struct System_String_array *v31;
  struct System_String_array *v33;
  s64 v34;
  s64 *v36;
  struct System_String_array *defname;
  struct System_String_array *nameTMPStr2;
  u64 v104;
  s32 v106;
  struct System_String_array *cnameTMPStr;
  struct System_String_array *nameTMPStr;
  s64 *v113;
  u32 *v114;
  s64 *v117;
  u32 *v118;
  struct System_String_array *v121;
  s64 *v124;
  u32 *v125;
  u64 v128;
  u64 *v129;
  System_String_o *v130;
  struct System_String_o *v131;
  UnityEngine_Transform_o *v133;
  UnityEngine_Component_o *v134;
  struct UnityEngine_GameObject_o *v135;
  u64 *v137;
  System_String_o *v138;
  struct System_String_o *v139;
  UnityEngine_Transform_o *v141;
  UnityEngine_Component_o *v142;
  struct UnityEngine_GameObject_o *v143;
  Il2CppObject *v145;
  u32 *v149;
  s64 *text;
  struct System_String_array *v152;
  s64 *v155;
  u32 *v156;
  u64 *v159;
  System_String_o *v160;
  struct System_String_o *v161;
  UnityEngine_Transform_o *v163;
  UnityEngine_Component_o *v164;
  struct UnityEngine_GameObject_o *v165;
  Il2CppObject *v167;
  s64 *v172;
  s64 v173;
  s32 v174;
  u64 v177;
  u64 *v178;
  System_String_o *v179;
  struct System_String_o *v180;
  u64 *v182;
  System_String_o *v183;
  struct System_String_o *v184;
  u64 *v186;
  System_String_o *v187;
  struct System_String_o *v188;
  u64 *v190;
  System_String_o *v191;
  struct System_String_o *v192;
  UnityEngine_Transform_o *v194;
  UnityEngine_Component_o *v195;
  struct UnityEngine_GameObject_o *v196;
  UnityEngine_Transform_o *v198;
  UnityEngine_Component_o *v199;
  struct UnityEngine_GameObject_o *v200;
  UnityEngine_Transform_o *v202;
  UnityEngine_Component_o *v203;
  struct UnityEngine_GameObject_o *v204;
  UnityEngine_Transform_o *v206;
  UnityEngine_Component_o *v207;
  struct UnityEngine_GameObject_o *v208;
  Il2CppObject *v210;
  Il2CppObject *v211;
  struct System_String_array *v212;
  TMPro_TMP_Text_o *v213;
  System_String_o *v215;
  s64 *v216;
  System_Object_array *v217;
  System_Object_array *v218;
  s64 *v219;
  s64 *v221;
  System_String_o *v223;
  struct System_String_array *v224;
  System_String_o *v226;
  System_Object_array *v227;
  System_Object_array *v228;
  s64 *v229;
  s64 *v230;
  System_String_o *v232;
  u32 v233;
  s32 v234;
  s32 v235;
  s32 nameend_cnamenum;
  s32 nameend_namenum;
  s32 bup_cnamenum;
  s32 bup_namenum;

  inited = GetoNameUI();
  NameUIObj = inited;
  defname = 0;
  transform = get_transform(NameUIObj, 0);
  v6 = Find(transform, "namechara", 0);
  gameObject = get_gameObject(v6);
  Component_object = GetComponent_object_(gameObject);
  if (char_sel)
  {
    else if (char_sel == 1)
    {
      goto LABEL_13;
    }
    else if (char_sel == 2)
    {
      goto LABEL_24;
    }
    if (char_sel == 3 && GetInteger(Component_object, "namechara") != 3)
    {
      v12 = "namechara";
      v13 = Component_object;
      v14 = 3;
      goto LABEL_33;
    }
    goto LABEL_34;
  }
  v15 = evtBitCheck(2224);
  Integer = GetInteger(Component_object, "namechara");
  if (v15)
  {
    if (Integer != 4)
    {
      v12 = "namechara";
      v13 = Component_object;
      v14 = 4;
      goto LABEL_33;
    }
  }
  else if (Integer)
  {
    v12 = "namechara";
    v13 = Component_object;
    v14 = 0;
    goto LABEL_33;
  }
LABEL_34:
  if (char_sel)
  {
    else if (defname)
    {
      goto LABEL_41;
    }
    v20 = NewSpecific(string, 2u);
    defname = v20;
    v24 = defname;
    v28 = tblDefName->m_Items[3 * char_sel];
    v24->m_Items[0] = v28;
    v31 = defname;
    v33 = tblDefName;
    v34 = 3LL * char_sel + 1;
    v36 = v33->m_Items[v34];
    v31->m_Items[1] = v36;
    defnameflag = 0;
    if ((v19->_2.bitflags2 & 2) == 0)
      goto LABEL_67;
    goto LABEL_42;
  }
LABEL_177:
  if (defname)
  {
    v104 = 0;
    do
    {
      if ((*&v19->_2.bitflags1 & 0x200) != 0)
      {
        else
        {
          if (codenmeflag)
          {
LABEL_185:
            else
            {
              if (v104 >= LODWORD(cnameTMPStr->max_length))
                goto LABEL_204;
            }
            if (cnameTMPStr->m_Items[v104])
            {
                goto LABEL_190;
              goto LABEL_221;
            }
            else
            {
              v113 = "";
              v114 = cnameTMPStr;
              if ("")
              {
LABEL_208:
              }
            }
            *&v114[2 * v104 + 8] = "";
            {
LABEL_190:
            }
LABEL_221:
            v121 = nameTMPStr2;
            if (v121->m_Items[v104])
            {
                goto LABEL_224;
              goto LABEL_236;
            }
            else
            {
              v124 = "";
              v125 = nameTMPStr2;
              if ("")
              {
LABEL_230:
              }
            }
            *&v125[2 * v104 + 8] = "";
            {
LABEL_224:
            }
LABEL_236:
            nameTMPColor = 12;
            v128 = v104 + 1;
            bup_namenum = v104 + 1;
            v129 = sub_8D3950(s32, &bup_namenum);
            v130 = Format("nameinput_letter{0:00}/TextTM", v129, 0);
            v131 = Concat_5224608("nameinput/namefull/stretch/", v130);
            tmpname_obj_str = v131;
            v133 = get_transform(NameUIObj, 0);
            v134 = Find(v133, tmpname_obj_str, 0);
            v135 = get_gameObject(v134);
            tmpname_obj = v135;
            nameTmpTextTP = GetComponent_object_(tmpname_obj);
            bup_cnamenum = v104 + 1;
            v137 = sub_8D3950(s32, &bup_cnamenum);
            v138 = Format("nameinput_letter{0:00}/TextTM", v137, 0);
            v139 = Concat_5224608("nameinput/namenick/stretch/", v138);
            tmpcname_obj_str = v139;
            v141 = get_transform(NameUIObj, 0);
            v142 = Find(v141, tmpcname_obj_str, 0);
            v143 = get_gameObject(v142);
            tmpcname_obj = v143;
            v145 = GetComponent_object_(tmpcname_obj);
            cnameTmpTextTP = v145;
            if (get_text(cnameTmpTextTP))
            {
              v149 = cnameTMPStr;
              text = get_text(cnameTmpTextTP);
              if (text)
                goto LABEL_266;
              goto LABEL_267;
            }
            goto LABEL_270;
          }
        }
      }
      else
      {
        v106 = 0;
        if (codenmeflag)
          goto LABEL_185;
      }
      else
      {
        if (v104 >= LODWORD(nameTMPStr->max_length))
          goto LABEL_211;
      }
      if (nameTMPStr->m_Items[v104])
      {
          goto LABEL_246;
LABEL_199:
        goto LABEL_246;
      }
      else
      {
        v117 = "";
        v118 = nameTMPStr;
        if (!"")
          goto LABEL_243;
      }
LABEL_243:
      *&v118[2 * v104 + 8] = "";
        goto LABEL_199;
LABEL_246:
      v152 = nameTMPStr2;
      if (v152->m_Items[v104])
      {
          goto LABEL_261;
LABEL_249:
        goto LABEL_261;
      }
      else
      {
        v155 = "";
        v156 = nameTMPStr2;
        if (!"")
          goto LABEL_258;
      }
LABEL_258:
      *&v156[2 * v104 + 8] = "";
        goto LABEL_249;
LABEL_261:
      nameTMPColor = 0;
      v128 = v104 + 1;
      bup_namenum = v104 + 1;
      v159 = sub_8D3950(s32, &bup_namenum);
      v160 = Format("nameinput_letter{0:00}/TextTM", v159, 0);
      v161 = Concat_5224608("nameinput/namefull/stretch/", v160);
      tmpname_obj_str = v161;
      v163 = get_transform(NameUIObj, 0);
      v164 = Find(v163, tmpname_obj_str, 0);
      v165 = get_gameObject(v164);
      tmpname_obj = v165;
      v167 = GetComponent_object_(tmpname_obj);
      nameTmpTextTP = v167;
      if (get_text(nameTmpTextTP))
      {
        v149 = nameTMPStr;
        text = get_text(nameTmpTextTP);
        if (text)
        {
LABEL_266:
        }
LABEL_267:
        *&v149[2 * v104 + 8] = text;
      }
LABEL_270:
      v104 = v128;
    }
    while (v128 != 8);
  }
  v172 = &object;
  v173 = 4;
  v174 = (v19->_2.bitflags2 >> 1) & 1;
  do
  {
    v177 = v173 - 4;
    v178 = sub_8D3950(s32, &bup_namenum);
    v179 = Format("nameinput_letter{0:00}/TextTM", v178, 0);
    v180 = Concat_5224608("nameinput/namefull/stretch/", v179);
    tmpname_obj_str = v180;
    v182 = sub_8D3950(s32, &bup_cnamenum);
    v183 = Format("nameinput_letter{0:00}/TextTM", v182, 0);
    v184 = Concat_5224608("nameinput/namenick/stretch/", v183);
    tmpcname_obj_str = v184;
    v186 = sub_8D3950(s32, &nameend_namenum);
    v187 = Format("nameinput_letter{0:00}/TextTM", v186, 0);
    v188 = Concat_5224608("nameinput/nameconfirm/namefull/stretch/", v187);
    tmpnameend_name_str = v188;
    v190 = sub_8D3950(s32, &nameend_cnamenum);
    v191 = Format("nameinput_letter{0:00}/TextTM", v190, 0);
    v192 = Concat_5224608("nameinput/nameconfirm/namenick/stretch/", v191);
    tmpnameend_cname_str = v192;
    v194 = get_transform(NameUIObj, 0);
    v195 = Find(v194, tmpname_obj_str, 0);
    v196 = get_gameObject(v195);
    tmpname_obj = v196;
    v198 = get_transform(NameUIObj, 0);
    v199 = Find(v198, tmpcname_obj_str, 0);
    v200 = get_gameObject(v199);
    tmpcname_obj = v200;
    v202 = get_transform(NameUIObj, 0);
    v203 = Find(v202, tmpnameend_name_str, 0);
    v204 = get_gameObject(v203);
    tmpnameend_name = v204;
    v206 = get_transform(NameUIObj, 0);
    v207 = Find(v206, tmpnameend_cname_str, 0);
    v208 = get_gameObject(v207);
    tmpnameend_cname = v208;
    GetComponent_object_(tmpname_obj);
    GetComponent_object_(tmpcname_obj);
    v210 = GetComponent_object_(tmpnameend_name);
    v211 = GetComponent_object_(tmpnameend_cname);
    v212 = nameTMPStr2;
    v213 = v211;
    v215 = *(&v212->obj.klass + v173);
    v216 = v172;
    v217 = NewSpecific(*v172, 1u);
    nameTMPColor = 12;
    v218 = v217;
    v235 = 12;
    v219 = sub_8D3950(s32, &v235);
    v221 = v219;
    v218->m_Items[0] = v221;
    v223 = RepColTag(v215, v218);
    set_text(v210, v223);
    v224 = cnameTMPStr;
    v172 = v216;
    v226 = *(&v224->obj.klass + v173);
    v227 = NewSpecific(*v216, 1u);
    nameTMPColor = 12;
    v228 = v227;
    v234 = 12;
    v229 = sub_8D3950(s32, &v234);
    v230 = v229;
    v228->m_Items[0] = v230;
    v232 = RepColTag(v226, v228);
    set_text(v213, v232);
    ++nameend_namenum;
    ++nameend_cnamenum;
    v233 = *&v19->_2.bitflags1;
    ++v173;
    v174 = (v233 >> 9) & 1;
  }
  while (v173 != 12);
  nameend_namenum = 1;
  nameend_cnamenum = 1;
}

// 0xf00bb0
s32 FCL_MAKE_COL(s32 r, s32 g, s32 b, u32 a) {
  return (g << 16) | (r << 24) | (b << 8) | a;
}

// 0xf20810
void ListCursorDispOff(void **obj) {
  Il2CppObject *Component_object;
  f32 v7;
  f32 v8;
  UnityEngine_Vector3_o v9;

  if (get_activeSelf(*obj))
    SetActive(*obj, 0, 0);
  Component_object = GetComponent_object_(*obj);
  v7 = screen_hei + screen_hei;
  v8 = screen_wid + screen_wid;
  v9.z = 0.0;
  *&v9.x = 0;
  sub_8524C0(&v9.x, v8, v7, 0.0);
  set_position(Component_object, v9);
}

// 0xf20900
void MojiChack_apo(void) {
  Nme_Draw_c *v7;
  u64 v8;
  s32 v9;
  s64 i;
  u64 *v11;
  System_String_o *v12;
  struct System_String_o *v13;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v16;
  struct UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  struct System_String_array *nameTMPStr2;
  bool v23;
  struct System_Boolean_array *apoCalcflag;
  struct System_Boolean_array *v27;
  struct UnityEngine_Vector3_array *apoPos;
  UnityEngine_Transform_o *v32;
  struct System_Boolean_array *apoUseflag;
  struct UnityEngine_Vector3_array *v39;
  struct UnityEngine_Vector3_array *v40;
  f32 v42;
  s64 v44;
  struct System_String_array *v45;
  bool v47;
  struct System_Boolean_array *v49;
  struct System_Boolean_array *v51;
  struct System_Boolean_array *v53;
  struct System_Boolean_array *v55;
  struct UnityEngine_Vector3_array *v59;
  UnityEngine_Transform_o *v60;
  struct System_Boolean_array *v64;
  struct UnityEngine_Vector3_array *v67;
  struct UnityEngine_Vector3_array *v68;
  f32 v70;
  s64 v72;
  f32 v73;
  struct UnityEngine_Vector3_array *v77;
  UnityEngine_Transform_o *v78;
  struct System_Boolean_array *v82;
  struct UnityEngine_Vector3_array *v85;
  struct UnityEngine_Vector3_array *v86;
  f32 v88;
  s64 v90;
  f32 v91;
  struct UnityEngine_Vector3_array *v93;
  struct UnityEngine_Vector3_array *v94;
  f32 v96;
  struct System_Boolean_array *v100;
  struct UnityEngine_Vector3_array *v103;
  struct UnityEngine_Vector3_array *v104;
  struct System_Boolean_array *v109;
  struct System_Boolean_array *v111;
  UnityEngine_Transform_o *v113;
  struct UnityEngine_Vector3_array *v114;
  UnityEngine_Transform_o *v115;
  f32 v117;
  struct UnityEngine_Vector3_array *v118;
  f32 v119;
  f32 v121;
  struct UnityEngine_Vector3_array *v122;
  f32 v123;
  f32 v125;
  struct UnityEngine_Vector3_array *v127;
  struct UnityEngine_Vector3_array *v128;
  UnityEngine_Transform_o *v133;
  struct UnityEngine_Vector3_array *v134;
  UnityEngine_Transform_o *v135;
  f32 v137;
  struct UnityEngine_Vector3_array *v138;
  f32 v139;
  f32 v141;
  struct UnityEngine_Vector3_array *v142;
  f32 v143;
  f32 v145;
  struct System_Boolean_array *v146;
  struct System_Boolean_array *v148;
  u32 v150;
  s64 v151;
  s64 v152;
  s32 v153;
  u64 *v154;
  System_String_o *v155;
  struct System_String_o *v156;
  UnityEngine_Transform_o *v158;
  UnityEngine_Component_o *v159;
  struct UnityEngine_GameObject_o *v160;
  Il2CppObject *v162;
  struct System_String_array *v164;
  u64 v165;
  bool v167;
  struct System_Boolean_array *v169;
  struct System_Boolean_array *v171;
  struct UnityEngine_Vector3_array *v175;
  UnityEngine_Transform_o *v176;
  struct System_Boolean_array *v180;
  struct UnityEngine_Vector3_array *v183;
  struct UnityEngine_Vector3_array *v184;
  f32 v186;
  s64 v188;
  struct System_String_array *v189;
  bool v191;
  struct System_Boolean_array *v193;
  struct System_Boolean_array *v195;
  struct System_Boolean_array *v197;
  struct System_Boolean_array *v199;
  struct UnityEngine_Vector3_array *v203;
  UnityEngine_Transform_o *v204;
  struct System_Boolean_array *v208;
  struct UnityEngine_Vector3_array *v211;
  struct UnityEngine_Vector3_array *v212;
  f32 v214;
  s64 v216;
  f32 v217;
  struct UnityEngine_Vector3_array *v221;
  UnityEngine_Transform_o *v222;
  struct System_Boolean_array *v226;
  struct UnityEngine_Vector3_array *v229;
  struct UnityEngine_Vector3_array *v230;
  f32 v232;
  s64 v234;
  f32 v235;
  struct UnityEngine_Vector3_array *v237;
  struct UnityEngine_Vector3_array *v238;
  f32 v240;
  struct System_Boolean_array *v244;
  struct UnityEngine_Vector3_array *v247;
  struct UnityEngine_Vector3_array *v248;
  struct System_Boolean_array *v253;
  struct System_Boolean_array *v255;
  UnityEngine_Transform_o *v257;
  struct UnityEngine_Vector3_array *v258;
  UnityEngine_Transform_o *v259;
  f32 v261;
  struct UnityEngine_Vector3_array *v262;
  f32 v263;
  f32 v265;
  struct UnityEngine_Vector3_array *v266;
  f32 v267;
  f32 v269;
  struct UnityEngine_Vector3_array *v271;
  struct UnityEngine_Vector3_array *v272;
  UnityEngine_Transform_o *v277;
  struct UnityEngine_Vector3_array *v278;
  UnityEngine_Transform_o *v279;
  f32 v281;
  struct UnityEngine_Vector3_array *v282;
  f32 v283;
  f32 v285;
  struct UnityEngine_Vector3_array *v286;
  f32 v287;
  f32 v289;
  struct System_Boolean_array *v290;
  struct System_Boolean_array *v292;
  u32 v294;
  UnityEngine_Vector3_o v295;
  UnityEngine_Vector3_o position;
  UnityEngine_Vector3_o v297;
  UnityEngine_Vector3_o v298;
  UnityEngine_Vector3_o v299;
  UnityEngine_Vector3_o v300;
  UnityEngine_Vector3_o v301;

  else if (!apoInitflag)
  {
    goto LABEL_6;
  }
  else if (StartEndNameflag == 1)
  {
    return;
  }
  v8 = 0;
  apoCnt = 1;
  v9 = (v7->_2.bitflags2 >> 1) & 1;
  for (i = 40; i != 88; i += 12)
  {
    LODWORD(v295.x) = apoCnt;
    v11 = sub_8D3950(s32, &v295);
    v12 = Format("nameinput_letter{0:00}/TextTM", v11, 0);
    v13 = Concat_5224608("nameinput/namefull/stretch/", v12);
    tmpname_obj_str = v13;
    transform = get_transform(NameUIObj, 0);
    v16 = Find(transform, tmpname_obj_str, 0);
    gameObject = get_gameObject(v16);
    tmpname_obj = gameObject;
    Component_object = GetComponent_object_(tmpname_obj);
    tmpname = Component_object;
    v23 = op_Equality(nameTMPStr2->m_Items[v8], "’", 0);
    if (v23)
    {
      apoCalcflag->m_Items[v8] = 0;
      v27 = apoCalcflag;
      if (!v27->m_Items[v8])
      {
        v32 = get_transform(tmpname_obj, 0);
        position = get_position(v32);
        *(apoPos + i - 8) = position;
        if (apoUseflag->m_Items[v8])
        {
          v39 = apoPos;
          v40 = apoPos_;
          v42 = sub_8527D0((v39 + i - 8), 0);
          v44 = v40 + i - 8;
        }
        else
        {
          v93 = apoPos;
          v94 = apoPos_;
          v96 = sub_8527D0((v93 + i - 8), 0);
          v44 = v94 + i - 8;
          v42 = v96 - apoPosAdj;
        }
        sub_8529B0(v44, 0, v42);
        v100 = apoUseflag;
        v100->m_Items[v8] = 1;
LABEL_133:
        v111 = apoCalcflag;
        v111->m_Items[v8] = 1;
        v113 = get_transform(tmpname_obj, 0);
        v114 = apoPos_;
        v115 = v113;
        v117 = sub_8527D0((v114 + i - 8), 0);
        v118 = apoPos;
        v119 = v117;
        v121 = sub_8527D0((v118 + i - 8), 1);
        v122 = apoPos;
        v123 = v121;
        v125 = sub_8527D0((v122 + i - 8), 2);
        v295.z = 0.0;
        *&v295.x = 0;
        sub_8524C0(&v295.x, v119, v123, v125);
        set_position(v115, v295);
        goto LABEL_142;
      }
      goto LABEL_142;
    }
    v45 = nameTMPStr2;
    v47 = op_Equality(v45->m_Items[v8], "", 0);
    if (!v47)
    {
      v53 = apoCalcflag;
      v53->m_Items[v8] = 0;
      v55 = apoCalcflag;
      if (!v55->m_Items[v8])
      {
        v59 = apoPos;
        v60 = get_transform(tmpname_obj, 0);
        v297 = get_position(v60);
        *(v59 + i - 8) = v297;
        v64 = apoUseflag;
        if (v64->m_Items[v8])
        {
          v67 = apoPos;
          v68 = apoPos_;
          v70 = sub_8527D0((v67 + i - 8), 0);
          v72 = v68 + i - 8;
          v73 = v70 + apoPosAdj;
        }
        else
        {
          v103 = apoPos;
          v104 = apoPos_;
          v73 = sub_8527D0((v103 + i - 8), 0);
          v72 = v104 + i - 8;
        }
        sub_8529B0(v72, 0, v73);
        v109 = apoUseflag;
        v109->m_Items[v8] = 0;
        goto LABEL_133;
      }
LABEL_142:
        goto LABEL_168;
LABEL_143:
      goto LABEL_168;
    }
    v49 = apoCalcflag;
    v49->m_Items[v8] = 0;
    v51 = apoCalcflag;
    if (v51->m_Items[v8])
    {
        goto LABEL_163;
LABEL_62:
      goto LABEL_163;
    }
    v77 = apoPos;
    v78 = get_transform(tmpname_obj, 0);
    v298 = get_position(v78);
    *(v77 + i - 8) = v298;
    v82 = apoUseflag;
    if (v82->m_Items[v8])
    {
      v85 = apoPos;
      v86 = apoPos_;
      v88 = sub_8527D0((v85 + i - 8), 0);
      v90 = v86 + i - 8;
      v91 = v88 + apoPosAdj;
    }
    else
    {
      v127 = apoPos;
      v128 = apoPos_;
      v91 = sub_8527D0((v127 + i - 8), 0);
      v90 = v128 + i - 8;
    }
    sub_8529B0(v90, 0, v91);
    v133 = get_transform(tmpname_obj, 0);
    v134 = apoPos_;
    v135 = v133;
    v137 = sub_8527D0((v134 + i - 8), 0);
    v138 = apoPos;
    v139 = v137;
    v141 = sub_8527D0((v138 + i - 8), 1);
    v142 = apoPos;
    v143 = v141;
    v145 = sub_8527D0((v142 + i - 8), 2);
    v295.z = 0.0;
    *&v295.x = 0;
    sub_8524C0(&v295.x, v139, v143, v145);
    set_position(v135, v295);
      goto LABEL_62;
LABEL_163:
    v146 = apoUseflag;
    v146->m_Items[v8] = 0;
    v148 = apoCalcflag;
    v148->m_Items[v8] = 1;
      goto LABEL_143;
LABEL_168:
    ++apoCnt;
    v150 = *&v7->_2.bitflags1;
    ++v8;
    v9 = (v150 >> 9) & 1;
  }
  apoCnt = 5;
  v151 = 0;
  v152 = 80;
  v153 = (v7->_2.bitflags2 >> 1) & 1;
  while (2)
  {
    LODWORD(v295.x) = apoCnt;
    v154 = sub_8D3950(s32, &v295);
    v155 = Format("nameinput_letter{0:00}/TextTM", v154, 0);
    v156 = Concat_5224608("nameinput/namefull/stretch/", v155);
    tmpname_obj_str = v156;
    v158 = get_transform(NameUIObj, 0);
    v159 = Find(v158, tmpname_obj_str, 0);
    v160 = get_gameObject(v159);
    tmpname_obj = v160;
    v162 = GetComponent_object_(tmpname_obj);
    tmpname = v162;
    v164 = nameTMPStr2;
    v165 = v151 + 4;
    v167 = op_Equality(v164->m_Items[v151 + 4], "’", 0);
    if (v167)
    {
      v169 = apoCalcflag;
      v169->m_Items[v151 + 4] = 0;
      v171 = apoCalcflag;
      if (!v171->m_Items[v151 + 4])
      {
        v175 = apoPos;
        v176 = get_transform(tmpname_obj, 0);
        v299 = get_position(v176);
        *(&v175->obj.klass + v152) = v299;
        v180 = apoUseflag;
        if (v180->m_Items[v151 + 4])
        {
          v183 = apoPos;
          v184 = apoPos_;
          v186 = sub_8527D0((v183 + v152), 0);
          v188 = v184 + v152;
        }
        else
        {
          v237 = apoPos;
          v238 = apoPos_;
          v240 = sub_8527D0((v237 + v152), 0);
          v188 = v238 + v152;
          v186 = v240 - apoPosAdj;
        }
        sub_8529B0(v188, 0, v186);
        v244 = apoUseflag;
        v244->m_Items[v151 + 4] = 1;
        goto LABEL_288;
      }
      goto LABEL_297;
    }
    v189 = nameTMPStr2;
    v191 = op_Equality(v189->m_Items[v151 + 4], "", 0);
    if (!v191)
    {
      v197 = apoCalcflag;
      v197->m_Items[v151 + 4] = 0;
      v199 = apoCalcflag;
      if (!v199->m_Items[v151 + 4])
      {
        v203 = apoPos;
        v204 = get_transform(tmpname_obj, 0);
        v300 = get_position(v204);
        *(&v203->obj.klass + v152) = v300;
        v208 = apoUseflag;
        if (v208->m_Items[v151 + 4])
        {
          v211 = apoPos;
          v212 = apoPos_;
          v214 = sub_8527D0((v211 + v152), 0);
          v216 = v212 + v152;
          v217 = v214 + apoPosAdj;
        }
        else
        {
          v247 = apoPos;
          v248 = apoPos_;
          v217 = sub_8527D0((v247 + v152), 0);
          v216 = v248 + v152;
        }
        sub_8529B0(v216, 0, v217);
        v253 = apoUseflag;
        v253->m_Items[v151 + 4] = 0;
LABEL_288:
        v255 = apoCalcflag;
        v255->m_Items[v151 + 4] = 1;
        v257 = get_transform(tmpname_obj, 0);
        v258 = apoPos_;
        v259 = v257;
        v261 = sub_8527D0((v258 + v152), 0);
        v262 = apoPos;
        v263 = v261;
        v265 = sub_8527D0((v262 + v152), 1);
        v266 = apoPos;
        v267 = v265;
        v269 = sub_8527D0((v266 + v152), 2);
        v295.z = 0.0;
        *&v295.x = 0;
        sub_8524C0(&v295.x, v263, v267, v269);
        set_position(v259, v295);
      }
LABEL_297:
        goto LABEL_323;
LABEL_298:
      goto LABEL_323;
    }
    v193 = apoCalcflag;
    v193->m_Items[v151 + 4] = 0;
    v195 = apoCalcflag;
    if (v195->m_Items[v151 + 4])
    {
        goto LABEL_217;
    }
    else
    {
      v221 = apoPos;
      v222 = get_transform(tmpname_obj, 0);
      v301 = get_position(v222);
      *(&v221->obj.klass + v152) = v301;
      v226 = apoUseflag;
      if (v226->m_Items[v151 + 4])
      {
        v229 = apoPos;
        v230 = apoPos_;
        v232 = sub_8527D0((v229 + v152), 0);
        v234 = v230 + v152;
        v235 = v232 + apoPosAdj;
      }
      else
      {
        v271 = apoPos;
        v272 = apoPos_;
        v235 = sub_8527D0((v271 + v152), 0);
        v234 = v272 + v152;
      }
      sub_8529B0(v234, 0, v235);
      v277 = get_transform(tmpname_obj, 0);
      v278 = apoPos_;
      v279 = v277;
      v281 = sub_8527D0((v278 + v152), 0);
      v282 = apoPos;
      v283 = v281;
      v285 = sub_8527D0((v282 + v152), 1);
      v286 = apoPos;
      v287 = v285;
      v289 = sub_8527D0((v286 + v152), 2);
      v295.z = 0.0;
      *&v295.x = 0;
      sub_8524C0(&v295.x, v283, v287, v289);
      set_position(v279, v295);
      {
LABEL_217:
      }
    }
    v290 = apoUseflag;
    v290->m_Items[v151 + 4] = 0;
    v292 = apoCalcflag;
    v292->m_Items[v151 + 4] = 1;
      goto LABEL_298;
LABEL_323:
    ++apoCnt;
    v294 = *&v7->_2.bitflags1;
    v152 += 12;
    ++v151;
    v153 = (v294 >> 9) & 1;
    if (v152 != 128)
      continue;
    break;
  }
  apoCnt = 1;
}

// 0xf1f680
void MojiPanelInit(void) {
  struct cmpCursorInfo_t_array *CharCursor;
  cmpCursorInfo_t_o *v5;
  struct Nme_Draw_StaticFields **p_static_fields;
  struct Nme_Draw_StaticFields *static_fields;
  s32 mojilist;
  s64 v12;
  s32 v13;
  struct System_String_array_array *v15;
  u64 *v19;
  u64 *v20;
  u64 *v21;
  System_String_o *v22;
  struct System_String_o *v23;
  u64 *v25;
  u64 *v26;
  u64 *v27;
  System_String_o *v28;
  struct System_String_o *v29;
  UnityEngine_Transform_o *v31;
  UnityEngine_Component_o *v32;
  struct UnityEngine_GameObject_o *v33;
  Il2CppObject *v35;
  TMPro_TMP_Text_o *v39;
  struct System_String_array_array *v40;
  System_String_array *v42;
  s64 v43;
  Nme_Draw_c *v45;
  struct Nme_Draw_StaticFields *v46;
  struct Nme_Draw_StaticFields **v47;
  s32 v48;
  s64 v51;
  s32 v52;
  struct System_String_array_array *nmeTblList22;
  u64 *v56;
  u64 *v57;
  u64 *v58;
  System_String_o *v59;
  struct System_String_o *v60;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v63;
  struct UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  TMPro_TMP_Text_o *panel_tmp;
  struct System_String_array_array *v70;
  System_String_array *v72;
  s64 ptcnt;
  Nme_Draw_c *v75;
  struct Nme_Draw_StaticFields *v76;
  struct Nme_Draw_StaticFields **v77;
  s32 v78;
  s64 v82;
  s32 v83;
  struct System_String_array_array *v85;
  u64 *v88;
  u64 *v89;
  System_String_o *v90;
  struct System_String_o *v91;
  u64 *v93;
  u64 *v94;
  System_String_o *v95;
  struct System_String_o *v96;
  UnityEngine_Transform_o *v98;
  UnityEngine_Component_o *v99;
  struct UnityEngine_GameObject_o *v100;
  Il2CppObject *v102;
  TMPro_TMP_Text_o *v106;
  struct System_String_array_array *v107;
  System_String_array *v109;
  s64 v110;
  Nme_Draw_c *v112;
  struct Nme_Draw_StaticFields *v113;
  struct Nme_Draw_StaticFields **v114;
  s32 v115;
  struct cmpCursorInfo_t_array *v117;
  struct Nme_Draw_StaticFields *v119;
  struct cmpCursorInfo_t_array *v120;
  s32 Index;
  s32 v123;
  s32 i;
  u64 *v125;
  u64 *v126;
  System_String_o *v127;
  System_String_o *v129;
  UnityEngine_Transform_o *v131;
  UnityEngine_Component_o *v132;
  struct UnityEngine_GameObject_o *v133;
  Il2CppObject *v135;
  TMPro_TMP_Text_o *v139;
  struct System_String_array_array *v140;
  System_String_array *v142;
  s32 v143;
  s32 ShiftMax;
  s32 v146;
  s32 v147;
  s32 v148;
  s32 letter_num;
  s32 box_num;
  s32 kanabox_num;

  CharCursor = GBWK->CharCursor;
  v5 = CharCursor->m_Items[0];
  cmpGetCursorIndex(v5);
  if (!mojilist)
  {
    kanabox_numbup = kanabox_num;
    (*p_static_fields)->kanabox_num = 3;
    (*p_static_fields)->box_num = 1;
    (*p_static_fields)->letter_num = 1;
    v51 = "";
    (*p_static_fields)->ptext_str = "";
    (*p_static_fields)->ptext_str_null = v51;
    (*p_static_fields)->ptcnt = 0;
    v52 = 0;
      goto LABEL_76;
LABEL_72:
    while (1)
    {
LABEL_76:
      if (!LODWORD(nmeTblList22->max_length))
        goto LABEL_77;
LABEL_78:
      if (v52 >= SLODWORD(nmeTblList22->m_Items[0]->max_length))
      {
LABEL_123:
        kanabox_num = kanabox_numbup;
        box_num = 1;
        letter_num = 1;
        goto LABEL_127;
      }
      v56 = sub_8D3950(s32, &kanabox_num);
      v57 = sub_8D3950(s32, &box_num);
      v58 = sub_8D3950(s32, &letter_num);
      v59 = Format_5268688("name_kana_box{0:00}/namelist_box{1:00}/Text_letter{2:00}TM", v56, v57, v58);
      v60 = Concat_5224608("namelist/name_kana/", v59);
      ptext_str = v60;
      transform = get_transform(NameUIObj, 0);
      v63 = Find(transform, ptext_str, 0);
      gameObject = get_gameObject(v63);
      panel_text_tmp = gameObject;
      Component_object = GetComponent_object_(panel_text_tmp);
      panel_tmp = Component_object;
      else
      {
        v70 = nmeTblList22;
        if (!LODWORD(v70->max_length))
          goto LABEL_85;
      }
      v72 = v70->m_Items[0];
      set_text(panel_tmp, v72->m_Items[ptcnt]);
      v78 = box_num;
      if (v78 <= 4)
      {
        else
        {
          box_num = v78 + 1;
          if ((v75->_2.bitflags2 & 2) == 0)
            goto LABEL_113;
        }
      }
      else
      {
              v75 = Nme_Draw,
              v77 = &Nme_Draw->static_fields,
              v76 = Nme_Draw->static_fields,
              box_num >= 5))
        {
          box_num = 1;
          --(*v77)->kanabox_num;
        }
        if ((v75->_2.bitflags2 & 2) == 0)
          goto LABEL_113;
      }
LABEL_113:
      if (kanabox_num <= 0)
      {
LABEL_99:
        kanabox_num = 3;
        ++letter_num;
        if ((v75->_2.bitflags2 & 2) == 0)
          goto LABEL_115;
        goto LABEL_103;
      }
LABEL_114:
      if ((v75->_2.bitflags2 & 2) == 0)
        goto LABEL_115;
LABEL_103:
LABEL_115:
      if (letter_num >= 7)
      {
LABEL_105:
        letter_num = 1;
        if ((v75->_2.bitflags2 & 2) == 0)
          goto LABEL_75;
LABEL_117:
        goto LABEL_75;
      }
LABEL_116:
      if ((v75->_2.bitflags2 & 2) != 0)
        goto LABEL_117;
LABEL_75:
      ++v52;
      ++ptcnt;
        goto LABEL_72;
    }
  }
  else if (mojilist == 1)
  {
LABEL_15:
    kanabox_numbup = kanabox_num;
    (*p_static_fields)->kanabox_num = 3;
    (*p_static_fields)->box_num = 1;
    (*p_static_fields)->letter_num = 1;
    v12 = "";
    (*p_static_fields)->ptext_str = "";
    (*p_static_fields)->ptext_str_null = v12;
    (*p_static_fields)->ptcnt = 0;
    v13 = 0;
    {
LABEL_19:
      goto LABEL_22;
    }
    while (1)
    {
LABEL_22:
      v15 = nmeTblList22;
      if (v13 >= SLODWORD(v15->m_Items[1]->max_length))
        goto LABEL_123;
      v19 = sub_8D3950(s32, &kanabox_num);
      v20 = sub_8D3950(s32, &box_num);
      v21 = sub_8D3950(s32, &letter_num);
      v22 = Format_5268688("name_kana_box{0:00}/namelist_box{1:00}/Text_letter{2:00}TM", v19, v20, v21);
      v23 = Concat_5224608("namelist/name_kana/", v22);
      ptext_str = v23;
      v148 = kanabox_num;
      v25 = sub_8D3950(s32, &v148);
      v147 = box_num;
      v26 = sub_8D3950(s32, &v147);
      v146 = letter_num;
      v27 = sub_8D3950(s32, &v146);
      v28 = Format_5268688("name_kana_box{0:00}/namelist_box{1:00}/Text_letter{2:00}", v25, v26, v27);
      v29 = Concat_5224608("namelist/name_kana/", v28);
      ptext_str_null = v29;
      v31 = get_transform(NameUIObj, 0);
      v32 = Find(v31, ptext_str, 0);
      v33 = get_gameObject(v32);
      panel_text_tmp = v33;
      v35 = GetComponent_object_(panel_text_tmp);
      panel_tmp = v35;
      v39 = panel_tmp;
      v40 = nmeTblList22;
      v42 = v40->m_Items[1];
      v43 = ptcnt;
      set_text(v39, v42->m_Items[v43]);
      v48 = box_num;
      if (v48 <= 4)
      {
        else
        {
          box_num = v48 + 1;
          if ((v45->_2.bitflags2 & 2) == 0)
            goto LABEL_60;
        }
      }
      else
      {
              v45 = Nme_Draw,
              v47 = &Nme_Draw->static_fields,
              v46 = Nme_Draw->static_fields,
              box_num >= 5))
        {
          box_num = 1;
          --(*v47)->kanabox_num;
        }
        if ((v45->_2.bitflags2 & 2) == 0)
          goto LABEL_60;
      }
LABEL_60:
      if (kanabox_num <= 0)
      {
LABEL_46:
        kanabox_num = 3;
        ++letter_num;
        if ((v45->_2.bitflags2 & 2) == 0)
          goto LABEL_62;
        goto LABEL_50;
      }
LABEL_61:
      if ((v45->_2.bitflags2 & 2) == 0)
        goto LABEL_62;
LABEL_50:
LABEL_62:
      if (letter_num >= 7)
      {
LABEL_52:
        letter_num = 1;
        if ((v45->_2.bitflags2 & 2) == 0)
          goto LABEL_21;
LABEL_64:
        goto LABEL_21;
      }
LABEL_63:
      if ((v45->_2.bitflags2 & 2) != 0)
        goto LABEL_64;
LABEL_21:
      ++v13;
      ++ptcnt;
        goto LABEL_19;
    }
  }
  else if (mojilist == 2)
  {
LABEL_135:
    box_num = 1;
    (*p_static_fields)->letter_num = 1;
    v82 = "";
    (*p_static_fields)->ptext_str = "";
    (*p_static_fields)->ptext_str_null = v82;
    (*p_static_fields)->ptcnt = 0;
    v83 = 0;
    {
LABEL_139:
      goto LABEL_142;
    }
    while (1)
    {
LABEL_142:
      v85 = nmeTblList22;
      if (v83 >= SLODWORD(v85->m_Items[2]->max_length))
        goto LABEL_127;
      kanabox_num = box_num;
      v88 = sub_8D3950(s32, &kanabox_num);
      box_num = letter_num;
      v89 = sub_8D3950(s32, &box_num);
      v90 = Format_5268592("namelist_box{0:00}/Text_letter{1:00}TM", v88, v89);
      v91 = Concat_5224608("namelist/name_alpabet/name_alphabet_box/", v90);
      ptext_str = v91;
      letter_num = box_num;
      v93 = sub_8D3950(s32, &letter_num);
      v148 = letter_num;
      v94 = sub_8D3950(s32, &v148);
      v95 = Format_5268592("namelist_box{0:00}/Text_letter{1:00}", v93, v94);
      v96 = Concat_5224608("namelist/name_alpabet/name_alphabet_box/", v95);
      ptext_str_null = v96;
      v98 = get_transform(NameUIObj, 0);
      v99 = Find(v98, ptext_str, 0);
      v100 = get_gameObject(v99);
      panel_text_tmp = v100;
      v102 = GetComponent_object_(panel_text_tmp);
      panel_tmp = v102;
      v106 = panel_tmp;
      v107 = nmeTblList22;
      v109 = v107->m_Items[2];
      v110 = ptcnt;
      set_text(v106, v109->m_Items[v110]);
      v115 = box_num;
      if (v115 <= 15)
      {
        else
        {
          box_num = v115 + 1;
          if ((v112->_2.bitflags2 & 2) == 0)
            goto LABEL_174;
        }
      }
      else
      {
              v112 = Nme_Draw,
              v114 = &Nme_Draw->static_fields,
              v113 = Nme_Draw->static_fields,
              box_num >= 16))
        {
          box_num = 1;
          ++(*v114)->letter_num;
        }
        if ((v112->_2.bitflags2 & 2) == 0)
          goto LABEL_174;
      }
LABEL_174:
      if (letter_num >= 7)
      {
LABEL_166:
        letter_num = 1;
        if ((v112->_2.bitflags2 & 2) == 0)
          goto LABEL_141;
LABEL_176:
        goto LABEL_141;
      }
LABEL_175:
      if ((v112->_2.bitflags2 & 2) != 0)
        goto LABEL_176;
LABEL_141:
      ++v83;
      ++ptcnt;
        goto LABEL_139;
    }
  }
  if (mojilist == 3)
  {
    ckanUDcnt = 6;
    (*p_static_fields)->ptext_str = "";
    (*p_static_fields)->ptcnt = 0;
    v117 = (*p_static_fields)->GBWK->CharCursor;
    (*p_static_fields)->cpos = v117->m_Items[0]->CursorPos;
    v119 = *p_static_fields;
    v120 = v119->GBWK->CharCursor;
    Index = v119->cpos->Index;
    ShiftMax = v120->m_Items[0]->CursorPos->ShiftMax;
    if (ShiftMax >= 1)
    {
      v123 = 0;
      do
      {
        ++v123;
        for (i = 1; i != 16; ++i)
        {
          kanabox_num = i;
          v125 = sub_8D3950(s32, &kanabox_num);
          box_num = v123;
          v126 = sub_8D3950(s32, &box_num);
          v127 = Format_5268592("namelist_box{0:00}/Text_letter{1:00}TM", v125, v126);
          v129 = Concat_5224608("namelist/name_kanji/name_kanji_box/", v127);
          ptext_str = v129;
          v131 = get_transform(NameUIObj, 0);
          v132 = Find(v131, ptext_str, 0);
          v133 = get_gameObject(v132);
          panel_text_tmp = v133;
          v135 = GetComponent_object_(panel_text_tmp);
          panel_tmp = v135;
          v139 = panel_tmp;
          v140 = nmeTblList22;
          v142 = v140->m_Items[3];
          v143 = ptcnt + eLRcnt_max * Index;
          set_text(v139, v142->m_Items[v143]);
          ++ptcnt;
        }
      }
      while (v123 != ShiftMax);
    }
  }
LABEL_127:
  PlistUpdateflag = 0;
}

// 0xf1cc40
void NameInit(void) {
  UnityEngine_GameObject_o *inited;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v6;
  struct UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  UnityEngine_Transform_o *v11;
  UnityEngine_Component_o *v12;
  struct UnityEngine_GameObject_o *v13;
  Il2CppObject *v15;
  UnityEngine_Transform_o *v17;
  UnityEngine_Component_o *v18;
  struct UnityEngine_GameObject_o *v19;
  Il2CppObject *v21;
  UnityEngine_Transform_o *v23;
  UnityEngine_Component_o *v24;
  struct UnityEngine_GameObject_o *v25;
  Il2CppObject *v27;
  UnityEngine_Transform_o *v29;
  UnityEngine_Component_o *v30;
  struct UnityEngine_GameObject_o *v31;
  UnityEngine_Transform_o *v33;
  UnityEngine_Component_o *v34;
  struct UnityEngine_GameObject_o *v35;
  Il2CppObject *v37;
  UnityEngine_Transform_o *v39;
  UnityEngine_Component_o *v40;
  struct UnityEngine_GameObject_o *v41;
  Il2CppObject *v43;
  UnityEngine_Transform_o *v45;
  UnityEngine_Component_o *v46;
  struct UnityEngine_GameObject_o *v47;
  Il2CppObject *v49;
  UnityEngine_Transform_o *v51;
  UnityEngine_Component_o *v52;
  struct UnityEngine_GameObject_o *v53;
  Il2CppObject *v55;
  UnityEngine_Transform_o *v57;
  UnityEngine_Component_o *v58;
  struct UnityEngine_GameObject_o *v59;
  UnityEngine_Transform_o *v61;
  UnityEngine_Component_o *v62;
  struct UnityEngine_GameObject_o *v63;
  UnityEngine_Transform_o *v65;
  UnityEngine_Component_o *v66;
  struct UnityEngine_GameObject_o *v67;
  UnityEngine_Transform_o *v69;
  UnityEngine_Component_o *v70;
  struct UnityEngine_GameObject_o *v71;
  UnityEngine_Transform_o *v73;
  UnityEngine_Component_o *v74;
  struct UnityEngine_GameObject_o *v75;
  Il2CppObject *v77;
  UnityEngine_Transform_o *v79;
  UnityEngine_Component_o *v80;
  struct UnityEngine_GameObject_o *v81;
  Il2CppObject *v83;
  UnityEngine_Transform_o *v85;
  UnityEngine_Component_o *v86;
  struct UnityEngine_GameObject_o *v87;
  Il2CppObject *v89;
  UnityEngine_Transform_o *v91;
  UnityEngine_Component_o *v92;
  struct UnityEngine_GameObject_o *v93;
  Il2CppObject *v95;
  UnityEngine_Transform_o *v97;
  UnityEngine_Component_o *v98;
  struct UnityEngine_GameObject_o *v99;
  Il2CppObject *v101;
  UnityEngine_Transform_o *v103;
  UnityEngine_Component_o *v104;
  struct UnityEngine_GameObject_o *v105;
  Il2CppObject *v107;
  UnityEngine_Transform_o *v109;
  UnityEngine_Component_o *v110;
  struct UnityEngine_GameObject_o *v111;
  Il2CppObject *v113;
  UnityEngine_Transform_o *v115;
  UnityEngine_Component_o *v116;
  struct UnityEngine_GameObject_o *v117;
  UnityEngine_Transform_o *v119;
  UnityEngine_Component_o *v120;
  struct UnityEngine_GameObject_o *v121;
  UnityEngine_Transform_o *v123;
  UnityEngine_Component_o *v124;
  struct UnityEngine_GameObject_o *v125;
  Il2CppObject *v127;
  UnityEngine_Transform_o *v130;
  UnityEngine_Component_o *v131;
  struct UnityEngine_GameObject_o *v132;
  Il2CppObject *v134;
  UnityEngine_Transform_o *v136;
  UnityEngine_Component_o *v137;
  struct UnityEngine_GameObject_o *v138;
  UnityEngine_Transform_o *v140;
  UnityEngine_Component_o *v141;
  struct UnityEngine_GameObject_o *v142;
  UnityEngine_Transform_o *v144;
  UnityEngine_Component_o *v145;
  struct UnityEngine_GameObject_o *v146;
  UnityEngine_Transform_o *v148;
  UnityEngine_Component_o *v149;
  struct UnityEngine_GameObject_o *v150;
  UnityEngine_Transform_o *v152;
  UnityEngine_Component_o *v153;
  struct UnityEngine_GameObject_o *v154;
  UnityEngine_Transform_o *v156;
  UnityEngine_Component_o *v157;
  struct UnityEngine_GameObject_o *v158;
  UnityEngine_Transform_o *v160;
  UnityEngine_Component_o *v161;
  struct UnityEngine_GameObject_o *v162;
  UnityEngine_Transform_o *v164;
  UnityEngine_Component_o *v165;
  struct UnityEngine_GameObject_o *v166;
  UnityEngine_Transform_o *v168;
  UnityEngine_Component_o *v169;
  struct UnityEngine_GameObject_o *v170;
  UnityEngine_Transform_o *v172;
  UnityEngine_Component_o *v173;
  struct UnityEngine_GameObject_o *v174;
  UnityEngine_Transform_o *v176;
  UnityEngine_Component_o *v177;
  struct UnityEngine_GameObject_o *v178;
  UnityEngine_Transform_o *v180;
  UnityEngine_Component_o *v181;
  struct UnityEngine_GameObject_o *v182;
  UnityEngine_Transform_o *v184;
  UnityEngine_Component_o *v185;
  struct UnityEngine_GameObject_o *v186;
  UnityEngine_Transform_o *v188;
  UnityEngine_Component_o *v189;
  struct UnityEngine_GameObject_o *v190;
  UnityEngine_Transform_o *v192;
  UnityEngine_Component_o *v193;
  struct UnityEngine_GameObject_o *v194;
  UnityEngine_Transform_o *v196;
  UnityEngine_Component_o *v197;
  struct UnityEngine_GameObject_o *v198;
  u64 *v200;
  System_String_o *v201;
  struct System_String_o *v202;
  u64 *v204;
  System_String_o *v205;
  struct System_String_o *v206;
  UnityEngine_Transform_o *v208;
  UnityEngine_Component_o *v209;
  struct UnityEngine_GameObject_o *v210;
  UnityEngine_Transform_o *v212;
  UnityEngine_Component_o *v213;
  struct UnityEngine_GameObject_o *v214;
  u64 *v216;
  System_String_o *v217;
  struct System_String_o *v218;
  UnityEngine_Transform_o *v220;
  UnityEngine_Component_o *v221;
  struct UnityEngine_GameObject_o *v222;
  Il2CppObject *v224;
  u64 *v226;
  System_String_o *v227;
  struct System_String_o *v228;
  u64 *v230;
  System_String_o *v231;
  struct System_String_o *v232;
  UnityEngine_Transform_o *v234;
  UnityEngine_Component_o *v235;
  struct UnityEngine_GameObject_o *v236;
  UnityEngine_Transform_o *v238;
  UnityEngine_Component_o *v239;
  struct UnityEngine_GameObject_o *v240;
  u64 *v242;
  System_String_o *v243;
  struct System_String_o *v244;
  u64 *v246;
  System_String_o *v247;
  struct System_String_o *v248;
  UnityEngine_Transform_o *v250;
  UnityEngine_Component_o *v251;
  struct UnityEngine_GameObject_o *v252;
  UnityEngine_Transform_o *v254;
  UnityEngine_Component_o *v255;
  struct UnityEngine_GameObject_o *v256;
  u64 *v258;
  System_String_o *v259;
  struct System_String_o *v260;
  u64 *v262;
  System_String_o *v263;
  struct System_String_o *v264;
  UnityEngine_Transform_o *v266;
  UnityEngine_Component_o *v267;
  struct UnityEngine_GameObject_o *v268;
  UnityEngine_Transform_o *v270;
  UnityEngine_Component_o *v271;
  struct UnityEngine_GameObject_o *v272;
  u64 *v274;
  System_String_o *v275;
  struct System_String_o *v276;
  u64 *v278;
  System_String_o *v279;
  struct System_String_o *v280;
  UnityEngine_Transform_o *v282;
  UnityEngine_Component_o *v283;
  struct UnityEngine_GameObject_o *v284;
  UnityEngine_Transform_o *v286;
  UnityEngine_Component_o *v287;
  struct UnityEngine_GameObject_o *v288;
  u64 *v290;
  System_String_o *v291;
  struct System_String_o *v292;
  u64 *v294;
  System_String_o *v295;
  struct System_String_o *v296;
  UnityEngine_Transform_o *v298;
  UnityEngine_Component_o *v299;
  struct UnityEngine_GameObject_o *v300;
  UnityEngine_Transform_o *v302;
  UnityEngine_Component_o *v303;
  struct UnityEngine_GameObject_o *v304;
  u64 *v306;
  System_String_o *v307;
  struct System_String_o *v308;
  UnityEngine_Transform_o *v310;
  UnityEngine_Component_o *v311;
  struct UnityEngine_GameObject_o *v312;
  u64 *v314;
  System_String_o *v315;
  struct System_String_o *v316;
  UnityEngine_Transform_o *v318;
  UnityEngine_Component_o *v319;
  struct UnityEngine_GameObject_o *v320;
  UnityEngine_Transform_o *v322;
  UnityEngine_Component_o *v323;
  struct UnityEngine_GameObject_o *v324;
  Il2CppObject *v326;
  UnityEngine_Transform_o *v328;
  UnityEngine_Component_o *v329;
  struct UnityEngine_GameObject_o *v330;
  Il2CppObject *v332;
  UnityEngine_Transform_o *v334;
  UnityEngine_Component_o *v335;
  struct UnityEngine_GameObject_o *v336;
  UnityEngine_Transform_o *v338;
  UnityEngine_Component_o *v339;
  struct UnityEngine_GameObject_o *v340;
  UnityEngine_Transform_o *v342;
  UnityEngine_Component_o *v343;
  struct UnityEngine_GameObject_o *v344;
  UnityEngine_Transform_o *v346;
  UnityEngine_Component_o *v347;
  s32 underline_num_c;
  s32 underline_num;
  s32 v350;
  s32 nameend_cnamenum;
  s32 v352;
  s32 nameend_namenum;
  s32 v354;
  s32 bup_cnamenum;
  s32 v356;
  s32 bup_namenum;
  s32 v358;
  s32 kanjiScrollcnt;
  s32 v360;
  s32 v361;
  s32 kanjiIndexObjcnt;
  UnityEngine_Vector2_o anchoredPosition;
  UnityEngine_Vector3_o position;
  UnityEngine_Vector3_o v365;
  UnityEngine_Vector3_o v366;
  UnityEngine_Vector3_o v367;
  UnityEngine_Vector3_o v368;
  UnityEngine_Vector2_o v369;

  inited = GetoNameUI();
  NameUIObj = inited;
  transform = get_transform(NameUIObj, 0);
  v6 = Find(transform, "namemode/namelr_menu/namemode01", 0);
  gameObject = get_gameObject(v6);
  kanalist_hira = gameObject;
  Component_object = GetComponent_object_(kanalist_hira);
  kanalist_hira_anim = Component_object;
  v11 = get_transform(NameUIObj, 0);
  v12 = Find(v11, "namemode/namelr_menu/namemode02", 0);
  v13 = get_gameObject(v12);
  kanalist_kata = v13;
  v15 = GetComponent_object_(kanalist_kata);
  kanalist_kata_anim = v15;
  v17 = get_transform(NameUIObj, 0);
  v18 = Find(v17, "namemode/namelr_menu/namemode03", 0);
  v19 = get_gameObject(v18);
  kanalist_alphabet = v19;
  v21 = GetComponent_object_(kanalist_alphabet);
  kanalist_alphabet_anim = v21;
  v23 = get_transform(NameUIObj, 0);
  v24 = Find(v23, "namemode/namelr_menu/namemode04", 0);
  v25 = get_gameObject(v24);
  kanalist_kanji = v25;
  v27 = GetComponent_object_(kanalist_kanji);
  kanalist_kanji_anim = v27;
  v29 = get_transform(NameUIObj, 0);
  v30 = Find(v29, "namelist_button", 0);
  v31 = get_gameObject(v30);
  functionImage = v31;
  v33 = get_transform(NameUIObj, 0);
  v34 = Find(v33, "namelist_button/namebutton_r", 0);
  v35 = get_gameObject(v34);
  namelist_rightbutton = v35;
  v37 = GetComponent_object_(namelist_rightbutton);
  namelist_buttonAnim_r = v37;
  v39 = get_transform(NameUIObj, 0);
  v40 = Find(v39, "namelist_button/namebutton_l", 0);
  v41 = get_gameObject(v40);
  namelist_leftbutton = v41;
  v43 = GetComponent_object_(namelist_leftbutton);
  namelist_buttonAnim_l = v43;
  v45 = get_transform(NameUIObj, 0);
  v46 = Find(v45, "namelist_button/namebutton_del", 0);
  v47 = get_gameObject(v46);
  namelist_deletebutton = v47;
  v49 = GetComponent_object_(namelist_deletebutton);
  namelist_buttonAnim_del = v49;
  v51 = get_transform(NameUIObj, 0);
  v52 = Find(v51, "namelist_button/namebutton_end", 0);
  v53 = get_gameObject(v52);
  namelist_endbutton = v53;
  v55 = GetComponent_object_(namelist_endbutton);
  namelist_buttonAnim_end = v55;
  v57 = get_transform(NameUIObj, 0);
  v58 = Find(v57, "namelist", 0);
  v59 = get_gameObject(v58);
  name_list = v59;
  v61 = get_transform(NameUIObj, 0);
  v62 = Find(v61, "namelist/name_kana", 0);
  v63 = get_gameObject(v62);
  list_hira = v63;
  v65 = get_transform(NameUIObj, 0);
  v66 = Find(v65, "namelist/name_alpabet", 0);
  v67 = get_gameObject(v66);
  list_alphabet = v67;
  v69 = get_transform(NameUIObj, 0);
  v70 = Find(v69, "namelist/name_kanji", 0);
  v71 = get_gameObject(v70);
  list_kanji = v71;
  v73 = get_transform(NameUIObj, 0);
  v74 = Find(v73, "namelist/name_kanji/namekindex_yau", 0);
  v75 = get_gameObject(v74);
  kanji_scrollbar_up = v75;
  v77 = GetComponent_object_(kanji_scrollbar_up);
  kanji_scrollbar_up_anime = v77;
  v79 = get_transform(NameUIObj, 0);
  v80 = Find(v79, "namelist/name_kanji/namekindex_yad", 0);
  v81 = get_gameObject(v80);
  kanji_scrollbar_down = v81;
  v83 = GetComponent_object_(kanji_scrollbar_down);
  kanji_scrollbar_down_anime = v83;
  v85 = get_transform(NameUIObj, 0);
  v86 = Find(v85, "namelist/name_kanji/namekindex_line", 0);
  v87 = get_gameObject(v86);
  kanji_scrollbar = v87;
  v89 = GetComponent_object_(kanji_scrollbar);
  kanji_scrollbar_anime = v89;
  v91 = get_transform(NameUIObj, 0);
  v92 = Find(v91, "namelist/namelist_cursur", 0);
  v93 = get_gameObject(v92);
  listcursur = v93;
  v95 = GetComponent_object_(listcursur);
  position = get_position(v95);
  listcursurPos = position;
  v97 = get_transform(NameUIObj, 0);
  v98 = Find(v97, "namelist/name_kana/name_kana_box03/namelist_box01/Text_letter01", 0);
  v99 = get_gameObject(v98);
  listcursur_hira_a = v99;
  v101 = GetComponent_object_(listcursur_hira_a);
  v365 = get_position(v101);
  listcursur_hirafirstPos = v365;
  v103 = get_transform(NameUIObj, 0);
  v104 = Find(v103, "namelist/name_alpabet/name_alphabet_box/namelist_box01/Text_letter01", 0);
  v105 = get_gameObject(v104);
  listcursur_alpha_a = v105;
  v107 = GetComponent_object_(listcursur_alpha_a);
  v366 = get_position(v107);
  listcursur_alphafirstPos = v366;
  v109 = get_transform(NameUIObj, 0);
  v110 = Find(v109, "nameinput", 0);
  v111 = get_gameObject(v110);
  name_input = v111;
  v113 = GetComponent_object_(name_input);
  _name_input = v113;
  v115 = get_transform(NameUIObj, 0);
  v116 = Find(v115, "nameinput/nameannounce/stretch/Text", 0);
  v117 = get_gameObject(v116);
  name_description = v117;
  v119 = get_transform(NameUIObj, 0);
  v120 = Find(v119, "nameinput/nameannounce/stretch/TextTM", 0);
  v121 = get_gameObject(v120);
  name_descriptionTM = v121;
  v123 = get_transform(NameUIObj, 0);
  v124 = Find(v123, "nameinput/namefull", 0);
  v125 = get_gameObject(v124);
  mynameImage = v125;
  v127 = GetComponent_object_(mynameImage);
  anchoredPosition = get_anchoredPosition(v127);
  v367 = op_Implicit_8725680(anchoredPosition);
  mynameImagePos = v367;
  v130 = get_transform(NameUIObj, 0);
  v131 = Find(v130, "nameinput/namenick", 0);
  v132 = get_gameObject(v131);
  codenameImage = v132;
  v134 = GetComponent_object_(codenameImage);
  v369 = get_anchoredPosition(v134);
  v368 = op_Implicit_8725680(v369);
  codenameImagePos = v368;
  v136 = get_transform(NameUIObj, 0);
  v137 = Find(v136, "nameinput/namefull/stretch/nameinput_letter01/TextTM", 0);
  v138 = get_gameObject(v137);
  Tmpnameone_obj = v138;
  v140 = get_transform(NameUIObj, 0);
  v141 = Find(v140, "nameinput/namefull/stretch/nameinput_letter02/TextTM", 0);
  v142 = get_gameObject(v141);
  Tmpnametwo_obj = v142;
  v144 = get_transform(NameUIObj, 0);
  v145 = Find(v144, "nameinput/namefull/stretch/nameinput_letter03/TextTM", 0);
  v146 = get_gameObject(v145);
  Tmpnamethree_obj = v146;
  v148 = get_transform(NameUIObj, 0);
  v149 = Find(v148, "nameinput/namefull/stretch/nameinput_letter04/TextTM", 0);
  v150 = get_gameObject(v149);
  Tmpnamefour_obj = v150;
  v152 = get_transform(NameUIObj, 0);
  v153 = Find(v152, "nameinput/namefull/stretch/nameinput_letter05/TextTM", 0);
  v154 = get_gameObject(v153);
  Tmpnamefive_obj = v154;
  v156 = get_transform(NameUIObj, 0);
  v157 = Find(v156, "nameinput/namefull/stretch/nameinput_letter06/TextTM", 0);
  v158 = get_gameObject(v157);
  Tmpnamesix_obj = v158;
  v160 = get_transform(NameUIObj, 0);
  v161 = Find(v160, "nameinput/namefull/stretch/nameinput_letter07/TextTM", 0);
  v162 = get_gameObject(v161);
  Tmpnameseven_obj = v162;
  v164 = get_transform(NameUIObj, 0);
  v165 = Find(v164, "nameinput/namefull/stretch/nameinput_letter08/TextTM", 0);
  v166 = get_gameObject(v165);
  Tmpnameeight_obj = v166;
  v168 = get_transform(NameUIObj, 0);
  v169 = Find(v168, "nameinput/namenick/stretch/nameinput_letter01/TextTM", 0);
  v170 = get_gameObject(v169);
  Tmpcodenameone_obj = v170;
  v172 = get_transform(NameUIObj, 0);
  v173 = Find(v172, "nameinput/namenick/stretch/nameinput_letter02/TextTM", 0);
  v174 = get_gameObject(v173);
  Tmpcodenametwo_obj = v174;
  v176 = get_transform(NameUIObj, 0);
  v177 = Find(v176, "nameinput/namenick/stretch/nameinput_letter03/TextTM", 0);
  v178 = get_gameObject(v177);
  Tmpcodenamethree_obj = v178;
  v180 = get_transform(NameUIObj, 0);
  v181 = Find(v180, "nameinput/namenick/stretch/nameinput_letter04/TextTM", 0);
  v182 = get_gameObject(v181);
  Tmpcodenamefour_obj = v182;
  v184 = get_transform(NameUIObj, 0);
  v185 = Find(v184, "nameinput/namenick/stretch/nameinput_letter05/TextTM", 0);
  v186 = get_gameObject(v185);
  Tmpcodenamefive_obj = v186;
  v188 = get_transform(NameUIObj, 0);
  v189 = Find(v188, "nameinput/namenick/stretch/nameinput_letter06/TextTM", 0);
  v190 = get_gameObject(v189);
  Tmpcodenamesix_obj = v190;
  v192 = get_transform(NameUIObj, 0);
  v193 = Find(v192, "nameinput/namenick/stretch/nameinput_letter07/TextTM", 0);
  v194 = get_gameObject(v193);
  Tmpcodenameseven_obj = v194;
  v196 = get_transform(NameUIObj, 0);
  v197 = Find(v196, "nameinput/namenick/stretch/nameinput_letter08/TextTM", 0);
  v198 = get_gameObject(v197);
  Tmpcodenameeight_obj = v198;
  v200 = sub_8D3950(s32, &kanjiIndexObjcnt);
  v201 = Format("name_kanji_index{0:0}/TextTM", v200, 0);
  v202 = Concat_5224608("namelist/name_kanji/", v201);
  kanjiIndexTmpText_str = v202;
  v361 = kanjiIndexObjcnt;
  v204 = sub_8D3950(s32, &v361);
  v205 = Format("name_kanji_index{0:0}/Text", v204, 0);
  v206 = Concat_5224608("namelist/name_kanji/", v205);
  kanjiIndexText_str = v206;
  v208 = get_transform(NameUIObj, 0);
  v209 = Find(v208, kanjiIndexTmpText_str, 0);
  v210 = get_gameObject(v209);
  kanjiScrIndexTmpText = v210;
  v212 = get_transform(NameUIObj, 0);
  v213 = Find(v212, kanjiIndexText_str, 0);
  v214 = get_gameObject(v213);
  kanjiScrIndexText = v214;
  v360 = kanjiIndexObjcnt;
  v216 = sub_8D3950(s32, &v360);
  v217 = Format("name_kanji_index{0:0}", v216, 0);
  v218 = Concat_5224608("namelist/name_kanji/", v217);
  kanjiIndexObj_str = v218;
  v220 = get_transform(NameUIObj, 0);
  v221 = Find(v220, kanjiIndexObj_str, 0);
  v222 = get_gameObject(v221);
  kanjiIndexObj = v222;
  v224 = GetComponent_object_(kanjiIndexObj);
  kanjiIndexObj_anim = v224;
  v226 = sub_8D3950(s32, &kanjiScrollcnt);
  v227 = Format("Text_letter{0:00}", v226, 0);
  v228 = Concat_5224608("namelist/name_kanji/name_kanji_box/namelist_box01/", v227);
  scrollindex_text = v228;
  v358 = kanjiScrollcnt;
  v230 = sub_8D3950(s32, &v358);
  v231 = Format("Text_letter{0:00}TM", v230, 0);
  v232 = Concat_5224608("namelist/name_kanji/name_kanji_box/namelist_box01/", v231);
  scrollindex_tmptext = v232;
  v234 = get_transform(NameUIObj, 0);
  v235 = Find(v234, scrollindex_text, 0);
  v236 = get_gameObject(v235);
  kanjiIndexList = v236;
  v238 = get_transform(NameUIObj, 0);
  v239 = Find(v238, scrollindex_tmptext, 0);
  v240 = get_gameObject(v239);
  kanjiIndexTmpList = v240;
  v242 = sub_8D3950(s32, &bup_namenum);
  v243 = Format("nameinput_letter{0:00}/Text", v242, 0);
  v244 = Concat_5224608("nameinput/namefull/stretch/", v243);
  name_obj_str = v244;
  v356 = bup_namenum;
  v246 = sub_8D3950(s32, &v356);
  v247 = Format("nameinput_letter{0:00}/TextTM", v246, 0);
  v248 = Concat_5224608("nameinput/namefull/stretch/", v247);
  tmpname_obj_str = v248;
  v250 = get_transform(NameUIObj, 0);
  v251 = Find(v250, name_obj_str, 0);
  v252 = get_gameObject(v251);
  name_obj = v252;
  v254 = get_transform(NameUIObj, 0);
  v255 = Find(v254, tmpname_obj_str, 0);
  v256 = get_gameObject(v255);
  tmpname_obj = v256;
  v258 = sub_8D3950(s32, &bup_cnamenum);
  v259 = Format("nameinput_letter{0:00}/Text", v258, 0);
  v260 = Concat_5224608("nameinput/namenick/stretch/", v259);
  cname_obj_str = v260;
  v354 = bup_cnamenum;
  v262 = sub_8D3950(s32, &v354);
  v263 = Format("nameinput_letter{0:00}/TextTM", v262, 0);
  v264 = Concat_5224608("nameinput/namenick/stretch/", v263);
  tmpcname_obj_str = v264;
  v266 = get_transform(NameUIObj, 0);
  v267 = Find(v266, cname_obj_str, 0);
  v268 = get_gameObject(v267);
  cname_obj = v268;
  v270 = get_transform(NameUIObj, 0);
  v271 = Find(v270, tmpcname_obj_str, 0);
  v272 = get_gameObject(v271);
  tmpcname_obj = v272;
  v274 = sub_8D3950(s32, &nameend_namenum);
  v275 = Format("nameinput_letter{0:00}/Text", v274, 0);
  v276 = Concat_5224608("nameinput/nameconfirm/namefull/stretch/", v275);
  nameend_name_str = v276;
  v352 = nameend_namenum;
  v278 = sub_8D3950(s32, &v352);
  v279 = Format("nameinput_letter{0:00}/TextTM", v278, 0);
  v280 = Concat_5224608("nameinput/nameconfirm/namefull/stretch/", v279);
  tmpnameend_name_str = v280;
  v282 = get_transform(NameUIObj, 0);
  v283 = Find(v282, nameend_name_str, 0);
  v284 = get_gameObject(v283);
  nameend_name = v284;
  v286 = get_transform(NameUIObj, 0);
  v287 = Find(v286, nameend_name_str, 0);
  v288 = get_gameObject(v287);
  tmpnameend_name = v288;
  v290 = sub_8D3950(s32, &nameend_cnamenum);
  v291 = Format("nameinput_letter{0:00}/Text", v290, 0);
  v292 = Concat_5224608("nameinput/nameconfirm/namenick/stretch/", v291);
  nameend_cname_str = v292;
  v350 = nameend_namenum;
  v294 = sub_8D3950(s32, &v350);
  v295 = Format("nameinput_letter{0:00}/TextTM", v294, 0);
  v296 = Concat_5224608("nameinput/nameconfirm/namefull/stretch/", v295);
  tmpnameend_cname_str = v296;
  v298 = get_transform(NameUIObj, 0);
  v299 = Find(v298, nameend_cname_str, 0);
  v300 = get_gameObject(v299);
  nameend_cname = v300;
  v302 = get_transform(NameUIObj, 0);
  v303 = Find(v302, nameend_cname_str, 0);
  v304 = get_gameObject(v303);
  tmpnameend_cname = v304;
  v306 = sub_8D3950(s32, &underline_num);
  v307 = Format("nameinput_letter{0:00}/nameinput_cursur", v306, 0);
  v308 = Concat_5224608("nameinput/namefull/stretch/", v307);
  name_underline_str = v308;
  v310 = get_transform(NameUIObj, 0);
  v311 = Find(v310, name_underline_str, 0);
  v312 = get_gameObject(v311);
  name_underline = v312;
  v314 = sub_8D3950(s32, &underline_num_c);
  v315 = Format("nameinput_letter{0:00}/nameinput_cursur", v314, 0);
  v316 = Concat_5224608("nameinput/namenick/stretch/", v315);
  cname_underline_str = v316;
  v318 = get_transform(NameUIObj, 0);
  v319 = Find(v318, cname_underline_str, 0);
  v320 = get_gameObject(v319);
  cname_underline = v320;
  v322 = get_transform(NameUIObj, 0);
  v323 = Find(v322, "nameinput/namefull/stretch/stretch_sur/TextTM", 0);
  v324 = get_gameObject(v323);
  SeiText = v324;
  v326 = GetComponent_object_(SeiText);
  SeiTextTM = v326;
  v328 = get_transform(NameUIObj, 0);
  v329 = Find(v328, "nameinput/namefull/stretch/stretch_name/TextTM", 0);
  v330 = get_gameObject(v329);
  MeiText = v330;
  v332 = GetComponent_object_(MeiText);
  MeiTextTM = v332;
  v334 = get_transform(NameUIObj, 0);
  v335 = Find(v334, "namemode/namelr_iconl/button_l", 0);
  v336 = get_gameObject(v335);
  ButtonL = v336;
  v338 = get_transform(NameUIObj, 0);
  v339 = Find(v338, "namemode/namelr_iconl/button_l_PS4", 0);
  v340 = get_gameObject(v339);
  ButtonL_PS4 = v340;
  v342 = get_transform(NameUIObj, 0);
  v343 = Find(v342, "namemode/namelr_iconr/tbutton_r", 0);
  v344 = get_gameObject(v343);
  ButtonR = v344;
  v346 = get_transform(NameUIObj, 0);
  v347 = Find(v346, "namemode/namelr_iconr/tbutton_r_PS4", 0);
  ButtonR_PS4 = get_gameObject(v347);
}

// 0xf1e1b0
void NameInit2(void) {
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v5;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v7;
  UnityEngine_Component_o *v8;
  struct UnityEngine_GameObject_o *v9;
  Il2CppObject *Component_object;
  UnityEngine_Transform_o *v14;
  UnityEngine_Component_o *v15;
  struct UnityEngine_GameObject_o *v16;
  Il2CppObject *v18;
  UnityEngine_Transform_o *v20;
  UnityEngine_Component_o *v21;
  struct UnityEngine_GameObject_o *v22;
  UnityEngine_Transform_o *v24;
  UnityEngine_Component_o *v25;
  struct UnityEngine_GameObject_o *v26;
  UnityEngine_Transform_o *v28;
  UnityEngine_Component_o *v29;
  struct UnityEngine_GameObject_o *v30;
  UnityEngine_Transform_o *v32;
  UnityEngine_Component_o *v33;
  UnityEngine_GameObject_o *v34;
  UnityEngine_Transform_o *v35;
  UnityEngine_Component_o *v36;
  UnityEngine_GameObject_o *v37;
  Nme_Draw_c *v39;
  struct Nme_Draw_StaticFields *static_fields;
  struct Nme_Draw_StaticFields **p_static_fields;
  u64 v43;
  struct System_String_array_array *nmeTblList22;
  u64 *v48;
  u64 *v49;
  u64 *v50;
  System_String_o *v51;
  System_String_o *v52;
  u64 *v53;
  u64 *v54;
  u64 *v55;
  System_String_o *v56;
  UnityEngine_Transform_o *v57;
  UnityEngine_Component_o *v58;
  UnityEngine_GameObject_o *v59;
  Il2CppObject *v61;
  struct System_String_array_array *v62;
  System_String_array *v63;
  Nme_Draw_c *v65;
  struct Nme_Draw_StaticFields *v66;
  struct Nme_Draw_StaticFields **v67;
  s32 v68;
  u64 *v74;
  System_String_o *v75;
  struct System_String_o *v76;
  UnityEngine_Transform_o *v78;
  UnityEngine_Component_o *v79;
  struct UnityEngine_GameObject_o *v80;
  struct UnityEngine_GameObject_array *kanaList;
  UnityEngine_Object_o *v85;
  struct UnityEngine_GameObject_array *v89;
  UnityEngine_Transform_o *v90;
  UnityEngine_Component_o *v91;
  s64 *v92;
  s64 *v93;
  struct UnityEngine_GameObject_array *v97;
  struct TMPro_TextMeshProUGUI_array *kanaListTP;
  s64 *v100;
  s64 *v101;
  struct TMPro_TextMeshProUGUI_array *v103;
  TMPro_TMP_Text_o *v104;
  System_String_o *text;
  System_Object_array *v106;
  s64 *v107;
  s64 *v109;
  System_String_o *v111;
  s32 v125;
  s32 v126;
  s32 v127;
  s32 letter_num;
  s32 box_num;
  s32 kanabox_num;
  UnityEngine_Vector2_o anchoredPosition;
  UnityEngine_Vector3_o v132;
  UnityEngine_Vector3_o v133;
  UnityEngine_Vector2_o v134;

  GetoNameUI();
  transform = get_transform(NameUIObj, 0);
  v5 = Find(transform, "nameinput", 0);
  gameObject = get_gameObject(v5);
  v7 = get_transform(NameUIObj, 0);
  v8 = Find(v7, "nameinput/namefull", 0);
  v9 = get_gameObject(v8);
  mynameImage = v9;
  Component_object = GetComponent_object_(mynameImage);
  anchoredPosition = get_anchoredPosition(Component_object);
  v132 = op_Implicit_8725680(anchoredPosition);
  mynameImagePos = v132;
  v14 = get_transform(NameUIObj, 0);
  v15 = Find(v14, "nameinput/namenick", 0);
  v16 = get_gameObject(v15);
  codenameImage = v16;
  v18 = GetComponent_object_(codenameImage);
  v134 = get_anchoredPosition(v18);
  v133 = op_Implicit_8725680(v134);
  codenameImagePos = v133;
  v20 = get_transform(NameUIObj, 0);
  v21 = Find(v20, "namelist_button", 0);
  v22 = get_gameObject(v21);
  functionImage = v22;
  v24 = get_transform(NameUIObj, 0);
  v25 = Find(v24, "namelist", 0);
  v26 = get_gameObject(v25);
  name_list = v26;
  v28 = get_transform(NameUIObj, 0);
  v29 = Find(v28, "namelist/namelist_cursur", 0);
  v30 = get_gameObject(v29);
  listcursur = v30;
  v32 = get_transform(NameUIObj, 0);
  v33 = Find(v32, "namechoice", 0);
  v34 = get_gameObject(v33);
  v35 = get_transform(NameUIObj, 0);
  v36 = Find(v35, "talk01_choice", 0);
  v37 = get_gameObject(v36);
  SetActive(gameObject, 1, 0);
  SetActive(codenameImage, 0, 0);
  SetActive(functionImage, 1, 0);
  SetActive(v34, 0, 0);
  SetActive(v37, 0, 0);
  SetActive(listcursur, 1, 0);
  SetActive(name_list, 1, 0);
  box_num = 1;
  letter_num = 1;
  kanabox_num = 3;
  endChoiceflag = 0;
  nameEndChackflag = 0;
  if (defnameChackflag)
  {
    if ((v39->_2.bitflags2 & 2) == 0)
      goto LABEL_21;
  }
  else
  {
    defname = 0;
    defnameChackflag = 1;
    if ((v39->_2.bitflags2 & 2) == 0)
      goto LABEL_21;
  }
LABEL_21:
  if (mojilist)
    goto LABEL_79;
LABEL_22:
  kanabox_numbup = kanabox_num;
  (*p_static_fields)->kanabox_num = 3;
  (*p_static_fields)->box_num = 1;
  (*p_static_fields)->letter_num = 1;
  v43 = 0;
    goto LABEL_28;
LABEL_29:
  if (!LODWORD(nmeTblList22->max_length))
  {
LABEL_30:
  }
  while (1)
  {
    if (v43 >= SLODWORD(nmeTblList22->m_Items[0]->max_length))
      break;
    v48 = sub_8D3950(s32, &kanabox_num);
    v49 = sub_8D3950(s32, &box_num);
    v50 = sub_8D3950(s32, &letter_num);
    v51 = Format_5268688("name_kana_box{0:00}/namelist_box{1:00}/Text_letter{2:00}TM", v48, v49, v50);
    v52 = Concat_5224608("namelist/name_kana/", v51);
    v127 = kanabox_num;
    v53 = sub_8D3950(s32, &v127);
    v126 = box_num;
    v54 = sub_8D3950(s32, &v126);
    v125 = letter_num;
    v55 = sub_8D3950(s32, &v125);
    v56 = Format_5268688("name_kana_box{0:00}/namelist_box{1:00}/Text_letter{2:00}", v53, v54, v55);
    Concat_5224608("namelist/name_kana/", v56);
    v57 = get_transform(NameUIObj, 0);
    v58 = Find(v57, v52, 0);
    v59 = get_gameObject(v58);
    v61 = GetComponent_object_(v59);
    else
    {
      v62 = nmeTblList22;
      if (!LODWORD(v62->max_length))
        goto LABEL_72;
    }
    v63 = v62->m_Items[0];
    set_text(v61, v63->m_Items[v43]);
    v68 = box_num;
    if (v68 <= 4)
    {
      else
      {
        box_num = v68 + 1;
        if ((v65->_2.bitflags2 & 2) == 0)
          goto LABEL_55;
      }
    }
    else
    {
            v65 = Nme_Draw,
            v67 = &Nme_Draw->static_fields,
            v66 = Nme_Draw->static_fields,
            box_num >= 5))
      {
        box_num = 1;
        --(*v67)->kanabox_num;
      }
      if ((v65->_2.bitflags2 & 2) == 0)
        goto LABEL_55;
    }
LABEL_55:
    if (kanabox_num > 0)
    {
LABEL_56:
      if ((v65->_2.bitflags2 & 2) == 0)
        goto LABEL_64;
      goto LABEL_57;
    }
LABEL_60:
    kanabox_num = 3;
    ++letter_num;
    if ((v65->_2.bitflags2 & 2) == 0)
    {
LABEL_64:
      if (letter_num < 7)
        goto LABEL_27;
      goto LABEL_65;
    }
LABEL_57:
      goto LABEL_64;
    if (letter_num < 7)
      goto LABEL_27;
LABEL_65:
    letter_num = 1;
LABEL_27:
    ++v43;
      goto LABEL_29;
LABEL_28:
      goto LABEL_29;
    if (!LODWORD(nmeTblList22->max_length))
      goto LABEL_30;
  }
  kanabox_num = kanabox_numbup;
  box_num = 1;
  letter_num = 1;
LABEL_79:
  ButtonGuideDispSet("NAME01", 0, 0, 90);
  kanabox_num = 3;
  box_num = 1;
  letter_num = 1;
  underLineflag = 1;
  kanabox_num = underline_num;
  v74 = sub_8D3950(s32, &kanabox_num);
  v75 = Format("nameinput_letter{0:00}/nameinput_cursur", v74, 0);
  v76 = Concat_5224608("nameinput/namefull/stretch/", v75);
  name_underline_str = v76;
  v78 = get_transform(NameUIObj, 0);
  v79 = Find(v78, name_underline_str, 0);
  v80 = get_gameObject(v79);
  name_underline = v80;
  SetActive(name_underline, 1, 0);
  v85 = kanaList->m_Items[0];
  if (op_Equality(v85, 0, 0))
  {
    v89 = kanaList;
    v90 = get_transform(NameUIObj, 0);
    v91 = Find(v90, "namemode/namelr_menu/namemode01/stretch_on/Text", 0);
    v92 = get_gameObject(v91);
    v93 = v92;
    v89->m_Items[0] = v93;
  }
  v97 = kanaList;
  v100 = GetComponent_object_(v97->m_Items[0]);
  v101 = v100;
  kanaListTP->m_Items[0] = v101;
  v103 = kanaListTP;
  v104 = v103->m_Items[0];
  text = get_text(kanaListTP->m_Items[0]);
  v106 = NewSpecific(object, 1u);
  kanabox_num = 12;
  v107 = sub_8D3950(s32, &kanabox_num);
  v109 = v107;
  v106->m_Items[0] = v109;
  v111 = RepColTag(text, v106);
  set_text(v104, v111);
  if (GetInteger(kanalist_hira_anim, "namemode") != 1)
  {
    SetInteger(kanalist_hira_anim, "namemode", 1);
  }
  if (!get_activeSelf(ButtonL))
  {
    SetActive(ButtonL, 1, 0);
  }
  if (!get_activeSelf(ButtonR))
  {
    SetActive(ButtonR, 1, 0);
  }
  ++name_fadecnt;
  nameInitflag = 1;
}

// 0xf22280
void NameInputAnim(void) {
  s16 v3;
  s32 v4;

  if ((v3 & 0x200) != 0)
  {
    v4 = v3 & 0x200;
    if (NameAnim0 != 1)
      goto LABEL_5;
LABEL_23:
    if (GetInteger(_name_input, "nameimput"))
    {
      SetInteger(_name_input, "nameimput", 0);
    }
    NameAnim0 = 0;
    return;
  }
  v4 = 0;
  if (NameAnim0 == 1)
    goto LABEL_23;
LABEL_5:
  else if (NameAnim1 == 1)
  {
    goto LABEL_8;
  }
  else if (NameAnim2 == 1)
  {
    goto LABEL_40;
  }
  if (NameAnim3 == 1)
  {
    if (GetInteger(_name_input, "nameimput") != 3)
    {
      SetInteger(_name_input, "nameimput", 3);
    }
    NameAnim3 = 0;
  }
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
  if (GetInteger(namelist_buttonAnim_r, "namebutton"))
  {
    SetInteger(namelist_buttonAnim_r, "namebutton", 0);
  }
  if (GetInteger(namelist_buttonAnim_l, "namebutton"))
  {
    SetInteger(namelist_buttonAnim_l, "namebutton", 0);
  }
  if (GetInteger(namelist_buttonAnim_del, "namebutton"))
  {
    SetInteger(namelist_buttonAnim_del, "namebutton", 0);
  }
  if (GetInteger(namelist_buttonAnim_end, "namebutton"))
  {
    SetInteger(namelist_buttonAnim_end, "namebutton", 0);
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
      if (GetInteger(namelist_buttonAnim_r, "namebutton") != 1)
      {
        SetInteger(namelist_buttonAnim_r, "namebutton", 1);
      }
      if (!GetInteger(namelist_buttonAnim_l, "namebutton"))
        goto LABEL_88;
      goto LABEL_87;
    case 1:
      if (GetInteger(namelist_buttonAnim_l, "namebutton") != 1)
      {
        SetInteger(namelist_buttonAnim_l, "namebutton", 1);
      }
      if (GetInteger(namelist_buttonAnim_r, "namebutton"))
      {
        namelist_buttonAnim_l = namelist_buttonAnim_r;
LABEL_87:
        SetInteger(namelist_buttonAnim_l, "namebutton", 0);
      }
LABEL_88:
      if (!GetInteger(namelist_buttonAnim_del, "namebutton"))
        goto LABEL_121;
      goto LABEL_120;
    case 2:
      if (GetInteger(namelist_buttonAnim_del, "namebutton") != 1)
      {
        SetInteger(namelist_buttonAnim_del, "namebutton", 1);
      }
      if (GetInteger(namelist_buttonAnim_r, "namebutton"))
      {
        SetInteger(namelist_buttonAnim_r, "namebutton", 0);
      }
      if (!GetInteger(namelist_buttonAnim_l, "namebutton"))
        goto LABEL_121;
      namelist_buttonAnim_del = namelist_buttonAnim_l;
LABEL_120:
      SetInteger(namelist_buttonAnim_del, "namebutton", 0);
LABEL_121:
      if (!GetInteger(namelist_buttonAnim_end, "namebutton"))
        return;
LABEL_161:
      SetInteger(namelist_buttonAnim_end, "namebutton", 0);
      break;
    case 3:
      if (GetInteger(namelist_buttonAnim_end, "namebutton") != 1)
      {
        SetInteger(namelist_buttonAnim_end, "namebutton", 1);
      }
      if (GetInteger(namelist_buttonAnim_r, "namebutton"))
      {
        SetInteger(namelist_buttonAnim_r, "namebutton", 0);
      }
      if (GetInteger(namelist_buttonAnim_l, "namebutton"))
      {
        SetInteger(namelist_buttonAnim_l, "namebutton", 0);
      }
      if (!GetInteger(namelist_buttonAnim_del, "namebutton"))
        return;
      namelist_buttonAnim_end = namelist_buttonAnim_del;
      goto LABEL_161;
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

  pStr = "00";
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
      Tex = GBWK->Tex;
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
LABEL_47:
    goto LABEL_49;
  }
  while (1)
  {
LABEL_49:
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
      goto LABEL_47;
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
  u16 v25;
  u16 v28;
  sdfTexHandle_t_array *Tex;
  fclSprTblArry_t_array *nmeSprTblArry;
  s64 v34;
  s64 v37;
  sdfTexHandle_t_array *v42;
  fclSprTblArry_t_array *v43;
  System_UInt32_array *v50;
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
        goto LABEL_28;
      goto LABEL_57;
    }
    v28 = *(v22 + 33);
    Tex = GBWK->Tex;
    fclDrawParts(0, 0, 0, 0, 0, v28, Tex, nmeSprTblArry, 0x47u);
    if (Flag < 2u)
    {
      v37 = v19[v18];
      v25 = *(v37 + 34);
        goto LABEL_57;
LABEL_28:
LABEL_57:
      v42 = GBWK->Tex;
      v43 = nmeSprTblArry;
      fclDrawParts(0, 0, 0, 0, 0, v25, v42, v43, 0x47u);
      goto LABEL_64;
    }
    if (Flag == 2)
      break;
LABEL_64:
    if (++v18 == 4)
      return;
  }
  v34 = v19[v18];
  v25 = *(v34 + 34);
  if (v18 != 3)
  {
      goto LABEL_28;
    goto LABEL_57;
  }
  {
    v50 = pCol;
  }
  else
  {
    v50 = pCol;
  }
  v53 = GBWK->Tex;
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

  v7 = "00";
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
LABEL_60:
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
      if (InputMode >= *(v12 + 6))
      {
LABEL_19:
      }
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
          goto LABEL_19;
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
  pStr = "00";
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

  pStr = "00";
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
LABEL_83:
    goto LABEL_85;
  }
  while (1)
  {
LABEL_85:
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
      goto LABEL_83;
  }
  v68 = CMP_X(X2 - 19);
  v70 = CMP_Y(Y2 + 9);
  v72 = GBWK->Tex;
  v74 = nmeSprTblArry;
  fclDrawParts(v68, v70, 0, 0, 0, 0x12u, v72, v74, 0x47u);
  v76 = 0;
  v77 = 16 * X2;
  {
LABEL_125:
    goto LABEL_127;
  }
  while (1)
  {
LABEL_127:
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
      goto LABEL_125;
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
  v4[4] = "これでよろしいでしょうか";
  v4[5] = "はい";
  v4[6] = "いいえ";
  v8 = v4[4];
  v9 = frLinkFontString(v8, 0, 0, 0, 0);
  frSetDrawPosition(v9, 9600, 5600);
  frSetPriority(v9, 0xFF0u);
  frDrawFontEx2(v9, 0, 0x47u);
  frDestroyFontRequestAfter(v9);
  v11 = frLinkFontString(v4[5], 0, 0, 0, 0);
  frSetDrawPosition(v11, 9600, 6400);
  if (Pos)
  {
      goto LABEL_31;
    goto LABEL_22;
  }
  frSetFontColorNo(v11, 1u);
  nmeDrawYesNoCursorBase(9552, 6416, 0xFFu);
  {
LABEL_22:
  }
LABEL_31:
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
  System_UInt32_array *v8;
  il2cpp_array_size_t max_length;

  v8 = NewSpecific(uint, 4u);
  else
  {
    max_length = v8->max_length;
    if (!max_length)
      goto LABEL_6;
  }
  v8->m_Items[0] = 1159734912;
  v8->m_Items[1] = 0;
  v8->m_Items[2] = v8->m_Items[0];
  v8->m_Items[3] = 0;
  cmpDrawBoxG(X, Y, Z, 79, 22, v8, 0x47u);
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
