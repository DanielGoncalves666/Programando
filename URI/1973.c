#include<stdio.h>
#include<stdlib.h>

int N, qtd=0,anterior;
unsigned long long int carneiros=0;


int main(){
	scanf("%d",&N);
	int vet[N];
	int roubado[N];
	for(int i=0; i<N; i++){
		scanf("%d",&vet[i]);
		carneiros += vet[i];
		roubado[i] = 0;
	}
	for(int i=0;i>-1 && i<N;){
		if(vet[i] > 0){
			anterior = vet[i];
			vet[i]--;
			carneiros--;
			
			if(roubado[i] == 0){
				qtd++;
				roubado[i] = 1;
			}
		}
		
		if(anterior%2 == 0)
			i--;
		else if(anterior%2 == 1)
			i++;
	}
	printf("%d %llu\n",qtd,carneiros);

	return 0;
}
