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
        goto LABEL_34;
    }
LABEL_9:
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
    goto LABEL_9;
LABEL_34:
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
  u64 *v8;
  u64 *v9;
  PIPE_EFF_t_o *v11;
  PIPE_EFF_t_o *v13;
  PIPE_EFF_t_o *v17;
  AssetBundleCtrl_o *asset_bc;
  System_String_o *v19;
  PIPE_EFF_t_o *v21;
  struct UnityEngine_Texture_array *tex;
  AssetBundleCtrl_o *v25;
  System_String_o *v26;
  s64 *FileObject;
  s64 *v28;
  s64 v29;
  s64 typeHierarchyDepth;
  char *v31;
  s64 *v32;
  s64 v37;
  s64 v38;
  char *v39;
  s64 *v40;
  s64 v42;
  PIPE_EFF_t_o *v46;
  s32 v52;
  u64 v53[2];
  char *v54;
  s32 v55;

  v55 = maxSize;
  v8 = Allocate(PIPE_EFF_t);
  PIPE_EFF_t___ctor(v8);
  v9 = Allocate(PIPE_EFF_t);
  PIPE_EFF_t___ctor(v9);
  v11 = (*pEffect)->m_Items[0];
  v11->mhFile = 0;
  (*pEffect)->m_Items[0]->d3p = 0;
  v13 = (*pEffect)->m_Items[0];
  v13->z = 0.0;
  v13->y = 0.0;
  v13->x = 0.0;
  (*pEffect)->m_Items[0]->size = 0;
  (*pEffect)->m_Items[0]->ptr = 0;
  v17 = (*pEffect)->m_Items[0];
  asset_bc = get_asset_bc();
  v19 = Concat_5224608("dds3data", d3pName);
  v17->ptr = LoadFileByte(asset_bc, "pipe_common", v19);
  (*pEffect)->m_Items[0]->tex = 0;
  if (tgaName)
  {
    v21 = (*pEffect)->m_Items[0];
    v21->tex = NewSpecific(UnityEngine_Texture, 1u);
    tex = (*pEffect)->m_Items[0]->tex;
    v25 = get_asset_bc();
    v26 = Concat_5224608("dds3data", tgaName);
    FileObject = LoadFileObject(v25, "pipe_common", v26);
    v28 = FileObject;
    if (FileObject)
    {
      v29 = *FileObject;
      if (*(*FileObject + 288) < typeHierarchyDepth
        || *(*(v29 + 200) + 8 * typeHierarchyDepth - 8) != UnityEngine_Texture)
      {
        sub_8FC2C0(*(v29 + 64), UnityEngine_Texture, v53);
        if ((v53[0] & 1) != 0)
          v31 = v54;
        else
          v31 = v53 + 1;
        v32 = sub_8C4940(v31);
      }
      v37 = *v28;
      if (*(*v28 + 288) < v38 || *(*(v37 + 200) + 8 * v38 - 8) != UnityEngine_Texture)
      {
        sub_8FC2C0(*(v37 + 64), UnityEngine_Texture, v53);
        if ((v53[0] & 1) != 0)
          v39 = v54;
        else
          v39 = v53 + 1;
        v40 = sub_8C4940(v39);
      }
    }
    tex->m_Items[0] = v28;
  }
  if (v55 != 1)
  {
    v42 = (v55 - 1);
    do
    {
      (*pEffect)->m_Items[v42]->mhFile = 0;
      (*pEffect)->m_Items[v42]->d3p = 0;
      v46 = (*pEffect)->m_Items[v42];
      *(v9 + 52) = 0;
      v46->x = 0.0;
      (*pEffect)->m_Items[v42]->size = v11->size;
      (*pEffect)->m_Items[v42]->ptr = 0;
      sub_8518D0(&(*pEffect)->m_Items[v42]->pos2, 0, 0.0);
      sub_8518D0(&(*pEffect)->m_Items[v42]->pos2, 1, 0.0);
      (*pEffect)->m_Items[v42]->offset = 0;
      v52 = v42--;
    }
    while (v52 != 1);
  }
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
  tagPipeObject_o *v5;
  char v7;
  s64 v8;
  Il2CppObject **p_pData;
  u8 v12;
  u32 v13;
  s64 v14;
  effHandle_t_o *d3p;
  u16 State;
  PIPE_EFF_t_array *v20;
  u32 max_length;
  f32 v23;
  f32 v25;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  struct effHandle_t_o *v37;
  Il2CppObject *pData;
  UnityEngine_Vector4_o pos;
  UnityEngine_Vector4_o v40;

  *&pos.x = 0;
  *&pos.z = 0;
  v37 = 0;
  pData = 0;
  sub_854690(&pos.x, 0.0, 0.0, 0.0, 1.0);
  v5 = Allocate(tagPipeObject);
  tagPipeObject___ctor(v5);
  v7 = maxSize - 1;
  if (maxSize != 1)
  {
    v8 = (maxSize - 2);
    while (1)
    {
      v12 = v7 - 1;
      v13 = v12;
      v14 = v12;
      if (!(*pEffect)->m_Items[v12]->d3p)
        goto LABEL_51;
      d3p = (*pEffect)->m_Items[v12]->d3p;
      State = dds3EffectGetState(d3p);
      v20 = *pEffect;
      max_length = (*pEffect)->max_length;
      if (!State)
        break;
      v23 = sub_851730(&v20->m_Items[v14]->pos2, 0);
      sub_8518D0(&v5->pos, 0, v23);
      v25 = sub_851730(&(*pEffect)->m_Items[v14]->pos2, 1);
      sub_8518D0(&v5->pos, 1, v25);
      v5->offset = (*pEffect)->m_Items[v14]->offset;
      getPosTranslate(v5, &pos);
      x = pos.x;
      y = pos.y;
      pData = (*pEffect)->m_Items[v14]->d3p;
      z = pos.z;
      w = pos.w;
      v40.x = x;
      v40.y = y;
      v40.z = z;
      v40.w = w;
      dds3EffectSetPosition(&pData, v40);
      dds3EffectDraw(&pData);
      if (maxSize != 5)
        goto LABEL_51;
      if ((*pEffect)->m_Items[v14]->count < 1)
        goto LABEL_51;
      --(*pEffect)->m_Items[v14]->count;
      if (!(*pEffect)->m_Items[v14]->count)
      {
        p_pData = &pData;
LABEL_11:
        dds3EffectDelete(p_pData);
        (*pEffect)->m_Items[v14]->d3p = 0;
        v7 = v8--;
        if (v8 == -1)
          return;
      }
      else
      {
LABEL_51:
        v7 = v8--;
        if (v8 == -1)
          return;
      }
    }
    v37 = v20->m_Items[v14]->d3p;
    p_pData = &v37;
    goto LABEL_11;
  }
}

