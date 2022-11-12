#include<stdio.h>


int main()
{
	int num;
	int soma = 0;
	int i = 0;
	
	while(i < 10)
	{
		scanf("%d",&num);
		
		if(num <= 0)
			continue;
		
		soma += num;

		i++;
	}
	
	printf("%.2f\n",soma/ 10.0);



	return 0;
}
