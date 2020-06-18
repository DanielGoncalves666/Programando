#include<stdio.h>

int N, l, c, quebrados = 0;

int main(){
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        scanf("%d %d",&l,&c);
        if(l > c)
            quebrados += c;
    }
    printf("%d\n",quebrados);

    return 0;
}
