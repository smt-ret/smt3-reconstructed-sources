#include "types.h"

typedef struct bDrawText bDrawText;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct nbActionProcessData_t nbActionProcessData_t;
typedef struct nbDebugProcessData_t nbDebugProcessData_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;
typedef struct nbParty_t nbParty_t;

static char *MenuStr[6];
static char *MotStr[26];
static s32 menucur;
static s32 devilcur;
static s32 devilbase;
static s32 badcur;
static s32 motcur;
static s32 motbase;
static s32 motdatacur;
static char *DispBadStatus_bads[12];
static s32 nbDebugStockSelect_cur;
static s32 nbDebugStockSelect_basecur;
static bDrawText bsetText;
static char *Tname[20];
static char *aisyoname[16];
static s32 aisyoselect;

bool DDS3_PADCHECK_REP2(s32 id);
bool DDS3_PADCHECK_TRIG(s32 id);
bool DDS3_PADCHECK_TRIG2(s32 id);
void DispHpMpBad(nbDebugProcessData_t **d);
void DispHpMpBad2(nbDebugProcessData_t **d, nbFormation_t **form);
u8 Get(s32 id);
char *GetBadString(u32 bad);
void PreBtlMenuObj(s32 idx);
s32 SelectAisyo(nbDebugProcessData_t **d);
s32 SelectBad(nbDebugProcessData_t **d);
s32 SelectDevil(nbDebugProcessData_t **d);
s32 SelectHpMp(nbDebugProcessData_t **d);
s32 SelectMenu(nbDebugProcessData_t **d);
s32 SelectMot(nbDebugProcessData_t **d, s32 mode);
void SetBtlMenuObj(s32 idx);
void SetDvlChange(nbDebugProcessData_t **d);
void SetNextSeq(nbDebugProcessData_t **d);
void SetTarget(nbDebugProcessData_t **d);
bDrawText btlDevPrintf(s32 aX, s32 aY, s32 aZ, s32 color, char *aStr, s32 f);
void btlDrawTagLink(bDrawText *setText, bDrawText dt, s32 idx);
void datSetDevilWork(s32 id, datUnitWork_t *w);
void *dds3GetProcessData(dds3ProcessID_t **id);
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
s32 dds3SelectMenu(s32 pad, s32 listsx, s32 listsy, s32 winsx, s32 winsy, s32 *basex, s32 *basey, s32 *x, s32 *y);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void deleteBtlMenuObj(s32 idx);
void initBtlMenuObj(s32 x, s32 y, s32 w, s32 h, s32 idx);
u32 nbGetAisyo(s32 nskill, s32 formindex, s32 attr);
nbMainProcessData_t *nbGetMainProcessData(void);
nbParty_t *nbGetPartyFromFormindex(s32 formindex);
s32 nbGetTarSelStat(void);
datUnitWork_t *nbGetUnitWorkFromFormindex(s32 formindex);
s32 nbMakeBadDamagePacket(s32 startframe, s32 uniqueid, nbFormation_t **form, u32 bad);
s32 nbMakeBadKaifukuPacket(s32 startframe, s32 uniqueid, nbFormation_t **form);
void nbReturnUnit(s32 partyno, s32 lost, s32 dead);
void nbSetEnemyFormation(nbMainProcessData_t **data);
void nbSetNextOrder(void);
void nbSetOrder(void);
void nbSetPlayerFormation(nbMainProcessData_t **data, s32 empty);
s32 nbSetTargetProcess(nbActionProcessData_t *act, s32 partyindex, s32 ctype, s32 crule, s32 carea);
void nbSetUnitMotion(nbFormation_t **form, s32 motion2, s32 mode, f32 ritu);
void nbSummonUnit(s32 side, s32 stockno, s32 formindex);

// 0x16e8400
void BackUpHpMpBad(nbDebugProcessData_t **d) {
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;

  formindex = (*d)->form->formindex;
  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
  (*d)->hp = UnitWorkFromFormindex->hp;
  (*d)->mp = UnitWorkFromFormindex->mp;
  (*d)->bad = UnitWorkFromFormindex->badstatus;
}

// 0x16e56b0
void DispBadStatus(s32 ox, s32 oy, u32 bad, s32 col) {
  ;
}

// 0x16e6550
void DispHpMpBad(nbDebugProcessData_t **d) {
  s64 v4;
  struct nbFormation_t_array *v5;
  u64 v6;
  struct nbFormation_t_array *v8;
  nbFormation_t_o *form;

  v4 = 4;
  form = 0;
  while (1)
  {
    v5 = (*d)->data->form;
    v6 = v4 - 4;
    if ((*(*(&v5->obj.klass + v4) + 144LL) & 8) != 0)
      break;
    ++v4;
    if (v6 > 0x1E)
      return;
  }
  v8 = (*d)->data->form;
  form = *(&v8->obj.klass + v4);
  if (form)
  {
    DispHpMpBad2(d, &form);
  }
}

