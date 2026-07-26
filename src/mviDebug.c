#include "types.h"

typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct mviDebugCb_t mviDebugCb_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;

static mviDebugCb_t *mviDebugCb;
static s32 SOX;
static s32 SOY;
static u32 SZM;
static s32 CX__;
static s32 CY__;
static u32 Z__;
static s32 OX__;
static s32 OY__;
static s32 SX__;
static s32 SY__;
static u32 IPU_CTRL;

bool DDS3_PAD2CHECK_PRESS(s32 id);
bool DDS3_PAD2CHECK_REP(s32 id);
void dds3MovieDebugDefault(void);
void *sdfDevPrintf(s32 aX, s32 aY, u32 aZ, s32 aAttr, char *aStr, void **LegacyParamArray);
void sdfDrawTagLink(sdfDrawTag_t *aTag, void *aPacket);

// 0x19c7de0
void dds3MovieDebugDataActivate(void) {
  mviDebugCb->ioAct = 1;
  mviDebugCb->memAct = 1;
}

// 0x19c7f70
void dds3MovieDebugDataUpdate(void) {

}

// 0x19c7e60
void dds3MovieDebugDefault(void) {
  mviDebug_c *v2;
  struct mviDebug_StaticFields *static_fields;
  struct mviDebugCb_t_o *mviDebugCb;

  mviDebugCb->ioAddr = IPU_CTRL;
  static_fields = v2->static_fields;
  mviDebugCb = static_fields->mviDebugCb;
  mviDebugCb->memAddr = dds3MovieCb;
  mviDebugCb->ioAct = 1;
  mviDebugCb->memAct = 1;
}

// 0x19c7fe0
dds3ProcessFunc_t *dds3MovieDebugProcess(dds3ProcessID_t *id) {
    dds3MovieDebugDefault();
    DDS3_PAD2CHECK_PRESS(0);
    DDS3_PAD2CHECK_REP(0);
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLink(0, 0);
    return 0;
}
