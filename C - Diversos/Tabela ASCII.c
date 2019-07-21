#include<stdio.h>

char b=67;

int main()
{
    printf("%c\n",b);      /*quando declaramos um numero na variavel char estamos apenas identificando um caracter que é
                            correspondente aquele numero na tabela ASCII*/
    printf("%c%c%c%c%c%c",68,97,110,105,101,108);
                            /*Podemos fazer o contrario tambem. Dentro do printf colocar os numeros apos a virgula.*/
    return 0;
}
