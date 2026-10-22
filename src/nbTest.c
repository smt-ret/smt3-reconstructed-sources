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
  char *v3;
  s32 v7;
  nbTest_c *v8;
  s16 v9;
  s32 v10;
  char *v12;
  s32 v13;
  System_String_o *v14;
  s64 *v15;
  struct System_String_o *v20;
  bool v22;
  s64 *v23;
  bool v25;
  bool v27;
  bool v29;
  bool v31;
  bool v33;
  bool v35;
  bool v37;
  bool v39;
  bool v41;
  bool v43;
  bool v45;
  bool v47;
  bool v49;
  s32 Bit;
  bool v52;
  bool v54;
  bool v56;
  bool v58;
  bool v60;
  s32 skillchg;
  bool v64;
  bool v66;
  bool v68;
  System_String_o *v69;
  System_String_array *v71;
  s64 *v73;
  s64 *v74;
  s64 *v79;
  s64 *v80;
  s64 v88;
  u64 v89;
  s32 f;
  struct System_UInt16_array *devil;
  s32 v94;
  struct System_UInt16_array *v96;
  s32 v98;
  s32 v100;
  System_String_o *v101;
  s32 EncountMax;
  s32 EncountCnt;
  bDrawText_o v105;
  bDrawText_o v106;
  bDrawText_o v107;
  bDrawText_o v108;
  bDrawText_o v109;

  v3 = &byte_3F59000;
  EncountCnt = 0;
  EncountMax = 0;
  v105.DrawTxt = "BATTLE ENCOUNT\n";
  *&v105.color = 0;
  btlDrawTagLink(&bsetText, v105, 0);
  v7 = 0;
  if ((v9 & 0x200) == 0)
    goto LABEL_279;
  while (2)
  {
    v10 = v9 & 0x200;
    if (v7 < selectmax)
    {
LABEL_10:
      v12 = v3;
      v3 = (4 * (v7 == cur));
      switch (v7)
      {
        case 0:
          if ((*&v8->_2.bitflags1 & 0x200) != 0)
          {
            else
            {
              if (mode)
              {
LABEL_16:
                v14 = sub_232970(&pack);
                v15 = &"ENCPACK   :";
                goto LABEL_156;
              }
            }
          }
          else
          {
            v13 = 0;
            if (mode)
              goto LABEL_16;
          }
          v69 = sub_232A70(&f, "x4");
          v107.DrawTxt = Concat_5221536("ENCOUNT   :", v69, "\n");
          *&v107.color = v3;
          btlDrawTagLink(&bsetText, v107, 0);
          evtBitCheck(3083);
          ++v7;
          if ((v9 & 0x200) != 0)
            continue;
LABEL_279:
          v10 = 0;
          if (v7 >= selectmax)
            goto LABEL_313;
          goto LABEL_10;
        case 1:
          else if (mode)
          {
            goto LABEL_23;
          }
          v71 = NewSpecific(string, 5u);
          v71->m_Items[0] = "STAGE     :";
          v73 = sub_232970(&stagemajor);
          v74 = v73;
          v71->m_Items[1] = v74;
          v71->m_Items[2] = "_";
          v79 = sub_232970(&stageminor);
          v80 = v79;
          v71->m_Items[3] = v80;
          v71->m_Items[4] = "\n";
          v20 = Concat_5271600(v71);
LABEL_157:
          v106.DrawTxt = v20;
LABEL_277:
          *&v106.color = v3;
          btlDrawTagLink(&bsetText, v106, 0);
LABEL_278:
          ++v7;
          if ((v9 & 0x200) == 0)
            goto LABEL_279;
          continue;
        case 2:
          v14 = sub_232970(&num);
          v15 = &"PLAYER    :";
          goto LABEL_156;
        case 3:
          v22 = evtBitCheck(3072);
          if (v22)
          {
            v23 = &"DAMAGE    :OFF\n";
          }
          else
          {
            v23 = &"DAMAGE    :ON\n";
          }
          goto LABEL_276;
        case 4:
          v25 = evtBitCheck(3073);
          if (v25)
          {
            v23 = &"PRESS     :OFF\n";
          }
          else
          {
            v23 = &"PRESS     :ON\n";
          }
          goto LABEL_276;
        case 5:
          v27 = evtBitCheck(3074);
          if (v27)
          {
            v23 = &"CHANGE    :OFF\n";
          }
          else
          {
            v23 = &"CHANGE    :ON\n";
          }
          goto LABEL_276;
        case 6:
          v29 = evtBitCheck(3075);
          if (v29)
          {
            v23 = &"NEGODEBUG :ON\n";
          }
          else
          {
            v23 = &"NEGODEBUG :OFF\n";
          }
          goto LABEL_276;
        case 7:
          v31 = evtBitCheck(3076);
          if (v31)
          {
            v23 = &"NEGOBOUGAI:ON\n";
          }
          else
          {
            v23 = &"NEGOBOUGAI:OFF\n";
          }
          goto LABEL_276;
        case 8:
          v33 = evtBitCheck(3077);
          if (v33)
          {
            v23 = &"NEGOJIHATU:ON\n";
          }
          else
          {
            v23 = &"NEGOJIHATU:OFF\n";
          }
          goto LABEL_276;
        case 9:
          v35 = evtBitCheck(3078);
          if (v35)
          {
            v23 = &"ALLSKILL  :ON\n";
          }
          else
          {
            v23 = &"ALLSKILL  :OFF\n";
          }
          goto LABEL_276;
        case 10:
          v37 = evtBitCheck(3079);
          if (v37)
          {
            v23 = &"ALLHIT    :ON\n";
          }
          else
          {
            v23 = &"ALLHIT    :OFF\n";
          }
          goto LABEL_276;
        case 11:
          v39 = evtBitCheck(3081);
          if (v39)
          {
            v23 = &"HITSTOP   :ON\n";
          }
          else
          {
            v23 = &"HITSTOP   :OFF\n";
          }
          goto LABEL_276;
        case 12:
          v41 = evtBitCheck(3082);
          if (v41)
          {
            v23 = &"SENSEIOFF :ON\n";
          }
          else
          {
            v23 = &"SENSEIOFF :OFF\n";
          }
          goto LABEL_276;
        case 13:
          v43 = evtBitCheck(3085);
          if (v43)
          {
            v23 = &"ALLHANSYA :ON\n";
          }
          else
          {
            v23 = &"ALLHANSYA :OFF\n";
          }
          goto LABEL_276;
        case 14:
          v45 = evtBitCheck(3088);
          if (v45)
          {
            v23 = &"ALLBACKATK:ON\n";
          }
          else
          {
            v23 = &"ALLBACKATK:OFF\n";
          }
          goto LABEL_276;
        case 15:
          v47 = evtBitCheck(3090);
          if (v47)
          {
            v23 = &"ALLSENSEI :ON\n";
          }
          else
          {
            v23 = &"ALLSENSEI :OFF\n";
          }
          goto LABEL_276;
        case 16:
          if ((v8->_2.bitflags2 & 2) != 0)
          {
            {
            }
          }
          v23 = &"BTL_TEST  :ON\n";
          goto LABEL_276;
        case 17:
          v49 = evtBitCheck(3712);
          if (v49)
          {
            v23 = &"DANTE    :ON\n";
          }
          else
          {
            v23 = &"DANTE   :OFF\n";
          }
          goto LABEL_276;
        case 18:
          Bit = cfgGetBit(9u);
          if (Bit == 2)
          {
            v23 = &"DIFFICULTY:HARD  \n";
          }
          else if (Bit == 1)
          {
            v23 = &"DIFFICULTY:NORMAL\n";
          }
          else
          {
            if (Bit)
              goto LABEL_278;
            v23 = &"DIFFICULTY:EASY  \n";
          }
LABEL_276:
          v106.DrawTxt = *v23;
          goto LABEL_277;
        case 19:
          v52 = evtBitCheck(3824);
          if (v52)
          {
            v23 = &"連続戦闘:ON\n";
          }
          else
          {
            v23 = &"連続戦闘:OFF\n";
          }
          goto LABEL_276;
        case 20:
          v14 = sub_232970(&renzokucnt);
          v15 = &"連続戦闘回数:";
          goto LABEL_156;
        case 21:
          v54 = evtBitCheck(3825);
          if (v54)
          {
            v23 = &"必ずクリティカル:ON\n";
          }
          else
          {
            v23 = &"必ずクリティカル:OFF\n";
          }
          goto LABEL_276;
        case 22:
          v56 = evtBitCheck(3826);
          if (v56)
          {
            v23 = &"必ず状態異常:ON\n";
          }
          else
          {
            v23 = &"必ず状態異常:OFF\n";
          }
          goto LABEL_276;
        case 23:
          v58 = evtBitCheck(3827);
          if (v58)
          {
            v23 = &"攻撃（回復）のランダムOFF:ON\n";
          }
          else
          {
            v23 = &"攻撃（回復）のランダムOFF:OFF\n";
          }
          goto LABEL_276;
        case 24:
          v60 = evtBitCheck(3828);
          if (v60)
          {
            v23 = &"敵使用スキルチェンジ:ON\n";
          }
          else
          {
            v23 = &"敵使用スキルチェンジ:OFF\n";
          }
          goto LABEL_276;
        case 25:
          v14 = Get(skillchg, 0, 0);
          v15 = &"敵使用スキル:";
LABEL_156:
          v20 = Concat_5221536(*v15, v14, "\n");
          goto LABEL_157;
        case 26:
          v64 = evtBitCheck(3829);
          if (v64)
          {
            v23 = &"必ず自動効果スキル発生:ON\n";
          }
          else
          {
            v23 = &"必ず自動効果スキル発生:OFF\n";
          }
          goto LABEL_276;
        case 27:
          v66 = evtBitCheck(3830);
          if (v66)
          {
            v23 = &"効果きれない:ON\n";
          }
          else
          {
            v23 = &"効果きれない:OFF\n";
          }
          goto LABEL_276;
        case 28:
          v68 = evtBitCheck(3831);
          if (v68)
          {
            v23 = &"ランダムログ:ON\n";
          }
          else
          {
            v23 = &"ランダムログ:OFF\n";
          }
          goto LABEL_276;
        default:
          v3 = v12;
          goto LABEL_278;
      }
    }
    break;
  }
