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
    u32 *blkOpenFlg00;
    u32 blkOpenFlg01[32];
    u32 blkOpenFlg02[32];
    u32 blkOpenFlg03[32];
    u32 blkOpenFlg04[32];
    u32 blkOpenFlg05[32];
    u32 blkOpenFlg06[32];
    u32 blkOpenFlg07[32];
    u32 blkOpenFlg08[32];
    u32 blkOpenFlg09[32];
    u32 blkOpenFlg10[32];
    u32 blkOpenFlg11[32];
    u32 blkOpenFlg12[32];
    u32 blkOpenFlg13[32];
    u32 blkOpenFlg14[32];
    u32 blkOpenFlg15[32];
    u32 blkOpenFlg16[32];
    u32 blkOpenFlg17[32];
    u32 blkOpenFlg18[32];
    u32 blkOpenFlg19[32];
    u32 blkOpenFlg20[32];
    u32 blkOpenFlg21[32];
    u32 blkOpenFlg22[32];
    u32 blkOpenFlg23[32];
    u32 blkOpenFlg24[32];
    u32 blkOpenFlg25[32];
    u32 blkOpenFlg26[32];
    u32 blkOpenFlg27[32];
    u32 blkOpenFlg28[32];
    u32 blkOpenFlg29[32];
};

struct SAVEDATA_fldAutoMapBuff31_tag {
    u32 *blkOpenFlg00;
    u32 blkOpenFlg01[32];
    u32 blkOpenFlg02[32];
    u32 blkOpenFlg03[32];
    u32 blkOpenFlg04[32];
    u32 blkOpenFlg05[32];
    u32 blkOpenFlg06[32];
    u32 blkOpenFlg07[32];
};

struct SAVEDATA_fldAutoMapBuffEX_tag {
    u32 *blkOpenFlg00;
    u32 blkOpenFlg01[32];
};

struct SAVEDATA_fclencyceelem_tag {
    u16 id;
    u16 reserved0;
    u16 maxhp;
    u16 maxmp;
    u32 exp;
    u16 level;
    s8 param[6];
    s8 skillparam[6];
    u16 skillcnt;
    u16 skill[24];
    s8 mitamaparam[6];
    s8 levelupparam[6];
    u16 keisyoskill[24];
    u8 keiattr[24];
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
    s8 autoMapOpen[36];
    u8 fldRunWork[107];
    s8 autoMapOpenEX[2];
    s8 reserved[147];
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
    s8 reserved[276];
};

struct SAVEDATA_GameFileInfo_tag {
    u16 *verstr;
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
    u16 end_list[7];
};

struct SAVEDATA_evtMoon_tag {
    s32 Stat;
    s32 Age;
    s32 TakaraCnt;
    s32 pub;
    f32 MoveCnt;
};

