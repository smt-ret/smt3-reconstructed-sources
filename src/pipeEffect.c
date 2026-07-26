#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct PIPE_EFF_t PIPE_EFF_t;
typedef struct dds3Effect_Blur_t dds3Effect_Blur_t;
typedef struct effHandle_t effHandle_t;
typedef struct tagPipeObject tagPipeObject;

static s32 BulrLimitFrame;

u8 **LoadFileByte(AssetBundleCtrl *this, char *key, char *path_name);
void *LoadFileObject(AssetBundleCtrl *this, char *key, char *path_name);
void billSetTexture(void **pTexture);
void dds3EffectBlur(dds3Effect_Blur_t **pBlur, bool bPS2mode, s32 SkillID);
void dds3EffectDelete(void **pData);
void dds3EffectDraw(void **pData);
u16 dds3EffectGetState(effHandle_t *hEffect);
effHandle_t *dds3EffectLoad(void **pD3P, s32 bPos, bool tbldata);
void dds3EffectSetPosition(void **pData, sdfVector4_t pPos);
void getPosTranslate(tagPipeObject *objPtr, sdfVector4_t *pos);
tagPipeObject *objMyData(void);
void pipeEffCreateLoadFile(PIPE_EFF_t ***pEffect, char *d3pName, char *tgaName, u8 maxSize);
void pipeEffDraw2Doffset(PIPE_EFF_t ***pEffect, u8 maxSize);
void pipeEffReleaseData(PIPE_EFF_t ***pEffect, u8 maxSize);
void pipeEffSet2Doffset(s32 offset, f32 x, f32 y, PIPE_EFF_t ***pEffect, u8 maxSize);
void pipeEffTask(PIPE_EFF_t ***pEffect, u8 effNum);

// 0x14b8600
u32 COLOR_ARGB(s32 a, s32 r, s32 g, s32 b) {
  return r | (a << 24) | (g << 8) | (b << 16);
}

// 0x14b8690
void pipeBulrLimit(void) {
  u64 *v1;
  dds3Effect_Blur_t_o *v2;
  u64 *v3;
  sdfIVector2_t_o *v4;
  s32 v8;
  s64 v9;
  s64 v11;
  u64 v12;
  s64 v13;
  u64 v14;
  s64 v15;
  u64 v17;
  s64 v19;
  u64 v21;
  s64 v23;
  s64 v25;
  s64 v27;
  u64 v28;
  s64 v29;
  u64 v30;
  s64 v31;
  u64 v33;
  s64 v35;
  u64 v37;
  s64 v39;
  dds3Effect_Blur_t_o *pBlur;

  v1 = Allocate(dds3Effect_Blur_t);
  dds3Effect_Blur_t___ctor(v1);
  pBlur = v1;
  NewSpecific(sdfIVector2_t, 2u);
  v2 = Allocate(dds3Effect_Blur_t);
  dds3Effect_Blur_t___ctor(v2);
  v3 = NewSpecific(sdfIVector2_t, 1u);
  v4 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v4);
  v4->pm = NewSpecific(s32, 2u);
  v3[4] = v4;
  v2->xy = v3;
  {
    else
    {
      if (!BulrLimitFrame)
    }
    v1[2] = 0x25C8A8A8ALL;
    v1[3] = 0x3F80000000000000LL;
    v9 = *(v1[4] + 16);
    *(v9 + 32) = 0;
    v11 = *(v1[4] + 16);
    *(v11 + 36) = 0;
    v12 = v1[5];
    v13 = *(*(v12 + 32) + 16LL);
    *(v13 + 32) = 0;
    v14 = v1[5];
    v15 = *(*(v14 + 32) + 16LL);
    *(v15 + 36) = 0;
    v17 = v1[5];
    v19 = *(*(v17 + 40) + 16LL);
    *(v19 + 32) = 512;
    v21 = v1[5];
    v23 = *(*(v21 + 40) + 16LL);
    *(v23 + 36) = 448;
    dds3EffectBlur(&pBlur, 0, 0);
    --BulrLimitFrame;
    return;
  }
  v8 = 0;
  if (BulrLimitFrame)
  v1[2] = 0x22E8A8A8ALL;
  v1[3] = 0x3F80000000000000LL;
  v25 = *(v1[4] + 16);
  *(v25 + 32) = 0;
  v27 = *(v1[4] + 16);
  *(v27 + 36) = 0;
  v28 = v1[5];
  v29 = *(*(v28 + 32) + 16LL);
  *(v29 + 32) = 0;
  v30 = v1[5];
  v31 = *(*(v30 + 32) + 16LL);
  *(v31 + 36) = 0;
  v33 = v1[5];
  v35 = *(*(v33 + 40) + 16LL);
  *(v35 + 32) = 512;
  v37 = v1[5];
  v39 = *(*(v37 + 40) + 16LL);
  *(v39 + 36) = 448;
  dds3EffectBlur(&pBlur, 0, 0);
}

// 0x14b8620
void pipeBulrSetLimit(s32 frame) {
  BulrLimitFrame = frame;
}

