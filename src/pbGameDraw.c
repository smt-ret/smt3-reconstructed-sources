#include "types.h"

typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct pbBlockDataBase_t pbBlockDataBase_t;
typedef struct pbGroupData_t pbGroupData_t;
typedef struct pbProcHandle_t pbProcHandle_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfIVector4_t sdfIVector4_t;
typedef struct sdfMat_t sdfMat_t;

static s32 degree_mode_b;
static pbProcHandle_t *menu_proc;
static pbProcHandle_t *help_proc;
static s32 *csrColor[4];
static sdfIVector4_t *csrPos[4];
static sdfIVector4_t *csrUv[4];
static sdfVector4_t mrpb_angle;
static sdfVector4_t mrpb_pos;
static s32 RndBlkPosCnt;
static s32 RndCoreBlkPosCnt;
static s32 RndBlkPosgrpCnt;
static s32 RndBlkflag;
static s32 RndCoreBlkPosCnflag;
static s32 mBlkStageChangeflag;
static sdfVector3_t RndCorePos;
static u32 outLineChkCnt;
static u32 outLineChkCnt2;
static u8 **outLineChk;
static bool OutLineFDraw;
static bool OutLineMDraw;
static s32 PB_BLOCK_LENGTH_H;
static f32 PB_OUTLINE;
static sdfVector4_t *outlineBase;
static f32 mapCursor_f;

void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
void dds3SetProcessData(dds3ProcessID_t **id, void *data);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
u32 drawBlock(sdfVector4_t offset, u8 face, u32 type, sdfDrawTag_t **drTag);
void linkTM(sdfVector4_t angle, sdfVector4_t trans, sdfDrawTag_t **drTag);
void makeBlockDataBase(pbBlockDataBase_t **db);
u8 pbCheckDrawFace(s16 x, s16 y, u32 type);
void pbRebuildOutline(pbGroupData_t **p);
u16 pb_General__GET_MAP_BLK_(s32 x, s32 y);
u32 pb_General__GET_MAP_GRPID_(s32 x, s32 y);
void pb_General__SET_MAP_BLK_(s32 x, s32 y, s32 v);
s32 sdfDrawTagInit(sdfDrawTag_t *a);
void sdfMatFreeDelayed(sdfMat_t *aMat);
sdfMat_t *sdfMatNew(void);
f32 sdfSin(f32 aRadius);
void sdfVu0LoadMatrix(sdfMatrix4_t *aMatrix);
void sdfVu0StoreMatrix(sdfMatrix4_t *aMatrix);

// 0x149be30
dds3ProcessFunc_t *blockDB(dds3ProcessID_t *id) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppClass *v8;
  u64 *image;
  s64 v10;
  char *v11;
  s64 *v12;
  u64 *v13;
  u64 *v14;
  u64 *v15;
  u64 *v17;
  s32 v19;
  u64 v20;
  const char *namespaze;
  const char *v23;
  u64 *v26;
  u64 *v28;
  pbGameDraw_c *v32;
  struct System_Byte_array_array *v33;
  u64 v35;
  const char *v37;
  s64 v39;
  struct System_Byte_array_array *outLineChk;
  u32 *v44;
  s64 *v45;
  s64 *v46;
  f32 v48;
  f32 v49;
  f32 v50;
  f32 v51;
  f32 v52;
  f32 v53;
  f32 v54;
  f32 v55;
  u64 v56;
  s64 v57;
  s64 v58;
  u64 v59;
  s16 v60;
  s64 v62;
  s64 v64;
  pbDraw_c *v66;
  s64 v68;
  s16 v69;
  s16 v70;
  Il2CppClass *v71;
  s16 v73;
  s16 v74;
  u8 v76;
  u8 v78;
  struct System_Byte_array_array *v80;
  System_Byte_array *v82;
  s64 v84;
  struct System_Int32_array *v85;
  struct System_Int32_array *mBlk_grpnumCnt;
  s64 mBlk_allCnt;
  s64 v90;
  s64 v91;
  s64 v92;
  u32 v94;
  s64 v95;
  s64 v97;
  const char *v103;
  s64 v105;
  const char *v107;
  s64 v109;
  const char *v112;
  struct System_Int16_array *mBlk_grpID;
  s64 mBlk_grpIDCnt;
  const char *v121;
  struct System_Int16_array *v122;
  s64 v123;
  s16 v125;
  u8 v127;
  s64 v130;
  s64 v131;
  s16 v132;
  s16 v134;
  s16 v135;
  s16 v136;
  f32 v139;
  s64 v142;
  s64 v144;
  struct XRD773Unity_CommonMesh_array *pMRBlk_Mesh;
  s64 pBlk_MeshCnt;
  UnityEngine_Object_o *v151;
  struct XRD773Unity_CommonMesh_array *v154;
  s64 v155;
  UnityEngine_Transform_o *transform;
  s64 v159;
  s64 v161;
  f32 v163;
  f32 v164;
  f32 v165;
  f32 v169;
  struct XRD773Unity_CommonMesh_array *v172;
  s64 v173;
  UnityEngine_Transform_o *v175;
  f32 z;
  f32 x;
  f32 y;
  UnityEngine_Transform_o *v181;
  f32 v182;
  f32 v183;
  struct XRD773Unity_CommonMesh_array *v185;
  s64 v186;
  UnityEngine_Transform_o *v188;
  f32 v192;
  struct System_Byte_array_array *v194;
  System_Byte_array *v196;
  const char *v200;
  s64 v202;
  s64 v203;
  const char *v205;
  s64 v207;
  pbGameDraw_c *v209;
  u64 *v212;
  UnityEngine_Vector4_o v213;
  sdfDrawTag_t_o *drTag;
  pbBlockDataBase_t_o *db;
  s64 v216;
  f32 v217;
  char *v218;
  UnityEngine_Vector3_o up;
  UnityEngine_Vector3_o position;
  UnityEngine_Vector3_o v221;
  UnityEngine_Vector4_o v222;
  UnityEngine_Vector4_o v223;
  UnityEngine_Quaternion_o v224;
  UnityEngine_Vector4_o v225;

  drTag = 0;
  db = 0;
  *&v213.x = 0;
  *&v213.z = 0;
  workdata = id->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbProcHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, pbProcHandle_t, &v216);
      if ((v216 & 1) != 0)
        v6 = v218;
      else
        v6 = &v216 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = workdata[2].klass;
  if (v8)
  {
    image = v8->_1.image;
    if (*(v8->_1.image + 288) < v10 || *(image[25] + 8 * v10 - 8) != pbBlockDataBase_t)
    {
      sub_8FC2C0(image[8], pbBlockDataBase_t, &v216);
      if ((v216 & 1) != 0)
        v11 = v218;
      else
        v11 = &v216 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  db = workdata[2].klass;
  v13 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v13);
  drTag = v13;
  v14 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v14);
  v15 = Allocate(pbGroupData_t);
  pbGroupData_t___ctor(v15);
  sub_854690(&v213.x, 0.0, 0.0, 0.0, 0.0);
  v17 = Allocate(sdfMatrix4_t);
  sdfMatrix4_t___ctor(v17);
  v19 = SLODWORD(workdata[1].monitor) >> 16;
  if (v19 == 5)
    goto LABEL_63;
