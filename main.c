#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "FloatStack.h"
#include "functions.h"
#include "linkedlist.h"


int main()
{
    linkedlist ll;
    initialize(&ll);

    while(1)
    {

        double a, b;

        int flag=0;
        char post[100]="\0";
        printf(">");

        char exp[100]="\0";
        fgets(exp,100,stdin);



        if(checkExp(exp)==3)
        {

            char filename[20],tempStr2[20];
            printf("Enter file name.\n");
            scanf("%s",filename);
            FILE*fp;
            fp=fopen(filename,"r");

            if(fp!=NULL)
            {
                while(!feof(fp))
                {
                    fscanf(fp,"%s",tempStr2);




            char variable[30]="\0";
            strcpy(variable,getVar(tempStr2));

            flag =toPostfix(&ll,tempStr2,post);

            double value = evaluate(&ll,post);

            if(flag!=-1&&value!=-99999)
            {

                setValue(&ll,variable,value);


                }
            }

        printf("Got your variables.\n");} else error();}
        if(checkExp(exp)==-2) goto endloop;
        if(checkExp(exp)==0)return 0;
        if(checkExp(exp)==-1)
        {
            error();
            goto endloop;
        }


        if(checkExp(exp)==1)

        {

            flag = toPostfix(&ll,exp,post);


            double x = evaluate(&ll,post);

            if(flag!=-1&&x!=-99999)
            {

                if(toInt(x)!=-99999)
                    printf("%d\n",toInt(x));
                else  printf("%lf\n",x);
            }
        }


        if(checkExp(exp)==2)
        {


            char variable[30];
            strcpy(variable,getVar(exp));

            flag =toPostfix(&ll,exp,post);

            double value = evaluate(&ll,post);

            if(flag!=-1&&value!=-99999)
            {

                setValue(&ll,variable,value);
                if(toInt(value)!=-99999)
                    printf("%d\n",toInt(value));
                else  printf("%lf\n",value);
            }
        }
endloop:
        ;

    }
    dispose(&ll);
    return 0;
}
