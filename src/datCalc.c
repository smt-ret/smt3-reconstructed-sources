#include "types.h"

typedef struct datBossPress_t datBossPress_t;
typedef struct datUnitWork_s datUnitWork_t;

static datBossPress_t *datBossPress[40];

u8 Get(s32 id);
f32 GetAisyoRitu(s32 nskill, datUnitWork_t *s, datUnitWork_t *d);
s32 GetButuriAttack(s32 nskill, datUnitWork_t *s, datUnitWork_t *d, s32 waza);
s32 GetMagicAttack(s32 nskill, datUnitWork_t *s, datUnitWork_t *d, s32 waza);
s32 GetMagicKaifuku(s32 nskill, datUnitWork_t *s, datUnitWork_t *d, s32 waza);
bool IsDLC(void);
void Unlock_16599376(char *id);
s32 datAddDevil(s32 id, s32 sw);
s32 datAddHearts(s32 id);
s32 datBossRashGetRec(s32 eid, s32 type);
s32 datCheckSyojiSkill(datUnitWork_t *work, u32 skill);
u32 datGetAisyo(datUnitWork_t *work, s32 attr);
s32 datGetBadStatusAttr(s32 bad);
s32 datGetBaseMaxHp(datUnitWork_t *work);
s32 datGetBaseMaxMp(datUnitWork_t *work);
s32 datGetBaseParam(datUnitWork_t *work, s32 paratype);
s32 datGetDefPow(datUnitWork_t *work);
u32 datGetMaxHp(datUnitWork_t *work);
u32 datGetMaxMp(datUnitWork_t *work);
s32 datGetNormalAtkPow(datUnitWork_t *work);
s32 datGetSkillBadKouka(s32 nskill, datUnitWork_t *s, datUnitWork_t *d);
s32 datGetSkillKouka(s32 nskill, s32 type, datUnitWork_t *s, datUnitWork_t *d);
void datRemoveHearts(void);
void datSetAutoKaifukuSkill(datUnitWork_t *work, s32 skill);
void datSetBadStat(datUnitWork_t *work, u32 badstat);
void datSetDevilWork(s32 id, datUnitWork_t *w);
void datUnitWork_t__Clear(datUnitWork_t *this);
void datUnitWork_t__Copy(datUnitWork_t *this, datUnitWork_t *dat);
f32 dds3GetRandFloatA(char *name);
u32 dds3GetRandIntA(u32 aLimit, char *name);
bool evtBitCheck(s32 no);
void evtBitOff(s32 no);
void evtBitOn(s32 no);
s8 fclChkItemHearts(u16 ItemID);
s32 fclEncycRegist(datUnitWork_t *punit, s32 overwrite, bool update);
void rstLoadHeartsSkill(s8 HeartsID, datUnitWork_t *pStock);
void rstStoreHeartsSkill(s8 HeartsID, datUnitWork_t *pStock);

// 0x16385e0
f32 GetAisyoRitu(s32 nskill, datUnitWork_t *s, datUnitWork_t *d) {
  struct datSkill_t_array *tbl;
  s32 skillattr;
  f32 Aisyo;

  skillattr = tbl->m_Items[nskill]->skillattr;
  if (skillattr == -1 || (skillattr - 12) < 3)
    return 1.0;
  Aisyo = datGetAisyo(d, skillattr, d);
  return Aisyo * 0.01;
}

// 0x1637d40
s32 GetButuriAttack(s32 nskill, datUnitWork_t *s, datUnitWork_t *d, s32 waza) {
  u32 level;
  s32 v13;
  s32 v14;
  s32 BaseParam;
  s32 v17;
  f32 v18;
  u32 v19;
  u32 v20;
  s32 v21;
  s32 v22;
  s32 v23;
  s32 v24;

  datGetNormalAtkPow(s, s);
  datGetDefPow(d);
  level = s->level;
  if ((s->flag & 0x20) != 0)
  {
    if (nskill)
    {
      BaseParam = datGetBaseParam(s, 0);
      if ((s->badstatus & 0xFFF) == 0x200)
        v17 = 1;
      else
        v17 = BaseParam;
      if (v17 <= 1)
        v17 = 1;
      v18 = (((level + level) + (v17 + v17)) * waza) / 23.2;
      v19 = s->level + 10;
      v20 = 50;
    }
    else
    {
      v23 = datGetBaseParam(s, 0);
      if ((s->badstatus & 0xFFF) == 0x200)
        v24 = 1;
      else
        v24 = v23;
      if (v24 <= 1)
        v24 = 1;
      v18 = ((level + level) + (v24 + v24)) * 1.33;
      v19 = s->level + 10;
      v20 = 48;
    }
    return ((v18 * 0.6) - (v20 / v19));
  }
  else if (nskill)
  {
    v13 = datGetBaseParam(s, 0);
    if ((s->badstatus & 0xFFF) == 0x200)
      v14 = 1;
    else
      v14 = v13;
    if (v14 <= 1)
      v14 = 1;
    return (((((level + level) + (v14 + v14)) * waza) / 23.2) * 0.8);
  }
  else
  {
    v21 = datGetBaseParam(s, 0);
    if ((s->badstatus & 0xFFF) == 0x200)
      v22 = 1;
    else
      v22 = v21;
    if (v22 <= 1)
      v22 = 1;
    return ((((level + level) + (v22 + v22)) * 1.33) * 0.8);
  }
}

// 0x16380a0
s32 GetButuriKaifuku(s32 nskill, datUnitWork_t *s, datUnitWork_t *d, s32 waza) {
  return GetButuriAttack(nskill, s, d, waza);
}

// 0x1638130
s32 GetMagicAttack(s32 nskill, datUnitWork_t *s, datUnitWork_t *d, s32 waza) {
  int16x4_t v5;
  struct datNormalSkill_t_array *tbl;
  int16x4_t v12;
  f32 v13;
  int16x4_t v14;
  struct datNormalSkill_t_array *v16;
  s32 BaseParam;
  s32 v19;
  f32 v20;
  u32 level;
  f32 v22;

  v5.n64_u16[0] = tbl->m_Items[nskill]->magicbase;
  v12.n64_u64[0] = vmovl_s16(v5).n128_u64[0];
  v12.n64_f32[0] = v12.n64_i32[0];
  v13 = ((2 * waza * s->level) / 21.0) + v12.n64_f32[0];
  v12.n64_u16[0] = tbl->m_Items[nskill]->magiclimit;
  v14.n64_u64[0] = vmovl_s16(v12).n128_u64[0];
  v14.n64_f32[0] = v14.n64_i32[0];
  if (v13 > v14.n64_f32[0])
  {
    v16 = tbl;
    v14.n64_u16[0] = v16->m_Items[nskill]->magiclimit;
    v13 = vmovl_s16(v14).n128_i32[0];
  }
LABEL_19:
  BaseParam = datGetBaseParam(s, 2, d);
  if ((s->badstatus & 0xFFF) == 0x200)
    v19 = 1;
  else
    v19 = BaseParam;
  if (v19 <= 1)
    v19 = 1;
  v20 = v19;
  level = s->level;
  v22 = (v13 + ((v13 / 100.0) * ((v20 - ((level / 5.0) + 4.0)) * 2.5))) * 0.8;
  if ((s->flag & 0x20) != 0)
    return ((v22 * 0.75) + (-50.0 / (level + 10)));
  return v22;
}

// 0x16383c0
s32 GetMagicKaifuku(s32 nskill, datUnitWork_t *s, datUnitWork_t *d, s32 waza) {
  s32 BaseParam;
  s32 v9;
  s32 v10;
  s32 level;

LABEL_7:
  BaseParam = datGetBaseParam(s, 2, d);
  if ((s->badstatus & 0xFFF) == 0x200)
    v9 = 1;
  else
    v9 = BaseParam;
  if (v9 <= 1)
    v10 = 1;
  else
    v10 = v9;
  level = s->level;
  return (((level + 4 * v10 + dds3GetRandIntA(8u, "GetMagicKaifuku")) / 10.0) * waza);
}

// 0x1638500
s32 GetMaxHpWazaPoint(s32 nskill, datUnitWork_t *s, datUnitWork_t *d, s32 waza) {
  u32 v5;

  if ((s->flag & 0x20) != 0)
  {
    return ((((datGetBaseMaxHp(s, s) / 69.6) * waza) * 0.6) + (-50.0 / (s->level + 10)));
  }
  else
  {
    LOWORD(v5) = s->maxhp;
    return ((v5 / 69.6) * waza);
  }
}

// 0x163a740
bool IsNOCTURNE(void) {
  u32 Bit;

  Bit = cfgGetBit(9u);
  return Bit >= 3 && Bit == 3;
}

// 0x163db70
s32 datAddDevil(s32 id, s32 sw) {
  s32 v5;
  s64 i;
  u64 v8;
  struct datUnitWork_t_array *unitwork;
  struct datUnitWork_t_array *v12;
  s64 v14;
  s64 v16;
  struct dds3GlobalWork_t_o *DDS3_GBWK;
  struct datUnitWork_t_array *v18;
  struct dds3GlobalWork_t_o *v20;
  u32 v21;
  struct datUnitWork_t_array *v22;
  datUnitWork_t_o *v24;
  struct datUnitWork_t_array *v27;
  datUnitWork_t_o *v29;
  struct datUnitWork_t_array *v31;
  struct dds3GlobalWork_t_o *v34;
  struct System_Int32_array *stocklist;
  s64 stockcnt;

  v5 = 0;
  for (i = 4; i != 20; ++i)
  {
    while (1)
    {
      v8 = i - 4;
      unitwork = DDS3_GBWK->unitwork;
      if ((*(*(&unitwork->obj.klass + i) + 16LL) & 1) != 0)
        break;
      if (++i == 20)
        goto LABEL_18;
    }
    v12 = DDS3_GBWK->unitwork;
    v5 += (*(*(&v12->obj.klass + i) + 16LL) >> 1) & 1;
  }
LABEL_18:
  v14 = 8;
  v16 = 0;
    goto LABEL_23;
LABEL_21:
LABEL_23:
  while (1)
  {
    if (v16 >= DDS3_GBWK->maxstock)
      break;
    v18 = DDS3_GBWK->unitwork;
    if ((*(*(&v18->obj.klass + v14) + 16LL) & 1) == 0)
    {
      break;
    }
    ++v14;
    v16 = v14 - 8;
      goto LABEL_21;
  }
  v20 = DDS3_GBWK;
  if (v14 - v20->maxstock == 8)
    return -1;
  v22 = v20->unitwork;
  v21 = v14 - 4;
  v24 = *(&v22->obj.klass + v14);
  datSetDevilWork(id & 0x7FFFFFFF, v24);
  if ((id & 0x80000000) == 0)
  {
    v27 = DDS3_GBWK->unitwork;
    v29 = *(&v27->obj.klass + v14);
    fclEncycRegist(v29, 0, 0);
  }
  if (sw && v5 <= 3)
  {
    v31 = DDS3_GBWK->unitwork;
    *(*(&v31->obj.klass + v14) + 16LL) |= 2u;
  }
  v34 = DDS3_GBWK;
  stocklist = v34->stocklist;
  stockcnt = v34->stockcnt;
  stocklist->m_Items[stockcnt] = v21;
  ++DDS3_GBWK->stockcnt;
  return v21;
}

// 0x163e4b0
void datAddExp(datUnitWork_t *w, s32 exp) {
  w->exp += exp;
}

