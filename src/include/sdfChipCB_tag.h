#pragma once
#include "types.h"

typedef struct sdfChipCB_tag sdfChipCB_tag;
typedef struct sdfChipPageInfo_tag sdfChipPageInfo_tag;

struct sdfChipCB_tag {
    sdfChipPageInfo_tag *currentPage;
    sdfChipPageInfo_tag *freeLink;
    s16 chipSize;
    s16 chipsPerPage;
};
