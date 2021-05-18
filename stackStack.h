#ifndef STACK_STACK_H
#define STACK_STACK_H

#include "stringStack.h"

/*
can hold struct StackStack data in stack form 
This file has the same interface as StackStack, but code "ss" was changes to "st"

methods:
1) push(char *) 
2) pop() 
3) peek() 
4) size() 
5) clear() 
6) init() 
*/

struct StackStackNode;

struct StackStackNode
{
    struct StringStack *data; 
    struct StackStackNode* privious;
};

struct StackStack
{
    struct StackStackNode* last;
}; 

void pushst(struct StackStack *stack, struct StringStack *data);

struct StringStack* popst(struct StackStack *stack);

struct StringStack* peekst(struct StackStack *stack);

int sizest(struct StackStack *stack);

void clearst(struct StackStack *stack);

void initst(struct StackStack *stack);  

#endif