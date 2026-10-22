#include "types.h"

typedef struct pbBackup_t pbBackup_t;
typedef struct pbProcHandle_t pbProcHandle_t;
typedef struct pbWork_t pbWork_t;

u16 Byte2UInt16(u8 **bytedata, s32 pos);
u32 Byte2UInt32(u8 **bytedata, s32 pos);
void pbBackup_t__pCopy(pbBackup_t *this, u8 **bytedata, s32 *bpos);
f32 sdfSin(f32 aRadius);

// 0x14aaaf0
void pbBackup_t__pCopy(pbBackup_t *this, u8 **bytedata, s32 *bpos) {
  s32 v7;
  s64 v9;
  struct System_Byte_array *pchar_reg;
  u8 v12;
  s64 v14;
  struct System_Byte_array *v15;
  u8 v17;
  s64 v19;
  struct System_Byte_array *v20;
  u8 v22;
  s64 v24;
  struct System_Byte_array *v25;
  u64 v28;
  s32 v29;
  struct System_UInt16_array *pchar_pos;
  u16 v31;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;
  s32 v37;
  struct System_UInt16_array *v38;
  u16 v39;
  Il2CppArrayBounds *v40;
  il2cpp_array_size_t v42;
  u64 v44;
  struct System_UInt16_array *exit_pos;
  u16 v47;
  s32 v49;
  struct System_UInt16_array *v50;
  u16 v52;
  s32 v54;
  u64 v55;
  u64 v56;
  struct System_UInt16_array *mapdata;
  u16 v58;
  Il2CppArrayBounds *v59;
  il2cpp_array_size_t v61;
  u64 v63;
  s64 v64[2];
  s64 v65[2];

  v7 = *bpos;
  this->pchar_num = Byte2UInt32(bytedata, v7);
  *bpos += 4;
  this->pchar_reg = NewSpecific(byte, 4u);
  v65[0] = 4;
  v65[1] = 2;
  this->pchar_pos = sub_8DB0C0(ushort_, v65, 0);
  this->exit_pos = NewSpecific(ushort, 2u);
  v64[0] = 20;
  v64[1] = 20;
  this->mapdata = sub_8DB0C0(ushort_, v64, 0);
  v9 = *bpos;
  pchar_reg = this->pchar_reg;
  v12 = bytedata->m_Items[v9];
  pchar_reg->m_Items[0] = v12;
  v14 = *bpos + 1LL;
  *bpos = v14;
  v15 = this->pchar_reg;
  v17 = bytedata->m_Items[v14];
  v15->m_Items[1] = v17;
  v19 = *bpos + 1LL;
  *bpos = v19;
  v20 = this->pchar_reg;
  v22 = bytedata->m_Items[v19];
  v20->m_Items[2] = v22;
  v24 = *bpos + 1LL;
  *bpos = v24;
  v25 = this->pchar_reg;
  v25->m_Items[3] = bytedata->m_Items[v24];
  v28 = 0;
  v29 = *bpos + 1;
  *bpos = v29;
  do
  {
    pchar_pos = this->pchar_pos;
    v31 = Byte2UInt16(bytedata, v29);
    bounds = pchar_pos->bounds;
    length = bounds[1].length;
    pchar_pos->m_Items[length * v28] = v31;
    v37 = *bpos + 2;
    *bpos = v37;
    v38 = this->pchar_pos;
    v39 = Byte2UInt16(bytedata, v37);
    v40 = v38->bounds;
    v42 = v40[1].length;
    v44 = v42 * v28++;
    v38->m_Items[v44 + 1] = v39;
    v29 = *bpos + 2;
    *bpos = v29;
  }
  while (v28 != 4);
  exit_pos = this->exit_pos;
  v47 = Byte2UInt16(bytedata, v29);
  exit_pos->m_Items[0] = v47;
  v49 = *bpos + 2;
  *bpos = v49;
  v50 = this->exit_pos;
  v52 = Byte2UInt16(bytedata, v49);
  v50->m_Items[1] = v52;
  v54 = *bpos + 2;
  v55 = 0;
  v56 = 0;
  *bpos = v54;
  while (1)
  {
    do
    {
      mapdata = this->mapdata;
      v58 = Byte2UInt16(bytedata, v54);
      v59 = mapdata->bounds;
      v61 = v59[1].length;
      v63 = v55 + v61 * v56++;
      mapdata->m_Items[v63] = v58;
      v54 = *bpos + 2;
      *bpos = v54;
    }
    while (v56 != 20);
    if (++v55 == 20)
      break;
    v56 = 0;
  }
}

