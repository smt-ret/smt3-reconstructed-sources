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
static sdfVector4_t *blockVert;
static s32 blk_max;
static s32 pBlk_MeshCnt;
static XRD773Unity_CommonMesh *pBlk_Mesh;
static XRD773Unity_CommonMesh *pMRBlk_Mesh;
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
static sdfVector3_t *fBlkPosbup;
static s32 fBlkPosbupCnt;
static s32 fBlk_allCnt;
static s32 fBlk_allCntbup;
static XRD773Unity_CommonMesh *allwMesh;
static sdfVector3_t *wBlkPosbup;
static s32 wBlkPosbupCnt;
static s32 wBlk_allCnt;
static s32 **widxbup;
static u8 **facebup;
static XRD773Unity_CommonMesh *allmMesh;
static sdfVector3_t **mBlkPosbup;
static s32 mBlkPosbupCnt;
static s32 mBlk_allCnt;
static s32 mBlk_grpCnt;
static s32 mBlk_grpnumCnt[20];
static s16 *mBlk_grpID;
static s32 mBlk_grpIDCnt;
static s32 mBlk_Resetflag;
static s32 mBlk_AllDalate;
static XRD773Unity_CommonMesh *allrMesh;
static sdfVector3_t **rBlkPosbup;
static s32 rBlkPosbupCnt;
static s32 rBlk_allCnt;
static s32 rBlk_grpCnt;
static s32 *rBlk_grpnumCnt;
static XRD773Unity_CommonMesh *allw2Mesh;
static sdfVector3_t *w2BlkPosbup;
static s32 w2BlkPosbupCnt;
static s32 w2Blk_allCnt;
static s32 **w2idxbup;
static u8 **facebup2;
static XRD773Unity_CommonMesh *BGImage;
static sdfVector3_t BGImagePos;
static s32 BGflag;
static bool StageDrawflag;
static bool MRBlockDrawflag;
static bool WallChangeflag;
static s32 RBlockOutCnt;
static bool RBlockOutDrawFlag;
static char *RBlockStrbup;
static s32 MBlockOutCnt;
static bool MBlockOutDrawFlag;
static char *MBlockStrbup;
static f32 Gcol;
static bool GcolZ;
static sdfVector3_t **autLinePos;
static s32 aut_line_a;
static s32 aut_line_b;
static s32 autline_type;
static sdfVector3_t outline_vec3;
static s32 outlineDrawflag;
static s32 BlkInitflag;
static s32 NBlkDrawflag;
static sdfVector3_t *allwpos;
static sdfVector3_t *allw2pos;
static s32 *allwidx;
static sdfColor_t *allwcolor;
static sdfVector2_t *alluvwpos;
static sdfVector2_t *alluvw2pos;
static sdfVector3_t npos[24];
static sdfVector3_t *autPos;
static sdfVector3_t *WallautPos;
static sdfVector3_t *wpos;
static sdfVector3_t *wpos2;
static sdfVector3_t *gpos;
static sdfVector3_t *bgpos;
static s32 idx[36];
static s32 *widx;
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
  System_String_o *v13;
  UnityEngine_Object_o *v15;
  u64 *v17;
  UnityEngine_Transform_o *transform;
  UnityEngine_GameObject_o *v19;
  UnityEngine_Transform_o *v20;
  Il2CppObject *Item;
  AssetBundleCtrl_o *asset_bc;
  Il2CppObject *Prefab_16624656;
  UnityEngine_GameObject_o *v31;
  UnityEngine_Transform_o *v33;
  Il2CppObject *Component_object;
  AssetBundleCtrl_o *v38;
  Il2CppObject *v39;
  UnityEngine_GameObject_o *v40;
  UnityEngine_Transform_o *v42;
  Il2CppObject *v43;
  Il2CppObject *v47;
  s32 v48;
  u64 v49;
  f32 *p_z;
  u32 v51;
  u32 v52;
  s32 v53;
  u32 v54;
  u32 v55;
  s32 v56;
  u32 v58;
  u32 v59;
  s32 v60;
  u32 v61;
  u32 v62;
  s32 v63;
  u32 v64;
  u32 v65;
  s32 v66;
  u32 v67;
  u32 v68;
  s32 v69;
  u32 v70;
  u32 v71;
  s32 v72;
  u32 v73;
  u32 v74;
  s32 v75;
  s32 v80;
  s32 autline_type;
  struct XRD773Unity_CommonMesh_array *pMRBlk_Mesh;
  s64 pBlk_MeshCnt;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v91;
  f32 v95;
  f32 v97;
  f32 v98;
  f32 v99;
  f32 v100;
  f32 v105;
  u32 v108;
  u32 v109;
  s32 v110;
  f32 v113;
  s32 v115;
  f32 v117;
  f32 v118;
  u32 v119;
  u32 v120;
  s32 v121;
  f32 v123;
  f32 v125;
  s32 kakekari;
  f32 v127;
  s64 v129;
  f32 w;
  f32 z;
  f32 v135;
  f32 v136;
  f32 v137;
  struct XRD773Unity_CommonMesh_array *v139;
  s64 v140;
  UnityEngine_GameObject_o *v142;
  UnityEngine_Transform_o *v143;
  long f64 v145;
  long f64 v146;
  struct XRD773Unity_CommonMesh_array *v148;
  s64 v149;
  f32 v150;
  f32 v151;
  f32 v152;
  f32 v153;
  f32 v154;
  UnityEngine_GameObject_o *v156;
  UnityEngine_Transform_o *v157;
  System_Type_o *v159;
  UnityEngine_Matrix4x4_o v160;
  u64 v161;
  s32 v162;
  unsigned __int128 v163;
  UnityEngine_Quaternion_o v164;
  UnityEngine_Matrix4x4_o v165;
  UnityEngine_Vector3_o position;
  UnityEngine_Vector3_o v167;
  UnityEngine_Color_o RgbColor;
  UnityEngine_Quaternion_o rotation;
  UnityEngine_Vector3_o v170;
  UnityEngine_Vector3_o v171;
  UnityEngine_Vector3_o v172;
  UnityEngine_Vector3_o v173;
  UnityEngine_Quaternion_o v174;

  memset(&v165, 0, sizeof(v165));
  *&v164.x = 0;
  *&v164.z = 0;
  v163 = 0u;
  v162 = 0;
  v161 = 0;
  v13 = Concat_5224608("Field/", pName);
  v15 = Find(v13, 0);
  if (op_Equality(v15, 0, 0))
  {
    v17 = Allocate(UnityEngine_GameObject);
    _ctor(v17, pName, 0);
    *parent = v17;
    transform = get_transform(v17, 0);
    v19 = Find("Field", 0);
    v20 = get_transform(v19, 0);
    set_parent(transform, v20);
  }
  RgbColor = GetRgbColor(col);
  if (!Line3D)
    return;
  if (Animator___ContainsKey(Line3D, cName))
  {
    Item = object___get_Item(Line3D, cName);
      goto LABEL_39;
  }
  else
  {
    if (!pos || RgbColor.a == 0.0)
      return;
    asset_bc = get_asset_bc();
    Prefab_16624656 = LoadPrefab_16624656(asset_bc, "debug", "debug", "FldLine3D");
    v31 = Find(v13, 0);
    v33 = get_transform(v31, 0);
    Item = Instantiate_object__425520(Prefab_16624656, v33);
    set_name(Item, cName);
    Component_object = GetComponent_object_(Item);
    if (op_Equality(Component_object, 0, 0))
      AddComponent_object_(Item);
    PropertySheet___Add(Line3D, cName, Item);
      goto LABEL_39;
  }
LABEL_39:
  if (op_Equality(Item, 0, 0))
  {
    v38 = get_asset_bc();
    v39 = LoadPrefab_16624656(v38, "debug", "debug", "FldLine3D");
    v40 = Find(v13, 0);
    v42 = get_transform(v40, 0);
    Item = Instantiate_object__425520(v39, v42);
    set_name(Item, cName);
    v43 = GetComponent_object_(Item);
    if (op_Equality(v43, 0, 0))
      AddComponent_object_(Item);
    HashSet_Text____Remove(Line3D, cName);
    PropertySheet___Add(Line3D, cName, Item);
  }
  if (op_Inequality(Item, 0, 0))
  {
    v47 = GetComponent_object_(Item);
    set_startWidth(v47, 1.2);
    set_endWidth(v47, 1.2);
    set_startColor(v47, RgbColor);
    set_endColor(v47, RgbColor);
    v48 = NameToLayer("map");
    set_layer(Item, v48);
    set_positionCount(v47, size);
    if (size >= 1)
    {
      v49 = 0;
      p_z = &pos->m_Items[0].z;
      do
      {
        else
        {
          if (autline_type == 4)
            goto LABEL_90;
        }
        else if (autline_type != 5)
        {
          goto LABEL_110;
        }
LABEL_90:
        {
        }
        get_identity(&v160, 0);
        v165 = v160;
        gameObject = get_gameObject(pMRBlk_Mesh->m_Items[pBlk_MeshCnt]);
        v91 = get_transform(gameObject, 0);
        rotation = get_rotation(v91);
        v164 = rotation;
        v163 = 0u;
        sub_854710(&mrpb_angle, 1u);
        if (v95 != 0.0)
        {
          v164.z = 0.0;
          v164.x = 0.0;
          sub_854710(&mrpb_angle, 1u);
          if (v105 == 0.0)
            goto LABEL_148;
          if (kakekari != 15)
            goto LABEL_148;
          if (kakekariflag)
            goto LABEL_148;
          if (kakekaris == 1)
          {
            sub_1A1CAE0(&v164.x, 0);
            v161 = __PAIR64__(v109, v108);
            v162 = v110;
            if (sub_8527D0(&v161, 1) == 0.0)
              goto LABEL_130;
            sub_1A1CAE0(&v164.x, 0);
            v161 = __PAIR64__(v52, v51);
            v162 = v53;
            if (sub_8527D0(&v161, 1) <= 0.0
              || (sub_1A1CAE0(&v164.x, 0), v161 = __PAIR64__(v55, v54), v162 = v56, sub_8527D0(&v161, 1) > 90.0))
            {
              sub_1A1CAE0(&v164.x, 0);
              v161 = __PAIR64__(v59, v58);
              v162 = v60;
              if (sub_8527D0(&v161, 1) > 90.0
                && (sub_1A1CAE0(&v164.x, 0),
                    v161 = __PAIR64__(v62, v61),
                    v162 = v63,
                    sub_8527D0(&v161, 1) <= 180.0))
              {
                v80 = 90;
              }
              else
              {
                sub_1A1CAE0(&v164.x, 0);
                v161 = __PAIR64__(v65, v64);
                v162 = v66;
                if (sub_8527D0(&v161, 1) > 180.0
                  && (sub_1A1CAE0(&v164.x, 0),
                      v161 = __PAIR64__(v68, v67),
                      v162 = v69,
                      sub_8527D0(&v161, 1) <= 270.0))
                {
                  v80 = 180;
                }
                else
                {
                  sub_1A1CAE0(&v164.x, 0);
                  v161 = __PAIR64__(v71, v70);
                  v162 = v72;
                  if (sub_8527D0(&v161, 1) <= 270.0)
                    goto LABEL_135;
                  sub_1A1CAE0(&v164.x, 0);
                  v161 = __PAIR64__(v74, v73);
                  v162 = v75;
                  if (sub_8527D0(&v161, 1) > 360.0)
                    goto LABEL_135;
LABEL_130:
                  v80 = 270;
                }
              }
              kakekaris = v80;
              goto LABEL_135;
            }
            kakekaris = 0;
            {
LABEL_138:
              sub_854710(&mrpb_angle, 1u);
              if (v113 <= 0.0)
              {
                v115 = ((1240768329LL * kakekaris) >> 32) - kakekaris;
              }
              else
              {
                v115 = (3054198967LL * kakekaris) >> 32;
              }
              kakekari = (v115 >> 6) + (v115 >> 31);
LABEL_148:
              sub_854710(&mrpb_angle, 1u);
              v118 = v117;
              sub_1A1CAE0(&v164.x, 0);
              v161 = __PAIR64__(v120, v119);
              v162 = v121;
              v123 = sub_8527D0(&v161, 1);
              v125 = v123;
              if (v118 <= 0.0)
              {
                v127 = (kakekari * 90.0) + -90.0;
                v160.m20 = 0.0;
                *&v160.m00 = 0;
              }
              else
              {
                v160.m20 = 0.0;
                *&v160.m00 = 0;
                v127 = kakekari * -90.0;
              }
              sub_8524C0(&v160.m00, 0.0, v125 + v127, 0.0);
              sub_1A1CC60(&v164, 0, v160.m00, v160.m10, v160.m20);
              v129 = *&v164.x;
              z = v164.z;
              w = v164.w;
              {
              }
              *&v174.x = v129;
              v174.z = z;
              v174.w = w;
              Rotate(&v160, v174, 0);
              v165 = v160;
              v135 = *(p_z - 2);
              v136 = *(p_z - 1);
              v137 = *p_z;
              v139 = pMRBlk_Mesh;
              v140 = pBlk_MeshCnt;
              v142 = get_gameObject(v139->m_Items[v140]);
              v143 = get_transform(v142, 0);
              position = get_position(v143);
              {
              }
              v171.x = v135;
              v171.y = v136;
              v171.z = v137;
              v167 = op_Subtraction(v171, position);
              v146 = sub_1A00CF0(&v165.m00, v167.x, v167.y, v167.z, v145);
              v148 = pMRBlk_Mesh;
              v149 = pBlk_MeshCnt;
              v150 = *&v146;
              v152 = v151;
              v154 = v153;
              v156 = get_gameObject(v148->m_Items[v149]);
              v157 = get_transform(v156, 0);
              v173 = get_position(v157);
              v172.x = v150;
              v172.y = v152;
              v172.z = v154;
              v170 = op_Addition(v172, v173);
              goto LABEL_176;
            }
          }
          else
          {
LABEL_135:
              goto LABEL_138;
          }
          goto LABEL_138;
        }
        sub_854710(&mrpb_angle, 1u);
        if (v97 == 0.0)
        {
          sub_1A1CAE0(&v164.x, 0);
          sub_1A1CC60(&v163, 0, v98, v99, v100);
          v160.m20 = 0.0;
          *&v160.m00 = 0;
          sub_8524C0(&v160.m00, 0.0, 0.0, 0.0);
          sub_1A1CC60(&v164, 0, v160.m00, v160.m10, v160.m20);
          kakekari = 15;
        }
LABEL_110:
        v170 = *(p_z - 2);
LABEL_176:
        SetPosition(v47, v49++, v170);
        p_z += 3;
      }
      while (size != v49);
    }
  }
  {
    v159 = cName;
  }
  else
  {
    v159 = cName;
  }
  AttributeUsageAttribute___set_Item(Line3D, v159, Item);
}

// 0x1653900
void AutLineFree(void) {
  PropertySheet___Clear(Line3D);
}

// 0x16527b0
void BlkAllDalate(void) {
  s64 i;
  struct XRD773Unity_CommonMesh_array *pMRBlk_Mesh;
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
      if (pbBlkDalateflag == 1)
        goto LABEL_9;
LABEL_28:
      if (++i == 404)
        goto LABEL_29;
    }
    if (pbBlkDalateflag != 1)
      goto LABEL_28;
LABEL_9:
    v6 = i - 4;
    else
    {
      if (v6 >= LODWORD(pMRBlk_Mesh->max_length))
      {
LABEL_12:
      }
    }
    v8 = *(&pMRBlk_Mesh->obj.klass + i);
    if (!op_Inequality(v8, 0, 0))
      goto LABEL_28;
    v10 = pMRBlk_Mesh;
    gameObject = get_gameObject(*(&v10->obj.klass + i), 0);
    Destroy_27360000(gameObject);
  }
LABEL_29:
  v15 = NewSpecific(XRD773Unity_CommonMesh, 0x190u);
  pMRBlk_Mesh = v15;
  pbBlkDalateflag = 0;
}

// 0x16513e0
void InitDrawMapBase(pbProcHandle_t **p) {
  Il2CppObject *data;
  u64 *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  data = (*p)->data;
  v4 = Allocate(sdfMat_t);
  sdfMat_t___ctor(v4);
  klass = data->klass;
  if (data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbMapBase_t)
  {
    sub_8FC2C0(klass->_1.element_class, pbMapBase_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  data[1].monitor = v4;
}

// 0x164fdb0
dds3ProcessFunc_t *deleteExit(dds3ProcessID_t *id) {
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
    return 0;
  }
  image = v6->_1.image;
  if (*(v6->_1.image + 288) < v8 || *(image[25] + 8 * v8 - 8) != pbExit_t)
  {
    sub_8FC2C0(image[8], pbExit_t, v14);
    if ((v14[0] & 1) != 0)
      v9 = v15;
    else
      v9 = v14 + 1;
    v10 = sub_8C4940(v9);
  }
  return 0;
}

// 0x1650ee0
dds3ProcessFunc_t *deleteMapBase(dds3ProcessID_t *id) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v7;
  u64 *image;
  s64 v9;
  char *v10;
  s64 *v11;
  s64 v13;
  s32 v14;
  u64 v15;
  struct XRD773Unity_CommonMesh_array *pBlk_Mesh;
  UnityEngine_Object_o *v18;
  struct XRD773Unity_CommonMesh_array *v21;
  UnityEngine_Object_o *gameObject;
  struct XRD773Unity_CommonMesh_array *pMRBlk_Mesh;
  UnityEngine_Object_o *v28;
  struct XRD773Unity_CommonMesh_array *v30;
  UnityEngine_Object_o *v33;
  u32 v34;
  UnityEngine_Object_o *v36;
  UnityEngine_Object_o *v37;
  UnityEngine_Object_o *v38;
  u64 v40;
  struct XRD773Unity_CommonMesh_array *allmMesh;
  UnityEngine_Object_o *v46;
  char *v48;
  s64 *v49;
  u64 v50[2];
  char *v51;

  workdata = id->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbProcHandle_t)
  {
    sub_8FC2C0(klass->_1.element_class, pbProcHandle_t, v50);
    if ((v50[0] & 1) != 0)
      v48 = v51;
    else
      v48 = v50 + 1;
    v49 = sub_8C4940(v48);
  }
  v7 = workdata[2].klass;
  else if (!v7)
  {
    goto LABEL_15;
  }
  image = v7->_1.image;
  if (*(v7->_1.image + 288) < v9 || *(image[25] + 8 * v9 - 8) != pbMapBase_t)
  {
    sub_8FC2C0(image[8], pbMapBase_t, v50);
    if ((v50[0] & 1) != 0)
      v10 = v51;
    else
      v10 = v50 + 1;
    v11 = sub_8C4940(v10);
  }
LABEL_15:
  v13 = 4;
  do
  {
    v15 = v13 - 4;
    v18 = *(&pBlk_Mesh->obj.klass + v13);
    if (op_Inequality(v18, 0, 0))
    {
      v21 = pBlk_Mesh;
      gameObject = get_gameObject(*(&v21->obj.klass + v13), 0);
      Destroy_27360000(gameObject);
    }
    v28 = *(&pMRBlk_Mesh->obj.klass + v13);
    if (op_Inequality(v28, 0, 0))
    {
      v30 = pMRBlk_Mesh;
      v33 = get_gameObject(*(&v30->obj.klass + v13), 0);
      Destroy_27360000(v33);
    }
    ++v13;
    v14 = (v34 >> 9) & 1;
  }
  while (v13 != 404);
  v36 = get_gameObject(allMesh);
  Destroy_27360000(v36);
  v37 = get_gameObject(allwMesh);
  Destroy_27360000(v37);
  v38 = get_gameObject(allw2Mesh);
  Destroy_27360000(v38);
  v40 = 0;
  {
LABEL_62:
  }
  while (1)
  {
    if (v40 >= mBlk_grpCnt)
      return 0;
    else
    {
      if (v40 >= LODWORD(allmMesh->max_length))
        goto LABEL_68;
    }
    v46 = get_gameObject(allmMesh->m_Items[v40]);
    Destroy_27360000(v46);
    ++v40;
      goto LABEL_62;
  }
}

