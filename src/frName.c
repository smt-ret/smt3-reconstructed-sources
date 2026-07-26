#include "types.h"

typedef struct GsFont_t GsFont_t;
typedef struct TextManager TextManager;
typedef struct _FRQ _FRQ;

static s32 NME_NAME_NUMS;
static u32 CMP_PE_NORMAL;
static GsFont_t *gNameStr[2];
static s32 gNameTransFlag[4];
static char *tblDefCodeName[4];
static char *tblDefName[4];

char *GetLocalizeText(char *ID);
u8 **ReplaceSpace(u8 **dat);
u8 **UnicodeToIndexByte(TextManager *this, char *str);
u8 **UnicodeToIndexByte2(TextManager *this, char *str);
_FRQ *frGetName1NFRQ(s8 TargetNo, s8 Style, _FRQ *pFRQ);
char *frGetName1NString(s8 TargetNo);
_FRQ *frGetName2NFRQ(s8 TargetNo, s8 Style, _FRQ *pFRQ);
char *frGetName2NString(s8 TargetNo);
_FRQ *frLinkFontString_20580272(u8 **pStr, s8 Style, s8 ColNo, s8 Tp, _FRQ *pFRQ);

// 0x13a4580
u8 **ReplaceSpace(u8 **dat) {
  System_Byte_array *result;
  il2cpp_array_size_t max_length;
  u64 v5;
  s64 v6;
  u64 v7;
  u64 v8;
  s16 v11;
  u64 max_length_low;

  result = NewSpecific(byte, LODWORD(dat->max_length));
  max_length = dat->max_length;
  if (max_length >= 2)
  {
    v5 = 0;
    v6 = (max_length >> 1) - 1LL;
    v7 = 1;
    v8 = max_length;
    while (1)
    {
      if ((dat->m_Items[v5] | (dat->m_Items[v5 + 1] << 8)) == 0xFFFF)
        v11 = 12288;
      else
        v11 = dat->m_Items[v5] | (dat->m_Items[v5 + 1] << 8);
      max_length_low = LODWORD(result->max_length);
      result->m_Items[v5] = v11;
      result->m_Items[v5 + 1] = HIBYTE(v11);
      if (!v6)
        break;
      v5 += 2LL;
      --v6;
      v7 = v5 + 1;
      v8 = LODWORD(dat->max_length);
    }
  }
  return result;
}

// 0x13a4290
_FRQ *frCreateNameHandle(s8 TargetNo, s8 Style, _FRQ *pFRQ) {
  struct System_Byte_array_array *name_nums;
  u32 v9;
  s64 v10;
  struct System_Byte_array_array *v13;
  struct System_Byte_array_array *v16;
  System_Byte_array *v18;
  s64 v20;
  System_Array_o *v21;
  struct System_Byte_array_array *name_code;
  System_Array_o *v23;
  _FRQ_o *v30;

  name_nums = DDS3_GBWK->name_nums;
  v9 = TargetNo;
  v10 = TargetNo;
  v13 = DDS3_GBWK->name_nums;
  v16 = DDS3_GBWK->name_nums;
  v18 = v16->m_Items[v10];
  v20 = 2LL * v18->m_Items[0];
  v21 = NewSpecific(byte, v20 | 1);
  name_code = DDS3_GBWK->name_code;
  v23 = v21;
  Copy_3886320(name_code->m_Items[v10], v21, v20);
  *(&v23[2].klass + v20) = 0;
  gModeFlag |= 1u;
  v30 = frLinkFontString_20580272(v23, Style, 0, 0, pFRQ);
  gModeFlag &= ~1u;
  return v30;
}

