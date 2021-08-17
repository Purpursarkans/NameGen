#include <bits/stdc++.h>

#define PLATFORM "UNKNOWN"

#ifdef _WIN64
        #define PLATFORM "WINDOWS"
        #define PWIN 1
#elif __linux__
        #define PLATFORM "LINUX"
        #define PLIN 1
#endif

void pause()
{
    #ifdef PWIN
        system("pause");
    #elif PLIN
        system("read -n1 -r -p \"Press any key to continue...\" key");
    #endif
}

int main()
{
    char* mask[] = {"kakao","kakar","kakakao"};

    char mask1[] = "test";
    
    std::cout << "NameGen" << std::endl;
    std::cout << PLATFORM << std::endl;
    pause();
}
