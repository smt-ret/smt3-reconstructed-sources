#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct sdfMovieCb_t sdfMovieCb_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;
typedef struct titleGlobal titleGlobal;

static s32 mainMenuIdxCnt;
static s32 mainMenuTextIdxCnt;
static s32 movieChangeflag;
static s32 dlcChackflag;
static s32 continueCursurflag;
static s32 fadeoutTime;
static s32 movTitleInitflag;
static void *modeobj;
static void *MainMenuObj;
static void *mainMenuCursur;
static sdfVector3_t mainMenuCursurPos;
static void *mainMenuCursur_r;
static char *mainMenuIdx_str;
static void *mainMenuIdx;
static sdfVector3_t mainMenuIdxPos;
static char *mainMenuText_str;
static void *mainMenu;
static void *mainMenuTM;
static char *mainMenuTextIdx_str;
static void *mainMenuTextIdx;
static void *mainMenuTextTM;
static void *TitleObj;
static void *titleobj;
static void *titleStartLogo;
static void *titleSprite[7];
static s32 titleStartInitflag;
static s32 titleStartLogoAnimflag;
static f32 titleStartLogoAnimtime;
static void *titleStartLogoAnim;
static s32 WarningCnt;
static u32 WarningFadeSpeed;
static bool Warningflag;
static void *WarningObj;
static s32 title2Pos;
static s32 title2flag;
static s32 title2mode;
static bool title2Posflag;
static bool MovieSkipflag;
static char *titleMainText[4];
static char *Lclstr;
static char *Lclstr_a;
static char *Dellcl[1];
static char *titleMainMenuText[7];
static char *titleMainMenuText_K[7];
static s32 titleMainInitflag;
static s32 titileMainCursorflag;
static s32 menuCursurCnt;
static char *titleMainHELPText[7];
static u8 dlcMesData[983];
static s32 dlcMsgNum;
static bool dlcMsgSave;
static void *DLCMsgFunc;
static dds3ProcessID_t *DLCMsgID;
static sdfMovieCb_t *dds3MovieCb;
static titleGlobal *gGlobal;
static s32 gGemeMode;
static f32 dds3DrawMenuString_cntf;
static f32 dds3DrawNameSprite_fcnt;
static s32 dds3TitleMain_mode;
static void *oMainmenu_UI;
static void *oA_logo_UI;
static void *oD_logo_UI;

void ButtonGuideDispOff(void);
void ButtonGuideDispSet(char *name, bool timer, bool empty, s32 waitTimer);
void ClearA_logoUI(void);
void ClearD_logoUI(void);
void ClearMainmenuUI(void);
bool DDS3_PADCHECK_PRESS(s32 id);
bool DDS3_PADCHECK_REP(s32 id);
bool DDS3_PADCHECK_TRIG(s32 id);
void FilterDelete(void);
s32 FindId(s32 type, char *name);
char *GetLocalizeText(char *ID);
char *GetPlatformStr(void);
void LoadLocalizeText(char *key, char *filename);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
void Remove(char *key);
char *RepColTag(char *txt, void **LegacyParamArray);
void aDrawBoxG(s32 x, s32 y, s32 w, s32 h, s32 r0, s32 g0, s32 b0, s32 a0, s32 r1, s32 g1, s32 b1, s32 a1, s32 r2, s32 g2, s32 b2, s32 a2, s32 r3, s32 g3, s32 b3, s32 a3);
void dds3AdminiCallSequence(s32 sequence, void *data, s32 datasize, s32 restore);
bool dds3CheckDLC1(void);
bool dds3CheckDLC2(void);
bool dds3CheckDLC3(void);
bool dds3CheckDLC4(void);
bool dds3CheckDLC5(void);
bool dds3CheckDLC6(void);
bool dds3CheckDLC7(void);
bool dds3CheckDLC8(void);
void dds3CheckPadInput(void);
void dds3CheckPadInput2(void);
void dds3DestroyTitleSprite(void);
void dds3DrawLogoSprite(void);
void dds3DrawMenuString(void);
void dds3DrawNameSprite(void);
s32 dds3FadeCheck(void);
void dds3FadeIn(u32 r, u32 g, u32 b, u32 frame);
void dds3FadeIn2(u32 frame);
void dds3FadeOut(u32 r, u32 g, u32 b, u32 frame);
void dds3InitTitleSprite(void);
s32 dds3KillProcessName(char *name, s32 shutdowntimer);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void dds3TitleInit(s32 mode);
void dlcMsgInit(void);
void dlcMsgLast(void);
s8 fclChkMessage(void);
s8 fclDestroyMessage(void);
s8 fclEndMessage(void);
s8 fclInitMessage(void *pData);
void fclSetMessageInvalid(s8 Mode);
s8 fclStartMessage(s32 MsgNo);
void fclUpdateMessage(void);
void fldAutoMapDelete(void);
void fldPlayerDelete(void);
s32 frame(void);
s32 movieCheckEnd(void);
s32 moviePlay(s32 aNum, s32 Layer);
void movieStop(void);
s32 p2sdFadeOut(s32 a);
s32 p2sdPlayBGM(s32 a);
s32 p2sdPlaySE(s32 a);
void rsetAlpha(s32 mode);
void rsetOtOfs(s32 otofs);
void rsetTest(s32 ate, s32 atst, s32 aref, s32 afail, s32 date, s32 datm, s32 zte, s32 ztst);
f32 sdfSin(f32 aRadius);
void sdfTexFree(sdfTexHandle_t *aHandle);
void slDLCMsgKill(void);
void *slDLCMsgProc(void);
s32 slGetInfo(void);
bool slSuspendDataCheck(void);
bool titleDLCMsgCheck(void);
bool titleDLCMsgDraw(void);
void titleMovePlayCheck(void);

// 0x10000f0
void ClearA_logoUI(void) {
  UnityEngine_Object_o *oA_logo_UI;
  UnityEngine_Object_o *v6;

  if (op_Inequality(oA_logo_UI, 0, 0))
  {
    v6 = oA_logo_UI;
    Destroy_27360000(v6);
    oA_logo_UI = 0;
  }
}

// 0x10001f0
void ClearD_logoUI(void) {
  UnityEngine_Object_o *oD_logo_UI;
  UnityEngine_Object_o *v6;

  if (op_Inequality(oD_logo_UI, 0, 0))
  {
    v6 = oD_logo_UI;
    Destroy_27360000(v6);
    oD_logo_UI = 0;
  }
}

// 0xfffff0
void ClearMainmenuUI(void) {
  UnityEngine_Object_o *oMainmenu_UI;
  UnityEngine_Object_o *v6;

  if (op_Inequality(oMainmenu_UI, 0, 0))
  {
    v6 = oMainmenu_UI;
    Destroy_27360000(v6);
    oMainmenu_UI = 0;
  }
}

// 0xffaa00
void *GetMainMenuUI(void) {
  return oMainmenu_UI;
}

// 0xffff10
void *GetoA_logoUI(void) {
  return oA_logo_UI;
}

// 0xffff80
void *GetoD_logoUI(void) {
  return oD_logo_UI;
}

// 0xff6a90
void dds3CheckPadInput(void) {
  struct titleGlobal_o *gGlobal;
  s32 pos;
  bool v17;
  dds3TitleMain_c *v18;
  bool v21;
  struct titleGlobal_o *v23;
  s32 v24;
  s32 v25;
  bool v26;
  struct titleGlobal_o *v27;
  struct titleGlobal_o *v28;
  struct titleGlobal_o *v29;

  if (DDS3_PADCHECK_REP(6))
    goto LABEL_6;
LABEL_67:
  v17 = DDS3_PADCHECK_REP(7);
  if (v17)
  {
    ++gGlobal->pos;
    p2sdPlaySE(0);
    v21 = dds3CheckDLC2();
    if (v21)
    {
      v23 = gGlobal;
      if (v23->pos != 1)
        goto LABEL_102;
      v24 = 2;
    }
    else
    {
      v25 = gGlobal->pos;
      if (v25 != 2)
      {
        if (v25 != 3)
          goto LABEL_102;
      }
      v23 = gGlobal;
      v24 = 4;
    }
    v23->pos = v24;
LABEL_102:
    v26 = slSuspendDataCheck();
    if (!v26)
    {
      v27 = gGlobal;
      if (v27->pos == 4)
      {
        v27->pos = 5;
      }
    }
    titileMainCursorflag = 0;
  }
  else
  {
    v28 = gGlobal;
    if ((v28->pos & 0x80000000) == 0)
      goto LABEL_121;
  }
  v28->pos = 7;
  if ((v18->_2.bitflags2 & 2) != 0)
  {
LABEL_122:
  }
LABEL_129:
  v29 = gGlobal;
  if (v29->pos >= 7)
  {
    v29->pos = 0;
  }
}

// 0xff70b0
void dds3CheckPadInput2(void) {
  struct titleGlobal_o *gGlobal;
  s32 pos;
  s32 v7;
  struct titleGlobal_o *v12;
  s32 v13;
  s32 v14;

  else if (!DDS3_PADCHECK_REP(6))
  {
    goto LABEL_30;
  }
  --gGlobal->pos;
  p2sdPlaySE(0);
  pos = gGlobal->pos;
  if (pos > 1)
  {
    if (pos != 4)
      goto LABEL_26;
    v7 = 3;
  }
  else
  {
    v7 = 6;
  }
  gGlobal->pos = v7;
LABEL_26:
  titileMainCursorflag = 0;
LABEL_30:
  else if (!DDS3_PADCHECK_REP(7))
  {
    return;
  }
  ++gGlobal->pos;
  p2sdPlaySE(0);
  v12 = gGlobal;
  v13 = v12->pos;
  if (v13 == 4)
  {
    v14 = 5;
  }
  else
  {
    if (v13 < 7)
      goto LABEL_53;
    v14 = 2;
  }
  v12->pos = v14;
LABEL_53:
  titileMainCursorflag = 0;
}

// 0xffb6c0
void dds3DestroyTitleSprite(void) {
  sdfTexHandle_t_o *LogoSpriteHandle;
  sdfTexHandle_t_o *TlogoSpriteHandle;
  sdfTexHandle_t_o *PressSpriteHandle;
  sdfTexHandle_t_o *Win1SpriteHandle;
  sdfTexHandle_t_o *Win1BSpriteHandle;

  LogoSpriteHandle = gGlobal->LogoSpriteHandle;
  if (LogoSpriteHandle)
  {
    sdfTexFree(LogoSpriteHandle);
    gGlobal->LogoSpriteHandle = 0;
  }
  TlogoSpriteHandle = gGlobal->TlogoSpriteHandle;
  if (TlogoSpriteHandle)
  {
    sdfTexFree(TlogoSpriteHandle);
    gGlobal->TlogoSpriteHandle = 0;
  }
  PressSpriteHandle = gGlobal->PressSpriteHandle;
  if (PressSpriteHandle)
  {
    sdfTexFree(PressSpriteHandle);
    gGlobal->PressSpriteHandle = 0;
  }
  Win1SpriteHandle = gGlobal->Win1SpriteHandle;
  if (Win1SpriteHandle)
  {
    sdfTexFree(Win1SpriteHandle);
    gGlobal->Win1SpriteHandle = 0;
  }
  Win1BSpriteHandle = gGlobal->Win1BSpriteHandle;
  if (Win1BSpriteHandle)
  {
    sdfTexFree(Win1BSpriteHandle);
    gGlobal->Win1BSpriteHandle = 0;
  }
}

// 0xffaa70
void dds3DrawLogoSprite(void) {
  s32 pressFadeinCnt;
  s32 v9;
  bool v10;
  s32 v11;
  s32 a2;
  s32 v16;
  s32 v17;
  s64 v18;
  u64 v19;
  s64 v20;
  s32 v21;
  struct UnityEngine_GameObject_array *titleSprite;
  Il2CppObject *Component_object;
  dds3TitleMain_c *v26;
  s64 v28;
  s64 v29;

  rsetAlpha(1);
  ++gGlobal->pressFadeinCnt;
  pressFadeinCnt = gGlobal->pressFadeinCnt;
  if (pressFadeinCnt < 50)
  {
    set_enabled(titleStartLogoAnim, 0);
      goto LABEL_29;
LABEL_27:
    goto LABEL_29;
  }
  set_enabled(titleStartLogoAnim, 1);
  if (pressFadeinCnt == 50)
  {
    Play_8777152(titleStartLogoAnim, "title_press", 0, 0.0);
  }
    goto LABEL_27;
LABEL_29:
  v9 = gGlobal->pressFadeinCnt;
  v10 = __OFSUB__(v9, 60);
  v11 = v9 - 60;
  if (v11 < 0 == v10)
  {
    if (v11 >= 16)
      v11 = 16;
    a2 = 3 * v11;
    aDrawBoxG(-300, 21, 812, 202, 35, 37, 86, 0, 35, 37, 86, 0, 35, 37, 86, a2, 35, 37, 86, 0);
  }
  rsetAlpha(0);
  v16 = gGlobal->pressFadeinCnt;
  v10 = __OFSUB__(v16, 50);
  v17 = v16 - 50;
  if (v17 < 0 == v10)
  {
    if (v17 >= 150)
      v17 = 150;
    v18 = 458129845LL * (v17 << 7);
    v19 = v18 >> 63;
    v20 = v18 >> 36;
    v21 = v20 + v19;
    Component_object = GetComponent_object_(titleSprite->m_Items[2]);
    v28 = 0;
    v29 = 0;
    sub_19EC630(&v28, 255.0, 255.0, 255.0, v21 / 60.0);
    (Component_object->klass->vtable[23].methodPtr)(
      Component_object,
      Component_object->klass->vtable[23].*&v28,
      *(&v28 + 1),
      *&v29,
      *(&v29 + 1));
  }
  rsetAlpha(1);
         v26 = dds3TitleMain,
  {
      goto LABEL_62;
  }
  else
  {
      goto LABEL_62;
  }
LABEL_62:
  rsetAlpha(0);
}

