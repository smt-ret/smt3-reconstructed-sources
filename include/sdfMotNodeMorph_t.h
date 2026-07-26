#pragma once
#include "types.h"

typedef struct sdfModelMorph_t sdfModelMorph_t;
typedef struct sdfMotNodeMorph_t sdfMotNodeMorph_t;
typedef struct sdfMotionNode_t sdfMotionNode_t;

struct sdfMotNodeMorph_t {
    sdfMotionNode_t *nodeBase;
    sdfModelMorph_t *morphNode;
    sdfModelMorph_t *blendSrc;
};
