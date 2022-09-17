#include<stdio.h>
#include<string.h>

int
main()
{
	int centavos;
	int tamanho;
	char dolares[11];

	while(scanf("%s %d",dolares,&centavos) != EOF)
	{
		printf("$");
		tamanho = strlen(dolares);
		for(int i = 0; i < tamanho;)
		{
			if(i == 0)
			{
				if(tamanho % 3 == 0)
				{
					printf("%c%c%c",dolares[i],dolares[i+1],dolares[i+2]);
					i += 3;
				}
				else if(tamanho % 3 == 2)
				{
					printf("%c%c",dolares[0],dolares[1]);
					i += 2;
				}
				else
				{
					printf("%c",dolares[0]);
					i += 1;
				}
			}
			else
			{
				printf(",");
				printf("%c%c%c",dolares[i],dolares[i+1],dolares[i+2]);
				i += 3;
			}	
		}

		printf(".%02d\n",centavos);
	}

	return 0;
}