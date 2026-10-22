#include "types.h"

typedef struct GsFont_t GsFont_t;
typedef struct TextManager TextManager;
typedef struct _FRQ _FRQ;
typedef struct _RING_BUF _RING_BUF;
typedef struct _TEXT _TEXT;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct evtTexManager evtTexManager;
typedef struct frDrawCommonPkt_t frDrawCommonPkt_t;
typedef struct frDrawEnvPkt_t frDrawEnvPkt_t;
typedef struct frFontTable_t frFontTable_t;
typedef struct frGsTex_t frGsTex_t;
typedef struct frMsgInfo_t frMsgInfo_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;

static u8 frImageDumpFlag;
static frFontTable_t *gFT;
static u32 gMessageRequestResult;
static s8 gMessageSpaceX;
static s32 gMessageStepY;
static s8 gFontBaseWidth[5];
static s8 gModeFlag;
static char *gVarStr[32];
static s32 gRegistMax;
static u32 gFontDrawOT;
static char *DrawBuffer;
static u32 DrawColor;
static char *TagList[9];
static s8 frGetYShiftLev_y_sht_tbl[114];
static u8 frSetFontString_style;
static s32 frFlipPacketBuf_x;
static s32 frFlipPacketBuf_y;
static u8 frFlipPacketBuf_trig;
static sdfDrawTag_t *frDumpFontTexture_env_tag[2];
static frDrawEnvPkt_t *frDumpFontTexture_env_pkt[2];
static sdfDrawTag_t *frDumpFontTexture_draw_tag[2];
static frDrawCommonPkt_t *frDumpFontTexture_draw_pkt[2];
static char *ColMaterialName[26];
static void *pRepColTagRet;

s32 CMP_YM(s32 b);
char *ConvertChar(TextManager *this, u16 data);
void Draw(s32 x, s32 y, _FRQ *frq, s32 colno);
void Draw_20213232(TextManager *this, f32 x, f32 y, f32 z, char *text, _FRQ *frq);
u8 **EncodingSJIS(char *instr);
sdfVector2_t GetFontSize(TextManager *this, s32 no);
char *GetLocalizeText(char *ID);
char *GetLocalizeText_19472448(char *dic, char *ID);
s32 GetTagIndex(char *tag);
void Initialize(evtTexManager *this, char *key, char *path);
_FRQ *MessageRequestEx2(s32 X, s32 Y, u32 Z, u8 Style, u8 ColNo, u8 Tp, u8 Spd, u8 **pMsg, _FRQ *pFRQ);
_FRQ *MessageRequestExLocalize(s32 x, s32 y, u8 Style, u8 ColNo, u8 Tp, u8 Spd, u8 **pMsg, _FRQ *pFRQ);
s32 SDF_ABORT1(char *a);
u8 **UnicodeToIndexByte(TextManager *this, char *str);
s32 dds3GetFrameID(void);
void fldCamMainEventForUnity(void);
_FRQ *frAnalyzeMessage(frMsgInfo_t *pMsgInfo);
_FRQ *frAnalyzeMessageLocalize(frMsgInfo_t *pMsgInfo);
s8 frAnalyzeTag(s32 code, frMsgInfo_t **mi);
s8 frAnalyzeTagLocalize1(s32 code, frMsgInfo_t **mi, char **message, void *index);
s8 frAnalyzeTagLocalize2(char *message, s32 *index, frMsgInfo_t **mi);
void frCreateDrawFontPacket(s32 x, s32 y, _FRQ *frq, _TEXT *text);
void frCreateNewHandle(frMsgInfo_t *pMsgInfo);
void frCreateVariableRequest(char *VarNo, frMsgInfo_t *pMsgInfo);
_FRQ *frDestroyFontRequestNow(_FRQ *pFRQ);
s32 frDrawFontEx2(_FRQ *pFRQ, s8 Mode, u32 Ot);
_FRQ *frGetCNameFRQ(s8 TargetNo, s8 Style, _FRQ *pFRQ);
char *frGetCNameString(s8 TargetNo);
_FRQ *frGetName1NFRQ(s8 TargetNo, s8 Style, _FRQ *pFRQ);
char *frGetName1NString(s8 TargetNo);
_FRQ *frGetName2NFRQ(s8 TargetNo, s8 Style, _FRQ *pFRQ);
char *frGetName2NString(s8 TargetNo);
void frGetXShiftLev(_TEXT *pText, s32 FontNo);
_FRQ *frLinkFontString_20580272(u8 **pStr, s8 Style, s8 ColNo, s8 Tp, _FRQ *pFRQ);
char *frReplaceLocalizeText(char *message, frMsgInfo_t **mi, void *index);
_TEXT *frSetFont(u16 Code, u8 Style, u8 ColNo, u8 Tp);
_FRQ *frSetFontStringLocalize(u16 pStr, s8 Style, s8 ColNo, s8 Tp, _FRQ *pFRQ);
_FRQ *frSetFontString_20554176(u8 **pStr, s8 Style, s8 ColNo, s8 Tp, _FRQ *pFRQ);
_FRQ *frSetUserImage(GsFont_t *pFont, _FRQ *pFRQ);
s32 rbDestroyRingBuf(s32 index, _RING_BUF *pRingBuf);
_RING_BUF *rbInitRingBuf(s32 index, s32 Nums);
_TEXT *rbRentFromRingBuf__TEXT_(_RING_BUF *pRingBuf);
s32 rbRetToRingBuf__TEXT_(s32 index, _TEXT *pBuf, _RING_BUF *pRingBuf);
char *replace_space(char *message);

// 0x139edd0
_FRQ *CreateVarFRQ(char *message) {
  u64 *v3;
  s32 Length;
  s32 v5;
  s32 v6;
  u16 Chars;
  u64 *v13;

  v3 = Allocate(frMsgInfo_t);
  _ctor(v3, 0);
  Length = get_Length(message);
  if (Length >= 1)
  {
    v5 = Length;
    v6 = 0;
    while (1)
    {
      Chars = get_Chars(message, v6);
      if (Chars != 10)
      {
        frCreateNewHandle(v3);
        v13 = NewSpecific(byte, 2u);
        *(v13 + 32) = 0x80;
        v3[5] = frSetFontStringLocalize(Chars, *(v3 + 28), *(v3 + 29), *(v3 + 30), v3[5]);
        goto LABEL_31;
      }
      else
      {
        if ((gModeFlag & 4) != 0)
          goto LABEL_13;
LABEL_31:
        if (v5 == ++v6)
          return v3[5];
      }
    }
  }
  return v3[5];
}

// 0x13a2190
char *CutAF_DEL(char *message) {
  s32 v3;

  v3 = IndexOf_5260384(message, "<AF_DEL>");
  if (v3 == -1)
    return message;
  else
    return Substring_5248048(message, 0, v3);
}

// 0x13991a0
s32 DIC2NO(s32 val) {
  return ((val - 32896) >> 1) & 0x7F80 | (val - 32896) & 0x7F;
}

// 0x13991d0
void Draw(s32 x, s32 y, _FRQ *frq, s32 colno) {
  struct _TEXT_o *str;
  struct System_UInt32_array_array *frClutTbl;
  System_UInt32_array *v15;
  struct System_UInt32_array_array *v17;
  u32 v18;
  System_UInt32_array *v19;
  u32 v22;
  TextManager_o *txtMgr;

  if (!IsNullOrEmpty(DrawBuffer))
  {
    if (frq)
    {
      str = frq->str;
      v15 = frClutTbl->m_Items[colno];
      v17 = frClutTbl;
      v18 = v15->m_Items[15];
      v19 = v17->m_Items[colno];
      if (str)
      {
        v22 = v19->m_Items[0];
        do
        {
          str->color_base = v18;
          str->color_edge = v22;
          str = str->next;
        }
        while (str);
      }
    }
    Draw_20213232(txtMgr, x, y, 0.0, DrawBuffer, frq);
  }
}

// 0x13991c0
s32 FR_STR_WIDTH(_FRQ *frq) {
  return frq->w_pxls;
}

// 0x139e390
s32 GetTagIndex(char *tag) {
  s32 Length;
  s64 v5;
  s32 v6;
  u64 v8;
  struct System_String_array *TagList;
  u64 max_length_low;
  struct System_String_array *v13;
  s32 v15;
  System_String_o *v16;
  System_String_o *v17;
  struct System_String_array *v18;

  Length = get_Length(tag);
  v5 = 4;
  v6 = -1;
  v8 = 0;
  {
LABEL_6:
  }
  while (1)
  {
    max_length_low = LODWORD(TagList->max_length);
    if (v8 >= max_length_low)
      return v6;
    else if (v8 >= max_length_low)
    {
      goto LABEL_12;
    }
    if (get_Length(*(&TagList->obj.klass + v5), 0) < Length)
    {
      v13 = TagList;
      v15 = get_Length(*(&v13->obj.klass + v5), 0);
      v16 = Substring_5248048(tag, 0, v15);
      v17 = ToUpper(v16, 0);
      v18 = TagList;
      if (Equals_5234480(v17, *(&v18->obj.klass + v5), 0))
        return v5 - 4;
    }
    ++v5;
    v8 = v5 - 4;
      goto LABEL_6;
  }
}

// 0x13a13b0
u8 **MessageNumSearch(s32 Index, u8 **pData, s32 Size) {
  System_Array_o *v7;
  s32 v8;
  s32 v9;
  u32 v10;
  s32 v11;

  v7 = 0;
  if (ToInt32(pData, 24, 0) > Index)
  {
    v8 = ToInt32(pData, 8 * Index + 36, 0);
    v9 = v8 + 4 * ToInt16(pData, v8 + 56, 0);
    v10 = ToInt32(pData, v9 + 60, 0);
    v11 = v9 + 64;
    v7 = NewSpecific(byte, v10);
    Copy_3880080(pData, v11, v7, 0, v10);
  }
  return v7;
}

// 0x13a14d0
_FRQ *MessageRequest(s32 X, s32 Y, u8 **pMsg, _FRQ *pFRQ) {
  return MessageRequestEx2(X, Y, 0, 0, 0, 0, 0x80u, pMsg, pFRQ);
}

// 0x13a1870
_FRQ *MessageRequestEx(s32 X, s32 Y, u8 Style, u8 ColNo, u8 Tp, u8 Spd, u8 **pMsg, _FRQ *pFRQ) {
  return MessageRequestEx2(X, Y, 0, Style, ColNo, Tp, Spd, pMsg, pFRQ);
}

// 0x13a1580
_FRQ *MessageRequestEx2(s32 X, s32 Y, u32 Z, u8 Style, u8 ColNo, u8 Tp, u8 Spd, u8 **pMsg, _FRQ *pFRQ) {
  u64 *v18;
  System_Array_o *v19;

  v18 = Allocate(frMsgInfo_t);
  _ctor(v18, 0);
  *(v18 + 4) = X;
  *(v18 + 5) = Y;
  *(v18 + 28) = Style;
  *(v18 + 6) = 16 * Z;
  *(v18 + 29) = ColNo;
  *(v18 + 30) = Tp;
  *(v18 + 31) = Spd;
  v19 = NewSpecific(byte, LODWORD(pMsg->max_length));
  v18[4] = v19;
  Copy_3886320(pMsg, v19, pMsg->max_length);
  v18[5] = pFRQ;
  *(v18 + 12) = 0;
  *(v18 + 26) = 257;
  return frAnalyzeMessage(v18);
}

// 0x13a17b0
_FRQ *MessageRequestEx2Localize(s32 X, s32 Y, u8 Style, u8 ColNo, u8 Tp, u8 Spd, u8 **pMsg, _FRQ *pFRQ) {
  return MessageRequestExLocalize(X, Y, Style, ColNo, Tp, Spd, pMsg, pFRQ);
}

// 0x13a16a0
_FRQ *MessageRequestExLocalize(s32 x, s32 y, u8 Style, u8 ColNo, u8 Tp, u8 Spd, u8 **pMsg, _FRQ *pFRQ) {
  u64 *v17;
  System_Array_o *v18;

  v17 = Allocate(frMsgInfo_t);
  _ctor(v17, 0);
  *(v17 + 4) = x;
  *(v17 + 5) = y;
  *(v17 + 6) = 0;
  *(v17 + 28) = Style;
  *(v17 + 29) = ColNo;
  *(v17 + 30) = Tp;
  *(v17 + 31) = Spd;
  v18 = NewSpecific(byte, LODWORD(pMsg->max_length));
  v17[4] = v18;
  Copy_3886320(pMsg, v18, pMsg->max_length);
  v17[5] = pFRQ;
  *(v17 + 12) = 0;
  *(v17 + 26) = 257;
  return frAnalyzeMessageLocalize(v17);
}

