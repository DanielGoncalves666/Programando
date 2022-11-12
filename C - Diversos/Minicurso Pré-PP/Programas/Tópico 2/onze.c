#include<stdio.h>


int main()
{
	int ano;
	
	scanf("%d",&ano);

	if( ano % 4 == 0 && ( !(ano % 100 == 0) || ( ano % 100 == 0 && ano % 400 == 0) ) )
	{
		printf("Bissexto.\n");
	} 
	else
	{
		printf("Não eh Bissexto.\n");
	}	


	/*
	if( ano % 4 == 0 )
	{
		if( ano % 100 == 0)
		{
			if( ano % 400 == 0)
			{
				printf("Bissexto.\n");
			}
			else
			{
				printf("Não eh bissexto.\n");
			}
		}
		else
		{
			printf("Bissexto.\n");
		}
	}
	else
	{
		printf("Não eh bissexto.\n");
	}
	*/


	return 0;
}
