#include "types.h"

typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;

static dds3ProcessID_t *addressprocess_id;
static dds3ProcessID_t *inputpanel_id;
static char *inputpanel_mes0[12];
static s32 inputpanel_xpos[12];
static u16 bChanged;

bool DDS3_PADCHECK_TRIG(s32 id);
void *GetAnnounceUI(dds3DefaultMain *this);
char *GetLocalizeText(char *ID);
char *RepColTag(char *txt, void **LegacyParamArray);
void SetAreaUI(dds3DefaultMain *this, bool disp, s32 x, s32 y, char *text, u32 rgba);
void dds3FadeIn2(u32 frame);
void *dds3GetProcessData(dds3ProcessID_t **id);
s32 dds3KillProcess(dds3ProcessID_t **id, s32 shutdowntimer);
dds3ProcessID_t *dds3SearchProcessName(char *namestr);
void dds3SetProcessData(dds3ProcessID_t **id, void *data);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
s32 encChk(void);
void fldBasyoDraw(s32 w, s32 x, s32 y);
s32 fldCamMiwatasiChk(void);
void fldDrawAreaBlockFont(s32 ofsx);
s32 fldProcAmChk(void);
s32 fldProcCampChk(void);
s32 fldProcHirakenaiChk(void);
s32 fldProcKiretaChk(void);
s32 fldTitleChk(void);
s32 fmProcessChk(void);

// 0x10c9340
void *fldAddressProcess1(dds3ProcessID_t *id) {
  fldAddressProcessData_t_o *v2;
  struct System_Int32_array *dmy;
  struct System_Int32_array *v6;
  struct System_Int32_array *v8;
  struct System_Int32_array *v10;
  u64 *v12;
  dds3ProcessID_t_o *ida;

  ida = id;
  v2 = Allocate(fldAddressProcessData_t);
  fldAddressProcessData_t___ctor(v2);
  dmy = v2->dmy;
  dmy->m_Items[0] = 0;
  v6 = v2->dmy;
  v6->m_Items[1] = 0;
  v8 = v2->dmy;
  v8->m_Items[2] = 0;
  v10 = v2->dmy;
  v10->m_Items[3] = 0;
  dds3SetProcessData(&ida, v2);
  v12 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v12,
    0,
    Method_fldPanel_fldAddressProcess2__);
  return v12;
}

// 0x10c9080
dds3ProcessFunc_t *fldAddressProcess2(dds3ProcessID_t *id) {
  if (dds3SearchProcessName("titleProc"))
  {
    SetAreaUI(kernelObject, 0, 0, 0, 0, 0xFFFFFFFF);
    id->func_ans = -1;
    return 0;
  }
  else if (fldProcCampChk())
  {
    goto LABEL_39;
  }
  if (!fldProcAmChk())
  {
    if (fmProcessChk() != 1)
    {
      if (fldTitleChk() != 1)
      {
        if (!encChk())
        {
          if (gFldElvFloorNow == -999)
          {
            fldDrawAreaBlockFont(0);
            return 0;
          }
          else
          {
            fldBasyoDraw(128, 0, 0);
            return 0;
          }
        }
      }
    }
  }
LABEL_39:
  SetAreaUI(kernelObject, 0, 0, 0, 0, 0xFFFFFFFF);
  return 0;
}

// 0x10c94a0
void *fldAddressShutdown(dds3ProcessID_t *id) {
  dds3ProcessID_t_o *ida;

  ida = id;
  dds3GetProcessData(&ida);
  addressprocess_id = 0;
  ida->func_ans = -1;
  SetAreaUI(kernelObject, 0, 0, 0, 0, 0xFFFFFFFF);
  return 0;
}

// 0x10c96f0
void fldFreeAddressProcess(void) {
  else if (!addressprocess_id)
  {
    return;
  }
  dds3KillProcess(&addressprocess_id, 1);
}

// 0x10c8880
void fldFreeInputPanel(void) {
  else if (!inputpanel_id)
  {
    return;
  }
  dds3KillProcess(&inputpanel_id, 1);
}

// 0x10c9590
void fldInitAddressProcess(void) {
  u64 *v2;
  u64 *v3;
  dds3ProcessID_t_o *started;

  else if (addressprocess_id)
  {
    return;
  }
  v2 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v2,
    0,
    Method_fldPanel_fldAddressProcess1__);
  v3 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v3,
    0,
    Method_fldPanel_fldAddressShutdown__);
  started = dds3StartProcess("address", 0x2B0Bu, 1, 1, v2, 0, v3, 0, 0, 0);
  addressprocess_id = started;
}

