#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ObjectBaseControlWorkData_t dds3ObjectBaseControlWorkData_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct fldResourceLightPath_t fldResourceLightPath_t;
typedef struct fldResourceLight_t fldResourceLight_t;

void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__COPYVECTOR_A_TO_B(void);
void SDF_VU0__COPYVECTOR_A_TO_C(void);
void SDF_VU0__COPYVECTOR_C_TO_A(void);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__SCALEVECTOR(f32 v);
void SDF_VU0__SCALEVECTOR_B(f32 v);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__STOREVECTOR_B(sdfVector4_t *p);
u32 SDF_VU0__dds3ColorFtoI(f32 ratio);
void SDF_VU0__dds3ColorItoF(u32 rgba);
dds3Basic_t *dds3AddSceneBasicData(u32 type);
void dds3DeleteSceneBasicData(dds3Basic_t **basic);
void dds3FreePoseSet(dds3Basic_t **basic);
dds3ObjectBaseControlWorkData_t *dds3GetBaseControlWorkData(dds3Basic_t **pObjectBasic);
s32 dds3InitPoseSet(dds3Basic_t **basic);
void dds3ObjectBaseCreateMover(dds3Basic_t **pObjectBasic);
void dds3ObjectBaseFreeControlWorkData(dds3ObjectBaseControlWorkData_t **pControl);
dds3ObjectBaseControlWorkData_t *dds3ObjectBaseInitControlWorkData(dds3Basic_t **pObjectBasic);
void evtLinkLightObjectBasic(evtUnitHandle_t **h, dds3Basic_t **light, s32 frame);
void evtUnlinkLightObjectBasic(evtUnitHandle_t **h, s32 frame);

// 0x14e5d30
dds3Basic_t *dds3AddLightObjectBasic(u32 serial) {
  dds3Basic_t_o *pObjectBasic;

  pObjectBasic = 0;
  pObjectBasic = dds3AddSceneBasicData(9u);
  pObjectBasic->serialID = serial;
  dds3ObjectBaseCreateMover(&pObjectBasic);
  return pObjectBasic;
}

// 0x14e6070
void dds3DeleteLightObjectBasic(dds3Basic_t **basic) {
    dds3DeleteSceneBasicData(0);
}

// 0x14e5c40
dds3ObjectBaseControlWorkData_t *dds3LightObjectBasicGetControlWorkData(dds3Basic_t **basic) {
    return 0;
}

// 0x14e65c0
void dds3LinkLightObjectToUnitObject(dds3Basic_t **lightbasic, dds3Basic_t **unitbasic, u32 frame) {
    evtLinkLightObjectBasic(0, 0, 0);
}

// 0x14e6300
void dds3LinkSceneLight(dds3Basic_t **basic, u32 frame) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__dds3ColorFtoI(0);
}

// 0x14e6a30
void dds3SetLightObjectPathResoruce(dds3Basic_t **basic, fldResourceLightPath_t *resource) {
}

// 0x14e6830
void dds3SetLightObjectResoruce(dds3Basic_t **basic, fldResourceLight_t *resource) {
}

// 0x14e6700
void dds3UnlinkLightObjectFromUnitObject(dds3Basic_t **unitbasic, u32 frame) {
    evtUnlinkLightObjectBasic(0, 0);
}

// 0x14e64d0
void dds3UnlinkSceneLight(dds3Basic_t **basic) {
}

// 0x14e5160
s32 lightconstructor(dds3Basic_t *basic) {
    dds3InitPoseSet(0);
    dds3ObjectBaseInitControlWorkData(0);
    dds3GetBaseControlWorkData(0);
    return 0;
}

// 0x14e5610
s32 lightdestructor(dds3Basic_t *basic) {
    dds3ObjectBaseFreeControlWorkData(0);
    dds3FreePoseSet(0);
    return 0;
}

// 0x14e5c30
s32 lightdrawprocedure(dds3Basic_t *basic) {
  return 1;
}

// 0x14e5920
s32 lightmainprocedure(dds3Basic_t *basic) {
    SDF_VU0__dds3ColorItoF(0);
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SCALEVECTOR_B(0);
    SDF_VU0__ADDVECTOR();
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__dds3ColorFtoI(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__COPYVECTOR_C_TO_A();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__STOREVECTOR_B(0);
    return 0;
}
