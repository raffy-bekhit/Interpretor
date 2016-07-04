#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "linkedlist.h"

void init(stack*s)
{
    s->top=0;

}
void push(stack*s,TYPE value)
{
    s->items[s->top]=value;
    s->top++;
}
TYPE pop (stack*s)
{
    --s->top;
    return s->items[s->top];
}
int isEmpty(stack*s)
{
    return s->top==0?1:0;
}
int isFull(stack*s)
{
    return s->top==SIZE?1:0;
}

TYPE Top(stack * s )
{
    s->top--;
    int vreturn = s->items[s->top];
    s->top++;
    return vreturn;
}
int priority(char c)
{
    if(c=='(')return 0;
    else if(c=='+'||c=='-') return 1;
    else if(c=='*'||c=='/'||c=='%') return 2;
    else return 3;

}
int toPostfix(linkedlist*ll,char* infix, char*postfix)
{
    stack s;
    init(&s);
    char ch1,ch2;
    char *pt=infix;
    int i=0;

    while(ch1=*pt++)
    {
        char tempStr[30]="\0";
        int j = 0;
        if(ch1==' '||ch1=='\n'||ch1=='\0')goto endloop;
        if(ch1=='(')
        {
            postfix[i++]=' ';
            push(&s,ch1);
        }
        else if(isalpha(ch1))
        {

                postfix[i++]=ch1;



            }
            else if(isdigit(ch1) || ch1=='.'  )
            {
                postfix[i++]=ch1;
            }

            else

                if(ch1==')')
                {
                    while(!isEmpty(&s))
                    {
                        ch2=pop(&s);
                        if(ch2=='(')break;
                        postfix[i++]=ch2;
                    }

                }
                else
                {
                    while((priority(Top(&s))>=priority(ch1))&&!isEmpty(&s))
                    {
                        postfix[i]=pop(&s);
                        i++;
                    }

                    postfix[i++]=' ';
                    push(&s,ch1);
                }

endloop:
            ;
        }
        while(!isEmpty(&s))
        {
            postfix[i]=pop(&s);
            i++;
        }
        postfix[i]='\0';
        return 1;
    }