// 0x163ad10
s32 datAddHearts(s32 id) {
  s64 v3;
  s16 v5;
  u64 v6;
  s32 v7;
  struct dds3GlobalWork_t_o *DDS3_GBWK;
  u64 heartscnt;
  struct System_Byte_array *hearts;
  s32 v12;
  struct System_Byte_array *v13;
  struct System_Byte_array *heartsskcnt;
  struct datUnitWork_t_array *unitwork;
  datUnitWork_t_o *v22;
  u32 v25;
  s64 *achievementTbl;
  System_String_o *v28;
  s32 v29;

  v3 = 32;
  while (1)
  {
    v6 = v3 - 32;
    if ((v5 & 0x200) != 0)
    {
      v7 = v5 & 0x200;
    }
    else
    {
      v7 = 0;
    }
    heartscnt = DDS3_GBWK->heartscnt;
    if (v6 >= heartscnt)
      break;
    else
    {
      hearts = DDS3_GBWK->hearts;
      if (v6 >= LODWORD(hearts->max_length))
        goto LABEL_13;
    }
    v12 = *(&hearts->obj.klass + v3++);
    if (v12 == id)
      return 0;
  }
  else
  {
    v13 = DDS3_GBWK->hearts;
    if (heartscnt >= LODWORD(v13->max_length))
      goto LABEL_21;
  }
  v13->m_Items[heartscnt] = id;
  ++DDS3_GBWK->heartscnt;
  heartsskcnt = DDS3_GBWK->heartsskcnt;
  heartsskcnt->m_Items[id] = 0;
  if (cmpChkHaveNormalHeartsAll())
    evtBitOn(2144);
  unitwork = DDS3_GBWK->unitwork;
  v22 = unitwork->m_Items[0];
  cmbCreateDefaultHeartsSkill(id, v22);
  v25 = 0;
  SystemWork->MagaTama_Bit |= 1 << (id - 1);
  while (1)
  {
    v29 = 1;
    if ((SystemWork->MagaTama_Bit & (1 << v25)) == 0)
      break;
    if (v25++ >= 0x18)
    {
      achievementTbl = get_achievementTbl();
      v28 = sub_B7950(0x18u, DefineAchievementID_string_, achievementTbl);
      Unlock_16599376(v28);
      return 1;
    }
  }
  return v29;
}

// 0x1639dd0
u32 datAddHp(datUnitWork_t *work, s32 hp) {
  s32 maxhp;

  maxhp = (work->hp + hp) & ~((work->hp + hp) >> 31);
  if (maxhp > work->maxhp)
    maxhp = work->maxhp;
  work->hp = maxhp;
  return maxhp;
}

// 0x163aa90
void datAddItem(s32 id, s32 num) {
  s8 v5;
  s32 v7;
  struct System_Byte_array *item;
  s32 v11;
  s32 v12;
  char v13;
  struct System_Byte_array *v14;
  struct System_Byte_array *v18;
  s32 v20;
  struct System_Byte_array *v22;

  v5 = fclChkItemHearts(id);
  if (v5)
  {
    v7 = v5;
    datAddHearts(v7);
    return;
  }
  if (id < 112)
  {
    item = DDS3_GBWK->item;
    v11 = item->m_Items[id] + num;
    v12 = v11 & ~(v11 >> 31);
    if (v12 >= 99)
      v13 = 99;
    else
      v13 = v12;
    v14 = DDS3_GBWK->item;
    v14->m_Items[id] = v13;
    return;
  }
  evtBitOn(id + 864);
  if (id != 141)
    return;
  v18 = DDS3_GBWK->item;
  v20 = v18->m_Items[141];
  if (num < 1)
  {
    if (num < 0)
    {
      v20 += num;
      if (v20 <= 0)
      {
        evtBitOff(id + 864);
        LOBYTE(v20) = 0;
      }
    }
      goto LABEL_44;
    goto LABEL_42;
  }
  if (v20 + num >= 99)
    LOBYTE(v20) = 99;
  else
    LOBYTE(v20) = v20 + num;
  {
LABEL_42:
  }
LABEL_44:
  v22 = DDS3_GBWK->item;
  v22->m_Items[141] = v20;
}

// 0x163ed80
void datAddKotowariPoint(s32 type, s32 point) {
  struct System_Byte_array *kotowari;
  s32 v8;
  s32 v9;
  char v10;
  struct System_Byte_array *v11;

  if (type)
  {
    kotowari = DDS3_GBWK->kotowari;
    v8 = kotowari->m_Items[type] + point;
    v9 = v8 & ~(v8 >> 31);
    if (v9 >= 128)
      v10 = 0x80;
    else
      v10 = v9;
    v11 = DDS3_GBWK->kotowari;
    v11->m_Items[type] = v10;
  }
}

// 0x163a840
void datAddMaka(s32 addmaka) {
  s16 v4;
  s32 v5;
  struct dds3GlobalWork_t_o *DDS3_GBWK;
  s32 v7;

  if ((v4 & 0x200) != 0)
  {
    v5 = v4 & 0x200;
  }
  else
  {
    v5 = 0;
  }
  if (((DDS3_GBWK->maka + addmaka) & ~((DDS3_GBWK->maka + addmaka) >> 31)) >= 9999999)
    v7 = 9999999;
  else
    v7 = (DDS3_GBWK->maka + addmaka) & ~((DDS3_GBWK->maka + addmaka) >> 31);
  else
  {
    DDS3_GBWK->maka = v7;
  }
}

// 0x163a910
void datAddMakaPar(s32 addmaka) {
  struct dds3GlobalWork_t_o *DDS3_GBWK;
  s32 maka;
  s32 v6;
  s32 v7;
  s32 v8;
  s32 v9;

  maka = DDS3_GBWK->maka;
  v6 = maka * addmaka / 100 + maka;
  v7 = maka - -(maka * addmaka) / 100;
  if (addmaka >= 0)
    v7 = v6;
  v8 = v7 & ~(v7 >> 31);
  if (v8 >= 9999999)
    v9 = 9999999;
  else
    v9 = v8;
  else
  {
    DDS3_GBWK->maka = v9;
  }
}

// 0x1639da0
u32 datAddMp(datUnitWork_t *work, s32 mp) {
  s32 maxmp;

  maxmp = (work->mp + mp) & ~((work->mp + mp) >> 31);
  if (maxmp > work->maxmp)
    maxmp = work->maxmp;
  work->mp = maxmp;
  return maxmp;
}

// 0x163b6b0
void datAddPlayerParam(s32 id, s32 add) {
  struct datUnitWork_t_array *unitwork;
  struct System_SByte_array *param;
  char v11;
  struct datUnitWork_t_array *v12;
  struct System_SByte_array *v14;
  struct datUnitWork_t_array *v16;
  datUnitWork_t_o *v18;
  struct datUnitWork_t_array *v20;
  struct datUnitWork_t_array *v21;

  unitwork = DDS3_GBWK->unitwork;
  param = unitwork->m_Items[0]->param;
  if (param->m_Items[id] + add >= 40)
    v11 = 40;
  else
    v11 = param->m_Items[id] + add;
  v12 = DDS3_GBWK->unitwork;
  v14 = v12->m_Items[0]->param;
  v14->m_Items[id] = v11;
  v16 = DDS3_GBWK->unitwork;
  v18 = v16->m_Items[0];
  cmpSetMaxHPMP(v18);
  v20 = DDS3_GBWK->unitwork;
  v20->m_Items[0]->hp = v20->m_Items[0]->maxhp;
  v21 = DDS3_GBWK->unitwork;
  v21->m_Items[0]->mp = v21->m_Items[0]->maxmp;
}

// 0x163df50
s32 datAddUniqueDevil(s32 id, s32 sw, s32 uid) {
  s32 v8;
  struct datUnitWork_t_array *unitwork;
  struct datUnitWork_t_array *v12;
  struct datUnitWork_t_array *v15;
  datUnitWork_t_o *v17;

  v8 = datAddDevil(id, sw, *&uid);
  unitwork = DDS3_GBWK->unitwork;
  unitwork->m_Items[v8]->flag |= 0x400u;
  v12 = DDS3_GBWK->unitwork;
  v12->m_Items[v8]->uniqueid = uid;
  if (uid == 1)
  {
    v15 = DDS3_GBWK->unitwork;
    v17 = v15->m_Items[v8];
    v17->flag |= 0x1000u;
  }
  return v8;
}

// 0x163ebb0
void datAllClearCommMemory(void) {
  u64 i;
  struct datUnitWork_t_array *unitwork;
  datUnitWork_t_o *v6;

  for (i = 0; i != 16; ++i)
  {
    while (1)
    {
      unitwork = DDS3_GBWK->unitwork;
      v6 = unitwork->m_Items[i];
        break;
      ++i;
      *&v6->prevcommand = 0xFFFFFFFF00000000LL;
      if (i == 16)
        return;
    }
    *&v6->prevcommand = 0xFFFFFFFF00000000LL;
  }
}

// 0x16409d0
s32 datBossRashChk(s32 eid) {
  s64 i;
  u64 i_1;
  struct datBossPress_t_array *datBossPress;
  struct datBossPress_t_array *datBossPress_1;
  struct datBossPress_t_array *datBossPress_2;

  for (i = 4; ; ++i)
  {
    i_1 = i - 4;
    if (*(*(&datBossPress->obj.klass + i) + 24LL) == eid)
    {
      datBossPress_1 = datBossPress;
      if (*(*(&datBossPress_1->obj.klass + i) + 16LL))
      {
        datBossPress_2 = datBossPress;
        if (evtBitCheck(*(*(&datBossPress_2->obj.klass + i) + 16LL), 0))
          break;
      }
    }
    if (i_1 >= 0x27)
      return 0;
  }
  return 1;
}

// 0x1640300
s32 datBossRashGetRec(s32 eid, s32 type) {
  s64 i;
  u64 v7;
  struct datBossPress_t_array *datBossPress;
  struct datBossPress_t_array *v11;
  s64 j;
  u64 v15;
  struct datBossPress_t_array *v16;
  struct System_Int32_array_array *v20;
  s64 v21;
  struct System_Int32_array_array *v23;
  s64 v25;
  struct datBossPress_t_array *v28;
  struct System_Int32_array_array *boss_press;
  s64 v32;
  struct System_Int32_array_array *v34;
  s64 v36;

  if (type)
  {
    for (i = 4; ; ++i)
    {
      v7 = i - 4;
      if (*(*(&datBossPress->obj.klass + i) + 24LL) == eid)
      {
        if (type != 1)
        {
          v28 = datBossPress;
          return *(*(&v28->obj.klass + i) + 28LL);
        }
        v11 = datBossPress;
        if (evtBitCheck(*(*(&v11->obj.klass + i) + 16LL), 0))
        {
          boss_press = DDS3_GBWK->boss_press;
          v32 = *(&boss_press->obj.klass + i);
          if (!*(v32 + 36))
            return 1;
          v34 = DDS3_GBWK->boss_press;
          v36 = *(&v34->obj.klass + i);
          return *(v36 + 36);
        }
      }
      if (v7 >= 0x27)
        return 0;
    }
  }
  for (j = 4; ; ++j)
  {
    v15 = j - 4;
    v16 = datBossPress;
    if (*(*(&v16->obj.klass + j) + 24LL) == eid)
      break;
    if (v15 > 0x26)
      return 0;
  }
  v20 = DDS3_GBWK->boss_press;
  v21 = *(&v20->obj.klass + j);
  if (*(v21 + 32) < 1)
    return 999;
  v23 = DDS3_GBWK->boss_press;
  v25 = *(&v23->obj.klass + j);
  return *(v25 + 32);
}

// 0x16406e0
void datBossRashUpdRec(s32 eid, s32 press) {
  s32 press_1;
  s32 eid_1;
  s64 i_1;
  s32 eid_2;
  u64 i;
  struct datBossPress_t_array *datBossPress_1;
  struct datBossPress_t_array *datBossPress_2;
  struct System_Int32_array_array *boss_press;
  s64 v20;
  struct System_Int32_array_array *boss_press_1;
  s64 v26;
  struct datBossPress_t_array *datBossPress;

  if (press)
    press_1 = press;
  else
    press_1 = 1;
  if (eid == 993)
    eid_1 = 472;
  else
    eid_1 = eid;
  i_1 = 4;
  if (eid_1 == 992)
    eid_2 = 334;
  else
    eid_2 = eid_1;
  while (1)
  {
    i = i_1 - 4;
    datBossPress_1 = datBossPress;
    if (*(*(&datBossPress_1->obj.klass + i_1) + 24LL) == eid_2)
      break;
    ++i_1;
    if (i >= 0x27)
      return;
  }
  datBossPress_2 = datBossPress;
  if (evtBitCheck(*(*(&datBossPress_2->obj.klass + i_1) + 16LL), 0))
  {
    boss_press = DDS3_GBWK->boss_press;
    v20 = *(&boss_press->obj.klass + i_1);
    *(v20 + 36) = press_1;
    if (datBossRashGetRec(eid_2, 0) > press_1)
    {
      boss_press_1 = DDS3_GBWK->boss_press;
      v26 = *(&boss_press_1->obj.klass + i_1);
      *(v26 + 32) = press_1;
      evtBitOn(*(*(&datBossPress->obj.klass + i_1) + 20LL), 0);
    }
  }
}

// 0x163a7d0
s32 datCheckDying(datUnitWork_t *work) {
  return work
      && (!evtBitCheck(3712) || !evtBitCheck(3715))
      && (100 * work->hp / work->maxhp) < 25;
}

// 0x163b030
s32 datCheckItem(s32 id, s32 num) {
  struct System_Byte_array *item;

  item = DDS3_GBWK->item;
  return item->m_Items[id] >= num;
}

