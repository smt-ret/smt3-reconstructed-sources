#include "types.h"

typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct pbBackup_t pbBackup_t;
typedef struct pbMenu_menuFuncDelegate pbMenu_menuFuncDelegate;
typedef struct pbMenu_requireFuncDelegate pbMenu_requireFuncDelegate;
typedef struct pbMenu_t pbMenu_t;
typedef struct pbProcHandle_t pbProcHandle_t;
typedef struct sdfFileCmdHandle_t sdfFileCmdHandle_t;

struct pbMenu_t {
    u32 mode;
};

static char *mapname;
static u8 mapname_a;
static s32 map_num;
static s32 mstrCnr;
static char *mstr[4];
static char *mstr_K[4];
static s32 dirCreateMode;
static u8 menu;
static u8 menuCsr;
static u16 fileName_a[64];
static u8 fileName[64];
static u8 userfileNum;
static u8 systemfileNum;
static s8 fileEnd;
static u8 menuMax[2];
static pbMenu_requireFuncDelegate *requireFunc[2];
static pbMenu_menuFuncDelegate *menuFunc[2];
static s32 mcPort;
static s32 mcSlot;

void ButtonGuideDispOff(void);
void ButtonGuideDispSet(char *name, bool timer, bool empty, s32 waitTimer);
bool DDS3_PADCHECK_REP(s32 id);
bool DDS3_PADCHECK_TRIG(s32 id);
s32 FindId(s32 type, char *name);
char *GetLocalizeText(char *ID);
s32 GetStageNumber(void);
void *GetoPB_UI(void);
char *RepColTag(char *txt, void **LegacyParamArray);
void dds3AdminiCallSequence(s32 sequence, void *data, s32 datasize, s32 restore);
void dds3FadeOut(u32 r, u32 g, u32 b, u32 frame);
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
void dds3ResetProcessFlag(dds3ProcessID_t **target, u32 flag, s32 type);
dds3ProcessID_t *dds3SearchProcessName(char *namestr);
void dds3SetProcessData(dds3ProcessID_t **id, void *data);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
s32 p2sdPlaySE(s32 a);
void pbBackup_t__pCopy(pbBackup_t *this, u8 **bytedata, s32 *bpos);
u32 pbCheckMap(void);
s8 pbCheckPreviousRecord(void);
void pbLoadSystemData(s32 num);
void pbPreviousRecord(void);
void pbSetGameCamera0(void);
dds3ProcessID_t *pbStartGiveupConfirm(void);
pbProcHandle_t *pbStartHelp(pbProcHandle_t *parent, u32 page);
pbProcHandle_t *pbWaitLoadMapData(pbProcHandle_t *parent);
void *sdfDevLoadFileUnity_25061072(char *aFilename, u8 ***aTopPtr, s32 aSizePtr, char *akey);

// 0x14aa100
dds3ProcessFunc_t *deleteMenu(dds3ProcessID_t *id) {
    GetoPB_UI();
    return 0;
}

// 0x14aa6c0
dds3ProcessFunc_t *deleteWaitLoadEnd(dds3ProcessID_t *id) {
  return 0;
}

// 0x14a7ba0
void exitGame(pbProcHandle_t **p) {
  pbProcHandle_t_o *v4;

  pbStartGiveupConfirm();
  v4 = *p;
  else if (!v4)
  {
    return;
  }
  v4->mes = 327680;
}

// 0x14a7a30
void exitPB(pbProcHandle_t **p) {
  pbProcHandle_t_Fields *p_fields;
  struct pbProcHandle_t_o *current_proc;

  pbSetGameCamera0();
  p_fields = &(*p)->fields;
  dds3ResetProcessFlag(&p_fields->id, 0x10u, 1);
  if (current_proc)
    current_proc->mes = 393216;
  dds3AdminiCallSequence(0, 0, 0, 0);
}

// 0x14a6af0
void fileCallback(sdfFileCmdHandle_t *aHandle, s32 aCause, void *aBuffer, s32 aLength, void *aUserData) {
  char v8;

  if (aCause)
  {
    if (aCause != 8)
      return;
    v8 = 1;
  }
  else
  {
    v8 = -1;
  }
  fileEnd = v8;
}

// 0x14a6ba0
s8 generalReq_OK(pbProcHandle_t **p) {
  return 1;
}

// 0x14a7c40
void help(pbProcHandle_t **p) {
    pbStartHelp(0, 0);
    dds3SearchProcessName(0);
    ButtonGuideDispSet(0, 0, 0, 0);
}

// 0x14a75b0
void load(pbProcHandle_t **p) {
    dds3FadeOut(0, 0, 0, 0);
    pbWaitLoadMapData(0);
}

// 0x14a78f0
void loadSystemData(pbProcHandle_t **p) {
    dds3FadeOut(0, 0, 0, 0);
    pbWaitLoadMapData(0);
}

// 0x14a7a10
void mcLoad(pbProcHandle_t **p) {
  ;
}

// 0x14a7a20
void mcSave(pbProcHandle_t **p) {
  ;
}

// 0x14a82e0
dds3ProcessFunc_t *menuProc(dds3ProcessID_t *id) {
    GetoPB_UI();
    GetLocalizeText(0);
    RepColTag(0, 0);
    DDS3_PADCHECK_TRIG(0);
    FindId(0, 0);
    p2sdPlaySE(0);
    DDS3_PADCHECK_REP(0);
    return 0;
}

