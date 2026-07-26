#include "types.h"

typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct dds3StartMenuDisp dds3StartMenuDisp;
typedef struct dds3StartMenu_menu_s dds3StartMenu_menu_s;
typedef struct dds3StartMenu_menu_s_funcDelegate dds3StartMenu_menu_s_funcDelegate;

struct dds3StartMenu_menu_s {
    char *name;
    dds3StartMenu_menu_s_funcDelegate *func;
    s32 noend;
    s32 effidx;
};

static dds3StartMenuDisp *dispobj;
static s32 InitGameStartProcess_boot;
static s32 dbg_eff_cut[2];
static s32 dbg_draw_stop1;
static s32 dbg_arrow_hdr;
static f32 dbg_camfar;
static s32 dbg_effresolution;
static s32 cursor;
static dds3StartMenu_menu_s *menu[25];

bool DDS3_PADCHECK_REP(s32 id);
void *GetMainCamera(dds3DefaultMain *this);
char *PlStr(void);
void SetCameraArrow(dds3DefaultMain *this, bool hdr, bool msaa);
void SetCameraFar(dds3DefaultMain *this, f32 far);
void dds3AdminiCallSequence(s32 sequence, void *data, s32 datasize, s32 restore);
s32 dds3SelectMenu(s32 pad, s32 listsx, s32 listsy, s32 winsx, s32 winsy, s32 *basex, s32 *basey, s32 *x, s32 *y);

// 0x14ffdb0
u32 DbgEffPCPFlashCut(u32 number) {
  struct System_Int32_array *dbg_eff_cut;
  struct System_Int32_array *v7;

  if (dbg_eff_cut->m_Items[1] != 100)
  {
    v7 = dbg_eff_cut;
    return v7->m_Items[1] * number / 0x64;
  }
  return number;
}

// 0x14ffec0
void InitArrowHdrProcess(void) {
  dds3StartMenu_c *v2;
  struct dds3StartMenu_StaticFields *static_fields;
  dds3DefaultMain_o *kernelObject;
  bool v6;

  dbg_arrow_hdr = (dbg_arrow_hdr & 1) == 0;
  static_fields = v2->static_fields;
  if (static_fields->dbg_arrow_hdr)
  {
    v6 = 0;
  }
  else
  {
    v6 = 1;
  }
  SetCameraArrow(kernelObject, v6, 1);
}

// 0x14ffa00
void InitBattleFieldTestProcess(void) {
  dds3AdminiCallSequence(21, 0, 0, 0);
}

// 0x14fffa0
void InitCameraFarProcess(void) {
  dds3DefaultMain_o *kernelObject;

  SetCameraFar(kernelObject, dbg_camfar);
}

// 0x14ffab0
void InitCampTestProcess(void) {
  dds3AdminiCallSequence(27, 0, 0, 0);
}

// 0x14ffad0
void InitCombineTestProcess(void) {
  dds3AdminiCallSequence(28, 0, 0, 0);
}

// 0x14ffeb0
void InitDrawStop1Process(void) {
  ;
}

// 0x14ffda0
void InitEffCutProcess(void) {
  ;
}

// 0x1500040
void InitEffResolution(void) {
  dbg_effresolution = (dbg_effresolution & 1) == 0;
}

// 0x1500170
void InitEndSaveProcess(void) {
  ;
}

// 0x14ffa40
void InitEventTestProcess(void) {
  dds3AdminiCallSequence(23, 0, 0, 0);
}

// 0x14ffa60
void InitEventViewerProcess(void) {
  dds3AdminiCallSequence(24, 0, 0, 0);
}

// 0x14ffa80
void InitFieldProcess(void) {
  ;
}

// 0x15000c0
void InitFontTestProcess(void) {
  dds3AdminiCallSequence(38, 0, 0, 0);
}

// 0x14ff8b0
void InitGameStartProcess(void) {
  InitGameStartProcess_boot = 0;
  if (InitGameStartProcess_boot)
  {
    dds3AdminiCallSequence(1, 0, 0, 0);
    InitGameStartProcess_boot = 0;
  }
  else
  {
    dds3AdminiCallSequence(2, 0, 0, 0);
  }
}

