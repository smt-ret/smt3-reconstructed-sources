#include "types.h"

typedef struct sdfPkt_GIFTAG_PARM_t sdfPkt_GIFTAG_PARM_t;
typedef struct sdfPkt_GS_ALPHA_t sdfPkt_GS_ALPHA_t;
typedef struct sdfPkt_GS_CLAMP_t sdfPkt_GS_CLAMP_t;
typedef struct sdfPkt_GS_PRIM_t sdfPkt_GS_PRIM_t;
typedef struct sdfPkt_GS_RGBAQ_t sdfPkt_GS_RGBAQ_t;
typedef struct sdfPkt_GS_TEST_t sdfPkt_GS_TEST_t;
typedef struct sdfPkt_GS_XYZ2_t sdfPkt_GS_XYZ2_t;
typedef struct sdfPrm sdfPrm;

struct sdfPkt_GIFTAG_PARM_t {
    u8 flg;
    u8 nreg;
    u8 pre;
    u8 pad;
    u16 nloop;
    u16 prim;
    u32 eop;
};

struct sdfPkt_GS_ALPHA_t {
    u8 a;
    u8 b;
    u8 c;
    u8 d;
    s32 fix;
};

struct sdfPkt_GS_CLAMP_t {
    u8 wms;
    u8 wmt;
    u16 minu;
    u16 maxu;
    u16 minv;
    u16 maxv;
};

struct sdfPkt_GS_PRIM_t {
    u8 prim;
    u8 iip;
    u8 tme;
    u8 fge;
    u8 abe;
    u8 aa1;
    u8 fst;
    u8 ctx;
    u8 fix;
};

struct sdfPkt_GS_RGBAQ_t {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
    s32 q;
};

struct sdfPkt_GS_TEST_t {
    u8 ate;
    u8 atst;
    u8 aref;
    u8 afail;
    u8 date;
    u8 datm;
    u8 zte;
    u8 pad;
    u32 ztst;
};

struct sdfPkt_GS_XYZ2_t {
    u16 x;
    u16 y;
    u32 z;
};

// 0x17a6c00
u8 SDF_DMA_ID(u8 irq, u8 id, u8 pce) {
  return (16 * id) | (irq << 7) | (4 * pce);
}

// 0x17a6c10
u64 SDF_DMA_TAG(u16 qwc, u16 id, u32 type) {
  return qwc | type | (id << 24);
}

// 0x17a6120
u64 SDF_GIFTAG_PARM(u16 nloop, u32 eop, u8 pre, u16 prim, u8 flg, u8 nreg) {
  return nloop | (eop << 15) | (pre << 46) | (prim << 47) | (flg << 58) | (nreg << 60);
}

// 0x17a6150
sdfPkt_GIFTAG_PARM_t SDF_GIFTAG_PARM_24797520(u64 data) {
  u64 v2;
  sdfPkt_GIFTAG_PARM_t_o result;

  v2 = (data >> 15) & 0x7FFFFFFF;
  *&result.flg = (2 * data) & 0x7FF000000000000LL
                      | ((data & 0x7FFF) << 32)
                      | (data >> 30) & 0x10000
                      | (data >> 52) & 0x700
                      | (data >> 58) & 3;
  result.eop = v2;
  return result;
}

// 0x17a6870
u64 SDF_GIFTAG_REGS1(s32 r0) {
  u64 result;

  *&r0 = r0;
  LODWORD(result) = r0;
  return result;
}

// 0x17a6980
u64 SDF_GIFTAG_REGS10(s32 r0, s32 r1, s32 r2, s32 r3, s32 r4, s32 r5, s32 r6, s32 r7, s32 r8, s32 r9) {
  return r0 | (16 * r1) | (r2 << 8) | (r3 << 12) | (r4 << 16) | (r5 << 20) | (r6 << 24) | (r7 << 28) | r8 | (16 * r9);
}

// 0x17a69c0
u64 SDF_GIFTAG_REGS11(s32 r0, s32 r1, s32 r2, s32 r3, s32 r4, s32 r5, s32 r6, s32 r7, s32 r8, s32 r9, s32 r10) {
  return r0
       | (16 * r1)
       | (r2 << 8)
       | (r3 << 12)
       | (r4 << 16)
       | (r5 << 20)
       | (r6 << 24)
       | (r7 << 28)
       | r8
       | (16 * r9)
       | (r10 << 8);
}

