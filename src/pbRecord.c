#include "types.h"

typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct pbGroupData_t pbGroupData_t;
typedef struct pbProcHandle_t pbProcHandle_t;
typedef struct pbRecordData_t pbRecordData_t;
typedef struct pbRecord_t pbRecord_t;

struct pbRecord_t {
    s32 pnt;
    pbRecordData_t *rec;
};

void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
void dds3SetProcessData(dds3ProcessID_t **id, void *data);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void pbClearRecord(pbProcHandle_t **p);
void pbDispMyCharacter(pbProcHandle_t **p, s8 sw);
void pbGetMyCharcterPos2(pbProcHandle_t **p, s16 *x, s16 *y);
u32 pbMyCharacterDispStat(pbProcHandle_t **p);
pbGroupData_t *pbSearchGroupDB(pbProcHandle_t **p, u32 grpID);
void pbSetMyCharcterPos2(pbProcHandle_t **p, s16 x, s16 y);
void pb_General__CLR_MAP_BLKDAT_(s32 x, s32 y);
u16 pb_General__GET_MAP_BLK_(s32 x, s32 y);
void pb_General__SET_MAP_BLK_(s32 x, s32 y, s32 v);

// 0x14b0ae0
dds3ProcessFunc_t *deleteRecord(dds3ProcessID_t *id) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppObject *v9;
  u64 v10[3];

  v9 = 0;
  workdata = id->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbProcHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, pbProcHandle_t, v10);
      if ((v10[0] & 1) != 0)
        v6 = v10[2];
      else
        v6 = v10 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v9 = id->workdata;
  pbClearRecord(&v9);
  return 0;
}

// 0x14b0910
void deleteStack(pbRecordData_t **p) {
  pbRecordData_t_o *v2;

  v2 = *p;
  if ((*p)->c)
  {
    v2->current = 0;
    (*p)->c_num = 0;
    (*p)->c = 0;
    v2 = *p;
  }
  if (v2->blk)
  {
    v2->b_num = 0;
    (*p)->blk = 0;
    v2 = *p;
  }
  if (v2->flor)
  {
    v2->f_num = 0;
    (*p)->flor = 0;
  }
}

// 0x14b1db0
u32 pbAddRecord_blk(pbProcHandle_t **p, pbGroupData_t **grp) {
  Il2CppObject *data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  u32 *monitor;
  s64 klass_low;
  u32 *v11;
  s64 v12;
  u32 *v15;
  s64 v16;
  s64 v18;
  u64 i;
  u32 *v21;
  u32 *v22;
  s64 v23;
  u32 *v25;
  u64 *v26;
  pbGroupData_t_o *v29;
  s64 v30;
  u64 v31;
  struct pbBlockData_t_array *blk;
  struct pbBlockData_t_array *v36;
  s64 v40;
  struct System_UInt16_array *mapdata;
  s64 v43;
  s64 v44;
  Il2CppArrayBounds *bounds;
  s64 v46;
  il2cpp_array_size_t length;
  s64 v50;
  u32 *v51;
  s64 v52;
  u32 *v54;
  u32 v55;
  u32 *v57;
  s64 v58;
  char *v61;
  s64 *v62;
  u64 v63[3];

  data = (*p)->data;
  klass = data->klass;
  if (data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbRecord_t)
  {
    sub_8FC2C0(klass->_1.element_class, pbRecord_t, v63);
    if ((v63[0] & 1) != 0)
      v61 = v63[2];
    else
      v61 = v63 + 1;
    v62 = sub_8C4940(v61);
  }
  monitor = data[1].monitor;
  klass_low = SLODWORD(data[1].klass);
  *(*&monitor[2 * klass_low + 8] + 18LL) = (*grp)->num;
  v11 = data[1].monitor;
  v12 = SLODWORD(data[1].klass);
  v15 = data[1].monitor;
  v16 = SLODWORD(data[1].klass);
  v18 = *&v15[2 * v16 + 8];
  *(v18 + 32) = NewSpecific(pbRecordMapData_t, (*grp)->num);
  for (i = 0; ; ++i)
  {
    v22 = data[1].monitor;
    v23 = SLODWORD(data[1].klass);
    v25 = *(*&v22[2 * v23 + 8] + 32LL);
    if (i >= (*grp)->num)
      break;
    v26 = Allocate(pbRecordMapData_t);
    _ctor(v26, 0);
    v21 = &v25[2 * i];
    *(v21 + 4) = v26;
  }
  v29 = *grp;
  if ((*grp)->num >= 1)
  {
    v30 = 4;
    do
    {
      v31 = v30 - 4;
      blk = v29->blk;
      *(*&v25[2 * v30] + 16LL) = *(*(&blk->obj.klass + v30) + 18LL) + v29->core->x;
      v36 = (*grp)->blk;
      *(*&v25[2 * v30] + 18LL) = *(*(&v36->obj.klass + v30) + 20LL) + (*grp)->core->y;
      v40 = *&v25[2 * v30];
      mapdata = pbWk->bup->mapdata;
      v43 = *&v25[2 * v30];
      v44 = *(v43 + 18);
      bounds = mapdata->bounds;
      v46 = *(v43 + 16);
      length = bounds[1].length;
      *(v40 + 20) = mapdata->m_Items[v46 + length * v44] & 0xE7FF;
      v29 = *grp;
      v50 = v30 - 3;
      ++v30;
    }
    while (v50 < (*grp)->num);
  }
  v51 = data[1].monitor;
  v52 = SLODWORD(data[1].klass);
  if (*(*&v51[2 * v52 + 8] + 40LL))
  {
    v54 = data[1].monitor;
    v55 = data[1].klass;
    *(*&v54[2 * v55 + 8] + 40LL) = 0;
    v57 = data[1].monitor;
    v58 = SLODWORD(data[1].klass);
    *(*&v57[2 * v58 + 8] + 19LL) = 0;
  }
  return data[1].klass;
}

