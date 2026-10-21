#pragma once
#include "types.h"

typedef enum {
    SDF_OT_FUNC_SETUP = 0,
    SDF_OT_FUNC_LINK_TO_HEAD = 1,
} SdfOt;

typedef enum {
    SDF_FILE_DEVICE_CDVD = 0,
    SDF_FILE_DEVICE_HOST = 1,
    SDF_FILE_DEVICE_HDD = 2,
    SDF_FILE_DEVICE_CDIMG = 3,
} SdfFileDevice;

typedef enum {
    SDF_FILE_DEVICE_TYPE_CDVD = 0,
    SDF_FILE_DEVICE_TYPE_HOST = 1,
    SDF_FILE_DEVICE_TYPE_HDD = 2,
    SDF_FILE_DEVICE_TYPE_CDIMG = 3,
} SdfFileIODevice;

typedef enum {
    SDF_FILE_CMD_NONE = 0,
    SDF_FILE_CMD_READOPEN = 1,
    SDF_FILE_CMD_WRITEOPEN = 2,
    SDF_FILE_CMD_SEEK = 3,
    SDF_FILE_CMD_FILESIZE = 4,
    SDF_FILE_CMD_READ = 5,
    SDF_FILE_CMD_WRITE = 6,
    SDF_FILE_CMD_CLOSE = 7,
    SDF_FILE_CMD_READFILE = 8,
    SDF_FILE_CMD_WRITEFILE = 9,
} SdfFileIOCmd;

typedef enum {
    SDF_FILE_CMD_STAT_INIT = 0,
    SDF_FILE_CMD_STAT_DORMANT = 1,
    SDF_FILE_CMD_STAT_OPEN = 2,
    SDF_FILE_CMD_STAT_SEEK = 3,
    SDF_FILE_CMD_STAT_READ = 4,
    SDF_FILE_CMD_STAT_WRITE = 5,
    SDF_FILE_CMD_STAT_CLOSE = 6,
    SDF_FILE_CMD_STAT_SUSPEND = 7,
    SDF_FILE_CMD_STAT_DONE = 8,
    SDF_FILE_CMD_STAT_ERROR = 9,
    SDF_FILE_CMD_STAT_CANCEL = 10,
} SdfFileIOCmdStat;

typedef enum {
    SDF_FILE_CMD_CLBK_ERROR = 0,
    SDF_FILE_CMD_CLBK_CANCEL = 1,
    SDF_FILE_CMD_CLBK_OPEN = 2,
    SDF_FILE_CMD_CLBK_SEEK = 3,
    SDF_FILE_CMD_CLBK_FILESIZE = 4,
    SDF_FILE_CMD_CLBK_READ = 5,
    SDF_FILE_CMD_CLBK_WRITE = 6,
    SDF_FILE_CMD_CLBK_CLOSE = 7,
    SDF_FILE_CMD_CLBK_DONE = 8,
    SDF_FILE_CMD_CLBK_FREE = 9,
} SdfFileIOCmdClbk;

typedef enum {
    SDF_IMAGESET_MEM_IGNORE = 0,
    SDF_IMAGESET_MEM_HANDLE = 1,
    SDF_IMAGESET_MEM_CHIP = 2,
} SdfImageSetMem;

typedef enum {
    SDF_IPU_STRM_CB_GETLENG = 0,
    SDF_IPU_STRM_CB_GETDATA = 1,
    SDF_IPU_STRM_CB_FILLDATA = 2,
} SdfIpuStrm;

typedef enum {
    SDF_PAC_CB_ACT_READ = 0,
    SDF_PAC_CB_ACT_HOLD = 0,
    SDF_PAC_CB_ACT_END = 1,
    SDF_PAC_CB_ACT_SKIP = 2,
    SDF_PAC_CB_ACT_PASS = 3,
    SDF_PAC_CB_ACT_UNLINK = 4,
} SdfPacDecodePacCbAct;

typedef enum {
    SDF_PAC_CB_CAUSE_START = 0,
    SDF_PAC_CB_CAUSE_END = 1,
} SdfPacDecodePacCbCause;

typedef enum {
    SDF_PAC_STAT_END = -1,
    SDF_PAC_STAT_IDLE = 0,
    SDF_PAC_STAT_SKIP = 1,
    SDF_PAC_STAT_DECODE = 2,
} SdfPacDecodePacStat;

typedef enum {
    SDF_PADMAP_RL = 0,
    SDF_PADMAP_RR = 1,
    SDF_PADMAP_RU = 2,
    SDF_PADMAP_RD = 3,
    SDF_PADMAP_L = 4,
    SDF_PADMAP_R = 5,
    SDF_PADMAP_U = 6,
    SDF_PADMAP_D = 7,
    SDF_PADMAP_L1 = 8,
    SDF_PADMAP_L2 = 9,
    SDF_PADMAP_R1 = 10,
    SDF_PADMAP_R2 = 11,
    SDF_PADMAP_START = 12,
    SDF_PADMAP_SELECT = 13,
    SDF_PADMAP_L3 = 14,
    SDF_PADMAP_R3 = 15,
    SDF_PADMAP_COUNT = 16,
    RL = 0,
    RR = 1,
    RU = 2,
    RD = 3,
    L = 4,
    R = 5,
    U = 6,
    D = 7,
    L1 = 8,
    L2 = 9,
    R1 = 10,
    R2 = 11,
    START = 12,
    SELECT = 13,
    L3 = 14,
    R3 = 15,
    OPT2 = 0,
    OK = 1,
    OPT1 = 2,
    CANCEL = 3,
} SDF_PADMAP;

typedef enum {
    OPT2 = 0,
    OK = 1,
    OPT1 = 2,
    CANCEL = 3,
} SDF_PADMAP2;

typedef enum {
    SDF_HANDLER_INTC = 0,
    SDF_HANDLER_DMAC = 1,
    SDF_HANDLER_SBUS = 2,
} SdfSystemHandler;

