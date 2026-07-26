#include "types.h"

typedef struct bDrawText bDrawText;
typedef struct datDevilAI_s datDevilAI_t;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;

static s32 selectmax;
static s32 renzokucnt;
static s32 skillchg;
static void *BtlDbgMenuObj[4];
static void *BtlDbgMenuTxtTM[4];
static void *BtlDrawText[4];
static bDrawText bsetText;
static s32 num;
static s32 stagemajor;
static s32 stageminor;
static s32 pack;
static s32 f;
static s32 cur;
static s32 mode;
static s32 bgmloading;
static datUnitWork_t *test_pdummy;
static s32 test_dvllist[4];
static s32 *test_skilllist[4];
static s32 test_pskill[12];
static s32 test_phearts;
static datUnitWork_t *test2_pdummy;
static s32 test2_dvllist[4];
static s32 *test2_skilllist[4];
static s32 test2_pskill[5];
static datUnitWork_t *test3_pdummy;
static s32 test3_dvllist[4];
static s32 *test3_skilllist[1];
static s32 test3_pskill[1];
static datDevilAI_t *dummyDevilAI[11];
static s32 test1st_dvllist[1];

bool DDS3_PADCHECK_PRESS(s32 id);
bool DDS3_PADCHECK_REP(s32 id);
bool DDS3_PADCHECK_TRIG(s32 id);
void DrawTest(void);
u8 Get(s32 id);
void SetBossDummy(void);
s32 TestSelectEncount(s32 sel, bool mov);
void btlDrawTagLink(bDrawText *setText, bDrawText dt, s32 idx);
s32 datAddHearts(s32 id);
void datDevilAI_t__Copy(datDevilAI_t *this, datDevilAI_t *data);
void datEquipHearts(s32 HeartsID);
u32 datGetMaxHp(datUnitWork_t *work);
u32 datGetMaxMp(datUnitWork_t *work);
void datRemoveHearts(void);
void datSetDevilWork(s32 id, datUnitWork_t *w);
void datUnitWork_t__Clear(datUnitWork_t *this);
void datUnitWork_t__Copy(datUnitWork_t *this, datUnitWork_t *dat);
bool dds3CheckDLC6(void);
bool dds3CheckDLC7(void);
s32 dds3KillProcessName(char *name, s32 shutdowntimer);
dds3ProcessID_t *dds3SearchProcessPriority(s32 priority);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
bool evtBitCheck(s32 no);
void evtBitOff(s32 no);
void evtBitOn(s32 no);
void evtSetAgeOfMoon(s32 age);
void nbCallNewBattle(s32 encpack, s32 data);
s32 nbEncountCalc(s32 id, f32 length);
void nbExit(void);
s32 nbGetEncountCnt(void);
s32 nbGetEncountMax(s32 id);
void nbInitMainProcess(s32 encpackno, s32 packno, s32 packindex, s32 encno, s32 stagemajor, s32 stageminor);
void nbSetBattleDummy(s32 pcnt, s32 **dvllist, s32 ***skilllist, s32 **pskill, datUnitWork_t *dummy);
u32 rstCalcExpFromLevel(u8 Index, s32 Level);

// 0x15877e0
void DrawTest(void) {
    btlDrawTagLink(0, (bDrawText){0}, 0);
    evtBitCheck(0);
    nbGetEncountCnt();
    nbGetEncountMax(0);
    Get(0);
    Get(0);
    Get(0);
}

// 0x1586720
void PreBtlMenuObj(s32 idx) {
  struct System_Collections_Generic_List_bDrawText__array *BtlDrawText;

  _Clear(BtlDrawText->m_Items[idx]);
}