// 0x1646100
u32 drawBlock(sdfVector4_t offset, u8 face, u32 type, sdfDrawTag_t **drTag) {
  struct System_UInt32_array *blockColor;
  u32 *v12;
  struct pbDraw_StaticFields *static_fields;
  s64 v15;
  f32 b;
  f32 v18;
  f32 v19;
  f32 v20;
  f32 v21;
  u64 v22;
  u32 *p_a;
  s32 v24;
  s32 v25;
  s32 v26;
  u32 v28;
  u64 v29;
  u32 v30;
  u32 v31;
  u32 v32;
  u32 v33;
  u32 v34;
  u32 v35;
  u64 v44;
  u32 v45;
  u64 *v47;
  s32 PB_BLOCK;
  s32 v50;
  s32 v51;
  s32 v53;
  f32 y;
  f32 z;
  s32 v57;
  s32 v58;
  s32 v59;
  f32 v61;
  s32 v62;
  s32 v63;
  s32 v65;
  s32 v66;
  s32 v67;
  s32 v69;
  s32 v70;
  s32 v71;
  s32 v73;
  s32 v74;
  s32 v75;
  s32 v77;
  s32 v78;
  s32 v79;
  s32 v81;
  s32 v82;
  s32 v83;
  f32 v85;
  s32 v86;
  s32 v87;
  s32 v89;
  s32 v90;
  s32 v91;
  s32 v93;
  s32 v94;
  s32 v95;
  s32 v97;
  s32 v98;
  s32 v99;
  s32 v101;
  s32 v102;
  s32 v103;
  s32 v105;
  s32 v106;
  s32 v107;
  s32 v109;
  s32 v110;
  s32 v111;
  s32 v113;
  s32 v114;
  s32 v115;
  s32 v117;
  s32 v118;
  s32 v119;
  s32 v121;
  s32 v122;
  s32 v123;
  s32 v125;
  s32 v126;
  s32 v127;
  s32 v129;
  s32 v130;
  s32 v131;
  s32 v133;
  s32 v134;
  s32 v135;
  s32 v137;
  s32 v138;
  s32 v139;
  s32 v141;
  s32 v142;
  s32 v143;
  u64 *v145;
  struct pbDraw_StaticFields *v146;
  f32 PB_BLOCK_A;
  u64 *v148;
  s32 v149;
  s32 v150;
  struct pbDraw_StaticFields *v152;
  f32 v153;
  s32 v154;
  s32 v155;
  struct pbDraw_StaticFields *v157;
  f32 v158;
  s32 v159;
  s32 v160;
  struct pbDraw_StaticFields *v162;
  f32 v163;
  s32 v164;
  s32 v165;
  u64 *v167;
  struct pbDraw_StaticFields *v168;
  f32 v169;
  u64 *v170;
  s32 v171;
  s32 v172;
  f32 PB_BLOCK_W;
  f32 v176;
  s32 v177;
  s32 v178;
  f32 v181;
  f32 v182;
  s32 v183;
  s32 v184;
  struct pbDraw_StaticFields *v186;
  f32 v187;
  s32 v188;
  s32 v189;
  struct pbDraw_StaticFields *v191;
  f32 v192;
  s32 v193;
  s32 v194;
  f32 v197;
  f32 v198;
  s32 v199;
  s32 v200;
  f32 v203;
  f32 v204;
  s32 v205;
  s32 v206;
  struct pbDraw_StaticFields *v208;
  f32 v209;
  s32 v210;
  s32 v211;
  struct pbDraw_StaticFields *v213;
  f32 v214;
  s32 v215;
  s32 v216;
  struct pbDraw_StaticFields *v218;
  f32 v219;
  s32 v220;
  s32 v221;
  f32 v224;
  f32 v225;
  s32 v226;
  s32 v227;
  f32 v230;
  f32 v231;
  s32 v232;
  s32 v233;
  struct pbDraw_StaticFields *v235;
  f32 v236;
  s32 v237;
  s32 v238;
  struct pbDraw_StaticFields *v240;
  f32 v241;
  s32 v242;
  s32 v243;
  f32 v246;
  f32 v247;
  s32 v248;
  s32 v249;
  f32 v252;
  f32 v253;
  s32 v254;
  s32 v255;
  u64 *v257;
  struct pbDraw_StaticFields *v258;
  f32 v259;
  u64 *v260;
  s32 v261;
  s32 v262;
  f32 v265;
  f32 v266;
  s32 v267;
  s32 v268;
  struct pbDraw_StaticFields *v270;
  f32 v271;
  s32 v272;
  s32 v273;
  f32 v276;
  f32 v277;
  s32 v278;
  s32 v279;
  struct pbDraw_StaticFields *v281;
  f32 v282;
  s32 v283;
  s32 v284;
  f32 v287;
  f32 v288;
  s32 v289;
  s32 v290;
  struct pbDraw_StaticFields *v292;
  f32 v293;
  s32 v294;
  s32 v295;
  f32 v298;
  f32 v299;
  s32 v300;
  s32 v301;
  struct pbDraw_StaticFields *v303;
  f32 v304;
  s32 v305;
  s32 v306;
  struct pbDraw_StaticFields *v308;
  f32 v309;
  s32 v310;
  s32 v311;
  f32 v314;
  f32 v315;
  s32 v316;
  s32 v317;
  f32 v320;
  f32 v321;
  s32 v322;
  s32 v323;
  struct pbDraw_StaticFields *v325;
  f32 v326;
  s32 v327;
  s32 v328;
  struct pbDraw_StaticFields *v330;
  f32 v331;
  s32 v332;
  s32 v333;
  f32 v336;
  f32 v337;
  s32 v338;
  s32 v339;
  f32 v342;
  f32 v343;
  s32 v344;
  s32 v345;
  u64 *v347;
  s32 v348;
  u64 *v349;
  s32 v350;
  s32 v351;
  f32 v353;
  s32 v354;
  s32 v355;
  s32 v357;
  s32 v358;
  s32 v359;
  s32 v361;
  s32 v362;
  s32 v363;
  s32 v365;
  s32 v366;
  s32 v367;
  s32 v369;
  s32 v370;
  s32 v371;
  s32 v373;
  s32 v374;
  s32 v375;
  s32 v377;
  s32 v378;
  s32 v379;
  s32 v381;
  s32 v382;
  s32 v383;
  s32 v385;
  s32 v386;
  s32 v387;
  s32 v389;
  s32 v390;
  s32 v391;
  f32 v393;
  s32 v394;
  s32 v395;
  s32 v397;
  s32 v398;
  s32 v399;
  s32 v401;
  s32 v402;
  s32 v403;
  s32 v405;
  s32 v406;
  s32 v407;
  s32 v409;
  s32 v410;
  s32 v411;
  u64 *v413;
  s32 v414;
  u64 *v415;
  s32 v416;
  s32 v417;
  s32 v419;
  s32 v420;
  s32 v421;
  s32 v423;
  s32 v424;
  s32 v425;
  s32 v427;
  s32 v428;
  s32 v429;
  s32 v431;
  s32 v432;
  s32 v433;
  s32 v435;
  s32 v436;
  s32 v437;
  s32 v439;
  s32 v440;
  s32 v441;
  s32 v443;
  s32 v444;
  s32 v445;
  s32 v447;
  s32 v448;
  s32 v449;
  s32 v451;
  s32 v452;
  s32 v453;
  s32 v455;
  s32 v456;
  s32 v457;
  s32 v459;
  s32 v460;
  s32 v461;
  s32 v463;
  s32 v464;
  s32 v465;
  s32 v467;
  s32 v468;
  s32 v469;
  s32 v471;
  s32 v472;
  s32 v473;
  s32 v475;
  s32 v476;
  s32 v477;
  s32 v479;
  s32 v480;
  s32 v481;
  s32 v483;
  s32 v484;
  s32 v485;
  s32 v487;
  s32 v488;
  s32 v489;
  s32 v491;
  s32 v492;
  s32 v493;
  s32 v495;
  s32 v496;
  s32 v497;
  s32 v499;
  s32 v500;
  s32 v501;
  s32 v503;
  s32 v504;
  s32 v505;
  s32 v507;
  s32 v508;
  s32 v509;
  System_Array_o *v511;
  struct System_Int32_array_array *v512;
  System_Array_o *v513;
  System_Array_o *v516;
  System_Array_o *v519;
  System_Array_o *v522;
  System_Array_o *v525;
  u64 *v526;
  s32 v527;
  u64 *v528;
  s32 v529;
  s32 v530;
  s32 v532;
  s32 v533;
  s32 v534;
  s32 v536;
  s32 v537;
  s32 v538;
  s32 v540;
  s32 v541;
  s32 v542;
  System_Array_o *v544;
  struct pbDraw_StaticFields *v546;
  struct pbDraw_StaticFields *v547;
  struct XRD773Unity_CommonMesh_array *pMRBlk_Mesh;
  s64 pBlk_MeshCnt;
  UnityEngine_Object_o *v551;
  bool v552;
  s64 v553;
  u32 *v554;
  s64 v555;
  XRD773Unity_GraphicManager_o *Instance;
  s64 *Mesh;
  s64 *v558;
  struct XRD773Unity_CommonMesh_array *v562;
  s64 v563;
  UnityEngine_Transform_o *transform;
  struct pbDraw_StaticFields *v566;
  UnityEngine_Object_o *pGoalBlk_Mesh;
  XRD773Unity_GraphicManager_o *v568;
  XRD773Unity_CommonMesh_o *v570;
  UnityEngine_Transform_o *v572;
  u64 *v574;
  struct UnityEngine_Vector3_array_array *v579;
  struct UnityEngine_Vector3_array_array *mBlkPosbup;
  s64 mBlk_allCnt;
  signed s64 v584;
  u32 v594;
  f32 v595;
  pbDraw_c *v596;
  pbDraw_c *v597;
  struct pbDraw_StaticFields **p_static_fields;
  UnityEngine_Transform_o *v600;
  f32 v601;
  UnityEngine_Transform_o *v602;
  f32 v603;
  f32 v604;
  f32 v605;
  f32 v606;
  f32 v607;
  f32 v608;
  f32 v609;
  UnityEngine_Transform_o *v610;
  u32 v613;
  struct XRD773Unity_CommonMesh_array *v614;
  s64 v615;
  struct XRD773Unity_CommonMesh_array *v618;
  s64 v619;
  struct XRD773Unity_CommonMesh_array *v622;
  s64 v623;
  struct XRD773Unity_CommonMesh_array *v627;
  s64 v628;
  XRD773Unity_CommonMesh_o *v630;
  struct XRD773Unity_CommonMesh_array *v633;
  s64 v634;
  XRD773Unity_CommonMesh_o *v636;
  UnityEngine_Vector2_array *rnd_uvpos;
  pbDraw_c *v638;
  struct XRD773Unity_CommonMesh_array *v641;
  s64 v642;
  XRD773Unity_CommonMesh_o *v644;
  struct XRD773Unity_CommonMesh_array *v647;
  s64 v648;
  pbDraw_c *v652;
  UnityEngine_Object_o *pMRBlk_GameObj;
  u64 *v656;
  struct UnityEngine_Vector3_array_array *v659;
  struct XRD773Unity_CommonMesh_array *v663;
  s64 v664;
  UnityEngine_Transform_o *v666;
  f32 x;
  UnityEngine_Transform_o *v668;
  f32 v669;
  f32 v670;
  f32 v671;
  f32 v672;
  f32 v673;
  f32 v674;
  f32 v675;
  f32 v676;
  f32 v677;
  f32 v678;
  struct System_Int32_array_array *widxbup;
  s64 wBlk_allCnt;
  s64 *v681;
  s64 *v682;
  struct System_Int32_array_array *v687;
  s64 v688;
  System_Int32_array *v689;
  struct XRD773Unity_CommonMesh_array *v693;
  s64 v694;
  UnityEngine_Transform_o *v696;
  f32 v697;
  f32 v698;
  f32 v699;
  f32 v700;
  f32 v701;
  f32 v702;
  f32 v703;
  f32 v705;
  f32 v706;
  f32 w;
  f32 v708;
  struct UnityEngine_Vector3_array_array *v710;
  s64 v711;
  s64 v713;
  s64 mBlkPosbupCnt;
  s64 v715;
  f32 v716;
  f32 v717;
  f32 v718;
  f32 v719;
  f32 v720;
  s32 v721;
  s32 v722;
  u32 *v724;
  u64 v725;
  struct System_Byte_array_array *outLineChk;
  s64 outLineChkCnt;
  s64 v731;
  s64 outLineChkCnt2;
  s64 v733;
  pbDraw_c *v735;
  s64 v736;
  bool v737;
  u64 v739;
  struct UnityEngine_Vector3_array_array *autLinePos;
  u32 *v743;
  s64 *v744;
  s64 *v745;
  u32 v748;
  struct UnityEngine_Vector3_array_array *v750;
  s64 v752;
  struct XRD773Unity_CommonMesh_array *v753;
  s64 v754;
  s64 v755;
  UnityEngine_Transform_o *v757;
  f32 v758;
  struct UnityEngine_Vector3_array *autPos;
  f32 v760;
  f32 v762;
  struct UnityEngine_Vector3_array_array *v765;
  struct XRD773Unity_CommonMesh_array *v767;
  s64 v768;
  UnityEngine_Vector3_array *v769;
  UnityEngine_Transform_o *v771;
  f32 v772;
  struct UnityEngine_Vector3_array *v773;
  f32 v774;
  f32 v776;
  struct UnityEngine_Vector3_array_array *v779;
  struct XRD773Unity_CommonMesh_array *v781;
  s64 v782;
  UnityEngine_Vector3_array *v783;
  UnityEngine_Transform_o *v785;
  f32 v786;
  struct UnityEngine_Vector3_array *v787;
  f32 v788;
  f32 v790;
  s32 v793;
  struct UnityEngine_Vector3_array_array *v795;
  s64 v797;
  struct UnityEngine_Vector3_array_array *v798;
  s64 v799;
  s64 v800;
  UnityEngine_Vector3_array *v802;
  s64 v803;
  f32 v805;
  struct UnityEngine_Vector3_array *v806;
  f32 v807;
  f32 v809;
  struct UnityEngine_Vector3_array_array *v812;
  struct UnityEngine_Vector3_array_array *v814;
  UnityEngine_Vector3_array *v815;
  s64 v816;
  UnityEngine_Vector3_array *v818;
  s64 v819;
  f32 v821;
  struct UnityEngine_Vector3_array *v822;
  f32 v823;
  f32 v825;
  struct UnityEngine_Vector3_array_array *v828;
  struct UnityEngine_Vector3_array_array *v830;
  UnityEngine_Vector3_array *v831;
  s64 v832;
  UnityEngine_Vector3_array *v834;
  s64 v835;
  f32 v837;
  struct UnityEngine_Vector3_array *v838;
  f32 v839;
  f32 v841;
  s16 v843;
  s32 v844;
  struct System_String_array *RBlockStrbup;
  s64 RBlockOutCnt;
  s64 *v849;
  struct System_String_array *MBlockStrbup;
  s64 MBlockOutCnt;
  u64 *v857;
  u64 *v858;
  struct System_String_array *v860;
  s64 v861;
  struct UnityEngine_Vector3_array_array *v865;
  UnityEngine_GameObject_o **p_pMBlk_GameObj;
  UnityEngine_Vector3_array *v868;
  s64 *v869;
  System_Object_array *v871;
  s64 *v875;
  s64 *v876;
  s64 *v879;
  s64 *v880;
  s64 *v883;
  s64 *v884;
  struct System_String_array *v888;
  s64 v889;
  struct UnityEngine_Vector3_array_array *v893;
  struct UnityEngine_Vector3_array_array *v897;
  s64 v898;
  s64 v900;
  s64 v901;
  s64 v902;
  f32 v903;
  f32 v904;
  f32 v905;
  f32 v906;
  f32 v907;
  s32 v908;
  s32 v909;
  u32 *v911;
  struct System_Int32_array_array *v915;
  s64 v916;
  System_Int32_array *v918;
  struct System_Int32_array_array *v922;
  s64 v923;
  System_Int32_array *v925;
  struct System_Int32_array_array *v929;
  s64 v930;
  System_Int32_array *v932;
  struct System_Int32_array_array *v936;
  s64 v937;
  System_Int32_array *v939;
  struct System_Int32_array_array *v943;
  s64 v944;
  System_Int32_array *v946;
  u64 v948;
  s32 v949;
  struct System_Byte_array_array *facebup;
  s64 v960;
  System_Byte_array *v962;
  struct System_Byte_array_array *v966;
  s64 v967;
  System_Byte_array *v969;
  u8 v970;
  s32 v971;
  struct System_Int32_array_array *v976;
  struct System_Int32_array *v977;
  s64 v978;
  System_Int32_array *v979;
  s32 v980;
  struct System_Int32_array_array *v984;
  struct System_Int32_array *v985;
  System_Int32_array *v987;
  s32 v989;
  struct System_Int32_array_array *v993;
  struct System_Int32_array *v994;
  System_Int32_array *v996;
  s32 v998;
  struct System_Int32_array_array *v1002;
  struct System_Int32_array *v1003;
  System_Int32_array *v1005;
  s32 v1007;
  struct System_Int32_array_array *v1011;
  struct System_Int32_array *v1012;
  System_Int32_array *v1014;
  s32 v1016;
  struct System_Int32_array_array *v1020;
  struct System_Int32_array *v1021;
  System_Int32_array *v1023;
  s32 v1025;
  s64 v1026;
  UnityEngine_Vector3_array *v1029;
  u64 v1031;
  s64 v1033;
  struct UnityEngine_Vector3_array *v1035;
  s64 v1036;
  f32 v1038;
  struct UnityEngine_Vector3_array *v1039;
  f32 v1040;
  u64 v1041;
  f32 v1043;
  struct UnityEngine_Vector3_array *v1046;
  s64 v1047;
  f32 v1049;
  struct UnityEngine_Vector3_array *v1050;
  f32 v1051;
  f32 v1053;
  struct UnityEngine_Vector3_array *v1056;
  s64 v1057;
  f32 v1059;
  struct UnityEngine_Vector3_array *v1060;
  f32 v1061;
  f32 v1063;
  u64 *v1065;
  u64 *v1066;
  System_String_o *v1067;
  struct System_Int32_array_array *widx2;
  struct System_Int32_array *widx;
  s64 v1077;
  System_Int32_array *v1078;
  s32 v1079;
  struct System_Int32_array_array *v1083;
  struct System_Int32_array *v1084;
  System_Int32_array *v1086;
  struct System_Int32_array_array *v1091;
  struct System_Int32_array *v1092;
  System_Int32_array *v1094;
  s32 v1096;
  struct System_Int32_array_array *v1100;
  struct System_Int32_array *v1101;
  System_Int32_array *v1103;
  struct System_Int32_array_array *v1108;
  struct System_Int32_array *v1109;
  System_Int32_array *v1111;
  s32 v1113;
  struct System_Int32_array_array *v1117;
  struct System_Int32_array *v1118;
  System_Int32_array *v1120;
  s32 v1122;
  s64 v1123;
  UnityEngine_Vector3_array *v1126;
  u64 v1128;
  s64 v1130;
  struct UnityEngine_Vector3_array *wBlkPosbup;
  s64 v1133;
  f32 v1135;
  struct UnityEngine_Vector3_array *WallautPos;
  f32 v1137;
  u64 v1138;
  f32 v1140;
  struct UnityEngine_Vector3_array *v1143;
  s64 v1144;
  f32 v1146;
  struct UnityEngine_Vector3_array *v1147;
  f32 v1148;
  f32 v1150;
  struct UnityEngine_Vector3_array *v1153;
  s64 v1154;
  f32 v1156;
  struct UnityEngine_Vector3_array *v1157;
  f32 v1158;
  f32 v1160;
  u64 *v1162;
  u64 *v1163;
  System_String_o *v1164;
  struct System_Int32_array_array *v1171;
  struct System_Int32_array *v1172;
  s64 v1173;
  System_Int32_array *v1174;
  s32 v1175;
  struct System_Int32_array_array *v1179;
  struct System_Int32_array *v1180;
  System_Int32_array *v1182;
  struct System_Int32_array_array *v1187;
  struct System_Int32_array *v1188;
  System_Int32_array *v1190;
  s32 v1192;
  struct System_Int32_array_array *v1196;
  struct System_Int32_array *v1197;
  System_Int32_array *v1199;
  struct System_Int32_array_array *v1204;
  struct System_Int32_array *v1205;
  System_Int32_array *v1207;
  s32 v1209;
  struct System_Int32_array_array *v1213;
  struct System_Int32_array *v1214;
  System_Int32_array *v1216;
  s32 v1218;
  s64 v1219;
  UnityEngine_Vector3_array *v1222;
  u64 v1224;
  s64 v1226;
  struct UnityEngine_Vector3_array *v1228;
  s64 v1229;
  f32 v1231;
  struct UnityEngine_Vector3_array *v1232;
  f32 v1233;
  f32 v1235;
  struct UnityEngine_Vector3_array *v1238;
  s64 v1239;
  f32 v1241;
  struct UnityEngine_Vector3_array *v1242;
  f32 v1243;
  f32 v1245;
  struct UnityEngine_Vector3_array *v1248;
  s64 v1249;
  f32 v1251;
  struct UnityEngine_Vector3_array *v1252;
  f32 v1253;
  f32 v1255;
  u64 *v1257;
  u64 *v1258;
  System_String_o *v1259;
  struct System_Int32_array_array *v1266;
  struct System_Int32_array *v1267;
  s64 v1268;
  System_Int32_array *v1269;
  s32 v1270;
  struct System_Int32_array_array *v1274;
  struct System_Int32_array *v1275;
  System_Int32_array *v1277;
  struct System_Int32_array_array *v1282;
  struct System_Int32_array *v1283;
  System_Int32_array *v1285;
  s32 v1287;
  struct System_Int32_array_array *v1291;
  struct System_Int32_array *v1292;
  System_Int32_array *v1294;
  struct System_Int32_array_array *v1299;
  struct System_Int32_array *v1300;
  System_Int32_array *v1302;
  s32 v1304;
  struct System_Int32_array_array *v1308;
  struct System_Int32_array *v1309;
  System_Int32_array *v1311;
  s32 v1313;
  s64 v1314;
  UnityEngine_Vector3_array *v1317;
  u64 v1319;
  s64 v1321;
  struct UnityEngine_Vector3_array *v1323;
  s64 v1324;
  f32 v1326;
  u64 v1327;
  struct UnityEngine_Vector3_array *v1328;
  f32 v1329;
  f32 v1331;
  struct UnityEngine_Vector3_array *v1334;
  s64 v1335;
  f32 v1337;
  struct UnityEngine_Vector3_array *v1338;
  f32 v1339;
  f32 v1341;
  struct UnityEngine_Vector3_array *v1344;
  s64 v1345;
  f32 v1347;
  struct UnityEngine_Vector3_array *v1348;
  f32 v1349;
  f32 v1351;
  u64 *v1353;
  u64 *v1354;
  System_String_o *v1355;
  s32 v1358;
  s64 v1359;
  s64 v1360;
  struct System_Int32_array_array *v1363;
  s64 v1364;
  struct System_Int32_array *v1366;
  System_Int32_array *v1367;
  s32 v1369;
  u32 v1371;
  struct pbDraw_StaticFields **v1373;
  struct XRD773Unity_CommonMesh_array *allmMesh;
  UnityEngine_Object_o *gameObject;
  s32 fBlk_allCnt;
  UnityEngine_Object_o *allMesh;
  XRD773Unity_GraphicManager_o *v1383;
  XRD773Unity_CommonMesh_o *v1384;
  pbDraw_c *v1385;
  UnityEngine_Vector3_array *v1386;
  u64 *v1387;
  UnityEngine_Vector2_array *v1389;
  u64 v1390;
  f32 *v1391;
  f32 g;
  f32 v1395;
  f32 a;
  u32 v1398;
  signed s64 v1399;
  struct UnityEngine_Vector3_array *npos;
  struct System_Int32_array *idx;
  XRD773Unity_CommonMesh_o *v1446;
  UnityEngine_Object_o *allwMesh;
  XRD773Unity_GraphicManager_o *v1450;
  XRD773Unity_CommonMesh_o *v1451;
  pbDraw_c *v1452;
  struct UnityEngine_Vector3_array *v1453;
  struct UnityEngine_Vector3_array *v1455;
  struct System_Int32_array *v1457;
  struct UnityEngine_Color_array *v1459;
  struct UnityEngine_Vector2_array *v1461;
  u64 v1463;
  u32 *v1464;
  s32 v1466;
  s32 v1467;
  s32 v1468;
  u32 v1470;
  s32 v1471;
  u64 v1472;
  struct UnityEngine_Vector3_array *wpos;
  struct UnityEngine_Vector3_array *allwpos;
  struct UnityEngine_Vector3_array *wpos2;
  struct UnityEngine_Vector3_array *allw2pos;
  struct System_Int32_array *allwidx;
  struct UnityEngine_Color_array *allwcolor;
  struct UnityEngine_Vector2_array *alluvwpos;
  struct UnityEngine_Vector2_array *alluvw2pos;
  XRD773Unity_CommonMesh_o *v1548;
  UnityEngine_Object_o *allw2Mesh;
  XRD773Unity_GraphicManager_o *v1552;
  XRD773Unity_CommonMesh_o *v1553;
  pbDraw_c *v1554;
  XRD773Unity_CommonMesh_o *v1557;
  f32 v1559;
  pbDraw_c *v1562;
  signed s64 v1563;
  s16 v1564;
  s32 v1565;
  struct XRD773Unity_CommonMesh_array *v1567;
  UnityEngine_Object_o *v1570;
  pbDraw_c *v1572;
  u64 v1574;
  s16 v1576;
  s32 i;
  struct XRD773Unity_CommonMesh_array *v1579;
  UnityEngine_Object_o *v1582;
  u64 v1584;
  struct XRD773Unity_CommonMesh_array *v1585;
  u64 v1586;
  UnityEngine_Object_o *v1589;
  struct System_Int32_array *mBlk_grpnumCnt;
  s64 v1592;
  u32 mBlk_grpCnt;
  struct XRD773Unity_CommonMesh_array *v1596;
  u64 v1597;
  s16 v1598;
  s32 j;
  struct pbDraw_StaticFields **v1601;
  struct XRD773Unity_CommonMesh_array *v1602;
  UnityEngine_Object_o *v1604;
  u32 *v1607;
  XRD773Unity_GraphicManager_o *v1608;
  s64 *v1609;
  s64 *v1610;
  struct System_Int32_array *v1614;
  UnityEngine_Vector3_array *v1616;
  struct System_Int32_array *v1618;
  u64 *v1620;
  struct System_Int32_array *v1621;
  u64 *v1622;
  UnityEngine_Color_array *v1624;
  struct System_Int32_array *v1625;
  UnityEngine_Vector2_array *v1628;
  u32 v1629;
  u64 v1630;
  struct System_Int32_array *v1632;
  u32 *v1634;
  s64 v1635;
  u64 v1636;
  s64 v1637;
  pbDraw_c *v1638;
  char *v1639;
  struct UnityEngine_Vector3_array *v1642;
  struct UnityEngine_Vector3_array_array *v1644;
  f32 v1645;
  f32 v1646;
  f32 v1647;
  UnityEngine_Vector3_array *v1649;
  f32 *v1651;
  f32 v1652;
  f32 v1653;
  f32 v1654;
  s64 v1655;
  u64 v1657;
  struct System_Int32_array *v1658;
  u64 v1659;
  s32 *v1662;
  u64 v1663;
  s32 v1665;
  s32 v1666;
  s32 v1667;
  s64 v1669;
  u64 v1670;
  struct UnityEngine_Vector2_array *move_uvpos;
  f32 *v1674;
  f32 v1675;
  f32 v1676;
  UnityEngine_Vector2_o *v1678;
  struct XRD773Unity_CommonMesh_array *v1680;
  struct XRD773Unity_CommonMesh_array *v1682;
  struct XRD773Unity_CommonMesh_array *v1684;
  struct XRD773Unity_CommonMesh_array *v1687;
  XRD773Unity_CommonMesh_o *v1689;
  struct XRD773Unity_CommonMesh_array *v1691;
  s16 v1695;
  s32 v1696;
  f32 Gcol;
  f32 v1698;
  u32 *v1699;
  u64 v1700;
  s32 v1702;
  s32 v1703;
  s32 v1704;
  sdf3DPrimPolyParm_t_o *v1736;
  UnityEngine_Vector2_o *m_Items;
  UnityEngine_Vector2_o *v1738;
  UnityEngine_Vector3_array *v1739;
  UnityEngine_Vector2_array *v1741;
  UnityEngine_Vector2_array *v1743;
  u32 *v1744;
  u64 v1745;
  u32 *v1746;
  UnityEngine_Vector2_o *v1747;
  UnityEngine_Color_array *v1748;
  UnityEngine_Color_array *v1749;
  UnityEngine_Color_array *col;
  u32 pos;
  s32 posa;
  s32 posc;
  UnityEngine_Vector3_array *posd;
  s64 v1756;
  s64 value;
  s64 v1758;
  s32 v1759;
  s64 v1760;
  s32 v1761;
  s64 v1762;
  s32 v1763;
  s64 v1764;
  s32 v1765;
  s64 v1766;
  s32 v1767;
  s64 v1768;
  s32 v1769;
  s64 v1770;
  s32 v1771;
  s64 v1772;
  s32 v1773;
  s64 v1774;
  s32 v1775;
  s64 v1776;
  s32 v1777;
  s64 v1778;
  s32 v1779;
  s64 v1780;
  s32 v1781;
  s64 v1782;
  s32 v1783;
  s64 v1784;
  s32 v1785;
  s64 v1786;
  s32 v1787;
  s64 v1788;
  s32 v1789;
  s64 v1790;
  s32 v1791;
  s64 v1792;
  s32 v1793;
  s64 v1794;
  s32 v1795;
  s64 v1796;
  s32 v1797;
  s64 v1798;
  s32 v1799;
  s64 v1800;
  s32 v1801;
  s64 v1802;
  s32 v1803;
  s64 v1804;
  s32 v1805;
  s64 v1806;
  s32 v1807;
  s64 v1808;
  s32 v1809;
  s64 v1810;
  s32 v1811;
  s64 v1812;
  s32 v1813;
  s64 v1814;
  s32 v1815;
  s64 v1816;
  s32 v1817;
  s64 v1818;
  s32 v1819;
  s64 v1820;
  s32 v1821;
  s64 v1822;
  s32 v1823;
  s64 v1824;
  s32 v1825;
  s64 v1826;
  s32 v1827;
  s64 v1828;
  s32 v1829;
  s64 v1830;
  s32 v1831;
  s64 v1832;
  s32 v1833;
  s64 v1834;
  s32 v1835;
  s64 v1836;
  s32 v1837;
  s64 v1838;
  s32 v1839;
  s64 v1840;
  s32 v1841;
  s64 v1842;
  s32 v1843;
  s64 v1844;
  s32 v1845;
  s64 v1846;
  s32 v1847;
  s64 v1848;
  s32 v1849;
  s64 v1850;
  s32 v1851;
  s64 v1852;
  s32 v1853;
  s64 v1854;
  s32 v1855;
  s64 v1856;
  s32 v1857;
  s64 v1858;
  s32 v1859;
  s64 v1860;
  s32 v1861;
  s64 v1862;
  s32 v1863;
  s64 v1864;
  s32 v1865;
  s64 v1866;
  s32 v1867;
  s64 v1868;
  s32 v1869;
  s64 v1870;
  s32 v1871;
  s64 v1872;
  s32 v1873;
  s64 v1874;
  s32 v1875;
  s64 v1876;
  s32 v1877;
  s64 v1878;
  s32 v1879;
  s64 v1880;
  s32 v1881;
  s64 v1882;
  s32 v1883;
  s64 v1884;
  s32 v1885;
  s64 v1886;
  s32 v1887;
  s64 v1888;
  s32 v1889;
  s64 v1890;
  s32 v1891;
  s64 v1892;
  s32 v1893;
  s64 v1894;
  s32 v1895;
  s64 v1896;
  s32 v1897;
  s64 v1898;
  s32 v1899;
  s64 v1900;
  s32 v1901;
  s64 v1902;
  s32 v1903;
  s64 v1904;
  s32 v1905;
  s64 v1906;
  s32 v1907;
  s64 v1908;
  s32 v1909;
  s64 v1910;
  s32 v1911;
  s64 v1912;
  s32 v1913;
  s64 v1914;
  s32 v1915;
  s64 v1916;
  s32 v1917;
  s64 v1918;
  s32 v1919;
  s64 v1920;
  s32 v1921;
  s64 v1922;
  s32 v1923;
  s64 v1924;
  s32 v1925;
  s64 v1926;
  s32 v1927;
  s64 v1928;
  s32 v1929;
  s64 v1930;
  s32 v1931;
  s64 v1932;
  s32 v1933;
  s64 v1934;
  s32 v1935;
  s64 v1936;
  s32 v1937;
  s64 v1938;
  s32 v1939;
  s64 v1940;
  s32 v1941;
  s64 v1942;
  s32 v1943;
  s64 v1944;
  s32 v1945;
  s64 v1946;
  s32 v1947;
  s64 v1948;
  s32 v1949;
  s64 v1950;
  s32 v1951;
  s64 v1952;
  s32 v1953;
  s64 v1954;
  s32 v1955;
  s64 v1956;
  s32 v1957;
  s64 v1958;
  s32 v1959;
  s64 v1960;
  s32 v1961;
  UnityEngine_Vector3_o v1962;
  UnityEngine_Vector3_o v1963;
  s64 v1964;
  u64 v1965;
  UnityEngine_Vector4_o v1966;
  UnityEngine_Vector3_o position;
  UnityEngine_Vector3_o v1971;
  UnityEngine_Vector4_o v1972;
  UnityEngine_Vector3_o v1973;
  UnityEngine_Vector3_o v1974;
  UnityEngine_Vector3_o v1977;
  UnityEngine_Vector3_o v1980;
  UnityEngine_Vector4_o v1981;

  v1966 = offset;
  v1964 = 0;
  v1965 = 0;
  v1963.z = 0.0;
  *&v1963.x = 0;
  v1736 = Allocate(sdf3DPrimPolyParm_t);
  sdf3DPrimPolyParm_t___ctor(v1736);
  if (!face)
    return 0;
  autline_type = 0;
  v1972 = SDF_VU0__Retdds3ColorItoF(blockColor->m_Items[2], 128.0);
  v1964 = 0;
  v1965 = 0;
  col = NewSpecific(UnityEngine_Color, 0x18u);
  v12 = NewSpecific(UnityEngine_Color, 0x10u);
  switch (type)
  {
    case 0u:
    case 2u:
    case 3u:
    case 4u:
    case 5u:
      v15 = *&DefblockCol.r;
      b = DefblockCol.b;
      *&static_fields = DefblockCol.a;
      v1964 = v15;
      v1965 = __PAIR64__(static_fields, LODWORD(b));
      break;
    case 1u:
      v18 = v1972.y + -0.5;
      v19 = v1972.w + -1.0;
      v20 = v1972.x + -0.5;
      v21 = v1972.z + -0.5;
      goto LABEL_17;
    case 6u:
      v20 = 0.0;
      v18 = 1.0;
      v19 = 1.0;
      v21 = 0.0;
LABEL_17:
      sub_19EC630(&v1964, v20, v18, v21, v19);
      break;
    default:
      break;
  }
  v22 = 0;
  p_a = &col->m_Items[0].a;
  do
  {
    v24 = HIDWORD(v1964);
    v26 = v1965;
    v25 = HIDWORD(v1965);
    ++v22;
    *(p_a - 3) = v1964;
    *(p_a - 2) = v24;
    *(p_a - 1) = v26;
    *p_a = v25;
    p_a += 4;
  }
  while (v22 != 24);
  v28 = HIDWORD(v1964);
  v29 = v12[6];
  v31 = v1965;
  v30 = HIDWORD(v1965);
  pos = type;
  v32 = HIDWORD(v1965);
  v33 = v1965;
  v34 = HIDWORD(v1964);
  v35 = v1964;
  v12[8] = v1964;
  v12[9] = v28;
  v12[10] = v31;
  v12[11] = v30;
  v12[12] = v35;
  v12[13] = v34;
  v12[14] = v33;
  v12[15] = v32;
  v12[16] = v35;
  v12[17] = v34;
  v12[18] = v33;
  v12[19] = v32;
  v12[20] = v35;
  v12[21] = v34;
  v12[22] = v33;
  v12[23] = v32;
  v12[24] = v35;
  v12[25] = v34;
  v12[26] = v33;
  v12[27] = v32;
  v12[28] = v35;
  v12[29] = v34;
  v12[30] = v33;
  v12[31] = v32;
  v12[32] = v35;
  v12[33] = v34;
  v12[34] = v33;
  v12[35] = v32;
  v12[36] = v35;
  v12[37] = v34;
  v12[38] = v33;
  v12[39] = v32;
  v1746 = v12;
  {
    v45 = pos;
    else
    {
      if (!BlkInitflag)
        goto LABEL_40;
    }
  }
  else
  {
    v45 = pos;
    if (!BlkInitflag)
    {
LABEL_40:
      v47 = NewSpecific(UnityEngine_Vector3, 0x18u);
      LODWORD(value) = 0;
      v1756 = 0;
      sub_8524C0(&v1756, -PB_BLOCK, -PB_BLOCK, PB_BLOCK);
      v50 = HIDWORD(v1756);
      v51 = value;
      *(v47 + 8) = v1756;
      *(v47 + 9) = v50;
      *(v47 + 10) = v51;
      v53 = PB_BLOCK;
      v1962.z = 0.0;
      *&v1962.x = 0;
      sub_8524C0(&v1962.x, v53, -v53, v53);
      y = v1962.y;
      z = v1962.z;
      *(v47 + 11) = LODWORD(v1962.x);
      *(v47 + 12) = y;
      *(v47 + 13) = z;
      v57 = PB_BLOCK;
      v1961 = 0;
      v1960 = 0;
      sub_8524C0(&v1960, -v57, v57, v57);
      v58 = HIDWORD(v1960);
      v59 = v1961;
      *(v47 + 14) = v1960;
      *(v47 + 15) = v58;
      *(v47 + 16) = v59;
      v61 = PB_BLOCK;
      v1959 = 0;
      v1958 = 0;
      sub_8524C0(&v1958, v61, v61, v61);
      v62 = HIDWORD(v1958);
      v63 = v1959;
      *(v47 + 17) = v1958;
      *(v47 + 18) = v62;
      *(v47 + 19) = v63;
      v65 = PB_BLOCK;
      v1957 = 0;
      v1956 = 0;
      sub_8524C0(&v1956, -v65, -v65, -v65);
      v66 = v1957;
      v67 = HIDWORD(v1956);
      *(v47 + 20) = v1956;
      *(v47 + 21) = v67;
      *(v47 + 22) = v66;
      v69 = PB_BLOCK;
      v1955 = 0;
      v1954 = 0;
      sub_8524C0(&v1954, v69, -v69, -v69);
      v70 = v1955;
      v71 = HIDWORD(v1954);
      *(v47 + 23) = v1954;
      *(v47 + 24) = v71;
      *(v47 + 25) = v70;
      v73 = PB_BLOCK;
      v1953 = 0;
      v1952 = 0;
      sub_8524C0(&v1952, -v73, v73, -v73);
      v74 = v1953;
      v75 = HIDWORD(v1952);
      *(v47 + 26) = v1952;
      *(v47 + 27) = v75;
      *(v47 + 28) = v74;
      v77 = PB_BLOCK;
      v1951 = 0;
      v1950 = 0;
      sub_8524C0(&v1950, v77, v77, -v77);
      v78 = v1951;
      v79 = HIDWORD(v1950);
      *(v47 + 29) = v1950;
      *(v47 + 30) = v79;
      *(v47 + 31) = v78;
      v81 = PB_BLOCK;
      v1949 = 0;
      v1948 = 0;
      sub_8524C0(&v1948, v81, -v81, v81);
      v82 = v1949;
      v83 = HIDWORD(v1948);
      *(v47 + 32) = v1948;
      *(v47 + 33) = v83;
      *(v47 + 34) = v82;
      v85 = PB_BLOCK;
      v1947 = 0;
      v1946 = 0;
      sub_8524C0(&v1946, v85, v85, v85);
      v86 = v1947;
      v87 = HIDWORD(v1946);
      *(v47 + 35) = v1946;
      *(v47 + 36) = v87;
      *(v47 + 37) = v86;
      v89 = PB_BLOCK;
      v1945 = 0;
      v1944 = 0;
      sub_8524C0(&v1944, v89, -v89, -v89);
      v90 = v1945;
      v91 = HIDWORD(v1944);
      *(v47 + 38) = v1944;
      *(v47 + 39) = v91;
      *(v47 + 40) = v90;
      v93 = PB_BLOCK;
      v1943 = 0;
      v1942 = 0;
      sub_8524C0(&v1942, v93, v93, -v93);
      v94 = v1943;
      v95 = HIDWORD(v1942);
      *(v47 + 41) = v1942;
      *(v47 + 42) = v95;
      *(v47 + 43) = v94;
      v97 = PB_BLOCK;
      v1941 = 0;
      v1940 = 0;
      sub_8524C0(&v1940, -v97, -v97, v97);
      v98 = v1941;
      v99 = HIDWORD(v1940);
      *(v47 + 44) = v1940;
      *(v47 + 45) = v99;
      *(v47 + 46) = v98;
      v101 = PB_BLOCK;
      v1939 = 0;
      v1938 = 0;
      sub_8524C0(&v1938, -v101, v101, v101);
      v102 = v1939;
      v103 = HIDWORD(v1938);
      *(v47 + 47) = v1938;
      *(v47 + 48) = v103;
      *(v47 + 49) = v102;
      v105 = PB_BLOCK;
      v1937 = 0;
      v1936 = 0;
      sub_8524C0(&v1936, -v105, -v105, -v105);
      v106 = v1937;
      v107 = HIDWORD(v1936);
      *(v47 + 50) = v1936;
      *(v47 + 51) = v107;
      *(v47 + 52) = v106;
      v109 = PB_BLOCK;
      v1935 = 0;
      v1934 = 0;
      sub_8524C0(&v1934, -v109, v109, -v109);
      v110 = v1935;
      v111 = HIDWORD(v1934);
      *(v47 + 53) = v1934;
      *(v47 + 54) = v111;
      *(v47 + 55) = v110;
      v113 = PB_BLOCK;
      v1933 = 0;
      v1932 = 0;
      sub_8524C0(&v1932, -v113, -v113, v113);
      v114 = v1933;
      v115 = HIDWORD(v1932);
      *(v47 + 56) = v1932;
      *(v47 + 57) = v115;
      *(v47 + 58) = v114;
      v117 = PB_BLOCK;
      v1931 = 0;
      v1930 = 0;
      sub_8524C0(&v1930, v117, -v117, v117);
      v118 = v1931;
      v119 = HIDWORD(v1930);
      *(v47 + 59) = v1930;
      *(v47 + 60) = v119;
      *(v47 + 61) = v118;
      v121 = PB_BLOCK;
      v1929 = 0;
      v1928 = 0;
      sub_8524C0(&v1928, -v121, -v121, -v121);
      v122 = v1929;
      v123 = HIDWORD(v1928);
      *(v47 + 62) = v1928;
      *(v47 + 63) = v123;
      *(v47 + 64) = v122;
      v125 = PB_BLOCK;
      v1927 = 0;
      v1926 = 0;
      sub_8524C0(&v1926, v125, -v125, -v125);
      v126 = v1927;
      v127 = HIDWORD(v1926);
      *(v47 + 65) = v1926;
      *(v47 + 66) = v127;
      *(v47 + 67) = v126;
      v129 = PB_BLOCK;
      v1925 = 0;
      v1924 = 0;
      sub_8524C0(&v1924, -v129, v129, v129);
      v130 = v1925;
      v131 = HIDWORD(v1924);
      *(v47 + 68) = v1924;
      *(v47 + 69) = v131;
      *(v47 + 70) = v130;
      v133 = PB_BLOCK;
      v1923 = 0;
      v1922 = 0;
      sub_8524C0(&v1922, v133, v133, v133);
      v134 = v1923;
      v135 = HIDWORD(v1922);
      *(v47 + 71) = v1922;
      *(v47 + 72) = v135;
      *(v47 + 73) = v134;
      v137 = PB_BLOCK;
      v1921 = 0;
      v1920 = 0;
      sub_8524C0(&v1920, -v137, v137, -v137);
      v138 = v1921;
      v139 = HIDWORD(v1920);
      *(v47 + 74) = v1920;
      *(v47 + 75) = v139;
      *(v47 + 76) = v138;
      v141 = PB_BLOCK;
      v1919 = 0;
      v1918 = 0;
      sub_8524C0(&v1918, v141, v141, -v141);
      v142 = v1919;
      v143 = HIDWORD(v1918);
      *(v47 + 77) = v1918;
      *(v47 + 78) = v143;
      *(v47 + 79) = v142;
      npos = v47;
      v145 = NewSpecific(UnityEngine_Vector3, 4u);
      LODWORD(v146) = PB_BLOCK;
      v1917 = 0;
      v1916 = 0;
      v148 = v145;
      sub_8524C0(&v1916, -PB_BLOCK_A, -v146, PB_BLOCK_A);
      v149 = v1917;
      v150 = HIDWORD(v1916);
      *(v148 + 8) = v1916;
      *(v148 + 9) = v150;
      *(v148 + 10) = v149;
      v153 = PB_BLOCK_A;
      LODWORD(v152) = PB_BLOCK;
      v1915 = 0;
      v1914 = 0;
      sub_8524C0(&v1914, v153, -v152, v153);
      v154 = v1915;
      v155 = HIDWORD(v1914);
      *(v148 + 11) = v1914;
      *(v148 + 12) = v155;
      *(v148 + 13) = v154;
      v158 = PB_BLOCK_A;
      LODWORD(v157) = PB_BLOCK;
      v1913 = 0;
      v1912 = 0;
      sub_8524C0(&v1912, v158, -v157, -v158);
      v159 = v1913;
      v160 = HIDWORD(v1912);
      *(v148 + 14) = v1912;
      *(v148 + 15) = v160;
      *(v148 + 16) = v159;
      v163 = PB_BLOCK_A;
      LODWORD(v162) = PB_BLOCK;
      v1911 = 0;
      v1910 = 0;
      sub_8524C0(&v1910, -v163, -v162, -v163);
      v164 = v1911;
      v165 = HIDWORD(v1910);
      *(v148 + 17) = v1910;
      *(v148 + 18) = v165;
      *(v148 + 19) = v164;
      autPos = v148;
      v167 = NewSpecific(UnityEngine_Vector3, 0x10u);
      v169 = PB_BLOCK_A;
      LODWORD(v168) = PB_BLOCK_W;
      v1909 = 0;
      v1908 = 0;
      v170 = v167;
      sub_8524C0(&v1908, v169, -v168, v169);
      v171 = v1909;
      v172 = HIDWORD(v1908);
      *(v170 + 8) = v1908;
      *(v170 + 9) = v172;
      *(v170 + 10) = v171;
      v176 = PB_BLOCK_A;
      v1907 = 0;
      v1906 = 0;
      sub_8524C0(&v1906, v176, PB_BLOCK_W, v176);
      v177 = v1907;
      v178 = HIDWORD(v1906);
      *(v170 + 11) = v1906;
      *(v170 + 12) = v178;
      *(v170 + 13) = v177;
      v181 = PB_BLOCK_A;
      v182 = PB_BLOCK_W;
      v1905 = 0;
      v1904 = 0;
      sub_8524C0(&v1904, v181, v182, -v181);
      v183 = v1905;
      v184 = HIDWORD(v1904);
      *(v170 + 14) = v1904;
      *(v170 + 15) = v184;
      *(v170 + 16) = v183;
      v187 = PB_BLOCK_A;
      LODWORD(v186) = PB_BLOCK_W;
      v1903 = 0;
      v1902 = 0;
      sub_8524C0(&v1902, v187, -v186, -v187);
      v188 = v1903;
      v189 = HIDWORD(v1902);
      *(v170 + 17) = v1902;
      *(v170 + 18) = v189;
      *(v170 + 19) = v188;
      v192 = PB_BLOCK_A;
      LODWORD(v191) = PB_BLOCK_W;
      v1901 = 0;
      v1900 = 0;
      sub_8524C0(&v1900, -v192, -v191, v192);
      v193 = v1901;
      v194 = HIDWORD(v1900);
      *(v170 + 20) = v1900;
      *(v170 + 21) = v194;
      *(v170 + 22) = v193;
      v197 = PB_BLOCK_A;
      v198 = PB_BLOCK_W;
      v1899 = 0;
      v1898 = 0;
      sub_8524C0(&v1898, -v197, v198, v197);
      v199 = v1899;
      v200 = HIDWORD(v1898);
      *(v170 + 23) = v1898;
      *(v170 + 24) = v200;
      *(v170 + 25) = v199;
      v203 = PB_BLOCK_W;
      v204 = -PB_BLOCK_A;
      v1897 = 0;
      v1896 = 0;
      sub_8524C0(&v1896, v204, v203, v204);
      v205 = v1897;
      v206 = HIDWORD(v1896);
      *(v170 + 26) = v1896;
      *(v170 + 27) = v206;
      *(v170 + 28) = v205;
      v209 = PB_BLOCK_A;
      LODWORD(v208) = PB_BLOCK_W;
      v1895 = 0;
      v1894 = 0;
      sub_8524C0(&v1894, -v209, -v208, -v209);
      v210 = v1895;
      v211 = HIDWORD(v1894);
      *(v170 + 29) = v1894;
      *(v170 + 30) = v211;
      *(v170 + 31) = v210;
      v214 = PB_BLOCK_A;
      LODWORD(v213) = PB_BLOCK_W;
      v1893 = 0;
      v1892 = 0;
      sub_8524C0(&v1892, -v214, -v213, v214);
      v215 = v1893;
      v216 = HIDWORD(v1892);
      *(v170 + 32) = v1892;
      *(v170 + 33) = v216;
      *(v170 + 34) = v215;
      v219 = PB_BLOCK_A;
      LODWORD(v218) = PB_BLOCK_W;
      v1891 = 0;
      v1890 = 0;
      sub_8524C0(&v1890, v219, -v218, v219);
      v220 = v1891;
      v221 = HIDWORD(v1890);
      *(v170 + 35) = v1890;
      *(v170 + 36) = v221;
      *(v170 + 37) = v220;
      v224 = PB_BLOCK_W;
      v225 = PB_BLOCK_A;
      v1889 = 0;
      v1888 = 0;
      sub_8524C0(&v1888, v225, v224, v225);
      v226 = v1889;
      v227 = HIDWORD(v1888);
      *(v170 + 38) = v1888;
      *(v170 + 39) = v227;
      *(v170 + 40) = v226;
      v230 = PB_BLOCK_A;
      v231 = PB_BLOCK_W;
      v1887 = 0;
      v1886 = 0;
      sub_8524C0(&v1886, -v230, v231, v230);
      v232 = v1887;
      v233 = HIDWORD(v1886);
      *(v170 + 41) = v1886;
      *(v170 + 42) = v233;
      *(v170 + 43) = v232;
      v236 = PB_BLOCK_A;
      LODWORD(v235) = PB_BLOCK_W;
      v1885 = 0;
      v1884 = 0;
      sub_8524C0(&v1884, -v236, -v235, -v236);
      v237 = v1885;
      v238 = HIDWORD(v1884);
      *(v170 + 44) = v1884;
      *(v170 + 45) = v238;
      *(v170 + 46) = v237;
      v241 = PB_BLOCK_A;
      LODWORD(v240) = PB_BLOCK_W;
      v1883 = 0;
      v1882 = 0;
      sub_8524C0(&v1882, v241, -v240, -v241);
      v242 = v1883;
      v243 = HIDWORD(v1882);
      *(v170 + 47) = v1882;
      *(v170 + 48) = v243;
      *(v170 + 49) = v242;
      v246 = PB_BLOCK_A;
      v247 = PB_BLOCK_W;
      v1881 = 0;
      v1880 = 0;
      sub_8524C0(&v1880, v246, v247, -v246);
      v248 = v1881;
      v249 = HIDWORD(v1880);
      *(v170 + 50) = v1880;
      *(v170 + 51) = v249;
      *(v170 + 52) = v248;
      v252 = PB_BLOCK_W;
      v253 = -PB_BLOCK_A;
      v1879 = 0;
      v1878 = 0;
      sub_8524C0(&v1878, v253, v252, v253);
      v254 = v1879;
      v255 = HIDWORD(v1878);
      *(v170 + 53) = v1878;
      *(v170 + 54) = v255;
      *(v170 + 55) = v254;
      WallautPos = v170;
      v257 = NewSpecific(UnityEngine_Vector3, 0x10u);
      v259 = PB_BLOCK_A;
      LODWORD(v258) = PB_BLOCK_W;
      v1877 = 0;
      v1876 = 0;
      v260 = v257;
      sub_8524C0(&v1876, v259, -v258, v259);
      v261 = v1877;
      v262 = HIDWORD(v1876);
      *(v260 + 8) = v1876;
      *(v260 + 9) = v262;
      *(v260 + 10) = v261;
      v265 = PB_BLOCK_W;
      v266 = PB_BLOCK_A;
      v1875 = 0;
      v1874 = 0;
      sub_8524C0(&v1874, v266, v265, v266);
      v267 = v1875;
      v268 = HIDWORD(v1874);
      *(v260 + 11) = v1874;
      *(v260 + 12) = v268;
      *(v260 + 13) = v267;
      v271 = PB_BLOCK_A;
      LODWORD(v270) = PB_BLOCK_W;
      v1873 = 0;
      v1872 = 0;
      sub_8524C0(&v1872, v271, -v270, -v271);
      v272 = v1873;
      v273 = HIDWORD(v1872);
      *(v260 + 14) = v1872;
      *(v260 + 15) = v273;
      *(v260 + 16) = v272;
      v276 = PB_BLOCK_A;
      v277 = PB_BLOCK_W;
      v1871 = 0;
      v1870 = 0;
      sub_8524C0(&v1870, v276, v277, -v276);
      v278 = v1871;
      v279 = HIDWORD(v1870);
      *(v260 + 17) = v1870;
      *(v260 + 18) = v279;
      *(v260 + 19) = v278;
      v282 = PB_BLOCK_A;
      LODWORD(v281) = PB_BLOCK_W;
      v1869 = 0;
      v1868 = 0;
      sub_8524C0(&v1868, -v282, -v281, v282);
      v283 = v1869;
      v284 = HIDWORD(v1868);
      *(v260 + 20) = v1868;
      *(v260 + 21) = v284;
      *(v260 + 22) = v283;
      v287 = PB_BLOCK_A;
      v288 = PB_BLOCK_W;
      v1867 = 0;
      v1866 = 0;
      sub_8524C0(&v1866, -v287, v288, v287);
      v289 = v1867;
      v290 = HIDWORD(v1866);
      *(v260 + 23) = v1866;
      *(v260 + 24) = v290;
      *(v260 + 25) = v289;
      v293 = PB_BLOCK_A;
      LODWORD(v292) = PB_BLOCK_W;
      v1865 = 0;
      v1864 = 0;
      sub_8524C0(&v1864, -v293, -v292, -v293);
      v294 = v1865;
      v295 = HIDWORD(v1864);
      *(v260 + 26) = v1864;
      *(v260 + 27) = v295;
      *(v260 + 28) = v294;
      v298 = PB_BLOCK_W;
      v299 = -PB_BLOCK_A;
      v1863 = 0;
      v1862 = 0;
      sub_8524C0(&v1862, v299, v298, v299);
      v300 = v1863;
      v301 = HIDWORD(v1862);
      *(v260 + 29) = v1862;
      *(v260 + 30) = v301;
      *(v260 + 31) = v300;
      v304 = PB_BLOCK_A;
      LODWORD(v303) = PB_BLOCK_W;
      v1861 = 0;
      v1860 = 0;
      sub_8524C0(&v1860, -v304, -v303, v304);
      v305 = v1861;
      v306 = HIDWORD(v1860);
      *(v260 + 32) = v1860;
      *(v260 + 33) = v306;
      *(v260 + 34) = v305;
      v309 = PB_BLOCK_A;
      LODWORD(v308) = PB_BLOCK_W;
      v1859 = 0;
      v1858 = 0;
      sub_8524C0(&v1858, v309, -v308, v309);
      v310 = v1859;
      v311 = HIDWORD(v1858);
      *(v260 + 35) = v1858;
      *(v260 + 36) = v311;
      *(v260 + 37) = v310;
      v314 = PB_BLOCK_A;
      v315 = PB_BLOCK_W;
      v1857 = 0;
      v1856 = 0;
      sub_8524C0(&v1856, -v314, v315, v314);
      v316 = v1857;
      v317 = HIDWORD(v1856);
      *(v260 + 38) = v1856;
      *(v260 + 39) = v317;
      *(v260 + 40) = v316;
      v320 = PB_BLOCK_W;
      v321 = PB_BLOCK_A;
      v1855 = 0;
      v1854 = 0;
      sub_8524C0(&v1854, v321, v320, v321);
      v322 = v1855;
      v323 = HIDWORD(v1854);
      *(v260 + 41) = v1854;
      *(v260 + 42) = v323;
      *(v260 + 43) = v322;
      v326 = PB_BLOCK_A;
      LODWORD(v325) = PB_BLOCK_W;
      v1853 = 0;
      v1852 = 0;
      sub_8524C0(&v1852, -v326, -v325, -v326);
      v327 = v1853;
      v328 = HIDWORD(v1852);
      *(v260 + 44) = v1852;
      *(v260 + 45) = v328;
      *(v260 + 46) = v327;
      v331 = PB_BLOCK_A;
      LODWORD(v330) = PB_BLOCK_W;
      v1851 = 0;
      v1850 = 0;
      sub_8524C0(&v1850, v331, -v330, -v331);
      v332 = v1851;
      v333 = HIDWORD(v1850);
      *(v260 + 47) = v1850;
      *(v260 + 48) = v333;
      *(v260 + 49) = v332;
      v336 = PB_BLOCK_W;
      v337 = -PB_BLOCK_A;
      v1849 = 0;
      v1848 = 0;
      sub_8524C0(&v1848, v337, v336, v337);
      v338 = v1849;
      v339 = HIDWORD(v1848);
      *(v260 + 50) = v1848;
      *(v260 + 51) = v339;
      *(v260 + 52) = v338;
      v342 = PB_BLOCK_A;
      v343 = PB_BLOCK_W;
      v1847 = 0;
      v1846 = 0;
      sub_8524C0(&v1846, v342, v343, -v342);
      v344 = v1847;
      v345 = HIDWORD(v1846);
      *(v260 + 53) = v1846;
      *(v260 + 54) = v345;
      *(v260 + 55) = v344;
      wpos = v260;
      v347 = NewSpecific(UnityEngine_Vector3, 0x10u);
      v348 = PB_BLOCK;
      v1845 = 0;
      v1844 = 0;
      v349 = v347;
      sub_8524C0(&v1844, v348, -v348, v348);
      v350 = v1845;
      v351 = HIDWORD(v1844);
      *(v349 + 8) = v1844;
      *(v349 + 9) = v351;
      *(v349 + 10) = v350;
      v353 = PB_BLOCK;
      v1843 = 0;
      v1842 = 0;
      sub_8524C0(&v1842, v353, v353, v353);
      v354 = v1843;
      v355 = HIDWORD(v1842);
      *(v349 + 11) = v1842;
      *(v349 + 12) = v355;
      *(v349 + 13) = v354;
      v357 = PB_BLOCK;
      v1841 = 0;
      v1840 = 0;
      sub_8524C0(&v1840, v357, -v357, -v357);
      v358 = v1841;
      v359 = HIDWORD(v1840);
      *(v349 + 14) = v1840;
      *(v349 + 15) = v359;
      *(v349 + 16) = v358;
      v361 = PB_BLOCK;
      v1839 = 0;
      v1838 = 0;
      sub_8524C0(&v1838, v361, v361, -v361);
      v362 = v1839;
      v363 = HIDWORD(v1838);
      *(v349 + 17) = v1838;
      *(v349 + 18) = v363;
      *(v349 + 19) = v362;
      v365 = PB_BLOCK;
      v1837 = 0;
      v1836 = 0;
      sub_8524C0(&v1836, -v365, -v365, v365);
      v366 = v1837;
      v367 = HIDWORD(v1836);
      *(v349 + 20) = v1836;
      *(v349 + 21) = v367;
      *(v349 + 22) = v366;
      v369 = PB_BLOCK;
      v1835 = 0;
      v1834 = 0;
      sub_8524C0(&v1834, -v369, v369, v369);
      v370 = v1835;
      v371 = HIDWORD(v1834);
      *(v349 + 23) = v1834;
      *(v349 + 24) = v371;
      *(v349 + 25) = v370;
      v373 = PB_BLOCK;
      v1833 = 0;
      v1832 = 0;
      sub_8524C0(&v1832, -v373, -v373, -v373);
      v374 = v1833;
      v375 = HIDWORD(v1832);
      *(v349 + 26) = v1832;
      *(v349 + 27) = v375;
      *(v349 + 28) = v374;
      v377 = PB_BLOCK;
      v1831 = 0;
      v1830 = 0;
      sub_8524C0(&v1830, -v377, v377, -v377);
      v378 = v1831;
      v379 = HIDWORD(v1830);
      *(v349 + 29) = v1830;
      *(v349 + 30) = v379;
      *(v349 + 31) = v378;
      v381 = PB_BLOCK;
      v1829 = 0;
      v1828 = 0;
      sub_8524C0(&v1828, -v381, -v381, v381);
      v382 = v1829;
      v383 = HIDWORD(v1828);
      *(v349 + 32) = v1828;
      *(v349 + 33) = v383;
      *(v349 + 34) = v382;
      v385 = PB_BLOCK;
      v1827 = 0;
      v1826 = 0;
      sub_8524C0(&v1826, v385, -v385, v385);
      v386 = v1827;
      v387 = HIDWORD(v1826);
      *(v349 + 35) = v1826;
      *(v349 + 36) = v387;
      *(v349 + 37) = v386;
      v389 = PB_BLOCK;
      v1825 = 0;
      v1824 = 0;
      sub_8524C0(&v1824, -v389, v389, v389);
      v390 = v1825;
      v391 = HIDWORD(v1824);
      *(v349 + 38) = v1824;
      *(v349 + 39) = v391;
      *(v349 + 40) = v390;
      v393 = PB_BLOCK;
      v1823 = 0;
      v1822 = 0;
      sub_8524C0(&v1822, v393, v393, v393);
      v394 = v1823;
      v395 = HIDWORD(v1822);
      *(v349 + 41) = v1822;
      *(v349 + 42) = v395;
      *(v349 + 43) = v394;
      v397 = PB_BLOCK;
      v1821 = 0;
      v1820 = 0;
      sub_8524C0(&v1820, -v397, -v397, -v397);
      v398 = v1821;
      v399 = HIDWORD(v1820);
      *(v349 + 44) = v1820;
      *(v349 + 45) = v399;
      *(v349 + 46) = v398;
      v401 = PB_BLOCK;
      v1819 = 0;
      v1818 = 0;
      sub_8524C0(&v1818, v401, -v401, -v401);
      v402 = v1819;
      v403 = HIDWORD(v1818);
      *(v349 + 47) = v1818;
      *(v349 + 48) = v403;
      *(v349 + 49) = v402;
      v405 = PB_BLOCK;
      v1817 = 0;
      v1816 = 0;
      sub_8524C0(&v1816, -v405, v405, -v405);
      v406 = v1817;
      v407 = HIDWORD(v1816);
      *(v349 + 50) = v1816;
      *(v349 + 51) = v407;
      *(v349 + 52) = v406;
      v409 = PB_BLOCK;
      v1815 = 0;
      v1814 = 0;
      sub_8524C0(&v1814, v409, v409, -v409);
      v410 = v1815;
      v411 = HIDWORD(v1814);
      *(v349 + 53) = v1814;
      *(v349 + 54) = v411;
      *(v349 + 55) = v410;
      wpos2 = v349;
      v413 = NewSpecific(UnityEngine_Vector3, 0x18u);
      v414 = PB_BLOCK;
      v1813 = 0;
      v1812 = 0;
      v415 = v413;
      sub_8524C0(&v1812, (v414 / -2), (v414 / -2), (v414 / 2));
      v416 = v1813;
      v417 = HIDWORD(v1812);
      *(v415 + 8) = v1812;
      *(v415 + 9) = v417;
      *(v415 + 10) = v416;
      v419 = PB_BLOCK;
      v1811 = 0;
      v1810 = 0;
      sub_8524C0(&v1810, (v419 / 2), (v419 / -2), (v419 / 2));
      v420 = v1811;
      v421 = HIDWORD(v1810);
      *(v415 + 11) = v1810;
      *(v415 + 12) = v421;
      *(v415 + 13) = v420;
      v423 = PB_BLOCK;
      v1809 = 0;
      v1808 = 0;
      sub_8524C0(&v1808, (v423 / -2), (v423 / 2), (v423 / 2));
      v424 = v1809;
      v425 = HIDWORD(v1808);
      *(v415 + 14) = v1808;
      *(v415 + 15) = v425;
      *(v415 + 16) = v424;
      v427 = PB_BLOCK;
      v1807 = 0;
      v1806 = 0;
      sub_8524C0(&v1806, (v427 / 2), (v427 / 2), (v427 / 2));
      v428 = v1807;
      v429 = HIDWORD(v1806);
      *(v415 + 17) = v1806;
      *(v415 + 18) = v429;
      *(v415 + 19) = v428;
      v431 = PB_BLOCK;
      v1805 = 0;
      v1804 = 0;
      sub_8524C0(&v1804, (v431 / -2), (v431 / -2), (v431 / -2));
      v432 = v1805;
      v433 = HIDWORD(v1804);
      *(v415 + 20) = v1804;
      *(v415 + 21) = v433;
      *(v415 + 22) = v432;
      v435 = PB_BLOCK;
      v1803 = 0;
      v1802 = 0;
      sub_8524C0(&v1802, (v435 / 2), (v435 / -2), (v435 / -2));
      v436 = v1803;
      v437 = HIDWORD(v1802);
      *(v415 + 23) = v1802;
      *(v415 + 24) = v437;
      *(v415 + 25) = v436;
      v439 = PB_BLOCK;
      v1801 = 0;
      v1800 = 0;
      sub_8524C0(&v1800, (v439 / -2), (v439 / 2), (v439 / -2));
      v440 = v1801;
      v441 = HIDWORD(v1800);
      *(v415 + 26) = v1800;
      *(v415 + 27) = v441;
      *(v415 + 28) = v440;
      v443 = PB_BLOCK;
      v1799 = 0;
      v1798 = 0;
      sub_8524C0(&v1798, (v443 / 2), (v443 / 2), (v443 / -2));
      v444 = v1799;
      v445 = HIDWORD(v1798);
      *(v415 + 29) = v1798;
      *(v415 + 30) = v445;
      *(v415 + 31) = v444;
      v447 = PB_BLOCK;
      v1797 = 0;
      v1796 = 0;
      sub_8524C0(&v1796, (v447 / 2), (v447 / -2), (v447 / 2));
      v448 = v1797;
      v449 = HIDWORD(v1796);
      *(v415 + 32) = v1796;
      *(v415 + 33) = v449;
      *(v415 + 34) = v448;
      v451 = PB_BLOCK;
      v1795 = 0;
      v1794 = 0;
      sub_8524C0(&v1794, (v451 / 2), (v451 / 2), (v451 / 2));
      v452 = v1795;
      v453 = HIDWORD(v1794);
      *(v415 + 35) = v1794;
      *(v415 + 36) = v453;
      *(v415 + 37) = v452;
      v455 = PB_BLOCK;
      v1793 = 0;
      v1792 = 0;
      sub_8524C0(&v1792, (v455 / 2), (v455 / -2), (v455 / -2));
      v456 = v1793;
      v457 = HIDWORD(v1792);
      *(v415 + 38) = v1792;
      *(v415 + 39) = v457;
      *(v415 + 40) = v456;
      v459 = PB_BLOCK;
      v1791 = 0;
      v1790 = 0;
      sub_8524C0(&v1790, (v459 / 2), (v459 / 2), (v459 / -2));
      v460 = v1791;
      v461 = HIDWORD(v1790);
      *(v415 + 41) = v1790;
      *(v415 + 42) = v461;
      *(v415 + 43) = v460;
      v463 = PB_BLOCK;
      v1789 = 0;
      v1788 = 0;
      sub_8524C0(&v1788, (v463 / -2), (v463 / -2), (v463 / 2));
      v464 = v1789;
      v465 = HIDWORD(v1788);
      *(v415 + 44) = v1788;
      *(v415 + 45) = v465;
      *(v415 + 46) = v464;
      v467 = PB_BLOCK;
      v1787 = 0;
      v1786 = 0;
      sub_8524C0(&v1786, (v467 / -2), (v467 / 2), (v467 / 2));
      v468 = v1787;
      v469 = HIDWORD(v1786);
      *(v415 + 47) = v1786;
      *(v415 + 48) = v469;
      *(v415 + 49) = v468;
      v471 = PB_BLOCK;
      v1785 = 0;
      v1784 = 0;
      sub_8524C0(&v1784, (v471 / -2), (v471 / -2), (v471 / -2));
      v472 = v1785;
      v473 = HIDWORD(v1784);
      *(v415 + 50) = v1784;
      *(v415 + 51) = v473;
      *(v415 + 52) = v472;
      v475 = PB_BLOCK;
      v1783 = 0;
      v1782 = 0;
      sub_8524C0(&v1782, (v475 / -2), (v475 / 2), (v475 / -2));
      v476 = v1783;
      v477 = HIDWORD(v1782);
      *(v415 + 53) = v1782;
      *(v415 + 54) = v477;
      *(v415 + 55) = v476;
      v479 = PB_BLOCK;
      v1781 = 0;
      v1780 = 0;
      sub_8524C0(&v1780, (v479 / -2), (v479 / -2), (v479 / 2));
      v480 = v1781;
      v481 = HIDWORD(v1780);
      *(v415 + 56) = v1780;
      *(v415 + 57) = v481;
      *(v415 + 58) = v480;
      v483 = PB_BLOCK;
      v1779 = 0;
      v1778 = 0;
      sub_8524C0(&v1778, (v483 / 2), (v483 / -2), (v483 / 2));
      v484 = v1779;
      v485 = HIDWORD(v1778);
      *(v415 + 59) = v1778;
      *(v415 + 60) = v485;
      *(v415 + 61) = v484;
      v487 = PB_BLOCK;
      v1777 = 0;
      v1776 = 0;
      sub_8524C0(&v1776, (v487 / -2), (v487 / -2), (v487 / -2));
      v488 = v1777;
      v489 = HIDWORD(v1776);
      *(v415 + 62) = v1776;
      *(v415 + 63) = v489;
      *(v415 + 64) = v488;
      v491 = PB_BLOCK;
      v1775 = 0;
      v1774 = 0;
      sub_8524C0(&v1774, (v491 / 2), (v491 / -2), (v491 / -2));
      v492 = HIDWORD(v1774);
      v493 = v1775;
      *(v415 + 65) = v1774;
      *(v415 + 66) = v492;
      *(v415 + 67) = v493;
      v495 = PB_BLOCK;
      v1773 = 0;
      v1772 = 0;
      sub_8524C0(&v1772, (v495 / -2), (v495 / 2), (v495 / 2));
      v496 = HIDWORD(v1772);
      v497 = v1773;
      *(v415 + 68) = v1772;
      *(v415 + 69) = v496;
      *(v415 + 70) = v497;
      v499 = PB_BLOCK;
      v1771 = 0;
      v1770 = 0;
      sub_8524C0(&v1770, (v499 / 2), (v499 / 2), (v499 / 2));
      v500 = HIDWORD(v1770);
      v501 = v1771;
      *(v415 + 71) = v1770;
      *(v415 + 72) = v500;
      *(v415 + 73) = v501;
      v503 = PB_BLOCK;
      v1769 = 0;
      v1768 = 0;
      sub_8524C0(&v1768, (v503 / -2), (v503 / 2), (v503 / -2));
      v504 = HIDWORD(v1768);
      v505 = v1769;
      *(v415 + 74) = v1768;
      *(v415 + 75) = v504;
      *(v415 + 76) = v505;
      v507 = PB_BLOCK;
      v1767 = 0;
      v1766 = 0;
      sub_8524C0(&v1766, (v507 / 2), (v507 / 2), (v507 / -2));
      v508 = HIDWORD(v1766);
      v509 = v1767;
      *(v415 + 77) = v1766;
      *(v415 + 78) = v508;
      *(v415 + 79) = v509;
      gpos = v415;
      v511 = NewSpecific(s32, 0x24u);
      InitializeArray_1543888(v511, Field__PrivateImplementationDetails__3A0B436E7CD13DDC9EAFE5BC0A5AFFDEFE8D25DE);
      idx = v511;
      widx = NewSpecific(s32, 0);
      v512 = NewSpecific(int__, 4u);
      v513 = NewSpecific(s32, 6u);
      InitializeArray_1543888(v513, Field__PrivateImplementationDetails__BEEEBCEF33AF5B72B0463DF9185C0226DE5909AD);
      v512->m_Items[0] = v513;
      v516 = NewSpecific(s32, 6u);
      InitializeArray_1543888(v516, Field__PrivateImplementationDetails__26BB20FF8E58118938D74E24B7B3E412D7C833D2);
      v512->m_Items[1] = v516;
      v519 = NewSpecific(s32, 6u);
      InitializeArray_1543888(v519, Field__PrivateImplementationDetails__D4B99ACFBF7B848109D819ED7C091DB636CBE342);
      v512->m_Items[2] = v519;
      v522 = NewSpecific(s32, 6u);
      InitializeArray_1543888(v522, Field__PrivateImplementationDetails__11AA432D541A3A69B2CA3656E90D98E499FCDDF5);
      v512->m_Items[3] = v522;
      widx2 = v512;
      v525 = NewSpecific(s32, 0x18u);
      InitializeArray_1543888(v525, Field__PrivateImplementationDetails__37745A2AF0CA8331D100EE4F920A52726DC7B3CE);
      widx3 = v525;
      v526 = NewSpecific(UnityEngine_Vector3, 4u);
      v527 = PB_BLOCK;
      v1765 = 0;
      v1764 = 0;
      v528 = v526;
      sub_8524C0(&v1764, (-16 * v527) * 4.0, (-4 * v527), (9 * v527) * 4.0);
      v529 = HIDWORD(v1764);
      v530 = v1765;
      *(v528 + 8) = v1764;
      *(v528 + 9) = v529;
      *(v528 + 10) = v530;
      v532 = PB_BLOCK;
      v1763 = 0;
      v1762 = 0;
      sub_8524C0(&v1762, (16 * v532) * 4.0, (-4 * v532), (9 * v532) * 4.0);
      v533 = HIDWORD(v1762);
      v534 = v1763;
      *(v528 + 11) = v1762;
      *(v528 + 12) = v533;
      *(v528 + 13) = v534;
      v536 = PB_BLOCK;
      v1761 = 0;
      v1760 = 0;
      sub_8524C0(&v1760, (-16 * v536) * 4.0, (-4 * v536), (-9 * v536) * 4.0);
      v537 = HIDWORD(v1760);
      v538 = v1761;
      *(v528 + 14) = v1760;
      *(v528 + 15) = v537;
      *(v528 + 16) = v538;
      v540 = PB_BLOCK;
      v1759 = 0;
      v1758 = 0;
      sub_8524C0(&v1758, (16 * v540) * 4.0, (-4 * v540), (-9 * v540) * 4.0);
      v541 = HIDWORD(v1758);
      v542 = v1759;
      *(v528 + 17) = v1758;
      *(v528 + 18) = v541;
      *(v528 + 19) = v542;
      bgpos = v528;
      v544 = NewSpecific(s32, 6u);
      InitializeArray_1543888(v544, Field__PrivateImplementationDetails__BEEEBCEF33AF5B72B0463DF9185C0226DE5909AD);
      bgidx = v544;
      BlkInitflag = 1;
        goto LABEL_290;
      goto LABEL_272;
    }
  }
  if ((*(v44 + 295) & 2) == 0)
    goto LABEL_290;
LABEL_272:
  if (!*(v44 + 216))
  {
    if (pbBlkDalateflag != 1)
      goto LABEL_291;
    goto LABEL_274;
  }
LABEL_290:
  v546 = *(v44 + 184);
  if (pbBlkDalateflag != 1)
    goto LABEL_291;
LABEL_274:
  if (overBlkflg != 1)
    goto LABEL_291;
  if (outlineDrawflag)
  {
LABEL_291:
    if ((*(v44 + 295) & 2) == 0)
      goto LABEL_294;
    goto LABEL_292;
  }
  BlkAllDalate(v44);
  {
LABEL_292:
  }
LABEL_294:
  v547 = *(v44 + 184);
  if (overBlkflg == 1)
  {
    v551 = pMRBlk_Mesh->m_Items[pBlk_MeshCnt];
    v552 = op_Equality(v551, 0, 0);
    if ((v45 & 0xFFFFFFFE) == 4 && v552)
    {
      v553 = *(v44 + 184);
      v554 = *(v553 + 96);
      v555 = *(v553 + 84);
      {
      }
      Instance = get_Instance();
      Mesh = GetMesh(Instance, 4, 1);
      v558 = Mesh;
      *&v554[2 * v555 + 8] = v558;
      v562 = pMRBlk_Mesh;
      v563 = pBlk_MeshCnt;
      transform = get_transform(v562->m_Items[v563], 0);
      position = get_position(transform);
      pMRBlk_MeshPos = position;
    }
  }
  v566 = *(v44 + 184);
  if (overBlkflg == 2)
  {
    if (op_Equality(pGoalBlk_Mesh, 0, 0))
    {
      {
      }
      v568 = get_Instance();
      v570 = GetMesh(v568, 2, 0);
      pGoalBlk_Mesh = v570;
      v572 = get_transform(pGoalBlk_Mesh, 0);
      pGoalBlk_MeshPos = get_position(v572);
    }
  }
  if (clearAutLine == 1)
  {
    v574 = Allocate(System_Collections_Generic_Dictionary_string__GameObject_);
    PropertySheet____ctor(v574);
    Line3D = v574;
    clearAutLine = 0;
  }
  else
  {
    if (overBlkflg != 1)
      goto LABEL_400;
  }
  else if (outlineDrawflag)
  {
    goto LABEL_400;
  }
  if (mBlk_grpCnt)
  {
    if (!mBlkPosbup)
    {
      v579 = NewSpecific(UnityEngine_Vector3__, mBlk_grpCnt);
      mBlkPosbup = v579;
    }
    if (!mBlkPosbup->m_Items[mBlk_allCnt])
    {
      v584 = 0;
        goto LABEL_378;
LABEL_373:
      else
      {
        if (v584 < mBlk_grpCnt)
          goto LABEL_379;
      }
    }
  }
  sub_854710(&mrpb_angle, 1u);
  v594 = v45 - 4;
  if (v595 == 0.0)
  {
    if (v594 >= 2)
    {
      if (v45 == 3)
      {
        if (mBlk_grpCnt)
        {
          if ((v596->_2.bitflags2 & 2) == 0)
            goto LABEL_584;
LABEL_582:
LABEL_584:
          v710 = mBlkPosbup;
          v711 = mBlk_allCnt;
          v713 = v710 + 8 * v711;
          v715 = *(v713 + 32);
          sub_854710(&v1966, 0);
          v717 = v716;
          sub_854710(&v1966, 1u);
          v719 = v718;
          sub_854710(&v1966, 2u);
          LODWORD(value) = 0;
          v1756 = 0;
          sub_8524C0(&v1756, v717, -v719, v720);
          v721 = HIDWORD(v1756);
          v722 = value;
          v724 = (v715 + 12 * mBlkPosbupCnt);
          v724[8] = v1756;
          v724[9] = v721;
          v724[10] = v722;
          ++mBlkPosbupCnt;
            goto LABEL_403;
LABEL_401:
          goto LABEL_403;
        }
      }
      else if (v45 == 2)
      {
          goto LABEL_584;
        goto LABEL_582;
      }
LABEL_400:
        goto LABEL_403;
      goto LABEL_401;
    }
    v663 = pMRBlk_Mesh;
    v664 = pBlk_MeshCnt;
    v666 = get_transform(v663->m_Items[v664], 0);
    x = pMRBlk_MeshPos.x;
    v668 = v666;
    sub_854710(&v1966, 0);
    v669 = pMRBlk_MeshPos.y;
    v671 = v670;
    sub_854710(&v1966, 1u);
    v672 = pMRBlk_MeshPos.z;
    v674 = v673;
    sub_854710(&v1966, 2u);
    v675 = v669 - v674;
    v677 = v672 + v676;
    v678 = x + v671;
    LODWORD(value) = 0;
    v1756 = 0;
    goto LABEL_572;
  }
  if (v594 >= 2)
  {
    if (v45 == 3)
    {
      if (!mBlk_grpCnt)
        goto LABEL_400;
      if ((v638->_2.bitflags2 & 2) == 0)
        goto LABEL_776;
    }
    else
    {
      if (v45 != 2)
        goto LABEL_400;
        goto LABEL_776;
    }
LABEL_776:
    v897 = mBlkPosbup;
    v898 = mBlk_allCnt;
    v900 = v897 + 8 * v898;
    v901 = mBlkPosbupCnt;
    v902 = *(v900 + 32);
    sub_854710(&v1966, 0);
    v904 = v903;
    sub_854710(&v1966, 1u);
    v906 = v905;
    sub_854710(&v1966, 2u);
    LODWORD(value) = 0;
    v1756 = 0;
    sub_8524C0(&v1756, v904, -v906, v907);
    v908 = HIDWORD(v1756);
    v909 = value;
    v911 = (v902 + 12 * v901);
    v911[8] = v1756;
    v911[9] = v908;
    v911[10] = v909;
      goto LABEL_401;
    goto LABEL_403;
  }
  v693 = pMRBlk_Mesh;
  v694 = pBlk_MeshCnt;
  v696 = get_transform(v693->m_Items[v694], 0);
  v697 = pMRBlk_MeshPos.x;
  v668 = v696;
  sub_854710(&v1966, 0);
  v699 = v698;
  sub_854710(&v1966, 1u);
  v700 = pMRBlk_MeshPos.z;
  v702 = v701;
  sub_854710(&v1966, 2u);
  LODWORD(value) = 0;
  v1756 = 0;
  v677 = v700 + v703;
  v678 = v697 + v699;
  v675 = v702;
LABEL_572:
  sub_8524C0(&v1756, v678, v675, v677);
  *&v1974.x = v1756;
  LODWORD(v1974.z) = value;
  set_position(v668, v1974);
  v706 = v1966.x;
  v705 = v1966.y;
  v708 = v1966.z;
  w = v1966.w;
  v1981.x = v706;
  v1981.y = v705;
  v1981.z = v708;
  v1981.w = w;
  outline_vec3 = op_Implicit_8738992(v1981);
    goto LABEL_401;
LABEL_403:
  if (overBlkflg == 2)
  {
    grot = grot + 0.2;
    v600 = get_transform((*p_static_fields)->pGoalBlk_Mesh, 0);
    v601 = pGoalBlk_MeshPos.x;
    v602 = v600;
    sub_854710(&v1966, 0);
    v603 = pGoalBlk_MeshPos.y;
    v605 = v604;
    sub_854710(&v1966, 1u);
    v606 = pGoalBlk_MeshPos.z;
    v608 = v607;
    sub_854710(&v1966, 2u);
    LODWORD(value) = 0;
    v1756 = 0;
    sub_8524C0(&v1756, v601 + v605, v603 - v608, v606 + v609);
    *&v1973.x = v1756;
    LODWORD(v1973.z) = value;
    set_position(v602, v1973);
    v610 = get_transform(pGoalBlk_Mesh, 0);
    v1962.z = 0.0;
    *&v1962.x = 0;
    sub_8524C0(&v1962.x, 0.0, 1.0, 0.0);
    Rotate_27486976(v610, v1962);
  }
  else
  {
    if (overBlkflg)
      goto LABEL_427;
  }
  if (NBlkDrawflag)
  {
LABEL_427:
    else
    {
      if (overBlkflg != 1)
        goto LABEL_1215;
    }
    else if (outlineDrawflag)
    {
      goto LABEL_1215;
    }
    v613 = v45 & 0xFFFFFFFE;
    if ((v45 & 0xFFFFFFFE) == 4)
    {
      v614 = pMRBlk_Mesh;
      v615 = pBlk_MeshCnt;
      SetPosition_20241056(v614->m_Items[v615], npos);
      v618 = pMRBlk_Mesh;
      v619 = pBlk_MeshCnt;
      SetIndexTable(v618->m_Items[v619], idx);
      v622 = pMRBlk_Mesh;
      v623 = pBlk_MeshCnt;
      SetColor_20241296(v622->m_Items[v623], col);
    }
    if (v45 == 5)
    {
      v641 = pMRBlk_Mesh;
      v642 = pBlk_MeshCnt;
      v644 = v641->m_Items[v642];
      SetMatTexture(v644, pbWk->blockTex);
      v647 = pMRBlk_Mesh;
      v648 = pBlk_MeshCnt;
      v636 = v647->m_Items[v648];
    }
    else
    {
      if (v45 != 4)
      {
LABEL_478:
        if (MRblockAutLine == 1)
        {
          if (changeAutLine == 1)
          {
            Destroy_27360000(pMRBlk_GameObj);
            PropertySheet___Clear(Line3D);
            v656 = Allocate(System_Collections_Generic_Dictionary_string__GameObject_);
            PropertySheet____ctor(v656);
            Line3D = v656;
          }
          --autLineDeleteCnt;
          if ((v652->_2.bitflags2 & 2) == 0)
            goto LABEL_506;
        }
        else
        {
          {
LABEL_506:
            if (autLineDeleteCnt < 0)
            {
              MRblockAutLine = 0;
              autLineDeleteflag = 0;
            }
            if (autLineDeleteCnt >= pBlk_MeshCnt)
              goto LABEL_1784;
            if (autLineDeleteflag)
            {
LABEL_1784:
              autLineDeleteflag = 1;
            }
            else
            {
              autLineDeleteCnt = pBlk_MeshCnt;
            }
            v659 = NewSpecific(UnityEngine_Vector3__, 4u);
            autLinePos = v659;
            if (outlineDrawflag)
              goto LABEL_1215;
            if (MoveBlkFallflag)
            {
                goto LABEL_1216;
              goto LABEL_535;
            }
            v725 = 0;
            while (1)
            {
              v731 = outLineChk + 8 * outLineChkCnt;
              v733 = *(v731 + 32);
              if (((1 << v725) & *(v733 + outLineChkCnt2 + 32)) == 0)
                goto LABEL_763;
              v736 = 0;
              do
              {
                v739 = v736;
                if (!autLinePos->m_Items[v725])
                {
                  v743 = autLinePos;
                  v744 = NewSpecific(UnityEngine_Vector3, 2u);
                  v745 = v744;
                  *&v743[2 * v725 + 8] = v745;
                }
                if (v739 + v725 <= 3)
                  v748 = v739 + v725;
                else
                  v748 = 0;
                if (v613 == 4)
                {
                  v750 = autLinePos;
                  v752 = v750 + 8 * v725;
                  v753 = pMRBlk_Mesh;
                  v754 = pBlk_MeshCnt;
                  v755 = *(v752 + 32);
                  v757 = get_transform(v753->m_Items[v754], 0);
                  v1963 = get_position(v757);
                  v758 = sub_8527D0(&v1963.x, 0);
                  v760 = v758;
                  v762 = sub_8527D0(&autPos->m_Items[v748].x, 0);
                  sub_8529B0(v755 + 12 * v739 + 32, 0, v760 - v762);
                  v765 = autLinePos;
                  v767 = pMRBlk_Mesh;
                  v768 = pBlk_MeshCnt;
                  v769 = v765->m_Items[v725];
                  v771 = get_transform(v767->m_Items[v768], 0);
                  v1963 = get_position(v771);
                  v772 = sub_8527D0(&v1963.x, 1);
                  v773 = autPos;
                  v774 = v772;
                  v776 = sub_8527D0(&v773->m_Items[v748].x, 1);
                  sub_8529B0(&v769->m_Items[v739], 1, (v774 - v776) + 0.3);
                  v779 = autLinePos;
                  v781 = pMRBlk_Mesh;
                  v782 = pBlk_MeshCnt;
                  v783 = v779->m_Items[v725];
                  v785 = get_transform(v781->m_Items[v782], 0);
                  v1963 = get_position(v785);
                  v786 = sub_8527D0(&v1963.x, 2);
                  v787 = autPos;
                  v788 = v786;
                  v790 = sub_8527D0(&v787->m_Items[v748].x, 2);
                  sub_8529B0(&v783->m_Items[v739], 2, v788 - v790);
                  v793 = pos;
                }
                else
                {
                  v795 = autLinePos;
                  v797 = v795 + 8 * v725;
                  v798 = mBlkPosbup;
                  v799 = *(v797 + 32);
                  v800 = mBlk_allCnt;
                  v802 = v798->m_Items[v800];
                  v803 = mBlkPosbupCnt - 1LL;
                  v805 = sub_8527D0(&v802->m_Items[v803].x, 0);
                  v806 = autPos;
                  v807 = v805;
                  v809 = sub_8527D0(&v806->m_Items[v748].x, 0);
                  sub_8529B0(v799 + 12 * v739 + 32, 0, v807 - v809);
                  v812 = autLinePos;
                  v814 = mBlkPosbup;
                  v815 = v812->m_Items[v725];
                  v816 = mBlk_allCnt;
                  v818 = v814->m_Items[v816];
                  v819 = mBlkPosbupCnt - 1LL;
                  v821 = sub_8527D0(&v818->m_Items[v819].x, 1);
                  v822 = autPos;
                  v823 = v821;
                  v825 = sub_8527D0(&v822->m_Items[v748].x, 1);
                  sub_8529B0(&v815->m_Items[v739], 1, (v823 - v825) + 0.3);
                  v828 = autLinePos;
                  v830 = mBlkPosbup;
                  v831 = v828->m_Items[v725];
                  v832 = mBlk_allCnt;
                  v834 = v830->m_Items[v832];
                  v835 = mBlkPosbupCnt - 1LL;
                  v837 = sub_8527D0(&v834->m_Items[v835].x, 2);
                  v838 = autPos;
                  v839 = v837;
                  v841 = sub_8527D0(&v838->m_Items[v748].x, 2);
                  sub_8529B0(&v831->m_Items[v739], 2, v839 - v841);
                  v793 = 0;
                }
                autline_type = v793;
                v843 = *&v735->_2.bitflags1;
                v737 = (v843 & 0x200) == 0;
                v736 = 1;
              }
              while (!v739);
              v844 = v843 & 0x200;
              if (v613 != 4)
              {
                if (MBlockOutCnt >= SLODWORD(MBlockStrbup->max_length))
                {
                  MBlockOutDrawFlag = 0;
                }
                if (MBlockOutDrawFlag)
                {
                  v849 = MBlockStrbup->m_Items[MBlockOutCnt];
                    goto LABEL_713;
                }
                else
                {
                  v871 = NewSpecific(object, 4u);
                  if ("MblkAutLine"
                    && !QueryInterface("MblkAutLine", v871->obj.klass->_1.element_class))
                  {
                  }
                  v871->m_Items[0] = "MblkAutLine";
                  LODWORD(v1756) = autLineCnt;
                  v875 = sub_8D3950(s32, &v1756);
                  v876 = v875;
                  v871->m_Items[1] = v876;
                  LODWORD(v1962.x) = mBlk_allCnt;
                  v879 = sub_8D3950(s32, &v1962);
                  v880 = v879;
                  v871->m_Items[2] = v880;
                  LODWORD(v1960) = mBlkPosbupCnt;
                  v883 = sub_8D3950(s32, &v1960);
                  v884 = v883;
                  v871->m_Items[3] = v884;
                  v849 = Concat_5270224(v871);
                  Resize_string_(
                    &MBlockStrbup,
                    LODWORD(MBlockStrbup->max_length) + 1);
                  v888 = MBlockStrbup;
                  v889 = MBlockOutCnt;
                  v888->m_Items[v889] = v849;
                  {
LABEL_713:
                  }
                }
                ++MBlockOutCnt;
                v893 = autLinePos;
                p_pMBlk_GameObj = &pMBlk_GameObj;
                v868 = v893->m_Items[v725];
                v869 = &"AUTLINE_M";
                goto LABEL_759;
              }
              if (RBlockOutDrawFlag)
              {
                v849 = RBlockStrbup->m_Items[RBlockOutCnt];
                  goto LABEL_724;
              }
              else
              {
                LODWORD(v1756) = autLineCnt;
                v857 = sub_8D3950(s32, &v1756);
                LODWORD(v1962.x) = pBlk_MeshCnt;
                v858 = sub_8D3950(s32, &v1962);
                v849 = Concat_5269984("RblkAutLine", v857, v858);
                Resize_string_(
                  &RBlockStrbup,
                  LODWORD(RBlockStrbup->max_length) + 1);
                v860 = RBlockStrbup;
                v861 = RBlockOutCnt;
                v860->m_Items[v861] = v849;
                  goto LABEL_724;
              }
LABEL_724:
              ++RBlockOutCnt;
              v865 = autLinePos;
              p_pMBlk_GameObj = &pMRBlk_GameObj;
              v868 = v865->m_Items[v725];
              v869 = &"AUTLINE_MR";
LABEL_759:
              AutLineDraw(p_pMBlk_GameObj, *v869, v849, 0xFFFFFFu, 2, v868);
              ++autLineCnt;
LABEL_763:
              if (++v725 == 4)
              {
                autLineCnt = 0;
                if ((v597->_2.bitflags2 & 2) == 0)
                  goto LABEL_1216;
LABEL_535:
                goto LABEL_1216;
              }
            }
          }
        }
        goto LABEL_506;
      }
      v627 = pMRBlk_Mesh;
      v628 = pBlk_MeshCnt;
      v630 = v627->m_Items[v628];
      SetMatTexture(v630, pbWk->blockTex);
      v633 = pMRBlk_Mesh;
      v634 = pBlk_MeshCnt;
      v636 = v633->m_Items[v634];
      rnd_uvpos = rcore_uvpos;
    }
    SetUvTable_20243232(v636, rnd_uvpos);
    goto LABEL_478;
  }
  if (v45 == 1)
  {
    if (!WallChangeflag)
    {
      v681 = NewSpecific(s32, 0x18u);
      v682 = v681;
      widxbup->m_Items[wBlk_allCnt] = v682;
      v687 = widxbup;
      v688 = wBlk_allCnt;
      v689 = v687->m_Items[v688];
      v689->m_Items[0] = 0;
      v915 = widxbup;
      v916 = wBlk_allCnt;
      v918 = v915->m_Items[v916];
      v918->m_Items[1] = 0;
      v922 = widxbup;
      v923 = wBlk_allCnt;
      v925 = v922->m_Items[v923];
      v925->m_Items[2] = 0;
      v929 = widxbup;
      v930 = wBlk_allCnt;
      v932 = v929->m_Items[v930];
      v932->m_Items[3] = 0;
      v936 = widxbup;
      v937 = wBlk_allCnt;
      v939 = v936->m_Items[v937];
      v939->m_Items[4] = 0;
      v943 = widxbup;
      v944 = wBlk_allCnt;
      v946 = v943->m_Items[v944];
      v946->m_Items[5] = 0;
      v948 = 0;
      posa = 0;
      while (1)
      {
        v960 = wBlk_allCnt;
        v962 = facebup->m_Items[v960];
        if (!v962->m_Items[v948])
          goto LABEL_1206;
        v966 = facebup;
        v967 = wBlk_allCnt;
        v969 = v966->m_Items[v967];
        v970 = v969->m_Items[v948];
        if ((v970 & 2) != 0)
        {
          Resize_int_(
            &widx,
            LODWORD(widx->max_length) + 6);
          if (!flag1)
          {
            v1077 = 6LL * posa;
            v1078 = widx2->m_Items[0];
            v1079 = v1078->m_Items[0];
            widx->m_Items[6 * posa] = v1079;
            v1083 = widx2;
            v1084 = widx;
            v1086 = v1083->m_Items[0];
            v1084->m_Items[v1077 | 1] = v1086->m_Items[1];
            v1091 = widx2;
            v1092 = widx;
            v1094 = v1091->m_Items[0];
            v1096 = v1094->m_Items[2];
            v1092->m_Items[v1077 + 2] = v1096;
            v1100 = widx2;
            v1101 = widx;
            v1103 = v1100->m_Items[0];
            v1101->m_Items[v1077 + 3] = v1103->m_Items[3];
            v1108 = widx2;
            v1109 = widx;
            v1111 = v1108->m_Items[0];
            v1113 = v1111->m_Items[4];
            v1109->m_Items[v1077 + 4] = v1113;
            v1117 = widx2;
            v1118 = widx;
            v1120 = v1117->m_Items[0];
            v1122 = v1120->m_Items[5];
            v1123 = v1077 + 5;
            v1118->m_Items[v1123] = v1122;
          }
          flag1 = 1;
          v1126 = NewSpecific(UnityEngine_Vector3, 4u);
          v1128 = 0;
          v1130 = 80;
          do
          {
            v1133 = wBlkPosbupCnt - 1LL;
            v1135 = sub_8527D0(&wBlkPosbup->m_Items[v1133].x, 0);
            v1137 = v1135;
            v1138 = v1128 + 4;
            v1140 = sub_8527D0((WallautPos + v1130), 0);
            sub_8529B0(v1126 + v1130 - 48, 0, v1137 - v1140);
            v1143 = wBlkPosbup;
            v1144 = wBlkPosbupCnt - 1LL;
            v1146 = sub_8527D0(&v1143->m_Items[v1144].x, 1);
            v1147 = WallautPos;
            v1148 = v1146;
            v1150 = sub_8527D0((v1147 + v1130), 1);
            sub_8529B0(v1126 + v1130 - 48, 1, v1148 - v1150);
            v1153 = wBlkPosbup;
            v1154 = wBlkPosbupCnt - 1LL;
            v1156 = sub_8527D0(&v1153->m_Items[v1154].x, 2);
            v1157 = WallautPos;
            v1158 = v1156;
            v1160 = sub_8527D0((v1157 + v1130), 2);
            sub_8529B0(v1126 + v1130 - 48, 2, v1158 - v1160);
            ++v1128;
            v1130 += 12;
          }
          while (v1128 != 4);
          LODWORD(v1756) = autLineCnt;
          v1162 = sub_8D3950(s32, &v1756);
          LODWORD(v1962.x) = pBlk_MeshCnt;
          v1163 = sub_8D3950(s32, &v1962);
          v1164 = Concat_5269984("blkAutLine", v1162, v1163);
          ++autLineCnt;
          AutLineDraw(&pBlk_GameObj, "AUTLINE", v1164, 0x808080u, 4, v1126);
          if ((v970 & 4) == 0)
          {
LABEL_843:
            if ((v970 & 8) != 0)
              goto LABEL_1107;
            goto LABEL_844;
          }
        }
        else if ((v970 & 4) == 0)
        {
          goto LABEL_843;
        }
        Resize_int_(
          &widx,
          LODWORD(widx->max_length) + 6);
        if (!flag2)
        {
          v1171 = widx2;
          v1172 = widx;
          v1173 = 6LL * posa;
          v1174 = v1171->m_Items[1];
          v1175 = v1174->m_Items[0];
          v1172->m_Items[6 * posa] = v1175;
          v1179 = widx2;
          v1180 = widx;
          v1182 = v1179->m_Items[1];
          v1180->m_Items[v1173 | 1] = v1182->m_Items[1];
          v1187 = widx2;
          v1188 = widx;
          v1190 = v1187->m_Items[1];
          v1192 = v1190->m_Items[2];
          v1188->m_Items[v1173 + 2] = v1192;
          v1196 = widx2;
          v1197 = widx;
          v1199 = v1196->m_Items[1];
          v1197->m_Items[v1173 + 3] = v1199->m_Items[3];
          v1204 = widx2;
          v1205 = widx;
          v1207 = v1204->m_Items[1];
          v1209 = v1207->m_Items[4];
          v1205->m_Items[v1173 + 4] = v1209;
          v1213 = widx2;
          v1214 = widx;
          v1216 = v1213->m_Items[1];
          v1218 = v1216->m_Items[5];
          v1219 = v1173 + 5;
          v1214->m_Items[v1219] = v1218;
        }
        flag2 = 1;
        v1222 = NewSpecific(UnityEngine_Vector3, 4u);
        v1224 = 0;
        v1226 = 32;
        do
        {
          v1228 = wBlkPosbup;
          v1229 = wBlkPosbupCnt - 1LL;
          v1231 = sub_8527D0(&v1228->m_Items[v1229].x, 0);
          v1232 = WallautPos;
          v1233 = v1231;
          v1235 = sub_8527D0((v1232 + v1226), 0);
          sub_8529B0(v1222 + v1226, 0, v1233 - v1235);
          v1238 = wBlkPosbup;
          v1239 = wBlkPosbupCnt - 1LL;
          v1241 = sub_8527D0(&v1238->m_Items[v1239].x, 1);
          v1242 = WallautPos;
          v1243 = v1241;
          v1245 = sub_8527D0((v1242 + v1226), 1);
          sub_8529B0(v1222 + v1226, 1, v1243 - v1245);
          v1248 = wBlkPosbup;
          v1249 = wBlkPosbupCnt - 1LL;
          v1251 = sub_8527D0(&v1248->m_Items[v1249].x, 2);
          v1252 = WallautPos;
          v1253 = v1251;
          v1255 = sub_8527D0((v1252 + v1226), 2);
          sub_8529B0(v1222 + v1226, 2, v1253 - v1255);
          ++v1224;
          v1226 += 12;
        }
        while (v1224 != 4);
        LODWORD(v1756) = autLineCnt;
        v1257 = sub_8D3950(s32, &v1756);
        LODWORD(v1962.x) = pBlk_MeshCnt;
        v1258 = sub_8D3950(s32, &v1962);
        v1259 = Concat_5269984("blkAutLine", v1257, v1258);
        ++autLineCnt;
        AutLineDraw(&pBlk_GameObj, "AUTLINE", v1259, 0x808080u, 4, v1222);
        if ((v970 & 8) != 0)
        {
LABEL_1107:
          Resize_int_(
            &widx,
            LODWORD(widx->max_length) + 6);
          if (!flag3)
          {
            v1266 = widx2;
            v1267 = widx;
            v1268 = 6LL * posa;
            v1269 = v1266->m_Items[2];
            v1270 = v1269->m_Items[0];
            v1267->m_Items[6 * posa] = v1270;
            v1274 = widx2;
            v1275 = widx;
            v1277 = v1274->m_Items[2];
            v1275->m_Items[v1268 | 1] = v1277->m_Items[1];
            v1282 = widx2;
            v1283 = widx;
            v1285 = v1282->m_Items[2];
            v1287 = v1285->m_Items[2];
            v1283->m_Items[v1268 + 2] = v1287;
            v1291 = widx2;
            v1292 = widx;
            v1294 = v1291->m_Items[2];
            v1292->m_Items[v1268 + 3] = v1294->m_Items[3];
            v1299 = widx2;
            v1300 = widx;
            v1302 = v1299->m_Items[2];
            v1304 = v1302->m_Items[4];
            v1300->m_Items[v1268 + 4] = v1304;
            v1308 = widx2;
            v1309 = widx;
            v1311 = v1308->m_Items[2];
            v1313 = v1311->m_Items[5];
            v1314 = v1268 + 5;
            v1309->m_Items[v1314] = v1313;
          }
          flag3 = 1;
          v1317 = NewSpecific(UnityEngine_Vector3, 4u);
          v1319 = 0;
          v1321 = 176;
          do
          {
            v1323 = wBlkPosbup;
            v1324 = wBlkPosbupCnt - 1LL;
            v1326 = sub_8527D0(&v1323->m_Items[v1324].x, 0);
            v1327 = v1319 + 12;
            v1328 = WallautPos;
            v1329 = v1326;
            v1331 = sub_8527D0((v1328 + v1321), 0);
            sub_8529B0(v1317 + v1321 - 144, 0, v1329 - v1331);
            v1334 = wBlkPosbup;
            v1335 = wBlkPosbupCnt - 1LL;
            v1337 = sub_8527D0(&v1334->m_Items[v1335].x, 1);
            v1338 = WallautPos;
            v1339 = v1337;
            v1341 = sub_8527D0((v1338 + v1321), 1);
            sub_8529B0(v1317 + v1321 - 144, 1, v1339 - v1341);
            v1344 = wBlkPosbup;
            v1345 = wBlkPosbupCnt - 1LL;
            v1347 = sub_8527D0(&v1344->m_Items[v1345].x, 2);
            v1348 = WallautPos;
            v1349 = v1347;
            v1351 = sub_8527D0((v1348 + v1321), 2);
            sub_8529B0(v1317 + v1321 - 144, 2, v1349 - v1351);
            ++v1319;
            v1321 += 12;
          }
          while (v1319 != 4);
          LODWORD(v1756) = autLineCnt;
          v1353 = sub_8D3950(s32, &v1756);
          LODWORD(v1962.x) = pBlk_MeshCnt;
          v1354 = sub_8D3950(s32, &v1962);
          v1355 = Concat_5269984("blkAutLine", v1353, v1354);
          ++autLineCnt;
          AutLineDraw(&pBlk_GameObj, "AUTLINE", v1355, 0x808080u, 4, v1317);
          v971 = posa + 1;
          if ((v970 & 0x10) == 0)
            goto LABEL_1194;
LABEL_845:
          Resize_int_(
            &widx,
            LODWORD(widx->max_length) + 6);
          if (!flag4)
          {
            v976 = widx2;
            v977 = widx;
            v978 = 6LL * posa;
            v979 = v976->m_Items[3];
            v980 = v979->m_Items[0];
            v977->m_Items[6 * posa] = v980;
            v984 = widx2;
            v985 = widx;
            v987 = v984->m_Items[3];
            v989 = v987->m_Items[1];
            v985->m_Items[v978 | 1] = v989;
            v993 = widx2;
            v994 = widx;
            v996 = v993->m_Items[3];
            v998 = v996->m_Items[2];
            v994->m_Items[v978 + 2] = v998;
            v1002 = widx2;
            v1003 = widx;
            v1005 = v1002->m_Items[3];
            v1007 = v1005->m_Items[3];
            v1003->m_Items[v978 + 3] = v1007;
            v1011 = widx2;
            v1012 = widx;
            v1014 = v1011->m_Items[3];
            v1016 = v1014->m_Items[4];
            v1012->m_Items[v978 + 4] = v1016;
            v1020 = widx2;
            v1021 = widx;
            v1023 = v1020->m_Items[3];
            v1025 = v1023->m_Items[5];
            v1026 = v978 + 5;
            v1021->m_Items[v1026] = v1025;
          }
          flag4 = 1;
          v1029 = NewSpecific(UnityEngine_Vector3, 4u);
          v1031 = 0;
          v1033 = 128;
          do
          {
            v1035 = wBlkPosbup;
            v1036 = wBlkPosbupCnt - 1LL;
            v1038 = sub_8527D0(&v1035->m_Items[v1036].x, 0);
            v1039 = WallautPos;
            v1040 = v1038;
            v1041 = v1031 + 8;
            v1043 = sub_8527D0((v1039 + v1033), 0);
            sub_8529B0(v1029 + v1033 - 96, 0, v1040 - v1043);
            v1046 = wBlkPosbup;
            v1047 = wBlkPosbupCnt - 1LL;
            v1049 = sub_8527D0(&v1046->m_Items[v1047].x, 1);
            v1050 = WallautPos;
            v1051 = v1049;
            v1053 = sub_8527D0((v1050 + v1033), 1);
            sub_8529B0(v1029 + v1033 - 96, 1, v1051 - v1053);
            v1056 = wBlkPosbup;
            v1057 = wBlkPosbupCnt - 1LL;
            v1059 = sub_8527D0(&v1056->m_Items[v1057].x, 2);
            v1060 = WallautPos;
            v1061 = v1059;
            v1063 = sub_8527D0((v1060 + v1033), 2);
            sub_8529B0(v1029 + v1033 - 96, 2, v1061 - v1063);
            ++v1031;
            v1033 += 12;
          }
          while (v1031 != 4);
          LODWORD(v1756) = autLineCnt;
          v1065 = sub_8D3950(s32, &v1756);
          LODWORD(v1962.x) = pBlk_MeshCnt;
          v1066 = sub_8D3950(s32, &v1962);
          v1067 = Concat_5269984("blkAutLine", v1065, v1066);
          ++autLineCnt;
          AutLineDraw(&pBlk_GameObj, "AUTLINE", v1067, 0x808080u, 4, v1029);
          goto LABEL_1194;
        }
LABEL_844:
        v971 = posa + 1;
        if ((v970 & 0x10) != 0)
          goto LABEL_845;
LABEL_1194:
        v1358 = 6 * posa;
        v1359 = 0;
        v1360 = 24LL * posa + 32;
        do
        {
          v1363 = widxbup;
          v1364 = wBlk_allCnt;
          v1366 = widx;
          v1367 = v1363->m_Items[v1364];
          v1369 = *(&v1366->obj.klass + 4 * v1359 + v1360);
          *(&v1367->obj.klass + 4 * v1359++ + v1360) = v1369;
        }
        while (v1359 != 6);
        posa = v971;
LABEL_1206:
        ++v948;
        v949 = (v1371 >> 9) & 1;
        if (v948 == 4)
        {
          flag1 = 0;
          flag2 = 0;
          flag3 = 0;
          flag4 = 0;
          autLineCnt = 0;
          if (pBlk_MeshCnt < blk_max)
          {
            ++wBlk_allCnt;
          }
          break;
        }
      }
    }
LABEL_1215:
    if ((v597->_2.bitflags2 & 2) == 0)
      goto LABEL_1216;
    goto LABEL_535;
  }
  if (v45)
    goto LABEL_1215;
  if (pBlk_MeshCnt >= blk_max)
    goto LABEL_1215;
  ++fBlk_allCnt;
  if ((v597->_2.bitflags2 & 2) != 0)
    goto LABEL_535;
LABEL_1216:
  if (pBlk_MeshCnt != blk_max - 1)
    goto LABEL_1221;
  if (NBlkDrawflag)
  {
LABEL_1221:
    if ((v597->_2.bitflags2 & 2) == 0)
      goto LABEL_1455;
    goto LABEL_1222;
  }
  if (fBlk_allCntbup != fBlk_allCnt)
  {
    fBlk_allCntbup = fBlk_allCnt;
    allMesh = (*v1373)->allMesh;
    if (op_Equality(allMesh, 0, 0))
    {
      {
      }
      v1383 = get_Instance();
      v1384 = GetMesh(v1383, 4, 1);
      allMesh = v1384;
      if ((v1385->_2.bitflags2 & 2) == 0)
        goto LABEL_1269;
    }
    else
    {
      {
LABEL_1269:
        v1386 = NewSpecific(
                  UnityEngine_Vector3,
                  (fBlk_allCnt * LODWORD(npos->max_length)));
        v1387 = NewSpecific(
                  s32,
                  (fBlk_allCnt * LODWORD(idx->max_length)));
        v1748 = NewSpecific(UnityEngine_Color, (24 * fBlk_allCnt));
        v1389 = NewSpecific(UnityEngine_Vector2, (24 * fBlk_allCnt));
        v1390 = 0;
        v1391 = &col->m_Items[0].a;
        do
        {
          g = DefblockCol.g;
          v1395 = DefblockCol.b;
          a = DefblockCol.a;
          ++v1390;
          *(v1391 - 3) = DefblockCol.r;
          *(v1391 - 2) = g;
          *(v1391 - 1) = v1395;
          *v1391 = a;
          v1391 += 4;
        }
        while (v1390 != 24);
        v1398 = 0;
        v1739 = v1386;
        v1399 = 0;
        m_Items = v1389->m_Items;
        v1741 = v1389;
          goto LABEL_1281;
LABEL_1277:
        else
        {
          if (v1399 < fBlk_allCnt)
            goto LABEL_1282;
        }
        SetPosition_20241056(allMesh, v1386);
        SetIndexTable(allMesh, v1387);
        SetColor_20241296(allMesh, v1748);
        v1446 = allMesh;
        SetMatTexture(v1446, pbWk->blockTex);
        SetUvTable_20243232(allMesh, v1389);
        goto LABEL_1336;
      }
    }
    goto LABEL_1269;
  }
LABEL_1336:
  fBlk_allCnt = 0;
  fBlkPosbupCnt = 0;
  if (!WallChangeflag)
  {
    if (op_Equality(allwMesh, 0, 0))
    {
      {
      }
      v1450 = get_Instance();
      v1451 = GetMesh(v1450, 5, 1);
      allwMesh = v1451;
      if ((v1452->_2.bitflags2 & 2) == 0)
      {
LABEL_1358:
        v1453 = NewSpecific(
                  UnityEngine_Vector3,
                  (wBlk_allCnt * LODWORD(wpos->max_length)));
        allwpos = v1453;
        v1455 = NewSpecific(
                  UnityEngine_Vector3,
                  (wBlk_allCnt * LODWORD(wpos->max_length)));
        allw2pos = v1455;
        v1457 = NewSpecific(s32, (24 * wBlk_allCnt));
        allwidx = v1457;
        v1459 = NewSpecific(UnityEngine_Color, (16 * wBlk_allCnt));
        allwcolor = v1459;
        v1461 = NewSpecific(UnityEngine_Vector2, (16 * wBlk_allCnt));
        alluvwpos = v1461;
        alluvw2pos = NewSpecific(
                                                       UnityEngine_Vector2,
                                                       (16 * wBlk_allCnt));
        v1463 = 0;
        v1464 = v1746 + 11;
        do
        {
          v1756 = 0;
          value = 0;
          sub_19EC630(&v1756, v1972.x, v1972.y, v1972.z, v1972.w + -0.8);
          v1466 = HIDWORD(v1756);
          v1468 = value;
          v1467 = HIDWORD(value);
          ++v1463;
          *(v1464 - 3) = v1756;
          *(v1464 - 2) = v1466;
          *(v1464 - 1) = v1468;
          *v1464 = v1467;
          v1464 += 4;
        }
        while (v1463 != 16);
        v1470 = 0;
        v1471 = 0;
        posc = 0;
        v1472 = 0;
        v1744 = v1746 + 11;
          goto LABEL_1367;
LABEL_1363:
        else
        {
          if (v1472 < wBlk_allCnt)
            goto LABEL_1368;
        }
        SetPosition_20241056(allwMesh, allwpos);
        SetIndexTable(allwMesh, allwidx);
        SetColor_20241296(allwMesh, allwcolor);
        v1548 = allwMesh;
        SetMatTexture(v1548, pbWk->blockTex);
        SetUvTable_20243232(allwMesh, alluvwpos);
        if (op_Equality(allw2Mesh, 0, 0))
        {
          {
          }
          v1552 = get_Instance();
          v1553 = GetMesh(v1552, 4, 1);
          allw2Mesh = v1553;
          if ((v1554->_2.bitflags2 & 2) == 0)
            goto LABEL_1447;
        }
        else
        {
          {
LABEL_1447:
            SetPosition_20241056(allw2Mesh, allw2pos);
            SetIndexTable(allw2Mesh, allwidx);
            SetColor_20241296(allw2Mesh, allwcolor);
            v1557 = allw2Mesh;
            SetMatTexture(v1557, pbWk->blockTex);
            SetUvTable_20243232(allw2Mesh, alluvw2pos);
            WallChangeflag = 1;
            goto LABEL_1451;
          }
        }
        goto LABEL_1447;
      }
    }
    else
    {
        goto LABEL_1358;
    }
    goto LABEL_1358;
  }
LABEL_1451:
  wBlk_allCnt = 0;
  wBlkPosbupCnt = 0;
  NBlkDrawflag = 1;
  StageDrawflag = 1;
  if ((v597->_2.bitflags2 & 2) == 0)
  {
LABEL_1455:
    if (!mBlk_grpCnt)
      goto LABEL_1224;
LABEL_1456:
    if ((v597->_2.bitflags2 & 2) == 0)
      goto LABEL_1457;
    goto LABEL_1245;
  }
LABEL_1222:
    goto LABEL_1455;
  if (mBlk_grpCnt)
    goto LABEL_1456;
LABEL_1224:
  if (allmMesh)
  {
    if (mBlk_Resetflag == 1)
    {
      gameObject = get_gameObject(allmMesh->m_Items[0]);
      Destroy_27360000(gameObject);
      allmMesh = 0;
    }
  }
  mBlk_Resetflag = 0;
  if ((v597->_2.bitflags2 & 2) != 0)
  {
LABEL_1245:
  }
LABEL_1457:
  if (pBlk_MeshCnt == blk_max - 1)
    goto LABEL_1469;
  sub_854710(&mrpb_angle, 1u);
  if (v1559 == 0.0)
  {
LABEL_1469:
    if (mBlk_grpnumCnt)
    {
      if (overBlkflg == 1)
      {
        if (MBlkFallflag == 1)
        {
          if (!mBlk_grpCnt)
          {
            v1563 = 0;
            v1564 = *&v1562->_2.bitflags1;
            if ((v1564 & 0x200) == 0)
              goto LABEL_1496;
            while (1)
            {
              v1565 = v1564 & 0x200;
              if (v1563 > mBlk_grpCnt)
                break;
              while (1)
              {
                v1567 = allmMesh;
                if (v1567)
                {
                  v1570 = get_gameObject(v1567->m_Items[v1563]);
                  {
                  }
                  Destroy_27360000(v1570);
                }
                ++v1563;
                v1564 = *&v1562->_2.bitflags1;
                if ((v1564 & 0x200) != 0)
                  break;
LABEL_1496:
                v1565 = 0;
                if (v1563 > mBlk_grpCnt)
                  goto LABEL_1497;
              }
            }
LABEL_1497:
            allmMesh = 0;
            MBlkFallflag = 0;
          }
        }
        if (mBlk_Resetflag == 1)
        {
          if (mBlkStageChangeflag == 1)
          {
            v1574 = 0;
            if ((v1576 & 0x200) == 0)
              goto LABEL_1517;
LABEL_1513:
            for (i = v1576 & 0x200; ; i = 0)
            {
              v1579 = allmMesh;
              if (v1574 >= SLODWORD(v1579->max_length))
                break;
              if (v1579)
              {
                else if (v1574 >= LODWORD(v1579->max_length))
                {
                  goto LABEL_1526;
                }
                v1582 = get_gameObject(v1579->m_Items[v1574]);
                {
                }
                Destroy_27360000(v1582);
              }
              ++v1574;
              if ((v1576 & 0x200) != 0)
                goto LABEL_1513;
LABEL_1517:
              ;
            }
            allmMesh = 0;
            mBlkStageChangeflag = 0;
          }
          if (allmMesh)
          {
            v1584 = 0;
            if ((v1572->_2.bitflags2 & 2) == 0)
              goto LABEL_1548;
LABEL_1545:
LABEL_1548:
            while (1)
            {
              v1585 = allmMesh;
              v1586 = LODWORD(v1585->max_length);
              if (v1584 >= v1586)
                break;
              else if (v1584 >= v1586)
              {
                goto LABEL_1552;
              }
              v1589 = get_gameObject(v1585->m_Items[v1584]);
              {
              }
              Destroy_27360000(v1589);
              ++v1584;
                goto LABEL_1545;
            }
          }
          allmMesh = 0;
          mBlk_Resetflag = 0;
        }
        v1592 = mBlk_allCnt;
        if (mBlkPosbupCnt >= mBlk_grpnumCnt->m_Items[v1592])
        {
          mBlkPosbupCnt = 0;
        }
        if (!allmMesh)
        {
          if (mBlk_grpCnt)
          {
            v1596 = NewSpecific(XRD773Unity_CommonMesh, mBlk_grpCnt);
            allmMesh = v1596;
          }
        }
        v1597 = 0;
        v1598 = *&v597->_2.bitflags1;
        if ((v1598 & 0x200) == 0)
          goto LABEL_1589;
LABEL_1585:
        for (j = v1598 & 0x200; ; j = 0)
        {
          if (v1597 >= mBlk_grpCnt)
            break;
          else
          {
            v1602 = allmMesh;
            if (v1597 >= LODWORD(v1602->max_length))
              goto LABEL_1594;
          }
          v1604 = v1602->m_Items[v1597];
          if (op_Equality(v1604, 0, 0))
          {
            v1607 = allmMesh;
            {
            }
            v1608 = get_Instance();
            v1609 = GetMesh(v1608, 4, 1);
            v1610 = v1609;
            *&v1607[2 * v1597 + 8] = v1610;
          }
          v1614 = mBlk_grpnumCnt;
          v1616 = NewSpecific(
                    UnityEngine_Vector3,
                    (v1614->m_Items[v1597] * LODWORD(npos->max_length)));
          v1618 = mBlk_grpnumCnt;
          posd = v1616;
          v1620 = NewSpecific(s32, (v1618->m_Items[v1597] * LODWORD(idx->max_length)));
          v1621 = mBlk_grpnumCnt;
          v1622 = v1620;
          v1624 = NewSpecific(UnityEngine_Color, (24 * v1621->m_Items[v1597]));
          v1625 = mBlk_grpnumCnt;
          v1749 = v1624;
          v1628 = NewSpecific(UnityEngine_Vector2, (24 * v1625->m_Items[v1597]));
          v1743 = v1628;
          v1629 = 0;
          v1630 = 0;
          v1738 = v1628->m_Items;
          v1745 = v1597;
          {
LABEL_1622:
            goto LABEL_1625;
          }
          while (1)
          {
LABEL_1625:
            v1632 = mBlk_grpnumCnt;
            if (v1630 >= v1632->m_Items[v1597])
              break;
            v1634 = &v1749->m_Items[v1629].a;
            v1635 = 0;
            v1636 = 0;
            v1637 = v1629;
            v1747 = &v1738[v1629];
              goto LABEL_1632;
LABEL_1629:
LABEL_1632:
            while (1)
            {
              if (SLODWORD(npos->max_length) <= v1636)
                break;
              else if (v1597 >= LODWORD(mBlkPosbup->max_length))
              {
                goto LABEL_1636;
              }
              v1642 = npos;
              v1644 = mBlkPosbup;
              v1645 = v1642->m_Items[v1635].z;
              v1646 = v1642->m_Items[v1635].x;
              v1647 = v1642->m_Items[v1635].y;
              v1649 = v1644->m_Items[v1597];
              v1651 = (v1649 + 12 * v1630);
              v1652 = v1651[10];
              v1653 = v1651[8];
              v1654 = v1651[9];
              {
              }
              v1977.x = v1646;
              v1977.y = v1647;
              v1977.z = v1645;
              v1980.x = v1653;
              v1980.y = v1654;
              v1980.z = v1652;
              v1971 = op_Addition(v1977, v1980);
              v1655 = SLODWORD(v1642->max_length);
              v1639 = posd + 12 * v1636++ + 12 * v1630 * v1655;
              ++v1635;
              *(v1639 + 32) = v1971;
                goto LABEL_1629;
            }
            v1657 = 0;
            if ((v1638->_2.bitflags2 & 2) == 0)
              goto LABEL_1654;
LABEL_1651:
LABEL_1654:
            while (1)
            {
              v1658 = idx;
              v1659 = LODWORD(v1658->max_length);
              if (v1657 >= v1659)
                break;
              else if (v1657 >= v1659)
              {
                goto LABEL_1658;
              }
              *(v1622 + v1657 + v1630 * v1659 + 8) = v1658->m_Items[v1657] + 24 * v1630;
              ++v1657;
                goto LABEL_1651;
            }
            v1662 = &col->m_Items[0].a;
            v1663 = 0;
            do
            {
              v1665 = *(v1662 - 2);
              v1666 = *(v1662 - 1);
              v1667 = *v1662;
              ++v1663;
              *(v1634 - 3) = *(v1662 - 3);
              *(v1634 - 2) = v1665;
              *(v1634 - 1) = v1666;
              *v1634 = v1667;
              v1634 += 4;
              v1662 += 4;
            }
            while (v1663 != 24);
            v1628 = v1743;
            v1669 = 0;
            v1670 = 0;
            do
            {
              v1674 = (move_uvpos + v1669 * 8);
              v1675 = move_uvpos->m_Items[v1669].x;
              v1676 = v1674[9];
              ++v1670;
              v1678 = &v1747[v1669++];
              v1678->x = v1675;
              v1678->y = v1676;
            }
            while (v1670 != 24);
            v1597 = v1745;
            ++v1630;
            v1629 = v1637 + 24;
              goto LABEL_1622;
          }
          v1680 = allmMesh;
          SetPosition_20241056(v1680->m_Items[v1597], posd);
          v1682 = allmMesh;
          SetIndexTable(v1682->m_Items[v1597], v1622);
          v1684 = allmMesh;
          SetColor_20241296(v1684->m_Items[v1597], v1749);
          v1687 = allmMesh;
          v1689 = v1687->m_Items[v1597];
          SetMatTexture(v1689, pbWk->blockTex);
          v1691 = allmMesh;
          SetUvTable_20243232(v1691->m_Items[v1745], v1628);
          v1597 = v1745 + 1;
          if ((v1598 & 0x200) != 0)
            goto LABEL_1585;
LABEL_1589:
          ;
        }
        pbObjflag = 1;
        (*v1601)->MRBlockDrawflag = 1;
      }
    }
  }
  if (overBlkflg == 2)
  {
    v1695 = *&v597->_2.bitflags1;
    if ((v1695 & 0x200) != 0)
    {
      v1696 = v1695 & 0x200;
      if (GcolZ)
        goto LABEL_1708;
    }
    else
    {
      v1696 = 0;
      if (GcolZ)
      {
LABEL_1708:
        else
        {
          if (Gcol > 1.0)
            goto LABEL_1711;
        }
        v1698 = 0.1;
LABEL_1735:
        Gcol = Gcol + v1698;
LABEL_1736:
        v1699 = &col->m_Items[0].a;
        v1700 = 0;
        do
        {
          v1756 = 0;
          value = 0;
          sub_19EC630(&v1756, 0.0, 255.0, 200.0, 0.3);
          v1702 = HIDWORD(v1756);
          v1704 = value;
          v1703 = HIDWORD(value);
          ++v1700;
          *(v1699 - 3) = v1756;
          *(v1699 - 2) = v1702;
          *(v1699 - 1) = v1704;
          *v1699 = v1703;
          v1699 += 4;
        }
        while (v1700 != 24);
        SetPosition_20241056(pGoalBlk_Mesh, gpos);
        SetIndexTable(pGoalBlk_Mesh, idx);
        SetColor_20241296(pGoalBlk_Mesh, col);
        goto LABEL_1744;
      }
    }
    if (Gcol <= 0.2)
    {
      GcolZ = 1;
      goto LABEL_1736;
    }
    v1698 = -0.1;
    goto LABEL_1735;
  }
LABEL_1744:
  else if (!BGflag)
  {
    goto LABEL_1747;
  }
  return v1736->pointCount;
}

