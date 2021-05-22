#include <stdio.h>
#include <assert.h>

#include "calculator.h"

#define false 0
#define true 1 

int main()
{  
    assert(checkExpr("11") == true);
    assert(checkExpr("+11") == false);
    assert(checkExpr("1+1+") == false);
    assert(checkExpr("+1+1") == false);

    assert(checkExpr("1+1") == true);
    assert(checkExpr("1234*123+12-1/0") == true);
    assert(checkExpr("1+1") == true);
    assert(checkExpr("1-1") == true);
    assert(checkExpr("1*1") == true);
    assert(checkExpr("1/1") == true);


    assert(calculateExptr("1+1") == 2);
    assert(calculateExptr("1/15") == 0);
    assert(calculateExptr("15*3") == 45);
    assert(calculateExptr("100/25") == 4);
    assert(calculateExptr("200-100") == 100); 
    assert(calculateExptr("12000*100/10+15-3") == 120012); 

    puts("All ok :D");
    return 0;
}
