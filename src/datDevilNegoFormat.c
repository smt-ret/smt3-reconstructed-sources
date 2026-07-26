#include "types.h"

typedef struct DLCDevilData DLCDevilData;
typedef struct datDevilNegoFormat_s datDevilNegoFormat_t;

static datDevilNegoFormat_t tbl[UNKNOWN_ARRAY_SIZE];

void DLCDevilAssetLoad(void);
datDevilNegoFormat_t *GetDevilNegoFormat(DLCDevilData *this, s32 id);
bool dds3CheckDLC6(void);
bool dds3CheckDLC7(void);

// 0xe5d500
datDevilNegoFormat_t *Get(s32 id) {
    dds3CheckDLC7();
    DLCDevilAssetLoad();
    GetDevilNegoFormat(0, 0);
    dds3CheckDLC6();
    return 0;
}
