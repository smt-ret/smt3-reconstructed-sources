#include "types.h"

typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct scrCode_t scrCode_t;
typedef struct scrHeader_t scrHeader_t;
typedef struct scrLabelTable_t scrLabelTable_t;
typedef struct scrProcTable_t scrProcTable_t;
typedef struct scrProcessWork_s scrProcessWork_s;
typedef struct scrTypeTable_t scrTypeTable_t;

static u8 dds3ScriptPadTable[16];
static void *NowName_SCR_RUN;

bool DDS3_PADCHECK_TRIG(s32 id);
bool DDS3_PADCHECK_TRIG2(s32 id);
dds3ProcessID_t *IndexToProcess(s32 id);
s32 ProcessToIndex(dds3ProcessID_t *id);
void SDF_ASSERT(bool result);
f32 SDF_DEGtoRAD(f32 n);
void SDF_VU0__SETVECTOR_X(f32 v);
void SDF_VU0__SETVECTOR_Y(f32 v);
void SDF_VU0__SETVECTOR_Z(f32 v);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__VECTOR_W_SET_ONE(void);
void SDF_VU0__VECTOR_W_SET_ZERO(void);
void dds3Blur2Off(s32 frame);
void dds3Blur2On(s32 frame);
void dds3Blur2Swap(s32 frame);
void dds3DistBlurOff(s32 frame);
void dds3DistBlurOn(s32 frame);
void dds3DistBlurSwap(s32 frame);
s32 dds3ExistProcess(dds3ProcessID_t **id);
void dds3FadeIn(u32 r, u32 g, u32 b, u32 frame);
void dds3FadeOut(u32 r, u32 g, u32 b, u32 frame);
void dds3Filter2Off(s32 frame);
void dds3Filter2On(s32 frame);
void dds3Filter2Swap(s32 frame);
u32 dds3GetProcessRunTime(dds3ProcessID_t **id);
u32 dds3GetRandIntA(u32 aLimit, char *name);
s32 dds3KillProcess(dds3ProcessID_t **id, s32 shutdowntimer);
void dds3MFilterOff(s32 frame);
void dds3MFilterOn(s32 frame);
void dds3MFilterSwap(s32 frame);
void dds3MultiBlurOff(s32 frame);
void dds3MultiBlurOn(s32 frame);
void dds3MultiBlurSwap(s32 frame);
void dds3PadAct(u32 mode, u8 pow, u32 frame);
void dds3Printf(char *str, void **LegacyParamArray);
void dds3RipBlurOff(s32 frame);
void dds3RipBlurOn(s32 frame);
void dds3RipBlurSwap(s32 frame);
void dds3SetAmbientColor(u32 frame, sdfVector4_t col);
void dds3SetBlur(u32 frame, s32 alpha, s32 scale);
void dds3SetBlur2Area(s32 posx, s32 posy);
void dds3SetBlur2Para(f32 rotate, f32 scale, s32 blend);
void dds3SetBlur2RGBA(u32 rgba);
void dds3SetDistBlurArea(s32 area, s32 posx, s32 posy);
void dds3SetDistBlurPara(s32 number, s32 width, s32 intval, f32 speed, f32 rotate, f32 distor, s32 blend);
void dds3SetDistBlurRGBA(u32 rgba);
void dds3SetFilter2Para(s32 blend);
void dds3SetFilter2RGBA(u32 rgba);
void dds3SetFogColor(u32 frame, sdfVector4_t col);
void dds3SetFogPara(u32 frame, f32 max, f32 min, f32 near, f32 far);
void dds3SetLightColor(u32 frame, u32 no, sdfVector4_t col);
void dds3SetLightDir(u32 frame, u32 no, sdfVector4_t dir);
void dds3SetMFilterArea(s32 area, s32 posx, s32 posy);
void dds3SetMFilterPara(s32 blend);
void dds3SetMFilterRGBA(u32 rgba);
void dds3SetMultiBlurArea(s32 area, s32 posx, s32 posy);
void dds3SetMultiBlurPara(f32 rotate, f32 scale, s32 blend);
void dds3SetMultiBlurRGBA(u32 rgba);
void dds3SetQuake(s32 frame, u32 range);
void dds3SetRipBlurArea(s32 area, s32 posx, s32 posy);
void dds3SetRipBlurPara(s32 number, f32 speed, f32 intval, f32 rotate, f32 distor, f32 distor_s, s32 blend);
void dds3SetRipBlurRGBA(u32 rgba);
void dds3SetScreenFovy(f32 fovy);
void dds3SetSoftenBias(u32 frame, f32 soften, f32 bias);
void dds3StopQuake(void);
bool evtBitCheck(s32 no);
void evtBitOff(s32 no);
void evtBitOn(s32 no);
s32 scrGetCommandTimer(void);
f32 scrGetFloatPara(s32 n);
s32 scrGetIntPara(s32 n);
s32 scrGetLabelCodeAddress(s32 labelindex);
scrProcessWork_s *scrGetScriptHandle(void);
char *scrGetStrPara(s32 n);
void scrSetCodePointer(s32 cp);
void scrSetIntReturnValue(s32 i);
dds3ProcessID_t *scrStartScript1a(s32 priority, scrHeader_t *header, scrTypeTable_t **typetable, scrProcTable_t **proctable, scrLabelTable_t **labeltable, scrCode_t **code, u8 **mesdata, u8 **stringdata, s32 startproc);
f32 sdfFabs(f32 c);

