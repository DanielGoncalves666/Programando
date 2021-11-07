#include <stdio.h>
#include "TAD.h"

int main()
{
	int escolha, retorno;
	char elemento;
	Deque deq = NULL, aux;

	while(1)
	{
		printf("\n----- Escolha uma das opções: -----\n");
		printf("1 - Criar um deque.\n");
		printf("2 - Inserir elemento no inicio.\n");
		printf("3 - Remover elemento do inicio.\n");
		printf("4 - Inserir elemento no fim.\n");
		printf("5 - Remover elemento do fim.\n");
		printf("6 - Imprimir deque.\n");
		printf("7 - Liberar deque.\n");
		printf("8 - Encerrar.\n");
		scanf("%d",&escolha);

		if(escolha == 8)
			break;

		if(escolha == 1)
		{
			if(deq == NULL)
			{
				deq = cria_deque();
				if(deq == NULL)
					printf("\n ----- Falha na criação do deque! -----\n");
				else
					printf("\n ----- Deque Criado! ----- \n");
				
				continue;
			}
			else
			{
				printf("\n ----- O deque já existe! ----- \n");
				continue;
			}
		}
		else
		{
			if(deq == NULL)
			{
				printf("\n----- Falha! Apenas a opcao 1 é permitida quando o deque não existe! ----- \n");
				continue;
			}
		}

		switch(escolha)
		{
			case 2:
				printf("\n ----- Entre com o caractere a ser inserido no inicio.-----\n");
				scanf(" %c",&elemento);

				retorno = insere_inicio(deq,elemento);
				if(!retorno)
					printf("\n----- Falha na insercao!  -----\n");
				
				break;
			case 3:
				retorno = remove_inicio(deq,&elemento);

				if(!retorno)
					printf("\n ----- Falha na remocao! Deque vazio! -----\n");
				else
					printf("\n----- Elemento removido do inicio: %c ------\n",elemento);	

				break;
			case 4:
				printf("\n ----- Entre com o caractere a ser inserido no final. -----\n");
				scanf(" %c",&elemento);

				retorno = insere_final(deq,elemento);
				if(!retorno)
					printf("\n----- Falha na insercao! -----\n");
				
				break;
			case 5:
				retorno = remove_final(deq,&elemento);

				if(!retorno)
					printf("\n ----- Falha na remocao! Deque vazio! -----\n");
				else
					printf("\n----- Elemento removido do fim: %c ------\n",elemento);	

				break;
			case 6:
				//a maneira mais eficiente de se fazer isso seria removendo os elementos e ja colocando eles de volta no final da fila, mas como não temos uma função que retorne o tamanho do deque, isso não é possível.

				if(deque_vazio(deq))
						printf("\n ----- Deque vazio! -----\n");
				else
				{
					aux = cria_deque();
					if(aux == NULL)
						printf("\n----- Falha! -----\n");
					else
					{
						printf("\n ----- Imprimindo Deque -----\n");
						while(!deque_vazio(deq))
						{
							remove_inicio(deq,&elemento);
							printf("%10c\n",elemento);
							insere_final(aux,elemento);
						}

						while(!deque_vazio(aux))
						{
							remove_inicio(aux,&elemento);
							insere_final(deq,elemento);
						}
					}

					apagar_deque(&aux);				
				}
				
				break;
			case 7:
				apagar_deque(&deq);
				printf("\n----- Deque liberado! -----\n");

				break;
			default:
				printf("\n----- Opcao Invalida! -----\n");
				break;
		}
	}

	apagar_deque(&deq);

	return (0);
}