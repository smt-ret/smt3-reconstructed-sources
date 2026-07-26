#include "types.h"

void DofOff(void);
s32 movieCheckDrawStat(void);
s32 movieCheckEnd(void);
s32 moviePlay(s32 aNum, s32 Layer);
void movieStop(void);
s32 scrGetIntPara(s32 n);
void scrSetIntReturnValue(s32 i);

// 0xf24ff0
s32 mviScrCmd_MOVIE_CHK(void) {
  s32 v3;

  v3 = movieCheckEnd() == 0;
  scrSetIntReturnValue(v3);
  return 1;
}

// 0xf25090
s32 mviScrCmd_MOVIE_CHKDRAW(void) {
  s32 v3;

  v3 = movieCheckDrawStat() == 2;
  scrSetIntReturnValue(v3);
  return v3;
}

// 0xf24e80
s32 mviScrCmd_MOVIE_PLAY(void) {
  s32 IntPara;

  DofOff();
  IntPara = scrGetIntPara(0);
  if (IntPara == 5)
  {
    PPSV2_update = 1;
    PPSV2_bloom_type = 600;
  }
  return moviePlay(IntPara, 0);
}

// 0xf24f80
s32 mviScrCmd_MOVIE_STOP(void) {
  movieStop();
  return 1;
}
