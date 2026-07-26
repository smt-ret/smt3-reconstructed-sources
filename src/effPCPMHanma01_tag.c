#include "types.h"

typedef struct effPCPMHanma01_tag effPCPMHanma01_tag;
typedef struct effPartHandle_t effPartHandle_t;

struct effPCPMHanma01_tag {
    sdfVector4_t pos;
    u32 abgr;
    f32 scale;
    effPartHandle_t *hPart[6];
    u32 interval[6];
};

// 0x1157cc0
void Clear(effPCPMHanma01_tag *this) {
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

  v3 = NewSpecific(effPartHandle_t__, 6u);
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
  this->interval = NewSpecific(uint, 6u);
}
