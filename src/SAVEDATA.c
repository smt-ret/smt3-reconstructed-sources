#include "types.h"

typedef struct GameFileInfo_t GameFileInfo_t;
typedef struct SAVEDATA SAVEDATA;
typedef struct SAVEDATA_GameFileInfo_tag SAVEDATA_GameFileInfo_tag;
typedef struct SAVEDATA_datUnitWork_tag SAVEDATA_datUnitWork_tag;
typedef struct SAVEDATA_dds3AdditionWork_tag SAVEDATA_dds3AdditionWork_tag;
typedef struct SAVEDATA_dds3GlobalWork_tag SAVEDATA_dds3GlobalWork_tag;
typedef struct SAVEDATA_dds3SystemVer7_tag SAVEDATA_dds3SystemVer7_tag;
typedef struct SAVEDATA_dds3SystemWork_tag SAVEDATA_dds3SystemWork_tag;
typedef struct SAVEDATA_dds3WorkVer7_tag SAVEDATA_dds3WorkVer7_tag;
typedef struct SAVEDATA_evtMoon_tag SAVEDATA_evtMoon_tag;
typedef struct SAVEDATA_fclEncycRecord_tag SAVEDATA_fclEncycRecord_tag;
typedef struct SAVEDATA_fclencyceelem_tag SAVEDATA_fclencyceelem_tag;
typedef struct SAVEDATA_fldAutoMapBuff31_tag SAVEDATA_fldAutoMapBuff31_tag;
typedef struct SAVEDATA_fldAutoMapBuffEX_tag SAVEDATA_fldAutoMapBuffEX_tag;
typedef struct SAVEDATA_fldAutoMapBuff_tag SAVEDATA_fldAutoMapBuff_tag;
typedef struct SAVEDATA_fldBlockBuff_tag SAVEDATA_fldBlockBuff_tag;
typedef struct SAVEDATA_fldSave_tag SAVEDATA_fldSave_tag;
typedef struct dds3AdditionWork_t dds3AdditionWork_t;
typedef struct dds3GlobalWork_t dds3GlobalWork_t;
typedef struct fldBlockBuff_t fldBlockBuff_t;
typedef struct fldRunSuspendData fldRunSuspendData;
typedef struct fldUnitControl_t fldUnitControl_t;

