#include "types.h"

typedef struct TextManager TextManager;
typedef struct _FRQ _FRQ;

static u16 *frwExchgStyle_frExchgTbl;

void Draw_20213616(TextManager *this, _FRQ *frq);
u8 **EncodingSJIS(char *instr);
u8 Get(s32 id);
sdfVector2_t GetFontSize(TextManager *this, s32 no);
u8 **MessageNumSearch(s32 Index, u8 **pData, s32 Size);
_FRQ *MessageRequestEx2(s32 X, s32 Y, u32 Z, u8 Style, u8 ColNo, u8 Tp, u8 Spd, u8 **pMsg, _FRQ *pFRQ);
u8 **UnicodeToIndexByte(TextManager *this, char *str);
_FRQ *frLinkFontString_20580272(u8 **pStr, s8 Style, s8 ColNo, s8 Tp, _FRQ *pFRQ);
_FRQ *frSetFontString_20554176(u8 **pStr, s8 Style, s8 ColNo, s8 Tp, _FRQ *pFRQ);
_FRQ *frwGetFontEx(s32 X, s32 Y, s32 Pri, u32 Color, u8 **pStr, s8 ChangeStyle, s8 Mode, _FRQ *pFRQ, s32 ftype);
_FRQ *frwGetSmallFontFRQ2(s32 X, s32 Y, s32 Pri, u32 Color, u8 **pStr, _FRQ *pFRQ);

// 0x13a57e0
u16 frwExchgStyle(u16 Code) {
  return Code;
}

// 0x13a57d0
void frwFreeStaffFont(void) {
  ;
}

// 0x13a5810
_FRQ *frwGetFontEx(s32 X, s32 Y, s32 Pri, u32 Color, u8 **pStr, s8 ChangeStyle, s8 Mode, _FRQ *pFRQ, s32 ftype) {
  frFont_c *v18;
  _FRQ_o *v20;
  _FRQ_o *v22;
  _FRQ_o *prev;
  struct _TEXT_o *i;
  struct _TEXT_o *j;
  struct System_UInt32_array_array *frClutTbl;
  s64 col_no;
  System_UInt32_array *v30;
  struct System_UInt32_array_array *v32;
  s64 v33;
  System_UInt32_array *v34;
  struct _TEXT_o *str;
  s32 v39;
  struct _TEXT_o *next;
  s32 v41;
  s32 lw;
  UnityEngine_Vector2_o FontSize;

  NewSpecific(byte, 3u);
  if (Mode)
  {
      goto LABEL_17;
  }
  else
  {
    gModeFlag |= 1u;
    if ((v18->_2.bitflags2 & 2) == 0)
      goto LABEL_17;
  }
LABEL_17:
LABEL_19:
  gModeFlag &= ~2u;
  v20 = frLinkFontString_20580272(pStr, ChangeStyle, 0, 0, 0);
  v22 = v20;
  if (v20)
  {
    prev = v20;
    do
    {
      for (i = prev->str; i; i = i->next)
        i->color = Color;
      prev = prev->prev;
    }
    while (prev);
  }
  for (j = v20->str; j; j = j->next)
  {
    col_no = j->col_no;
    v30 = frClutTbl->m_Items[col_no];
    j->color_base = v30->m_Items[15];
    v32 = frClutTbl;
    v33 = j->col_no;
    v34 = v32->m_Items[v33];
    j->color_edge = v34->m_Items[0];
  }
  v22->x = X;
  v22->y = Y;
  if (ftype != -1)
  {
    str = v22->str;
    FontSize = GetFontSize(txtMgr, ftype);
    v39 = FontSize.x;
    do
    {
      str->width = FontSize.x;
      str->height = FontSize.y;
      str->lw = v39;
      str->style = ftype;
      str = str->next;
    }
    while (str);
    v22->x_size = v39;
    v22->y_size = FontSize.y;
    else
    {
      next = v22->str;
      if (next)
        goto LABEL_50;
    }
    v41 = 0;
LABEL_55:
    v22->w_pxls = v41;
  }
  Draw_20213616(txtMgr, v22);
LABEL_63:
  gModeFlag |= 2u;
  if (!Mode)
  {
    gModeFlag &= ~1u;
  }
  return v22;
}

