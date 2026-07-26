#include "types.h"

typedef struct dds3LightEditorWork_t dds3LightEditorWork_t;
typedef struct dds3ModelBlurCb_t dds3ModelBlurCb_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct mdlSetDef_t mdlSetDef_t;
typedef struct pibChunkItem_BLUR_t pibChunkItem_BLUR_t;
typedef struct pibChunkItem_IPU_t pibChunkItem_IPU_t;
typedef struct pibChunkItem_P2A_D3P_t pibChunkItem_P2A_D3P_t;
typedef struct pibChunkItem_TRACK_t pibChunkItem_TRACK_t;
typedef struct pibChunkItem_t pibChunkItem_t;
typedef struct pibChunk_t pibChunk_t;
typedef struct pibHeaderChunk_t pibHeaderChunk_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;

f32 Byte2Float(u8 **data, s32 pos);
u16 Byte2UInt16(u8 **bytedata, s32 pos);
u32 Byte2UInt32(u8 **bytedata, s32 pos);
void sdfModelRootNode_t__dCopy(sdfModelRootNode_t *this, sdfModelRootNode_t **dst);

// 0x19bfb40
void dds3LightEditorWork_t__Clear(dds3LightEditorWork_t *this) {
}

// 0x19ada90
void dds3ModelBlurCb_t__Clear(dds3ModelBlurCb_t *this) {
}

// 0x19bfbc0
void dds3ModelBlurCb_t__dCopy(dds3ModelBlurCb_t *this, dds3ModelBlurCb_t **dst) {
  dds3ModelBlurCb_t_o *v3;
  f32 z;
  f32 w;
  dds3ModelBlurCb_t_o *v6;
  f32 v7;
  f32 v8;

  (*dst)->instants = 0;
  (*dst)->spawnCount = this->spawnCount;
  (*dst)->count = this->count;
  (*dst)->interval = this->interval;
  (*dst)->intervalCount = this->intervalCount;
  (*dst)->keepCount = this->keepCount;
  v3 = *dst;
  z = this->colorBase.z;
  w = this->colorBase.w;
  *&v3->colorBase.x = *&this->colorBase.x;
  v3->colorBase.z = z;
  v3->colorBase.w = w;
  v6 = *dst;
  v7 = this->colorDelta.z;
  v8 = this->colorDelta.w;
  *&v6->colorDelta.x = *&this->colorDelta.x;
  v6->colorDelta.z = v7;
  v6->colorDelta.w = v8;
}

// 0x19bfc70
void dds3ModelHandle_t__dCopy(dds3ModelHandle_t *this, dds3ModelHandle_t **dst) {
  dds3ModelHandle_t_o *v5;
  u64 *v6;
  dds3ModelHandle_t_o *v7;
  f32 z;
  f32 w;
  dds3ModelHandle_t_o *v10;
  u64 *v11;
  dds3ModelHandle_t_o *v12;
  struct dds3ModelBlurCb_t_o *blur;
  struct dds3ModelBlurCb_t_o *v14;
  f32 v15;
  f32 v16;
  struct dds3ModelBlurCb_t_o *v17;
  s64 v18;
  f32 v19;

  (*dst)->stat = this->stat;
  (*dst)->next = this->next;
  (*dst)->prev = this->prev;
  (*dst)->resrc = this->resrc;
  (*dst)->motionMajorNum = this->motionMajorNum;
  (*dst)->motionMinorNum = this->motionMinorNum;
  (*dst)->effects = this->effects;
  v5 = *dst;
  v6 = Allocate(sdfModelRootNode_t);
  sdfModelRootNode_t___ctor(v6);
  v5->modelRoot = v6;
  sdfModelRootNode_t__dCopy(this->modelRoot, &(*dst)->modelRoot, 0);
  (*dst)->motionCtrlr = this->motionCtrlr;
  (*dst)->motions = this->motions;
  (*dst)->blur = 0;
  (*dst)->Owner = this->Owner;
  (*dst)->radius = this->radius;
  (*dst)->uLight = this->uLight;
  v7 = *dst;
  z = this->uAmbient.z;
  w = this->uAmbient.w;
  *&v7->uAmbient.x = *&this->uAmbient.x;
  v7->uAmbient.z = z;
  v7->uAmbient.w = w;
  if (this->blur)
  {
    v10 = *dst;
    v11 = Allocate(dds3ModelBlurCb_t);
    _ctor(v11, 0);
    v10->blur = v11;
    v12 = *dst;
    blur = this->blur;
    (*dst)->blur->instants = 0;
    v12->blur->spawnCount = blur->spawnCount;
    v12->blur->count = blur->count;
    v12->blur->interval = blur->interval;
    v12->blur->intervalCount = blur->intervalCount;
    v12->blur->keepCount = blur->keepCount;
    v14 = v12->blur;
    v15 = blur->colorBase.z;
    v16 = blur->colorBase.w;
    *&v14->colorBase.x = *&blur->colorBase.x;
    v14->colorBase.z = v15;
    v14->colorBase.w = v16;
    v17 = v12->blur;
    v18 = *&blur->colorDelta.x;
    v19 = blur->colorDelta.z;
    *&blur = blur->colorDelta.w;
    *&v17->colorDelta.x = v18;
    v17->colorDelta.z = v19;
    LODWORD(v17->colorDelta.w) = blur;
  }
}

// 0x19bfe60
void mdlSetDef_t__Clear(mdlSetDef_t *this) {
  ;
}

// 0x19bff60
s32 pibChunkItem_BLUR_t__GetSize(pibChunkItem_BLUR_t *this) {
  return 20;
}

