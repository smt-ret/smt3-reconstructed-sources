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
  bool v5;
  s32 playtime;
  s32 startTime;
  s32 waitTime;

  if (!timeCheck)
    return 0;
LABEL_6:
  else if (typeClose)
  {
    goto LABEL_35;
  }
  if (startTime < 0 || reset)
    goto LABEL_44;
  v5 = fldProcCheckFlag(0x40u) == 0;
  if (v5)
  {
LABEL_44:
    playtime = DDS3_GBWK->playtime;
    startTime = playtime;
    if ((v3->_2.bitflags2 & 2) == 0)
      goto LABEL_38;
    goto LABEL_36;
  }
LABEL_35:
  if ((v3->_2.bitflags2 & 2) != 0)
  {
LABEL_36:
  }
LABEL_38:
  return waitTime + startTime < DDS3_GBWK->playtime;
}

// 0xfe0ea0
void ButtonGuideDispDel(void) {
  UnityEngine_Object_o *ButtonGuideAnm;

  if (!op_Equality(ButtonGuideAnm, 0, 0))
  {
    SetInteger(ButtonGuideAnm, "fbuttonguide", 0);
    GuideNowAnm = 0;
    timeCheck = 0;
    waitTime = 90;
  }
}

// 0xfdfbd0
void ButtonGuideDispIn(void) {
  UnityEngine_Object_o *ButtonGuideAnm;
  s32 GuideNowAnm;

  if (!op_Equality(ButtonGuideAnm, 0, 0))
  {
    if (GuideNowAnm != 1)
    {
      if (GuideNowAnm != 2)
      {
        SetInteger(ButtonGuideAnm, "fbuttonguide", 1);
        GuideNowAnm = 1;
      }
    }
  }
}

// 0xfdf6f0
void ButtonGuideDispOff(void) {
  UnityEngine_Object_o *ButtonGuideAnm;

  if (!op_Equality(ButtonGuideAnm, 0, 0))
  {
    if (GuideNowAnm)
    {
      SetInteger(ButtonGuideAnm, "fbuttonguide", 0);
      GuideNowAnm = 0;
      waitTime = 90;
    }
  }
}

// 0xfe0750
void ButtonGuideDispOn(void) {
  UnityEngine_Object_o *ButtonGuideAnm;

  if (!op_Equality(ButtonGuideAnm, 0, 0))
  {
    if (GuideNowAnm != 2)
    {
      SetInteger(ButtonGuideAnm, "fbuttonguide", 2);
      GuideNowAnm = 2;
    }
  }
}

// 0xfdfd10
void ButtonGuideDispOut(void) {
  UnityEngine_Object_o *ButtonGuideAnm;
  s32 GuideNowAnm;

  if (!op_Equality(ButtonGuideAnm, 0, 0))
  {
    if (GuideNowAnm != 3)
    {
      if (GuideNowAnm)
      {
        SetInteger(ButtonGuideAnm, "fbuttonguide", 3);
        GuideNowAnm = 3;
        waitTime = 90;
      }
    }
  }
}

