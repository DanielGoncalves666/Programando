#include<stdio.h>


int main()
{
	int a = 0, b = 0, c = 0;
	int premio = 0;

	scanf("%d %d %d", &a, &b, &c);
	scanf("%d", &premio);
	
	int total = a + b + c;
	
	printf("%d\n", (a * premio) / total);
	printf("%d\n", (b * premio) / total);
	printf("%d\n", (c * premio) / total);


	return 0;
}
