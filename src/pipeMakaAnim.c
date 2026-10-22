#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct mdlManager_AbHeaderParm_t mdlManager_AbHeaderParm_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;
typedef struct tagMakaObject tagMakaObject;

void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
void Set(mdlManager_AbHeaderParm_t *this, u8 **src);
void eglLinkAlpha(s32 mode);
void eglLinkSprite(s32 x, s32 y, s32 w, s32 h, s32 u, s32 v, s32 uw, s32 vh, s32 rgba0, s32 rgba1, s32 rgba2, s32 rgba3, sdfTexHandle_t *th);
void makaDrawAnimation(s32 x, s32 y, f32 sclw, f32 sclh, u16 maka, u8 alpha);
void makaDrawAnimationZ(s32 x, s32 y, f32 sclw, f32 sclh, u16 maka, u8 alpha);
void makaDrawMAKA(tagMakaObject *makaPtr);
void makaDrawZMAKA(tagMakaObject *makaPtr);
void makaDrawZMAKA2(tagMakaObject *makaPtr);

// 0x1534830
void makaAdd(s32 maka, f32 x, f32 y) {
  struct tagMakaObject_array *makaWork;
  tagMakaObject_o *v8;
  struct System_Int32_array *pos;
  s32 v25;
  struct System_Int32_array *v26;
  char v28;
  UnityEngine_GameObject_o *makaObject;
  Il2CppObject *Component_object;
  UnityEngine_Animator_o *v34;
  Il2CppObject *v35;
  void *monitor;
  Il2CppObject *v37;
  CounterCtr_o *v39;
  void *v40;
  CounterCtr_o *v42;
  s32 v43;
  CounterCtr_o *v44;
  s32 v46;
  Il2CppObject *v47;
  void *v48;
  Il2CppObject *v49;
  CounterCtr_o *v51;
  void *v52;
  CounterCtr_o *v54;
  UnityEngine_Color_o white;
  UnityEngine_Color_o v57;
  UnityEngine_Color_o v58;

  if (!LODWORD(makaWork->max_length))
    goto LABEL_50;
LABEL_6:
  v8 = makaWork->m_Items[0];
  if (!v8->maka)
    goto LABEL_51;
  v8 = makaWork->m_Items[1];
  if (!v8->maka)
    goto LABEL_51;
  v8 = makaWork->m_Items[2];
  if (!v8->maka)
    goto LABEL_51;
  v8 = makaWork->m_Items[3];
  if (!v8->maka)
    goto LABEL_51;
  v8 = makaWork->m_Items[4];
  if (!v8->maka)
    goto LABEL_51;
  v8 = makaWork->m_Items[5];
  if (!v8->maka)
    goto LABEL_51;
  v8 = makaWork->m_Items[6];
  if (!v8->maka)
    goto LABEL_51;
  v8 = makaWork->m_Items[7];
  if (!v8->maka)
    goto LABEL_51;
  v8 = makaWork->m_Items[8];
  if (!v8->maka)
    goto LABEL_51;
  v8 = makaWork->m_Items[9];
  if (!v8->maka)
    goto LABEL_51;
  v8 = makaWork->m_Items[10];
  if (!v8->maka)
    goto LABEL_51;
  v8 = makaWork->m_Items[11];
  if (!v8->maka)
    goto LABEL_51;
  v8 = makaWork->m_Items[12];
  if (!v8->maka)
    goto LABEL_51;
  v8 = makaWork->m_Items[13];
  if (!v8->maka)
    goto LABEL_51;
  v8 = makaWork->m_Items[14];
  if (!v8->maka)
  {
LABEL_51:
    pos = v8->pos;
    if (maka < 0)
    {
      pos->m_Items[0] = 256;
      v26 = v8->pos;
      v28 = 16;
      v25 = 188;
    }
    else
    {
      pos->m_Items[0] = x;
      v25 = y;
      v26 = v8->pos;
      v28 = 15;
    }
    v26->m_Items[1] = v25;
    makaObject = v8->makaObject;
    v8->count = v28;
    SetActive(makaObject, 1, 0);
    Component_object = GetComponent_object_(v8->makaObject);
    v34 = Component_object;
    if ((maka & 0x7FFFFFFF) == 5)
    {
      SetInteger(Component_object, "anim", 1);
      v35 = GetComponent_object_(v8->makaObject);
      monitor = v35[1].monitor;
      v37 = v35;
      v39 = *(monitor + 4);
      white = get_white();
      Set(v39, 5, white, 0, 0);
      v40 = v37[1].monitor;
      v42 = *(v40 + 5);
      v57 = get_white();
      v43 = 5;
      v44 = v42;
    }
    else
    {
      if (ZmakaCount)
        v46 = 3;
      else
        v46 = 2;
      SetInteger(v34, "anim", v46);
      v47 = GetComponent_object_(v8->makaObject);
      v48 = v47[1].monitor;
      v49 = v47;
      v51 = *(v48 + 6);
      v58 = get_white();
      Set(v51, maka & 0x7FFFFFFF, v58, 0, 0);
      v52 = v49[1].monitor;
      v54 = *(v52 + 7);
      v57 = get_white();
      v44 = v54;
      v43 = maka & 0x7FFFFFFF;
    }
    Set(v44, v43, v57, 0, 0);
    v8->maka = maka;
  }
}

