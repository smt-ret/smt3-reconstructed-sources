#include "types.h"

typedef struct FsSaveData FsSaveData;
typedef struct GameFileInfo_t GameFileInfo_t;
typedef struct SAVEDATA SAVEDATA;
typedef struct SAVEDATA_dds3GlobalWork_tag SAVEDATA_dds3GlobalWork_tag;
typedef struct SAVEDATA_dds3WorkVer7_tag SAVEDATA_dds3WorkVer7_tag;
typedef struct dds3AdditionWork_t dds3AdditionWork_t;
typedef struct dds3GlobalWork_t dds3GlobalWork_t;

static SAVEDATA *saveData;

void LoadCorrectionVer7(FsSaveData *this, SAVEDATA_dds3GlobalWork_tag *dds3Work, SAVEDATA_dds3WorkVer7_tag *dds3Ver7);
void backupData(SAVEDATA *this, s32 num, dds3GlobalWork_t *data, bool init);
void backupSystem(SAVEDATA *this);
void backupSystemVer7(SAVEDATA *this);
void initSystemVer7(SAVEDATA *this);
void initialize(SAVEDATA *this);
void restoreData(SAVEDATA *this, s32 num, dds3GlobalWork_t **data, dds3AdditionWork_t **addition);
void restoreSystem(SAVEDATA *this);
void restoreSystemVer7(SAVEDATA *this);
void setHeaderGameFileInfo(SAVEDATA *this, s32 num, GameFileInfo_t **data);

// 0x1140be0
void GetSuspendDispName(FsSaveData *this, s32 *nameU, s32 *nameD) {
  *nameU = saveData->AdditionBuff.nameU;
  *nameD = saveData->AdditionBuff.nameD;
}

// 0x1140b40
void GetSuspendFieldArea(FsSaveData *this, s32 *fieldID, s32 *areaID) {
  *fieldID = saveData->AdditionBuff.fieldID;
  *areaID = saveData->AdditionBuff.areaID;
}

