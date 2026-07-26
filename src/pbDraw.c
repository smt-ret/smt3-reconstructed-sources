#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct XRD773Unity_CommonMesh XRD773Unity_CommonMesh;
typedef struct XRD773Unity_GraphicManager XRD773Unity_GraphicManager;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct pbProcHandle_t pbProcHandle_t;
typedef struct sdf3DPrimPolyParm_t sdf3DPrimPolyParm_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfMat_t sdfMat_t;

static sdfVector4_t blk_base_vert[36];
static sdfVector4_t blk_base_norm[36];
static sdfVector4_t blockNormal[10];
static sdfVector2_t uvFloor[4];
static s32 PB_BLOCK_LENGTH_H;
static s32 PB_BLOCK;
static s32 PB_BLOCK_W;
static s32 PB_BLOCK_W2;
static s32 PB_BLOCK_LENGTH_W;
static f32 PB_BLOCK_A;
static u32 blockColor[7];
static u8 blockVertIndex[60];
static sdfVector4_t blockVert[UNKNOWN_ARRAY_SIZE];
static s32 blk_max;
static s32 pBlk_MeshCnt;
static XRD773Unity_CommonMesh pBlk_Mesh[UNKNOWN_ARRAY_SIZE];
static XRD773Unity_CommonMesh pMRBlk_Mesh[UNKNOWN_ARRAY_SIZE];
static XRD773Unity_CommonMesh *pGoalBlk_Mesh;
static sdfVector3_t pBlk_MeshPos;
static sdfVector3_t pMRBlk_MeshPos;
static sdfVector3_t pGoalBlk_MeshPos;
static void *pBlk_GameObj;
static void *pMRBlk_GameObj;
static void *pMBlk_GameObj;
static s32 overBlkflg;
static s32 goalBlkflag;
static f32 grot;
static s32 faceCnt;
static s32 autLineCnt;
static s32 autLineDeleteCnt;
static s32 autLineDeleteflag;
static s32 autLineDrawflag;
static sdfVector3_t BaseTrans;
static sdfVector3_t BaseOffset;
static s32 returnMRblk;
static s32 flag1;
static s32 flag2;
static s32 flag3;
static s32 flag4;
static s32 kakekari;
static s32 kakekaris;
static s32 kakekarisCnt;
static s32 kakekariflag;
static s32 pbObjflag;
static s32 pbBlkDalateflag;
static s32 pbmBlkDalateflag;
static XRD773Unity_CommonMesh *allMesh;
static sdfVector3_t fBlkPosbup[UNKNOWN_ARRAY_SIZE];
static s32 fBlkPosbupCnt;
static s32 fBlk_allCnt;
static s32 fBlk_allCntbup;
static XRD773Unity_CommonMesh *allwMesh;
static sdfVector3_t wBlkPosbup[UNKNOWN_ARRAY_SIZE];
static s32 wBlkPosbupCnt;
static s32 wBlk_allCnt;
static s32 *widxbup[UNKNOWN_ARRAY_SIZE];
static u8 *facebup[UNKNOWN_ARRAY_SIZE];
static XRD773Unity_CommonMesh allmMesh[UNKNOWN_ARRAY_SIZE];
static sdfVector3_t *mBlkPosbup[UNKNOWN_ARRAY_SIZE];
static s32 mBlkPosbupCnt;
static s32 mBlk_allCnt;
static s32 mBlk_grpCnt;
static s32 mBlk_grpnumCnt[20];
static s16 mBlk_grpID[UNKNOWN_ARRAY_SIZE];
static s32 mBlk_grpIDCnt;
static s32 mBlk_Resetflag;
static s32 mBlk_AllDalate;
static XRD773Unity_CommonMesh allrMesh[UNKNOWN_ARRAY_SIZE];
static sdfVector3_t *rBlkPosbup[UNKNOWN_ARRAY_SIZE];
static s32 rBlkPosbupCnt;
static s32 rBlk_allCnt;
static s32 rBlk_grpCnt;
static s32 rBlk_grpnumCnt[UNKNOWN_ARRAY_SIZE];
static XRD773Unity_CommonMesh *allw2Mesh;
static sdfVector3_t w2BlkPosbup[UNKNOWN_ARRAY_SIZE];
static s32 w2BlkPosbupCnt;
static s32 w2Blk_allCnt;
static s32 *w2idxbup[UNKNOWN_ARRAY_SIZE];
static u8 *facebup2[UNKNOWN_ARRAY_SIZE];
static XRD773Unity_CommonMesh *BGImage;
static sdfVector3_t BGImagePos;
static s32 BGflag;
static bool StageDrawflag;
static bool MRBlockDrawflag;
static bool WallChangeflag;
static s32 RBlockOutCnt;
static bool RBlockOutDrawFlag;
static char RBlockStrbup[UNKNOWN_ARRAY_SIZE];
static s32 MBlockOutCnt;
static bool MBlockOutDrawFlag;
static char MBlockStrbup[UNKNOWN_ARRAY_SIZE];
static f32 Gcol;
static bool GcolZ;
static sdfVector3_t *autLinePos[UNKNOWN_ARRAY_SIZE];
static s32 aut_line_a;
static s32 aut_line_b;
static s32 autline_type;
static sdfVector3_t outline_vec3;
static s32 outlineDrawflag;
static s32 BlkInitflag;
static s32 NBlkDrawflag;
static sdfVector3_t allwpos[UNKNOWN_ARRAY_SIZE];
static sdfVector3_t allw2pos[UNKNOWN_ARRAY_SIZE];
static s32 allwidx[UNKNOWN_ARRAY_SIZE];
static sdfColor_t allwcolor[UNKNOWN_ARRAY_SIZE];
static sdfVector2_t alluvwpos[UNKNOWN_ARRAY_SIZE];
static sdfVector2_t alluvw2pos[UNKNOWN_ARRAY_SIZE];
static sdfVector3_t npos[24];
static sdfVector3_t autPos[UNKNOWN_ARRAY_SIZE];
static sdfVector3_t WallautPos[UNKNOWN_ARRAY_SIZE];
static sdfVector3_t wpos[UNKNOWN_ARRAY_SIZE];
static sdfVector3_t wpos2[UNKNOWN_ARRAY_SIZE];
static sdfVector3_t gpos[UNKNOWN_ARRAY_SIZE];
static sdfVector3_t bgpos[UNKNOWN_ARRAY_SIZE];
static s32 idx[36];
static s32 widx[UNKNOWN_ARRAY_SIZE];
static s32 *widx2[4];
static s32 widx3[24];
static s32 bgidx[6];
static void *Line3D;
static sdfVector4_t drawExit_angle;
static sdfColor_t DefblockCol;
static sdfVector2_t move_uvpos[24];
static sdfVector2_t flor_uvpos[24];
static sdfVector2_t wall_uvpos[16];
static sdfVector2_t wall_uvpos2[16];
static sdfVector2_t rnd_uvpos[24];
static sdfVector2_t rcore_uvpos[24];
static sdfVector2_t BG_uvpos[4];