// 0x17a6a00
u64 SDF_GIFTAG_REGS12(s32 r0, s32 r1, s32 r2, s32 r3, s32 r4, s32 r5, s32 r6, s32 r7, s32 r8, s32 r9, s32 r10, s32 r11) {
  return r0
       | (16 * r1)
       | (r2 << 8)
       | (r3 << 12)
       | (r4 << 16)
       | (r5 << 20)
       | (r6 << 24)
       | (r7 << 28)
       | r8
       | (16 * r9)
       | (r10 << 8)
       | (r11 << 12);
}

// 0x17a6a50
u64 SDF_GIFTAG_REGS13(s32 r0, s32 r1, s32 r2, s32 r3, s32 r4, s32 r5, s32 r6, s32 r7, s32 r8, s32 r9, s32 r10, s32 r11, s32 r12) {
  return r0
       | (16 * r1)
       | (r2 << 8)
       | (r3 << 12)
       | (r4 << 16)
       | (r5 << 20)
       | (r6 << 24)
       | (r7 << 28)
       | r8
       | (16 * r9)
       | (r10 << 8)
       | (r11 << 12)
       | (r12 << 16);
}

// 0x17a6aa0
u64 SDF_GIFTAG_REGS14(s32 r0, s32 r1, s32 r2, s32 r3, s32 r4, s32 r5, s32 r6, s32 r7, s32 r8, s32 r9, s32 r10, s32 r11, s32 r12, s32 r13) {
  return r0
       | (16 * r1)
       | (r2 << 8)
       | (r3 << 12)
       | (r4 << 16)
       | (r5 << 20)
       | (r6 << 24)
       | (r7 << 28)
       | r8
       | (16 * r9)
       | (r10 << 8)
       | (r11 << 12)
       | (r12 << 16)
       | (r13 << 20);
}

// 0x17a6b00
u64 SDF_GIFTAG_REGS15(s32 r0, s32 r1, s32 r2, s32 r3, s32 r4, s32 r5, s32 r6, s32 r7, s32 r8, s32 r9, s32 r10, s32 r11, s32 r12, s32 r13, s32 r14) {
  return r0
       | (16 * r1)
       | (r2 << 8)
       | (r3 << 12)
       | (r4 << 16)
       | (r5 << 20)
       | (r6 << 24)
       | (r7 << 28)
       | r8
       | (16 * r9)
       | (r10 << 8)
       | (r11 << 12)
       | (r12 << 16)
       | (r13 << 20)
       | (r14 << 24);
}

// 0x17a6b60
u64 SDF_GIFTAG_REGS16(s32 r0, s32 r1, s32 r2, s32 r3, s32 r4, s32 r5, s32 r6, s32 r7, s32 r8, s32 r9, s32 r10, s32 r11, s32 r12, s32 r13, s32 r14, s32 r15) {
  return r0
       | (16 * r1)
       | (r2 << 8)
       | (r3 << 12)
       | (r4 << 16)
       | (r5 << 20)
       | (r6 << 24)
       | (r7 << 28)
       | r8
       | (16 * r9)
       | (r10 << 8)
       | (r11 << 12)
       | (r12 << 16)
       | (r13 << 20)
       | (r14 << 24)
       | (r15 << 28);
}

// 0x17a6880
u64 SDF_GIFTAG_REGS2(s32 r0, s32 r1) {
  return r0 | (16 * r1);
}

// 0x17a6890
u64 SDF_GIFTAG_REGS3(s32 r0, s32 r1, s32 r2) {
  return r0 | (16 * r1) | (r2 << 8);
}

// 0x17a68a0
u64 SDF_GIFTAG_REGS4(s32 r0, s32 r1, s32 r2, s32 r3) {
  return r0 | (16 * r1) | (r2 << 8) | (r3 << 12);
}

