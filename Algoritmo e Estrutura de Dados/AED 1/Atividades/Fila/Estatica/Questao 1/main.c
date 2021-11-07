#include <stdio.h>
#include <string.h>
#include "TAD.h"

void imprimir(Fila *f);

int main()
{
	Fila f = NULL;
	char string[tam];
	int escolha;
	int retorno;

	while(1)
	{
		printf("\n----Entre com a opção desejada:----");
		printf("\n1 - Criar fila.");
		printf("\n2 - Inserir elemento.");
		printf("\n3 - Remover elemento.");
		printf("\n4 - Imprimir fila.");
		printf("\n5 - Sair.\n");
		scanf("%d",&escolha);

		if(escolha == 5)
			break;

		switch(escolha)
		{
			case 1:
				if(f == NULL)
				{
					f = cria_fila();
					if(f == NULL)
						printf("\n----Memória insuficiente----\n");
					else
						printf("\n----Fila Criada----\n");
				}
				else
				{
					printf("\n---- Fila já existente.----\n");
				}

				break;
			case 2:
				if(f == NULL)
				{
					printf("\n----Fila inexistente----\n");
					break;
				}

				printf("\n----Entre com o elemento a ser inserido: ");
				scanf(" %10s",string);
				retorno = inseri_fim(f,string);
				if(retorno == 1)
					printf("\n----Sucesso----\n");
				else
					printf("\n----Fila cheia!----\n");

				break;
			case 3:
				if(f == NULL)
				{
					printf("\n----Fila inexistente----\n");
					break;
				}

				retorno = remove_ini(f,string);
				if(retorno == 1)
					printf("\n---- Sucesso! O elemento %s foi removido da fila----\n", string);
				else	
					printf("\n---- Fila vazia!----\n");

				break;
			case 4:
				if(f == NULL)
				{
					printf("\n----Fila inexistente----\n");
					break;
				}

				imprimir(&f);
				break;
			default:
				printf("\n----Opção Inválida----\n");
				break;
		}
	}


	return (0);
}

void imprimir(Fila *f)
{
	Fila aux = cria_fila();
	char string[tam];
	int retorno;

	if(aux == NULL)
	{
		printf("\n----Falha!----\n");
		return;
	}

	printf("\n----Imprimindo fila----\n");
	while(!fila_vazia(*f))
	{
		remove_ini(*f,string);
		printf("%s\n",string);

		retorno = inseri_fim(aux,string);
		if(retorno == 0)
		{
			printf("\n----Falha----\n");
			return;
		}
	}

	liberar(f);
	*f = aux;
}