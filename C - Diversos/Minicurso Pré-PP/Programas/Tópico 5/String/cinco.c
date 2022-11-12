#include<stdio.h>
#include<string.h>

int main()
{
	char string[31];
	int tamanho = 0;
	int i;
	
	scanf("%s",string);
	tamanho = strlen(string);
	
	for(i = tamanho - 1; i>= 0; i--)
	{
		printf("%c",string[i]);
	}


	return 0;
}
