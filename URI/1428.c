#include<stdio.h>
#include<stdlib.h>

int main(){
	int t,N,M;

	scanf("%d",&t);

	for(int i=0; i<t; i++){
		scanf("%d %d",&N,&M);
		int linhas, colunas;
		N -= 2;
		M -= 2;

		linhas = N/3;
		colunas = M/3;

		if(N % 3 != 0)
			linhas++;

		if(M % 3 != 0)
			colunas++;

		printf("%d\n",colunas*linhas);
	}

	return 0;
}