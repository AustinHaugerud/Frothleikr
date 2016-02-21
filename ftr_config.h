#ifndef ftr_config_h
#define ftr_config_h

#if defined(_WIN32) || defined(__WIN32__)

    #if defined(FTR_EXPORT)
        #define FTR_API __declspec(dllexport)
    #else
        #define FTR_API __declspec(dllimport)
    #endif

#elif defined(linux) || defined(__linux)
    #define FTR_API
#endif

#define FTR_VERSION_MAJOR 1
#define FTR_VERSION_MINOR 0
#define FTR_VERSION_PATCH 0

#endif

