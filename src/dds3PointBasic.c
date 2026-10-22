#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct fldResourcePoint_t fldResourcePoint_t;

dds3Basic_t *dds3AddSceneBasicData(u32 type);

// 0x14f76d0
dds3Basic_t *dds3AddPointBasic(u32 serialID, fldResourcePoint_t *pData, char *pName) {
  dds3Basic_t_o *v7;
  s64 v8;
  dds3Basic_t_o *v9;
  s64 v10;
  s64 v11;
  s64 v12;
  u64 v14[6];

  v7 = dds3AddSceneBasicData(0x11u, pData);
  v8 = *&pData->pos.z;
  v9 = v7;
  v14[0] = *&pData->pos.x;
  v14[1] = v8;
  v10 = *&pData->rot.x;
  v11 = *&pData->rot.z;
  v12 = *&pData->scl.z;
  v14[4] = *&pData->scl.x;
  v14[5] = v12;
  v14[2] = v10;
  v14[3] = v11;
  v7->workdata = sub_8D3950(fldResourcePoint_t, v14);
  v9->serialID = serialID;
  v9->name = pName;
  return v9;
}

// 0x14f7790
void *dds3PointBasicGetResource(dds3Basic_t *pPointBasic) {
  return pPointBasic->workdata;
}
