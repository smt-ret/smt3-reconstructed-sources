#include "types.h"

typedef struct nbMainProcessData_t nbMainProcessData_t;

static s32 encmax;

bool ChkLength(s32 id);
u8 Get(s32 id);
s32 GetBgmCategory(s32 encpackno, s32 encno);
s32 datGetPlayerLevel(void);
u32 dds3GetRandIntA(u32 aLimit, char *name);
bool evtBitCheck(s32 no);
s32 evtGetAgeOfMoon(void);
s32 nbCheckEncountLevel(s32 tbl);
s32 nbGetEncountJoken(s32 id);
s32 nbGetEncountMax(s32 id);
nbMainProcessData_t *nbGetMainProcessData(void);

// 0x1707bb0
s32 GetBgmCategory(s32 encpackno, s32 encno) {
  s32 btlsound;

  if (encpackno < 1)
  {
    btlsound = 0;
  }
  else
  {
    btlsound = Get(encpackno, 0)->btlsound;
  }
  if (Get(encno, 0)->btlsound)
  {
    btlsound = Get(encno, 0)->btlsound;
  }
  if (btlsound)
    return btlsound;
  else
    return 1;
}

// 0x1707dc0
s32 NB_GET_ENCNO(u32 x) {
  return x;
}

// 0x1707db0
s32 NB_GET_PACKNO(u32 x) {
  return HIBYTE(x);
}

// 0x1707ba0
s32 NB_MAKE_ENCDATA(s32 x, s32 y, s32 z) {
  return (y << 16) | (x << 24) | z;
}

// 0x1707990
s32 nbCheckEncountLevel(s32 tbl) {
  u64 v3;
  s32 v4;
  s32 v5;
  struct System_UInt16_array *devil;
  char *v8;
  s32 v9;
  s32 PlayerLevel;

  if (!tbl)
    return 0;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  do
  {
    devil = Get(tbl, 0)->devil;
    v8 = devil + 2 * v3;
    v9 = *(v8 + 16);
    if (*(v8 + 16))
    {
      v4 += Get(v9, 1, 0)->level;
      ++v5;
    }
    ++v3;
  }
  while (v3 != 11);
  if (!v5)
    return 0;
  PlayerLevel = datGetPlayerLevel();
  return v4 / v5 + PlayerLevel / 4 >= PlayerLevel;
}

// 0x17073d0
s32 nbEncountCalc(s32 id, f32 length) {
    nbGetEncountJoken(0);
    nbGetEncountMax(0);
    dds3GetRandIntA(0, 0);
    Get(0);
    nbCheckEncountLevel(0);
    return 0;
}

// 0x1707ca0
s32 nbGetBgmCategoryInBattle(void) {
  nbMainProcessData_t_o *MainProcessData;
  s32 encpackno;
  s32 encno;

  MainProcessData = nbGetMainProcessData();
  encpackno = MainProcessData->encpackno;
  encno = MainProcessData->encno;
  return GetBgmCategory(encpackno, encno);
}

// 0x1707d40
s32 nbGetBgmCategoryInField(u32 encdata) {
  return GetBgmCategory(HIBYTE(encdata), encdata);
}

// 0x1707360
s32 nbGetEncountCnt(void) {
  return DDS3_GBWK->encountcnt;
}

// 0x1706e30
s32 nbGetEncountJoken(s32 id) {
  datEncountPack_t_o *v5;
  s32 result;
  _BOOL4 v7;
  s32 eventbit2;
  _BOOL4 v9;
  struct System_Byte_array *table1;
  struct System_Byte_array *v12;
  struct System_Byte_array *v14;
  struct System_Byte_array *v16;

  if (!ChkLength(id))
    id = 1;
  v5 = Get(id, 0);
  if (v5->moonchk)
  {
    if (((1 << evtGetAgeOfMoon()) & v5->moonchk) != 0)
      return v5->table2;
  }
  if (v5->eventbit1)
  {
    v7 = evtBitCheck(v5->eventbit1);
    eventbit2 = v5->eventbit2;
    if (v5->eventbit2)
  }
  else
  {
    v7 = 0;
    eventbit2 = v5->eventbit2;
    if (v5->eventbit2)
    {
      v9 = !evtBitCheck(eventbit2);
      if (!v9)
    }
  }
  v9 = 1;
  if (!v7)
  {
    table1 = v5->table1;
    return table1->m_Items[0];
  }
  if (!v7 || !v9)
  {
    if (v7 || v9)
    {
      result = 0;
      if (v7 && !v9)
      {
        v14 = v5->table1;
        return v14->m_Items[3];
      }
    }
    else
    {
      v16 = v5->table1;
      return v16->m_Items[2];
    }
  }
  else
  {
    v12 = v5->table1;
    return v12->m_Items[1];
  }
  return result;
}

// 0x1707040
s32 nbGetEncountMax(s32 id) {
    ChkLength(0);
    nbGetEncountJoken(0);
    Get(0);
    dds3GetRandIntA(0, 0);
    return 0;
}

// 0x1707af0
void nbResetEncountCount(void) {
  DDS3_GBWK->encountkyori = 0.0;
  DDS3_GBWK->encountcnt = 0;
  encmax = 0;
}