// 0x15364c0
void makaDraw(tagMakaObject *makaPtr) {
  if ((makaPtr->maka & 0x80000000) != 0)
  {
    if (ZmakaCount == 1)
      makaDrawZMAKA(makaPtr);
    else
      makaDrawZMAKA2(makaPtr);
  }
  else
  {
    makaDrawMAKA(makaPtr);
  }
}

// 0x15351b0
void makaDrawAnimation(s32 x, s32 y, f32 sclw, f32 sclh, u16 maka, u8 alpha) {
  u32 v10;
  s64 v11;
  bool v12;
  s32 v13;
  s16 v14;
  char v15;
  s64 v16;
  s32 v17;
  char v18;
  s32 v19;
  s32 v20;
  s32 v21;
  s32 v22;
  s32 v23;
  s32 v24;
  char *v26;
  s16 v27;
  f32 v31;
  s32 rgba0;
  f32 v33;
  u64 *v34;
  struct tagPipeTexture_array *MakaTex;
  f32 v37;
  f32 v38;
  s16 v40;
  f32 v41;
  f32 v42;
  s32 v44;
  char v45;
  sdfTexHandle_t_o *th;
  s32 v49;
  s32 v50;
  s32 v51;
  u64 *v52;
  u64 *v53;
  u64 v54[2];

  v10 = maka;
  v11 = 0;
  v49 = maka;
  v54[0] = 0;
  v54[1] = 0;
  if (maka)
  {
    do
    {
      v12 = v10 > 9;
      ++v11;
      v10 /= 0xAu;
    }
    while (v12);
  }
  v52 = NewSpecific(s16, 0xAu);
  v53 = NewSpecific(sbyte, 0xAu);
  sub_854930(v54, 0);
  sub_854930(v54, 1u);
  v13 = 0;
  v14 = 0;
  v15 = 0;
  v16 = v11;
  v17 = 1 - v11;
  v18 = v11 + 7;
  do
  {
    if (!v16)
    {
      LOBYTE(v20) = -1;
      if (!*(v53 + 6))
        goto LABEL_20;
      goto LABEL_21;
    }
    if (v16 == 1)
    {
      v19 = 1;
      goto LABEL_19;
    }
    v21 = v18 & 7;
    v22 = (~v13 + v11) & 7;
    if ((v11 - 2 - v13) < 7)
    {
      v19 = 1;
      if (!v22)
        goto LABEL_19;
LABEL_17:
      v24 = -v21;
      do
      {
        v19 = (10 * v19);
        ++v24;
      }
      while (v24);
      goto LABEL_19;
    }
    v23 = v17 + v21;
    LOWORD(v19) = 1;
    do
    {
      v19 = (-7936 * v19);
      v23 += 8;
    }
    while (v23);
    if (v22)
      goto LABEL_17;
LABEL_19:
    v20 = v49 / v19 % 10;
    if (v16 >= *(v53 + 6))
    {
LABEL_20:
    }
LABEL_21:
    *(v53 + v16 + 32) = v20;
    v26 = v53 + v16 + 32;
    if (v16 == v11)
    {
      v27 = 0;
    }
    else
    {
      v27 = (sclw * 10.0);
      if (v15 != 1)
      {
        v27 = (sclw * 13.0);
        if (v20 == 1)
          v27 = (sclw * 10.0);
      }
    }
    v14 += v27;
    *(v52 + v16 + 16) = v14;
    v15 = *v26;
    v12 = v16-- <= 0;
    ++v13;
    ++v17;
    ++*v26;
    v18 += 7;
  }
  while (!v12);
  v51 = (sclw * 22.0);
  v31 = ((v14 + v51) >> 1);
  v50 = (sclh * 26.0);
  v33 = (sclh * 26.0) * 0.5;
  v34 = v53 + 4;
  do
  {
    sub_854710(v54, 0);
    v38 = v37;
    v40 = *(v52 + v11 + 16);
    sub_854710(v54, 1u);
    v42 = v41;
    v44 = *(v34 + v11);
    v45 = *(v34 + v11);
    else
    {
      if (!LODWORD(MakaTex->max_length))
      {
LABEL_44:
      }
    }
    th = MakaTex->m_Items[0]->th;
    rgba0 = (alpha << 24) | 0x808080;
    eglLinkSprite(
      ((v38 + v40) - v31),
      (v42 - v33),
      v51,
      v50,
      (22 * (v44 % 5)) | 1,
      26 * (((1717986919LL * v45) >> 33) + (1717986919LL * v45 < 0)) + 2,
      22,
      26,
      rgba0,
      rgba0,
      rgba0,
      rgba0,
      th,
      0);
    v12 = v11-- <= 0;
  }
  while (!v12);
}

