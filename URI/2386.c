#include<stdio.h>
#include<stdlib.h>

int main(){
    int area,N,estrela,qtd = 0;
    scanf("%d",&area);
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        scanf("%d",&estrela);
        if(estrela*area >= 40000000)
            qtd++;
    }
    printf("%d\n",qtd);

    return 0;
}
