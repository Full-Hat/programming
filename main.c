#include <stdio.h> 
#include <string.h>

#include "calculator.h"

int main()
{   
    puts("Enter your math expression: "); 
    char data[50];
    scanf("%s", data);
    if(checkExpr(data))
    { 
        printf("Result: %d\n", calculateExptr(data));
    }
    else
    {
        puts("Invalid expression\n");
    } 

    return 0;
}
