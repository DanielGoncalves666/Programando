#include<stdio.h>
#include<stdlib.h>

int main()
{
    int vet[15];
    int i;

    for(i=0;i<15;i++)
        scanf("%d",&vet[i]);
    for(i=0;i<15;i++)
    {
        if(vet[i]%2==0)
            printf("%d\n",vet[i]);
    }

    return 0;
}
