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
  id = dds3SearchProcessName("movieViewer");
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
  v7->procId = dds3StartProcess("movieViewer", 0x2B02u, 1, 1, v8, 0, v9, 0, 0, 0);
}

// 0x12aaba0
void MakeMovieFileList(void) {
  System_String_o *dataPath;
  System_String_o *v5;
  u64 v6;
  u32 v7;
  s64 v8;
  s32 v10;
  struct mviManager_sMovTbl_array *dds3MovieTable;
  u64 max_length_low;
  struct movieViewerWork_t_o *movieViewerWork;
  s64 v17;
  u64 v18;
  s32 v19;
  struct mviManager_sMovTbl_array *v21;
  u64 v22;
  struct movieFileItem_tag_array *fileItems;
  u64 *v26;
  struct movieFileItem_tag_array *v29;
  movieFileItem_tag_o *v32;
  struct mviManager_sMovTbl_array *v33;
  u64 v38;
  struct movieFileItem_tag_array *v39;
  movieFileItem_tag_o *v41;
  movieFileItem_tag_o *v42;
  struct movieFileItem_tag_array *v44;

LABEL_7:
  movieViewerWork->fileItems = 0;
  movieViewerWork->fileListTopIndex = 0;
  movieViewerWork->fileListIndex = 0;
  movieViewerWork->fileListCount = 0;
  dataPath = get_dataPath();
  v5 = Concat_5224608(dataPath, "/StreamingAssets/movie/");
  v6 = 0;
  v7 = 0;
  v8 = 48;
  {
LABEL_13:
  }
  while (1)
  {
    max_length_low = LODWORD(dds3MovieTable->max_length);
    if (v6 >= max_length_low)
      break;
    else if (v6 >= max_length_low)
    {
      goto LABEL_19;
    }
    v10 = *(&dds3MovieTable->obj.klass + v8);
    v8 += 32;
    v7 += v10;
    ++v6;
      goto LABEL_13;
  }
  movieViewerWork->fileItems = NewSpecific(movieFileItem_tag, v7);
  v17 = 0;
  v18 = 0;
  v19 = 0;
  {
LABEL_28:
  }
  while (1)
  {
    v21 = dds3MovieTable;
    v22 = LODWORD(v21->max_length);
    if (v18 >= v22)
      break;
    else if (v18 >= v22)
    {
      goto LABEL_34;
    }
    if (v21->m_Items[v17].enabled)
    {
      fileItems = movieViewerWork->fileItems;
      v26 = Allocate(movieFileItem_tag);
      _ctor(v26, 0);
      fileItems->m_Items[v19] = v26;
      v29 = movieViewerWork->fileItems;
      v32 = v29->m_Items[v19];
      v33 = dds3MovieTable;
      ++v19;
      v32->filename = Concat_5271136(v5, v33->m_Items[v17].folder, dds3MovieTable->m_Items[v17].name, ".mp4");
    }
    ++v18;
    ++v17;
      goto LABEL_28;
  }
  if (v19 >= 1)
  {
    v38 = 0;
    do
    {
      v39 = movieViewerWork->fileItems;
      v41 = v39->m_Items[v38];
      if (v38 == v19 - 1)
      {
        v42 = 0;
        ++v38;
      }
      else
      {
        v44 = movieViewerWork->fileItems;
        v42 = v44->m_Items[v38];
      }
      v41->next = v42;
    }
    while (v38 != v19);
  }
  movieViewerWork->fileListCount = v19;
}

// 0x12ac5b0
void MovieViewerDrawFrameInfo(void) {
  sdfDrawTag_t_o *drawTag;
  s32 CX;
  s32 CY;
  System_Object_array *v9;
  s64 *v11;
  s64 *v12;
  s64 *v14;
  s64 *v16;
  Il2CppObject *v20;
  s32 frameCount;
  s32 frame;

  else if (movieCheckEnd())
  {
    return;
  }
  drawTag = movieViewerWork->drawTag;
  CX = CX__;
  CY = CY__;
  v9 = NewSpecific(object, 2u);
  frame = dds3MovieCb->decodeCb->frame;
  v11 = sub_8D3950(s32, &frame);
  v12 = v11;
  v9->m_Items[0] = v12;
  frameCount = dds3MovieCb->decodeCb->frameCount;
  v14 = sub_8D3950(s32, &frameCount);
  v16 = v14;
  v9->m_Items[1] = v16;
  v20 = sdfDevPrintf(11 * CX + 0x8000, 16 * CY + 0x8000, 0xFEFFFFu, 0, "%04d/%04d", v9);
  sdfDrawTagLink(drawTag, v20);
}

