#include "types.h"

typedef struct dds3DebugCons dds3DebugCons;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;

// 0x152fbd0
dds3ProcessFunc_t *dds3DebugConsProcess(dds3DebugCons *this, dds3ProcessID_t *id) {
  return 0;
}

// 0x152fbe0
void dds3DebugConsShutdown(dds3DebugCons *this, dds3ProcessID_t *id) {
  ;
}

// 0x152fbf0
void dds3Printf(char *str, void **LegacyParamArray) {
  Il2CppObject *v6;

  v6 = Format_5268784(str, LegacyParamArray);
  Log(v6, 0);
}
