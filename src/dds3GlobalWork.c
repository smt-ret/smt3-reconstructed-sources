#include "types.h"

typedef struct dds3GlobalWork_t dds3GlobalWork_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct fclEncycRecord_t fclEncycRecord_t;

static dds3GlobalWork_t *DDS3_GBWK;
static s32 NewGame2_SYS_ENDING0;
static s32 NewGame2_SYS_ENDING1;
static s32 NewGame2_SYS_ENDING2;
static s32 NewGame2_SYS_ENDING3;
static s32 NewGame2_SYS_ENDING4;
static s32 NewGame2_SYS_ENDING5;
static s32 NewGame2_SYS_ENDING6;
static s32 NewGame2_SYS_ENDING7;
static s32 NewGame2_SYS_ZENSHO_ALL;
static s32 NewGame2_EV_ZENSYO_ALL;
static s16 NewGame2_endcnt;
static s32 NewGame2_playtime;
static fclEncycRecord_t *NewGame2_encyc_record;
static s32 **NewGame2_boss_press;
static s32 NewGame2_SYS_BOSSRASH[24];
static s32 NewGame2_config_data[14];

void NewGame2Pop(void);
void NewGame2Push(void);
void UpdateAudioVolume(s32 type);
void UserInit(void);
void datInitBossPress(void);
void datInitPlayer(void);
void dds3GlobalWork_t__Init(dds3GlobalWork_t *this);
s32 dds3KillProcessName(char *name, s32 shutdowntimer);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
bool evtBitCheck(s32 no);
void evtBitOn(s32 no);
void evtInitGlobalWork(void);
void fclEncycInitRecord(s32 mode);
void fclEncycRecord_t__Clear(fclEncycRecord_t *this);
void fclEncycRecord_t__Copy(fclEncycRecord_t *this, fclEncycRecord_t *data);
void fldGbInit_System(s32 mode);
void frInitNameData(void);
void scrInitGlobalWork(void);