// 0x14b9280
void pipeEffLoad(void) {
  pipeEffCreateLoadFile(&pipe_CELL01_D3P, "/pipe/CEL01.D3P.bytes", "/pipe/CEL01.tga", 0xAu);
  pipeEffCreateLoadFile(&pipe_BREAK01_D3P, "/pipe/BRAKE01.D3P.bytes", 0, 0xAu);
  pipeEffCreateLoadFile(&pipe_BREAK02_D3P, "/pipe/BRAKE02.D3P.bytes", 0, 0xAu);
  pipeEffCreateLoadFile(&pipe_DAMAGE01_D3P, "/pipe/DAMAGE01.D3P.bytes", 0, 0xAu);
  pipeEffCreateLoadFile(&pipe_DAMAGE03_D3P, "/pipe/DAMAGE03.D3P.bytes", 0, 0xAu);
  pipeEffCreateLoadFile(&pipe_ATTACK01_D3P, "/pipe/FPS3.D3P.bytes", 0, 5u);
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
  s32 v5;
  struct UnityEngine_Vector2_o *v6;
  f32 v7;
  f32 v10;
  s32 v11;
  f32 v12;
  f32 v14;
  s32 v15;
  f32 v16;
  u8 v17;
  PIPE_EFF_t_array **p_pipe_ATTACK01_D3P;
  s32 offset;
  struct UnityEngine_Vector2_o *p_pos;
  f32 v21;
  f32 v23;
  s32 v24;
  struct UnityEngine_Vector2_o *v25;
  f32 v26;
  f32 v29;
  s32 v30;
  f32 v31;
  f32 v32;
  s32 v34;
  f32 v35;

  switch (effNum)
  {
    case 6u:
      offset = objPtr->offset;
      p_pos = &objPtr->pos;
      v21 = sub_851730(p_pos, 0);
      v23 = sub_851730(p_pos, 1);
      v16 = v21 + -16.0;
      v14 = v23 + -48.0;
      p_pipe_ATTACK01_D3P = &pipe_ATTACK01_D3P;
      v17 = 5;
      v15 = offset;
      break;
    case 4u:
      v24 = objPtr->offset;
      v25 = &objPtr->pos;
      v26 = sub_851730(&objPtr->pos, 0);
      v29 = sub_851730(&objPtr->pos, 1);
      pipeEffSet2Doffset(v24 + 5, v26, v29, &pipe_BREAK01_D3P, 0xAu);
      v30 = objPtr->offset;
      v31 = sub_851730(&objPtr->pos, 0);
      v32 = sub_851730(&objPtr->pos, 1);
      pipeEffSet2Doffset(v30 + 5, v31, v32, &pipe_BREAK02_D3P, 0xAu);
      v34 = objPtr->offset;
      v35 = sub_851730(v25, 0);
      v14 = sub_851730(v25, 1);
      v15 = v34 + 5;
      v16 = v35;
      v17 = 10;
      p_pipe_ATTACK01_D3P = &pipe_CELL01_D3P;
      break;
    case 2u:
      v5 = objPtr->offset;
      v6 = &objPtr->pos;
      v7 = sub_851730(&objPtr->pos, 0);
      v10 = sub_851730(&objPtr->pos, 1);
      pipeEffSet2Doffset(v5, v7, v10, &pipe_DAMAGE01_D3P, 0xAu);
      v11 = objPtr->offset;
      v12 = sub_851730(v6, 0);
      v14 = sub_851730(v6, 1);
      v15 = v11;
      v16 = v12;
      v17 = 10;
      p_pipe_ATTACK01_D3P = &pipe_DAMAGE03_D3P;
      break;
    default:
      return;
  }
  pipeEffSet2Doffset(v15, v16, v14, p_pipe_ATTACK01_D3P, v17);
}