LABEL_20:
  if (v19 == 1)
  {
    if (SLODWORD(v8->_1.name) >= 1)
    {
      v20 = 0;
      do
      {
        namespaze = v8->_1.namespaze;
        else if (v20 >= *(namespaze + 6))
        {
LABEL_33:
        }
        v23 = &namespaze[8 * v20++];
        *(v23 + 4) = 0;
      }
      while (v20 < SLODWORD(v8->_1.name));
    }
    LODWORD(v8->_1.name) = 0;
    makeBlockDataBase(&db);
    changeAutLine = 1;
    if (workdata)
      LODWORD(workdata[1].monitor) = 0;
  }
  v26 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v26);
  drTag = v26;
  sdfDrawTagInit(v26);
  v28 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v28);
  sdfDrawTagInit(v28);
  else if (changeAutLine != 1)
  {
    goto LABEL_56;
  }
  outLineChk = 0;
  changeAutLine = 0;
LABEL_56:
  else if (outLineChk)
  {
    goto LABEL_59;
  }
  v33 = NewSpecific(byte__, LODWORD(v8->_1.name));
  outLineChk = v33;
  if ((v32->_2.bitflags2 & 2) != 0)
  {
LABEL_60:
  }
LABEL_71:
  RndBlkPosgrpCnt = 0;
  else if (MRBlockDrawflag)
  {
    goto LABEL_331;
  }
  if (SLODWORD(v8->_1.name) < 1)
    goto LABEL_331;
  v35 = 0;
  v212 = v17;
  do
  {
    v37 = v8->_1.namespaze;
    v39 = *&v37[8 * v35 + 32];
    sub_854710(v39 + 48, 1u);
    sub_854930(&mrpb_angle, 1u);
    if (!outLineChk->m_Items[v35])
    {
      v44 = outLineChk;
      v45 = NewSpecific(byte, *(v39 + 22));
      v46 = v45;
      *&v44[2 * v35 + 8] = v46;
    }
    v48 = *(v39 + 48);
    v49 = *(v39 + 52);
    v50 = *(v39 + 56);
    v51 = *(v39 + 60);
    v52 = *(v39 + 64);
    v53 = *(v39 + 68);
    v55 = *(v39 + 72);
    v54 = *(v39 + 76);
    v222.x = v48;
    v222.y = v49;
    v222.z = v50;
    v222.w = v51;
    v225.x = v52;
    v225.y = v53;
    v225.z = v55;
    v225.w = v54;
    linkTM(v222, v225, &drTag);
    if (*(v39 + 22) >= 1)
    {
      v56 = 0;
      while (1)
      {
        if (*(v39 + 16))
        {
          v127 = 63;
            goto LABEL_220;
        }
        else
        {
          v130 = *(v39 + 40);
          v131 = *(v39 + 24);
          v132 = *(v131 + 18);
          v134 = *(*(v130 + 8 * v56 + 32) + 18LL);
          v135 = *(v131 + 20);
          v136 = *(*(*(v39 + 40) + 8 * v56 + 32) + 20LL);
          v127 = pbCheckDrawFace(v134 + v132, v136 + v135, 1u);
          {
LABEL_220:
            if (pBlk_MeshCnt != 399)
              goto LABEL_225;
            goto LABEL_221;
          }
        }
          goto LABEL_220;
        if (pBlk_MeshCnt != 399)
          goto LABEL_225;
LABEL_221:
        pBlk_MeshCnt = 0;
LABEL_225:
        sub_854710(&mrpb_angle, 1u);
        if (v139 == 0.0)
        {
          sub_854930(&v213, 0);
          sub_854930(&v213, 1u);
          sub_854930(&v213, 2u);
          v142 = *(v39 + 40);
          if (*(*(v142 + 8 * v56 + 32) + 16LL) == 4)
            goto LABEL_239;
          v144 = *(v39 + 40);
          if (*(*(v144 + 8 * v56 + 32) + 16LL) == 5)
          {
LABEL_239:
            v151 = pMRBlk_Mesh->m_Items[pBlk_MeshCnt];
            if (op_Inequality(v151, 0, 0))
            {
              v154 = pMRBlk_Mesh;
              v155 = pBlk_MeshCnt;
              transform = get_transform(v154->m_Items[v155], 0);
              v224.x = 0.0;
              v224.y = 0.0;
              v224.z = 0.0;
              v224.w = 0.0;
              set_rotation(transform, v224);
            }
          }
            goto LABEL_255;
        }
        else
        {
          v159 = *(v39 + 40);
          if (*(*(v159 + 8 * v56 + 32) + 16LL) == 4)
            goto LABEL_263;
          v161 = *(v39 + 40);
          if (*(*(v161 + 8 * v56 + 32) + 16LL) == 5)
          {
LABEL_263:
            v163 = *(v39 + 64);
            v164 = *(v39 + 68);
            v165 = *(v39 + 72);
            v217 = 0.0;
            v216 = 0;
            sub_8524C0(&v216, v163, -v164, v165);
            v169 = v217;
            *&RndCorePos.x = v216;
            RndCorePos.z = v169;
            v172 = pMRBlk_Mesh;
            v173 = pBlk_MeshCnt;
            v175 = get_transform(v172->m_Items[v173], 0);
            z = RndCorePos.z;
            x = RndCorePos.x;
            y = RndCorePos.y;
            v181 = v175;
            {
            }
            up = get_up();
            sub_854710(&mrpb_angle, 1u);
            v183 = v182;
            v221.x = x;
            v221.y = y;
            v221.z = z;
            RotateAround(v181, v221, up, v183);
            v185 = pMRBlk_Mesh;
            v186 = pBlk_MeshCnt;
            v188 = get_transform(v185->m_Items[v186], 0);
            position = get_position(v188);
            {
            }
            v213 = op_Implicit(position, 0);
          }
          RndBlkflag = 1;
          RndCoreBlkPosCnflag = 1;
          {
LABEL_255:
          }
        }
        overBlkflg = 1;
        outLineChkCnt = v35;
        outLineChkCnt2 = v56;
        sub_854710(&mrpb_angle, 1u);
        if (v192 != 0.0)
          goto LABEL_296;
        v194 = outLineChk;
        v196 = v194->m_Items[v35];
        if (!v196->m_Items[v56])
        {
          v57 = *(v39 + 40);
          v58 = *(v39 + 24);
          v59 = *(v57 + 24);
          v60 = *(v58 + 18);
          v68 = v57 + 8 * v56;
          v69 = *(v58 + 20);
          v70 = *(*(v68 + 32) + 18LL);
          v71 = v8;
          v73 = *(v39 + 20);
          v74 = *(*(*(v39 + 40) + 8 * v56 + 32) + 20LL);
          v76 = checkDrawOutline(v70 + v60, v74 + v69, v73);
          if (v76 == 15 && v127 == 63)
            v78 = 0;
          else
            v78 = v76;
          {
            v17 = v212;
            v8 = v71;
          }
          else
          {
            v17 = v212;
            v8 = v71;
          }
          v80 = outLineChk;
          v82 = v80->m_Items[v35];
          v82->m_Items[v56] = v78;
          v84 = *(v39 + 40);
          if (v56 >= *(v84 + 24))
          {
LABEL_297:
          }
        }
        else
        {
LABEL_296:
          v84 = *(v39 + 40);
          if (v56 >= *(v84 + 24))
            goto LABEL_297;
        }
        if (!*(v84 + 8 * v56 + 32))
          goto LABEL_302;
        else if (!clearAutLine)
        {
LABEL_101:
          if (!mBlk_grpCnt)
            goto LABEL_147;
LABEL_104:
          v62 = *(v39 + 40);
          if (*(*(v62 + 8 * v56 + 32) + 16LL) == 2)
            goto LABEL_110;
          v64 = *(v39 + 40);
          if (*(*(v64 + 8 * v56 + 32) + 16LL) == 3)
          {
LABEL_110:
            else
            {
              if (mBlk_grpnumCnt)
                goto LABEL_113;
LABEL_141:
              v85 = NewSpecific(s32, 0x14u);
              else
              {
                mBlk_grpnumCnt = v85;
                if ((v66->_2.bitflags2 & 2) == 0)
                  goto LABEL_144;
              }
            }
            goto LABEL_144;
          }
LABEL_147:
          v90 = *(v39 + 40);
          v91 = *&v213.x;
          v92 = *&v213.z;
          v94 = *(*(v90 + 8 * v56 + 32) + 16LL);
          *&v223.x = v91;
          *&v223.z = v92;
          drawBlock(v223, v127, v94, &drTag);
          ++pBlk_MeshCnt;
          v95 = *(v39 + 40);
          if (*(*(v95 + 8 * v56 + 32) + 16LL) == 2)
            goto LABEL_158;
          v97 = *(v39 + 40);
          if (*(*(v97 + 8 * v56 + 32) + 16LL) == 3)
          {
LABEL_158:
            if (v56 == *(v39 + 22) - 1LL)
            {
              ++mBlk_allCnt;
              if (mBlk_grpCnt == mBlk_allCnt)
              {
                mBlk_allCnt = 0;
              }
            }
          }
          else
          {
            if (mBlk_grpID)
            {
LABEL_170:
              v103 = v8->_1.namespaze;
              if (v35 >= *(v103 + 6))
                goto LABEL_171;
LABEL_172:
              v105 = *(*&v103[8 * v35 + 32] + 40LL);
              if (*(*(v105 + 8 * v56 + 32) + 16LL) == 2)
                goto LABEL_180;
              v107 = v8->_1.namespaze;
              v109 = *(*&v107[8 * v35 + 32] + 40LL);
              if (*(*(v109 + 8 * v56 + 32) + 16LL) == 3)
              {
LABEL_180:
                if (mBlk_grpCnt != mBlk_grpIDCnt)
                {
                  v112 = v8->_1.namespaze;
                  if (*(*&v112[8 * v35 + 32] + 20LL) == *(v39 + 20))
                  {
                    if (!mBlk_grpID->m_Items[mBlk_grpIDCnt])
                    {
                      v121 = v8->_1.namespaze;
                      v122 = mBlk_grpID;
                      v123 = mBlk_grpIDCnt;
                      v125 = *(*&v121[8 * v35 + 32] + 20LL);
                      v122->m_Items[v123] = v125;
                      ++mBlk_grpIDCnt;
                    }
                  }
                }
              }
              goto LABEL_302;
            }
          }
          mBlk_grpID = NewSpecific(s16, mBlk_grpCnt);
          v103 = v8->_1.namespaze;
          if (v35 >= *(v103 + 6))
          {
LABEL_171:
          }
          goto LABEL_172;
        }
LABEL_302:
        sdfVu0StoreMatrix(v17);
        sdfVu0LoadMatrix(v17);
        if (++v56 >= *(v39 + 22))
        {
          v200 = v8->_1.namespaze;
          if (v35 >= *(v200 + 6))
            goto LABEL_309;
          goto LABEL_310;
        }
      }
    }
    LODWORD(v56) = 0;
    v200 = v8->_1.namespaze;
    if (v35 >= *(v200 + 6))
    {
LABEL_309:
    }
LABEL_310:
    v202 = *(*&v200[8 * v35 + 32] + 40LL);
    v203 = v56 - 1LL;
    if (*(*(v202 + 8 * v203 + 32) + 16LL) != 4)
    {
      v205 = v8->_1.namespaze;
      v207 = *(*&v205[8 * v35 + 32] + 40LL);
      if (*(*(v207 + 8 * v203 + 32) + 16LL) != 5)
      {
          goto LABEL_327;
LABEL_322:
        goto LABEL_327;
      }
    }
    ++RndBlkPosgrpCnt;
    if ((v209->_2.bitflags2 & 2) != 0)
      goto LABEL_322;
LABEL_327:
    RndBlkPosCnt = 0;
    RndCoreBlkPosCnt = 0;
    ++v35;
  }
  while (v35 < SLODWORD(v8->_1.name));
    goto LABEL_334;