void AutLineDraw(void **parent, char *pName, char *cName, u32 col, s32 size, sdfVector3_t **pos);
void BlkAllDalate(void);
XRD773Unity_CommonMesh *GetMesh(XRD773Unity_GraphicManager *this, s32 index, bool outlinechk);
sdfColor_t GetRgbColor(u32 color);
void InitDrawMapBase(pbProcHandle_t **p);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
sdfVector4_t SDF_VU0__Retdds3ColorItoF(u32 rgba, f32 ratio);
void SetColor_20241296(XRD773Unity_CommonMesh *this, sdfColor_t **col);
void SetIndexTable(XRD773Unity_CommonMesh *this, s32 **idx);
void SetMatTexture(XRD773Unity_CommonMesh *this, void *texture);
void SetPosition_20241056(XRD773Unity_CommonMesh *this, sdfVector3_t **pos);
void SetUvTable_20243232(XRD773Unity_CommonMesh *this, sdfVector2_t **pos);
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
void dds3SetProcessData(dds3ProcessID_t **id, void *data);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
u32 drawBlock(sdfVector4_t offset, u8 face, u32 type, sdfDrawTag_t **drTag);
u32 drawBlock2(s32 x, s32 y, u8 face, u32 type, sdfDrawTag_t **drTag);
void drawMapPanel(sdfVector4_t offset, sdfDrawTag_t **drTag);
void linkTM(sdfVector4_t angle, sdfVector4_t trans, sdfDrawTag_t **drTag);
u16 pb_General__GET_MAP_BLK_(s32 x, s32 y);
s32 pb_General__GET_MAP_HALL_(s32 x, s32 y);
s32 pb_General__PB_PROC_REF_MESS(pbProcHandle_t *p);
void pb_General__PB_PROC_SEND_MESS(pbProcHandle_t *p, s32 mes);
s32 sdfDrawTagInit(sdfDrawTag_t *a);
void sdfMatSetDiffuse(sdfMat_t *aMat, u32 aColor);
void sdfVu0LoadMatrix(sdfMatrix4_t *aMatrix);
void sdfVu0StoreMatrix(sdfMatrix4_t *aMatrix);