// 0x113ed20
bool Load(FsSaveData *this) {
  bool v4;
  u64 *v8;
  u64 *v9;
  System_RuntimeTypeHandle_o v12;
  System_Type_o *TypeFromHandle;
  s32 v16;
  intptr_t v17;
  u64 *v18;
  Il2CppObject *v19;
  System_Type_o *v20;
  s32 v21;
  System_Type_o *v22;
  s32 v23;
  System_Type_o *v24;
  s32 v25;
  System_Type_o *v26;
  System_Type_o *v27;
  u64 *v28;
  Il2CppObject *v29;
  u64 v30;
  s32 v31;
  s64 v32;
  u64 *v33;
  Il2CppObject *v35;
  struct SAVEDATA_dds3GlobalWork_tag_array *saveBuff;
  intptr_t v39;
  System_RuntimeTypeHandle_o v41;
  intptr_t v42;
  System_Type_o *v44;
  Il2CppObject *v45;
  const void *v46;
  struct SAVEDATA_dds3GlobalWork_tag_array *v49;
  struct SAVEDATA_dds3GlobalWork_tag_array *v52;
  u64 *v54;
  bool v57;
  intptr_t v58;
  s32 max_length;
  s32 v61;
  s32 v62;
  intptr_t v63;
  s32 v64;
  struct SAVEDATA_o *saveData;
  System_RuntimeTypeHandle_o v68;
  System_Type_o *v69;
  Il2CppObject *v70;
  const void *v71;
  struct SAVEDATA_o *v73;
  s32 v77;
  s32 v78;
  intptr_t v79;
  struct SAVEDATA_o *v82;
  System_RuntimeTypeHandle_o v83;
  System_Type_o *v84;
  Il2CppObject *v85;
  const void *v86;
  s32 v87;
  intptr_t v88;
  struct SAVEDATA_o *v91;
  System_RuntimeTypeHandle_o v92;
  System_Type_o *v93;
  Il2CppObject *v94;
  struct System_SByte_array **v95;
  struct System_SByte_array *v96;
  u64 v98;
  s64 v99;
  intptr_t v101;
  struct SAVEDATA_dds3WorkVer7_tag_array *v104;
  System_RuntimeTypeHandle_o v105;
  System_Type_o *v106;
  Il2CppObject *v107;
  const void *v108;
  intptr_t v110;
  struct SAVEDATA_o *v113;
  System_RuntimeTypeHandle_o v114;
  System_Type_o *v115;
  Il2CppObject *v116;
  const void *v117;
  intptr_t v118;
  struct SAVEDATA_o *v119;
  System_Type_o *v120;
  Il2CppObject *v121;
  s64 *v122;
  s64 v123;
  s64 v124;
  struct System_SByte_array *v125;
  FsSaveData_c *v126;
  s32 v127;
  u64 v128;
  s64 v129;
  s64 v130;
  struct SAVEDATA_o *v131;
  struct SAVEDATA_dds3GlobalWork_tag_array *v132;
  struct SAVEDATA_dds3WorkVer7_tag_array *saveVer7;
  u32 v136;
  s32 v137;
  s32 v138;
  s32 v139;
  s32 v140;
  s32 v141;
  s32 v142;
  System_Byte_array *v143;
  u8 v144[456];
  u8 v145[1880];
  s32 v146;
  s32 v147;
  nn_ErrorRange_o ResultPathNotFound;
  s64 v149;
  u32 innerValue;
  s32 outValue[3];

  innerValue = 0;
  v149 = 0;
  ResultPathNotFound._descriptionEnd = 0;
  *&ResultPathNotFound._module = 0;
  outValue[0] = 0;
  Log("Load Data EntryType", 0);
  innerValue = GetEntryType(outValue, this->filePath).innerValue;
  ResultPathNotFound = get_ResultPathNotFound();
  if (sub_15C4E70(&ResultPathNotFound, innerValue))
    return 0;
  v4 = sub_15C4FE0(&innerValue);
  if (!v4)
  {
    {
LABEL_30:
      Log("error", 0);
      return 0;
    }
LABEL_27:
    goto LABEL_30;
  }
  Log("Load Data Open", 0);
  innerValue = Open(&this->fileHandle, this->filePath, 1, 0).innerValue;
  if (!sub_15C4FE0(&innerValue))
    goto LABEL_29;
  v149 = 0;
  Log("Load Data GetSize", 0);
  innerValue = GetSize(&v149, this->fileHandle).innerValue;
  if (!sub_15C4FE0(&innerValue))
  {
LABEL_29:
      goto LABEL_30;
    goto LABEL_27;
  }
  v143 = NewSpecific(byte, v149);
  Log("Load Data Read", 0);
  innerValue = Read_22868432(this->fileHandle, 0, v143, v149).innerValue;
  if (!sub_15C4FE0(&innerValue))
    return 0;
  Log("Load Data Close", 0);
  Close(this->fileHandle, 0);
  Log("Load Data Set", 0);
  v8 = Allocate(System_IO_MemoryStream);
  _ctor_3692656(v8, v143);
  v9 = Allocate(System_IO_BinaryReader);
  _ctor(v9, v8, 0);
  if ((*(*v9 + 536))(v9, *(*v9 + 544)) != 2)
  {
    v137 = 1324;
    if (!v8)
      goto LABEL_34;
    goto LABEL_33;
  }
  v137 = 285;
  if (v8)
LABEL_33:
    sub_22F10(0, System_IDisposable, v8);
LABEL_34:
  if (v137 == 1324)
    return 0;
  v12.value = SAVEDATA_fldAutoMapBuffEX_tag_var;
  TypeFromHandle = GetTypeFromHandle(v12);
  {
  }
  v142 = SizeOf_1552656(TypeFromHandle);
  Log("1", 0);
  v16 = LODWORD(v143->max_length) - 4;
  v17 = AllocHGlobal_1551568(v16);
  Copy(v143, 4, v17, v16, 0);
  v147 = v16;
  v18 = sub_8D3950(s32, &v147);
  v19 = Concat("2 : ", v18);
  Log(v19, 0);
  v20 = GetTypeFromHandle(SAVEDATA_dds3GlobalWork_tag_var);
  v21 = SizeOf_1552656(v20);
  v22 = GetTypeFromHandle(SAVEDATA_dds3AdditionWork_tag_var);
  v23 = SizeOf_1552656(v22);
  v24 = GetTypeFromHandle(SAVEDATA_dds3SystemWork_tag_var);
  v25 = SizeOf_1552656(v24);
  v26 = GetTypeFromHandle(SAVEDATA_dds3WorkVer7_tag_var);
  v141 = SizeOf_1552656(v26);
  v27 = GetTypeFromHandle(SAVEDATA_dds3SystemVer7_tag_var);
  v138 = SizeOf_1552656(v27);
  v146 = v21;
  v28 = sub_8D3950(s32, &v146);
  v139 = v25;
  v140 = v23;
  v29 = Concat("sizeGameInfo : ", v28);
  Log(v29, 0);
  v30 = 0;
  v31 = 0;
  v32 = 1904;
  do
  {
    v147 = v30;
    v33 = sub_8D3950(s32, &v147);
    v35 = Concat("loop : ", v33);
    Log(v35, 0);
    saveBuff = saveData->saveBuff;
    v39 = op_Addition(v17, v31);
    v41.value = SAVEDATA_dds3GlobalWork_tag_var;
    v42 = v39;
    v44 = GetTypeFromHandle(v41);
    {
    }
    v45 = PtrToStructure(v42, v44);
    v46 = il2cp::SizeOf(v45, SAVEDATA_dds3GlobalWork_tag);
    memcpy(v145, v46, sizeof(v145));
    memcpy(saveBuff + v32 - 1872, v145, 0x758u);
    v49 = saveData->saveBuff;
    v31 += v21;
    if (*(v49 + v32 - 1864) <= 5u)
    {
      v52 = saveData->saveBuff;
      v54 = (&v52->obj.klass + v32);
      *(v54 - 1) = 0;
      *v54 = 0;
      *(v54 - 1) = NewSpecific(uint, 0x20u);
      *v54 = NewSpecific(uint, 0x20u);
      *(v54 - 932) = 6;
      Log("Version old", 0);
      v31 -= v142;
    }
    Log("LoopEnd", 0);
    v57 = v30++ >= 0x13;
    v32 += 1880;
  }
  while (!v57);
  {
  }
  FreeHGlobal(v17);
  v58 = AllocHGlobal_1551568(v21);
  max_length = v143->max_length;
  v61 = v31 + 4;
  v62 = v31 + 4 + v21;
  v63 = v58;
  if (v62 <= max_length)
    v64 = v21;
  else
    v64 = max_length - v61;
  {
  }
  Copy(v143, v61, v63, v64, 0);
  v68.value = SAVEDATA_dds3GlobalWork_tag_var;
  v69 = GetTypeFromHandle(v68);
  v70 = PtrToStructure(v63, v69);
  v71 = il2cp::SizeOf(v70, SAVEDATA_dds3GlobalWork_tag);
  memmove(&saveData->suspendBuff, v71, 0x758u);
  v73 = saveData;
  if (v73->suspendBuff.GameFileInfo.ver <= 5u)
  {
    v73->suspendBuff.amapEX.blkOpenFlg01 = 0;
    v73->suspendBuff.amapEX.blkOpenFlg00 = 0;
    v73->suspendBuff.amapEX.blkOpenFlg00 = NewSpecific(uint, 0x20u);
    v73->suspendBuff.amapEX.blkOpenFlg01 = NewSpecific(uint, 0x20u);
    v73->suspendBuff.GameFileInfo.ver = 6;
    Log("Version old", 0);
    v62 -= v142;
  }
  {
  }
  FreeHGlobal(v63);
  v77 = v143->max_length;
  v78 = v62 + v140;
  if (v62 + v140 <= v77)
  {
    {
    }
    v79 = AllocHGlobal_1551568(v140);
    Copy(v143, v62, v79, v140, 0);
    v82 = saveData;
    v83.value = SAVEDATA_dds3AdditionWork_tag_var;
    v84 = GetTypeFromHandle(v83);
    v85 = PtrToStructure(v79, v84);
    v86 = il2cp::SizeOf(v85, SAVEDATA_dds3AdditionWork_tag);
    memmove(&v82->AdditionBuff, v86, 0x58u);
    FreeHGlobal(v79);
    v77 = v143->max_length;
  }
  v87 = v78 + v139;
  if (v78 + v139 <= v77)
  {
    {
    }
    v88 = AllocHGlobal_1551568(v139);
    Copy(v143, v78, v88, v139, 0);
    v91 = saveData;
    v92.value = SAVEDATA_dds3SystemWork_tag_var;
    v93 = GetTypeFromHandle(v92);
    v94 = PtrToStructure(v88, v93);
    v95 = il2cp::SizeOf(v94, SAVEDATA_dds3SystemWork_tag);
    v96 = v95[1];
    v91->SystemBuff.dlcflg = *v95;
    v91->SystemBuff.dummy = v96;
    FreeHGlobal(v88);
    restoreSystem(saveData);
    v77 = v143->max_length;
  }
  if (v87 >= v77)
  {
    v128 = -1;
    v129 = 32;
    v130 = 32;
    do
    {
      v131 = saveData;
      v132 = v131->saveBuff;
      saveVer7 = v131->saveVer7;
      LoadCorrectionVer7(v126, (v132 + v130), (saveVer7 + v129));
      ++v128;
      v130 += 1880;
      v127 = (v136 >> 9) & 1;
      v129 += 456;
    }
    while (v128 <= 0x12);
    LoadCorrectionVer7(v126, &saveData->suspendBuff, &saveData->suspendVer7);
    initSystemVer7(saveData);
  }
  else
  {
    v98 = -1;
    v99 = 32;
    do
    {
      v101 = AllocHGlobal_1551568(v141);
      Copy(v143, v87, v101, v141, 0);
      v104 = saveData->saveVer7;
      v105.value = SAVEDATA_dds3WorkVer7_tag_var;
      v106 = GetTypeFromHandle(v105);
      v107 = PtrToStructure(v101, v106);
      v108 = il2cp::SizeOf(v107, SAVEDATA_dds3WorkVer7_tag);
      memcpy(v144, v108, sizeof(v144));
      memcpy(v104 + v99, v144, 0x1C8u);
      FreeHGlobal(v101);
      ++v98;
      v87 += v141;
      v99 += 456;
    }
    while (v98 <= 0x12);
    {
    }
    v110 = AllocHGlobal_1551568(v141);
    Copy(v143, v87, v110, v141, 0);
    v113 = saveData;
    v114.value = SAVEDATA_dds3WorkVer7_tag_var;
    v115 = GetTypeFromHandle(v114);
    v116 = PtrToStructure(v110, v115);
    v117 = il2cp::SizeOf(v116, SAVEDATA_dds3WorkVer7_tag);
    memmove(&v113->suspendVer7, v117, 0x1C8u);
    FreeHGlobal(v110);
    v118 = AllocHGlobal_1551568(v138);
    Copy(v143, v141 + v87, v118, v138, 0);
    v119 = saveData;
    v120 = GetTypeFromHandle(SAVEDATA_dds3SystemVer7_tag_var);
    v121 = PtrToStructure(v118, v120);
    v122 = il2cp::SizeOf(v121, SAVEDATA_dds3SystemVer7_tag);
    v123 = *v122;
    v124 = v122[1];
    v125 = v122[3];
    *&v119->SystemVer7.Bad_Bit = v122[2];
    v119->SystemVer7.reserved = v125;
    *&v119->SystemVer7.Transport_Count = v123;
    *&v119->SystemVer7.EndingList = v124;
    FreeHGlobal(v118);
    restoreSystemVer7(saveData);
  }
  return 1;
}

