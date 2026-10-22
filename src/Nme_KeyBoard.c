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
static char *NameSave;
static char *NameSave2[3];
static char *kariif;
static char *NameDecRcl_[3];
static char *NameDesRcl_[3];
static void *NameKeyBoardUI;
static void *NameSet;
static void *NameSetTM;
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
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v4;
  struct UnityEngine_GameObject_o *gameObject;
  s32 width;
  s32 height;
  u64 *v12;
  UnityEngine_Texture2D_o *BackImageTex;
  s32 v17;
  s32 v18;
  UnityEngine_Rect_o v19;

  transform = get_transform(NameUIObj, 0);
  v4 = Find(transform, "RawImage", 0);
  gameObject = get_gameObject(v4);
  RenImageObj = gameObject;
  if (!get_activeSelf(RenImageObj))
  {
    SetActive(RenImageObj, 1, 0);
  }
  RenImage = GetComponent_object_(RenImageObj);
  width = get_width(0);
  height = get_height(0);
  v12 = Allocate(UnityEngine_RenderTexture);
  _ctor_27407312(v12, width, height, 0);
  RenTex = v12;
  set_name(RenTex, "RenRT");
  set_targetTexture(CameraR, RenTex);
  Render(CameraR, 0);
  set_active(RenTex, 0);
  v17 = get_width(0);
  v18 = get_height(0);
  *&v19.m_XMin = 0;
  *&v19.m_Width = 0;
  sub_1A1D780(&v19.m_XMin, 0.0, 0.0, v17, v18);
  ReadPixels_27473280(BackImageTex, v19, 0, 0);
  Apply_27472496(BackImageTex);
  set_texture(RenImage, BackImageTex);
  set_targetTexture(CameraR, 0);
  set_active(0, 0);
  BackImageTex = 0;
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
  s16 v6;
  s32 v7;
  s16 v9;
  s32 v10;
  s16 v11;
  s32 v12;
  struct Nme_KeyBoard_StaticFields **p_static_fields;
  struct cmpSeqInfo_t_o *SeqInfo;
  struct Nme_KeyBoard_StaticFields **v20;

  v3 = cmpChkCommonInput(0xF3u);
  if (v3 <= 2)
  {
    if (v3 != 1)
    {
      if (v3 != 2)
        goto LABEL_61;
      yesnoBackflag = 1;
      goto LABEL_56;
    }
    if ((v9 & 0x200) != 0)
    {
      v10 = v9 & 0x200;
    }
    else
    {
      v10 = 0;
    }
    if (yesnoswith == 1)
    {
      yesnoBackflag = 1;
      if ((v4->_2.bitflags2 & 2) == 0)
        goto LABEL_56;
    }
    else
    {
      yesnoflag = 0;
      (*p_static_fields)->yesnoInitflag = 0;
      nmeFadeOut();
      SeqInfo = GBWK->SeqInfo;
      SeqInfo->Flag |= 0x10u;
      GBWK->CfmFlag = 2;
      if ((v4->_2.bitflags2 & 2) == 0)
        goto LABEL_56;
    }
LABEL_56:
    if (GetInteger(name_end_anim, "talk_choice"))
    {
      SetInteger(name_end_anim, "talk_choice", 0);
    }
LABEL_61:
      goto LABEL_64;
    goto LABEL_62;
  }
  if (v3 == 16)
  {
    if ((v11 & 0x200) != 0)
    {
      v12 = v11 & 0x200;
      if (yesnoswith)
      {
LABEL_24:
        if (!v12)
          goto LABEL_25;
        goto LABEL_18;
      }
    }
    else
    {
      v12 = 0;
      if (yesnoswith)
        goto LABEL_24;
    }
    if (!v12)
      goto LABEL_47;
    goto LABEL_31;
  }
  if (v3 != 32)
    goto LABEL_61;
  if ((v6 & 0x200) != 0)
  {
    v7 = v6 & 0x200;
    if (yesnoswith)
    {
LABEL_17:
      if (!v7)
        goto LABEL_25;
LABEL_18:
LABEL_25:
      yesnoswith = 0;
        goto LABEL_64;
      goto LABEL_62;
    }
  }
  else
  {
    v7 = 0;
    if (yesnoswith)
      goto LABEL_17;
  }
  if (v7)
  {
LABEL_31:
  }
LABEL_47:
  yesnoswith = 1;
    goto LABEL_64;
LABEL_62:
LABEL_64:
  cmpPlaySE2(v3, 2);
  if (yesnoBackflag == 1)
  {
    NameUIPos = 0;
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
  s32 v4;
  f32 *v6;
  u64 v7;
  s32 v8;
  f32 v9;
  System_Collections_Generic_IEnumerable_TSource__o *Pixels_27473296;
  u64 *_9__111_0;
  Il2CppObject *v16;
  System_Collections_Generic_IEnumerable_TSource__o *v17;
  System_Single_array *v18;
  u64 *v19;
  u64 *v20;
  s64 v21;
  s64 v22;
  s64 v23;
  u32 v24;
  f32 v27;
  f32 v36;
  s64 v46;
  u32 *v47;
  s32 v48;
  s32 v49;
  s32 v50;
  s64 v51;
  s64 v52;
  u64 *v53;
  u32 v54;
  f32 v55;
  f32 v66;
  s32 v75;
  s32 v76;
  s32 v77;
  UnityEngine_Texture2D_o *v80;
  s64 v81;
  s32 v82;
  s32 v83;
  s32 v84;
  s64 v85;
  u32 *v86;
  s64 v87;
  s64 v88;
  UnityEngine_Color_array *colors;
  s64 v90;
  s32 v91;
  s64 v92;
  s32 v93;
  s64 v94;
  s32 v95;
  _BOOL4 v96;
  _BOOL4 v97;
  _BOOL4 v98;
  s64 v99;
  s64 v100;
  s64 v101;
  s64 v102;
  s64 v103;
  s64 v104;
  u64 *v105;
  s32 v106;
  s64 v107;
  s64 v108;
  UnityEngine_Color_o v109;

  v106 = (Text->klass->vtable._4_get_width.methodPtr)(Text, Text->klass->vtable._4_get_width.method);
  v4 = (Text->klass->vtable._6_get_height.methodPtr)(Text, Text->klass->vtable._6_get_height.method);
  v6 = NewSpecific(f32, 9u);
  v7 = 0;
  v8 = 4;
  do
  {
    v9 = expf((v8 * (v7 - 4)) * 0.125);
    v6[v7++ + 8] = v9 / 5.0133;
    --v8;
  }
  while (v7 != 9);
  v109.r = 0.0;
  v109.g = 0.0;
  v109.b = 0.0;
  v109.a = 0.0;
  SetPixel(Text, v106, v4, v109);
  Pixels_27473296 = GetPixels_27473296(Text, 0);
  v80 = Text;
  else
  {
    _9__111_0 = __9__111_0;
    if (_9__111_0)
      goto LABEL_21;
  }
  v16 = __9;
  _9__111_0 = Allocate(System_Func_Color__float_);
  float____ctor(
    _9__111_0,
    v16,
    Method_Nme_KeyBoard___c__ImageBlur_b__111_0__);
  __9__111_0 = _9__111_0;
LABEL_21:
  v17 = Select_Color__float_(Pixels_27473296, _9__111_0);
  v18 = ToArray_float_(v17);
  v19 = NewSpecific(f32, LODWORD(v18->max_length));
  v20 = NewSpecific(UnityEngine_Color, LODWORD(v18->max_length));
  colors = v20;
  if (v106 >= 1 && v4 >= 1)
  {
    v102 = 4LL * v106;
    v93 = 4 * v106;
    v95 = 2 * v106;
    v105 = v19;
    v81 = v4;
    v21 = 0;
    v22 = 0;
    v91 = 3 * v106;
    while (1)
    {
      v23 = -4;
      v85 = v22;
      v87 = v21;
      v24 = v22;
      do
      {
        v27 = 0.0;
        if ((v23 & 0x8000000000000000LL) == 0)
        {
          v27 = (v6[8] * *(v18->m_Items + v21 + -16 * v106)) + 0.0;
        }
        if (v23 + 1 >= 0)
        {
          v27 = v27 + (v6[9] * *(v18->m_Items + v21 + -12 * v106));
        }
        if (v23 + 2 < 0)
        {
          if (v23 == -4)
          {
            if (*(v6 + 6) <= 4uLL)
              goto LABEL_30;
            goto LABEL_51;
          }
        }
        else
        {
          v27 = v27 + (v6[10] * *(v18->m_Items + v21 + -8 * v106));
        }
        v27 = v27 + (v6[11] * *(&v18->m_Items[v102 / 0xFFFFFFFFFFFFFFFCLL] + v21));
        if (*(v6 + 6) <= 4uLL)
        {
LABEL_30:
        }
LABEL_51:
        v36 = v27 + (v6[12] * *(v18->m_Items + v21));
        if (v23 + 5 < v4)
        {
          v36 = v36 + (v6[13] * *(&v18->m_Items[v102 / 4] + v21));
        }
        if (v23 + 6 >= 0 && v23 + 6 < v4)
        {
          v36 = v36 + (v6[14] * v18->m_Items[v95 + v24]);
        }
        if (v23 + 7 >= 0 && v23 + 7 < v4)
        {
          v36 = v36 + (v6[15] * v18->m_Items[v91 + v24]);
        }
        if (v23 + 8 >= 0 && v23 + 8 < v4)
        {
          v36 = v36 + (v6[16] * v18->m_Items[v93 + v24]);
        }
        v24 += v106;
        ++v23;
        *(v19 + v21 + 32) = v36;
        v21 += v102;
      }
      while (v23 - v4 != -4);
      ++v22;
      v21 = v87 + 4;
      if (v85 + 1 == v106)
      {
        v46 = 0;
        v47 = v20 + 11;
        v48 = 4;
        v49 = 2;
        v50 = 3;
        v51 = 36;
        while (1)
        {
          v82 = v50;
          v83 = v49;
          v94 = 4LL * v49 + 32;
          v92 = 4LL * v50 + 32;
          v90 = 4LL * v48 + 32;
          v101 = v46 - 3;
          v86 = v47;
          v88 = v46;
          v52 = v81;
          v103 = v46 - 4;
          v53 = v19;
          v54 = v48;
          v100 = v46 - 2;
          v99 = v46 + 1;
          v98 = v46 + 2 >= 0 && v46 + 2 < v106;
          v97 = v46 + 3 >= 0 && v46 + 3 < v106;
          v96 = v46 + 4 >= 0 && v46 + 4 < v106;
          v84 = v48;
          v104 = v51;
          do
          {
            v55 = 0.0;
            if ((v103 & 0x8000000000000000LL) == 0)
            {
              v55 = (v6[8] * *(v53 + v51 - 20)) + 0.0;
            }
            if ((v101 & 0x8000000000000000LL) == 0)
            {
              v55 = v55 + (v6[9] * *(v53 + v51 - 16));
            }
            if (v100 < 0)
            {
              if (!v88)
                goto LABEL_111;
              if ((v6[6] & 0xFFFFFFFC) == 0)
                goto LABEL_107;
            }
            else
            {
              v55 = v55 + (v6[10] * *(v53 + v51 - 12));
              if ((v6[6] & 0xFFFFFFFC) == 0)
              {
LABEL_107:
              }
            }
            v55 = v55 + (v6[11] * *(v53 + v51 - 8));
LABEL_111:
            v66 = v55 + (v6[12] * *(v53 + v51 - 4));
            if (v99 < v106)
            {
              v66 = v66 + (v6[13] * *(v53 + v51));
              if (!v98)
              {
LABEL_117:
                if (!v97)
                  goto LABEL_118;
                goto LABEL_134;
              }
            }
            else if (!v98)
            {
              goto LABEL_117;
            }
            v66 = v66 + (v6[14] * *(v53 + v94));
            if (!v97)
            {
LABEL_118:
              if (!v96)
                goto LABEL_139;
LABEL_119:
              v66 = v66 + (v6[16] * *(v53 + v90));
              goto LABEL_139;
            }
LABEL_134:
            v66 = v66 + (v6[15] * *(v53 + v92));
            if (v96)
              goto LABEL_119;
LABEL_139:
            v107 = 0;
            v108 = 0;
            sub_19EC630(&v107, v66 * 0.55, v66 * 0.55, v66 * 0.55, v66);
            v75 = HIDWORD(v107);
            v76 = v108;
            v77 = HIDWORD(v108);
            *(v47 - 3) = v107;
            *(v47 - 2) = v75;
            v19 = v105;
            *(v47 - 1) = v76;
            *v47 = v77;
            v51 = v104;
            v54 += v106;
            v53 = (v53 + 4 * v106);
            --v52;
            v47 += 4 * v106;
          }
          while (v52);
          v48 = v84 + 1;
          v46 = v88 + 1;
          v49 = v83 + 1;
          v50 = v82 + 1;
          v47 = v86 + 4;
          v51 = v104 + 4;
          if (v88 + 1 == v106)
            goto LABEL_143;
        }
      }
    }
  }
LABEL_143:
  SetPixels_27471904(v80, colors);
  Apply_27472496(v80);
  return v80;
}

