#include <stdio.h>
#include <stdlib.h>
#include "LR.h"

int main(){

    Lista lst = NULL;

	int escolha;
	int retorno;
	int sair;
	int i;
	double elem;

    while(1){
        printf("================================\n");
        printf("  Escolha um curso de acao de 1 a 5.\n");
        printf("================================\n");
        printf("[1](Re)inicialize a lista\n");
        printf("[2]Imprimir a lista.\n");
        printf("[3]Inserir elemento na lista.\n");
        printf("[4]Remover elemento da lista.\n");
        printf("[5]Sair.\n");
        
        scanf("%d", &escolha);

        switch(escolha)
        {
            case 1:
				printf("\n-----------(Re)inicializando a lista----------\n");
                retorno = apagar_lista(&lst);
				if(retorno == 0)
					printf("\n------Falha!-----\n");
				else
				{
					lst = cria_lista();
					printf("\n----Sucesso----\n");
				}

                break;
            case 2:
				if(lista_vazia(lst))
					printf("\n-------Lista vazia!-------\n");
				else
				{
					printf("\n--------Imprimindo lista!--------\n");

					i = 1;
					while(obtem_elem(lst,i,&elem))
					{
						printf("%d - %.2lf\n", i, elem);
						i++;
					}
					printf("\n");
				}

                break;
            case 3:
				printf("Qual o elemento que deseja inserir: ");
           		scanf("%lf", &elem);
            	retorno = insere_ord(&lst, elem);
          	  	
				if(retorno == 0)
                	printf("Erro ao inserir.\n");
            	else
                	printf("Elemento inserido.\n");
            	
				break;
            case 4:
               	printf("Elemento que deseja remover: ");
           		scanf("%lf", &elem);
            	retorno = remove_ord(&lst,elem);
            	if(retorno == 0)
                	printf("\nERRO ao remover.\n\n");
             	else
                	printf("\nElemento removido.\n\n");
            
            	break;
			case 5:
                sair = 1;
                break;
            default:
                printf("\nOpção invalida!\n");
        }

        if(sair == 1)
            break;
    }
}