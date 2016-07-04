#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_


typedef struct Node
{
    char var[100];
    double value;
    struct Node * next;
    } Node;

typedef struct
{
    Node *head, *tail;
} linkedlist;

void initialize(linkedlist*);
Node* construct(char*,double );
void addHead(linkedlist*,char*,double );
void addTail(linkedlist*,char*,double);
Node* search(linkedlist*,char*);
double getValue(linkedlist*,char* );
void setValue(linkedlist*,char*,double );
void dispose(linkedlist*);


#endif // LINKEDLIST_H_