// 0x19bfe70
void pibChunkItem_BLUR_t__pCopy(pibChunkItem_BLUR_t *this, u8 **bytedata, s32 pos) {
  this->type = Byte2UInt32(bytedata, pos);
  this->size = Byte2UInt32(bytedata, pos + 4);
  this->interval = Byte2UInt16(bytedata, pos + 8);
  this->count = Byte2UInt16(bytedata, pos + 10);
  this->startColor = Byte2UInt32(bytedata, pos + 12);
  this->endColor = Byte2UInt32(bytedata, pos + 16);
}

// 0x19c00c0
s32 pibChunkItem_IPU_t__GetSize(pibChunkItem_IPU_t *this) {
  return 20;
}

// 0x19bff80
void pibChunkItem_IPU_t__pCopy(pibChunkItem_IPU_t *this, u8 **bytedata, s32 pos) {
  s64 v7;
  s64 v9;

  this->type = Byte2UInt32(bytedata, pos);
  this->size = Byte2UInt32(bytedata, pos + 4);
  this->texId = Byte2UInt32(bytedata, pos + 8);
  this->startFrame = Byte2UInt32(bytedata, pos + 12);
  v7 = pos + 16LL;
  this->fps = bytedata->m_Items[v7];
  v9 = pos + 17LL;
  this->loop = bytedata->m_Items[v9];
  this->effectIndex = Byte2UInt16(bytedata, pos + 18);
}

// 0x19c01d0
s32 pibChunkItem_P2A_D3P_t__GetSize(pibChunkItem_P2A_D3P_t *this) {
  return 20;
}

// 0x19c00e0
void pibChunkItem_P2A_D3P_t__pCopy(pibChunkItem_P2A_D3P_t *this, u8 **bytedata, s32 pos) {
  this->type = Byte2UInt32(bytedata, pos);
  this->size = Byte2UInt32(bytedata, pos + 4);
  this->markId = Byte2UInt32(bytedata, pos + 8);
  this->count = Byte2UInt16(bytedata, pos + 12);
  this->effectIndex = Byte2UInt16(bytedata, pos + 14);
  this->zOffset = Byte2Float(bytedata, pos + 16);
}

// 0x19c04a0
s32 pibChunkItem_TRACK_t__GetSize(pibChunkItem_TRACK_t *this) {
  return 40;
}

// 0x19c01f0
void pibChunkItem_TRACK_t__pCopy(pibChunkItem_TRACK_t *this, u8 **bytedata, s32 pos) {
  struct System_UInt32_array *v7;
  u32 v8;
  struct System_UInt32_array *mark;
  u32 v11;
  s64 v13;
  s64 v15;
  struct System_UInt32_array *v17;
  u32 v18;
  struct System_UInt32_array *colors;
  u32 v21;
  struct System_UInt32_array *v23;
  u32 v24;
  s32 v26;
  struct System_UInt32_array *v27;
  u32 v28;

  this->type = Byte2UInt32(bytedata, pos);
  this->size = Byte2UInt32(bytedata, pos + 4);
  v7 = NewSpecific(uint, 2u);
  this->mark = v7;
  v8 = Byte2UInt32(bytedata, pos + 8);
  v7->m_Items[0] = v8;
  mark = this->mark;
  v11 = Byte2UInt32(bytedata, pos + 12);
  mark->m_Items[1] = v11;
  this->startFrame = Byte2UInt16(bytedata, pos + 16);
  this->endFrame = Byte2UInt16(bytedata, pos + 18);
  this->interval = Byte2UInt16(bytedata, pos + 20);
  v13 = pos + 22LL;
  this->face = bytedata->m_Items[v13];
  v15 = pos + 23LL;
  this->blendAlgo = bytedata->m_Items[v15];
  v17 = NewSpecific(uint, 4u);
  this->colors = v17;
  v18 = Byte2UInt32(bytedata, pos + 24);
  v17->m_Items[0] = v18;
  colors = this->colors;
  v21 = Byte2UInt32(bytedata, pos + 28);
  colors->m_Items[1] = v21;
  v23 = this->colors;
  v24 = Byte2UInt32(bytedata, pos + 32);
  v23->m_Items[2] = v24;
  v26 = pos + 36;
  v27 = this->colors;
  v28 = Byte2UInt32(bytedata, v26);
  v27->m_Items[3] = v28;
}

// 0x19c0560
s32 pibChunkItem_t__GetSize(pibChunkItem_t *this) {
  return 8;
}

// 0x19c04c0
void pibChunkItem_t__pCopy(pibChunkItem_t *this, u8 **bytedata, s32 pos) {
  this->type = Byte2UInt32(bytedata, pos);
  this->size = Byte2UInt32(bytedata, pos + 4);
}

// 0x19c0620
s32 pibChunk_t__GetSize(pibChunk_t *this) {
  return 8;
}

// 0x19c0580
void pibChunk_t__pCopy(pibChunk_t *this, u8 **bytedata, s32 pos) {
  this->group = Byte2UInt32(bytedata, pos);
  this->size = Byte2UInt32(bytedata, pos + 4);
}

// 0x19c0740
s32 pibHeaderChunk_t__GetSize(pibHeaderChunk_t *this) {
  return 20;
}

// 0x19c0640
void pibHeaderChunk_t__pCopy(pibHeaderChunk_t *this, u8 **bytedata, s32 pos) {
  this->group = Byte2UInt32(bytedata, pos);
  this->size = Byte2UInt32(bytedata, pos + 4);
  this->version = Byte2UInt32(bytedata, pos + 8);
  this->chunkCount = Byte2UInt32(bytedata, pos + 12);
  this->effectCount = Byte2UInt16(bytedata, pos + 14);
  this->motionCount = Byte2UInt16(bytedata, pos + 16);
  this->pad = Byte2UInt16(bytedata, pos + 18);
}
