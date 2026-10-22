#include "types.h"

typedef struct dds3DrawEnv_t dds3DrawEnv_t;
typedef struct sdf3DPrimPolyParm_t sdf3DPrimPolyParm_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfGrOt_t sdfGrOt_t;
typedef struct sdfGrPacketHeader_t sdfGrPacketHeader_t;
typedef struct sdfGrRefPacketHeader_t sdfGrRefPacketHeader_t;
typedef struct sdfGrStdDrawEnv_t sdfGrStdDrawEnv_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

static s32 PRIM;
static s32 RGBAQ;
static s32 XYZ2;
static s32 NOP;
static sdfGrOt_t *dds3Ot[1];
static u32 dds3RBackColor;
static dds3DrawEnv_t *dds3DrawEnv;
static sdfVector4_t dds3RCameraTargetPos;
static sdfVector4_t dds3RCameraEyePos;
static u32 effPktDefaultTriangleFaceIndex[32];
static s8 dds3CrossfadeRunFlag;
static u32 dds3CrossfadeFrame;
static u32 dds3CrossfadeFrame_End;

s32 dds3AllocRenderTexture(u16 sx, u16 sy, f32 aspect);
void dds3CrossfadeEnd(void);
void dds3FreeRenderTexture(void);
s32 dds3GetFrameID(void);
void dds3RenderTextureOFF(void);
s32 dds3RenderTextureON(void);
void *sdf2DAllocSprite(s32 aNumOfSpr);
s32 sdf2DGetPrimPacketSize(s32 aNumOfRegs, s32 aNumOfPrim);
void *sdf2DGetPrimPtr(void *aPacketPtr);
void *sdf2DLinkTexPacket(sdfDrawTag_t *aTag, sdfTexHandle_t *aTexHndl, s32 aCtx);
void *sdf2DMakePrimPacketHeader_24943632(void *aPacketPtr, s32 aPrimReg, s32 aNumOfRegs, u64 aGifRegs, s32 aNumOfPrim);
s32 sdfDrawTagInit(sdfDrawTag_t *a);
void sdfDrawTagLink(sdfDrawTag_t *aTag, void *aPacket);
s32 sdfDrawTagLinkOt(s32 a, sdfDrawTag_t *b);
void *sdfGrAllocPacketBuff(s32 aSize);
void sdfGrLinkDispFrameTex(sdfDrawTag_t *aTag, sdfGrStdDrawEnv_t *aEnv, sdfGrRefPacketHeader_t *aPkt);

// 0x122a110
s32 SDF_DMA_ID(s32 irq, s32 id, s32 pce) {
  return 0;
}

// 0x122a120
s32 SDF_DMA_SET_TAG(s32 p, s32 qwc, s32 id, s32 addr) {
  return 0;
}

// 0x122a0d0
s32 SDF_EVAL(s32 a) {
  return a;
}

// 0x122a170
s32 SDF_GIFTAG_PARM(s32 nloop, s32 eop, s32 pre, s32 prim, s32 flg, s32 nreg) {
  return 0;
}

// 0x122a180
s32 SDF_GIFTAG_REGS11(s32 r0, s32 r1, s32 r2, s32 r3, s32 r4, s32 r5, s32 r6, s32 r7, s32 r8, s32 r9, s32 rA) {
  return 0;
}

// 0x122a160
s32 SDF_GIF_SET_XYZ2(s32 pkt, s32 x, s32 y, s32 z, s32 adc) {
  return 0;
}

// 0x122a1c0
u64 SDF_GS_SET_ALPHA(s32 a, s32 b, s32 c, s32 d, s32 fix) {
  return a | (4 * b) | (16 * c) | fix | (d << 6);
}

// 0x122a130
s32 SDF_GS_SET_PRIM(s32 prim, s32 iip, s32 tme, s32 fge, s32 abe, s32 aa1, s32 fst, s32 ctxt, s32 fix) {
  return prim | (8 * iip) | (16 * tme) | (32 * fge) | (abe << 6) | (aa1 << 7) | (fst << 8) | (ctxt << 9) | (fix << 10);
}

// 0x122a1e0
u64 SDF_GS_SET_TEST(s32 ate, s32 atst, s32 aref, s32 afail, s32 date, s32 datm, s32 zte, s32 ztst) {
  return ate | (2 * atst) | (16 * aref) | (afail << 12) | (date << 14) | (datm << 15) | (zte << 16) | (ztst << 17);
}