// 0x13a1940
_FRQ *MessageRequestNS(s32 X, s32 Y, u32 Z, u8 Style, u8 ColNo, u8 Tp, u8 Spd, u8 **pMsg, _FRQ *pFRQ) {
  s8 gMessageSpaceX;
  _FRQ_o *result;

  gMessageSpaceX = 0;
  result = MessageRequestEx2(X, Y, Z, Style, ColNo, Tp, Spd, pMsg, 0);
  return result;
}

// 0x1399180
s32 NO2DIC(s32 val) {
  return (((2 * val) & 0x1FF00) + 32896) & 0xFFFFFF80 | val & 0x7F;
}

// 0x13a1cf0
char *RepColTag(char *txt, void **LegacyParamArray) {
  il2cpp_array_size_t max_length;
  System_Text_StringBuilder_o *pRepColTagRet;
  struct System_String_array *ColMaterialName;
  s64 v13;
  s64 v18;
  u64 v19;
  Il2CppClass **v21;
  s32 v22;
  s64 v25;
  struct System_String_array *v27;
  System_String_o *v29;
  System_Text_StringBuilder_o *v30;
  System_String_o *v31;
  s32 Length;

  max_length = LegacyParamArray->max_length;
  if (!max_length)
    return txt;
  Clear(pRepColTagRet, 0);
  if (max_length == 1)
  {
    else
    {
      if (!LODWORD(LegacyParamArray->max_length))
        goto LABEL_11;
    }
    v13 = *il2cp::SizeOf(LegacyParamArray->m_Items[0], s32);
    AppendFormat(pRepColTagRet, "<material=\"{0}\">", ColMaterialName->m_Items[v13]);
    Append_5380272(pRepColTagRet, txt);
  }
  else
  {
    Append_5380272(pRepColTagRet, txt);
    if (max_length >= 1)
    {
      v18 = max_length;
      v19 = 0;
      do
      {
        v21 = &LegacyParamArray->obj.klass + v19;
        v22 = *il2cp::SizeOf(v21[4], s32);
        v25 = *il2cp::SizeOf(v21[5], s32);
        v27 = ColMaterialName;
        v29 = Format("<material=\"{0}\">", v27->m_Items[v25], 0);
        v30 = pRepColTagRet;
        v31 = v29;
        Length = get_Length(v29);
        Insert(v30, v22, v31, Length, 0);
        v19 += 2LL;
        --v18;
      }
      while (v18);
    }
  }
  return (pRepColTagRet->klass->vtable._3_ToString.methodPtr)(
           pRepColTagRet,
           pRepColTagRet->klass->vtable._3_ToString.method);
}

// 0x13a1ff0
char *RepColTag_20586480(char *txt) {
  s32 v3;
  s32 i;
  s32 v5;
  System_String_o *v6;
  s32 Length;
  System_String_o *v8;
  System_String_o *v9;
  System_String_o *v10;
  u64 *v11;
  System_String_o *v12;
  s32 v14;
  s32 result;

  result = 0;
  v3 = IndexOf_5260400(txt, "<COLOR", 0);
  if (v3 != -1)
  {
    for (i = v3; i != -1; i = IndexOf_5260400(txt, "<COLOR", i))
    {
      v5 = IndexOf_5260400(txt, ">", i + 6);
      if (v5 == -1)
        break;
      v6 = Substring_5248048(txt, i, 1 - i + v5);
      Length = get_Length(v6);
      v8 = Substring_5248048(v6, 6, Length - 6);
      v9 = Replace_5267216(v8, " ", "");
      v10 = Replace_5267216(v9, ">", "");
      if (!TryParse(v10, &result, 0))
        break;
      v14 = result;
      v11 = sub_8D3950(s32, &v14);
      v12 = Format("<material=\"MsgFont{0}\">", v11, 0);
      txt = Replace_5267216(txt, v6, v12);
    }
  }
  return txt;
}

// 0x139f9f0
void frAddFontStyle(u8 StyleNo, u8 **pFontData, sdfMemHandle_t *DataMh) {
  ;
}

// 0x139a4f0
_FRQ *frAnalyzeMessage(frMsgInfo_t *pMsgInfo) {
  frMsgInfo_t_o *v3;
  struct System_Byte_array *pMsg;
  s64 Ofs;
  struct System_Byte_array *v10;
  s32 v12;
  u8 v13;
  frMsgInfo_t_o *v15;
  s32 Y;
  s32 gMessageStepY;
  frMsgInfo_t_o *v19;
  System_Byte_array *v23;
  s64 v26;
  struct System_Byte_array *v27;
  s32 v29;
  u32 v30;
  s16 v31;
  u64 *v32;
  u32 v34;
  System_Byte_array *v35;
  _FRQ_o *pFRQ;
  struct _FRQ_o **p_pFRQ;
  u8 ColNo;
  u8 Tp;
  System_Byte_array *v41;
  s8 v42;
  s8 v43;
  s8 v44;
  u64 *v45;
  u32 v46;
  u8 Style;
  u8 v49;
  u8 v50;
  struct _FRQ_o *v52;
  s8 gMessageSpaceX;
  struct _TEXT_o *str;
  s32 v55;
  s32 lw;
  frMsgInfo_t_o *mi;

  v3 = pMsgInfo;
  gModeFlag |= 1u;
  gModeFlag &= ~2u;
  while (1)
  {
    Ofs = v3->Ofs;
    v10 = v3->pMsg;
    v3->Ofs = Ofs + 1;
    v12 = v10->m_Items[Ofs];
    if (!v10->m_Items[Ofs])
      break;
    if ((~v12 & 0xF0) != 0)
    {
      v13 = v10->m_Items[Ofs];
      if (v12 != 10)
      {
        v19 = mi;
        else
        {
          frCreateNewHandle(mi);
          if ((v12 & 0x80000000) == 0)
            goto LABEL_52;
LABEL_58:
          v26 = mi->Ofs;
          v27 = mi->pMsg;
          mi->Ofs = v26 + 1;
          v29 = v27->m_Items[v26];
          v30 = v29 & 0xFFFF00FF | (v12 << 8);
          if (v30 >> 7 > 0x180)
          {
            v31 = v30 - 0x4000;
            v32 = NewSpecific(byte, 3u);
            v34 = *(v32 + 6);
            v35 = v32;
            *(v32 + 32) = HIBYTE(v31);
            *(v32 + 33) = v31;
            p_pFRQ = &mi->pFRQ;
            pFRQ = mi->pFRQ;
            ColNo = mi->ColNo;
            Tp = mi->Tp;
            v41 = v35;
            v42 = 8;
            v43 = ColNo;
            v44 = Tp;
LABEL_76:
            *p_pFRQ = frSetFontString_20554176(v41, v42, v43, v44, pFRQ);
            v52 = mi->pFRQ;
            else
            {
              if ((byte_3F59674 & 1) == 0)
                goto LABEL_79;
            }
            v52->space = gMessageSpaceX;
            else
            {
              str = v52->str;
              if (str)
              {
LABEL_83:
                v55 = 0;
                do
                {
                  lw = str->lw;
                  str = str->next;
                  v55 += v52->space + lw;
                }
                while (str);
                goto LABEL_90;
              }
            }
            v55 = 0;
LABEL_90:
            v52->w_pxls = v55;
            mi->pFRQ->priority = mi->Z >> 4;
            goto LABEL_24;
          }
          v45 = NewSpecific(byte, 3u);
          v46 = *(v45 + 6);
          v23 = v45;
          *(v45 + 32) = v13;
          *(v45 + 33) = v29;
        }
        p_pFRQ = &mi->pFRQ;
        pFRQ = mi->pFRQ;
        Style = mi->Style;
        v49 = mi->ColNo;
        v50 = mi->Tp;
        v41 = v23;
        v42 = Style;
        v43 = v49;
        v44 = v50;
        goto LABEL_76;
      }
      else if ((gModeFlag & 4) == 0)
      {
        goto LABEL_24;
      }
      v15 = mi;
      else if ((byte_3F5967C & 1) == 0)
      {
        goto LABEL_41;
      }
      Y = v15->Y;
      v15->Y = CMP_YM(gMessageStepY) + Y;
      *&v15->FrqFlag = 257;
      goto LABEL_24;
    }
    if (frAnalyzeTag(v12, &mi) == 1)
      break;
LABEL_24:
    v3 = mi;
  }
  else if ((byte_3F59676 & 1) == 0)
  {
    goto LABEL_98;
  }
  gModeFlag &= ~1u;
  gModeFlag |= 2u;
  return mi->pFRQ;
}

// 0x139bc10
_FRQ *frAnalyzeMessageLocalize(frMsgInfo_t *pMsgInfo) {
  struct System_Byte_array *pMsg;
  struct System_Byte_array *v4;
  u64 *v8;
  char v12;
  s32 v13;
  s64 Ofs;
  struct System_Byte_array *v15;
  s32 v17;
  System_String_o *v18;
  System_String_o *v19;
  System_String_o *v20;
  System_String_o *v21;
  System_String_o *v22;
  s32 Length;
  s32 v25;
  s32 i;
  u16 Chars;
  u16 v29;
  System_String_o *v30;
  frMsgInfo_t_o *v31;
  u64 *v32;
  frMsgInfo_t_o *v35;
  struct _FRQ_o *pFRQ;
  u16 v44[2];
  s32 index;
  System_String_o *message;
  frMsgInfo_t_o *mi;

  message = 0;
  mi = pMsgInfo;
  index = 0;
  v44[0] = 0;
  pMsg = pMsgInfo->pMsg;
  if (pMsg->m_Items[0] <= 0xEFu)
  {
    v4 = pMsgInfo->pMsg;
    if (v4->m_Items[1] == 8)
      pMsgInfo->Ofs += 4;
  }
  gMessageRequestResult &= ~1u;
  gMessageRequestResult &= ~2u;
  gMessageRequestResult &= ~4u;
  gModeFlag |= 1u;
  gModeFlag &= ~2u;
  message = "";
  v8 = Allocate(System_Collections_Generic_List_int_);
  __ctor(v8);
  v12 = 0;
  v13 = 0;
  while (1)
  {
    Ofs = pMsgInfo->Ofs;
    v15 = pMsgInfo->pMsg;
    pMsgInfo->Ofs = Ofs + 1;
    v17 = v15->m_Items[Ofs];
    if (!v15->m_Items[Ofs])
      break;
    if ((~v17 & 0xF0) != 0)
    {
      if (!v13)
        _Add(v8, 0);
      v19 = message;
      v44[0] = v17;
      v20 = sub_3C3A80(v44, 0);
      v12 = (v17 != 62) & (v12 | (v17 == 60));
      ++v13;
      message = Concat_5224608(v19, v20);
    }
    else
    {
      if ((v12 & 1) != 0)
      {
        v18 = message;
        message = replace_space(v18);
      }
      if (frAnalyzeTagLocalize1(v17, &mi, &message, v8) == 1)
        goto LABEL_47;
      v12 = 0;
      v13 = 0;
    }
    pMsgInfo = mi;
  }
  if ((v12 & 1) != 0)
  {
    v21 = message;
    message = replace_space(v21);
  }
LABEL_47:
  v22 = message;
  message = frReplaceLocalizeText(v22, &mi, v8);
  index = 0;
  Length = get_Length(message);
  if (Length >= 1)
  {
    v25 = Length;
    for (i = 0; i < v25; index = ++i)
    {
      while (1)
      {
        Chars = get_Chars(message, i);
        if (Chars == 10)
          break;
        v29 = Chars;
        if (Chars != 60)
          goto LABEL_60;
        v30 = message;
        if (frAnalyzeTagLocalize2(v30, &index, &mi))
        {
          i = index;
          if (index >= v25)
            goto LABEL_87;
        }
        else
        {
LABEL_60:
          v31 = mi;
          frCreateNewHandle(v31);
          v32 = NewSpecific(byte, 2u);
          *(v32 + 32) = 0x80;
          v35 = mi;
          v35->pFRQ = frSetFontStringLocalize(v29, mi->Style, mi->ColNo, mi->Tp, mi->pFRQ);
          i = index + 1;
          index = i;
          if (i >= v25)
            goto LABEL_87;
        }
      }
      else if ((gModeFlag & 4) != 0)
      {
        goto LABEL_70;
      }
    }
  }
LABEL_87:
  pFRQ = mi->pFRQ;
  if (pFRQ)
    pFRQ->tag_id = mi->talk_tag;
LABEL_93:
  gModeFlag &= ~1u;
  gModeFlag |= 2u;
  return mi->pFRQ;
}

