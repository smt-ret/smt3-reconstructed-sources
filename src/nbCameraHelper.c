#include "types.h"

typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct debug_tag debug_tag;
typedef struct effPartHandle_t effPartHandle_t;
typedef struct effViewer_Menu_Item_t effViewer_Menu_Item_t;
typedef struct effViewer_Menu_t effViewer_Menu_t;
typedef struct nbCameraHelper_effFLWinHandle_t nbCameraHelper_effFLWinHandle_t;
typedef struct nbCameraHelper_effFileListHandle_t nbCameraHelper_effFileListHandle_t;
typedef struct nbCameraHelper_tag nbCameraHelper_tag;
typedef struct sdfFileCmdHandle_t sdfFileCmdHandle_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;

struct nbCameraHelper_tag {
    sdfVector4_t target;
    sdfVector4_t eye;
    sdfVector4_t up;
    s32 frame;
    s32 frameMax;
    effPartHandle_t *hPB;
};

static s32 EFFFILE_TYPE_PB;
static nbCameraHelper_effFileListHandle_t *hNbCameraHelperViewer_PB_FileList;
static nbCameraHelper_effFLWinHandle_t *hNbCameraHelperViewer_PB_FLWin;
static char *pNbCameraHelperViewer_PB_File;
static char *NbCameraHelperViewer_PB_File;
static effViewer_Menu_Item_t nbCameraHelperViewer_PB_Item[UNKNOWN_ARRAY_SIZE];
static effViewer_Menu_t *nbCameraHelperViewer_PB_Menu;
static nbCameraHelper_tag *hNbCameraHelperViewer;
static sdfMemHandle_t *hNbCameraHelperViewerEyeMem;
static sdfVector4_t pNbCameraHelperViewerEye[UNKNOWN_ARRAY_SIZE];
static sdfMemHandle_t *hNbCameraHelperViewerTargetMem;
static sdfVector4_t pNbCameraHelperViewerTarget[UNKNOWN_ARRAY_SIZE];
static u8 nbCameraHelperViewer_Frame;
static u8 nbCameraHelperViewer_Path;

void SDF_VU0__COPYVECTOR_A_TO_B(void);
f32 SDF_VU0__GETLENGTH(void);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__NORMALIZE(void);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
effPartHandle_t *dds3EffectPartCreate(u16 type, void *pData);
void dds3EffectPartDelete(effPartHandle_t **hEffPart);
void dds3EffectPartDraw(effPartHandle_t **hEffPart);
dds3ModelHandle_t *dds3EffectPartGetHandle(effPartHandle_t *hEffPart);
effPartHandle_t *nbCameraHelperFileLoadPB(char **pFilename);
void nbCameraHelperModelSetSub(dds3ModelHandle_t *hModel, u32 target, u32 eye);
void sdfFileClose(sdfFileCmdHandle_t *aHandle);
s32 sdfFileLength(sdfFileCmdHandle_t *aHandle);
sdfFileCmdHandle_t *sdfFileOpen(char *aFileName);
void sdfFileRead(sdfFileCmdHandle_t *aHandle, void *aPtr, s32 aLeng);
debug_tag *sdfMemLock(void *aHandle);
s32 sdfModelGetMarkPosUnity(sdfModelRootNode_t *aRoot, s32 aId);

// 0x1678310
nbCameraHelper_effFileListHandle_t *dds3EffectFileListCreate(u16 dir, s32 type) {
  return 0;
}

// 0x16782b0
void dds3EffectFileListDelete(nbCameraHelper_effFileListHandle_t *a) {
  ;
}

// 0x1678320
nbCameraHelper_effFLWinHandle_t *dds3EffectFileListWindowCreate(nbCameraHelper_effFileListHandle_t *a) {
  return 0;
}

// 0x16782c0
void dds3EffectFileListWindowDelete(nbCameraHelper_effFLWinHandle_t *a) {
  ;
}

// 0x1678280
s32 dds3EffectFileListWindowDraw(nbCameraHelper_effFLWinHandle_t *a) {
  return 0;
}

// 0x16782a0
s32 dds3EffectFileListWindowGetFilename(nbCameraHelper_effFLWinHandle_t *a, u16 b) {
  return 0;
}

// 0x1678290
s32 dds3EffectFileListWindowGetState(nbCameraHelper_effFLWinHandle_t *a) {
  return 0;
}

// 0x16782e0
void dds3EffectFileListWindowSetOt(nbCameraHelper_effFLWinHandle_t *hEffFLWin, s32 ot) {
  ;
}

// 0x16782f0
void dds3EffectFileListWindowSetPadWait(nbCameraHelper_effFLWinHandle_t *hEffFLWin, s32 wait) {
  ;
}