LABEL_313:
  v108.DrawTxt = "\n";
  *&v108.color = 1;
  btlDrawTagLink(&bsetText, v108, 0);
  evtBitCheck(3083);
  if (f <= 1363)
  {
    v88 = 16;
      goto LABEL_321;
LABEL_318:
    while (1)
    {
LABEL_321:
      v89 = v88 - 16;
      devil = Get(f, 0)->devil;
      if (*(&devil->obj.klass + v88))
      {
        v94 = f;
        v96 = Get(v94, 0)->devil;
        v98 = *(&v96->obj.klass + v88);
        v100 = convDLCDevilNumber(v98);
        v101 = Get(v100, 0);
        v109.DrawTxt = Concat_5224608(v101, "\n");
        *&v109.color = 0;
        btlDrawTagLink(&bsetText, v109, 0);
      }
      if (v88 == 26)
        break;
      ++v88;
        goto LABEL_318;
    }
  }
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
  s32 v3;
  System_String_o *v4;
  System_String_o *DrawTxt;
  System_String_o *v7;
  struct System_Collections_Generic_List_bDrawText__array *BtlDrawText;
  s32 Count;
  struct System_Collections_Generic_List_bDrawText__array *v13;
  struct System_Collections_Generic_List_bDrawText__array *v16;
  s64 *v18;
  System_String_o *v19;
  struct System_Collections_Generic_List_bDrawText__array *v21;
  struct System_Collections_Generic_List_bDrawText__array *v24;
  struct System_Collections_Generic_List_bDrawText__array *v27;
  System_String_o *v30;
  struct System_Collections_Generic_List_bDrawText__array *v32;
  struct System_Collections_Generic_List_bDrawText__array *v35;
  System_String_o *v37;
  struct TMPro_TextMeshProUGUI_array *BtlDbgMenuTxtTM;
  s32 v40;
  bDrawText_o Item;
  bDrawText_o v42;
  bDrawText_o v43;
  bDrawText_o v44;
  bDrawText_o v45;

  v3 = 0;
  v40 = 0;
  v4 = "";
  {
LABEL_4:
    goto LABEL_7;
  }
  while (1)
  {
LABEL_7:
    Count = _get_Count(BtlDrawText->m_Items[idx]);
    if (v3 >= Count)
      break;
    v13 = BtlDrawText;
    Item = _get_Item(
             v13->m_Items[idx],
             v3);
    if (Item.color)
    {
      v16 = BtlDrawText;
      v42 = _get_Item(
              v16->m_Items[idx],
              v3);
      if (v42.color == 6)
      {
        v18 = &"<color=#008080>";
      }
      else
      {
        v21 = BtlDrawText;
        v43 = _get_Item(
                v21->m_Items[idx],
                v3);
        if (v43.color == 2)
        {
          v18 = &"<color=#ff0000>";
        }
        else
        {
          v24 = BtlDrawText;
          v44 = _get_Item(
                  v24->m_Items[idx],
                  v3);
          if (v44.color == 4)
          {
            v18 = &"<color=#00ff00>";
          }
          else
          {
            v27 = BtlDrawText;
            v45 = _get_Item(
                    v27->m_Items[idx],
                    v3);
            if (v45.color != 5)
            {
              v35 = BtlDrawText;
              v40 = _get_Item(
                      v35->m_Items[idx],
                      v3).color
                  & 0xFFFFFF;
              v37 = sub_232A70(&v40, "X");
              v30 = Concat_5271136(v4, "<color=#", v37, ">");
                goto LABEL_49;
LABEL_47:
              goto LABEL_49;
            }
            v18 = &"<color=#0000ff>";
          }
        }
      }
      v19 = *v18;
    }
    else
    {
      v19 = "<color=#ffffff>";
    }
    v30 = Concat_5224608(v4, v19);
      goto LABEL_47;
LABEL_49:
    v32 = BtlDrawText;
    DrawTxt = _get_Item(
                v32->m_Items[idx],
                v3).DrawTxt;
    v7 = Concat_5224608(v30, DrawTxt);
    v4 = Concat_5224608(v7, "</color>");
    ++v3;
      goto LABEL_4;
  }
  set_text(BtlDbgMenuTxtTM->m_Items[idx], v4);
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
  System_Array_o *v2;
  s64 i;
  struct datUnitWork_t_array *unitwork;
  s64 v11;
  s64 v12;
  s64 v14;
  struct datUnitWork_t_array *v16;
  u64 v17;
  struct datUnitWork_t_array *v20;
  struct datUnitWork_t_array *v23;
  struct datUnitWork_t_array *v28;
  struct datUnitWork_t_array *v29;
  u64 *v33;
  intptr_t *v34;
  s32 v43;
  datEncount_t_o *v44;
  s32 v45;
  datEncount_t_o *v46;
  nbTest_c *v50;
  struct nbTest_StaticFields **p_static_fields;
  s32 cur;
  s16 v54;
  s32 v55;
  struct nbTest_StaticFields *v56;
  bool v60;
  s64 v62;
  s32 v64;
  datEncount_t_o *v65;
  s64 v66;
  s32 stageid;
  s32 areaid;
  nbTest_c *v71;
  s32 f;
  s32 stageminor;
  s32 stagemajor;
  s32 v76;
  s32 v77;
  s32 v78;
  s32 num;
  s64 v81;
  s32 v83;
  nbTest_c *v86;
  struct nbTest_StaticFields **v88;
  s32 v89;
  s16 v90;
  s32 v91;
  struct nbTest_StaticFields *v92;
  s32 v94;
  s32 v95;
  nbTest_c *v98;
  struct nbTest_StaticFields **v100;
  s32 v101;
  s16 v102;
  s32 v103;
  struct nbTest_StaticFields *v104;
  nbTest_c *v108;
  struct nbTest_StaticFields **v110;
  s32 v111;
  s16 v112;
  s32 v113;
  struct nbTest_StaticFields *v114;
  s32 v116;
  nbTest_c *v119;
  struct nbTest_StaticFields **v120;
  s16 v122;
  s32 v123;
  struct nbTest_StaticFields *v124;
  nbTest_c *v128;
  struct nbTest_StaticFields **v129;
  s16 v133;
  s32 v134;
  struct nbTest_StaticFields *v135;
  s32 v138;
  s32 v139;
  s32 Bit;
  s32 v150;
  s32 v151;
  Il2CppObject *v157;

  v2 = NewSpecific(s32, 0x10u);
  InitializeArray_1543888(v2, Field__PrivateImplementationDetails__203CA16D7E347680C2A4813955C1269C081DBDEC);
  DrawTest();
  else if (DDS3_PADCHECK_TRIG(1))
  {
LABEL_9:
    for (i = 8; i != 20; ++i)
    {
      unitwork = DDS3_GBWK->unitwork;
      v11 = *(&unitwork->obj.klass + i);
      *(v11 + 16) &= ~2u;
    }
    v12 = 8;
    v14 = 0;
    {
LABEL_17:
    }
    while (v14 < num - 1LL)
    {
      v16 = DDS3_GBWK->unitwork;
      v17 = v12 - 4;
      if ((*(*(&v16->obj.klass + v12) + 16LL) & 1) != 0)
      {
        v20 = DDS3_GBWK->unitwork;
        if (*(*(&v20->obj.klass + v12) + 30LL) != 2048)
        {
          v23 = DDS3_GBWK->unitwork;
          *(*(&v23->obj.klass + v12) + 16LL) |= 2u;
        }
      }
      ++v12;
      v14 = v12 - 8;
        goto LABEL_17;
    }
    if (evtBitCheck(3083))
    {
      SetBossDummy();
    }
    v28 = DDS3_GBWK->unitwork;
    v28->m_Items[0]->hp = DDS3_GBWK->unitwork->m_Items[0]->maxhp;
    v29 = DDS3_GBWK->unitwork;
    v29->m_Items[4]->hp = v29->m_Items[4]->maxhp;
    evtBitOff(2080);
    evtBitOff(2081);
    evtBitOff(2082);
    evtBitOff(2083);
    evtBitOff(2084);
    evtBitOff(2085);
    evtBitOff(2086);
    evtBitOff(2087);
    evtBitOff(2088);
    evtBitOff(2089);
    evtBitOff(2090);
    evtBitOff(2091);
    evtBitOff(2092);
    evtBitOff(2093);
    evtBitOff(2094);
    evtBitOff(2095);
    evtBitOff(2096);
    evtBitOff(2097);
    evtBitOff(2098);
    evtBitOff(2099);
    evtBitOff(2100);
    evtBitOff(2101);
    evtBitOff(2102);
    evtBitOff(2103);
    evtBitOff(2104);
    evtBitOff(2105);
    evtBitOff(2106);
    evtBitOff(2107);
    evtBitOff(2108);
    evtBitOff(2109);
    evtBitOff(2110);
    evtBitOff(2111);
    else if (mode)
    {
      goto LABEL_54;
    }
    v60 = evtBitCheck(3083);
    if (!v60)
    {
      v76 = f;
      v77 = stagemajor;
      v78 = stageminor;
      goto LABEL_173;
    }
    v62 = f;
    v64 = *(&v2[2].klass + v62);
    v65 = Get(v64, 0);
    v66 = f;
    stageid = v65->stageid;
    areaid = Get(*(&v2[2].klass + v66), 0)->areaid;
    if (areaid | stageid)
    {
      {
LABEL_167:
        v81 = f;
        v83 = *(&v2[2].klass + v81);
        v76 = v83;
        v77 = stageid;
        v78 = areaid;
LABEL_173:
        nbInitMainProcess(0, 0, 0, v76, v77, v78);
        v33 = Allocate(System_Func_dds3ProcessID_t__object_);
        v34 = &Method_nbTest_TestProcess2__;
LABEL_523:
        v157 = v33;
        object____ctor(v33, 0, *v34);
        return v157;
      }
    }
    else
    {
      stageid = stagemajor;
      areaid = stageminor;
      if ((v71->_2.bitflags2 & 2) == 0)
        goto LABEL_167;
    }
    goto LABEL_167;
  }
  if (DDS3_PADCHECK_REP(6))
  {
    --cur;
    if (cur < 0)
    {
      cur = selectmax - 1;
    }
  }
  if (DDS3_PADCHECK_REP(7))
  {
    ++cur;
    if (cur >= selectmax)
    {
      cur = 0;
    }
  }
  if (DDS3_PADCHECK_REP(14))
  {
    v43 = f;
    v44 = Get(v43, 0);
    v45 = v44->stageid;
    if (v44->stageid)
    {
      v46 = v44;
      if (v44->areaid)
      {
        stagemajor = v45;
        stageminor = v46->areaid;
      }
    }
  }
  else if (!DDS3_PADCHECK_REP(5))
  {
    goto LABEL_181;
  }
  if (cur == 2)
  {
    if (num <= 3)
    {
      num = num + 1;
        goto LABEL_182;
LABEL_183:
      if (!DDS3_PADCHECK_REP(4))
        goto LABEL_232;
      goto LABEL_184;
    }
LABEL_181:
      goto LABEL_183;
    goto LABEL_182;
  }
  if (cur == 1)
  {
    if (!mode)
    {
      ++stagemajor;
        goto LABEL_182;
      goto LABEL_183;
    }
    goto LABEL_181;
  }
  if (cur)
    goto LABEL_181;
  v54 = *&v50->_2.bitflags1;
  if ((v54 & 0x200) == 0)
  {
    v55 = 0;
    if (mode)
      goto LABEL_110;
    goto LABEL_177;
  }
  v55 = v54 & 0x200;
  if (!mode)
  {
LABEL_177:
    ++f;
    f = TestSelectEncount((*p_static_fields)->f, 1);
    goto LABEL_181;
  }
