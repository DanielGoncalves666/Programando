#include <stdio.h>
#include <stdlib.h>
#include "../include/complexo.h"

struct complexo
{
	double real;
	double imaginaria;
};


/*
Nome: criar_nro
--------
Entrada: dois doubles, um representando a parte real e outro a parte imaginaria
Processo: aloca uma estrutura do tipo complexo e atribui a ela os valores recebidos.
Saída: endereço para uma estrutura do tipo complexo.
*/
Nr_complexo *criar_nro(double r, double im)
{
	Nr_complexo *num = (Nr_complexo *) malloc(sizeof(Nr_complexo));
	if(num == NULL)
		return NULL;

	num->real = r;
	num->imaginaria = im;

	return num;
}

/*
Nome: libera_nro
--------
Entrada: ponteiro para ponteiro do tipo complexo
Processo: desaloca a estrutura cujo endereço foi recebido
Saída: nada.
*/
void libera_nro(Nr_complexo **num)
{
	free(*num);
	*num = NULL;//é por causa dessa linha que usamos ponteiro para ponteiro
}

/* 
Nome: soma
--------
Entrada: dois ponteiros para estruturas do tipo complexo
Processo: realiza a soma de dois numeros complexos
Saída: endereço para estrutura do tipo complexo
*/
Nr_complexo *soma(Nr_complexo *um, Nr_complexo *dois)
{
	int r = 0;
	int im = 0;

	if(um == NULL || dois == NULL)
		return NULL;

	r = um->real + dois->real;
	im = um->imaginaria + dois->imaginaria;

	Nr_complexo *tres = criar_nro(r,im);
	//caso um erro tenha ocrrido, criar_nro ja retornará NULL

	return tres;
}

/* 
Nome: subtracao
--------
Entrada: dois ponteiros para estruturas do tipo complexo
Processo: realiza a subtração de dois números complexos
Saída: endereço para estrutura do tipo complexo
*/
Nr_complexo *subtracao(Nr_complexo *um, Nr_complexo *dois)
{
	int r = 0;
	int im = 0;

	if(um == NULL || dois == NULL)
		return NULL;

	r = um->real - dois->real;
	im = um->imaginaria - dois->imaginaria;

	Nr_complexo *tres = criar_nro(r,im);
	//caso um erro tenha ocrrido, criar_nro ja retornará NULL

	return tres;
}

/* 
Nome: mult
--------
Entrada: dois ponteiros para estruturas do tipo complexo
Processo: realiza a subtração de dois números complexos
Saída: endereço para estrutura do tipo complexo
*/
Nr_complexo *mult(Nr_complexo *um, Nr_complexo *dois)
{
	int r = 0;
	int im = 0;

	if(um == NULL || dois == NULL)
		return NULL;

	r = (um->real * dois->real) - (um->imaginaria * dois->imaginaria);
	im = (um->real * dois->imaginaria) + (um->imaginaria * dois->real);

	Nr_complexo *tres = criar_nro(r,im);
	//caso um erro tenha ocrrido, criar_nro ja retornará NULL
		
	return tres;
}

/* 
Nome: acesso_real
--------
Entrada: endereço para uma estrutura do tipo complexo
Processo: nenhum
Saída: valor armazenado no campo real da estrutura
*/
double acesso_real(Nr_complexo *num)
{
	return num->real;
}

/* 
Nome: acesso_imaginario
--------
Entrada: endereço para uma estrutura do tipo complexo
Processo: nenhum
Saída: valor armazenado no campo imaginario da estrutura
*/
double acesso_imaginario(Nr_complexo *num)
{
	return num->imaginaria;
}