// 0x16782d0
void dds3EffectFileListWindowSetPos(nbCameraHelper_effFLWinHandle_t *a, s32 b, s32 c) {
  ;
}

// 0x1678300
void dds3EffectFileListWindowSetWindowColor(nbCameraHelper_effFLWinHandle_t *hEffFLWin, u32 frame_c, u32 bg_c) {
  ;
}

// 0x1678380
effPartHandle_t *dds3EffectPartCreate(u16 type, void *pData) {
  return 0;
}

// 0x1678330
void effDebugLineDraw2(sdfVector4_t pPos0, sdfVector4_t pPos1, u32 abgr) {
  ;
}

// 0x1678340
void effDebugPointDraw2(sdfVector4_t pPos, u32 color) {
  ;
}

// 0x1678350
void effDebugStringDraw(s32 x, s32 y, s32 attr, char **pString) {
  ;
}

// 0x1678360
u16 mdlGetMotionLength(dds3ModelHandle_t *aHandle) {
  return 0;
}

// 0x1678370
void mdlSingleMotion(dds3ModelHandle_t **aHandle, s32 aGroup, s32 aNumber) {
  ;
}

// 0x1678650
nbCameraHelper_tag *nbCameraHelperCreate(char **pFilename) {
  u64 *v3;
  u64 *v5;

  v3 = Allocate(nbCameraHelper_tag);
  _ctor(v3, 0);
  v3[9] = nbCameraHelperFileLoadPB(pFilename);
  *(v3 + 16) = 0;
  v5 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v5);
  *(v3 + 17) = 0;
  return v3;
}

// 0x16787e0
void nbCameraHelperDelete(nbCameraHelper_tag *hCameraHelper) {
  effPartHandle_t_o **p_hPB;

  p_hPB = &hCameraHelper->hPB;
  dds3EffectPartDelete(p_hPB);
}

// 0x1678390
effPartHandle_t *nbCameraHelperFileLoadPB(char **pFilename) {
    sdfFileOpen(0);
    sdfFileLength(0);
    sdfMemLock(0);
    sdfFileRead(0, 0, 0);
    sdfFileClose(0);
    dds3EffectPartCreate(0, 0);
    return 0;
}

// 0x1678750
u16 nbCameraHelperLength(nbCameraHelper_tag *hCameraHelper) {
  u64 *v2;

  v2 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v2);
    return 0;
  return 0;
}

// 0x1678cd0
void nbCameraHelperModelSet(dds3ModelHandle_t *hModel) {
  nbCameraHelperModelSetSub(hModel, 0, 1u);
}

// 0x1678b20
void nbCameraHelperModelSetSub(dds3ModelHandle_t *hModel, u32 target, u32 eye) {
  struct nbCamera_t_o *nbCameraCurrent;
  sdfModelRootNode_t_o *modelRoot;
  sdfModelRootNode_t_o *v12;

  modelRoot = hModel->modelRoot;
  if (!sdfModelGetMarkPosUnity(modelRoot, target))
  {
    Write(StringLiteral_21153, 0);
  }
  SDF_VU0__STOREVECTOR(&nbCameraCurrent->target);
  v12 = hModel->modelRoot;
  if (!sdfModelGetMarkPosUnity(v12, eye))
  {
    Write(StringLiteral_21154, 0);
  }
  SDF_VU0__COPYVECTOR_A_TO_B();
  SDF_VU0__LOADVECTOR(nbCameraCurrent->target);
  SDF_VU0__SUBVECTOR();
  nbCameraCurrent->distance = SDF_VU0__GETLENGTH();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&nbCameraCurrent->direction);
  nbCameraCurrent->fovy = 0.7854;
}

// 0x1678850
void nbCameraHelperRun(nbCameraHelper_tag *hCameraHelper) {
    dds3EffectPartDraw(0);
    dds3EffectPartGetHandle(0);
    sdfModelGetMarkPosUnity(0, 0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    SDF_VU0__NORMALIZE();
}

// 0x1678f70
void nbCameraHelperViewer_Draw(void *pData) {
  ;
}

// 0x1678f80
void nbCameraHelperViewer_End(void *pData) {
  ;
}

// 0x1678f60
void *nbCameraHelperViewer_Init(void *pData) {
  return 0;
}

// 0x1678e80
void nbCameraHelperViewer_PB_Draw(void *pData) {

}

// 0x1678ef0
void nbCameraHelperViewer_PB_End(void *pData) {

}

// 0x1678d40
void *nbCameraHelperViewer_PB_Init(void *pData) {
    return 0;
}
