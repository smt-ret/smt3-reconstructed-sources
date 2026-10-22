#include "types.h"

typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct pbBackup_t pbBackup_t;
typedef struct pbMenu_menuFuncDelegate pbMenu_menuFuncDelegate;
typedef struct pbMenu_requireFuncDelegate pbMenu_requireFuncDelegate;
typedef struct pbMenu_t pbMenu_t;
typedef struct pbProcHandle_t pbProcHandle_t;
typedef struct sdfFileCmdHandle_t sdfFileCmdHandle_t;

struct pbMenu_t {
    u32 mode;
};

static char *mapname;
static u8 mapname_a;
static s32 map_num;
static s32 mstrCnr;
static char *mstr[4];
static char *mstr_K[4];
static s32 dirCreateMode;
static u8 menu;
static u8 menuCsr;
static u16 fileName_a[64];
static u8 fileName[64];
static u8 userfileNum;
static u8 systemfileNum;
static s8 fileEnd;
static u8 menuMax[2];
static pbMenu_requireFuncDelegate *requireFunc[2];
static pbMenu_menuFuncDelegate *menuFunc[2];
static s32 mcPort;
static s32 mcSlot;

void ButtonGuideDispOff(void);
void ButtonGuideDispSet(char *name, bool timer, bool empty, s32 waitTimer);
bool DDS3_PADCHECK_REP(s32 id);
bool DDS3_PADCHECK_TRIG(s32 id);
s32 FindId(s32 type, char *name);
char *GetLocalizeText(char *ID);
s32 GetStageNumber(void);
void *GetoPB_UI(void);
char *RepColTag(char *txt, void **LegacyParamArray);
void dds3AdminiCallSequence(s32 sequence, void *data, s32 datasize, s32 restore);
void dds3FadeOut(u32 r, u32 g, u32 b, u32 frame);
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
void dds3ResetProcessFlag(dds3ProcessID_t **target, u32 flag, s32 type);
dds3ProcessID_t *dds3SearchProcessName(char *namestr);
void dds3SetProcessData(dds3ProcessID_t **id, void *data);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
s32 p2sdPlaySE(s32 a);
void pbBackup_t__pCopy(pbBackup_t *this, u8 **bytedata, s32 *bpos);
u32 pbCheckMap(void);
s8 pbCheckPreviousRecord(void);
void pbLoadSystemData(s32 num);
void pbPreviousRecord(void);
void pbSetGameCamera0(void);
dds3ProcessID_t *pbStartGiveupConfirm(void);
pbProcHandle_t *pbStartHelp(pbProcHandle_t *parent, u32 page);
pbProcHandle_t *pbWaitLoadMapData(pbProcHandle_t *parent);
void *sdfDevLoadFileUnity_25061072(char *aFilename, u8 ***aTopPtr, s32 aSizePtr, char *akey);

// 0x14aa100
dds3ProcessFunc_t *deleteMenu(dds3ProcessID_t *id) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v7;
  u64 *image;
  s64 v9;
  char *v10;
  s64 *v11;
  UnityEngine_GameObject_o *v12;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v14;
  UnityEngine_GameObject_o *gameObject;
  char *v19;
  s64 *v20;
  u64 v21[2];
  char *v22;

  workdata = id->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbProcHandle_t)
  {
    sub_8FC2C0(klass->_1.element_class, pbProcHandle_t, v21);
    if ((v21[0] & 1) != 0)
      v19 = v22;
    else
      v19 = v21 + 1;
    v20 = sub_8C4940(v19);
  }
  v7 = workdata[2].klass;
  else if (!v7)
  {
    goto LABEL_15;
  }
  image = v7->_1.image;
  if (*(v7->_1.image + 288) < v9 || *(image[25] + 8 * v9 - 8) != pbMenu_t)
  {
    sub_8FC2C0(image[8], pbMenu_t, v21);
    if ((v21[0] & 1) != 0)
      v10 = v22;
    else
      v10 = v21 + 1;
    v11 = sub_8C4940(v10);
  }
LABEL_15:
  v12 = GetoPB_UI();
  transform = get_transform(v12, 0);
  v14 = Find(transform, "pzlmenu", 0);
  gameObject = get_gameObject(v14);
  if (get_activeSelf(gameObject))
    SetActive(gameObject, 0, 0);
  pbWk->menu_proc = 0;
  return 0;
}

// 0x14aa6c0
dds3ProcessFunc_t *deleteWaitLoadEnd(dds3ProcessID_t *id) {
  return 0;
}

