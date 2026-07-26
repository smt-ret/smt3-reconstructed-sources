# SMT3 reconstructed source code and headers

This repo contains a reconstruction of the SMT3 source code based on the metadata info provided by SMT3 HD.
SMT3 HD is seemingly a C-to-C# or C++/IL transpiled port, meaning a lot of the original source structure is reconstructable.
Some examples are:
```
struct scr_H_scrHeader_t_Fields
{
  uint8_t FileType;
  uint8_t FileFormat;
  uint16_t UserID;
  int32_t FileSize;
  struct System_Char_array *MagicCode;
  int32_t ExpandSize;
  int32_t TypeTableCount;
  uint16_t LocalIntCount;
  uint16_t LocalFloatCount;
  int32_t Resrve2;
  int32_t Resrve3;
};

struct ScrScriptProcess_StaticFields
{
  int32_t scrHandleCount;
  struct scr_H_scrProcessWork_s_o *scrHandleFirst;
  struct scr_H_scrProcessWork_s_o *scrHandleLast;
  struct scr_H_scrProcessWork_s_o *scrHandle_t;
  int32_t LoadAssetProcNo;
};

kernel_H_dds3ProcessID_t_o *__fastcall dds3KernelCore__dds3StartProcess(System_String_o *namestr, uint32_t priority, int32_t starttimer, int32_t shutdowntimer,
  System_Func_dds3ProcessID_t__object__o *processfunc, kernel_H_dds3ProcessID_t_o *id0, System_Func_dds3ProcessID_t__object__o *shutdownfunc, kernel_H_dds3ProcessID_t_o *id1, Il2CppObject *data, const MethodInfo *method);
```
These can be seen as transpiled versions of
```
// scr.h
typedef struct {
  uint8_t FileType;
  // ...
} scrHeader_t;

// ScrScriptProcess.c
#include "scr.h"
int32_t scrHandleCount;
struct scrProcessWork_s *scrHandleFirst;
struct scrProcessWork_s *scrHandleLast;
struct scrProcessWork_s *scrHandle_t;
int32_t LoadAssetProcNo;

// dds3KernelCore.c
#include "kernel.h"
struct dds3ProcessID_t dds3StartProcess(const char* namestr, ...);
```
