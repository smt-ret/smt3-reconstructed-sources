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
    frCreateNewHandle(0);
    frSetFontStringLocalize(0, 0, 0, 0, 0);
    CMP_YM(0);
    return 0;
}

// 0x13a2190
char *CutAF_DEL(char *message) {
  s32 v3;

  v3 = IndexOf_5260384(message, StringLiteral_16999);
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
  GlobalData_c *v23;
  struct GlobalData_StaticFields *static_fields;
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
    static_fields = v23->static_fields;
    txtMgr = static_fields->txtMgr;
    Draw_20213232(txtMgr, x, y, 0.0, DrawBuffer, frq);
  }
}

// 0x13991c0
s32 FR_STR_WIDTH(_FRQ *frq) {
  return frq->w_pxls;
}

// 0x139e390
s32 GetTagIndex(char *tag) {
    return 0;
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
  frFont_c *v18;
  struct frFont_StaticFields *static_fields;
  s8 gMessageSpaceX;
  _FRQ_o *result;

  static_fields = v18->static_fields;
  gMessageSpaceX = static_fields->gMessageSpaceX;
  static_fields->gMessageSpaceX = 0;
  result = MessageRequestEx2(X, Y, Z, Style, ColNo, Tp, Spd, pMsg, 0);
  return result;
}

// 0x1399180
s32 NO2DIC(s32 val) {
  return (((2 * val) & 0x1FF00) + 32896) & 0xFFFFFF80 | val & 0x7F;
}

// 0x13a1cf0
char *RepColTag(char *txt, void **LegacyParamArray) {
    return 0;
}

// 0x13a1ff0
char *RepColTag_20586480(char *txt) {
    return 0;
}

// 0x139f9f0
void frAddFontStyle(u8 StyleNo, u8 **pFontData, sdfMemHandle_t *DataMh) {
  ;
}

// 0x139a4f0
_FRQ *frAnalyzeMessage(frMsgInfo_t *pMsgInfo) {
    frCreateNewHandle(0);
    frSetFontString_20554176(0, 0, 0, 0, 0);
    CMP_YM(0);
    frAnalyzeTag(0, 0);
    return 0;
}

// 0x139bc10
_FRQ *frAnalyzeMessageLocalize(frMsgInfo_t *pMsgInfo) {
    replace_space(0);
    frAnalyzeTagLocalize1(0, 0, 0, 0);
    frReplaceLocalizeText(0, 0, 0);
    frAnalyzeTagLocalize2(0, 0, 0);
    frCreateNewHandle(0);
    frSetFontStringLocalize(0, 0, 0, 0, 0);
    CMP_YM(0);
    return 0;
}

// 0x139ad00
s8 frAnalyzeTag(s32 code, frMsgInfo_t **mi) {
    frCreateNewHandle(0);
    frCreateVariableRequest(0, 0);
    frGetName1NFRQ(0, 0, 0);
    frGetName2NFRQ(0, 0, 0);
    frGetCNameFRQ(0, 0, 0);
    CMP_YM(0);
    return 0;
}

