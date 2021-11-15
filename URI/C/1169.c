#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int N,i,X,h;
unsigned long long a,b;

int main(){
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&X);
        a=0;
        for(h=0;h<X-1;h++){
            a+=pow(2,h);
        }
        b=a/6000;
        printf("%lld kg\n",b);
    }
}
