#include<stdio.h>
#include<stdlib.h>

int fatorial_menor(int num);

int main(){
	int N,qtd = 0;

	scanf("%d",&N);

	int aux = fatorial_menor(N);
	if(N == aux)
		printf("1\n");
	else{
		qtd++;
		for(;;){
			N -= aux;
			aux = fatorial_menor(N);
			qtd++;

			if(N == aux){
				printf("%d\n",qtd);
				break;
			}
		}
	}
	return 0;
}

int fatorial_menor(int num){
	int fator = 1;
	for(int i=1;;i++){
		fator *= i;

		if(num == fator)//num é um fatorial
			return num;

		if(num < fator)
			return fator/i;//retorna o fatorial que é menor que num
	}
}