// 0x12ac0e0
void MovieViewerDrawMovieFileList(void) {
  MovieViewer_c *v2;
  struct movieViewerWork_t_o *movieViewerWork;
  struct movieFileItem_tag_array *fileItems;
  s64 fileListTopIndex;
  s32 fileListIndex;
  movieFileItem_tag_o *next;
  bool v9;
  u32 v10;
  s32 v11;
  System_String_o *v13;
  s32 v14;
  s32 v15;
  s16 v16;
  u64 *v17;
  System_String_o *v19;
  s16 v20;

  if (movieViewerWork->fileItems)
  {
    else if (movieViewerWork->hideList)
    {
      return;
    }
    fileItems = movieViewerWork->fileItems;
    fileListTopIndex = movieViewerWork->fileListTopIndex;
    fileListIndex = movieViewerWork->fileListIndex;
    next = fileItems->m_Items[fileListTopIndex];
    v9 = (v2->_2.bitflags2 & 2) == 0;
    if (next)
    {
      v10 = 0;
      v11 = fileListIndex - fileListTopIndex;
      do
      {
        v13 = "{0}{1}";
        v14 = (3 * CX__) >> 4;
        v15 = (CY__ + CY__ * (v10 + 1)) >> 4;
        if (v11 == v10)
          v16 = 62;
        else
          v16 = 32;
        v20 = v16;
        v17 = sub_8D3950(char, &v20);
        v19 = Format_5268592(v13, v17, next->filename);
        fldKanjiDraw_17012416(v14, v15, 0xA09DC380, v19, 4);
        if (v10 > 6)
          break;
        next = next->next;
        ++v10;
      }
      while (next);
    }
  }
}

// 0x12ab160
movieFileItem_tag *MovieViewerGetCurr(void) {
  struct movieViewerWork_t_o *movieViewerWork;
  struct movieFileItem_tag_array *fileItems;
  u32 fileListIndex;

  fileItems = movieViewerWork->fileItems;
  if (!fileItems)
    return 0;
LABEL_6:
  fileListIndex = movieViewerWork->fileListIndex;
  return fileItems->m_Items[fileListIndex];
}

// 0x12ab220
dds3ProcessFunc_t *MovieViewerProc(dds3ProcessID_t *procId) {
  bool v4;
  char v6;

  v4 = DDS3_PADCHECK_PRESS(13);
  if (v4)
  {
    v6 = 1;
  }
  else
  {
    v6 = 30;
  }
  dds3MovieCb->decodeCb->fps = v6;
  if (!movieViewerWork->hideList)
    goto LABEL_35;
LABEL_18:
  else if (movieCheckEnd())
  {
    goto LABEL_48;
  }
  else if (DDS3_PADCHECK_TRIG(1))
  {
    goto LABEL_48;
  }
  if (!DDS3_PADCHECK_TRIG(3))
  {
    SelectVolumeMain();
      goto LABEL_43;
    goto LABEL_32;
  }
LABEL_48:
  movieViewerWork->hideList = 0;
  return 0;
}

// 0x12abb10
bool SelectMovieMain(void) {
  const char *namespaze;
  struct movieViewerWork_t_o *movieViewerWork;
  s32 fileListIndex;
  struct movieViewerWork_t_o *v16;
  s32 v17;
  struct movieViewerWork_t_o *v19;
  s32 v20;
  struct movieViewerWork_t_o *v21;
  s32 v22;

  else if (DDS3_PADCHECK_TRIG(1))
  {
    goto LABEL_6;
  }
  else if (!DDS3_PADCHECK_REP(7))
  {
    goto LABEL_47;
  }
  fileListIndex = movieViewerWork->fileListIndex;
  if (movieViewerWork->fileListCount - 1 > fileListIndex)
  {
    movieViewerWork->fileListIndex = fileListIndex + 1;
    v16 = movieViewerWork;
    v17 = v16->fileListIndex - 7;
    if (v17 > v16->fileListTopIndex)
    {
      v16->fileListTopIndex = v17;
    }
    goto LABEL_71;
  }
LABEL_47:
  else if (!DDS3_PADCHECK_REP(6))
  {
    goto LABEL_63;
  }
  v19 = movieViewerWork;
  v20 = v19->fileListIndex;
  if (v20 >= 1)
  {
    v19->fileListIndex = v20 - 1;
    v21 = movieViewerWork;
    v22 = v21->fileListIndex;
    if (v22 < v21->fileListTopIndex)
    {
      v21->fileListTopIndex = v22;
    }
    goto LABEL_71;
  }
LABEL_63:
  if (!DDS3_PADCHECK_TRIG(3))
    goto LABEL_71;
LABEL_66:
  movieStop();
  return 1;
}

