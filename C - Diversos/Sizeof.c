#include<stdio.h>

int main ()
{
    printf("int: %d bytes\n",sizeof(int)); //a fun��o sizeof � utilizada para saber o tamanho de um tipo de vari�vel
    printf("short int: %d bytes\n",sizeof(short)); //short=curto e long=grande
    printf("long int: %d bytes\n",sizeof(long));
                                                //signed=positivos e negativos; unsigned=positivos

    return 0;
}
