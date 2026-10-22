#pragma once
#include "types.h"

typedef struct effPCPHelperBED_tag effPCPHelperBED_tag;
typedef struct effPCP_HBED2_Param_t effPCP_HBED2_Param_t;
typedef struct effPCP_HBED2_tag effPCP_HBED2_tag;

struct effPCP_HBED2_tag {
    effPCP_HBED2_Param_t *param;
    effPCPHelperBED_tag *pHelperBED;
};
