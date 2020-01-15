#include<stdio.h>
#include<stdlib.h>

int N, C = 0, R = 0, S = 0, qtd;
float total = 0;
char tipo;

int main(){
	scanf("%d",&N);
	
	for(int i=0; i<N; i++){
		scanf("%d %c",&qtd,&tipo);
		total += qtd;
		
		if(tipo == 'C')
			C += qtd;
		if(tipo == 'S')
			S += qtd;
		if(tipo == 'R')
			R += qtd;
	}
	
	printf("Total: %.0f cobaias\n",total);
	printf("Total de coelhos: %d\n",C);
	printf("Total de ratos: %d\n",R);
	printf("Total de sapos: %d\n",S);
	printf("Percentual de coelhos: %.2f %%\n", (C/total)*100);
	printf("Percentual de ratos: %.2f %%\n",(R/total)*100);
	printf("Percentual de sapos: %.2f %%\n",(S/total)*100);

	return 0;
}
