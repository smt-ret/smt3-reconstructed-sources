#include "types.h"

typedef struct doormovetbl_s doormovetbl_s;
typedef struct fldwarp_s fldwarp_s;
typedef struct warp_elvtbl_s warp_elvtbl_s;

struct fldwarp_s {
    warp_elvtbl_s *elvtbl[5];
    doormovetbl_s *door_buff[256];
};

s32 SetCopy(warp_elvtbl_s *this, u8 **data, s32 pos);

// 0x1398380
void SetCopy(fldwarp_s *this, u8 **data, s32 pos) {
  struct warp_elvtbl_s_array *elvtbl;
  il2cpp_array_size_t max_length;
  u64 v9;
  s32 v11;
  struct doormovetbl_s_array *door_buff;
  il2cpp_array_size_t v13;
  u64 v14;
  s32 v16;

  elvtbl = this->elvtbl;
  max_length = elvtbl->max_length;
  if (max_length >= 1)
  {
    v9 = 0;
    do
    {
      v11 = SetCopy(elvtbl->m_Items[v9], data, pos, 0);
      elvtbl = this->elvtbl;
      LODWORD(max_length) = elvtbl->max_length;
      ++v9;
      pos = v11;
    }
    while (v9 < max_length);
  }
  door_buff = this->door_buff;
  v13 = door_buff->max_length;
  if (v13 >= 1)
  {
    v14 = 0;
    do
    {
      v16 = SetCopy(door_buff->m_Items[v14], data, pos, 0);
      door_buff = this->door_buff;
      LODWORD(v13) = door_buff->max_length;
      ++v14;
      pos = v16;
    }
    while (v14 < v13);
  }
}
