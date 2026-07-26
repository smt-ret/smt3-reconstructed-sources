#include "types.h"

typedef struct _RING_BUF _RING_BUF;
typedef struct _TEXT _TEXT;

static _RING_BUF *ring_bufs[2];

void release_ringbufs(s32 index);

// 0x1557fc0
void Initialize(void) {
  struct _RING_BUF_array_array *ring_bufs;
  struct _RING_BUF_array_array *v4;

  ring_bufs = NewSpecific(_RING_BUF__, 2u);
  ring_bufs->m_Items[0] = 0;
  v4 = ring_bufs;
  v4->m_Items[1] = 0;
}

// 0x1558540
s32 rbDestroyRingBuf(s32 index, _RING_BUF *pRingBuf) {
  release_ringbufs(index, pRingBuf);
  return 1;
}

// 0x1558080
_RING_BUF *rbInitRingBuf(s32 index, s32 Nums) {
  struct _RING_BUF_array_array *ring_bufs;
  struct _RING_BUF_array_array *v7;
  s64 *v8;
  s64 *v9;
  u64 v11;
  struct _RING_BUF_array_array *v13;
  u32 *v15;
  u64 *v16;
  struct _RING_BUF_array_array *v18;
  _RING_BUF_array *v20;
  struct _RING_BUF_array_array *v22;
  _RING_BUF_array *v24;
  Il2CppClass **v26;
  u64 i;
  Il2CppClass **v28;
  struct _RING_BUF_array_array *v29;
  _RING_BUF_array *v31;
  _RING_BUF_o *v33;
  struct _RING_BUF_array_array *v34;
  _RING_BUF_array *v36;
  _RING_BUF_o *v38;
  struct _RING_BUF_array_array *v39;
  _RING_BUF_array *v41;
  struct _RING_BUF_array_array *v43;
  _RING_BUF_array *v45;
  _RING_BUF_o *v47;
  struct _RING_BUF_array_array *v48;
  _RING_BUF_array *v50;
  struct _RING_BUF_array_array *v52;
  _RING_BUF_array *v54;

  if (ring_bufs->m_Items[index])
    release_ringbufs(index, *&Nums);
  v7 = ring_bufs;
  v8 = NewSpecific(_RING_BUF, (Nums + 1));
  v9 = v8;
  v7->m_Items[index] = v9;
  if ((Nums & 0x80000000) == 0)
  {
    v11 = 0;
    do
    {
      v13 = ring_bufs;
      v15 = v13->m_Items[index];
      v16 = Allocate(_RING_BUF);
      _RING_BUF___ctor(v16);
      *&v15[2 * v11 + 8] = v16;
      v18 = ring_bufs;
      v20 = v18->m_Items[index];
      v20->m_Items[v11]->ID = v11;
      v22 = ring_bufs;
      v24 = v22->m_Items[index];
      v26 = &v24->obj.klass + v11++;
      v26[4]->_1.byval_arg.data = 0;
    }
    while (Nums + 1 != v11);
  }
  for (i = 0; ; ++i)
  {
    v29 = ring_bufs;
    v31 = v29->m_Items[index];
    v33 = v31->m_Items[i];
    if (i >= Nums)
      break;
    v33->ID = i;
    v34 = ring_bufs;
    v36 = v34->m_Items[index];
    v38 = v36->m_Items[i];
    v39 = ring_bufs;
    v41 = v39->m_Items[index];
    v28 = &v41->obj.klass + i;
    v38->Next = v28[5];
  }
  v33->ID = Nums;
  v43 = ring_bufs;
  v45 = v43->m_Items[index];
  v47 = v45->m_Items[i];
  v48 = ring_bufs;
  v50 = v48->m_Items[index];
  v47->Next = v50->m_Items[1];
  v52 = ring_bufs;
  v54 = v52->m_Items[index];
  return v54->m_Items[1];
}

// 0x69380
_TEXT *rbRentFromRingBuf__TEXT_(_RING_BUF *pRingBuf) {
    return 0;
}

// 0xf0d70
s32 rbRetToRingBuf__TEXT_(s32 index, _TEXT *pBuf, _RING_BUF *pRingBuf) {
    return 0;
}

// 0x1557eb0
void release_ringbufs(s32 index) {
  struct rbRingBuf_StaticFields *static_fields;
  struct _RING_BUF_array_array *ring_bufs;
  s32 max_length;
  bool v6;
  u64 v7;
  _RING_BUF_array *v9;
  s64 v11;
  struct rbRingBuf_StaticFields *v12;
  il2cpp_array_size_t v13;

  static_fields = rbRingBuf->static_fields;
  ring_bufs = static_fields->ring_bufs;
  max_length = static_fields->ring_bufs->max_length;
  v6 = max_length > index;
  if (max_length >= 1)
  {
    v7 = 0;
    do
    {
      v9 = ring_bufs->m_Items[index];
      v11 = v9 + 8 * v7++;
      *(*(v11 + 32) + 32LL) = 0;
      v12 = rbRingBuf->static_fields;
      ring_bufs = v12->ring_bufs;
      v13 = v12->ring_bufs->max_length;
      v6 = v13 > index;
    }
    while (v7 < v13);
  }
  ring_bufs->m_Items[index] = 0;
}
