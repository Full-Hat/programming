#include "stringStack.h"

#include <stdio.h>
#include <malloc.h>
#include <string.h> 

void pushss(struct StringStack *stack, char* data)
{ 
    if(stack->last == NULL)
    {  
        stack->last = (struct StackNode*)malloc(sizeof(struct StackNode)); 
        stack->last->data = (char*)malloc(sizeof(char*) * (strlen(data) + 2));
        strcpy(stack->last->data, data); 

        stack->last->privious = NULL;
    } 
    else
    {
        struct StackNode* newEl = (struct StackNode*)malloc(sizeof(struct StackNode));
        newEl->data = (char*)malloc(sizeof(char*) * (strlen(data) + 2));
        strcpy(newEl->data, data);
        newEl->privious = stack->last;
        stack->last = newEl;
    } 
}

char* popss(struct StringStack *stack)
{ 
    char* data = stack->last->data; 

    struct StackNode *temp = stack->last->privious;

    free(stack->last);

    stack->last = temp;

    return data;
} 

char* peekss(struct StringStack *stack)
{ 
    return stack->last->data;
}

int sizess(struct StringStack *stack)
{
    struct StackNode* temp = stack->last; 

    int i = 0;
    while(temp != NULL)
    {  
        ++i;
        temp = temp->privious;
    }

    return i;
}

void clearss(struct StringStack *stack)
{
    if(stack->last == NULL)
    {
        return;
    }

    struct StackNode* temp = stack->last->privious; 

    while(stack->last != NULL)
    {   
        if(stack->last->data != NULL)
        {
            free(stack->last->data); 
        }
        free(stack->last);

        stack->last = temp; 

        if(temp == NULL)
        {
            return;
        }

        temp = temp->privious;
    }
}

void initss(struct StringStack *stack)
{
    stack->last = NULL;
}