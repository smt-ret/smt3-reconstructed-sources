#include "types.h"

typedef struct RippleEffect RippleEffect;

static u32 **dds3PrivatePadMapRepeat[2];
static u32 *dds3PrivatePadAnalogRepeat[UNKNOWN_ARRAY_SIZE];
static u8 **dds3PrivatePadMap[UNKNOWN_ARRAY_SIZE];
static u8 **dds3PrivatePadAnalog[UNKNOWN_ARRAY_SIZE];
static u8 *dds3PrivatePadAnalogMap[UNKNOWN_ARRAY_SIZE];
static u8 **dds3PadMap[UNKNOWN_ARRAY_SIZE];
static u8 **dds3PadAnalog[UNKNOWN_ARRAY_SIZE];
static u8 *dds3PadAnalogMap[UNKNOWN_ARRAY_SIZE];
static s32 dbg_2p;
static u8 dds3PadActPow[UNKNOWN_ARRAY_SIZE];
static u8 dds3PadActPow_goal[2];
static u32 dds3PadActFrame[2];

u64 GetCurrentKey(s32 kind);
void Init(void);
f32 SDF_VU0__GETLENGTH(void);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void Update(RippleEffect *this);
s32 dds3CheckConfigBit(u32 Type);
void dds3PadAct2Sub(void);
void dds3PadActUpdate(void);
void effPadVibeFadeUpdate(void);
void sdfPadSetAct(s32 pad, s32 value0, s32 value1);
void sdfPadSetAct0(s32 pad, s32 value);
void sdfPadSetAct1(s32 pad, s32 value);

// 0x14f6620
bool DDS3_ANALOG2CHECK_PRESS(s32 id) {
  struct System_Byte_array_array *dds3PadAnalogMap;
  System_Byte_array *v6;

  v6 = dds3PadAnalogMap->m_Items[1];
  return v6->m_Items[id] != 0;
}

// 0x14f67c0
bool DDS3_ANALOG2CHECK_REP(s32 id) {
  struct System_Byte_array_array *dds3PadAnalogMap;
  System_Byte_array *v6;

  v6 = dds3PadAnalogMap->m_Items[1];
  return (v6->m_Items[id] >> 1) & 1;
}

// 0x14f66f0
bool DDS3_ANALOG2CHECK_TRIG(s32 id) {
  struct System_Byte_array_array *dds3PadAnalogMap;
  System_Byte_array *v6;

  v6 = dds3PadAnalogMap->m_Items[1];
  return (v6->m_Items[id] & 0x80u) != 0;
}

// 0x14f6390
bool DDS3_ANALOGCHECK_PRESS(s32 id) {
    return 0;
}

// 0x14f6550
bool DDS3_ANALOGCHECK_REP(s32 id) {
    return 0;
}

// 0x14f6470
bool DDS3_ANALOGCHECK_TRIG(s32 id) {
    return 0;
}

// 0x14f60d0
bool DDS3_PAD2CHECK_PRESS(s32 id) {
  struct System_Byte_array_array_array *dds3PadMap;
  System_Byte_array_array *v6;
  System_Byte_array *v8;

  v6 = dds3PadMap->m_Items[1];
  v8 = v6->m_Items[1];
  return v8->m_Items[id] != 0;
}

// 0x14f5b10
bool DDS3_PAD2CHECK_PRESS2(s32 id) {
  struct System_Byte_array_array_array *dds3PadMap;
  System_Byte_array_array *v4;
  System_Byte_array *v6;

  if (!LODWORD(dds3PadMap->max_length))
  v4 = dds3PadMap->m_Items[0];
  v6 = v4->m_Items[1];
  return v6->m_Items[id] != 0;
}

// 0x14f62b0
bool DDS3_PAD2CHECK_REP(s32 id) {
  struct System_Byte_array_array_array *dds3PadMap;
  System_Byte_array_array *v6;
  System_Byte_array *v8;

  v6 = dds3PadMap->m_Items[1];
  v8 = v6->m_Items[1];
  return (v8->m_Items[id] >> 1) & 1;
}

// 0x14f5d30
bool DDS3_PAD2CHECK_REP2(s32 id) {
  struct System_Byte_array_array_array *dds3PadMap;
  System_Byte_array_array *v4;
  System_Byte_array *v6;

  if (!LODWORD(dds3PadMap->max_length))
  v4 = dds3PadMap->m_Items[0];
  v6 = v4->m_Items[1];
  return (v6->m_Items[id] >> 1) & 1;
}

// 0x14f6a20
u32 DDS3_PAD2CHECK_REPTIME(s32 id) {
  struct System_UInt32_array_array_array *dds3PrivatePadMapRepeat;
  System_UInt32_array_array *v6;
  System_UInt32_array *v8;
  struct System_UInt32_array_array_array *v11;
  System_UInt32_array_array *v12;
  System_UInt32_array *v13;

  v6 = dds3PrivatePadMapRepeat->m_Items[1];
  v8 = v6->m_Items[1];
  if (v8->m_Items[id] < 8)
    return 0;
  v11 = dds3PrivatePadMapRepeat;
  v12 = v11->m_Items[1];
  v13 = v12->m_Items[1];
  return v13->m_Items[id] - 8;
}

