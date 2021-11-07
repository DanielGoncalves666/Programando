#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{
    int num,elem,resto,result;
    int retorno;
    char op;
    pilha p = cria_pilha();

    do{
        printf("\n\n ----- Digite o numero decimal a ser convertido: ");
        scanf("%d",&num);
        
        if(num < 0){
            printf("\n ----- Fim do programa -----\n");
            break;
        }

        //obriga o usuário a entrar com uma opção válida.
        do{
            printf("\nB - Binario\n");
            printf("O - Octal\n");
            printf("H - Hexadecimal\n");

            printf("----- Digite a conversao desejada:\n");
			while ((op = getchar()) != '\n' && op != EOF);
            
            scanf("%c",&op);

            if(op!='B' && op!='O' && op!='H' && op!='b' && op!='o' && op!='h')
                printf("\n ----- Opcao invalida! -----\n");
            else
                break;

        }while(1);

        if(op == 'B' || op == 'b'){
            result = num;

            while(result != 0){
                resto = result % 2;
                result = result / 2;
                retorno = push(p,resto);
                
                if(!retorno)
                    break;
            }

            if(!retorno)
            {
                printf("\n ----- Falha! Número com muitos dígitos quando convertido! -----\n");
                continue;
            }

            printf("\nO numero convertido e: ");
            while(pilha_vazia(p)!=1){
                ve_topo(p,&elem);
                printf(" %d ", elem);
                pop(p,&elem);//quando a pilha for vazia, não entra no laço
            }
        }
        
        if(op == 'O' || op == 'o'){
            result = num;

            while(result != 0){
                resto = result%8;
                result = result/8;
                push(p,resto);
                
                if(!retorno)
                    break;
            }

            if(!retorno)
            {
                printf("\n ----- Falha! Número com muitos dígitos quando convertido! -----\n");
                continue;
            }

            printf("\nO numero convertido e: ");
            while(pilha_vazia(p)!=1){
                ve_topo(p,&elem);
                printf(" %d ",elem);
                pop(p,&elem); //quando a pilha for vazia, não entra no laço
            }
        }
        
        if(op == 'H' || op == 'h'){
            result = num;

            while(result != 0){
                resto = result % 16;
                result = result / 16;
                push(p,resto);
                
                if(!retorno)
                    break;
            }

            if(!retorno)
            {
                printf("\n ----- Falha! Número com muitos dígitos quando convertido! -----\n");
                continue;
            }

            printf("\nO numero convertido e: ");
            while(pilha_vazia(p)!=1){
                ve_topo(p,&elem);
                
                if(elem>=0 && elem<=9)
                    printf(" %d ", elem);
                if(elem == 10)
                    printf(" A ");
                if(elem == 11)
                    printf(" B ");
                if(elem == 12)
                    printf(" C ");
                if(elem == 13)
                    printf(" D ");
                if(elem == 14)
                    printf(" E ");
                if(elem == 15)
                    printf(" F ");
                
                pop(p,&elem); //quando a pilha for vazia, não entra no laço
            }
        }

    }while(1);

    return 0;
}
