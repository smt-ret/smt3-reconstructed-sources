#include "types.h"

typedef struct DLCDevilData DLCDevilData;
typedef struct datEncount_s datEncount_t;

static datEncount_t *tbl;

void DLCDevilAssetLoad(void);
datEncount_t *GetDevilEncountData(DLCDevilData *this, s32 id);
bool dds3CheckDLC6(void);
bool dds3CheckDLC7(void);

// 0xdbe710
datEncount_t *Get(s32 id) {
  bool v4;
  datEncount_t_o *result;
  DLCDevilData_o *DLCDevilDataExp;
  s32 v7;
  struct datEncount_t_array *tbl;
  bool v12;

  if (id <= 1279)
  {
    return tbl->m_Items[id];
  }
  else if (id <= 1327)
  {
    v12 = dds3CheckDLC6();
    result = 0;
    if (v12)
    {
      DLCDevilAssetLoad();
      v7 = id - 1280;
      return GetDevilEncountData(DLCDevilDataExp, v7);
    }
  }
  else if (id > 1363)
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
      v7 = id - 1328;
      return GetDevilEncountData(DLCDevilDataExp, v7);
    }
  }
  return result;
}
