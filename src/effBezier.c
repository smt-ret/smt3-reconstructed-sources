#include "types.h"

typedef struct effBezier_t effBezier;
typedef struct effBezier_t effBezier_t;

static f32 EFF_BEZ_DEFAULTSTEP;

void effBezCalc(effBezier *this, sdfVector4_t out, effBezier_t *pbezier, f32 weight, u32 segment);

// 0x1379620
void effBezCalc(effBezier *this, sdfVector4_t out, effBezier_t *pbezier, f32 weight, u32 segment) {
}

// 0x13793f0
effBezier_t *effBezInitialize(effBezier *this, sdfVector3_t ppoint, u32 numpoint) {
    return 0;
}

// 0x1379590
void effBezRelease(effBezier *this, effBezier_t *pbezier) {
  ;
}

// 0x1379f70
void effBezRewind(effBezier *this, effBezier_t *pbezier) {
  *&pbezier->segment = 0;
}

// 0x13795a0
s32 effBezRun(effBezier *this, sdfVector4_t out, effBezier_t *pbezier) {
  f32 weight;
  u32 segment;
  f32 v8;
  u32 v9;
  u32 v10;
  bool v11;
  s32 result;

  weight = pbezier->weight;
  segment = pbezier->segment;
  effBezCalc(this, out, pbezier, weight, segment);
  v8 = weight + pbezier->step;
  v9 = segment + 3;
  if (v8 <= 1.0)
    v9 = segment;
  v10 = pbezier->numpoint - 1;
  if (v8 > 1.0)
    v8 = v8 + -1.0;
  v11 = v9 >= v10;
  if (v9 >= v10)
    v9 = 0;
  pbezier->segment = v9;
  result = !v11;
  if (v11)
    v8 = 0.0;
  pbezier->weight = v8;
  return result;
}

// 0x1379f80
void effBezSetStep(effBezier *this, effBezier_t *pbezier, f32 step) {
  pbezier->step = step;
}
