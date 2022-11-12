#include<stdio.h>

int main()
{
	int i;
	int N = 0;
	
	scanf("%d",&N);
	
	if( N % 2 == 1)
		N--;
	
	for(i = N; i >= 0; i -= 2)
	{
		printf("%d\n", i);
	}

	return 0;
}