// 0x17b6900
void NewGame2Pop(void) {
  dds3GlobalWork_c *v2;
  struct dds3GlobalWork_StaticFields *static_fields;
  struct dds3GlobalWork_t_o *DDS3_GBWK;
  struct GameFileInfo_t_o *GameFileInfo;
  u64 *v6;
  dds3GlobalWork_c *v10;
  struct System_Int32_array_array *v11;
  u64 i;
  u32 *NewGame2_boss_press;
  s64 *v15;
  s64 *v16;
  u32 *v18;
  s32 v19;
  s64 j;
  u64 v26;
  struct System_Int32_array_array *v28;
  struct System_Int32_array_array *boss_press;
  s64 v31;
  s64 v32;
  s32 v33;
  struct System_Int32_array_array *v35;
  struct System_Int32_array_array *v37;
  s64 v38;
  s64 v39;
  s32 v40;
  u32 v42;
  struct System_Int32_array *NewGame2_SYS_BOSSRASH;
  struct System_Int32_array *v46;
  struct System_Int32_array *v49;
  struct System_Int32_array *v52;
  struct System_Int32_array *v55;
  struct System_Int32_array *v58;
  struct System_Int32_array *v61;
  struct System_Int32_array *v64;
  struct System_Int32_array *v67;
  struct System_Int32_array *v70;
  struct System_Int32_array *v73;
  struct System_Int32_array *v76;
  struct System_Int32_array *v79;
  struct System_Int32_array *v82;
  struct System_Int32_array *v85;
  struct System_Int32_array *v88;
  struct System_Int32_array *v91;
  struct System_Int32_array *v94;
  struct System_Int32_array *v97;
  struct System_Int32_array *v100;
  struct System_Int32_array *v103;
  struct System_Int32_array *v106;
  struct System_Int32_array *v109;
  struct System_Int32_array *v112;
  s64 v114;
  u64 v116;
  struct System_Int32_array *config_data;
  struct System_Int32_array *NewGame2_config_data;
  s32 v121;

  if (NewGame2_SYS_ENDING0)
  {
    evtBitOn(2208);
  }
  if (NewGame2_SYS_ENDING1)
  {
    evtBitOn(2209);
  }
  if (NewGame2_SYS_ENDING2)
  {
    evtBitOn(2210);
  }
  if (NewGame2_SYS_ENDING3)
  {
    evtBitOn(2211);
  }
  if (NewGame2_SYS_ENDING4)
  {
    evtBitOn(2212);
  }
  if (NewGame2_SYS_ENDING5)
  {
    evtBitOn(2213);
  }
  if (NewGame2_SYS_ENDING6)
  {
    evtBitOn(2214);
  }
  if (NewGame2_SYS_ENDING7)
  {
    evtBitOn(2215);
  }
  if (NewGame2_SYS_ZENSHO_ALL)
  {
    evtBitOn(2323);
  }
  if (NewGame2_EV_ZENSYO_ALL)
  {
    evtBitOn(162);
  }
  DDS3_GBWK->GameFileInfo->endcnt = NewGame2_endcnt;
  LODWORD(static_fields) = NewGame2_playtime;
  GameFileInfo = DDS3_GBWK->GameFileInfo;
  DDS3_GBWK->playtime = static_fields;
  GameFileInfo->PlayTime = static_fields;
  if (NewGame2_encyc_record)
  {
    if ((v2->_2.bitflags2 & 2) == 0)
      goto LABEL_64;
    goto LABEL_58;
  }
  v6 = Allocate(fclEncycRecord_t);
  fclEncycRecord_t___ctor(v6);
  NewGame2_encyc_record = v6;
  fclEncycRecord_t__Clear(NewGame2_encyc_record);
  {
LABEL_58:
  }
LABEL_64:
  fclEncycRecord_t__Copy(DDS3_GBWK->encyc_record, NewGame2_encyc_record);
  if (!NewGame2_boss_press)
  {
    v11 = NewSpecific(int__, 0x28u);
    NewGame2_boss_press = v11;
    for (i = 0; i != 40; ++i)
    {
      v15 = NewSpecific(s32, 2u);
      v16 = v15;
      v18 = &NewGame2_boss_press[2 * i];
      *(v18 + 4) = v16;
    }
  }
  v19 = (v10->_2.bitflags2 >> 1) & 1;
  for (j = 4; j != 44; ++j)
  {
    v26 = j - 4;
    v28 = NewGame2_boss_press;
    boss_press = DDS3_GBWK->boss_press;
    v31 = *(&v28->obj.klass + j);
    v32 = *(&boss_press->obj.klass + j);
    v33 = *(v32 + 32);
    *(v31 + 32) = v33;
    v35 = NewGame2_boss_press;
    v37 = DDS3_GBWK->boss_press;
    v38 = *(&v35->obj.klass + j);
    v39 = *(&v37->obj.klass + j);
    v40 = *(v39 + 36);
    *(v38 + 36) = v40;
    v19 = (v42 >> 9) & 1;
  }
  else
  {
    if (!LODWORD(NewGame2_SYS_BOSSRASH->max_length))
      goto LABEL_102;
  }
  if (NewGame2_SYS_BOSSRASH->m_Items[0])
    evtBitOn(2561);
  v46 = NewGame2_SYS_BOSSRASH;
  if (v46->m_Items[1])
    evtBitOn(2563);
  v49 = NewGame2_SYS_BOSSRASH;
  if (v49->m_Items[2])
    evtBitOn(2565);
  v52 = NewGame2_SYS_BOSSRASH;
  if (v52->m_Items[3])
    evtBitOn(2567);
  v55 = NewGame2_SYS_BOSSRASH;
  if (v55->m_Items[4])
    evtBitOn(2569);
  v58 = NewGame2_SYS_BOSSRASH;
  if (v58->m_Items[5])
    evtBitOn(2571);
  v61 = NewGame2_SYS_BOSSRASH;
  if (v61->m_Items[6])
    evtBitOn(2573);
  v64 = NewGame2_SYS_BOSSRASH;
  if (v64->m_Items[7])
    evtBitOn(2575);
  v67 = NewGame2_SYS_BOSSRASH;
  if (v67->m_Items[8])
    evtBitOn(2577);
  v70 = NewGame2_SYS_BOSSRASH;
  if (v70->m_Items[9])
    evtBitOn(2579);
  v73 = NewGame2_SYS_BOSSRASH;
  if (v73->m_Items[10])
    evtBitOn(2581);
  v76 = NewGame2_SYS_BOSSRASH;
  if (v76->m_Items[11])
    evtBitOn(2583);
  v79 = NewGame2_SYS_BOSSRASH;
  if (v79->m_Items[12])
    evtBitOn(2585);
  v82 = NewGame2_SYS_BOSSRASH;
  if (v82->m_Items[13])
    evtBitOn(2587);
  v85 = NewGame2_SYS_BOSSRASH;
  if (v85->m_Items[14])
    evtBitOn(2589);
  v88 = NewGame2_SYS_BOSSRASH;
  if (v88->m_Items[15])
    evtBitOn(2591);
  v91 = NewGame2_SYS_BOSSRASH;
  if (v91->m_Items[16])
    evtBitOn(2593);
  v94 = NewGame2_SYS_BOSSRASH;
  if (v94->m_Items[17])
    evtBitOn(2595);
  v97 = NewGame2_SYS_BOSSRASH;
  if (v97->m_Items[18])
    evtBitOn(2597);
  v100 = NewGame2_SYS_BOSSRASH;
  if (v100->m_Items[19])
    evtBitOn(2599);
  v103 = NewGame2_SYS_BOSSRASH;
  if (v103->m_Items[20])
    evtBitOn(2601);
  v106 = NewGame2_SYS_BOSSRASH;
  if (v106->m_Items[21])
    evtBitOn(2603);
  v109 = NewGame2_SYS_BOSSRASH;
  if (v109->m_Items[22])
    evtBitOn(2605);
  v112 = NewGame2_SYS_BOSSRASH;
  if (v112->m_Items[23])
    evtBitOn(2607);
  v114 = 8;
  v116 = 0;
  {
LABEL_269:
  }
  while (1)
  {
    config_data = DDS3_GBWK->config_data;
    if (v116 >= SLODWORD(config_data->max_length))
      break;
    else
    {
      if (v116 >= LODWORD(NewGame2_config_data->max_length))
        goto LABEL_275;
    }
    v121 = *(&NewGame2_config_data->obj.klass + v114);
    *(&config_data->obj.klass + v114++) = v121;
    v116 = v114 - 8;
      goto LABEL_269;
  }
}