// 0x16e5890
void DispHpMpBad2(nbDebugProcessData_t **d, nbFormation_t **form) {
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;
  nbParty_t_o *PartyFromFormindex;
  s32 id;
  System_String_o *v9;
  System_String_o *v10;
  System_String_o *v11;
  System_String_o *v12;
  System_String_o *v13;
  System_String_o *v14;
  _BOOL4 v16;
  System_String_array *v17;
  s64 *v19;
  s64 *v20;
  s64 *v23;
  s64 *v24;
  System_String_o *v29;
  _BOOL4 v31;
  System_String_array *v32;
  s64 *v34;
  s64 *v35;
  s64 *v38;
  s64 *v39;
  System_String_o *v44;
  System_String_o *BadString;
  System_String_o *v47;
  u64 v50;
  s32 v51;
  s64 v52;
  struct System_String_array *Tname;
  struct System_Int16_array *count;
  System_String_o *v56;
  System_String_o *v58;
  System_String_o *v60;
  u32 v61;
  u64 i;
  u32 Aisyo;
  System_String_o *v74;
  System_String_o *v75;
  nbDebugProcess_c *v76;
  s32 v77;
  struct System_String_array *aisyoname;
  Il2CppObject *v80;
  u64 *v81;
  System_String_o *v83;
  s64 *v85;
  System_String_o *v87;
  s32 v91;
  bDrawText_o v92;
  bDrawText_o v93;
  bDrawText_o v94;
  bDrawText_o v95;
  bDrawText_o v96;
  bDrawText_o v97;
  bDrawText_o v98;
  bDrawText_o v99;
  bDrawText_o v100;
  bDrawText_o v101;

  PreBtlMenuObj(0);
  formindex = (*form)->formindex;
  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
  PartyFromFormindex = nbGetPartyFromFormindex((*form)->formindex, 0);
  id = UnitWorkFromFormindex->id;
  v9 = Get(id, 0);
  v10 = Concat_5224608(v9, "\n");
  v92 = btlDevPrintf(0, 0, 0, 0, v10, 0);
  btlDrawTagLink(&bsetText, v92, 0);
  v11 = sub_817880(&UnitWorkFromFormindex->id, "X3");
  v12 = Concat_5221536("ID  : 0x", v11, "\n");
  v93 = btlDevPrintf(0, 0, 0, 0, v12, 0);
  btlDrawTagLink(&bsetText, v93, 0);
  v13 = sub_817780(&UnitWorkFromFormindex->level);
  v14 = Concat_5221536("LV  : ", v13, "\n");
  v94 = btlDevPrintf(0, 0, 0, 0, v14, 0);
  btlDrawTagLink(&bsetText, v94, 0);
  v16 = (*d)->seq == 5;
  v17 = NewSpecific(string, 5u);
  v17->m_Items[0] = "HP  : ";
  v19 = sub_817780(&UnitWorkFromFormindex->hp);
  v20 = v19;
  v17->m_Items[1] = v20;
  v17->m_Items[2] = " / ";
  v23 = sub_817780(&UnitWorkFromFormindex->maxhp);
  v24 = v23;
  v17->m_Items[3] = v24;
  v17->m_Items[4] = "\n";
  v29 = Concat_5271600(v17);
  v95 = btlDevPrintf(0, 0, 0, 4 * v16, v29, 0);
  btlDrawTagLink(&bsetText, v95, 0);
  v31 = (*d)->seq == 6;
  v32 = NewSpecific(string, 5u);
  v32->m_Items[0] = "MP  : ";
  v34 = sub_817780(&UnitWorkFromFormindex->mp);
  v35 = v34;
  v32->m_Items[1] = v35;
  v32->m_Items[2] = " / ";
  v38 = sub_817780(&UnitWorkFromFormindex->maxmp);
  v39 = v38;
  v32->m_Items[3] = v39;
  v32->m_Items[4] = "\n";
  v44 = Concat_5271600(v32);
  v96 = btlDevPrintf(0, 0, 0, 4 * v31, v44, 0);
  btlDrawTagLink(&bsetText, v96, 0);
  BadString = GetBadString(UnitWorkFromFormindex->badstatus);
  v47 = Concat_5221536("BAD : ", BadString, "\n");
  v97 = btlDevPrintf(0, 0, 0, 0, v47, 0);
  btlDrawTagLink(&bsetText, v97, 0);
  v50 = 0;
  v52 = 32;
  do
  {
    count = PartyFromFormindex->count;
    v56 = Tname->m_Items[v50];
    v58 = sub_231650((count + v52));
    v60 = Concat_5271136(v56, " ", v58, "\n");
    v98 = btlDevPrintf(0, 0, 0, 0, v60, 0);
    btlDrawTagLink(&bsetText, v98, 0);
    ++v50;
    v52 += 2;
    v51 = (v61 >> 9) & 1;
  }
  while (v50 != 20);
  else
  {
      goto LABEL_84;
  }
  v99 = btlDevPrintf(0, 0, 0, 0, "\n", 0);
  btlDrawTagLink(&bsetText, v99, 0);
  for (i = 0; i != 12; ++i)
  {
    Aisyo = nbGetAisyo(-1, (*form)->formindex, i, 0);
    v74 = "";
    if ((Aisyo & 0x10000) != 0)
    {
      v74 = Concat_5224608("", "M");
      if ((Aisyo & 0x20000) == 0)
      {
LABEL_98:
        if ((Aisyo & 0x40000) == 0)
          goto LABEL_99;
        goto LABEL_113;
      }
    }
    else if ((Aisyo & 0x20000) == 0)
    {
      goto LABEL_98;
    }
    v74 = Concat_5224608(v74, "H");
    if ((Aisyo & 0x40000) == 0)
    {
LABEL_99:
      if ((Aisyo & 0x100000) != 0)
        goto LABEL_114;
      goto LABEL_100;
    }
LABEL_113:
    v74 = Concat_5224608(v74, "K");
    if ((Aisyo & 0x100000) != 0)
    {
LABEL_114:
      v74 = Concat_5224608(v74, "B");
      if ((Aisyo & 0x80000000) == 0)
        goto LABEL_101;
      goto LABEL_115;
    }
LABEL_100:
    if ((Aisyo & 0x80000000) == 0)
      goto LABEL_101;
LABEL_115:
    v74 = Concat_5224608(v74, "W");
LABEL_101:
    if (v74)
      v75 = v74;
    else
      v75 = "";
    if ((*d)->seq != 10)
    {
LABEL_117:
      v77 = 0;
      if ((v76->_2.bitflags2 & 2) == 0)
        goto LABEL_118;
      goto LABEL_109;
    }
    else if (i != aisyoselect)
    {
      goto LABEL_117;
    }
    v77 = 4;
    if ((v76->_2.bitflags2 & 2) == 0)
      goto LABEL_118;
LABEL_109:
LABEL_118:
    v80 = aisyoname->m_Items[i];
    v91 = Aisyo;
    v81 = sub_8D3950(uint, &v91);
    v83 = Concat_5269984(v80, " ", v81);
    v100 = btlDevPrintf(0, 0, 0, v77, v83, 0);
    btlDrawTagLink(&bsetText, v100, 0);
    if ((~i & 3) != 0)
    {
      v85 = &"        ";
    }
    else
    {
      v85 = &"\n";
    }
    v87 = Concat_5224608(v75, *v85);
    v101 = btlDevPrintf(0, 0, 0, v77, v87, 0);
    btlDrawTagLink(&bsetText, v101, 0);
  }
  SetBtlMenuObj(0);
}

