#include "types.h"

typedef struct sdfDecompCb_t sdfDecompCb_t;

static u8 src_start[UNKNOWN_ARRAY_SIZE];
static u8 dst_start[UNKNOWN_ARRAY_SIZE];
static s32 direc_hist_index;
static s32 direc_hist[16];

s32 SDF_ABORT1(char *a);
void SDF_ABORT2(char *aFmt, void **LegacyParamArray);

// 0x15d8060
s32 sdfDecomp(sdfDecompCb_t *cb, void *src, s32 length) {
    SDF_ABORT2(0, 0);
    SDF_ABORT1(0);
    return 0;
}

// 0x15d9120
void sdfDecompInit(sdfDecompCb_t *cb, void *dst) {
}