// 0x16529b0
void AutLineDraw(void **parent, char *pName, char *cName, u32 col, s32 size, sdfVector3_t **pos) {
    GetRgbColor(0);
    LoadPrefab_16624656(0, 0, 0, 0);
}

// 0x1653900
void AutLineFree(void) {
  PropertySheet___Clear(Line3D);
}

// 0x16527b0
void BlkAllDalate(void) {
  s64 i;
  struct XRD773Unity_CommonMesh_array *pMRBlk_Mesh;
  struct pbDraw_StaticFields *static_fields;
  u64 v6;
  UnityEngine_Object_o *v8;
  struct XRD773Unity_CommonMesh_array *v10;
  UnityEngine_Object_o *gameObject;
  struct XRD773Unity_CommonMesh_array *v15;

  for (i = 4; i != 404; ++i)
  {
    while (1)
    {
        break;
      static_fields = pbDraw->static_fields;
      if (static_fields->pbBlkDalateflag == 1)
      if (++i == 404)
    }
    static_fields = pbDraw->static_fields;
    if (static_fields->pbBlkDalateflag != 1)
    v6 = i - 4;
    else
    {
      pMRBlk_Mesh = static_fields->pMRBlk_Mesh;
    }
    v8 = *(&pMRBlk_Mesh->obj.klass + i);
    if (!op_Inequality(v8, 0, 0))
    v10 = pMRBlk_Mesh;
    gameObject = get_gameObject(*(&v10->obj.klass + i), 0);
    Destroy_27360000(gameObject);
  }
  v15 = NewSpecific(XRD773Unity_CommonMesh, 0x190u);
  pMRBlk_Mesh = v15;
  pbBlkDalateflag = 0;
}

// 0x16513e0
void InitDrawMapBase(pbProcHandle_t **p) {
}

// 0x164fdb0
dds3ProcessFunc_t *deleteExit(dds3ProcessID_t *id) {
    return 0;
}

// 0x1650ee0
dds3ProcessFunc_t *deleteMapBase(dds3ProcessID_t *id) {
    return 0;
}

// 0x1646100
u32 drawBlock(sdfVector4_t offset, u8 face, u32 type, sdfDrawTag_t **drTag) {
    SDF_VU0__Retdds3ColorItoF(0, 0);
    BlkAllDalate();
    GetMesh(0, 0, 0);
    SetPosition_20241056(0, 0);
    SetIndexTable(0, 0);
    SetColor_20241296(0, 0);
    SetMatTexture(0, 0);
    AutLineDraw(0, 0, 0, 0, 0, 0);
    SetUvTable_20243232(0, 0);
    return 0;
}