// 0x11404d0
void LoadCorrectionVer6(FsSaveData *this, s32 *start, SAVEDATA_dds3GlobalWork_tag *dds3Work, s32 size) {
  *start -= size;
  dds3Work->amapEX.blkOpenFlg01 = 0;
  dds3Work->amapEX.blkOpenFlg00 = 0;
  dds3Work->amapEX.blkOpenFlg00 = NewSpecific(uint, 0x20u);
  dds3Work->amapEX.blkOpenFlg01 = NewSpecific(uint, 0x20u);
  dds3Work->GameFileInfo.ver = 6;
}

// 0x1140570
void LoadCorrectionVer7(FsSaveData *this, SAVEDATA_dds3GlobalWork_tag *dds3Work, SAVEDATA_dds3WorkVer7_tag *dds3Ver7) {
  struct System_UInt32_array *v6;
  struct System_UInt32_array *v7;
  struct System_UInt32_array *v8;

  dds3Ver7->amap.blkOpenFlg28 = 0;
  dds3Ver7->amap.blkOpenFlg29 = 0;
  dds3Ver7->amap.blkOpenFlg26 = 0;
  dds3Ver7->amap.blkOpenFlg27 = 0;
  dds3Ver7->amap.blkOpenFlg24 = 0;
  dds3Ver7->amap.blkOpenFlg25 = 0;
  dds3Ver7->amap.blkOpenFlg22 = 0;
  dds3Ver7->amap.blkOpenFlg23 = 0;
  dds3Ver7->amap.blkOpenFlg20 = 0;
  dds3Ver7->amap.blkOpenFlg21 = 0;
  dds3Ver7->amap.blkOpenFlg18 = 0;
  dds3Ver7->amap.blkOpenFlg19 = 0;
  dds3Ver7->amap.blkOpenFlg16 = 0;
  dds3Ver7->amap.blkOpenFlg17 = 0;
  dds3Ver7->amap.blkOpenFlg14 = 0;
  dds3Ver7->amap.blkOpenFlg15 = 0;
  dds3Ver7->amap.blkOpenFlg12 = 0;
  dds3Ver7->amap.blkOpenFlg13 = 0;
  dds3Ver7->amap.blkOpenFlg10 = 0;
  dds3Ver7->amap.blkOpenFlg11 = 0;
  dds3Ver7->amap.blkOpenFlg08 = 0;
  dds3Ver7->amap.blkOpenFlg09 = 0;
  dds3Ver7->amap.blkOpenFlg06 = 0;
  dds3Ver7->amap.blkOpenFlg07 = 0;
  dds3Ver7->amap.blkOpenFlg04 = 0;
  dds3Ver7->amap.blkOpenFlg05 = 0;
  dds3Ver7->amap.blkOpenFlg02 = 0;
  dds3Ver7->amap.blkOpenFlg03 = 0;
  dds3Ver7->amap.blkOpenFlg00 = 0;
  dds3Ver7->amap.blkOpenFlg01 = 0;
  dds3Ver7->amap.blkOpenFlg00 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg01 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg02 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg03 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg04 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg05 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg06 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg07 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg08 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg09 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg10 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg11 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg12 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg13 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg14 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg15 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg16 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg17 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg18 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg19 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg20 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg21 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg22 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg23 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg24 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg25 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg26 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg27 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg28 = NewSpecific(uint, 0x20u);
  v6 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap31.blkOpenFlg06 = 0;
  dds3Ver7->amap31.blkOpenFlg07 = 0;
  dds3Ver7->amap31.blkOpenFlg04 = 0;
  dds3Ver7->amap31.blkOpenFlg05 = 0;
  dds3Ver7->amap.blkOpenFlg29 = v6;
  dds3Ver7->amap31.blkOpenFlg02 = 0;
  dds3Ver7->amap31.blkOpenFlg03 = 0;
  dds3Ver7->amap31.blkOpenFlg00 = 0;
  dds3Ver7->amap31.blkOpenFlg01 = 0;
  dds3Ver7->amap31.blkOpenFlg00 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap31.blkOpenFlg01 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap31.blkOpenFlg02 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap31.blkOpenFlg03 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap31.blkOpenFlg04 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap31.blkOpenFlg05 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap31.blkOpenFlg06 = NewSpecific(uint, 0x20u);
  v7 = NewSpecific(uint, 0x20u);
  dds3Ver7->amapEX.blkOpenFlg00 = 0;
  dds3Ver7->amapEX.blkOpenFlg01 = 0;
  dds3Ver7->amap31.blkOpenFlg07 = v7;
  dds3Ver7->amapEX.blkOpenFlg00 = NewSpecific(uint, 0x20u);
  v8 = NewSpecific(uint, 0x20u);
  *&dds3Ver7->dante_pelem.hensinmae = 0;
  *&dds3Ver7->dante_pelem.reserved2 = 0;
  dds3Ver7->dante_pelem.keisyoskill = 0;
  dds3Ver7->dante_pelem.keiattr = 0;
  *&dds3Ver7->dante_pelem.exp = 0;
  dds3Ver7->dante_pelem.mitamaparam = 0;
  dds3Ver7->dante_pelem.levelupparam = 0;
  *&dds3Ver7->dante_pelem.skillcnt = 0;
  dds3Ver7->dante_pelem.skill = 0;
  dds3Ver7->dante_pelem.param = 0;
  dds3Ver7->dante_pelem.skillparam = 0;
  dds3Ver7->amapEX.blkOpenFlg01 = v8;
  *&dds3Ver7->dante_pelem.id = 0;
  dds3Ver7->dante_pelem.param = NewSpecific(sbyte, 6u);
  dds3Ver7->dante_pelem.skillparam = NewSpecific(sbyte, 6u);
  dds3Ver7->dante_pelem.skill = NewSpecific(ushort, 0x18u);
  dds3Ver7->dante_pelem.mitamaparam = NewSpecific(sbyte, 6u);
  dds3Ver7->dante_pelem.levelupparam = NewSpecific(sbyte, 6u);
  dds3Ver7->dante_pelem.keisyoskill = NewSpecific(ushort, 0x18u);
  dds3Ver7->dante_pelem.keiattr = NewSpecific(byte, 0x18u);
  dds3Ver7->saveTime = 0;
  dds3Ver7->autoMapOpen = NewSpecific(sbyte, 0x24u);
  dds3Ver7->autoMapOpenEX = NewSpecific(sbyte, 2u);
  dds3Ver7->fldRunWork = NewSpecific(byte, 0x6Bu);
  dds3Ver7->reserved = NewSpecific(sbyte, 0x93u);
  dds3Work->GameFileInfo.ver = 7;
}

