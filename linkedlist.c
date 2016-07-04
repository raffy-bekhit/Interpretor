#include <stdlib.h>
#include "linkedlist.h"


void initialize(linkedlist*ll)
{
    ll->head=NULL;
    ll->tail=NULL;
}

Node* construct(char* var,double value)
{
    Node*n=(Node*)malloc(sizeof(Node));
    strcpy(n->var,var);
    n->value=value;
    n->next=NULL;
    return n;
}
void addHead(linkedlist*ll,char* var,double value)
{
    Node*n=construct(var,value);
    n->next=ll->head;
    ll->head=n;
    if(!ll->tail)ll->tail=n;

}
void addTail(linkedlist*ll,char* var,double value)
{
    Node*tail = ll->tail;
    Node*n=construct(var,value);
    ll->tail=n;
    if(tail)tail->next=n;
    else ll->head=n;
}
Node* search(linkedlist*ll,char* var)
{
    Node * tempNode = ll->head ;
    while(tempNode)
    {
        if(!strcmp(tempNode->var,var)) return tempNode;
        tempNode=tempNode->next;
    }
    return NULL;
}

double getValue(linkedlist*ll,char* var)
{
    Node*tempNode=search(ll,var);
    if(tempNode!=NULL) return tempNode->value;


}

void setValue(linkedlist*ll,char* var,double value)
{
    Node*tempNode=search(ll,var);
    if(tempNode) tempNode->value=value;
    else addHead(ll,var,value);

}
void dispose(linkedlist*ll)
{
    Node*tempnode=ll->head;
    while(tempnode)
    {
        free(tempnode);
        tempnode=tempnode->next;
    }
}