// 0x10c8720
void fldInitInputPanel(void) {
  u64 *v2;
  u64 *v3;
  dds3ProcessID_t_o *started;

  else if (inputpanel_id)
  {
    return;
  }
  v2 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v2,
    0,
    Method_fldPanel_fldInputPanelProcess1__);
  v3 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v3,
    0,
    Method_fldPanel_fldInputPanelShutdown__);
  started = dds3StartProcess("inputpanel", 0x2B0Bu, 1, 1, v2, 0, v3, 0, 0, 0);
  inputpanel_id = started;
}

// 0x10c8be0
s32 fldInputPanelCheckKey(void) {
  Il2CppObject *ProcessData;
  Il2CppObject *v13;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v16;
  s64 *v17;
  u64 v23[3];

  else if (fldProcCampChk())
  {
    return 0;
  }
  else if (fldProcAmChk())
  {
    return 0;
  }
  if (fldDbg->MenuOn)
    return 0;
  if (fmProcessChk() == 1)
    return 0;
  if (fldCamMiwatasiChk() == 1)
    return 0;
  if (fldProcKiretaChk() == 1)
    return 0;
  if (fldProcHirakenaiChk() == 1)
    return 0;
  if (fldGb->NoroiDamegeCnt)
    return 0;
  ProcessData = dds3GetProcessData(&inputpanel_id);
  v13 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fldInputPanelProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, fldInputPanelProcessData_t, v23);
      if ((v23[0] & 1) != 0)
        v16 = v23[2];
      else
        v16 = v23 + 1;
      v17 = sub_8C4940(v16);
    }
  }
  if (!WORD2(ProcessData[1].klass))
    return -1;
  if (fldGb->FukiTalk)
    goto LABEL_69;
  if (gFldInf_WpExit != 1)
  {
    if (!DDS3_PADCHECK_TRIG(1))
      return 0;
  }
LABEL_69:
  WORD2(v13[1].klass) = 0;
  if (fldGb->FukiTalk)
  {
    dds3FadeIn2(8u);
    fldGb->FukiTalk = 0;
  }
  return 1;
}

// 0x10c83c0
void *fldInputPanelProcess1(dds3ProcessID_t *id) {
  u64 *v2;
  UnityEngine_GameObject_o *AnnounceUI;
  UnityEngine_Object_o *v10;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v13;
  UnityEngine_Object_o *v14;
  u64 *v15;
  dds3ProcessID_t_o *ida;

  ida = id;
  v2 = Allocate(fldInputPanelProcessData_t);
  fldInputPanelProcessData_t___ctor(v2);
  v2[2] = 0x10000;
  dds3SetProcessData(&ida, v2);
  bChanged = 0;
  AnnounceUI = GetAnnounceUI(kernelObject);
  if (op_Inequality(AnnounceUI, 0, 0))
  {
    v10 = v2[4];
    if (op_Equality(v10, 0, 0))
    {
      transform = get_transform(AnnounceUI, 0);
      v13 = Find(transform, "guidetext/TextTM", 0);
      v2[4] = get_gameObject(v13);
    }
    v14 = v2[3];
    if (op_Equality(v14, 0, 0))
      v2[3] = GetComponent_object_(v2[4]);
  }
  v15 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v15,
    0,
    Method_fldPanel_fldInputPanelProcess2__);
  return v15;
}

