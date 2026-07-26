#include "types.h"

typedef struct pmdProcessWork_t pmdProcessWork_t;

// 0x10ddb00
void SaveGameDataBlur2(s32 h) {
  ;
}

// 0x10ddad0
void SaveGameDataCamera(s32 h) {
  ;
}

// 0x10ddaa0
void SaveGameDataCutInfo(s32 h) {
  ;
}

// 0x10ddb20
void SaveGameDataDistBlur(s32 h) {
  ;
}

// 0x10ddb40
void SaveGameDataFilter(s32 h) {
  ;
}

// 0x10ddab0
void SaveGameDataFrame(s32 h) {
  ;
}

// 0x10dda90
void SaveGameDataHeader(s32 h, s32 no) {
  ;
}

// 0x10ddb10
void SaveGameDataMultBlur(s32 h) {
  ;
}

// 0x10ddb50
void SaveGameDataMultFilter(s32 h) {
  ;
}

// 0x10ddac0
void SaveGameDataName(s32 h) {
  ;
}

// 0x10ddb30
void SaveGameDataRipBlur(s32 h) {
  ;
}

// 0x10ddaf0
void SaveGameDataSceneFog(s32 h) {
  ;
}

// 0x10ddae0
void SaveGameDataSceneLight(s32 h) {
  ;
}

// 0x10dda30
s32 SetBlur2Index(void) {
  return 0;
}

// 0x10dda50
s32 SetDistBlurIndex(void) {
  return 0;
}

// 0x10dda70
s32 SetFilterIndex(void) {
  return 0;
}

// 0x10ddb70
s32 SetGameData(pmdProcessWork_t *wdata) {
  return 1;
}

// 0x10dda40
s32 SetMultBlurIndex(void) {
  return 0;
}

// 0x10dda80
s32 SetMultFilterIndex(void) {
  return 0;
}

// 0x10dda60
s32 SetRipBlurIndex(void) {
  return 0;
}

// 0x10dda20
s32 SetSceneFogIndex(void) {
  return 0;
}

// 0x10dda10
s32 SetSceneLightIndex(void) {
  return 0;
}

// 0x10dda00
void evtFileCmdWrite(s32 h, void *data, s32 size) {
  ;
}

// 0x10ddb80
s32 evtViewerLoadGameData(s32 type) {
  return 1;
}

// 0x10ddb60
s32 evtViewerSaveGameData(s32 type) {
  return 1;
}
