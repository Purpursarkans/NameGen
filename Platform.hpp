#ifndef PLATFORM_HPP
#define PLATFORM_HPP

    #define PLATFORM "UNKNOWN"
    #ifdef _WIN64
            #define PLATFORM "WINDOWS"
            #define PWIN 1
    #elif __linux__
            #define PLATFORM "LINUX"
            #define PLIN 1
    #endif

#endif