LABEL_332:
LABEL_334:
  pBlk_MeshCnt = 0;
  overBlkflg = 0;
  RndBlkPosgrpCnt = 0;
  RBlockOutCnt = 0;
  RBlockOutDrawFlag = 1;
  MBlockOutCnt = 0;
  MBlockOutDrawFlag = 1;
  return 0;
}

// 0x149d5d0
dds3ProcessFunc_t *deleteBlockDB(dds3ProcessID_t *id) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v7;
  u64 *image;
  s64 v9;
  char *v10;
  s64 *v11;
  sdfMat_t_o *data;
  u64 v14;
  const char *namespaze;
  const char *v17;
  char *v19;
  s64 *v20;
  u64 v21[2];
  char *v22;

  workdata = id->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbProcHandle_t)
  {
    sub_8FC2C0(klass->_1.element_class, pbProcHandle_t, v21);
    if ((v21[0] & 1) != 0)
      v19 = v22;
    else
      v19 = v21 + 1;
    v20 = sub_8C4940(v19);
  }
  v7 = workdata[2].klass;
  if (v7)
  {
    image = v7->_1.image;
    if (*(v7->_1.image + 288) < v9 || *(image[25] + 8 * v9 - 8) != pbBlockDataBase_t)
    {
      sub_8FC2C0(image[8], pbBlockDataBase_t, v21);
      if ((v21[0] & 1) != 0)
        v10 = v22;
      else
        v10 = v21 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  data = v7->_1.byval_arg.data;
  sdfMatFreeDelayed(data);
LABEL_19:
  if (SLODWORD(v7->_1.name) >= 1)
  {
    v14 = 0;
    do
    {
      namespaze = v7->_1.namespaze;
      else if (v14 >= *(namespaze + 6))
      {
LABEL_26:
      }
      v17 = &namespaze[8 * v14++];
      *(v17 + 4) = 0;
    }
    while (v14 < SLODWORD(v7->_1.name));
  }
  LODWORD(v7->_1.name) = 0;
  return 0;
}

// 0x149df50
void deleteMapCursor(dds3ProcessID_t *id) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v8[3];

  workdata = id->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbProcHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, pbProcHandle_t, v8);
      if ((v8[0] & 1) != 0)
        v6 = v8[2];
      else
        v6 = v8 + 1;
      v7 = sub_8C4940(v6);
    }
  }
}

