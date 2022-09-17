#include<stdio.h>
#include<stdlib.h>

int N[10];
int i,num;

int main()
{
    scanf("%d",&num);
    for(i=0;i<10;i++)
    {
        if(i==0)
            N[i]=num;
        else
            N[i]=N[i-1]*2;
        printf("N[%d] = %d\n",i,N[i]);
    }

    return 0;
}
