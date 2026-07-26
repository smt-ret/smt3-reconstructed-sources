#include "types.h"

typedef struct FieldBgHD FieldBgHD;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3MatterObjectBasicWorkData_t dds3MatterObjectBasicWorkData_t;
typedef struct dds3ObjectBaseControlWorkData_t dds3ObjectBaseControlWorkData_t;
typedef struct dds3PoseSet_t dds3PoseSet_t;
typedef struct sdfModelOt_t sdfModelOt_t;

FieldBgHD *GetFHD(void);
void RetTransparent(void *obj);
void SDF_VU0__SET_ROW3(void);
void SDF_VU0__STOREMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SetTransparentEvent(FieldBgHD *this, void *rootobj, u32 rgba);
dds3Basic_t *dds3AddSceneBasicData(u32 type);
void dds3BackupPoseSet(dds3PoseSet_t **pPoseSet);
void dds3DeleteSceneBasicData(dds3Basic_t **basic);
void dds3FreePoseSet(dds3Basic_t **basic);
dds3ObjectBaseControlWorkData_t *dds3GetBaseControlWorkData(dds3Basic_t **pObjectBasic);
dds3Basic_t *dds3GetControlScene(void);
void dds3GetPosPoseSet(dds3Basic_t **pBasic);
void dds3GetRotPoseSet(dds3Basic_t **pBasic);
void dds3GetTMPoseSet(dds3Basic_t **pBasic);
s32 dds3InitPoseSet(dds3Basic_t **basic);
void dds3MatterObjectBasicWorkData_t__Clear(dds3MatterObjectBasicWorkData_t *this);
void dds3ObjectBaseCreateMover(dds3Basic_t **pObjectBasic);
void dds3ObjectBaseFreeControlWorkData(dds3ObjectBaseControlWorkData_t **pControl);
dds3ObjectBaseControlWorkData_t *dds3ObjectBaseInitControlWorkData(dds3Basic_t **pObjectBasic);
void dds3ObjectBaseModelLinkOt(sdfModelOt_t *pModelOt, dds3Basic_t **pObjectBasic);
void dds3OffPoseSetFlag(dds3PoseSet_t **pPoseSet, u32 flag);
dds3Basic_t *dds3SearchSceneBasic(dds3Basic_t **pBasic, u32 serialID, u32 type);
void dds3SetPosPoseSet(dds3Basic_t **pBasic, sdfVector4_t pos);
void dds3SetRotPoseSet(dds3Basic_t **pBasic, sdfVector4_t rot);
s32 fldDoor_Step(s32 matter_resid, f32 *x, f32 *y, f32 *z);

// 0x14e9e70
FieldBgHD *GetFHD(void) {
  UnityEngine_Object_o *fldprefab;
  bool v5;
  FieldBgHD_o *result;

  fldprefab = kernelObject->fldprefab;
  v5 = op_Inequality(fldprefab, 0, 0);
  result = 0;
  if (v5)
  {
    return GetComponent_object_(kernelObject->fldprefab);
  }
  return result;
}

// 0x14ea530
dds3Basic_t *dds3AddMatterObjectBasic(u32 serialID, sdfVector4_t pos, sdfVector4_t rot) {
    dds3AddSceneBasicData(0);
    dds3ObjectBaseCreateMover(0);
    dds3SetRotPoseSet(0, (sdfVector4_t){0});
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
    dds3BackupPoseSet(0);
    return 0;
}

// 0x14ea730
void dds3DeleteMatterObjectBasic(dds3Basic_t **aPtr) {
    dds3DeleteSceneBasicData(0);
}

// 0x14e9350
s32 dds3MatterObjectBasicConstructor(dds3Basic_t *aPtr) {
    dds3InitPoseSet(0);
    dds3MatterObjectBasicWorkData_t__Clear(0);
    dds3ObjectBaseInitControlWorkData(0);
    dds3GetBaseControlWorkData(0);
    return 0;
}

// 0x14e9590
s32 dds3MatterObjectBasicDestructor(dds3Basic_t *aPtr) {
    dds3FreePoseSet(0);
    dds3ObjectBaseFreeControlWorkData(0);
    return 0;
}

// 0x14e9f70
s32 dds3MatterObjectBasicDrawProcedure(dds3Basic_t *aPtr) {
    dds3GetBaseControlWorkData(0);
    dds3ObjectBaseModelLinkOt(0, 0);
    return 0;
}

// 0x14eae00
s32 dds3MatterObjectBasicGetAlpMode(dds3Basic_t **aPtr) {
    return 0;
}

// 0x14ea440
dds3ObjectBaseControlWorkData_t *dds3MatterObjectBasicGetControlWorkData(dds3Basic_t **pBasic) {
    return 0;
}

// 0x14ea9b0
s32 dds3MatterObjectBasicGetHojiID(s32 resID) {
    dds3GetControlScene();
    dds3SearchSceneBasic(0, 0, 0);
    return 0;
}

// 0x14e96c0
s32 dds3MatterObjectBasicMainProcedure(dds3Basic_t *aPtr) {
    GetFHD();
    dds3GetBaseControlWorkData(0);
    SetTransparentEvent(0, 0, 0);
    dds3OffPoseSetFlag(0, 0);
    dds3GetRotPoseSet(0);
    SDF_VU0__STOREVECTOR(0);
    dds3GetTMPoseSet(0);
    dds3GetPosPoseSet(0);
    fldDoor_Step(0, 0, 0, 0);
    SDF_VU0__SET_ROW3();
    SDF_VU0__STOREMATRIX(0);
    dds3BackupPoseSet(0);
    return 0;
}

// 0x14eac80
void dds3MatterObjectBasicSetAlpMode(dds3Basic_t **aPtr, s32 alpmode) {
    GetFHD();
    RetTransparent(0);
}

// 0x14ea8b0
void dds3MatterObjectBasicSetHojiID(dds3Basic_t **aPtr, s32 hojiID) {
}

// 0x14ea7b0
void dds3MatterObjectBasicSetOt(dds3Basic_t **aPtr, s32 idx) {
}

// 0x14e9330
void rsetOtOfs(s32 otofs) {
  ;
}

// 0x14e9340
void rsetTest(s32 ate, s32 atst, s32 aref, s32 afail, s32 date, s32 datm, s32 zte, s32 ztst) {
  ;
}
