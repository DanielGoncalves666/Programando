/*
	Um polimonio pode ter infinitos digitos, por isso o uso da alocação dinamica aplicada em cada um deles
é essencial para poupar memória e tornar a operação mais eficiente, evitando a ocupação desnecessária
de posições cujos coeficientes são zero.
	Por padrão, um polimonio é inicializado contendo um nó, que armazena o coeficiente 0 (unico permitido) 
para a potencia 0.
	Deste modo, não precisaremos nos preocupar com a inserção de elementos antes dele, apenas com a soma no 
expoente zero, e nem com a alteração do ponteiro para a lista. 
	Por isso usamos a implementação dinamica/encadeada sem cabeçalho. 
*/

#include <stdio.h>
#include <stdlib.h>
#include "header_8.h"

struct no
{
	int expoente;
	int coeficiente;
	struct no *prox;
};

int potenciacao(int base, int expoente);//como é apenas uma função, foi implementada para não se ter que incluir math.h

Polimonio inicializar()  
{
	Polimonio lst;
	lst = (Polimonio) malloc(sizeof(struct no));
	//alocamos o primeiro elemento do polimonio, de expoente zero

	lst->coeficiente = 0;
	lst->expoente = 0;
	lst->prox = NULL;
	//inicializamos o elemento no modo vazio.

	return lst;
}

int vazio(Polimonio lst)
{
	if(lst->prox == NULL && lst->expoente == 0 && lst->coeficiente == 0)
		return 1;

	return 0;
}


//0 para falha, 1 para sucesso, 2 para termo removido
int inserir(Polimonio lst, int poten, int coef)
{
	//expoentes inválidos
	if(poten < 0)
		return 0;

	//tratamos especialmente do expoente zero pois nao o desalocamos
	if(poten == 0)
	{
		lst->coeficiente += coef;
		return 1;
	}

	Polimonio aux = lst;

	while(aux->prox != NULL && poten > aux->prox->expoente)
		aux = aux->prox;

	//se ja existir aquela potencia, somamos o coeficiente
	if(aux->prox != NULL && poten == aux->prox->expoente)
	{
		aux->prox->coeficiente += coef;
		//existe a possibilidade que essa soma dos coeficientes resulta em 0, o que faz com que precisemos eliminar o termo
		if(aux->prox->coeficiente == 0)
		{
			eliminar_potencia(lst,poten,&coef);
			//coef passado apenas para preencher o argumento da função.

			return 2;
		}
	}
	else
	{
		//se não existir a potencia, criamos um novo no.
		Polimonio novo = (Polimonio) malloc(sizeof(struct no));
		if(novo == NULL)
			return 0;

		novo->coeficiente = coef;
		novo->expoente = poten;
		
		novo->prox = aux->prox;//recebe o endereço do proximo no
		aux->prox = novo;//o no anterior recebe o endereço do novo
	}
	
	return 1;
}

int eliminar_potencia(Polimonio lst, int poten, int *retorno)
{
	Polimonio aux = NULL;

	//expoentes negativos não existem no nosso polimonio
	//ou se a lista estiver no modo vazio
	if(poten < 0 || vazio(lst))
		return 0;
		
	//tratamos o zero de forma especial pois é o unico elemento que nunca é desalocado
	if(poten == 0)
	{
		*retorno = lst->coeficiente;
		lst->coeficiente = 0;
		return 1;
	}

	while(lst->prox != NULL && poten > lst->prox->expoente)
		lst = lst->prox;

	if(lst->prox == NULL || poten != lst->prox->expoente)
		return 0;
	
	*retorno = lst->prox->coeficiente;
	aux = lst->prox;
	lst->prox = aux->prox;
	free(aux);
	
	return 1;
}

void reiniciar(Polimonio lst)
{
	Polimonio aux = lst;
	Polimonio aux2 = NULL;

	if(vazio(lst))
		return;

	while(aux->prox != NULL)
	{
		aux2 = aux->prox;
		aux->prox = aux2->prox;

		free(aux2);
	}

	//coloca o nó do expoente 0 para o modo vazio
	lst->prox = NULL;
	lst->coeficiente = 0;
}

int calcular(Polimonio lst, int X)
{
	int numero = lst->coeficiente;//atribuimos direto o coeficiente do expoente zero

	while(lst->prox != NULL)
	{
		numero += lst->prox->coeficiente * potenciacao(X, lst->prox->expoente);
		lst = lst->prox; 
	}

	return numero;
}

void imprimir(Polimonio lst)
{
	int coef = 0;

	printf("P(x) = ");

	if(vazio(lst))
	{
		printf("0\n");
		return;
	}

	if(lst->coeficiente != 0)
	{
		if(coef > 0)
			printf("+");
		printf("%d ", lst->coeficiente);
	}

	while(lst->prox != NULL)
	{
		coef = lst->prox->coeficiente;

		if(coef > 0)
			printf("+");

		printf("%dx^%d ",coef,lst->prox->expoente);

		lst = lst->prox;
	}
	printf("\n");
}

int potenciacao(int base, int expoente)
{
	if(expoente == 0)
		return 1;

	return base * potenciacao(base, expoente - 1);
}