// 0x1586c70
void SetBossDummy(void) {
  datDevilAI_t_o *v3;
  struct datDevilAI_t_array *dummyDevilAI;
  datDevilAI_t_o *v7;
  struct datDevilAI_t_array *v8;
  datDevilAI_t_o *v10;
  struct datDevilAI_t_array *v11;
  datDevilAI_t_o *v13;
  struct datDevilAI_t_array *v14;
  datDevilAI_t_o *v16;
  struct datDevilAI_t_array *v17;
  datDevilAI_t_o *v19;
  struct datDevilAI_t_array *v20;
  datDevilAI_t_o *v22;
  struct datDevilAI_t_array *v23;
  datDevilAI_t_o *v25;
  struct datDevilAI_t_array *v26;
  datDevilAI_t_o *v28;
  struct datDevilAI_t_array *v29;
  datDevilAI_t_o *v31;
  struct datDevilAI_t_array *v32;
  datDevilAI_t_o *v34;
  struct datDevilAI_t_array *v35;
  datDevilAI_t_o *v37;
  struct datDevilAI_t_array *v38;
  datDevilAI_t_o *v40;
  struct datDevilAI_t_array *v41;

  v3 = Get(269, 0);
  datDevilAI_t__Copy(v3, dummyDevilAI->m_Items[1]);
  v7 = Get(278, 0);
  v8 = dummyDevilAI;
  datDevilAI_t__Copy(v7, v8->m_Items[2]);
  v10 = Get(279, 0);
  v11 = dummyDevilAI;
  datDevilAI_t__Copy(v10, v11->m_Items[3]);
  v13 = Get(280, 0);
  v14 = dummyDevilAI;
  datDevilAI_t__Copy(v13, v14->m_Items[3]);
  v16 = Get(281, 0);
  v17 = dummyDevilAI;
  datDevilAI_t__Copy(v16, v17->m_Items[3]);
  v19 = Get(282, 0);
  v20 = dummyDevilAI;
  datDevilAI_t__Copy(v19, v20->m_Items[3]);
  v22 = Get(288, 0);
  v23 = dummyDevilAI;
  datDevilAI_t__Copy(v22, v23->m_Items[4]);
  v25 = Get(292, 0);
  v26 = dummyDevilAI;
  datDevilAI_t__Copy(v25, v26->m_Items[5]);
  v28 = Get(259, 0);
  v29 = dummyDevilAI;
  datDevilAI_t__Copy(v28, v29->m_Items[6]);
  v31 = Get(291, 0);
  v32 = dummyDevilAI;
  datDevilAI_t__Copy(v31, v32->m_Items[7]);
  v34 = Get(258, 0);
  v35 = dummyDevilAI;
  datDevilAI_t__Copy(v34, v35->m_Items[8]);
  v37 = Get(293, 0);
  v38 = dummyDevilAI;
  datDevilAI_t__Copy(v37, v38->m_Items[9]);
  v40 = Get(264, 0);
  v41 = dummyDevilAI;
  datDevilAI_t__Copy(v40, v41->m_Items[10]);
  evtBitOn(3083);
  evtBitOff(3073);
  evtBitOff(3079);
  if (f == 2)
  {
    evtSetAgeOfMoon(8);
  }
}

// 0x15867d0
void SetBtlMenuObj(s32 idx) {
}

// 0x158b680
void SetNakama(u16 DevilID, s32 idx) {
  struct datUnitWork_t_array *unitwork;
  datUnitWork_t_o *v8;
  struct System_SByte_array *param;
  struct System_SByte_array *v12;
  s8 v13;
  struct System_SByte_array *v14;
  struct System_SByte_array *v16;
  s8 v17;
  struct System_SByte_array *v18;
  struct System_SByte_array *v20;
  s8 v22;
  struct System_SByte_array *v24;
  struct System_SByte_array *v26;
  s8 v27;
  struct System_SByte_array *v28;
  struct System_SByte_array *v30;
  s8 v32;
  struct System_SByte_array *v34;
  struct System_SByte_array *v36;
  s8 v38;
  u16 MaxHp;
  u16 MaxMp;
  struct datUnitWork_t_array *v45;
  datUnitWork_t_o *v46;
  datUnitWork_t_o *pStock;

  pStock = 0;
  unitwork = DDS3_GBWK->unitwork;
  v8 = unitwork->m_Items[idx];
  pStock = v8;
  v8->flag = 1;
  v8->id = DevilID;
  v8->level = Get(DevilID, 1, 0)->level;
  param = v8->param;
  v12 = Get(DevilID, 1, 0)->param;
  v13 = v12->m_Items[0];
  param->m_Items[0] = v13;
  v14 = v8->param;
  v16 = Get(DevilID, 1, 0)->param;
  v17 = v16->m_Items[1];
  v14->m_Items[1] = v17;
  v18 = v8->param;
  v20 = Get(DevilID, 1, 0)->param;
  v22 = v20->m_Items[2];
  v18->m_Items[2] = v22;
  v24 = v8->param;
  v26 = Get(DevilID, 1, 0)->param;
  v27 = v26->m_Items[3];
  v24->m_Items[3] = v27;
  v28 = v8->param;
  v30 = Get(DevilID, 1, 0)->param;
  v32 = v30->m_Items[4];
  v28->m_Items[4] = v32;
  v34 = v8->param;
  v36 = Get(DevilID, 1, 0)->param;
  v38 = v36->m_Items[5];
  v34->m_Items[5] = v38;
  MaxHp = datGetMaxHp(v8);
  v8->hp = MaxHp;
  v8->maxhp = MaxHp;
  MaxMp = datGetMaxMp(v8);
  v8->mp = MaxMp;
  v8->maxmp = MaxMp;
  cmbCreateDefaultSkill(DevilID, &pStock);
  v45 = DDS3_GBWK->unitwork;
  v46 = pStock;
  v45->m_Items[idx] = v46;
}

