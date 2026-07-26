#include "types.h"

typedef struct cmpLocalStock_t cmpLocalStock_t;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;

u32 datGetMaxHp(datUnitWork_t *work);
u32 datGetMaxMp(datUnitWork_t *work);
void *dds3GetProcessData(dds3ProcessID_t **id);
u32 dds3GetProcessStat(dds3ProcessID_t **id);
s8 fclChkSignal(s8 Idx);
s32 fclClearPanelTimer(void *a);
void fclClearSignal(s8 Idx);
dds3ProcessID_t *fclScriptStart(u8 **pScriptData, s32 StartNo, dds3ProcessID_t **pPID);
s32 rcvCalcPriceRecover(datUnitWork_t *pStock);
s32 rcvGetDevilAttr(datUnitWork_t *pStock);

// 0x198ef90
void rcvAppAllRecover(datUnitWork_t *pStock) {
  u16 MaxMp;
  u16 v5;

  pStock->badstatus &= ~0x800u;
  pStock->hp = (datGetMaxHp(pStock) + 9) / 0xA;
  pStock->hp = datGetMaxHp(pStock);
  MaxMp = datGetMaxMp(pStock);
  v5 = pStock->badstatus & 0xFE9F;
  pStock->mp = MaxMp;
  pStock->badstatus = v5;
}

// 0x198ef80
void rcvAppDispel(datUnitWork_t *pStock) {
  pStock->badstatus &= ~0x8000u;
}

// 0x198ee40
s8 rcvAppRecover(datUnitWork_t *pStock) {
  pStock->hp = datGetMaxHp(pStock);
  pStock->mp = datGetMaxMp(pStock);
  return 1;
}

// 0x198eef0
void rcvAppRevive(datUnitWork_t *pStock) {
  pStock->badstatus &= ~0x800u;
  pStock->hp = (datGetMaxHp(pStock) + 9) / 0xA;
}

// 0x198eed0
void rcvAppStatusRecover(datUnitWork_t *pStock) {
  pStock->badstatus &= 0xFE9Fu;
}

// 0x198fb80
dds3ProcessFunc_t *rcvCalc(dds3ProcessID_t *PID) {
    dds3GetProcessData(0);
    fclChkSignal(0);
    fclClearSignal(0);
    fclClearPanelTimer(0);
    dds3GetProcessStat(0);
    fclScriptStart(0, 0, 0);
    return 0;
}

// 0x198ed80
s32 rcvCalcPrice(datUnitWork_t *pStock, s32 Flag) {
  s32 result;
  s32 v5;
  s32 badstatus;
  bool v7;
  s32 v8;
  s32 v9;

  result = -1;
  switch (Flag)
  {
    case 1:
      result = rcvCalcPriceRecover(pStock, *&Flag);
      break;
    case 2:
      if ((pStock->badstatus & 0x160) != 0)
        result = 100;
      else
        result = 0;
      break;
    case 4:
      result = (HIBYTE(pStock->badstatus) << 28 >> 31) & 0x190;
      break;
    case 7:
      v5 = rcvCalcPriceRecover(pStock, *&Flag);
      badstatus = pStock->badstatus;
      v7 = (badstatus & 0x160) == 0;
      v8 = badstatus << 20;
      if (v7)
        v9 = 0;
      else
        v9 = 100;
      result = v9 + v5 + ((v8 >> 31) & 0x190);
      break;
    default:
      return result;
  }
  return result;
}

// 0x198ed30
s32 rcvCalcPriceAllRecover(datUnitWork_t *pStock) {
  s32 v3;
  s32 badstatus;
  bool v5;
  s32 v6;
  s32 v7;

  v3 = rcvCalcPriceRecover(pStock);
  badstatus = pStock->badstatus;
  v5 = (badstatus & 0x160) == 0;
  v6 = badstatus << 20;
  if (v5)
    v7 = 0;
  else
    v7 = 100;
  return v7 + v3 + ((v6 >> 31) & 0x190);
}

// 0x198ed20
s32 rcvCalcPriceDispel(void) {
  return 400;
}

// 0x198ebd0
s32 rcvCalcPriceRecover(datUnitWork_t *pStock) {
  s32 v3;
  u32 MaxHp;
  s32 hp;
  u32 v6;
  f32 v7;

  if ((pStock->badstatus & 0x800) != 0)
  {
    v3 = (datGetMaxHp(pStock) + 9) / -10;
  }
  else
  {
    v3 = 0;
  }
  MaxHp = datGetMaxHp(pStock);
  hp = pStock->hp;
  v6 = MaxHp;
  v7 = (datGetMaxMp(pStock) - pStock->mp);
  return v6 + v3 - hp + (v7 * 2.5);
}

// 0x198ed00
s32 rcvCalcPriceRevive(datUnitWork_t *pStock) {
  return (HIBYTE(pStock->badstatus) << 28 >> 31) & 0x190;
}

// 0x198ece0
s32 rcvCalcPriceStatusRecover(datUnitWork_t *pStock) {
  if ((pStock->badstatus & 0x160) != 0)
    return 100;
  else
    return 0;
}

// 0x198f180
void rcvCreateLocalStock(cmpLocalStock_t *pLocalStock, s32 Flag) {
    rcvGetDevilAttr(0);
    rcvCalcPriceRecover(0);
}

// 0x198f0a0
s32 rcvGetDevilAttr(datUnitWork_t *pStock) {
  u32 hp;
  u32 MaxHp;
  u32 mp;
  u32 MaxMp;
  u32 badstatus;
  s32 v9;
  bool v10;
  u32 v11;

  hp = pStock->hp;
  MaxHp = datGetMaxHp(pStock);
  mp = pStock->mp;
  MaxMp = datGetMaxMp(pStock);
  badstatus = pStock->badstatus;
  v9 = MaxHp > hp || MaxMp > mp;
  v10 = (badstatus & 0x160) == 0;
  v11 = badstatus >> 9;
  if (!v10)
    v9 |= 2u;
  return v9 | v11 & 4;
}