// 0xfdfef0
void ButtonGuideDispSet(char *name, bool timer, bool empty, s32 waitTimer) {
  GuideDataTbl_GuideData_o *GuideData;
  u64 v12;
  struct GuideDataTbl_GuideSet_array *guideSet;
  UnityEngine_GameObject_o *v15;
  struct GuideDataTbl_GuideSet_array *v17;
  il2cpp_array_size_t max_length;
  u64 v19;
  s32 v20;
  struct UnityEngine_GameObject_array *v23;
  UnityEngine_GameObject_o *v25;
  struct GuideDataTbl_GuideSet_array *v26;
  struct GuideDataTbl_GuideSet_array *v29;
  struct UnityEngine_GameObject_array *v32;
  UnityEngine_GameObject_o *v34;
  struct GuideDataTbl_GuideSet_array *v35;
  struct UnityEngine_GameObject_array *guideObj;
  UnityEngine_GameObject_o *v41;
  struct UnityEngine_GameObject_array *subObj;
  UnityEngine_GameObject_o *v44;
  struct TMPro_TextMeshProUGUI_array *guideText;
  struct GuideDataTbl_GuideSet_array *v47;
  TMPro_TMP_Text_o *v48;
  System_String_o *text;
  System_String_o *LocalizeText;
  System_Object_array *v52;
  System_Object_array *v53;
  s64 *v54;
  s64 *v56;
  System_String_o *v59;
  u64 v60;
  ButtonGuide_c *v62;
  bool v69;
  s32 v70;

  GuideData = GetGuideData(GuideList, name, empty);
  waitTime = waitTimer;
  guideSet = GuideData->_guideSet;
  if (guideSet->m_Items[0]->button1 > 0)
  {
    v69 = timer;
    v15 = *(*(*(v12 + 184) + 16LL) + 64LL);
    cmpSetupObject(v15, empty);
    v17 = GuideData->_guideSet;
    max_length = v17->max_length;
    if (max_length >= 1)
    {
      v19 = 0;
      v20 = 1;
      do
      {
        if (v17->m_Items[v19]->button1 <= 0)
        {
          guideObj = _buttonguideUI->guideObj;
          v41 = guideObj->m_Items[v19];
          cmpSetupObject(v41, 0);
          goto LABEL_80;
        }
        v23 = _buttonguideUI->guideObj;
        v25 = v23->m_Items[v19];
        cmpSetupObject(v25, 1);
        v26 = GuideData->_guideSet;
        Change(
          _buttonguideUI,
          v20 - 1,
          v26->m_Items[v19]->button1,
          0);
        v29 = GuideData->_guideSet;
        if (v29->m_Items[v19]->button2 <= 0)
        {
          subObj = _buttonguideUI->subObj;
          v44 = subObj->m_Items[v19];
          cmpSetupObject(v44, 0);
            goto LABEL_64;
        }
        else
        {
          v32 = _buttonguideUI->subObj;
          v34 = v32->m_Items[v19];
          cmpSetupObject(v34, 1);
          v35 = GuideData->_guideSet;
          Change(
            _buttonguideUI,
            v20,
            v35->m_Items[v19]->button2,
            0);
            goto LABEL_64;
        }
LABEL_64:
        guideText = _buttonguideUI->_guideText;
        v47 = GuideData->_guideSet;
        v48 = guideText->m_Items[v19];
        text = v47->m_Items[v19]->text;
        LocalizeText = GetLocalizeText(text);
        v52 = NewSpecific(object, 1u);
        v70 = 0;
        v53 = v52;
        v54 = sub_8D3950(s32, &v70);
        v56 = v54;
        v53->m_Items[0] = v56;
        v59 = RepColTag(LocalizeText, v53);
        set_text(v48, v59);
LABEL_80:
        v17 = GuideData->_guideSet;
        LODWORD(max_length) = v17->max_length;
        ++v19;
        v20 += 2;
      }
      while (v19 < max_length);
    }
    if (v69)
    {
      else if (typeClose)
      {
        goto LABEL_85;
      }
      ButtonGuideDispOff(v60);
      {
LABEL_112:
        timeCheck = 1;
        if ((v62->_2.bitflags2 & 2) == 0)
          goto LABEL_113;
        goto LABEL_94;
      }
LABEL_108:
      goto LABEL_112;
    }
LABEL_85:
    if ((*(v60 + 295) & 2) != 0 && !*(v60 + 216))
    {
      ButtonGuideDispOn();
      if (v69)
        goto LABEL_111;
    }
    else
    {
      ButtonGuideDispOn(v60);
      if (v69)
        goto LABEL_111;
    }
    else
    {
      if (!typeClose)
      {
LABEL_91:
        else
        {
          timeCheck = 0;
          if ((v62->_2.bitflags2 & 2) == 0)
            goto LABEL_113;
        }
LABEL_94:
LABEL_113:
        if ((byte_3F587AA & 1) != 0)
          goto LABEL_115;
        goto LABEL_114;
      }
    }
LABEL_111:
      goto LABEL_112;
    goto LABEL_108;
  }
  ButtonGuideDispOff(v12);
  timeCheck = 0;
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
  v17 = "common";
  v18 = "ButtonGuideList";
  v19 = ".asset";
  v20 = Concat_5271136(ButtonGuideAssetPath, "/", v18, v19);
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
  s32 playtime;

  if (!ButtonGuideCheck(0))
    return 0;
LABEL_6:
  {
    else
    {
      if (!typeClose)
        goto LABEL_22;
    }
LABEL_8:
    ButtonGuideDispOut(v3);
    playtime = DDS3_GBWK->playtime;
    startTime = playtime;
    typeClose = 0;
    waitTime = 90;
    return 0;
  }
  v4 = 0;
  if (typeClose)
    goto LABEL_8;
LABEL_22:
  ButtonGuideDispIn(v3);
  return 0;
}

// 0xfe0860
bool ButtonGuideResetCheck(bool reset) {
  bool result;

  result = 1;
  if ((startTime & 0x80000000) == 0 && !reset)
  {
    if (dds3SearchProcessName("PipeMain"))
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
  if (!timeCheck)
    return;
  else if (typeClose)
  {
    return;
  }
  if (DDS3_PADCHECK_PRESS(4))
    goto LABEL_77;
LABEL_13:
  if (DDS3_PADCHECK_PRESS(5))
    goto LABEL_77;
  if (DDS3_PADCHECK_PRESS(6))
    goto LABEL_77;
  if (DDS3_PADCHECK_PRESS(7))
    goto LABEL_77;
  if (DDS3_PADCHECK_PRESS(0))
    goto LABEL_77;
  if (DDS3_PADCHECK_PRESS(1))
    goto LABEL_77;
  if (DDS3_PADCHECK_PRESS(2))
    goto LABEL_77;
  if (DDS3_PADCHECK_PRESS(3))
    goto LABEL_77;
  if (DDS3_PADCHECK_PRESS(8))
    goto LABEL_77;
  if (DDS3_PADCHECK_PRESS(9))
    goto LABEL_77;
  if (DDS3_PADCHECK_PRESS(10))
    goto LABEL_77;
  if (DDS3_PADCHECK_PRESS(11))
    goto LABEL_77;
  if (DDS3_PADCHECK_PRESS(12))
    goto LABEL_77;
  if (DDS3_PADCHECK_PRESS(13))
    goto LABEL_77;
  if (DDS3_PADCHECK_PRESS(14))
    goto LABEL_77;
  if (DDS3_PADCHECK_PRESS(15))
    goto LABEL_77;
}

// 0xfe0db0
bool CheckTypeClose(void) {
  struct fldGlobalWork_t_o *fldGb;

  if (fldGb->fieldID != 15)
    return 0;
  if (fldGb->areaID != 16)
    return 0;
LABEL_10:
  return typeClose;
}

// 0xfe0d40
void SetTypeClose(bool flg) {
  typeClose = flg;
}
