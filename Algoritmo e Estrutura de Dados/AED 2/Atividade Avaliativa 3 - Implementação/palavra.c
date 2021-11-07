#include "palavra.h"
#include <string.h>
#include <ctype.h>

/*
criar_Palavra
--------------
Entrada: três strings, cada uma armazenando os componentes de uma palavra
Função: cria uma strutura do tipo Palavra e preenche com os valores passados
Saída: uma estrutura do tipo Palavra.
*/
Palavra criar_Palavra(char palavra[], char classificacao[], char significado[])
{
	Palavra nova; 
    strcpy(nova.palavra,palavra);
    strcpy(nova.classificacao, classificacao);
    strcpy(nova.significado,significado);

    return nova;
}

/*
comparar
------------------
Entrada: duas estruturas do tipo Palavra
Função: decide se as palavras sao iguais ou qual é menor (vem antes)
Saída: 0, se iguais, 1, se a primeira for menor, 2, se a segunda for menor
*/
int comparar(Palavra x, Palavra y){
    char str1[TAMANHO_PALAVRA];
	char str2[TAMANHO_PALAVRA];

	strcpy(str1,x.palavra);
	strcpy(str2,y.palavra);
	
	paraMinuscula(str1);
	paraMinuscula(str2);
	
	if(strcmp(str1,str2) < 0)
	{
		return 1;
	}
	else if(strcmp(str1,str2) > 0)
	{
		return 2;
	}
	else
		return 0;
}


/*
paraMinuscula
--------------
Entrada: string
Função: altera os caracteres dessa string para minusculos
Saída: nenhuma
*/
void paraMinuscula(char *word)
{
	for(int i = 0;;i++)
	{
		if(word[i] == '\0')
			break;
		word[i] = tolower(word[i]);
	}
}
