#include <iostream>
#include <fstream>
#include <cassert>

#include "interface.h"

int main()
{
    FILE* out = fopen("test_output", "w");
    FILE* in = fopen("test_input", "r");
    stdin = in;
    stdout = out;

    startApp("test");
    fclose(out);
    fclose(in);

    std::ifstream fincto("correct_test_output");
    std::ifstream finto("test_output");
    try
    {
        std::string temp1, temp2;
        while(std::getline(fincto, temp1) && std::getline(finto, temp2))
        {
            //std::cout << temp1 << "|" << temp2 << "\n";
            assert(temp1 == temp2);
        }
    }
    catch(...)
    {
        throw "Files not the same :: wrong program logic";
    }
    
    AccountSet accs;
    std::ifstream fin("test");
    accs.load(fin);
    remove("test");

    return 0;
}
