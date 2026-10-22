#pragma once
#include "types.h"

typedef enum {
    PHASE_INIT = 0,
    PHASE_OPEN = 1,
    PHASE_FILESIZE = 2,
    PHASE_READ = 3,
    PHASE_READING = 4,
    PHASE_CLOSE = 5,
    PHASE_DONE = 6,
    PHASE_WAIT_ALLOC = 7,
} FILE_LOAD;
