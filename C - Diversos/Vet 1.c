#include<stdio.h>
#include<stdlib.h>

int main()
{
    int vet[20];
    int i;

    for(i=0;i<20;i++)
    {
        scanf("%d",&vet[i]);
    }
    for(i=19;i>=0;i--)
    {
        printf("%d\n",vet[i]);
    }
    return 0;

}
