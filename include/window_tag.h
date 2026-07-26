#pragma once
#include "types.h"

typedef struct itfpanel_t itfpanel_t;
typedef struct sdfIVector4_t sdfIVector4_t;
typedef struct window_tag window_tag;

struct window_tag {
    itfpanel_t *spk;
    itfpanel_t *mes;
    sdfIVector4_t *mes_offset;
    sdfIVector4_t *mes_color;
};