// 0xff73a0
void dds3DrawMenuString(void) {
  u64 v3;
  u64 v4;
  s16 v9;
  s32 v10;
  struct dds3TitleMain_StaticFields **p_static_fields;
  f32 v13;
  f32 v15;
  s32 a3;
  f32 dds3DrawMenuString_cntf;
  f32 v19;
  s64 v20;
  s32 pos;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v23;
  struct UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v30;
  UnityEngine_Component_o *v31;
  struct UnityEngine_GameObject_o *v32;
  Il2CppObject *Component_object;
  Il2CppObject *v36;
  u64 *v38;
  System_String_o *v39;
  struct System_String_o *v40;
  UnityEngine_Transform_o *v42;
  UnityEngine_Component_o *v43;
  struct UnityEngine_GameObject_o *v44;
  Il2CppObject *v46;
  dds3TitleMain_c *v48;
  s32 v50;
  struct titleGlobal_o *gGlobal;
  s64 v55;
  s32 v56;
  u64 v57;
  u64 *v58;
  System_String_o *v59;
  struct System_String_o *v60;
  UnityEngine_Transform_o *v62;
  UnityEngine_Component_o *v63;
  struct UnityEngine_GameObject_o *v64;
  Il2CppObject *v67;
  struct System_String_array *titleMainMenuText;
  TMPro_TMP_Text_o *mainMenuTM;
  System_String_o *v73;
  System_String_o *LocalizeText;
  System_Object_array *v75;
  struct System_String_array *v76;
  System_String_o *v78;
  s64 *v79;
  s64 *v81;
  System_String_o *v84;
  u32 v86;
  u64 *v87;
  System_String_o *v88;
  struct System_String_o *v89;
  UnityEngine_Transform_o *v91;
  UnityEngine_Component_o *v92;
  struct UnityEngine_GameObject_o *v93;
  Il2CppObject *v96;
  u64 *v99;
  System_String_o *v100;
  struct System_String_o *v101;
  UnityEngine_Transform_o *v103;
  UnityEngine_Component_o *v104;
  struct UnityEngine_GameObject_o *v105;
  u64 *v110;
  System_String_o *v111;
  struct System_String_o *v112;
  UnityEngine_Transform_o *v114;
  UnityEngine_Component_o *v115;
  struct UnityEngine_GameObject_o *v116;
  s32 v122;
  u64 *v123;
  System_String_o *v124;
  struct System_String_o *v125;
  UnityEngine_Transform_o *v127;
  UnityEngine_Component_o *v128;
  struct UnityEngine_GameObject_o *v129;
  bool v134;
  u64 *v136;
  System_String_o *v137;
  struct System_String_o *v138;
  UnityEngine_Transform_o *v140;
  UnityEngine_Component_o *v141;
  struct UnityEngine_GameObject_o *v142;
  u64 *v147;
  System_String_o *v148;
  struct System_String_o *v149;
  UnityEngine_Transform_o *v151;
  UnityEngine_Component_o *v152;
  struct UnityEngine_GameObject_o *v153;
  bool v158;
  u64 *v161;
  System_String_o *v162;
  struct System_String_o *v163;
  UnityEngine_Transform_o *v165;
  UnityEngine_Component_o *v166;
  struct UnityEngine_GameObject_o *v167;
  UnityEngine_GameObject_o *mainMenuIdx;
  bool v172;
  dds3TitleMain_c *v173;
  struct System_String_array *v175;
  struct System_String_array *titleMainHELPText;
  System_String_o *v179;
  System_String_o *v180;
  struct System_String_array *v182;
  dds3TitleMain_c *v183;
  s64 v184;
  s32 v185;
  u64 v186;
  struct System_String_array *Lclstr;
  u64 max_length_low;
  u32 *v190;
  s64 *v192;
  u32 *Lclstr_a;
  s64 *v196;
  u64 *v201;
  System_String_o *v202;
  struct System_String_o *v203;
  UnityEngine_Transform_o *v205;
  UnityEngine_Component_o *v206;
  struct UnityEngine_GameObject_o *v207;
  Il2CppObject *v209;
  struct System_String_array *v212;
  TMPro_TMP_Text_o *mainMenuTextTM;
  System_String_o *v215;
  System_Object_array *v216;
  s64 *v217;
  s64 *v219;
  System_String_o *v222;
  u32 v223;
  Il2CppObject *v224;
  struct System_String_array *v226;
  struct System_String_array *v228;
  System_String_o *v230;
  System_String_o *v231;
  struct System_String_array *v233;
  dds3TitleMain_c *v234;
  s64 v235;
  s32 v236;
  u64 v237;
  struct System_String_array *v239;
  u64 v240;
  u32 *v241;
  s64 *v243;
  u32 *v246;
  s64 *v247;
  u64 *v252;
  System_String_o *v253;
  struct System_String_o *v254;
  UnityEngine_Transform_o *v256;
  UnityEngine_Component_o *v257;
  struct UnityEngine_GameObject_o *v258;
  Il2CppObject *v260;
  struct System_String_array *v263;
  TMPro_TMP_Text_o *v264;
  System_String_o *v266;
  System_Object_array *v267;
  s64 *v268;
  s64 *v270;
  System_String_o *v273;
  u32 v274;
  Il2CppObject *v275;
  struct System_String_array *v277;
  struct System_String_array *v279;
  System_String_o *v281;
  System_String_o *v282;
  struct System_String_array *v284;
  dds3TitleMain_c *v285;
  s64 v286;
  s32 v287;
  u64 v288;
  struct System_String_array *v290;
  u64 v291;
  u32 *v292;
  s64 *v294;
  u32 *v297;
  s64 *v298;
  u64 *v303;
  System_String_o *v304;
  struct System_String_o *v305;
  UnityEngine_Transform_o *v307;
  UnityEngine_Component_o *v308;
  struct UnityEngine_GameObject_o *v309;
  Il2CppObject *v311;
  struct System_String_array *v314;
  TMPro_TMP_Text_o *v315;
  System_String_o *v317;
  System_Object_array *v318;
  s64 *v319;
  s64 *v321;
  System_String_o *v324;
  u32 v325;
  Il2CppObject *v326;
  struct System_String_array *v328;
  struct System_String_array *v330;
  System_String_o *v332;
  System_String_o *v333;
  struct System_String_array *v335;
  dds3TitleMain_c *v336;
  s64 v337;
  s32 v338;
  u64 v339;
  struct System_String_array *v341;
  u64 v342;
  u32 *v343;
  s64 *v345;
  u32 *v348;
  s64 *v349;
  u64 *v354;
  System_String_o *v355;
  struct System_String_o *v356;
  UnityEngine_Transform_o *v358;
  UnityEngine_Component_o *v359;
  struct UnityEngine_GameObject_o *v360;
  Il2CppObject *v362;
  struct System_String_array *v365;
  TMPro_TMP_Text_o *v366;
  System_String_o *v368;
  System_Object_array *v369;
  s64 *v370;
  s64 *v372;
  System_String_o *v375;
  u32 v376;
  Il2CppObject *v377;
  struct System_String_array *v379;
  struct System_String_array *v381;
  System_String_o *v383;
  System_String_o *v384;
  struct System_String_array *v386;
  dds3TitleMain_c *v387;
  s64 v388;
  s32 v389;
  u64 v390;
  struct System_String_array *v392;
  u64 v393;
  u32 *v394;
  s64 *v396;
  u32 *v399;
  s64 *v400;
  u64 *v405;
  System_String_o *v406;
  struct System_String_o *v407;
  UnityEngine_Transform_o *v409;
  UnityEngine_Component_o *v410;
  struct UnityEngine_GameObject_o *v411;
  Il2CppObject *v413;
  struct System_String_array *v416;
  TMPro_TMP_Text_o *v417;
  System_String_o *v419;
  System_Object_array *v420;
  s64 *v421;
  s64 *v423;
  System_String_o *v426;
  u32 v427;
  Il2CppObject *v428;
  struct System_String_array *v430;
  struct System_String_array *v432;
  System_String_o *v434;
  System_String_o *v435;
  struct System_String_array *v437;
  dds3TitleMain_c *v438;
  s64 v439;
  s32 v440;
  u64 v441;
  struct System_String_array *v443;
  u64 v444;
  u32 *v445;
  s64 *v447;
  u32 *v450;
  s64 *v451;
  u64 *v456;
  System_String_o *v457;
  struct System_String_o *v458;
  UnityEngine_Transform_o *v460;
  UnityEngine_Component_o *v461;
  struct UnityEngine_GameObject_o *v462;
  Il2CppObject *v464;
  struct System_String_array *v467;
  TMPro_TMP_Text_o *v468;
  System_String_o *v470;
  System_Object_array *v471;
  s64 *v472;
  s64 *v474;
  System_String_o *v477;
  u32 v478;
  Il2CppObject *v479;
  struct System_String_array *v481;
  struct System_String_array *v483;
  System_String_o *v485;
  System_String_o *v486;
  struct System_String_array *v488;
  dds3TitleMain_c *v489;
  s64 v490;
  s32 v491;
  u64 v492;
  struct System_String_array *v494;
  u64 v495;
  u32 *v496;
  s64 *v498;
  u32 *v501;
  s64 *v502;
  u64 *v507;
  System_String_o *v508;
  struct System_String_o *v509;
  UnityEngine_Transform_o *v511;
  UnityEngine_Component_o *v512;
  struct UnityEngine_GameObject_o *v513;
  Il2CppObject *v515;
  struct System_String_array *v518;
  TMPro_TMP_Text_o *v519;
  System_String_o *v521;
  System_Object_array *v522;
  s64 *v523;
  s64 *v525;
  System_String_o *v528;
  u32 v529;
  Il2CppObject *v530;
  s32 v540;
  s32 mainMenuIdxCnt;
  UnityEngine_Vector3_o position;
  UnityEngine_Vector3_o v543;

LABEL_7:
  MainMenuObj = oMainmenu_UI;
  rsetOtOfs(72);
  rsetAlpha(0);
  rsetTest(1, 0, 128, 3, 0, 0, 1, 1);
  rsetAlpha(1);
  aDrawBoxG(0, 0, 190, 190, 37, 39, 84, 61, 37, 39, 84, 0, 37, 39, 84, 0, 37, 39, 84, 0);
  rsetAlpha(0);
  v3 = 715827883LL * (gGlobal->menucnt << 7);
  aDrawBoxG(
    0,
    28,
    256,
    72,
    0,
    0,
    0,
    (v3 >> 63) + (SHIDWORD(v3) >> 2),
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    (v3 >> 63) + (SHIDWORD(v3) >> 2),
    0);
  v4 = 82320206545LL * gGlobal->menucnt;
  aDrawBoxG(
    196,
    28,
    316,
    72,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    (v4 >> 63) + (SHIDWORD(v4) >> 2),
    0,
    0,
    0,
    (v4 >> 63) + (SHIDWORD(v4) >> 2),
    0,
    0,
    0,
    0,
    0);
  if (gGlobal->menucnt >= 12)
  {
    rsetAlpha(1);
    if ((v9 & 0x200) != 0)
    {
      v10 = v9 & 0x200;
    }
    else
    {
      v10 = 0;
    }
    if (gGlobal->menucnt <= 23)
    {
      v19 = sdfSin(dds3DrawMenuString_cntf);
      v20 = 715827883LL
          * (gGlobal->menucnt - 12)
          * (((v19 * 20.0) + 10.0) + 92);
      a3 = (v20 >> 33) + (v20 >> 63);
        goto LABEL_39;
    }
    else
    {
      dds3DrawMenuString_cntf = dds3DrawMenuString_cntf + 0.15;
      v13 = (*p_static_fields)->dds3DrawMenuString_cntf;
      v15 = sdfSin(v13);
      a3 = ((v15 * 20.0) + 10.0) + 92;
        goto LABEL_39;
    }
LABEL_39:
    pos = gGlobal->pos;
    aDrawBoxG(0, 15 * pos + 36, 223, 11, 0, 0, 128, a3, 64, 0, 128, 1, 96, 0, 128, 1, 32, 0, 128, a3);
    rsetAlpha(0);
  }
  transform = get_transform(MainMenuObj, 0);
  v23 = Find(transform, "titlemain", 0);
  gameObject = get_gameObject(v23);
  modeobj = gameObject;
  if (gGlobal->step == 19)
  {
    if (!get_activeSelf(modeobj))
    {
      SetActive(modeobj, 1, 0);
    }
  }
  v30 = get_transform(MainMenuObj, 0);
  v31 = Find(v30, "titlemain/titlemain_cursur", 0);
  v32 = get_gameObject(v31);
  mainMenuCursur = v32;
  Component_object = GetComponent_object_(mainMenuCursur);
  position = get_position(Component_object);
  mainMenuCursurPos = position;
  v36 = GetComponent_object_(mainMenuCursur);
  mainMenuCursur_r = v36;
  v38 = sub_8D3950(s32, &mainMenuIdxCnt);
  v39 = Format("titlemain_item{0:00}", v38, 0);
  v40 = Concat_5224608("titlemain/titlemainmenu/stretch/", v39);
  mainMenuIdx_str = v40;
  v42 = get_transform(MainMenuObj, 0);
  v43 = Find(v42, mainMenuIdx_str, 0);
  v44 = get_gameObject(v43);
  mainMenuIdx = v44;
  v46 = GetComponent_object_(mainMenuIdx);
  v543 = get_position(v46);
  mainMenuIdxPos = v543;
  if (!titleMainInitflag)
  {
    if ((*&v48->_2.bitflags1 & 0x200) != 0)
    {
      else
      {
        if (title2flag)
          goto LABEL_61;
      }
    }
    else
    {
      v50 = 0;
      if (title2flag)
      {
LABEL_61:
        else if (title2Posflag)
        {
          goto LABEL_64;
        }
        title2Posflag = 1;
        if ((v48->_2.bitflags2 & 2) == 0)
          goto LABEL_82;
        goto LABEL_73;
      }
    }
    if (!v50)
      goto LABEL_72;
    goto LABEL_65;
  }
LABEL_94:
  else
  {
    if (titileMainCursorflag)
      goto LABEL_97;
  }
  mainMenuIdxCnt = 1;
  v55 = 4;
  do
  {
    v57 = v55 - 4;
    v58 = sub_8D3950(s32, &mainMenuIdxCnt);
    v59 = Format("titlemain_item{0:00}/slide/Text_TM", v58, 0);
    v60 = Concat_5224608("titlemain/titlemainmenu/stretch/", v59);
    mainMenuText_str = v60;
    v62 = get_transform(MainMenuObj, 0);
    v63 = Find(v62, mainMenuText_str, 0);
    v64 = get_gameObject(v63);
    mainMenu = v64;
    v67 = GetComponent_object_(mainMenu);
    mainMenuTM = v67;
    if (v57 == gGlobal->pos)
    {
      v73 = *(&titleMainMenuText->obj.klass + v55);
      LocalizeText = GetLocalizeText(v73);
      v75 = NewSpecific(object, 1u);
      mainMenuIdxCnt = 0;
    }
    else
    {
      v76 = titleMainMenuText;
      v78 = *(&v76->obj.klass + v55);
      LocalizeText = GetLocalizeText(v78);
      v75 = NewSpecific(object, 1u);
      mainMenuIdxCnt = 15;
    }
    v79 = sub_8D3950(s32, &mainMenuIdxCnt);
    v81 = v79;
    v75->m_Items[0] = v81;
    v84 = RepColTag(LocalizeText, v75);
    set_text(mainMenuTM, v84);
    ++mainMenuIdxCnt;
    ++v55;
    v56 = (v86 >> 9) & 1;
  }
  while (v55 != 11);
  mainMenuIdxCnt = menuCursurCnt;
  titileMainCursorflag = 1;
  if ((v48->_2.bitflags2 & 2) != 0)
  {
LABEL_98:
  }
LABEL_143:
  mainMenuIdxCnt = mainMenuTextIdxCnt;
  v87 = sub_8D3950(s32, &mainMenuIdxCnt);
  v88 = Format("Text_mainnote{0:00}TM", v87, 0);
  v89 = Concat_5224608("titlemain/titlemain_note/", v88);
  mainMenuTextIdx_str = v89;
  v91 = get_transform(MainMenuObj, 0);
  v92 = Find(v91, mainMenuTextIdx_str, 0);
  v93 = get_gameObject(v92);
  mainMenuTextIdx = v93;
  v96 = GetComponent_object_(mainMenuTextIdx);
  mainMenuTextTM = v96;
  if (title2flag)
  {
    mainMenuIdxCnt = 1;
    v99 = sub_8D3950(s32, &mainMenuIdxCnt);
    v100 = Format("titlemain_item{0:00}", v99, 0);
    v101 = Concat_5224608("titlemain/titlemainmenu/stretch/", v100);
    mainMenuIdx_str = v101;
    v103 = get_transform(MainMenuObj, 0);
    v104 = Find(v103, mainMenuIdx_str, 0);
    v105 = get_gameObject(v104);
    mainMenuIdx = v105;
    if (get_activeSelf(mainMenuIdx))
    {
      SetActive(mainMenuIdx, 0, 0);
    }
    mainMenuIdxCnt = 2;
    v110 = sub_8D3950(s32, &mainMenuIdxCnt);
    v111 = Format("titlemain_item{0:00}", v110, 0);
    v112 = Concat_5224608("titlemain/titlemainmenu/stretch/", v111);
    mainMenuIdx_str = v112;
    v114 = get_transform(MainMenuObj, 0);
    v115 = Find(v114, mainMenuIdx_str, 0);
    v116 = get_gameObject(v115);
    mainMenuIdx = v116;
    if (get_activeSelf(mainMenuIdx))
    {
      SetActive(mainMenuIdx, 0, 0);
    }
    v122 = 5;
  }
  else
  {
    mainMenuIdxCnt = 1;
    v123 = sub_8D3950(s32, &mainMenuIdxCnt);
    v124 = Format("titlemain_item{0:00}", v123, 0);
    v125 = Concat_5224608("titlemain/titlemainmenu/stretch/", v124);
    mainMenuIdx_str = v125;
    v127 = get_transform(MainMenuObj, 0);
    v128 = Find(v127, mainMenuIdx_str, 0);
    v129 = get_gameObject(v128);
    mainMenuIdx = v129;
    if (!get_activeSelf(mainMenuIdx))
    {
      SetActive(mainMenuIdx, 1, 0);
    }
    v134 = dds3CheckDLC2();
    if (v134)
    {
      v122 = 2;
    }
    else
    {
      mainMenuIdxCnt = 3;
      v136 = sub_8D3950(s32, &mainMenuIdxCnt);
      v137 = Format("titlemain_item{0:00}", v136, 0);
      v138 = Concat_5224608("titlemain/titlemainmenu/stretch/", v137);
      mainMenuIdx_str = v138;
      v140 = get_transform(MainMenuObj, 0);
      v141 = Find(v140, mainMenuIdx_str, 0);
      v142 = get_gameObject(v141);
      mainMenuIdx = v142;
      if (get_activeSelf(mainMenuIdx))
      {
        SetActive(mainMenuIdx, 0, 0);
      }
      v122 = 4;
    }
  }
  mainMenuIdxCnt = v122;
  v147 = sub_8D3950(s32, &mainMenuIdxCnt);
  v148 = Format("titlemain_item{0:00}", v147, 0);
  v149 = Concat_5224608("titlemain/titlemainmenu/stretch/", v148);
  mainMenuIdx_str = v149;
  v151 = get_transform(MainMenuObj, 0);
  v152 = Find(v151, mainMenuIdx_str, 0);
  v153 = get_gameObject(v152);
  mainMenuIdx = v153;
  if (get_activeSelf(mainMenuIdx))
  {
    SetActive(mainMenuIdx, 0, 0);
  }
  v158 = slSuspendDataCheck();
  if (!v158)
    goto LABEL_204;
  if (!title2flag)
    goto LABEL_611;
LABEL_204:
  mainMenuIdxCnt = 5;
  v161 = sub_8D3950(s32, &mainMenuIdxCnt);
  v162 = Format("titlemain_item{0:00}", v161, 0);
  v163 = Concat_5224608("titlemain/titlemainmenu/stretch/", v162);
  mainMenuIdx_str = v163;
  v165 = get_transform(MainMenuObj, 0);
  v166 = Find(v165, mainMenuIdx_str, 0);
  v167 = get_gameObject(v166);
  mainMenuIdx = v167;
  if (!get_activeSelf(mainMenuIdx))
    goto LABEL_213;
  v172 = 0;
LABEL_212:
  SetActive(mainMenuIdx, v172, 0);
LABEL_213:
         v173 = dds3TitleMain,
  {
    if (gGlobal->pos)
    {
LABEL_218:
      if ((v173->_2.bitflags2 & 2) == 0)
        goto LABEL_275;
      goto LABEL_219;
    }
  }
  else if (gGlobal->pos)
  {
    goto LABEL_218;
  }
  v175 = NewSpecific(string, 4u);
  Lclstr_a = v175;
  v179 = titleMainHELPText->m_Items[0];
  v180 = GetLocalizeText(v179);
  v182 = Split_5246672(v180, Dellcl, 0);
  Lclstr = v182;
  v184 = 4;
  v185 = (v183->_2.bitflags2 >> 1) & 1;
  do
  {
    v186 = v184 - 4;
    max_length_low = LODWORD(Lclstr->max_length);
    if (v186 >= max_length_low)
    {
      else
      {
        v196 = "";
        if (!"")
          goto LABEL_257;
      }
LABEL_257:
      *&Lclstr_a[2 * v184] = "";
        goto LABEL_246;
      goto LABEL_260;
    }
    else
    {
      v190 = Lclstr_a;
      if (v186 >= max_length_low)
        goto LABEL_240;
    }
    v192 = *(&Lclstr->obj.klass + v184);
    *&v190[2 * v184] = v192;
    {
LABEL_246:
    }
LABEL_260:
    mainMenuIdxCnt = mainMenuTextIdxCnt;
    v201 = sub_8D3950(s32, &mainMenuIdxCnt);
    v202 = Format("Text_mainnote{0:00}TM", v201, 0);
    v203 = Concat_5224608("titlemain/titlemain_note/", v202);
    mainMenuTextIdx_str = v203;
    v205 = get_transform(MainMenuObj, 0);
    v206 = Find(v205, mainMenuTextIdx_str, 0);
    v207 = get_gameObject(v206);
    mainMenuTextIdx = v207;
    v209 = GetComponent_object_(mainMenuTextIdx);
    mainMenuTextTM = v209;
    v212 = Lclstr_a;
    v215 = *(&v212->obj.klass + v184);
    v216 = NewSpecific(object, 1u);
    v540 = 0;
    v217 = sub_8D3950(s32, &v540);
    v219 = v217;
    v216->m_Items[0] = v219;
    v222 = RepColTag(v215, v216);
    set_text(mainMenuTextTM, v222);
    ++mainMenuTextIdxCnt;
    ++v184;
    v185 = (v223 >> 9) & 1;
  }
  while (v184 != 8);
  mainMenuIdxCnt = 1;
  mainMenuTextIdxCnt = 1;
  v224 = GetComponent_object_(mainMenuCursur);
  set_position(v224, mainMenuIdxPos);
  {
LABEL_219:
          v173 = dds3TitleMain,
    {
    }
  }
LABEL_275:
  if (gGlobal->pos != 1)
    goto LABEL_327;
  v226 = NewSpecific(string, 4u);
  Lclstr_a = v226;
  v228 = titleMainHELPText;
  v230 = v228->m_Items[1];
  v231 = GetLocalizeText(v230);
  v233 = Split_5246672(v231, Dellcl, 0);
  Lclstr = v233;
  v235 = 4;
  v236 = (v234->_2.bitflags2 >> 1) & 1;
  while (2)
  {
    v237 = v235 - 4;
    v239 = Lclstr;
    v240 = LODWORD(v239->max_length);
    if (v237 >= v240)
    {
      else
      {
        v246 = Lclstr_a;
        v247 = "";
        if (!"")
          goto LABEL_309;
      }
LABEL_309:
      *&v246[2 * v235] = "";
        goto LABEL_298;
      goto LABEL_312;
    }
    else
    {
      v241 = Lclstr_a;
      if (v237 >= v240)
        goto LABEL_292;
    }
    v243 = *(&v239->obj.klass + v235);
    *&v241[2 * v235] = v243;
    {
LABEL_298:
    }
LABEL_312:
    mainMenuIdxCnt = mainMenuTextIdxCnt;
    v252 = sub_8D3950(s32, &mainMenuIdxCnt);
    v253 = Format("Text_mainnote{0:00}TM", v252, 0);
    v254 = Concat_5224608("titlemain/titlemain_note/", v253);
    mainMenuTextIdx_str = v254;
    v256 = get_transform(MainMenuObj, 0);
    v257 = Find(v256, mainMenuTextIdx_str, 0);
    v258 = get_gameObject(v257);
    mainMenuTextIdx = v258;
    v260 = GetComponent_object_(mainMenuTextIdx);
    mainMenuTextTM = v260;
    v263 = Lclstr_a;
    v264 = mainMenuTextTM;
    v266 = *(&v263->obj.klass + v235);
    v267 = NewSpecific(object, 1u);
    v540 = 0;
    v268 = sub_8D3950(s32, &v540);
    v270 = v268;
    v267->m_Items[0] = v270;
    v273 = RepColTag(v266, v267);
    set_text(v264, v273);
    ++mainMenuTextIdxCnt;
    ++v235;
    v236 = (v274 >> 9) & 1;
    if (v235 != 8)
      continue;
    break;
  }
  mainMenuIdxCnt = 2;
  mainMenuTextIdxCnt = 1;
  v275 = GetComponent_object_(mainMenuCursur);
  set_position(v275, mainMenuIdxPos);
LABEL_327:
  if ((v173->_2.bitflags2 & 2) != 0)
  {
          v173 = dds3TitleMain,
    {
    }
  }
  if (gGlobal->pos == 2)
  {
    v277 = NewSpecific(string, 4u);
    Lclstr_a = v277;
    v279 = titleMainHELPText;
    v281 = v279->m_Items[2];
    v282 = GetLocalizeText(v281);
    v284 = Split_5246672(v282, Dellcl, 0);
    Lclstr = v284;
    v286 = 4;
    v287 = (v285->_2.bitflags2 >> 1) & 1;
    while (1)
    {
      v288 = v286 - 4;
      v290 = Lclstr;
      v291 = LODWORD(v290->max_length);
      if (v288 >= v291)
        break;
      else
      {
        v292 = Lclstr_a;
        if (v288 >= v291)
          goto LABEL_349;
      }
      v294 = *(&v290->obj.klass + v286);
      *&v292[2 * v286] = v294;
        goto LABEL_369;
LABEL_355:
LABEL_369:
      mainMenuIdxCnt = mainMenuTextIdxCnt;
      v303 = sub_8D3950(s32, &mainMenuIdxCnt);
      v304 = Format("Text_mainnote{0:00}TM", v303, 0);
      v305 = Concat_5224608("titlemain/titlemain_note/", v304);
      mainMenuTextIdx_str = v305;
      v307 = get_transform(MainMenuObj, 0);
      v308 = Find(v307, mainMenuTextIdx_str, 0);
      v309 = get_gameObject(v308);
      mainMenuTextIdx = v309;
      v311 = GetComponent_object_(mainMenuTextIdx);
      mainMenuTextTM = v311;
      v314 = Lclstr_a;
      v315 = mainMenuTextTM;
      v317 = *(&v314->obj.klass + v286);
      v318 = NewSpecific(object, 1u);
      v540 = 0;
      v319 = sub_8D3950(s32, &v540);
      v321 = v319;
      v318->m_Items[0] = v321;
      v324 = RepColTag(v317, v318);
      set_text(v315, v324);
      ++mainMenuTextIdxCnt;
      ++v286;
      v287 = (v325 >> 9) & 1;
      if (v286 == 8)
      {
        mainMenuIdxCnt = 3;
        mainMenuTextIdxCnt = 1;
        v326 = GetComponent_object_(mainMenuCursur);
        set_position(v326, mainMenuIdxPos);
        goto LABEL_384;
      }
    }
    else
    {
      v297 = Lclstr_a;
      v298 = "";
      if ("")
      {
LABEL_360:
      }
    }
    *&v297[2 * v286] = "";
      goto LABEL_369;
    goto LABEL_355;
  }
LABEL_384:
  if ((v173->_2.bitflags2 & 2) != 0)
  {
          v173 = dds3TitleMain,
    {
    }
  }
  if (gGlobal->pos == 3)
  {
    v328 = NewSpecific(string, 4u);
    Lclstr_a = v328;
    v330 = titleMainHELPText;
    v332 = v330->m_Items[3];
    v333 = GetLocalizeText(v332);
    v335 = Split_5246672(v333, Dellcl, 0);
    Lclstr = v335;
    v337 = 4;
    v338 = (v336->_2.bitflags2 >> 1) & 1;
    while (1)
    {
      v339 = v337 - 4;
      v341 = Lclstr;
      v342 = LODWORD(v341->max_length);
      if (v339 >= v342)
        break;
      else
      {
        v343 = Lclstr_a;
        if (v339 >= v342)
          goto LABEL_406;
      }
      v345 = *(&v341->obj.klass + v337);
      *&v343[2 * v337] = v345;
        goto LABEL_426;
LABEL_412:
LABEL_426:
      mainMenuIdxCnt = mainMenuTextIdxCnt;
      v354 = sub_8D3950(s32, &mainMenuIdxCnt);
      v355 = Format("Text_mainnote{0:00}TM", v354, 0);
      v356 = Concat_5224608("titlemain/titlemain_note/", v355);
      mainMenuTextIdx_str = v356;
      v358 = get_transform(MainMenuObj, 0);
      v359 = Find(v358, mainMenuTextIdx_str, 0);
      v360 = get_gameObject(v359);
      mainMenuTextIdx = v360;
      v362 = GetComponent_object_(mainMenuTextIdx);
      mainMenuTextTM = v362;
      v365 = Lclstr_a;
      v366 = mainMenuTextTM;
      v368 = *(&v365->obj.klass + v337);
      v369 = NewSpecific(object, 1u);
      v540 = 0;
      v370 = sub_8D3950(s32, &v540);
      v372 = v370;
      v369->m_Items[0] = v372;
      v375 = RepColTag(v368, v369);
      set_text(v366, v375);
      ++mainMenuTextIdxCnt;
      ++v337;
      v338 = (v376 >> 9) & 1;
      if (v337 == 8)
      {
        mainMenuIdxCnt = 4;
        mainMenuTextIdxCnt = 1;
        v377 = GetComponent_object_(mainMenuCursur);
        set_position(v377, mainMenuIdxPos);
        goto LABEL_441;
      }
    }
    else
    {
      v348 = Lclstr_a;
      v349 = "";
      if ("")
      {
LABEL_417:
      }
    }
    *&v348[2 * v337] = "";
      goto LABEL_426;
    goto LABEL_412;
  }
LABEL_441:
  if (gGlobal->pos == 4)
  {
    v379 = NewSpecific(string, 4u);
    Lclstr_a = v379;
    v381 = titleMainHELPText;
    v383 = v381->m_Items[4];
    v384 = GetLocalizeText(v383);
    v386 = Split_5246672(v384, Dellcl, 0);
    Lclstr = v386;
    v388 = 4;
    v389 = (v387->_2.bitflags2 >> 1) & 1;
    while (1)
    {
      v390 = v388 - 4;
      v392 = Lclstr;
      v393 = LODWORD(v392->max_length);
      if (v390 >= v393)
        break;
      else
      {
        v394 = Lclstr_a;
        if (v390 >= v393)
          goto LABEL_461;
      }
      v396 = *(&v392->obj.klass + v388);
      *&v394[2 * v388] = v396;
        goto LABEL_481;
LABEL_467:
LABEL_481:
      mainMenuIdxCnt = mainMenuTextIdxCnt;
      v405 = sub_8D3950(s32, &mainMenuIdxCnt);
      v406 = Format("Text_mainnote{0:00}TM", v405, 0);
      v407 = Concat_5224608("titlemain/titlemain_note/", v406);
      mainMenuTextIdx_str = v407;
      v409 = get_transform(MainMenuObj, 0);
      v410 = Find(v409, mainMenuTextIdx_str, 0);
      v411 = get_gameObject(v410);
      mainMenuTextIdx = v411;
      v413 = GetComponent_object_(mainMenuTextIdx);
      mainMenuTextTM = v413;
      v416 = Lclstr_a;
      v417 = mainMenuTextTM;
      v419 = *(&v416->obj.klass + v388);
      v420 = NewSpecific(object, 1u);
      v540 = 0;
      v421 = sub_8D3950(s32, &v540);
      v423 = v421;
      v420->m_Items[0] = v423;
      v426 = RepColTag(v419, v420);
      set_text(v417, v426);
      ++mainMenuTextIdxCnt;
      ++v388;
      v389 = (v427 >> 9) & 1;
      if (v388 == 8)
      {
        mainMenuIdxCnt = 5;
        mainMenuTextIdxCnt = 1;
        v428 = GetComponent_object_(mainMenuCursur);
        set_position(v428, mainMenuIdxPos);
        goto LABEL_496;
      }
    }
    else
    {
      v399 = Lclstr_a;
      v400 = "";
      if ("")
      {
LABEL_472:
      }
    }
    *&v399[2 * v388] = "";
      goto LABEL_481;
    goto LABEL_467;
  }
LABEL_496:
  if (gGlobal->pos == 5)
  {
    v430 = NewSpecific(string, 4u);
    Lclstr_a = v430;
    v432 = titleMainHELPText;
    v434 = v432->m_Items[5];
    v435 = GetLocalizeText(v434);
    v437 = Split_5246672(v435, Dellcl, 0);
    Lclstr = v437;
    v439 = 4;
    v440 = (v438->_2.bitflags2 >> 1) & 1;
    while (1)
    {
      v441 = v439 - 4;
      v443 = Lclstr;
      v444 = LODWORD(v443->max_length);
      if (v441 >= v444)
        break;
      else
      {
        v445 = Lclstr_a;
        if (v441 >= v444)
          goto LABEL_516;
      }
      v447 = *(&v443->obj.klass + v439);
      *&v445[2 * v439] = v447;
        goto LABEL_536;
LABEL_522:
LABEL_536:
      mainMenuIdxCnt = mainMenuTextIdxCnt;
      v456 = sub_8D3950(s32, &mainMenuIdxCnt);
      v457 = Format("Text_mainnote{0:00}TM", v456, 0);
      v458 = Concat_5224608("titlemain/titlemain_note/", v457);
      mainMenuTextIdx_str = v458;
      v460 = get_transform(MainMenuObj, 0);
      v461 = Find(v460, mainMenuTextIdx_str, 0);
      v462 = get_gameObject(v461);
      mainMenuTextIdx = v462;
      v464 = GetComponent_object_(mainMenuTextIdx);
      mainMenuTextTM = v464;
      v467 = Lclstr_a;
      v468 = mainMenuTextTM;
      v470 = *(&v467->obj.klass + v439);
      v471 = NewSpecific(object, 1u);
      v540 = 0;
      v472 = sub_8D3950(s32, &v540);
      v474 = v472;
      v471->m_Items[0] = v474;
      v477 = RepColTag(v470, v471);
      set_text(v468, v477);
      ++mainMenuTextIdxCnt;
      ++v439;
      v440 = (v478 >> 9) & 1;
      if (v439 == 8)
      {
        mainMenuIdxCnt = 6;
        mainMenuTextIdxCnt = 1;
        v479 = GetComponent_object_(mainMenuCursur);
        set_position(v479, mainMenuIdxPos);
        goto LABEL_551;
      }
    }
    else
    {
      v450 = Lclstr_a;
      v451 = "";
      if ("")
      {
LABEL_527:
      }
    }
    *&v450[2 * v439] = "";
      goto LABEL_536;
    goto LABEL_522;
  }
LABEL_551:
  if (gGlobal->pos == 6)
  {
    v481 = NewSpecific(string, 4u);
    Lclstr_a = v481;
    v483 = titleMainHELPText;
    v485 = v483->m_Items[6];
    v486 = GetLocalizeText(v485);
    v488 = Split_5246672(v486, Dellcl, 0);
    Lclstr = v488;
    v490 = 4;
    v491 = (v489->_2.bitflags2 >> 1) & 1;
    while (1)
    {
      v492 = v490 - 4;
      v494 = Lclstr;
      v495 = LODWORD(v494->max_length);
      if (v492 >= v495)
        break;
      else
      {
        v496 = Lclstr_a;
        if (v492 >= v495)
          goto LABEL_571;
      }
      v498 = *(&v494->obj.klass + v490);
      *&v496[2 * v490] = v498;
        goto LABEL_591;
LABEL_577:
LABEL_591:
      mainMenuIdxCnt = mainMenuTextIdxCnt;
      v507 = sub_8D3950(s32, &mainMenuIdxCnt);
      v508 = Format("Text_mainnote{0:00}TM", v507, 0);
      v509 = Concat_5224608("titlemain/titlemain_note/", v508);
      mainMenuTextIdx_str = v509;
      v511 = get_transform(MainMenuObj, 0);
      v512 = Find(v511, mainMenuTextIdx_str, 0);
      v513 = get_gameObject(v512);
      mainMenuTextIdx = v513;
      v515 = GetComponent_object_(mainMenuTextIdx);
      mainMenuTextTM = v515;
      v518 = Lclstr_a;
      v519 = mainMenuTextTM;
      v521 = *(&v518->obj.klass + v490);
      v522 = NewSpecific(object, 1u);
      v540 = 0;
      v523 = sub_8D3950(s32, &v540);
      v525 = v523;
      v522->m_Items[0] = v525;
      v528 = RepColTag(v521, v522);
      set_text(v519, v528);
      ++mainMenuTextIdxCnt;
      ++v490;
      v491 = (v529 >> 9) & 1;
      if (v490 == 8)
      {
        mainMenuIdxCnt = 7;
        mainMenuTextIdxCnt = 1;
        v530 = GetComponent_object_(mainMenuCursur);
        set_position(v530, mainMenuIdxPos);
        goto LABEL_606;
      }
    }
    else
    {
      v501 = Lclstr_a;
      v502 = "";
      if ("")
      {
LABEL_582:
      }
    }
    *&v501[2 * v490] = "";
      goto LABEL_591;
    goto LABEL_577;
  }
LABEL_606:
}

