#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>  
#include <string.h>
#include <malloc.h>

#define bool int
#define true 1
#define false 0 

bool isAnagrams(const char* str1, const char* str2)
{
    if(strlen(str1) != strlen(str2)) 
    {
        return false;
    }
    
    int len = strlen(str1);
    char* temp = (char*)malloc(sizeof(char) * len);

    strcpy(temp, str1);

    bool found = false;
    int i = 0, ii = 0;
    for(i = 0; i < len; ++i)
    {
        found = false;
        for(ii = 0; ii < len; ++ii)
        {
            if(str2[i] == temp[ii] || str2[i] + ('a' - 'A') == temp[ii] || str2[i] - ('a' - 'A') == temp[ii])
            {
                found = true;
                temp[ii] = '\0';
                break;
            }
        }
        if(found == false)
        {
            return false;
        }
    }

    return true;
}

#endif