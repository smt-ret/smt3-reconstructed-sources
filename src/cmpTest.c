#include "types.h"

typedef struct cmpCursorInfo_t cmpCursorInfo_t;
typedef struct cmpTest_cmpDbgList_s cmpTest_cmpDbgList_s;
typedef struct cmpTest_cmpDbgList_s_funcDelegate cmpTest_cmpDbgList_s_funcDelegate;
typedef struct dds3ProcessID_t dds3ProcessID_t;

struct cmpTest_cmpDbgList_s {
    char *word;
    s32 Para;
    cmpTest_cmpDbgList_s_funcDelegate *func;
    cmpTest_cmpDbgList_s *nextList;
    s32 nextSize;
};

static cmpTest_cmpDbgList_s *cmpDbgListParam[11];
static cmpTest_cmpDbgList_s *cmpDbgRootList[13];
static cmpTest_cmpDbgList_s *cmpDbgStatusList[1];
static cmpTest_cmpDbgList_s *gRootList;
static s8 gListNums;
static cmpCursorInfo_t *gCursorInfo[3];
static u16 gTargetModel;
static s8 gCursorSection;
static s8 gInitFlag;
static s8 gActive1;
static s8 gActive2;
static s32 gWork;
static s8 gTerminateFlag;
static s32 gSelSkill;
static dds3ProcessID_t *cmpDbgPID;
static s32 status_id;
static s32 Skill_id;

static s8 pCaption;
static s8 CallbackMode;
static cmpTest_cmpDbgList_s *pNextList;
static s8 ListSize;
