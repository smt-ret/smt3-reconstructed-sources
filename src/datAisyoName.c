#include "types.h"

static char *txt[448];

char *GetLocalizeText(char *ID);

// 0x162ce60
char *Get(s32 id) {
    GetLocalizeText(0);
    return 0;
}
