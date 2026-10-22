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
  System_String_o *v11;
  System_String_o *v12;
  s32 v13;
  struct datUnitWork_t_array *unitwork;
  u8 PlayerRaceID;
  System_String_o *v21;
  System_String_o *CNameString;

  else
  {
    nbGetMainProcessData(nbMainProcess);
    if (id)
      goto LABEL_6;
  }
  unitwork = DDS3_GBWK->unitwork;
  else if (!LODWORD(unitwork->max_length))
  {
    goto LABEL_26;
  }
  PlayerRaceID = cmbGetPlayerRaceID(unitwork->m_Items);
  v21 = Get(PlayerRaceID, 0);
  CNameString = frGetCNameString(0);
  v11 = v21;
  v12 = CNameString;
  v13 = 2;
LABEL_37:
  nbDispText(v11, v12, v13, 2, 0xA09DC380, 0);
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
      goto LABEL_24;
    case 2:
      v3 = 14;
      goto LABEL_24;
    case 3:
      v3 = 2;
      goto LABEL_24;
    case 6:
      v3 = 3;
      goto LABEL_24;
    case 7:
      v3 = 4;
LABEL_24:
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
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  s32 v12;
  u32 v13;
  char *v14;
  s64 *v15;
  dds3ProcessID_t_o *v16;
  u64 v17[3];

  v16 = 0;
  v16 = dds3SearchProcessName("nb_help");
  ProcessData = dds3GetProcessData(&v16);
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbHelpProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbHelpProcessData_t, v17);
    if ((v17[0] & 1) != 0)
      v14 = v17[2];
    else
      v14 = v17 + 1;
    v15 = sub_8C4940(v14);
  }
  LODWORD(ProcessData[6].monitor) = msgid;
  HIDWORD(ProcessData[6].monitor) = no;
  switch (msgtype)
  {
    case 0:
    case 1:
      v12 = 45;
      v13 = -1979777152;
      goto LABEL_21;
    case 2:
      v12 = 20;
      v13 = -1600273536;
      goto LABEL_21;
    case 3:
      v13 = -1979777152;
      v12 = 30;
LABEL_21:
      nbDispText(0, 0, 1, v12, v13, 0);
      break;
    default:
      return;
  }
}

// 0x1972300
void nbDispSkillName(s32 id) {
  System_String_o *v5;

  v5 = Get(id, 0, 0);
  nbDispText(v5, 0, 0, 30, 0x89FEFF80, 1);
}

// 0x1971eb0
void nbDispText(char *text1, char *text2, s32 type, s32 max, u32 col, bool type_skill) {
  Il2CppObject *ProcessData;
  Il2CppObject *v15;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v18;
  s64 *v19;
  System_String_o *monitor;
  _BOOL4 v21;
  System_String_o *v22;
  s32 v25;
  s32 monitor_high;
  dds3ProcessID_t_o *v27[3];
  dds3ProcessID_t_o *id;

  id = 0;
  id = dds3SearchProcessName("nb_help");
  ProcessData = dds3GetProcessData(&id);
  v15 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbHelpProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, nbHelpProcessData_t, v27);
      if ((v27[0] & 1) != 0)
        v18 = v27[2];
      else
        v18 = v27 + 1;
      v19 = sub_8C4940(v18);
    }
  }
  if (type == 1 || !type_skill)
    goto LABEL_25;
  monitor = ProcessData[1].monitor;
  if (monitor)
  {
    if (text1)
    {
      v21 = !Equals_5234480(monitor, text1);
      if (!text2)
        goto LABEL_23;
LABEL_18:
      v22 = v15[2].klass;
      if (v22)
      {
        if (Equals_5234480(v22, text2) && !v21)
          goto LABEL_25;
        goto LABEL_24;
      }
LABEL_23:
      if (!(v21 | 1))
        goto LABEL_25;
      goto LABEL_24;
    }
LABEL_22:
    v21 = 1;
    if (!text2)
      goto LABEL_23;
    goto LABEL_18;
  }
  if (v15[2].klass)
    goto LABEL_22;
  if (!v15[2].monitor)
    goto LABEL_25;
