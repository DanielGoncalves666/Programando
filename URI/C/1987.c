#include<stdio.h>
#include<stdlib.h>

int main(){
	int N;
	
	while(scanf("%d ",&N) != EOF){
		char string[N + 1];
		scanf("%s",string);

		int soma = 0;
		for(int i=0; i<N; i++){
			soma += string[i] - '0';
		}

		printf("%d ",soma);

		if(soma % 3 == 0)
			printf("sim\n");
		else
			printf("nao\n");
	}

	return 0;
}