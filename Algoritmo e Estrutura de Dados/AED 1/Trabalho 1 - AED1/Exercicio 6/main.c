#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){

    Lista lst = criaLista();
    Lista lst2 = criaLista();

    int escolha, i, elem, result;

    while(1){
        do{
            printf("\nEscolha uma op%c%co de 1 %c 9.\n",135,198,133);
            printf("1_Imprimir lista.\n");
            printf("2_Inserir elemento na lista.\n");
            printf("3_Verificar tamanho da lista.\n");
            printf("4_Esvaziar a lista.\n");
            printf("5_Remover maior elemento da lista.\n");
            printf("6_Inverter a lista.\n");
            printf("7_Nova lista com primos.\n");
            printf("8_Remover todas as ocorr%cncias de um elemento na lista.\n", 136);
            printf("9_Sair.\n");
            printf("Escolha: ");
            scanf("%d", &escolha);
        }while(escolha < 1 || escolha > 9);

        switch(escolha){
        case 1:

            if(listaVazia(lst) == 1)
                printf("A lista est%c vazia.\n", 160);
            else{
                i = 1;
                printf("Lista: ");
                while(i <= tamanho(lst)){
                    printf("%d ", obtem_valor(lst,i));
                    i++;}
                printf("\n");
            }
            break;

        case 2:
            printf("Elemento que deseja inserir: ");
            scanf("%d", &elem);
            result = insereElem(&lst, elem);
            if(result != 1)
                printf("Inser%c%co falhou.\n",135,198);
            else
                printf("Inser%c%co feita com sucesso.\n",135,198);
            break;

        case 3:
            printf("O tamanho da lista %c: %d\n", 130, tamanho(lst));
            break;

        case 4:
            result = esvaziar(&lst);
            if(result == 0)
                printf("A lista j%c est%c vazia.\n",160,160);
            else
                printf("Lista esvaziada com sucesso.\n");
            break;

        case 5:
            result = removeMaior(&lst);
            if(result != 1)
                printf("Remo%c%co falhou.\n", 135,198);
            else
                printf("Remo%c%co feita com sucesso.\n",135,198);
            break;

        case 6:
            lst2 = inverter(lst);
            if(listaVazia(lst2) == 1)
                printf("A lista est%c vazia.\n", 160);
            else{
                i = 1;
                printf("Lista Invertida: ");
                while(i <= tamanho(lst2)){
                    printf("%d ", obtem_valor(lst2,i));
                    i++;}
                printf("\n");
            }
            break;

        case 7:
            lst2 = primos(lst);
            if(listaVazia(lst2) == 1)
                printf("A lista est%c vazia.\n", 160);
            else{
                i = 1;
                printf("Lista Invertida: ");
                while(i <= tamanho(lst2)){
                    printf("%d ", obtem_valor(lst2,i));
                    i++;}
                printf("\n");
            }
            break;

        case 8:
            printf("Elemento que dejesa remover: ");
            scanf("%d", &elem);
            result = removeTodos(&lst,elem);
            if(result == 0)
                printf("Remo%c%co falhou.\n", 135,198);
            else
                printf("Remo%c%co feita com sucesso.\n",135,198);
            break;

        case 9: return 1;
        }
   }
}
