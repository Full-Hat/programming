#ifndef MENU_H
#define MENU_H

#include "utils.h"

#include <iostream>
#include <string>
#include <vector>

class Menu
{
public:
    std::vector<std::string> fields;

    void print();
    int execute();

    Menu();
};

#endif // MENU_H
