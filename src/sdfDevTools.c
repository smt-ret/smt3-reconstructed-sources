#include "types.h"

static char *dma_id_str[8];
static char *sdfDevDumpDmaVifLink_vif_unpack_str[16];
static char *sdfDevDumpDmaVifLink_vif_flag_str[8];
static s32 sdfDevDumpDmaVifLink_vif_elem_count[16];
static char *sdfDevDumpGsMemInfo_type_str[4];
static char *sdfDevDumpGsMemInfoRev_type_str[4];

s32 sdfPrintf(char *str, void **LegacyParamArray);

// 0x17e6eb0
void sdfDevDumpChipMemInfo(void) {
  ;
}

// 0x17e6e60
void sdfDevDumpDmaLink(void *aTag) {
  ;
}

// 0x17e6e70
void sdfDevDumpDmaVifLink(void *aTag) {
  ;
}

// 0x17e6e80
void sdfDevDumpGsMemInfo(void) {
  ;
}

// 0x17e6e90
void sdfDevDumpGsMemInfoRev(void) {
  ;
}

// 0x17e6b20
void sdfDevDumpMem(void *aPtr, s32 aLeng) {
  s32 v5;
  System_Object_array *v6;
  s64 *v7;
  s64 *v9;
  System_Object_array *v11;
  bool v12;
  System_Object_array *v14;
  s32 v17;
  s32 v18;
  System_Object_array *v20;
  System_Object_array *v22;
  System_Object_array *v24;
  s64 *v25;
  s32 v26;

  if (aLeng >= 1)
  {
    v5 = 0;
    while (1)
    {
      while (1)
      {
        while (v5 == 8)
        {
          v11 = Empty_string_();
          sdfPrintf("-", v11);
          v5 = 9;
          v12 = __OFSUB__(aLeng--, 1);
          if ((aLeng < 0) ^ v12 | (aLeng == 0))
            goto LABEL_44;
        }
        if (!v5)
          break;
        v14 = Empty_string_();
        sdfPrintf(" ", v14);
        if (++v5 != 16)
          goto LABEL_37;
LABEL_33:
        v22 = Empty_string_();
        sdfPrintf("\n", v22);
        v5 = 0;
LABEL_37:
        v12 = __OFSUB__(aLeng--, 1);
        if ((aLeng < 0) ^ v12 | (aLeng == 0))
          goto LABEL_44;
      }
      v6 = NewSpecific(object, 1u);
      v26 = *il2cp::SizeOf(aPtr, s32);
      v7 = sub_8D3950(s32, &v26);
      v9 = v7;
      v6->m_Items[0] = v9;
      sdfPrintf("%08X : ", v6);
      v17 = *il2cp::SizeOf(aPtr, s32) & 0xF;
      if (v17)
      {
        v18 = v17 + 1;
        do
        {
          v20 = Empty_string_();
          sdfPrintf("   ", v20);
          --v18;
        }
        while (v18 >= 2);
        v5 = v17 + 1;
        if (v5 != 16)
          goto LABEL_37;
        goto LABEL_33;
      }
      v5 = 1;
      v12 = __OFSUB__(aLeng--, 1);
      if ((aLeng < 0) ^ v12 | (aLeng == 0))
        goto LABEL_44;
    }
  }
  v5 = 0;
LABEL_44:
  v24 = Empty_string_();
  if (v5)
  {
    v25 = &"\n\n";
  }
  else
  {
    v25 = &"\n";
  }
  sdfPrintf(*v25, v24);
}

// 0x17e6ea0
void sdfDevDumpMemInfo(void) {
  ;
}
