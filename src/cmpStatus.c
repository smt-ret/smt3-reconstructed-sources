#include "types.h"

typedef struct cmpDataStatus_t cmpDataStatus_t;
typedef struct statusUI statusUI;

static void *statusObj;
static statusUI *_statusUIScr;
static bool _baseFlagStatus;
static void *baseBackObj;
static s32 statusDrawType;
static cmpDataStatus_t *GBWK;
static s8 gTerminateFlag;
static s8 gModelLoadFlag;
static s8 gReloadFlag;
