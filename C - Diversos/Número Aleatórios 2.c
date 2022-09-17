#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main()
{

    int i;
    printf("intervalo da rand: [0,%d]\n", RAND_MAX);
    srand( (unsigned)time(NULL) );

    for(i=1 ; i <= 10 ; i++)
        printf("Numero %d: %d\n",i, rand());

    return 0;
    //já que a sequencia gerada é sempre a mesma é necessario muda-la inserindo uma semente na rand()
    //neste caso o que sera inserido é o tempo atual, assim a rand pega toda vez um tempo diferent e gera uma sequencia !=
    //para isso temos que usar a função srand que ira alimentar a rand
    //srand( (unsigned)time(NULL) ); antes da rand().
    //para gerar numeros aleatorios entre um intervalo basta fazer o seguinte:
                //x = rand() % 10 - para gerar um valor entre 0 e 9
                //x = 1 + ( rand() % 10 ) - para gerar valores entre 1 e 10

}
