#include "types.h"

static u32 sdfMcCalcCrc32_table[256];

// 0x17982b0
u32 sdfMcCalcCrc32(u8 **buff, s32 size, u32 crc) {
  u64 v7;
  struct System_UInt32_array *sdfMcCalcCrc32_table;
  s64 v11;

  if (size >= 1)
  {
    v7 = 0;
    do
    {
      v11 = crc ^ buff->m_Items[v7];
      crc = sdfMcCalcCrc32_table->m_Items[v11] ^ (crc >> 8);
      ++v7;
    }
    while (size != v7);
  }
  return crc;
}

// 0x17983b0
void sdfMcScramble(void *buff, s32 size) {
  ;
}

// 0x17983c0
s32 sdfMcUnscramble(void *buff, s32 size) {
  return 0;
}