// 0x18831e0
void KeyBoardDraw(char *Help, char *Name, s32 Num, s32 Lang) {
  switch (CharNo)
  {
    case 0:
    case 1:
    case 2:
    case 3:
      OpenIME(keyboardObj_a, Help, Name, Num, Lang, 0);
      break;
    default:
      return;
  }
}

// 0x18836c0
void KeyBoradEnd(void) {
  u64 v2;
  s32 yesnoOpeCnt;
  s32 v5;
  struct Nme_KeyBoard_StaticFields *v6;
  struct System_String_array *v14;
  TMPro_TMP_Text_o *v15;
  System_String_o *v17;
  System_String_o *v18;
  System_Object_array *v19;
  s64 *v20;
  s64 *v22;
  System_String_o *v24;
  struct System_String_array *v26;
  TMPro_TMP_Text_o *nemeend_noTM;
  System_String_o *v29;
  System_Object_array *v30;
  s32 v31;
  struct System_String_array *ChoicestrRcl;
  TMPro_TMP_Text_o *nemeend_yesTM;
  System_String_o *v42;
  System_String_o *LocalizeText;
  System_Object_array *v44;
  s64 *v45;
  s64 *v47;
  System_String_o *v50;
  struct System_String_array *v52;
  s64 *v54;
  s64 *v55;
  System_String_o *v57;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v61;
  struct UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  struct System_String_array *v68;
  TMPro_TMP_Text_o *nameend_decTM;
  System_String_o *v71;
  System_String_o *v72;
  System_Object_array *v73;
  s64 *v74;
  s64 *v76;
  System_String_o *v78;
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
  s32 v125;
  s32 v126;

  else
  {
    if (yesnoInitflag)
    {
LABEL_6:
      if (yesnoOpeCnt <= 15)
      {
        yesnoOpeCnt = yesnoOpeCnt + 1;
      }
      if (*(*(v2 + 184) + 60LL) >= 11)
      {
        EndKeyMove(v2);
      }
      if ((*(v2 + 294) & 0x200) == 0)
      {
        v5 = 0;
        v6 = *(v2 + 184);
        if (yesnoswith)
          goto LABEL_24;
LABEL_60:
        if (get_activeSelf(name_endcursorNo))
        {
          SetActive(name_endcursorNo, 0, 0);
        }
        if (!get_activeSelf(name_endcursorYes))
        {
          SetActive(name_endcursorYes, 1, 0);
        }
        v42 = ChoicestrRcl->m_Items[1];
        LocalizeText = GetLocalizeText(v42);
        v126 = 8;
        v44 = NewSpecific(object, 1u);
        v45 = sub_8D3950(s32, &v126);
        v47 = v45;
        v44->m_Items[0] = v47;
        v50 = RepColTag(LocalizeText, v44);
        set_text(nemeend_yesTM, v50);
        v52 = ChoicestrRcl;
        v29 = GetLocalizeText(v52->m_Items[2]);
        v30 = NewSpecific(object, 1u);
        v31 = 22;
        goto LABEL_95;
      }
      if (*(v2 + 216))
      {
        v5 = *(v2 + 294) & 0x200;
        v6 = *(v2 + 184);
        if (!yesnoswith)
          goto LABEL_60;
      }
      else
      {
        if (!yesnoswith)
          goto LABEL_60;
      }
LABEL_24:
      if (!get_activeSelf(name_endcursorNo))
      {
        SetActive(name_endcursorNo, 1, 0);
      }
      if (get_activeSelf(name_endcursorYes))
      {
        SetActive(name_endcursorYes, 0, 0);
      }
      v14 = ChoicestrRcl;
      v15 = nemeend_yesTM;
      v17 = v14->m_Items[1];
      v18 = GetLocalizeText(v17);
      v126 = 22;
      v19 = NewSpecific(object, 1u);
      v20 = sub_8D3950(s32, &v126);
      v22 = v20;
      v19->m_Items[0] = v22;
      v24 = RepColTag(v18, v19);
      set_text(v15, v24);
      v26 = ChoicestrRcl;
      v29 = GetLocalizeText(v26->m_Items[2]);
      v30 = NewSpecific(object, 1u);
      v31 = 8;
LABEL_95:
      v125 = v31;
      v54 = sub_8D3950(s32, &v125);
      v55 = v54;
      v30->m_Items[0] = v55;
      v57 = RepColTag(v29, v30);
      set_text(nemeend_noTM, v57);
      return;
    }
  }
  ButtonGuideDispOff();
  transform = get_transform(NameUIObj, 0);
  v61 = Find(transform, "namechoice/talk_window/Text01TM", 0);
  gameObject = get_gameObject(v61);
  nameend_dec = gameObject;
  Component_object = GetComponent_object_(nameend_dec);
  nameend_decTM = Component_object;
  v68 = ChoicestrRcl;
  v71 = v68->m_Items[0];
  v72 = GetLocalizeText(v71);
  v126 = 0;
  v73 = NewSpecific(object, 1u);
  v74 = sub_8D3950(s32, &v126);
  v76 = v74;
  v73->m_Items[0] = v76;
  v78 = RepColTag(v72, v73);
  set_text(nameend_decTM, v78);
  v79 = get_transform(NameUIObj, 0);
  v80 = Find(v79, "talk01_choice/choice_answer02/answer01TM", 0);
  v81 = get_gameObject(v80);
  nemeend_no = v81;
  v83 = GetComponent_object_(nemeend_no);
  nemeend_noTM = v83;
  v85 = get_transform(NameUIObj, 0);
  v86 = Find(v85, "talk01_choice/choice_answer01/answer01TM", 0);
  v87 = get_gameObject(v86);
  nemeend_yes = v87;
  v89 = GetComponent_object_(nemeend_yes);
  nemeend_yesTM = v89;
  v91 = get_transform(NameUIObj, 0);
  v92 = Find(v91, "talk01_choice/choice_answer02/choice_cursur", 0);
  v93 = get_gameObject(v92);
  name_endcursorNo = v93;
  v95 = GetComponent_object_(name_endcursorNo);
  name_endcursorNo_anim = v95;
  v97 = get_transform(NameUIObj, 0);
  v98 = Find(v97, "talk01_choice/choice_answer01/choice_cursur", 0);
  v99 = get_gameObject(v98);
  name_endcursorYes = v99;
  v101 = GetComponent_object_(name_endcursorYes);
  name_endcursorYes_anim = v101;
  v103 = get_transform(NameUIObj, 0);
  v104 = Find(v103, "talk01_choice", 0);
  v105 = get_gameObject(v104);
  name_end = v105;
  v107 = GetComponent_object_(name_end);
  name_end_anim = v107;
  v109 = get_transform(NameUIObj, 0);
  v110 = Find(v109, "namechoice", 0);
  v111 = get_gameObject(v110);
  name_end2 = v111;
  set_enabled(name_end_anim, 1);
  SetActive(name_end, 1, 0);
  SetActive(name_end2, 1, 0);
  if (GetInteger(name_endcursorNo_anim, "choice_cursur") != 1)
  {
    SetInteger(name_endcursorNo_anim, "choice_cursur", 1);
  }
  if (GetInteger(name_endcursorYes_anim, "choice_cursur"))
  {
    SetInteger(name_endcursorYes_anim, "choice_cursur", 0);
  }
  if (GetInteger(name_end_anim, "talk_choice") != 1)
  {
    SetInteger(name_end_anim, "talk_choice", 1);
  }
  yesnoInitflag = 1;
  yesnoOpeCnt = 0;
}

