#include "types.h"

typedef struct sdfRandCB_t sdfRandCB_t;

static sdfRandCB_t *dds3RandCB;

void sdfRandomize(sdfRandCB_t **aCB, u32 aSeed);

// 0x14e1680
void dds3InitRandCB(void) {
  u64 *v1;

  v1 = Allocate(sdfRandCB_t);
  sdfRandCB_t___ctor(v1);
  dds3RandCB = v1;
  sdfRandomize(&dds3RandCB, 0x12345678u);
}