// 0x1650a10
u32 drawBlock2(s32 x, s32 y, u8 face, u32 type, sdfDrawTag_t **drTag) {
  struct XRD773Unity_CommonMesh_array *pBlk_Mesh;
  s64 pBlk_MeshCnt;
  UnityEngine_Object_o *v16;
  struct UnityEngine_Vector3_array *wBlkPosbup;
  s64 wBlkPosbupCnt;
  f32 v24;
  f32 v25;
  f32 v26;
  s32 v27;
  s32 v28;
  u32 *v30;
  struct UnityEngine_Vector3_array *w2BlkPosbup;
  s64 v33;
  f32 v34;
  f32 v35;
  f32 v36;
  s32 v37;
  s32 v38;
  u32 *v40;
  pbDraw_c *v41;
  struct UnityEngine_Vector3_array *fBlkPosbup;
  s64 fBlkPosbupCnt;
  f32 v46;
  f32 v47;
  f32 v48;
  s32 v49;
  s32 v50;
  u32 *v52;
  f32 *v53;
  f32 v54;
  f32 v55;
  f32 v56;
  sdfDrawTag_t_o **v57;
  s64 v59;
  s32 v60;
  s64 v61;
  s32 v62;
  UnityEngine_Vector3_o v63;
  UnityEngine_Vector4_o v64;

  if (!face)
    return 0;
  else
  {
    if (NBlkDrawflag)
      return 0;
  }
  v16 = pBlk_Mesh->m_Items[pBlk_MeshCnt];
  op_Equality(v16, 0, 0);
  sub_8529B0(&BaseTrans, 0, (40 * x - 380));
  sub_8529B0(&BaseTrans, 2, (40 * y - 380));
  if (!type)
  {
    sub_8529B0(&BaseTrans, 1, 20.0);
    v46 = sub_8527D0(&BaseTrans.x, 0);
    v47 = sub_8527D0(&BaseTrans.x, 1);
    v48 = sub_8527D0(&BaseTrans.x, 2);
    v62 = 0;
    v61 = 0;
    sub_8524C0(&v61, v46, -v47, v48);
    v49 = HIDWORD(v61);
    v50 = v62;
    v52 = (fBlkPosbup + 12 * fBlkPosbupCnt);
    v52[8] = v61;
    v52[9] = v49;
    v52[10] = v50;
    ++fBlkPosbupCnt;
    if ((v41->_2.bitflags2 & 2) == 0)
      goto LABEL_40;
    goto LABEL_30;
  }
  if (type == 1)
  {
    sub_8529B0(&BaseTrans, 1, -20.0);
    v24 = sub_8527D0(&BaseTrans.x, 0);
    v25 = sub_8527D0(&BaseTrans.x, 1);
    v26 = sub_8527D0(&BaseTrans.x, 2);
    v62 = 0;
    v61 = 0;
    sub_8524C0(&v61, v24, 5.0 - v25, v26);
    v27 = HIDWORD(v61);
    v28 = v62;
    v30 = (wBlkPosbup + 12 * wBlkPosbupCnt);
    v30[8] = v61;
    v30[9] = v27;
    v30[10] = v28;
    v33 = wBlkPosbupCnt;
    v34 = sub_8527D0(&BaseTrans.x, 0);
    v35 = sub_8527D0(&BaseTrans.x, 1);
    v36 = sub_8527D0(&BaseTrans.x, 2);
    v60 = 0;
    v59 = 0;
    sub_8524C0(&v59, v34, v35, v36);
    v37 = HIDWORD(v59);
    v38 = v60;
    v40 = (w2BlkPosbup + 12 * v33);
    v40[8] = v59;
    v40[9] = v37;
    v40[10] = v38;
    ++wBlkPosbupCnt;
    if ((v41->_2.bitflags2 & 2) == 0)
      goto LABEL_40;
    goto LABEL_30;
  }
  {
LABEL_30:
  }
LABEL_40:
  v54 = v53[55];
  v55 = v53[56];
  v56 = v53[57];
  v63.x = v54;
  v63.y = v55;
  v63.z = v56;
  v64 = op_Implicit(v63, 0);
  return drawBlock(v64, face, type, v57);
}

