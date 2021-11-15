#include<stdio.h>
#include<stdlib.h>

int N,i;

int main()
{
    scanf("%d",&N);
    for(i=1;i<=10;i++)
    {
        printf("%d x %d = %d\n",i,N,i*N);
    }

    return 0;
}
