#include<stdio.h>

char letra='A';             //para inicializar uma variavel char deve-se colocar a letra entre aspas simples
                            //pela Linguagem C ser case sensitive, letras maiusculas e minusculas sao totalmente diferentes
int main()
{
    printf("%c\n",letra);
                            //espaço e quebra de linhas tambem sao considerados caracteres
                            /*quando letras precisam ser repetidas em vez de gastar mais espaço armazenando a mesma letra,
                              basta utiliza-la mais vezes */
    return 0;
}