// 0x15895d0
void *TestProcess1(dds3ProcessID_t *id) {
    DrawTest();
    DDS3_PADCHECK_TRIG(0);
    evtBitCheck(0);
    SetBossDummy();
    evtBitOff(0);
    Get(0);
    nbInitMainProcess(0, 0, 0, 0, 0, 0);
    DDS3_PADCHECK_REP(0);
    TestSelectEncount(0, 0);
    DDS3_PADCHECK_PRESS(0);
    evtBitOn(0);
    return 0;
}

// 0x1589410
void *TestProcess2(dds3ProcessID_t *id) {
  dds3ProcessID_t_o *v3;

  else
  {
    v3 = dds3SearchProcessPriority(1018);
    if (v3)
      return 0;
  }
  nbExit(v3);
  id->func_ans = -1;
  return 0;
}

// 0x1589150
void *TestProcess3(dds3ProcessID_t *id) {
  nbTest_c *v4;
  s32 test_phearts;
  u64 *v9;

  evtBitOff(3072);
  evtBitOff(3073);
  evtBitOff(3074);
  evtBitOff(3075);
  evtBitOn(3076);
  evtBitOff(3077);
  evtBitOff(3078);
  evtBitOff(3079);
  evtBitOff(3082);
  evtBitOn(3084);
  evtBitOff(3085);
  evtBitOff(3088);
  evtBitOff(3090);
  nbSetBattleDummy(v4, test_dvllist, test_skilllist, test_pskill, test_pdummy);
  if (test_phearts < 1)
  {
    datRemoveHearts();
  }
  else
  {
    Write(StringLiteral_21667, 0);
    datAddHearts(test_phearts);
    datEquipHearts(test_phearts);
  }
  v9 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v9,
    0,
    Method_nbTest_TestProcess1__);
  return v9;
}

// 0x1588c30
void *TestProcess4(dds3ProcessID_t *id) {
  nbTest_c *v4;
  struct datUnitWork_t_array *unitwork;
  datUnitWork_t_o *v9;
  struct datUnitWork_t_array *v12;
  struct datUnitWork_t_array *v14;
  u64 v16;
  struct System_Byte_array *item;
  u64 *v19;

  evtBitOn(3072);
  evtBitOn(3073);
  evtBitOff(3074);
  evtBitOff(3075);
  evtBitOff(3076);
  evtBitOff(3077);
  evtBitOn(3078);
  evtBitOn(3079);
  evtBitOn(3082);
  evtBitOff(3085);
  evtBitOff(3088);
  evtBitOff(3090);
  nbSetBattleDummy(v4, test2_dvllist, 0, test2_pskill, test2_pdummy);
  unitwork = DDS3_GBWK->unitwork;
  v9 = unitwork->m_Items[0];
  v9->exp = rstCalcExpFromLevel(0, 50);
  v12 = DDS3_GBWK->unitwork;
  v12->m_Items[7]->hp = 0;
  v14 = DDS3_GBWK->unitwork;
  v14->m_Items[7]->badstatus = 2048;
  v16 = 0;
  DDS3_GBWK->maka = 90000;
  while (1)
  {
    item = DDS3_GBWK->item;
    item->m_Items[v16] = 9;
    if (v16 == 159)
      break;
    ++v16;
  }
  v19 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v19,
    0,
    Method_nbTest_TestProcess1__);
  return v19;
}