// 0x14a7ba0
void exitGame(pbProcHandle_t **p) {
  pbProcHandle_t_o *v4;

  pbStartGiveupConfirm();
  v4 = *p;
  else if (!v4)
  {
    return;
  }
  v4->mes = 327680;
}

// 0x14a7a30
void exitPB(pbProcHandle_t **p) {
  pbProcHandle_t_Fields *p_fields;
  struct pbProcHandle_t_o *current_proc;

  pbSetGameCamera0();
  p_fields = &(*p)->fields;
  dds3ResetProcessFlag(&p_fields->id, 0x10u, 1);
LABEL_13:
  if (current_proc)
LABEL_19:
    current_proc->mes = 393216;
LABEL_20:
  dds3AdminiCallSequence(0, 0, 0, 0);
}

// 0x14a6af0
void fileCallback(sdfFileCmdHandle_t *aHandle, s32 aCause, void *aBuffer, s32 aLength, void *aUserData) {
  char v8;

  if (aCause)
  {
    if (aCause != 8)
      return;
    v8 = 1;
  }
  else
  {
    v8 = -1;
  }
  fileEnd = v8;
}

// 0x14a6ba0
s8 generalReq_OK(pbProcHandle_t **p) {
  return 1;
}

// 0x14a7c40
void help(pbProcHandle_t **p) {
  Il2CppObject *data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  s64 v9;
  struct pbWork_t_o *pbWk;
  pbProcHandle_t_o *current_proc;
  u64 v17[3];

  data = (*p)->data;
  if (data)
  {
    klass = data->klass;
    if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbMenu_t)
    {
      sub_8FC2C0(klass->_1.element_class, pbMenu_t, v17);
      if ((v17[0] & 1) != 0)
        v6 = v17[2];
      else
        v6 = v17 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v8);
LABEL_17:
  pbWk->help_proc = pbStartHelp(current_proc, v9);
  dds3SearchProcessName("DebugOwner");
  if (*p)
    (*p)->mes = 327680;
  ButtonGuideDispSet("PZL04", 0, 0, 90);
}

// 0x14a75b0
void load(pbProcHandle_t **p) {
  else
  {
    if (menu == 1)
      goto LABEL_6;
  }
  menu = 1;
}

// 0x14a78f0
void loadSystemData(pbProcHandle_t **p) {
  else
  {
    if (menu == 3)
      goto LABEL_6;
  }
  menu = 3;
}

// 0x14a7a10
void mcLoad(pbProcHandle_t **p) {
  ;
}

// 0x14a7a20
void mcSave(pbProcHandle_t **p) {
  ;
}

