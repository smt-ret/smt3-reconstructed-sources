#include "types.h"

static u16 tbl[384];

// 0x12c1720
u16 Get(s32 id) {
  s32 v4;
  struct System_UInt16_array *tbl;

  v4 = convDLCDevilNumber(id);
  return tbl->m_Items[v4];
}
