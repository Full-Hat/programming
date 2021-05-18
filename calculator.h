#ifndef CALC
#define CALC 

#define true 1
#define false 0
#define bool int

#include <string.h>

bool isOperator(const char op);

bool isDigit(const char symb);

bool checkExpr(const char expr[]);

#endif 