#include "types.h"

typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ModelResrc_t dds3ModelResrc_t;
typedef struct effBattleSystem_effCAMPBad_tag effBattleSystem_effCAMPBad_tag;
typedef struct effCAMPBadParams_t effCAMPBadParams_t;

static f32 CMP_DEFAULT_FOVY;
static u32 EFFCAMP_SYSTEM_PARALYZE;
static u32 EFFCAMP_SYSTEM_POISON;
static u32 EFFCAMP_SYSTEM_CLOSE;
static u32 EFFCAMP_SYSTEM_CURSE;
static void *cmpMdlObj;
static void *cmpDevilObj;
static char *cmpMdlKey;
static char *cmpMdlName;
static sdfVector3_t cmpDevilRot;
static void *cmpModelReq;
static void *cmpModelObj;
static dds3ModelResrc_t *cmpMrc;
static dds3ModelHandle_t *cmpModelHandle;
static effBattleSystem_effCAMPBad_tag *cmpBadEffHandle;
static effCAMPBadParams_t *cmpBadEffParam;
static s8 gMoveMode;
static s8 gLoadStat;
static u16 gTargetMajorNo;
static u16 gTargetMinorNo;
static s32 gBlockMode;
static sdfMatrix4_t *cmpCameraTM;
static sdfVector4_t cmpCameraTargetPos;
static sdfVector4_t cmpCameraEyePos;
static sdfVector4_t cmpCameraUpVector;
static bool cmpModelSetFlag;
