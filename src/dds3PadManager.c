#include "types.h"

typedef struct RippleEffect RippleEffect;

static u32 **dds3PrivatePadMapRepeat[2];
static u32 **dds3PrivatePadAnalogRepeat;
static u8 ***dds3PrivatePadMap;
static u8 ***dds3PrivatePadAnalog;
static u8 **dds3PrivatePadAnalogMap;
static u8 ***dds3PadMap;
static u8 ***dds3PadAnalog;
static u8 **dds3PadAnalogMap;
static s32 dbg_2p;
static u8 *dds3PadActPow;
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
  struct System_Byte_array_array *dds3PadAnalogMap;
  System_Byte_array *v5;

  else
  {
    if (!LODWORD(dds3PadAnalogMap->max_length))
      goto LABEL_6;
  }
  v5 = dds3PadAnalogMap->m_Items[0];
  return v5->m_Items[id] != 0;
}

// 0x14f6550
bool DDS3_ANALOGCHECK_REP(s32 id) {
  struct System_Byte_array_array *dds3PadAnalogMap;
  System_Byte_array *v5;

  else
  {
    if (!LODWORD(dds3PadAnalogMap->max_length))
      goto LABEL_6;
  }
  v5 = dds3PadAnalogMap->m_Items[0];
  return (v5->m_Items[id] >> 1) & 1;
}

// 0x14f6470
bool DDS3_ANALOGCHECK_TRIG(s32 id) {
  struct System_Byte_array_array *dds3PadAnalogMap;
  System_Byte_array *v5;

  else
  {
    if (!LODWORD(dds3PadAnalogMap->max_length))
      goto LABEL_6;
  }
  v5 = dds3PadAnalogMap->m_Items[0];
  return (v5->m_Items[id] & 0x80u) != 0;
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
    goto LABEL_12;
LABEL_6:
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
    goto LABEL_12;
LABEL_6:
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
    goto LABEL_12;
LABEL_6:
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
    goto LABEL_11;
LABEL_6:
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
    goto LABEL_11;
LABEL_6:
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
    goto LABEL_11;
LABEL_6:
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
      goto LABEL_25;
  }
  else
  {
    v13 = v8[2].klass->_1.declaringType;
    *(&v13->_1.byval_arg.data + v9) = v5;
    dds3PadActPow->m_Items[v9] = v5;
      goto LABEL_25;
  }
LABEL_25:
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

  v7 = dds3PadActPow_goal->m_Items[1];
  if (dds3PadActPow->m_Items[1] >= v7)
  {
    v11 = dds3PadActPow;
    v13 = *&v2->_2.bitflags1;
    if (v11->m_Items[1] <= v7)
      goto LABEL_32;
    v14 = dds3PadActPow;
    v13 = *&v2->_2.bitflags1;
    if ((v14->m_Items[1] - v7) < 33)
    {
LABEL_32:
      if ((v13 & 0x200) != 0)
      {
LABEL_18:
      }
LABEL_33:
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
        goto LABEL_18;
      goto LABEL_33;
    }
    v18 = dds3PadActPow;
    v18->m_Items[1] += 32;
  }
}

