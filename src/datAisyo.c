#include "types.h"

typedef struct DLCDevilData DLCDevilData;

static u32 *tbl[448];

void DLCDevilAssetLoad(void);
u32 GetDevilAisyoData(DLCDevilData *this, s32 id, s32 attr);
bool dds3CheckDLC6(void);
bool dds3CheckDLC7(void);

// 0x161f780
u32 Get(s32 id, s32 attr, u32 su_flag) {
    dds3CheckDLC7();
    DLCDevilAssetLoad();
    dds3CheckDLC6();
    GetDevilAisyoData(0, 0, 0);
    return 0;
}
