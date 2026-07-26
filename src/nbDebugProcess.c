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
    PreBtlMenuObj(0);
    nbGetUnitWorkFromFormindex(0);
    nbGetPartyFromFormindex(0);
    Get(0);
    btlDevPrintf(0, 0, 0, 0, 0, 0);
    btlDrawTagLink(0, (bDrawText){0}, 0);
    GetBadString(0);
    nbGetAisyo(0, 0, 0);
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
      return StringLiteral_12376;
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
    nbGetUnitWorkFromFormindex(0);
    nbGetPartyFromFormindex(0);
    DDS3_PADCHECK_REP2(0);
    DDS3_PADCHECK_TRIG2(0);
    return 0;
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
        BadString = StringLiteral_12376;
      }
    }
    BadString = GetBadString(1 << (i - 1));
    v13 = Concat_5224608(BadString, StringLiteral_3622);
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
    initBtlMenuObj(0, 0, 0, 0, 0);
    PreBtlMenuObj(0);
    Get(0);
    btlDevPrintf(0, 0, 0, 0, 0, 0);
    btlDrawTagLink(0, (bDrawText){0}, 0);
    dds3SelectMenu(0, 0, 0, 0, 0, 0, 0, 0, 0);
    deleteBtlMenuObj(0);
    DDS3_PADCHECK_REP2(0);
    SetBtlMenuObj(0);
    return 0;
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
    initBtlMenuObj(0, 0, 0, 0, 0);
    PreBtlMenuObj(0);
    btlDevPrintf(0, 0, 0, 0, 0, 0);
    btlDrawTagLink(0, (bDrawText){0}, 0);
    DDS3_PADCHECK_TRIG2(0);
    deleteBtlMenuObj(0);
    dds3SelectMenu(0, 0, 0, 0, 0, 0, 0, 0, 0);
    SetBtlMenuObj(0);
    return 0;
}

// 0x16e6ff0
s32 SelectMot(nbDebugProcessData_t **d, s32 mode) {
    initBtlMenuObj(0, 0, 0, 0, 0);
    PreBtlMenuObj(0);
    nbGetUnitWorkFromFormindex(0);
    btlDevPrintf(0, 0, 0, 0, 0, 0);
    btlDrawTagLink(0, (bDrawText){0}, 0);
    SetBtlMenuObj(0);
    dds3SelectMenu(0, 0, 0, 0, 0, 0, 0, 0, 0);
    nbSetUnitMotion(0, 0, 0, 0);
    DDS3_PADCHECK_REP2(0);
    DDS3_PADCHECK_TRIG(0);
    deleteBtlMenuObj(0);
    return 0;
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
  nbDebugProcess_c *v10;
  struct nbDebugProcess_StaticFields *static_fields;
  s32 devilcur;
  s32 devilbase;
  struct nbDebugProcess_StaticFields *v15;
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
  }
  enemyunit = DDS3_GBWK->unitwork;
  stockno = v4->stockno;
  if (stockno >= LODWORD(enemyunit->max_length))
  v9 = enemyunit->m_Items[stockno];
  static_fields = v10->static_fields;
  devilcur = static_fields->devilcur;
  devilbase = static_fields->devilbase;
  datSetDevilWork(devilcur + devilbase, v9);
  v15 = nbDebugProcess->static_fields;
  v16 = v15->devilcur;
  v17 = v15->devilbase;
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
    dds3GetProcessData(0);
    nbGetTarSelStat();
    SetTarget(0);
    DispHpMpBad(0);
    SelectDevil(0);
    nbSetOrder();
    nbSetNextOrder();
    deleteBtlMenuObj(0);
    SelectMenu(0);
    DispHpMpBad2(0, 0);
    SelectHpMp(0);
    SelectBad(0);
    SelectMot(0, 0);
    SetNextSeq(0);
    SelectAisyo(0);
    return 0;
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
  target = dds3StartProcess(StringLiteral_21257, 0x3F9u, 1, 1, v6, 0, v7, 0, v3, 0);
  dds3LinkProcess(&(*data)->MainProcessID, &target, 0);
  (*data)->DebugProcessID = target;
  initBtlMenuObj(0, 200, 800, 880, 0);
}
