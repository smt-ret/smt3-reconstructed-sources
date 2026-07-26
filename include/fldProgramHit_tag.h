#pragma once
#include "types.h"

typedef struct fldProgramHit_tag fldProgramHit_tag;
typedef struct fldResCollisionPolyFace_t fldResCollisionPolyFace_t;
typedef struct fldResCollisionPoly_t fldResCollisionPoly_t;

struct fldProgramHit_tag {
    sdfVector4_t Vertex[8];
    fldResCollisionPolyFace_t *Face[4];
    fldResCollisionPoly_t *DataPoly;
};
