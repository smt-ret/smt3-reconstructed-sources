#include "types.h"

typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfGsMemSlice_t sdfGsMemSlice_t;
typedef struct sdfLoadImagePacket_t sdfLoadImagePacket_t;
typedef struct sdfPreDrawHook_t sdfPreDrawHook_t;
typedef struct sdfPreDrawTag_t sdfPreDrawTag_t;
typedef struct sdfStoreImagePacket_t sdfStoreImagePacket_t;

// 0x1791af0
void sdfLinkLoadImage(sdfDrawTag_t *aDrawTag, sdfGsMemSlice_t *aGsHandle, s32 aDstX, s32 aDstY, s32 aWidth, s32 aHeight, void *aBuffer, void *aAllocator) {
  ;
}

// 0x1791ad0
void sdfLinkStoreFrameImage(sdfDrawTag_t *aDrawTag, sdfPreDrawTag_t *aPreDrawTag, s32 aSrcX, s32 aSrcY, s32 aWidth, s32 aHeight, void *aBuffer, void *aCallback, void *aCallbackParam, void *aAllocator) {
  ;
}

// 0x1791ac0
void sdfLinkStoreFrameImagePredraw(sdfPreDrawHook_t *aPre, s32 aEvenOdd) {
  ;
}

// 0x1791ab0
void sdfLinkStoreImage(sdfDrawTag_t *aDrawTag, sdfGsMemSlice_t *aGsHandle, s32 aSrcX, s32 aSrcY, s32 aWidth, s32 aHeight, void *aBuffer, void *aCallback, void *aCallbackParam, void *aAllocator) {
  ;
}

// 0x1791ae0
void sdfSetLoadImage(sdfLoadImagePacket_t *aPacket, sdfGsMemSlice_t *aGsHandle, s32 aDstX, s32 aDstY, s32 aWidth, s32 aHeight, void *aBuffer) {
  ;
}

// 0x1791aa0
void sdfSetStoreImage(sdfStoreImagePacket_t *aPacket, sdfGsMemSlice_t *aGsHandle, s32 aSrcX, s32 aSrcY, s32 aWidth, s32 aHeight, void *aBuffer, void *aCallback, void *aCallbackParam) {
  ;
}
