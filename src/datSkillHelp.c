#include "types.h"

static u8 tbl[47501];

static char txt[UNKNOWN_ARRAY_SIZE];

char *GetLocalizeText(char *ID);

// 0x15029d0
char *Get(s32 id) {
    GetLocalizeText(0);
    return 0;
}
