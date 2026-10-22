#include "types.h"

typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct dds3StartMenuDisp dds3StartMenuDisp;
typedef struct dds3StartMenu_menu_s dds3StartMenu_menu_s;
typedef struct dds3StartMenu_menu_s_funcDelegate dds3StartMenu_menu_s_funcDelegate;

struct dds3StartMenu_menu_s {
    char *name;
    dds3StartMenu_menu_s_funcDelegate *func;
    s32 noend;
    s32 effidx;
};

static dds3StartMenuDisp *dispobj;
static s32 InitGameStartProcess_boot;
static s32 dbg_eff_cut[2];
static s32 dbg_draw_stop1;
static s32 dbg_arrow_hdr;
static f32 dbg_camfar;
static s32 dbg_effresolution;
static s32 cursor;
static dds3StartMenu_menu_s *menu[25];

bool DDS3_PADCHECK_REP(s32 id);
void *GetMainCamera(dds3DefaultMain *this);
char *PlStr(void);
void SetCameraArrow(dds3DefaultMain *this, bool hdr, bool msaa);
void SetCameraFar(dds3DefaultMain *this, f32 far);
void dds3AdminiCallSequence(s32 sequence, void *data, s32 datasize, s32 restore);
s32 dds3SelectMenu(s32 pad, s32 listsx, s32 listsy, s32 winsx, s32 winsy, s32 *basex, s32 *basey, s32 *x, s32 *y);

// 0x14ffdb0
u32 DbgEffPCPFlashCut(u32 number) {
  struct System_Int32_array *dbg_eff_cut;
  struct System_Int32_array *v7;

  if (dbg_eff_cut->m_Items[1] != 100)
  {
    v7 = dbg_eff_cut;
    return v7->m_Items[1] * number / 0x64;
  }
  return number;
}

// 0x14ffec0
void InitArrowHdrProcess(void) {
  dds3DefaultMain_o *kernelObject;
  bool v6;

  dbg_arrow_hdr = (dbg_arrow_hdr & 1) == 0;
  if (dbg_arrow_hdr)
  {
    v6 = 0;
  }
  else
  {
    v6 = 1;
  }
  SetCameraArrow(kernelObject, v6, 1);
}

// 0x14ffa00
void InitBattleFieldTestProcess(void) {
  dds3AdminiCallSequence(21, 0, 0, 0);
}

// 0x14fffa0
void InitCameraFarProcess(void) {
  dds3DefaultMain_o *kernelObject;

  SetCameraFar(kernelObject, dbg_camfar);
}

// 0x14ffab0
void InitCampTestProcess(void) {
  dds3AdminiCallSequence(27, 0, 0, 0);
}

// 0x14ffad0
void InitCombineTestProcess(void) {
  dds3AdminiCallSequence(28, 0, 0, 0);
}

// 0x14ffeb0
void InitDrawStop1Process(void) {
  ;
}

// 0x14ffda0
void InitEffCutProcess(void) {
  ;
}

// 0x1500040
void InitEffResolution(void) {
  dbg_effresolution = (dbg_effresolution & 1) == 0;
}

// 0x1500170
void InitEndSaveProcess(void) {
  ;
}

// 0x14ffa40
void InitEventTestProcess(void) {
  dds3AdminiCallSequence(23, 0, 0, 0);
}

// 0x14ffa60
void InitEventViewerProcess(void) {
  dds3AdminiCallSequence(24, 0, 0, 0);
}

// 0x14ffa80
void InitFieldProcess(void) {
  ;
}

// 0x15000c0
void InitFontTestProcess(void) {
  dds3AdminiCallSequence(38, 0, 0, 0);
}

// 0x14ff8b0
void InitGameStartProcess(void) {
  InitGameStartProcess_boot = 0;
  if (InitGameStartProcess_boot)
  {
    dds3AdminiCallSequence(1, 0, 0, 0);
    InitGameStartProcess_boot = 0;
  }
  else
  {
    dds3AdminiCallSequence(2, 0, 0, 0);
  }
}

