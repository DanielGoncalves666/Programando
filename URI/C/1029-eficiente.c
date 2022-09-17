/*
calls(fib(0)) = 0
calls(fib(1)) = 0
calls(fib(2)) = 2
calls(fib(3)) = calls(fib(2)) + 2 = 4
calls(fib(4)) = calls(fib(3)) + calls(fib(2)) + 2 = 4 + 2 + 2 = 8
*/

#include<stdio.h>

int fibonacci(int N, int *resul);

int main()
{
	int N, num;
	int fn, fn_1, fn_2;
	int valor, calls, calls_1, calls_2;

	scanf("%d",&N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d",&num);
		fn = 0;
		fn_1 = 1;
		fn_2 = 0;
		calls = 0;
		calls_1 = 0;
		calls_2 = 0;

		if(num == 1)
		{ 
			fn = 1;
		}

		for(int i = 2; i <= num; i++)
		{
			fn = fn_1 + fn_2;
			fn_2 = fn_1;
			fn_1 = fn;
			calls = calls_1 + calls_2 + 2;
			calls_2 = calls_1;
			calls_1 = calls;
		}

		printf("fib(%d) = %d calls = %d\n",num,calls,fn);
	}

	return 0;
}