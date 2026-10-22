#pragma once
#include "types.h"

typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct movieFileItem_tag movieFileItem_tag;
typedef struct movieViewerWork_t movieViewerWork_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;

struct movieViewerWork_t {
    dds3ProcessID_t *procId;
    movieFileItem_tag *fileItems;
    s16 fileListTopIndex;
    s16 fileListIndex;
    s16 fileListCount;
    u8 hideList;
    s32 Volume;
    s32 BaseVol;
    f32 Offset;
    bool bDisp;
    sdfDrawTag_t *drawTag;
};
