#pragma once
#include "types.h"

typedef struct movieFileItem_tag movieFileItem_tag;

struct movieFileItem_tag {
    movieFileItem_tag *next;
    char *filename;
};