// 0x139ad00
s8 frAnalyzeTag(s32 code, frMsgInfo_t **mi) {
  frMsgInfo_t_o *v5;
  s64 Ofs;
  struct System_Byte_array *pMsg;
  u8 ColNo;
  s32 v10;
  frMsgInfo_t_o *v11;
  s64 v12;
  struct System_Byte_array *v13;
  struct System_String_array *gVarStr;
  struct System_Byte_array *v19;
  s64 v20;
  s64 v22;
  frMsgInfo_t_o *v24;
  struct System_String_array *v26;
  struct System_Byte_array *v27;
  s64 v28;
  s64 v30;
  System_String_o *v33;
  u64 *_9__43_0;
  System_String_o *v36;
  Il2CppObject *v37;
  System_String_o *v40;
  frMsgInfo_t_o *v41;
  frMsgInfo_t_o *v42;
  s32 v43;
  frMsgInfo_t_o *v44;
  s64 v45;
  struct System_Byte_array *v46;
  frMsgInfo_t_o *v48;
  s64 v49;
  struct System_Byte_array *v50;
  frMsgInfo_t_o *v52;
  s64 v53;
  struct System_Byte_array *v54;
  frMsgInfo_t_o *v56;
  s8 result;
  s64 v58;
  struct System_Byte_array *v59;
  u8 v61;
  frMsgInfo_t_o *v62;
  frMsgInfo_t_o *v65;
  s8 Style;
  _FRQ_o *pFRQ;
  s8 v68;
  _FRQ_o *Name1NFRQ;
  struct _FRQ_o *prev;
  struct _TEXT_o *i;
  struct _FRQ_o *v74;
  s64 v75;
  struct System_Byte_array *v76;
  s8 v78;
  frMsgInfo_t_o *v79;
  frMsgInfo_t_o *v82;
  s8 v83;
  _FRQ_o *v84;
  struct _FRQ_o *v86;
  struct _TEXT_o *j;
  s64 v88;
  struct System_Byte_array *v89;
  s8 v91;
  frMsgInfo_t_o *v92;
  frMsgInfo_t_o *v95;
  s8 v96;
  _FRQ_o *v97;
  struct _FRQ_o *v99;
  struct _TEXT_o *k;
  u32 v101;
  struct System_Byte_array *v102;
  frMsgInfo_t_o *v104;
  frMsgInfo_t_o *v107;
  s8 v108;
  s8 v109;
  _FRQ_o *v110;
  struct _FRQ_o *v113;
  struct _TEXT_o *m;
  struct _FRQ_o *v115;
  frMsgInfo_t_o *v117;
  s32 Y;
  s32 gMessageStepY;
  s32 v122;
  s8 gMessageSpaceX;
  s64 v127;
  s32 v128;
  s32 v129;
  s8 v131;
  s64 v132;
  s32 v133;
  s8 v135;
  s64 v136;
  s32 v137;
  s8 v138;
  s64 v139;
  s32 v140;
  s32 v141;
  u32 Spd;
  u8 v143;

  v5 = *mi;
  Ofs = (*mi)->Ofs;
  pMsg = (*mi)->pMsg;
  v5->Ofs = Ofs + 1;
  ColNo = v5->ColNo;
  v10 = pMsg->m_Items[Ofs] | (code << 8);
  switch (v10)
  {
    case 61954:
      v11 = *mi;
      v12 = (*mi)->Ofs;
      v13 = (*mi)->pMsg;
      (*mi)->Ofs = v12 + 1;
      v11->ColNo = v13->m_Items[v12] - 1;
      goto LABEL_54;
    case 61955:
      v19 = (*mi)->pMsg;
      v20 = (*mi)->Ofs;
      v22 = v19->m_Items[v20] - 1LL;
      if (gVarStr->m_Items[v22])
      {
        v24 = *mi;
        frCreateNewHandle(v24, mi);
        v26 = gVarStr;
        v27 = (*mi)->pMsg;
        v28 = (*mi)->Ofs;
        v30 = v27->m_Items[v28] - 1LL;
        v33 = v26->m_Items[v30];
        _9__43_0 = __9__43_0;
        v36 = "[0-9]";
        if (!_9__43_0)
        {
          v37 = __9;
          _9__43_0 = Allocate(System_Text_RegularExpressions_MatchEvaluator);
          _ctor(
            _9__43_0,
            v37,
            Method_frFont___c__frAnalyzeTag_b__43_0__,
            0);
          __9__43_0 = _9__43_0;
        }
        {
        }
        v40 = Replace_4089328(v33, v36, _9__43_0);
        v41 = *mi;
        frCreateVariableRequest(v40, v41);
      }
      v42 = *mi;
      v43 = (*mi)->Ofs + 2;
      goto LABEL_55;
    case 61956:
    case 61957:
    case 61960:
LABEL_120:
      v42 = *mi;
      v43 = 2 * (code & 0xF) + (*mi)->Ofs - 2;
      goto LABEL_55;
    case 61958:
      v44 = *mi;
      v45 = (*mi)->Ofs;
      v46 = (*mi)->pMsg;
      (*mi)->Ofs = v45 + 1;
      v44->Style = v46->m_Items[v45] - 1;
      goto LABEL_54;
    case 61959:
      v48 = *mi;
      v49 = (*mi)->Ofs;
      v50 = (*mi)->pMsg;
      (*mi)->Ofs = v49 + 1;
      v48->Spd = v50->m_Items[v49] - 1;
      goto LABEL_54;
    case 61961:
      v52 = *mi;
      v53 = (*mi)->Ofs;
      v54 = (*mi)->pMsg;
      (*mi)->Ofs = v53 + 1;
      v52->Tp = v54->m_Items[v53] - 1;
      goto LABEL_54;
    case 61962:
      v58 = (*mi)->Ofs;
      v59 = (*mi)->pMsg;
      (*mi)->Ofs = v58 + 1;
      v61 = v59->m_Items[v58];
      ++(*mi)->Ofs;
      v62 = *mi;
      frCreateNewHandle(v62, mi);
      v65 = *mi;
      Style = (*mi)->Style;
      pFRQ = (*mi)->pFRQ;
      v68 = v61 - 1;
      Name1NFRQ = frGetName1NFRQ(v68, Style, pFRQ);
      Name1NFRQ->w_pxls += 8;
      Name1NFRQ->str_end->lw += 8;
      v65->pFRQ = frGetName2NFRQ(v68, Style, Name1NFRQ);
      prev = (*mi)->pFRQ;
      if (prev)
      {
        do
        {
          for (i = prev->str; i; i = i->next)
            i->col_no = ColNo;
          prev = prev->prev;
        }
        while (prev);
        v74 = (*mi)->pFRQ;
      }
      else
      {
        v74 = 0;
      }
      *(&xmmword_10 + v74 + 1) = gMessageSpaceX;
      v127 = *(init_proc + v74);
      if (!v127)
        goto LABEL_187;
      v128 = 0;
      do
      {
        v129 = *(v127 + 28);
        v127 = *(v127 + 80);
        v128 += *(&xmmword_10 + v74 + 1) + v129;
      }
      while (v127);
      goto LABEL_185;
    case 61963:
      v75 = (*mi)->Ofs;
      v76 = (*mi)->pMsg;
      (*mi)->Ofs = v75 + 1;
      v78 = v76->m_Items[v75] - 1;
      ++(*mi)->Ofs;
      v79 = *mi;
      frCreateNewHandle(v79, mi);
      v82 = *mi;
      v83 = (*mi)->Style;
      v84 = (*mi)->pFRQ;
      v82->pFRQ = frGetName1NFRQ(v78, v83, v84);
      v86 = (*mi)->pFRQ;
      if (v86)
      {
        do
        {
          for (j = v86->str; j; j = j->next)
            j->col_no = ColNo;
          v86 = v86->prev;
        }
        while (v86);
        v74 = (*mi)->pFRQ;
      }
      else
      {
        v74 = 0;
      }
      v131 = gMessageSpaceX;
      *(&xmmword_10 + v74 + 1) = v131;
      v132 = *(init_proc + v74);
      if (!v132)
        goto LABEL_187;
      v128 = 0;
      do
      {
        v133 = *(v132 + 28);
        v132 = *(v132 + 80);
        v128 += *(&xmmword_10 + v74 + 1) + v133;
      }
      while (v132);
      goto LABEL_185;
    case 61964:
      v88 = (*mi)->Ofs;
      v89 = (*mi)->pMsg;
      (*mi)->Ofs = v88 + 1;
      v91 = v89->m_Items[v88] - 1;
      ++(*mi)->Ofs;
      v92 = *mi;
      frCreateNewHandle(v92, mi);
      v95 = *mi;
      v96 = (*mi)->Style;
      v97 = (*mi)->pFRQ;
      v95->pFRQ = frGetName2NFRQ(v91, v96, v97);
      v99 = (*mi)->pFRQ;
      if (v99)
      {
        do
        {
          for (k = v99->str; k; k = k->next)
            k->col_no = ColNo;
          v99 = v99->prev;
        }
        while (v99);
        v74 = (*mi)->pFRQ;
      }
      else
      {
        v74 = 0;
      }
      v135 = gMessageSpaceX;
      *(&xmmword_10 + v74 + 1) = v135;
      v136 = *(init_proc + v74);
      if (v136)
      {
        v128 = 0;
        do
        {
          v137 = *(v136 + 28);
          v136 = *(v136 + 80);
          v128 += *(&xmmword_10 + v74 + 1) + v137;
        }
        while (v136);
LABEL_185:
        *(&qword_20 + v74) = v128;
        v56 = *mi;
        if (!(*mi)->FrqFlag)
          goto LABEL_186;
        return 0;
      }
LABEL_187:
      *(&qword_20 + v74) = 0;
      v56 = *mi;
      if ((*mi)->FrqFlag)
        return 0;
LABEL_186:
      v56->FrqFlag = 1;
      return 0;
    case 61965:
      v101 = (*mi)->Ofs;
      v102 = (*mi)->pMsg;
      (*mi)->Ofs = v101 + 1;
      ++(*mi)->Ofs;
      v104 = *mi;
      frCreateNewHandle(v104, mi);
      v107 = *mi;
      v108 = (*mi)->Style;
      v110 = (*mi)->pFRQ;
      v107->pFRQ = frGetCNameFRQ(v109, v108, v110);
      gModeFlag |= 1u;
      v113 = (*mi)->pFRQ;
      if (v113)
      {
        do
        {
          for (m = v113->str; m; m = m->next)
            m->col_no = ColNo;
          v113 = v113->prev;
        }
        while (v113);
        v115 = (*mi)->pFRQ;
      }
      else
      {
        v115 = 0;
      }
      v138 = gMessageSpaceX;
      *(&xmmword_10 + v115 + 1) = v138;
      v139 = *(init_proc + v115);
      if (v139)
      {
        v140 = 0;
        do
        {
          v141 = *(v139 + 28);
          v139 = *(v139 + 80);
          v140 += *(&xmmword_10 + v115 + 1) + v141;
        }
        while (v139);
      }
      else
      {
        v140 = 0;
      }
      *(&qword_20 + v115) = v140;
      Spd = (*mi)->Spd;
      if (Spd >= 0x41)
        v143 = 0x80;
      else
        v143 = 2 * Spd;
      (*mi)->pFRQ->draw_spd = v143;
      v56 = *mi;
      if (!(*mi)->FrqFlag)
        goto LABEL_186;
      return 0;
    case 61966:
LABEL_54:
      v42 = *mi;
      v43 = (*mi)->Ofs + 1;
LABEL_55:
      v42->Ofs = v43;
LABEL_56:
      v56 = *mi;
      if ((*mi)->FrqFlag)
        return 0;
      goto LABEL_186;
    default:
      switch (v10)
      {
        case 61700:
          goto LABEL_149;
        case 61711:
          if ((gModeFlag & 4) != 0)
            goto LABEL_56;
          v117 = *mi;
          Y = v117->Y;
          v117->Y = CMP_YM(gMessageStepY) + Y;
          *&v117->FrqFlag = 257;
          v56 = *mi;
          if (!(*mi)->FrqFlag)
            goto LABEL_186;
          return 0;
        case 61712:
          v122 = gMessageRequestResult | 2;
          goto LABEL_150;
        case 61713:
          if ((gModeFlag & 8) == 0)
            goto LABEL_56;
LABEL_149:
          v122 = gMessageRequestResult | 1;
LABEL_150:
          gMessageRequestResult = v122;
          result = 1;
          break;
        case 61714:
          gMessageRequestResult |= 4u;
          v56 = *mi;
          if (!(*mi)->FrqFlag)
            goto LABEL_186;
          return 0;
        default:
          goto LABEL_120;
      }
      return result;
  }
}