// 0x163b0e0
s32 datCheckItemFull(s32 id) {
  struct System_Byte_array *item;

  item = DDS3_GBWK->item;
  if (id >= 112)
  {
    if (item->m_Items[id])
      return 1;
  }
  else if (item->m_Items[id] > 0x62u)
  {
    return 1;
  }
  return 0;
}

// 0x163aa10
s32 datCheckMaka(s32 maka) {
  return DDS3_GBWK->maka >= maka;
}

// 0x163b4d0
s32 datCheckPlayerDead(void) {
  struct datUnitWork_t_array *unitwork;

  unitwork = DDS3_GBWK->unitwork;
  return (unitwork->m_Items[0]->badstatus & 0xFFF) == 2048;
}

// 0x163e860
s32 datCheckSkillInParty(s32 skillid) {
  u64 v4;
  struct datUnitWork_t_array *unitwork;
  datUnitWork_t_o *v8;

  v4 = 0;
  while (1)
  {
    unitwork = DDS3_GBWK->unitwork;
    v8 = unitwork->m_Items[v4];
    if ((~v8->flag & 3) == 0)
    {
      if (datCheckSyojiSkill(v8, skillid))
        break;
    }
    if (v4++ >= 0xF)
      return 0;
  }
  return 1;
}

// 0x163e960
s32 datCheckSkillTakaraSagasi(void) {
  s32 flag;
  u64 v5;
  struct datUnitWork_t_array *unitwork;
  datUnitWork_t_o *v10;
  struct System_SByte_array *param;
  s32 v13;
  s32 v14;

  flag = datTakaraSagasi->flag;
  if (flag)
    goto LABEL_6;
LABEL_9:
  v5 = 0;
  while (1)
  {
    unitwork = DDS3_GBWK->unitwork;
    v10 = unitwork->m_Items[v5];
    if ((~v10->flag & 3) != 0)
      goto LABEL_27;
    param = v10->param;
    v13 = param->m_Items[5];
      break;
    if (datCheckSyojiSkill(v10, 0x161u))
      goto LABEL_23;
LABEL_27:
    if (v5++ >= 0xF)
      return 0;
  }
  if (!datCheckSyojiSkill(v10, 0x161u))
    goto LABEL_27;
LABEL_23:
  v14 = (v13 << 7) / 100;
  if (v14 < dds3GetRandIntA(0x20u, "datCheckSkillTakaraSagasi"))
    goto LABEL_27;
  return v10->id;
}

// 0x163d510
s32 datCheckStockFull(void) {
  dds3GlobalWork_c *v2;
  s32 v3;
  s64 v4;
  bool v5;
  struct datUnitWork_t_array *unitwork;
  s32 v8;

  v3 = 0;
  v4 = 8;
  do
  {
    unitwork = DDS3_GBWK->unitwork;
    v8 = *(*(&unitwork->obj.klass + v4++) + 16LL) & 1;
    v3 += v8;
    v5 = (*&v2->_2.bitflags1 & 0x200) == 0;
  }
  while (v4 != 20);
  return v3 >= DDS3_GBWK->maxstock;
}

// 0x1639fa0
s32 datCheckSyojiSkill(datUnitWork_t *work, u32 skill) {
  u64 v5;
  struct System_Int32_array *v6;
  s32 id;
  struct System_UInt16_array *v11;
  s32 v13;
  struct System_UInt16_array *v15;
  s32 v17;
  struct System_UInt16_array *v19;
  s32 v21;
  struct System_UInt16_array *v23;
  s32 v25;
  struct System_UInt16_array *v27;
  s32 v29;
  struct System_UInt16_array *v31;
  s32 v33;
  struct System_UInt16_array *v35;
  s32 v37;
  struct System_UInt16_array *v38;

  if ((work->flag & 0x20) != 0)
  {
    id = work->id;
    v11 = Get(id, 1, 0)->skill;
    if (v11->m_Items[0] == skill)
    {
      return 1;
    }
    else
    {
      v13 = work->id;
      v15 = Get(v13, 1, 0)->skill;
      if (v15->m_Items[1] == skill)
      {
        return 1;
      }
      else
      {
        v17 = work->id;
        v19 = Get(v17, 1, 0)->skill;
        if (v19->m_Items[2] == skill)
        {
          return 1;
        }
        else
        {
          v21 = work->id;
          v23 = Get(v21, 1, 0)->skill;
          if (v23->m_Items[3] == skill)
          {
            return 1;
          }
          else
          {
            v25 = work->id;
            v27 = Get(v25, 1, 0)->skill;
            if (v27->m_Items[4] == skill)
            {
              return 1;
            }
            else
            {
              v29 = work->id;
              v31 = Get(v29, 1, 0)->skill;
              if (v31->m_Items[5] == skill)
              {
                return 1;
              }
              else
              {
                v33 = work->id;
                v35 = Get(v33, 1, 0)->skill;
                if (v35->m_Items[6] == skill)
                {
                  return 1;
                }
                else
                {
                  v37 = work->id;
                  v38 = Get(v37, 1, 0)->skill;
                  return v38->m_Items[7] == skill;
                }
              }
            }
          }
        }
      }
    }
  }
  else if (work->skillcnt < 1)
  {
    return 0;
  }
  else
  {
    v5 = 0;
    while (1)
    {
      v6 = work->skill;
      if (v6->m_Items[v5] == skill)
        break;
      if (++v5 >= work->skillcnt)
        return 0;
    }
    return 1;
  }
}

// 0x163b260
s32 datCheckTalk(datUnitWork_t *work) {
  u16 badstatus;
  u32 v3;
  s32 result;

  badstatus = work->badstatus;
  v3 = badstatus & 0xFFF;
  if (v3 <= 8)
  {
    if (v3 - 1 < 2)
      return 0;
    result = 0;
    if ((badstatus & 0xFFF) != 4 && (badstatus & 0xFFF) != 8)
      return 1;
  }
  else
  {
    result = 0;
    if (v3 != 16 && v3 != 512 && v3 != 1024)
      return 1;
  }
  return result;
}

// 0x163eba0
void datClearCommMemory(datUnitWork_t *work) {
  *&work->prevcommand = 0xFFFFFFFF00000000LL;
}

// 0x163fcf0
void datCopyDevilWork(s32 id, datUnitWork_t *w) {
  struct System_SByte_array *param;
  struct System_SByte_array *v8;
  s8 v9;
  struct System_SByte_array *v10;
  struct System_SByte_array *v12;
  s8 v13;
  struct System_SByte_array *v14;
  struct System_SByte_array *v16;
  s8 v18;
  struct System_SByte_array *v20;
  struct System_SByte_array *v22;
  s8 v23;
  struct System_SByte_array *v24;
  struct System_SByte_array *v26;
  s8 v28;
  struct System_SByte_array *v30;
  struct System_SByte_array *v32;
  u32 v35;
  s64 i;
  u64 v37;
  struct fclSkillParam_t_array *Event;
  struct fclSkillParam_t_array *v40;
  struct System_Int32_array *skill;
  struct fclSkillParam_t_array *v43;
  char *v46;
  datUnitWork_t_o *v47;
  u16 MaxHp;
  u16 MaxMp;
  u16 level;
  u64 *v53;
  s32 v55;
  u64 *v56;
  datUnitWork_t_o *v58;
  u32 exp;
  u16 v66;
  datUnitWork_t_o *work;

  work = w;
  w->level = Get(id, 1, 0)->level;
  param = w->param;
  v8 = Get(id, 1, 0)->param;
  v9 = v8->m_Items[0];
  param->m_Items[0] = v9;
  v10 = w->param;
  v12 = Get(id, 1, 0)->param;
  v13 = v12->m_Items[1];
  v10->m_Items[1] = v13;
  v14 = w->param;
  v16 = Get(id, 1, 0)->param;
  v18 = v16->m_Items[2];
  v14->m_Items[2] = v18;
  v20 = w->param;
  v22 = Get(id, 1, 0)->param;
  v23 = v22->m_Items[3];
  v20->m_Items[3] = v23;
  v24 = w->param;
  v26 = Get(id, 1, 0)->param;
  v28 = v26->m_Items[4];
  v24->m_Items[4] = v28;
  v30 = w->param;
  v32 = Get(id, 1, 0)->param;
  v30->m_Items[5] = v32->m_Items[5];
  v35 = 0;
  for (i = 4; i != 28; ++i)
  {
    v37 = i - 4;
    Event = Get(id, 0)->Event;
    if (!*(*(&Event->obj.klass + i) + 16LL))
    {
      v40 = Get(id, 0)->Event;
      if (*(*(&v40->obj.klass + i) + 17LL) == 1)
      {
        skill = work->skill;
        v43 = Get(id, 0)->Event;
        v46 = skill + 4 * v35++;
        *(v46 + 8) = *(*(&v43->obj.klass + i) + 18LL);
      }
    }
  }
  v47 = work;
  MaxHp = datGetMaxHp(work);
  work->maxhp = MaxHp;
  v47->hp = MaxHp;
  MaxMp = datGetMaxMp(v47);
  level = v47->level;
  v47->maxmp = MaxMp;
  v47->mp = MaxMp;
  v47->skillcnt = v35;
  v66 = level;
  v53 = sub_8D3950(ushort, &v66);
  Write_2930400("YAMI-B Lv:{0:D}\n", v53);
  v55 = v47->level;
  v47->exp = cmbCalcLevelUpExp(&work, v55);
  exp = work->exp;
  v56 = sub_8D3950(uint, &exp);
  Write_2930400("YAMI-B Exp:{0:D}\n", v56);
  v58 = work;
  fclEncycRegist(v58, 0, 0);
}

// 0x163bba0
void datDeadNakama(s32 did) {
  s64 i;
  u64 v6;
  struct datUnitWork_t_array *unitwork;
  struct datUnitWork_t_array *v10;
  struct datUnitWork_t_array *v13;
  struct datUnitWork_t_array *v16;
  struct datUnitWork_t_array *v18;
  datUnitWork_t_o *v20;
  struct datUnitWork_t_array *v22;
  struct datUnitWork_t_array *v25;

  for (i = 0; i != 15; ++i)
  {
    v6 = i + 1;
    unitwork = DDS3_GBWK->unitwork;
    if ((unitwork->m_Items[i + 1]->flag & 1) != 0)
    {
      v10 = DDS3_GBWK->unitwork;
      if (v10->m_Items[i + 1]->id == did)
      {
        v13 = DDS3_GBWK->unitwork;
        if (v13->m_Items[i + 1]->hp)
        {
          v16 = DDS3_GBWK->unitwork;
          v16->m_Items[i + 1]->hp = 0;
          v18 = DDS3_GBWK->unitwork;
          v20 = v18->m_Items[i + 1];
          datSetBadStat(v20, 0x800u);
        }
        v22 = DDS3_GBWK->unitwork;
        if ((v22->m_Items[i + 1]->flag & 2) != 0)
        {
          v25 = DDS3_GBWK->unitwork;
          v25->m_Items[i + 1]->flag &= ~2u;
        }
      }
    }
  }
}

// 0x163fb10
s32 datDelDevil(s32 id) {
  cmpRemoveDevilEx(id);
  return id;
}

// 0x1619970
void datEquipHearts(s32 HeartsID) {
  struct dds3GlobalWork_t_o *DDS3_GBWK;
  struct datUnitWork_t_array *pUnitWork;
  datUnitWork_t_o *unitWork;
  u8 heartsequip;
  s8 v12;

  pUnitWork = DDS3_GBWK->unitwork;
  if (DDS3_GBWK->heartscnt)
  {
    unitWork = pUnitWork->m_Items[0];
    else if (DDS3_GBWK->heartsequip == HeartsID)
    {
      return;
    }
    datRemoveHearts();
    DDS3_GBWK->heartsequip = HeartsID;
    heartsequip = DDS3_GBWK->heartsequip;
    cmbAddHeartsParam(heartsequip, unitWork);
    v12 = DDS3_GBWK->heartsequip;
    rstLoadHeartsSkill(v12, unitWork);
    cmpSetMaxHPMP(unitWork);
  }
}

