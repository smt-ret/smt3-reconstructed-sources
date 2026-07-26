#include "types.h"

typedef struct sdfTime_t sdfTime_t;

static sdfTime_t *sdfLastTime;
static u8 sdfGetTimeDelay;

// 0x15d5780
s32 sdfGetTime(sdfTime_t *aTime) {
    return 0;
}
