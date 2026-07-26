#include "types.h"

typedef struct bDrawText bDrawText;
typedef struct dds3LightEditorWork_t dds3LightEditorWork_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct mdlDebugLight_dds3LightEditorStrTable_t mdlDebugLight_dds3LightEditorStrTable_t;

struct mdlDebugLight_dds3LightEditorStrTable_t {
    s32 x;
    s32 y;
    u32 attr;
    char *str;
};

static f32 fog_all_off;
static s32 CX__;
static s32 CY__;
static s32 Z__;
static dds3LightEditorWork_t *dds3LightEditorDefWork;
static mdlDebugLight_dds3LightEditorStrTable_t *staticStrTbl[4];
static s32 DDS3_SCREEN_OFFX;
static s32 DDS3_SCREEN_OFFY;
static s32 dds3LightEditorProcess_cursor_y_pos[UNKNOWN_ARRAY_SIZE];
static bDrawText bsetText;
static s16 curmax;

void FromRotation(f32 aAngle);
void PreBtlMenuObj(s32 idx);
void SDF_VU0__APPLYMATRIX_XYZ1(void);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_MTXCOL(sdfMatrix4_t *p);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__VECTOR_W_SET_ONE(void);
void SetBtlMenuObj(s32 idx);
void ToMatrix(void);
bDrawText btlDevPrintf(s32 aX, s32 aY, s32 aZ, s32 color, char *aStr, s32 f);
void btlDrawTagLink(bDrawText *setText, bDrawText dt, s32 idx);
f32 dds3DebugFloatEditEx(f32 aValue, f32 aMin, f32 aMax, f32 aSmall, f32 aLarge, u8 **aPadMap);
void *dds3GetProcessData(dds3ProcessID_t **id);
void dds3LightEditorAngleEdit(dds3LightEditorWork_t **wrk, sdfVector4_t aAngle);
void initBtlMenuObj(s32 x, s32 y, s32 w, s32 h, s32 idx);