// 0xffaf50
void dds3DrawNameSprite(void) {
  dds3TitleMain_c *v2;
  UnityEngine_Transform_o *transform;
  u64 v10;
  s32 v11;
  struct UnityEngine_GameObject_array *titleSprite;
  Il2CppObject *Component_object;
  u32 v15;
  dds3TitleMain_c *v17;
  s16 v18;
  s32 v19;
  struct titleGlobal_o *gGlobal;
  s32 v21;
  s32 v22;
  bool v23;
  s32 LogoCnt;
  s32 v25;
  f32 dds3DrawNameSprite_fcnt;
  s16 v27;
  s32 v28;
  s32 v30;
  s64 v31;
  u64 v32;
  s64 v33;
  s32 v34;
  struct UnityEngine_GameObject_array *v35;
  Il2CppObject *v37;
  Il2CppObject *v38;
  struct UnityEngine_GameObject_array *v39;
  Il2CppObject *v41;
  u64 v43;
  s64 v44;
  s64 v45;
  s64 v46;
  s64 v47;
  UnityEngine_Vector3_o zero;

  if (gGlobal->LogoCnt == -1)
    return;
  else if (titleStartLogoAnimflag)
  {
    goto LABEL_10;
  }
  if (get_enabled(titleStartLogoAnim))
  {
    set_enabled(titleStartLogoAnim, 0);
  }
  titleStartLogoAnimtime = 0.0;
  if ((v2->_2.bitflags2 & 2) != 0)
  {
LABEL_11:
  }
LABEL_26:
  transform = get_transform(titleobj, 0);
  zero = get_zero();
  set_localPosition(transform, zero);
  if (!movTitleInitflag)
  {
    set_enabled(titleStartLogoAnim, 0);
    v10 = 0;
    do
    {
      Component_object = GetComponent_object_(titleSprite->m_Items[v10]);
      v46 = 0;
      v47 = 0;
      sub_19EC630(&v46, 255.0, 255.0, 255.0, 0.0);
      (Component_object->klass->vtable[23].methodPtr)(
        Component_object,
        Component_object->klass->vtable[23].*&v46,
        *(&v46 + 1),
        *&v47,
        *(&v47 + 1));
      ++v10;
      v11 = (v15 >> 9) & 1;
    }
    while (v10 != 7);
    movTitleInitflag = 1;
  }
  rsetOtOfs(72);
  rsetAlpha(0);
  rsetTest(1, 0, 128, 3, 0, 0, 1, 1);
  if ((v18 & 0x200) != 0)
  {
    v19 = v18 & 0x200;
    if (gGlobal->MovieId)
      goto LABEL_49;
LABEL_56:
    else
    {
      LogoCnt = gGlobal->LogoCnt;
      if (LogoCnt < 126)
        goto LABEL_77;
    }
    v21 = LogoCnt - 125;
    v22 = 30;
    v23 = v21 < 30;
    goto LABEL_60;
  }
  v19 = 0;
  if (!gGlobal->MovieId)
    goto LABEL_56;
LABEL_49:
  v21 = gGlobal->LogoCnt;
  v22 = 12;
  v23 = v21 < 12;
LABEL_60:
  if (!v23)
    v21 = v22;
  v25 = (v21 << 7) / v22;
  if (v25 < 1)
  {
LABEL_77:
    dds3DrawNameSprite_fcnt = 0.0;
    v27 = *&v17->_2.bitflags1;
    if ((v27 & 0x200) == 0)
      goto LABEL_75;
LABEL_81:
    v28 = v27 & 0x200;
    goto LABEL_84;
  }
  if (v25 == 128)
  {
    sdfSin(dds3DrawNameSprite_fcnt);
    dds3DrawNameSprite_fcnt = dds3DrawNameSprite_fcnt
                                                                   + 0.05;
  }
  rsetAlpha(1);
  rsetAlpha(0);
  if ((v27 & 0x200) != 0)
    goto LABEL_81;
LABEL_75:
  v28 = 0;
LABEL_84:
  v30 = gGlobal->LogoCnt;
  if (v30 >= 12)
    v30 = 12;
  v31 = 715827883LL * (v30 << 7);
  v32 = v31 >> 63;
  v33 = v31 >> 33;
  else
  {
    v34 = v33 + v32;
    v35 = titleSprite;
    if (!LODWORD(v35->max_length))
      goto LABEL_89;
  }
  v37 = GetComponent_object_(v35->m_Items[0]);
  v46 = 0;
  v47 = 0;
  v38 = v37;
  sub_19EC630(&v46, 255.0, 255.0, 255.0, v34 * 0.0078125);
  (v38->klass->vtable[23].methodPtr)(v38, v38->klass->vtable[23].*&v46, *(&v46 + 1), *&v47, *(&v47 + 1));
  v39 = titleSprite;
  v41 = GetComponent_object_(v39->m_Items[1]);
  v44 = 0;
  v45 = 0;
  sub_19EC630(&v44, 255.0, 255.0, 255.0, v34 * 0.0078125);
  (v41->klass->vtable[23].methodPtr)(v41, v41->klass->vtable[23].*&v44, *(&v44 + 1), *&v45, *(&v45 + 1));
  if (gGlobal->LogoCnt >= 13)
  {
    dds3DrawLogoSprite(v43);
  }
  ++*(*(*(v43 + 184) + 368LL) + 92LL);
}

