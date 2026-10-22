#pragma once
#include "types.h"

typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfSortOtNode_tag sdfSortOtNode_tag;

struct sdfSortOtNode_tag {
    sdfSortOtNode_tag *child[2];
    sdfDrawTag_t *tag;
    s32 balance;
};
