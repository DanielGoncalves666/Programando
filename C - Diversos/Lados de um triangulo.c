#include<stdio.h>
#include<stdlib.h>

int X,Y,Z,s1,s2,s3;

int main()
{
	scanf("%d",&X);
	scanf("%d",&Y);
	scanf("%d",&Z);

	s1=X+Y;
	s2=Y+Z;
	s3=X+Z;

	if(Z<=s1 && X<=s2 && Y<=s3)
	{
		if(X==Y && Y==Z)
		{
			printf("Triangulo Equilatero\n");
		}
		if(X!=Y && Y!=Z && Z!=X)
		{
			printf("Triangulo Escaleno\n");
		}
		if((X==Y && Z!=X) || (Y==Z && X!=Y) || (Z==X && Y!=Z))
		{
			printf("Triangulo Isosceles\n");
		}
	}
	else
	{
		printf("Os lados nao formam um triangulo\n");
	}
	return 0;

}