typedef struct AB_HEADER_t AB_HEADER_t;
typedef struct MB_HEADER_t MB_HEADER_t;
typedef struct SpecularTex2 SpecularTex2;
typedef struct TB_HEADER_t TB_HEADER_t;
typedef struct TMX_HEADER_t TMX_HEADER_t;
typedef struct free_funcDelegate free_funcDelegate;
typedef struct p2sdIOPtoEEpkt p2sdIOPtoEEpkt;
typedef struct p2sdPosvect p2sdPosvect;
typedef struct p2sdSMGstatus p2sdSMGstatus;
typedef struct p2sdSubHandle p2sdSubHandle;
typedef struct p2sdadpcmheader p2sdadpcmheader;
typedef struct p2sdfileheader p2sdfileheader;
typedef struct p2sdsoundheader p2sdsoundheader;
typedef struct sdf2DSpriteParm_t sdf2DSpriteParm_t;
typedef struct sdf3DFogPacket_t sdf3DFogPacket_t;
typedef struct sdf3DFogParam_t sdf3DFogParam_t;
typedef struct sdf3DLightParallelPacket_t sdf3DLightParallelPacket_t;
typedef struct sdf3DLight_t sdf3DLight_t;
typedef struct sdf3DPrimPolyParm_t sdf3DPrimPolyParm_t;
typedef struct sdf3DScreenParam_t sdf3DScreenParam_t;
typedef struct sdf3DTmPacketData_t sdf3DTmPacketData_t;
typedef struct sdfBillBoard1Packet_t sdfBillBoard1Packet_t;
typedef struct sdfBillBoardTMPacket_t sdfBillBoardTMPacket_t;
typedef struct sdfBillBoardVc1Packet_t sdfBillBoardVc1Packet_t;
typedef struct sdfCdImageDirEntry_t sdfCdImageDirEntry_t;
typedef struct sdfChipInfo_t sdfChipInfo_t;
typedef struct sdfDecompCb_t sdfDecompCb_t;
typedef struct sdfDelayedResrcCB_t sdfDelayedResrcCB_t;
typedef struct sdfDelayedResrcChunk_t sdfDelayedResrcChunk_t;
typedef struct sdfDelayedResrcItems_t sdfDelayedResrcItems_t;
typedef struct sdfDevPrintCB_t sdfDevPrintCB_t;
typedef struct sdfDmaTag_t sdfDmaTag_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfFileCmdCB_t sdfFileCmdCB_t;
typedef struct sdfFileCmdCallback_t sdfFileCmdCallback_t;
typedef struct sdfFileCmdHandle_t sdfFileCmdHandle_t;
typedef struct sdfGifTag_t sdfGifTag_t;
typedef struct sdfGrCallPacketHeader_t sdfGrCallPacketHeader_t;
typedef struct sdfGrClearPacket_t sdfGrClearPacket_t;
typedef struct sdfGrDrawDefParmPacket_t sdfGrDrawDefParmPacket_t;
typedef struct sdfGrDrawDefParm_t sdfGrDrawDefParm_t;
typedef struct sdfGrDrawEnv_t sdfGrDrawEnv_t;
typedef struct sdfGrDrawFramePacket_t sdfGrDrawFramePacket_t;
typedef struct sdfGrDrawFrame_t sdfGrDrawFrame_t;
typedef struct sdfGrFramePacket_t sdfGrFramePacket_t;
typedef struct sdfGrFrameSet_t sdfGrFrameSet_t;
typedef struct sdfGrOt_t sdfGrOt_t;
typedef struct sdfGrOt_t_callbackFuncDelegate sdfGrOt_t_callbackFuncDelegate;
typedef struct sdfGrOt_t_regFuncDelegate sdfGrOt_t_regFuncDelegate;
typedef struct sdfGrPacketHeader_t sdfGrPacketHeader_t;
typedef struct sdfGrRefGifPacketHeader_t sdfGrRefGifPacketHeader_t;
typedef struct sdfGrRefPacketHeader_t sdfGrRefPacketHeader_t;
typedef struct sdfGrStdDrawEnv_t sdfGrStdDrawEnv_t;
typedef struct sdfGrStdDrawEnv_t_AnonymousClass sdfGrStdDrawEnv_t_AnonymousClass;
typedef struct sdfGrStdDrawEnv_t_AnonymousClass_AnonymousClass2 sdfGrStdDrawEnv_t_AnonymousClass_AnonymousClass2;
typedef struct sdfGrTagFOG_t sdfGrTagFOG_t;
typedef struct sdfGrTagPRIM_t sdfGrTagPRIM_t;
typedef struct sdfGrTagRGBA_t sdfGrTagRGBA_t;
typedef struct sdfGrTagSTQ_t sdfGrTagSTQ_t;
typedef struct sdfGrTagStdReg_t sdfGrTagStdReg_t;
typedef struct sdfGrTagUV_t sdfGrTagUV_t;
typedef struct sdfGrTagXYZ2_t sdfGrTagXYZ2_t;
typedef struct sdfGrTagXYZF2_t sdfGrTagXYZF2_t;
typedef struct sdfGsFrameBuff_t sdfGsFrameBuff_t;
typedef struct sdfGsMemSlice_t sdfGsMemSlice_t;
typedef struct sdfHandlerLink_t sdfHandlerLink_t;
typedef struct sdfIVector2_t sdfIVector2_t;
typedef struct sdfIVector3_t sdfIVector3_t;
typedef struct sdfIVector4_t sdfIVector4_t;
typedef struct sdfImageSetParm_t sdfImageSetParm_t;
typedef struct sdfIopLoadStartModuleParm_t sdfIopLoadStartModuleParm_t;
typedef struct sdfIopLoadStartModuleResult_t sdfIopLoadStartModuleResult_t;
typedef struct sdfIpuDecodeCb_t sdfIpuDecodeCb_t;
typedef struct sdfIpuInitParm_t sdfIpuInitParm_t;
typedef struct sdfIpuStrmCallback_t sdfIpuStrmCallback_t;
typedef struct sdfItemArray_t sdfItemArray_t;
typedef struct sdfLoadImagePacket_t sdfLoadImagePacket_t;
typedef struct sdfMatDef_t sdfMatDef_t;
typedef struct sdfMatList_t sdfMatList_t;
typedef struct sdfMatPacket_t sdfMatPacket_t;
typedef struct sdfMatUvwParm_t sdfMatUvwParm_t;
typedef struct sdfMat_t sdfMat_t;
typedef struct sdfMatrix2_t sdfMatrix2_t;
typedef struct sdfMatrix3_t sdfMatrix3_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfMemInfo_t sdfMemInfo_t;
typedef struct sdfModelDef_t sdfModelDef_t;
typedef struct sdfModelDrawEnv_t sdfModelDrawEnv_t;
typedef struct sdfModelDrawEnv_t_AnonymousClass sdfModelDrawEnv_t_AnonymousClass;
typedef struct sdfModelDrawEnv_t_AnonymousClass2 sdfModelDrawEnv_t_AnonymousClass2;
typedef struct sdfModelExtraChunkMarkPos_t sdfModelExtraChunkMarkPos_t;
typedef struct sdfModelExtraChunk_t sdfModelExtraChunk_t;
typedef struct sdfModelMorphList_t sdfModelMorphList_t;
typedef struct sdfModelMorphParm_t sdfModelMorphParm_t;
typedef struct sdfModelMorph_t sdfModelMorph_t;
typedef struct sdfModelNodeDef_t sdfModelNodeDef_t;
typedef struct sdfModelNodeList_t sdfModelNodeList_t;
typedef struct sdfModelNode_t sdfModelNode_t;
typedef struct sdfModelOt_t sdfModelOt_t;
typedef struct sdfModelPacketHeader_tag sdfModelPacketHeader_tag;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;
typedef struct sdfModelTexList_t sdfModelTexList_t;
typedef struct sdfMotCLBK_BlendSeek_t sdfMotCLBK_BlendSeek_t;
typedef struct sdfMotCLBK_Destroy_t sdfMotCLBK_Destroy_t;
typedef struct sdfMotCLBK_InitBlend_t sdfMotCLBK_InitBlend_t;
typedef struct sdfMotCLBK_Seek_t sdfMotCLBK_Seek_t;
typedef struct sdfMotCLBK_SetCut_t sdfMotCLBK_SetCut_t;
typedef struct sdfMotionCtrlr_t sdfMotionCtrlr_t;
typedef struct sdfMotionCutChunk_t sdfMotionCutChunk_t;
typedef struct sdfMotionCutDef_t sdfMotionCutDef_t;
typedef struct sdfMotionNodeDef_t sdfMotionNodeDef_t;
typedef struct sdfMotionNodeList_t sdfMotionNodeList_t;
typedef struct sdfMotionNodeVTBL_t sdfMotionNodeVTBL_t;
typedef struct sdfMotionNode_t sdfMotionNode_t;
typedef struct sdfMotionPlayBook_t sdfMotionPlayBook_t;
typedef struct sdfMovieCb_t sdfMovieCb_t;
typedef struct sdfMovieInitParm_t sdfMovieInitParm_t;
typedef struct sdfMultiBillBoard1Packet_t sdfMultiBillBoard1Packet_t;
typedef struct sdfMultiBillBoardVc1Packet_t sdfMultiBillBoardVc1Packet_t;
typedef struct sdfPacCallback_t sdfPacCallback_t;
typedef struct sdfPacDecodeCb_t sdfPacDecodeCb_t;
typedef struct sdfPacDecodeFunc_t sdfPacDecodeFunc_t;
typedef struct sdfPacDecodeResrc_t sdfPacDecodeResrc_t;
typedef struct sdfPacStdBlockHeader_t sdfPacStdBlockHeader_t;
typedef struct sdfPreDrawChain_t sdfPreDrawChain_t;
typedef struct sdfPreDrawHook_t sdfPreDrawHook_t;
typedef struct sdfPreDrawHook_t_predrawFuncDelegate sdfPreDrawHook_t_predrawFuncDelegate;
typedef struct sdfPreDrawTag_t sdfPreDrawTag_t;
typedef struct sdfPrimBitBltElem_t sdfPrimBitBltElem_t;
typedef struct sdfPrimBitBltPacket_t sdfPrimBitBltPacket_t;
typedef struct sdfPrimBoxLineElem_t sdfPrimBoxLineElem_t;
typedef struct sdfPrimBoxLinePacket_t sdfPrimBoxLinePacket_t;
typedef struct sdfPrimF3Elem_t sdfPrimF3Elem_t;
typedef struct sdfPrimF3Packet_t sdfPrimF3Packet_t;
typedef struct sdfPrimF4Elem_t sdfPrimF4Elem_t;
typedef struct sdfPrimF4Packet_t sdfPrimF4Packet_t;
typedef struct sdfPrimFrameMovePacket_t sdfPrimFrameMovePacket_t;
typedef struct sdfPrimFt3Elem_t sdfPrimFt3Elem_t;
typedef struct sdfPrimFt3Packet_t sdfPrimFt3Packet_t;
typedef struct sdfPrimFt4Elem_t sdfPrimFt4Elem_t;
typedef struct sdfPrimFt4Packet_t sdfPrimFt4Packet_t;
typedef struct sdfPrimG3Elem_t sdfPrimG3Elem_t;
typedef struct sdfPrimG3Packet_t sdfPrimG3Packet_t;
typedef struct sdfPrimG4Elem_t sdfPrimG4Elem_t;
typedef struct sdfPrimG4Packet_t sdfPrimG4Packet_t;
typedef struct sdfPrimGt3Elem_t sdfPrimGt3Elem_t;
typedef struct sdfPrimGt3Packet_t sdfPrimGt3Packet_t;
typedef struct sdfPrimGt4Elem_t sdfPrimGt4Elem_t;
typedef struct sdfPrimGt4Packet_t sdfPrimGt4Packet_t;
typedef struct sdfPrimLineElem_t sdfPrimLineElem_t;
typedef struct sdfPrimLinePacket_t sdfPrimLinePacket_t;
typedef struct sdfPrimRectElem_t sdfPrimRectElem_t;
typedef struct sdfPrimRectPacket_t sdfPrimRectPacket_t;
typedef struct sdfPrimSpriteElem_t sdfPrimSpriteElem_t;
typedef struct sdfPrimSpritePacket_t sdfPrimSpritePacket_t;
typedef struct sdfPrimTexflushPacket_t sdfPrimTexflushPacket_t;
typedef struct sdfPrimTransElem_t sdfPrimTransElem_t;
typedef struct sdfPrimTransPacket_t sdfPrimTransPacket_t;
typedef struct sdfPrm sdfPrm;
typedef struct sdfRandCB_t sdfRandCB_t;
typedef struct sdfSVector2_t sdfSVector2_t;
typedef struct sdfSVector3_t sdfSVector3_t;
typedef struct sdfSVector4_t sdfSVector4_t;
typedef struct sdfShape_t sdfShape_t;
typedef struct sdfSndMap_t sdfSndMap_t;
typedef struct sdfSndReqPlayInfo_t sdfSndReqPlayInfo_t;
typedef struct sdfSndReqSeInfo_t sdfSndReqSeInfo_t;
typedef struct sdfSndSeqInfo_t sdfSndSeqInfo_t;
typedef struct sdfSndSeqMap_t sdfSndSeqMap_t;
typedef struct sdfSndVoiceInfo_t sdfSndVoiceInfo_t;
typedef struct sdfSndVoiceMap_t sdfSndVoiceMap_t;
typedef struct sdfStoreFrameImagePacket_t sdfStoreFrameImagePacket_t;
typedef struct sdfStoreImagePacket_t sdfStoreImagePacket_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;
typedef struct sdfTexMapCB_t sdfTexMapCB_t;
typedef struct sdfTexMapPacket_t sdfTexMapPacket_t;
typedef struct sdfTexPacket_t sdfTexPacket_t;
typedef struct sdfThCB_t sdfThCB_t;
typedef struct sdfTime_t sdfTime_t;