// 0x17b5700
void NewGame2Push(void) {
  bool v22;
  dds3GlobalWork_c *v23;
  u64 *v24;
  struct System_Int32_array_array *v28;
  dds3GlobalWork_c *v29;
  u64 v30;
  u32 *NewGame2_boss_press;
  s64 *v32;
  s64 *v33;
  s64 i;
  u64 v38;
  struct System_Int32_array_array *boss_press;
  struct System_Int32_array_array *v42;
  s64 v43;
  s64 v44;
  s32 v45;
  struct System_Int32_array_array *v47;
  struct System_Int32_array_array *v49;
  s64 v50;
  s64 v51;
  s32 v52;
  u64 j;
  struct System_Int32_array *NewGame2_SYS_BOSSRASH;
  char *v63;
  struct System_Int32_array *v89;
  struct System_Int32_array *v91;
  struct System_Int32_array *v94;
  struct System_Int32_array *v97;
  struct System_Int32_array *v100;
  struct System_Int32_array *v103;
  struct System_Int32_array *v106;
  struct System_Int32_array *v109;
  struct System_Int32_array *v112;
  struct System_Int32_array *v115;
  struct System_Int32_array *v118;
  struct System_Int32_array *v121;
  struct System_Int32_array *v124;
  struct System_Int32_array *v127;
  struct System_Int32_array *v130;
  struct System_Int32_array *v133;
  struct System_Int32_array *v136;
  struct System_Int32_array *v139;
  struct System_Int32_array *v142;
  struct System_Int32_array *v145;
  struct System_Int32_array *v148;
  struct System_Int32_array *v151;
  struct System_Int32_array *v154;
  struct System_Int32_array *v157;
  s64 v159;
  u64 v161;
  struct System_Int32_array *config_data;
  u64 max_length_low;
  struct System_Int32_array *NewGame2_config_data;
  s32 v167;

  NewGame2_SYS_ENDING0 = 0;
  NewGame2_SYS_ENDING1 = 0;
  NewGame2_SYS_ENDING2 = 0;
  NewGame2_SYS_ENDING3 = 0;
  NewGame2_SYS_ENDING4 = 0;
  NewGame2_SYS_ENDING5 = 0;
  NewGame2_SYS_ENDING6 = 0;
  NewGame2_SYS_ENDING7 = 0;
  NewGame2_SYS_ZENSHO_ALL = 0;
  NewGame2_EV_ZENSYO_ALL = 0;
  NewGame2_endcnt = 0;
  NewGame2_playtime = 0;
  if (evtBitCheck(2208))
  {
    NewGame2_SYS_ENDING0 = 1;
    if (!evtBitCheck(2209))
    {
LABEL_8:
      if (!evtBitCheck(2210))
        goto LABEL_9;
      goto LABEL_27;
    }
  }
  else if (!evtBitCheck(2209))
  {
    goto LABEL_8;
  }
  NewGame2_SYS_ENDING1 = 1;
  if (!evtBitCheck(2210))
  {
LABEL_9:
    if (!evtBitCheck(2211))
      goto LABEL_10;
    goto LABEL_31;
  }
LABEL_27:
  NewGame2_SYS_ENDING2 = 1;
  if (!evtBitCheck(2211))
  {
LABEL_10:
    if (!evtBitCheck(2212))
      goto LABEL_11;
    goto LABEL_35;
  }
LABEL_31:
  NewGame2_SYS_ENDING3 = 1;
  if (!evtBitCheck(2212))
  {
LABEL_11:
    if (!evtBitCheck(2213))
      goto LABEL_12;
    goto LABEL_39;
  }
LABEL_35:
  NewGame2_SYS_ENDING4 = 1;
  if (!evtBitCheck(2213))
  {
LABEL_12:
    if (!evtBitCheck(2214))
      goto LABEL_13;
    goto LABEL_43;
  }
LABEL_39:
  NewGame2_SYS_ENDING5 = 1;
  if (!evtBitCheck(2214))
  {
LABEL_13:
    if (!evtBitCheck(2215))
      goto LABEL_14;
    goto LABEL_47;
  }
LABEL_43:
  NewGame2_SYS_ENDING6 = 1;
  if (!evtBitCheck(2215))
  {
LABEL_14:
    if (!evtBitCheck(2323))
      goto LABEL_51;
    goto LABEL_15;
  }
LABEL_47:
  NewGame2_SYS_ENDING7 = 1;
  if (evtBitCheck(2323))
  {
LABEL_15:
    NewGame2_SYS_ZENSHO_ALL = 1;
  }
LABEL_51:
  v22 = evtBitCheck(162);
  if (v22)
  {
    NewGame2_EV_ZENSYO_ALL = 1;
  }
  NewGame2_endcnt = DDS3_GBWK->GameFileInfo->endcnt;
  NewGame2_playtime = DDS3_GBWK->playtime;
  if (NewGame2_encyc_record)
  {
    if ((v23->_2.bitflags2 & 2) == 0)
      goto LABEL_67;
    goto LABEL_61;
  }
  v24 = Allocate(fclEncycRecord_t);
  fclEncycRecord_t___ctor(v24);
  NewGame2_encyc_record = v24;
  fclEncycRecord_t__Clear(NewGame2_encyc_record);
  {
LABEL_61:
  }
LABEL_67:
  fclEncycRecord_t__Copy(NewGame2_encyc_record, DDS3_GBWK->encyc_record);
  if (!NewGame2_boss_press)
  {
    v28 = NewSpecific(int__, 0x28u);
    NewGame2_boss_press = v28;
    v30 = 0;
    if ((v29->_2.bitflags2 & 2) != 0)
    {
LABEL_74:
      goto LABEL_76;
    }
    while (1)
    {
LABEL_76:
      v32 = NewSpecific(s32, 2u);
      v33 = v32;
      *&NewGame2_boss_press[2 * v30 + 8] = v33;
      if (v30 == 39)
        break;
      ++v30;
        goto LABEL_74;
    }
  }
  for (i = 4; i != 44; ++i)
  {
    v38 = i - 4;
    boss_press = DDS3_GBWK->boss_press;
    v42 = NewGame2_boss_press;
    v43 = *(&boss_press->obj.klass + i);
    v44 = *(&v42->obj.klass + i);
    v45 = *(v44 + 32);
    *(v43 + 32) = v45;
    v47 = DDS3_GBWK->boss_press;
    v49 = NewGame2_boss_press;
    v50 = *(&v47->obj.klass + i);
    v51 = *(&v49->obj.klass + i);
    v52 = *(v51 + 36);
    *(v50 + 36) = v52;
  }
  for (j = 0; j != 24; ++j)
  {
    v63 = NewGame2_SYS_BOSSRASH + 4 * j;
    *(v63 + 8) = 0;
  }
  if (!evtBitCheck(2561))
  {
    if (!evtBitCheck(2563))
      goto LABEL_113;
    goto LABEL_146;
  }
  else
  {
    v91 = NewGame2_SYS_BOSSRASH;
    if (!LODWORD(v91->max_length))
      goto LABEL_144;
  }
  v91->m_Items[0] = 1;
  if (!evtBitCheck(2563))
  {
LABEL_113:
    if (!evtBitCheck(2565))
      goto LABEL_114;
    goto LABEL_152;
  }
LABEL_146:
  v94 = NewGame2_SYS_BOSSRASH;
  v94->m_Items[1] = 1;
  if (!evtBitCheck(2565))
  {
LABEL_114:
    if (!evtBitCheck(2567))
      goto LABEL_115;
    goto LABEL_158;
  }
LABEL_152:
  v97 = NewGame2_SYS_BOSSRASH;
  v97->m_Items[2] = 1;
  if (!evtBitCheck(2567))
  {
LABEL_115:
    if (!evtBitCheck(2569))
      goto LABEL_116;
    goto LABEL_164;
  }
LABEL_158:
  v100 = NewGame2_SYS_BOSSRASH;
  v100->m_Items[3] = 1;
  if (!evtBitCheck(2569))
  {
LABEL_116:
    if (!evtBitCheck(2571))
      goto LABEL_117;
    goto LABEL_170;
  }
LABEL_164:
  v103 = NewGame2_SYS_BOSSRASH;
  v103->m_Items[4] = 1;
  if (!evtBitCheck(2571))
  {
LABEL_117:
    if (!evtBitCheck(2573))
      goto LABEL_118;
    goto LABEL_176;
  }
LABEL_170:
  v106 = NewGame2_SYS_BOSSRASH;
  v106->m_Items[5] = 1;
  if (!evtBitCheck(2573))
  {
LABEL_118:
    if (!evtBitCheck(2575))
      goto LABEL_119;
    goto LABEL_182;
  }
LABEL_176:
  v109 = NewGame2_SYS_BOSSRASH;
  v109->m_Items[6] = 1;
  if (!evtBitCheck(2575))
  {
LABEL_119:
    if (!evtBitCheck(2577))
      goto LABEL_120;
    goto LABEL_188;
  }
LABEL_182:
  v112 = NewGame2_SYS_BOSSRASH;
  v112->m_Items[7] = 1;
  if (!evtBitCheck(2577))
  {
LABEL_120:
    if (!evtBitCheck(2579))
      goto LABEL_121;
    goto LABEL_194;
  }
LABEL_188:
  v115 = NewGame2_SYS_BOSSRASH;
  v115->m_Items[8] = 1;
  if (!evtBitCheck(2579))
  {
LABEL_121:
    if (!evtBitCheck(2581))
      goto LABEL_122;
    goto LABEL_200;
  }
LABEL_194:
  v118 = NewGame2_SYS_BOSSRASH;
  v118->m_Items[9] = 1;
  if (!evtBitCheck(2581))
  {
LABEL_122:
    if (!evtBitCheck(2583))
      goto LABEL_123;
    goto LABEL_206;
  }
LABEL_200:
  v121 = NewGame2_SYS_BOSSRASH;
  v121->m_Items[10] = 1;
  if (!evtBitCheck(2583))
  {
LABEL_123:
    if (!evtBitCheck(2585))
      goto LABEL_124;
    goto LABEL_212;
  }
LABEL_206:
  v124 = NewGame2_SYS_BOSSRASH;
  v124->m_Items[11] = 1;
  if (!evtBitCheck(2585))
  {
LABEL_124:
    if (!evtBitCheck(2587))
      goto LABEL_125;
    goto LABEL_218;
  }
LABEL_212:
  v127 = NewGame2_SYS_BOSSRASH;
  v127->m_Items[12] = 1;
  if (!evtBitCheck(2587))
  {
LABEL_125:
    if (!evtBitCheck(2589))
      goto LABEL_126;
    goto LABEL_224;
  }
LABEL_218:
  v130 = NewGame2_SYS_BOSSRASH;
  v130->m_Items[13] = 1;
  if (!evtBitCheck(2589))
  {
LABEL_126:
    if (!evtBitCheck(2591))
      goto LABEL_127;
    goto LABEL_230;
  }
LABEL_224:
  v133 = NewGame2_SYS_BOSSRASH;
  v133->m_Items[14] = 1;
  if (!evtBitCheck(2591))
  {
LABEL_127:
    if (!evtBitCheck(2593))
      goto LABEL_128;
    goto LABEL_236;
  }
LABEL_230:
  v136 = NewGame2_SYS_BOSSRASH;
  v136->m_Items[15] = 1;
  if (!evtBitCheck(2593))
  {
LABEL_128:
    if (!evtBitCheck(2595))
      goto LABEL_129;
    goto LABEL_242;
  }
LABEL_236:
  v139 = NewGame2_SYS_BOSSRASH;
  v139->m_Items[16] = 1;
  if (!evtBitCheck(2595))
  {
LABEL_129:
    if (!evtBitCheck(2597))
      goto LABEL_130;
    goto LABEL_248;
  }
LABEL_242:
  v142 = NewGame2_SYS_BOSSRASH;
  v142->m_Items[17] = 1;
  if (!evtBitCheck(2597))
  {
LABEL_130:
    if (!evtBitCheck(2599))
      goto LABEL_131;
    goto LABEL_254;
  }
LABEL_248:
  v145 = NewGame2_SYS_BOSSRASH;
  v145->m_Items[18] = 1;
  if (!evtBitCheck(2599))
  {
LABEL_131:
    if (!evtBitCheck(2601))
      goto LABEL_132;
    goto LABEL_260;
  }
LABEL_254:
  v148 = NewGame2_SYS_BOSSRASH;
  v148->m_Items[19] = 1;
  if (!evtBitCheck(2601))
  {
LABEL_132:
    if (!evtBitCheck(2603))
      goto LABEL_133;
    goto LABEL_266;
  }
LABEL_260:
  v151 = NewGame2_SYS_BOSSRASH;
  v151->m_Items[20] = 1;
  if (!evtBitCheck(2603))
  {
LABEL_133:
    if (!evtBitCheck(2605))
      goto LABEL_134;
    goto LABEL_272;
  }
LABEL_266:
  v154 = NewGame2_SYS_BOSSRASH;
  v154->m_Items[21] = 1;
  if (!evtBitCheck(2605))
  {
LABEL_134:
    if (!evtBitCheck(2607))
      goto LABEL_278;
    goto LABEL_135;
  }
LABEL_272:
  v157 = NewGame2_SYS_BOSSRASH;
  v157->m_Items[22] = 1;
  if (evtBitCheck(2607))
  {
LABEL_135:
    v89 = NewGame2_SYS_BOSSRASH;
    v89->m_Items[23] = 1;
  }
LABEL_278:
  v159 = 8;
  v161 = 0;
    goto LABEL_283;
LABEL_281:
LABEL_283:
  while (1)
  {
    config_data = DDS3_GBWK->config_data;
    max_length_low = LODWORD(config_data->max_length);
    if (v161 >= max_length_low)
      break;
    else
    {
      if (v161 >= max_length_low)
        goto LABEL_287;
    }
    v167 = *(&config_data->obj.klass + v159);
    *(&NewGame2_config_data->obj.klass + v159++) = v167;
    v161 = v159 - 8;
      goto LABEL_281;
  }
}

