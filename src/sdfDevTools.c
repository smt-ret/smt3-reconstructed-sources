#include "types.h"

static char *dma_id_str[8];
static char *sdfDevDumpDmaVifLink_vif_unpack_str[16];
static char *sdfDevDumpDmaVifLink_vif_flag_str[8];
static s32 sdfDevDumpDmaVifLink_vif_elem_count[16];
static char *sdfDevDumpGsMemInfo_type_str[4];
static char *sdfDevDumpGsMemInfoRev_type_str[4];

s32 sdfPrintf(char *str, void **LegacyParamArray);

// 0x17e6eb0
void sdfDevDumpChipMemInfo(void) {
  ;
}

// 0x17e6e60
void sdfDevDumpDmaLink(void *aTag) {
  ;
}

// 0x17e6e70
void sdfDevDumpDmaVifLink(void *aTag) {
  ;
}

// 0x17e6e80
void sdfDevDumpGsMemInfo(void) {
  ;
}

// 0x17e6e90
void sdfDevDumpGsMemInfoRev(void) {
  ;
}

// 0x17e6b20
void sdfDevDumpMem(void *aPtr, s32 aLeng) {
    sdfPrintf(0, 0);
}

// 0x17e6ea0
void sdfDevDumpMemInfo(void) {
  ;
}
