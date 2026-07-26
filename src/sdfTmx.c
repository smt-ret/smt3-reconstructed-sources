#include "types.h"

typedef struct TMX_HEADER_t TMX_HEADER_t;

// 0x15d58e0
void sdfTmxSetHeader(TMX_HEADER_t **aHeader, s32 aWidth, s32 aHeight, s32 aPixelFormat, s32 aNumOfCLUT, s32 aCLUTFormat) {
  (*aHeader)->fileType = 2;
  (*aHeader)->formatId = 811093332;
  (*aHeader)->width = aWidth;
  (*aHeader)->height = aHeight;
  (*aHeader)->pixelFormat = aPixelFormat;
  (*aHeader)->numOfCLUT = aNumOfCLUT;
  (*aHeader)->CLUTFormat = aCLUTFormat;
}