// 0x17b4600
void UserDestroy(void) {
  ;
}

// 0x17b4490
void UserInit(void) {
  scrInitGlobalWork();
  evtInitGlobalWork();
  DDS3_GBWK->maxstock = 8;
  datInitPlayer();
  datInitBossPress();
  DDS3_GBWK->heartsequip = 0;
  DDS3_GBWK->heartscnt = 0;
  frInitNameData();
  fldGbInit_System(0);
  fclEncycInitRecord(0);
}

// 0x17b55b0
void dds3GlobalWorkDestroy(void) {
  dds3KillProcessName("GBWK", 0);
  DDS3_GBWK = 0;
}

// 0x17b4610
void dds3GlobalWorkInit(void) {
  Il2CppObject *v1;
  u64 *v5;
  dds3ProcessID_t_o *v7;
  dds3ProcessID_t_o *v8;
  Il2CppObject *data;
  dds3ProcessID_t_o *started;

  v1 = Allocate(dds3GlobalWork_t);
  v1[8].klass = NewSpecific(byte, 0x40u);
  v1[8].monitor = NewSpecific(byte, 4u);
  v1[9].klass = NewSpecific(byte, 4u);
  _ctor(v1, 0);
  DDS3_GBWK = v1;
  dds3GlobalWork_t__Init(DDS3_GBWK);
  DDS3_GBWK->runtime = 0;
  DDS3_GBWK->playtime = 0;
  v5 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v5,
    0,
    Method_dds3GlobalWork_dds3GlobalWorkMainProc__);
  data = DDS3_GBWK;
  started = dds3StartProcess("GBWK", 1u, 0, 0, v5, v7, 0, v8, data);
  UserInit(started);
}