// 0x149bb90
void freeAllDataBase(pbBlockDataBase_t **db) {
  pbBlockDataBase_t_o *v3;
  pbBlockDataBase_t_Fields *p_fields;
  u64 v5;
  struct pbGroupData_t_array *grp;
  Il2CppClass **v8;

  v3 = *db;
  p_fields = &(*db)->fields;
  if (p_fields->grp_num >= 1)
  {
    v5 = 0;
    do
    {
      grp = v3->grp;
      else if (v5 >= LODWORD(grp->max_length))
      {
LABEL_10:
      }
      v8 = &grp->obj.klass + v5++;
      v8[4] = 0;
      v3 = *db;
    }
    while (v5 < (*db)->grp_num);
    p_fields = &v3->fields;
  }
  p_fields->grp_num = 0;
}

// 0x149bb80
void freeGroupData(pbGroupData_t **p) {
  *p = 0;
}

// 0x149a660
void makeBlockDataBase(pbBlockDataBase_t **db) {
  u64 *v2;
  s64 v6;
  pbDraw_c *v7;
  u64 v8;
  struct XRD773Unity_CommonMesh_array *allmMesh;
  s32 v20;
  s32 i;
  struct pbGroupData_t_array *v22;
  s64 grp_num;
  u64 *v24;
  struct pbGroupData_t_array *v29;
  s64 v30;
  pbGroupData_t_o *v32;
  s16 v35;
  struct pbBlockData_t_o *core;
  struct System_UInt32_array *outline_c;
  struct System_UInt32_array *v39;
  struct System_UInt32_array *v41;
  struct System_UInt32_array *v43;
  struct System_UInt32_array *v45;
  struct System_UInt32_array *v47;
  struct System_UInt32_array *v49;
  struct System_UInt32_array *v51;
  u16 v54;
  u32 v55;
  pbBlockDataBase_t_o *v56;
  u32 v57;
  s64 v58;
  struct pbGroupData_t_array *grp;
  s64 v61;
  struct pbGroupData_t_array *v62;
  s32 v64;
  s32 v65;
  pbBlockDataBase_t_o *v66;
  u32 v67;
  s64 v68;
  s64 v69;
  struct pbGroupData_t_array *v70;
  s64 v72;
  struct pbGroupData_t_array *v73;
  s64 v75;
  s32 v76;
  s32 v77;
  u16 v78;
  u16 v79;
  pbBlockDataBase_t_o *v80;
  u32 v81;
  s64 v82;
  s64 v83;
  struct pbGroupData_t_array *v84;
  s64 v86;
  struct pbGroupData_t_array *v87;
  s64 v89;
  u64 *v90;
  u32 *v91;
  u32 *v92;
  u64 v93;
  Il2CppObject *v94;
  u32 *v96;
  s64 v98;
  s64 v99;
  s64 v101;
  s64 v102;
  u32 v103;
  s64 v104;
  s64 v106;
  s64 v108;
  pbBlockDataBase_t_o *v110;
  u64 v111;
  s64 v112;
  struct pbGroupData_t_array *v113;
  pbGameDraw_c *v116;
  struct System_String_array *v119;

  v2 = Allocate(pbGroupData_t);
  pbGroupData_t___ctor(v2);
  if (mBlkStageChangeflag != 1)
    goto LABEL_50;
LABEL_6:
  v6 = 4;
  v8 = 0;
    goto LABEL_31;
LABEL_7:
  if (v8 < mBlk_grpCnt)
    goto LABEL_32;
LABEL_36:
  mBlkStageChangeflag = 0;
  allmMesh = 0;
  if ((v7->_2.bitflags2 & 2) == 0)
    goto LABEL_51;
LABEL_42:
    goto LABEL_51;
  if (mBlk_grpnumCnt)
  {
LABEL_44:
    mBlk_grpnumCnt = 0;
    if ((v7->_2.bitflags2 & 2) == 0)
      goto LABEL_55;
    goto LABEL_53;
  }
LABEL_52:
  if ((v7->_2.bitflags2 & 2) != 0)
  {
LABEL_53:
  }
LABEL_55:
  pbObjflag = 0;
  mBlk_grpCnt = 0;
  NBlkDrawflag = 0;
  mBlk_grpIDCnt = 0;
  mBlkPosbup = 0;
  v20 = 0;
  mBlk_grpID = 0;
  do
  {
    for (i = 0; i != 20; ++i)
    {
      while (1)
      {
        v54 = pb_General__GET_MAP_BLK_(v20, i);
        if (v54 - 3 <= 1)
          break;
LABEL_110:
        if (++i == 20)
          goto LABEL_111;
      }
      v35 = v54;
      v55 = pb_General__GET_MAP_GRPID_(v20, i);
      v56 = *db;
      v57 = v55;
      else if (v56->grp_num < 1)
      {
        goto LABEL_58;
      }
      v58 = 4;
      while (1)
      {
        grp = v56->grp;
        if (v57 == *(*(&grp->obj.klass + v58) + 20LL))
          break;
        v61 = v58 - 3;
        ++v58;
        if (v61 >= v56->grp_num)
          goto LABEL_58;
      }
      v62 = v56->grp;
      if (*(&v62->obj.klass + v58))
        goto LABEL_110;
LABEL_58:
      v22 = (*db)->grp;
      grp_num = (*db)->grp_num;
      v24 = Allocate(pbGroupData_t);
      pbGroupData_t___ctor(v24);
      v22->m_Items[grp_num] = v24;
      v29 = (*db)->grp;
      v30 = (*db)->grp_num;
      v32 = v29->m_Items[v30];
      if (v35 == 3)
      {
        pb_General__SET_MAP_BLK_(v20, i, 2);
        v35 = 2;
        ++mBlk_grpCnt;
      }
      core = v32->core;
      v32->grpID = v57;
      core->type = v35;
      v32->core->x = v20;
      v32->core->y = i;
      sub_854930(&v32->trans, 0);
      sub_854930(&v32->trans, 2u);
      sub_854930(&v32->trans, 1u);
      outline_c = v32->outline_c;
      outline_c->m_Items[0] = -2133798704;
      v39 = v32->outline_c;
      v39->m_Items[1] = -2133798704;
      v41 = v32->outline_c;
      v41->m_Items[2] = -2133798704;
      v43 = v32->outline_c;
      v43->m_Items[3] = -2133798704;
      v45 = v32->outline_c;
      v45->m_Items[4] = -2133798704;
      v47 = v32->outline_c;
      v47->m_Items[5] = -2133798704;
      v49 = v32->outline_c;
      v49->m_Items[6] = -2133798704;
      v51 = v32->outline_c;
      v51->m_Items[7] = -2133798704;
      ++(*db)->grp_num;
    }
LABEL_111:
    ++v20;
  }
  while (v20 != 20);
  v64 = 0;
  v65 = 0;
  while (2)
  {
    while (2)
    {
      while (2)
      {
        if (pb_General__GET_MAP_BLK_(v64, v65) - 2 > 3)
          goto LABEL_137;
        v66 = *db;
        v67 = pb_General__GET_MAP_GRPID_(v64, v65);
        if (v66->grp_num < 1)
        {
LABEL_137:
          if (++v65 != 20)
            continue;
          goto LABEL_134;
        }
        break;
      }
      v68 = v67;
      v69 = 4;
      while (1)
      {
        v70 = v66->grp;
        if (v68 == *(*(&v70->obj.klass + v69) + 20LL))
          break;
        v72 = v69 - 3;
        ++v69;
        if (v72 >= v66->grp_num)
          goto LABEL_137;
      }
      v73 = v66->grp;
      v75 = *(&v73->obj.klass + v69);
      if (!v75)
        goto LABEL_137;
      ++*(v75 + 22);
      if (++v65 != 20)
        continue;
      break;
    }
LABEL_134:
    if (++v64 != 20)
    {
      v65 = 0;
      continue;
    }
    break;
  }
  v76 = 0;
  while (2)
  {
    v77 = 0;
    while (2)
    {
      while (2)
      {
        v78 = pb_General__GET_MAP_BLK_(v76, v77);
        if (v78 - 2 > 3)
          goto LABEL_185;
        v79 = v78;
        v80 = *db;
        v81 = pb_General__GET_MAP_GRPID_(v76, v77);
        if (v80->grp_num < 1)
          goto LABEL_185;
LABEL_150:
        v82 = v81;
        v83 = 4;
        while (1)
        {
          v84 = v80->grp;
          if (v82 == *(*(&v84->obj.klass + v83) + 20LL))
            break;
          v86 = v83 - 3;
          ++v83;
          if (v86 >= v80->grp_num)
            goto LABEL_185;
        }
        v87 = v80->grp;
        v89 = *(&v87->obj.klass + v83);
        if (!v89)
        {
LABEL_185:
          if (++v77 == 20)
            goto LABEL_186;
          continue;
        }
        break;
      }
      if (!*(v89 + 40))
      {
        v90 = Allocate(sdfMemHandle_tag);
        _ctor(v90, 0);
        *(v89 + 32) = v90;
        v91 = NewSpecific(pbBlockData_t, *(v89 + 22));
        *(v89 + 40) = v91;
        if (*(v89 + 22) >= 1)
        {
          v92 = v91;
          v93 = 0;
          while (1)
          {
            v94 = Allocate(pbBlockData_t);
            v94[1].monitor = NewSpecific(UnityEngine_Vector4, 8u);
            _ctor(v94, 0);
            v96 = &v92[2 * v93++];
            *(v96 + 4) = v94;
            if (v93 >= *(v89 + 22))
              break;
            v92 = *(v89 + 40);
          }
        }
      }
      v98 = 4;
      do
      {
        v99 = *(v89 + 40);
        v101 = *(v99 + 8 * v98++);
      }
      while (*(v101 + 16));
      v102 = *(v89 + 40);
      v103 = v98 - 5;
      v104 = (v98 - 5);
      *(*(v102 + 8 * v104 + 32) + 16LL) = v79;
      v106 = *(v89 + 40);
      *(*(v106 + 8 * v104 + 32) + 18LL) = v76 - *(*(v89 + 24) + 18LL);
      v108 = *(v89 + 40);
      *(*(v108 + 8 * v104 + 32) + 20LL) = v77++ - *(*(v89 + 24) + 20LL);
      if (v77 != 20)
        continue;
      break;
    }
LABEL_186:
    if (++v76 != 20)
      continue;
    break;
  }
  v110 = *db;
  if ((*db)->grp_num >= 1)
  {
    v111 = 0;
    v112 = 32;
    do
    {
      v113 = v110->grp;
      else if (v111 >= LODWORD(v113->max_length))
      {
LABEL_194:
      }
      pbRebuildOutline((v113 + v112));
      v110 = *db;
      ++v111;
      v112 += 8;
    }
    while (v111 < (*db)->grp_num);
  }
  outlineDrawflag = 0;
  StageDrawflag = 0;
  MRBlockDrawflag = 0;
  else
  {
    if (OutLineFDraw)
      goto LABEL_202;
LABEL_213:
    RBlockOutDrawFlag = 0;
    v119 = NewSpecific(string, 0);
    RBlockStrbup = v119;
    MBlockOutCnt = 0;
    OutLineFDraw = 1;
    if ((v116->_2.bitflags2 & 2) == 0)
      goto LABEL_220;
LABEL_203:
      goto LABEL_220;
    if (OutLineMDraw)
      goto LABEL_205;
  }
}

