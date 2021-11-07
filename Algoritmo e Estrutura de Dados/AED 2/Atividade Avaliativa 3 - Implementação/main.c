#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "arvore.h"
#include "palavra.h"
#include "lista.h"

void menu();
void lerArquivo(Dicionario *raiz, Lista *diciLista, char *nome);
void eliminarQuebraFinal(char *string);
void significadosEmUmaFrase(Dicionario raiz, char frase[]);
void relatorioDicionario(Dicionario raiz);
void salvarDicionario(Dicionario raiz, char nome[], int escolha);
void limparBuffer();

int main()
{
	menu();
	return 0;
}

//while ((tipo = getchar()) != '\n' && tipo != EOF);

void menu()
{
	Dicionario *dici = cria_Dicionario();
	Lista diciLista = cria_lista();

	int op, retorno1, retorno2;
	double tempo1, tempo2;
	char tipo;
	char nomeArquivo[30];
	char frase[400];
	char palavra[TAMANHO_PALAVRA];
	char classificao[TAMANHO_CLASSIFICACAO];
	char significado[TAMANHO_SIGNIFICADO];
	clock_t ini, fim;
	double tempo;

	while(1)
	{
		printf("\n------ Menu: Dicionário AVL ------\n");
        printf(" 1 - Carregar dicionario.\n");
		printf(" 2 - Buscar palavra.\n");
		printf(" 3 - Inserir nova palavra.\n");
		printf(" 4 - Remover uma palavra.\n");
		printf(" 5 - Exibir significado das palavras de uma frase.\n");
		printf(" 6 - Relatório da quantidade de palavras por letra.\n");
		printf(" 7 - Salvar dicionário em um arquivo de texto.\n");
		printf(" 8 - Sair\n");

		scanf("%d",&op);

		if(op == 8)
			break;

		switch(op)
		{
			case 1:
				printf("\nInsira o nome do arquivo: ");
				scanf("%s",nomeArquivo);
				limparBuffer();

				lerArquivo(dici, &diciLista, nomeArquivo);
				break;
			case 2:
				limparBuffer();
				printf("\nInsira a palavra a ser buscada: ");
				scanf("%[^\n]",palavra);
					
				ini = clock();
				Palavra *buscada1 = consulta_Dicionario(dici,palavra);
				fim = clock();
				tempo1 = ((double)fim-ini)/CLOCKS_PER_SEC;

				ini = clock();
				Palavra *buscada2 = consulta_lista(diciLista, criar_Palavra(palavra,"",""));
				fim = clock();
				tempo2 = ((double)fim-ini)/CLOCKS_PER_SEC;

				if(buscada1 == NULL)
				{
					printf("\nPalavra não está presente no dicionário.\n");
				}
				else
				{
					printf("%s\n",buscada1->palavra);
					printf("%s\n",buscada1->classificacao);
					printf("%s\n",buscada1->significado);
				}

  				printf("\nTempo gasto (Dicionário em Árvore AVL): %.8f seconds.\n", tempo1);
  				printf("\nTempo gasto (Dicionário em lista encadeada): %.8f seconds.\n", tempo2);
				
				break;
			case 3:
				printf("\nInsira a palavra: ");
				limparBuffer();
				scanf("%[^\n]",palavra);

				printf("\nInsira a classificação: ");
				limparBuffer();
				scanf("%[^\n]",classificao);

				printf("\nInsira o significado: ");
				limparBuffer();
				scanf("%[^\n]",significado);

				Palavra nova = criar_Palavra(palavra,classificao,significado);
				retorno1 = insere_Palavra(dici,nova);		// adiciona na árvore
				retorno2 = insere_ord(&diciLista,nova);					// adiciona na lista

				if(retorno1 == 0 || retorno2 == 0)
					printf("\n Falha na inserção.\n");

				if(retorno1 == -1)
					printf("\n Falha na inserção. Palavra já existente.\n");

				if(retorno1 == 1)
					printf("\n Inserção bem-sucedida.\n");

				break;
			case 4:
				printf("\nInsira a palavra: ");
				limparBuffer();
				scanf("%[^\n]",palavra);

				Palavra procurada = criar_Palavra(palavra,"","");

				retorno1 = remove_Palavra(dici, palavra);
				retorno2 = remove_ord(&diciLista,procurada);

				if(retorno1 == 0 || retorno2 == 0)
				{
					printf("\n Falha na remoção. Palavra não presente.\n");
				}
				else
				{
					printf("\n Remocação bem-sucedida.\n");
				}

				break;
			case 5:
				printf("\nEntre com a frase: \n");
				limparBuffer();
				scanf("%[^\n]",frase);

				significadosEmUmaFrase(*dici, frase);
				break;
			case 6:
				relatorioDicionario(*dici);
				break;
			case 7:
				printf("Insira o nome do arquivo em que os dados serão salvos: ");
				limparBuffer();
				scanf("%s",nomeArquivo);
				limparBuffer();

				printf("Em qual ordem as palavras devem ser armazendas: \n1 - Em ordem.\n2 - Pré-Ordem.\n3 - Pós-Ordem.\n");
				scanf("%d",&op);

				salvarDicionario(*dici, nomeArquivo, op);
				break;
			default:
				printf("\n Opção indisponível.\n");
				break;
		}

	}
}

