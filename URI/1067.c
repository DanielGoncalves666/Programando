#include<stdio.h>
#include<stdlib.h>

int X,i;

int main()
{
    scanf("%d",&X);
    for(i=1;i<=X;i++)
    {
        if(i%2==1)
        {
            printf("%d\n",i);
        }
    }

    return 0;
}
