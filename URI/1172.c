#include<stdio.h>
#include<stdlib.h>

int X[10],i;

int main()
{
    for(i=0;i<10;i++)
    {
        scanf("%d",&X[i]);
    }
    for(i=0;i<10;i++)
    {
        if(X[i]==0 || X[i]<0)
        {
            X[i]=1;
        }
        printf("X[%d] = %d\n",i,X[i]);
    }

    return 0;
}
