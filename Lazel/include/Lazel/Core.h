#pragma once

// macOS Platform
#ifdef __APPLE__ 
    #define LAZEL_API
#endif

// Windows Platform
#ifdef _WIN32 
    #ifdef LZ_BUILD_DLL
        #define LAZEL_API __declspec(dllexport) 
    #else
        #define LAZEL_API __declspec(dllimport) 
    #endif
#endif