// 0x1650a10
u32 drawBlock2(s32 x, s32 y, u8 face, u32 type, sdfDrawTag_t **drTag) {
    drawBlock((sdfVector4_t){0}, 0, 0, 0);
    return 0;
}

// 0x1645b60
dds3ProcessFunc_t *drawExit(dds3ProcessID_t *id) {
    pb_General__PB_PROC_REF_MESS(0);
    pb_General__PB_PROC_SEND_MESS(0, 0);
    sdfDrawTagInit(0);
    linkTM((sdfVector4_t){0}, (sdfVector4_t){0}, 0);
    drawBlock((sdfVector4_t){0}, 0, 0, 0);
    return 0;
}

// 0x164ff50
dds3ProcessFunc_t *drawMapBase(dds3ProcessID_t *id) {
    pb_General__PB_PROC_REF_MESS(0);
    pb_General__PB_PROC_SEND_MESS(0, 0);
    sdfDrawTagInit(0);
    pb_General__GET_MAP_HALL_(0, 0);
    pb_General__GET_MAP_BLK_(0, 0);
    drawBlock2(0, 0, 0, 0, 0);
    return 0;
}

// 0x16522c0
void drawMapPanel(sdfVector4_t offset, sdfDrawTag_t **drTag) {
}

// 0x1652680
void drawMapPanel2(s32 x, s32 y, sdfDrawTag_t **drTag) {
    linkTM((sdfVector4_t){0}, (sdfVector4_t){0}, 0);
    drawMapPanel((sdfVector4_t){0}, 0);
}

// 0x1646040
void linkTM(sdfVector4_t angle, sdfVector4_t trans, sdfDrawTag_t **drTag) {
  u64 *v4;

  v4 = Allocate(sdfMatrix4_t);
  sdfMatrix4_t___ctor(v4);
  NewSpecific(f32, 1u);
  NewSpecific(float__, 5u);
  sdfVu0StoreMatrix(v4);
  sdfVu0LoadMatrix(v4);
}