// 0x17a68c0
u64 SDF_GIFTAG_REGS5(s32 r0, s32 r1, s32 r2, s32 r3, s32 r4) {
  return r0 | (16 * r1) | (r2 << 8) | (r3 << 12) | (r4 << 16);
}

// 0x17a68e0
u64 SDF_GIFTAG_REGS6(s32 r0, s32 r1, s32 r2, s32 r3, s32 r4, s32 r5) {
  return r0 | (16 * r1) | (r2 << 8) | (r3 << 12) | (r4 << 16) | (r5 << 20);
}

// 0x17a6900
u64 SDF_GIFTAG_REGS7(s32 r0, s32 r1, s32 r2, s32 r3, s32 r4, s32 r5, s32 r6) {
  return r0 | (16 * r1) | (r2 << 8) | (r3 << 12) | (r4 << 16) | (r5 << 20) | (r6 << 24);
}

// 0x17a6920
u64 SDF_GIFTAG_REGS8(s32 r0, s32 r1, s32 r2, s32 r3, s32 r4, s32 r5, s32 r6, s32 r7) {
  return r0 | (16 * r1) | (r2 << 8) | (r3 << 12) | (r4 << 16) | (r5 << 20) | (r6 << 24) | (r7 << 28);
}

// 0x17a6950
u64 SDF_GIFTAG_REGS9(s32 r0, s32 r1, s32 r2, s32 r3, s32 r4, s32 r5, s32 r6, s32 r7, s32 r8) {
  return r0 | (16 * r1) | (r2 << 8) | (r3 << 12) | (r4 << 16) | (r5 << 20) | (r6 << 24) | (r7 << 28) | r8;
}

// 0x17a6810
void SDF_GIF_SET_FOG(sdfPrm **pkt, s32 *index, u16 fog) {
  s64 v4;

  v4 = *index;
  *(&pkt->m_Items[0].l + 4 * v4 + 3) = fog;
  ++*index;
}

// 0x17a62f0
void SDF_GIF_SET_PRIM(sdfPrm **pkt, s32 *index, u64 prim) {
  s64 v4;

  v4 = *index;
  *index = v4 + 1;
  *(&pkt->m_Items[0].l + v4) = prim;
}

// 0x17a6350
void SDF_GIF_SET_RGBA(sdfPrm **pkt, s32 *index, u8 r, u8 g, u8 b, u8 a) {
  s64 v7;
  s64 v9;
  s64 v11;
  s64 v13;

  v7 = *index;
  *(&pkt->m_Items[0].l + 2 * v7) = r;
  v9 = *index;
  *(&pkt->m_Items[0].l + 2 * v9 + 1) = g;
  v11 = *index + 1LL;
  *index = v11;
  *(&pkt->m_Items[0].l + 2 * v11) = b;
  v13 = *index;
  *(&pkt->m_Items[0].l + 2 * v13 + 1) = a;
  ++*index;
}

// 0x17a6460
void SDF_GIF_SET_STQ(sdfPrm **pkt, s32 *index, f32 s, f32 t, f32 q) {
  s64 v6;
  s64 v8;
  s64 v10;

  v6 = *index;
  *(&pkt->m_Items[0].l + 2 * v6) = s;
  v8 = *index;
  *(&pkt->m_Items[0].l + 2 * v8 + 1) = t;
  v10 = *index + 1LL;
  *index = v10;
  *(&pkt->m_Items[0].l + 2 * v10) = q;
  ++*index;
}

// 0x17a6530
void SDF_GIF_SET_UV(sdfPrm **pkt, s32 *index, s32 u, s32 v) {
  s64 v5;
  s64 v7;

  v5 = *index;
  *(&pkt->m_Items[0].l + 2 * v5) = u;
  v7 = *index;
  *(&pkt->m_Items[0].l + 2 * v7 + 1) = v;
  ++*index;
}

// 0x17a6700
void SDF_GIF_SET_XYZ2(sdfPrm **pkt, s32 *index, s32 x, s32 y, u16 z, u16 adc) {
  s64 v7;
  s64 v9;
  s64 v11;
  s64 v13;

  v7 = *index;
  *(&pkt->m_Items[0].l + 2 * v7) = x;
  v9 = *index;
  *(&pkt->m_Items[0].l + 2 * v9 + 1) = y;
  v11 = *index + 1LL;
  *index = v11;
  *(&pkt->m_Items[0].l + 2 * v11) = z;
  v13 = *index;
  *(&pkt->m_Items[0].l + 2 * v13 + 1) = adc;
  ++*index;
}

