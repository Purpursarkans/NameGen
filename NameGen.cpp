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

    

    std::map<char, std::vector<std::string>> groupsVector;

    for (std::map<char, std::string>::iterator it = groups.begin(); it != groups.end(); it++)
    {
        char tempChar = it->first;
        std::vector<std::string> tempVector;
        std::string tempString;

        tempString = it->second;
        for(;!tempString.empty();)
        {
            std::string str = tempString.substr(tempString.find_last_of(' ') + 1);
            tempVector.push_back(tempString.substr(tempString.find_last_of(' ') + 1));
            if(tempString == str)
            {
                tempString = tempString.erase(tempString.size()-str.size());
            }
            else
            {
                tempString = tempString.erase(tempString.size()-str.size()-1);
            }
        }
        

        groupsVector.insert(std::pair<char, std::vector<std::string>>(tempChar, tempVector));
    }

    std::cout << "---------" << std::endl;


    for (std::map<char, std::vector<std::string>>::iterator it = groupsVector.begin(); it != groupsVector.end(); it++)
    {
        std::reverse(it->second.begin(), it->second.end());
    }


    std::cout << "Group(s) is: " << std:: endl;

    for(const std::pair<char, std::vector<std::string>> &it: groupsVector)
    {
        std::cout << it.first << ": ";
        for(const std::string &iit: it.second)
        {
            std::cout << iit << "-";
        }       
        std::cout << std::endl;
    }

    std::cout << "Mask(s) is: " << std:: endl;

    for(const std::string &it: masks)
    {
        std::cout << ">>> " << it << std::endl;
    }

    std::cout << "";

    for(const std::string &it: masks)
    {
        std::string temp = it;
    }


    //std::cout << "Platform is - " << PLATFORM << std::endl;
    pause();
}