// 0xffb5f0
void dds3InitTitleSprite(void) {
  u64 *v3;
  u64 *v4;

  gGlobal->LogoSpriteHandle = 0;
  gGlobal->TlogoSpriteHandle = 0;
  gGlobal->PressSpriteHandle = 0;
  gGlobal->Win1SpriteHandle = 0;
  gGlobal->Win1BSpriteHandle = 0;
  v3 = Allocate(pacFileHandle_t);
  pacFileHandle_t___ctor(v3);
  v4 = Allocate(sdfPacDecodeResrc_t);
  sdfPacDecodeResrc_t___ctor(v4);
}

// 0xffae50
void dds3LogoStart(void) {
  gGlobal->LogoCnt = 0;
  gGlobal->pressFadeinCnt = 0;
}

// 0xffaed0
void dds3LogoStart2(void) {
  gGlobal->LogoCnt = 192;
  gGlobal->pressFadeinCnt = 50;
}

// 0x1000470
s32 dds3Title(void) {
  dds3TitleInit(0);
  return 0;
}

// 0xffbf70
void dds3TitleDestroy(dds3ProcessID_t **id) {
  dds3DestroyTitleSprite();
  else
  {
    movieStop();
  }
}

// 0xffb9b0
void dds3TitleInit(s32 mode) {
  u64 *v3;
  u64 *v15;
  AssetBundleCtrl_o *asset_bc;
  Il2CppObject *Prefab_16624656;
  UnityEngine_GameObject_o *v20;
  UnityEngine_Transform_o *transform;
  Il2CppObject *v24;
  AssetBundleCtrl_o *v26;
  Il2CppObject *v27;
  UnityEngine_GameObject_o *v28;
  UnityEngine_Transform_o *v29;
  Il2CppObject *v30;
  AssetBundleCtrl_o *v32;
  Il2CppObject *v33;
  UnityEngine_GameObject_o *v34;
  UnityEngine_Transform_o *v35;
  u64 *v36;

  v3 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v3);
  FilterDelete();
  v6[2].klass->vtable[4].method->token = 0;
  *&v6[2].klass->vtable[4].method->flags = 0;
  *&v6[2].klass->vtable[4].method->slot = 0;
  LODWORD(v6[2].klass->vtable[4].method[1].invoker_method) = 0;
  HIDWORD(v6[2].klass->vtable[4].method[1].invoker_method) = -1;
  LODWORD(v6[2].klass->vtable[4].method[1].name) = 0;
  HIDWORD(v6[2].klass->vtable[4].method[1].name) = 0;
  HIDWORD(v6[2].klass->vtable[4].method[1].methodPointer) = 0;
  dds3InitTitleSprite();
  MovieSkipflag = 1;
  if (titleStartInitflag)
  {
    titleStartInitflag = 0;
  }
  else
  {
    if (title2mode != 1)
      goto LABEL_21;
  }
  gGlobal->pos = 2;