// 0x149d850
dds3ProcessFunc_t *mapCursor(dds3ProcessID_t *id) {
  s32 *workdata;
  s64 v4;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  u64 *v9;
  u64 *v10;
  sdfIVector4_t_o *v11;
  struct System_Int32_array *v12;
  u32 max_length;
  sdfIVector4_t_o *v17;
  struct System_Int32_array *v18;
  u32 v19;
  sdfIVector4_t_o *v23;
  struct System_Int32_array *v24;
  u32 v25;
  sdfIVector4_t_o *v29;
  struct System_Int32_array *v30;
  u32 v32;
  s32 v36;
  u64 *v37;
  u64 v48[3];

  workdata = id->workdata;
  if (workdata)
  {
    v4 = *workdata;
    if (*(*workdata + 288LL) < typeHierarchyDepth
      || *(*(v4 + 200) + 8 * typeHierarchyDepth - 8) != pbProcHandle_t)
    {
      sub_8FC2C0(*(v4 + 64), pbProcHandle_t, v48);
      if ((v48[0] & 1) != 0)
        v6 = v48[2];
      else
        v6 = v48 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v8);
  v9 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v9);
  NewSpecific(sdfIVector4_t, 4u);
  v10 = NewSpecific(sdfIVector4_t, 4u);
  v11 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v11);
  v12 = NewSpecific(s32, 4u);
  max_length = v12->max_length;
  v12->m_Items[1] = -1;
  v12->m_Items[3] = -1;
  v11->pm = v12;
  v10[4] = v11;
  v17 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v17);
  v18 = NewSpecific(s32, 4u);
  v19 = v18->max_length;
  v18->m_Items[0] = -1;
  v18->m_Items[2] = -1;
  v17->pm = v18;
  v10[5] = v17;
  v23 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v23);
  v24 = NewSpecific(s32, 4u);
  v25 = v24->max_length;
  v24->m_Items[1] = 1;
  v24->m_Items[3] = 1;
  v23->pm = v24;
  v10[6] = v23;
  v29 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v29);
  v30 = NewSpecific(s32, 4u);
  v32 = v30->max_length;
  v30->m_Items[0] = 1;
  v30->m_Items[2] = 1;
  v29->pm = v30;
  v10[7] = v29;
  v36 = workdata[6] >> 16;
  if (v36 == 5)
    goto LABEL_77;
