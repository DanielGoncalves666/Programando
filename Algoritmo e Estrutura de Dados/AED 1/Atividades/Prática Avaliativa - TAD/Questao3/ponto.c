#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

struct ponto
{
	int x;
	int y;
	int z;
};

/*
cria_ponto
-----------
Entrada: três inteiros, representando as coordenadas x, y e z.
Processo: Aloca uma estrutura do tipo ponto_tri e preenche seus campos.
Saída: ponteiro para o tipo ponto_tri
*/
ponto_tri *cria_ponto(int x, int y, int z)
{
	ponto_tri *point = (ponto_tri *) malloc(sizeof(ponto_tri));
	if(point == NULL)
		return NULL;

	point->x = x;
	point->y = y;
	point->z = z;

	return point;
}

/*
libera_ponto
-------------
Entrada: ponteiro para ponteiro do tipo ponto_tri
Processo: Realiza a liberação de memória alocada para uma estrutura.
Saída: nenhuma
*/
void libera_ponto(ponto_tri **p)
{
	free(*p);
	*p = NULL;
}

/*
distancia_pontos
-----------------
Entrada: dois ponteiros para estruturas do tipo ponto_tri
Processo: Calcula a distancia entre dois pontos tridimensionais
Saída: Um double: -1, se a operação falhar, a distancia, se ocorrer sucesso
*/
double distancia_pontos(ponto_tri *um, ponto_tri *dois)
{
	double distancia = 0;
	
	if(um == NULL || dois == NULL)
		return -1;

	distancia = sqrt(pow(um->x - dois->x,2) + pow(um->y - dois->y,2) + pow(um->z - dois->z,2));
	
	return distancia;
}

/*
get_x
--------
Entrada: ponteiro para o tipo ponto_tri
Processo: Retorna a coordenada X.
Saída: coordenada x armazenada na estrutura recebida.
*/
int get_x(ponto_tri *point)
{
	return point->x;
}

/*
get_y
--------
Entrada: ponteiro para o tipo ponto_tri
Processo: Retorna a coordenada y.
Saída: coordenada y armazenada na estrutura recebida.
*/
int get_y(ponto_tri *point)
{
	return point->y;
}

/*
get_z
--------
Entrada: ponteiro para o tipo ponto_tri
Processo: Retorna a coordenada z.
Saída: coordenada z armazenada na estrutura recebida.
*/
int get_z(ponto_tri *point)
{
	return point->z;
}