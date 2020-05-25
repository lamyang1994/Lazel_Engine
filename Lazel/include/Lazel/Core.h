#pragma once

// macOS Platform
#ifdef __APPLE__ 
    #define LAZEL_API
    #define GL_SILENCE_DEPRECATION
#endif

// Windows Platform
#ifdef _WIN32 
    #ifdef LZ_BUILD_DLL
        #define LAZEL_API __declspec(dllexport) 
    #else
        #define LAZEL_API __declspec(dllimport) 
    #endif
#endif

#ifdef LZ_ENABLE_ASSERT
    #define LZ_ASSERT(x, ...) { if (!x) { LZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); assert(x); } }
    #define LZ_CORE_ASSERT(x, ...) { if (!x) { LZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); assert(x); } }
#else
    #define LZ_ASSERT(x, ...) 
    #define LZ_CORE_ASSERT(x, ...) 
#endif

#define BIT(x) 1 << x