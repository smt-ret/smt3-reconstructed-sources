#pragma once
#include <stdint.h>
#include <stdbool.h>

typedef int8_t s8;
typedef uint8_t u8;
typedef int16_t s16;
typedef uint16_t u16;
typedef int32_t s32;
typedef uint32_t u32;
typedef int64_t s64;
typedef uint64_t u64;
typedef float f32;
typedef double f64;

#define UNKNOWN_ARRAY_SIZE 1
#define UNKNOWN_DEFINE_VALUE 0

typedef struct { f32 x, y; } sdfVector2_t;
typedef struct { f32 x, y, z; } sdfVector3_t;
typedef struct { f32 x, y, z, w; } sdfVector4_t;
typedef struct { f32 x, y, z, w; } sdfQuaternion_t;
typedef struct { f32 m[16]; } sdfMatrix4_t;
typedef struct { f32 r, g, b, a; } sdfColor_t;
typedef struct { u8 r, g, b, a; } sdfColor32_t;
