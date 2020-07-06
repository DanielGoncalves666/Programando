#include<stdio.h>
#include<stdlib.h>

int main(){
    int N;
    while(scanf("%d",&N) != EOF){
        int str[N];
        for(int i=0; i<N; i++){
            scanf("%d",&str[i]);
        }
        for(int i=0;i<N-1;){
            if(str[i] > str[i+1]){
                int aux = str[i];
                str[i] = str[i+1];
                str[i+1] = aux;
                i = 0;
            }else
                i++;
        }
        for(int i=0; i<N; i++){
            printf("%04d\n",str[i]);
        }
    }

    return 0;
}