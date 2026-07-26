#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct ButtonGuideList ButtonGuideList;
typedef struct GuideDataTbl_GuideData GuideDataTbl_GuideData;
typedef struct buttonguideUI buttonguideUI;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;

static void *ButtonGuideObj;
static void *ButtonGuideAnm;
static buttonguideUI *_buttonguideUI;
static bool timeCheck;
static s32 startTime;
static s32 waitTime;
static s32 GuideNowAnm;
static ButtonGuideList *GuideList;
static bool typeClose;

bool ButtonGuideCheck(bool reset);
void ButtonGuideDispIn(void);
void ButtonGuideDispOff(void);
void ButtonGuideDispOn(void);
void ButtonGuideDispOut(void);
void Change(buttonguideUI *this, s32 setNum, s32 setSpr);
bool DDS3_PADCHECK_PRESS(s32 id);
void *GetButtonGuide(dds3DefaultMain *this);
GuideDataTbl_GuideData *GetGuideData(ButtonGuideList *this, char *category);
char *GetLocalizeText(char *ID);
void *LoadFile_16626736(AssetBundleCtrl *this, char *key, char *path_name);
char *RepColTag(char *txt, void **LegacyParamArray);
dds3ProcessID_t *dds3SearchProcessName(char *namestr);
s8 fldProcCheckFlag(u32 flag);

// 0xfdf9b0
bool ButtonGuideCheck(bool reset) {
  ButtonGuide_c *v3;
  struct ButtonGuide_StaticFields *static_fields;
  bool v5;
  dds3GlobalWork_c *v6;
  struct dds3GlobalWork_StaticFields *v7;
  s32 playtime;
  struct ButtonGuide_StaticFields *v10;
  s32 startTime;
  s32 waitTime;

  static_fields = ButtonGuide->static_fields;
  if (!static_fields->timeCheck)
    return 0;
  else  if (static_fields->startTime < 0 || reset)
  v5 = fldProcCheckFlag(0x40u) == 0;
  if (v5)
  {
    v7 = v6->static_fields;
    playtime = v7->DDS3_GBWK->playtime;
    startTime = playtime;
    if ((v3->_2.bitflags2 & 2) == 0)
  }
  v10 = v3->static_fields;
  startTime = v10->startTime;
  waitTime = v10->waitTime;
  return waitTime + startTime < DDS3_GBWK->playtime;
}

// 0xfe0ea0
void ButtonGuideDispDel(void) {
  UnityEngine_Object_o *ButtonGuideAnm;

  if (!op_Equality(ButtonGuideAnm, 0, 0))
  {
    SetInteger(ButtonGuideAnm, StringLiteral_4614, 0);
    GuideNowAnm = 0;
    timeCheck = 0;
    waitTime = 90;
  }
}

// 0xfdfbd0
void ButtonGuideDispIn(void) {
  UnityEngine_Object_o *ButtonGuideAnm;
  ButtonGuide_c *v5;
  struct ButtonGuide_StaticFields *static_fields;
  s32 GuideNowAnm;

  if (!op_Equality(ButtonGuideAnm, 0, 0))
  {
    static_fields = v5->static_fields;
    GuideNowAnm = static_fields->GuideNowAnm;
    if (GuideNowAnm != 1)
    {
      if (GuideNowAnm != 2)
      {
        SetInteger(static_fields->ButtonGuideAnm, StringLiteral_4614, 1);
        GuideNowAnm = 1;
      }
    }
  }
}

// 0xfdf6f0
void ButtonGuideDispOff(void) {
  UnityEngine_Object_o *ButtonGuideAnm;
  ButtonGuide_c *v5;
  struct ButtonGuide_StaticFields *static_fields;

  if (!op_Equality(ButtonGuideAnm, 0, 0))
  {
    static_fields = v5->static_fields;
    if (static_fields->GuideNowAnm)
    {
      SetInteger(static_fields->ButtonGuideAnm, StringLiteral_4614, 0);
      GuideNowAnm = 0;
      waitTime = 90;
    }
  }
}

// 0xfe0750
void ButtonGuideDispOn(void) {
  UnityEngine_Object_o *ButtonGuideAnm;
  ButtonGuide_c *v5;
  struct ButtonGuide_StaticFields *static_fields;

  if (!op_Equality(ButtonGuideAnm, 0, 0))
  {
    static_fields = v5->static_fields;
    if (static_fields->GuideNowAnm != 2)
    {
      SetInteger(static_fields->ButtonGuideAnm, StringLiteral_4614, 2);
      GuideNowAnm = 2;
    }
  }
}

