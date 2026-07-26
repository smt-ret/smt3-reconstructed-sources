#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct AssetBundles AssetBundles;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct tagpipeBasic tagpipeBasic;

static s32 SectionIndex;
static s32 mapIndex;
static s32 mapPrev;
static s8 pipeFlow;
static s8 debugMode;

char *GetAppendix(void);
bool IsLoad(AssetBundles *this, char *key);
void Load(char *key, char *filePath);
void LoadLocalizeText(char *key, char *filename);
void Remove(char *key);
void UnloadAB(AssetBundleCtrl *this, char *key);
void dds3DeleteScene(dds3Basic_t **scene);
void dds3FadeIn(u32 r, u32 g, u32 b, u32 frame);
dds3Basic_t *dds3GetControlScene(void);
s32 dds3KillProcessName(char *name, s32 shutdowntimer);
dds3ProcessID_t *dds3SearchProcessName(char *namestr);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void mymdlDelete(tagpipeBasic **pWork, s16 mNum);
s8 pipeCamGetMode(s32 mapIdx, s32 prevArea);
void pipeEffLoad(void);
void pipeEndSection(void);
void pipeInitSection(void);
s32 pipeLoadSection(s32 index);
s32 pipeResultSection(void);
s32 pipe_Section(void);

// 0x1534440
s32 ChkPipe(void) {
  return dds3SearchProcessName(StringLiteral_4613) != 0;
}

// 0x15344c0
void DEBUG_PRINT(char **str, void **LegacyParamArray) {
  ;
}

// 0x1533ea0
void EndPipe(void) {
  System_String_o *v19;
  System_String_o *Appendix;
  System_String_o *v22;
  AssetBundleCtrl_o *asset_bc;
  AssetBundleCtrl_o *v24;

  pipeEndSection();
  dds3KillProcessName(StringLiteral_4613, 1);
  mymdlDelete(basicMy, basicMy->max_length);
  mymdlDelete(MyLine, MyLine->max_length);
  mymdlDelete(PipeMaka1, PipeMaka1->max_length);
  mymdlDelete(PipeZMaka, PipeZMaka->max_length);
  mymdlDelete(PipeDMaka, PipeDMaka->max_length);
  mymdlDelete(PipeDRBOX, PipeDRBOX->max_length);
  mymdlDelete(PipeLine, PipeLine->max_length);
  mymdlDelete(PipeCur, PipeCur->max_length);
  mymdlDelete(PipeCur2, PipeCur2->max_length);
  mymdlDelete(PipeRBOX, PipeRBOX->max_length);
  mymdlDelete(PipeEMS, PipeEMS->max_length);
  mymdlDelete(PipeEML, PipeEML->max_length);
  basicMyAnm = 0;
  basicMyChk = 0;
  v19 = StringLiteral_19042;
  Appendix = GetAppendix();
  v22 = Concat_5224608(StringLiteral_19042, Appendix);
  asset_bc = get_asset_bc();
  UnloadAB(asset_bc, v19);
  v24 = get_asset_bc();
  UnloadAB(v24, v22);
  Remove(StringLiteral_21893, 0);
}

// 0x1533740
void InitPipe(s32 data, s32 prevData) {
  System_String_o *v5;
  System_String_o *Appendix;
  System_String_o *v8;
  AssetBundleCtrl_o *asset_bc;
  AssetBundleCtrl_o *v11;
  AssetBundleCtrl_o *v12;
  AssetBundleCtrl_o *v14;
  u64 *v15;
  pipeMain_c *v20;
  struct pipeMain_StaticFields *static_fields;
  s32 mapPrev;
  s32 mapIndex;

  v5 = StringLiteral_19042;
  Appendix = GetAppendix();
  v8 = Concat_5224608(StringLiteral_19042, Appendix);
  asset_bc = get_asset_bc();
  if (!IsLoad(asset_bc, v5))
  {
    v11 = get_asset_bc();
    Load(v11, v5, v5, 0);
  }
  v12 = get_asset_bc();
  if (!IsLoad(v12, v8))
  {
    v14 = get_asset_bc();
    Load(v14, v8, v8, 0);
  }
  v15 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v15,
    0,
    Method_pipeMain_MainPipe__);
  dds3StartProcess(StringLiteral_4613, 0x3E8u, 0, 0, v15, 0, 0, 0, 0, 0);
  if (data)
  {
    SectionIndex = 1;
    debugMode = 0;
    mapIndex = data;
    mapPrev = prevData;
    static_fields = v20->static_fields;
    mapIndex = static_fields->mapIndex;
    mapPrev = static_fields->mapPrev;
    pipeFlow = pipeCamGetMode(mapIndex, mapPrev);
  }
  else
  {
    SectionIndex = 258;
    debugMode = 1;
  }
  pipeInitSection();
}

// 0x1532c20
dds3ProcessFunc_t *MainPipe(dds3ProcessID_t *aProcId) {
  AssetBundleCtrl_o *asset_bc;
  pipeMain_c *v5;
  struct pipeMain_StaticFields *static_fields;
  s32 SectionIndex;
  s16 v8;
  s32 v9;
  s32 debugMode;
  pipeMain_c *v12;
  AssetBundleCtrl_o *v21;
  System_String_o *Appendix;
  System_String_o *v23;
  s32 mapIndex;
  pipeMain_c *v29;
  dds3Basic_t_o *scene;

  scene = 0;
  asset_bc = get_asset_bc();
  if (!IsLoad(asset_bc, StringLiteral_19042))
    return 0;
  else
  {
    static_fields = pipeMain->static_fields;
    SectionIndex = static_fields->SectionIndex;
    if (static_fields->SectionIndex > 257)
    {
      if (SectionIndex == 258)
      {
        return 0;
      }
      if (SectionIndex == 259)
      {
        if (pipeResultSection())
        {
          SectionIndex = 0xFFFF;
        }
        return 0;
      }
      if (SectionIndex != 0xFFFF)
        return 0;
      v8 = *&v5->_2.bitflags1;
      if ((v8 & 0x200) != 0)
      {
        v9 = v8 & 0x200;
        debugMode = static_fields->debugMode;
        if (debugMode != 2)
      }
      else
      {
        v9 = 0;
        debugMode = static_fields->debugMode;
        if (debugMode != 2)
        {
          if (debugMode == 1)
          {
            dds3FadeIn(0, 0, 0, 0);
            static_fields = v12->static_fields;
            static_fields->SectionIndex = 258;
            return 0;
          }
          scene = dds3GetControlScene();
          dds3DeleteScene(&scene);
          aProcId->func_ans = -1;
          return 0;
        }
      }
      static_fields->SectionIndex = 257;
      return 0;
    }
  }
  if (SectionIndex != 1)
  {
    if (SectionIndex == 257)
    {
      if (pipe_Section())
      {
        SectionIndex = 259;
      }
    }
    return 0;
  }
  pipeEffLoad();
  v21 = get_asset_bc();
  Appendix = GetAppendix();
  v23 = Concat_5224608(StringLiteral_19042, Appendix);
  if (IsLoad(v21, v23))
  {
    LoadLocalizeText(StringLiteral_19042, StringLiteral_21893);
    pipeLoadSection(mapIndex - 1);
    static_fields = v29->static_fields;
  }
  return 0;
}
