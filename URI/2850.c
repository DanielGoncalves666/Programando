#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char str[9];

int main(){
    while(scanf("%[^\n]s",str) != EOF){
        getchar();
        if(strcmp(str,"esquerda") == 0)
            printf("ingles\n");
        else if(strcmp(str,"direita") == 0)
            printf("frances\n");
        else if(strcmp(str,"nenhuma") == 0)
            printf("portugues\n");
        else if(strcmp(str,"as duas") == 0){
            printf("caiu\n");
        }
    }
    return 0;
}
