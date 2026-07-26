#include "types.h"

typedef struct effHandle_t effHandle_t;
typedef struct effPCPAgiraoFireParam_t effPCPAgiraoFireParam_t;
typedef struct effPCPAgiraoFire_tag effPCPAgiraoFire_tag;

struct effPCPAgiraoFire_tag {
    effPCPAgiraoFireParam_t *param;
    s32 frame;
    u32 abgr;
    effHandle_t *hD3P[3];
};

// 0x16c3df0
void Clear(effPCPAgiraoFire_tag *this) {
  u64 *v3;
  u32 *v4;
  s32 *hD3P;
  u64 v6;
  s64 *v8;
  s64 *v9;
  s32 *v11;

  v3 = NewSpecific(effHandle_t__, 3u);
  this->hD3P = v3;
  v4 = (v3 + 3);
  if (*(v3 + 6) >= 1)
  {
    hD3P = v3;
    v6 = 0;
    do
    {
      v8 = NewSpecific(effHandle_t, 7u);
      v9 = v8;
      v11 = &hD3P[2 * v6++];
      *(v11 + 4) = v9;
      hD3P = this->hD3P;
      v4 = (hD3P + 6);
    }
    while (v6 < hD3P[6]);
  }
}