// 0x1573100
char *GetNowName_SCR_RUN(void) {
  return (NowName_SCR_RUN->klass->vtable._3_ToString.methodPtr)(
           NowName_SCR_RUN,
           NowName_SCR_RUN->klass->vtable._3_ToString.method);
}

// 0x1571b30
s32 scrCommand_BIT_CHK(void) {
  s32 v4;
  s32 IntPara;

  if (scrGetIntPara(0) == 2802)
  {
    v4 = cfgGetBit(9u) == 0;
    {
    }
  }
  else
  {
    IntPara = scrGetIntPara(0);
    v4 = evtBitCheck(IntPara);
  }
  scrSetIntReturnValue(v4);
  return 1;
}

// 0x1571c40
s32 scrCommand_BIT_CHK2(void) {
  s32 v4;
  s32 IntPara;

  if (scrGetIntPara(0) == 2802)
  {
    v4 = cfgGetBit(9u) < 2;
    {
    }
  }
  else
  {
    IntPara = scrGetIntPara(0);
    v4 = evtBitCheck(IntPara);
  }
  scrSetIntReturnValue(v4);
  return 1;
}

// 0x1571e00
s32 scrCommand_BIT_OFF(void) {
  u32 IntPara;

  IntPara = scrGetIntPara(0);
  SDF_ASSERT(IntPara < 0x1000);
  evtBitOff(IntPara);
  return 1;
}

// 0x1571d50
s32 scrCommand_BIT_ON(void) {
  u32 IntPara;

  IntPara = scrGetIntPara(0);
  SDF_ASSERT(IntPara < 0x1000);
  evtBitOn(IntPara);
  return 1;
}

// 0x1573f20
s32 scrCommand_BLUR(void) {
  s32 IntPara;
  s32 v3;
  s32 v5;

  IntPara = scrGetIntPara(0);
  v3 = scrGetIntPara(1);
  v5 = scrGetIntPara(2);
  dds3SetBlur(IntPara, v3, v5);
  return 1;
}

// 0x1575110
s32 scrCommand_BLUR2_AREA(void) {
  s32 IntPara;
  s32 v4;

  IntPara = scrGetIntPara(0);
  v4 = scrGetIntPara(1);
  dds3SetBlur2Area(IntPara, v4);
  return 1;
}

// 0x1575300
s32 scrCommand_BLUR2_OFF(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  dds3Blur2Off(IntPara);
  return 1;
}

// 0x1575260
s32 scrCommand_BLUR2_ON(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  dds3Blur2On(IntPara);
  return 1;
}

// 0x1574f40
s32 scrCommand_BLUR2_PARA(void) {
  u32 IntPara;
  s32 v4;
  f32 FloatPara;
  f32 v7;

  IntPara = scrGetIntPara(2);
  if (IntPara < 3)
    v4 = IntPara + 1;
  else
    v4 = 1;
  FloatPara = scrGetFloatPara(0);
  v7 = scrGetFloatPara(1);
  dds3SetBlur2Para(FloatPara, v7, v4);
  return 1;
}

