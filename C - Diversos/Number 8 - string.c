#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char palavra[20];
int i;

int main()
{
    scanf("%s",&palavra);

    for(i=19;i>=0;i--)
        printf("%c",palavra[i]);

    return 0;
}