// 0x1882720
void KeyMove(void) {
  u16 v3;
  u64 v4;
  s16 v5;
  s32 v6;
  struct Nme_KeyBoard_StaticFields *static_fields;
  s32 NameUIPos;
  u32 v9;
  s32 v10;
  s16 v11;
  s32 v12;
  struct Nme_KeyBoard_StaticFields *v13;
  s32 v14;
  s16 v15;
  s32 v16;
  s32 v17;
  bool v18;
  s16 v19;
  s32 v20;
  s16 v21;
  s32 v22;
  struct Nme_KeyBoard_StaticFields *v23;
  s16 v24;
  s32 v25;
  s32 v26;
  bool v27;
  s16 v28;
  s32 v29;
  s32 v30;
  bool v31;
  s32 v33;
  s16 v34;
  s16 v35;
  bool v36;

  v3 = cmpChkCommonInput(0xF3u);
  if ((v5 & 0x200) != 0)
  {
    v6 = v5 & 0x200;
    static_fields = *(v4 + 184);
    v9 = v3;
    if (NameUIPos)
    {
LABEL_8:
      if (v6 && !*(v4 + 216))
      {
        if (NameUIPos == 1)
          goto LABEL_11;
      }
      else if (NameUIPos == 1)
      {
LABEL_11:
        FramePos = 1;
        v10 = v3;
        if (v9 > 0x10)
          goto LABEL_23;
LABEL_31:
        if (v10 != 1)
        {
          if (v10 != 16)
            goto LABEL_143;
          v15 = *(v4 + 294);
          if ((v15 & 0x200) != 0)
          {
            v16 = v15 & 0x200;
            v13 = *(v4 + 184);
            if (CharNo)
            {
LABEL_35:
              v17 = NameUIPos;
              if (!v17)
                goto LABEL_202;
              if ((*(v4 + 295) & 2) != 0 && !*(v4 + 216))
              {
                v17 = NameUIPos;
              }
              if (v17 == 1)
              {
LABEL_202:
                v18 = TextZyage(v4);
                if (v18)
                {
LABEL_77:
                  if ((*(v4 + 295) & 2) == 0)
                    goto LABEL_99;
LABEL_78:
LABEL_99:
                  *(*(v4 + 184) + 36LL) = 3;
                    goto LABEL_144;
                  goto LABEL_100;
                }
              }
              v13 = *(v4 + 184);
              if (NameUIPos != 3)
                goto LABEL_155;
              v19 = *(v4 + 294);
              if ((v19 & 0x200) != 0)
              {
LABEL_150:
                v20 = v19 & 0x200;
                if (FramePos)
                  goto LABEL_153;
                goto LABEL_53;
              }
LABEL_52:
              v20 = 0;
              if (FramePos)
                goto LABEL_153;
              goto LABEL_53;
            }
          }
          else
          {
            v16 = 0;
            v13 = *(v4 + 184);
            if (CharNo)
              goto LABEL_35;
          }
          v30 = NameUIPos;
          if (!v30)
            goto LABEL_203;
          if ((*(v4 + 295) & 2) != 0 && !*(v4 + 216))
          {
            v30 = NameUIPos;
          }
          if (v30 == 1)
          {
LABEL_203:
            v31 = TextZyage(v4);
            if (v31)
            {
                goto LABEL_99;
              goto LABEL_78;
            }
              goto LABEL_160;
            goto LABEL_158;
          }
          v34 = *(v4 + 294);
          if ((v34 & 0x200) != 0)
          {
            if (!*(v4 + 216))
            {
              v30 = NameUIPos;
            }
            v12 = v34 & 0x200;
            if (v30 == 2)
              goto LABEL_184;
          }
          else
          {
            v12 = 0;
            if (v30 == 2)
              goto LABEL_184;
          }
LABEL_161:
          NameUIPos = 2;
            goto LABEL_144;
          goto LABEL_100;
        }
        v21 = *(v4 + 294);
        if ((v21 & 0x200) != 0)
        {
          v22 = v21 & 0x200;
          v23 = *(v4 + 184);
          if (NameUIPos != 3)
          {
LABEL_57:
            KeyBoardUseflag = 1;
            if ((*(v4 + 295) & 2) != 0)
            {
LABEL_61:
            }
LABEL_109:
            *(*(v4 + 184) + 392LL) = " la";
            *(*(v4 + 184) + 32LL) = 1;
              goto LABEL_144;
            goto LABEL_100;
          }
        }
        else
        {
          v22 = 0;
          v23 = *(v4 + 184);
          if (NameUIPos != 3)
            goto LABEL_57;
        }
        NameYseNoflag = 1;
        if ((*(v4 + 295) & 2) != 0)
          goto LABEL_61;
        goto LABEL_109;
      }
      v10 = v3;
      if (v9 > 0x10)
        goto LABEL_23;
      goto LABEL_31;
    }
  }
  else
  {
    v6 = 0;
    v9 = v3;
    if (NameUIPos)
      goto LABEL_8;
  }
  FramePos = 0;
  v10 = v3;
  if (v9 <= 0x10)
    goto LABEL_31;
LABEL_23:
  if (v10 == 32)
  {
    v24 = *(v4 + 294);
    if ((v24 & 0x200) != 0)
    {
      v25 = v24 & 0x200;
      v13 = *(v4 + 184);
      if (CharNo)
      {
LABEL_65:
        v26 = NameUIPos;
        if (!v26)
          goto LABEL_204;
        if ((*(v4 + 295) & 2) != 0 && !*(v4 + 216))
        {
          v26 = NameUIPos;
        }
        if (v26 == 1)
        {
LABEL_204:
          v27 = TextZyage(v4);
          if (v27)
            goto LABEL_77;
        }
        v13 = *(v4 + 184);
        if (NameUIPos != 3)
          goto LABEL_155;
        v19 = *(v4 + 294);
        if ((v19 & 0x200) != 0)
          goto LABEL_150;
        goto LABEL_52;
      }
    }
    else
    {
      v25 = 0;
      v13 = *(v4 + 184);
      if (CharNo)
        goto LABEL_65;
    }
    v33 = NameUIPos;
    if (!v33)
      goto LABEL_130;
    if ((*(v4 + 295) & 2) != 0 && !*(v4 + 216))
    {
      v33 = NameUIPos;
    }
    if (v33 == 1)
    {
LABEL_130:
      if ((*(v4 + 295) & 2) == 0)
      {
LABEL_160:
        v13 = *(v4 + 184);
        goto LABEL_161;
      }
LABEL_158:
      goto LABEL_160;
    }
    v35 = *(v4 + 294);
    if ((v35 & 0x200) != 0)
    {
      if (!*(v4 + 216))
      {
        v33 = NameUIPos;
      }
      v12 = v35 & 0x200;
      if (v33 == 2)
      {
LABEL_178:
        v36 = TextZyage(v4);
        if (v36)
        {
            goto LABEL_99;
          goto LABEL_78;
        }
        v13 = *(v4 + 184);
        if (FramePos)
        {
LABEL_153:
          if (!v20)
            goto LABEL_191;
          goto LABEL_189;
        }
LABEL_53:
        if (v20)
          goto LABEL_140;
        goto LABEL_142;
      }
    }
    else
    {
      v12 = 0;
      if (v33 == 2)
        goto LABEL_178;
    }
LABEL_184:
    if (!FramePos)
    {
      if (v12)
      {
LABEL_140:
      }
LABEL_142:
      NameUIPos = 0;
LABEL_143:
        goto LABEL_144;
      goto LABEL_100;
    }
    goto LABEL_188;
  }
  if (v10 == 64)
  {
    v28 = *(v4 + 294);
    if ((v28 & 0x200) != 0)
    {
      v12 = v28 & 0x200;
      v13 = *(v4 + 184);
      v29 = NameUIPos;
      if (!v29)
        goto LABEL_188;
    }
    else
    {
      v12 = 0;
      v13 = *(v4 + 184);
      v29 = NameUIPos;
      if (!v29)
        goto LABEL_188;
    }
    if (v12 && !*(v4 + 216))
    {
      v29 = NameUIPos;
    }
    if (v29 == 1)
      goto LABEL_139;
LABEL_155:
    v3 = 0;
      goto LABEL_144;
    goto LABEL_100;
  }
  if (v10 != 128)
    goto LABEL_143;
  v11 = *(v4 + 294);
  if ((v11 & 0x200) == 0)
  {
    v12 = 0;
    v13 = *(v4 + 184);
    v14 = NameUIPos;
    if (!v14)
      goto LABEL_188;
LABEL_114:
    if (v12 && !*(v4 + 216))
    {
      v14 = NameUIPos;
    }
    if (v14 != 1)
      goto LABEL_155;
LABEL_139:
    if ((*(v4 + 295) & 2) != 0)
      goto LABEL_140;
    goto LABEL_142;
  }
  v12 = v11 & 0x200;
  v13 = *(v4 + 184);
  v14 = NameUIPos;
  if (v14)
    goto LABEL_114;
LABEL_188:
  if (!v12)
    goto LABEL_191;
LABEL_189:
LABEL_191:
  NameUIPos = 1;
    goto LABEL_144;
LABEL_100:
LABEL_144:
  cmpPlaySE2(v3, 1);
}

// 0x1882180
void MojiColorChange(void) {
  u64 v2;
  u64 v3;
  s64 v4;
  System_String_o *v6;
  struct System_SByte_array *InputNums;
  u64 v8;
  struct System_SByte_array *v11;
  struct UnityEngine_GameObject_array *v13;
  struct System_SByte_array *v15;
  struct TMPro_TextMeshProUGUI_array *v17;
  System_String_o *MojiSizeStr;
  u64 *v20;
  u64 *v21;
  System_String_o *v22;
  struct System_String_o *v23;
  u32 *NameSet;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v28;
  s64 *gameObject;
  s64 *v30;
  struct UnityEngine_GameObject_array *v33;
  u32 *NameSetTM;
  s64 *Component_object;
  s64 *v38;
  struct TMPro_TextMeshProUGUI_array *v41;
  struct System_String_array *NameSave;
  Il2CppArrayBounds *bounds;
  TMPro_TMP_Text_o *v45;
  il2cpp_array_size_t length;
  System_String_o *v49;
  System_Object_array *v50;
  struct TMPro_TextMeshProUGUI_array *v51;
  struct System_String_array *v53;
  Il2CppArrayBounds *v54;
  il2cpp_array_size_t v56;
  s64 *v58;
  s64 *v60;
  s32 v65;
  s32 v66;

  v2 = 0;
  do
  {
    v3 = v2++;
    v4 = 4;
      goto LABEL_9;
LABEL_7:
    while (1)
    {
LABEL_9:
      InputNums = GBWK->InputNums;
      v8 = v4 - 4;
      if (v8 >= InputNums->m_Items[v3])
        break;
      v11 = GBWK->InputNums;
      v13 = NewSpecific(UnityEngine_GameObject, v11->m_Items[v3]);
      NameSet = v13;
      v15 = GBWK->InputNums;
      v17 = NewSpecific(TMPro_TextMeshProUGUI, v15->m_Items[v3]);
      NameSetTM = v17;
      v66 = v2;
      v20 = sub_8D3950(s32, &v66);
      v65 = v4 - 3;
      v21 = sub_8D3950(s32, &v65);
      v22 = Format_5268592("Form{0:0}/Text/TextTM{1:00}", v20, v21);
      v23 = Concat_5221536("AnotherCountry/Anm/", MojiSizeStr, v22);
      StrAssist = v23;
      transform = get_transform(NameUIObj, 0);
      v28 = Find(transform, StrAssist, 0);
      gameObject = get_gameObject(v28);
      v30 = gameObject;
      *&NameSet[2 * v4] = v30;
      v33 = NameSet;
      Component_object = GetComponent_object_(
                           *(&v33->obj.klass + v4));
      v38 = Component_object;
      *&NameSetTM[2 * v4] = v38;
      if (ChangeColor)
      {
        else
        {
          v41 = NameSetTM;
          if (v8 >= LODWORD(v41->max_length))
            goto LABEL_33;
        }
        bounds = NameSave->bounds;
        v45 = *(&v41->obj.klass + v4);
        length = bounds[1].length;
        v49 = *(&NameSave->obj.klass + v4 + v3 * length);
        v50 = NewSpecific(object, 1u);
        v66 = 12;
      }
      else
      {
        else
        {
          v51 = NameSetTM;
          if (v8 >= LODWORD(v51->max_length))
            goto LABEL_42;
        }
        v53 = NameSave;
        v54 = v53->bounds;
        v45 = *(&v51->obj.klass + v4);
        v56 = v54[1].length;
        v49 = *(&v53->obj.klass + v4 + v3 * v56);
        v50 = NewSpecific(object, 1u);
        v66 = 0;
      }
      v58 = sub_8D3950(s32, &v66);
      v60 = v58;
      v50->m_Items[0] = v60;
      v6 = RepColTag(v49, v50);
      set_text(v45, v6);
      ++v4;
        goto LABEL_7;
    }
  }
  while (v2 != 3);
}

