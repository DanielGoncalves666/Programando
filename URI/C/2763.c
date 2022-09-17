#include<stdio.h>
#include<stdlib.h>

int main(){
    char string[15];
    scanf("%s",string);

    for(int i=0; i<14; i++){
        if(string[i] == '.' || string[i] == '-')
            printf("\n");
        else
            printf("%c",string[i]);
    }
    printf("\n");

    return 0;
}
