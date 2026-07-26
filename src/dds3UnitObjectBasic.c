#include "types.h"

typedef struct FieldChrHD FieldChrHD;
typedef struct ModelHD ModelHD;
typedef struct dds3BasicArrayHandle_t dds3BasicArrayHandle_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ObjectBaseControlWorkData_t dds3ObjectBaseControlWorkData_t;
typedef struct dds3PoseSet_t dds3PoseSet_t;
typedef struct dds3UnitObjectBasicWorkData_t dds3UnitObjectBasicWorkData_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct sdfModelOt_t sdfModelOt_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;

static sdfVector4_t r_q;
static sdfVector4_t r_v;
static dds3PoseSet_t *r_update;

void FromRotation(f32 aAngle);
f32 GetBattle(FieldChrHD *this);
void KageSet_Battle(FieldChrHD *this, f32 x, f32 z, f32 size, f32 alp);
void Mult(void);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__COPYVECTOR_A_TO_B(void);
void SDF_VU0__LOADIDENTITYVECTOR(void);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__MULVECTOR(void);
void SDF_VU0__SETVECTOR_X(f32 v);
void SDF_VU0__SETVECTOR_Y(f32 v);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__VECTOR_W_SET_ZERO(void);
void StepFrame(ModelHD *this);
void dds3AddPosPoseSet(dds3Basic_t **pBasic, sdfVector4_t pos);
void dds3AddRotPoseSet(dds3Basic_t **pBasic, sdfVector4_t rot);
dds3Basic_t *dds3AddSceneBasicData(u32 type);
void dds3AddSclPoseSet(dds3Basic_t **pBasic, sdfVector4_t scl);
dds3Basic_t *dds3AreaBasicGetFastArea(void);
void dds3BackupPoseSet(dds3PoseSet_t **pPoseSet);
s32 dds3CheckPoseSetFlag(dds3PoseSet_t **pPoseSet, u32 flag);
void dds3DeleteSceneBasicData(dds3Basic_t **basic);
void dds3FreeBasicArrayHandle(dds3BasicArrayHandle_t **hndl);
void dds3FreePoseSet(dds3Basic_t **basic);
dds3Basic_t *dds3GetBasicArray(dds3BasicArrayHandle_t **hndl);
s32 dds3GetBasicArrayCount(dds3BasicArrayHandle_t **hndl);
dds3Basic_t *dds3GetControlScene(void);
void dds3GetPos2PoseSetMCR(dds3Basic_t **pBasic);
void dds3GetPosPoseSetMCR(dds3Basic_t **pBasic);
void dds3GetRotPoseSetMCR(dds3Basic_t **pBasic);
void dds3GetSclPoseSetMCR(dds3Basic_t *pBasic);
evtUnitHandle_t *dds3GetUnitHandleObjectBasic(dds3Basic_t **b);
s32 dds3InitPoseSet(dds3Basic_t **basic);
void dds3InitPoseSetValue(dds3PoseSet_t **pPoseSet);
void dds3LinkLightObjectToUnitObject(dds3Basic_t **lightbasic, dds3Basic_t **unitbasic, u32 frame);
s32 dds3ObjectBaseCheckFlag(dds3Basic_t **pObjectBasic, u32 flag);
void dds3ObjectBaseCreateMover(dds3Basic_t **pObjectBasic);
void dds3ObjectBaseFreeControlWorkData(dds3ObjectBaseControlWorkData_t **pControl);
void dds3ObjectBaseFreeModelHandle(dds3Basic_t **pObjectBasic);
dds3ObjectBaseControlWorkData_t *dds3ObjectBaseInitControlWorkData(dds3Basic_t **pObjectBasic);
void dds3ObjectBaseModelLinkOt(sdfModelOt_t *pModelOt, dds3Basic_t **pObjectBasic);
void dds3ObjectBaseOnFlag(dds3Basic_t **pObjectBasic, u32 flag, bool alock);
s32 dds3ObjectBaseRegistArea(dds3Basic_t **pObjectBasic);
dds3Basic_t *dds3ObjectBaseSetControlBasicType(dds3Basic_t **pObjectBasic, dds3Basic_t **pItemBasic, u32 itemType);
void dds3OffPoseSetFlag(dds3PoseSet_t **pPoseSet, u32 flag);
s32 dds3RadiusCheckPoseSet2(dds3PoseSet_t **p1, dds3PoseSet_t **p2);
dds3BasicArrayHandle_t *dds3SceneBasicGetList(dds3Basic_t **pBasic, u32 type);
s32 dds3SetFirstBasicArray(dds3BasicArrayHandle_t **hndl);
s32 dds3SetNextBasicArray(dds3BasicArrayHandle_t **hndl);
void dds3SetPosPoseSet(dds3Basic_t **pBasic, sdfVector4_t pos);
void dds3SetRotPoseSet(dds3Basic_t **pBasic, sdfVector4_t rot);
void dds3UnitObjectBasicEL_Link(dds3Basic_t **unitBasic);
void dds3UnitObjectBasicEL_LinkFree(dds3Basic_t **unitBasic);
dds3ObjectBaseControlWorkData_t *dds3UnitObjectBasicGetControlWorkData(dds3Basic_t **pBasic);
void dds3UnitObjectBasicWorkData_t__Clear(dds3UnitObjectBasicWorkData_t *this);
void dds3UnlinkLightObjectFromUnitObject(dds3Basic_t **unitbasic, u32 frame);
s32 evtDeleteUnitHandle(evtUnitHandle_t **h);
s32 evtUnitManagerPrimaryFunc(dds3PoseSet_t *pose, dds3Basic_t *basic);
dds3Basic_t *fldCamNowEveCamera(bool nc);
void fldSdwDraw(dds3Basic_t *pObjectBasic);
s32 mdlChkHide(dds3ModelHandle_t *mdl);
s32 mdlGetMajorNum(dds3ModelHandle_t **aHandle);
s32 mdlGetMinorNum(dds3ModelHandle_t **aHandle);
void mdlGetPosition(dds3ModelHandle_t **aHandle);
void mdlGetRotate(dds3ModelHandle_t **aHandle);
void mdlGetScale(dds3ModelHandle_t **aHandle);
void mdlSetPosition(dds3ModelHandle_t **aHandle);
void mdlSetRotate(dds3ModelHandle_t **aHandle);
void mdlSetScale(dds3ModelHandle_t **aHandle);
s32 sdfModelGetMarkPosUnity(sdfModelRootNode_t *aRoot, s32 aId);
f32 sdfSin(f32 aRadius);
void update_position(dds3Basic_t **basic);

