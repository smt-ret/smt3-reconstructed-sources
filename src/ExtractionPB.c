#include "types.h"

// 0xfef460
void Extraction(char *base_path, char *src_bin, char *out_bin) {
  System_String_o *dataPath;
  System_String_o *v7;
  Il2CppObject *v9;
  u64 *v10;
  u64 *v11;
  Il2CppObject *v12;
  u64 *v13;
  s64 v14;
  s64 v15;
  s32 v16;
  u32 v17;
  s64 v21;
  s64 v22;
  s64 v27;
  s64 v30;
  System_Object_array *v33;
  s64 *v34;
  s64 *v35;
  s64 *v42;
  s64 *v43;
  System_String_o *v47;
  Il2CppObject *v49;
  u64 *v50;
  u64 *v51;
  u8 *v52;
  u32 v54;
  u64 *v55;
  s32 v57;
  s64 v58;

  dataPath = get_dataPath();
  v7 = Concat_5221536(dataPath, base_path, src_bin);
  v9 = Concat_5224608("Read Path=", v7);
  Log(v9, 0);
  v10 = Allocate(System_IO_FileStream);
  _ctor_3664720(v10, v7, 3);
  v58 = (*(*v10 + 456))(v10, *(*v10 + 464));
  v11 = sub_8D3950(long, &v58);
  v12 = Concat("Read Size=", v11);
  Log(v12, 0);
  v13 = Allocate(System_IO_BinaryReader);
  _ctor(v13, v10, 0);
  v14 = (*(*v10 + 456))(v10, *(*v10 + 464));
  v55 = v13;
  v15 = (*(*v13 + 696))(v13, v14, *(*v13 + 704));
  v16 = 0;
  v17 = 0;
  do
  {
    v22 = v17 + 8LL;
    if (*(v15 + v22 + 32) == 80)
    {
      if (*(v15 + v17 + 9LL + 32) == 73)
      {
        if (*(v15 + v17 + 10LL + 32) == 66)
        {
          if (*(v15 + v17 + 11LL + 32) == 48)
          {
            v21 = 0;
            v27 = v15 + 40 + v17;
            while (1)
            {
              if (*(v27 + v21) == 69)
              {
                v30 = v27 + v21;
                if (*(v27 + v21 + 1) == 78)
                {
                  if (*(v30 + 2) == 68)
                  {
                    if (*(v30 + 3) == 48)
                      break;
                  }
                }
              }
              v21 += 16;
              if ((*(*v10 + 456))(v10, *(*v10 + 464)) <= v17 + v21)
                goto LABEL_37;
            }
            LODWORD(v21) = v21 + 16;
LABEL_37:
            v33 = NewSpecific(object, 6u);
            v34 = get_dataPath();
            v35 = v34;
            v33->m_Items[0] = v35;
            v33->m_Items[1] = base_path;
            v33->m_Items[2] = out_bin;
            v33->m_Items[3] = "_";
            v57 = v16;
            v42 = sub_8D3950(s32, &v57);
            v43 = v42;
            v33->m_Items[4] = v43;
            v33->m_Items[5] = ".pb";
            v47 = Concat_5270224(v33);
            v49 = Concat_5224608("Write Path=", v47);
            Log(v49, 0);
            v50 = Allocate(System_IO_FileStream);
            _ctor_3664720(v50, v47, 2);
            v51 = Allocate(System_IO_BinaryWriter);
            _ctor_3633568(v51, v50);
            v52 = (v15 + 32 + v17);
            do
            {
              v54 = *v52++;
              (*(*v51 + 440))(v51, v54, *(*v51 + 448));
              ++v17;
              LODWORD(v21) = v21 - 1;
            }
            while (v21);
            (*(*v51 + 376))(v51, *(*v51 + 384));
            (*(*v50 + 504))(v50, *(*v50 + 512));
            ++v16;
          }
        }
      }
    }
    v17 += 16;
  }
  while ((*(*v10 + 456))(v10, *(*v10 + 464)) > v17);
  (*(*v55 + 392))(v55, *(*v55 + 400));
  (*(*v10 + 504))(v10, *(*v10 + 512));
}

// 0xfef450
void ExtractionAll(void) {
  ;
}
