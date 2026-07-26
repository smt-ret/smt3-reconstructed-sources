#include "types.h"

typedef struct DLCDevilData DLCDevilData;
typedef struct datEncountPack_s datEncountPack_t;

static s32 datEncountBase;
static datEncountPack_t tbl[UNKNOWN_ARRAY_SIZE];

void DLCDevilAssetLoad(void);
datEncountPack_t *GetDevilEncountPackData(DLCDevilData *this, s32 id);
bool dds3CheckDLC6(void);
bool dds3CheckDLC7(void);

// 0xa71000
bool ChkLength(s32 id) {
  if (SLODWORD(tbl->max_length) > id)
    return 1;
  if (id <= 259)
  {
    else
    {
      return dds3CheckDLC6();
    }
  }
  else if (id > 262)
  {
    return 0;
  }
  else
  {
    return dds3CheckDLC7();
  }
}

// 0xa70e50
datEncountPack_t *Get(s32 id) {
  bool v4;
  datEncountPack_t_o *result;
  DLCDevilData_o *DLCDevilDataExp;
  s32 v7;
  struct datEncountPack_t_array *tbl;
  bool v12;

  if (id <= 255)
  {
    return tbl->m_Items[id];
  }
  else if (id <= 259)
  {
    v12 = dds3CheckDLC6();
    result = 0;
    if (v12)
    {
      DLCDevilAssetLoad();
      v7 = id - 256;
      return GetDevilEncountPackData(DLCDevilDataExp, v7);
    }
  }
  else if (id > 262)
  {
    return 0;
  }
  else
  {
    v4 = dds3CheckDLC7();
    result = 0;
    if (v4)
    {
      DLCDevilAssetLoad();
      DLCDevilDataExp = DLCDevilDataMaka;
      v7 = id - 260;
      return GetDevilEncountPackData(DLCDevilDataExp, v7);
    }
  }
  return result;
}