LABEL_110:
  ++pack;
  v56 = *p_static_fields;
  if ((*p_static_fields)->pack < 1281)
    goto LABEL_181;
  v56->pack = 1;
    goto LABEL_183;
LABEL_182:
    goto LABEL_183;
  if (!DDS3_PADCHECK_REP(4))
    goto LABEL_232;
LABEL_184:
  v89 = cur;
  if (v89 == 2)
  {
    v94 = num;
    if (v94 >= 2)
    {
      num = v94 - 1;
        goto LABEL_233;
LABEL_234:
      if (!DDS3_PADCHECK_REP(10))
        goto LABEL_269;
      goto LABEL_235;
    }
LABEL_232:
      goto LABEL_234;
    goto LABEL_233;
  }
  if (v89 == 1)
  {
    if (!mode)
    {
      v95 = stagemajor;
      if (v95 >= 2)
      {
        stagemajor = v95 - 1;
          goto LABEL_233;
        goto LABEL_234;
      }
    }
    goto LABEL_232;
  }
  if (v89)
    goto LABEL_232;
  v90 = *&v86->_2.bitflags1;
  if ((v90 & 0x200) == 0)
  {
    v91 = 0;
    if (mode)
      goto LABEL_192;
    goto LABEL_228;
  }
  v91 = v90 & 0x200;
  if (!mode)
  {
LABEL_228:
    --f;
    f = TestSelectEncount((*v88)->f, 0);
    goto LABEL_232;
  }