// 0x1575030
s32 scrCommand_BLUR2_RGBA(void) {
  u8 IntPara;
  u8 v3;
  u8 v4;
  u8 v6;

  IntPara = scrGetIntPara(0);
  v3 = scrGetIntPara(1);
  v4 = scrGetIntPara(2);
  v6 = scrGetIntPara(3);
  dds3SetBlur2RGBA(IntPara | (v3 << 8) | (v4 << 16) & 0xFFFFFF | (v6 << 24), 0);
  return 1;
}

// 0x15751c0
s32 scrCommand_BLUR2_SWAP(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  dds3Blur2Swap(IntPara);
  return 1;
}

// 0x1575b50
s32 scrCommand_BLUR_ALLOFF(void) {
  dds3SetBlur(0, 0, 0);
  dds3Blur2Off(0);
  dds3MultiBlurOff(0);
  dds3DistBlurOff(0);
  dds3RipBlurOff(0);
  return 1;
}

// 0x15747a0
s32 scrCommand_DIST_BLUR_AREA(void) {
  s32 IntPara;
  s32 v3;
  s32 v5;

  IntPara = scrGetIntPara(0);
  v3 = scrGetIntPara(1);
  v5 = scrGetIntPara(2);
  dds3SetDistBlurArea(IntPara, v3, v5);
  return 1;
}

// 0x15749b0
s32 scrCommand_DIST_BLUR_OFF(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  dds3DistBlurOff(IntPara);
  return 1;
}

// 0x1574910
s32 scrCommand_DIST_BLUR_ON(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  dds3DistBlurOn(IntPara);
  return 1;
}

// 0x1574560
s32 scrCommand_DIST_BLUR_PARA(void) {
  s32 IntPara;
  s32 v4;
  s32 v5;
  s32 v6;
  s32 v7;
  s32 v8;
  f32 FloatPara;
  f32 v10;
  f32 v12;

  IntPara = scrGetIntPara(6);
  if (IntPara == 1)
    v4 = 2;
  else
    v4 = 1;
  if (IntPara == 2)
    v5 = 3;
  else
    v5 = v4;
  v6 = scrGetIntPara(0);
  v7 = scrGetIntPara(1);
  v8 = scrGetIntPara(2);
  FloatPara = scrGetFloatPara(3);
  v10 = scrGetFloatPara(4);
  v12 = scrGetFloatPara(5);
  dds3SetDistBlurPara(v6, v7, v8, FloatPara, v10, v12, v5);
  return 1;
}

// 0x15746c0
s32 scrCommand_DIST_BLUR_RGBA(void) {
  u8 IntPara;
  u8 v3;
  u8 v4;
  u8 v6;

  IntPara = scrGetIntPara(0);
  v3 = scrGetIntPara(1);
  v4 = scrGetIntPara(2);
  v6 = scrGetIntPara(3);
  dds3SetDistBlurRGBA(IntPara | (v3 << 8) | (v4 << 16) & 0xFFFFFF | (v6 << 24), 0);
  return 1;
}

// 0x1574870
s32 scrCommand_DIST_BLUR_SWAP(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  dds3DistBlurSwap(IntPara);
  return 1;
}

// 0x1572390
s32 scrCommand_FADE_IN(void) {
  s32 IntPara;
  s32 v7;
  u32 v8;
  u32 v9;
  u32 v10;

  else if (scrGetCommandTimer())
  {
    return 1;
  }
  IntPara = scrGetIntPara(0);
  if (IntPara == 1)
  {
    v7 = scrGetIntPara(1);
    v8 = 255;
    v9 = 255;
    v10 = 255;
  }
  if (!IntPara)
  {
    v7 = scrGetIntPara(1);
    v8 = 0;
    v9 = 0;
    v10 = 0;
    dds3FadeIn(v8, v9, v10, v7);
    return 0;
  }
  SDF_ASSERT(0);
  return 1;
}

// 0x1572540
s32 scrCommand_FADE_OUT(void) {
  s32 IntPara;
  s32 v7;
  u32 v8;
  u32 v9;
  u32 v10;

  else if (scrGetCommandTimer())
  {
    return 1;
  }
  IntPara = scrGetIntPara(0);
  if (IntPara == 1)
  {
    v7 = scrGetIntPara(1);
    v8 = 255;
    v9 = 255;
    v10 = 255;
  }
  if (!IntPara)
  {
    v7 = scrGetIntPara(1);
    v8 = 0;
    v9 = 0;
    v10 = 0;
    dds3FadeOut(v8, v9, v10, v7);
    return 0;
  }
  SDF_ASSERT(0);
  return 1;
}

