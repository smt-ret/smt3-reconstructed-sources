#include "types.h"

typedef struct sdfPadCb_t sdfPadCb_t;

static u8 sdfPadManagerMode;
static s8 *sdfPadMap[2];
static u16 sdfPadData[2];
static u8 **sdfPadAnalog[2];
static u8 *sdfPadPress[2];
static u16 sdfPadDataLast[2];
static s32 sdfPadRepCount[2];
static sdfPadCb_t *sdfPadCb[2];
static u8 *sdfPadPortSlot[2];
static u8 sdfPadWork_act_align[6];

void SetVib(s32 index, s32 value0, s32 value1);
void SetVib0(s32 index, s32 value0);
void SetVib1(s32 index, s32 value1);

// 0x15ded40
void sdfPadChangeMode(s32 aPadNum, s32 mode) {
  u8 v3;
  struct sdfPadCb_t_array *sdfPadCb;

  v3 = mode;
  sdfPadCb->m_Items[aPadNum]->reqMode = v3;
}

// 0x15de940
void sdfPadControl(void) {
  if (!LODWORD(sdfPadCb->max_length))
    goto LABEL_10;
LABEL_6:
}

// 0x15d2c50
void sdfPadInitManager(void) {
  u64 v2;
  s32 *v4;
  s32 *sdfPadCb;
  u64 *v7;
  struct System_Byte_array_array *sdfPadPortSlot;
  System_Byte_array *v11;
  struct System_Byte_array_array *v12;
  u8 v13;
  System_Byte_array *v14;
  u8 v16;
  struct sdfPadCb_t_array *v17;
  sdfPadCb_t_o *v19;
  struct System_Int16_array *actData;
  struct System_Int16_array *v22;
  struct System_Byte_array_array *v25;
  System_Byte_array *v26;
  struct System_Byte_array_array *v27;
  u8 v28;
  System_Byte_array *v29;
  u8 v31;
  struct sdfPadCb_t_array *v32;
  sdfPadCb_t_o *v34;
  struct System_Int16_array *v35;
  struct System_Int16_array *v37;

  v2 = 0;
  {
LABEL_6:
  }
  while (1)
  {
    if (v2 >= sdfPadCb[6])
      break;
    v7 = Allocate(sdfPadCb_t);
    _ctor(v7, 0);
    v4 = &sdfPadCb[2 * v2++];
    *(v4 + 4) = v7;
      goto LABEL_6;
  }
  if (!LODWORD(sdfPadPortSlot->max_length))
    goto LABEL_53;
LABEL_20:
  v11 = sdfPadPortSlot->m_Items[0];
  v12 = sdfPadPortSlot;
  v13 = v11->m_Items[0];
  v14 = v12->m_Items[0];
  v16 = v14->m_Items[1];
  v17 = sdfPadCb;
  v19 = v17->m_Items[0];
  v19->port = v13;
  actData = v19->actData;
  v19->slot = v16;
  v19->stat = 0;
  v19->lastPadData = 0;
  *&v19->mode = 0;
  actData->m_Items[0] = 0;
  v22 = v19->actData;
  v22->m_Items[1] = 0;
  v25 = sdfPadPortSlot;
  v26 = v25->m_Items[1];
  v27 = sdfPadPortSlot;
  v28 = v26->m_Items[0];
  v29 = v27->m_Items[1];
  v31 = v29->m_Items[1];
  v32 = sdfPadCb;
  v34 = v32->m_Items[1];
  v34->port = v28;
  v35 = v34->actData;
  v34->slot = v31;
  v34->stat = 0;
  v34->lastPadData = 0;
  *&v34->mode = 0;
  v35->m_Items[0] = 0;
  v37 = v34->actData;
  v37->m_Items[1] = 0;
  sdfPadManagerMode = 0;
}

// 0x15dea30
void sdfPadManager(void) {
  u32 sdfVSyncCount;
  struct sdfPadCb_t_array *sdfPadCb;
  sdfPadCb_t_o *v7;
  struct System_UInt16_array *sdfPadData;
  u32 v9;
  s32 padData;
  s32 lastPadData;
  u32 v13;
  s32 v14;
  u64 i;
  struct System_SByte_array_array *sdfPadMap;
  System_SByte_array *v18;
  char *v20;
  struct sdfPadCb_t_array *v23;
  struct System_UInt16_array *v25;
  sdfPadCb_t_o *v26;
  s32 v27;
  s32 v29;
  s32 v30;
  u64 j;
  struct System_SByte_array_array *v34;
  System_SByte_array *v35;
  s64 v37;

  else
  {
    if (!LODWORD(sdfPadCb->max_length))
      goto LABEL_9;
  }
  v7 = sdfPadCb->m_Items[0];
  v9 = sdfVSyncCount + 15;
  padData = v7->padData;
  sdfPadData->m_Items[0] = padData;
  lastPadData = v7->lastPadData;
  v13 = sdfVSyncCount + 4;
  v7->lastPadData = padData;
  if (padData == lastPadData)
  {
    if (padData)
    {
      v14 = sdfVSyncCount - v7->repeatLapse;
      if (v14 >= 0)
        v7->repeatLapse = v13 + v14;
    }
  }
  else
  {
    v7->repeatLapse = v9;
  }
  for (i = 0; i != 16; ++i)
  {
    else
    {
      if (!LODWORD(sdfPadMap->max_length))
      {
LABEL_19:
      }
    }
    v18 = sdfPadMap->m_Items[0];
    v20 = v18 + i;
    v20[32] = 0;
  }
  v23 = sdfPadCb;
  v25 = sdfPadData;
  v26 = v23->m_Items[1];
  v27 = v26->padData;
  v25->m_Items[1] = v27;
  v29 = v26->lastPadData;
  v26->lastPadData = v27;
  if (v27 == v29)
  {
    if (v27)
    {
      v30 = sdfVSyncCount - v26->repeatLapse;
      if (v30 >= 0)
        v26->repeatLapse = v13 + v30;
    }
  }
  else
  {
    v26->repeatLapse = v9;
  }
  for (j = 0; j != 16; ++j)
  {
    v34 = sdfPadMap;
    v35 = v34->m_Items[1];
    v37 = v35 + j;
    *(v37 + 32) = 0;
  }
}

// 0x15defe0
void sdfPadSetAct(s32 pad, s32 value0, s32 value1) {
  struct sdfPadCb_t_array *sdfPadCb;
  struct System_Int16_array *actData;
  struct sdfPadCb_t_array *v12;
  struct System_Int16_array *v14;

  actData = sdfPadCb->m_Items[pad]->actData;
  actData->m_Items[0] = value0;
  v12 = sdfPadCb;
  v14 = v12->m_Items[pad]->actData;
  v14->m_Items[1] = value1;
  SetVib(pad, value0, value1);
}

// 0x15dedf0
void sdfPadSetAct0(s32 pad, s32 value) {
  struct sdfPadCb_t_array *sdfPadCb;
  struct System_Int16_array *actData;

  actData = sdfPadCb->m_Items[pad]->actData;
  actData->m_Items[0] = value;
  SetVib0(pad, value);
}

// 0x15deee0
void sdfPadSetAct1(s32 pad, s32 value) {
  struct sdfPadCb_t_array *sdfPadCb;
  struct System_Int16_array *actData;

  actData = sdfPadCb->m_Items[pad]->actData;
  actData->m_Items[1] = value;
  SetVib1(pad, value);
}

// 0x15de930
void sdfPadWork(sdfPadCb_t *cb) {
  ;
}
