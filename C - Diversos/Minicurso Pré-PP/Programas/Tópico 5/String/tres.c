#include<stdio.h>

int main()
{
	char nome[31];
	
	scanf("%s",nome);
	
	if(nome[0] == 'a' || nome[0] == 'A')
		printf("%s",nome);


	return 0;
}