// 0x1575670
s32 scrCommand_FILTER2_OFF(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  dds3Filter2Off(IntPara);
  return 1;
}

// 0x15755d0
s32 scrCommand_FILTER2_ON(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  dds3Filter2On(IntPara);
  return 1;
}

// 0x15753a0
s32 scrCommand_FILTER2_PARA(void) {
  u32 IntPara;
  s32 v4;

  IntPara = scrGetIntPara(0);
  if (IntPara < 4)
    v4 = IntPara + 1;
  else
    v4 = 1;
  dds3SetFilter2Para(v4);
  return 1;
}

// 0x1575450
s32 scrCommand_FILTER2_RGBA(void) {
  u8 IntPara;
  u8 v3;
  u8 v4;
  u8 v6;

  IntPara = scrGetIntPara(0);
  v3 = scrGetIntPara(1);
  v4 = scrGetIntPara(2);
  v6 = scrGetIntPara(3);
  dds3SetFilter2RGBA(IntPara | (v3 << 8) | (v4 << 16) & 0xFFFFFF | (v6 << 24), 0);
  return 1;
}

// 0x1575530
s32 scrCommand_FILTER2_SWAP(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  dds3Filter2Swap(IntPara);
  return 1;
}

// 0x1575c00
s32 scrCommand_FILTER_ALLOFF(void) {
  dds3Filter2Off(0);
  dds3MFilterOff(0);
  return 1;
}

// 0x1571a90
s32 scrCommand_KEY(void) {
  s32 result;

  result = scrGetCommandTimer();
  if (result)
  {
    return DDS3_PADCHECK_TRIG(1);
  }
  return result;
}

// 0x15758a0
s32 scrCommand_MFILTER_AREA(void) {
  s32 IntPara;
  s32 v3;
  s32 v5;

  IntPara = scrGetIntPara(0);
  v3 = scrGetIntPara(1);
  v5 = scrGetIntPara(2);
  dds3SetMFilterArea(IntPara, v3, v5);
  return 1;
}

// 0x1575ab0
s32 scrCommand_MFILTER_OFF(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  dds3MFilterOff(IntPara);
  return 1;
}

// 0x1575a10
s32 scrCommand_MFILTER_ON(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  dds3MFilterOn(IntPara);
  return 1;
}

// 0x1575710
s32 scrCommand_MFILTER_PARA(void) {
  u32 IntPara;
  s32 v4;

  IntPara = scrGetIntPara(0);
  if (IntPara < 4)
    v4 = IntPara + 1;
  else
    v4 = 1;
  dds3SetMFilterPara(v4);
  return 1;
}

// 0x15757c0
s32 scrCommand_MFILTER_RGBA(void) {
  u8 IntPara;
  u8 v3;
  u8 v4;
  u8 v6;

  IntPara = scrGetIntPara(0);
  v3 = scrGetIntPara(1);
  v4 = scrGetIntPara(2);
  v6 = scrGetIntPara(3);
  dds3SetMFilterRGBA(IntPara | (v3 << 8) | (v4 << 16) & 0xFFFFFF | (v6 << 24), 0);
  return 1;
}

// 0x1575970
s32 scrCommand_MFILTER_SWAP(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  dds3MFilterSwap(IntPara);
  return 1;
}

// 0x15741d0
s32 scrCommand_MUL_BLUR_AREA(void) {
  s32 IntPara;
  s32 v3;
  s32 v5;

  IntPara = scrGetIntPara(0);
  v3 = scrGetIntPara(1);
  v5 = scrGetIntPara(2);
  dds3SetMultiBlurArea(IntPara, v3, v5);
  return 1;
}

// 0x15743e0
s32 scrCommand_MUL_BLUR_OFF(void) {
  System_String_o *v3;
  s32 v5;
  s32 IntPara;

  v3 = (NowName_SCR_RUN->klass->vtable._3_ToString.methodPtr)(
         NowName_SCR_RUN,
         NowName_SCR_RUN->klass->vtable._3_ToString.method);
  if (IsNullOrEmpty(v3) || !Equals_5234480(v3, StringLiteral_21957))
  {
    IntPara = scrGetIntPara(0);
    v5 = IntPara;
  }
  else
  {
    v5 = 8;
  }
  dds3MultiBlurOff(v5);
  return 1;
}

