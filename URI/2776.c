#include<stdio.h>

int main(){
    int N, M, latas, valor;
    while(scanf("%d %d",&N,&M) != EOF){
        int melhor = 0;
        for(int i=0; i<N; i++){
            scanf("%d %d",&latas,&valor);
            int inteiro = M / latas;
            valor *= inteiro;

            if(valor > melhor)
                melhor  = valor;
        }
        printf("%d\n",melhor);
    }

    return 0;
}
