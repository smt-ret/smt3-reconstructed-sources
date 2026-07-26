#include "types.h"

static char *txt[16];

char *GetLocalizeText(char *ID);

// 0x7c4220
char *Get(s32 id) {
    GetLocalizeText(0);
    return 0;
}
