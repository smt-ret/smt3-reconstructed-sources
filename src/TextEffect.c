#include "types.h"

typedef struct TextEffect TextEffect;

static void *_verticesCache;

void Process(void *vertices);

// 0x1345240
void ModifyMesh(TextEffect *this, void *vh) {
  GetUIVertexStream(vh, _verticesCache);
  Process(_verticesCache);
  Clear(vh, 0);
  AddUIVertexTriangleStream(vh, _verticesCache);
}

// 0x13452f0
void Process(void *vertices) {
  s32 Count;
  s32 v4;
  s32 v5;
  s32 v6;
  s64 v7;
  s32 v8;
  UnityEngine_UIVertex_o v9;
  UnityEngine_UIVertex_o v10;
  UnityEngine_UIVertex_o v11;
  UnityEngine_UIVertex_o v12;
  UnityEngine_UIVertex_o v13;
  UnityEngine_UIVertex_o v14;
  UnityEngine_UIVertex_o v15;
  UnityEngine_UIVertex_o v16;

  Count = _get_Count(vertices);
  if (Count < 6)
  {
    v5 = 0;
  }
  else
  {
    v4 = 0;
    v5 = 0;
    v6 = Count / 6;
    do
    {
      _get_Item(
        &v15,
        vertices,
        v4);
      *&v16.position.z = *&v15.position.z;
      *&v16.normal.y = *&v15.normal.y;
      v16.tangent = v15.tangent;
      *&v16.position.x = *&v15.position.x;
      v16.uv1 = v15.uv1;
      v16.uv2 = v15.uv2;
      v16.uv3.x = v15.uv3.x;
      v16.color = v15.color;
      v16.uv0 = v15.uv0;
      _set_Item(vertices, v5, &v16);
      _get_Item(
        &v14,
        vertices,
        v4 + 1);
      *&v16.position.z = *&v14.position.z;
      *&v16.normal.y = *&v14.normal.y;
      v16.tangent = v14.tangent;
      *&v16.position.x = *&v14.position.x;
      v16.uv3.x = v14.uv3.x;
      v16.uv1 = v14.uv1;
      v16.uv2 = v14.uv2;
      v16.color = v14.color;
      v16.uv0 = v14.uv0;
      _set_Item(vertices, v5 + 1, &v16);
      _get_Item(
        &v13,
        vertices,
        v4 + 2);
      *&v16.position.z = *&v13.position.z;
      *&v16.normal.y = *&v13.normal.y;
      v16.tangent = v13.tangent;
      *&v16.position.x = *&v13.position.x;
      v16.uv1 = v13.uv1;
      v16.uv2 = v13.uv2;
      v16.uv3.x = v13.uv3.x;
      v16.color = v13.color;
      v16.uv0 = v13.uv0;
      _set_Item(vertices, v5 + 2, &v16);
      _get_Item(
        &v12,
        vertices,
        v4 + 3);
      *&v16.position.z = *&v12.position.z;
      *&v16.normal.y = *&v12.normal.y;
      v16.tangent = v12.tangent;
      *&v16.position.x = *&v12.position.x;
      v16.uv1 = v12.uv1;
      v16.uv2 = v12.uv2;
      v16.uv3.x = v12.uv3.x;
      v16.color = v12.color;
      v16.uv0 = v12.uv0;
      _set_Item(vertices, v5 + 3, &v16);
      _get_Item(
        &v11,
        vertices,
        v4 + 4);
      *&v16.position.z = *&v11.position.z;
      *&v16.normal.y = *&v11.normal.y;
      v16.tangent = v11.tangent;
      *&v16.position.x = *&v11.position.x;
      v16.uv1 = v11.uv1;
      v16.uv2 = v11.uv2;
      v16.uv3.x = v11.uv3.x;
      v16.color = v11.color;
      v16.uv0 = v11.uv0;
      _set_Item(vertices, v5 + 4, &v16);
      _get_Item(
        &v10,
        vertices,
        v4 + 5);
      *&v16.position.z = *&v10.position.z;
      *&v16.normal.y = *&v10.normal.y;
      v16.tangent = v10.tangent;
      *&v16.position.x = *&v10.position.x;
      v16.uv1 = v10.uv1;
      v16.uv2 = v10.uv2;
      v16.uv3.x = v10.uv3.x;
      v16.color = v10.color;
      v16.uv0 = v10.uv0;
      _set_Item(vertices, v5 + 5, &v16);
      _get_Item(
        &v16,
        vertices,
        v5);
      v7 = *&v16.position.x;
      _get_Item(
        &v9,
        vertices,
        v5 + 1);
      if ((((v9.position.x - *&v7) * (v9.position.x - *&v7))
          + ((v9.position.y - *(&v7 + 1)) * (v9.position.y - *(&v7 + 1)))) > 0.0)
        v5 += 6;
      --v6;
      v4 += 6;
    }
    while (v6);
  }
  v8 = _get_Count(vertices);
  _RemoveRange(vertices, v5, v8 - v5);
}
