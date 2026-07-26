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
  v8 = makaWork->m_Items[0];
  if (!v8->maka)
  v8 = makaWork->m_Items[1];
  if (!v8->maka)
  v8 = makaWork->m_Items[2];
  if (!v8->maka)
  v8 = makaWork->m_Items[3];
  if (!v8->maka)
  v8 = makaWork->m_Items[4];
  if (!v8->maka)
  v8 = makaWork->m_Items[5];
  if (!v8->maka)
  v8 = makaWork->m_Items[6];
  if (!v8->maka)
  v8 = makaWork->m_Items[7];
  if (!v8->maka)
  v8 = makaWork->m_Items[8];
  if (!v8->maka)
  v8 = makaWork->m_Items[9];
  if (!v8->maka)
  v8 = makaWork->m_Items[10];
  if (!v8->maka)
  v8 = makaWork->m_Items[11];
  if (!v8->maka)
  v8 = makaWork->m_Items[12];
  if (!v8->maka)
  v8 = makaWork->m_Items[13];
  if (!v8->maka)
  v8 = makaWork->m_Items[14];
  if (!v8->maka)
  {
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
      SetInteger(Component_object, StringLiteral_4572, 1);
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
      SetInteger(v34, StringLiteral_4572, v46);
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
    eglLinkSprite(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

// 0x1535ac0
void makaDrawAnimationZ(s32 x, s32 y, f32 sclw, f32 sclh, u16 maka, u8 alpha) {
    eglLinkSprite(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
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
      v22 = 6.0;
      v23 = (11 - v11);
    }
    v21 = v23 / v22;
  }
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
      }
    }
  }
  v22 = v9 - 1LL;
  v10 = *(&v4[2].klass + v22);
  if (v8 > 0x1000000)
  {
    v11 = ((12 - v9) / 11.0) * 128.0;
    pos = makaPtr->pos;
    max_length = pos->max_length;
    v14 = pos;
    if (!max_length)
  }
  v11 = 128.0;
  pos = makaPtr->pos;
  max_length = pos->max_length;
  v14 = pos;
  if (!max_length)
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
      }
    }
  }
  v19 = v9 - 1LL;
  v10 = *(&v4[2].klass + v19);
  if (v8 > 0x1000000)
  {
    v11 = ((12 - v9) / 11.0) * 128.0;
    pos = makaPtr->pos;
    max_length = pos->max_length;
    v14 = pos;
    if (!max_length)
  }
  v11 = 128.0;
  pos = makaPtr->pos;
  max_length = pos->max_length;
  v14 = pos;
  if (!max_length)
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
  }
  v25 = (16 - v9) / 9.0;
  v26 = makaPtr->pos;
  v27 = v26->max_length;
  v28 = v26;
  if (!v27)
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
  Prefab_16624656 = LoadPrefab_16624656(asset_bc, StringLiteral_19042, StringLiteral_21894, StringLiteral_21895);
  v5 = 4;
  v7 = 0;
  {
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
    v14 = Find(StringLiteral_4905, 0);
    transform = get_transform(v14, 0);
    *(v13 + 40) = Instantiate_object__425664(Prefab_16624656, transform, 0);
    v17 = makaWork;
    SetActive(*(*(&v17->obj.klass + v5++) + 40LL), 0, 0);
    v7 = v5 - 4;
  }
}