LABEL_21:
  if (mode)
  {
    if (mode == 3)
    {
      gGlobal->pos = 2;
      title2flag = 1;
      title2mode = 1;
    }
    else if (mode == 2)
    {
      gGlobal->pos = 0;
    }
    p2sdFadeOut(3801088);
    dds3FadeIn2(0xFu);
    movieStop();
    gGlobal->bgalp = 128;
    gGlobal->cnt = 0;
    gGlobal->pressFadeinCnt = 0;
    gGlobal->step = 22;
  }
  dds3BackColor = 0x80000000;
  v15 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v15,
    0,
    Method_dds3TitleMain_dds3Titlemain__);
  dds3StartProcess("titleProc", 0x2B19u, 0, 0, v15, 0, 0, 0, 0, 0);
  asset_bc = get_asset_bc();
  Prefab_16624656 = LoadPrefab_16624656(asset_bc, "common", "dds3data/UI", "titleUI");
  v20 = Find("Canvas_UI", 0);
  transform = get_transform(v20, 0);
  v24 = Instantiate_object__425664(Prefab_16624656, transform, 0);
  oMainmenu_UI = v24;
  AddComponent_object_(oMainmenu_UI);
  v26 = get_asset_bc();
  v27 = LoadPrefab_16624656(v26, "title", "dds3data/title", "AtlusLogoUI");
  v28 = Find("Canvas_UI", 0);
  v29 = get_transform(v28, 0);
  v30 = Instantiate_object__425664(v27, v29, 0);
  oA_logo_UI = v30;
  AddComponent_object_(oA_logo_UI);
  v32 = get_asset_bc();
  v33 = LoadPrefab_16624656(v32, "title", "dds3data/title", "RdLogoUI");
  v34 = Find("Canvas_UI", 0);
  v35 = get_transform(v34, 0);
  oD_logo_UI = Instantiate_object__425664(v33, v35, 0);
  v36 = Allocate(sdfMovieCb_t);
  sdfMovieCb_t___ctor(v36);
  dds3MovieCb = v36;
}

