/* 	Lê da entrada uma quantidade indefinida de linhas contendo dois inteiros, indicando uma máquinas e as peças que produziu. Então, 
		calcula o total produzido por cada máquina.
  	Nenhum dado de entrada é necessário para se executar o programa.
  	Imprime uma lista informando a quantidade de peças produzidas por cada uma das 6 máquinas.
	
	Daniel Gonçalves
	2022
*/

#include<stdio.h>

int
main()
{
	int M = 0; // armazena a n-ésima máquina lida
	int P = 0; // armazena a produção referente a n-ésima máquina lida
	int somas[6] = {0}; // armazena a soma de cada máquina
	int i;

	while( scanf("%d %d",&M,&P) != EOF)
		somas[M - 1] += P;

	for(i = 0; i < 6; i++)
		printf("Máquina %d: %d\n",i+1,somas[i]);

	return 0;
}
