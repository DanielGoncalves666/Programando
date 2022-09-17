#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int N,T,soma;
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        scanf("%d",&T);
        soma = 0;
        for(int h=0; h<T; h++){
            soma += pow(2,h);
        }
        printf("%d\n",soma);
    }

    return 0;
}