// 0x139c420
s8 frAnalyzeTagLocalize1(s32 code, frMsgInfo_t **mi, char **message, void *index) {
    frGetName1NString(0);
    frGetName2NString(0);
    frGetCNameString(0);
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
  frFont_c *v17;
  struct frFont_StaticFields *static_fields;
  frFont_c *v20;
  s32 v21;
  frMsgInfo_t_o *v24;
  s32 Y;
  s32 gMessageStepY;
  frFont_c *v29;
  u8 v30;
  frFont_c *v32;
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
  if (!TryParse(v10, &result, 0))
    return 0;
  if (result == -1)
  {
    if (op_Equality(v11, StringLiteral_16971, 0)
      || op_Equality(v11, StringLiteral_16972, 0)
      || op_Equality(v11, StringLiteral_16973, 0))
    {
      return 0;
    }
    v12 = &StringLiteral_16974;
  }
  else
  {
    if (op_Equality(v11, StringLiteral_16975, 0)
      || op_Equality(v11, StringLiteral_16976, 0)
      || op_Equality(v11, StringLiteral_16977, 0)
      || op_Equality(v11, StringLiteral_16978, 0))
    {
      return 0;
    }
    v12 = &StringLiteral_16979;
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
        if (v13 == 502539224 && op_Equality(v11, StringLiteral_16971, 0))
        {
          (*mi)->Style = result - 1;
          v14 = *mi;
          v15 = 1;
          if ((*mi)->FrqFlag)
            return v15;
        }
        return 0;
      }
      if (op_Equality(v11, StringLiteral_16975, 0))
      {
        static_fields = v20->static_fields;
        v21 = static_fields->gMessageRequestResult | 1;
        static_fields->gMessageRequestResult = v21;
      }
      return 0;
    }
    if (v13 == 601086367)
    {
      if (op_Equality(v11, StringLiteral_16979, 0))
      {
        static_fields = v29->static_fields;
        v21 = static_fields->gMessageRequestResult | 4;
      }
      return 0;
    }
    if (v13 != 652993342 || !op_Equality(v11, StringLiteral_16978, 0))
      return 0;
    static_fields = v17->static_fields;
    v14 = *mi;
    v15 = 1;
    if ((*mi)->FrqFlag)
      return v15;
  }
  if (v13 > 0x5DE7BCA5)
  {
    if (v13 != 1858024696)
    {
      if (v13 == 1977586600)
      {
        if (op_Equality(v11, StringLiteral_16977, 0))
        {
          static_fields = v32->static_fields;
          v21 = static_fields->gMessageRequestResult | 2;
        }
      }
      else if (v13 == 2026933719 && op_Equality(v11, StringLiteral_16973, 0))
      {
        (*mi)->Tp = result;
        v14 = *mi;
        v15 = 1;
        if ((*mi)->FrqFlag)
          return v15;
      }
      return 0;
    }
    if (!op_Equality(v11, StringLiteral_16974, 0))
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
    return v15;
  }
  if (v13 != 667064010)
  {
    if (v13 == 1575468197 && op_Equality(v11, StringLiteral_16972, 0))
    {
      (*mi)->ColNo = result;
      v14 = *mi;
      v15 = 1;
      if ((*mi)->FrqFlag)
        return v15;
    }
    return 0;
  }
  if (!op_Equality(v11, StringLiteral_16976, 0))
    return 0;
  if ((gModeFlag & 4) != 0)
  v24 = *mi;
  Y = v24->Y;
  v24->Y = CMP_YM(gMessageStepY) + Y;
  *&v24->FrqFlag = 257;
  v14 = *mi;
  v15 = 1;
  if (!(*mi)->FrqFlag)
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
    v6 = StringLiteral_416;
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
    UnicodeToIndexByte(0, 0);
    frSetFontString_20554176(0, 0, 0, 0, 0);
    EncodingSJIS(0);
    frLinkFontString_20580272(0, 0, 0, 0, 0);
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
  else  *v10 = pFRQ;
  return 0;
}

// 0x139f860
_FRQ *frDestroyFontRequestNow(_FRQ *pFRQ) {
  struct _TEXT_o *str;
  _FRQ_o *v4;
  _TEXT_o *v5;

  if (!pFRQ)
    return 0;
  do
  {
    str = pFRQ->str;
    v4 = pFRQ;
    if (!str)
    {
      pFRQ = pFRQ->prev;
    }
    do
    {
      v5 = str;
      str = str->next;

      {
        v5->user_font = 0;
      }
      rbRetToRingBuf__TEXT_(0, v5, gFT->pTextRing);
      --gFT->TextHandleNums;
    }
    while (str);
    pFRQ = v4->prev;
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

  Log(StringLiteral_16995, 0);
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
  frFont_c *v3;
  struct frFont_StaticFields *static_fields;
  u8 result;

  static_fields = v3->static_fields;
  result = static_fields->gModeFlag;
  static_fields->gModeFlag = result & ~Flag;
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
    p_color = &pText->color;
    v10 = pText->color;
  }
  v7 = pFRQ->prev;
  if (!v7 || (str_end = v7->str_end) == 0)
  {
    LOBYTE(color) = 0x80;
  }
  color = str_end->color;
  tp = str_end->tp;
  p_color = &pText->color;
  v10 = pText->color;
  if (tp && tp != pText->tp)
  {
    if (color == 128)
  }
  if (color >= AlphaDelay)
  {
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
  }
  if ((v10 & 0x80) != 0)
    return 0;
  if (pText->tp == 1)
    return 32 - 16 * (2 * pText->draw_count % 5);
  else
    return 0;
}

