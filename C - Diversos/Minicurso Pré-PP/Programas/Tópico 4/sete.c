#include<stdio.h>

int main()
{
	int i;
	int num;
	int menor = 0, maior = 0;


	for(i = 0; i < 10; i++)
	{
		scanf("%d",&num);
		
		if(i == 0)
		{
			menor = num;
			maior = num;
		}
		else
		{
			if(num < menor)
				menor = num;
				
			if(num > maior)
				maior = num;
		}
	}
	
	printf("Menor = %d\n Maior = %d\n",menor,maior);

	return 0;
}
