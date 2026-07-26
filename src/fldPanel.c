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
  if (dds3SearchProcessName(StringLiteral_14979))
  {
    SetAreaUI(kernelObject, 0, 0, 0, 0, 0xFFFFFFFF);
    id->func_ans = -1;
    return 0;
  }
  else  if (!fldProcAmChk())
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
  started = dds3StartProcess(StringLiteral_2860, 0x2B0Bu, 1, 1, v2, 0, v3, 0, 0, 0);
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
  started = dds3StartProcess(StringLiteral_16708, 0x2B0Bu, 1, 1, v2, 0, v3, 0, 0, 0);
  inputpanel_id = started;
}

// 0x10c8be0
s32 fldInputPanelCheckKey(void) {
    fldProcCampChk();
    fldProcAmChk();
    fmProcessChk();
    fldCamMiwatasiChk();
    fldProcKiretaChk();
    fldProcHirakenaiChk();
    dds3GetProcessData(0);
    DDS3_PADCHECK_TRIG(0);
    dds3FadeIn2(0);
    return 0;
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
      v13 = Find(transform, StringLiteral_16707, 0);
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
    fldProcCampChk();
    fldProcAmChk();
    fmProcessChk();
    fldCamMiwatasiChk();
    fldProcKiretaChk();
    fldProcHirakenaiChk();
    GetAnnounceUI(0);
    dds3GetProcessData(0);
    GetLocalizeText(0);
    RepColTag(0, 0);
    return 0;
}

// 0x10c8950
void fldInputPanelSetDraw(s32 flag) {
    dds3GetProcessData(0);
}

// 0x10c8a90
void fldInputPanelSetMessage(s32 no) {
    dds3GetProcessData(0);
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
