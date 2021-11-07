#include <stdio.h>
#include <stdlib.h>
#include "../include/esfera.h"
#include "../include/ponto.h"

const double PI = 3.1415;

struct esfera
{
	ponto_tri *centro;
	ponto_tri *superficie;
};

/*
criar_esfera
-------------
Entrada: seis inteiros, representando as coordenadas de dois pontos tridimensionais. Os três primeiros se referem ao primeiro ponto e os últimos ao segundo ponto.
Processo: aloca e preenche uma estrutura do tipo esfera.
Saída: endereço para uma estrutura do tipo Esfera
*/
Esfera *criar_esfera(int x1, int y1, int z1, int x2, int y2, int z2)
{
	if(x1 == x2 && y1 == y2 && z1 == z2)
		return NULL;

	ponto_tri *C = cria_ponto(x1,y1,z1);
	ponto_tri *S = cria_ponto(x2,y2,z2);
	Esfera *E = (Esfera *) malloc(sizeof(Esfera));

	if(C == NULL || S == NULL || E == NULL)
		return NULL;

	E->centro = C;
	E->superficie = S;

	return E;
}

/*
libera_esfera
--------------
Entrada: ponteiro para ponteiro do tipo Esfera.
Processo: desaloca a estrutura Esfera e seta o ponteiro apontado para NULL
Saída: nenhuma
*/
void libera_esfera(Esfera **E)
{
	free((*E)->centro);
	free((*E)->superficie);

	free(*E);
	*E = NULL;
}

/*
raio_esfera
------------
Entrada: ponteiro para o tipo Esfera
Processo: calcula o raio
Saída: inteiro, representando o raio, em sucesso, 0, em fracasso
*/
double raio_esfera(Esfera *E)
{
	double distancia = 0;//armazena a distancia

	if(E == NULL)
		return 0;

	distancia = distancia_pontos(E->centro,E->superficie);

	return distancia;
}

/*
area_esfera
-----------
Entrada: um inteiro, representando o raio.
Processo: calcula a area superficial de uma esfera
Saída: 0, em falha, um double, representando a superficie de uma esferea
*/
double area_esfera(double raio)
{
	if(raio <= 0)
		return 0;

	return 4 * PI * raio * raio;
}

/*
volume_esfera
---------------
Entrada: um inteiro, representando o raio de uma esfera
Processo: calcula o volume de uma esfera com o raio dado
Saída: 0, em falha, um double, representando o volume da esfera, em sucesso
*/
double volume_esfera(double raio)
{
	if(raio <= 0)
		return 0;

	return 4.0/3 * PI * raio * raio * raio;
}