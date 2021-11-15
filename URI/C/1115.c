#include<stdio.h>
#include<stdlib.h>

int main()
{
    int X,Y;
    for(;X!=0 && Y!=0;)
    {
        scanf("%d",&X);
        scanf("%d",&Y);
        if(X>0 && Y>0)
            printf("primeiro\n");
        if(X<0 && Y>0)
            printf("segundo\n");
        if(X<0 && Y<0)
            printf("terceiro\n");
        if(X>0 && Y<0)
            printf("quarto\n");
    }

    return 0;
}