// 0x14ffa20
void InitKernelTestProcess(void) {
  dds3AdminiCallSequence(22, 0, 0, 0);
}

// 0x14ffa90
void InitMesScriptTestProcess(void) {
  dds3AdminiCallSequence(26, 0, 0, 0);
}

// 0x15001a0
void InitModeSelectProcess(void) {
  dds3AdminiCallSequence(42, 0, 0, 0);
}

// 0x14ffbb0
void InitModelViewerProcess(void) {
  dds3AdminiCallSequence(35, 0, 0, 0);
}

// 0x14ffbd0
void InitMovieViewerProcess(void) {
  dds3AdminiCallSequence(41, 0, 0, 0);
}

// 0x14ffb90
void InitNameTestProcess(void) {
  dds3AdminiCallSequence(34, 0, 0, 0);
}

// 0x14ff980
void InitNewBattleTestProcess(void) {
  fldBattleData.encountpack = -1;
  dds3AdminiCallSequence(20, 0, 0, 0);
}

// 0x1500180
void InitPipeProcess(void) {
  dds3AdminiCallSequence(19, 0, 0, 0);
}

// 0x14ffc30
void InitPostProcessLayerProcess(void) {
  UnityEngine_GameObject_o *MainCamera;
  Il2CppObject *Component_object;
  UnityEngine_Behaviour_o *v5;
  bool v6;

  MainCamera = GetMainCamera(kernelObject);
  Component_object = GetComponent_object_(MainCamera);
  if (get_enabled(Component_object))
  {
    v5 = Component_object;
    v6 = 0;
  }
  else
  {
    v5 = Component_object;
    v6 = 1;
  }
  set_enabled(v5, v6);
}

// 0x15000e0
void InitPuzzleBoyGame(void) {
  dds3AdminiCallSequence(39, 0, 0, 0);
}

// 0x14ffb10
void InitRagTestProcess(void) {
  dds3AdminiCallSequence(30, 0, 0, 0);
}

// 0x14ffb30
void InitRecoverTestProcess(void) {
  dds3AdminiCallSequence(31, 0, 0, 0);
}

// 0x14ffb70
void InitResult2TestProcess(void) {
  dds3AdminiCallSequence(33, 0, 0, 0);
}

// 0x14ffaf0
void InitShopTestProcess(void) {
  dds3AdminiCallSequence(29, 0, 0, 0);
}

// 0x14ffbf0
void InitSndPtnProcess(void) {
  dds3AdminiCallSequence(44, 0, 0, 0);
}

// 0x14ffc10
void InitSoundTestProcess(void) {
  dds3AdminiCallSequence(36, 0, 0, 0);
}

// 0x1500100
void InitStaffTestProcess(void) {
    dds3AdminiCallSequence(0, 0, 0, 0);
}

// 0x14ffb50
void InitTerminalTestProcess(void) {
  dds3AdminiCallSequence(32, 0, 0, 0);
}

// 0x15001c0
void InitTgsProcess(void) {
  dds3AdminiCallSequence(43, 0, 0, 0);
}

// 0x14ffcf0
char *PlStr(void) {
  UnityEngine_GameObject_o *MainCamera;
  Il2CppObject *Component_object;
  bool enabled;
  s64 *v6;

  MainCamera = GetMainCamera(kernelObject);
  Component_object = GetComponent_object_(MainCamera);
  enabled = get_enabled(Component_object);
  v6 = &StringLiteral_12383;
  if (!enabled)
    v6 = &StringLiteral_12189;
  return *v6;
}

// 0x15001e0
void *dds3StartMenuProcess(dds3ProcessID_t *id) {
    PlStr();
    dds3SelectMenu(0, 0, 0, 0, 0, 0, 0, 0, 0);
    DDS3_PADCHECK_REP(0);
    return 0;
}
