#include<stdio.h>
#include<stdlib.h>

int N,maior = 0;

int main(){
    for(;;){
        scanf("%d",&N);
        if(N == 0){
            printf("%d\n",maior);
            break;
        }
        if(maior < N)
            maior = N;
    }

    return 0;
}