// 0x18832d0
void MojiInput(void) {
  bool IsCancel;
  struct Nme_KeyBoard_StaticFields **p_static_fields;
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
      if (NameUIPos == 3)
        goto LABEL_10;
    }
    InputText = get_InputText(keyboardObj_a);
    nmeChack(InputText, 0);
    v13 = get_InputText(keyboardObj_a);
    MojiSave(v13);
    if (FrameMove)
    {
LABEL_71:
      if (**(v16 + 184))
      {
        v23 = TextZyage(v16);
        if (v23)
        {
          v24 = *(v16 + 184);
          if (NameUIPos == 2)
          {
            NameUIPos = 3;
          }
        }
      }
      p_static_fields = (v16 + 184);
      goto LABEL_91;
    }
    v17 = TextZyage(v16);
    if (!v17)
    {
      if ((v18 & 0x200) != 0)
      {
        v19 = v18 & 0x200;
        v20 = *(v16 + 184);
        if (!CharNo)
        {
LABEL_29:
          if (NameUIPos)
          {
            if (NameUIPos == 1)
            {
              NameUIPos = 2;
              if ((*(v16 + 295) & 2) == 0)
                goto LABEL_70;
              goto LABEL_68;
            }
            if (NameUIPos != 2)
              goto LABEL_67;
            goto LABEL_63;
          }
LABEL_54:
          NameUIPos = 1;
          if ((*(v16 + 295) & 2) == 0)
            goto LABEL_70;
          goto LABEL_68;
        }
      }
      else
      {
        v19 = 0;
        if (!CharNo)
          goto LABEL_29;
      }
      v22 = NameUIPos;
      if (!v22)
        goto LABEL_54;
      if (v19 && !*(v16 + 216))
      {
        v22 = NameUIPos;
      }
      if (v22 == 1)
      {
LABEL_63:
        NameUIPos = 0;
      }
    }
LABEL_67:
    if ((*(v16 + 295) & 2) == 0)
    {
LABEL_70:
      *(*(v16 + 184) + 323LL) = 1;
      goto LABEL_71;
    }
LABEL_68:
    goto LABEL_70;
  }
LABEL_10:
  if (get_IsCancel(keyboardObj_a))
  {
    NameKeyBoardflag = 0;
    (*p_static_fields)->KeyBoardUseflag = 0;
LABEL_91:
    (*p_static_fields)->TransitionNo = 4;
  }
}

// 0x187fc00
void MojiSave(char *name) {
  System_Byte_array *v4;
  struct System_SByte_array *InputNums;
  s64 MojiType;
  struct System_SByte_array *v12;
  s64 v13;
  u64 i;
  struct System_Byte_array *InputCode;
  s64 v24;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;
  il2cpp_array_size_t v27;
  struct System_Byte_array *v29;
  s64 v30;
  Il2CppArrayBounds *v31;
  il2cpp_array_size_t v32;
  il2cpp_array_size_t v33;
  u64 v35;
  u64 v37;
  u64 v38;
  s64 v46;
  struct System_Byte_array *v47;
  Il2CppArrayBounds *v49;
  il2cpp_array_size_t v50;
  il2cpp_array_size_t v51;
  struct System_Byte_array *v53;
  s64 v54;
  Il2CppArrayBounds *v56;
  il2cpp_array_size_t v57;
  il2cpp_array_size_t v58;
  struct System_SByte_array *v61;
  s64 v62;

  v4 = UnicodeToIndexByte2(txtMgr, name);
  InputNums = GBWK->InputNums;
  if (InputNums->m_Items[MojiType])
  {
    v12 = GBWK->InputNums;
    v13 = MojiType;
    v12->m_Items[v13] = 0;
  }
  for (i = 0; i != 8; ++i)
  {
    InputCode = GBWK->InputCode;
    v24 = MojiType;
    bounds = InputCode->bounds;
    length = bounds[1].length;
    v27 = bounds[2].length;
    InputCode->m_Items[v27 * (i + length * v24)] = 0;
    v29 = GBWK->InputCode;
    v30 = MojiType;
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
      v46 = MojiType;
      v47 = GBWK->InputCode;
      v49 = v47->bounds;
      v50 = v49[1].length;
      v51 = v49[2].length;
      v47->m_Items[v51 * (v38 + v50 * v46)] = v4->m_Items[v37];
      v53 = GBWK->InputCode;
      v54 = MojiType;
      v56 = v53->bounds;
      v57 = v56[1].length;
      v58 = v56[2].length;
      v53->m_Items[v58 * (v38 + v57 * v54) + 1] = v4->m_Items[v37 + 1];
      v61 = GBWK->InputNums;
      v62 = MojiType;
      ++v38;
      ++v61->m_Items[v62];
      v37 += 2LL;
    }
    while (v38 < get_Length(name));
  }
}

// 0x1885020
void NameUIPosMoveCorect(void) {
  bool v4;
  s32 NameUIPos;
  s32 v9;
  s32 v11;

  v4 = TextZyage();
  if (v4)
  {
    else
    {
      if (CharNo)
      {
LABEL_10:
        else
        {
          if (NameUIPos >= 4)
          {
LABEL_13:
LABEL_69:
            NameUIPos = 0;
            return;
          }
        }
LABEL_52:
        if (NameUIPos < 0)
        {
          v11 = 3;
LABEL_80:
          NameUIPos = v11;
          return;
        }
        return;
      }
    }
    else
    {
      if (NameUIPos < 4)
        goto LABEL_52;
    }
    NameUIPos = 0;
    return;
  }
  if (!CharNo)
    goto LABEL_34;
LABEL_19:
  else
  {
    v9 = NameUIPos;
    if (v9 == 2)
    {
LABEL_22:
      goto LABEL_69;
    }
  }
  else if (v9 >= 2)
  {
    goto LABEL_47;
  }
  if (v9 < 0)
  {
    v11 = 1;
    goto LABEL_80;
  }
}

// 0x18818e0
bool TextZyage(void) {
  u64 v3;
  u64 v4;
  struct System_SByte_array *InputNums;
  s32 v11;
  struct System_Byte_array *InputCode;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;
  il2cpp_array_size_t v16;
  struct System_Byte_array *v18;
  Il2CppArrayBounds *v19;
  il2cpp_array_size_t v20;
  il2cpp_array_size_t v21;
  struct System_Byte_array *v23;
  Il2CppArrayBounds *v24;
  il2cpp_array_size_t v25;
  il2cpp_array_size_t v26;
  struct System_Byte_array *v28;
  Il2CppArrayBounds *v29;
  il2cpp_array_size_t v30;
  il2cpp_array_size_t v31;
  struct System_Byte_array *v37;
  Il2CppArrayBounds *v38;
  il2cpp_array_size_t v39;
  il2cpp_array_size_t v40;
  struct System_Byte_array *v42;
  Il2CppArrayBounds *v43;
  il2cpp_array_size_t v44;
  il2cpp_array_size_t v45;
  struct System_Byte_array *v53;
  Il2CppArrayBounds *v54;
  il2cpp_array_size_t v55;
  il2cpp_array_size_t v56;
  struct System_Byte_array *v58;
  Il2CppArrayBounds *v59;
  il2cpp_array_size_t v60;
  il2cpp_array_size_t v61;

  v3 = 0;
  v4 = 0;
  NameEndflag = 0;
  {
LABEL_7:
    goto LABEL_11;
  }
  while (1)
  {
    while (1)
    {
LABEL_11:
      InputNums = GBWK->InputNums;
      if (v4 >= InputNums->m_Items[v3])
        break;
      {
        else
        {
          if (CharNo)
          {
LABEL_16:
            InputCode = GBWK->InputCode;
            bounds = InputCode->bounds;
            length = bounds[1].length;
            v16 = bounds[2].length;
            if (!InputCode->m_Items[v16 * (v4 + v3 * length)])
            {
              v18 = GBWK->InputCode;
              v19 = v18->bounds;
              v20 = v19[1].length;
              v21 = v19[2].length;
              if (v18->m_Items[v21 * (v4 + v3 * v20) + 1] == 48)
                goto LABEL_10;
            }
            v37 = GBWK->InputCode;
            v38 = v37->bounds;
            v39 = v38[1].length;
            v40 = v38[2].length;
            if (v37->m_Items[v40 * (v4 + v3 * v39)] == 32)
            {
              v42 = GBWK->InputCode;
              v43 = v42->bounds;
              v44 = v43[1].length;
              v45 = v43[2].length;
              if (!v42->m_Items[v45 * (v4 + v3 * v44) + 1])
                goto LABEL_10;
            }
            if (v3 != 1)
            {
LABEL_99:
              if (!v3)
              {
                NameEndflag = 2;
              }
              goto LABEL_10;
            }
            else
            {
              if (NameEndflag == 2)
                goto LABEL_71;
            }
            goto LABEL_10;
          }
        }
      }
      else
      {
        v11 = 0;
        if (CharNo)
          goto LABEL_16;
      }
      v23 = GBWK->InputCode;
      v24 = v23->bounds;
      v25 = v24[1].length;
      v26 = v24[2].length;
      if (!v23->m_Items[v26 * (v4 + v3 * v25)])
      {
        v28 = GBWK->InputCode;
        v29 = v28->bounds;
        v30 = v29[1].length;
        v31 = v29[2].length;
        if (v28->m_Items[v31 * (v4 + v3 * v30) + 1] == 48)
          goto LABEL_10;
      }
      v53 = GBWK->InputCode;
      v54 = v53->bounds;
      v55 = v54[1].length;
      v56 = v54[2].length;
      if (v53->m_Items[v56 * (v4 + v3 * v55)] == 32)
      {
        v58 = GBWK->InputCode;
        v59 = v58->bounds;
        v60 = v59[1].length;
        v61 = v59[2].length;
        if (!v58->m_Items[v61 * (v4 + v3 * v60) + 1])
          goto LABEL_10;
      }
      if (v3 == 2)
      {
        if (NameEndflag != 3)
          goto LABEL_10;
LABEL_71:
        NameEndflag = 1;
        goto LABEL_10;
      }
      if (v3 != 1)
        goto LABEL_99;
      else
      {
        if (NameEndflag == 2)
          goto LABEL_125;
      }
LABEL_10:
      ++v4;
        goto LABEL_7;
    }
    if (++v3 == 3)
      break;
    v4 = 0;
      goto LABEL_7;
  }
  return NameEndflag == 1;
}

