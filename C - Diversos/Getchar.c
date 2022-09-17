#include<stdio.h>

char letra,letra0;

int main()
{
    scanf("%c",&letra0);  //maneira de se ler um caracter usando a função scanf.
    letra=getchar();     /*a função getchar funciona como a função scanf. A diferença é que ela é voltada para caracteres.
                          para usá-la é só fazer como o mostrado ao lado.*/
    printf("%c",letra);

    return 0;
}