LABEL_49:
  if (v36 == 1)
  {
    workdata[6] = 0;
  }
  v37 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v37);
  sdfDrawTagInit(v37);
LABEL_61:
  sdfSin(0.0);
  mapCursor_f = mapCursor_f + 0.2;
  if (mapCursor_f >= 3.1416)
  {
    mapCursor_f = 0.0;
  }
  return 0;
}

// 0x149e920
void pbPrintBlockDB(pbProcHandle_t **p) {
  Il2CppObject *data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  s64 *v9;
  u64 v18;
  System_Object_array *v23;
  u64 *monitor;
  System_Object_array *v25;
  s64 *v27;
  s64 *v28;
  u64 *v30;
  s64 *v32;
  s64 *v33;
  u64 *v35;
  s64 *v37;
  s64 *v38;
  u64 *v40;
  s64 *v42;
  s64 *v44;
  s64 v46;
  u64 *v47;
  System_Object_array *v49;
  u64 *v51;
  System_Object_array *v52;
  Il2CppObject *v54;
  u64 *v55;
  u64 v56;
  s64 v57;
  s64 *v58;
  s64 *v59;
  u64 *v61;
  u64 *v63;
  u64 v64;
  s64 v65;
  s64 *v66;
  s64 *v67;
  u64 *v69;
  s16 *v71;
  s64 v72;
  s64 v73;
  Il2CppObject *v75;
  u64 *v77;
  s16 *v79;
  s64 v80;
  s64 v81;
  s64 *v82;
  s64 *v84;
  char *v99;
  s64 *v100;
  char *v101;
  s64 *v102;
  char *v103;
  s64 *v104;
  char *v105;
  s64 *v106;
  s32 v107;
  s32 v108;
  s16 v109[2];
  s32 v110;
  s16 v111[2];
  s32 v112;
  char v113[16];
  char *v114;

  data = (*p)->data;
  if (data)
  {
    klass = data->klass;
    if (data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbBlockDataBase_t)
    {
      sub_8FC2C0(klass->_1.element_class, pbBlockDataBase_t, v113);
      if ((v113[0] & 1) != 0)
        v6 = v114;
      else
        v6 = &v113[1];
      v7 = sub_8C4940(v6);
    }
  }
  v8 = NewSpecific(string__, 1u);
  v9 = NewSpecific(string, 0x20u);
  v9[4] = "FLOOR";
  v9[5] = "WALL";
  v9[6] = "NORMAL BLOCK CORE";
  v9[7] = "NORMAL BLOCK";
  v9[8] = "ROUND BLOCK CORE";
  v9[9] = "ROUND BLOCK";
  v9[10] = "EXIT";
  v8[4] = v9;
  Write("\n((block data))\n", 0);
  if (SLODWORD(data[1].klass) >= 1)
  {
    v18 = 0;
    do
    {
      v23 = NewSpecific(object, 4u);
      monitor = data[1].monitor;
      v25 = v23;
      *v113 = *(monitor[v18 + 4] + 20LL);
      v27 = sub_8D3950(s16, v113);
      v28 = v27;
      v25->m_Items[0] = v28;
      v30 = data[1].monitor;
      LOWORD(v112) = *(*(v30[v18 + 4] + 24LL) + 18LL);
      v32 = sub_8D3950(s16, &v112);
      v33 = v32;
      v25->m_Items[1] = v33;
      v35 = data[1].monitor;
      LOWORD(v110) = *(*(v35[v18 + 4] + 24LL) + 20LL);
      v37 = sub_8D3950(s16, &v110);
      v38 = v37;
      v25->m_Items[2] = v38;
      v40 = data[1].monitor;
      LOWORD(v108) = *(v40[v18 + 4] + 22LL);
      v42 = sub_8D3950(s16, &v108);
      v44 = v42;
      v25->m_Items[3] = v44;
      Write_2930544("ID = {0:D}, (core x,y) = ({1:D}, {2:D}) {3:D}blocks\n", v25, 0);
      v46 = 0;
      v47 = data[1].monitor;
      if (v18 >= *(v47 + 6))
      {
LABEL_79:
      }
      while (v46 < *(v47[v18 + 4] + 22LL))
      {
        v49 = NewSpecific(object, 4u);
        v51 = data[1].monitor;
        v52 = v49;
        v54 = *(v51[v18 + 4] + 40LL);
        v112 = v46 + ToUInt32(v54, 0);
        v55 = sub_8D3950(uint, &v112);
        v56 = *v55;
        if (*(*v55 + 288) < v57 || *(*(v56 + 200) + 8 * v57 - 8) != pbBlockData_t)
        {
          sub_8FC2C0(*(v56 + 64), pbBlockData_t, v113);
          if ((v113[0] & 1) != 0)
            v99 = v114;
          else
            v99 = &v113[1];
          v100 = sub_8C4940(v99);
        }
        v111[0] = *(v55 + 9);
        v58 = sub_8D3950(s16, v111);
        v59 = v58;
        v52->m_Items[0] = v59;
        v61 = data[1].monitor;
        v110 = v46 + ToUInt32(*(v61[v18 + 4] + 40LL), 0);
        v63 = sub_8D3950(uint, &v110);
        v64 = *v63;
        if (*(*v63 + 288) < v65 || *(*(v64 + 200) + 8 * v65 - 8) != pbBlockData_t)
        {
          sub_8FC2C0(*(v64 + 64), pbBlockData_t, v113);
          if ((v113[0] & 1) != 0)
            v101 = v114;
          else
            v101 = &v113[1];
          v102 = sub_8C4940(v101);
        }
        v109[0] = *(v63 + 10);
        v66 = sub_8D3950(s16, v109);
        v67 = v66;
        v52->m_Items[1] = v67;
        v69 = data[1].monitor;
        v108 = v46 + ToUInt32(*(v69[v18 + 4] + 40LL), 0);
        v71 = sub_8D3950(uint, &v108);
        v72 = *v71;
        if (*(*v71 + 288LL) < v73 || *(*(v72 + 200) + 8 * v73 - 8) != pbBlockData_t)
        {
          sub_8FC2C0(*(v72 + 64), pbBlockData_t, v113);
          if ((v113[0] & 1) != 0)
            v103 = v114;
          else
            v103 = &v113[1];
          v104 = sub_8C4940(v103);
        }
        v75 = v8[v71[8] + 4];
        v52->m_Items[2] = v75;
        v77 = data[1].monitor;
        v107 = v46 + ToUInt32(*(v77[v18 + 4] + 40LL), 0);
        v79 = sub_8D3950(uint, &v107);
        v80 = *v79;
        if (*(*v79 + 288LL) < v81 || *(*(v80 + 200) + 8 * v81 - 8) != pbBlockData_t)
        {
          sub_8FC2C0(*(v80 + 64), pbBlockData_t, v113);
          if ((v113[0] & 1) != 0)
            v105 = v114;
          else
            v105 = &v113[1];
          v106 = sub_8C4940(v105);
        }
        *v113 = v79[11] >> 1;
        v82 = sub_8D3950(s32, v113);
        v84 = v82;
        v52->m_Items[3] = v84;
        Write_2930544("\t(x,y) = ({0:D}, {1:D}) type = {2} : outline = {3:D}\n", v52, 0);
        ++v46;
        v47 = data[1].monitor;
        if (v18 >= *(v47 + 6))
          goto LABEL_79;
      }
      ++v18;
    }
    while (v18 < SLODWORD(data[1].klass));
  }
}

