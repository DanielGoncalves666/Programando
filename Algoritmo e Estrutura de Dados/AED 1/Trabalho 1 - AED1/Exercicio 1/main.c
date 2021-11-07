#include <stdio.h>
#include "TADListaEstSeq_01.h"

void imprime_lista(Lista L) {

    if (lista_vazia(L) == 1) {
        printf("\n*** LISTA VAZIA ***\n\n");
        return;
    }

    printf("\nLista: {");
    int i;
    for (i=1; ; i++) {
        float N;
        if (get_elem(L,i, &N) == 0) {
            break;
        }
        printf(" %f ", N);
    }
    printf("}\nExistem %d elementos na lista.\n\n", i-1);
}

int main()
{
    int swi, sinal, sinal2 = 0; // sinal contabiliza a qtde de reinicializacoes da lista
    Lista L;
    Lista L2;
    Lista L3;
    do {
        do{
            // Obtem opcao do usuario
            printf("\nOpcoes:\n");
            printf("[1] Criar uma lista\n");
            printf("[2] Inserir um elemento na lista\n");
            printf("[3] Remover um elemento da lista\n");
            printf("[4] Inverter a lista\n");
            printf("[5] Imprimir a lista\n");
            printf("[6] Imprimir o tamanho da lista\n");
            printf("[7] Imprimir o maior elemento da lista\n");
            printf("[8] Remover todos os numeros impares da lista\n");
            printf("[9] Remover todos elementos da lista\n");
            printf("[10] Concatenar lista com uma nova\n");
            printf("[11] Sair do sistema\n");
            printf("\nQual opcao deseja realizar? ");
            scanf("%d", &swi);
            setbuf(stdin, NULL);
            if (swi < 1 || swi > 11)
                printf("\nOpcao invalida...Somente existem essas opcoes:\n");

        } while (swi < 1 || swi > 11);

        if (swi == 11)
            break;
        else if (swi != 1 && sinal == 0) {
            printf("\nAntes de realizar operacoes, crie uma lista.\n\n");
            continue;
        }

        switch (swi) {
            case 1: {
                if (sinal) { // Verifica se a lista já existe
                    libera_lista(&L);
                }

                L = cria_lista();
                if (L == NULL) {
                    printf("\nFalha na alocacao...\n\n");
                    return -1;
                }

                if (sinal)
                    printf("\nReinicializacao da lista pela %d vez...\n\n", sinal);
                else
                    printf("\nCriacao bem sucessida!\n\n");

                sinal++;

                break;
            }
            case 2: {
                float N;
                printf("Digite um numero a ser inserido na lista: \n");
                scanf("%f", &N);
                if (insere_elem(L, N) == 0)
                    printf("\nA lista esta cheia! O elemento %f nao foi incluido.\n\n", N);
                else
                    printf("\nO elemento %f foi incluido com sucesso!\n\n", N);

                break;
            }
            case 3: {
                float N;

                printf("\nDigite o elemento a ser removido da lista: ");
                scanf("%f", &N);

                if (remove_elem(L, N) == 0) {
                    if (lista_vazia(L) == 1)
                        printf("\nLista vazia!\n\n");
                    else
                        printf("\nO elemento %f nao esta na lista.\n\n", N);
                }
                else
                    printf("\nO elemento %f foi removido com sucesso!\n\n", N);

                break;
            }
            case 4: {
                L = inverter(L);
                break;
            }
            case 5:{
                imprime_lista(L);
                break;
            }
            case 6:{
                int tam = 0;
                tam = tamanho(L);
                printf("\nTamanho da lista eh%d\n", tam);
                break;
            }
            case 7:{
                float maior = 0;
                if(retorna_maior(L, &maior) == 0)
                    printf("\nOcorreu um erro...Verifique se a lista nao esta vazia ou se foi criada corretamente\n");
                else
                    printf("\nO maior elemento da lista eh: %f ", maior);
                break;
            }
            case 8:{
                if(remove_impar(L) == 0)
                    printf("\nOcorreu um erro...Verifique se a lista nao esta vazia ou se foi criada corretamente.\n");
                else
                    printf("\nNumeros impares removidos com sucesso!\n");
                break;

            }
            case 9:{
                if(esvaziar(L) == 0)
                   printf("\nOcorreu um erro...Verifique se a lista nao esta vazia ou se foi criada corretamente\n");
                else
                    printf("\nLista esvaziada com sucesso\n");
                break;
            }
            case 10:{
                if(sinal2 > 0){
                    printf("\nA fim de repetir o processo de concatenacao, as novas listas foram apagadas e novas serao criadas");
                    libera_lista(&L2);
                    libera_lista(&L3);
                }

                printf("\nEntao, precisamos criar a segunda lista para concatenar com a primeira...\n");
                L2 = cria_lista();
                if (L2 == NULL){
                    printf("\nFalha na alocacao...\n\n");
                    return -1;
                }
                int aux = 0;
                int aux2 = 0;
                do{
                    do{
                        printf("\nEscolha:\n");
                        printf("[1] Inserir um elemento na nova lista\n");
                        printf("[2] Remover um elemento da nova lista\n");
                        printf("[3] Imprimir a nova lista\n");
                        printf("[4] Finalizar a criacao da nova lista e prosseguir para concatenar\n");
                        fflush(stdin);
                        scanf("%d", &aux);
                        if (aux < 1 || aux > 4)
                            printf("\nOpcao invalida!\nEscolha alguma das abaixo:\n");
                    }while (aux < 1 || aux > 4);

                    if(aux == 1){
                            float Num1;
                            printf("Digite um numero a ser inserido na lista: \n");
                            fflush(stdin);
                            scanf("%f", &Num1);
                            if (insere_elem(L2, Num1) == 0)
                                printf("\nA lista ja estah cheia! Nao foi possivel incluir o elemento %f.\n\n", Num1);
                            else{
                                printf("\nO elemento %f foi incluido com sucesso!\n\n", Num1);
                                aux2++;
                            }
                        }
                    if(aux == 2){
                        float Num;

                        printf("\nDigite o elemento a ser removido da lista: ");
                        fflush(stdin);
                        scanf("%f", &Num);
                        if (remove_elem(L2, Num) == 0) {
                            if (lista_vazia(L2) == 1)
                                printf("\nA lista estah vazia!\n\n");
                            else
                                printf("\nNao existe o elemento %f na lista.\n\n", Num);
                        }
                        else
                            printf("\nO elemento %f foi removido com sucesso!\n\n", Num);

                        }
                    if(aux == 3){
                        imprime_lista(L2);
                    }
                    if(aux == 4){
                        if(lista_vazia(L2) == 1){
                            printf("\nA lista estah vazia!\n\n");
                            printf("Insira ao menos um elemento antes de prosseguir\n");
                        }
                        else{
                            L3 = concatenar(L, L2);
                            if(L3 == NULL){
                                printf("\nErro na concatenacao...verifique se o tamanho somado das duas listas nao ultrapassa 20(tamanho maximo para uma lista).\n");
                            }
                        }
                    }
                }while(aux != 4 || aux2 < 1);
                if(L3 != NULL){
                    printf("A lista criada a partir da concatenacao da primeira com a segunda eh:\n");
                    imprime_lista(L3);
                }
                sinal2++;
                break;
            }
        }
    }while (swi != 11);
    printf("\nEncerrando o programa...\n");
    return 0;
}