LABEL_192:
  --pack;
  v92 = *v88;
  if ((*v88)->pack > 0)
    goto LABEL_232;
  v92->pack = 1279;
    goto LABEL_234;
LABEL_233:
    goto LABEL_234;
  if (!DDS3_PADCHECK_REP(10))
    goto LABEL_269;
LABEL_235:
  v101 = cur;
  if (v101 != 1)
  {
    if (v101)
      goto LABEL_269;
    v102 = *&v98->_2.bitflags1;
    if ((v102 & 0x200) != 0)
    {
      v103 = v102 & 0x200;
      if (mode)
      {
LABEL_242:
        pack += 16;
        v104 = *v100;
        if ((*v100)->pack >= 1281)
        {
          v104->pack = 1;
            goto LABEL_271;
          goto LABEL_270;
        }
LABEL_269:
          goto LABEL_271;
        goto LABEL_270;
      }
    }
    else
    {
      v103 = 0;
      if (mode)
        goto LABEL_242;
    }
    f += 16;
    f = TestSelectEncount((*v100)->f, 1);
    goto LABEL_269;
  }
  if (mode)
    goto LABEL_269;
  ++stageminor;
  {
LABEL_271:
    if (!DDS3_PADCHECK_REP(8))
      goto LABEL_310;
    goto LABEL_272;
  }
