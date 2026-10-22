#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3KernelProcess_sdfGr dds3KernelProcess_sdfGr;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct sdf3DLightParallelPacket_t sdf3DLightParallelPacket_t;
typedef struct sdf3DLight_t sdf3DLight_t;
typedef struct sdf3DScreenParam_t sdf3DScreenParam_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfGrPacketHeader_t sdfGrPacketHeader_t;
typedef struct sdfGrTagStdReg_t sdfGrTagStdReg_t;

struct dds3KernelProcess_sdfGr {
    sdfGrPacketHeader_t *header;
    sdfGrTagStdReg_t *texa;
    sdfGrTagStdReg_t *texflush;
};

static sdfDrawTag_t *dds3FrameDrawTag;

void ClrDrawFlag(u32 flag);
void dds3BlurUpdate(void);
s32 dds3CallDrawProcuder(dds3Basic_t **basic);
s32 dds3CallMainProcuder(dds3Basic_t **basic);
void dds3DrawFade(void);
void dds3FadeUpdate(void);
void dds3InitDrawEnvSub(s32 i);
void dds3RunQuake(void);
void dds3SceneLightUpdateFirst(void);
void sdf3DMakeLightParallelPacket(sdf3DLightParallelPacket_t *aPacket, sdf3DLight_t **aLights, sdfVector4_t aAmbient);
void sdf3DMakeScreenParam(sdf3DScreenParam_t **aParam);
void sdf3DSetDefaultLight(sdf3DLightParallelPacket_t *aLight);

// 0x14e5020
dds3ProcessFunc_t *dds3BasicDrawProcess(dds3ProcessID_t *id) {
  dds3CallDrawProcuder(&dds3TheWorld);
  return 0;
}

// 0x14e4f90
dds3ProcessFunc_t *dds3BasicMainProcess(dds3ProcessID_t *id) {
  dds3CallMainProcuder(&dds3TheWorld);
  return 0;
}

// 0x14e4d20
dds3ProcessFunc_t *dds3DrawFirstProcess(dds3ProcessID_t *id) {
  s64 dds3FrameID;
  struct dds3DrawEnv_t_array *dds3DrawEnv;
  sdf3DLight_t_array *dds3DirLights;
  f32 x;
  f32 y;
  sdf3DLightParallelPacket_t_o *DirLightPacket;
  f32 w;
  f32 z;
  struct dds3DrawEnv_t_array *v14;
  UnityEngine_Vector4_o v17;

LABEL_7:
  dds3RunQuake();
  dds3SceneLightUpdateFirst();
  x = dds3Ambient.x;
  y = dds3Ambient.y;
  DirLightPacket = dds3DrawEnv->m_Items[dds3FrameID]->DirLightPacket;
  z = dds3Ambient.z;
  w = dds3Ambient.w;
  v17.x = x;
  v17.y = y;
  v17.z = z;
  v17.w = w;
  sdf3DMakeLightParallelPacket(DirLightPacket, dds3DirLights, v17);
  sdf3DMakeScreenParam(&dds3ScreenParam);
  v14 = dds3DrawEnv;
  sdf3DSetDefaultLight(v14->m_Items[dds3FrameID]->DirLightPacket);
  return 0;
}

// 0x14e4f00
dds3ProcessFunc_t *dds3DrawProcess(dds3ProcessID_t *id) {
  dds3FadeUpdate();
  dds3DrawFade();
  ClrDrawFlag(0x80000000);
  dds3BlurUpdate();
  return 0;
}

// 0x14e4c30
void *dds3FirstProcess(dds3ProcessID_t *id) {
  s32 dds3FrameID;

LABEL_7:
  dds3InitDrawEnvSub(dds3FrameID);
  return 0;
}
