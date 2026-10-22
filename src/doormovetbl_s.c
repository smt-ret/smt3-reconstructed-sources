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
  doormovetbl_s_o *v4;
  u32 max_length;
  u32 v10;
  s64 v12;
  s16 v14;
  s64 v15;
  u64 v16;
  u8 *v17;
  u64 v18;
  char v19;
  doormovetbl_s_o *v21;
  struct System_Char_array *union02;
  s16 v23;
  char *v25;
  u32 v26;
  u32 v29;
  u32 v32;
  s64 v35;
  u64 v36;
  char v37;
  u8 *v38;
  struct System_Char_array *union06;
  s16 v41;
  s64 v43;
  s32 v44;
  s64 v45;
  u64 v46;
  u64 v47;
  char v48;
  u8 *v49;
  struct System_Char_array *union07;
  s16 v52;
  char *v54;
  s32 v56;
  u32 v58;
  u32 v61;
  u32 v64;
  u8 v66;
  s16 v68;
  s64 v69;
  u64 v70;
  u64 v71;
  char v72;
  u8 *v73;
  struct System_Char_array *warp_pos;
  s16 v76;
  s64 v78;
  s32 v80;
  s64 v82;
  u64 v83;
  char v84;
  u64 v85;
  u8 *v86;
  struct System_Char_array *warp_camname;
  s16 v89;
  s64 v91;
  u16 v95;
  s64 v96;
  u64 v97;
  char v98;
  u8 *v99;
  struct System_Char_array *after_scr;
  s16 v102;
  s64 v104;

  v4 = this;
  this->movetype = data->m_Items[pos];
  this->flagmode = data->m_Items[pos + 1];
  max_length = data->max_length;
  this->flag = data->m_Items[pos + 2] | (data->m_Items[pos + 3] << 8);
  v10 = data->max_length;
  v12 = pos + 5LL;
  v14 = data->m_Items[v12];
  v15 = pos + 6;
  v16 = 0xFFFFFFFF00000000LL * v15;
  v17 = &data->m_Items[v15];
  v18 = 0;
  v19 = 0;
  this->union01 = data->m_Items[pos + 4] | (v14 << 8);
  do
  {
    v21 = v4;
    union02 = v4->union02;
    if (!v17[v18])
      v19 = 1;
    if (v19 == 1)
      v23 = 0;
    else
      v23 = v17[v18];
    v25 = union02 + 2 * v18++;
    v16 -= 0x100000000LL;
    v4 = v21;
    *(v25 + 16) = v23;
  }
  while (v18 != 12);
  v26 = data->max_length;
  v21->union03 = data->m_Items[-v16 >> 32] | (data->m_Items[pos + 19] << 8);
  v29 = data->max_length;
  v21->union04 = data->m_Items[pos + 20] | (data->m_Items[pos + 21] << 8);
  v32 = data->max_length;
  v35 = (0x600000000LL - v16) >> 32;
  v36 = 0;
  v37 = 0;
  v21->union05 = data->m_Items[pos + 22] | (data->m_Items[pos + 23] << 8);
  v38 = &data->m_Items[v35];
  do
  {
    union06 = v21->union06;
    if (!v38[v36])
      v37 = 1;
    if (v37 == 1)
      v41 = 0;
    else
      v41 = v38[v36];
    v43 = union06 + 2 * v36++;
    *(v43 + 32) = v41;
  }
  while (v36 != 12);
  v44 = v35 + 12;
  v45 = v35 + 12;
  v46 = 0xFFFFFFFF00000000LL * v45;
  v47 = 0;
  v48 = 0;
  v49 = &data->m_Items[v45];
  do
  {
    union07 = v4->union07;
    if (!v49[v47])
      v48 = 1;
    if (v48 == 1)
      v52 = 0;
    else
      v52 = v49[v47];
    v54 = union07 + 2 * v47++;
    v4 = v21;
    *(v54 + 16) = v52;
    v46 -= 0x100000000LL;
  }
  while (v47 != 12);
  v21->warptype = data->m_Items[-v46 >> 32];
  v56 = v35 + 24;
  v21->warp_attr = data->m_Items[v44 + 13];
  v58 = data->max_length;
  v21->union08 = data->m_Items[v44 + 14] | (data->m_Items[v44 + 15] << 8);
  v61 = data->max_length;
  v21->union09 = data->m_Items[v44 + 16] | (data->m_Items[v44 + 17] << 8);
  v64 = data->max_length;
  v66 = data->m_Items[v44 + 18];
  v68 = data->m_Items[v56 + 7];
  v69 = (0x800000000LL - v46) >> 32;
  v70 = v46 - 0x800000000LL;
  v71 = 0;
  v72 = 0;
  v21->union10 = v66 | (v68 << 8);
  v73 = &data->m_Items[v69];
  do
  {
    warp_pos = v21->warp_pos;
    if (!v73[v71])
      v72 = 1;
    if (v72 == 1)
      v76 = 0;
    else
      v76 = v73[v71];
    v78 = warp_pos + 2 * v71++;
    v70 -= 0x100000000LL;
    *(v78 + 32) = v76;
  }
  while (v71 != 12);
  v21->warp_cammode = data->m_Items[-v70 >> 32];
  v80 = v69 + 13;
  v82 = (0x200000000LL - v70) >> 32;
  v83 = 0;
  v84 = 0;
  v85 = v70 - 0x200000000LL;
  v21->warp_camtbl = data->m_Items[v80];
  v86 = &data->m_Items[v82];
  do
  {
    warp_camname = v21->warp_camname;
    if (!v86[v83])
      v84 = 1;
    if (v84 == 1)
      v89 = 0;
    else
      v89 = v86[v83];
    v91 = warp_camname + 2 * v83++;
    v85 -= 0x100000000LL;
    *(v91 + 32) = v89;
  }
  while (v83 != 12);
  v21->warp_bgm = data->m_Items[-v85 >> 32];
  v21->warp_foot = data->m_Items[v82 + 13];
  v95 = data->m_Items[v82 + 14];
  v96 = (0x300000000LL - v85) >> 32;
  v97 = 0;
  v98 = 0;
  v99 = &data->m_Items[v96];
  v21->after_flag = v95;
  do
  {
    after_scr = v21->after_scr;
    if (!v99[v97])
      v98 = 1;
    if (v98 == 1)
      v102 = 0;
    else
      v102 = v99[v97];
    v104 = after_scr + 2 * v97++;
    *(v104 + 32) = v102;
  }
  while (v97 != 15);
  return v96 + 15;
}
