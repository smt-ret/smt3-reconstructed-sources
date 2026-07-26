#include "types.h"

typedef struct fclSkill_t fclSkill_t;

static fclSkill_t fclSkillTbl[UNKNOWN_ARRAY_SIZE];

bool IsZensyoMode(void);
bool evtBitCheck(s32 no);

// 0xc16530
fclSkill_t *Get(s32 id) {
    IsZensyoMode();
    evtBitCheck(0);
    return 0;
}
