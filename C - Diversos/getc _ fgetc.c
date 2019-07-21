#include<stdio.h>

char a,b;

int main()
{
    a=getc(stdin);
    b=fgetc(stind);

    return 0;
    /*
    As funções getc e fgetc, assim como a funçao getchar servem para ler caracteres
    O unico porem é que precisamos dizer ao programa de onde devera retirar as informações
    Neste caso especificamos o teclado em ambas funções
    */
}