// 0x139c420
s8 frAnalyzeTagLocalize1(s32 code, frMsgInfo_t **mi, char **message, void *index) {
  s64 Ofs;
  struct System_Byte_array *pMsg;
  s32 v12;
  s64 v13;
  struct System_Byte_array *v14;
  System_String_o *v15;
  u64 *v17;
  s64 *v18;
  System_String_o *v19;
  System_Object_array *v20;
  System_String_o *v21;
  System_String_o *v22;
  struct System_String_array *gVarStr;
  struct System_Byte_array *v25;
  s64 v26;
  s64 v28;
  struct System_String_array *v31;
  struct System_Byte_array *v32;
  s64 v33;
  s64 v35;
  System_String_o *v38;
  u64 *_9__38_0;
  System_String_o *v41;
  Il2CppObject *v42;
  System_String_o *v43;
  frMsgInfo_t_o *v44;
  s32 v45;
  s64 v46;
  struct System_Byte_array *v47;
  s64 v49;
  struct System_Byte_array *v50;
  s64 v52;
  struct System_Byte_array *v53;
  System_String_o *CNameString;
  s64 v56;
  struct System_Byte_array *v57;
  u8 v59;
  s8 v60;
  System_String_o *Name1NString;
  System_String_o *Name2NString;
  s64 v64;
  struct System_Byte_array *v65;
  s8 v67;
  s64 v68;
  struct System_Byte_array *v69;
  s8 v71;
  s64 v72;
  struct System_Byte_array *v73;
  s8 v75;
  frMsgInfo_t_o *v76;
  System_String_o *v78;
  s64 *v79;
  s64 *v80;
  u8 v82[4];
  u8 v83[4];
  u8 v84[4];
  u8 v85[4];

  Ofs = (*mi)->Ofs;
  pMsg = (*mi)->pMsg;
  (*mi)->Ofs = Ofs + 1;
  v12 = pMsg->m_Items[Ofs] | (code << 8);
  switch (v12)
  {
    case 61954:
      _Add(index, -1);
      v13 = (*mi)->Ofs;
      v14 = (*mi)->pMsg;
      v15 = *message;
      (*mi)->Ofs = v13 + 1;
      v84[0] = v14->m_Items[v13];
      v17 = sub_8D3950(qword_3F088F8, v84);
      v18 = &"<COLOR {0}>";
      goto LABEL_48;
    case 61955:
      v25 = (*mi)->pMsg;
      v26 = (*mi)->Ofs;
      v28 = v25->m_Items[v26] - 1LL;
      if (gVarStr->m_Items[v28])
      {
        v31 = gVarStr;
        v32 = (*mi)->pMsg;
        v33 = (*mi)->Ofs;
        v35 = v32->m_Items[v33] - 1LL;
        v38 = v31->m_Items[v35];
        _9__38_0 = __9__38_0;
        v41 = "[0-9]";
        if (!_9__38_0)
        {
          v42 = __9;
          _9__38_0 = Allocate(System_Text_RegularExpressions_MatchEvaluator);
          _ctor(
            _9__38_0,
            v42,
            Method_frFont___c__frAnalyzeTagLocalize1_b__38_0__,
            0);
          __9__38_0 = _9__38_0;
        }
        {
        }
        v43 = Replace_4089328(v38, v41, _9__38_0);
        *message = Concat_5224608(*message, v43);
      }
      v44 = *mi;
      v45 = (*mi)->Ofs + 2;
      goto LABEL_80;
    case 61956:
    case 61957:
    case 61960:
LABEL_83:
      v44 = *mi;
      v45 = 2 * (code & 0xF) + (*mi)->Ofs - 2;
      goto LABEL_80;
    case 61958:
      _Add(index, -1);
      v46 = (*mi)->Ofs;
      v47 = (*mi)->pMsg;
      v15 = *message;
      (*mi)->Ofs = v46 + 1;
      v85[0] = v47->m_Items[v46];
      v17 = sub_8D3950(qword_3F088F8, v85);
      v18 = &"<FONT {0}>";
      goto LABEL_48;
    case 61959:
      _Add(index, -1);
      v49 = (*mi)->Ofs;
      v50 = (*mi)->pMsg;
      v15 = *message;
      (*mi)->Ofs = v49 + 1;
      v82[0] = v50->m_Items[v49];
      v17 = sub_8D3950(qword_3F088F8, v82);
      v18 = &"<SPD {0}>";
      goto LABEL_48;
    case 61961:
      _Add(index, -1);
      v52 = (*mi)->Ofs;
      v53 = (*mi)->pMsg;
      v15 = *message;
      (*mi)->Ofs = v52 + 1;
      v83[0] = v53->m_Items[v52];
      v17 = sub_8D3950(qword_3F088F8, v83);
      v18 = &"<TP {0}>";
LABEL_48:
      CNameString = Format(*v18, v17, 0);
      goto LABEL_78;
    case 61962:
      v56 = (*mi)->Ofs;
      v57 = (*mi)->pMsg;
      (*mi)->Ofs = v56 + 1;
      v59 = v57->m_Items[v56];
      v15 = *message;
      v60 = v59 - 1;
      Name1NString = frGetName1NString(v60, mi);
      Name2NString = frGetName2NString(v60);
      CNameString = Concat_5221536(Name1NString, " ", Name2NString);
      goto LABEL_78;
    case 61963:
      v64 = (*mi)->Ofs;
      v65 = (*mi)->pMsg;
      (*mi)->Ofs = v64 + 1;
      v67 = v65->m_Items[v64] - 1;
      v15 = *message;
      CNameString = frGetName1NString(v67, mi);
      goto LABEL_78;
    case 61964:
      v68 = (*mi)->Ofs;
      v69 = (*mi)->pMsg;
      (*mi)->Ofs = v68 + 1;
      v71 = v69->m_Items[v68] - 1;
      v15 = *message;
      CNameString = frGetName2NString(v71, mi);
      goto LABEL_78;
    case 61965:
      v72 = (*mi)->Ofs;
      v73 = (*mi)->pMsg;
      (*mi)->Ofs = v72 + 1;
      v75 = v73->m_Items[v72] - 1;
      v15 = *message;
      CNameString = frGetCNameString(v75, mi);
LABEL_78:
      *message = Concat_5224608(v15, CNameString);
      break;
    case 61966:
      break;
    default:
      switch (v12)
      {
        case 61700:
          _Add(index, -1);
          v19 = *message;
          v20 = Empty_string_();
          v21 = Format_5268784("<WAIT>", v20);
          v22 = v19;
          goto LABEL_92;
        case 61711:
          _Add(index, -1);
          v78 = *message;
          v79 = &"<RET>";
          goto LABEL_94;
        case 61712:
          _Add(index, -1);
          v22 = *message;
          v80 = &"<NWAIT>";
          goto LABEL_91;
        case 61713:
          if ((gModeFlag & 8) == 0)
            goto LABEL_81;
          _Add(index, -1);
          v22 = *message;
          v80 = &"\n";
LABEL_91:
          v21 = *v80;
LABEL_92:
          *message = Concat_5224608(v22, v21);
          return 1;
        case 61714:
          _Add(index, -1);
          v78 = *message;
          v79 = &"<KUTI>";
LABEL_94:
          *message = Concat_5224608(v78, *v79);
          v76 = *mi;
          if (!(*mi)->FrqFlag)
            goto LABEL_95;
          return 0;
        default:
          goto LABEL_83;
      }
  }
  v44 = *mi;
  v45 = (*mi)->Ofs + 1;
LABEL_80:
  v44->Ofs = v45;
LABEL_81:
  v76 = *mi;
  if ((*mi)->FrqFlag)
    return 0;
LABEL_95:
  v76->FrqFlag = 1;
  return 0;
}

// 0x139d660
s8 frAnalyzeTagLocalize2(char *message, s32 *index, frMsgInfo_t **mi) {
  s32 v7;
  s32 v8;
  s32 v9;
  System_String_o *v10;
  System_String_o *v11;
  s64 *v12;
  u32 v13;
  frMsgInfo_t_o *v14;
  s8 v15;
  s32 v21;
  frMsgInfo_t_o *v24;
  s32 Y;
  s32 gMessageStepY;
  u8 v30;
  s32 result;

  result = -1;
  v7 = IndexOf_5259744(message, 0x3Eu, *index);
  if (v7 == -1)
    return 0;
  v8 = v7;
  v9 = v7 - *index - 3;
  if (v9 < 0)
    return 0;
  v10 = Substring_5248048(message, *index + 3, v9);
  v11 = Substring_5248048(message, *index, 3);
  if (IsNullOrEmpty(v10))
    goto LABEL_8;
  if (!TryParse(v10, &result, 0))
    return 0;
  if (result == -1)
  {
LABEL_8:
    if (op_Equality(v11, "<FO", 0)
      || op_Equality(v11, "<CO", 0)
      || op_Equality(v11, "<TP", 0))
    {
      return 0;
    }
    v12 = &"<SP";
  }
  else
  {
    if (op_Equality(v11, "<WA", 0)
      || op_Equality(v11, "<RE", 0)
      || op_Equality(v11, "<NW", 0)
      || op_Equality(v11, "<AD", 0))
    {
      return 0;
    }
    v12 = &"<KU";
  }
  if (op_Equality(v11, *v12, 0))
    return 0;
  *index = v8 + 1;
  v13 = _ComputeStringHash_16596480(v11);
  if (v13 <= 0x26EBE33E)
  {
    if (v13 <= 0x1DF423D8)
    {
      if (v13 != 399063391)
      {
        if (v13 == 502539224 && op_Equality(v11, "<FO", 0))
        {
          (*mi)->Style = result - 1;
          v14 = *mi;
          v15 = 1;
          if ((*mi)->FrqFlag)
            return v15;
          goto LABEL_89;
        }
        return 0;
      }
      if (op_Equality(v11, "<WA", 0))
      {
LABEL_52:
        v21 = gMessageRequestResult | 1;
LABEL_87:
        gMessageRequestResult = v21;
        goto LABEL_88;
      }
      return 0;
    }
    if (v13 == 601086367)
    {
      if (op_Equality(v11, "<KU", 0))
      {
        v21 = gMessageRequestResult | 4;
        goto LABEL_87;
      }
      return 0;
    }
    if (v13 != 652993342 || !op_Equality(v11, "<AD", 0))
      return 0;
    if ((gModeFlag & 8) != 0)
    {
      goto LABEL_52;
    }
LABEL_88:
    v14 = *mi;
    v15 = 1;
    if ((*mi)->FrqFlag)
      return v15;
    goto LABEL_89;
  }
  if (v13 > 0x5DE7BCA5)
  {
    if (v13 != 1858024696)
    {
      if (v13 == 1977586600)
      {
        if (op_Equality(v11, "<NW", 0))
        {
          v21 = gMessageRequestResult | 2;
          goto LABEL_87;
        }
      }
      else if (v13 == 2026933719 && op_Equality(v11, "<TP", 0))
      {
        (*mi)->Tp = result;
        v14 = *mi;
        v15 = 1;
        if ((*mi)->FrqFlag)
          return v15;
        goto LABEL_89;
      }
      return 0;
    }
    if (!op_Equality(v11, "<SP", 0))
      return 0;
    if (result == 129)
      v30 = 0x80;
    else
      v30 = 4 * result - 4;
    (*mi)->Spd = v30;
    ++(*mi)->Ofs;
    v14 = *mi;
    v15 = 1;
    if (!(*mi)->FrqFlag)
      goto LABEL_89;
    return v15;
  }
  if (v13 != 667064010)
  {
    if (v13 == 1575468197 && op_Equality(v11, "<CO", 0))
    {
      (*mi)->ColNo = result;
      v14 = *mi;
      v15 = 1;
      if ((*mi)->FrqFlag)
        return v15;
      goto LABEL_89;
    }
    return 0;
  }
  if (!op_Equality(v11, "<RE", 0))
    return 0;
  if ((gModeFlag & 4) != 0)
    goto LABEL_88;
  v24 = *mi;
  Y = v24->Y;
  v24->Y = CMP_YM(gMessageStepY) + Y;
  *&v24->FrqFlag = 257;
  v14 = *mi;
  v15 = 1;
  if (!(*mi)->FrqFlag)
LABEL_89:
    v14->FrqFlag = 1;
  return v15;
}

// 0x1399540
void frClearTexBuf(void) {
  ;
}

// 0x13a0600
_FRQ *frCombineFontRequest(_FRQ *pFRQ1, _FRQ *pFRQ2) {
  _FRQ_o *v3;
  struct _FRQ_o *head;

  v3 = pFRQ2;
  if (pFRQ1)
  {
    if (v3)
    {
      pFRQ1->next = v3->head;
      head = v3->head;
      if (pFRQ1->str)
        head->prev = pFRQ1;
      else
        head->prev = pFRQ1->prev;
      v3->head = pFRQ1->head;
      v3->x = pFRQ1->x + 16 * pFRQ1->w_pxls;
      v3->y = pFRQ1->y;
    }
    else
    {
      return pFRQ1;
    }
  }
  return v3;
}

