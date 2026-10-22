#pragma once
#include "types.h"

typedef struct instanceMes_tag instanceMes_tag;
typedef struct itfmisclinkheader_t itfmisclinkheader_t;
typedef struct mesflow_tag mesflow_tag;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct mesflow_tag {
    itfmisclinkheader_t *linkheader;
    instanceMes_tag *pinst;
    sdfMemHandle_t *memhandle;
};