// 0x1535ac0
void makaDrawAnimationZ(s32 x, s32 y, f32 sclw, f32 sclh, u16 maka, u8 alpha) {
  u32 v10;
  s64 v11;
  bool v12;
  s32 v13;
  s32 v14;
  char v15;
  s64 v16;
  s32 v17;
  s32 v18;
  char v19;
  s32 v21;
  s32 v22;
  s32 v23;
  s32 v24;
  s32 v25;
  s32 v26;
  char *v28;
  s32 v34;
  f32 v35;
  f32 v36;
  s32 rgba0;
  u64 *v38;
  f32 v39;
  f32 v40;
  s16 v42;
  f32 v44;
  f32 v45;
  s32 v47;
  char v48;
  struct tagPipeTexture_array *MakaTex;
  sdfTexHandle_t_o *th;
  u32 v54;
  s32 v55;
  s32 v56;
  s16 w;
  s32 wa;
  u64 *v59;
  u64 *v60;
  u64 v61[2];

  v10 = maka;
  v11 = 0;
  v55 = maka;
  v61[0] = 0;
  v61[1] = 0;
  if (maka)
  {
    do
    {
      v12 = v10 > 9;
      ++v11;
      v10 /= 0xAu;
    }
    while (v12);
  }
  v60 = NewSpecific(sbyte, 0xAu);
  v59 = NewSpecific(s16, 0xAu);
  sub_854930(v61, 0);
  sub_854930(v61, 1u);
  v13 = 0;
  v14 = 0;
  v54 = vcvts_n_s32_f32(sclw, 4u);
  v15 = 0;
  v16 = v11;
  v17 = 1 - v11;
  LOWORD(v18) = 0;
  v19 = v11 + 7;
  do
  {
    w = v18;
    if (!v16)
    {
      LOBYTE(v22) = -1;
      if (!*(v60 + 6))
        goto LABEL_24;
      goto LABEL_25;
    }
    if (v16 == 1)
    {
      v21 = 1;
      goto LABEL_23;
    }
    v23 = v19 & 7;
    v24 = (~v13 + v11) & 7;
    if ((v11 - 2 - v13) < 7)
    {
      v21 = 1;
      if (!v24)
        goto LABEL_23;
LABEL_21:
      v26 = -v23;
      do
      {
        v21 = (10 * v21);
        ++v26;
      }
      while (v26);
      goto LABEL_23;
    }
    v25 = v17 + v23;
    LOWORD(v21) = 1;
    do
    {
      v21 = (-7936 * v21);
      v25 += 8;
    }
    while (v25);
    if (v24)
      goto LABEL_21;
LABEL_23:
    v22 = v55 / v21 % 10;
    if (v16 >= *(v60 + 6))
    {
LABEL_24:
    }
LABEL_25:
    *(v60 + v16 + 32) = v22;
    v28 = v60 + v16 + 32;
    if (v16 == v11)
    {
      v14 = 0;
      goto LABEL_42;
    }
    v56 = v14;
    if (v15 == 9)
    {
      v14 = (sclw * 20.0);
      if (v22 == 9)
        goto LABEL_42;
LABEL_33:
      v14 = (sclw * 14.0);
      if (v22 >= 1)
        goto LABEL_42;
LABEL_38:
      v14 = v56;
      if (!v22)
        goto LABEL_41;
      goto LABEL_42;
    }
    if (v15 >= 1)
      goto LABEL_33;
    if (v15)
      goto LABEL_38;
    v14 = (sclw * 14.0);
    if (v22)
LABEL_41:
      v14 = v54;
LABEL_42:
    v18 = w + v14;
    *(v59 + v16 + 16) = v18;
    v15 = *v28;
    v12 = v16-- <= 0;
    ++v13;
    ++v17;
    ++*v28;
    v19 += 7;
  }
  while (!v12);
  wa = (sclw * 25.0);
  v34 = (sclh * 30.0);
  v35 = (sclh * 30.0) * 0.5;
  v36 = ((v18 + wa) << 16 >> 17);
  v38 = v60 + 4;
  do
  {
    sub_854710(v61, 0);
    v40 = v39;
    v42 = *(v59 + v11 + 16);
    sub_854710(v61, 1u);
    v45 = v44;
    v47 = *(v38 + v11);
    v48 = *(v38 + v11);
    th = MakaTex->m_Items[1]->th;
    rgba0 = (alpha << 24) | 0x808080;
    eglLinkSprite(
      ((v40 + v42) - v36),
      (v45 - v35),
      wa,
      v34,
      25 * (v47 % 5) + 1,
      30 * (((1717986919LL * v48) >> 33) + (1717986919LL * v48 < 0)) + 2,
      25,
      30,
      rgba0,
      rgba0,
      rgba0,
      rgba0,
      th,
      0);
    v12 = v11-- <= 0;
  }
  while (!v12);
}

