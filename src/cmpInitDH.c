#include "types.h"

typedef struct DHeartsUI DHeartsUI;
typedef struct cmpDataDH_t cmpDataDH_t;
typedef struct cmpHeartsPosTbl_t cmpHeartsPosTbl_t;

static void *DHeartsObj;
static DHeartsUI *_DHeartsUIScr;
static bool _baseFlagDHearts;
static cmpDataDH_t *CmpDataDH_t;
static cmpDataDH_t *GBWK;
static cmpHeartsPosTbl_t *cmpHeartsPosTbl[27];
static bool cmpDHDrawFlag;
