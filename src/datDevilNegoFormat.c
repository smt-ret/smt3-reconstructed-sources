#include "types.h"

typedef struct DLCDevilData DLCDevilData;
typedef struct datDevilNegoFormat_s datDevilNegoFormat_t;

static datDevilNegoFormat_t *tbl;

void DLCDevilAssetLoad(void);
datDevilNegoFormat_t *GetDevilNegoFormat(DLCDevilData *this, s32 id);
bool dds3CheckDLC6(void);
bool dds3CheckDLC7(void);

// 0xe5d500
datDevilNegoFormat_t *Get(s32 id) {
  DLCDevilData_o **p_DLCDevilDataMaka;
  s32 v4;
  datDevilNegoFormat_t_o *result;
  struct datDevilNegoFormat_t_array *tbl;

  if ((id & 0xFFFFFFF0) == 0x180)
  {
    else if (!dds3CheckDLC7())
    {
      goto LABEL_24;
    }
    DLCDevilAssetLoad();
    p_DLCDevilDataMaka = &DLCDevilDataMaka;
    v4 = -384;
LABEL_19:
    result = GetDevilNegoFormat(*p_DLCDevilDataMaka, v4 + id);
    if (result)
      return result;
    goto LABEL_24;
  }
  if ((id & 0xFFFFFFF0) == 0x170)
  {
    else if (dds3CheckDLC6())
    {
      goto LABEL_8;
    }
  }
LABEL_24:
  return tbl->m_Items[id];
}
