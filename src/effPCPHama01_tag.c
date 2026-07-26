#include "types.h"

typedef struct effPCPHama01_tag effPCPHama01_tag;
typedef struct effPartHandle_t effPartHandle_t;

struct effPCPHama01_tag {
    sdfVector4_t pos;
    u32 abgr;
    u32 frame;
    f32 scale;
    effPartHandle_t *hPart[8];
    effPartHandle_t *hBillPart[8];
    u32 bill_frame[8];
    u32 interval[8];
};

// 0x11574d0
void Clear(effPCPHama01_tag *this) {
  this->hPart = NewSpecific(effPartHandle_t__, 8u);
  this->hBillPart = NewSpecific(effPartHandle_t, 8u);
  this->bill_frame = NewSpecific(uint, 8u);
  this->interval = NewSpecific(uint, 8u);
}