// 0x1639900
s32 datExecSkill(s32 nskill, datUnitWork_t *s, datUnitWork_t *d) {
  s32 SkillKouka;
  s32 v10;
  s32 SkillBadKouka;
  s32 result;
  struct datNormalSkill_t_array *tbl;
  s32 v18;
  s32 v19;
  struct datNormalSkill_t_array *v21;
  struct dds3GlobalWork_t_o *DDS3_GBWK;
  s32 v25;

  if (!s || !d)
    goto LABEL_38;
  SkillKouka = datGetSkillKouka(nskill, 0, s, d);
  v10 = datGetSkillKouka(nskill, 1, s, d);
  SkillBadKouka = datGetSkillBadKouka(nskill, s, d);
  result = 0;
  if (v10 | SkillBadKouka | SkillKouka)
  {
    if (SkillBadKouka)
    {
      if ((tbl->m_Items[nskill]->badtype | 2) != 3)
      {
        d->badstatus &= ~SkillBadKouka;
        if (!v10)
          goto LABEL_27;
        goto LABEL_21;
      }
      datSetBadStat(d, SkillBadKouka);
    }
    if (!v10)
    {
LABEL_27:
      if (SkillKouka)
      {
        v19 = (SkillKouka + d->hp) & ~((SkillKouka + d->hp) >> 31);
        if (v19 > d->maxhp)
          LOWORD(v19) = d->maxhp;
        d->hp = v19;
        if (!v19)
        {
          datSetBadStat(d, 0x800u);
        }
      }
LABEL_38:
      v21 = tbl;
      switch (v21->m_Items[nskill]->program)
      {
        case 8u:
          v25 = DDS3_GBWK->stat | 1;
          goto LABEL_60;
        case 9u:
          v25 = DDS3_GBWK->stat | 2;
          goto LABEL_60;
        case 0xAu:
          v25 = DDS3_GBWK->stat | 4;
          goto LABEL_60;
        case 0xBu:
          v25 = DDS3_GBWK->stat | 8;
LABEL_60:
          DDS3_GBWK->stat = v25;
          break;
        default:
          return 1;
      }
      return 1;
    }
LABEL_21:
    v18 = (v10 + d->mp) & ~((v10 + d->mp) >> 31);
    if (v18 > d->maxmp)
      LOWORD(v18) = d->maxmp;
    d->mp = v18;
    goto LABEL_27;
  }
  return result;
}

// 0x163e760
void datFieldSkillKaifuku(void) {
  u64 i;
  struct datUnitWork_t_array *unitwork;
  datUnitWork_t_o *v7;

  for (i = 0; i != 16; ++i)
  {
    unitwork = DDS3_GBWK->unitwork;
    v7 = unitwork->m_Items[i];
    if ((~v7->flag & 3) == 0)
    {
      datSetAutoKaifukuSkill(v7, 349);
      datSetAutoKaifukuSkill(v7, 350);
    }
  }
}

// 0x163d430
s32 datGet3Zokusei(datUnitWork_t *work) {
  s32 id;
  s32 v4;
  s32 v6;

  if ((work->flag & 4) != 0)
    return 0;
  id = work->id;
  v4 = 1;
  if ((Get(id, 1, 0)->flag & 0x40) != 0)
    return v4;
  v6 = work->id;
  return Get(v6, 1, 0)->flag >> 7;
}

// 0x16386f0
u32 datGetAisyo(datUnitWork_t *work, s32 attr) {
  u32 flag;
  s32 id;
  s32 aisyoid;
  u32 v10;
  s32 v11;
  s32 v12;
  u32 v13;
  u32 result;
  u32 v17;

  if (attr == -1)
    return 0;
  flag = work->flag;
  if ((flag & 4) != 0)
  {
    v11 = 0;
    v12 = attr;
    v13 = flag;
  }
  else
  {
    id = work->id;
    aisyoid = Get(id, 1, 0)->aisyoid;
    v10 = work->flag;
    v11 = aisyoid;
    v12 = attr;
    v13 = v10;
  }
  result = Get(v11, v12, v13);
  if ((work->badstatus & 0xFFF) == 0x400)
  {
    v17 = work->flag;
    return Get(246, attr, v17);
  }
  return result;
}

// 0x163a6c0
s32 datGetAisyoFlag(datUnitWork_t *work, s32 attr) {
  return datGetAisyo(work, attr) & 0xFFFF0000;
}

// 0x163a640
s32 datGetAisyoValue(datUnitWork_t *work, s32 attr) {
  return datGetAisyo(work, attr);
}

// 0x1639710
s32 datGetBadStatusAttr(s32 bad) {
  s32 result;
  s32 v4;

  if (bad <= 256)
  {
    if (bad <= 16)
    {
      v4 = bad - 1;
      if ((bad - 1) < 8 && ((0x8Fu >> v4) & 1) != 0)
      {
        return dword_32C2154[v4];
      }
      else if (bad == 16)
      {
        return 9;
      }
      else
      {
        return -1;
      }
    }
    else if (bad <= 64)
    {
      result = 8;
      if (bad != 32)
      {
        if (bad == 64)
          return 8;
        else
          return -1;
      }
    }
    else if (bad == 128)
    {
      return 10;
    }
    else if (bad == 256)
    {
      return 9;
    }
    else
    {
      return -1;
    }
  }
  else if (bad <= 2048)
  {
    if (bad == 512)
    {
      return 5;
    }
    else if (bad == 1024)
    {
      return 7;
    }
    else
    {
      return -1;
    }
  }
  else
  {
    if (bad <= 0x2000)
    {
      if (bad != 4096 && bad != 0x2000)
        return -1;
    }
    else if (bad != 0x4000)
    {
      return -1;
    }
    if (cfgGetBit(9u) == 3)
      return -1;
    else
      return 5;
  }
  return result;
}

// 0x1637310
s32 datGetBaseMaxHp(datUnitWork_t *work) {
  s32 level;
  s32 BaseParam;
  s32 v6;
  s32 result;

  level = work->level;
LABEL_7:
  BaseParam = datGetBaseParam(work, 3);
  if ((work->badstatus & 0xFFF) == 0x200)
    v6 = 1;
  else
    v6 = BaseParam;
  if (v6 <= 1)
    v6 = 1;
  result = 6 * (v6 + level);
  if ((work->flag & 0x20) == 0 && result >= 999)
    return 999;
  return result;
}

// 0x16374b0
s32 datGetBaseMaxMp(datUnitWork_t *work) {
  s32 level;
  s32 magic;
  s32 magic_1;
  s32 maxMpBoost;
  s32 result;

  level = work->level;
LABEL_7:
  magic = datGetBaseParam(work, 2);
  if ((work->badstatus & 0xFFF) == 0x200)
    magic_1 = 1;
  else
    magic_1 = magic;
  if (magic_1 <= 1)
    magic_1 = 1;
  maxMpBoost = 300 * (magic_1 + level);
  result = maxMpBoost / 100;
  if ((work->flag & 0x20) == 0 && maxMpBoost > 99999)
    return 999;
  return result;
}

// 0x163a560
s32 datGetBaseParam(datUnitWork_t *work, s32 paratype) {
  struct System_SByte_array *param;
  struct System_SByte_array *skillparam;
  s32 v6;
  s32 v8;
  struct System_SByte_array *mitamaparam;
  s8 v11;
  s32 v12;

  param = work->param;
  skillparam = work->skillparam;
  v6 = param->m_Items[paratype];
  v8 = skillparam->m_Items[paratype];
  if ((work->flag & 4) != 0)
  {
    v11 = v6;
  }
  else
  {
    mitamaparam = work->mitamaparam;
    v11 = mitamaparam->m_Items[paratype];
    v8 += v6;
  }
  v12 = v8 + v11;
  if (v12 <= 1)
    v12 = 1;
  if (v12 >= 40)
    return 40;
  else
    return v12;
}

// 0x1637b00
s32 datGetDefPow(datUnitWork_t *work) {
  s32 BaseParam;
  s32 v5;

LABEL_7:
  BaseParam = datGetBaseParam(work, 3);
  if ((work->badstatus & 0xFFF) == 0x200)
    v5 = 1;
  else
    v5 = BaseParam;
  if (v5 <= 1)
    v5 = 1;
  return 2 * (v5 + work->level);
}

// 0x163fb80
s32 datGetItemSkillNo(s32 itemid) {
  System_Array_o *v3;
  u32 RandIntA;
  struct datItem_t_array *tbl;

  v3 = NewSpecific(s32, 6u);
  InitializeArray_1543888(v3, Field__PrivateImplementationDetails__CE77C6C1C59F8885B997EDBF3FAF9172243357A4);
  if (itemid == 1)
  {
    RandIntA = dds3GetRandIntA(6u, "datGetItemSkillNo");
    return *(&v3[2].klass + RandIntA);
  }
  else
  {
    return tbl->m_Items[itemid]->skillid;
  }
}

// 0x163ee90
s32 datGetKotowariLank(s32 lank) {
  u32 *v3;
  u64 v5;
  u32 *v6;
  s32 *v7;
  struct System_Byte_array *kotowari;
  s64 v11;
  u32 v13;
  struct System_Byte_array *v14;
  s64 v15;
  u32 v16;
  u64 v17;
  s32 v18;
  struct System_Byte_array *v24;
  s64 v25;
  u32 v27;
  struct System_Byte_array *v28;
  s64 v29;
  u32 v30;
  u64 v31;
  s32 v32;
  struct System_Byte_array *v38;
  s64 v40;
  u32 v42;
  struct System_Byte_array *v43;
  s64 v44;
  u32 v45;
  u64 v46;
  s32 v48;
  s64 v56;

  v3 = NewSpecific(s32, 4u);
  v6 = v3 + 6;
  v5 = v3[6];
  v7 = v3;
  v3[9] = 1;
  v3[10] = 2;
  v3[11] = 3;
  kotowari = DDS3_GBWK->kotowari;
  v11 = v7[9];
  v13 = kotowari->m_Items[v11];
  v14 = DDS3_GBWK->kotowari;
  v15 = v7[10];
  v16 = v14->m_Items[v15];
  if (v13 > v16)
    goto LABEL_29;
  if (v13 == v16)
  {
    if (dds3GetRandIntA(0x64u, "datGetKotowariLank") < 50)
    {
LABEL_29:
        goto LABEL_32;
      goto LABEL_30;
    }
  }
  v17 = *v6;
  v18 = v7[9];
  v7[9] = v7[10];
  v7[10] = v18;
  {
LABEL_30:
  }
LABEL_32:
  v24 = DDS3_GBWK->kotowari;
  v25 = v7[9];
  v27 = v24->m_Items[v25];
  v28 = DDS3_GBWK->kotowari;
  v29 = v7[11];
  v30 = v28->m_Items[v29];
  if (v27 > v30)
    goto LABEL_51;
  if (v27 == v30)
  {
    if (dds3GetRandIntA(0x64u, "datGetKotowariLank") < 50)
    {
LABEL_51:
        goto LABEL_54;
      goto LABEL_52;
    }
  }
  v31 = *v6;
  v32 = v7[9];
  v7[9] = v7[11];
  v7[11] = v32;
  {
LABEL_52:
  }
LABEL_54:
  v38 = DDS3_GBWK->kotowari;
  v40 = v7[10];
  v42 = v38->m_Items[v40];
  v43 = DDS3_GBWK->kotowari;
  v44 = v7[11];
  v45 = v43->m_Items[v44];
  if (v42 <= v45)
  {
    if (v42 != v45)
      goto LABEL_66;
    if (dds3GetRandIntA(0x64u, "datGetKotowariLank") >= 50)
    {
LABEL_66:
      v46 = *v6;
      v48 = v7[10];
      v7[10] = v7[11];
      v7[11] = v48;
    }
  }
  v56 = lank + 1LL;
  return v7[v56 + 8];
}

// 0x163fcd0
s32 datGetLevelForDraw(datUnitWork_t *work) {
  if (work->level >= 0x63u)
    return 99;
  else
    return work->level;
}

// 0x16376f0
s32 datGetMagicAtkPow(datUnitWork_t *work) {
  s32 BaseParam;
  s32 v8;
  s32 v9;
  s32 v10;
  s32 v11;
  s64 v12;

  if ((work->flag & 4) != 0)
  {
      goto LABEL_9;
  }
  else
  {
      goto LABEL_9;
  }
LABEL_9:
LABEL_11:
  BaseParam = datGetBaseParam(work, 2);
  if ((work->badstatus & 0xFFF) == 0x200)
    v8 = 1;
  else
    v8 = BaseParam;
  if (v8 <= 1)
    v9 = 1;
  else
    v9 = v8;
  v10 = datGetBaseParam(work, 2);
  if ((work->badstatus & 0xFFF) == 0x200)
    v11 = 1;
  else
    v11 = v10;
  if (v11 <= 1)
    v11 = 1;
  v12 = 1374389535LL * (85 * ((v11 >> 1) + 2 * (v9 + work->level)));
  return (v12 >> 37) + (v12 >> 63);
}

