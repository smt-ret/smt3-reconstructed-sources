#include "types.h"

typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;

static s32 base;
static s32 x;
static s32 y;
static void *strbuf;

bool DDS3_PAD2CHECK_REP(s32 id);
char *ToZenkaku(char *istr);
void dds3ConsPanelTagLink(sdfDrawTag_t *tag, s32 x, s32 y, s32 sx, s32 sy);
s32 dds3SelectMenu(s32 pad, s32 listsx, s32 listsy, s32 winsx, s32 winsy, s32 *basex, s32 *basey, s32 *x, s32 *y);
bool evtBitCheck(s32 no);
void evtBitOff(s32 no);
void evtBitOn(s32 no);
void *sdfDevPrintf(s32 aX, s32 aY, u32 aZ, s32 aAttr, char *aStr, void **LegacyParamArray);
s32 sdfDrawTagInit(sdfDrawTag_t *a);
void sdfDrawTagLink(sdfDrawTag_t *aTag, void *aPacket);
s32 sdfDrawTagLinkOt(s32 a, sdfDrawTag_t *b);

// 0x1352630
dds3ProcessFunc_t *dds3BitEditorProcess(dds3ProcessID_t *id) {
  System_Object_array *v4;
  Il2CppObject *v5;
  s32 y;
  s32 x;
  bool v11;
  System_String_o *v12;
  s64 *v13;
  System_String_o *v14;
  System_Object_array *v16;
  Il2CppObject *v18;
  s32 v23;
  System_Text_StringBuilder_o *strbuf;
  bool v27;
  s64 *v28;
  System_Text_StringBuilder_o *v31;
  u16 Chars;
  System_String_o *v33;
  System_Object_array *v35;
  Il2CppObject *v37;
  s32 i;
  System_Text_StringBuilder_o *v42;
  s64 *v43;
  System_Text_StringBuilder_o *v46;
  u64 *v47;
  System_String_o *v49;
  System_String_o *v50;
  s32 v53;
  evtBitEditor_c *v56;
  System_String_o *v58;
  System_String_o *v60;
  System_String_o *v62;
  System_Object_array *v64;
  Il2CppObject *v66;
  struct sdfGrOt_t_array *dds3Ot;
  sdfGrOt_t_o *v70;
  s32 base;
  s32 v81;
  s32 v84;
  bool v88;
  sdfDrawTag_t_o *aTag;
  s32 v93;
  s32 basex[2];

  *basex = 0;
  aTag = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(aTag);
  sdfDrawTagInit(aTag);
  dds3ConsPanelTagLink(aTag, 50, 50, 23, 20);
  v4 = Empty_string_();
  v5 = sdfDevPrintf(31872, 31936, 0xFF0000u, 0, "BitEditor", v4);
  sdfDrawTagLink(aTag, v5);
  basex[1] = x + 16 * (y + base);
  v11 = evtBitCheck(x + 16 * (base + y), 0);
  v12 = sub_232A70(&basex[1], "X4");
  if (v11)
    v13 = &" = ON";
  else
    v13 = &" = OFF";
  v14 = Concat_5224608(v12, *v13);
  v16 = Empty_string_();
  v18 = sdfDevPrintf(34944, 31936, 0xFF0000u, 7, v14, v16);
  sdfDrawTagLink(aTag, v18);
  Clear(strbuf, 0);
  v23 = 0;
  do
  {
    v27 = v23 == x;
    v28 = &"<C00>";
    if (v27)
      v28 = &"<C14>";
    Append_5380272(strbuf, *v28);
    v31 = strbuf;
    Chars = get_Chars("０１２３４５６７８９ＡＢＣＤＥＦ", v23);
    Append_5387312(v31, Chars);
    Append_5380272(strbuf, "<D>");
    ++v23;
  }
  while (v23 != 16);
  v33 = (strbuf->klass->vtable._3_ToString.methodPtr)(
          strbuf,
          strbuf->klass->vtable._3_ToString.method);
  v35 = Empty_string_();
  v37 = sdfDevPrintf(32640, 32128, 0xFF0000u, 0, v33, v35);
  sdfDrawTagLink(aTag, v37);
  for (i = 0; i != 16; ++i)
  {
    Clear(strbuf, 0);
    basex[1] = 16 * (base + i);
    v42 = strbuf;
    v27 = y == i;
    v43 = &"<C00>";
    if (v27)
      v43 = &"<C14>";
    Append_5380272(v42, *v43);
    v46 = strbuf;
    v93 = basex[1];
    v47 = sub_8D3950(s32, &v93);
    v49 = Format("{0:X4}", v47, 0);
    v50 = ToZenkaku(v49);
    Append_5380272(v46, v50);
    Append_5380272(strbuf, "<D>");
    v53 = 0;
    do
    {
      if (evtBitCheck(v53 + 16 * (i + base), 0))
      {
        v58 = "〇";
        else
        {
          if (v53 != x)
            goto LABEL_65;
        }
      }
      else
      {
        v58 = "＋";
        else
        {
          if (v53 == x)
            goto LABEL_85;
        }
        else if (y != i)
        {
          goto LABEL_76;
        }
      }
LABEL_85:
      v60 = "<C14>";
      if ((v56->_2.bitflags2 & 2) == 0)
        goto LABEL_87;
LABEL_86:
      if (v53 != x)
        goto LABEL_93;
LABEL_88:
      if (y == i)
        v60 = "<C04>";
LABEL_93:
      Append_5380272(strbuf, v60);
      Append_5380272(strbuf, v58);
      Append_5380272(strbuf, "<D>");
      ++v53;
    }
    while (v53 != 16);
    v62 = (strbuf->klass->vtable._3_ToString.methodPtr)(
            strbuf,
            strbuf->klass->vtable._3_ToString.method);
    v64 = Empty_string_();
    v66 = sdfDevPrintf(31872, 96 * i + 32224, 0xFF0000u, 7, v62, v64);
    sdfDrawTagLink(aTag, v66);
  }
  v70 = dds3Ot->m_Items[81];
  sdfDrawTagLinkOt(v70, aTag);
  if (!DDS3_PAD2CHECK_REP(8))
    goto LABEL_132;
LABEL_118:
  if (base < 1)
    goto LABEL_132;
  base = base - 16;
  if ((base & 0x80000000) == 0)
  {
LABEL_132:
      goto LABEL_134;
    goto LABEL_133;
  }
  base = 0;
  {
LABEL_134:
    if (DDS3_PAD2CHECK_REP(10))
      goto LABEL_135;
LABEL_149:
    basex[0] = 0;
      goto LABEL_150;
    goto LABEL_152;
  }
LABEL_133:
    goto LABEL_134;
  if (!DDS3_PAD2CHECK_REP(10))
    goto LABEL_149;
LABEL_135:
  v81 = base;
  if (base > 239)
    goto LABEL_149;
  base = v81 + 16;
  if (base < 241)
    goto LABEL_149;
  base = 240;
  basex[0] = 0;
  {
LABEL_150:
  }
LABEL_152:
  v84 = dds3SelectMenu(1, 16, 256, 16, 16, basex, &base, &x, &y);
  if (v84 == -1)
  {
    id->func_ans = -1;
  }
  else if (v84 == 1)
  {
    v88 = evtBitCheck(x + 16 * (y + base), 0);
    if (v88)
    {
      evtBitOff(x + 16 * (y + base), 0);
    }
    else
    {
      evtBitOn(x + 16 * (y + base), 0);
    }
  }
  return 0;
}
