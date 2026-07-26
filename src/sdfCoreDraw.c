#include "types.h"

typedef struct sdf3DFogPacket_t sdf3DFogPacket_t;
typedef struct sdf3DLightParallelPacket_t sdf3DLightParallelPacket_t;
typedef struct sdfCorePacketFaceDivParm_t sdfCorePacketFaceDivParm_t;
typedef struct sdfCorePacketPointBuff_tag sdfCorePacketPointBuff_tag;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfModelNode_t sdfModelNode_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;

static sdfCorePacketFaceDivParm_t *corePktFaceDivParm;
static sdfCorePacketPointBuff_tag *corePktPointBuff;
static sdfMemHandle_t *sdfCoreDrawBuffHandle;
static sdfCorePacketPointBuff_tag *corePktFaceList[2];
static u16 corePktBackFaceList[4096];
static u16 corePktPrimBase;
static sdfVector4_t corePktFogParm;
static sdf3DLightParallelPacket_t *corePktCurrLight;
static sdf3DFogPacket_t *corePktCurrFog;
static f32 corePktZBias;
static sdfVector4_t corePktWorldLightMtxCache[3];

// 0x17e4590
void sdfCoreDrawInit(s32 buffSize) {
  ;
}

// 0x17e4520
void sdfCoreDrawReset(void) {
  corePktCurrLight = 0;
  corePktCurrFog = 0;
}

// 0x17e43c0
void sdfCoreDrawScanOneSkinNodes(sdfModelRootNode_t *root, void *p) {
  ;
}

// 0x17e4470
void sdfCoreDrawSetFog(sdf3DFogPacket_t *fog) {
  sdfCoreDraw_c *v3;
  struct sdfCoreDraw_StaticFields *static_fields;

  static_fields = v3->static_fields;
  if (static_fields->corePktCurrFog != fog)
  {
    static_fields->corePktCurrFog = fog;
  }
}

// 0x17e43d0
void sdfCoreDrawSetLight(sdf3DLightParallelPacket_t *light) {
  sdfCoreDraw_c *v3;
  struct sdfCoreDraw_StaticFields *static_fields;

  static_fields = v3->static_fields;
  if (static_fields->corePktCurrLight != light)
  {
    static_fields->corePktCurrLight = light;
  }
}

// 0x17e4510
void sdfCoreDrawSetZBias(f32 z) {
  ;
}

// 0x17e4270
void *sdfCorePacketGen(sdfModelNode_t *node, void *packet_p, u32 attr_mask, u32 color, f32 fdSoften, f32 fdBias, s32 frame_id, s32 reverse) {
  Il2CppObject *v9;
  u64 *v10;

  v9 = Allocate(sdfCorePacketCb_t);
  v10 = Allocate(sdfMatrix4_t);
  sdfMatrix4_t___ctor(v10);
  v9[1].klass = v10;
  _ctor(v9, 0);
    return 0;
  return 0;
}