// 0x14a82e0
dds3ProcessFunc_t *menuProc(dds3ProcessID_t *id) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppClass *v8;
  u64 *image;
  s64 v10;
  char *v11;
  s64 *v12;
  UnityEngine_GameObject_o *v13;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v15;
  Il2CppObject *Component_object;
  pbMenu_c **v19;
  pbMenu_c *v20;
  u64 v21;
  s32 v22;
  u64 *v23;
  System_String_o *v24;
  System_String_o *v25;
  UnityEngine_Transform_o *v26;
  UnityEngine_Component_o *v27;
  UnityEngine_GameObject_o *v28;
  Il2CppObject *v29;
  pbMenu_c **v31;
  struct System_String_array *mstr;
  TMPro_TMP_Text_o *v33;
  System_String_o *v35;
  System_String_o *LocalizeText;
  System_Object_array *v37;
  s64 *v38;
  s64 *v40;
  System_String_o *v43;
  u32 v44;
  pbProcHandle_t_o *v45;
  s32 v46;
  pbProcHandle_t_o *v47;
  u64 v50;
  s32 v53;
  u64 v55;
  s16 v56;
  s32 v57;
  struct pbMenu_StaticFields *static_fields;
  u8 menuCsr;
  struct System_Byte_array *menuMax;
  s64 name_low;
  s64 v63;
  UnityEngine_GameObject_o *v64;
  UnityEngine_Transform_o *v65;
  f32 v66;
  s32 v81;
  u64 v82;
  s64 v83;
  u32 v84;
  s32 v87;
  u64 v88;
  s64 v89;
  u32 v90;
  s32 v92;
  u64 v93;
  s16 v94;
  s32 v95;
  struct pbMenu_StaticFields *v96;
  s32 v99;
  s32 v101;
  u64 v103;
  s64 v104;
  s64 v105;
  s64 v106;
  UnityEngine_Transform_o *v108;
  f32 v109;
  s32 v112;
  u64 v113;
  s32 v116;
  u64 v117;
  UnityEngine_Transform_o *v118;
  s32 v121;
  u64 v122;
  s32 v125;
  u64 v126;
  Il2CppObject *v127;
  UnityEngine_Transform_o *v128;
  s32 v131;
  u64 v132;
  s32 v134;
  u64 v135;
  u64 v138;
  Il2CppClass *v139;
  s64 v140;
  s64 v141;
  s64 v142;
  s64 v144;
  s64 v145;
  s64 v146;
  s32 v150;
  u64 v153;
  s64 v154;
  s64 v155;
  s64 v156;
  s64 v158;
  s64 v159;
  s64 v160;
  s32 v163;
  s32 v166;
  u64 v168;
  struct pbMenu_StaticFields *v169;
  Il2CppClass *v170;
  dds3ProcessID_t_o *v171;
  UnityEngine_GameObject_o *gameObject;
  s32 v173;
  UnityEngine_Vector3_o v174;
  char *v175;
  pbProcHandle_t_o *p;
  UnityEngine_Vector2_o anchoredPosition;
  UnityEngine_Vector3_o v178;
  UnityEngine_Vector3_o v181;
  UnityEngine_Vector2_o v184;

  p = 0;
  workdata = id->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbProcHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, pbProcHandle_t, &v174);
      if ((LOBYTE(v174.x) & 1) != 0)
        v6 = v175;
      else
        v6 = &v174.x + 1;
      v7 = sub_8C4940(v6);
    }
  }
  p = id->workdata;
  v8 = workdata[2].klass;
  if (v8)
  {
    image = v8->_1.image;
    if (*(v8->_1.image + 288) < v10 || *(image[25] + 8 * v10 - 8) != pbMenu_t)
    {
      sub_8FC2C0(image[8], pbMenu_t, &v174);
      if ((LOBYTE(v174.x) & 1) != 0)
        v11 = v175;
      else
        v11 = &v174.x + 1;
      v12 = sub_8C4940(v11);
    }
  }
  v170 = v8;
  v171 = id;
  v13 = GetoPB_UI();
  transform = get_transform(v13, 0);
  v15 = Find(transform, "pzlmenu/pzlmenu_cursur", 0);
  gameObject = get_gameObject(v15);
  Component_object = GetComponent_object_(gameObject);
  anchoredPosition = get_anchoredPosition(Component_object);
  v178 = op_Implicit_8725680(anchoredPosition);
  v19 = &pbMenu;
  v21 = 0;
  do
  {
    LODWORD(v174.x) = mstrCnr;
    v23 = sub_8D3950(s32, &v174);
    v24 = Format("Text_pzlmenu0{0:0}TM", v23, 0);
    v25 = Concat_5224608("pzlmenu/", v24);
    v26 = get_transform(v13, 0);
    v27 = Find(v26, v25, 0);
    v28 = get_gameObject(v27);
    v29 = GetComponent_object_(v28);
    v31 = v19;
    mstr = (*v19)->static_fields->mstr;
    v33 = v29;
    v35 = mstr->m_Items[v21];
    LocalizeText = GetLocalizeText(v35);
    v37 = NewSpecific(object, 1u);
    v173 = 22;
    v38 = sub_8D3950(s32, &v173);
    v40 = v38;
    v37->m_Items[0] = v40;
    v43 = RepColTag(LocalizeText, v37);
    set_text(v33, v43);
    v20 = *v31;
    ++(*v31)->static_fields->mstrCnr;
    v44 = *&v20->_2.bitflags1;
    ++v21;
    v19 = v31;
    v22 = (v44 >> 9) & 1;
  }
  while (v21 != 4);
  mstrCnr = 1;
  v45 = p;
  v46 = v45->mes >> 16;
  if (v46 == 5)
    goto LABEL_82;
LABEL_47:
  if (v46 == 1)
  {
    v47 = p;
    if (v47)
      v47->mes = 0;
  }
  else if (DDS3_PADCHECK_TRIG(3))
  {
    goto LABEL_89;
  }
  if (DDS3_PADCHECK_TRIG(0))
    goto LABEL_89;
