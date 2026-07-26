#pragma once
#include "types.h"

typedef struct sdfChipCB_tag sdfChipCB_tag;
typedef struct sdfChipPageInfo_tag sdfChipPageInfo_tag;
typedef struct sdfChipPageInfo_tag_allocDelegate sdfChipPageInfo_tag_allocDelegate;

struct sdfChipPageInfo_tag {
    sdfChipPageInfo_tag *next;
    void *page;
    sdfChipPageInfo_tag_allocDelegate *alloc;
    sdfChipCB_tag *owner;
    void *freeLink;
    s16 allocCount;
    s16 growLeft;
};
