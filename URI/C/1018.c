#include<stdio.h>
#include<stdio.h>

int N,cem,cinq,vinte,dez,cinco,dois,um;

int main()
{
    scanf("%d",&N);
    printf("%d\n",N);
    if(N>=100)
    {
        cem=N/100;
        N=N-cem*100;
    }
    if(N>=50)
    {
        cinq+=1;
        N=N-50;
    }
    if(N>=20)
    {
        vinte=N/20;
        N=N-vinte*20;
    }
    if(N>=10)
    {
        dez+=1;
        N=N-10;
    }
    if(N>=5)
    {
        cinco+=1;
        N=N-5;
    }
    if(N>=2)
    {
        dois=N/2;
        N=N-2*dois;
    }
    if(N%2==1)
    {
        um+=1;
    }
    printf("%d nota(s) de R$ 100,00\n",cem);
    printf("%d nota(s) de R$ 50,00\n",cinq);
    printf("%d nota(s) de R$ 20,00\n",vinte);
    printf("%d nota(s) de R$ 10,00\n",dez);
    printf("%d nota(s) de R$ 5,00\n",cinco);
    printf("%d nota(s) de R$ 2,00\n",dois);
    printf("%d nota(s) de R$ 1,00\n",um);

    return 0;
}
