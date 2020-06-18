#include<stdio.h>
#include<stdlib.h>

int main(){
    int N,total=0,carro;
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        scanf("%d",&carro);
        if(carro == 2)
            total++;
        else if(carro == 3)
            total++;
    }
    printf("%d\n",total);

    return 0;
}
