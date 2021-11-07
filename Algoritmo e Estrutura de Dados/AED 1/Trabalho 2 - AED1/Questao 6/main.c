#include <stdio.h>
#include <string.h>
#include "TAD.h"

int main()
{
    int escolha;
    int retorno;
    Fila fpd = NULL;
    Fila aux = cria_fp();

    if(aux == NULL)
    {
        printf("\n ----- Falha! ----- \n");
        return 0;
    }

    char nome[QTD];
    int idade;
    int orgao;
    int gravidade;

    char buffer;

    while(1)
    {
        printf("\n----- Entre com uma das opcoes abaixo: -----\n");
        printf("1 - Criar uma Fila de prioridade para pacientes.\n");
        printf("2 - Inserir paciente.\n");
        printf("3 - Remover paciente do inicio.\n");
        printf("4 - Esvaziar fila.\n");
        printf("5 - Imprimir.\n");
        printf("6 - Sair.\n");
        scanf("%d",&escolha);

        if(escolha == 6)
            break;

        if(escolha == 1)
        {
            if(fpd == NULL)
            {
                fpd = cria_fp();
                printf("\n ----- Fila criada com sucesso! ----- \n");
                continue;
            }
            else
            {
                printf("\n ----- A fila já existe! ------\n");
                continue;
            }
        }
        else
        {
            if(fpd == NULL)
            {
                printf("\n ----- Nenhuma fila existe! ----- \n");
                continue;
            }
        }

        switch(escolha)
        {
            case 2:
                printf("\nDigite o nome do paciente\n");
                scanf(" %30[^\n]",nome);

                while ((buffer = getchar()) != '\n' && buffer != EOF);

                printf("\nDigite a idade\n");
                scanf("%d",&idade);

                printf("\nDigite o orgao necessitado (1 - coração, 2 - fígado, 3 – rins, 4 – cornea)\n");
                scanf("%d",&orgao);

                if(orgao < 1 || orgao > 4)
                {
                    printf("\n ----- Entrada Invalida! ----- \n");
                    break;
                }

                printf("\nDigite a gravidade\n");
                scanf("%d",&gravidade);

                retorno = insere_ord(fpd,nome,idade,orgao,gravidade);

                if(retorno)
                {
                    printf("\n ----- Paciente inserido ----- \n");
                }
                else
                {
                    printf("\n ----- Fila cheia! ----- \n");
                }

                break;
        
            case 3:
                retorno = remove_ini(fpd,nome,&idade,&orgao,&gravidade);

                if(retorno)
                    printf("\n Paciente removido:\n Nome: %s\nIdade: %d\nOrgao: %d\nGravidade: %d\n",nome,idade,orgao,gravidade);
                else
                    printf("\n ----- Fila vazia ----- \n");
                
                break;
        
            case 4:
                esvazia_fp(fpd);
                printf("\n ----- Fila esvaziada! ----- \n");

                break;
        
            case 5:

                if(fp_vazia(fpd))
                {
                    printf("\n ----- Fila vazia! ----- \n");
                    break;
                }

                while(!fp_vazia(fpd))
                {
                    remove_ini(fpd, nome, &idade, &orgao, &gravidade);
                    printf("\nNome = %s\nIdade = %d\nOrgao Desejado = %d\nGravidade = %d\n",nome,idade,orgao,gravidade);
                    insere_ord(aux,nome,idade,orgao,gravidade);
                }

                while(!fp_vazia(aux))
                {
                    remove_ini(aux, nome, &idade, &orgao, &gravidade);
                    insere_ord(fpd,nome,idade,orgao,gravidade);
                }

                esvazia_fp(aux);

                break;
            
            default:
                printf("\n ----- Opcao inválida! -----\n");
                break;
        }
    }
}
