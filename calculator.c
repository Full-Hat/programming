#include "calculator.h"

bool isOperator(const char op)
{
    switch(op)
    {
        case '*':
        case '/':
        case '+':
        case '-':
        return true;
        default:
        return false;
    }
}

bool isDigit(const char symb)
{
    return (symb >= '0') && (symb <= '9');
}

bool checkExpr(const char expr[])
{
    if (strlen(expr) < 1)
    {
        return false;
    }
    if (isOperator(expr[strlen(expr) - 1]) || isOperator(expr[0]) || expr[0] == ')' || expr[strlen(expr) - 1] == '(')
    {
        return false;
    }
    for (int i = 0; i < strlen(expr); i++)
    {
        if (i != strlen(expr) - 1)
        {
            if (expr[i] == ')' && expr[i + 1] == '(')
            {
                return false;
            }
            if (expr[i] == '(' && expr[i + 1] == ')')
            {
                return false;
            }
        }
        if (!(isDigit(expr[i]) || expr[i] == '.' || expr[i] == '(' || expr[i] == ')' || isOperator(expr[i])))
        {
            return false;
        }
        if (((expr[i] == '.' || expr[i] == ')') && i == 0) || ((expr[i] == '.' || expr[i] == '(') && i == strlen(expr) - 1))
        {
            return false;
        }
        if ((expr[i] == '.' && !isDigit(expr[i - 1])) || (expr[i] == '.' && !isDigit(expr[i + 1])))
        {
            return false;
        }
        if (isOperator(expr[i]) && (!(isDigit(expr[i - 1]) || expr[i - 1] == ')') || !(isDigit(expr[i + 1]) || expr[i + 1] == '(')))
        {
            return false;
        }
    }
    int bracketsCounter = 0;
    for (int i = 0; i < strlen(expr); i++)
    {
        if (expr[i] == '(')
        {
            bracketsCounter++;
        }
        else if(expr[i] == ')')
        {
            bracketsCounter--;
        }
    }
    if (bracketsCounter != 0)
    {
        return false;
    }

    return true;
}