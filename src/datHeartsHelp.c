#include "types.h"

static u8 tbl[3341];

static char *txt[28];

char *GetLocalizeText(char *ID);

// 0x12aee90
char *Get(s32 id) {
    GetLocalizeText(0);
    return 0;
}