LABEL_24:
  if (!HIDWORD(v15[4].monitor))
  {
    HIDWORD(v15[4].monitor) = 2;
    v15[5].klass = text1;
    v15[5].monitor = text2;
LABEL_34:
    LODWORD(v15[4].monitor) = col;
    goto LABEL_35;
  }
LABEL_25:
  nbHelpOff();
  v15[1].monitor = text1;
  v15[2].klass = text2;
  v15[2].monitor = 0;
  if (type != 1)
    goto LABEL_34;
  v25 = v15[6].monitor;
  monitor_high = HIDWORD(v15[6].monitor);
  LODWORD(v15[6].klass) = v25;
  HIDWORD(v15[6].klass) = monitor_high;
  LODWORD(v15[4].monitor) = col;
  itfMesMngRequestMessage(v25, monitor_high, 0, 2);
  v15[2].monitor = itfMesMngGetStrImmediate(v15[6].klass, HIDWORD(v15[6].klass), 0, 0);
LABEL_35:
  LODWORD(v15[1].klass) = type;
  LODWORD(v15[3].klass) = 0;
  HIDWORD(v15[3].klass) = max;
}

// 0x1972160
void nbHelpOff(void) {
  Il2CppObject *ProcessData;
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  void **p_monitor;
  s32 v10;
  s32 v11;
  dds3ProcessID_t_o *v12;
  u64 v13[3];

  v12 = 0;
  v12 = dds3SearchProcessName("nb_help");
  ProcessData = dds3GetProcessData(&v12);
  v4 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbHelpProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, nbHelpProcessData_t, v13);
      if ((v13[0] & 1) != 0)
        v7 = v13[2];
      else
        v7 = v13 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  p_monitor = &ProcessData[1].monitor;
  v10 = ProcessData[1].klass;
  if (ProcessData[1].monitor)
  {
    *p_monitor = 0;
    ProcessData[2].klass = 0;
    if (v10 != 1)
      return;
  }
  else
  {
    if (v10 != 1 || (ProcessData[6].klass & 0x80000000) != 0)
      return;
    *p_monitor = 0;
    ProcessData[2].klass = 0;
  }
  v11 = ProcessData[6].klass;
  itfMesMngRequestMessageRelease(v11, 0);
  v4[2].monitor = 0;
  LODWORD(v4[6].klass) = -1;
}

// 0x1972cb0
void *nbHelpProcess1(dds3ProcessID_t *id) {
  Il2CppObject *ProcessData;
  nbHelpProcessData_t_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppObject *v6;
  char *v7;
  s64 *v8;
  UnityEngine_Object_o *BattleUI;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v13;
  UnityEngine_GameObject_o *gameObject;
  System_String_o *monitor;
  s32 v18;
  Il2CppObject *v19;
  Il2CppObject *Component_object;
  System_String_o *v22;
  Il2CppObject *v24;
  System_String_o *v25;
  System_String_o *text;
  s32 v27;
  s32 klass_high;
  Il2CppObject *v30;
  dds3ProcessID_t_o *v31[3];
  dds3ProcessID_t_o *ida;

  ida = id;
  v30 = 0;
  ProcessData = dds3GetProcessData(&ida);
  if (!ProcessData)
    goto LABEL_13;
LABEL_6:
  klass = ProcessData->klass;
  v6 = ProcessData;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbHelpProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbHelpProcessData_t, v31);
    if ((v31[0] & 1) != 0)
      v7 = v31[2];
    else
      v7 = v31 + 1;
    v8 = sub_8C4940(v7);
  }
  v30 = ProcessData;
  BattleUI = GetBattleUI(3, v3);
  if (op_Equality(BattleUI, 0, 0))
    return 0;
  transform = get_transform(BattleUI, 0);
  v13 = Find(transform, "stretch/TextTM", 0);
  gameObject = get_gameObject(v13);
  monitor = v6[1].monitor;
  v18 = v6[1].klass;
  if (!monitor)
  {
    if (v18 != 1 || (v6[6].klass & 0x80000000) != 0)
    {
      if (v6[2].monitor && HIDWORD(v6[4].monitor))
        goto LABEL_78;
      if (op_Inequality(BattleUI, 0, 0) && get_activeSelf(BattleUI))
      {
        if (op_Inequality(BattleUI, 0, 0) && get_activeSelf(BattleUI))
          SetActive(BattleUI, 0, 0);
      }
      return 0;
    }
    v19 = v6 + 1;
    goto LABEL_30;
  }
  v19 = v6 + 1;
  if (v18 && v18 != 2)
  {
    if (v18 != 1)
      goto LABEL_74;
LABEL_30:
    if (!IsNullOrEmpty(v6[2].monitor))
    {
      if (!get_activeSelf(BattleUI))
        SetActive(BattleUI, 1, 0);
      Component_object = GetComponent_object_(gameObject);
      v22 = v6[2].monitor;
      goto LABEL_72;
    }
    goto LABEL_35;
  }
  if (!IsNullOrEmpty(monitor))
  {
    if (!HIDWORD(v6[4].monitor) && !get_activeSelf(BattleUI))
      SetActive(BattleUI, 1, 0);
    v24 = GetComponent_object_(gameObject);
    v25 = v6[1].monitor;
    if (!IsNullOrEmpty(v6[2].klass))
      v25 = Concat_5221536(v25, "　", v6[2].klass);
    text = get_text(v24);
    if (!Equals_5234480(text, v25))
    {
      Component_object = v24;
      v22 = v25;
LABEL_72:
      set_text(Component_object, v22);
    }
LABEL_73:
    if (LODWORD(v19->klass) != 1)
      goto LABEL_74;
    goto LABEL_77;
  }
