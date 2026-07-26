#include "types.h"

void dds3GlobalWorkDestroy(void);
void dds3GlobalWorkInit(void);
void evtFreeStage(void);

// 0x152eca0
void dds3CreateGameData(s32 no) {
  evtFreeStage();
  dds3GlobalWorkDestroy();
  dds3GlobalWorkInit();
}
