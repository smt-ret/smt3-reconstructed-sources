#include "types.h"

typedef struct datUnitWork_s datUnitWork_t;

s32 datAddDevil(s32 id, s32 sw);
s32 datAddHearts(s32 id);
void datAddItem(s32 id, s32 num);
void datAddMaka(s32 addmaka);
void datAddMakaPar(s32 addmaka);
void datAddPlayerParam(s32 id, s32 add);
s32 datAddUniqueDevil(s32 id, s32 sw, s32 uid);
s32 datBossRashGetRec(s32 eid, s32 type);
s32 datCheckMaka(s32 maka);
s32 datCheckStockFull(void);
void datCopyDevilWork(s32 id, datUnitWork_t *w);
void datDeadNakama(s32 did);
s32 datDelDevil(s32 id);
void datEquipHearts(s32 HeartsID);
s32 datGetNakamaParam(s32 did, s32 id);
s32 datGetPlayerLND(void);
s32 datGetPlayerLevel(void);
s32 datGetPlayerParam(s32 id);
s32 datGetUniqueDevilId(s32 uid);
void datPartyDamage(s32 mode);
void datPartyKaifuku(void);
void datRemoveHearts(void);
s32 datSearchDevilStock(s32 id);
s32 datSearchUniqueDevilStock(s32 uid);
s32 p2sdPlaySE(s32 a);
s32 scrGetIntPara(s32 n);
void scrSetIntReturnValue(s32 i);

// 0x1577410
s32 prm_BOSS_PRESS_REC(void) {
  s32 IntPara;
  s32 v4;
  s32 Rec;

  IntPara = scrGetIntPara(0);
  v4 = scrGetIntPara(1);
  Rec = datBossRashGetRec(IntPara, v4);
  scrSetIntReturnValue(Rec);
  return 1;
}

// 0x1575eb0
s32 prm_DH_EQUIP(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  if (IntPara)
  {
    datEquipHearts(IntPara);
    return 1;
  }
  else
  {
    datRemoveHearts();
    return 1;
  }
}

// 0x1575e10
s32 prm_DH_PLUS(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  datAddHearts(IntPara);
  return 1;
}

// 0x15764f0
s32 prm_DV_CHECK(void) {
  s32 IntPara;
  s32 v5;

  IntPara = scrGetIntPara(0);
  if (datSearchDevilStock(IntPara) == -1)
  {
    v5 = 0;
  }
  else
  {
    v5 = 1;
  }
  scrSetIntReturnValue(v5);
  return 1;
}

// 0x15774d0
s32 prm_DV_COPY_PARAM(void) {
  s32 IntPara;
  s32 v4;
  s64 i;
  u64 v7;
  struct datUnitWork_t_array *unitwork;
  struct datUnitWork_t_array *v11;
  struct datUnitWork_t_array *v14;
  datUnitWork_t_o *v16;

  IntPara = scrGetIntPara(0);
  v4 = scrGetIntPara(1);
  for (i = 5; ; ++i)
  {
    v7 = i - 4;
    unitwork = DDS3_GBWK->unitwork;
    if ((*(*(&unitwork->obj.klass + i) + 16LL) & 1) != 0)
    {
      v11 = DDS3_GBWK->unitwork;
      if (IntPara == *(*(&v11->obj.klass + i) + 20LL))
        break;
    }
    if (v7 >= 0xF)
      return 1;
  }
  v14 = DDS3_GBWK->unitwork;
  v16 = *(&v14->obj.klass + i);
  datCopyDevilWork(v4, v16);
  return 1;
}

// 0x1576360
s32 prm_DV_PLUS(void) {
  s32 IntPara;
  s32 v4;
  s32 v6;
  s32 v8;
  s32 v10;
  s32 v11;

  IntPara = scrGetIntPara(2);
  v4 = scrGetIntPara(1);
  if (IntPara)
  {
    v6 = scrGetIntPara(0);
    datAddUniqueDevil(v6, v4, IntPara);
  }
  else
  {
    v8 = scrGetIntPara(0);
    if (datSearchDevilStock(v8) == -1)
    {
      if (v4 == 2)
      {
        v10 = v8 | 0x80000000;
        v11 = 1;
      }
      else
      {
        v10 = v8;
        v11 = v4;
      }
      datAddDevil(v10, v11);
    }
  }
  return 1;
}

