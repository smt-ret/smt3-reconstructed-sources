#include "types.h"

typedef struct sdfDrawTag_t sdfDrawTag_t;

static u8 dds3DebugDispColorValue_tagAttr[3];
static char *dds3DebugDispColorValue_tagStr[3];

f32 dds3DebugFloatEditEx(f32 aValue, f32 aMin, f32 aMax, f32 aSmall, f32 aLarge, u8 **aPadMap);

// 0x152ffb0
s32 dds3DebugColorEdit(u32 aValue, s32 aColumn) {
    return 0;
  return 0;
}

// 0x152ffa0
s32 dds3DebugColorEditEx(u32 aValue, s32 aColumn, u8 **aPadMap) {
  return 0;
}

// 0x15300a0
void dds3DebugDispColorValue(sdfDrawTag_t *aDrawTag, s32 aX, s32 aY, s32 aCursor, f32 **aColor) {
  ;
}

// 0x15300b0
void dds3DebugDispIntColorValue(sdfDrawTag_t *aDrawTag, s32 aX, s32 aY, s32 aCursor, u32 aColor, s32 aFloatDisp) {
  ;
}

// 0x152fe70
void dds3DebugFloatEdit(f32 aValue, f32 aMin, f32 aMax, f32 aSmall, f32 aLarge) {
  struct System_Byte_array_array_array *dds3PadMap;
  System_Byte_array_array *v15;
  System_Byte_array *v17;

  v15 = dds3PadMap->m_Items[1];
  v17 = v15->m_Items[0];
  dds3DebugFloatEditEx(aValue, aMin, aMax, aSmall, aLarge, v17);
}

// 0x152fca0
f32 dds3DebugFloatEditEx(f32 aValue, f32 aMin, f32 aMax, f32 aSmall, f32 aLarge, u8 **aPadMap) {
  f32 v7;
  s32 v9;
  s32 v12;
  s32 v15;
  s32 v18;
  f32 v20;
  f32 result;
  f32 v22;
  f32 v23;

  v7 = aValue;
  v9 = aPadMap->m_Items[5];
  if ((v9 & 0x80000000) == 0)
  {
    if ((v9 & 2) != 0)
    {
      v22 = aValue + aLarge;
    }
    else
    {
      v12 = aPadMap->m_Items[4];
      if (v12 < 0)
      {
        v23 = aValue - aLarge;
      }
      if ((v12 & 2) != 0)
      {
        v20 = aValue - aLarge;
        if (v20 >= aMin)
          return v20;
        else
          return aMin;
      }
      v15 = aPadMap->m_Items[7];
      if (v15 < 0)
      {
        if ((aValue + aSmall) <= aMax)
          return aValue + aSmall;
        else
          return aMin;
      }
      if ((v15 & 2) == 0)
      {
        v18 = aPadMap->m_Items[6];
        if ((v18 & 0x80000000) == 0)
        {
          if ((v18 & 2) == 0)
            return v7;
          v20 = aValue - aSmall;
        }
        v23 = aValue - aSmall;
        if (v23 >= aMin)
          return v23;
        else
          return aMax;
      }
      v22 = aValue + aSmall;
    }
    if (v22 <= aMax)
      return v22;
    else
      return aMax;
  }
  result = aValue + aLarge;
  if ((v7 + aLarge) > aMax)
    return aMin;
  return result;
}

// 0x152ff90
void dds3DebugIntEdit(void *aValue, s32 aValueSize, s32 aMin, s32 aMax, s32 aSmall, s32 aLarge) {
  ;
}

// 0x152ff80
void dds3DebugIntEditEx(void *aValue, s32 aValueSize, s32 aMin, s32 aMax, s32 aSmall, s32 aLarge, s8 **aPadMap) {
  ;
}

// 0x1530090
void dds3DebugMakeFloatStr(char *aStr, f32 aValue) {
  ;
}
