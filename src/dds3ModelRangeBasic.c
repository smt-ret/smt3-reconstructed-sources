#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ModelRangeBasicWorkData_t dds3ModelRangeBasicWorkData_t;

dds3Basic_t *dds3AddSceneBasicData(u32 type);
dds3Basic_t *dds3GetControlScene(void);
void dds3ModelRangeBasicWorkData_t__Clear(dds3ModelRangeBasicWorkData_t *this);
dds3Basic_t *dds3SearchSceneBasic(dds3Basic_t **pBasic, u32 serialID, u32 type);

// 0x14eb420
s32 ModelRangeBasicConstructor(dds3Basic_t *pBasic) {
    dds3ModelRangeBasicWorkData_t__Clear(0);
    return 0;
}

// 0x14eb540
s32 ModelRangeBasicDestructor(dds3Basic_t *pBasic) {
    return 0;
}

// 0x14eb630
dds3Basic_t *dds3AddModelRangeBasicNew(u32 serialID, void *pData, sdfVector4_t pos, char *pName) {
    dds3AddSceneBasicData(0);
    return 0;
}

// 0x14eb850
s32 dds3ModelRangeBasicGetBlockID(s32 resID) {
    dds3GetControlScene();
    dds3SearchSceneBasic(0, 0, 0);
    return 0;
}

// 0x14eb750
void dds3ModelRangeBasicSetBlockID(dds3Basic_t **aPtr, s32 blockID) {
}