struct sdfModelOt_t {
    sdfGrOt_t *ot[4];
};

struct sdfModelRootNode_t {
    sdfModelNodeList_t *nodeList;
    sdfModelNode_t *headNode;
    sdfModelTexList_t *texList;
    sdfMatList_t *matList;
    sdfModelMorphList_t *morphList;
    sdfMotionCtrlr_t *motion;
    u8 complexNodeId;
    u8 flags;
    u16 drawAttr;
    u32 color;
    sdfMatrix4_t tm;
    sdfVector4_t rotate;
    sdfVector4_t scale;
    void *light;
    void *fog;
    f32 faceDivSoften;
    f32 faceDivBias;
    void *extraData;
    f32 zBias;
    void *modelobj;
    void *oData;
    s32 effpos_type;
    s32 reversePB;
};

struct sdfMotionCtrlr_t {
    sdfMotionCtrlr_t *next;
    sdfModelRootNode_t *rootNode;
    sdfMotionPlayBook_t *playbook;
    sdfMemHandle_t *playbookMemHandle;
    sdfMotionNodeList_t *nodeList;
    f32 blendLength;
    f32 blendPreLength;
    f32 frame;
    f32 speed;
    void *userData;
    s16 userId;
    s16 userId2;
    u16 cutNumber;
    u16 frameLength;
    u8 stat;
    u8 statBeforePause;
    u8 playType;
};

struct sdfModelTexList_t {
    sdfMemHandle_t *memHandle;
    s16 count;
    s16 capacity;
    s16 elemSize;
    s16 growStep;
    sdfTexHandle_t *items;
};

struct sdfModelDef_t {
    s32 modelDef;
    void *matDef_Old;
    s32 count;
    sdfMatDef_t *matDef_New;
    u32 morphCount;
    void *extraData;
    sdfModelNodeDef_t *nodeDef;
};

struct sdfMemHandle_t {
    sdfMemHandle_t *prev;
    sdfMemHandle_t *next;
    void *ptr;
    u16 stat;
    u16 mlock;
};

struct sdfModelNodeList_t {
    sdfMemHandle_t *memHandle;
    s16 count;
    s16 capacity;
    s16 elemSize;
    s16 growStep;
    sdfModelNode_t *items;
};

struct sdfModelNode_t {
    sdfModelNode_t *prev;
    sdfModelNode_t *next;
    sdfModelNode_t *parent;
    sdfModelNode_t *children;
    sdfModelRootNode_t *root;
    u16 flags;
    u16 drawAttr;
    u32 id;
    u32 color;
    sdfMemHandle_t *drawPacketMemHandle[2];
    sdfModelPacketHeader_tag *drawPacket;
    void *tmPacket;
    f32 bounds;
    sdfModelNodeDef_t *shape;
    u32 pad0;
    void *userData;
    u32 pad1[3];
    sdfVector4_t rotate;
    sdfVector4_t pos;
    sdfVector4_t scale;
    sdfMatrix4_t localNoScaledTm;
    sdfMatrix4_t tm;
};

