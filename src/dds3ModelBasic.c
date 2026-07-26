#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ModelBasicWorkData_t dds3ModelBasicWorkData_t;
typedef struct sdfModelDef_t sdfModelDef_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;
typedef struct sdfModelTexList_t sdfModelTexList_t;
typedef struct sdfMotionCtrlr_t sdfMotionCtrlr_t;
typedef struct sdfMotionPlayBook_t sdfMotionPlayBook_t;

dds3Basic_t *dds3AddSceneBasicData(u32 type);
void dds3ModelBasicWorkData_t__Clear(dds3ModelBasicWorkData_t *this);

// 0x14eaef0
s32 ModelBasicConstructor(dds3Basic_t *pBasic) {
  u64 *v3;

  v3 = Allocate(dds3ModelBasicWorkData_t);
  dds3ModelBasicWorkData_t___ctor(v3);
  pBasic->workdata = v3;
  dds3ModelBasicWorkData_t__Clear(v3);
  return 1;
}

// 0x14eaf60
s32 ModelBasicDestructor(dds3Basic_t *pBasic) {
  return 0;
}

// 0x14eaf70
dds3Basic_t *dds3AddModelBasic(u32 serialID, sdfModelDef_t *pModelDef, sdfMotionPlayBook_t *pMotDef, dds3Basic_t *pTextureBasic, char *pName) {
    dds3AddSceneBasicData(0);
    return 0;
}

// 0x14eb0c0
dds3Basic_t *dds3AddModelBasic2(u32 serialID, sdfModelDef_t *pModelDef, sdfMotionPlayBook_t *pMotDef, sdfModelTexList_t *pTexList, char *pName) {
    dds3AddSceneBasicData(0);
    return 0;
}

// 0x14eb320
sdfMotionCtrlr_t *dds3ModelBasicMakeMotion(dds3Basic_t **pBasic, sdfModelRootNode_t *pRootNode) {
    return 0;
}

// 0x14eb210
sdfModelRootNode_t *dds3ModelBasicMakeRootNode(dds3Basic_t **pBasic) {
    return 0;
}
