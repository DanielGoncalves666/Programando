#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD.h"

void tratamento(Pilha *plt, int escolha);
void imprimir(Pilha *plt);

int main()
{
	Pilha plt = NULL;

	int escolha;

	while(1)
	{
		printf("\n\n-------- Escolha uma das opções abaixo: --------\n");
		printf("1 - Criar Lista.\n");
		printf("2 - Inserir elemento.\n");
		printf("3 - Remover elemento.\n");
		printf("4 - Ver elemento do topo.\n");
		printf("5 - Esvaziar pilha.\n");
		printf("6 - Imprimir pilha.\n");
		printf("7 - sair.\n");

		scanf("%d",&escolha);

		if(escolha == 7)
			break;
		else
			tratamento(&plt,escolha);
	}


	return (0);
}

void tratamento(Pilha *plt, int escolha)
{
	char nom[MAX];
	int retorno;

	switch(escolha)
	{
		case 1:
			if(*plt != NULL)
				printf("\n----Pilha já existente!----\n");
			else
			{
				*plt = cria_pilha();
				printf("----Lista criada!----\n");
			}
			break;
		case 2:
			printf("\n----Entre com a string a ser inserida:----\n");
			scanf(" %[^\n]",nom);

			retorno = push(plt, nom);
			if(retorno == 0)
				printf("----Falha!----\n");
			else
				printf("----Sucesso!----\n");
			break;
		case 3:
			printf("----Removendo elemento do topo da pilha... ----");
			
			retorno = pop(plt, nom);
			if(retorno == 0)
				printf("----Falha! Pilha inexistente ou vazia!----\n");
			else
			{
				printf("----O elemento removido foi: %s\n", nom);
			}
			break;
		case 4:			
			retorno = le_topo(*plt, nom);
			if(retorno == 0)
				printf("----Falha! Pilha inexistente ou vazia!----\n");
			else
			{
				printf("----O elemento do topo é: %s.-------",nom);
			}
			break;
		case 5:
				printf("----Esvaziando a lista\n");
				retorno = esvaziar_pilha(plt);
				if(retorno == 0)
					printf("Pilha inexistente----\n");
				else
					printf("Pilha esvaziada!-----\n");
			break;
		case 6:
			imprimir(plt);

			break;
		default:
			printf("---Opção inválida!---\n\n");
			break;
	}
}

void imprimir(Pilha *plt)
{
	Pilha aux;
	char string[MAX];
	int retorno;

	if(pilha_vazia(*plt))
	{
		printf("----Pilha vazia!----\n");
		return;
	}

	while(1)
	{
		retorno = pop(plt,string);
		if(!retorno)
			break;
		
		push(&aux,string);
	}

	printf("\n----Imprimindo a pilha----\n");
	while(1)
	{
		retorno = pop(&aux,string);
		printf("-- %s --\n",string);

		if(!retorno)
			break;
		
		push(plt,string);
	}
}