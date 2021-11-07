#include <stdio.h>
#include "../include/LLOI.h"

int escolha(int,int *, Lista *);
void imprimir(Lista p);

int main()
{
	Lista listinha;
	int retorno = 0;//recebe o retorno da funcao escolha
	int num = 0;//recebe a escolha do usuario
	int inicializada = 0;//indica se a lista já foi inicializada, 0 para não, 1 para sim

	while(1)
	{
		printf("\nPor favor, entre com uma das opções abaixo:\n");
		printf("1: Criar uma lista.\n");
		printf("2: Imprimir a lista.\n");
		printf("3: Adicionar elementos na lista.\n");
		printf("4: Remover elementos da lista por valor.\n");
		printf("5: Remover elementos da lista por posicao.\n");
		printf("6: Sair.\n");
		scanf("%d",&num);

		retorno = escolha(num,&inicializada,&listinha);

		if(retorno == 1)
			break;
	}


	return (0);
}


/*
escolha
--------
Entrada:inteiro
Processo: trata a escolha do usuário.
Saída: inteiro; 0, para continuar, 1, para parar
*/
int escolha(int choice, int *inicializada, Lista *list)
{
	int retorno = 0;
	int elemento;
	int posicao;

	switch(choice)
	{
		case 1:
			if(*inicializada == 1)
				printf("Lista ja inicializada!\n");
			else
			{
				*list = inicializar_lista();
				*inicializada = 1;

				printf("---Lista Inicializada!---\n");
			}

			break;
		case 2:
			if(*inicializada == 0)
				printf("Nenhuma lista existente!\n");	
			else
			{
				retorno = lista_vazia(*list);

				if(retorno == 1)
					printf("\n----A Lista está vazia!----\n");
				else
					imprimir(*list);
			}

			break;
		case 3:
			if(*inicializada == 0)
				printf("Nenhuma lista existente!\n");	
			else
			{
				printf("Entre com o elemento :\n");
				scanf("%d",&elemento);
					
				retorno = insere_ord(list,elemento);

				if(retorno == 0)
					printf("\n----Falha ocorrida! Sem memória.----\n");
				else
					printf("Elemento adicionado!\n");
			}

			break;
		case 4:
			if(*inicializada == 0)
				printf("Nenhuma lista existente!\n");	
			else
			{
				
				printf("Entre com o elemento:\n");
				scanf("%d",&elemento);
				
				retorno = remove_ord(list,elemento);

				if(retorno == 0)
					printf("\n----Falha ocorrida! Lista vazia ou elemento não encontrado.----\n");
				else
					printf("Elemento removido!\n");
			}

			break;
		case 5:
			if(*inicializada == 0)
				printf("Nenhuma lista existente!\n");	
			else
			{
				
				printf("Entre com a posicao do elemento a ser removido (começando por 1):\n");
				scanf("%d",&posicao);
				
				retorno = remove_pos(list,posicao - 1, &elemento);

				if(retorno == 0)
					printf("\n----Falha ocorrida! Lista vazia ou elemento não encontrado.----\n");
				else
				{
					printf("Elemento removido!\n");
					printf("O elemento removido foi %d\n.", elemento);
				}
				
			}

			break;
		case 6:
			return 1;
			break;
		default:
			printf("\n-------- Escolha invalida! --------\n");
			break;
	}

	return 0;	
}

/*
imprimir
-----------
Entrada: tipo Lista
Processo: imprime a lista
Saída: nenhuma
*/
void imprimir(Lista p)
{
	int i;
	int retorno;
	int elem;

	for(i = 0;; i++)
	{
		retorno = get_pos(p,i,&elem);

		if(retorno == 0)
		{
			printf("FIM\n");
			break;
		}

		printf("Elemento %d: ",i + 1);
		printf("%d.\n", elem);
	}
}