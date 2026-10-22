#pragma once
#include "types.h"

typedef struct PIPE_EFF_t PIPE_EFF_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct effHandle_t effHandle_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;
typedef struct tagMakaObject tagMakaObject;
typedef struct tagPipeEnemyInfo tagPipeEnemyInfo;
typedef struct tagPipeEnemyTable tagPipeEnemyTable;
typedef struct tagPipeFileHeader tagPipeFileHeader;
typedef struct tagPipeObject tagPipeObject;
typedef struct tagPipePartsInfo tagPipePartsInfo;
typedef struct tagPipePartsType tagPipePartsType;
typedef struct tagPipePosData tagPipePosData;
typedef struct tagPipePosTable tagPipePosTable;
typedef struct tagPipeTable tagPipeTable;
typedef struct tagPipeTexture tagPipeTexture;
typedef struct tagpipeBasic tagpipeBasic;
typedef struct tagpipeParts tagpipeParts;

struct tagpipeParts {
    s32 offset;
    u8 id;
    u8 mdl;
    s8 resv[5];
};

struct tagpipeBasic {
    dds3Basic_t *basic;
    dds3ModelHandle_t *model;
    s8 resv[3];
    s32 enabled;
    sdfVector4_t pos;
    sdfVector4_t rot;
    sdfVector4_t scl;
};

struct tagPipeObject {
    s32 offset;
    f32 w;
    sdfVector2_t pos;
    sdfVector2_t vpos;
    u8 id;
    u8 action;
    s32 enabled;
    u8 mdl;
    s16 count;
    u16 status;
};

struct tagPipeTexture {
    sdfTexHandle_t *th;
    sdfMemHandle_t *mh;
    void *mp;
    s32 resv;
};

struct tagMakaObject {
    u32 maka;
    s8 count;
    s32 pos[2];
    s8 resv[3];
    void *makaObject;
};

struct PIPE_EFF_t {
    sdfMemHandle_t *mhFile;
    void *ptr;
    s32 size;
    effHandle_t *d3p;
    f32 x;
    f32 y;
    f32 z;
    sdfVector2_t pos2;
    s32 offset;
    s32 count;
    void *tex;
};

struct tagPipePosTable {
    sdfMemHandle_t *aHandle;
    s32 tSize;
    tagPipePosData *pData;
};

struct tagPipeTable {
    s32 tabMax;
    sdfMemHandle_t *aHandle;
    tagPipeEnemyTable *tabPtr[1];
    s8 *data;
};

struct tagPipePosData {
    sdfVector4_t pos;
    sdfVector4_t up;
};

struct tagPipeEnemyTable {
    s32 offset;
    u8 chID;
    u8 way;
    u8 action;
    u8 value;
};

struct tagPipeEnemyInfo {
    u8 chID;
    f32 w;
    u8 resv;
    u16 resv2;
};

struct tagPipePartsType {
    f32 radius;
    f32 length;
    u32 frame;
};

struct tagPipePartsInfo {
    u16 partsID;
    u8 inWay;
    u8 goWay;
    s32 type;
};

struct tagPipeFileHeader {
    s32 posSize;
    s32 posAddr;
    s32 emSize;
    s32 emAddr;
    s32 linkSize;
    s32 linkAddr;
    s8 resv[8];
};