// 0x139eb50
_FRQ *frGetCNameFRQ(s8 TargetNo, s8 Style, _FRQ *pFRQ) {
  struct System_Byte_array *cname_nums;
  System_Array_o *v9;
  struct dds3GlobalWork_t_o *DDS3_GBWK;
  struct System_Byte_array_array *cname_code;
  System_Array_o *v12;
  struct System_Byte_array *v13;
  System_Array_o *v14;
  struct System_Byte_array *v17;
  s64 v19;
  _FRQ_o *v23;

  cname_nums = DDS3_GBWK->cname_nums;
  v9 = NewSpecific(byte, (2LL * cname_nums->m_Items[0]) | 1);
  cname_code = DDS3_GBWK->cname_code;
  v12 = v9;
  v13 = DDS3_GBWK->cname_nums;
  v14 = cname_code->m_Items[0];
  Copy_3886320(v14, v9, 2 * v13->m_Items[0]);
  v17 = DDS3_GBWK->cname_nums;
  v19 = 2LL * v17->m_Items[0];
  *(&v12[2].klass + v19) = 0;
  gModeFlag |= 1u;
  v23 = frLinkFontString_20580272(v12, Style, 0, 0, pFRQ);
  gModeFlag &= ~1u;
  return v23;
}

// 0x139e230
char *frGetCNameString(s8 TargetNo) {
  struct System_Byte_array *cname_nums;
  u32 v5;
  s64 v6;
  s64 v8;
  System_Array_o *v9;
  struct System_Byte_array_array *cname_code;
  System_Byte_array *v11;
  System_Text_Encoding_o *Unicode;
  System_Byte_array *v15;

  cname_nums = DDS3_GBWK->cname_nums;
  v5 = TargetNo;
  v6 = TargetNo;
  v8 = 2LL * cname_nums->m_Items[TargetNo];
  v9 = NewSpecific(byte, v8);
  cname_code = DDS3_GBWK->cname_code;
  v11 = v9;
  Copy_3880080(cname_code->m_Items[v6], 0, v9, 0, v8);
  Unicode = get_Unicode();
  v15 = ReplaceSpace(v11);
  return (Unicode->klass[1]._1.byval_arg.data)(Unicode, v15, *&Unicode->klass[1]._1.byval_arg.bits);
}

// 0x139e650
_FRQ *frGetName1NFRQ(s8 TargetNo, s8 Style, _FRQ *pFRQ) {
  struct System_Byte_array_array *name_nums;
  u32 v9;
  s64 v10;
  System_Byte_array *v12;
  s64 v14;
  System_Array_o *v15;
  struct System_Byte_array_array *name_code;
  System_Array_o *v17;
  _FRQ_o *v24;

  name_nums = DDS3_GBWK->name_nums;
  v9 = TargetNo;
  v10 = TargetNo;
  v12 = name_nums->m_Items[TargetNo];
  v14 = 2LL * v12->m_Items[0];
  v15 = NewSpecific(byte, v14 | 1);
  name_code = DDS3_GBWK->name_code;
  v17 = v15;
  Copy_3886320(name_code->m_Items[v10], v15, v14);
  *(&v17[2].klass + v14) = 0;
  gModeFlag |= 1u;
  v24 = frLinkFontString_20580272(v17, Style, 0, 0, pFRQ);
  gModeFlag &= ~1u;
  return v24;
}

// 0x139dee0
char *frGetName1NString(s8 TargetNo) {
  struct System_Byte_array_array *name_nums;
  u32 v5;
  s64 v6;
  System_Byte_array *v8;
  s32 v10;
  System_Array_o *v11;
  struct System_Byte_array_array *name_code;
  System_Byte_array *v13;
  System_Text_Encoding_o *Unicode;
  System_Byte_array *v17;

  name_nums = DDS3_GBWK->name_nums;
  v5 = TargetNo;
  v6 = TargetNo;
  v8 = name_nums->m_Items[TargetNo];
  v10 = 2 * v8->m_Items[0];
  v11 = NewSpecific(byte, 2LL * v8->m_Items[0]);
  name_code = DDS3_GBWK->name_code;
  v13 = v11;
  Copy_3880080(name_code->m_Items[v6], 0, v11, 0, v10);
  Unicode = get_Unicode();
  v17 = ReplaceSpace(v13);
  return (Unicode->klass[1]._1.byval_arg.data)(Unicode, v17, *&Unicode->klass[1]._1.byval_arg.bits);
}

