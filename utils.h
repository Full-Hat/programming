#ifndef UTILS_H
#define UTILS_H

#include <random>
#include <algorithm>

class Utils
{
public:
    static bool isDigit(char ch)
    {
        return ch >= '0' && ch <= '9';
    }

    static bool isNumber(std::string number)
    {
        for(char ch : number)
        {
            if(!isDigit(ch))
                return false;
        }
        return true;
    }
};

#endif // UTILS_H