struct sdfMatList_t {
    sdfMemHandle_t *memHandle;
    s16 count;
    s16 capacity;
    s16 elemSize;
    s16 growStep;
    sdfMat_t *items;
};

struct sdfModelMorphList_t {
    sdfMemHandle_t *memHandle;
    s16 count;
    s16 capacity;
    s16 elemSize;
    s16 growStep;
    sdfModelMorph_t *items;
    sdfModelMorph_t *items2;
};

struct sdfMotionPlayBook_t {
    u16 numOfCut;
    u16 numOfNode;
    sdfMotionCutDef_t *cutList;
    sdfMotionNodeDef_t nodeDefList[1];
};

struct sdfMotionNodeList_t {
    sdfMemHandle_t *memHandle;
    s16 count;
    s16 capacity;
    s16 elemSize;
    s16 growStep;
    sdfMotionNode_t *items;
};

struct sdf3DLight_t {
    sdfVector4_t color;
    sdfVector4_t v;
    sdfVector4_t p;
    f32 param[4];
};

struct sdfGrOt_t {
    sdfGrOt_t *next;
    sdfDrawTag_t *tagHead;
    sdfDrawTag_t *tagTail;
    sdfDrawTag_t *noSortTag;
    sdfGrOt_t_regFuncDelegate *regFunc;
    sdfGrOt_t_callbackFuncDelegate *callbackFunc;
    void *data;
    u32 pad;
};

struct sdfTexHandle_t {
    sdfTexHandle_t *prev;
    sdfTexHandle_t *next;
    sdfTexHandle_t *origin;
    s16 width;
    s16 height;
    sdfGsMemSlice_t *pixelGsHandle;
    sdfGsMemSlice_t *clutGsHandle;
    u8 numOfCLUT;
    u8 CLUTFormat;
    u8 pixelFormat;
    u8 numOfMipmap;
    u16 mipmapParam;
    u8 flags;
    u8 texWrapMode;
    u32 texId;
    u32 clutId;
    void *packet;
    void *packetCtx2;
    void *clutData;
    u32 clutDataSize;
    u32 clutColor;
    u8 monoClutData;
    char *hashname;
    void *image;
};

struct sdfMatDef_t {
    u32 id;
    u16 flags;
    u16 parmBits;
};

struct sdfModelNodeDef_t {
    u16 format;
    u16 pad0;
    u32 pad1;
    u32 id;
    s32 parentIndex;
    sdfVector4_t rotate;
    sdfVector4_t pos;
    sdfVector4_t scale;
    f32 bounds;
    void *shape[3];
};

struct sdfModelMorph_t {
    sdfModelMorphParm_t target[2];
};

struct sdfDrawTag_t {
    sdfDrawTag_t *next;
    sdfGrPacketHeader_t *head;
    sdfGrPacketHeader_t *tail;
    f32 z;
    void *lightPacket;
    void *fogPacket;
    void *texPacket[2];
};

struct sdfGsMemSlice_t {
    sdfGsMemSlice_t *prev;
    sdfGsMemSlice_t *next;
    s32 type;
    u32 addr;
    s32 size;
    s16 w;
    s16 h;
    u32 pixelFormat;
};

struct sdfModelPacketHeader_tag {
    sdfModelPacketHeader_tag *next;
    u8 type;
    u8 otIndex;
    u16 size;
    void *dataPtr;
    sdfMemHandle_t *memHandle;
};

struct sdfMat_t {
    u32 id;
    u16 flags;
    u8 duty;
    u8 pad;
    sdfMatPacket_t *packet[2];
    u32 ambient;
    u32 diffuse;
    u32 multiTexDiffuse;
    f32 constant;
    u32 specular;
    u32 specularParm;
    u32 refmap;
    sdfTexHandle_t *texHandle;
    sdfTexHandle_t *multiTexHandle;
    u32 multiTexMethod;
    sdfMatUvwParm_t *uvwParm;
    sdfMatUvwParm_t *multiTexUvwParm;
    f32 fdBias;
    f32 fdSoften;
};

struct sdfMotionCutDef_t {
    u32 frameLength;
    sdfMotionCutChunk_t *cutChunk;
};

struct sdfMotionNodeDef_t {
    u32 typeId;
    u32 nodeId;
};

struct sdfMotionNode_t {
    sdfMotionNodeVTBL_t *vtbl;
    sdfMotionCtrlr_t *owner;
    sdfMotionCutChunk_t *table;
};

struct sdfGrPacketHeader_t {
    sdfDmaTag_t *dmatag;
    sdfGifTag_t giftag;
    sdfPrm *primitive;
};

struct sdfMatUvwParm_t {
    f32 offset[2];
    f32 tile[2];
    f32 angle;
    f32 pad;
};

struct sdfModelMorphParm_t {
    u32 targetId;
    f32 blend;
};

struct sdfMotionNodeVTBL_t {
    sdfMotCLBK_Destroy_t *destroy;
    sdfMotCLBK_SetCut_t *setCut;
    sdfMotCLBK_Seek_t *seek;
    sdfMotCLBK_InitBlend_t *initBlend;
    sdfMotCLBK_BlendSeek_t *blendSeek;
};

struct sdfMotionCutChunk_t {
    u32 size;
    u16 numOfKey;
    u16 keyElemSize;
    u32 pad;
    u16 *keyFrameList;
};

struct sdfDmaTag_t {
    u16 qwc;
    u8 pad;
    u8 id;
    void *addr;
    u32 dat0;
    u32 dat1;
};

struct sdfGifTag_t {
    u64 parm;
    u64 regs;
};

struct sdfPrm {
    u64 l;
    u8 b1;
    u8 b2;
    u8 b3;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    u8 b8;
    u16 s1;
    u16 s2;
    u16 s3;
    u16 s4;
    u32 i1;
    u32 i2;
    f32 f1;
    f32 f2;
};

struct sdfMatPacket_t {
    u32 vifcode0;
    u32 ambient;
    u32 diffuse;
    u32 mtexDiffuse;
    u32 specularColor;
    u32 refmapColor;
    u32 vifcode1;
    f32 constant;
    u32 mtexAlpha;
    u32 mtexAlgo;
    f32 fdBias;
    f32 fdSoften;
    u32 pad;
    u32 vifcode2;
    u64 tex1Data;
    u64 tex0Data;
    u64 clampData;
    u64 mtexTex1Data;
    u64 mtexTex0Data;
    u64 mtexClampData;
    f32 ***texTm;
    u32 cmd_call_spec;
    u32 cmd_call_kind;
};

struct sdfGrTagStdReg_t {
    u64 data;
    u64 reg;
};

struct sdf3DLightParallelPacket_t {
    sdfDmaTag_t dmatag;
    sdfVector4_t normal[3];
    sdfVector4_t colorBase;
    sdfVector4_t color[5];
    sdfMatrix4_t TM;
};

struct sdfGrTagRGBA_t {
    s32 r;
    s32 g;
    s32 b;
    s32 a;
};

struct sdfGrTagXYZ2_t {
    s32 x;
    s32 y;
    s32 z;
    u16 adc;
    u16 pad;
};

struct sdfPacDecodeCb_t {
    s8 stat;
    u8 flag;
    s16 currBlockNum;
    sdfPacCallback_t *callback;
    sdfPacDecodeFunc_t *decoder;
    sdfPacDecodeFunc_t *onEnd;
    void *srcData;
    s32 src_ptr;
    s32 srcLength;
    s32 srcTotal;
    void *workPtr;
    s32 work_ptr;
    s32 rest;
    void *decompWork;
    void *decodeCb;
    void *decodeWork;
    sdfPacDecodeResrc_t *resrcCurr;
    sdfPacDecodeResrc_t *resrcHead;
    sdfPacDecodeResrc_t *resrcTail;
};