// 0x1645b60
dds3ProcessFunc_t *drawExit(dds3ProcessID_t *id) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v6;
  u64 *image;
  s64 v8;
  char *v9;
  s64 *v10;
  s32 v12;
  u64 *v14;
  s64 p_drawExit_angle;
  f32 v21;
  f32 v23;
  s64 v24;
  sdfDrawTag_t_o **v26;
  sdfDrawTag_t_o **v27;
  char *v30;
  s64 *v31;
  UnityEngine_Vector4_o v32;
  u64 v33[2];
  u64 v34[2];
  char *v35;
  UnityEngine_Vector4_o v36;
  UnityEngine_Vector4_o v37;

  v33[0] = 0;
  v33[1] = 0;
  *&v32.x = 0;
  *&v32.z = 0;
  workdata = id->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbProcHandle_t)
  {
    sub_8FC2C0(klass->_1.element_class, pbProcHandle_t, v34);
    if ((v34[0] & 1) != 0)
      v30 = v35;
    else
      v30 = v34 + 1;
    v31 = sub_8C4940(v30);
  }
  v6 = workdata[2].klass;
  if (v6)
  {
    image = v6->_1.image;
    if (*(v6->_1.image + 288) < v8 || *(image[25] + 8 * v8 - 8) != pbExit_t)
    {
      sub_8FC2C0(image[8], pbExit_t, v34);
      if ((v34[0] & 1) != 0)
        v9 = v35;
      else
        v9 = v34 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  sub_854690(v33, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v32.x, 0.0, 0.0, 0.0, 0.0);
  v12 = pb_General__PB_PROC_REF_MESS(workdata);
  if (v12 == 5)
  {
    id->func_ans = -1;
    return 0;
  }
  if (v12 == 1)
  {
    pb_General__PB_PROC_SEND_MESS(workdata, 0);
  }
  if (LODWORD(v6->_1.name))
  {
    v14 = Allocate(sdfDrawTag_t);
    sdfDrawTag_t___ctor(v14);
    sdfDrawTagInit(v14);
    p_drawExit_angle = &drawExit_angle;
    sub_854710(p_drawExit_angle, 1u);
    sub_854930(p_drawExit_angle, 1u);
    sub_854710(&drawExit_angle, 1u);
    if (v21 <= 3.1416)
    {
      sub_854710(&drawExit_angle, 1u);
      if (v23 >= -3.1416)
        goto LABEL_42;
    }
    {
    }
    v24 = &drawExit_angle;
    sub_854710(v24, 1u);
    sub_854930(v24, 1u);
LABEL_42:
    sub_854930(v33, 0);
    sub_854930(v33, 1u);
    sub_854930(v33, 2u);
    linkTM(v36, v37, v26);
    overBlkflg = 2;
    sub_854710(v33, 0);
    sub_854930(&v32, 0);
    sub_854710(v33, 1u);
    sub_854930(&v32, 1u);
    sub_854710(v33, 2u);
    sub_854930(&v32, 2u);
    drawBlock(v32, 0x1Fu, 6u, v27);
    overBlkflg = 0;
  }
  return 0;
}

// 0x164ff50
dds3ProcessFunc_t *drawMapBase(dds3ProcessID_t *id) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v6;
  u64 *image;
  s64 v8;
  char *v9;
  s64 *v10;
  u64 *v11;
  s64 *v12;
  s64 v13;
  s64 *v14;
  s64 *v16;
  s64 v18;
  s64 *v19;
  s32 v21;
  u64 *v23;
  u64 v26;
  s16 v27;
  u8 v28;
  u64 v29;
  struct System_UInt16_array *mapdata;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;
  sdfDrawTag_t_o **v37;
  s64 v40;
  MethodInfo *v42;
  s64 name_high;
  s16 v48;
  s32 v49;
  s32 pBlk_MeshCnt;
  s32 blk_max;
  char *v56;
  s64 *v57;
  u64 v58[2];
  char *v59;

  workdata = id->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbProcHandle_t)
  {
    sub_8FC2C0(klass->_1.element_class, pbProcHandle_t, v58);
    if ((v58[0] & 1) != 0)
      v56 = v59;
    else
      v56 = v58 + 1;
    v57 = sub_8C4940(v56);
  }
  v6 = workdata[2].klass;
  if (v6)
  {
    image = v6->_1.image;
    if (*(v6->_1.image + 288) < v8 || *(image[25] + 8 * v8 - 8) != pbMapBase_t)
    {
      sub_8FC2C0(image[8], pbMapBase_t, v58);
      if ((v58[0] & 1) != 0)
        v9 = v59;
      else
        v9 = v58 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  v11 = NewSpecific(pbDraw_faceChkDelegate, 2u);
  v12 = Allocate(pbDraw_faceChkDelegate);
  v13 = Method_pbDraw_pbCheckDrawFace2__;
  v14 = v12;
  v12[2] = *Method_pbDraw_pbCheckDrawFace2__;
  v12[4] = 0;
  v12[5] = v13;
  v11[4] = v14;
  v16 = Allocate(pbDraw_faceChkDelegate);
  v18 = Method_pbDraw_pbCheckDrawFace__;
  v19 = v16;
  v16[2] = *Method_pbDraw_pbCheckDrawFace__;
  v16[4] = 0;
  v16[5] = v18;
  v11[5] = v19;
  v21 = pb_General__PB_PROC_REF_MESS(workdata);
  if (v21 == 5)
  {
    id->func_ans = -1;
  }
  else
  {
    if (v21 == 1)
    {
      pb_General__PB_PROC_SEND_MESS(workdata, 0);
    }
    v23 = Allocate(sdfDrawTag_t);
    sdfDrawTag_t___ctor(v23);
    sdfDrawTagInit(v23);
    else if (!StageDrawflag)
    {
LABEL_35:
      v26 = 0;
      v27 = 0;
      v28 = 31;
      v29 = 0;
      while (1)
      {
        if (!pb_General__GET_MAP_HALL_(v29, v26))
        {
          mapdata = pbWk->bup->mapdata;
          bounds = mapdata->bounds;
          length = bounds[1].length;
          if (mapdata->m_Items[v29 + v26 * length] != 2048)
          {
            if (pb_General__GET_MAP_BLK_(v29, v26) != 1)
              break;
          }
        }
LABEL_61:
        if (pb_General__GET_MAP_BLK_(v29, v26) != 1)
          goto LABEL_73;
        if (!LODWORD(v6->_1.name))
        {
          name_high = HIDWORD(v6->_1.name);
          v28 = Invoke(v11[name_high + 4], v29, v27, 2u, v42);
            goto LABEL_72;
LABEL_67:
          goto LABEL_72;
        }
          goto LABEL_67;
LABEL_72:
        drawBlock2(v26, v29, v28, 1u, v42);
LABEL_73:
        if ((v48 & 0x200) != 0)
        {
          v49 = v48 & 0x200;
        }
        else
        {
          v49 = 0;
        }
        if (pBlk_MeshCnt >= blk_max - 1)
        {
          else if (pBlk_MeshCnt == blk_max)
          {
            goto LABEL_87;
          }
          if (++v29 == 20)
            goto LABEL_92;
        }
        else
        {
          pBlk_MeshCnt = pBlk_MeshCnt + 1;
          if (++v29 == 20)
          {
LABEL_92:
            ++v26;
            ++v27;
            if (v26 == 20)
              return 0;
            v29 = 0;
          }
        }
      }
      if (LODWORD(v6->_1.name))
      {
        {
LABEL_60:
          drawBlock2(v26, v29, v28, 0, v37);
          goto LABEL_61;
        }
      }
      else
      {
        v40 = HIDWORD(v6->_1.name);
        v28 = Invoke(v11[v40 + 4], v29, v27, 0, v37);
          goto LABEL_60;
      }
      goto LABEL_60;
    }
  }
  return 0;
}

// 0x16522c0
void drawMapPanel(sdfVector4_t offset, sdfDrawTag_t **drTag) {
  u64 *v3;
  u64 *v4;
  s64 v6;
  s64 i;
  u64 v9;
  struct UnityEngine_Vector4_array *blockVert;
  struct System_Byte_array *blockVertIndex;
  s64 v14;
  struct UnityEngine_Vector4_array *v18;
  struct System_Byte_array *v19;
  s64 v21;
  struct UnityEngine_Vector4_array *v25;
  struct System_Byte_array *v26;
  s64 v28;
  struct UnityEngine_Vector4_array *v32;
  struct System_Byte_array *v33;
  s64 v35;
  UnityEngine_Vector4_o v39;

  v39 = offset;
  v3 = NewSpecific(UnityEngine_Vector4, 6u);
  v4 = Allocate(sdf3DPrimPolyParm_t);
  sdf3DPrimPolyParm_t___ctor(v4);
  v6 = (v3 + 4);
  for (i = 32; i != 38; ++i)
  {
    v9 = i - 32;
    v14 = *(&blockVertIndex->obj.klass + i);
    sub_854710(&blockVert->m_Items[v14], 0);
    sub_854710(&v39, 0);
    sub_854930(v6, 0);
    v19 = blockVertIndex;
    v18 = blockVert;
    v21 = *(&v19->obj.klass + i);
    sub_854710(&v18->m_Items[v21], 1u);
    sub_854710(&v39, 1u);
    sub_854930(v6, 1u);
    v26 = blockVertIndex;
    v25 = blockVert;
    v28 = *(&v26->obj.klass + i);
    sub_854710(&v25->m_Items[v28], 2u);
    sub_854710(&v39, 2u);
    sub_854930(v6, 2u);
    v33 = blockVertIndex;
    v32 = blockVert;
    v35 = *(&v33->obj.klass + i);
    sub_854710(&v32->m_Items[v35], 3u);
    sub_854710(&v39, 3u);
    sub_854930(v6, 3u);
    v6 += 16;
  }
  *(v4 + 6) = -2139062144;
  *(v4 + 4) = 393218;
  v4[5] = v3;
  v4[6] = blk_base_norm;
  v4[7] = uvFloor;
}

// 0x1652680
void drawMapPanel2(s32 x, s32 y, sdfDrawTag_t **drTag) {
  sdfDrawTag_t_o **v5;
  sdfDrawTag_t_o **v6;
  UnityEngine_Vector4_o v8;
  u64 v9[2];
  u64 v10[2];
  UnityEngine_Vector4_o v11;
  UnityEngine_Vector4_o v12;

  v10[0] = 0;
  v10[1] = 0;
  v9[0] = 0;
  v9[1] = 0;
  sub_854690(v10, 0.0, 0.0, 0.0, 0.0);
  sub_854690(v9, 0.0, 0.0, 0.0, 0.0);
  *&v8.x = 0;
  *&v8.z = 0;
  sub_854690(&v8.x, 0.0, 20.0, 0.0, 0.0);
  sub_854930(v9, 0);
  sub_854930(v9, 2u);
  linkTM(v11, v12, v5);
  drawMapPanel(v8, v6);
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
  u32 v72;
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
      goto LABEL_55;
    }
    return 0;
  }
  if (type != 1)
  {
    v79 = v34;
    v83 = 0;
    goto LABEL_55;
  }
  if (!v34)
    return 0;
  v79 = v34;
  v83 = 1;
