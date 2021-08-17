#include "Head.hpp"

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
    
    std::cout << mask[0] << " " << mask[1] << " " << mask[2] << std::endl;
    std::cout << "NameGen" << std::endl;
    std::cout << "Platform is - " << PLATFORM << std::endl;
    pause();
}