// 0x1574340
s32 scrCommand_MUL_BLUR_ON(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  dds3MultiBlurOn(IntPara);
  return 1;
}

// 0x1573ff0
s32 scrCommand_MUL_BLUR_PARA(void) {
  s32 IntPara;
  s32 v4;
  s32 v5;
  f32 FloatPara;
  f32 v8;

  IntPara = scrGetIntPara(2);
  if (IntPara == 1)
    v4 = 2;
  else
    v4 = 1;
  if (IntPara == 2)
    v5 = 3;
  else
    v5 = v4;
  FloatPara = scrGetFloatPara(0);
  v8 = scrGetFloatPara(1);
  dds3SetMultiBlurPara(FloatPara, v8, v5);
  return 1;
}

// 0x15740f0
s32 scrCommand_MUL_BLUR_RGBA(void) {
  u8 IntPara;
  u8 v3;
  u8 v4;
  u8 v6;

  IntPara = scrGetIntPara(0);
  v3 = scrGetIntPara(1);
  v4 = scrGetIntPara(2);
  v6 = scrGetIntPara(3);
  dds3SetMultiBlurRGBA(IntPara | (v3 << 8) | (v4 << 16) & 0xFFFFFF | (v6 << 24), 0);
  return 1;
}

// 0x15742a0
s32 scrCommand_MUL_BLUR_SWAP(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  dds3MultiBlurSwap(IntPara);
  return 1;
}

// 0x1572af0
s32 scrCommand_PAD_ACT(void) {
  s32 IntPara;
  u8 v3;
  s32 v4;
  s32 v6;
  u32 v7;

  IntPara = scrGetIntPara(0);
  v3 = scrGetIntPara(1);
  v4 = scrGetIntPara(2);
  if (v4 >= 0)
    v6 = v4;
  else
    v6 = v4 + 1;
  v7 = v6 >> 1;
  dds3PadAct(IntPara, v3, v7);
  return 1;
}

// 0x1572930
s32 scrCommand_PAD_PRESS(void) {
  s32 IntPara;
  bool v5;
  struct System_Byte_array_array_array *dds3PadMap;
  System_Byte_array_array *v8;
  System_Byte_array *v9;
  s32 v11;

  IntPara = scrGetIntPara(0);
  if (IntPara < 0)
  {
    v5 = 0;
  }
  else
  {
    v5 = IntPara < SLODWORD(dds3ScriptPadTable->max_length);
  }
  SDF_ASSERT(v5);
  if (!LODWORD(dds3PadMap->max_length))
  v8 = dds3PadMap->m_Items[0];
  v9 = v8->m_Items[0];
  v11 = v9->m_Items[IntPara] != 0;
  scrSetIntReturnValue(v11);
  return 1;
}

// 0x15727f0
s32 scrCommand_PAD_TRIG(void) {
  s32 IntPara;
  bool v5;
  s32 v8;

  IntPara = scrGetIntPara(0);
  if (IntPara < 0)
  {
    v5 = 0;
  }
  else
  {
    v5 = IntPara < SLODWORD(dds3ScriptPadTable->max_length);
  }
  SDF_ASSERT(v5);
  v8 = DDS3_PADCHECK_TRIG2(IntPara);
  scrSetIntReturnValue(v8);
  return 1;
}

// 0x15720a0
s32 scrCommand_PUT(void) {
    scrGetIntPara(0);
    dds3Printf(0, 0);
    return 0;
}

// 0x1572210
s32 scrCommand_PUTS(void) {
    scrGetStrPara(0);
    dds3Printf(0, 0);
    return 0;
}

// 0x15736f0
s32 scrCommand_QUAKE_OFF(void) {
  dds3StopQuake();
  return 1;
}

// 0x1573640
s32 scrCommand_QUAKE_ON(void) {
  s32 IntPara;
  s32 v4;

  IntPara = scrGetIntPara(0);
  v4 = scrGetIntPara(1);
  dds3SetQuake(IntPara, v4);
  return 1;
}