// 0x14ba3d0
void pipeEffSet2Doffset(s32 offset, f32 x, f32 y, PIPE_EFF_t ***pEffect, u8 maxSize) {
  u8 v11;
  UnityEngine_Texture_array *tex;
  char v14;
  char v16;
  s64 v17;
  il2cpp_array_size_t max_length;
  PIPE_EFF_t_o *v20;
  Il2CppObject **p_ptr;
  PIPE_EFF_t_array *v27;

  v11 = maxSize;
  tex = (*pEffect)->m_Items[0]->tex;
  v14 = v11 - 1;
  billSetTexture(tex);
  while (1)
  {
    v16 = v14;
    if (!v14)
      break;
    --v14;
    v17 = (v16 - 1);
    if (!(*pEffect)->m_Items[v17]->d3p)
    {
      max_length = (*pEffect)->max_length;
      v20 = (*pEffect)->m_Items[v17];
      p_ptr = &(*pEffect)->m_Items[0]->ptr;
      v20->d3p = dds3EffectLoad(p_ptr, 0, 0, 0);
      sub_8518D0(&(*pEffect)->m_Items[v17]->pos2, 0, x);
      sub_8518D0(&(*pEffect)->m_Items[v17]->pos2, 1, y);
      (*pEffect)->m_Items[v17]->offset = offset;
      v27 = *pEffect;
      v27->m_Items[v17]->count = 14;
      return;
    }
  }
}

// 0x14b9d90
void pipeEffTask(PIPE_EFF_t ***pEffect, u8 effNum) {
  u64 *v5;
  s64 k;
  s64 i;
  s64 v14;
  struct UnityEngine_Vector2_o *p_pos;
  s64 j;
  u32 v18;
  s64 v22;
  s64 v24;
  f32 v25;
  s64 v27;
  f32 v28;

  v5 = Allocate(tagPipeObject);
  tagPipeObject___ctor(v5);
  switch (effNum)
  {
    case 2u:
      for (i = 13; i != 3; --i)
      {
        if (*(*(&(*pEffect)->obj.klass + i) + 40LL))
        {
          v14 = *(&(*pEffect)->obj.klass + i);
          *(v14 + 68) = offsetCount;
        }
      }
      break;
    case 6u:
      p_pos = &objMyData()->pos;
      for (j = 8; j != 3; --j)
      {
        v18 = j - 4;
        if (*(*(&(*pEffect)->obj.klass + j) + 40LL))
        {
          v22 = *(&(*pEffect)->obj.klass + j);
          *(v22 + 68) = offsetCount + 4;
          v24 = *(&(*pEffect)->obj.klass + j) + 60LL;
          v25 = sub_851730(p_pos, 0);
          sub_8518D0(v24, 0, v25 + -16.0);
          v27 = *(&(*pEffect)->obj.klass + j) + 60LL;
          v28 = sub_851730(p_pos, 1);
          sub_8518D0(v27, 1, v28 + -48.0);
        }
      }
      break;
    case 4u:
      for (k = 13; k != 3; --k)
      {
        if (*(*(&(*pEffect)->obj.klass + k) + 40LL))
        {
          *(*(&(*pEffect)->obj.klass + k) + 68LL) += 6;
        }
      }
      break;
  }
}
