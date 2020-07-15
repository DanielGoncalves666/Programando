#include<stdio.h>
#include<stdlib.h>

int main(){
	int N,vet[5];
	char letra;

	for(;;){
		scanf("%d",&N);

		if(N == 0)
			break;

		for(int i=0; i<N; i++){
			int preto = 0;
			for(int h=0; h<5; h++){
				scanf("%d",&vet[h]);

				if(vet[h] <=127){
					preto++;
					letra = (char) h + 65;
				}
			}
			
			if(preto == 1)
				printf("%c\n",letra);
			else
				printf("*\n");
		}
	}

	return 0;
}