// 0x14f7160
void dds3PadActAllStop(void) {
  struct System_Byte_array *dds3PadActPow;
  struct System_UInt32_array *dds3PadActFrame;
  struct System_Byte_array *v7;
  struct System_UInt32_array *v9;

  else
  {
    if (!LODWORD(dds3PadActPow->max_length))
      goto LABEL_6;
  }
  dds3PadActPow->m_Items[0] = 0;
  dds3PadActFrame->m_Items[0] = 0;
  v7 = dds3PadActPow;
  v7->m_Items[1] = 0;
  v9 = dds3PadActFrame;
  v9->m_Items[1] = 0;
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
        goto LABEL_30;
      v8 = dds3PadActFrame;
      --v8->m_Items[v4];
      v10 = dds3PadActFrame;
      if (v10->m_Items[v4])
        break;
      dds3PadActPow->m_Items[v4] = 0;
      if (v4)
      {
        v21 = 0;
        goto LABEL_54;
      }
      sdfPadSetAct0(0, 0);
LABEL_30:
      v2 = 1;
      if (v4)
        return;
    }
    v2 = 1;
  }
  while (v4 != 1);
  v17 = dds3PadActPow;
  v20 = v17->m_Items[1];
  if (v20 != dds3PadActPow_goal->m_Items[1])
  {
    dds3PadAct2Sub();
    v25 = dds3PadActPow;
    v27 = v25->m_Items[1];
    v21 = v27;
LABEL_54:
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
  s64 v5;
  u64 v7;
  u32 *dds3PrivatePadMapRepeat;
  s64 *v9;
  s64 *v11;
  struct System_UInt32_array_array_array *v14;
  System_UInt32_array_array *v16;
  s64 *v17;
  s64 *v19;
  struct System_UInt32_array_array_array *v24;
  System_UInt32_array_array *v26;
  s64 *v27;
  s64 *v28;
  struct System_UInt32_array_array *v31;
  struct System_UInt32_array_array *v33;
  dds3PadManager_c *v34;
  struct System_UInt32_array_array *dds3PrivatePadAnalogRepeat;
  s64 *v36;
  s64 *v38;
  struct System_UInt32_array_array *v42;
  s64 *v43;
  s64 *v44;
  struct System_Byte_array_array_array *v47;
  dds3PadManager_c *v48;
  u64 v49;
  u32 *dds3PrivatePadMap;
  s64 *v51;
  s64 *v53;
  struct System_Byte_array_array_array *v56;
  System_Byte_array_array *v58;
  s64 *v59;
  s64 *v61;
  struct System_Byte_array_array_array *v66;
  System_Byte_array_array *v68;
  s64 *v69;
  s64 *v70;
  struct System_Byte_array_array_array *v73;
  struct System_Byte_array_array_array *v75;
  dds3PadManager_c *v76;
  u64 v77;
  u32 *dds3PrivatePadAnalog;
  s64 *v79;
  s64 *v81;
  struct System_Byte_array_array_array *v84;
  System_Byte_array_array *v86;
  s64 *v87;
  s64 *v89;
  struct System_Byte_array_array_array *v94;
  System_Byte_array_array *v96;
  s64 *v97;
  s64 *v98;
  struct System_Byte_array_array *v101;
  struct System_Byte_array_array *v103;
  dds3PadManager_c *v104;
  struct System_Byte_array_array *dds3PrivatePadAnalogMap;
  s64 *v107;
  s64 *v109;
  struct System_Byte_array_array *v113;
  s64 *v114;
  s64 *v115;
  struct System_Byte_array_array_array *v118;
  dds3PadManager_c *v119;
  u64 v120;
  u32 *dds3PadMap;
  s64 *v122;
  s64 *v124;
  struct System_Byte_array_array_array *v127;
  System_Byte_array_array *v129;
  s64 *v130;
  s64 *v132;
  struct System_Byte_array_array_array *v137;
  System_Byte_array_array *v139;
  s64 *v140;
  s64 *v141;
  struct System_Byte_array_array_array *v144;
  struct System_Byte_array_array_array *v146;
  dds3PadManager_c *v147;
  u64 v148;
  u32 *dds3PadAnalog;
  s64 *v150;
  s64 *v152;
  struct System_Byte_array_array_array *v155;
  System_Byte_array_array *v157;
  s64 *v158;
  s64 *v160;
  struct System_Byte_array_array_array *v165;
  System_Byte_array_array *v167;
  s64 *v168;
  s64 *v169;
  struct System_Byte_array_array *v172;
  struct System_Byte_array_array *v174;
  dds3PadManager_c *v175;
  struct System_Byte_array_array *dds3PadAnalogMap;
  s64 *v178;
  s64 *v180;
  struct System_Byte_array_array *v184;
  s64 *v185;
  s64 *v186;
  struct System_Byte_array *v189;
  struct System_UInt32_array *v191;
  s64 v193;
  u64 v194;
  u64 v195;
  struct System_UInt32_array_array_array *v198;
  System_UInt32_array_array *v200;
  System_UInt32_array *v202;
  struct System_Byte_array_array_array *v204;
  System_Byte_array_array *v205;
  System_Byte_array *v207;
  struct System_Byte_array_array_array *v209;
  System_Byte_array_array *v210;
  System_Byte_array *v212;
  s64 v214;
  u64 i;
  struct System_UInt32_array_array_array *v220;
  System_UInt32_array_array *v221;
  System_UInt32_array *v223;
  struct System_Byte_array_array_array *v225;
  System_Byte_array_array *v226;
  System_Byte_array *v228;
  struct System_Byte_array_array_array *v230;
  System_Byte_array_array *v231;
  System_Byte_array *v233;
  s64 v235;
  s64 v236;
  u64 v238;
  struct System_UInt32_array_array *v239;
  System_UInt32_array *v241;
  struct System_Byte_array_array_array *v243;
  System_Byte_array_array *v245;
  System_Byte_array *v247;
  struct System_Byte_array_array_array *v249;
  System_Byte_array_array *v251;
  System_Byte_array *v253;
  struct System_Byte_array_array *v255;
  System_Byte_array *v257;
  struct System_Byte_array_array_array *v259;
  System_Byte_array_array *v261;
  System_Byte_array *v263;
  struct System_Byte_array_array_array *v265;
  System_Byte_array_array *v267;
  System_Byte_array *v269;
  struct System_Byte_array_array *v271;
  System_Byte_array *v273;
  struct System_Byte_array *dds3PadActPow;
  struct System_Byte_array *dds3PadActPow_goal;
  struct System_UInt32_array *dds3PadActFrame;
  struct System_Byte_array *v282;
  struct System_Byte_array *v284;
  struct System_UInt32_array *v286;

  Init(0);
  dbg_2p = 0;
  dds3PrivatePadMapRepeat = NewSpecific(uint____, 2u);
  v5 = 0;
  do
  {
    v7 = v5;
    v9 = NewSpecific(uint__, 2u);
    v11 = v9;
    *&dds3PrivatePadMapRepeat[2 * v7 + 8] = v11;
    v14 = dds3PrivatePadMapRepeat;
    v16 = v14->m_Items[v7];
    v17 = NewSpecific(uint, 0x10u);
    v19 = v17;
    v16->m_Items[0] = v19;
    v24 = dds3PrivatePadMapRepeat;
    v26 = v24->m_Items[v7];
    v27 = NewSpecific(uint, 0x10u);
    v28 = v27;
    v5 = 1;
    v26->m_Items[1] = v28;
  }
  while (!v7);
  v31 = NewSpecific(uint__, 2u);
  v33 = v31;
  else
  {
    dds3PrivatePadAnalogRepeat = v33;
    if ((v34->_2.bitflags2 & 2) == 0)
      goto LABEL_46;
  }
LABEL_46:
  v36 = NewSpecific(uint, 2u);
  v38 = v36;
  dds3PrivatePadAnalogRepeat->m_Items[0] = v38;
  v42 = dds3PrivatePadAnalogRepeat;
  v43 = NewSpecific(uint, 2u);
  v44 = v43;
  v42->m_Items[1] = v44;
  v47 = NewSpecific(byte____, 2u);
  dds3PrivatePadMap = v47;
  v49 = 0;
  if ((v48->_2.bitflags2 & 2) != 0)
  {
LABEL_64:
    goto LABEL_66;
  }
  while (1)
  {
LABEL_66:
    v51 = NewSpecific(byte__, 2u);
    v53 = v51;
    *&dds3PrivatePadMap[2 * v49 + 8] = v53;
    v56 = dds3PrivatePadMap;
    v58 = v56->m_Items[v49];
    v59 = NewSpecific(byte, 0x10u);
    v61 = v59;
    v58->m_Items[0] = v61;
    v66 = dds3PrivatePadMap;
    v68 = v66->m_Items[v49];
    v69 = NewSpecific(byte, 0x10u);
    v70 = v69;
    v68->m_Items[1] = v70;
    if (v49)
      break;
    v49 = 1;
      goto LABEL_64;
  }
  v73 = NewSpecific(byte____, 2u);
  v75 = v73;
  v77 = 0;
  dds3PrivatePadAnalog = v75;
  if ((v76->_2.bitflags2 & 2) != 0)
  {
LABEL_99:
    goto LABEL_101;
  }
  while (1)
  {
LABEL_101:
    v79 = NewSpecific(byte__, 2u);
    v81 = v79;
    *&dds3PrivatePadAnalog[2 * v77 + 8] = v81;
    v84 = dds3PrivatePadAnalog;
    v86 = v84->m_Items[v77];
    v87 = NewSpecific(byte, 2u);
    v89 = v87;
    v86->m_Items[0] = v89;
    v94 = dds3PrivatePadAnalog;
    v96 = v94->m_Items[v77];
    v97 = NewSpecific(byte, 2u);
    v98 = v97;
    v96->m_Items[1] = v98;
    if (v77)
      break;
    v77 = 1;
      goto LABEL_99;
  }
  v101 = NewSpecific(byte__, 2u);
  v103 = v101;
  else
  {
    dds3PrivatePadAnalogMap = v103;
    if ((v104->_2.bitflags2 & 2) == 0)
      goto LABEL_135;
  }
LABEL_135:
  v107 = NewSpecific(byte, 2u);
  v109 = v107;
  dds3PrivatePadAnalogMap->m_Items[0] = v109;
  v113 = dds3PrivatePadAnalogMap;
  v114 = NewSpecific(byte, 2u);
  v115 = v114;
  v113->m_Items[1] = v115;
  v118 = NewSpecific(byte____, 2u);
  v120 = 0;
  dds3PadMap = v118;
  if ((v119->_2.bitflags2 & 2) != 0)
  {
LABEL_153:
    goto LABEL_155;
  }
  while (1)
  {
LABEL_155:
    v122 = NewSpecific(byte__, 2u);
    v124 = v122;
    *&dds3PadMap[2 * v120 + 8] = v124;
    v127 = dds3PadMap;
    v129 = v127->m_Items[v120];
    v130 = NewSpecific(byte, 0x10u);
    v132 = v130;
    v129->m_Items[0] = v132;
    v137 = dds3PadMap;
    v139 = v137->m_Items[v120];
    v140 = NewSpecific(byte, 0x10u);
    v141 = v140;
    v139->m_Items[1] = v141;
    if (v120)
      break;
    v120 = 1;
      goto LABEL_153;
  }
  v144 = NewSpecific(byte____, 2u);
  v146 = v144;
  v148 = 0;
  dds3PadAnalog = v146;
  if ((v147->_2.bitflags2 & 2) != 0)
  {
LABEL_188:
    goto LABEL_190;
  }
  while (1)
  {
LABEL_190:
    v150 = NewSpecific(byte__, 2u);
    v152 = v150;
    *&dds3PadAnalog[2 * v148 + 8] = v152;
    v155 = dds3PadAnalog;
    v157 = v155->m_Items[v148];
    v158 = NewSpecific(byte, 2u);
    v160 = v158;
    v157->m_Items[0] = v160;
    v165 = dds3PadAnalog;
    v167 = v165->m_Items[v148];
    v168 = NewSpecific(byte, 2u);
    v169 = v168;
    v167->m_Items[1] = v169;
    if (v148)
      break;
    v148 = 1;
      goto LABEL_188;
  }
  v172 = NewSpecific(byte__, 2u);
  v174 = v172;
  else
  {
    dds3PadAnalogMap = v174;
    if ((v175->_2.bitflags2 & 2) != 0)
      goto LABEL_220;
  }
  v178 = NewSpecific(byte, 2u);
  v180 = v178;
  dds3PadAnalogMap->m_Items[0] = v180;
  v184 = dds3PadAnalogMap;
  v185 = NewSpecific(byte, 2u);
  v186 = v185;
  v184->m_Items[1] = v186;
  v189 = NewSpecific(byte, 2u);
  dds3PadActPow = v189;
  dds3PadActPow_goal = NewSpecific(byte, 2u);
  v191 = NewSpecific(uint, 2u);
  v193 = 0;
  dds3PadActFrame = v191;
  do
  {
    v194 = 0;
    v195 = v193;
    do
    {
      else
      {
        v198 = dds3PrivatePadMapRepeat;
        if (!LODWORD(v198->max_length))
        {
LABEL_244:
        }
      }
      v200 = v198->m_Items[0];
      v202 = v200->m_Items[v195];
      v202->m_Items[v194] = 0;
      v204 = dds3PrivatePadMap;
      v205 = v204->m_Items[0];
      v207 = v205->m_Items[v195];
      v207->m_Items[v194] = 0;
      v209 = dds3PadMap;
      v210 = v209->m_Items[0];
      v212 = v210->m_Items[v195];
      v214 = v212 + v194++;
      *(v214 + 32) = 0;
    }
    while (v194 != 16);
    for (i = 0; i != 16; ++i)
    {
      v220 = dds3PrivatePadMapRepeat;
      v221 = v220->m_Items[1];
      v223 = v221->m_Items[v195];
      v223->m_Items[i] = 0;
      v225 = dds3PrivatePadMap;
      v226 = v225->m_Items[1];
      v228 = v226->m_Items[v195];
      v228->m_Items[i] = 0;
      v230 = dds3PadMap;
      v231 = v230->m_Items[1];
      v233 = v231->m_Items[v195];
      v235 = v233 + i;
      *(v235 + 32) = 0;
    }
    v236 = 0;
    do
    {
      v238 = v236;
      v239 = dds3PrivatePadAnalogRepeat;
      v241 = v239->m_Items[v195];
      v241->m_Items[v238] = 0;
      v243 = dds3PrivatePadAnalog;
      v245 = v243->m_Items[v195];
      v247 = v245->m_Items[v238];
      v247->m_Items[0] = 0;
      v249 = dds3PrivatePadAnalog;
      v251 = v249->m_Items[v195];
      v253 = v251->m_Items[v238];
      v253->m_Items[1] = 0;
      v255 = dds3PrivatePadAnalogMap;
      v257 = v255->m_Items[v195];
      v257->m_Items[v238] = 0;
      v259 = dds3PadAnalog;
      v261 = v259->m_Items[v195];
      v263 = v261->m_Items[v238];
      v263->m_Items[0] = 0;
      v265 = dds3PadAnalog;
      v267 = v265->m_Items[v195];
      v269 = v267->m_Items[v238];
      v269->m_Items[1] = 0;
      v271 = dds3PadAnalogMap;
      v273 = v271->m_Items[v195];
      v273->m_Items[v238] = 0;
      v236 = 1;
    }
    while (!v238);
    v193 = 1;
  }
  while (!v195);
  else
  {
    if (!LODWORD(dds3PadActPow->max_length))
      goto LABEL_331;
  }
  dds3PadActPow->m_Items[0] = 0;
  dds3PadActPow_goal->m_Items[0] = 0;
  dds3PadActFrame->m_Items[0] = 0;
  v282 = dds3PadActPow;
  v282->m_Items[1] = 0;
  v284 = dds3PadActPow_goal;
  v284->m_Items[1] = 0;
  v286 = dds3PadActFrame;
  v286->m_Items[1] = 0;
}

