#ifndef CC_CORE_H
#define CC_CORE_H
/* Core fixed-size integer and floating point types, and common small structs.
   Copyright 2017 ClassicalSharp | Licensed under BSD-3
*/

#if _MSC_VER
typedef unsigned __int8  uint8_t;
typedef unsigned __int16 uint16_t;
typedef unsigned __int32 uint32_t;
typedef unsigned __int64 uint64_t;
#ifdef _WIN64
typedef unsigned __int64 uintptr_t;
#else
typedef unsigned int     uintptr_t;
#endif

typedef signed __int8  int8_t;
typedef signed __int16 int16_t;
typedef signed __int32 int32_t;
typedef signed __int64 int64_t;
#define NOINLINE_ __declspec(noinline)
#elif __GNUC__
#include <stdint.h>
#define NOINLINE_ __attribute__((noinline))
#else
#error "I don't recognise this compiler. You'll need to add required definitions in Core.h!"
#endif

typedef uint16_t Codepoint;
typedef uint8_t bool;
#define true 1
#define false 0
#define NULL ((void*)0)

#define EXTENDED_BLOCKS
#ifdef EXTENDED_BLOCKS
typedef uint16_t BlockID;
#else
typedef uint8_t BlockID;
#endif

#define EXTENDED_TEXTURES
#ifdef EXTENDED_TEXTURES
typedef uint16_t TextureLoc;
#else
typedef uint8_t TextureLoc;
#endif

typedef uint8_t BlockRaw;
typedef uint8_t EntityID;
typedef uint8_t Face;
typedef uint32_t ReturnCode;
typedef uint64_t TimeMS;

typedef struct Rect2D_  { int X, Y, Width, Height; } Rect2D;
typedef struct Point2D_ { int X, Y; } Point2D;
typedef struct Size2D_  { int Width, Height; } Size2D;
typedef struct FontDesc_ { void* Handle; uint16_t Size, Style; } FontDesc;
typedef struct TextureRec_ { float U1, V1, U2, V2; } TextureRec;
typedef struct Bitmap_ { uint8_t* Scan0; int Width, Height; } Bitmap;

/*#define CC_BUILD_GL11*/
#define CC_BUILD_D3D9
#define CC_BUILD_WIN
/*#define CC_BUILD_OSX*/
/*#define CC_BUILD_NIX*/
/*#define CC_BUILD_SOLARIS*/

#ifdef CC_BUILD_D3D9
typedef void* GfxResourceID;
#else
typedef uint32_t GfxResourceID;
#endif
#endif
