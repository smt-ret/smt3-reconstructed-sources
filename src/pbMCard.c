#include "types.h"

typedef struct pbMCardStat_t pbMCardStat_t;
typedef struct pb_MCARD_sceMcTblGetDir pb_MCARD_sceMcTblGetDir;

static s32 SCE_RDWR;

// 0x14a3090
s32 pbChangeDirectory(s32 port, s32 slot, char **pathName) {
    return 0;
  return 0;
}

// 0x14a2fb0
s32 pbGetDirMCard(s32 port, s32 slot, char **fileName, pb_MCARD_sceMcTblGetDir **tbl) {
    return 0;
  return 0;
}

// 0x14a3020
s32 pbGetDirMCard2(s32 port, s32 slot, char **fileName) {
    return 0;
  return 0;
}

// 0x14a2df0
void pbGetFormatStatusMCard(s32 port, s32 slot, pbMCardStat_t *stat) {

}

// 0x14a2ed0
void pbGetFreeStatusMCard(s32 port, s32 slot, pbMCardStat_t **stat) {

}

// 0x14a2f40
void pbGetStatusMCard(s32 port, s32 slot, pbMCardStat_t **stat) {

}

// 0x14a2e60
void pbGetTypeStatusMCard(s32 port, s32 slot, pbMCardStat_t **stat) {

}

// 0x14a2ce0
void pbInitMCard(void) {
}

// 0x14a3100
s32 pbMkdirMCard(s32 port, s32 slot, char **dirName) {
    return 0;
  return 0;
}

// 0x14a3170
s32 pbReadMCard(s32 port, s32 slot, char **fileName, void *buff, s32 size) {
    return 0;
}

// 0x14a3330
s32 pbWriteMCard(s32 port, s32 slot, char **fileName, s32 mode, void *buff, s32 size) {
    return 0;
}

// 0x14a2c80
s32 sceMcChdir(s32 a, s32 b, char *c, s32 d) {
  return 0;
}

// 0x14a2c40
s32 sceMcClose(s32 a) {
  return 0;
}

// 0x14a2c90
s32 sceMcGetDir(s32 a, s32 b, char *c, s32 d, s32 e, void *f) {
  return 0;
}

// 0x14a2cd0
s32 sceMcGetInfo(s32 a, s32 b, s32 c, s32 d, s32 e) {
  return 0;
}

// 0x14a2cb0
s32 sceMcInit(void) {
  return 0;
}

// 0x14a2c70
s32 sceMcMkdir(s32 a, s32 b, char *c) {
  return 0;
}

// 0x14a2c60
s32 sceMcOpen(s32 a, s32 b, char *c, s32 d) {
  return 0;
}

// 0x14a2c50
s32 sceMcRead(s32 a, void *b, s32 c) {
  return 0;
}

// 0x14a2ca0
s32 sceMcSync(s32 a, s32 b, s32 c) {
  return 0;
}

// 0x14a2c30
s32 sceMcWrite(s32 a, void *b, s32 c) {
  return 0;
}

// 0x14a2cc0
s32 sceSifLoadModule(char *a, s32 b, void *c) {
  return 0;
}
