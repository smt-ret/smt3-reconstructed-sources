#include "types.h"

typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct pbHelp_t pbHelp_t;
typedef struct pbProcHandle_t pbProcHandle_t;

struct pbHelp_t {
    u32 page;
};

static s32 NmlCnt;
static char *pbHelpLcl[12];

bool DDS3_PADCHECK_TRIG(s32 id);
s32 FindId(s32 type, char *name);
char *GetLocalizeText(char *ID);
void *GetoPB_UI(void);
char *RepColTag(char *txt, void **LegacyParamArray);
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
void dds3SetProcessData(dds3ProcessID_t **id, void *data);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
s32 p2sdPlaySE(s32 a);
pbProcHandle_t *pbStartHelp(pbProcHandle_t *parent, u32 page);

// 0x14a1360
dds3ProcessFunc_t *deleteHelp(dds3ProcessID_t *id) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v7;
  u64 *image;
  s64 v9;
  char *v10;
  s64 *v11;
  char *v14;
  s64 *v15;
  u64 v16[2];
  char *v17;

  workdata = id->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbProcHandle_t)
  {
    sub_8FC2C0(klass->_1.element_class, pbProcHandle_t, v16);
    if ((v16[0] & 1) != 0)
      v14 = v17;
    else
      v14 = v16 + 1;
    v15 = sub_8C4940(v14);
  }
  v7 = workdata[2].klass;
  else if (!v7)
  {
    goto LABEL_15;
  }
  image = v7->_1.image;
  if (*(v7->_1.image + 288) < v9 || *(image[25] + 8 * v9 - 8) != pbHelp_t)
  {
    sub_8FC2C0(image[8], pbHelp_t, v16);
    if ((v16[0] & 1) != 0)
      v10 = v17;
    else
      v10 = v16 + 1;
    v11 = sub_8C4940(v10);
  }
LABEL_15:
  pbWk->help_proc = 0;
  return 0;
}

