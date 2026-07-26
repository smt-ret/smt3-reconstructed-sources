#include "types.h"

typedef struct sdfRandCB_t sdfRandCB_t;
typedef struct sdfSystem_sdfUserIOHandlerDelegate sdfSystem_sdfUserIOHandlerDelegate;

static s32 T0_COUNT;
static u32 sdfCoreDrawPointBuffSize;
static sdfSystem_sdfUserIOHandlerDelegate *sdfUserIOHandler;

void sdf3DInit(s32 aNestLevelLimit);
void sdfPadInitManager(void);
void sdfRandomizeByTime(sdfRandCB_t **aCB);

// 0x15d2a60
s32 sdfCreateSema(s32 initCount, s32 maxCount, s32 option) {
  return 0;
}

// 0x15d2a50
void sdfDummyFunc(void) {
  ;
}

// 0x15d2ae0
s32 sdfGetRunTimeCount(s32 aBaseTime) {
  return T0_COUNT - aBaseTime;
}

// 0x15d2a70
s32 sdfGetRunTimeCountBase(void) {
  return T0_COUNT;
}

// 0x15d2b60
void sdfInit(s32 aBuffSize, s32 aChipSize, s32 aFrameBuffSize) {
  sdfRandCB_t_o *aCB;

  aCB = 0;
  T0_COUNT = 0;
  sdfPadInitManager();
  sdf3DInit(64);
  aCB = 0;
  sdfRandomizeByTime(&aCB);
}

// 0x15d2b50
void sdfSetDebugHandler(void) {
  ;
}
