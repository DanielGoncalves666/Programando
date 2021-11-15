#include<stdio.h>

int C,B,P,Cr,Br,Pr,nao = 0;

int main(){
    scanf("%d %d %d",&C,&B,&P);
    scanf("%d %d %d",&Cr,&Br,&Pr);

    if(C < Cr)
        nao += Cr - C;
    if(B < Br)
        nao += Br - B;
    if(P < Pr)
        nao += Pr - P;

    printf("%d\n",nao);

    return 0;
}