// 0x149b9c0
void pbRebuildOutline(pbGroupData_t **p) {
  pbGroupData_t_o *v4;
  s64 v5;
  struct pbBlockData_t_array *blk;
  u64 v7;
  struct pbBlockData_t_array *v8;
  struct pbBlockData_t_o *core;
  u64 max_length_low;
  s16 x;
  s16 v14;
  s16 y;
  s16 grpID;
  s16 v18;
  s64 v19;

  v4 = *p;
  if ((*p)->num >= 1)
  {
    v5 = 4;
    do
    {
      blk = v4->blk;
      v7 = v5 - 4;
      *(*(&blk->obj.klass + v5) + 22LL) = 0;
      v8 = (*p)->blk;
      core = (*p)->core;
      max_length_low = LODWORD(v8->max_length);
      x = core->x;
      v14 = *(*(&v8->obj.klass + v5) + 18LL);
      y = core->y;
      grpID = (*p)->grpID;
      v18 = *(*(&(*p)->blk->obj.klass + v5) + 20LL);
      checkDrawOutline(v14 + x, v18 + y, grpID);
      v4 = *p;
      v19 = v5 - 3;
      ++v5;
    }
    while (v19 < (*p)->num);
  }
}

// 0x149e6c0
void pbReleaseGroupDB(pbProcHandle_t **p, u32 grpID) {
  u32 v3;
  Il2CppObject *data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  signed s64 klass_low;
  u64 v11;
  s32 v12;
  s64 v13;
  u32 *monitor;
  u32 *v17;
  s64 v18;
  u64 *v20;
  u64 *v22;
  u64 v24[3];

  v3 = grpID;
  data = (*p)->data;
  if (data)
  {
    klass = data->klass;
    if (data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbBlockDataBase_t)
    {
      sub_8FC2C0(klass->_1.element_class, pbBlockDataBase_t, v24);
      if ((v24[0] & 1) != 0)
        v8 = v24[2];
      else
        v8 = v24 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  LODWORD(klass_low) = data[1].klass;
  if (klass_low >= 1)
  {
    v11 = 0;
    v12 = 0;
    v13 = v3;
    do
    {
      if (v12)
      {
        monitor = data[1].monitor;
        v17 = &monitor[2 * v11];
        v18 = *(v17 + 4);
        *(v17 + 3) = v18;
      }
      v20 = data[1].monitor;
      if (*(v20[v11 + 4] + 20LL) == v13)
      {
        v22 = data[1].monitor;
        else if (v11 >= *(v22 + 6))
        {
LABEL_29:
        }
        v12 = 1;
        v22[v11 + 4] = 0;
      }
      klass_low = SLODWORD(data[1].klass);
      ++v11;
    }
    while (v11 < klass_low);
  }
  LODWORD(data[1].klass) = klass_low - 1;
}

// 0x149e510
pbGroupData_t *pbSearchGroupDB(pbProcHandle_t **p, u32 grpID) {
  Il2CppObject *data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  s64 v10;
  s64 i;
  u64 *monitor;
  s64 v14;
  u32 *v16;
  u64 v18[3];

  data = (*p)->data;
  else if (!data)
  {
    goto LABEL_12;
  }
  klass = data->klass;
  if (data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbBlockDataBase_t)
  {
    sub_8FC2C0(klass->_1.element_class, pbBlockDataBase_t, v18);
    if ((v18[0] & 1) != 0)
      v8 = v18[2];
    else
      v8 = v18 + 1;
    v9 = sub_8C4940(v8);
  }
LABEL_12:
  if (SLODWORD(data[1].klass) < 1)
    return 0;
  v10 = grpID;
  for (i = 4; ; ++i)
  {
    monitor = data[1].monitor;
    if (v10 == *(monitor[i] + 20LL))
      break;
    v14 = i - 3;
    if (v14 >= SLODWORD(data[1].klass))
      return 0;
  }
  v16 = data[1].monitor;
  return *&v16[2 * i];
}

// 0x149f900
void pbSetMapCursorFlag(pbProcHandle_t **p, s32 flag) {
  Il2CppObject *data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  data = (*p)->data;
  if (data)
  {
    klass = data->klass;
    if (data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbMapCursor_t)
    {
      sub_8FC2C0(klass->_1.element_class, pbMapCursor_t, v10);
      if ((v10[0] & 1) != 0)
        v8 = v10[2];
      else
        v8 = v10 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  if (*p)
    LODWORD(data[1].klass) = flag;
}

// 0x149e040
pbProcHandle_t *pbStartBlockDataBase(pbProcHandle_t **parent) {
  Il2CppObject *v3;
  u64 *v4;
  u64 *v5;
  u64 *v6;
  u64 *v7;
  u64 *v8;
  pbProcHandle_t_Fields *p_fields;
  Il2CppObject *v12;
  u64 *v13;
  u64 *v16;
  sdfMat_t_o *v17;
  s64 v18;
  s64 typeHierarchyDepth;
  char *v21;
  s64 *v22;
  u64 v23[3];

  v3 = Allocate(pbProcHandle_t);
  v4 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v4);
  v3[1].klass = v4;
  LODWORD(v23[0]) = 0;
  v3[2].klass = sub_8D3950(s32, v23);
  _ctor(v3, 0);
  v5 = Allocate(pbProcHandle_t);
  v6 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v6);
  v5[2] = v6;
  LODWORD(v23[0]) = 0;
  v5[4] = sub_8D3950(s32, v23);
  _ctor(v5, 0);
  v7 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v7,
    0,
    Method_pbGameDraw_blockDB__);
  v8 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v8,
    0,
    Method_pbGameDraw_deleteBlockDB__);
  v5[2] = dds3StartProcess("pb-proc-block DB", 0x2AFDu, 1, 1, v7, 0, v8, 0, 0, 0);
  if (*parent)
  {
    p_fields = &(*parent)->fields;
    dds3LinkProcess(&p_fields->id, v5 + 2);
  }
  *(v5 + 6) = 0x10000;
  v12 = Allocate(pbBlockDataBase_t);
  v12[1].monitor = NewSpecific(pbGroupData_t, 0x40u);
  v13 = Allocate(sdfMat_t);
  sdfMat_t___ctor(v13);
  v12[2].klass = v13;
  _ctor(v12, 0);
  v5[4] = v12;
  dds3SetProcessData(v5 + 2, v5);
  v16 = v5[4];
  v17 = sdfMatNew();
  v18 = *v16;
  if (*(*v16 + 288LL) < typeHierarchyDepth
    || *(*(v18 + 200) + 8 * typeHierarchyDepth - 8) != pbBlockDataBase_t)
  {
    sub_8FC2C0(*(v18 + 64), pbBlockDataBase_t, v23);
    if ((v23[0] & 1) != 0)
      v21 = v23[2];
    else
      v21 = v23 + 1;
    v22 = sub_8C4940(v21);
  }
  v16[4] = v17;
  return v5;
}

