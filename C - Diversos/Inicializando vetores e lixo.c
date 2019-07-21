#include <stdio.h>

//para inicializar um vetor assim que é declarado temos que colocar os valores entre chaves na sequencia em
//que serao armazenados,conforme exemplo:
int numeros[3] = { 1, 2, 3};
//Ou seja:
//numeros[0] = 1;
//numeros[1] = 2;
//numeros[2] = 3;
//é possivel fazer isso com int,float e ate caracteres
//porem o vetor de caracteres é especial e se chama string

//quando alocamos uma variavel por meio da declaração estamos usando um espaço que ja foi usado em algum momento
//neste espaço foi deixado um vestigio de seu uso, o qual damos o nome de lixo.
//para detectar este lixo basta nao inicializar as variaveis ou vetores
int main()
{
    int lixo[10];
    int indice;

    for(indice=0 ; indice < 11 ; indice++)
        printf("Lixo na posicao %d: %d\n", indice, lixo[indice]);

    return 0;


}