LABEL_270:
    goto LABEL_271;
  if (!DDS3_PADCHECK_REP(8))
    goto LABEL_310;
LABEL_272:
  v111 = cur;
  if (v111 != 1)
  {
    if (v111)
      goto LABEL_310;
    v112 = *&v108->_2.bitflags1;
    if ((v112 & 0x200) != 0)
    {
      v113 = v112 & 0x200;
      if (mode)
      {
LABEL_279:
        pack -= 16;
        v114 = *v110;
        if ((*v110)->pack <= 0)
        {
          v114->pack = 1279;
            goto LABEL_312;
          goto LABEL_311;
        }
LABEL_310:
          goto LABEL_312;
        goto LABEL_311;
      }
    }
    else
    {
      v113 = 0;
      if (mode)
        goto LABEL_279;
    }
    f -= 16;
    f = TestSelectEncount((*v110)->f, 0);
    goto LABEL_310;
  }
  if (mode)
    goto LABEL_310;
  v116 = stageminor;
  if (v116 < 2)
    goto LABEL_310;
  stageminor = v116 - 1;
  {
LABEL_312:
    if (!DDS3_PADCHECK_REP(11))
      goto LABEL_329;
    goto LABEL_313;
  }
LABEL_311:
    goto LABEL_312;
  if (!DDS3_PADCHECK_REP(11))
    goto LABEL_329;
