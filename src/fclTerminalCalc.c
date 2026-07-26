#include "types.h"

typedef struct AssetBundles AssetBundles;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;

bool IsLoad(AssetBundles *this, char *key);
void dds3FadeIn(u32 r, u32 g, u32 b, u32 frame);
void *dds3GetProcessData(dds3ProcessID_t **id);
s8 fclChkDbgProcess(void);
void fclClearSignal(s8 Idx);
dds3ProcessID_t *fclScriptStart(u8 **pScriptData, s32 StartNo, dds3ProcessID_t **pPID);
s8 trmChkEventWait(void);
void trmStartBGM(s32 TerminalType, s32 TerminalNo, bool nocheck);
s8 trmStartEvent(void);

// 0xf78030
dds3ProcessFunc_t *trmCalc(dds3ProcessID_t *PID) {
    dds3GetProcessData(0);
    fclChkDbgProcess();
    trmChkEventWait();
    IsLoad(0, 0);
    fclClearSignal(0);
    trmStartEvent();
    fclScriptStart(0, 0, 0);
    trmStartBGM(0, 0, 0);
    dds3FadeIn(0, 0, 0, 0);
    return 0;
}

// 0xf77fb0
void trmCalcAct(void) {
  GBWK->ActFlag = -1;
  GBWK->ActStartFlag = 0;
}