// 0x16e56c0
char *GetBadString(u32 bad) {
  s16 v2;
  s64 v4;
  struct System_String_array *DispBadStatus_bads;

  v2 = bad;
  if ((v2 & 1) != 0)
  {
    v4 = 0;
  }
  else if ((v2 & 2) != 0)
  {
    v4 = 1;
  }
  else if ((v2 & 4) != 0)
  {
    v4 = 2;
  }
  else if ((v2 & 8) != 0)
  {
    v4 = 3;
  }
  else if ((v2 & 0x10) != 0)
  {
    v4 = 4;
  }
  else if ((v2 & 0x20) != 0)
  {
    v4 = 5;
  }
  else if ((v2 & 0x40) != 0)
  {
    v4 = 6;
  }
  else if ((v2 & 0x80) != 0)
  {
    v4 = 7;
  }
  else if ((v2 & 0x100) != 0)
  {
    v4 = 8;
  }
  else if ((v2 & 0x200) != 0)
  {
    v4 = 9;
  }
  else if ((v2 & 0x400) != 0)
  {
    v4 = 10;
  }
  else
  {
    if ((v2 & 0x800) == 0)
      return "-----";
    v4 = 11;
  }
  return DispBadStatus_bads->m_Items[v4];
}

// 0x16e8c80
nbDebugProcessData_t *InitDebugProcessData(nbMainProcessData_t **data) {
  nbDebugProcessData_t_o *v3;

  v3 = Allocate(nbDebugProcessData_t);
  nbDebugProcessData_t___ctor(v3);
  v3->data = *data;
  v3->seq = 0;
  v3->formindex = 0;
  v3->form = 0;
  menucur = 0;
  return v3;
}