LABEL_313:
  if (cur)
    goto LABEL_329;
  v122 = *&v119->_2.bitflags1;
  if ((v122 & 0x200) != 0)
  {
    v123 = v122 & 0x200;
    if (mode)
    {
LABEL_319:
      pack += 256;
      v124 = *v120;
      if (v124->pack >= 1281)
      {
        v124->pack = 1;
          goto LABEL_332;
LABEL_330:
        goto LABEL_332;
      }
LABEL_329:
        goto LABEL_332;
      goto LABEL_330;
    }
  }
  else
  {
    v123 = 0;
    if (mode)
      goto LABEL_319;
  }
  f += 256;
  f = TestSelectEncount((*v120)->f, 1);
    goto LABEL_330;
LABEL_332:
  if (!DDS3_PADCHECK_REP(9))
    goto LABEL_337;
  if (cur)
  {
LABEL_337:
      goto LABEL_340;
    goto LABEL_338;
  }
  v133 = *&v128->_2.bitflags1;
  if ((v133 & 0x200) == 0)
  {
    v134 = 0;
    if (mode)
      goto LABEL_347;
LABEL_395:
    f -= 256;
    f = TestSelectEncount((*v129)->f, 0);
      goto LABEL_340;
LABEL_338:
    goto LABEL_340;
  }
  v134 = v133 & 0x200;
  if (!mode)
    goto LABEL_395;
LABEL_347:
  pack -= 256;
  v135 = *v129;
  if (v135->pack > 0)
    goto LABEL_337;
  v135->pack = 1279;
    goto LABEL_338;