// 0x14e21e0
void dds3PadUpdate(void) {
  u64 *v2;
  s64 *v3;
  s64 *v4;
  s64 *v6;
  s64 *v7;
  u64 *v9;
  s64 *v10;
  s64 *v11;
  s64 *v13;
  s64 *v14;
  s64 v17;
  u64 v31;
  u64 v32;
  u64 CurrentKey;
  s64 v35;
  u64 v36;
  s64 v38;
  char v40;
  s64 v46;
  struct System_Single_array_array_array *AnalogStickLRval;
  System_Single_array_array *v49;
  System_Single_array *v50;
  struct System_Single_array_array_array *v51;
  System_Single_array_array *v53;
  System_Single_array *v55;
  f32 v57;
  f32 v58;
  f32 v59;
  f32 v60;
  s64 v62;
  s64 v63;
  struct System_Single_array_array_array *v66;
  System_Single_array_array *v68;
  System_Single_array *v69;
  struct System_Single_array_array_array *v70;
  System_Single_array_array *v72;
  System_Single_array *v74;
  f32 v76;
  f32 v77;
  f32 v78;
  f32 v79;
  s64 v81;
  s64 v82;
  struct System_Byte_array_array_array *dds3PrivatePadAnalog;
  System_Byte_array_array *v86;
  System_Byte_array *v87;
  s64 v88;
  u8 v89;
  struct System_Byte_array_array_array *v90;
  System_Byte_array_array *v91;
  System_Byte_array *v92;
  s64 v93;
  struct System_Byte_array_array_array *v108;
  System_Byte_array_array *v110;
  System_Byte_array *v111;
  s64 v112;
  u8 v113;
  struct System_Byte_array_array_array *v114;
  System_Byte_array_array *v116;
  System_Byte_array *v117;
  s64 v118;
  s64 v120;
  u64 v121;
  u64 v122;
  s64 v123;
  struct System_Byte_array_array_array *dds3PrivatePadMap;
  System_Byte_array_array *v129;
  System_Byte_array *v131;
  struct System_UInt32_array_array_array *dds3PrivatePadMapRepeat;
  System_UInt32_array_array *v135;
  System_UInt32_array *v137;
  struct System_UInt32_array_array_array *v139;
  System_UInt32_array_array *v141;
  System_UInt32_array *v143;
  struct System_Byte_array_array_array *v145;
  System_Byte_array_array *v147;
  System_Byte_array *v149;
  struct System_Byte_array_array_array *v151;
  System_Byte_array_array *v153;
  System_Byte_array *v155;
  struct System_Byte_array_array_array *v158;
  System_Byte_array_array *v160;
  System_Byte_array *v162;
  struct System_UInt32_array_array_array *v164;
  System_UInt32_array_array *v166;
  System_UInt32_array *v168;
  struct System_UInt32_array_array_array *v171;
  System_UInt32_array_array *v173;
  System_UInt32_array *v175;
  struct System_UInt32_array_array_array *v178;
  System_UInt32_array_array *v180;
  System_UInt32_array *v182;
  struct System_Byte_array_array_array *v185;
  System_Byte_array_array *v187;
  System_Byte_array *v189;
  u64 v191;
  u64 v192;
  u64 *v194;
  u64 *v195;
  s64 v196;
  f32 v200;
  struct System_Byte_array_array *v202;
  System_Byte_array *v204;
  struct System_UInt32_array_array *v206;
  System_UInt32_array *v208;
  struct System_Byte_array_array *dds3PrivatePadAnalogMap;
  System_Byte_array *v213;
  struct System_UInt32_array_array *dds3PrivatePadAnalogRepeat;
  System_UInt32_array *v217;
  struct System_UInt32_array_array *v219;
  System_UInt32_array *v221;
  struct System_Byte_array_array *v223;
  System_Byte_array *v225;
  struct System_Byte_array_array *v227;
  System_Byte_array *v229;
  struct System_UInt32_array_array *v232;
  System_UInt32_array *v234;
  struct System_UInt32_array_array *v237;
  System_UInt32_array *v239;
  struct System_Byte_array_array *v242;
  System_Byte_array *v244;
  System_Array_o *v252;
  u64 v253[2];
  UnityEngine_Vector4_o v254;

  *&v254.x = 0;
  *&v254.z = 0;
  Update(0);
  v252 = NewSpecific(ulong, 0x10u);
  InitializeArray_1543888(v252, Field__PrivateImplementationDetails__F0532B9CBC224777E09A5AC01DAD5C79142E1EEB);
  v2 = NewSpecific(byte__, 2u);
  v3 = NewSpecific(byte, 0x10u);
  v4 = v3;
  v2[4] = v4;
  v6 = NewSpecific(byte, 0x10u);
  v7 = v6;
  v2[5] = v7;
  v9 = NewSpecific(byte__, 2u);
  v10 = NewSpecific(byte, 2u);
  v11 = v10;
  v9[4] = v11;
  v13 = NewSpecific(byte, 2u);
  v14 = v13;
  v9[5] = v14;
  *&v254.x = 0;
  *&v254.z = 0;
  v253[0] = 0;
  v253[1] = 0;
  sub_854690(v253, 0.0, 0.0, -1.0, 0.0);
  v17 = 0;
  do
  {
    v31 = 0;
    v32 = v17;
    do
    {
      CurrentKey = GetCurrentKey(v32);
      v35 = v2[4];
      v36 = *(v35 + 24);
      if ((*(&v252[2].klass + v31) & CurrentKey) != 0)
      {
        *(v35 + v31 + 32) = 1;
        v38 = v2[5];
        v40 = 1;
      }
      else
      {
        *(v35 + v31 + 32) = 0;
        v38 = v2[5];
        v40 = 0;
      }
      v46 = v38 + v31++;
      *(v46 + 32) = v40;
    }
    while (v31 != 16);
    v49 = AnalogStickLRval->m_Items[v32];
    v50 = v49->m_Items[0];
    v51 = AnalogStickLRval;
    v53 = v51->m_Items[v32];
    v55 = v53->m_Items[0];
    if (((v50->m_Items[0] * 128.0) + 128.0) >= 256.0)
      v57 = 255.0;
    else
      v57 = (v50->m_Items[0] * 128.0) + 128.0;
    v58 = (v55->m_Items[1] * 128.0) + 128.0;
    if (v57 <= -256.0)
      v59 = -255.0;
    else
      v59 = v57;
    if (v58 >= 256.0)
      v58 = 255.0;
    if (v58 <= -256.0)
      v60 = -255.0;
    else
      v60 = v58;
    v62 = v9[4];
    *(v62 + 32) = v59;
    v63 = v9[4];
    *(v63 + 33) = v60;
    v66 = AnalogStickLRval;
    v68 = v66->m_Items[v32];
    v69 = v68->m_Items[1];
    v70 = AnalogStickLRval;
    v72 = v70->m_Items[v32];
    v74 = v72->m_Items[1];
    if (((v69->m_Items[0] * 128.0) + 128.0) >= 256.0)
      v76 = 255.0;
    else
      v76 = (v69->m_Items[0] * 128.0) + 128.0;
    v77 = (v74->m_Items[1] * 128.0) + 128.0;
    if (v76 <= -256.0)
      v78 = -255.0;
    else
      v78 = v76;
    if (v77 >= 256.0)
      v77 = 255.0;
    if (v77 <= -256.0)
      v79 = -255.0;
    else
      v79 = v77;
    v81 = v9[5];
    *(v81 + 32) = v78;
    v82 = v9[5];
    *(v82 + 33) = v79;
    v86 = dds3PrivatePadAnalog->m_Items[v32];
    v87 = v86->m_Items[0];
    v88 = v9[4];
    v89 = *(v88 + 32);
    v87->m_Items[0] = v89;
    v90 = dds3PrivatePadAnalog;
    v91 = v90->m_Items[v32];
    v92 = v91->m_Items[0];
    v93 = v9[4];
    v92->m_Items[1] = *(v93 + 33);
    v108 = dds3PrivatePadAnalog;
    v110 = v108->m_Items[v32];
    v111 = v110->m_Items[1];
    v112 = v9[5];
    v113 = *(v112 + 32);
    v111->m_Items[0] = v113;
    v114 = dds3PrivatePadAnalog;
    v116 = v114->m_Items[v32];
    v117 = v116->m_Items[1];
    v118 = v9[5];
    v120 = 0;
    v117->m_Items[1] = *(v118 + 33);
    do
    {
      v121 = v120;
      v122 = 0;
      v123 = &v2[v120 + 4];
      do
      {
        if (*(*v123 + v122 + 32))
        {
          v129 = dds3PrivatePadMap->m_Items[v121];
          v131 = v129->m_Items[v32];
          v131->m_Items[v122] = 1;
          v135 = dds3PrivatePadMapRepeat->m_Items[v121];
          v137 = v135->m_Items[v32];
          ++v137->m_Items[v122];
          v139 = dds3PrivatePadMapRepeat;
          v141 = v139->m_Items[v121];
          v143 = v141->m_Items[v32];
          if (v143->m_Items[v122] != 1)
          {
              goto LABEL_226;
LABEL_205:
            goto LABEL_226;
          }
          v145 = dds3PrivatePadMap;
          v147 = v145->m_Items[v121];
          v149 = v147->m_Items[v32];
          v149->m_Items[v122] |= 0x80u;
          v151 = dds3PrivatePadMap;
          v153 = v151->m_Items[v121];
          v155 = v153->m_Items[v32];
          v155->m_Items[v122] |= 2u;
            goto LABEL_205;
        }
        else
        {
          v158 = dds3PrivatePadMap;
          v160 = v158->m_Items[v121];
          v162 = v160->m_Items[v32];
          v162->m_Items[v122] = 0;
          v164 = dds3PrivatePadMapRepeat;
          v166 = v164->m_Items[v121];
          v168 = v166->m_Items[v32];
          v168->m_Items[v122] = 0;
            goto LABEL_205;
        }
LABEL_226:
        v171 = dds3PrivatePadMapRepeat;
        v173 = v171->m_Items[v121];
        v175 = v173->m_Items[v32];
        if (v175->m_Items[v122] >= 8)
        {
          v178 = dds3PrivatePadMapRepeat;
          v180 = v178->m_Items[v121];
          v182 = v180->m_Items[v32];
          if ((v182->m_Items[v122] & 1) == 0)
          {
            v185 = dds3PrivatePadMap;
            v187 = v185->m_Items[v121];
            v189 = v187->m_Items[v32];
            v189->m_Items[v122] |= 2u;
          }
        }
        ++v122;
      }
      while (v122 != 16);
      v120 = 1;
    }
    while (!v121);
    v191 = 0;
    do
    {
      v192 = v191;
      v194 = &v9[v191];
      v196 = v194[4];
      v195 = v194 + 4;
      sub_854930(&v254, 0);
      sub_854930(&v254, 1u);
      sub_854930(&v254, 2u);
      sub_854930(&v254, 3u);
      SDF_VU0__LOADVECTOR(v254);
      v200 = SDF_VU0__GETLENGTH();
      if (v200 >= 64.0)
      {
        v213 = dds3PrivatePadAnalogMap->m_Items[v32];
        v213->m_Items[v192] = 1;
        v217 = dds3PrivatePadAnalogRepeat->m_Items[v32];
        ++v217->m_Items[v192];
        v219 = dds3PrivatePadAnalogRepeat;
        v221 = v219->m_Items[v32];
        if (v221->m_Items[v192] != 1)
        {
            goto LABEL_309;
LABEL_277:
          goto LABEL_309;
        }
        v223 = dds3PrivatePadAnalogMap;
        v225 = v223->m_Items[v32];
        v225->m_Items[v192] |= 0x80u;
        v227 = dds3PrivatePadAnalogMap;
        v229 = v227->m_Items[v32];
        v229->m_Items[v192] |= 2u;
          goto LABEL_277;
      }
      else
      {
        v202 = dds3PrivatePadAnalogMap;
        v204 = v202->m_Items[v32];
        v204->m_Items[v192] = 0;
        v206 = dds3PrivatePadAnalogRepeat;
        v208 = v206->m_Items[v32];
        v208->m_Items[v192] = 0;
          goto LABEL_277;
      }
LABEL_309:
      v232 = dds3PrivatePadAnalogRepeat;
      v234 = v232->m_Items[v32];
      if (v234->m_Items[v192] >= 8)
      {
        v237 = dds3PrivatePadAnalogRepeat;
        v239 = v237->m_Items[v32];
        if ((v239->m_Items[v192] & 1) == 0)
        {
          v242 = dds3PrivatePadAnalogMap;
          v244 = v242->m_Items[v32];
          v244->m_Items[v192] |= 2u;
        }
      }
      v191 = 1;
    }
    while (!v192);
    v17 = 1;
  }
  while (!v32);
  dds3PadActUpdate();
  effPadVibeFadeUpdate();
}