LABEL_55:
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
        goto LABEL_83;
      v53 = v43[v41];
      if (*(v53 + 32) + x >= 20)
      {
LABEL_83:
        v54 = 1;
        if (v41 >= *(v7 + 6))
        {
LABEL_84:
        }
      }
      else
      {
        v54 = 0;
        if (v41 >= *(v7 + 6))
          goto LABEL_84;
      }
      v62 = v43[v41];
      if (*(v62 + 33) + y < 0)
        goto LABEL_97;
      v63 = v43[v41];
      if (*(v63 + 33) + y >= 20)
      {
LABEL_97:
        v54 = 1;
        if (!v48)
        {
LABEL_98:
          if (v54)
            goto LABEL_122;
          if (v82)
          {
            v83 |= (0x10000 << *(&v80->klass + v41)) >> 16;
          }
          if ((v79 || v42 != 1) && v79 < 2u)
            goto LABEL_122;
          break;
        }
      }
      else if (!v48)
      {
        goto LABEL_98;
      }
      if (v48 != 1)
      {
        if (v42 != 1 && !v54)
        {
          v70 = *(&v80->klass + v41);
          v72 = 0x10000 << v70;
          v74 = facebup;
          v75 = wBlk_allCnt;
          v83 |= HIWORD(v72);
          v77 = v74->m_Items[v75];
          type = v48;
          v77->m_Items[v41] = v83;
        }
        goto LABEL_122;
      }
      if (v42 <= 1u)
        break;