// 0x1574c90
s32 scrCommand_RIP_BLUR_AREA(void) {
  s32 IntPara;
  s32 v3;
  s32 v5;

  IntPara = scrGetIntPara(0);
  v3 = scrGetIntPara(1);
  v5 = scrGetIntPara(2);
  dds3SetRipBlurArea(IntPara, v3, v5);
  return 1;
}

// 0x1574ea0
s32 scrCommand_RIP_BLUR_OFF(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  dds3RipBlurOff(IntPara);
  return 1;
}

// 0x1574e00
s32 scrCommand_RIP_BLUR_ON(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  dds3RipBlurOn(IntPara);
  return 1;
}

// 0x1574a50
s32 scrCommand_RIP_BLUR_PARA(void) {
  s32 IntPara;
  s32 v4;
  s32 v5;
  s32 v6;
  f32 FloatPara;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v12;

  IntPara = scrGetIntPara(6);
  if (IntPara == 1)
    v4 = 2;
  else
    v4 = 1;
  if (IntPara == 2)
    v5 = 3;
  else
    v5 = v4;
  v6 = scrGetIntPara(0);
  FloatPara = scrGetFloatPara(1);
  v8 = scrGetFloatPara(2);
  v9 = scrGetFloatPara(3);
  v10 = scrGetFloatPara(4);
  v12 = scrGetFloatPara(5);
  dds3SetRipBlurPara(v6, FloatPara, v8, v9, v10, v12, v5);
  return 1;
}

// 0x1574bb0
s32 scrCommand_RIP_BLUR_RGBA(void) {
  u8 IntPara;
  u8 v3;
  u8 v4;
  u8 v6;

  IntPara = scrGetIntPara(0);
  v3 = scrGetIntPara(1);
  v4 = scrGetIntPara(2);
  v6 = scrGetIntPara(3);
  dds3SetRipBlurRGBA(IntPara | (v3 << 8) | (v4 << 16) & 0xFFFFFF | (v6 << 24), 0);
  return 1;
}

// 0x1574d60
s32 scrCommand_RIP_BLUR_SWAP(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  dds3RipBlurSwap(IntPara);
  return 1;
}

// 0x1571eb0
s32 scrCommand_RND(void) {
  s32 IntPara;
  u32 RandIntA;

  IntPara = scrGetIntPara(0);
  RandIntA = dds3GetRandIntA(IntPara, StringLiteral_416);
  scrSetIntReturnValue(RandIntA + 1);
  return 1;
}

// 0x1573ae0
s32 scrCommand_SCENE_AMBIENT(void) {
  f32 FloatPara;
  f32 v3;
  f32 v4;
  s32 IntPara;
  s64 v7;
  u32 v8;
  f32 w;
  f32 z;
  UnityEngine_Vector4_o v12;
  UnityEngine_Vector4_o v13;

  *&v12.x = 0;
  *&v12.z = 0;
  FloatPara = scrGetFloatPara(1);
  SDF_VU0__SETVECTOR_X(FloatPara);
  v3 = scrGetFloatPara(2);
  SDF_VU0__SETVECTOR_Y(v3);
  v4 = scrGetFloatPara(3);
  SDF_VU0__SETVECTOR_Z(v4);
  SDF_VU0__VECTOR_W_SET_ONE();
  SDF_VU0__STOREVECTOR(&v12);
  IntPara = scrGetIntPara(0);
  v7 = *&v12.x;
  v8 = IntPara;
  z = v12.z;
  w = v12.w;
  *&v13.x = v7;
  v13.z = z;
  v13.w = w;
  dds3SetAmbientColor(v8, v13);
  return 1;
}

// 0x1573d40
s32 scrCommand_SCENE_FOG_PARA(void) {
  s32 IntPara;
  u32 v3;
  u32 v4;
  u32 v5;
  u32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;

  IntPara = scrGetIntPara(0);
  v3 = scrGetIntPara(1);
  v4 = scrGetIntPara(3);
  v5 = scrGetIntPara(2);
  v7 = scrGetIntPara(4);
  v8 = v3;
  v9 = v4;
  v10 = v5;
  v11 = v7;
  dds3SetFogPara(IntPara, v8, v9, v10, v11);
  return 1;
}

// 0x1573c00
s32 scrCommand_SCENE_FOG_RGB(void) {
    scrGetFloatPara(0);
    scrGetIntPara(0);
    dds3SetFogColor(0, (sdfVector4_t){0});
    return 0;
}