// 0x149f650
pbProcHandle_t *pbStartDrawMapCursor(pbProcHandle_t **parent) {
  Il2CppObject *v3;
  u64 *v4;
  u64 *v5;
  u64 *v6;
  u64 *v7;
  u64 *v8;
  pbProcHandle_t_Fields *p_fields;
  u64 *v12;
  s32 v15;
  s32 v16;

  v3 = Allocate(pbProcHandle_t);
  v4 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v4);
  v3[1].klass = v4;
  v15 = 0;
  v3[2].klass = sub_8D3950(s32, &v15);
  _ctor(v3, 0);
  v5 = Allocate(pbProcHandle_t);
  v6 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v6);
  v5[2] = v6;
  v16 = 0;
  v5[4] = sub_8D3950(s32, &v16);
  _ctor(v5, 0);
  v7 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v7,
    0,
    Method_pbGameDraw_mapCursor__);
  v8 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v8,
    0,
    Method_pbGameDraw_mapCursor__);
  v5[2] = dds3StartProcess("pb-draw-map cursor", 0x2AFDu, 1, 1, v7, 0, v8, 0, 0, 0);
  if (*parent)
  {
    p_fields = &(*parent)->fields;
    dds3LinkProcess(&p_fields->id, v5 + 2);
  }
  *(v5 + 6) = 0x10000;
  v12 = Allocate(pbMapCursor_t);
  _ctor(v12, 0);
  v5[4] = v12;
  dds3SetProcessData(v5 + 2, v5);
  return v5;
}

// 0x149a5a0
pbGroupData_t *searchGroupDB(pbBlockDataBase_t *db, u32 grpID) {
  u64 v3;
  struct pbGroupData_t_array *grp;
  struct pbGroupData_t_array *v7;

  if (db->grp_num < 1)
    return 0;
  v3 = 0;
  while (1)
  {
    grp = db->grp;
    if (grpID == grp->m_Items[v3]->grpID)
      break;
    if (++v3 >= db->grp_num)
      return 0;
  }
  v7 = db->grp;
  return v7->m_Items[v3];
}
