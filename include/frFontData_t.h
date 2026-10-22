#pragma once
#include "types.h"

typedef struct GsFont_t GsFont_t;
typedef struct frFontData_t frFontData_t;
typedef struct frFontHeader_t frFontHeader_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct frFontData_t {
    sdfMemHandle_t *mh;
    frFontHeader_t *header;
    s32 prop_size;
    s32 ysht_size;
    s8 *prop;
    s8 ysht;
    GsFont_t *trans;
    void *data;
};
