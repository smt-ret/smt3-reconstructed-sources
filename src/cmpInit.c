#include "types.h"

typedef struct campUI campUI;
typedef struct cmpGlobalWork_t cmpGlobalWork_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

static u8 gCommandFlag[2];
static campUI *_campUIScr;
static void *campCameraObj;
static cmpGlobalWork_t *CMP_GBWK;
static s8 gProcessStat;
static char *gCmpRootMenuStr[8];
static char *gCmpItemRootStr[4];
static char *gCmpPartyRootStr[3];
static char *gCmpHeartsRootStr[2];
static sdfTexHandle_t *cmpTex[6];
static u8 cmpMesData[2962];
static u8 gExitState;

// 0x13f18c0
sdfColor_t GetToRGBA(u32 val) {
    return (sdfColor_t){0};
}
