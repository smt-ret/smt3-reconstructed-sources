#include "types.h"

typedef struct ScrCommandTable ScrCommandTable;
typedef struct scrCommandTable_t scrCommandTable_t;

struct ScrCommandTable {
    s32 scrCommandMax;
};

static scrCommandTable_t *scrCommandTable[544];
