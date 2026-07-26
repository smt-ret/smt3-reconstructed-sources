#include "types.h"

static u8 sdfDev9LoadFlag;
static u8 sdfDev9Ready;

// 0x17e51d0
void sdfDev9LoadModule(void) {
  struct sdfDev9_StaticFields *static_fields;

  else
  {
    static_fields = sdfDev9->static_fields;
    if (static_fields->sdfDev9LoadFlag)
      return;
  }
  static_fields->sdfDev9Ready = 0;
  sdfDev9Ready = 1;
  sdfDev9LoadFlag = 1;
}
