#include<stdio.h>

char letra,letra0;

int main()
{
    scanf("%c",&letra0);  //maneira de se ler um caracter usando a fun��o scanf.
    letra=getchar();     /*a fun��o getchar funciona como a fun��o scanf. A diferen�a � que ela � voltada para caracteres.
                          para us�-la � s� fazer como o mostrado ao lado.*/
    printf("%c",letra);

    return 0;
}
