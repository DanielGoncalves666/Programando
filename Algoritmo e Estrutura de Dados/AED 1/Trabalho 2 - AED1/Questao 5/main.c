#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

int main(){

    Fila f = cria_fila();
    Fila backup = cria_fila();
    if(f == NULL || backup == NULL){
        printf("\n----- Falha! -----\n");
        return 0;
    }

    Aluno a;
    int escolha;
    char lixo;

    while(1){
        printf("1_Insere no fim da fila.\n");
        printf("2_Remove o menor cra da fila.\n");
        printf("3_Imprimir fila.\n");
        printf("4_Esvaziar fila.\n");
        printf("5_Sair.\n >>");
        scanf("%d", &escolha);

        if(escolha == 5)
                break;

        switch(escolha){
            case 1: 
                printf("Nome: ");
		while ((lixo = getchar()) != '\n' && lixo != EOF);
                scanf("%50[^\n]",a.nome);
                
                printf("CRA: ");
                scanf("%f", &a.cra);
                
                printf("Matricula: ");
                scanf("%d", &a.matricula);
                
                printf("Ano: ");
                scanf("%d", &a.ano);
                
                insere_fim(f, a);
                break;

            case 2: 
                remove_ord(f, &a);
                printf("\nAluno removido:\n Nome = %s\nCRA = %.2f\nMatricula = %d\nAno = %d\n", a.nome,a.cra,a.matricula,a.ano);
                break;

            case 3: 
                printf("\n=== Fila ===\n");
                while(fp_vazia(f) == 0){
                    remove_ord(f, &a);
                    printf("\n Nome = %s\nCRA = %.2f\nMatricula = %d\nAno = %d\n\n", a.nome,a.cra,a.matricula,a.ano);
                    insere_fim(backup,a);
                }
                
                while(fp_vazia(backup) == 0){
                        remove_ord(backup,&a);
                        insere_fim(f,a);
                }

                esvazia_fp(backup);

                break;

            case 4:
                esvazia_fp(f);
                break;

            default: 
                printf("Opcao invalida.\n");
        }
    }

    return 0;
}