// 0x17b4400
dds3ProcessFunc_t *dds3GlobalWorkMainProc(dds3ProcessID_t *procID) {
  ++DDS3_GBWK->runtime;
  ++DDS3_GBWK->playtime;
  return 0;
}

// 0x17b77a0
void dds3GlobalWorkUserInit2(s32 mode) {
  if (mode == 1)
  {
    NewGame2Push();
    dds3GlobalWork_t__Init(DDS3_GBWK);
  }
  DDS3_GBWK->runtime = 0;
  DDS3_GBWK->playtime = 0;
  scrInitGlobalWork();
  evtInitGlobalWork();
  DDS3_GBWK->maxstock = 8;
  datInitPlayer();
  datInitBossPress();
  DDS3_GBWK->heartsequip = 0;
  DDS3_GBWK->heartscnt = 0;
  frInitNameData();
  fldGbInit_System(0);
  fclEncycInitRecord(0);
  if (mode == 1)
  {
    NewGame2Pop();
  }
}

// 0x17b4830
void dds3GlobalWork_t__Init(dds3GlobalWork_t *this) {
  u64 *v3;
  u64 *v4;
  u64 *v5;
  struct datUnitWork_t_array *v6;
  u32 *unitwork;
  u64 i;
  u64 *v9;
  struct System_Int32_array_array *boss_press;
  u64 v13;
  s64 *v14;
  s64 *v15;
  struct System_Byte_array *v18;
  struct System_Byte_array_array *v19;
  struct System_Byte_array_array *v20;
  s64 *v21;
  s64 *v22;
  struct System_Byte_array_array *name_nums;
  s64 *v25;
  s64 *v26;
  struct System_Byte_array_array *v28;
  s64 *v29;
  s64 *v30;
  struct System_Byte_array_array *v32;
  s64 *v33;
  s64 *v34;
  struct System_Byte_array_array *v36;
  struct System_Byte_array_array *v37;
  s64 *v38;
  s64 *v39;
  struct System_Byte_array_array *name_code;
  s64 *v42;
  s64 *v43;
  struct System_Byte_array_array *v45;
  s64 *v46;
  s64 *v47;
  struct System_Byte_array_array *v49;
  s64 *v50;
  s64 *v51;
  struct System_Byte_array_array *v53;
  struct System_Byte_array_array *v54;
  s64 *v55;
  s64 *v56;
  struct System_Byte_array_array *cname_code;
  s64 *v59;
  s64 *v60;
  struct System_Byte_array_array *v62;
  s64 *v63;
  s64 *v64;
  struct System_Byte_array_array *v66;
  s64 *v67;
  s64 *v68;
  u64 *v70;
  System_Array_o *v71;
  struct System_UInt16_array_array *v73;
  u32 *hearts_sk;
  u64 j;
  s64 *v76;
  s64 *v77;
  struct System_SByte_array_array *v80;
  u32 *hearts_up_param;
  u64 k;
  s64 *v83;
  s64 *v84;
  u64 *v87;
  u64 *v88;
  u64 *v89;
  u64 *v90;
  u64 *v91;
  u64 *v92;

  v3 = Allocate(GameFileInfo_t);
  GameFileInfo_t___ctor(v3);
  this->GameFileInfo = v3;
  v4 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v4);
  this->mh = v4;
  *&this->runtime = 0;
  this->IntVariable = NewSpecific(s32, 0x100u);
  this->FloatVariable = NewSpecific(f32, 0x100u);
  this->EventBit = NewSpecific(s32, 0x80u);
  v5 = Allocate(evtMoon_t);
  evtMoon_t___ctor(v5);
  this->Moon = v5;
  *&this->maka = 0;
  this->maxstock = 0;
  v6 = NewSpecific(datUnitWork_t, 0x10u);
  this->unitwork = v6;
  unitwork = v6;
  for (i = 0; ; ++i)
  {
    v9 = Allocate(datUnitWork_t);
    datUnitWork_t___ctor(v9);
    *&unitwork[2 * i + 8] = v9;
    if (i == 15)
      break;
    unitwork = this->unitwork;
  }
  this->stocklist = NewSpecific(s32, 0x10u);
  this->stockcnt = 0;
  this->item = NewSpecific(byte, 0xA0u);
  boss_press = NewSpecific(int__, 0x28u);
  v13 = 0;
  this->boss_press = boss_press;
  while (1)
  {
    v14 = NewSpecific(s32, 2u);
    v15 = v14;
    boss_press->m_Items[v13] = v15;
    if (v13 == 39)
      break;
    boss_press = this->boss_press;
    ++v13;
  }
  this->syakkincnt = NewSpecific(byte, 0x40u);
  this->negoques = NewSpecific(byte, 4u);
  v18 = NewSpecific(byte, 4u);
  *(&this->encountkyori + 3) = 0.0;
  this->kotowari = v18;
  *&this->wakimi_id = 0;
  this->hearts = NewSpecific(byte, 0x40u);
  this->heartsskcnt = NewSpecific(byte, 0x40u);
  this->heartscnt = 0;
  v19 = NewSpecific(byte__, 4u);
  this->name_nums = v19;
  v20 = v19;
  v21 = NewSpecific(byte, 2u);
  v22 = v21;
  v20->m_Items[0] = v22;
  name_nums = this->name_nums;
  v25 = NewSpecific(byte, 2u);
  v26 = v25;
  name_nums->m_Items[1] = v26;
  v28 = this->name_nums;
  v29 = NewSpecific(byte, 2u);
  v30 = v29;
  v28->m_Items[2] = v30;
  v32 = this->name_nums;
  v33 = NewSpecific(byte, 2u);
  v34 = v33;
  v32->m_Items[3] = v34;
  v36 = NewSpecific(byte__, 4u);
  this->name_code = v36;
  v37 = v36;
  v38 = NewSpecific(byte, 0x10u);
  v39 = v38;
  v37->m_Items[0] = v39;
  name_code = this->name_code;
  v42 = NewSpecific(byte, 0x10u);
  v43 = v42;
  name_code->m_Items[1] = v43;
  v45 = this->name_code;
  v46 = NewSpecific(byte, 0x10u);
  v47 = v46;
  v45->m_Items[2] = v47;
  v49 = this->name_code;
  v50 = NewSpecific(byte, 0x10u);
  v51 = v50;
  v49->m_Items[3] = v51;
  v53 = NewSpecific(byte__, 4u);
  this->cname_code = v53;
  v54 = v53;
  v55 = NewSpecific(byte, 0x10u);
  v56 = v55;
  v54->m_Items[0] = v56;
  cname_code = this->cname_code;
  v59 = NewSpecific(byte, 0x10u);
  v60 = v59;
  cname_code->m_Items[1] = v60;
  v62 = this->cname_code;
  v63 = NewSpecific(byte, 0x10u);
  v64 = v63;
  v62->m_Items[2] = v64;
  v66 = this->cname_code;
  v67 = NewSpecific(byte, 0x10u);
  v68 = v67;
  v66->m_Items[3] = v68;
  this->cname_nums = NewSpecific(byte, 4u);
  v70 = Allocate(fldSave_t);
  fldSave_t___ctor(v70);
  this->fldSave = v70;
  v71 = NewSpecific(s32, 0xEu);
  InitializeArray_1543888(v71, Field__PrivateImplementationDetails__1C9E8F123DA81E20E1E772CFD4E8F05F801D3B5B);
  this->config_data = v71;
  UpdateAudioVolume(3);
  this->dmy = 0;
  v73 = NewSpecific(ushort__, 0x20u);
  this->hearts_sk = v73;
  hearts_sk = v73;
  for (j = 0; ; ++j)
  {
    v76 = NewSpecific(ushort, 0xCu);
    v77 = v76;
    *&hearts_sk[2 * j + 8] = v77;
    if (j == 31)
      break;
    hearts_sk = this->hearts_sk;
  }
  v80 = NewSpecific(sbyte__, 0x20u);
  this->hearts_up_param = v80;
  hearts_up_param = v80;
  for (k = 0; ; ++k)
  {
    v83 = NewSpecific(sbyte, 6u);
    v84 = v83;
    *&hearts_up_param[2 * k + 8] = v84;
    if (k == 31)
      break;
    hearts_up_param = this->hearts_up_param;
  }
  v87 = Allocate(fclEncycRecord_t);
  fclEncycRecord_t___ctor(v87);
  this->encyc_record = v87;
  v88 = Allocate(fldAutoMapBuff31_t);
  fldAutoMapBuff31_t___ctor(v88);
  this->amap31 = v88;
  v89 = Allocate(fldAutoMapBuffEX_t);
  fldAutoMapBuffEX_t___ctor(v89);
  this->amapEX = v89;
  v90 = Allocate(fldAutoMapBuff_t);
  fldAutoMapBuff_t___ctor(v90);
  this->amap_Ver7 = v90;
  v91 = Allocate(fldAutoMapBuff31_t);
  fldAutoMapBuff31_t___ctor(v91);
  this->amap31_Ver7 = v91;
  v92 = Allocate(fldAutoMapBuffEX_t);
  fldAutoMapBuffEX_t___ctor(v92);
  this->amapEX_Ver7 = v92;
}
