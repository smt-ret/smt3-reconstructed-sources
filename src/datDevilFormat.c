#include "types.h"

typedef struct DLCDevilData DLCDevilData;
typedef struct datDevilFormat_s datDevilFormat_t;

static datDevilFormat_t *tbl;

void DLCDevilAssetLoad(void);
datDevilFormat_t *GetDevilFormatData(DLCDevilData *this, s32 id);
bool IsZensyoMode(void);
bool dds3CheckDLC6(void);
bool dds3CheckDLC7(void);

// 0x1242820
datDevilFormat_t *Analyze(s32 id) {
  s32 v4;
  struct datDevilFormat_t_array *tbl;

  v4 = convDLCDevilNumber(id);
  return tbl->m_Items[v4];
}

// 0x1242640
datDevilFormat_t *Get(s32 id, bool dlc) {
  datDevilFormat_t_o *DevilFormatData;
  DLCDevilData_o *DLCDevilDataExp;
  s32 v7;
  struct datDevilFormat_t_array *tbl;

  if (!dlc)
    goto LABEL_14;
  if ((id & 0xFFFFFFF0) != 0x180)
  {
    if ((id & 0xFFFFFFF0) == 0x170)
    {
      DevilFormatData = 0;
      if (dds3CheckDLC6())
      {
        DLCDevilAssetLoad();
        v7 = id - 368;
LABEL_36:
        DevilFormatData = GetDevilFormatData(DLCDevilDataExp, v7);
        goto LABEL_15;
      }
      goto LABEL_15;
    }
LABEL_14:
    DevilFormatData = 0;
    goto LABEL_15;
  }
  DevilFormatData = 0;
  if (dds3CheckDLC7())
  {
    DLCDevilAssetLoad();
    DLCDevilDataExp = DLCDevilDataMaka;
    v7 = id - 384;
    goto LABEL_36;
  }
LABEL_15:
  if (((id == 191) & IsZensyoMode()) != 0)
    id = 192;
  if (!DevilFormatData)
  {
    return tbl->m_Items[id];
  }
  return DevilFormatData;
}
