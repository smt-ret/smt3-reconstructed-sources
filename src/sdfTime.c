#include "types.h"

typedef struct sdfTime_t sdfTime_t;

static sdfTime_t *sdfLastTime;
static u8 sdfGetTimeDelay;

// 0x15d5780
s32 sdfGetTime(sdfTime_t *aTime) {
  sdfTime_c *v2;
  s32 v4;

  else
  {
    if (sdfGetTimeDelay)
      goto LABEL_6;
  }
  v4 = 0;
  sdfGetTimeDelay = 20;
  if ((v2->_2.bitflags2 & 2) == 0)
    return v4;
LABEL_7:
  return v4;
}
