#include "types.h"

typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;

static char *DispUnit1_bad[13];
static s32 kotowaricur;
static s32 kotowarimax;
static char *kotowari_str[8];

bool DDS3_PAD2CHECK_REP(s32 id);
void DispList(s32 x, s32 y, sdfDrawTag_t *tag);
void DispUnit1(s32 i, s32 x, s32 y, sdfDrawTag_t *tag);
void dds3ConsPanelTagLink(sdfDrawTag_t *tag, s32 x, s32 y, s32 sx, s32 sy);
s32 dds3SelectMenu(s32 pad, s32 listsx, s32 listsy, s32 winsx, s32 winsy, s32 *basex, s32 *basey, s32 *x, s32 *y);
void *sdfDevPrintf(s32 aX, s32 aY, u32 aZ, s32 aAttr, char *aStr, void **LegacyParamArray);
s32 sdfDrawTagInit(sdfDrawTag_t *a);
void sdfDrawTagLink(sdfDrawTag_t *aTag, void *aPacket);
s32 sdfDrawTagLinkOt(s32 a, sdfDrawTag_t *b);

// 0xcc97c0
void DispList(s32 x, s32 y, sdfDrawTag_t *tag) {
  s64 stockcnt;
  s32 v9;
  System_Object_array *v10;
  s64 *v11;
  s64 *v13;
  s32 v14;
  Il2CppObject *v17;
  System_Object_array *v18;
  Il2CppObject *v19;
  s32 v20;
  s64 i;
  u64 v23;
  s32 v24;
  System_Object_array *v26;
  struct System_Int32_array *stocklist;
  s64 *v30;
  s64 *v32;
  Il2CppObject *v35;
  struct System_Int32_array *v36;
  s32 v38;
  s32 v39;
  s32 v41;
  s32 v42;

  stockcnt = DDS3_GBWK->stockcnt;
  v9 = 96 * y;
  v42 = DDS3_GBWK->stockcnt;
  v10 = NewSpecific(object, 1u);
  v11 = sub_8D3950(s32, &v42);
  v13 = v11;
  v14 = 192 * x + 28672;
  v10->m_Items[0] = v13;
  v17 = sdfDevPrintf(v14, v9 + 30976, 0xFEFFFFu, 0, "STOCKCNT :{0}", v10);
  sdfDrawTagLink(tag, v17);
  v18 = Empty_string_();
  v19 = sdfDevPrintf(v14, v9 + 30984, 0xFEFFFFu, 0, "STOCKLIST:", v18);
  sdfDrawTagLink(tag, v19);
  v20 = v9 + 30992;
  for (i = 8; i != 24; ++i)
  {
    v23 = i - 8;
    if (i - 8 >= stockcnt)
      v24 = 14;
    else
      v24 = 5;
    v26 = NewSpecific(object, 1u);
    stocklist = DDS3_GBWK->stocklist;
    v41 = *(&stocklist->obj.klass + i);
    v30 = sub_8D3950(s32, &v41);
    v32 = v30;
    v26->m_Items[0] = v32;
    v35 = sdfDevPrintf(v14, v20, 0xFEFFFFu, v24, "{0}", v26);
    sdfDrawTagLink(tag, v35);
    v36 = DDS3_GBWK->stocklist;
    v38 = *(&v36->obj.klass + i);
    if (v38 >= 10)
      v39 = 576;
    else
      v39 = 384;
    v14 += v39;
  }
}