// 0x1651520
u8 pbCheckDrawFace(s16 x, s16 y, u32 type) {
  u64 *v7;
  u64 *v8;
  u64 *v9;
  u64 *v12;
  u64 *v13;
  u64 *v16;
  u64 *v17;
  u64 *v20;
  u64 *v21;
  pbDraw_c *v25;
  struct pbDraw_StaticFields *static_fields;
  struct System_Byte_array_array *facebup;
  s64 wBlk_allCnt;
  s64 *v29;
  s64 *v31;
  u16 v34;
  u64 v41;
  u16 v42;
  u64 *v43;
  s64 v44;
  s32 v45;
  s64 v47;
  u32 v48;
  s32 v50;
  s32 v51;
  s64 v52;
  s64 v53;
  s32 v54;
  s64 v62;
  s64 v63;
  s32 v70;
  pbDraw_c *v71;
  u32 v72;
  struct pbDraw_StaticFields *v73;
  struct System_Byte_array_array *v74;
  s64 v75;
  System_Byte_array *v77;
  u16 v79;
  System_Array_o *v80;
  System_Array_o *v81;
  s32 v82;
  s32 v83;

  v7 = NewSpecific(sbyte__, 4u);
  v8 = NewSpecific(sbyte, 2u);
  v9 = v8;
  *(v8 + 32) = 1;
  v7[4] = v9;
  v12 = NewSpecific(sbyte, 2u);
  v13 = v12;
  *(v12 + 32) = -1;
  v7[5] = v13;
  v16 = NewSpecific(sbyte, 2u);
  v17 = v16;
  *(v16 + 33) = 1;
  v7[6] = v17;
  v20 = NewSpecific(sbyte, 2u);
  v21 = v20;
  *(v20 + 33) = -1;
  v7[7] = v21;
  v81 = NewSpecific(uint, 4u);
  InitializeArray_1543888(v81, Field__PrivateImplementationDetails__F3F9294DA5DA053B94714084B5441D382C9D5B5A);
  static_fields = v25->static_fields;
  facebup = static_fields->facebup;
  wBlk_allCnt = static_fields->wBlk_allCnt;
  v29 = NewSpecific(byte, 4u);
  v31 = v29;
  facebup->m_Items[wBlk_allCnt] = v31;
  v34 = pb_General__GET_MAP_BLK_(x, y);
  if (!type)
  {
    if (!pb_General__GET_MAP_HALL_(x, y))
    {
      v83 = v34 == 0;
      v79 = v34;
    }
    return 0;
  }
  if (type != 1)
  {
    v79 = v34;
    v83 = 0;
  }
  if (!v34)
    return 0;
  v79 = v34;
  v83 = 1;
  v41 = 0;
  v42 = 0;
  v43 = v7 + 4;
  v82 = 0;
  v80 = v81 + 2;
  do
  {
    while (1)
    {
      v44 = v43[v41];
      v45 = *(v44 + 32);
      v47 = v43[v41];
      v48 = type;
      v50 = *(v47 + 33) + y;
      if (v50 <= 19)
      {
        v51 = v45 + x;
        if (v51 <= 19 && ((v50 | v51) & 0x80000000) == 0)
        {
          v42 = pb_General__GET_MAP_BLK_(v51, v50);
          v82 = pb_General__GET_MAP_HALL_(v51, v50);
        }
      }
      v52 = v43[v41];
      type = v48;
      if (*(v52 + 32) + x < 0)
      v53 = v43[v41];
      if (*(v53 + 32) + x >= 20)
      {
        v54 = 1;
      }
      else
      {
        v54 = 0;
        if (v41 >= *(v7 + 6))
      }
      v62 = v43[v41];
      if (*(v62 + 33) + y < 0)
      v63 = v43[v41];
      if (*(v63 + 33) + y >= 20)
      {
        v54 = 1;
        if (!v48)
        {
          if (v54)
          if (v82)
          {
            v83 |= (0x10000 << *(&v80->klass + v41)) >> 16;
          }
          if ((v79 || v42 != 1) && v79 < 2u)
          break;
        }
      }
      else      if (v48 != 1)
      {
        if (v42 != 1 && !v54)
        {
          v70 = *(&v80->klass + v41);
          v72 = 0x10000 << v70;
          v73 = v71->static_fields;
          v74 = v73->facebup;
          v75 = v73->wBlk_allCnt;
          v83 |= HIWORD(v72);
          v77 = v74->m_Items[v75];
          type = v48;
          v77->m_Items[v41] = v83;
        }
      }
      if (v42 <= 1u)
        break;
      if (++v41 == 4)
        return v83;
    }
    v83 |= (0x10000 << *(&v80->klass + v41++)) >> 16;
  }
  while (v41 != 4);
  return v83;
}

