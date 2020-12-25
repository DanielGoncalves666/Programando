#include<stdio.h>
#include<string.h>

int valor_coluna(char string[], int tamanho);

int
main()
{
	char string[11], aux[4] = "XFD";
	int tamanho = 0;
	int valor = 0;
	int maximo = valor_coluna(aux,3);

	while(scanf("%s",string) != EOF)
	{
		tamanho = strlen(string);

		if(tamanho >= 4)
		{
			printf("Essa coluna nao existe Tobias!\n");
			continue;
		}

		if(tamanho == 3)
		{
			if(valor_coluna(string,tamanho) > maximo)
			{
				printf("Essa coluna nao existe Tobias!\n");
				continue;
			}
		}

		valor = valor_coluna(string, tamanho);
		printf("%d\n",valor);
	}

	return 0;
}

int valor_coluna(char string[], int tamanho)
{
	if(tamanho == 1)
		return string[0] - 'A' + 1;

	if(tamanho == 2)
		return ((string[0] - 'A' + 1) * 26) + (string[1] - 'A' + 1);

	if(tamanho == 3)
		return (((string[0] - 'A' + 1) * 26 * 26) + ((string[1] - 'A' + 1) * 26)) + (string[2] - 'A' + 1);
}