LABEL_59:
  v50 = *v31;
  if (((*v31)->_2.bitflags2 & 2) != 0 && !*(v50 + 216))
  {
    v50 = *v31;
  }
  switch (*(*(v50 + 184) + 44LL))
  {
    case 0:
      if (DDS3_PADCHECK_REP(6))
      {
        v53 = FindId(1, "JYAKYO02_SE06");
        p2sdPlaySE(v53);
        v55 = *v31;
        v56 = *&(*v31)->_2.bitflags1;
        if ((v56 & 0x200) != 0)
        {
          if (!*(v55 + 216))
          {
            v55 = *v31;
            v56 = *&(*v31)->_2.bitflags1;
          }
          v57 = v56 & 0x200;
          static_fields = *(v55 + 184);
          menuCsr = static_fields->menuCsr;
          if (!menuCsr)
            goto LABEL_75;
        }
        else
        {
          v57 = 0;
          static_fields = *(v55 + 184);
          menuCsr = static_fields->menuCsr;
          if (!menuCsr)
          {
LABEL_75:
            if (v57 && !*(v55 + 216))
            {
              static_fields = (*v31)->static_fields;
            }
            menuMax = static_fields->menuMax;
            name_low = LODWORD(v170->_1.name);
            v63 = menuMax + name_low;
            v64 = gameObject;
            static_fields->menuCsr = *(v63 + 32) - 1;
            v65 = get_transform(gameObject, 0);
            v66 = -206.0;
LABEL_261:
            v118 = v65;
            v174.z = 0.0;
            *&v174.x = 0;
            goto LABEL_262;
          }
        }
        if (v57 && !*(v55 + 216))
        {
          static_fields = (*v31)->static_fields;
          menuCsr = static_fields->menuCsr;
        }
        v64 = gameObject;
        static_fields->menuCsr = menuCsr - 1;
        v108 = get_transform(gameObject, 0);
        v109 = 58.0;
      }
      else
      {
        if (!DDS3_PADCHECK_REP(7))
          goto LABEL_298;
        v101 = FindId(1, "JYAKYO02_SE06");
        p2sdPlaySE(v101);
        v103 = *v31;
        if (((*v31)->_2.bitflags2 & 2) != 0 && !*(v103 + 216))
        {
          v103 = *v31;
        }
        v104 = *(v103 + 184);
        v105 = *(v104 + 72);
        v106 = LODWORD(v170->_1.name);
        if (*(v105 + v106 + 32) - 1 <= *(v104 + 45))
        {
          if ((*(v103 + 294) & 0x200) != 0 && !*(v103 + 216))
          {
            v103 = *v31;
          }
          v64 = gameObject;
          *(*(v103 + 184) + 45LL) = 0;
          v65 = get_transform(gameObject, 0);
          v66 = -32.0;
          goto LABEL_261;
        }
        if ((*(v103 + 294) & 0x200) != 0 && !*(v103 + 216))
        {
          v103 = *v31;
        }
        v64 = gameObject;
        ++*(*(v103 + 184) + 45LL);
        v108 = get_transform(gameObject, 0);
        v109 = -58.0;
      }
      v118 = v108;
      v174.z = 0.0;
      *&v174.x = 0;
      v66 = v178.y + v109;
LABEL_262:
      sub_8524C0(&v174.x, v178.x, v66, v178.z);
      set_position(v118, v174);
      v127 = GetComponent_object_(v64);
      v128 = get_transform(v64, 0);
      v181 = get_position(v128);
      v184 = op_Implicit(v181, 0);
      set_anchoredPosition(v127, v184);
        goto LABEL_299;
      goto LABEL_300;
    case 1:
      if (DDS3_PADCHECK_REP(4))
      {
        v81 = FindId(1, "JYAKYO02_SE06");
        p2sdPlaySE(v81);
        v82 = *v19;
        if (((*v19)->_2.bitflags2 & 2) != 0 && !*(v82 + 216))
        {
          v82 = *v19;
        }
        v83 = *(v82 + 184);
        v84 = *(v83 + 64) + 29;
      }
      else
      {
        if (DDS3_PADCHECK_REP(5))
        {
          v112 = FindId(1, "JYAKYO02_SE06");
          p2sdPlaySE(v112);
          v113 = *v19;
          if (((*v19)->_2.bitflags2 & 2) != 0 && !*(v113 + 216))
          {
            v113 = *v19;
          }
          v83 = *(v113 + 184);
          v84 = *(v83 + 64) + 31;
        }
        else
        {
          if (DDS3_PADCHECK_REP(6))
          {
            v121 = FindId(1, "JYAKYO02_SE06");
            p2sdPlaySE(v121);
            v122 = *v19;
            if (((*v19)->_2.bitflags2 & 2) != 0 && !*(v122 + 216))
            {
              v122 = *v19;
            }
            v83 = *(v122 + 184);
            v84 = *(v83 + 64) + 40;
          }
          else
          {
            if (!DDS3_PADCHECK_REP(7))
              goto LABEL_298;
            v131 = FindId(1, "JYAKYO02_SE06");
            p2sdPlaySE(v131);
            v132 = *v19;
            if (((*v19)->_2.bitflags2 & 2) != 0 && !*(v132 + 216))
            {
              v132 = *v19;
            }
            v83 = *(v132 + 184);
            v84 = *(v83 + 64) + 20;
          }
        }
      }
      *(v83 + 64) = v84 % 0x1E;
        goto LABEL_299;
      goto LABEL_300;
    case 3:
      if (DDS3_PADCHECK_REP(4))
      {
        v87 = FindId(1, "JYAKYO02_SE06");
        p2sdPlaySE(v87);
        v88 = *v19;
        if (((*v19)->_2.bitflags2 & 2) != 0 && !*(v88 + 216))
        {
          v88 = *v19;
        }
        v89 = *(v88 + 184);
        v90 = *(v89 + 65) + 49;
LABEL_297:
        *(v89 + 65) = v90 % 0x32;
        goto LABEL_298;
      }
      if (DDS3_PADCHECK_REP(5))
      {
        v116 = FindId(1, "JYAKYO02_SE06");
        p2sdPlaySE(v116);
        v117 = *v19;
        if (((*v19)->_2.bitflags2 & 2) != 0 && !*(v117 + 216))
        {
          v117 = *v19;
        }
        v89 = *(v117 + 184);
        v90 = *(v89 + 65) + 51;
        goto LABEL_297;
      }
      if (DDS3_PADCHECK_REP(6))
      {
        v125 = FindId(1, "JYAKYO02_SE06");
        p2sdPlaySE(v125);
        v126 = *v19;
        if (((*v19)->_2.bitflags2 & 2) != 0 && !*(v126 + 216))
        {
          v126 = *v19;
        }
        v89 = *(v126 + 184);
        v90 = *(v89 + 65) + 60;
        goto LABEL_297;
      }
      if (DDS3_PADCHECK_REP(7))
      {
        v134 = FindId(1, "JYAKYO02_SE06");
        p2sdPlaySE(v134);
        v135 = *v19;
        if (((*v19)->_2.bitflags2 & 2) != 0 && !*(v135 + 216))
        {
          v135 = *v19;
        }
        v89 = *(v135 + 184);
        v90 = *(v89 + 65) + 40;
        goto LABEL_297;
      }
LABEL_298:
        goto LABEL_300;
LABEL_299:
        goto LABEL_300;
      if (!DDS3_PADCHECK_TRIG(1))
        goto LABEL_332;
      goto LABEL_301;
    case 4:
      if (!DDS3_PADCHECK_REP(4))
      {
        if (!DDS3_PADCHECK_REP(5))
          goto LABEL_298;
      }
      v92 = FindId(1, "JYAKYO02_SE06");
      p2sdPlaySE(v92);
      v93 = *v19;
      v94 = *&(*v19)->_2.bitflags1;
      if ((v94 & 0x200) != 0)
      {
        if (!*(v93 + 216))
        {
          v93 = *v19;
          v94 = *&(*v19)->_2.bitflags1;
        }
        v95 = v94 & 0x200;
        v96 = *(v93 + 184);
        if (!v96->mcPort)
        {
LABEL_144:
          if (v95 && !*(v93 + 216))
          {
            v96 = (*v19)->static_fields;
          }
          v96->mcPort = 1;
            goto LABEL_299;
          goto LABEL_300;
        }
      }
      else
      {
        v95 = 0;
        v96 = *(v93 + 184);
        if (!v96->mcPort)
          goto LABEL_144;
      }
      if (v95 && !*(v93 + 216))
      {
        v96 = (*v19)->static_fields;
      }
      v96->mcPort = 0;
        goto LABEL_299;
LABEL_300:
      if (DDS3_PADCHECK_TRIG(1))
      {
LABEL_301:
        v138 = *v19;
        if (((*v19)->_2.bitflags2 & 2) != 0)
        {
          v139 = v170;
          if (!*(v138 + 216))
          {
            v138 = *v19;
          }
        }
        else
        {
          v139 = v170;
        }
        v140 = *(v138 + 184);
        v141 = *(v140 + 80);
        v142 = LODWORD(v139->_1.name);
        v144 = v141 + 8 * v142;
        v145 = *(v140 + 45);
        v146 = *(v144 + 32);
        if (Invoke(*(v146 + 8 * v145 + 32), &p) == 1)
        {
          v150 = FindId(1, "JYAKYO02_SE04");
          p2sdPlaySE(v150);
          v153 = *v19;
          if (((*v19)->_2.bitflags2 & 2) != 0 && !*(v153 + 216))
          {
            v153 = *v19;
          }
          v154 = *(v153 + 184);
          v155 = *(v154 + 88);
          v156 = LODWORD(v139->_1.name);
          v158 = v155 + 8 * v156;
          v159 = *(v154 + 45);
          v160 = *(v158 + 32);
          Invoke(*(v160 + 8 * v159 + 32), &p);
        }
        else
        {
          v163 = FindId(1, "JYAKYO02_SE07");
          p2sdPlaySE(v163);
        }
      }
      else
      {
LABEL_332:
        if (DDS3_PADCHECK_TRIG(3))
        {
          v166 = FindId(1, "JYAKYO02_SE05");
          p2sdPlaySE(v166);
          v168 = *v19;
          if (((*v19)->_2.bitflags2 & 2) != 0 && !*(v168 + 216))
          {
            v168 = *v19;
          }
          v169 = *(v168 + 184);
          if (v169->menu)
          {
            if ((*(v168 + 295) & 2) != 0 && !*(v168 + 216))
            {
              v169 = (*v19)->static_fields;
            }
            v169->menu = 0;
          }
        }
      }
      break;
    case 5:
      if (!DDS3_PADCHECK_REP(4))
      {
        if (!DDS3_PADCHECK_REP(5))
          goto LABEL_298;
      }
      v99 = FindId(1, "JYAKYO02_SE06");
      p2sdPlaySE(v99);
        goto LABEL_300;
      goto LABEL_299;
    default:
      goto LABEL_298;
  }
  return 0;
}

