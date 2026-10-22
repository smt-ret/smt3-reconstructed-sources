#include "types.h"

typedef struct sdfRandCB_t sdfRandCB_t;

static sdfRandCB_t *sdfDefaultRandCB;

u32 sdfGetRand(sdfRandCB_t **aCB);
void sdfRandomize(sdfRandCB_t **aCB, u32 aSeed);

// 0x17a9910
u32 sdfGetRand(sdfRandCB_t **aCB) {
  sdfRandCB_t_o *sdfDefaultRandCB;
  s32 v4;
  struct System_UInt32_array *v;
  u32 v7;
  struct System_UInt32_array *v8;
  u32 v10;
  struct System_UInt32_array *v11;
  u32 v13;
  struct System_UInt32_array *v14;
  struct System_UInt32_array *v16;
  u64 v17;
  u32 v18;
  struct System_UInt32_array *v20;
  struct System_UInt32_array *v22;
  struct System_UInt32_array *v24;
  sdfRandCB_t_o *v27;

  sdfDefaultRandCB = *aCB;
  if (*aCB)
  {
    v4 = 0;
    v = sdfDefaultRandCB->v;
    if (!LODWORD(v->max_length))
      goto LABEL_5;
  }
  else
  {
    v4 = 1;
    *aCB = sdfDefaultRandCB;
    v = sdfDefaultRandCB->v;
    if (!LODWORD(v->max_length))
    {
LABEL_5:
    }
  }
  v7 = v->m_Items[0];
  v8 = sdfDefaultRandCB->v;
  v10 = v8->m_Items[1];
  v11 = sdfDefaultRandCB->v;
  v13 = v11->m_Items[2];
  v14 = sdfDefaultRandCB->v;
  v16 = sdfDefaultRandCB->v;
  HIDWORD(v17) = v14->m_Items[3];
  LODWORD(v17) = v13;
  v18 = (v17 >> 31) ^ (__PAIR64__(v10, v7) >> 30);
  v16->m_Items[0] = v18;
  v20 = (*aCB)->v;
  v20->m_Items[1] = v7;
  v22 = (*aCB)->v;
  v22->m_Items[2] = v10;
  v24 = (*aCB)->v;
  v24->m_Items[3] = v13;
  if (v4)
  {
    v27 = *aCB;
    sdfDefaultRandCB = v27;
  }
  return v18;
}

// 0x17a9b30
f32 sdfGetRandFloat(sdfRandCB_t **aCB) {
  f32 v3;

  v3 = (sdfGetRand(aCB) & 0xFFFFFF);
  return v3 * 0.000000059605;
}

// 0x17a9bb0
u32 sdfGetRandInt(sdfRandCB_t **aCB, u32 aLimit) {
  if (!aLimit)
    return 0;
  return sdfGetRand(aCB, *&aLimit) % aLimit;
}

// 0x17a9c50
void sdfRandomize(sdfRandCB_t **aCB, u32 aSeed) {
  sdfRandCB_t_o *sdfDefaultRandCB;
  s32 v6;
  u32 v8;
  struct System_UInt32_array *v;
  struct System_UInt32_array *v11;
  u32 v12;
  u32 v13;
  u64 v14;
  u32 v16;
  struct System_UInt32_array *v17;
  u32 v19;
  u64 v20;
  struct System_UInt32_array *v21;
  sdfRandCB_t_o *v24;

  sdfDefaultRandCB = *aCB;
  if (*aCB)
  {
    v6 = 0;
  }
  else
  {
    v6 = 1;
    *aCB = sdfDefaultRandCB;
  }
  v8 = aSeed ^ 0xAED1A0C;
  v = sdfDefaultRandCB->v;
  v->m_Items[0] = v8;
  v11 = (*aCB)->v;
  v12 = v8 >> 8;
  HIDWORD(v14) = v8;
  LODWORD(v14) = v8;
  v13 = v14 >> 8;
  v11->m_Items[1] = v13;
  v16 = __PAIR64__(v12, v13) >> 8;
  v17 = (*aCB)->v;
  v17->m_Items[2] = v16;
  HIDWORD(v20) = v16 ^ 0x11BE81C7;
  LODWORD(v20) = v16 ^ 0x11BE81C7;
  v19 = v20 >> 8;
  v21 = (*aCB)->v;
  v21->m_Items[3] = v19;
  if (v6)
  {
    v24 = *aCB;
    sdfDefaultRandCB = v24;
  }
}

// 0x17a9de0
void sdfRandomizeByTime(sdfRandCB_t **aCB) {
  System_Array_o *v3;
  s32 v5;
  u32 v6;
  s32 v7;
  s32 v9;
  s32 v10;
  s32 v11;
  s32 v12;
  u32 v15;
  u64 dateData;

  dateData = 0;
  v3 = NewSpecific(ushort, 0xDu);
  InitializeArray_1543888(v3, Field__PrivateImplementationDetails__4CB70A8C9D931318D045B1B277D0A5672811F20B);
  dateData = get_Now().dateData;
  v5 = sub_2DC9F0(&dateData);
  v6 = v5 - 1;
  if (v5 < 1 || v5 > SLODWORD(v3[1].monitor))
    v6 = 0;
  v7 = sub_2DCDC0(&dateData);
  v9 = *(&v3[2].klass + v6);
  v10 = v9 + 366 * v7 + sub_2DC7B0(&dateData);
  v11 = sub_2DC890(&dateData) + 24 * v10;
  v12 = sub_2DC970(&dateData) + 60 * v11;
  v15 = sub_2DCC70(&dateData) + 60 * v12 + 2128295040;
  sdfRandomize(aCB, v15);
}
