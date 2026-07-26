#include "types.h"

static s8 keyActMode;
static u8 keyAct[UNKNOWN_ARRAY_SIZE];
static s16 *pbMoveDir[4];

// 0x14a2540
u8 pbGetKeyAction(u8 press) {
  pbKeyConv_c *v3;
  struct pbKeyConv_StaticFields *static_fields;
  struct System_Byte_array *keyAct;
  u32 keyActMode;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;

  static_fields = v3->static_fields;
  keyAct = static_fields->keyAct;
  keyActMode = static_fields->keyActMode;
  bounds = keyAct->bounds;
  length = bounds[1].length;
  return keyAct->m_Items[press + length * keyActMode];
}

// 0x14a2620
u8 pbGetKeyMode(void) {
  return keyActMode;
}

// 0x14a1dd0
void pbInitKeyAction(void) {
  struct System_Byte_array *keyAct;
  Il2CppArrayBounds *bounds;
  struct System_Byte_array *v5;
  Il2CppArrayBounds *v6;
  struct System_Byte_array *v8;
  Il2CppArrayBounds *v9;
  struct System_Byte_array *v11;
  Il2CppArrayBounds *v12;
  struct System_Byte_array *v14;
  Il2CppArrayBounds *v15;
  struct System_Byte_array *v17;
  Il2CppArrayBounds *v18;
  il2cpp_array_size_t length;
  struct System_Byte_array *v22;
  Il2CppArrayBounds *v23;
  il2cpp_array_size_t v25;
  struct System_Byte_array *v27;
  Il2CppArrayBounds *v28;
  il2cpp_array_size_t v30;
  struct System_Byte_array *v32;
  Il2CppArrayBounds *v33;
  il2cpp_array_size_t v35;
  struct System_Byte_array *v37;
  Il2CppArrayBounds *v38;
  il2cpp_array_size_t v40;
  struct System_Byte_array *v42;
  Il2CppArrayBounds *v43;
  il2cpp_array_size_t v45;
  struct System_Byte_array *v47;
  Il2CppArrayBounds *v48;
  il2cpp_array_size_t v50;
  struct System_Byte_array *v52;
  Il2CppArrayBounds *v53;
  il2cpp_array_size_t v55;
  struct System_Byte_array *v57;
  Il2CppArrayBounds *v58;
  il2cpp_array_size_t v60;
  struct System_Byte_array *v62;
  Il2CppArrayBounds *v63;
  il2cpp_array_size_t v65;
  struct System_Byte_array *v67;
  Il2CppArrayBounds *v68;
  il2cpp_array_size_t v70;
  struct System_Byte_array *v72;
  Il2CppArrayBounds *v73;
  il2cpp_array_size_t v75;
  struct System_Byte_array *v77;
  Il2CppArrayBounds *v78;
  il2cpp_array_size_t v80;
  struct System_Byte_array *v82;
  Il2CppArrayBounds *v83;
  il2cpp_array_size_t v85;
  struct System_Byte_array *v87;
  Il2CppArrayBounds *v88;
  il2cpp_array_size_t v90;

  keyActMode = 0;
  bounds = keyAct->bounds;
  keyAct->m_Items[0] = 0;
  v5 = keyAct;
  v6 = v5->bounds;
  v5->m_Items[1] = 1;
  v8 = keyAct;
  v9 = v8->bounds;
  v8->m_Items[2] = 2;
  v11 = keyAct;
  v12 = v11->bounds;
  v11->m_Items[3] = 3;
  v14 = keyAct;
  v15 = v14->bounds;
  v14->m_Items[4] = 4;
  v17 = keyAct;
  v18 = v17->bounds;
  length = v18[1].length;
  v17->m_Items[length] = 3;
  v22 = keyAct;
  v23 = v22->bounds;
  v25 = v23[1].length;
  v22->m_Items[v25 + 1] = 0;
  v27 = keyAct;
  v28 = v27->bounds;
  v30 = v28[1].length;
  v27->m_Items[v30 + 2] = 1;
  v32 = keyAct;
  v33 = v32->bounds;
  v35 = v33[1].length;
  v32->m_Items[v35 + 3] = 2;
  v37 = keyAct;
  v38 = v37->bounds;
  v40 = v38[1].length;
  v37->m_Items[v40 + 4] = 4;
  v42 = keyAct;
  v43 = v42->bounds;
  v45 = v43[1].length;
  v42->m_Items[2 * v45] = 2;
  v47 = keyAct;
  v48 = v47->bounds;
  v50 = v48[1].length;
  v47->m_Items[(2 * v50) | 1] = 3;
  v52 = keyAct;
  v53 = v52->bounds;
  v55 = v53[1].length;
  v52->m_Items[2 * v55 + 2] = 0;
  v57 = keyAct;
  v58 = v57->bounds;
  v60 = v58[1].length;
  v57->m_Items[2 * v60 + 3] = 1;
  v62 = keyAct;
  v63 = v62->bounds;
  v65 = v63[1].length;
  v62->m_Items[2 * v65 + 4] = 4;
  v67 = keyAct;
  v68 = v67->bounds;
  v70 = v68[1].length;
  v67->m_Items[3 * v70] = 1;
  v72 = keyAct;
  v73 = v72->bounds;
  v75 = v73[1].length;
  v72->m_Items[3 * v75 + 1] = 2;
  v77 = keyAct;
  v78 = v77->bounds;
  v80 = v78[1].length;
  v77->m_Items[3 * v80 + 2] = 3;
  v82 = keyAct;
  v83 = v82->bounds;
  v85 = v83[1].length;
  v82->m_Items[3 * v85 + 3] = 0;
  v87 = keyAct;
  v88 = v87->bounds;
  v90 = v88[1].length;
  v87->m_Items[3 * v90 + 4] = 4;
}

// 0x14a2790
u8 pbRotLKeyAct(void) {
  pbKeyConv_c *v2;
  struct pbKeyConv_StaticFields *static_fields;
  s32 keyActMode;
  s32 v5;
  char v6;
  u8 result;

  static_fields = v2->static_fields;
  keyActMode = static_fields->keyActMode;
  v5 = keyActMode + 3;
  v6 = keyActMode + 6;
  if (v5 >= 0)
    v6 = v5;
  result = v5 - (v6 & 0xFC);
  static_fields->keyActMode = result;
  return result;
}

// 0x14a2700
u8 pbRotRKeyAct(void) {
  pbKeyConv_c *v2;
  struct pbKeyConv_StaticFields *static_fields;
  s32 keyActMode;
  s32 v5;
  char v6;
  u8 result;

  static_fields = v2->static_fields;
  keyActMode = static_fields->keyActMode;
  v5 = keyActMode + 5;
  v6 = keyActMode + 8;
  if (v5 >= 0)
    v6 = v5;
  result = v5 - (v6 & 0xFC);
  static_fields->keyActMode = result;
  return result;
}

// 0x14a2690
void pbSetKeyMode(u8 mode) {
  keyActMode = mode;
}
