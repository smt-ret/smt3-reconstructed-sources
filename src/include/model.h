#pragma once
#include "types.h"

typedef enum {
    P2A = 1,
    D3P = 2,
    TRACK = 3,
    BLUR = 4,
    IPU = 5,
    END = 65535,
} PIB_CHUNK_TYPE;

typedef enum {
    P2A = 0,
    D3P = 1,
    TRACK = 2,
    IPU = 3,
} dds3ModelEffectType;

typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3LightEditorWork_t dds3LightEditorWork_t;
typedef struct dds3ModelBlurCb_t dds3ModelBlurCb_t;
typedef struct dds3ModelBlurInstance_t dds3ModelBlurInstance_t;
typedef struct dds3ModelEffectCtrlr_t dds3ModelEffectCtrlr_t;
typedef struct dds3ModelFileIndex_t dds3ModelFileIndex_t;
typedef struct dds3ModelFileKindTable_t dds3ModelFileKindTable_t;
typedef struct dds3ModelFileTableDef_t dds3ModelFileTableDef_t;
typedef struct dds3ModelFileTable_t dds3ModelFileTable_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ModelResrcPlayBook_t dds3ModelResrcPlayBook_t;
typedef struct dds3ModelResrc_t dds3ModelResrc_t;
typedef struct mdlEffectResrcItem_t mdlEffectResrcItem_t;
typedef struct mdlEffectResrcList_t mdlEffectResrcList_t;
typedef struct mdlLoadingTag_t mdlLoadingTag_t;
typedef struct mdlSetDef_t mdlSetDef_t;
typedef struct pibChunkItem_BLUR_t pibChunkItem_BLUR_t;
typedef struct pibChunkItem_IPU_t pibChunkItem_IPU_t;
typedef struct pibChunkItem_P2A_D3P_t pibChunkItem_P2A_D3P_t;
typedef struct pibChunkItem_TRACK_t pibChunkItem_TRACK_t;
typedef struct pibChunkItem_t pibChunkItem_t;
typedef struct pibChunk_t pibChunk_t;
typedef struct pibHeaderChunk_t pibHeaderChunk_t;
typedef struct sdf3DLight_t sdf3DLight_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfModelDef_t sdfModelDef_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;
typedef struct sdfModelTexList_t sdfModelTexList_t;
typedef struct sdfMotionCtrlr_t sdfMotionCtrlr_t;
typedef struct sdfMotionPlayBook_t sdfMotionPlayBook_t;

struct dds3ModelHandle_t {
    u32 stat;
    dds3ModelHandle_t *next;
    dds3ModelHandle_t *prev;
    dds3ModelResrc_t *resrc;
    s16 motionMajorNum;
    s16 motionMinorNum;
    dds3ModelEffectCtrlr_t *effects;
    sdfModelRootNode_t *modelRoot;
    sdfMotionCtrlr_t *motionCtrlr;
    sdfMotionCtrlr_t *motions[4];
    dds3ModelBlurCb_t *blur;
    dds3Basic_t *Owner;
    f32 radius;
    sdf3DLight_t *uLight;
    sdfVector4_t uAmbient;
};

struct dds3ModelResrc_t {
    dds3ModelResrc_t *next;
    dds3ModelResrc_t *prev;
    u16 major;
    u16 minor;
    u8 autoFreeFlag;
    u8 *pad;
    dds3ModelHandle_t *models;
    sdfModelTexList_t *texList;
    sdfModelDef_t *modelDefPtr;
    sdfMemHandle_t *modelDefHandle;
    dds3ModelResrcPlayBook_t *playbooks[8];
    sdfMemHandle_t *effectMemHandle;
    void *effectData;
    mdlEffectResrcList_t *effectResrcList;
    f32 scale;
    f32 radius;
};

struct dds3ModelEffectCtrlr_t {
    dds3ModelEffectCtrlr_t *next;
    u16 type;
    s16 playGroup;
    void *handle;
    void *work;
    s32 mark_id;
    void *pTexture;
};

struct dds3ModelBlurCb_t {
    dds3ModelBlurInstance_t *instants;
    s16 spawnCount;
    s16 count;
    s16 interval;
    s16 intervalCount;
    s32 keepCount;
    sdfVector4_t colorBase;
    sdfVector4_t colorDelta;
};

struct mdlEffectResrcList_t {
    sdfMemHandle_t *memHandle;
    s16 count;
    s16 capacity;
    s16 elemSize;
    s16 growStep;
    void *items;
};

struct dds3ModelBlurInstance_t {
    dds3ModelBlurInstance_t *next;
    void *modelobj;
    s32 keepCount;
};

struct dds3ModelResrcPlayBook_t {
    s32 flags;
    s16 playGroup;
    s16 firstMotion;
    sdfMotionPlayBook_t *ptr;
    sdfMemHandle_t *handle;
};

struct mdlEffectResrcItem_t {
    u32 type;
    s32 count;
    void *handle;
    sdfMemHandle_t *memHandle;
    void *pTexture;
};

struct dds3LightEditorWork_t {
    sdf3DLight_t *lightSrc;
    sdfVector4_t ambientSrc;
    u8 *padSrc;
    u8 mode;
    u8 cursorTimer;
    s16 cursor;
    sdfDrawTag_t *drawTag;
};

struct dds3ModelFileTable_t {
    char *texFile;
    char *modelFile;
    char *motionFile;
    char *akey;
    char *fname;
};

struct dds3ModelFileTableDef_t {
    dds3ModelFileTable_t *fileTable;
    s32 numOfFile;
};

struct dds3ModelFileIndex_t {
    u16 major;
    u16 minor;
    s16 scale;
    u16 radius;
};

struct dds3ModelFileKindTable_t {
    dds3ModelFileIndex_t *indexTable;
    s32 numOfIndex;
};

struct mdlLoadingTag_t {
    mdlLoadingTag_t *next;
    s32 minor;
};

struct mdlSetDef_t {
    sdfModelTexList_t *texList;
    sdfModelDef_t *modelDefPtr;
    sdfMemHandle_t *modelDefHandle;
    sdfMotionPlayBook_t *playbookPtr;
    sdfMemHandle_t *playbookHandle;
    void *effectData;
    sdfMemHandle_t *effectMemHandle;
    mdlEffectResrcList_t *effectResrcList;
};

struct pibHeaderChunk_t {
    s32 group;
    u32 size;
    u32 version;
    u16 chunkCount;
    u16 effectCount;
    u16 motionCount;
    u16 pad;
};

struct pibChunk_t {
    s32 group;
    u32 size;
};

struct pibChunkItem_t {
    u32 type;
    u32 size;
};

struct pibChunkItem_P2A_D3P_t {
    s32 type;
    u32 size;
    u32 markId;
    u16 count;
    u16 effectIndex;
    f32 zOffset;
};

struct pibChunkItem_TRACK_t {
    s32 type;
    u32 size;
    u32 mark[2];
    u16 startFrame;
    u16 endFrame;
    u16 interval;
    u8 face;
    u8 blendAlgo;
    u32 colors[4];
};

struct pibChunkItem_BLUR_t {
    s32 type;
    u32 size;
    u16 interval;
    u16 count;
    u32 startColor;
    u32 endColor;
};

struct pibChunkItem_IPU_t {
    s32 type;
    u32 size;
    u32 texId;
    u32 startFrame;
    u8 fps;
    u8 loop;
    u16 effectIndex;
};