// 0x139fd30
_FRQ *frCombineFontRequestEx(_FRQ *pFRQ1, _FRQ *pFRQ2, u32 Mode) {
  struct _FRQ_o *head;

  if (!pFRQ1)
    return pFRQ2;
  if (pFRQ2)
  {
    pFRQ1->next = pFRQ2->head;
    head = pFRQ2->head;
    if (pFRQ1->str)
    {
      head->prev = pFRQ1;
      pFRQ2->head = pFRQ1->head;
      if (Mode != 1)
        return pFRQ2;
    }
    else
    {
      head->prev = pFRQ1->prev;
      pFRQ2->head = pFRQ1->head;
      if (Mode != 1)
        return pFRQ2;
    }
    pFRQ2->x = pFRQ1->x + 16 * pFRQ1->w_pxls;
    pFRQ2->y = pFRQ1->y;
    return pFRQ2;
  }
  return pFRQ1;
}

// 0x13994f0
u8 frConvertVal2N(u32 Val) {
  u32 v2;

  v2 = __clz(Val) ^ 0x1F;
  if (Val)
    return v2;
  else
    return 0;
}

// 0x1399530
void frCopyFontClutToVram(u32 GS_LocalAddr, u32 pClut) {
  ;
}

// 0x13994d0
void frCreateDrawEnvPacket(frDrawEnvPkt_t *pDrawEnvPkt) {
  ;
}

// 0x13993f0
void frCreateDrawFontPacket(s32 x, s32 y, _FRQ *frq, _TEXT *text) {
  System_String_o *DrawBuffer;
  System_String_o *v9;

  v9 = ConvertChar(txtMgr, text->code);
  DrawBuffer = Concat_5224608(DrawBuffer, v9);
}

// 0x13994c0
void frCreateDrawFontPacket_20550848(s32 X, s32 Y, s32 Width, s32 Height, u8 ClutNo, u32 Col, u32 Pri, s32 Filter, s32 **pUv, frGsTex_t *pGsTex, u32 Ot) {
  ;
}

// 0x139ba90
void frCreateNewHandle(frMsgInfo_t *pMsgInfo) {
  struct _FRQ_o *pFRQ;
  s8 ColNo;
  s8 Tp;
  System_String_o *v6;
  System_Byte_array *v9;
  _FRQ_o *v10;
  u32 Spd;
  char v12;
  struct _FRQ_o *v13;
  s32 Y;
  s32 X;

  pFRQ = pMsgInfo->pFRQ;
  if (pFRQ && !pFRQ->str)
    pMsgInfo->FrqFlag = 0;
  if (pMsgInfo->FrqFlag)
  {
    ColNo = pMsgInfo->ColNo;
    Tp = pMsgInfo->Tp;
    v6 = "";
    v9 = EncodingSJIS(v6);
    v10 = frLinkFontString_20580272(v9, 0, ColNo, Tp, pFRQ);
    Spd = pMsgInfo->Spd;
    if (Spd >= 0x41)
      v12 = 0x80;
    else
      v12 = 2 * Spd;
    pMsgInfo->pFRQ = v10;
    v10->draw_spd = v12;
    pMsgInfo->FrqFlag = 0;
  }
  if (pMsgInfo->RetFlag)
  {
    v13 = pMsgInfo->pFRQ;
    X = pMsgInfo->X;
    Y = pMsgInfo->Y;
    v13->x = X;
    v13->y = Y;
    pMsgInfo->RetFlag = 0;
  }
}

// 0x139f120
void frCreateUserFontPacket(s32 X, s32 Y, u32 Z, _TEXT *pText, u32 Ot) {
  ;
}

// 0x1399c80
void frCreateVariableRequest(char *VarNo, frMsgInfo_t *pMsgInfo) {
  u64 *v5;
  u8 Style;
  System_Byte_array *v9;
  System_Byte_array *v12;
  u64 v13;
  s64 v17;
  s32 v18;
  struct _FRQ_o *v19;
  u8 v20;
  u8 v21;
  System_String_o *v22;
  System_Byte_array *v25;
  System_Byte_array *v26;
  s8 v27;
  s8 v28;
  _FRQ_o *v29;
  s64 v32;
  u8 v33;
  System_String_o *v34;
  System_Byte_array *v36;
  u32 Spd;
  char v38;
  s8 ColNo;
  s8 Tp;
  _FRQ_o *pFRQ;
  struct _FRQ_o *v42;
  struct _FRQ_o *v43;
  s8 gMessageSpaceX;
  struct _TEXT_o *str;
  s32 v47;
  s32 lw;
  il2cpp_array_size_t max_length;

  v5 = NewSpecific(byte, 3u);
  if (!IsNullOrEmpty(VarNo))
  {
    Style = pMsgInfo->Style;
    v9 = UnicodeToIndexByte(txtMgr, VarNo);
    max_length = v9->max_length;
    if (max_length >= 1)
    {
      v12 = v9;
      v13 = 0;
      while (1)
      {
        *(v5 + 32) = v12->m_Items[v13];
        v17 = v5[3];
        *(v5 + 33) = v12->m_Items[v13 | 1];
        *(v5 + 34) = 0;
        v18 = pMsgInfo->Style;
        if (v18 != Style)
          break;
LABEL_47:
        ColNo = pMsgInfo->ColNo;
        Tp = pMsgInfo->Tp;
        pFRQ = pMsgInfo->pFRQ;
        v42 = frSetFontString_20554176(v5, v18, ColNo, Tp, pFRQ);
        pMsgInfo->pFRQ = v42;
        v43 = v42;
        v43->space = gMessageSpaceX;
        else
        {
          str = v43->str;
          if (!str)
            goto LABEL_59;
        }
        v47 = 0;
        do
        {
          lw = str->lw;
          str = str->next;
          v47 += v43->space + lw;
        }
        while (str);
LABEL_60:
        v43->w_pxls = v47;
        v13 += 2LL;
        if (v13 >= max_length)
          return;
      }
      v19 = pMsgInfo->pFRQ;
      if (v19)
      {
        if (!v19->str)
          goto LABEL_41;
        v20 = pMsgInfo->ColNo;
        v21 = pMsgInfo->Tp;
        v22 = "";
        v25 = EncodingSJIS(v22);
        v26 = v25;
        v27 = v20;
        v28 = v21;
        v29 = v19;
      }
      else
      {
        v32 = pMsgInfo->ColNo;
        v33 = pMsgInfo->Tp;
        v34 = "";
        v36 = EncodingSJIS(v34);
        v26 = v36;
        v27 = v32;
        v28 = v33;
        v29 = 0;
      }
      v19 = frLinkFontString_20580272(v26, 0, v27, v28, v29);
      pMsgInfo->pFRQ = v19;
LABEL_41:
      Spd = pMsgInfo->Spd;
      v38 = 2 * Spd;
      if (Spd >= 0x41)
        v38 = 0x80;
      Style = v18;
      v19->draw_spd = v38;
      goto LABEL_47;
    }
  }
}

// 0x13a0740
void *frDecodeFontImage(u8 Style, s32 FontNo) {
  u64 *v3;

  v3 = Allocate(hmDecodeTbl_t);
  _ctor(v3, 0);
  return 0;
}

// 0x139fa00
void frDelFontStyle(u8 StyleNo) {
  ;
}

// 0x1399520
void frDelStyleAll(void) {
  ;
}

// 0x13a1130
void frDestroyExtDic(void) {

}

// 0x139fb20
_FRQ *frDestroyFontRequest(_FRQ *pFRQ) {
  frFont_c *v3;

  {
          v3 = frFont,
    {
    }
  }
  frDestroyFontRequestNow(pFRQ);
  return 0;
}

// 0x139fbc0
_FRQ *frDestroyFontRequestAfter(_FRQ *pFRQ) {
  u32 FrameID;
  struct _FRQ_array *DestroyHandleList;
  Il2CppClass **v8;
  _FRQ_o *v9;
  _FRQ_o **v10;
  _FRQ_o *v11;
  struct _FRQ_o *head;

  FrameID = dds3GetFrameID();
  DestroyHandleList = gFT->DestroyHandleList;
  v8 = &DestroyHandleList->obj.klass + FrameID;
  v11 = v8[4];
  v10 = (v8 + 4);
  v9 = v11;
  if (v11)
  {
    if (pFRQ)
    {
      v9->next = pFRQ->head;
      head = pFRQ->head;
      if (v9->str)
        head->prev = v9;
      else
        head->prev = v9->prev;
      pFRQ->head = v9->head;
    }
    else
    {
      pFRQ = v9;
    }
  }
  else if (!pFRQ)
  {
    goto LABEL_21;
  }
LABEL_21:
  *v10 = pFRQ;
  return 0;
}

// 0x139f860
_FRQ *frDestroyFontRequestNow(_FRQ *pFRQ) {
  struct _TEXT_o *str;
  _FRQ_o *v4;
  _TEXT_o *v5;
  frFont_c *v7;

  if (!pFRQ)
    return 0;
  do
  {
    str = pFRQ->str;
    v4 = pFRQ;
    if (!str)
    {
      pFRQ = pFRQ->prev;
        goto LABEL_16;
      goto LABEL_19;
    }
    do
    {
      v5 = str;
      str = str->next;

      {
        v5->user_font = 0;
      }
        goto LABEL_14;
LABEL_12:
LABEL_14:
      rbRetToRingBuf__TEXT_(0, v5, gFT->pTextRing);
      --gFT->TextHandleNums;
    }
    while (str);
    pFRQ = v4->prev;
    if ((v7->_2.bitflags2 & 2) != 0)
    {
LABEL_16:
    }
LABEL_19:
    rbRetToRingBuf__TEXT_(1, v4, gFT->pRequestRing);
    --gFT->FontHandleNums;
  }
  while (pFRQ);
  return 0;
}

// 0x139f730
void *frDestroyFontTable(dds3ProcessID_t *id) {
  struct _FRQ_array *DestroyHandleList;
  struct _FRQ_array *v7;

  Log("DestroyFontTable", 0);
  DestroyHandleList = gFT->DestroyHandleList;
  frDestroyFontRequestNow(DestroyHandleList->m_Items[0]);
  v7 = gFT->DestroyHandleList;
  frDestroyFontRequestNow(v7->m_Items[1]);
  rbDestroyRingBuf(0, gFT->pTextRing);
  rbDestroyRingBuf(1, gFT->pRequestRing);
  return 0;
}

// 0x139ac80
u8 frDisableMode(s8 Flag) {
  u8 result;

  result = gModeFlag;
  gModeFlag = result & ~Flag;
  return result;
}

// 0x1399b60
s32 frDrawEffect(_FRQ *pFRQ, _TEXT *pText, u8 AlphaDelay, u8 DrawSpeed) {
  struct _TEXT_o *prev;
  u32 color;
  struct _FRQ_o *v7;
  struct _TEXT_o *str_end;
  s32 tp;
  u32 v10;
  u32 *p_color;
  u32 v13;
  u32 v14;

  prev = pText->prev;
  if (prev)
  {
    color = prev->color;
LABEL_13:
    p_color = &pText->color;
    v10 = pText->color;
    goto LABEL_14;
  }
  v7 = pFRQ->prev;
  if (!v7 || (str_end = v7->str_end) == 0)
  {
    LOBYTE(color) = 0x80;
    goto LABEL_13;
  }
  color = str_end->color;
  tp = str_end->tp;
  p_color = &pText->color;
  v10 = pText->color;
  if (tp && tp != pText->tp)
  {
    if (color == 128)
      goto LABEL_15;
    goto LABEL_8;
  }
LABEL_14:
  if (color >= AlphaDelay)
  {
LABEL_15:
    if ((DrawSpeed & 0x80000000) == 0)
      *&DrawSpeed = (DrawSpeed << 6) / (pText->lw + pFRQ->space);
    if (128 - v10 >= DrawSpeed)
    {
      v14 = v10 + DrawSpeed;
      *p_color = v14;
      if ((v14 & 0x80) != 0)
        return 0;
    }
    else
    {
      v13 = v10 & 0xFFFFFF00 | 0x80;
      *p_color = v13;
      if ((v13 & 0x80) != 0)
        return 0;
    }
    goto LABEL_9;
  }
LABEL_8:
  if ((v10 & 0x80) != 0)
    return 0;
LABEL_9:
  if (pText->tp == 1)
    return 32 - 16 * (2 * pText->draw_count % 5);
  else
    return 0;
}

// 0x13a0b80
s32 frDrawFont(_FRQ *pFRQ) {
  u32 v2;

LABEL_7:
  return frDrawFontEx2(pFRQ, 0, v2);
}

// 0x13a0c40
s32 frDrawFontEx(_FRQ *pFRQ, s8 Mode) {
  return frDrawFontEx2(pFRQ, Mode);
}

