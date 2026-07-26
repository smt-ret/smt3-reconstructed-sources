#include "types.h"

typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct movieFileItem_tag movieFileItem_tag;
typedef struct movieViewerWork_t movieViewerWork_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfMovieInitParm_t sdfMovieInitParm_t;

static s32 SCRN_OX;
static s32 SCRN_OY;
static s32 SCRN_TOP_X;
static s32 SCRN_TOP_Y;
static s32 CX__;
static s32 CY__;
static s32 CX2_;
static s32 CY2_;
static s32 FILE_LIST_CONS_OX;
static s32 FILE_LIST_CONS_OY;
static s32 FILE_LIST_CONS_SX;
static s32 FILE_LIST_CONS_SY;
static s32 FILE_LIST_UPDOWN_OX;
static s32 FILE_LIST_UPDOWN_OY_U;
static s32 FILE_LIST_UPDOWN_OY_D;
static s32 FILE_LIST_UPDOWN_W;
static s32 FILE_LIST_UPDOWN_H;
static movieViewerWork_t *movieViewerWork;
static sdfMovieInitParm_t *MovieViewerProc_movie_parm;
static u32 MovieViewerProc_pad_old;

bool DDS3_PADCHECK_PRESS(s32 id);
bool DDS3_PADCHECK_REP(s32 id);
bool DDS3_PADCHECK_TRIG(s32 id);
f32 GetVolume(void);
void MakeMovieFileList(void);
void MovieViewerDrawMovieFileList(void);
bool SelectMovieMain(void);
void SelectVolumeMain(void);
void SetMovieVolume(void);
void SetVolume(f32 f);
s32 dds3KillProcess(dds3ProcessID_t **id, s32 shutdowntimer);
u32 dds3PadGetPadMap(void);
dds3ProcessID_t *dds3SearchProcessName(char *namestr);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void fldKanjiDraw_17012416(s32 x, s32 y, u32 rgba, char *moji, s32 ftype);
s32 movieCheckEnd(void);
s32 moviePlay(s32 aNum, s32 Layer);
void moviePlayFile_27041744(char *filename, sdfMovieInitParm_t *prm, s32 Layer);
void movieStop(void);
void *sdfDevPrintf(s32 aX, s32 aY, u32 aZ, s32 aAttr, char *aStr, void **LegacyParamArray);
void sdfDrawTagLink(sdfDrawTag_t *aTag, void *aPacket);
s32 sdfDrawTagLinkOt(s32 a, sdfDrawTag_t *b);

// 0x12ac340
void *EventViewerShutdown(dds3ProcessID_t *id) {
  id->func_ans = -1;
  return 0;
}

// 0x12ac3d0
void FinishMovieViewer(void) {
  s32 BaseVol;
  dds3ProcessID_t_o *id;

  id = 0;
  id = dds3SearchProcessName(StringLiteral_5288);
  if (id)
  {
    dds3KillProcess(&id, 0);
    movieViewerWork->procId = 0;
    movieStop();
  }
  BaseVol = movieViewerWork->BaseVol;
  cfgSetBit_22187328(3u, BaseVol);
  movieViewerWork->fileItems = 0;
  movieViewerWork->fileListTopIndex = 0;
  movieViewerWork->fileListIndex = 0;
  movieViewerWork->fileListCount = 0;
}

// 0x12ab0d0
void FreeMovieFileList(void) {
  movieViewerWork->fileItems = 0;
  movieViewerWork->fileListTopIndex = 0;
  movieViewerWork->fileListIndex = 0;
  movieViewerWork->fileListCount = 0;
}

// 0x12aaa10
void InitMovieViewer(void) {
  struct movieViewerWork_t_o *movieViewerWork;
  s32 Bit;
  struct movieViewerWork_t_o *v7;
  u64 *v8;
  u64 *v9;

  MakeMovieFileList();
  Bit = cfgGetBit(3u);
  movieViewerWork->Volume = Bit;
  movieViewerWork->BaseVol = Bit;
  movieViewerWork->Offset = 0.0;
  movieViewerWork->hideList = 0;
  movieViewerWork->bDisp = 1;
  v7 = movieViewerWork;
  v8 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v8,
    0,
    Method_MovieViewer_MovieViewerProc__);
  v9 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v9,
    0,
    Method_MovieViewer_EventViewerShutdown__);
  v7->procId = dds3StartProcess(StringLiteral_5288, 0x2B02u, 1, 1, v8, 0, v9, 0, 0, 0);
}

// 0x12aaba0
void MakeMovieFileList(void) {
}

// 0x12ac5b0
void MovieViewerDrawFrameInfo(void) {
    movieCheckEnd();
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLink(0, 0);
}

// 0x12ac0e0
void MovieViewerDrawMovieFileList(void) {
    fldKanjiDraw_17012416(0, 0, 0, 0, 0);
}

// 0x12ab160
movieFileItem_tag *MovieViewerGetCurr(void) {
  struct movieViewerWork_t_o *movieViewerWork;
  struct movieFileItem_tag_array *fileItems;
  u32 fileListIndex;

  fileItems = movieViewerWork->fileItems;
  if (!fileItems)
    return 0;
  fileListIndex = movieViewerWork->fileListIndex;
  return fileItems->m_Items[fileListIndex];
}

// 0x12ab220
dds3ProcessFunc_t *MovieViewerProc(dds3ProcessID_t *procId) {
    DDS3_PADCHECK_PRESS(0);
    SelectMovieMain();
    dds3PadGetPadMap();
    movieCheckEnd();
    DDS3_PADCHECK_TRIG(0);
    SelectVolumeMain();
    return 0;
}

// 0x12abb10
bool SelectMovieMain(void) {
    DDS3_PADCHECK_TRIG(0);
    SetMovieVolume();
    movieStop();
    moviePlayFile_27041744(0, 0, 0);
    moviePlay(0, 0);
    DDS3_PADCHECK_REP(0);
    MovieViewerDrawMovieFileList();
    sdfDrawTagLinkOt(0, 0);
    return 0;
}

// 0x12ab4a0
void SelectVolumeMain(void) {
    movieCheckEnd();
    DDS3_PADCHECK_PRESS(0);
    DDS3_PADCHECK_REP(0);
    SetVolume(0);
    GetVolume();
    fldKanjiDraw_17012416(0, 0, 0, 0, 0);
    sdfDrawTagLinkOt(0, 0);
}

// 0x12ac000
void SetMovieVolume(void) {
  s32 Volume;
  f32 Offset;

  Volume = movieViewerWork->Volume;
  cfgSetBit_22187328(3u, Volume);
  Offset = movieViewerWork->Offset;
  SetVolume(Offset, 0);
}

// 0x12ac350
bool ViewerEndCheck(void) {
  return dds3SearchProcessName(StringLiteral_5288) == 0;
}
