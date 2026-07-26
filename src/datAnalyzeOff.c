#include "types.h"

static u8 tbl[384];

// 0x16371c0
u8 Get(s32 id) {
  s32 v4;
  struct System_Byte_array *tbl;

  v4 = convDLCDevilNumber(id);
  return tbl->m_Items[v4];
}
