#include<stdio.h>

int fibonacci(int N, int *resul);

int main()
{
	int N, num;
	int valor, calls;

	scanf("%d",&N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d",&num);
		valor = calls = 0;

		calls = fibonacci(num,&valor);

		printf("fib(%d) = %d calls = %d\n",num,calls,valor);
	}

	return 0;
}

int fibonacci(int N, int *resul)
{
	if(N == 0)
	{
		*resul = 0;
		return 0;
	}
	else if(N == 1)
	{
		*resul = 1;
		return 0;
	}
	else
	{
		int fn_1, fn_2, calls;
		calls = fibonacci(N - 1, &fn_1);
		calls += fibonacci(N - 2, &fn_2);
		*resul = fn_1 + fn_2;

		return  calls + 2;
	}
}