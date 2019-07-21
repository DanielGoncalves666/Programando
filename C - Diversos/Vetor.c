#include<stdio.h>
#include<stdlib.h>
//a sintaxe dos vetores é a seguinte:
// tipo nome[numero_de_elementos]
//a contagem do indice de elementos sempre começa no 0 ou seja:
//nome[0],nome[1],etc
//para usa-las é só se referir a elas usando o nome e seu indice
//usar nomes para os vetores/arrays em vez de apenas letras

//AVISO:O INDICE COMEÇA NO 0

int main()
{

    int number[3],
        indice;

        for(indice=0 ; indice <= 2 ; indice++)
        {
            printf("Entre com o numero %d: ", indice+1);
            scanf("%d", &number[indice]);
        }

        for(indice=0 ; indice <= 2 ; indice++)
            printf("Numero %d = %d\n", indice+1, number[indice]);

    return 0;
}
