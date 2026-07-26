#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;

dds3Basic_t *dds3AddSceneBasicData(u32 type);

// 0x17b3670
dds3Basic_t *dds3AddEventBasic(u32 serialID, void *pData, char *pName) {
  dds3Basic_t_o *result;

  result = dds3AddSceneBasicData(0xDu);
  result->workdata = pData;
  result->serialID = serialID;
  result->name = pName;
  return result;
}

// 0x17b3700
void *dds3EventBasicGetResource(dds3Basic_t *pBasic) {
  return pBasic->workdata;
}