// 0x13a0cc0
s32 frDrawFontEx2(_FRQ *pFRQ, s8 Mode, u32 Ot) {
  struct _FRQ_o *head;
  s32 v8;
  s32 v9;
  s32 x;
  s32 y;
  _TEXT_o *str;
  u32 col_no;
  s32 draw_spd;
  struct _TEXT_o *prev;
  u32 color;
  struct _FRQ_o *v18;
  struct _TEXT_o *str_end;
  s32 tp;
  u32 *p_color;
  u32 v22;
  s32 v23;
  u32 v24;
  char v25;
  struct _TEXT_o *v26;
  u32 v27;

  if (!pFRQ)
    return 0;
  head = pFRQ->head;
  if (!head)
    return 0;
  v8 = 0;
  v9 = 1;
  do
  {
    x = head->x;
    y = head->y;
    str = head->str;
    DrawBuffer = "";
    if (str)
    {
      col_no = str->col_no;
      else
      {
        DrawColor = col_no;
        if (Mode)
          goto LABEL_35;
      }
      draw_spd = head->draw_spd;
      else
      {
        prev = str->prev;
        if (prev)
        {
LABEL_16:
          color = prev->color;
          goto LABEL_27;
        }
      }
      v18 = head->prev;
      if (v18)
      {
        str_end = v18->str_end;
        if (str_end)
        {
          color = str_end->color;
          tp = str_end->tp;
          p_color = &str->color;
          v22 = str->color;
          if (tp && tp != str->tp)
          {
            if (color != 128)
              goto LABEL_35;
LABEL_29:
            LOBYTE(v23) = draw_spd;
            if ((draw_spd & 0x80000000) == 0)
              v23 = (draw_spd << 6) / (str->lw + head->space);
            if (128 - v22 >= v23)
              v24 = v22 + v23;
            else
              v24 = v22 & 0xFFFFFF00 | 0x80;
            *p_color = v24;
LABEL_35:
            while (str->user_font)
            {
              v25 = str->color;
              if (v25)
                goto LABEL_37;
LABEL_38:
              str = str->next;
              v9 &= v25 >> 7;
              if (!str)
              {
                goto LABEL_62;
              }
              if (!Mode)
              {
                draw_spd = head->draw_spd;
                else
                {
                  v26 = str->prev;
                  if (!v26)
                    goto LABEL_51;
LABEL_43:
                  v27 = v26->color;
LABEL_58:
                  p_color = &str->color;
                  v22 = str->color;
LABEL_59:
                  if (v27 >= 0x1Cu)
                    goto LABEL_29;
                }
              }
            }
            else
            {
              frCreateDrawFontPacket(frFont, Mode, *&Ot, str);
              v25 = str->color;
              if (!v25)
                goto LABEL_38;
            }
LABEL_37:
            ++str->draw_count;
            goto LABEL_38;
          }
LABEL_28:
          if (color < 0x1Cu)
            goto LABEL_35;
          goto LABEL_29;
        }
      }
      LOBYTE(color) = 0x80;
LABEL_27:
      p_color = &str->color;
      v22 = str->color;
      goto LABEL_28;
    }
LABEL_62:
    v8 += head->strlen;
    Draw(x >> 4, y >> 3, head, DrawColor);
    head = head->next;
  }
  while (head);
  if (v9)
    return v8;
  else
    return 0;
}

// 0x13a1b90
void frDumpFontTexture(s32 X, s32 Y, s32 Pri) {
  u8 FrameID;
  struct frGsTex_t_o *GsTex;
  u32 Width;
  u32 Height;
  u32 *v12;
  u32 v13;
  s32 v14;
  s32 v16;

  FrameID = dds3GetFrameID();
  GsTex = gFT->GsTex;
  Width = GsTex->Width;
  Height = GsTex->Height;
  v12 = NewSpecific(s32, 4u);
  v13 = v12[6];
  v14 = 16 * Width;
  v16 = 16 * Height;
  v12[10] = v14;
  v12[11] = v16;
}

// 0x139ac00
u8 frEnableMode(s8 Flag) {
  u8 result;

  result = gModeFlag;
  gModeFlag = result | Flag;
  return result;
}

// 0x1399c70
s8 frEraseEffect(_FRQ *pFRQ) {
  return 0;
}

// 0x13a0ff0
dds3ProcessFunc_t *frFlipPacketBuf(dds3ProcessID_t *id) {
  s32 FrameID;
  _BOOL8 v5;
  struct _FRQ_array *DestroyHandleList;
  _BOOL4 v7;
  Il2CppClass **v9;
  u64 *v10;
  _FRQ_o *v11;

  FrameID = dds3GetFrameID();
  v5 = FrameID == 0;
  DestroyHandleList = gFT->DestroyHandleList;
  v7 = FrameID == 0;
  v9 = &DestroyHandleList->obj.klass + v5;
  v11 = v9[4];
  v10 = v9 + 4;
  frDestroyFontRequestNow(v11);
  *v10 = 0;
  fldCamMainEventForUnity();
  return 0;
}

// 0x139fa10
void frFlushGsFontTable(_TEXT *pText) {
  struct GsFont_t_o *gs_font;
  struct frFontData_t_array *pFont;
  s64 style;
  struct GsFont_t_array *trans;
  s64 font_no;

  gs_font = pText->gs_font;
  if (gs_font && !gs_font->used_count)
  {
    pFont = gFT->pFont;
    style = pText->style;
    trans = pFont->m_Items[style]->trans;
    font_no = gs_font->font_no;
    trans->m_Items[font_no] = 0;
    --gFT->GsFontNums;
  }
}

// 0x13a0090
s32 frGetDefaultFontHeight(u8 Style) {
  return COERCE_FLOAT(LODWORD(GetFontSize(txtMgr, Style).y));
}

// 0x13a0010
s32 frGetDefaultFontWidth(u8 Style) {
  return GetFontSize(txtMgr, Style).x;
}

// 0x139fe80
s32 frGetFontHandleNum(void) {
  return gFT->FontHandleNums;
}

// 0x139fda0
s32 frGetGsFontNum(void) {
  return gFT->GsFontNums;
}

// 0x13a1a30
u32 frGetMessageResult(u32 Flag) {
  return gMessageRequestResult & Flag;
}

// 0x13a09c0
s32 frGetStrWidth(_FRQ *pFRQ) {
  struct _TEXT_o *str;
  s32 result;
  s32 space;
  s32 lw;

  str = pFRQ->str;
  if (!str)
    return 0;
  result = 0;
  space = pFRQ->space;
  do
  {
    lw = str->lw;
    str = str->next;
    result += lw + space;
  }
  while (str);
  return result;
}

// 0x13a11b0
s32 frGetStrWidth2(_FRQ *pFRQ) {
  struct _FRQ_o *head;
  s32 result;
  struct _TEXT_o *i;
  s32 lw;

  head = pFRQ->head;
  if (!head)
    return 0;
  result = 0;
  do
  {
    for (i = head->str; i; result += lw + head->space)
    {
      lw = i->lw;
      i = i->next;
    }
    head = head->next;
  }
  while (head);
  return result;
}

// 0x139fe10
s32 frGetTextHandleNum(void) {
  return gFT->TextHandleNums;
}

// 0x1399a10
void frGetXShiftLev(_TEXT *pText, s32 FontNo) {
  s32 style;
  s32 v7;

  style = pText->style;
LABEL_7:
  pText->width = GetFontSize(txtMgr, style).x;
  v7 = pText->style;
  pText->height = COERCE_FLOAT(LODWORD(GetFontSize(txtMgr, v7).y));
  pText->lw = pText->width;
}

// 0x139fef0
s32 frGetYShiftLev(s8 Style, s32 FontNo) {
  s32 result;
  u32 v6;
  struct System_SByte_array *frGetYShiftLev_y_sht_tbl;

  if (Style != 1)
  {
    if (Style)
      return 0;
    v6 = FontNo - 340;
    if (v6 > 0x71)
      return 0;
    if (!frGetYShiftLev_y_sht_tbl->m_Items[v6])
      return 0;
    return 24;
  }
  if (FontNo + 32 > 103)
  {
    if (FontNo != 74)
    {
      result = 24;
      if ((FontNo & 0xFFFFFFFE) == 0x50 || FontNo == 89)
        return result;
      return 0;
    }
    return 24;
  }
  result = 24;
  if (FontNo != 49 && FontNo != 71)
    return 0;
  return result;
}

// 0x13997c0
void frInitFontHandle(_FRQ *pFRQ) {
  *&pFRQ->x = 0;
  *&pFRQ->w_pxls = 0;
  *&pFRQ->draw_spd = 128;
  pFRQ->strlen = 0;
  pFRQ->str = 0;
  pFRQ->prev = 0;
  pFRQ->next = 0;
  pFRQ->str_end = 0;
  pFRQ->head = pFRQ;
}

// 0x139f140
void frInitFontTable(s32 GsFontNums, s32 TextNums) {
  struct frFontData_t_array *pFont;
  struct frFontData_t_array *v8;
  struct frFontData_t_array *v10;
  struct frFontData_t_array *v12;
  struct frFontData_t_array *v14;
  struct frFontData_t_array *v16;
  struct frFontData_t_array *v18;
  struct frFontData_t_array *v20;
  struct frFontData_t_array *v22;
  s32 v24;
  struct frGsTex_t_o *GsTex;
  u32 Width;
  u32 v27;
  u32 v28;
  s32 v29;
  struct frGsTex_t_o *v30;
  u32 Height;
  u32 v32;
  u32 v33;
  struct _FRQ_array *DestroyHandleList;
  struct _FRQ_array *v36;
  struct frFontTable_t_o *gFT;
  struct frFontTable_t_o *v41;
  u64 v44;
  s32 v45;
  struct System_String_array *gVarStr;
  Il2CppClass **v48;
  u32 v49;

  gFT->GsFontNums = 0;
  gFT->TextHandleNums = 0;
  gFT->FontHandleNums = 0;
  pFont = gFT->pFont;
  pFont->m_Items[0]->data = 0;
  v8 = gFT->pFont;
  v8->m_Items[1]->data = 0;
  v10 = gFT->pFont;
  v10->m_Items[2]->data = 0;
  v12 = gFT->pFont;
  v12->m_Items[3]->data = 0;
  v14 = gFT->pFont;
  v14->m_Items[4]->data = 0;
  v16 = gFT->pFont;
  v16->m_Items[5]->data = 0;
  v18 = gFT->pFont;
  v18->m_Items[6]->data = 0;
  v20 = gFT->pFont;
  v20->m_Items[7]->data = 0;
  v22 = gFT->pFont;
  v22->m_Items[8]->data = 0;
  v24 = GsFontNums / 21;
  gFT->GsTex->Width = 512;
  GsTex = gFT->GsTex;
  Width = GsTex->Width;
  v27 = __clz(Width) ^ 0x1F;
  if (Width)
    v28 = v27;
  else
    v28 = 0;
  GsTex->Width2 = v28;
  v29 = 1 << -__clz(66 * v24);
  if ((GsFontNums + 20) < 0x29)
    v29 = 2;
  gFT->GsTex->Height = v29;
  v30 = gFT->GsTex;
  Height = v30->Height;
  v32 = __clz(Height) ^ 0x1F;
  if (Height)
    v33 = v32;
  else
    v33 = 0;
  v30->Height2 = v33;
  DestroyHandleList = gFT->DestroyHandleList;
  DestroyHandleList->m_Items[0] = 0;
  v36 = gFT->DestroyHandleList;
  v36->m_Items[1] = 0;
  Initialize(0);
  gFT->pTextRing = rbInitRingBuf(0, 4 * TextNums);
  v41 = gFT;
  v41->pRequestRing = rbInitRingBuf(1, TextNums);
  v44 = 0;
  do
  {
    v48 = &gVarStr->obj.klass + v44++;
    v48[4] = 0;
    v45 = (v49 >> 9) & 1;
  }
  while (v44 != 32);
  gRegistMax = 21 * v24;
}

// 0x13996f0
void frInitTextHandle(_TEXT *pText, u16 Code, u8 Style, u8 ColNo, u32 Color, u8 Tp) {
  u8 gModeFlag;

  pText->code = Code;
  pText->style = Style;
  *&pText->lx = 0;
  pText->col_no = ColNo;
  pText->lw = 0;
  pText->color = Color & 0xFFFFFF00;
  pText->tp = Tp;
  pText->draw_count = 0;
  pText->prev = 0;
  pText->next = 0;
  pText->mode = gModeFlag;
  pText->gs_font = 0;
  pText->user_font = 0;
}

// 0x139a0f0
_FRQ *frLinkFontString(char *pStr, s8 Style, s8 ColNo, s8 Tp, _FRQ *pFRQ) {
  System_Byte_array *v13;

  v13 = EncodingSJIS(pStr);
  return frLinkFontString_20580272(v13, Style, ColNo, Tp, pFRQ);
}

