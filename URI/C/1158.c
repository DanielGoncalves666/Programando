#include<stdio.h>
#include<stdlib.h>

int N,i,h,X,Y,soma;

int main(){
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d %d",&X,&Y);
        soma=0;
        for(h=0;h<Y;){
            if(X%2==1 || X%2==-1){
                soma+=X;
                h++;
                X+=2;
            }else
                X++;
        }
        printf("%d\n",soma);
    }

    return 0;
}