// 0x1003a10
dds3Basic_t *dds3AddUnitObjectBasic(u32 serialID, sdfVector4_t aPos, sdfVector4_t aRot) {
    dds3AddSceneBasicData(0);
    dds3ObjectBaseCreateMover(0);
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
    dds3SetRotPoseSet(0, (sdfVector4_t){0});
    dds3BackupPoseSet(0);
    dds3AreaBasicGetFastArea();
    dds3ObjectBaseSetControlBasicType(0, 0, 0);
    dds3ObjectBaseRegistArea(0);
    return 0;
}

// 0x1003c40
void dds3DeleteUnitObjectBasic(dds3Basic_t **aPtr) {
  dds3DeleteSceneBasicData(aPtr);
}

// 0x1003cb0
s32 dds3GetStatusUnitObjectBasic(dds3Basic_t **aPtr) {
    return 0;
}

// 0x1003830
evtUnitHandle_t *dds3GetUnitHandleObjectBasic(dds3Basic_t **b) {
    return 0;
}

// 0x1001bb0
s32 dds3UnitObjectBasicConstructor(dds3Basic_t *aPtr) {
    dds3InitPoseSet(0);
    dds3UnitObjectBasicWorkData_t__Clear(0);
    dds3ObjectBaseInitControlWorkData(0);
    dds3ObjectBaseOnFlag(0, 0, 0);
    return 0;
}

