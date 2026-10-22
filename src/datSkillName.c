#include "types.h"

static char *txt;

char *GetLocalizeText(char *ID);
bool IsZensyoMode(void);
bool evtBitCheck(s32 no);

// 0x150f660
char *Get(s32 id, s32 Devilid) {
  s64 *v6;

LABEL_7:
  if (!IsZensyoMode())
    goto LABEL_19;
LABEL_10:
  if (Devilid != 192)
    goto LABEL_20;
LABEL_11:
  switch (id)
  {
    case 262:
      v6 = &"SKILLMC_L0262";
      break;
    case 263:
      v6 = &"SKILLMC_L0263";
      break;
    case 264:
      v6 = &"SKILLMC_L0264";
      break;
    case 266:
      v6 = &"SKILLMC_L0266";
      break;
    case 267:
      v6 = &"SKILLMC_L0267";
      break;
    case 268:
      v6 = &"SKILLMC_L0268";
      break;
    case 269:
      v6 = &"SKILLMC_L0269";
      break;
    case 274:
      v6 = &"SKILLMC_L0274";
      break;
    case 360:
      v6 = &"SKILLMC_L0360";
      break;
    case 361:
      v6 = &"SKILLMC_L0361";
      break;
    default:
      goto LABEL_20;
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
