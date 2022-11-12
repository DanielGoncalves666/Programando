#include<stdio.h>

int main()
{
	int i = 0;
	
	while(i < 1000)
	{
		if( i % 3 == 0 || i % 5 == 0)
		{
			printf("%d\n",i);
		
		}
		
		i++;
	}

	return 0;
}