LABEL_122:
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
      goto LABEL_17;
    }
    return 0;
  }
  v7 = x;
  v9 = pb_General__GET_MAP_BLK_(x, y) == 0;
  if (pb_General__GET_MAP_HALL_(x, y))
    return 0;
LABEL_17:
  v12 = v7 + 1;
  if (v7 + 1 >= 20)
  {
    v9 |= 8u;
    if (x <= 0)
      goto LABEL_81;
    goto LABEL_28;
  }
  v13 = pb_General__GET_MAP_BLK_(v12, y);
  if (type)
  {
    if (type == 1)
    {
      if (v13 <= 1u)
        v9 |= 8u;
      if (x <= 0)
        goto LABEL_81;
LABEL_28:
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
            goto LABEL_45;
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
            goto LABEL_45;
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
          goto LABEL_45;
      }
LABEL_82:
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
      goto LABEL_46;
    }
    if (!v13)
      v9 |= 8u;
    pb_General__GET_MAP_HALL_(v12, y);
    if (x > 0)
      goto LABEL_28;
  }
  else
  {
    if (!pb_General__GET_MAP_HALL_(v12, y))
      v9 |= 8u;
    if (x > 0)
      goto LABEL_28;
  }
LABEL_81:
  v17 = v9 | 0x10;
  v15 = y;
  v18 = y + 1;
  if (v18 < 20)
    goto LABEL_82;
