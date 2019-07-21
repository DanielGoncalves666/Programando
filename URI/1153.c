#include<stdio.h>
#include<stdlib.h>

int main()
{
    int N,fatorial=1;

    scanf("%d",&N);
    for(N;N>0;N--)
    {
        fatorial=fatorial*N;
    }
    printf("%d\n",fatorial);

    return 0;
}
