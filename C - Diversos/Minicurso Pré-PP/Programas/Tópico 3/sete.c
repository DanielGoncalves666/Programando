#include<stdio.h>

int main()
{
	int num;
	int i = 0;
	int maior = 0, menor = 0;
	
	while( i < 10 )
	{
		scanf("%d",&num);
	
		if(i == 0)
		{
			maior = num;
			menor = num;
		}
		else
		{
			if(num > maior)
				maior = num;
				
			if(num < menor)
				menor = num;
		}
	
		i++;
	}
	
	printf("Maior = %d\n",maior);
	printf("Menor = %d\n",menor);


	return 0;
}