LABEL_45:
  v17 |= 2u;
  if (y <= 0)
    return v17 | 4;
LABEL_46:
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
  u32 *data;
  s64 v5;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  data = (*p)->data;
  v5 = *data;
  if (*(*data + 288LL) < typeHierarchyDepth || *(*(v5 + 200) + 8 * typeHierarchyDepth - 8) != pbExit_t)
  {
    sub_8FC2C0(*(v5 + 64), pbExit_t, v10);
    if ((v10[0] & 1) != 0)
      v8 = v10[2];
    else
      v8 = v10 + 1;
    v9 = sub_8C4940(v8);
  }
  return data[4];
}

// 0x1651510
void pbInitBlockNormal(void) {
  ;
}

// 0x1653980
pbProcHandle_t *pbInitExitDraw(pbProcHandle_t **parent) {
  u64 *v3;
  u64 *v4;
  u64 *v5;
  pbProcHandle_t_Fields *p_fields;
  Il2CppObject *v9;
  u64 *v10;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  u64 *v14;
  char *v17;
  s64 *v18;
  u64 v19[3];

  v3 = Allocate(pbProcHandle_t);
  pbProcHandle_t___ctor(v3);
  v4 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v4,
    0,
    Method_pbDraw_drawExit__);
  v5 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v5,
    0,
    Method_pbDraw_deleteExit__);
  v3[2] = dds3StartProcess("pb-draw-exit", 0x2AFDu, 1, 1, v4, 0, v5, 0, 0, 0);
  if (*parent)
  {
    p_fields = &(*parent)->fields;
    dds3LinkProcess(&p_fields->id, v3 + 2);
  }
  pb_General__PB_PROC_SEND_MESS(v3, 1);
  *(v3 + 7) = 655370;
  v9 = Allocate(pbExit_t);
  v10 = Allocate(sdfMat_t);
  sdfMat_t___ctor(v10);
  v9[1].monitor = v10;
  _ctor(v9, 0);
  v3[4] = v9;
  dds3SetProcessData(v3 + 2, v3);
  klass = v9->klass;
  if (v9->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbExit_t)
  {
    sub_8FC2C0(klass->_1.element_class, pbExit_t, v19);
    if ((v19[0] & 1) != 0)
      v17 = v19[2];
    else
      v17 = v19 + 1;
    v18 = sub_8C4940(v17);
  }
  v9[1].klass = (&xmmword_0 + 1);
  v14 = Allocate(sdfMat_t);
  sdfMat_t___ctor(v14);
  v9[1].monitor = v14;
  sdfMatSetDiffuse(v14, 0x70FFFFFFu);
  return v3;
}

