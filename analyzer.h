#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "stackStack.h"
#include "stringStack.h"
#include "utils.h"

struct StringStack** findAnagram(struct StackStack *stack, const char* string)
{ 
    if(stack->last == NULL)
    {
        return NULL;
    }

    struct StackStackNode* temp = stack->last;   

    while(temp != NULL) 
    {   
        if(isAnagrams(peekss(temp->data), string))  
        { 
            return &(temp->data);
        }
        temp = temp->privious;  
    }

    return NULL;
}

void printss(struct StringStack *stack) 
{
    if(stack->last == NULL)
    {
        return;
    }

    struct StackNode* temp = stack->last; 

    while(temp != NULL) 
    {  
        printf("%s", temp->data); 

        temp = temp->privious;
    } 
}

void printst(struct StackStack *stack)
{
    if(stack->last == NULL)
    {
        return;
    }

    struct StackStackNode* temp = stack->last;  

    puts("\n\nIt : \n");
    int i = 0;
    while(temp != NULL)  
    {  
        if(sizess(temp->data) > 1)
        { 
            printf("[%d] \n", i++);
            printss(temp->data); 
        }

        temp = temp->privious;
    } 
}

void readFile(const char* fileName)
{ 
    FILE* file;
    fopen_s(&file, fileName, "r");  

    struct WordsSet* set = NULL;

    char buff[50];

    struct StackStack stack;  
    initst(&stack);

    int i = 0;
    while(fgets(buff, 50, file) != NULL)
    {   

        struct StringStack** strStack = findAnagram(&stack, buff);
        if(strStack == NULL)
        { 
            struct StringStack *newStack = (struct StringStack*)malloc(sizeof(struct StringStack));
            initss(newStack); 
            pushss(newStack, buff);
            pushst(&stack, newStack);
        }
        else
        {  
            pushss(*strStack, buff);
        } 

    }
    
    printst(&stack);
} 