struct sdfFileCmdHandle_t {
    sdfFileCmdHandle_t *next;
    sdfFileCmdHandle_t *prev;
    sdfFileCmdHandle_t *deviceNext;
    sdfFileCmdHandle_t *devicePrev;
    u16 *filename;
    u8 device;
    u8 cmd;
    s8 stat;
    s8 phase;
    s16 offset;
    s16 length;
    void *buffer;
    u32 cmdParm;
    s32 fd;
    s32 errorCode;
    u32 currentOffset;
    u32 remainder;
    sdfFileCmdCallback_t *callback;
    void *userData;
};

struct sdfPacDecodeResrc_t {
    sdfPacDecodeResrc_t *next;
    sdfPacDecodeCb_t *cb;
    void *handle;
    void *ptr;
    s32 head_index;
    sdfPacStdBlockHeader_t *header;
};

struct sdfPacStdBlockHeader_t {
    u8 fileType;
    u8 compression;
    u16 userId;
    u32 size;
    u32 magicCode;
    u32 realSize;
    u32 head_addr;
    u8 *compdata;
};

struct sdfIVector2_t {
    s32 pm[2];
};

struct sdfRandCB_t {
    u32 v[4];
};

struct sdfPreDrawTag_t {
    sdfPreDrawTag_t *next;
    sdfPreDrawHook_t *head;
    sdfPreDrawHook_t *tail;
    u32 pad;
};

struct sdfGrStdDrawEnv_t {
    sdfPreDrawHook_t *worker;
    sdfGrPacketHeader_t *header;
    sdfGrDrawDefParmPacket_t *defParm;
    sdfGrDrawFramePacket_t *frame1;
    sdfGrDrawFramePacket_t *frame2;
    sdfGrClearPacket_t *clear;
    sdfGrTagStdReg_t *test1;
    sdfGrTagStdReg_t *alpha1;
    sdfGrTagStdReg_t *test2;
    sdfGrTagStdReg_t *alpha2;
    sdfGrStdDrawEnv_t_AnonymousClass *ext;
};

struct sdfGrDrawEnv_t {
    sdfGrPacketHeader_t header;
    sdfGrDrawDefParmPacket_t defParm;
    sdfGrDrawFramePacket_t frame1;
    sdfGrDrawFramePacket_t frame2;
    sdfGrClearPacket_t clear;
    sdfGrTagStdReg_t test1;
    sdfGrTagStdReg_t alpha1;
    sdfGrTagStdReg_t test2;
    sdfGrTagStdReg_t alpha2;
};

struct sdfModelDrawEnv_t {
    sdfModelDrawEnv_t_AnonymousClass set[4];
    sdfModelDrawEnv_t_AnonymousClass2 *term;
};

struct sdfPreDrawHook_t {
    sdfPreDrawHook_t *next;
    sdfPreDrawHook_t_predrawFuncDelegate *predrawFunc;
    u32 option0;
    u32 option1;
};

struct sdfGrDrawDefParmPacket_t {
    sdfGrTagStdReg_t prmodecont;
    sdfGrTagStdReg_t colclamp;
    sdfGrTagStdReg_t dthe;
    sdfGrTagStdReg_t texa;
};

struct sdfGrDrawFramePacket_t {
    sdfGrTagStdReg_t frame;
    sdfGrTagStdReg_t zbuf;
    sdfGrTagStdReg_t xyoffset;
    sdfGrTagStdReg_t scissor;
};

struct sdfGrClearPacket_t {
    sdfGrTagStdReg_t test;
    sdfGrTagStdReg_t prim;
    sdfGrTagStdReg_t rgbaq;
    sdfGrTagStdReg_t xyzA;
    sdfGrTagStdReg_t xyzB;
};

struct sdfGrStdDrawEnv_t_AnonymousClass {
    sdfGrStdDrawEnv_t_AnonymousClass_AnonymousClass2 *alphaMask;
    sdfTexPacket_t *dispTex;
    sdfTexPacket_t *drawTex;
};

struct sdfModelDrawEnv_t_AnonymousClass2 {
    sdfDrawTag_t *drawTag;
    sdfDmaTag_t *footer;
};

struct sdfGrStdDrawEnv_t_AnonymousClass_AnonymousClass2 {
    sdfGrTagStdReg_t *frame1;
    sdfGrTagStdReg_t *frame2;
};

struct sdfTexPacket_t {
    sdfGifTag_t giftag;
    sdfGrTagStdReg_t tex1;
    sdfGrTagStdReg_t tex0;
    sdfGrTagStdReg_t clamp;
};

struct sdfModelDrawEnv_t_AnonymousClass {
    sdfDrawTag_t *drawTag;
    sdfPrimTransPacket_t *transPacket;
};

struct sdfPrimTransPacket_t {
    sdfGrPacketHeader_t header;
    sdfPrimTransElem_t *trans;
};

struct sdfPrimTransElem_t {
    sdfGrTagStdReg_t test;
    sdfGrTagStdReg_t alpha;
};

struct sdf3DPrimPolyParm_t {
    s16 faceCount;
    s16 pointCount;
    u16 attr;
    u16 attrInhibit;
    u32 color;
    u32 *faceIndex;
    sdfVector4_t *vertex;
    sdfVector4_t *normal;
    sdfVector2_t *uv;
    sdfVector2_t *multiUv;
    u32 *vertexColor;
    void *allocator;
    f32 zBias;
};

struct sdf3DFogParam_t {
    f32 fogMax;
    f32 fogMin;
    f32 fogNear;
    f32 fogFar;
    u32 color;
};

struct sdfIVector4_t {
    s32 pm[4];
};

struct sdfGrTagUV_t {
    s32 u;
    s32 v;
    u64 pad;
};

struct sdfImageSetParm_t {
    void *data;
    sdfMemHandle_t *dataMemHandle;
    u8 dataMemMode;
    u8 pixelFormat;
    u16 dstBuffWidth;
    u32 gsAddr;
    u16 dstX;
    u16 dstY;
    u16 width;
    u16 height;
};

struct sdf3DScreenParam_t {
    u32 flags;
    f32 aspect;
    f32 projDist;
    f32 fovy;
    f32 ox;
    f32 oy;
    f32 width;
    f32 height;
    f32 zMin;
    f32 zMax;
    f32 nearClip;
    f32 farClip;
    sdfMatrix4_t TM;
    sdfVector4_t scale;
    sdfVector4_t trans;
    sdfVector4_t cameraPos;
};

struct sdfDecompCb_t {
    u8 stat;
    u8 direc;
    u16 direcLeng;
    u8 *dstPtr;
    void *srcPtr;
    u32 srcRemain;
    u8 sdOfs;
    u8 pad0[3];
    u32 pad1[3];
};

struct sdf3DFogPacket_t {
    sdfDmaTag_t dmatag;
    f32 fogParm[4];
    sdfGifTag_t giftag;
    sdfGrTagStdReg_t fogColor;
    u32 mscal;
    u32 pad[3];
};

struct sdfCdImageDirEntry_t {
    u32 nameOffset_;
    u32 offset_;
    s32 size_;
};

struct sdfDelayedResrcCB_t {
    free_funcDelegate *freeFuncPtr;
    sdfDelayedResrcChunk_t *chunk;
};

struct sdfDelayedResrcChunk_t {
    sdfDelayedResrcChunk_t *next;
    sdfDelayedResrcCB_t *owner;
    sdfDelayedResrcItems_t *items;
    s32 itemsFreeCount;
};

