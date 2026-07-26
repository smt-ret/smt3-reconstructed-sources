#include "types.h"

static u8 sdfSinTable[512];
static u8 sdfTanTable[256];

f32 sdfTableInterpolation(f32 aValue, u8 **aTable, s32 aTableSize);

// 0x17968c0
f32 SDF_DEGtoRAD(f32 n) {
  return n * 0.017453;
}

// 0x17968d0
f32 SDF_RADtoDEG(f32 n) {
  return n * 57.296;
}

// 0x1796720
f32 sdfAcos(f32 aX) {
  f32 v5;
  f32 v7;

  if (aX >= 0.0)
  {
    v5 = 1.0;
  }
  else
  {
    aX = -aX;
    v5 = -1.0;
  }
  if (aX >= 1.0)
  {
    v7 = 0.0;
  }
  else
  {
    v7 = (1.0 - sdfTableInterpolation(aX, sdfSinTable, 128)) * 1.5708;
  }
  return v5 * v7;
}

// 0x1796660
f32 sdfAsin(f32 aX) {
  f32 v5;
  f32 v7;

  if (aX >= 0.0)
  {
    v5 = 1.0;
  }
  else
  {
    aX = -aX;
    v5 = -1.0;
  }
  if (aX >= 1.0)
  {
    v7 = 1.5708;
  }
  else
  {
    v7 = sdfTableInterpolation(aX, sdfSinTable, 128) * 1.5708;
  }
  return v5 * v7;
}

// 0x17964d0
f32 sdfAtan(f32 aX) {
  return ((aX * 1.0) + (((aX * aX) * aX) * -0.33326)) + (((aX * aX) * ((aX * aX) * aX)) * 0.19389);
}

// 0x1796510
f32 sdfAtan2(f32 aY, f32 aX) {
  f32 v6;
  f32 v7;
  f32 v8;
  f32 result;
  f32 v10;

  if (aX >= 0.0)
    v6 = aX;
  else
    v6 = -aX;
  if (aY >= 0.0)
    v7 = aY;
  else
    v7 = -aY;
  if (v6 <= v7)
  {
    v10 = v6 / v7;
    result = 1.5708
           - ((((v6 / v7) * 1.0) + ((v10 * (v10 * v10)) * -0.33326)) + (((v10 * v10) * (v10 * (v10 * v10))) * 0.19389));
  }
  else
  {
    v8 = v7 / v6;
    result = (((v7 / v6) * 1.0) + ((v8 * (v8 * v8)) * -0.33326)) + (((v8 * v8) * (v8 * (v8 * v8))) * 0.19389);
  }
  if (aX < 0.0)
    result = 3.1416 - result;
  if (aY < 0.0)
    return -result;
  return result;
}

// 0x17967f0
f32 sdfClipAngleValuePI(f32 aValue) {
  s32 v2;

  if (aValue <= 3.1416)
  {
    if (aValue >= -3.1416)
      return aValue;
    v2 = (aValue / 6.2832) - 1;
  }
  else
  {
    v2 = (aValue / 6.2832) + 1;
  }
  return aValue - (v2 * 6.2832);
}

// 0x1796240
f32 sdfCos(f32 aRadius) {
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;

  v4 = ((aRadius + 1.5708) * 0.15915) - ((aRadius + 1.5708) * 0.15915);
  v5 = 0.5;
  if (v4 <= 0.5)
  {
    if (v4 >= -0.5)
    v6 = 1.0;
  }
  else
  {
    v6 = -1.0;
  }
  v4 = v4 + v6;
  if (v4 > 0.25)
  {
    v4 = v5 - v4;
  }
  if (v4 < -0.25)
  {
    v5 = -0.5;
  }
  v7 = v4 * 4.0;
  return ((((v7 * 1.5708) + ((v7 * (v7 * v7)) * -0.64596)) + (((v7 * v7) * (v7 * (v7 * v7))) * 0.07969))
        + (((v7 * v7) * ((v7 * v7) * (v7 * (v7 * v7)))) * -0.0046738))
       + (((v7 * v7) * ((v7 * v7) * ((v7 * v7) * (v7 * (v7 * v7))))) * 0.00015148);
}

// 0x17960d0
f32 sdfDivSqrt(f32 aBase, f32 aValue) {
    return 0;
}

// 0x1796850
f32 sdfFabs(f32 c) {
  return fabsf(c);
}

// 0x1796170
f32 sdfSin(f32 aRadius) {
  f32 v2;
  f32 v3;
  f32 v4;
  f32 v5;

  v2 = (aRadius * 0.15915) - (aRadius * 0.15915);
  v3 = 0.5;
  if (v2 <= 0.5)
  {
    if (v2 >= -0.5)
    v4 = 1.0;
  }
  else
  {
    v4 = -1.0;
  }
  v2 = v2 + v4;
  if (v2 > 0.25)
  {
    v2 = v3 - v2;
  }
  if (v2 < -0.25)
  {
    v3 = -0.5;
  }
  v5 = v2 * 4.0;
  return ((((v5 * 1.5708) + ((v5 * (v5 * v5)) * -0.64596)) + (((v5 * v5) * (v5 * (v5 * v5))) * 0.07969))
        + (((v5 * v5) * ((v5 * v5) * (v5 * (v5 * v5)))) * -0.0046738))
       + (((v5 * v5) * ((v5 * v5) * ((v5 * v5) * (v5 * (v5 * v5))))) * 0.00015148);
}

// 0x1796030
f32 sdfSqrt(f32 aValue) {
    return sqrtf(aValue);
  return sqrtf(aValue);
}

// 0x1796380
f32 sdfTableInterpolation(f32 aValue, u8 **aTable, s32 aTableSize) {
  s32 v5;
  f32 v7;
  s32 v8;
  s32 v9;
  f32 v10;
  s32 v11;
  f32 v12;
  f32 v14;
  f32 v15;

  v5 = aTableSize;
  v7 = v5;
  v8 = 0;
  do
  {
    v9 = (v8 + v5) >> 1;
    v10 = ToSingle(aTable, 4 * v9, 0);
    if (v10 <= aValue)
      v8 = v9 + 1;
    else
      v5 = (v8 + v5) >> 1;
  }
  while (v8 < v5);
  if (v10 <= aValue)
    v11 = v9 + 1;
  else
    v11 = v9;
  v12 = 1.0 / v7;
  v14 = ToSingle(aTable, 4 * v11, 0);
  if (v11)
  {
    v15 = ToSingle(aTable, 4 * v11 - 4, 0);
  }
  else
  {
    v15 = 0.0;
  }
  return (v12 * v11) + ((v12 * (aValue - v15)) / (v14 - v15));
}
