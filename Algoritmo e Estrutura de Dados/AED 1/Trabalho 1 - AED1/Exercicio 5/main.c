#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){

    Lista lst = criaLista();
    int escolha,result,pos;
    char elem;

    while(1){
        do{
            printf("\nEscolha uma op%c%co de 1 %c 9\n",135,198,133);
            printf("1_Inserir no inicio da lista.\n");
            printf("2_Inserir em uma posi%c%co determinada da lista.\n", 135,198);
            printf("3_Remover do fim da lista.\n");
            printf("4_Remover de uma posi%c%co determinada da lista.\n", 135,198);
            printf("5_Verificar tamanho da lista.\n");
            printf("6_Imprimir a lista.\n");
            printf("7_Sair.\n");
            printf("Escolha: ");
            scanf("%d", &escolha);
        }while(escolha < 0 || escolha > 8);


        switch(escolha){

        case 1:printf("Elemento que deseja inserir: ");
                setbuf(stdin,NULL);
                scanf("%c", &elem);
                result = insereInicio(&lst,elem);
                if(result != 1)
                    printf("Inser%c%co falhou.\n",135,198);
                else
                    printf("Inser%c%co feita com sucesso.\n", 135,198);
               break;

        case 2: printf("Elemento e a posi%c%co que deseja inserir: ", 135,198);
                setbuf(stdin,NULL);
                scanf("%c %d", &elem, &pos);
                result = inserePos(&lst,pos,elem);
                if(result != 1)
                    printf("Inser%c%co falhou.\n",135,198);
                else
                    printf("Inser%c%co feita com sucesso.\n", 135,198);
               break;

        case 3: result = remove_final(&lst, &elem);
                if(result == 1)
                    printf("Elemento removido: %c.\n", elem);
                else
                    printf("Erro: nada foi removido.\n");
                break;

        case 4: printf("Posi%c%co que deseja remover: ", 135,198);
                scanf("%d", &pos);
                result = removePos(&lst,pos);
                if(result == 1)
                    printf("Elemento removido com sucesso.\n");
                else
                    printf("Erro: nada foi removido.\n");
                break;

        case 5: printf("O tamanho da lista %c: %d.\n", 130,tamanho(lst));
                break;

        case 6: imprimeLista(lst);
                break;

        case 7: return 0;

        }
    }
}
