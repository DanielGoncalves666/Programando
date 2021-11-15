#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,num,maior=0,posicao;

    for(i=1;i<=100;i++)
    {
        scanf("%d",&num);
        if(maior<num)
        {
            maior=num;
            posicao=i;
        }
    }
    printf("%d\n",maior);
    printf("%d\n",posicao);

    return 0;
}