// 0x1001dc0
s32 dds3UnitObjectBasicDestructor(dds3Basic_t *aPtr) {
    dds3UnitObjectBasicEL_LinkFree(0);
    dds3FreePoseSet(0);
    evtDeleteUnitHandle(0);
    dds3ObjectBaseFreeModelHandle(0);
    dds3ObjectBaseFreeControlWorkData(0);
    return 0;
}

// 0x1002fd0
s32 dds3UnitObjectBasicDrawProcedure(dds3Basic_t *aPtr) {
    dds3ObjectBaseCheckFlag(0, 0);
    dds3GetUnitHandleObjectBasic(0);
    mdlChkHide(0);
    fldSdwDraw(0);
    GetBattle(0);
    mdlGetPosition(0);
    SDF_VU0__STOREVECTOR(0);
    mdlGetRotate(0);
    mdlGetScale(0);
    StepFrame(0);
    dds3UnitObjectBasicGetControlWorkData(0);
    sdfModelGetMarkPosUnity(0, 0);
    KageSet_Battle(0, 0, 0, 0, 0);
    dds3ObjectBaseModelLinkOt(0, 0);
    return 0;
}

// 0x1002810
void dds3UnitObjectBasicEL_Link(dds3Basic_t **unitBasic) {
    dds3GetControlScene();
    dds3SceneBasicGetList(0, 0);
    dds3GetBasicArrayCount(0);
    dds3FreeBasicArrayHandle(0);
    dds3SetFirstBasicArray(0);
    dds3GetBasicArray(0);
    dds3RadiusCheckPoseSet2(0, 0);
    dds3UnlinkLightObjectFromUnitObject(0, 0);
    dds3SetNextBasicArray(0);
    dds3LinkLightObjectToUnitObject(0, 0, 0);
}

// 0x1001f70
void dds3UnitObjectBasicEL_LinkFree(dds3Basic_t **unitBasic) {
    dds3UnlinkLightObjectFromUnitObject(0, 0);
}

// 0x1003920
dds3ObjectBaseControlWorkData_t *dds3UnitObjectBasicGetControlWorkData(dds3Basic_t **pBasic) {
    return 0;
}

// 0x1002080
s32 dds3UnitObjectBasicMainProcedure(dds3Basic_t *aPtr) {
    dds3InitPoseSetValue(0);
    evtUnitManagerPrimaryFunc(0, 0);
    dds3AddSclPoseSet(0, (sdfVector4_t){0});
    dds3AddRotPoseSet(0, (sdfVector4_t){0});
    dds3AddPosPoseSet(0, (sdfVector4_t){0});
    dds3CheckPoseSetFlag(0, 0);
    dds3OffPoseSetFlag(0, 0);
    mdlGetMajorNum(0);
    mdlGetMinorNum(0);
    dds3GetSclPoseSetMCR(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__LOADIDENTITYVECTOR();
    SDF_VU0__VECTOR_W_SET_ZERO();
    sdfSin(0);
    SDF_VU0__SETVECTOR_X(0);
    SDF_VU0__SETVECTOR_Y(0);
    SDF_VU0__MULVECTOR();
    SDF_VU0__ADDVECTOR();
    mdlSetScale(0);
    dds3GetRotPoseSetMCR(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    FromRotation(0);
    Mult();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    mdlSetRotate(0);
    dds3GetPos2PoseSetMCR(0);
    dds3GetPosPoseSetMCR(0);
    mdlSetPosition(0);
    dds3BackupPoseSet(0);
    dds3ObjectBaseCheckFlag(0, 0);
    dds3UnitObjectBasicEL_Link(0);
    update_position(0);
    return 0;
}

// 0x1003da0
void dds3UnitObjectBasicSetOt(dds3Basic_t **aPtr, s32 idx) {
}

// 0x1002d90
void update_position(dds3Basic_t **basic) {
    fldCamNowEveCamera(0);
}
