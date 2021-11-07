#include <stdio.h>
#include <stdlib.h>
#include "pilhaf.h"
#include "pilhac.h"
#include <string.h>
#include <math.h>

int prioridade(char c){
    if(c=='+'||c=='-')
        return 1;
    if(c=='*'||c=='/')
        return 2;
    if(c=='^')
        return 3;
    return 0;
}

int main(){

    Pilhac p = cria_pilha_char();
    char expressao[20];
    int i;
    printf("\nDigite a expressao\n");
    setbuf(stdin,NULL);
    gets(expressao);

    ///Validacao do escopo
    for(i=0; i<strlen(expressao);i++){
        if(expressao[i] == '('){
            pushchar(&p,expressao[i]);
        }

        if(expressao[i] == '{'){
            char elem;
            le_topo_char(&p,&elem);
            if(elem == '('  || elem == '['){
                printf("\nErro: procedencia nao obedecida\n");
                break;
            }else
                pushchar(&p,expressao[i]);
        }

        if(expressao[i] == '['){
            char elem;
            le_topo_char(&p,&elem);
            if(elem == '('){
                printf("\nErro: procedencia nao obedecida\n");
                break;
            }else
                pushchar(&p,expressao[i]);
        }

        if(expressao[i] == ')'){
            char elem;
            le_topo_char(&p,&elem);
            if(elem == '(' || elem == '{' || elem == '['){
                popchar(&p,&elem);
            }else{
                printf("\nErro: Ordem de fechamento dos escopos é diferente da ordem de abertura\n");
                break;
            }
        }
        if(expressao[i] == ']'){
            char elem;
            le_topo_char(&p,&elem);
            if(elem == '[' || elem == '{'){
                popchar(&p,&elem);
            }else{
                printf("\nErro: Ordem de fechamento dos escopos é diferente da ordem de abertura\n");
                break;
            }
        }
        if(expressao[i] == '}'){
            char elem;
            le_topo_char(&p,&elem);
            if(elem == '{'){
                popchar(&p,&elem);
            }else{
                printf("\nErro: Ordem de fechamento dos escopos é diferente da ordem de abertura\n");
                break;
            }
        }
    }
    if(pilha_vazia_char(p)==1)
        printf("\nEscopo da expressao e valido\n");
    else
        return 0;

    ///Pós-fixa
    char aux[strlen(expressao)];
    int j=0;
    int cont1=0,cont2=0;
    for(i=0;i<strlen(expressao);i++){
        char elem;

        if(expressao[i]>='A' && expressao[i]<='J'){
            printf("%c",expressao[i]);
            aux[j]=expressao[i];
            j++;
            cont1++;
        }
        if(expressao[i]=='(' || expressao[i]=='[' || expressao[i]=='{'){
            pushchar(&p,expressao[i]);
        }
        if(expressao[i]=='^' || expressao[i]=='*' || expressao[i]=='/' || expressao[i]=='+' || expressao[i]=='-'){
            cont2++;
            le_topo_char(&p,&elem);
            if(elem=='^' || elem=='*' || elem=='/' || elem=='+' || elem=='-'){
                if(prioridade(expressao[i])>= prioridade(elem)){
                    pushchar(&p,expressao[i]);
                }else{
                    popchar(&p,&elem);
                    printf("%c",elem);
                    aux[j]=elem;
                    j++;
                    pushchar(&p,expressao[i]);
                }
            }else{
               pushchar(&p,expressao[i]);
            }
        }
        if(expressao[i]==')'){
            do{
                popchar(&p,&elem);
                printf("%c",elem);
                aux[j]=elem;
                j++;
                le_topo_char(&p,&elem);

            }while(elem != '(');
        popchar(&p,&elem);
        }

        if(expressao[i]==']'){
            do{
                popchar(&p,&elem);
                printf("%c",elem);
                aux[j]=elem;
                j++;
                le_topo_char(&p,&elem);

            }while(elem != '[');
        popchar(&p,&elem);
        }

        if(expressao[i]=='}'){
            do{
                popchar(&p,&elem);
                printf("%c",elem);
                aux[j]=elem;
                j++;
                le_topo_char(&p,&elem);

            }while(elem != '{');
        popchar(&p,&elem);
        }

        if(i==strlen(expressao)-1){
            while(pilha_vazia(p)!=1){
                popchar(&p,&elem);
                printf("%c",elem);
                aux[j]=elem;
                j++;
            }
        }
    }
    ///Resolucao da espressao

    if(cont2 != cont1 - 1){
        printf("\nErro: numero de operadores nao e adequado\n");
        return 0;
    }

    Pilha p2 = cria_pilha();
    float a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,il=0,jl=0;
    float A,B,C,D,E,F,G,H,I,J;
    for(i=0;i<strlen(aux);i++){
        if(aux[i]=='A'){
            if(a==0){
                printf("\nDigite o valor de %c\n",aux[i]);
                scanf("%f",&A);
                a=1;
            }
            push(&p2,A);
        }

        if(aux[i]=='B'){
            if(b==0){
                printf("\nDigite o valor de %c\n",aux[i]);
                scanf("%f",&B);
                b=1;
            }
            push(&p2,B);
        }
        if(aux[i]=='C'){
            if(c==0){
                printf("\nDigite o valor de %c\n",aux[i]);
                scanf("%f",&C);
                c=1;
            }
            push(&p2,C);
        }
        if(aux[i]=='D'){
            if(d==0){
                printf("\nDigite o valor de %c\n",aux[i]);
                scanf("%f",&D);
                d=1;
            }
            push(&p2,D);
        }
        if(aux[i]=='E'){
            if(e==0){
                printf("\nDigite o valor de %c\n",aux[i]);
                scanf("%f",&E);
                e=1;
            }
            push(&p2,e);
        }
        if(aux[i]=='F'){
            if(f==0){
                printf("\nDigite o valor de %c\n",aux[i]);
                scanf("%f",&F);
                f=1;
            }
            push(&p2,F);
        }
        if(aux[i]=='G'){
            if(g==0){
                printf("\nDigite o valor de %c\n",aux[i]);
                scanf("%f",&G);
                g=1;
            }
            push(&p2,G);
        }
        if(aux[i]=='H'){
            if(h==0){
                printf("\nDigite o valor de %c\n",aux[i]);
                scanf("%f",&H);
                h=1;
            }
            push(&p2,H);
        }
        if(aux[i]=='I'){
            if(il==0){
                printf("\nDigite o valor de %c\n",aux[i]);
                scanf("%f",&I);
                il=1;
            }
            push(&p2,I);
        }
        if(aux[i]=='J'){
            if(jl==0){
                printf("\nDigite o valor de %c\n",aux[i]);
                scanf("%f",&J);
                jl=1;
            }
            push(&p2,J);
        }
        if(aux[i]=='^'){
            float x2,x1;
            float r;
            pop(&p2,&x2);
            pop(&p2,&x1);
            r = pow(x1,x2);
            push(&p2,r);
        }
        if(aux[i]=='*'){
            float x2,x1;
            float r;
            pop(&p2,&x2);
            pop(&p2,&x1);
            r = x1*x2;
            push(&p2,r);
        }
        if(aux[i]=='/'){
            float x2,x1;
            float r;
            pop(&p2,&x2);
            pop(&p2,&x1);
            r = x1/x2;
            push(&p2,r);
        }
        if(aux[i]=='+'){
            float x2,x1;
            float r;
            pop(&p2,&x2);
            pop(&p2,&x1);
            r = x1+x2;
            push(&p2,r);
        }
        if(aux[i]=='-'){
            float x2,x1;
            float r;
            pop(&p2,&x2);
            pop(&p2,&x1);
            r = x1-x2;
            push(&p2,r);
        }

    }
    float result;
    pop(&p2,&result);

    printf("\nResultado: %.2f", result);
}