// 0x15888d0
void *TestProcess5(dds3ProcessID_t *id) {
  nbTest_c *v4;
  struct datUnitWork_t_array *unitwork;
  struct datUnitWork_t_array *v9;
  u64 v11;
  struct System_Byte_array *item;
  char *v14;
  u64 v15;
  s32 v16;
  struct datUnitWork_t_array *v17;
  datUnitWork_t_o *v19;
  u16 maxmp;
  u32 v21;
  struct System_Int32_array *config_data;
  struct System_Int32_array *v24;
  u64 *v26;

  evtBitOn(3072);
  evtBitOn(3073);
  evtBitOff(3074);
  evtBitOff(3075);
  evtBitOff(3076);
  evtBitOff(3077);
  evtBitOn(3078);
  evtBitOn(3079);
  evtBitOn(3082);
  evtBitOn(3084);
  evtBitOff(3085);
  evtBitOff(3088);
  evtBitOff(3090);
  nbSetBattleDummy(v4, test2_dvllist, test2_skilllist, test2_pskill, test2_pdummy);
  unitwork = DDS3_GBWK->unitwork;
  unitwork->m_Items[7]->hp = 0;
  v9 = DDS3_GBWK->unitwork;
  v9->m_Items[7]->badstatus = 2048;
  v11 = 0;
  DDS3_GBWK->maka = 90000;
  do
  {
    item = DDS3_GBWK->item;
    v14 = item + v11++;
    v14[32] = 9;
  }
  while (v11 != 160);
  v15 = 0;
  do
  {
    v17 = DDS3_GBWK->unitwork;
    v19 = v17->m_Items[v15];
    if ((v19->flag & 1) != 0 && v19->badstatus != 2048)
    {
      v19->hp = v19->maxhp;
      maxmp = v19->maxmp;
      v19->badstatus = 0;
      v19->mp = maxmp;
    }
    ++v15;
    v16 = (v21 >> 9) & 1;
  }
  while (v15 != 16);
  config_data = DDS3_GBWK->config_data;
  config_data->m_Items[11] = 1;
  v24 = DDS3_GBWK->config_data;
  v24->m_Items[12] = 1;
  v26 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v26,
    0,
    Method_nbTest_TestProcess1__);
  return v26;
}

// 0x15894b0
void *TestProcess6(dds3ProcessID_t *id) {
  s32 pack;
  s32 v4;
  s32 v6;
  u64 *v8;

  v4 = nbEncountCalc(pack, 100.0);
  if (!v4)
    return 0;
  v6 = v4;
  nbCallNewBattle(pack, v6);
  v8 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v8,
    0,
    Method_nbTest_TestProcess2__);
  return v8;
}

// 0x1589370
void *TestProcess7(dds3ProcessID_t *id) {
  u64 *v3;

  SetBossDummy();
  v3 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v3,
    0,
    Method_nbTest_TestProcess1__);
  return v3;
}

// 0x1588ef0
void *TestProcess8(dds3ProcessID_t *id) {
  nbTest_c *v4;
  struct datUnitWork_t_array *unitwork;
  datUnitWork_t_o *v9;
  u64 v11;
  struct System_Byte_array *item;
  char *v15;
  u64 *v16;

  evtBitOn(3072);
  evtBitOn(3073);
  evtBitOff(3074);
  evtBitOff(3075);
  evtBitOff(3076);
  evtBitOff(3077);
  evtBitOn(3078);
  evtBitOff(3079);
  evtBitOn(3082);
  evtBitOn(3084);
  evtBitOff(3085);
  evtBitOff(3088);
  evtBitOff(3090);
  evtBitOn(3087);
  evtBitOn(3089);
  nbSetBattleDummy(v4, test3_dvllist, test3_skilllist, test3_pskill, test3_pdummy);
  unitwork = DDS3_GBWK->unitwork;
  v9 = unitwork->m_Items[0];
  v9->exp = rstCalcExpFromLevel(0, 50);
  v11 = 0;
  f = 12;
  do
  {
    item = DDS3_GBWK->item;
    v15 = item + v11++;
    v15[32] = 9;
  }
  while (v11 != 160);
  v16 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v16,
    0,
    Method_nbTest_TestProcess1__);
  return v16;
}

