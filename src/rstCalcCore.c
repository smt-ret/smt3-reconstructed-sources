#include "types.h"

typedef struct datUnitWork_s datUnitWork_t;

static f32 LEV_UP_NUM_A;
static f32 LEV_UP_NUM_B;
static f32 LEV_UP_NUM_C;

// 0x155e4c0
u32 GetNextExpDisp(datUnitWork_t *pStock, u32 now_exp) {
  s32 level;
  datUnitWork_t_o *pStocka;

  pStocka = pStock;
  level = pStock->level;
  return cmbCalcLevelUpExp(&pStocka, level + 1) - now_exp;
}

// 0x15594c0
void UnlockCheckRaceID(datUnitWork_t **pStock) {
  ;
}
