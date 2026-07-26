#include "types.h"

typedef struct XRD773Unity_CommonMesh XRD773Unity_CommonMesh;
typedef struct dds3ScatterPolyListTexResource_tag dds3ScatterPolyListTexResource_tag;
typedef struct dds3ScatterPolyList_tag dds3ScatterPolyList_tag;
typedef struct sdfMat_t sdfMat_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct dds3ScatterPolyList_tag {
    sdfVector4_t pos;
    u32 blend;
    u32 abgr;
    s32 point;
    f32 scale;
    sdfVector4_t pVertex[UNKNOWN_ARRAY_SIZE];
    u32 pVC[UNKNOWN_ARRAY_SIZE];
    sdfMat_t *pMat;
    sdfMemHandle_t *hMem;
    dds3ScatterPolyListTexResource_tag *hTexRes;
    u32 number;
    void *pTexture;
    XRD773Unity_CommonMesh pMesh[UNKNOWN_ARRAY_SIZE];
};

// 0x14f77f0
void pClone(dds3ScatterPolyList_tag *this, dds3ScatterPolyList_tag **dst) {
  dds3ScatterPolyList_tag_o *v5;
  f32 z;
  f32 w;
  dds3ScatterPolyList_tag_o *v8;
  struct UnityEngine_Vector4_array *pVertex;
  f32 *max_length;
  dds3ScatterPolyList_tag_o *v11;
  s64 v12;
  u64 v13;
  struct UnityEngine_Vector4_array *v14;
  u32 *v16;
  f32 x;
  s32 v18;
  s32 v19;
  s32 v20;
  struct System_UInt32_array *pVC;
  il2cpp_array_size_t v23;
  dds3ScatterPolyList_tag_o *v24;
  s64 v25;
  struct System_UInt32_array *v26;
  s32 v28;
  s64 v30;

  v5 = *dst;
  z = this->pos.z;
  w = this->pos.w;
  *&v5->pos.x = *&this->pos.x;
  v5->pos.z = z;
  v5->pos.w = w;
  (*dst)->blend = this->blend;
  (*dst)->abgr = this->abgr;
  (*dst)->point = this->point;
  (*dst)->scale = this->scale;
  v8 = *dst;
  v8->pVertex = NewSpecific(UnityEngine_Vector4, LODWORD(this->pVertex->max_length));
  pVertex = this->pVertex;
  max_length = pVertex->max_length;
  v11 = *dst;
  if (max_length >= 1)
  {
    v12 = 0;
    v13 = 0;
    do
    {
      v14 = v11->pVertex;
      v16 = (pVertex + v12 * 16);
      x = pVertex->m_Items[v12].x;
      v18 = v16[9];
      v19 = v16[10];
      v20 = v16[11];
      max_length = (v14 + v12 * 16);
      ++v12;
      max_length[8] = x;
      *(max_length + 9) = v18;
      *(max_length + 10) = v19;
      *(max_length + 11) = v20;
      pVertex = this->pVertex;
      LODWORD(max_length) = pVertex->max_length;
      v11 = *dst;
      ++v13;
    }
    while (v13 < max_length);
  }
  v11->pVC = NewSpecific(uint, LODWORD(this->pVC->max_length));
  pVC = this->pVC;
  v23 = pVC->max_length;
  v24 = *dst;
  if (v23 >= 1)
  {
    v25 = 8;
    do
    {
      v26 = v24->pVC;
      v28 = *(&pVC->obj.klass + v25);
      *(&v26->obj.klass + v25) = v28;
      pVC = this->pVC;
      LODWORD(v23) = pVC->max_length;
      v24 = *dst;
      v30 = v25 - 7;
      ++v25;
    }
    while (v30 < v23);
  }
  v24->pMat = this->pMat;
  (*dst)->hMem = this->hMem;
  (*dst)->hTexRes = this->hTexRes;
  (*dst)->number = this->number;
  (*dst)->pTexture = this->pTexture;
  (*dst)->pMesh = 0;
}