// 0x13a0b80
s32 frDrawFont(_FRQ *pFRQ) {
  u32 v2;

  return frDrawFontEx2(pFRQ, 0, v2);
}

// 0x13a0c40
s32 frDrawFontEx(_FRQ *pFRQ, s8 Mode) {
  return frDrawFontEx2(pFRQ, Mode);
}

// 0x13a0cc0
s32 frDrawFontEx2(_FRQ *pFRQ, s8 Mode, u32 Ot) {
    frCreateDrawFontPacket(0, 0, 0, 0);
    Draw(0, 0, 0, 0);
    return 0;
}

// 0x13a1b90
void frDumpFontTexture(s32 X, s32 Y, s32 Pri) {
  u8 FrameID;
  frFont_c *v6;
  struct frFont_StaticFields *static_fields;
  struct frGsTex_t_o *GsTex;
  u32 Width;
  u32 Height;
  u32 *v12;
  u32 v13;
  s32 v14;
  s32 v16;

  FrameID = dds3GetFrameID();
  static_fields = v6->static_fields;
  GsTex = static_fields->gFT->GsTex;
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
  frFont_c *v3;
  struct frFont_StaticFields *static_fields;
  u8 result;

  static_fields = v3->static_fields;
  result = static_fields->gModeFlag;
  static_fields->gModeFlag = result | Flag;
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
  v7 = v5;
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
    GetLocalizeText_19472448(0, 0);
    GetLocalizeText(0);
    GetTagIndex(0);
    frGetName2NString(0);
    frGetName1NString(0);
    frGetCNameString(0);
    return 0;
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
  }
  else
  {
    SDF_ABORT1(StringLiteral_16958);
  }
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
  v10 = 0;
  do
  {
    lw = str->lw;
    str = str->next;
    v10 += pFRQ->space + lw;
  }
  while (str);
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
  v6 = 0;
  do
  {
    lw = str->lw;
    str = str->next;
    v6 += pFRQ->space + lw;
  }
  while (str);
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
    }
    if (!v15)
      return v6;
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
  }
  else
  {
    if (v3)
    {
      if ((v5->_2.bitflags2 & 2) == 0)
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
  v7 = rbRentFromRingBuf__TEXT_(gFT->pTextRing);
  str_end = v3->str_end;
  ++gFT->TextHandleNums;
  if (v7)
  {
    if ((v8->_2.bitflags2 & 2) == 0)
  }
  else
  {
    SDF_ABORT1(StringLiteral_16958);
  }
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
  }
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
    return 0;
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

  v4 = Concat_5224608(StringLiteral_16959, message);
  Log(v4, 0);
  IndexOf_5262640 = LastIndexOf_5262640(message, StringLiteral_2303);
  Length = get_Length(message);
  v7 = Substring_5248048(message, IndexOf_5262640, Length - IndexOf_5262640);
  v8 = Replace_5267216(v7, StringLiteral_212, StringLiteral_416);
  v9 = Concat_5224608(v8, StringLiteral_604);
  if (IndexOf_5262640 >= 1)
  {
    v10 = Substring_5248048(message, 0, IndexOf_5262640 - 1);
    v9 = Concat_5224608(v10, v9);
  }
  v12 = Concat_5271136(StringLiteral_16960, message, StringLiteral_16961, v9);
  Log(v12, 0);
  return v9;
}
