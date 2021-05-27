#include "menu.h"

Menu::Menu()
{

}

void Menu::print()
{
    std::cout << "\n\n" << std::string(10, '~') << " menu " << std::string(10, '~') << "\n";
    for(int i = 0; i < fields.size(); ++i)
    {
        std::cout << "#" << i << " " << fields[i] << "\n";
    }
}

int Menu::execute()
{
    std::cout << "Your choose: ";
    std::string inputChoose;
    std::getline(std::cin, inputChoose);

    if(!Utils::isNumber(inputChoose))
    {
        return -1;
    }

    int number;
    try
    {
        number = std::stoi(inputChoose);
    }
    catch(...)
    {
        return -1;
    }

    if(number > fields.size() - 1 || number < 0)
    {
        return -1;
    }

    std::cout << "\n";
    return number;
}
