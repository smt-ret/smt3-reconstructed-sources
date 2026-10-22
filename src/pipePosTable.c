#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct mnMyLink_h_tagPipeLinkInfo mnMyLink_h_tagPipeLinkInfo;
typedef struct tagPipePartsInfo tagPipePartsInfo;
typedef struct tagPipePosTable tagPipePosTable;
typedef struct tagPipeTable tagPipeTable;

u8 **LoadFileByte(AssetBundleCtrl *this, char *key, char *path_name);
tagPipePartsInfo *getPartsInfo(s16 partsID);

// 0x15429e0
s32 MakePosTable(tagPipePosTable *pPos, mnMyLink_h_tagPipeLinkInfo *linkInfoPtr, f32 x, f32 y, f32 z, s32 mode) {
  return 1;
}

// 0x1540e30
tagPipePartsInfo *getPartsInfo(s16 partsID) {
  struct tagPipePartsInfo_array *pipePartsInfo;
  u64 v5;
  tagPipePartsInfo_o *result;

  {
  }
  v5 = 0;
  while (1)
  {
    result = pipePartsInfo->m_Items[v5];
    if (result->partsID == partsID)
      break;
    if (v5++ >= 0x3B)
      return 0;
  }
  return result;
}

// 0x1540dd0
s32 getPartsType(s32 id) {
  tagPipePartsInfo_o *PartsInfo;
  u32 v4;

  PartsInfo = getPartsInfo(id);
  if (PartsInfo)
  {
    v4 = (id << 19 >> 24) & 0xFFFFFFFE;
    if (PartsInfo->inWay + PartsInfo->goWay == 7)
      LODWORD(PartsInfo) = v4 | 1;
    else
      LODWORD(PartsInfo) = v4 + 2;
  }
  return PartsInfo;
}

// 0x15429f0
void lineTo(f32 **tPosPtr, f32 **sPosPtr, f32 **ePosPtr, f32 par) {
  f32 v5;
  f32 v6;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;

  v5 = ePosPtr->m_Items[0];
  v6 = sPosPtr->m_Items[0];
  v7 = ePosPtr->m_Items[1];
  v8 = sPosPtr->m_Items[1];
  v9 = ePosPtr->m_Items[2];
  v10 = sPosPtr->m_Items[2];
  tPosPtr->m_Items[0] = sPosPtr->m_Items[0];
  tPosPtr->m_Items[1] = sPosPtr->m_Items[1];
  tPosPtr->m_Items[2] = sPosPtr->m_Items[2];
  tPosPtr->m_Items[0] = ((v5 - v6) * par) + tPosPtr->m_Items[0];
  tPosPtr->m_Items[1] = ((v7 - v8) * par) + tPosPtr->m_Items[1];
  tPosPtr->m_Items[2] = ((v9 - v10) * par) + tPosPtr->m_Items[2];
}

// 0x1541ba0
s32 pipeFileLoad(char *filename, tagPipePosTable **posPtr, tagPipeTable **tabPtr, mnMyLink_h_tagPipeLinkInfo **linkInfo) {
  u64 *v9;
  u64 *v10;
  u64 *v11;
  AssetBundleCtrl_o *asset_bc;
  System_String_o *v14;
  System_Byte_array *FileByte;
  tagPipeFileHeader_o *v17;

  v9 = Allocate(mnMyLink_h_tagPipeLTable);
  _ctor(v9, 0);
  v10 = Allocate(mnMyLink_h_tagPipeLinkInfo);
  _ctor(v10, 0);
  v11 = Allocate(fileHandle_t);
  fileHandle_t___ctor(v11);
  asset_bc = get_asset_bc();
  v14 = Concat_5224608("dds3data", filename);
  FileByte = LoadFileByte(asset_bc, "pipe_common", v14);
  v17 = cnvPipeFileHeader(FileByte);
  *posPtr = cnvPipePosTable(FileByte, v17->posAddr, v17->posSize);
  *tabPtr = cnvPipeTable(FileByte, v17->emAddr, v17->emSize);
  *linkInfo = cnvPipeLinkInfo(FileByte, v17->linkAddr, v17->linkSize);
  return 1;
}

// 0x1541b90
s32 pipeFileSave(s8 filename, tagPipePosTable *posPtr, s8 index) {
  return 1;
}

// 0x15429d0
s32 pipeGetLinkOffset(mnMyLink_h_tagPipeLinkInfo *pInfo) {
  return 0;
}

// 0x1542cf0
void setEndPos(f32 **ePosPtr, tagPipePartsInfo *piPtr, f32 **sPosPtr, s32 mode) {
  ;
}
