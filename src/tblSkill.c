#include "types.h"

typedef struct fclSkill_t fclSkill_t;

static fclSkill_t *fclSkillTbl;

bool IsZensyoMode(void);
bool evtBitCheck(s32 no);

// 0xc16530
fclSkill_t *Get(s32 id) {
  bool IsZensyoMode;
  bool v5;
  struct fclSkill_t_array *v7;
  fclSkill_t_o **v9;
  bool v10;
  struct fclSkill_t_array *fclSkillTbl;
  struct fclSkill_t_array *v16;

  v10 = IsZensyoMode();
  v5 = id == 192;
  if (!v10)
    goto LABEL_15;
LABEL_6:
  if (!v5)
  {
    if (id == 191)
    {
      v7 = fclSkillTbl;
      v9 = &v7->m_Items[191];
      return *v9;
    }
    goto LABEL_20;
  }
  v16 = fclSkillTbl;
  v9 = &v16->m_Items[192];
  return *v9;
}
