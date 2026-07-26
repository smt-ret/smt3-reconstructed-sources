#include "types.h"

typedef struct SwitchMovie SwitchMovie;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3MovieTable_t dds3MovieTable_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct mviManager_MvSTAT mviManager_MvSTAT;
typedef struct mviManager_sMovTbl mviManager_sMovTbl;
typedef struct sdfMovieCb_t sdfMovieCb_t;
typedef struct sdfMovieInitParm_t sdfMovieInitParm_t;

struct mviManager_sMovTbl {
    char *folder;
    char *name;
    bool enabled;
    s32 fps;
    s32 vblank;
};

struct mviManager_MvSTAT {
    s32 value__;
};

static dds3MovieTable_t *movie_param;
static s32 loadstat;
static s32 moviestep;
static s32 moviestep2;
static sdfMovieCb_t *dds3MovieCb;
static void *movieObject;
static s32 PlayingNo;
static f32 Multiply;
static s32 bAfterRelease;
static sdfMovieInitParm_t *dds3MvTblPrm;
static mviManager_sMovTbl *dds3MovieTable[27];
static dds3ProcessID_t *dds3MovieDrawProcId;
static void *movie_obj;
static SwitchMovie *video;

f32 GetMovieVolume(void);
void SetDrawFlag(u32 flag, u32 cnt);
void SetNormalFrameRate(dds3DefaultMain *this);
void SetOffset(SwitchMovie *this, f32 ofs);
void Stop(SwitchMovie *this);
void *dds3GetProcessData(dds3ProcessID_t **id);
s32 dds3KillProcess(dds3ProcessID_t **id, s32 shutdowntimer);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
s32 moviePlay(s32 aNum, s32 Layer);
void moviePlayFile(s32 index, s32 Layer);
void movieStop(void);
void release_movieobj(dds3MovieTable_t *data);
void release_movieobj2(dds3MovieTable_t *data);
void release_movieobj_e658(dds3MovieTable_t *data);
void video_update(dds3MovieTable_t *data);

// 0x19ca690
bool CanStopVideo(void) {
  return 1;
}

// 0x19ca4f0
void FldChrObjSw(bool sw) {
  UnityEngine_GameObject_o *v3;
  Il2CppObject *Component_object;
  struct dds3MovieTable_t_o *movie_param;
  struct dds3MovieTable_t_o *v8;
  bool v9;

  v3 = Find(StringLiteral_4672, 0);
  Component_object = GetComponent_object_(v3);
  if (!sw)
  {
    movie_param->fldmap = get_activeSelf(Component_object[14].klass);
    v8 = movie_param;
    v8->character = get_activeSelf(Component_object[13].klass);
  }
  v9 = sw;
  SetActive(Component_object[14].klass, v9, 0);
  SetActive(Component_object[13].klass, v9, 0);
}

// 0x19caab0
f32 GetVolume(void) {
  f32 MovieVolume;

  MovieVolume = GetMovieVolume();
  return powf(10.0, MovieVolume / 20.0);
}

// 0x19c8e10
void MovieInit(void) {
  LODWORD(v2[2].klass->_1.gc_desc) = 0;
  movieStop();
}

// 0x19c9760
void SetAfterRelease(dds3MovieTable_t *data) {
  bAfterRelease = 30;
  SetDrawFlag(0x2000000u, 1u);
  loadstat = 5;
}

// 0x19ca9c0
void SetVolume(f32 f) {
  UnityEngine_Object_o *video;

  Multiply = f;
  if (!op_Equality(video, 0, 0))
  {
    SetOffset(video, f);
  }
}

// 0x19ca720
s32 frame(void) {
  return get_frame();
}

// 0x19ca870
s32 frameCount(void) {
  return get_framecount();
}

// 0x19ca6a0
s32 movieCheckDrawStat(void) {
  return 2 * (loadstat == 3);
}

