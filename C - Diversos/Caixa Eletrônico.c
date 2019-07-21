#include<stdio.h.>
#include<stdlib.h>

int saque,notas,valor,cinquenta,vinte,dez,cinco,dois,um;
int resto_1,resto_2,resto_3,resto_4,resto_5;

int main()
{
    printf("Informe o valor a ser sacado.\n");
    scanf("%d",& saque);
    if(saque<=2000)
    {
       cinquenta=saque/50;
       resto_1=saque%50;
       if(resto_1!=0)
       {
           vinte=resto_1/20;
           resto_2=saque%20;
           if(resto_2!=0)
           {
               dez=resto_2/10;
               resto_3=saque%10;
               if(resto_3!=0)
               {
                   cinco=resto_3/5;
                   resto_4=saque%5;
                   if(resto_4!=0)
                   {
                        dois=resto_4/2;
                        resto_5=saque%2;
                        if(resto_5!=0)
                        {
                            um=resto_5/1;
                        }
                   }
               }
           }
       }
    }
    else
    {
        printf("Nao pode sacar valores maiores que 2000\n");
    }
    printf("Saque de R$%d,00:\n",saque);
    printf("%d notas de 50\n",cinquenta);
    printf("%d notas de 20\n",vinte);
    printf("%d notas de 10\n",dez);
    printf("%d notas de 5\n",cinco);
    printf("%d notas de 2\n",dois);
    printf("%d notas de 1\n",um);


    return 0;
}