// 0x16e7b20
s32 SelectAisyo(nbDebugProcessData_t **d) {
  s32 formindex;
  nbParty_t_o *PartyFromFormindex;
  struct System_UInt32_array *aisyo;
  s32 aisyoselect;
  char *v10;
  struct System_UInt32_array *v11;
  s32 v12;
  s32 v14;
  s32 v18;

  formindex = (*d)->form->formindex;
  nbGetUnitWorkFromFormindex(formindex);
  PartyFromFormindex = nbGetPartyFromFormindex((*d)->form->formindex, 0);
  aisyo = PartyFromFormindex->aisyo;
  v10 = aisyo + 4 * aisyoselect;
  v11 = PartyFromFormindex->aisyo;
  v12 = *(v10 + 16);
  v14 = HIWORD(v11->m_Items[aisyoselect]);
  else if (DDS3_PADCHECK_REP2(8))
  {
LABEL_16:
    --aisyoselect;
    if (aisyoselect < 0)
    {
      v18 = 0;
      aisyoselect = 11;
      return v18;
    }
    return 0;
  }
  if (!DDS3_PADCHECK_REP2(10))
    goto LABEL_38;
LABEL_28:
  ++aisyoselect;
  if (aisyoselect < 12)
    return 0;
  v18 = 0;
  aisyoselect = 0;
  return v18;
}

// 0x16e6c20
s32 SelectBad(nbDebugProcessData_t **d) {
  s32 formindex;
  s32 i;
  s16 v8;
  s32 v9;
  s32 v10;
  System_String_o *BadString;
  System_String_o *v13;
  s32 v15;
  nbFormation_t_o **p_form;
  s32 v19;
  datUnitWork_t_o *UnitWorkFromFormindex;
  nbDebugProcessData_t_o **v22;
  s32 x;
  s32 basey[2];
  bDrawText_o v25;

  *basey = 0;
  x = 0;
  initBtlMenuObj(1600, 380, 320, 480, 2);
  PreBtlMenuObj(2);
  v22 = d;
  formindex = (*d)->form->formindex;
  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
  for (i = 0; i != 13; ++i)
  {
    if ((v8 & 0x200) != 0)
    {
      v9 = v8 & 0x200;
    }
    else
    {
      v9 = 0;
    }
    v10 = 4 * (i == badcur);
    if (!i)
    {
      else if ((byte_3F5A47B & 1) != 0)
      {
LABEL_26:
        BadString = "-----";
        goto LABEL_27;
      }
      goto LABEL_26;
    }
    BadString = GetBadString(1 << (i - 1));
LABEL_27:
    v13 = Concat_5224608(BadString, "\n");
    v25 = btlDevPrintf(0, 0, 0, v10, v13, 0);
    btlDrawTagLink(&bsetText, v25, 2);
  }
  *basey = 0;
  x = 0;
  v15 = dds3SelectMenu(0, 1, 13, 1, 13, &basey[1], basey, &x, &badcur);
  if (v15 == -1)
  {
    deleteBtlMenuObj(2);
    return -1;
  }
  else
  {
    if (v15 == 1)
    {
      else if (badcur)
      {
LABEL_39:
        UnitWorkFromFormindex->badstatus &= 0xF000u;
        p_form = &(*v22)->form;
        v19 = 1;
        nbMakeBadDamagePacket(0, 0, p_form, 1 << (LOBYTE(badcur) - 1), 0);
        return v19;
      }
      nbMakeBadKaifukuPacket(0, 0, &(*v22)->form, 0);
      return 1;
    }
    SetBtlMenuObj(2);
    return 0;
  }
}