// 0xffc010
dds3ProcessFunc_t *dds3Titlemain(dds3ProcessID_t *id) {
  UnityEngine_GameObject_o *oA_logo_UI;
  UnityEngine_GameObject_o *oD_logo_UI;
  UnityEngine_Object_o *MainMenuObj;
  bool v9;
  u64 v10;
  struct dds3TitleMain_StaticFields **v66;
  struct dds3TitleMain_StaticFields *v67;
  struct titleGlobal_o *gGlobal;
  struct dds3TitleMain_StaticFields **p_static_fields;
  UnityEngine_Transform_o *v78;
  UnityEngine_Transform_o *v79;
  UnityEngine_Component_o *v80;
  UnityEngine_GameObject_o *v81;
  Il2CppObject *v82;
  Il2CppObject *v83;
  s16 v85;
  s32 v86;
  UnityEngine_Transform_o *v87;
  UnityEngine_Component_o *v88;
  UnityEngine_GameObject_o *v90;
  struct titleGlobal_o *v91;
  s32 v92;
  UnityEngine_Transform_o *v96;
  UnityEngine_Component_o *v97;
  UnityEngine_GameObject_o *v98;
  s16 v99;
  dds3TitleMain_c *v101;
  s32 v102;
  s16 v103;
  s32 v104;
  s32 v105;
  s32 movieChangeflag;
  s32 v111;
  s16 v122;
  s32 cnt;
  struct titleGlobal_o *v127;
  s32 v128;
  s16 v138;
  UnityEngine_Transform_o *v139;
  u64 v147;
  s16 v148;
  s32 v149;
  s16 v153;
  s32 v154;
  s32 v159;
  s32 v160;
  s32 v161;
  bool v171;
  u64 v172;
  u64 *v177;
  Il2CppObject *v180;
  Il2CppObject *DLCMsgFunc;
  struct dds3ProcessID_t_o *DLCMsgID;
  char *v185;
  s64 *v186;
  Il2CppObject *v188;
  Il2CppObject *v191;
  struct dds3ProcessID_t_o *v192;
  char *v193;
  s64 *v194;
  struct dds3TitleMain_StaticFields *v198;
  UnityEngine_Transform_o *v199;
  struct dds3TitleMain_StaticFields **v201;
  struct titleGlobal_o *v202;
  s32 v203;
  struct dds3TitleMain_StaticFields *v204;
  UnityEngine_Object_o *WarningObj;
  bool v207;
  UnityEngine_Transform_o *v209;
  UnityEngine_Component_o *v210;
  struct UnityEngine_GameObject_o *v211;
  u32 WarningFadeSpeed;
  s16 v218;
  s32 v219;
  s32 WarningCnt;
  u32 v222;
  struct titleGlobal_o *v229;
  Il2CppObject *v230;
  s32 v231;
  Il2CppObject *v232;
  bool v233;
  struct dds3TitleMain_StaticFields *v234;
  s16 v235;
  s32 v236;
  struct dds3TitleMain_StaticFields *v237;
  struct dds3TitleMain_StaticFields **v238;
  struct dds3TitleMain_StaticFields *v239;
  s32 v246;
  UnityEngine_GameObject_o *modeobj;
  s32 pos;
  dds3TitleMain_c *v262;
  dds3TitleMain_c *v272;
  u32 v275;
  s32 v278;
  u64 v281;
  u64 *v284;
  u64 *v289;
  s32 v295;
  struct Account_o *Instance;
  u64 data0;
  u64 data1;
  u64 context;
  s32 v309;
  struct dds3TitleMain_StaticFields *v313;
  UnityEngine_Transform_o *v314;
  UnityEngine_Component_o *v315;
  UnityEngine_GameObject_o *v316;
  nn_account_UserHandle_o v318;
  s64 v319;
  s64 v320;
  char *v321;
  UnityEngine_Vector3_o v323;
  UnityEngine_Vector3_o v324;
  UnityEngine_Vector3_o v325;

LABEL_7:
  MainMenuObj = oMainmenu_UI;
  v9 = op_Inequality(MainMenuObj, 0, 0);
  if (v9)
  {
    if (!titleStartInitflag)
      goto LABEL_33;
  }
LABEL_27:
  if ((*(v10 + 295) & 2) != 0)
  {
LABEL_28:
  }
LABEL_72:
  v66 = (v10 + 184);
  v67 = *(v10 + 184);
  switch (gGlobal->step)
  {
    case 0:
      if (init_flag)
      {
        cfginitialize(0);
      }
      gGlobal->cnt = 0;
      ++gGlobal->step;
      if (!Warningflag)
      {
        gGlobal->step = 36;
        (*p_static_fields)->Warningflag = 1;
      }
      aDrawBoxG(0, 0, 512, 224, 0, 0, 0, 128, 0, 0, 0, 128, 0, 0, 0, 128, 0, 0, 0, 128);
      return 0;
    case 1:
      if ((*(v10 + 295) & 2) == 0)
        goto LABEL_1120;
      goto LABEL_1118;
    case 2:
      dds3FadeIn(0, 0, 0, 0x14u);
        goto LABEL_124;
      goto LABEL_122;
    case 3:
      v78 = get_transform(titleobj, 0);
      LODWORD(v320) = 0;
      v319 = 0;
      sub_8524C0(&v319, 0.0, 2160.0, 0.0);
      *&v323.x = v319;
      LODWORD(v323.z) = v320;
      set_localPosition(v78, v323);
      v79 = get_transform(oA_logo_UI, 0);
      v80 = Find(v79, "atluslogo", 0);
      v81 = get_gameObject(v80);
      if (!get_activeSelf(v81))
        SetActive(v81, 1, 0);
      v82 = GetComponent_object_(v81);
      v319 = 0;
      v320 = 0;
      v83 = v82;
      sub_19EC630(&v319, 255.0, 255.0, 255.0, 1.0);
      (v83->klass->vtable[23].methodPtr)(v83, v83->klass->vtable[23].*&v319, *(&v319 + 1), *&v320, *(&v320 + 1));
      if (dds3FadeCheck())
        return 0;
      {
LABEL_122:
      }
LABEL_124:
      gGlobal->cnt = 0;
      ++gGlobal->step;
      movieStop();
      return 0;
    case 4:
      if (DDS3_PADCHECK_PRESS(1))
        goto LABEL_148;
      if (DDS3_PADCHECK_PRESS(3))
        goto LABEL_148;
      if (DDS3_PADCHECK_PRESS(2))
        goto LABEL_148;
      if (DDS3_PADCHECK_PRESS(0))
        goto LABEL_148;
      if (DDS3_PADCHECK_PRESS(12))
      {
LABEL_148:
        *(*(*(v10 + 184) + 368LL) + 72LL) = 50;
        v85 = *(v10 + 294);
        if ((v85 & 0x200) == 0)
          goto LABEL_152;
      }
      else
      {
        if ((v85 & 0x200) == 0)
        {
LABEL_152:
          v86 = 0;
          goto LABEL_1116;
        }
      }
      v86 = v85 & 0x200;
LABEL_1116:
      v66 = (v10 + 184);
      gGlobal = *(*(v10 + 184) + 368LL);
      cnt = gGlobal->cnt;
      if (cnt <= 49)
        goto LABEL_1124;
LABEL_1117:
      if (v86)
      {
LABEL_1118:
      }
LABEL_1120:
      gGlobal->cnt = 0;
      v313 = *v66;
      goto LABEL_1121;
    case 5:
      if ((*(v10 + 295) & 2) != 0 && !*(v10 + 216))
      v87 = get_transform(oA_logo_UI, 0);
      v88 = Find(v87, "atluslogo", 0);
      v90 = get_gameObject(v88);
      v91 = gGlobal;
      v92 = v91->cnt;
      if (v92 <= 21)
      {
        v91->cnt = v92 + 1;
        v230 = GetComponent_object_(v90);
        v231 = gGlobal->cnt;
        v319 = 0;
        v320 = 0;
        v232 = v230;
        sub_19EC630(&v319, 255.0, 255.0, 255.0, (v231 / -22.0) + 1.0);
        (v232->klass->vtable[23].methodPtr)(
          v232,
          v232->klass->vtable[23].*&v319,
          *(&v319 + 1),
          *&v320,
          *(&v320 + 1));
      }
      else
      {
        if (get_activeSelf(v90))
          SetActive(v90, 0, 0);
        gGlobal->cnt = 0;
        gGlobal->step = 8;
        if (init_flag)
        {
          cfginitialize(1);
        }
        init_flag = 0;
      }
      return 0;
    case 6:
      if ((*(v10 + 295) & 2) != 0 && !*(v10 + 216))
      v96 = get_transform(oD_logo_UI, 0);
      v97 = Find(v96, "rdlogo", 0);
      v98 = get_gameObject(v97);
      if (!get_activeSelf(v98))
        SetActive(v98, 1, 0);
      if ((v99 & 0x200) != 0)
      {
        v86 = v99 & 0x200;
      }
      else
      {
        v86 = 0;
      }
      v66 = (v10 + 184);
      gGlobal = *(*(v10 + 184) + 368LL);
      cnt = gGlobal->cnt;
      if (cnt <= 19)
        goto LABEL_1124;
      goto LABEL_1117;
    case 7:
      if (!DDS3_PADCHECK_PRESS(1))
      {
        if (!DDS3_PADCHECK_PRESS(3))
        {
          if (!DDS3_PADCHECK_PRESS(2))
          {
            if (!DDS3_PADCHECK_PRESS(0))
            {
              if (!DDS3_PADCHECK_PRESS(12))
              {
                  goto LABEL_207;
                goto LABEL_205;
              }
            }
          }
        }
      }
      gGlobal->cnt = 50;
      if ((v101->_2.bitflags2 & 2) != 0)
      {
LABEL_205:
      }
LABEL_207:
      v102 = gGlobal->cnt;
      if (v102 <= 49)
      {
LABEL_426:
        v159 = v102 + 1;
        goto LABEL_1128;
      }
      dds3FadeOut(0, 0, 0, 0x14u);
        goto LABEL_1083;
      goto LABEL_1085;
    case 8:
      v103 = *(v10 + 294);
      if ((v103 & 0x200) != 0)
      {
        v104 = v103 & 0x200;
        v105 = gGlobal->cnt;
        if (v105 > 21)
        {
LABEL_215:
          gGlobal->LogoCnt = -1;
          dds3FadeIn(0, 0, 0, 0x1Eu);
          if ((dds3TitleMain_mode & 1) == 0)
          {
            if (dds3CheckDLC2())
            {
              if (movieChangeflag)
              {
                v111 = 25;
                goto LABEL_1060;
              }
                goto LABEL_1057;
            }
            else
            {
              {
LABEL_1057:
              }
            }
            v111 = 23;
LABEL_1060:
            moviePlay(v111, -1);
            else
            {
              v309 = 0;
            }
LABEL_1096:
            gGlobal->MovieId = v309;
            ++dds3TitleMain_mode;
            gGlobal->cnt = 0;
            ++gGlobal->step;
            v314 = get_transform(oD_logo_UI, 0);
            v315 = Find(v314, "rdlogo", 0);
            v316 = get_gameObject(v315);
            if (get_activeSelf(v316))
            {
              modeobj = v316;
              goto LABEL_1101;
            }
            return 0;
          }
          if (dds3CheckDLC2())
          {
            if (movieChangeflag)
            {
              moviePlay(26, -1);
              movieChangeflag = 0;
              if ((v272->_2.bitflags2 & 2) == 0)
                goto LABEL_1095;
            }
            else
            {
              moviePlay(24, -1);
              movieChangeflag = 1;
              if ((v272->_2.bitflags2 & 2) == 0)
                goto LABEL_1095;
            }
          }
          else
          {
            moviePlay(24, -1);
              goto LABEL_1095;
          }
LABEL_1095:
          v309 = 1;
          goto LABEL_1096;
        }
      }
      else
      {
        v104 = 0;
        v105 = gGlobal->cnt;
        if (v105 > 21)
          goto LABEL_215;
      }
      if (v104 && !*(v10 + 216))
      {
        v105 = gGlobal->cnt;
      }
      v159 = v105 + 1;
      goto LABEL_1128;
    case 9:
      if (frame() >= 2707)
      {
        if (gGlobal->MovieId == 1)
        {
          gGlobal->LogoCnt = 0;
          gGlobal->pressFadeinCnt = 0;
          gGlobal->cnt = 0;
          movTitleInitflag = 0;
          ++gGlobal->step;
        }
      }
      if (movieCheckEnd())
      {
        gGlobal->cnt = 0;
        gGlobal->LogoCnt = -1;
      }
      else
      {
        if (!DDS3_PADCHECK_PRESS(1))
        {
          if (!DDS3_PADCHECK_PRESS(3))
          {
            if (!DDS3_PADCHECK_PRESS(2))
            {
              if (!DDS3_PADCHECK_PRESS(0))
              {
                if (!DDS3_PADCHECK_PRESS(12))
                  return 0;
              }
            }
          }
        }
        dds3FadeOut(0xFFu, 0xFFu, 0xFFu, 0xFu);
        gGlobal->cnt = 0;
        movTitleInitflag = 1;
        titleStartLogoAnimflag = 1;
      }
      v127 = gGlobal;
      v128 = 24;
      goto LABEL_1122;
    case 0xA:
      dds3DrawNameSprite(v10);
      if (gGlobal->MovieId)
      {
        if (movieCheckEnd())
        {
          dds3FadeOut(0, 0, 0, 0xFu);
          gGlobal->cnt = 0;
          goto LABEL_731;
        }
      }
      else
      {
        if (movieCheckEnd())
        {
          dds3FadeOut(0, 0, 0, 0xFu);
          gGlobal->cnt = 0;
          movieStop();
          moviePlay(18, -1);
          goto LABEL_730;
        }
      }
      if (DDS3_PADCHECK_PRESS(1))
        goto LABEL_1133;
      if (DDS3_PADCHECK_PRESS(3))
        goto LABEL_1133;
      if (DDS3_PADCHECK_PRESS(2))
        goto LABEL_1133;
      if (DDS3_PADCHECK_PRESS(0))
        goto LABEL_1133;
      if (DDS3_PADCHECK_PRESS(12))
      {
LABEL_1133:
        dds3FadeOut(0, 0, 0, 0xFu);
        p2sdPlaySE(3801089);
        gGlobal->cnt = 0;
        v127 = gGlobal;
        v128 = 11;
        goto LABEL_1122;
      }
      return 0;
    case 0xB:
    case 0x14:
    case 0x18:
      if (dds3FadeCheck())
        return 0;
      movieStop();
        goto LABEL_1085;
      goto LABEL_1083;
    case 0xC:
      v122 = *(v10 + 294);
      if ((v122 & 0x200) == 0)
      {
        v86 = 0;
        cnt = gGlobal->cnt;
        if (cnt <= 3)
          goto LABEL_1124;
LABEL_634:
        gGlobal->loopflg = 0;
        (*v66)->gGlobal->menucnt = 0;
        (*v66)->gGlobal->cnt = 0;
        if ((*v66)->title2flag)
        {
LABEL_1108:
          if ((*(v10 + 295) & 2) == 0)
          {
LABEL_1111:
            v127 = *(*(v10 + 184) + 368LL);
            v128 = 18;
            goto LABEL_1122;
          }
LABEL_1109:
          goto LABEL_1111;
        }
        v233 = slSuspendDataCheck();
        if (v233)
        {
          v234 = *(v10 + 184);
          if (!continueCursurflag)
          {
            menuCursurCnt = 5;
            *(*(*(v10 + 184) + 368LL) + 68LL) = *(*(v10 + 184) + 312LL) - 1;
            *(*(v10 + 184) + 308LL) = 0;
            goto LABEL_1107;
          }
        }
        v235 = *(v10 + 294);
        if ((v235 & 0x200) != 0)
        {
          v236 = v235 & 0x200;
          v237 = *(v10 + 184);
          if (!continueCursurflag)
            goto LABEL_648;
        }
        else
        {
          v236 = 0;
          v237 = *(v10 + 184);
          if (!continueCursurflag)
          {
LABEL_648:
            gGlobal->pos = 0;
LABEL_1107:
            *(*(v10 + 184) + 16LL) = 1;
            goto LABEL_1108;
          }
        }
        gGlobal->pos = mainMenuIdxCnt - 1;
        if ((*(v10 + 295) & 2) == 0)
          goto LABEL_1111;
        goto LABEL_1109;
      }
      v86 = v122 & 0x200;
      cnt = gGlobal->cnt;
      if (cnt > 3)
        goto LABEL_634;
LABEL_1124:
      if (v86)
        goto LABEL_1125;
      goto LABEL_1127;
    case 0xD:
      dds3DrawNameSprite(v10);
      v102 = gGlobal->cnt;
      if (v102 <= 14)
        goto LABEL_426;
      if (!movieCheckEnd())
        return 0;
      movieStop();
      gGlobal->cnt = 0;
      v127 = gGlobal;
      v128 = 2;
      goto LABEL_1122;
    case 0xE:
      dds3FadeIn2(0xFu);
      gGlobal->bgalp = 128;
      gGlobal->cnt = 0;
      gGlobal->pressFadeinCnt = 0;
      ++gGlobal->step;
      gGlobal->LogoCnt = 192;
      gGlobal->pressFadeinCnt = 50;
      return 0;
    case 0xF:
      dds3DrawNameSprite(v10);
      ++gGlobal->cnt;
      if (!dds3FadeCheck())
        goto LABEL_1082;
      return 0;
    case 0x10:
      dds3DrawNameSprite(v10);
      if (dds3MovieCb->decodeCb->frameCount)
      {
        Write("Title Movie frameCount==0\n", 0);
      }
      else
      {
        v246 = movieCheckEnd();
        if (v246)
        {
          movTitleInitflag = 0;
          titleStartLogoAnimflag = 0;
          movieStop();
          dds3FadeOut(0, 0, 0, 0xFu);
          gGlobal->cnt = 0;
LABEL_730:
LABEL_731:
          v127 = gGlobal;
          v128 = 13;
          goto LABEL_1122;
        }
        ++gGlobal->cnt;
      }
      if (DDS3_PADCHECK_PRESS(1))
        goto LABEL_1134;
      if (DDS3_PADCHECK_PRESS(3))
        goto LABEL_1134;
      if (DDS3_PADCHECK_PRESS(2))
        goto LABEL_1134;
      if (DDS3_PADCHECK_PRESS(0))
        goto LABEL_1134;
      if (DDS3_PADCHECK_PRESS(12))
      {
LABEL_1134:
        dds3FadeOut(0, 0, 0, 0xFu);
        p2sdPlaySE(3801089);
        gGlobal->cnt = 0;
        v127 = gGlobal;
        v128 = 17;
        goto LABEL_1122;
      }
      return 0;
    case 0x11:
      dds3DrawNameSprite(v10);
      if (gGlobal->cnt == 16)
      {
        movieStop();
      }
      v138 = *(v10 + 294);
      if ((v138 & 0x200) != 0)
      {
        v86 = v138 & 0x200;
      }
      else
      {
        v86 = 0;
      }
      v238 = (v10 + 184);
      gGlobal = *(*(v10 + 184) + 368LL);
      cnt = gGlobal->cnt;
      if (cnt <= 17)
        goto LABEL_1124;
      gGlobal->cnt = 0;
      v239 = *v238;
      v128 = 12;
      v127 = v239->gGlobal;
      goto LABEL_1122;
    case 0x12:
      v139 = get_transform(titleobj, 0);
      LODWORD(v320) = 0;
      v319 = 0;
      sub_8524C0(&v319, 0.0, 2160.0, 0.0);
      *&v324.x = v319;
      LODWORD(v324.z) = v320;
      set_localPosition(v139, v324);
      moviePlay(13, -1);
      dds3FadeIn2(0xFu);
      goto LABEL_481;
    case 0x13:
      titleMovePlayCheck(v10);
      ButtonGuideDispSet("TITLE01", 0, 0, 90);
      if (title2flag)
      {
        dds3CheckPadInput2();
          goto LABEL_738;
      }
      else
      {
        dds3CheckPadInput();
        {
LABEL_738:
          dds3DrawMenuString(v147);
          if (DDS3_PADCHECK_TRIG(3))
          {
            p2sdPlaySE(10);
            dds3FadeOut(0, 0, 0, 0xEu);
            gGlobal->cnt = 0;
            gGlobal->step = 26;
            movieStop();
            title2flag = 0;
            title2mode = 0;
            menuCursurCnt = 1;
            titleMainInitflag = 0;
            titileMainCursorflag = 0;
            title2Posflag = 0;
            if (get_activeSelf(modeobj))
            {
LABEL_1101:
              SetActive(modeobj, 0, 0);
            }
            return 0;
          }
          if (!DDS3_PADCHECK_TRIG(1))
          {
            if (!DDS3_PADCHECK_TRIG(12))
              return 0;
          }
          pos = gGlobal->pos;
          if (pos == 1)
            goto LABEL_1135;
          if (pos == 2)
            goto LABEL_1135;
          if (pos == 3)
          {
LABEL_1135:
            dds3FadeOut(0, 0, 0, 0x3Cu);
            fadeoutTime = 45;
            if ((v262->_2.bitflags2 & 2) != 0)
            {
LABEL_786:
            }
          }
          else
          {
            dds3FadeOut(0, 0, 0, 0xFu);
            fadeoutTime = 4;
            if ((v262->_2.bitflags2 & 2) != 0)
              goto LABEL_786;
          }
          if (get_activeSelf(modeobj))
          {
            SetActive(modeobj, 0, 0);
          }
          ButtonGuideDispOff();
          p2sdPlaySE(8);
LABEL_1082:
          {
LABEL_1083:
          }
LABEL_1085:
          gGlobal->cnt = 0;
LABEL_1121:
          v127 = gGlobal;
          v128 = v127->step + 1;
          goto LABEL_1122;
        }
      }
      goto LABEL_738;
    case 0x15:
      v148 = *(v10 + 294);
      if ((v148 & 0x200) != 0)
      {
        v149 = v148 & 0x200;
        cnt = gGlobal->cnt;
        if (cnt < fadeoutTime)
          goto LABEL_384;
        goto LABEL_663;
      }
      v149 = 0;
      cnt = gGlobal->cnt;
      if (cnt >= fadeoutTime)
      {
LABEL_663:
        switch (gGlobal->pos)
        {
          case 0:
            gGemeMode = -1;
            dds3AdminiCallSequence(3, 0, 0, 0);
            goto LABEL_1029;
          case 1:
            v278 = gGlobal->cnt;
            if (v278 <= 29)
              goto LABEL_1008;
            dds3FadeIn(0, 0, 0, 0x32u);
            id->func_ans = -1;
            dds3AdminiCallSequence(42, 0, 0, 0);
            gGlobal->step = 39;
            ButtonGuideDispOff();
            dlcChackflag = 0;
              goto LABEL_1047;
            goto LABEL_1045;
          case 2:
            v278 = gGlobal->cnt;
            if (v278 <= 29)
              goto LABEL_1008;
            dds3FadeIn(0, 0, 0, 0x32u);
            id->func_ans = -1;
            LODWORD(v319) = title2mode;
            v284 = sub_8D3950(s32, &v319);
            dds3AdminiCallSequence(42, v284, 0, 0);
            gGlobal->step = 39;
            ButtonGuideDispOff();
            dlcChackflag = 0;
            goto LABEL_994;
          case 3:
            v278 = gGlobal->cnt;
            if (v278 <= 29)
              goto LABEL_1008;
            dds3FadeIn(0, 0, 0, 0x32u);
            id->func_ans = -1;
            LODWORD(v319) = title2mode;
            v289 = sub_8D3950(s32, &v319);
            dds3AdminiCallSequence(42, v289, 0, 0);
            gGlobal->step = 39;
            ButtonGuideDispOff();
            dlcChackflag = 1;
LABEL_994:
            title2flag = 0;
            title2mode = 0;
              goto LABEL_1047;
            goto LABEL_1045;
          case 4:
            v278 = gGlobal->cnt;
            if (v278 <= 29)
            {
LABEL_1008:
              if ((*(v10 + 295) & 2) != 0 && !*(v10 + 216))
              {
                v278 = gGlobal->cnt;
              }
              gGlobal->cnt = v278 + 1;
              {
LABEL_1047:
                if (*(*(*(v281 + 184) + 368LL) + 68LL) != 6)
                {
                  ClearMainmenuUI(v281);
                  ClearA_logoUI();
                  ClearD_logoUI();
                }
                *(*(v281 + 184) + 253LL) = 0;
                *(*(v281 + 184) + 304LL) = 0;
                *(*(v281 + 184) + 192LL) = 0;
                *(*(v281 + 184) + 308LL) = 0;
                *(*(v281 + 184) + 312LL) = *(*(*(v281 + 184) + 368LL) + 68LL) + 1;
                *(*(v281 + 184) + 168LL) = 0;
                *(*(v281 + 184) + 184LL) = 0;
                *(*(v281 + 184) + 176LL) = 0;
                return 0;
              }
            }
            else
            {
              dds3AdminiCallSequence(5, 0, 0, 0);
              gGlobal->step = 39;
              moviePlay(0, -1);
                goto LABEL_1047;
            }
LABEL_1045:
            goto LABEL_1047;
          case 5:
            dds3FadeIn(0, 0, 0, 0xAu);
            v295 = FindId(0, "BGM_CONF_BGM00");
            p2sdPlayBGM(v295);
            dds3AdminiCallSequence(18, 0, 0, 0);
            ButtonGuideDispOff();
LABEL_1029:
            gGlobal->step = 39;
              goto LABEL_1047;
            goto LABEL_1045;
          case 6:
            Begin(0);
            data0 = Instance->userHandle._data0;
            data1 = Instance->userHandle._data1;
            context = Instance->userHandle._context;
            v318._data1 = data1;
            v318._context = context;
            v318._data0 = data0;
            ShowAddOnContentList(&v318);
            End(0);
            gGlobal->cnt = 0;
            ButtonGuideDispOff();
            gGlobal->step = 19;
            dds3FadeIn(0, 0, 0, 0xAu);
            goto LABEL_1044;
          default:
LABEL_1044:
              goto LABEL_1045;
            goto LABEL_1047;
        }
      }
LABEL_384:
      if (v149)
      {
LABEL_1125:
        if (!*(v10 + 216))
        {
          cnt = gGlobal->cnt;
        }
      }
LABEL_1127:
      v159 = cnt + 1;
LABEL_1128:
      gGlobal->cnt = v159;
      return 0;
    case 0x16:
      ++gGlobal->menucnt;
      dds3DrawMenuString(v10);
      if (!get_activeSelf(modeobj))
      {
        SetActive(modeobj, 1, 0);
      }
      if ((v153 & 0x200) == 0)
        goto LABEL_395;
      goto LABEL_540;
    case 0x19:
      ++gGlobal->cnt;
      if ((*v66)->gGlobal->cnt < 6)
        return 0;
      moviePlay(18, -1);
      gGlobal->cnt = 0;
      v127 = gGlobal;
      v128 = 14;
      goto LABEL_1122;
    case 0x1A:
      dds3DrawMenuString(v10);
      v102 = gGlobal->cnt;
      if (v102 <= 14)
        goto LABEL_426;
      if (movieCheckEnd())
      {
        movieStop();
      }
      gGlobal->cnt = 0;
      ButtonGuideDispOff();
      v127 = gGlobal;
      v128 = 25;
      goto LABEL_1122;
    case 0x1B:
      v160 = gGlobal->cnt;
      if (v160 >= 1)
      {
        if ((*(v10 + 295) & 2) != 0 && !*(v10 + 216))
        {
          v160 = gGlobal->cnt;
        }
        v161 = v160 + 1;
LABEL_799:
        gGlobal->cnt = v161;
        goto LABEL_800;
      }
      if (movieCheckEnd())
        goto LABEL_1136;
      if (*(*(*(*(v10 + 184) + 360LL) + 64LL) + 92LL) < 31)
      {
LABEL_800:
        if ((*(v10 + 295) & 2) == 0)
          goto LABEL_803;
        goto LABEL_801;
      }
      if (DDS3_PADCHECK_TRIG(1))
        goto LABEL_1136;
      if (DDS3_PADCHECK_TRIG(3))
        goto LABEL_1136;
      if (DDS3_PADCHECK_TRIG(2))
        goto LABEL_1136;
      if (DDS3_PADCHECK_TRIG(0))
        goto LABEL_1136;
      if (DDS3_PADCHECK_TRIG(12))
      {
LABEL_1136:
        dds3FadeOut(0xFFu, 0xFFu, 0xFFu, 0x3Cu);
        gGlobal = *(*(v10 + 184) + 368LL);
        v161 = 1;
        goto LABEL_799;
      }
        goto LABEL_803;
LABEL_801:
LABEL_803:
      if (*(*(*(v10 + 184) + 368LL) + 72LL) < 60)
        return 0;
      movieStop();
      gGlobal->cnt = 0;
      v127 = gGlobal;
      v128 = 28;
      goto LABEL_1122;
    case 0x1C:
      ++gGlobal->cnt;
      if ((*v66)->gGlobal->cnt < 5)
        return 0;
      dds3FadeIn(0xFFu, 0xFFu, 0xFFu, 0xFu);
      moviePlay(13, -1);
      gGlobal->menucnt = 0;
      gGlobal->bgalp = 128;
      gGlobal->cnt = 0;
      gGlobal->pressFadeinCnt = 0;
      v127 = gGlobal;
      v128 = 22;
      goto LABEL_1122;
    case 0x1D:
      titleMovePlayCheck(v10);
      if (dds3FadeCheck() == 1)
        return 0;
      fldAutoMapDelete();
      fldPlayerDelete();
      v171 = titleDLCMsgCheck();
      if (v171)
      {
        dlcMsgInit(v172);
        v127 = gGlobal;
        v128 = 30;
        goto LABEL_1122;
      }
      v198 = *(v172 + 184);
      if (dlcMsgSave)
      {
        v127 = gGlobal;
        v128 = 31;
        goto LABEL_1122;
      }
      goto LABEL_526;
    case 0x1E:
      titleMovePlayCheck(v10);
      if (!titleDLCMsgDraw())
        return 0;
LABEL_481:
      v127 = gGlobal;
      v128 = 29;
      goto LABEL_1122;
    case 0x1F:
      dlcMsgSave = 0;
      v177 = Allocate(dds3ProcessID_t);
      dds3ProcessID_t___ctor(v177);
      DLCMsgID = v177;
      v180 = slDLCMsgProc();
      DLCMsgFunc = v180;
      if (!DLCMsgFunc)
        goto LABEL_498;
      else
      {
      }
      if (DLCMsgFunc->klass != System_Func_dds3ProcessID_t__object_)
      {
        sub_8FC2C0(DLCMsgFunc->klass->_1.element_class, System_Func_dds3ProcessID_t__object_, &v319);
        if ((v319 & 1) != 0)
          v185 = v321;
        else
          v185 = &v319 + 1;
        v186 = sub_8C4940(v185);
      }
LABEL_497:
      DLCMsgID->processfunc = DLCMsgFunc;
LABEL_498:
      v127 = gGlobal;
      v128 = 32;
      goto LABEL_1122;
    case 0x20:
      DLCMsgID->func_ans = 0;
      v188 = Assembly___Invoke(
               (*v66)->DLCMsgID->processfunc,
               (*v66)->DLCMsgID);
      DLCMsgFunc = v188;
      v191 = DLCMsgFunc;
      if (!v191)
        goto LABEL_515;
      else
      {
        v192 = DLCMsgID;
      }
      if (v191->klass != System_Func_dds3ProcessID_t__object_)
      {
        sub_8FC2C0(v191->klass->_1.element_class, System_Func_dds3ProcessID_t__object_, &v319);
        if ((v319 & 1) != 0)
          v193 = v321;
        else
          v193 = &v319 + 1;
        v194 = sub_8C4940(v193);
      }
LABEL_514:
      v192->processfunc = v191;
LABEL_515:
      if (slGetInfo() != 4)
        return 0;
      slDLCMsgKill();
LABEL_526:
      v127 = gGlobal;
      v128 = 34;
      goto LABEL_1122;
    case 0x22:
      dlcMsgLast(v10);
      v127 = gGlobal;
      v128 = 35;
      goto LABEL_1122;
    case 0x23:
      ++gGlobal->menucnt;
      dds3DrawMenuString(v10);
      v199 = get_transform(titleobj, 0);
      LODWORD(v320) = 0;
      v319 = 0;
      sub_8524C0(&v319, 0.0, 2160.0, 0.0);
      *&v325.x = v319;
      LODWORD(v325.z) = v320;
      set_localPosition(v199, v325);
      if (!get_activeSelf(modeobj))
      {
        SetActive(modeobj, 1, 0);
      }
      if ((v153 & 0x200) != 0)
      {
LABEL_540:
        v154 = v153 & 0x200;
      }
      else
      {
LABEL_395:
        v154 = 0;
      }
      v202 = gGlobal;
      v203 = v202->cnt;
      if (v203 > 23)
      {
        v202->loopflg = 0;
        (*v201)->gGlobal->cnt = 0;
        v204 = *v201;
        v128 = 19;
        v127 = v204->gGlobal;
        goto LABEL_1122;
      }
      v202->cnt = v203 + 1;
      gGlobal->bgalp -= 5;
      v229 = gGlobal;
      if (v229->bgalp < 0)
      {
        v229->bgalp = 0;
      }
      return 0;
    case 0x24:
      v207 = op_Equality(WarningObj, 0, 0);
      if (v207)
      {
        v209 = get_transform(MainMenuObj, 0);
        v210 = Find(v209, "WarningState", 0);
        v211 = get_gameObject(v210);
        WarningObj = v211;
      }
      if (!get_activeSelf(WarningObj))
      {
        SetActive(WarningObj, 1, 0);
      }
      dds3FadeIn(0, 0, 0, WarningFadeSpeed);
      v127 = gGlobal;
      v128 = 37;
      goto LABEL_1122;
    case 0x25:
      if (dds3FadeCheck() == 1)
        return 0;
      if ((v218 & 0x200) != 0)
      {
        v219 = v218 & 0x200;
        if (WarningCnt > 129)
          goto LABEL_580;
      }
      else
      {
        v219 = 0;
        if (WarningCnt > 129)
        {
LABEL_580:
          v222 = WarningFadeSpeed;
          dds3FadeOut(0, 0, 0, v222);
          gGlobal->step = 38;
          goto LABEL_872;
        }
      }
      WarningCnt = WarningCnt + 1;
LABEL_872:
      if (!DDS3_PADCHECK_PRESS(1))
      {
        if (!DDS3_PADCHECK_PRESS(3))
        {
          if (!DDS3_PADCHECK_PRESS(2))
          {
            if (!DDS3_PADCHECK_PRESS(0))
            {
              if (!DDS3_PADCHECK_PRESS(12))
                return 0;
            }
          }
        }
      }
      v275 = WarningFadeSpeed;
      dds3FadeOut(0, 0, 0, v275);
      v127 = gGlobal;
      v128 = 38;
LABEL_1122:
      v127->step = v128;
      return 0;
    case 0x26:
      if (dds3FadeCheck() == 1)
        return 0;
      WarningCnt = 0;
      if (get_activeSelf(WarningObj))
      {
        SetActive(WarningObj, 0, 0);
      }
      v127 = gGlobal;
      v128 = 1;
      goto LABEL_1122;
    case 0x27:
      id->func_ans = -1;
      ClearA_logoUI(v10);
      ClearD_logoUI();
      return 0;
    default:
      return 0;
  }
}

