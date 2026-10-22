#include "types.h"

typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct pbProcHandle_t pbProcHandle_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfPrimTransPacket_t sdfPrimTransPacket_t;

static void *pbEcode;

void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
void dds3SetProcessData(dds3ProcessID_t **id, void *data);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
s32 pb_General__PB_PROC_REF_MESS(pbProcHandle_t *p);
void pb_General__PB_PROC_SEND_MESS(pbProcHandle_t *p, s32 mes);
void rsetAlpha(s32 mode);
void rsetOtOfs(s32 otofs);
void rsetTest(s32 ate, s32 atst, s32 aref, s32 afail, s32 date, s32 datm, s32 zte, s32 ztst);
void *sdfDevPrintf(s32 aX, s32 aY, u32 aZ, s32 aAttr, char *aStr, void **LegacyParamArray);
s32 sdfDrawTagInit(sdfDrawTag_t *a);
void sdfDrawTagLink(sdfDrawTag_t *aTag, void *aPacket);
s32 sdfDrawTagLinkOt(s32 a, sdfDrawTag_t *b);
void sdfPrimSetOpaquePacket(sdfPrimTransPacket_t *aPkt);

// 0x1657370
void *dds3PrimFrameRect(s32 aX, s32 aY, u32 aZ, s32 aW, s32 aH, u32 aBgCol, u32 aFrameCol) {
  s32 v9;

  v9 = 0;
  return sub_8D3950(s32, &v9);
}

// 0x1657d80
dds3ProcessFunc_t *deleteError(dds3ProcessID_t *id) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v6;
  u64 *image;
  s64 v8;
  char *v9;
  s64 *v10;
  char *v12;
  s64 *v13;
  u64 v14[2];
  char *v15;

  workdata = id->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbProcHandle_t)
  {
    sub_8FC2C0(klass->_1.element_class, pbProcHandle_t, v14);
    if ((v14[0] & 1) != 0)
      v12 = v15;
    else
      v12 = v14 + 1;
    v13 = sub_8C4940(v12);
  }
  v6 = workdata[2].klass;
  else if (!v6)
  {
    goto LABEL_15;
  }
  image = v6->_1.image;
  if (*(v6->_1.image + 288) < v8 || *(image[25] + 8 * v8 - 8) != pbError_t)
  {
    sub_8FC2C0(image[8], pbError_t, v14);
    if ((v14[0] & 1) != 0)
      v9 = v15;
    else
      v9 = v14 + 1;
    v10 = sub_8C4940(v9);
  }
LABEL_15:
  id->func_ans = -1;
  return 0;
}

