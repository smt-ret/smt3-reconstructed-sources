#pragma once
#include "types.h"

typedef enum {
    DDS3_AREABASIC_ITEMTYPE_OBJECT = 0,
    DDS3_AREABASIC_ITEMTYPE_EVENT = 1,
    DDS3_AREABASIC_ITEMTYPE_MAX = 2,
} DDS3_AREABASIC_ITEMTYPE;

typedef enum {
    BASIC_TYPE_WORLD = 0,
    BASIC_TYPE_SCENE = 1,
    BASIC_TYPE_AREA = 2,
    BASIC_TYPE_MOVER = 3,
    BASIC_TYPE_CAMERAOBJECT = 4,
    BASIC_TYPE_UNITOBJECT = 5,
    BASIC_TYPE_MATTEROBJECT = 6,
    BASIC_TYPE_EFFECTOBJECT = 7,
    BASIC_TYPE_EVENTOBJECT = 8,
    BASIC_TYPE_LIGHTOBJECT = 9,
    BASIC_TYPE_STATICMODEL = 10,
    BASIC_TYPE_MODELRANGE = 11,
    BASIC_TYPE_EFFECT = 12,
    BASIC_TYPE_EVENT = 13,
    BASIC_TYPE_FOG = 14,
    BASIC_TYPE_LIGHT = 15,
    BASIC_TYPE_PATH = 16,
    BASIC_TYPE_POINT = 17,
    BASIC_TYPE_MAX = 18,
} BASIC_TYPE;

typedef enum {
    POSESET_FLAG_UPDATEPOSE = 1,
    POSESET_FLAG_UPDATETM = 2,
    POSESET_FLAG_ONGROUND = 4,
    POSESET_FLAG_POS2 = 8,
} POSESET_FLAG;

typedef enum {
    DDS3_CAMERAOBJECT_MODE_LOOKAT = 0,
    DDS3_CAMERAOBJECT_MODE_FREE = 1,
    DDS3_CAMERAOBJECT_MODE_MAX = 2,
} DDS3_CAMERAOBJECT_MODE;

typedef enum {
    DDS3_EFFECTOBJECT_TYPE_D3P = 1,
    DDS3_EFFECTOBJECT_TYPE_P2A = 2,
    DDS3_EFFECTOBJECT_TYPE_TMX = 3,
    DDS3_EFFECTOBJECT_TYPE_BILLBOARD = 4,
    DDS3_EFFECTOBJECT_TYPE_BED = 5,
    DDS3_EFFECTOBJECT_TYPE_ESP = 6,
    DDS3_EFFECTOBJECT_TYPE_MG1 = 7,
    DDS3_EFFECTOBJECT_TYPE_MG2 = 8,
} DDS3_EFFECTOBJECT_TYPE;

typedef enum {
    DDS3_OBJECTBASE_FLAG_IGNORE_DRAW_MODEL = 1,
    DDS3_OBJECTBASE_FLAG_IGNORE_DRAW_RANGE = 2,
    DDS3_OBJECTBASE_FLAG_IGNORE_COLLISION = 32,
    DDS3_OBJECTBASE_FLAG_IGNORE_EVENT = 64,
    DDS3_OBJECTBASE_FLAG_IGNORE_AREA = 128,
    DDS3_OBJECTBASE_FLAG_IGNORE_ELAUTO = 256,
    DDS3_OBJECTBASE_FLAG_SVKAGE = 512,
    DDS3_OBJECTBASE_FLAG_MARUKAGE = 1024,
    DDS3_OBJECTBASE_FLAG_USE_SVS = 2048,
    DDS3_OBJECTBASE_FLAG_IGNORE_DRAW_SHADOW = 4096,
    DDS3_OBJECTBASE_FLAG_MARUKAGE_UNITY = 8192,
    DDS3_OBJECTBASE_FLAG_MARUKAGEPLUS_UNITY = 16384,
    DDS3_OBJECTBASE_FLAG_MAXBIT = 15,
} DDS3_OBJECTBASE_FLAG;