// 0x187f6d0
void nmeChack(char *name, bool judg) {
  u64 *v5;
  struct Nme_KeyBoard_StaticFields *static_fields;
  struct System_String_array *tblDefName;
  s32 v9;
  System_String_o *v11;
  u64 v12;
  Nme_KeyBoard_c *v13;
  s16 v14;
  s32 v15;
  struct Nme_KeyBoard_StaticFields *i;
  struct TMPro_TextMeshProUGUI_array *NameSetTM;
  struct System_String_array *NameSave2;
  s64 MojiType;
  u64 v22;
  u16 Chars;
  struct TMPro_TextMeshProUGUI_array *v27;
  TMPro_TMP_Text_o *v29;
  System_String_o *String_5280336;
  struct TMPro_TextMeshProUGUI_array *v31;
  TMPro_TMP_Text_o *v33;
  System_String_o *text;
  System_Object_array *v35;
  s64 *v36;
  s64 *v38;
  System_String_o *v41;
  struct System_String_array *NameSave;
  s64 v44;
  System_String_o *v45;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;
  u64 v50;
  s32 v52;

  v5 = NewSpecific(char, 1u);
  ChackLang = 1;
  if (ChackLang != UseLang)
  {
    v9 = MojiType + 3 * CharNo;
    v11 = tblDefName->m_Items[v9];
    name = GetLocalizeText(v11);
  }
  v12 = 0;
  if ((v14 & 0x200) != 0)
    goto LABEL_24;
LABEL_19:
  v15 = 0;
  for (i = v13->static_fields; v12 < i->MojiNum; i = v13->static_fields)
  {
    else
    {
      NameSetTM = i->NameSetTM;
      if (v12 >= LODWORD(NameSetTM->max_length))
        goto LABEL_23;
    }
    set_text(NameSetTM->m_Items[v12++], "");
    if ((v14 & 0x200) == 0)
      goto LABEL_19;
LABEL_24:
    v15 = v14 & 0x200;
  }
  NameSave2 = i->NameSave2;
  MojiType = i->MojiType;
  NameSave2->m_Items[MojiType] = name;
  if (get_Length(name) >= 1)
  {
    v22 = 0;
    do
    {
      Chars = get_Chars(name, v22);
      *(v5 + 16) = Chars;
      v27 = NameSetTM;
      v29 = v27->m_Items[v22];
      String_5280336 = CreateString_5280336(0, v5);
      set_text(v29, String_5280336);
      v31 = NameSetTM;
      v33 = v31->m_Items[v22];
      text = get_text(NameSetTM->m_Items[v22]);
      v35 = NewSpecific(object, 1u);
      v52 = 0;
      v36 = sub_8D3950(s32, &v52);
      v38 = v36;
      v35->m_Items[0] = v38;
      v41 = RepColTag(text, v35);
      set_text(v33, v41);
      v44 = MojiType;
      v45 = CreateString_5280336(0, v5);
      bounds = NameSave->bounds;
      length = bounds[1].length;
      v50 = v22 + length * v44;
      ++v22;
      NameSave->m_Items[v50] = v45;
    }
    while (v22 < get_Length(name));
  }
}

// 0x1886010
s8 nmeChkKeyBoardProcess(void) {
  return gProcessStat == 1;
}

// 0x1886760
dds3ProcessFunc_t *nmeKeyBoardCalc(dds3ProcessID_t *PID) {
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  s32 v10;
  struct cmpSeqInfo_t_o *SeqInfo;
  dds3ProcessID_t_o *v15[3];
  dds3ProcessID_t_o *id;

  id = PID;
  ProcessData = dds3GetProcessData(&id);
  else
  {
    if (!ProcessData)
      goto LABEL_15;
  }
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nmeData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nmeData_t, v15);
    if ((v15[0] & 1) != 0)
      v7 = v15[2];
    else
      v7 = v15 + 1;
    v8 = sub_8C4940(v7);
  }
LABEL_15:
  GBWK = ProcessData;
  v10 = dds3FadeCheck();
  else if (ToBoolean_2953872(v10))
  {
    return 0;
  }
  SeqInfo = GBWK->SeqInfo;
  if ((SeqInfo->Flag & 0x10) != 0)
  {
    cmpUpdateTerminate(SeqInfo);
    id->func_ans = -1;
  }
  return 0;
}

// 0x18847e0
dds3ProcessFunc_t *nmeKeyBoardDestroy(dds3ProcessID_t *PID) {
  struct nmeData_t_o *GBWK;
  s8 TargetNo;
  struct System_String_array *NameSave2;
  struct System_String_array *v12;
  struct System_String_array *v14;
  UnityEngine_Object_o *CanvasMenu;
  UnityEngine_Object_o *CameraObj;

  if (GBWK)
  {
    TargetNo = GBWK->TargetNo;
    nmeSetFontImageToGW(TargetNo, &GBWK);
    frDelFontStyle(4u);
    GBWK = 0;
    gProcessStat = 2;
    dds3KernelDebugSign = 0;
    dds3FadeClear();
  }
  if (!LODWORD(NameSave2->max_length))
    goto LABEL_30;
LABEL_26:
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
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  struct cmpSeqInfo_t_o *SeqInfo;
  Nme_KeyBoard_c *v12;
  s16 v14;
  s32 v15;
  UnityEngine_Animator_o *NickSetAnim;
  System_String_o *v19;
  bool v20;
  u64 v26;
  UnityEngine_Animator_o *EndSetAnim;
  System_String_o *v33;
  bool v34;
  dds3ProcessID_t_o *v39[3];
  dds3ProcessID_t_o *id;

  id = PID;
  ProcessData = dds3GetProcessData(&id);
  else
  {
    if (!ProcessData)
      goto LABEL_15;
  }
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nmeData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nmeData_t, v39);
    if ((v39[0] & 1) != 0)
      v8 = v39[2];
    else
      v8 = v39 + 1;
    v9 = sub_8C4940(v8);
  }
LABEL_15:
  GBWK = ProcessData;
  SeqInfo = GBWK->SeqInfo;
  if ((SeqInfo->Flag & 0x20) != 0)
  {
    cmpUpdateTerminate(SeqInfo);
    id->func_ans = -1;
    return 0;
  }
  if (!dds3FadeCheck())
    return 0;
  if (GBWK->CfmFlag == 2)
    return 0;
  v14 = *&v12->_2.bitflags1;
  if ((v14 & 0x200) != 0)
  {
    v15 = v14 & 0x200;
    if (CharNo)
    {
LABEL_26:
      if (GetBool(NickSetAnim, "nickname"))
      {
        v19 = "nickname";
        v20 = 0;
LABEL_55:
        SetBool(NickSetAnim, v19, v20);
        goto LABEL_56;
      }
      goto LABEL_56;
    }
  }
  else
  {
    v15 = 0;
    if (CharNo)
      goto LABEL_26;
  }
  if (!GetBool(NickSetAnim, "nickname"))
  {
    v19 = "nickname";
    v20 = 1;
    goto LABEL_55;
  }
LABEL_56:
  if (GetInteger(SelFrameAnim, "select") != 1)
  {
    SetInteger(SelFrameAnim, "select", 1);
  }
  if (*(*(v26 + 184) + 20LL) != 2)
  {
    if (TextZyage(v26))
    {
      ButtonGuideDispSet("NAME03", 0, 0, 90);
      if (!GetBool(EndSetAnim, "fix"))
      {
        v33 = "fix";
        v34 = 1;
LABEL_94:
        SetBool(EndSetAnim, v33, v34);
      }
    }
    else
    {
      ButtonGuideDispSet("NAME02", 0, 0, 90);
      if (GetBool(EndSetAnim, "fix"))
      {
        v33 = "fix";
        v34 = 0;
        goto LABEL_94;
      }
    }
  }
  return 0;
}

