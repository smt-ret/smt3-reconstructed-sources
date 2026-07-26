#include "types.h"

typedef struct nbTarSelProcessData_t nbTarSelProcessData_t;

s32 CheckEnemy(nbTarSelProcessData_t **t, s32 formindex);
void evtDisableMoonCalc(void);
void evtDisableMoonDraw(void);
void evtSetAgeOfMoon(s32 age);

// 0xfe6e70
void evtBitAllOff(void) {
  u64 i;
  struct System_Int32_array *EventBit;
  char *v6;

  for (i = 0; i != 128; ++i)
  {
    EventBit = DDS3_GBWK->EventBit;
    v6 = EventBit + 4 * i;
    *(v6 + 8) = 0;
  }
}

// 0xfe6f20
void evtBitAllOff_FieldDebug(void) {
  u32 i;
  struct System_Int32_array *EventBit;
  s64 v5;
  s32 v7;
  u32 j;
  struct System_Int32_array *v10;
  s64 v11;
  s32 v13;

  for (i = 0; i != 3072; ++i)
  {
    EventBit = DDS3_GBWK->EventBit;
    v5 = i >> 5;
    v7 = 1 << i;
    EventBit->m_Items[v5] &= ~v7;
  }
  for (j = 3328; j != 4096; ++j)
  {
    v10 = DDS3_GBWK->EventBit;
    v11 = j >> 5;
    v13 = 1 << j;
    v10->m_Items[v11] &= ~v13;
  }
}

// 0xfe71f0
bool evtBitCheck(s32 no) {
  s32 v2;
  struct System_Int32_array *EventBit;

  if (no == 1871)
    return 0;
  if ((no & 0xFFFFFF00) == 0x100)
  {
    CheckEnemy(no, 0);
  }
  EventBit = DDS3_GBWK->EventBit;
  return (EventBit->m_Items[v2 >> 5] & (1 << no)) != 0;
}

// 0xfe7070
void evtBitOff(s32 no) {
  s32 v2;
  struct System_Int32_array *EventBit;

  EventBit = DDS3_GBWK->EventBit;
  EventBit->m_Items[v2 >> 5] &= ~(1 << no);
}

// 0xfe7130
void evtBitOn(s32 no) {
  s32 v2;
  struct System_Int32_array *EventBit;

  EventBit = DDS3_GBWK->EventBit;
  EventBit->m_Items[v2 >> 5] |= 1 << no;
}

// 0xfe6d60
void evtInitGlobalWork(void) {
  u64 i;
  struct System_Int32_array *EventBit;
  char *v6;

  for (i = 0; i != 128; ++i)
  {
    EventBit = DDS3_GBWK->EventBit;
    v6 = EventBit + 4 * i;
    *(v6 + 8) = 0;
  }
  evtSetAgeOfMoon(0);
  evtDisableMoonDraw();
  evtDisableMoonCalc();
}
