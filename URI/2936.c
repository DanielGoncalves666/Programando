#include<stdio.h>
#include<stdlib.h>

int main(){
	int C,B,Bo,M,I,soma;
    scanf("%d %d %d %d %d",&C,&B,&Bo,&M,&I);
	soma = C * 300 + B * 1500 + Bo * 600 + M * 1000 + I * 150 + 225;
	printf("%d\n",soma);
	return 0;
}
