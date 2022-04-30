#include<stdio.h>

int sub(int a, int b)
{
	return a - b;
}

int add(int a, int b)
{

	return a + b;
}

int primeiro()
{
	return 1;
}

int segundo()
{
	return 2;
}

int main()
{
	int (*doisInteiros)(int a, int b);
	int (*nada) ();

	int x = 10;
	int y = 5;
	
	//doisInteiros = sub;
	//printf("%d\n", doisInteiros(x,y));
	
	
	nada = primeiro;
	
	printf("%d\n",segundo());
	

	return 0;
}



