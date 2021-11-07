#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Trabalho-ex7.h"
#define MAX 30

void imprime_lista(Lista lst)
{
    if (lista_vazia(lst) == 1)
    {
        printf("\n*** LISTA VAZIA ***\n\n");
        return;
    }
    printf("\n {");
    int i;
    for (i=1; ; i++)
    {
        char name[MAX];
        if (get_nome(lst,i, name) == 0)
        {
            break;
        }
        printf(" %s ", name);
    }
    printf("}\nExistem %d elementos na lista.\n\n", i-1);
}

int main()
{
    int qnt=0, x;
    char nome[20];
    char opcao[4];
    Lista lst;
    printf("[ ---O PROBLEMA DE JOSEPHUS--- ]\n");
    do
    {
        printf("\nInsira o nome de um soldado: ");
        fflush(stdin);
        gets(nome);
        if(insere_elem(&lst, nome)==1)
        {
            printf("\nO soldado foi inserido com sucesso!\n\n");
            qnt++;
        }
        else
            printf("O soldado nao foi inserido!\n");

        printf("Gostaria de inserir outro soldado?[Sim ou Nao]: ");
        fflush(stdin);
        scanf("%s", opcao);
        if(strcmp(opcao, "Sim") != 0 && strcmp(opcao, "sim") != 0 && strcmp(opcao, "s") != 0 && strcmp(opcao, "S") != 0 && strcmp(opcao, "SIM") != 0 && strcmp(opcao, "Nao") != 0 && strcmp(opcao, "nao")!= 0 && strcmp(opcao, "n") != 0 && strcmp(opcao, "N") != 0 && strcmp(opcao, "NAO") != 0)
        {
            fprintf(stderr, "Erro: Opcao invalida\n");
            printf("O programa sera finalizado\n");
            return 5;
        }
    }
    while(strcmp(opcao, "Sim") == 0 || strcmp(opcao, "sim") == 0 || strcmp(opcao, "s") == 0 || strcmp(opcao, "S") == 0 || strcmp(opcao, "SIM") == 0);

    printf("\nQual a posicao inicial da contagem que deseja comecar ?\n");
    printf("[1]Iniciar a contagem a partir do primeiro soldado da lista\n");
    printf("[2]Iniciar a contagem a partir de uma posicao sorteada aleatoriamente da lista\n");
    printf("[3]Iniciar a contagem a partir de um soldado especifico\n");

    do
    {
        printf("Digite a opcao: ");
        scanf("%d", &x);
        if(x!=1 && x!=2 && x!=3)
            printf("Opcao invalida!");
    }
    while(x!=1 && x!=2 && x!=3);

    if(x==1)
    {
        escolha_pos(&lst, 2, nome);
        printf("\nA contagem ira ser iniciada a partir do soldado %s!\n", nome);
    }

    if(x==2)
    {
        srand(time(NULL));
        escolha_pos(&lst, (rand()%qnt)+1, nome);
        printf("\nA contagem ira ser iniciada a partir do soldado %s!\n", nome);
    }

    if(x==3)
    {
        int y;
        printf("\nDeseja iniciar a contagem a partir de qual soldado ?\n");
        do
        {
            printf("Nome do soldado: ");
            fflush(stdin);
            gets(nome);
            y = escolha_nome(&lst, nome);
            if(y==1)
                printf("A contagem ira ser iniciada a partir do soldado %s!\n", nome);
            else
            {
                printf("O nome do soldado inserido %s nao existe na lista!\n", nome);
                printf("Por favor insira um soldado valido!\n\n");
            }
        }
        while(y!=1);
    }

    int num;
    srand(time(NULL));
    num=(rand()%qnt)+1;
    printf("\nO numero sorteado foi: %d\n\n", num);

    do
    {
        x=remove_pos(&lst, num, qnt, nome);
        qnt--;

        if(x==1)
        {
            printf("Soldado eliminado foi: %s\n", nome);
            printf("\nSoldados restantes:");
            imprime_lista(lst);
            printf("---- Pressione ENTER para continuar. ----\n");
            fflush(stdin);
            getchar();
        }

        if(x==-1)
        {
            printf("\nO soldado sobrevivente foi: %s\n", nome);
            printf("\nFim do jogo!\n");
        }
    }
    while(x!=-1);
    return 0;
}