// 0x13a07b0
_FRQ *frLinkFontString_20580272(u8 **pStr, s8 Style, s8 ColNo, s8 Tp, _FRQ *pFRQ) {
  _FRQ_o *v11;
  _FRQ_o *v13;
  struct _FRQ_o *head;

  v11 = frSetFontString_20554176(pStr, Style, ColNo, Tp, 0);
  if (!v11)
    return pFRQ;
  v13 = v11;
LABEL_11:
  if (pFRQ)
  {
    pFRQ->next = v13->head;
    head = v13->head;
    if (pFRQ->str)
      head->prev = pFRQ;
    else
      head->prev = pFRQ->prev;
    v13->head = pFRQ->head;
    v13->x = pFRQ->x + 16 * pFRQ->w_pxls;
    v13->y = pFRQ->y;
  }
  return v13;
}

// 0x13a04b0
_FRQ *frLinkUserImage(GsFont_t *pFont, _FRQ *pFRQ) {
  _FRQ_o *v5;
  _FRQ_o *v7;
  struct _FRQ_o *head;

  v5 = frSetUserImage(pFont, 0);
  if (!v5)
    return pFRQ;
LABEL_6:
  v7 = v5;
LABEL_10:
  if (pFRQ)
  {
    pFRQ->next = v7->head;
    head = v7->head;
    if (pFRQ->str)
      head->prev = pFRQ;
    else
      head->prev = pFRQ->prev;
    v7->head = pFRQ->head;
    v7->x = pFRQ->x + 16 * pFRQ->w_pxls;
    v7->y = pFRQ->y;
  }
  return v7;
}

// 0x139f130
void frLoadFontData(u8 StyleNo, s8 pFileName) {
  ;
}

// 0x1399510
void frLoadStyleAll(void) {
  ;
}

// 0x139b9d0
void frMessageReturnCode(frMsgInfo_t *pMsgInfo) {
  s32 Y;
  s32 gMessageStepY;

  Y = pMsgInfo->Y;
  pMsgInfo->Y = CMP_YM(gMessageStepY) + Y;
  *&pMsgInfo->FrqFlag = 257;
}

// 0x13a11f0
s32 frPreCalcStrWidth(char *pStr, u8 Style, u8 Mode) {
  u64 *v7;
  f32 x;

  v7 = Allocate(_TEXT);
  _ctor(v7, 0);
  *(v7 + 7) = 0;
  *(v7 + 45) = Style;
  *(v7 + 47) = Mode;
  x = GetFontSize(txtMgr, Style).x;
  return (x * get_Length(pStr));
}

// 0x139ccb0
char *frReplaceLocalizeText(char *message, frMsgInfo_t **mi, void *index) {
  System_String_o *v6;
  s32 v7;
  _BOOL4 v8;
  s32 i;
  s32 v10;
  s32 v11;
  s32 v12;
  System_String_o *v13;
  System_String_o *LocalizeText_19472448;
  s32 Length;
  s32 v19;
  System_String_o *v21;
  frFont_c **v22;
  s32 v23;
  s32 v24;
  s32 TagIndex;
  System_String_o *v28;
  System_String_o *v29;
  s8 v30;
  System_String_o *Name2NString;
  s8 v32;
  System_String_o *Name1NString;
  System_String_o *v35;
  s8 v36;
  u64 v37;
  s64 v38;
  u64 v40;
  s64 v41;
  System_String_o *v43;
  struct frFont___c_StaticFields *static_fields;
  u64 *_9__42_0;
  System_String_o *v47;
  Il2CppObject *v48;
  s32 v49;
  s32 v50;
  System_String_o *v51;
  System_String_o *v53;
  u64 v54;
  s32 v55;
  u64 v56;
  s64 v57;
  s32 v59;
  s32 v60;
  frFont_c **v61;
  struct System_String_array *TagList;
  s32 v63;
  s32 v65;
  System_String_o *v66;
  s8 v67;
  System_String_o *v68;
  System_String_o *v69;
  System_String_o *v70;
  System_String_o *v71;
  System_String_o *v72;
  System_String_o *v73;
  System_String_o *v74;
  System_String_o *v75;
  System_String_o *v76;
  System_String_o *v77;
  System_String_o *v78;
  System_String_o *v79;
  s32 v82;
  s8 TargetNo[4];
  u16 Chars;

  Chars = 0;
  *TargetNo = 0;
  v6 = "";
  if (_get_Count(index))
  {
    if (_get_Count(index) >= 1)
    {
      v7 = 0;
      v8 = 0;
      for (i = 0;
            i < _get_Count(index);
            ++i)
      {
        v10 = IndexOf(message, 0x3Eu, 0);
        v11 = v10 + 1;
        v12 = v10;
        v13 = Substring_5248048(message, 0, v10 + 1);
        if (_get_Item(
               index,
               i) == -1)
        {
          if ((v8 & op_Inequality(v13, "<WAIT>", 0) & 1) != 0)
          {
            if (fldGb->fieldID == 1)
              v6 = Concat_5224608(v6, "\n");
          }
          v6 = Concat_5224608(v6, v13);
          v8 = 0;
          goto LABEL_27;
        }
        (*mi)->talk_tag = v13;
        if (op_Equality(v13, "<COLLECTIONBOOK_L0191>", 0))
        {
          LocalizeText_19472448 = GetLocalizeText_19472448("COLLECTIONBOOK_M", "<COLLECTIONBOOK_L0192>");
          if (v7)
            goto LABEL_25;
        }
        else
        {
          LocalizeText_19472448 = GetLocalizeText(v13);
          if (v7)
          {
LABEL_25:
            v6 = Concat_5224608(v6, "\n");
            goto LABEL_26;
          }
        }
        if (v8)
          goto LABEL_25;
LABEL_26:
        v6 = Concat_5224608(v6, LocalizeText_19472448);
        v8 = op_Inequality(LocalizeText_19472448, v13, 0);
        ++v7;
LABEL_27:
        Length = get_Length(message);
        message = Substring_5248048(message, v11, Length + ~v12);
      }
    }
    v19 = get_Length(v6);
    v21 = "";
    if (v19 >= 1)
    {
      v22 = &frFont;
      v23 = v19;
      v24 = 0;
      v82 = v19;
      do
      {
        if (get_Chars(v6, v24) == 60)
        {
          v49 = IndexOf_5259744(v6, 0x3Eu, v24);
          if (v49 == -1)
            break;
          v50 = v49 + 1;
          v51 = Substring_5248048(v6, v24, v49 + 1 - v24);
          v53 = Replace_5267216(v51, " ", "");
          v54 = *v22;
          if (((*v22)->_2.bitflags2 & 2) != 0 && !*(v54 + 216))
          {
            TagIndex = GetTagIndex(v53);
            if (TagIndex == -1)
              goto LABEL_31;
          }
          else
          {
            TagIndex = GetTagIndex(v53);
            if (TagIndex == -1)
            {
LABEL_31:
              v28 = v21;
              v29 = v53;
              goto LABEL_93;
            }
          }
          v55 = TagIndex;
          v56 = *v22;
          *TargetNo = -1;
          if ((*(v56 + 295) & 2) != 0 && !*(v56 + 216))
          {
            v56 = *v22;
          }
          v57 = *(*(v56 + 184) + 80LL);
          v59 = get_Length(*(v57 + 8LL * v55 + 32), 0);
          v60 = get_Length(v53);
          v61 = v22;
          TagList = (*v22)->static_fields->TagList;
          v63 = v60;
          v65 = get_Length(TagList->m_Items[v55]);
          v66 = Substring_5248048(v53, v59, v63 + ~v65);
          if (!TryParse(v66, TargetNo, 0))
            *TargetNo = 0;
          v22 = v61;
          v23 = v82;
          switch (v55)
          {
            case 0:
              v37 = *v22;
              if (((*v22)->_2.bitflags2 & 2) != 0 && !*(v37 + 216))
              {
                v37 = *v22;
              }
              v38 = *(*(v37 + 184) + 48LL);
              if (!*(v38 + 8LL * *TargetNo + 32))
                goto LABEL_94;
              v40 = *v22;
              if (((*v22)->_2.bitflags2 & 2) != 0 && !*(v40 + 216))
              {
                v40 = *v22;
              }
              v41 = *(*(v40 + 184) + 48LL);
              v43 = *(v41 + 8LL * *TargetNo + 32);
              _9__42_0 = __9__42_0;
              v47 = "[0-9]";
              if (!_9__42_0)
              {
                v48 = __9;
                _9__42_0 = Allocate(System_Text_RegularExpressions_MatchEvaluator);
                _ctor(
                  _9__42_0,
                  v48,
                  Method_frFont___c__frReplaceLocalizeText_b__42_0__,
                  0);
                __9__42_0 = _9__42_0;
              }
              {
              }
              Name2NString = Replace_4089328(v43, v47, _9__42_0);
              break;
            case 1:
            case 2:
              v67 = TargetNo[0];
              Name2NString = frGetName2NString(v67);
              break;
            case 3:
            case 4:
              v30 = TargetNo[0];
              Name2NString = frGetName1NString(v30);
              break;
            case 5:
            case 6:
              v32 = TargetNo[0];
              Name1NString = frGetName1NString(v32);
              v35 = frGetName2NString(v32);
              Name2NString = Concat_5221536(Name1NString, " ", v35);
              break;
            case 7:
            case 8:
              v36 = TargetNo[0];
              Name2NString = frGetCNameString(v36);
              break;
            default:
              goto LABEL_94;
          }
        }
        else
        {
          v50 = v24 + 1;
          Chars = get_Chars(v6, v24);
          Name2NString = sub_3C3A80(&Chars, 0);
        }
        v29 = Name2NString;
        v28 = v21;
LABEL_93:
        v21 = Concat_5224608(v28, v29);
LABEL_94:
        v24 = v50;
      }
      while (v50 < v23);
    }
    {
    }
    v68 = Replace(v21, "<font ", "<FO", 1, 0);
    v69 = Replace(v68, "<font", "<FO", 1, 0);
    v70 = Replace(v69, "<color ", "<CO", 1, 0);
    v71 = Replace(v70, "<color", "<CO", 1, 0);
    v72 = Replace(v71, "<tp ", "<TP", 1, 0);
    v73 = Replace(v72, "<tp", "<TP", 1, 0);
    v74 = Replace(v73, "<spd ", "<SP", 1, 0);
    v75 = Replace(v74, "<spd", "<SP", 1, 0);
    v76 = Replace(v75, "<WAIT", "<WA", 1, 0);
    v77 = Replace(v76, "<RET", "<RE", 1, 0);
    v78 = Replace(v77, "<NWAIT", "<NW", 1, 0);
    v79 = Replace(v78, "<AF_DEL", "<AD", 1, 0);
    return Replace(v79, "<KUTI", "<KU", 1, 0);
  }
  return message;
}

// 0x139f020
void frSetDrawPosition(_FRQ *pFRQ, s32 X, s32 Y) {
  pFRQ->x = X;
  pFRQ->y = Y;
}

// 0x139a1a0
void frSetDrawSpeed(_FRQ *pFRQ, u8 Speed) {
  u8 v3;

  if (Speed >= 0x41u)
    v3 = 0x80;
  else
    v3 = 2 * Speed;
  pFRQ->draw_spd = v3;
}

// 0x13a1120
void frSetExtDic(u8 pExtFontData) {
  ;
}

// 0x13997e0
_TEXT *frSetFont(u16 Code, u8 Style, u8 ColNo, u8 Tp) {
  u64 *v9;
  s64 v12;
  _TEXT_o *v14;
  frFont_c *v15;
  s8 gModeFlag;

  v9 = Allocate(_TEXT);
  _ctor(v9, 0);
  v14 = rbRentFromRingBuf__TEXT_(gFT->pTextRing);
  ++gFT->TextHandleNums;
  if (v14)
  {
    if ((v15->_2.bitflags2 & 2) == 0)
      goto LABEL_15;
  }
  else
  {
    SDF_ABORT1("FONT SYS : Text buffer overflow error.\n");
      goto LABEL_15;
  }
LABEL_15:
LABEL_17:
  v14->code = Code;
  v14->style = Style;
  *&v14->lx = 0;
  v14->col_no = ColNo;
  *&v14->lw = 0xA09DC30000000000LL;
  v14->tp = Tp;
  v14->draw_count = 0;
  v14->prev = 0;
  v14->next = 0;
  v14->mode = gModeFlag;
  v14->gs_font = 0;
  v14->user_font = 0;
  frGetXShiftLev(v14, v12);
  if ((v14->mode & 0x10) == 0)
LABEL_27:
    v14->ly = 0;
  return v14;
}