// 0x158b1f0
s32 TestSelectEncount(s32 sel, bool mov) {
  if ((sel - 1) < 0x4FF)
    return sel;
  if (sel > 0)
  {
    if (mov)
    {
      if (sel <= 1327)
      {
        if (!dds3CheckDLC6())
          sel = 1328;
      }
      if ((sel - 1328) <= 0x23)
      {
        if (!dds3CheckDLC7())
          sel = 1;
      }
      if (sel > 1363)
        return 1;
    }
    else
    {
      if (sel >= 1328)
      {
        if (dds3CheckDLC7())
          return sel;
        sel = 1327;
      }
      if (!dds3CheckDLC6())
        return 1279;
    }
    return sel;
  }
  else if (dds3CheckDLC7())
  {
    return 1363;
  }
  if (dds3CheckDLC6())
    return 1327;
  else
    return 1279;
}

// 0x158b3d0
void *TestShutdown(dds3ProcessID_t *id) {
  return 0;
}

// 0x1586710
bDrawText btlDevPrintf(s32 aX, s32 aY, s32 aZ, s32 color, char *aStr, s32 f) {
  bDrawText_o result;

  result.DrawTxt = aStr;
  *&result.color = color;
  return result;
}

// 0x1586640
void btlDrawTagLink(bDrawText *setText, bDrawText dt, s32 idx) {
  s32 color;
  struct System_String_o *DrawTxt;
  struct System_Collections_Generic_List_bDrawText__array *BtlDrawText;

  color = dt.color;
  DrawTxt = dt.DrawTxt;
  setText->DrawTxt = DrawTxt;
  setText->color = color;
  _Add(BtlDrawText->m_Items[idx], *setText);
}

// 0x1585d30
void deleteBtlMenuObj(s32 idx) {
  struct UnityEngine_GameObject_array *BtlDbgMenuObj;
  UnityEngine_Object_o *v6;
  struct UnityEngine_GameObject_array *v9;
  UnityEngine_Object_o *v11;
  struct UnityEngine_GameObject_array *v12;
  struct TMPro_TextMeshProUGUI_array *BtlDbgMenuTxtTM;
  struct System_Collections_Generic_List_bDrawText__array *BtlDrawText;

  v6 = BtlDbgMenuObj->m_Items[idx];
  if (op_Inequality(v6, 0, 0))
  {
    v9 = BtlDbgMenuObj;
    v11 = v9->m_Items[idx];
    Destroy_27360000(v11);
    v12 = BtlDbgMenuObj;
    v12->m_Items[idx] = 0;
    BtlDbgMenuTxtTM->m_Items[idx] = 0;
    _Clear(BtlDrawText->m_Items[idx]);
  }
}

// 0x1585d20
s32 effBTLDebugCheckBEDFileFix(void) {
  return 1;
}

// 0x1585f30
void initBtlMenuObj(s32 x, s32 y, s32 w, s32 h, s32 idx) {
}

// 0x158b3e0
void nbExitBattleTest(void) {
  nbExit();
  dds3KillProcessName(StringLiteral_14940, 1);
}

// 0x158b460
void nbInitBattleTest(void) {
  nbTest_c *v3;
  struct System_Int32_array *config_data;
  struct System_Int32_array *v8;
  u64 *v11;
  u64 *v12;

  if (!evtBitCheck(3080))
  {
    nbSetBattleDummy(v3, test_dvllist, test_skilllist, test_pskill, test_pdummy);
    evtBitOn(3080);
  }
  evtBitOn(3712);
  DDS3_GBWK->encountcnt = 0;
  DDS3_GBWK->encountkyori = 0.0;
  config_data = DDS3_GBWK->config_data;
  config_data->m_Items[11] = 1;
  v8 = DDS3_GBWK->config_data;
  v8->m_Items[12] = 1;
  bgmloading = 0;
  v11 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v11,
    0,
    Method_nbTest_TestProcess1__);
  v12 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v12,
    0,
    Method_nbTest_TestShutdown__);
  dds3StartProcess(StringLiteral_14940, 0x2B0Cu, 1, 1, v11, 0, v12, 0, 0, 0);
}

// 0x1587760
void nbInitPlayer(void) {
  nbTest_c *v3;

  nbSetBattleDummy(v3, test_dvllist, test_skilllist, test_pskill, test_pdummy);
  evtBitOn(3076);
}

