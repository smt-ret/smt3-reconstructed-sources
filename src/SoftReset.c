#include "types.h"

typedef struct SoftReset SoftReset;

void Init(void);
void SoftReset(void);
void fldNpcClear(bool clrflg);

// 0x1335160
void Start(SoftReset *this) {
  Init(0);
  SoftReset();
  SoftReset();
  fldNpcClear(1);
  dds3TheWorld = 0;
  UnloadUnusedAssets();
  LoadScene("xrd773");
}

// 0x1335290
void Update(SoftReset *this) {
  ;
}
