#include "types.h"

static s8 sdfPrintIopFlag;
static u8 sdfPrintRpcBuff[1024];

// 0x17a8010
void Log(char *fmt, void **parray) {
  ;
}

// 0x17a7fb0
s32 SDF_FOURCC(s32 a, s32 b, s32 c, s32 d) {
  return a | (b << 8) | (c << 16) & 0xFFFFFF | (d << 24);
}

// 0x17a7fe0
void sdfPrintIopInit(void) {
  ;
}

// 0x17a7fc0
void *sdfPrintRpcFunc(u32 funcNo, void *data, s32 size) {
  return 0;
}

// 0x17a7fd0
void sdfPrintRpcThread(void *dummy) {
  ;
}

// 0x17a8000
s32 sdfPrintf(char *str, void **LegacyParamArray) {
  return 0;
}

// 0x17a7ff0
void sdfPuts(char *str) {
  ;
}
