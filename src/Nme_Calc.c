#include "types.h"

typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct nmeData_t nmeData_t;

static nmeData_t *GBWK;

s32 dds3FadeCheck(void);
void *dds3GetProcessData(dds3ProcessID_t **id);

// 0xeffff0
dds3ProcessFunc_t *nmeCalc(dds3ProcessID_t *PID) {
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s32 v9;
  struct cmpSeqInfo_t_o *SeqInfo;
  dds3ProcessID_t_o *v13[3];
  dds3ProcessID_t_o *id;

  id = PID;
  ProcessData = dds3GetProcessData(&id);
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nmeData_t)
    {
      sub_8FC2C0(klass->_1.element_class, nmeData_t, v13);
      if ((v13[0] & 1) != 0)
        v6 = v13[2];
      else
        v6 = v13 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  GBWK = ProcessData;
  v9 = dds3FadeCheck();
  else if (ToBoolean_2953872(v9))
  {
    return 0;
  }
  SeqInfo = GBWK->SeqInfo;
  if ((SeqInfo->Flag & 0x10) != 0)
  {
    cmpUpdateTerminate(SeqInfo);
    id->func_ans = -1;
  }
  return 0;
}
