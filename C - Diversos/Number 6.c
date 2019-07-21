#include<stdio.h>
#include<stdlib.h>

int mes;

fon()
{
    if(mes<1 || mes>12)
        printf("Mes incompativel.\n");
    if(mes==1)
        printf("Janeiro.\n");
    if(mes==2)
        printf("Fevereiro.\n");
    if(mes==3)
        printf("Março.\n");
    if(mes==4)
        printf("Abril.\n");
    if(mes==5)
        printf("Maio.\n");
    if(mes==6)
        printf("Junho.\n");
    if(mes==7)
        printf("Julho.\n");
    if(mes==8)
        printf("Agosto.\n");
    if(mes==9)
        printf("Setembro.\n");
    if(mes==10)
        printf("Outubro.\n");
    if(mes==11)
        printf("Novembro.\n");
    if(mes==12)
        printf("Dezembro.\n");
}
int main()
{
    scanf("%d",&mes);
    fon();

    return 0;
}
