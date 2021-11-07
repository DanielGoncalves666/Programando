#include <stdio.h>
#include "2.h"

/*
Utilizando APENAS as operações do item anterior, implemente a função elimina_elem() no programa 
aplicativo que, dado uma fila e o percentual mínimo de rendimento como entrada, retorna essa mesma 
fila sem os investimentos com rendimento inferior ao valor informado. Esta função também deve imprimir
 a soma dos valores retirados da aplicação ou uma mensagem de erro se não for possível realizar a operação.

Ex: Dada a fila F = { {2, 1750.00, 6.12}; {5, 500.25, -1.33}; {3, 5366.00, 0.5}; {7, 3800.22, 2.0} }
 e um percentual mínimo de rendimento igual a 1.0, a função deve alterar a fila para:
F = {  {2, 1750.00, 6.12}; {7, 3800.22, 2.0} } e imprimir a mensagem “Foram resgatados R$ 5866.25”
*/

void elimina_elem(Fila f, float minimo)
{
	if(fila_vazia(f))
	{
		printf("\n ----- Nao é possivel realizar a operação! ----- \n");
		return;
	}

	int retorno;
	double total = 0;
	Fila aux = cria_fila;
	struct investimentos inv;

	while(!fila_vazia(f))
	{
		remove_ini(f,&inv);

		if(inv.percentual >= minimo){//adiciona apenas os investimentos que foram maiores que o minimo
			retorno = insere_fim(aux,inv.codigo,inv.valor,inv.percentual);
			if(!retorno)
			{
				printf("\n ----- Falha ------ \n");
				return;
			}
		}
		else
		{
			total += inv.valor;
		}
	}

	while(!fila_vazia(aux))
	{
		remove_ini(aux,&inv);
		retorno = insere_fim(f,inv.codigo,inv.valor,inv.percentual);
		if(!retorno)
		{
			printf("\n ----- Falha ------ \n");
			return;
		}
	}

	if(total == 0)
		printf("\n ----- Nada foi resgatado! ----- \n");
	else
		printf("\n ----- Foram resgatados R$ %.2lf ------ \n",total);

}