// 0x19ca5f0
s32 movieCheckEnd(void) {
  s64 loadstat;

  else
  {
    if (loadstat <= 4)
      return dword_344436C[loadstat];
  }
  return 0;
}

// 0x19c9170
dds3ProcessFunc_t *movieDrawProc(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
    video_update(0);
    release_movieobj(0);
    SetDrawFlag(0, 0);
    release_movieobj2(0);
    return 0;
}

// 0x19ca410
s32 moviePlay(s32 aNum, s32 Layer) {
  struct mviManager_StaticFields *static_fields;
  s32 loadstat;

  static_fields = mviManager->static_fields;
  loadstat = static_fields->loadstat;
  if (loadstat == 3)
    return 1;
  if (!loadstat)
  {
    static_fields->PlayingNo = aNum;
    moviePlayFile(aNum, Layer);
  }
  return 0;
}

// 0x19ca390
s32 moviePlay2(s32 aNum, s32 Layer) {
  movieStop();
  moviePlay(aNum, Layer);
  return 0;
}

// 0x19c9a80
void moviePlayFile(s32 index, s32 Layer) {
  u64 *v5;
  struct dds3MovieTable_t_o *movie_param;
  System_String_array *v9;
  s64 *streamingAssetsPath;
  s64 *v11;
  struct mviManager_sMovTbl_array *dds3MovieTable;
  s64 *folder;
  struct mviManager_sMovTbl_array *v20;
  s64 *name;
  struct mviManager_sMovTbl_array *v28;
  struct mviManager_sMovTbl_array *v30;
  u64 *v34;
  Il2CppObject *data;

  else if (dds3MovieDrawProcId)
  {
    Log(StringLiteral_19163, 0);
    return;
  }
  v5 = Allocate(dds3MovieTable_t);
  _ctor(v5, 0);
  movie_param = v5;
  v9 = NewSpecific(string, 5u);
  streamingAssetsPath = get_streamingAssetsPath();
  v11 = streamingAssetsPath;
  v9->m_Items[0] = v11;
  v9->m_Items[1] = StringLiteral_19164;
  folder = dds3MovieTable->m_Items[index].folder;
  v9->m_Items[2] = folder;
  v20 = dds3MovieTable;
  name = v20->m_Items[index].name;
  v9->m_Items[3] = name;
  v9->m_Items[4] = StringLiteral_5290;
  movie_param->filename = Concat_5271600(v9);
  movie_param->initParm = dds3MvTblPrm;
  movie_param->id = index;
  movie_param->layer = Layer;
  loadstat = 1;
  PlayingNo = index;
  v28 = dds3MovieTable;
  set_targetFrameRate(v28->m_Items[index].fps);
  v30 = dds3MovieTable;
  set_vSyncCount(v30->m_Items[index].vblank);
  if (index != 6 && !MovieSkipflag && (index > 0x11 || ((1 << index) & 0x39200) == 0))
  {
    SetDrawFlag(0x2000000u, 1u);
  }
  v34 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v34,
    0,
    Method_mviManager_movieDrawProc__);
  data = movie_param;
  dds3MovieDrawProcId = dds3StartProcess(
                                                              StringLiteral_19165,
                                                              0x2AFBu,
                                                              1,
                                                              1,
                                                              v34,
                                                              0,
                                                              0,
                                                              0,
                                                              data,
                                                              0);
}