// 0xcc9b90
void DispUnit1(s32 i, s32 x, s32 y, sdfDrawTag_t *tag) {
  struct datUnitWork_t_array *unitwork;
  datUnitWork_t_o *v12;
  s32 v13;
  System_Object_array *v14;
  s64 *v15;
  s64 *v17;
  s32 v18;
  Il2CppObject *v21;
  System_String_array *v23;
  System_String_o *v24;
  s32 v25;
  s32 v26;
  s32 v27;
  System_Object_array *v28;
  System_Object_array *v29;
  System_Object_array *v30;
  s64 *v31;
  s64 *v33;
  Il2CppObject *v36;
  System_Object_array *v38;
  Il2CppObject *v40;
  System_Object_array *v41;
  s64 *v42;
  s64 *v44;
  Il2CppObject *v47;
  System_Object_array *v48;
  s64 *v49;
  s64 *v50;
  s64 *v52;
  s64 *v53;
  Il2CppObject *v56;
  System_Object_array *v57;
  s64 *v58;
  s64 *v59;
  s64 *v61;
  s64 *v62;
  Il2CppObject *v65;
  u16 badstatus;
  u32 v67;
  u64 *v74;
  struct System_String_array *DispUnit1_bad;
  s64 *v78;
  Il2CppObject *v81;
  u16 maxmp;
  u16 v84[2];
  u16 maxhp;
  u16 v86[2];
  s32 v87;

  unitwork = DDS3_GBWK->unitwork;
  v12 = unitwork->m_Items[i];
  v13 = 192 * x;
  v87 = i;
  v14 = NewSpecific(object, 1u);
  v15 = sub_8D3950(s32, &v87);
  v17 = v15;
  v18 = 96 * y + 30976;
  v14->m_Items[0] = v17;
  v21 = sdfDevPrintf(v13 + 28672, v18, 0xFEFFFFu, 0, "[{0, 2}] ", v14, 0);
  sdfDrawTagLink(tag, v21);
  if ((v12->flag & 1) != 0)
  {
    v29 = NewSpecific(object, 1u);
    LOWORD(v87) = v12->id;
    v30 = v29;
    v31 = sub_8D3950(ushort, &v87);
    v33 = v31;
    v30->m_Items[0] = v33;
    v36 = sdfDevPrintf(v13 + 29632, v18, 0xFEFFFFu, 0, "{0:X3} ", v30);
    sdfDrawTagLink(tag, v36);
    if ((v12->flag & 2) != 0)
    {
      v38 = Empty_string_();
      v40 = sdfDevPrintf(v13 + 30400, v18, 0xFEFFFFu, 5, "P", v38);
      sdfDrawTagLink(tag, v40);
    }
    v41 = NewSpecific(object, 1u);
    LOWORD(v87) = v12->level;
    v42 = sub_8D3950(ushort, &v87);
    v44 = v42;
    v41->m_Items[0] = v44;
    v47 = sdfDevPrintf(v13 + 30784, v18, 0xFEFFFFu, 0, "{0, 3}", v41, 0);
    sdfDrawTagLink(tag, v47);
    v48 = NewSpecific(object, 2u);
    v86[0] = v12->hp;
    v49 = sub_8D3950(ushort, v86);
    v50 = v49;
    v48->m_Items[0] = v50;
    maxhp = v12->maxhp;
    v52 = sub_8D3950(ushort, &maxhp);
    v53 = v52;
    v48->m_Items[1] = v53;
    v56 = sdfDevPrintf(v13 + 31552, v18, 0xFEFFFFu, 0, "%3d/%3d", v48);
    sdfDrawTagLink(tag, v56);
    v57 = NewSpecific(object, 2u);
    v84[0] = v12->mp;
    v58 = sub_8D3950(ushort, v84);
    v59 = v58;
    v57->m_Items[0] = v59;
    maxmp = v12->maxmp;
    v61 = sub_8D3950(ushort, &maxmp);
    v62 = v61;
    v57->m_Items[1] = v62;
    v65 = sdfDevPrintf(v13 + 33088, v18, 0xFEFFFFu, 0, "%3d/%3d", v57);
    sdfDrawTagLink(tag, v65);
    badstatus = v12->badstatus;
    v67 = 0;
    if ((badstatus & 1) == 0)
    {
      if ((badstatus & 2) != 0)
      {
        v67 = 1;
      }
      else if ((badstatus & 4) != 0)
      {
        v67 = 2;
      }
      else if ((badstatus & 8) != 0)
      {
        v67 = 3;
      }
      else if ((badstatus & 0x10) != 0)
      {
        v67 = 4;
      }
      else if ((badstatus & 0x20) != 0)
      {
        v67 = 5;
      }
      else if ((badstatus & 0x40) != 0)
      {
        v67 = 6;
      }
      else if ((badstatus & 0x80) != 0)
      {
        v67 = 7;
      }
      else if ((v12->badstatus & 0x100) != 0)
      {
        v67 = 8;
      }
      else if ((v12->badstatus & 0x200) != 0)
      {
        v67 = 9;
      }
      else if ((v12->badstatus & 0x400) != 0)
      {
        v67 = 10;
      }
      else if ((v12->badstatus & 0x800) != 0)
      {
        v67 = 11;
      }
      else
      {
        v67 = 12;
      }
    }
    v74 = NewSpecific(object, 1u);
    v78 = DispUnit1_bad->m_Items[v67];
    v74[4] = v78;
    v24 = "{0}";
    v25 = v13 + 34624;
    v26 = v18;
    v27 = 0;
    v28 = v74;
  }
  else
  {
    v23 = Empty_string_();
    v24 = "EMPTY";
    v25 = v13 + 29632;
    v26 = v18;
    v27 = 14;
    v28 = v23;
  }
  v81 = sdfDevPrintf(v25, v26, 0xFEFFFFu, v27, v24, v28);
  sdfDrawTagLink(tag, v81);
}

