#include "types.h"

typedef struct cmpCursorInfo_t cmpCursorInfo_t;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct sdf3DLightParallelPacket_t sdf3DLightParallelPacket_t;

static u8 gRstGeneralStrTbl[UNKNOWN_ARRAY_SIZE];

s32 CMP_X(s32 a);
s32 CMP_Y(s32 b);
void *GetCampCameraObj(dds3DefaultMain *this);
char *RepColTag(char *txt, void **LegacyParamArray);
dds3Basic_t *dds3GetActiveScene(void);
void *dds3GetProcessData(dds3ProcessID_t **id);
dds3Basic_t *dds3SearchSceneBasic(dds3Basic_t **pBasic, u32 serialID, u32 type);
evtUnitHandle_t *evtGetUnitHandle2(dds3Basic_t *unit);
s8 fclChkMessage(void);
char *frwGetHelpForUnity(s32 X, s32 Y, u32 Z, s8 HelpType, u16 HelpID, s8 DrawMode);
void mdlSetLight(dds3ModelHandle_t **HNDL, sdf3DLightParallelPacket_t *LIGHT);
void rstDrawEvoBgFade(void);
void rstDrawSeqAsignPlayerParam(void);
s8 rstDrawSeqDestroySkill(s16 SkillLevOfs, s8 CursorMode);
void rstDrawSeqDevilStatus(s16 SkillLevOfs, s8 FlashMode, s8 SkillMode);
void rstDrawSeqDevilStatusSkillPUp(s16 SkillLevOfs, s8 FlashMode, s8 CursorPos);
u16 rstGetCursorPosSkillID(datUnitWork_t **pStock, cmpCursorInfo_t **pCursorInfo);
void rstSetEvoActLight(void);
void rstSetEvoLight(void);
void rstSetModelLight(void);
s8 rstSetModelLightCore(dds3ModelHandle_t **Model);

// 0x1567580
void *rstDraw(dds3ProcessID_t *PID) {
    dds3GetProcessData(0);
    GetCampCameraObj(0);
    rstDrawEvoBgFade();
    rstDrawSeqAsignPlayerParam();
    rstDrawSeqDevilStatusSkillPUp(0, 0, 0);
    rstDrawSeqDevilStatus(0, 0, 0);
    rstSetEvoLight();
    rstSetEvoActLight();
    rstDrawSeqDestroySkill(0, 0);
    return 0;
}

// 0x15674d0
void rstDrawEvoBgFade(void) {
  u32 EvoBgFade;

  EvoBgFade = GBWK->EvoBgFade;
  cmpDrawBoxF(0, 0, 0, 512, 448, EvoBgFade, 7u);
}

// 0x1566540
void rstDrawSeqAsignPlayerParam(void) {
    fclChkMessage();
}

// 0x1566ab0
s8 rstDrawSeqDestroySkill(s16 SkillLevOfs, s8 CursorMode) {
    fclChkMessage();
    rstGetCursorPosSkillID(0, 0);
    CMP_X(0);
    CMP_Y(0);
    frwGetHelpForUnity(0, 0, 0, 0, 0, 0);
    RepColTag(0, 0);
    return 0;
}

// 0x1566820
void rstDrawSeqDevilStatus(s16 SkillLevOfs, s8 FlashMode, s8 SkillMode) {
  struct rstData_t_o *GBWK;
  datUnitWork_t_o *pCurrentStock;
  u8 StatAlpha;
  System_SByte_array *ParamOfs;

  pCurrentStock = GBWK->pCurrentStock;
  StatAlpha = GBWK->StatAlpha;
  ParamOfs = GBWK->ParamOfs;
  cmpDrawStatusComEx(pCurrentStock, StatAlpha, 255, 0, ParamOfs, SkillLevOfs, 0xA09DC380, 2, FlashMode, SkillMode);
}

// 0x1566910
void rstDrawSeqDevilStatusSkillPUp(s16 SkillLevOfs, s8 FlashMode, s8 CursorPos) {
  s16 v8;
  s32 v9;
  struct rstData_t_o *GBWK;
  datUnitWork_t_o *pCurrentStock;
  u8 StatAlpha;
  System_SByte_array *ParamOfs;
  datUnitWork_t_o *v14;
  u8 v15;
  System_SByte_array *v16;

  if ((v8 & 0x200) != 0)
  {
    v9 = v8 & 0x200;
  }
  else
  {
    v9 = 0;
  }
  if (GBWK->MessageWait)
  {
    pCurrentStock = GBWK->pCurrentStock;
    StatAlpha = GBWK->StatAlpha;
    ParamOfs = GBWK->ParamOfs;
    cmpDrawStatusComEx(pCurrentStock, StatAlpha, CursorPos, 3, ParamOfs, SkillLevOfs, 0xA09DC380, 2, FlashMode, 0);
  }
  else
  {
    v14 = GBWK->pCurrentStock;
    v15 = GBWK->StatAlpha;
    v16 = GBWK->ParamOfs;
    cmpDrawStatusComEx(v14, v15, 255, 3, v16, SkillLevOfs, 0xA09DC380, 2, FlashMode, 0);
  }
}

// 0x15673e0
void rstSetEvoActLight(void) {
  dds3ModelHandle_t_o *HNDL;

  HNDL = 0;
  if (*(v2[2].klass->_1.image + 84) <= 4)
  {
    rstSetModelLight();
  }
  else
  {
    HNDL = cmpGetStatusModelHandle();
    mdlSetLight(&HNDL, 0);
  }
}

// 0x15672f0
void rstSetEvoLight(void) {
  dds3ModelHandle_t_o *HNDL;

  HNDL = 0;
  if (*(v2[2].klass->_1.image + 126) > 1u)
  {
    HNDL = cmpGetStatusModelHandle();
    mdlSetLight(&HNDL, 0);
  }
  else
  {
    rstSetModelLight();
  }
}

// 0x1567200
void rstSetModelLight(void) {
  u64 *v1;
  dds3ModelHandle_t_o *Model;

  v1 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v1);
  Model = v1;
  else if (GBWK->EvoActStatFlag)
  {
    return;
  }
  Model = cmpGetStatusModelHandle();
  if (Model)
    rstSetModelLightCore(&Model);
}

// 0x1567070
s8 rstSetModelLightCore(dds3ModelHandle_t **Model) {
  dds3Basic_t_o *ActiveScene;
  struct System_Int32_array *IntVariable;
  u32 v8;
  dds3Basic_t_o *v10;
  sdf3DLightParallelPacket_t_o *gameObject;
  dds3Basic_t_o *pBasic;

  pBasic = 0;
  ActiveScene = dds3GetActiveScene();
  pBasic = ActiveScene;
  if (ActiveScene)
  {
    IntVariable = DDS3_GBWK->IntVariable;
    v8 = IntVariable->m_Items[12];
    ActiveScene = dds3SearchSceneBasic(&pBasic, v8, 5u);
    if (ActiveScene)
    {
      v10 = ActiveScene;
      ActiveScene = evtGetUnitHandle2(v10);
      if (ActiveScene)
      {
        gameObject = ActiveScene->gameObject;
        if (gameObject)
        {
          mdlSetLight(Model, gameObject);
          LOBYTE(ActiveScene) = 1;
        }
        else
        {
          LOBYTE(ActiveScene) = 0;
        }
      }
    }
  }
  return ActiveScene;
}