// 0x139e8a0
_FRQ *frGetName2NFRQ(s8 TargetNo, s8 Style, _FRQ *pFRQ) {
  struct System_Byte_array_array *name_nums;
  u32 v9;
  s64 v10;
  System_Byte_array *v12;
  struct System_Byte_array_array *v14;
  s32 v15;
  s32 v17;
  System_Byte_array *v18;
  s64 v20;
  System_Array_o *v21;
  struct System_Byte_array_array *name_code;
  System_Array_o *v23;
  _FRQ_o *v30;

  name_nums = DDS3_GBWK->name_nums;
  v9 = TargetNo;
  v10 = TargetNo;
  v12 = name_nums->m_Items[TargetNo];
  v14 = DDS3_GBWK->name_nums;
  v15 = v12->m_Items[0];
  v17 = 2 * v15;
  v18 = v14->m_Items[v10];
  v20 = 2LL * v18->m_Items[1];
  v21 = NewSpecific(byte, v20 | 1);
  name_code = DDS3_GBWK->name_code;
  v23 = v21;
  Copy_3880080(name_code->m_Items[v10], v17, v21, 0, v20);
  *(&v23[2].klass + v20) = 0;
  gModeFlag |= 1u;
  v30 = frLinkFontString_20580272(v23, Style, 0, 0, pFRQ);
  gModeFlag &= ~1u;
  return v30;
}

// 0x139e060
char *frGetName2NString(s8 TargetNo) {
  struct System_Byte_array_array *name_nums;
  u32 v5;
  s64 v6;
  System_Byte_array *v8;
  struct System_Byte_array_array *v10;
  s32 v11;
  System_Byte_array *v13;
  s32 v14;
  s32 v16;
  System_Array_o *v17;
  struct System_Byte_array_array *name_code;
  System_Byte_array *v19;
  System_Text_Encoding_o *Unicode;
  System_Byte_array *v23;

  name_nums = DDS3_GBWK->name_nums;
  v5 = TargetNo;
  v6 = TargetNo;
  v8 = name_nums->m_Items[TargetNo];
  v10 = DDS3_GBWK->name_nums;
  v11 = v8->m_Items[0];
  v13 = v10->m_Items[v6];
  v14 = 2 * v11;
  v16 = 2 * v13->m_Items[1];
  v17 = NewSpecific(byte, 2LL * v13->m_Items[1]);
  name_code = DDS3_GBWK->name_code;
  v19 = v17;
  Copy_3880080(name_code->m_Items[v6], v14, v17, 0, v16);
  Unicode = get_Unicode();
  v23 = ReplaceSpace(v19);
  return (Unicode->klass[1]._1.byval_arg.data)(Unicode, v23, *&Unicode->klass[1]._1.byval_arg.bits);
}

// 0x139e570
_FRQ *frGetNameFRQ(s8 TargetNo, s8 Style, _FRQ *pFRQ) {
  _FRQ_o *Name1NFRQ;
  struct _TEXT_o *str_end;

  Name1NFRQ = frGetName1NFRQ(TargetNo, Style, pFRQ);
  str_end = Name1NFRQ->str_end;
  Name1NFRQ->w_pxls += 8;
  str_end->lw += 8;
  return frGetName2NFRQ(TargetNo, Style, Name1NFRQ);
}

// 0x139de50
char *frGetNameString(s8 TargetNo) {
  System_String_o *Name1NString;
  System_String_o *Name2NString;

  Name1NString = frGetName1NString(TargetNo);
  Name2NString = frGetName2NString(TargetNo);
  return Concat_5221536(Name1NString, StringLiteral_212, Name2NString);
}

// 0x13a36f0
void frInitNameData(void) {
    UnicodeToIndexByte(0, 0);
    GetLocalizeText(0);
    UnicodeToIndexByte2(0, 0);
}

// 0x139fbb0
void frRestoreNameImage(s8 TargetNo) {
  ;
}

// 0x13a4270
void frSetNameData(s8 TargetNo, s8 Type, s8 ImageNums, u8 **pData) {
  ;
}

// 0x13a4280
void frTransNameImage(s8 TargetNo, s8 Type) {
  ;
}