// 0x14a7280
void pbLoadSystemData(s32 num) {
  struct pbWork_t_o *pbWk;
  u64 *v5;
  u64 *v8;
  System_String_o *v9;
  s64 *v10;
  u64 *v11;
  System_String_o *v13;
  s32 v20;
  s32 v21;
  s32 bpos;

  bpos = 0;
  v5 = Allocate(pbBackup_t);
  pbBackup_t___ctor(v5);
  pbWk->bup = v5;
  dds3FadeOut(0, 0, 0, 1u);
  if (num <= 29)
  {
    v21 = num;
    v11 = sub_8D3950(s32, &v21);
    v9 = Format("pbMap{0:00}.map.bytes", v11, 0);
    v10 = &"dds3data/pb/mapdata/data/pb1/";
  }
  else
  {
    v20 = num;
    v8 = sub_8D3950(s32, &v20);
    v9 = Format("pbMap{0:00}.map.bytes", v8, 0);
    v10 = &"dds3data/pb/mapdata/data/pb2/";
  }
  v13 = Concat_5224608(*v10, v9);
  mapname = v13;
  sdfDevLoadFileUnity_25061072(mapname, &fileName, 0, "pazzleboy");
  bpos = 0;
  pbBackup_t__pCopy(pbWk->bup, fileName, &bpos);
  fileEnd = 0;
  pbWaitLoadMapData(0);
}

