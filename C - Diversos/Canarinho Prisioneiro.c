#include<stdio.h>
#include<stdlib.h>

int main()
{
    int num,i=0;
    float soma=0.0,media;
    for(;num!=0;)
    {
        scanf("%d",&num);
        if(num!=0)
        {
            soma=soma+num;
            i++;
            media=soma/i;
        }
    }
    printf("%.2f",media);

    return 0;
}
