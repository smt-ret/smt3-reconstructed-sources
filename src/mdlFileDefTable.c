#include "types.h"

typedef struct dds3ModelFileIndex_t dds3ModelFileIndex_t;
typedef struct dds3ModelFileKindTable_t dds3ModelFileKindTable_t;
typedef struct dds3ModelFileTableDef_t dds3ModelFileTableDef_t;
typedef struct dds3ModelFileTable_t dds3ModelFileTable_t;

static dds3ModelFileTable_t humanModelFileTable[UNKNOWN_ARRAY_SIZE];
static dds3ModelFileTable_t devilModelFileTable[UNKNOWN_ARRAY_SIZE];
static dds3ModelFileTable_t devilOnModelFileTable[UNKNOWN_ARRAY_SIZE];
static dds3ModelFileTable_t fieldModelFileTable[UNKNOWN_ARRAY_SIZE];
static dds3ModelFileTable_t eventModelFileTable[UNKNOWN_ARRAY_SIZE];
static dds3ModelFileTable_t eventModelFileTable2[UNKNOWN_ARRAY_SIZE];
static dds3ModelFileTable_t testModelFileTable[UNKNOWN_ARRAY_SIZE];
static dds3ModelFileTableDef_t modelFileTable[UNKNOWN_ARRAY_SIZE];
static dds3ModelFileIndex_t humanModelIndex[UNKNOWN_ARRAY_SIZE];
static dds3ModelFileIndex_t devilModelIndex[UNKNOWN_ARRAY_SIZE];
static dds3ModelFileIndex_t devilOnModelIndex[UNKNOWN_ARRAY_SIZE];
static dds3ModelFileIndex_t fieldModelIndex[UNKNOWN_ARRAY_SIZE];
static dds3ModelFileIndex_t eventModelIndex[UNKNOWN_ARRAY_SIZE];
static dds3ModelFileIndex_t testModelIndex[UNKNOWN_ARRAY_SIZE];
static dds3ModelFileKindTable_t modelFileKindTable[UNKNOWN_ARRAY_SIZE];

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
    if (!evtBitCheck(3712))
  }
  if (v5 < 3)
  if (no != 191)
  {
    if (no == 192)
    {
      v9 = devilModelFileTable->m_Items[192];
      p_akey = &v9->akey;
      return *p_akey;
    }
    v12 = convDLCDevilNumber(no);
    v14 = devilModelFileTable;
    v9 = v14->m_Items[v12];
  }
  p_akey = &StringLiteral_4869;
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
    if (!evtBitCheck(3712))
  }
  if (v5 < 3)
  if (no != 191)
  {
    if (no == 192)
    {
      v9 = devilModelFileTable->m_Items[192];
      p_fname = &v9->fname;
      return *p_fname;
    }
    v12 = convDLCDevilNumber(no);
    v14 = devilModelFileTable;
    v9 = v14->m_Items[v12];
  }
  p_fname = &StringLiteral_17096;
  return *p_fname;
}

// 0xdfff80
char *GetPBname(s32 no) {
  struct dds3ModelFileTable_t_array *devilModelFileTable;
  dds3ModelFileTable_t_o *v7;
  s64 *p_modelFile;
  s32 v11;
  struct dds3ModelFileTable_t_array *v13;

  else  if (no == 191)
  if (no == 192)
  {
    v7 = devilModelFileTable->m_Items[192];
    p_modelFile = &v7->modelFile;
    return *p_modelFile;
  }
  if (!evtBitCheck(3712))
  if (no > 339)
  {
    if (no == 340)
    {
      p_modelFile = &StringLiteral_17099;
      return *p_modelFile;
    }
    if (no == 341)
    {
      p_modelFile = &StringLiteral_17100;
      return *p_modelFile;
    }
    v11 = convDLCDevilNumber(no);
    v13 = devilModelFileTable;
    v7 = v13->m_Items[v11];
  }
  if (no == 192)
  {
    p_modelFile = &StringLiteral_17097;
    return *p_modelFile;
  }
  if (no != 339)
  p_modelFile = &StringLiteral_17098;
  return *p_modelFile;
}
