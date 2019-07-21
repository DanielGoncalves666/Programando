#include<stdlib.h>
#include<stdio.h>

int main()
{
    int vet1[10],vet2[10];
    int i,mult;

    for(i=0;i<10;i++)
    {
        scanf("%d",&vet1[i]);
    }
    for(i=0;i<10;i++)
    {
        scanf("%d",&vet2[i]);
    }
    for(i=0;i<10;i++)
    {
        mult=vet1[i]*vet2[i];
        printf("%d\n",mult);
    }


    return 0;
}