// 0x16573e0
dds3ProcessFunc_t *error(dds3ProcessID_t *id) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v6;
  u64 *image;
  s64 v8;
  char *v9;
  s64 *v10;
  u64 *v11;
  u64 *v12;
  s32 v14;
  u32 name;
  UnityEngine_Transform_o *v19;
  UnityEngine_Component_o *v20;
  UnityEngine_GameObject_o *v21;
  UnityEngine_GameObject_o *oPB_UI;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v27;
  struct System_Object_array *pbEcode;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;
  Il2CppObject *v35;
  s64 v36;
  Il2CppClass *v37;
  Il2CppObject *monitor;
  System_String_o *v39;
  s32 v40;
  u64 *v41;
  u64 *v43;
  u64 *v44;
  struct System_Object_array *v45;
  Il2CppArrayBounds *v46;
  s64 name_low;
  il2cpp_array_size_t v49;
  Il2CppObject *v51;
  s64 v52;
  Il2CppClass *v53;
  s32 v54;
  struct System_Object_array *v55;
  Il2CppArrayBounds *v56;
  s64 v57;
  il2cpp_array_size_t v59;
  Il2CppObject **v61;
  s64 v62;
  Il2CppObject *v63;
  s32 v64;
  System_String_o *v65;
  System_Object_array *v67;
  Il2CppObject *v68;
  struct sdfGrOt_t_array *dds3Ot;
  char *v74;
  s64 *v75;
  char *v76;
  s64 *v77;
  char *v78;
  s64 *v79;
  char *v80;
  s64 *v81;
  char v82[16];
  char *v83;

  workdata = id->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbProcHandle_t)
  {
    sub_8FC2C0(klass->_1.element_class, pbProcHandle_t, v82);
    if ((v82[0] & 1) != 0)
      v74 = v83;
    else
      v74 = &v82[1];
    v75 = sub_8C4940(v74);
  }
  v6 = workdata[2].klass;
  if (v6)
  {
    image = v6->_1.image;
    if (*(v6->_1.image + 288) < v8 || *(image[25] + 8 * v8 - 8) != pbError_t)
    {
      sub_8FC2C0(image[8], pbError_t, v82);
      if ((v82[0] & 1) != 0)
        v9 = v83;
      else
        v9 = &v82[1];
      v10 = sub_8C4940(v9);
    }
  }
  v11 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v11);
  v12 = Allocate(sdfPrimTransPacket_t);
  sdfPrimTransPacket_t___ctor(v12);
  v14 = pb_General__PB_PROC_REF_MESS(workdata);
  if (v14 == 5)
  {
    id->func_ans = -1;
  }
  else
  {
    if (v14 == 1)
    {
      pb_General__PB_PROC_SEND_MESS(workdata, 0);
    }
    if (HIDWORD(v6->_1.name) >= LODWORD(v6->_1.namespaze))
    {
      gameObject = 0;
      if (op_Inequality(oPB_UI, 0, 0))
      {
        transform = get_transform(oPB_UI, 0);
        v27 = Find(transform, "pzlundo", 0);
        gameObject = get_gameObject(v27);
      }
      if (!op_Equality(gameObject, 0, 0))
      {
        if (op_Inequality(gameObject, 0, 0)
          && get_activeSelf(gameObject))
        {
          SetActive(gameObject, 0, 0);
        }
      }
    }
    else
    {
      name = v6->_1.name;
      if (name == 9)
      {
        rsetOtOfs(71);
        rsetAlpha(0);
        rsetTest(1, 0, 128, 3, 0, 0, 1, 1);
        v19 = get_transform(oPB_UI, 0);
        v20 = Find(v19, "pzlundo", 0);
        v21 = get_gameObject(v20);
        if (!get_activeSelf(v21))
          SetActive(v21, 1, 0);
      }
      else
      {
        bounds = pbEcode->bounds;
        length = bounds[1].length;
        v35 = pbEcode->m_Items[length * name];
        v37 = v35->klass;
        if (v35->klass->_2.typeHierarchyDepth < v36 || v37->_2.typeHierarchy[v36 - 1] != pbErrorCode_t)
        {
          sub_8FC2C0(v37->_1.element_class, pbErrorCode_t, v82);
          if ((v82[0] & 1) != 0)
            v76 = v83;
          else
            v76 = &v82[1];
          v77 = sub_8C4940(v76);
        }
        monitor = v35[1].monitor;
        v39 = ToString(monitor, 0);
        v40 = get_Length(v39);
        v41 = Allocate(sdfDrawTag_t);
        sdfDrawTag_t___ctor(v41);
        sdfDrawTagInit(v41);
        v43 = Allocate(sdfPrimTransPacket_t);
        sdfPrimTransPacket_t___ctor(v43);
        sdfPrimSetOpaquePacket(v43);
        sdfDrawTagLink(v41, v43);
        *v82 = 0;
        v44 = sub_8D3950(s32, v82);
        sdfDrawTagLink(v41, v44);
        v45 = pbEcode;
        v46 = v45->bounds;
        name_low = LODWORD(v6->_1.name);
        v49 = v46[1].length;
        v51 = v45->m_Items[v49 * name_low];
        v53 = v51->klass;
        if (v51->klass->_2.typeHierarchyDepth < v52 || v53->_2.typeHierarchy[v52 - 1] != pbErrorCode_t)
        {
          sub_8FC2C0(v53->_1.element_class, pbErrorCode_t, v82);
          if ((v82[0] & 1) != 0)
            v78 = v83;
          else
            v78 = &v82[1];
          v79 = sub_8C4940(v78);
        }
        v54 = v51[1].klass;
        v55 = pbEcode;
        v56 = v55->bounds;
        v57 = LODWORD(v6->_1.name);
        v59 = v56[1].length;
        v61 = v55->m_Items[v59 * v57];
        v63 = *v61;
        if (LOBYTE((*v61)[18].klass) < v62 || *(v63[12].monitor + v62 - 1) != pbErrorCode_t)
        {
          sub_8FC2C0(v63[4].klass, pbErrorCode_t, v82);
          if ((v82[0] & 1) != 0)
            v80 = v83;
          else
            v80 = &v82[1];
          v81 = sub_8C4940(v80);
        }
        v64 = -96 * v40;
        v65 = ToString(v61[3], 0);
        v67 = Empty_string_();
        v68 = sdfDevPrintf(v64 + 0x8000, 32720, 0xFFFF80u, v54, v65, v67);
        sdfDrawTagLink(v41, v68);
        sdfDrawTagLinkOt(dds3Ot->m_Items[39], v41);
      }
      ++HIDWORD(v6->_1.name);
    }
  }
  return 0;
}

// 0x1657f30
pbProcHandle_t *pbStartErrorDraw(pbProcHandle_t *parent, u32 eCode, u32 frame) {
  u64 *v7;
  u64 *v8;
  pbProcHandle_t_o *v9;
  u64 *v10;
  u64 *v11;
  pbProcHandle_t_Fields *p_fields;
  u64 *v15;
  u64 v17;
  s64 typeHierarchyDepth;
  char *v21;
  s64 *v22;
  u64 v23[3];

  v7 = Allocate(pbProcHandle_t);
  pbProcHandle_t___ctor(v7);
  v8 = Allocate(pbError_t);
  _ctor(v8, 0);
  v9 = Allocate(pbProcHandle_t);
  pbProcHandle_t___ctor(v9);
  v10 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v10,
    0,
    Method_pbErrorDraw_error__);
  v11 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v11,
    0,
    Method_pbErrorDraw_deleteError__);
  v9->id = dds3StartProcess("pb-draw-error", 0x2AFDu, 1, 1, v10, 0, v11, 0, 0, 0);
  if (parent)
  {
    p_fields = &parent->fields;
    dds3LinkProcess(&p_fields->id, &v9->id);
  }
  v15 = Allocate(pbError_t);
  _ctor(v15, 0);
  v9->data = v15;
  v17 = *v15;
  if (*(*v15 + 288) < typeHierarchyDepth || *(*(v17 + 200) + 8 * typeHierarchyDepth - 8) != pbError_t)
  {
    sub_8FC2C0(*(v17 + 64), pbError_t, v23);
    if ((v23[0] & 1) != 0)
      v21 = v23[2];
    else
      v21 = v23 + 1;
    v22 = sub_8C4940(v21);
  }
  *(v15 + 6) = frame;
  *(v15 + 4) = eCode;
  *(v15 + 5) = 0;
  pb_General__PB_PROC_SEND_MESS(v9, 1);
  dds3SetProcessData(&v9->id, v9);
  return v9;
}

// 0x16573d0
void sdfChipFreeDelayed(void *aPtr) {
  ;
}
