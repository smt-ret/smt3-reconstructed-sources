#include "types.h"

typedef struct dds3DrawEnv_t dds3DrawEnv_t;

// 0x15a8380
void dds3DrawEnv_t__Clear(dds3DrawEnv_t *this) {
  Il2CppObject *v3;
  u64 *v4;
  struct sdfModelDrawEnv_t_array *v5;
  u32 *ModelDrawEnv;
  u64 i;
  Il2CppObject *v8;
  u64 *v9;
  Il2CppObject *v13;
  u64 *v14;
  u64 *v15;
  u64 *v17;
  Il2CppObject *v19;
  u64 *v20;
  Il2CppObject *v21;
  u64 *v22;
  u64 *v24;
  Il2CppObject *v26;
  u64 *v27;
  Il2CppObject *v28;
  u64 *v29;
  Il2CppObject *v31;
  u64 *v32;

  v3 = Allocate(sdfDrawTag_t);
  v3[4].klass = NewSpecific(object, 2u);
  _ctor(v3, 0);
  this->SysDrawTag = v3;
  v4 = Allocate(sdf3DInitPacket_t);
  _ctor(v4, 0);
  this->TdPacket = v4;
  v5 = NewSpecific(sdfModelDrawEnv_t, 0xBu);
  this->ModelDrawEnv = v5;
  ModelDrawEnv = v5;
  for (i = 0; ; ++i)
  {
    v8 = Allocate(sdfModelDrawEnv_t);
    v8[1].klass = NewSpecific(sdfModelDrawEnv_t_AnonymousClass, 4u);
    v9 = Allocate(sdfModelDrawEnv_t_AnonymousClass2);
    sdfModelDrawEnv_t_AnonymousClass2___ctor(v9);
    v8[1].monitor = v9;
    _ctor(v8, 0);
    *&ModelDrawEnv[2 * i + 8] = v8;
    if (i == 10)
      break;
    ModelDrawEnv = this->ModelDrawEnv;
  }
  v13 = Allocate(sdfDrawTag_t);
  v13[4].klass = NewSpecific(object, 2u);
  _ctor(v13, 0);
  this->DrawTag = v13;
  v14 = Allocate(sdfPreDrawTag_t);
  _ctor(v14, 0);
  this->PreDrawTag = v14;
  v15 = Allocate(sdfGrStdDrawEnv_t);
  sdfGrStdDrawEnv_t___ctor(v15);
  this->DrawEnv = v15;
  v17 = Allocate(sdf3DViewportPacket_t);
  sdf3DViewportPacket_t___ctor(v17);
  this->ViewportPacket = v17;
  v19 = Allocate(sdf3DLightParallelPacket_t);
  v20 = Allocate(sdfDmaTag_t);
  _ctor(v20, 0);
  v19[1].klass = v20;
  v19[1].monitor = NewSpecific(UnityEngine_Vector4, 3u);
  v19[3].klass = NewSpecific(UnityEngine_Vector4, 5u);
  _ctor(v19, 0);
  this->DirLightPacket = v19;
  v21 = Allocate(sdfDrawTag_t);
  v21[4].klass = NewSpecific(object, 2u);
  _ctor(v21, 0);
  this->RenderDrawTag = v21;
  v22 = Allocate(sdfGrDrawEnv_t);
  sdfGrDrawEnv_t___ctor(v22);
  this->RenderDrawEnv = v22;
  v24 = Allocate(sdf3DViewportPacket_t);
  sdf3DViewportPacket_t___ctor(v24);
  this->RenderViewportPacket = v24;
  v26 = Allocate(sdf3DLightParallelPacket_t);
  v27 = Allocate(sdfDmaTag_t);
  _ctor(v27, 0);
  v26[1].klass = v27;
  v26[1].monitor = NewSpecific(UnityEngine_Vector4, 3u);
  v26[3].klass = NewSpecific(UnityEngine_Vector4, 5u);
  _ctor(v26, 0);
  this->RenderDirLightPacket = v26;
  v28 = Allocate(sdfDrawTag_t);
  v28[4].klass = NewSpecific(object, 2u);
  _ctor(v28, 0);
  this->HighDrawTag = v28;
  v29 = Allocate(sdf3DViewportPacket_t);
  sdf3DViewportPacket_t___ctor(v29);
  this->HighViewportPacket = v29;
  v31 = Allocate(sdf3DLightParallelPacket_t);
  v32 = Allocate(sdfDmaTag_t);
  _ctor(v32, 0);
  v31[1].klass = v32;
  v31[1].monitor = NewSpecific(UnityEngine_Vector4, 3u);
  v31[3].klass = NewSpecific(UnityEngine_Vector4, 5u);
  _ctor(v31, 0);
  this->HighDirLightPacket = v31;
}