// 0x13a6620
_FRQ *frwGetHelpFRQ(s32 X, s32 Y, u32 Z, s8 HelpType, u16 HelpID, s8 DrawMode) {
  void **v13;
  void *v14;
  System_Byte_array *v15;
  System_Byte_array *v16;
  frFont_c *v17;
  s8 gMessageSpaceX;
  _FRQ_o *result;

  if (HelpType == 2)
  {
    v13 = &datHeartsHelp;
      goto LABEL_12;
    goto LABEL_7;
  }
  if (HelpType == 1)
  {
    v13 = &datItemHelp;
      goto LABEL_12;
    goto LABEL_7;
  }
  if (HelpType)
  {
    v16 = 0;
    if (DrawMode != 1)
      goto LABEL_16;
LABEL_24:
    gModeFlag &= ~4u;
    if ((byte_3F59675 & 1) != 0)
    {
LABEL_35:
      gModeFlag |= 8u;
      if ((v17->_2.bitflags2 & 2) == 0)
        goto LABEL_53;
      goto LABEL_49;
    }
LABEL_33:
LABEL_34:
    goto LABEL_35;
  }
  v13 = &datSkillHelp;
  {
LABEL_7:
    if (!*(v14 + 54))
    {
      v14 = *v13;
    }
  }
LABEL_12:
  v15 = **(v14 + 23);
  v16 = MessageNumSearch(HelpID, v15, Z, HelpType);
  if (DrawMode == 1)
    goto LABEL_24;
LABEL_16:
  if (DrawMode == 2)
  {
    gModeFlag &= ~4u;
    if ((v17->_2.bitflags2 & 2) == 0)
      goto LABEL_53;
    goto LABEL_49;
  }
  if (DrawMode == 3)
  {
    if ((byte_3F59675 & 1) != 0)
      goto LABEL_34;
    goto LABEL_33;
  }
    goto LABEL_53;
LABEL_49:
LABEL_53:
LABEL_55:
  gMessageSpaceX = 0;
  result = MessageRequestEx2(X, Y, Z, 1u, 0, 0, 0x80u, v16, 0);
  return result;
}

// 0x13a69a0
char *frwGetHelpForUnity(s32 X, s32 Y, u32 Z, s8 HelpType, u16 HelpID, s8 DrawMode) {
  System_String_o *v10;
  System_String_o *v11;
  System_String_o *v12;
  System_String_o *v13;
  s32 v15;

  if (HelpType == 2)
  {
    v10 = Get(HelpID, 0);
    if (DrawMode == 2)
      goto LABEL_24;
  }
  else if (HelpType == 1)
  {
    v10 = Get(HelpID, 0);
    if (DrawMode == 2)
      goto LABEL_24;
  }
  else if (HelpType)
  {
    v10 = 0;
    if (DrawMode == 2)
    {
LABEL_24:
      v13 = Replace_5267216(v10, "\n", "");
      v11 = "<AF_DEL>";
      v12 = "";
      return Replace_5267216(v13, v11, v12);
    }
  }
  else
  {
    v10 = Get(HelpID, 0);
    if (DrawMode == 2)
      goto LABEL_24;
  }
  if (DrawMode == 1)
  {
    v15 = IndexOf_5260384(v10, "<AF_DEL>");
    if (v15 != -1)
      return Substring_5248048(v10, 0, v15);
  }
  else if (!DrawMode)
  {
    v11 = "<AF_DEL>";
    v12 = "";
    v13 = v10;
    return Replace_5267216(v13, v11, v12);
  }
  return v10;
}

// 0x13a6350
_FRQ *frwGetNumFontFRQ(s32 X, s32 Y, s32 Pri, u32 Color, u8 **pStr, _FRQ *pFRQ) {
  System_String_o *v13;
  System_Byte_array *v16;
  _FRQ_o *v19;
  _FRQ_o *v22;
  _FRQ_o *prev;
  struct _TEXT_o *i;

  v13 = "";
  v16 = EncodingSJIS(v13);
  v19 = frLinkFontString_20580272(v16, 0, 0, 0, pFRQ);
  gModeFlag &= ~2u;
  v22 = frSetFontString_20554176(pStr, 3, 0, 0, v19);
  gModeFlag |= 2u;
  v22->x = X;
  v22->y = Y;
  v22->priority = Pri & 0xFFFFFFF;
  if (v22)
  {
    prev = v22;
    do
    {
      for (i = prev->str; i; i = i->next)
        i->color = Color;
      prev = prev->prev;
    }
    while (prev);
  }
  return v22;
}

// 0x13a6550
_FRQ *frwGetNumFontFRQ_20604240(s32 X, s32 Y, s32 Pri, u32 Color, char *pStr, _FRQ *pFRQ) {
  System_Byte_array *v14;

  v14 = UnicodeToIndexByte(txtMgr, pStr);
  return frwGetSmallFontFRQ2(X, Y, Pri, Color, v14, pFRQ);
}

// 0x13a6610
_FRQ *frwGetSmallCaptionFontFRQ(s32 X, s32 Y, s32 Pri, u32 Color, u8 pStr, _FRQ *pFRQ) {
  return pFRQ;
}

// 0x13a5800
_FRQ *frwGetSmallFont1FRQ(s32 X, s32 Y, s32 Pri, u32 Color, u8 pStr, _FRQ *pFRQ) {
  return pFRQ;
}

// 0x13a5200
_FRQ *frwGetSmallFontFRQ(s32 X, s32 Y, s32 Pri, u32 Color, u8 **pStr, _FRQ *pFRQ) {
  _FRQ_o *v7;

  return frwGetFontEx(X, Y, Pri, Color, pStr, 1, 0, v7, -1);
}

