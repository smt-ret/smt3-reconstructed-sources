#include "types.h"

typedef struct dds3StartMenuDisp dds3StartMenuDisp;

// 0xff5b20
void Awake(dds3StartMenuDisp *this) {
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v5;

  gameObject = get_gameObject(this);
  transform = get_transform(gameObject, 0);
  v5 = Find(transform, StringLiteral_14973, 0);
  this->menutxt = GetComponent_GUILayer_(v5);
}

// 0xff5ba0
void Start(dds3StartMenuDisp *this) {
  ;
}

// 0xff5bb0
void Update(dds3StartMenuDisp *this) {
  ;
}
