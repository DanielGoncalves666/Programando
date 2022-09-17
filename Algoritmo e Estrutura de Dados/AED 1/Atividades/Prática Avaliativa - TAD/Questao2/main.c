#include <stdio.h>
#include <math.h>
#include "../include/ponto.h"

int main()
{
	int x = 0, y = 0, z = 0;
	double result = 0;
	ponto_tri *um = NULL, *dois = NULL;

	printf("----Entre com as coordenadas para dois pontos tridimensionais:----\n");
	printf("Primeiro ponto, coordenadas x,y e z, respectivamente:\n");
	scanf("%d %d %d",&x,&y,&z);	
	um = cria_ponto(x,y,z);
	
	printf("Segundo ponto, coordenadas x,y e z, respectivamente:\n");
	scanf("%d %d %d",&x,&y,&z);	
	dois = cria_ponto(x,y,z);

	if(um == NULL || dois == NULL)
	{
		printf("\n------Falha ao alocar as estruturas!------\n");
		return 1;
	}

	result = distancia_pontos(um,dois);

	printf("\nA distancia entre os pontos inseridos é de %.2lf\n",result);

	libera_ponto(&um);
	libera_ponto(&dois);

	return 0;
}