typedef enum {
    DDS3_OBJECTBASE_ITEMTYPE_OWN = 0,
    DDS3_OBJECTBASE_ITEMTYPE_MOVER = 1,
    DDS3_OBJECTBASE_ITEMTYPE_DECIDER = 2,
    DDS3_OBJECTBASE_ITEMTYPE_MODEL = 3,
    DDS3_OBJECTBASE_ITEMTYPE_RANGE = 4,
    DDS3_OBJECTBASE_ITEMTYPE_AREA = 5,
    DDS3_OBJECTBASE_ITEMTYPE_PADD01 = 6,
    DDS3_OBJECTBASE_ITEMTYPE_PADD02 = 7,
    DDS3_OBJECTBASE_ITEMTYPE_MAX = 8,
} DDS3_OBJECTBASE_ITEMTYPE;

typedef enum {
    DDS3_OBJECTBASE_MODELTYPE_UNIT = 0,
    DDS3_OBJECTBASE_MODELTYPE_MATTER = 1,
    DDS3_OBJECTBASE_MODELTYPE_EFFECT = 2,
    DDS3_OBJECTBASE_MODELTYPE_MAX = 3,
} DDS3_OBJECTBASE_MODELTYPE;

typedef enum {
    DDS3_PATHBASIC_CONTROL_FORWARD = 0,
    DDS3_PATHBASIC_CONTROL_BACK = 1,
    DDS3_PATHBASIC_CONTROL_MAX = 2,
} DDS3_PATHBASIC_CONTROL;

typedef enum {
    DDS3_PATHBASIC_FLAG_POS = 1,
    DDS3_PATHBASIC_FLAG_ROT = 2,
    DDS3_PATHBASIC_FLAG_FOVY = 4,
    DDS3_PATHBASIC_FLAG_STOP = 8,
    DDS3_PATHBASIC_FLAG_LIGHT = 16,
    DDS3_PATHBASIC_FLAG_LOOP = 32,
} DDS3_PATHBASIC_FLAG;

typedef enum {
    DDS3_UNITSTATUS_STATUS_GOOD = 0,
} DDS3_UNITSTATUS;

typedef enum {
    DDS3_BASICARRAY_SERACHDELETE_MODE_FIRST = 0,
    DDS3_BASICARRAY_SERACHDELETE_MODE_ALL = 1,
    DDS3_BASICARRAY_SERACHDELETE_MODE_MAX = 2,
} DDS3_BASICARRAY;

typedef struct dds3AreaBasicWorkData_t dds3AreaBasicWorkData_t;
typedef struct dds3BasicArrayHandle_t dds3BasicArrayHandle_t;
typedef struct dds3BasicArray_t dds3BasicArray_t;
typedef struct dds3BasicFunction_t dds3BasicFunction_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3CameraObjectBasicWorkData_t dds3CameraObjectBasicWorkData_t;
typedef struct dds3EffectObjectBasicWorkData_t dds3EffectObjectBasicWorkData_t;
typedef struct dds3EventObjectBasicWorkData_t dds3EventObjectBasicWorkData_t;
typedef struct dds3LightObjectBasicWorkData_t dds3LightObjectBasicWorkData_t;
typedef struct dds3MatterObjectBasicWorkData_t dds3MatterObjectBasicWorkData_t;
typedef struct dds3ModelBasicWorkData_t dds3ModelBasicWorkData_t;
typedef struct dds3ModelRangeBasicWorkData_t dds3ModelRangeBasicWorkData_t;
typedef struct dds3MoverBasicWorkData_t dds3MoverBasicWorkData_t;
typedef struct dds3ObjectBaseControlWorkData_t dds3ObjectBaseControlWorkData_t;
typedef struct dds3PathBasicControl_t dds3PathBasicControl_t;
typedef struct dds3PoseSet_t dds3PoseSet_t;
typedef struct dds3SceneBasicTable_t dds3SceneBasicTable_t;
typedef struct dds3SceneBasic_t dds3SceneBasic_t;
typedef struct dds3UnitAction_t dds3UnitAction_t;
typedef struct dds3UnitObjectBasicWorkData_t dds3UnitObjectBasicWorkData_t;
typedef struct dds3UnitStatus_t dds3UnitStatus_t;
typedef struct dds3WorldBasic_t dds3WorldBasic_t;
typedef struct effSpline_t effSpline_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct fldResourceEffect_t fldResourceEffect_t;
typedef struct fldResourceModelRange_t fldResourceModelRange_t;
typedef struct fldResourcePathData_t_Float fldResourcePathData_t_Float;
typedef struct fldResourcePathData_t_Light fldResourcePathData_t_Light;
typedef struct fldResourcePathData_t_Vector3 fldResourcePathData_t_Vector3;
typedef struct fldResourcePathData_t_Vector4 fldResourcePathData_t_Vector4;
typedef struct sdf3DLightParallelPacket_t sdf3DLightParallelPacket_t;
typedef struct sdf3DLight_t sdf3DLight_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfModelDef_t sdfModelDef_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;
typedef struct sdfModelTexList_t sdfModelTexList_t;
typedef struct sdfMotionCtrlr_t sdfMotionCtrlr_t;
typedef struct sdfMotionPlayBook_t sdfMotionPlayBook_t;

