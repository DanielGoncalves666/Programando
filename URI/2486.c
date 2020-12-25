#include<stdio.h>
#include<string.h>

int determinar_vitamina(char string[]);

int
main()
{
	int T = 0, N = 0;
	char string[16];
	int total;

	while(1)
	{
		scanf("%d", &T);
		if(T == 0)
			break;

		total = 0;
		for(int i=0; i<T; i++)
		{
			scanf("%d %[^\n]", &N, string);
			total += N * determinar_vitamina(string);
		}

		if(total > 130)
			printf("Menos %d mg\n", total - 130);
		else if(total < 110)
			printf("Mais %d mg\n", 110 - total);
		else
			printf("%d mg\n", total);	
	}

	return 0;
}

int determinar_vitamina(char string[])
{
	if(!strcmp(string,"suco de laranja"))
		return 120;
	else if(!strcmp(string,"morango fresco"))
		return 85;
	else if(!strcmp(string,"mamao"))
		return 85;
	else if(!strcmp(string,"goiaba vermelha"))
		return 70;
	else if(!strcmp(string, "manga"))
		return 56;
	else if(!strcmp(string, "laranja"))
		return 50;
	else if(!strcmp(string,"brocolis"))
		return 34;
}