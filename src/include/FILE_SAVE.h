#pragma once
#include "types.h"

typedef enum {
    PHASE_INIT = 0,
    PHASE_OPEN = 1,
    PHASE_DUMMY = 2,
    PHASE_WRITE = 3,
    PHASE_WRITING = 4,
    PHASE_CLOSE = 5,
    PHASE_DONE = 6,
} FILE_SAVE;