struct dds3BasicFunction_t {
    void *constructor;
    void *destructor;
    void *mainprocuder;
    void *drawprocuder;
    void *reserve1;
    void *reserve2;
};

struct dds3PoseSet_t {
    sdfMatrix4_t *workTM;
    sdfVector4_t pos;
    sdfVector4_t rot;
    sdfVector4_t scl;
    sdfVector4_t pos2;
    sdfVector4_t workpos;
    sdfVector4_t workrot;
    sdfVector4_t workscl;
    sdfVector4_t plane;
    u32 flag;
    f32 r;
    f32 frameFall;
    u32 pad;
};

struct dds3Basic_t {
    u32 flag;
    u32 serialID;
    char *name;
    u32 type;
    dds3BasicFunction_t *basicfunction;
    void *staticdata;
    void *workdata;
    dds3PoseSet_t *poseset;
    dds3Basic_t *next;
    dds3Basic_t *prev;
    dds3Basic_t *worknext;
    dds3Basic_t *workprev;
    dds3Basic_t *workpointer;
    u32 color;
    u32 pad[3];
    void *gameObject;
};

struct dds3PathBasicControl_t {
    u32 mode;
    u32 flag;
    f32 frameMax;
    f32 frame;
    effSpline_t *pSplineHandle;
    fldResourcePathData_t_Vector3 *pTransrate;
    fldResourcePathData_t_Vector4 *pRotation;
    fldResourcePathData_t_Float *pFovy;
    fldResourcePathData_t_Light *pLight;
};

struct dds3UnitAction_t {
    u32 action;
};

struct dds3AreaBasicWorkData_t {
    dds3BasicArrayHandle_t hBasicArray[UNKNOWN_ARRAY_SIZE];
};

struct dds3BasicArrayHandle_t {
    s16 firstindex;
    s16 lastindex;
    s16 nowindex;
    u16 count;
    dds3BasicArrayHandle_t *next;
    dds3BasicArrayHandle_t *prev;
};

struct dds3CameraObjectBasicWorkData_t {
    sdfMatrix4_t *cameraTM;
    sdfVector4_t eyeVector;
    sdfVector4_t vertical;
    sdfVector4_t targetPos;
    sdfVector4_t upVector;
    dds3ObjectBaseControlWorkData_t *pObjectBaseControlWorkData;
    u32 mode;
    u32 flag;
    f32 fovy;
};

struct dds3ObjectBaseControlWorkData_t {
    u32 flag;
    dds3BasicArrayHandle_t *hEventBasicArray;
    u32 modelType;
    void *pModel;
    dds3Basic_t *pBasic[8];
    void *pUserValue;
    sdfModelRootNode_t *pModelRangeRootNode;
    sdfMotionCtrlr_t *pMot;
    s32 MotMode;
    f32 MotSpeed;
    u32 svs;
    s32 sdwchrid;
    s32 sdwnodeidx[24];
};

struct dds3EffectObjectBasicWorkData_t {
    dds3ObjectBaseControlWorkData_t *pObjectBaseControlWorkData;
    u32 stat;
    s32 type;
    void *handle;
    sdfVector4_t linkpos;
    dds3Basic_t *linkbasic;
    u16 linkindex;
    u16 linkbasictype;
    void *para;
    void *cuth;
    s32 reserve1;
    s32 reserve2;
    s32 reserve3;
    fldResourceEffect_t *pFldEx;
    sdfVector4_t FldExBasePos;
};

