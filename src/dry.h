//
//  dry.h
//  dryGL main include
//
//  Created by Jordi Ros on 15/02/13.
//  Copyright (c) 2013 Jordi Ros. All rights reserved.
//

#ifndef DRY_H_
#define DRY_H_

// Common includes
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// STL
#include <string>
#include <vector>
#include <map>

// Null
#ifndef NULL
#define NULL 0
#endif

// Mem
#define NEW                         new
#define NEW_ARRAY(x,c)              new x[c]
#define DISPOSE(p)                  do { if (p) { delete   (p);  (p)  = NULL; } } while (0)
#define DISPOSE_ARRAY(p)            do { if (p) { delete [](p); (p) = NULL; } } while (0)
#define DISPOSE_ARRAY_P(p,n)        do { if (p) { for (int i=0; i<(int)n; i++) DISPOSE(p[i]); DISPOSE_ARRAY(p); } } while(0)
#define SAFE_RELEASE(p)             do { if (p) { (p)->Release(); (p)=NULL; } } while(0)

// Min/Max
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

// Stringify
#define STRING(A) #A

// Types
typedef unsigned char   uchar;
typedef unsigned short  ushort;
typedef unsigned int    uint;

// Macro
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&);               \
  void operator=(const TypeName&)

//------------------------------------------------------------------------------------------------
// Dry
//------------------------------------------------------------------------------------------------
namespace dry {
    
#define DRY_TARGET_IOS                  // DRY platform target: only iOS for now
#define DRY_VERSION_STR     "0.1.0"     // DRY version

// LogLevel
// TODO: Log policy we do not log by ourselfs (we offer a default policy tho)
enum LogLevel
{
    LogSystem  = 1<<0,
    LogError   = 1<<0,
    LogWarning = 1<<1,
    LogInfo    = 1<<3,
    // Presets
    LogErrors   = LogError | LogWarning,
    LogDebug    = LogSystem | LogError | LogWarning | LogInfo,
    LogRelease  = LogError,
};
    
void                Init        (LogLevel loglevel, const std::string &logfile);
void                Shut        ();
void                Log         (LogLevel loglevel, const char *log, ...);                  // Log function
void                SetPaths    (const std::string &bundle, const std::string &docpath);    // Set app paths
const std::string  &GetFilePath (const std::string &file);                                  // Main bundle path (read only)
const std::string  &GetFilePath (const std::string &file, const std::string &docpath);      // Documents path (read/write)
float               GetTime     ();                                                         // Get system time

// AppParams
struct AppParams
{
    AppParams() { }
    AppParams(int width, int height, bool retina)
    {
        Width   = width;
        Height  = height;
        Retina  = retina;
    }
    int  Width;
    int  Height;
    bool Retina;
};

// DeviceOrientation
enum DeviceOrientation
{
    DeviceOrientationPortrait,
    DeviceOrientationPortraitUpsideDown,
    DeviceOrientationLandscapeLeft,
    DeviceOrientationLandscapeRight,
    DeviceOrientationUnknown = 0xFFFFFFFF,
};

// PixelFormat
enum PixelFormat
{
    PixelFormatAlpha,
    PixelFormatRgb565,
    PixelFormatRgb24,
    PixelFormatArgb32,
    PixelFormatUnknown = 0xFFFFFFFF,
};

// TextureCubeSide
enum TextureCubeSide
{
    TextureCubeSidePosX,
    TextureCubeSideNegX,
    TextureCubeSidePosY,
    TextureCubeSideNegY,
    TextureCubeSidePosZ,
    TextureCubeSideNegZ,
    TextureCubeSideUnknown = 0xFFFFFFFF,
};

// BlendMode
enum BlendMode
{
    BlendAlpha,
    BlendAdd,
    BlendPMAlpha,
    BlendPMAdd,
    BlendScreen,
    BlendMultiply,
    BlendUnknown = 0xFFFFFFFF,
};

}

//------------------------------------------------------------------------------------------------
// Modules
//------------------------------------------------------------------------------------------------

// Glm
#include <glm/glm.hpp>
#include <glm/ext.hpp>

// System
#include "system/Timer.h"
#include "system/Random.h"
#include "system/Color.h"
#include "system/DataType.h"
#include "system/App.h"

// Graphics
#include "graphics/Renderer.h"
#include "graphics/Image.h"
#include "graphics/Texture.h"
#include "graphics/TextureCube.h"
#include "graphics/Fbo.h"
#include "graphics/Vbo.h"
#include "graphics/Ibo.h"
#include "graphics/Shader.h"
#include "graphics/Uniform.h"
#include "graphics/Attrib.h"
//#include "graphics/Material.h"

// Camera
#include "camera/Camera.h"
#include "camera/CameraPerspective.h"
#include "camera/CameraOrthogonal.h"

// Target iOS
#ifdef DRY_TARGET_IOS
    #include "ios/dry.h"
#endif

#endif
