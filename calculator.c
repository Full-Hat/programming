#include "calculator.h" 
#include <malloc.h>

int pow_(int x, int i) 
{ 
    if(i == 0)
    {
        return 1;
    }

    int result = x;

    for(int ii = 0; ii < i - 1; ++ii)
    {
        result *= x;
    }

    return result;
}

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
    if (isOperator(expr[strlen(expr) - 1]) || isOperator(expr[0]))
    {
        return false;
    }
    for (int i = 0; i < strlen(expr); i++)
    { 
        if (!(isDigit(expr[i]) || expr[i] == '.' || isOperator(expr[i])))
        {
            return false;
        }
        if ((expr[i] == '.' && i == 0) || (expr[i] == '.' && i == strlen(expr) - 1))
        {
            return false;
        }
        if ((expr[i] == '.' && !isDigit(expr[i - 1])) || (expr[i] == '.' && !isDigit(expr[i + 1])))
        {
            return false;
        }
        if (isOperator(expr[i]) && (!isDigit(expr[i - 1]) || !isDigit(expr[i + 1])))
        {
            return false;
        }
    } 

    return true;
} 

char* makeEasy(char exptr[]) 
{
    int l;
    int r;
    char* data = (char*)malloc(sizeof(char) * (strlen(exptr) + 1));
    int localResult;
    bool found = false;
    for(int i = 0; i < strlen(exptr); ++i)
    {
        if(exptr[i] == '*' || exptr[i] == '/')
        { 
            l = 0;
            int lV = 0;
            int ii;
            for(ii = i - 1; ii >=0 && !isOperator(exptr[ii]); --ii, ++l)
            { 
                lV += (exptr[ii] - '0') * pow_(10, l);
            } 
            l = ii + 1;

            r = 0;
            int rV = 0; 
            for(ii = i + 1; ii < strlen(exptr) && !isOperator(exptr[ii]); ++ii, ++r)
            { 
                rV = (exptr[ii] - '0') + rV * 10;
            }
            r = ii;

            if(exptr[i] == '*')
            {   
                localResult = lV * rV;
            } 
            else if(exptr[i] == '/')
            {
                localResult = lV / rV;
            }
            
            found = true;
            break;
        }
    }  

    if(!found)
    { 
        for(int i = 0; i < strlen(exptr); ++i)
        {
            if(exptr[i] == '+' || exptr[i] == '-')
            { 
                l = 0;
                int lV = 0;
                int ii;
                for(ii = i - 1; ii >=0 && !isOperator(exptr[ii]); --ii, ++l)
                { 
                    lV += (exptr[ii] - '0') * pow_(10, l);
                } 
                l = ii + 1;

                r = 0;
                int rV = 0; 
                for(ii = i + 1; ii < strlen(exptr) && !isOperator(exptr[ii]); ++ii, r++)
                { 
                    rV = (exptr[ii] - '0') + rV * 10;
                }
                r = ii;

                if(exptr[i] == '+')
                {   
                    localResult = lV + rV;
                } 
                else if(exptr[i] == '-')
                {
                    localResult = lV - rV;
                }
                
                break;
            }
        }  
    }

    int i = 0;
    for(i = 0; i < l; ++i)
    {  
        data[i] = exptr[i];
    }
    char numberBuff[100];
    sprintf(numberBuff, "%d", localResult);
    for(int ii = 0; ii < strlen(numberBuff); ++ii)
    {
        data[i++] = numberBuff[ii];
    }
    for(int ii = r; ii < exptr[i] != '\0'; ++ii)
    { 
        data[i++] = exptr[ii];
    }

    return data;
}

bool isNumber(char number[])
{
    for(int i = 0; i < strlen(number); ++i)
    { 
        if(!isDigit(number[i]))
        {
            return false;
        }
    }
    return true;
}

int calculateExptr(char exptr[])
{
    while(!isNumber(exptr))
    {
        exptr = makeEasy(exptr);
    }

    int result = 0;
    for(int i = 0; i < strlen(exptr); ++i)
    { 
        result = (exptr[i] - '0') + result * 10;
    }

    return result;
}
