#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char string[50];
int i,n=0,num;

int main()
{
    gets(string);
    for(i=0;i<50;i++)
    {
        if(string[i]!='\0')
            n++;
    }
    printf("Esse nome tem %d letras.\n",n);

    return 0;
}
