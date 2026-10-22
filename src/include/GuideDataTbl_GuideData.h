#pragma once
#include "types.h"

typedef struct GuideDataTbl_GuideData GuideDataTbl_GuideData;
typedef struct GuideDataTbl_GuideSet GuideDataTbl_GuideSet;

struct GuideDataTbl_GuideData {
    char *_name;
    char *_category;
    GuideDataTbl_GuideSet *_guideSet[5];
};
