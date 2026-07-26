#include "types.h"

typedef struct XRD773Unity_GraphicManager XRD773Unity_GraphicManager;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3Effect_PartialMultiBlurParam_t dds3Effect_PartialMultiBlurParam_t;
typedef struct dds3Effect_PartialMultiBlur_t dds3Effect_PartialMultiBlur_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;

static dds3Effect_PartialMultiBlurParam_t *fldEncBlurBuff;
static dds3Effect_PartialMultiBlur_t *fldEncBlurHdl;
static s32 gencMode;
static s32 gencStageInnAlp;
static s32 gencStageOutCnt;
static s32 gencOn;
static f32 gencScale;
static f32 gencArea;
static bool gencIsRandomEncount;

void Continue(XRD773Unity_GraphicManager *this);
void FieldFilterOff(dds3DefaultMain *this);
void FieldFilterOn(dds3DefaultMain *this);
void dds3EffectEncountBlur(void);
void dds3EffectEncountBlur1(f32 scale, f32 area);
void dds3EffectEncountBlur2(void);
void dds3EffectEncountBlur3(s32 alp);
dds3Basic_t *dds3GetActiveScene(void);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void dds3VisibleSceneBasic(dds3Basic_t **basic, s32 visible);

// 0x103a7b0
s32 encChk(void) {
  return gencOn;
}

// 0x103a900
void *encDrawProc(dds3ProcessID_t *aProcId) {
    FieldFilterOff(0);
    dds3EffectEncountBlur();
    dds3EffectEncountBlur1(0, 0);
    dds3EffectEncountBlur2();
    dds3EffectEncountBlur3(0);
    FieldFilterOn(0);
    return 0;
}

// 0x103af70
void encInitProcess(void) {
  u64 *v1;

  v1 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v1,
    0,
    Method_fldEnc_encDrawProc__);
  dds3StartProcess(StringLiteral_16608, 0x2B0Fu, 0, 1, v1, 0, 0, 0, 0, 0);
}

// 0x103a820
void encMode(s32 mode) {
  gencMode = mode;
}

// 0x103a890
s32 encModeGet(void) {
  return gencMode;
}

// 0x103ad60
void encStart(bool bRandomEncount) {
  struct fldEnc_StaticFields **p_static_fields;
  struct fldEnc_StaticFields *static_fields;
  XRD773Unity_GraphicManager_o *Instance;
  dds3Basic_t_o *basic;

  basic = 0;
  else
  {
    p_static_fields = &fldEnc->static_fields;
    static_fields = fldEnc->static_fields;
    if (static_fields->gencOn)
      return;
  }
  static_fields->gencMode = 0;
  (*p_static_fields)->gencStageOutCnt = 0;
  (*p_static_fields)->gencStageInnAlp = 128;
  (*p_static_fields)->gencScale = 1.02;
  (*p_static_fields)->gencArea = 300.0;
  {
  }
  Instance = get_Instance();
  Continue(Instance);
  dds3EffectEncountBlur();
  gencOn = 1;
  gencIsRandomEncount = bRandomEncount;
  basic = dds3GetActiveScene();
  if (basic)
  {
    dds3VisibleSceneBasic(&basic, 0);
  }
}

// 0x103a740
void encStop(void) {
  gencOn = 0;
}
