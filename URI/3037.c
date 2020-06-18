#include<stdio.h>

int main(){
    int N, maria, joao, ponto, dist;

    scanf("%d",&N);
    for(int i=0; i<N; i++){
        maria = 0, joao = 0;
        for(int h=0;h<3;h++){
            scanf("%d %d",&ponto,&dist);
            joao += ponto*dist;
        }
        for(int h=0;h<3;h++){
            scanf("%d %d",&ponto,&dist);
            maria += ponto*dist;
        }
        if(maria > joao)
            printf("MARIA\n");
        else
            printf("JOAO\n");
//não em uma opção pra empate
    }

    return 0;
}