// 0x1573890
s32 scrCommand_SCENE_LIGHT_DIR(void) {
    scrGetFloatPara(0);
    sdfFabs(0);
    dds3Printf(0, 0);
    scrGetIntPara(0);
    dds3SetLightDir(0, 0, (sdfVector4_t){0});
    return 0;
}

// 0x1573760
s32 scrCommand_SCENE_LIGHT_RGB(void) {
  f32 FloatPara;
  f32 v3;
  f32 v4;
  s32 IntPara;
  s64 v7;
  u32 v8;
  f32 w;
  f32 z;
  UnityEngine_Vector4_o v12;
  UnityEngine_Vector4_o v13;

  *&v12.x = 0;
  *&v12.z = 0;
  FloatPara = scrGetFloatPara(1);
  SDF_VU0__SETVECTOR_X(FloatPara);
  v3 = scrGetFloatPara(2);
  SDF_VU0__SETVECTOR_Y(v3);
  v4 = scrGetFloatPara(3);
  SDF_VU0__SETVECTOR_Z(v4);
  SDF_VU0__VECTOR_W_SET_ZERO();
  SDF_VU0__STOREVECTOR(&v12);
  IntPara = scrGetIntPara(0);
  v7 = *&v12.x;
  v8 = IntPara;
  z = v12.z;
  w = v12.w;
  *&v13.x = v7;
  v13.z = z;
  v13.w = w;
  dds3SetLightColor(v8, 0, v13);
  return 1;
}

// 0x1573170
s32 scrCommand_SCR_KILL(void) {
  u64 *v1;
  s32 IntPara;
  dds3ProcessID_t_o *id;

  v1 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v1);
  id = v1;
  IntPara = scrGetIntPara(0);
  id = IndexToProcess(IntPara);
  if (dds3ExistProcess(&id))
  {
    dds3KillProcess(&id, 1);
  }
  return 1;
}

// 0x1572d60
s32 scrCommand_SCR_RUN(void) {
  u64 *v1;
  u64 *v2;
  scrProcessWork_s_o *ScriptHandle;
  s32 IntPara;
  s32 v7;
  struct scrTypeTable_t_array *TypeTable;
  s64 v12;
  struct scrProcTable_t_array *ProcTable;
  u64 v14;
  struct System_Byte_array *Name;
  struct scrProcTable_t_array *v19;
  struct System_Byte_array *v21;
  System_String_o *v24;
  Il2CppObject *v26;
  u32 priority;
  s32 v29;
  s32 v31;
  struct System_Char_array *MagicCode;
  s64 v33;
  s64 v34;
  scrTypeTable_t_array *v35;
  scrProcTable_t_array *v36;
  scrLabelTable_t_array *LabelTable;
  scrCode_t_array *Code;
  System_Byte_array *StringData;
  System_Byte_array *MessageData;
  dds3ProcessID_t_o *started;
  s32 v42;
  scrHeader_t_o v44;
  scrHeader_t_o v45;

  v1 = Allocate(scrProcessWork_s);
  scrProcessWork_s___ctor(v1);
  v2 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v2);
  ScriptHandle = scrGetScriptHandle();
  IntPara = scrGetIntPara(0);
  if (ScriptHandle)
  {
    if (ScriptHandle->ProcessID)
    {
      v7 = IntPara;
      if ((IntPara & 0x80000000) == 0)
      {
        TypeTable = ScriptHandle->TypeTable;
        if (IntPara < TypeTable->m_Items[0].ItemCount)
        {
          Clear(NowName_SCR_RUN, 0);
          v12 = 32;
          do
          {
            ProcTable = ScriptHandle->ProcTable;
            v14 = v12 - 32;
            Name = ProcTable->m_Items[v7].Name;
            if (!*(&Name->obj.klass + v12))
              break;
            v19 = ScriptHandle->ProcTable;
            v21 = v19->m_Items[v7].Name;
            Append_5387312(
              NowName_SCR_RUN,
              *(&v21->obj.klass + v12++),
              0);
          }
          while (v14 < 0xF);
          v24 = (NowName_SCR_RUN->klass->vtable._3_ToString.methodPtr)(
                  NowName_SCR_RUN,
                  NowName_SCR_RUN->klass->vtable._3_ToString.method);
          v26 = Concat_5221536(StringLiteral_21955, v24, StringLiteral_441);
          Log(v26, 0);
          priority = ScriptHandle->ProcessID->priority;
          v29 = scrGetIntPara(1);
          *&v45.FileType = *&ScriptHandle->Header.FileType;
          v31 = v29;
          MagicCode = ScriptHandle->Header.MagicCode;
          v33 = *&ScriptHandle->Header.ExpandSize;
          v34 = *&ScriptHandle->Header.Resrve3;
          *&v45.LocalIntCount = *&ScriptHandle->Header.LocalIntCount;
          *&v45.Resrve3 = v34;
          v45.MagicCode = MagicCode;
          *&v45.ExpandSize = v33;
          v35 = ScriptHandle->TypeTable;
          v36 = ScriptHandle->ProcTable;
          LabelTable = ScriptHandle->LabelTable;
          Code = ScriptHandle->Code;
          MessageData = ScriptHandle->MessageData;
          StringData = ScriptHandle->StringData;
          v44 = v45;
          started = scrStartScript1a(priority - v31, &v44, v35, v36, LabelTable, Code, MessageData, StringData, v7);
          v42 = ProcessToIndex(started);
          scrSetIntReturnValue(v42);
        }
      }
    }
    else
    {
      Write(StringLiteral_21954, 0);
    }
  }
  return 1;
}