// 0x16379b0
s32 datGetMagicHitPow(datUnitWork_t *work) {
  s32 BaseParam;
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;

LABEL_7:
  BaseParam = datGetBaseParam(work, 2);
  if ((work->badstatus & 0xFFF) == 0x200)
    v7 = 1;
  else
    v7 = BaseParam;
  if (v7 <= 1)
    v8 = 1;
  else
    v8 = v7;
  v9 = datGetBaseParam(work, 5);
  if ((work->badstatus & 0xFFF) == 0x200)
    v10 = 1;
  else
    v10 = v9;
  if (v10 <= 1)
    v10 = 1;
  return work->level + 2 * v8 + ((v10 + 5) >> 1) + 15;
}

// 0x1639e20
u32 datGetMaxHp(datUnitWork_t *work) {
  s32 BaseMaxHp;
  u32 v7;
  u32 result;

  BaseMaxHp = datGetBaseMaxHp(work);
  if (datCheckSyojiSkill(work, 0x122u))
  {
    v7 = 10 * BaseMaxHp / 0x64u;
      goto LABEL_12;
  }
  else
  {
    v7 = 0;
      goto LABEL_12;
  }
LABEL_12:
  if (datCheckSyojiSkill(work, 0x123u))
LABEL_13:
    v7 += 20 * BaseMaxHp / 0x64u;
LABEL_14:
  if (datCheckSyojiSkill(work, 0x124u))
LABEL_17:
    v7 += 30 * BaseMaxHp / 0x64u;
LABEL_18:
  result = v7 + BaseMaxHp;
  if ((work->flag & 0x20) == 0 && result >= 0x3E7)
    return 999;
  return result;
}

// 0x163a3e0
u32 datGetMaxMp(datUnitWork_t *work) {
  s32 BaseMaxMp;
  u32 v7;
  u32 result;

  BaseMaxMp = datGetBaseMaxMp(work);
  if (datCheckSyojiSkill(work, 0x125u))
  {
    v7 = 10 * BaseMaxMp / 0x64u;
      goto LABEL_12;
  }
  else
  {
    v7 = 0;
      goto LABEL_12;
  }
LABEL_12:
  if (datCheckSyojiSkill(work, 0x126u))
LABEL_13:
    v7 += 20 * BaseMaxMp / 0x64u;
LABEL_14:
  if (datCheckSyojiSkill(work, 0x127u))
LABEL_17:
    v7 += 30 * BaseMaxMp / 0x64u;
LABEL_18:
  result = v7 + BaseMaxMp;
  if ((work->flag & 0x20) == 0 && result >= 0x3E7)
    return 999;
  return result;
}

// 0x163eca0
s32 datGetNakamaNum(void) {
  u64 *v1;
  s32 v3;
  s64 i;
  struct datUnitWork_t_array *unitwork;
  s64 v8;

  v1 = Allocate(datUnitWork_t);
  datUnitWork_t___ctor(v1);
  v3 = 0;
  for (i = 8; i != 20; ++i)
  {
    unitwork = DDS3_GBWK->unitwork;
    v8 = *(&unitwork->obj.klass + i);
    v3 += *(v8 + 16) & 1;
  }
  return v3;
}

// 0x163b930
s32 datGetNakamaParam(s32 did, s32 id) {
  s32 v5;
  s64 i;
  u64 v8;
  struct datUnitWork_t_array *unitwork;
  struct datUnitWork_t_array *v12;
  s64 v14;

  v5 = 0;
  for (i = 5; i != 20; ++i)
  {
    while (1)
    {
      v8 = i - 4;
      unitwork = DDS3_GBWK->unitwork;
      if (*(*(&unitwork->obj.klass + i) + 20LL) == did)
        break;
      if (++i == 20)
        return v5;
    }
    v12 = DDS3_GBWK->unitwork;
    v14 = *(*(&v12->obj.klass + i) + 40LL);
    v5 = *(v14 + id + 32);
  }
  return v5;
}

// 0x16375d0
s32 datGetNormalAtkPow(datUnitWork_t *work) {
  s32 BaseParam;
  s32 v6;
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;

  if ((work->flag & 4) != 0)
  {
      goto LABEL_9;
  }
  else
  {
      goto LABEL_9;
  }
LABEL_9:
LABEL_11:
  BaseParam = datGetBaseParam(work, 0);
  v6 = work->badstatus & 0xFFF;
  if (v6 == 512)
    v7 = 1;
  else
    v7 = BaseParam;
  if (v7 <= 1)
    v7 = 1;
  v8 = 2 * (v7 + work->level);
  if (v8 >= 0)
    v9 = v8;
  else
    v9 = v8 + 1;
  v10 = v9 >> 1;
  if (v6 == 64)
    return v10;
  else
    return v8;
}

// 0x1637870
s32 datGetNormalHitPow(datUnitWork_t *work) {
  s32 BaseParam;
  s32 v7;
  s32 v8;
  s32 v9;

LABEL_7:
  BaseParam = datGetBaseParam(work, 4);
  if (BaseParam <= 1)
    v7 = 1;
  else
    v7 = BaseParam;
  v8 = datGetBaseParam(work, 5);
  if ((work->badstatus & 0xFFF) == 0x200)
    v9 = 1;
  else
    v9 = v8;
  if (v9 <= 1)
    v9 = 1;
  return work->level + 2 * v7 + ((v9 + 5) >> 1) + 15;
}

// 0x1637410
s32 datGetParam(datUnitWork_t *work, s32 paratype) {
  s32 BaseParam;
  s32 v7;

  BaseParam = datGetBaseParam(work, paratype);
  if ((work->badstatus & 0xFFF) != 0x200 || paratype == 4)
    v7 = BaseParam;
  else
    v7 = 1;
  if (v7 <= 1)
    return 1;
  else
    return v7;
}

// 0x163baa0
s32 datGetPlayerLND(void) {
  struct datUnitWork_t_array *unitwork;
  u8 PlayerRaceID;

  unitwork = DDS3_GBWK->unitwork;
  else if (!LODWORD(unitwork->max_length))
  {
    goto LABEL_9;
  }
  PlayerRaceID = cmbGetPlayerRaceID(unitwork->m_Items);
  if (PlayerRaceID)
    return (PlayerRaceID - 1) % 3;
  else
    return 1;
}

// 0x163b440
s32 datGetPlayerLevel(void) {
  struct datUnitWork_t_array *unitwork;

  unitwork = DDS3_GBWK->unitwork;
  return unitwork->m_Items[0]->level;
}

// 0x163b570
s32 datGetPlayerParam(s32 id) {
  struct datUnitWork_t_array *unitwork;
  struct System_SByte_array *param;
  s32 v8;
  s8 heartsequip;
  s32 HeartsParam;

  unitwork = DDS3_GBWK->unitwork;
  param = unitwork->m_Items[0]->param;
  v8 = param->m_Items[id];
  heartsequip = DDS3_GBWK->heartsequip;
  if (heartsequip)
  {
    HeartsParam = cmbGetHeartsParam(heartsequip, id);
  }
  else
  {
    HeartsParam = 0;
  }
  return v8 - HeartsParam;
}

// 0x163b1d0
s32 datGetRace(datUnitWork_t *work) {
  s32 id;

  if ((work->flag & 4) != 0)
    return 0;
  id = work->id;
  return Get(id, 1, 0)->race;
}

// 0x1637bf0
s32 datGetSakePow(datUnitWork_t *work) {
  s32 BaseParam;
  s32 v7;
  s32 v8;
  s32 v9;

LABEL_7:
  BaseParam = datGetBaseParam(work, 4);
  if (BaseParam <= 1)
    v7 = 1;
  else
    v7 = BaseParam;
  v8 = datGetBaseParam(work, 5);
  if ((work->badstatus & 0xFFF) == 0x200)
    v9 = 1;
  else
    v9 = v8;
  if (v9 <= 1)
    v9 = 1;
  return ((v7 + 5) * 1.5) + work->level + v9 + 10;
}

// 0x16390b0
s32 datGetSkillBadKouka(s32 nskill, datUnitWork_t *s, datUnitWork_t *d) {
  u64 *v8;
  f32 v9;
  struct datNormalSkill_t_array *datNormalSkill_tbl;
  s32 basstatus;
  s64 v14;
  char *v16;
  char *v18;
  char *v20;
  char *v22;
  char *v24;
  char *v26;
  char *v28;
  char *v30;
  char *v32;
  char *v34;
  char *v36;
  u32 RandIntA;
  struct datNormalSkill_t_array *tbl;
  s32 BadStatusAttr;
  u32 Aisyo;
  f32 v45;
  struct datNormalSkill_t_array *v47;
  struct datNormalSkill_t_array *v50;
  f32 v52;
  f32 v53;
  struct datNormalSkill_t_array *v55;

  v8 = NewSpecific(s32, 0x10u);
  datNormalSkill_tbl = tbl;
  basstatus = datNormalSkill_tbl->m_Items[nskill]->basstatus & 0xFFF;
  if (tbl->m_Items[nskill]->badtype == 3)
  {
    if ((basstatus & 1) != 0)
    {
      v14 = 1;
      *(v8 + 8) = 0;
      if ((basstatus & 2) != 0)
      {
LABEL_11:
        v16 = v8 + 4 * v14;
        v14 = (v14 + 1);
        *(v16 + 8) = 1;
        if ((basstatus & 4) != 0)
        {
LABEL_30:
          v20 = v8 + 4 * v14;
          v14 = (v14 + 1);
          *(v20 + 8) = 2;
          if ((basstatus & 8) != 0)
          {
LABEL_33:
            v22 = v8 + 4 * v14;
            v14 = (v14 + 1);
            *(v22 + 8) = 3;
            if ((basstatus & 0x10) != 0)
            {
LABEL_36:
              v24 = v8 + 4 * v14;
              v14 = (v14 + 1);
              *(v24 + 8) = 4;
              if ((basstatus & 0x20) != 0)
              {
LABEL_39:
                v26 = v8 + 4 * v14;
                v14 = (v14 + 1);
                *(v26 + 8) = 5;
                if ((basstatus & 0x40) != 0)
                {
LABEL_42:
                  v28 = v8 + 4 * v14;
                  v14 = (v14 + 1);
                  *(v28 + 8) = 6;
                  if ((basstatus & 0x80) != 0)
                  {
LABEL_45:
                    v30 = v8 + 4 * v14;
                    v14 = (v14 + 1);
                    *(v30 + 8) = 7;
                    if ((basstatus & 0x100) != 0)
                    {
LABEL_48:
                      v32 = v8 + 4 * v14;
                      v14 = (v14 + 1);
                      *(v32 + 8) = 8;
                      if ((basstatus & 0x200) != 0)
                      {
LABEL_51:
                        v34 = v8 + 4 * v14;
                        v14 = (v14 + 1);
                        *(v34 + 8) = 9;
                        if ((basstatus & 0x400) != 0)
                        {
LABEL_54:
                          v36 = v8 + 4 * v14;
                          v14 = (v14 + 1);
                          *(v36 + 8) = 10;
                          if ((basstatus & 0x800) == 0)
                            goto LABEL_57;
                          goto LABEL_27;
                        }
LABEL_26:
                        if ((basstatus & 0x800) == 0)
                        {
LABEL_57:
                          {
                          }
                          RandIntA = dds3GetRandIntA(v14, "datGetSkillBadKouka");
                          basstatus = 1 << *(v8 + RandIntA + 8);
                          goto LABEL_63;
                        }
LABEL_27:
                        v18 = v8 + 4 * v14;
                        LODWORD(v14) = v14 + 1;
                        *(v18 + 8) = 11;
                        goto LABEL_57;
                      }
LABEL_25:
                      if ((basstatus & 0x400) != 0)
                        goto LABEL_54;
                      goto LABEL_26;
                    }
LABEL_24:
                    if ((basstatus & 0x200) != 0)
                      goto LABEL_51;
                    goto LABEL_25;
                  }
LABEL_23:
                  if ((basstatus & 0x100) != 0)
                    goto LABEL_48;
                  goto LABEL_24;
                }
LABEL_22:
                if ((basstatus & 0x80) != 0)
                  goto LABEL_45;
                goto LABEL_23;
              }
LABEL_21:
              if ((basstatus & 0x40) != 0)
                goto LABEL_42;
              goto LABEL_22;
            }
LABEL_20:
            if ((basstatus & 0x20) != 0)
              goto LABEL_39;
            goto LABEL_21;
          }
LABEL_19:
          if ((basstatus & 0x10) != 0)
            goto LABEL_36;
          goto LABEL_20;
        }
LABEL_18:
        if ((basstatus & 8) != 0)
          goto LABEL_33;
        goto LABEL_19;
      }
    }
    else
    {
      v14 = 0;
      if ((basstatus & 2) != 0)
        goto LABEL_11;
    }
    if ((basstatus & 4) != 0)
      goto LABEL_30;
    goto LABEL_18;
  }
LABEL_63:
  if (tbl->m_Items[nskill]->badtype == 1)
  {
    BadStatusAttr = datGetBadStatusAttr(basstatus);
    Aisyo = datGetAisyo(d, BadStatusAttr);
    if ((Aisyo & 0x170000) != 0)
    {
      v45 = 0.0;
        goto LABEL_79;
    }
    else
    {
      v9 = Aisyo;
      v45 = v9 / 100.0;
        goto LABEL_79;
    }
  }
  else
  {
    v45 = 1.0;
      goto LABEL_79;
  }
LABEL_79:
  v47 = tbl;
  if (v47->m_Items[nskill]->badlevel == 255)
    goto LABEL_94;
  v50 = tbl;
  LOBYTE(v9) = v50->m_Items[nskill]->badlevel;
  v52 = v45 * (LODWORD(v9) / 100.0);
  if ((s->flag & 0x20) != 0)
    v53 = (v52 * 100.0) * 0.7;
  else
    v53 = v52 * 100.0;
  if (dds3GetRandIntA(0x64u, "datGetSkillBadKouka") >= v53)
    return 0;
LABEL_94:
  v55 = tbl;
  if (v55->m_Items[nskill]->badtype == 1 && basstatus <= (d->badstatus & 0xFFF))
    return 0;
  return basstatus;
}