// 0x14ffa20
void InitKernelTestProcess(void) {
  dds3AdminiCallSequence(22, 0, 0, 0);
}

// 0x14ffa90
void InitMesScriptTestProcess(void) {
  dds3AdminiCallSequence(26, 0, 0, 0);
}

// 0x15001a0
void InitModeSelectProcess(void) {
  dds3AdminiCallSequence(42, 0, 0, 0);
}

// 0x14ffbb0
void InitModelViewerProcess(void) {
  dds3AdminiCallSequence(35, 0, 0, 0);
}

// 0x14ffbd0
void InitMovieViewerProcess(void) {
  dds3AdminiCallSequence(41, 0, 0, 0);
}

// 0x14ffb90
void InitNameTestProcess(void) {
  dds3AdminiCallSequence(34, 0, 0, 0);
}

// 0x14ff980
void InitNewBattleTestProcess(void) {
  fldBattleData.encountpack = -1;
  dds3AdminiCallSequence(20, 0, 0, 0);
}

// 0x1500180
void InitPipeProcess(void) {
  dds3AdminiCallSequence(19, 0, 0, 0);
}

// 0x14ffc30
void InitPostProcessLayerProcess(void) {
  UnityEngine_GameObject_o *MainCamera;
  Il2CppObject *Component_object;
  UnityEngine_Behaviour_o *v5;
  bool v6;

  MainCamera = GetMainCamera(kernelObject);
  Component_object = GetComponent_object_(MainCamera);
  if (get_enabled(Component_object))
  {
    v5 = Component_object;
    v6 = 0;
  }
  else
  {
    v5 = Component_object;
    v6 = 1;
  }
  set_enabled(v5, v6);
}

// 0x15000e0
void InitPuzzleBoyGame(void) {
  dds3AdminiCallSequence(39, 0, 0, 0);
}

// 0x14ffb10
void InitRagTestProcess(void) {
  dds3AdminiCallSequence(30, 0, 0, 0);
}

// 0x14ffb30
void InitRecoverTestProcess(void) {
  dds3AdminiCallSequence(31, 0, 0, 0);
}

// 0x14ffb70
void InitResult2TestProcess(void) {
  dds3AdminiCallSequence(33, 0, 0, 0);
}

// 0x14ffaf0
void InitShopTestProcess(void) {
  dds3AdminiCallSequence(29, 0, 0, 0);
}

// 0x14ffbf0
void InitSndPtnProcess(void) {
  dds3AdminiCallSequence(44, 0, 0, 0);
}

// 0x14ffc10
void InitSoundTestProcess(void) {
  dds3AdminiCallSequence(36, 0, 0, 0);
}

// 0x1500100
void InitStaffTestProcess(void) {
  u64 *v1;
  s32 v2;

  v2 = 1;
  v1 = sub_8D3950(s32, &v2);
  dds3AdminiCallSequence(17, v1, 0, 0);
}

// 0x14ffb50
void InitTerminalTestProcess(void) {
  dds3AdminiCallSequence(32, 0, 0, 0);
}

// 0x15001c0
void InitTgsProcess(void) {
  dds3AdminiCallSequence(43, 0, 0, 0);
}

// 0x14ffcf0
char *PlStr(void) {
  UnityEngine_GameObject_o *MainCamera;
  Il2CppObject *Component_object;
  bool enabled;
  s64 *v6;

  MainCamera = GetMainCamera(kernelObject);
  Component_object = GetComponent_object_(MainCamera);
  enabled = get_enabled(Component_object);
  v6 = &"ON";
  if (!enabled)
    v6 = &"OFF";
  return *v6;
}

