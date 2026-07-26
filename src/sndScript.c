#include "types.h"

void FadeinBGM_20161776(s32 id, f32 fadetime);
s32 FindId_1916848(s32 type, s32 id);
void StopBGM_ALL(void);
s32 p2sdPlayBGM(s32 a);
s32 p2sdPlaySE(s32 a);
s32 scrGetIntPara(s32 n);

// 0x168f000
s32 sndScrCmd_BGM_PLAY(void) {
  s32 IntPara;
  s32 Id_1916848;

  IntPara = scrGetIntPara(0);
  Id_1916848 = FindId_1916848(0, IntPara);
  if (IntPara == 4587522)
  {
    FadeinBGM_20161776(Id_1916848, 2.0);
    return 1;
  }
  else
  {
    p2sdPlayBGM(Id_1916848);
    return 1;
  }
}

// 0x168f1c0
s32 sndScrCmd_BGM_STOP(void) {
  StopBGM_ALL();
  return 1;
}

// 0x168f120
s32 sndScrCmd_SE_PLAY(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  p2sdPlaySE(IntPara);
  return 1;
}
