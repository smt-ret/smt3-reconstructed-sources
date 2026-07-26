#include "types.h"

typedef struct dds3Effect_Blur_t dds3Effect_Blur_t;
typedef struct dds3Effect_RipBlurPart_tag dds3Effect_RipBlurPart_tag;

struct dds3Effect_RipBlurPart_tag {
    f32 scale;
    f32 radiun;
    dds3Effect_Blur_t *Blur;
};

void dds3Effect_Blur_t__Clear(dds3Effect_Blur_t *this);

// 0x17b3590
void Clear(dds3Effect_RipBlurPart_tag *this) {
  u64 *v3;

  v3 = Allocate(dds3Effect_Blur_t);
  dds3Effect_Blur_t___ctor(v3);
  this->Blur = v3;
  dds3Effect_Blur_t__Clear(v3);
}
