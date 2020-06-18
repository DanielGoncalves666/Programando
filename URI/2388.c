#include<stdio.h>

int main(){
    int N,T,V,total=0;
    scanf("%d",&N);

    for(int i=0; i<N; i++){
        scanf("%d %d",&T,&V);
        total += T*V;
    }
    printf("%d\n",total);

    return 0;
}

