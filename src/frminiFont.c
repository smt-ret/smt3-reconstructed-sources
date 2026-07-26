#include "types.h"

typedef struct _FRQ _FRQ;
typedef struct frminiFont frminiFont;
typedef struct sdfTexHandle_t sdfTexHandle_t;

// 0x13a6f80
void frDestroyMiniFont(frminiFont *this) {
  ;
}

// 0x13a6f70
void frInitMiniFont(frminiFont *this) {
  ;
}

// 0x13a6f50
void frInitUvTable(void) {
  ;
}

// 0x13a6f60
sdfTexHandle_t *frLoadFontTexture(frminiFont *this, s8 pFileName) {
  return 0;
}

// 0x13a6f90
_FRQ *frSetMiniFont(frminiFont *this, s8 pStr, u32 Color, _FRQ *pFRQ) {
  return pFRQ;
}