struct SAVEDATA_fldSave_tag {
    SAVEDATA_fldBlockBuff_tag *PushBlock00;
    SAVEDATA_fldBlockBuff_tag *PushBlock01[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock02[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock03[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock04[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock05[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock06[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock07[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock08[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock09[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock10[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock11[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock12[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock13[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock14[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock15[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock16[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock17[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock18[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock19[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock20[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock21[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock22[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock23[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock24[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock25[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock26[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock27[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock28[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock29[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock30[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock31[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock32[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock33[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock34[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock35[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock36[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock37[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock38[32];
    SAVEDATA_fldBlockBuff_tag *PushBlock39[32];
    SAVEDATA_fldAutoMapBuff_tag amap;
    u8 takara[32];
    s16 tmnltype;
    s16 tmnlid;
    s32 AnahoriCnt;
    u8 takara2[12];
    s32 pub[11];
};

struct SAVEDATA_fclEncycRecord_tag {
    s32 num;
    u32 reserved0;
    u32 reserved1;
    u32 reserved2;
    SAVEDATA_fclencyceelem_tag *pelem[184];
};

struct SAVEDATA_dds3GlobalWork_tag {
    SAVEDATA_GameFileInfo_tag GameFileInfo;
    s32 runtime;
    s32 playtime;
    s32 IntVariable[256];
    f32 FloatVariable[256];
    s32 EventBit[128];
    SAVEDATA_evtMoon_tag Moon;
    s32 maka;
    u32 stat;
    s32 maxstock;
    SAVEDATA_datUnitWork_tag *unitwork[16];
    s32 stocklist[16];
    s32 stockcnt;
    u8 item[160];
    s32 boss_press00[2];
    s32 boss_press01[2];
    s32 boss_press02[2];
    s32 boss_press03[2];
    s32 boss_press04[2];
    s32 boss_press05[2];
    s32 boss_press06[2];
    s32 boss_press07[2];
    s32 boss_press08[2];
    s32 boss_press09[2];
    s32 boss_press10[2];
    s32 boss_press11[2];
    s32 boss_press12[2];
    s32 boss_press13[2];
    s32 boss_press14[2];
    s32 boss_press15[2];
    s32 boss_press16[2];
    s32 boss_press17[2];
    s32 boss_press18[2];
    s32 boss_press19[2];
    s32 boss_press20[2];
    s32 boss_press21[2];
    s32 boss_press22[2];
    s32 boss_press23[2];
    s32 boss_press24[2];
    s32 boss_press25[2];
    s32 boss_press26[2];
    s32 boss_press27[2];
    s32 boss_press28[2];
    s32 boss_press29[2];
    s32 boss_press30[2];
    s32 boss_press31[2];
    s32 boss_press32[2];
    s32 boss_press33[2];
    s32 boss_press34[2];
    s32 boss_press35[2];
    s32 boss_press36[2];
    s32 boss_press37[2];
    s32 boss_press38[2];
    s32 boss_press39[2];
    u8 syakkincnt[64];
    u8 negoques[4];
    u8 kotowari[4];
    u16 wakimi_id;
    u16 bouga_cnt;
    f32 encountkyori;
    u16 encountcnt;
    u8 heartsequip;
    u8 hearts[64];
    u8 heartsskcnt[64];
    u8 heartscnt;
    u8 name_nums00[2];
    u8 name_nums01[2];
    u8 name_nums02[2];
    u8 name_nums03[2];
    u8 name_code00[16];
    u8 name_code01[16];
    u8 name_code02[16];
    u8 name_code03[16];
    u8 cname_code00[16];
    u8 cname_code01[16];
    u8 cname_code02[16];
    u8 cname_code03[16];
    u8 cname_nums[4];
    SAVEDATA_fldSave_tag fldSave;
    s32 config_data[14];
    s32 dmy;
    u16 hearts_sk00[12];
    u16 hearts_sk01[12];
    u16 hearts_sk02[12];
    u16 hearts_sk03[12];
    u16 hearts_sk04[12];
    u16 hearts_sk05[12];
    u16 hearts_sk06[12];
    u16 hearts_sk07[12];
    u16 hearts_sk08[12];
    u16 hearts_sk09[12];
    u16 hearts_sk10[12];
    u16 hearts_sk11[12];
    u16 hearts_sk12[12];
    u16 hearts_sk13[12];
    u16 hearts_sk14[12];
    u16 hearts_sk15[12];
    u16 hearts_sk16[12];
    u16 hearts_sk17[12];
    u16 hearts_sk18[12];
    u16 hearts_sk19[12];
    u16 hearts_sk20[12];
    u16 hearts_sk21[12];
    u16 hearts_sk22[12];
    u16 hearts_sk23[12];
    u16 hearts_sk24[12];
    u16 hearts_sk25[12];
    u16 hearts_sk26[12];
    u16 hearts_sk27[12];
    u16 hearts_sk28[12];
    u16 hearts_sk29[12];
    u16 hearts_sk30[12];
    u16 hearts_sk31[12];
    s8 hearts_up_param00[6];
    s8 hearts_up_param01[6];
    s8 hearts_up_param02[6];
    s8 hearts_up_param03[6];
    s8 hearts_up_param04[6];
    s8 hearts_up_param05[6];
    s8 hearts_up_param06[6];
    s8 hearts_up_param07[6];
    s8 hearts_up_param08[6];
    s8 hearts_up_param09[6];
    s8 hearts_up_param10[6];
    s8 hearts_up_param11[6];
    s8 hearts_up_param12[6];
    s8 hearts_up_param13[6];
    s8 hearts_up_param14[6];
    s8 hearts_up_param15[6];
    s8 hearts_up_param16[6];
    s8 hearts_up_param17[6];
    s8 hearts_up_param18[6];
    s8 hearts_up_param19[6];
    s8 hearts_up_param20[6];
    s8 hearts_up_param21[6];
    s8 hearts_up_param22[6];
    s8 hearts_up_param23[6];
    s8 hearts_up_param24[6];
    s8 hearts_up_param25[6];
    s8 hearts_up_param26[6];
    s8 hearts_up_param27[6];
    s8 hearts_up_param28[6];
    s8 hearts_up_param29[6];
    s8 hearts_up_param30[6];
    s8 hearts_up_param31[6];
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
    s8 dummy[5];
};

struct SAVEDATA_dds3SystemWork_tag {
    s8 *dlcflg;
    s8 dummy[20];
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
    s8 *param;
    s8 *skillparam;
    u16 uniqueid;
    u16 reserve1;
    u16 reserve2;
    u16 *namecode;
    s32 skillcnt;
    s32 *skill;
    s16 nowcommand;
    u16 nowindex;
    s16 nowtarea;
    s16 nowtform;
    s16 prevcommand;
    u16 previndex;
    s16 prevtarea;
    s16 prevtform;
    s8 *mitamaparam;
    s8 *levelupparam;
    u16 *keisyoskill;
    u8 *keiattr;
    u16 hensinmae;
    u16 *getdevilhearts;
    u32 hensinmaeexp;
    u16 *fullnamecode;
};

struct SAVEDATA_fldBlockBuff_tag {
    u16 MviewOffFlg;
    u16 ManimeOffFlg;
    u16 hitOffFlg;
    u16 EviewOffFlg;
    u16 EanimeOffFlg;
    u8 *EanimeCngID;
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
  struct System_Int32_array *IntVariable;
  u64 v9;
  struct SAVEDATA_datUnitWork_tag_array **p_unitwork;
  struct datUnitWork_t_array **v11;
  s64 v12;
  struct SAVEDATA_datUnitWork_tag_array *v13;
  struct SAVEDATA_datUnitWork_tag_array *v16;
  struct SAVEDATA_datUnitWork_tag_array *v19;
  struct SAVEDATA_datUnitWork_tag_array *v22;
  struct SAVEDATA_datUnitWork_tag_array *v25;
  struct SAVEDATA_datUnitWork_tag_array *v28;
  struct SAVEDATA_datUnitWork_tag_array *v31;
  struct SAVEDATA_datUnitWork_tag_array *v34;
  struct SAVEDATA_datUnitWork_tag_array *v37;
  struct SAVEDATA_datUnitWork_tag_array *v44;
  struct SAVEDATA_datUnitWork_tag_array *v47;
  struct SAVEDATA_datUnitWork_tag_array *v50;
  struct SAVEDATA_datUnitWork_tag_array *v55;
  struct SAVEDATA_datUnitWork_tag_array *v60;
  struct SAVEDATA_datUnitWork_tag_array *v63;
  struct SAVEDATA_datUnitWork_tag_array *v66;
  struct SAVEDATA_datUnitWork_tag_array *v69;
  struct SAVEDATA_datUnitWork_tag_array *v72;
  struct SAVEDATA_datUnitWork_tag_array *v75;
  struct SAVEDATA_datUnitWork_tag_array *v78;
  struct SAVEDATA_datUnitWork_tag_array *v81;
  struct SAVEDATA_datUnitWork_tag_array *v92;
  struct SAVEDATA_datUnitWork_tag_array *v97;
  struct System_Byte_array *item;
  struct System_Int32_array_array **p_boss_press;
  struct System_Int32_array_array *boss_press;
  struct System_Int32_array_array *v144;
  struct System_Byte_array *hearts;
  struct System_Byte_array_array *name_nums;
  struct System_Byte_array_array *v149;
  struct System_Byte_array_array *v151;
  struct System_Byte_array_array *v153;
  struct System_Byte_array_array *name_code;
  struct System_Byte_array_array *v157;
  struct System_Byte_array_array *v159;
  struct System_Byte_array_array *v161;
  struct System_Byte_array_array *cname_code;
  struct System_Byte_array_array *v165;
  struct System_Byte_array_array *v167;
  struct System_Byte_array_array *v169;
  SAVEDATA_o *v171;
  struct fldSave_t_o **p_fldSave;
  struct fldBlockBuff_t_array_array *PushBlock;
  SAVEDATA_o *v176;
  struct fldBlockBuff_t_array_array *v178;
  SAVEDATA_o *v180;
  struct fldBlockBuff_t_array_array *v182;
  SAVEDATA_o *v184;
  struct fldBlockBuff_t_array_array *v186;
  SAVEDATA_o *v188;
  struct fldBlockBuff_t_array_array *v190;
  SAVEDATA_o *v192;
  struct fldBlockBuff_t_array_array *v194;
  SAVEDATA_o *v196;
  struct fldBlockBuff_t_array_array *v198;
  SAVEDATA_o *v200;
  struct fldBlockBuff_t_array_array *v202;
  SAVEDATA_o *v204;
  struct fldBlockBuff_t_array_array *v206;
  SAVEDATA_o *v208;
  struct fldBlockBuff_t_array_array *v210;
  SAVEDATA_o *v212;
  struct fldBlockBuff_t_array_array *v214;
  SAVEDATA_o *v216;
  struct fldBlockBuff_t_array_array *v218;
  SAVEDATA_o *v220;
  struct fldBlockBuff_t_array_array *v222;
  SAVEDATA_o *v224;
  struct fldBlockBuff_t_array_array *v226;
  SAVEDATA_o *v228;
  struct fldBlockBuff_t_array_array *v230;
  SAVEDATA_o *v232;
  struct fldBlockBuff_t_array_array *v234;
  SAVEDATA_o *v236;
  struct fldBlockBuff_t_array_array *v238;
  SAVEDATA_o *v240;
  struct fldBlockBuff_t_array_array *v242;
  SAVEDATA_o *v244;
  struct fldBlockBuff_t_array_array *v246;
  SAVEDATA_o *v248;
  struct fldBlockBuff_t_array_array *v250;
  SAVEDATA_o *v252;
  struct fldBlockBuff_t_array_array *v254;
  SAVEDATA_o *v256;
  struct fldBlockBuff_t_array_array *v258;
  SAVEDATA_o *v260;
  struct fldBlockBuff_t_array_array *v262;
  SAVEDATA_o *v264;
  struct fldBlockBuff_t_array_array *v266;
  SAVEDATA_o *v268;
  struct fldBlockBuff_t_array_array *v270;
  SAVEDATA_o *v272;
  struct fldBlockBuff_t_array_array *v274;
  SAVEDATA_o *v276;
  struct fldBlockBuff_t_array_array *v278;
  SAVEDATA_o *v280;
  struct fldBlockBuff_t_array_array *v282;
  SAVEDATA_o *v284;
  struct fldBlockBuff_t_array_array *v286;
  SAVEDATA_o *v288;
  struct fldBlockBuff_t_array_array *v290;
  SAVEDATA_o *v292;
  struct fldBlockBuff_t_array_array *v294;
  SAVEDATA_o *v296;
  struct fldBlockBuff_t_array_array *v298;
  SAVEDATA_o *v300;
  struct fldBlockBuff_t_array_array *v302;
  SAVEDATA_o *v304;
  struct fldBlockBuff_t_array_array *v306;
  SAVEDATA_o *v308;
  struct fldBlockBuff_t_array_array *v310;
  SAVEDATA_o *v312;
  struct fldBlockBuff_t_array_array *v314;
  SAVEDATA_o *v316;
  struct fldBlockBuff_t_array_array *v318;
  SAVEDATA_o *v320;
  struct fldBlockBuff_t_array_array *v322;
  SAVEDATA_o *v324;
  struct fldBlockBuff_t_array_array *v326;
  SAVEDATA_o *v328;
  struct fldBlockBuff_t_array_array *v330;
  struct System_UInt32_array_array *blkOpenFlg;
  struct System_UInt32_array_array *v334;
  struct System_UInt32_array_array *v336;
  struct System_UInt32_array_array *v338;
  struct System_UInt32_array_array *v340;
  struct System_UInt32_array_array *v342;
  struct System_UInt32_array_array *v344;
  struct System_UInt32_array_array *v346;
  struct System_UInt32_array_array *v348;
  struct System_UInt32_array_array *v350;
  struct System_UInt32_array_array *v352;
  struct System_UInt32_array_array *v354;
  struct System_UInt32_array_array *v356;
  struct System_UInt32_array_array *v358;
  struct System_UInt32_array_array *v360;
  struct System_UInt32_array_array *v362;
  struct System_UInt32_array_array *v364;
  struct System_UInt32_array_array *v366;
  struct System_UInt32_array_array *v368;
  struct System_UInt32_array_array *v370;
  struct System_UInt32_array_array *v372;
  struct System_UInt32_array_array *v374;
  struct System_UInt32_array_array *v376;
  struct System_UInt32_array_array *v378;
  struct System_UInt32_array_array *v380;
  struct System_UInt32_array_array *v382;
  struct System_UInt32_array_array *v384;
  struct System_UInt32_array_array *v386;
  struct System_UInt32_array_array *v388;
  struct System_UInt32_array_array *v390;
  struct System_UInt16_array_array *hearts_sk;
  struct System_UInt16_array_array **p_hearts_sk;
  struct System_UInt16_array_array *v425;
  struct System_SByte_array_array *hearts_up_param;
  struct System_SByte_array_array **p_hearts_up_param;
  struct System_SByte_array_array *v460;
  u64 v462;
  struct fclEncycRecord_t_o **p_encyc_record;
  struct SAVEDATA_fclencyceelem_tag_array **p_pelem;
  s64 v465;
  struct fclencyceelem_t_array *pelem;
  struct SAVEDATA_fclencyceelem_tag_array *v467;
  u16 id;
  struct fclencyceelem_t_array *v471;
  struct SAVEDATA_fclencyceelem_tag_array *v472;
  u16 reserved0;
  struct fclencyceelem_t_array *v476;
  struct SAVEDATA_fclencyceelem_tag_array *v477;
  u16 maxhp;
  struct fclencyceelem_t_array *v481;
  struct SAVEDATA_fclencyceelem_tag_array *v482;
  u16 maxmp;
  struct fclencyceelem_t_array *v486;
  struct SAVEDATA_fclencyceelem_tag_array *v487;
  u32 exp;
  struct fclencyceelem_t_array *v491;
  struct SAVEDATA_fclencyceelem_tag_array *v492;
  u16 level;
  struct fclencyceelem_t_array *v496;
  System_Array_o *param;
  struct fclencyceelem_t_array *v500;
  System_Array_o *skillparam;
  struct fclencyceelem_t_array *v504;
  struct SAVEDATA_fclencyceelem_tag_array *v505;
  u16 skillcnt;
  struct fclencyceelem_t_array *v509;
  System_Array_o *skill;
  struct fclencyceelem_t_array *v513;
  System_Array_o *mitamaparam;
  struct fclencyceelem_t_array *v517;
  System_Array_o *levelupparam;
  struct fclencyceelem_t_array *v521;
  System_Array_o *keisyoskill;
  struct fclencyceelem_t_array *v525;
  System_Array_o *keiattr;
  struct fclencyceelem_t_array *v529;
  struct SAVEDATA_fclencyceelem_tag_array *v530;
  u16 hensinmae;
  struct fclencyceelem_t_array *v534;
  struct SAVEDATA_fclencyceelem_tag_array *v535;
  u16 reserved1;
  struct fclencyceelem_t_array *v539;
  struct SAVEDATA_fclencyceelem_tag_array *v540;
  u32 flag;
  struct fclencyceelem_t_array *v544;
  struct SAVEDATA_fclencyceelem_tag_array *v545;
  u32 reserved2;
  struct fclencyceelem_t_array *v549;
  struct SAVEDATA_fclencyceelem_tag_array *v550;
  u32 hensinmaeexp;
  struct System_UInt32_array_array *v554;
  struct System_UInt32_array_array *v556;
  struct System_UInt32_array_array *v558;
  struct System_UInt32_array_array *v560;
  struct System_UInt32_array_array *v562;
  struct System_UInt32_array_array *v564;
  struct System_UInt32_array_array *v566;
  struct System_UInt32_array_array *v568;
  struct System_UInt32_array_array *v570;
  struct System_UInt32_array_array *v572;
  struct System_UInt32_array_array *v574;
  struct fldAutoMapBuff_t_o **p_amap_Ver7;
  struct System_UInt32_array_array *v577;
  struct System_UInt32_array_array *v579;
  struct System_UInt32_array_array *v581;
  struct System_UInt32_array_array *v583;
  struct System_UInt32_array_array *v585;
  struct System_UInt32_array_array *v587;
  struct System_UInt32_array_array *v589;
  struct System_UInt32_array_array *v591;
  struct System_UInt32_array_array *v593;
  struct System_UInt32_array_array *v595;
  struct System_UInt32_array_array *v597;
  struct System_UInt32_array_array *v599;
  struct System_UInt32_array_array *v601;
  struct System_UInt32_array_array *v603;
  struct System_UInt32_array_array *v605;
  struct System_UInt32_array_array *v607;
  struct System_UInt32_array_array *v609;
  struct System_UInt32_array_array *v611;
  struct System_UInt32_array_array *v613;
  struct System_UInt32_array_array *v615;
  struct System_UInt32_array_array *v617;
  struct System_UInt32_array_array *v619;
  struct System_UInt32_array_array *v621;
  struct System_UInt32_array_array *v623;
  struct System_UInt32_array_array *v625;
  struct System_UInt32_array_array *v627;
  struct System_UInt32_array_array *v629;
  struct System_UInt32_array_array *v631;
  struct System_UInt32_array_array *v633;
  struct System_UInt32_array_array *v635;
  struct System_UInt32_array_array *v637;
  struct System_UInt32_array_array *v639;
  struct System_UInt32_array_array *v641;
  struct System_UInt32_array_array *v643;
  struct System_UInt32_array_array *v645;
  struct System_UInt32_array_array *v647;
  struct System_UInt32_array_array *v649;
  struct System_UInt32_array_array *v651;
  struct System_UInt32_array_array *v653;
  struct fclencyceelem_t_array *v655;
  struct fclencyceelem_t_array *v657;
  struct fclencyceelem_t_array *v659;
  struct fclencyceelem_t_array *v661;
  struct fclencyceelem_t_array *v663;
  struct fclencyceelem_t_array *v665;
  struct fclencyceelem_t_array *v667;
  struct fclencyceelem_t_array *v669;
  struct fclencyceelem_t_array *v671;
  struct fclencyceelem_t_array *v673;
  struct fclencyceelem_t_array *v675;
  struct fclencyceelem_t_array *v677;
  struct fclencyceelem_t_array *v679;
  struct fclencyceelem_t_array *v681;
  struct fclencyceelem_t_array *v683;
  struct fclencyceelem_t_array *v685;
  struct fclencyceelem_t_array *v687;
  struct fclencyceelem_t_array *v689;
  struct fclencyceelem_t_array *v691;
  System_Array_o *v695;

  Copy_3886320(data->GameFileInfo->verstr, saveData->GameFileInfo.verstr, saveData->GameFileInfo.verstr->max_length);
  saveData->GameFileInfo.ver = data->GameFileInfo->ver;
  saveData->GameFileInfo.TmnlMode = data->GameFileInfo->TmnlMode;
  saveData->GameFileInfo.TmnlId = data->GameFileInfo->TmnlId;
  saveData->GameFileInfo.Lv = data->GameFileInfo->Lv;
  saveData->GameFileInfo.mode = data->GameFileInfo->mode;
  saveData->GameFileInfo.PlayTime = data->GameFileInfo->PlayTime;
  saveData->GameFileInfo.endcnt = data->GameFileInfo->endcnt;
  saveData->GameFileInfo.newfile = data->GameFileInfo->newfile;
  saveData->GameFileInfo.cname_code = data->GameFileInfo->cname_code;
  saveData->GameFileInfo.cname_nums = data->GameFileInfo->cname_nums;
  saveData->GameFileInfo.pad3 = data->GameFileInfo->pad3;
  saveData->GameFileInfo.dante_mode = data->GameFileInfo->dante_mode;
  Copy_3886320(data->GameFileInfo->end_list, saveData->GameFileInfo.end_list, saveData->GameFileInfo.end_list->max_length);
  saveData->runtime = data->runtime;
  IntVariable = saveData->IntVariable;
  saveData->playtime = data->playtime;
  Copy_3886320(data->IntVariable, IntVariable, IntVariable->max_length);
  Copy_3886320(data->FloatVariable, saveData->FloatVariable, saveData->FloatVariable->max_length);
  Copy_3886320(data->EventBit, saveData->EventBit, saveData->EventBit->max_length);
  saveData->Moon.Stat = data->Moon->Stat;
  saveData->Moon.Age = data->Moon->Age;
  saveData->Moon.TakaraCnt = data->Moon->TakaraCnt;
  saveData->Moon.pub = data->Moon->pub;
  saveData->Moon.MoveCnt = data->Moon->MoveCnt;
  saveData->maka = data->maka;
  saveData->stat = data->stat;
  v9 = 0;
  p_unitwork = &saveData->unitwork;
  v11 = &data->unitwork;
  v12 = 176;
  saveData->maxstock = data->maxstock;
  do
  {
    v13 = *p_unitwork;
    *(v13 + v12 - 144) = (*v11)->m_Items[v9]->flag;
    v16 = *p_unitwork;
    *(v16 + v12 - 140) = (*v11)->m_Items[v9]->id;
    v19 = *p_unitwork;
    *(v19 + v12 - 138) = (*v11)->m_Items[v9]->hp;
    v22 = *p_unitwork;
    *(v22 + v12 - 136) = (*v11)->m_Items[v9]->maxhp;
    v25 = *p_unitwork;
    *(v25 + v12 - 134) = (*v11)->m_Items[v9]->mp;
    v28 = *p_unitwork;
    *(v28 + v12 - 132) = (*v11)->m_Items[v9]->maxmp;
    v31 = *p_unitwork;
    *(v31 + v12 - 130) = (*v11)->m_Items[v9]->badstatus;
    v34 = *p_unitwork;
    *(v34 + v12 - 128) = (*v11)->m_Items[v9]->exp;
    v37 = *p_unitwork;
    *(v37 + v12 - 124) = (*v11)->m_Items[v9]->level;
    Copy_3886320(
      (*v11)->m_Items[v9]->param,
      *(*p_unitwork + v12 - 120),
      *(*(*p_unitwork + v12 - 120) + 24LL),
      0);
    Copy_3886320(
      (*v11)->m_Items[v9]->skillparam,
      *(*p_unitwork + v12 - 112),
      *(*(*p_unitwork + v12 - 112) + 24LL),
      0);
    v44 = *p_unitwork;
    *(v44 + v12 - 104) = (*v11)->m_Items[v9]->uniqueid;
    v47 = *p_unitwork;
    *(v47 + v12 - 102) = (*v11)->m_Items[v9]->reserve1;
    v50 = *p_unitwork;
    *(v50 + v12 - 100) = (*v11)->m_Items[v9]->reserve2;
    Copy_3886320(
      (*v11)->m_Items[v9]->namecode,
      *(*p_unitwork + v12 - 96),
      *(*(*p_unitwork + v12 - 96) + 24LL),
      0);
    v55 = *p_unitwork;
    *(v55 + v12 - 88) = (*v11)->m_Items[v9]->skillcnt;
    Copy_3886320(
      (*v11)->m_Items[v9]->skill,
      *(*p_unitwork + v12 - 80),
      *(*(*p_unitwork + v12 - 80) + 24LL),
      0);
    v60 = *p_unitwork;
    *(v60 + v12 - 72) = (*v11)->m_Items[v9]->nowcommand;
    v63 = *p_unitwork;
    *(v63 + v12 - 70) = (*v11)->m_Items[v9]->nowindex;
    v66 = *p_unitwork;
    *(v66 + v12 - 68) = (*v11)->m_Items[v9]->nowtarea;
    v69 = *p_unitwork;
    *(v69 + v12 - 66) = (*v11)->m_Items[v9]->nowtform;
    v72 = *p_unitwork;
    *(v72 + v12 - 64) = (*v11)->m_Items[v9]->prevcommand;
    v75 = *p_unitwork;
    *(v75 + v12 - 62) = (*v11)->m_Items[v9]->previndex;
    v78 = *p_unitwork;
    *(v78 + v12 - 60) = (*v11)->m_Items[v9]->prevtarea;
    v81 = *p_unitwork;
    *(v81 + v12 - 58) = (*v11)->m_Items[v9]->prevtform;
    Copy_3886320(
      (*v11)->m_Items[v9]->mitamaparam,
      *(*p_unitwork + v12 - 56),
      *(*(*p_unitwork + v12 - 56) + 24LL),
      0);
    Copy_3886320(
      (*v11)->m_Items[v9]->levelupparam,
      *(*p_unitwork + v12 - 48),
      *(*(*p_unitwork + v12 - 48) + 24LL),
      0);
    Copy_3886320(
      (*v11)->m_Items[v9]->keisyoskill,
      *(*p_unitwork + v12 - 40),
      *(*(*p_unitwork + v12 - 40) + 24LL),
      0);
    Copy_3886320(
      (*v11)->m_Items[v9]->keiattr,
      *(*p_unitwork + v12 - 32),
      *(*(*p_unitwork + v12 - 32) + 24LL),
      0);
    v92 = *p_unitwork;
    *(v92 + v12 - 24) = (*v11)->m_Items[v9]->hensinmae;
    Copy_3886320(
      (*v11)->m_Items[v9]->getdevilhearts,
      *(*p_unitwork + v12 - 16),
      *(*(*p_unitwork + v12 - 16) + 24LL),
      0);
    v97 = *p_unitwork;
    *(v97 + v12 - 8) = (*v11)->m_Items[v9]->hensinmaeexp;
    Copy_3886320(
      (*v11)->m_Items[v9]->fullnamecode,
      *(&(*p_unitwork)->obj.klass + v12),
      (*(&(*p_unitwork)->obj.klass + v12))->_1.namespaze,
      0);
    v12 += 152;
    ++v9;
  }
  while (v12 != 2608);
  Copy_3886320(data->stocklist, saveData->stocklist, saveData->stocklist->max_length);
  item = saveData->item;
  saveData->stockcnt = data->stockcnt;
  Copy_3886320(data->item, item, item->max_length);
  p_boss_press = &data->boss_press;
  boss_press = data->boss_press;
  Copy_3886320(boss_press->m_Items[0], saveData->boss_press00, saveData->boss_press00->max_length);
  Copy_3886320(
    (*p_boss_press)->m_Items[1],
    saveData->boss_press01,
    saveData->boss_press01->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[2],
    saveData->boss_press02,
    saveData->boss_press02->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[3],
    saveData->boss_press03,
    saveData->boss_press03->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[4],
    saveData->boss_press04,
    saveData->boss_press04->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[5],
    saveData->boss_press05,
    saveData->boss_press05->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[6],
    saveData->boss_press06,
    saveData->boss_press06->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[7],
    saveData->boss_press07,
    saveData->boss_press07->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[8],
    saveData->boss_press08,
    saveData->boss_press08->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[9],
    saveData->boss_press09,
    saveData->boss_press09->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[10],
    saveData->boss_press10,
    saveData->boss_press10->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[11],
    saveData->boss_press11,
    saveData->boss_press11->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[12],
    saveData->boss_press12,
    saveData->boss_press12->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[13],
    saveData->boss_press13,
    saveData->boss_press13->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[14],
    saveData->boss_press14,
    saveData->boss_press14->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[15],
    saveData->boss_press15,
    saveData->boss_press15->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[16],
    saveData->boss_press16,
    saveData->boss_press16->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[17],
    saveData->boss_press17,
    saveData->boss_press17->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[18],
    saveData->boss_press18,
    saveData->boss_press18->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[19],
    saveData->boss_press19,
    saveData->boss_press19->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[20],
    saveData->boss_press20,
    saveData->boss_press20->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[21],
    saveData->boss_press21,
    saveData->boss_press21->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[22],
    saveData->boss_press22,
    saveData->boss_press22->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[23],
    saveData->boss_press23,
    saveData->boss_press23->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[24],
    saveData->boss_press24,
    saveData->boss_press24->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[25],
    saveData->boss_press25,
    saveData->boss_press25->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[26],
    saveData->boss_press26,
    saveData->boss_press26->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[27],
    saveData->boss_press27,
    saveData->boss_press27->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[28],
    saveData->boss_press28,
    saveData->boss_press28->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[29],
    saveData->boss_press29,
    saveData->boss_press29->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[30],
    saveData->boss_press30,
    saveData->boss_press30->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[31],
    saveData->boss_press31,
    saveData->boss_press31->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[32],
    saveData->boss_press32,
    saveData->boss_press32->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[33],
    saveData->boss_press33,
    saveData->boss_press33->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[34],
    saveData->boss_press34,
    saveData->boss_press34->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[35],
    saveData->boss_press35,
    saveData->boss_press35->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[36],
    saveData->boss_press36,
    saveData->boss_press36->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[37],
    saveData->boss_press37,
    saveData->boss_press37->max_length,
    0);
  Copy_3886320(
    (*p_boss_press)->m_Items[38],
    saveData->boss_press38,
    saveData->boss_press38->max_length,
    0);
  v144 = *p_boss_press;
  Copy_3886320(v144->m_Items[39], saveData->boss_press39, saveData->boss_press39->max_length);
  Copy_3886320(data->syakkincnt, saveData->syakkincnt, saveData->syakkincnt->max_length);
  Copy_3886320(data->negoques, saveData->negoques, saveData->negoques->max_length);
  Copy_3886320(data->kotowari, saveData->kotowari, saveData->kotowari->max_length);
  saveData->wakimi_id = data->wakimi_id;
  saveData->bouga_cnt = data->bouga_cnt;
  saveData->encountkyori = data->encountkyori;
  saveData->encountcnt = data->encountcnt;
  hearts = saveData->hearts;
  saveData->heartsequip = data->heartsequip;
  Copy_3886320(data->hearts, hearts, hearts->max_length);
  Copy_3886320(data->heartsskcnt, saveData->heartsskcnt, saveData->heartsskcnt->max_length);
  saveData->heartscnt = data->heartscnt;
  name_nums = data->name_nums;
  Copy_3886320(name_nums->m_Items[0], saveData->name_nums00, saveData->name_nums00->max_length);
  v149 = data->name_nums;
  Copy_3886320(v149->m_Items[1], saveData->name_nums01, saveData->name_nums01->max_length);
  v151 = data->name_nums;
  Copy_3886320(v151->m_Items[2], saveData->name_nums02, saveData->name_nums02->max_length);
  v153 = data->name_nums;
  Copy_3886320(v153->m_Items[3], saveData->name_nums03, saveData->name_nums03->max_length);
  name_code = data->name_code;
  Copy_3886320(name_code->m_Items[0], saveData->name_code00, saveData->name_code00->max_length);
  v157 = data->name_code;
  Copy_3886320(v157->m_Items[1], saveData->name_code01, saveData->name_code01->max_length);
  v159 = data->name_code;
  Copy_3886320(v159->m_Items[2], saveData->name_code02, saveData->name_code02->max_length);
  v161 = data->name_code;
  Copy_3886320(v161->m_Items[3], saveData->name_code03, saveData->name_code03->max_length);
  cname_code = data->cname_code;
  Copy_3886320(cname_code->m_Items[0], saveData->cname_code00, saveData->cname_code00->max_length);
  v165 = data->cname_code;
  Copy_3886320(v165->m_Items[1], saveData->cname_code01, saveData->cname_code01->max_length);
  v167 = data->cname_code;
  Copy_3886320(v167->m_Items[2], saveData->cname_code02, saveData->cname_code02->max_length);
  v169 = data->cname_code;
  Copy_3886320(v169->m_Items[3], saveData->cname_code03, saveData->cname_code03->max_length);
  Copy_3886320(data->cname_nums, saveData->cname_nums, saveData->cname_nums->max_length);
  p_fldSave = &data->fldSave;
  PushBlock = data->fldSave->PushBlock;
  backupPushBlock(v171, &saveData->fldSave.PushBlock00, PushBlock->m_Items);
  v178 = (*p_fldSave)->PushBlock;
  backupPushBlock(v176, &saveData->fldSave.PushBlock01, &v178->m_Items[1]);
  v182 = (*p_fldSave)->PushBlock;
  backupPushBlock(v180, &saveData->fldSave.PushBlock02, &v182->m_Items[2]);
  v186 = (*p_fldSave)->PushBlock;
  backupPushBlock(v184, &saveData->fldSave.PushBlock03, &v186->m_Items[3]);
  v190 = (*p_fldSave)->PushBlock;
  backupPushBlock(v188, &saveData->fldSave.PushBlock04, &v190->m_Items[4]);
  v194 = (*p_fldSave)->PushBlock;
  backupPushBlock(v192, &saveData->fldSave.PushBlock05, &v194->m_Items[5]);
  v198 = (*p_fldSave)->PushBlock;
  backupPushBlock(v196, &saveData->fldSave.PushBlock06, &v198->m_Items[6]);
  v202 = (*p_fldSave)->PushBlock;
  backupPushBlock(v200, &saveData->fldSave.PushBlock07, &v202->m_Items[7]);
  v206 = (*p_fldSave)->PushBlock;
  backupPushBlock(v204, &saveData->fldSave.PushBlock08, &v206->m_Items[8]);
  v210 = (*p_fldSave)->PushBlock;
  backupPushBlock(v208, &saveData->fldSave.PushBlock09, &v210->m_Items[9]);
  v214 = (*p_fldSave)->PushBlock;
  backupPushBlock(v212, &saveData->fldSave.PushBlock10, &v214->m_Items[10]);
  v218 = (*p_fldSave)->PushBlock;
  backupPushBlock(v216, &saveData->fldSave.PushBlock11, &v218->m_Items[11]);
  v222 = (*p_fldSave)->PushBlock;
  backupPushBlock(v220, &saveData->fldSave.PushBlock12, &v222->m_Items[12]);
  v226 = (*p_fldSave)->PushBlock;
  backupPushBlock(v224, &saveData->fldSave.PushBlock13, &v226->m_Items[13]);
  v230 = (*p_fldSave)->PushBlock;
  backupPushBlock(v228, &saveData->fldSave.PushBlock14, &v230->m_Items[14]);
  v234 = (*p_fldSave)->PushBlock;
  backupPushBlock(v232, &saveData->fldSave.PushBlock15, &v234->m_Items[15]);
  v238 = (*p_fldSave)->PushBlock;
  backupPushBlock(v236, &saveData->fldSave.PushBlock16, &v238->m_Items[16]);
  v242 = (*p_fldSave)->PushBlock;
  backupPushBlock(v240, &saveData->fldSave.PushBlock17, &v242->m_Items[17]);
  v246 = (*p_fldSave)->PushBlock;
  backupPushBlock(v244, &saveData->fldSave.PushBlock18, &v246->m_Items[18]);
  v250 = (*p_fldSave)->PushBlock;
  backupPushBlock(v248, &saveData->fldSave.PushBlock19, &v250->m_Items[19]);
  v254 = (*p_fldSave)->PushBlock;
  backupPushBlock(v252, &saveData->fldSave.PushBlock20, &v254->m_Items[20]);
  v258 = (*p_fldSave)->PushBlock;
  backupPushBlock(v256, &saveData->fldSave.PushBlock21, &v258->m_Items[21]);
  v262 = (*p_fldSave)->PushBlock;
  backupPushBlock(v260, &saveData->fldSave.PushBlock22, &v262->m_Items[22]);
  v266 = (*p_fldSave)->PushBlock;
  backupPushBlock(v264, &saveData->fldSave.PushBlock23, &v266->m_Items[23]);
  v270 = (*p_fldSave)->PushBlock;
  backupPushBlock(v268, &saveData->fldSave.PushBlock24, &v270->m_Items[24]);
  v274 = (*p_fldSave)->PushBlock;
  backupPushBlock(v272, &saveData->fldSave.PushBlock25, &v274->m_Items[25]);
  v278 = (*p_fldSave)->PushBlock;
  backupPushBlock(v276, &saveData->fldSave.PushBlock26, &v278->m_Items[26]);
  v282 = (*p_fldSave)->PushBlock;
  backupPushBlock(v280, &saveData->fldSave.PushBlock27, &v282->m_Items[27]);
  v286 = (*p_fldSave)->PushBlock;
  backupPushBlock(v284, &saveData->fldSave.PushBlock28, &v286->m_Items[28]);
  v290 = (*p_fldSave)->PushBlock;
  backupPushBlock(v288, &saveData->fldSave.PushBlock29, &v290->m_Items[29]);
  v294 = (*p_fldSave)->PushBlock;
  backupPushBlock(v292, &saveData->fldSave.PushBlock30, &v294->m_Items[30]);
  v298 = (*p_fldSave)->PushBlock;
  backupPushBlock(v296, &saveData->fldSave.PushBlock31, &v298->m_Items[31]);
  v302 = (*p_fldSave)->PushBlock;
  backupPushBlock(v300, &saveData->fldSave.PushBlock32, &v302->m_Items[32]);
  v306 = (*p_fldSave)->PushBlock;
  backupPushBlock(v304, &saveData->fldSave.PushBlock33, &v306->m_Items[33]);
  v310 = (*p_fldSave)->PushBlock;
  backupPushBlock(v308, &saveData->fldSave.PushBlock34, &v310->m_Items[34]);
  v314 = (*p_fldSave)->PushBlock;
  backupPushBlock(v312, &saveData->fldSave.PushBlock35, &v314->m_Items[35]);
  v318 = (*p_fldSave)->PushBlock;
  backupPushBlock(v316, &saveData->fldSave.PushBlock36, &v318->m_Items[36]);
  v322 = (*p_fldSave)->PushBlock;
  backupPushBlock(v320, &saveData->fldSave.PushBlock37, &v322->m_Items[37]);
  v326 = (*p_fldSave)->PushBlock;
  backupPushBlock(v324, &saveData->fldSave.PushBlock38, &v326->m_Items[38]);
  v330 = (*p_fldSave)->PushBlock;
  backupPushBlock(v328, &saveData->fldSave.PushBlock39, &v330->m_Items[39]);
  blkOpenFlg = (*p_fldSave)->amap->blkOpenFlg;
  Copy_3886320(blkOpenFlg->m_Items[0], saveData->fldSave.amap.blkOpenFlg00, saveData->fldSave.amap.blkOpenFlg00->max_length);
  v334 = (*p_fldSave)->amap->blkOpenFlg;
  Copy_3886320(v334->m_Items[1], saveData->fldSave.amap.blkOpenFlg01, saveData->fldSave.amap.blkOpenFlg01->max_length);
  v336 = (*p_fldSave)->amap->blkOpenFlg;
  Copy_3886320(v336->m_Items[2], saveData->fldSave.amap.blkOpenFlg02, saveData->fldSave.amap.blkOpenFlg02->max_length);
  v338 = (*p_fldSave)->amap->blkOpenFlg;
  Copy_3886320(v338->m_Items[3], saveData->fldSave.amap.blkOpenFlg03, saveData->fldSave.amap.blkOpenFlg03->max_length);
  v340 = (*p_fldSave)->amap->blkOpenFlg;
  Copy_3886320(v340->m_Items[4], saveData->fldSave.amap.blkOpenFlg04, saveData->fldSave.amap.blkOpenFlg04->max_length);
  v342 = (*p_fldSave)->amap->blkOpenFlg;
  Copy_3886320(v342->m_Items[5], saveData->fldSave.amap.blkOpenFlg05, saveData->fldSave.amap.blkOpenFlg05->max_length);
  v344 = (*p_fldSave)->amap->blkOpenFlg;
  Copy_3886320(v344->m_Items[6], saveData->fldSave.amap.blkOpenFlg06, saveData->fldSave.amap.blkOpenFlg06->max_length);
  v346 = (*p_fldSave)->amap->blkOpenFlg;
  Copy_3886320(v346->m_Items[7], saveData->fldSave.amap.blkOpenFlg07, saveData->fldSave.amap.blkOpenFlg07->max_length);
  v348 = (*p_fldSave)->amap->blkOpenFlg;
  Copy_3886320(v348->m_Items[8], saveData->fldSave.amap.blkOpenFlg08, saveData->fldSave.amap.blkOpenFlg08->max_length);
  v350 = (*p_fldSave)->amap->blkOpenFlg;
  Copy_3886320(v350->m_Items[9], saveData->fldSave.amap.blkOpenFlg09, saveData->fldSave.amap.blkOpenFlg09->max_length);
  v352 = (*p_fldSave)->amap->blkOpenFlg;
  Copy_3886320(v352->m_Items[10], saveData->fldSave.amap.blkOpenFlg10, saveData->fldSave.amap.blkOpenFlg10->max_length);
  v354 = (*p_fldSave)->amap->blkOpenFlg;
  Copy_3886320(v354->m_Items[11], saveData->fldSave.amap.blkOpenFlg11, saveData->fldSave.amap.blkOpenFlg11->max_length);
  v356 = (*p_fldSave)->amap->blkOpenFlg;
  Copy_3886320(v356->m_Items[12], saveData->fldSave.amap.blkOpenFlg12, saveData->fldSave.amap.blkOpenFlg12->max_length);
  v358 = (*p_fldSave)->amap->blkOpenFlg;
  Copy_3886320(v358->m_Items[13], saveData->fldSave.amap.blkOpenFlg13, saveData->fldSave.amap.blkOpenFlg13->max_length);
  v360 = (*p_fldSave)->amap->blkOpenFlg;
  Copy_3886320(v360->m_Items[14], saveData->fldSave.amap.blkOpenFlg14, saveData->fldSave.amap.blkOpenFlg14->max_length);
  v362 = (*p_fldSave)->amap->blkOpenFlg;
  Copy_3886320(v362->m_Items[15], saveData->fldSave.amap.blkOpenFlg15, saveData->fldSave.amap.blkOpenFlg15->max_length);
  v364 = (*p_fldSave)->amap->blkOpenFlg;
  Copy_3886320(v364->m_Items[16], saveData->fldSave.amap.blkOpenFlg16, saveData->fldSave.amap.blkOpenFlg16->max_length);
  v366 = (*p_fldSave)->amap->blkOpenFlg;
  Copy_3886320(v366->m_Items[17], saveData->fldSave.amap.blkOpenFlg17, saveData->fldSave.amap.blkOpenFlg17->max_length);
  v368 = (*p_fldSave)->amap->blkOpenFlg;
  Copy_3886320(v368->m_Items[18], saveData->fldSave.amap.blkOpenFlg18, saveData->fldSave.amap.blkOpenFlg18->max_length);
  v370 = (*p_fldSave)->amap->blkOpenFlg;
  Copy_3886320(v370->m_Items[19], saveData->fldSave.amap.blkOpenFlg19, saveData->fldSave.amap.blkOpenFlg19->max_length);
  v372 = (*p_fldSave)->amap->blkOpenFlg;
  Copy_3886320(v372->m_Items[20], saveData->fldSave.amap.blkOpenFlg20, saveData->fldSave.amap.blkOpenFlg20->max_length);
  v374 = (*p_fldSave)->amap->blkOpenFlg;
  Copy_3886320(v374->m_Items[21], saveData->fldSave.amap.blkOpenFlg21, saveData->fldSave.amap.blkOpenFlg21->max_length);
  v376 = (*p_fldSave)->amap->blkOpenFlg;
  Copy_3886320(v376->m_Items[22], saveData->fldSave.amap.blkOpenFlg22, saveData->fldSave.amap.blkOpenFlg22->max_length);
  v378 = (*p_fldSave)->amap->blkOpenFlg;
  Copy_3886320(v378->m_Items[23], saveData->fldSave.amap.blkOpenFlg23, saveData->fldSave.amap.blkOpenFlg23->max_length);
  v380 = (*p_fldSave)->amap->blkOpenFlg;
  Copy_3886320(v380->m_Items[24], saveData->fldSave.amap.blkOpenFlg24, saveData->fldSave.amap.blkOpenFlg24->max_length);
  v382 = (*p_fldSave)->amap->blkOpenFlg;
  Copy_3886320(v382->m_Items[25], saveData->fldSave.amap.blkOpenFlg25, saveData->fldSave.amap.blkOpenFlg25->max_length);
  v384 = (*p_fldSave)->amap->blkOpenFlg;
  Copy_3886320(v384->m_Items[26], saveData->fldSave.amap.blkOpenFlg26, saveData->fldSave.amap.blkOpenFlg26->max_length);
  v386 = (*p_fldSave)->amap->blkOpenFlg;
  Copy_3886320(v386->m_Items[27], saveData->fldSave.amap.blkOpenFlg27, saveData->fldSave.amap.blkOpenFlg27->max_length);
  v388 = (*p_fldSave)->amap->blkOpenFlg;
  Copy_3886320(v388->m_Items[28], saveData->fldSave.amap.blkOpenFlg28, saveData->fldSave.amap.blkOpenFlg28->max_length);
  v390 = (*p_fldSave)->amap->blkOpenFlg;
  Copy_3886320(v390->m_Items[29], saveData->fldSave.amap.blkOpenFlg29, saveData->fldSave.amap.blkOpenFlg29->max_length);
  Copy_3886320(data->fldSave->takara, saveData->fldSave.takara, saveData->fldSave.takara->max_length);
  saveData->fldSave.tmnltype = data->fldSave->tmnltype;
  saveData->fldSave.tmnlid = data->fldSave->tmnlid;
  saveData->fldSave.AnahoriCnt = data->fldSave->AnahoriCnt;
  Copy_3886320(data->fldSave->takara2, saveData->fldSave.takara2, saveData->fldSave.takara2->max_length);
  Copy_3886320(data->fldSave->pub, saveData->fldSave.pub, saveData->fldSave.pub->max_length);
  Copy_3886320(data->config_data, saveData->config_data, saveData->config_data->max_length);
  saveData->dmy = data->dmy;
  hearts_sk = data->hearts_sk;
  p_hearts_sk = &data->hearts_sk;
  Copy_3886320(hearts_sk->m_Items[0], saveData->hearts_sk00, saveData->hearts_sk00->max_length);
  Copy_3886320(
    (*p_hearts_sk)->m_Items[1],
    saveData->hearts_sk01,
    saveData->hearts_sk01->max_length,
    0);
  Copy_3886320(
    (*p_hearts_sk)->m_Items[2],
    saveData->hearts_sk02,
    saveData->hearts_sk02->max_length,
    0);
  Copy_3886320(
    (*p_hearts_sk)->m_Items[3],
    saveData->hearts_sk03,
    saveData->hearts_sk03->max_length,
    0);
  Copy_3886320(
    (*p_hearts_sk)->m_Items[4],
    saveData->hearts_sk04,
    saveData->hearts_sk04->max_length,
    0);
  Copy_3886320(
    (*p_hearts_sk)->m_Items[5],
    saveData->hearts_sk05,
    saveData->hearts_sk05->max_length,
    0);
  Copy_3886320(
    (*p_hearts_sk)->m_Items[6],
    saveData->hearts_sk06,
    saveData->hearts_sk06->max_length,
    0);
  Copy_3886320(
    (*p_hearts_sk)->m_Items[7],
    saveData->hearts_sk07,
    saveData->hearts_sk07->max_length,
    0);
  Copy_3886320(
    (*p_hearts_sk)->m_Items[8],
    saveData->hearts_sk08,
    saveData->hearts_sk08->max_length,
    0);
  Copy_3886320(
    (*p_hearts_sk)->m_Items[9],
    saveData->hearts_sk09,
    saveData->hearts_sk09->max_length,
    0);
  Copy_3886320(
    (*p_hearts_sk)->m_Items[10],
    saveData->hearts_sk10,
    saveData->hearts_sk10->max_length,
    0);
  Copy_3886320(
    (*p_hearts_sk)->m_Items[11],
    saveData->hearts_sk11,
    saveData->hearts_sk11->max_length,
    0);
  Copy_3886320(
    (*p_hearts_sk)->m_Items[12],
    saveData->hearts_sk12,
    saveData->hearts_sk12->max_length,
    0);
  Copy_3886320(
    (*p_hearts_sk)->m_Items[13],
    saveData->hearts_sk13,
    saveData->hearts_sk13->max_length,
    0);
  Copy_3886320(
    (*p_hearts_sk)->m_Items[14],
    saveData->hearts_sk14,
    saveData->hearts_sk14->max_length,
    0);
  Copy_3886320(
    (*p_hearts_sk)->m_Items[15],
    saveData->hearts_sk15,
    saveData->hearts_sk15->max_length,
    0);
  Copy_3886320(
    (*p_hearts_sk)->m_Items[16],
    saveData->hearts_sk16,
    saveData->hearts_sk16->max_length,
    0);
  Copy_3886320(
    (*p_hearts_sk)->m_Items[17],
    saveData->hearts_sk17,
    saveData->hearts_sk17->max_length,
    0);
  Copy_3886320(
    (*p_hearts_sk)->m_Items[18],
    saveData->hearts_sk18,
    saveData->hearts_sk18->max_length,
    0);
  Copy_3886320(
    (*p_hearts_sk)->m_Items[19],
    saveData->hearts_sk19,
    saveData->hearts_sk19->max_length,
    0);
  Copy_3886320(
    (*p_hearts_sk)->m_Items[20],
    saveData->hearts_sk20,
    saveData->hearts_sk20->max_length,
    0);
  Copy_3886320(
    (*p_hearts_sk)->m_Items[21],
    saveData->hearts_sk21,
    saveData->hearts_sk21->max_length,
    0);
  Copy_3886320(
    (*p_hearts_sk)->m_Items[22],
    saveData->hearts_sk22,
    saveData->hearts_sk22->max_length,
    0);
  Copy_3886320(
    (*p_hearts_sk)->m_Items[23],
    saveData->hearts_sk23,
    saveData->hearts_sk23->max_length,
    0);
  Copy_3886320(
    (*p_hearts_sk)->m_Items[24],
    saveData->hearts_sk24,
    saveData->hearts_sk24->max_length,
    0);
  Copy_3886320(
    (*p_hearts_sk)->m_Items[25],
    saveData->hearts_sk25,
    saveData->hearts_sk25->max_length,
    0);
  Copy_3886320(
    (*p_hearts_sk)->m_Items[26],
    saveData->hearts_sk26,
    saveData->hearts_sk26->max_length,
    0);
  Copy_3886320(
    (*p_hearts_sk)->m_Items[27],
    saveData->hearts_sk27,
    saveData->hearts_sk27->max_length,
    0);
  Copy_3886320(
    (*p_hearts_sk)->m_Items[28],
    saveData->hearts_sk28,
    saveData->hearts_sk28->max_length,
    0);
  Copy_3886320(
    (*p_hearts_sk)->m_Items[29],
    saveData->hearts_sk29,
    saveData->hearts_sk29->max_length,
    0);
  Copy_3886320(
    (*p_hearts_sk)->m_Items[30],
    saveData->hearts_sk30,
    saveData->hearts_sk30->max_length,
    0);
  v425 = *p_hearts_sk;
  Copy_3886320(v425->m_Items[31], saveData->hearts_sk31, saveData->hearts_sk31->max_length);
  hearts_up_param = data->hearts_up_param;
  p_hearts_up_param = &data->hearts_up_param;
  Copy_3886320(hearts_up_param->m_Items[0], saveData->hearts_up_param00, saveData->hearts_up_param00->max_length);
  Copy_3886320(
    (*p_hearts_up_param)->m_Items[1],
    saveData->hearts_up_param01,
    saveData->hearts_up_param01->max_length,
    0);
  Copy_3886320(
    (*p_hearts_up_param)->m_Items[2],
    saveData->hearts_up_param02,
    saveData->hearts_up_param02->max_length,
    0);
  Copy_3886320(
    (*p_hearts_up_param)->m_Items[3],
    saveData->hearts_up_param03,
    saveData->hearts_up_param03->max_length,
    0);
  Copy_3886320(
    (*p_hearts_up_param)->m_Items[4],
    saveData->hearts_up_param04,
    saveData->hearts_up_param04->max_length,
    0);
  Copy_3886320(
    (*p_hearts_up_param)->m_Items[5],
    saveData->hearts_up_param05,
    saveData->hearts_up_param05->max_length,
    0);
  Copy_3886320(
    (*p_hearts_up_param)->m_Items[6],
    saveData->hearts_up_param06,
    saveData->hearts_up_param06->max_length,
    0);
  Copy_3886320(
    (*p_hearts_up_param)->m_Items[7],
    saveData->hearts_up_param07,
    saveData->hearts_up_param07->max_length,
    0);
  Copy_3886320(
    (*p_hearts_up_param)->m_Items[8],
    saveData->hearts_up_param08,
    saveData->hearts_up_param08->max_length,
    0);
  Copy_3886320(
    (*p_hearts_up_param)->m_Items[9],
    saveData->hearts_up_param09,
    saveData->hearts_up_param09->max_length,
    0);
  Copy_3886320(
    (*p_hearts_up_param)->m_Items[10],
    saveData->hearts_up_param10,
    saveData->hearts_up_param10->max_length,
    0);
  Copy_3886320(
    (*p_hearts_up_param)->m_Items[11],
    saveData->hearts_up_param11,
    saveData->hearts_up_param11->max_length,
    0);
  Copy_3886320(
    (*p_hearts_up_param)->m_Items[12],
    saveData->hearts_up_param12,
    saveData->hearts_up_param12->max_length,
    0);
  Copy_3886320(
    (*p_hearts_up_param)->m_Items[13],
    saveData->hearts_up_param13,
    saveData->hearts_up_param13->max_length,
    0);
  Copy_3886320(
    (*p_hearts_up_param)->m_Items[14],
    saveData->hearts_up_param14,
    saveData->hearts_up_param14->max_length,
    0);
  Copy_3886320(
    (*p_hearts_up_param)->m_Items[15],
    saveData->hearts_up_param15,
    saveData->hearts_up_param15->max_length,
    0);
  Copy_3886320(
    (*p_hearts_up_param)->m_Items[16],
    saveData->hearts_up_param16,
    saveData->hearts_up_param16->max_length,
    0);
  Copy_3886320(
    (*p_hearts_up_param)->m_Items[17],
    saveData->hearts_up_param17,
    saveData->hearts_up_param17->max_length,
    0);
  Copy_3886320(
    (*p_hearts_up_param)->m_Items[18],
    saveData->hearts_up_param18,
    saveData->hearts_up_param18->max_length,
    0);
  Copy_3886320(
    (*p_hearts_up_param)->m_Items[19],
    saveData->hearts_up_param19,
    saveData->hearts_up_param19->max_length,
    0);
  Copy_3886320(
    (*p_hearts_up_param)->m_Items[20],
    saveData->hearts_up_param20,
    saveData->hearts_up_param20->max_length,
    0);
  Copy_3886320(
    (*p_hearts_up_param)->m_Items[21],
    saveData->hearts_up_param21,
    saveData->hearts_up_param21->max_length,
    0);
  Copy_3886320(
    (*p_hearts_up_param)->m_Items[22],
    saveData->hearts_up_param22,
    saveData->hearts_up_param22->max_length,
    0);
  Copy_3886320(
    (*p_hearts_up_param)->m_Items[23],
    saveData->hearts_up_param23,
    saveData->hearts_up_param23->max_length,
    0);
  Copy_3886320(
    (*p_hearts_up_param)->m_Items[24],
    saveData->hearts_up_param24,
    saveData->hearts_up_param24->max_length,
    0);
  Copy_3886320(
    (*p_hearts_up_param)->m_Items[25],
    saveData->hearts_up_param25,
    saveData->hearts_up_param25->max_length,
    0);
  Copy_3886320(
    (*p_hearts_up_param)->m_Items[26],
    saveData->hearts_up_param26,
    saveData->hearts_up_param26->max_length,
    0);
  Copy_3886320(
    (*p_hearts_up_param)->m_Items[27],
    saveData->hearts_up_param27,
    saveData->hearts_up_param27->max_length,
    0);
  Copy_3886320(
    (*p_hearts_up_param)->m_Items[28],
    saveData->hearts_up_param28,
    saveData->hearts_up_param28->max_length,
    0);
  Copy_3886320(
    (*p_hearts_up_param)->m_Items[29],
    saveData->hearts_up_param29,
    saveData->hearts_up_param29->max_length,
    0);
  Copy_3886320(
    (*p_hearts_up_param)->m_Items[30],
    saveData->hearts_up_param30,
    saveData->hearts_up_param30->max_length,
    0);
  v460 = *p_hearts_up_param;
  Copy_3886320(v460->m_Items[31], saveData->hearts_up_param31, saveData->hearts_up_param31->max_length);
  saveData->encyc_record.num = data->encyc_record->num;
  saveData->encyc_record.reserved0 = data->encyc_record->reserved0;
  saveData->encyc_record.reserved1 = data->encyc_record->reserved1;
  v462 = 0;
  p_encyc_record = &data->encyc_record;
  p_pelem = &saveData->encyc_record.pelem;
  v465 = 124;
  saveData->encyc_record.reserved2 = data->encyc_record->reserved2;
  do
  {
    pelem = (*p_encyc_record)->pelem;
    v467 = *p_pelem;
    id = pelem->m_Items[v462]->id;
    *(v467 + v465 - 92) = id;
    v471 = (*p_encyc_record)->pelem;
    v472 = *p_pelem;
    reserved0 = v471->m_Items[v462]->reserved0;
    *(v472 + v465 - 90) = reserved0;
    v476 = (*p_encyc_record)->pelem;
    v477 = *p_pelem;
    maxhp = v476->m_Items[v462]->maxhp;
    *(v477 + v465 - 88) = maxhp;
    v481 = (*p_encyc_record)->pelem;
    v482 = *p_pelem;
    maxmp = v481->m_Items[v462]->maxmp;
    *(v482 + v465 - 86) = maxmp;
    v486 = (*p_encyc_record)->pelem;
    v487 = *p_pelem;
    exp = v486->m_Items[v462]->exp;
    *(v487 + v465 - 84) = exp;
    v491 = (*p_encyc_record)->pelem;
    v492 = *p_pelem;
    level = v491->m_Items[v462]->level;
    *(v492 + v465 - 80) = level;
    v496 = (*p_encyc_record)->pelem;
    param = v496->m_Items[v462]->param;
    Copy_3886320(param, *(*p_pelem + v465 - 76), *(*(*p_pelem + v465 - 76) + 24LL), 0);
    v500 = (*p_encyc_record)->pelem;
    skillparam = v500->m_Items[v462]->skillparam;
    Copy_3886320(skillparam, *(*p_pelem + v465 - 68), *(*(*p_pelem + v465 - 68) + 24LL), 0);
    v504 = (*p_encyc_record)->pelem;
    v505 = *p_pelem;
    skillcnt = v504->m_Items[v462]->skillcnt;
    *(v505 + v465 - 60) = skillcnt;
    v509 = (*p_encyc_record)->pelem;
    skill = v509->m_Items[v462]->skill;
    Copy_3886320(skill, *(*p_pelem + v465 - 52), *(*(*p_pelem + v465 - 52) + 24LL), 0);
    v513 = (*p_encyc_record)->pelem;
    mitamaparam = v513->m_Items[v462]->mitamaparam;
    Copy_3886320(mitamaparam, *(*p_pelem + v465 - 44), *(*(*p_pelem + v465 - 44) + 24LL), 0);
    v517 = (*p_encyc_record)->pelem;
    levelupparam = v517->m_Items[v462]->levelupparam;
    Copy_3886320(levelupparam, *(*p_pelem + v465 - 36), *(*(*p_pelem + v465 - 36) + 24LL), 0);
    v521 = (*p_encyc_record)->pelem;
    keisyoskill = v521->m_Items[v462]->keisyoskill;
    Copy_3886320(keisyoskill, *(*p_pelem + v465 - 28), *(*(*p_pelem + v465 - 28) + 24LL), 0);
    v525 = (*p_encyc_record)->pelem;
    keiattr = v525->m_Items[v462]->keiattr;
    Copy_3886320(keiattr, *(*p_pelem + v465 - 20), *(*(*p_pelem + v465 - 20) + 24LL), 0);
    v529 = (*p_encyc_record)->pelem;
    v530 = *p_pelem;
    hensinmae = v529->m_Items[v462]->hensinmae;
    *(v530 + v465 - 12) = hensinmae;
    v534 = (*p_encyc_record)->pelem;
    v535 = *p_pelem;
    reserved1 = v534->m_Items[v462]->reserved1;
    *(v535 + v465 - 10) = reserved1;
    v539 = (*p_encyc_record)->pelem;
    v540 = *p_pelem;
    flag = v539->m_Items[v462]->flag;
    *(v540 + v465 - 8) = flag;
    v544 = (*p_encyc_record)->pelem;
    v545 = *p_pelem;
    reserved2 = v544->m_Items[v462]->reserved2;
    *(v545 + v465 - 4) = reserved2;
    v549 = (*p_encyc_record)->pelem;
    v550 = *p_pelem;
    hensinmaeexp = v549->m_Items[v462]->hensinmaeexp;
    ++v462;
    *(&v550->obj.klass + v465) = hensinmaeexp;
    v465 += 96;
  }
  while (v462 != 184);
  v554 = data->amap31->blkOpenFlg;
  Copy_3886320(v554->m_Items[0], saveData->amap31.blkOpenFlg00, saveData->amap31.blkOpenFlg00->max_length);
  v556 = data->amap31->blkOpenFlg;
  Copy_3886320(v556->m_Items[1], saveData->amap31.blkOpenFlg01, saveData->amap31.blkOpenFlg01->max_length);
  v558 = data->amap31->blkOpenFlg;
  Copy_3886320(v558->m_Items[2], saveData->amap31.blkOpenFlg02, saveData->amap31.blkOpenFlg02->max_length);
  v560 = data->amap31->blkOpenFlg;
  Copy_3886320(v560->m_Items[3], saveData->amap31.blkOpenFlg03, saveData->amap31.blkOpenFlg03->max_length);
  v562 = data->amap31->blkOpenFlg;
  Copy_3886320(v562->m_Items[4], saveData->amap31.blkOpenFlg04, saveData->amap31.blkOpenFlg04->max_length);
  v564 = data->amap31->blkOpenFlg;
  Copy_3886320(v564->m_Items[5], saveData->amap31.blkOpenFlg05, saveData->amap31.blkOpenFlg05->max_length);
  v566 = data->amap31->blkOpenFlg;
  Copy_3886320(v566->m_Items[6], saveData->amap31.blkOpenFlg06, saveData->amap31.blkOpenFlg06->max_length);
  v568 = data->amap31->blkOpenFlg;
  Copy_3886320(v568->m_Items[7], saveData->amap31.blkOpenFlg07, saveData->amap31.blkOpenFlg07->max_length);
  v570 = data->amapEX->blkOpenFlg;
  Copy_3886320(v570->m_Items[0], saveData->amapEX.blkOpenFlg00, saveData->amapEX.blkOpenFlg00->max_length);
  v572 = data->amapEX->blkOpenFlg;
  Copy_3886320(v572->m_Items[1], saveData->amapEX.blkOpenFlg01, saveData->amapEX.blkOpenFlg01->max_length);
  v574 = data->amap_Ver7->blkOpenFlg;
  p_amap_Ver7 = &data->amap_Ver7;
  Copy_3886320(v574->m_Items[0], saveDataVer7->amap.blkOpenFlg00, saveDataVer7->amap.blkOpenFlg00->max_length);
  v577 = (*p_amap_Ver7)->blkOpenFlg;
  Copy_3886320(v577->m_Items[1], saveDataVer7->amap.blkOpenFlg01, saveDataVer7->amap.blkOpenFlg01->max_length);
  v579 = (*p_amap_Ver7)->blkOpenFlg;
  Copy_3886320(v579->m_Items[2], saveDataVer7->amap.blkOpenFlg02, saveDataVer7->amap.blkOpenFlg02->max_length);
  v581 = (*p_amap_Ver7)->blkOpenFlg;
  Copy_3886320(v581->m_Items[3], saveDataVer7->amap.blkOpenFlg03, saveDataVer7->amap.blkOpenFlg03->max_length);
  v583 = (*p_amap_Ver7)->blkOpenFlg;
  Copy_3886320(v583->m_Items[4], saveDataVer7->amap.blkOpenFlg04, saveDataVer7->amap.blkOpenFlg04->max_length);
  v585 = (*p_amap_Ver7)->blkOpenFlg;
  Copy_3886320(v585->m_Items[5], saveDataVer7->amap.blkOpenFlg05, saveDataVer7->amap.blkOpenFlg05->max_length);
  v587 = (*p_amap_Ver7)->blkOpenFlg;
  Copy_3886320(v587->m_Items[6], saveDataVer7->amap.blkOpenFlg06, saveDataVer7->amap.blkOpenFlg06->max_length);
  v589 = (*p_amap_Ver7)->blkOpenFlg;
  Copy_3886320(v589->m_Items[7], saveDataVer7->amap.blkOpenFlg07, saveDataVer7->amap.blkOpenFlg07->max_length);
  v591 = (*p_amap_Ver7)->blkOpenFlg;
  Copy_3886320(v591->m_Items[8], saveDataVer7->amap.blkOpenFlg08, saveDataVer7->amap.blkOpenFlg08->max_length);
  v593 = (*p_amap_Ver7)->blkOpenFlg;
  Copy_3886320(v593->m_Items[9], saveDataVer7->amap.blkOpenFlg09, saveDataVer7->amap.blkOpenFlg09->max_length);
  v595 = (*p_amap_Ver7)->blkOpenFlg;
  Copy_3886320(v595->m_Items[10], saveDataVer7->amap.blkOpenFlg10, saveDataVer7->amap.blkOpenFlg10->max_length);
  v597 = (*p_amap_Ver7)->blkOpenFlg;
  Copy_3886320(v597->m_Items[11], saveDataVer7->amap.blkOpenFlg11, saveDataVer7->amap.blkOpenFlg11->max_length);
  v599 = (*p_amap_Ver7)->blkOpenFlg;
  Copy_3886320(v599->m_Items[12], saveDataVer7->amap.blkOpenFlg12, saveDataVer7->amap.blkOpenFlg12->max_length);
  v601 = (*p_amap_Ver7)->blkOpenFlg;
  Copy_3886320(v601->m_Items[13], saveDataVer7->amap.blkOpenFlg13, saveDataVer7->amap.blkOpenFlg13->max_length);
  v603 = (*p_amap_Ver7)->blkOpenFlg;
  Copy_3886320(v603->m_Items[14], saveDataVer7->amap.blkOpenFlg14, saveDataVer7->amap.blkOpenFlg14->max_length);
  v605 = (*p_amap_Ver7)->blkOpenFlg;
  Copy_3886320(v605->m_Items[15], saveDataVer7->amap.blkOpenFlg15, saveDataVer7->amap.blkOpenFlg15->max_length);
  v607 = (*p_amap_Ver7)->blkOpenFlg;
  Copy_3886320(v607->m_Items[16], saveDataVer7->amap.blkOpenFlg16, saveDataVer7->amap.blkOpenFlg16->max_length);
  v609 = (*p_amap_Ver7)->blkOpenFlg;
  Copy_3886320(v609->m_Items[17], saveDataVer7->amap.blkOpenFlg17, saveDataVer7->amap.blkOpenFlg17->max_length);
  v611 = (*p_amap_Ver7)->blkOpenFlg;
  Copy_3886320(v611->m_Items[18], saveDataVer7->amap.blkOpenFlg18, saveDataVer7->amap.blkOpenFlg18->max_length);
  v613 = (*p_amap_Ver7)->blkOpenFlg;
  Copy_3886320(v613->m_Items[19], saveDataVer7->amap.blkOpenFlg19, saveDataVer7->amap.blkOpenFlg19->max_length);
  v615 = (*p_amap_Ver7)->blkOpenFlg;
  Copy_3886320(v615->m_Items[20], saveDataVer7->amap.blkOpenFlg20, saveDataVer7->amap.blkOpenFlg20->max_length);
  v617 = (*p_amap_Ver7)->blkOpenFlg;
  Copy_3886320(v617->m_Items[21], saveDataVer7->amap.blkOpenFlg21, saveDataVer7->amap.blkOpenFlg21->max_length);
  v619 = (*p_amap_Ver7)->blkOpenFlg;
  Copy_3886320(v619->m_Items[22], saveDataVer7->amap.blkOpenFlg22, saveDataVer7->amap.blkOpenFlg22->max_length);
  v621 = (*p_amap_Ver7)->blkOpenFlg;
  Copy_3886320(v621->m_Items[23], saveDataVer7->amap.blkOpenFlg23, saveDataVer7->amap.blkOpenFlg23->max_length);
  v623 = (*p_amap_Ver7)->blkOpenFlg;
  Copy_3886320(v623->m_Items[24], saveDataVer7->amap.blkOpenFlg24, saveDataVer7->amap.blkOpenFlg24->max_length);
  v625 = (*p_amap_Ver7)->blkOpenFlg;
  Copy_3886320(v625->m_Items[25], saveDataVer7->amap.blkOpenFlg25, saveDataVer7->amap.blkOpenFlg25->max_length);
  v627 = (*p_amap_Ver7)->blkOpenFlg;
  Copy_3886320(v627->m_Items[26], saveDataVer7->amap.blkOpenFlg26, saveDataVer7->amap.blkOpenFlg26->max_length);
  v629 = (*p_amap_Ver7)->blkOpenFlg;
  Copy_3886320(v629->m_Items[27], saveDataVer7->amap.blkOpenFlg27, saveDataVer7->amap.blkOpenFlg27->max_length);
  v631 = (*p_amap_Ver7)->blkOpenFlg;
  Copy_3886320(v631->m_Items[28], saveDataVer7->amap.blkOpenFlg28, saveDataVer7->amap.blkOpenFlg28->max_length);
  v633 = (*p_amap_Ver7)->blkOpenFlg;
  Copy_3886320(v633->m_Items[29], saveDataVer7->amap.blkOpenFlg29, saveDataVer7->amap.blkOpenFlg29->max_length);
  v635 = data->amap31_Ver7->blkOpenFlg;
  Copy_3886320(v635->m_Items[0], saveDataVer7->amap31.blkOpenFlg00, saveDataVer7->amap31.blkOpenFlg00->max_length);
  v637 = data->amap31_Ver7->blkOpenFlg;
  Copy_3886320(v637->m_Items[1], saveDataVer7->amap31.blkOpenFlg01, saveDataVer7->amap31.blkOpenFlg01->max_length);
  v639 = data->amap31_Ver7->blkOpenFlg;
  Copy_3886320(v639->m_Items[2], saveDataVer7->amap31.blkOpenFlg02, saveDataVer7->amap31.blkOpenFlg02->max_length);
  v641 = data->amap31_Ver7->blkOpenFlg;
  Copy_3886320(v641->m_Items[3], saveDataVer7->amap31.blkOpenFlg03, saveDataVer7->amap31.blkOpenFlg03->max_length);
  v643 = data->amap31_Ver7->blkOpenFlg;
  Copy_3886320(v643->m_Items[4], saveDataVer7->amap31.blkOpenFlg04, saveDataVer7->amap31.blkOpenFlg04->max_length);
  v645 = data->amap31_Ver7->blkOpenFlg;
  Copy_3886320(v645->m_Items[5], saveDataVer7->amap31.blkOpenFlg05, saveDataVer7->amap31.blkOpenFlg05->max_length);
  v647 = data->amap31_Ver7->blkOpenFlg;
  Copy_3886320(v647->m_Items[6], saveDataVer7->amap31.blkOpenFlg06, saveDataVer7->amap31.blkOpenFlg06->max_length);
  v649 = data->amap31_Ver7->blkOpenFlg;
  Copy_3886320(v649->m_Items[7], saveDataVer7->amap31.blkOpenFlg07, saveDataVer7->amap31.blkOpenFlg07->max_length);
  v651 = data->amapEX_Ver7->blkOpenFlg;
  Copy_3886320(v651->m_Items[0], saveDataVer7->amapEX.blkOpenFlg00, saveDataVer7->amapEX.blkOpenFlg00->max_length);
  v653 = data->amapEX_Ver7->blkOpenFlg;
  Copy_3886320(v653->m_Items[1], saveDataVer7->amapEX.blkOpenFlg01, saveDataVer7->amapEX.blkOpenFlg01->max_length);
  v655 = (*p_encyc_record)->pelem;
  saveDataVer7->dante_pelem.id = v655->m_Items[184]->id;
  v657 = (*p_encyc_record)->pelem;
  saveDataVer7->dante_pelem.reserved0 = v657->m_Items[184]->reserved0;
  v659 = (*p_encyc_record)->pelem;
  saveDataVer7->dante_pelem.maxhp = v659->m_Items[184]->maxhp;
  v661 = (*p_encyc_record)->pelem;
  saveDataVer7->dante_pelem.maxmp = v661->m_Items[184]->maxmp;
  v663 = (*p_encyc_record)->pelem;
  saveDataVer7->dante_pelem.exp = v663->m_Items[184]->exp;
  v665 = (*p_encyc_record)->pelem;
  saveDataVer7->dante_pelem.level = v665->m_Items[184]->level;
  v667 = (*p_encyc_record)->pelem;
  Copy_3886320(v667->m_Items[184]->param, saveDataVer7->dante_pelem.param, saveDataVer7->dante_pelem.param->max_length);
  v669 = (*p_encyc_record)->pelem;
  Copy_3886320(v669->m_Items[184]->skillparam, saveDataVer7->dante_pelem.skillparam, saveDataVer7->dante_pelem.skillparam->max_length);
  v671 = (*p_encyc_record)->pelem;
  saveDataVer7->dante_pelem.skillcnt = v671->m_Items[184]->skillcnt;
  v673 = (*p_encyc_record)->pelem;
  Copy_3886320(v673->m_Items[184]->skill, saveDataVer7->dante_pelem.skill, saveDataVer7->dante_pelem.skill->max_length);
  v675 = (*p_encyc_record)->pelem;
  Copy_3886320(v675->m_Items[184]->mitamaparam, saveDataVer7->dante_pelem.mitamaparam, saveDataVer7->dante_pelem.mitamaparam->max_length);
  v677 = (*p_encyc_record)->pelem;
  Copy_3886320(v677->m_Items[184]->levelupparam, saveDataVer7->dante_pelem.levelupparam, saveDataVer7->dante_pelem.levelupparam->max_length);
  v679 = (*p_encyc_record)->pelem;
  Copy_3886320(v679->m_Items[184]->keisyoskill, saveDataVer7->dante_pelem.keisyoskill, saveDataVer7->dante_pelem.keisyoskill->max_length);
  v681 = (*p_encyc_record)->pelem;
  Copy_3886320(v681->m_Items[184]->keiattr, saveDataVer7->dante_pelem.keiattr, saveDataVer7->dante_pelem.keiattr->max_length);
  v683 = (*p_encyc_record)->pelem;
  saveDataVer7->dante_pelem.hensinmae = v683->m_Items[184]->hensinmae;
  v685 = (*p_encyc_record)->pelem;
  saveDataVer7->dante_pelem.reserved1 = v685->m_Items[184]->reserved1;
  v687 = (*p_encyc_record)->pelem;
  saveDataVer7->dante_pelem.flag = v687->m_Items[184]->flag;
  v689 = (*p_encyc_record)->pelem;
  saveDataVer7->dante_pelem.reserved2 = v689->m_Items[184]->reserved2;
  v691 = (*p_encyc_record)->pelem;
  saveDataVer7->dante_pelem.hensinmaeexp = v691->m_Items[184]->hensinmaeexp;
  saveDataVer7->saveTime = data->GameFileInfo->saveTime;
  Copy_3886320(data->GameFileInfo->autoMapOpen, saveDataVer7->autoMapOpen, saveDataVer7->autoMapOpen->max_length);
  Copy_3886320(data->GameFileInfo->autoMapOpenEX, saveDataVer7->autoMapOpenEX, saveDataVer7->autoMapOpenEX->max_length);
  BackupFldRunWork();
  v695 = ToArray(SuspendData);
  Copy_3886320(v695, saveDataVer7->fldRunWork, saveDataVer7->fldRunWork->max_length);
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
      goto LABEL_3;
LABEL_10:
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
      goto LABEL_4;
    goto LABEL_20;
  }
  if (init)
    goto LABEL_10;
LABEL_3:
  if (num <= 19)
  {
LABEL_4:
    saveBuff = v8->saveBuff;
    saveVer7 = v8->saveVer7;
    backupBuff(this, &saveBuff->m_Items[num], data, &saveVer7->m_Items[num]);
    return;
  }
LABEL_20:
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
  System_Char_array *v6;
  System_Char_array *v7;
  struct System_Char_array *v8;
  struct System_Char_array *verstr;
  struct System_Int32_array *v15;
  struct SAVEDATA_datUnitWork_tag_array *v16;
  struct SAVEDATA_datUnitWork_tag_array *v17;
  u64 v18;
  s64 v19;
  u64 *v21;
  struct SAVEDATA_datUnitWork_tag_array *unitwork;
  u64 *v23;
  struct SAVEDATA_datUnitWork_tag_array *v25;
  u64 *v26;
  struct SAVEDATA_datUnitWork_tag_array *v28;
  u64 *v29;
  struct SAVEDATA_datUnitWork_tag_array *v31;
  u64 *v32;
  struct SAVEDATA_datUnitWork_tag_array *v34;
  u64 *v35;
  struct SAVEDATA_datUnitWork_tag_array *v37;
  u64 *v38;
  struct SAVEDATA_datUnitWork_tag_array *v40;
  u64 *v41;
  struct SAVEDATA_datUnitWork_tag_array *v43;
  u64 *v44;
  struct SAVEDATA_datUnitWork_tag_array *v46;
  u64 *v47;
  struct SAVEDATA_datUnitWork_tag_array *v49;
  Il2CppClass *v50;
  SAVEDATA_o *v52;
  SAVEDATA_o *v54;
  SAVEDATA_o *v56;
  SAVEDATA_o *v58;
  SAVEDATA_o *v60;
  SAVEDATA_o *v62;
  SAVEDATA_o *v64;
  SAVEDATA_o *v66;
  SAVEDATA_o *v68;
  SAVEDATA_o *v70;
  SAVEDATA_o *v72;
  SAVEDATA_o *v74;
  SAVEDATA_o *v76;
  SAVEDATA_o *v78;
  SAVEDATA_o *v80;
  SAVEDATA_o *v82;
  SAVEDATA_o *v84;
  SAVEDATA_o *v86;
  SAVEDATA_o *v88;
  SAVEDATA_o *v90;
  SAVEDATA_o *v92;
  SAVEDATA_o *v94;
  SAVEDATA_o *v96;
  SAVEDATA_o *v98;
  SAVEDATA_o *v100;
  SAVEDATA_o *v102;
  SAVEDATA_o *v104;
  SAVEDATA_o *v106;
  SAVEDATA_o *v108;
  SAVEDATA_o *v110;
  SAVEDATA_o *v112;
  SAVEDATA_o *v114;
  SAVEDATA_o *v116;
  SAVEDATA_o *v118;
  SAVEDATA_o *v120;
  SAVEDATA_o *v122;
  SAVEDATA_o *v124;
  SAVEDATA_o *v126;
  SAVEDATA_o *v128;
  SAVEDATA_o *v130;
  struct SAVEDATA_fclencyceelem_tag_array *v132;
  u64 v133;
  s64 v134;
  struct System_SByte_array *v135;
  struct SAVEDATA_fclencyceelem_tag_array *pelem;
  struct System_SByte_array *v138;
  struct SAVEDATA_fclencyceelem_tag_array *v140;
  struct System_UInt16_array *v141;
  struct SAVEDATA_fclencyceelem_tag_array *v143;
  struct System_SByte_array *v144;
  struct SAVEDATA_fclencyceelem_tag_array *v146;
  struct System_SByte_array *v147;
  struct SAVEDATA_fclencyceelem_tag_array *v149;
  struct System_UInt16_array *v150;
  struct SAVEDATA_fclencyceelem_tag_array *v152;
  struct System_Byte_array *v153;
  struct System_UInt32_array *v155;
  struct System_UInt32_array *v156;
  struct System_UInt32_array *v157;

  memset(data, 0, sizeof(SAVEDATA_dds3GlobalWork_tag_o));
  data->GameFileInfo.verstr = NewSpecific(char, 3u);
  v6 = NewSpecific(char, 0x10u);
  data->GameFileInfo.cname_code = CreateString_5280336(0, v6);
  v7 = NewSpecific(char, 0xFu);
  data->GameFileInfo.pad3 = CreateString_5280336(0, v7);
  v8 = NewSpecific(char, 7u);
  verstr = data->GameFileInfo.verstr;
  data->GameFileInfo.end_list = v8;
  verstr->m_Items[0] = 86;
  data->GameFileInfo.verstr->m_Items[1] = 69;
  data->GameFileInfo.verstr->m_Items[2] = 82;
  data->GameFileInfo.ver = saveVer;
  data->IntVariable = NewSpecific(s32, 0x100u);
  data->FloatVariable = NewSpecific(f32, 0x100u);
  v15 = NewSpecific(s32, 0x80u);
  data->Moon.MoveCnt = 0.0;
  *&data->Moon.Stat = 0;
  *&data->Moon.TakaraCnt = 0;
  data->EventBit = v15;
  v16 = NewSpecific(SAVEDATA_datUnitWork_tag, 0x10u);
  data->unitwork = v16;
  v17 = v16;
  v18 = 0;
  v19 = 176;
  if (!LODWORD(v16->max_length))
  {
LABEL_15:
  }
  while (1)
  {
    v21 = (&v17->obj.klass + v19);
    *(v21 - 1) = 0;
    *v21 = 0;
    *(v21 - 3) = 0;
    *(v21 - 2) = 0;
    *(v21 - 18) = 0;
    *(v21 - 5) = 0;
    *(v21 - 4) = 0;
    *(v21 - 7) = 0;
    *(v21 - 6) = 0;
    *(v21 - 9) = 0;
    *(v21 - 8) = 0;
    *(v21 - 11) = 0;
    *(v21 - 10) = 0;
    *(v21 - 13) = 0;
    *(v21 - 12) = 0;
    *(v21 - 15) = 0;
    *(v21 - 14) = 0;
    *(v21 - 17) = 0;
    *(v21 - 16) = 0;
    unitwork = data->unitwork;
    v23 = NewSpecific(sbyte, 6u);
    *(unitwork + v19 - 120) = v23;
    v25 = data->unitwork;
    v26 = NewSpecific(sbyte, 6u);
    *(v25 + v19 - 112) = v26;
    v28 = data->unitwork;
    v29 = NewSpecific(char, 8u);
    *(v28 + v19 - 96) = v29;
    v31 = data->unitwork;
    v32 = NewSpecific(s32, 0x18u);
    *(v31 + v19 - 80) = v32;
    v34 = data->unitwork;
    v35 = NewSpecific(sbyte, 6u);
    *(v34 + v19 - 56) = v35;
    v37 = data->unitwork;
    v38 = NewSpecific(sbyte, 6u);
    *(v37 + v19 - 48) = v38;
    v40 = data->unitwork;
    v41 = NewSpecific(ushort, 0x18u);
    *(v40 + v19 - 40) = v41;
    v43 = data->unitwork;
    v44 = NewSpecific(byte, 0x18u);
    *(v43 + v19 - 32) = v44;
    v46 = data->unitwork;
    v47 = NewSpecific(ushort, 4u);
    *(v46 + v19 - 16) = v47;
    v49 = data->unitwork;
    v50 = NewSpecific(char, 8u);
    *(&v49->obj.klass + v19) = v50;
    if (v19 == 2456)
      break;
    v17 = data->unitwork;
    ++v18;
    v19 += 152;
    if (v18 >= LODWORD(v17->max_length))
      goto LABEL_15;
  }
  data->stocklist = NewSpecific(s32, 0x10u);
  data->item = NewSpecific(byte, 0xA0u);
  data->boss_press00 = NewSpecific(s32, 2u);
  data->boss_press01 = NewSpecific(s32, 2u);
  data->boss_press02 = NewSpecific(s32, 2u);
  data->boss_press03 = NewSpecific(s32, 2u);
  data->boss_press04 = NewSpecific(s32, 2u);
  data->boss_press05 = NewSpecific(s32, 2u);
  data->boss_press06 = NewSpecific(s32, 2u);
  data->boss_press07 = NewSpecific(s32, 2u);
  data->boss_press08 = NewSpecific(s32, 2u);
  data->boss_press09 = NewSpecific(s32, 2u);
  data->boss_press10 = NewSpecific(s32, 2u);
  data->boss_press11 = NewSpecific(s32, 2u);
  data->boss_press12 = NewSpecific(s32, 2u);
  data->boss_press13 = NewSpecific(s32, 2u);
  data->boss_press14 = NewSpecific(s32, 2u);
  data->boss_press15 = NewSpecific(s32, 2u);
  data->boss_press16 = NewSpecific(s32, 2u);
  data->boss_press17 = NewSpecific(s32, 2u);
  data->boss_press18 = NewSpecific(s32, 2u);
  data->boss_press19 = NewSpecific(s32, 2u);
  data->boss_press20 = NewSpecific(s32, 2u);
  data->boss_press21 = NewSpecific(s32, 2u);
  data->boss_press22 = NewSpecific(s32, 2u);
  data->boss_press23 = NewSpecific(s32, 2u);
  data->boss_press24 = NewSpecific(s32, 2u);
  data->boss_press25 = NewSpecific(s32, 2u);
  data->boss_press26 = NewSpecific(s32, 2u);
  data->boss_press27 = NewSpecific(s32, 2u);
  data->boss_press28 = NewSpecific(s32, 2u);
  data->boss_press29 = NewSpecific(s32, 2u);
  data->boss_press30 = NewSpecific(s32, 2u);
  data->boss_press31 = NewSpecific(s32, 2u);
  data->boss_press32 = NewSpecific(s32, 2u);
  data->boss_press33 = NewSpecific(s32, 2u);
  data->boss_press34 = NewSpecific(s32, 2u);
  data->boss_press35 = NewSpecific(s32, 2u);
  data->boss_press36 = NewSpecific(s32, 2u);
  data->boss_press37 = NewSpecific(s32, 2u);
  data->boss_press38 = NewSpecific(s32, 2u);
  data->boss_press39 = NewSpecific(s32, 2u);
  data->syakkincnt = NewSpecific(byte, 0x40u);
  data->negoques = NewSpecific(byte, 4u);
  data->kotowari = NewSpecific(byte, 4u);
  data->hearts = NewSpecific(byte, 0x40u);
  data->heartsskcnt = NewSpecific(byte, 0x40u);
  data->name_nums00 = NewSpecific(byte, 2u);
  data->name_nums01 = NewSpecific(byte, 2u);
  data->name_nums02 = NewSpecific(byte, 2u);
  data->name_nums03 = NewSpecific(byte, 2u);
  data->name_code00 = NewSpecific(byte, 0x10u);
  data->name_code01 = NewSpecific(byte, 0x10u);
  data->name_code02 = NewSpecific(byte, 0x10u);
  data->name_code03 = NewSpecific(byte, 0x10u);
  data->cname_code00 = NewSpecific(byte, 0x10u);
  data->cname_code01 = NewSpecific(byte, 0x10u);
  data->cname_code02 = NewSpecific(byte, 0x10u);
  data->cname_code03 = NewSpecific(byte, 0x10u);
  data->cname_nums = NewSpecific(byte, 4u);
  v52 = memset(&data->fldSave, 0, sizeof(data->fldSave));
  initPushBlock(v52, &data->fldSave.PushBlock00);
  initPushBlock(v54, &data->fldSave.PushBlock01);
  initPushBlock(v56, &data->fldSave.PushBlock02);
  initPushBlock(v58, &data->fldSave.PushBlock03);
  initPushBlock(v60, &data->fldSave.PushBlock04);
  initPushBlock(v62, &data->fldSave.PushBlock05);
  initPushBlock(v64, &data->fldSave.PushBlock06);
  initPushBlock(v66, &data->fldSave.PushBlock07);
  initPushBlock(v68, &data->fldSave.PushBlock08);
  initPushBlock(v70, &data->fldSave.PushBlock09);
  initPushBlock(v72, &data->fldSave.PushBlock10);
  initPushBlock(v74, &data->fldSave.PushBlock11);
  initPushBlock(v76, &data->fldSave.PushBlock12);
  initPushBlock(v78, &data->fldSave.PushBlock13);
  initPushBlock(v80, &data->fldSave.PushBlock14);
  initPushBlock(v82, &data->fldSave.PushBlock15);
  initPushBlock(v84, &data->fldSave.PushBlock16);
  initPushBlock(v86, &data->fldSave.PushBlock17);
  initPushBlock(v88, &data->fldSave.PushBlock18);
  initPushBlock(v90, &data->fldSave.PushBlock19);
  initPushBlock(v92, &data->fldSave.PushBlock20);
  initPushBlock(v94, &data->fldSave.PushBlock21);
  initPushBlock(v96, &data->fldSave.PushBlock22);
  initPushBlock(v98, &data->fldSave.PushBlock23);
  initPushBlock(v100, &data->fldSave.PushBlock24);
  initPushBlock(v102, &data->fldSave.PushBlock25);
  initPushBlock(v104, &data->fldSave.PushBlock26);
  initPushBlock(v106, &data->fldSave.PushBlock27);
  initPushBlock(v108, &data->fldSave.PushBlock28);
  initPushBlock(v110, &data->fldSave.PushBlock29);
  initPushBlock(v112, &data->fldSave.PushBlock30);
  initPushBlock(v114, &data->fldSave.PushBlock31);
  initPushBlock(v116, &data->fldSave.PushBlock32);
  initPushBlock(v118, &data->fldSave.PushBlock33);
  initPushBlock(v120, &data->fldSave.PushBlock34);
  initPushBlock(v122, &data->fldSave.PushBlock35);
  initPushBlock(v124, &data->fldSave.PushBlock36);
  initPushBlock(v126, &data->fldSave.PushBlock37);
  initPushBlock(v128, &data->fldSave.PushBlock38);
  initPushBlock(v130, &data->fldSave.PushBlock39);
  data->fldSave.amap.blkOpenFlg29 = 0;
  data->fldSave.amap.blkOpenFlg28 = 0;
  data->fldSave.amap.blkOpenFlg27 = 0;
  data->fldSave.amap.blkOpenFlg26 = 0;
  data->fldSave.amap.blkOpenFlg25 = 0;
  data->fldSave.amap.blkOpenFlg24 = 0;
  data->fldSave.amap.blkOpenFlg23 = 0;
  data->fldSave.amap.blkOpenFlg22 = 0;
  data->fldSave.amap.blkOpenFlg21 = 0;
  data->fldSave.amap.blkOpenFlg20 = 0;
  data->fldSave.amap.blkOpenFlg19 = 0;
  data->fldSave.amap.blkOpenFlg18 = 0;
  data->fldSave.amap.blkOpenFlg17 = 0;
  data->fldSave.amap.blkOpenFlg16 = 0;
  data->fldSave.amap.blkOpenFlg15 = 0;
  data->fldSave.amap.blkOpenFlg14 = 0;
  data->fldSave.amap.blkOpenFlg13 = 0;
  data->fldSave.amap.blkOpenFlg12 = 0;
  data->fldSave.amap.blkOpenFlg11 = 0;
  data->fldSave.amap.blkOpenFlg10 = 0;
  data->fldSave.amap.blkOpenFlg09 = 0;
  data->fldSave.amap.blkOpenFlg08 = 0;
  data->fldSave.amap.blkOpenFlg07 = 0;
  data->fldSave.amap.blkOpenFlg06 = 0;
  data->fldSave.amap.blkOpenFlg05 = 0;
  data->fldSave.amap.blkOpenFlg04 = 0;
  data->fldSave.amap.blkOpenFlg03 = 0;
  data->fldSave.amap.blkOpenFlg02 = 0;
  data->fldSave.amap.blkOpenFlg01 = 0;
  data->fldSave.amap.blkOpenFlg00 = 0;
  data->fldSave.amap.blkOpenFlg00 = NewSpecific(uint, 0x20u);
  data->fldSave.amap.blkOpenFlg01 = NewSpecific(uint, 0x20u);
  data->fldSave.amap.blkOpenFlg02 = NewSpecific(uint, 0x20u);
  data->fldSave.amap.blkOpenFlg03 = NewSpecific(uint, 0x20u);
  data->fldSave.amap.blkOpenFlg04 = NewSpecific(uint, 0x20u);
  data->fldSave.amap.blkOpenFlg05 = NewSpecific(uint, 0x20u);
  data->fldSave.amap.blkOpenFlg06 = NewSpecific(uint, 0x20u);
  data->fldSave.amap.blkOpenFlg07 = NewSpecific(uint, 0x20u);
  data->fldSave.amap.blkOpenFlg08 = NewSpecific(uint, 0x20u);
  data->fldSave.amap.blkOpenFlg09 = NewSpecific(uint, 0x20u);
  data->fldSave.amap.blkOpenFlg10 = NewSpecific(uint, 0x20u);
  data->fldSave.amap.blkOpenFlg11 = NewSpecific(uint, 0x20u);
  data->fldSave.amap.blkOpenFlg12 = NewSpecific(uint, 0x20u);
  data->fldSave.amap.blkOpenFlg13 = NewSpecific(uint, 0x20u);
  data->fldSave.amap.blkOpenFlg14 = NewSpecific(uint, 0x20u);
  data->fldSave.amap.blkOpenFlg15 = NewSpecific(uint, 0x20u);
  data->fldSave.amap.blkOpenFlg16 = NewSpecific(uint, 0x20u);
  data->fldSave.amap.blkOpenFlg17 = NewSpecific(uint, 0x20u);
  data->fldSave.amap.blkOpenFlg18 = NewSpecific(uint, 0x20u);
  data->fldSave.amap.blkOpenFlg19 = NewSpecific(uint, 0x20u);
  data->fldSave.amap.blkOpenFlg20 = NewSpecific(uint, 0x20u);
  data->fldSave.amap.blkOpenFlg21 = NewSpecific(uint, 0x20u);
  data->fldSave.amap.blkOpenFlg22 = NewSpecific(uint, 0x20u);
  data->fldSave.amap.blkOpenFlg23 = NewSpecific(uint, 0x20u);
  data->fldSave.amap.blkOpenFlg24 = NewSpecific(uint, 0x20u);
  data->fldSave.amap.blkOpenFlg25 = NewSpecific(uint, 0x20u);
  data->fldSave.amap.blkOpenFlg26 = NewSpecific(uint, 0x20u);
  data->fldSave.amap.blkOpenFlg27 = NewSpecific(uint, 0x20u);
  data->fldSave.amap.blkOpenFlg28 = NewSpecific(uint, 0x20u);
  data->fldSave.amap.blkOpenFlg29 = NewSpecific(uint, 0x20u);
  data->fldSave.takara = NewSpecific(byte, 0x20u);
  data->fldSave.takara2 = NewSpecific(byte, 0xCu);
  data->fldSave.pub = NewSpecific(s32, 0xBu);
  data->config_data = NewSpecific(s32, 0xEu);
  data->hearts_sk00 = NewSpecific(ushort, 0xCu);
  data->hearts_sk01 = NewSpecific(ushort, 0xCu);
  data->hearts_sk02 = NewSpecific(ushort, 0xCu);
  data->hearts_sk03 = NewSpecific(ushort, 0xCu);
  data->hearts_sk04 = NewSpecific(ushort, 0xCu);
  data->hearts_sk05 = NewSpecific(ushort, 0xCu);
  data->hearts_sk06 = NewSpecific(ushort, 0xCu);
  data->hearts_sk07 = NewSpecific(ushort, 0xCu);
  data->hearts_sk08 = NewSpecific(ushort, 0xCu);
  data->hearts_sk09 = NewSpecific(ushort, 0xCu);
  data->hearts_sk10 = NewSpecific(ushort, 0xCu);
  data->hearts_sk11 = NewSpecific(ushort, 0xCu);
  data->hearts_sk12 = NewSpecific(ushort, 0xCu);
  data->hearts_sk13 = NewSpecific(ushort, 0xCu);
  data->hearts_sk14 = NewSpecific(ushort, 0xCu);
  data->hearts_sk15 = NewSpecific(ushort, 0xCu);
  data->hearts_sk16 = NewSpecific(ushort, 0xCu);
  data->hearts_sk17 = NewSpecific(ushort, 0xCu);
  data->hearts_sk18 = NewSpecific(ushort, 0xCu);
  data->hearts_sk19 = NewSpecific(ushort, 0xCu);
  data->hearts_sk20 = NewSpecific(ushort, 0xCu);
  data->hearts_sk21 = NewSpecific(ushort, 0xCu);
  data->hearts_sk22 = NewSpecific(ushort, 0xCu);
  data->hearts_sk23 = NewSpecific(ushort, 0xCu);
  data->hearts_sk24 = NewSpecific(ushort, 0xCu);
  data->hearts_sk25 = NewSpecific(ushort, 0xCu);
  data->hearts_sk26 = NewSpecific(ushort, 0xCu);
  data->hearts_sk27 = NewSpecific(ushort, 0xCu);
  data->hearts_sk28 = NewSpecific(ushort, 0xCu);
  data->hearts_sk29 = NewSpecific(ushort, 0xCu);
  data->hearts_sk30 = NewSpecific(ushort, 0xCu);
  data->hearts_sk31 = NewSpecific(ushort, 0xCu);
  data->hearts_up_param00 = NewSpecific(sbyte, 6u);
  data->hearts_up_param01 = NewSpecific(sbyte, 6u);
  data->hearts_up_param02 = NewSpecific(sbyte, 6u);
  data->hearts_up_param03 = NewSpecific(sbyte, 6u);
  data->hearts_up_param04 = NewSpecific(sbyte, 6u);
  data->hearts_up_param05 = NewSpecific(sbyte, 6u);
  data->hearts_up_param06 = NewSpecific(sbyte, 6u);
  data->hearts_up_param07 = NewSpecific(sbyte, 6u);
  data->hearts_up_param08 = NewSpecific(sbyte, 6u);
  data->hearts_up_param09 = NewSpecific(sbyte, 6u);
  data->hearts_up_param10 = NewSpecific(sbyte, 6u);
  data->hearts_up_param11 = NewSpecific(sbyte, 6u);
  data->hearts_up_param12 = NewSpecific(sbyte, 6u);
  data->hearts_up_param13 = NewSpecific(sbyte, 6u);
  data->hearts_up_param14 = NewSpecific(sbyte, 6u);
  data->hearts_up_param15 = NewSpecific(sbyte, 6u);
  data->hearts_up_param16 = NewSpecific(sbyte, 6u);
  data->hearts_up_param17 = NewSpecific(sbyte, 6u);
  data->hearts_up_param18 = NewSpecific(sbyte, 6u);
  data->hearts_up_param19 = NewSpecific(sbyte, 6u);
  data->hearts_up_param20 = NewSpecific(sbyte, 6u);
  data->hearts_up_param21 = NewSpecific(sbyte, 6u);
  data->hearts_up_param22 = NewSpecific(sbyte, 6u);
  data->hearts_up_param23 = NewSpecific(sbyte, 6u);
  data->hearts_up_param24 = NewSpecific(sbyte, 6u);
  data->hearts_up_param25 = NewSpecific(sbyte, 6u);
  data->hearts_up_param26 = NewSpecific(sbyte, 6u);
  data->hearts_up_param27 = NewSpecific(sbyte, 6u);
  data->hearts_up_param28 = NewSpecific(sbyte, 6u);
  data->hearts_up_param29 = NewSpecific(sbyte, 6u);
  data->hearts_up_param30 = NewSpecific(sbyte, 6u);
  data->hearts_up_param31 = NewSpecific(sbyte, 6u);
  data->encyc_record.pelem = 0;
  *&data->encyc_record.reserved1 = 0;
  *&data->encyc_record.num = 0;
  v132 = NewSpecific(SAVEDATA_fclencyceelem_tag, 0xB8u);
  v133 = 0;
  v134 = -17568;
  data->encyc_record.pelem = v132;
  while (1)
  {
    v135 = NewSpecific(sbyte, 6u);
    *(&v132->m_Items[183].param + v134) = v135;
    pelem = data->encyc_record.pelem;
    v138 = NewSpecific(sbyte, 6u);
    *(&pelem->m_Items[183].skillparam + v134) = v138;
    v140 = data->encyc_record.pelem;
    v141 = NewSpecific(ushort, 0x18u);
    *(&v140->m_Items[183].skill + v134) = v141;
    v143 = data->encyc_record.pelem;
    v144 = NewSpecific(sbyte, 6u);
    *(&v143->m_Items[183].mitamaparam + v134) = v144;
    v146 = data->encyc_record.pelem;
    v147 = NewSpecific(sbyte, 6u);
    *(&v146->m_Items[183].levelupparam + v134) = v147;
    v149 = data->encyc_record.pelem;
    v150 = NewSpecific(ushort, 0x18u);
    *(&v149->m_Items[183].keisyoskill + v134) = v150;
    v152 = data->encyc_record.pelem;
    v153 = NewSpecific(byte, 0x18u);
    *(&v152->m_Items[183].keiattr + v134) = v153;
    if (!v134)
      break;
    v132 = data->encyc_record.pelem;
    ++v133;
    v134 += 96;
  }
  data->amap31.blkOpenFlg07 = 0;
  data->amap31.blkOpenFlg06 = 0;
  data->amap31.blkOpenFlg05 = 0;
  data->amap31.blkOpenFlg04 = 0;
  data->amap31.blkOpenFlg03 = 0;
  data->amap31.blkOpenFlg02 = 0;
  data->amap31.blkOpenFlg01 = 0;
  data->amap31.blkOpenFlg00 = 0;
  data->amap31.blkOpenFlg00 = NewSpecific(uint, 0x20u);
  data->amap31.blkOpenFlg01 = NewSpecific(uint, 0x20u);
  data->amap31.blkOpenFlg02 = NewSpecific(uint, 0x20u);
  data->amap31.blkOpenFlg03 = NewSpecific(uint, 0x20u);
  data->amap31.blkOpenFlg04 = NewSpecific(uint, 0x20u);
  data->amap31.blkOpenFlg05 = NewSpecific(uint, 0x20u);
  data->amap31.blkOpenFlg06 = NewSpecific(uint, 0x20u);
  data->amap31.blkOpenFlg07 = NewSpecific(uint, 0x20u);
  data->amapEX.blkOpenFlg01 = 0;
  data->amapEX.blkOpenFlg00 = 0;
  data->amapEX.blkOpenFlg00 = NewSpecific(uint, 0x20u);
  data->amapEX.blkOpenFlg01 = NewSpecific(uint, 0x20u);
  dataVer7->amap.blkOpenFlg28 = 0;
  dataVer7->amap.blkOpenFlg29 = 0;
  dataVer7->amap.blkOpenFlg26 = 0;
  dataVer7->amap.blkOpenFlg27 = 0;
  dataVer7->amap.blkOpenFlg24 = 0;
  dataVer7->amap.blkOpenFlg25 = 0;
  dataVer7->amap.blkOpenFlg22 = 0;
  dataVer7->amap.blkOpenFlg23 = 0;
  dataVer7->amap.blkOpenFlg20 = 0;
  dataVer7->amap.blkOpenFlg21 = 0;
  dataVer7->amap.blkOpenFlg18 = 0;
  dataVer7->amap.blkOpenFlg19 = 0;
  dataVer7->amap.blkOpenFlg16 = 0;
  dataVer7->amap.blkOpenFlg17 = 0;
  dataVer7->amap.blkOpenFlg14 = 0;
  dataVer7->amap.blkOpenFlg15 = 0;
  dataVer7->amap.blkOpenFlg12 = 0;
  dataVer7->amap.blkOpenFlg13 = 0;
  dataVer7->amap.blkOpenFlg10 = 0;
  dataVer7->amap.blkOpenFlg11 = 0;
  dataVer7->amap.blkOpenFlg08 = 0;
  dataVer7->amap.blkOpenFlg09 = 0;
  dataVer7->amap.blkOpenFlg06 = 0;
  dataVer7->amap.blkOpenFlg07 = 0;
  dataVer7->amap.blkOpenFlg04 = 0;
  dataVer7->amap.blkOpenFlg05 = 0;
  dataVer7->amap.blkOpenFlg02 = 0;
  dataVer7->amap.blkOpenFlg03 = 0;
  dataVer7->amap.blkOpenFlg00 = 0;
  dataVer7->amap.blkOpenFlg01 = 0;
  dataVer7->amap.blkOpenFlg00 = NewSpecific(uint, 0x20u);
  dataVer7->amap.blkOpenFlg01 = NewSpecific(uint, 0x20u);
  dataVer7->amap.blkOpenFlg02 = NewSpecific(uint, 0x20u);
  dataVer7->amap.blkOpenFlg03 = NewSpecific(uint, 0x20u);
  dataVer7->amap.blkOpenFlg04 = NewSpecific(uint, 0x20u);
  dataVer7->amap.blkOpenFlg05 = NewSpecific(uint, 0x20u);
  dataVer7->amap.blkOpenFlg06 = NewSpecific(uint, 0x20u);
  dataVer7->amap.blkOpenFlg07 = NewSpecific(uint, 0x20u);
  dataVer7->amap.blkOpenFlg08 = NewSpecific(uint, 0x20u);
  dataVer7->amap.blkOpenFlg09 = NewSpecific(uint, 0x20u);
  dataVer7->amap.blkOpenFlg10 = NewSpecific(uint, 0x20u);
  dataVer7->amap.blkOpenFlg11 = NewSpecific(uint, 0x20u);
  dataVer7->amap.blkOpenFlg12 = NewSpecific(uint, 0x20u);
  dataVer7->amap.blkOpenFlg13 = NewSpecific(uint, 0x20u);
  dataVer7->amap.blkOpenFlg14 = NewSpecific(uint, 0x20u);
  dataVer7->amap.blkOpenFlg15 = NewSpecific(uint, 0x20u);
  dataVer7->amap.blkOpenFlg16 = NewSpecific(uint, 0x20u);
  dataVer7->amap.blkOpenFlg17 = NewSpecific(uint, 0x20u);
  dataVer7->amap.blkOpenFlg18 = NewSpecific(uint, 0x20u);
  dataVer7->amap.blkOpenFlg19 = NewSpecific(uint, 0x20u);
  dataVer7->amap.blkOpenFlg20 = NewSpecific(uint, 0x20u);
  dataVer7->amap.blkOpenFlg21 = NewSpecific(uint, 0x20u);
  dataVer7->amap.blkOpenFlg22 = NewSpecific(uint, 0x20u);
  dataVer7->amap.blkOpenFlg23 = NewSpecific(uint, 0x20u);
  dataVer7->amap.blkOpenFlg24 = NewSpecific(uint, 0x20u);
  dataVer7->amap.blkOpenFlg25 = NewSpecific(uint, 0x20u);
  dataVer7->amap.blkOpenFlg26 = NewSpecific(uint, 0x20u);
  dataVer7->amap.blkOpenFlg27 = NewSpecific(uint, 0x20u);
  dataVer7->amap.blkOpenFlg28 = NewSpecific(uint, 0x20u);
  v155 = NewSpecific(uint, 0x20u);
  dataVer7->amap31.blkOpenFlg06 = 0;
  dataVer7->amap31.blkOpenFlg07 = 0;
  dataVer7->amap31.blkOpenFlg04 = 0;
  dataVer7->amap31.blkOpenFlg05 = 0;
  dataVer7->amap.blkOpenFlg29 = v155;
  dataVer7->amap31.blkOpenFlg02 = 0;
  dataVer7->amap31.blkOpenFlg03 = 0;
  dataVer7->amap31.blkOpenFlg00 = 0;
  dataVer7->amap31.blkOpenFlg01 = 0;
  dataVer7->amap31.blkOpenFlg00 = NewSpecific(uint, 0x20u);
  dataVer7->amap31.blkOpenFlg01 = NewSpecific(uint, 0x20u);
  dataVer7->amap31.blkOpenFlg02 = NewSpecific(uint, 0x20u);
  dataVer7->amap31.blkOpenFlg03 = NewSpecific(uint, 0x20u);
  dataVer7->amap31.blkOpenFlg04 = NewSpecific(uint, 0x20u);
  dataVer7->amap31.blkOpenFlg05 = NewSpecific(uint, 0x20u);
  dataVer7->amap31.blkOpenFlg06 = NewSpecific(uint, 0x20u);
  v156 = NewSpecific(uint, 0x20u);
  dataVer7->amapEX.blkOpenFlg00 = 0;
  dataVer7->amapEX.blkOpenFlg01 = 0;
  dataVer7->amap31.blkOpenFlg07 = v156;
  dataVer7->amapEX.blkOpenFlg00 = NewSpecific(uint, 0x20u);
  v157 = NewSpecific(uint, 0x20u);
  *&dataVer7->dante_pelem.hensinmae = 0;
  *&dataVer7->dante_pelem.reserved2 = 0;
  dataVer7->dante_pelem.keisyoskill = 0;
  dataVer7->dante_pelem.keiattr = 0;
  dataVer7->amapEX.blkOpenFlg01 = v157;
  dataVer7->dante_pelem.mitamaparam = 0;
  dataVer7->dante_pelem.levelupparam = 0;
  *&dataVer7->dante_pelem.skillcnt = 0;
  dataVer7->dante_pelem.skill = 0;
  dataVer7->dante_pelem.param = 0;
  dataVer7->dante_pelem.skillparam = 0;
  *&dataVer7->dante_pelem.id = 0;
  *&dataVer7->dante_pelem.exp = 0;
  dataVer7->dante_pelem.param = NewSpecific(sbyte, 6u);
  dataVer7->dante_pelem.skillparam = NewSpecific(sbyte, 6u);
  dataVer7->dante_pelem.skill = NewSpecific(ushort, 0x18u);
  dataVer7->dante_pelem.mitamaparam = NewSpecific(sbyte, 6u);
  dataVer7->dante_pelem.levelupparam = NewSpecific(sbyte, 6u);
  dataVer7->dante_pelem.keisyoskill = NewSpecific(ushort, 0x18u);
  dataVer7->dante_pelem.keiattr = NewSpecific(byte, 0x18u);
  dataVer7->saveTime = 0;
  dataVer7->autoMapOpen = NewSpecific(sbyte, 0x24u);
  dataVer7->fldRunWork = NewSpecific(byte, 0x6Bu);
  dataVer7->autoMapOpenEX = NewSpecific(sbyte, 2u);
  dataVer7->reserved = NewSpecific(sbyte, 0x93u);
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
  if (!LODWORD(v4->max_length))
  {
LABEL_6:
  }
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
      goto LABEL_6;
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
  dds3GlobalWork_t_o *v8;
  s64 v9;
  s64 v10;
  struct System_String_o *cname_code;
  s64 v12;
  struct System_String_o *pad3;
  struct System_Char_array *end_list;
  SAVEDATA_o *v15;
  dds3GlobalWork_t_o *v17;
  struct evtMoon_t_o *Moon;
  u64 *v19;
  dds3GlobalWork_t_o *v20;
  u64 v21;
  struct SAVEDATA_datUnitWork_tag_array **p_unitwork;
  s64 v23;
  struct datUnitWork_t_array *unitwork;
  u32 *v27;
  u64 *v28;
  struct datUnitWork_t_array *v30;
  datUnitWork_t_o *v32;
  struct datUnitWork_t_array *v34;
  datUnitWork_t_o *v36;
  struct datUnitWork_t_array *v38;
  datUnitWork_t_o *v40;
  struct datUnitWork_t_array *v42;
  datUnitWork_t_o *v44;
  struct datUnitWork_t_array *v46;
  datUnitWork_t_o *v48;
  struct datUnitWork_t_array *v50;
  datUnitWork_t_o *v52;
  struct datUnitWork_t_array *v54;
  datUnitWork_t_o *v56;
  struct datUnitWork_t_array *v58;
  datUnitWork_t_o *v60;
  struct datUnitWork_t_array *v62;
  datUnitWork_t_o *v64;
  struct datUnitWork_t_array *v67;
  struct datUnitWork_t_array *v70;
  struct datUnitWork_t_array *v72;
  datUnitWork_t_o *v74;
  struct datUnitWork_t_array *v76;
  datUnitWork_t_o *v78;
  struct datUnitWork_t_array *v80;
  datUnitWork_t_o *v82;
  struct datUnitWork_t_array *v85;
  struct datUnitWork_t_array *v87;
  datUnitWork_t_o *v89;
  struct datUnitWork_t_array *v92;
  struct datUnitWork_t_array *v94;
  datUnitWork_t_o *v96;
  struct datUnitWork_t_array *v98;
  datUnitWork_t_o *v100;
  struct datUnitWork_t_array *v102;
  datUnitWork_t_o *v104;
  struct datUnitWork_t_array *v106;
  datUnitWork_t_o *v108;
  struct datUnitWork_t_array *v110;
  datUnitWork_t_o *v112;
  struct datUnitWork_t_array *v114;
  datUnitWork_t_o *v116;
  struct datUnitWork_t_array *v118;
  datUnitWork_t_o *v120;
  struct datUnitWork_t_array *v122;
  datUnitWork_t_o *v124;
  struct datUnitWork_t_array *v127;
  struct datUnitWork_t_array *v130;
  struct datUnitWork_t_array *v133;
  struct datUnitWork_t_array *v136;
  struct datUnitWork_t_array *v138;
  datUnitWork_t_o *v140;
  struct datUnitWork_t_array *v143;
  struct datUnitWork_t_array *v145;
  datUnitWork_t_o *v147;
  struct datUnitWork_t_array *v150;
  struct System_Int32_array_array *boss_press;
  struct System_Int32_array_array *v153;
  struct System_Int32_array_array *v155;
  struct System_Int32_array_array *v157;
  struct System_Int32_array_array *v159;
  struct System_Int32_array_array *v161;
  struct System_Int32_array_array *v163;
  struct System_Int32_array_array *v165;
  struct System_Int32_array_array *v167;
  struct System_Int32_array_array *v169;
  struct System_Int32_array_array *v171;
  struct System_Int32_array_array *v173;
  struct System_Int32_array_array *v175;
  struct System_Int32_array_array *v177;
  struct System_Int32_array_array *v179;
  struct System_Int32_array_array *v181;
  struct System_Int32_array_array *v183;
  struct System_Int32_array_array *v185;
  struct System_Int32_array_array *v187;
  struct System_Int32_array_array *v189;
  struct System_Int32_array_array *v191;
  struct System_Int32_array_array *v193;
  struct System_Int32_array_array *v195;
  struct System_Int32_array_array *v197;
  struct System_Int32_array_array *v199;
  struct System_Int32_array_array *v201;
  struct System_Int32_array_array *v203;
  struct System_Int32_array_array *v205;
  struct System_Int32_array_array *v207;
  struct System_Int32_array_array *v209;
  struct System_Int32_array_array *v211;
  struct System_Int32_array_array *v213;
  struct System_Int32_array_array *v215;
  struct System_Int32_array_array *v217;
  struct System_Int32_array_array *v219;
  struct System_Int32_array_array *v221;
  struct System_Int32_array_array *v223;
  struct System_Int32_array_array *v225;
  struct System_Int32_array_array *v227;
  struct System_Int32_array_array *v229;
  struct System_Byte_array_array *name_nums;
  struct System_Byte_array_array *v232;
  struct System_Byte_array_array *v234;
  struct System_Byte_array_array *v236;
  struct System_Byte_array_array *name_code;
  struct System_Byte_array_array *v239;
  struct System_Byte_array_array *v241;
  struct System_Byte_array_array *v243;
  struct System_Byte_array_array *v245;
  struct System_Byte_array_array *v246;
  struct System_Byte_array_array *v248;
  struct System_Byte_array_array *v250;
  SAVEDATA_o *v252;
  dds3GlobalWork_t_o *v254;
  struct fldSave_t_o *fldSave;
  struct fldBlockBuff_t_array_array *PushBlock;
  struct SAVEDATA_fldSave_tag_o *p_fldSave;
  SAVEDATA_o *v259;
  struct fldBlockBuff_t_array_array *v261;
  SAVEDATA_o *v263;
  struct fldBlockBuff_t_array_array *v265;
  SAVEDATA_o *v267;
  struct fldBlockBuff_t_array_array *v269;
  SAVEDATA_o *v271;
  struct fldBlockBuff_t_array_array *v273;
  SAVEDATA_o *v275;
  struct fldBlockBuff_t_array_array *v277;
  SAVEDATA_o *v279;
  struct fldBlockBuff_t_array_array *v281;
  SAVEDATA_o *v283;
  struct fldBlockBuff_t_array_array *v285;
  SAVEDATA_o *v287;
  struct fldBlockBuff_t_array_array *v289;
  SAVEDATA_o *v291;
  struct fldBlockBuff_t_array_array *v293;
  SAVEDATA_o *v295;
  struct fldBlockBuff_t_array_array *v297;
  SAVEDATA_o *v299;
  struct fldBlockBuff_t_array_array *v301;
  SAVEDATA_o *v303;
  struct fldBlockBuff_t_array_array *v305;
  SAVEDATA_o *v307;
  struct fldBlockBuff_t_array_array *v309;
  SAVEDATA_o *v311;
  struct fldBlockBuff_t_array_array *v313;
  SAVEDATA_o *v315;
  struct fldBlockBuff_t_array_array *v317;
  SAVEDATA_o *v319;
  struct fldBlockBuff_t_array_array *v321;
  SAVEDATA_o *v323;
  struct fldBlockBuff_t_array_array *v325;
  SAVEDATA_o *v327;
  struct fldBlockBuff_t_array_array *v329;
  SAVEDATA_o *v331;
  struct fldBlockBuff_t_array_array *v333;
  SAVEDATA_o *v335;
  struct fldBlockBuff_t_array_array *v337;
  SAVEDATA_o *v339;
  struct fldBlockBuff_t_array_array *v341;
  SAVEDATA_o *v343;
  struct fldBlockBuff_t_array_array *v345;
  SAVEDATA_o *v347;
  struct fldBlockBuff_t_array_array *v349;
  SAVEDATA_o *v351;
  struct fldBlockBuff_t_array_array *v353;
  SAVEDATA_o *v355;
  struct fldBlockBuff_t_array_array *v357;
  SAVEDATA_o *v359;
  struct fldBlockBuff_t_array_array *v361;
  SAVEDATA_o *v363;
  struct fldBlockBuff_t_array_array *v365;
  SAVEDATA_o *v367;
  struct fldBlockBuff_t_array_array *v369;
  SAVEDATA_o *v371;
  struct fldBlockBuff_t_array_array *v373;
  SAVEDATA_o *v375;
  struct fldBlockBuff_t_array_array *v377;
  SAVEDATA_o *v379;
  struct fldBlockBuff_t_array_array *v381;
  SAVEDATA_o *v383;
  struct fldBlockBuff_t_array_array *v385;
  SAVEDATA_o *v387;
  struct fldBlockBuff_t_array_array *v389;
  SAVEDATA_o *v391;
  struct fldBlockBuff_t_array_array *v393;
  SAVEDATA_o *v395;
  struct fldBlockBuff_t_array_array *v397;
  SAVEDATA_o *v399;
  struct fldBlockBuff_t_array_array *v401;
  SAVEDATA_o *v403;
  struct fldBlockBuff_t_array_array *v405;
  SAVEDATA_o *v407;
  struct fldBlockBuff_t_array_array *v409;
  SAVEDATA_o *v411;
  struct fldBlockBuff_t_array_array *v413;
  struct System_UInt32_array_array *blkOpenFlg;
  struct System_UInt32_array_array *v416;
  struct System_UInt32_array_array *v418;
  struct System_UInt32_array_array *v420;
  struct System_UInt32_array_array *v422;
  struct System_UInt32_array_array *v424;
  struct System_UInt32_array_array *v426;
  struct System_UInt32_array_array *v428;
  struct System_UInt32_array_array *v430;
  struct System_UInt32_array_array *v432;
  struct System_UInt32_array_array *v434;
  struct System_UInt32_array_array *v436;
  struct System_UInt32_array_array *v438;
  struct System_UInt32_array_array *v440;
  struct System_UInt32_array_array *v442;
  struct System_UInt32_array_array *v444;
  struct System_UInt32_array_array *v446;
  struct System_UInt32_array_array *v448;
  struct System_UInt32_array_array *v450;
  struct System_UInt32_array_array *v452;
  struct System_UInt32_array_array *v454;
  struct System_UInt32_array_array *v456;
  struct System_UInt32_array_array *v458;
  struct System_UInt32_array_array *v460;
  struct System_UInt32_array_array *v462;
  struct System_UInt32_array_array *v464;
  struct System_UInt32_array_array *v466;
  struct System_UInt32_array_array *v468;
  struct System_UInt32_array_array *v470;
  struct System_UInt32_array_array *v472;
  struct System_Byte_array *takara;
  struct System_Byte_array *takara2;
  struct System_Int32_array *pub;
  struct System_UInt16_array_array *hearts_sk;
  struct System_UInt16_array_array *v478;
  struct System_UInt16_array_array *v480;
  struct System_UInt16_array_array *v482;
  struct System_UInt16_array_array *v484;
  struct System_UInt16_array_array *v486;
  struct System_UInt16_array_array *v488;
  struct System_UInt16_array_array *v490;
  struct System_UInt16_array_array *v492;
  struct System_UInt16_array_array *v494;
  struct System_UInt16_array_array *v496;
  struct System_UInt16_array_array *v498;
  struct System_UInt16_array_array *v500;
  struct System_UInt16_array_array *v502;
  struct System_UInt16_array_array *v504;
  struct System_UInt16_array_array *v506;
  struct System_UInt16_array_array *v508;
  struct System_UInt16_array_array *v510;
  struct System_UInt16_array_array *v512;
  struct System_UInt16_array_array *v514;
  struct System_UInt16_array_array *v516;
  struct System_UInt16_array_array *v518;
  struct System_UInt16_array_array *v520;
  struct System_UInt16_array_array *v522;
  struct System_UInt16_array_array *v524;
  struct System_UInt16_array_array *v526;
  struct System_UInt16_array_array *v528;
  struct System_UInt16_array_array *v530;
  struct System_UInt16_array_array *v532;
  struct System_UInt16_array_array *v534;
  struct System_UInt16_array_array *v536;
  struct System_UInt16_array_array *v538;
  struct System_SByte_array_array *hearts_up_param;
  struct System_SByte_array_array *v541;
  struct System_SByte_array_array *v543;
  struct System_SByte_array_array *v545;
  struct System_SByte_array_array *v547;
  struct System_SByte_array_array *v549;
  struct System_SByte_array_array *v551;
  struct System_SByte_array_array *v553;
  struct System_SByte_array_array *v555;
  struct System_SByte_array_array *v557;
  struct System_SByte_array_array *v559;
  struct System_SByte_array_array *v561;
  struct System_SByte_array_array *v563;
  struct System_SByte_array_array *v565;
  struct System_SByte_array_array *v567;
  struct System_SByte_array_array *v569;
  struct System_SByte_array_array *v571;
  struct System_SByte_array_array *v573;
  struct System_SByte_array_array *v575;
  struct System_SByte_array_array *v577;
  struct System_SByte_array_array *v579;
  struct System_SByte_array_array *v581;
  struct System_SByte_array_array *v583;
  struct System_SByte_array_array *v585;
  struct System_SByte_array_array *v587;
  struct System_SByte_array_array *v589;
  struct System_SByte_array_array *v591;
  struct System_SByte_array_array *v593;
  struct System_SByte_array_array *v595;
  struct System_SByte_array_array *v597;
  struct System_SByte_array_array *v599;
  struct System_SByte_array_array *v601;
  dds3GlobalWork_t_o *v603;
  struct fclEncycRecord_t_o *encyc_record;
  u64 *v605;
  dds3GlobalWork_t_o *v606;
  struct fclEncycRecord_t_o *v607;
  u64 v608;
  s64 v609;
  struct fclencyceelem_t_array *pelem;
  u32 *v613;
  u64 *v614;
  struct fclencyceelem_t_array *v616;
  struct SAVEDATA_fclencyceelem_tag_array *v618;
  fclencyceelem_t_o *v619;
  struct fclencyceelem_t_array *v621;
  struct SAVEDATA_fclencyceelem_tag_array *v623;
  fclencyceelem_t_o *v624;
  struct fclencyceelem_t_array *v626;
  struct SAVEDATA_fclencyceelem_tag_array *v628;
  fclencyceelem_t_o *v629;
  struct fclencyceelem_t_array *v631;
  struct SAVEDATA_fclencyceelem_tag_array *v633;
  fclencyceelem_t_o *v634;
  struct fclencyceelem_t_array *v636;
  struct SAVEDATA_fclencyceelem_tag_array *v638;
  fclencyceelem_t_o *v639;
  struct fclencyceelem_t_array *v641;
  struct SAVEDATA_fclencyceelem_tag_array *v643;
  fclencyceelem_t_o *v644;
  struct SAVEDATA_fclencyceelem_tag_array *v646;
  System_Array_o *v648;
  struct fclencyceelem_t_array *v649;
  struct SAVEDATA_fclencyceelem_tag_array *v651;
  System_Array_o *v653;
  struct fclencyceelem_t_array *v654;
  struct fclencyceelem_t_array *v656;
  struct SAVEDATA_fclencyceelem_tag_array *v658;
  fclencyceelem_t_o *v659;
  struct SAVEDATA_fclencyceelem_tag_array *v661;
  System_Array_o *v663;
  struct fclencyceelem_t_array *v664;
  struct SAVEDATA_fclencyceelem_tag_array *v666;
  System_Array_o *v668;
  struct fclencyceelem_t_array *v669;
  struct SAVEDATA_fclencyceelem_tag_array *v671;
  System_Array_o *v673;
  struct fclencyceelem_t_array *v674;
  struct SAVEDATA_fclencyceelem_tag_array *v676;
  System_Array_o *v678;
  struct fclencyceelem_t_array *v679;
  struct SAVEDATA_fclencyceelem_tag_array *v681;
  System_Array_o *v683;
  struct fclencyceelem_t_array *v684;
  struct fclencyceelem_t_array *v686;
  struct SAVEDATA_fclencyceelem_tag_array *v688;
  fclencyceelem_t_o *v689;
  struct fclencyceelem_t_array *v691;
  struct SAVEDATA_fclencyceelem_tag_array *v693;
  fclencyceelem_t_o *v694;
  struct fclencyceelem_t_array *v696;
  struct SAVEDATA_fclencyceelem_tag_array *v698;
  fclencyceelem_t_o *v699;
  struct fclencyceelem_t_array *v701;
  struct SAVEDATA_fclencyceelem_tag_array *v703;
  fclencyceelem_t_o *v704;
  struct fclencyceelem_t_array *v706;
  struct SAVEDATA_fclencyceelem_tag_array *v708;
  fclencyceelem_t_o *v709;
  struct fldAutoMapBuff31_t_o *amap31;
  u64 *v712;
  struct System_UInt32_array_array *v713;
  struct System_UInt32_array_array *v714;
  struct System_UInt32_array_array *v716;
  struct System_UInt32_array_array *v718;
  struct System_UInt32_array_array *v720;
  struct System_UInt32_array_array *v722;
  struct System_UInt32_array_array *v724;
  struct System_UInt32_array_array *v726;
  dds3GlobalWork_t_o *v728;
  struct fldAutoMapBuffEX_t_o *amapEX;
  u64 *v730;
  struct System_UInt32_array_array *v731;
  struct System_UInt32_array_array *v732;
  System_Array_o *blkOpenFlg01;
  dds3GlobalWork_t_o *v735;
  struct fldAutoMapBuff_t_o *amap_Ver7;
  u64 *v737;
  struct System_UInt32_array_array *v738;
  struct System_UInt32_array_array *v739;
  struct System_UInt32_array_array *v741;
  struct System_UInt32_array_array *v743;
  struct System_UInt32_array_array *v745;
  struct System_UInt32_array_array *v747;
  struct System_UInt32_array_array *v749;
  struct System_UInt32_array_array *v751;
  struct System_UInt32_array_array *v753;
  struct System_UInt32_array_array *v755;
  struct System_UInt32_array_array *v757;
  struct System_UInt32_array_array *v759;
  struct System_UInt32_array_array *v761;
  struct System_UInt32_array_array *v763;
  struct System_UInt32_array_array *v765;
  struct System_UInt32_array_array *v767;
  struct System_UInt32_array_array *v769;
  struct System_UInt32_array_array *v771;
  struct System_UInt32_array_array *v773;
  struct System_UInt32_array_array *v775;
  struct System_UInt32_array_array *v777;
  struct System_UInt32_array_array *v779;
  struct System_UInt32_array_array *v781;
  struct System_UInt32_array_array *v783;
  struct System_UInt32_array_array *v785;
  struct System_UInt32_array_array *v787;
  struct System_UInt32_array_array *v789;
  struct System_UInt32_array_array *v791;
  struct System_UInt32_array_array *v793;
  struct System_UInt32_array_array *v795;
  dds3GlobalWork_t_o *v797;
  struct fldAutoMapBuff31_t_o *amap31_Ver7;
  u64 *v799;
  struct System_UInt32_array_array *v800;
  struct System_UInt32_array_array *v801;
  struct System_UInt32_array_array *v803;
  struct System_UInt32_array_array *v805;
  struct System_UInt32_array_array *v807;
  struct System_UInt32_array_array *v809;
  struct System_UInt32_array_array *v811;
  struct System_UInt32_array_array *v813;
  dds3GlobalWork_t_o *v815;
  struct fldAutoMapBuffEX_t_o *amapEX_Ver7;
  u64 *v817;
  struct System_UInt32_array_array *v818;
  struct System_UInt32_array_array *v819;
  struct fclencyceelem_t_array *v821;
  struct fclencyceelem_t_array *v823;
  u64 *v824;
  struct fclencyceelem_t_array *v826;
  struct fclencyceelem_t_array *v828;
  struct fclencyceelem_t_array *v830;
  struct fclencyceelem_t_array *v832;
  struct fclencyceelem_t_array *v834;
  struct fclencyceelem_t_array *v836;
  struct fclencyceelem_t_array *v838;
  struct fclencyceelem_t_array *v840;
  struct fclencyceelem_t_array *v842;
  struct fclencyceelem_t_array *v844;
  struct fclencyceelem_t_array *v846;
  struct fclencyceelem_t_array *v848;
  struct fclencyceelem_t_array *v850;
  struct fclencyceelem_t_array *v852;
  struct fclencyceelem_t_array *v854;
  struct fclencyceelem_t_array *v856;
  struct fclencyceelem_t_array *v858;
  struct fclencyceelem_t_array *v860;
  struct fclencyceelem_t_array *v862;
  struct System_SByte_array *autoMapOpen;
  struct System_SByte_array *autoMapOpenEX;
  u64 *v870;
  SAVEDATA_dds3WorkVer7_tag_o dest;
  SAVEDATA_GameFileInfo_tag_o v881;

  v8 = *data;
  if (!*data)
  {
    v8 = Allocate(dds3GlobalWork_t);
    dds3GlobalWork_t___ctor(v8);
    *data = v8;
  }
  v881.verstr = loadData->GameFileInfo.verstr;
  v9 = *&loadData->GameFileInfo.ver;
  v10 = *&loadData->GameFileInfo.mode;
  cname_code = loadData->GameFileInfo.cname_code;
  *&v881.endcnt = *&loadData->GameFileInfo.endcnt;
  v881.cname_code = cname_code;
  *&v881.ver = v9;
  *&v881.mode = v10;
  v12 = *&loadData->GameFileInfo.cname_nums;
  pad3 = loadData->GameFileInfo.pad3;
  end_list = loadData->GameFileInfo.end_list;
  *&v881.dante_mode = *&loadData->GameFileInfo.dante_mode;
  v881.end_list = end_list;
  *&v881.cname_nums = v12;
  v881.pad3 = pad3;
  v15 = memcpy(&dest, loadDataVer7, sizeof(dest));
  restoreGameFileInfo(v15, &v881, &v8->GameFileInfo, &dest);
  (*data)->runtime = loadData->runtime;
  (*data)->playtime = loadData->playtime;
  Copy_3886320(
    loadData->IntVariable,
    (*data)->IntVariable,
    (*data)->IntVariable->max_length,
    0);
  Copy_3886320(
    loadData->FloatVariable,
    (*data)->FloatVariable,
    (*data)->FloatVariable->max_length,
    0);
  Copy_3886320(
    loadData->EventBit,
    (*data)->EventBit,
    (*data)->EventBit->max_length,
    0);
  v17 = *data;
  Moon = (*data)->Moon;
  if (!Moon)
  {
    v19 = Allocate(evtMoon_t);
    evtMoon_t___ctor(v19);
    v17->Moon = v19;
    Moon = (*data)->Moon;
  }
  Moon->Stat = loadData->Moon.Stat;
  (*data)->Moon->Age = loadData->Moon.Age;
  (*data)->Moon->TakaraCnt = loadData->Moon.TakaraCnt;
  (*data)->Moon->pub = loadData->Moon.pub;
  (*data)->Moon->MoveCnt = loadData->Moon.MoveCnt;
  (*data)->maka = loadData->maka;
  (*data)->stat = loadData->stat;
  (*data)->maxstock = loadData->maxstock;
  if (!(*data)->unitwork)
  {
    v20 = *data;
    v20->unitwork = NewSpecific(datUnitWork_t, 0x10u);
  }
  v21 = 0;
  p_unitwork = &loadData->unitwork;
  v23 = 176;
  do
  {
    unitwork = (*data)->unitwork;
    if (!unitwork->m_Items[v21])
    {
      v27 = (*data)->unitwork;
      v28 = Allocate(datUnitWork_t);
      datUnitWork_t___ctor(v28);
      *&v27[2 * v21 + 8] = v28;
    }
    v30 = (*data)->unitwork;
    v32 = v30->m_Items[v21];
    v32->flag = *(*p_unitwork + v23 - 144);
    v34 = (*data)->unitwork;
    v36 = v34->m_Items[v21];
    v36->id = *(*p_unitwork + v23 - 140);
    v38 = (*data)->unitwork;
    v40 = v38->m_Items[v21];
    v40->hp = *(*p_unitwork + v23 - 138);
    v42 = (*data)->unitwork;
    v44 = v42->m_Items[v21];
    v44->maxhp = *(*p_unitwork + v23 - 136);
    v46 = (*data)->unitwork;
    v48 = v46->m_Items[v21];
    v48->mp = *(*p_unitwork + v23 - 134);
    v50 = (*data)->unitwork;
    v52 = v50->m_Items[v21];
    v52->maxmp = *(*p_unitwork + v23 - 132);
    v54 = (*data)->unitwork;
    v56 = v54->m_Items[v21];
    v56->badstatus = *(*p_unitwork + v23 - 130);
    v58 = (*data)->unitwork;
    v60 = v58->m_Items[v21];
    v60->exp = *(*p_unitwork + v23 - 128);
    v62 = (*data)->unitwork;
    v64 = v62->m_Items[v21];
    v64->level = *(*p_unitwork + v23 - 124);
    v67 = (*data)->unitwork;
    Copy_3886320(
      *(*p_unitwork + v23 - 120),
      v67->m_Items[v21]->param,
      (*data)->unitwork->m_Items[v21]->param->max_length,
      0);
    v70 = (*data)->unitwork;
    Copy_3886320(
      *(*p_unitwork + v23 - 112),
      v70->m_Items[v21]->skillparam,
      (*data)->unitwork->m_Items[v21]->skillparam->max_length,
      0);
    v72 = (*data)->unitwork;
    v74 = v72->m_Items[v21];
    v74->uniqueid = *(*p_unitwork + v23 - 104);
    v76 = (*data)->unitwork;
    v78 = v76->m_Items[v21];
    v78->reserve1 = *(*p_unitwork + v23 - 102);
    v80 = (*data)->unitwork;
    v82 = v80->m_Items[v21];
    v82->reserve2 = *(*p_unitwork + v23 - 100);
    v85 = (*data)->unitwork;
    Copy_3886320(
      *(*p_unitwork + v23 - 96),
      v85->m_Items[v21]->namecode,
      (*data)->unitwork->m_Items[v21]->namecode->max_length,
      0);
    v87 = (*data)->unitwork;
    v89 = v87->m_Items[v21];
    v89->skillcnt = *(*p_unitwork + v23 - 88);
    v92 = (*data)->unitwork;
    Copy_3886320(
      *(*p_unitwork + v23 - 80),
      v92->m_Items[v21]->skill,
      (*data)->unitwork->m_Items[v21]->skill->max_length,
      0);
    v94 = (*data)->unitwork;
    v96 = v94->m_Items[v21];
    v96->nowcommand = *(*p_unitwork + v23 - 72);
    v98 = (*data)->unitwork;
    v100 = v98->m_Items[v21];
    v100->nowindex = *(*p_unitwork + v23 - 70);
    v102 = (*data)->unitwork;
    v104 = v102->m_Items[v21];
    v104->nowtarea = *(*p_unitwork + v23 - 68);
    v106 = (*data)->unitwork;
    v108 = v106->m_Items[v21];
    v108->nowtform = *(*p_unitwork + v23 - 66);
    v110 = (*data)->unitwork;
    v112 = v110->m_Items[v21];
    v112->prevcommand = *(*p_unitwork + v23 - 64);
    v114 = (*data)->unitwork;
    v116 = v114->m_Items[v21];
    v116->previndex = *(*p_unitwork + v23 - 62);
    v118 = (*data)->unitwork;
    v120 = v118->m_Items[v21];
    v120->prevtarea = *(*p_unitwork + v23 - 60);
    v122 = (*data)->unitwork;
    v124 = v122->m_Items[v21];
    v124->prevtform = *(*p_unitwork + v23 - 58);
    v127 = (*data)->unitwork;
    Copy_3886320(
      *(*p_unitwork + v23 - 56),
      v127->m_Items[v21]->mitamaparam,
      (*data)->unitwork->m_Items[v21]->mitamaparam->max_length,
      0);
    v130 = (*data)->unitwork;
    Copy_3886320(
      *(*p_unitwork + v23 - 48),
      v130->m_Items[v21]->levelupparam,
      (*data)->unitwork->m_Items[v21]->levelupparam->max_length,
      0);
    v133 = (*data)->unitwork;
    Copy_3886320(
      *(*p_unitwork + v23 - 40),
      v133->m_Items[v21]->keisyoskill,
      (*data)->unitwork->m_Items[v21]->keisyoskill->max_length,
      0);
    v136 = (*data)->unitwork;
    Copy_3886320(
      *(*p_unitwork + v23 - 32),
      v136->m_Items[v21]->keiattr,
      (*data)->unitwork->m_Items[v21]->keiattr->max_length,
      0);
    v138 = (*data)->unitwork;
    v140 = v138->m_Items[v21];
    v140->hensinmae = *(*p_unitwork + v23 - 24);
    v143 = (*data)->unitwork;
    Copy_3886320(
      *(*p_unitwork + v23 - 16),
      v143->m_Items[v21]->getdevilhearts,
      (*data)->unitwork->m_Items[v21]->getdevilhearts->max_length,
      0);
    v145 = (*data)->unitwork;
    v147 = v145->m_Items[v21];
    v147->hensinmaeexp = *(*p_unitwork + v23 - 8);
    v150 = (*data)->unitwork;
    Copy_3886320(
      *(&(*p_unitwork)->obj.klass + v23),
      v150->m_Items[v21]->fullnamecode,
      (*data)->unitwork->m_Items[v21]->fullnamecode->max_length,
      0);
    ++v21;
    v23 += 152;
  }
  while (v21 != 16);
  Copy_3886320(
    loadData->stocklist,
    (*data)->stocklist,
    (*data)->stocklist->max_length,
    0);
  (*data)->stockcnt = loadData->stockcnt;
  Copy_3886320(loadData->item, (*data)->item, (*data)->item->max_length, 0);
  boss_press = (*data)->boss_press;
  Copy_3886320(
    loadData->boss_press00,
    boss_press->m_Items[0],
    (*data)->boss_press->m_Items[0]->max_length,
    0);
  v153 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press01, v153->m_Items[1], v153->m_Items[1]->max_length);
  v155 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press02, v155->m_Items[2], v155->m_Items[2]->max_length);
  v157 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press03, v157->m_Items[3], v157->m_Items[3]->max_length);
  v159 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press04, v159->m_Items[4], v159->m_Items[4]->max_length);
  v161 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press05, v161->m_Items[5], v161->m_Items[5]->max_length);
  v163 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press06, v163->m_Items[6], v163->m_Items[6]->max_length);
  v165 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press07, v165->m_Items[7], v165->m_Items[7]->max_length);
  v167 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press08, v167->m_Items[8], v167->m_Items[8]->max_length);
  v169 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press09, v169->m_Items[9], v169->m_Items[9]->max_length);
  v171 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press10, v171->m_Items[10], v171->m_Items[10]->max_length);
  v173 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press11, v173->m_Items[11], v173->m_Items[11]->max_length);
  v175 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press12, v175->m_Items[12], v175->m_Items[12]->max_length);
  v177 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press13, v177->m_Items[13], v177->m_Items[13]->max_length);
  v179 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press14, v179->m_Items[14], v179->m_Items[14]->max_length);
  v181 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press15, v181->m_Items[15], v181->m_Items[15]->max_length);
  v183 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press16, v183->m_Items[16], v183->m_Items[16]->max_length);
  v185 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press17, v185->m_Items[17], v185->m_Items[17]->max_length);
  v187 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press18, v187->m_Items[18], v187->m_Items[18]->max_length);
  v189 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press19, v189->m_Items[19], v189->m_Items[19]->max_length);
  v191 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press20, v191->m_Items[20], v191->m_Items[20]->max_length);
  v193 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press21, v193->m_Items[21], v193->m_Items[21]->max_length);
  v195 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press22, v195->m_Items[22], v195->m_Items[22]->max_length);
  v197 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press23, v197->m_Items[23], v197->m_Items[23]->max_length);
  v199 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press24, v199->m_Items[24], v199->m_Items[24]->max_length);
  v201 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press25, v201->m_Items[25], v201->m_Items[25]->max_length);
  v203 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press26, v203->m_Items[26], v203->m_Items[26]->max_length);
  v205 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press27, v205->m_Items[27], v205->m_Items[27]->max_length);
  v207 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press28, v207->m_Items[28], v207->m_Items[28]->max_length);
  v209 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press29, v209->m_Items[29], v209->m_Items[29]->max_length);
  v211 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press30, v211->m_Items[30], v211->m_Items[30]->max_length);
  v213 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press31, v213->m_Items[31], v213->m_Items[31]->max_length);
  v215 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press32, v215->m_Items[32], v215->m_Items[32]->max_length);
  v217 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press33, v217->m_Items[33], v217->m_Items[33]->max_length);
  v219 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press34, v219->m_Items[34], v219->m_Items[34]->max_length);
  v221 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press35, v221->m_Items[35], v221->m_Items[35]->max_length);
  v223 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press36, v223->m_Items[36], v223->m_Items[36]->max_length);
  v225 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press37, v225->m_Items[37], v225->m_Items[37]->max_length);
  v227 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press38, v227->m_Items[38], v227->m_Items[38]->max_length);
  v229 = (*data)->boss_press;
  Copy_3886320(loadData->boss_press39, v229->m_Items[39], v229->m_Items[39]->max_length);
  Copy_3886320(
    loadData->syakkincnt,
    (*data)->syakkincnt,
    (*data)->syakkincnt->max_length,
    0);
  Copy_3886320(
    loadData->negoques,
    (*data)->negoques,
    (*data)->negoques->max_length,
    0);
  Copy_3886320(
    loadData->kotowari,
    (*data)->kotowari,
    (*data)->kotowari->max_length,
    0);
  (*data)->wakimi_id = loadData->wakimi_id;
  (*data)->bouga_cnt = loadData->bouga_cnt;
  (*data)->encountkyori = loadData->encountkyori;
  (*data)->encountcnt = loadData->encountcnt;
  (*data)->heartsequip = loadData->heartsequip;
  Copy_3886320(loadData->hearts, (*data)->hearts, (*data)->hearts->max_length, 0);
  Copy_3886320(
    loadData->heartsskcnt,
    (*data)->heartsskcnt,
    (*data)->heartsskcnt->max_length,
    0);
  (*data)->heartscnt = loadData->heartscnt;
  name_nums = (*data)->name_nums;
  Copy_3886320(
    loadData->name_nums00,
    name_nums->m_Items[0],
    (*data)->name_nums->m_Items[0]->max_length,
    0);
  v232 = (*data)->name_nums;
  Copy_3886320(loadData->name_nums01, v232->m_Items[1], v232->m_Items[1]->max_length);
  v234 = (*data)->name_nums;
  Copy_3886320(loadData->name_nums02, v234->m_Items[2], v234->m_Items[2]->max_length);
  v236 = (*data)->name_nums;
  Copy_3886320(loadData->name_nums03, v236->m_Items[3], v236->m_Items[3]->max_length);
  name_code = (*data)->name_code;
  Copy_3886320(
    loadData->name_code00,
    name_code->m_Items[0],
    (*data)->name_code->m_Items[0]->max_length,
    0);
  v239 = (*data)->name_code;
  Copy_3886320(loadData->name_code01, v239->m_Items[1], v239->m_Items[1]->max_length);
  v241 = (*data)->name_code;
  Copy_3886320(loadData->name_code02, v241->m_Items[2], v241->m_Items[2]->max_length);
  v243 = (*data)->name_code;
  Copy_3886320(loadData->name_code03, v243->m_Items[3], v243->m_Items[3]->max_length);
  v245 = (*data)->cname_code;
  Copy_3886320(
    loadData->cname_code00,
    v245->m_Items[0],
    (*data)->cname_code->m_Items[0]->max_length,
    0);
  v246 = (*data)->cname_code;
  Copy_3886320(loadData->cname_code01, v246->m_Items[1], v246->m_Items[1]->max_length);
  v248 = (*data)->cname_code;
  Copy_3886320(loadData->cname_code02, v248->m_Items[2], v248->m_Items[2]->max_length);
  v250 = (*data)->cname_code;
  Copy_3886320(loadData->cname_code03, v250->m_Items[3], v250->m_Items[3]->max_length);
  Copy_3886320(
    loadData->cname_nums,
    (*data)->cname_nums,
    (*data)->cname_nums->max_length,
    0);
  v254 = *data;
  fldSave = (*data)->fldSave;
  if (fldSave)
  {
    PushBlock = fldSave->PushBlock;
    p_fldSave = &loadData->fldSave;
    if (!LODWORD(PushBlock->max_length))
      goto LABEL_302;
  }
  else
  {
    v870 = Allocate(fldSave_t);
    fldSave_t___ctor(v870);
    v254->fldSave = v870;
    PushBlock = (*data)->fldSave->PushBlock;
    p_fldSave = &loadData->fldSave;
    if (!LODWORD(PushBlock->max_length))
    {
LABEL_302:
    }
  }
  restorePushBlock(v252, &p_fldSave->PushBlock00, PushBlock->m_Items);
  v261 = (*data)->fldSave->PushBlock;
  restorePushBlock(v259, &loadData->fldSave.PushBlock01, &v261->m_Items[1]);
  v265 = (*data)->fldSave->PushBlock;
  restorePushBlock(v263, &loadData->fldSave.PushBlock02, &v265->m_Items[2]);
  v269 = (*data)->fldSave->PushBlock;
  restorePushBlock(v267, &loadData->fldSave.PushBlock03, &v269->m_Items[3]);
  v273 = (*data)->fldSave->PushBlock;
  restorePushBlock(v271, &loadData->fldSave.PushBlock04, &v273->m_Items[4]);
  v277 = (*data)->fldSave->PushBlock;
  restorePushBlock(v275, &loadData->fldSave.PushBlock05, &v277->m_Items[5]);
  v281 = (*data)->fldSave->PushBlock;
  restorePushBlock(v279, &loadData->fldSave.PushBlock06, &v281->m_Items[6]);
  v285 = (*data)->fldSave->PushBlock;
  restorePushBlock(v283, &loadData->fldSave.PushBlock07, &v285->m_Items[7]);
  v289 = (*data)->fldSave->PushBlock;
  restorePushBlock(v287, &loadData->fldSave.PushBlock08, &v289->m_Items[8]);
  v293 = (*data)->fldSave->PushBlock;
  restorePushBlock(v291, &loadData->fldSave.PushBlock09, &v293->m_Items[9]);
  v297 = (*data)->fldSave->PushBlock;
  restorePushBlock(v295, &loadData->fldSave.PushBlock10, &v297->m_Items[10]);
  v301 = (*data)->fldSave->PushBlock;
  restorePushBlock(v299, &loadData->fldSave.PushBlock11, &v301->m_Items[11]);
  v305 = (*data)->fldSave->PushBlock;
  restorePushBlock(v303, &loadData->fldSave.PushBlock12, &v305->m_Items[12]);
  v309 = (*data)->fldSave->PushBlock;
  restorePushBlock(v307, &loadData->fldSave.PushBlock13, &v309->m_Items[13]);
  v313 = (*data)->fldSave->PushBlock;
  restorePushBlock(v311, &loadData->fldSave.PushBlock14, &v313->m_Items[14]);
  v317 = (*data)->fldSave->PushBlock;
  restorePushBlock(v315, &loadData->fldSave.PushBlock15, &v317->m_Items[15]);
  v321 = (*data)->fldSave->PushBlock;
  restorePushBlock(v319, &loadData->fldSave.PushBlock16, &v321->m_Items[16]);
  v325 = (*data)->fldSave->PushBlock;
  restorePushBlock(v323, &loadData->fldSave.PushBlock17, &v325->m_Items[17]);
  v329 = (*data)->fldSave->PushBlock;
  restorePushBlock(v327, &loadData->fldSave.PushBlock18, &v329->m_Items[18]);
  v333 = (*data)->fldSave->PushBlock;
  restorePushBlock(v331, &loadData->fldSave.PushBlock19, &v333->m_Items[19]);
  v337 = (*data)->fldSave->PushBlock;
  restorePushBlock(v335, &loadData->fldSave.PushBlock20, &v337->m_Items[20]);
  v341 = (*data)->fldSave->PushBlock;
  restorePushBlock(v339, &loadData->fldSave.PushBlock21, &v341->m_Items[21]);
  v345 = (*data)->fldSave->PushBlock;
  restorePushBlock(v343, &loadData->fldSave.PushBlock22, &v345->m_Items[22]);
  v349 = (*data)->fldSave->PushBlock;
  restorePushBlock(v347, &loadData->fldSave.PushBlock23, &v349->m_Items[23]);
  v353 = (*data)->fldSave->PushBlock;
  restorePushBlock(v351, &loadData->fldSave.PushBlock24, &v353->m_Items[24]);
  v357 = (*data)->fldSave->PushBlock;
  restorePushBlock(v355, &loadData->fldSave.PushBlock25, &v357->m_Items[25]);
  v361 = (*data)->fldSave->PushBlock;
  restorePushBlock(v359, &loadData->fldSave.PushBlock26, &v361->m_Items[26]);
  v365 = (*data)->fldSave->PushBlock;
  restorePushBlock(v363, &loadData->fldSave.PushBlock27, &v365->m_Items[27]);
  v369 = (*data)->fldSave->PushBlock;
  restorePushBlock(v367, &loadData->fldSave.PushBlock28, &v369->m_Items[28]);
  v373 = (*data)->fldSave->PushBlock;
  restorePushBlock(v371, &loadData->fldSave.PushBlock29, &v373->m_Items[29]);
  v377 = (*data)->fldSave->PushBlock;
  restorePushBlock(v375, &loadData->fldSave.PushBlock30, &v377->m_Items[30]);
  v381 = (*data)->fldSave->PushBlock;
  restorePushBlock(v379, &loadData->fldSave.PushBlock31, &v381->m_Items[31]);
  v385 = (*data)->fldSave->PushBlock;
  restorePushBlock(v383, &loadData->fldSave.PushBlock32, &v385->m_Items[32]);
  v389 = (*data)->fldSave->PushBlock;
  restorePushBlock(v387, &loadData->fldSave.PushBlock33, &v389->m_Items[33]);
  v393 = (*data)->fldSave->PushBlock;
  restorePushBlock(v391, &loadData->fldSave.PushBlock34, &v393->m_Items[34]);
  v397 = (*data)->fldSave->PushBlock;
  restorePushBlock(v395, &loadData->fldSave.PushBlock35, &v397->m_Items[35]);
  v401 = (*data)->fldSave->PushBlock;
  restorePushBlock(v399, &loadData->fldSave.PushBlock36, &v401->m_Items[36]);
  v405 = (*data)->fldSave->PushBlock;
  restorePushBlock(v403, &loadData->fldSave.PushBlock37, &v405->m_Items[37]);
  v409 = (*data)->fldSave->PushBlock;
  restorePushBlock(v407, &loadData->fldSave.PushBlock38, &v409->m_Items[38]);
  v413 = (*data)->fldSave->PushBlock;
  restorePushBlock(v411, &loadData->fldSave.PushBlock39, &v413->m_Items[39]);
  blkOpenFlg = (*data)->fldSave->amap->blkOpenFlg;
  Copy_3886320(
    loadData->fldSave.amap.blkOpenFlg00,
    blkOpenFlg->m_Items[0],
    (*data)->fldSave->amap->blkOpenFlg->m_Items[0]->max_length,
    0);
  v416 = (*data)->fldSave->amap->blkOpenFlg;
  Copy_3886320(loadData->fldSave.amap.blkOpenFlg01, v416->m_Items[1], v416->m_Items[1]->max_length);
  v418 = (*data)->fldSave->amap->blkOpenFlg;
  Copy_3886320(loadData->fldSave.amap.blkOpenFlg02, v418->m_Items[2], v418->m_Items[2]->max_length);
  v420 = (*data)->fldSave->amap->blkOpenFlg;
  Copy_3886320(loadData->fldSave.amap.blkOpenFlg03, v420->m_Items[3], v420->m_Items[3]->max_length);
  v422 = (*data)->fldSave->amap->blkOpenFlg;
  Copy_3886320(loadData->fldSave.amap.blkOpenFlg04, v422->m_Items[4], v422->m_Items[4]->max_length);
  v424 = (*data)->fldSave->amap->blkOpenFlg;
  Copy_3886320(loadData->fldSave.amap.blkOpenFlg05, v424->m_Items[5], v424->m_Items[5]->max_length);
  v426 = (*data)->fldSave->amap->blkOpenFlg;
  Copy_3886320(loadData->fldSave.amap.blkOpenFlg06, v426->m_Items[6], v426->m_Items[6]->max_length);
  v428 = (*data)->fldSave->amap->blkOpenFlg;
  Copy_3886320(loadData->fldSave.amap.blkOpenFlg07, v428->m_Items[7], v428->m_Items[7]->max_length);
  v430 = (*data)->fldSave->amap->blkOpenFlg;
  Copy_3886320(loadData->fldSave.amap.blkOpenFlg08, v430->m_Items[8], v430->m_Items[8]->max_length);
  v432 = (*data)->fldSave->amap->blkOpenFlg;
  Copy_3886320(loadData->fldSave.amap.blkOpenFlg09, v432->m_Items[9], v432->m_Items[9]->max_length);
  v434 = (*data)->fldSave->amap->blkOpenFlg;
  Copy_3886320(loadData->fldSave.amap.blkOpenFlg10, v434->m_Items[10], v434->m_Items[10]->max_length);
  v436 = (*data)->fldSave->amap->blkOpenFlg;
  Copy_3886320(loadData->fldSave.amap.blkOpenFlg11, v436->m_Items[11], v436->m_Items[11]->max_length);
  v438 = (*data)->fldSave->amap->blkOpenFlg;
  Copy_3886320(loadData->fldSave.amap.blkOpenFlg12, v438->m_Items[12], v438->m_Items[12]->max_length);
  v440 = (*data)->fldSave->amap->blkOpenFlg;
  Copy_3886320(loadData->fldSave.amap.blkOpenFlg13, v440->m_Items[13], v440->m_Items[13]->max_length);
  v442 = (*data)->fldSave->amap->blkOpenFlg;
  Copy_3886320(loadData->fldSave.amap.blkOpenFlg14, v442->m_Items[14], v442->m_Items[14]->max_length);
  v444 = (*data)->fldSave->amap->blkOpenFlg;
  Copy_3886320(loadData->fldSave.amap.blkOpenFlg15, v444->m_Items[15], v444->m_Items[15]->max_length);
  v446 = (*data)->fldSave->amap->blkOpenFlg;
  Copy_3886320(loadData->fldSave.amap.blkOpenFlg16, v446->m_Items[16], v446->m_Items[16]->max_length);
  v448 = (*data)->fldSave->amap->blkOpenFlg;
  Copy_3886320(loadData->fldSave.amap.blkOpenFlg17, v448->m_Items[17], v448->m_Items[17]->max_length);
  v450 = (*data)->fldSave->amap->blkOpenFlg;
  Copy_3886320(loadData->fldSave.amap.blkOpenFlg18, v450->m_Items[18], v450->m_Items[18]->max_length);
  v452 = (*data)->fldSave->amap->blkOpenFlg;
  Copy_3886320(loadData->fldSave.amap.blkOpenFlg19, v452->m_Items[19], v452->m_Items[19]->max_length);
  v454 = (*data)->fldSave->amap->blkOpenFlg;
  Copy_3886320(loadData->fldSave.amap.blkOpenFlg20, v454->m_Items[20], v454->m_Items[20]->max_length);
  v456 = (*data)->fldSave->amap->blkOpenFlg;
  Copy_3886320(loadData->fldSave.amap.blkOpenFlg21, v456->m_Items[21], v456->m_Items[21]->max_length);
  v458 = (*data)->fldSave->amap->blkOpenFlg;
  Copy_3886320(loadData->fldSave.amap.blkOpenFlg22, v458->m_Items[22], v458->m_Items[22]->max_length);
  v460 = (*data)->fldSave->amap->blkOpenFlg;
  Copy_3886320(loadData->fldSave.amap.blkOpenFlg23, v460->m_Items[23], v460->m_Items[23]->max_length);
  v462 = (*data)->fldSave->amap->blkOpenFlg;
  Copy_3886320(loadData->fldSave.amap.blkOpenFlg24, v462->m_Items[24], v462->m_Items[24]->max_length);
  v464 = (*data)->fldSave->amap->blkOpenFlg;
  Copy_3886320(loadData->fldSave.amap.blkOpenFlg25, v464->m_Items[25], v464->m_Items[25]->max_length);
  v466 = (*data)->fldSave->amap->blkOpenFlg;
  Copy_3886320(loadData->fldSave.amap.blkOpenFlg26, v466->m_Items[26], v466->m_Items[26]->max_length);
  v468 = (*data)->fldSave->amap->blkOpenFlg;
  Copy_3886320(loadData->fldSave.amap.blkOpenFlg27, v468->m_Items[27], v468->m_Items[27]->max_length);
  v470 = (*data)->fldSave->amap->blkOpenFlg;
  Copy_3886320(loadData->fldSave.amap.blkOpenFlg28, v470->m_Items[28], v470->m_Items[28]->max_length);
  v472 = (*data)->fldSave->amap->blkOpenFlg;
  Copy_3886320(loadData->fldSave.amap.blkOpenFlg29, v472->m_Items[29], v472->m_Items[29]->max_length);
  takara = (*data)->fldSave->takara;
  Copy_3886320(loadData->fldSave.takara, takara, takara->max_length);
  (*data)->fldSave->tmnltype = loadData->fldSave.tmnltype;
  (*data)->fldSave->tmnlid = loadData->fldSave.tmnlid;
  (*data)->fldSave->AnahoriCnt = loadData->fldSave.AnahoriCnt;
  takara2 = (*data)->fldSave->takara2;
  Copy_3886320(loadData->fldSave.takara2, takara2, takara2->max_length);
  pub = (*data)->fldSave->pub;
  Copy_3886320(loadData->fldSave.pub, pub, pub->max_length);
  Copy_3886320(
    loadData->config_data,
    (*data)->config_data,
    (*data)->config_data->max_length,
    0);
  (*data)->dmy = loadData->dmy;
  hearts_sk = (*data)->hearts_sk;
  Copy_3886320(
    loadData->hearts_sk00,
    hearts_sk->m_Items[0],
    (*data)->hearts_sk->m_Items[0]->max_length,
    0);
  v478 = (*data)->hearts_sk;
  Copy_3886320(loadData->hearts_sk01, v478->m_Items[1], v478->m_Items[1]->max_length);
  v480 = (*data)->hearts_sk;
  Copy_3886320(loadData->hearts_sk02, v480->m_Items[2], v480->m_Items[2]->max_length);
  v482 = (*data)->hearts_sk;
  Copy_3886320(loadData->hearts_sk03, v482->m_Items[3], v482->m_Items[3]->max_length);
  v484 = (*data)->hearts_sk;
  Copy_3886320(loadData->hearts_sk04, v484->m_Items[4], v484->m_Items[4]->max_length);
  v486 = (*data)->hearts_sk;
  Copy_3886320(loadData->hearts_sk05, v486->m_Items[5], v486->m_Items[5]->max_length);
  v488 = (*data)->hearts_sk;
  Copy_3886320(loadData->hearts_sk06, v488->m_Items[6], v488->m_Items[6]->max_length);
  v490 = (*data)->hearts_sk;
  Copy_3886320(loadData->hearts_sk07, v490->m_Items[7], v490->m_Items[7]->max_length);
  v492 = (*data)->hearts_sk;
  Copy_3886320(loadData->hearts_sk08, v492->m_Items[8], v492->m_Items[8]->max_length);
  v494 = (*data)->hearts_sk;
  Copy_3886320(loadData->hearts_sk09, v494->m_Items[9], v494->m_Items[9]->max_length);
  v496 = (*data)->hearts_sk;
  Copy_3886320(loadData->hearts_sk10, v496->m_Items[10], v496->m_Items[10]->max_length);
  v498 = (*data)->hearts_sk;
  Copy_3886320(loadData->hearts_sk11, v498->m_Items[11], v498->m_Items[11]->max_length);
  v500 = (*data)->hearts_sk;
  Copy_3886320(loadData->hearts_sk12, v500->m_Items[12], v500->m_Items[12]->max_length);
  v502 = (*data)->hearts_sk;
  Copy_3886320(loadData->hearts_sk13, v502->m_Items[13], v502->m_Items[13]->max_length);
  v504 = (*data)->hearts_sk;
  Copy_3886320(loadData->hearts_sk14, v504->m_Items[14], v504->m_Items[14]->max_length);
  v506 = (*data)->hearts_sk;
  Copy_3886320(loadData->hearts_sk15, v506->m_Items[15], v506->m_Items[15]->max_length);
  v508 = (*data)->hearts_sk;
  Copy_3886320(loadData->hearts_sk16, v508->m_Items[16], v508->m_Items[16]->max_length);
  v510 = (*data)->hearts_sk;
  Copy_3886320(loadData->hearts_sk17, v510->m_Items[17], v510->m_Items[17]->max_length);
  v512 = (*data)->hearts_sk;
  Copy_3886320(loadData->hearts_sk18, v512->m_Items[18], v512->m_Items[18]->max_length);
  v514 = (*data)->hearts_sk;
  Copy_3886320(loadData->hearts_sk19, v514->m_Items[19], v514->m_Items[19]->max_length);
  v516 = (*data)->hearts_sk;
  Copy_3886320(loadData->hearts_sk20, v516->m_Items[20], v516->m_Items[20]->max_length);
  v518 = (*data)->hearts_sk;
  Copy_3886320(loadData->hearts_sk21, v518->m_Items[21], v518->m_Items[21]->max_length);
  v520 = (*data)->hearts_sk;
  Copy_3886320(loadData->hearts_sk22, v520->m_Items[22], v520->m_Items[22]->max_length);
  v522 = (*data)->hearts_sk;
  Copy_3886320(loadData->hearts_sk23, v522->m_Items[23], v522->m_Items[23]->max_length);
  v524 = (*data)->hearts_sk;
  Copy_3886320(loadData->hearts_sk24, v524->m_Items[24], v524->m_Items[24]->max_length);
  v526 = (*data)->hearts_sk;
  Copy_3886320(loadData->hearts_sk25, v526->m_Items[25], v526->m_Items[25]->max_length);
  v528 = (*data)->hearts_sk;
  Copy_3886320(loadData->hearts_sk26, v528->m_Items[26], v528->m_Items[26]->max_length);
  v530 = (*data)->hearts_sk;
  Copy_3886320(loadData->hearts_sk27, v530->m_Items[27], v530->m_Items[27]->max_length);
  v532 = (*data)->hearts_sk;
  Copy_3886320(loadData->hearts_sk28, v532->m_Items[28], v532->m_Items[28]->max_length);
  v534 = (*data)->hearts_sk;
  Copy_3886320(loadData->hearts_sk29, v534->m_Items[29], v534->m_Items[29]->max_length);
  v536 = (*data)->hearts_sk;
  Copy_3886320(loadData->hearts_sk30, v536->m_Items[30], v536->m_Items[30]->max_length);
  v538 = (*data)->hearts_sk;
  Copy_3886320(loadData->hearts_sk31, v538->m_Items[31], v538->m_Items[31]->max_length);
  hearts_up_param = (*data)->hearts_up_param;
  Copy_3886320(
    loadData->hearts_up_param00,
    hearts_up_param->m_Items[0],
    (*data)->hearts_up_param->m_Items[0]->max_length,
    0);
  v541 = (*data)->hearts_up_param;
  Copy_3886320(loadData->hearts_up_param01, v541->m_Items[1], v541->m_Items[1]->max_length);
  v543 = (*data)->hearts_up_param;
  Copy_3886320(loadData->hearts_up_param02, v543->m_Items[2], v543->m_Items[2]->max_length);
  v545 = (*data)->hearts_up_param;
  Copy_3886320(loadData->hearts_up_param03, v545->m_Items[3], v545->m_Items[3]->max_length);
  v547 = (*data)->hearts_up_param;
  Copy_3886320(loadData->hearts_up_param04, v547->m_Items[4], v547->m_Items[4]->max_length);
  v549 = (*data)->hearts_up_param;
  Copy_3886320(loadData->hearts_up_param05, v549->m_Items[5], v549->m_Items[5]->max_length);
  v551 = (*data)->hearts_up_param;
  Copy_3886320(loadData->hearts_up_param06, v551->m_Items[6], v551->m_Items[6]->max_length);
  v553 = (*data)->hearts_up_param;
  Copy_3886320(loadData->hearts_up_param07, v553->m_Items[7], v553->m_Items[7]->max_length);
  v555 = (*data)->hearts_up_param;
  Copy_3886320(loadData->hearts_up_param08, v555->m_Items[8], v555->m_Items[8]->max_length);
  v557 = (*data)->hearts_up_param;
  Copy_3886320(loadData->hearts_up_param09, v557->m_Items[9], v557->m_Items[9]->max_length);
  v559 = (*data)->hearts_up_param;
  Copy_3886320(loadData->hearts_up_param10, v559->m_Items[10], v559->m_Items[10]->max_length);
  v561 = (*data)->hearts_up_param;
  Copy_3886320(loadData->hearts_up_param11, v561->m_Items[11], v561->m_Items[11]->max_length);
  v563 = (*data)->hearts_up_param;
  Copy_3886320(loadData->hearts_up_param12, v563->m_Items[12], v563->m_Items[12]->max_length);
  v565 = (*data)->hearts_up_param;
  Copy_3886320(loadData->hearts_up_param13, v565->m_Items[13], v565->m_Items[13]->max_length);
  v567 = (*data)->hearts_up_param;
  Copy_3886320(loadData->hearts_up_param14, v567->m_Items[14], v567->m_Items[14]->max_length);
  v569 = (*data)->hearts_up_param;
  Copy_3886320(loadData->hearts_up_param15, v569->m_Items[15], v569->m_Items[15]->max_length);
  v571 = (*data)->hearts_up_param;
  Copy_3886320(loadData->hearts_up_param16, v571->m_Items[16], v571->m_Items[16]->max_length);
  v573 = (*data)->hearts_up_param;
  Copy_3886320(loadData->hearts_up_param17, v573->m_Items[17], v573->m_Items[17]->max_length);
  v575 = (*data)->hearts_up_param;
  Copy_3886320(loadData->hearts_up_param18, v575->m_Items[18], v575->m_Items[18]->max_length);
  v577 = (*data)->hearts_up_param;
  Copy_3886320(loadData->hearts_up_param19, v577->m_Items[19], v577->m_Items[19]->max_length);
  v579 = (*data)->hearts_up_param;
  Copy_3886320(loadData->hearts_up_param20, v579->m_Items[20], v579->m_Items[20]->max_length);
  v581 = (*data)->hearts_up_param;
  Copy_3886320(loadData->hearts_up_param21, v581->m_Items[21], v581->m_Items[21]->max_length);
  v583 = (*data)->hearts_up_param;
  Copy_3886320(loadData->hearts_up_param22, v583->m_Items[22], v583->m_Items[22]->max_length);
  v585 = (*data)->hearts_up_param;
  Copy_3886320(loadData->hearts_up_param23, v585->m_Items[23], v585->m_Items[23]->max_length);
  v587 = (*data)->hearts_up_param;
  Copy_3886320(loadData->hearts_up_param24, v587->m_Items[24], v587->m_Items[24]->max_length);
  v589 = (*data)->hearts_up_param;
  Copy_3886320(loadData->hearts_up_param25, v589->m_Items[25], v589->m_Items[25]->max_length);
  v591 = (*data)->hearts_up_param;
  Copy_3886320(loadData->hearts_up_param26, v591->m_Items[26], v591->m_Items[26]->max_length);
  v593 = (*data)->hearts_up_param;
  Copy_3886320(loadData->hearts_up_param27, v593->m_Items[27], v593->m_Items[27]->max_length);
  v595 = (*data)->hearts_up_param;
  Copy_3886320(loadData->hearts_up_param28, v595->m_Items[28], v595->m_Items[28]->max_length);
  v597 = (*data)->hearts_up_param;
  Copy_3886320(loadData->hearts_up_param29, v597->m_Items[29], v597->m_Items[29]->max_length);
  v599 = (*data)->hearts_up_param;
  Copy_3886320(loadData->hearts_up_param30, v599->m_Items[30], v599->m_Items[30]->max_length);
  v601 = (*data)->hearts_up_param;
  Copy_3886320(loadData->hearts_up_param31, v601->m_Items[31], v601->m_Items[31]->max_length);
  v603 = *data;
  encyc_record = (*data)->encyc_record;
  if (!encyc_record)
  {
    v605 = Allocate(fclEncycRecord_t);
    fclEncycRecord_t___ctor(v605);
    v603->encyc_record = v605;
    encyc_record = (*data)->encyc_record;
  }
  encyc_record->num = loadData->encyc_record.num;
  (*data)->encyc_record->reserved0 = loadData->encyc_record.reserved0;
  (*data)->encyc_record->reserved1 = loadData->encyc_record.reserved1;
  (*data)->encyc_record->reserved2 = loadData->encyc_record.reserved2;
  v606 = *data;
  v607 = (*data)->encyc_record;
  if (!v607->pelem)
  {
    v607->pelem = NewSpecific(fclencyceelem_t, 0xB8u);
    v606 = *data;
  }
  v608 = 0;
  v609 = 124;
  do
  {
    pelem = v606->encyc_record->pelem;
    if (!pelem->m_Items[v608])
    {
      v613 = (*data)->encyc_record->pelem;
      v614 = Allocate(fclencyceelem_t);
      fclencyceelem_t___ctor(v614);
      *&v613[2 * v608 + 8] = v614;
    }
    v616 = (*data)->encyc_record->pelem;
    v618 = loadData->encyc_record.pelem;
    v619 = v616->m_Items[v608];
    v619->id = *(v618 + v609 - 92);
    v621 = (*data)->encyc_record->pelem;
    v623 = loadData->encyc_record.pelem;
    v624 = v621->m_Items[v608];
    v624->reserved0 = *(v623 + v609 - 90);
    v626 = (*data)->encyc_record->pelem;
    v628 = loadData->encyc_record.pelem;
    v629 = v626->m_Items[v608];
    v629->maxhp = *(v628 + v609 - 88);
    v631 = (*data)->encyc_record->pelem;
    v633 = loadData->encyc_record.pelem;
    v634 = v631->m_Items[v608];
    v634->maxmp = *(v633 + v609 - 86);
    v636 = (*data)->encyc_record->pelem;
    v638 = loadData->encyc_record.pelem;
    v639 = v636->m_Items[v608];
    v639->exp = *(v638 + v609 - 84);
    v641 = (*data)->encyc_record->pelem;
    v643 = loadData->encyc_record.pelem;
    v644 = v641->m_Items[v608];
    v644->level = *(v643 + v609 - 80);
    v646 = loadData->encyc_record.pelem;
    v648 = *(v646 + v609 - 76);
    v649 = (*data)->encyc_record->pelem;
    Copy_3886320(
      v648,
      v649->m_Items[v608]->param,
      (*data)->encyc_record->pelem->m_Items[v608]->param->max_length,
      0);
    v651 = loadData->encyc_record.pelem;
    v653 = *(v651 + v609 - 68);
    v654 = (*data)->encyc_record->pelem;
    Copy_3886320(
      v653,
      v654->m_Items[v608]->skillparam,
      (*data)->encyc_record->pelem->m_Items[v608]->skillparam->max_length,
      0);
    v656 = (*data)->encyc_record->pelem;
    v658 = loadData->encyc_record.pelem;
    v659 = v656->m_Items[v608];
    v659->skillcnt = *(v658 + v609 - 60);
    v661 = loadData->encyc_record.pelem;
    v663 = *(v661 + v609 - 52);
    v664 = (*data)->encyc_record->pelem;
    Copy_3886320(
      v663,
      v664->m_Items[v608]->skill,
      (*data)->encyc_record->pelem->m_Items[v608]->skill->max_length,
      0);
    v666 = loadData->encyc_record.pelem;
    v668 = *(v666 + v609 - 44);
    v669 = (*data)->encyc_record->pelem;
    Copy_3886320(
      v668,
      v669->m_Items[v608]->mitamaparam,
      (*data)->encyc_record->pelem->m_Items[v608]->mitamaparam->max_length,
      0);
    v671 = loadData->encyc_record.pelem;
    v673 = *(v671 + v609 - 36);
    v674 = (*data)->encyc_record->pelem;
    Copy_3886320(
      v673,
      v674->m_Items[v608]->levelupparam,
      (*data)->encyc_record->pelem->m_Items[v608]->levelupparam->max_length,
      0);
    v676 = loadData->encyc_record.pelem;
    v678 = *(v676 + v609 - 28);
    v679 = (*data)->encyc_record->pelem;
    Copy_3886320(
      v678,
      v679->m_Items[v608]->keisyoskill,
      (*data)->encyc_record->pelem->m_Items[v608]->keisyoskill->max_length,
      0);
    v681 = loadData->encyc_record.pelem;
    v683 = *(v681 + v609 - 20);
    v684 = (*data)->encyc_record->pelem;
    Copy_3886320(
      v683,
      v684->m_Items[v608]->keiattr,
      (*data)->encyc_record->pelem->m_Items[v608]->keiattr->max_length,
      0);
    v686 = (*data)->encyc_record->pelem;
    v688 = loadData->encyc_record.pelem;
    v689 = v686->m_Items[v608];
    v689->hensinmae = *(v688 + v609 - 12);
    v691 = (*data)->encyc_record->pelem;
    v693 = loadData->encyc_record.pelem;
    v694 = v691->m_Items[v608];
    v694->reserved1 = *(v693 + v609 - 10);
    v696 = (*data)->encyc_record->pelem;
    v698 = loadData->encyc_record.pelem;
    v699 = v696->m_Items[v608];
    v699->flag = *(v698 + v609 - 8);
    v701 = (*data)->encyc_record->pelem;
    v703 = loadData->encyc_record.pelem;
    v704 = v701->m_Items[v608];
    v704->reserved2 = *(v703 + v609 - 4);
    v706 = (*data)->encyc_record->pelem;
    v708 = loadData->encyc_record.pelem;
    v709 = v706->m_Items[v608];
    v709->hensinmaeexp = *(&v708->obj.klass + v609);
    v606 = *data;
    ++v608;
    v609 += 96;
  }
  while (v608 != 184);
  amap31 = v606->amap31;
  if (!amap31)
  {
    v712 = Allocate(fldAutoMapBuff31_t);
    fldAutoMapBuff31_t___ctor(v712);
    v606->amap31 = v712;
    amap31 = (*data)->amap31;
  }
  v713 = amap31->blkOpenFlg;
  Copy_3886320(loadData->amap31.blkOpenFlg00, v713->m_Items[0], v713->m_Items[0]->max_length);
  v714 = (*data)->amap31->blkOpenFlg;
  Copy_3886320(loadData->amap31.blkOpenFlg01, v714->m_Items[1], v714->m_Items[1]->max_length);
  v716 = (*data)->amap31->blkOpenFlg;
  Copy_3886320(loadData->amap31.blkOpenFlg02, v716->m_Items[2], v716->m_Items[2]->max_length);
  v718 = (*data)->amap31->blkOpenFlg;
  Copy_3886320(loadData->amap31.blkOpenFlg03, v718->m_Items[3], v718->m_Items[3]->max_length);
  v720 = (*data)->amap31->blkOpenFlg;
  Copy_3886320(loadData->amap31.blkOpenFlg04, v720->m_Items[4], v720->m_Items[4]->max_length);
  v722 = (*data)->amap31->blkOpenFlg;
  Copy_3886320(loadData->amap31.blkOpenFlg05, v722->m_Items[5], v722->m_Items[5]->max_length);
  v724 = (*data)->amap31->blkOpenFlg;
  Copy_3886320(loadData->amap31.blkOpenFlg06, v724->m_Items[6], v724->m_Items[6]->max_length);
  v726 = (*data)->amap31->blkOpenFlg;
  Copy_3886320(loadData->amap31.blkOpenFlg07, v726->m_Items[7], v726->m_Items[7]->max_length);
  v728 = *data;
  amapEX = (*data)->amapEX;
  if (!amapEX)
  {
    v730 = Allocate(fldAutoMapBuffEX_t);
    fldAutoMapBuffEX_t___ctor(v730);
    v728->amapEX = v730;
    amapEX = (*data)->amapEX;
  }
  v731 = amapEX->blkOpenFlg;
  Copy_3886320(loadData->amapEX.blkOpenFlg00, v731->m_Items[0], v731->m_Items[0]->max_length);
  v732 = (*data)->amapEX->blkOpenFlg;
  blkOpenFlg01 = loadData->amapEX.blkOpenFlg01;
  Copy_3886320(blkOpenFlg01, v732->m_Items[1], v732->m_Items[1]->max_length);
  v735 = *data;
  amap_Ver7 = (*data)->amap_Ver7;
  if (!amap_Ver7)
  {
    v737 = Allocate(fldAutoMapBuff_t);
    fldAutoMapBuff_t___ctor(v737);
    v735->amap_Ver7 = v737;
    amap_Ver7 = (*data)->amap_Ver7;
  }
  v738 = amap_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap.blkOpenFlg00, v738->m_Items[0], v738->m_Items[0]->max_length);
  v739 = (*data)->amap_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap.blkOpenFlg01, v739->m_Items[1], v739->m_Items[1]->max_length);
  v741 = (*data)->amap_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap.blkOpenFlg02, v741->m_Items[2], v741->m_Items[2]->max_length);
  v743 = (*data)->amap_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap.blkOpenFlg03, v743->m_Items[3], v743->m_Items[3]->max_length);
  v745 = (*data)->amap_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap.blkOpenFlg04, v745->m_Items[4], v745->m_Items[4]->max_length);
  v747 = (*data)->amap_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap.blkOpenFlg05, v747->m_Items[5], v747->m_Items[5]->max_length);
  v749 = (*data)->amap_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap.blkOpenFlg06, v749->m_Items[6], v749->m_Items[6]->max_length);
  v751 = (*data)->amap_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap.blkOpenFlg07, v751->m_Items[7], v751->m_Items[7]->max_length);
  v753 = (*data)->amap_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap.blkOpenFlg08, v753->m_Items[8], v753->m_Items[8]->max_length);
  v755 = (*data)->amap_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap.blkOpenFlg09, v755->m_Items[9], v755->m_Items[9]->max_length);
  v757 = (*data)->amap_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap.blkOpenFlg10, v757->m_Items[10], v757->m_Items[10]->max_length);
  v759 = (*data)->amap_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap.blkOpenFlg11, v759->m_Items[11], v759->m_Items[11]->max_length);
  v761 = (*data)->amap_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap.blkOpenFlg12, v761->m_Items[12], v761->m_Items[12]->max_length);
  v763 = (*data)->amap_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap.blkOpenFlg13, v763->m_Items[13], v763->m_Items[13]->max_length);
  v765 = (*data)->amap_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap.blkOpenFlg14, v765->m_Items[14], v765->m_Items[14]->max_length);
  v767 = (*data)->amap_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap.blkOpenFlg15, v767->m_Items[15], v767->m_Items[15]->max_length);
  v769 = (*data)->amap_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap.blkOpenFlg16, v769->m_Items[16], v769->m_Items[16]->max_length);
  v771 = (*data)->amap_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap.blkOpenFlg17, v771->m_Items[17], v771->m_Items[17]->max_length);
  v773 = (*data)->amap_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap.blkOpenFlg18, v773->m_Items[18], v773->m_Items[18]->max_length);
  v775 = (*data)->amap_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap.blkOpenFlg19, v775->m_Items[19], v775->m_Items[19]->max_length);
  v777 = (*data)->amap_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap.blkOpenFlg20, v777->m_Items[20], v777->m_Items[20]->max_length);
  v779 = (*data)->amap_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap.blkOpenFlg21, v779->m_Items[21], v779->m_Items[21]->max_length);
  v781 = (*data)->amap_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap.blkOpenFlg22, v781->m_Items[22], v781->m_Items[22]->max_length);
  v783 = (*data)->amap_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap.blkOpenFlg23, v783->m_Items[23], v783->m_Items[23]->max_length);
  v785 = (*data)->amap_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap.blkOpenFlg24, v785->m_Items[24], v785->m_Items[24]->max_length);
  v787 = (*data)->amap_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap.blkOpenFlg25, v787->m_Items[25], v787->m_Items[25]->max_length);
  v789 = (*data)->amap_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap.blkOpenFlg26, v789->m_Items[26], v789->m_Items[26]->max_length);
  v791 = (*data)->amap_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap.blkOpenFlg27, v791->m_Items[27], v791->m_Items[27]->max_length);
  v793 = (*data)->amap_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap.blkOpenFlg28, v793->m_Items[28], v793->m_Items[28]->max_length);
  v795 = (*data)->amap_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap.blkOpenFlg29, v795->m_Items[29], v795->m_Items[29]->max_length);
  v797 = *data;
  amap31_Ver7 = (*data)->amap31_Ver7;
  if (!amap31_Ver7)
  {
    v799 = Allocate(fldAutoMapBuff31_t);
    fldAutoMapBuff31_t___ctor(v799);
    v797->amap31_Ver7 = v799;
    amap31_Ver7 = (*data)->amap31_Ver7;
  }
  v800 = amap31_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap31.blkOpenFlg00, v800->m_Items[0], v800->m_Items[0]->max_length);
  v801 = (*data)->amap31_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap31.blkOpenFlg01, v801->m_Items[1], v801->m_Items[1]->max_length);
  v803 = (*data)->amap31_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap31.blkOpenFlg02, v803->m_Items[2], v803->m_Items[2]->max_length);
  v805 = (*data)->amap31_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap31.blkOpenFlg03, v805->m_Items[3], v805->m_Items[3]->max_length);
  v807 = (*data)->amap31_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap31.blkOpenFlg04, v807->m_Items[4], v807->m_Items[4]->max_length);
  v809 = (*data)->amap31_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap31.blkOpenFlg05, v809->m_Items[5], v809->m_Items[5]->max_length);
  v811 = (*data)->amap31_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap31.blkOpenFlg06, v811->m_Items[6], v811->m_Items[6]->max_length);
  v813 = (*data)->amap31_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amap31.blkOpenFlg07, v813->m_Items[7], v813->m_Items[7]->max_length);
  v815 = *data;
  amapEX_Ver7 = (*data)->amapEX_Ver7;
  if (!amapEX_Ver7)
  {
    v817 = Allocate(fldAutoMapBuffEX_t);
    fldAutoMapBuffEX_t___ctor(v817);
    v815->amapEX_Ver7 = v817;
    amapEX_Ver7 = (*data)->amapEX_Ver7;
  }
  v818 = amapEX_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amapEX.blkOpenFlg00, v818->m_Items[0], v818->m_Items[0]->max_length);
  v819 = (*data)->amapEX_Ver7->blkOpenFlg;
  Copy_3886320(loadDataVer7->amapEX.blkOpenFlg01, v819->m_Items[1], v819->m_Items[1]->max_length);
  v821 = (*data)->encyc_record->pelem;
  if (!v821->m_Items[184])
  {
    v823 = (*data)->encyc_record->pelem;
    v824 = Allocate(fclencyceelem_t);
    fclencyceelem_t___ctor(v824);
    v823->m_Items[184] = v824;
  }
  v826 = (*data)->encyc_record->pelem;
  v826->m_Items[184]->id = loadDataVer7->dante_pelem.id;
  v828 = (*data)->encyc_record->pelem;
  v828->m_Items[184]->reserved0 = loadDataVer7->dante_pelem.reserved0;
  v830 = (*data)->encyc_record->pelem;
  v830->m_Items[184]->maxhp = loadDataVer7->dante_pelem.maxhp;
  v832 = (*data)->encyc_record->pelem;
  v832->m_Items[184]->maxmp = loadDataVer7->dante_pelem.maxmp;
  v834 = (*data)->encyc_record->pelem;
  v834->m_Items[184]->exp = loadDataVer7->dante_pelem.exp;
  v836 = (*data)->encyc_record->pelem;
  v836->m_Items[184]->level = loadDataVer7->dante_pelem.level;
  v838 = (*data)->encyc_record->pelem;
  Copy_3886320(loadDataVer7->dante_pelem.param, v838->m_Items[184]->param, v838->m_Items[184]->param->max_length);
  v840 = (*data)->encyc_record->pelem;
  Copy_3886320(loadDataVer7->dante_pelem.skillparam, v840->m_Items[184]->skillparam, v840->m_Items[184]->skillparam->max_length);
  v842 = (*data)->encyc_record->pelem;
  v842->m_Items[184]->skillcnt = loadDataVer7->dante_pelem.skillcnt;
  v844 = (*data)->encyc_record->pelem;
  Copy_3886320(loadDataVer7->dante_pelem.skill, v844->m_Items[184]->skill, v844->m_Items[184]->skill->max_length);
  v846 = (*data)->encyc_record->pelem;
  Copy_3886320(loadDataVer7->dante_pelem.mitamaparam, v846->m_Items[184]->mitamaparam, v846->m_Items[184]->mitamaparam->max_length);
  v848 = (*data)->encyc_record->pelem;
  Copy_3886320(loadDataVer7->dante_pelem.levelupparam, v848->m_Items[184]->levelupparam, v848->m_Items[184]->levelupparam->max_length);
  v850 = (*data)->encyc_record->pelem;
  Copy_3886320(loadDataVer7->dante_pelem.keisyoskill, v850->m_Items[184]->keisyoskill, v850->m_Items[184]->keisyoskill->max_length);
  v852 = (*data)->encyc_record->pelem;
  Copy_3886320(loadDataVer7->dante_pelem.keiattr, v852->m_Items[184]->keiattr, v852->m_Items[184]->keiattr->max_length);
  v854 = (*data)->encyc_record->pelem;
  v854->m_Items[184]->hensinmae = loadDataVer7->dante_pelem.hensinmae;
  v856 = (*data)->encyc_record->pelem;
  v856->m_Items[184]->reserved1 = loadDataVer7->dante_pelem.reserved1;
  v858 = (*data)->encyc_record->pelem;
  v858->m_Items[184]->flag = loadDataVer7->dante_pelem.flag;
  v860 = (*data)->encyc_record->pelem;
  v860->m_Items[184]->reserved2 = loadDataVer7->dante_pelem.reserved2;
  v862 = (*data)->encyc_record->pelem;
  v862->m_Items[184]->hensinmaeexp = loadDataVer7->dante_pelem.hensinmaeexp;
  (*data)->GameFileInfo->saveTime = loadDataVer7->saveTime;
  autoMapOpen = (*data)->GameFileInfo->autoMapOpen;
  Copy_3886320(loadDataVer7->autoMapOpen, autoMapOpen, autoMapOpen->max_length);
  autoMapOpenEX = (*data)->GameFileInfo->autoMapOpenEX;
  Copy_3886320(loadDataVer7->autoMapOpenEX, autoMapOpenEX, autoMapOpenEX->max_length);
  RestoreFldRunWork(loadDataVer7->fldRunWork);
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
  if (!LODWORD(v6->max_length))
  {
LABEL_8:
  }
  while (1)
  {
    if (v6->m_Items[v7])
    {
      v10 = *data;
      if (v7 >= LODWORD((*data)->max_length))
        goto LABEL_11;
    }
    else
    {
      v28 = *data;
      v29 = Allocate(fldBlockBuff_t);
      fldBlockBuff_t___ctor(v29);
      *&v28[2 * v7 + 8] = v29;
      v10 = *data;
      if (v7 >= LODWORD((*data)->max_length))
      {
LABEL_11:
      }
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
      goto LABEL_8;
  }
}

// 0x189e3e0
void restoreSystem(SAVEDATA *this) {
  System_Array_o *dlcflg;
  struct System_SByte_array *v5;

  dlcflg = this->SystemBuff.dlcflg;
  else
  {
    v5 = this->SystemBuff.dlcflg;
  }
  Copy_3886320(dlcflg, SystemWork->dlcflg, v5->max_length);
  Copy_3886320(this->SystemBuff.dummy, SystemWork->dummy, this->SystemBuff.dummy->max_length);
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
