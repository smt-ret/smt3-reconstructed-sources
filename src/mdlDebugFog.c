#include "types.h"

typedef struct bDrawText bDrawText;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct mdlDebugFog_dds3FogEditorStrTable_t mdlDebugFog_dds3FogEditorStrTable_t;
typedef struct mdlDebugFog_dds3FogEditorWork_t mdlDebugFog_dds3FogEditorWork_t;
typedef struct mdlDebugFog_fogControlValueTable_t mdlDebugFog_fogControlValueTable_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;

struct mdlDebugFog_dds3FogEditorWork_t {
    u8 *padSrc;
    u8 mode;
    u8 cursorTimer;
    s16 cursor;
    f32 valuePtr[8];
    f32 min[8];
    f32 max[8];
    sdfDrawTag_t *drawTag;
};

struct mdlDebugFog_dds3FogEditorStrTable_t {
    u16 x;
    u16 y;
    u32 attr;
    char *str;
};

struct mdlDebugFog_fogControlValueTable_t {
    u32 y;
    f32 valuePtr;
    s32 minValue;
    s32 maxValue;
    char *tagStr;
    char *valueFormatStr;
};

static s32 CX__;
static s32 CY__;
static s32 Z__;
static mdlDebugFog_dds3FogEditorWork_t *dds3FogEditorWork;
static bDrawText bsetText;

void PreBtlMenuObj(s32 idx);
sdfVector4_t SDF_VU0__Retdds3ColorItoF(u32 rgba, f32 ratio);
void SetBtlMenuObj(s32 idx);
bDrawText btlDevPrintf(s32 aX, s32 aY, s32 aZ, s32 color, char *aStr, s32 f);
void btlDrawTagLink(bDrawText *setText, bDrawText dt, s32 idx);
f32 dds3FogEditorChangeValue(s32 num);
void initBtlMenuObj(s32 x, s32 y, s32 w, s32 h, s32 idx);

// 0xdf7c50
f32 dds3FogEditorChangeValue(s32 num) {
  struct System_Single_array *valuePtr;
  s64 v5;
  f32 v7;
  f32 v8;
  f32 v9;
  struct mdlDebugFog_dds3FogEditorWork_t_o *dds3FogEditorWork;
  struct System_Single_array *min;
  s64 v14;
  struct System_Single_array *max;
  f32 v16;
  struct System_Byte_array *padSrc;
  f32 v19;
  struct System_Byte_array *v22;
  struct System_Byte_array *v25;
  struct System_Byte_array *v28;
  struct System_Byte_array *v31;
  struct System_Byte_array *v34;
  struct System_Byte_array *v37;
  struct System_Byte_array *v40;
  f32 result;

  valuePtr = dds3FogEditorWork->valuePtr;
  v5 = num;
  v7 = valuePtr->m_Items[num];
  v8 = 1000.0;
  if (v7 >= 1000.0)
  {
    if (v7 >= 10000.0)
    {
      v9 = 100.0;
        goto LABEL_16;
    }
    else
    {
      v8 = 100.0;
      v9 = 10.0;
        goto LABEL_16;
    }
  }
  else
  {
    v9 = 1.0;
    v8 = 10.0;
      goto LABEL_16;
  }
LABEL_16:
  min = dds3FogEditorWork->min;
  v14 = min + 4 * num;
  max = dds3FogEditorWork->max;
  v16 = *(v14 + 32);
  padSrc = dds3FogEditorWork->padSrc;
  v19 = max->m_Items[v5];
  if (padSrc->m_Items[5] < 0)
  {
    result = *(v14 + 32);
    if (v7 >= v19)
      return result;
    goto LABEL_67;
  }
  v22 = dds3FogEditorWork->padSrc;
  if ((v22->m_Items[5] & 2) != 0)
  {
LABEL_67:
    result = v7 + v8;
LABEL_68:
    if (result > v19)
      return v19;
    return result;
  }
  v25 = dds3FogEditorWork->padSrc;
  if (v25->m_Items[4] < 0)
  {
    result = v19;
    if (v7 <= v16)
      return result;
    goto LABEL_72;
  }
  v28 = dds3FogEditorWork->padSrc;
  if ((v28->m_Items[4] & 2) != 0)
  {
LABEL_72:
    result = v7 - v8;
LABEL_73:
    if (result < v16)
      return v16;
    return result;
  }
  v31 = dds3FogEditorWork->padSrc;
  if (v31->m_Items[7] < 0)
  {
    result = v16;
    if (v7 >= v19)
      return result;
    result = v7 + v9;
    goto LABEL_68;
  }
  v34 = dds3FogEditorWork->padSrc;
  if ((v34->m_Items[7] & 2) == 0)
  {
    v37 = dds3FogEditorWork->padSrc;
    if ((v37->m_Items[6] & 0x80000000) == 0)
    {
      v40 = dds3FogEditorWork->padSrc;
      if ((v40->m_Items[6] & 2) == 0)
        return v7;
      result = v7 - v9;
      if ((v7 - v9) < v16)
        return v19;
      return result;
    }
    result = v19;
    if (v7 <= v16)
      return result;
    result = v7 - v9;
    goto LABEL_73;
  }
  result = v7 + v9;
  if ((v7 + v9) > v19)
    return v16;
  return result;
}