// 0x1140980
s32 Load_18090368(FsSaveData *this, s32 num, dds3GlobalWork_t **Loadbuff, dds3AdditionWork_t **AdditionBuff) {
  s32 v11;

  if (num <= 19)
  {
    restoreData(saveData, num, Loadbuff, AdditionBuff);
    v11 = 0;
  }
  else
  {
    restoreData(saveData, 20, Loadbuff, AdditionBuff);
    v11 = 1;
  }
  SuspendData->IsRestored = v11;
  return v11;
}

// 0x113e1c0
bool Save(FsSaveData *this, s32 num, dds3GlobalWork_t *Savebuff, bool init) {
  SAVEDATA_o *saveData;
  bool v12;
  s32 v13;
  dds3GlobalWork_t_o *v14;
  System_RuntimeTypeHandle_o v17;
  System_Type_o *TypeFromHandle;
  s32 v20;
  System_Type_o *v21;
  s32 v22;
  System_Type_o *v23;
  s32 v24;
  System_Type_o *v25;
  s32 v26;
  System_Type_o *v27;
  s32 v28;
  u64 *v29;
  Il2CppObject *v31;
  s32 v32;
  u64 v33;
  u64 *v34;
  Il2CppObject *v35;
  System_Byte_array *v36;
  intptr_t v38;
  s32 v39;
  u64 v40;
  s64 v41;
  struct SAVEDATA_dds3GlobalWork_tag_array *v43;
  const MethodInfo_1145 *v46;
  intptr_t v48;
  const MethodInfo_1145 *v50;
  s32 v51;
  intptr_t v52;
  struct SAVEDATA_o *v53;
  struct System_Char_array *v54;
  s64 v55;
  s64 v56;
  struct System_String_o *v57;
  s64 v58;
  s64 v59;
  struct System_Char_array *v60;
  s64 v61;
  intptr_t v62;
  intptr_t v63;
  intptr_t v65;
  u64 v66;
  s32 v67;
  s64 v68;
  struct SAVEDATA_dds3WorkVer7_tag_array *saveVer7;
  const MethodInfo_1145 *v73;
  s32 v74;
  intptr_t v76;
  const MethodInfo_1145 *v78;
  intptr_t v79;
  struct SAVEDATA_o *v80;
  struct System_Char_array *v81;
  s64 v82;
  intptr_t v83;
  s64 v84;
  u64 *v85;
  u64 *v86;
  s64 v87;
  Il2CppObject *v89;
  u32 innerValue;
  s32 v94;
  s32 v95;
  s32 cb;
  s32 v97;
  s32 v98;
  FsSaveData_o *v99;
  char dest[1880];
  nn_ErrorRange_o ResultPathNotFound;
  u32 v102;
  SAVEDATA_dds3GlobalWork_tag_o v103;

  v102 = 0;
  ResultPathNotFound._descriptionEnd = 0;
  *&ResultPathNotFound._module = 0;
  Log("Save", 0);
  if ((num & 0x80000000) == 0)
  {
    if (num <= 19)
    {
      v13 = num;
      v14 = Savebuff;
      v12 = 0;
    }
    else
    {
      v12 = init;
      v13 = 20;
      v14 = Savebuff;
    }
    backupData(saveData, v13, v14, v12);
  }
  backupSystem(saveData);
  backupSystemVer7(saveData);
  v17.value = SAVEDATA_dds3GlobalWork_tag_var;
  TypeFromHandle = GetTypeFromHandle(v17);
  {
  }
  v99 = this;
  v20 = SizeOf_1552656(TypeFromHandle);
  v21 = GetTypeFromHandle(SAVEDATA_dds3AdditionWork_tag_var);
  v22 = SizeOf_1552656(v21);
  v23 = GetTypeFromHandle(SAVEDATA_dds3SystemWork_tag_var);
  v24 = SizeOf_1552656(v23);
  v25 = GetTypeFromHandle(SAVEDATA_dds3WorkVer7_tag_var);
  v26 = SizeOf_1552656(v25);
  v27 = GetTypeFromHandle(SAVEDATA_dds3SystemVer7_tag_var);
  LODWORD(v103.GameFileInfo.verstr) = v20;
  v28 = SizeOf_1552656(v27);
  v29 = sub_8D3950(s32, &v103);
  v31 = Concat_5269984("sizeGameInfo[", v29, "]");
  Log(v31, 0);
  v32 = v24 + v22 + 21 * (v26 + v20);
  v95 = v24;
  cb = v22;
  v98 = v28;
  v33 = (v32 + v28);
  *dest = v32 + v28;
  v34 = sub_8D3950(s32, dest);
  v35 = Concat_5269984("saveDataSize[", v34, "]");
  Log(v35, 0);
  v97 = v33;
  v36 = NewSpecific(byte, v33);
  v38 = AllocHGlobal_1551568(v20);
  v39 = 0;
  v40 = 0;
  v41 = 32;
  do
  {
    v43 = saveData->saveBuff;
    memcpy(dest, v43 + v41, sizeof(dest));
    {
    }
    v46 = Method_System_Runtime_InteropServices_Marshal_StructureToPtr_SAVEDATA_dds3GlobalWork_tag___;
    memcpy(&v103, dest, sizeof(v103));
    StructureToPtr_SAVEDATA_dds3GlobalWork_tag_(&v103, v38, 0, v46);
    Copy_1551888(v38, v36, v39, v20);
    ++v40;
    v41 += 1880;
    v39 += v20;
  }
  while (v40 != 20);
  {
  }
  FreeHGlobal(v38);
  v48 = AllocHGlobal_1551568(v20);
  v50 = Method_System_Runtime_InteropServices_Marshal_StructureToPtr_SAVEDATA_dds3GlobalWork_tag___;
  memmove(&v103, &saveData->suspendBuff, 0x758u);
  StructureToPtr_SAVEDATA_dds3GlobalWork_tag_(&v103, v48, 0, v50);
  Copy_1551888(v48, v36, 20 * v20, v20);
  FreeHGlobal(v48);
  v51 = 21 * v20;
  v52 = AllocHGlobal_1551568(cb);
  v53 = saveData;
  v54 = *&v53->AdditionBuff.fieldID;
  v55 = *&v53->AdditionBuff.CamTableIdx;
  *&v103.GameFileInfo.mode = *&v53->AdditionBuff.SeId;
  *&v103.GameFileInfo.ver = v55;
  v103.GameFileInfo.verstr = v54;
  v56 = *&v53->AdditionBuff.playerPos.y;
  v57 = *&v53->AdditionBuff.playerPos.w;
  v58 = *&v53->AdditionBuff.playerRot.y;
  v103.GameFileInfo.pad3 = *&v53->AdditionBuff.playerRot.w;
  *&v103.GameFileInfo.cname_nums = v58;
  v103.GameFileInfo.cname_code = v57;
  *&v103.GameFileInfo.endcnt = v56;
  v59 = *&v53->AdditionBuff.nameU;
  v60 = *&v53->AdditionBuff.CamMode;
  v61 = *&v53->AdditionBuff.gFldNowDZone;
  v62 = v52;
  v103.IntVariable = v53->AdditionBuff.dummy;
  *&v103.runtime = v61;
  v103.GameFileInfo.end_list = v60;
  *&v103.GameFileInfo.dante_mode = v59;
  StructureToPtr_SAVEDATA_dds3AdditionWork_tag_(&v103, v52, 0);
  Copy_1551888(v62, v36, 21 * v20, cb);
  FreeHGlobal(v62);
  LODWORD(v62) = cb + 21 * v20;
  v63 = AllocHGlobal_1551568(v95);
  StructureToPtr_SAVEDATA_dds3SystemWork_tag_(saveData->SystemBuff, v63, 0);
  Copy_1551888(v63, v36, v62, v95);
  FreeHGlobal(v63);
  v94 = v95 + v62;
  v65 = AllocHGlobal_1551568(v26);
  v66 = 0;
  v67 = cb + v95 + v51;
  v68 = 32;
  do
  {
    saveVer7 = saveData->saveVer7;
    memcpy(dest, saveVer7 + v68, 0x1C8u);
    {
    }
    v73 = Method_System_Runtime_InteropServices_Marshal_StructureToPtr_SAVEDATA_dds3WorkVer7_tag___;
    memcpy(&v103, dest, 0x1C8u);
    StructureToPtr_SAVEDATA_dds3WorkVer7_tag_(&v103, v65, 0, v73);
    Copy_1551888(v65, v36, v67, v26);
    ++v66;
    v68 += 456;
    v67 += v26;
  }
  while (v66 != 20);
  {
  }
  FreeHGlobal(v65);
  v74 = v94 + 20 * v26;
  v76 = AllocHGlobal_1551568(v26);
  v78 = Method_System_Runtime_InteropServices_Marshal_StructureToPtr_SAVEDATA_dds3WorkVer7_tag___;
  memmove(&v103, &saveData->suspendVer7, 0x1C8u);
  StructureToPtr_SAVEDATA_dds3WorkVer7_tag_(&v103, v76, 0, v78);
  Copy_1551888(v76, v36, v74, v26);
  FreeHGlobal(v76);
  LODWORD(v78) = v74 + v26;
  v79 = AllocHGlobal_1551568(v98);
  v80 = saveData;
  v81 = *&v80->SystemVer7.Transport_Count;
  v82 = *&v80->SystemVer7.EndingList;
  v83 = v79;
  v84 = *&v80->SystemVer7.Bad_Bit;
  *&v103.GameFileInfo.endcnt = v80->SystemVer7.reserved;
  *&v103.GameFileInfo.mode = v84;
  *&v103.GameFileInfo.ver = v82;
  v103.GameFileInfo.verstr = v81;
  StructureToPtr_SAVEDATA_dds3SystemVer7_tag_(&v103, v79, 0);
  Copy_1551888(v83, v36, v78, v98);
  FreeHGlobal(v83);
  v85 = Allocate(System_IO_MemoryStream);
  _ctor_3692368(v85, v97 + 4);
  v86 = Allocate(System_IO_BinaryWriter);
  _ctor_3633568(v86, v85);
  (*(*v86 + 568))(v86, 2, *(*v86 + 576));
  (*(*v86 + 456))(v86, v36, *(*v86 + 464));
  (*(*v85 + 504))(v85, *(*v85 + 512));
  v87 = (*(*v85 + 696))(v85, *(*v85 + 704));
  sub_22F10(0, System_IDisposable, v85);
  EnterExitRequestHandlingSection();
  v89 = Concat_5224608("Account Initialize filePath : ", v99->filePath);
  Log(v89, 0);
  Log("Save Data Delete", 0);
  innerValue = Delete(v99->filePath, 0).innerValue;
  v102 = innerValue;
  ResultPathNotFound = get_ResultPathNotFound();
  if (!sub_15C4E70(&ResultPathNotFound, innerValue))
    sub_15C5000(&v102);
  Log("Save Data Create", 0);
  v102 = Create(v99->filePath, v97 + 4, 0).innerValue;
  sub_15C5000(&v102);
  Log("Save Data Open", 0);
  v102 = Open(&v99->fileHandle, v99->filePath, 2, 0).innerValue;
  sub_15C5000(&v102);
  Log("Save Data Write", 0);
  v102 = Write(v99->fileHandle, 0, v87, *(v87 + 24), 1, 0).innerValue;
  sub_15C5000(&v102);
  Log("Save Data Close", 0);
  Close(v99->fileHandle, 0);
  Log("Save Data Commit", 0);
  v102 = Commit("ShinMegaten3").innerValue;
  sub_15C5000(&v102);
  LeaveExitRequestHandlingSection();
  return &xmmword_0 + 1;
}

// 0x113dff0
void SaveInit(FsSaveData *this) {
  u32 innerValue;

  innerValue = 0;
  Log("SaveInit", 0);
  Log("Mount", 0);
  innerValue = Mount("ShinMegaten3", Instance->userId, 0).innerValue;
  sub_15C5000(&innerValue);
  this->filePath = Format_5268592("{0}:/{1}", "ShinMegaten3", "SaveData");
  initialize(saveData, 0);
}

// 0x113e140
void SaveUnmount(FsSaveData *this) {
  Log("unmount", 0);
  Unmount("ShinMegaten3", 0);
}

// 0x1140ab0
void loadHeaderGameFileInfo(FsSaveData *this, s32 num, GameFileInfo_t **data) {
  setHeaderGameFileInfo(saveData, num, data);
}
