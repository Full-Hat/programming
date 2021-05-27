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

    static unsigned long long generateUniqueNumber(std::vector<unsigned long long> numbers)
    {
        if(numbers.size() == 0)
            return rand() % 1000000000;

        unsigned long long number = numbers[0];
        while(std::find(numbers.begin(), numbers.end(), number) != numbers.end())
        {
            number = rand() % 1000000000;
        }

        return number;
    }
};

#endif // UTILS_H
