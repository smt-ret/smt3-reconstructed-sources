#include "types.h"

typedef struct effPCPHamaCardSpiralPart_tag effPCPHamaCardSpiralPart_tag;

struct effPCPHamaCardSpiralPart_tag {
    s32 frame;
    f32 radius_s;
    f32 roll_s;
    f32 up_s;
    f32 radius;
    f32 radian;
    f32 height;
};

// 0x11579d0
void pClone(effPCPHamaCardSpiralPart_tag *this, effPCPHamaCardSpiralPart_tag **dst) {
  ;
}
