#include "types.h"

typedef struct bDrawText bDrawText;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct mdlDebugFog_dds3FogEditorStrTable_t mdlDebugFog_dds3FogEditorStrTable_t;
typedef struct mdlDebugFog_dds3FogEditorWork_t mdlDebugFog_dds3FogEditorWork_t;
typedef struct mdlDebugFog_fogControlValueTable_t mdlDebugFog_fogControlValueTable_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;

struct mdlDebugFog_dds3FogEditorWork_t {
    u8 padSrc[UNKNOWN_ARRAY_SIZE];
    u8 mode;
    u8 cursorTimer;
    s16 cursor;
    f32 valuePtr[8];
    f32 min[8];
    f32 max[8];
    sdfDrawTag_t *drawTag;
};

struct mdlDebugFog_dds3FogEditorStrTable_t {
    u16 x;
    u16 y;
    u32 attr;
    char *str;
};

struct mdlDebugFog_fogControlValueTable_t {
    u32 y;
    f32 valuePtr;
    s32 minValue;
    s32 maxValue;
    char *tagStr;
    char *valueFormatStr;
};

static s32 CX__;
static s32 CY__;
static s32 Z__;
static mdlDebugFog_dds3FogEditorWork_t *dds3FogEditorWork;
static bDrawText bsetText;

void PreBtlMenuObj(s32 idx);
sdfVector4_t SDF_VU0__Retdds3ColorItoF(u32 rgba, f32 ratio);
void SetBtlMenuObj(s32 idx);
bDrawText btlDevPrintf(s32 aX, s32 aY, s32 aZ, s32 color, char *aStr, s32 f);
void btlDrawTagLink(bDrawText *setText, bDrawText dt, s32 idx);
f32 dds3FogEditorChangeValue(s32 num);
void initBtlMenuObj(s32 x, s32 y, s32 w, s32 h, s32 idx);

// 0xdf7c50
f32 dds3FogEditorChangeValue(s32 num) {
  struct System_Single_array *valuePtr;
  s64 v5;
  f32 v7;
  f32 v8;
  f32 v9;
  struct mdlDebugFog_dds3FogEditorWork_t_o *dds3FogEditorWork;
  struct System_Single_array *min;
  s64 v14;
  struct System_Single_array *max;
  f32 v16;
  struct System_Byte_array *padSrc;
  f32 v19;
  struct System_Byte_array *v22;
  struct System_Byte_array *v25;
  struct System_Byte_array *v28;
  struct System_Byte_array *v31;
  struct System_Byte_array *v34;
  struct System_Byte_array *v37;
  struct System_Byte_array *v40;
  f32 result;

  valuePtr = dds3FogEditorWork->valuePtr;
  v5 = num;
  v7 = valuePtr->m_Items[num];
  v8 = 1000.0;
  if (v7 >= 1000.0)
  {
    if (v7 >= 10000.0)
    {
      v9 = 100.0;
    }
    else
    {
      v8 = 100.0;
      v9 = 10.0;
    }
  }
  else
  {
    v9 = 1.0;
    v8 = 10.0;
  }
  min = dds3FogEditorWork->min;
  v14 = min + 4 * num;
  max = dds3FogEditorWork->max;
  v16 = *(v14 + 32);
  padSrc = dds3FogEditorWork->padSrc;
  v19 = max->m_Items[v5];
  if (padSrc->m_Items[5] < 0)
  {
    result = *(v14 + 32);
    if (v7 >= v19)
      return result;
  }
  v22 = dds3FogEditorWork->padSrc;
  if ((v22->m_Items[5] & 2) != 0)
  {
    result = v7 + v8;
    if (result > v19)
      return v19;
    return result;
  }
  v25 = dds3FogEditorWork->padSrc;
  if (v25->m_Items[4] < 0)
  {
    result = v19;
    if (v7 <= v16)
      return result;
  }
  v28 = dds3FogEditorWork->padSrc;
  if ((v28->m_Items[4] & 2) != 0)
  {
    result = v7 - v8;
    if (result < v16)
      return v16;
    return result;
  }
  v31 = dds3FogEditorWork->padSrc;
  if (v31->m_Items[7] < 0)
  {
    result = v16;
    if (v7 >= v19)
      return result;
    result = v7 + v9;
  }
  v34 = dds3FogEditorWork->padSrc;
  if ((v34->m_Items[7] & 2) == 0)
  {
    v37 = dds3FogEditorWork->padSrc;
    if ((v37->m_Items[6] & 0x80000000) == 0)
    {
      v40 = dds3FogEditorWork->padSrc;
      if ((v40->m_Items[6] & 2) == 0)
        return v7;
      result = v7 - v9;
      if ((v7 - v9) < v16)
        return v19;
      return result;
    }
    result = v19;
    if (v7 <= v16)
      return result;
    result = v7 - v9;
  }
  result = v7 + v9;
  if ((v7 + v9) > v19)
    return v16;
  return result;
}

// 0xdf80b0
void *dds3FogEditorProcess(dds3ProcessID_t *aId) {
    initBtlMenuObj(0, 0, 0, 0, 0);
    PreBtlMenuObj(0);
    SDF_VU0__Retdds3ColorItoF(0, 0);
    dds3FogEditorChangeValue(0);
    btlDevPrintf(0, 0, 0, 0, 0, 0);
    btlDrawTagLink(0, (bDrawText){0}, 0);
    SetBtlMenuObj(0);
    return 0;
}
