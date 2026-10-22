#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ObjectBaseControlWorkData_t dds3ObjectBaseControlWorkData_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;

bool DDS3_PAD2CHECK_TRIG(s32 id);
s32 DispBaseData(dds3Basic_t *basic, s32 x, s32 y, sdfDrawTag_t *tag);
s32 DispObjectBaseData(dds3Basic_t *basic, s32 x, s32 y, sdfDrawTag_t *tag);
void dds3ConsPanelTagLink(sdfDrawTag_t *tag, s32 x, s32 y, s32 sx, s32 sy);
dds3Basic_t *dds3GetActiveScene(void);
dds3ObjectBaseControlWorkData_t *dds3GetBaseControlWorkData(dds3Basic_t **pObjectBasic);
void *dds3GetProcessData(dds3ProcessID_t **id);
s32 dds3SceneBasicExistBasic(dds3Basic_t **scene, dds3Basic_t **target);
void *sdfDevPrintf(s32 aX, s32 aY, u32 aZ, s32 aAttr, char *aStr, void **LegacyParamArray);
s32 sdfDrawTagInit(sdfDrawTag_t *a);
void sdfDrawTagLink(sdfDrawTag_t *aTag, void *aPacket);

// 0x152ed30
s32 DispBaseData(dds3Basic_t *basic, s32 x, s32 y, sdfDrawTag_t *tag) {
  System_Object_array *v9;
  System_Object_array *v10;
  s64 *v11;
  s64 *v13;
  s32 v15;
  s32 v16;
  s32 v17;
  Il2CppObject *v19;
  u64 *v20;
  struct System_String_o *name;
  u64 *v22;
  Il2CppObject *v24;
  struct dds3PoseSet_t_o *poseset;
  System_Object_array *v27;
  Il2CppObject *v29;
  System_Object_array *v30;
  u32 v31;
  s64 *v32;
  s64 *v33;
  s32 v35;
  s64 *v36;
  s64 *v37;
  s32 v39;
  s64 *v40;
  s64 *v41;
  s32 v43;
  Il2CppObject *v44;
  System_Object_array *v45;
  Il2CppObject *v46;
  System_Object_array *v47;
  s32 v48;
  s64 *v49;
  s64 *v50;
  s32 v52;
  s64 *v53;
  s64 *v54;
  s32 v56;
  s64 *v57;
  s64 *v58;
  s32 v60;
  s64 *v61;
  s64 *v62;
  Il2CppObject *v64;
  System_Object_array *v65;
  Il2CppObject *v66;
  System_Object_array *v67;
  s32 v68;
  s64 *v69;
  s64 *v70;
  s32 v72;
  s64 *v73;
  s64 *v74;
  s32 v76;
  s64 *v77;
  s64 *v78;
  Il2CppObject *v80;
  s32 v94;
  s32 v95;
  s32 v96;
  s32 v97;
  s32 v98;
  s32 v99;
  s32 v100;
  s32 v101;
  s32 v102;
  u32 serialID;

  v9 = NewSpecific(object, 1u);
  serialID = basic->serialID;
  v10 = v9;
  v11 = sub_8D3950(uint, &serialID);
  v13 = v11;
  v10->m_Items[0] = v13;
  v15 = 192 * x;
  v16 = v15 + 28672;
  v17 = 96 * y;
  v19 = sdfDevPrintf(v15 + 28672, 96 * y + 30976, 0xFEFFFFu, 0, "ID    : 0x%05X", v10);
  sdfDrawTagLink(tag, v19);
  v20 = NewSpecific(object, 1u);
  name = basic->name;
  v22 = v20;
  v22[4] = name;
  v24 = sdfDevPrintf(v16, v17 + 31072, 0xFEFFFFu, 0, "NAME  : %s", v22);
  sdfDrawTagLink(tag, v24);
  poseset = basic->poseset;
  if (!poseset)
    return 2;
  v27 = Empty_string_();
  v29 = sdfDevPrintf(v16, v17 + 31264, 0xFEFFFFu, 0, "POS  :", v27);
  sdfDrawTagLink(tag, v29);
  v30 = NewSpecific(object, 3u);
  sub_854710(&poseset->pos, 0);
  serialID = v31;
  v32 = sub_8D3950(f32, &serialID);
  v33 = v32;
  v30->m_Items[0] = v33;
  sub_854710(&poseset->pos, 1u);
  v102 = v35;
  v36 = sub_8D3950(f32, &v102);
  v37 = v36;
  v30->m_Items[1] = v37;
  sub_854710(&poseset->pos, 2u);
  v101 = v39;
  v40 = sub_8D3950(f32, &v101);
  v41 = v40;
  v30->m_Items[2] = v41;
  v43 = v15 + 30016;
  v44 = sdfDevPrintf(v15 + 30016, v17 + 31264, 0xFEFFFFu, 14, "%3.2f %3.2f %3.2f", v30);
  sdfDrawTagLink(tag, v44);
  v45 = Empty_string_();
  v46 = sdfDevPrintf(v16, v17 + 31456, 0xFEFFFFu, 0, "ROT  :", v45);
  sdfDrawTagLink(tag, v46);
  v47 = NewSpecific(object, 4u);
  sub_854710(&poseset->rot, 0);
  v100 = v48;
  v49 = sub_8D3950(f32, &v100);
  v50 = v49;
  v47->m_Items[0] = v50;
  sub_854710(&poseset->rot, 1u);
  v99 = v52;
  v53 = sub_8D3950(f32, &v99);
  v54 = v53;
  v47->m_Items[1] = v54;
  sub_854710(&poseset->rot, 2u);
  v98 = v56;
  v57 = sub_8D3950(f32, &v98);
  v58 = v57;
  v47->m_Items[2] = v58;
  sub_854710(&poseset->rot, 3u);
  v97 = v60;
  v61 = sub_8D3950(f32, &v97);
  v62 = v61;
  v47->m_Items[3] = v62;
  v64 = sdfDevPrintf(v43, v17 + 31456, 0xFEFFFFu, 14, "%3.2f %3.2f %3.2f %3.2f", v47);
  sdfDrawTagLink(tag, v64);
  v65 = Empty_string_();
  v66 = sdfDevPrintf(v16, v17 + 31648, 0xFEFFFFu, 0, "SCL  :", v65);
  sdfDrawTagLink(tag, v66);
  v67 = NewSpecific(object, 3u);
  sub_854710(&poseset->scl, 0);
  v96 = v68;
  v69 = sub_8D3950(f32, &v96);
  v70 = v69;
  v67->m_Items[0] = v70;
  sub_854710(&poseset->scl, 1u);
  v95 = v72;
  v73 = sub_8D3950(f32, &v95);
  v74 = v73;
  v67->m_Items[1] = v74;
  sub_854710(&poseset->scl, 2u);
  v94 = v76;
  v77 = sub_8D3950(f32, &v94);
  v78 = v77;
  v67->m_Items[2] = v78;
  v80 = sdfDevPrintf(v43, v17 + 31648, 0xFEFFFFu, 14, "%3.1f %3.1f %3.1f", v67);
  sdfDrawTagLink(tag, v80);
  return 8;
}

