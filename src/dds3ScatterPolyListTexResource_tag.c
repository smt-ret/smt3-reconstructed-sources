#include "types.h"

typedef struct dds3ScatterPolyListTexResource_tag dds3ScatterPolyListTexResource_tag;
typedef struct sdfTexHandle_t sdfTexHandle_t;

struct dds3ScatterPolyListTexResource_tag {
    sdfTexHandle_t *hTex;
    u32 count;
};

// 0x14f77c0
void pClone(dds3ScatterPolyListTexResource_tag *this, dds3ScatterPolyListTexResource_tag **dst) {
  (*dst)->fields = this->fields;
}