// 0x14a7280
void pbLoadSystemData(s32 num) {
    dds3FadeOut(0, 0, 0, 0);
    sdfDevLoadFileUnity_25061072(0, 0, 0, 0);
    pbBackup_t__pCopy(0, 0, 0);
    pbWaitLoadMapData(0);
}

// 0x14aa700
pbProcHandle_t *pbStartMenu(pbProcHandle_t **parent, u32 mode) {
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
    dds3LinkProcess(0, 0);
    dds3SetProcessData(0, 0);
    return 0;
}

// 0x14a76d0
pbProcHandle_t *pbWaitLoadMapData(pbProcHandle_t *parent) {
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
    dds3LinkProcess(0, 0);
    dds3SetProcessData(0, 0);
    return 0;
}

// 0x14a74b0
void previous(pbProcHandle_t **p) {
  pbPreviousRecord();
  pbBlkDalateflag = 1;
  mBlk_Resetflag = 1;
  StageDrawflag = 0;
  MRBlockDrawflag = 0;
  OutLineMDraw = 1;
  RBlockOutCnt = 0;
  MBlockOutCnt = 0;
}

// 0x14a6c20
s8 previousReq(pbProcHandle_t **p) {
    return pbCheckPreviousRecord();
  return pbCheckPreviousRecord();
}

// 0x14a6ef0
void reTry(pbProcHandle_t **p) {
  s32 StageNumber;
  pbProcHandle_t_o *v6;
  s64 v8;
  s32 v9;
  u64 v10;
  struct XRD773Unity_CommonMesh_array *pBlk_Mesh;
  UnityEngine_Object_o *v13;
  struct XRD773Unity_CommonMesh_array *v16;
  UnityEngine_Object_o *gameObject;
  struct XRD773Unity_CommonMesh_array *pMRBlk_Mesh;
  UnityEngine_Object_o *v23;
  struct XRD773Unity_CommonMesh_array *v25;
  UnityEngine_Object_o *v28;
  u32 v29;
  UnityEngine_Object_o *v32;

  StageNumber = GetStageNumber();
  pbLoadSystemData(StageNumber);
  v6 = *p;
  if (v6)
    v6->mes = 327680;
  v8 = 4;
  do
  {
    v10 = v8 - 4;
    v13 = *(&pBlk_Mesh->obj.klass + v8);
    if (op_Inequality(v13, 0, 0))
    {
      v16 = pBlk_Mesh;
      gameObject = get_gameObject(*(&v16->obj.klass + v8), 0);
      Destroy_27360000(gameObject);
    }
    v23 = *(&pMRBlk_Mesh->obj.klass + v8);
    if (op_Inequality(v23, 0, 0))
    {
      v25 = pMRBlk_Mesh;
      v28 = get_gameObject(*(&v25->obj.klass + v8), 0);
      Destroy_27360000(v28);
    }
    ++v8;
    v9 = (v29 >> 9) & 1;
  }
  while (v8 != 404);
  outlineDrawflag = 1;
  OutLineFDraw = 0;
  mBlkStageChangeflag = 1;
  ButtonGuideDispOff();
  v32 = Find(StringLiteral_21771, 0);
  Destroy_27360000(v32);
}

// 0x14a8150
void save(pbProcHandle_t *p) {
  u64 *v2;
  pbMenu_c *v4;
  s16 v5;
  s32 v6;
  struct pbMenu_StaticFields *static_fields;
  Il2CppObject *p_obj;

  v2 = Allocate(pbMenu_sce_stat);
  _ctor(v2, 0);
  if ((v5 & 0x200) == 0)
  v6 = v5 & 0x200;
  {
    v6 = 0;
    static_fields = v4->static_fields;
    if (static_fields->menu == 1)
  }
  static_fields = pbMenu->static_fields;
  if (static_fields->menu == 1)
  {
    p_obj = &static_fields->fileName->obj;
    Write_2930400(StringLiteral_21855, p_obj);
    return;
  }
  static_fields->menu = 1;
}

// 0x14a7eb0
void save_clbk(sdfFileCmdHandle_t *aHandle, s32 aCause, void *aBuffer, s32 aLength, void *aUserData) {
}

// 0x14a6ac0
s32 sceGetstat(char *a, void *b) {
  return 0;
}

// 0x14a6ad0
s32 sceMkdir(char *a, s32 b) {
  return 0;
}

// 0x14a6ae0
void sdfChipFreeDelayed(void *aPtr) {
  ;
}

// 0x14a7ea0
s8 searchFileMC(u32 fileIdx) {
  return 0;
}

// 0x14a6c90
void toGame(pbProcHandle_t **p) {
  pbProcHandle_t_Fields *p_fields;
  struct pbProcHandle_t_o *current_proc;

  else if (pbCheckMap())
  {
    return;
  }
  dds3FadeOut(0, 0, 0, 1u);
  p_fields = &(*p)->fields;
  dds3ResetProcessFlag(&p_fields->id, 0x10u, 1);
  if (current_proc)
  {
    current_proc->mes = 262145;
  }
}

// 0x14a6bb0
s8 toGameReq(pbProcHandle_t **p) {
  return pbCheckMap() == 0;
}

// 0x14aa340
dds3ProcessFunc_t *waitLoadEnd(dds3ProcessID_t *id) {
    dds3ResetProcessFlag(0, 0, 0);
    return 0;
}
