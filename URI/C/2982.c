#include<stdio.h>
#include<stdlib.h>

int N, valor;
unsigned long long int gastos = 0, verba = 0;
char T;

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf(" %c %d",&T,&valor);
		if(T == 'G')
			gastos += valor;
		if(T == 'V')
			verba += valor;
	}
	if(gastos <= verba)
		printf("A greve vai parar.\n");
	else
		printf("NAO VAI TER CORTE, VAI TER LUTA!\n");

	return 0;
}
