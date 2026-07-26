#include "types.h"

typedef struct doormovetbl_s doormovetbl_s;

struct doormovetbl_s {
    u16 movetype;
    u16 flagmode;
    s16 flag;
    s16 union01;
    u16 union02[12];
    s16 union03;
    s16 union04;
    s16 union05;
    u16 union06[12];
    u16 union07[12];
    u16 warptype;
    u16 warp_attr;
    s16 union08;
    s16 union09;
    s16 union10;
    u16 warp_pos[12];
    u16 warp_cammode;
    u16 warp_camtbl;
    u16 warp_camname[12];
    u16 warp_bgm;
    u16 warp_foot;
    u16 after_flag;
    u16 after_scr[15];
};

// 0x1810800
s32 Byte2Int(doormovetbl_s *this, u8 **data, s32 pos) {
  u32 max_length;
  s64 v8;

  max_length = data->max_length;
  v8 = pos + 3LL;
  return data->m_Items[pos]
       | (data->m_Items[pos + 1] << 8)
       | (data->m_Items[pos + 2] << 16) & 0xFFFFFF
       | (data->m_Items[v8] << 24);
}

// 0x18108e0
s16 Byte2Short(doormovetbl_s *this, u8 **data, s32 pos) {
  u32 max_length;
  s64 v6;

  max_length = data->max_length;
  v6 = pos + 1LL;
  return data->m_Items[pos] | (data->m_Items[v6] << 8);
}

// 0x1810960
s32 Byte2String(doormovetbl_s *this, u16 ***buff, u8 **data, s32 pos, s32 size) {
  s32 v6;
  u64 v7;
  System_Char_array *v8;
  s16 v10;
  char *v12;

  v6 = pos;
  if (size >= 1)
  {
    v7 = 0;
    do
    {
      v8 = *buff;
      v10 = data->m_Items[pos + v7];
      v12 = v8 + 2 * v7++;
      *(v12 + 16) = v10;
    }
    while (size != v7);
    return pos + v7;
  }
  return v6;
}

// 0x1810a20
s32 Byte2String2(doormovetbl_s *this, u16 ***buff, u8 **data, s32 pos, s32 size) {
  s32 v6;
  u64 v7;
  char v8;
  u8 *v9;
  System_Char_array *v11;
  s16 v12;
  char *v14;

  v6 = pos;
  if (size >= 1)
  {
    v7 = 0;
    v8 = 0;
    v9 = &data->m_Items[pos];
    do
    {
      v11 = *buff;
      if (!v9[v7])
        v8 = 1;
      if (v8 == 1)
        v12 = 0;
      else
        v12 = v9[v7];
      v14 = v11 + 2 * v7++;
      *(v14 + 16) = v12;
    }
    while (size != v7);
    return pos + v7;
  }
  return v6;
}

// 0x1810b00
s32 SetCopy(doormovetbl_s *this, u8 **data, s32 pos) {
    return 0;
}