// 0xdf9b90
void dds3LightEditorAngleEdit(dds3LightEditorWork_t **wrk, sdfVector4_t aAngle) {
  struct System_Byte_array *padSrc;
  dds3KernelDraw_c *v6;
  struct dds3KernelDraw_StaticFields *static_fields;
  s64 v8;
  s64 v9;
  s64 v10;
  s64 v11;
  s64 v12;
  s64 v13;
  s64 v14;
  f32 v15;
  struct System_Byte_array *v16;
  dds3KernelDraw_c *v18;
  struct dds3KernelDraw_StaticFields *v19;
  s64 v20;
  s64 v21;
  s64 v22;
  s64 v23;
  s64 v24;
  s64 v25;
  s64 v26;
  struct System_Byte_array *v27;
  dds3KernelDraw_c *v29;
  struct dds3KernelDraw_StaticFields *v30;
  s64 v31;
  s64 v32;
  s64 v33;
  s64 v34;
  s64 v35;
  s64 v36;
  s64 v37;
  f32 v38;
  struct System_Byte_array *v39;
  dds3KernelDraw_c *v41;
  struct dds3KernelDraw_StaticFields *v42;
  s64 v43;
  s64 v44;
  s64 v45;
  s64 v46;
  s64 v47;
  s64 v48;
  s64 v49;
  UnityEngine_Matrix4x4_o v50;
  UnityEngine_Matrix4x4_o v51;
  UnityEngine_Matrix4x4_o v52;
  UnityEngine_Matrix4x4_o v53;
  UnityEngine_Vector4_o p;

  p = aAngle;
  padSrc = (*wrk)->padSrc;
  if (padSrc->m_Items[5])
  {
    static_fields = v6->static_fields;
    v8 = *&static_fields->dds3CameraTM.m00;
    v9 = *&static_fields->dds3CameraTM.m20;
    v10 = *&static_fields->dds3CameraTM.m21;
    *&v53.m01 = *&static_fields->dds3CameraTM.m01;
    *&v53.m21 = v10;
    *&v53.m00 = v8;
    *&v53.m20 = v9;
    v11 = *&static_fields->dds3CameraTM.m02;
    v12 = *&static_fields->dds3CameraTM.m22;
    v14 = *&static_fields->dds3CameraTM.m03;
    v13 = *&static_fields->dds3CameraTM.m23;
    *&v53.m03 = v14;
    *&v53.m23 = v13;
    *&v53.m02 = v11;
    *&v53.m22 = v12;
    SDF_VU0__LOADVECTOR_MTXCOL(&v53);
    v15 = 0.034907;
    FromRotation(v15);
    ToMatrix();
    SDF_VU0__LOADVECTOR(p);
    SDF_VU0__APPLYMATRIX_XYZ1();
    SDF_VU0__VECTOR_W_SET_ONE();
    SDF_VU0__STOREVECTOR(&p);
  }
  v16 = (*wrk)->padSrc;
  if (v16->m_Items[4])
  {
    v19 = v18->static_fields;
    v20 = *&v19->dds3CameraTM.m00;
    v21 = *&v19->dds3CameraTM.m20;
    v22 = *&v19->dds3CameraTM.m21;
    *&v52.m01 = *&v19->dds3CameraTM.m01;
    *&v52.m21 = v22;
    *&v52.m00 = v20;
    *&v52.m20 = v21;
    v23 = *&v19->dds3CameraTM.m02;
    v24 = *&v19->dds3CameraTM.m22;
    v26 = *&v19->dds3CameraTM.m03;
    v25 = *&v19->dds3CameraTM.m23;
    *&v52.m03 = v26;
    *&v52.m23 = v25;
    *&v52.m02 = v23;
    *&v52.m22 = v24;
    SDF_VU0__LOADVECTOR_MTXCOL(&v52);
    v15 = -0.034907;
  }
  v27 = (*wrk)->padSrc;
  if (v27->m_Items[7])
  {
    v30 = v29->static_fields;
    v31 = *&v30->dds3CameraTM.m00;
    v32 = *&v30->dds3CameraTM.m20;
    v33 = *&v30->dds3CameraTM.m21;
    *&v51.m01 = *&v30->dds3CameraTM.m01;
    *&v51.m21 = v33;
    *&v51.m00 = v31;
    *&v51.m20 = v32;
    v34 = *&v30->dds3CameraTM.m02;
    v35 = *&v30->dds3CameraTM.m22;
    v37 = *&v30->dds3CameraTM.m03;
    v36 = *&v30->dds3CameraTM.m23;
    *&v51.m03 = v37;
    *&v51.m23 = v36;
    *&v51.m02 = v34;
    *&v51.m22 = v35;
    SDF_VU0__LOADVECTOR_MTXCOL(&v51);
    v38 = -0.034907;
    FromRotation(v38);
    ToMatrix();
    SDF_VU0__LOADVECTOR(p);
    SDF_VU0__APPLYMATRIX_XYZ1();
    SDF_VU0__VECTOR_W_SET_ONE();
    SDF_VU0__STOREVECTOR(&p);
    return;
  }
  v39 = (*wrk)->padSrc;
  if (v39->m_Items[6])
  {
    v42 = v41->static_fields;
    v43 = *&v42->dds3CameraTM.m00;
    v44 = *&v42->dds3CameraTM.m20;
    v45 = *&v42->dds3CameraTM.m21;
    *&v50.m01 = *&v42->dds3CameraTM.m01;
    *&v50.m21 = v45;
    *&v50.m00 = v43;
    *&v50.m20 = v44;
    v46 = *&v42->dds3CameraTM.m02;
    v47 = *&v42->dds3CameraTM.m22;
    v49 = *&v42->dds3CameraTM.m03;
    v48 = *&v42->dds3CameraTM.m23;
    *&v50.m03 = v49;
    *&v50.m23 = v48;
    *&v50.m02 = v46;
    *&v50.m22 = v47;
    SDF_VU0__LOADVECTOR_MTXCOL(&v50);
    v38 = 0.034907;
  }
}

// 0xdf9e90
void *dds3LightEditorProcess(dds3ProcessID_t *aId) {
    initBtlMenuObj(0, 0, 0, 0, 0);
    PreBtlMenuObj(0);
    dds3GetProcessData(0);
    dds3LightEditorAngleEdit(0, (sdfVector4_t){0});
    dds3DebugFloatEditEx(0, 0, 0, 0, 0, 0);
    btlDevPrintf(0, 0, 0, 0, 0, 0);
    btlDrawTagLink(0, (bDrawText){0}, 0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SetBtlMenuObj(0);
    return 0;
}
