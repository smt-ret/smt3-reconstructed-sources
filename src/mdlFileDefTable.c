#include "types.h"

typedef struct dds3ModelFileIndex_t dds3ModelFileIndex_t;
typedef struct dds3ModelFileKindTable_t dds3ModelFileKindTable_t;
typedef struct dds3ModelFileTableDef_t dds3ModelFileTableDef_t;
typedef struct dds3ModelFileTable_t dds3ModelFileTable_t;

static dds3ModelFileTable_t *humanModelFileTable;
static dds3ModelFileTable_t *devilModelFileTable;
static dds3ModelFileTable_t *devilOnModelFileTable;
static dds3ModelFileTable_t *fieldModelFileTable;
static dds3ModelFileTable_t *eventModelFileTable;
static dds3ModelFileTable_t *eventModelFileTable2;
static dds3ModelFileTable_t *testModelFileTable;
static dds3ModelFileTableDef_t *modelFileTable;
static dds3ModelFileIndex_t *humanModelIndex;
static dds3ModelFileIndex_t *devilModelIndex;
static dds3ModelFileIndex_t *devilOnModelIndex;
static dds3ModelFileIndex_t *fieldModelIndex;
static dds3ModelFileIndex_t *eventModelIndex;
static dds3ModelFileIndex_t *testModelIndex;
static dds3ModelFileKindTable_t *modelFileKindTable;

bool IsZensyoMode(void);
bool evtBitCheck(s32 no);

// 0xe00160
char *GetAkey(s32 no) {
  bool IsZensyoMode;
  u32 v5;
  struct dds3ModelFileTable_t_array *devilModelFileTable;
  dds3ModelFileTable_t_o *v9;
  System_String_o **p_akey;
  s32 v12;
  struct dds3ModelFileTable_t_array *v14;

  IsZensyoMode = IsZensyoMode();
  v5 = no - 339;
  if (!IsZensyoMode)
  {
    if (v5 >= 3 && no != 192)
      goto LABEL_20;
LABEL_18:
    if (!evtBitCheck(3712))
      goto LABEL_20;
    goto LABEL_19;
  }
  if (v5 < 3)
    goto LABEL_18;
  if (no != 191)
  {
    if (no == 192)
    {
      v9 = devilModelFileTable->m_Items[192];
LABEL_29:
      p_akey = &v9->akey;
      return *p_akey;
    }
LABEL_20:
    v12 = convDLCDevilNumber(no);
    v14 = devilModelFileTable;
    v9 = v14->m_Items[v12];
    goto LABEL_29;
  }
LABEL_19:
  p_akey = &"dvl0xc0d";
  return *p_akey;
}

// 0xdffde0
char *GetFname(s32 no) {
  bool IsZensyoMode;
  u32 v5;
  struct dds3ModelFileTable_t_array *devilModelFileTable;
  dds3ModelFileTable_t_o *v9;
  System_String_o **p_fname;
  s32 v12;
  struct dds3ModelFileTable_t_array *v14;

  IsZensyoMode = IsZensyoMode();
  v5 = no - 339;
  if (!IsZensyoMode)
  {
    if (v5 >= 3 && no != 192)
      goto LABEL_20;
LABEL_18:
    if (!evtBitCheck(3712))
      goto LABEL_20;
    goto LABEL_19;
  }
  if (v5 < 3)
    goto LABEL_18;
  if (no != 191)
  {
    if (no == 192)
    {
      v9 = devilModelFileTable->m_Items[192];
LABEL_29:
      p_fname = &v9->fname;
      return *p_fname;
    }
LABEL_20:
    v12 = convDLCDevilNumber(no);
    v14 = devilModelFileTable;
    v9 = v14->m_Items[v12];
    goto LABEL_29;
  }
LABEL_19:
  p_fname = &"devil_0xc0d";
  return *p_fname;
}

// 0xdfff80
char *GetPBname(s32 no) {
  struct dds3ModelFileTable_t_array *devilModelFileTable;
  dds3ModelFileTable_t_o *v7;
  s64 *p_modelFile;
  s32 v11;
  struct dds3ModelFileTable_t_array *v13;

  else if (!IsZensyoMode())
  {
    goto LABEL_15;
  }
  if (no == 191)
    goto LABEL_20;
  if (no == 192)
  {
    v7 = devilModelFileTable->m_Items[192];
LABEL_33:
    p_modelFile = &v7->modelFile;
    return *p_modelFile;
  }
LABEL_15:
  if (!evtBitCheck(3712))
    goto LABEL_24;
  if (no > 339)
  {
    if (no == 340)
    {
      p_modelFile = &"d0x154d.PB";
      return *p_modelFile;
    }
    if (no == 341)
    {
      p_modelFile = &"d0x155d.PB";
      return *p_modelFile;
    }
LABEL_24:
    v11 = convDLCDevilNumber(no);
    v13 = devilModelFileTable;
    v7 = v13->m_Items[v11];
    goto LABEL_33;
  }
  if (no == 192)
  {
LABEL_20:
    p_modelFile = &"d0xc0d.PB";
    return *p_modelFile;
  }
  if (no != 339)
    goto LABEL_24;
  p_modelFile = &"d0x153d.PB";
  return *p_modelFile;
}
