#include <stdio.h>
#include "1.h"

int main()
{

}

int inverte_palavras(Pilha p, char string[])
{
	if(pilha_vazia(p))
		return 0;

	int retorno;
	char c;
	char str[101];
	Pilha aux = cria_pilha;

	int i;
	while(!pilha_vazia(p))
	{
		i = 0;
		while(1)
		{
			retorno = pop(p,c);

			if(!retorno || c == ' ')
				break;

			str[i] = c;
			i++;
		}

		for(;i >= 0; i--)
		{
			push(aux,str[i]);
		}
		push(aux,' ');
	}

	i = 0;
	while(!pilha_vazia(aux))
	{
		pop(aux,str[i]);

		i++;
	}

	return 1;
}