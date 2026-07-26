#include "types.h"

typedef struct effPCPMakka_tag effPCPMakka_tag;
typedef struct effPartHandle_t effPartHandle_t;

struct effPCPMakka_tag {
    sdfVector4_t pos;
    f32 scale;
    u32 abgr;
    u32 number;
    s32 frame;
    s32 timing[10];
    f32 rotate[10];
    effPartHandle_t *hModel[10];
};

// 0x1158000
void Clear(effPCPMakka_tag *this) {
  *&this->scale = 0;
  *&this->number = 0;
  *&this->pos.x = 0;
  *&this->pos.z = 0;
  this->timing = NewSpecific(s32, 0xAu);
  this->rotate = NewSpecific(f32, 0xAu);
  this->hModel = NewSpecific(effPartHandle_t, 0xAu);
}