// 0x1653ed0
pbProcHandle_t *pbInitMapBaseDraw(pbProcHandle_t **parent, u32 sw) {
  pbProcHandle_t_o *v5;
  u64 *v6;
  u64 *v7;
  pbProcHandle_t_Fields *p_fields;
  pbMapBase_t_o *v11;
  pbMapBase_t_c *klass;
  s64 typeHierarchyDepth;
  char *v17;
  s64 *v18;
  pbProcHandle_t_o *p;
  u64 v20[3];

  v5 = Allocate(pbProcHandle_t);
  pbProcHandle_t___ctor(v5);
  p = v5;
  v6 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v6,
    0,
    Method_pbDraw_drawMapBase__);
  v7 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v7,
    0,
    Method_pbDraw_deleteMapBase__);
  v5->id = dds3StartProcess("pb-draw-mapbase", 0x2AFDu, 1, 1, v6, 0, v7, 0, 0, 0);
  if (*parent)
  {
    p_fields = &(*parent)->fields;
    dds3LinkProcess(&p_fields->id, &v5->id);
  }
  pb_General__PB_PROC_SEND_MESS(v5, 1);
  v11 = Allocate(pbMapBase_t);
  _ctor(v11, 0);
  v5->data = v11;
  klass = v11->klass;
  if (v11->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbMapBase_t)
  {
    sub_8FC2C0(klass->_1.element_class, pbMapBase_t, v20);
    if ((v20[0] & 1) != 0)
      v17 = v20[2];
    else
      v17 = v20 + 1;
    v18 = sub_8C4940(v17);
  }
  v11->mode = sw;
  dds3SetProcessData(&v5->id, v5);
  InitDrawMapBase(&p);
  return v5;
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
  Il2CppObject *data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  data = (*p)->data;
  klass = data->klass;
  if (data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbMapBase_t)
  {
    sub_8FC2C0(klass->_1.element_class, pbMapBase_t, v10);
    if ((v10[0] & 1) != 0)
      v8 = v10[2];
    else
      v8 = v10 + 1;
    v9 = sub_8C4940(v8);
  }
  LODWORD(data[1].klass) = flag;
}

// 0x1645b50
s32 sdf3DPrimLinkPoly(sdfDrawTag_t *a, sdf3DPrimPolyParm_t *b) {
  return 0;
}

// 0x1645b40
s32 sdfChipFreeDelayed(void *a) {
  return 0;
}
