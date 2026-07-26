#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct AssetBundles AssetBundles;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct fldTitleName fldTitleName;
typedef struct sdfTexHandle_t sdfTexHandle_t;

static s32 gfldTitleCnt;
static s32 gfldTitleStep;
static s32 gfldTitleID;
static s32 gfldTitleWait;
static bool gfldTitleDelete;
static sdfTexHandle_t *hFldTitleName;
static sdfTexHandle_t *hFldTitle01;
static sdfTexHandle_t *hFldTitle02;
static sdfTexHandle_t *hFldTitle03;
static s32 gfldTitleMiniCnt;
static s32 gfldTitleMiniStep;
static s32 gfldTitleMiniID;
static bool gfldTitleMiniDelete;
static sdfTexHandle_t *hFldTitleMiniName;
static sdfTexHandle_t *hFldTitleMini04;
static void *tit_obj;
static fldTitleName *tit_scr;
static char *langTbl[8];

s32 GetLanguage(void);
bool IsDLCField(s32 area);
bool IsFinished(fldTitleName *this);
bool IsFinishedMini(fldTitleName *this);
bool IsLoad(AssetBundles *this, char *key);
void LoadAssetExt(char *key, char *name, char *dlc);
void *LoadFile(AssetBundleCtrl *this, char *key, char *path, char *name, char *extension);
void **LoadSprite(AssetBundleCtrl *this, char *key, char *path, char *name);
void SetSprite(fldTitleName *this, bool amara, void **a, void **b);
void StartAnim(fldTitleName *this, bool in1st, s32 timer);
dds3ProcessID_t *dds3SearchProcessName(char *namestr);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
bool evtBitCheck(s32 no);
void evtBitOn(s32 no);

// 0x178ea30
s32 fldTitleChk(void) {
  return dds3SearchProcessName(StringLiteral_16661) != 0;
}

// 0x178eab0
void *fldTitleDrawProc(dds3ProcessID_t *aProcId) {
    GetLanguage();
    LoadSprite(0, 0, 0, 0);
    SetSprite(0, 0, 0, 0);
    IsDLCField(0);
    IsLoad(0, 0);
    LoadAssetExt(0, 0, 0);
    IsFinished(0);
    StartAnim(0, 0, 0);
    return 0;
}

// 0x178f720
s32 fldTitleMiniChk(void) {
  return dds3SearchProcessName(StringLiteral_16662) != 0;
}

// 0x178f7a0
dds3ProcessFunc_t *fldTitleMiniDrawProc(dds3ProcessID_t *aProcId) {
    IsDLCField(0);
    IsLoad(0, 0);
    LoadAssetExt(0, 0, 0);
    GetLanguage();
    LoadSprite(0, 0, 0, 0);
    SetSprite(0, 0, 0, 0);
    StartAnim(0, 0, 0);
    IsFinishedMini(0);
    return 0;
}

// 0x178fdc0
dds3ProcessFunc_t *fldTitleMiniShutDown(dds3ProcessID_t *id) {
  UnityEngine_Object_o *tit_obj;
  UnityEngine_Object_o *v6;
  fldTitle_c *v7;
  struct fldTitle_StaticFields *static_fields;
  struct fldTitle_StaticFields *v9;

  if (op_Inequality(tit_obj, 0, 0))
  {
    v6 = tit_obj;
    Destroy_27360000(v6);
  }
  static_fields = v7->static_fields;
  if (static_fields->hFldTitleMiniName)
  {
    static_fields->hFldTitleMiniName = 0;
  }
  v9 = v7->static_fields;
  if (v9->hFldTitleMini04)
  {
    v9->hFldTitleMini04 = 0;
  }
  return 0;
}

// 0x178ff40
void fldTitleMiniStart(s32 fld) {
    evtBitCheck(0);
    evtBitOn(0);
    LoadFile(0, 0, 0, 0, 0);
    IsDLCField(0);
    IsLoad(0, 0);
    LoadAssetExt(0, 0, 0);
    dds3SearchProcessName(0);
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
}

// 0x17908a0
void fldTitleMiniStart2(void) {
  fldTitle_c *v2;
  struct fldTitle_StaticFields *static_fields;
  s32 gfldTitleMiniID;
  s32 fieldID;
  struct fldTitle_StaticFields *v7;

  static_fields = fldTitle->static_fields;
  if (static_fields->gfldTitleMiniStep != 3)
  gfldTitleMiniID = static_fields->gfldTitleMiniID;
  fieldID = fldGb->fieldID;

  {
    gfldTitleMiniID = fieldID;
    if ((v2->_2.bitflags2 & 2) == 0)
    {
      v7 = v2->static_fields;
      if (v7->gfldTitleMiniStep != 4)
        return;
    }
  }
  v7 = fldTitle->static_fields;
  if (v7->gfldTitleMiniStep != 4)
    return;
  v7->gfldTitleMiniStep = 0;
}

// 0x178f0d0
dds3ProcessFunc_t *fldTitleShutDown(dds3ProcessID_t *id) {
  fldTitle_c *v2;
  struct fldTitle_StaticFields *static_fields;
  struct fldTitle_StaticFields *v4;
  struct fldTitle_StaticFields *v5;
  struct fldTitle_StaticFields *v6;

  static_fields = v2->static_fields;
  if (static_fields->hFldTitleName)
  {
    static_fields->hFldTitleName = 0;
  }
  v4 = v2->static_fields;
  if (v4->hFldTitle01)
  {
    v4->hFldTitle01 = 0;
  }
  v5 = v2->static_fields;
  if (v5->hFldTitle02)
  {
    v5->hFldTitle02 = 0;
  }
  v6 = v2->static_fields;
  if (v6->hFldTitle03)
  {
    v6->hFldTitle03 = 0;
  }
  return 0;
}

// 0x178f230
void fldTitleStart(s32 fld, s32 waittime) {
    LoadFile(0, 0, 0, 0, 0);
    IsDLCField(0);
    IsLoad(0, 0);
    LoadAssetExt(0, 0, 0);
    dds3SearchProcessName(0);
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
}
