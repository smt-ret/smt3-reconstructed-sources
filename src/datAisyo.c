#include "types.h"

typedef struct DLCDevilData DLCDevilData;

static u32 *tbl[448];

void DLCDevilAssetLoad(void);
u32 GetDevilAisyoData(DLCDevilData *this, s32 id, s32 attr);
bool dds3CheckDLC6(void);
bool dds3CheckDLC7(void);

// 0x161f780
u32 Get(s32 id, s32 attr, u32 su_flag) {
  char v4;
  s32 v8;
  u32 DevilAisyoData;
  struct System_UInt32_array_array *tbl;
  System_UInt32_array *v13;
  s32 Bit;

  v4 = su_flag;
  if ((id & 0xFFFFFFF0) == 0x1D0)
  {
    else if (!dds3CheckDLC7())
    {
      goto LABEL_31;
    }
    DLCDevilAssetLoad();
    v8 = id - 464;
    goto LABEL_19;
  }
  if ((id & 0xFFFFFFF0) == 0x1C0)
  {
    else if (dds3CheckDLC6())
    {
      goto LABEL_8;
    }
LABEL_31:
    DevilAisyoData = 100;
    goto LABEL_32;
  }
  v13 = tbl->m_Items[id];
  DevilAisyoData = v13->m_Items[attr];
LABEL_32:
  Bit = cfgGetBit(9u);
  if (DevilAisyoData && (v4 & 0x20) != 0 && !Bit && DevilAisyoData - 1 <= 0x31)
    return DevilAisyoData & 0xFFFF0000 | 0x4B;
  return DevilAisyoData;
}
