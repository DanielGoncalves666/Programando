#include<stdio.h>
#include<stdlib.h>

int D,ano,mes,dia;

int main()
{
    scanf("%d",&D);
    if(D>=365)
    {
        ano=D/365;
        D=D-(ano*365);
    }
    mes=D/30;
    dia=D%30;
    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n",ano,mes,dia);

    return 0;
}
