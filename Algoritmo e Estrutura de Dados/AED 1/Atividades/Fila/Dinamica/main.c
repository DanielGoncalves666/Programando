#include <stdio.h>
#include <string.h>
#include "TAD.h"

void imprimir(Fila *f);

int main()
{
	Fila f = NULL;
	char nome[tam];
	int volume;
	float preco;
	int escolha;
	int retorno;

	while(1)
	{
		printf("\n----Entre com a opção desejada:----");
		printf("\n1 - Criar fila.");
		printf("\n2 - Apagar fila.");
		printf("\n3 - Esvaziar fila.");
		printf("\n4 - Inserir elemento.");
		printf("\n5 - Remover elemento.");
		printf("\n6 - Imprimir fila.");
		printf("\n7 - Sair.\n");
		scanf("%d",&escolha);

		if(escolha == 7)
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
					printf("\n---- Fila inexistente.----\n");
				}
				else
				{
					apaga_fila(&f);
					printf("\n----Fila apagada!----\n");
				}

				break;
			case 3:
				retorno = esvazia_fila(f);
				if(retorno == 0)
					printf("\n----Fila inexistente----\n");
				else
					printf("\n----Fila esvaziada----\n");

				break;
			case 4:
				if(f == NULL)
				{
					printf("\n----Fila inexistente----\n");
					break;
				}

				printf("\n----Entre com matricula, nome, faltas e a media, a ser inseridos: \n");
				scanf("%d",&volume);
				scanf(" %[^\n]",nome);
				scanf("%f",&preco);
				retorno = insere_fim(f,volume,nome,preco);
				if(retorno == 1)
					printf("\n----Sucesso----\n");
				else
					printf("\n----Fila cheia!----\n");

				break;
			case 5:
				if(f == NULL)
				{
					printf("\n----Fila inexistente----\n");
					break;
				}

				retorno = remove_ini(f,&volume,nome,&preco);
				if(retorno == 1)
					printf("\n---- Sucesso! O elemento aluno \nVolume:%d \nNome: %s \nPreco: %.2f \n\nfoi removido da fila----\n", volume,nome,preco);
				else	
					printf("\n---- Fila vazia!----\n");

				break;
			case 6:
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
	char nome[tam];
	int volume;
	float preco;
	int retorno;

	if(aux == NULL)
	{
		printf("\n----Falha!----\n");
		return;
	}

	printf("\n----Imprimindo fila----\n");
	while(!fila_vazia(*f))
	{
		remove_ini(*f,&volume,nome,&preco);
		printf("Volume: %d\n",volume);
		printf("Nome: %s\n",nome);
		printf("Preco: %.2f\n\n",preco);

		retorno = insere_fim(aux,volume,nome,preco);
		if(retorno == 0)
		{
			printf("\n----Falha----\n");
			return;
		}
	}

	apaga_fila(f);
	*f = aux;
}