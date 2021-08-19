#ifndef PLATFORM_HPP
#define PLATFORM_HPP

    #include "Head.hpp"

    #ifdef _WIN64
        #define PLATFORM "WINDOWS"
        #define PWIN 1
    #elif __linux__
        #define PLATFORM "LINUX"
        #define PLIN 1
    #else
        #define PLATFORM "UNKNOWN"
    #endif

    void pause()
    {
        #ifdef PWIN
            system("pause");
        #elif PLIN
            system("read -n1 -r -p \"Press any key to continue...\" key; echo -e \"\n\"");
        #endif
    }

#endif