#include "types.h"

typedef struct RippleEffect RippleEffect;

void UpdateShaderParameters(RippleEffect *this);

// 0x1892b80
void Awake(RippleEffect *this) {
  this->initflg = 0;
}

// 0x1892db0
void OnRenderImage(RippleEffect *this, void *source, void *destination) {
  UnityEngine_Material_o *material;

  if (this->initflg)
  {
    material = this->material;
    Blit_27233792(source, destination, material);
  }
  else
  {
    Blit(source, destination, 0);
  }
}

// 0x1892b90
void Update(RippleEffect *this) {
    UpdateShaderParameters(0);
}

// 0x1892510
void UpdateShaderParameters(RippleEffect *this) {
}