struct dds3EventObjectBasicWorkData_t {
    dds3ObjectBaseControlWorkData_t *pObjectBaseControlWorkData;
    u32 padd[3];
};

struct dds3LightObjectBasicWorkData_t {
    sdf3DLight_t *Light;
    sdfVector4_t Ambient;
    f32 InsideR;
    f32 OutsideR;
    f32 Soften;
    f32 Bias;
    u32 AnimeType;
    u32 Flag;
    u32 BaseLightRGB;
    u32 BaseAmbientRGB;
    u16 SwitchFrame;
    u16 Reserve1;
    dds3ObjectBaseControlWorkData_t *ObjectBaseControlWorkData;
    sdf3DLightParallelPacket_t *LightPacket;
};

struct dds3MatterObjectBasicWorkData_t {
    dds3ObjectBaseControlWorkData_t *pObjectBaseControlWorkData;
    u32 hojiID;
    u32 alpmode;
    s32 OtLinkIdx;
    sdfVector4_t base_pos;
    sdfVector4_t move_pos;
};

struct dds3ModelBasicWorkData_t {
    dds3Basic_t *pTextureBasic;
    sdfModelDef_t *pModelDef;
    sdfMotionPlayBook_t *pMotDef;
    sdfModelTexList_t *pTexList;
    u32 padd[3];
};

struct dds3ModelRangeBasicWorkData_t {
    fldResourceModelRange_t *pRange;
    void *pShapePacket;
    sdfMemHandle_t *hPlane;
    sdfVector4_t pPlane;
    u32 blockID;
    u32 padd;
};

struct dds3MoverBasicWorkData_t {
    dds3Basic_t *pObjectBasic;
    dds3PathBasicControl_t *pPathControl;
    void *pFunc;
    dds3Basic_t *pPathBasic;
};

struct dds3SceneBasicTable_t {
    s32 linkcount;
    dds3Basic_t *firstbasic;
    dds3Basic_t *lastbasic;
};

struct dds3SceneBasic_t {
    s32 mapno;
    sdfMemHandle_t *mem_hndl;
    dds3SceneBasicTable_t basictable[UNKNOWN_ARRAY_SIZE];
    dds3Basic_t *activecamera;
    dds3Basic_t *activeunit;
    sdfMemHandle_t *hFileHandle;
    sdfMemHandle_t *hScrFileHandle;
    void *pScrFileData;
    s32 visible;
    s32 pad[7];
};

struct dds3UnitObjectBasicWorkData_t {
    s32 statusID;
    void *pWorkData;
    evtUnitHandle_t *hUnit;
    dds3ObjectBaseControlWorkData_t *pObjectBaseControlWorkData;
    s32 EL_serialID;
    s32 OtLinkIdx;
    u32 flag;
    s32 dmy;
    s32 IsBattle;
};

struct dds3UnitStatus_t {
    s32 flags;
    u16 code;
    u8 aclass;
    u8 status;
    u8 level;
    u8 life;
    u8 lifepoint;
    u8 attribute;
    u8 rpoints[4];
    s16 hp;
    s16 maxhp;
    s16 mp;
    s16 maxmp;
    s16 power;
    s16 magery;
    s16 agility;
    s16 luck;
    s8 regists[8];
    u8 skills[4];
    u8 equips[4];
    dds3UnitAction_t *presetact;
    dds3UnitAction_t *act;
};

struct dds3BasicArray_t {
    dds3Basic_t *target;
    s16 next;
    s16 prev;
};

struct dds3WorldBasic_t {
    dds3Basic_t *firstscene;
    dds3Basic_t *lastscene;
    dds3Basic_t *activescene;
    dds3Basic_t *controlscene;
    sdfMemHandle_t *basicarray_hndl;
    dds3BasicArray_t basicarray[UNKNOWN_ARRAY_SIZE];
    u16 basicarraycnt;
    s16 firstempty;
    s16 lastempty;
    u16 emptycount;
    dds3BasicArrayHandle_t *firstheader;
    dds3BasicArrayHandle_t *lastheader;
};
