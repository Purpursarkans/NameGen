#include "Head.hpp"

#define version "ver 1.0"

#define cinclear std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')

int main()
{
    std::cout << "NameGen " << version << std::endl;

    std::map <char, std::string> groups;

    int numGroups = 0;
    std::cout << "input num of groups: ";
    std::cin >> numGroups;

    for(int i = 0; i < numGroups; i++)
    {
        char tempChar;
        std::string tempString;

        std::cout << "enter char group: ";
        std::cin >> tempChar;
        cinclear;

        std::cout << "enter chars you want to replace (through a space): ";
        std::getline(std::cin, tempString);

        groups.insert(std::pair<char,std::string>(tempChar, tempString));
    }

    std::cout << "Groups is: " << std:: endl;

    for (std::map<char, std::string>::iterator it = groups.begin(); it != groups.end(); it++)///вывод на экран
    {
        std::cout << ">>> " << it->first << ": " << it->second << std::endl;
    }

    int numMask = 0;
    std::cout << "input num of mask: ";
    std::cin >> numMask;
    cinclear;

    std::vector<std::string> masks;

    for(int i = 0; i < numMask; i++)
    {
        std::string tempString;
        
        std::cout << "enter mask: ";
        std::getline(std::cin, tempString);
        masks.push_back(tempString);
    }

    std::cout << "Masks is: " << std:: endl;

    for(auto const &it: masks)
    {
        std::cout << ">>> " << it << std::endl;
    }


    


    std::cout << "Platform is - " << PLATFORM << std::endl;
    pause();
}