// 0x14b27a0
u32 pbAddRecord_char(pbProcHandle_t **p, u32 idx, pbProcHandle_t ***c) {
  char v5;
  Il2CppObject *data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v10;
  s64 *v11;
  u32 *monitor;
  s64 klass_low;
  s64 v15;
  u32 *v17;
  s64 v18;
  u32 *v21;
  s64 v22;
  s64 v25;
  u64 v28;
  u32 *v30;
  u32 *v31;
  s64 v32;
  s64 v34;
  u32 *v35;
  u64 *v36;
  u64 v39;
  u32 v41;
  pbProcHandle_t_array *v42;
  u32 *v45;
  s64 v46;
  s64 v48;
  u32 *v50;
  s64 v51;
  s64 v53;
  u32 *v55;
  s64 v56;
  s64 v58;
  s64 v60;
  u64 v63[3];
  s16 y[2];
  s16 x;

  v5 = idx;
  x = 0;
  y[0] = 0;
  data = (*p)->data;
  if (data)
  {
    klass = data->klass;
    if (data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbRecord_t)
    {
      sub_8FC2C0(klass->_1.element_class, pbRecord_t, v63);
      if ((v63[0] & 1) != 0)
        v10 = v63[2];
      else
        v10 = v63 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  x = 0;
  y[0] = 0;
  monitor = data[1].monitor;
  klass_low = SLODWORD(data[1].klass);
  v15 = *&monitor[2 * klass_low + 8];
  *(v15 + 17) = pbWk->bup->pchar_num;
  v17 = data[1].monitor;
  v18 = SLODWORD(data[1].klass);
  v21 = data[1].monitor;
  v22 = SLODWORD(data[1].klass);
  v25 = *&v21[2 * v22 + 8];
  *(v25 + 24) = NewSpecific(
                  pbRecordCharData_t,
                  pbWk->bup->pchar_num);
  v28 = 0;
  {
LABEL_28:
    goto LABEL_30;
  }
  while (1)
  {
LABEL_30:
    v31 = data[1].monitor;
    v32 = SLODWORD(data[1].klass);
    v34 = *&v31[2 * v32 + 8];
    if (v28 >= pbWk->bup->pchar_num)
      break;
    v35 = *(v34 + 24);
    v36 = Allocate(pbRecordCharData_t);
    _ctor(v36, 0);
    v30 = &v35[2 * v28++];
    *(v30 + 4) = v36;
      goto LABEL_28;
  }
  *(v34 + 16) = v5;
  v39 = 0;
    goto LABEL_43;
LABEL_41:
LABEL_43:
  while (v39 < pbWk->bup->pchar_num)
  {
    v42 = *c;
    else if (v39 >= LODWORD(v42->max_length))
    {
      goto LABEL_47;
    }
    pbGetMyCharcterPos2(&v42->m_Items[v39], &x, y);
    v45 = data[1].monitor;
    v46 = SLODWORD(data[1].klass);
    v48 = *(*&v45[2 * v46 + 8] + 24LL);
    *(*(v48 + 8 * v39 + 32) + 20LL) = x;
    v50 = data[1].monitor;
    v51 = SLODWORD(data[1].klass);
    v53 = *(*&v50[2 * v51 + 8] + 24LL);
    *(*(v53 + 8 * v39 + 32) + 22LL) = y[0];
    v55 = data[1].monitor;
    v56 = SLODWORD(data[1].klass);
    v58 = *(*&v55[2 * v56 + 8] + 24LL);
    v60 = *(v58 + 8 * v39 + 32);
    v41 = pbMyCharacterDispStat(&(*c)->m_Items[v39++]);
    *(v60 + 16) = v41;
      goto LABEL_41;
  }
  return data[1].klass;
}

// 0x14b2310
u32 pbAddRecord_flor(pbProcHandle_t **p, pbGroupData_t **grp) {
  Il2CppObject *data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  u32 *monitor;
  s64 klass_low;
  u32 *v11;
  s64 v12;
  u32 *v15;
  s64 v16;
  s64 v18;
  u64 i;
  u32 *v21;
  u32 *v22;
  s64 v23;
  u32 *v25;
  u64 *v26;
  pbGroupData_t_o *v29;
  s64 v30;
  u64 v31;
  struct pbBlockData_t_array *blk;
  struct pbBlockData_t_array *v36;
  s64 v40;
  struct System_UInt16_array *mapdata;
  s64 v43;
  s64 v44;
  Il2CppArrayBounds *bounds;
  s64 v46;
  il2cpp_array_size_t length;
  s64 v50;
  char *v52;
  s64 *v53;
  u64 v54[3];

  data = (*p)->data;
  klass = data->klass;
  if (data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbRecord_t)
  {
    sub_8FC2C0(klass->_1.element_class, pbRecord_t, v54);
    if ((v54[0] & 1) != 0)
      v52 = v54[2];
    else
      v52 = v54 + 1;
    v53 = sub_8C4940(v52);
  }
  monitor = data[1].monitor;
  klass_low = SLODWORD(data[1].klass);
  *(*&monitor[2 * klass_low + 8] + 19LL) = (*grp)->num;
  v11 = data[1].monitor;
  v12 = SLODWORD(data[1].klass);
  v15 = data[1].monitor;
  v16 = SLODWORD(data[1].klass);
  v18 = *&v15[2 * v16 + 8];
  *(v18 + 40) = NewSpecific(pbRecordMapData_t, (*grp)->num);
  for (i = 0; ; ++i)
  {
    v22 = data[1].monitor;
    v23 = SLODWORD(data[1].klass);
    v25 = *(*&v22[2 * v23 + 8] + 40LL);
    if (i >= (*grp)->num)
      break;
    v26 = Allocate(pbRecordMapData_t);
    _ctor(v26, 0);
    v21 = &v25[2 * i];
    *(v21 + 4) = v26;
  }
  v29 = *grp;
  if ((*grp)->num >= 1)
  {
    v30 = 4;
    do
    {
      v31 = v30 - 4;
      blk = v29->blk;
      *(*&v25[2 * v30] + 16LL) = *(*(&blk->obj.klass + v30) + 18LL) + v29->core->x;
      v36 = (*grp)->blk;
      *(*&v25[2 * v30] + 18LL) = *(*(&v36->obj.klass + v30) + 20LL) + (*grp)->core->y;
      v40 = *&v25[2 * v30];
      mapdata = pbWk->bup->mapdata;
      v43 = *&v25[2 * v30];
      v44 = *(v43 + 18);
      bounds = mapdata->bounds;
      v46 = *(v43 + 16);
      length = bounds[1].length;
      *(v40 + 20) = mapdata->m_Items[v46 + length * v44] & 0x800;
      v29 = *grp;
      v50 = v30 - 3;
      ++v30;
    }
    while (v50 < (*grp)->num);
  }
  return data[1].klass;
}

// 0x14b1390
s8 pbCheckPopRecord(pbProcHandle_t **p) {
  Il2CppObject *data;
  u64 *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  s32 v7;
  u32 *monitor;
  s32 v9;
  char *v12;
  s64 *v13;
  u64 v14[3];

  data = (*p)->data;
  v4 = Allocate(pbRecordData_t);
  _ctor(v4, 0);
  klass = data->klass;
  if (data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbRecord_t)
  {
    sub_8FC2C0(klass->_1.element_class, pbRecord_t, v14);
    if ((v14[0] & 1) != 0)
      v12 = v14[2];
    else
      v12 = v14 + 1;
    v13 = sub_8C4940(v12);
  }
  v7 = data[1].klass;
  monitor = data[1].monitor;
  v9 = (v7 + 29) % 30;
  return *(*&monitor[2 * v9 + 8] + 24LL) != 0;
}

// 0x14b0be0
void pbClearRecord(pbProcHandle_t **p) {
  Il2CppObject *data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 i;
  u32 *monitor;
  u32 *v11;
  s64 v12;
  u64 v13[3];

  data = (*p)->data;
  if (data)
  {
    klass = data->klass;
    if (data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbRecord_t)
    {
      sub_8FC2C0(klass->_1.element_class, pbRecord_t, v13);
      if ((v13[0] & 1) != 0)
        v6 = v13[2];
      else
        v6 = v13 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  for (i = 0; i != 30; ++i)
  {
    monitor = data[1].monitor;
    v11 = &monitor[2 * i];
    v12 = *(v11 + 4);
    if (*(v12 + 24))
    {
      *(v12 + 16) = 0;
      *(*(v11 + 4) + 17LL) = 0;
      *(*(v11 + 4) + 24LL) = 0;
      v12 = *(v11 + 4);
    }
    if (*(v12 + 32))
    {
      *(v12 + 18) = 0;
      *(*(v11 + 4) + 32LL) = 0;
      v12 = *(v11 + 4);
    }
    if (*(v12 + 40))
    {
      *(v12 + 19) = 0;
      *(*(v11 + 4) + 40LL) = 0;
    }
  }
}

// 0x14b2cf0
void pbDebugPrintRecord(pbProcHandle_t **p) {
  Il2CppObject *data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  s64 *v9;
  u64 *v18;
  u64 i;
  u64 *v21;
  s64 *v22;
  u64 *monitor;
  u64 *v27;
  u64 *v28;
  u64 *v30;
  s64 j;
  u64 *v32;
  u64 v34;
  s64 v35;
  s64 v36;
  u64 *v38;
  u64 *v39;
  Il2CppObject *v40;
  s64 v42;
  u64 *v45;
  u64 *v46;
  s64 v47;
  u64 *v50;
  u64 v51;
  s64 v52;
  u64 *v53;
  System_Object_array *v55;
  s64 *v57;
  s64 *v58;
  s64 *v60;
  s64 *v61;
  s64 v64;
  s64 *v66;
  s64 *v69;
  s64 *v71;
  u64 *v78;
  s64 v80;
  u64 *v82;
  u64 v83;
  s64 v84;
  u64 *v85;
  System_Object_array *v87;
  s64 *v89;
  s64 *v90;
  s64 *v92;
  s64 *v93;
  s64 v96;
  s64 *v98;
  s64 *v101;
  s64 *v103;
  char v119[4];
  char v120[4];
  u64 v121[3];

  data = (*p)->data;
  if (data)
  {
    klass = data->klass;
    if (data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbRecord_t)
    {
      sub_8FC2C0(klass->_1.element_class, pbRecord_t, v121);
      if ((v121[0] & 1) != 0)
        v6 = v121[2];
      else
        v6 = v121 + 1;
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
  Write("\n((record data))\n", 0);
  LODWORD(v121[0]) = data[1].klass;
  v18 = sub_8D3950(s32, v121);
  Write_2930400("stack point = {0:D}\n", v18);
  for (i = 0; i != 30; ++i)
  {
    if (i == LODWORD(data[1].klass))
    {
      LODWORD(v121[0]) = i;
      v21 = sub_8D3950(uint, v121);
      v22 = &">>>stack {0:D}\n";
    }
    else
    {
      LODWORD(v121[0]) = i;
      v21 = sub_8D3950(uint, v121);
      v22 = &"---stack {0:D}\n";
    }
    Write_2930400(*v22, v21);
    monitor = data[1].monitor;
    LOBYTE(v121[0]) = *(monitor[i + 4] + 17LL);
    v27 = sub_8D3950(qword_3F088F8, v121);
    Write_2930400("\t<character = {0:D}>\n", v27);
    v28 = data[1].monitor;
    v120[0] = *(v28[i + 4] + 16LL);
    v30 = sub_8D3950(qword_3F088F8, v120);
    Write_2930400("\tcurrent char = {0:D}\n", v30);
    for (j = 4; ; ++j)
    {
      v32 = data[1].monitor;
      v34 = j - 4;
      v35 = *(data[1].monitor + i + 4);
      if (j - 4 >= *(v32[i + 4] + 17LL))
        break;
      v36 = *(v35 + 24);
      LOWORD(v121[0]) = *(*(v36 + 8 * j) + 20LL);
      v38 = sub_8D3950(s16, v121);
      v39 = data[1].monitor;
      v40 = v38;
      v42 = *(v39[i + 4] + 24LL);
      *v120 = *(*(v42 + 8 * j) + 22LL);
      v45 = sub_8D3950(s16, v120);
      Write_2930752("\t  (x,y) = ({0:D}, {1:D})\n", v40, v45, 0);
    }
    v46 = data[1].monitor;
    v47 = *(v35 + 32);
    LOBYTE(v121[0]) = *(v46[i + 4] + 18LL);
    v50 = sub_8D3950(qword_3F088F8, v121);
    Write_2930400("\t<block = {0:D}>\n", v50);
    v51 = 0;
    v52 = v47 + 32;
    v53 = data[1].monitor;
    if (i >= *(v53 + 6))
    {
LABEL_82:
    }
    while (v51 < *(v53[i + 4] + 18LL))
    {
      v55 = NewSpecific(object, 4u);
      *v120 = *(*(v52 + 8 * v51) + 16LL);
      v57 = sub_8D3950(s16, v120);
      v58 = v57;
      v55->m_Items[0] = v58;
      *v119 = *(*(v52 + 8 * v51) + 18LL);
      v60 = sub_8D3950(s16, v119);
      v61 = v60;
      v55->m_Items[1] = v61;
      v64 = *(*(v52 + 8 * v51) + 20LL) >> 13;
      v66 = v8[v64 + 4];
      v55->m_Items[2] = v66;
      LODWORD(v121[0]) = *(*(v52 + 8 * v51) + 20LL) & 0x7FF;
      v69 = sub_8D3950(uint, v121);
      v71 = v69;
      v55->m_Items[3] = v71;
      Write_2930544("\t  (x,y) = ({0:D},{1:D}) {2} : grpid = {3:D}\n", v55, 0);
      ++v51;
      v53 = data[1].monitor;
      if (i >= *(v53 + 6))
        goto LABEL_82;
    }
    v78 = data[1].monitor;
    v80 = *(v78[i + 4] + 40LL);
    LOBYTE(v121[0]) = *(*(data[1].monitor + i + 4) + 19LL);
    v82 = sub_8D3950(qword_3F088F8, v121);
    Write_2930400("\t<floor = {0:D}>\n", v82);
    v83 = 0;
    v84 = v80 + 32;
    v85 = data[1].monitor;
    if (i >= *(v85 + 6))
    {
LABEL_125:
    }
    while (v83 < *(v85[i + 4] + 19LL))
    {
      v87 = NewSpecific(object, 4u);
      *v120 = *(*(v84 + 8 * v83) + 16LL);
      v89 = sub_8D3950(s16, v120);
      v90 = v89;
      v87->m_Items[0] = v90;
      *v119 = *(*(v84 + 8 * v83) + 18LL);
      v92 = sub_8D3950(s16, v119);
      v93 = v92;
      v87->m_Items[1] = v93;
      v96 = *(*(v84 + 8 * v83) + 20LL) >> 13;
      v98 = v8[v96 + 4];
      v87->m_Items[2] = v98;
      LODWORD(v121[0]) = *(*(v84 + 8 * v83) + 20LL) & 0x7FF;
      v101 = sub_8D3950(uint, v121);
      v103 = v101;
      v87->m_Items[3] = v103;
      Write_2930544("\t  (x,y) = ({0:D},{1:D}) {2} : grpid = {3:D}\n", v87, 0);
      ++v83;
      v85 = data[1].monitor;
      if (i >= *(v85 + 6))
        goto LABEL_125;
    }
  }
}

// 0x14b1180
u32 pbGetRecordPnt(pbProcHandle_t **p) {
  u32 *data;
  s64 v4;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  data = (*p)->data;
  v4 = *data;
  if (*(*data + 288LL) < typeHierarchyDepth || *(*(v4 + 200) + 8 * typeHierarchyDepth - 8) != pbRecord_t)
  {
    sub_8FC2C0(*(v4 + 64), pbRecord_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  return data[4];
}

// 0x14b14f0
s32 pbPopRecord(pbProcHandle_t **p, pbProcHandle_t ***c, pbProcHandle_t **blkDB) {
  Il2CppObject *data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v10;
  s64 *v11;
  u64 *v12;
  u64 *v13;
  s32 v18;
  u32 *monitor;
  s64 v21;
  s64 v22;
  u64 v23;
  pbProcHandle_t_array *v24;
  s64 v25;
  s16 v27;
  s16 v28;
  s64 v31;
  pbProcHandle_t_array *v32;
  s32 v34;
  s64 v36;
  s32 v37;
  s32 v39;
  pbGroupData_t_o *v40;
  pbGroupData_t_o *v43;
  s64 v44;
  struct pbBlockData_t_array *blk;
  struct pbBlockData_t_o *core;
  s32 x;
  s32 v49;
  s32 y;
  s32 v51;
  s64 v52;
  s64 v53;
  u64 v55;
  s64 v56;
  s64 v57;
  struct System_UInt16_array *mapdata;
  s64 v60;
  s64 v61;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;
  s64 v66;
  s64 v67;
  struct System_UInt16_array *v68;
  s64 v70;
  s64 v71;
  Il2CppArrayBounds *v72;
  il2cpp_array_size_t v74;
  char *v76;
  u16 *v77;
  s16 v78;
  s16 v79;
  s64 v80;
  u64 v82;
  s32 v83;
  s32 i;
  s64 v86;
  u64 v88;
  s64 v89;
  s64 v90;
  struct System_UInt16_array *v91;
  s64 v93;
  s64 v94;
  Il2CppArrayBounds *v95;
  il2cpp_array_size_t v97;
  char *v99;
  u16 *v100;
  s16 v101;
  s16 v102;
  s64 v103;
  u64 v105;
  u64 v107[3];

  data = (*p)->data;
  if (data)
  {
    klass = data->klass;
    if (data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbRecord_t)
    {
      sub_8FC2C0(klass->_1.element_class, pbRecord_t, v107);
      if ((v107[0] & 1) != 0)
        v10 = v107[2];
      else
        v10 = v107 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  v12 = Allocate(pbRecordData_t);
  _ctor(v12, 0);
  v13 = Allocate(pbGroupData_t);
  pbGroupData_t___ctor(v13);
  v18 = (LODWORD(data[1].klass) + 29) % 30;
  LODWORD(data[1].klass) = v18;
  monitor = data[1].monitor;
  v21 = *&monitor[2 * v18 + 8];
  v22 = *(v21 + 24);
  if (!v22)
    return -1;
  if (*(v21 + 17))
  {
    v23 = 0;
    while (1)
    {
      v24 = *c;
      v25 = v22;
      v27 = *(*(v22 + 8 * v23 + 32) + 20LL);
      v28 = *(*(v25 + 8 * v23 + 32) + 22LL);
      else if (v23 >= LODWORD(v24->max_length))
      {
        goto LABEL_21;
      }
      pbSetMyCharcterPos2(&v24->m_Items[v23], v27, v28);
      v31 = *(v21 + 24);
      v32 = *c;
      v34 = *(*(v31 + 8 * v23 + 32) + 16LL);
      pbDispMyCharacter(&v32->m_Items[v23++], v34);
      if (v23 >= *(v21 + 17))
        break;
      v22 = *(v21 + 24);
    }
  }
  v36 = *(v21 + 32);
  v37 = *(v21 + 16);
  v39 = *(*(v36 + 32) + 20LL);
  v40 = pbSearchGroupDB(blkDB, v39 & 0x7FF);
  if (v40)
  {
    v43 = v40;
    if (v40->num >= 1)
    {
      v44 = 4;
      do
      {
        blk = v43->blk;
        core = v43->core;
        x = core->x;
        v49 = *(*(&blk->obj.klass + v44) + 18LL);
        y = core->y;
        v51 = *(*(&v43->blk->obj.klass + v44) + 20LL);
        pb_General__CLR_MAP_BLKDAT_(v49 + x, v51 + y);
        v52 = v44 - 3;
        ++v44;
      }
      while (v52 < v43->num);
    }
  }
  if (*(v21 + 18))
  {
    v53 = 4;
    do
    {
      v55 = v53 - 4;
      v56 = *(v21 + 32);
      v57 = v56;
      mapdata = pbWk->bup->mapdata;
      v60 = *(*(v56 + 8 * v53) + 18LL);
      v61 = *(*(v57 + 8 * v53) + 16LL);
      bounds = mapdata->bounds;
      length = bounds[1].length;
      mapdata->m_Items[v61 + length * v60] &= 0x800u;
      v66 = *(v21 + 32);
      v67 = v66;
      v68 = pbWk->bup->mapdata;
      v70 = *(*(v66 + 8 * v53) + 18LL);
      v71 = *(*(v67 + 8 * v53) + 16LL);
      v72 = v68->bounds;
      v74 = v72[1].length;
      v76 = v68 + 2 * v71 + 2 * v74 * v70;
      v79 = *(v76 + 16);
      v77 = v76 + 32;
      v78 = v79;
      v80 = *(v21 + 32);
      *v77 = v78 | *(*(v80 + 8 * v53) + 20LL);
      v82 = v53 - 3;
      ++v53;
    }
    while (v82 < *(v21 + 18));
  }
  v83 = 0;
  for (i = 0; ; i = 0)
  {
    do
    {
      if (pb_General__GET_MAP_BLK_(i, v83) == 2)
      {
        pb_General__SET_MAP_BLK_(i, v83, 3);
      }
      ++i;
    }
    while (i != 20);
    if (++v83 == 20)
      break;
  }
  if (*(v21 + 18) == *(v21 + 19) && *(v21 + 18))
  {
    v86 = 4;
    do
    {
      v88 = v86 - 4;
      v89 = *(v21 + 40);
      v90 = v89;
      v91 = pbWk->bup->mapdata;
      v93 = *(*(v89 + 8 * v86) + 18LL);
      v94 = *(*(v90 + 8 * v86) + 16LL);
      v95 = v91->bounds;
      v97 = v95[1].length;
      v99 = v91 + 2 * v94 + 2 * v97 * v93;
      v102 = *(v99 + 16);
      v100 = v99 + 32;
      v101 = v102;
      v103 = *(v21 + 40);
      *v100 = v101 | *(*(v103 + 8 * v86) + 20LL);
      v105 = v86 - 3;
      ++v86;
    }
    while (v105 < *(v21 + 19));
  }
  if (*(v21 + 24))
  {
    *(v21 + 16) = 0;
    *(v21 + 24) = 0;
  }
  if (*(v21 + 32))
  {
    *(v21 + 18) = 0;
    *(v21 + 32) = 0;
  }
  if (*(v21 + 40))
  {
    *(v21 + 19) = 0;
    *(v21 + 40) = 0;
  }
  return v37;
}

// 0x14b1270
u32 pbPushRecord(pbProcHandle_t **p) {
  Il2CppObject *data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  u32 result;
  char *v7;
  s64 *v8;
  u64 v9[3];

  data = (*p)->data;
  klass = data->klass;
  if (data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbRecord_t)
  {
    sub_8FC2C0(klass->_1.element_class, pbRecord_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  result = (LODWORD(data[1].klass) + 31) % 30;
  LODWORD(data[1].klass) = result;
  return result;
}

// 0x14b0d60
pbProcHandle_t *pbStartRecord(pbProcHandle_t **parent) {
  Il2CppObject *v3;
  u64 *v4;
  u64 *v5;
  u64 *v6;
  u64 *v7;
  u64 *v8;
  u64 *v9;
  pbProcHandle_t_Fields *p_fields;
  u64 *v13;
  u64 v14;
  s64 typeHierarchyDepth;
  char *v16;
  s64 *v17;
  u32 *v18;
  u32 *v19;
  u64 i;
  u64 *v21;
  u64 v26[3];

  v3 = Allocate(pbProcHandle_t);
  v4 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v4);
  v3[1].klass = v4;
  LODWORD(v26[0]) = 0;
  v3[2].klass = sub_8D3950(s32, v26);
  _ctor(v3, 0);
  v5 = Allocate(pbRecord_t);
  _ctor(v5, 0);
  v6 = Allocate(pbProcHandle_t);
  v7 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v7);
  v6[2] = v7;
  LODWORD(v26[0]) = 0;
  v6[4] = sub_8D3950(s32, v26);
  _ctor(v6, 0);
  v8 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v8,
    0,
    Method_pbRecord_record__);
  v9 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v9,
    0,
    Method_pbRecord_deleteRecord__);
  v6[2] = dds3StartProcess("pb-proc-record", 0x3EEu, 1, 1, v8, 0, v9, 0, 0, 0);
  if (*parent)
  {
    p_fields = &(*parent)->fields;
    dds3LinkProcess(&p_fields->id, v6 + 2);
  }
  *(v6 + 6) = 0x10000;
  v13 = Allocate(pbRecord_t);
  _ctor(v13, 0);
  v6[4] = v13;
  if (v13)
  {
    v14 = *v13;
    if (*(*v13 + 288) < typeHierarchyDepth || *(*(v14 + 200) + 8 * typeHierarchyDepth - 8) != pbRecord_t)
    {
      sub_8FC2C0(*(v14 + 64), pbRecord_t, v26);
      if ((v26[0] & 1) != 0)
        v16 = v26[2];
      else
        v16 = v26 + 1;
      v17 = sub_8C4940(v16);
    }
  }
  *(v13 + 4) = 0;
  v18 = NewSpecific(pbRecordData_t, 0x1Eu);
  v13[3] = v18;
  v19 = v18;
  for (i = 0; ; ++i)
  {
    v21 = Allocate(pbRecordData_t);
    _ctor(v21, 0);
    *&v19[2 * i + 8] = v21;
    if (i == 29)
      break;
    v19 = v13[3];
  }
  dds3SetProcessData(v6 + 2, v6);
  return v6;
}

// 0x14b0970
dds3ProcessFunc_t *record(dds3ProcessID_t *id) {
  s32 *workdata;
  s64 v4;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s32 v8;
  u64 v10[3];

  workdata = id->workdata;
  if (workdata)
  {
    v4 = *workdata;
    if (*(*workdata + 288LL) < typeHierarchyDepth
      || *(*(v4 + 200) + 8 * typeHierarchyDepth - 8) != pbProcHandle_t)
    {
      sub_8FC2C0(*(v4 + 64), pbProcHandle_t, v10);
      if ((v10[0] & 1) != 0)
        v6 = v10[2];
      else
        v6 = v10 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  else
  {
    v8 = workdata[6] >> 16;
    if (v8 == 1)
      goto LABEL_13;
  }
  if ((v8 - 4) < 3)
    id->func_ans = -1;
  return 0;
}

// 0x14b0900
void sdfChipFreeDelayed(void *aPtr) {
  ;
}