// 0x122a1b0
s32 SDF_GS_SET_TEXA(s32 ta0, s32 aem, s32 ta1) {
  return 0;
}

// 0x122a1a0
s32 SDF_GS_SET_XYZ2(s32 x, s32 y, s32 z) {
  return 0;
}

// 0x122a0e0
s32 SDF_MAKE32(s32 l, s32 h) {
  return 0;
}

// 0x122a100
s32 SDF_MAKE64(s32 l, s32 h) {
  return 0;
}

// 0x122a0f0
s32 SDF_POKE64(s32 p, s32 d) {
  return 0;
}

// 0x122a190
s32 SDF_SIZE_ADJUST(s32 i, s32 n) {
  return 0;
}

// 0x122a290
void SDF_STORE_UNALIGN96(void *p, u32 d) {
  ;
}

// 0x122a250
u32 SDF_VIF_SET_DIRECT(u32 addr) {
  return addr | 0x50000000;
}

// 0x122a260
u32 SDF_VIF_SET_DIRECTHL(u32 size) {
  return size | 0x51000000;
}

// 0x122a230
u32 SDF_VIF_SET_ITOP(u32 addr) {
  return addr | 0x4000000;
}

// 0x122a240
u32 SDF_VIF_SET_MPG(u32 addr, u32 size) {
  return addr | (size << 16) | 0x4A000000;
}

// 0x122a220
u32 SDF_VIF_SET_MSCAL(u32 addr) {
  return addr | 0x14000000;
}

// 0x122a270
u32 SDF_VIF_SET_UNPACK(u32 typ, u32 m, u32 usn, u32 flg, u32 addr, u32 size) {
  return (typ << 24) | (m << 28) | (usn << 14) | (flg << 15) | addr | (size << 16) | 0x60000000;
}

// 0x122a990
void dds3CrossfadeEnd(void) {
  dds3RenderTextureOFF();
  dds3FreeRenderTexture();
  dds3CrossfadeRunFlag = 0;
  Write("dds3CrossfadeEnd\n", 0);
}

