#include<stdio.h>
#include<stdlib.h>

int main()
{
    int vet[15];
    int i, cont1=0;

    for(i=0;i<15;i++)
    {
        scanf("%d",& vet[i]);
        if(vet[i]==10 || vet[i]==20)
        {
            cont1++;
        }
    }

    printf("%d\n", cont1);

    return 0;
}
