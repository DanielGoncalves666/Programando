#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,num,maior;

    for(i=0;i<17;i++)
    {
        scanf("%d",&num);
        if(i==0)
            maior=num;
        if(num>maior)
            maior=num;
    }
    printf("%d",maior);

    return 0;
}

