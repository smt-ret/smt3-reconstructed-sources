#include "types.h"

typedef struct FLD_INF_ALL_t FLD_INF_ALL_t;
typedef struct FLD_INF_EX_t FLD_INF_EX_t;
typedef struct FLD_INF_PACK_t FLD_INF_PACK_t;
typedef struct FLD_INF_SET_t FLD_INF_SET_t;
typedef struct FLD_INF_VIEW_t FLD_INF_VIEW_t;

struct FLD_INF_ALL_t {
    FLD_INF_PACK_t *pack[8];
    FLD_INF_VIEW_t *view[40];
    FLD_INF_EX_t *ex[40];
    FLD_INF_SET_t *set[40];
};

// 0xff0210
void SetCopy(FLD_INF_ALL_t *this, u8 **data) {
  struct FLD_INF_PACK_t_array *pack;
  u64 *v6;
  struct FLD_INF_PACK_t_array *v9;
  u64 *v10;
  struct FLD_INF_PACK_t_array *v13;
  u64 *v14;
  struct FLD_INF_PACK_t_array *v17;
  u64 *v18;
  struct FLD_INF_PACK_t_array *v21;
  u64 *v22;
  struct FLD_INF_PACK_t_array *v25;
  u64 *v26;
  struct FLD_INF_PACK_t_array *v29;
  u64 *v30;
  struct FLD_INF_PACK_t_array *v33;
  u64 *v34;
  u64 i;
  u32 *view;
  u64 *v40;
  u32 *v43;
  u64 j;
  u32 *ex;
  u64 *v47;
  u32 *v50;
  u64 k;
  u32 *set;
  u64 *v54;
  u32 *v57;
  s32 pos;

  pos = 0;
  pack = this->pack;
  v6 = Allocate(FLD_INF_PACK_t);
  _ctor(v6, data, &pos);
  pack->m_Items[0] = v6;
  v9 = this->pack;
  v10 = Allocate(FLD_INF_PACK_t);
  _ctor(v10, data, &pos);
  v9->m_Items[1] = v10;
  v13 = this->pack;
  v14 = Allocate(FLD_INF_PACK_t);
  _ctor(v14, data, &pos);
  v13->m_Items[2] = v14;
  v17 = this->pack;
  v18 = Allocate(FLD_INF_PACK_t);
  _ctor(v18, data, &pos);
  v17->m_Items[3] = v18;
  v21 = this->pack;
  v22 = Allocate(FLD_INF_PACK_t);
  _ctor(v22, data, &pos);
  v21->m_Items[4] = v22;
  v25 = this->pack;
  v26 = Allocate(FLD_INF_PACK_t);
  _ctor(v26, data, &pos);
  v25->m_Items[5] = v26;
  v29 = this->pack;
  v30 = Allocate(FLD_INF_PACK_t);
  _ctor(v30, data, &pos);
  v29->m_Items[6] = v30;
  v33 = this->pack;
  v34 = Allocate(FLD_INF_PACK_t);
  _ctor(v34, data, &pos);
  v33->m_Items[7] = v34;
  for (i = 0; i != 40; ++i)
  {
    view = this->view;
    v40 = Allocate(FLD_INF_VIEW_t);
    _ctor(v40, data, &pos);
    v43 = &view[2 * i];
    *(v43 + 4) = v40;
  }
  for (j = 0; j != 40; ++j)
  {
    ex = this->ex;
    v47 = Allocate(FLD_INF_EX_t);
    _ctor(v47, data, &pos);
    v50 = &ex[2 * j];
    *(v50 + 4) = v47;
  }
  for (k = 0; k != 40; ++k)
  {
    set = this->set;
    v54 = Allocate(FLD_INF_SET_t);
    _ctor(v54, data, &pos);
    v57 = &set[2 * k];
    *(v57 + 4) = v54;
  }
}
