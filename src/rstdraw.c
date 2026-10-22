#include "types.h"

typedef struct cmpCursorInfo_t cmpCursorInfo_t;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct sdf3DLightParallelPacket_t sdf3DLightParallelPacket_t;

static u8 *gRstGeneralStrTbl;

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
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  struct cmpSeqInfo_t_o *SeqInfo;
  UnityEngine_GameObject_o *CampCameraObj;
  s32 BgTimer;
  rstinit_c *v20;
  struct rstData_t_o *GBWK;
  struct cmpSeqInfo_t_o *v22;
  s32 v24;
  s8 v25;
  s8 v28;
  s16 v29;
  s32 v30;
  dds3ProcessID_t_o *v35[3];
  dds3ProcessID_t_o *id;

  id = PID;
  ProcessData = dds3GetProcessData(&id);
  else
  {
    if (!ProcessData)
      goto LABEL_15;
  }
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != rstData_t)
  {
    sub_8FC2C0(klass->_1.element_class, rstData_t, v35);
    if ((v35[0] & 1) != 0)
      v7 = v35[2];
    else
      v7 = v35 + 1;
    v8 = sub_8C4940(v7);
  }
LABEL_15:
  GBWK = ProcessData;
  SeqInfo = GBWK->SeqInfo;
  if ((SeqInfo->Flag & 0x20) != 0)
  {
    cmpUpdateTerminate(SeqInfo);
    id->func_ans = -1;
  }
  else
  {
    CampCameraObj = GetCampCameraObj(kernelObject);
    campCameraObj = CampCameraObj;
    BgTimer = GBWK->BgTimer;
    cmpDrawBG(0x10u, BgTimer);
    rstDrawEvoBgFade();
    v22 = GBWK->SeqInfo;
    if ((v22->Flag & 2) != 0)
    {
      switch (v22->Current)
      {
        case 0:
        case 0x18:
          rstDrawSeqAsignPlayerParam(v20);
          break;
        case 1:
        case 7:
        case 8:
          v24 = -GBWK->LevelUpCnt;
          v25 = 2;
          goto LABEL_79;
        case 3:
          v29 = *&v20->_2.bitflags1;
          if ((v29 & 0x200) != 0)
          {
            v30 = v29 & 0x200;
            if (GBWK->HeartsEventMode == 1)
              goto LABEL_59;
          }
          else
          {
            v30 = 0;
            if (GBWK->HeartsEventMode == 1)
            {
LABEL_59:
              rstDrawSeqDevilStatusSkillPUp(-GBWK->LevelUpCnt, 0, GBWK->PUpSkillIndex);
              break;
            }
          }
          if (v30)
          {
LABEL_34:
          }
LABEL_55:
          v24 = -GBWK->LevelUpCnt;
          v25 = 2;
LABEL_56:
          v28 = 0;
LABEL_80:
          rstDrawSeqDevilStatus(v24, v25, v28);
          break;
        case 5:
          v24 = -GBWK->LevelUpCnt;
          v25 = 5;
          goto LABEL_56;
        case 6:
        case 0xB:
        case 0xC:
        case 0xD:
          if ((v20->_2.bitflags2 & 2) != 0)
            goto LABEL_34;
          goto LABEL_55;
        case 0xA:
          rstDrawSeqDevilStatusSkillPUp(-GBWK->LevelUpCnt, 2, GBWK->PUpSkillIndex);
          break;
        case 0x11:
        case 0x12:
          rstSetEvoLight(v20);
          goto LABEL_54;
        case 0x13:
          PPSV2_StatusMode = 1;
          break;
        case 0x14:
          rstSetEvoActLight(v20);
          v24 = -GBWK->LevelUpCnt;
          v25 = 0;
LABEL_79:
          v28 = 1;
          goto LABEL_80;
        case 0x15:
          rstDrawSeqDestroySkill(-GBWK->LevelUpCnt, 1);
          break;
        case 0x16:
          rstDrawSeqDestroySkill(-GBWK->LevelUpCnt, 0);
          break;
        default:
          break;
      }
    }
    cmpDrawPanelEff(0x48u);
  }
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
  cmpCursorInfo_t_o *ParamCursor;
  s8 CursorIndex;
  s16 AsignParamMax;
  s16 AsignParam;
  s8 v11;
  bool v13;
  struct rstData_t_o *GBWK;
  datUnitWork_t_o *pCurrentStock;
  System_SByte_array *ParamOfs;
  struct rstData_t_o *v18;
  datUnitWork_t_o *v19;
  System_SByte_array *v20;

  ParamCursor = GBWK->ParamCursor;
  CursorIndex = cmpGetCursorIndex(ParamCursor);
  AsignParamMax = GBWK->AsignParamMax;
  else if (!ToBoolean_2953840(AsignParamMax))
  {
    goto LABEL_19;
  }
  AsignParam = GBWK->AsignParam;
  cmpDrawRestPoint(0, 0, AsignParam);
