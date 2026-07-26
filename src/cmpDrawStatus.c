#include "types.h"

typedef struct datUnitWork_s datUnitWork_t;

static s32 CMB_UPINFO_COL;
static s32 gStatusTimer[3];
static s32 gStatusBlinkQue[5];
static s32 gPointFlash;
static s8 gFlashFlag[3];
static s8 gSkillEffectPos;
static s16 gRaceNameFlash;
static datUnitWork_t *gCompareUnit;

s32 itfMesMngGetStatManager(void);

// 0x13fef00
s32 itfMesMngIsDispWin(void) {
  return itfMesMngGetStatManager() & 2;
}
