#include<stdio.h>

int main()
{
	char palavra[51];
	int i;
	
	scanf("%s", palavra);
	
	for(i = 0; palavra[i] != '\0'; i++)
	{
		palavra[i]++;
	}
	
	printf("%s\n",palavra);


	return 0;
}