// 0x1536110
void makaDrawBack1(s32 x, s32 y, f32 w, f32 h, f32 alpha) {
  ;
}

// 0x15364b0
void makaDrawBack2(s32 x, s32 y, f32 w, f32 h, f32 alpha) {
  ;
}

// 0x1534ec0
void makaDrawMAKA(tagMakaObject *makaPtr) {
  s32 count;
  u32 *v4;
  u32 v6;
  u32 *v7;
  u32 maka;
  s32 v11;
  s32 v13;
  u32 v14;
  f32 v15;
  f32 v16;
  f32 v21;
  f32 v22;
  f32 v23;
  u32 v24;

  count = makaPtr->count;
  v4 = NewSpecific(s32, 2u);
  v6 = v4[6];
  v7 = v4;
  v4[8] = 256;
  v4[9] = 236;
  maka = makaPtr->maka;
  v11 = 15 - count;
  eglLinkAlpha(0);
  v13 = v11 << 24;
  v14 = v7[6];
  if (v11 << 24 <= 83886080)
    v15 = v11 / 5.0;
  else
    v15 = 1.0;
  if (v13 <= 83886080)
    v16 = v11 / 5.0;
  else
    v16 = (15 - v11) / 10.0;
  makaDrawAnimation(
    v7[8],
    (((1.0 - v15) * v7[9]) + (v15 * (v7[9] - 48))),
    1.0,
    1.0,
    maka,
    vcvts_n_s32_f32(v16, 7u));
  eglLinkAlpha(1);
  v21 = 0.0;
  if (v13 >= 33554433)
  {
    if (v13 <= 83886080)
    {
      v23 = (v11 - 2);
      v22 = 3.0;
    }
    else
    {
      if (v13 > 167772160)
        goto LABEL_30;
      v22 = 6.0;
      v23 = (11 - v11);
    }
    v21 = v23 / v22;
  }
LABEL_30:
  v24 = v7[6];
  makaDrawAnimation(v7[8], v7[9] - 48, 1.0, 1.0, maka, vcvts_n_s32_f32(v21, 7u));
}

