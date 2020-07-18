#include<stdio.h>
#include<stdlib.h>

int main(){
	int N, T, num;

	scanf("%d",&N);

	for(int i=0; i<N; i++){
		scanf("%d",&T);

		int *vet = (int *) calloc(T,sizeof(int)), qtd = 0;
		for(int h=0; h<T; h++){
			scanf("%d",&num);
			
			if(num == 0){
				for(int j=0; j<T; j++){
					if(vet[j] == -1){
						break;
					}

					if(j == T - 1){//se for a ultima posição do vetor
						vet[h] = -1;
						qtd++;
					}
				}
			}else if(vet[h] == 0){
				for(int j=0; j<T; j++){
					if(vet[j] == num){
						break;
					}

					if(j == T - 1){//se for a ultima posição do vetor
						vet[h] = num;
						qtd++;
					}
				}
			}
		}

		printf("%d\n",qtd);

	}
	return 0;
}