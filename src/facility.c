#include "types.h"

typedef struct fclEncycRecord_t fclEncycRecord_t;
typedef struct fclencyceelem_t fclencyceelem_t;

void fclencyceelem_t__Clear(fclencyceelem_t *this);
void fclencyceelem_t__Copy(fclencyceelem_t *this, fclencyceelem_t *data);

// 0x195d140
s32 FACILITY__FCL_BLEND_ALPHA(s64 src, s64 dst) {
  return ((dst * src) >> 7) | src & 0xFFFFFF00;
}

// 0x1960700
void fclEncycRecord_t__Clear(fclEncycRecord_t *this) {
  struct fclencyceelem_t_array *v3;
  u32 *v4;
  s64 i;
  u64 v6;
  u64 *v7;
  struct fclencyceelem_t_array *pelem;

  *&this->num = 0;
  *&this->reserved1 = 0;
  v3 = NewSpecific(fclencyceelem_t, 0xB9u);
  this->pelem = v3;
  v4 = v3;
  for (i = 4; ; ++i)
  {
    v6 = i - 4;
    v7 = Allocate(fclencyceelem_t);
    _ctor(v7, 0);
    *&v4[2 * i] = v7;
    pelem = this->pelem;
    fclencyceelem_t__Clear(*(&pelem->obj.klass + i));
    if (i == 188)
      break;
    v4 = this->pelem;
  }
}

// 0x1960920
void fclEncycRecord_t__Copy(fclEncycRecord_t *this, fclEncycRecord_t *data) {
  struct fclencyceelem_t_array *v5;
  u32 *v6;
  s64 i;
  u64 v8;
  u64 *v9;
  struct fclencyceelem_t_array *pelem;
  struct fclencyceelem_t_array *v14;
  fclencyceelem_t_o *v15;

  this->num = data->num;
  this->reserved0 = data->reserved0;
  this->reserved1 = data->reserved1;
  this->reserved2 = data->reserved2;
  v5 = NewSpecific(fclencyceelem_t, 0xB9u);
  this->pelem = v5;
  v6 = v5;
  for (i = 4; ; ++i)
  {
    v8 = i - 4;
    v9 = Allocate(fclencyceelem_t);
    _ctor(v9, 0);
    *&v6[2 * i] = v9;
    pelem = this->pelem;
    v14 = data->pelem;
    v15 = *(&pelem->obj.klass + i);
    fclencyceelem_t__Copy(v15, *(&v14->obj.klass + i));
    if (i == 188)
      break;
    v6 = this->pelem;
  }
}

// 0x1960840
void fclencyceelem_t__Clear(fclencyceelem_t *this) {
  struct System_Byte_array *v3;

  *&this->maxmp = 0;
  *&this->id = 0;
  this->param = NewSpecific(sbyte, 6u);
  this->skillparam = NewSpecific(sbyte, 6u);
  this->skillcnt = 0;
  this->skill = NewSpecific(ushort, 0x18u);
  this->mitamaparam = NewSpecific(sbyte, 6u);
  this->levelupparam = NewSpecific(sbyte, 6u);
  this->keisyoskill = NewSpecific(ushort, 0x18u);
  v3 = NewSpecific(byte, 0x18u);
  *&this->hensinmae = 0;
  *&this->reserved2 = 0;
  this->keiattr = v3;
}

// 0x1960aa0
void fclencyceelem_t__Copy(fclencyceelem_t *this, fclencyceelem_t *data) {
}
