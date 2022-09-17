#include<stdio.h>

int main(){
    int N;
    scanf("%d",&N);

    for(int i=0; i<N; i++){
        int N,K;
        scanf("%d %d",&N,&K);

        if(N == K)
            printf("1\n");
        else if(N < K)
            printf("%d\n",N);
        else{
            int extras = N / K;
            printf("%d\n",extras + N%K);
        }
    }

    return 0;
}
