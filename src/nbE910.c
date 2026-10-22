#include "types.h"

typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct nbE910_funcDelegate nbE910_funcDelegate;
typedef struct nbEventProcessData_t nbEventProcessData_t;

static nbE910_funcDelegate *func[2];

void *dds3GetProcessData(dds3ProcessID_t **id);
void nbPanelAllHide(void);
void nbUpdateEventProcessData(dds3ProcessID_t **id);

// 0x16fe130
s32 End(nbEventProcessData_t *ed) {
  if (ed->seqtime < 61)
    return 0;
  Write("カグツチ死亡\n", 0);
  ed->data->endtype = 8;
  return 1;
}

// 0x16fe080
s32 Test(nbEventProcessData_t *ed) {
  nbPanelAllHide();
  if (ed)
LABEL_9:
    *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x16fe1d0
void *nbE910Process_1(dds3ProcessID_t *id) {
  Il2CppObject *ProcessData;
  nbEventProcessData_t_o *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  struct nbE910_funcDelegate_array *func;
  s64 seq;
  dds3ProcessID_t_o *v16[3];
  dds3ProcessID_t_o *ida;

  ida = id;
  ProcessData = dds3GetProcessData(&ida);
  v5 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbEventProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, nbEventProcessData_t, v16);
      if ((v16[0] & 1) != 0)
        v8 = v16[2];
      else
        v8 = v16 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  seq = v5->seq;
  if (Invoke(func->m_Items[seq], v5))
  {
    ida->func_ans = -1;
  }
  else
  {
    nbUpdateEventProcessData(&ida);
  }
  return 0;
}
