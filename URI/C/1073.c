#include<stdio.h>
#include<stdlib.h>

int N,quad,i;

int main()
{
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    {
        if(i%2==0)
        {
            quad=i*i;
            printf("%d^2 = %d\n",i,quad);
        }
    }
    return 0;
}