// 0x15001e0
void *dds3StartMenuProcess(dds3ProcessID_t *id) {
  struct UnityEngine_UI_Text_o *menutxt;
  u64 v6;
  struct dds3StartMenu_menu_s_array *menu;
  dds3StartMenu_c *v10;
  s64 *v11;
  s16 v12;
  s32 v13;
  struct dds3StartMenu_menu_s_array *v15;
  struct dds3StartMenu_menu_s_array *v17;
  struct UnityEngine_UI_Text_o *v19;
  System_String_array *v20;
  s64 *Interface;
  s64 *v22;
  s64 v23;
  struct dds3StartMenu_menu_s_array *v24;
  System_String_o *v25;
  System_String_o *name;
  System_String_o *v28;
  System_String_o *v29;
  struct dds3StartMenu_menu_s_array *v30;
  s64 *v32;
  s64 *v33;
  struct dds3StartMenu_menu_s_array *v34;
  System_Object_array *v36;
  s64 *v37;
  s64 *v38;
  struct dds3StartMenu_menu_s_array *v39;
  s32 v41;
  s64 v43;
  struct dds3StartMenu_menu_s_array *v44;
  s64 *v46;
  struct dds3StartMenu_menu_s_array *v50;
  s64 *v52;
  s64 *started;
  struct dds3StartMenu_menu_s_array *v57;
  s64 *v59;
  s64 *v60;
  struct dds3StartMenu_menu_s_array *v64;
  s64 *v66;
  struct dds3StartMenu_menu_s_array *v69;
  struct System_Int32_array *dbg_eff_cut;
  s64 effidx;
  struct dds3StartMenu_menu_s_array *v80;
  s16 v82;
  struct dds3StartMenu_menu_s_array *v86;
  s64 *v88;
  s64 *v90;
  s64 *v91;
  s64 v98;
  struct dds3StartMenu_menu_s_array *v99;
  struct dds3StartMenu_menu_s_array *v104;
  s64 *v106;
  struct dds3StartMenu_menu_s_array *v114;
  s64 cursor;
  struct dds3StartMenu_menu_s_array *v119;
  s64 v120;
  struct dds3StartMenu_menu_s_array *v123;
  s64 v124;
  struct dds3StartMenu_menu_s_array *v128;
  s64 v129;
  struct dds3StartMenu_menu_s_array *v138;
  s64 v139;
  struct dds3StartMenu_menu_s_array *v143;
  struct System_Int32_array *v144;
  s64 v145;
  s64 v147;
  struct dds3StartMenu_menu_s_array *v150;
  struct System_Int32_array *v151;
  s64 v152;
  s64 v154;
  struct dds3StartMenu_menu_s_array *v158;
  struct System_Int32_array *v159;
  s64 v160;
  s64 v162;
  struct dds3StartMenu_menu_s_array *v168;
  struct System_Int32_array *v169;
  s64 v170;
  s64 v172;
  struct dds3StartMenu_menu_s_array *v175;
  struct System_Int32_array *v176;
  s64 v177;
  s64 v179;
  struct dds3StartMenu_menu_s_array *v183;
  struct System_Int32_array *v184;
  s64 v185;
  s64 v187;
  struct dds3StartMenu_menu_s_array *v190;
  s64 v191;
  dds3ProcessID_t_o *v201;
  s32 dbg_draw_stop1;
  s32 x;

  v201 = id;
  x = 0;
  menutxt = dispobj->menutxt;
  (menutxt->klass[1]._1.properties)(menutxt, "     NOCTURNE MANIAX CHRONICLE\n\n", menutxt->klass[1]._1.methods);
  v6 = 0;
  {
LABEL_7:
    goto LABEL_10;
  }
  while (1)
  {
LABEL_10:
    if (!menu->m_Items[v6]->func)
      break;
    v11 = "    ";
    if ((v12 & 0x200) != 0)
    {
      v13 = v12 & 0x200;
    }
    else
    {
      v13 = 0;
    }
    if (v6 == cursor)
      v11 = "  > ";
    else
    {
      v15 = menu;
      if (v6 >= LODWORD(v15->max_length))
        goto LABEL_23;
    }
    if (!v15->m_Items[v6]->noend)
    {
      v19 = dispobj->menutxt;
      v23 = (v19->klass[1]._1.fields)(v19, v19->klass[1]._1.events);
      v24 = menu;
      v25 = v23;
      name = v24->m_Items[v6]->name;
      v28 = "\n";
      goto LABEL_45;
    }
    v17 = menu;
    if (v17->m_Items[v6]->noend == 1)
    {
      v19 = dispobj->menutxt;
      v20 = NewSpecific(string, 5u);
      Interface = (v19->klass[1]._1.fields)(v19, v19->klass[1]._1.events);
      v22 = Interface;
      if (Interface)
      {
        Interface = QueryInterface(Interface, v20->obj.klass->_1.element_class);
      }
      v20->m_Items[0] = v22;
      if (v11)
      {
        Interface = QueryInterface(v11, v20->obj.klass->_1.element_class);
      }
      v20->m_Items[1] = v11;
      v50 = menu;
      v52 = v50->m_Items[v6]->name;
      if (v52)
      {
        Interface = QueryInterface(v52, v20->obj.klass->_1.element_class);
      }
      v20->m_Items[2] = v52;
      started = PlStr(Interface);
      if (!started)
        goto LABEL_137;
      goto LABEL_136;
    }
    v30 = menu;
    if (v30->m_Items[v6]->noend == 2)
    {
      v19 = dispobj->menutxt;
      v20 = NewSpecific(string, 5u);
      v32 = (v19->klass[1]._1.fields)(v19, v19->klass[1]._1.events);
      v33 = v32;
      v20->m_Items[0] = v33;
      v20->m_Items[1] = v11;
      v64 = menu;
      v66 = v64->m_Items[v6]->name;
      v20->m_Items[2] = v66;
      v69 = menu;
      effidx = v69->m_Items[v6]->effidx;
      started = sub_232A70(&dbg_eff_cut->m_Items[effidx], "d3");
      if (!started)
        goto LABEL_137;
      goto LABEL_136;
    }
    v34 = menu;
    if (v34->m_Items[v6]->noend == 3)
    {
      v19 = dispobj->menutxt;
      v36 = NewSpecific(object, 5u);
      v37 = (v19->klass[1]._1.fields)(v19, v19->klass[1]._1.events);
      v38 = v37;
      v36->m_Items[0] = v38;
      v36->m_Items[1] = v11;
      v86 = menu;
      v88 = v86->m_Items[v6]->name;
      v36->m_Items[2] = v88;
      v90 = sub_8D3950(s32, &dbg_draw_stop1);
      v91 = v90;
      v36->m_Items[3] = v91;
      v36->m_Items[4] = "\n";
      v29 = Concat_5270224(v36);
      goto LABEL_144;
    }
    v39 = menu;
    v41 = *&v10->_2.bitflags1 & 0x200;
    if (v39->m_Items[v6]->noend == 4)
    {
      else
      {
        if (!dbg_arrow_hdr)
          goto LABEL_185;
      }
    }
    else
    {
      v57 = menu;
      if (v57->m_Items[v6]->noend == 5)
      {
        v19 = dispobj->menutxt;
        v20 = NewSpecific(string, 5u);
        v59 = (v19->klass[1]._1.fields)(v19, v19->klass[1]._1.events);
        v60 = v59;
        v20->m_Items[0] = v60;
        v20->m_Items[1] = v11;
        v104 = menu;
        v106 = v104->m_Items[v6]->name;
        v20->m_Items[2] = v106;
        started = sub_4FDC70(&dbg_camfar, "f4");
        if (!started)
          goto LABEL_137;
LABEL_136:
LABEL_137:
        v20->m_Items[3] = started;
        v20->m_Items[4] = "\n";
        v29 = Concat_5271600(v20);
        goto LABEL_144;
      }
      v80 = menu;
      if (v80->m_Items[v6]->noend != 6)
        goto LABEL_9;
      if ((v82 & 0x200) != 0)
      {
        v41 = v82 & 0x200;
        if (dbg_effresolution)
        {
LABEL_157:
          if (v41)
          {
LABEL_158:
          }
LABEL_186:
          v19 = dispobj->menutxt;
          v98 = (v19->klass[1]._1.fields)(v19, v19->klass[1]._1.events);
          v99 = menu;
          v25 = v98;
          name = v99->m_Items[v6]->name;
          v46 = &"ON\n";
          goto LABEL_189;
        }
      }
      else
      {
        v41 = 0;
        if (dbg_effresolution)
          goto LABEL_157;
      }
    }
    v19 = dispobj->menutxt;
    v43 = (v19->klass[1]._1.fields)(v19, v19->klass[1]._1.events);
    v44 = menu;
    v25 = v43;
    name = v44->m_Items[v6]->name;
    v46 = &"OFF\n";
LABEL_189:
    v28 = *v46;
LABEL_45:
    v29 = Concat_5271136(v25, v11, name, v28);
LABEL_144:
    (v19->klass[1]._1.properties)(v19, v29, v19->klass[1]._1.methods);
LABEL_9:
    ++v6;
      goto LABEL_7;
  }
  x = 0;
  if (dds3SelectMenu(0, 1, v6, 1, v6, &x, &x, &x, &cursor) == 1)
  {
    v114 = menu;
    if (v114->m_Items[cursor]->func)
    {
      v119 = menu;
      v120 = cursor;
      Invoke(v119->m_Items[v120]->func, 0);
      v123 = menu;
      v124 = cursor;
      if (!v123->m_Items[v124]->noend)
      {
        v201->func_ans = -1;
        return 0;
      }
    }
  }
  v128 = menu;
  v129 = cursor;
  if (v128->m_Items[v129]->noend != 3)
  {
LABEL_260:
      goto LABEL_244;
    goto LABEL_261;
  }
  if (!DDS3_PADCHECK_REP(4))
  {
LABEL_248:
    if (DDS3_PADCHECK_REP(5))
    {
      ++dbg_draw_stop1;
      if (dbg_draw_stop1 >= 11)
      {
        dbg_draw_stop1 = 0;
      }
    }
    goto LABEL_260;
  }
LABEL_236:
  --dbg_draw_stop1;
  if ((dbg_draw_stop1 & 0x80000000) == 0)
    goto LABEL_260;
  dbg_draw_stop1 = 10;
  {
LABEL_244:
  }
LABEL_261:
  v138 = menu;
  v139 = cursor;
  if (v138->m_Items[v139]->noend != 2)
  {
LABEL_314:
      goto LABEL_287;
    goto LABEL_315;
  }
  if (!DDS3_PADCHECK_REP(4))
  {
LABEL_290:
    if (DDS3_PADCHECK_REP(5))
    {
      v168 = menu;
      v169 = dbg_eff_cut;
      v170 = cursor;
      v172 = v168->m_Items[v170]->effidx;
      v169->m_Items[v172] += 5;
      v175 = menu;
      v176 = dbg_eff_cut;
      v177 = cursor;
      v179 = v175->m_Items[v177]->effidx;
      if (v176->m_Items[v179] >= 101)
      {
        v183 = menu;
        v184 = dbg_eff_cut;
        v185 = cursor;
        v187 = v183->m_Items[v185]->effidx;
        v184->m_Items[v187] = 5;
      }
    }
    goto LABEL_314;
  }
LABEL_267:
  v143 = menu;
  v144 = dbg_eff_cut;
  v145 = cursor;
  v147 = v143->m_Items[v145]->effidx;
  v144->m_Items[v147] -= 5;
  v150 = menu;
  v151 = dbg_eff_cut;
  v152 = cursor;
  v154 = v150->m_Items[v152]->effidx;
  if (v151->m_Items[v154] > 4)
    goto LABEL_314;
  v158 = menu;
  v159 = dbg_eff_cut;
  v160 = cursor;
  v162 = v158->m_Items[v160]->effidx;
  v159->m_Items[v162] = 100;
  {
LABEL_287:
  }
LABEL_315:
  v190 = menu;
  v191 = cursor;
  if (v190->m_Items[v191]->noend == 5)
  {
    else if (DDS3_PADCHECK_REP(4))
    {
LABEL_321:
      dbg_camfar = dbg_camfar + -5.0;
      if (dbg_camfar < 5.0)
      {
        dbg_camfar = 5.0;
      }
      return 0;
    }
    if (DDS3_PADCHECK_REP(5))
    {
      dbg_camfar = dbg_camfar + 5.0;
    }
  }
  return 0;
}
