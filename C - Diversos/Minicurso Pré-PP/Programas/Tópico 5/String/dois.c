#include<stdio.h>

int main()
{
	char string[31];
	int i;
	int tamanho = 0;
	
	scanf("%s", string);
	
	for(i = 0; i < 32; i++)
	{
		if(string[i] == '\0')
			break;
	
		tamanho++;
	}

	printf("%d\n",tamanho);

	return 0;
}
