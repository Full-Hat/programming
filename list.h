#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct Node
{ 
    struct Node* next;
    void* data;
};

struct List
{
    struct Node* first;
};

void init(struct List* list)
{
    list->first = NULL;
}

void push_back(struct List* list, void* data, int size)
{
    if(list->first == NULL)
    { 
        list->first = (struct Node*)malloc(sizeof(struct Node*) + size);
        list->first->data = data;
        list->first->next = NULL;
    }
    else
    {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*) + size);
        newNode->data = data;  
        newNode->next = list->first;
        list->first = newNode; 
    } 
}

void print(struct List* list, char* type)
{
    struct Node* temp = list->first;
    while(temp != NULL)
    {
        if(strcmp(type, "%s") == 0) 
        { 
            printf(type, *((char**)temp->data));
        }
        temp = temp->next;
    }
}