// 0x163f580
s32 datGetSkillCost(datUnitWork_t *w, s32 nskill) {
  struct datNormalSkill_t_array *tbl;
  s32 costtype;
  s32 id;
  s32 maxhp;
  struct datNormalSkill_t_array *v12;
  u32 max_length;
  s32 v14;
  struct datNormalSkill_t_array *v16;
  u32 v20;

  costtype = tbl->m_Items[nskill]->costtype;
  if (costtype != 2)
  {
    if (costtype == 1)
    {
      if ((w->flag & 4) != 0)
        goto LABEL_16;
      id = w->id;
      if ((Get(id, 1, 0)->flag & 0x200) == 0 && (w->flag & 0x20) == 0)
      {
LABEL_16:
        maxhp = w->maxhp;
        v12 = tbl;
        max_length = v12->max_length;
        v20 = v12->m_Items[nskill]->cost * maxhp / 0x64;
        if (v20 + v12->m_Items[nskill]->costbase)
          return v20 + v12->m_Items[nskill]->costbase;
        else
          return 1;
      }
    }
    return 0;
  }
  if ((w->flag & 4) == 0)
  {
    v14 = w->id;
    if ((Get(v14, 1, 0)->flag & 0x400) != 0)
      return 0;
  }
  v16 = tbl;
  return v16->m_Items[nskill]->cost;
}

// 0x1638840
s32 datGetSkillKouka(s32 nskill, s32 type, datUnitWork_t *s, datUnitWork_t *d) {
  datUnitWork_t_o *v10;
  f32 AisyoRitu;
  f32 v13;
  struct datNormalSkill_t_array *v15;
  u32 v16;
  struct datNormalSkill_t_array *tbl;
  u32 max_length;
  s32 v20;
  s16 mpn;
  s16 mpbase;
  u16 *p_maxmp;
  u16 *p_mp;
  u32 mptype;
  s32 v28;
  s32 v29;
  struct datNormalSkill_t_array *v31;
  s32 MagicAttack;
  s32 v34;
  s32 v35;
  s32 v36;
  s32 v39;
  s32 v40;
  struct datNormalSkill_t_array *v42;
  u32 MagicKaifuku;
  f32 v45;
  f32 v46;
  s32 v47;
  s32 v48;
  struct datNormalSkill_t_array *v50;
  u32 hptype;
  f32 RandFloatA;
  f32 v54;
  s32 v56;

  AisyoRitu = GetAisyoRitu(nskill, *&type, d, d);
  v13 = AisyoRitu;
  if (type == 1)
  {
    max_length = tbl->max_length;
    mpn = tbl->m_Items[nskill]->mpn;
    mpbase = tbl->m_Items[nskill]->mpbase;
    p_maxmp = &d->maxmp;
    p_mp = &d->mp;
    mptype = tbl->m_Items[nskill]->mptype;
    if (mptype > 0xF)
    {
LABEL_44:
      v20 = -1;
      v36 = -1;
      goto LABEL_106;
    }
  }
  else
  {
    if (type)
      return 0;
    v15 = tbl;
    v16 = v15->max_length;
    mpn = v15->m_Items[nskill]->hpn;
    mpbase = tbl->m_Items[nskill]->hpbase;
    p_maxmp = &d->maxhp;
    p_mp = &d->hp;
    mptype = tbl->m_Items[nskill]->hptype;
  }
  v28 = *p_maxmp;
  v29 = *p_mp;
  v20 = 0;
  switch (mptype)
  {
    case 0u:
      return v20;
    case 1u:
    case 0xCu:
    case 0xEu:
      v31 = tbl;
      if (v31->m_Items[nskill]->koukatype == 1)
      {
        MagicAttack = GetMagicAttack(nskill, s, v10, mpn);
        goto LABEL_97;
      }
      if (!v31->m_Items[nskill]->koukatype)
      {
        MagicAttack = GetButuriAttack(nskill, s, d, mpn);
        v34 = s->badstatus & 0xFFF;
        if (v34 == 512 || v34 == 64)
        {
          if (MagicAttack >= 0)
            v35 = MagicAttack;
          else
            v35 = MagicAttack + 1;
          v36 = (v35 >> 1) + mpbase;
          goto LABEL_105;
        }
LABEL_97:
        v36 = MagicAttack + mpbase;
        goto LABEL_105;
      }
      v36 = mpbase;
LABEL_105:
      v20 = -1;
LABEL_106:
      v50 = tbl;
      hptype = v50->m_Items[nskill]->hptype;
      if (hptype > 7)
        goto LABEL_121;
      if (((1 << hptype) & 0x38) != 0)
        goto LABEL_126;
      if (((1 << hptype) & 0x42) != 0)
      {
        if (v36 < 1)
          goto LABEL_126;
LABEL_122:
        RandFloatA = dds3GetRandFloatA("datGetSkillKouka0");
        v54 = (((RandFloatA + -0.5) + (RandFloatA + -0.5)) * 0.05) * v36;
        v36 = (v13 * ((v54 + v36) & ~((v54 + v36) >> 31)));
        goto LABEL_126;
      }
      if (((1 << hptype) & 0x84) == 0)
      {
LABEL_121:
        if (v36 < 1 || hptype != 12)
          goto LABEL_126;
        goto LABEL_122;
      }
      if (v20 >= 1)
      {
        v20 = (v13 * v20);
        if ((v20 & 0x80000000) == 0)
          return v20;
        goto LABEL_127;
      }
LABEL_126:
      if ((v20 & 0x80000000) == 0)
        return v20;
LABEL_127:
      if (v36)
        return -v36;
      else
        return -1;
    case 2u:
      v42 = tbl;
      if (v42->m_Items[nskill]->koukatype == 1)
      {
        MagicKaifuku = GetMagicKaifuku(v56, s, v10, mpn);
      }
      else if (v42->m_Items[nskill]->koukatype)
      {
        MagicKaifuku = 0;
      }
      else
      {
        MagicKaifuku = GetButuriAttack(nskill, s, d, mpn);
      }
      goto LABEL_141;
    case 3u:
      if (mpn + mpbase >= v29)
        v36 = -1;
      else
        v36 = v29 - (mpn + mpbase);
      goto LABEL_105;
    case 4u:
    case 0xDu:
      v36 = mpn + mpbase;
      goto LABEL_105;
    case 5u:
      v20 = mpn + mpbase;
      v36 = -1;
      goto LABEL_106;
    case 6u:
      if ((s->flag & 0x20) != 0)
      {
        v45 = (((datGetBaseMaxHp(s) / 69.6) * mpn) * 0.6) + (-50.0 / (s->level + 10));
      }
      else
      {
        LOWORD(AisyoRitu) = s->maxhp;
        v45 = (LODWORD(AisyoRitu) / 69.6) * mpn;
      }
      v48 = v45;
      goto LABEL_104;
    case 7u:
      if ((s->flag & 0x20) != 0)
      {
        v46 = (((datGetBaseMaxHp(s) / 69.6) * mpn) * 0.6) + (-50.0 / (s->level + 10));
      }
      else
      {
        LOWORD(AisyoRitu) = s->maxhp;
        v46 = (LODWORD(AisyoRitu) / 69.6) * mpn;
      }
      v20 = v46 + mpbase;
      v36 = -1;
      goto LABEL_106;
    case 8u:
      v39 = v29 * mpn;
      goto LABEL_88;
    case 9u:
      v40 = v29 * mpn;
      goto LABEL_83;
    case 0xAu:
      v39 = v28 * mpn;
LABEL_88:
      v48 = v39 / 100;
LABEL_104:
      v36 = v48 + mpbase;
      goto LABEL_105;
    case 0xBu:
      v40 = v28 * mpn;
LABEL_83:
      v47 = v40 / 100 + mpbase;
      if (v47 <= 1)
        v20 = 1;
      else
        v20 = v47;
      v36 = -1;
      goto LABEL_106;
    case 0xFu:
      MagicKaifuku = dds3GetRandIntA(mpn, "datGetSkillKouka");
LABEL_141:
      v20 = MagicKaifuku + mpbase;
      v36 = -1;
      goto LABEL_106;
    default:
      goto LABEL_44;
  }
}

// 0x163e2a0
s32 datGetUniqueDevilId(s32 uid) {
  s64 v3;
  s32 v4;
  u64 v6;
  struct datUnitWork_t_array *unitwork;
  struct datUnitWork_t_array *v10;
  struct datUnitWork_t_array *v13;
  struct datUnitWork_t_array *v16;
  struct datUnitWork_t_array *v20;

  v3 = 4;
  v4 = -1;
  while (1)
  {
    v6 = v3 - 4;
    unitwork = DDS3_GBWK->unitwork;
    if ((*(*(&unitwork->obj.klass + v3) + 16LL) & 1) != 0)
    {
      v10 = DDS3_GBWK->unitwork;
      if ((*(*(&v10->obj.klass + v3) + 16LL) & 4) == 0)
      {
        v13 = DDS3_GBWK->unitwork;
        if ((*(*(&v13->obj.klass + v3) + 17LL) & 4) != 0)
        {
          v16 = DDS3_GBWK->unitwork;
          if (*(*(&v16->obj.klass + v3) + 56LL) == uid)
            break;
        }
      }
    }
    ++v3;
    if (v6 >= 0xF)
      return v4;
  }
  v20 = DDS3_GBWK->unitwork;
  return *(*(&v20->obj.klass + v3) + 20LL);
}

// 0x163f9c0
void datInitBossPress(void) {
  s64 i;
  u64 v4;
  struct System_Int32_array_array *boss_press;
  s64 v7;
  struct System_Int32_array_array *v9;
  s64 v10;

  for (i = 4; i != 44; ++i)
  {
    v4 = i - 4;
    boss_press = DDS3_GBWK->boss_press;
    v7 = *(&boss_press->obj.klass + i);
    *(v7 + 32) = -1;
    v9 = DDS3_GBWK->boss_press;
    v10 = *(&v9->obj.klass + i);
    *(v10 + 36) = -1;
  }
}

// 0x163f7d0
void datInitPlayer(void) {
  u64 v3;
  s32 v4;
  struct datUnitWork_t_array *unitwork;
  u32 v7;
  struct datUnitWork_t_array *v8;
  datUnitWork_t_o *v11;
  dds3GlobalWork_c *v13;
  struct System_Int32_array *stocklist;
  u64 v16;
  struct System_Byte_array *item;

  v3 = 0;
  do
  {
    unitwork = DDS3_GBWK->unitwork;
    datUnitWork_t__Clear(unitwork->m_Items[v3]);
    ++v3;
    v4 = (v7 >> 9) & 1;
  }
  while (v3 != 16);
  v8 = DDS3_GBWK->unitwork;
  v11 = v8->m_Items[0];
  datUnitWork_t__Copy(v11, datHumanUnitWork);
  DDS3_GBWK->stockcnt = 1;
  stocklist = DDS3_GBWK->stocklist;
  stocklist->m_Items[0] = 0;
  v16 = 0;
  DDS3_GBWK->maka = 0;
  if ((v13->_2.bitflags2 & 2) != 0)
  {
LABEL_23:
    goto LABEL_25;
  }
  while (1)
  {
LABEL_25:
    item = DDS3_GBWK->item;
    item->m_Items[v16] = 0;
    if (v16 == 159)
      break;
    ++v16;
      goto LABEL_23;
  }
  evtBitOn(3076);
}

