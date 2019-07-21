#include<stdio.h>
#include<stdlib.h>

int main()
{
    int vet8[10];
    int i;

    printf("Multiplos de 2\n");
    for(i=0;i<10;i++)
    {
         scanf("%d",& vet8[i]);
         if(vet8[i]%2==0)
             printf("%d\n",vet8[i]);
    }

    printf("Multiplos de 5\n");
    for(i=0;i<10;i++)
    {
        if(vet8[i]%5==0)
            printf("%d\n", vet8[i]);
    }

    printf("Multiplos de 2 e de 5\n");
    for(i=0;i<10;i++)
    {
        if(vet8[i]%2==0 && vet8[i]%5==0)
            printf("%d\n",vet8[i]);
    }


    return 0;
}