// 0x122aa60
void dds3CrossfadeRun(void) {
  u64 v2;
  u64 v3;
  u64 v4;
  s16 v6;
  s32 v7;
  u32 dds3CrossfadeFrame;
  u64 *v9;
  s32 *v11;
  Il2CppObject *v12;
  sdfDrawTag_t_o *v14;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v17;
  s64 *v18;
  u64 *v19;
  s32 *v20;
  Il2CppObject *v21;
  sdfGrRefPacketHeader_t_o *v23;
  Il2CppClass *v24;
  s64 v25;
  char *v26;
  s64 *v27;
  struct dds3DrawEnv_t_array *dds3DrawEnv;
  s32 FrameID;
  u64 *v32;
  s32 *v33;
  Il2CppObject *v34;
  Il2CppClass *v35;
  s64 v36;
  char *v37;
  s64 *v38;
  u64 *v39;
  s32 *v40;
  Il2CppObject *v41;
  Il2CppObject *v42;
  Il2CppClass *v43;
  s64 v44;
  char *v45;
  s64 *v46;
  u64 *v47;
  Il2CppObject *v48;
  Il2CppObject *v49;
  Il2CppClass *v50;
  s64 v51;
  char *v52;
  s64 *v53;
  struct sdfGrOt_t_array *dds3Ot;
  s64 v56;
  u64 *v57;
  s32 *v59;
  Il2CppObject *v60;
  sdfDrawTag_t_o *v62;
  Il2CppClass *v63;
  s64 v64;
  char *v65;
  s64 *v66;
  Il2CppObject *v67;
  Il2CppObject *v68;
  Il2CppClass *v69;
  s64 v70;
  char *v71;
  s64 *v72;
  f32 v73;
  f32 v74;
  struct sdfGrOt_t_array *v75;
  u64 v77[2];
  char *v78;

  else
  {
    if (!dds3CrossfadeRunFlag)
      return;
  }
  v6 = *(v4 + 294);
  if ((v6 & 0x200) != 0)
  {
    v7 = v6 & 0x200;
    if (dds3CrossfadeFrame != dds3CrossfadeFrame_End)
    {
LABEL_8:
      if (v7 && !*(v4 + 216))
      {
        if (!dds3CrossfadeFrame)
          goto LABEL_11;
      }
      else if (!dds3CrossfadeFrame)
      {
LABEL_11:
        v9 = Allocate(sdfDrawTag_t);
        sdfDrawTag_t___ctor(v9);
        v11 = il2cp::SizeOf(v9, s32);
        v12 = sdfGrAllocPacketBuff(*v11);
        v14 = v12;
        if (v12)
        {
          klass = v12->klass;
          if (v12->klass->_2.typeHierarchyDepth < typeHierarchyDepth
            || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfDrawTag_t)
          {
            sub_8FC2C0(klass->_1.element_class, sdfDrawTag_t, v77);
            if ((v77[0] & 1) != 0)
              v17 = v78;
            else
              v17 = v77 + 1;
            v18 = sub_8C4940(v17);
          }
        }
        sdfDrawTagInit(v14);
        v19 = Allocate(sdfGrRefPacketHeader_t);
        sdfGrRefPacketHeader_t___ctor(v19);
        v20 = il2cp::SizeOf(v19, s32);
        v21 = sdfGrAllocPacketBuff(*v20);
        v23 = v21;
        if (v21)
        {
          v24 = v21->klass;
          if (v21->klass->_2.typeHierarchyDepth < v25
            || v24->_2.typeHierarchy[v25 - 1] != sdfGrRefPacketHeader_t)
          {
            sub_8FC2C0(v24->_1.element_class, sdfGrRefPacketHeader_t, v77);
            if ((v77[0] & 1) != 0)
              v26 = v78;
            else
              v26 = v77 + 1;
            v27 = sub_8C4940(v26);
          }
        }
        FrameID = dds3GetFrameID();
        sdfGrLinkDispFrameTex(v14, dds3DrawEnv->m_Items[FrameID]->DrawEnv, v23);
        v32 = Allocate(pTexPkt);
        _ctor(v32, 0);
        v33 = il2cp::SizeOf(v32, s32);
        v34 = sdfGrAllocPacketBuff(*v33);
        if (v34)
        {
          v35 = v34->klass;
          if (v34->klass->_2.typeHierarchyDepth < v36 || v35->_2.typeHierarchy[v36 - 1] != pTexPkt)
          {
            sub_8FC2C0(v35->_1.element_class, pTexPkt, v77);
            if ((v77[0] & 1) != 0)
              v37 = v78;
            else
              v37 = v77 + 1;
            v38 = sub_8C4940(v37);
          }
        }
        *(v34[1].monitor + 3) = 0;
        *(v34[1].monitor + 4) = 59;
        v34[2].klass->_1.namespaze = 0;
        v34[2].klass->_1.byval_arg.data = &loc_3C + 3;
        sdfDrawTagLink(v14, v34);
        v39 = Allocate(sdfPrimTransPacket_t);
        sdfPrimTransPacket_t___ctor(v39);
        v40 = il2cp::SizeOf(v39, s32);
        v41 = sdfGrAllocPacketBuff(*v40);
        v42 = v41;
        if (v41)
        {
          v43 = v41->klass;
          if (v41->klass->_2.typeHierarchyDepth < v44
            || v43->_2.typeHierarchy[v44 - 1] != sdfPrimTransPacket_t)
          {
            sub_8FC2C0(v43->_1.element_class, sdfPrimTransPacket_t, v77);
            if ((v77[0] & 1) != 0)
              v45 = v78;
            else
              v45 = v77 + 1;
            v46 = sub_8C4940(v45);
          }
        }
        v47 = Allocate(sdfPrimTransPacket_t);
        sdfPrimTransPacket_t___ctor(v47);
        il2cp::SizeOf(v47, s32);
        *(*(v42[1].monitor + 2) + 24LL) = 200705;
        *(*(v42[1].monitor + 2) + 32LL) = 71;
        *(*(v42[1].monitor + 3) + 24LL) = 68;
        *(*(v42[1].monitor + 3) + 32LL) = 66;
        sdfDrawTagLink(v14, v42);
        v48 = sdf2DAllocSprite(1);
        v49 = sdf2DGetPrimPtr(v48);
        if (v49)
        {
          v50 = v49->klass;
          if (v49->klass->_2.typeHierarchyDepth < v51
            || v50->_2.typeHierarchy[v51 - 1] != sdf2DSpriteParm_t)
          {
            sub_8FC2C0(v50->_1.element_class, sdf2DSpriteParm_t, v77);
            if ((v77[0] & 1) != 0)
              v52 = v78;
            else
              v52 = v77 + 1;
            v53 = sub_8C4940(v52);
          }
        }
        LODWORD(v49[1].klass->_1.name) = 128;
        HIDWORD(v49[1].klass->_1.name) = 128;
        LODWORD(v49[1].klass->_1.namespaze) = 128;
        HIDWORD(v49[1].klass->_1.namespaze) = 128;
        *(v49[1].monitor + 4) = 0;
        *(v49[1].monitor + 5) = 0;
        LODWORD(v49[2].klass->_1.name) = 30712;
        HIDWORD(v49[2].klass->_1.name) = 30968;
        LODWORD(v49[2].klass->_1.namespaze) = 16711680;
        WORD2(v49[2].klass->_1.namespaze) = 0;
        *(v49[2].monitor + 4) = 0x2000;
        *(v49[2].monitor + 5) = 3584;
        LODWORD(v49[3].klass->_1.name) = 34808;
        HIDWORD(v49[3].klass->_1.name) = 34552;
        LODWORD(v49[3].klass->_1.namespaze) = 16711680;
        WORD2(v49[3].klass->_1.namespaze) = 0;
        sdfDrawTagLink(v14, v48);
        sdfDrawTagLinkOt(dds3Ot->m_Items[2], v14);
          goto LABEL_77;
        goto LABEL_75;
      }
      if ((*(v4 + 295) & 2) == 0)
      {
LABEL_77:
        ++*(*(v4 + 184) + 84LL);
        v56 = *(v4 + 184);
        LODWORD(v3) = *(v56 + 84);
        LODWORD(v2) = *(v56 + 88);
        v57 = Allocate(sdfDrawTag_t);
        sdfDrawTag_t___ctor(v57);
        v59 = il2cp::SizeOf(v57, s32);
        v60 = sdfGrAllocPacketBuff(*v59);
        v62 = v60;
        if (v60)
        {
          v63 = v60->klass;
          if (v60->klass->_2.typeHierarchyDepth < v64
            || v63->_2.typeHierarchy[v64 - 1] != sdfDrawTag_t)
          {
            sub_8FC2C0(v63->_1.element_class, sdfDrawTag_t, v77);
            if ((v77[0] & 1) != 0)
              v65 = v78;
            else
              v65 = v77 + 1;
            v66 = sub_8C4940(v65);
          }
        }
        sdfDrawTagInit(v62);
        sdf2DLinkTexPacket(v62, 0, 0);
        v67 = sdf2DAllocSprite(1);
        v68 = sdf2DGetPrimPtr(v67);
        if (v68)
        {
          v69 = v68->klass;
          if (v68->klass->_2.typeHierarchyDepth < v70
            || v69->_2.typeHierarchy[v70 - 1] != sdf2DSpriteParm_t)
          {
            sub_8FC2C0(v69->_1.element_class, sdf2DSpriteParm_t, v77);
            if ((v77[0] & 1) != 0)
              v71 = v78;
            else
              v71 = v77 + 1;
            v72 = sub_8C4940(v71);
          }
        }
        v73 = v3;
        v74 = v2;
        LODWORD(v68[1].klass->_1.name) = 128;
        HIDWORD(v68[1].klass->_1.name) = 128;
        LODWORD(v68[1].klass->_1.namespaze) = 128;
        HIDWORD(v68[1].klass->_1.namespaze) = (0x80 - ((v73 * 128.0) / v74));
        *(v68[1].monitor + 4) = 0;
        *(v68[1].monitor + 5) = 0;
        LODWORD(v68[2].klass->_1.name) = 28672;
        HIDWORD(v68[2].klass->_1.name) = 30976;
        LODWORD(v68[2].klass->_1.namespaze) = 16711680;
        WORD2(v68[2].klass->_1.namespaze) = 0;
        *(v68[2].monitor + 4) = 4096;
        *(v68[2].monitor + 5) = 3584;
        LODWORD(v68[3].klass->_1.name) = 36864;
        HIDWORD(v68[3].klass->_1.name) = 34560;
        LODWORD(v68[3].klass->_1.namespaze) = 16711680;
        WORD2(v68[3].klass->_1.namespaze) = 0;
        sdfDrawTagLink(v62, v67);
        v75 = dds3Ot;
        sdfDrawTagLinkOt(v75->m_Items[70], v62);
        return;
      }
LABEL_75:
      goto LABEL_77;
    }
  }
  else
  {
    v7 = 0;
    if (dds3CrossfadeFrame != dds3CrossfadeFrame_End)
      goto LABEL_8;
  }
  dds3CrossfadeEnd(v4);
}

