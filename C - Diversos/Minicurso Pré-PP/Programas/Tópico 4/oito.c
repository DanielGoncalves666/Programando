#include<stdio.h>

int main()
{
	int N = 0;
	int i;
	
	scanf("%d",&N);
	
	for(i = 0; i < N; i++)
	{
		printf("%d\n", (2 * i) + 1);
	}


	return 0;
}
