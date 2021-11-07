#include <stdio.h>
#include <stdlib.h>
#include "Trabalho-ex2.h"

/*
O programa tem como objetivo implementar o TAD lista ordenadade crescente de caracteres usando alocação estática/sequencial.
O qual possue as funções de remover pares, retornar o menor elemento da lista, retornar o tamanho da lista, esvaziar a lista, intercalar a lista entre outros.

Alunos:
Henrique Braga
Arthur Rezende
Lorenzo Machado
Daniel Gonçalves
2021

*/

void imprimir_lista(Lista l)
{
    if(lista_vazia(l))
    {
            printf("Lista vazia\n");
            return;
    }

    int i = 0;
    for(i = 0; i < tamanho(l); i++)
    {
       printf("%c ", get_posicao(l,i));
    }
    printf("\n");
}

int main()
{
    int Num = 0;
    int Y = 0;
    Lista l;
    do
    {
        do
        {
            printf("\nDigite [1] caso queira criar uma nova lista.\n");
            printf("Digite [2] caso queira inserir um elemento.\n");
            printf("Digite [3] caso queira remover um elemento.\n");
            printf("Digite [4] caso queira imprimir os elementos presentes da lista.\n");
            printf("Digite [5] caso queira remover os elementos pares da lista.\n");
            printf("Digite [6] caso queira ver o menor elemento inserido na lista.\n");
            printf("Digite [7] caso queira ver o tamanho da lista.\n");
            printf("Digite [8] caso queira esvaziar a lista.\n");
            printf("Digite [9] caso queira inserir outra lista e intercalar com a lista atual.\n");
            printf("Digite [10] caso deseje encerrar o programa.\n\n");

            fflush(stdin);
            scanf("%d", &Num);

            if(Num < 1 || Num > 10)
            {
                printf("\nO numero digitado deve estar entre 1 e 10.\n");
                printf("O programa foi encerrado!!!\n");
                return 0;
            }
        }

        while (Num < 1 || Num > 10);
        if (Num == 10)
        {
            return 0;
        }

        if (Num != 1 && Y == 0)
        {
                printf("\n");
                printf("Primeiro a lista deve ser criada.\n");
                printf("O sistema ira ser encerrado!!!");
                break;
        }

        if (Num == 1)
        {
            printf("\n");
            if(Y > 0)
            {
                l = limpa_lista(l);
                Y = 0;
                printf("A antiga lista foi apagada e uma nova lista sera criada\n");
            }
            printf("A lista foi criada com sucesso!\n");
            l = criar_lista();

            Y++;
        }

        if(Num == 2)
        {
            printf("\n");
            char elem;
            printf("Digite o numero que sera inserido na lista:\n");
            fflush(stdin);
            scanf("%c", &elem);
            if(lista_cheia(l))
            {
                printf("Elemento nao foi inserido, a lista esta cheia.\n");
                printf("Remova um elemento, para acrestar outro.\n");
            }
            else
            {
                l = insere_ord(l, elem);
                printf("Elemento inserido com sucesso!\n");
            }
        }

        if(Num == 3)
        {
            printf("\n");
            char elem;
            printf("Insira o elemento:\n");
            fflush(stdin);
            scanf("%c", &elem);
            if(lista_vazia(l))
            {
                printf("A lista esta vazia, insira um elemento.\n");
            }
            else
            {
                if(contem(l, elem) == 0)
                {
                    printf("Elemento nao esta dentro da lista!\n");
                }
                else
                {
                    l = remove_elem(l, elem);
                    printf("Elemento removido com sucesso!\n");
                }
            }
        }

        if(Num == 4)
        {
            imprimir_lista(l);
        }

        if(Num == 5)
        {
            l = remove_pares(l);
            printf("Elementos pares removidos com sucesso!\n");
        }

        if(Num == 6)
        {
            if(lista_vazia(l))
            {
                printf("A lista esta vazia, nao eh possivel encontrar o menor elemento.\n");
            }
            else
                printf("O menor elementos da lista eh %c\n", menor(l));
        }

        if(Num == 7)
        {
            printf("O tamanho da lista eh %d\n", tamanho(l));
        }

        if(Num == 8)
        {
            l =  limpa_lista(l);
            printf("A lista foi esvaziada com sucesso!\n");
        }

        if(Num == 9)
        {
            int parar = 0;
            Lista l2 = criar_lista();
            while(parar == 0)
            {
                char c;
                printf("Digite um elemento para inserir na lista(insira [0] para finalizar a insercao de elementos.)\n\n");
                fflush(stdin);
                scanf("%c", &c);

                if(c == '0')
                    parar = 1;

                else
                {
                    l2 = insere_ord(l2, c);
                    printf("Elemento inserido com sucesso!\n");
                }
            }
            Lista l3 = intercalar(l,l2);
            imprimir_lista(l3);
        }
    }

    while(Num != 10);

    return 0;
}


