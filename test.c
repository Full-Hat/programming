#include "test.h"

int main()
{
    assert(checkExpr("1+2/3*4-0")); 
    assert(!checkExpr("1++b"));

    puts("Test passed, all ok");
    return 0;
}