#include <stdio.h>
#include <stdlib.h>
#include "header_4.h"

void manipular_lista(Lista lst);
void tratamento_escolha(Lista lst, int escolha);

int main(){

    Lista lst = cria_lista();
    Lista lst2 = cria_lista();
    Lista lst3 = cria_lista();

    if(lst == NULL || lst2 == NULL || lst3 == NULL)
    {
        printf("\n----Falha na criação das listas!----\n");
        return 1;
    }

    int escolha = 0;
    int retorno = 0;
    double valor = 0;
    int sair = 0;
    int i;

    while(1){
        printf("================================\n");
        printf("  Escolha um curso de acao de 1 a 5.\n");
        printf("================================\n");
        printf("[1]Manipular lista 1.\n");
        printf("[2]Manipular lista 2.\n");
        printf("[3]Verificar se a lista 1 e 2 são iguais\n");
        printf("[4]Intercalar as 2 lista.\n");
        printf("[5]Sair.\n");
        
        scanf("%d", &escolha);

        switch(escolha)
        {
            case 1:
                manipular_lista(lst);
                
                break;
            case 2:
                manipular_lista(lst2);

                break;
            case 3:
                retorno = iguais(lst,lst2);
                if(retorno == 1)
                    printf("\nIguais.\n\n");
                else
                    printf("\nDiferentes.\n\n");
               
                break;
            case 4:
                lst3 = intercala(lst,lst2);
                if(lst3 == NULL)
                {
                    printf("ERRO.\n");
                    break;
                }

                printf("\nLista intercalada: ");
                if(lista_vazia(lst3))
                    printf("Lista vazia!\n\n");
                else
                {
                    for(i = 1; i<=tamanho(lst3); i++)
                    {
                        obtem_valor_elem(lst3,i, &valor);
                        printf("%.2lf ",valor);
                    }
                    printf("\n\n");
                }

                esvaziar(lst3);

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

void manipular_lista(Lista lst)
{
    int escolha = 0;

    while(1)
    {
        printf("\n\nEscolha uma opcao de 1 a 7\n");
        printf("[1] para imprimir lista.\n");
        printf("[2] para inserir elemento na lista.\n");
        printf("[3] para remover elemento da lista.\n");
        printf("[4] para esvaziar lista.\n");
        printf("[5] para mostrar o maior valor da lista.\n");
        printf("[6] para mostrar o tamanho da lista.\n");
        printf("[7] para voltar.\n");
        scanf("%d", &escolha);

        if(escolha == 7)
            break;

        tratamento_escolha(lst, escolha);
    }
}

void tratamento_escolha(Lista lst, int escolha)
{
    int i = 0;
    int retorno = 0;
    double valor = 0;

    switch(escolha){
        case 1: 
            if(lista_vazia(lst) == 1){
                printf("\nLista Vazia.\n");
                break;
            }

            printf("\nLista: ");
            for(i = 1; i<=tamanho(lst); i++)
            {
                obtem_valor_elem(lst,i,&valor);
                printf("%.2lf ",valor);
            }
            printf("\n\n");
            
            break;
        case 2: 
            printf("Qual o elemento que deseja inserir: ");
            scanf("%lf", &valor);
            retorno = insere_ord(lst, valor);
            if(retorno == 0)
                printf("Erro ao inserir.\n");
            else
                printf("Elemento inserido.\n");
            
            break;
        case 3: 
            printf("Elemento que deseja remover: ");
            scanf("%lf", &valor);
            retorno = remov(lst,valor);
            if(retorno == 0)
                printf("ERRO ao remover.\n");
             else
                printf("Elemento removido.\n");
            
            break;
        case 4: 
            esvaziar(lst);
            printf("\nLista esvaziada!\n");

            break;
        case 5: 
            retorno = maior(lst, &valor);
            
            if(retorno == 0)
                printf("Lista vazia!\n");
            else
                printf("O maior elemento desta lista é %.2lf\n", valor);
            
            break;
        case 6: 
            printf("O tamanho da lista é %d\n", tamanho(lst));
            
            break;
        default:
            printf("Opcao invalida!\n");
    }
}