// 0x187e170
void nmeKeyBoardInit(void) {
  u64 *v1;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v5;
  cmpSeqInfo_t_o *v9;
  UnityEngine_Transform_o *v14;
  UnityEngine_Component_o *v15;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  s32 CharNo;
  System_String_o *v21;
  UnityEngine_Animator_o *v22;
  s32 v23;
  bool v24;
  s32 Integer;
  UnityEngine_Object_o *name_backloopAnime;
  UnityEngine_Transform_o *v30;
  UnityEngine_Component_o *v31;
  struct UnityEngine_GameObject_o *v32;
  Il2CppObject *v34;
  s32 v39;
  Nme_KeyBoard_c *v40;
  s32 v43;
  UnityEngine_Transform_o *v50;
  UnityEngine_Component_o *v51;
  struct UnityEngine_GameObject_o *v52;
  Il2CppObject *v54;
  UnityEngine_Transform_o *v56;
  UnityEngine_Component_o *v57;
  struct UnityEngine_GameObject_o *v58;
  UnityEngine_Transform_o *v63;
  UnityEngine_Component_o *v64;
  struct UnityEngine_GameObject_o *v65;
  UnityEngine_Transform_o *v67;
  UnityEngine_Component_o *v68;
  struct UnityEngine_GameObject_o *v69;
  Il2CppObject *v71;
  struct System_String_array *NameDecRcl;
  TMPro_TMP_Text_o *NameDescriptionTM;
  System_String_o *v78;
  System_String_o *LocalizeText;
  System_Object_array *v80;
  s64 *v81;
  s64 *v83;
  System_String_o *v85;
  UnityEngine_Transform_o *v86;
  UnityEngine_Component_o *v87;
  struct UnityEngine_GameObject_o *v88;
  UnityEngine_Transform_o *v90;
  UnityEngine_Component_o *v91;
  struct UnityEngine_GameObject_o *v92;
  Il2CppObject *v95;
  s64 *v101;
  s64 *v102;
  UnityEngine_Transform_o *v105;
  UnityEngine_Component_o *v106;
  struct UnityEngine_GameObject_o *v108;
  Il2CppObject *v110;
  Il2CppObject *v112;
  Il2CppObject *v114;
  s32 v119;
  UnityEngine_Animator_o *NickSetAnim;
  System_String_o *v124;
  bool v125;
  u64 v127;
  u64 v129;
  System_String_o *MojiSizeStr;
  u64 *v131;
  System_String_o *v132;
  struct System_String_o *v133;
  UnityEngine_Transform_o *v135;
  UnityEngine_Component_o *v136;
  struct UnityEngine_GameObject_o *v137;
  Il2CppObject *v139;
  struct System_String_array *NameDesRcl;
  TMPro_TMP_Text_o *NameDesTM;
  System_String_o *v146;
  System_String_o *v147;
  System_Object_array *v148;
  s64 *v149;
  s64 *v151;
  System_String_o *v154;
  u64 *v155;
  UnityEngine_Transform_o *v158;
  Il2CppObject *v159;
  Nme_KeyBoard_c *v162;
  struct UnityEngine_GameObject_array *v165;
  struct TMPro_TextMeshProUGUI_array *v168;
  Nme_KeyBoard_c *v169;
  s32 v170;
  bool v171;
  s32 v172;
  s64 v173;
  s16 v174;
  s64 v175;
  s32 v178;
  System_String_o *v180;
  u64 *v181;
  s64 v182;
  u64 *v183;
  System_String_o *v184;
  struct System_String_o *v185;
  u32 *NameSet;
  UnityEngine_Transform_o *v189;
  UnityEngine_Component_o *v190;
  s64 *v191;
  s64 *v192;
  u64 v193;
  struct UnityEngine_GameObject_array *v196;
  u32 *NameSetTM;
  s64 *v199;
  s64 *v200;
  struct System_String_array *tblDefName;
  u32 v203;
  System_String_o *v205;
  System_String_o *v206;
  struct System_String_array *v209;
  u32 v210;
  System_String_o *v212;
  UnityEngine_Vector3_o v214;
  s32 v215;

  v1 = Allocate(nmeData_t);
  nmeData_t___ctor(v1);
LABEL_7:
  NameUIObj = oName_UI;
  transform = get_transform(NameUIObj, 0);
  v5 = Find(transform, "AnotherCountry", 0);
  NameKeyBoardUI = get_gameObject(v5);
  ButtonGuideDispSet("NAME02", 0, 0, 90);
  *(v1[2] + 17) = 0;
  *(v1[2] + 19) = 0;
  *(v1[2] + 20) = 1;
  *(v1 + 16) = CharNo;
  gProcessStat = 1;
  v9 = v1[2];
  cmpInitSeqInfo(v9, 0);
  GBWK = v1;
  if (!get_activeSelf(NameKeyBoardUI))
  {
    SetActive(NameKeyBoardUI, 1, 0);
  }
  v14 = get_transform(NameUIObj, 0);
  v15 = Find(v14, "namechara", 0);
  gameObject = get_gameObject(v15);
  Component_object = GetComponent_object_(gameObject);
  if (CharNo)
  {
    else if (CharNo == 1)
    {
      goto LABEL_28;
    }
    else if (CharNo == 2)
    {
      goto LABEL_41;
    }
    if (CharNo == 3 && GetInteger(Component_object, "namechara") != 3)
    {
      v21 = "namechara";
      v22 = Component_object;
      v23 = 3;
      goto LABEL_50;
    }
    goto LABEL_51;
  }
  v24 = evtBitCheck(2224);
  Integer = GetInteger(Component_object, "namechara");
  if (v24)
  {
    if (Integer != 4)
    {
      v21 = "namechara";
      v22 = Component_object;
      v23 = 4;
      goto LABEL_50;
    }
  }
  else if (Integer)
  {
    v21 = "namechara";
    v22 = Component_object;
    v23 = 0;
    goto LABEL_50;
  }
LABEL_51:
  if (op_Equality(name_backloopAnime, 0, 0))
  {
    v30 = get_transform(NameUIObj, 0);
    v31 = Find(v30, "name_bg", 0);
    v32 = get_gameObject(v31);
    name_backloop = v32;
    v34 = GetComponent_object_(name_backloop);
    name_backloopAnime = v34;
    Play_8766576(name_backloopAnime, "name_bg");
  }
  switch (GetLanguage(0))
  {
    case 0:
      v39 = 1;
      goto LABEL_103;
    case 1:
      v43 = 8;
      goto LABEL_92;
    case 2:
      v43 = 16;
      goto LABEL_92;
    case 3:
      v43 = 32;
      goto LABEL_92;
    case 4:
      v43 = 64;
      goto LABEL_92;
    case 5:
      v43 = 128;
LABEL_92:
      UseLang = v43;
      MojiSize = 1;
      if ((v40->_2.bitflags2 & 2) != 0)
        goto LABEL_93;
      goto LABEL_104;
    case 6:
      v39 = 4;
      goto LABEL_103;
    case 7:
      v39 = 2;
LABEL_103:
      UseLang = v39;
      MojiSize = 0;
      if ((v40->_2.bitflags2 & 2) == 0)
        goto LABEL_104;
      goto LABEL_93;
    default:
        goto LABEL_104;
LABEL_93:
LABEL_104:
      v50 = get_transform(NameUIObj, 0);
      v51 = Find(v50, "KeyBoard", 0);
      v52 = get_gameObject(v51);
      keyboardObj = v52;
      v54 = AddComponent_object_(keyboardObj);
      keyboardObj_a = v54;
      v56 = get_transform(NameUIObj, 0);
      v57 = Find(v56, "namemode", 0);
      v58 = get_gameObject(v57);
      NameMode = v58;
      if (get_activeSelf(NameMode))
      {
        SetActive(NameMode, 0, 0);
      }
      v63 = get_transform(NameUIObj, 0);
      v64 = Find(v63, "Filter", 0);
      v65 = get_gameObject(v64);
      Filter = v65;
      v67 = get_transform(NameUIObj, 0);
      v68 = Find(v67, "AnotherCountry/Announce/TextTM", 0);
      v69 = get_gameObject(v68);
      NameDescription = v69;
      v71 = GetComponent_object_(NameDescription);
      NameDescriptionTM = v71;
      v78 = NameDecRcl->m_Items[0];
      LocalizeText = GetLocalizeText(v78);
      LODWORD(v214.x) = 22;
      v80 = NewSpecific(object, 1u);
      v81 = sub_8D3950(s32, &v214);
      v83 = v81;
      v80->m_Items[0] = v83;
      v85 = RepColTag(LocalizeText, v80);
      set_text(NameDescriptionTM, v85);
      v86 = get_transform(NameUIObj, 0);
      v87 = Find(v86, "AnotherCountry/Announce", 0);
      v88 = get_gameObject(v87);
      NameDescriptionFrame = v88;
      v90 = get_transform(NameUIObj, 0);
      v91 = Find(v90, "AnotherCountry/Anm", 0);
      v92 = get_gameObject(v91);
      NameSize = v92;
      v95 = GetComponent_object_(NameSize);
      NameSizeAnim = v95;
      if (MojiSize)
      {
        if (!GetBool(NameSizeAnim, "Half"))
        {
          SetBool(NameSizeAnim, "Half", 1);
        }
        else
        {
          v101 = &"AnotherCountry/Anm/Half";
        }
        v102 = &"Half/";
      }
      else
      {
        if (GetBool(NameSizeAnim, "Half"))
        {
          SetBool(NameSizeAnim, "Half", 0);
        }
        else
        {
          v101 = &"AnotherCountry/Anm/Full";
        }
        v102 = &"Full/";
      }
      MojiSizeStr = *v102;
      v105 = get_transform(NameUIObj, 0);
      v106 = Find(v105, *v101, 0);
      v108 = get_gameObject(v106);
      NameFrame = v108;
      v110 = GetComponent_object_(NameFrame);
      SelFrameAnim = v110;
      v112 = GetComponent_object_(NameFrame);
      NickSetAnim = v112;
      v114 = GetComponent_object_(NameFrame);
      EndSetAnim = v114;
      if (GetInteger(SelFrameAnim, "select") != 1)
      {
        SetInteger(SelFrameAnim, "select", 1);
      }
      {
        else
        {
          if (CharNo)
            goto LABEL_159;
        }
      }
      else
      {
        v119 = 0;
        if (CharNo)
        {
LABEL_159:
          if (GetBool(NickSetAnim, "nickname"))
          {
            v124 = "nickname";
            v125 = 0;
LABEL_177:
            SetBool(NickSetAnim, v124, v125);
            goto LABEL_178;
          }
          goto LABEL_178;
        }
      }
      if (!GetBool(NickSetAnim, "nickname"))
      {
        v124 = "nickname";
        v125 = 1;
        goto LABEL_177;
      }
LABEL_178:
      v127 = 0;
      do
      {
        v129 = v127 + 1;
        LODWORD(v214.x) = v127 + 1;
        v131 = sub_8D3950(s32, &v214);
        v132 = Format("Form{0:0}/TextTM_Title", v131, 0);
        v133 = Concat_5221536("AnotherCountry/Anm/", MojiSizeStr, v132);
        FormStr = v133;
        v135 = get_transform(NameUIObj, 0);
        v136 = Find(v135, FormStr, 0);
        v137 = get_gameObject(v136);
        NameDes = v137;
        v139 = GetComponent_object_(NameDes);
        NameDesTM = v139;
        v146 = NameDesRcl->m_Items[v127];
        v147 = GetLocalizeText(v146);
        v148 = NewSpecific(object, 1u);
        v215 = 11;
        v149 = sub_8D3950(s32, &v215);
        v151 = v149;
        v148->m_Items[0] = v151;
        v154 = RepColTag(v147, v148);
        set_text(NameDesTM, v154);
        v127 = v129;
      }
      while (v129 != 3);
      v155 = Allocate(UnityEngine_GameObject);
      _ctor_27226688(v155);
      CameraObj = v155;
      set_name(CameraObj, "CameraR");
      v158 = get_transform(CameraObj, 0);
      v214.z = 0.0;
      *&v214.x = 0;
      sub_8524C0(&v214.x, -250.0, 1000.0, 0.0);
      set_position(v158, v214);
      AddComponent_object_(CameraObj);
      AddComponent_object_(CameraObj);
      v159 = GetComponent_object_(CameraObj);
      CameraR = v159;
      set_fieldOfView(CameraR, 0.5);
      if (MojiSize)
      {
        else
        {
          MojiNum = 8;
          if ((v162->_2.bitflags2 & 2) == 0)
            goto LABEL_217;
        }
      }
      {
        MojiNum = 4;
        if ((v162->_2.bitflags2 & 2) == 0)
          goto LABEL_217;
      }
      else
      {
        MojiNum = 4;
        if ((v162->_2.bitflags2 & 2) == 0)
          goto LABEL_217;
      }
LABEL_217:
      v165 = NewSpecific(UnityEngine_GameObject, MojiNum);
      NameSet = v165;
      v168 = NewSpecific(TMPro_TextMeshProUGUI, MojiNum);
      NameSetTM = v168;
      if (!CharNo)
        return;
      v170 = 0;
      v171 = (v169->_2.bitflags2 & 2) == 0;
      break;
  }
  do
  {
    v172 = v170;
    MojiType = v172;
    v173 = 4;
    v174 = *&v169->_2.bitflags1;
    v175 = 0;
    if ((v174 & 0x200) == 0)
      goto LABEL_243;
    while (1)
    {
      v178 = v174 & 0x200;
      if (v175 >= MojiNum)
        break;
      while (1)
      {
        v180 = MojiSizeStr;
        LODWORD(v214.x) = MojiType + 1;
        v181 = sub_8D3950(s32, &v214);
        v182 = v175 + 1;
        v215 = v175 + 1;
        v183 = sub_8D3950(s32, &v215);
        v184 = Format_5268592("Form{0:0}/Text/TextTM{1:00}", v181, v183);
        v185 = Concat_5221536("AnotherCountry/Anm/", v180, v184);
        StrAssist = v185;
        v189 = get_transform(NameUIObj, 0);
        v190 = Find(v189, StrAssist, 0);
        v191 = get_gameObject(v190);
        v192 = v191;
        v193 = v182 - 1;
        *&NameSet[2 * v173] = v192;
        v196 = NameSet;
        v199 = GetComponent_object_(
                 *(&v196->obj.klass + v173));
        v200 = v199;
        *&NameSetTM[2 * v173] = v200;
        ++v173;
        v175 = v173 - 4;
        if ((v174 & 0x200) != 0)
          break;
LABEL_243:
        v178 = 0;
        if (v175 >= MojiNum)
          goto LABEL_244;
      }
    }
LABEL_244:
    v203 = 3 * CharNo + v172;
    v205 = tblDefName->m_Items[v203];
    v206 = GetLocalizeText(v205);
    nmeChack(v206, 0);
    v209 = tblDefName;
    v210 = 3 * CharNo + v172;
    v212 = GetLocalizeText(v209->m_Items[v210]);
    MojiSave(v212);
    v170 = 1;
  }
  while (!v172);
  MojiType = 0;
}