// 0x1639e00
void datOverwriteBadStat(datUnitWork_t *work, u32 badstat) {
  u16 badstatus;
  s16 v4;
  u16 v5;
  u16 v6;

  badstatus = work->badstatus;
  v4 = badstatus & 0xF000;
  v5 = badstatus | 0x8000;
  v6 = v4 & 0xF000 | badstat & 0xFFF;
  if (badstat != 0x8000)
    v5 = v6;
  work->badstatus = v5;
}

// 0x163be70
void datPartyDamage(s32 mode) {
  s64 i;
  u64 v6;
  struct datUnitWork_t_array *unitwork;
  struct datUnitWork_t_array *v10;
  struct datUnitWork_t_array *v13;
  u32 v15;
  u32 v16;
  s32 Bit;
  s32 v19;
  s32 v20;
  s16 v21;
  struct datUnitWork_t_array *v22;
  s64 j;
  u64 v26;
  struct datUnitWork_t_array *v27;
  struct datUnitWork_t_array *v30;
  struct datUnitWork_t_array *v33;
  u32 v35;
  s32 v36;
  s32 v37;
  s32 v39;
  s32 v40;
  s16 v41;
  struct datUnitWork_t_array *v42;
  u64 v44;
  struct datUnitWork_t_array *v46;
  struct datUnitWork_t_array *v49;
  struct datUnitWork_t_array *v52;
  s32 v54;
  struct datUnitWork_t_array *v56;
  struct datUnitWork_t_array *v58;
  u32 hp;
  s32 v61;
  s32 v62;
  s16 v63;
  struct datUnitWork_t_array *v64;
  u64 k;
  struct datUnitWork_t_array *v68;
  struct datUnitWork_t_array *v71;
  struct datUnitWork_t_array *v74;
  datUnitWork_t_o *v76;
  datUnitWork_t_o *v77;
  u32 v78;
  struct datUnitWork_t_array *v80;
  datUnitWork_t_o *v82;
  struct datUnitWork_t_array *v84;
  datUnitWork_t_o *v86;

  switch (mode)
  {
    case 1:
    case 4:
    case 5:
    case 6:
      for (i = 4; i != 20; ++i)
      {
        v6 = i - 4;
        unitwork = DDS3_GBWK->unitwork;
        if ((*(*(&unitwork->obj.klass + i) + 16LL) & 2) != 0)
        {
          v10 = DDS3_GBWK->unitwork;
          if (*(*(&v10->obj.klass + i) + 22LL))
          {
            v13 = DDS3_GBWK->unitwork;
            v15 = *(*(&v13->obj.klass + i) + 22LL);
            v16 = v15 / 0xA;
            Bit = cfgGetBit(9u);
            if (Bit == 2)
            {
              v16 *= 3;
            }
            else if (!Bit)
            {
              v16 = 30 * v16 / 0x64;
            }
            if (v16)
              v19 = v16;
            else
              v19 = 1;
            v20 = v15 - v19;
            if (v20 <= 1)
              v21 = 1;
            else
              v21 = v20;
            v22 = DDS3_GBWK->unitwork;
            *(*(&v22->obj.klass + i) + 22LL) = v21;
          }
        }
      }
      if ((mode - 4) < 3)
        goto LABEL_139;
      if (mode == 3)
        goto LABEL_85;
      if (mode == 2)
        goto LABEL_45;
      return;
    case 2:
LABEL_45:
      for (j = 4; j != 20; ++j)
      {
        v26 = j - 4;
        v27 = DDS3_GBWK->unitwork;
        if ((*(*(&v27->obj.klass + j) + 16LL) & 2) != 0)
        {
          v30 = DDS3_GBWK->unitwork;
          if (*(*(&v30->obj.klass + j) + 22LL))
          {
            v33 = DDS3_GBWK->unitwork;
            v35 = *(*(&v33->obj.klass + j) + 22LL);
            v36 = v35 >> 1;
            v37 = cfgGetBit(9u);
            if (v37 == 2)
            {
              v36 *= 3;
            }
            else if (!v37)
            {
              v36 = 30 * v36 / 0x64u;
            }
            if (v36)
              v39 = v36;
            else
              v39 = 1;
            v40 = v35 - v39;
            if (v40 <= 1)
              v41 = 1;
            else
              v41 = v40;
            v42 = DDS3_GBWK->unitwork;
            *(*(&v42->obj.klass + j) + 22LL) = v41;
          }
        }
      }
      if ((mode - 4) < 3)
        goto LABEL_139;
      if (mode == 3)
        goto LABEL_85;
      return;
    case 3:
LABEL_85:
      v44 = 0;
      break;
    default:
      return;
  }
  do
  {
    while (1)
    {
      else if (!IsDLC())
      {
        goto LABEL_97;
      }
      v46 = DDS3_GBWK->unitwork;
      if (v46->m_Items[v44]->id == 192)
        goto LABEL_119;
LABEL_97:
      v49 = DDS3_GBWK->unitwork;
      if ((v49->m_Items[v44]->flag & 2) == 0)
        goto LABEL_119;
      v52 = DDS3_GBWK->unitwork;
      if (!v52->m_Items[v44]->hp)
        goto LABEL_119;
      v54 = cfgGetBit(9u);
      if (!v54)
        break;
      v56 = DDS3_GBWK->unitwork;
      v56->m_Items[v44]->hp = 1;
LABEL_119:
      if (++v44 == 16)
        goto LABEL_138;
    }
    v58 = DDS3_GBWK->unitwork;
    hp = v58->m_Items[v44]->hp;
    if (50 * hp <= 0x63)
      v61 = 1;
    else
      v61 = hp >> 1;
    v62 = hp - v61;
    if (v62 <= 1)
      v63 = 1;
    else
      v63 = v62;
    v64 = DDS3_GBWK->unitwork;
    v64->m_Items[v44++]->hp = v63;
  }
  while (v44 != 16);
LABEL_138:
  if ((mode - 4) <= 2)
  {
LABEL_139:
    for (k = 0; k != 16; ++k)
    {
      v68 = DDS3_GBWK->unitwork;
      if ((v68->m_Items[k]->flag & 2) != 0)
      {
        v71 = DDS3_GBWK->unitwork;
        if (v71->m_Items[k]->hp)
        {
          if (mode == 6)
          {
            v80 = DDS3_GBWK->unitwork;
            v82 = v80->m_Items[k];
            v77 = v82;
            v78 = 32;
          }
          else if (mode == 5)
          {
            v84 = DDS3_GBWK->unitwork;
            v86 = v84->m_Items[k];
            v77 = v86;
            v78 = 256;
          }
          else
          {
            v74 = DDS3_GBWK->unitwork;
            v76 = v74->m_Items[k];
            v77 = v76;
            v78 = 64;
          }
          datSetBadStat(v77, v78);
        }
      }
    }
  }
}

// 0x163c7b0
void datPartyDamageFld(s32 mode) {
  u64 i;
  struct datUnitWork_t_array *unitwork;
  struct datUnitWork_t_array *v8;
  struct datUnitWork_t_array *v11;
  struct datUnitWork_t_array *v14;
  s32 hp;
  s32 Bit;
  u32 v18;
  u32 v19;
  bool v20;
  s32 v22;
  s16 v23;
  struct datUnitWork_t_array *v24;
  s64 j;
  u64 v28;
  struct datUnitWork_t_array *v29;
  struct datUnitWork_t_array *v32;
  struct datUnitWork_t_array *v35;
  s32 v37;
  u32 v38;
  s32 v39;
  s32 v41;
  s32 v42;
  s16 v43;
  struct datUnitWork_t_array *v44;
  s64 k;
  u64 v48;
  struct datUnitWork_t_array *v49;
  struct datUnitWork_t_array *v52;
  struct datUnitWork_t_array *v55;
  s32 v57;
  signed s32 v59;
  s32 v61;
  s32 v62;
  s32 v63;
  s16 v64;
  struct datUnitWork_t_array *v65;
  s64 m;
  u64 v69;
  struct datUnitWork_t_array *v70;
  struct datUnitWork_t_array *v73;
  struct datUnitWork_t_array *v76;
  u32 v78;
  char v80;
  s32 v81;
  s32 v82;
  s16 v83;
  struct datUnitWork_t_array *v84;
  s32 v86;

  switch (mode)
  {
    case 1:
      for (i = 0; i != 16; ++i)
      {
        unitwork = DDS3_GBWK->unitwork;
        if ((unitwork->m_Items[i]->flag & 2) != 0)
        {
          v8 = DDS3_GBWK->unitwork;
          if ((v8->m_Items[i]->badstatus & 0x40) != 0)
          {
            v11 = DDS3_GBWK->unitwork;
            if (v11->m_Items[i]->hp)
            {
              v14 = DDS3_GBWK->unitwork;
              hp = v14->m_Items[i]->hp;
              Bit = cfgGetBit(9u);
              v18 = 3 * (3 * hp / 0x64u);
              v19 = 3 * hp / 0x190u;
              if (Bit)
                v19 = 3 * hp / 0x64u;
              v20 = Bit == 2;
              if (!v20)
                v18 = v19;
              if (!v18)
                v18 = 1;
              v22 = hp - v18;
              if (v22 <= 1)
                v23 = 1;
              else
                v23 = v22;
              v24 = DDS3_GBWK->unitwork;
              v24->m_Items[i]->hp = v23;
            }
          }
        }
      }
      break;
    case 2:
      for (j = 4; j != 20; ++j)
      {
        v28 = j - 4;
        v29 = DDS3_GBWK->unitwork;
        if ((*(*(&v29->obj.klass + j) + 16LL) & 2) != 0)
        {
          v32 = DDS3_GBWK->unitwork;
          if (*(*(&v32->obj.klass + j) + 22LL))
          {
            v35 = DDS3_GBWK->unitwork;
            v37 = *(*(&v35->obj.klass + j) + 22LL);
            v38 = 3 * v37 / 0x64u;
            v39 = cfgGetBit(9u);
            if (v39 == 2)
            {
              v38 *= 3;
            }
            else if (!v39)
            {
              v38 = (30 * v38) / 0x64u;
            }
            if (v38)
              v41 = v38;
            else
              v41 = 1;
            v42 = v37 - v41;
            if (v42 <= 1)
              v43 = 1;
            else
              v43 = v42;
            v44 = DDS3_GBWK->unitwork;
            *(*(&v44->obj.klass + j) + 22LL) = v43;
          }
        }
      }
      if (mode == 4)
        goto LABEL_128;
      if (mode == 3)
        goto LABEL_88;
      break;
    case 3:
LABEL_88:
      v86 = mode;
      for (k = 4; k != 20; ++k)
      {
        v48 = k - 4;
        v49 = DDS3_GBWK->unitwork;
        if ((*(*(&v49->obj.klass + k) + 16LL) & 2) != 0)
        {
          v52 = DDS3_GBWK->unitwork;
          if (*(*(&v52->obj.klass + k) + 22LL))
          {
            v55 = DDS3_GBWK->unitwork;
            v57 = *(*(&v55->obj.klass + k) + 22LL);
            v59 = (dds3GetRandIntA(2u, "datPartyDamageFld") + 1) * v57;
            v20 = cfgGetBit(9u) == 0;
            if (v20)
              v61 = 200;
            else
              v61 = 100;
            v62 = v59 / v61;
            if (!v62)
              v62 = 1;
            v63 = v57 - v62;
            if (v63 <= 1)
              v64 = 1;
            else
              v64 = v63;
            v65 = DDS3_GBWK->unitwork;
            *(*(&v65->obj.klass + k) + 22LL) = v64;
          }
        }
      }
      if (v86 == 4)
        goto LABEL_128;
      break;
    case 4:
LABEL_128:
      for (m = 4; m != 20; ++m)
      {
        v69 = m - 4;
        v70 = DDS3_GBWK->unitwork;
        if ((*(*(&v70->obj.klass + m) + 16LL) & 2) != 0)
        {
          v73 = DDS3_GBWK->unitwork;
          if (*(*(&v73->obj.klass + m) + 22LL))
          {
            v76 = DDS3_GBWK->unitwork;
            v78 = *(*(&v76->obj.klass + m) + 22LL);
            v20 = cfgGetBit(9u) == 0;
            if (v20)
              v80 = 2;
            else
              v80 = 1;
            v81 = v78 >> v80;
            if (!v81)
              v81 = 1;
            v82 = v78 - v81;
            if (v82 <= 1)
              v83 = 1;
            else
              v83 = v82;
            v84 = DDS3_GBWK->unitwork;
            *(*(&v84->obj.klass + m) + 22LL) = v83;
          }
        }
      }
      break;
    default:
      return;
  }
}