// 0x14aa700
pbProcHandle_t *pbStartMenu(pbProcHandle_t **parent, u32 mode) {
  u64 *v5;
  u64 *v6;
  u64 *v7;
  u64 *v8;
  pbProcHandle_t_Fields *p_fields;
  u64 *v12;
  u64 v14;
  s64 typeHierarchyDepth;
  char *v19;
  s64 *v20;
  u64 v21[3];

  v5 = Allocate(pbProcHandle_t);
  v6 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v6);
  v5[2] = v6;
  LODWORD(v21[0]) = 0;
  v5[4] = sub_8D3950(s32, v21);
  _ctor(v5, 0);
  v7 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v7,
    0,
    Method_pbMenu_menuProc__);
  v8 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v8,
    0,
    Method_pbMenu_deleteMenu__);
  v5[2] = dds3StartProcess("pb-proc-menu", 0x3F8u, 1, 1, v7, 0, v8, 0, 0, 0);
  if (*parent)
  {
    p_fields = &(*parent)->fields;
    dds3LinkProcess(&p_fields->id, v5 + 2);
  }
  *(v5 + 6) = 0x10000;
  v12 = Allocate(pbMenu_t);
  _ctor(v12, 0);
  v5[4] = v12;
  v14 = *v12;
  if (*(*v12 + 288) < typeHierarchyDepth || *(*(v14 + 200) + 8 * typeHierarchyDepth - 8) != pbMenu_t)
  {
    sub_8FC2C0(*(v14 + 64), pbMenu_t, v21);
    if ((v21[0] & 1) != 0)
      v19 = v21[2];
    else
      v19 = v21 + 1;
    v20 = sub_8C4940(v19);
  }
  *(v12 + 4) = mode;
  dds3SetProcessData(v5 + 2, v5);
  menuCsr = 0;
  menu = 0;
  return v5;
}