// 0xfdfd10
void ButtonGuideDispOut(void) {
  UnityEngine_Object_o *ButtonGuideAnm;
  ButtonGuide_c *v5;
  struct ButtonGuide_StaticFields *static_fields;
  s32 GuideNowAnm;

  if (!op_Equality(ButtonGuideAnm, 0, 0))
  {
    static_fields = v5->static_fields;
    GuideNowAnm = static_fields->GuideNowAnm;
    if (GuideNowAnm != 3)
    {
      if (GuideNowAnm)
      {
        SetInteger(static_fields->ButtonGuideAnm, StringLiteral_4614, 3);
        GuideNowAnm = 3;
        waitTime = 90;
      }
    }
  }
}

// 0xfdfef0
void ButtonGuideDispSet(char *name, bool timer, bool empty, s32 waitTimer) {
    GetGuideData(0, 0);
    Change(0, 0, 0);
    GetLocalizeText(0);
    RepColTag(0, 0);
    ButtonGuideDispOff();
    ButtonGuideDispOn();
}

// 0xfdf480
void ButtonGuideInit(void) {
  UnityEngine_GameObject_o *ButtonGuide;
  Il2CppObject *Component_object;
  Il2CppObject *v8;
  UnityEngine_GameObject_o *ButtonGuideObj;
  AssetBundleCtrl_o *asset_bc;
  System_String_o *ButtonGuideAssetPath;
  System_String_o *v17;
  System_String_o *v18;
  System_String_o *v19;
  System_String_o *v20;
  UnityEngine_Object_o *File_16626736;
  s64 typeHierarchyDepth;
  struct ButtonGuideList_o *v24;

  ButtonGuide = GetButtonGuide(kernelObject);
  ButtonGuideObj = ButtonGuide;
  Component_object = GetComponent_object_(ButtonGuideObj);
  ButtonGuideAnm = Component_object;
  v8 = GetComponent_object_(ButtonGuideObj);
  _buttonguideUI = v8;
  cmpSetupObject(ButtonGuideObj, 1);
  ButtonGuideDispOff();
  timeCheck = 0;
  asset_bc = get_asset_bc();
  {
  }
  v17 = StringLiteral_4611;
  v18 = StringLiteral_4612;
  v19 = StringLiteral_4586;
  v20 = Concat_5271136(ButtonGuideAssetPath, StringLiteral_74, v18, v19);
  File_16626736 = LoadFile_16626736(asset_bc, v17, v20);
  if (File_16626736
        File_16626736->klass->_2.typeHierarchyDepth >= typeHierarchyDepth))
  {
    if (File_16626736->klass->_2.typeHierarchy[typeHierarchyDepth - 1] == ButtonGuideList)
      v24 = File_16626736;
    else
      v24 = 0;
  }
  else
  {
    v24 = 0;
  }
  GuideList = v24;
}

// 0xfdf810
dds3ProcessFunc_t *ButtonGuideMain(dds3ProcessID_t *id) {
  u64 v3;
  s32 v4;
  dds3GlobalWork_c *v6;
  struct dds3GlobalWork_StaticFields *static_fields;
  s32 playtime;

  if (!ButtonGuideCheck(0))
    return 0;
  {
    else
    {
      if (!typeClose)
    }
    if (v4 && !*(v3 + 216))
    ButtonGuideDispOut(v3);
    static_fields = v6->static_fields;
    playtime = static_fields->DDS3_GBWK->playtime;
    startTime = playtime;
    typeClose = 0;
    waitTime = 90;
    return 0;
  }
  v4 = 0;
  if (typeClose)
  if (v4 && !*(v3 + 216))
  ButtonGuideDispIn(v3);
  return 0;
}

// 0xfe0860
bool ButtonGuideResetCheck(bool reset) {
  ButtonGuide_c *v3;
  struct ButtonGuide_StaticFields *static_fields;
  bool result;

  static_fields = v3->static_fields;
  result = 1;
  if ((static_fields->startTime & 0x80000000) == 0 && !reset)
  {
    if (dds3SearchProcessName(StringLiteral_4613))
    {
      return 0;
    }
    else
    {
      return fldProcCheckFlag(0x40u) == 0;
    }
  }
  return result;
}

// 0xfdfe50
void ButtonGuideTimerReset(void) {
  struct dds3GlobalWork_t_o *DDS3_GBWK;
  s32 playtime;

  playtime = DDS3_GBWK->playtime;
  startTime = playtime;
}

// 0xfe0960
void CheckPlayerCtrl(void) {
    DDS3_PADCHECK_PRESS(0);
    ButtonGuideDispOut();
}

// 0xfe0db0
bool CheckTypeClose(void) {
  struct fldGlobalWork_t_o *fldGb;

  if (fldGb->fieldID != 15)
    return 0;
  if (fldGb->areaID != 16)
    return 0;
  return typeClose;
}

// 0xfe0d40
void SetTypeClose(bool flg) {
  typeClose = flg;
}