// 0xdf80b0
void *dds3FogEditorProcess(dds3ProcessID_t *aId) {
  struct mdlDebugFog_dds3FogEditorWork_t_o *dds3FogEditorWork;
  struct System_Byte_array_array_array *dds3PadMap;
  System_Byte_array_array *v6;
  struct System_Single_array *valuePtr;
  struct System_Single_array *min;
  struct System_Single_array *max;
  struct System_Single_array *v15;
  struct System_Single_array *v17;
  struct System_Single_array *v19;
  struct System_Single_array *v21;
  struct System_Single_array *v23;
  struct System_Single_array *v25;
  struct System_Single_array *v27;
  struct System_Single_array *v29;
  struct System_Single_array *v31;
  mdlDebugFog_c *v33;
  struct System_Single_array *v34;
  f64 v35;
  f32 v36;
  struct System_Single_array *v38;
  struct System_Single_array *v40;
  struct System_Single_array *v42;
  f64 v43;
  f32 v44;
  struct System_Single_array *v46;
  struct System_Single_array *v48;
  struct System_Single_array *v50;
  f64 v51;
  f32 v52;
  struct System_Single_array *v54;
  struct System_Single_array *v56;
  struct mdlDebugFog_dds3FogEditorWork_t_o *v58;
  s16 v59;
  s32 v60;
  struct mdlDebugFog_dds3FogEditorWork_t_o *v61;
  struct System_Byte_array *padSrc;
  struct System_Byte_array *v65;
  struct mdlDebugFog_dds3FogEditorWork_t_o *v68;
  s64 cursor;
  struct System_Single_array *v70;
  f32 v71;
  s16 v74;
  struct System_Byte_array *v75;
  s32 v77;
  struct System_Byte_array *v78;
  struct System_Byte_array *v80;
  s32 v82;
  struct System_Byte_array *v83;
  struct System_Byte_array *v85;
  s32 v86;
  s32 v88;
  struct mdlDebugFog_dds3FogEditorWork_t_o *v91;
  s32 v92;
  struct System_Single_array *v93;
  System_String_o *v95;
  System_String_o *v97;
  struct mdlDebugFog_dds3FogEditorWork_t_o *v99;
  s32 v100;
  struct System_Single_array *v101;
  System_String_o *v103;
  System_String_o *v105;
  struct mdlDebugFog_dds3FogEditorWork_t_o *v107;
  s32 v108;
  struct System_Single_array *v109;
  System_String_o *v111;
  System_String_o *v113;
  struct mdlDebugFog_dds3FogEditorWork_t_o *v115;
  s32 v116;
  struct System_Single_array *v117;
  System_String_o *v119;
  System_String_o *v121;
  struct mdlDebugFog_dds3FogEditorWork_t_o *v123;
  s32 v124;
  struct System_Single_array *v125;
  System_String_o *v127;
  System_String_o *v129;
  struct mdlDebugFog_dds3FogEditorWork_t_o *v131;
  s32 v132;
  struct System_Single_array *v133;
  System_String_o *v135;
  System_String_o *v137;
  struct mdlDebugFog_dds3FogEditorWork_t_o *v139;
  s32 v140;
  struct System_Single_array *v141;
  System_String_o *v143;
  System_String_o *v145;
  struct mdlDebugFog_dds3FogEditorWork_t_o *v147;
  struct System_Single_array *v148;
  il2cpp_array_size_t max_length;
  f32 v150;
  f32 v152;
  f32 v153;
  f32 v155;
  s32 v156;
  System_String_o *v157;
  System_String_o *v159;
  s32 v161;
  System_String_o *v162;
  System_String_o *v164;
  struct System_Single_array *v168;
  struct System_Single_array *v170;
  struct System_Single_array *v172;
  struct System_Single_array *v174;
  struct System_Single_array *v176;
  u32 v177;
  f32 v178;
  f32 v180;
  f32 v181;
  struct System_Single_array *v182;
  u32 v183;
  f32 v184;
  f32 v185;
  s32 v187;
  f32 v188;
  s32 v189;
  s32 v190;
  s32 v191;
  struct mdlDebugFog_dds3FogEditorWork_t_o *v199;
  s32 v200;
  struct mdlDebugFog_dds3FogEditorWork_t_o *v201;
  s32 v202;
  struct mdlDebugFog_dds3FogEditorWork_t_o *v203;
  s32 v204;
  struct mdlDebugFog_dds3FogEditorWork_t_o *v205;
  s32 v206;
  u64 v209;
  u64 v210[2];
  f32 v211;
  f32 v212;
  bDrawText_o v213;
  bDrawText_o v214;
  bDrawText_o v215;
  bDrawText_o v216;
  bDrawText_o v217;
  bDrawText_o v218;
  bDrawText_o v219;
  bDrawText_o v220;
  bDrawText_o v221;
  bDrawText_o v222;

  v212 = 0.0;
  v211 = 0.0;
  initBtlMenuObj(1380, 0, 540, 800, 0);
  PreBtlMenuObj(0);
  if (!LODWORD(dds3PadMap->max_length))
    goto LABEL_258;
LABEL_12:
  v6 = dds3PadMap->m_Items[0];
  dds3FogEditorWork->padSrc = v6->m_Items[0];
  valuePtr = dds3FogEditorWork->valuePtr;
  valuePtr->m_Items[0] = dds3FogParam->fogMax;
  min = dds3FogEditorWork->min;
  min->m_Items[0] = 0.0;
  max = dds3FogEditorWork->max;
  max->m_Items[0] = 255.0;
  v15 = dds3FogEditorWork->valuePtr;
  v15->m_Items[1] = dds3FogParam->fogNear;
  v17 = dds3FogEditorWork->min;
  v17->m_Items[1] = 0.0;
  v19 = dds3FogEditorWork->max;
  v19->m_Items[1] = 100000000.0;
  v21 = dds3FogEditorWork->valuePtr;
  v21->m_Items[2] = dds3FogParam->fogMin;
  v23 = dds3FogEditorWork->min;
  v23->m_Items[2] = 0.0;
  v25 = dds3FogEditorWork->max;
  v25->m_Items[2] = 255.0;
  v27 = dds3FogEditorWork->valuePtr;
  v27->m_Items[3] = dds3FogParam->fogFar;
  v29 = dds3FogEditorWork->min;
  v29->m_Items[3] = 0.0;
  v31 = dds3FogEditorWork->max;
  v31->m_Items[3] = 100000000.0;
  *&v209 = SDF_VU0__Retdds3ColorItoF(dds3FogParam->color, 128.0).x;
  v34 = dds3FogEditorWork->valuePtr;
  LOBYTE(v209) = dds3FogParam->color;
  v35 = v209;
  v36 = v35;
  v34->m_Items[4] = v36;
  v38 = dds3FogEditorWork->min;
  v38->m_Items[4] = 0.0;
  v40 = dds3FogEditorWork->max;
  v40->m_Items[4] = 255.0;
  v42 = dds3FogEditorWork->valuePtr;
  LOBYTE(v35) = BYTE1(dds3FogParam->color);
  v43 = *&v35;
  v44 = v43;
  v42->m_Items[5] = v44;
  v46 = dds3FogEditorWork->min;
  v46->m_Items[5] = 0.0;
  v48 = dds3FogEditorWork->max;
  v48->m_Items[5] = 255.0;
  v50 = dds3FogEditorWork->valuePtr;
  LOBYTE(v43) = BYTE2(dds3FogParam->color);
  v51 = *&v43;
  v52 = v51;
  v50->m_Items[6] = v52;
  v54 = dds3FogEditorWork->min;
  v54->m_Items[6] = 0.0;
  v56 = dds3FogEditorWork->max;
  v56->m_Items[6] = 255.0;
  ++dds3FogEditorWork->cursorTimer;
  v58 = dds3FogEditorWork;
  if (v58->cursorTimer == 30)
  {
    v58->cursorTimer = 0;
  }
  v59 = *&v33->_2.bitflags1;
  if ((v59 & 0x200) != 0)
  {
    v60 = v59 & 0x200;
    v61 = dds3FogEditorWork;
    if (v61->mode)
    {
LABEL_65:
      else
      {
        padSrc = v61->padSrc;
        if (LODWORD(padSrc->max_length) <= 1)
          goto LABEL_68;
      }
      if (padSrc->m_Items[1] < 0)
        goto LABEL_117;
      v65 = dds3FogEditorWork->padSrc;
      if (v65->m_Items[3] < 0)
      {
LABEL_117:
        dds3FogEditorWork->mode = 0;
        if ((v74 & 0x200) != 0)
          goto LABEL_121;
      }
      else
      {
        v68 = dds3FogEditorWork;
        cursor = v68->cursor;
        v70 = v68->valuePtr;
        v71 = dds3FogEditorChangeValue(v68->cursor);
        v70->m_Items[cursor] = v71;
        if ((v74 & 0x200) != 0)
          goto LABEL_121;
      }
LABEL_116:
      v86 = 0;
      goto LABEL_124;
    }
  }
  else
  {
    v60 = 0;
    v61 = dds3FogEditorWork;
    if (v61->mode)
      goto LABEL_65;
  }
  v75 = v61->padSrc;
  v77 = *&v33->_2.bitflags1 & 0x200;
  if (v75->m_Items[7] < 0)
  {
    v199 = dds3FogEditorWork;
    v200 = v199->cursor;
    if (v200 <= 5)
    {
      v199->cursor = v200 + 1;
      if ((v33->_2.bitflags2 & 2) != 0)
        goto LABEL_328;
    }
    else
    {
      v199->cursor = 0;
      if ((v33->_2.bitflags2 & 2) != 0)
        goto LABEL_328;
    }
    goto LABEL_330;
  }
  v78 = dds3FogEditorWork->padSrc;
  if ((v78->m_Items[7] & 2) != 0)
  {
    v201 = dds3FogEditorWork;
    v202 = v201->cursor;
    if (v202 <= 5)
    {
      v201->cursor = v202 + 1;
      if ((v33->_2.bitflags2 & 2) != 0)
        goto LABEL_328;
      goto LABEL_330;
    }
    goto LABEL_327;
  }
  v80 = dds3FogEditorWork->padSrc;
  v82 = *&v33->_2.bitflags1 & 0x200;
  if (v80->m_Items[6] < 0)
  {
    v203 = dds3FogEditorWork;
    v204 = v203->cursor;
    if (v204 >= 1)
    {
      v203->cursor = v204 - 1;
      if ((v33->_2.bitflags2 & 2) != 0)
        goto LABEL_328;
      goto LABEL_330;
    }
    v203->cursor = 6;
LABEL_327:
    if ((v33->_2.bitflags2 & 2) == 0)
      goto LABEL_330;
    goto LABEL_328;
  }
  v83 = dds3FogEditorWork->padSrc;
  if ((v83->m_Items[6] & 2) != 0)
  {
    v205 = dds3FogEditorWork;
    v206 = v205->cursor;
    if (v206 >= 1)
    {
      v205->cursor = v206 - 1;
      if ((v33->_2.bitflags2 & 2) != 0)
        goto LABEL_328;
LABEL_330:
      dds3FogEditorWork->cursorTimer = 0;
      if ((v74 & 0x200) == 0)
        goto LABEL_116;
      goto LABEL_121;
    }
    goto LABEL_327;
  }
  v85 = dds3FogEditorWork->padSrc;
  if (v85->m_Items[1] < 0)
  {
    dds3FogEditorWork->mode = 1;
    if ((v33->_2.bitflags2 & 2) == 0)
      goto LABEL_330;
LABEL_328:
    goto LABEL_330;
  }
  if ((v74 & 0x200) == 0)
    goto LABEL_116;
LABEL_121:
  v86 = v74 & 0x200;
LABEL_124:
  if (dds3FogEditorWork->mode)
    v88 = 4;
  else
    v88 = 2;
  else
  {
      goto LABEL_133;
  }
LABEL_133:
  v213 = btlDevPrintf(0, 0, 0, 0, "FOG:\n", 0);
  btlDrawTagLink(&bsetText, v213, 0);
  v91 = dds3FogEditorWork;
  if (v91->cursor)
    v92 = 0;
  else
    v92 = v88;
  else
  {
    v93 = v91->valuePtr;
    if (!LODWORD(v93->max_length))
      goto LABEL_139;
  }
  v95 = sub_4FDC70(v93->m_Items, "F0");
  v97 = Concat_5221536("MAX    :", v95, "\n");
  v214 = btlDevPrintf(0, 0, 0, v92, v97, 0);
  btlDrawTagLink(&bsetText, v214, 0);
  v99 = dds3FogEditorWork;
  if (v99->cursor == 1)
    v100 = v88;
  else
    v100 = 0;
  else
  {
    v101 = v99->valuePtr;
    if (LODWORD(v101->max_length) <= 1)
      goto LABEL_149;
  }
  v103 = sub_4FDC70(&v101->m_Items[1], "F0");
  v105 = Concat_5221536("NEAR   :", v103, "\n");
  v215 = btlDevPrintf(0, 0, 0, v100, v105, 0);
  btlDrawTagLink(&bsetText, v215, 0);
  v107 = dds3FogEditorWork;
  if (v107->cursor == 2)
    v108 = v88;
  else
    v108 = 0;
  else
  {
    v109 = v107->valuePtr;
    if (LODWORD(v109->max_length) <= 2)
      goto LABEL_159;
  }
  v111 = sub_4FDC70(&v109->m_Items[2], "F0");
  v113 = Concat_5221536("MIN    :", v111, "\n");
  v216 = btlDevPrintf(0, 0, 0, v108, v113, 0);
  btlDrawTagLink(&bsetText, v216, 0);
  v115 = dds3FogEditorWork;
  if (v115->cursor == 3)
    v116 = v88;
  else
    v116 = 0;
  else
  {
    v117 = v115->valuePtr;
    if (LODWORD(v117->max_length) <= 3)
      goto LABEL_169;
  }
  v119 = sub_4FDC70(&v117->m_Items[3], "F0");
  v121 = Concat_5221536("FAR    :", v119, "\n");
  v217 = btlDevPrintf(0, 0, 0, v116, v121, 0);
  btlDrawTagLink(&bsetText, v217, 0);
  v123 = dds3FogEditorWork;
  if (v123->cursor == 4)
    v124 = v88;
  else
    v124 = 0;
  else
  {
    v125 = v123->valuePtr;
    if (LODWORD(v125->max_length) <= 4)
      goto LABEL_179;
  }
  v127 = sub_4FDC70(&v125->m_Items[4], "F0");
  v129 = Concat_5221536("R      :", v127, "\n");
  v218 = btlDevPrintf(0, 0, 0, v124, v129, 0);
  btlDrawTagLink(&bsetText, v218, 0);
  v131 = dds3FogEditorWork;
  if (v131->cursor == 5)
    v132 = v88;
  else
    v132 = 0;
  else
  {
    v133 = v131->valuePtr;
    if (LODWORD(v133->max_length) <= 5)
      goto LABEL_189;
  }
  v135 = sub_4FDC70(&v133->m_Items[5], "F0");
  v137 = Concat_5221536("G      :", v135, "\n");
  v219 = btlDevPrintf(0, 0, 0, v132, v137, 0);
  btlDrawTagLink(&bsetText, v219, 0);
  v139 = dds3FogEditorWork;
  if (v139->cursor == 6)
    v140 = v88;
  else
    v140 = 0;
  else
  {
    v141 = v139->valuePtr;
    if (LODWORD(v141->max_length) <= 6)
      goto LABEL_199;
  }
  v143 = sub_4FDC70(&v141->m_Items[6], "F0");
  v145 = Concat_5221536("B      :", v143, "\n");
  v220 = btlDevPrintf(0, 0, 0, v140, v145, 0);
  btlDrawTagLink(&bsetText, v220, 0);
  v147 = dds3FogEditorWork;
  v148 = v147->valuePtr;
  max_length = v148->max_length;
  v150 = v148->m_Items[2];
  v152 = v148->m_Items[0];
  v153 = v148->m_Items[1];
  v155 = v148->m_Items[3];
  v211 = ((v152 - v150) * (v153 * v155)) / (v155 - v153);
  v212 = ((v150 + v152) + (((v150 - v152) * (v153 + v155)) / (v155 - v153))) * 0.5;
  if (v147->cursor == 7)
    v156 = v88;
  else
    v156 = 0;
  v157 = sub_4FDC70(&v212, "F4");
  v159 = Concat_5221536("param2:", v157, "\n");
  v221 = btlDevPrintf(0, 0, 0, v156, v159, 0);
  btlDrawTagLink(&bsetText, v221, 0);
  if (dds3FogEditorWork->cursor == 8)
    v161 = v88;
  else
    v161 = 0;
  v162 = sub_4FDC70(&v211, "F4");
  v164 = Concat_5221536("param3:", v162, "\n");
  v222 = btlDevPrintf(0, 0, 0, v161, v164, 0);
  btlDrawTagLink(&bsetText, v222, 0);
  SetBtlMenuObj(0);
  v168 = dds3FogEditorWork->valuePtr;
  dds3FogParam->fogMax = v168->m_Items[0];
  v170 = dds3FogEditorWork->valuePtr;
  dds3FogParam->fogNear = v170->m_Items[1];
  v172 = dds3FogEditorWork->valuePtr;
  dds3FogParam->fogMin = v172->m_Items[2];
  v174 = dds3FogEditorWork->valuePtr;
  dds3FogParam->fogFar = v174->m_Items[3];
  v176 = dds3FogEditorWork->valuePtr;
  v177 = v176->max_length;
  v178 = v176->m_Items[5];
  v180 = v176->m_Items[6];
  v181 = v176->m_Items[4] / 255.0;
  v210[0] = 0;
  v210[1] = 0;
  sub_854690(v210, v181, v178 / 255.0, v180 / 255.0, 1.0);
  v182 = dds3FogEditorWork->valuePtr;
  v183 = v182->max_length;
  v184 = v182->m_Items[4];
  v185 = v182->m_Items[5];
  v187 = v184;
  if (v184 >= 0.0)
    v187 = v184;
  v188 = v182->m_Items[6];
  v189 = v185;
  if (v185 < 0.0)
    v189 = v185;
  v190 = v187 | (v189 << 8);
  if (v188 >= 0.0)
    v191 = v188;
  else
    v191 = v188;
  dds3FogParam->color = v190 | (v191 << 16);
  return 0;
}
