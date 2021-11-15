#include<stdio.h>
#include<stdlib.h>

int i,T,h,N;
unsigned long long aN,a1,a2;

int main(){
    scanf("%d",&T);
    for(i=0;i<T;i++){
        a1=0;
        a2=1;
        scanf("%d",&N);
        if(N==0)
            printf("Fib(0) = 0\n");
        else if(N==1)
            printf("Fib(1) = 1\n");
        else{
            for(h=2;h<=N;h++){
                aN=a1+a2;
                a1=a2;
                a2=aN;
            }
            printf("Fib(%d) = %lld\n",N,aN);
        }

    }
    return 0;
}