// 0x14a76d0
pbProcHandle_t *pbWaitLoadMapData(pbProcHandle_t *parent) {
  u64 *v3;
  u64 *v4;
  u64 *v5;
  u64 *v6;
  pbProcHandle_t_Fields *p_fields;
  s32 v12;

  v3 = Allocate(pbProcHandle_t);
  v4 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v4);
  v3[2] = v4;
  v12 = 0;
  v3[4] = sub_8D3950(s32, &v12);
  _ctor(v3, 0);
  v5 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v5,
    0,
    Method_pbMenu_waitLoadEnd__);
  v6 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v6,
    0,
    Method_pbMenu_deleteWaitLoadEnd__);
  v3[2] = dds3StartProcess("pb-load-mapdata", 0x3EEu, 1, 1, v5, 0, v6, 0, 0, 0);
  if (parent)
  {
    p_fields = &parent->fields;
    dds3LinkProcess(&p_fields->id, v3 + 2);
  }
  else
  {
    *(v3 + 6) = 0;
      goto LABEL_19;
  }
LABEL_19:
  dds3SetProcessData(v3 + 2, v3);
  return v3;
}

// 0x14a74b0
void previous(pbProcHandle_t **p) {
  pbPreviousRecord();
  pbBlkDalateflag = 1;
  mBlk_Resetflag = 1;
  StageDrawflag = 0;
  MRBlockDrawflag = 0;
  OutLineMDraw = 1;
  RBlockOutCnt = 0;
  MBlockOutCnt = 0;
}

// 0x14a6c20
s8 previousReq(pbProcHandle_t **p) {
    return pbCheckPreviousRecord();
  return pbCheckPreviousRecord();
}

// 0x14a6ef0
void reTry(pbProcHandle_t **p) {
  s32 StageNumber;
  pbProcHandle_t_o *v6;
  s64 v8;
  s32 v9;
  u64 v10;
  struct XRD773Unity_CommonMesh_array *pBlk_Mesh;
  UnityEngine_Object_o *v13;
  struct XRD773Unity_CommonMesh_array *v16;
  UnityEngine_Object_o *gameObject;
  struct XRD773Unity_CommonMesh_array *pMRBlk_Mesh;
  UnityEngine_Object_o *v23;
  struct XRD773Unity_CommonMesh_array *v25;
  UnityEngine_Object_o *v28;
  u32 v29;
  UnityEngine_Object_o *v32;

  StageNumber = GetStageNumber();
  pbLoadSystemData(StageNumber);
  v6 = *p;
  if (v6)
LABEL_12:
    v6->mes = 327680;
LABEL_13:
  v8 = 4;
  do
  {
    v10 = v8 - 4;
    v13 = *(&pBlk_Mesh->obj.klass + v8);
    if (op_Inequality(v13, 0, 0))
    {
      v16 = pBlk_Mesh;
      gameObject = get_gameObject(*(&v16->obj.klass + v8), 0);
      Destroy_27360000(gameObject);
    }
    v23 = *(&pMRBlk_Mesh->obj.klass + v8);
    if (op_Inequality(v23, 0, 0))
    {
      v25 = pMRBlk_Mesh;
      v28 = get_gameObject(*(&v25->obj.klass + v8), 0);
      Destroy_27360000(v28);
    }
    ++v8;
    v9 = (v29 >> 9) & 1;
  }
  while (v8 != 404);
  outlineDrawflag = 1;
  OutLineFDraw = 0;
  mBlkStageChangeflag = 1;
  ButtonGuideDispOff();
  v32 = Find("pbInitMyCharacterDraw", 0);
  Destroy_27360000(v32);
}

