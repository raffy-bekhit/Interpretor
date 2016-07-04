#ifndef STACK_H_
#define STACK_H_
#define TYPE char
#define SIZE 100
#include "linkedlist.h"

typedef struct
{
    int top;
    TYPE items[SIZE];
} stack;


void init(stack*);
void push(stack*,TYPE);
TYPE pop(stack*);
int isEmpty(stack*);
int isFull(stack*);
TYPE Top(stack*);
int toPostfix(linkedlist*,char*, char*);


#endif // STACK_H_
