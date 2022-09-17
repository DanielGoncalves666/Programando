#include<stdio.h>

int main(){
	long long int N;

	scanf("%lld",&N);
	long long int qtd_diagonais = (N * (N - 3))/2;

	printf("%lld\n",qtd_diagonais);
	
	return 0;
}