// 0x14f61c0
bool DDS3_PAD2CHECK_TRIG(s32 id) {
  struct System_Byte_array_array_array *dds3PadMap;
  System_Byte_array_array *v6;
  System_Byte_array *v8;

  v6 = dds3PadMap->m_Items[1];
  v8 = v6->m_Items[1];
  return (v8->m_Items[id] & 0x80u) != 0;
}

// 0x14f5c20
bool DDS3_PAD2CHECK_TRIG2(s32 id) {
  struct System_Byte_array_array_array *dds3PadMap;
  System_Byte_array_array *v4;
  System_Byte_array *v6;

  if (!LODWORD(dds3PadMap->max_length))
  v4 = dds3PadMap->m_Items[0];
  v6 = v4->m_Items[1];
  return (v6->m_Items[id] & 0x80u) != 0;
}

// 0x14f5e30
bool DDS3_PADCHECK_PRESS(s32 id) {
  struct System_Byte_array_array_array *dds3PadMap;
  System_Byte_array_array *v6;
  System_Byte_array *v8;

  v6 = dds3PadMap->m_Items[1];
  v8 = v6->m_Items[0];
  return v8->m_Items[id] != 0;
}

// 0x14f5910
bool DDS3_PADCHECK_PRESS2(s32 id) {
  struct System_Byte_array_array_array *dds3PadMap;
  System_Byte_array_array *v4;
  System_Byte_array *v5;

  if (!LODWORD(dds3PadMap->max_length))
  v4 = dds3PadMap->m_Items[0];
  v5 = v4->m_Items[0];
  return v5->m_Items[id] != 0;
}

// 0x14f5ff0
bool DDS3_PADCHECK_REP(s32 id) {
  struct System_Byte_array_array_array *dds3PadMap;
  System_Byte_array_array *v6;
  System_Byte_array *v8;

  v6 = dds3PadMap->m_Items[1];
  v8 = v6->m_Items[0];
  return (v8->m_Items[id] >> 1) & 1;
}

// 0x14f5a10
bool DDS3_PADCHECK_REP2(s32 id) {
  struct System_Byte_array_array_array *dds3PadMap;
  System_Byte_array_array *v4;
  System_Byte_array *v5;

  if (!LODWORD(dds3PadMap->max_length))
  v4 = dds3PadMap->m_Items[0];
  v5 = v4->m_Items[0];
  return (v5->m_Items[id] >> 1) & 1;
}

// 0x14f6880
u32 DDS3_PADCHECK_REPTIME(s32 id) {
  struct System_UInt32_array_array_array *dds3PrivatePadMapRepeat;
  System_UInt32_array_array *v6;
  System_UInt32_array *v8;
  struct System_UInt32_array_array_array *v11;
  System_UInt32_array_array *v12;
  System_UInt32_array *v13;

  v6 = dds3PrivatePadMapRepeat->m_Items[1];
  v8 = v6->m_Items[0];
  if (v8->m_Items[id] < 8)
    return 0;
  v11 = dds3PrivatePadMapRepeat;
  v12 = v11->m_Items[1];
  v13 = v12->m_Items[0];
  return v13->m_Items[id] - 8;
}

// 0x14f5f10
bool DDS3_PADCHECK_TRIG(s32 id) {
  struct System_Byte_array_array_array *dds3PadMap;
  System_Byte_array_array *v6;
  System_Byte_array *v8;

  v6 = dds3PadMap->m_Items[1];
  v8 = v6->m_Items[0];
  return (v8->m_Items[id] & 0x80u) != 0;
}

// 0x14e4760
bool DDS3_PADCHECK_TRIG2(s32 id) {
  struct System_Byte_array_array_array *dds3PadMap;
  System_Byte_array_array *v4;
  System_Byte_array *v5;

  if (!LODWORD(dds3PadMap->max_length))
  v4 = dds3PadMap->m_Items[0];
  v5 = v4->m_Items[0];
  return (v5->m_Items[id] & 0x80u) != 0;
}

