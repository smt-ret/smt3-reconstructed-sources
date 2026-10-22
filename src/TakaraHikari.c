#include "types.h"

typedef struct TakaraHikari TakaraHikari;
typedef struct dds3DefaultMain dds3DefaultMain;

static s32 id_AlfPower;

void *GetMainCamera(dds3DefaultMain *this);

// 0x1344dc0
void Start(TakaraHikari *this) {
  ;
}

// 0x1344dd0
void Update(TakaraHikari *this) {
  UnityEngine_Object_o *hikari_obj;
  UnityEngine_GameObject_o *MainCamera;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v8;
  f32 *static_fields;
  f32 v12;
  f32 v13;
  f32 v14;
  f32 v15;
  s32 fieldID;
  UnityEngine_Transform_o *v19;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  UnityEngine_Material_array *materials;
  il2cpp_array_size_t max_length;
  UnityEngine_Material_array *v28;
  u64 v29;
  UnityEngine_Material_o **m_Items;
  UnityEngine_Material_o *v33;
  UnityEngine_Vector3_o position;
  UnityEngine_Vector3_o v35;
  UnityEngine_Vector4_o v36;

  hikari_obj = this->hikari_obj;
  if (op_Inequality(hikari_obj, 0, 0)
    && get_activeSelf(this->hikari_obj))
  {
    MainCamera = GetMainCamera(kernelObject);
    transform = get_transform(this->hikari_obj, 0);
    v8 = get_transform(MainCamera, 0);
    position = get_position(v8);
    v12 = static_fields[42];
    v13 = static_fields[43];
    v15 = static_fields[44];
    v14 = static_fields[45];
    v36.x = v12;
    v36.y = v13;
    v36.z = v15;
    v36.w = v14;
    v35 = op_Implicit_8738992(v36);
    LookAt_27488480(transform, position, v35);
    fieldID = fldGb->fieldID;
    if (fieldID >= 1)
    {
      if (fieldID <= 8)
      {
        v19 = get_transform(this->hikari_obj, 0);
        Child = GetChild(v19, 0);
        gameObject = get_gameObject(Child);
        if (op_Inequality(gameObject, 0, 0))
        {
          Component_object = GetComponent_object_(gameObject);
          if (op_Inequality(Component_object, 0, 0))
          {
            materials = get_materials(Component_object);
            max_length = materials->max_length;
            if (max_length >= 1)
            {
              v28 = materials;
              v29 = 0;
              m_Items = materials->m_Items;
              do
              {
                v33 = m_Items[v29];
                SetFloat_27246832(v33, id_AlfPower, 0.25);
                LODWORD(max_length) = v28->max_length;
                ++v29;
              }
              while (v29 < max_length);
            }
          }
        }
      }
    }
  }
}
