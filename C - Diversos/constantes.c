#include<stdio.h>
#include<stdlib.h>
#define MAIORIDADE 18
const int aposentadoria = 65;
const int motorista = 16;

//nao é recomendavel o uso de variáveis pois em caso de ter alguma alteração que deva ser feita
//em um programa com mmilhares de linhas, isso causaria um grande problema.
//para solucionar esse problema podemos usar constantes
//podemos declarar funções usando o comando const ou #define e por muitas vezes é um costume declara-las abixo das bibliotecas
//a sintaxe no caso do comando const é:       const tipo_da_variavel nome_da_variavel = valor_da_variavel;
//a sintaxe pro #define:              #define nome_da_variavel valor_da_variavel, sem igualdade ou ;
//na #define é costume usar letras maiusculas para o nome da variavel

int main()
{
    int idade;
    printf("Digite sua idade: ");
    scanf("%d", &idade);

    if( idade >= MAIORIDADE )
        printf("Voce ja pode se alistar e dirigir.\n");
    else
        if( idade >= motorista )
            printf("Voce pode dirigir, mas nao pode se alistar.\n");
        else
            printf("Voce nao pode dirigir nem se alistar\n");

    if( idade >= aposentadoria )
        printf("Voce ja pode se aposentar!\n");

    return 0;
}
