#include "types.h"

typedef struct effPCPAgiFireballParam_t effPCPAgiFireballParam_t;
typedef struct effPCPAgiFireball_tag effPCPAgiFireball_tag;
typedef struct effPartHandle_t effPartHandle_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct effPCPAgiFireball_tag {
    sdfMatrix4_t matrix;
    sdfVector4_t pos_old;
    sdfVector4_t pos;
    effPCPAgiFireballParam_t *param;
    s32 frame;
    s32 motion_f;
    u32 abgr;
    u32 type;
    effPartHandle_t *hHelper;
    effPartHandle_t *hAttach[5];
    effPartHandle_t *phTrack[3];
    effPartHandle_t *hStart[5];
    effPartHandle_t *hOkSmoke;
    sdfMemHandle_t *hTrackMem[3];
    effPCPAgiFireball_tag *pCopySrc;
};

// 0x16c3d00
void Clear(effPCPAgiFireball_tag *this) {
  u64 *v3;
  u64 *v4;

  v3 = Allocate(effPartHandle_t);
  effPartHandle_t___ctor(v3);
  this->hHelper = v3;
  this->hAttach = NewSpecific(effPartHandle_t, 5u);
  this->phTrack = NewSpecific(effPartHandle_t__, 3u);
  this->hStart = NewSpecific(effPartHandle_t, 5u);
  v4 = Allocate(effPartHandle_t);
  effPartHandle_t___ctor(v4);
  this->hOkSmoke = v4;
  this->hTrackMem = NewSpecific(sdfMemHandle_t, 3u);
}
