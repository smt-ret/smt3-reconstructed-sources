#include "types.h"

static s32 CMP_PE_NORMAL;
static s8 gParamIdxTbl[5];

// 0x11b9e90
s32 CMP_MAKE_COL(s32 r, s32 g, s32 b, s32 a) {
  return (g << 16) | (r << 24) | (b << 8) | a;
}
