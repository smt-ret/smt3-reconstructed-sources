#include "types.h"

typedef struct effPCPMudo_tag effPCPMudo_tag;
typedef struct effPartHandle_t effPartHandle_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct effPCPMudo_tag {
    sdfVector4_t *P2APos[25];
    sdfVector4_t pos;
    u32 *P2AFrame[25];
    f32 *P2AScale[25];
    u32 *P2AScaleF[25];
    u32 abgr;
    f32 scale;
    u32 frame;
    u32 fade_frame;
    u32 fade_abgr;
    effPartHandle_t *hHelperPB;
    effPartHandle_t *hP2A;
    sdfMemHandle_t *hMem;
};

// 0x1758ab0
void Clear(effPCPMudo_tag *this) {
  s64 i;
  u32 *P2APos;
  u64 v9;
  s64 *v10;
  s64 *v11;
  u32 *P2AFrame;
  s64 *v14;
  s64 *v15;
  u32 *P2AScale;
  s64 *v18;
  s64 *v19;
  u32 *P2AScaleF;
  s64 *v22;
  s64 *v23;

  *&this->pos.x = 0;
  *&this->pos.z = 0;
  this->P2APos = NewSpecific(UnityEngine_Vector4__, 0x19u);
  this->P2AFrame = NewSpecific(uint__, 0x19u);
  this->P2AScale = NewSpecific(float__, 0x19u);
  this->P2AScaleF = NewSpecific(uint__, 0x19u);
  for (i = 4; i != 29; ++i)
  {
    P2APos = this->P2APos;
    v9 = i - 4;
    v10 = NewSpecific(UnityEngine_Vector4, 7u);
    v11 = v10;
    *&P2APos[2 * i] = v11;
    P2AFrame = this->P2AFrame;
    v14 = NewSpecific(uint, 7u);
    v15 = v14;
    *&P2AFrame[2 * i] = v15;
    P2AScale = this->P2AScale;
    v18 = NewSpecific(f32, 7u);
    v19 = v18;
    *&P2AScale[2 * i] = v19;
    P2AScaleF = this->P2AScaleF;
    v22 = NewSpecific(uint, 7u);
    v23 = v22;
    *&P2AScaleF[2 * i] = v23;
  }
}
