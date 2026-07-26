#include "types.h"

typedef struct motiontable_tag motiontable_tag;

struct motiontable_tag {
    s32 no;
    f32 speed;
};

static motiontable_tag *tbl[256];
