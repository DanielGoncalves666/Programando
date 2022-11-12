#include<stdio.h>

int main()
{
	char c;
	
	scanf("%c", &c);
	
	if( c < 65 || c > 90)
	{
		printf("Não é letra maiúscula.\n");
	}
	else
	{
		printf("%c\n", c + 32);
	}

	return 0;
}
