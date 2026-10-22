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
  UnityEngine_Color32_o c;
  UnityEngine_Color_o v7;
  UnityEngine_Color_o result;

  c.rgba = 0;
  sub_19ED4B0(&c, SHIBYTE(val), SBYTE2(val), SBYTE1(val), val);
  v7 = op_Implicit_27186704(c.rgba);
  result.r = v7.r;
  result.g = v7.g;
  result.b = v7.b;
  result.a = v7.a;
  return result;
}
