#include "Head.hpp"

#define cinclear std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')

int main()
{
    std::srand(time(NULL));

    std::cout << "Enter num of random name: ";
    int numOfRandomName;
    std::cin >> numOfRandomName;

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

    for (std::map<char, std::vector<std::string>>::iterator it = groupsVector.begin(); it != groupsVector.end(); it++)
    {
        std::reverse(it->second.begin(), it->second.end());
    }

    std::cout << "-------------" << std:: endl;

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
    std::cout << "-------------" << std:: endl;
    std::cout << "Random name:" << std:: endl;
    //------------------------------------------            Кол-во рандомных имен
    for(int i = 0; i < numOfRandomName; i++)
    {
        //------------------------------------------            Выбираем рандомную маску
        int randMask = rand() % masks.size();
        std::string randVecMask = masks[randMask];
        //------------------------------------------

        std::string result = randVecMask;
        
        for(int i = 0; i < result.length();)
        {
            char temp = result[i];
            std::map<char, std::vector<std::string>>::iterator cc = groupsVector.find(temp);
            int razmer = 0;

            for(std::map<char, std::vector<std::string>>::iterator it = groupsVector.begin(); it != groupsVector.end(); it++)
            {
                if(temp == it->first)
                {
                    razmer = cc->second.size();
                }
            }

            int randChar = 0;

            if(razmer > 0) 
            {
                randChar = rand() % razmer;
                std::string tempString = cc->second[randChar];
                if(i == 0)
                {
                    char TC = (char)std::toupper(tempString[0]);
                    std::string TCS(1, TC);
                    //tempString = (char)std::toupper(tempString[0]);

                    tempString.erase(0, 1);
                    tempString.insert(0, TCS);
                }
                result.erase(i, 1);
                result.insert(i, tempString);
                i+= tempString.size();
            }
            else
            {
                i++;
            }
            
        }


        std::cout << result << std::endl;
    }

    pause();
}
