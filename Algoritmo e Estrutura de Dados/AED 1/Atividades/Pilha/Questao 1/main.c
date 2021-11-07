#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD.h"

void tratamento(Pilha *plt, int escolha);
void imprimir(Pilha plt);

int main()
{
	Pilha plt = NULL;

	int escolha;

	while(1)
	{
		printf("\n-------- Escolha uma das opções abaixo: --------\n");
		printf("1 - Criar Lista.\n");
		printf("2 - Inserir elemento.\n");
		printf("3 - Remover elemento.\n");
		printf("4 - Ver elemento do topo.\n");
		printf("5 - Liberar pilha.\n");
		printf("6 - Esvaziar pilha.\n");
		printf("7 - Imprimir pilha.\n");
		printf("8 - sair.\n");

		scanf("%d",&escolha);

		if(escolha == 8)
			break;
		else
			tratamento(&plt,escolha);
	}


	return (0);
}

void tratamento(Pilha *plt, int escolha)
{
	long int matricula;
	char nom[MAX];
	char set;
	float sal;
	int retorno;

	switch(escolha)
	{
		case 1:
			if(*plt == NULL)
			{
				*plt = cria_pilha();
				if(plt == NULL)
					printf("----Falha na criação da lista! Sem memória!----\n");
				else
					printf("----Sucesso!----\n");
			}
			else
				printf("\n----Pilha já existente!----\n");
			break;
		case 2:
			if(*plt == NULL)
			{
				printf("----Lista inexistente----\n");
				break;
			}

			printf("\n----Entre com os dados a serem inseridos:----\n");
			printf("Matricula:\n");
			scanf("%ld",&matricula);
			printf("Nome:\n");
			scanf(" %[^\n]", nom);
			printf("Setor:\n");
			scanf(" %c",&set);
			printf("Salario:\n");
			scanf("%f",&sal);

			retorno = push(*plt,matricula,nom,set,sal);
			if(retorno == 0)
				printf("----Falha!----\n");
			else
				printf("----Sucesso!----\n");
			break;
		case 3:
			printf("----Removendo elemento do topo da pilha... ----");
			
			retorno = pop(*plt, &matricula, nom, &set, &sal);
			if(retorno == 0)
				printf("Falha! Pilha inexistente ou cheia!----\n");
			else
			{
				printf("O elemento removido foi:\nMatricula = %ld\nNome = %s\n",matricula,nom);
				if(set == 'F')
					printf("Setor = Fábrica\n");
				else if(set == 'A')
					printf("Setor = Administrativo\n");
				else if(set == 'C')
					printf("Setor = Comercial\n");
				else if(set == 'G')
					printf("Setor = Gerência\n");
				else
					printf("Setor = Não identificado\n");

				printf("Salario = %.2f\n\n",sal);
			}
			break;
		case 4:			
			retorno = get_topo(*plt, &matricula, nom, &set, &sal);
			if(retorno == 0)
				printf("----Falha! Pilha inexistente ou vazia!----\n");
			else
			{
				printf("----O elemento do topo é:\nMatricula = %ld\nNome = %s\n",matricula,nom);
				if(set == 'F')
					printf("Setor = Fábrica\n");
				else if(set == 'A')
					printf("Setor = Administrativo\n");
				else if(set == 'C')
					printf("Setor = Comercial\n");
				else if(set == 'G')
					printf("Setor = Gerência\n");
				else
					printf("Setor = Não identificado\n");

				printf("Salario = %.2f\n\n",sal);
			}
			break;
		case 5:
			retorno = libera_pilha(plt);
			if(retorno == 0)
				printf("----Falha, nenhuma pilha a ser liberada!----\n");
			else
			{
				printf("----Pilha liberada!----\n");
			}
			break;
		case 6:
				printf("----Esvaziando a lista\n");
				retorno = esvazia_pilha(*plt);
				if(retorno == 0)
					printf("Pilha inexistente----\n");
				else
					printf("Pilha esvaziada!-----\n");
			break;
		case 7:
			imprimir(*plt);
			break;
		default:
			printf("---Opção inválida!---\n\n");
			break;
	}
}

void imprimir(Pilha plt)
{
	long int matricula;
	char nom[MAX];
	char set;
	float sal;
	int retorno;

	if(plt == NULL)
	{
		printf("----Pilha inexistente----\n");
		return;
	}

	Pilha aux = cria_pilha();

	if(pilha_vazia(plt) || aux == NULL) 
	{
		printf("----Falha!----\n");
	}

	while(1)
	{
		retorno = pop(plt,&matricula,nom,&set,&sal);
		if(!retorno)
			break;
		push(aux,matricula,nom,set,sal);
	}

	printf("\n----Imprimindo a pilha----\n");
	while(1)
	{
		retorno = pop(plt,&matricula,nom,&set,&sal);
		printf("----Matricula = %ld\nNome = %s\n",matricula,nom);
		if(set == 'F')
			printf("Setor = Fábrica\n");
		else if(set == 'A')
			printf("Setor = Administrativo\n");
		else if(set == 'C')
			printf("Setor = Comercial\n");
		else if(set == 'G')
			printf("Setor = Gerência\n");
		else
			printf("Setor = Não identificado\n");
		
		printf("Salario = %.2f\n\n",sal);
		
		if(!retorno)
			break;
		push(aux,matricula,nom,set,sal);
	}

	libera_pilha(&aux);
}