#include "types.h"

static s32 CMP_DEFAULT_Z;
static u32 CMP_DEFAULT_OT;

// 0x13e2130
s32 CMP_X(s32 a) {
  return 16 * a;
}

// 0x13e5dc0
s32 CMP_XM(s32 a) {
  return 16 * (a * 3.75);
}

// 0x13e2140
s32 CMP_Y(s32 b) {
  return 8 * b;
}

// 0x13e5de0
s32 CMP_YM(s32 b) {
  return 8 * (b * 2.25);
}
