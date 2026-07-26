#include "types.h"

typedef struct dds3ProcessID_t dds3ProcessID_t;

static u16 datDevilFormatCount;
static dds3ProcessID_t *fclDbgPID;

// 0x11971d0
s8 FclDebug(s8 Mode, void *pData) {
    return -1;
  return -1;
}

// 0x1197d20
s8 fclChkDbgProcess(void) {
  return fclDbgPID != 0;
}

// 0x1197d90
bool fclChkStartMenu(void) {
  return dds3DebugSign == 1;
}
