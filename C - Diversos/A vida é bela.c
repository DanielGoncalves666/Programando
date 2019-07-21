#include<stdio.h>
#include<stdlib.h>

int p,i,qtd=0;

int main()
{
    for(p=0;p<15;p++)
    {
        scanf("%d",&i);
        if(i>20)
            qtd++;
    }
    printf("%d",qtd);

    return 0;
}