// 0x1886080
s32 nmeKeyBoardNameEntry(void) {
  s32 gProcessStat;
  s64 v5;
  s8 IntPara;
  s32 v8;
  s32 v9;

  else
  {
    if (gProcessStat != 2)
    {
LABEL_6:
      if (!gProcessStat)
      {
        IntPara = scrGetIntPara(0);
        nmeKeyBoardProcessStart(IntPara, v5);
      }
      v8 = 0;
      v9 = 1;
      goto LABEL_20;
    }
  }
  v9 = 0;
  v8 = 1;
  gProcessStat = 0;
LABEL_20:
  scrSetIntReturnValue(v9);
  return v8;
}

// 0x18861c0
void nmeKeyBoardProcessStart(s8 TargetNo, s8 DebugMode) {
  AssetBundleCtrl_o *asset_bc;
  Il2CppObject *Prefab_16624656;
  UnityEngine_GameObject_o *v6;
  UnityEngine_Transform_o *transform;
  Il2CppObject *v10;
  u64 *v15;
  Il2CppObject *data;
  u64 *v19;
  u64 *v20;
  u64 *v21;
  bool v23;
  struct System_Byte_array *v25;
  struct System_Byte_array *v27;
  struct System_Byte_array *v29;
  struct System_Byte_array *gFadeCol;
  struct System_Byte_array *v34;
  struct System_Byte_array *v36;
  struct System_Byte_array *v38;
  u32 max_length;
  u32 v40;
  u32 v41;
  u32 v43;

  asset_bc = get_asset_bc();
  Prefab_16624656 = LoadPrefab_16624656(asset_bc, "common", "dds3data/UI", "nameUI");
  v6 = Find("Canvas_UI", 0);
  transform = get_transform(v6, 0);
  v10 = Instantiate_object__425664(Prefab_16624656, transform, 0);
  oName_UI = v10;
  AddComponent_object_(oName_UI);
  if (!ForeignCountriesInit)
  {
    CharNo = TargetNo;
    nmeKeyBoardInit();
    ForeignCountriesInit = 1;
  }
  v15 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v15,
    0,
    Method_Nme_KeyBoard_nmeKeyBoardCalc__);
  data = GBWK;
  dds3StartProcess("name", 0x406u, 1, 1, v15, 0, 0, 0, data, 0);
  v19 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v19,
    0,
    Method_Nme_KeyBoard_nmeKeyBoardDraw__);
  dds3StartProcess(
    "name_draw",
    0x2B16u,
    1,
    1,
    v19,
    0,
    0,
    0,
    GBWK,
    0);
  v20 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v20,
    0,
    Method_Nme_KeyBoard_nmeKeyBoardUpdata__);
  v21 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v21,
    0,
    Method_Nme_KeyBoard_nmeKeyBoardDestroy__);
  dds3StartProcess(
    "name_update",
    0x5212u,
    1,
    1,
    v20,
    0,
    v21,
    0,
    GBWK,
    0);
  v23 = evtBitCheck(18);
  if (!v23)
  {
    else
    {
      if (!LODWORD(gFadeCol->max_length))
        goto LABEL_37;
    }
    gFadeCol->m_Items[0] = -1;
    v34 = gFadeCol;
    v34->m_Items[1] = -1;
    v36 = gFadeCol;
    v36->m_Items[2] = -1;
      goto LABEL_45;
LABEL_43:
    goto LABEL_45;
  }
  else
  {
    v25 = gFadeCol;
    if (!LODWORD(v25->max_length))
      goto LABEL_27;
  }
  v25->m_Items[0] = 0;
  v27 = gFadeCol;
  v27->m_Items[1] = 0;
  v29 = gFadeCol;
  v29->m_Items[2] = 0;
    goto LABEL_43;
LABEL_45:
  v38 = gFadeCol;
  max_length = v38->max_length;
  v40 = v38->m_Items[0];
  v41 = gFadeCol->m_Items[1];
  v43 = gFadeCol->m_Items[2];
  dds3FadeIn(v40, v41, v43, 0x1Eu);
}

// 0x18800c0
dds3ProcessFunc_t *nmeKeyBoardUpdata(dds3ProcessID_t *PID) {
  u16 v3;
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  u64 v12;
  s16 v13;
  s32 v14;
  struct Nme_KeyBoard_StaticFields *v15;
  struct Nme_KeyBoard_StaticFields *v17;
  struct System_String_array *tblHelp;
  s64 MojiType;
  System_String_o *v21;
  struct System_String_o *LocalizeText;
  Nme_KeyBoard_c *v24;
  s32 v26;
  s16 v27;
  s32 v28;
  s16 v29;
  s32 v30;
  struct System_String_array *NameSave2;
  s64 v33;
  struct System_String_array *v36;
  s64 v37;
  struct System_String_array *tblDefName;
  s32 v41;
  System_String_o *v43;
  struct System_String_o *v44;
  struct UnityEngine_GameObject_array *v45;
  struct TMPro_TextMeshProUGUI_array *v47;
  s64 v48;
  s16 v49;
  s64 v50;
  s32 v51;
  struct Nme_KeyBoard_StaticFields *v52;
  System_String_o *MojiSizeStr;
  u64 *v54;
  s64 v55;
  u64 *v56;
  System_String_o *v57;
  struct System_String_o *v58;
  u32 *NameSet;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v63;
  s64 *gameObject;
  s64 *v65;
  u64 v67;
  struct UnityEngine_GameObject_array *v70;
  u32 *NameSetTM;
  s64 *Component_object;
  s64 *v74;
  struct Nme_KeyBoard_StaticFields *v77;
  struct Nme_KeyBoard_StaticFields *v79;
  struct System_String_array *NameDecRcl;
  TMPro_TMP_Text_o *NameDescriptionTM;
  System_String_o *v83;
  struct System_String_array *v85;
  struct System_String_array *v87;
  struct System_String_array *v89;
  System_String_o *v91;
  System_Object_array *v92;
  System_Object_array *v93;
  s64 *v94;
  s64 *v96;
  System_String_o *v99;
  u64 v103;
  struct Nme_KeyBoard_StaticFields **p_static_fields;
  s16 v108;
  s32 v109;
  struct UnityEngine_GameObject_o *v110;
  Il2CppObject *v112;
  UnityEngine_Object_o *BackImageTex;
  bool v118;
  UnityEngine_Object_o *v122;
  UnityEngine_Texture2D_o *v124;
  UnityEngine_Sprite_o *_27456544;
  Il2CppObject *v129;
  UnityEngine_GUILayer_o *Component_GUILayer;
  f32 FilterAlpha;
  UnityEngine_GUILayer_o *v135;
  UnityEngine_GUILayer_o *v136;
  f32 v137;
  UnityEngine_GUILayer_o *v138;
  u64 v144;
  s32 v145;
  s32 v146;
  s32 Integer;
  s32 v149;
  struct Nme_KeyBoard_StaticFields *v150;
  s32 NameUIPos;
  u32 v152;
  s32 v153;
  struct Nme_KeyBoard_StaticFields *v154;
  UnityEngine_Animator_o *EndSetAnim;
  System_String_o *v164;
  bool v165;
  s32 v169;
  dds3ProcessID_t_o *id;
  UnityEngine_Rect_o v171;
  char *v172;
  UnityEngine_Vector2_o zero;

  id = PID;
  v3 = cmpChkCommonInput(0x1000u);
  ProcessData = dds3GetProcessData(&id);
  else
  {
    if (!ProcessData)
      goto LABEL_18;
  }
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nmeData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nmeData_t, &v171);
    if ((LOBYTE(v171.m_XMin) & 1) != 0)
      v9 = v172;
    else
      v9 = &v171.m_XMin + 1;
    v10 = sub_8C4940(v9);
  }
