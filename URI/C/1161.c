#include<stdio.h>
#include<stdlib.h>

int a,N,M;
unsigned long long R1,R2;

unsigned long long fatorial(int x){
    unsigned long long alfa;
    int i;
    alfa=1;
    if(x==0 || x==1)
        return 1;
    else{
        for(i=2;i<=x;i++){
            alfa*=i;
        }
        return alfa;
    }
}

int main(){
    for(;;){
        a=scanf("%d %d",&N,&M);
        if(a==-1)
            break;
        R1=fatorial(N);
        R2=fatorial(M);
        printf("%lld\n",R1+R2);
    }
    return 0;
}
