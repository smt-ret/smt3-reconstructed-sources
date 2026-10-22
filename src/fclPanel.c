#include "types.h"

typedef struct fclPanelMoverFunc_t fclPanelMoverFunc_t;
typedef struct fclPanelMover_t fclPanelMover_t;
typedef struct fclPanel_t fclPanel_t;
typedef struct fclSprTblArry_t fclSprTblArry_t;
typedef struct fclSprite_t fclSprite_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

s32 CMP_X(s32 a);
s32 CMP_XM(s32 a);
s32 CMP_Y(s32 b);
s32 SDF_GS_SET_ALPHA(s32 a, s32 b, s32 c, s32 d, s32 fix);
u64 SDF_GS_SET_TEST(u8 ate, u8 atst, u8 aref, u8 afail, u8 date, u8 datm, u8 zte, u32 ztst);
s32 fclDefaultMoverCoreFunc(s32 MaxOfs, s32 Rate);
void fclDrawArrowCursor(fclPanel_t *pPanel, u32 Z, s32 OfsX, u32 OtNo);
void fclDrawPanelGradDouble(fclPanel_t *pPanel, u32 Color, u32 OtNo);
void fclDrawPanelType0Grad(fclPanel_t *pPanel, u32 OtNo);
void fclDrawPanelType3BackGrad(fclPanel_t *pPanel, u32 OtNo);
void fclDrawPanelType3Base(fclPanel_t *pPanel, u32 OtNo);
void fclDrawPanelType3Line(fclPanel_t *pPanel, u32 OtNo);
void fclDrawParts(s32 X, s32 Y, u32 Z, u32 **pCol, u8 TblNo, u16 PartsNo, sdfTexHandle_t **pTexHandle, fclSprTblArry_t *pSprTblArry, u32 OtNo);
void fclDrawPartsEx3(s32 X, s32 Y, u32 Z, u8 FilterFlag, u32 **pCol, u8 TblNo, u16 PartsNo, sdfTexHandle_t **pTexHandle, fclSprTblArry_t **pSprTblArry, u32 OtNo);
void fclDrawPartsEx6(s32 X, s32 Y, u32 Z, s32 W, s32 H, u8 FilterFlag, u32 **pCol, u8 TblNo, u16 PartsNo, sdfTexHandle_t **pTexHandle, fclSprTblArry_t **pSprTblArry, u32 OtNo);
void fclDrawSpriteCore(s32 X, s32 Y, s32 W, s32 H, u32 **pCol, fclSprite_t *pSprite, u8 FlipFlag, u8 AlphaFlag, u8 FilterFlag, u32 OtNo);
void fclInitPanel(fclPanel_t *pPanel, s32 X, s32 Y, u32 Z, s32 W, s32 H, u32 Col, s8 Type, s8 Spd);
void fclSetSprite(fclSprite_t *pSprite, s32 Xsize, s32 Ysize, s32 Z, s32 U1, s32 V1, s32 U2, s32 V2, u32 Col, sdfTexHandle_t *TexHandle);
f32 sdfSqrt(f32 aValue);

// 0x13c9710
void fclClearPanelTimer(fclPanel_t *panel) {
  panel->Timer = 0;
}

// 0x13cd910
fclPanel_t *fclCreatePanel(s32 X, s32 Y, u32 Z, s32 W, s32 H, u32 Col, s8 Type, s8 Spd) {
  u64 *v17;

  v17 = Allocate(fclPanel_t);
  fclPanel_t___ctor(v17);
  fclInitPanel(v17, X, Y, Z, W, H, Col, Type, Spd);
  return v17;
}

// 0x13c9720
s32 fclDefaultMoverCoreFunc(s32 MaxOfs, s32 Rate) {
  s32 v6;
  s32 v7;

  v6 = CMP_XM(MaxOfs);
  v7 = sdfSqrt(v6) * Rate;
  return v7 / 512 * (v7 / 512);
}