// 0x16e7670
s32 SelectDevil(nbDebugProcessData_t **d) {
  s32 i;
  s16 v5;
  s32 v6;
  _BOOL4 v8;
  s32 v9;
  u64 *v10;
  System_String_o *v11;
  System_String_o *v13;
  s32 v15;
  s32 devilbase;
  System_String_o *v17;
  System_String_o *v19;
  s32 result;
  s32 v26;
  s32 v31;
  s32 v33;
  s32 x[2];
  bDrawText_o v35;

  x[1] = 0;
  x[0] = 0;
  initBtlMenuObj(1600, 380, 320, 480, 2);
  PreBtlMenuObj(2);
  for (i = 0; i != 10; ++i)
  {
    if ((v5 & 0x200) != 0)
    {
      v6 = v5 & 0x200;
    }
    else
    {
      v6 = 0;
    }
    v8 = i == devilcur;
    else
    {
      v9 = i + devilbase;
      if (v9 <= 255)
        goto LABEL_17;
    }
    v33 = v9;
    v10 = sub_8D3950(s32, &v33);
    v11 = "0x{0:x3}";
LABEL_18:
    v13 = Format(v11, v10, 0);
    v15 = 4 * v8;
    v17 = Get(i + devilbase, 0);
    v19 = Concat_5271136(v13, " ", v17, "\n");
    v35 = btlDevPrintf(0, 0, 0, v15, v19, 0);
    btlDrawTagLink(&bsetText, v35, 2);
  }
  *x = 0;
  result = dds3SelectMenu(0, 1, 384, 1, 10, &x[1], &devilbase, x, &devilcur);
  if (result != 1)
  {
    if (result == -1)
    {
      deleteBtlMenuObj(2);
      return -1;
    }
    else
    {
      if (DDS3_PADCHECK_REP2(5))
      {
        v26 = devilbase;
        if (v26 <= 373)
        {
          devilbase = v26 + 10;
          if (devilbase >= 374)
          {
            devilbase = 374;
          }
        }
      }
      if (DDS3_PADCHECK_REP2(4))
      {
        v31 = devilbase;
        if (v31 >= 1)
        {
          devilbase = v31 - 10;
          if (devilbase < 0)
          {
            devilbase = 0;
          }
        }
      }
      SetBtlMenuObj(2);
      return 0;
    }
  }
  return result;
}

// 0x16e6990
s32 SelectHpMp(nbDebugProcessData_t **d) {
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;
  s32 v7;
  s32 v13;
  s32 v14;
  s32 seq;
  s32 v17;
  s32 v18;

  formindex = (*d)->form->formindex;
  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
  if (DDS3_PADCHECK_REP2(4))
    v7 = -100;
  else
    v7 = 0;
  if (DDS3_PADCHECK_REP2(5))
    v7 = 100;
  if (DDS3_PADCHECK_REP2(6))
    v7 = -10;
  if (DDS3_PADCHECK_REP2(7))
    v7 = 10;
  if (DDS3_PADCHECK_REP2(8))
    v7 = -1;
  if (DDS3_PADCHECK_REP2(10))
    v13 = 1;
  else
    v13 = v7;
  v14 = 1;
  if (!DDS3_PADCHECK_TRIG2(1))
  {
    else if (DDS3_PADCHECK_TRIG2(3))
    {
      return -1;
    }
    seq = (*d)->seq;
    if (seq == 6)
    {
      v18 = (v13 + UnitWorkFromFormindex->mp) & ~((v13 + UnitWorkFromFormindex->mp) >> 31);
      v14 = 0;
      if (v18 > UnitWorkFromFormindex->maxmp)
        LOWORD(v18) = UnitWorkFromFormindex->maxmp;
      UnitWorkFromFormindex->mp = v18;
    }
    else if (seq == 5)
    {
      v17 = v13 + UnitWorkFromFormindex->hp;
      if (v17 <= 1)
        v17 = 1;
      if (v17 > UnitWorkFromFormindex->maxhp)
        LOWORD(v17) = UnitWorkFromFormindex->maxhp;
      v14 = 0;
      UnitWorkFromFormindex->hp = v17;
    }
    else
    {
      return 0;
    }
  }
  return v14;
}

// 0x16e6660
s32 SelectMenu(nbDebugProcessData_t **d) {
  u64 v3;
  nbDebugProcess_c *v4;
  s32 v6;
  struct System_String_array *MenuStr;
  System_String_o *v11;
  s32 result;
  s32 x;
  s32 basey[2];
  bDrawText_o v18;

  *basey = 0;
  x = 0;
  initBtlMenuObj(800, 380, 320, 320, 1);
  PreBtlMenuObj(1);
  v3 = 0;
  {
LABEL_9:
  }
  while (1)
  {
    if (v3 >= SLODWORD(MenuStr->max_length))
      break;
    if ((v4->_2.bitflags2 & 2) != 0)
    {
      else
      {
        v6 = 4 * (v3 == menucur);
      }
      if (v3 >= LODWORD(MenuStr->max_length))
        goto LABEL_20;
    }
    else
    {
      v6 = 4 * (v3 == menucur);
      if (v3 >= LODWORD(MenuStr->max_length))
        goto LABEL_20;
    }
LABEL_21:
    v11 = Concat_5224608(MenuStr->m_Items[v3], "\n");
    v18 = btlDevPrintf(0, 0, 0, v6, v11, 0);
    btlDrawTagLink(&bsetText, v18, 1);
    ++v3;
      goto LABEL_9;
  }
  else if (DDS3_PADCHECK_TRIG2(3))
  {
LABEL_29:
    deleteBtlMenuObj(1);
    return -1;
  }
  *basey = 0;
  x = 0;
  result = dds3SelectMenu(0, 1, 6, 1, 6, &basey[1], basey, &x, &menucur);
  if (result != -1 && result != 1)
  {
    SetBtlMenuObj(1);
    return 0;
  }
  return result;
}

