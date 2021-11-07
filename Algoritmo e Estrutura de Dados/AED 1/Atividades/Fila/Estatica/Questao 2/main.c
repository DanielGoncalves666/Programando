#include <stdio.h>
#include <string.h>
#include "TAD.h"

void imprimir(Fila *f);

int main()
{
	Fila f = NULL;
	int mat;
	int falt;
	float med;
	char nome[tam];
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

				printf("\n----Entre com matricula, nome, faltas e a media, a ser inseridos: \n");
				scanf("%d",&mat);
				scanf(" %[^\n]",nome);
				scanf("%d",&falt);
				scanf("%f",&med);
				retorno = inseri_fim(f,mat, nome,falt,med);
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

				retorno = remove_ini(f,&mat,nome,&falt,&med);
				if(retorno == 1)
					printf("\n---- Sucesso! O elemento aluno \nMatricula:%d \nNome: %s \nFaltas: %d \nMedia: %.2f \n\nfoi removido da fila----\n", mat,nome,falt,med);
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
	int mat;
	int falt;
	float med;
	char nome[tam];
	int retorno;

	if(aux == NULL)
	{
		printf("\n----Falha!----\n");
		return;
	}

	printf("\n----Imprimindo fila----\n");
	while(!fila_vazia(*f))
	{
		remove_ini(*f,&mat,nome,&falt,&med);
		printf("Matricula: %d\n",mat);
		printf("Nome: %s\n",nome);
		printf("Faltas: %d\n",falt);
		printf("Media: %.2f\n\n",med);

		retorno = inseri_fim(aux,mat, nome,falt,med);
		if(retorno == 0)
		{
			printf("\n----Falha----\n");
			return;
		}
	}

	liberar(f);
	*f = aux;
}