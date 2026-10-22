#pragma once
#include "types.h"

typedef struct fldProgramEveHit_tag fldProgramEveHit_tag;
typedef struct fldResHeadPos_t fldResHeadPos_t;
typedef struct fldResHead_t fldResHead_t;
typedef struct fldResPutEveBall_t fldResPutEveBall_t;
typedef struct fldResPut_t fldResPut_t;

struct fldProgramEveHit_tag {
    fldResPutEveBall_t *ball;
    fldResPut_t *put;
    fldResHeadPos_t *sisei;
    fldResHead_t *ResHead;
    fldResHead_t *ResHeadData;
};