// 0x149fd40
dds3ProcessFunc_t *help(dds3ProcessID_t *id) {
  UnityEngine_GameObject_o *v2;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v4;
  UnityEngine_GameObject_o *gameObject;
  s32 v9;
  s32 v10;
  s32 v12;
  u64 *v13;
  System_String_o *v14;
  System_String_o *v15;
  UnityEngine_Transform_o *v16;
  UnityEngine_Component_o *v17;
  UnityEngine_GameObject_o *v18;
  Il2CppObject *Component_object;
  struct System_String_array *pbHelpLcl;
  s64 v25;
  System_String_o *v27;
  System_String_o *LocalizeText;
  System_Object_array *v29;
  System_Object_array *v30;
  s64 *v31;
  s64 *v33;
  System_String_o *v35;
  u32 v36;
  u64 *v38;
  System_String_o *v39;
  System_String_o *v40;
  UnityEngine_Transform_o *v41;
  UnityEngine_Component_o *v42;
  UnityEngine_GameObject_o *v43;
  Il2CppObject *v44;
  struct System_String_array *v47;
  s64 v48;
  TMPro_TMP_Text_o *v49;
  System_String_o *v51;
  System_String_o *v52;
  System_Object_array *v53;
  s64 *v54;
  s64 *v56;
  System_String_o *v58;
  u64 *v61;
  System_String_o *v62;
  System_String_o *v63;
  UnityEngine_Transform_o *v64;
  UnityEngine_Component_o *v65;
  UnityEngine_GameObject_o *v66;
  Il2CppObject *v67;
  struct System_String_array *v70;
  s64 v71;
  TMPro_TMP_Text_o *v72;
  System_String_o *v74;
  System_String_o *v75;
  System_Object_array *v76;
  System_Object_array *v77;
  s64 *v78;
  s64 *v80;
  System_String_o *v82;
  UnityEngine_Transform_o *v85;
  UnityEngine_Component_o *v86;
  UnityEngine_GameObject_o *v87;
  Il2CppObject *v88;
  struct System_String_array *v91;
  s64 v92;
  TMPro_TMP_Text_o *v93;
  System_String_o *v95;
  System_String_o *v96;
  System_Object_array *v97;
  System_Object_array *v98;
  s64 *v99;
  s64 *v101;
  System_String_o *v103;
  u64 *v106;
  System_String_o *v107;
  System_String_o *v108;
  UnityEngine_Transform_o *v109;
  UnityEngine_Component_o *v110;
  UnityEngine_GameObject_o *v111;
  Il2CppObject *v112;
  struct System_String_array *v115;
  s64 v116;
  TMPro_TMP_Text_o *v117;
  System_String_o *v119;
  System_String_o *v120;
  System_Object_array *v121;
  System_Object_array *v122;
  s64 *v123;
  s64 *v125;
  System_String_o *v127;
  u64 *v130;
  System_String_o *v131;
  System_String_o *v132;
  UnityEngine_Transform_o *v133;
  UnityEngine_Component_o *v134;
  UnityEngine_GameObject_o *v135;
  Il2CppObject *v136;
  struct System_String_array *v139;
  s64 v140;
  TMPro_TMP_Text_o *v141;
  System_String_o *v143;
  System_String_o *v144;
  System_Object_array *v145;
  System_Object_array *v146;
  s64 *v147;
  s64 *v149;
  System_String_o *v151;
  UnityEngine_Transform_o *v152;
  UnityEngine_Component_o *v153;
  UnityEngine_GameObject_o *v154;
  Il2CppObject *v156;
  struct System_String_array *v159;
  s64 v160;
  System_String_o *v162;
  System_String_o *v163;
  System_Object_array *v164;
  System_Object_array *v165;
  s64 *v166;
  s64 *v168;
  System_String_o *v170;
  u64 *v171;
  System_String_o *v172;
  System_String_o *v173;
  UnityEngine_Transform_o *v174;
  UnityEngine_Component_o *v175;
  UnityEngine_GameObject_o *v176;
  Il2CppObject *v177;
  struct System_String_array *v179;
  s64 v180;
  TMPro_TMP_Text_o *v181;
  System_String_o *v183;
  System_Object_array *v184;
  s64 *v185;
  s64 *v186;
  System_String_o *v188;
  UnityEngine_Transform_o *v189;
  UnityEngine_Component_o *v190;
  UnityEngine_GameObject_o *v191;
  Il2CppObject *v192;
  struct System_String_array *v194;
  s64 v195;
  TMPro_TMP_Text_o *v196;
  System_String_o *v198;
  System_Object_array *v199;
  s64 *v200;
  s64 *v201;
  System_String_o *v203;
  u64 *v206;
  System_String_o *v207;
  System_String_o *v208;
  UnityEngine_Transform_o *v209;
  UnityEngine_Component_o *v210;
  UnityEngine_GameObject_o *v211;
  Il2CppObject *v212;
  struct System_String_array *v215;
  s64 v216;
  TMPro_TMP_Text_o *v217;
  System_String_o *v219;
  System_String_o *v220;
  System_Object_array *v221;
  System_Object_array *v222;
  s64 *v223;
  s64 *v225;
  System_String_o *v227;
  u64 *v230;
  System_String_o *v231;
  System_String_o *v232;
  UnityEngine_Transform_o *v233;
  UnityEngine_Component_o *v234;
  UnityEngine_GameObject_o *v235;
  Il2CppObject *v236;
  struct System_String_array *v239;
  s64 v240;
  TMPro_TMP_Text_o *v241;
  System_String_o *v243;
  System_String_o *v244;
  System_Object_array *v245;
  System_Object_array *v246;
  s64 *v247;
  s64 *v249;
  System_String_o *v251;
  s32 v267;
  UnityEngine_GameObject_o *v269;
  s32 v271;
  s32 v272;
  s32 v273;
  s32 NmlCnt;

  v2 = GetoPB_UI();
  transform = get_transform(v2, 0);
  v4 = Find(transform, "pzlhelp", 0);
  gameObject = get_gameObject(v4);
  if (!get_activeSelf(gameObject))
    SetActive(gameObject, 1, 0);
  v269 = gameObject;
  NmlCnt = 1;
  v9 = 0;
  do
  {
    v12 = v9;
    v13 = sub_8D3950(s32, &NmlCnt);
    v14 = Format("pzlhelp_index{0:00}/Text_pzlhelpindex{0:00}", v13, 0);
    v15 = Concat_5224608("pzlhelp/", v14);
    v16 = get_transform(v2, 0);
    v17 = Find(v16, v15, 0);
    v18 = get_gameObject(v17);
    Component_object = GetComponent_object_(v18);
    if (NmlCnt == 2)
    {
      NmlCnt = 3;
        goto LABEL_21;
    }
    else
    {
      NmlCnt = 0;
      {
LABEL_21:
      }
    }
    v25 = NmlCnt;
    v27 = pbHelpLcl->m_Items[v25];
    LocalizeText = GetLocalizeText(v27);
    v29 = NewSpecific(object, 1u);
    NmlCnt = 12;
    v30 = v29;
    v31 = sub_8D3950(s32, &NmlCnt);
    v33 = v31;
    v30->m_Items[0] = v33;
    v35 = RepColTag(LocalizeText, v30);
    set_text(Component_object, v35);
    NmlCnt = 2;
    v10 = (v36 >> 9) & 1;
    v9 = 1;
  }
  while (!v12);
  NmlCnt = 1;
  v38 = sub_8D3950(s32, &NmlCnt);
  v39 = Format("Text_pzlhelp{0:00}", v38, 0);
  v40 = Concat_5224608("pzlhelp/", v39);
  v41 = get_transform(v2, 0);
  v42 = Find(v41, v40, 0);
  v43 = get_gameObject(v42);
  v44 = GetComponent_object_(v43);
  v47 = pbHelpLcl;
  v48 = NmlCnt;
  v49 = v44;
  v51 = v47->m_Items[v48];
  v52 = GetLocalizeText(v51);
  v273 = 24;
  v53 = NewSpecific(object, 1u);
  v54 = sub_8D3950(s32, &v273);
  v56 = v54;
  v53->m_Items[0] = v56;
  v58 = RepColTag(v52, v53);
  set_text(v49, v58);
  ++NmlCnt;
  v61 = sub_8D3950(s32, &NmlCnt);
  v62 = Format("Text_pzlhelp{0:00}", v61, 0);
  v63 = Concat_5224608("pzlhelp/", v62);
  v64 = get_transform(v2, 0);
  v65 = Find(v64, v63, 0);
  v66 = get_gameObject(v65);
  v67 = GetComponent_object_(v66);
  v70 = pbHelpLcl;
  v71 = NmlCnt;
  v72 = v67;
  v74 = v70->m_Items[v71];
  v75 = GetLocalizeText(v74);
  v76 = NewSpecific(object, 1u);
  v273 = 24;
  v77 = v76;
  v78 = sub_8D3950(s32, &v273);
  v80 = v78;
  v77->m_Items[0] = v80;
  v82 = RepColTag(v75, v77);
  set_text(v72, v82);
  ++NmlCnt;
  NmlCnt = 4;
  v85 = get_transform(v2, 0);
  v86 = Find(v85, "pzlhelp/Text_pzlhelp03", 0);
  v87 = get_gameObject(v86);
  v88 = GetComponent_object_(v87);
  v91 = pbHelpLcl;
  v92 = NmlCnt;
  v93 = v88;
  v95 = v91->m_Items[v92];
  v96 = GetLocalizeText(v95);
  v97 = NewSpecific(object, 1u);
  NmlCnt = 25;
  v98 = v97;
  v99 = sub_8D3950(s32, &NmlCnt);
  v101 = v99;
  v98->m_Items[0] = v101;
  v103 = RepColTag(v96, v98);
  set_text(v93, v103);
  NmlCnt = 4;
  v106 = sub_8D3950(s32, &NmlCnt);
  v107 = Format("Text_pzlhelp{0:00}", v106, 0);
  v108 = Concat_5224608("pzlhelp/", v107);
  v109 = get_transform(v2, 0);
  v110 = Find(v109, v108, 0);
  v111 = get_gameObject(v110);
  v112 = GetComponent_object_(v111);
  v115 = pbHelpLcl;
  v116 = NmlCnt + 1LL;
  v117 = v112;
  v119 = v115->m_Items[v116];
  v120 = GetLocalizeText(v119);
  v121 = NewSpecific(object, 1u);
  v273 = 24;
  v122 = v121;
  v123 = sub_8D3950(s32, &v273);
  v125 = v123;
  v122->m_Items[0] = v125;
  v127 = RepColTag(v120, v122);
  set_text(v117, v127);
  ++NmlCnt;
  v130 = sub_8D3950(s32, &NmlCnt);
  v131 = Format("Text_pzlhelp{0:00}", v130, 0);
  v132 = Concat_5224608("pzlhelp/", v131);
  v133 = get_transform(v2, 0);
  v134 = Find(v133, v132, 0);
  v135 = get_gameObject(v134);
  v136 = GetComponent_object_(v135);
  v139 = pbHelpLcl;
  v140 = NmlCnt + 1LL;
  v141 = v136;
  v143 = v139->m_Items[v140];
  v144 = GetLocalizeText(v143);
  v145 = NewSpecific(object, 1u);
  v273 = 24;
  v146 = v145;
  v147 = sub_8D3950(s32, &v273);
  v149 = v147;
  v146->m_Items[0] = v149;
  v151 = RepColTag(v144, v146);
  set_text(v141, v151);
  ++NmlCnt;
  v152 = get_transform(v2, 0);
  v153 = Find(v152, "pzlhelp/Text_pzlhelp06", 0);
  v154 = get_gameObject(v153);
  v156 = GetComponent_object_(v154);
  v159 = pbHelpLcl;
  v160 = NmlCnt + 1LL;
  v162 = v159->m_Items[v160];
  v163 = GetLocalizeText(v162);
  v164 = NewSpecific(object, 1u);
  NmlCnt = 25;
  v165 = v164;
  v166 = sub_8D3950(s32, &NmlCnt);
  v168 = v166;
  v165->m_Items[0] = v168;
  v170 = RepColTag(v163, v165);
  set_text(v156, v170);
  NmlCnt = 7;
  v273 = NmlCnt;
  v171 = sub_8D3950(s32, &v273);
  v172 = Format("Text_pzlhelp{0:00}", v171, 0);
  v173 = Concat_5224608("pzlhelp/", v172);
  v174 = get_transform(v2, 0);
  v175 = Find(v174, v173, 0);
  v176 = get_gameObject(v175);
  v177 = GetComponent_object_(v176);
  v179 = pbHelpLcl;
  v180 = NmlCnt + 1LL;
  v181 = v177;
  v183 = GetLocalizeText(v179->m_Items[v180]);
  v272 = 24;
  v184 = NewSpecific(object, 1u);
  v185 = sub_8D3950(s32, &v272);
  v186 = v185;
  v184->m_Items[0] = v186;
  v188 = RepColTag(v183, v184);
  set_text(v181, v188);
  ++NmlCnt;
  v189 = get_transform(v2, 0);
  v190 = Find(v189, "pzlhelp/Text_pzlhelp08", 0);
  v191 = get_gameObject(v190);
  v192 = GetComponent_object_(v191);
  v194 = pbHelpLcl;
  v195 = NmlCnt + 1LL;
  v196 = v192;
  v198 = GetLocalizeText(v194->m_Items[v195]);
  v271 = 25;
  v199 = NewSpecific(object, 1u);
  v200 = sub_8D3950(s32, &v271);
  v201 = v200;
  v199->m_Items[0] = v201;
  v203 = RepColTag(v198, v199);
  set_text(v196, v203);
  NmlCnt = 9;
  v206 = sub_8D3950(s32, &NmlCnt);
  v207 = Format("Text_pzlhelp{0:00}", v206, 0);
  v208 = Concat_5224608("pzlhelp/", v207);
  v209 = get_transform(v2, 0);
  v210 = Find(v209, v208, 0);
  v211 = get_gameObject(v210);
  v212 = GetComponent_object_(v211);
  v215 = pbHelpLcl;
  v216 = NmlCnt + 1LL;
  v217 = v212;
  v219 = v215->m_Items[v216];
  v220 = GetLocalizeText(v219);
  v221 = NewSpecific(object, 1u);
  v273 = 24;
  v222 = v221;
  v223 = sub_8D3950(s32, &v273);
  v225 = v223;
  v222->m_Items[0] = v225;
  v227 = RepColTag(v220, v222);
  set_text(v217, v227);
  ++NmlCnt;
  v230 = sub_8D3950(s32, &NmlCnt);
  v231 = Format("Text_pzlhelp{0:00}", v230, 0);
  v232 = Concat_5224608("pzlhelp/", v231);
  v233 = get_transform(v2, 0);
  v234 = Find(v233, v232, 0);
  v235 = get_gameObject(v234);
  v236 = GetComponent_object_(v235);
  v239 = pbHelpLcl;
  v240 = NmlCnt + 1LL;
  v241 = v236;
  v243 = v239->m_Items[v240];
  v244 = GetLocalizeText(v243);
  v245 = NewSpecific(object, 1u);
  v273 = 24;
  v246 = v245;
  v247 = sub_8D3950(s32, &v273);
  v249 = v247;
  v246->m_Items[0] = v249;
  v251 = RepColTag(v244, v246);
  set_text(v241, v251);
  ++NmlCnt;
  if (DDS3_PADCHECK_TRIG(1))
  {
LABEL_199:
    if (get_activeSelf(v269))
      SetActive(v269, 0, 0);
    v267 = FindId(1, "JYAKYO02_SE05");
    p2sdPlaySE(v267);
    id->func_ans = -1;
    return 0;
  }
LABEL_178:
  if (DDS3_PADCHECK_TRIG(3))
    goto LABEL_199;
LABEL_181:
  if (DDS3_PADCHECK_TRIG(0))
    goto LABEL_199;
  return 0;
}

