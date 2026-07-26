#include "types.h"

typedef struct effPCPHama02_tag effPCPHama02_tag;
typedef struct effPartHandle_t effPartHandle_t;

struct effPCPHama02_tag {
    sdfVector4_t pos;
    u32 abgr;
    f32 scale;
    f32 h_add[8];
    effPartHandle_t *hPart[8];
    u32 interval[8];
};

// 0x1157580
void Clear(effPCPHama02_tag *this) {
  struct effPartHandle_t_array_array *v3;
  struct effPartHandle_t_array_array *v4;
  s64 *v5;
  s64 *v6;
  struct effPartHandle_t_array_array *hPart;
  s64 *v9;
  s64 *v10;
  struct effPartHandle_t_array_array *v12;
  s64 *v13;
  s64 *v14;
  struct effPartHandle_t_array_array *v16;
  s64 *v17;
  s64 *v18;
  struct effPartHandle_t_array_array *v20;
  s64 *v21;
  s64 *v22;
  struct effPartHandle_t_array_array *v24;
  s64 *v25;
  s64 *v26;
  struct effPartHandle_t_array_array *v28;
  s64 *v29;
  s64 *v30;
  struct effPartHandle_t_array_array *v32;
  s64 *v33;
  s64 *v34;

  this->h_add = NewSpecific(f32, 8u);
  v3 = NewSpecific(effPartHandle_t__, 8u);
  this->hPart = v3;
  v4 = v3;
  v5 = NewSpecific(effPartHandle_t, 2u);
  v6 = v5;
  v4->m_Items[0] = v6;
  hPart = this->hPart;
  v9 = NewSpecific(effPartHandle_t, 2u);
  v10 = v9;
  hPart->m_Items[1] = v10;
  v12 = this->hPart;
  v13 = NewSpecific(effPartHandle_t, 2u);
  v14 = v13;
  v12->m_Items[2] = v14;
  v16 = this->hPart;
  v17 = NewSpecific(effPartHandle_t, 2u);
  v18 = v17;
  v16->m_Items[3] = v18;
  v20 = this->hPart;
  v21 = NewSpecific(effPartHandle_t, 2u);
  v22 = v21;
  v20->m_Items[4] = v22;
  v24 = this->hPart;
  v25 = NewSpecific(effPartHandle_t, 2u);
  v26 = v25;
  v24->m_Items[5] = v26;
  v28 = this->hPart;
  v29 = NewSpecific(effPartHandle_t, 2u);
  v30 = v29;
  v28->m_Items[6] = v30;
  v32 = this->hPart;
  v33 = NewSpecific(effPartHandle_t, 2u);
  v34 = v33;
  v32->m_Items[7] = v34;
  this->interval = NewSpecific(uint, 8u);
}
