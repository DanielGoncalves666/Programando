#include <stdio.h>
#include "../include/LLO.h"

int escolha(int,int *, ListaBebidas *);
void imprimir(ListaBebidas p);

int main()
{
	ListaBebidas listinha = NULL;
	int retorno = 0;//recebe o retorno da funcao escolha
	int num = 0;//recebe a escolha do usuario
	int criada = 0;//indica se a lista já foi criada, 0 para não, 1 para sim

	while(1)
	{
		printf("\nPor favor, entre com uma das opções abaixo:\n");
		printf("1: Criar uma lista.\n");
		printf("2: Apagar a lista.\n");
		printf("3: Imprimir a lista.\n");
		printf("4: Adicionar elementos na lista.\n");
		printf("5: Remover elementos na lista.\n");
		printf("6: Sair.\n");
		scanf("%d",&num);

		retorno = escolha(num,&criada,&listinha);

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
int escolha(int choice, int *criada, ListaBebidas *list)
{
	int retorno = 0;
	char name[lim];
	int vol = 0;
	float price = 0;

	switch(choice)
	{
		case 1:
			if(*criada == 1)
				printf("Lista ja criada!\n");
			else
			{
				*list = criar_lista();
				*criada = 1;

				printf("---Lista Criada!---\n");
			}

			break;
		case 2:
			if(*criada == 0)
				printf("Nenhuma lista existente!\n");		
			else
			{
				apaga_lista(list);
				*criada = 0;
				printf("---Lista Apagada!---\n");
			}

			break;
		case 3:
			if(*criada == 0)
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
		case 4:
			if(*criada == 0)
				printf("Nenhuma lista existente!\n");	
			else
			{
				printf("Entre com o nome da bebida (maximo de 20 caracteres):\n");
				scanf(" %20[^\n]",name);
				
				printf("Entre com o volume, em ml, da bebida:\n");
				scanf("%d", &vol);
				printf("Entre com o preco, por unidade, da bebida:\n");
				scanf("%f", &price);
				
				retorno = insere_ord(*list,name,vol,price);

				if(retorno == 0)
					printf("\n----Falha ocorrida! Lista cheia.----\n");
				else
					printf("Elemento adicionado!\n");
			}

			break;
		case 5:
			if(*criada == 0)
				printf("Nenhuma lista existente!\n");	
			else
			{
				
				printf("Entre com o nome da bebida (maximo de 20 caracteres) a ser removida:\n");
				scanf(" %20[^\n]", name);
				
				retorno = remove_ord(*list, name);

				if(retorno == 0)
					printf("\n----Falha ocorrida! Lista vazia ou elemento não encontrado.----\n");
				else
					printf("Elemento removido!\n");
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
Entrada: tipo ListaBebidas
Processo: imprime a lista
Saída: nenhuma
*/
void imprimir(ListaBebidas p)
{
	int i;
	const char *vet;
	int volume = 0;
	float preco = 0;

	for(i = 1;; i++)
	{
		vet = get_pos_nome(p,i);
		volume = get_pos_volume(p,i);
		preco = get_pos_preco(p,i);

		if(vet == NULL || volume == -1 || preco == -1)
			break;

		printf("Bebida %d: ",i);
		printf("%s.\n",vet);
		printf("Volume: %d ml\n", volume);
		printf("Preco: R$%.2f\n\n", preco);
	}
}