// 0x14a1530
pbProcHandle_t *pbStartHelp(pbProcHandle_t *parent, u32 page) {
  Il2CppObject *v4;
  u64 *v5;
  u64 *v6;
  u64 *v7;
  u64 *v8;
  u64 *v9;
  u64 *v10;
  pbProcHandle_t_Fields *p_fields;
  u64 *v14;
  s32 v17;
  s32 v18;

  v4 = Allocate(pbProcHandle_t);
  v5 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v5);
  v4[1].klass = v5;
  v17 = 0;
  v4[2].klass = sub_8D3950(s32, &v17);
  _ctor(v4, 0);
  v6 = Allocate(pbHelp_t);
  _ctor(v6, 0);
  v7 = Allocate(pbProcHandle_t);
  v8 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v8);
  v7[2] = v8;
  v18 = 0;
  v7[4] = sub_8D3950(s32, &v18);
  _ctor(v7, 0);
  v9 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v9,
    0,
    Method_pbHelp_help__);
  v10 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v10,
    0,
    Method_pbHelp_deleteHelp__);
  v7[2] = dds3StartProcess("pb-draw-help", 0x2AFDu, 1, 1, v9, 0, v10, 0, 0, 0);
  if (parent)
  {
    p_fields = &parent->fields;
    dds3LinkProcess(&p_fields->id, v7 + 2);
  }
  v7[3] = 0x10000;
  v14 = Allocate(pbHelp_t);
  _ctor(v14, 0);
  v7[4] = v14;
  dds3SetProcessData(v7 + 2, v7);
  return v7;
}

// 0x14a17f0
pbProcHandle_t *pbStartHelp2(pbProcHandle_t **parent) {
  pbProcHandle_t_o *v4;
  pbProcHandle_t_o *v5;

  v4 = *parent;
  else
  {
    v5 = v4;
  }
  return pbStartHelp(v5);
}

// 0x149fd30
void sdfChipFreeDelayed(void *aPtr) {
  ;
}
