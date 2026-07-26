#include "types.h"

static u8 tbl[595];

static char *txt[7];

char *GetLocalizeText(char *ID);

// 0x161f390
char *Get(s32 id) {
    GetLocalizeText(0);
    return 0;
}
