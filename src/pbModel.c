#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct FieldChrHD FieldChrHD;
typedef struct ModelHD ModelHD;
typedef struct XRD773Unity_CommonMesh XRD773Unity_CommonMesh;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct pbProcHandle_t pbProcHandle_t;
typedef struct sdfModelOt_t sdfModelOt_t;

static f32 dir_rot[4];
static XRD773Unity_CommonMesh *pMesh;
static sdfVector3_t pMeshPos;
static sdfVector3_t r_cameraPos;
static sdfVector3_t r_cameraQuakePos;
static void *m_colorTex;
static void *m_depthTex;
static void *m_postRenderMat;
static s32 pbStartCameraPosflag;
static s32 pbChangeInitPosflag;
static s32 P_DrawCnt;
static bool ScaleCharflag;
static void *pModelObj;
static void *childobj;
static sdfVector3_t pbCameraPos[4];
static sdfVector3_t pbcCameraPos[4];
static sdfVector3_t pbBGAngle[4];
static sdfVector3_t pbcBGAngle[4];
static void *rCameraObj;
static void *r_camera;
static void *pbCameraObj;
static void *pb_camera;
static sdfVector3_t pbBGPos[4];

void FromEuler(f32 aRotateX, f32 aRotateY, f32 aRotateZ);
void *GetMainCamera(dds3DefaultMain *this);
void *GetRenderCamera(dds3DefaultMain *this);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SetFrameAnime(ModelHD *this, bool act);
void StepFrame(ModelHD *this);
f32 dds3GetRandFloatA(char *name);
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
void dds3SetProcessData(dds3ProcessID_t **id, void *data);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void fldDrawMaruKage(f32 x, f32 y, f32 z, f32 r, s32 a);
void mdlFree(dds3ModelHandle_t **aHandle);
void mdlGetPosition(dds3ModelHandle_t **aHandle);
void mdlGetRotate(dds3ModelHandle_t **aHandle);
void mdlLinkSub(dds3ModelHandle_t **aHandle, sdfModelOt_t **aModelOt, void *modelobj, bool camera_identity);
dds3ModelHandle_t *mdlLoad(s32 aMajor, s32 aMinor, u8 **byteData, s32 bPos);
void mdlLoopMotion(dds3ModelHandle_t **aHandle, s32 aGroup, s32 aNumber);
void mdlSetEffectScale(dds3ModelHandle_t **aHandle, f32 aScale);
FieldChrHD *mdlSetHD(void *obj, s32 mode, evtUnitHandle_t *hunit, s32 layer);
void mdlSetPosition(dds3ModelHandle_t **aHandle);
void mdlSetRotate(dds3ModelHandle_t **aHandle);
void mdlSetScale(dds3ModelHandle_t **aHandle);
void *pbGetMyCharRootNode(pbProcHandle_t **p);

// 0x14aed30
dds3ProcessFunc_t *deleteMyCharacter(dds3ProcessID_t *id) {
    mdlFree(0);
    return 0;
}

// 0x14ac7d0
dds3ProcessFunc_t *drawMyCharacter(dds3ProcessID_t *id) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    mdlSetPosition(0);
    StepFrame(0);
    mdlLinkSub(0, 0, 0, 0);
    mdlGetPosition(0);
    SDF_VU0__STOREVECTOR(0);
    fldDrawMaruKage(0, 0, 0, 0, 0);
    GetMainCamera(0);
    GetRenderCamera(0);
    dds3GetRandFloatA(0);
    return 0;
}

// 0x14afd60
void pbChangeMotion(pbProcHandle_t **p, u32 num) {
  ;
}

// 0x14afd70
void pbChangeMotion2(pbProcHandle_t **p, u32 num, f32 st, f32 total) {
  ;
}

// 0x14afc50
void pbDispMyCharacter(pbProcHandle_t **p, s8 sw) {
}

// 0x14aef10
void pbGetModelPos(dds3ModelHandle_t *aHandle, sdfVector4_t *pos) {
  dds3ModelHandle_t_o *aHandlea;

  aHandlea = aHandle;
  mdlGetPosition(&aHandlea);
  SDF_VU0__STOREVECTOR(pos);
}

// 0x14aefa0
void pbGetModelRot(dds3ModelHandle_t *aHandle, sdfVector4_t *rot) {
  dds3ModelHandle_t_o *aHandlea;

  aHandlea = aHandle;
  mdlGetRotate(&aHandlea);
  SDF_VU0__STOREVECTOR(rot);
}

// 0x14af0e0
void pbGetModelScl(dds3ModelHandle_t *aHandle, sdfVector4_t *scl) {
  ;
}

// 0x14afd80
u32 pbGetMotion(pbProcHandle_t **p) {
  return 0;
}

// 0x14afa40
void *pbGetMyCharRootNode(pbProcHandle_t **p) {
    return 0;
}

// 0x14b0160
void pbGetMyCharcterPos(pbProcHandle_t **p, sdfVector4_t *pos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x14b0280
void pbGetMyCharcterPos2(pbProcHandle_t **p, s16 *x, s16 *y) {
}

// 0x14b03a0
s32 pbGetMyCharcterRot(pbProcHandle_t **p) {
    return 0;
}

// 0x14af100
pbProcHandle_t *pbInitMyCharacterDraw(pbProcHandle_t **parent, u32 col, u32 motion) {
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
    dds3LinkProcess(0, 0);
    dds3SetProcessData(0, 0);
    mdlLoad(0, 0, 0, 0);
    mdlLoopMotion(0, 0, 0);
    LoadPrefab_16624656(0, 0, 0, 0);
    mdlSetHD(0, 0, 0, 0);
    SetFrameAnime(0, 0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    mdlSetScale(0);
    mdlSetEffectScale(0, 0);
    return 0;
}

// 0x14afd90
void pbMoveMyCharcter(pbProcHandle_t **p, f32 x, f32 y) {
}

// 0x14afee0
void pbMoveMyCharcter2(pbProcHandle_t **p, s16 x, s16 y) {
}

// 0x14afb40
u32 pbMyCharacterDispStat(pbProcHandle_t **p) {
    return 0;
}

// 0x14aeca0
void pbSetModelPos(dds3ModelHandle_t *aHandle, sdfVector4_t *pos) {
  dds3ModelHandle_t_o *aHandlea;

  aHandlea = aHandle;
  SDF_VU0__LOADVECTOR(*pos);
  mdlSetPosition(&aHandlea);
}

// 0x14af030
void pbSetModelRot(dds3ModelHandle_t *aHandle, f32 x, f32 y, f32 z) {
  dds3ModelHandle_t_o *aHandlea;

  aHandlea = aHandle;
  FromEuler(x, y, z);
  mdlSetRotate(&aHandlea);
}

// 0x14af0f0
void pbSetModelScl(dds3ModelHandle_t *aHandle, sdfVector4_t *scl) {
  ;
}

// 0x14b0000
void pbSetMyCharcterPos2(pbProcHandle_t **p, s16 x, s16 y) {
}

// 0x14b04b0
void pbSetMyCharcterRot(pbProcHandle_t **p, s32 dir) {
    pbGetMyCharRootNode(0);
    FromEuler(0, 0, 0);
    mdlSetRotate(0);
}

// 0x14ac7c0
void sdfChipFreeDelayed(void *aPtr) {
  ;
}