// 0x1399550
void frSetFontClut(void) {
  ;
}

// 0x13a0ae0
void frSetFontColor(_FRQ *pFRQ, u32 Color) {
  struct _TEXT_o *i;

  for (; pFRQ; pFRQ = pFRQ->prev)
  {
    for (i = pFRQ->str; i; i = i->next)
      i->color = Color;
  }
}

// 0x139e620
void frSetFontColorNo(_FRQ *pFRQ, u8 ColorNo) {
  struct _TEXT_o *i;

  for (; pFRQ; pFRQ = pFRQ->prev)
  {
    for (i = pFRQ->str; i; i = i->next)
      i->col_no = ColorNo;
  }
}

// 0x13a0b10
void frSetFontDrawOT(u32 OtType) {
  gFontDrawOT = OtType;
}

// 0x13a0a00
void frSetFontSize(_FRQ *pFRQ, s32 Width, s32 Height) {
  s16 v4;
  _FRQ_o *prev;
  struct _TEXT_o *i;
  struct _TEXT_o *str;
  s32 v10;
  s32 lw;

  v4 = Height;
  pFRQ->x_size = Width;
  pFRQ->y_size = v4;
  if (pFRQ)
  {
    prev = pFRQ;
    do
    {
      for (i = prev->str; i; i = i->next)
      {
        i->lw = Width;
        i->width = Width;
        i->height = v4;
      }
      prev = prev->prev;
    }
    while (prev);
  }
  str = pFRQ->str;
  if (!str)
    goto LABEL_15;
LABEL_11:
  v10 = 0;
  do
  {
    lw = str->lw;
    str = str->next;
    v10 += pFRQ->space + lw;
  }
  while (str);
LABEL_16:
  pFRQ->w_pxls = v10;
}

// 0x139a440
void frSetFontSpace(_FRQ *pFRQ, s32 Space) {
  s8 v3;
  struct _TEXT_o *str;
  s32 v6;
  s32 lw;

  v3 = Space;
  pFRQ->space = v3;
  str = pFRQ->str;
  if (!str)
    goto LABEL_10;
LABEL_6:
  v6 = 0;
  do
  {
    lw = str->lw;
    str = str->next;
    v6 += pFRQ->space + lw;
  }
  while (str);
LABEL_11:
  pFRQ->w_pxls = v6;
}

// 0x13a0910
_FRQ *frSetFontString(char *pStr, s8 Style, s8 ColNo, s8 Tp, _FRQ *pFRQ) {
  System_Byte_array *v13;

  v13 = EncodingSJIS(pStr);
  return frSetFontString_20554176(v13, Style, ColNo, Tp, pFRQ);
}

// 0x139dc90
_FRQ *frSetFontStringLocalize(u16 pStr, s8 Style, s8 ColNo, s8 Tp, _FRQ *pFRQ) {
  _FRQ_o *v6;
  frFont_c *v11;
  struct _TEXT_o *str_end;
  _TEXT_o *v13;
  _TEXT_o **p_str;

  v6 = pFRQ;
  frSetFontString_style = 0;
  if ((Style & 0x80000000) == 0)
  {
    frSetFontString_style = Style;
  }
  if (v6)
  {
    str_end = v6->str_end;
    if ((v11->_2.bitflags2 & 2) == 0)
      goto LABEL_19;
    goto LABEL_13;
  }
  v6 = rbRentFromRingBuf__TEXT_(gFT->pRequestRing);
  ++gFT->FontHandleNums;
  v6->strlen = 0;
  *&v6->x = 0;
  *&v6->w_pxls = 0;
  v6->str = 0;
  v6->prev = 0;
  v6->next = 0;
  *&v6->draw_spd = 128;
  v6->str_end = 0;
  v6->head = v6;
  str_end = v6->str_end;
  if ((v11->_2.bitflags2 & 2) != 0)
  {
LABEL_13:
  }
LABEL_19:
  v13 = frSetFont(0x8000u, frSetFontString_style, ColNo, Tp, pFRQ);
  p_str = &v6->str;
  if (str_end)
    p_str = &str_end->next;
  *p_str = v13;
  v13->chcode = pStr;
  v13->prev = str_end;
  v6->w_pxls += v13->lw;
  ++v6->strlen;
  if (v13)
  {
    v6->str_end = v13;
    v6->x_size = v13->width;
    v6->y_size = v13->height;
  }
  return v6;
}

// 0x139a1c0
_FRQ *frSetFontString_20554176(u8 **pStr, s8 Style, s8 ColNo, s8 Tp, _FRQ *pFRQ) {
  _FRQ_o *v6;
  u32 max_length;
  _TEXT_o *str_end;
  s64 v14;
  _TEXT_o *v15;
  u16 v17;
  _TEXT_o *v20;
  _TEXT_o **p_next;
  s32 strlen;

  v6 = pFRQ;
  frSetFontString_style = 0;
  if ((Style & 0x80000000) == 0)
  {
    frSetFontString_style = Style;
  }
  max_length = pStr->max_length;
  if (!v6)
  {
    v6 = rbRentFromRingBuf__TEXT_(gFT->pRequestRing);
    ++gFT->FontHandleNums;
    *&v6->x = 0;
    *&v6->w_pxls = 0;
    v6->prev = 0;
    v6->next = 0;
    v6->strlen = 0;
    v6->str_end = 0;
    v6->head = v6;
    v6->str = 0;
    *&v6->draw_spd = 128;
  }
  if (max_length)
  {
    str_end = v6->str_end;
    LODWORD(v14) = 0;
    v15 = 0;
    while (1)
    {
      v17 = pStr->m_Items[v14];
      if (!pStr->m_Items[v14])
        break;
      if (v17 < 0)
      {
        v14 = (v14 + 1);
        v17 = pStr->m_Items[v14] | (v17 << 8);
      }
      v20 = frSetFont(v17, frSetFontString_style, ColNo, Tp, pFRQ);
      p_next = &str_end->next;
      if (!str_end)
        p_next = &v6->str;
      *p_next = v20;
      v20->prev = str_end;
      strlen = v6->strlen;
      LODWORD(v14) = v14 + 1;
      v15 = v20;
      str_end = v20;
      v6->w_pxls += v20->lw;
      v6->strlen = strlen + 1;
      if (v14 >= max_length)
        goto LABEL_33;
    }
    if (!v15)
      return v6;
LABEL_33:
    v6->str_end = v15;
    v6->x_size = v15->width;
    v6->y_size = v15->height;
  }
  return v6;
}

// 0x13a12d0
void frSetMessageDefStepY(void) {
  gMessageStepY = 33;
}

// 0x13a1340
void frSetMessageStepY(s32 StepY) {
  gMessageStepY = StepY;
}

// 0x139bc00
void frSetPriority(_FRQ *pFRQ, u32 Pri) {
  pFRQ->priority = Pri >> 4;
}

// 0x13a0110
_FRQ *frSetUserImage(GsFont_t *pFont, _FRQ *pFRQ) {
  _FRQ_o *v3;
  frFont_c *v5;
  _TEXT_o *v7;
  frFont_c *v8;
  struct _TEXT_o *str_end;
  _TEXT_o **p_str;
  s32 v17;
  f32 y;
  UnityEngine_Vector2_o FontSize;

  v3 = pFRQ;
  if ((byte_3F59670 & 1) != 0)
  {
    if (pFRQ)
      goto LABEL_3;
  }
  else
  {
    if (v3)
    {
LABEL_3:
      if ((v5->_2.bitflags2 & 2) == 0)
        goto LABEL_11;
      goto LABEL_4;
    }
  }
  v3 = rbRentFromRingBuf__TEXT_(gFT->pRequestRing);
  ++gFT->FontHandleNums;
  v3->strlen = 0;
  *&v3->x = 0;
  *&v3->w_pxls = 0;
  v3->str = 0;
  v3->prev = 0;
  v3->next = 0;
  *&v3->draw_spd = 128;
  v3->str_end = 0;
  v3->head = v3;
  if ((v5->_2.bitflags2 & 2) != 0)
  {
LABEL_4:
  }
LABEL_11:
  v7 = rbRentFromRingBuf__TEXT_(gFT->pTextRing);
  str_end = v3->str_end;
  ++gFT->TextHandleNums;
  if (v7)
  {
    if ((v8->_2.bitflags2 & 2) == 0)
      goto LABEL_20;
  }
  else
  {
    SDF_ABORT1("FONT SYS : Text buffer overflow error.\n");
      goto LABEL_20;
  }
LABEL_20:
LABEL_22:
  v7->code = 0;
  *&v7->lx = 0;
  *&v7->col_no = 0;
  v7->tp = 0;
  *&v7->lw = 0xA09DC30000000000LL;
  v7->mode = gModeFlag;
  p_str = &v3->str;
  v7->prev = 0;
  v7->next = 0;
  if (str_end)
    p_str = &str_end->next;
  v7->draw_count = 0;
  v7->gs_font = 0;
  v7->user_font = 0;
  *p_str = v7;
  v7->user_font = pFont;
  FontSize = GetFontSize(txtMgr, 0);
  v7->lw = FontSize.x;
LABEL_34:
  v7->width = GetFontSize(txtMgr, 0).x;
  y = GetFontSize(txtMgr, 0).y;
  v7->prev = str_end;
  v7->height = y;
  ++v3->strlen;
  v17 = v7->lw + v3->w_pxls;
  v3->str_end = v7;
  v3->x_size = FontSize.x;
  v3->y_size = FontSize.y;
  v3->w_pxls = v17;
  return v3;
}

// 0x13a1aa0
void frSetVariableRequest(s32 VarNo, char *pStr) {
  struct System_String_array *gVarStr;

  else
  {
    if (!pStr)
      goto LABEL_9;
  }
LABEL_9:
  gVarStr->m_Items[VarNo] = pStr;
}

// 0x139f030
void frSetWhiteSpaceW(u8 StyleNo, s32 Width) {
  char v3;
  struct frFontData_t_array *pFont;
  frFontData_t_o *v8;
  struct System_SByte_array *prop;
  struct System_SByte_array *v11;
  s8 v12;

  v3 = Width;
  pFont = gFT->pFont;
  v8 = pFont->m_Items[StyleNo];
  prop = v8->prop;
  prop->m_Items[0] = 1;
  v11 = v8->prop;
  v12 = v3 + 1;
  v11->m_Items[1] = v12;
}

// 0x13a11a0
s32 frStrLen(s8 **pStr) {
  return 0;
}

// 0x13994e0
u32 frSwapColor(u32 Col) {
  return bswap32(Col);
}

// 0x1399560
GsFont_t *frTranslateFont2GS(_TEXT *pText, s32 FontNo) {
  struct frFontData_t_array *pFont;
  s64 style;
  frFontData_t_o *v9;
  u64 *v11;
  struct GsFont_t_array *trans;
  GsFont_t_o *v14;
  u64 *v16;
  u16 v18[2];
  s32 v19;

  pFont = gFT->pFont;
  style = pText->style;
  v9 = pFont->m_Items[style];
  v19 = FontNo;
  v11 = sub_8D3950(s32, &v19);
  Write_2930400("[{0:x3}] require\n", v11);
  trans = v9->trans;
  v14 = trans->m_Items[FontNo];
  if (v14)
  {
    ++v14->used_count;
    v18[0] = v14->font_no;
    v16 = sub_8D3950(ushort, v18);
    Write_2930400("[{0:x3}] complete\n", v16);
  }
  return v14;
}

// 0x13a06d0
GsFont_t *frTranslateUserData(s32 Width, s32 Height, void *pData, s8 DataFreeMode) {
  u64 *v5;

  NewSpecific(s32, 2u);
  v5 = Allocate(sdfImageSetParm_t);
  sdfImageSetParm_t___ctor(v5);
  return 0;
}

// 0x139c2a0
char *replace_space(char *message) {
  Il2CppObject *v4;
  s32 IndexOf_5262640;
  s32 Length;
  System_String_o *v7;
  System_String_o *v8;
  System_String_o *v9;
  System_String_o *v10;
  Il2CppObject *v12;

  v4 = Concat_5224608("message = ", message);
  Log(v4, 0);
  IndexOf_5262640 = LastIndexOf_5262640(message, "<");
  Length = get_Length(message);
  v7 = Substring_5248048(message, IndexOf_5262640, Length - IndexOf_5262640);
  v8 = Replace_5267216(v7, " ", "");
  v9 = Concat_5224608(v8, ">");
  if (IndexOf_5262640 >= 1)
  {
    v10 = Substring_5248048(message, 0, IndexOf_5262640 - 1);
    v9 = Concat_5224608(v10, v9);
  }
  v12 = Concat_5271136("LongTagName Error : ", message, " => ", v9);
  Log(v12, 0);
  return v9;
}