// 0x12ab4a0
void SelectVolumeMain(void) {
  f32 v4;
  s32 v8;
  MovieViewer_c *v13;
  struct movieViewerWork_t_o *movieViewerWork;
  f32 Offset;
  f32 v16;
  struct movieViewerWork_t_o *v17;
  f32 v18;
  f32 v19;
  f32 v20;
  s32 CX2;
  s32 v24;
  f32 Volume;
  f32 v26;
  s32 v27;
  u64 *v28;
  u64 *v29;
  System_String_o *v31;
  struct sdfGrOt_t_array *dds3Ot;
  sdfGrOt_t_o *v36;
  sdfDrawTag_t_o *drawTag;
  f32 v38;
  f32 v39;

  else if (movieCheckEnd())
  {
    return;
  }
  if (DDS3_PADCHECK_PRESS(10))
    v4 = 0.1;
  else
    v4 = 0.01;
  if (DDS3_PADCHECK_PRESS(8))
    v4 = 1.0;
  if (!DDS3_PADCHECK_PRESS(2))
    goto LABEL_30;
LABEL_20:
  v8 = 1;
  movieViewerWork->Offset = 0.0;
    goto LABEL_31;
LABEL_24:
    goto LABEL_31;
  if (!DDS3_PADCHECK_PRESS(13))
    goto LABEL_36;
LABEL_32:
  movieViewerWork->bDisp ^= 1u;
LABEL_36:
  else if (!DDS3_PADCHECK_REP(5))
  {
    goto LABEL_53;
  }
  Offset = movieViewerWork->Offset;
  if (Offset < 10.0)
  {
    v16 = v4 + Offset;
    movieViewerWork->Offset = v16;
    if (v16 > 10.0)
    {
      movieViewerWork->Offset = 10.0;
      if ((v13->_2.bitflags2 & 2) == 0)
        goto LABEL_75;
      goto LABEL_73;
    }
    goto LABEL_72;
  }
LABEL_53:
  else if (!DDS3_PADCHECK_REP(4))
  {
    goto LABEL_70;
  }
  v17 = movieViewerWork;
  v18 = v17->Offset;
  if (v18 > -1.0)
  {
    v19 = v18 - v4;
    v17->Offset = v19;
    if (v19 < -1.0)
    {
      movieViewerWork->Offset = -1.0;
      if ((v13->_2.bitflags2 & 2) == 0)
        goto LABEL_75;
      goto LABEL_73;
    }
LABEL_72:
    if ((v13->_2.bitflags2 & 2) == 0)
    {
LABEL_75:
      v20 = movieViewerWork->Offset;
      SetVolume(v20, 0);
      goto LABEL_79;
    }
LABEL_73:
    goto LABEL_75;
  }
LABEL_70:
  if (v8)
  {
    goto LABEL_72;
  }
LABEL_79:
  if (movieViewerWork->bDisp)
  {
    CX2 = CX2_;
    v24 = CY2_ >> 4;
    Volume = GetVolume(0);
    v39 = movieViewerWork->Offset;
    v26 = Volume + v39;
    v27 = CX2 >> 4;
    v28 = sub_8D3950(f32, &v39);
    v38 = v26;
    v29 = sub_8D3950(f32, &v38);
    v31 = Format_5268592("Volume + {0} = {1}", v28, v29);
    fldKanjiDraw_17012416(v27, v24, 0xA09DC380, v31, 4);
    fldKanjiDraw_17012416(v27, v24 + 12, 0xA09DC380, "L or R        : OFFSET +- 0.01   ", 4);
    fldKanjiDraw_17012416(v27, v24 + 24, 0xA09DC380, "R1 + L or R   : OFFSET +- 0.1    ", 4);
    fldKanjiDraw_17012416(v27, v24 + 36, 0xA09DC380, "L1 + L or R   : OFFSET +- 1.0    ", 4);
    fldKanjiDraw_17012416(v27, v24 + 48, 0xA09DC380, "RU            : RESET OFFSET     ", 4);
    fldKanjiDraw_17012416(v27, v24 + 60, 0xA09DC380, "SELECT        : MENU DISP ON/OFF ", 4);
    v36 = dds3Ot->m_Items[71];
    drawTag = movieViewerWork->drawTag;
    sdfDrawTagLinkOt(v36, drawTag);
  }
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
  return dds3SearchProcessName("movieViewer") == 0;
}
