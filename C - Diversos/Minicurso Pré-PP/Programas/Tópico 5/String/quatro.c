#include<stdio.h>
#include<string.h>

int main()
{
	char string[31];
	char copia[5];

	scanf("%s",string);
	
	strncpy(copia,string,4);
	
	printf("%s",copia);

	return 0;
}