LABEL_18:
  GBWK = ProcessData;
  else if (dds3FadeCheck())
  {
    return 0;
  }
  if ((v13 & 0x200) != 0)
  {
    v14 = v13 & 0x200;
  }
  else
  {
    v14 = 0;
  }
  v15 = *(v12 + 184);
  if ((GBWK->SeqInfo->Flag & 0x40) != 0)
  {
    ClearNameUI(v12);
    id->func_ans = -1;
    return 0;
  }
  if (yesnoflag)
    goto LABEL_170;
  if (!TransitionNo)
  {
    if (TextZyage(v12))
    {
      if (v3 == 4096)
      {
        NameYseNoflag = 1;
      }
      cmpPlaySE(v3);
    }
  }
  v17 = *(v12 + 184);
  if (!FadeMove)
  {
    if (KeyBoardUseflag)
    {
      v21 = tblHelp->m_Items[MojiType];
      LocalizeText = GetLocalizeText(v21);
      UseHelp = LocalizeText;
      v26 = MojiType;
      if (!v26)
        goto LABEL_73;
      if (v26 == 1)
      {
LABEL_73:
        v27 = *&v24->_2.bitflags1;
        if ((v27 & 0x200) != 0)
        {
          v28 = v27 & 0x200;
          if (!MojiSize)
          {
LABEL_75:
            else
            {
              MojiNum = 4;
              if ((v24->_2.bitflags2 & 2) == 0)
                goto LABEL_108;
            }
            goto LABEL_106;
          }
        }
        else
        {
          v28 = 0;
          if (!MojiSize)
            goto LABEL_75;
        }
LABEL_93:
        MojiNum = 8;
        if ((v24->_2.bitflags2 & 2) == 0)
          goto LABEL_108;
        goto LABEL_106;
      }
      v29 = *&v24->_2.bitflags1;
      if ((v29 & 0x200) != 0)
      {
        v30 = v29 & 0x200;
        if (!MojiSize)
        {
LABEL_91:
            goto LABEL_103;
          goto LABEL_93;
        }
      }
      else
      {
        v30 = 0;
        if (!MojiSize)
          goto LABEL_91;
      }
      MojiNum = 16;
      if ((v24->_2.bitflags2 & 2) == 0)
      {
LABEL_108:
        v33 = MojiType;
        if (NameSave2->m_Items[v33])
        {
          v36 = NameSave2;
          v37 = MojiType;
          UseName = v36->m_Items[v37];
          if ((v24->_2.bitflags2 & 2) == 0)
            goto LABEL_129;
        }
        else
        {
          v41 = MojiType + 3 * CharNo;
          v43 = tblDefName->m_Items[v41];
          v44 = GetLocalizeText(v43);
          UseName = v44;
          if ((v24->_2.bitflags2 & 2) == 0)
            goto LABEL_129;
        }
LABEL_129:
        v45 = NewSpecific(UnityEngine_GameObject, MojiNum);
        NameSet = v45;
        v47 = NewSpecific(TMPro_TextMeshProUGUI, MojiNum);
        NameSetTM = v47;
        v48 = 4;
        v49 = *(v12 + 294);
        v50 = 0;
        if ((v49 & 0x200) == 0)
          goto LABEL_149;
        while (1)
        {
          v51 = v49 & 0x200;
          v52 = *(v12 + 184);
          if (v50 >= MojiNum)
            break;
          while (1)
          {
            LODWORD(v171.m_XMin) = MojiType + 1;
            v54 = sub_8D3950(s32, &v171);
            v55 = v50 + 1;
            v169 = v55;
            v56 = sub_8D3950(s32, &v169);
            v57 = Format_5268592("Form{0:0}/Text/TextTM{1:00}", v54, v56);
            v58 = Concat_5221536("AnotherCountry/Anm/", MojiSizeStr, v57);
            StrAssist = v58;
            transform = get_transform(NameUIObj, 0);
            v63 = Find(transform, StrAssist, 0);
            gameObject = get_gameObject(v63);
            v65 = gameObject;
            v67 = v55 - 1;
            *&NameSet[2 * v48] = v65;
            v70 = NameSet;
            Component_object = GetComponent_object_(
                                 *(&v70->obj.klass + v48));
            v74 = Component_object;
            *&NameSetTM[2 * v48] = v74;
            ++v48;
            v50 = v48 - 4;
            if ((v49 & 0x200) != 0)
              break;
LABEL_149:
            v51 = 0;
            v52 = *(v12 + 184);
            if (v50 >= MojiNum)
              goto LABEL_150;
          }
        }
LABEL_150:
        TransitionNo = 3;
        goto LABEL_154;
      }
LABEL_106:
      goto LABEL_108;
    }
  }
LABEL_154:
  v77 = *(v12 + 184);
  if (NameYseNoflag == 1)
  {
    ChangeColor = 1;
    MojiColorChange(v12);
    if (get_activeSelf(NameDescriptionFrame))
    {
      SetActive(NameDescriptionFrame, 0, 0);
    }
    *(*(v12 + 184) + 52LL) = 1;
    *(*(v12 + 184) + 24LL) = 0;
    *(*(v12 + 184) + 20LL) = 2;
  }
LABEL_170:
  v79 = *(v12 + 184);
  switch (NameUIPos)
  {
    case 0:
      v83 = NameDecRcl->m_Items[0];
        goto LABEL_201;
      goto LABEL_203;
    case 1:
      v85 = NameDecRcl;
      v83 = v85->m_Items[1];
        goto LABEL_203;
      goto LABEL_201;
    case 2:
      v87 = NameDecRcl;
      v83 = v87->m_Items[2];
        goto LABEL_203;
      goto LABEL_201;
    case 3:
      v89 = NameDecRcl;
      v83 = v89->m_Items[3];
      {
LABEL_201:
      }
LABEL_203:
      v91 = GetLocalizeText(v83);
      v92 = NewSpecific(object, 1u);
      LODWORD(v171.m_XMin) = 22;
      v93 = v92;
      v94 = sub_8D3950(s32, &v171);
      v96 = v94;
      v93->m_Items[0] = v96;
      v99 = RepColTag(v91, v93);
      set_text(NameDescriptionTM, v99);
      break;
    default:
      break;
  }
  get_IsOpenIME(keyboardObj_a);
  switch (TransitionNo)
  {
    case 0:
      KeyMove(v103);
      if (FrameMove)
      {
        FrameMove = 0;
      }
      PS4Nextflag = 0;
      goto LABEL_334;
    case 1:
      if ((v108 & 0x200) != 0)
      {
        v109 = v108 & 0x200;
        if (!NameKeyBoardflag)
          goto LABEL_230;
      }
      else
      {
        v109 = 0;
        if (!NameKeyBoardflag)
        {
LABEL_230:
          NameKeyBoardflag = 1;
          KeyBoardDraw(
            (*p_static_fields)->UseHelp,
            (*p_static_fields)->UseName,
            (*p_static_fields)->MojiNum,
            (*p_static_fields)->UseLang);
          goto LABEL_334;
        }
      }
      MojiInput(v103);
LABEL_334:
      v145 = 4;
      do
      {
        while (1)
        {
          Integer = GetInteger(*(*(v144 + 184) + 464LL), "select", 0);
          v149 = NameUIPos + 1;
          if (Integer != v149)
          {
            SetInteger(SelFrameAnim, "select", v149);
          }
          if ((*(v144 + 295) & 2) != 0 && !*(v144 + 216))
          {
            if (KeyBoardUseflag != 1)
              goto LABEL_357;
          }
          else
          {
            v150 = *(v144 + 184);
            if (KeyBoardUseflag != 1)
              goto LABEL_357;
          }
          if ((*(v144 + 295) & 2) == 0 || *(v144 + 216))
            break;
          if (NameUIPos != 3)
            goto LABEL_349;
LABEL_357:
          v152 = *(v144 + 294);
          v146 = (v152 >> 9) & 1;
          if (!--v145)
            goto LABEL_358;
        }
        if (NameUIPos == 3)
          goto LABEL_357;
LABEL_349:
        MojiType = NameUIPos;
        v152 = *(v144 + 294);
        v146 = (v152 >> 9) & 1;
        --v145;
      }
      while (v145);
LABEL_358:
      v153 = v152 & 0x200;
      if ((v152 & 0x200) != 0 && !*(v144 + 216))
      {
        if (TransitionNo == 2)
          goto LABEL_361;
      }
      else
      {
        v154 = *(v144 + 184);
        if (TransitionNo == 2)
        {
LABEL_361:
          if (GetInteger(SelFrameAnim, "select"))
          {
            SetInteger(SelFrameAnim, "select", 0);
          }
            goto LABEL_370;
          goto LABEL_392;
        }
      }
      if (TextZyage(v144))
      {
        ButtonGuideDispSet("NAME03", 0, 0, 90);
        if (!GetBool(EndSetAnim, "fix"))
        {
          v164 = "fix";
          v165 = 1;
LABEL_397:
          SetBool(EndSetAnim, v164, v165);
        }
      }
      else
      {
        ButtonGuideDispSet("NAME02", 0, 0, 90);
        {
LABEL_370:
        }
LABEL_392:
        if (GetBool(EndSetAnim, "fix"))
        {
          v164 = "fix";
          v165 = 0;
          goto LABEL_397;
        }
      }
      return 0;
    case 2:
      KeyBoradEnd(v103);
      goto LABEL_334;
    case 3:
      if (!FadeMove)
      {
        if (!BackInit)
        {
          BackImageCreate(v103);
          v110 = Find("Canvas_UI", 0);
          MainCanvas = v110;
          v112 = GetComponent_object_(MainCanvas);
          CanvasMenu = v112;
          set_renderMode(CanvasMenu, 1);
          set_worldCamera(CanvasMenu, CameraR);
          if (get_activeSelf(RenImageObj))
          {
            SetActive(RenImageObj, 0, 0);
          }
          *(*(v103 + 184) + 325LL) = 1;
        }
      }
      *(*(v103 + 184) + 322LL) = 1;
      v118 = op_Inequality(BackImageTex, 0, 0);
      if (v118)
      {
        FilterAlpha = FilterAlpha + 0.1;
      }
      if (!Capflag)
      {
        Fadeflag = 0;
        v122 = BackImageTex;
        if (op_Inequality(v122, 0, 0))
        {
          v124 = BackImageTex;
          *&v171.m_XMin = 0;
          *&v171.m_Width = 0;
          sub_1A1D780(&v171.m_XMin, 0.0, 0.0, 477.0, 548.0);
          zero = get_zero();
          _27456544 = Create_27456544(v124, v171, zero);
          BackImageCap = _27456544;
          v129 = GetComponent_object_(Filter);
          set_sprite(v129, BackImageCap);
          Capflag = 1;
          BackImageCreate();
        }
      }
      if (FilterAlpha >= 1.0)
      {
        FilterAlpha = 1.0;
        TransitionNo = 1;
      }
      Component_GUILayer = GetComponent_GUILayer_(RenImage);
      v135 = Component_GUILayer;
      *&v171.m_XMin = 0;
      *&v171.m_Width = 0;
      sub_19EC630(&v171.m_XMin, 255.0, 255.0, 255.0, FilterAlpha);
      (v135->klass[1].vtable._0_Equals.method)(
        v135,
        v135->klass[1].vtable._1_Finalize.methodPtr,
        v171.m_XMin,
        v171.m_YMin,
        v171.m_Width,
        v171.m_Height);
      goto LABEL_334;
    case 4:
      FilterAlpha = FilterAlpha + -0.1;
      v136 = GetComponent_GUILayer_(
               (*p_static_fields)->RenImage);
      v137 = FilterAlpha;
      v138 = v136;
      *&v171.m_XMin = 0;
      *&v171.m_Width = 0;
      sub_19EC630(&v171.m_XMin, 255.0, 255.0, 255.0, v137);
      (v138->klass[1].vtable._0_Equals.method)(
        v138,
        v138->klass[1].vtable._1_Finalize.methodPtr,
        v171.m_XMin,
        v171.m_YMin,
        v171.m_Width,
        v171.m_Height);
      if (FilterAlpha <= 0.0)
      {
        Capflag = 0;
        FadeMove = 0;
        Fadeflag = 1;
        FilterAlpha = 0.0;
        KeyBoardUseflag = 0;
        NameKeyBoardflag = 0;
        BackImageTex = 0;
        set_targetTexture(CameraR, 0);
        if (get_activeSelf(RenImageObj))
        {
          SetActive(RenImageObj, 0, 0);
        }
        TransitionNo = 0;
      }
      goto LABEL_334;
    default:
      goto LABEL_334;
  }
}
