#include "types.h"

typedef struct sdfThCB_t sdfThCB_t;
typedef struct sdfThread_aStartFuncDelegate sdfThread_aStartFuncDelegate;

static s32 thCtlSemaId;
static sdfThCB_t *thCBLinkHead;
static s32 sdfThVSyncThreadId;
static u16 sdfThVSyncThreadStack[2048];
static s32 sdfThIdleThreadId;
static u32 sdfVSyncCount;

// 0x15d4f10
void sdfThCreate(sdfThCB_t *aCB, sdfThread_aStartFuncDelegate *aStartFunc, void *aStack, s64 aStackSize, s32 aPrio, void *aExecParam) {
  ;
}

// 0x15d4f30
void sdfThDelete(sdfThCB_t *aCB) {
  ;
}

// 0x15d50f0
void sdfThEnterIdle(void) {
  ;
}

// 0x15d4fe0
void sdfThExit(void) {
  struct sdfThCB_t_o *thCBLinkHead;

LABEL_7:
  else
  {
    if (!thCBLinkHead)
      return;
  }
  do
  {
    if (thCBLinkHead->thId == -1)
      break;
    thCBLinkHead = thCBLinkHead->next;
  }
  while (thCBLinkHead);
}

// 0x15d4f40
sdfThCB_t *sdfThFindCB(s32 aId) {
  sdfThCB_t_o *result;

  else
  {
    result = thCBLinkHead;
    if (!result)
      return result;
  }
  do
  {
    if (result->thId == aId)
      break;
    result = result->next;
  }
  while (result);
  return result;
}

// 0x15d50e0
void sdfThInit(void) {
  ;
}

// 0x15d4f20
void sdfThSleep(s32 aCycle) {
  ;
}

// 0x15d50c0
s32 sdfThVSyncHandler(s32 aCause) {
  return 0;
}

// 0x15d50d0
void sdfThVSyncThread(void *aDummy) {
  ;
}
