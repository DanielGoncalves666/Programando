#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arvore.h"
#include "palavra.h"

struct NO
{
	Palavra item;
	int altura;
	struct NO *esq;
	struct NO *dir;
};

void libera_NO(struct NO* no);
int altura_NO(struct NO* no);
int fatorBalanceamento_NO(struct NO* no);
int maior(int x, int y);
int altura_Dicionario(Dicionario *raiz);
Dicionario procuraMenor(Dicionario raiz);

void RotacaoDireita(Dicionario *A);
void RotacaoEsquerda(Dicionario *A);
void RotacaoDuplaDireita(Dicionario *A);
void RotacaoDuplaEsquerda(Dicionario *A);



/*
cria_Dicionario
----------------
Entrada: nenhuma
Função: criar uma nova árvore Avl
Saída: endereço para ponteiro que aponta para a raiz da arvore
*/
Dicionario *cria_Dicionario()
{
	Dicionario* raiz = (Dicionario *) malloc(sizeof(Dicionario));

	if(raiz != NULL)
		*raiz = NULL;

	return raiz;
}

/*
libera_NO
----------------
Entrada: ponteiro para no
Função: libera o no e suas sub-arvores
Saída: nenhuma
*/
void libera_NO(struct NO* no){
    if(no == NULL)
        return;

    libera_NO(no->esq);
    libera_NO(no->dir);
    
	free(no);
    no = NULL;
}

/*
libera_Dicionario
------------------
Entrada: ponteiro para um tipo Dicionario
Função: libera toda a árvore
Saída: nenhuma
*/
void libera_Dicionario(Dicionario* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera todos os nós
    free(raiz);//libera a raiz
}

/*
altura_NO
--------------
Entrada: ponteiro para um nó
Função: retornar a altura do nó
Saída: inteiro, indicando a altura do nó
*/
int altura_NO(struct NO* no){
    if(no == NULL)
        return -1;
    else
    	return no->altura;
}

/*
fatorBalanceamento_NO
---------------------
Entrada: ponteiro para um nó
Função: calcula o fato de balanceamento do nó passado
Saída: inteiro, indicando o fator de balanceamento
*/
int fatorBalanceamento_NO(struct NO* no){
    return labs(altura_NO(no->esq) - altura_NO(no->dir));
		// lasb retorna o valor absoluto
			// o fato de balanceamento é obtida por: alturaEsq - alturaDir
}

/*
estaVazio_Dicionario
----------------------
Entrada: ponteiro para um tipo Dicionario
Função: verifica se a árvore está vazia
Saída: 1, se sim, 0, se nao
*/
int estaVazio_Dicionario(Dicionario *raiz){
    if(raiz == NULL) // ponteiro inválido
        return 1;
    if(*raiz == NULL) // o ponteiro que aponta para a raiz não apónta para nada.
        return 1;
    return 0;
}

/*
totalNo_Dicionario
-------------------
Entrada: ponteiro para um tipo Dicionario
Função: calcula a quantidade de itens na árvore
Saída: quantidade de itens na árvore
*/
int totalNO_Dicionario(Dicionario *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int qtd_esq = totalNO_Dicionario(&((*raiz)->esq));
    int qtd_dir = totalNO_Dicionario(&((*raiz)->dir));
    return(qtd_esq + qtd_dir + 1);
}

