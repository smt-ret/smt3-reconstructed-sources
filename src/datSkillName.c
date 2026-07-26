#include "types.h"

static char txt[UNKNOWN_ARRAY_SIZE];

char *GetLocalizeText(char *ID);
bool IsZensyoMode(void);
bool evtBitCheck(s32 no);

// 0x150f660
char *Get(s32 id, s32 Devilid) {
  s64 *v6;

  if (!IsZensyoMode())
  if (Devilid != 192)
  switch (id)
  {
    case 262:
      v6 = &StringLiteral_14196;
      break;
    case 263:
      v6 = &StringLiteral_14197;
      break;
    case 264:
      v6 = &StringLiteral_14198;
      break;
    case 266:
      v6 = &StringLiteral_14199;
      break;
    case 267:
      v6 = &StringLiteral_14200;
      break;
    case 268:
      v6 = &StringLiteral_14201;
      break;
    case 269:
      v6 = &StringLiteral_14202;
      break;
    case 274:
      v6 = &StringLiteral_14203;
      break;
    case 360:
      v6 = &StringLiteral_14204;
      break;
    case 361:
      v6 = &StringLiteral_14205;
      break;
    default:
  }
  return GetLocalizeText(*v6);
}

// 0x150f9a0
bool raidoCheck(s32 Devilid) {
 if (IsZensyoMode())
  {
    return Devilid == 192;
  }
  return !evtBitCheck(3712);
}
