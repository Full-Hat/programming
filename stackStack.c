#include "stackStack.h"

#include <stdio.h>
#include <malloc.h>
#include <string.h> 

void pushst(struct StackStack *stack, struct StringStack* data)
{ 
    if(stack->last == NULL)
    {  
        stack->last = (struct StackStackNode*)malloc(sizeof(struct StackStackNode));   
        stack->last->data = data;

        stack->last->privious = NULL;
    } 
    else
    {
        struct StackStackNode* newEl = (struct StackStackNode*)malloc(sizeof(struct StackStackNode));  
        newEl->data = data;
        newEl->privious = stack->last;
        stack->last = newEl;
    }
}

struct StringStack* popst(struct StackStack *stack)
{ 
    struct StringStack* data = stack->last->data; 

    struct StackStackNode *temp = stack->last->privious;

    free(stack->last);

    stack->last = temp;

    return data;
} 

struct StringStack* peekst(struct StackStack *stack)
{ 
    return stack->last->data;
}

int sizest(struct StackStack *stack)
{
    struct StackStackNode* temp = stack->last; 

    int i = 0;
    while(temp != NULL)
    {  
        ++i;
        temp = temp->privious;
    }

    return i;
}

void clearst(struct StackStack *stack)
{
    if(stack->last == NULL)
    {
        return;
    }

    struct StackStackNode* temp = stack->last->privious; 

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

void initst(struct StackStack *stack)
{
    stack->last = NULL;
}