struct sdfDelayedResrcItems_t {
    sdfDelayedResrcItems_t *next;
    void *items[63];
};

struct sdfThCB_t {
    sdfThCB_t *next;
    s32 thId;
};

struct sdfIpuDecodeCb_t {
    sdfIpuDecodeCb_t *prev;
    sdfIpuDecodeCb_t *next;
    sdfIpuDecodeCb_t *taskNext;
    u8 type;
    u8 queueLinked;
    u8 init;
    u8 end;
    u8 drawStart;
    u8 toIpuDmaActive;
    u8 toIpuDmaSuspend;
    u8 imageTrans;
    u8 rgbMode;
    u8 loopMode;
    u8 fps;
    u8 drawTick;
    u8 buffId;
    u8 getBuffId;
    u8 activeBuffCount;
    s32 buffSize;
    s32 bltPacketSize;
    u32 gsAddr;
    sdfGsMemSlice_t *gsHandle;
    u16 width;
    u16 height;
    s32 frameCount;
    s32 encodeFrame;
    s32 frame;
    void *toIpuDmaTag;
    u8 strmInitFlag;
    u8 strmBuffEndFlag;
    u8 strmBuffActiveChunk;
    u8 strmBuffIndex;
    u8 strmBuffTop;
    sdfMemHandle_t *strmBuffMemHandle;
    sdfIpuStrmCallback_t *strmCallback;
    void *strmCallbackParm;
    u8 strmToIpuDmaStep;
    u8 firstFrame;
    u8 pad[2];
};

struct sdfHandlerLink_t {
    sdfHandlerLink_t *next;
    s32 type;
    s32 cause;
    s32 id;
};

struct sdfIpuStrmCallback_t {
    sdfIpuDecodeCb_t *cb;
    intptr_t userdata;
    s32 cause;
    intptr_t argp;
    s32 argi;
};

struct sdf3DTmPacketData_t {
    sdfVector4_t tm[7];
    u32 cmd[4];
};

struct sdfSndMap_t {
    u32 numOfVoice;
    u32 numOfSeq;
    void *readBuff;
    u32 readBuffSize;
    sdfSndVoiceMap_t *voiceMap[16];
    sdfSndSeqMap_t *seqMap[16];
    p2sdSMGstatus *smg[7];
    void *returnAddr;
    u32 returnSize;
    void *TransBufAddr;
    s32 TransBufSize;
    s32 error_count;
    s32 last_error;
    u8 *dbg_voltbl_f[7];
    u8 *dbg_vostat_f[2];
};

struct p2sdPosvect {
    u32 reqno;
    u32 limit;
    s32 cx;
    s32 cy;
    s32 cz;
    s32 px;
    s32 py;
    s32 pz;
};

struct p2sdIOPtoEEpkt {
    u32 command;
    u32 src;
    u32 dst;
    u32 size;
};

struct sdfSndVoiceMap_t {
    u8 priority;
    u8 polyCount;
    u16 iopSize;
    u32 spuSize;
    void *iopAddr;
    void *spuAddr;
};

struct sdfSndSeqMap_t {
    u32 iopSize;
    void *iopAddr;
};

struct p2sdSMGstatus {
    s32 reqno;
    u8 totaltimes;
    u8 bgmtimes;
};

struct sdfTime_t {
    u8 pad;
    u8 sec;
    u8 min;
    u8 hour;
    u8 day;
    u8 month;
    u16 year;
};

struct sdfModelExtraChunkMarkPos_t {
    s32 nodeId;
    s32 id;
    u32 param;
    u32 pad1;
    sdfVector4_t pos;
    sdfVector4_t forward;
    sdfVector4_t up;
    void *obj;
};

struct sdfMovieInitParm_t {
    s32 x;
    s32 y;
    u32 z;
    s32 width;
    s32 height;
    u8 rgbMode;
    u8 ditherMode;
    u8 fps;
    u8 pad;
};

struct sdfMovieCb_t {
    u8 stat;
    u8 readStat;
    u8 cancel;
    u8 mode;
    s16 x;
    s16 y;
    u32 z;
    s16 width;
    s16 height;
    sdfFileCmdHandle_t *fileHandle;
    s32 fileSize;
    s32 readRemain;
    void *readCb;
    u8 sndActive;
    u8 sndPlaying;
    u8 sndVolume;
    u8 reserve;
    sdfIpuDecodeCb_t *decodeCb;
};

struct sdfGrRefPacketHeader_t {
    sdfDmaTag_t *reftag;
    sdfDmaTag_t *linktag;
};

struct sdfGrRefGifPacketHeader_t {
    sdfDmaTag_t *dmatag;
    sdfGifTag_t *giftag;
    sdfDmaTag_t *reftag;
    sdfDmaTag_t *linktag;
};

struct sdfGrCallPacketHeader_t {
    sdfDmaTag_t *calltag;
    sdfDmaTag_t *linktag;
};

struct sdfPreDrawChain_t {
    sdfPreDrawTag_t *tagHead;
    sdfPreDrawTag_t *tagTail;
    u32 pad[2];
};

struct sdfGrDrawDefParm_t {
    sdfGrPacketHeader_t *header;
    sdfGrDrawDefParmPacket_t *packet;
};

struct sdfGrDrawFrame_t {
    sdfGrPacketHeader_t *header;
    sdfGrDrawFramePacket_t *packet;
};

struct sdfGrFramePacket_t {
    sdfPreDrawHook_t *worker;
    sdfGrPacketHeader_t *header;
    sdfGrTagStdReg_t *frame;
    sdfGrTagStdReg_t *zbuff;
    sdfGrFrameSet_t *frameSet;
    u32 frameMask;
    u32 zbuffMask;
    u32 context;
};

struct sdfGrFrameSet_t {
    s16 w;
    s16 h;
    s16 buffH;
    u8 pixelFormat;
    u8 zbuffFormat;
    sdfGsMemSlice_t *frameHandle[2];
    sdfGsMemSlice_t *zbuffHandle;
};

struct sdfGsFrameBuff_t {
    sdfGsMemSlice_t *slice;
    s32 pad2;
};

struct sdfGrTagPRIM_t {
    u32 prim;
    u32 pad1;
    u64 pad2;
};

struct sdfGrTagSTQ_t {
    f32 s;
    f32 t;
    f32 q;
    u32 pad;
};

struct sdfGrTagXYZF2_t {
    s32 x;
    s32 y;
    s32 z;
    u16 f;
    u16 pad;
};

struct sdfGrTagFOG_t {
    u64 pad1;
    u32 pad2;
    u16 f;
    u16 pad3;
};

struct SpecularTex2 {
    TMX_HEADER_t *header;
    u32 *clut;
    u8 **pixel;
};

struct TMX_HEADER_t {
    u8 fileType;
    u8 compression;
    s16 userId;
    s32 fileSize;
    u32 formatId;
    s32 realSize;
    u8 numOfCLUT;
    u8 CLUTFormat;
    s16 width;
    s16 height;
    u8 pixelFormat;
    u8 numOfMipmap;
    u16 mipmapParam;
    u8 flags;
    u8 texWrapMode;
    u8 *userArea;
    u8 *comment;
};

struct sdfModelExtraChunk_t {
    u32 chunkId;
    u32 size;
    u32 data0;
    u32 data1;
    s32 sPos;
};

struct sdfPrimTexflushPacket_t {
    sdfGrPacketHeader_t header;
    sdfGrTagStdReg_t texflush;
};

struct sdfPrimBitBltElem_t {
    sdfGrTagStdReg_t bitbltbuf;
    sdfGrTagStdReg_t trxpos;
    sdfGrTagStdReg_t trxreg;
    sdfGrTagStdReg_t trxdir;
};

