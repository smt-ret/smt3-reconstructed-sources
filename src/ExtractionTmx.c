#include "types.h"

void Extraction(char *base_path, char *src_bin, char *out_bin);

// 0xfefbd0
void Extraction(char *base_path, char *src_bin, char *out_bin) {
  System_String_o *dataPath;
  System_String_o *v7;
  Il2CppObject *v9;
  u64 *v10;
  u64 *v11;
  Il2CppObject *v12;
  u64 *v13;
  s64 v14;
  s64 v16;
  s32 v17;
  u32 v18;
  s32 v26;
  System_Object_array *v27;
  s64 *v28;
  s64 *v29;
  s64 *v36;
  s64 *v37;
  System_String_o *v41;
  Il2CppObject *v43;
  u64 *v44;
  u64 *v45;
  u8 *v46;
  u32 v48;
  s32 v50;
  s64 v51;

  dataPath = get_dataPath();
  v7 = Concat_5221536(dataPath, base_path, src_bin);
  v9 = Concat_5224608("Read Path=", v7);
  Log(v9, 0);
  v10 = Allocate(System_IO_FileStream);
  _ctor_3664720(v10, v7, 3);
  v51 = (*(*v10 + 456))(v10, *(*v10 + 464));
  v11 = sub_8D3950(long, &v51);
  v12 = Concat("Read Size=", v11);
  Log(v12, 0);
  v13 = Allocate(System_IO_BinaryReader);
  _ctor(v13, v10, 0);
  v14 = (*(*v10 + 456))(v10, *(*v10 + 464));
  v16 = (*(*v13 + 696))(v13, v14, *(*v13 + 704));
  v17 = 0;
  v18 = 0;
  do
  {
    if (*(v16 + v18 + 32) == 84)
    {
      if (*(v16 + v18 + 1LL + 32) == 77)
      {
        if (*(v16 + v18 + 2LL + 32) == 88)
        {
          if (*(v16 + v18 + 3LL + 32) == 48)
          {
            {
            }
            v26 = ToInt32(v16, v18 - 4, 0);
            v27 = NewSpecific(object, 6u);
            v28 = get_dataPath();
            v29 = v28;
            v27->m_Items[0] = v29;
            v27->m_Items[1] = base_path;
            v27->m_Items[2] = out_bin;
            v27->m_Items[3] = "_";
            v50 = v17;
            v36 = sub_8D3950(s32, &v50);
            v37 = v36;
            v27->m_Items[4] = v37;
            v18 -= 8;
            v27->m_Items[5] = ".tmx";
            v41 = Concat_5270224(v27);
            v43 = Concat_5224608("Write Path=", v41);
            Log(v43, 0);
            v44 = Allocate(System_IO_FileStream);
            _ctor_3664720(v44, v41, 2);
            v45 = Allocate(System_IO_BinaryWriter);
            _ctor_3633568(v45, v44);
            if (v26)
            {
              v46 = (v16 + 32 + v18);
              do
              {
                v48 = *v46++;
                (*(*v45 + 440))(v45, v48, *(*v45 + 448));
                ++v18;
                --v26;
              }
              while (v26);
            }
            (*(*v45 + 376))(v45, *(*v45 + 384));
            (*(*v44 + 504))(v44, *(*v44 + 512));
            ++v17;
          }
        }
      }
    }
    ++v18;
  }
  while ((*(*v10 + 456))(v10, *(*v10 + 464)) > v18);
  (*(*v13 + 392))(v13, *(*v13 + 400));
  (*(*v10 + 504))(v10, *(*v10 + 512));
}

// 0xfefb70
void ExtractionAll(void) {
  Extraction("/AssetBundle/AssetData/dds3data/test/", "0x59.PB.bytes", "0x59");
}
