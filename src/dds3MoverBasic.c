#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3MoverBasicObjFunc_t dds3MoverBasicObjFunc_t;
typedef struct dds3MoverBasicWorkData_t dds3MoverBasicWorkData_t;
typedef struct dds3PathBasicControl_t dds3PathBasicControl_t;
typedef struct dds3PoseSet_t dds3PoseSet_t;
typedef struct fldResourceLightPath_t fldResourceLightPath_t;

static s32 movername;
static char *movernamestr[10];

u32 DDS3_GETBASICTYPEL(dds3Basic_t *pAreaBasic);
s32 MoverBasicMainprocuder(dds3Basic_t *pBasic);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void dds3AddPosPoseSet(dds3Basic_t **pBasic, sdfVector4_t pos);
void dds3AddRotPoseSet(dds3Basic_t **pBasic, sdfVector4_t rot);
dds3Basic_t *dds3AddSceneBasicData(u32 type);
void dds3AddSclPoseSet(dds3Basic_t **pBasic, sdfVector4_t scl);
void dds3InitPoseSetValue(dds3PoseSet_t **pPoseSet);
void dds3MoverBasicFreePath(dds3Basic_t **pMoverBasic);
void dds3MoverBasicWorkData_t__Clear(dds3MoverBasicWorkData_t *this);
dds3Basic_t *dds3ObjectBaseSetControlBasicType(dds3Basic_t **pObjectBasic, dds3Basic_t **pItemBasic, u32 itemType);
f32 dds3PathBasicControlGetFovy(dds3PathBasicControl_t **pControl);
void dds3PathBasicControlGetLight(dds3PathBasicControl_t **pControl, fldResourceLightPath_t **resource);
void dds3PathBasicControlGetPos(dds3PathBasicControl_t **pControl);
void dds3PathBasicControlGetRot(dds3PathBasicControl_t **pControl);
dds3PathBasicControl_t *dds3PathBasicMakeControl(dds3Basic_t **pBasic);
u32 dds3SerializeID(void);
void dds3SetLightObjectPathResoruce(dds3Basic_t **basic, fldResourceLightPath_t *resource);
void dds3SetPosPoseSet(dds3Basic_t **pBasic, sdfVector4_t pos);
void dds3SetRotPoseSet(dds3Basic_t **pBasic, sdfVector4_t rot);
void update_hoji_position(dds3Basic_t *basic);

// 0x14eb9a0
s32 MoverBasicConstructor(dds3Basic_t *pBasic) {
    dds3MoverBasicWorkData_t__Clear(0);
    return 0;
}

// 0x14ebac0
s32 MoverBasicDestructor(dds3Basic_t *pBasic) {
    dds3MoverBasicFreePath(0);
    dds3ObjectBaseSetControlBasicType(0, 0, 0);
    return 0;
}

// 0x14ebdf0
s32 MoverBasicMainprocuder(dds3Basic_t *pBasic) {
    dds3PathBasicControlGetPos(0);
    SDF_VU0__STOREVECTOR(0);
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
    DDS3_GETBASICTYPEL(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    dds3PathBasicControlGetRot(0);
    dds3SetRotPoseSet(0, (sdfVector4_t){0});
    dds3PathBasicControlGetFovy(0);
    dds3PathBasicControlGetLight(0, 0);
    dds3SetLightObjectPathResoruce(0, 0);
    update_hoji_position(0);
    dds3InitPoseSetValue(0);
    dds3AddSclPoseSet(0, (sdfVector4_t){0});
    dds3AddRotPoseSet(0, (sdfVector4_t){0});
    dds3AddPosPoseSet(0, (sdfVector4_t){0});
    return 0;
}

// 0x14ed380
dds3Basic_t *dds3AddMoverBasic(dds3Basic_t **pObjectBasic) {
    dds3AddSceneBasicData(0);
    dds3SerializeID();
    return 0;
}

// 0x14ebbf0
void dds3MoverBasicFreePath(dds3Basic_t **pMoverBasic) {
}

// 0x14edd80
dds3PathBasicControl_t *dds3MoverBasicGetPathControl(dds3Basic_t **pMoverBasic) {
    return 0;
}

// 0x14ed770
void dds3MoverBasicMakePath(dds3Basic_t **pMoverBasic) {
    dds3PathBasicMakeControl(0);
}

// 0x14ed570
void dds3MoverBasicSetCallBackPrimaryControl(dds3Basic_t **mover, dds3MoverBasicObjFunc_t *func) {
}

// 0x14ed670
void dds3MoverBasicSetPath(dds3Basic_t **pMoverBasic, dds3Basic_t **pPathBasic) {
}

// 0x14ede70
s32 dds3MoverBasicUpdate(dds3Basic_t **pBasic) {
  dds3Basic_t_o *v3;

  v3 = *pBasic;
  MoverBasicMainprocuder(v3);
  return 1;
}

// 0x14ecd90
void updatePositionForUnity(dds3Basic_t *basic) {
    update_hoji_position(0);
}

// 0x14ecea0
void update_hoji_position(dds3Basic_t *basic) {
    DDS3_GETBASICTYPEL(0);
}