struct sdfPrimBitBltPacket_t {
    sdfGrPacketHeader_t header;
    sdfPrimBitBltElem_t bitblt;
};

struct sdfPrimFrameMovePacket_t {
    sdfPreDrawHook_t *worker;
    sdfPrimBitBltPacket_t *packet;
};

struct sdfPrimSpriteElem_t {
    sdfGifTag_t *giftag;
    u64 prim;
    u64 rgbaq;
    u64 uv0;
    u64 xy0;
    u64 uv1;
    u64 xy1;
};

struct sdfPrimSpritePacket_t {
    sdfDmaTag_t *dmatag;
    sdfPrimSpriteElem_t *spr;
};

struct sdfPrimF3Elem_t {
    sdfGifTag_t *giftag;
    u64 prim;
    u64 rgbaq;
    u64 xy0;
    u64 xy1;
    u64 xy2;
    u64 nop;
};

struct sdfPrimF3Packet_t {
    sdfDmaTag_t *dmatag;
    sdfPrimF3Elem_t *elem;
};

struct sdfPrimF4Elem_t {
    sdfGifTag_t *giftag;
    u64 prim;
    u64 rgbaq;
    u64 xy0;
    u64 xy1;
    u64 xy2;
    u64 xy3;
};

struct sdfPrimF4Packet_t {
    sdfDmaTag_t *dmatag;
    sdfPrimF4Elem_t *elem;
};

struct sdfPrimG3Elem_t {
    sdfGifTag_t *giftag;
    u64 prim;
    u64 rgbaq0;
    u64 xy0;
    u64 rgbaq1;
    u64 xy1;
    u64 rgbaq2;
    u64 xy2;
    u64 nop;
};

struct sdfPrimG3Packet_t {
    sdfDmaTag_t *dmatag;
    sdfPrimG3Elem_t *elem;
};

struct sdfPrimG4Elem_t {
    sdfGifTag_t *giftag;
    u64 prim;
    u64 rgbaq0;
    u64 xy0;
    u64 rgbaq1;
    u64 xy1;
    u64 rgbaq2;
    u64 xy2;
    u64 rgbaq3;
    u64 xy3;
    u64 nop;
};

struct sdfPrimG4Packet_t {
    sdfDmaTag_t *dmatag;
    sdfPrimG4Elem_t *elem;
};

struct sdfPrimFt3Elem_t {
    sdfGifTag_t *giftag;
    u64 prim;
    u64 rgbaq;
    u64 uv0;
    u64 xy0;
    u64 uv1;
    u64 xy1;
    u64 uv2;
    u64 xy2;
};

struct sdfPrimFt3Packet_t {
    sdfDmaTag_t *dmatag;
    sdfPrimFt3Elem_t *elem;
};

struct sdfPrimFt4Elem_t {
    sdfGifTag_t *giftag;
    u64 prim;
    u64 rgbaq;
    u64 uv0;
    u64 xy0;
    u64 uv1;
    u64 xy1;
    u64 uv2;
    u64 xy2;
    u64 uv3;
    u64 xy3;
};

struct sdfPrimFt4Packet_t {
    sdfDmaTag_t *dmatag;
    sdfPrimFt4Elem_t *elem;
};

struct sdfPrimGt3Elem_t {
    sdfGifTag_t *giftag;
    u64 prim;
    u64 uv0;
    u64 rgbaq0;
    u64 xy0;
    u64 uv1;
    u64 rgbaq1;
    u64 xy1;
    u64 uv2;
    u64 rgbaq2;
    u64 xy2;
};

struct sdfPrimGt3Packet_t {
    sdfDmaTag_t *dmatag;
    sdfPrimGt3Elem_t *elem;
};

struct sdfPrimGt4Elem_t {
    sdfGifTag_t *giftag;
    u64 prim;
    u64 uv0;
    u64 rgbaq0;
    u64 xy0;
    u64 uv1;
    u64 rgbaq1;
    u64 xy1;
    u64 uv2;
    u64 rgbaq2;
    u64 xy2;
    u64 uv3;
    u64 rgbaq3;
    u64 xy3;
    u64 nop;
};

struct sdfPrimGt4Packet_t {
    sdfDmaTag_t *dmatag;
    sdfPrimGt4Elem_t *elem;
};

struct sdfPrimRectElem_t {
    sdfGifTag_t *giftag;
    u64 prim;
    u64 rgbaq;
    u64 xy0;
    u64 xy1;
};

struct sdfPrimRectPacket_t {
    sdfDmaTag_t *dmatag;
    sdfPrimRectElem_t *rect;
};

struct sdfPrimLineElem_t {
    sdfGifTag_t *giftag;
    u64 prim;
    u64 rgbaq;
    u64 xy0;
    u64 xy1;
};

struct sdfPrimLinePacket_t {
    sdfDmaTag_t *dmatag;
    sdfPrimLineElem_t *line;
};

struct sdfPrimBoxLineElem_t {
    sdfGifTag_t *giftag;
    u64 prim;
    u64 rgbaq;
    u64 xy0;
    u64 xy1;
    u64 xy2;
    u64 xy3;
    u64 xy4;
    u64 nop;
};

struct sdfPrimBoxLinePacket_t {
    sdfDmaTag_t *dmatag;
    sdfPrimBoxLineElem_t *line;
};

struct sdf2DSpriteParm_t {
    sdfGrTagRGBA_t *rgba;
    sdfGrTagUV_t *uv0;
    sdfGrTagXYZ2_t *xyz0;
    sdfGrTagUV_t *uv1;
    sdfGrTagXYZ2_t *xyz1;
};

struct sdfMatrix2_t {
    sdfVector2_t pm[2];
};

struct sdfMatrix3_t {
    sdfVector3_t pm[3];
};

struct sdfSVector2_t {
    s16 pm[2];
};

struct sdfSVector3_t {
    s16 pm[3];
};

struct sdfSVector4_t {
    s16 pm[4];
};

struct sdfIVector3_t {
    s32 pm[3];
};

struct sdfBillBoardTMPacket_t {
    u16 dma_qwc;
    u8 dma_pad;
    u8 dma_id;
    u32 dma_addr;
    u32 vif_unpack;
    f32 tm[6];
    u32 vif_itop;
    u32 vif_mscal;
    u32 pad[3];
};

struct sdfBillBoard1Packet_t {
    u16 dma_qwc;
    u8 dma_pad;
    u8 dma_id;
    u32 dma_addr;
    u32 vif_unpack1;
    u32 count;
    u32 giftag_h;
    u32 giftag_reg_l;
    u32 giftag_reg_h;
    u32 vif_unpack2;
    u32 prim;
    u32 vif_unpack3;
    f32 center[3];
    u32 vif_unpack4;
    u32 color;
    u32 vif_unpack5;
    u32 uv[4];
    u32 vif_unpack6;
    f32 xyOffset[8];
    u32 vif_itop;
    u32 vif_mscal;
    u32 pad;
};

struct sdfMultiBillBoard1Packet_t {
    u16 dma_qwc;
    u8 dma_pad;
    u8 dma_id;
    u32 dma_addr;
    u32 vif_unpack1;
    u32 count;
    u32 giftag_h;
    u32 giftag_reg_l;
    u32 giftag_reg_h;
    u32 vif_unpack2;
    u32 prim;
    u32 vif_unpack3;
    f32 center[3];
    u32 vif_unpack4;
    u32 color[2];
    u32 vif_unpack5;
    u32 uv[8];
    u32 vif_unpack6;
    f32 xyOffset[8];
    u32 vif_itop;
    u32 vif_mscal;
};

