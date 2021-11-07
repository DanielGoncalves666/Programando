#include <stdio.h>

//Os números de Pell são definidos pela seguinte recursão
//p(n) = 0 se n = 0
//p(n) = 1 se n = 1
//p(n) = 2p(n-1)+ p(n-2) se n > 1

int pell(int N)
{
	if(N == 0)
		return 0;
	else if(N == 1)
		return 1;
	else 
		return 2 * pell(N - 1) + pell(N - 2);
}

int main()
{
	int N;
	scanf("%d",&N);
	printf("%d\n",pell(N));

	return 0;
}