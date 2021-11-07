#ifndef PALAVRA_H
#define PALAVRA_H

typedef struct palavra Palavra;

#define TAMANHO_PALAVRA 25
#define TAMANHO_CLASSIFICACAO 15
#define TAMANHO_SIGNIFICADO 250

struct palavra
{
	char palavra[TAMANHO_PALAVRA];
	char classificacao[TAMANHO_CLASSIFICACAO];
	char significado[TAMANHO_SIGNIFICADO];
};

Palavra criar_Palavra(char palavra[], char classificacao[], char significado[]);
int comparar(Palavra x, Palavra y);
void paraMinuscula(char *word);

#endif