struct sdfBillBoardVc1Packet_t {
    u16 dma_qwc;
    u8 dma_pad;
    u8 dma_id;
    u32 dma_addr;
    u32 vif_unpack1;
    u32 count;
    u32 giftag_h;
    u32 giftag_reg_l;
    u32 giftag_reg_h;
    u32 vif_unpack2;
    u32 prim;
    u32 vif_unpack3;
    f32 center[3];
    u32 vif_unpack4;
    u32 color[4];
    u32 vif_unpack5;
    u32 uv[4];
    u32 vif_unpack6;
    f32 xyOffset[8];
    u32 vif_itop;
    u32 vif_mscal;
    u32 pad[2];
};

struct sdfMultiBillBoardVc1Packet_t {
    u16 dma_qwc;
    u8 dma_pad;
    u8 dma_id;
    u32 dma_addr;
    u32 vif_unpack1;
    u32 count;
    u32 giftag_h;
    u32 giftag_reg_l;
    u32 giftag_reg_h;
    u32 vif_unpack2;
    u32 prim;
    u32 vif_unpack3;
    f32 center[3];
    u32 vif_unpack4;
    u32 vif_unpack5;
    u32 uv[8];
    u32 vif_unpack6;
    f32 xyOffset[8];
    u32 vif_itop;
    u32 vif_mscal;
    u32 pad[2];
};

struct sdfChipInfo_t {
    s32 total;
    s32 freeSize;
    s32 pageCount;
    s32 freePageCount;
    s32 fragmentedPageCount;
    s32 severalAllocCount[7];
};

struct sdfDevPrintCB_t {
    s32 x;
    s32 y;
    u32 z;
    u32 attr;
    char *message;
};

struct sdfFileCmdCB_t {
    sdfFileCmdCB_t *next;
    sdfFileCmdCB_t *prev;
    sdfFileCmdCB_t *deviceNext;
    sdfFileCmdCB_t *devicePrev;
    char *filename;
    u8 device;
    u8 cmd;
    s8 stat;
    s8 phase;
    s32 offset;
    s32 length;
    void *buffer;
    u32 cmdParm;
    s32 fd;
    s32 errorCode;
    u32 currentOffset;
    u32 remainder;
    sdfFileCmdCallback_t *callback;
    void *userData;
};

struct sdfStoreImagePacket_t {
    sdfDmaTag_t *dmaAnchor;
    u64 anchor[2];
    sdfDmaTag_t *dmaFinish;
    sdfGifTag_t *gifFinish;
    sdfGrTagStdReg_t *finish;
    sdfDmaTag_t *dmaBitblt;
    sdfGifTag_t *gifBitblt;
    sdfPrimBitBltElem_t *bitblt;
    u32 leng;
    void *addr;
    void *callback;
    void *callbackParam;
    sdfDmaTag_t *dmaFooter;
    sdfGifTag_t *gifFooter;
    sdfGrTagStdReg_t *footer;
};

struct sdfLoadImagePacket_t {
    sdfDmaTag_t *dmatag;
    sdfGifTag_t *giftag;
    sdfPrimBitBltElem_t *bitblt;
    sdfGifTag_t *giftagData;
    sdfDmaTag_t *dmatagData;
    sdfDmaTag_t *dmatagFlush;
    sdfGifTag_t *giftagFlush;
    sdfGrTagStdReg_t *texflush;
};

struct sdfStoreFrameImagePacket_t {
    sdfPreDrawHook_t *worker;
    sdfStoreImagePacket_t *packet;
};

struct sdfIpuInitParm_t {
    u8 rgbMode;
    u8 ditherMode;
    u8 loopMode;
    u8 fps;
};

struct sdfMemInfo_t {
    s32 total;
    s32 freeSize;
    s32 maxFreeSize;
    s32 minFreeSize;
    s32 handleCount;
    s32 freeHandleCount;
};

struct sdfItemArray_t {
    sdfMemHandle_t *memHandle;
    s16 count;
    s16 capacity;
    s16 elemSize;
    s16 growStep;
    s32 *items;
};

struct MB_HEADER_t {
    u8 fileType;
    u8 compression;
    s16 userId;
    s32 fileSize;
    u32 formatId;
    s32 realSize;
    u32 dataSize;
    u32 addrInfoSize;
    u32 pad[2];
};

struct AB_HEADER_t {
    u8 fileType;
    u8 compression;
    s16 userId;
    s32 fileSize;
    u32 formatId;
    s32 realSize;
    u32 dataSize;
    u32 addrInfoSize;
    u32 pad[2];
};

struct sdfShape_t {
    u32 flags;
    s32 vertexCount;
    s32 faceCount;
    s16 pointElemCount;
    s16 packetPointMax;
    sdfMemHandle_t *vertexListHandle;
    sdfVector4_t vertexList;
    sdfMemHandle_t *normalListHandle;
    sdfVector4_t normalList;
    sdfMemHandle_t *uvListHandles[2];
    sdfVector2_t uvList[2];
    sdfMemHandle_t *vertColorListHandle;
    u32 vertColorList;
    sdfMemHandle_t *faceListHandle;
    s32 faceList[4];
    sdfMemHandle_t *faceNormalListHandle;
    sdfVector4_t faceNormalList;
    sdfMemHandle_t *faceColorListHandle;
    s32 faceColorList[4];
    void *packetPtr;
};

struct sdfSndVoiceInfo_t {
    u8 priority;
    u8 polyCount;
    u16 iopSize;
    u32 spuSize;
};

struct sdfSndSeqInfo_t {
    u32 iopSize;
};

struct sdfTexMapPacket_t {
    u64 tex1;
    u64 tex0;
    u64 clamp;
    u32 tmVifCmd;
};

struct sdfTexMapCB_t {
    sdfTexHandle_t *texHandle;
};

struct TB_HEADER_t {
    u8 fileType;
    u8 compression;
    s16 userId;
    s32 fileSize;
    u32 formatId;
    s32 realSize;
    s32 numOfPack;
    u32 offsetTable[3];
};

struct sdfSndReqPlayInfo_t {
    u32 reqno;
    u32 playpos;
    u16 volume;
    void *pCalback;
};

struct p2sdfileheader {
    s8 type;
    s8 format;
    u16 ID;
    u32 fsize;
    s8 code[4];
    u32 dsize;
};

struct p2sdsoundheader {
    u32 hdofs;
    u32 hdsize;
    u32 bdofs;
    u32 bdsize;
    u32 sqofs;
    u32 sqsize;
    u32 reqno;
    u8 totaltimes;
    u8 bgmtimes;
    u8 songtimes;
    u8 area;
};

struct p2sdadpcmheader {
    u32 strsize;
    u32 interleave;
    s16 looppoint;
    u8 mode;
    u8 frequensy;
    u16 dsp;
    u16 reserve;
};

struct p2sdSubHandle {
    void *SpuAddress;
    s32 IopHandle;
};

struct sdfSndReqSeInfo_t {
    u32 reqno;
    u32 playpos;
    u16 volume;
    u16 pan;
};

struct sdfIopLoadStartModuleParm_t {
    s32 filenameLeng;
    s32 args;
    char *filename;
};

struct sdfIopLoadStartModuleResult_t {
    s32 result;
    s32 iopResult;
};

typedef struct sdfMemHandle_t sdfMemHandle_tag;

extern sdfVector4_t vf00;
extern sdfVector4_t vct_A;
extern sdfVector4_t vct_B;
extern sdfVector4_t vct_C;
extern sdfMatrix4_t mtx_A;
extern sdfMatrix4_t mtx_B;
extern sdfMatrix4_t mtx_C;

extern s32 clip;
