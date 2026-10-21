#pragma once
#include "types.h"

typedef struct sdfModelNode_t sdfModelNode_t;
typedef struct sdfMotNodeModelBase_t sdfMotNodeModelBase_t;
typedef struct sdfMotionNode_t sdfMotionNode_t;

struct sdfMotNodeModelBase_t {
    sdfMotionNode_t nodeBase;
    sdfModelNode_t *modelNode;
};