// 0x16e6ff0
s32 SelectMot(nbDebugProcessData_t **d, s32 mode) {
  s32 formindex;
  s32 v8;
  nbDebugProcess_c *v9;
  s32 v10;
  struct System_String_array *MotStr;
  u32 v13;
  System_String_o *v16;
  nbDebugProcess_c *v17;
  s16 v18;
  s32 v19;
  s32 v21;
  struct System_String_array *v22;
  u32 v23;
  System_String_o *v26;
  s32 v28;
  nbFormation_t_o **p_form;
  s32 v32;
  u64 *v33;
  s32 motbase;
  s32 v43;
  s32 x;
  s32 basex;
  bDrawText_o v47;
  bDrawText_o v48;

  basex = 0;
  x = 0;
  initBtlMenuObj(1600, 380, 320, 640, 2);
  PreBtlMenuObj(2);
  formindex = (*d)->form->formindex;
  nbGetUnitWorkFromFormindex(formindex);
  v8 = 0;
  if (mode)
  {
    while (1)
    {
      else if (v8 == motcur)
      {
        goto LABEL_16;
      }
      else
      {
        v10 = 0;
        if ((v9->_2.bitflags2 & 2) != 0)
        {
LABEL_17:
        }
      }
LABEL_23:
      v13 = v8 + motbase;
      v16 = Concat_5224608(MotStr->m_Items[v13], "\n");
      v47 = btlDevPrintf(0, 0, 0, v10, v16, 0);
      btlDrawTagLink(&bsetText, v47, 2);
      if (++v8 == 10)
        goto LABEL_48;
    }
  }
  do
  {
    if ((v18 & 0x200) != 0
           v17 = nbDebugProcess,
           (v18 & 0x200) != 0)))
    {
      v19 = v18 & 0x200;
    }
    else
    {
      v19 = 0;
    }
    if (v8 == motcur)
      v21 = 5;
    else
      v21 = 0;
    v22 = MotStr;
    v23 = v8 + motbase;
    v26 = Concat_5224608(v22->m_Items[v23], "\n");
    v48 = btlDevPrintf(0, 0, 0, v21, v26, 0);
    btlDrawTagLink(&bsetText, v48, 2);
    ++v8;
  }
  while (v8 != 10);
LABEL_48:
  if (!mode)
  {
LABEL_101:
    SetBtlMenuObj(2);
    return 0;
  }
  basex = 0;
  x = 0;
  v28 = dds3SelectMenu(0, 1, 26, 1, 10, &basex, &motbase, &x, &motcur);
  if (v28 != -1)
  {
    if (v28 == 1)
    {
      p_form = &(*d)->form;
      v32 = motcur + motbase;
      v33 = Allocate(evtUnitHandle_t);
      evtUnitHandle_t___ctor(v33);
      nbSetUnitMotion(p_form, v32, 0, 1.0);
      return 1;
    }
    if (DDS3_PADCHECK_REP2(5))
    {
      if (motbase <= 15)
      {
        motbase = motbase + 10;
        if (motbase >= 16)
        {
          motbase = 16;
        }
      }
    }
    if (DDS3_PADCHECK_REP2(4))
    {
      v43 = motbase;
      if (v43 >= 1)
      {
        motbase = v43 - 10;
        if (motbase < 0)
        {
          motbase = 0;
        }
      }
    }
    else if (DDS3_PADCHECK_TRIG(0))
    {
      return 2;
    }
    goto LABEL_101;
  }
  deleteBtlMenuObj(2);
  return -1;
}

// 0x16e6fe0
s32 SelectMotData(nbDebugProcessData_t **d, s32 mode) {
  return 0;
}

// 0x16e8050
void SetDvlChange(nbDebugProcessData_t **d) {
  nbDebugProcessData_t_o *v4;
  struct datUnitWork_t_array *enemyunit;
  s64 stockno;
  datUnitWork_t_o *v9;
  s32 devilcur;
  s32 devilbase;
  s32 v16;
  s32 v17;
  u16 maxhp;
  u16 maxmp;
  nbDebugProcessData_t_o *v21;
  s32 side;
  nbMainProcessData_t_o **p_data;
  nbMainProcessData_t_o **v24;

  nbReturnUnit((*d)->partyindex, 0, 0, 0);
  v4 = *d;
  if ((*d)->side == 1)
  {
    enemyunit = v4->data->enemyunit;
    stockno = v4->stockno;
    if (stockno < LODWORD(enemyunit->max_length))
      goto LABEL_11;
LABEL_10:
  }
  enemyunit = DDS3_GBWK->unitwork;
  stockno = v4->stockno;
  if (stockno >= LODWORD(enemyunit->max_length))
    goto LABEL_10;
LABEL_11:
  v9 = enemyunit->m_Items[stockno];
  datSetDevilWork(devilcur + devilbase, v9);
  v16 = devilcur;
  v17 = devilbase;
  maxhp = Get(v16 + v17, 1, 0)->maxhp;
  v9->maxhp = maxhp;
  v9->hp = maxhp;
  maxmp = Get(
            devilcur + devilbase,
            1,
            0)->maxmp;
  v9->maxmp = maxmp;
  v9->mp = maxmp;
  nbSummonUnit((*d)->side, (*d)->stockno, (*d)->formindex, 0);
  v21 = *d;
  side = (*d)->side;
  if (side)
  {
    if (side == 1)
    {
      p_data = &v21->data;
      nbSetEnemyFormation(p_data);
    }
  }
  else
  {
    v24 = &v21->data;
    nbSetPlayerFormation(v24, 0);
  }
}