// 0x1535740
void makaDrawZMAKA(tagMakaObject *makaPtr) {
  s32 count;
  System_Array_o *v4;
  u32 maka;
  s32 v8;
  s32 v9;
  f32 v10;
  f32 v11;
  struct System_Int32_array *pos;
  u32 max_length;
  struct System_Int32_array *v14;
  s32 v15;
  s32 v16;
  f32 v18;
  struct System_Int32_array *v19;
  u32 v20;
  struct System_Int32_array *v21;
  s64 v22;

  count = makaPtr->count;
  v4 = NewSpecific(f32, 7u);
  InitializeArray_1543888(v4, Field__PrivateImplementationDetails__D4034CD50F657181B2AA43F9FCD0FC4D5A4283E0);
  maka = makaPtr->maka;
  eglLinkAlpha(1);
  v8 = 0x10000000 - (count << 24);
  v9 = v8 >> 24;
  if (v8 > 117440512)
  {
    if (v8 <= 184549376)
    {
      v10 = (11 - v9) * 0.25;
    }
    else
    {
      v10 = 0.0;
      v11 = 0.0;
      if (v8 > 201326592)
      {
        pos = makaPtr->pos;
        max_length = pos->max_length;
        v14 = pos;
        if (max_length)
          goto LABEL_10;
LABEL_24:
      }
    }
    goto LABEL_23;
  }
  v22 = v9 - 1LL;
  v10 = *(&v4[2].klass + v22);
  if (v8 > 0x1000000)
  {
LABEL_23:
    v11 = ((12 - v9) / 11.0) * 128.0;
    pos = makaPtr->pos;
    max_length = pos->max_length;
    v14 = pos;
    if (!max_length)
      goto LABEL_24;
    goto LABEL_10;
  }
  v11 = 128.0;
  pos = makaPtr->pos;
  max_length = pos->max_length;
  v14 = pos;
  if (!max_length)
    goto LABEL_24;
LABEL_10:
  v15 = pos->m_Items[0];
  v16 = v14->m_Items[1];
  if (v8 > 117440512)
  {
    makaDrawAnimationZ(v15, ((v10 * (v16 - 40)) + ((1.0 - v10) * (v16 + 3))), 1.3, 1.3, maka, v11);
    v18 = (16 - v9) / 9.0;
    v19 = makaPtr->pos;
    v20 = v19->max_length;
    v21 = v19;
    if (!v20)
      goto LABEL_27;
  }
  else
  {
    makaDrawAnimationZ(v15, (((1.0 - v10) * v16) + (v10 * (v16 - 40))), 1.3, 1.3, maka, v11);
    if (v8 >= 100663297)
      v18 = 1.0;
    else
      v18 = 0.0;
    v19 = makaPtr->pos;
    v20 = v19->max_length;
    v21 = v19;
    if (!v20)
    {
LABEL_27:
    }
  }
  makaDrawAnimationZ(v19->m_Items[0], v21->m_Items[1] - 40, 1.5, 1.7, maka, (v18 * 25.0));
}