/*
altura_Dicionario
-----------------
Entrada: ponteiro para um tipo Dicionario
Função: Calcula a altura do nó que o ponteiro aponta
Saída: inteiro, indicando a altura;
*/
int altura_Dicionario(Dicionario *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_Dicionario(&((*raiz)->esq));
    int alt_dir = altura_Dicionario(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}

/*
consulta_Dicionario
--------------------
Entrada: ponteiro para tipo dicionario e uma string indicando a palavra que deve ser buscada
Função: procura a palavra indicada pela string na árvore
Saída: ponteiro para a palvra procurada em sucesso, NULL em fracasso
*/
Palavra *consulta_Dicionario(Dicionario *raiz, char palavra[]){
    if(raiz == NULL)
		return NULL;

	struct NO* atual = *raiz;
    Palavra procurada = criar_Palavra(palavra,"","");


	while(atual != NULL)
	{
		if(comparar(procurada,atual->item) == 0)
            return &atual->item;

        if(comparar(procurada,atual->item) == 1)
        {
            // a palavra procurada é menor
            atual = atual->esq;
        }
        else
        {
            // a palavra procurada é maior
            atual = atual->dir;
        }
	}
	
    return NULL;
}

/*
RotacaoDireita
------------------
Entrada: ponteiro para tipo dicionario
Função: realiza a rotacao à direita de modo a balancear o nó apontado 
Saída: nenhuma
*/
void RotacaoDireita(Dicionario *A){//LL
    Dicionario B;
    B = (*A)->esq;
    (*A)->esq = B->dir;
    B->dir = *A;
    (*A)->altura = maior(altura_NO((*A)->esq),altura_NO((*A)->dir)) + 1;
    B->altura = maior(altura_NO(B->esq),(*A)->altura) + 1;
    *A = B;
}

/*
RotacaoEsquerda
------------------
Entrada: ponteiro para tipo dicionario
Função: realiza a rotacao à esquerda de modo a balancear o nó apontado 
Saída: nenhuma
*/
void RotacaoEsquerda(Dicionario *A){//RR
    Dicionario B;
    B = (*A)->dir;
    (*A)->dir = B->esq;
    B->esq = (*A);
    (*A)->altura = maior(altura_NO((*A)->esq),altura_NO((*A)->dir)) + 1;
    B->altura = maior(altura_NO(B->dir),(*A)->altura) + 1;
    (*A) = B;
}

/*
RotacaoDuplaDireita
------------------
Entrada: ponteiro para tipo dicionario
Função: realiza a rotacao à dupla direita de modo a balancear o nó apontado 
Saída: nenhuma
*/
void RotacaoDuplaDireita(Dicionario *A){//LR
    RotacaoEsquerda(&(*A)->esq);
    RotacaoDireita(A);
}

/*
RotacaoDuplaEsquerda
------------------
Entrada: ponteiro para tipo dicionario
Função: realiza a rotacao dupla à esquerda de modo a balancear o nó apontado 
Saída: nenhuma
*/
void RotacaoDuplaEsquerda(Dicionario *A){//RL
    RotacaoDireita(&(*A)->dir);
    RotacaoEsquerda(A);
}

/*
maior
-------
Entrada: dois inteiros
Função: determinar qual o maior
Saída: um inteiro, sendo o maior entre os dois passados
*/
int maior(int x, int y){
    if(x > y)
        return x;
    else
        return y;
}

/*
insere_Palavra
----------------
Entrada: ponteiro para tipo Dicionario, uma palavra
Função: Realiza a inserção de uma no dicionario
Saída: 0, em falha ou se for uma palavra já inserida, 1 em sucesso
*/
int insere_Palavra(Dicionario *raiz, Palavra nova){
    int r;
   
    if(*raiz == NULL){//árvore vazia ou nó folha
        struct NO *novo;
        novo = (struct NO*) malloc(sizeof(struct NO));
        if(novo == NULL)
            return 0;

        novo->item = nova;
        novo->altura = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return 1;
    }

    struct NO *atual = *raiz;
    // nova < atual->item
    if(comparar(nova,atual->item) == 1){
        r = insere_Palavra(&(atual->esq), nova);
        if(r == 1){
            if(fatorBalanceamento_NO(atual) >= 2){
                // nova < (*raiz)->dir->item)
                if(comparar(nova,(*raiz)->esq->item) == 1) 
                    RotacaoDireita(raiz);
                else
                    RotacaoDuplaDireita(raiz);
            }
        }
    }
    else
    {

        // nova > atual->item
        if(comparar(nova,atual->item) == 2){
            r = insere_Palavra(&(atual->dir), nova); 
            if(r == 1){
                if(fatorBalanceamento_NO(atual) >= 2){
                    // nova > (*raiz)->dir->item)
                    if(comparar(nova, (*raiz)->dir->item) == 2)
                        RotacaoEsquerda(raiz);
                    else
                        RotacaoDuplaEsquerda(raiz);
                }
            }
        }else{
            return -1;
        }
    }

    atual->altura = maior(altura_NO(atual->esq),altura_NO(atual->dir)) + 1;

    return r;
}

/*
remove_Palavra
---------------
Entrada: ponteiro para dicionario e uma string
Função: remove a string do dicionario, se ela existir
Saída: 0, em falha, 1 em sucesso
*/
int remove_Palavra(Dicionario *raiz, char palavra[]){

    int r;
    Palavra procurada = criar_Palavra(palavra,"","");

	if(*raiz == NULL){// valor não existe
	    printf("valor não encontrado!!\n");
	    return 0;
	}

    // procurada < (*raiz)->item
    if(comparar(procurada,(*raiz)->item) == 1){
      r = remove_Palavra(&(*raiz)->esq,palavra);
	    if(r == 1){
            if(fatorBalanceamento_NO(*raiz) >= 2){
                if(altura_NO((*raiz)->dir->esq) <= altura_NO((*raiz)->dir->dir))
                    RotacaoEsquerda(raiz);
                else
                    RotacaoDuplaEsquerda(raiz);
            }
	    }
	}

    // procurada > atual->item
	if(comparar(procurada,(*raiz)->item) == 2)
    {
        r = remove_Palavra(&(*raiz)->dir, palavra);
	    if(r == 1){
            if(fatorBalanceamento_NO(*raiz) >= 2){
                if(altura_NO((*raiz)->esq->dir) <= altura_NO((*raiz)->esq->esq) )
                    RotacaoDireita(raiz);
                else
                    RotacaoDuplaDireita(raiz);
            }
	    }
	}

    // procurada ==  atual->item
	if(comparar(procurada,(*raiz)->item) == 0)
    {
	    if(((*raiz)->esq == NULL || (*raiz)->dir == NULL)){// nó tem 1 filho ou nenhum
			struct NO *raizAntiga = (*raiz);
			if((*raiz)->esq != NULL)
                *raiz = (*raiz)->esq;
            else
                *raiz = (*raiz)->dir;
			    free(raizAntiga);
	    }
        else 
        {                                               // nó tem 2 filhos
			struct NO* temp = procuraMenor((*raiz)->dir);
			(*raiz)->item = temp->item;
			
            remove_Palavra(&(*raiz)->dir, (*raiz)->item.palavra);
            if(fatorBalanceamento_NO(*raiz) >= 2){
  	            if(altura_NO((*raiz)->esq->dir) <= altura_NO((*raiz)->esq->esq))
				    RotacaoDireita(raiz);
	           else
				    RotacaoDuplaDireita(raiz);
	       }
	   }
	   if (*raiz != NULL)
            (*raiz)->altura = maior(altura_NO((*raiz)->esq),altura_NO((*raiz)->dir)) + 1;
	  
       return 1;
	}

   (*raiz)->altura = maior(altura_NO((*raiz)->esq),altura_NO((*raiz)->dir)) + 1;
   return r;
}

/*
procuraMenor
-------------
Entrada: tipo dicionario
Função: busca pela meno palabra na subarvore passada
Saída: tipo dicionario (ponteiro para o menor)
*/
Dicionario procuraMenor(Dicionario raiz){
    struct NO *atual, *prox;

    if (estaVazio_Dicionario(&raiz)) 
        return NULL;
   
    atual = raiz;
    prox = raiz->esq;
    while(prox != NULL){
        atual = prox;
        prox = prox->esq;
    }

    return atual;
}

/*
salvarPalavrasEmOrdem
---------------
Entrada: ponteiro para tipo arquivo e ponteiro para dicionario
Função: salvar o conteudo do dicionario em ordem, de forma recursiva
Saída: nenhuma
*/
void salvarPalavrasEmOrdem(FILE *arq, Dicionario raiz)
{
    if(!estaVazio_Dicionario(&raiz))
    {
        salvarPalavrasEmOrdem(arq, raiz->esq);
        fprintf(arq,"%s\n", raiz->item.palavra);
        fprintf(arq,"%s\n", raiz->item.classificacao);
        fprintf(arq,"%s\n", raiz->item.significado);
        salvarPalavrasEmOrdem(arq, raiz->dir);
    }
}


/*
salvarPalavrasPreOrdem
---------------
Entrada: ponteiro para tipo arquivo e ponteiro para dicionario
Função: salvar o conteudo do dicionario em pre ordem, de forma recursiva
Saída: nenhuma
*/
void salvarPalavrasPreOrdem(FILE *arq, Dicionario raiz)
{
    if(estaVazio_Dicionario(&raiz))
    {
        fprintf(arq,"%s\n", raiz->item.palavra);
        fprintf(arq,"%s\n", raiz->item.classificacao);
        fprintf(arq,"%s\n", raiz->item.significado);
        salvarPalavrasPreOrdem(arq, raiz->esq);
        salvarPalavrasPreOrdem(arq, raiz->dir);
    }
}


/*
salvarPalavrasPosOrdem
---------------
Entrada: ponteiro para tipo arquivo e ponteiro para dicionario
Função: salvar o conteudo do dicionario em pos ordem, de forma recursiva
Saída: nenhuma
*/
void salvarPalavrasPosOrdem(FILE *arq, Dicionario raiz)
{
    if(!estaVazio_Dicionario(&raiz))
    {
        salvarPalavrasPosOrdem(arq, raiz->esq);
        salvarPalavrasPosOrdem(arq, raiz->dir);
        fprintf(arq,"%s\n", raiz->item.palavra);
        fprintf(arq,"%s\n", raiz->item.classificacao);
        fprintf(arq,"%s\n", raiz->item.significado);
    }
}


// percorre em preOrdem
void calcularQuantidadePorLetra(Dicionario raiz, int *vetor)
{
    if(!estaVazio_Dicionario(&raiz))
    {
        char *vet = raiz->item.palavra;
        char first = tolower(vet[0]);
        vetor[first - 'a']++;

        calcularQuantidadePorLetra(raiz->esq, vetor);
        calcularQuantidadePorLetra(raiz->dir, vetor);
    }
}
