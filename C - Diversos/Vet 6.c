#include<stdio.h>
#include<stdlib.h>

int main()
{
    int vet[20];
    int i,cont=0;

    for(i=0;i<20;i++)
    {
        scanf("%d",& vet[i]);
        if(vet[i]%2==0)
           cont++;

    }
    printf("%d",cont);


    return 0;
}