// 0x14a8150
void save(pbProcHandle_t *p) {
  u64 *v2;
  s16 v5;
  s32 v6;
  Il2CppObject *p_obj;

  v2 = Allocate(pbMenu_sce_stat);
  _ctor(v2, 0);
  if ((v5 & 0x200) == 0)
    goto LABEL_4;
  v6 = v5 & 0x200;
    goto LABEL_12;
  {
LABEL_4:
    v6 = 0;
    if (menu == 1)
      goto LABEL_13;
    goto LABEL_5;
  }
  if (menu == 1)
  {
LABEL_13:
    p_obj = &fileName->obj;
    Write_2930400("{0} wrote.\n", p_obj);
    return;
  }
LABEL_5:
  menu = 1;
}

// 0x14a7eb0
void save_clbk(sdfFileCmdHandle_t *aHandle, s32 aCause, void *aBuffer, s32 aLength, void *aUserData) {
  System_Object_array *v11;
  System_Object_array *v12;
  s64 *v14;
  s64 *v15;
  s64 *v18;
  s64 *v20;
  s32 v28;
  s32 v29;

  v11 = NewSpecific(object, 5u);
  v12 = v11;
  v12->m_Items[0] = aHandle;
  v29 = aCause;
  v14 = sub_8D3950(s32, &v29);
  v15 = v14;
  v12->m_Items[1] = v15;
  v12->m_Items[2] = aBuffer;
  v28 = aLength;
  v18 = sub_8D3950(s32, &v28);
  v20 = v18;
  v12->m_Items[3] = v20;
  v12->m_Items[4] = aUserData;
  Write_2930544("save_clbk: %p {1:D} %p {3:D} %p\n", v12);
}

// 0x14a6ac0
s32 sceGetstat(char *a, void *b) {
  return 0;
}

// 0x14a6ad0
s32 sceMkdir(char *a, s32 b) {
  return 0;
}

// 0x14a6ae0
void sdfChipFreeDelayed(void *aPtr) {
  ;
}

// 0x14a7ea0
s8 searchFileMC(u32 fileIdx) {
  return 0;
}

// 0x14a6c90
void toGame(pbProcHandle_t **p) {
  pbProcHandle_t_Fields *p_fields;
  struct pbProcHandle_t_o *current_proc;

  else if (pbCheckMap())
  {
    return;
  }
  dds3FadeOut(0, 0, 0, 1u);
  p_fields = &(*p)->fields;
  dds3ResetProcessFlag(&p_fields->id, 0x10u, 1);
  if (current_proc)
  {
    current_proc->mes = 262145;
  }
}

// 0x14a6bb0
s8 toGameReq(pbProcHandle_t **p) {
  return pbCheckMap() == 0;
}

// 0x14aa340
dds3ProcessFunc_t *waitLoadEnd(dds3ProcessID_t *id) {
  struct dds3ProcessID_t_o *parent;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v9;
  u64 *image;
  s64 v11;
  char *v12;
  s64 *v13;
  struct pbProcHandle_t_o *current_proc;
  struct pbProcHandle_t_o *v18;
  char *v20;
  s64 *v21;
  u64 v22[2];
  char *v23;

  fileEnd = 1;
  parent = id->parent;
  if (parent)
  {
    workdata = parent->workdata;
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbProcHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, pbProcHandle_t, v22);
      if ((v22[0] & 1) != 0)
        v20 = v23;
      else
        v20 = v22 + 1;
      v21 = sub_8C4940(v20);
    }
    v9 = workdata[2].klass;
    if (v9)
    {
      image = v9->_1.image;
      if (*(image + 288) < v11 || *(image[25] + 8 * v11 - 8) != pbMenu_t)
      {
        sub_8FC2C0(image[8], pbMenu_t, v22);
        if ((v22[0] & 1) != 0)
          v12 = v23;
        else
          v12 = v22 + 1;
        v13 = sub_8C4940(v12);
      }
    }
    if (fileEnd == 1)
    {
      dds3ResetProcessFlag(&workdata[1], 0x10u, 1);
      LODWORD(workdata[1].monitor) = 327680;
      if (current_proc)
        current_proc->mes = 0x10000;
LABEL_53:
      id->func_ans = -1;
    }
  }
  else
  {
    if (fileEnd == 1)
    {
      v18 = current_proc;
      if (v18)
        v18->mes = 0x10000;
      goto LABEL_53;
    }
  }
  return 0;
}
