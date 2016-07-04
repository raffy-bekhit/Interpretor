#include "functions.h"
#include <ctype.h>

int error()
{
    printf("error\n");
    return -1;

}
int toInt(double x)
{
    if(x==(int)x) return (int)x;
    else return -99999;

}
double max(double a,double b)
{
    return a>b? a:b ;
}

double min(double a,double b)
{
    return a>b? b:a ;
}

double power(double a,double b)
{
    if(b==0) return 1 ;
    return a*power(a,b-1) ;
}

int checkExp(char*exp)
{

if(!strcmp(exp,"getFile\n"))return 3;
    int eq=0;
    int ch1=0, ch2=0, no1=0,no2=0;
    int i;
    for(i=0; i<strlen(exp); i++)
    {
        if(exp[i]=='=') eq++;
        if(isalpha(exp[i]))
        {
            while(isalpha(exp[i]))i++;
            if(eq==0) ch1++;
            else if(eq==1) ch2++;
            i--;
        }
        if(isdigit(exp[i])&&eq==0) no1++;
        if(isdigit(exp[i])&&eq==1) no2++;
    }
    if(eq==0&&(ch1>0||no1>0)) return 1; //evaluation exp
    if(eq==1&&ch1==1&&no1==0&&(ch2>0||no2>0)) return 2; //declaration exp
    if(eq==0&&ch1==0&&ch2==0&&no1==0&&no2==0) return -2;

    else return -1;

}

char* getVar(char*exp)
{
    int i;
    char var[30];
    int j=0;
    for(i=0; i<strlen(exp); i++)
    {
        if (isalpha(exp[i]))
        {
            while(isalpha(exp[i]))
                var[j++]=exp[i++];
            i--;
            var[j]='\0';
        }

        if(exp[i]=='=')
        {
            strcpy(exp,exp+i+1);
            return var;
        }
    }

}

void remBlank(char*exp)
{
    char temp[100]="\0";
    int i;
    int j=0;
    for(i=0; i<strlen(exp); i++)
    {
        if(exp[i]!=' '&&exp[i]!='\n')
            temp[j++]=exp[i];

    }
    temp[j]='\0';
    strcpy(exp,temp);
}