// 0x1575d60
s32 prm_ITEM_PLUS(void) {
  s32 IntPara;
  s32 v4;

  IntPara = scrGetIntPara(0);
  v4 = scrGetIntPara(1);
  datAddItem(IntPara, v4);
  return 1;
}

// 0x15760c0
s32 prm_MAKA_CHECK(void) {
  s32 IntPara;
  s32 v5;

  IntPara = scrGetIntPara(0);
  if (datCheckMaka(IntPara) == 1)
  {
    v5 = 1;
  }
  else
  {
    v5 = 0;
  }
  scrSetIntReturnValue(v5);
  return 1;
}

// 0x1575f80
s32 prm_MAKA_PLUS(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  datAddMaka(IntPara);
  return 1;
}

// 0x1576020
s32 prm_MAKA_PLUS_PER(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  datAddMakaPar(IntPara);
  return 1;
}

// 0x1577090
s32 prm_NAKAMA_CHK_PIKUKO(void) {
  s64 v2;
  u64 v4;
  struct datUnitWork_t_array *unitwork;
  struct datUnitWork_t_array *v8;
  s32 v10;
  struct datUnitWork_t_array *v12;
  s32 v14;

  v2 = 5;
  while (1)
  {
    v4 = v2 - 4;
    unitwork = DDS3_GBWK->unitwork;
    if ((*(*(&unitwork->obj.klass + v2) + 16LL) & 1) != 0)
    {
      v8 = DDS3_GBWK->unitwork;
      v10 = *(*(&v8->obj.klass + v2) + 20LL);
      if (scrGetIntPara(0) == v10)
      {
        v12 = DDS3_GBWK->unitwork;
        if ((*(*(&v12->obj.klass + v2) + 17LL) & 0x10) != 0)
          break;
      }
    }
    ++v2;
    if (v4 >= 0xF)
    {
      v14 = 0;
      goto LABEL_34;
    }
  }
  v14 = 1;
LABEL_34:
  scrSetIntReturnValue(v14);
  return 1;
}

// 0x1576ff0
s32 prm_NAKAMA_DEAD(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  datDeadNakama(IntPara);
  return 1;
}

// 0x1576df0
s32 prm_NAKAMA_GET_PARAM(void) {
  s32 IntPara;
  s32 v4;
  s32 NakamaParam;

  IntPara = scrGetIntPara(0);
  v4 = scrGetIntPara(1);
  NakamaParam = datGetNakamaParam(IntPara, v4);
  scrSetIntReturnValue(NakamaParam);
  return 1;
}

// 0x15761b0
s32 prm_PARTY_DAMAGE(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  datPartyDamage(IntPara);
  return 1;
}

// 0x1576250
s32 prm_PARTY_KAIFUKU(void) {
  datPartyKaifuku();
  p2sdPlaySE(16);
  return 1;
}

// 0x15762f0
s32 prm_PARTY_KAIFUKU2(void) {
  datPartyKaifuku();
  return 1;
}

// 0x1577260
s32 prm_PIKUKO_GETID(void) {
  s64 v2;
  u64 v4;
  struct datUnitWork_t_array *unitwork;
  struct datUnitWork_t_array *v8;
  s32 v10;
  struct datUnitWork_t_array *v12;
  s32 v14;

  v2 = 5;
  while (1)
  {
    v4 = v2 - 4;
    unitwork = DDS3_GBWK->unitwork;
    if ((*(*(&unitwork->obj.klass + v2) + 16LL) & 1) != 0)
    {
      v8 = DDS3_GBWK->unitwork;
      if ((*(*(&v8->obj.klass + v2) + 17LL) & 0x10) != 0)
        break;
    }
    ++v2;
    if (v4 >= 0xF)
    {
      v10 = 0;
      goto LABEL_30;
    }
  }
  v12 = DDS3_GBWK->unitwork;
  v14 = *(*(&v12->obj.klass + v2) + 20LL);
  v10 = v14;
LABEL_30:
  scrSetIntReturnValue(v10);
  return 1;
}