// 0xcca6e0
dds3ProcessFunc_t *datDebugKotowariProcess(dds3ProcessID_t *id) {
  u64 *v2;
  System_Object_array *v5;
  Il2CppObject *v6;
  u64 v8;
  s32 v9;
  s32 v12;
  System_Object_array *v14;
  struct System_String_array *v16;
  s64 *v18;
  struct System_Byte_array *kotowari;
  s32 v23;
  struct System_String_array *kotowari_str;
  s64 *v26;
  struct System_Byte_array *negoques;
  s64 *v31;
  s64 *v33;
  Il2CppObject *v36;
  u64 *v40;
  struct sdfGrOt_t_array *dds3Ot;
  struct sdfGrOt_t_array *v46;
  struct System_Byte_array *v54;
  s64 v55;
  struct System_Byte_array *v57;
  s64 kotowaricur;
  struct System_Byte_array *v64;
  s64 v65;
  struct System_Byte_array *v67;
  s64 v68;
  struct System_Byte_array *v74;
  s64 v75;
  struct System_Byte_array *v77;
  s64 v78;
  struct System_Byte_array *v84;
  s64 v85;
  struct System_Byte_array *v87;
  s64 v88;
  s32 v93;
  s32 x;
  s32 basey;
  s32 basex;

  basex = 25;
  x = 0;
  basey = 5;
  v2 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v2);
  sdfDrawTagInit(v2);
  x = 25;
  v5 = Empty_string_();
  v6 = sdfDevPrintf(33472, 31456, 0xFEFFFFu, 14, "KOTOWARI EDIT", v5);
  sdfDrawTagLink(v2, v6);
  v8 = 0;
  v9 = 31552;
  {
LABEL_12:
  }
  while (1)
  {
    if (v8 >= kotowarimax)
      break;
    v12 = 4 * (v8 == kotowaricur);
    v14 = NewSpecific(object, 2u);
    if (v8 <= 3)
    {
      v26 = kotowari_str->m_Items[v8];
      v14->m_Items[0] = v26;
      negoques = DDS3_GBWK->negoques;
      v23 = negoques->m_Items[v8];
    }
    else
    {
      v16 = kotowari_str;
      v18 = v16->m_Items[v8];
      v14->m_Items[0] = v18;
      kotowari = DDS3_GBWK->kotowari;
      v23 = *(&kotowari->max_length + v8 + 4);
    }
    v93 = v23;
    v31 = sub_8D3950(s32, &v93);
    v33 = v31;
    v14->m_Items[1] = v33;
    v36 = sdfDevPrintf(33856, v9, 0xFEFFFFu, v12, "{0}  {1, 3}", v14, 0);
    sdfDrawTagLink(v2, v36);
    v9 += 96;
    ++v8;
      goto LABEL_12;
  }
  v40 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v40);
  sdfDrawTagInit(v40);
  dds3ConsPanelTagLink(v40, 12 * basex, 12 * basey - 6, 15, 6 - basey);
  sdfDrawTagLinkOt(dds3Ot->m_Items[81], v40);
  v46 = dds3Ot;
  sdfDrawTagLinkOt(v46->m_Items[81], v2);
  if (dds3SelectMenu(1, 1, kotowarimax, 1, kotowarimax, &basex, &basey, &x, &kotowaricur) == -1)
  {
    id->func_ans = -1;
    return 0;
  }
  else if (!DDS3_PAD2CHECK_REP(4))
  {
    goto LABEL_105;
  }
  if (kotowaricur > 3)
  {
    v54 = DDS3_GBWK->kotowari;
    v55 = kotowaricur - 4LL;
    v54->m_Items[v55] -= 10;
    if ((kotowaricur - 4) < LODWORD(DDS3_GBWK->kotowari->max_length))
      goto LABEL_105;
LABEL_103:
  }
  v57 = DDS3_GBWK->negoques;
  --v57->m_Items[kotowaricur];
  if (kotowaricur >= LODWORD(DDS3_GBWK->negoques->max_length))
    goto LABEL_103;