// 0x122a610
void dds3CrossfadeStart(u32 frame) {
  u64 v3;
  struct dds3DrawEnv_t_array *dds3DrawEnv;
  struct sdfGrTagStdReg_t_o *xyzA;
  struct dds3DrawEnv_t_array *v11;
  struct dds3DrawEnv_t_array *v13;
  struct sdfGrTagStdReg_t_o *v15;
  struct dds3DrawEnv_t_array *v16;

  if (*(*(v3 + 184) + 80LL))
  {
    dds3CrossfadeEnd(v3);
  }
  if (frame)
  {
    sub_854930(&dds3RCameraTargetPos, 0);
    sub_854930(&dds3RCameraTargetPos, 1u);
    sub_854930(&dds3RCameraTargetPos, 2u);
    sub_854930(&dds3RCameraEyePos, 0);
    sub_854930(&dds3RCameraEyePos, 1u);
    sub_854930(&dds3RCameraEyePos, 2u);
    dds3RBackColor = -2139062144;
    dds3AllocRenderTexture(0x100u, 0xE0u, 0.0);
    dds3RenderTextureON();
    else
    {
      if (!LODWORD(dds3DrawEnv->max_length))
        goto LABEL_21;
    }
    xyzA = dds3DrawEnv->m_Items[0]->RenderDrawEnv->clear->xyzA;
    xyzA->data = 0;
    v11 = dds3DrawEnv;
    v11->m_Items[0]->RenderDrawEnv->clear->xyzB->data = 0;
    v13 = dds3DrawEnv;
    v15 = v13->m_Items[1]->RenderDrawEnv->clear->xyzA;
    v15->data = 0;
    v16 = dds3DrawEnv;
    v16->m_Items[1]->RenderDrawEnv->clear->xyzB->data = 0;
    dds3CrossfadeRunFlag = 1;
    dds3CrossfadeFrame = 0;
    Write("dds3CrossfadeStart\n", 0);
  }
}