// 0x1576d40
s32 prm_PLAYER_ADD_PARAM(void) {
  s32 IntPara;
  s32 v4;

  IntPara = scrGetIntPara(0);
  v4 = scrGetIntPara(1);
  datAddPlayerParam(IntPara, v4);
  return 1;
}

// 0x1576f50
s32 prm_PLAYER_GET_LEVEL(void) {
  s32 PlayerLevel;

  PlayerLevel = datGetPlayerLevel();
  scrSetIntReturnValue(PlayerLevel);
  return 1;
}

// 0x1576eb0
s32 prm_PLAYER_GET_LND(void) {
  s32 PlayerLND;

  PlayerLND = datGetPlayerLND();
  scrSetIntReturnValue(PlayerLND);
  return 1;
}

// 0x1576c90
s32 prm_PLAYER_GET_PARAM(void) {
  s32 IntPara;
  s32 PlayerParam;

  IntPara = scrGetIntPara(0);
  PlayerParam = datGetPlayerParam(IntPara);
  scrSetIntReturnValue(PlayerParam);
  return 1;
}

// 0x1576bd0
s32 prm_STOCK_FULL_CHECK(void) {
  s32 v3;

  if (datCheckStockFull() == 1)
  {
    v3 = 1;
  }
  else
  {
    v3 = 0;
  }
  scrSetIntReturnValue(v3);
  return 1;
}

// 0x1576af0
s32 prm_STOCK_PLUS(void) {
  s32 maxstock;
  s32 v5;
  s32 v7;

  maxstock = DDS3_GBWK->maxstock;
  v5 = scrGetIntPara(0) + maxstock;
  if (v5 >= 12)
    v7 = 12;
  else
    v7 = v5;
  DDS3_GBWK->maxstock = v7;
  return 1;
}

// 0x1576710
s32 prm_UDV_CHECK(void) {
  s32 IntPara;
  s32 v5;

  IntPara = scrGetIntPara(0);
  if (datSearchUniqueDevilStock(IntPara) == -1)
  {
    v5 = 0;
  }
  else
  {
    v5 = 1;
  }
  scrSetIntReturnValue(v5);
  return 1;
}

// 0x15769d0
s32 prm_UDV_DELETE_NG(void) {
  s32 IntPara;
  s32 v4;
  s32 v6;
  struct datUnitWork_t_array *unitwork;
  datUnitWork_t_o *v10;

  IntPara = scrGetIntPara(0);
  v4 = datSearchUniqueDevilStock(IntPara);
  if (v4 != -1)
  {
    v6 = v4;
    unitwork = DDS3_GBWK->unitwork;
    v10 = unitwork->m_Items[v6];
    v10->flag |= 0x800u;
  }
  return 1;
}

// 0x15768b0
s32 prm_UDV_DELETE_OK(void) {
  s32 IntPara;
  s32 v4;
  s32 v6;
  struct datUnitWork_t_array *unitwork;
  datUnitWork_t_o *v10;

  IntPara = scrGetIntPara(0);
  v4 = datSearchUniqueDevilStock(IntPara);
  if (v4 != -1)
  {
    v6 = v4;
    unitwork = DDS3_GBWK->unitwork;
    v10 = unitwork->m_Items[v6];
    v10->flag &= ~0x800u;
  }
  return 1;
}

// 0x1576800
s32 prm_UDV_GETID(void) {
  s32 IntPara;
  s32 UniqueDevilId;

  IntPara = scrGetIntPara(0);
  UniqueDevilId = datGetUniqueDevilId(IntPara);
  scrSetIntReturnValue(UniqueDevilId);
  return 1;
}

// 0x15765e0
s32 prm_UDV_LEAVE(void) {
  s32 IntPara;
  s32 v4;
  s32 v6;
  struct datUnitWork_t_array *unitwork;
  s32 id;

  IntPara = scrGetIntPara(0);
  v4 = datSearchUniqueDevilStock(IntPara);
  if (v4 != -1)
  {
    v6 = v4;
    unitwork = DDS3_GBWK->unitwork;
    id = unitwork->m_Items[v6]->id;
    datDelDevil(id);
  }
  return 1;
}
