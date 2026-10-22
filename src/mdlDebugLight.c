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
static s32 *dds3LightEditorProcess_cursor_y_pos;
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
  s64 v8;
  s64 v9;
  s64 v10;
  s64 v11;
  s64 v12;
  s64 v13;
  s64 v14;
  f32 v15;
  struct System_Byte_array *v16;
  s64 v20;
  s64 v21;
  s64 v22;
  s64 v23;
  s64 v24;
  s64 v25;
  s64 v26;
  struct System_Byte_array *v27;
  s64 v31;
  s64 v32;
  s64 v33;
  s64 v34;
  s64 v35;
  s64 v36;
  s64 v37;
  f32 v38;
  struct System_Byte_array *v39;
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
    v8 = *&dds3CameraTM.m00;
    v9 = *&dds3CameraTM.m20;
    v10 = *&dds3CameraTM.m21;
    *&v53.m01 = *&dds3CameraTM.m01;
    *&v53.m21 = v10;
    *&v53.m00 = v8;
    *&v53.m20 = v9;
    v11 = *&dds3CameraTM.m02;
    v12 = *&dds3CameraTM.m22;
    v14 = *&dds3CameraTM.m03;
    v13 = *&dds3CameraTM.m23;
    *&v53.m03 = v14;
    *&v53.m23 = v13;
    *&v53.m02 = v11;
    *&v53.m22 = v12;
    SDF_VU0__LOADVECTOR_MTXCOL(&v53);
    v15 = 0.034907;
LABEL_17:
    FromRotation(v15);
    ToMatrix();
    SDF_VU0__LOADVECTOR(p);
    SDF_VU0__APPLYMATRIX_XYZ1();
    SDF_VU0__VECTOR_W_SET_ONE();
    SDF_VU0__STOREVECTOR(&p);
    goto LABEL_18;
  }
  v16 = (*wrk)->padSrc;
  if (v16->m_Items[4])
  {
    v20 = *&dds3CameraTM.m00;
    v21 = *&dds3CameraTM.m20;
    v22 = *&dds3CameraTM.m21;
    *&v52.m01 = *&dds3CameraTM.m01;
    *&v52.m21 = v22;
    *&v52.m00 = v20;
    *&v52.m20 = v21;
    v23 = *&dds3CameraTM.m02;
    v24 = *&dds3CameraTM.m22;
    v26 = *&dds3CameraTM.m03;
    v25 = *&dds3CameraTM.m23;
    *&v52.m03 = v26;
    *&v52.m23 = v25;
    *&v52.m02 = v23;
    *&v52.m22 = v24;
    SDF_VU0__LOADVECTOR_MTXCOL(&v52);
    v15 = -0.034907;
    goto LABEL_17;
  }
LABEL_18:
  v27 = (*wrk)->padSrc;
  if (v27->m_Items[7])
  {
    v31 = *&dds3CameraTM.m00;
    v32 = *&dds3CameraTM.m20;
    v33 = *&dds3CameraTM.m21;
    *&v51.m01 = *&dds3CameraTM.m01;
    *&v51.m21 = v33;
    *&v51.m00 = v31;
    *&v51.m20 = v32;
    v34 = *&dds3CameraTM.m02;
    v35 = *&dds3CameraTM.m22;
    v37 = *&dds3CameraTM.m03;
    v36 = *&dds3CameraTM.m23;
    *&v51.m03 = v37;
    *&v51.m23 = v36;
    *&v51.m02 = v34;
    *&v51.m22 = v35;
    SDF_VU0__LOADVECTOR_MTXCOL(&v51);
    v38 = -0.034907;
LABEL_32:
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
    v43 = *&dds3CameraTM.m00;
    v44 = *&dds3CameraTM.m20;
    v45 = *&dds3CameraTM.m21;
    *&v50.m01 = *&dds3CameraTM.m01;
    *&v50.m21 = v45;
    *&v50.m00 = v43;
    *&v50.m20 = v44;
    v46 = *&dds3CameraTM.m02;
    v47 = *&dds3CameraTM.m22;
    v49 = *&dds3CameraTM.m03;
    v48 = *&dds3CameraTM.m23;
    *&v50.m03 = v49;
    *&v50.m23 = v48;
    *&v50.m02 = v46;
    *&v50.m22 = v47;
    SDF_VU0__LOADVECTOR_MTXCOL(&v50);
    v38 = 0.034907;
    goto LABEL_32;
  }
}

