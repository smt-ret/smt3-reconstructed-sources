#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct fldResourcePoint_t fldResourcePoint_t;

dds3Basic_t *dds3AddSceneBasicData(u32 type);

// 0x14f76d0
dds3Basic_t *dds3AddPointBasic(u32 serialID, fldResourcePoint_t *pData, char *pName) {
    dds3AddSceneBasicData(0);
    return 0;
}

// 0x14f7790
void *dds3PointBasicGetResource(dds3Basic_t *pPointBasic) {
  return pPointBasic->workdata;
}
