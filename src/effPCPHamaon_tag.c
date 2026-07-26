#include "types.h"

typedef struct effPCPHamaon_tag effPCPHamaon_tag;
typedef struct effPartHandle_t effPartHandle_t;

struct effPCPHamaon_tag {
    sdfVector4_t pos;
    u32 abgr;
    f32 scale;
    effPartHandle_t *hPartHelper;
    effPartHandle_t *hPart[4];
    effPartHandle_t *hBillPart[12];
    u32 bill_frame[12];
    u32 *interval[4];
};

// 0x1157a00
void Clear(effPCPHamaon_tag *this) {
  u64 *v3;
  struct System_UInt32_array_array *v4;
  struct System_UInt32_array_array *v5;
  s64 *v6;
  s64 *v7;
  struct System_UInt32_array_array *interval;
  s64 *v10;
  s64 *v11;
  struct System_UInt32_array_array *v13;
  s64 *v14;
  s64 *v15;
  struct System_UInt32_array_array *v17;
  s64 *v18;
  s64 *v19;

  v3 = Allocate(effPartHandle_t);
  effPartHandle_t___ctor(v3);
  this->hPartHelper = v3;
  this->hPart = NewSpecific(effPartHandle_t__, 4u);
  this->hBillPart = NewSpecific(effPartHandle_t, 0xCu);
  this->bill_frame = NewSpecific(uint, 0xCu);
  v4 = NewSpecific(uint__, 4u);
  this->interval = v4;
  v5 = v4;
  v6 = NewSpecific(uint, 3u);
  v7 = v6;
  v5->m_Items[0] = v7;
  interval = this->interval;
  v10 = NewSpecific(uint, 3u);
  v11 = v10;
  interval->m_Items[1] = v11;
  v13 = this->interval;
  v14 = NewSpecific(uint, 3u);
  v15 = v14;
  v13->m_Items[2] = v15;
  v17 = this->interval;
  v18 = NewSpecific(uint, 3u);
  v19 = v18;
  v17->m_Items[3] = v19;
}
