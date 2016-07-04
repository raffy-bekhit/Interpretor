#include <stdio.h>
#include <stdlib.h>
#include "FloatStack.h"
#include "linkedlist.h"

void initF(float_stack*s)
{
    s->top=0;

}
void pushF(float_stack*s,TYPE value)
{
    s->items[s->top]=value;
    s->top++;
}
TYPE popF (float_stack*s)
{
    --s->top;
    return s->items[s->top];
}
int isEmptyF(float_stack*s)
{
    return s->top==0?1:0;
}
int isFullF(float_stack*s)
{
    return s->top==SIZE?1:0;
}

TYPE TopF(float_stack * s )
{
    s->top--;
    int vreturn = s->items[s->top];
    s->top++;
    return vreturn;
}

TYPE evaluate(linkedlist*ll,char*postfix)
{
    float_stack s;
    initF(&s);
    int i;

    for (i=0; i<strlen(postfix); i++)
    {
        char tempString[25]="\0";

        int j=0;

        if(postfix[i]==' '||postfix[i]=='\n') goto endloop;
        if(isalpha(postfix[i]))
        {



            while(isalpha(postfix[i]))
            {
                tempString[j++]=postfix[i++];
            }
            tempString[j++]='\0';

            if(search(ll,tempString))
            {

                pushF(&s,getValue(ll,tempString));
                i--;
            }
            else
            {
                error();
                return -99999;
            }
        }

        else if (isdigit(postfix[i])||postfix[i]=='.')
        {
            while(isdigit(postfix[i])|| postfix[i]=='.')
            {
                tempString[j++]=postfix[i++];
            }

            pushF(&s,atof(tempString));
            i--;
        }
        else
        {
            TYPE a,b;
            if (!isEmptyF(&s)) b=popF(&s);
            else
            {
                error();
                return -99999;
            }
            if (!isEmptyF(&s)) a=popF(&s);
            else
            {
                error();

                return -99999;
            }
            switch(postfix[i])
            {
            case '+':
                pushF(&s,a+b);
                break;
            case '-':
                pushF(&s,a-b);
                break;
            case '*':
                pushF(&s,a*b);
                break;
            case '/':
                pushF(&s,a/b);
                break;
            default:
                error();

                return -99999;
            }
        }
endloop:
        ;
    }
    return popF(&s);
}