// 0x1536120
void makaDrawZMAKA2(tagMakaObject *makaPtr) {
  s32 count;
  System_Array_o *v4;
  u32 maka;
  s32 v8;
  s32 v9;
  f32 v10;
  f32 v11;
  struct System_Int32_array *pos;
  u32 max_length;
  struct System_Int32_array *v14;
  s32 v15;
  s32 v16;
  f32 v17;
  f32 v18;
  s64 v19;
  f32 v25;
  struct System_Int32_array *v26;
  u32 v27;
  struct System_Int32_array *v28;

  count = makaPtr->count;
  v4 = NewSpecific(f32, 7u);
  InitializeArray_1543888(v4, Field__PrivateImplementationDetails__D4034CD50F657181B2AA43F9FCD0FC4D5A4283E0);
  maka = makaPtr->maka;
  eglLinkAlpha(0);
  v8 = 0x10000000 - (count << 24);
  v9 = v8 >> 24;
  if (v8 > 117440512)
  {
    if (v8 <= 184549376)
    {
      v10 = (11 - v9) * 0.25;
    }
    else
    {
      v10 = 0.0;
      v11 = 0.0;
      if (v8 > 201326592)
      {
        pos = makaPtr->pos;
        max_length = pos->max_length;
        v14 = pos;
        if (max_length)
          goto LABEL_10;
LABEL_20:
      }
    }
    goto LABEL_19;
  }
  v19 = v9 - 1LL;
  v10 = *(&v4[2].klass + v19);
  if (v8 > 0x1000000)
  {
LABEL_19:
    v11 = ((12 - v9) / 11.0) * 128.0;
    pos = makaPtr->pos;
    max_length = pos->max_length;
    v14 = pos;
    if (!max_length)
      goto LABEL_20;
    goto LABEL_10;
  }
  v11 = 128.0;
  pos = makaPtr->pos;
  max_length = pos->max_length;
  v14 = pos;
  if (!max_length)
    goto LABEL_20;
LABEL_10:
  v15 = pos->m_Items[0];
  v16 = v14->m_Items[1];
  if (v8 > 117440512)
  {
    v17 = v10 * (v16 - 40);
    v18 = (1.0 - v10) * (v16 + 3);
  }
  else
  {
    v17 = (1.0 - v10) * v16;
    v18 = v10 * (v16 - 40);
  }
  makaDrawAnimationZ(v15, (v17 + v18), 1.7, 1.7, maka, v11);
  eglLinkAlpha(1);
  if (v8 <= 100663296)
    v25 = 0.0;
  else
    v25 = 1.0;
  if (v8 < 117440513)
  {
    v26 = makaPtr->pos;
    v27 = v26->max_length;
    v28 = v26;
    if (v27)
      goto LABEL_31;
LABEL_35:
  }
  v25 = (16 - v9) / 9.0;
  v26 = makaPtr->pos;
  v27 = v26->max_length;
  v28 = v26;
  if (!v27)
    goto LABEL_35;
LABEL_31:
  makaDrawAnimationZ(v26->m_Items[0], v28->m_Items[1] - 40, 1.8, 1.8, maka, (v25 * 25.0));
}

// 0x1534dd0
s32 makaGetMaxNum(u32 maka) {
  u32 v2;
  s32 result;
  bool v4;

  v2 = maka & 0x7FFFFFFF;
  if ((maka & 0x7FFFFFFF) == 0)
    return 0;
  result = 0;
  do
  {
    v4 = v2 > 9;
    ++result;
    v2 /= 0xAu;
  }
  while (v4);
  return result;
}

// 0x1534e10
s32 makaGetNum(s32 maka, s32 num) {
  s32 v3;
  s32 v5;
  s32 v6;

  if (!num)
    return -1;
  if (num != 1)
  {
    v3 = (num - 1) & 3;
    if ((num - 2) >= 3)
    {
      v5 = v3 + 1 - num;
      LOWORD(num) = 1;
      do
      {
        num = (10000 * num);
        v5 += 4;
      }
      while (v5);
      if (!v3)
        return maka / num % 10;
    }
    else
    {
      num = 1;
      if (!v3)
        return maka / num % 10;
    }
    v6 = -v3;
    do
    {
      num = (10 * num);
      ++v6;
    }
    while (v6);
  }
  return maka / num % 10;
}

// 0x15344e0
void makaInit(void) {
  AssetBundleCtrl_o *asset_bc;
  Il2CppObject *Prefab_16624656;
  s64 v5;
  u64 v7;
  s32 *makaWork;
  Il2CppObject *v9;
  struct tagMakaObject_array *v11;
  s64 v13;
  UnityEngine_GameObject_o *v14;
  UnityEngine_Transform_o *transform;
  struct tagMakaObject_array *v17;

  asset_bc = get_asset_bc();
  Prefab_16624656 = LoadPrefab_16624656(asset_bc, "pipe_common", "charactor/e/pipedata/makamark", "makamark");
  v5 = 4;
  v7 = 0;
  {
LABEL_9:
  }
  while (1)
  {
    if (v7 >= makaWork[6])
      break;
    v9 = Allocate(tagMakaObject);
    v9[1].monitor = NewSpecific(s32, 2u);
    v9[2].klass = NewSpecific(sbyte, 3u);
    _ctor(v9, 0);
    *&makaWork[2 * v5] = v9;
    v11 = makaWork;
    v13 = *(&v11->obj.klass + v5);
    v14 = Find("Canvas_UI", 0);
    transform = get_transform(v14, 0);
    *(v13 + 40) = Instantiate_object__425664(Prefab_16624656, transform, 0);
    v17 = makaWork;
    SetActive(*(*(&v17->obj.klass + v5++) + 40LL), 0, 0);
    v7 = v5 - 4;
      goto LABEL_9;
  }
}
