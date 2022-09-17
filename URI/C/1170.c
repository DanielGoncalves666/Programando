#include<stdio.h>
#include<stdlib.h>

int i,N,h;
float C;

int main(){
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%f",&C);
        for(h=0;C>1.0;h++){
            C/=2.0;
        }
        printf("%d dias\n",h);
    }
    return 0;
}
