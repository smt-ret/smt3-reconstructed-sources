#include "types.h"

typedef struct effBTL_t effBTL_t;
typedef struct effEveBEDCutHandle_t effEveBEDCutHandle_t;
typedef struct effPCPDANTE_Damage_Param_t effPCPDANTE_Damage_Param_t;
typedef struct effPCPDANTE_Damage_tag effPCPDANTE_Damage_tag;

struct effPCPDANTE_Damage_tag {
    effPCPDANTE_Damage_Param_t *param;
    u8 wait[32];
    s32 frame;
    u8 original;
    effBTL_t *hBED;
    effEveBEDCutHandle_t *hCutBED[32];
    s32 BEDFrame[32];
    u32 abgr;
};

// 0x11eefd0
void Clear(effPCPDANTE_Damage_tag *this) {
  this->param = 0;
  this->wait = NewSpecific(byte, 0x20u);
  this->frame = 0;
  this->original = 0;
  this->hBED = 0;
  this->hCutBED = NewSpecific(effEveBEDCutHandle_t, 0x20u);
  this->BEDFrame = NewSpecific(s32, 0x20u);
  this->abgr = 0;
}
