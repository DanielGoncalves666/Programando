#include<stdio.h>

int main(){
    int N,valor;
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        scanf("%d",&valor);
        if(valor > 8000)
            printf("Mais de 8000!\n");
        else
            printf("Inseto!\n");
    }

    return 0;
}
