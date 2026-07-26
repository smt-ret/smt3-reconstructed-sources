#include "types.h"

s32 sdfGetRunTimeCount(s32 aBaseTime);
s32 sdfGetRunTimeCountBase(void);

// 0x17935f0
void sdfIopInit(char *iopName, char *msifName) {
  s32 RunTimeCountBase;

  while (1)
  {
    RunTimeCountBase = sdfGetRunTimeCountBase();
    do
    {
    }
    while (sdfGetRunTimeCount(RunTimeCountBase) <= 0x1ED1);
  }
}

// 0x17934c0
s32 sdfIopLoadStartModule(char *filename, s32 args, char *argp, s32 *result) {
  u64 *v9;
  sdfIopLoadStartModuleParm_t_o *v10;
  sdfIopLoadStartModuleResult_t_o *v11;
  s32 Length;

  v9 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v9);
  v10 = Allocate(sdfIopLoadStartModuleParm_t);
  sdfIopLoadStartModuleParm_t___ctor(v10);
  v11 = Allocate(sdfIopLoadStartModuleResult_t);
  sdfIopLoadStartModuleResult_t___ctor(v11);
  Length = get_Length(filename);
  {
  }
  SizeOf_sdfMemRecord_t_(v10);
  v10->filenameLeng = Length;
  v10->args = args;
  v10->filename = filename;
  if (args)
    v10->filename = Concat_5224608(filename, argp);
  *result = v11->iopResult;
  return v11->result;
}
