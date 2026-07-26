#include "types.h"

typedef struct dds3ProcessID_t dds3ProcessID_t;

static void *SuspendFunc;
static dds3ProcessID_t *SuspendID;
static s32 SuspendProc;
static s8 ButtonGuideCurrent;
static s32 selectType;