// 0x14e4990
void dds3PadAct(u32 mode, u8 pow, u32 frame) {
  u8 v5;
  _BOOL8 v9;
  Il2CppClass *declaringType;
  Il2CppClass *v13;
  struct System_Byte_array *dds3PadActPow;
  struct System_UInt32_array *dds3PadActFrame;
  struct System_Byte_array *v20;
  s32 v22;

  v5 = pow;
  else if (!dds3CheckConfigBit(0xAu))
  {
    return;
  }
  if (!mode)
    v5 = v5 != 0;
  v9 = mode != 0;
  if (mode)
  {
    declaringType = v8[2].klass->_1.declaringType;
    *(&declaringType->_1.byval_arg.data + v9) = v5;
    dds3PadAct2Sub();
  }
  else
  {
    v13 = v8[2].klass->_1.declaringType;
    *(&v13->_1.byval_arg.data + v9) = v5;
    dds3PadActPow->m_Items[v9] = v5;
  }
  dds3PadActFrame->m_Items[v9] = frame;
  if (mode)
  {
    v20 = dds3PadActPow;
    v22 = v20->m_Items[v9];
    sdfPadSetAct1(0, v22);
  }
  else
  {
    sdfPadSetAct0(0, v5);
  }
}

// 0x14f6eb0
void dds3PadAct2Sub(void) {
  dds3PadManager_c *v2;
  struct dds3PadManager_StaticFields *static_fields;
  struct System_Byte_array *dds3PadActPow_goal;
  struct System_Byte_array *dds3PadActPow;
  u32 v7;
  struct System_Byte_array *v9;
  struct System_Byte_array *v11;
  s16 v13;
  struct System_Byte_array *v14;
  struct System_Byte_array *v16;
  struct System_Byte_array *v18;
  struct System_Byte_array *v20;

  static_fields = v2->static_fields;
  dds3PadActPow_goal = static_fields->dds3PadActPow_goal;
  dds3PadActPow = static_fields->dds3PadActPow;
  v7 = dds3PadActPow_goal->m_Items[1];
  if (dds3PadActPow->m_Items[1] >= v7)
  {
    v11 = dds3PadActPow;
    v13 = *&v2->_2.bitflags1;
    if (v11->m_Items[1] <= v7)
    v14 = dds3PadActPow;
    v13 = *&v2->_2.bitflags1;
    if ((v14->m_Items[1] - v7) < 33)
    {
      v16 = dds3PadActPow;
      v16->m_Items[1] = v7;
      return;
    }
    v20 = dds3PadActPow;
    v20->m_Items[1] -= 32;
  }
  else
  {
    v9 = dds3PadActPow;
    if ((v7 - v9->m_Items[1]) < 33)
    {
      if ((*&v2->_2.bitflags1 & 0x200) != 0)
    }
    v18 = dds3PadActPow;
    v18->m_Items[1] += 32;
  }
}

// 0x14f7160
void dds3PadActAllStop(void) {
    sdfPadSetAct(0, 0, 0);
}

// 0x14f6bd0
void dds3PadActUpdate(void) {
  s64 v2;
  u64 v4;
  struct System_UInt32_array *dds3PadActFrame;
  struct System_UInt32_array *v8;
  struct System_UInt32_array *v10;
  struct System_Byte_array *dds3PadActPow;
  dds3PadManager_c *v15;
  struct dds3PadManager_StaticFields *static_fields;
  struct System_Byte_array *v17;
  struct System_Byte_array *dds3PadActPow_goal;
  s32 v20;
  s32 v21;
  struct System_Byte_array *v25;
  s32 v27;

  v2 = 0;
  do
  {
    while (1)
    {
      v4 = v2;
      if (!dds3PadActFrame->m_Items[v4])
      v8 = dds3PadActFrame;
      --v8->m_Items[v4];
      v10 = dds3PadActFrame;
      if (v10->m_Items[v4])
        break;
      dds3PadActPow->m_Items[v4] = 0;
      if (v4)
      {
        v21 = 0;
      }
      sdfPadSetAct0(0, 0);
      v2 = 1;
      if (v4)
        return;
    }
    v2 = 1;
  }
  while (v4 != 1);
  static_fields = v15->static_fields;
  v17 = static_fields->dds3PadActPow;
  dds3PadActPow_goal = static_fields->dds3PadActPow_goal;
  v20 = v17->m_Items[1];
  if (v20 != dds3PadActPow_goal->m_Items[1])
  {
    dds3PadAct2Sub();
    v25 = dds3PadActPow;
    v27 = v25->m_Items[1];
    v21 = v27;
    sdfPadSetAct1(0, v21);
  }
}

// 0x14f72b0
u32 dds3PadGetPadMap(void) {
  u64 v2;
  u32 v3;
  struct System_Byte_array_array_array *dds3PadMap;
  System_Byte_array_array *v8;
  System_Byte_array *v9;
  s32 v11;

  v2 = 0;
  v3 = 0;
  do
  {
    v8 = dds3PadMap->m_Items[1];
    v9 = v8->m_Items[0];
    v11 = (v9->m_Items[v2] != 0) << v2;
    ++v2;
    v3 |= v11;
  }
  while (v2 != 16);
  return v3;
}

// 0x14dfc00
void dds3PadInitialize(void) {
    Init();
}

// 0x14e21e0
void dds3PadUpdate(void) {
    Update(0);
    GetCurrentKey(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__GETLENGTH();
    dds3PadActUpdate();
    effPadVibeFadeUpdate();
}
