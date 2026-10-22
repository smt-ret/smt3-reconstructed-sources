#include "types.h"

static char *gCombineInfoStrTbl[3];
static char *gStatusPanelText1[4];
static char *gStatusPanelText2[1];
static char *gStatusPanelText3[1];
static char *gStatusPanelText4[1];
static void *ListObjs;
static void *TextObjs;
static void *CCtrObjs;
static void *AnimObjs;
static char *cmbIconName[7];
static s32 RibbonOld;

void *GetGameObject(char *name);

// 0x1463200
void FinalizeGameObject(void) {
  PropertySheet___Clear(AnimObjs);
  PropertySheet___Clear(CCtrObjs);
  PropertySheet___Clear(TextObjs);
  PropertySheet___Clear(ListObjs);
}

// 0x145f250
void InitializeGameObject(void) {
  UnityEngine_Transform_o *transform;
  UnityEngine_Object_o *v3;
  System_String_o *name;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *ListObjs;
  UnityEngine_GameObject_o *v8;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v9;
  System_String_o *v10;
  UnityEngine_Component_o *v11;
  UnityEngine_GameObject_o *v12;
  System_Collections_Generic_Dictionary_object__object__o *v13;
  Il2CppObject *v14;
  Il2CppObject *Item;
  Il2CppObject *Component_object;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v20;
  System_String_o *v21;
  UnityEngine_Component_o *v22;
  UnityEngine_GameObject_o *v23;
  struct System_Collections_Generic_Dictionary_string__TextMeshProUGUI__o *TextObjs;
  System_String_o *v25;
  System_Collections_Generic_Dictionary_object__object__o *v26;
  UnityEngine_Shader_o *v27;
  Il2CppObject *v28;
  Il2CppObject *v29;
  Il2CppObject *v30;
  struct System_Collections_Generic_Dictionary_string__CounterCtr__o *CCtrObjs;
  System_String_o *v32;
  System_Collections_Generic_Dictionary_object__object__o *v33;
  UnityEngine_Shader_o *v34;
  Il2CppObject *v35;
  Il2CppObject *v36;
  Il2CppObject *v37;
  UnityEngine_Transform_o *v38;
  UnityEngine_Object_o *v39;
  System_String_o *v40;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v41;
  UnityEngine_Shader_o *v42;
  UnityEngine_GameObject_o *v43;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v44;
  System_String_o *v45;
  UnityEngine_Component_o *v46;
  UnityEngine_GameObject_o *v47;
  System_Collections_Generic_Dictionary_object__object__o *v48;
  Il2CppObject *v49;
  Il2CppObject *v50;
  Il2CppObject *v52;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v55;
  System_String_o *v56;
  UnityEngine_Component_o *v57;
  UnityEngine_GameObject_o *v58;
  System_Collections_Generic_Dictionary_object__object__o *v59;
  Il2CppObject *v60;
  Il2CppObject *v61;
  Il2CppObject *v63;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v66;
  System_String_o *v67;
  UnityEngine_Component_o *v68;
  UnityEngine_GameObject_o *v69;
  struct System_Collections_Generic_Dictionary_string__TextMeshProUGUI__o *v70;
  System_String_o *v71;
  System_Collections_Generic_Dictionary_object__object__o *v72;
  UnityEngine_Shader_o *v73;
  Il2CppObject *v74;
  Il2CppObject *v75;
  Il2CppObject *v76;
  struct System_Collections_Generic_Dictionary_string__TextMeshProUGUI__o *v77;
  System_String_o *v78;
  System_Collections_Generic_Dictionary_object__object__o *v79;
  UnityEngine_Shader_o *v80;
  Il2CppObject *v81;
  Il2CppObject *v82;
  Il2CppObject *v83;
  struct System_Collections_Generic_Dictionary_string__CounterCtr__o *v84;
  System_String_o *v85;
  System_Collections_Generic_Dictionary_object__object__o *v86;
  UnityEngine_Shader_o *v87;
  Il2CppObject *v88;
  Il2CppObject *v89;
  Il2CppObject *v90;
  UnityEngine_Transform_o *v91;
  UnityEngine_Object_o *v92;
  System_String_o *v93;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v94;
  UnityEngine_Shader_o *v95;
  UnityEngine_GameObject_o *v96;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v97;
  System_String_o *v98;
  UnityEngine_Component_o *v99;
  UnityEngine_GameObject_o *v100;
  System_Collections_Generic_Dictionary_object__object__o *v101;
  Il2CppObject *v102;
  Il2CppObject *v103;
  Il2CppObject *v105;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v108;
  System_String_o *v109;
  UnityEngine_Component_o *v110;
  UnityEngine_GameObject_o *v111;
  System_Collections_Generic_Dictionary_object__object__o *v112;
  Il2CppObject *v113;
  Il2CppObject *v114;
  Il2CppObject *v116;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v119;
  System_String_o *v120;
  UnityEngine_Component_o *v121;
  UnityEngine_GameObject_o *v122;
  struct System_Collections_Generic_Dictionary_string__TextMeshProUGUI__o *v123;
  System_String_o *v124;
  System_Collections_Generic_Dictionary_object__object__o *v125;
  UnityEngine_Shader_o *v126;
  Il2CppObject *v127;
  Il2CppObject *v128;
  Il2CppObject *v129;
  struct System_Collections_Generic_Dictionary_string__TextMeshProUGUI__o *v130;
  System_String_o *v131;
  System_Collections_Generic_Dictionary_object__object__o *v132;
  UnityEngine_Shader_o *v133;
  Il2CppObject *v134;
  Il2CppObject *v135;
  Il2CppObject *v136;
  struct System_Collections_Generic_Dictionary_string__CounterCtr__o *v137;
  System_String_o *v138;
  System_Collections_Generic_Dictionary_object__object__o *v139;
  UnityEngine_Shader_o *v140;
  Il2CppObject *v141;
  Il2CppObject *v142;
  Il2CppObject *v143;
  UnityEngine_Transform_o *v144;
  UnityEngine_Object_o *v145;
  System_String_o *v146;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v147;
  UnityEngine_Shader_o *v148;
  UnityEngine_GameObject_o *v149;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v150;
  System_String_o *v151;
  UnityEngine_Component_o *v152;
  UnityEngine_GameObject_o *v153;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v154;
  System_String_o *v155;
  UnityEngine_Component_o *v156;
  UnityEngine_GameObject_o *v157;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v158;
  System_String_o *v159;
  UnityEngine_Component_o *v160;
  UnityEngine_GameObject_o *v161;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v162;
  System_String_o *v163;
  UnityEngine_Component_o *v164;
  UnityEngine_GameObject_o *v165;
  struct System_Collections_Generic_Dictionary_string__TextMeshProUGUI__o *v166;
  System_String_o *v167;
  System_Collections_Generic_Dictionary_object__object__o *v168;
  UnityEngine_Shader_o *v169;
  Il2CppObject *v170;
  Il2CppObject *v171;
  Il2CppObject *v172;
  struct System_Collections_Generic_Dictionary_string__TextMeshProUGUI__o *v173;
  System_String_o *v174;
  System_Collections_Generic_Dictionary_object__object__o *v175;
  UnityEngine_Shader_o *v176;
  Il2CppObject *v177;
  Il2CppObject *v178;
  Il2CppObject *v179;
  struct System_Collections_Generic_Dictionary_string__TextMeshProUGUI__o *v180;
  System_String_o *v181;
  System_Collections_Generic_Dictionary_object__object__o *v182;
  UnityEngine_Shader_o *v183;
  Il2CppObject *v184;
  Il2CppObject *v185;
  Il2CppObject *v186;
  struct System_Collections_Generic_Dictionary_string__TextMeshProUGUI__o *v187;
  System_String_o *v188;
  System_Collections_Generic_Dictionary_object__object__o *v189;
  UnityEngine_Shader_o *v190;
  Il2CppObject *v191;
  Il2CppObject *v192;
  Il2CppObject *v193;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v194;
  UnityEngine_Transform_o *v195;
  UnityEngine_Component_o *v196;
  UnityEngine_GameObject_o *v197;
  UnityEngine_Transform_o *v198;
  UnityEngine_Object_o *v199;
  System_String_o *v200;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v201;
  UnityEngine_Shader_o *v202;
  UnityEngine_GameObject_o *v203;
  System_Collections_Generic_List_WeakReference__o *v204;
  UnityEngine_Transform_o *v205;
  s32 v206;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *v208;
  s32 v209;
  System_WeakReference_o *v210;
  System_WeakReference_o *v211;
  s32 v212;
  System_WeakReference_o *v213;
  System_WeakReference_o *v214;
  System_String_o *v216;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v218;
  UnityEngine_GameObject_o *v219;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v220;
  System_String_o *v221;
  UnityEngine_Component_o *v222;
  UnityEngine_GameObject_o *v223;
  System_Collections_Generic_Dictionary_object__object__o *v224;
  Il2CppObject *v225;
  Il2CppObject *v226;
  Il2CppObject *v228;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v231;
  System_String_o *v232;
  UnityEngine_Component_o *v233;
  UnityEngine_GameObject_o *v234;
  System_Collections_Generic_Dictionary_object__object__o *v235;
  Il2CppObject *v236;
  Il2CppObject *v237;
  Il2CppObject *v239;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v242;
  System_String_o *v243;
  UnityEngine_Component_o *v244;
  UnityEngine_GameObject_o *v245;
  struct System_Collections_Generic_Dictionary_string__TextMeshProUGUI__o *v246;
  System_String_o *v247;
  System_Collections_Generic_Dictionary_object__object__o *v248;
  UnityEngine_Shader_o *v249;
  Il2CppObject *v250;
  Il2CppObject *v251;
  Il2CppObject *v252;
  struct System_Collections_Generic_Dictionary_string__TextMeshProUGUI__o *v253;
  System_String_o *v254;
  System_Collections_Generic_Dictionary_object__object__o *v255;
  UnityEngine_Shader_o *v256;
  Il2CppObject *v257;
  Il2CppObject *v258;
  Il2CppObject *v259;
  struct System_Collections_Generic_Dictionary_string__CounterCtr__o *v260;
  System_String_o *v261;
  System_Collections_Generic_Dictionary_object__object__o *v262;
  UnityEngine_Shader_o *v263;
  Il2CppObject *v264;
  Il2CppObject *v265;
  Il2CppObject *v266;
  s32 v267;
  u64 *v268;
  System_String_o *v269;
  System_String_o *v271;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v273;
  UnityEngine_Component_o *v274;
  UnityEngine_GameObject_o *v275;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *AnimObjs;
  Il2CppObject *v278;
  Il2CppObject *v279;
  Il2CppObject *v280;
  UnityEngine_Transform_o *v282;
  s32 v283;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v285;
  u64 *v286;
  System_String_o *v287;
  System_String_o *v288;
  UnityEngine_Component_o *v289;
  UnityEngine_GameObject_o *v291;
  UnityEngine_Transform_o *v293;
  UnityEngine_Object_o *v294;
  System_String_o *v296;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v298;
  UnityEngine_GameObject_o *v299;
  UnityEngine_Transform_o *v300;
  s32 v301;
  UnityEngine_Component_o *v302;
  UnityEngine_GameObject_o *v303;
  s32 v304;
  System_WeakReference_o *v305;
  System_WeakReference_o *v306;
  s32 v307;
  System_WeakReference_o *v308;
  UnityEngine_Component_o *v309;
  System_WeakReference_o *v310;
  System_String_o *v312;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v314;
  UnityEngine_GameObject_o *v315;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v316;
  System_String_o *v317;
  UnityEngine_Component_o *v318;
  UnityEngine_GameObject_o *v319;
  System_Collections_Generic_Dictionary_object__object__o *v320;
  Il2CppObject *v321;
  Il2CppObject *v322;
  Il2CppObject *v324;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v327;
  System_String_o *v328;
  UnityEngine_Component_o *v329;
  UnityEngine_GameObject_o *v330;
  System_Collections_Generic_Dictionary_object__object__o *v331;
  Il2CppObject *v332;
  Il2CppObject *v333;
  Il2CppObject *v335;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v338;
  System_String_o *v339;
  UnityEngine_Component_o *v340;
  UnityEngine_GameObject_o *v341;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v342;
  System_String_o *v343;
  UnityEngine_Component_o *v344;
  UnityEngine_GameObject_o *v345;
  System_Collections_Generic_Dictionary_object__object__o *v346;
  Il2CppObject *v347;
  Il2CppObject *v348;
  Il2CppObject *v350;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v353;
  System_String_o *v354;
  UnityEngine_Component_o *v355;
  UnityEngine_GameObject_o *v356;
  System_Collections_Generic_Dictionary_object__object__o *v357;
  Il2CppObject *v358;
  Il2CppObject *v359;
  Il2CppObject *v361;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v364;
  System_String_o *v365;
  UnityEngine_Component_o *v366;
  UnityEngine_GameObject_o *v367;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v368;
  System_String_o *v369;
  UnityEngine_Component_o *v370;
  UnityEngine_GameObject_o *v371;
  struct System_Collections_Generic_Dictionary_string__Animator__o *v372;
  System_String_o *v373;
  System_Collections_Generic_Dictionary_object__object__o *v374;
  UnityEngine_Shader_o *v375;
  Il2CppObject *v376;
  Il2CppObject *v377;
  Il2CppObject *v378;
  System_Collections_Generic_Dictionary_object__object__o *v379;
  Il2CppObject *v380;
  Il2CppObject *v382;
  s32 v383;
  s16 v385;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v386;
  u64 *v387;
  System_String_o *v388;
  System_String_o *v389;
  UnityEngine_Transform_o *v390;
  UnityEngine_Component_o *v391;
  UnityEngine_GameObject_o *v392;
  s32 v393;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v395;
  System_String_o *v396;
  System_Collections_Generic_Dictionary_object__object__o *v397;
  UnityEngine_Shader_o *v398;
  Il2CppObject *v399;
  Il2CppObject *v400;
  Il2CppObject *v401;
  struct System_Collections_Generic_Dictionary_string__TextMeshProUGUI__o *v402;
  System_String_o *v403;
  System_Collections_Generic_Dictionary_object__object__o *v404;
  UnityEngine_Shader_o *v405;
  Il2CppObject *v406;
  Il2CppObject *v407;
  Il2CppObject *v408;
  struct System_Collections_Generic_Dictionary_string__TextMeshProUGUI__o *v409;
  System_String_o *v410;
  System_Collections_Generic_Dictionary_object__object__o *v411;
  UnityEngine_Shader_o *v412;
  Il2CppObject *v413;
  Il2CppObject *v414;
  Il2CppObject *v415;
  struct System_Collections_Generic_Dictionary_string__TextMeshProUGUI__o *v416;
  System_String_o *v417;
  System_Collections_Generic_Dictionary_object__object__o *v418;
  UnityEngine_Shader_o *v419;
  Il2CppObject *v420;
  Il2CppObject *v421;
  Il2CppObject *v422;
  struct System_Collections_Generic_Dictionary_string__CounterCtr__o *v423;
  System_String_o *v424;
  System_Collections_Generic_Dictionary_object__object__o *v425;
  UnityEngine_Shader_o *v426;
  Il2CppObject *v427;
  Il2CppObject *v428;
  Il2CppObject *v429;
  struct System_Collections_Generic_Dictionary_string__CounterCtr__o *v430;
  System_String_o *v431;
  System_Collections_Generic_Dictionary_object__object__o *v432;
  UnityEngine_Shader_o *v433;
  Il2CppObject *v434;
  Il2CppObject *v435;
  Il2CppObject *v436;
  UnityEngine_Transform_o *v437;
  UnityEngine_Component_o *v439;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v441;
  UnityEngine_GameObject_o *v442;
  UnityEngine_Transform_o *v443;
  UnityEngine_Object_o *v444;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v445;
  UnityEngine_Component_o *v446;
  System_String_o *v447;
  UnityEngine_GameObject_o *v448;
  UnityEngine_GameObject_o *v450;
  UnityEngine_Transform_o *v451;
  UnityEngine_Object_o *v452;
  System_String_o *v453;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v454;
  UnityEngine_Shader_o *v455;
  UnityEngine_GameObject_o *v456;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v457;
  System_String_o *v458;
  UnityEngine_Component_o *v459;
  UnityEngine_GameObject_o *v460;
  System_Collections_Generic_Dictionary_object__object__o *v462;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v463;
  Il2CppObject *v464;
  Il2CppObject *v465;
  Il2CppObject *v466;
  UnityEngine_Transform_o *v467;
  UnityEngine_Object_o *v468;
  System_String_o *v469;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v470;
  UnityEngine_Shader_o *v471;
  UnityEngine_GameObject_o *v472;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v473;
  System_String_o *v474;
  UnityEngine_Component_o *v475;
  UnityEngine_GameObject_o *v476;
  System_Collections_Generic_Dictionary_object__object__o *v478;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v479;
  Il2CppObject *v480;
  Il2CppObject *v481;
  Il2CppObject *v482;
  UnityEngine_Transform_o *v483;
  UnityEngine_Component_o *v484;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v485;
  UnityEngine_GameObject_o *v486;
  UnityEngine_Transform_o *v487;
  UnityEngine_Component_o *v488;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v489;
  UnityEngine_GameObject_o *v490;
  UnityEngine_Transform_o *v491;
  UnityEngine_Object_o *v492;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v493;
  UnityEngine_Component_o *v494;
  System_String_o *v495;
  UnityEngine_GameObject_o *v496;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v497;
  UnityEngine_Component_o *v498;
  UnityEngine_GameObject_o *v499;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v500;
  UnityEngine_Component_o *v501;
  UnityEngine_GameObject_o *v502;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v504;
  Il2CppObject *v505;
  UnityEngine_Transform_o *v506;
  UnityEngine_Component_o *v507;
  UnityEngine_GUILayer_o *Component_GUILayer;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v510;
  Il2CppObject *v511;
  UnityEngine_Transform_o *v512;
  UnityEngine_Component_o *v513;
  UnityEngine_GUILayer_o *v514;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v516;
  Il2CppObject *v517;
  UnityEngine_Transform_o *v518;
  UnityEngine_Component_o *v519;
  UnityEngine_GUILayer_o *v520;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v522;
  Il2CppObject *v523;
  UnityEngine_Transform_o *v524;
  UnityEngine_Component_o *v525;
  UnityEngine_GUILayer_o *v526;
  UnityEngine_Transform_o *v527;
  UnityEngine_Object_o *v528;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v529;
  UnityEngine_Component_o *v530;
  System_String_o *v531;
  UnityEngine_GameObject_o *v532;
  UnityEngine_Transform_o *v533;
  UnityEngine_Object_o *v534;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v535;
  UnityEngine_Component_o *v536;
  System_String_o *v537;
  UnityEngine_GameObject_o *v538;
  UnityEngine_Transform_o *v539;
  UnityEngine_Object_o *v540;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v541;
  UnityEngine_Component_o *v542;
  System_String_o *v543;
  UnityEngine_GameObject_o *v544;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v545;
  UnityEngine_Transform_o *v546;
  UnityEngine_Component_o *v547;
  UnityEngine_GameObject_o *v548;
  UnityEngine_Transform_o *v549;
  UnityEngine_Component_o *v550;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v551;
  UnityEngine_Transform_o *v552;
  UnityEngine_GameObject_o *v553;
  System_Collections_Generic_List_WeakReference__o *v554;
  s32 v555;
  UnityEngine_Component_o *v556;
  UnityEngine_GameObject_o *v557;
  s32 v558;
  System_WeakReference_o *v559;
  UnityEngine_Transform_o *v560;
  System_WeakReference_o *v561;
  System_String_o *v563;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v565;
  UnityEngine_Component_o *v566;
  UnityEngine_GameObject_o *v567;
  UnityEngine_Transform_o *v568;
  UnityEngine_Object_o *v570;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v572;
  System_String_o *v573;
  UnityEngine_GameObject_o *v574;
  s32 v575;
  UnityEngine_Component_o *v576;
  UnityEngine_GameObject_o *v577;
  s32 v578;
  System_WeakReference_o *v579;
  System_WeakReference_o *v580;
  s32 v582;
  System_WeakReference_o *v583;
  UnityEngine_Component_o *v584;
  System_WeakReference_o *v585;
  System_String_o *v587;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v589;
  UnityEngine_GameObject_o *v590;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v591;
  System_String_o *v592;
  UnityEngine_Component_o *v593;
  UnityEngine_GameObject_o *v594;
  System_Collections_Generic_Dictionary_object__object__o *v595;
  Il2CppObject *v596;
  Il2CppObject *v597;
  Il2CppObject *v599;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v602;
  System_String_o *v603;
  UnityEngine_Component_o *v604;
  UnityEngine_GameObject_o *v605;
  System_Collections_Generic_Dictionary_object__object__o *v606;
  Il2CppObject *v607;
  Il2CppObject *v608;
  Il2CppObject *v610;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v613;
  System_String_o *v614;
  UnityEngine_Component_o *v615;
  UnityEngine_GameObject_o *v616;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v617;
  System_String_o *v618;
  UnityEngine_Component_o *v619;
  UnityEngine_GameObject_o *v620;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v621;
  System_String_o *v622;
  UnityEngine_Component_o *v623;
  UnityEngine_GameObject_o *v624;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v625;
  System_String_o *v626;
  UnityEngine_Component_o *v627;
  UnityEngine_GameObject_o *v628;
  struct System_Collections_Generic_Dictionary_string__TextMeshProUGUI__o *v629;
  System_String_o *v630;
  System_Collections_Generic_Dictionary_object__object__o *v631;
  UnityEngine_Shader_o *v632;
  Il2CppObject *v633;
  Il2CppObject *v634;
  Il2CppObject *v635;
  struct System_Collections_Generic_Dictionary_string__TextMeshProUGUI__o *v636;
  System_String_o *v637;
  System_Collections_Generic_Dictionary_object__object__o *v638;
  UnityEngine_Shader_o *v639;
  Il2CppObject *v640;
  Il2CppObject *v641;
  Il2CppObject *v642;
  struct System_Collections_Generic_Dictionary_string__CounterCtr__o *v643;
  System_String_o *v644;
  System_Collections_Generic_Dictionary_object__object__o *v645;
  UnityEngine_Shader_o *v646;
  Il2CppObject *v647;
  Il2CppObject *v648;
  Il2CppObject *v649;
  struct System_Collections_Generic_Dictionary_string__CounterCtr__o *v650;
  System_String_o *v651;
  System_Collections_Generic_Dictionary_object__object__o *v652;
  UnityEngine_Shader_o *v653;
  Il2CppObject *v654;
  Il2CppObject *v655;
  Il2CppObject *v656;
  UnityEngine_GameObject_o *v657;
  UnityEngine_Object_o *v659;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v661;
  System_String_o *v662;
  System_String_o *v663;
  UnityEngine_Component_o *v664;
  UnityEngine_GameObject_o *v665;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v666;
  System_String_o *v667;
  System_String_o *v668;
  UnityEngine_Component_o *v669;
  UnityEngine_GameObject_o *v670;
  UnityEngine_Transform_o *v671;
  UnityEngine_Component_o *v672;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v673;
  UnityEngine_Transform_o *v674;
  UnityEngine_GameObject_o *v675;
  s32 v676;
  UnityEngine_Component_o *v677;
  UnityEngine_GameObject_o *v678;
  s32 v679;
  System_WeakReference_o *v680;
  System_WeakReference_o *v681;
  s32 v683;
  System_WeakReference_o *v684;
  UnityEngine_Component_o *v685;
  System_WeakReference_o *v686;
  System_String_o *v688;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v690;
  UnityEngine_GameObject_o *v691;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v692;
  System_String_o *v693;
  UnityEngine_Component_o *v694;
  UnityEngine_GameObject_o *v695;
  System_Collections_Generic_Dictionary_object__object__o *v696;
  Il2CppObject *v697;
  Il2CppObject *v698;
  Il2CppObject *v700;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v703;
  System_String_o *v704;
  UnityEngine_Component_o *v705;
  UnityEngine_GameObject_o *v706;
  System_Collections_Generic_Dictionary_object__object__o *v707;
  Il2CppObject *v708;
  Il2CppObject *v709;
  Il2CppObject *v711;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v714;
  System_String_o *v715;
  UnityEngine_Component_o *v716;
  UnityEngine_GameObject_o *v717;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v718;
  System_String_o *v719;
  UnityEngine_Component_o *v720;
  UnityEngine_GameObject_o *v721;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v722;
  System_String_o *v723;
  UnityEngine_Component_o *v724;
  UnityEngine_GameObject_o *v725;
  struct System_Collections_Generic_Dictionary_string__TextMeshProUGUI__o *v726;
  System_String_o *v727;
  System_Collections_Generic_Dictionary_object__object__o *v728;
  UnityEngine_Shader_o *v729;
  Il2CppObject *v730;
  Il2CppObject *v731;
  Il2CppObject *v732;
  struct System_Collections_Generic_Dictionary_string__TextMeshProUGUI__o *v733;
  System_String_o *v734;
  System_Collections_Generic_Dictionary_object__object__o *v735;
  UnityEngine_Shader_o *v736;
  Il2CppObject *v737;
  Il2CppObject *v738;
  Il2CppObject *v739;
  struct System_Collections_Generic_Dictionary_string__CounterCtr__o *v740;
  System_String_o *v741;
  System_Collections_Generic_Dictionary_object__object__o *v742;
  UnityEngine_Shader_o *v743;
  Il2CppObject *v744;
  Il2CppObject *v745;
  Il2CppObject *v746;
  struct System_Collections_Generic_Dictionary_string__CounterCtr__o *v747;
  System_String_o *v748;
  System_Collections_Generic_Dictionary_object__object__o *v749;
  UnityEngine_Shader_o *v750;
  Il2CppObject *v751;
  Il2CppObject *v752;
  Il2CppObject *v753;
  struct System_Collections_Generic_Dictionary_string__CounterCtr__o *v754;
  System_String_o *v755;
  System_Collections_Generic_Dictionary_object__object__o *v756;
  UnityEngine_Shader_o *v757;
  Il2CppObject *v758;
  Il2CppObject *v759;
  Il2CppObject *v760;
  UnityEngine_GameObject_o *v762;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v764;
  UnityEngine_Transform_o *v765;
  UnityEngine_Component_o *v766;
  UnityEngine_GUILayer_o *v767;
  UnityEngine_GameObject_o *GameObject;
  s32 v769;
  u64 *v770;
  UnityEngine_Component_o *v771;
  s32 v772;
  s32 v773;
  s32 v774;
  s32 v775;

  GameObject = GetGameObject("combmenu");
  transform = get_transform(GameObject, 0);
  v3 = Find(transform, "comname", 0);
  v770 = Allocate(System_Collections_Generic_List_GameObject_);
  __ctor(v770);
  name = get_name(v3);
  PropertySheet___Clear(ListObjs);
  PropertySheet___Clear(TextObjs);
  PropertySheet___Clear(CCtrObjs);
  PropertySheet___Clear(AnimObjs);
  v8 = get_gameObject(v3);
  PropertySheet___Add(ListObjs, name, v8);
  v9 = ListObjs;
  v10 = Concat_5224608(name, "_name");
  v11 = Find(v3, "Text_nameTM", 0);
  v12 = get_gameObject(v11);
  PropertySheet___Add(v9, v10, v12);
  v13 = ListObjs;
  v14 = Concat_5224608(name, "_name");
  Item = object___get_Item(v13, v14);
  Component_object = GetComponent_object_(Item);
  if (op_Inequality(Component_object, 0, 0))
    set_enabled(Component_object, 0);
  v20 = ListObjs;
  v21 = Concat_5224608(name, "_lv");
  v22 = Find(v3, "lv_num", 0);
  v23 = get_gameObject(v22);
  PropertySheet___Add(v20, v21, v23);
  v25 = Concat_5224608(name, "_name");
  v26 = ListObjs;
  v27 = v25;
  v28 = Concat_5224608(name, "_name");
  v29 = object___get_Item(v26, v28);
  v30 = GetComponent_object_(v29);
  PropertySheet___Add(TextObjs, v27, v30);
  v32 = Concat_5224608(name, "_lv");
  v33 = ListObjs;
  v34 = v32;
  v35 = Concat_5224608(name, "_lv");
  v36 = object___get_Item(v33, v35);
  v37 = GetComponent_object_(v36);
  PropertySheet___Add(CCtrObjs, v34, v37);
  v38 = get_transform(GameObject, 0);
  v39 = Find(v38, "comdname01", 0);
  v40 = get_name(v39);
  v41 = ListObjs;
  v42 = v40;
  v43 = get_gameObject(v39);
  PropertySheet___Add(v41, v42, v43);
  v44 = ListObjs;
  v45 = Concat_5224608(v42, "_name");
  v46 = Find(v39, "Text_nameTM", 0);
  v47 = get_gameObject(v46);
  PropertySheet___Add(v44, v45, v47);
  v48 = ListObjs;
  v49 = Concat_5224608(v42, "_name");
  v50 = object___get_Item(v48, v49);
  v52 = GetComponent_object_(v50);
  if (op_Inequality(v52, 0, 0))
    set_enabled(v52, 0);
  v55 = ListObjs;
  v56 = Concat_5224608(v42, "_race");
  v57 = Find(v39, "Tex_raceTM", 0);
  v58 = get_gameObject(v57);
  PropertySheet___Add(v55, v56, v58);
  v59 = ListObjs;
  v60 = Concat_5224608(v42, "_race");
  v61 = object___get_Item(v59, v60);
  v63 = GetComponent_object_(v61);
  if (op_Inequality(v63, 0, 0))
    set_enabled(v63, 0);
  v66 = ListObjs;
  v67 = Concat_5224608(v42, "_lv");
  v68 = Find(v39, "lvnum", 0);
  v69 = get_gameObject(v68);
  PropertySheet___Add(v66, v67, v69);
  v70 = TextObjs;
  v71 = Concat_5224608(v42, "_name");
  v72 = ListObjs;
  v73 = v71;
  v74 = Concat_5224608(v42, "_name");
  v75 = object___get_Item(v72, v74);
  v76 = GetComponent_object_(v75);
  PropertySheet___Add(v70, v73, v76);
  v77 = TextObjs;
  v78 = Concat_5224608(v42, "_race");
  v79 = ListObjs;
  v80 = v78;
  v81 = Concat_5224608(v42, "_race");
  v82 = object___get_Item(v79, v81);
  v83 = GetComponent_object_(v82);
  PropertySheet___Add(v77, v80, v83);
  v84 = CCtrObjs;
  v85 = Concat_5224608(v42, "_lv");
  v86 = ListObjs;
  v87 = v85;
  v88 = Concat_5224608(v42, "_lv");
  v89 = object___get_Item(v86, v88);
  v90 = GetComponent_object_(v89);
  PropertySheet___Add(v84, v87, v90);
  v91 = get_transform(GameObject, 0);
  v92 = Find(v91, "comdname02", 0);
  v93 = get_name(v92);
  v94 = ListObjs;
  v95 = v93;
  v96 = get_gameObject(v92);
  PropertySheet___Add(v94, v95, v96);
  v97 = ListObjs;
  v98 = Concat_5224608(v95, "_name");
  v99 = Find(v92, "Text_nameTM", 0);
  v100 = get_gameObject(v99);
  PropertySheet___Add(v97, v98, v100);
  v101 = ListObjs;
  v102 = Concat_5224608(v95, "_name");
  v103 = object___get_Item(v101, v102);
  v105 = GetComponent_object_(v103);
  if (op_Inequality(v105, 0, 0))
    set_enabled(v105, 0);
  v108 = ListObjs;
  v109 = Concat_5224608(v95, "_race");
  v110 = Find(v92, "Tex_raceTM", 0);
  v111 = get_gameObject(v110);
  PropertySheet___Add(v108, v109, v111);
  v112 = ListObjs;
  v113 = Concat_5224608(v95, "_race");
  v114 = object___get_Item(v112, v113);
  v116 = GetComponent_object_(v114);
  if (op_Inequality(v116, 0, 0))
    set_enabled(v116, 0);
  v119 = ListObjs;
  v120 = Concat_5224608(v95, "_lv");
  v121 = Find(v92, "lvnum", 0);
  v122 = get_gameObject(v121);
  PropertySheet___Add(v119, v120, v122);
  v123 = TextObjs;
  v124 = Concat_5224608(v95, "_name");
  v125 = ListObjs;
  v126 = v124;
  v127 = Concat_5224608(v95, "_name");
  v128 = object___get_Item(v125, v127);
  v129 = GetComponent_object_(v128);
  PropertySheet___Add(v123, v126, v129);
  v130 = TextObjs;
  v131 = Concat_5224608(v95, "_race");
  v132 = ListObjs;
  v133 = v131;
  v134 = Concat_5224608(v95, "_race");
  v135 = object___get_Item(v132, v134);
  v136 = GetComponent_object_(v135);
  PropertySheet___Add(v130, v133, v136);
  v137 = CCtrObjs;
  v138 = Concat_5224608(v95, "_lv");
  v139 = ListObjs;
  v140 = v138;
  v141 = Concat_5224608(v95, "_lv");
  v142 = object___get_Item(v139, v141);
  v143 = GetComponent_object_(v142);
  PropertySheet___Add(v137, v140, v143);
  v144 = get_transform(GameObject, 0);
  v145 = Find(v144, "comguide", 0);
  v146 = get_name(v145);
  v147 = ListObjs;
  v148 = v146;
  v149 = get_gameObject(v145);
  PropertySheet___Add(v147, v148, v149);
  v150 = ListObjs;
  v151 = Concat_5224608(v148, "_icon01");
  v152 = Find(v145, "Text_comicon01TM", 0);
  v153 = get_gameObject(v152);
  PropertySheet___Add(v150, v151, v153);
  v154 = ListObjs;
  v155 = Concat_5224608(v148, "_icon02");
  v156 = Find(v145, "Text_comicon02TM", 0);
  v157 = get_gameObject(v156);
  PropertySheet___Add(v154, v155, v157);
  v158 = ListObjs;
  v159 = Concat_5224608(v148, "_icon03");
  v160 = Find(v145, "Text_comicon03TM", 0);
  v161 = get_gameObject(v160);
  PropertySheet___Add(v158, v159, v161);
  v162 = ListObjs;
  v163 = Concat_5224608(v148, "_icon04");
  v164 = Find(v145, "Text_comicon04TM", 0);
  v165 = get_gameObject(v164);
  PropertySheet___Add(v162, v163, v165);
  v166 = TextObjs;
  v167 = Concat_5224608(v148, "_icon01");
  v168 = ListObjs;
  v169 = v167;
  v170 = Concat_5224608(v148, "_icon01");
  v171 = object___get_Item(v168, v170);
  v172 = GetComponent_object_(v171);
  PropertySheet___Add(v166, v169, v172);
  v173 = TextObjs;
  v174 = Concat_5224608(v148, "_icon02");
  v175 = ListObjs;
  v176 = v174;
  v177 = Concat_5224608(v148, "_icon02");
  v178 = object___get_Item(v175, v177);
  v179 = GetComponent_object_(v178);
  PropertySheet___Add(v173, v176, v179);
  v180 = TextObjs;
  v181 = Concat_5224608(v148, "_icon03");
  v182 = ListObjs;
  v183 = v181;
  v184 = Concat_5224608(v148, "_icon03");
  v185 = object___get_Item(v182, v184);
  v186 = GetComponent_object_(v185);
  PropertySheet___Add(v180, v183, v186);
  v187 = TextObjs;
  v188 = Concat_5224608(v148, "_icon04");
  v189 = ListObjs;
  v190 = v188;
  v191 = Concat_5224608(v148, "_icon04");
  v192 = object___get_Item(v189, v191);
  v193 = GetComponent_object_(v192);
  PropertySheet___Add(v187, v190, v193);
  v194 = ListObjs;
  v195 = get_transform(GameObject, 0);
  v196 = Find(v195, "combase", 0);
  v197 = get_gameObject(v196);
  PropertySheet___Add(v194, "combmenu_base", v197);
  v198 = get_transform(GameObject, 0);
  v199 = Find(v198, "comtable01", 0);
  v200 = get_name(v199);
  v201 = ListObjs;
  v202 = v200;
  v203 = get_gameObject(v199);
  PropertySheet___Add(v201, v202, v203);
  v204 = v770;
  v205 = Find(v199, "comtable_row", 0);
  _Clear(v770);
  if (get_childCount(v205) >= 1)
  {
    v206 = 0;
    do
    {
      Child = GetChild(v205, v206);
      v208 = get_gameObject(Child);
      _Add(v770, v208);
      ++v206;
    }
    while (v206 < get_childCount(v205));
  }
  if (_get_Count(v770) >= 1)
  {
    v209 = 0;
    do
    {
      v210 = _get_Item(
               v770,
               v209);
      if (get_activeSelf(v210))
      {
        v211 = _get_Item(
                 v770,
                 v209);
        SetActive(v211, 0, 0);
      }
      ++v209;
    }
    while (v209 < _get_Count(v770));
  }
  if (_get_Count(v770) >= 1)
  {
    v212 = 0;
    do
    {
      v213 = _get_Item(
               v204,
               v212);
      v771 = get_transform(v213, 0);
      v214 = _get_Item(
               v204,
               v212);
      v216 = get_name(v214);
      v769 = v212;
      v218 = ListObjs;
      v219 = get_gameObject(v771);
      PropertySheet___Add(v218, v216, v219);
      v220 = ListObjs;
      v221 = Concat_5224608(v216, "_name");
      v222 = Find(v771, "Text_nameTM", 0);
      v223 = get_gameObject(v222);
      PropertySheet___Add(v220, v221, v223);
      v224 = ListObjs;
      v225 = Concat_5224608(v216, "_name");
      v226 = object___get_Item(v224, v225);
      v228 = GetComponent_object_(v226);
      if (op_Inequality(v228, 0, 0))
        set_enabled(v228, 0);
      v231 = ListObjs;
      v232 = Concat_5224608(v216, "_race");
      v233 = Find(v771, "Text_raceTM", 0);
      v234 = get_gameObject(v233);
      PropertySheet___Add(v231, v232, v234);
      v235 = ListObjs;
      v236 = Concat_5224608(v216, "_race");
      v237 = object___get_Item(v235, v236);
      v239 = GetComponent_object_(v237);
      if (op_Inequality(v239, 0, 0))
        set_enabled(v239, 0);
      v242 = ListObjs;
      v243 = Concat_5224608(v216, "_lv");
      v244 = Find(v771, "lvnum", 0);
      v245 = get_gameObject(v244);
      PropertySheet___Add(v242, v243, v245);
      v246 = TextObjs;
      v247 = Concat_5224608(v216, "_name");
      v248 = ListObjs;
      v249 = v247;
      v250 = Concat_5224608(v216, "_name");
      v251 = object___get_Item(v248, v250);
      v252 = GetComponent_object_(v251);
      PropertySheet___Add(v246, v249, v252);
      v253 = TextObjs;
      v254 = Concat_5224608(v216, "_race");
      v255 = ListObjs;
      v256 = v254;
      v257 = Concat_5224608(v216, "_race");
      v258 = object___get_Item(v255, v257);
      v259 = GetComponent_object_(v258);
      PropertySheet___Add(v253, v256, v259);
      v260 = CCtrObjs;
      v261 = Concat_5224608(v216, "_lv");
      v262 = ListObjs;
      v263 = v261;
      v264 = Concat_5224608(v216, "_lv");
      v265 = object___get_Item(v262, v264);
      v266 = GetComponent_object_(v265);
      PropertySheet___Add(v260, v263, v266);
      v267 = 0;
      do
      {
        v775 = ++v267;
        v268 = sub_8D3950(s32, &v775);
        v269 = Format("comtable_icon{0:D2}", v268, 0);
        v271 = Concat_5221536(v216, "_", v269);
        v273 = ListObjs;
        v274 = Find(v771, v269, 0);
        v275 = get_gameObject(v274);
        PropertySheet___Add(v273, v271, v275);
        v278 = object___get_Item(ListObjs, v271);
        v279 = GetComponent_object_(v278);
        PropertySheet___Add(AnimObjs, v271, v279);
        v280 = object___get_Item(ListObjs, v271);
        v282 = get_transform(v280, 0);
        v283 = 0;
        {
LABEL_85:
        }
        while (v283 < SLODWORD(cmbIconName->max_length))
        {
          v289 = GetChild(v282, v283);
          v291 = get_gameObject(v289);
          v285 = ListObjs;
          v774 = v283;
          v286 = sub_8D3950(s32, &v774);
          v287 = Format("_{0:D2}", v286, 0);
          v288 = Concat_5224608(v271, v287);
          PropertySheet___Add(v285, v288, v291);
          ++v283;
            goto LABEL_85;
        }
      }
      while (v267 != 12);
      v204 = v770;
      v212 = v769 + 1;
    }
    while (v769 + 1 < _get_Count(v770));
  }
  v293 = get_transform(GameObject, 0);
  v294 = Find(v293, "comtable02", 0);
  v296 = get_name(v294);
  v298 = ListObjs;
  v299 = get_gameObject(v294);
  PropertySheet___Add(v298, v296, v299);
  v300 = Find(v294, "comtable_row", 0);
  _Clear(v204);
  if (get_childCount(v300) >= 1)
  {
    v301 = 0;
    do
    {
      v302 = GetChild(v300, v301);
      v303 = get_gameObject(v302);
      _Add(v204, v303);
      ++v301;
    }
    while (v301 < get_childCount(v300));
  }
  if (_get_Count(v204) >= 1)
  {
    v304 = 0;
    do
    {
      v305 = _get_Item(
               v204,
               v304);
      if (get_activeSelf(v305))
      {
        v306 = _get_Item(
                 v204,
                 v304);
        SetActive(v306, 0, 0);
      }
      ++v304;
    }
    while (v304 < _get_Count(v204));
  }
  if (_get_Count(v204) >= 1)
  {
    v307 = 0;
    do
    {
      v308 = _get_Item(
               v204,
               v307);
      v309 = get_transform(v308, 0);
      v310 = _get_Item(
               v204,
               v307);
      v312 = get_name(v310);
      v772 = v307;
      v314 = ListObjs;
      v315 = get_gameObject(v309);
      PropertySheet___Add(v314, v312, v315);
      v316 = ListObjs;
      v317 = Concat_5224608(v312, "_name1");
      v318 = Find(v309, "Text_name01TM", 0);
      v319 = get_gameObject(v318);
      PropertySheet___Add(v316, v317, v319);
      v320 = ListObjs;
      v321 = Concat_5224608(v312, "_name1");
      v322 = object___get_Item(v320, v321);
      v324 = GetComponent_object_(v322);
      if (op_Inequality(v324, 0, 0))
        set_enabled(v324, 0);
      v327 = ListObjs;
      v328 = Concat_5224608(v312, "_race1");
      v329 = Find(v309, "Text_race01TM", 0);
      v330 = get_gameObject(v329);
      PropertySheet___Add(v327, v328, v330);
      v331 = ListObjs;
      v332 = Concat_5224608(v312, "_race1");
      v333 = object___get_Item(v331, v332);
      v335 = GetComponent_object_(v333);
      if (op_Inequality(v335, 0, 0))
        set_enabled(v335, 0);
      v338 = ListObjs;
      v339 = Concat_5224608(v312, "_lv1");
      v340 = Find(v309, "lvnum01", 0);
      v341 = get_gameObject(v340);
      PropertySheet___Add(v338, v339, v341);
      v342 = ListObjs;
      v343 = Concat_5224608(v312, "_name2");
      v344 = Find(v309, "Text_name02TM", 0);
      v345 = get_gameObject(v344);
      PropertySheet___Add(v342, v343, v345);
      v346 = ListObjs;
      v347 = Concat_5224608(v312, "_name2");
      v348 = object___get_Item(v346, v347);
      v350 = GetComponent_object_(v348);
      if (op_Inequality(v350, 0, 0))
        set_enabled(v350, 0);
      v353 = ListObjs;
      v354 = Concat_5224608(v312, "_race2");
      v355 = Find(v309, "Text_race02TM", 0);
      v356 = get_gameObject(v355);
      PropertySheet___Add(v353, v354, v356);
      v357 = ListObjs;
      v358 = Concat_5224608(v312, "_race2");
      v359 = object___get_Item(v357, v358);
      v361 = GetComponent_object_(v359);
      if (op_Inequality(v361, 0, 0))
        set_enabled(v361, 0);
      v364 = ListObjs;
      v365 = Concat_5224608(v312, "_lv2");
      v366 = Find(v309, "lvnum02", 0);
      v367 = get_gameObject(v366);
      PropertySheet___Add(v364, v365, v367);
      v368 = ListObjs;
      v369 = Concat_5224608(v312, "_icon");
      v370 = Find(v309, "comtable_icon", 0);
      v371 = get_gameObject(v370);
      PropertySheet___Add(v368, v369, v371);
      v372 = AnimObjs;
      v373 = Concat_5224608(v312, "_icon");
      v374 = ListObjs;
      v375 = v373;
      v376 = Concat_5224608(v312, "_icon");
      v377 = object___get_Item(v374, v376);
      v378 = GetComponent_object_(v377);
      PropertySheet___Add(v372, v375, v378);
      v379 = ListObjs;
      v380 = Concat_5224608(v312, "_icon");
      v382 = object___get_Item(v379, v380);
      v383 = 0;
      if ((v385 & 0x200) == 0)
      {
LABEL_144:
        v393 = 0;
        goto LABEL_148;
      }
      while (1)
      {
        v393 = v385 & 0x200;
LABEL_148:
        if (v383 >= SLODWORD(cmbIconName->max_length))
          break;
        v386 = ListObjs;
        v773 = v383;
        v387 = sub_8D3950(s32, &v773);
        v388 = Format("_icon{0:D2}", v387, 0);
        v389 = Concat_5224608(v312, v388);
        v390 = get_transform(v382, 0);
        v391 = GetChild(v390, v383);
        v392 = get_gameObject(v391);
        PropertySheet___Add(v386, v389, v392);
        ++v383;
        if ((v385 & 0x200) == 0)
          goto LABEL_144;
      }
      v395 = TextObjs;
      v396 = Concat_5224608(v312, "_name1");
      v397 = ListObjs;
      v398 = v396;
      v399 = Concat_5224608(v312, "_name1");
      v400 = object___get_Item(v397, v399);
      v401 = GetComponent_object_(v400);
      PropertySheet___Add(v395, v398, v401);
      v402 = TextObjs;
      v403 = Concat_5224608(v312, "_race1");
      v404 = ListObjs;
      v405 = v403;
      v406 = Concat_5224608(v312, "_race1");
      v407 = object___get_Item(v404, v406);
      v408 = GetComponent_object_(v407);
      PropertySheet___Add(v402, v405, v408);
      v409 = TextObjs;
      v410 = Concat_5224608(v312, "_name2");
      v411 = ListObjs;
      v412 = v410;
      v413 = Concat_5224608(v312, "_name2");
      v414 = object___get_Item(v411, v413);
      v415 = GetComponent_object_(v414);
      PropertySheet___Add(v409, v412, v415);
      v416 = TextObjs;
      v417 = Concat_5224608(v312, "_race2");
      v418 = ListObjs;
      v419 = v417;
      v420 = Concat_5224608(v312, "_race2");
      v421 = object___get_Item(v418, v420);
      v422 = GetComponent_object_(v421);
      PropertySheet___Add(v416, v419, v422);
      v423 = CCtrObjs;
      v424 = Concat_5224608(v312, "_lv1");
      v425 = ListObjs;
      v426 = v424;
      v427 = Concat_5224608(v312, "_lv1");
      v428 = object___get_Item(v425, v427);
      v429 = GetComponent_object_(v428);
      PropertySheet___Add(v423, v426, v429);
      v430 = CCtrObjs;
      v431 = Concat_5224608(v312, "_lv2");
      v432 = ListObjs;
      v433 = v431;
      v434 = Concat_5224608(v312, "_lv2");
      v435 = object___get_Item(v432, v434);
      v436 = GetComponent_object_(v435);
      PropertySheet___Add(v430, v433, v436);
      v204 = v770;
      ++v307;
    }
    while (v772 + 1 < _get_Count(v770));
  }
  v437 = get_transform(GameObject, 0);
  v439 = Find(v437, "menu_cursur", 0);
  v441 = ListObjs;
  v442 = get_gameObject(v439);
  PropertySheet___Add(v441, "combmenu_cursor", v442);
  v443 = get_transform(GameObject, 0);
  v444 = Find(v443, "comlisttex_numt", 0);
  v445 = ListObjs;
  v446 = v444;
  v447 = get_name(v444);
  v448 = get_gameObject(v446);
  PropertySheet___Add(v445, v447, v448);
  v450 = GetGameObject("dlistsum");
  v451 = get_transform(v450, 0);
  v452 = Find(v451, "dlistmoney_base", 0);
  v453 = get_name(v452);
  v454 = ListObjs;
  v455 = v453;
  v456 = get_gameObject(v452);
  PropertySheet___Add(v454, v455, v456);
  v457 = ListObjs;
  v458 = Concat_5224608(v455, "_money");
  v459 = Find(v452, "num_money", 0);
  v460 = get_gameObject(v459);
  PropertySheet___Add(v457, v458, v460);
  v462 = ListObjs;
  v463 = CCtrObjs;
  v464 = Concat_5224608(v455, "_money");
  v465 = object___get_Item(v462, v464);
  v466 = GetComponent_object_(v465);
  PropertySheet___Add(v463, v455, v466);
  v467 = get_transform(v450, 0);
  v468 = Find(v467, "dlistsum_ratio", 0);
  v469 = get_name(v468);
  v470 = ListObjs;
  v471 = v469;
  v472 = get_gameObject(v468);
  PropertySheet___Add(v470, v471, v472);
  v473 = ListObjs;
  v474 = Concat_5224608(v471, "_ratio");
  v475 = Find(v468, "num_dlistratio", 0);
  v476 = get_gameObject(v475);
  PropertySheet___Add(v473, v474, v476);
  v478 = ListObjs;
  v479 = CCtrObjs;
  v480 = Concat_5224608(v471, "_ratio");
  v481 = object___get_Item(v478, v480);
  v482 = GetComponent_object_(v481);
  PropertySheet___Add(v479, v471, v482);
  v483 = get_transform(v450, 0);
  v484 = Find(v483, "dlistsumscroll", 0);
  v485 = ListObjs;
  v486 = get_gameObject(v484);
  PropertySheet___Add(v485, "dlistsum_scroll", v486);
  v487 = get_transform(v450, 0);
  v488 = Find(v487, "menu_cursur", 0);
  v489 = ListObjs;
  v490 = get_gameObject(v488);
  PropertySheet___Add(v489, "dlistsum_cursor", v490);
  v491 = get_transform(v450, 0);
  v492 = Find(v491, "dlistsumlr_base", 0);
  v493 = ListObjs;
  v494 = v492;
  v495 = get_name(v492);
  v496 = get_gameObject(v494);
  PropertySheet___Add(v493, v495, v496);
  v497 = ListObjs;
  v498 = Find(v494, "dlistsort01", 0);
  v499 = get_gameObject(v498);
  PropertySheet___Add(v497, "dlistsum_race", v499);
  v500 = ListObjs;
  v501 = Find(v494, "dlistsort02", 0);
  v502 = get_gameObject(v501);
  PropertySheet___Add(v500, "dlistsum_level", v502);
  v504 = TextObjs;
  v505 = object___get_Item(ListObjs, "dlistsum_race");
  v506 = get_transform(v505, 0);
  v507 = Find(v506, "Text_sortTM", 0);
  Component_GUILayer = GetComponent_GUILayer_(v507);
  PropertySheet___Add(v504, "dlistsum_race1", Component_GUILayer);
  v510 = TextObjs;
  v511 = object___get_Item(ListObjs, "dlistsum_race");
  v512 = get_transform(v511, 0);
  v513 = Find(v512, "Text_sortTM/Text_sortgTM", 0);
  v514 = GetComponent_GUILayer_(v513);
  PropertySheet___Add(v510, "dlistsum_race2", v514);
  v516 = TextObjs;
  v517 = object___get_Item(ListObjs, "dlistsum_level");
  v518 = get_transform(v517, 0);
  v519 = Find(v518, "Text_sortTM", 0);
  v520 = GetComponent_GUILayer_(v519);
  PropertySheet___Add(v516, "dlistsum_level1", v520);
  v522 = TextObjs;
  v523 = object___get_Item(ListObjs, "dlistsum_level");
  v524 = get_transform(v523, 0);
  v525 = Find(v524, "Text_sortTM/Text_sortgTM", 0);
  v526 = GetComponent_GUILayer_(v525);
  PropertySheet___Add(v522, "dlistsum_level2", v526);
  v527 = get_transform(v450, 0);
  v528 = Find(v527, "dlistsumindex_base", 0);
  v529 = ListObjs;
  v530 = v528;
  v531 = get_name(v528);
  v532 = get_gameObject(v530);
  PropertySheet___Add(v529, v531, v532);
  v533 = get_transform(v450, 0);
  v534 = Find(v533, "dlistsum_base", 0);
  v535 = ListObjs;
  v536 = v534;
  v537 = get_name(v534);
  v538 = get_gameObject(v536);
  PropertySheet___Add(v535, v537, v538);
  v539 = get_transform(v450, 0);
  v540 = Find(v539, "dlistsumscroll", 0);
  v541 = ListObjs;
  v542 = v540;
  v543 = get_name(v540);
  v544 = get_gameObject(v542);
  PropertySheet___Add(v541, v543, v544);
  v545 = ListObjs;
  v546 = get_transform(v450, 0);
  v547 = Find(v546, "combase", 0);
  v548 = get_gameObject(v547);
  PropertySheet___Add(v545, "dlistsum_combase", v548);
  v549 = get_transform(v450, 0);
  v550 = Find(v549, "dlistsum_rule", 0);
  v551 = ListObjs;
  v552 = v550;
  v553 = get_gameObject(v550);
  PropertySheet___Add(v551, "dlistsum_rule", v553);
  v554 = v770;
  _Clear(v770);
  if (get_childCount(v552) >= 1)
  {
    v555 = 0;
    do
    {
      v556 = GetChild(v552, v555);
      v557 = get_gameObject(v556);
      _Add(v770, v557);
      ++v555;
    }
    while (v555 < get_childCount(v552));
  }
  if (_get_Count(v770) >= 1)
  {
    v558 = 0;
    do
    {
      v559 = _get_Item(
               v554,
               v558);
      v560 = get_transform(v559, 0);
      v561 = _get_Item(
               v554,
               v558);
      v563 = get_name(v561);
      v565 = ListObjs;
      v566 = Find(v560, "dlist_rule01", 0);
      v567 = get_gameObject(v566);
      PropertySheet___Add(v565, v563, v567);
      v554 = v770;
      ++v558;
    }
    while (v558 < _get_Count(v770));
  }
  v568 = get_transform(v450, 0);
  v570 = Find(v568, "dlistsum_row", 0);
  v572 = ListObjs;
  v573 = get_name(v570);
  v574 = get_gameObject(v570);
  PropertySheet___Add(v572, v573, v574);
  _Clear(v554);
  if (get_childCount(v570) >= 1)
  {
    v575 = 0;
    do
    {
      v576 = GetChild(v570, v575);
      v577 = get_gameObject(v576);
      _Add(v554, v577);
      ++v575;
    }
    while (v575 < get_childCount(v570));
  }
  if (_get_Count(v554) >= 1)
  {
    v578 = 0;
    do
    {
      v579 = _get_Item(
               v554,
               v578);
      if (get_activeSelf(v579))
      {
        v580 = _get_Item(
                 v554,
                 v578);
        SetActive(v580, 0, 0);
      }
      ++v578;
    }
    while (v578 < _get_Count(v554));
  }
  if (_get_Count(v554) >= 1)
  {
    v582 = 0;
    do
    {
      v583 = _get_Item(
               v554,
               v582);
      v584 = get_transform(v583, 0);
      v585 = _get_Item(
               v554,
               v582);
      v587 = get_name(v585);
      v589 = ListObjs;
      v590 = get_gameObject(v584);
      PropertySheet___Add(v589, v587, v590);
      v591 = ListObjs;
      v592 = Concat_5224608(v587, "_name");
      v593 = Find(v584, "Text_nameTM", 0);
      v594 = get_gameObject(v593);
      PropertySheet___Add(v591, v592, v594);
      v595 = ListObjs;
      v596 = Concat_5224608(v587, "_name");
      v597 = object___get_Item(v595, v596);
      v599 = GetComponent_object_(v597);
      if (op_Inequality(v599, 0, 0))
        set_enabled(v599, 0);
      v602 = ListObjs;
      v603 = Concat_5224608(v587, "_race");
      v604 = Find(v584, "Text_raceTM", 0);
      v605 = get_gameObject(v604);
      PropertySheet___Add(v602, v603, v605);
      v606 = ListObjs;
      v607 = Concat_5224608(v587, "_race");
      v608 = object___get_Item(v606, v607);
      v610 = GetComponent_object_(v608);
      if (op_Inequality(v610, 0, 0))
        set_enabled(v610, 0);
      v613 = ListObjs;
      v614 = Concat_5224608(v587, "_lv");
      v615 = Find(v584, "lvnum", 0);
      v616 = get_gameObject(v615);
      PropertySheet___Add(v613, v614, v616);
      v617 = ListObjs;
      v618 = Concat_5224608(v587, "_money");
      v619 = Find(v584, "moneynum", 0);
      v620 = get_gameObject(v619);
      PropertySheet___Add(v617, v618, v620);
      v621 = ListObjs;
      v622 = Concat_5224608(v587, "_mak00");
      v623 = Find(v584, "dlisttex_summakka00", 0);
      v624 = get_gameObject(v623);
      PropertySheet___Add(v621, v622, v624);
      v625 = ListObjs;
      v626 = Concat_5224608(v587, "_mak01");
      v627 = Find(v584, "dlisttex_summakka01", 0);
      v628 = get_gameObject(v627);
      PropertySheet___Add(v625, v626, v628);
      v629 = TextObjs;
      v630 = Concat_5224608(v587, "_name");
      v631 = ListObjs;
      v632 = v630;
      v633 = Concat_5224608(v587, "_name");
      v634 = object___get_Item(v631, v633);
      v635 = GetComponent_object_(v634);
      PropertySheet___Add(v629, v632, v635);
      v636 = TextObjs;
      v637 = Concat_5224608(v587, "_race");
      v638 = ListObjs;
      v639 = v637;
      v640 = Concat_5224608(v587, "_race");
      v641 = object___get_Item(v638, v640);
      v642 = GetComponent_object_(v641);
      PropertySheet___Add(v636, v639, v642);
      v643 = CCtrObjs;
      v644 = Concat_5224608(v587, "_lv");
      v645 = ListObjs;
      v646 = v644;
      v647 = Concat_5224608(v587, "_lv");
      v648 = object___get_Item(v645, v647);
      v649 = GetComponent_object_(v648);
      PropertySheet___Add(v643, v646, v649);
      v650 = CCtrObjs;
      v651 = Concat_5224608(v587, "_money");
      v652 = ListObjs;
      v653 = v651;
      v654 = Concat_5224608(v587, "_money");
      v655 = object___get_Item(v652, v654);
      v656 = GetComponent_object_(v655);
      PropertySheet___Add(v650, v653, v656);
      v554 = v770;
      ++v582;
    }
    while (v582 < _get_Count(v770));
  }
  v657 = GetGameObject("dlistrec");
  v659 = get_transform(v657, 0);
  v661 = ListObjs;
  v662 = get_name(v659);
  v663 = Concat_5224608(v662, "_scroll");
  v664 = Find(v659, "dlistrecscroll", 0);
  v665 = get_gameObject(v664);
  PropertySheet___Add(v661, v663, v665);
  v666 = ListObjs;
  v667 = get_name(v659);
  v668 = Concat_5224608(v667, "_cursor");
  v669 = Find(v659, "menu_cursur", 0);
  v670 = get_gameObject(v669);
  PropertySheet___Add(v666, v668, v670);
  v671 = get_transform(v657, 0);
  v672 = Find(v671, "dlistsum_row", 0);
  v673 = ListObjs;
  v674 = v672;
  v675 = get_gameObject(v672);
  PropertySheet___Add(v673, "dlistrec_row", v675);
  _Clear(v554);
  if (get_childCount(v674) >= 1)
  {
    v676 = 0;
    do
    {
      v677 = GetChild(v674, v676);
      v678 = get_gameObject(v677);
      _Add(v554, v678);
      ++v676;
    }
    while (v676 < get_childCount(v674));
  }
  if (_get_Count(v554) >= 1)
  {
    v679 = 0;
    do
    {
      v680 = _get_Item(
               v554,
               v679);
      if (get_activeSelf(v680))
      {
        v681 = _get_Item(
                 v554,
                 v679);
        SetActive(v681, 0, 0);
      }
      ++v679;
    }
    while (v679 < _get_Count(v554));
  }
  if (_get_Count(v554) >= 1)
  {
    v683 = 0;
    do
    {
      v684 = _get_Item(
               v554,
               v683);
      v685 = get_transform(v684, 0);
      v686 = _get_Item(
               v554,
               v683);
      v688 = get_name(v686);
      v690 = ListObjs;
      v691 = get_gameObject(v685);
      PropertySheet___Add(v690, v688, v691);
      v692 = ListObjs;
      v693 = Concat_5224608(v688, "_name");
      v694 = Find(v685, "Text_nameTM", 0);
      v695 = get_gameObject(v694);
      PropertySheet___Add(v692, v693, v695);
      v696 = ListObjs;
      v697 = Concat_5224608(v688, "_name");
      v698 = object___get_Item(v696, v697);
      v700 = GetComponent_object_(v698);
      if (op_Inequality(v700, 0, 0))
        set_enabled(v700, 0);
      v703 = ListObjs;
      v704 = Concat_5224608(v688, "_race");
      v705 = Find(v685, "Text_raceTM", 0);
      v706 = get_gameObject(v705);
      PropertySheet___Add(v703, v704, v706);
      v707 = ListObjs;
      v708 = Concat_5224608(v688, "_race");
      v709 = object___get_Item(v707, v708);
      v711 = GetComponent_object_(v709);
      if (op_Inequality(v711, 0, 0))
        set_enabled(v711, 0);
      v714 = ListObjs;
      v715 = Concat_5224608(v688, "_hp");
      v716 = Find(v685, "hpnum", 0);
      v717 = get_gameObject(v716);
      PropertySheet___Add(v714, v715, v717);
      v718 = ListObjs;
      v719 = Concat_5224608(v688, "_mp");
      v720 = Find(v685, "mpnum", 0);
      v721 = get_gameObject(v720);
      PropertySheet___Add(v718, v719, v721);
      v722 = ListObjs;
      v723 = Concat_5224608(v688, "_lv");
      v724 = Find(v685, "lvnum", 0);
      v725 = get_gameObject(v724);
      PropertySheet___Add(v722, v723, v725);
      v726 = TextObjs;
      v727 = Concat_5224608(v688, "_name");
      v728 = ListObjs;
      v729 = v727;
      v730 = Concat_5224608(v688, "_name");
      v731 = object___get_Item(v728, v730);
      v732 = GetComponent_object_(v731);
      PropertySheet___Add(v726, v729, v732);
      v733 = TextObjs;
      v734 = Concat_5224608(v688, "_race");
      v735 = ListObjs;
      v736 = v734;
      v737 = Concat_5224608(v688, "_race");
      v738 = object___get_Item(v735, v737);
      v739 = GetComponent_object_(v738);
      PropertySheet___Add(v733, v736, v739);
      v740 = CCtrObjs;
      v741 = Concat_5224608(v688, "_hp");
      v742 = ListObjs;
      v743 = v741;
      v744 = Concat_5224608(v688, "_hp");
      v745 = object___get_Item(v742, v744);
      v746 = GetComponent_object_(v745);
      PropertySheet___Add(v740, v743, v746);
      v747 = CCtrObjs;
      v748 = Concat_5224608(v688, "_mp");
      v749 = ListObjs;
      v750 = v748;
      v751 = Concat_5224608(v688, "_mp");
      v752 = object___get_Item(v749, v751);
      v753 = GetComponent_object_(v752);
      PropertySheet___Add(v747, v750, v753);
      v754 = CCtrObjs;
      v755 = Concat_5224608(v688, "_lv");
      v756 = ListObjs;
      v757 = v755;
      v758 = Concat_5224608(v688, "_lv");
      v759 = object___get_Item(v756, v758);
      v760 = GetComponent_object_(v759);
      PropertySheet___Add(v754, v757, v760);
      v554 = v770;
      ++v683;
    }
    while (v683 < _get_Count(v770));
  }
  v762 = GetGameObject("comtitle");
  v764 = TextObjs;
  v765 = get_transform(v762, 0);
  v766 = Find(v765, "Text_comtitleTM", 0);
  v767 = GetComponent_GUILayer_(v766);
  PropertySheet___Add(v764, "comtitle", v767);
}

// 0x1469760
void UpdateDevilList(s32 mode) {
  switch (mode)
  {
    case 8:
      cmbCalcDevSelSac();
      cmbDrawInfoWindow(2);
      cmbDrawSelDevilInfo(2, CMB_GBWK->HelpFlag);
      cmbDrawSacDevilSelect();
      break;
    case 6:
      cmbCalcDevSel2nd();
      cmbDrawInfoWindow(1);
      cmbDrawSelDevilInfo(1, CMB_GBWK->HelpFlag);
      cmbDraw2ndDevilSelect();
      break;
    case 5:
      cmbCalcDevSel1st();
      cmbDrawInfoWindow(0);
      cmbDrawSelDevilInfo(0, CMB_GBWK->HelpFlag);
      cmbDraw1stDevilSelect();
      break;
  }
}
