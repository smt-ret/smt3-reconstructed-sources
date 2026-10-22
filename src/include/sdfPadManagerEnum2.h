#pragma once
#include "types.h"

typedef enum {
    SDF_PADCTL_MODE_DEFAULT = 0,
    SDF_PADCTL_MODE_UNLOCK = 1,
    SDF_PADCTL_MODE_LOCK_DIGITAL = 2,
    SDF_PADCTL_MODE_LOCK_ANALOG = 3,
    SDF_PADCTL_MODE_LOCK_PRESS = 4,
} sdfPadManagerEnum2;
