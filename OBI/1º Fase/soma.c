//errado

#include<stdio.h>

int N, K, vet[10],soma;
long int qtd = 0;

int main(){
	scanf("%d %d",&N,&K);
	
	for(int i=0;i<N;i++){
		scanf("%d",&vet[i]);
	}
	for(int i=0;i<N;i++){
		soma = vet[i];
		if(soma == K)
			qtd++;
		for(int h=1+i;h<N;h++){
			soma += vet[h];
			if(soma == K)
				qtd++;
		}
	}
	printf("%ld",qtd);

	return 0;
}	
