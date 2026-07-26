#include "types.h"

static u32 SEARCH_CODE_TMX;
static u32 SEARCH_CODE_PIB;
static u32 SEARCH_CODE_END;

s32 GetIndex(u32 pac_magic_code, u8 **bData, s32 bPos);
void MarkIndex(u32 pac_magic_code, u8 **bData, u8 mark);

// 0x17a53e0
s32 GetIndex(u32 pac_magic_code, u8 **bData, s32 bPos) {
  u32 v7;
  s32 v8;
  u8 *i;

  v7 = (bPos + 15) & 0xFFFFFFF0;
  v8 = v7 | 8;
  if ((v7 | 8) >= SLODWORD(bData->max_length))
    return 0;
  for (i = &bData->m_Items[v7 + 15]; ; i += 16)
  {
    if (ToUInt32(bData, v8, 0) == pac_magic_code)
      break;
    v8 += 16;
    if (v8 >= SLODWORD(bData->max_length))
      return 0;
  }
  if (v8 < 8)
    return 0;
  return *i;
}

// 0x17a5880
s32 GetNextPos(u8 **bData, s32 bPos) {
  return (bPos + 63 - (bPos & 0x3F) + ToInt32(bData, bPos + 4, 0)) & 0xFFFFFFC0 | bPos & 0x3F;
}

// 0x17a5630
u8 **GetPibArray(u8 **bData, s32 bPos) {
  u32 SEARCH_CODE_PIB;
  s32 v7;
  s32 v8;
  u32 v9;
  u32 max_length;
  u64 *v13;

  v7 = (bPos + 15) & 0xFFFFFFF0;
  if ((v7 | 8) < SLODWORD(bData->max_length))
  {
    while (1)
    {
      if (ToUInt32(bData, v7 + 8, 0) == SEARCH_CODE_PIB)
        break;
      v8 = v7 + 24;
      v7 += 16;
      if (v8 >= SLODWORD(bData->max_length))
        return 0;
    }
    if ((v7 & 0x80000000) == 0)
    {
      v9 = 0;
      max_length = v7;
      {
        do
        {
          max_length = (max_length + 63 - (max_length & 0x3F) + ToInt32(bData, max_length + 4, 0))
                     & 0xFFFFFFC0
                     | max_length & 0x3F;
          if (v9 == SEARCH_CODE_END)
          {
            v13 = NewSpecific(byte, max_length - v7);
            Copy_3880080(bData, v7, v13, 0, *(v13 + 6), 0);
            return v13;
          }
          if ((max_length & 0x80000000) != 0)
          {
            max_length = bData->max_length;
          }
          v9 = ToUInt32(bData, max_length + 8, 0);
        }
      }
      if ((byte_3F5A759 & 1) == 0)
    }
  }
  return 0;
}

// 0x17a55b0
s32 GetPibIndex(u8 **bData, s32 bPos) {
  return GetIndex(SEARCH_CODE_PIB, bData, bPos);
}

// 0x17a5360
s32 GetTmxIndex(u8 **bData, s32 bPos) {
  return GetIndex(SEARCH_CODE_TMX, bData, bPos);
}

// 0x17a5060
void MarkIndex(u32 pac_magic_code, u8 **bData, u8 mark) {
  s32 v6;
  s32 v7;
  s32 v9;
  s32 v10;
  u64 v11;
  s64 v12;
  u32 v13;
  u32 i;
  s32 v15;
  u32 v16;
  s32 v20;
  s32 v21;
  u8 *v22;

  v22 = &bData->m_Items[14];
  v6 = 0;
  v7 = 0;
  v21 = v7;
  while (1)
  {
    v9 = v6 + 15;
    v10 = v6;
    v11 = (v6 + 15) & 0xFFFFFFFFFFFFFFF0LL;
    if ((v11 | 8) >= SLODWORD(bData->max_length))
      break;
    v12 = 0;
    v13 = v9 & 0xFFFFFFF0;
    for (i = v11; ; i += 16)
    {
      if (ToUInt32(bData, v13 + v12 + 8, 0) == pac_magic_code)
        break;
      v12 += 16;
      if ((v13 + v12 + 8) >= SLODWORD(bData->max_length))
        return;
    }
    v15 = ((v10 + 15) & 0xFFFFFFF0) + v12;
    if (v15 < 0)
      break;
    v16 = ((v10 + 15) & 0xFFFFFFF0) + v12 + 14;
    if (v22[v11 + v12] == mark)
      break;
    v22[v11 + v12] = mark;
    v22[v11 + 1 + v12] = v21;
    if ((byte_3F5A759 & 1) == 0)
    v7 = v21 + 1;
    v20 = v15 & 0x38;
    v6 = (ToInt32(bData, ((v10 + 15) & 0xFFFFFFF0) + v12 + 4, 0)
        + v11
        + 56
        - 8 * ((i >> 3) & 7)
        + v12
        + 7)
       & 0xFFFFFFC0
       | v20;
    v21 = v7;
    if ((byte_3F5A75A & 1) == 0)
  }
}

// 0x17a5530
void MarkPibIndex(u8 ***bData) {
  MarkIndex(SEARCH_CODE_PIB, *bData, 0x25u);
}

// 0x17a4fe0
void MarkTmxIndex(u8 ***bData) {
  MarkIndex(SEARCH_CODE_TMX, *bData, 0x24u);
}

// 0x179fd30
u32 SDF_FOURCC(s32 a, s32 b, s32 c, s32 d) {
  return a | (b << 8) | (c << 16) & 0xFFFFFF | (d << 24);
}

// 0x179e420
s32 SearchCode(u32 pac_magic_code, u8 **bData, s32 bPos) {
  s32 v7;
  s32 v8;

  v7 = (bPos + 15) & 0xFFFFFFF0;
  if ((v7 | 8) >= SLODWORD(bData->max_length))
    return -1;
  while (1)
  {
    if (ToUInt32(bData, v7 + 8, 0) == pac_magic_code)
      break;
    v8 = v7 + 24;
    v7 += 16;
    if (v8 >= SLODWORD(bData->max_length))
      return -1;
  }
  return v7;
}
