#pragma once
#include "types.h"

typedef enum {
    SDF_PADCTL_STAT_WAIT_CONNECT = 0,
    SDF_PADCTL_STAT_SET_MAIN_MODE = 1,
    SDF_PADCTL_STAT_SET_PRESS_MODE = 2,
    SDF_PADCTL_STAT_ACT_INIT = 3,
    SDF_PADCTL_STAT_ACT_WAIT = 4,
    SDF_PADCTL_STAT_NORMAL = 5,
} sdfPadManagerEnum;
