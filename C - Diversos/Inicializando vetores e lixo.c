#include <stdio.h>

//para inicializar um vetor assim que � declarado temos que colocar os valores entre chaves na sequencia em
//que serao armazenados,conforme exemplo:
int numeros[3] = { 1, 2, 3};
//Ou seja:
//numeros[0] = 1;
//numeros[1] = 2;
//numeros[2] = 3;
//� possivel fazer isso com int,float e ate caracteres
//porem o vetor de caracteres � especial e se chama string

//quando alocamos uma variavel por meio da declara��o estamos usando um espa�o que ja foi usado em algum momento
//neste espa�o foi deixado um vestigio de seu uso, o qual damos o nome de lixo.
//para detectar este lixo basta nao inicializar as variaveis ou vetores
int main()
{
    int lixo[10];
    int indice;

    for(indice=0 ; indice < 11 ; indice++)
        printf("Lixo na posicao %d: %d\n", indice, lixo[indice]);

    return 0;


}