// 0xff5be0
void dlcMsgInit(void) {
  System_String_o *PlatformStr;
  System_String_o *v3;
  System_String_o *v4;
  System_String_o *v5;
  Il2CppObject *p_obj;

  LoadLocalizeText("common", "DLC_SHOP");
  PlatformStr = GetPlatformStr();
  v3 = Concat_5224608("common", PlatformStr);
  v4 = GetPlatformStr();
  v5 = Concat_5224608("DLC_SHOP", v4);
  LoadLocalizeText(v3, v5);
  p_obj = &dlcMesData->obj;
  fclInitMessage(p_obj);
}

// 0xff5d00
void dlcMsgLast(void) {
  System_String_o *PlatformStr;
  System_String_o *v4;

  fclEndMessage();
  fclDestroyMessage();
  Remove("DLC_SHOP", 0);
  PlatformStr = GetPlatformStr();
  v4 = Concat_5224608("DLC_SHOP", PlatformStr);
  Remove(v4, 0);
}

// 0xff5bd0
void *pacGetResrc(void *a) {
  return 0;
}

// 0xff5dc0
bool titleDLCMsgCheck(void) {
  struct System_SByte_array *dlcflg;
  struct System_SByte_array *v8;
  s32 v12;
  struct System_SByte_array *v17;
  struct System_SByte_array *v22;
  struct System_SByte_array *v27;
  struct System_SByte_array *v32;
  struct System_SByte_array *v37;

  else if (!dds3CheckDLC1())
  {
    goto LABEL_15;
  }
  dlcflg = SystemWork->dlcflg;
  if (dlcflg->m_Items[0])
  {
LABEL_15:
    else if (!dds3CheckDLC2())
    {
      goto LABEL_33;
    }
    v8 = SystemWork->dlcflg;
    if (!v8->m_Items[1])
    {
      v12 = 2;
LABEL_119:
      dlcMsgNum = v12;
      return 1;
    }
LABEL_33:
    else if (!dds3CheckDLC6())
    {
      goto LABEL_47;
    }
    v17 = SystemWork->dlcflg;
    if (!v17->m_Items[5])
    {
      v12 = 3;
      goto LABEL_119;
    }
LABEL_47:
    else if (!dds3CheckDLC7())
    {
      goto LABEL_61;
    }
    v22 = SystemWork->dlcflg;
    if (!v22->m_Items[6])
    {
      v12 = 4;
      goto LABEL_119;
    }
LABEL_61:
    else if (!dds3CheckDLC3())
    {
      goto LABEL_75;
    }
    v27 = SystemWork->dlcflg;
    if (!v27->m_Items[2])
    {
      v12 = 5;
      goto LABEL_119;
    }
LABEL_75:
    else if (!dds3CheckDLC4())
    {
      goto LABEL_89;
    }
    v32 = SystemWork->dlcflg;
    if (!v32->m_Items[3])
    {
      v12 = 6;
      goto LABEL_119;
    }
LABEL_89:
    else if (!dds3CheckDLC5())
    {
      goto LABEL_103;
    }
    v37 = SystemWork->dlcflg;
    if (!v37->m_Items[4])
    {
      v12 = 7;
      goto LABEL_119;
    }
LABEL_103:
    else if (dds3CheckDLC8())
    {
      goto LABEL_106;
    }
    return 0;
  }
  dlcMsgNum = 1;
  return 1;
}