// 0xdf9e90
void *dds3LightEditorProcess(dds3ProcessID_t *aId) {
  Il2CppObject *ProcessData;
  dds3LightEditorWork_t_c *v4;
  Il2CppClass *klass;
  dds3LightEditorWork_t_o *v7;
  dds3LightEditorWork_t_o *dds3LightEditorDefWork;
  struct System_Byte_array_array_array *dds3PadMap;
  System_Byte_array_array *v13;
  struct System_Byte_array_array_array *v14;
  System_Byte_array_array *v15;
  struct sdf3DLight_t_array **p_fld_player_lights;
  dds3LightEditorWork_t_o *v19;
  f32 *p_x;
  f32 *p_y;
  f32 *p_z;
  f32 *p_w;
  f32 v28;
  f32 v29;
  f32 v30;
  struct System_Byte_array *padSrc;
  u32 max_length;
  struct System_Byte_array *v34;
  dds3LightEditorWork_t_o *v36;
  s32 v37;
  f32 ToonType;
  System_Byte_array *v40;
  dds3LightEditorWork_t_o *v43;
  struct System_Byte_array *v44;
  struct System_Byte_array *v46;
  struct System_Byte_array *v48;
  struct System_Byte_array *v50;
  struct System_Byte_array *v52;
  s32 cursor;
  s32 v60;
  struct sdf3DLight_t_array *lightSrc;
  u32 v62;
  s64 v63;
  f32 *v65;
  s32 v66;
  f32 v67;
  f32 v68;
  f32 v69;
  f32 v70;
  s32 v72;
  f32 z;
  System_Byte_array *v74;
  s32 v76;
  bool v77;
  struct sdf3DLight_t_array *v79;
  sdf3DLight_t_o *v80;
  f32 x;
  System_Byte_array *v82;
  s32 v83;
  dds3LightEditorWork_t_o *v84;
  s32 cursorTimer;
  u8 v86;
  s32 v88;
  s64 v89;
  System_String_o **v90;
  System_String_o **v91;
  s32 v92;
  s32 v93;
  System_String_o **v94;
  u64 v95;
  struct mdlDebugLight_dds3LightEditorStrTable_t_array *staticStrTbl;
  s32 v97;
  s64 v99;
  s32 v100;
  s32 v101;
  s32 v102;
  System_String_o **v103;
  System_String_o *v105;
  struct sdf3DLight_t_array *v106;
  s64 v108;
  s32 v110;
  System_String_o *v111;
  System_String_o *v113;
  s32 v115;
  System_String_o *v116;
  System_String_o *v118;
  s32 v120;
  System_String_o *v121;
  System_String_o *v123;
  s32 v125;
  System_String_o *v126;
  System_String_o *v128;
  System_String_o *v129;
  System_String_o *v130;
  System_String_o *v131;
  System_String_o *v132;
  struct mdlDebugLight_dds3LightEditorStrTable_t_array *v133;
  s32 v134;
  mdlDebugLight_dds3LightEditorStrTable_t_o *v136;
  s32 v137;
  s32 v138;
  s32 attr;
  System_String_o *v141;
  s32 v143;
  System_String_o *v144;
  System_String_o *v146;
  s32 v148;
  System_String_o *v149;
  System_String_o *v151;
  s32 v153;
  System_String_o *v154;
  System_String_o *v156;
  s32 v158;
  System_String_o *v160;
  System_String_o *v162;
  s32 v164;
  System_String_o *v166;
  System_String_o *v168;
  s32 v170;
  System_String_o *v172;
  System_String_o *v174;
  s32 v176;
  System_String_o *v178;
  System_String_o *v180;
  s32 v182;
  System_String_o *v184;
  System_String_o *v186;
  s32 v188;
  System_String_o *v190;
  System_String_o *v192;
  dds3LightEditorWork_t_o *v194;
  struct sdf3DLight_t_array *v195;
  s64 v197;
  f32 w;
  f32 v200;
  f32 *v201;
  s64 v203;
  f32 v204;
  f32 v207;
  System_Byte_array *v208;
  f32 v209;
  System_Byte_array *v210;
  struct sdf3DLight_t_array *v211;
  struct sdf3DLight_t_array *v212;
  sdf3DLight_t_o *v213;
  f32 y;
  System_Byte_array *v215;
  f32 ToonTypeStart;
  System_Byte_array *v218;
  f32 ToonTypeDiv;
  System_Byte_array *v221;
  f32 Adj_ColorR;
  System_Byte_array *v224;
  f32 Adj_ColorG;
  System_Byte_array *v227;
  f32 Adj_ColorB;
  System_Byte_array *v230;
  s32 v234;
  s64 v235;
  s64 v236;
  s64 v237;
  s64 v238;
  dds3LightEditorWork_t_o *wrk;
  dds3ProcessID_t_o *id;
  u64 v241[3];
  bDrawText_o v242;
  bDrawText_o v243;
  bDrawText_o v244;
  bDrawText_o v245;
  bDrawText_o v246;
  bDrawText_o v247;
  bDrawText_o v248;
  bDrawText_o v249;
  bDrawText_o v250;
  bDrawText_o v251;
  bDrawText_o v252;
  bDrawText_o v253;
  bDrawText_o v254;
  bDrawText_o v255;
  bDrawText_o v256;
  bDrawText_o v257;
  bDrawText_o v258;
  bDrawText_o v259;
  bDrawText_o v260;
  UnityEngine_Vector4_o v261;

  id = aId;
  v238 = 0;
  wrk = 0;
  v236 = 0;
  v237 = 0;
  v235 = 0;
  v234 = 0;
  initBtlMenuObj(1380, 0, 540, 1000, 0);
  PreBtlMenuObj(0);
  else
  {
    ProcessData = dds3GetProcessData(&id);
    if (ProcessData)
      goto LABEL_9;
  }
  wrk = 0;
  wrk = dds3LightEditorDefWork;
  if (!LODWORD(dds3PadMap->max_length))
    goto LABEL_91;
LABEL_22:
  v13 = dds3PadMap->m_Items[0];
  dds3LightEditorDefWork->padSrc = v13->m_Items[0];
  v7 = wrk;
LABEL_24:
  v14 = dds3PadMap;
  if (!LODWORD(v14->max_length))
    goto LABEL_88;
LABEL_27:
  v15 = v14->m_Items[0];
  v7->padSrc = v15->m_Items[0];
  if (id->workdata)
  {
    p_fld_player_lights = &fld_player_lights;
  }
  else
  {
    p_fld_player_lights = &dds3DirLights;
  }
  wrk->lightSrc = *p_fld_player_lights;
  v19 = wrk;
  if (id->workdata)
  {
    p_x = &fld_player_ambient.x;
    p_y = &fld_player_ambient.y;
    p_z = &fld_player_ambient.z;
    p_w = &fld_player_ambient.w;
  }
  else
  {
    p_x = &dds3Ambient.x;
    p_y = &dds3Ambient.y;
    p_z = &dds3Ambient.z;
    p_w = &dds3Ambient.w;
  }
  v28 = *p_z;
  v29 = *p_y;
  v30 = *p_w;
  wrk->ambientSrc.x = *p_x;
  v19->ambientSrc.y = v29;
  v19->ambientSrc.z = v28;
  v19->ambientSrc.w = v30;
  padSrc = wrk->padSrc;
  max_length = padSrc->max_length;
  if (!wrk->mode)
  {
    if (padSrc->m_Items[13] < 0)
    {
      fog_all_off = 1.0 - fog_all_off;
    }
    v43 = wrk;
    v44 = wrk->padSrc;
    if (v44->m_Items[7] < 0)
    {
      cursor = wrk->cursor;
      if (cursor >= curmax)
      {
        v43->cursor = 0;
        goto LABEL_133;
      }
      LOWORD(v60) = v43->cursor + 1;
    }
    else
    {
      v46 = wrk->padSrc;
      if ((v46->m_Items[7] & 2) != 0)
      {
        v72 = wrk->cursor;
        if (v72 < curmax)
          ++wrk->cursor;
        goto LABEL_133;
      }
      v48 = wrk->padSrc;
      if ((v48->m_Items[6] & 0x80000000) == 0)
      {
        v50 = wrk->padSrc;
        if ((v50->m_Items[6] & 2) == 0)
        {
          v52 = wrk->padSrc;
          if ((v52->m_Items[1] & 0x80000000) == 0)
            goto LABEL_134;
          wrk->mode = 1;
          goto LABEL_133;
        }
        v83 = wrk->cursor;
        v77 = __OFSUB__(v83, 1);
        v60 = v83 - 1;
        if (v60 < 0 == v77)
          goto LABEL_132;
LABEL_133:
        wrk->cursorTimer = 0;
        goto LABEL_134;
      }
      v76 = wrk->cursor;
      v77 = __OFSUB__(v76, 1);
      v60 = v76 - 1;
      if (v60 < 0 != v77)
      {
        LOWORD(v60) = curmax;
      }
    }
LABEL_132:
    v43->cursor = v60;
    goto LABEL_133;
  }
  if ((padSrc->m_Items[1] & 0x80000000) == 0)
  {
    v34 = wrk->padSrc;
    if ((v34->m_Items[3] & 0x80000000) == 0)
    {
      v36 = wrk;
      v37 = wrk->cursor;
      if (v37 <= 11)
      {
        lightSrc = wrk->lightSrc;
        v62 = v37 >> 2;
        v63 = wrk->cursor >> 2;
        v65 = lightSrc->m_Items[v63];
        if (!v65)
          goto LABEL_134;
        v66 = wrk->cursor & 3;
        if (v66 == 3)
        {
          v67 = v65[8];
          v68 = v65[9];
          v70 = v65[10];
          v69 = v65[11];
          v261.x = v67;
          v261.y = v68;
          v261.z = v70;
          v261.w = v69;
          dds3LightEditorAngleEdit(&wrk, v261, v4);
          goto LABEL_134;
        }
        if (v66 != 2)
        {
          if (v66 == 1)
          {
            v212 = wrk->lightSrc;
            v213 = v212->m_Items[v63];
            y = wrk->lightSrc->m_Items[v63]->color.y;
            v215 = wrk->padSrc;
            v213->color.y = dds3DebugFloatEditEx(y, 0.0, 2.0, 0.1, 0.01, v215);
          }
          else if ((wrk->cursor & 3) == 0)
          {
            v79 = wrk->lightSrc;
            v80 = v79->m_Items[v63];
            x = wrk->lightSrc->m_Items[v63]->color.x;
            v82 = wrk->padSrc;
            v80->color.x = dds3DebugFloatEditEx(x, 0.0, 2.0, 0.1, 0.01, v82);
          }
          goto LABEL_134;
        }
        v211 = wrk->lightSrc;
        v36 = v211->m_Items[v63];
        z = wrk->lightSrc->m_Items[v63]->color.z;
        v74 = wrk->padSrc;
          goto LABEL_326;
      }
      else
      {
        if (v37 > 14)
        {
          switch (wrk->cursor)
          {
            case 0xF:
              v40 = v36->padSrc;
              ToonType = dds3DebugFloatEditEx(ToonType, 0.0, 32.0, 1.0, 1.0, v40);
              break;
            case 0x10:
              v218 = v36->padSrc;
              ToonTypeStart = dds3DebugFloatEditEx(ToonTypeStart, 0.0, 1.0, 0.1, 0.01, v218);
              break;
            case 0x11:
              v221 = v36->padSrc;
              ToonTypeDiv = dds3DebugFloatEditEx(ToonTypeDiv, 0.0, 16.0, 0.1, 0.01, v221);
              break;
            case 0x12:
              v224 = v36->padSrc;
              Adj_ColorR = dds3DebugFloatEditEx(Adj_ColorR, 0.0, 1.0, 0.1, 0.01, v224);
              break;
            case 0x13:
              v227 = v36->padSrc;
              Adj_ColorG = dds3DebugFloatEditEx(Adj_ColorG, 0.0, 1.0, 0.1, 0.01, v227);
              break;
            case 0x14:
              v230 = v36->padSrc;
              Adj_ColorB = dds3DebugFloatEditEx(Adj_ColorB, 0.0, 1.0, 0.1, 0.01, v230);
              break;
            default:
              goto LABEL_134;
          }
          goto LABEL_134;
        }
        if (v37 == 14)
        {
          v207 = wrk->ambientSrc.z;
          v208 = wrk->padSrc;
          wrk->ambientSrc.z = dds3DebugFloatEditEx(v207, 0.0, 2.0, 0.1, 0.01, v208);
          goto LABEL_134;
        }
        if (v37 == 13)
        {
          v209 = wrk->ambientSrc.y;
          v210 = wrk->padSrc;
          wrk->ambientSrc.y = dds3DebugFloatEditEx(v209, 0.0, 2.0, 0.1, 0.01, v210);
          goto LABEL_134;
        }
        z = wrk->ambientSrc.x;
        v74 = wrk->padSrc;
          goto LABEL_326;
      }
LABEL_326:
      v36->ambientSrc.x = dds3DebugFloatEditEx(z, 0.0, 2.0, 0.1, 0.01, v74);
      goto LABEL_134;
    }
  }
  wrk->mode = 0;
LABEL_134:
  v84 = wrk;
  cursorTimer = wrk->cursorTimer;
  if (cursorTimer == 29)
    v86 = 0;
  else
    v86 = cursorTimer + 1;
  wrk->cursorTimer = v86;
  if (v84->mode)
    v88 = 4;
  else
    v88 = 2;
  v89 = 4;
  v90 = &"\n";
  v91 = &"F2";
  v92 = 0;
  do
  {
    while (1)
    {
      v93 = v88;
      v94 = v91;
      v95 = v89 - 4;
      v97 = v92;
      v99 = *(&staticStrTbl->obj.klass + v89);
      v100 = *(v99 + 16);
      v101 = *(v99 + 20);
      v102 = *(v99 + 24);
      v103 = v90;
      v105 = Concat_5224608(*(v99 + 32), *v90, 0);
      v242 = btlDevPrintf(v100, v101, 16711808, v102, v105, 0);
      btlDrawTagLink(&bsetText, v242, 0);
      v106 = wrk->lightSrc;
      v108 = *(&v106->obj.klass + v89);
      v91 = v94;
      v90 = v103;
      v92 = v97;
      if (!v108)
        break;
      SDF_VU0__LOADVECTOR(*(v108 + 32), 0);
      LODWORD(v237) = *(v108 + 16);
      HIDWORD(v236) = *(v108 + 20);
      LODWORD(v236) = *(v108 + 24);
      HIDWORD(v235) = *(v108 + 32);
      LODWORD(v235) = *(v108 + 36);
      v234 = *(v108 + 40);
      v88 = v93;
      if (v97 == wrk->cursor)
        v110 = v93;
      else
        v110 = 0;
      v111 = sub_4FDC70(&v237, *v91);
      v113 = Concat_5221536("R:", v111, *v103);
      v243 = btlDevPrintf(0, 0, 0, v110, v113, 0);
      btlDrawTagLink(&bsetText, v243, 0);
      if (v97 + 1 == wrk->cursor)
        v115 = v93;
      else
        v115 = 0;
      v116 = sub_4FDC70(&v236 + 1, *v91);
      v118 = Concat_5221536("G:", v116, *v103);
      v244 = btlDevPrintf(0, 0, 0, v115, v118, 0);
      btlDrawTagLink(&bsetText, v244, 0);
      if (v97 + 2 == wrk->cursor)
        v120 = v93;
      else
        v120 = 0;
      v121 = sub_4FDC70(&v236, *v91);
      v123 = Concat_5221536("B:", v121, *v103);
      v245 = btlDevPrintf(0, 0, 0, v120, v123, 0);
      btlDrawTagLink(&bsetText, v245, 0);
      if (v97 + 3 == wrk->cursor)
        v125 = v93;
      else
        v125 = 0;
      v126 = sub_4FDC70(&v235 + 1, *v91);
      v128 = Concat_5221536("      ", v126, *v103);
      v246 = btlDevPrintf(0, 0, 0, v125, v128, 0);
      btlDrawTagLink(&bsetText, v246, 0);
      v129 = sub_4FDC70(&v235, *v91);
      v130 = Concat_5221536("      ", v129, *v103);
      v247 = btlDevPrintf(0, 0, 0, v125, v130, 0);
      btlDrawTagLink(&bsetText, v247, 0);
      v131 = sub_4FDC70(&v234, *v91);
      v132 = Concat_5221536("      ", v131, *v103);
      v248 = btlDevPrintf(0, 0, 0, v125, v132, 0);
      btlDrawTagLink(&bsetText, v248, 0);
      v92 = v97 + 4;
        goto LABEL_196;
LABEL_192:
        goto LABEL_196;
      if (++v89 == 7)
        goto LABEL_197;
    }
    v241[0] = 0;
    v241[1] = 0;
    sub_854690(v241, 0.0, 0.0, 0.0, 0.0);
    v88 = v93;
      goto LABEL_192;
LABEL_196:
    ++v89;
  }
  while (v89 != 7);
LABEL_197:
  v133 = staticStrTbl;
  v134 = v92;
  v136 = v133->m_Items[3];
  v137 = v136->x;
  v138 = v136->y;
  attr = v136->attr;
  v141 = Concat_5224608(v136->str, *v103);
  v249 = btlDevPrintf(v137, v138, 16711808, attr, v141, 0);
  btlDrawTagLink(&bsetText, v249, 0);
  HIDWORD(v238) = LODWORD(wrk->ambientSrc.x);
  *&v238 = wrk->ambientSrc.y;
  HIDWORD(v237) = LODWORD(wrk->ambientSrc.z);
  if (v134 == wrk->cursor)
    v143 = v88;
  else
    v143 = 0;
  v144 = sub_4FDC70(&v238 + 1, *v91);
  v146 = Concat_5221536("R:", v144, *v103);
  v250 = btlDevPrintf(0, 0, 0, v143, v146, 0);
  btlDrawTagLink(&bsetText, v250, 0);
  if (v134 + 1 == wrk->cursor)
    v148 = v88;
  else
    v148 = 0;
  v149 = sub_4FDC70(&v238, *v91);
  v151 = Concat_5221536("G:", v149, *v103);
  v251 = btlDevPrintf(0, 0, 0, v148, v151, 0);
  btlDrawTagLink(&bsetText, v251, 0);
  if (v134 + 2 == wrk->cursor)
    v153 = v88;
  else
    v153 = 0;
  v154 = sub_4FDC70(&v237 + 1, *v91);
  v156 = Concat_5221536("B:", v154, *v103);
  v252 = btlDevPrintf(0, 0, 0, v153, v156, 0);
  btlDrawTagLink(&bsetText, v252, 0);
  v253 = btlDevPrintf(0, 0, 0, 0, *v103, 0);
  btlDrawTagLink(&bsetText, v253, 0);
  if (v134 + 3 == wrk->cursor)
    v158 = v88;
  else
    v158 = 0;
  v160 = sub_4FDC70(&ToonType, *v91);
  v162 = Concat_5221536("Toon Type  :", v160, *v103);
  v254 = btlDevPrintf(0, 0, 0, v158, v162, 0);
  btlDrawTagLink(&bsetText, v254, 0);
  if (v134 + 4 == wrk->cursor)
    v164 = v88;
  else
    v164 = 0;
  else
  {
    {
LABEL_250:
    }
  }
  v166 = sub_4FDC70(&ToonTypeStart, *v91);
  v168 = Concat_5221536("Toon StartX:", v166, *v103);
  v255 = btlDevPrintf(0, 0, 0, v164, v168, 0);
  btlDrawTagLink(&bsetText, v255, 0);
  if (v134 + 5 == wrk->cursor)
    v170 = v88;
  else
    v170 = 0;
  else
  {
    {
LABEL_262:
    }
  }
  v172 = sub_4FDC70(&ToonTypeDiv, *v91);
  v174 = Concat_5221536("Toon Xdiv  :", v172, *v103);
  v256 = btlDevPrintf(0, 0, 0, v170, v174, 0);
  btlDrawTagLink(&bsetText, v256, 0);
  v257 = btlDevPrintf(0, 0, 0, 0, *v103, 0);
  btlDrawTagLink(&bsetText, v257, 0);
  if (v134 + 6 == wrk->cursor)
    v176 = v88;
  else
    v176 = 0;
  else
  {
    {
LABEL_274:
    }
  }
  v178 = sub_4FDC70(&Adj_ColorR, *v91);
  v180 = Concat_5221536("Adjust R  :", v178, *v103);
  v258 = btlDevPrintf(0, 0, 0, v176, v180, 0);
  btlDrawTagLink(&bsetText, v258, 0);
  if (v134 + 7 == wrk->cursor)
    v182 = v88;
  else
    v182 = 0;
  else
  {
    {
LABEL_286:
    }
  }
  v184 = sub_4FDC70(&Adj_ColorG, *v91);
  v186 = Concat_5221536("Adjust G  :", v184, *v103);
  v259 = btlDevPrintf(0, 0, 0, v182, v186, 0);
  btlDrawTagLink(&bsetText, v259, 0);
  if (v134 + 8 == wrk->cursor)
    v188 = v88;
  else
    v188 = 0;
  else
  {
    {
LABEL_298:
    }
  }
  v190 = sub_4FDC70(&Adj_ColorB, *v91);
  v192 = Concat_5221536("Adjust B  :", v190, *v103);
  v260 = btlDevPrintf(0, 0, 0, v188, v192, 0);
  btlDrawTagLink(&bsetText, v260, 0);
  SetBtlMenuObj(0);
  v194 = wrk;
  v195 = wrk->lightSrc;
  if (id->workdata)
  {
    fld_player_lights = v195;
    v197 = *&v194->ambientSrc.x;
    v200 = v194->ambientSrc.z;
    w = v194->ambientSrc.w;
    *&fld_player_ambient.x = v197;
    v201 = &fld_player_ambient.w;
    fld_player_ambient.z = v200;
  }
  else
  {
    dds3DirLights = v195;
    v203 = *&v194->ambientSrc.x;
    v204 = v194->ambientSrc.z;
    w = v194->ambientSrc.w;
    *&dds3Ambient.x = v203;
    dds3Ambient.z = v204;
    v201 = &dds3Ambient.w;
  }
  *v201 = w;
  return 0;
}
