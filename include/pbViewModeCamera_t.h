#pragma once
#include "types.h"

typedef struct pbViewModeCamera_t pbViewModeCamera_t;

struct pbViewModeCamera_t {
    f32 ratio;
    sdfVector4_t eye;
    sdfVector4_t tgt;
};
