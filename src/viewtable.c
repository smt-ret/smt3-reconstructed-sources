#include "types.h"

typedef struct viewtable_tag viewtable_tag;

struct viewtable_tag {
    f32 radius;
    f32 rad_far;
    f32 rot_x;
    s16 ofs_x;
    s16 ofs_y;
};

static viewtable_tag *tbl[256];