// 0x14b3bf0
void pbWork_t__pCopy(pbWork_t *this, u8 **bytedata, s32 *bpos) {
  u64 *v7;
  s32 v11;
  s32 v12;
  s64 v13;
  s64 v15;
  s32 v17;

  v7 = Allocate(pbBackup_t);
  pbBackup_t___ctor(v7);
  this->bup = v7;
  pbBackup_t__pCopy(v7, bytedata, bpos);
  this->etcTex = 0;
  this->helpTex = 0;
  this->blockTex = 0;
  this->bgTex = 0;
  v11 = *bpos;
  this->level = Byte2UInt16(bytedata, v11);
  v12 = *bpos + 2;
  *bpos = v12;
  this->stage = Byte2UInt16(bytedata, v12);
  v13 = *bpos + 2LL;
  *bpos = v13;
  this->debug_flag = bytedata->m_Items[v13];
  v15 = *bpos + 4LL;
  *bpos = v15;
  this->reserved0 = bytedata->m_Items[v15];
  v17 = *bpos + 4;
  *bpos = v17;
  this->reserved1 = Byte2UInt16(bytedata, v17);
  *bpos += 2;
}

// 0x14b1cc0
void pb_General__CLR_MAP_BLKDAT_(s32 x, s32 y) {
  struct System_UInt16_array *mapdata;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;
  char *v11;

  mapdata = pbWk->bup->mapdata;
  bounds = mapdata->bounds;
  length = bounds[1].length;
  v11 = mapdata + 2 * x + 2 * length * y;
  *(v11 + 16) &= 0x1800u;
}

// 0x149b640
u16 pb_General__GET_MAP_BLK_(s32 x, s32 y) {
  struct System_UInt16_array *mapdata;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;

  mapdata = pbWk->bup->mapdata;
  bounds = mapdata->bounds;
  length = bounds[1].length;
  return mapdata->m_Items[x + length * y] >> 13;
}

// 0x14b4170
s32 pb_General__GET_MAP_GOAL_(s32 x, s32 y) {
  struct System_UInt16_array *mapdata;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;

  mapdata = pbWk->bup->mapdata;
  bounds = mapdata->bounds;
  length = bounds[1].length;
  return mapdata->m_Items[x + length * y] & 0x1000;
}

// 0x149b720
u32 pb_General__GET_MAP_GRPID_(s32 x, s32 y) {
  struct System_UInt16_array *mapdata;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;

  mapdata = pbWk->bup->mapdata;
  bounds = mapdata->bounds;
  length = bounds[1].length;
  return mapdata->m_Items[x + length * y] & 0x7FF;
}

// 0x14b3f30
s32 pb_General__GET_MAP_HALL_(s32 x, s32 y) {
  struct System_UInt16_array *mapdata;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;

  mapdata = pbWk->bup->mapdata;
  bounds = mapdata->bounds;
  length = bounds[1].length;
  return mapdata->m_Items[x + length * y] & 0x800;
}

// 0x14b3db0
u32 pb_General__PB_FIXED_U(u32 u) {
  return 16 * u;
}

// 0x14b3dc0
u32 pb_General__PB_FIXED_V(u32 v) {
  return 16 * v;
}

// 0x14b3d90
u32 pb_General__PB_FIXED_X(u32 x) {
  return 16 * x;
}

// 0x14b3da0
u32 pb_General__PB_FIXED_Y(u32 y) {
  return 8 * y;
}

// 0x149ded0
f32 pb_General__PB_GET_RATIO(f32 f, f32 limit) {
  return sdfSin(f) * limit;
}

// 0x14b3d70
u32 pb_General__PB_MAIN(u32 a, u32 b) {
  if (a >= b)
    return b;
  return a;
}

// 0x14b3d80
u32 pb_General__PB_MAX(u32 a, u32 b) {
  if (a <= b)
    return b;
  return a;
}