// 0x1573380
s32 scrCommand_SCR_STAT(void) {
  u64 *v1;
  s32 IntPara;
  s32 v7;
  dds3ProcessID_t_o *id;

  v1 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v1);
  id = v1;
  IntPara = scrGetIntPara(0);
  id = IndexToProcess(IntPara);
  if (dds3ExistProcess(&id) == 1)
  {
    v7 = 1;
  }
  else
  {
    v7 = 0;
  }
  scrSetIntReturnValue(v7);
  return 1;
}

// 0x15734c0
s32 scrCommand_SCR_TIME(void) {
    scrGetIntPara(0);
    IndexToProcess(0);
    dds3ExistProcess(0);
    dds3GetProcessRunTime(0);
    scrSetIntReturnValue(0);
    return 0;
}

// 0x1573290
s32 scrCommand_SCR_WAIT(void) {
  u64 *v1;
  s32 IntPara;
  dds3ProcessID_t_o *id;

  v1 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v1);
  id = v1;
  IntPara = scrGetIntPara(0);
  id = IndexToProcess(IntPara);
  return dds3ExistProcess(&id) == 0;
}

// 0x15726f0
s32 scrCommand_SEL_JMP(void) {
  s32 IntPara;
  s32 v4;
  s32 v6;
  s32 v8;
  s32 LabelCodeAddress;

  IntPara = scrGetIntPara(0);
  if ((IntPara & 0x80000000) == 0)
  {
    v4 = IntPara;
    SDF_ASSERT(v4 < 7);
    v6 = scrGetIntPara(v4 + 1);
    if ((v6 & 0x80000000) == 0)
    {
      v8 = v6;
      LabelCodeAddress = scrGetLabelCodeAddress(v8);
      scrSetCodePointer(LabelCodeAddress);
    }
  }
  return 1;
}

// 0x1572bd0
s32 scrCommand_SET_FOVY(void) {
    scrGetFloatPara(0);
    SDF_DEGtoRAD(0);
    dds3Printf(0, 0);
    dds3SetScreenFovy(0);
    return 0;
}

// 0x1573e50
s32 scrCommand_SOFTEN_BIAS(void) {
  s32 IntPara;
  f32 FloatPara;
  f32 v5;

  IntPara = scrGetIntPara(0);
  FloatPara = scrGetFloatPara(1);
  v5 = scrGetFloatPara(2);
  dds3SetSoftenBias(IntPara, FloatPara, v5);
  return 1;
}

// 0x1571f70
s32 scrCommand_SYNC(void) {
  return scrGetCommandTimer() != 0;
}

// 0x1575c80
s32 scrCommand_UNLOAD(void) {
  UnloadUnusedAssets();
  return 1;
}

// 0x1571fe0
s32 scrCommand_WAIT(void) {
  s32 CommandTimer;

  if (scrGetIntPara(0) < 1)
    return 1;
  CommandTimer = scrGetCommandTimer();
  return CommandTimer >= scrGetIntPara(0);
}
