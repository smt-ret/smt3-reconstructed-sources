#include "types.h"

typedef struct warp_elvtbl_s warp_elvtbl_s;

struct warp_elvtbl_s {
    s32 area;
    s16 se;
    s16 floormax;
    s16 floor[6];
    s16 sblock[6];
};

// 0x18a3bd0
s32 Byte2Int(warp_elvtbl_s *this, u8 **data, s32 pos) {
  u32 max_length;
  s64 v8;

  max_length = data->max_length;
  v8 = pos + 3LL;
  return data->m_Items[pos]
       | (data->m_Items[pos + 1] << 8)
       | (data->m_Items[pos + 2] << 16) & 0xFFFFFF
       | (data->m_Items[v8] << 24);
}

// 0x18a3cb0
s16 Byte2Short(warp_elvtbl_s *this, u8 **data, s32 pos) {
  u32 max_length;
  s64 v6;

  max_length = data->max_length;
  v6 = pos + 1LL;
  return data->m_Items[pos] | (data->m_Items[v6] << 8);
}

// 0x18a3d30
s32 Byte2String(warp_elvtbl_s *this, s16 ***buff, u8 **data, s32 pos, s32 size) {
  s32 v6;
  u64 v7;
  s64 v8;
  u32 max_length;
  System_Int16_array *v10;

  v6 = pos;
  if (size >= 1)
  {
    v7 = 0;
    v8 = 32;
    do
    {
      max_length = data->max_length;
      v10 = *buff;
      ++v7;
      *(&v10->obj.klass + v8) = *(&data->obj.klass + pos + v8) | (*(&data->obj.klass + pos + v8 + 1) << 8);
      v8 += 2;
    }
    while (size != v7);
    return pos + v8 - 32;
  }
  return v6;
}

// 0x18a3e30
s32 SetCopy(warp_elvtbl_s *this, u8 **data, s32 pos) {
  s16 v7;
  struct System_Int16_array *floor;
  s32 v10;
  il2cpp_array_size_t *p_max_length;
  u64 v12;
  s16 v13;
  char *v15;
  struct System_Int16_array *sblock;
  il2cpp_array_size_t *v17;
  u64 v18;
  s16 v19;
  char *v21;

  this->area = ToInt32(data, pos, 0);
  this->se = ToInt16(data, pos + 4, 0);
  v7 = ToInt16(data, pos + 6, 0);
  floor = this->floor;
  this->floormax = v7;
  v10 = pos + 8;
  p_max_length = &floor->max_length;
  if (SLODWORD(floor->max_length) >= 1)
  {
    v12 = 0;
    do
    {
      v13 = ToInt16(data, v10, 0);
      v15 = floor + 2 * v12++;
      *(v15 + 16) = v13;
      floor = this->floor;
      v10 += 2;
      p_max_length = &floor->max_length;
    }
    while (v12 < SLODWORD(floor->max_length));
  }
  sblock = this->sblock;
  v17 = &sblock->max_length;
  if (SLODWORD(sblock->max_length) >= 1)
  {
    v18 = 0;
    do
    {
      v19 = ToInt16(data, v10, 0);
      v21 = sblock + 2 * v18++;
      *(v21 + 16) = v19;
      sblock = this->sblock;
      v10 += 2;
      v17 = &sblock->max_length;
    }
    while (v18 < SLODWORD(sblock->max_length));
  }
  return v10;
}