// 0x16e5800
void SetMotion(nbMainProcessData_t **data, nbFormation_t **form, s32 motno, s32 mode) {
  u64 *v8;

  v8 = Allocate(evtUnitHandle_t);
  evtUnitHandle_t___ctor(v8);
  nbSetUnitMotion(form, motno, mode, 1.0);
}

// 0x16e84a0
void SetNextSeq(nbDebugProcessData_t **d) {
  s32 seq;
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;
  nbDebugProcessData_t_o **v6;

  (*d)->seq = (*d)->nextseq;
  (*d)->nextseq = -1;
  seq = (*d)->seq;
  if ((seq - 5) >= 3)
  {
    if (seq == 3)
    {
      else
      {
        v6 = d;
      }
      SetDvlChange(v6);
    }
    else if (seq == 1)
    {
      nbSetTargetProcess(0, 0, 0, 0, 3);
    }
  }
  else
  {
    formindex = (*d)->form->formindex;
    UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
    (*d)->hp = UnitWorkFromFormindex->hp;
    (*d)->mp = UnitWorkFromFormindex->mp;
    (*d)->bad = UnitWorkFromFormindex->badstatus;
  }
}

// 0x16e8030
void SetSelect(nbDebugProcessData_t **d) {
  nbSetTargetProcess(0, 0, 0, 0, 3);
}

// 0x16e82c0
void SetTarget(nbDebugProcessData_t **d) {
  s64 v2;
  struct nbFormation_t_array *form;
  u64 v4;
  struct nbFormation_t_array *v6;
  struct nbParty_t_array *party;
  s64 partyindex;

  (*d)->form = 0;
  v2 = 4;
  (*d)->formindex = 0;
  while (1)
  {
    form = (*d)->data->form;
    v4 = v2 - 4;
    if ((*(*(&form->obj.klass + v2) + 136LL) & 8) != 0)
      break;
    ++v2;
    if (v4 >= 0xF)
      return;
  }
  (*d)->formindex = v2 - 4;
  v6 = (*d)->data->form;
  (*d)->form = *(&v6->obj.klass + v2);
  (*d)->partyindex = (*d)->form->partyindex;
  party = (*d)->data->party;
  partyindex = (*d)->partyindex;
  (*d)->party = party->m_Items[partyindex];
  (*d)->side = ((*d)->party->flag >> 1) & 1;
  (*d)->stockno = (*d)->party->statindex;
}

// 0x16e8650
void *nbDebugProcess1(dds3ProcessID_t *id) {
  nbDebugProcessData_t_o *ProcessData;
  nbDebugProcessData_t_c *v3;
  nbDebugProcessData_t_c *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  s32 v9;
  s32 v11;
  s32 TarSelStat;
  nbDebugProcessData_t_o **v14;
  s32 v15;
  s32 side;
  nbDebugProcessData_t_o **v17;
  s32 v18;
  s32 v19;
  nbFormation_t_o **p_form;
  struct nbMainProcessData_t_o *data;
  struct nbParty_t_array *party;
  u32 activeunit;
  s32 v25;
  nbDebugProcessData_t_o *v28;
  dds3ProcessID_t_o *v29[3];
  dds3ProcessID_t_o *ida;

  ida = id;
  v28 = 0;
  else
  {
    ProcessData = dds3GetProcessData(&ida);
    if (!ProcessData)
      goto LABEL_12;
  }
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbDebugProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbDebugProcessData_t, v29);
    if ((v29[0] & 1) != 0)
      v7 = v29[2];
    else
      v7 = v29 + 1;
    v8 = sub_8C4940(v7);
  }