// 0x13c97f0
void fclDefaultMoverFunc(void *pMover) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s32 klass_high;
  u64 v10[3];

  if (pMover)
  {
    klass = pMover->klass;
    if (pMover->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclPanelMover_t)
    {
      sub_8FC2C0(klass->_1.element_class, fclPanelMover_t, v10);
      if ((v10[0] & 1) != 0)
        v6 = v10[2];
      else
        v6 = v10 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  klass_high = HIDWORD(pMover[2].klass);
  HIDWORD(pMover[1].klass) = fclDefaultMoverCoreFunc(HIDWORD(pMover[1].monitor), klass_high);
  LODWORD(pMover[1].monitor) = fclDefaultMoverCoreFunc(pMover[2].klass, klass_high);
}

// 0x13cd9e0
s8 fclDestroyPanel(fclPanel_t *pPanel) {
  return 1;
}

// 0x13ca1b0
void fclDrawArrowCursor(fclPanel_t *pPanel, u32 Z, s32 OfsX, u32 OtNo) {
  u32 *v8;
  u64 *v9;
  u32 *v10;
  System_UInt32_array *v11;
  u32 *v12;
  u32 v14;
  u32 *v15;
  u32 v17;
  s32 Timer;
  s32 v20;
  u32 v21;
  s32 v24;
  u32 Flag;
  s32 v26;
  u32 *v27;
  u32 v36;
  il2cpp_array_size_t max_length;
  s32 v40;
  s32 v41;
  s32 Y;
  s32 v43;
  s32 v46;
  s32 v49;
  sdfTexHandle_t_array *cmpTex;
  fclSprTblArry_t_array *cmpSprTblArry;
  u32 v53;
  il2cpp_array_size_t v54;
  s32 v56;
  s32 v58;
  s32 v59;
  s32 v60;
  s32 v62;
  s32 X;
  s32 v76;
  u32 v78;
  u32 *v79;
  u32 *v80;

  v8 = NewSpecific(s32, 2u);
  v9 = NewSpecific(s32, 2u);
  v10 = NewSpecific(s32, 2u);
  v11 = NewSpecific(uint, 4u);
  v12 = NewSpecific(uint, 2u);
  v14 = v8[6];
  v15 = v12;
  v8[8] = 6;
  v8[9] = 8;
  *(v9 + 9) = 5;
  *(v9 + 8) = 5;
  v17 = v10[6];
  v10[8] = 28;
  v79 = v10;
  v80 = v9;
  v10[9] = 41;
  Timer = pPanel->Timer;
  if (Timer >= 257)
    v20 = 512 - Timer;
  else
    v20 = pPanel->Timer;
  v21 = v12[6];
  v12[8] = -2139062144;
  v12[9] = -2139062144;
  v24 = (v20 / 4 + 64);
  Flag = pPanel->Flag;
  if ((Flag & 1) == 0)
  {
    v26 = 0;
    v27 = v79;
    if ((Flag & 2) != 0)
      goto LABEL_19;
LABEL_38:
    if (v26)
    {
      if (!v12[6])
        goto LABEL_84;
    }
    else
    {
      pPanel->Timer = 0;
      if (!v12[6])
        goto LABEL_84;
    }
    goto LABEL_40;
  }
  ++v8[8];
  *(v9 + 8) = -1;
  v79[8] = 21;
  v12[8] = v24 | 0x80808000;
  v26 = 1;
  v27 = v79;
  if ((pPanel->Flag & 2) == 0)
    goto LABEL_38;
LABEL_19:
  ++v8[9];
  v80[9] = -1;
  v27[9] = 48;
  v12[9] = v24 | 0x80808000;
  if (!v12[6])
  {
LABEL_84:
  }
LABEL_40:
  v36 = v12[8];
  max_length = v11->max_length;
  v11->m_Items[0] = v36;
  v11->m_Items[1] = v36;
  v11->m_Items[2] = v11->m_Items[0];
  v78 = Z;
  v11->m_Items[3] = v11->m_Items[0];
  X = pPanel->X;
  v40 = v80[8];
  v76 = OfsX;
  v41 = CMP_X(v40 + OfsX);
  Y = pPanel->Y;
  v43 = v41;
  v46 = CMP_Y(v27[8]);
  v49 = v8[8];
  fclDrawParts(v43 + X, v46 + Y, v78, v11, 0xAu, v49, cmpTex, cmpSprTblArry, OtNo);
  v53 = v15[9];
  v54 = v11->max_length;
  v11->m_Items[0] = v53;
  v11->m_Items[1] = v53;
  v11->m_Items[2] = v11->m_Items[0];
  v11->m_Items[3] = v11->m_Items[0];
  v56 = pPanel->X;
  v58 = CMP_X(v80[9] + v76);
  v59 = pPanel->Y;
  v60 = v58;
  v62 = CMP_Y(pPanel->H - v79[9]);
  fclDrawParts(v60 + v56, v62 + v59, v78, v11, 0xAu, v8[9], cmpTex, cmpSprTblArry, OtNo);
}

// 0x13cd9f0
void fclDrawPanel(fclPanel_t *pPanel, u32 OtNo) {
  u64 v6;
  u64 v7;

  v6 = SDF_GS_SET_TEST(1u, 0, 0, 3u, 0, 0, 1u, 2u);
  cmpSetRegTEST(v6, OtNo);
  fclDrawPanelFunc_t__Invoke(pPanel->DrawFunc, pPanel, OtNo);
  v7 = SDF_GS_SET_TEST(1u, 5u, 1u, 1u, 0, 0, 1u, 2u);
  cmpSetRegTEST(v7, OtNo);
}

// 0x13caa30
void fclDrawPanelGrad(fclPanel_t *pPanel, u32 Color, u32 Type, u32 OtNo) {
  u64 v10;
  fclPanel_t_o *v13;
  u32 v14;
  u64 v16;

  v10 = SDF_GS_SET_TEST(1u, 0, 0, 3u, 0, 0, 1u, 1u);
  cmpSetRegTEST(v10, OtNo);
  if (Type == 1)
  {
    v13 = pPanel;
    v14 = Color;
  }
  else
  {
    v14 = 337456460;
    v13 = pPanel;
  }
  fclDrawPanelGradDouble(v13, v14, OtNo);
  v16 = SDF_GS_SET_TEST(1u, 5u, 1u, 1u, 0, 0, 1u, 2u);
  cmpSetRegTEST(v16, OtNo);
}

// 0x13c9a00
void fclDrawPanelGradDouble(fclPanel_t *pPanel, u32 Color, u32 OtNo) {
  u64 *v7;
  s64 *v8;
  s64 *v9;
  s64 *v11;
  s64 *v12;
  u64 *v14;
  u64 v16;
  u32 v18;
  s64 v19;
  s32 X;
  s32 W;
  s32 v22;
  s64 v23;
  s64 v24;
  s32 v25;
  s32 v26;
  s64 v29;
  s32 Y;
  s32 v31;
  s64 v34;
  s32 v35;
  s32 v36;
  s32 v37;
  s64 v40;
  u32 v41;
  s64 v43;
  s64 v45;
  s32 v46;
  s32 v47;
  s64 v48;
  s32 v49;
  s32 v50;
  s64 v53;
  s32 v54;
  s32 v55;
  s64 v58;
  s64 v61;
  s32 v62;
  s32 v63;
  u32 v64;
  u64 v66;

  v7 = NewSpecific(int__, 2u);
  v8 = NewSpecific(s32, 3u);
  v9 = v8;
  v7[4] = v9;
  v11 = NewSpecific(s32, 3u);
  v12 = v11;
  v7[5] = v12;
  v14 = NewSpecific(uint, 3u);
  v16 = SDF_GS_SET_ALPHA(0, 2u, 0, 1u, 0);
  cmpSetRegALPHA(v16, OtNo);
  v18 = *(v14 + 6);
  *(v14 + 8) = Color;
  *(v14 + 9) = Color;
  *(v14 + 10) = Color;
  v19 = v7[4];
  X = pPanel->X;
  W = pPanel->W;
  v22 = CMP_X(W) + X;
  *(v19 + 32) = v22;
  v23 = v7[5];
  *(v23 + 32) = pPanel->Y;
  v24 = v7[4];
  v25 = pPanel->X;
  v26 = CMP_X(pPanel->W) + v25;
  *(v24 + 36) = v26;
  v29 = v7[5];
  Y = pPanel->Y;
  v31 = CMP_Y(80 * pPanel->H / 0x64) + Y;
  *(v29 + 36) = v31;
  v34 = v7[4];
  v35 = pPanel->X;
  v36 = CMP_X(pPanel->W);
  v37 = v36 + v35 - CMP_X(80 * pPanel->H / 0x64);
  *(v34 + 40) = v37;
  v40 = v7[5];
  *(v40 + 40) = pPanel->Y;
  v41 = *(v7 + 6);
  cmpDrawTriangleG(v7[4], v7[5], pPanel->Z, v14, OtNo);
  v43 = v7[4];
  *(v43 + 32) = pPanel->X;
  v45 = v7[5];
  v46 = pPanel->Y;
  v47 = CMP_Y(pPanel->H) + v46;
  *(v45 + 32) = v47;
  v48 = v7[4];
  v49 = pPanel->X;
  v50 = CMP_X(80 * pPanel->H / 0x64) + v49;
  *(v48 + 36) = v50;
  v53 = v7[5];
  v54 = pPanel->Y;
  v55 = CMP_Y(pPanel->H) + v54;
  *(v53 + 36) = v55;
  v58 = v7[4];
  *(v58 + 40) = pPanel->X;
  v61 = v7[5];
  v62 = pPanel->Y;
  v63 = CMP_Y(pPanel->H / 5u) + v62;
  *(v61 + 40) = v63;
  v64 = *(v7 + 6);
  cmpDrawTriangleG(v7[4], v7[5], pPanel->Z, v14, OtNo);
  v66 = SDF_GS_SET_ALPHA(0, 1u, 0, 1u, 0);
  cmpSetRegALPHA(v66, OtNo);
}

// 0x13cb690
void fclDrawPanelType0(void *pPanel, u32 OtNo) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  System_UInt32_array *v10;
  s32 monitor_high;
  u32 v12;
  s64 monitor_low;
  s32 v14;
  u32 v15;
  u64 v17;
  s32 klass_high;
  s32 v20;
  s32 v21;
  s32 v22;
  il2cpp_array_size_t max_length;
  s32 v25;
  u64 v27;
  s32 v28;
  u64 v29;
  s32 v30;
  u64 v31;
  s32 v32;
  u32 monitor;
  u32 v34;
  u32 v35;
  u32 v36;
  s32 v37;
  u64 v44;
  u32 v45;
  u32 v46;
  u32 v47;
  u64 v52;
  s32 v53;
  s32 v54;
  s32 v55;
  il2cpp_array_size_t v56;
  s32 v57;
  s32 v58;
  u64 v61;
  s32 v62;
  u64 v63;
  s32 v64;
  u64 v65;
  s32 v66;
  u32 v67;
  s32 v68;
  u64 v75;
  u64 v76;
  s32 v78;
  u64 v79[3];

  if (pPanel)
  {
    klass = pPanel->klass;
    if (pPanel->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclPanel_t)
    {
      sub_8FC2C0(klass->_1.element_class, fclPanel_t, v79);
      if ((v79[0] & 1) != 0)
        v7 = v79[2];
      else
        v7 = v79 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  v10 = NewSpecific(uint, 4u);
  monitor_high = HIWORD(pPanel[1].monitor);
  v12 = 80 * monitor_high / 0x64u;
  monitor_low = SLODWORD(pPanel[2].monitor);
  v14 = monitor_high - 8;
  v78 = v12 * (256 - monitor_low) + -((v12 * (256 - monitor_low)) < 0);
  v15 = (102 * monitor_low / 256) | 0x11171800;
  v17 = SDF_GS_SET_ALPHA(0, 1u, 0, 1u, 0);
  cmpSetRegALPHA(v17, OtNo);
  klass_high = HIDWORD(pPanel[1].klass);
  v20 = CMP_Y(4);
  cmpDrawBoxF(0, v20 + klass_high, pPanel[1].monitor, 512, v14, v15, OtNo);
  v21 = HIDWORD(pPanel[1].klass);
  v22 = CMP_Y(22);
  max_length = v10->max_length;
  v10->m_Items[0] = 34411008;
  v25 = v21 - v22;
  v10->m_Items[1] = 34411008;
  v10->m_Items[2] = 34411072;
  v10->m_Items[3] = 34411072;
  v27 = SDF_GS_SET_ALPHA(0, 1u, 0, 1u, 0);
  cmpSetRegALPHA(v27, OtNo);
  cmpDrawBoxG(0, v25, pPanel[1].monitor, 512, 22, v10, OtNo);
  v28 = CMP_Y(22) + v25;
  v29 = SDF_GS_SET_ALPHA(0, 1u, 0, 1u, 0);
  cmpSetRegALPHA(v29, OtNo);
  cmpDrawBoxF(0, v28, pPanel[1].monitor, 512, 4, 0x80u, OtNo);
  v30 = CMP_Y(4) + v28;
  v31 = SDF_GS_SET_ALPHA(0, 2u, 0, 1u, 0);
  cmpSetRegALPHA(v31, OtNo);
  cmpDrawBoxF(0, v30, pPanel[1].monitor, 512, 4, 0x1F252B80u, OtNo);
  v32 = CMP_Y(4);
  monitor = pPanel[2].monitor;
  if (monitor <= 0x100)
    v34 = 256 - monitor;
  else
    v34 = monitor + 256;
  v35 = ((256 - v34) << 9) & 0xFFFF0000 | (37 * (256 - v34)) & 0xFFFFFF00 | (393216 * (256 - v34)) & 0xFF000000 | 0x3C;
  v36 = v10->max_length;
  v10->m_Items[0] = v35;
  v37 = v32 + v30;
  v10->m_Items[1] = v35;
  v10->m_Items[2] = 60;
  v10->m_Items[3] = 60;
  v44 = SDF_GS_SET_ALPHA(0, 2u, 0, 1u, 0);
  cmpSetRegALPHA(v44, OtNo);
  cmpDrawBoxG(0, v37, pPanel[1].monitor, 512, 34, v10, OtNo);
  v45 = pPanel[2].monitor;
  if (v45 > 0x100)
    v45 = 512 - v45;
  v46 = ((256 - v45) << 9) & 0xFFFF0000 | (37 * (256 - v45)) & 0xFFFFFF00 | (393216 * (256 - v45)) & 0xFF000000 | 0x3C;
  v47 = v10->max_length;
  v10->m_Items[0] = v46;
  v10->m_Items[1] = v46;
  v10->m_Items[2] = 60;
  v10->m_Items[3] = 60;
  v52 = SDF_GS_SET_ALPHA(0, 2u, 0, 1u, 0);
  cmpSetRegALPHA(v52, OtNo);
  cmpDrawBoxG(0, v37, pPanel[1].monitor, 512, v12 - (v78 >> 8) + 34, v10, OtNo, 0);
  v53 = HIDWORD(pPanel[1].klass);
  v54 = CMP_Y(HIWORD(pPanel[1].monitor) - 8, 0);
  v55 = CMP_Y(34);
  v56 = v10->max_length;
  v10->m_Items[0] = 60;
  v57 = v54 + v53;
  v58 = v57 - v55;
  v10->m_Items[1] = 60;
  v10->m_Items[2] = 100803900;
  v10->m_Items[3] = 100803900;
  v61 = SDF_GS_SET_ALPHA(0, 2u, 0, 1u, 0);
  cmpSetRegALPHA(v61, OtNo);
  cmpDrawBoxG(0, v58, pPanel[1].monitor, 512, 34, v10, OtNo);
  v62 = CMP_Y(34) + v58;
  v63 = SDF_GS_SET_ALPHA(0, 2u, 0, 1u, 0);
  cmpSetRegALPHA(v63, OtNo);
  cmpDrawBoxF(0, v62, pPanel[1].monitor, 512, 4, 0x1F252B80u, OtNo);
  v64 = CMP_Y(4) + v62;
  v65 = SDF_GS_SET_ALPHA(0, 1u, 0, 1u, 0);
  cmpSetRegALPHA(v65, OtNo);
  cmpDrawBoxF(0, v64, pPanel[1].monitor, 512, 4, 0x80u, OtNo);
  v66 = CMP_Y(4);
  v67 = v10->max_length;
  v10->m_Items[0] = 34411072;
  v68 = v66 + v64;
  v10->m_Items[1] = 34411072;
  v10->m_Items[2] = 34411008;
  v10->m_Items[3] = 34411008;
  v75 = SDF_GS_SET_ALPHA(0, 1u, 0, 1u, 0);
  cmpSetRegALPHA(v75, OtNo);
  cmpDrawBoxG(0, v68, pPanel[1].monitor, 512, 22, v10, OtNo);
  CMP_Y(22);
  v76 = SDF_GS_SET_ALPHA(0, 1u, 0, 1u, 0);
  cmpSetRegALPHA(v76, OtNo);
  fclDrawPanelType0Grad(pPanel, OtNo);
}

// 0x13cae00
void fclDrawPanelType0Grad(fclPanel_t *pPanel, u32 OtNo) {
  u64 *v5;
  s64 *v6;
  s64 *v7;
  s64 *v9;
  s64 *v10;
  System_UInt32_array *v12;
  u64 v14;
  il2cpp_array_size_t max_length;
  s64 v17;
  s32 v18;
  s64 v20;
  s32 v21;
  s64 v22;
  s32 v23;
  s64 v26;
  s32 v27;
  s64 v30;
  s32 v31;
  s64 v34;
  s32 v35;
  u32 v36;
  il2cpp_array_size_t v38;
  s64 v39;
  s32 v40;
  s64 v42;
  s32 v43;
  s64 v44;
  s32 v45;
  s64 v48;
  s32 v49;
  s64 v52;
  s32 v53;
  s64 v56;
  s32 v57;
  u32 v58;
  u64 v60;

  v5 = NewSpecific(int__, 2u);
  v6 = NewSpecific(s32, 3u);
  v7 = v6;
  v5[4] = v7;
  v9 = NewSpecific(s32, 3u);
  v10 = v9;
  v5[5] = v10;
  v12 = NewSpecific(uint, 3u);
  v14 = SDF_GS_SET_ALPHA(0, 2u, 0, 1u, 0);
  cmpSetRegALPHA(v14, OtNo);
  max_length = v12->max_length;
  if (!max_length)
    goto LABEL_87;
LABEL_17:
  v12->m_Items[0] = 1416465203;
  v12->m_Items[1] = 51;
  v12->m_Items[2] = LOBYTE(v12->m_Items[0]);
  v17 = v5[4];
  v18 = CMP_X(0);
  *(v17 + 32) = v18;
  v20 = v5[5];
  v21 = CMP_Y(0);
  *(v20 + 32) = v21;
  v22 = v5[4];
  v23 = CMP_X(780);
  *(v22 + 36) = v23;
  v26 = v5[5];
  v27 = CMP_Y(0);
  *(v26 + 36) = v27;
  v30 = v5[4];
  v31 = CMP_X(0);
  *(v30 + 40) = v31;
  v34 = v5[5];
  v35 = CMP_Y(400);
  *(v34 + 40) = v35;
  v36 = *(v5 + 6);
  cmpDrawTriangleG(v5[4], v5[5], pPanel->Z, v12, OtNo);
  v38 = v12->max_length;
  v12->m_Items[0] = 826827622;
  v12->m_Items[1] = 102;
  v12->m_Items[2] = LOBYTE(v12->m_Items[0]);
  v39 = v5[4];
  v40 = CMP_X(512);
  *(v39 + 32) = v40;
  v42 = v5[5];
  v43 = CMP_Y(480);
  *(v42 + 32) = v43;
  v44 = v5[4];
  v45 = CMP_X(-268);
  *(v44 + 36) = v45;
  v48 = v5[5];
  v49 = CMP_Y(480);
  *(v48 + 36) = v49;
  v52 = v5[4];
  v53 = CMP_X(512);
  *(v52 + 40) = v53;
  v56 = v5[5];
  v57 = CMP_Y(80);
  *(v56 + 40) = v57;
  v58 = *(v5 + 6);
  cmpDrawTriangleG(v5[4], v5[5], pPanel->Z, v12, OtNo);
  v60 = SDF_GS_SET_ALPHA(0, 1u, 0, 1u, 0);
  cmpSetRegALPHA(v60, OtNo);
}

// 0x13cc250
void fclDrawPanelType1(void *pPanel, u32 OtNo) {
  u32 v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  s32 v9;
  s32 v10;
  s32 monitor;
  s32 v12;
  u64 v14;
  s32 v16;
  s32 v17;
  s32 v18;
  s32 v20;
  s32 klass_high;
  u32 v25;
  sdfTexHandle_t_array *cmpTex;
  fclSprTblArry_t_array *pSprTblArry;
  s32 v28;
  s32 v29;
  s32 v30;
  s32 v31;
  s32 v32;
  s32 v33;
  s32 v34;
  s32 v35;
  s32 v36;
  s32 v37;
  u64 v39[3];

  v3 = OtNo;
  if (pPanel)
  {
    klass = pPanel->klass;
    if (pPanel->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclPanel_t)
    {
      sub_8FC2C0(klass->_1.element_class, fclPanel_t, v39);
      if ((v39[0] & 1) != 0)
        v7 = v39[2];
      else
        v7 = v39 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  if ((BYTE2(pPanel[3].klass) & 1) != 0)
    v9 = 24;
  else
    v9 = 6;
  v10 = WORD2(pPanel[1].monitor) - 19;
  monitor = pPanel[1].monitor;
  v12 = v10 - v9;
  v14 = SDF_GS_SET_ALPHA(0, 1u, 0, 1u, 0);
  cmpSetRegALPHA(v14, v3);
  cmpDrawBoxF(
    pPanel[1].klass,
    HIDWORD(pPanel[1].klass),
    pPanel[1].monitor,
    v9,
    HIWORD(pPanel[1].monitor),
    0x13141559u,
    v3,
    0);
  v16 = pPanel[1].klass;
  v17 = CMP_X(v9 + 19);
  cmpDrawBoxF(
    v17 + v16,
    HIDWORD(pPanel[1].klass),
    pPanel[1].monitor,
    v12,
    HIWORD(pPanel[1].monitor),
    0x13141559u,
    v3,
    0);
  v18 = pPanel[1].klass;
  v20 = CMP_X(v9);
  klass_high = HIDWORD(pPanel[1].klass);
  v25 = 16 * monitor;
  pSprTblArry = cmpSprTblArry;
  fclDrawPartsEx3(v20 + v18, klass_high, v25, 0, 0, 0xAu, 3u, cmpTex, pSprTblArry, v3);
  v28 = pPanel[1].klass;
  v29 = CMP_X(v9);
  v30 = HIDWORD(pPanel[1].klass);
  v31 = v29;
  v32 = CMP_Y(25);
  fclDrawPartsEx6(
    v31 + v28,
    v32 + v30,
    v25,
    19,
    HIWORD(pPanel[1].monitor) - 50,
    0,
    0,
    0xAu,
    5u,
    cmpTex,
    cmpSprTblArry,
    v3,
    0);
  v33 = pPanel[1].klass;
  v34 = CMP_X(v9);
  v35 = HIDWORD(pPanel[1].klass);
  v36 = v34;
  v37 = CMP_Y(HIWORD(pPanel[1].monitor) - 25, 0);
  fclDrawPartsEx3(v36 + v33, v37 + v35, v25, 0, 0, 0xAu, 4u, cmpTex, cmpSprTblArry, v3);
  fclDrawArrowCursor(pPanel, v25, v9, v3);
}

// 0x13cc740
void fclDrawPanelType2(void *pPanel, u32 OtNo) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u32 v9;
  u64 v11;
  s32 v13;
  s32 klass_high;
  s32 monitor_high;
  s32 v16;
  u64 v17[3];

  if (pPanel)
  {
    klass = pPanel->klass;
    if (pPanel->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclPanel_t)
    {
      sub_8FC2C0(klass->_1.element_class, fclPanel_t, v17);
      if ((v17[0] & 1) != 0)
        v7 = v17[2];
      else
        v7 = v17 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  v9 = pPanel[2].klass;
  v11 = SDF_GS_SET_ALPHA(0, 1u, 0, 1u, 0);
  cmpSetRegALPHA(v11, OtNo);
  cmpDrawBoxF(
    pPanel[1].klass,
    HIDWORD(pPanel[1].klass),
    pPanel[1].monitor,
    WORD2(pPanel[1].monitor),
    HIWORD(pPanel[1].monitor) - 26,
    v9,
    OtNo,
    0);
  v13 = pPanel[1].klass;
  klass_high = HIDWORD(pPanel[1].klass);
  monitor_high = HIWORD(pPanel[1].monitor);
  v16 = CMP_Y(monitor_high - 26);
  cmpDrawBoxF(v13, v16 + klass_high, pPanel[1].monitor, WORD2(pPanel[1].monitor), 26, 0x3151A40u, OtNo, 0);
}

// 0x13cd180
void fclDrawPanelType3(void *pPanel, u32 OtNo) {
  u32 v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  s32 monitor;
  s32 v12;
  s32 v13;
  s32 klass_high;
  s32 v15;
  s32 v17;
  sdfTexHandle_t_array *cmpTex;
  u32 v21;
  fclSprTblArry_t_array *pSprTblArry;
  s32 v23;
  s32 v24;
  s32 v25;
  s32 v26;
  s32 v27;
  s32 v28;
  s32 v29;
  s32 v30;
  s32 v31;
  s32 v32;
  u64 v34[3];

  v3 = OtNo;
  if (pPanel)
  {
    klass = pPanel->klass;
    if (pPanel->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclPanel_t)
    {
      sub_8FC2C0(klass->_1.element_class, fclPanel_t, v34);
      if ((v34[0] & 1) != 0)
        v7 = v34[2];
      else
        v7 = v34 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  monitor = pPanel[1].monitor;
  if (pPanel[4].klass)
  {
    fclDrawPanelType3BackGrad(pPanel, v3);
    fclDrawPanelType3Line(pPanel, v3);
    fclDrawPanelType3Base(pPanel, v3);
  }
  v12 = pPanel[1].klass;
  v13 = CMP_X(23);
  klass_high = HIDWORD(pPanel[1].klass);
  v15 = v13;
  v17 = CMP_Y(6);
  v21 = 16 * monitor;
  pSprTblArry = cmpSprTblArry;
  fclDrawPartsEx3(v15 + v12, v17 + klass_high, v21, 0, 0, 0xAu, 0xDu, cmpTex, pSprTblArry, v3);
  v23 = pPanel[1].klass;
  v24 = CMP_X(23);
  v25 = HIDWORD(pPanel[1].klass);
  v26 = v24;
  v27 = CMP_Y(31);
  fclDrawPartsEx6(
    v26 + v23,
    v27 + v25,
    v21,
    19,
    HIWORD(pPanel[1].monitor) - 62,
    0,
    0,
    0xAu,
    0xFu,
    cmpTex,
    cmpSprTblArry,
    v3,
    0);
  v28 = pPanel[1].klass;
  v29 = CMP_X(23);
  v30 = HIDWORD(pPanel[1].klass);
  v31 = v29;
  v32 = CMP_Y(HIWORD(pPanel[1].monitor) - 31, 0);
  fclDrawPartsEx3(v31 + v28, v32 + v30, v21, 0, 0, 0xAu, 0xEu, cmpTex, cmpSprTblArry, v3);
  fclDrawArrowCursor(pPanel, v21, 23, v3);
}

// 0x13ccc70
void fclDrawPanelType3BackGrad(fclPanel_t *pPanel, u32 OtNo) {
  u64 *v7;
  s32 W;
  s32 v9;
  u32 v11;
  s32 v12;
  s32 Y;
  s32 v15;
  s32 v16;
  u32 Z;
  s32 H;
  s32 v20;
  u32 v22;
  s32 v23;
  s32 v24;
  s32 v25;
  s32 v26;

  v7 = NewSpecific(uint, 4u);
  W = pPanel->W;
  v9 = fclDefaultMoverCoreFunc(100, 512 - pPanel->Timer2);
  v11 = *(v7 + 6);
  v12 = v9;
  *(v7 + 8) = 40;
  *(v7 + 9) = 0;
  *(v7 + 10) = 40;
  *(v7 + 11) = 0;
  Y = pPanel->Y;
  v15 = W - 70;
  v16 = CMP_Y(15);
  Z = pPanel->Z;
  H = pPanel->H;
  v20 = v16;
  v22 = *(v7 + 8);
  cmpDrawBoxF(-v12, Y - v20, Z, v15, H + 30, v22, OtNo);
  v23 = CMP_X(v15);
  v24 = pPanel->Y;
  v25 = v23;
  v26 = CMP_Y(15);
  cmpDrawBoxG(v25 - v12, v24 - v26, pPanel->Z, 60, pPanel->H + 30, v7, OtNo);
}

// 0x13ccec0
void fclDrawPanelType3Base(fclPanel_t *pPanel, u32 OtNo) {
  u64 *v5;
  u64 *v7;
  fclSprite_t_o *v9;
  u32 Z;
  sdfTexHandle_t_o *TexHandle;
  s32 Y;
  s32 i;
  s32 v17;
  s32 H;
  s32 X;
  fclSprite_t_o *v22;
  s32 v24;
  s32 v25;

  v5 = NewSpecific(fclSprite_t, 2u);
  v7 = v5;
  v9 = v5[4];
  Z = pPanel->Z;
  TexHandle = pPanel->TexHandle;
  fclSetSprite(v9, 53, 29, 16 * Z, 3, 32, 56, 61, 0x80808080, TexHandle);
  fclSetSprite(v7[5], 244, 29, 16 * pPanel->Z, 3, 1, 247, 30, 0x80808080, pPanel->TexHandle);
  Y = pPanel->Y;
  for (i = CMP_Y(6) + Y; ; i += CMP_Y(29))
  {
    v17 = pPanel->Y;
    H = pPanel->H;
    if (i >= CMP_Y(H - 9) + v17)
      break;
    X = pPanel->X;
    v22 = v7[4];
    fclDrawSpriteCore(X, i, 53, 29, 0, v22, 0, 0, 1u, OtNo);
    v24 = pPanel->X;
    v25 = CMP_X(53);
    fclDrawSpriteCore(v25 + v24, i, 244, 29, 0, v7[5], 0, 0, 1u, OtNo);
  }
}

// 0x13cca30
void fclDrawPanelType3Line(fclPanel_t *pPanel, u32 OtNo) {
  s32 v5;
  s32 H;
  s32 v7;
  u64 *v8;
  u32 Z;
  sdfTexHandle_t_o *TexHandle;
  s32 X;
  s32 v13;

  v5 = pPanel->W - 107;
  H = pPanel->H;
  v7 = CMP_Y(H - 3);
  v8 = Allocate(fclSprite_t);
  fclSprite_t___ctor(v8);
  Z = pPanel->Z;
  TexHandle = pPanel->TexHandle;
  fclSetSprite(v8, 73, 4, 16 * Z, 148, 68, 221, 72, 0x80808080, TexHandle);
  X = pPanel->X;
  v13 = CMP_X(v5) + X;
  fclDrawSpriteCore(v13, pPanel->Y, 73, 4, 0, v8, 0, 0, 1u, OtNo);
  fclDrawSpriteCore(v13, pPanel->Y + v7, 73, 4, 0, v8, 2u, 0, 1u, OtNo);
  fclSetSprite(v8, v5, 3, 16 * pPanel->Z, 148, 68, 149, 72, 0x80808080, pPanel->TexHandle);
  fclDrawSpriteCore(pPanel->X, pPanel->Y, v5, 4, 0, v8, 0, 0, 1u, OtNo);
  fclDrawSpriteCore(pPanel->X, pPanel->Y + v7, v5, 4, 0, v8, 2u, 0, 1u, OtNo);
}

// 0x13cab90
void fclDrawPanelTypeDef(void *pPanel, u32 OtNo) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u32 v9;
  u64 v11;
  u64 v12[3];

  if (pPanel)
  {
    klass = pPanel->klass;
    if (pPanel->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclPanel_t)
    {
      sub_8FC2C0(klass->_1.element_class, fclPanel_t, v12);
      if ((v12[0] & 1) != 0)
        v7 = v12[2];
      else
        v7 = v12 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  v9 = pPanel[2].klass;
  v11 = SDF_GS_SET_ALPHA(0, 1u, 0, 1u, 0);
  cmpSetRegALPHA(v11, OtNo);
  cmpDrawBoxF(
    pPanel[1].klass,
    HIDWORD(pPanel[1].klass),
    pPanel[1].monitor,
    WORD2(pPanel[1].monitor),
    HIWORD(pPanel[1].monitor),
    v9,
    OtNo,
    0);
}

// 0x13c96e0
u32 fclGetPanelFlag(fclPanel_t *panel) {
  return panel->Flag;
}

// 0x13c99c0
s32 fclGetPanelMoverOfsX(fclPanelMover_t *pMover) {
  return pMover->OfsX;
}

// 0x13c99d0
s32 fclGetPanelMoverRate(fclPanelMover_t *pMover) {
  return pMover->Rate;
}

// 0x13c99f0
s32 fclGetPanelMoverWork(fclPanelMover_t *pMover) {
  return pMover->Work;
}

// 0x13c9700
s32 fclGetPanelTimer(fclPanel_t *panel) {
  return panel->Timer;
}

// 0x13cd6b0
void fclInitPanel(fclPanel_t *pPanel, s32 X, s32 Y, u32 Z, s32 W, s32 H, u32 Col, s8 Type, s8 Spd) {
  u16 v12;
  u16 v13;
  u64 *v18;
  u64 *v19;
  intptr_t *v20;
  u64 *v21;
  u64 *v22;
  u64 *v23;
  u64 *v24;
  struct fclUpdatePanelFunc_t_o *v25;

  v12 = H;
  v13 = W;
  pPanel->X = X;
  pPanel->Y = Y;
  pPanel->Z = Z;
  pPanel->W = v13;
  pPanel->H = v12;
  pPanel->Col = Col;
  pPanel->Spd = Spd;
  *&pPanel->Timer = 0;
  pPanel->TexHandle = 0;
  switch (Type)
  {
    case 0:
      v18 = Allocate(fclDrawPanelFunc_t);
      fclDrawPanelFunc_t___ctor(v18, 0, Method_fclPanel_fclDrawPanelType0__);
      pPanel->DrawFunc = v18;
      v19 = Allocate(fclUpdatePanelFunc_t);
      v20 = &Method_fclPanel_fclUpdatePanelType0__;
      break;
    case 1:
      v22 = Allocate(fclDrawPanelFunc_t);
      fclDrawPanelFunc_t___ctor(v22, 0, Method_fclPanel_fclDrawPanelType1__);
      pPanel->DrawFunc = v22;
      v19 = Allocate(fclUpdatePanelFunc_t);
      v20 = &Method_fclPanel_fclUpdatePanelType1__;
      break;
    case 2:
      v23 = Allocate(fclDrawPanelFunc_t);
      fclDrawPanelFunc_t___ctor(v23, 0, Method_fclPanel_fclDrawPanelType2__);
      pPanel->DrawFunc = v23;
      v19 = Allocate(fclUpdatePanelFunc_t);
      v20 = &Method_fclPanel_fclUpdatePanelType2__;
      break;
    case 3:
      v24 = Allocate(fclDrawPanelFunc_t);
      fclDrawPanelFunc_t___ctor(v24, 0, Method_fclPanel_fclDrawPanelType3__);
      pPanel->DrawFunc = v24;
      v19 = Allocate(fclUpdatePanelFunc_t);
      v20 = &Method_fclPanel_fclUpdatePanelType3__;
      break;
    default:
      v21 = Allocate(fclDrawPanelFunc_t);
      fclDrawPanelFunc_t___ctor(v21, 0, Method_fclPanel_fclDrawPanelTypeDef__);
      pPanel->DrawFunc = v21;
      v19 = Allocate(fclUpdatePanelFunc_t);
      v20 = &Method_fclPanel_fclUpdatePanelTypeDef__;
      break;
  }
  v25 = v19;
  fclUpdatePanelFunc_t___ctor(v19, 0, *v20);
  pPanel->UpdateFunc = v25;
}

// 0x13c9900
void fclInitPanelMover(fclPanelMover_t *pMover, s32 DefX, s32 DefY, s32 MaxOfsX, s32 MaxOfsY, s32 DefRate, s32 Spd, fclPanelMoverFunc_t *MoverFunc) {
  pMover->Mode = 0;
  pMover->OfsX = DefX;
  pMover->OfsY = DefY;
  pMover->MaxOfsX = MaxOfsX;
  pMover->MaxOfsY = MaxOfsY;
  pMover->Rate = DefRate;
  pMover->Spd = Spd;
  pMover->MoverFunc = MoverFunc;
  fclPanelMoverFunc_t__Invoke(MoverFunc, pMover);
}

// 0x13c96f0
void fclSetPanelFlag(fclPanel_t *panel, u32 flag) {
  panel->Flag = flag;
}

// 0x13c99b0
void fclSetPanelMoverMode(fclPanelMover_t *pMover, s32 Mode) {
  pMover->Mode = Mode;
}

// 0x13c99e0
void fclSetPanelMoverWork(fclPanelMover_t *pMover, s32 Val) {
  pMover->Work = Val;
}

// 0x13cd5d0
void fclSetPanelTex(fclPanel_t *pPanel, u32 UV1, u32 UV2, u32 UV3, u32 UV4, sdfTexHandle_t *TexHandle) {
  struct System_UInt32_array *TexUV;
  struct System_UInt32_array *v9;
  struct System_UInt32_array *v11;
  struct System_UInt32_array *v13;

  TexUV = pPanel->TexUV;
  TexUV->m_Items[0] = UV1;
  v9 = pPanel->TexUV;
  v9->m_Items[1] = UV2;
  v11 = pPanel->TexUV;
  v11->m_Items[2] = UV3;
  v13 = pPanel->TexUV;
  v13->m_Items[3] = UV4;
  pPanel->TexHandle = TexHandle;
}

// 0x13cdaf0
void fclUpdatePanel(fclPanel_t *pPanel) {
  fclUpdatePanelFunc_t__Invoke(pPanel->UpdateFunc, pPanel);
}

// 0x13c9930
s32 fclUpdatePanelMover(fclPanelMover_t *pMover) {
  s32 Mode;
  s32 *p_Rate;
  s32 v5;

  Mode = pMover->Mode;
  if (Mode == 2)
  {
    p_Rate = &pMover->Rate;
    v5 = (pMover->Rate - pMover->Spd) & ~((pMover->Rate - pMover->Spd) >> 31);
LABEL_6:
    *p_Rate = v5;
    goto LABEL_7;
  }
  if (Mode == 1)
  {
    p_Rate = &pMover->Rate;
    v5 = pMover->Spd + pMover->Rate;
    if (v5 >= 512)
      v5 = 512;
    goto LABEL_6;
  }
LABEL_7:
  fclPanelMoverFunc_t__Invoke(pMover->MoverFunc, pMover);
  return pMover->Rate;
}

// 0x13cc150
void fclUpdatePanelType0(void *pPanel) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  s32 v5;
  char *v6;
  s64 *v7;
  u64 v8[3];

  klass = pPanel->klass;
  if (pPanel->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclPanel_t)
  {
    sub_8FC2C0(klass->_1.element_class, fclPanel_t, v8);
    if ((v8[0] & 1) != 0)
      v6 = v8[2];
    else
      v6 = v8 + 1;
    v7 = sub_8C4940(v6);
  }
  v5 = LODWORD(pPanel[2].monitor) + BYTE4(pPanel[2].klass);
  if (v5 >= 256)
    v5 = 256;
  LODWORD(pPanel[2].monitor) = v5;
}

// 0x13cc640
void fclUpdatePanelType1(void *pPanel) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  s32 v5;
  char *v6;
  s64 *v7;
  u64 v8[3];

  klass = pPanel->klass;
  if (pPanel->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclPanel_t)
  {
    sub_8FC2C0(klass->_1.element_class, fclPanel_t, v8);
    if ((v8[0] & 1) != 0)
      v6 = v8[2];
    else
      v6 = v8 + 1;
    v7 = sub_8C4940(v6);
  }
  v5 = LODWORD(pPanel[2].monitor) + BYTE4(pPanel[2].klass);
  if (v5 > 512)
    v5 = 0;
  LODWORD(pPanel[2].monitor) = v5;
}

// 0x13cc930
void fclUpdatePanelType2(void *pPanel) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  s32 v5;
  char *v6;
  s64 *v7;
  u64 v8[3];

  klass = pPanel->klass;
  if (pPanel->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclPanel_t)
  {
    sub_8FC2C0(klass->_1.element_class, fclPanel_t, v8);
    if ((v8[0] & 1) != 0)
      v6 = v8[2];
    else
      v6 = v8 + 1;
    v7 = sub_8C4940(v6);
  }
  v5 = LODWORD(pPanel[2].monitor) + BYTE4(pPanel[2].klass);
  if (v5 >= 256)
    v5 = 256;
  LODWORD(pPanel[2].monitor) = v5;
}

// 0x13cd4c0
void fclUpdatePanelType3(void *pPanel) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  s32 monitor_high;
  s32 v6;
  s32 v7;
  char *v8;
  s64 *v9;
  u64 v10[3];

  klass = pPanel->klass;
  if (pPanel->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclPanel_t)
  {
    sub_8FC2C0(klass->_1.element_class, fclPanel_t, v10);
    if ((v10[0] & 1) != 0)
      v8 = v10[2];
    else
      v8 = v10 + 1;
    v9 = sub_8C4940(v8);
  }
  monitor_high = HIDWORD(pPanel[2].monitor);
  v6 = LODWORD(pPanel[2].monitor) + BYTE4(pPanel[2].klass);
  if (v6 >= 513)
    v6 = 0;
  LODWORD(pPanel[2].monitor) = v6;
  v7 = monitor_high + 32;
  if (monitor_high + 32 >= 512)
    v7 = 512;
  HIDWORD(pPanel[2].monitor) = v7;
}

// 0x13cad00
void fclUpdatePanelTypeDef(void *pPanel) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  s32 v5;
  char *v6;
  s64 *v7;
  u64 v8[3];

  klass = pPanel->klass;
  if (pPanel->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclPanel_t)
  {
    sub_8FC2C0(klass->_1.element_class, fclPanel_t, v8);
    if ((v8[0] & 1) != 0)
      v6 = v8[2];
    else
      v6 = v8 + 1;
    v7 = sub_8C4940(v6);
  }
  v5 = LODWORD(pPanel[2].monitor) + BYTE4(pPanel[2].klass);
  if (v5 >= 256)
    v5 = 256;
  LODWORD(pPanel[2].monitor) = v5;
}
