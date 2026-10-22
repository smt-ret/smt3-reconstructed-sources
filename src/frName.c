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
LABEL_26:
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
LABEL_18:
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
LABEL_18:
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
LABEL_22:
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
  return Concat_5221536(Name1NString, " ", Name2NString);
}

// 0x13a36f0
void frInitNameData(void) {
  u64 *v1;
  u32 v3;
  u64 *v4;
  struct dds3GlobalWork_t_o *DDS3_GBWK;
  struct dds3GlobalWork_t_o *v8;
  struct dds3GlobalWork_t_o *v9;
  struct dds3GlobalWork_t_o *v10;
  u64 i;
  struct System_Int32_array *gNameTransFlag;
  u32 *name_nums;
  s64 *v21;
  s64 *v22;
  u32 *name_code;
  s64 *v25;
  s64 *v26;
  u32 *cname_code;
  s64 *v29;
  s64 *v30;
  u32 *v32;
  s32 v34;
  struct System_Byte_array_array *v35;
  struct System_Byte_array_array *v37;
  System_Byte_array *v39;
  s32 v40;
  struct System_Byte_array_array *v42;
  s32 v43;
  struct System_Byte_array_array *v46;
  System_Byte_array *v48;
  s32 v49;
  struct System_String_array *tblDefCodeName;
  s32 Length;
  struct System_String_array *v56;
  System_Array_o *v58;
  struct System_Byte_array_array *v59;
  struct System_Byte_array *cname_nums;
  s32 v63;
  u64 j;
  struct System_String_array_array *v66;
  struct System_String_array_array *v69;
  TextManager_o *txtMgr;
  struct System_String_array_array *tblDefName;
  System_String_array *v76;
  System_String_o *v77;
  System_String_array *v78;
  System_String_o *LocalizeText;
  System_Byte_array *v83;
  s32 max_length;
  struct System_Byte_array_array *v86;
  struct System_Byte_array_array *v89;
  System_Byte_array *v91;
  s32 v92;
  TextManager_o *v96;
  struct System_String_array_array *v97;
  System_String_array *v99;
  System_String_o *v101;
  System_String_o *v102;
  System_String_array *v104;
  System_Byte_array *v107;
  s32 v108;
  struct System_Byte_array_array *v110;
  struct System_Byte_array_array *v113;
  System_Byte_array *v115;
  s32 v116;
  TextManager_o *v121;
  struct System_String_array *v122;
  System_Byte_array *v124;
  struct System_Byte_array_array *v125;
  s32 v126;
  struct System_Byte_array *v128;
  s32 v129;
  s32 v130;
  char *v132;

  v1 = NewSpecific(byte, 2u);
  v3 = *(v1 + 6);
  v4 = v1;
  *(v1 + 32) = 0x80;
  *(v1 + 33) = 0x80;
  DDS3_GBWK->name_nums = NewSpecific(byte__, 4u);
  v8 = DDS3_GBWK;
  v8->name_code = NewSpecific(byte__, 4u);
  v9 = DDS3_GBWK;
  v9->cname_nums = NewSpecific(byte, 4u);
  v10 = DDS3_GBWK;
  v10->cname_code = NewSpecific(byte__, 4u);
  for (i = 0; i != 4; ++i)
  {
    gNameTransFlag->m_Items[i] = 0;
    name_nums = DDS3_GBWK->name_nums;
    v21 = NewSpecific(byte, 2u);
    v22 = v21;
    *&name_nums[2 * i + 8] = v22;
    name_code = DDS3_GBWK->name_code;
    v25 = NewSpecific(byte, 0x10u);
    v26 = v25;
    *&name_code[2 * i + 8] = v26;
    cname_code = DDS3_GBWK->cname_code;
    v29 = NewSpecific(byte, 0x10u);
    v30 = v29;
    v32 = &cname_code[2 * i];
    *(v32 + 4) = v30;
  }
  v34 = *(v4 + 6);
  v35 = DDS3_GBWK->name_code;
  Copy_3886320(v4, v35->m_Items[0], v34);
  v37 = DDS3_GBWK->name_nums;
  v39 = v37->m_Items[0];
  if (v34 >= 0)
    v40 = v34;
  else
    v40 = v34 + 1;
  v39->m_Items[0] = v40 >> 1;
  v42 = DDS3_GBWK->name_code;
  v43 = *(v4 + 6);
  Copy_3880080(v4, 0, v42->m_Items[0], v34, v34);
  v46 = DDS3_GBWK->name_nums;
  v48 = v46->m_Items[0];
  if (v43 >= 0)
    v49 = v43;
  else
    v49 = v43 + 1;
  v48->m_Items[1] = v49 >> 1;
  else
  {
    if (!LODWORD(tblDefCodeName->max_length))
      goto LABEL_58;
  }
  Length = get_Length(tblDefCodeName->m_Items[0]);
  v56 = tblDefCodeName;
  v58 = UnicodeToIndexByte(txtMgr, v56->m_Items[0]);
  v59 = DDS3_GBWK->cname_code;
  Copy_3886320(v58, v59->m_Items[0], Length);
  cname_nums = DDS3_GBWK->cname_nums;
  if (Length >= 0)
    v63 = Length;
  else
    v63 = Length + 1;
  cname_nums->m_Items[0] = v63 >> 1;
  for (j = 0; j != 4; ++j)
  {
    if (j)
    {
      v76 = tblDefName->m_Items[j];
      v77 = v76->m_Items[0];
      LocalizeText = GetLocalizeText(v77);
    }
    else
    {
      else
      {
        v66 = tblDefName;
        if (!LODWORD(v66->max_length))
        {
LABEL_73:
        }
      }
      v78 = v66->m_Items[0];
      LocalizeText = v78->m_Items[0];
    }
    v83 = UnicodeToIndexByte2(txtMgr, LocalizeText);
    max_length = v83->max_length;
    v86 = DDS3_GBWK->name_code;
    Copy_3886320(v83, v86->m_Items[j], max_length);
    v89 = DDS3_GBWK->name_nums;
    v91 = v89->m_Items[j];
    if (max_length >= 0)
      v92 = max_length;
    else
      v92 = max_length + 1;
    v91->m_Items[0] = v92 >> 1;
    if (j)
    {
      v96 = txtMgr;
      v97 = tblDefName;
      v99 = v97->m_Items[j];
      v101 = v99->m_Items[1];
      v102 = GetLocalizeText(v101);
    }
    else
    {
      v96 = txtMgr;
      else
      {
        v69 = tblDefName;
        if (!LODWORD(v69->max_length))
        {
LABEL_76:
        }
      }
      v104 = v69->m_Items[0];
      v102 = v104->m_Items[1];
    }
    v107 = UnicodeToIndexByte2(v96, v102);
    v108 = v107->max_length;
    v110 = DDS3_GBWK->name_code;
    Copy_3880080(v107, 0, v110->m_Items[j], max_length, v108);
    v113 = DDS3_GBWK->name_nums;
    v115 = v113->m_Items[j];
    if (v108 >= 0)
      v116 = v108;
    else
      v116 = v108 + 1;
    v115->m_Items[1] = v116 >> 1;
    v121 = txtMgr;
    v122 = tblDefCodeName;
    v124 = UnicodeToIndexByte2(v121, v122->m_Items[j]);
    v125 = DDS3_GBWK->cname_code;
    v126 = v124->max_length;
    Copy_3886320(v124, v125->m_Items[j], v126);
    v128 = DDS3_GBWK->cname_nums;
    if (v126 >= 0)
      v129 = v126;
    else
      v129 = v126 + 1;
    v130 = v129 >> 1;
    v132 = v128 + j;
    v132[32] = v130;
  }
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