// 0x1587110
void nbSetBattleDummy(s32 pcnt, s32 **dvllist, s32 ***skilllist, s32 **pskill, datUnitWork_t *dummy) {
  System_Int32_array *v8;
  u64 v10;
  s32 v11;
  struct datUnitWork_t_array *unitwork;
  u32 v14;
  struct datUnitWork_t_array *v15;
  u64 v18;
  u64 v19;
  s32 v21;
  struct datUnitWork_t_array *v24;
  u64 v25;
  datUnitWork_t_o *v27;
  struct datUnitWork_t_array *v28;
  s32 skillcnt;
  System_Int32_array **v31;
  struct datUnitWork_t_array *v34;
  struct System_Int32_array *skill;
  s32 v39;
  s64 v40;
  struct datUnitWork_t_array *v44;
  System_Int32_array *v47;
  struct System_Int32_array *stocklist;
  s64 v50;
  struct System_Int32_array *v52;
  s64 v53;
  char *v55;
  s32 v56;
  u64 v57;
  s32 *m_Items;
  s64 v59;
  struct datUnitWork_t_array *v62;
  struct System_Int32_array *v64;
  s32 v66;
  struct datUnitWork_t_array *v68;
  u64 v70;
  struct System_Byte_array *item;
  System_Int32_array *v74;

  v8 = dvllist;
  v10 = 0;
  do
  {
    unitwork = DDS3_GBWK->unitwork;
    datUnitWork_t__Clear(unitwork->m_Items[v10]);
    ++v10;
    v11 = (v14 >> 9) & 1;
  }
  while (v10 != 16);
  v15 = DDS3_GBWK->unitwork;
  datUnitWork_t__Copy(v15->m_Items[0], dummy);
  v18 = 0;
  LODWORD(v19) = 0;
  v74 = v8;
  while (1)
  {
    v21 = v8->m_Items[v18];
    if (v21 < 0)
      break;
    v24 = DDS3_GBWK->unitwork;
    v25 = v18 + 4;
    v27 = v24->m_Items[v25];
    datSetDevilWork(v21, v27);
    v28 = DDS3_GBWK->unitwork;
    skillcnt = v28->m_Items[v25]->skillcnt;
    if (skilllist)
    {
      v19 = 0;
      v31 = &skilllist->m_Items[v18];
      while (1)
      {
        if ((*v31)->m_Items[v19] < 0)
          break;
        v34 = DDS3_GBWK->unitwork;
        skill = v34->m_Items[v25]->skill;
        v39 = (*v31)->m_Items[v19];
        v40 = skillcnt + v19;
        ++v19;
        skill->m_Items[v40] = v39;
        if (v18 >= LODWORD(skilllist->max_length))
      }
    }
    v44 = DDS3_GBWK->unitwork;
    v8 = v74;
    ++v18;
    v44->m_Items[v25]->skillcnt = v19 + skillcnt;
    if (v18 >= LODWORD(v74->max_length))
  }
  {
    v47 = pskill;
  }
  else
  {
    v47 = pskill;
  }
  DDS3_GBWK->stockcnt = v18 + 1;
  stocklist = DDS3_GBWK->stocklist;
  stocklist->m_Items[0] = 0;
  if (v18)
  {
    v50 = 0;
    do
    {
      v52 = DDS3_GBWK->stocklist;
      v53 = v50 + 1;
      v55 = v52 + 4 * v50;
      v56 = v50++ + 4;
      *(v55 + 9) = v56;
    }
    while (v18 != v53);
  }
  v57 = 0;
  m_Items = v47->m_Items;
  while (1)
  {
    if (m_Items[v57] < 0)
      break;
    v62 = DDS3_GBWK->unitwork;
    v64 = v62->m_Items[0]->skill;
    v66 = m_Items[v57];
    v59 = v64 + 4 * v57++;
    *(v59 + 32) = v66;
    if (v57 >= LODWORD(v47->max_length))
  }
  v68 = DDS3_GBWK->unitwork;
  v68->m_Items[0]->skillcnt = v57;
  v70 = 0;
  DDS3_GBWK->maka = 0;
  while (1)
  {
    item = DDS3_GBWK->item;
    item->m_Items[v70] = 0;
    if (v70 == 159)
      break;
    ++v70;
  }
}