// 0x14b9ca0
void pipeEffCal(void) {
  pipeEffTask(&pipe_CELL01_D3P, 4u);
  pipeEffTask(&pipe_BREAK01_D3P, 4u);
  pipeEffTask(&pipe_BREAK02_D3P, 4u);
  pipeEffTask(&pipe_DAMAGE01_D3P, 2u);
  pipeEffTask(&pipe_DAMAGE03_D3P, 2u);
  pipeEffTask(&pipe_ATTACK01_D3P, 6u);
}

// 0x14b8c10
void pipeEffCreateLoadFile(PIPE_EFF_t ***pEffect, char *d3pName, char *tgaName, u8 maxSize) {
    LoadFileByte(0, 0, 0);
    LoadFileObject(0, 0, 0);
}

// 0x14b9760
void pipeEffDraw(void) {
  pipeEffDraw2Doffset(&pipe_CELL01_D3P, 0xAu);
  pipeEffDraw2Doffset(&pipe_BREAK01_D3P, 0xAu);
  pipeEffDraw2Doffset(&pipe_BREAK02_D3P, 0xAu);
  pipeEffDraw2Doffset(&pipe_DAMAGE01_D3P, 0xAu);
  pipeEffDraw2Doffset(&pipe_DAMAGE03_D3P, 0xAu);
  pipeEffDraw2Doffset(&pipe_ATTACK01_D3P, 5u);
}

// 0x14b9860
void pipeEffDraw2Doffset(PIPE_EFF_t ***pEffect, u8 maxSize) {
    dds3EffectGetState(0);
    getPosTranslate(0, 0);
    dds3EffectSetPosition(0, (sdfVector4_t){0});
    dds3EffectDraw(0);
    dds3EffectDelete(0);
}

// 0x14b9280
void pipeEffLoad(void) {
  pipeEffCreateLoadFile(&pipe_CELL01_D3P, StringLiteral_21886, StringLiteral_21887, 0xAu);
  pipeEffCreateLoadFile(&pipe_BREAK01_D3P, StringLiteral_21888, 0, 0xAu);
  pipeEffCreateLoadFile(&pipe_BREAK02_D3P, StringLiteral_21889, 0, 0xAu);
  pipeEffCreateLoadFile(&pipe_DAMAGE01_D3P, StringLiteral_21890, 0, 0xAu);
  pipeEffCreateLoadFile(&pipe_DAMAGE03_D3P, StringLiteral_21891, 0, 0xAu);
  pipeEffCreateLoadFile(&pipe_ATTACK01_D3P, StringLiteral_21892, 0, 5u);
}

// 0x14b9660
void pipeEffRelease(void) {
  pipeEffReleaseData(&pipe_CELL01_D3P, 0xAu);
  pipeEffReleaseData(&pipe_BREAK01_D3P, 0xAu);
  pipeEffReleaseData(&pipe_BREAK02_D3P, 0xAu);
  pipeEffReleaseData(&pipe_DAMAGE01_D3P, 0xAu);
  pipeEffReleaseData(&pipe_DAMAGE03_D3P, 0xAu);
  pipeEffReleaseData(&pipe_ATTACK01_D3P, 5u);
}

// 0x14b93e0
void pipeEffReleaseData(PIPE_EFF_t ***pEffect, u8 maxSize) {
  PIPE_EFF_t_array *v5;
  u32 v6;
  s64 v7;
  struct UnityEngine_Texture_array *tex;
  PIPE_EFF_t_array *v14;
  Il2CppObject *pData;

  pData = 0;
  v5 = *pEffect;
  if (maxSize != 1)
  {
    v6 = (maxSize - 1);
    do
    {
      v7 = v6;
      if (v5->m_Items[v6]->d3p)
      {
        pData = (*pEffect)->m_Items[v6]->d3p;
        dds3EffectDelete(&pData);
        (*pEffect)->m_Items[v7]->d3p = 0;
      }
      ++(*pEffect)->m_Items[v7]->count;
      v5 = *pEffect;
      v6 = (v7 - 1);
    }
    while (v7 != 1);
  }
  if (v5->m_Items[0]->mhFile)
  {
    (*pEffect)->m_Items[0]->mhFile = 0;
  }
  if ((*pEffect)->m_Items[0]->tex)
  {
    tex = (*pEffect)->m_Items[0]->tex;
    tex->m_Items[0] = 0;
    v14 = *pEffect;
    v14->m_Items[0]->tex = 0;
  }
}

// 0x14ba0a0
void pipeEffSet(tagPipeObject *objPtr, u8 effNum) {
    pipeEffSet2Doffset(0, 0, 0, 0, 0);
}

// 0x14ba3d0
void pipeEffSet2Doffset(s32 offset, f32 x, f32 y, PIPE_EFF_t ***pEffect, u8 maxSize) {
    billSetTexture(0);
    dds3EffectLoad(0, 0, 0);
}

// 0x14b9d90
void pipeEffTask(PIPE_EFF_t ***pEffect, u8 effNum) {
    objMyData();
}
