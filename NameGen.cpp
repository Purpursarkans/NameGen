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

    char* group[] = {"a", "q w e"};
    
    std::cout << sizeof(*mask) << std::endl;

    std::cout << mask[0] << " " << mask[1] << " " << mask[2] << std::endl;
    std::cout << "NameGen" << std::endl;
    std::cout << PLATFORM << std::endl;
    pause();
}
