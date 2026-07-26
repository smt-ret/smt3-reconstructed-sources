#include "types.h"

typedef struct DLCDevilData DLCDevilData;
typedef struct datDevilAI_s datDevilAI_t;
typedef struct datDevilAI_t2 datDevilAI_t2;

static datDevilAI_t tbl[UNKNOWN_ARRAY_SIZE];

void DLCDevilAssetLoad(void);
datDevilAI_t2 *GetDevilAIData(DLCDevilData *this, s32 id);
void datDevilAI_t2__Copy(datDevilAI_t2 *this, datDevilAI_t **data);
bool dds3CheckDLC6(void);
bool dds3CheckDLC7(void);

// 0xccbe10
datDevilAI_t *Get(s32 id) {
  DLCDevilData_o *DLCDevilDataMaka;
  s32 v4;
  datDevilAI_t2_o *DevilAIData;
  u64 *v6;
  datDevilAI_t_o *result;
  struct datDevilAI_t_array *tbl;
  datDevilAI_t_o *data;

  data = 0;
  if ((id & 0xFFFFFFF0) == 0x180)
  {
    if (dds3CheckDLC7())
    {
      DLCDevilAssetLoad();
      v4 = id - 384;
    }
    result = data;
    if (data)
      return result;
  }
  if ((id & 0xFFFFFFF0) == 0x170)
  {
    if (dds3CheckDLC6())
    {
      DLCDevilAssetLoad();
      DLCDevilDataMaka = DLCDevilDataExp;
      v4 = id - 368;
      DevilAIData = GetDevilAIData(DLCDevilDataMaka, v4);
      v6 = Allocate(datDevilAI_t);
      datDevilAI_t___ctor(v6);
      data = v6;
      datDevilAI_t2__Copy(DevilAIData, &data);
    }
  }
  return tbl->m_Items[id];
}