LABEL_105:
  else if (!DDS3_PAD2CHECK_REP(5))
  {
    goto LABEL_133;
  }
  if (kotowaricur > 3)
  {
    v64 = DDS3_GBWK->kotowari;
    v65 = kotowaricur - 4LL;
    ++v64->m_Items[v65];
    if ((kotowaricur - 4) < LODWORD(DDS3_GBWK->kotowari->max_length))
      goto LABEL_133;
LABEL_131:
  }
  v67 = DDS3_GBWK->negoques;
  v68 = kotowaricur;
  ++v67->m_Items[v68];
  if (kotowaricur >= LODWORD(DDS3_GBWK->negoques->max_length))
    goto LABEL_131;
LABEL_133:
  else if (!DDS3_PAD2CHECK_REP(8))
  {
    goto LABEL_161;
  }
  if (kotowaricur > 3)
  {
    v74 = DDS3_GBWK->kotowari;
    v75 = kotowaricur - 4LL;
    v74->m_Items[v75] -= 10;
    if ((kotowaricur - 4) < LODWORD(DDS3_GBWK->kotowari->max_length))
      goto LABEL_161;
LABEL_159:
  }
  v77 = DDS3_GBWK->negoques;
  v78 = kotowaricur;
  v77->m_Items[v78] -= 10;
  if (kotowaricur >= LODWORD(DDS3_GBWK->negoques->max_length))
    goto LABEL_159;
LABEL_161:
  else if (!DDS3_PAD2CHECK_REP(10))
  {
    return 0;
  }
  if (kotowaricur > 3)
  {
    v84 = DDS3_GBWK->kotowari;
    v85 = kotowaricur - 4LL;
    v84->m_Items[v85] += 10;
    if ((kotowaricur - 4) < LODWORD(DDS3_GBWK->kotowari->max_length))
      return 0;
LABEL_187:
  }
  v87 = DDS3_GBWK->negoques;
  v88 = kotowaricur;
  v87->m_Items[v88] += 10;
  if (kotowaricur >= LODWORD(DDS3_GBWK->negoques->max_length))
    goto LABEL_187;
  return 0;
}

// 0xcca480
dds3ProcessFunc_t *datDebugUnitProcess(dds3ProcessID_t *id) {
  u64 *v2;
  System_Object_array *v7;
  Il2CppObject *v8;
  s32 i;
  u64 *v12;
  struct sdfGrOt_t_array *dds3Ot;
  struct sdfGrOt_t_array *v18;

  v2 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v2);
  sdfDrawTagInit(v2);
  DispList(2, 10, v2);
  v7 = Empty_string_();
  v8 = sdfDevPrintf(29056, 32320, 0xFEFFFFu, 4, "     ID     LV  HP       MP     STAT", v7);
  sdfDrawTagLink(v2, v8);
  for (i = 0; i != 16; ++i)
  {
    DispUnit1(i, 2, i + 15, v2);
  }
  v12 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v12);
  sdfDrawTagInit(v12);
  dds3ConsPanelTagLink(v12, 24, 114, 37, 23);
  sdfDrawTagLinkOt(dds3Ot->m_Items[81], v12);
  v18 = dds3Ot;
  sdfDrawTagLinkOt(v18->m_Items[81], v2);
  return 0;
}
