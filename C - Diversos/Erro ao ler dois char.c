#include<stdio.h>

char a,b;

int main()
{
    scanf("%c",&a);
    scanf(" %c",&b);



    return 0;
    /* Quando vamos ler dois caracteres usando a função scanf costuma ler somente a primeira pois quando damos enter
    ele é considerado o outro caractere. Para evitar que isso acontece basta colocar um espaço antes do %c no segundo
    scanf.Porem isso funciona apenas para esta funcao
    Outra alternativa, que serve para todas as outras funções, é limppar o buffer(memoria temporaria) do teclado depois de
    cada scanf,getchar,gect ou fgect.
    Para isso usa-se fflush(stdin) no caso do windows e __fpurge(stdin) no caso do linux
    */
}
