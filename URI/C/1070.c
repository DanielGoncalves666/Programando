#include<stdio.h>
#include<stdlib.h>

int X,i;

int main()
{
    scanf("%d",&X);
    for(i=1;i<=6;)
    {
        if(X%2==1)
        {
            printf("%d\n",X);
            i++;
        }
        X++;
    }
    return 0;
}