// 0x149d5b0
s32 pb_General__PB_PROC_REF_MESS(pbProcHandle_t *p) {
  return p->mes >> 16;
}

// 0x14a5100
s32 pb_General__PB_PROC_REF_MESSID(pbProcHandle_t *p) {
  return LOWORD(p->mes);
}

// 0x149d5c0
void pb_General__PB_PROC_SEND_MESS(pbProcHandle_t *p, s32 mes) {
  if (p)
    p->mes = mes << 16;
}

// 0x14a6e70
void pb_General__PB_PROC_SEND_MESSID(pbProcHandle_t *p, s32 id) {
  if (p)
  {
    p->mes = id | 0x40000;
  }
}

// 0x149b800
void pb_General__SET_MAP_BLK_(s32 x, s32 y, s32 v) {
  s16 v4;
  struct System_UInt16_array *mapdata;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;
  s64 v12;
  struct System_UInt16_array *v14;
  Il2CppArrayBounds *v15;
  il2cpp_array_size_t v17;
  char *v19;

  v4 = v;
  mapdata = pbWk->bup->mapdata;
  bounds = mapdata->bounds;
  length = bounds[1].length;
  v12 = y;
  mapdata->m_Items[x + length * y] &= 0x1FFFu;
  v14 = pbWk->bup->mapdata;
  v15 = v14->bounds;
  v17 = v15[1].length;
  v19 = v14 + 2 * x + 2 * v17 * v12;
  *(v19 + 16) |= v4 << 13;
}

// 0x14b4250
void pb_General__SET_MAP_GOAL_(s32 x, s32 y, s32 v) {
  char v4;
  struct System_UInt16_array *mapdata;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;
  s64 v13;
  struct System_UInt16_array *v15;
  Il2CppArrayBounds *v16;
  il2cpp_array_size_t v18;
  char *v20;

  v4 = v;
  Log("Passing_start: ", 0);
  mapdata = pbWk->bup->mapdata;
  bounds = mapdata->bounds;
  length = bounds[1].length;
  v13 = y;
  mapdata->m_Items[x + length * y] &= ~0x1000u;
  v15 = pbWk->bup->mapdata;
  v16 = v15->bounds;
  v18 = v16[1].length;
  v20 = v15 + 2 * x + 2 * v18 * v13;
  *(v20 + 16) |= (v4 & 1) << 12;
}

// 0x14b3dd0
void pb_General__SET_MAP_GRPID_(s32 x, s32 y, s32 id) {
  s16 v4;
  struct System_UInt16_array *mapdata;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;
  s64 v12;
  struct System_UInt16_array *v14;
  Il2CppArrayBounds *v15;
  il2cpp_array_size_t v17;
  char *v19;

  v4 = id;
  mapdata = pbWk->bup->mapdata;
  bounds = mapdata->bounds;
  length = bounds[1].length;
  v12 = y;
  mapdata->m_Items[x + length * y] &= 0xF800u;
  v14 = pbWk->bup->mapdata;
  v15 = v14->bounds;
  v17 = v15[1].length;
  v19 = v14 + 2 * x + 2 * v17 * v12;
  *(v19 + 16) |= v4 & 0x7FF;
}

// 0x14b4010
void pb_General__SET_MAP_HALL_(s32 x, s32 y, s32 v) {
  char v4;
  struct System_UInt16_array *mapdata;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;
  s64 v12;
  struct System_UInt16_array *v14;
  Il2CppArrayBounds *v15;
  il2cpp_array_size_t v17;
  char *v19;

  v4 = v;
  mapdata = pbWk->bup->mapdata;
  bounds = mapdata->bounds;
  length = bounds[1].length;
  v12 = y;
  mapdata->m_Items[x + length * y] &= ~0x800u;
  v14 = pbWk->bup->mapdata;
  v15 = v14->bounds;
  v17 = v15[1].length;
  v19 = v14 + 2 * x + 2 * v17 * v12;
  *(v19 + 16) |= (v4 & 1) << 11;
}

// 0x14b44a0
u32 pb_MCARD__PB_GET_ENTRY_CLUSTER(u32 num) {
  return (num + 1) >> 1;
}

// 0x14b44b0
u32 pb_MCARD__PB_GET_FILE_CLUSTER(u32 size) {
  return (size + 1023) >> 10;
}