// 0x19c9fd0
void moviePlayFile_27041744(char *filename, sdfMovieInitParm_t *prm, s32 Layer) {
  mviManager_c *v7;
  s64 v8;
  u64 v9;
  System_String_o *FileNameWithoutExtension;
  System_String_o *v12;
  struct mviManager_sMovTbl_array *dds3MovieTable;
  struct mviManager_StaticFields **p_static_fields;
  struct mviManager_StaticFields *static_fields;
  struct mviManager_sMovTbl_array *v18;
  struct mviManager_sMovTbl_array *v20;
  u64 *v22;
  u64 *v24;
  Il2CppObject *data;

  else if (dds3MovieDrawProcId)
  {
    Log(StringLiteral_19163, 0);
    return;
  }
  v8 = 0;
  v9 = 0;
  if ((v7->_2.bitflags2 & 2) == 0)
  while (v9 < SLODWORD(dds3MovieTable->max_length))
  {
    FileNameWithoutExtension = GetFileNameWithoutExtension(filename);
    v12 = ToUpper(FileNameWithoutExtension, 0);
    if (Equals_5234480(v12, dds3MovieTable->m_Items[v8].name))
    {
      break;
    }
    ++v9;
    ++v8;
  }
  p_static_fields = &v7->static_fields;
  static_fields = v7->static_fields;
  if (LODWORD(static_fields->dds3MovieTable->max_length) != v9)
  {
    static_fields->PlayingNo = v9;
    v18 = (*p_static_fields)->dds3MovieTable;
    set_targetFrameRate(v18->m_Items[v8].fps);
    v20 = dds3MovieTable;
    set_vSyncCount(v20->m_Items[v8].vblank);
  }
  PlayingNo = v9;
  v22 = Allocate(dds3MovieTable_t);
  _ctor(v22, 0);
  movie_param = v22;
  movie_param->filename = filename;
  movie_param->initParm = prm;
  movie_param->id = v9;
  movie_param->layer = Layer;
  loadstat = 1;
  v24 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v24,
    0,
    Method_mviManager_movieDrawProc__);
  data = movie_param;
  dds3MovieDrawProcId = dds3StartProcess(
                                                              StringLiteral_19165,
                                                              0x2AFBu,
                                                              1,
                                                              1,
                                                              v24,
                                                              0,
                                                              0,
                                                              0,
                                                              data,
                                                              0);
}

// 0x19c8e80
void movieStop(void) {
    SetNormalFrameRate(0);
    dds3GetProcessData(0);
    SetDrawFlag(0, 0);
    release_movieobj(0);
    dds3KillProcess(0, 0);
}

// 0x19c9810
void release_movieobj(dds3MovieTable_t *data) {
  UnityEngine_Object_o *video;
  UnityEngine_Object_o *movie_obj;

  if (!op_Equality(video, 0, 0))
  {
    Stop(video);
    Destroy_27360000(movie_obj);
    movie_obj = 0;
    UnloadUnusedAssets();
    Collect(0);
  }
}

// 0x19c9960
void release_movieobj2(dds3MovieTable_t *data) {
  u64 v3;
  s64 v4;
  s32 v5;
  bool v6;

  SetDrawFlag(0x2000000u, 1u);
  v4 = *(v3 + 184);
  v5 = *(v4 + 48);
  v6 = __OFSUB__(v5--, 1);
  *(v4 + 48) = v5;
  if ((v5 < 0) ^ v6 | (v5 == 0))
  {
    if ((*(v3 + 295) & 2) != 0 && !*(v3 + 216))
    release_movieobj_e658(v3);
    dds3KillProcess(&dds3MovieDrawProcId, 0);
    dds3MovieDrawProcId = 0;
    loadstat = 0;
    PlayingNo = -1;
  }
}

// 0x19cab60
void release_movieobj_e658(dds3MovieTable_t *data) {
  UnityEngine_Object_o *video;
  UnityEngine_Object_o *movie_obj;

  if (!op_Equality(video, 0, 0))
  {
    Stop(video);
    Destroy_27360000(movie_obj);
    movie_obj = 0;
    UnloadUnusedAssets();
    Collect(0);
  }
}

// 0x19cab50
void stop_movie_e658(void) {
  ;
}

// 0x19c9670
void video_update(dds3MovieTable_t *data) {
  UnityEngine_Object_o *video;
  mviManager_c *v5;
  struct mviManager_StaticFields *static_fields;

  if (!op_Equality(video, 0, 0))
  {
    static_fields = v5->static_fields;
    if (static_fields->video->Status == 5)
    {
      static_fields->loadstat = 4;
    }
  }
}