/*
lerArquivo
------------
Entrada: ponteiro para tipo dicionario, ponteiro para tipo lista e uma string
Função: abre e lê o arquivo cujo nome foi passado pela string e armazena seu conteudo na arvore e lista.
Saída: nenhuma
*/
void lerArquivo(Dicionario *raiz, Lista *diciLista, char *nome)
{
	FILE *arq = fopen(nome,"rt");
	if(arq == NULL)
	{
		printf("\nFalha na abertura do arquivo.\n");
		return;
	}

	Palavra nova;

	char palavra[TAMANHO_PALAVRA];
	char classificacao[TAMANHO_CLASSIFICACAO];
	char significado[TAMANHO_SIGNIFICADO];

	while(!feof(arq))
	{
		fgets(palavra,TAMANHO_PALAVRA + 1,arq);
		fgets(classificacao,TAMANHO_CLASSIFICACAO + 1, arq);
		fgets(significado, TAMANHO_SIGNIFICADO + 1, arq);

		if(feof(arq))
			break;

		eliminarQuebraFinal(palavra);
		eliminarQuebraFinal(classificacao);
		eliminarQuebraFinal(significado);

		nova = criar_Palavra(palavra,classificacao,significado);
		insere_Palavra(raiz,nova);		// adiciona na árvore
		insere_ord(diciLista,nova);		// adiciona na lista
	}

	printf("\nConteúdo do arquivo carregado!\n");
	fclose(arq);
}

/*
eliminaQuebraFinal
-------------------
Entrada: uma string
Função: sobrepõe a ultima posiçao com conteudo da string pelo finalizador de string
Saída: nenhuma
*/
void eliminarQuebraFinal(char *string)
{
	int length = strlen(string);
	string[length - 1] = '\0';
}

/*
significadosEmUmaFase
---------------------
Entrada: Tipo dicionario e uma string
Função: Mostra as palavras da string passada que tenham significados registrados no dicionario
Saída: nenhuma
*/
void significadosEmUmaFrase(Dicionario raiz, char frase[])
{
	char *token;
	Palavra *buscada;

	token = strtok(frase, " ,.-?!");
	while(token != NULL)
	{
		// o que tiver que ser feito
		buscada = consulta_Dicionario(&raiz,token);
		if(buscada == NULL)
			printf("\nA palavra \"%s\" não está registrada no dicionário.", token);
		else
		{
			printf("\n%s: ",buscada->palavra);
		    printf("%s",buscada->significado);
		}

		token = strtok(NULL, " ,.-?!");
	}
	printf("\n");
}


/*
relatorioDicionario
-------------------
Entrada: tipo dicionario
Função: imprime a quantidade de palavras por letra que estão armazenadas no dicionário.
Saída: nenhuma
*/
void relatorioDicionario(Dicionario raiz)
{
    int *qtd = (int *) calloc(26, sizeof(int));

    calcularQuantidadePorLetra(raiz, qtd);

    printf("\n -------- Relatorio de contagem de palavras por letra ---------\n");
    for(int i = 0; i < 26; i++)
    {
        printf("%c - %d palavras.\n", 'A' + i, qtd[i]);
    }
	printf("\n");
}

/*
salvarDicionario
---------------
Entrada: tipo Dicionario e uma string e um inteiro
Função: abre o arquivo cujo nome foi passado na string e chama a função para salvar o dicionario, de acordo com o valor do inteiro passado
Saída: nenhuma
*/
void salvarDicionario(Dicionario raiz, char nome[], int escolha)
{
    FILE *arquivo = fopen(nome,"wt");

    if(arquivo == NULL)
    {
        printf("Problemas na criação do arquivo!\n");
        return;
    }

	if(escolha == 1)
	{
		salvarPalavrasEmOrdem(arquivo, raiz);
		printf("Dicionário armazenado com sucesso!\n");
	}else if(escolha == 2){
        salvarPalavrasPreOrdem(arquivo, raiz);
		printf("Dicionário armazenado com sucesso!\n");
	}else if(escolha == 3){
		salvarPalavrasPosOrdem(arquivo, raiz);
		printf("Dicionário armazenado com sucesso!\n");
	}else
        printf("\nEscolha inválida!\n");
    fclose(arquivo);
}

void limparBuffer()
{
	char tipo;
	while ((tipo = getchar()) != '\n' && tipo != EOF);				
}
