#include<stdio.h>
#include<stdlib.h>

int i,num,par=0,impar=0,nega=0,posi=0;

int main()
{
    for(i=1;i<=5;i++)
    {
        scanf("%d",&num);

        switch(num%2)
        {
            case 0:
                par++;
                break;
            case 1:
                impar++;
                break;
            case -1:
                impar++;
        }
        if(num>0)
        {
            posi++;
        }
        else if(num<0)
        {
            nega++;
        }
    }
    printf("%d valor(es) par(es)\n",par);
    printf("%d valor(es) impar(es)\n",impar);
    printf("%d valor(es) positivo(s)\n",posi);
    printf("%d valor(es) negativo(s)\n",nega);

    return 0;
}
