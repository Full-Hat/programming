#ifndef STRING_STACK_H
#define STRING_STACK_H

/*
can hold char* data in stack form 

methods:
1) push(char *) V
2) pop() V
3) peek() V
4) size() V
5) clear() V
6) init() V
*/  

struct StackNode;

struct StackNode
{
    char* data; 
    struct StackNode* privious;
};

struct StringStack
{
    struct StackNode* last;
}; 

void pushss(struct StringStack *stack, char* data);

char* popss(struct StringStack *stack);

char* peekss(struct StringStack *stack);

int sizess(struct StringStack *stack);

void clearss(struct StringStack *stack);

void initss(struct StringStack *stack); 

#endif