// 0x13a5d80
_FRQ *frwGetSmallFontFRQ2(s32 X, s32 Y, s32 Pri, u32 Color, u8 **pStr, _FRQ *pFRQ) {
  System_Byte_array *v9;
  il2cpp_array_size_t max_length;
  System_Byte_array *v13;
  s32 v15;
  s64 v16;
  s32 v18;
  s64 v20;
  u8 v22;
  u32 v23;
  _FRQ_o *v30;
  _FRQ_o *prev;
  struct _TEXT_o *i;
  _FRQ_o *result;
  struct _FRQ_o *head;

  v9 = NewSpecific(byte, 0x400u);
  max_length = pStr->max_length;
  v13 = v9;
  v9->m_Items[max_length] = 0;
  if (max_length >= 1)
  {
    v15 = 0;
    do
    {
      v16 = v15;
      v18 = pStr->m_Items[v15];
      if (v18 < 0)
      {
        v20 = v15 + 1LL;
        v22 = pStr->m_Items[v20];
        v23 = v9->max_length;
        if ((v22 | (v18 << 8)) == 0xFFFF)
        {
          LOBYTE(v18) = 0x80;
          v9->m_Items[v15] = 0x80;
          v16 = v15 + 1LL;
        }
        else
        {
          v9->m_Items[v15] = v18;
          v16 = v15 + 1LL;
          LOBYTE(v18) = v22;
        }
        ++v15;
      }
      else      ++v15;
      v9->m_Items[v16] = v18;
    }
    while (v15 < max_length);
  }
LABEL_31:
  gModeFlag |= 1u;
  gModeFlag &= ~2u;
  v30 = frLinkFontString_20580272(v13, 1, 0, 0, 0);
  gModeFlag |= 2u;
  gModeFlag &= ~1u;
  v30->x = X;
  v30->y = Y;
  v30->priority = Pri & 0xFFFFFFF;
  if (v30)
  {
    prev = v30;
    do
    {
      for (i = prev->str; i; i = i->next)
        i->color = Color;
      prev = prev->prev;
    }
    while (prev);
    if (pFRQ)
      result = pFRQ;
    else
      result = v30;
    if (pFRQ)
    {
      pFRQ->next = v30->head;
      head = v30->head;
      if (pFRQ->str)
        head->prev = pFRQ;
      else
        head->prev = pFRQ->prev;
      v30->head = pFRQ->head;
      return v30;
    }
  }
  else if (pFRQ)
  {
    return pFRQ;
  }
  else
  {
    return 0;
  }
  return result;
}

// 0x13a6190
_FRQ *frwGetSmallFontFRQ2_20603280(s32 X, s32 Y, s32 Pri, u32 Color, char *pStr, _FRQ *pFRQ) {
  System_Byte_array *v14;

  v14 = UnicodeToIndexByte(txtMgr, pStr);
  return frwGetSmallFontFRQ2(X, Y, Pri, Color, v14, pFRQ);
}

// 0x13a5cc0
_FRQ *frwGetSmallFontFRQ_20602048(s32 X, s32 Y, s32 Pri, u32 Col, char *pStr, _FRQ *pFRQ, s32 ftype) {
  System_Byte_array *v14;
  s32 v15;
  _FRQ_o *v16;

  v14 = UnicodeToIndexByte(txtMgr, pStr);
  return frwGetFontEx(X, Y, v15, Col, v14, 1, 0, v16, ftype);
}

// 0x13a6250
_FRQ *frwGetSmallFontNoPropFRQ(s32 X, s32 Y, s32 Pri, u32 Color, u8 **pStr, _FRQ *pFRQ) {
  _FRQ_o *v7;

  return frwGetFontEx(X, Y, Pri, Color, pStr, 3, 1, v7, -1);
}

// 0x13a6280
_FRQ *frwGetSmallNumFontFRQ(s32 X, s32 Y, s32 Pri, u32 Color, u8 **pStr, _FRQ *pFRQ) {
  return pFRQ;
}

// 0x13a6290
_FRQ *frwGetSmallNumFontFRQ_20603536(s32 X, s32 Y, s32 Pri, u32 Color, char *pStr, _FRQ *pFRQ) {
  System_Byte_array *v14;

  v14 = UnicodeToIndexByte(txtMgr, pStr);
  return frwGetSmallFontFRQ2(X, Y, Pri, Color, v14, pFRQ);
}

// 0x13a57c0
_FRQ *frwGetStaffFontFRQ(s32 X, s32 Y, s32 Pri, s32 Style, u32 Space, u32 WhiteSpaceW, u32 Color, u8 pStr, _FRQ *pFRQ) {
  return 0;
}

// 0x13a5380
void frwLoadStaffFont(void) {
  ;
}

// 0x13a57f0
void frwStrExchgStyle(u8 **pDst, u8 **pSrc) {
  ;
}
