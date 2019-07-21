#include <stdio.h>

int soma(int n)
{
    if(n == 1)                              //a recursividade é invocar uma função dentro dela propria
        return 1;                           //porem temos que ter cuidado para n fazer um loop infinito e definir
    else                                    //uma maneira de parar o processo em um ponto
        return ( n + soma(n-1) );           //em grande parte das vezes acab amos por usar o if else
}

int main()
{
    int n;
    printf("Digite um inteiro positivo: ");
    scanf("%d", &n);

    printf("Soma: %d\n", soma(n));
}
