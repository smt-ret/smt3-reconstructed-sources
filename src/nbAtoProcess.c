#include "types.h"

typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;

void datBossRashUpdRec(s32 eid, s32 press);
void dds3FadeOut(u32 r, u32 g, u32 b, u32 frame);
u32 dds3GetProcessRunTime(dds3ProcessID_t **id);
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void evtSetUnitColorA(evtUnitHandle_t **h, u32 frame, u32 a);
void evtSetUnitColorRGB(evtUnitHandle_t **h, u32 frame, u32 rgb);
void evtSetUnitMotion(evtUnitHandle_t **h, s32 motion, s32 before, s32 smooth, s32 mode);
s32 mdlGetMinorNum(dds3ModelHandle_t **aHandle);
void mdlSetMotionSpeedAnimator(void *mAnimator, f32 speed);
void nbBgmFadeOut(void);
void nbCameraSetBougai(nbFormation_t **pTargetForm);
void nbCameraSetState(u16 state);
void nbDispMsgHelp(s32 msgid, s32 no, s32 msgtype);
nbMainProcessData_t *nbGetMainProcessData(void);
void nbPanelDraw(s32 flag);
void nbSetDevilNameMes(s32 hmsg, s32 no, datUnitWork_t *work);
void nbSingleFormExceptedDispOff(nbFormation_t **form);

// 0xfaabb0
void *nbAtoGameover2Process(dds3ProcessID_t *id) {
  u32 ProcessRunTime;
  dds3ProcessID_t_o *ida;

  ida = id;
  ProcessRunTime = dds3GetProcessRunTime(&ida);
  if (ProcessRunTime == 40)
  {
    ida->func_ans = -1;
    return 0;
  }
  else
  {
    if (ProcessRunTime == 10)
    {
      dds3FadeOut(0xFFu, 0xFFu, 0xFFu, 0x1Eu);
    }
    return 0;
  }
}

// 0xfaa960
void *nbAtoGameoverProcess(dds3ProcessID_t *id) {
  u32 ProcessRunTime;
  struct nbFormation_t_array *form;
  evtUnitHandle_t_o **p_hunit;
  UnityEngine_Animator_o *modelanm;
  nbFormation_t_o *v13;
  dds3ProcessID_t_o *ida;

  ida = id;
  v13 = 0;
  ProcessRunTime = dds3GetProcessRunTime(&ida);
  form = nbGetMainProcessData()->form;
  v13 = form->m_Items[0];
  switch (ProcessRunTime)
  {
    case 0x50u:
      ida->func_ans = -1;
      break;
    case 0x32u:
      dds3FadeOut(0xFFu, 0xFFu, 0xFFu, 0x1Eu);
      break;
    case 1u:
      nbSingleFormExceptedDispOff(&v13);
      p_hunit = &v13->hunit;
      evtSetUnitColorRGB(p_hunit, 0, 0x80808080);
      evtSetUnitColorA(&v13->hunit, 0, 0x80808080);
      modelanm = v13->modelanm;
      mdlSetMotionSpeedAnimator(modelanm, 1.0);
      evtSetUnitMotion(&v13->hunit, 23, 0, 0, 2);
      nbCameraSetBougai(&v13);
      break;
  }
  return 0;
}

// 0xfaac90
void *nbAtoProcess1(dds3ProcessID_t *id) {
  nbMainProcessData_t_o *MainProcessData;
  u32 endtype;
  nbMainProcessData_t_o *v5;
  s32 encno;
  s32 d31_press_total;
  u64 *v9;
  intptr_t v10;
  const MethodInfo_104 *v11;
  Il2CppObject *v12;
  struct nbFormation_t_array *form;
  dds3ModelHandle_t_o **p_Model;
  s32 MinorNum;
  intptr_t *v17;
  dds3ProcessID_t_o *ida;

  ida = id;
  MainProcessData = nbGetMainProcessData();
  endtype = MainProcessData->endtype;
  v5 = MainProcessData;
  if (endtype == 1)
  {
    encno = MainProcessData->encno;
    d31_press_total = MainProcessData->d31_press_total;
    datBossRashUpdRec(encno, d31_press_total);
    endtype = v5->endtype;
  }
  if ((endtype | 4) == 6)
  {
    nbPanelDraw(0);
    nbBgmFadeOut();
    endtype = v5->endtype;
  }
  if (endtype == 2)
  {
    form = v5->form;
    p_Model = &form->m_Items[0]->hunit->Model;
    MinorNum = mdlGetMinorNum(p_Model);
    v9 = Allocate(System_Func_dds3ProcessID_t__object_);
    v12 = v9;
    if (MinorNum)
      v17 = &Method_nbAtoProcess_nbAtoGameover2Process__;
    else
      v17 = &Method_nbAtoProcess_nbAtoGameoverProcess__;
    v10 = *v17;
    v11 = Method_System_Func_dds3ProcessID_t__object___ctor__;
    goto LABEL_36;
  }
  if (endtype == 6)
  {
    v9 = Allocate(System_Func_dds3ProcessID_t__object_);
    v10 = Method_nbAtoProcess_nbAtoStoneProcess__;
    v11 = Method_System_Func_dds3ProcessID_t__object___ctor__;
    v12 = v9;
LABEL_36:
    object____ctor(v9, 0, v10, v11);
    return v12;
  }
  v12 = 0;
  if (dds3GetProcessRunTime(&ida) >= 1)
    ida->func_ans = -1;
  return v12;
}

// 0xfaaef0
void *nbAtoShutdown(dds3ProcessID_t *id) {
  nbGetMainProcessData()->AtoProcessID = 0;
  return 0;
}

// 0xfaa740
void *nbAtoStoneProcess(dds3ProcessID_t *id) {
  signed s32 ProcessRunTime;
  nbMainProcessData_t_o *MainProcessData;
  nbMainProcessData_t_o *v6;
  s32 jyokyomsgid;
  struct datUnitWork_t_array *unitwork;
  datUnitWork_t_o *v11;
  s32 v13;
  dds3ProcessID_t_o *ida;

  ida = id;
  ProcessRunTime = dds3GetProcessRunTime(&ida);
  else
  {
    MainProcessData = nbGetMainProcessData();
    if (ProcessRunTime > 30)
      goto LABEL_9;
  }
  if (ProcessRunTime == 10)
  {
    nbCameraSetState(0x14u);
  }
  else if (ProcessRunTime == 30)
  {
    v6 = MainProcessData;
    jyokyomsgid = MainProcessData->jyokyomsgid;
    unitwork = DDS3_GBWK->unitwork;
    v11 = unitwork->m_Items[0];
    nbSetDevilNameMes(jyokyomsgid, 0, v11);
    v13 = v6->jyokyomsgid;
    nbDispMsgHelp(v13, 58, 1);
  }
  return 0;
}

// 0xfaaf60
void nbInitAtoProcess(nbMainProcessData_t *data) {
  u64 *v3;
  u64 *v4;
  u64 *v5;
  dds3ProcessID_t_o *target;

  v3 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v3);
  target = v3;
  v4 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v4,
    0,
    Method_nbAtoProcess_nbAtoProcess1__);
  v5 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v5,
    0,
    Method_nbAtoProcess_nbAtoShutdown__);
  target = dds3StartProcess("nb_ato", 0x3F9u, 1, 1, v4, 0, v5, 0, 0, 0);
  dds3LinkProcess(&data->MainProcessID, &target);
  data->AtoProcessID = target;
}