// 0x1651e10
u8 pbCheckDrawFace2(s16 x, s16 y, u32 type) {
  s32 v7;
  char v9;
  s32 v12;
  u16 v13;
  s32 v14;
  s32 v15;
  u16 v16;
  u8 v17;
  s32 v18;
  s32 v19;
  u16 v20;
  u8 v22;
  u16 v23;

  if (type)
  {
    v7 = x;
    if (pb_General__GET_MAP_BLK_(x, y))
    {
      v9 = 1;
    }
    return 0;
  }
  v7 = x;
  v9 = pb_General__GET_MAP_BLK_(x, y) == 0;
  if (pb_General__GET_MAP_HALL_(x, y))
    return 0;
  v12 = v7 + 1;
  if (v7 + 1 >= 20)
  {
    v9 |= 8u;
    if (x <= 0)
  }
  v13 = pb_General__GET_MAP_BLK_(v12, y);
  if (type)
  {
    if (type == 1)
    {
      if (v13 <= 1u)
        v9 |= 8u;
      if (x <= 0)
      v14 = v7 - 1;
      v15 = y;
      v16 = pb_General__GET_MAP_BLK_(v14, y);
      if (type)
      {
        if (type == 1)
        {
          if (v16 <= 1u)
            v17 = v9 | 0x10;
          else
            v17 = v9;
          v18 = y + 1;
          if (v18 >= 20)
        }
        else
        {
          if (v16)
            v17 = v9;
          else
            v17 = v9 | 0x10;
          pb_General__GET_MAP_HALL_(v14, y);
          v18 = y + 1;
          if (v18 >= 20)
        }
      }
      else
      {
        if (pb_General__GET_MAP_HALL_(v14, y))
          v17 = v9;
        else
          v17 = v9 | 0x10;
        v18 = y + 1;
        if (v18 >= 20)
      }
      v23 = pb_General__GET_MAP_BLK_(v7, v18);
      if (type)
      {
        if (type == 1)
        {
          if (v23 <= 1u)
            v17 |= 2u;
          if (y <= 0)
            return v17 | 4;
        }
        else
        {
          if (!v23)
            v17 |= 2u;
          pb_General__GET_MAP_HALL_(v7, v18);
          if (y <= 0)
            return v17 | 4;
        }
      }
      else
      {
        if (!pb_General__GET_MAP_HALL_(v7, v18))
          v17 |= 2u;
        if (y <= 0)
          return v17 | 4;
      }
    }
    if (!v13)
      v9 |= 8u;
    pb_General__GET_MAP_HALL_(v12, y);
    if (x > 0)
  }
  else
  {
    if (!pb_General__GET_MAP_HALL_(v12, y))
      v9 |= 8u;
    if (x > 0)
  }
  v17 = v9 | 0x10;
  v15 = y;
  v18 = y + 1;
  if (v18 < 20)
  v17 |= 2u;
  if (y <= 0)
    return v17 | 4;
  v19 = v15 - 1;
  v20 = pb_General__GET_MAP_BLK_(v7, v19);
  if (type)
  {
    if (type == 1)
    {
      if (v20 >= 2u)
        return v17;
      else
        return v17 | 4;
    }
    else
    {
      if (v20)
        v22 = v17;
      else
        v22 = v17 | 4;
      pb_General__GET_MAP_HALL_(v7, v19);
      return v22;
    }
  }
  else
  {
    if (pb_General__GET_MAP_HALL_(v7, v19))
      return v17;
    else
      return v17 | 4;
  }
}

// 0x1653dc0
u32 pbGetExitDisp(pbProcHandle_t **p, s8 sw) {
    return 0;
}

// 0x1651510
void pbInitBlockNormal(void) {
  ;
}

// 0x1653980
pbProcHandle_t *pbInitExitDraw(pbProcHandle_t **parent) {
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
    dds3LinkProcess(0, 0);
    pb_General__PB_PROC_SEND_MESS(0, 0);
    dds3SetProcessData(0, 0);
    sdfMatSetDiffuse(0, 0);
    return 0;
}

// 0x1653ed0
pbProcHandle_t *pbInitMapBaseDraw(pbProcHandle_t **parent, u32 sw) {
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
    dds3LinkProcess(0, 0);
    pb_General__PB_PROC_SEND_MESS(0, 0);
    dds3SetProcessData(0, 0);
    InitDrawMapBase(0);
    return 0;
}

// 0x1653d00
void pbSetExitDisp(pbProcHandle_t **p, s8 sw) {
  u64 *v4;
  u64 *v5;

  v4 = Allocate(pbExit_t);
  v5 = Allocate(sdfMat_t);
  sdfMat_t___ctor(v5);
  v4[3] = v5;
  _ctor(v4, 0);
  *(v4 + 4) = sw;
}

// 0x1653eb0
void pbSetExitPos(pbProcHandle_t **p, s16 x, s16 y) {
  (*p)->x = x;
  (*p)->y = y;
}

// 0x1654170
void pbSetFlagMapBaseDraw(pbProcHandle_t **p, u32 flag) {
}

// 0x1645b50
s32 sdf3DPrimLinkPoly(sdfDrawTag_t *a, sdf3DPrimPolyParm_t *b) {
  return 0;
}

// 0x1645b40
s32 sdfChipFreeDelayed(void *a) {
  return 0;
}