LABEL_340:
  if (DDS3_PADCHECK_PRESS(9))
  {
    else if (DDS3_PADCHECK_PRESS(11))
    {
LABEL_344:
      v33 = Allocate(System_Func_dds3ProcessID_t__object_);
      v34 = &Method_nbTest_TestProcess7__;
      goto LABEL_523;
    }
  }
  else if (!DDS3_PADCHECK_TRIG(4))
  {
LABEL_368:
    if (!DDS3_PADCHECK_TRIG(5))
    {
LABEL_510:
        goto LABEL_511;
      goto LABEL_387;
    }
  }
  else
  {
    v138 = cur;
    if (v138 < 3)
      goto LABEL_510;
  }
  v139 = 3081;
  switch (v138)
  {
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
      v139 = v138 + 3069;
      if (v138 == -3070)
        goto LABEL_510;
      goto LABEL_385;
    case 11:
LABEL_385:
      if (evtBitCheck(v139))
        goto LABEL_386;
      goto LABEL_509;
    case 12:
      v139 = 3082;
      if (!evtBitCheck(3082))
        goto LABEL_509;
      goto LABEL_386;
    case 13:
      v139 = 3085;
      if (!evtBitCheck(3085))
        goto LABEL_509;
      goto LABEL_386;
    case 14:
      v139 = 3088;
      if (!evtBitCheck(3088))
        goto LABEL_509;
      goto LABEL_386;
    case 15:
      v139 = 3090;
      if (!evtBitCheck(3090))
        goto LABEL_509;
      goto LABEL_386;
    case 17:
      v139 = 3712;
      if (!evtBitCheck(3712))
        goto LABEL_509;
      goto LABEL_386;
    case 18:
      if (DDS3_PADCHECK_TRIG(4))
      {
        Bit = cfgGetBit(9u);
        if (Bit != 2)
        {
          if (Bit != 1)
          {
            if (Bit)
              goto LABEL_508;
            goto LABEL_503;
          }
LABEL_499:
          v151 = 0;
          goto LABEL_507;
        }
LABEL_473:
        v151 = 1;
        goto LABEL_507;
      }
      if (DDS3_PADCHECK_TRIG(5))
      {
        v150 = cfgGetBit(9u);
        if (v150 == 2)
          goto LABEL_499;
        if (v150 == 1)
        {
LABEL_503:
          v151 = 2;
LABEL_507:
          cfgSetBit_22187328(9u, v151);
          goto LABEL_508;
        }
        if (v150)
          goto LABEL_508;
        goto LABEL_473;
      }
LABEL_508:
      v139 = 0;
      if (!evtBitCheck(0))
      {
LABEL_509:
        evtBitOn(v139);
        goto LABEL_510;
      }
LABEL_386:
      evtBitOff(v139);
        goto LABEL_511;
LABEL_387:
LABEL_511:
      if (DDS3_PADCHECK_TRIG(2))
      {
LABEL_512:
        v33 = Allocate(System_Func_dds3ProcessID_t__object_);
        v34 = &Method_nbTest_TestProcess3__;
        goto LABEL_523;
      }
LABEL_513:
      else if (DDS3_PADCHECK_TRIG(0))
      {
LABEL_516:
        v33 = Allocate(System_Func_dds3ProcessID_t__object_);
        v34 = &Method_nbTest_TestProcess4__;
        goto LABEL_523;
      }
      if (DDS3_PADCHECK_TRIG(3))
      {
        v33 = Allocate(System_Func_dds3ProcessID_t__object_);
        v34 = &Method_nbTest_TestProcess5__;
        goto LABEL_523;
      }
      v157 = 0;
      if (DDS3_PADCHECK_TRIG(13))
      {
        v157 = 0;
        mode ^= 1u;
      }
      return v157;
    case 19:
      v139 = 3824;
      if (!evtBitCheck(3824))
        goto LABEL_509;
      goto LABEL_386;
    case 20:
      if (DDS3_PADCHECK_TRIG(4))
      {
        --renzokucnt;
        if ((renzokucnt & 0x80000000) == 0)
          goto LABEL_510;
        renzokucnt = 0;
          goto LABEL_387;
      }
      else
      {
        if (!DDS3_PADCHECK_TRIG(5))
          goto LABEL_510;
        ++renzokucnt;
          goto LABEL_387;
      }
      goto LABEL_511;
    case 21:
      v139 = 3825;
      if (!evtBitCheck(3825))
        goto LABEL_509;
      goto LABEL_386;
    case 22:
      v139 = 3826;
      if (!evtBitCheck(3826))
        goto LABEL_509;
      goto LABEL_386;
    case 23:
      v139 = 3827;
      if (!evtBitCheck(3827))
        goto LABEL_509;
      goto LABEL_386;
    case 24:
      v139 = 3828;
      if (!evtBitCheck(3828))
        goto LABEL_509;
      goto LABEL_386;
    case 25:
      if (DDS3_PADCHECK_TRIG(4))
      {
        --skillchg;
        if (skillchg > 0)
          goto LABEL_510;
        skillchg = 287;
          goto LABEL_387;
      }
      else
      {
        if (!DDS3_PADCHECK_TRIG(5))
          goto LABEL_510;
        ++skillchg;
        if (skillchg < 288)
          goto LABEL_510;
        skillchg = 1;
          goto LABEL_387;
      }
      goto LABEL_511;
    case 26:
      v139 = 3829;
      if (!evtBitCheck(3829))
        goto LABEL_509;
      goto LABEL_386;
    case 27:
      v139 = 3830;
      if (!evtBitCheck(3830))
        goto LABEL_509;
      goto LABEL_386;
    case 28:
      v139 = 3831;
      if (!evtBitCheck(3831))
        goto LABEL_509;
      goto LABEL_386;
    default:
      goto LABEL_508;
  }
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
    Write("set devilhearts!!\n", 0);
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
  dds3GlobalWork_c *v11;
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
  if ((v11->_2.bitflags2 & 2) != 0)
  {
LABEL_21:
    goto LABEL_23;
  }
  while (1)
  {
LABEL_23:
    item = DDS3_GBWK->item;
    item->m_Items[v16] = 9;
    if (v16 == 159)
      break;
    ++v16;
      goto LABEL_21;
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
  s32 v9;
  struct System_Collections_Generic_List_bDrawText__array *BtlDrawText;
  struct System_Collections_Generic_List_bDrawText__array *v16;
  u64 *v17;
  struct UnityEngine_GameObject_array *BtlDbgMenuObj;
  UnityEngine_Object_o *v22;
  s32 v25;
  s32 v26;
  s32 v27;
  struct UnityEngine_GameObject_array *v28;
  Il2CppObject *object;
  UnityEngine_GameObject_o *v30;
  UnityEngine_Transform_o *transform;
  s64 *v33;
  s64 *v34;
  struct TMPro_TextMeshProUGUI_array *BtlDbgMenuTxtTM;
  struct UnityEngine_GameObject_array *v39;
  UnityEngine_Transform_o *v41;
  UnityEngine_Component_o *v42;
  s64 *Component_GUILayer;
  s64 *v44;
  struct System_Collections_Generic_List_bDrawText__array *v47;
  struct UnityEngine_GameObject_array *v50;
  UnityEngine_Object_o *v52;
  struct UnityEngine_GameObject_array *v55;
  UnityEngine_Transform_o *v57;
  s64 *Enumerator;
  UnityEngine_Component_o *v59;
  UnityEngine_Component_c *klass;
  s64 typeHierarchyDepth;
  char *v62;
  s64 *v63;
  UnityEngine_GUILayer_o *v65;
  s64 *Interface;
  s32 v67;
  UnityEngine_Vector3_o v68;
  char *v69;
  UnityEngine_Vector2_o v70;

  v9 = y;
  if (BtlDrawText->m_Items[idx])
  {
      goto LABEL_21;
    goto LABEL_9;
  }
  v16 = BtlDrawText;
  v17 = Allocate(System_Collections_Generic_List_bDrawText_);
  __ctor(v17);
  v16->m_Items[idx] = v17;
  {
LABEL_9:
  }
LABEL_21:
  v22 = BtlDbgMenuObj->m_Items[idx];
  if (op_Equality(v22, 0, 0))
  {
    v67 = w;
    v25 = x;
    {
      v26 = h;
      v27 = v9;
    }
    else
    {
      v26 = h;
      v27 = v9;
    }
    v28 = BtlDbgMenuObj;
    object = Load_object_("BtlDbgMenu");
    v30 = Find("Canvas_UI", 0);
    transform = get_transform(v30, 0);
    v33 = Instantiate_object__425520(object, transform);
    v34 = v33;
    v9 = v27;
    v28->m_Items[idx] = v34;
    v39 = BtlDbgMenuObj;
    h = v26;
    v41 = get_transform(v39->m_Items[idx], 0);
    v42 = Find(v41, "menu", 0);
    Component_GUILayer = GetComponent_GUILayer_(v42);
    v44 = Component_GUILayer;
    x = v25;
    w = v67;
    BtlDbgMenuTxtTM->m_Items[idx] = v44;
    v47 = BtlDrawText;
    _Clear(v47->m_Items[idx]);
  }
  v50 = BtlDbgMenuObj;
  v52 = v50->m_Items[idx];
  if (op_Inequality(v52, 0, 0))
  {
    v55 = BtlDbgMenuObj;
    v57 = get_transform(v55->m_Items[idx], 0);
    Enumerator = GetEnumerator(v57);
    while ((sub_69BB0(0, System_Collections_IEnumerator, Enumerator) & 1) != 0)
    {
      v59 = sub_69A60(1u, System_Collections_IEnumerator, Enumerator);
      if (v59)
      {
        klass = v59->klass;
        if (v59->klass->_2.typeHierarchyDepth < typeHierarchyDepth
          || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != UnityEngine_Transform)
        {
          sub_8FC2C0(klass->_1.element_class, UnityEngine_Transform, &v68);
          if ((LOBYTE(v68.x) & 1) != 0)
            v62 = v69;
          else
            v62 = &v68.x + 1;
          v63 = sub_8C4940(v62);
        }
      }
      v65 = GetComponent_GUILayer_(v59);
      if (op_Inequality(v65, 0, 0))
      {
        v70 = 0;
        sub_851710(&v70, w, h);
        set_sizeDelta(v65, v70);
        v68.z = 0.0;
        *&v68.x = 0;
        sub_8524C0(&v68.x, x, -v9, 0.0);
        set_localPosition(v65, v68);
      }
    }
    Interface = QueryInterface(Enumerator, System_IDisposable);
    if (Interface)
      sub_22F10(0, System_IDisposable, Interface);
  }
}

