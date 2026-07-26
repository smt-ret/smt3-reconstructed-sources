#include "types.h"

// 0x1860570
void *_Get_effPCPParamTable(u32 kateg, u32 param) {
  Il2CppObject *result;

  result = 0;
  switch (kateg)
  {
    case 0u:
      switch (param)
      {
        case 0u:
          result = effPCP_ThunderSpherePoly_Param000;
          break;
        case 1u:
          result = effPCP_ThunderSpherePoly_Param001;
          break;
        case 2u:
          result = effPCP_ThunderSpherePoly_Param002;
          break;
        case 3u:
          result = effPCP_ThunderSpherePoly_Param003;
          break;
        case 4u:
          result = effPCP_ThunderSpherePoly_Param004;
          break;
        case 5u:
          result = effPCP_ThunderSpherePoly_Param005;
          break;
        case 6u:
          result = effPCP_ThunderSpherePoly_Param006;
          break;
        case 7u:
          result = effPCP_ThunderSpherePoly_Param007;
          break;
        case 8u:
          result = effPCP_ThunderSpherePoly_Param008;
          break;
        default:
          result = 0;
          break;
      }
      break;
    case 1u:
      switch (param)
      {
        case 0u:
          result = effPCP_ThunderPoly_Param000;
          break;
        case 1u:
          result = effPCP_ThunderPoly_Param001;
          break;
        case 2u:
          result = effPCP_Zio_Param000;
          break;
        case 3u:
          result = effPCP_Zio_Param001;
          break;
        case 4u:
          result = effPCP_Zio_Param002;
          break;
        case 5u:
          result = effPCP_Zio_Param003;
          break;
        case 6u:
          result = effPCP_Zio_Param004;
          break;
        case 7u:
          result = effPCP_Zio_Param005;
          break;
        case 8u:
          result = effPCP_Zio_Param006;
          break;
        case 9u:
          result = effPCP_Zio_Param007;
          break;
        case 0xAu:
          result = effPCP_Zio_Param008;
          break;
        case 0xBu:
          result = effPCP_Zio_Param009;
          break;
        case 0xCu:
          result = effPCP_12_Eve001;
          break;
        case 0xDu:
          result = effPCP_13_Eve002;
          break;
        case 0xEu:
          result = effPCP_14_Eve003;
          break;
        case 0xFu:
          result = effPCP_15_Eve004;
          break;
        case 0x10u:
          result = effPCP_16_Syok001;
          break;
        case 0x11u:
          result = effPCP_17_Syok002;
          break;
        case 0x12u:
          result = effPCP_18_Syok003;
          break;
        case 0x13u:
          result = effPCP_19_Syok004;
          break;
        case 0x14u:
          result = effPCP_20_Syok005;
          break;
        case 0x15u:
          result = effPCP_21_Syok005A;
          break;
        default:
          result = 0;
          break;
      }
      break;
    case 2u:
      result = effPCP_ThunderRadiatePoly_Param000;
      break;
    case 0xAu:
      if (param == 1)
      {
        result = effPCP_MultiBlurExp_Param001;
      }
      else if (param)
      {
        result = 0;
      }
      else
      {
        result = effPCP_MultiBlurExp_Param000;
      }
      break;
    case 0xDu:
      result = effPCP_SparkleSphere_Param000;
      break;
    case 0xEu:
      result = effPCP_FlashPolySphere_Param000;
      break;
    case 0x1Au:
      if (param == 1)
      {
        result = effPCP_MultiFilterExp_Param001;
      }
      else if (param)
      {
        result = 0;
      }
      else
      {
        result = effPCP_MultiFilterExp_Param000;
      }
      break;
    case 0x1Bu:
      result = effPCP_BlinkMultiBlur_Param000;
      break;
    default:
      return result;
  }
  return result;
}
