#include<stdio.h>
#include<stdlib.h>

int N,soma;
char str[13];

int main(){
	scanf("%d",&N);
	for(int i=0; i<N;i++){
		scanf("%s",str);
		soma = 0;
		soma += (((int) str[2] -48) * 10) + (((int) str[3] -48) * 1);
		soma += (((int) str[5] -48) * 100) + (((int) str[6] -48) * 10) + (((int) str[7] -48) * 1);
		soma += (((int) str[11] -48) * 10) + (((int) str[12] -48) * 1);
		printf("%d\n",soma);
	}

	return 0;
}