LABEL_12:
  v28 = ProcessData;
  switch (ProcessData->seq)
  {
    case 0:
      v11 = 1;
      goto LABEL_63;
    case 1:
      TarSelStat = nbGetTarSelStat();
      if (TarSelStat == 2)
      {
        v25 = 0;
        goto LABEL_91;
      }
      if (!TarSelStat)
      {
        SetTarget(&v28);
        goto LABEL_62;
      }
      DispHpMpBad(&v28);
      return 0;
    case 2:
      v15 = SelectDevil(v14, v3);
      if (v15 == -1)
        goto LABEL_62;
      if (v15 != 1)
        return 0;
      ProcessData = v28;
      v11 = 3;
      goto LABEL_63;
    case 3:
      side = ProcessData->side;
      if ((ProcessData->data->stat & 8) != 0)
      {
        if (side != 1)
          goto LABEL_83;
      }
      else if (side)
      {
        goto LABEL_83;
      }
      nbSetOrder();
      while (1)
      {
        data = v28->data;
        party = data->party;
        activeunit = data->activeunit;
        if (v28->formindex == party->m_Items[activeunit]->formindex)
          break;
        nbSetNextOrder();
      }
LABEL_83:
      deleteBtlMenuObj(0);
      deleteBtlMenuObj(1);
      v25 = 2;
LABEL_91:
      deleteBtlMenuObj(v25);
      ida->func_ans = -1;
      return 0;
    case 4:
      v18 = SelectMenu(v17, v3);
      if (v18 == 1)
      {
        switch (menucur)
        {
          case 0:
            ProcessData = v28;
            v11 = 2;
            goto LABEL_63;
          case 1:
            ProcessData = v28;
            v11 = 5;
            goto LABEL_63;
          case 2:
            ProcessData = v28;
            v11 = 6;
            goto LABEL_63;
          case 3:
            ProcessData = v28;
            v11 = 7;
            goto LABEL_63;
          case 4:
            ProcessData = v28;
            v11 = 8;
            goto LABEL_63;
          case 5:
            ProcessData = v28;
            v11 = 10;
            goto LABEL_63;
          default:
            return 0;
        }
      }
      else
      {
        if (v18 == -1)
        {
          ProcessData = v28;
          v11 = 1;
          goto LABEL_63;
        }
LABEL_67:
        p_form = &v28->form;
        DispHpMpBad2(&v28, p_form);
      }
      return 0;
    case 5:
    case 6:
      v9 = SelectHpMp(&v28, v3);
      if (v9 == 1)
        goto LABEL_62;
      goto LABEL_61;
    case 7:
      v9 = SelectBad(&v28, v3);
      if (v9 == 1)
        return 0;
      goto LABEL_61;
    case 8:
      v19 = SelectMot(&v28, 1);
      if (v19 == 2)
      {
        ProcessData = v28;
        v11 = 9;
      }
      else
      {
        if (v19 != -1)
          return 0;
LABEL_62:
        ProcessData = v28;
        v11 = 4;
      }
LABEL_63:
      ProcessData->nextseq = v11;
      SetNextSeq(&v28, v3);
      return 0;
    case 9:
      SelectMot(&v28, 0);
      return 0;
    case 0xA:
      v9 = SelectAisyo(&v28, v3);
      if (v9 == 1)
        goto LABEL_62;
LABEL_61:
      if (v9 == -1)
        goto LABEL_62;
      goto LABEL_67;
    default:
      return 0;
  }
}

// 0x16e8be0
void *nbDebugShutdown(dds3ProcessID_t *id) {
  nbMainProcessData_t_o *MainProcessData;
  dds3ProcessID_t_o *ida;

  ida = id;
  MainProcessData = nbGetMainProcessData();
  dds3GetProcessData(&ida);
  MainProcessData->DebugProcessID = 0;
  return 0;
}

// 0x16e5880
s32 nbDebugStockSelect(nbMainProcessData_t **data) {
  return -1;
}

// 0x16e8d20
void nbInitDebugProcess(nbMainProcessData_t **data) {
  nbDebugProcessData_t_o *v3;
  u64 *v6;
  u64 *v7;
  dds3ProcessID_t_o *target;

  target = 0;
LABEL_7:
  v3 = Allocate(nbDebugProcessData_t);
  nbDebugProcessData_t___ctor(v3);
  v3->data = *data;
  v3->seq = 0;
  v3->formindex = 0;
  v3->form = 0;
  menucur = 0;
  v6 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v6,
    0,
    Method_nbDebugProcess_nbDebugProcess1__);
  v7 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v7,
    0,
    Method_nbDebugProcess_nbDebugShutdown__);
  target = dds3StartProcess("nb_debug", 0x3F9u, 1, 1, v6, 0, v7, 0, v3, 0);
  dds3LinkProcess(&(*data)->MainProcessID, &target, 0);
  (*data)->DebugProcessID = target;
  initBtlMenuObj(0, 200, 800, 880, 0);
}
