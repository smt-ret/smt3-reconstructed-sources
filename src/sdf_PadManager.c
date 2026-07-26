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
}

// 0x15d2c50
void sdfPadInitManager(void) {
  u64 v2;
  sdf_PadManager_c *v3;
  s32 *v4;
  struct sdf_PadManager_StaticFields *static_fields;
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
  }
  while (1)
  {
    static_fields = v3->static_fields;
    sdfPadCb = static_fields->sdfPadCb;
    if (v2 >= sdfPadCb[6])
      break;
    v7 = Allocate(sdfPadCb_t);
    _ctor(v7, 0);
    v4 = &sdfPadCb[2 * v2++];
    *(v4 + 4) = v7;
  }
  if (!LODWORD(sdfPadPortSlot->max_length))
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