// 0x163cff0
void datPartyDamagePipe(s32 big, s32 sml) {
  s64 i;
  u64 v7;
  struct datUnitWork_t_array *unitwork;
  struct datUnitWork_t_array *v11;
  struct datUnitWork_t_array *v14;
  u32 v16;
  s32 v17;
  s32 Bit;
  s32 v20;
  s32 v21;
  s16 v22;
  struct datUnitWork_t_array *v23;

  if (big | sml)
  {
    for (i = 4; i != 20; ++i)
    {
      v7 = i - 4;
      unitwork = DDS3_GBWK->unitwork;
      if ((*(*(&unitwork->obj.klass + i) + 16LL) & 2) != 0)
      {
        v11 = DDS3_GBWK->unitwork;
        if (*(*(&v11->obj.klass + i) + 22LL))
        {
          v14 = DDS3_GBWK->unitwork;
          v16 = *(*(&v14->obj.klass + i) + 22LL);
          v17 = v16 / 0xA * big + 3 * v16 / 0x64 * sml;
          Bit = cfgGetBit(9u);
          if (Bit == 2)
          {
            v17 *= 3;
          }
          else if (!Bit)
          {
            v17 = 30 * v17 / 100;
          }
          if (v17)
            v20 = v17;
          else
            v20 = 1;
          v21 = v16 - v20;
          if (v21 <= 1)
            v22 = 1;
          else
            v22 = v21;
          v23 = DDS3_GBWK->unitwork;
          *(*(&v23->obj.klass + i) + 22LL) = v22;
        }
      }
    }
  }
}

// 0x163d250
void datPartyKaifuku(void) {
  s64 i;
  u64 v4;
  struct datUnitWork_t_array *unitwork;
  struct datUnitWork_t_array *v8;
  s64 v10;
  u32 v11;
  struct datUnitWork_t_array *v13;
  s64 v15;
  u32 v16;
  struct datUnitWork_t_array *v17;

  for (i = 4; i != 20; ++i)
  {
    while (1)
    {
      v4 = i - 4;
      unitwork = DDS3_GBWK->unitwork;
      if ((*(*(&unitwork->obj.klass + i) + 16LL) & 1) != 0)
        break;
      if (++i == 20)
        return;
    }
    v8 = DDS3_GBWK->unitwork;
    v10 = *(&v8->obj.klass + i);
    v11 = *(v10 + 22) + 9999;
    if (v11 > *(v10 + 24))
      LOWORD(v11) = *(v10 + 24);
    *(v10 + 22) = v11;
    v13 = DDS3_GBWK->unitwork;
    v15 = *(&v13->obj.klass + i);
    v16 = *(v15 + 26) + 9999;
    if (v16 > *(v15 + 28))
      LOWORD(v16) = *(v15 + 28);
    *(v15 + 26) = v16;
    v17 = DDS3_GBWK->unitwork;
    *(*(&v17->obj.klass + i) + 30LL) = 0;
  }
}

// 0x161b080
void datRemoveHearts(void) {
  struct dds3GlobalWork_t_o *DDS3_GBWK;
  struct datUnitWork_t_array *unitwork;
  datUnitWork_t_o *v5;
  u8 heartsequip;
  s8 v8;

  unitwork = DDS3_GBWK->unitwork;
  if (DDS3_GBWK->heartscnt)
  {
    v5 = unitwork->m_Items[0];
    heartsequip = DDS3_GBWK->heartsequip;
    cmbSubHeartsParam(heartsequip, v5);
    v8 = DDS3_GBWK->heartsequip;
    rstStoreHeartsSkill(v8, v5);
    DDS3_GBWK->heartsequip = 0;
    cmpSetMaxHPMP(v5);
  }
}

// 0x1639d90
void datResetBadStat(datUnitWork_t *work, u32 badstat) {
  work->badstatus &= ~badstat;
}

// 0x163b2d0
s32 datSearchDevilStock(s32 id) {
  s64 v3;
  s32 v4;
  u64 v6;
  struct datUnitWork_t_array *unitwork;
  struct datUnitWork_t_array *v10;
  struct datUnitWork_t_array *v13;

  v3 = 4;
  v4 = -1;
  while (1)
  {
    v6 = v3 - 4;
    unitwork = DDS3_GBWK->unitwork;
    if ((*(*(&unitwork->obj.klass + v3) + 16LL) & 1) != 0)
    {
      v10 = DDS3_GBWK->unitwork;
      if ((*(*(&v10->obj.klass + v3) + 16LL) & 4) == 0)
      {
        v13 = DDS3_GBWK->unitwork;
        if (*(*(&v13->obj.klass + v3) + 20LL) == id)
          break;
      }
    }
    ++v3;
    if (v6 > 0xE)
      return v4;
  }
  return v3 - 4;
}

// 0x163e0e0
s32 datSearchUniqueDevilStock(s32 uid) {
  s64 v3;
  s32 v4;
  u64 v6;
  struct datUnitWork_t_array *unitwork;
  struct datUnitWork_t_array *v10;
  struct datUnitWork_t_array *v13;
  struct datUnitWork_t_array *v16;

  v3 = 4;
  v4 = -1;
  while (1)
  {
    v6 = v3 - 4;
    unitwork = DDS3_GBWK->unitwork;
    if ((*(*(&unitwork->obj.klass + v3) + 16LL) & 1) != 0)
    {
      v10 = DDS3_GBWK->unitwork;
      if ((*(*(&v10->obj.klass + v3) + 16LL) & 4) == 0)
      {
        v13 = DDS3_GBWK->unitwork;
        if ((*(*(&v13->obj.klass + v3) + 17LL) & 4) != 0)
        {
          v16 = DDS3_GBWK->unitwork;
          if (*(*(&v16->obj.klass + v3) + 56LL) == uid)
            break;
        }
      }
    }
    ++v3;
    if (v6 > 0xE)
      return v4;
  }
  return v3 - 4;
}

// 0x163e4c0
void datSetAutoKaifukuSkill(datUnitWork_t *work, s32 skill) {
  struct datSpecialSkill_t_array *tbl;
  s64 v8;
  s32 n;
  s32 m;
  s32 v12;
  s32 v13;
  s32 v14;
  s32 v15;

  if (datCheckSyojiSkill(work, skill))
  {
    v8 = skill - 288LL;
    n = tbl->m_Items[v8]->n;
    m = tbl->m_Items[v8]->m;
    switch (skill)
    {
      case 346:
      case 349:
        if (n >= 1)
        {
          v12 = 0;
          v13 = work->maxhp / n;
          if (v13 < 1)
            goto LABEL_24;
          goto LABEL_15;
        }
        return;
      case 347:
      case 350:
        if (n >= 1)
        {
          v12 = work->maxmp / n;
          goto LABEL_24;
        }
        return;
      case 348:
        if (n < 1)
        {
          v13 = 0;
          if (m >= 1)
          {
LABEL_34:
            v12 = work->maxmp / m;
            if (v13 < 1)
              goto LABEL_24;
            goto LABEL_15;
          }
        }
        else
        {
          v13 = work->maxhp / n;
          if (m >= 1)
            goto LABEL_34;
        }
        v12 = 0;
        if (v13 < 1)
        {
LABEL_24:
          if (v12 < 1)
            return;
          goto LABEL_25;
        }
LABEL_15:
        v14 = (v13 + work->hp) & ~((v13 + work->hp) >> 31);
        if (v14 > work->maxhp)
          LOWORD(v14) = work->maxhp;
        work->hp = v14;
        if (v12 >= 1)
        {
LABEL_25:
          v15 = (v12 + work->mp) & ~((v12 + work->mp) >> 31);
          if (v15 > work->maxmp)
            LOWORD(v15) = work->maxmp;
          work->mp = v15;
          return;
        }
        break;
      default:
        return;
    }
  }
}

// 0x1639c90
void datSetBadStat(datUnitWork_t *work, u32 badstat) {
  u16 badstatus;
  u16 v6;
  s64 *achievementTbl;
  System_String_o *v9;

  badstatus = work->badstatus;
  if (badstat == 0x8000)
  {
    v6 = badstatus | 0x8000;
  }
  else
  {
    if ((badstatus & 0xFFFu) >= badstat)
      goto LABEL_8;
    v6 = badstatus & 0xF000 | badstat & 0xFFF;
  }
  work->badstatus = v6;
LABEL_8:
  if ((work->flag & 0x24) != 0x20)
  {
    SystemWork->Bad_Bit |= badstat;
    achievementTbl = get_achievementTbl();
    v9 = sub_B7950(0x10u, DefineAchievementID_string_, achievementTbl);
    Unlock_16599376(v9);
  }
}

// 0x163d610
void datSetDevilWork(s32 id, datUnitWork_t *w) {
  struct System_SByte_array *param;
  struct System_SByte_array *v9;
  s8 v10;
  struct System_SByte_array *v11;
  struct System_SByte_array *v13;
  s8 v14;
  struct System_SByte_array *v15;
  struct System_SByte_array *v17;
  s8 v19;
  struct System_SByte_array *v21;
  struct System_SByte_array *v23;
  s8 v24;
  struct System_SByte_array *v25;
  struct System_SByte_array *v27;
  s8 v29;
  struct System_SByte_array *v31;
  struct System_SByte_array *v33;
  s8 v35;
  tblSkill_c *v37;
  s32 v38;
  s64 v39;
  u64 v40;
  struct fclSkillParam_t_array *Event;
  struct fclSkillParam_t_array *v43;
  struct System_Int32_array *skill;
  struct fclSkillParam_t_array *v46;
  char *v49;
  u16 MaxHp;
  u16 MaxMp;

  datUnitWork_t__Clear(w);
  w->flag = 1;
  w->id = id;
  w->level = Get(id, 1, 0)->level;
  w->exp = 0;
  param = w->param;
  v9 = Get(id, 1, 0)->param;
  v10 = v9->m_Items[0];
  param->m_Items[0] = v10;
  v11 = w->param;
  v13 = Get(id, 1, 0)->param;
  v14 = v13->m_Items[1];
  v11->m_Items[1] = v14;
  v15 = w->param;
  v17 = Get(id, 1, 0)->param;
  v19 = v17->m_Items[2];
  v15->m_Items[2] = v19;
  v21 = w->param;
  v23 = Get(id, 1, 0)->param;
  v24 = v23->m_Items[3];
  v21->m_Items[3] = v24;
  v25 = w->param;
  v27 = Get(id, 1, 0)->param;
  v29 = v27->m_Items[4];
  v25->m_Items[4] = v29;
  v31 = w->param;
  v33 = Get(id, 1, 0)->param;
  v35 = v33->m_Items[5];
  v31->m_Items[5] = v35;
  if (SLODWORD(fclSkillTbl->max_length) <= id)
  {
    v38 = 0;
  }
  else
  {
    v38 = 0;
    v39 = 4;
    v40 = 0;
    if ((v37->_2.bitflags2 & 2) == 0)
      goto LABEL_51;
LABEL_49:
    while (1)
    {
LABEL_51:
      Event = Get(id, 0)->Event;
      if (!*(*(&Event->obj.klass + v39) + 16LL))
      {
        v43 = Get(id, 0)->Event;
        if (*(*(&v43->obj.klass + v39) + 17LL) == 1)
        {
          skill = w->skill;
          v46 = Get(id, 0)->Event;
          v49 = skill + 4 * v38++;
          *(v49 + 8) = *(*(&v46->obj.klass + v39) + 18LL);
        }
      }
      if (v39 == 27)
        break;
      v40 = ++v39 - 4;
        goto LABEL_49;
    }
  }
  MaxHp = datGetMaxHp(w);
  w->maxhp = MaxHp;
  w->hp = MaxHp;
  MaxMp = datGetMaxMp(w);
  w->maxmp = MaxMp;
  w->mp = MaxMp;
  w->skillcnt = v38;
}
