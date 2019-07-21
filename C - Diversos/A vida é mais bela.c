#include<stdio.h>
#include<stdlib.h>

int main()
{
    int num,i,qtd[5]={0,0,0,0,0},p;

    for(i=0;i<20;i++)
    {
        scanf("%d",&num);
        if(num>0 && num<=12)
            qtd[0]++;
        if(num>=13 && num<=20)
            qtd[1]++;
        if(num>=21 && num<=45)
            qtd[2]++;
        if(num>=46 && num<=60)
            qtd[3]++;
        if(num>60)
            qtd[4]++;
    }
    for(p=0;p<5;p++)
    {
        printf("Intervalo %d: %d\n",p+1,qtd[p]);
    }

    return 0;
}