// 0x158b3e0
void nbExitBattleTest(void) {
  nbExit();
  dds3KillProcessName("battle test", 1);
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
  dds3StartProcess("battle test", 0x2B0Cu, 1, 1, v11, 0, v12, 0, 0, 0);
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
  dds3GlobalWork_c *v61;
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
  if (!LODWORD(v8->max_length))
  {
LABEL_18:
  }
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
      if (v18 >= LODWORD(skilllist->max_length))
      {
LABEL_36:
      }
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
          goto LABEL_36;
      }
    }
    v44 = DDS3_GBWK->unitwork;
    v8 = v74;
    ++v18;
    v44->m_Items[v25]->skillcnt = v19 + skillcnt;
    if (v18 >= LODWORD(v74->max_length))
      goto LABEL_18;
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
  if (!LODWORD(v47->max_length))
  {
LABEL_74:
  }
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
      goto LABEL_74;
  }
  v68 = DDS3_GBWK->unitwork;
  v68->m_Items[0]->skillcnt = v57;
  v70 = 0;
  DDS3_GBWK->maka = 0;
  if ((v61->_2.bitflags2 & 2) != 0)
  {
LABEL_93:
    goto LABEL_95;
  }
  while (1)
  {
LABEL_95:
    item = DDS3_GBWK->item;
    item->m_Items[v70] = 0;
    if (v70 == 159)
      break;
    ++v70;
      goto LABEL_93;
  }
}
