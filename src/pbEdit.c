#include "types.h"

typedef struct pbProcHandle_t pbProcHandle_t;

static pbProcHandle_t *goal;

// 0x1657100
u32 pbCheckMap(void) {
  s16 v3;
  s32 v4;
  struct pbBackup_t_o *bup;
  u32 v6;

  if ((v3 & 0x200) != 0)
  {
    v4 = v3 & 0x200;
  }
  else
  {
    v4 = 0;
  }
  bup = pbWk->bup;
  v6 = bup->pchar_num == 0;
  if (!LODWORD(bup->exit_pos->max_length))
    goto LABEL_15;
LABEL_11:
  return v6;
}

// 0x16570f0
pbProcHandle_t *pbStartEditMap(pbProcHandle_t **parent) {
  return 0;
}
