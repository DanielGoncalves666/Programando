#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
	char palavra1[21];
	char palavra2[21];
	int i;
	
	scanf("%s %s",palavra1,palavra2);
	
	for(i = 0; palavra1[i] != '\0'; i++)
	{
		palavra1[i] = tolower(palavra1[i]);
	}
	
	for(i = 0; palavra2[i] != '\0'; i++)
	{
		palavra2[i] = tolower(palavra2[i]);
	}
	
	int comparacao = strcmp(palavra1,palavra2);
	
	if(comparacao < 0)
	{
		printf("string 1 vem antes\n");
	}
	else if (comparacao > 0)
	{
		printf("string 2 vem antes\n");
	}
	else
	{
		printf("strings iguais\n");
	}
	 


	return 0;
}