// 0x152f680
s32 DispObjectBaseData(dds3Basic_t *basic, s32 x, s32 y, sdfDrawTag_t *tag) {
  dds3ObjectBaseControlWorkData_t_o *BaseControlWorkData;
  System_Object_array *v9;
  System_Object_array *v10;
  s64 *v11;
  s64 *v13;
  Il2CppObject *v16;
  u32 flag;
  dds3Basic_t_o *pObjectBasic;

  pObjectBasic = basic;
  BaseControlWorkData = dds3GetBaseControlWorkData(&pObjectBasic);
  v9 = NewSpecific(object, 1u);
  flag = BaseControlWorkData->flag;
  v10 = v9;
  v11 = sub_8D3950(uint, &flag);
  v13 = v11;
  v10->m_Items[0] = v13;
  v16 = sdfDevPrintf(192 * x + 28672, 96 * y + 30976, 0xFEFFFFu, 0, "FLAG  : 0x%08X", v10);
  sdfDrawTagLink(tag, v16);
  return 1;
}

// 0x152f810
dds3ProcessFunc_t *dds3DebugBasic(dds3ProcessID_t *id) {
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 *v9;
  s32 v14;
  dds3Basic_t_o *v15;
  u64 *v16;
  u64 *v19;
  u64 *v20;
  char *v21;
  s64 *v22;
  s32 v24;
  dds3Basic_t_o *scene;
  dds3Basic_t_o *target;
  u64 v27[2];
  char *v28;
  dds3ProcessID_t_o *ida;

  ida = id;
  target = 0;
  scene = 0;
  else
  {
    scene = dds3GetActiveScene();
    if (scene)
    {
LABEL_6:
      else
      {
        ProcessData = dds3GetProcessData(&ida);
        if (ProcessData)
        {
LABEL_9:
          klass = ProcessData->klass;
          if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
            || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Basic_t)
          {
            sub_8FC2C0(klass->_1.element_class, dds3Basic_t, v27);
            if ((v27[0] & 1) != 0)
              v7 = v28;
            else
              v7 = v27 + 1;
            v8 = sub_8C4940(v7);
          }
        }
      }
      target = ProcessData;
      if (!dds3SceneBasicExistBasic(&scene, &target))
        goto LABEL_34;
      v9 = Allocate(sdfDrawTag_t);
      sdfDrawTag_t___ctor(v9);
      sdfDrawTagInit(v9);
      v14 = DispBaseData(target, 3, 10, v9) + 11;
      v15 = target;
      if (HIBYTE(v15->type) - 4 <= 5)
        v14 += DispObjectBaseData(target, 3, v14, v9);
      v16 = Allocate(sdfDrawTag_t);
      sdfDrawTag_t___ctor(v16);
      sdfDrawTagInit(v16);
      dds3ConsPanelTagLink(v16, 36, 114, 35, v14 - 9);
      v19 = 0;
      if (DDS3_PAD2CHECK_TRIG(3))
      {
LABEL_34:
        v19 = Allocate(dds3ProcessFunc_t);
        dds3ProcessFunc_t___ctor(v19, 0, Method_evtDebug_evtSceneDispProcess__);
      }
      return v19;
    }
  }
  v24 = -1;
  v20 = sub_8D3950(s32, &v24);
  v19 = v20;
  if (v20 && *v20 != dds3ProcessFunc_t)
  {
    sub_8FC2C0(*(*v20 + 64), dds3ProcessFunc_t, v27);
    if ((v27[0] & 1) != 0)
      v21 = v28;
    else
      v21 = v27 + 1;
    v22 = sub_8C4940(v21);
  }
  return v19;
}