struct SAVEDATA_fldAutoMapBuff_tag {
    u32 blkOpenFlg00[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg01[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg02[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg03[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg04[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg05[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg06[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg07[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg08[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg09[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg10[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg11[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg12[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg13[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg14[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg15[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg16[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg17[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg18[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg19[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg20[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg21[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg22[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg23[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg24[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg25[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg26[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg27[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg28[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg29[UNKNOWN_ARRAY_SIZE];
};

struct SAVEDATA_fldAutoMapBuff31_tag {
    u32 blkOpenFlg00[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg01[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg02[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg03[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg04[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg05[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg06[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg07[UNKNOWN_ARRAY_SIZE];
};

struct SAVEDATA_fldAutoMapBuffEX_tag {
    u32 blkOpenFlg00[UNKNOWN_ARRAY_SIZE];
    u32 blkOpenFlg01[UNKNOWN_ARRAY_SIZE];
};

struct SAVEDATA_fclencyceelem_tag {
    u16 id;
    u16 reserved0;
    u16 maxhp;
    u16 maxmp;
    u32 exp;
    u16 level;
    s8 param[UNKNOWN_ARRAY_SIZE];
    s8 skillparam[UNKNOWN_ARRAY_SIZE];
    u16 skillcnt;
    u16 skill[UNKNOWN_ARRAY_SIZE];
    s8 mitamaparam[UNKNOWN_ARRAY_SIZE];
    s8 levelupparam[UNKNOWN_ARRAY_SIZE];
    u16 keisyoskill[UNKNOWN_ARRAY_SIZE];
    u8 keiattr[UNKNOWN_ARRAY_SIZE];
    u16 hensinmae;
    u16 reserved1;
    u32 flag;
    u32 reserved2;
    u32 hensinmaeexp;
};

struct SAVEDATA_dds3WorkVer7_tag {
    SAVEDATA_fldAutoMapBuff_tag amap;
    SAVEDATA_fldAutoMapBuff31_tag amap31;
    SAVEDATA_fldAutoMapBuffEX_tag amapEX;
    SAVEDATA_fclencyceelem_tag dante_pelem;
    s64 saveTime;
    s8 autoMapOpen[UNKNOWN_ARRAY_SIZE];
    u8 fldRunWork[UNKNOWN_ARRAY_SIZE];
    s8 autoMapOpenEX[UNKNOWN_ARRAY_SIZE];
    s8 reserved[UNKNOWN_ARRAY_SIZE];
};

struct SAVEDATA_dds3SystemVer7_tag {
    s16 Transport_Count;
    s16 Combine_Count;
    s16 Purchase_Bit;
    s16 Race_Bit;
    s16 EndingList;
    s16 GiftCount;
    s16 WeakCount;
    s16 TalkJoin;
    u32 Bad_Bit;
    u32 MagaTama_Bit;
    s8 reserved[UNKNOWN_ARRAY_SIZE];
};

struct SAVEDATA_GameFileInfo_tag {
    u16 verstr[UNKNOWN_ARRAY_SIZE];
    u16 ver;
    u16 TmnlMode;
    u16 TmnlId;
    u16 Lv;
    u16 mode;
    s32 PlayTime;
    s16 endcnt;
    s16 newfile;
    char *cname_code;
    u16 cname_nums;
    char *pad3;
    u16 dante_mode;
    u16 end_list[UNKNOWN_ARRAY_SIZE];
};

struct SAVEDATA_evtMoon_tag {
    s32 Stat;
    s32 Age;
    s32 TakaraCnt;
    s32 pub;
    f32 MoveCnt;
};

struct SAVEDATA_fldSave_tag {
    SAVEDATA_fldBlockBuff_tag PushBlock00[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock01[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock02[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock03[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock04[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock05[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock06[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock07[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock08[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock09[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock10[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock11[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock12[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock13[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock14[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock15[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock16[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock17[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock18[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock19[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock20[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock21[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock22[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock23[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock24[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock25[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock26[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock27[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock28[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock29[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock30[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock31[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock32[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock33[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock34[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock35[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock36[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock37[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock38[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldBlockBuff_tag PushBlock39[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldAutoMapBuff_tag amap;
    u8 takara[UNKNOWN_ARRAY_SIZE];
    s16 tmnltype;
    s16 tmnlid;
    s32 AnahoriCnt;
    u8 takara2[UNKNOWN_ARRAY_SIZE];
    s32 pub[UNKNOWN_ARRAY_SIZE];
};

struct SAVEDATA_fclEncycRecord_tag {
    s32 num;
    u32 reserved0;
    u32 reserved1;
    u32 reserved2;
    SAVEDATA_fclencyceelem_tag pelem[UNKNOWN_ARRAY_SIZE];
};

struct SAVEDATA_dds3GlobalWork_tag {
    SAVEDATA_GameFileInfo_tag GameFileInfo;
    s32 runtime;
    s32 playtime;
    s32 IntVariable[UNKNOWN_ARRAY_SIZE];
    f32 FloatVariable[UNKNOWN_ARRAY_SIZE];
    s32 EventBit[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_evtMoon_tag Moon;
    s32 maka;
    u32 stat;
    s32 maxstock;
    SAVEDATA_datUnitWork_tag unitwork[UNKNOWN_ARRAY_SIZE];
    s32 stocklist[UNKNOWN_ARRAY_SIZE];
    s32 stockcnt;
    u8 item[UNKNOWN_ARRAY_SIZE];
    s32 boss_press00[UNKNOWN_ARRAY_SIZE];
    s32 boss_press01[UNKNOWN_ARRAY_SIZE];
    s32 boss_press02[UNKNOWN_ARRAY_SIZE];
    s32 boss_press03[UNKNOWN_ARRAY_SIZE];
    s32 boss_press04[UNKNOWN_ARRAY_SIZE];
    s32 boss_press05[UNKNOWN_ARRAY_SIZE];
    s32 boss_press06[UNKNOWN_ARRAY_SIZE];
    s32 boss_press07[UNKNOWN_ARRAY_SIZE];
    s32 boss_press08[UNKNOWN_ARRAY_SIZE];
    s32 boss_press09[UNKNOWN_ARRAY_SIZE];
    s32 boss_press10[UNKNOWN_ARRAY_SIZE];
    s32 boss_press11[UNKNOWN_ARRAY_SIZE];
    s32 boss_press12[UNKNOWN_ARRAY_SIZE];
    s32 boss_press13[UNKNOWN_ARRAY_SIZE];
    s32 boss_press14[UNKNOWN_ARRAY_SIZE];
    s32 boss_press15[UNKNOWN_ARRAY_SIZE];
    s32 boss_press16[UNKNOWN_ARRAY_SIZE];
    s32 boss_press17[UNKNOWN_ARRAY_SIZE];
    s32 boss_press18[UNKNOWN_ARRAY_SIZE];
    s32 boss_press19[UNKNOWN_ARRAY_SIZE];
    s32 boss_press20[UNKNOWN_ARRAY_SIZE];
    s32 boss_press21[UNKNOWN_ARRAY_SIZE];
    s32 boss_press22[UNKNOWN_ARRAY_SIZE];
    s32 boss_press23[UNKNOWN_ARRAY_SIZE];
    s32 boss_press24[UNKNOWN_ARRAY_SIZE];
    s32 boss_press25[UNKNOWN_ARRAY_SIZE];
    s32 boss_press26[UNKNOWN_ARRAY_SIZE];
    s32 boss_press27[UNKNOWN_ARRAY_SIZE];
    s32 boss_press28[UNKNOWN_ARRAY_SIZE];
    s32 boss_press29[UNKNOWN_ARRAY_SIZE];
    s32 boss_press30[UNKNOWN_ARRAY_SIZE];
    s32 boss_press31[UNKNOWN_ARRAY_SIZE];
    s32 boss_press32[UNKNOWN_ARRAY_SIZE];
    s32 boss_press33[UNKNOWN_ARRAY_SIZE];
    s32 boss_press34[UNKNOWN_ARRAY_SIZE];
    s32 boss_press35[UNKNOWN_ARRAY_SIZE];
    s32 boss_press36[UNKNOWN_ARRAY_SIZE];
    s32 boss_press37[UNKNOWN_ARRAY_SIZE];
    s32 boss_press38[UNKNOWN_ARRAY_SIZE];
    s32 boss_press39[UNKNOWN_ARRAY_SIZE];
    u8 syakkincnt[UNKNOWN_ARRAY_SIZE];
    u8 negoques[UNKNOWN_ARRAY_SIZE];
    u8 kotowari[UNKNOWN_ARRAY_SIZE];
    u16 wakimi_id;
    u16 bouga_cnt;
    f32 encountkyori;
    u16 encountcnt;
    u8 heartsequip;
    u8 hearts[UNKNOWN_ARRAY_SIZE];
    u8 heartsskcnt[UNKNOWN_ARRAY_SIZE];
    u8 heartscnt;
    u8 name_nums00[UNKNOWN_ARRAY_SIZE];
    u8 name_nums01[UNKNOWN_ARRAY_SIZE];
    u8 name_nums02[UNKNOWN_ARRAY_SIZE];
    u8 name_nums03[UNKNOWN_ARRAY_SIZE];
    u8 name_code00[UNKNOWN_ARRAY_SIZE];
    u8 name_code01[UNKNOWN_ARRAY_SIZE];
    u8 name_code02[UNKNOWN_ARRAY_SIZE];
    u8 name_code03[UNKNOWN_ARRAY_SIZE];
    u8 cname_code00[UNKNOWN_ARRAY_SIZE];
    u8 cname_code01[UNKNOWN_ARRAY_SIZE];
    u8 cname_code02[UNKNOWN_ARRAY_SIZE];
    u8 cname_code03[UNKNOWN_ARRAY_SIZE];
    u8 cname_nums[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fldSave_tag fldSave;
    s32 config_data[UNKNOWN_ARRAY_SIZE];
    s32 dmy;
    u16 hearts_sk00[UNKNOWN_ARRAY_SIZE];
    u16 hearts_sk01[UNKNOWN_ARRAY_SIZE];
    u16 hearts_sk02[UNKNOWN_ARRAY_SIZE];
    u16 hearts_sk03[UNKNOWN_ARRAY_SIZE];
    u16 hearts_sk04[UNKNOWN_ARRAY_SIZE];
    u16 hearts_sk05[UNKNOWN_ARRAY_SIZE];
    u16 hearts_sk06[UNKNOWN_ARRAY_SIZE];
    u16 hearts_sk07[UNKNOWN_ARRAY_SIZE];
    u16 hearts_sk08[UNKNOWN_ARRAY_SIZE];
    u16 hearts_sk09[UNKNOWN_ARRAY_SIZE];
    u16 hearts_sk10[UNKNOWN_ARRAY_SIZE];
    u16 hearts_sk11[UNKNOWN_ARRAY_SIZE];
    u16 hearts_sk12[UNKNOWN_ARRAY_SIZE];
    u16 hearts_sk13[UNKNOWN_ARRAY_SIZE];
    u16 hearts_sk14[UNKNOWN_ARRAY_SIZE];
    u16 hearts_sk15[UNKNOWN_ARRAY_SIZE];
    u16 hearts_sk16[UNKNOWN_ARRAY_SIZE];
    u16 hearts_sk17[UNKNOWN_ARRAY_SIZE];
    u16 hearts_sk18[UNKNOWN_ARRAY_SIZE];
    u16 hearts_sk19[UNKNOWN_ARRAY_SIZE];
    u16 hearts_sk20[UNKNOWN_ARRAY_SIZE];
    u16 hearts_sk21[UNKNOWN_ARRAY_SIZE];
    u16 hearts_sk22[UNKNOWN_ARRAY_SIZE];
    u16 hearts_sk23[UNKNOWN_ARRAY_SIZE];
    u16 hearts_sk24[UNKNOWN_ARRAY_SIZE];
    u16 hearts_sk25[UNKNOWN_ARRAY_SIZE];
    u16 hearts_sk26[UNKNOWN_ARRAY_SIZE];
    u16 hearts_sk27[UNKNOWN_ARRAY_SIZE];
    u16 hearts_sk28[UNKNOWN_ARRAY_SIZE];
    u16 hearts_sk29[UNKNOWN_ARRAY_SIZE];
    u16 hearts_sk30[UNKNOWN_ARRAY_SIZE];
    u16 hearts_sk31[UNKNOWN_ARRAY_SIZE];
    s8 hearts_up_param00[UNKNOWN_ARRAY_SIZE];
    s8 hearts_up_param01[UNKNOWN_ARRAY_SIZE];
    s8 hearts_up_param02[UNKNOWN_ARRAY_SIZE];
    s8 hearts_up_param03[UNKNOWN_ARRAY_SIZE];
    s8 hearts_up_param04[UNKNOWN_ARRAY_SIZE];
    s8 hearts_up_param05[UNKNOWN_ARRAY_SIZE];
    s8 hearts_up_param06[UNKNOWN_ARRAY_SIZE];
    s8 hearts_up_param07[UNKNOWN_ARRAY_SIZE];
    s8 hearts_up_param08[UNKNOWN_ARRAY_SIZE];
    s8 hearts_up_param09[UNKNOWN_ARRAY_SIZE];
    s8 hearts_up_param10[UNKNOWN_ARRAY_SIZE];
    s8 hearts_up_param11[UNKNOWN_ARRAY_SIZE];
    s8 hearts_up_param12[UNKNOWN_ARRAY_SIZE];
    s8 hearts_up_param13[UNKNOWN_ARRAY_SIZE];
    s8 hearts_up_param14[UNKNOWN_ARRAY_SIZE];
    s8 hearts_up_param15[UNKNOWN_ARRAY_SIZE];
    s8 hearts_up_param16[UNKNOWN_ARRAY_SIZE];
    s8 hearts_up_param17[UNKNOWN_ARRAY_SIZE];
    s8 hearts_up_param18[UNKNOWN_ARRAY_SIZE];
    s8 hearts_up_param19[UNKNOWN_ARRAY_SIZE];
    s8 hearts_up_param20[UNKNOWN_ARRAY_SIZE];
    s8 hearts_up_param21[UNKNOWN_ARRAY_SIZE];
    s8 hearts_up_param22[UNKNOWN_ARRAY_SIZE];
    s8 hearts_up_param23[UNKNOWN_ARRAY_SIZE];
    s8 hearts_up_param24[UNKNOWN_ARRAY_SIZE];
    s8 hearts_up_param25[UNKNOWN_ARRAY_SIZE];
    s8 hearts_up_param26[UNKNOWN_ARRAY_SIZE];
    s8 hearts_up_param27[UNKNOWN_ARRAY_SIZE];
    s8 hearts_up_param28[UNKNOWN_ARRAY_SIZE];
    s8 hearts_up_param29[UNKNOWN_ARRAY_SIZE];
    s8 hearts_up_param30[UNKNOWN_ARRAY_SIZE];
    s8 hearts_up_param31[UNKNOWN_ARRAY_SIZE];
    SAVEDATA_fclEncycRecord_tag encyc_record;
    SAVEDATA_fldAutoMapBuff31_tag amap31;
    SAVEDATA_fldAutoMapBuffEX_tag amapEX;
};

struct SAVEDATA_dds3AdditionWork_tag {
    s32 fieldID;
    s32 areaID;
    s32 CamTableIdx;
    s32 BgmId;
    s32 SeId;
    sdfVector4_t playerPos;
    sdfVector4_t playerRot;
    u8 WapIdx;
    s32 nameU;
    s32 nameD;
    u8 CamMode;
    s32 AmFloor;
    u8 gFldNowDZone;
    s8 dummy[UNKNOWN_ARRAY_SIZE];
};

struct SAVEDATA_dds3SystemWork_tag {
    s8 dlcflg[UNKNOWN_ARRAY_SIZE];
    s8 dummy[UNKNOWN_ARRAY_SIZE];
};

struct SAVEDATA {
    SAVEDATA_dds3WorkVer7_tag *saveVer7[20];
    SAVEDATA_dds3WorkVer7_tag suspendVer7;
    SAVEDATA_dds3SystemVer7_tag SystemVer7;
    SAVEDATA_dds3GlobalWork_tag *saveBuff[20];
    SAVEDATA_dds3GlobalWork_tag suspendBuff;
    SAVEDATA_dds3AdditionWork_tag AdditionBuff;
    SAVEDATA_dds3SystemWork_tag SystemBuff;
};

struct SAVEDATA_datUnitWork_tag {
    u32 flag;
    u16 id;
    u16 hp;
    u16 maxhp;
    u16 mp;
    u16 maxmp;
    u16 badstatus;
    u32 exp;
    u16 level;
    s8 param[UNKNOWN_ARRAY_SIZE];
    s8 skillparam[UNKNOWN_ARRAY_SIZE];
    u16 uniqueid;
    u16 reserve1;
    u16 reserve2;
    u16 namecode[UNKNOWN_ARRAY_SIZE];
    s32 skillcnt;
    s32 skill[UNKNOWN_ARRAY_SIZE];
    s16 nowcommand;
    u16 nowindex;
    s16 nowtarea;
    s16 nowtform;
    s16 prevcommand;
    u16 previndex;
    s16 prevtarea;
    s16 prevtform;
    s8 mitamaparam[UNKNOWN_ARRAY_SIZE];
    s8 levelupparam[UNKNOWN_ARRAY_SIZE];
    u16 keisyoskill[UNKNOWN_ARRAY_SIZE];
    u8 keiattr[UNKNOWN_ARRAY_SIZE];
    u16 hensinmae;
    u16 getdevilhearts[UNKNOWN_ARRAY_SIZE];
    u32 hensinmaeexp;
    u16 fullnamecode[UNKNOWN_ARRAY_SIZE];
};

struct SAVEDATA_fldBlockBuff_tag {
    u16 MviewOffFlg;
    u16 ManimeOffFlg;
    u16 hitOffFlg;
    u16 EviewOffFlg;
    u16 EanimeOffFlg;
    u8 EanimeCngID[UNKNOWN_ARRAY_SIZE];
    u16 npcOffFlg;
    u16 gimicLastFlg;
};

void BackupFldRunWork(void);
void RestoreFldRunWork(u8 **data);
u8 **ToArray(fldRunSuspendData *this);
void backupAddition(SAVEDATA *this);
void backupBuff(SAVEDATA *this, SAVEDATA_dds3GlobalWork_tag *saveData, dds3GlobalWork_t *data, SAVEDATA_dds3WorkVer7_tag *saveDataVer7);
void backupPushBlock(SAVEDATA *this, SAVEDATA_fldBlockBuff_tag ***save, fldBlockBuff_t ***data);
void dds3GlobalWork_t__Init(dds3GlobalWork_t *this);
fldUnitControl_t *fldGetUnitControl(void);
void initAddition(SAVEDATA *this);
void initCreate(SAVEDATA *this, SAVEDATA_dds3GlobalWork_tag *data, SAVEDATA_dds3WorkVer7_tag *dataVer7);
void initPushBlock(SAVEDATA *this, SAVEDATA_fldBlockBuff_tag ***data);
void restoreBuff(SAVEDATA *this, SAVEDATA_dds3GlobalWork_tag *loadData, dds3GlobalWork_t **data, SAVEDATA_dds3WorkVer7_tag *loadDataVer7);
void restoreGameFileInfo(SAVEDATA *this, SAVEDATA_GameFileInfo_tag *load, GameFileInfo_t **data, SAVEDATA_dds3WorkVer7_tag *loadDataVer7);
void restorePushBlock(SAVEDATA *this, SAVEDATA_fldBlockBuff_tag ***load, fldBlockBuff_t ***data);

// 0x18a38f0
void backupAddition(SAVEDATA *this) {
  fldUnitControl_t_o *UnitControl;
  struct dds3PoseSet_t_o *poseset;
  s64 v8;
  f32 z;
  struct dds3PoseSet_t_o *v10;
  s64 v11;
  f32 v12;

  this->AdditionBuff.fieldID = fldSceneParam.loadField;
  this->AdditionBuff.areaID = fldSceneParam.loadArea;
  this->AdditionBuff.CamTableIdx = fldGb->CamTableIdx;
  this->AdditionBuff.BgmId = fldGb->BgmId;
  this->AdditionBuff.SeId = fldGb->FootSE;
  this->AdditionBuff.WapIdx = gSuspendWarpIndex;
  this->AdditionBuff.CamMode = BYTE1(gSuspendWarpIndex);
  this->AdditionBuff.nameU = fldGb->nameU;
  this->AdditionBuff.nameD = fldGb->nameD;
  this->AdditionBuff.AmFloor = fldGb->AmFloor;
  this->AdditionBuff.gFldNowDZone = gFldNowDZone;
  UnitControl = fldGetUnitControl();
  poseset = UnitControl->handle->poseset;
  v8 = *&poseset->pos.x;
  z = poseset->pos.z;
  *&poseset = poseset->pos.w;
  *&this->AdditionBuff.playerPos.x = v8;
  this->AdditionBuff.playerPos.z = z;
  LODWORD(this->AdditionBuff.playerPos.w) = poseset;
  v10 = UnitControl->handle->poseset;
  v11 = *&v10->rot.x;
  v12 = v10->rot.z;
  *&v10 = v10->rot.w;
  *&this->AdditionBuff.playerRot.x = v11;
  this->AdditionBuff.playerRot.z = v12;
  LODWORD(this->AdditionBuff.playerRot.w) = v10;
}

// 0x189e9d0
void backupBuff(SAVEDATA *this, SAVEDATA_dds3GlobalWork_tag *saveData, dds3GlobalWork_t *data, SAVEDATA_dds3WorkVer7_tag *saveDataVer7) {
    backupPushBlock(0, 0, 0);
    BackupFldRunWork();
    ToArray(0);
}

// 0x189e7d0
void backupData(SAVEDATA *this, s32 num, dds3GlobalWork_t *data, bool init) {
  SAVEDATA_o *v8;
  struct SAVEDATA_dds3GlobalWork_tag_array *saveBuff;
  struct SAVEDATA_dds3WorkVer7_tag_array *saveVer7;
  struct System_Char_array *verstr;
  struct System_Char_array *v16;
  struct System_Char_array *v18;
  struct GameFileInfo_t_o *GameFileInfo;

  v8 = this;
  if ((byte_3F5A9D2 & 1) != 0)
  {
    if (!init)
    data = Allocate(dds3GlobalWork_t);
    dds3GlobalWork_t___ctor(data);
    dds3GlobalWork_t__Init(data);
    verstr = data->GameFileInfo->verstr;
    verstr->m_Items[0] = 86;
    v16 = data->GameFileInfo->verstr;
    v16->m_Items[1] = 69;
    v18 = data->GameFileInfo->verstr;
    v18->m_Items[2] = 82;
    GameFileInfo = data->GameFileInfo;
    GameFileInfo->ver = HIWORD(this->suspendVer7.amap.blkOpenFlg20->m_Items[20]);
    if (num <= 19)
  }
  if (init)
  if (num <= 19)
  {
    saveBuff = v8->saveBuff;
    saveVer7 = v8->saveVer7;
    backupBuff(this, &saveBuff->m_Items[num], data, &saveVer7->m_Items[num]);
    return;
  }
  backupBuff(this, &v8->suspendBuff, data, &v8->suspendVer7);
  if (!init)
    backupAddition(v8);
}

// 0x189e4a0
void backupPushBlock(SAVEDATA *this, SAVEDATA_fldBlockBuff_tag ***save, fldBlockBuff_t ***data) {
  u64 v6;
  s64 v7;
  SAVEDATA_fldBlockBuff_tag_array *v8;
  SAVEDATA_fldBlockBuff_tag_array *v11;
  SAVEDATA_fldBlockBuff_tag_array *v14;
  SAVEDATA_fldBlockBuff_tag_array *v17;
  SAVEDATA_fldBlockBuff_tag_array *v20;
  SAVEDATA_fldBlockBuff_tag_array *v25;
  SAVEDATA_fldBlockBuff_tag_array *v28;
  u16 gimicLastFlg;

  v6 = 0;
  v7 = 58;
  do
  {
    v8 = *save;
    *(v8 + v7 - 26) = (*data)->m_Items[v6]->MviewOffFlg;
    v11 = *save;
    *(v11 + v7 - 24) = (*data)->m_Items[v6]->ManimeOffFlg;
    v14 = *save;
    *(v14 + v7 - 22) = (*data)->m_Items[v6]->hitOffFlg;
    v17 = *save;
    *(v17 + v7 - 20) = (*data)->m_Items[v6]->EviewOffFlg;
    v20 = *save;
    *(v20 + v7 - 18) = (*data)->m_Items[v6]->EanimeOffFlg;
    Copy_3886320(
      (*data)->m_Items[v6]->EanimeCngID,
      *(*save + v7 - 10),
      *(*(*save + v7 - 10) + 24LL),
      0);
    v25 = *save;
    *(v25 + v7 - 2) = (*data)->m_Items[v6]->npcOffFlg;
    v28 = *save;
    gimicLastFlg = (*data)->m_Items[v6]->gimicLastFlg;
    ++v6;
    *(&v28->obj.klass + v7) = gimicLastFlg;
    v7 += 32;
  }
  while (v6 != 32);
}

// 0x18a3aa0
void backupSystem(SAVEDATA *this) {
  Copy_3886320(SystemWork->dlcflg, this->SystemBuff.dlcflg, this->SystemBuff.dlcflg->max_length);
  Copy_3886320(SystemWork->dummy, this->SystemBuff.dummy, this->SystemBuff.dummy->max_length);
}

// 0x1893400
void backupSystemVer7(SAVEDATA *this) {
  this->SystemVer7.Transport_Count = SystemWork->Transport_Count;
  this->SystemVer7.Combine_Count = SystemWork->Combine_Count;
  this->SystemVer7.Purchase_Bit = SystemWork->Purchase_Bit;
  this->SystemVer7.Race_Bit = SystemWork->Race_Bit;
  this->SystemVer7.EndingList = SystemWork->EndingList;
  this->SystemVer7.GiftCount = SystemWork->GiftCount;
  this->SystemVer7.WeakCount = SystemWork->WeakCount;
  this->SystemVer7.TalkJoin = SystemWork->TalkJoin;
  this->SystemVer7.Bad_Bit = SystemWork->Bad_Bit;
  this->SystemVer7.MagaTama_Bit = SystemWork->MagaTama_Bit;
}

// 0x1894d50
void initAddition(SAVEDATA *this) {
  struct System_SByte_array *v3;
  UnityEngine_Vector3_o v4;
  UnityEngine_Vector3_o v5;

  this->AdditionBuff.SeId = 0;
  *&this->AdditionBuff.CamTableIdx = 0;
  *&this->AdditionBuff.fieldID = 0;
  v4.x = 0.0;
  v4.y = 0.0;
  v4.z = 0.0;
  this->AdditionBuff.playerPos = op_Implicit(v4, 0);
  v5.x = 0.0;
  v5.y = 0.0;
  v5.z = 0.0;
  this->AdditionBuff.playerRot = op_Implicit(v5, 0);
  this->AdditionBuff.WapIdx = 0;
  v3 = NewSpecific(sbyte, 5u);
  this->AdditionBuff.AmFloor = 0;
  this->AdditionBuff.dummy = v3;
  this->AdditionBuff.gFldNowDZone = 0;
  this->AdditionBuff.CamMode = 0;
  *&this->AdditionBuff.nameU = 0;
}

// 0x18936b0
void initCreate(SAVEDATA *this, SAVEDATA_dds3GlobalWork_tag *data, SAVEDATA_dds3WorkVer7_tag *dataVer7) {
    initPushBlock(0, 0);
}

// 0x1894eb0
void initPushBlock(SAVEDATA *this, SAVEDATA_fldBlockBuff_tag ***data) {
  SAVEDATA_fldBlockBuff_tag_array *v4;
  SAVEDATA_fldBlockBuff_tag_array *v5;
  s64 v6;
  u64 v7;
  u64 *v9;
  SAVEDATA_fldBlockBuff_tag_array *v10;
  struct System_Byte_array *v11;

  v4 = NewSpecific(SAVEDATA_fldBlockBuff_tag, 0x20u);
  *data = v4;
  v5 = v4;
  v6 = 0;
  v7 = 0;
  while (1)
  {
    v9 = (&v5->obj.klass + v6 * 32);
    v9[6] = 0;
    v9[7] = 0;
    v9[4] = 0;
    v9[5] = 0;
    v10 = *data;
    v11 = NewSpecific(byte, 0x10u);
    v10->m_Items[v6].EanimeCngID = v11;
    if (v7 == 31)
      break;
    v5 = *data;
    ++v7;
    ++v6;
    if (v7 >= LODWORD((*data)->max_length))
  }
}

// 0x1894e40
void initSystem(SAVEDATA *this) {
  this->SystemBuff.dlcflg = NewSpecific(sbyte, 8u);
  this->SystemBuff.dummy = NewSpecific(sbyte, 0x14u);
}

// 0x1893510
void initSystemVer7(SAVEDATA *this) {
  *&this->SystemVer7.EndingList = 0;
  *&this->SystemVer7.Bad_Bit = 0;
  *&this->SystemVer7.Transport_Count = 0;
  this->SystemVer7.reserved = NewSpecific(sbyte, 0x114u);
}

// 0x1893570
void initialize(SAVEDATA *this) {
  u64 v4;
  s64 v5;
  s64 v6;
  struct SAVEDATA_dds3GlobalWork_tag_array *saveBuff;
  struct SAVEDATA_dds3WorkVer7_tag_array *saveVer7;
  SAVEDATA_dds3GlobalWork_tag_o *v10;

  v4 = 0;
  v5 = 32;
  v6 = 32;
  do
  {
    saveBuff = this->saveBuff;
    saveVer7 = this->saveVer7;
    v10 = (saveBuff + v5);
    initCreate(this, v10, (saveVer7 + v6));
    ++v4;
    v6 += 456;
    v5 += 1880;
  }
  while (v4 != 20);
  initCreate(this, &this->suspendBuff, &this->suspendVer7);
  initAddition(this);
  this->SystemBuff.dlcflg = NewSpecific(sbyte, 8u);
  this->SystemBuff.dummy = NewSpecific(sbyte, 0x14u);
  *&this->SystemVer7.EndingList = 0;
  *&this->SystemVer7.Bad_Bit = 0;
  *&this->SystemVer7.Transport_Count = 0;
  this->SystemVer7.reserved = NewSpecific(sbyte, 0x114u);
}

// 0x189e300
void restoreAddition(SAVEDATA *this, dds3AdditionWork_t **addition) {
  dds3AdditionWork_t_o *v3;
  f32 z;
  f32 w;
  dds3AdditionWork_t_o *v6;
  f32 v7;
  f32 v8;

  (*addition)->fieldID = this->AdditionBuff.fieldID;
  (*addition)->areaID = this->AdditionBuff.areaID;
  v3 = *addition;
  z = this->AdditionBuff.playerPos.z;
  w = this->AdditionBuff.playerPos.w;
  *&v3->playerPos.x = *&this->AdditionBuff.playerPos.x;
  v3->playerPos.z = z;
  v3->playerPos.w = w;
  v6 = *addition;
  v7 = this->AdditionBuff.playerRot.z;
  v8 = this->AdditionBuff.playerRot.w;
  *&v6->playerRot.x = *&this->AdditionBuff.playerRot.x;
  v6->playerRot.z = v7;
  v6->playerRot.w = v8;
  (*addition)->CamTableIdx = this->AdditionBuff.CamTableIdx;
  (*addition)->BgmId = this->AdditionBuff.BgmId;
  (*addition)->SeId = this->AdditionBuff.SeId;
  (*addition)->WarpIndex = this->AdditionBuff.WapIdx;
  (*addition)->CamMode = this->AdditionBuff.CamMode;
  (*addition)->nameU = this->AdditionBuff.nameU;
  (*addition)->nameD = this->AdditionBuff.nameD;
  (*addition)->AmFloor = this->AdditionBuff.AmFloor;
  (*addition)->gFldNowDZone = this->AdditionBuff.gFldNowDZone;
  Copy_3886320(
    this->AdditionBuff.dummy,
    (*addition)->dummy,
    this->AdditionBuff.dummy->max_length,
    0);
}

// 0x18958f0
void restoreBuff(SAVEDATA *this, SAVEDATA_dds3GlobalWork_tag *loadData, dds3GlobalWork_t **data, SAVEDATA_dds3WorkVer7_tag *loadDataVer7) {
    restoreGameFileInfo(0, 0, 0, 0);
    restorePushBlock(0, 0, 0);
    RestoreFldRunWork(0);
}

// 0x18956e0
void restoreData(SAVEDATA *this, s32 num, dds3GlobalWork_t **data, dds3AdditionWork_t **addition) {
  struct SAVEDATA_dds3GlobalWork_tag_array *saveBuff;
  s64 v9;
  struct SAVEDATA_dds3WorkVer7_tag_array *saveVer7;
  SAVEDATA_o *v13;
  SAVEDATA_o *v16;
  dds3AdditionWork_t_o *v18;
  f32 z;
  f32 w;
  dds3AdditionWork_t_o *v21;
  f32 v22;
  f32 v23;
  SAVEDATA_dds3WorkVer7_tag_o v24;
  SAVEDATA_dds3GlobalWork_tag_o v25;
  SAVEDATA_dds3WorkVer7_tag_o v26;
  SAVEDATA_dds3GlobalWork_tag_o dest;
  u8 v28[456];
  u8 v29[1880];

  if (num > 19)
  {
    memcpy(&v25, &this->suspendBuff, sizeof(v25));
    v16 = memcpy(&v24, &this->suspendVer7, sizeof(v24));
    restoreBuff(v16, &v25, data, &v24);
    (*addition)->fieldID = this->AdditionBuff.fieldID;
    (*addition)->areaID = this->AdditionBuff.areaID;
    v18 = *addition;
    z = this->AdditionBuff.playerPos.z;
    w = this->AdditionBuff.playerPos.w;
    *&v18->playerPos.x = *&this->AdditionBuff.playerPos.x;
    v18->playerPos.z = z;
    v18->playerPos.w = w;
    v21 = *addition;
    v22 = this->AdditionBuff.playerRot.z;
    v23 = this->AdditionBuff.playerRot.w;
    *&v21->playerRot.x = *&this->AdditionBuff.playerRot.x;
    v21->playerRot.z = v22;
    v21->playerRot.w = v23;
    (*addition)->CamTableIdx = this->AdditionBuff.CamTableIdx;
    (*addition)->BgmId = this->AdditionBuff.BgmId;
    (*addition)->SeId = this->AdditionBuff.SeId;
    (*addition)->WarpIndex = this->AdditionBuff.WapIdx;
    (*addition)->CamMode = this->AdditionBuff.CamMode;
    (*addition)->nameU = this->AdditionBuff.nameU;
    (*addition)->nameD = this->AdditionBuff.nameD;
    (*addition)->AmFloor = this->AdditionBuff.AmFloor;
    (*addition)->gFldNowDZone = this->AdditionBuff.gFldNowDZone;
    Copy_3886320(
      this->AdditionBuff.dummy,
      (*addition)->dummy,
      this->AdditionBuff.dummy->max_length,
      0);
  }
  else
  {
    saveBuff = this->saveBuff;
    v9 = num;
    memcpy(v29, &saveBuff->m_Items[num], sizeof(v29));
    saveVer7 = this->saveVer7;
    memcpy(v28, &saveVer7->m_Items[v9], sizeof(v28));
    memcpy(&dest, v29, sizeof(dest));
    v13 = memcpy(&v26, v28, sizeof(v26));
    restoreBuff(v13, &dest, data, &v26);
  }
}

// 0x1895110
void restoreGameFileInfo(SAVEDATA *this, SAVEDATA_GameFileInfo_tag *load, GameFileInfo_t **data, SAVEDATA_dds3WorkVer7_tag *loadDataVer7) {
  void *v8;

  v8 = *data;
  if (!*data)
  {
    v8 = Allocate(GameFileInfo_t);
    GameFileInfo_t___ctor(v8);
    *data = v8;
  }
  Copy_3886320(load->verstr, *(v8 + 2), *(*(v8 + 2) + 24LL), 0);
  (*data)->ver = load->ver;
  (*data)->TmnlMode = load->TmnlMode;
  (*data)->TmnlId = load->TmnlId;
  (*data)->Lv = load->Lv;
  (*data)->mode = load->mode;
  (*data)->PlayTime = load->PlayTime;
  (*data)->endcnt = load->endcnt;
  (*data)->newfile = load->newfile;
  (*data)->cname_code = load->cname_code;
  (*data)->cname_nums = load->cname_nums;
  (*data)->pad3 = load->pad3;
  (*data)->dante_mode = load->dante_mode;
  Copy_3886320(load->end_list, (*data)->end_list, (*data)->end_list->max_length, 0);
  (*data)->saveTime = loadDataVer7->saveTime;
  RestoreFldRunWork(loadDataVer7->fldRunWork);
  Copy_3886320(
    loadDataVer7->autoMapOpen,
    (*data)->autoMapOpen,
    (*data)->autoMapOpen->max_length,
    0);
  Copy_3886320(
    loadDataVer7->autoMapOpenEX,
    (*data)->autoMapOpenEX,
    (*data)->autoMapOpenEX->max_length,
    0);
}

// 0x1895290
void restorePushBlock(SAVEDATA *this, SAVEDATA_fldBlockBuff_tag ***load, fldBlockBuff_t ***data) {
  fldBlockBuff_t_array *v6;
  u64 v7;
  s64 v8;
  fldBlockBuff_t_array *v10;
  fldBlockBuff_t_o *v12;
  u32 *v28;
  u64 *v29;

  v6 = *data;
  if (!*data)
  {
    v6 = NewSpecific(fldBlockBuff_t, 0x20u);
    *data = v6;
  }
  v7 = 0;
  v8 = 58;
  while (1)
  {
    if (v6->m_Items[v7])
    {
      v10 = *data;
      if (v7 >= LODWORD((*data)->max_length))
    }
    else
    {
      v28 = *data;
      v29 = Allocate(fldBlockBuff_t);
      fldBlockBuff_t___ctor(v29);
      *&v28[2 * v7 + 8] = v29;
      v10 = *data;
    }
    v12 = v10->m_Items[v7];
    v12->MviewOffFlg = *(*load + v8 - 26);
    (*data)->m_Items[v7]->ManimeOffFlg = *(*load + v8 - 24);
    (*data)->m_Items[v7]->hitOffFlg = *(*load + v8 - 22);
    (*data)->m_Items[v7]->EviewOffFlg = *(*load + v8 - 20);
    (*data)->m_Items[v7]->EanimeOffFlg = *(*load + v8 - 18);
    Copy_3886320(
      *(*load + v8 - 10),
      (*data)->m_Items[v7]->EanimeCngID,
      (*data)->m_Items[v7]->EanimeCngID->max_length,
      0);
    (*data)->m_Items[v7]->npcOffFlg = *(*load + v8 - 2);
    (*data)->m_Items[v7]->gimicLastFlg = *(&(*load)->obj.klass + v8);
    if (v7 == 31)
      break;
    v6 = *data;
    ++v7;
    v8 += 32;
    if (v7 >= LODWORD((*data)->max_length))
  }
}

// 0x189e3e0
void restoreSystem(SAVEDATA *this) {
}

// 0x18932f0
void restoreSystemVer7(SAVEDATA *this) {
  SystemWork->Transport_Count = this->SystemVer7.Transport_Count;
  SystemWork->Combine_Count = this->SystemVer7.Combine_Count;
  SystemWork->Purchase_Bit = this->SystemVer7.Purchase_Bit;
  SystemWork->Race_Bit = this->SystemVer7.Race_Bit;
  SystemWork->EndingList = this->SystemVer7.EndingList;
  SystemWork->GiftCount = this->SystemVer7.GiftCount;
  SystemWork->WeakCount = this->SystemVer7.WeakCount;
  SystemWork->TalkJoin = this->SystemVer7.TalkJoin;
  SystemWork->Bad_Bit = this->SystemVer7.Bad_Bit;
  SystemWork->MagaTama_Bit = this->SystemVer7.MagaTama_Bit;
}

// 0x1894fb0
void setHeaderGameFileInfo(SAVEDATA *this, s32 num, GameFileInfo_t **data) {
  struct SAVEDATA_dds3GlobalWork_tag_array *saveBuff;
  Il2CppClass **v7;
  Il2CppClass *v8;
  Il2CppClass *v9;
  Il2CppClass *v10;
  Il2CppClass *v11;
  Il2CppClass *v12;
  Il2CppClass *v13;
  Il2CppClass *v14;
  struct SAVEDATA_dds3WorkVer7_tag_array *saveVer7;
  SAVEDATA_o *v17;
  SAVEDATA_GameFileInfo_tag_o *v19;
  SAVEDATA_dds3WorkVer7_tag_o *v20;
  s64 v21;
  s64 v22;
  struct System_String_o *cname_code;
  s64 v24;
  struct System_String_o *pad3;
  s64 v26;
  u8 v27[456];
  u64 v28[9];
  u8 dest[456];
  u64 v30[9];
  Il2CppClass *v31;
  Il2CppClass *v32;
  Il2CppClass *v33;
  Il2CppClass *v34;
  Il2CppClass *v35;
  Il2CppClass *v36;
  Il2CppClass *v37;
  Il2CppClass *v38;
  Il2CppClass *v39;

  if (num > 19)
  {
    v28[0] = this->suspendBuff.GameFileInfo.verstr;
    v21 = *&this->suspendBuff.GameFileInfo.ver;
    v22 = *&this->suspendBuff.GameFileInfo.mode;
    cname_code = this->suspendBuff.GameFileInfo.cname_code;
    v28[3] = *&this->suspendBuff.GameFileInfo.endcnt;
    v28[4] = cname_code;
    v28[1] = v21;
    v28[2] = v22;
    v24 = *&this->suspendBuff.GameFileInfo.cname_nums;
    pad3 = this->suspendBuff.GameFileInfo.pad3;
    v26 = *&this->suspendBuff.GameFileInfo.dante_mode;
    v28[8] = this->suspendBuff.GameFileInfo.end_list;
    v28[7] = v26;
    v28[5] = v24;
    v28[6] = pad3;
    v17 = memcpy(v27, &this->suspendVer7, sizeof(v27));
    v19 = v28;
    v20 = v27;
  }
  else
  {
    saveBuff = this->saveBuff;
    v7 = &saveBuff->obj.klass + 235 * num;
    v31 = v7[4];
    v8 = v7[5];
    v9 = v7[6];
    v10 = v7[8];
    v34 = v7[7];
    v35 = v10;
    v32 = v8;
    v33 = v9;
    v11 = v7[9];
    v12 = v7[10];
    v14 = v7[11];
    v13 = v7[12];
    v38 = v14;
    v39 = v13;
    v36 = v11;
    v37 = v12;
    saveVer7 = this->saveVer7;
    v17 = memcpy(dest, &saveVer7->m_Items[num], sizeof(dest));
    v19 = v30;
    v30[0] = v31;
    v30[1] = v32;
    v20 = dest;
    v30[3] = v34;
    v30[4] = v35;
    v30[2] = v33;
    v30[7] = v38;
    v30[8] = v39;
    v30[5] = v36;
    v30[6] = v37;
  }
  restoreGameFileInfo(v17, v19, data, v20);
}
