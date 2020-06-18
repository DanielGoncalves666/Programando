#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int T,turistas = 0, jipes = 0;
    char string[7];
    for(;;){
        scanf("%s",string);
        if(strcmp(string,"ABEND") == 0)
          break;

        scanf("%d",&T);

        if(strcmp(string,"SALIDA") == 0){
            jipes++;
            turistas += T;
        }
        if(strcmp(string,"VUELTA") == 0){
            jipes--;
            turistas -= T;
        }
    }
    printf("%d\n%d\n",turistas,jipes);

    return 0;
}
