#include<stdio.h>

char a,b;

int main()
{
    a=getc(stdin);
    b=fgetc(stind);

    return 0;
    /*
    As fun��es getc e fgetc, assim como a fun�ao getchar servem para ler caracteres
    O unico porem � que precisamos dizer ao programa de onde devera retirar as informa��es
    Neste caso especificamos o teclado em ambas fun��es
    */
}
