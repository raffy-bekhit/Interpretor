#ifndef FLOATSTACK_H_
#define FLOATSTACK_H_
#define TYPE double
#define SIZE 100
#include "linkedlist.h"

typedef struct float_stack
{
    int top;
    TYPE items[SIZE];
} float_stack;


void initF(float_stack*);
void pushF(float_stack*,TYPE);
TYPE popF(float_stack*);
int isEmptyF(float_stack*);
int isFullF(float_stack*);
TYPE TopF(float_stack*);
TYPE evaluate(linkedlist*ll,char*);


#endif // float_stack_H_
