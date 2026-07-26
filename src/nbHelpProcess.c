#include "types.h"

typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct nbHelpProcessData_t nbHelpProcessData_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;

static char *MiscStr[2];

u8 Get(s32 id);
void *GetBattleUI(s32 index);
char *GetStr(s32 no);
void WaitDisp(nbHelpProcessData_t **h, void *bUIo);
void *dds3GetProcessData(dds3ProcessID_t **id);
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
dds3ProcessID_t *dds3SearchProcessName(char *namestr);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
char *frGetCNameString(s8 TargetNo);
char *itfMesMngGetStrImmediate(s32 id, s32 message, s32 page);
s32 itfMesMngRequestMessage(s32 id, s32 message, s32 page, s32 callmode);
void itfMesMngRequestMessageRelease(s32 id, s32 cls_speaker);
void itfMesMngSetVar(s32 id, s32 index, s32 num, s32 type);
void nbDispMsgHelp(s32 msgid, s32 no, s32 msgtype);
void nbDispText(char *text1, char *text2, s32 type, s32 max, u32 col, bool type_skill);
nbMainProcessData_t *nbGetMainProcessData(void);
void nbHelpOff(void);
void nbHelpProcessData_t__Clear(nbHelpProcessData_t *this);

// 0x1972c00
void DrawPanel(nbHelpProcessData_t **h) {
  ;
}

// 0x1973590
nbHelpProcessData_t *InitHelpProcessData(nbMainProcessData_t **data) {
  nbHelpProcessData_t_o *v2;

  v2 = Allocate(nbHelpProcessData_t);
  nbHelpProcessData_t___ctor(v2);
  nbHelpProcessData_t__Clear(v2);
  v2->msgid = -1;
  v2->alpha = 128;
  return v2;
}

// 0x1973310
void WaitDisp(nbHelpProcessData_t **h, void *bUIo) {
  s32 v5;

  else if (Postblur_DrawStop)
  {
    return;
  }
  v5 = (*h)->wait_time - 1;
  (*h)->wait_time = v5;
  if (!v5)
  {
    nbHelpOff();
    if (!get_activeSelf(bUIo))
      SetActive(bUIo, 1, 0);
    (*h)->text1 = (*h)->wait_text1;
    (*h)->text2 = (*h)->wait_text2;
    (*h)->text3 = 0;
    (*h)->wait_text1 = 0;
    (*h)->wait_text2 = 0;
  }
}

// 0x1972c10
void bUIoOff(void *bUIo) {
  if (op_Inequality(bUIo, 0, 0) && get_activeSelf(bUIo))
    SetActive(bUIo, 0, 0);
}

// 0x19726a0
void nbDispDevilName(s32 id) {
    nbGetMainProcessData();
    Get(0);
    Get(0);
    Get(0);
    Get(0);
    frGetCNameString(0);
    nbDispText(0, 0, 0, 0, 0, 0);
}

// 0x19723b0
void nbDispItemName(s32 id) {
  System_String_o *v5;

  v5 = Get(id, 0);
  nbDispText(v5, 0, 0, 30, 0x89FEFF80, 1);
}

// 0x1972910
void nbDispJyokyoHelp(s32 msgid, s32 no, s32 var_id, s32 var_ind) {
  bool v9;

  if (var_ind)
    v9 = 0;
  else
    v9 = var_id == 1;
  if (v9)
    var_id = 10;
  if ((var_id & 0x80000000) == 0)
  {
    itfMesMngSetVar(msgid, 0, var_ind, var_id);
  }
  nbDispMsgHelp(msgid, no, 1, *&var_ind);
}

// 0x1972520
void nbDispMiscActionNameComm(s32 id) {
  s32 v3;
  System_String_o *Str;

  switch (id)
  {
    case 0:
      v3 = 0;
    case 2:
      v3 = 14;
    case 3:
      v3 = 2;
    case 6:
      v3 = 3;
    case 7:
      v3 = 4;
      Str = GetStr(v3);
      nbDispText(Str, 0, 0, 30, 0x89FEFF80, 0);
      break;
    default:
      return;
  }
}

// 0x1972460
void nbDispMiscName(s32 no, s32 type) {
  struct System_String_array *MiscStr;

  nbDispText(MiscStr->m_Items[no], 0, type, 30, 0x89FEFF80, 0);
}

// 0x19729f0
void nbDispMsgHelp(s32 msgid, s32 no, s32 msgtype) {
    dds3SearchProcessName(0);
    dds3GetProcessData(0);
    nbDispText(0, 0, 0, 0, 0, 0);
}

// 0x1972300
void nbDispSkillName(s32 id) {
  System_String_o *v5;

  v5 = Get(id, 0, 0);
  nbDispText(v5, 0, 0, 30, 0x89FEFF80, 1);
}

// 0x1971eb0
void nbDispText(char *text1, char *text2, s32 type, s32 max, u32 col, bool type_skill) {
    dds3SearchProcessName(0);
    dds3GetProcessData(0);
    nbHelpOff();
    itfMesMngRequestMessage(0, 0, 0, 0);
    itfMesMngGetStrImmediate(0, 0, 0);
}

// 0x1972160
void nbHelpOff(void) {
    dds3SearchProcessName(0);
    dds3GetProcessData(0);
    itfMesMngRequestMessageRelease(0, 0);
}

// 0x1972cb0
void *nbHelpProcess1(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
    GetBattleUI(0);
    WaitDisp(0, 0);
    nbHelpOff();
    return 0;
}

// 0x1973430
void *nbHelpShutdown(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
    return 0;
}

// 0x1973610
void nbInitHelpProcess(nbMainProcessData_t *data) {
  nbHelpProcessData_t_o *v3;
  u64 *v4;
  u64 *v5;
  dds3ProcessID_t_o *target;

  target = 0;
  v3 = Allocate(nbHelpProcessData_t);
  nbHelpProcessData_t___ctor(v3);
  nbHelpProcessData_t__Clear(v3);
  v3->msgid = -1;
  v3->alpha = 128;
  v4 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v4,
    0,
    Method_nbHelpProcess_nbHelpProcess1__);
  v5 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v5,
    0,
    Method_nbHelpProcess_nbHelpShutdown__);
  target = dds3StartProcess(StringLiteral_21413, 0x3F9u, 1, 1, v4, 0, v5, 0, v3, 0);
  dds3LinkProcess(&data->MainProcessID, &target);
  data->HelpProcessID = target;
}
