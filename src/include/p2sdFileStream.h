#pragma once
#include "types.h"

typedef struct p2sdFileStream p2sdFileStream;

struct p2sdFileStream {
    char *fname;
    s32 length;
    s32 mode;
    u8 mempointer;
};