LABEL_35:
  if (!op_Inequality(BattleUI, 0, 0) || !get_activeSelf(BattleUI))
    goto LABEL_73;
  SetActive(BattleUI, 0, 0);
  if (LODWORD(v19->klass) != 1)
  {
LABEL_74:
  }
LABEL_77:
  if (HIDWORD(v6[4].monitor))
  {
LABEL_78:
    WaitDisp(&v30, BattleUI);
    return 0;
  }
  v27 = v6[3].klass;
  klass_high = HIDWORD(v6[3].klass);
  LODWORD(v6[3].klass) = v27 + 1;
  if (klass_high < 1 || v27 < klass_high)
  {
    if (LODWORD(v19->klass) == 1
    {
    }
  }
  else
  {
    nbHelpOff();
  }
  return 0;
}

// 0x1973430
void *nbHelpShutdown(dds3ProcessID_t *id) {
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  void **p_monitor;
  s32 v8;
  dds3ProcessID_t_o *v10[3];
  dds3ProcessID_t_o *ida;

  ida = id;
  else
  {
    ProcessData = dds3GetProcessData(&ida);
    if (!ProcessData)
      goto LABEL_12;
  }
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbHelpProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbHelpProcessData_t, v10);
    if ((v10[0] & 1) != 0)
      v5 = v10[2];
    else
      v5 = v10 + 1;
    v6 = sub_8C4940(v5);
  }
LABEL_12:
  p_monitor = &ProcessData[1].monitor;
  v8 = ProcessData[1].klass;
  if (ProcessData[1].monitor)
  {
    *p_monitor = 0;
    ProcessData[2].klass = 0;
    if (v8 != 1)
      return 0;
    goto LABEL_18;
  }
  if (v8 == 1 && (ProcessData[6].klass & 0x80000000) == 0)
  {
    *p_monitor = 0;
    ProcessData[2].klass = 0;
LABEL_18:
    LODWORD(ProcessData[6].klass) = -1;
  }
  return 0;
}

// 0x1973610
void nbInitHelpProcess(nbMainProcessData_t *data) {
  nbHelpProcessData_t_o *v3;
  u64 *v4;
  u64 *v5;
  dds3ProcessID_t_o *target;

  target = 0;
LABEL_7:
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
  target = dds3StartProcess("nb_help", 0x3F9u, 1, 1, v4, 0, v5, 0, v3, 0);
  dds3LinkProcess(&data->MainProcessID, &target);
  data->HelpProcessID = target;
}
