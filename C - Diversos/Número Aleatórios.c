#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int main()
{
    int i;
    printf("intervalo da rand: [0,%d]\n", RAND_MAX);

    for(i=1 ; i <= 10 ; i++)
        printf("Numero %d: %d\n",i, rand());


    return 0;
    //os numeros que damos para gerar numeros aleatorios sao chamados de seed(semente)
    //a função que gera numeros aleatorios em C é a rand()
            //ela gera numeros entre 0 e RAND_MAX, onde este varia de pc para pc
    //a rand() necessita da biblioteca time.h e para determinar a RAND_MAX é ncessario stdlib.h

    //com essa estrtura sem pre obteremos a mesma sequencia, por isso temos que fazer o que esta expresso em
        //Numeros Aleatorios 2
}