// 0x10c7d30
dds3ProcessFunc_t *fldInputPanelProcess2(dds3ProcessID_t *id) {
  UnityEngine_GameObject_o *AnnounceUI;
  Il2CppObject *ProcessData;
  Il2CppObject *v15;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v18;
  s64 *v19;
  UnityEngine_GameObject_o *v22;
  UnityEngine_Object_o *v24;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v27;
  UnityEngine_Object_o *monitor;
  TMPro_TMP_Text_o *v31;
  struct System_String_array *inputpanel_mes0;
  s64 v33;
  System_String_o *v35;
  System_String_o *LocalizeText;
  System_Object_array *v37;
  s64 *v38;
  s64 *v40;
  System_String_o *v43;
  UnityEngine_GameObject_o *v48;
  dds3ProcessID_t_o *v51[3];
  dds3ProcessID_t_o *ida;

  ida = id;
  else if (fldProcCampChk())
  {
    return 0;
  }
  else if (fldProcAmChk())
  {
    return 0;
  }
  if (fmProcessChk() != 1)
  {
    if (fldCamMiwatasiChk() != 1)
    {
      if (fldProcKiretaChk() != 1)
      {
        if (fldProcHirakenaiChk() == 1)
        {
          AnnounceUI = GetAnnounceUI(kernelObject);
          cmpSetupObject(AnnounceUI, 0);
        }
        else
        {
          if (!fldGb->NoroiDamegeCnt)
          {
            ProcessData = dds3GetProcessData(&ida);
            v15 = ProcessData;
            if (ProcessData)
            {
              klass = ProcessData->klass;
              if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
                || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fldInputPanelProcessData_t)
              {
                sub_8FC2C0(klass->_1.element_class, fldInputPanelProcessData_t, v51);
                if ((v51[0] & 1) != 0)
                  v18 = v51[2];
                else
                  v18 = v51 + 1;
                v19 = sub_8C4940(v18);
              }
            }
            if (WORD2(ProcessData[1].klass) == 1)
            {
              v22 = GetAnnounceUI(kernelObject);
              {
              }
              if (op_Inequality(v22, 0, 0)
                && !get_activeInHierarchy(v22))
              {
                v24 = v15[2].klass;
                {
                }
                if (op_Equality(v24, 0, 0))
                {
                  transform = get_transform(v22, 0);
                  v27 = Find(transform, "guidetext/TextTM", 0);
                  v15[2].klass = get_gameObject(v27);
                }
                monitor = v15[1].monitor;
                {
                }
                if (op_Equality(monitor, 0, 0))
                  v15[1].monitor = GetComponent_object_(v15[2].klass);
                SetActive(v22, 1, 0);
                v31 = v15[1].monitor;
                v33 = WORD1(v15[1].klass);
                v35 = inputpanel_mes0->m_Items[v33];
                LocalizeText = GetLocalizeText(v35);
                LODWORD(v51[0]) = 0;
                v37 = NewSpecific(object, 1u);
                v38 = sub_8D3950(s32, v51);
                v40 = v38;
                v37->m_Items[0] = v40;
                v43 = RepColTag(LocalizeText, v37);
                set_text(v31, v43);
              }
              ++LOWORD(v15[1].klass);
              bChanged = 1;
              WORD2(v15[1].klass) = 0;
            }
            else
            {
              if (bChanged == 1)
              {
                v48 = GetAnnounceUI(kernelObject);
                {
                }
                if (op_Inequality(v48, 0, 0)
                  && get_activeInHierarchy(v48))
                {
                  SetActive(v48, 0, 0);
                }
                bChanged = 0;
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

// 0x10c8950
void fldInputPanelSetDraw(s32 flag) {
  s16 v2;
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v8[3];

  v2 = flag;
  ProcessData = dds3GetProcessData(&inputpanel_id);
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fldInputPanelProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, fldInputPanelProcessData_t, v8);
    if ((v8[0] & 1) != 0)
      v6 = v8[2];
    else
      v6 = v8 + 1;
    v7 = sub_8C4940(v6);
  }
  WORD2(ProcessData[1].klass) = v2;
}

// 0x10c8a90
void fldInputPanelSetMessage(s32 no) {
  s16 v2;
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v8[3];

  v2 = no;
  ProcessData = dds3GetProcessData(&inputpanel_id);
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fldInputPanelProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, fldInputPanelProcessData_t, v8);
      if ((v8[0] & 1) != 0)
        v6 = v8[2];
      else
        v6 = v8 + 1;
      v7 = sub_8C4940(v6);
    }
    WORD1(ProcessData[1].klass) = v2;
  }
}

// 0x10c85e0
void *fldInputPanelShutdown(dds3ProcessID_t *id) {
  UnityEngine_GameObject_o *AnnounceUI;
  dds3ProcessID_t_o *ida;

  ida = id;
  dds3GetProcessData(&ida);
  inputpanel_id = 0;
  AnnounceUI = GetAnnounceUI(kernelObject);
  if (op_Inequality(AnnounceUI, 0, 0) && get_activeSelf(AnnounceUI))
    SetActive(AnnounceUI, 0, 0);
  ida->func_ans = -1;
  return 0;
}