// 0xff63e0
bool titleDLCMsgDraw(void) {
  struct System_SByte_array *dlcflg;
  s8 *m_Items;
  struct System_SByte_array *v8;
  struct System_SByte_array *v11;
  struct System_SByte_array *v14;
  struct System_SByte_array *v17;
  struct System_SByte_array *v20;
  struct System_SByte_array *v23;
  struct System_SByte_array *v26;

  switch (dlcMsgNum)
  {
    case 1:
      fclSetMessageInvalid(1);
      fclStartMessage(0);
      dlcflg = SystemWork->dlcflg;
      m_Items = dlcflg->m_Items;
      goto LABEL_79;
    case 2:
      fclSetMessageInvalid(1);
      fclStartMessage(1);
      v8 = SystemWork->dlcflg;
      m_Items = &v8->m_Items[1];
      goto LABEL_79;
    case 3:
      fclSetMessageInvalid(1);
      fclStartMessage(2);
      v11 = SystemWork->dlcflg;
      m_Items = &v11->m_Items[5];
      goto LABEL_79;
    case 4:
      fclSetMessageInvalid(1);
      fclStartMessage(3);
      v14 = SystemWork->dlcflg;
      m_Items = &v14->m_Items[6];
      goto LABEL_79;
    case 5:
      fclSetMessageInvalid(1);
      fclStartMessage(4);
      v17 = SystemWork->dlcflg;
      m_Items = &v17->m_Items[2];
      goto LABEL_79;
    case 6:
      fclSetMessageInvalid(1);
      fclStartMessage(5);
      v20 = SystemWork->dlcflg;
      m_Items = &v20->m_Items[3];
      goto LABEL_79;
    case 7:
      fclSetMessageInvalid(1);
      fclStartMessage(6);
      v23 = SystemWork->dlcflg;
      m_Items = &v23->m_Items[4];
      goto LABEL_79;
    case 8:
      fclSetMessageInvalid(1);
      fclStartMessage(7);
      v26 = SystemWork->dlcflg;
      m_Items = &v26->m_Items[7];
LABEL_79:
      *m_Items = 1;
      break;
    default:
      break;
  }
  dlcMsgSave = 1;
  dlcMsgNum = 0;
  fclUpdateMessage();
  return fclChkMessage() == 0;
}

// 0xff6940
void titleMovePlayCheck(void) {
  struct titleGlobal_o *gGlobal;

  if (gGlobal->loopflg == 1)
  {
    gGlobal->loopflg = 0;
    moviePlay(13, -1);
  }
  else
  {
    if (movieCheckEnd())
    {
      movieStop();
      gGlobal->loopflg = 1;
    }
  }
}

// 0x1000360
s32 titleShutDown(void) {
LABEL_7:
  dds3DestroyTitleSprite();
  movieStop();
  dds3KillProcessName("titleProc", 1);
  return 0;
}

// 0x10002f0
s32 titleStart(s32 mode) {
  dds3TitleInit(mode);
  return -1;
}
