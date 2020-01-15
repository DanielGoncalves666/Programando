#include<stdio.h>
#include<stdlib.h>

int a;
long long A,B,C;

int main(){
    for(;;){
        a=scanf("%lld %lld",&A,&B);
        if(a==EOF)
            break;
        C=A-B;
        if(C<0)
            C*=-1;
        printf("%lld\n",C);
    }

    return 0;
}