// 0x122a2b0
sdfTexHandle_t *dds3GetRenderTexture(void) {
  return 0;
}

// 0x122a420
void *effPkt2DAllocF4(u32 prim) {
  u64 *v3;
  s32 *v5;
  Il2CppObject *v6;
  Il2CppObject *v7;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v10;
  s64 *v11;
  u64 *v12;
  u64 *v14;
  u64 v16[3];

  v3 = Allocate(effPkt2DF4Parm_t);
  effPkt2DF4Parm_t___ctor(v3);
  v5 = il2cp::SizeOf(v3, s32);
  v6 = sdfGrAllocPacketBuff(*v5);
  v7 = v6;
  if (v6)
  {
    klass = v6->klass;
    if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPkt2DF4Parm_t)
    {
      sub_8FC2C0(klass->_1.element_class, effPkt2DF4Parm_t, v16);
      if ((v16[0] & 1) != 0)
        v10 = v16[2];
      else
        v10 = v16 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  v12 = Allocate(effPkt2DF4Parm_t);
  effPkt2DF4Parm_t___ctor(v12);
  il2cp::SizeOf(v12, s32);
  v14 = Allocate(effPkt2DF4Parm_t);
  effPkt2DF4Parm_t___ctor(v14);
  il2cp::SizeOf(v14, uint);
  *(v7[1].monitor + 2) = 0;
  *(v7[1].monitor + 3) = 0;
  v7[6].monitor = 0;
  v7[7].klass = 0;
  v7[7].monitor = 0;
  v7[2].klass = (prim | 0x14C);
  return v7;
}

// 0x122a340
void *effPkt2DAllocTriStrip(s32 num, u32 prim) {
  s32 v6;
  Il2CppObject *v8;

  v6 = sdf2DGetPrimPacketSize(9, num);
  v8 = sdfGrAllocPacketBuff(v6);
  sdf2DMakePrimPacketHeader_24943632(v8, prim | 0x54, 9, 0, num);
  return v8;
}

// 0x122a2c0
void *effPkt2DGetPrimPtr(void *pPkt) {
  s32 v4;

  v4 = *il2cp::SizeOf(pPkt, s32) + 32;
  return sub_8D3950(s32, &v4);
}

// 0x122a600
void *effPkt3DPrimMakePoly(sdf3DPrimPolyParm_t *aParm) {
  return 0;
}

// 0x122a210
void sdfSetPacketHeader(sdfGrPacketHeader_t *aHdr, s32 aSize) {
  ;
}

// 0x122a2a0
void sdfSetPacketHeaderN(sdfGrPacketHeader_t *aHdr, s32 n) {
  ;
}
