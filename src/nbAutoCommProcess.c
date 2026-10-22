#include "types.h"

typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;

bool DDS3_PADCHECK_TRIG(s32 id);
void *GetBattleUI(s32 index);
void *dds3GetProcessData(dds3ProcessID_t **id);
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
s32 nbPanelAutoCheckShow(void);
void nbPlaySe_22541600(char *no);
void nbSetAutoImage(bool flag);

// 0xfab0a0
void *nbAutoCommProcess1(dds3ProcessID_t *id) {
  Il2CppObject *ProcessData;
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  s32 monitor_high;
  bool v15;
  dds3ProcessID_t_o *v18;
  u64 v19[3];

  v18 = id;
  ProcessData = dds3GetProcessData(&v18);
  v4 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbMainProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, nbMainProcessData_t, v19);
      if ((v19[0] & 1) != 0)
        v7 = v19[2];
      else
        v7 = v19 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  if (nbPanelAutoCheckShow())
  {
    nbSetAutoImage((BYTE4(v4[7].monitor) & 0x40) != 0);
    monitor_high = HIDWORD(v4[7].monitor);
    if (dds3DebugSign != 1 || (monitor_high & 0x20000000) == 0)
    {
      if ((monitor_high & 0x40) != 0)
      {
        if (DDS3_PADCHECK_TRIG(3))
          goto LABEL_39;
        if (DDS3_PADCHECK_TRIG(2))
        {
LABEL_39:
          HIDWORD(v4[7].monitor) &= ~0x40u;
          nbPlaySe_22541600("COMSE_SE0B");
          v15 = 0;
          goto LABEL_43;
        }
      }
      else
      {
        if (DDS3_PADCHECK_TRIG(2))
        {
          HIDWORD(v4[7].monitor) |= 0x40u;
          nbPlaySe_22541600("COMSE_SE0E");
          v15 = 1;
LABEL_43:
          nbSetAutoImage(v15);
        }
      }
    }
  }
  return 0;
}

// 0xfab4a0
void nbInitAutoCommProcess(nbMainProcessData_t *data) {
  u64 *v3;
  dds3ProcessID_t_o *target;

  target = 0;
  v3 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v3,
    0,
    Method_nbAutoCommProcess_nbAutoCommProcess1__);
  target = dds3StartProcess("nb_autocomm", 0x2B0Eu, 1, 1, v3, 0, 0, 0, data, 0);
  dds3LinkProcess(&data->MainProcessID, &target);
  data->AutoCommProcessID = target;
}

// 0xfab350
void nbSetAutoImage(bool flag) {
  UnityEngine_GameObject_o *BattleUI;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v6;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v8;
  UnityEngine_Component_o *v9;
  UnityEngine_GameObject_o *v10;
  UnityEngine_GameObject_o *v11;
  bool v12;

  BattleUI = GetBattleUI(2);
  if (op_Inequality(BattleUI, 0, 0))
  {
    transform = get_transform(BattleUI, 0);
    v6 = Find(transform, "bauto/auto_off", 0);
    gameObject = get_gameObject(v6);
    v8 = get_transform(BattleUI, 0);
    v9 = Find(v8, "bauto/auto_on", 0);
    v10 = get_gameObject(v9);
    if (flag)
    {
      SetActive(gameObject, 0, 0);
      v11 = v10;
      v12 = 1;
    }
    else
    {
      SetActive(gameObject, 1, 0);
      v11 = v10;
      v12 = 0;
    }
    SetActive(v11, v12, 0);
  }
}
