#include<stdio.h>
#include<stdlib.h>

int i=0;
float num,media,soma=0.0;

int main()
{
    for(;;)
    {
        scanf("%f",&num);
        if(num<0)
            break;
        soma=soma+num;
        i++;
    }
    media=soma/i;
    printf("%.2f\n",media);

    return 0;
}
