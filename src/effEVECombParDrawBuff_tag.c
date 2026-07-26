#include "types.h"

typedef struct effEVECombParDrawBuff_tag effEVECombParDrawBuff_tag;

struct effEVECombParDrawBuff_tag {
    sdfVector4_t pos[32];
    u32 abgr[32];
    u16 **uv[32];
    f32 **xy[32];
    s32 number;
};

// 0x138a780
void Clear(effEVECombParDrawBuff_tag *this) {
  s64 v3;
  struct UnityEngine_Vector4_array *pos;
  u64 v5;
  u64 *v7;
  struct System_UInt16_array_array_array *v8;
  u32 *v9;
  u64 i;
  s64 *v11;
  s64 *v12;
  struct System_UInt16_array_array_array *uv;
  System_UInt16_array_array *v16;
  s64 *v17;
  s64 *v18;
  struct System_UInt16_array_array_array *v20;
  System_UInt16_array_array *v22;
  s64 *v23;
  s64 *v24;
  struct System_UInt16_array_array_array *v26;
  System_UInt16_array_array *v28;
  s64 *v29;
  s64 *v30;
  struct System_UInt16_array_array_array *v32;
  System_UInt16_array_array *v34;
  s64 *v35;
  s64 *v36;
  struct System_Single_array_array_array *v43;
  u32 *v44;
  u64 j;
  s64 *v46;
  s64 *v47;
  struct System_Single_array_array_array *xy;
  System_Single_array_array *v51;
  s64 *v52;
  s64 *v53;
  struct System_Single_array_array_array *v55;
  System_Single_array_array *v57;
  s64 *v58;
  s64 *v59;
  struct System_Single_array_array_array *v61;
  System_Single_array_array *v63;
  s64 *v64;
  s64 *v65;
  struct System_Single_array_array_array *v67;
  System_Single_array_array *v69;
  s64 *v70;
  s64 *v71;

  v3 = 32;
  pos = NewSpecific(UnityEngine_Vector4, 0x20u);
  v5 = 0;
  this->pos = pos;
  while (1)
  {
    v7 = (&pos->obj.klass + v3);
    *v7 = 0;
    v7[1] = 0;
    if (v5 == 31)
      break;
    pos = this->pos;
    ++v5;
    v3 += 16;
    if (v5 >= LODWORD(pos->max_length))
  }
  this->abgr = NewSpecific(uint, 0x20u);
  v8 = NewSpecific(ushort____, 0x20u);
  this->uv = v8;
  v9 = v8;
  for (i = 0; ; ++i)
  {
    v11 = NewSpecific(ushort__, 4u);
    v12 = v11;
    *&v9[2 * i + 8] = v12;
    uv = this->uv;
    v16 = uv->m_Items[i];
    v17 = NewSpecific(ushort, 2u);
    v18 = v17;
    v16->m_Items[0] = v18;
    v20 = this->uv;
    v22 = v20->m_Items[i];
    v23 = NewSpecific(ushort, 2u);
    v24 = v23;
    v22->m_Items[1] = v24;
    v26 = this->uv;
    v28 = v26->m_Items[i];
    v29 = NewSpecific(ushort, 2u);
    v30 = v29;
    v28->m_Items[2] = v30;
    v32 = this->uv;
    v34 = v32->m_Items[i];
    v35 = NewSpecific(ushort, 2u);
    v36 = v35;
    v34->m_Items[3] = v36;
    if (i == 31)
      break;
    v9 = this->uv;
  }
  v43 = NewSpecific(float____, 0x20u);
  this->xy = v43;
  v44 = v43;
  for (j = 0; ; ++j)
  {
    v46 = NewSpecific(float__, 4u);
    v47 = v46;
    *&v44[2 * j + 8] = v47;
    xy = this->xy;
    v51 = xy->m_Items[j];
    v52 = NewSpecific(f32, 2u);
    v53 = v52;
    v51->m_Items[0] = v53;
    v55 = this->xy;
    v57 = v55->m_Items[j];
    v58 = NewSpecific(f32, 2u);
    v59 = v58;
    v57->m_Items[1] = v59;
    v61 = this->xy;
    v63 = v61->m_Items[j];
    v64 = NewSpecific(f32, 2u);
    v65 = v64;
    v63->m_Items[2] = v65;
    v67 = this->xy;
    v69 = v67->m_Items[j];
    v70 = NewSpecific(f32, 2u);
    v71 = v70;
    v69->m_Items[3] = v71;
    if (j == 31)
      break;
    v44 = this->xy;
  }
}