LABEL_19:
  v11 = fclChkMessage();
  v13 = ToBoolean_2953808(v11);
  if (!v13)
  {
    else
    {
      if (GBWK->AsignParamMax)
        goto LABEL_29;
    }
  }
  v18 = GBWK;
  v19 = v18->pCurrentStock;
  v20 = v18->ParamOfs;
  cmpDrawStatusComEx(v19, 0x80u, CursorIndex, 0, v20, 0, 0xA09DC380, 2, 0, 0);
}

// 0x1566ab0
s8 rstDrawSeqDestroySkill(s16 SkillLevOfs, s8 CursorMode) {
  cmpCursorInfo_t_o *SkillCursor;
  s8 CursorIndex;
  s8 v9;
  s8 v11;
  UnityEngine_Animator_o *skillFull;
  System_String_o *v14;
  bool v15;
  struct rstData_t_o *v18;
  datUnitWork_t_o *pCurrentStock;
  System_SByte_array *ParamOfs;
  struct rstData_t_o *GBWK;
  datUnitWork_t_o **p_pCurrentStock;
  cmpCursorInfo_t_o **p_SkillCursor;
  u16 CursorPosSkillID;
  s32 v30;
  s32 v31;
  System_String_o *HelpForUnity;
  System_String_o *v34;
  TMPro_TMP_Text_o *skillHelp;
  System_Object_array *v37;
  s64 *v38;
  s64 *v40;
  System_String_o *v43;
  s32 v44;

  SkillCursor = GBWK->SkillCursor;
  CursorIndex = cmpGetCursorIndex(SkillCursor);
  if (!CursorMode)
    goto LABEL_16;
  v9 = CursorIndex;
  v11 = fclChkMessage();
  else if (ToBoolean_2953808(v11))
  {
LABEL_16:
    v9 = -1;
    goto LABEL_17;
  }
  if (v9 < 0)
  {
LABEL_17:
    skillFull = _statusUIScr->skillFull;
    v14 = "sfeature_full";
    v15 = 0;
    goto LABEL_21;
  }
  cmpDrawAisyoPanel(70, 34, 0);
  cmpDrawAisyoPanel(70, 34, 0);
  p_pCurrentStock = &GBWK->pCurrentStock;
  p_SkillCursor = &GBWK->SkillCursor;
  CursorPosSkillID = rstGetCursorPosSkillID(p_pCurrentStock, p_SkillCursor);
  v30 = CMP_X(24);
  v31 = CMP_Y(308);
  HelpForUnity = frwGetHelpForUnity(v30, v31, 0xFFFFFu, 0, CursorPosSkillID, 2);
  v34 = Replace_5267216(HelpForUnity, "\n", "");
  skillHelp = _statusUIScr->skillHelp;
  v44 = 21;
  v37 = NewSpecific(object, 1u);
  v38 = sub_8D3950(s32, &v44);
  v40 = v38;
  v37->m_Items[0] = v40;
  v43 = RepColTag(v34, v37);
  set_text(skillHelp, v43);
  skillFull = _statusUIScr->skillFull;
  v14 = "sfeature_full";
  v15 = 1;
LABEL_21:
  SetBool(skillFull, v14, v15);
  v18 = GBWK;
  pCurrentStock = v18->pCurrentStock;
  ParamOfs = v18->ParamOfs;
  cmpDrawStatusComEx(pCurrentStock, 0x80u, v9, CursorMode, ParamOfs, SkillLevOfs, 0xA09DC380, 2, 2, 0);
  return 1;
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
