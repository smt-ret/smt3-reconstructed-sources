#include "types.h"

static char *txt[160];

char *GetLocalizeText(char *ID);
bool dds3CheckDLC6(void);
bool dds3CheckDLC7(void);

// 0x12baf50
char *Get(s32 id) {
    dds3CheckDLC6();
    dds3CheckDLC7();
    GetLocalizeText(0);
    return 0;
}
