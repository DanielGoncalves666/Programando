#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){

    Lista lst = cria_lista();
    Lista lst2 = cria_lista();
    Lista lst3 = cria_lista();

    int lista, escolha,i,r;
    float elem;

    while(1){
        do{
            printf("================================\n");
            printf("  Escolha um curso de acao de 1 a 4.\n");
            printf("================================\n");
            printf("[1]Manipular lista 1.\n");
            printf("[2]Manipular lista 2.\n");
            printf("[3]Intercalar as 2 lista.\n");
            printf("[4]Sair.\n");
            scanf("%d", &lista);
        }while(lista < 1 || lista > 4);


        if(lista == 1){
            do{
                printf("\n\nEscolha uma opcao de 1 a 7\n");
                printf("[1] para imprimir lista.\n");
                printf("[2] para inserir elemento na lista.\n");
                printf("[3] para remover elemento da lista.\n");
                printf("[4]para verficar se essa lista 1 igual a lista 2.\n");
                printf("[5] para esvaziar lista.\n");
                printf("[6] para mostrar o maior valor da lista.\n");
                printf("[7] para mostrar o tamanho da lista.\n");
                scanf("%d", &escolha);
            }while(escolha < 1 || escolha > 7);

            switch(escolha){
                case 1: if(lista_vazia(lst) == 1){
                            printf("Lista Vazia.\n");
                            break;
                        }
                        printf("\nLista: ");
                        for(i = 1;i<=tamanho(lst);i++)
                            printf("%.4f ", obtem_valor(lst,i));
                        break;

                case 2: printf("Elemento que deseja inserir: ");
                        scanf("%f", &elem);
                        r = insere(&lst,elem);
                        if(r != 1)
                            printf("ERRO.\n");
                        else
                            printf("Elemento inserido.\n");
                        break;

                case 3: printf("Elemento que deseja remover: ");
                        scanf("%f", &elem);
                        r = remov(&lst,elem);
                        if(r != 1)
                            printf("ERRO.\n");
                        else
                            printf("Elemento removido.\n");
                        break;

                case 4: r = iguais(lst,lst2);
                        if(r != 0)
                            printf("Iguais.\n");
                        else
                            printf("Diferentes.\n");
                        break;

                case 5: r= esvaziar(&lst);
                        if(r == 0)
                            printf("Essa lista j%c est%c vazia.\n", 160,160);
                        else
                            printf("Lista foi esvaziada com sucesso.\n");
                        break;

                case 6: if(lista_vazia(lst) == 1)
                            printf("Essa lista est%c vazia.\n", 160);
                        else
                            printf("O maior elemento desta lista %c: %f", 130,maior(lst));
                        break;

                case 7: printf("O tamanho da lista %c: %d",130, tamanho(lst));
            }

        }

         if(lista == 2){
            do{
                printf("\n\nEscolha uma opc%co de 1 a 7\n", 198);
                printf("1_Imprimir lista.\n");
                printf("2_Inserir elemento na lista.\n");
                printf("3_Remover elemento da lista.\n");
                printf("4_Verificar se essa lista %c igual a outra lista.\n", 130);
                printf("5_Esvaziar lista.\n");
                printf("6_Maior valor da lista.\n");
                printf("7_Tamanho da lista.\n");
                printf("Escolha: ");
                scanf("%d", &escolha);
            }while(escolha < 1 || escolha > 7);

            switch(escolha){
                case 1: if(lista_vazia(lst2) == 1){
                            printf("Lista Vazia.\n");
                            break;
                        }
                        printf("\nLista: ");
                        for(i = 1;i<=tamanho(lst2);i++)
                            printf("%.4f ", obtem_valor(lst2,i));
                        break;

                case 2: printf("Elemento que deseja inserir: ");
                        scanf("%f", &elem);
                        r = insere(&lst2,elem);
                        if(r != 1)
                            printf("Insercao falhou.\n");
                        else
                            printf("Insercao feita com sucesso.\n");
                        break;

                case 3: printf("Elemento que deseja remover: ");
                        scanf("%f", &elem);
                        r = remov(&lst2,elem);
                        if(r != 1)
                            printf("ERRO");
                        else
                            printf("Remocao feita com sucesso.\n");
                        break;

                case 4: r = iguais(lst2, lst);
                        if(r != 0)
                            printf("Iguais.\n");
                        else
                            printf("Diferentes.\n");
                        break;

                case 5: r = esvaziar(&lst2);
                        if(r == 0)
                            printf("Lista Vazia.\n");
                        else
                            printf("Lista Vazia.\n");
                        break;

                case 6: if(lista_vazia(lst2) == 1)
                            printf("Essa lista esta vazia.\n");
                        else
                            printf("O maior elemento desta lista eh: %f", maior(lst2));
                        break;

                case 7: printf("O tamanho da lista eh: %d", tamanho(lst2));
            }

        }

        if(lista == 3){
            lst3 = intercala(lst,lst2);
            printf("Lista intercalada: ");
            for(i = 1; i <= tamanho(lst3);i++)
                printf("%.4f ", obtem_valor(lst3,i));

        }

        if(lista == 4)
                return 0;

    }
}
