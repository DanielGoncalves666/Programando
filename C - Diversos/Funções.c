#include<stdio.h>
#include<stdlib.h>

//as funções devem fazer uma unica coisa e muito bem feita

int main()
{
    /*como declarar uma função. A sintaxe é a seguinte:
    tipo_de_retorno nome_da_função(lista de parâmetros)
    {

    }*/

    //e para invoca-la basta fazer: nome_da_funçao(lista de argumentos)

    /* Tipos de retorno:
    void-não recebem e nao retornam nada
    int-retorna inteiros
    float-retorna reias
    */

    //Parâmetros são variáveis que a função recebe.O número e tipo de parâmetros
           //são pré estabelecidos na declaração da função.
    //Os valores que podem ser atribuidos aos parametros sao os argumentos

    //para retornar um valor obtido dentro da função usamos o comando return _;  em que _=ao que ira se retornado

    //para alterar o valo de uma variavel dado por argumento basta utilizar o simbolo & antes da variavel ou
            //fazer com que a variavel receba o retorno da função por meio de uma igualdade em que a variavel é igual a função

    //para usar o prototipo de uma função com o intuito de n levar a main() pro final basta pegar o cabeçalho e colocar
            //um ponto e virgula no final

    return 0;

}
