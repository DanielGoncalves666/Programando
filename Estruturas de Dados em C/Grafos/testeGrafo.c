#include<stdio.h>
#include"GMA-D.h"

int main()
{
	Grafo teste = criarGrafo(5);

	printf("%d ",inserirAresta(teste,0,1));
	printf("%d ",inserirAresta(teste,0,2));
	printf("%d ",inserirAresta(teste,2,1));

	exibirMatriz(teste);
	exibirGrafo(teste);

	printf("%d ",removerAresta(teste,2,1));
	printf("%d ",removerAresta(teste,3,1));	

	exibirMatriz(teste);
	exibirGrafo(teste);

	liberarGrafo(teste);
	
	return 0;
}