// 0x17a65d0
void SDF_GIF_SET_XYZF2(sdfPrm **pkt, s32 *index, f32 x, f32 y, u16 z, u16 f, u16 adc) {
  s64 v8;
  s64 v10;
  s64 v12;
  s64 v14;
  s64 v16;

  v8 = *index;
  *(&pkt->m_Items[0].l + 2 * v8) = x;
  v10 = *index;
  *(&pkt->m_Items[0].l + 2 * v10 + 1) = y;
  v12 = *index + 1LL;
  *index = v12;
  *(&pkt->m_Items[0].l + 4 * v12) = z;
  v14 = *index;
  *(&pkt->m_Items[0].l + 4 * v14 + 1) = f;
  v16 = *index;
  *(&pkt->m_Items[0].l + 4 * v16 + 2) = adc;
  ++*index;
}

// 0x17a61d0
u64 SDF_GS_SET_ALPHA(u8 a, u8 b, u8 c, u8 d, s32 fix) {
  return a | (4 * b) | (16 * c) | (d << 6) | (fix << 32);
}

// 0x17a6200
u64 SDF_GS_SET_CLAMP(u8 wms, u8 wmt, u16 minu, u16 maxu, u16 minv, u16 maxv) {
  return wms | (4LL * wmt) | (16LL * minu) | (maxu << 15) | (minv << 26) | (maxv << 37);
}

// 0x17a6230
s32 SDF_GS_SET_PRIM(u8 prim, u8 iip, u8 tme, u8 fge, u8 abe, u8 aa1, u8 fst, s32 ctx, u8 fix) {
  return prim | (8 * iip) | (16 * tme) | (32 * fge) | (abe << 6) | (aa1 << 7) | (ctx << 9) | (fst << 8) | (fix << 10);
}

// 0x17a6280
u64 SDF_GS_SET_RGBAQ(u8 r, u8 g, u8 b, u8 a, s32 q) {
  return r | (g << 8) | (b << 16) & 0xFFFFFF | (a << 24) | (q << 32);
}

// 0x17a62a0
u64 SDF_GS_SET_TEST(u8 ate, u8 atst, u8 aref, u8 afail, u8 date, u8 datm, u8 zte, u32 ztst) {
  return ate
       | ((2 * atst) & 0xFFF)
       | (16 * aref) & 0xFFF
       | (afail << 12)
       | (date << 14)
       | (datm << 15)
       | (zte << 16)
       | (ztst << 17);
}

// 0x17a62e0
u64 SDF_GS_SET_XYZ2(u16 x, u16 y, u32 z) {
  return x | (y << 16) | (z << 32);
}

// 0x17a6bd0
u16 SDF_MAKE16(u8 l, u8 h) {
  return l | (h << 8);
}

// 0x17a6be0
u32 SDF_MAKE32(u16 l, u16 h) {
  return l | (h << 16);
}

// 0x17a6bf0
u64 SDF_MAKE64(u32 l, u32 h) {
  return h | l;
}

// 0x17a6100
u32 SDF_VIF_SET_DIRECT(u32 size) {
  return size | 0x50000000;
}

// 0x17a6110
u32 SDF_VIF_SET_DIRECTHL(u32 size) {
  return size | 0x51000000;
}

// 0x17956d0
u32 SDF_VIF_SET_ITOP(u32 addr) {
  return addr | 0x4000000;
}

// 0x17956e0
u32 SDF_VIF_SET_MSCAL(u32 addr) {
  return addr | 0x14000000;
}

// 0x17956b0
u32 SDF_VIF_SET_UNPACK(s32 typ, s32 m, s32 usn, s32 flg, s32 addr, s32 size) {
  return (typ << 24) | (m << 28) | (usn << 14) | (flg << 15) | addr | (size << 16) | 0x60000000;
}
